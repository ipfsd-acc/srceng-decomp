// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/xunzip.cpp
// Functions: 45
// ============================================================

#include "public\xunzip.h"

//------------------------------------------------------------------------------
// Address: 0x101F6D50
// Name: int inflate_flush(struct inflate_blocks_state __near *,struct z_stream_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_flush(inflate_blocks_state *s, z_stream_s *z, int r)
{
  unsigned __int8 *write; // edi
  unsigned __int8 *read; // eax
  unsigned int avail_out; // ecx
  unsigned int v7; // edi
  unsigned int (__cdecl *checkfn)(unsigned int, const unsigned __int8 *, unsigned int); // ecx
  unsigned int v9; // eax
  unsigned __int8 *end; // edx
  unsigned __int8 *window; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edi
  unsigned int (__cdecl *v14)(unsigned int, const unsigned __int8 *, unsigned int); // eax
  unsigned int v15; // eax
  unsigned __int8 *p; // [esp+Ch] [ebp-4h]
  unsigned __int8 *q; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 *qa; // [esp+1Ch] [ebp+Ch]

  write = s->write;
  p = z->next_out;
  read = s->read;
  q = read;
  if ( read > write )
    write = s->end;
  avail_out = z->avail_out;
  v7 = write - read;
  if ( v7 > avail_out )
    v7 = z->avail_out;
  if ( v7 != 0 && r == -5 )
    r = 0;
  z->total_out += v7;
  z->avail_out = avail_out - v7;
  checkfn = s->checkfn;
  if ( checkfn != nullptr )
  {
    v9 = checkfn(a1: s->check, a2: read, a3: v7);
    s->check = v9;
    z->adler = v9;
    read = q;
  }
  if ( v7 != 0 )
  {
    memcpy(dst: p, src: read, count: v7);
    p += v7;
    read = &q[v7];
  }
  end = s->end;
  if ( read == end )
  {
    window = s->window;
    qa = window;
    if ( s->write == end )
      s->write = window;
    v12 = z->avail_out;
    v13 = s->write - window;
    if ( v13 > v12 )
      v13 = z->avail_out;
    if ( v13 != 0 && r == -5 )
      r = 0;
    z->total_out += v13;
    z->avail_out = v12 - v13;
    v14 = s->checkfn;
    if ( v14 != nullptr )
    {
      v15 = v14(a1: s->check, a2: window, a3: v13);
      window = qa;
      s->check = v15;
      z->adler = v15;
    }
    memcpy(dst: p, src: window, count: v13);
    p += v13;
    read = &qa[v13];
  }
  z->next_out = p;
  s->read = read;
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x101F6E50
// Name: struct inflate_codes_state __near * inflate_codes_new(unsigned int,unsigned int,struct inflate_huft_s const __near *,struct inflate_huft_s const __near *,struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
inflate_codes_state *__cdecl inflate_codes_new(
        unsigned __int8 bl,
        unsigned __int8 bd,
        const inflate_huft_s *tl,
        const inflate_huft_s *td,
        z_stream_s *z)
{
  inflate_codes_state *result; // eax

  result = (inflate_codes_state *)z->zalloc(a1: z->opaque, a2: 1, a3: 28);
  if ( result != nullptr )
  {
    result->lbits = bl;
    result->dbits = bd;
    result->mode = START;
    result->ltree = tl;
    result->dtree = td;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F6E90
// Name: void inflate_blocks_reset(struct inflate_blocks_state __near *,struct z_stream_s __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl inflate_blocks_reset(inflate_blocks_state *s, z_stream_s *z, unsigned int *c)
{
  unsigned __int8 *window; // eax
  unsigned int (__cdecl *checkfn)(unsigned int, const unsigned __int8 *, unsigned int); // eax
  unsigned int v5; // eax

  if ( c != nullptr )
    *c = s->check;
  if ( s->mode == IBM_BTREE || s->mode == IBM_DTREE )
    z->zfree(a1: z->opaque, a2: s->sub.trees.blens);
  if ( s->mode == IBM_CODES )
    z->zfree(a1: z->opaque, a2: (void *)s->sub.left);
  window = s->window;
  s->write = window;
  s->read = window;
  checkfn = s->checkfn;
  s->mode = IBM_TYPE;
  s->bitk = 0;
  s->bitb = 0;
  if ( checkfn != nullptr )
  {
    v5 = checkfn(a1: 0, a2: nullptr, a3: 0);
    s->check = v5;
    z->adler = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6F20
// Name: struct inflate_blocks_state __near * inflate_blocks_new(struct z_stream_s __near *,unsigned long (*)(unsigned long,unsigned char const __near *,unsigned int),unsigned int)
// Source: json
//------------------------------------------------------------------------------
inflate_blocks_state *__cdecl inflate_blocks_new(
        z_stream_s *z,
        unsigned int (__cdecl *c)(unsigned int, const unsigned __int8 *, unsigned int),
        unsigned int w)
{
  inflate_blocks_state *v3; // esi
  inflate_huft_s *v4; // eax
  unsigned __int8 *v6; // eax

  v3 = (inflate_blocks_state *)z->zalloc(a1: z->opaque, a2: 1, a3: 64);
  if ( v3 == nullptr )
    return nullptr;
  v4 = (inflate_huft_s *)z->zalloc(a1: z->opaque, a2: 8, a3: 1440);
  v3->hufts = v4;
  if ( v4 == nullptr )
  {
    z->zfree(a1: z->opaque, a2: v3);
    return nullptr;
  }
  v6 = (unsigned __int8 *)z->zalloc(a1: z->opaque, a2: 1, a3: w);
  v3->window = v6;
  if ( v6 != nullptr )
  {
    v3->end = &v6[w];
    v3->checkfn = c;
    v3->mode = IBM_TYPE;
    inflate_blocks_reset(s: v3, z, c: nullptr);
    return v3;
  }
  else
  {
    z->zfree(a1: z->opaque, a2: v3->hufts);
    z->zfree(a1: z->opaque, a2: v3);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6FD0
// Name: int inflate_blocks_free(struct inflate_blocks_state __near *,struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_blocks_free(inflate_blocks_state *s, z_stream_s *z)
{
  unsigned __int8 *window; // eax
  unsigned int (__cdecl *checkfn)(unsigned int, const unsigned __int8 *, unsigned int); // eax
  unsigned int v4; // eax

  if ( s->mode == IBM_BTREE || s->mode == IBM_DTREE )
    z->zfree(a1: z->opaque, a2: s->sub.trees.blens);
  if ( s->mode == IBM_CODES )
    z->zfree(a1: z->opaque, a2: (void *)s->sub.left);
  window = s->window;
  s->write = window;
  s->read = window;
  checkfn = s->checkfn;
  s->mode = IBM_TYPE;
  s->bitk = 0;
  s->bitb = 0;
  if ( checkfn != nullptr )
  {
    v4 = checkfn(a1: 0, a2: nullptr, a3: 0);
    s->check = v4;
    z->adler = v4;
  }
  z->zfree(a1: z->opaque, a2: s->window);
  z->zfree(a1: z->opaque, a2: s->hufts);
  z->zfree(a1: z->opaque, a2: s);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F7070
// Name: int huft_build(unsigned int __near *,unsigned int,unsigned int,unsigned int const __near *,unsigned int const __near *,struct inflate_huft_s __near * __near *,unsigned int __near *,struct inflate_huft_s __near *,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl huft_build(
        unsigned int *b,
        unsigned int n,
        unsigned int s,
        const unsigned int *d,
        const unsigned int *e,
        inflate_huft_s **t,
        unsigned int *m,
        inflate_huft_s *hp,
        unsigned int *hn,
        unsigned int *v)
{
  unsigned int *v10; // eax
  unsigned int v11; // edx
  unsigned int v13; // edx
  unsigned int j; // ecx
  unsigned int ii; // esi
  int v16; // eax
  int v17; // eax
  unsigned int *v18; // edi
  unsigned int v19; // ecx
  int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // esi
  int v23; // edi
  unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // ecx
  unsigned int v27; // esi
  int v28; // ecx
  unsigned int v29; // edi
  int v30; // ebx
  unsigned int base; // esi
  int v32; // eax
  unsigned int v33; // edx
  unsigned int v34; // ecx
  unsigned int v35; // eax
  unsigned int *v36; // edi
  unsigned int v37; // edi
  unsigned int v38; // eax
  int v39; // eax
  unsigned int v40; // edx
  inflate_huft_s *v41; // edi
  unsigned int v42; // esi
  unsigned __int8 v43; // dl
  unsigned int v44; // eax
  int v45; // ecx
  unsigned int v46; // eax
  int v47; // eax
  int v48; // edx
  unsigned int v49; // eax
  unsigned int *v50; // ecx
  unsigned int jj; // eax
  int v52; // eax
  inflate_huft_s *u[15]; // [esp+8h] [ebp-F8h] BYREF
  unsigned int x[16]; // [esp+44h] [ebp-BCh]
  unsigned int c[16]; // [esp+84h] [ebp-7Ch] BYREF
  int y; // [esp+C4h] [ebp-3Ch]
  inflate_huft_s **v57; // [esp+C8h] [ebp-38h]
  unsigned int v58; // [esp+CCh] [ebp-34h]
  unsigned int v59; // [esp+D0h] [ebp-30h]
  unsigned int z; // [esp+D4h] [ebp-2Ch]
  inflate_huft_s r; // [esp+D8h] [ebp-28h]
  int g; // [esp+E0h] [ebp-20h]
  unsigned int *v63; // [esp+E4h] [ebp-1Ch]
  unsigned int i; // [esp+E8h] [ebp-18h]
  unsigned int *xp; // [esp+ECh] [ebp-14h]
  unsigned int a; // [esp+F0h] [ebp-10h]
  int h; // [esp+F4h] [ebp-Ch]
  int k; // [esp+F8h] [ebp-8h]
  int l; // [esp+FCh] [ebp-4h]
  unsigned int *p; // [esp+108h] [ebp+8h]
  unsigned int *pa; // [esp+108h] [ebp+8h]
  unsigned int na; // [esp+10Ch] [ebp+Ch]

  v10 = b;
  memset(c, 0, sizeof(c));
  v11 = n;
  do
  {
    ++c[*v10++];
    --v11;
  }
  while ( v11 != 0 );
  if ( c[0] == n )
  {
    *t = nullptr;
    *m = 0;
    return 0;
  }
  else
  {
    v13 = *m;
    l = *m;
    for ( j = 1; j <= 0xF; ++j )
    {
      if ( c[j] != 0 )
        break;
    }
    k = j;
    if ( v13 < j )
    {
      l = j;
      v13 = j;
    }
    for ( ii = 15; ii != 0; --ii )
    {
      if ( c[ii] != 0 )
        break;
    }
    g = ii;
    if ( v13 > ii )
    {
      l = ii;
      v13 = ii;
    }
    *m = v13;
    v16 = 1 << j;
    if ( j >= ii )
    {
LABEL_18:
      v18 = &c[ii];
      xp = (unsigned int *)(4 * ii);
      v19 = *v18;
      v20 = v16 - *v18;
      y = v20;
      if ( v20 >= 0 )
      {
        *v18 = v20 + v19;
        v21 = 0;
        v22 = ii - 1;
        x[1] = 0;
        if ( v22 != 0 )
        {
          v23 = 0;
          do
          {
            v21 += c[++v23];
            --v22;
            x[v23 + 1] = v21;
          }
          while ( v22 != 0 );
        }
        v24 = b;
        v25 = 0;
        do
        {
          v26 = *v24++;
          p = v24;
          if ( v26 != 0 )
          {
            v27 = x[v26];
            v[v27] = v25;
            x[v26] = v27 + 1;
            v24 = p;
          }
          ++v25;
        }
        while ( v25 < n );
        na = *(unsigned int *)((char *)x + (_DWORD)xp);
        pa = v;
        x[0] = 0;
        u[0] = nullptr;
        xp = nullptr;
        z = 0;
        v28 = k;
        v29 = 0;
        v30 = -v13;
        i = 0;
        h = -1;
        if ( k > g )
        {
LABEL_68:
          if ( v20 == 0 || g == 1 )
            return 0;
          else
            return -5;
        }
        else
        {
          base = r.base;
          v63 = &c[k];
          while ( 1 )
          {
            a = *v63;
            if ( a != 0 )
              break;
LABEL_66:
            ++v63;
            k = ++v28;
            if ( v28 > g )
            {
              v20 = y;
              goto LABEL_68;
            }
          }
          while ( 1 )
          {
            --a;
            v32 = v30 + v13;
            if ( k > (int)(v30 + v13) )
              break;
LABEL_49:
            r.word.what.Bits = k - v30;
            if ( pa < &v[na] )
            {
              v46 = *pa;
              if ( *pa >= s )
              {
                v47 = v46 - s;
                r.word.what.Exop = LOBYTE(e[v47]) + 80;
                base = d[v47];
              }
              else
              {
                r.word.what.Exop = v46 < 0x100 ? 0 : 96;
                base = v46;
              }
              ++pa;
            }
            else
            {
              r.word.what.Exop = -64;
            }
            v48 = 1 << (k - v30);
            v49 = v29 >> v30;
            if ( v29 >> v30 < z )
            {
              v50 = &xp[2 * v49];
              do
              {
                *v50 = r.word.pad;
                v50[1] = base;
                v49 += v48;
                v50 += 2 * v48;
              }
              while ( v49 < z );
              v29 = i;
            }
            for ( jj = 1 << (k - 1); (jj & v29) != 0; jj >>= 1 )
              v29 ^= jj;
            v29 ^= jj;
            v52 = h;
            i = v29;
            if ( (v29 & ((1 << v30) - 1)) != x[h] )
            {
              do
              {
                v30 -= l;
                --v52;
              }
              while ( (v29 & ((1 << v30) - 1)) != x[v52] );
              h = v52;
            }
            v13 = l;
            if ( a == 0 )
            {
              v28 = k;
              goto LABEL_66;
            }
          }
          v58 = a + 1;
          v59 = v30 - v13;
          while ( 1 )
          {
            v59 += v13;
            ++h;
            v30 = v32;
            v33 = g - v32;
            if ( g - v32 > (unsigned int)l )
              v33 = l;
            v34 = k - v32;
            if ( 1 << (k - v32) > v58 )
            {
              v35 = -1 - a + (1 << v34);
              v36 = v63;
              if ( v34 < v33 && ++v34 < v33 )
              {
                while ( 1 )
                {
                  xp = v36 + 1;
                  v37 = v36[1];
                  v38 = 2 * v35;
                  if ( v38 <= v37 )
                    break;
                  ++v34;
                  v35 = v38 - v37;
                  if ( v34 >= v33 )
                    break;
                  v36 = xp;
                }
              }
            }
            v39 = *hn;
            z = 1 << v34;
            v40 = v39 + (1 << v34);
            if ( v40 > 0x5A0 )
              return -4;
            v41 = &hp[v39];
            v57 = &u[h];
            *v57 = v41;
            *hn = v40;
            xp = &v41->word.pad;
            if ( h != 0 )
            {
              v42 = i;
              v43 = l;
              x[h] = i;
              r.word.what.Exop = v34;
              v44 = v42 >> v59;
              v45 = (int)*(v57 - 1);
              r.word.what.Bits = v43;
              base = (((int)v41 - v45) >> 3) - (v42 >> v59);
              *(_DWORD *)(v45 + 8 * v44) = r.word.pad;
              *(_DWORD *)(v45 + 8 * v44 + 4) = base;
            }
            else
            {
              *t = v41;
            }
            v32 = v30 + l;
            if ( k <= v30 + l )
            {
              v29 = i;
              goto LABEL_49;
            }
            v13 = l;
          }
        }
      }
      else
      {
        return -3;
      }
    }
    else
    {
      while ( 1 )
      {
        v17 = v16 - c[j];
        if ( v17 < 0 )
          return -3;
        ++j;
        v16 = 2 * v17;
        if ( j >= ii )
          goto LABEL_18;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7460
// Name: int inflate_trees_bits(unsigned int __near *,unsigned int __near *,struct inflate_huft_s __near * __near *,struct inflate_huft_s __near *,struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_trees_bits(
        unsigned int *c,
        unsigned int *bb,
        inflate_huft_s **tb,
        inflate_huft_s *hp,
        z_stream_s *z)
{
  void *(__cdecl *zalloc)(void *, unsigned int, unsigned int); // ecx
  unsigned int *v6; // eax
  unsigned int *v7; // ebx
  int v9; // eax
  int v10; // esi
  void *opaque; // [esp-Ch] [ebp-18h]
  unsigned int hn; // [esp+8h] [ebp-4h] BYREF

  zalloc = z->zalloc;
  opaque = z->opaque;
  hn = 0;
  v6 = (unsigned int *)zalloc(a1: opaque, a2: 19u, a3: 4u);
  v7 = v6;
  if ( v6 == nullptr )
    return -4;
  v9 = huft_build(b: c, n: 0x13u, s: 0x13u, d: nullptr, e: nullptr, t: tb, m: bb, hp, &hn, v: v6);
  v10 = v9;
  if ( v9 == -3 )
  {
    z->msg = "oversubscribed dynamic bit lengths tree";
  }
  else if ( v9 == -5 || *bb == 0 )
  {
    z->msg = "incomplete dynamic bit lengths tree";
    v10 = -3;
  }
  z->zfree(a1: z->opaque, a2: v7);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x101F7500
// Name: int inflate_trees_dynamic(unsigned int,unsigned int,unsigned int __near *,unsigned int __near *,unsigned int __near *,struct inflate_huft_s __near * __near *,struct inflate_huft_s __near * __near *,struct inflate_huft_s __near *,struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_trees_dynamic(
        unsigned int nl,
        unsigned int nd,
        unsigned int *c,
        unsigned int *bl,
        unsigned int *bd,
        inflate_huft_s **tl,
        inflate_huft_s **td,
        inflate_huft_s *hp,
        z_stream_s *z)
{
  void *(__cdecl *zalloc)(void *, unsigned int, unsigned int); // ecx
  unsigned int *v10; // eax
  unsigned int *v11; // edi
  int v13; // eax
  int v14; // esi
  int v15; // eax
  void (__cdecl *zfree)(void *, void *); // eax
  void (__cdecl *v17)(void *, void *); // eax
  void *opaque; // [esp-Ch] [ebp-18h]
  void *v19; // [esp-Ch] [ebp-18h]
  void *v20; // [esp-Ch] [ebp-18h]
  unsigned int hn; // [esp+8h] [ebp-4h] BYREF

  zalloc = z->zalloc;
  opaque = z->opaque;
  hn = 0;
  v10 = (unsigned int *)zalloc(a1: opaque, a2: 288u, a3: 4u);
  v11 = v10;
  if ( v10 == nullptr )
    return -4;
  v13 = huft_build(b: c, n: nl, s: 0x101u, d: cplens, e: cplext, t: tl, m: bl, hp, &hn, v: v10);
  v14 = v13;
  if ( v13 != 0 )
  {
    if ( v13 == -3 )
    {
      z->msg = "oversubscribed literal/length tree";
      goto LABEL_20;
    }
    if ( v13 == -4 )
      goto LABEL_20;
LABEL_19:
    z->msg = "incomplete literal/length tree";
    v14 = -3;
    goto LABEL_20;
  }
  if ( *bl == 0 )
    goto LABEL_19;
  v15 = huft_build(b: &c[nl], n: nd, s: 0, d: cpdist, e: cpdext, t: td, m: bd, hp, &hn, v: v11);
  v14 = v15;
  switch ( v15 )
  {
    case 0:
      if ( *bd != 0 || nl <= 0x101 )
      {
        z->zfree(a1: z->opaque, a2: v11);
        return 0;
      }
LABEL_14:
      z->msg = "empty distance tree with lengths";
      v14 = -3;
      goto LABEL_20;
    case -3:
      zfree = z->zfree;
      v19 = z->opaque;
      z->msg = "oversubscribed distance tree";
      zfree(a1: v19, a2: v11);
      return -3;
    case -5:
      v17 = z->zfree;
      v20 = z->opaque;
      z->msg = "incomplete distance tree";
      v17(a1: v20, a2: v11);
      return -3;
    default:
      break;
  }
  if ( v15 != -4 )
    goto LABEL_14;
LABEL_20:
  z->zfree(a1: z->opaque, a2: v11);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x101F7680
// Name: int inflate_fast(unsigned int,unsigned int,struct inflate_huft_s const __near *,struct inflate_huft_s const __near *,struct inflate_blocks_state __near *,struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_fast(
        unsigned int bl,
        unsigned int bd,
        const inflate_huft_s *tl,
        const inflate_huft_s *td,
        inflate_blocks_state *s,
        z_stream_s *z)
{
  unsigned __int8 *read; // esi
  unsigned int bitk; // eax
  unsigned __int8 *write; // edi
  unsigned int bitb; // edx
  int v10; // esi
  int v11; // esi
  int Exop; // ebx
  const inflate_huft_s *v13; // esi
  int Bits; // ecx
  unsigned int v15; // ecx
  int v16; // ebx
  unsigned int v17; // eax
  unsigned int i; // edx
  int v19; // ebx
  int v20; // ebx
  const inflate_huft_s *v21; // esi
  unsigned int v22; // ecx
  int v23; // ecx
  unsigned int v24; // ebx
  int v25; // edi
  int v26; // edi
  char v27; // cl
  unsigned int v28; // ebx
  unsigned __int8 *window; // ecx
  unsigned __int8 *v30; // esi
  unsigned __int8 *v31; // esi
  unsigned int v32; // ecx
  int v33; // esi
  unsigned int v34; // ecx
  int v35; // ecx
  z_stream_s *v37; // ecx
  unsigned int v38; // ecx
  int v39; // ecx
  unsigned int v40; // esi
  int v41; // edx
  unsigned int md; // [esp+Ch] [ebp-18h]
  unsigned int ml; // [esp+10h] [ebp-14h]
  unsigned __int8 *q; // [esp+14h] [ebp-10h]
  unsigned __int8 *m; // [esp+18h] [ebp-Ch]
  unsigned int n; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *p; // [esp+20h] [ebp-4h]
  unsigned __int8 *pa; // [esp+20h] [ebp-4h]
  unsigned __int8 *pb; // [esp+20h] [ebp-4h]
  unsigned __int8 *pc; // [esp+20h] [ebp-4h]
  unsigned int d; // [esp+2Ch] [ebp+8h]
  unsigned int c; // [esp+30h] [ebp+Ch]
  unsigned int ca; // [esp+30h] [ebp+Ch]

  p = z->next_in;
  read = s->read;
  bitk = s->bitk;
  write = s->write;
  n = z->avail_in;
  bitb = s->bitb;
  q = write;
  if ( write >= read )
    m = (unsigned __int8 *)(s->end - write);
  else
    m = (unsigned __int8 *)(read - write - 1);
  ml = inflate_mask[bl];
  md = inflate_mask[bd];
  while ( 1 )
  {
    for ( ; bitk < 0x14; bitb |= v11 )
    {
      v10 = *p;
      --n;
      ++p;
      v11 = v10 << bitk;
      bitk += 8;
    }
    Exop = tl[bitb & ml].word.what.Exop;
    v13 = &tl[bitb & ml];
    Bits = v13->word.what.Bits;
    bitb >>= Bits;
    if ( Exop == 0 )
    {
LABEL_29:
      bitk -= Bits;
      *write++ = v13->base;
      --m;
      goto LABEL_30;
    }
    bitk -= v13->word.what.Bits;
    if ( (Exop & 0x10) == 0 )
      break;
LABEL_12:
    v16 = Exop & 0xF;
    v17 = bitk - v16;
    c = v13->base + (bitb & inflate_mask[v16]);
    for ( i = bitb >> v16; v17 < 0xF; i |= v19 )
    {
      --n;
      v19 = *p << v17;
      v17 += 8;
      ++p;
    }
    v20 = td[i & md].word.what.Exop;
    v21 = &td[i & md];
    bitb = i >> v21->word.what.Bits;
    bitk = v17 - v21->word.what.Bits;
    if ( (v20 & 0x10) == 0 )
    {
      while ( (v20 & 0x40) == 0 )
      {
        v22 = v21->base + (bitb & inflate_mask[v20]);
        v20 = v21[v22].word.what.Exop;
        v21 += v22;
        v23 = v21->word.what.Bits;
        bitb >>= v23;
        bitk -= v23;
        if ( (v20 & 0x10) != 0 )
          goto LABEL_17;
      }
      v37 = z;
      z->msg = "invalid distance code";
      goto LABEL_41;
    }
LABEL_17:
    v24 = v20 & 0xF;
    if ( bitk < v24 )
    {
      do
      {
        v25 = *p;
        --n;
        ++p;
        v26 = v25 << bitk;
        bitk += 8;
        bitb |= v26;
      }
      while ( bitk < v24 );
      write = q;
    }
    bitk -= v24;
    d = v21->base + (bitb & inflate_mask[v24]);
    v27 = v24;
    v28 = c;
    m -= c;
    bitb >>= v27;
    window = s->window;
    if ( write - window < d )
    {
      v32 = d + window - write;
      v31 = &s->end[-v32];
      if ( c > v32 )
      {
        ca = c - v32;
        do
        {
          *write++ = *v31++;
          --v32;
        }
        while ( v32 != 0 );
        v31 = s->window;
        v28 = ca;
      }
    }
    else
    {
      v30 = &write[-d];
      write += 2;
      *(write - 2) = *v30;
      *(write - 1) = v30[1];
      v31 = v30 + 2;
      v28 = c - 2;
    }
    v33 = v31 - write;
    do
    {
      *write = write[v33];
      ++write;
      --v28;
    }
    while ( v28 != 0 );
LABEL_30:
    q = write;
    if ( (unsigned int)m < 0x102 || n < 0xA )
    {
      v34 = z->avail_in - n;
      if ( bitk >> 3 < v34 )
        v34 = bitk >> 3;
      pa = &p[-v34];
      s->bitb = bitb;
      s->bitk = bitk - 8 * v34;
      z->avail_in = n + v34;
      v35 = pa - z->next_in;
      z->next_in = pa;
      z->total_in += v35;
      s->write = write;
      return 0;
    }
  }
  while ( (Exop & 0x40) == 0 )
  {
    v15 = v13->base + (bitb & inflate_mask[Exop]);
    Exop = v13[v15].word.what.Exop;
    v13 += v15;
    Bits = v13->word.what.Bits;
    bitb >>= Bits;
    if ( Exop == 0 )
      goto LABEL_29;
    bitk -= v13->word.what.Bits;
    if ( (Exop & 0x10) != 0 )
      goto LABEL_12;
  }
  if ( (Exop & 0x20) == 0 )
  {
    v37 = z;
    z->msg = "invalid literal/length code";
LABEL_41:
    v40 = v37->avail_in - n;
    if ( bitk >> 3 < v40 )
      v40 = bitk >> 3;
    pc = &p[-v40];
    s->bitb = bitb;
    s->bitk = bitk - 8 * v40;
    v41 = pc - v37->next_in;
    v37->next_in = pc;
    v37->total_in += v41;
    v37->avail_in = n + v40;
    s->write = write;
    return -3;
  }
  v38 = z->avail_in - n;
  if ( bitk >> 3 < v38 )
    v38 = bitk >> 3;
  pb = &p[-v38];
  s->bitb = bitb;
  s->bitk = bitk - 8 * v38;
  z->avail_in = n + v38;
  v39 = pb - z->next_in;
  z->next_in = pb;
  z->total_in += v39;
  s->write = write;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F7990
// Name: unsigned long ucrc32(unsigned long,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ucrc32(unsigned int crc, const unsigned __int8 *buf, unsigned int len)
{
  const unsigned __int8 *v3; // ecx
  unsigned int v5; // edx
  unsigned int v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax

  v3 = buf;
  if ( buf == nullptr )
    return 0;
  v5 = len;
  v6 = ~crc;
  if ( len >= 8 )
  {
    v7 = len >> 3;
    do
    {
      v8 = crc_table[(unsigned __int8)(v6 ^ *v3)] ^ (v6 >> 8);
      v9 = crc_table[(unsigned __int8)(v8 ^ v3[1])] ^ (v8 >> 8);
      v10 = crc_table[(unsigned __int8)(v9 ^ v3[2])] ^ (v9 >> 8);
      v11 = crc_table[(unsigned __int8)(v10 ^ v3[3])] ^ (v10 >> 8);
      v12 = crc_table[(unsigned __int8)(v11 ^ v3[4])] ^ (v11 >> 8);
      v13 = crc_table[(unsigned __int8)(v12 ^ v3[5])] ^ (v12 >> 8);
      v14 = crc_table[(unsigned __int8)(v13 ^ v3[6])] ^ (v13 >> 8);
      v6 = crc_table[(unsigned __int8)(v14 ^ v3[7])] ^ (v14 >> 8);
      v3 += 8;
      v5 -= 8;
      --v7;
    }
    while ( v7 != 0 );
  }
  for ( ; v5 != 0; --v5 )
    v6 = crc_table[(unsigned __int8)(v6 ^ *v3++)] ^ (v6 >> 8);
  return ~v6;
}

//------------------------------------------------------------------------------
// Address: 0x101F7AA0
// Name: unsigned long adler32(unsigned long,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl adler32(unsigned int adler, const unsigned __int8 *buf, unsigned int len)
{
  const unsigned __int8 *v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // edi
  unsigned int i; // ebx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // ecx
  int v11; // edi
  int v12; // ecx
  int v13; // edi
  int v14; // ecx
  int v15; // edi
  int v16; // ecx
  int v17; // edi
  int v18; // ecx
  int v19; // edi
  int v20; // ecx
  int v21; // edi
  int v22; // ecx
  int v23; // edi
  int v24; // ecx
  int v25; // edi
  int v26; // ecx
  int v27; // edi
  int v28; // ecx
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

  v3 = buf;
  v4 = (unsigned __int16)adler;
  v5 = HIWORD(adler);
  if ( buf == nullptr )
    return 1;
  for ( i = len; i != 0; v5 %= 0xFFF1u )
  {
    v8 = i;
    if ( i >= 0x15B0 )
      v8 = 5552;
    i -= v8;
    if ( v8 >= 16 )
    {
      v9 = (unsigned int)v8 >> 4;
      v8 += -16 * ((unsigned int)v8 >> 4);
      do
      {
        v10 = *v3 + v4;
        v11 = v10 + v5;
        v12 = v3[1] + v10;
        v13 = v12 + v11;
        v14 = v3[2] + v12;
        v15 = v14 + v13;
        v16 = v3[3] + v14;
        v17 = v16 + v15;
        v18 = v3[4] + v16;
        v19 = v18 + v17;
        v20 = v3[5] + v18;
        v21 = v20 + v19;
        v22 = v3[6] + v20;
        v23 = v22 + v21;
        v24 = v3[7] + v22;
        v25 = v24 + v23;
        v26 = v3[8] + v24;
        v27 = v26 + v25;
        v28 = v3[9] + v26;
        v29 = v28 + v27;
        v30 = v3[10] + v28;
        v31 = v30 + v29;
        v32 = v3[11] + v30;
        v33 = v32 + v31;
        v34 = v3[12] + v32;
        v35 = v34 + v33;
        v36 = v3[13] + v34;
        v37 = v36 + v35;
        v38 = v3[14] + v36;
        v39 = v38 + v37;
        v4 = v3[15] + v38;
        v5 = v4 + v39;
        v3 += 16;
        --v9;
      }
      while ( v9 != 0 );
    }
    for ( ; v8 != 0; --v8 )
    {
      v4 += *v3++;
      v5 += v4;
    }
    v4 %= 0xFFF1u;
  }
  return v4 | (v5 << 16);
}

//------------------------------------------------------------------------------
// Address: 0x101F7BE0
// Name: void __near * zcalloc(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl zcalloc(void *opaque, unsigned int items, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * items);
  memset(dst: v3, value: 0, count: size * items);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101F7C10
// Name: void zcfree(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl zcfree(void *opaque, void *ptr)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x101F7C30
// Name: int inflateReset(struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflateReset(z_stream_s *z)
{
  internal_state *state; // ecx

  if ( z == nullptr )
    return -2;
  state = z->state;
  if ( state == nullptr )
    return -2;
  z->total_out = 0;
  z->total_in = 0;
  z->msg = nullptr;
  state->mode = state->nowrap != 0 ? IM_BLOCKS : IM_METHOD;
  inflate_blocks_reset(s: z->state->blocks, z, c: nullptr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F7C80
// Name: int inflateEnd(struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflateEnd(z_stream_s *z)
{
  internal_state *state; // eax
  inflate_blocks_state *blocks; // eax

  if ( z == nullptr )
    return -2;
  state = z->state;
  if ( state == nullptr || z->zfree == nullptr )
    return -2;
  blocks = state->blocks;
  if ( blocks != nullptr )
    inflate_blocks_free(s: blocks, z);
  z->zfree(a1: z->opaque, a2: z->state);
  z->state = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F7CD0
// Name: int inflateInit2(struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflateInit2(z_stream_s *z)
{
  internal_state *v2; // eax
  inflate_blocks_state *v3; // eax

  if ( z == nullptr )
    return -2;
  z->msg = nullptr;
  if ( z->zalloc == nullptr )
  {
    z->zalloc = (void *(__cdecl *)(void *, unsigned int, unsigned int))zcalloc;
    z->opaque = nullptr;
  }
  if ( z->zfree == nullptr )
    z->zfree = zcfree;
  v2 = (internal_state *)z->zalloc(a1: z->opaque, a2: 1, a3: 24);
  z->state = v2;
  if ( v2 == nullptr )
    return -4;
  v2->blocks = nullptr;
  z->state->nowrap = 0;
  z->state->nowrap = 1;
  z->state->wbits = 15;
  v3 = inflate_blocks_new(
         z,
         c: z->state->nowrap == 0
       ? (unsigned int (__cdecl *)(unsigned int, const unsigned __int8 *, unsigned int))adler32
       : nullptr,
         w: 0x8000u);
  z->state->blocks = v3;
  if ( v3 == nullptr )
  {
    inflateEnd(z);
    return -4;
  }
  inflateReset(z);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F7D90
// Name: struct LUFILE __near * lufopen(void __near *,unsigned int,unsigned long,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
LUFILE *__cdecl lufopen(void *z, unsigned int len, void *flags, unsigned int *err)
{
  void *v4; // edi
  LUFILE *result; // eax
  unsigned int *v6; // esi
  bool v7; // bl
  HANDLE FileA; // eax
  HANDLE v9; // eax
  LUFILE *v10; // esi
  unsigned int *v11; // edx
  HANDLE CurrentProcess; // [esp-1Ch] [ebp-20h]

  v4 = flags;
  if ( flags != (void *)1 && flags != (void *)2 && flags != (void *)3 )
  {
    *err = 0x10000;
    return nullptr;
  }
  v6 = err;
  v7 = false;
  flags = nullptr;
  *err = 0;
  if ( v4 == (void *)1 )
  {
    CurrentProcess = GetCurrentProcess();
    v9 = GetCurrentProcess();
    if ( !DuplicateHandle(
            hSourceProcessHandle: v9,
            hSourceHandle: z,
            hTargetProcessHandle: CurrentProcess,
            lpTargetHandle: &flags,
            dwDesiredAccess: 0,
            bInheritHandle: false,
            dwOptions: 2u) )
    {
      *v6 = 256;
      return nullptr;
    }
    FileA = flags;
    goto LABEL_12;
  }
  if ( v4 == (void *)2 )
  {
    FileA = CreateFileA(
              lpFileName: (LPCSTR)z,
              dwDesiredAccess: 0x80000000,
              dwShareMode: 1u,
              lpSecurityAttributes: nullptr,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: 0x80u,
              hTemplateFile: nullptr);
    flags = FileA;
    if ( FileA == (HANDLE)-1 )
    {
      *v6 = 512;
      return nullptr;
    }
LABEL_12:
    v7 = GetFileType(hFile: FileA) == 1;
  }
  result = (LUFILE *)MemAlloc_Alloc(nSize: 0x1Cu);
  v10 = result;
  if ( v4 == (void *)1 || v4 == (void *)2 )
  {
    result->is_handle = true;
    result->canseek = v7;
    result->h = flags;
    result->herr = false;
    result->initial_offset = 0;
    if ( v7 )
      result->initial_offset = SetFilePointer(
                                 hFile: flags,
                                 lDistanceToMove: 0,
                                 lpDistanceToMoveHigh: nullptr,
                                 dwMoveMethod: 1u);
    *err = 0;
    return v10;
  }
  else
  {
    result->len = len;
    v11 = err;
    result->pos = 0;
    result->initial_offset = 0;
    *(_WORD *)&result->is_handle = 256;
    result->buf = z;
    *v11 = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F7EC0
// Name: unsigned int lufread(void __near *,unsigned int,unsigned int,struct LUFILE __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl lufread(void *ptr, unsigned int size, unsigned int n, LUFILE *stream)
{
  unsigned int v4; // ebx
  LUFILE *v5; // edi
  unsigned int v6; // esi
  unsigned int pos; // ecx
  unsigned int len; // eax

  v4 = size;
  v5 = stream;
  v6 = n * size;
  if ( stream->is_handle )
  {
    if ( !ReadFile(
            hFile: stream->h,
            lpBuffer: ptr,
            nNumberOfBytesToRead: n * size,
            lpNumberOfBytesRead: &size,
            lpOverlapped: nullptr) )
      v5->herr = true;
    return size / v4;
  }
  else
  {
    pos = stream->pos;
    len = stream->len;
    if ( pos + v6 > len )
      v6 = len - pos;
    memcpy(dst: (unsigned __int8 *)ptr, src: (unsigned __int8 *)stream->buf + pos, count: v6);
    v5->pos += v6;
    return v6 / v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7F40
// Name: int unzlocal_getShort(struct LUFILE __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzlocal_getShort(LUFILE *fin, unsigned int *pX)
{
  int v2; // esi
  int result; // eax
  int v4; // ebx
  unsigned __int8 ptr; // [esp+Fh] [ebp-1h] BYREF

  v2 = 0;
  if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
  {
    v2 = ptr;
LABEL_3:
    result = 0;
    goto LABEL_4;
  }
  if ( !fin->is_handle || !fin->herr )
    goto LABEL_3;
  result = -1;
LABEL_4:
  v4 = v2;
  if ( result == 0 )
  {
    if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
    {
      v2 = ptr;
LABEL_7:
      *pX = v4 + (v2 << 8);
      return 0;
    }
    if ( !fin->is_handle || !fin->herr )
      goto LABEL_7;
    result = -1;
  }
  *pX = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F7FD0
// Name: int unzlocal_getLong(struct LUFILE __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzlocal_getLong(LUFILE *fin, unsigned int *pX)
{
  int v2; // esi
  int result; // eax
  int v4; // ebx
  int v5; // ebx
  int v6; // ebx
  unsigned __int8 ptr; // [esp+Fh] [ebp-1h] BYREF

  v2 = 0;
  if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
  {
    v2 = ptr;
LABEL_3:
    result = 0;
    goto LABEL_4;
  }
  if ( !fin->is_handle || !fin->herr )
    goto LABEL_3;
  result = -1;
LABEL_4:
  v4 = v2;
  if ( result == 0 )
  {
    if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
    {
      v2 = ptr;
LABEL_7:
      result = 0;
      goto LABEL_8;
    }
    if ( !fin->is_handle || !fin->herr )
      goto LABEL_7;
    result = -1;
  }
LABEL_8:
  v5 = (v2 << 8) + v4;
  if ( result == 0 )
  {
    if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
    {
      v2 = ptr;
LABEL_11:
      result = 0;
      goto LABEL_12;
    }
    if ( !fin->is_handle || !fin->herr )
      goto LABEL_11;
    result = -1;
  }
LABEL_12:
  v6 = (v2 << 16) + v5;
  if ( result == 0 )
  {
    if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
    {
      v2 = ptr;
LABEL_15:
      *pX = v6 + (v2 << 24);
      return 0;
    }
    if ( !fin->is_handle || !fin->herr )
      goto LABEL_15;
    result = -1;
  }
  *pX = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F80F0
// Name: int strcmpcasenosensitive_internal(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl strcmpcasenosensitive_internal(const char *fileName1, const char *fileName2)
{
  const char *v2; // esi
  char v3; // al
  char v4; // cl

  v2 = fileName2;
  while ( 1 )
  {
    v3 = v2[fileName1 - fileName2];
    v4 = *v2++;
    if ( (unsigned __int8)(v3 - 97) <= 0x19u )
      v3 -= 32;
    if ( (unsigned __int8)(v4 - 97) <= 0x19u )
      v4 -= 32;
    if ( v3 == 0 )
      return -(v4 != 0);
    if ( v4 == 0 )
      return 1;
    if ( v3 < v4 )
      break;
    if ( v3 > v4 )
      return 1;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101F8150
// Name: unsigned long unzlocal_SearchCentralDir(struct LUFILE __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl unzlocal_SearchCentralDir(LUFILE *fin)
{
  DWORD pos; // ebx
  unsigned __int8 *result; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  DWORD v8; // ebx
  unsigned int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int len; // ecx
  int v13; // eax
  unsigned int uReadPos; // [esp+4h] [ebp-18h]
  unsigned int NumberOfBytesRead; // [esp+8h] [ebp-14h] BYREF
  unsigned int uPosFound; // [esp+Ch] [ebp-10h]
  unsigned __int8 *buf; // [esp+10h] [ebp-Ch]
  unsigned int uBackRead; // [esp+14h] [ebp-8h]
  unsigned int uMaxBack; // [esp+18h] [ebp-4h]
  LUFILE *fina; // [esp+24h] [ebp+8h]

  if ( fin->is_handle )
  {
    if ( !fin->canseek )
      return nullptr;
    SetFilePointer(hFile: fin->h, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 2u);
  }
  else
  {
    fin->pos = fin->len;
  }
  if ( fin->is_handle )
  {
    if ( fin->canseek )
    {
      pos = SetFilePointer(hFile: fin->h, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 1u)
          - fin->initial_offset;
      fina = (LUFILE *)pos;
    }
    else
    {
      fina = nullptr;
      pos = 0;
    }
  }
  else
  {
    fina = (LUFILE *)fin->pos;
    pos = fin->pos;
  }
  v4 = 0xFFFF;
  uMaxBack = 0xFFFF;
  if ( pos < 0xFFFF )
  {
    uMaxBack = pos;
    v4 = pos;
  }
  result = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1028);
  buf = result;
  if ( result != nullptr )
  {
    v5 = 4;
    uPosFound = 0;
    if ( v4 > 4 )
    {
      while ( 1 )
      {
        v6 = v5 + 1024;
        uBackRead = v4;
        if ( v6 <= v4 )
          uBackRead = v6;
        v7 = pos - uBackRead;
        v8 = uBackRead;
        uReadPos = v7;
        if ( uBackRead > 0x404 )
          v8 = 1028;
        if ( fin->is_handle )
        {
          if ( !fin->canseek )
            break;
          SetFilePointer(
            hFile: fin->h,
            lDistanceToMove: v7 + fin->initial_offset,
            lpDistanceToMoveHigh: nullptr,
            dwMoveMethod: 0);
        }
        else
        {
          fin->pos = v7;
        }
        v9 = v8;
        if ( fin->is_handle )
        {
          if ( !ReadFile(
                  hFile: fin->h,
                  lpBuffer: buf,
                  nNumberOfBytesToRead: v8,
                  lpNumberOfBytesRead: &NumberOfBytesRead,
                  lpOverlapped: nullptr) )
            fin->herr = true;
          v10 = NumberOfBytesRead;
        }
        else
        {
          v11 = fin->pos;
          len = fin->len;
          if ( v11 + v8 > len )
            v9 = len - v11;
          memcpy(dst: buf, src: (unsigned __int8 *)fin->buf + v11, count: v9);
          fin->pos += v9;
          v10 = v9;
        }
        if ( v10 / v8 != 1 )
          break;
        v13 = v8 - 3;
        if ( (int)(v8 - 3) > 0 )
        {
          while ( buf[--v13] != 80 || buf[v13 + 1] != 75 || buf[v13 + 2] != 5 || buf[v13 + 3] != 6 )
          {
            if ( v13 <= 0 )
              goto LABEL_41;
          }
          uPosFound = uReadPos + v13;
          if ( uReadPos + v13 != 0 )
            break;
        }
LABEL_41:
        if ( uBackRead >= uMaxBack )
          break;
        v4 = uMaxBack;
        v5 = uBackRead;
        pos = (DWORD)fina;
      }
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf);
    return (unsigned __int8 *)uPosFound;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8330
// Name: int unzlocal_GetCurrentFileInfoInternal(struct unz_s __near *,struct unz_file_info_s __near *,struct unz_file_info_internal_s __near *,char __near *,unsigned long,void __near *,unsigned long,char __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzlocal_GetCurrentFileInfoInternal(
        unz_s *file,
        unz_file_info_s *pfile_info,
        unz_file_info_internal_s *pfile_info_internal,
        char *szFileName,
        unsigned int fileNameBufferSize,
        void *extraField,
        unsigned int extraFieldBufferSize,
        char *szComment,
        unsigned int commentBufferSize)
{
  LUFILE *v10; // eax
  unsigned int v11; // ecx
  LONG size_filename; // esi
  unsigned int v13; // edi
  unsigned int size_file_extra; // edi
  unsigned int v15; // ecx
  unsigned int v16; // ebx
  LUFILE *v17; // eax
  LONG v18; // esi
  char *v19; // ecx
  unsigned int size_file_comment; // edi
  unsigned int v21; // edx
  unsigned int v22; // ebx
  LUFILE *v23; // eax
  LUFILE *v24; // [esp-10h] [ebp-6Ch]
  unz_file_info_s file_info; // [esp+4h] [ebp-58h] BYREF
  unsigned int uMagic; // [esp+54h] [ebp-8h] BYREF
  int err; // [esp+58h] [ebp-4h]

  err = 0;
  if ( file == nullptr )
    return -102;
  v10 = file->file;
  v11 = file->byte_before_the_zipfile + file->pos_in_central_dir;
  if ( !file->file->is_handle )
  {
    v10->pos = v11;
LABEL_6:
    if ( unzlocal_getLong(fin: file->file, pX: &uMagic) != 0 )
    {
      err = -1;
    }
    else if ( uMagic != 33639248 )
    {
      err = -103;
    }
    goto LABEL_12;
  }
  if ( v10->canseek )
  {
    SetFilePointer(
      hFile: v10->h,
      lDistanceToMove: v11 + v10->initial_offset,
      lpDistanceToMoveHigh: nullptr,
      dwMoveMethod: 0);
    goto LABEL_6;
  }
  err = -1;
LABEL_12:
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.version) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.version_needed) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.flag) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.compression_method) != 0 )
    err = -1;
  if ( unzlocal_getLong(fin: file->file, pX: &file_info.dosDate) != 0 )
    err = -1;
  file_info.tmu_date.tm_mday = BYTE2(file_info.dosDate) & 0x1F;
  file_info.tmu_date.tm_year = (file_info.dosDate >> 25) + 1980;
  file_info.tmu_date.tm_mon = ((file_info.dosDate >> 21) & 0xF) - 1;
  file_info.tmu_date.tm_hour = LOWORD(file_info.dosDate) >> 11;
  file_info.tmu_date.tm_sec = 2 * (file_info.dosDate & 0x1F);
  v24 = file->file;
  file_info.tmu_date.tm_min = (file_info.dosDate >> 5) & 0x3F;
  if ( unzlocal_getLong(fin: v24, pX: &file_info.crc) != 0 )
    err = -1;
  if ( unzlocal_getLong(fin: file->file, pX: &file_info.compressed_size) != 0 )
    err = -1;
  if ( unzlocal_getLong(fin: file->file, pX: &file_info.uncompressed_size) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.size_filename) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.size_file_extra) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.size_file_comment) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.disk_num_start) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.internal_fa) != 0 )
    err = -1;
  if ( unzlocal_getLong(fin: file->file, pX: &file_info.external_fa) != 0 )
    err = -1;
  if ( unzlocal_getLong(fin: file->file, pX: &uMagic) != 0 )
    err = -1;
  size_filename = file_info.size_filename;
  if ( err != 0 )
    goto LABEL_66;
  if ( szFileName != nullptr )
  {
    if ( file_info.size_filename >= fileNameBufferSize )
    {
      v13 = fileNameBufferSize;
    }
    else
    {
      szFileName[file_info.size_filename] = 0;
      v13 = size_filename;
    }
    if ( size_filename != 0
      && fileNameBufferSize != 0
      && lufread(ptr: szFileName, size: v13, n: 1u, stream: file->file) != 1 )
    {
      err = -1;
    }
    size_filename -= v13;
    if ( err != 0 )
      goto LABEL_66;
  }
  if ( extraField == nullptr )
  {
LABEL_66:
    v18 = file_info.size_file_extra + size_filename;
  }
  else
  {
    size_file_extra = file_info.size_file_extra;
    v15 = extraFieldBufferSize;
    v16 = file_info.size_file_extra;
    if ( file_info.size_file_extra >= extraFieldBufferSize )
      v16 = extraFieldBufferSize;
    if ( size_filename != 0 )
    {
      v17 = file->file;
      if ( file->file->is_handle )
      {
        if ( v17->canseek )
        {
          SetFilePointer(hFile: v17->h, lDistanceToMove: size_filename, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 1u);
          v15 = extraFieldBufferSize;
          size_filename = 0;
        }
        else
        {
          err = -1;
        }
      }
      else
      {
        v17->pos += size_filename;
        size_filename = 0;
      }
    }
    if ( size_file_extra != 0 && v15 != 0 && lufread(ptr: extraField, size: v16, n: 1u, stream: file->file) != 1 )
      err = -1;
    v18 = size_file_extra - v16 + size_filename;
  }
  if ( err == 0 )
  {
    v19 = szComment;
    if ( szComment == nullptr )
      goto LABEL_83;
    size_file_comment = file_info.size_file_comment;
    v21 = commentBufferSize;
    if ( file_info.size_file_comment >= commentBufferSize )
    {
      v22 = commentBufferSize;
    }
    else
    {
      szComment[file_info.size_file_comment] = 0;
      v22 = size_file_comment;
    }
    if ( v18 != 0 )
    {
      v23 = file->file;
      if ( file->file->is_handle )
      {
        if ( v23->canseek )
        {
          SetFilePointer(hFile: v23->h, lDistanceToMove: v18, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 1u);
          v21 = commentBufferSize;
          v19 = szComment;
        }
        else
        {
          err = -1;
        }
      }
      else
      {
        v23->pos += v18;
      }
    }
    if ( size_file_comment != 0 && v21 != 0 && lufread(ptr: v19, size: v22, n: 1u, stream: file->file) != 1 )
    {
      err = -1;
      return -1;
    }
    if ( err == 0 )
    {
LABEL_83:
      if ( pfile_info != nullptr )
        *pfile_info = file_info;
      if ( pfile_info_internal != nullptr )
        pfile_info_internal->offset_curfile = uMagic;
    }
  }
  return err;
}

//------------------------------------------------------------------------------
// Address: 0x101F86D0
// Name: int unzGoToFirstFile(struct unz_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzGoToFirstFile(unz_s *file)
{
  int result; // eax

  if ( file == nullptr )
    return -102;
  file->pos_in_central_dir = file->offset_central_dir;
  file->num_file = 0;
  result = unzlocal_GetCurrentFileInfoInternal(
             file,
             pfile_info: &file->cur_file_info,
             pfile_info_internal: &file->cur_file_info_internal,
             szFileName: nullptr,
             fileNameBufferSize: 0,
             extraField: nullptr,
             extraFieldBufferSize: 0,
             szComment: nullptr,
             commentBufferSize: 0);
  file->current_file_ok = result == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8720
// Name: int unzGoToNextFile(struct unz_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzGoToNextFile(unz_s *file)
{
  int result; // eax
  unsigned int v2; // eax

  if ( file == nullptr )
    return -102;
  if ( file->current_file_ok == 0 )
    return -100;
  v2 = file->num_file + 1;
  if ( v2 == file->gi.number_entry )
    return -100;
  file->pos_in_central_dir += file->cur_file_info.size_file_extra
                            + file->cur_file_info.size_file_comment
                            + file->cur_file_info.size_filename
                            + 46;
  file->num_file = v2;
  result = unzlocal_GetCurrentFileInfoInternal(
             file,
             pfile_info: &file->cur_file_info,
             pfile_info_internal: &file->cur_file_info_internal,
             szFileName: nullptr,
             fileNameBufferSize: 0,
             extraField: nullptr,
             extraFieldBufferSize: 0,
             szComment: nullptr,
             commentBufferSize: 0);
  file->current_file_ok = result == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8790
// Name: int unzLocateFile(struct unz_s __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzLocateFile(unz_s *file, const char *szFileName, int iCaseSensitivity)
{
  int result; // eax
  const char *v5; // eax
  char v6; // cl
  unsigned int num_file; // ebx
  int v8; // eax
  char szFileNameA[260]; // [esp+4h] [ebp-208h] BYREF
  char szCurrentFileName[260]; // [esp+108h] [ebp-104h] BYREF
  unsigned int pos_in_central_dirSaved; // [esp+214h] [ebp+8h]

  if ( file == nullptr )
    return -102;
  v5 = szFileName;
  if ( strlen(szFileName) >= 0x100 )
    return -102;
  do
  {
    v6 = *v5;
    v5[szFileNameA - szFileName] = *v5;
    ++v5;
  }
  while ( v6 != 0 );
  if ( file->current_file_ok == 0 )
    return -100;
  num_file = file->num_file;
  pos_in_central_dirSaved = file->pos_in_central_dir;
  result = unzGoToFirstFile(file);
  if ( result != 0 )
  {
LABEL_14:
    file->num_file = num_file;
    file->pos_in_central_dir = pos_in_central_dirSaved;
  }
  else
  {
    while ( 1 )
    {
      unzlocal_GetCurrentFileInfoInternal(
        file,
        pfile_info: nullptr,
        pfile_info_internal: nullptr,
        szFileName: szCurrentFileName,
        fileNameBufferSize: 0x100u,
        extraField: nullptr,
        extraFieldBufferSize: 0,
        szComment: nullptr,
        commentBufferSize: 0);
      v8 = iCaseSensitivity == 1
         ? strcmp(szCurrentFileName, szFileNameA)
         : strcmpcasenosensitive_internal(fileName1: szCurrentFileName, fileName2: szFileNameA);
      if ( v8 == 0 )
        return 0;
      result = unzGoToNextFile(file);
      if ( result != 0 )
        goto LABEL_14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F88B0
// Name: int unzlocal_CheckCurrentFileCoherencyHeader(struct unz_s __near *,unsigned int __near *,unsigned long __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzlocal_CheckCurrentFileCoherencyHeader(
        unz_s *s,
        unsigned int *piSizeVar,
        unsigned int *poffset_local_extrafield,
        unsigned int *psize_local_extrafield)
{
  LUFILE *file; // ecx
  unsigned int v5; // eax
  int v6; // esi
  unsigned int compression_method; // eax
  int Long; // eax
  char v10; // bl
  int Short; // eax
  unsigned int v12; // ebx
  unsigned int v13; // eax
  unsigned int size_extra_field; // [esp+Ch] [ebp-14h] BYREF
  unsigned int size_filename; // [esp+10h] [ebp-10h] BYREF
  unsigned int uFlags; // [esp+14h] [ebp-Ch] BYREF
  unsigned int uMagic; // [esp+18h] [ebp-8h] BYREF
  unsigned int uData; // [esp+1Ch] [ebp-4h] BYREF

  *piSizeVar = 0;
  *poffset_local_extrafield = 0;
  *psize_local_extrafield = 0;
  file = s->file;
  v5 = s->cur_file_info_internal.offset_curfile + s->byte_before_the_zipfile;
  v6 = 0;
  uMagic = 0;
  uData = 0;
  uFlags = 0;
  size_filename = 0;
  size_extra_field = 0;
  if ( file->is_handle )
  {
    if ( !file->canseek )
      return -1;
    SetFilePointer(
      hFile: file->h,
      lDistanceToMove: v5 + file->initial_offset,
      lpDistanceToMoveHigh: nullptr,
      dwMoveMethod: 0);
  }
  else
  {
    file->pos = v5;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &uMagic) != 0 )
  {
    v6 = -1;
  }
  else if ( uMagic != 67324752 )
  {
    v6 = -103;
  }
  if ( unzlocal_getShort(fin: s->file, pX: &uData) != 0 )
    v6 = -1;
  if ( unzlocal_getShort(fin: s->file, pX: &uFlags) != 0 )
    v6 = -1;
  if ( unzlocal_getShort(fin: s->file, pX: &uData) != 0 )
  {
    v6 = -1;
  }
  else if ( v6 == 0 )
  {
    compression_method = s->cur_file_info.compression_method;
    if ( uData != compression_method || compression_method != 0 && compression_method != 8 )
      v6 = -103;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &uData) != 0 )
    v6 = -1;
  Long = unzlocal_getLong(fin: s->file, pX: &uData);
  v10 = uFlags;
  if ( Long != 0 )
  {
    v6 = -1;
  }
  else if ( v6 == 0 && uData != s->cur_file_info.crc && (uFlags & 8) == 0 )
  {
    v6 = -103;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &uData) != 0 )
  {
    v6 = -1;
  }
  else if ( v6 == 0 && uData != s->cur_file_info.compressed_size && (v10 & 8) == 0 )
  {
    v6 = -103;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &uData) != 0 )
  {
    v6 = -1;
  }
  else if ( v6 == 0 && uData != s->cur_file_info.uncompressed_size && (v10 & 8) == 0 )
  {
    v6 = -103;
  }
  Short = unzlocal_getShort(fin: s->file, pX: &size_filename);
  v12 = size_filename;
  if ( Short != 0 )
  {
    v6 = -1;
  }
  else if ( v6 == 0 && size_filename != s->cur_file_info.size_filename )
  {
    v6 = -103;
  }
  *piSizeVar += size_filename;
  if ( unzlocal_getShort(fin: s->file, pX: &size_extra_field) != 0 )
    v6 = -1;
  v13 = size_extra_field;
  *poffset_local_extrafield = s->cur_file_info_internal.offset_curfile + v12 + 30;
  *psize_local_extrafield = v13;
  *piSizeVar += v13;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101F8AA0
// Name: int unzCloseCurrentFile(struct unz_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzCloseCurrentFile(unz_s *file)
{
  file_in_zip_read_info_s *pfile_in_zip_read; // esi
  bool v3; // zf
  int err; // [esp+4h] [ebp-4h]

  err = 0;
  if ( file == nullptr )
    return -102;
  pfile_in_zip_read = file->pfile_in_zip_read;
  if ( pfile_in_zip_read == nullptr )
    return -102;
  if ( pfile_in_zip_read->rest_read_uncompressed == 0 && pfile_in_zip_read->crc32 != pfile_in_zip_read->crc32_wait )
    err = -105;
  if ( pfile_in_zip_read->read_buffer != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pfile_in_zip_read->read_buffer);
    pfile_in_zip_read->read_buffer = nullptr;
  }
  v3 = pfile_in_zip_read->stream_initialised == 0;
  pfile_in_zip_read->read_buffer = nullptr;
  if ( !v3 )
    inflateEnd(z: &pfile_in_zip_read->stream);
  pfile_in_zip_read->stream_initialised = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pfile_in_zip_read);
  file->pfile_in_zip_read = nullptr;
  return err;
}

//------------------------------------------------------------------------------
// Address: 0x101F8B40
// Name: struct _FILETIME timet2filetime(__int64)
// Source: json
//------------------------------------------------------------------------------
_FILETIME __cdecl timet2filetime(__int64 timer)
{
  unsigned __int16 *v1; // eax
  _SYSTEMTIME st; // [esp+0h] [ebp-18h] BYREF
  _FILETIME ft; // [esp+10h] [ebp-8h] BYREF

  v1 = (unsigned __int16 *)_gmtime64(timp: &timer);
  st.wYear = v1[10] + 1900;
  st.wMonth = v1[8] + 1;
  st.wDay = v1[6];
  st.wHour = v1[4];
  st.wMinute = v1[2];
  st.wSecond = *v1;
  st.wMilliseconds = 0;
  SystemTimeToFileTime(lpSystemTime: &st, lpFileTime: &ft);
  return ft;
}

//------------------------------------------------------------------------------
// Address: 0x101F8BB0
// Name: public: unsigned long TUnzip::Get(int,struct ZIPENTRY __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TUnzip::Get(TUnzip *this, int index, ZIPENTRY *ze)
{
  ZIPENTRY *v5; // eax
  LUFILE *file; // eax
  unsigned int v7; // esi
  char *v8; // eax
  TUnzip *v9; // edi
  char *v10; // ebx
  ZIPENTRY *v11; // esi
  char *v12; // eax
  char v13; // cl
  char external_fa; // al
  unsigned int v15; // edx
  char v16; // cl
  unsigned int uncompressed_size; // ecx
  unsigned int dwLowDateTime; // eax
  unsigned int dwHighDateTime; // ecx
  int v20; // edi
  bool v21; // cc
  char v22; // cl
  int v23; // eax
  bool v24; // dl
  int v25; // edi
  TUnzip *v26; // eax
  unsigned int dosDate_high; // [esp-Ch] [ebp-188h]
  WORD dosDate; // [esp-8h] [ebp-184h]
  __int64 v29; // [esp-8h] [ebp-184h]
  __int64 v30; // [esp-8h] [ebp-184h]
  char fn[260]; // [esp+Ch] [ebp-170h] BYREF
  unz_file_info_s ufi; // [esp+110h] [ebp-6Ch] BYREF
  unsigned int iSizeVar; // [esp+160h] [ebp-1Ch] BYREF
  _FILETIME ft; // [esp+164h] [ebp-18h] BYREF
  TUnzip *v35; // [esp+16Ch] [ebp-10h]
  unsigned int offset; // [esp+170h] [ebp-Ch] BYREF
  unsigned int extralen; // [esp+174h] [ebp-8h] BYREF
  bool whidden; // [esp+179h] [ebp-3h]
  bool uwriteable; // [esp+17Ah] [ebp-2h]
  bool hasctime; // [esp+17Bh] [ebp-1h]

  v35 = this;
  if ( index < -1 || index >= (signed int)this->uf->gi.number_entry )
    return 0x10000;
  if ( this->currentfile != -1 )
    unzCloseCurrentFile(file: this->uf);
  this->currentfile = -1;
  if ( index == this->czei )
  {
    if ( index != -1 )
    {
      *ze = this->cze;
      return 0;
    }
  }
  else if ( index != -1 )
  {
    if ( index < (signed int)this->uf->num_file )
      unzGoToFirstFile(file: this->uf);
    while ( (signed int)this->uf->num_file < index )
      unzGoToNextFile(file: this->uf);
    unzlocal_GetCurrentFileInfoInternal(
      file: this->uf,
      pfile_info: &ufi,
      pfile_info_internal: nullptr,
      szFileName: fn,
      fileNameBufferSize: 0x104u,
      extraField: nullptr,
      extraFieldBufferSize: 0,
      szComment: nullptr,
      commentBufferSize: 0);
    if ( unzlocal_CheckCurrentFileCoherencyHeader(
           s: this->uf,
           piSizeVar: &iSizeVar,
           poffset_local_extrafield: &offset,
           psize_local_extrafield: &extralen) != 0 )
      return 1792;
    file = this->uf->file;
    if ( file->is_handle )
    {
      if ( !file->canseek )
        return 2048;
      SetFilePointer(
        hFile: file->h,
        lDistanceToMove: offset + file->initial_offset,
        lpDistanceToMoveHigh: nullptr,
        dwMoveMethod: 0);
    }
    else
    {
      file->pos = offset;
    }
    v7 = extralen;
    v8 = (char *)MemAlloc_Alloc(nSize: extralen);
    v9 = v35;
    v10 = v8;
    if ( lufread(ptr: v8, size: 1u, n: v7, stream: v35->uf->file) != v7 )
    {
      free(pMem: v10);
      return 2048;
    }
    v11 = ze;
    ze->index = v9->uf->num_file;
    v12 = fn;
    do
    {
      v13 = *v12;
      v12[(char *)v11 - fn + 4] = *v12;
      ++v12;
    }
    while ( v13 != 0 );
    external_fa = ufi.external_fa;
    whidden = (ufi.external_fa & 2) != 0;
    hasctime = (ufi.external_fa & 4) != 0;
    HIBYTE(ze) = (ufi.external_fa & 0x20) != 0;
    uwriteable = (ufi.external_fa & 0x800000) != 0;
    v15 = ufi.external_fa >> 30;
    v16 = ufi.external_fa & 1;
    v11->attr = 128;
    if ( (v15 & 1) != 0 || (external_fa & 0x10) != 0 )
      v11->attr = 144;
    if ( HIBYTE(ze) != 0 )
      v11->attr |= 0x20u;
    if ( whidden )
      v11->attr |= 2u;
    if ( !uwriteable || v16 != 0 )
      v11->attr |= 1u;
    if ( hasctime )
      v11->attr |= 4u;
    uncompressed_size = ufi.uncompressed_size;
    v11->comp_size = ufi.compressed_size;
    dosDate = ufi.dosDate;
    dosDate_high = HIWORD(ufi.dosDate);
    v11->unc_size = uncompressed_size;
    DosDateTimeToFileTime(wFatDate: dosDate_high, wFatTime: dosDate, lpFileTime: &ft);
    dwLowDateTime = ft.dwLowDateTime;
    dwHighDateTime = ft.dwHighDateTime;
    v20 = 0;
    v21 = extralen <= 4;
    v11->atime = ft;
    v11->ctime.dwLowDateTime = dwLowDateTime;
    v11->ctime.dwHighDateTime = dwHighDateTime;
    v11->mtime.dwLowDateTime = dwLowDateTime;
    v11->mtime.dwHighDateTime = dwHighDateTime;
    if ( !v21 )
    {
      BYTE2(ze) = 0;
      while ( 1 )
      {
        v22 = v10[v20 + 1];
        LOBYTE(ze) = v10[v20];
        BYTE1(ze) = v22;
        if ( strcmp((const char *)&ze, "UT") == 0 )
          break;
        v20 += v10[v20 + 2] + 4;
        if ( v20 + 4 >= extralen )
          goto LABEL_48;
      }
      v23 = (unsigned __int8)v10[v20 + 4];
      v24 = (v10[v20 + 4] & 4) != 0;
      v25 = v20 + 5;
      HIBYTE(ze) = (v23 & 2) != 0;
      hasctime = v24;
      if ( (v23 & 1) != 0 )
      {
        v29 = *(_QWORD *)&v10[v25];
        v25 += 4;
        v11->mtime = timet2filetime(timer: v29);
      }
      if ( HIBYTE(ze) != 0 )
      {
        v30 = *(_QWORD *)&v10[v25];
        v25 += 4;
        v11->atime = timet2filetime(timer: v30);
      }
      if ( hasctime )
        v11->ctime = timet2filetime(timer: *(_QWORD *)&v10[v25]);
    }
LABEL_48:
    if ( v10 != nullptr )
      free(pMem: v10);
    v26 = v35;
    qmemcpy(&v35->cze, v11, sizeof(v35->cze));
    v26->czei = index;
    return 0;
  }
  v5 = ze;
  ze->index = this->uf->gi.number_entry;
  v5->name[0] = 0;
  v5->attr = 0;
  v5->atime.dwLowDateTime = 0;
  v5->atime.dwHighDateTime = 0;
  v5->ctime.dwLowDateTime = 0;
  v5->ctime.dwHighDateTime = 0;
  v5->mtime.dwLowDateTime = 0;
  v5->mtime.dwHighDateTime = 0;
  v5->comp_size = 0;
  v5->unc_size = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F8F80
// Name: public: unsigned long TUnzip::Find(char const __near *,bool,int __near *,struct ZIPENTRY __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TUnzip::Find(TUnzip *this, const char *name, bool ic, int *index, ZIPENTRY *ze)
{
  unsigned int result; // eax
  unz_s *uf; // ecx
  int num_file; // eax

  if ( unzLocateFile(file: this->uf, szFileName: name, iCaseSensitivity: ic + 1) != 0 )
  {
    if ( index != nullptr )
      *index = -1;
    if ( ze != nullptr )
    {
      memset(dst: (unsigned __int8 *)ze, value: 0, count: sizeof(ZIPENTRY));
      ze->index = -1;
    }
    return 1280;
  }
  else
  {
    if ( this->currentfile != -1 )
      unzCloseCurrentFile(file: this->uf);
    uf = this->uf;
    this->currentfile = -1;
    num_file = uf->num_file;
    if ( index != nullptr )
      *index = num_file;
    if ( ze == nullptr )
      return 0;
    result = TUnzip::Get(this, index: num_file, ze);
    if ( result == 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F9020
// Name: void EnsureDirectory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnsureDirectory(const char *rootdir, const char *dir)
{
  unsigned int v2; // eax
  char *v3; // edi
  char v4; // cl
  unsigned int v5; // esi
  char v6; // al
  char v7; // [esp-1h] [ebp-105h] BYREF
  char cd[260]; // [esp+0h] [ebp-104h] BYREF

  if ( dir != nullptr && *dir != 0 )
  {
    strcpy(cd, rootdir);
    v2 = strlen(dir) + 1;
    v3 = &v7;
    do
      v4 = *++v3;
    while ( v4 != 0 );
    qmemcpy(v3, dir, v2);
    v5 = 0;
    if ( &cd[strlen(cd) + 1] != &cd[1] )
    {
      do
      {
        v6 = cd[v5];
        if ( v6 == 47 || v6 == 92 )
        {
          cd[v5] = 0;
          CreateDirectoryA(lpPathName: cd, lpSecurityAttributes: nullptr);
          cd[v5] = 92;
        }
        ++v5;
      }
      while ( v5 < strlen(cd) );
    }
    CreateDirectoryA(lpPathName: cd, lpSecurityAttributes: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9100
// Name: unsigned long FindZipItemA(struct HZIP__ __near *,char const __near *,bool,int __near *,struct ZIPENTRY __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl FindZipItemA(TUnzip **hz, const char *name, bool ic, int *index, ZIPENTRY *ze)
{
  unsigned int result; // eax

  if ( hz != nullptr )
  {
    if ( *hz == (TUnzip *)1 )
    {
      result = TUnzip::Find(this: hz[1], name, ic, index, ze);
      lasterrorU = result;
    }
    else
    {
      lasterrorU = 0x80000;
      return 0x80000;
    }
  }
  else
  {
    lasterrorU = 0x10000;
    return 0x10000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F9150
// Name: int inflate_codes(struct inflate_blocks_state __near *,struct z_stream_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_codes(inflate_blocks_state *s, z_stream_s *z, int r)
{
  inflate_codes_state *codes; // ecx
  unsigned int bitk; // ebx
  unsigned int avail_in; // edx
  unsigned __int8 *write; // edx
  unsigned __int8 *read; // eax
  unsigned __int8 *v10; // eax
  __int32 mode; // ecx
  int v12; // ecx
  int v13; // eax
  unsigned __int8 *v14; // ecx
  unsigned __int8 *v15; // ecx
  unsigned int need; // eax
  int v17; // eax
  const inflate_huft_s *v18; // eax
  const inflate_huft_s *v19; // ecx
  unsigned int Exop; // eax
  const inflate_huft_s *tree; // eax
  int v22; // eax
  unsigned int v23; // ecx
  inflate_codes_state *v24; // eax
  unsigned int v25; // eax
  int v26; // eax
  const inflate_huft_s *v27; // eax
  int Bits; // ecx
  const inflate_huft_s *v29; // eax
  int v30; // eax
  unsigned int v31; // eax
  inflate_codes_state *v32; // ecx
  unsigned __int8 *v33; // eax
  unsigned __int8 *v34; // ecx
  int v35; // eax
  unsigned __int8 *v36; // eax
  unsigned __int8 *window; // ecx
  unsigned __int8 *v38; // eax
  unsigned __int8 *v39; // eax
  unsigned __int8 *v40; // ecx
  int v41; // eax
  unsigned __int8 *v42; // eax
  unsigned __int8 *v43; // ecx
  unsigned __int8 *v44; // eax
  int v46; // ecx
  int v47; // eax
  int v48; // [esp-4h] [ebp-28h]
  unsigned __int8 *f; // [esp+10h] [ebp-14h]
  const inflate_huft_s *t; // [esp+14h] [ebp-10h]
  const inflate_huft_s *ta; // [esp+14h] [ebp-10h]
  const inflate_huft_s *tb; // [esp+14h] [ebp-10h]
  const inflate_huft_s *tc; // [esp+14h] [ebp-10h]
  const inflate_huft_s *td; // [esp+14h] [ebp-10h]
  unsigned int m; // [esp+18h] [ebp-Ch]
  unsigned int ma; // [esp+18h] [ebp-Ch]
  unsigned int mb; // [esp+18h] [ebp-Ch]
  unsigned int n; // [esp+1Ch] [ebp-8h]
  inflate_codes_state *c; // [esp+20h] [ebp-4h]
  unsigned int b; // [esp+2Ch] [ebp+8h]
  unsigned __int8 *p; // [esp+30h] [ebp+Ch]

  codes = s->sub.decode.codes;
  bitk = s->bitk;
  avail_in = z->avail_in;
  p = z->next_in;
  n = avail_in;
  write = s->write;
  b = s->bitb;
  read = s->read;
  c = codes;
  if ( write >= read )
    v10 = (unsigned __int8 *)(s->end - write);
  else
    v10 = (unsigned __int8 *)(read - write - 1);
  mode = codes->mode;
  m = (unsigned int)v10;
  while ( 2 )
  {
    switch ( mode )
    {
      case 0:
        if ( (unsigned int)v10 >= 0x102 && n >= 0xA )
        {
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = n;
          v12 = p - z->next_in;
          z->next_in = p;
          z->total_in += v12;
          s->write = write;
          v13 = inflate_fast(bl: c->lbits, bd: c->dbits, tl: c->ltree, td: c->dtree, s, z);
          bitk = s->bitk;
          p = z->next_in;
          n = z->avail_in;
          write = s->write;
          b = s->bitb;
          v14 = s->read;
          r = v13;
          v15 = (unsigned __int8 *)(write >= v14 ? s->end - write : v14 - write - 1);
          m = (unsigned int)v15;
          if ( v13 != 0 )
          {
            c->mode = 2 * (v13 != 1) + 7;
            v10 = v15;
            goto LABEL_85;
          }
        }
        c->sub.code.need = c->lbits;
        c->sub.lit = (unsigned int)c->ltree;
        c->mode = LEN;
        goto $LN111_1;
      case 1:
$LN111_1:
        need = c->sub.code.need;
        t = (const inflate_huft_s *)need;
        if ( bitk < need )
        {
          do
          {
            if ( n == 0 )
              goto LABEL_89;
            --n;
            v17 = *p++ << bitk;
            bitk += 8;
            b |= v17;
            need = (unsigned int)t;
            r = 0;
          }
          while ( bitk < (unsigned int)t );
        }
        v18 = (const inflate_huft_s *)(c->sub.lit + 8 * (b & inflate_mask[need]));
        b >>= v18->word.what.Bits;
        v19 = v18;
        ta = v18;
        bitk -= v18->word.what.Bits;
        Exop = v18->word.what.Exop;
        if ( Exop == 0 )
        {
          c->sub.lit = v19->base;
          c->mode = LIT;
          v10 = (unsigned __int8 *)m;
          goto LABEL_85;
        }
        if ( (Exop & 0x10) != 0 )
        {
          c->sub.lit = Exop & 0xF;
          c->len = ta->base;
          v10 = (unsigned __int8 *)m;
          c->mode = LENEXT;
          goto LABEL_85;
        }
        if ( (Exop & 0x40) == 0 )
          goto LABEL_22;
        if ( (Exop & 0x20) == 0 )
        {
          c->mode = BADCODE;
          z->msg = "invalid literal/length code";
          goto LABEL_92;
        }
        c->mode = WASH;
        v10 = (unsigned __int8 *)m;
        goto LABEL_85;
      case 2:
        tree = c->sub.code.tree;
        for ( tb = tree; bitk < (unsigned int)tb; r = 0 )
        {
          if ( n == 0 )
            goto LABEL_89;
          --n;
          v22 = *p++ << bitk;
          bitk += 8;
          b |= v22;
          tree = tb;
        }
        v23 = b & inflate_mask[(_DWORD)tree];
        v24 = c;
        c->len += v23;
        b >>= (char)tb;
        bitk -= (unsigned int)tb;
        c->sub.code.need = c->dbits;
        c->sub.lit = (unsigned int)c->dtree;
        c->mode = DIST;
LABEL_30:
        v25 = v24->sub.code.need;
        tc = (const inflate_huft_s *)v25;
        if ( bitk >= v25 )
        {
LABEL_33:
          v27 = (const inflate_huft_s *)(c->sub.lit + 8 * (b & inflate_mask[v25]));
          b >>= v27->word.what.Bits;
          Bits = v27->word.what.Bits;
          ta = v27;
          Exop = v27->word.what.Exop;
          bitk -= Bits;
          if ( (Exop & 0x10) != 0 )
          {
            c->sub.lit = Exop & 0xF;
            c->sub.code.need = ta->base;
            v10 = (unsigned __int8 *)m;
            c->mode = DISTEXT;
            goto LABEL_85;
          }
          if ( (Exop & 0x40) != 0 )
          {
            c->mode = BADCODE;
            z->msg = "invalid distance code";
LABEL_92:
            s->bitb = b;
            s->bitk = bitk;
            z->avail_in = n;
            v48 = -3;
LABEL_88:
            z->total_in += p - z->next_in;
            z->next_in = p;
            s->write = write;
            return inflate_flush(s, z, r: v48);
          }
LABEL_22:
          c->sub.code.need = Exop;
          c->sub.lit = (unsigned int)&ta[ta->base];
          v10 = (unsigned __int8 *)m;
LABEL_85:
          mode = c->mode;
          if ( c->mode > (unsigned int)BADCODE )
          {
LABEL_86:
            v48 = -2;
LABEL_87:
            s->bitb = b;
            s->bitk = bitk;
            z->avail_in = n;
            goto LABEL_88;
          }
          continue;
        }
        while ( n != 0 )
        {
          --n;
          v26 = *p++ << bitk;
          bitk += 8;
          b |= v26;
          v25 = (unsigned int)tc;
          r = 0;
          if ( bitk >= (unsigned int)tc )
            goto LABEL_33;
        }
LABEL_89:
        s->bitb = b;
        s->bitk = bitk;
        z->avail_in = 0;
LABEL_90:
        v46 = p - z->next_in;
        z->next_in = p;
        z->total_in += v46;
        s->write = write;
        return inflate_flush(s, z, r);
      case 3:
        v24 = c;
        goto LABEL_30;
      case 4:
        v29 = c->sub.code.tree;
        for ( td = v29; bitk < (unsigned int)td; r = 0 )
        {
          if ( n == 0 )
            goto LABEL_89;
          --n;
          v30 = *p++ << bitk;
          bitk += 8;
          b |= v30;
          v29 = td;
        }
        c->sub.code.need += b & inflate_mask[(_DWORD)v29];
        b >>= (char)td;
        bitk -= (unsigned int)td;
        c->mode = COPY;
$LN101_0:
        v31 = c->sub.code.need;
        if ( write - s->window >= v31 )
          f = &write[-v31];
        else
          f = &write[s->end - s->window - c->sub.code.need];
        v32 = c;
        v10 = (unsigned __int8 *)m;
        if ( c->len != 0 )
        {
          while ( 1 )
          {
            if ( v10 == nullptr )
            {
              if ( write != s->end
                || (v33 = s->read, v34 = s->window, v33 == v34)
                || ((write = s->window, v34 >= v33)
                  ? (v10 = (unsigned __int8 *)(s->end - v34))
                  : (v10 = (unsigned __int8 *)(v33 - v34 - 1)),
                    v10 == nullptr) )
              {
                s->write = write;
                v35 = inflate_flush(s, z, r);
                write = s->write;
                r = v35;
                v36 = s->read;
                if ( write >= v36 )
                  v10 = (unsigned __int8 *)(s->end - write);
                else
                  v10 = (unsigned __int8 *)(v36 - write - 1);
                ma = (unsigned int)v10;
                if ( write == s->end )
                {
                  window = s->window;
                  v38 = s->read;
                  if ( v38 == window )
                  {
                    v10 = (unsigned __int8 *)ma;
                  }
                  else
                  {
                    write = s->window;
                    if ( window >= v38 )
                      v10 = (unsigned __int8 *)(s->end - window);
                    else
                      v10 = (unsigned __int8 *)(v38 - window - 1);
                  }
                }
                if ( v10 == nullptr )
                  break;
              }
            }
            *write = *f;
            --v10;
            ++write;
            r = 0;
            ++f;
            m = (unsigned int)v10;
            if ( f == s->end )
              f = s->window;
            v32 = c;
            if ( --c->len == 0 )
              goto LABEL_84;
          }
LABEL_93:
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = n;
          goto LABEL_90;
        }
LABEL_84:
        v32->mode = START;
        goto LABEL_85;
      case 5:
        goto $LN101_0;
      case 6:
        if ( v10 == nullptr )
        {
          if ( write != s->end
            || (v39 = s->read, v40 = s->window, v39 == v40)
            || ((write = s->window, v40 >= v39)
              ? (v10 = (unsigned __int8 *)(s->end - v40))
              : (v10 = (unsigned __int8 *)(v39 - v40 - 1)),
                v10 == nullptr) )
          {
            s->write = write;
            v41 = inflate_flush(s, z, r);
            write = s->write;
            r = v41;
            v42 = s->read;
            if ( write >= v42 )
              v10 = (unsigned __int8 *)(s->end - write);
            else
              v10 = (unsigned __int8 *)(v42 - write - 1);
            mb = (unsigned int)v10;
            if ( write == s->end )
            {
              v43 = s->window;
              v44 = s->read;
              if ( v44 == v43 )
              {
                v10 = (unsigned __int8 *)mb;
              }
              else
              {
                write = s->window;
                if ( v43 >= v44 )
                  v10 = (unsigned __int8 *)(s->end - v43);
                else
                  v10 = (unsigned __int8 *)(v44 - v43 - 1);
              }
            }
            if ( v10 == nullptr )
              goto LABEL_93;
          }
        }
        *write = c->sub.lit;
        v32 = c;
        ++write;
        --v10;
        r = 0;
        m = (unsigned int)v10;
        goto LABEL_84;
      case 7:
        if ( bitk > 7 )
        {
          ++n;
          bitk -= 8;
          --p;
        }
        s->write = write;
        v47 = inflate_flush(s, z, r);
        write = s->write;
        if ( s->read != write )
        {
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = n;
          z->total_in += p - z->next_in;
          z->next_in = p;
          s->write = write;
          return inflate_flush(s, z, r: v47);
        }
        c->mode = END;
$LN3_47:
        s->bitb = b;
        s->bitk = bitk;
        z->avail_in = n;
        v48 = 1;
        goto LABEL_88;
      case 8:
        goto $LN3_47;
      case 9:
        v48 = -3;
        goto LABEL_87;
      default:
        goto LABEL_86;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F97C0
// Name: int inflate_blocks(struct inflate_blocks_state __near *,struct z_stream_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_blocks(inflate_blocks_state *s, z_stream_s *z, int r)
{
  unsigned __int8 *next_in; // eax
  unsigned __int8 *write; // edx
  unsigned __int8 *read; // ecx
  unsigned int bitb; // eax
  unsigned int bitk; // edi
  unsigned __int8 *v10; // edx
  inflate_block_mode mode; // ecx
  unsigned int v12; // edx
  int v13; // ecx
  int v15; // edx
  unsigned int v16; // edi
  int v17; // ecx
  inflate_codes_state *v18; // eax
  int v19; // edx
  unsigned int v20; // ecx
  unsigned __int8 *end; // edx
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // ecx
  unsigned int v24; // eax
  int v25; // eax
  unsigned __int8 *v26; // ecx
  unsigned __int8 *v27; // eax
  unsigned __int8 *v28; // edx
  unsigned __int8 *window; // eax
  unsigned int left; // eax
  bool v31; // zf
  int v32; // edx
  unsigned int v33; // eax
  unsigned int v34; // ecx
  int v35; // eax
  unsigned int *v36; // eax
  int v37; // edx
  unsigned int bb; // ecx
  int v39; // edx
  inflate_huft_s *v40; // edx
  unsigned int Bits; // ecx
  unsigned int base; // edx
  int v43; // edx
  unsigned int v44; // eax
  unsigned int index; // ecx
  unsigned int v46; // eax
  unsigned int v47; // eax
  unsigned int v48; // eax
  unsigned int *v49; // edx
  void (__cdecl *zfree)(void *, void *); // ecx
  _BYTE *v51; // eax
  char v52; // dl
  inflate_huft_s *v53; // ecx
  inflate_huft_s *v54; // edx
  unsigned int v55; // ecx
  unsigned __int8 *v56; // eax
  int v57; // eax
  unsigned int v58; // ecx
  unsigned __int8 *v59; // edx
  unsigned __int8 *v60; // eax
  unsigned __int8 *v61; // ecx
  unsigned __int8 *v62; // eax
  unsigned __int8 *v63; // eax
  unsigned int v64; // eax
  unsigned __int8 *v65; // eax
  unsigned int v66; // edx
  unsigned __int8 *v67; // eax
  unsigned int v68; // eax
  unsigned int v69; // ecx
  unsigned __int8 *v70; // eax
  unsigned int v71; // eax
  unsigned __int8 *v72; // eax
  unsigned int v73; // edx
  unsigned int v74; // ecx
  unsigned __int8 *v75; // eax
  unsigned int v76; // ecx
  int v77; // edx
  unsigned int v78; // eax
  unsigned int *v79; // [esp-1Ch] [ebp-4Ch]
  unsigned int *blens; // [esp-14h] [ebp-44h]
  inflate_huft_s *hufts; // [esp-8h] [ebp-38h]
  inflate_huft_s *v82; // [esp-8h] [ebp-38h]
  unsigned int v83; // [esp-4h] [ebp-34h]
  unsigned int v84; // [esp-4h] [ebp-34h]
  inflate_huft_s *td; // [esp+Ch] [ebp-24h] BYREF
  inflate_huft_s *tl; // [esp+10h] [ebp-20h] BYREF
  unsigned int c; // [esp+14h] [ebp-1Ch]
  unsigned int v88; // [esp+18h] [ebp-18h]
  unsigned int i; // [esp+1Ch] [ebp-14h] BYREF
  unsigned int bd; // [esp+20h] [ebp-10h] BYREF
  unsigned int t; // [esp+24h] [ebp-Ch]
  unsigned int n; // [esp+28h] [ebp-8h]
  unsigned __int8 *p; // [esp+2Ch] [ebp-4h]
  unsigned __int8 *q; // [esp+38h] [ebp+8h]
  unsigned int b; // [esp+3Ch] [ebp+Ch]
  int ra; // [esp+40h] [ebp+10h]

  next_in = z->next_in;
  write = s->write;
  n = z->avail_in;
  read = s->read;
  p = next_in;
  bitb = s->bitb;
  bitk = s->bitk;
  b = bitb;
  q = write;
  if ( write >= read )
  {
    v10 = (unsigned __int8 *)(s->end - write);
    bd = s->end - q;
  }
  else
  {
    v10 = (unsigned __int8 *)(read - write - 1);
    bd = (unsigned int)v10;
  }
  mode = s->mode;
  while ( 2 )
  {
    switch ( mode )
    {
      case IBM_TYPE:
        for ( ; bitk < 3; b = bitb )
        {
          if ( n == 0 )
            goto LABEL_100;
          --n;
          v15 = *p++ << bitk;
          bitk += 8;
          bitb |= v15;
          r = 0;
        }
        s->last = bitb & 1;
        switch ( (unsigned __int8)(bitb & 7) >> 1 )
        {
          case 0:
            v16 = bitk - 3;
            v17 = v16 & 7;
            bitb = bitb >> 3 >> v17;
            bitk = v16 - v17;
            s->mode = IBM_LENS;
            b = bitb;
            goto LABEL_98;
          case 1:
            v18 = inflate_codes_new(bl: 9u, bd: 5u, tl: fixed_tl, td: fixed_td, z);
            s->sub.left = (unsigned int)v18;
            if ( v18 == nullptr )
            {
              v83 = -4;
              goto LABEL_6;
            }
            b >>= 3;
            bitk -= 3;
            s->mode = IBM_CODES;
            break;
          case 2:
            bitb >>= 3;
            b = bitb;
            bitk -= 3;
            s->mode = IBM_TABLE;
            goto LABEL_98;
          case 3:
            s->mode = IBM_BAD;
            z->msg = "invalid block type";
            s->bitb = b >> 3;
            v64 = n;
            s->bitk = bitk - 3;
            z->avail_in = v64;
            v83 = -3;
            goto LABEL_7;
          default:
            goto LABEL_98;
        }
        goto LABEL_97;
      case IBM_LENS:
        if ( bitk >= 0x20 )
          goto LABEL_22;
        do
        {
          if ( n == 0 )
          {
LABEL_104:
            s->bitb = b;
LABEL_101:
            v63 = p;
            s->bitk = bitk;
            v13 = v63 - z->next_in;
            z->next_in = v63;
            z->avail_in = 0;
            v83 = r;
            goto LABEL_8;
          }
          --n;
          v19 = *p++ << bitk;
          bitk += 8;
          bitb |= v19;
          r = 0;
          b = bitb;
        }
        while ( bitk < 0x20 );
LABEL_22:
        v20 = (unsigned __int16)bitb;
        if ( ~bitb >> 16 != (unsigned __int16)bitb )
        {
          s->mode = IBM_BAD;
          z->msg = "invalid stored block lengths";
          v83 = -3;
LABEL_6:
          v12 = n;
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = v12;
LABEL_7:
          v13 = p - z->next_in;
          z->next_in = p;
LABEL_8:
          z->total_in += v13;
          s->write = q;
          return inflate_flush(s, z, r: v83);
        }
        bitb = 0;
        bitk = 0;
        s->sub.left = v20;
        b = 0;
        if ( v20 != 0 )
          s->mode = IBM_STORED;
        else
          s->mode = s->last != 0 ? IBM_DRY : IBM_TYPE;
LABEL_98:
        mode = s->mode;
        if ( s->mode > (unsigned int)IBM_BAD )
        {
LABEL_5:
          v83 = -2;
          goto LABEL_6;
        }
        v10 = (unsigned __int8 *)bd;
        continue;
      case IBM_STORED:
        if ( n == 0 )
          goto LABEL_104;
        if ( v10 == nullptr )
        {
          if ( (end = s->end, q != end)
            || (v22 = s->read, (v23 = s->window) == v22)
            || ((q = s->window, v23 >= v22) ? (v24 = end - v23, bd = end - v23) : (v24 = v22 - v23 - 1, bd = v24),
                v24 == 0) )
          {
            s->write = q;
            v25 = inflate_flush(s, z, r);
            v26 = s->read;
            ra = v25;
            v27 = s->write;
            q = v27;
            if ( v27 >= v26 )
            {
              bd = s->end - v27;
              v28 = (unsigned __int8 *)bd;
            }
            else
            {
              v28 = (unsigned __int8 *)(v26 - v27 - 1);
              bd = (unsigned int)v28;
            }
            if ( v27 == s->end )
            {
              window = s->window;
              if ( window != v26 )
              {
                q = s->window;
                if ( window >= v26 )
                  v28 = (unsigned __int8 *)(s->end - window);
                else
                  v28 = (unsigned __int8 *)(v26 - window - 1);
                bd = (unsigned int)v28;
              }
            }
            if ( v28 == nullptr )
            {
              v65 = p;
              v66 = n;
              s->bitb = b;
              s->bitk = bitk;
              v13 = v65 - z->next_in;
              z->next_in = v65;
              z->avail_in = v66;
              v83 = ra;
              goto LABEL_8;
            }
          }
        }
        left = s->sub.left;
        r = 0;
        t = left;
        if ( left > n )
        {
          left = n;
          t = n;
        }
        if ( left > bd )
          t = bd;
        memcpy(dst: q, src: p, count: t);
        p += t;
        n -= t;
        q += t;
        bd -= t;
        v31 = s->sub.left == t;
        s->sub.left -= t;
        if ( v31 )
          s->mode = s->last != 0 ? IBM_DRY : IBM_TYPE;
        goto LABEL_97;
      case IBM_TABLE:
        for ( ; bitk < 0xE; b = bitb )
        {
          if ( n == 0 )
            goto LABEL_107;
          --n;
          v32 = *p++ << bitk;
          bitk += 8;
          bitb |= v32;
          r = 0;
        }
        v33 = bitb & 0x3FFF;
        v34 = v33 & 0x1F;
        s->sub.left = v33;
        if ( v34 > 0x1D || (unsigned int)(v35 = (v33 >> 5) & 0x1F) > 0x1D )
        {
          s->mode = IBM_BAD;
          z->msg = "too many length or distance symbols";
$LN2_38:
          v69 = n;
          s->bitb = b;
          v70 = p;
          s->bitk = bitk;
          z->total_in += v70 - z->next_in;
          z->next_in = v70;
          z->avail_in = v69;
          s->write = q;
          return inflate_flush(s, z, r: -3);
        }
        v36 = (unsigned int *)z->zalloc(a1: z->opaque, a2: v35 + v34 + 258, a3: 4);
        s->sub.trees.blens = v36;
        if ( v36 == nullptr )
          goto LABEL_108;
        b >>= 14;
        bitb = b;
        bitk -= 14;
        s->sub.trees.index = 0;
        s->mode = IBM_BTREE;
$LN112_1:
        if ( s->sub.trees.index < (s->sub.left >> 10) + 4 )
        {
          while ( bitk >= 3 )
          {
LABEL_61:
            s->sub.trees.blens[border[s->sub.trees.index++]] = bitb & 7;
            bitb = b >> 3;
            bitk -= 3;
            b >>= 3;
            if ( s->sub.trees.index >= (s->sub.left >> 10) + 4 )
              goto LABEL_62;
          }
          while ( n != 0 )
          {
            --n;
            v37 = *p++ << bitk;
            bitk += 8;
            bitb |= v37;
            r = 0;
            b = bitb;
            if ( bitk >= 3 )
              goto LABEL_61;
          }
          goto LABEL_107;
        }
LABEL_62:
        while ( s->sub.trees.index < 0x13 )
          s->sub.trees.blens[border[s->sub.trees.index++]] = 0;
        hufts = s->hufts;
        blens = s->sub.trees.blens;
        s->sub.trees.bb = 7;
        t = inflate_trees_bits(c: blens, bb: &s->sub.trees.bb, tb: &s->sub.trees.tb, hp: hufts, z);
        if ( t != 0 )
        {
          z->zfree(a1: z->opaque, a2: s->sub.trees.blens);
          if ( t == -3 )
            s->mode = IBM_BAD;
          v71 = n;
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = v71;
          v13 = p - z->next_in;
          z->next_in = p;
          v83 = t;
          goto LABEL_8;
        }
        s->sub.trees.index = 0;
        bitb = b;
        s->mode = IBM_DTREE;
$LN115_1:
        if ( s->sub.trees.index < ((s->sub.left >> 5) & 0x1F) + (s->sub.left & 0x1F) + 258 )
        {
          while ( 1 )
          {
            bb = s->sub.trees.bb;
            if ( bitk < bb )
              break;
LABEL_72:
            v40 = &s->sub.trees.tb[bitb & inflate_mask[bb]];
            Bits = v40->word.what.Bits;
            base = v40->base;
            t = Bits;
            c = base;
            if ( base >= 0x10 )
            {
              if ( base == 18 )
                i = 7;
              else
                i = base - 14;
              bd = 8 * (base == 18) + 3;
              v88 = i + t;
              if ( bitk < i + t )
              {
                while ( n != 0 )
                {
                  --n;
                  v43 = *p++ << bitk;
                  bitk += 8;
                  bitb |= v43;
                  r = 0;
                  b = bitb;
                  if ( bitk >= v88 )
                    goto LABEL_80;
                }
LABEL_100:
                s->bitb = b;
                goto LABEL_101;
              }
LABEL_80:
              v44 = bitb >> t;
              bd += v44 & inflate_mask[i];
              bitk -= t + i;
              index = s->sub.trees.index;
              b = v44 >> i;
              if ( index + bd > ((s->sub.left >> 5) & 0x1F) + (s->sub.left & 0x1F) + 258 )
                goto LABEL_114;
              if ( c == 16 )
              {
                if ( index == 0 )
                {
LABEL_114:
                  z->zfree(a1: z->opaque, a2: s->sub.trees.blens);
                  v72 = p;
                  v73 = n;
                  s->mode = IBM_BAD;
                  z->msg = "invalid bit length repeat";
                  s->bitb = b;
                  s->bitk = bitk;
                  z->total_in += v72 - z->next_in;
                  z->avail_in = v73;
                  z->next_in = v72;
                  s->write = q;
                  return inflate_flush(s, z, r: -3);
                }
                v46 = s->sub.trees.blens[index - 1];
              }
              else
              {
                v46 = 0;
              }
              do
              {
                s->sub.trees.blens[index++] = v46;
                --bd;
              }
              while ( bd != 0 );
              s->sub.trees.index = index;
            }
            else
            {
              bitk -= Bits;
              b = bitb >> Bits;
              s->sub.trees.blens[s->sub.trees.index++] = base;
            }
            if ( s->sub.trees.index >= ((s->sub.left >> 5) & 0x1F) + (s->sub.left & 0x1F) + 258 )
              goto LABEL_88;
            bitb = b;
          }
          while ( n != 0 )
          {
            --n;
            v39 = *p << bitk;
            bb = s->sub.trees.bb;
            bitk += 8;
            r = 0;
            bitb |= v39;
            ++p;
            b = bitb;
            if ( bitk >= bb )
              goto LABEL_72;
          }
LABEL_107:
          v67 = p;
          s->bitb = b;
          s->bitk = bitk;
          z->total_in += v67 - z->next_in;
          z->next_in = v67;
          z->avail_in = 0;
          s->write = q;
          return inflate_flush(s, z, r);
        }
LABEL_88:
        v47 = s->sub.left;
        v82 = s->hufts;
        v79 = s->sub.trees.blens;
        s->sub.trees.tb = nullptr;
        i = 9;
        bd = 6;
        v48 = inflate_trees_dynamic(
                nl: (v47 & 0x1F) + 257,
                nd: ((v47 >> 5) & 0x1F) + 1,
                c: v79,
                bl: &i,
                &bd,
                &tl,
                &td,
                hp: v82,
                z);
        v49 = s->sub.trees.blens;
        zfree = z->zfree;
        t = v48;
        zfree(a1: z->opaque, a2: v49);
        if ( t != 0 )
        {
          if ( t == -3 )
            s->mode = IBM_BAD;
          v74 = n;
          s->bitb = b;
          v75 = p;
          s->bitk = bitk;
          z->avail_in = v74;
          v84 = t;
          z->total_in += v75 - z->next_in;
          z->next_in = v75;
          s->write = q;
          return inflate_flush(s, z, r: v84);
        }
        v51 = z->zalloc(a1: z->opaque, a2: 1, a3: 28);
        if ( v51 == nullptr )
        {
LABEL_108:
          v68 = n;
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = v68;
          v83 = -4;
          goto LABEL_7;
        }
        v52 = bd;
        v51[16] = i;
        v53 = tl;
        v51[17] = v52;
        v54 = td;
        *(_DWORD *)v51 = 0;
        *((_DWORD *)v51 + 5) = v53;
        *((_DWORD *)v51 + 6) = v54;
        s->sub.left = (unsigned int)v51;
        s->mode = IBM_CODES;
$LN8_33:
        v55 = n;
        s->bitb = b;
        v56 = p;
        s->bitk = bitk;
        z->avail_in = v55;
        z->total_in += v56 - z->next_in;
        z->next_in = v56;
        s->write = q;
        v57 = inflate_codes(s, z, r);
        if ( v57 == 1 )
        {
          r = 0;
          z->zfree(a1: z->opaque, a2: (void *)s->sub.left);
          v58 = s->bitb;
          v59 = z->next_in;
          bitk = s->bitk;
          n = z->avail_in;
          v60 = s->read;
          b = v58;
          v61 = s->write;
          p = v59;
          q = v61;
          if ( v61 >= v60 )
            v62 = (unsigned __int8 *)(s->end - v61);
          else
            v62 = (unsigned __int8 *)(v60 - v61 - 1);
          v31 = s->last == 0;
          bd = (unsigned int)v62;
          if ( v31 )
          {
            s->mode = IBM_TYPE;
LABEL_97:
            bitb = b;
            goto LABEL_98;
          }
          s->mode = IBM_DRY;
$LN5_44:
          s->write = q;
          v57 = inflate_flush(s, z, r);
          q = s->write;
          if ( s->read == q )
          {
            s->mode = IBM_DONE;
$LN3_48:
            v78 = n;
            s->bitb = b;
            s->bitk = bitk;
            z->avail_in = v78;
            v83 = 1;
            goto LABEL_7;
          }
          v76 = n;
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = v76;
          v77 = p - z->next_in;
          z->next_in = p;
          z->total_in += v77;
          s->write = q;
        }
        return inflate_flush(s, z, r: v57);
      case IBM_BTREE:
        goto $LN112_1;
      case IBM_DTREE:
        goto $LN115_1;
      case IBM_CODES:
        goto $LN8_33;
      case IBM_DRY:
        goto $LN5_44;
      case IBM_DONE:
        goto $LN3_48;
      case IBM_BAD:
        goto $LN2_38;
      default:
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA180
// Name: int inflate(struct z_stream_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate(z_stream_s *z, int f)
{
  internal_state *state; // eax
  inflate_mode mode; // eax
  int v4; // edi
  unsigned int avail_in; // eax
  internal_state *v6; // ecx
  unsigned int v7; // eax
  internal_state *v8; // eax
  internal_state *v9; // eax
  unsigned int v10; // eax
  int v11; // ecx
  int v12; // eax
  internal_state *v13; // eax
  unsigned int v14; // eax
  internal_state *v15; // edx
  internal_state *v16; // eax
  unsigned int v17; // eax
  unsigned __int8 *v18; // ecx
  internal_state *v19; // eax
  unsigned int v20; // eax
  unsigned __int8 *v21; // ecx
  internal_state *v22; // eax
  unsigned int v23; // eax
  unsigned __int8 *v24; // ecx
  internal_state *v25; // eax
  unsigned int v27; // eax
  unsigned __int8 *next_in; // edx
  internal_state *v29; // ecx
  internal_state *v30; // edx
  unsigned int v31; // eax
  unsigned __int8 *v32; // ecx
  internal_state *v33; // eax
  unsigned int v34; // eax
  unsigned __int8 *v35; // ecx
  internal_state *v36; // eax
  unsigned int v37; // eax
  unsigned __int8 *v38; // ecx
  internal_state *v39; // eax
  internal_state *v40; // eax

  if ( z == nullptr )
    return -2;
  state = z->state;
  if ( state == nullptr || z->next_in == nullptr )
    return -2;
  mode = state->mode;
  v4 = -5;
  while ( 2 )
  {
    switch ( mode )
    {
      case IM_METHOD:
        avail_in = z->avail_in;
        if ( avail_in == 0 )
          return v4;
        ++z->total_in;
        v6 = z->state;
        z->avail_in = avail_in - 1;
        v7 = *z->next_in;
        v6->sub.method = v7;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        if ( (v7 & 0xF) != 8 )
        {
          z->state->mode = IM_BAD;
          v8 = z->state;
          z->msg = "unknown compression method";
          v8->sub.method = 5;
          goto LABEL_35;
        }
        v9 = z->state;
        if ( (v9->sub.method >> 4) + 8 > v9->wbits )
        {
          v9->mode = IM_BAD;
          z->msg = "invalid window size";
          goto LABEL_34;
        }
        v9->mode = IM_FLAG;
        goto $LN51_0;
      case IM_FLAG:
$LN51_0:
        v10 = z->avail_in;
        if ( v10 == 0 )
          return v4;
        ++z->total_in;
        z->avail_in = v10 - 1;
        v11 = *z->next_in++;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        if ( (v11 + (z->state->sub.method << 8)) % 0x1F != 0 )
        {
          z->state->mode = IM_BAD;
          z->msg = "incorrect header check";
LABEL_34:
          z->state->sub.method = 5;
LABEL_35:
          mode = z->state->mode;
          if ( (unsigned int)mode > IM_BAD )
            return -2;
          continue;
        }
        if ( (v11 & 0x20) == 0 )
        {
          z->state->mode = IM_BLOCKS;
          goto LABEL_35;
        }
        z->state->mode = IM_DICT4;
$LN26_5:
        v27 = z->avail_in;
        if ( v27 == 0 )
          return v4;
        next_in = z->next_in;
        ++z->total_in;
        v29 = z->state;
        z->avail_in = v27 - 1;
        v29->sub.check.need = *next_in << 24;
        v30 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v30->mode = IM_DICT3;
$LN55_1:
        v31 = z->avail_in;
        if ( v31 == 0 )
          return v4;
        v32 = z->next_in;
        ++z->total_in;
        z->avail_in = v31 - 1;
        z->state->sub.check.need += *v32 << 16;
        v33 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v33->mode = IM_DICT2;
$LN56_1:
        v34 = z->avail_in;
        if ( v34 == 0 )
          return v4;
        v35 = z->next_in;
        ++z->total_in;
        z->avail_in = v34 - 1;
        z->state->sub.check.need += *v35 << 8;
        v36 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v36->mode = IM_DICT1;
$LN57_1:
        v37 = z->avail_in;
        if ( v37 == 0 )
          return v4;
        v38 = z->next_in;
        ++z->total_in;
        z->avail_in = v37 - 1;
        z->state->sub.check.need += *v38;
        v39 = z->state;
        ++z->next_in;
        z->adler = v39->sub.check.need;
        v39->mode = IM_DICT0;
        return 2;
      case IM_DICT4:
        goto $LN26_5;
      case IM_DICT3:
        goto $LN55_1;
      case IM_DICT2:
        goto $LN56_1;
      case IM_DICT1:
        goto $LN57_1;
      case IM_DICT0:
        z->state->mode = IM_BAD;
        v40 = z->state;
        z->msg = "need dictionary";
        v40->sub.method = 0;
        return -2;
      case IM_BLOCKS:
        v12 = inflate_blocks(s: z->state->blocks, z, r: v4);
        v4 = v12;
        if ( v12 == -3 )
        {
          z->state->mode = IM_BAD;
          z->state->sub.method = 0;
          goto LABEL_35;
        }
        if ( v12 == 0 )
          v4 = f != 4 ? 0 : 0xFFFFFFFB;
        if ( v4 != 1 )
          return v4;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        inflate_blocks_reset(s: z->state->blocks, z, c: &z->state->sub.method);
        v13 = z->state;
        if ( v13->nowrap != 0 )
        {
          v13->mode = IM_DONE;
          goto LABEL_35;
        }
        v13->mode = IM_CHECK4;
$LN12_27:
        v14 = z->avail_in;
        if ( v14 == 0 )
          return v4;
        ++z->total_in;
        v15 = z->state;
        z->avail_in = v14 - 1;
        v15->sub.check.need = *z->next_in << 24;
        v16 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v16->mode = IM_CHECK3;
$LN52_0:
        v17 = z->avail_in;
        if ( v17 == 0 )
          return v4;
        v18 = z->next_in;
        ++z->total_in;
        z->avail_in = v17 - 1;
        z->state->sub.check.need += *v18 << 16;
        v19 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v19->mode = IM_CHECK2;
$LN53_2:
        v20 = z->avail_in;
        if ( v20 == 0 )
          return v4;
        v21 = z->next_in;
        ++z->total_in;
        z->avail_in = v20 - 1;
        z->state->sub.check.need += *v21 << 8;
        v22 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v22->mode = IM_CHECK1;
$LN54_2:
        v23 = z->avail_in;
        if ( v23 == 0 )
          return v4;
        v24 = z->next_in;
        ++z->total_in;
        z->avail_in = v23 - 1;
        z->state->sub.check.need += *v24;
        v25 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        if ( v25->sub.method == v25->sub.check.need )
        {
          z->state->mode = IM_DONE;
          return 1;
        }
        v25->mode = IM_BAD;
        z->msg = "incorrect data check";
        goto LABEL_34;
      case IM_CHECK4:
        goto $LN12_27;
      case IM_CHECK3:
        goto $LN52_0;
      case IM_CHECK2:
        goto $LN53_2;
      case IM_CHECK1:
        goto $LN54_2;
      case IM_DONE:
        return 1;
      case IM_BAD:
        return -3;
      default:
        return -2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA540
// Name: struct unz_s __near * unzOpenInternal(struct LUFILE __near *)
// Source: json
//------------------------------------------------------------------------------
unz_s *__cdecl unzOpenInternal(int fin)
{
  unsigned __int8 *v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax
  unsigned int offset_central_dir; // ecx
  unsigned int v7; // eax
  IMemAlloc_vtbl *v8; // edx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  unz_s *v10; // ebx
  unz_s us; // [esp+4h] [ebp-8Ch] BYREF
  unsigned int number_entry_CD; // [esp+84h] [ebp-Ch] BYREF
  unsigned int number_disk_with_CD; // [esp+88h] [ebp-8h] BYREF
  unsigned int number_disk; // [esp+8Ch] [ebp-4h] BYREF
  int err; // [esp+98h] [ebp+8h]

  if ( fin == 0 )
    return nullptr;
  err = 0;
  v3 = unzlocal_SearchCentralDir((LUFILE *)fin);
  v4 = (unsigned int)v3;
  if ( v3 == nullptr )
    err = -1;
  if ( *(_BYTE *)fin != 0 )
  {
    if ( *(_BYTE *)(fin + 1) != 0 )
      SetFilePointer(
        hFile: *(HANDLE *)(fin + 4),
        lDistanceToMove: (LONG)&v3[*(_DWORD *)(fin + 12)],
        lpDistanceToMoveHigh: nullptr,
        dwMoveMethod: 0);
    else
      err = -1;
  }
  else
  {
    *(_DWORD *)(fin + 24) = v3;
  }
  if ( unzlocal_getLong((LUFILE *)fin, pX: &number_disk) != 0 )
    err = -1;
  if ( unzlocal_getShort((LUFILE *)fin, pX: &number_disk) != 0 )
    err = -1;
  if ( unzlocal_getShort((LUFILE *)fin, pX: &number_disk_with_CD) != 0 )
    err = -1;
  if ( unzlocal_getShort((LUFILE *)fin, pX: &us.gi.number_entry) != 0 )
    err = -1;
  if ( unzlocal_getShort((LUFILE *)fin, pX: &number_entry_CD) != 0 )
    err = -1;
  if ( number_entry_CD != us.gi.number_entry || number_disk_with_CD != 0 || number_disk != 0 )
    err = -103;
  if ( unzlocal_getLong((LUFILE *)fin, pX: &us.size_central_dir) != 0 )
    err = -1;
  if ( unzlocal_getLong((LUFILE *)fin, pX: &us.offset_central_dir) != 0 )
    err = -1;
  if ( unzlocal_getShort((LUFILE *)fin, pX: &us.gi.size_comment) != 0 )
    err = -1;
  v5 = *(_DWORD *)(fin + 12);
  offset_central_dir = us.offset_central_dir;
  if ( v5 + v4 < us.offset_central_dir + us.size_central_dir || err != 0 )
  {
    if ( *(_BYTE *)fin != 0 )
      CloseHandle(hObject: *(HANDLE *)(fin + 4));
    free(pMem: (void *)fin);
    return nullptr;
  }
  else
  {
    v7 = v5 - us.size_central_dir;
    *(_DWORD *)(fin + 12) = 0;
    us.pfile_in_zip_read = nullptr;
    v8 = _g_pMemAlloc->__vftable;
    us.byte_before_the_zipfile = v4 + v7 - offset_central_dir;
    Alloc_2 = v8->Alloc_2;
    us.file = (LUFILE *)fin;
    us.central_pos = v4;
    v10 = (unz_s *)Alloc_2(this: _g_pMemAlloc, a2: 128u);
    *v10 = us;
    unzGoToFirstFile(file: v10);
    return v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA6F0
// Name: int unzClose(struct unz_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzClose(unz_s *file)
{
  LUFILE *v2; // esi

  if ( file == nullptr )
    return -102;
  if ( file->pfile_in_zip_read != nullptr )
    unzCloseCurrentFile(file);
  v2 = file->file;
  if ( file->file != nullptr )
  {
    if ( v2->is_handle )
      CloseHandle(hObject: v2->h);
    free(pMem: v2);
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FA750
// Name: int unzOpenCurrentFile(struct unz_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzOpenCurrentFile(unz_s *file)
{
  file_in_zip_read_info_s *v2; // esi
  char *v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // edx
  bool v6; // zf
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned int iSizeVar; // [esp+8h] [ebp-Ch] BYREF
  unsigned int size_local_extrafield; // [esp+Ch] [ebp-8h] BYREF
  unsigned int offset_local_extrafield; // [esp+10h] [ebp-4h] BYREF

  iSizeVar = 0;
  offset_local_extrafield = 0;
  size_local_extrafield = 0;
  if ( file == nullptr || file->current_file_ok == 0 )
    return -102;
  if ( file->pfile_in_zip_read != nullptr )
    unzCloseCurrentFile(file);
  if ( unzlocal_CheckCurrentFileCoherencyHeader(
         s: file,
         piSizeVar: &iSizeVar,
         poffset_local_extrafield: &offset_local_extrafield,
         psize_local_extrafield: &size_local_extrafield) != 0 )
    return -103;
  v2 = (file_in_zip_read_info_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 108);
  if ( v2 == nullptr )
    return -104;
  v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x4000);
  v4 = offset_local_extrafield;
  v5 = size_local_extrafield;
  v2->read_buffer = v3;
  v2->offset_local_extrafield = v4;
  v2->size_local_extrafield = v5;
  v2->pos_local_extrafield = 0;
  if ( v3 == nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
    return -104;
  }
  v2->stream_initialised = 0;
  v6 = file->cur_file_info.compression_method == 0;
  v2->crc32_wait = file->cur_file_info.crc;
  v2->crc32 = 0;
  v2->compression_method = file->cur_file_info.compression_method;
  v2->file = file->file;
  v2->byte_before_the_zipfile = file->byte_before_the_zipfile;
  v2->stream.total_out = 0;
  if ( !v6 )
  {
    v2->stream.zalloc = nullptr;
    v2->stream.zfree = nullptr;
    v2->stream.opaque = nullptr;
    if ( inflateInit2(z: &v2->stream) == 0 )
      v2->stream_initialised = 1;
  }
  v2->rest_read_compressed = file->cur_file_info.compressed_size;
  v7 = iSizeVar;
  v2->rest_read_uncompressed = file->cur_file_info.uncompressed_size;
  v8 = file->cur_file_info_internal.offset_curfile + v7 + 30;
  v2->stream.avail_in = 0;
  v2->pos_in_zipfile = v8;
  file->pfile_in_zip_read = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FA880
// Name: int unzReadCurrentFile(struct unz_s __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzReadCurrentFile(unz_s *file, unsigned __int8 *buf, unsigned int len)
{
  file_in_zip_read_info_s *pfile_in_zip_read; // esi
  unsigned int rest_read_uncompressed; // eax
  unsigned int rest_read_compressed; // eax
  unsigned int v7; // edi
  LUFILE *v8; // eax
  int v9; // ecx
  unsigned __int8 *read_buffer; // eax
  unsigned int avail_in; // edi
  unsigned int i; // eax
  const unsigned __int8 *next_out; // ebx
  int v14; // eax
  unsigned int total_out; // ebx
  int v16; // eax
  unsigned int v17; // edi
  int v18; // eax
  int err; // [esp+0h] [ebp-8h]
  unsigned int iRead; // [esp+4h] [ebp-4h]
  const unsigned __int8 *bufBefore; // [esp+10h] [ebp+8h]

  iRead = 0;
  if ( file == nullptr )
    return -102;
  pfile_in_zip_read = file->pfile_in_zip_read;
  if ( pfile_in_zip_read == nullptr )
    return -102;
  if ( pfile_in_zip_read->read_buffer == nullptr )
    return -100;
  if ( len == 0 )
    return 0;
  pfile_in_zip_read->stream.next_out = buf;
  rest_read_uncompressed = pfile_in_zip_read->rest_read_uncompressed;
  pfile_in_zip_read->stream.avail_out = len;
  if ( len > rest_read_uncompressed )
    pfile_in_zip_read->stream.avail_out = rest_read_uncompressed;
  if ( pfile_in_zip_read->stream.avail_out == 0 )
    return iRead;
  while ( 1 )
  {
    if ( pfile_in_zip_read->stream.avail_in == 0 )
    {
      rest_read_compressed = pfile_in_zip_read->rest_read_compressed;
      if ( rest_read_compressed != 0 )
      {
        v7 = 0x4000;
        if ( rest_read_compressed < 0x4000 )
          v7 = pfile_in_zip_read->rest_read_compressed;
        v8 = pfile_in_zip_read->file;
        v9 = pfile_in_zip_read->pos_in_zipfile + pfile_in_zip_read->byte_before_the_zipfile;
        if ( v8->is_handle )
        {
          if ( !v8->canseek )
            return -1;
          SetFilePointer(
            hFile: v8->h,
            lDistanceToMove: v9 + v8->initial_offset,
            lpDistanceToMoveHigh: nullptr,
            dwMoveMethod: 0);
        }
        else
        {
          v8->pos = v9;
        }
        if ( lufread(ptr: pfile_in_zip_read->read_buffer, size: v7, n: 1u, stream: pfile_in_zip_read->file) != 1 )
          return -1;
        read_buffer = (unsigned __int8 *)pfile_in_zip_read->read_buffer;
        pfile_in_zip_read->pos_in_zipfile += v7;
        pfile_in_zip_read->rest_read_compressed -= v7;
        pfile_in_zip_read->stream.next_in = read_buffer;
        pfile_in_zip_read->stream.avail_in = v7;
      }
    }
    if ( pfile_in_zip_read->compression_method != 0 )
      break;
    avail_in = pfile_in_zip_read->stream.avail_in;
    if ( pfile_in_zip_read->stream.avail_out < avail_in )
      avail_in = pfile_in_zip_read->stream.avail_out;
    for ( i = 0; i < avail_in; ++i )
      pfile_in_zip_read->stream.next_out[i] = pfile_in_zip_read->stream.next_in[i];
    next_out = pfile_in_zip_read->stream.next_out;
    v14 = ucrc32(crc: pfile_in_zip_read->crc32, buf: next_out, len: avail_in);
    pfile_in_zip_read->rest_read_uncompressed -= avail_in;
    pfile_in_zip_read->stream.avail_in -= avail_in;
    pfile_in_zip_read->stream.avail_out -= avail_in;
    pfile_in_zip_read->stream.next_in += avail_in;
    pfile_in_zip_read->stream.total_out += avail_in;
    iRead += avail_in;
    pfile_in_zip_read->crc32 = v14;
    pfile_in_zip_read->stream.next_out = (unsigned __int8 *)&next_out[avail_in];
LABEL_30:
    if ( pfile_in_zip_read->stream.avail_out == 0 )
      return iRead;
  }
  total_out = pfile_in_zip_read->stream.total_out;
  bufBefore = pfile_in_zip_read->stream.next_out;
  v16 = inflate(z: &pfile_in_zip_read->stream, f: 2);
  v17 = pfile_in_zip_read->stream.total_out - total_out;
  err = v16;
  v18 = ucrc32(crc: pfile_in_zip_read->crc32, buf: bufBefore, len: v17);
  pfile_in_zip_read->rest_read_uncompressed -= v17;
  iRead += v17;
  pfile_in_zip_read->crc32 = v18;
  if ( err == 1 )
    return iRead;
  if ( err == 0 )
    goto LABEL_30;
  return err;
}

//------------------------------------------------------------------------------
// Address: 0x101FAA40
// Name: public: unsigned long TUnzip::Open(void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TUnzip::Open(TUnzip *this, void *z, unsigned int len, unsigned int flags)
{
  char *v5; // edi
  char v6; // al
  unsigned int v7; // esi
  LUFILE *v9; // eax
  unz_s *v10; // eax

  if ( this->uf != nullptr || this->currentfile != -1 )
    return 0x1000000;
  GetCurrentDirectoryA(nBufferLength: 0x104u, lpBuffer: this->rootdir);
  v5 = (char *)&this->czei + 3;
  do
    v6 = *++v5;
  while ( v6 != 0 );
  v7 = flags;
  strcpy(v5, "\\");
  if ( v7 == 1 && GetFileType(hFile: z) != 1 )
    return 0x2000000;
  flags = 0;
  v9 = lufopen(z, len, flags: v7, err: &flags);
  if ( v9 == nullptr )
    return flags;
  v10 = unzOpenInternal(fin: v9);
  this->uf = v10;
  return v10 != nullptr ? 0 : 1792;
}

//------------------------------------------------------------------------------
// Address: 0x101FAB00
// Name: public: unsigned long TUnzip::Unzip(int,void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TUnzip::Unzip(TUnzip *this, int index, char *dst, unsigned int len, unsigned int flags)
{
  unsigned int v5; // esi
  int currentfile; // eax
  int v9; // esi
  unz_s *uf; // eax
  int v11; // esi
  unz_s *v12; // eax
  int v13; // ebx
  unz_s *v14; // esi
  int v15; // eax
  int v16; // edx
  unsigned int size_filename; // ecx
  char *FileA; // esi
  char v19; // al
  char *v20; // ebx
  char *v21; // ecx
  unsigned __int8 *v22; // eax
  unsigned __int8 v23; // cl
  bool v24; // bl
  char *v25; // eax
  int v26; // eax
  signed int v27; // eax
  bool v28; // zf
  char v29; // bl
  unz_s *v30; // [esp-14h] [ebp-424Ch]
  _BYTE Buffer[16384]; // [esp+8h] [ebp-4230h] BYREF
  ZIPENTRY ze; // [esp+4008h] [ebp-230h] BYREF
  unsigned __int8 str1[260]; // [esp+4134h] [ebp-104h] BYREF

  v5 = flags;
  if ( flags == 3 )
  {
    currentfile = this->currentfile;
    v9 = index;
    if ( index != currentfile )
    {
      if ( currentfile != -1 )
        unzCloseCurrentFile(file: this->uf);
      uf = this->uf;
      this->currentfile = -1;
      if ( v9 >= (signed int)uf->gi.number_entry )
        return 0x10000;
      if ( v9 < (signed int)uf->num_file )
        unzGoToFirstFile(file: uf);
      while ( (signed int)this->uf->num_file < v9 )
        unzGoToNextFile(file: this->uf);
      unzOpenCurrentFile(file: this->uf);
      this->currentfile = v9;
    }
    v11 = unzReadCurrentFile(file: this->uf, buf: dst, len);
    if ( v11 <= 0 )
    {
      unzCloseCurrentFile(file: this->uf);
      this->currentfile = -1;
      return v11 != 0 ? 0x5000000 : 0;
    }
    else
    {
      return 1536;
    }
  }
  else
  {
    if ( flags != 2 && flags != 1 )
      return 0x10000;
    if ( this->currentfile != -1 )
      unzCloseCurrentFile(file: this->uf);
    v12 = this->uf;
    this->currentfile = -1;
    v13 = index;
    if ( index < (signed int)v12->gi.number_entry )
    {
      if ( index < (signed int)v12->num_file )
        unzGoToFirstFile(file: v12);
      if ( (signed int)this->uf->num_file < v13 )
      {
        do
        {
          v14 = this->uf;
          if ( this->uf != nullptr && v14->current_file_ok != 0 )
          {
            v15 = v14->num_file + 1;
            if ( v15 != v14->gi.number_entry )
            {
              v16 = v14->cur_file_info.size_file_extra + v14->cur_file_info.size_file_comment;
              size_filename = v14->cur_file_info.size_filename;
              v14->num_file = v15;
              v14->pos_in_central_dir += v16 + size_filename + 46;
              v14->current_file_ok = unzlocal_GetCurrentFileInfoInternal(
                                       file: v14,
                                       pfile_info: &v14->cur_file_info,
                                       pfile_info_internal: &v14->cur_file_info_internal,
                                       szFileName: nullptr,
                                       fileNameBufferSize: 0,
                                       extraField: nullptr,
                                       extraFieldBufferSize: 0,
                                       szComment: nullptr,
                                       commentBufferSize: 0) == 0;
            }
          }
        }
        while ( (signed int)this->uf->num_file < v13 );
        v5 = flags;
      }
      TUnzip::Get(this, index: v13, &ze);
      if ( (ze.attr & 0x10) != 0 )
      {
        if ( v5 != 1 )
          EnsureDirectory(rootdir: this->rootdir, dir: ze.name);
        return 0;
      }
      else
      {
        v28 = v5 == 1;
        FileA = dst;
        if ( !v28 )
        {
          v19 = *dst;
          v20 = dst;
          v21 = dst;
          if ( *dst != 0 )
          {
            do
            {
              if ( v19 == 47 || v19 == 92 )
                v20 = v21 + 1;
              v19 = *++v21;
            }
            while ( v19 != 0 );
            if ( v20 != dst )
            {
              v22 = (unsigned __int8 *)dst;
              do
              {
                v23 = *v22;
                v22[str1 - (unsigned __int8 *)FileA] = *v22;
                ++v22;
              }
              while ( v23 != 0 );
              *((_BYTE *)&ze.unc_size + v20 - FileA + 3) = 0;
              v24 = str1[0] == 47 || str1[0] == 92 || str1[1] == 58;
              strstr(str1, str2: "../");
              dst = v25;
              strstr(str1, str2: "..\\");
              if ( !v24 && dst == nullptr && v26 == 0 )
                EnsureDirectory(rootdir: this->rootdir, dir: (const char *)str1);
            }
          }
          FileA = (char *)CreateFileA(
                            lpFileName: FileA,
                            dwDesiredAccess: 0x40000000u,
                            dwShareMode: 0,
                            lpSecurityAttributes: nullptr,
                            dwCreationDisposition: 2u,
                            dwFlagsAndAttributes: ze.attr,
                            hTemplateFile: nullptr);
        }
        if ( FileA == (char *)-1 )
        {
          return 512;
        }
        else
        {
          unzOpenCurrentFile(file: this->uf);
          v30 = this->uf;
          HIBYTE(dst) = 0;
          v27 = unzReadCurrentFile(file: v30, buf: Buffer, len: 0x4000u);
          v28 = v27 == 0;
          if ( v27 < 0 )
          {
LABEL_57:
            v29 = 1;
          }
          else
          {
            while ( !v28 )
            {
              if ( !WriteFile(
                      hFile: FileA,
                      lpBuffer: Buffer,
                      nNumberOfBytesToWrite: v27,
                      lpNumberOfBytesWritten: (LPDWORD)&index,
                      lpOverlapped: nullptr) )
              {
                HIBYTE(dst) = 1;
                break;
              }
              v27 = unzReadCurrentFile(file: this->uf, buf: Buffer, len: 0x4000u);
              v28 = v27 == 0;
              if ( v27 < 0 )
                goto LABEL_57;
            }
            v29 = HIBYTE(dst);
          }
          if ( GetFileType(hFile: FileA) == 1 && v29 == 0 )
            SetFileTime(
              hFile: FileA,
              lpCreationTime: &ze.ctime,
              lpLastAccessTime: &ze.atime,
              lpLastWriteTime: &ze.mtime);
          if ( flags != 1 )
            CloseHandle(hObject: FileA);
          unzCloseCurrentFile(file: this->uf);
          return v29 != 0 ? 0x400 : 0;
        }
      }
    }
    else
    {
      return 0x10000;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FAE70
// Name: struct HZIP__ __near * OpenZipU(void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HZIP__ *__cdecl OpenZipU(void *z, unsigned int len, unsigned int flags)
{
  TUnzip *v3; // eax
  TUnzip *v4; // esi
  HZIP__ *result; // eax

  v3 = (TUnzip *)MemAlloc_Alloc(nSize: 0x23Cu);
  if ( v3 != nullptr )
  {
    v3->uf = nullptr;
    v3->currentfile = -1;
    v3->czei = -1;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  lasterrorU = TUnzip::Open(this: v4, z, len, flags);
  if ( lasterrorU != 0 )
  {
    free(pMem: v4);
    return nullptr;
  }
  else
  {
    result = (HZIP__ *)MemAlloc_Alloc(nSize: 8u);
    *((_DWORD *)result + 1) = v4;
    *(_DWORD *)result = 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FAEE0
// Name: unsigned long UnzipItem(struct HZIP__ __near *,int,void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UnzipItem(TUnzip **hz, int index, char *dst, unsigned int len, unsigned int flags)
{
  int result; // eax

  if ( hz != nullptr )
  {
    if ( *hz == (TUnzip *)1 )
    {
      result = TUnzip::Unzip(this: hz[1], index, dst, len, flags);
      lasterrorU = result;
    }
    else
    {
      lasterrorU = 0x80000;
      return 0x80000;
    }
  }
  else
  {
    lasterrorU = 0x10000;
    return 0x10000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FAF30
// Name: unsigned long CloseZipU(struct HZIP__ __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CloseZipU(HZIP__ *hz)
{
  int v2; // esi
  unz_s *v3; // eax

  if ( hz != nullptr )
  {
    if ( *(_DWORD *)hz == 1 )
    {
      v2 = *((_DWORD *)hz + 1);
      if ( *(_DWORD *)(v2 + 4) != -1 )
        unzCloseCurrentFile(file: *(unz_s **)v2);
      v3 = *(unz_s **)v2;
      *(_DWORD *)(v2 + 4) = -1;
      if ( v3 != nullptr )
        unzClose(file: v3);
      *(_DWORD *)v2 = 0;
      lasterrorU = 0;
      free(pMem: (void *)v2);
      free(pMem: hz);
      return lasterrorU;
    }
    else
    {
      lasterrorU = 0x80000;
      return 0x80000;
    }
  }
  else
  {
    lasterrorU = 0x10000;
    return 0x10000;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101F6FB0
// Name: int inflate_flush(struct inflate_blocks_state __near *,struct z_stream_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_flush(inflate_blocks_state *s, z_stream_s *z, int r)
{
  unsigned __int8 *write; // edi
  unsigned __int8 *read; // eax
  unsigned int avail_out; // ecx
  unsigned int v7; // edi
  unsigned int (__cdecl *checkfn)(unsigned int, const unsigned __int8 *, unsigned int); // ecx
  unsigned int v9; // eax
  unsigned __int8 *end; // edx
  unsigned __int8 *window; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edi
  unsigned int (__cdecl *v14)(unsigned int, const unsigned __int8 *, unsigned int); // eax
  unsigned int v15; // eax
  unsigned __int8 *p; // [esp+Ch] [ebp-4h]
  unsigned __int8 *q; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 *qa; // [esp+1Ch] [ebp+Ch]

  write = s->write;
  p = z->next_out;
  read = s->read;
  q = read;
  if ( read > write )
    write = s->end;
  avail_out = z->avail_out;
  v7 = write - read;
  if ( v7 > avail_out )
    v7 = z->avail_out;
  if ( v7 != 0 && r == -5 )
    r = 0;
  z->total_out += v7;
  z->avail_out = avail_out - v7;
  checkfn = s->checkfn;
  if ( checkfn != nullptr )
  {
    v9 = checkfn(a1: s->check, a2: read, a3: v7);
    s->check = v9;
    z->adler = v9;
    read = q;
  }
  if ( v7 != 0 )
  {
    memcpy(dst: p, src: read, count: v7);
    p += v7;
    read = &q[v7];
  }
  end = s->end;
  if ( read == end )
  {
    window = s->window;
    qa = window;
    if ( s->write == end )
      s->write = window;
    v12 = z->avail_out;
    v13 = s->write - window;
    if ( v13 > v12 )
      v13 = z->avail_out;
    if ( v13 != 0 && r == -5 )
      r = 0;
    z->total_out += v13;
    z->avail_out = v12 - v13;
    v14 = s->checkfn;
    if ( v14 != nullptr )
    {
      v15 = v14(a1: s->check, a2: window, a3: v13);
      window = qa;
      s->check = v15;
      z->adler = v15;
    }
    memcpy(dst: p, src: window, count: v13);
    p += v13;
    read = &qa[v13];
  }
  z->next_out = p;
  s->read = read;
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x101F70B0
// Name: struct inflate_codes_state __near * inflate_codes_new(unsigned int,unsigned int,struct inflate_huft_s const __near *,struct inflate_huft_s const __near *,struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
inflate_codes_state *__cdecl inflate_codes_new(
        unsigned __int8 bl,
        unsigned __int8 bd,
        const inflate_huft_s *tl,
        const inflate_huft_s *td,
        z_stream_s *z)
{
  inflate_codes_state *result; // eax

  result = (inflate_codes_state *)z->zalloc(a1: z->opaque, a2: 1, a3: 28);
  if ( result != nullptr )
  {
    result->lbits = bl;
    result->dbits = bd;
    result->mode = START;
    result->ltree = tl;
    result->dtree = td;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F70F0
// Name: void inflate_blocks_reset(struct inflate_blocks_state __near *,struct z_stream_s __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl inflate_blocks_reset(inflate_blocks_state *s, z_stream_s *z, unsigned int *c)
{
  unsigned __int8 *window; // eax
  unsigned int (__cdecl *checkfn)(unsigned int, const unsigned __int8 *, unsigned int); // eax
  unsigned int v5; // eax

  if ( c != nullptr )
    *c = s->check;
  if ( s->mode == IBM_BTREE || s->mode == IBM_DTREE )
    z->zfree(a1: z->opaque, a2: s->sub.trees.blens);
  if ( s->mode == IBM_CODES )
    z->zfree(a1: z->opaque, a2: (void *)s->sub.left);
  window = s->window;
  s->write = window;
  s->read = window;
  checkfn = s->checkfn;
  s->mode = IBM_TYPE;
  s->bitk = 0;
  s->bitb = 0;
  if ( checkfn != nullptr )
  {
    v5 = checkfn(a1: 0, a2: nullptr, a3: 0);
    s->check = v5;
    z->adler = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7180
// Name: struct inflate_blocks_state __near * inflate_blocks_new(struct z_stream_s __near *,unsigned long (*)(unsigned long,unsigned char const __near *,unsigned int),unsigned int)
// Source: json
//------------------------------------------------------------------------------
inflate_blocks_state *__cdecl inflate_blocks_new(
        z_stream_s *z,
        unsigned int (__cdecl *c)(unsigned int, const unsigned __int8 *, unsigned int),
        unsigned int w)
{
  inflate_blocks_state *v3; // esi
  inflate_huft_s *v4; // eax
  unsigned __int8 *v6; // eax

  v3 = (inflate_blocks_state *)z->zalloc(a1: z->opaque, a2: 1, a3: 64);
  if ( v3 == nullptr )
    return nullptr;
  v4 = (inflate_huft_s *)z->zalloc(a1: z->opaque, a2: 8, a3: 1440);
  v3->hufts = v4;
  if ( v4 == nullptr )
  {
    z->zfree(a1: z->opaque, a2: v3);
    return nullptr;
  }
  v6 = (unsigned __int8 *)z->zalloc(a1: z->opaque, a2: 1, a3: w);
  v3->window = v6;
  if ( v6 != nullptr )
  {
    v3->end = &v6[w];
    v3->checkfn = c;
    v3->mode = IBM_TYPE;
    inflate_blocks_reset(s: v3, z, c: nullptr);
    return v3;
  }
  else
  {
    z->zfree(a1: z->opaque, a2: v3->hufts);
    z->zfree(a1: z->opaque, a2: v3);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7230
// Name: int inflate_blocks_free(struct inflate_blocks_state __near *,struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_blocks_free(inflate_blocks_state *s, z_stream_s *z)
{
  unsigned __int8 *window; // eax
  unsigned int (__cdecl *checkfn)(unsigned int, const unsigned __int8 *, unsigned int); // eax
  unsigned int v4; // eax

  if ( s->mode == IBM_BTREE || s->mode == IBM_DTREE )
    z->zfree(a1: z->opaque, a2: s->sub.trees.blens);
  if ( s->mode == IBM_CODES )
    z->zfree(a1: z->opaque, a2: (void *)s->sub.left);
  window = s->window;
  s->write = window;
  s->read = window;
  checkfn = s->checkfn;
  s->mode = IBM_TYPE;
  s->bitk = 0;
  s->bitb = 0;
  if ( checkfn != nullptr )
  {
    v4 = checkfn(a1: 0, a2: nullptr, a3: 0);
    s->check = v4;
    z->adler = v4;
  }
  z->zfree(a1: z->opaque, a2: s->window);
  z->zfree(a1: z->opaque, a2: s->hufts);
  z->zfree(a1: z->opaque, a2: s);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F72D0
// Name: int huft_build(unsigned int __near *,unsigned int,unsigned int,unsigned int const __near *,unsigned int const __near *,struct inflate_huft_s __near * __near *,unsigned int __near *,struct inflate_huft_s __near *,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl huft_build(
        unsigned int *b,
        unsigned int n,
        unsigned int s,
        const unsigned int *d,
        const unsigned int *e,
        inflate_huft_s **t,
        unsigned int *m,
        inflate_huft_s *hp,
        unsigned int *hn,
        unsigned int *v)
{
  unsigned int *v10; // eax
  unsigned int v11; // edx
  unsigned int v13; // edx
  unsigned int j; // ecx
  unsigned int ii; // esi
  int v16; // eax
  int v17; // eax
  unsigned int *v18; // edi
  unsigned int v19; // ecx
  int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // esi
  int v23; // edi
  unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // ecx
  unsigned int v27; // esi
  int v28; // ecx
  unsigned int v29; // edi
  int v30; // ebx
  unsigned int base; // esi
  int v32; // eax
  unsigned int v33; // edx
  unsigned int v34; // ecx
  unsigned int v35; // eax
  unsigned int *v36; // edi
  unsigned int v37; // edi
  unsigned int v38; // eax
  int v39; // eax
  unsigned int v40; // edx
  inflate_huft_s *v41; // edi
  unsigned int v42; // esi
  unsigned __int8 v43; // dl
  unsigned int v44; // eax
  int v45; // ecx
  unsigned int v46; // eax
  int v47; // eax
  int v48; // edx
  unsigned int v49; // eax
  unsigned int *v50; // ecx
  unsigned int jj; // eax
  int v52; // eax
  inflate_huft_s *u[15]; // [esp+8h] [ebp-F8h] BYREF
  unsigned int x[16]; // [esp+44h] [ebp-BCh]
  unsigned int c[16]; // [esp+84h] [ebp-7Ch] BYREF
  int y; // [esp+C4h] [ebp-3Ch]
  inflate_huft_s **v57; // [esp+C8h] [ebp-38h]
  unsigned int v58; // [esp+CCh] [ebp-34h]
  unsigned int v59; // [esp+D0h] [ebp-30h]
  unsigned int z; // [esp+D4h] [ebp-2Ch]
  inflate_huft_s r; // [esp+D8h] [ebp-28h]
  int g; // [esp+E0h] [ebp-20h]
  unsigned int *v63; // [esp+E4h] [ebp-1Ch]
  unsigned int i; // [esp+E8h] [ebp-18h]
  unsigned int *xp; // [esp+ECh] [ebp-14h]
  unsigned int a; // [esp+F0h] [ebp-10h]
  int h; // [esp+F4h] [ebp-Ch]
  int k; // [esp+F8h] [ebp-8h]
  int l; // [esp+FCh] [ebp-4h]
  unsigned int *p; // [esp+108h] [ebp+8h]
  unsigned int *pa; // [esp+108h] [ebp+8h]
  unsigned int na; // [esp+10Ch] [ebp+Ch]

  v10 = b;
  memset(c, 0, sizeof(c));
  v11 = n;
  do
  {
    ++c[*v10++];
    --v11;
  }
  while ( v11 != 0 );
  if ( c[0] == n )
  {
    *t = nullptr;
    *m = 0;
    return 0;
  }
  else
  {
    v13 = *m;
    l = *m;
    for ( j = 1; j <= 0xF; ++j )
    {
      if ( c[j] != 0 )
        break;
    }
    k = j;
    if ( v13 < j )
    {
      l = j;
      v13 = j;
    }
    for ( ii = 15; ii != 0; --ii )
    {
      if ( c[ii] != 0 )
        break;
    }
    g = ii;
    if ( v13 > ii )
    {
      l = ii;
      v13 = ii;
    }
    *m = v13;
    v16 = 1 << j;
    if ( j >= ii )
    {
LABEL_18:
      v18 = &c[ii];
      xp = (unsigned int *)(4 * ii);
      v19 = *v18;
      v20 = v16 - *v18;
      y = v20;
      if ( v20 >= 0 )
      {
        *v18 = v20 + v19;
        v21 = 0;
        v22 = ii - 1;
        x[1] = 0;
        if ( v22 != 0 )
        {
          v23 = 0;
          do
          {
            v21 += c[++v23];
            --v22;
            x[v23 + 1] = v21;
          }
          while ( v22 != 0 );
        }
        v24 = b;
        v25 = 0;
        do
        {
          v26 = *v24++;
          p = v24;
          if ( v26 != 0 )
          {
            v27 = x[v26];
            v[v27] = v25;
            x[v26] = v27 + 1;
            v24 = p;
          }
          ++v25;
        }
        while ( v25 < n );
        na = *(unsigned int *)((char *)x + (_DWORD)xp);
        pa = v;
        x[0] = 0;
        u[0] = nullptr;
        xp = nullptr;
        z = 0;
        v28 = k;
        v29 = 0;
        v30 = -v13;
        i = 0;
        h = -1;
        if ( k > g )
        {
LABEL_68:
          if ( v20 == 0 || g == 1 )
            return 0;
          else
            return -5;
        }
        else
        {
          base = r.base;
          v63 = &c[k];
          while ( 1 )
          {
            a = *v63;
            if ( a != 0 )
              break;
LABEL_66:
            ++v63;
            k = ++v28;
            if ( v28 > g )
            {
              v20 = y;
              goto LABEL_68;
            }
          }
          while ( 1 )
          {
            --a;
            v32 = v30 + v13;
            if ( k > (int)(v30 + v13) )
              break;
LABEL_49:
            r.word.what.Bits = k - v30;
            if ( pa < &v[na] )
            {
              v46 = *pa;
              if ( *pa >= s )
              {
                v47 = v46 - s;
                r.word.what.Exop = LOBYTE(e[v47]) + 80;
                base = d[v47];
              }
              else
              {
                r.word.what.Exop = v46 < 0x100 ? 0 : 96;
                base = v46;
              }
              ++pa;
            }
            else
            {
              r.word.what.Exop = -64;
            }
            v48 = 1 << (k - v30);
            v49 = v29 >> v30;
            if ( v29 >> v30 < z )
            {
              v50 = &xp[2 * v49];
              do
              {
                *v50 = r.word.pad;
                v50[1] = base;
                v49 += v48;
                v50 += 2 * v48;
              }
              while ( v49 < z );
              v29 = i;
            }
            for ( jj = 1 << (k - 1); (jj & v29) != 0; jj >>= 1 )
              v29 ^= jj;
            v29 ^= jj;
            v52 = h;
            i = v29;
            if ( (v29 & ((1 << v30) - 1)) != x[h] )
            {
              do
              {
                v30 -= l;
                --v52;
              }
              while ( (v29 & ((1 << v30) - 1)) != x[v52] );
              h = v52;
            }
            v13 = l;
            if ( a == 0 )
            {
              v28 = k;
              goto LABEL_66;
            }
          }
          v58 = a + 1;
          v59 = v30 - v13;
          while ( 1 )
          {
            v59 += v13;
            ++h;
            v30 = v32;
            v33 = g - v32;
            if ( g - v32 > (unsigned int)l )
              v33 = l;
            v34 = k - v32;
            if ( 1 << (k - v32) > v58 )
            {
              v35 = -1 - a + (1 << v34);
              v36 = v63;
              if ( v34 < v33 && ++v34 < v33 )
              {
                while ( 1 )
                {
                  xp = v36 + 1;
                  v37 = v36[1];
                  v38 = 2 * v35;
                  if ( v38 <= v37 )
                    break;
                  ++v34;
                  v35 = v38 - v37;
                  if ( v34 >= v33 )
                    break;
                  v36 = xp;
                }
              }
            }
            v39 = *hn;
            z = 1 << v34;
            v40 = v39 + (1 << v34);
            if ( v40 > 0x5A0 )
              return -4;
            v41 = &hp[v39];
            v57 = &u[h];
            *v57 = v41;
            *hn = v40;
            xp = &v41->word.pad;
            if ( h != 0 )
            {
              v42 = i;
              v43 = l;
              x[h] = i;
              r.word.what.Exop = v34;
              v44 = v42 >> v59;
              v45 = (int)*(v57 - 1);
              r.word.what.Bits = v43;
              base = (((int)v41 - v45) >> 3) - (v42 >> v59);
              *(_DWORD *)(v45 + 8 * v44) = r.word.pad;
              *(_DWORD *)(v45 + 8 * v44 + 4) = base;
            }
            else
            {
              *t = v41;
            }
            v32 = v30 + l;
            if ( k <= v30 + l )
            {
              v29 = i;
              goto LABEL_49;
            }
            v13 = l;
          }
        }
      }
      else
      {
        return -3;
      }
    }
    else
    {
      while ( 1 )
      {
        v17 = v16 - c[j];
        if ( v17 < 0 )
          return -3;
        ++j;
        v16 = 2 * v17;
        if ( j >= ii )
          goto LABEL_18;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F76C0
// Name: int inflate_trees_bits(unsigned int __near *,unsigned int __near *,struct inflate_huft_s __near * __near *,struct inflate_huft_s __near *,struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_trees_bits(
        unsigned int *c,
        unsigned int *bb,
        inflate_huft_s **tb,
        inflate_huft_s *hp,
        z_stream_s *z)
{
  void *(__cdecl *zalloc)(void *, unsigned int, unsigned int); // ecx
  unsigned int *v6; // eax
  unsigned int *v7; // ebx
  int v9; // eax
  int v10; // esi
  void *opaque; // [esp-Ch] [ebp-18h]
  unsigned int hn; // [esp+8h] [ebp-4h] BYREF

  zalloc = z->zalloc;
  opaque = z->opaque;
  hn = 0;
  v6 = (unsigned int *)zalloc(a1: opaque, a2: 19u, a3: 4u);
  v7 = v6;
  if ( v6 == nullptr )
    return -4;
  v9 = huft_build(b: c, n: 0x13u, s: 0x13u, d: nullptr, e: nullptr, t: tb, m: bb, hp, &hn, v: v6);
  v10 = v9;
  if ( v9 == -3 )
  {
    z->msg = "oversubscribed dynamic bit lengths tree";
  }
  else if ( v9 == -5 || *bb == 0 )
  {
    z->msg = "incomplete dynamic bit lengths tree";
    v10 = -3;
  }
  z->zfree(a1: z->opaque, a2: v7);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x101F7760
// Name: int inflate_trees_dynamic(unsigned int,unsigned int,unsigned int __near *,unsigned int __near *,unsigned int __near *,struct inflate_huft_s __near * __near *,struct inflate_huft_s __near * __near *,struct inflate_huft_s __near *,struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_trees_dynamic(
        unsigned int nl,
        unsigned int nd,
        unsigned int *c,
        unsigned int *bl,
        unsigned int *bd,
        inflate_huft_s **tl,
        inflate_huft_s **td,
        inflate_huft_s *hp,
        z_stream_s *z)
{
  void *(__cdecl *zalloc)(void *, unsigned int, unsigned int); // ecx
  unsigned int *v10; // eax
  unsigned int *v11; // edi
  int v13; // eax
  int v14; // esi
  int v15; // eax
  void (__cdecl *zfree)(void *, void *); // eax
  void (__cdecl *v17)(void *, void *); // eax
  void *opaque; // [esp-Ch] [ebp-18h]
  void *v19; // [esp-Ch] [ebp-18h]
  void *v20; // [esp-Ch] [ebp-18h]
  unsigned int hn; // [esp+8h] [ebp-4h] BYREF

  zalloc = z->zalloc;
  opaque = z->opaque;
  hn = 0;
  v10 = (unsigned int *)zalloc(a1: opaque, a2: 288u, a3: 4u);
  v11 = v10;
  if ( v10 == nullptr )
    return -4;
  v13 = huft_build(b: c, n: nl, s: 0x101u, d: cplens, e: cplext, t: tl, m: bl, hp, &hn, v: v10);
  v14 = v13;
  if ( v13 != 0 )
  {
    if ( v13 == -3 )
    {
      z->msg = "oversubscribed literal/length tree";
      goto LABEL_20;
    }
    if ( v13 == -4 )
      goto LABEL_20;
LABEL_19:
    z->msg = "incomplete literal/length tree";
    v14 = -3;
    goto LABEL_20;
  }
  if ( *bl == 0 )
    goto LABEL_19;
  v15 = huft_build(b: &c[nl], n: nd, s: 0, d: cpdist, e: cpdext, t: td, m: bd, hp, &hn, v: v11);
  v14 = v15;
  switch ( v15 )
  {
    case 0:
      if ( *bd != 0 || nl <= 0x101 )
      {
        z->zfree(a1: z->opaque, a2: v11);
        return 0;
      }
LABEL_14:
      z->msg = "empty distance tree with lengths";
      v14 = -3;
      goto LABEL_20;
    case -3:
      zfree = z->zfree;
      v19 = z->opaque;
      z->msg = "oversubscribed distance tree";
      zfree(a1: v19, a2: v11);
      return -3;
    case -5:
      v17 = z->zfree;
      v20 = z->opaque;
      z->msg = "incomplete distance tree";
      v17(a1: v20, a2: v11);
      return -3;
    default:
      break;
  }
  if ( v15 != -4 )
    goto LABEL_14;
LABEL_20:
  z->zfree(a1: z->opaque, a2: v11);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x101F78E0
// Name: int inflate_fast(unsigned int,unsigned int,struct inflate_huft_s const __near *,struct inflate_huft_s const __near *,struct inflate_blocks_state __near *,struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_fast(
        unsigned int bl,
        unsigned int bd,
        const inflate_huft_s *tl,
        const inflate_huft_s *td,
        inflate_blocks_state *s,
        z_stream_s *z)
{
  unsigned __int8 *read; // esi
  unsigned int bitk; // eax
  unsigned __int8 *write; // edi
  unsigned int bitb; // edx
  int v10; // esi
  int v11; // esi
  int Exop; // ebx
  const inflate_huft_s *v13; // esi
  int Bits; // ecx
  unsigned int v15; // ecx
  int v16; // ebx
  unsigned int v17; // eax
  unsigned int i; // edx
  int v19; // ebx
  int v20; // ebx
  const inflate_huft_s *v21; // esi
  unsigned int v22; // ecx
  int v23; // ecx
  unsigned int v24; // ebx
  int v25; // edi
  int v26; // edi
  char v27; // cl
  unsigned int v28; // ebx
  unsigned __int8 *window; // ecx
  unsigned __int8 *v30; // esi
  unsigned __int8 *v31; // esi
  unsigned int v32; // ecx
  int v33; // esi
  unsigned int v34; // ecx
  int v35; // ecx
  z_stream_s *v37; // ecx
  unsigned int v38; // ecx
  int v39; // ecx
  unsigned int v40; // esi
  int v41; // edx
  unsigned int md; // [esp+Ch] [ebp-18h]
  unsigned int ml; // [esp+10h] [ebp-14h]
  unsigned __int8 *q; // [esp+14h] [ebp-10h]
  unsigned __int8 *m; // [esp+18h] [ebp-Ch]
  unsigned int n; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *p; // [esp+20h] [ebp-4h]
  unsigned __int8 *pa; // [esp+20h] [ebp-4h]
  unsigned __int8 *pb; // [esp+20h] [ebp-4h]
  unsigned __int8 *pc; // [esp+20h] [ebp-4h]
  unsigned int d; // [esp+2Ch] [ebp+8h]
  unsigned int c; // [esp+30h] [ebp+Ch]
  unsigned int ca; // [esp+30h] [ebp+Ch]

  p = z->next_in;
  read = s->read;
  bitk = s->bitk;
  write = s->write;
  n = z->avail_in;
  bitb = s->bitb;
  q = write;
  if ( write >= read )
    m = (unsigned __int8 *)(s->end - write);
  else
    m = (unsigned __int8 *)(read - write - 1);
  ml = inflate_mask[bl];
  md = inflate_mask[bd];
  while ( 1 )
  {
    for ( ; bitk < 0x14; bitb |= v11 )
    {
      v10 = *p;
      --n;
      ++p;
      v11 = v10 << bitk;
      bitk += 8;
    }
    Exop = tl[bitb & ml].word.what.Exop;
    v13 = &tl[bitb & ml];
    Bits = v13->word.what.Bits;
    bitb >>= Bits;
    if ( Exop == 0 )
    {
LABEL_29:
      bitk -= Bits;
      *write++ = v13->base;
      --m;
      goto LABEL_30;
    }
    bitk -= v13->word.what.Bits;
    if ( (Exop & 0x10) == 0 )
      break;
LABEL_12:
    v16 = Exop & 0xF;
    v17 = bitk - v16;
    c = v13->base + (bitb & inflate_mask[v16]);
    for ( i = bitb >> v16; v17 < 0xF; i |= v19 )
    {
      --n;
      v19 = *p << v17;
      v17 += 8;
      ++p;
    }
    v20 = td[i & md].word.what.Exop;
    v21 = &td[i & md];
    bitb = i >> v21->word.what.Bits;
    bitk = v17 - v21->word.what.Bits;
    if ( (v20 & 0x10) == 0 )
    {
      while ( (v20 & 0x40) == 0 )
      {
        v22 = v21->base + (bitb & inflate_mask[v20]);
        v20 = v21[v22].word.what.Exop;
        v21 += v22;
        v23 = v21->word.what.Bits;
        bitb >>= v23;
        bitk -= v23;
        if ( (v20 & 0x10) != 0 )
          goto LABEL_17;
      }
      v37 = z;
      z->msg = "invalid distance code";
      goto LABEL_41;
    }
LABEL_17:
    v24 = v20 & 0xF;
    if ( bitk < v24 )
    {
      do
      {
        v25 = *p;
        --n;
        ++p;
        v26 = v25 << bitk;
        bitk += 8;
        bitb |= v26;
      }
      while ( bitk < v24 );
      write = q;
    }
    bitk -= v24;
    d = v21->base + (bitb & inflate_mask[v24]);
    v27 = v24;
    v28 = c;
    m -= c;
    bitb >>= v27;
    window = s->window;
    if ( write - window < d )
    {
      v32 = d + window - write;
      v31 = &s->end[-v32];
      if ( c > v32 )
      {
        ca = c - v32;
        do
        {
          *write++ = *v31++;
          --v32;
        }
        while ( v32 != 0 );
        v31 = s->window;
        v28 = ca;
      }
    }
    else
    {
      v30 = &write[-d];
      write += 2;
      *(write - 2) = *v30;
      *(write - 1) = v30[1];
      v31 = v30 + 2;
      v28 = c - 2;
    }
    v33 = v31 - write;
    do
    {
      *write = write[v33];
      ++write;
      --v28;
    }
    while ( v28 != 0 );
LABEL_30:
    q = write;
    if ( (unsigned int)m < 0x102 || n < 0xA )
    {
      v34 = z->avail_in - n;
      if ( bitk >> 3 < v34 )
        v34 = bitk >> 3;
      pa = &p[-v34];
      s->bitb = bitb;
      s->bitk = bitk - 8 * v34;
      z->avail_in = n + v34;
      v35 = pa - z->next_in;
      z->next_in = pa;
      z->total_in += v35;
      s->write = write;
      return 0;
    }
  }
  while ( (Exop & 0x40) == 0 )
  {
    v15 = v13->base + (bitb & inflate_mask[Exop]);
    Exop = v13[v15].word.what.Exop;
    v13 += v15;
    Bits = v13->word.what.Bits;
    bitb >>= Bits;
    if ( Exop == 0 )
      goto LABEL_29;
    bitk -= v13->word.what.Bits;
    if ( (Exop & 0x10) != 0 )
      goto LABEL_12;
  }
  if ( (Exop & 0x20) == 0 )
  {
    v37 = z;
    z->msg = "invalid literal/length code";
LABEL_41:
    v40 = v37->avail_in - n;
    if ( bitk >> 3 < v40 )
      v40 = bitk >> 3;
    pc = &p[-v40];
    s->bitb = bitb;
    s->bitk = bitk - 8 * v40;
    v41 = pc - v37->next_in;
    v37->next_in = pc;
    v37->total_in += v41;
    v37->avail_in = n + v40;
    s->write = write;
    return -3;
  }
  v38 = z->avail_in - n;
  if ( bitk >> 3 < v38 )
    v38 = bitk >> 3;
  pb = &p[-v38];
  s->bitb = bitb;
  s->bitk = bitk - 8 * v38;
  z->avail_in = n + v38;
  v39 = pb - z->next_in;
  z->next_in = pb;
  z->total_in += v39;
  s->write = write;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F7BF0
// Name: unsigned long ucrc32(unsigned long,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ucrc32(unsigned int crc, const unsigned __int8 *buf, unsigned int len)
{
  const unsigned __int8 *v3; // ecx
  unsigned int v5; // edx
  unsigned int v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax

  v3 = buf;
  if ( buf == nullptr )
    return 0;
  v5 = len;
  v6 = ~crc;
  if ( len >= 8 )
  {
    v7 = len >> 3;
    do
    {
      v8 = crc_table[(unsigned __int8)(v6 ^ *v3)] ^ (v6 >> 8);
      v9 = crc_table[(unsigned __int8)(v8 ^ v3[1])] ^ (v8 >> 8);
      v10 = crc_table[(unsigned __int8)(v9 ^ v3[2])] ^ (v9 >> 8);
      v11 = crc_table[(unsigned __int8)(v10 ^ v3[3])] ^ (v10 >> 8);
      v12 = crc_table[(unsigned __int8)(v11 ^ v3[4])] ^ (v11 >> 8);
      v13 = crc_table[(unsigned __int8)(v12 ^ v3[5])] ^ (v12 >> 8);
      v14 = crc_table[(unsigned __int8)(v13 ^ v3[6])] ^ (v13 >> 8);
      v6 = crc_table[(unsigned __int8)(v14 ^ v3[7])] ^ (v14 >> 8);
      v3 += 8;
      v5 -= 8;
      --v7;
    }
    while ( v7 != 0 );
  }
  for ( ; v5 != 0; --v5 )
    v6 = crc_table[(unsigned __int8)(v6 ^ *v3++)] ^ (v6 >> 8);
  return ~v6;
}

//------------------------------------------------------------------------------
// Address: 0x101F7D00
// Name: unsigned long adler32(unsigned long,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl adler32(unsigned int adler, const unsigned __int8 *buf, unsigned int len)
{
  const unsigned __int8 *v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // edi
  unsigned int i; // ebx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // ecx
  int v11; // edi
  int v12; // ecx
  int v13; // edi
  int v14; // ecx
  int v15; // edi
  int v16; // ecx
  int v17; // edi
  int v18; // ecx
  int v19; // edi
  int v20; // ecx
  int v21; // edi
  int v22; // ecx
  int v23; // edi
  int v24; // ecx
  int v25; // edi
  int v26; // ecx
  int v27; // edi
  int v28; // ecx
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

  v3 = buf;
  v4 = (unsigned __int16)adler;
  v5 = HIWORD(adler);
  if ( buf == nullptr )
    return 1;
  for ( i = len; i != 0; v5 %= 0xFFF1u )
  {
    v8 = i;
    if ( i >= 0x15B0 )
      v8 = 5552;
    i -= v8;
    if ( v8 >= 16 )
    {
      v9 = (unsigned int)v8 >> 4;
      v8 += -16 * ((unsigned int)v8 >> 4);
      do
      {
        v10 = *v3 + v4;
        v11 = v10 + v5;
        v12 = v3[1] + v10;
        v13 = v12 + v11;
        v14 = v3[2] + v12;
        v15 = v14 + v13;
        v16 = v3[3] + v14;
        v17 = v16 + v15;
        v18 = v3[4] + v16;
        v19 = v18 + v17;
        v20 = v3[5] + v18;
        v21 = v20 + v19;
        v22 = v3[6] + v20;
        v23 = v22 + v21;
        v24 = v3[7] + v22;
        v25 = v24 + v23;
        v26 = v3[8] + v24;
        v27 = v26 + v25;
        v28 = v3[9] + v26;
        v29 = v28 + v27;
        v30 = v3[10] + v28;
        v31 = v30 + v29;
        v32 = v3[11] + v30;
        v33 = v32 + v31;
        v34 = v3[12] + v32;
        v35 = v34 + v33;
        v36 = v3[13] + v34;
        v37 = v36 + v35;
        v38 = v3[14] + v36;
        v39 = v38 + v37;
        v4 = v3[15] + v38;
        v5 = v4 + v39;
        v3 += 16;
        --v9;
      }
      while ( v9 != 0 );
    }
    for ( ; v8 != 0; --v8 )
    {
      v4 += *v3++;
      v5 += v4;
    }
    v4 %= 0xFFF1u;
  }
  return v4 | (v5 << 16);
}

//------------------------------------------------------------------------------
// Address: 0x101F7E40
// Name: void __near * zcalloc(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl zcalloc(void *opaque, unsigned int items, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * items);
  memset(dst: v3, value: 0, count: size * items);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101F7E70
// Name: void zcfree(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl zcfree(void *opaque, void *ptr)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x101F7E90
// Name: int inflateReset(struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflateReset(z_stream_s *z)
{
  internal_state *state; // ecx

  if ( z == nullptr )
    return -2;
  state = z->state;
  if ( state == nullptr )
    return -2;
  z->total_out = 0;
  z->total_in = 0;
  z->msg = nullptr;
  state->mode = state->nowrap != 0 ? IM_BLOCKS : IM_METHOD;
  inflate_blocks_reset(s: z->state->blocks, z, c: nullptr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F7EE0
// Name: int inflateEnd(struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflateEnd(z_stream_s *z)
{
  internal_state *state; // eax
  inflate_blocks_state *blocks; // eax

  if ( z == nullptr )
    return -2;
  state = z->state;
  if ( state == nullptr || z->zfree == nullptr )
    return -2;
  blocks = state->blocks;
  if ( blocks != nullptr )
    inflate_blocks_free(s: blocks, z);
  z->zfree(a1: z->opaque, a2: z->state);
  z->state = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F7F30
// Name: int inflateInit2(struct z_stream_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflateInit2(z_stream_s *z)
{
  internal_state *v2; // eax
  inflate_blocks_state *v3; // eax

  if ( z == nullptr )
    return -2;
  z->msg = nullptr;
  if ( z->zalloc == nullptr )
  {
    z->zalloc = (void *(__cdecl *)(void *, unsigned int, unsigned int))zcalloc;
    z->opaque = nullptr;
  }
  if ( z->zfree == nullptr )
    z->zfree = zcfree;
  v2 = (internal_state *)z->zalloc(a1: z->opaque, a2: 1, a3: 24);
  z->state = v2;
  if ( v2 == nullptr )
    return -4;
  v2->blocks = nullptr;
  z->state->nowrap = 0;
  z->state->nowrap = 1;
  z->state->wbits = 15;
  v3 = inflate_blocks_new(
         z,
         c: z->state->nowrap == 0
       ? (unsigned int (__cdecl *)(unsigned int, const unsigned __int8 *, unsigned int))adler32
       : nullptr,
         w: 0x8000u);
  z->state->blocks = v3;
  if ( v3 == nullptr )
  {
    inflateEnd(z);
    return -4;
  }
  inflateReset(z);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F7FF0
// Name: struct LUFILE __near * lufopen(void __near *,unsigned int,unsigned long,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
LUFILE *__cdecl lufopen(void *z, unsigned int len, void *flags, unsigned int *err)
{
  void *v4; // edi
  LUFILE *result; // eax
  unsigned int *v6; // esi
  bool v7; // bl
  HANDLE FileA; // eax
  HANDLE v9; // eax
  LUFILE *v10; // esi
  unsigned int *v11; // edx
  HANDLE CurrentProcess; // [esp-1Ch] [ebp-20h]

  v4 = flags;
  if ( flags != (void *)1 && flags != (void *)2 && flags != (void *)3 )
  {
    *err = 0x10000;
    return nullptr;
  }
  v6 = err;
  v7 = false;
  flags = nullptr;
  *err = 0;
  if ( v4 == (void *)1 )
  {
    CurrentProcess = GetCurrentProcess();
    v9 = GetCurrentProcess();
    if ( !DuplicateHandle(
            hSourceProcessHandle: v9,
            hSourceHandle: z,
            hTargetProcessHandle: CurrentProcess,
            lpTargetHandle: &flags,
            dwDesiredAccess: 0,
            bInheritHandle: false,
            dwOptions: 2u) )
    {
      *v6 = 256;
      return nullptr;
    }
    FileA = flags;
    goto LABEL_12;
  }
  if ( v4 == (void *)2 )
  {
    FileA = CreateFileA(
              lpFileName: (LPCSTR)z,
              dwDesiredAccess: 0x80000000,
              dwShareMode: 1u,
              lpSecurityAttributes: nullptr,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: 0x80u,
              hTemplateFile: nullptr);
    flags = FileA;
    if ( FileA == (HANDLE)-1 )
    {
      *v6 = 512;
      return nullptr;
    }
LABEL_12:
    v7 = GetFileType(hFile: FileA) == 1;
  }
  result = (LUFILE *)MemAlloc_Alloc(nSize: 0x1Cu);
  v10 = result;
  if ( v4 == (void *)1 || v4 == (void *)2 )
  {
    result->is_handle = true;
    result->canseek = v7;
    result->h = flags;
    result->herr = false;
    result->initial_offset = 0;
    if ( v7 )
      result->initial_offset = SetFilePointer(
                                 hFile: flags,
                                 lDistanceToMove: 0,
                                 lpDistanceToMoveHigh: nullptr,
                                 dwMoveMethod: 1u);
    *err = 0;
    return v10;
  }
  else
  {
    result->len = len;
    v11 = err;
    result->pos = 0;
    result->initial_offset = 0;
    *(_WORD *)&result->is_handle = 256;
    result->buf = z;
    *v11 = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8120
// Name: unsigned int lufread(void __near *,unsigned int,unsigned int,struct LUFILE __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl lufread(void *ptr, unsigned int size, unsigned int n, LUFILE *stream)
{
  unsigned int v4; // ebx
  LUFILE *v5; // edi
  unsigned int v6; // esi
  unsigned int pos; // ecx
  unsigned int len; // eax

  v4 = size;
  v5 = stream;
  v6 = n * size;
  if ( stream->is_handle )
  {
    if ( !ReadFile(
            hFile: stream->h,
            lpBuffer: ptr,
            nNumberOfBytesToRead: n * size,
            lpNumberOfBytesRead: &size,
            lpOverlapped: nullptr) )
      v5->herr = true;
    return size / v4;
  }
  else
  {
    pos = stream->pos;
    len = stream->len;
    if ( pos + v6 > len )
      v6 = len - pos;
    memcpy(dst: (unsigned __int8 *)ptr, src: (unsigned __int8 *)stream->buf + pos, count: v6);
    v5->pos += v6;
    return v6 / v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F81A0
// Name: int unzlocal_getShort(struct LUFILE __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzlocal_getShort(LUFILE *fin, unsigned int *pX)
{
  int v2; // esi
  int result; // eax
  int v4; // ebx
  unsigned __int8 ptr; // [esp+Fh] [ebp-1h] BYREF

  v2 = 0;
  if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
  {
    v2 = ptr;
LABEL_3:
    result = 0;
    goto LABEL_4;
  }
  if ( !fin->is_handle || !fin->herr )
    goto LABEL_3;
  result = -1;
LABEL_4:
  v4 = v2;
  if ( result == 0 )
  {
    if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
    {
      v2 = ptr;
LABEL_7:
      *pX = v4 + (v2 << 8);
      return 0;
    }
    if ( !fin->is_handle || !fin->herr )
      goto LABEL_7;
    result = -1;
  }
  *pX = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8230
// Name: int unzlocal_getLong(struct LUFILE __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzlocal_getLong(LUFILE *fin, unsigned int *pX)
{
  int v2; // esi
  int result; // eax
  int v4; // ebx
  int v5; // ebx
  int v6; // ebx
  unsigned __int8 ptr; // [esp+Fh] [ebp-1h] BYREF

  v2 = 0;
  if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
  {
    v2 = ptr;
LABEL_3:
    result = 0;
    goto LABEL_4;
  }
  if ( !fin->is_handle || !fin->herr )
    goto LABEL_3;
  result = -1;
LABEL_4:
  v4 = v2;
  if ( result == 0 )
  {
    if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
    {
      v2 = ptr;
LABEL_7:
      result = 0;
      goto LABEL_8;
    }
    if ( !fin->is_handle || !fin->herr )
      goto LABEL_7;
    result = -1;
  }
LABEL_8:
  v5 = (v2 << 8) + v4;
  if ( result == 0 )
  {
    if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
    {
      v2 = ptr;
LABEL_11:
      result = 0;
      goto LABEL_12;
    }
    if ( !fin->is_handle || !fin->herr )
      goto LABEL_11;
    result = -1;
  }
LABEL_12:
  v6 = (v2 << 16) + v5;
  if ( result == 0 )
  {
    if ( lufread(&ptr, size: 1u, n: 1u, stream: fin) == 1 )
    {
      v2 = ptr;
LABEL_15:
      *pX = v6 + (v2 << 24);
      return 0;
    }
    if ( !fin->is_handle || !fin->herr )
      goto LABEL_15;
    result = -1;
  }
  *pX = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8350
// Name: int strcmpcasenosensitive_internal(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl strcmpcasenosensitive_internal(const char *fileName1, const char *fileName2)
{
  const char *v2; // esi
  char v3; // al
  char v4; // cl

  v2 = fileName2;
  while ( 1 )
  {
    v3 = v2[fileName1 - fileName2];
    v4 = *v2++;
    if ( (unsigned __int8)(v3 - 97) <= 0x19u )
      v3 -= 32;
    if ( (unsigned __int8)(v4 - 97) <= 0x19u )
      v4 -= 32;
    if ( v3 == 0 )
      return -(v4 != 0);
    if ( v4 == 0 )
      return 1;
    if ( v3 < v4 )
      break;
    if ( v3 > v4 )
      return 1;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101F83B0
// Name: unsigned long unzlocal_SearchCentralDir(struct LUFILE __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl unzlocal_SearchCentralDir(LUFILE *fin)
{
  DWORD pos; // ebx
  unsigned __int8 *result; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  DWORD v8; // ebx
  unsigned int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int len; // ecx
  int v13; // eax
  unsigned int uReadPos; // [esp+4h] [ebp-18h]
  unsigned int NumberOfBytesRead; // [esp+8h] [ebp-14h] BYREF
  unsigned int uPosFound; // [esp+Ch] [ebp-10h]
  unsigned __int8 *buf; // [esp+10h] [ebp-Ch]
  unsigned int uBackRead; // [esp+14h] [ebp-8h]
  unsigned int uMaxBack; // [esp+18h] [ebp-4h]
  LUFILE *fina; // [esp+24h] [ebp+8h]

  if ( fin->is_handle )
  {
    if ( !fin->canseek )
      return nullptr;
    SetFilePointer(hFile: fin->h, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 2u);
  }
  else
  {
    fin->pos = fin->len;
  }
  if ( fin->is_handle )
  {
    if ( fin->canseek )
    {
      pos = SetFilePointer(hFile: fin->h, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 1u)
          - fin->initial_offset;
      fina = (LUFILE *)pos;
    }
    else
    {
      fina = nullptr;
      pos = 0;
    }
  }
  else
  {
    fina = (LUFILE *)fin->pos;
    pos = fin->pos;
  }
  v4 = 0xFFFF;
  uMaxBack = 0xFFFF;
  if ( pos < 0xFFFF )
  {
    uMaxBack = pos;
    v4 = pos;
  }
  result = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1028);
  buf = result;
  if ( result != nullptr )
  {
    v5 = 4;
    uPosFound = 0;
    if ( v4 > 4 )
    {
      while ( 1 )
      {
        v6 = v5 + 1024;
        uBackRead = v4;
        if ( v6 <= v4 )
          uBackRead = v6;
        v7 = pos - uBackRead;
        v8 = uBackRead;
        uReadPos = v7;
        if ( uBackRead > 0x404 )
          v8 = 1028;
        if ( fin->is_handle )
        {
          if ( !fin->canseek )
            break;
          SetFilePointer(
            hFile: fin->h,
            lDistanceToMove: v7 + fin->initial_offset,
            lpDistanceToMoveHigh: nullptr,
            dwMoveMethod: 0);
        }
        else
        {
          fin->pos = v7;
        }
        v9 = v8;
        if ( fin->is_handle )
        {
          if ( !ReadFile(
                  hFile: fin->h,
                  lpBuffer: buf,
                  nNumberOfBytesToRead: v8,
                  lpNumberOfBytesRead: &NumberOfBytesRead,
                  lpOverlapped: nullptr) )
            fin->herr = true;
          v10 = NumberOfBytesRead;
        }
        else
        {
          v11 = fin->pos;
          len = fin->len;
          if ( v11 + v8 > len )
            v9 = len - v11;
          memcpy(dst: buf, src: (unsigned __int8 *)fin->buf + v11, count: v9);
          fin->pos += v9;
          v10 = v9;
        }
        if ( v10 / v8 != 1 )
          break;
        v13 = v8 - 3;
        if ( (int)(v8 - 3) > 0 )
        {
          while ( buf[--v13] != 80 || buf[v13 + 1] != 75 || buf[v13 + 2] != 5 || buf[v13 + 3] != 6 )
          {
            if ( v13 <= 0 )
              goto LABEL_41;
          }
          uPosFound = uReadPos + v13;
          if ( uReadPos + v13 != 0 )
            break;
        }
LABEL_41:
        if ( uBackRead >= uMaxBack )
          break;
        v4 = uMaxBack;
        v5 = uBackRead;
        pos = (DWORD)fina;
      }
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf);
    return (unsigned __int8 *)uPosFound;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8590
// Name: int unzlocal_GetCurrentFileInfoInternal(struct unz_s __near *,struct unz_file_info_s __near *,struct unz_file_info_internal_s __near *,char __near *,unsigned long,void __near *,unsigned long,char __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzlocal_GetCurrentFileInfoInternal(
        unz_s *file,
        unz_file_info_s *pfile_info,
        unz_file_info_internal_s *pfile_info_internal,
        char *szFileName,
        unsigned int fileNameBufferSize,
        void *extraField,
        unsigned int extraFieldBufferSize,
        char *szComment,
        unsigned int commentBufferSize)
{
  LUFILE *v10; // eax
  unsigned int v11; // ecx
  LONG size_filename; // esi
  unsigned int v13; // edi
  unsigned int size_file_extra; // edi
  unsigned int v15; // ecx
  unsigned int v16; // ebx
  LUFILE *v17; // eax
  LONG v18; // esi
  char *v19; // ecx
  unsigned int size_file_comment; // edi
  unsigned int v21; // edx
  unsigned int v22; // ebx
  LUFILE *v23; // eax
  LUFILE *v24; // [esp-10h] [ebp-6Ch]
  unz_file_info_s file_info; // [esp+4h] [ebp-58h] BYREF
  unsigned int uMagic; // [esp+54h] [ebp-8h] BYREF
  int err; // [esp+58h] [ebp-4h]

  err = 0;
  if ( file == nullptr )
    return -102;
  v10 = file->file;
  v11 = file->byte_before_the_zipfile + file->pos_in_central_dir;
  if ( !file->file->is_handle )
  {
    v10->pos = v11;
LABEL_6:
    if ( unzlocal_getLong(fin: file->file, pX: &uMagic) != 0 )
    {
      err = -1;
    }
    else if ( uMagic != 33639248 )
    {
      err = -103;
    }
    goto LABEL_12;
  }
  if ( v10->canseek )
  {
    SetFilePointer(
      hFile: v10->h,
      lDistanceToMove: v11 + v10->initial_offset,
      lpDistanceToMoveHigh: nullptr,
      dwMoveMethod: 0);
    goto LABEL_6;
  }
  err = -1;
LABEL_12:
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.version) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.version_needed) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.flag) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.compression_method) != 0 )
    err = -1;
  if ( unzlocal_getLong(fin: file->file, pX: &file_info.dosDate) != 0 )
    err = -1;
  file_info.tmu_date.tm_mday = BYTE2(file_info.dosDate) & 0x1F;
  file_info.tmu_date.tm_year = (file_info.dosDate >> 25) + 1980;
  file_info.tmu_date.tm_mon = ((file_info.dosDate >> 21) & 0xF) - 1;
  file_info.tmu_date.tm_hour = LOWORD(file_info.dosDate) >> 11;
  file_info.tmu_date.tm_sec = 2 * (file_info.dosDate & 0x1F);
  v24 = file->file;
  file_info.tmu_date.tm_min = (file_info.dosDate >> 5) & 0x3F;
  if ( unzlocal_getLong(fin: v24, pX: &file_info.crc) != 0 )
    err = -1;
  if ( unzlocal_getLong(fin: file->file, pX: &file_info.compressed_size) != 0 )
    err = -1;
  if ( unzlocal_getLong(fin: file->file, pX: &file_info.uncompressed_size) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.size_filename) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.size_file_extra) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.size_file_comment) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.disk_num_start) != 0 )
    err = -1;
  if ( unzlocal_getShort(fin: file->file, pX: &file_info.internal_fa) != 0 )
    err = -1;
  if ( unzlocal_getLong(fin: file->file, pX: &file_info.external_fa) != 0 )
    err = -1;
  if ( unzlocal_getLong(fin: file->file, pX: &uMagic) != 0 )
    err = -1;
  size_filename = file_info.size_filename;
  if ( err != 0 )
    goto LABEL_66;
  if ( szFileName != nullptr )
  {
    if ( file_info.size_filename >= fileNameBufferSize )
    {
      v13 = fileNameBufferSize;
    }
    else
    {
      szFileName[file_info.size_filename] = 0;
      v13 = size_filename;
    }
    if ( size_filename != 0
      && fileNameBufferSize != 0
      && lufread(ptr: szFileName, size: v13, n: 1u, stream: file->file) != 1 )
    {
      err = -1;
    }
    size_filename -= v13;
    if ( err != 0 )
      goto LABEL_66;
  }
  if ( extraField == nullptr )
  {
LABEL_66:
    v18 = file_info.size_file_extra + size_filename;
  }
  else
  {
    size_file_extra = file_info.size_file_extra;
    v15 = extraFieldBufferSize;
    v16 = file_info.size_file_extra;
    if ( file_info.size_file_extra >= extraFieldBufferSize )
      v16 = extraFieldBufferSize;
    if ( size_filename != 0 )
    {
      v17 = file->file;
      if ( file->file->is_handle )
      {
        if ( v17->canseek )
        {
          SetFilePointer(hFile: v17->h, lDistanceToMove: size_filename, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 1u);
          v15 = extraFieldBufferSize;
          size_filename = 0;
        }
        else
        {
          err = -1;
        }
      }
      else
      {
        v17->pos += size_filename;
        size_filename = 0;
      }
    }
    if ( size_file_extra != 0 && v15 != 0 && lufread(ptr: extraField, size: v16, n: 1u, stream: file->file) != 1 )
      err = -1;
    v18 = size_file_extra - v16 + size_filename;
  }
  if ( err == 0 )
  {
    v19 = szComment;
    if ( szComment == nullptr )
      goto LABEL_83;
    size_file_comment = file_info.size_file_comment;
    v21 = commentBufferSize;
    if ( file_info.size_file_comment >= commentBufferSize )
    {
      v22 = commentBufferSize;
    }
    else
    {
      szComment[file_info.size_file_comment] = 0;
      v22 = size_file_comment;
    }
    if ( v18 != 0 )
    {
      v23 = file->file;
      if ( file->file->is_handle )
      {
        if ( v23->canseek )
        {
          SetFilePointer(hFile: v23->h, lDistanceToMove: v18, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 1u);
          v21 = commentBufferSize;
          v19 = szComment;
        }
        else
        {
          err = -1;
        }
      }
      else
      {
        v23->pos += v18;
      }
    }
    if ( size_file_comment != 0 && v21 != 0 && lufread(ptr: v19, size: v22, n: 1u, stream: file->file) != 1 )
    {
      err = -1;
      return -1;
    }
    if ( err == 0 )
    {
LABEL_83:
      if ( pfile_info != nullptr )
        *pfile_info = file_info;
      if ( pfile_info_internal != nullptr )
        pfile_info_internal->offset_curfile = uMagic;
    }
  }
  return err;
}

//------------------------------------------------------------------------------
// Address: 0x101F8930
// Name: int unzGoToFirstFile(struct unz_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzGoToFirstFile(unz_s *file)
{
  int result; // eax

  if ( file == nullptr )
    return -102;
  file->pos_in_central_dir = file->offset_central_dir;
  file->num_file = 0;
  result = unzlocal_GetCurrentFileInfoInternal(
             file,
             pfile_info: &file->cur_file_info,
             pfile_info_internal: &file->cur_file_info_internal,
             szFileName: nullptr,
             fileNameBufferSize: 0,
             extraField: nullptr,
             extraFieldBufferSize: 0,
             szComment: nullptr,
             commentBufferSize: 0);
  file->current_file_ok = result == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8980
// Name: int unzGoToNextFile(struct unz_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzGoToNextFile(unz_s *file)
{
  int result; // eax
  unsigned int v2; // eax

  if ( file == nullptr )
    return -102;
  if ( file->current_file_ok == 0 )
    return -100;
  v2 = file->num_file + 1;
  if ( v2 == file->gi.number_entry )
    return -100;
  file->pos_in_central_dir += file->cur_file_info.size_file_extra
                            + file->cur_file_info.size_file_comment
                            + file->cur_file_info.size_filename
                            + 46;
  file->num_file = v2;
  result = unzlocal_GetCurrentFileInfoInternal(
             file,
             pfile_info: &file->cur_file_info,
             pfile_info_internal: &file->cur_file_info_internal,
             szFileName: nullptr,
             fileNameBufferSize: 0,
             extraField: nullptr,
             extraFieldBufferSize: 0,
             szComment: nullptr,
             commentBufferSize: 0);
  file->current_file_ok = result == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F89F0
// Name: int unzLocateFile(struct unz_s __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzLocateFile(unz_s *file, const char *szFileName, int iCaseSensitivity)
{
  int result; // eax
  const char *v5; // eax
  char v6; // cl
  unsigned int num_file; // ebx
  int v8; // eax
  char szFileNameA[260]; // [esp+4h] [ebp-208h] BYREF
  char szCurrentFileName[260]; // [esp+108h] [ebp-104h] BYREF
  unsigned int pos_in_central_dirSaved; // [esp+214h] [ebp+8h]

  if ( file == nullptr )
    return -102;
  v5 = szFileName;
  if ( strlen(szFileName) >= 0x100 )
    return -102;
  do
  {
    v6 = *v5;
    v5[szFileNameA - szFileName] = *v5;
    ++v5;
  }
  while ( v6 != 0 );
  if ( file->current_file_ok == 0 )
    return -100;
  num_file = file->num_file;
  pos_in_central_dirSaved = file->pos_in_central_dir;
  result = unzGoToFirstFile(file);
  if ( result != 0 )
  {
LABEL_14:
    file->num_file = num_file;
    file->pos_in_central_dir = pos_in_central_dirSaved;
  }
  else
  {
    while ( 1 )
    {
      unzlocal_GetCurrentFileInfoInternal(
        file,
        pfile_info: nullptr,
        pfile_info_internal: nullptr,
        szFileName: szCurrentFileName,
        fileNameBufferSize: 0x100u,
        extraField: nullptr,
        extraFieldBufferSize: 0,
        szComment: nullptr,
        commentBufferSize: 0);
      v8 = iCaseSensitivity == 1
         ? strcmp(szCurrentFileName, szFileNameA)
         : strcmpcasenosensitive_internal(fileName1: szCurrentFileName, fileName2: szFileNameA);
      if ( v8 == 0 )
        return 0;
      result = unzGoToNextFile(file);
      if ( result != 0 )
        goto LABEL_14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8B10
// Name: int unzlocal_CheckCurrentFileCoherencyHeader(struct unz_s __near *,unsigned int __near *,unsigned long __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzlocal_CheckCurrentFileCoherencyHeader(
        unz_s *s,
        unsigned int *piSizeVar,
        unsigned int *poffset_local_extrafield,
        unsigned int *psize_local_extrafield)
{
  LUFILE *file; // ecx
  unsigned int v5; // eax
  int v6; // esi
  unsigned int compression_method; // eax
  int Long; // eax
  char v10; // bl
  int Short; // eax
  unsigned int v12; // ebx
  unsigned int v13; // eax
  unsigned int size_extra_field; // [esp+Ch] [ebp-14h] BYREF
  unsigned int size_filename; // [esp+10h] [ebp-10h] BYREF
  unsigned int uFlags; // [esp+14h] [ebp-Ch] BYREF
  unsigned int uMagic; // [esp+18h] [ebp-8h] BYREF
  unsigned int uData; // [esp+1Ch] [ebp-4h] BYREF

  *piSizeVar = 0;
  *poffset_local_extrafield = 0;
  *psize_local_extrafield = 0;
  file = s->file;
  v5 = s->cur_file_info_internal.offset_curfile + s->byte_before_the_zipfile;
  v6 = 0;
  uMagic = 0;
  uData = 0;
  uFlags = 0;
  size_filename = 0;
  size_extra_field = 0;
  if ( file->is_handle )
  {
    if ( !file->canseek )
      return -1;
    SetFilePointer(
      hFile: file->h,
      lDistanceToMove: v5 + file->initial_offset,
      lpDistanceToMoveHigh: nullptr,
      dwMoveMethod: 0);
  }
  else
  {
    file->pos = v5;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &uMagic) != 0 )
  {
    v6 = -1;
  }
  else if ( uMagic != 67324752 )
  {
    v6 = -103;
  }
  if ( unzlocal_getShort(fin: s->file, pX: &uData) != 0 )
    v6 = -1;
  if ( unzlocal_getShort(fin: s->file, pX: &uFlags) != 0 )
    v6 = -1;
  if ( unzlocal_getShort(fin: s->file, pX: &uData) != 0 )
  {
    v6 = -1;
  }
  else if ( v6 == 0 )
  {
    compression_method = s->cur_file_info.compression_method;
    if ( uData != compression_method || compression_method != 0 && compression_method != 8 )
      v6 = -103;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &uData) != 0 )
    v6 = -1;
  Long = unzlocal_getLong(fin: s->file, pX: &uData);
  v10 = uFlags;
  if ( Long != 0 )
  {
    v6 = -1;
  }
  else if ( v6 == 0 && uData != s->cur_file_info.crc && (uFlags & 8) == 0 )
  {
    v6 = -103;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &uData) != 0 )
  {
    v6 = -1;
  }
  else if ( v6 == 0 && uData != s->cur_file_info.compressed_size && (v10 & 8) == 0 )
  {
    v6 = -103;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &uData) != 0 )
  {
    v6 = -1;
  }
  else if ( v6 == 0 && uData != s->cur_file_info.uncompressed_size && (v10 & 8) == 0 )
  {
    v6 = -103;
  }
  Short = unzlocal_getShort(fin: s->file, pX: &size_filename);
  v12 = size_filename;
  if ( Short != 0 )
  {
    v6 = -1;
  }
  else if ( v6 == 0 && size_filename != s->cur_file_info.size_filename )
  {
    v6 = -103;
  }
  *piSizeVar += size_filename;
  if ( unzlocal_getShort(fin: s->file, pX: &size_extra_field) != 0 )
    v6 = -1;
  v13 = size_extra_field;
  *poffset_local_extrafield = s->cur_file_info_internal.offset_curfile + v12 + 30;
  *psize_local_extrafield = v13;
  *piSizeVar += v13;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101F8D00
// Name: int unzCloseCurrentFile(struct unz_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzCloseCurrentFile(unz_s *file)
{
  file_in_zip_read_info_s *pfile_in_zip_read; // esi
  bool v3; // zf
  int err; // [esp+4h] [ebp-4h]

  err = 0;
  if ( file == nullptr )
    return -102;
  pfile_in_zip_read = file->pfile_in_zip_read;
  if ( pfile_in_zip_read == nullptr )
    return -102;
  if ( pfile_in_zip_read->rest_read_uncompressed == 0 && pfile_in_zip_read->crc32 != pfile_in_zip_read->crc32_wait )
    err = -105;
  if ( pfile_in_zip_read->read_buffer != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pfile_in_zip_read->read_buffer);
    pfile_in_zip_read->read_buffer = nullptr;
  }
  v3 = pfile_in_zip_read->stream_initialised == 0;
  pfile_in_zip_read->read_buffer = nullptr;
  if ( !v3 )
    inflateEnd(z: &pfile_in_zip_read->stream);
  pfile_in_zip_read->stream_initialised = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pfile_in_zip_read);
  file->pfile_in_zip_read = nullptr;
  return err;
}

//------------------------------------------------------------------------------
// Address: 0x101F8DA0
// Name: struct _FILETIME timet2filetime(__int64)
// Source: json
//------------------------------------------------------------------------------
_FILETIME __cdecl timet2filetime(__int64 timer)
{
  unsigned __int16 *v1; // eax
  _SYSTEMTIME st; // [esp+0h] [ebp-18h] BYREF
  _FILETIME ft; // [esp+10h] [ebp-8h] BYREF

  v1 = (unsigned __int16 *)_gmtime64(timp: &timer);
  st.wYear = v1[10] + 1900;
  st.wMonth = v1[8] + 1;
  st.wDay = v1[6];
  st.wHour = v1[4];
  st.wMinute = v1[2];
  st.wSecond = *v1;
  st.wMilliseconds = 0;
  SystemTimeToFileTime(lpSystemTime: &st, lpFileTime: &ft);
  return ft;
}

//------------------------------------------------------------------------------
// Address: 0x101F8E10
// Name: public: unsigned long TUnzip::Get(int,struct ZIPENTRY __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TUnzip::Get(TUnzip *this, int index, ZIPENTRY *ze)
{
  ZIPENTRY *v5; // eax
  LUFILE *file; // eax
  unsigned int v7; // esi
  char *v8; // eax
  TUnzip *v9; // edi
  char *v10; // ebx
  ZIPENTRY *v11; // esi
  char *v12; // eax
  char v13; // cl
  char external_fa; // al
  unsigned int v15; // edx
  char v16; // cl
  unsigned int uncompressed_size; // ecx
  unsigned int dwLowDateTime; // eax
  unsigned int dwHighDateTime; // ecx
  int v20; // edi
  bool v21; // cc
  char v22; // cl
  int v23; // eax
  bool v24; // dl
  int v25; // edi
  TUnzip *v26; // eax
  unsigned int dosDate_high; // [esp-Ch] [ebp-188h]
  WORD dosDate; // [esp-8h] [ebp-184h]
  __int64 v29; // [esp-8h] [ebp-184h]
  __int64 v30; // [esp-8h] [ebp-184h]
  char fn[260]; // [esp+Ch] [ebp-170h] BYREF
  unz_file_info_s ufi; // [esp+110h] [ebp-6Ch] BYREF
  unsigned int iSizeVar; // [esp+160h] [ebp-1Ch] BYREF
  _FILETIME ft; // [esp+164h] [ebp-18h] BYREF
  TUnzip *v35; // [esp+16Ch] [ebp-10h]
  unsigned int offset; // [esp+170h] [ebp-Ch] BYREF
  unsigned int extralen; // [esp+174h] [ebp-8h] BYREF
  bool whidden; // [esp+179h] [ebp-3h]
  bool uwriteable; // [esp+17Ah] [ebp-2h]
  bool hasctime; // [esp+17Bh] [ebp-1h]

  v35 = this;
  if ( index < -1 || index >= (signed int)this->uf->gi.number_entry )
    return 0x10000;
  if ( this->currentfile != -1 )
    unzCloseCurrentFile(file: this->uf);
  this->currentfile = -1;
  if ( index == this->czei )
  {
    if ( index != -1 )
    {
      *ze = this->cze;
      return 0;
    }
  }
  else if ( index != -1 )
  {
    if ( index < (signed int)this->uf->num_file )
      unzGoToFirstFile(file: this->uf);
    while ( (signed int)this->uf->num_file < index )
      unzGoToNextFile(file: this->uf);
    unzlocal_GetCurrentFileInfoInternal(
      file: this->uf,
      pfile_info: &ufi,
      pfile_info_internal: nullptr,
      szFileName: fn,
      fileNameBufferSize: 0x104u,
      extraField: nullptr,
      extraFieldBufferSize: 0,
      szComment: nullptr,
      commentBufferSize: 0);
    if ( unzlocal_CheckCurrentFileCoherencyHeader(
           s: this->uf,
           piSizeVar: &iSizeVar,
           poffset_local_extrafield: &offset,
           psize_local_extrafield: &extralen) != 0 )
      return 1792;
    file = this->uf->file;
    if ( file->is_handle )
    {
      if ( !file->canseek )
        return 2048;
      SetFilePointer(
        hFile: file->h,
        lDistanceToMove: offset + file->initial_offset,
        lpDistanceToMoveHigh: nullptr,
        dwMoveMethod: 0);
    }
    else
    {
      file->pos = offset;
    }
    v7 = extralen;
    v8 = (char *)MemAlloc_Alloc(nSize: extralen);
    v9 = v35;
    v10 = v8;
    if ( lufread(ptr: v8, size: 1u, n: v7, stream: v35->uf->file) != v7 )
    {
      free(pMem: v10);
      return 2048;
    }
    v11 = ze;
    ze->index = v9->uf->num_file;
    v12 = fn;
    do
    {
      v13 = *v12;
      v12[(char *)v11 - fn + 4] = *v12;
      ++v12;
    }
    while ( v13 != 0 );
    external_fa = ufi.external_fa;
    whidden = (ufi.external_fa & 2) != 0;
    hasctime = (ufi.external_fa & 4) != 0;
    HIBYTE(ze) = (ufi.external_fa & 0x20) != 0;
    uwriteable = (ufi.external_fa & 0x800000) != 0;
    v15 = ufi.external_fa >> 30;
    v16 = ufi.external_fa & 1;
    v11->attr = 128;
    if ( (v15 & 1) != 0 || (external_fa & 0x10) != 0 )
      v11->attr = 144;
    if ( HIBYTE(ze) != 0 )
      v11->attr |= 0x20u;
    if ( whidden )
      v11->attr |= 2u;
    if ( !uwriteable || v16 != 0 )
      v11->attr |= 1u;
    if ( hasctime )
      v11->attr |= 4u;
    uncompressed_size = ufi.uncompressed_size;
    v11->comp_size = ufi.compressed_size;
    dosDate = ufi.dosDate;
    dosDate_high = HIWORD(ufi.dosDate);
    v11->unc_size = uncompressed_size;
    DosDateTimeToFileTime(wFatDate: dosDate_high, wFatTime: dosDate, lpFileTime: &ft);
    dwLowDateTime = ft.dwLowDateTime;
    dwHighDateTime = ft.dwHighDateTime;
    v20 = 0;
    v21 = extralen <= 4;
    v11->atime = ft;
    v11->ctime.dwLowDateTime = dwLowDateTime;
    v11->ctime.dwHighDateTime = dwHighDateTime;
    v11->mtime.dwLowDateTime = dwLowDateTime;
    v11->mtime.dwHighDateTime = dwHighDateTime;
    if ( !v21 )
    {
      BYTE2(ze) = 0;
      while ( 1 )
      {
        v22 = v10[v20 + 1];
        LOBYTE(ze) = v10[v20];
        BYTE1(ze) = v22;
        if ( strcmp((const char *)&ze, "UT") == 0 )
          break;
        v20 += v10[v20 + 2] + 4;
        if ( v20 + 4 >= extralen )
          goto LABEL_48;
      }
      v23 = (unsigned __int8)v10[v20 + 4];
      v24 = (v10[v20 + 4] & 4) != 0;
      v25 = v20 + 5;
      HIBYTE(ze) = (v23 & 2) != 0;
      hasctime = v24;
      if ( (v23 & 1) != 0 )
      {
        v29 = *(_QWORD *)&v10[v25];
        v25 += 4;
        v11->mtime = timet2filetime(timer: v29);
      }
      if ( HIBYTE(ze) != 0 )
      {
        v30 = *(_QWORD *)&v10[v25];
        v25 += 4;
        v11->atime = timet2filetime(timer: v30);
      }
      if ( hasctime )
        v11->ctime = timet2filetime(timer: *(_QWORD *)&v10[v25]);
    }
LABEL_48:
    if ( v10 != nullptr )
      free(pMem: v10);
    v26 = v35;
    qmemcpy(&v35->cze, v11, sizeof(v35->cze));
    v26->czei = index;
    return 0;
  }
  v5 = ze;
  ze->index = this->uf->gi.number_entry;
  v5->name[0] = 0;
  v5->attr = 0;
  v5->atime.dwLowDateTime = 0;
  v5->atime.dwHighDateTime = 0;
  v5->ctime.dwLowDateTime = 0;
  v5->ctime.dwHighDateTime = 0;
  v5->mtime.dwLowDateTime = 0;
  v5->mtime.dwHighDateTime = 0;
  v5->comp_size = 0;
  v5->unc_size = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F91E0
// Name: public: unsigned long TUnzip::Find(char const __near *,bool,int __near *,struct ZIPENTRY __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TUnzip::Find(TUnzip *this, const char *name, bool ic, int *index, ZIPENTRY *ze)
{
  unsigned int result; // eax
  unz_s *uf; // ecx
  int num_file; // eax

  if ( unzLocateFile(file: this->uf, szFileName: name, iCaseSensitivity: ic + 1) != 0 )
  {
    if ( index != nullptr )
      *index = -1;
    if ( ze != nullptr )
    {
      memset(dst: (unsigned __int8 *)ze, value: 0, count: sizeof(ZIPENTRY));
      ze->index = -1;
    }
    return 1280;
  }
  else
  {
    if ( this->currentfile != -1 )
      unzCloseCurrentFile(file: this->uf);
    uf = this->uf;
    this->currentfile = -1;
    num_file = uf->num_file;
    if ( index != nullptr )
      *index = num_file;
    if ( ze == nullptr )
      return 0;
    result = TUnzip::Get(this, index: num_file, ze);
    if ( result == 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F9280
// Name: void EnsureDirectory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnsureDirectory(const char *rootdir, const char *dir)
{
  unsigned int v2; // eax
  char *v3; // edi
  char v4; // cl
  unsigned int v5; // esi
  char v6; // al
  char v7; // [esp-1h] [ebp-105h] BYREF
  char cd[260]; // [esp+0h] [ebp-104h] BYREF

  if ( dir != nullptr && *dir != 0 )
  {
    strcpy(cd, rootdir);
    v2 = strlen(dir) + 1;
    v3 = &v7;
    do
      v4 = *++v3;
    while ( v4 != 0 );
    qmemcpy(v3, dir, v2);
    v5 = 0;
    if ( &cd[strlen(cd) + 1] != &cd[1] )
    {
      do
      {
        v6 = cd[v5];
        if ( v6 == 47 || v6 == 92 )
        {
          cd[v5] = 0;
          CreateDirectoryA(lpPathName: cd, lpSecurityAttributes: nullptr);
          cd[v5] = 92;
        }
        ++v5;
      }
      while ( v5 < strlen(cd) );
    }
    CreateDirectoryA(lpPathName: cd, lpSecurityAttributes: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9360
// Name: unsigned long FindZipItemA(struct HZIP__ __near *,char const __near *,bool,int __near *,struct ZIPENTRY __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl FindZipItemA(TUnzip **hz, const char *name, bool ic, int *index, ZIPENTRY *ze)
{
  unsigned int result; // eax

  if ( hz != nullptr )
  {
    if ( *hz == (TUnzip *)1 )
    {
      result = TUnzip::Find(this: hz[1], name, ic, index, ze);
      lasterrorU = result;
    }
    else
    {
      lasterrorU = 0x80000;
      return 0x80000;
    }
  }
  else
  {
    lasterrorU = 0x10000;
    return 0x10000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F93B0
// Name: int inflate_codes(struct inflate_blocks_state __near *,struct z_stream_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_codes(inflate_blocks_state *s, z_stream_s *z, int r)
{
  inflate_codes_state *codes; // ecx
  unsigned int bitk; // ebx
  unsigned int avail_in; // edx
  unsigned __int8 *write; // edx
  unsigned __int8 *read; // eax
  unsigned __int8 *v10; // eax
  __int32 mode; // ecx
  int v12; // ecx
  int v13; // eax
  unsigned __int8 *v14; // ecx
  unsigned __int8 *v15; // ecx
  unsigned int need; // eax
  int v17; // eax
  const inflate_huft_s *v18; // eax
  const inflate_huft_s *v19; // ecx
  unsigned int Exop; // eax
  const inflate_huft_s *tree; // eax
  int v22; // eax
  unsigned int v23; // ecx
  inflate_codes_state *v24; // eax
  unsigned int v25; // eax
  int v26; // eax
  const inflate_huft_s *v27; // eax
  int Bits; // ecx
  const inflate_huft_s *v29; // eax
  int v30; // eax
  unsigned int v31; // eax
  inflate_codes_state *v32; // ecx
  unsigned __int8 *v33; // eax
  unsigned __int8 *v34; // ecx
  int v35; // eax
  unsigned __int8 *v36; // eax
  unsigned __int8 *window; // ecx
  unsigned __int8 *v38; // eax
  unsigned __int8 *v39; // eax
  unsigned __int8 *v40; // ecx
  int v41; // eax
  unsigned __int8 *v42; // eax
  unsigned __int8 *v43; // ecx
  unsigned __int8 *v44; // eax
  int v46; // ecx
  int v47; // eax
  int v48; // [esp-4h] [ebp-28h]
  unsigned __int8 *f; // [esp+10h] [ebp-14h]
  const inflate_huft_s *t; // [esp+14h] [ebp-10h]
  const inflate_huft_s *ta; // [esp+14h] [ebp-10h]
  const inflate_huft_s *tb; // [esp+14h] [ebp-10h]
  const inflate_huft_s *tc; // [esp+14h] [ebp-10h]
  const inflate_huft_s *td; // [esp+14h] [ebp-10h]
  unsigned int m; // [esp+18h] [ebp-Ch]
  unsigned int ma; // [esp+18h] [ebp-Ch]
  unsigned int mb; // [esp+18h] [ebp-Ch]
  unsigned int n; // [esp+1Ch] [ebp-8h]
  inflate_codes_state *c; // [esp+20h] [ebp-4h]
  unsigned int b; // [esp+2Ch] [ebp+8h]
  unsigned __int8 *p; // [esp+30h] [ebp+Ch]

  codes = s->sub.decode.codes;
  bitk = s->bitk;
  avail_in = z->avail_in;
  p = z->next_in;
  n = avail_in;
  write = s->write;
  b = s->bitb;
  read = s->read;
  c = codes;
  if ( write >= read )
    v10 = (unsigned __int8 *)(s->end - write);
  else
    v10 = (unsigned __int8 *)(read - write - 1);
  mode = codes->mode;
  m = (unsigned int)v10;
  while ( 2 )
  {
    switch ( mode )
    {
      case 0:
        if ( (unsigned int)v10 >= 0x102 && n >= 0xA )
        {
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = n;
          v12 = p - z->next_in;
          z->next_in = p;
          z->total_in += v12;
          s->write = write;
          v13 = inflate_fast(bl: c->lbits, bd: c->dbits, tl: c->ltree, td: c->dtree, s, z);
          bitk = s->bitk;
          p = z->next_in;
          n = z->avail_in;
          write = s->write;
          b = s->bitb;
          v14 = s->read;
          r = v13;
          v15 = (unsigned __int8 *)(write >= v14 ? s->end - write : v14 - write - 1);
          m = (unsigned int)v15;
          if ( v13 != 0 )
          {
            c->mode = 2 * (v13 != 1) + 7;
            v10 = v15;
            goto LABEL_85;
          }
        }
        c->sub.code.need = c->lbits;
        c->sub.lit = (unsigned int)c->ltree;
        c->mode = LEN;
        goto $LN111_1;
      case 1:
$LN111_1:
        need = c->sub.code.need;
        t = (const inflate_huft_s *)need;
        if ( bitk < need )
        {
          do
          {
            if ( n == 0 )
              goto LABEL_89;
            --n;
            v17 = *p++ << bitk;
            bitk += 8;
            b |= v17;
            need = (unsigned int)t;
            r = 0;
          }
          while ( bitk < (unsigned int)t );
        }
        v18 = (const inflate_huft_s *)(c->sub.lit + 8 * (b & inflate_mask[need]));
        b >>= v18->word.what.Bits;
        v19 = v18;
        ta = v18;
        bitk -= v18->word.what.Bits;
        Exop = v18->word.what.Exop;
        if ( Exop == 0 )
        {
          c->sub.lit = v19->base;
          c->mode = LIT;
          v10 = (unsigned __int8 *)m;
          goto LABEL_85;
        }
        if ( (Exop & 0x10) != 0 )
        {
          c->sub.lit = Exop & 0xF;
          c->len = ta->base;
          v10 = (unsigned __int8 *)m;
          c->mode = LENEXT;
          goto LABEL_85;
        }
        if ( (Exop & 0x40) == 0 )
          goto LABEL_22;
        if ( (Exop & 0x20) == 0 )
        {
          c->mode = BADCODE;
          z->msg = "invalid literal/length code";
          goto LABEL_92;
        }
        c->mode = WASH;
        v10 = (unsigned __int8 *)m;
        goto LABEL_85;
      case 2:
        tree = c->sub.code.tree;
        for ( tb = tree; bitk < (unsigned int)tb; r = 0 )
        {
          if ( n == 0 )
            goto LABEL_89;
          --n;
          v22 = *p++ << bitk;
          bitk += 8;
          b |= v22;
          tree = tb;
        }
        v23 = b & inflate_mask[(_DWORD)tree];
        v24 = c;
        c->len += v23;
        b >>= (char)tb;
        bitk -= (unsigned int)tb;
        c->sub.code.need = c->dbits;
        c->sub.lit = (unsigned int)c->dtree;
        c->mode = DIST;
LABEL_30:
        v25 = v24->sub.code.need;
        tc = (const inflate_huft_s *)v25;
        if ( bitk >= v25 )
        {
LABEL_33:
          v27 = (const inflate_huft_s *)(c->sub.lit + 8 * (b & inflate_mask[v25]));
          b >>= v27->word.what.Bits;
          Bits = v27->word.what.Bits;
          ta = v27;
          Exop = v27->word.what.Exop;
          bitk -= Bits;
          if ( (Exop & 0x10) != 0 )
          {
            c->sub.lit = Exop & 0xF;
            c->sub.code.need = ta->base;
            v10 = (unsigned __int8 *)m;
            c->mode = DISTEXT;
            goto LABEL_85;
          }
          if ( (Exop & 0x40) != 0 )
          {
            c->mode = BADCODE;
            z->msg = "invalid distance code";
LABEL_92:
            s->bitb = b;
            s->bitk = bitk;
            z->avail_in = n;
            v48 = -3;
LABEL_88:
            z->total_in += p - z->next_in;
            z->next_in = p;
            s->write = write;
            return inflate_flush(s, z, r: v48);
          }
LABEL_22:
          c->sub.code.need = Exop;
          c->sub.lit = (unsigned int)&ta[ta->base];
          v10 = (unsigned __int8 *)m;
LABEL_85:
          mode = c->mode;
          if ( c->mode > (unsigned int)BADCODE )
          {
LABEL_86:
            v48 = -2;
LABEL_87:
            s->bitb = b;
            s->bitk = bitk;
            z->avail_in = n;
            goto LABEL_88;
          }
          continue;
        }
        while ( n != 0 )
        {
          --n;
          v26 = *p++ << bitk;
          bitk += 8;
          b |= v26;
          v25 = (unsigned int)tc;
          r = 0;
          if ( bitk >= (unsigned int)tc )
            goto LABEL_33;
        }
LABEL_89:
        s->bitb = b;
        s->bitk = bitk;
        z->avail_in = 0;
LABEL_90:
        v46 = p - z->next_in;
        z->next_in = p;
        z->total_in += v46;
        s->write = write;
        return inflate_flush(s, z, r);
      case 3:
        v24 = c;
        goto LABEL_30;
      case 4:
        v29 = c->sub.code.tree;
        for ( td = v29; bitk < (unsigned int)td; r = 0 )
        {
          if ( n == 0 )
            goto LABEL_89;
          --n;
          v30 = *p++ << bitk;
          bitk += 8;
          b |= v30;
          v29 = td;
        }
        c->sub.code.need += b & inflate_mask[(_DWORD)v29];
        b >>= (char)td;
        bitk -= (unsigned int)td;
        c->mode = COPY;
$LN101_0:
        v31 = c->sub.code.need;
        if ( write - s->window >= v31 )
          f = &write[-v31];
        else
          f = &write[s->end - s->window - c->sub.code.need];
        v32 = c;
        v10 = (unsigned __int8 *)m;
        if ( c->len != 0 )
        {
          while ( 1 )
          {
            if ( v10 == nullptr )
            {
              if ( write != s->end
                || (v33 = s->read, v34 = s->window, v33 == v34)
                || ((write = s->window, v34 >= v33)
                  ? (v10 = (unsigned __int8 *)(s->end - v34))
                  : (v10 = (unsigned __int8 *)(v33 - v34 - 1)),
                    v10 == nullptr) )
              {
                s->write = write;
                v35 = inflate_flush(s, z, r);
                write = s->write;
                r = v35;
                v36 = s->read;
                if ( write >= v36 )
                  v10 = (unsigned __int8 *)(s->end - write);
                else
                  v10 = (unsigned __int8 *)(v36 - write - 1);
                ma = (unsigned int)v10;
                if ( write == s->end )
                {
                  window = s->window;
                  v38 = s->read;
                  if ( v38 == window )
                  {
                    v10 = (unsigned __int8 *)ma;
                  }
                  else
                  {
                    write = s->window;
                    if ( window >= v38 )
                      v10 = (unsigned __int8 *)(s->end - window);
                    else
                      v10 = (unsigned __int8 *)(v38 - window - 1);
                  }
                }
                if ( v10 == nullptr )
                  break;
              }
            }
            *write = *f;
            --v10;
            ++write;
            r = 0;
            ++f;
            m = (unsigned int)v10;
            if ( f == s->end )
              f = s->window;
            v32 = c;
            if ( --c->len == 0 )
              goto LABEL_84;
          }
LABEL_93:
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = n;
          goto LABEL_90;
        }
LABEL_84:
        v32->mode = START;
        goto LABEL_85;
      case 5:
        goto $LN101_0;
      case 6:
        if ( v10 == nullptr )
        {
          if ( write != s->end
            || (v39 = s->read, v40 = s->window, v39 == v40)
            || ((write = s->window, v40 >= v39)
              ? (v10 = (unsigned __int8 *)(s->end - v40))
              : (v10 = (unsigned __int8 *)(v39 - v40 - 1)),
                v10 == nullptr) )
          {
            s->write = write;
            v41 = inflate_flush(s, z, r);
            write = s->write;
            r = v41;
            v42 = s->read;
            if ( write >= v42 )
              v10 = (unsigned __int8 *)(s->end - write);
            else
              v10 = (unsigned __int8 *)(v42 - write - 1);
            mb = (unsigned int)v10;
            if ( write == s->end )
            {
              v43 = s->window;
              v44 = s->read;
              if ( v44 == v43 )
              {
                v10 = (unsigned __int8 *)mb;
              }
              else
              {
                write = s->window;
                if ( v43 >= v44 )
                  v10 = (unsigned __int8 *)(s->end - v43);
                else
                  v10 = (unsigned __int8 *)(v44 - v43 - 1);
              }
            }
            if ( v10 == nullptr )
              goto LABEL_93;
          }
        }
        *write = c->sub.lit;
        v32 = c;
        ++write;
        --v10;
        r = 0;
        m = (unsigned int)v10;
        goto LABEL_84;
      case 7:
        if ( bitk > 7 )
        {
          ++n;
          bitk -= 8;
          --p;
        }
        s->write = write;
        v47 = inflate_flush(s, z, r);
        write = s->write;
        if ( s->read != write )
        {
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = n;
          z->total_in += p - z->next_in;
          z->next_in = p;
          s->write = write;
          return inflate_flush(s, z, r: v47);
        }
        c->mode = END;
$LN3_47:
        s->bitb = b;
        s->bitk = bitk;
        z->avail_in = n;
        v48 = 1;
        goto LABEL_88;
      case 8:
        goto $LN3_47;
      case 9:
        v48 = -3;
        goto LABEL_87;
      default:
        goto LABEL_86;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9A20
// Name: int inflate_blocks(struct inflate_blocks_state __near *,struct z_stream_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_blocks(inflate_blocks_state *s, z_stream_s *z, int r)
{
  unsigned __int8 *next_in; // eax
  unsigned __int8 *write; // edx
  unsigned __int8 *read; // ecx
  unsigned int bitb; // eax
  unsigned int bitk; // edi
  unsigned __int8 *v10; // edx
  inflate_block_mode mode; // ecx
  unsigned int v12; // edx
  int v13; // ecx
  int v15; // edx
  unsigned int v16; // edi
  int v17; // ecx
  inflate_codes_state *v18; // eax
  int v19; // edx
  unsigned int v20; // ecx
  unsigned __int8 *end; // edx
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // ecx
  unsigned int v24; // eax
  int v25; // eax
  unsigned __int8 *v26; // ecx
  unsigned __int8 *v27; // eax
  unsigned __int8 *v28; // edx
  unsigned __int8 *window; // eax
  unsigned int left; // eax
  bool v31; // zf
  int v32; // edx
  unsigned int v33; // eax
  unsigned int v34; // ecx
  int v35; // eax
  unsigned int *v36; // eax
  int v37; // edx
  unsigned int bb; // ecx
  int v39; // edx
  inflate_huft_s *v40; // edx
  unsigned int Bits; // ecx
  unsigned int base; // edx
  int v43; // edx
  unsigned int v44; // eax
  unsigned int index; // ecx
  unsigned int v46; // eax
  unsigned int v47; // eax
  unsigned int v48; // eax
  unsigned int *v49; // edx
  void (__cdecl *zfree)(void *, void *); // ecx
  _BYTE *v51; // eax
  char v52; // dl
  inflate_huft_s *v53; // ecx
  inflate_huft_s *v54; // edx
  unsigned int v55; // ecx
  unsigned __int8 *v56; // eax
  int v57; // eax
  unsigned int v58; // ecx
  unsigned __int8 *v59; // edx
  unsigned __int8 *v60; // eax
  unsigned __int8 *v61; // ecx
  unsigned __int8 *v62; // eax
  unsigned __int8 *v63; // eax
  unsigned int v64; // eax
  unsigned __int8 *v65; // eax
  unsigned int v66; // edx
  unsigned __int8 *v67; // eax
  unsigned int v68; // eax
  unsigned int v69; // ecx
  unsigned __int8 *v70; // eax
  unsigned int v71; // eax
  unsigned __int8 *v72; // eax
  unsigned int v73; // edx
  unsigned int v74; // ecx
  unsigned __int8 *v75; // eax
  unsigned int v76; // ecx
  int v77; // edx
  unsigned int v78; // eax
  unsigned int *v79; // [esp-1Ch] [ebp-4Ch]
  unsigned int *blens; // [esp-14h] [ebp-44h]
  inflate_huft_s *hufts; // [esp-8h] [ebp-38h]
  inflate_huft_s *v82; // [esp-8h] [ebp-38h]
  unsigned int v83; // [esp-4h] [ebp-34h]
  unsigned int v84; // [esp-4h] [ebp-34h]
  inflate_huft_s *td; // [esp+Ch] [ebp-24h] BYREF
  inflate_huft_s *tl; // [esp+10h] [ebp-20h] BYREF
  unsigned int c; // [esp+14h] [ebp-1Ch]
  unsigned int v88; // [esp+18h] [ebp-18h]
  unsigned int i; // [esp+1Ch] [ebp-14h] BYREF
  unsigned int bd; // [esp+20h] [ebp-10h] BYREF
  unsigned int t; // [esp+24h] [ebp-Ch]
  unsigned int n; // [esp+28h] [ebp-8h]
  unsigned __int8 *p; // [esp+2Ch] [ebp-4h]
  unsigned __int8 *q; // [esp+38h] [ebp+8h]
  unsigned int b; // [esp+3Ch] [ebp+Ch]
  int ra; // [esp+40h] [ebp+10h]

  next_in = z->next_in;
  write = s->write;
  n = z->avail_in;
  read = s->read;
  p = next_in;
  bitb = s->bitb;
  bitk = s->bitk;
  b = bitb;
  q = write;
  if ( write >= read )
  {
    v10 = (unsigned __int8 *)(s->end - write);
    bd = s->end - q;
  }
  else
  {
    v10 = (unsigned __int8 *)(read - write - 1);
    bd = (unsigned int)v10;
  }
  mode = s->mode;
  while ( 2 )
  {
    switch ( mode )
    {
      case IBM_TYPE:
        for ( ; bitk < 3; b = bitb )
        {
          if ( n == 0 )
            goto LABEL_100;
          --n;
          v15 = *p++ << bitk;
          bitk += 8;
          bitb |= v15;
          r = 0;
        }
        s->last = bitb & 1;
        switch ( (unsigned __int8)(bitb & 7) >> 1 )
        {
          case 0:
            v16 = bitk - 3;
            v17 = v16 & 7;
            bitb = bitb >> 3 >> v17;
            bitk = v16 - v17;
            s->mode = IBM_LENS;
            b = bitb;
            goto LABEL_98;
          case 1:
            v18 = inflate_codes_new(bl: 9u, bd: 5u, tl: fixed_tl, td: fixed_td, z);
            s->sub.left = (unsigned int)v18;
            if ( v18 == nullptr )
            {
              v83 = -4;
              goto LABEL_6;
            }
            b >>= 3;
            bitk -= 3;
            s->mode = IBM_CODES;
            break;
          case 2:
            bitb >>= 3;
            b = bitb;
            bitk -= 3;
            s->mode = IBM_TABLE;
            goto LABEL_98;
          case 3:
            s->mode = IBM_BAD;
            z->msg = "invalid block type";
            s->bitb = b >> 3;
            v64 = n;
            s->bitk = bitk - 3;
            z->avail_in = v64;
            v83 = -3;
            goto LABEL_7;
          default:
            goto LABEL_98;
        }
        goto LABEL_97;
      case IBM_LENS:
        if ( bitk >= 0x20 )
          goto LABEL_22;
        do
        {
          if ( n == 0 )
          {
LABEL_104:
            s->bitb = b;
LABEL_101:
            v63 = p;
            s->bitk = bitk;
            v13 = v63 - z->next_in;
            z->next_in = v63;
            z->avail_in = 0;
            v83 = r;
            goto LABEL_8;
          }
          --n;
          v19 = *p++ << bitk;
          bitk += 8;
          bitb |= v19;
          r = 0;
          b = bitb;
        }
        while ( bitk < 0x20 );
LABEL_22:
        v20 = (unsigned __int16)bitb;
        if ( ~bitb >> 16 != (unsigned __int16)bitb )
        {
          s->mode = IBM_BAD;
          z->msg = "invalid stored block lengths";
          v83 = -3;
LABEL_6:
          v12 = n;
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = v12;
LABEL_7:
          v13 = p - z->next_in;
          z->next_in = p;
LABEL_8:
          z->total_in += v13;
          s->write = q;
          return inflate_flush(s, z, r: v83);
        }
        bitb = 0;
        bitk = 0;
        s->sub.left = v20;
        b = 0;
        if ( v20 != 0 )
          s->mode = IBM_STORED;
        else
          s->mode = s->last != 0 ? IBM_DRY : IBM_TYPE;
LABEL_98:
        mode = s->mode;
        if ( s->mode > (unsigned int)IBM_BAD )
        {
LABEL_5:
          v83 = -2;
          goto LABEL_6;
        }
        v10 = (unsigned __int8 *)bd;
        continue;
      case IBM_STORED:
        if ( n == 0 )
          goto LABEL_104;
        if ( v10 == nullptr )
        {
          if ( (end = s->end, q != end)
            || (v22 = s->read, (v23 = s->window) == v22)
            || ((q = s->window, v23 >= v22) ? (v24 = end - v23, bd = end - v23) : (v24 = v22 - v23 - 1, bd = v24),
                v24 == 0) )
          {
            s->write = q;
            v25 = inflate_flush(s, z, r);
            v26 = s->read;
            ra = v25;
            v27 = s->write;
            q = v27;
            if ( v27 >= v26 )
            {
              bd = s->end - v27;
              v28 = (unsigned __int8 *)bd;
            }
            else
            {
              v28 = (unsigned __int8 *)(v26 - v27 - 1);
              bd = (unsigned int)v28;
            }
            if ( v27 == s->end )
            {
              window = s->window;
              if ( window != v26 )
              {
                q = s->window;
                if ( window >= v26 )
                  v28 = (unsigned __int8 *)(s->end - window);
                else
                  v28 = (unsigned __int8 *)(v26 - window - 1);
                bd = (unsigned int)v28;
              }
            }
            if ( v28 == nullptr )
            {
              v65 = p;
              v66 = n;
              s->bitb = b;
              s->bitk = bitk;
              v13 = v65 - z->next_in;
              z->next_in = v65;
              z->avail_in = v66;
              v83 = ra;
              goto LABEL_8;
            }
          }
        }
        left = s->sub.left;
        r = 0;
        t = left;
        if ( left > n )
        {
          left = n;
          t = n;
        }
        if ( left > bd )
          t = bd;
        memcpy(dst: q, src: p, count: t);
        p += t;
        n -= t;
        q += t;
        bd -= t;
        v31 = s->sub.left == t;
        s->sub.left -= t;
        if ( v31 )
          s->mode = s->last != 0 ? IBM_DRY : IBM_TYPE;
        goto LABEL_97;
      case IBM_TABLE:
        for ( ; bitk < 0xE; b = bitb )
        {
          if ( n == 0 )
            goto LABEL_107;
          --n;
          v32 = *p++ << bitk;
          bitk += 8;
          bitb |= v32;
          r = 0;
        }
        v33 = bitb & 0x3FFF;
        v34 = v33 & 0x1F;
        s->sub.left = v33;
        if ( v34 > 0x1D || (unsigned int)(v35 = (v33 >> 5) & 0x1F) > 0x1D )
        {
          s->mode = IBM_BAD;
          z->msg = "too many length or distance symbols";
$LN2_38:
          v69 = n;
          s->bitb = b;
          v70 = p;
          s->bitk = bitk;
          z->total_in += v70 - z->next_in;
          z->next_in = v70;
          z->avail_in = v69;
          s->write = q;
          return inflate_flush(s, z, r: -3);
        }
        v36 = (unsigned int *)z->zalloc(a1: z->opaque, a2: v35 + v34 + 258, a3: 4);
        s->sub.trees.blens = v36;
        if ( v36 == nullptr )
          goto LABEL_108;
        b >>= 14;
        bitb = b;
        bitk -= 14;
        s->sub.trees.index = 0;
        s->mode = IBM_BTREE;
$LN112_1:
        if ( s->sub.trees.index < (s->sub.left >> 10) + 4 )
        {
          while ( bitk >= 3 )
          {
LABEL_61:
            s->sub.trees.blens[border[s->sub.trees.index++]] = bitb & 7;
            bitb = b >> 3;
            bitk -= 3;
            b >>= 3;
            if ( s->sub.trees.index >= (s->sub.left >> 10) + 4 )
              goto LABEL_62;
          }
          while ( n != 0 )
          {
            --n;
            v37 = *p++ << bitk;
            bitk += 8;
            bitb |= v37;
            r = 0;
            b = bitb;
            if ( bitk >= 3 )
              goto LABEL_61;
          }
          goto LABEL_107;
        }
LABEL_62:
        while ( s->sub.trees.index < 0x13 )
          s->sub.trees.blens[border[s->sub.trees.index++]] = 0;
        hufts = s->hufts;
        blens = s->sub.trees.blens;
        s->sub.trees.bb = 7;
        t = inflate_trees_bits(c: blens, bb: &s->sub.trees.bb, tb: &s->sub.trees.tb, hp: hufts, z);
        if ( t != 0 )
        {
          z->zfree(a1: z->opaque, a2: s->sub.trees.blens);
          if ( t == -3 )
            s->mode = IBM_BAD;
          v71 = n;
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = v71;
          v13 = p - z->next_in;
          z->next_in = p;
          v83 = t;
          goto LABEL_8;
        }
        s->sub.trees.index = 0;
        bitb = b;
        s->mode = IBM_DTREE;
$LN115_1:
        if ( s->sub.trees.index < ((s->sub.left >> 5) & 0x1F) + (s->sub.left & 0x1F) + 258 )
        {
          while ( 1 )
          {
            bb = s->sub.trees.bb;
            if ( bitk < bb )
              break;
LABEL_72:
            v40 = &s->sub.trees.tb[bitb & inflate_mask[bb]];
            Bits = v40->word.what.Bits;
            base = v40->base;
            t = Bits;
            c = base;
            if ( base >= 0x10 )
            {
              if ( base == 18 )
                i = 7;
              else
                i = base - 14;
              bd = 8 * (base == 18) + 3;
              v88 = i + t;
              if ( bitk < i + t )
              {
                while ( n != 0 )
                {
                  --n;
                  v43 = *p++ << bitk;
                  bitk += 8;
                  bitb |= v43;
                  r = 0;
                  b = bitb;
                  if ( bitk >= v88 )
                    goto LABEL_80;
                }
LABEL_100:
                s->bitb = b;
                goto LABEL_101;
              }
LABEL_80:
              v44 = bitb >> t;
              bd += v44 & inflate_mask[i];
              bitk -= t + i;
              index = s->sub.trees.index;
              b = v44 >> i;
              if ( index + bd > ((s->sub.left >> 5) & 0x1F) + (s->sub.left & 0x1F) + 258 )
                goto LABEL_114;
              if ( c == 16 )
              {
                if ( index == 0 )
                {
LABEL_114:
                  z->zfree(a1: z->opaque, a2: s->sub.trees.blens);
                  v72 = p;
                  v73 = n;
                  s->mode = IBM_BAD;
                  z->msg = "invalid bit length repeat";
                  s->bitb = b;
                  s->bitk = bitk;
                  z->total_in += v72 - z->next_in;
                  z->avail_in = v73;
                  z->next_in = v72;
                  s->write = q;
                  return inflate_flush(s, z, r: -3);
                }
                v46 = s->sub.trees.blens[index - 1];
              }
              else
              {
                v46 = 0;
              }
              do
              {
                s->sub.trees.blens[index++] = v46;
                --bd;
              }
              while ( bd != 0 );
              s->sub.trees.index = index;
            }
            else
            {
              bitk -= Bits;
              b = bitb >> Bits;
              s->sub.trees.blens[s->sub.trees.index++] = base;
            }
            if ( s->sub.trees.index >= ((s->sub.left >> 5) & 0x1F) + (s->sub.left & 0x1F) + 258 )
              goto LABEL_88;
            bitb = b;
          }
          while ( n != 0 )
          {
            --n;
            v39 = *p << bitk;
            bb = s->sub.trees.bb;
            bitk += 8;
            r = 0;
            bitb |= v39;
            ++p;
            b = bitb;
            if ( bitk >= bb )
              goto LABEL_72;
          }
LABEL_107:
          v67 = p;
          s->bitb = b;
          s->bitk = bitk;
          z->total_in += v67 - z->next_in;
          z->next_in = v67;
          z->avail_in = 0;
          s->write = q;
          return inflate_flush(s, z, r);
        }
LABEL_88:
        v47 = s->sub.left;
        v82 = s->hufts;
        v79 = s->sub.trees.blens;
        s->sub.trees.tb = nullptr;
        i = 9;
        bd = 6;
        v48 = inflate_trees_dynamic(
                nl: (v47 & 0x1F) + 257,
                nd: ((v47 >> 5) & 0x1F) + 1,
                c: v79,
                bl: &i,
                &bd,
                &tl,
                &td,
                hp: v82,
                z);
        v49 = s->sub.trees.blens;
        zfree = z->zfree;
        t = v48;
        zfree(a1: z->opaque, a2: v49);
        if ( t != 0 )
        {
          if ( t == -3 )
            s->mode = IBM_BAD;
          v74 = n;
          s->bitb = b;
          v75 = p;
          s->bitk = bitk;
          z->avail_in = v74;
          v84 = t;
          z->total_in += v75 - z->next_in;
          z->next_in = v75;
          s->write = q;
          return inflate_flush(s, z, r: v84);
        }
        v51 = z->zalloc(a1: z->opaque, a2: 1, a3: 28);
        if ( v51 == nullptr )
        {
LABEL_108:
          v68 = n;
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = v68;
          v83 = -4;
          goto LABEL_7;
        }
        v52 = bd;
        v51[16] = i;
        v53 = tl;
        v51[17] = v52;
        v54 = td;
        *(_DWORD *)v51 = 0;
        *((_DWORD *)v51 + 5) = v53;
        *((_DWORD *)v51 + 6) = v54;
        s->sub.left = (unsigned int)v51;
        s->mode = IBM_CODES;
$LN8_33:
        v55 = n;
        s->bitb = b;
        v56 = p;
        s->bitk = bitk;
        z->avail_in = v55;
        z->total_in += v56 - z->next_in;
        z->next_in = v56;
        s->write = q;
        v57 = inflate_codes(s, z, r);
        if ( v57 == 1 )
        {
          r = 0;
          z->zfree(a1: z->opaque, a2: (void *)s->sub.left);
          v58 = s->bitb;
          v59 = z->next_in;
          bitk = s->bitk;
          n = z->avail_in;
          v60 = s->read;
          b = v58;
          v61 = s->write;
          p = v59;
          q = v61;
          if ( v61 >= v60 )
            v62 = (unsigned __int8 *)(s->end - v61);
          else
            v62 = (unsigned __int8 *)(v60 - v61 - 1);
          v31 = s->last == 0;
          bd = (unsigned int)v62;
          if ( v31 )
          {
            s->mode = IBM_TYPE;
LABEL_97:
            bitb = b;
            goto LABEL_98;
          }
          s->mode = IBM_DRY;
$LN5_44:
          s->write = q;
          v57 = inflate_flush(s, z, r);
          q = s->write;
          if ( s->read == q )
          {
            s->mode = IBM_DONE;
$LN3_48:
            v78 = n;
            s->bitb = b;
            s->bitk = bitk;
            z->avail_in = v78;
            v83 = 1;
            goto LABEL_7;
          }
          v76 = n;
          s->bitb = b;
          s->bitk = bitk;
          z->avail_in = v76;
          v77 = p - z->next_in;
          z->next_in = p;
          z->total_in += v77;
          s->write = q;
        }
        return inflate_flush(s, z, r: v57);
      case IBM_BTREE:
        goto $LN112_1;
      case IBM_DTREE:
        goto $LN115_1;
      case IBM_CODES:
        goto $LN8_33;
      case IBM_DRY:
        goto $LN5_44;
      case IBM_DONE:
        goto $LN3_48;
      case IBM_BAD:
        goto $LN2_38;
      default:
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA3E0
// Name: int inflate(struct z_stream_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate(z_stream_s *z, int f)
{
  internal_state *state; // eax
  inflate_mode mode; // eax
  int v4; // edi
  unsigned int avail_in; // eax
  internal_state *v6; // ecx
  unsigned int v7; // eax
  internal_state *v8; // eax
  internal_state *v9; // eax
  unsigned int v10; // eax
  int v11; // ecx
  int v12; // eax
  internal_state *v13; // eax
  unsigned int v14; // eax
  internal_state *v15; // edx
  internal_state *v16; // eax
  unsigned int v17; // eax
  unsigned __int8 *v18; // ecx
  internal_state *v19; // eax
  unsigned int v20; // eax
  unsigned __int8 *v21; // ecx
  internal_state *v22; // eax
  unsigned int v23; // eax
  unsigned __int8 *v24; // ecx
  internal_state *v25; // eax
  unsigned int v27; // eax
  unsigned __int8 *next_in; // edx
  internal_state *v29; // ecx
  internal_state *v30; // edx
  unsigned int v31; // eax
  unsigned __int8 *v32; // ecx
  internal_state *v33; // eax
  unsigned int v34; // eax
  unsigned __int8 *v35; // ecx
  internal_state *v36; // eax
  unsigned int v37; // eax
  unsigned __int8 *v38; // ecx
  internal_state *v39; // eax
  internal_state *v40; // eax

  if ( z == nullptr )
    return -2;
  state = z->state;
  if ( state == nullptr || z->next_in == nullptr )
    return -2;
  mode = state->mode;
  v4 = -5;
  while ( 2 )
  {
    switch ( mode )
    {
      case IM_METHOD:
        avail_in = z->avail_in;
        if ( avail_in == 0 )
          return v4;
        ++z->total_in;
        v6 = z->state;
        z->avail_in = avail_in - 1;
        v7 = *z->next_in;
        v6->sub.method = v7;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        if ( (v7 & 0xF) != 8 )
        {
          z->state->mode = IM_BAD;
          v8 = z->state;
          z->msg = "unknown compression method";
          v8->sub.method = 5;
          goto LABEL_35;
        }
        v9 = z->state;
        if ( (v9->sub.method >> 4) + 8 > v9->wbits )
        {
          v9->mode = IM_BAD;
          z->msg = "invalid window size";
          goto LABEL_34;
        }
        v9->mode = IM_FLAG;
        goto $LN51_0;
      case IM_FLAG:
$LN51_0:
        v10 = z->avail_in;
        if ( v10 == 0 )
          return v4;
        ++z->total_in;
        z->avail_in = v10 - 1;
        v11 = *z->next_in++;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        if ( (v11 + (z->state->sub.method << 8)) % 0x1F != 0 )
        {
          z->state->mode = IM_BAD;
          z->msg = "incorrect header check";
LABEL_34:
          z->state->sub.method = 5;
LABEL_35:
          mode = z->state->mode;
          if ( (unsigned int)mode > IM_BAD )
            return -2;
          continue;
        }
        if ( (v11 & 0x20) == 0 )
        {
          z->state->mode = IM_BLOCKS;
          goto LABEL_35;
        }
        z->state->mode = IM_DICT4;
$LN26_5:
        v27 = z->avail_in;
        if ( v27 == 0 )
          return v4;
        next_in = z->next_in;
        ++z->total_in;
        v29 = z->state;
        z->avail_in = v27 - 1;
        v29->sub.check.need = *next_in << 24;
        v30 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v30->mode = IM_DICT3;
$LN55_1:
        v31 = z->avail_in;
        if ( v31 == 0 )
          return v4;
        v32 = z->next_in;
        ++z->total_in;
        z->avail_in = v31 - 1;
        z->state->sub.check.need += *v32 << 16;
        v33 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v33->mode = IM_DICT2;
$LN56_1:
        v34 = z->avail_in;
        if ( v34 == 0 )
          return v4;
        v35 = z->next_in;
        ++z->total_in;
        z->avail_in = v34 - 1;
        z->state->sub.check.need += *v35 << 8;
        v36 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v36->mode = IM_DICT1;
$LN57_1:
        v37 = z->avail_in;
        if ( v37 == 0 )
          return v4;
        v38 = z->next_in;
        ++z->total_in;
        z->avail_in = v37 - 1;
        z->state->sub.check.need += *v38;
        v39 = z->state;
        ++z->next_in;
        z->adler = v39->sub.check.need;
        v39->mode = IM_DICT0;
        return 2;
      case IM_DICT4:
        goto $LN26_5;
      case IM_DICT3:
        goto $LN55_1;
      case IM_DICT2:
        goto $LN56_1;
      case IM_DICT1:
        goto $LN57_1;
      case IM_DICT0:
        z->state->mode = IM_BAD;
        v40 = z->state;
        z->msg = "need dictionary";
        v40->sub.method = 0;
        return -2;
      case IM_BLOCKS:
        v12 = inflate_blocks(s: z->state->blocks, z, r: v4);
        v4 = v12;
        if ( v12 == -3 )
        {
          z->state->mode = IM_BAD;
          z->state->sub.method = 0;
          goto LABEL_35;
        }
        if ( v12 == 0 )
          v4 = f != 4 ? 0 : 0xFFFFFFFB;
        if ( v4 != 1 )
          return v4;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        inflate_blocks_reset(s: z->state->blocks, z, c: &z->state->sub.method);
        v13 = z->state;
        if ( v13->nowrap != 0 )
        {
          v13->mode = IM_DONE;
          goto LABEL_35;
        }
        v13->mode = IM_CHECK4;
$LN12_27:
        v14 = z->avail_in;
        if ( v14 == 0 )
          return v4;
        ++z->total_in;
        v15 = z->state;
        z->avail_in = v14 - 1;
        v15->sub.check.need = *z->next_in << 24;
        v16 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v16->mode = IM_CHECK3;
$LN52_0:
        v17 = z->avail_in;
        if ( v17 == 0 )
          return v4;
        v18 = z->next_in;
        ++z->total_in;
        z->avail_in = v17 - 1;
        z->state->sub.check.need += *v18 << 16;
        v19 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v19->mode = IM_CHECK2;
$LN53_2:
        v20 = z->avail_in;
        if ( v20 == 0 )
          return v4;
        v21 = z->next_in;
        ++z->total_in;
        z->avail_in = v20 - 1;
        z->state->sub.check.need += *v21 << 8;
        v22 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        v22->mode = IM_CHECK1;
$LN54_2:
        v23 = z->avail_in;
        if ( v23 == 0 )
          return v4;
        v24 = z->next_in;
        ++z->total_in;
        z->avail_in = v23 - 1;
        z->state->sub.check.need += *v24;
        v25 = z->state;
        ++z->next_in;
        v4 = f != 4 ? 0 : 0xFFFFFFFB;
        if ( v25->sub.method == v25->sub.check.need )
        {
          z->state->mode = IM_DONE;
          return 1;
        }
        v25->mode = IM_BAD;
        z->msg = "incorrect data check";
        goto LABEL_34;
      case IM_CHECK4:
        goto $LN12_27;
      case IM_CHECK3:
        goto $LN52_0;
      case IM_CHECK2:
        goto $LN53_2;
      case IM_CHECK1:
        goto $LN54_2;
      case IM_DONE:
        return 1;
      case IM_BAD:
        return -3;
      default:
        return -2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA7A0
// Name: struct unz_s __near * unzOpenInternal(struct LUFILE __near *)
// Source: json
//------------------------------------------------------------------------------
unz_s *__cdecl unzOpenInternal(int fin)
{
  unsigned __int8 *v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax
  unsigned int offset_central_dir; // ecx
  unsigned int v7; // eax
  IMemAlloc_vtbl *v8; // edx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  unz_s *v10; // ebx
  unz_s us; // [esp+4h] [ebp-8Ch] BYREF
  unsigned int number_entry_CD; // [esp+84h] [ebp-Ch] BYREF
  unsigned int number_disk_with_CD; // [esp+88h] [ebp-8h] BYREF
  unsigned int number_disk; // [esp+8Ch] [ebp-4h] BYREF
  int err; // [esp+98h] [ebp+8h]

  if ( fin == 0 )
    return nullptr;
  err = 0;
  v3 = unzlocal_SearchCentralDir((LUFILE *)fin);
  v4 = (unsigned int)v3;
  if ( v3 == nullptr )
    err = -1;
  if ( *(_BYTE *)fin != 0 )
  {
    if ( *(_BYTE *)(fin + 1) != 0 )
      SetFilePointer(
        hFile: *(HANDLE *)(fin + 4),
        lDistanceToMove: (LONG)&v3[*(_DWORD *)(fin + 12)],
        lpDistanceToMoveHigh: nullptr,
        dwMoveMethod: 0);
    else
      err = -1;
  }
  else
  {
    *(_DWORD *)(fin + 24) = v3;
  }
  if ( unzlocal_getLong((LUFILE *)fin, pX: &number_disk) != 0 )
    err = -1;
  if ( unzlocal_getShort((LUFILE *)fin, pX: &number_disk) != 0 )
    err = -1;
  if ( unzlocal_getShort((LUFILE *)fin, pX: &number_disk_with_CD) != 0 )
    err = -1;
  if ( unzlocal_getShort((LUFILE *)fin, pX: &us.gi.number_entry) != 0 )
    err = -1;
  if ( unzlocal_getShort((LUFILE *)fin, pX: &number_entry_CD) != 0 )
    err = -1;
  if ( number_entry_CD != us.gi.number_entry || number_disk_with_CD != 0 || number_disk != 0 )
    err = -103;
  if ( unzlocal_getLong((LUFILE *)fin, pX: &us.size_central_dir) != 0 )
    err = -1;
  if ( unzlocal_getLong((LUFILE *)fin, pX: &us.offset_central_dir) != 0 )
    err = -1;
  if ( unzlocal_getShort((LUFILE *)fin, pX: &us.gi.size_comment) != 0 )
    err = -1;
  v5 = *(_DWORD *)(fin + 12);
  offset_central_dir = us.offset_central_dir;
  if ( v5 + v4 < us.offset_central_dir + us.size_central_dir || err != 0 )
  {
    if ( *(_BYTE *)fin != 0 )
      CloseHandle(hObject: *(HANDLE *)(fin + 4));
    free(pMem: (void *)fin);
    return nullptr;
  }
  else
  {
    v7 = v5 - us.size_central_dir;
    *(_DWORD *)(fin + 12) = 0;
    us.pfile_in_zip_read = nullptr;
    v8 = _g_pMemAlloc->__vftable;
    us.byte_before_the_zipfile = v4 + v7 - offset_central_dir;
    Alloc_2 = v8->Alloc_2;
    us.file = (LUFILE *)fin;
    us.central_pos = v4;
    v10 = (unz_s *)Alloc_2(this: _g_pMemAlloc, a2: 128u);
    *v10 = us;
    unzGoToFirstFile(file: v10);
    return v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA950
// Name: int unzClose(struct unz_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzClose(unz_s *file)
{
  LUFILE *v2; // esi

  if ( file == nullptr )
    return -102;
  if ( file->pfile_in_zip_read != nullptr )
    unzCloseCurrentFile(file);
  v2 = file->file;
  if ( file->file != nullptr )
  {
    if ( v2->is_handle )
      CloseHandle(hObject: v2->h);
    free(pMem: v2);
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FA9B0
// Name: int unzOpenCurrentFile(struct unz_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzOpenCurrentFile(unz_s *file)
{
  file_in_zip_read_info_s *v2; // esi
  char *v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // edx
  bool v6; // zf
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned int iSizeVar; // [esp+8h] [ebp-Ch] BYREF
  unsigned int size_local_extrafield; // [esp+Ch] [ebp-8h] BYREF
  unsigned int offset_local_extrafield; // [esp+10h] [ebp-4h] BYREF

  iSizeVar = 0;
  offset_local_extrafield = 0;
  size_local_extrafield = 0;
  if ( file == nullptr || file->current_file_ok == 0 )
    return -102;
  if ( file->pfile_in_zip_read != nullptr )
    unzCloseCurrentFile(file);
  if ( unzlocal_CheckCurrentFileCoherencyHeader(
         s: file,
         piSizeVar: &iSizeVar,
         poffset_local_extrafield: &offset_local_extrafield,
         psize_local_extrafield: &size_local_extrafield) != 0 )
    return -103;
  v2 = (file_in_zip_read_info_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 108);
  if ( v2 == nullptr )
    return -104;
  v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x4000);
  v4 = offset_local_extrafield;
  v5 = size_local_extrafield;
  v2->read_buffer = v3;
  v2->offset_local_extrafield = v4;
  v2->size_local_extrafield = v5;
  v2->pos_local_extrafield = 0;
  if ( v3 == nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
    return -104;
  }
  v2->stream_initialised = 0;
  v6 = file->cur_file_info.compression_method == 0;
  v2->crc32_wait = file->cur_file_info.crc;
  v2->crc32 = 0;
  v2->compression_method = file->cur_file_info.compression_method;
  v2->file = file->file;
  v2->byte_before_the_zipfile = file->byte_before_the_zipfile;
  v2->stream.total_out = 0;
  if ( !v6 )
  {
    v2->stream.zalloc = nullptr;
    v2->stream.zfree = nullptr;
    v2->stream.opaque = nullptr;
    if ( inflateInit2(z: &v2->stream) == 0 )
      v2->stream_initialised = 1;
  }
  v2->rest_read_compressed = file->cur_file_info.compressed_size;
  v7 = iSizeVar;
  v2->rest_read_uncompressed = file->cur_file_info.uncompressed_size;
  v8 = file->cur_file_info_internal.offset_curfile + v7 + 30;
  v2->stream.avail_in = 0;
  v2->pos_in_zipfile = v8;
  file->pfile_in_zip_read = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FAAE0
// Name: int unzReadCurrentFile(struct unz_s __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl unzReadCurrentFile(unz_s *file, unsigned __int8 *buf, unsigned int len)
{
  file_in_zip_read_info_s *pfile_in_zip_read; // esi
  unsigned int rest_read_uncompressed; // eax
  unsigned int rest_read_compressed; // eax
  unsigned int v7; // edi
  LUFILE *v8; // eax
  int v9; // ecx
  unsigned __int8 *read_buffer; // eax
  unsigned int avail_in; // edi
  unsigned int i; // eax
  const unsigned __int8 *next_out; // ebx
  int v14; // eax
  unsigned int total_out; // ebx
  int v16; // eax
  unsigned int v17; // edi
  int v18; // eax
  int err; // [esp+0h] [ebp-8h]
  unsigned int iRead; // [esp+4h] [ebp-4h]
  const unsigned __int8 *bufBefore; // [esp+10h] [ebp+8h]

  iRead = 0;
  if ( file == nullptr )
    return -102;
  pfile_in_zip_read = file->pfile_in_zip_read;
  if ( pfile_in_zip_read == nullptr )
    return -102;
  if ( pfile_in_zip_read->read_buffer == nullptr )
    return -100;
  if ( len == 0 )
    return 0;
  pfile_in_zip_read->stream.next_out = buf;
  rest_read_uncompressed = pfile_in_zip_read->rest_read_uncompressed;
  pfile_in_zip_read->stream.avail_out = len;
  if ( len > rest_read_uncompressed )
    pfile_in_zip_read->stream.avail_out = rest_read_uncompressed;
  if ( pfile_in_zip_read->stream.avail_out == 0 )
    return iRead;
  while ( 1 )
  {
    if ( pfile_in_zip_read->stream.avail_in == 0 )
    {
      rest_read_compressed = pfile_in_zip_read->rest_read_compressed;
      if ( rest_read_compressed != 0 )
      {
        v7 = 0x4000;
        if ( rest_read_compressed < 0x4000 )
          v7 = pfile_in_zip_read->rest_read_compressed;
        v8 = pfile_in_zip_read->file;
        v9 = pfile_in_zip_read->pos_in_zipfile + pfile_in_zip_read->byte_before_the_zipfile;
        if ( v8->is_handle )
        {
          if ( !v8->canseek )
            return -1;
          SetFilePointer(
            hFile: v8->h,
            lDistanceToMove: v9 + v8->initial_offset,
            lpDistanceToMoveHigh: nullptr,
            dwMoveMethod: 0);
        }
        else
        {
          v8->pos = v9;
        }
        if ( lufread(ptr: pfile_in_zip_read->read_buffer, size: v7, n: 1u, stream: pfile_in_zip_read->file) != 1 )
          return -1;
        read_buffer = (unsigned __int8 *)pfile_in_zip_read->read_buffer;
        pfile_in_zip_read->pos_in_zipfile += v7;
        pfile_in_zip_read->rest_read_compressed -= v7;
        pfile_in_zip_read->stream.next_in = read_buffer;
        pfile_in_zip_read->stream.avail_in = v7;
      }
    }
    if ( pfile_in_zip_read->compression_method != 0 )
      break;
    avail_in = pfile_in_zip_read->stream.avail_in;
    if ( pfile_in_zip_read->stream.avail_out < avail_in )
      avail_in = pfile_in_zip_read->stream.avail_out;
    for ( i = 0; i < avail_in; ++i )
      pfile_in_zip_read->stream.next_out[i] = pfile_in_zip_read->stream.next_in[i];
    next_out = pfile_in_zip_read->stream.next_out;
    v14 = ucrc32(crc: pfile_in_zip_read->crc32, buf: next_out, len: avail_in);
    pfile_in_zip_read->rest_read_uncompressed -= avail_in;
    pfile_in_zip_read->stream.avail_in -= avail_in;
    pfile_in_zip_read->stream.avail_out -= avail_in;
    pfile_in_zip_read->stream.next_in += avail_in;
    pfile_in_zip_read->stream.total_out += avail_in;
    iRead += avail_in;
    pfile_in_zip_read->crc32 = v14;
    pfile_in_zip_read->stream.next_out = (unsigned __int8 *)&next_out[avail_in];
LABEL_30:
    if ( pfile_in_zip_read->stream.avail_out == 0 )
      return iRead;
  }
  total_out = pfile_in_zip_read->stream.total_out;
  bufBefore = pfile_in_zip_read->stream.next_out;
  v16 = inflate(z: &pfile_in_zip_read->stream, f: 2);
  v17 = pfile_in_zip_read->stream.total_out - total_out;
  err = v16;
  v18 = ucrc32(crc: pfile_in_zip_read->crc32, buf: bufBefore, len: v17);
  pfile_in_zip_read->rest_read_uncompressed -= v17;
  iRead += v17;
  pfile_in_zip_read->crc32 = v18;
  if ( err == 1 )
    return iRead;
  if ( err == 0 )
    goto LABEL_30;
  return err;
}

//------------------------------------------------------------------------------
// Address: 0x101FACA0
// Name: public: unsigned long TUnzip::Open(void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TUnzip::Open(TUnzip *this, void *z, unsigned int len, void *flags)
{
  char *v5; // edi
  char v6; // al
  void *v7; // esi
  LUFILE *v9; // eax
  unz_s *v10; // eax

  if ( this->uf != nullptr || this->currentfile != -1 )
    return 0x1000000;
  GetCurrentDirectoryA(nBufferLength: 0x104u, lpBuffer: this->rootdir);
  v5 = (char *)&this->czei + 3;
  do
    v6 = *++v5;
  while ( v6 != 0 );
  v7 = flags;
  strcpy(v5, "\\");
  if ( v7 == (void *)1 && GetFileType(hFile: z) != 1 )
    return 0x2000000;
  flags = nullptr;
  v9 = lufopen(z, len, flags: v7, err: (unsigned int *)&flags);
  if ( v9 == nullptr )
    return (int)flags;
  v10 = unzOpenInternal(fin: (int)v9);
  this->uf = v10;
  return v10 != nullptr ? 0 : 1792;
}

//------------------------------------------------------------------------------
// Address: 0x101FAD60
// Name: public: unsigned long TUnzip::Unzip(int,void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TUnzip::Unzip(TUnzip *this, int index, unsigned __int8 *dst, unsigned int len, unsigned int flags)
{
  unsigned int v5; // esi
  int currentfile; // eax
  int v9; // esi
  unz_s *uf; // eax
  int v11; // esi
  unz_s *v12; // eax
  int v13; // ebx
  unz_s *v14; // esi
  int v15; // eax
  int v16; // edx
  unsigned int size_filename; // ecx
  char *FileA; // esi
  unsigned __int8 v19; // al
  unsigned __int8 *v20; // ebx
  unsigned __int8 *v21; // ecx
  unsigned __int8 *v22; // eax
  unsigned __int8 v23; // cl
  bool v24; // bl
  unsigned __int8 *v25; // eax
  int v26; // eax
  signed int v27; // eax
  bool v28; // zf
  char v29; // bl
  unz_s *v30; // [esp-14h] [ebp-424Ch]
  unsigned __int8 Buffer[16384]; // [esp+8h] [ebp-4230h] BYREF
  ZIPENTRY ze; // [esp+4008h] [ebp-230h] BYREF
  unsigned __int8 str1[260]; // [esp+4134h] [ebp-104h] BYREF

  v5 = flags;
  if ( flags == 3 )
  {
    currentfile = this->currentfile;
    v9 = index;
    if ( index != currentfile )
    {
      if ( currentfile != -1 )
        unzCloseCurrentFile(file: this->uf);
      uf = this->uf;
      this->currentfile = -1;
      if ( v9 >= (signed int)uf->gi.number_entry )
        return 0x10000;
      if ( v9 < (signed int)uf->num_file )
        unzGoToFirstFile(file: uf);
      while ( (signed int)this->uf->num_file < v9 )
        unzGoToNextFile(file: this->uf);
      unzOpenCurrentFile(file: this->uf);
      this->currentfile = v9;
    }
    v11 = unzReadCurrentFile(file: this->uf, buf: dst, len);
    if ( v11 <= 0 )
    {
      unzCloseCurrentFile(file: this->uf);
      this->currentfile = -1;
      return v11 != 0 ? 0x5000000 : 0;
    }
    else
    {
      return 1536;
    }
  }
  else
  {
    if ( flags != 2 && flags != 1 )
      return 0x10000;
    if ( this->currentfile != -1 )
      unzCloseCurrentFile(file: this->uf);
    v12 = this->uf;
    this->currentfile = -1;
    v13 = index;
    if ( index < (signed int)v12->gi.number_entry )
    {
      if ( index < (signed int)v12->num_file )
        unzGoToFirstFile(file: v12);
      if ( (signed int)this->uf->num_file < v13 )
      {
        do
        {
          v14 = this->uf;
          if ( this->uf != nullptr && v14->current_file_ok != 0 )
          {
            v15 = v14->num_file + 1;
            if ( v15 != v14->gi.number_entry )
            {
              v16 = v14->cur_file_info.size_file_extra + v14->cur_file_info.size_file_comment;
              size_filename = v14->cur_file_info.size_filename;
              v14->num_file = v15;
              v14->pos_in_central_dir += v16 + size_filename + 46;
              v14->current_file_ok = unzlocal_GetCurrentFileInfoInternal(
                                       file: v14,
                                       pfile_info: &v14->cur_file_info,
                                       pfile_info_internal: &v14->cur_file_info_internal,
                                       szFileName: nullptr,
                                       fileNameBufferSize: 0,
                                       extraField: nullptr,
                                       extraFieldBufferSize: 0,
                                       szComment: nullptr,
                                       commentBufferSize: 0) == 0;
            }
          }
        }
        while ( (signed int)this->uf->num_file < v13 );
        v5 = flags;
      }
      TUnzip::Get(this, index: v13, &ze);
      if ( (ze.attr & 0x10) != 0 )
      {
        if ( v5 != 1 )
          EnsureDirectory(rootdir: this->rootdir, dir: ze.name);
        return 0;
      }
      else
      {
        v28 = v5 == 1;
        FileA = (char *)dst;
        if ( !v28 )
        {
          v19 = *dst;
          v20 = dst;
          v21 = dst;
          if ( *dst != 0 )
          {
            do
            {
              if ( v19 == 47 || v19 == 92 )
                v20 = v21 + 1;
              v19 = *++v21;
            }
            while ( v19 != 0 );
            if ( v20 != dst )
            {
              v22 = dst;
              do
              {
                v23 = *v22;
                v22[str1 - (unsigned __int8 *)FileA] = *v22;
                ++v22;
              }
              while ( v23 != 0 );
              *((_BYTE *)&ze.unc_size + v20 - (unsigned __int8 *)FileA + 3) = 0;
              v24 = str1[0] == 47 || str1[0] == 92 || str1[1] == 58;
              strstr(str1, str2: "../");
              dst = v25;
              strstr(str1, str2: "..\\");
              if ( !v24 && dst == nullptr && v26 == 0 )
                EnsureDirectory(rootdir: this->rootdir, dir: (const char *)str1);
            }
          }
          FileA = (char *)CreateFileA(
                            lpFileName: FileA,
                            dwDesiredAccess: 0x40000000u,
                            dwShareMode: 0,
                            lpSecurityAttributes: nullptr,
                            dwCreationDisposition: 2u,
                            dwFlagsAndAttributes: ze.attr,
                            hTemplateFile: nullptr);
        }
        if ( FileA == (char *)-1 )
        {
          return 512;
        }
        else
        {
          unzOpenCurrentFile(file: this->uf);
          v30 = this->uf;
          HIBYTE(dst) = 0;
          v27 = unzReadCurrentFile(file: v30, buf: Buffer, len: 0x4000u);
          v28 = v27 == 0;
          if ( v27 < 0 )
          {
LABEL_57:
            v29 = 1;
          }
          else
          {
            while ( !v28 )
            {
              if ( !WriteFile(
                      hFile: FileA,
                      lpBuffer: Buffer,
                      nNumberOfBytesToWrite: v27,
                      lpNumberOfBytesWritten: (LPDWORD)&index,
                      lpOverlapped: nullptr) )
              {
                HIBYTE(dst) = 1;
                break;
              }
              v27 = unzReadCurrentFile(file: this->uf, buf: Buffer, len: 0x4000u);
              v28 = v27 == 0;
              if ( v27 < 0 )
                goto LABEL_57;
            }
            v29 = HIBYTE(dst);
          }
          if ( GetFileType(hFile: FileA) == 1 && v29 == 0 )
            SetFileTime(
              hFile: FileA,
              lpCreationTime: &ze.ctime,
              lpLastAccessTime: &ze.atime,
              lpLastWriteTime: &ze.mtime);
          if ( flags != 1 )
            CloseHandle(hObject: FileA);
          unzCloseCurrentFile(file: this->uf);
          return v29 != 0 ? 0x400 : 0;
        }
      }
    }
    else
    {
      return 0x10000;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB0D0
// Name: struct HZIP__ __near * OpenZipU(void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HZIP__ *__cdecl OpenZipU(void *z, unsigned int len, void *flags)
{
  TUnzip *v3; // eax
  TUnzip *v4; // esi
  HZIP__ *result; // eax

  v3 = (TUnzip *)MemAlloc_Alloc(nSize: 0x23Cu);
  if ( v3 != nullptr )
  {
    v3->uf = nullptr;
    v3->currentfile = -1;
    v3->czei = -1;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  lasterrorU = TUnzip::Open(this: v4, z, len, flags);
  if ( lasterrorU != 0 )
  {
    free(pMem: v4);
    return nullptr;
  }
  else
  {
    result = (HZIP__ *)MemAlloc_Alloc(nSize: 8u);
    *((_DWORD *)result + 1) = v4;
    *(_DWORD *)result = 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FB140
// Name: unsigned long UnzipItem(struct HZIP__ __near *,int,void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UnzipItem(TUnzip **hz, int index, unsigned __int8 *dst, unsigned int len, unsigned int flags)
{
  int result; // eax

  if ( hz != nullptr )
  {
    if ( *hz == (TUnzip *)1 )
    {
      result = TUnzip::Unzip(this: hz[1], index, dst, len, flags);
      lasterrorU = result;
    }
    else
    {
      lasterrorU = 0x80000;
      return 0x80000;
    }
  }
  else
  {
    lasterrorU = 0x10000;
    return 0x10000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FB190
// Name: unsigned long CloseZipU(struct HZIP__ __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CloseZipU(HZIP__ *hz)
{
  int v2; // esi
  unz_s *v3; // eax

  if ( hz != nullptr )
  {
    if ( *(_DWORD *)hz == 1 )
    {
      v2 = *((_DWORD *)hz + 1);
      if ( *(_DWORD *)(v2 + 4) != -1 )
        unzCloseCurrentFile(file: *(unz_s **)v2);
      v3 = *(unz_s **)v2;
      *(_DWORD *)(v2 + 4) = -1;
      if ( v3 != nullptr )
        unzClose(file: v3);
      *(_DWORD *)v2 = 0;
      lasterrorU = 0;
      free(pMem: (void *)v2);
      free(pMem: hz);
      return lasterrorU;
    }
    else
    {
      lasterrorU = 0x80000;
      return 0x80000;
    }
  }
  else
  {
    lasterrorU = 0x10000;
    return 0x10000;
  }
}

} // namespace engine_xlsp
