// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/xzip.cpp
// Functions: 54
// ============================================================

#include "public\xzip.h"

//------------------------------------------------------------------------------
// Address: 0x101FAFB0
// Name: public: TTreeState::TTreeState(void)
// Source: json
//------------------------------------------------------------------------------
TTreeState *__thiscall TTreeState::TTreeState(TTreeState *this)
{
  tree_desc a; // 0:^8.28

  a.static_tree = this->static_ltree;
  a.dyn_tree = (ct_data *)this;
  a.extra_bits = extra_lbits;
  *(_QWORD *)&a.extra_base = 0x11E00000101LL;
  *(_QWORD *)&a.max_length = 15;
  this->l_desc = a;
  a.dyn_tree = this->dyn_dtree;
  a.static_tree = this->static_dtree;
  a.extra_bits = extra_dbits;
  a.extra_base = 0;
  a.elems = 30;
  this->d_desc = a;
  a.dyn_tree = this->bl_tree;
  a.static_tree = nullptr;
  a.extra_bits = extra_blbits;
  a.extra_base = 0;
  a.elems = 19;
  a.max_length = 7;
  this->bl_desc = a;
  this->last_lit = 0;
  this->last_dist = 0;
  this->last_flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FB090
// Name: void init_block(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl init_block(TState *state)
{
  TTreeState *p_ts; // ecx
  int i; // edx
  ct_data *dyn_dtree; // ecx
  int j; // edx
  ct_data *bl_tree; // ecx
  int k; // edx

  p_ts = &state->ts;
  for ( i = 286; i != 0; --i )
  {
    p_ts->dyn_ltree[0].fc.freq = 0;
    p_ts = (TTreeState *)((char *)p_ts + 4);
  }
  dyn_dtree = state->ts.dyn_dtree;
  for ( j = 30; j != 0; --j )
  {
    dyn_dtree->fc.freq = 0;
    ++dyn_dtree;
  }
  bl_tree = state->ts.bl_tree;
  for ( k = 19; k != 0; --k )
  {
    bl_tree->fc.freq = 0;
    ++bl_tree;
  }
  state->ts.dyn_ltree[256].fc.freq = 1;
  state->ts.static_len = 0;
  state->ts.opt_len = 0;
  state->ts.last_flags = 0;
  state->ts.last_dist = 0;
  state->ts.last_lit = 0;
  *(_WORD *)&state->ts.flags = 256;
}

//------------------------------------------------------------------------------
// Address: 0x101FB120
// Name: void pqdownheap(class TState __near &,struct ct_data __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl pqdownheap(TState *state, ct_data *tree, int k)
{
  int heap_len; // edx
  int v4; // edi
  int v5; // ecx
  bool v6; // cc
  int v7; // esi
  ct_data::<unnamed_type_fc> v8; // dx
  ct_data::<unnamed_type_fc> v9; // bx
  int v10; // esi
  ct_data::<unnamed_type_fc> v11; // dx
  ct_data::<unnamed_type_fc> v12; // bx
  int v13; // edx
  int v14; // edx
  int v15; // esi

  heap_len = state->ts.heap_len;
  v4 = state->ts.heap[k];
  v5 = 2 * k;
  v6 = 2 * k < heap_len;
  if ( 2 * k > heap_len )
  {
    state->ts.heap[k] = v4;
  }
  else
  {
    while ( 1 )
    {
      if ( v6 )
      {
        v7 = state->ts.heap[v5 + 1];
        v8.freq = (unsigned __int16)tree[v7].fc;
        v9.freq = (unsigned __int16)tree[state->ts.heap[v5]].fc;
        if ( v8.freq < v9.freq || v8.freq == v9.freq && state->ts.depth[v7] <= state->ts.depth[state->ts.heap[v5]] )
          ++v5;
      }
      v10 = state->ts.heap[v5];
      v11.freq = (unsigned __int16)tree[v4].fc;
      v12.freq = (unsigned __int16)tree[v10].fc;
      if ( v11.freq < v12.freq )
        break;
      if ( v11.freq == v12.freq )
      {
        v13 = v4;
        if ( state->ts.depth[v4] <= state->ts.depth[v10] )
          goto LABEL_13;
      }
      state->ts.heap[k] = v10;
      v14 = state->ts.heap_len;
      v15 = v5;
      v5 *= 2;
      k = v15;
      v6 = v5 < v14;
      if ( v5 > v14 )
      {
        state->ts.heap[v15] = v4;
        return;
      }
    }
    v13 = v4;
LABEL_13:
    state->ts.heap[k] = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB200
// Name: void gen_bitlen(class TState __near &,struct tree_desc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl gen_bitlen(TState *state, tree_desc *desc)
{
  int max_length; // esi
  ct_data *dyn_tree; // edi
  int v5; // ebx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // esi
  int freq; // ebx
  unsigned __int16 *v11; // esi
  int v12; // ecx
  _WORD *i; // edx
  int v14; // ebx
  int *v15; // edx
  int v16; // ecx
  int dad; // esi
  ct_data::<unnamed_type_dl> *p_dl; // edx
  unsigned __int16 v19; // di
  const int *extra; // [esp+Ch] [ebp-20h]
  const int *extraa; // [esp+Ch] [ebp-20h]
  int base; // [esp+10h] [ebp-1Ch]
  ct_data *tree; // [esp+14h] [ebp-18h]
  int max_code; // [esp+18h] [ebp-14h]
  int v25; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v26; // [esp+1Ch] [ebp-10h]
  ct_data *stree; // [esp+20h] [ebp-Ch]
  int h; // [esp+24h] [ebp-8h]
  int overflow; // [esp+28h] [ebp-4h]
  int *bits; // [esp+34h] [ebp+8h]
  int bitsa; // [esp+34h] [ebp+8h]
  int n; // [esp+38h] [ebp+Ch]
  int na; // [esp+38h] [ebp+Ch]

  extra = desc->extra_bits;
  max_code = desc->max_code;
  base = desc->extra_base;
  stree = desc->static_tree;
  max_length = desc->max_length;
  dyn_tree = desc->dyn_tree;
  *(_DWORD *)state->ts.bl_count = 0;
  *(_DWORD *)&state->ts.bl_count[2] = 0;
  *(_DWORD *)&state->ts.bl_count[4] = 0;
  *(_DWORD *)&state->ts.bl_count[6] = 0;
  *(_DWORD *)&state->ts.bl_count[8] = 0;
  *(_DWORD *)&state->ts.bl_count[10] = 0;
  *(_DWORD *)&state->ts.bl_count[12] = 0;
  *(_DWORD *)&state->ts.bl_count[14] = 0;
  dyn_tree[state->ts.heap[state->ts.heap_max]].dl.dad = 0;
  v5 = 0;
  v6 = state->ts.heap_max + 1;
  tree = dyn_tree;
  n = max_length;
  overflow = 0;
  if ( v6 < 573 )
  {
    bits = &state->ts.heap[v6];
    v25 = 573 - v6;
    h = 573;
    do
    {
      v7 = *bits;
      v8 = dyn_tree[dyn_tree[*bits].dl.dad].dl.dad + 1;
      if ( v8 > max_length )
      {
        ++v5;
        v8 = max_length;
        overflow = v5;
      }
      dyn_tree[v7].dl.dad = v8;
      if ( v7 <= max_code )
      {
        ++state->ts.bl_count[v8];
        v9 = 0;
        if ( v7 >= base )
          v9 = extra[v7 - base];
        freq = dyn_tree[v7].fc.freq;
        state->ts.opt_len += freq * (v9 + v8);
        if ( stree != nullptr )
          state->ts.static_len += freq * (v9 + stree[v7].dl.dad);
        max_length = n;
        v5 = overflow;
      }
      ++bits;
      --v25;
    }
    while ( v25 != 0 );
    if ( v5 != 0 )
    {
      v11 = &state->ts.bl_count[max_length];
      do
      {
        v12 = n - 1;
        for ( i = (_WORD *)&state->ts.bl_desc.max_code + n + 1; *i == 0; --v12 )
          --i;
        state->ts.bl_count[v12 + 1] += 2;
        --state->ts.bl_count[v12];
        --*v11;
        v5 -= 2;
      }
      while ( v5 > 0 );
      v14 = n;
      bitsa = n;
      if ( n != 0 )
      {
        v26 = v11;
        do
        {
          na = *v11;
          if ( *v11 != 0 )
          {
            v15 = &state->ts.heap[h];
            do
            {
              v16 = *(v15 - 1);
              --h;
              extraa = --v15;
              if ( v16 <= max_code )
              {
                dad = dyn_tree[v16].dl.dad;
                p_dl = &dyn_tree[v16].dl;
                v19 = v14;
                if ( (_WORD)dad != (_WORD)v14 )
                {
                  state->ts.opt_len += tree[v16].fc.freq * (v14 - dad);
                  v14 = bitsa;
                  p_dl->dad = v19;
                }
                --na;
                dyn_tree = tree;
                v15 = (int *)extraa;
              }
            }
            while ( na != 0 );
          }
          --v14;
          v11 = v26 - 1;
          bitsa = v14;
          --v26;
        }
        while ( v14 != 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB410
// Name: void scan_tree(class TState __near &,struct ct_data __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl scan_tree(TState *state, ct_data *tree, int max_code)
{
  int v3; // edx
  int v4; // ecx
  int v5; // esi
  int freq; // ebx
  int v7; // eax
  int nextlen; // [esp+Ch] [ebp-8h]
  int prevlen; // [esp+10h] [ebp-4h]
  ct_data *treea; // [esp+20h] [ebp+Ch]
  int max_codea; // [esp+24h] [ebp+10h]

  v3 = 0;
  prevlen = -1;
  nextlen = tree->dl.dad;
  v4 = 7;
  v5 = 4;
  if ( tree->dl.dad == 0 )
  {
    v4 = 138;
    v5 = 3;
  }
  tree[max_code + 1].dl.dad = -1;
  if ( max_code >= 0 )
  {
    freq = nextlen;
    treea = (ct_data *)((char *)tree + 6);
    max_codea = max_code + 1;
    do
    {
      v7 = freq;
      freq = treea->fc.freq;
      if ( ++v3 >= v4 || v7 != freq )
      {
        if ( v3 >= v5 )
        {
          if ( v7 != 0 )
          {
            if ( v7 != prevlen )
              ++state->ts.bl_tree[v7].fc.freq;
            ++state->ts.bl_tree[16].fc.freq;
          }
          else if ( v3 > 10 )
          {
            ++state->ts.bl_tree[18].fc.freq;
          }
          else
          {
            ++state->ts.bl_tree[17].fc.freq;
          }
        }
        else
        {
          state->ts.bl_tree[v7].fc.freq += v3;
        }
        v3 = 0;
        prevlen = v7;
        if ( freq != 0 )
        {
          if ( v7 == freq )
          {
            v4 = 6;
            v5 = 3;
          }
          else
          {
            v4 = 7;
            v5 = 4;
          }
        }
        else
        {
          v4 = 138;
          v5 = 3;
        }
      }
      ++treea;
      --max_codea;
    }
    while ( max_codea != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB4F0
// Name: int ct_tally(class TState __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ct_tally(TState *state, int dist, int lc)
{
  int v4; // eax
  unsigned __int8 v5; // bl
  unsigned __int8 v6; // dl
  unsigned __int8 flag_bit; // al
  unsigned int last_lit; // eax
  int v9; // edi
  const int *v10; // edx
  ct_data *v11; // esi
  unsigned int v12; // edi
  unsigned int in_length; // [esp+Ch] [ebp-4h]
  TState *statea; // [esp+18h] [ebp+8h]
  int lca; // [esp+20h] [ebp+10h]

  state->ts.l_buf[state->ts.last_lit++] = lc;
  if ( dist != 0 )
  {
    v4 = dist - 1;
    if ( (unsigned __int16)(dist - 1) >= 0x7EFAu
      || (unsigned __int16)lc > 0xFFu
      || (v4 >= 256 ? (v5 = state->ts.dist_code[(v4 >> 7) + 256]) : (v5 = state->ts.dist_code[v4]), v5 >= 0x1Eu) )
    {
      state->err = "ct_tally: bad match";
    }
    ++state->ts.dyn_ltree[state->ts.length_code[lc] + 257].fc.freq;
    if ( v4 >= 256 )
      v6 = state->ts.dist_code[(v4 >> 7) + 256];
    else
      v6 = state->ts.dist_code[v4];
    ++state->ts.dyn_dtree[v6].fc.freq;
    state->ts.d_buf[state->ts.last_dist] = v4;
    flag_bit = state->ts.flag_bit;
    ++state->ts.last_dist;
    state->ts.flags |= flag_bit;
  }
  else
  {
    ++state->ts.dyn_ltree[lc].fc.freq;
  }
  state->ts.flag_bit *= 2;
  if ( (state->ts.last_lit & 7) == 0 )
  {
    state->ts.flag_buf[state->ts.last_flags++] = state->ts.flags;
    *(_WORD *)&state->ts.flags = 256;
  }
  if ( state->level > 2 )
  {
    last_lit = state->ts.last_lit;
    if ( (last_lit & 0xFFF) == 0 )
    {
      v9 = 8 * last_lit;
      v10 = &extra_dbits[1];
      in_length = state->ds.strstart - state->ds.block_start;
      lca = 0;
      statea = nullptr;
      v11 = &state->ts.dyn_dtree[1];
      do
      {
        v9 += (*(v10 - 1) + 5) * v11[-1].fc.freq;
        statea = (TState *)((char *)statea + v11->fc.freq * (*v10 + 5));
        lca += (v10[1] + 5) * v11[1].fc.freq;
        v10 += 3;
        v11 += 3;
      }
      while ( (int)v10 < (int)&extra_blbits[1] );
      v12 = (unsigned int)statea + lca + v9;
      if ( state->ts.last_dist < state->ts.last_lit >> 1 && ((v12 >> 2) & 0x3FFFFFFE) < (in_length & 0xFFFFFFFE) )
        return true;
    }
  }
  return state->ts.last_lit == 0x7FFF || state->ts.last_dist == 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x101FB6F0
// Name: void set_file_type(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_file_type(TState *state)
{
  int v2; // ecx
  int v3; // edi
  int v4; // ebx
  ct_data *v5; // edx
  ct_data *v6; // edx
  int i; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]
  int statea; // [esp+1Ch] [ebp+8h]
  TState *stateb; // [esp+1Ch] [ebp+8h]

  v2 = state->ts.dyn_ltree[0].fc.freq
     + state->ts.dyn_ltree[1].fc.freq
     + state->ts.dyn_ltree[2].fc.freq
     + state->ts.dyn_ltree[3].fc.freq
     + state->ts.dyn_ltree[4].fc.freq
     + state->ts.dyn_ltree[5].fc.freq
     + state->ts.dyn_ltree[6].fc.freq;
  v3 = 0;
  v4 = 0;
  v5 = &state->ts.dyn_ltree[8];
  for ( statea = 60; statea != 0; --statea )
  {
    v3 += v5[-1].fc.freq;
    v4 += v5->fc.freq;
    v5 += 2;
  }
  stateb = nullptr;
  v8 = 0;
  v6 = &state->ts.dyn_ltree[129];
  for ( i = 64; i != 0; --i )
  {
    stateb = (TState *)((char *)stateb + v6[-1].fc.freq);
    v8 += v6->fc.freq;
    v6 += 2;
  }
  *state->ts.file_type = (v3 + v4 + (unsigned int)state->ts.dyn_ltree[127].fc.freq) >> 2 >= (unsigned int)stateb
                                                                                          + v8
                                                                                          + v2;
}

//------------------------------------------------------------------------------
// Address: 0x101FB7A0
// Name: void send_bits(class TState __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl send_bits(TState *state, unsigned int value, int length)
{
  char v3; // dl
  int bi_valid; // ecx
  unsigned int *p_out_offset; // edi

  v3 = length;
  if ( (unsigned int)(length - 1) > 0xE )
    state->err = "invalid length";
  bi_valid = state->bs.bi_valid;
  state->bs.bits_sent += length;
  state->bs.bi_buf |= value << bi_valid;
  state->bs.bi_valid = bi_valid + length;
  if ( bi_valid + length > 16 )
  {
    p_out_offset = &state->bs.out_offset;
    if ( state->bs.out_offset >= state->bs.out_size - 1 )
    {
      state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
      v3 = length;
    }
    if ( *p_out_offset < state->bs.out_size - 1 )
    {
      state->bs.out_buf[*p_out_offset] = state->bs.bi_buf;
      state->bs.out_buf[++*p_out_offset] = BYTE1(state->bs.bi_buf);
      ++*p_out_offset;
      v3 = length;
    }
    state->bs.bi_valid -= 16;
    state->bs.bi_buf = value >> (v3 - LOBYTE(state->bs.bi_valid));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB860
// Name: void bi_windup(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl bi_windup(TState *state)
{
  int bi_valid; // eax
  unsigned int *p_out_offset; // edi
  unsigned int v3; // ecx

  bi_valid = state->bs.bi_valid;
  if ( bi_valid <= 8 )
  {
    if ( bi_valid > 0 )
    {
      p_out_offset = &state->bs.out_offset;
      if ( state->bs.out_offset >= state->bs.out_size )
        state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
      if ( *p_out_offset < state->bs.out_size )
      {
        state->bs.out_buf[*p_out_offset] = state->bs.bi_buf;
        goto LABEL_11;
      }
    }
  }
  else
  {
    p_out_offset = &state->bs.out_offset;
    if ( state->bs.out_offset >= state->bs.out_size - 1 )
      state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
    if ( *p_out_offset < state->bs.out_size - 1 )
    {
      state->bs.out_buf[*p_out_offset] = state->bs.bi_buf;
      state->bs.out_buf[++*p_out_offset] = BYTE1(state->bs.bi_buf);
LABEL_11:
      ++*p_out_offset;
    }
  }
  if ( state->bs.flush_flg != 0 )
    state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
  v3 = (state->bs.bits_sent + 7) & 0xFFFFFFF8;
  state->bs.bi_buf = 0;
  state->bs.bi_valid = 0;
  state->bs.bits_sent = v3;
}

//------------------------------------------------------------------------------
// Address: 0x101FB960
// Name: void copy_block(class TState __near &,char __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl copy_block(TState *state, char *block, unsigned int len, int header)
{
  unsigned int *p_out_offset; // edi
  unsigned int (__cdecl *flush_outbuf)(void *, const char *, unsigned int *); // ecx
  unsigned int out_offset; // eax
  void *param; // [esp-18h] [ebp-24h]

  bi_windup(state);
  if ( header != 0 )
  {
    p_out_offset = &state->bs.out_offset;
    if ( state->bs.out_offset >= state->bs.out_size - 1 )
      state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
    if ( *p_out_offset < state->bs.out_size - 1 )
    {
      state->bs.out_buf[*p_out_offset] = len;
      state->bs.out_buf[++*p_out_offset] = BYTE1(len);
      ++*p_out_offset;
    }
    if ( *p_out_offset >= state->bs.out_size - 1 )
      state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
    if ( *p_out_offset < state->bs.out_size - 1 )
    {
      state->bs.out_buf[*p_out_offset] = ~(_BYTE)len;
      state->bs.out_buf[++*p_out_offset] = (unsigned __int16)~(_WORD)len >> 8;
      ++*p_out_offset;
    }
    state->bs.bits_sent += 32;
  }
  if ( state->bs.flush_flg != 0 )
  {
    state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
    flush_outbuf = state->flush_outbuf;
    param = state->param;
    state->bs.out_offset = len;
    flush_outbuf(a1: param, a2: block, a3: &state->bs.out_offset);
    state->bs.bits_sent += 8 * len;
  }
  else
  {
    out_offset = state->bs.out_offset;
    if ( out_offset + len <= state->bs.out_size )
    {
      memcpy(dst: (unsigned __int8 *)&state->bs.out_buf[out_offset], src: (unsigned __int8 *)block, count: len);
      state->bs.out_offset += len;
      state->bs.bits_sent += 8 * len;
    }
    else
    {
      state->bs.bits_sent += 8 * len;
      state->err = "output buffer too small for in-memory compression";
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBAC0
// Name: int longest_match(class TState __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl longest_match(TState *state, unsigned int cur_match)
{
  unsigned int strstart; // eax
  unsigned int prev_length; // edi
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v7; // edx
  char *v8; // ecx
  unsigned __int8 *v9; // edx
  char v10; // bl
  char v11; // bl
  char v12; // bl
  char v13; // bl
  char v14; // bl
  char v15; // bl
  char v16; // bl
  char v17; // bl
  int v18; // edx
  unsigned int limit; // [esp+Ch] [ebp-Ch]
  unsigned int chain_length; // [esp+10h] [ebp-8h]
  unsigned __int8 scan_end; // [esp+17h] [ebp-1h]
  char scan_end1_3; // [esp+23h] [ebp+Bh]

  chain_length = state->ds.max_chain_length;
  strstart = state->ds.strstart;
  prev_length = state->ds.prev_length;
  v5 = &state->ds.window[strstart];
  if ( strstart <= 0x7EFA )
    limit = 0;
  else
    limit = strstart - 32506;
  scan_end1_3 = v5[prev_length - 1];
  scan_end = v5[prev_length];
  if ( prev_length >= state->ds.good_match )
    chain_length >>= 2;
  if ( strstart > state->ds.window_size - 262 )
    state->err = "insufficient lookahead";
  do
  {
    if ( cur_match >= state->ds.strstart )
      state->err = "no future";
    v7 = &state->ds.window[cur_match];
    if ( v7[prev_length] == scan_end
      && v7[prev_length - 1] == scan_end1_3
      && *v7 == *v5
      && state->ds.window[cur_match + 1] == v5[1] )
    {
      v8 = (char *)(v5 + 2);
      v9 = &state->ds.window[cur_match + 2];
      do
      {
        v10 = *++v8;
        if ( v10 != v9[1] )
          break;
        v11 = *++v8;
        if ( v11 != v9[2] )
          break;
        v12 = *++v8;
        if ( v12 != v9[3] )
          break;
        v13 = *++v8;
        if ( v13 != v9[4] )
          break;
        v14 = *++v8;
        if ( v14 != v9[5] )
          break;
        v15 = *++v8;
        if ( v15 != v9[6] )
          break;
        v16 = *++v8;
        if ( v16 != v9[7] )
          break;
        v17 = *++v8;
        v9 += 8;
        if ( v17 != *v9 )
          break;
      }
      while ( v8 < (char *)&state->ds.window[state->ds.strstart + 258] );
      if ( v8 > (char *)&state->bs.bits_sent + state->ds.window_size + 3 )
        state->err = "wild scan";
      v18 = v8 - (char *)&state->ds.window[state->ds.strstart + 258] + 258;
      v5 = &state->ds.window[state->ds.strstart];
      if ( v18 > (int)prev_length )
      {
        state->ds.match_start = cur_match;
        prev_length = v18;
        if ( v18 >= state->ds.nice_match )
          return prev_length;
        scan_end1_3 = v5[v18 - 1];
        scan_end = v5[v18];
      }
    }
    cur_match = state->ds.prev[cur_match & 0x7FFF];
    if ( cur_match <= limit )
      break;
    --chain_length;
  }
  while ( chain_length != 0 );
  return prev_length;
}

//------------------------------------------------------------------------------
// Address: 0x101FBC70
// Name: void fill_window(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl fill_window(TState *state)
{
  unsigned int strstart; // eax
  unsigned int v2; // edi
  unsigned int *head; // eax
  int i; // edx
  int v5; // ecx
  unsigned int *prev; // eax
  int j; // edx
  int v8; // ecx
  unsigned int v9; // eax

  do
  {
    strstart = state->ds.strstart;
    v2 = state->ds.window_size - strstart - state->ds.lookahead;
    if ( v2 == -1 )
    {
      v2 = -2;
    }
    else if ( strstart >= 0xFEFA && state->ds.sliding != 0 )
    {
      memcpy(dst: state->ds.window, src: &state->ds.window[0x8000], count: 0x8000u);
      state->ds.match_start -= 0x8000;
      state->ds.strstart -= 0x8000;
      state->ds.block_start -= 0x8000;
      head = state->ds.head;
      for ( i = 0x8000; i != 0; --i )
      {
        if ( *head < 0x8000 )
          v5 = 0;
        else
          v5 = *head - 0x8000;
        *head++ = v5;
      }
      prev = state->ds.prev;
      for ( j = 0x8000; j != 0; --j )
      {
        if ( *prev < 0x8000 )
          v8 = 0;
        else
          v8 = *prev - 0x8000;
        *prev++ = v8;
      }
      v2 += 0x8000;
    }
    if ( state->ds.eofile != 0 )
      break;
    if ( v2 < 2 )
      state->err = "more < 2";
    v9 = state->readfunc(a1: state, a2: (char *)&state->ds.window[state->ds.strstart + state->ds.lookahead], a3: v2);
    if ( v9 == 0 || v9 == -1 )
      state->ds.eofile = 1;
    else
      state->ds.lookahead += v9;
  }
  while ( state->ds.lookahead < 0x106 && state->ds.eofile == 0 );
}

//------------------------------------------------------------------------------
// Address: 0x101FBDD0
// Name: int putlocal(struct zlist __near *,unsigned int (*)(void __near *,char const __near *,unsigned int),void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl putlocal(zlist *z, unsigned int (__cdecl *wfunc)(void *, const char *, unsigned int), void *param)
{
  void *v3; // esi
  unsigned int (__cdecl *v4)(void *, const char *, unsigned int); // edi
  char _putsh_c; // [esp+Fh] [ebp-1h] BYREF

  v3 = param;
  v4 = wfunc;
  _putsh_c = 80;
  wfunc(a1: param, a2: &_putsh_c, a3: 1u);
  _putsh_c = 75;
  v4(a1: v3, a2: &_putsh_c, a3: 1u);
  HIBYTE(wfunc) = 3;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 4;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->ver;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->ver);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->lflg;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->lflg);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->how;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->how);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->tim;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->tim);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->tim);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->tim);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->crc;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->siz;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->len;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->nam;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->nam);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->ext;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->ext);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  if ( v4(a1: v3, a2: z->iname, a3: z->nam) == z->nam && (z->ext == 0 || v4(a1: v3, a2: z->extra, a3: z->ext) == z->ext) )
    return 0;
  else
    return 10;
}

//------------------------------------------------------------------------------
// Address: 0x101FC010
// Name: int putextended(struct zlist __near *,unsigned int (*)(void __near *,char const __near *,unsigned int),void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl putextended(zlist *z, unsigned int (__cdecl *wfunc)(void *, const char *, unsigned int), void *param)
{
  void *v3; // esi
  unsigned int (__cdecl *v4)(void *, const char *, unsigned int); // edi
  char _putsh_c; // [esp+Fh] [ebp-1h] BYREF

  v3 = param;
  v4 = wfunc;
  _putsh_c = 80;
  wfunc(a1: param, a2: &_putsh_c, a3: 1u);
  _putsh_c = 75;
  v4(a1: v3, a2: &_putsh_c, a3: 1u);
  HIBYTE(wfunc) = 7;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 8;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->crc;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->siz;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->len;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FC130
// Name: int putcentral(struct zlist __near *,unsigned int (*)(void __near *,char const __near *,unsigned int),void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl putcentral(zlist *z, unsigned int (__cdecl *wfunc)(void *, const char *, unsigned int), void *param)
{
  unsigned int (__cdecl *v3)(void *, const char *, unsigned int); // ebx
  void *v4; // edi
  char _putsh_c; // [esp+Fh] [ebp-1h] BYREF

  v3 = wfunc;
  v4 = param;
  _putsh_c = 80;
  wfunc(a1: param, a2: &_putsh_c, a3: 1u);
  _putsh_c = 75;
  v3(a1: v4, a2: &_putsh_c, a3: 1u);
  HIBYTE(wfunc) = 1;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 2;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->vem;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->vem);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->ver;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->ver);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->flg;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->flg);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->how;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->how);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->tim;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->tim);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->tim);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->tim);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->crc;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->crc);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->crc);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->crc);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->siz;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->siz);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->siz);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->siz);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->len;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->len);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->len);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->len);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->nam;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->nam);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->cext;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->cext);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->com;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->com);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->dsk;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->dsk);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->att;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->att);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->atx;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->atx);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->atx);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->atx);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->off;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->off);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->off);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->off);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  if ( v3(a1: v4, a2: z->iname, a3: z->nam) == z->nam
    && (z->cext == 0 || v3(a1: v4, a2: z->cextra, a3: z->cext) == z->cext)
    && (z->com == 0 || v3(a1: v4, a2: z->comment, a3: z->com) == z->com) )
  {
    return 0;
  }
  else
  {
    return 10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FC490
// Name: int putend(int,unsigned long,unsigned long,unsigned int,char __near *,unsigned int (*)(void __near *,char const __near *,unsigned int),void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl putend(
        int n,
        unsigned int s,
        unsigned int c,
        unsigned int m,
        char *z,
        unsigned int (__cdecl *wfunc)(void *, const char *, unsigned int),
        void *param)
{
  void *v7; // esi
  unsigned int (__cdecl *v8)(void *, const char *, unsigned int); // edi
  int v9; // ebx
  unsigned int v10; // ebx
  unsigned int v11; // ebx
  unsigned int v12; // ebx
  char _putsh_c; // [esp+Fh] [ebp-1h] BYREF

  v7 = param;
  v8 = wfunc;
  _putsh_c = 80;
  wfunc(a1: param, a2: &_putsh_c, a3: 1u);
  _putsh_c = 75;
  v8(a1: v7, a2: &_putsh_c, a3: 1u);
  HIBYTE(wfunc) = 5;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 6;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 0;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 0;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 0;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 0;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  v9 = n;
  HIBYTE(wfunc) = n;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  v9 >>= 8;
  HIBYTE(wfunc) = v9;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(n) = n;
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = v9;
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  v10 = s;
  HIBYTE(n) = s;
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = BYTE1(v10);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = BYTE2(v10);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = HIBYTE(v10);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  v11 = c;
  HIBYTE(n) = c;
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = BYTE1(v11);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = BYTE2(v11);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = HIBYTE(v11);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  v12 = m;
  HIBYTE(n) = m;
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = BYTE1(v12);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  if ( v12 == 0 || v8(a1: v7, a2: z, a3: v12) == v12 )
    return 0;
  else
    return 10;
}

//------------------------------------------------------------------------------
// Address: 0x101FC620
// Name: unsigned long crc32(unsigned long,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl crc32(unsigned int crc, const unsigned __int8 *buf, unsigned int len)
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
      v8 = crc_table_0[(unsigned __int8)(v6 ^ *v3)] ^ (v6 >> 8);
      v9 = crc_table_0[(unsigned __int8)(v8 ^ v3[1])] ^ (v8 >> 8);
      v10 = crc_table_0[(unsigned __int8)(v9 ^ v3[2])] ^ (v9 >> 8);
      v11 = crc_table_0[(unsigned __int8)(v10 ^ v3[3])] ^ (v10 >> 8);
      v12 = crc_table_0[(unsigned __int8)(v11 ^ v3[4])] ^ (v11 >> 8);
      v13 = crc_table_0[(unsigned __int8)(v12 ^ v3[5])] ^ (v12 >> 8);
      v14 = crc_table_0[(unsigned __int8)(v13 ^ v3[6])] ^ (v13 >> 8);
      v6 = crc_table_0[(unsigned __int8)(v14 ^ v3[7])] ^ (v14 >> 8);
      v3 += 8;
      v5 -= 8;
      --v7;
    }
    while ( v7 != 0 );
  }
  for ( ; v5 != 0; --v5 )
    v6 = crc_table_0[(unsigned __int8)(v6 ^ *v3++)] ^ (v6 >> 8);
  return ~v6;
}

//------------------------------------------------------------------------------
// Address: 0x101FC730
// Name: bool HasZipSuffix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HasZipSuffix(const char *fn)
{
  unsigned int v1; // eax
  const char *v2; // esi
  bool v3; // zf

  v1 = strlen(fn);
  v2 = &fn[v1];
  v3 = &fn[v1] == fn;
  if ( &fn[v1] > fn )
  {
    do
    {
      if ( *v2 == 46 )
        break;
      --v2;
    }
    while ( v2 > fn );
    v3 = v2 == fn;
  }
  if ( v3 && *v2 != 46 )
    return false;
  if ( _stricmp(dst: v2, src: ".Z") == 0
    || _stricmp(dst: v2, src: ".zip") == 0
    || _stricmp(dst: v2, src: ".zoo") == 0
    || _stricmp(dst: v2, src: ".arc") == 0
    || _stricmp(dst: v2, src: ".lzh") == 0
    || _stricmp(dst: v2, src: ".arj") == 0
    || _stricmp(dst: v2, src: ".gz") == 0 )
  {
    return true;
  }
  return _stricmp(dst: v2, src: ".tgz") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FC810
// Name: __int64 filetime2timet(struct _FILETIME)
// Source: json
//------------------------------------------------------------------------------
__int64 __cdecl filetime2timet(_FILETIME ft)
{
  unsigned __int16 wYear; // ax
  tm tm; // [esp+0h] [ebp-34h] BYREF
  _SYSTEMTIME st; // [esp+24h] [ebp-10h] BYREF

  FileTimeToSystemTime(lpFileTime: &ft, lpSystemTime: &st);
  wYear = st.wYear;
  if ( st.wYear >= 0x7B2u )
  {
    if ( st.wYear >= 0x7F6u )
    {
      wYear = 2037;
      *(_DWORD *)&st.wYear = 788469;
      st.wDay = 31;
    }
  }
  else
  {
    wYear = 1970;
    *(_DWORD *)&st.wYear = 67506;
    st.wDay = 1;
  }
  tm.tm_sec = st.wSecond;
  tm.tm_min = st.wMinute;
  tm.tm_hour = st.wHour;
  tm.tm_mday = st.wDay;
  tm.tm_mon = st.wMonth - 1;
  tm.tm_year = wYear - 1900;
  tm.tm_isdst = 0;
  return _mktime64(tb: &tm);
}

//------------------------------------------------------------------------------
// Address: 0x101FC8B0
// Name: unsigned long GetFileInfo(void __near *,unsigned long __near *,long __near *,struct iztimes __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetFileInfo(void *hf, unsigned int *attr, int *size, iztimes *times, unsigned int *timestamp)
{
  int v6; // edi
  unsigned int v7; // edi
  int v8; // edi
  __int64 v9; // rax
  unsigned int dwHighDateTime; // ecx
  __int64 v11; // rax
  unsigned int dwLowDateTime; // ecx
  _FILETIME v13; // [esp-18h] [ebp-68h]
  _FILETIME v14; // [esp-10h] [ebp-60h]
  _BY_HANDLE_FILE_INFORMATION bhi; // [esp+4h] [ebp-4Ch] BYREF
  unsigned int signature; // [esp+38h] [ebp-18h] BYREF
  unsigned int hpos; // [esp+3Ch] [ebp-14h] BYREF
  unsigned int hsize; // [esp+40h] [ebp-10h]
  unsigned int red; // [esp+44h] [ebp-Ch] BYREF
  int dostime; // [esp+48h] [ebp-8h] BYREF
  unsigned __int16 dosdate; // [esp+4Ch] [ebp-4h] BYREF

  if ( GetFileType(hFile: hf) != 1 )
    return 0x1000000;
  if ( !GetFileInformationByHandle(hFile: hf, lpFileInformation: &bhi) )
    return 512;
  FileTimeToLocalFileTime(lpFileTime: &bhi.ftLastAccessTime, lpLocalFileTime: &bhi.ftLastAccessTime);
  FileTimeToLocalFileTime(lpFileTime: &bhi.ftLastWriteTime, lpLocalFileTime: &bhi.ftLastWriteTime);
  FileTimeToLocalFileTime(lpFileTime: &bhi.ftCreationTime, lpLocalFileTime: &bhi.ftCreationTime);
  v6 = 0;
  if ( (bhi.dwFileAttributes & 1) != 0 )
  {
    dostime = 1;
    v6 = 1;
  }
  if ( (bhi.dwFileAttributes & 2) != 0 )
    v6 |= 2u;
  if ( (bhi.dwFileAttributes & 4) != 0 )
    v6 |= 4u;
  if ( (bhi.dwFileAttributes & 0x10) != 0 )
    v6 |= 0x10u;
  if ( (bhi.dwFileAttributes & 0x20) != 0 )
    v6 |= 0x20u;
  if ( (bhi.dwFileAttributes & 0x10) != 0 )
    v7 = v6 | 0x40000000;
  else
    v7 = v6 | 0x80000000;
  v8 = v7 | 0x1000000;
  dostime = v8;
  if ( (bhi.dwFileAttributes & 1) == 0 )
  {
    v8 |= 0x800000u;
    dostime = v8;
  }
  hsize = GetFileSize(hFile: hf, lpFileSizeHigh: nullptr);
  if ( hsize > 0x28 )
  {
    SetFilePointer(hFile: hf, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 0);
    ReadFile(hFile: hf, lpBuffer: &dosdate, nNumberOfBytesToRead: 2u, lpNumberOfBytesRead: &red, lpOverlapped: nullptr);
    SetFilePointer(hFile: hf, lDistanceToMove: 36, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 0);
    ReadFile(hFile: hf, lpBuffer: &hpos, nNumberOfBytesToRead: 4u, lpNumberOfBytesRead: &red, lpOverlapped: nullptr);
    if ( dosdate == 21677 && hsize > hpos + 52 )
    {
      SetFilePointer(hFile: hf, lDistanceToMove: hpos, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 0);
      ReadFile(
        hFile: hf,
        lpBuffer: &signature,
        nNumberOfBytesToRead: 4u,
        lpNumberOfBytesRead: &red,
        lpOverlapped: nullptr);
      if ( signature == 23117 || signature == 17742 || signature == 17740 || signature == 17744 )
        dostime |= 0x400000u;
    }
    v8 = dostime;
  }
  if ( attr != nullptr )
    *attr = v8;
  if ( size != nullptr )
    *size = hsize;
  if ( times != nullptr )
  {
    v9 = filetime2timet(ft: bhi.ftLastAccessTime);
    dwHighDateTime = bhi.ftLastWriteTime.dwHighDateTime;
    HIDWORD(times->atime) = HIDWORD(v9);
    v14 = (_FILETIME)__PAIR64__(dwHighDateTime, bhi.ftLastWriteTime.dwLowDateTime);
    LODWORD(times->atime) = v9;
    v11 = filetime2timet(ft: v14);
    dwLowDateTime = bhi.ftCreationTime.dwLowDateTime;
    LODWORD(times->mtime) = v11;
    v13 = (_FILETIME)__PAIR64__(bhi.ftCreationTime.dwHighDateTime, dwLowDateTime);
    HIDWORD(times->mtime) = HIDWORD(v11);
    times->ctime = filetime2timet(ft: v13);
  }
  if ( timestamp != nullptr )
  {
    FileTimeToDosDateTime(lpFileTime: &bhi.ftLastWriteTime, lpFatDate: &dosdate, lpFatTime: (LPWORD)&dostime);
    *timestamp = (unsigned __int16)dostime | (dosdate << 16);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FCAA0
// Name: public: unsigned long TZip::Create(void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::Create(TZip *this, void *z, unsigned int len, unsigned int flags)
{
  HANDLE FileMappingA; // eax
  char *v7; // eax
  HANDLE v8; // eax
  DWORD FileType; // eax
  HANDLE FileA; // eax
  HANDLE CurrentProcess; // [esp-18h] [ebp-20h]

  if ( this->hfout != nullptr
    || this->hmapout != nullptr
    || this->obuf != nullptr
    || this->writ != 0
    || this->oerr != 0
    || this->hasputcen )
  {
    return 0x1000000;
  }
  if ( flags != 3 )
  {
    if ( flags == 1 )
    {
      CurrentProcess = GetCurrentProcess();
      v8 = GetCurrentProcess();
      if ( !DuplicateHandle(
              hSourceProcessHandle: v8,
              hSourceHandle: z,
              hTargetProcessHandle: CurrentProcess,
              lpTargetHandle: &this->hfout,
              dwDesiredAccess: 0,
              bInheritHandle: false,
              dwOptions: 2u) )
        return 256;
      FileType = GetFileType(hFile: this->hfout);
      this->ocanseek = FileType == 1;
      if ( FileType == 1 )
      {
        this->ooffset = SetFilePointer(
                          hFile: this->hfout,
                          lDistanceToMove: 0,
                          lpDistanceToMoveHigh: nullptr,
                          dwMoveMethod: 1u);
        return 0;
      }
    }
    else
    {
      if ( flags != 2 )
        return 0x10000;
      FileA = CreateFileA(
                lpFileName: (LPCSTR)z,
                dwDesiredAccess: 0x40000000u,
                dwShareMode: 0,
                lpSecurityAttributes: nullptr,
                dwCreationDisposition: 2u,
                dwFlagsAndAttributes: 0x80u,
                hTemplateFile: nullptr);
      this->hfout = FileA;
      if ( FileA == (HANDLE)-1 )
      {
        this->hfout = nullptr;
        return 512;
      }
      this->ocanseek = true;
    }
    this->ooffset = 0;
    return 0;
  }
  if ( len == 0 )
    return 196608;
  if ( z != nullptr )
  {
    this->obuf = (char *)z;
LABEL_12:
    this->mapsize = len;
    this->opos = 0;
    this->ocanseek = true;
    return 0;
  }
  FileMappingA = CreateFileMappingA(
                   hFile: (HANDLE)0xFFFFFFFF,
                   lpFileMappingAttributes: nullptr,
                   flProtect: 4u,
                   dwMaximumSizeHigh: 0,
                   dwMaximumSizeLow: len,
                   lpName: nullptr);
  this->hmapout = FileMappingA;
  if ( FileMappingA != nullptr )
  {
    v7 = (char *)MapViewOfFile(
                   hFileMappingObject: FileMappingA,
                   dwDesiredAccess: 0xF001Fu,
                   dwFileOffsetHigh: 0,
                   dwFileOffsetLow: 0,
                   dwNumberOfBytesToMap: len);
    this->obuf = v7;
    if ( v7 != nullptr )
      goto LABEL_12;
    CloseHandle(hObject: this->hmapout);
    this->hmapout = nullptr;
  }
  return 768;
}

//------------------------------------------------------------------------------
// Address: 0x101FCC20
// Name: public: unsigned int TZip::write(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::write(TZip *this, char *buf, unsigned int size)
{
  char *obuf; // ecx
  unsigned int opos; // eax
  unsigned int v6; // edi

  obuf = this->obuf;
  if ( obuf != nullptr )
  {
    opos = this->opos;
    v6 = size;
    if ( opos + size < this->mapsize )
    {
      memcpy(dst: (unsigned __int8 *)&obuf[opos], src: (unsigned __int8 *)buf, count: size);
      this->opos += v6;
      return v6;
    }
    else
    {
      this->oerr = 196608;
      return 0;
    }
  }
  else if ( this->hfout != nullptr )
  {
    WriteFile(
      hFile: this->hfout,
      lpBuffer: buf,
      nNumberOfBytesToWrite: size,
      lpNumberOfBytesWritten: &size,
      lpOverlapped: nullptr);
    return size;
  }
  else
  {
    this->oerr = 0x1000000;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCCA0
// Name: public: bool TZip::oseek(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall TZip::oseek(TZip *this, unsigned int pos)
{
  if ( this->ocanseek )
  {
    if ( this->obuf != nullptr )
    {
      if ( pos < this->mapsize )
      {
        this->opos = pos;
        return 1;
      }
      else
      {
        this->oerr = 196608;
        return 0;
      }
    }
    else if ( this->hfout != nullptr )
    {
      SetFilePointer(
        hFile: this->hfout,
        lDistanceToMove: pos + this->ooffset,
        lpDistanceToMoveHigh: nullptr,
        dwMoveMethod: 0);
      return 1;
    }
    else
    {
      this->oerr = 0x1000000;
      return 0;
    }
  }
  else
  {
    this->oerr = 0x2000000;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCD10
// Name: public: unsigned long TZip::open_handle(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::open_handle(TZip *this, void *hf, unsigned int len)
{
  void *v4; // edi
  int *p_isize; // ebx
  unsigned int result; // eax
  unsigned int v7; // eax
  __int64 v8; // rax
  int v9; // ecx
  _SYSTEMTIME st; // [esp+Ch] [ebp-18h] BYREF
  _FILETIME ft; // [esp+1Ch] [ebp-8h] BYREF

  v4 = hf;
  p_isize = &this->isize;
  this->hfin = nullptr;
  this->bufin = nullptr;
  this->selfclosehf = false;
  this->crc = 0;
  this->isize = 0;
  this->csize = 0;
  this->ired = 0;
  if ( v4 == nullptr || v4 == (void *)-1 )
    return 0x10000;
  if ( GetFileType(hFile: v4) == 1 )
  {
    result = GetFileInfo(hf: v4, attr: &this->attr, size: p_isize, times: &this->times, timestamp: &this->timestamp);
    if ( result == 0 )
    {
      SetFilePointer(hFile: v4, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 0);
      this->hfin = v4;
      this->iseekable = true;
      return 0;
    }
  }
  else
  {
    v7 = len;
    this->attr = 0x80000000;
    *p_isize = -1;
    if ( v7 != 0 )
      *p_isize = v7;
    this->iseekable = false;
    GetLocalTime(lpSystemTime: &st);
    SystemTimeToFileTime(lpSystemTime: &st, lpFileTime: &ft);
    FileTimeToDosDateTime(lpFileTime: &ft, lpFatDate: (LPWORD)&hf, lpFatTime: (LPWORD)&len);
    v8 = filetime2timet(ft);
    v9 = HIDWORD(v8);
    HIDWORD(this->times.atime) = HIDWORD(v8);
    HIDWORD(v8) = (unsigned __int16)hf;
    LODWORD(this->times.atime) = v8;
    LODWORD(this->times.mtime) = v8;
    LODWORD(this->times.ctime) = v8;
    HIDWORD(v8) = (unsigned __int16)len | (HIDWORD(v8) << 16);
    this->hfin = v4;
    HIDWORD(this->times.mtime) = v9;
    HIDWORD(this->times.ctime) = v9;
    this->timestamp = HIDWORD(v8);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FCE30
// Name: public: unsigned long TZip::open_mem(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::open_mem(TZip *this, const char *src, unsigned int len)
{
  const char *v3; // edx
  unsigned int v5; // ecx
  __int64 v6; // rax
  int v7; // ecx
  _SYSTEMTIME st; // [esp+4h] [ebp-18h] BYREF
  _FILETIME ft; // [esp+14h] [ebp-8h] BYREF

  v3 = src;
  v5 = len;
  this->hfin = nullptr;
  this->bufin = v3;
  this->selfclosehf = false;
  this->crc = 0;
  this->csize = 0;
  this->ired = 0;
  this->lenin = v5;
  this->posin = 0;
  if ( v3 == nullptr || v5 == 0 )
    return 0x10000;
  this->attr = 0x80000000;
  this->isize = v5;
  this->iseekable = true;
  GetLocalTime(lpSystemTime: &st);
  SystemTimeToFileTime(lpSystemTime: &st, lpFileTime: &ft);
  FileTimeToDosDateTime(lpFileTime: &ft, lpFatDate: (LPWORD)&src, lpFatTime: (LPWORD)&len);
  v6 = filetime2timet(ft);
  v7 = HIDWORD(v6);
  HIDWORD(this->times.atime) = HIDWORD(v6);
  HIDWORD(v6) = (unsigned __int16)src;
  LODWORD(this->times.atime) = v6;
  LODWORD(this->times.mtime) = v6;
  LODWORD(this->times.ctime) = v6;
  HIDWORD(v6) = (unsigned __int16)len | (HIDWORD(v6) << 16);
  HIDWORD(this->times.mtime) = v7;
  HIDWORD(this->times.ctime) = v7;
  this->timestamp = HIDWORD(v6);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FCEF0
// Name: public: unsigned long TZip::open_dir(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::open_dir(TZip *this)
{
  __int64 v2; // rax
  int v3; // ecx
  _SYSTEMTIME st; // [esp+4h] [ebp-20h] BYREF
  _FILETIME ft; // [esp+14h] [ebp-10h] BYREF
  unsigned __int16 dostime; // [esp+1Ch] [ebp-8h] BYREF
  unsigned __int16 dosdate; // [esp+20h] [ebp-4h] BYREF

  this->hfin = nullptr;
  this->bufin = nullptr;
  this->selfclosehf = false;
  this->crc = 0;
  this->csize = 0;
  this->ired = 0;
  this->isize = 0;
  this->iseekable = false;
  this->attr = 1103101968;
  GetLocalTime(lpSystemTime: &st);
  SystemTimeToFileTime(lpSystemTime: &st, lpFileTime: &ft);
  FileTimeToDosDateTime(lpFileTime: &ft, lpFatDate: &dosdate, lpFatTime: &dostime);
  v2 = filetime2timet(ft);
  v3 = HIDWORD(v2);
  HIDWORD(this->times.atime) = HIDWORD(v2);
  HIDWORD(v2) = dosdate;
  LODWORD(this->times.atime) = v2;
  LODWORD(this->times.mtime) = v2;
  LODWORD(this->times.ctime) = v2;
  HIDWORD(v2) = dostime | (HIDWORD(v2) << 16);
  HIDWORD(this->times.mtime) = v3;
  HIDWORD(this->times.ctime) = v3;
  this->timestamp = HIDWORD(v2);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FCF80
// Name: public: unsigned int TZip::read(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::read(TZip *this, char *buf, DWORD size)
{
  const char *bufin; // ecx
  unsigned int posin; // eax
  unsigned int lenin; // edi
  unsigned int v7; // edi
  unsigned int v8; // eax
  void *hfin; // eax
  unsigned int v11; // edi
  unsigned int crc; // eax

  bufin = this->bufin;
  if ( bufin == nullptr )
  {
    hfin = this->hfin;
    if ( hfin != nullptr )
    {
      if ( ReadFile(
             hFile: hfin,
             lpBuffer: buf,
             nNumberOfBytesToRead: size,
             lpNumberOfBytesRead: &size,
             lpOverlapped: nullptr) )
      {
        v11 = size;
        crc = this->crc;
        this->ired += size;
        this->crc = crc32(crc, (const unsigned __int8 *)buf, len: v11);
        return v11;
      }
    }
    else
    {
      this->oerr = 0x1000000;
    }
    return 0;
  }
  posin = this->posin;
  lenin = this->lenin;
  if ( posin >= lenin )
    return 0;
  v7 = lenin - posin;
  if ( v7 > size )
    v7 = size;
  memcpy(dst: (unsigned __int8 *)buf, src: (unsigned __int8 *)&bufin[posin], count: v7);
  v8 = this->crc;
  this->posin += v7;
  this->ired += v7;
  this->crc = crc32(crc: v8, (const unsigned __int8 *)buf, len: v7);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101FD020
// Name: public: unsigned long TZip::iclose(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::iclose(TZip *this)
{
  int isize; // eax

  if ( this->selfclosehf && this->hfin != nullptr )
    CloseHandle(hObject: this->hfin);
  isize = this->isize;
  this->hfin = nullptr;
  if ( isize == -1 || isize == this->ired )
  {
    this->isize = this->ired;
    return 0;
  }
  else
  {
    this->isize = this->ired;
    return 393216;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD080
// Name: public: unsigned long TZip::istore(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::istore(TZip *this)
{
  char *buf; // ebx
  unsigned int i; // edi
  char *obuf; // ecx
  unsigned int opos; // eax
  unsigned int v6; // eax
  unsigned int NumberOfBytesWritten; // [esp+Ch] [ebp-8h] BYREF
  unsigned int size; // [esp+10h] [ebp-4h]

  buf = this->buf;
  size = 0;
  for ( i = TZip::read(this, buf: this->buf, size: 0x4000u); i != 0; i = TZip::read(this, buf, size: 0x4000u) )
  {
    if ( i == -1 )
      break;
    obuf = this->obuf;
    if ( obuf != nullptr )
    {
      opos = this->opos;
      if ( opos + i < this->mapsize )
      {
        memcpy(dst: (unsigned __int8 *)&obuf[opos], src: (unsigned __int8 *)buf, count: i);
        this->opos += i;
        goto LABEL_12;
      }
      this->oerr = 196608;
    }
    else
    {
      if ( this->hfout != nullptr )
      {
        WriteFile(
          hFile: this->hfout,
          lpBuffer: buf,
          nNumberOfBytesToWrite: i,
          lpNumberOfBytesWritten: &NumberOfBytesWritten,
          lpOverlapped: nullptr);
        v6 = NumberOfBytesWritten;
        goto LABEL_11;
      }
      this->oerr = 0x1000000;
    }
    v6 = 0;
LABEL_11:
    if ( v6 != i )
      return 393216;
LABEL_12:
    size += i;
  }
  this->csize = size;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FD130
// Name: void gen_codes(class TState __near &,struct ct_data __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl gen_codes(TState *state, ct_data *tree, int max_code)
{
  __int16 v3; // ax
  int v4; // ecx
  unsigned __int16 *bl_count; // edx
  unsigned __int16 v6; // di
  int i; // esi
  int dad; // edx
  unsigned int v9; // ecx
  unsigned int v10; // eax
  int v11; // ebx
  unsigned __int16 next_code[16]; // [esp+8h] [ebp-20h]

  v3 = 0;
  v4 = 1;
  bl_count = state->ts.bl_count;
  do
  {
    v6 = 2 * (v3 + *bl_count);
    v3 = v6;
    next_code[v4++] = v6;
    ++bl_count;
  }
  while ( v4 <= 15 );
  if ( state->ts.bl_count[15] + v6 != 0x8000 )
    state->err = "inconsistent bit counts";
  for ( i = 0; i <= max_code; ++i )
  {
    dad = tree[i].dl.dad;
    if ( tree[i].dl.dad != 0 )
    {
      v9 = next_code[dad];
      next_code[dad] = v9 + 1;
      v10 = 0;
      do
      {
        v11 = v9 & 1;
        --dad;
        v9 >>= 1;
        v10 = 2 * (v11 | v10);
      }
      while ( dad > 0 );
      tree[i].fc.freq = v10 >> 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD1D0
// Name: void build_tree(class TState __near &,struct tree_desc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl build_tree(TState *state, tree_desc *desc)
{
  tree_desc *v2; // edx
  int elems; // ecx
  ct_data *static_tree; // ebx
  ct_data *dyn_tree; // edi
  int v6; // eax
  int v7; // eax
  int i; // ebx
  int heap_len; // eax
  int v10; // ebx
  int v11; // eax
  unsigned __int8 v12; // dl
  int node; // [esp+Ch] [ebp-8h]
  int max_code; // [esp+10h] [ebp-4h]

  v2 = desc;
  elems = desc->elems;
  static_tree = desc->static_tree;
  dyn_tree = desc->dyn_tree;
  v6 = 0;
  max_code = -1;
  node = elems;
  state->ts.heap_len = 0;
  state->ts.heap_max = 573;
  if ( elems > 0 )
  {
    do
    {
      if ( dyn_tree[v6].fc.freq != 0 )
      {
        state->ts.heap[++state->ts.heap_len] = v6;
        max_code = v6;
        state->ts.depth[v6] = 0;
      }
      else
      {
        dyn_tree[v6].dl.dad = 0;
      }
      ++v6;
    }
    while ( v6 < elems );
    v2 = desc;
  }
  while ( state->ts.heap_len < 2 )
  {
    if ( max_code >= 2 )
      v7 = 0;
    else
      v7 = ++max_code;
    state->ts.heap[++state->ts.heap_len] = v7;
    dyn_tree[v7].fc.freq = 1;
    state->ts.depth[v7] = 0;
    --state->ts.opt_len;
    if ( static_tree != nullptr )
      state->ts.static_len -= static_tree[v7].dl.dad;
  }
  v2->max_code = max_code;
  for ( i = state->ts.heap_len / 2; i >= 1; --i )
    pqdownheap(state, tree: dyn_tree, k: i);
  do
  {
    heap_len = state->ts.heap_len;
    v10 = state->ts.heap[1];
    state->ts.heap[1] = state->ts.heap[heap_len];
    state->ts.heap_len = heap_len - 1;
    pqdownheap(state, tree: dyn_tree, k: 1);
    v11 = state->ts.heap[1];
    --state->ts.heap_max;
    state->ts.heap[state->ts.heap_max--] = v10;
    state->ts.heap[state->ts.heap_max] = v11;
    dyn_tree[node].fc.freq = dyn_tree[v10].fc.freq + dyn_tree[v11].fc.freq;
    v12 = state->ts.depth[v10];
    if ( v12 < state->ts.depth[v11] )
      v12 = state->ts.depth[v11];
    state->ts.depth[node] = v12 + 1;
    dyn_tree[v11].dl.dad = node;
    dyn_tree[v10].dl.dad = node;
    state->ts.heap[1] = node++;
    pqdownheap(state, tree: dyn_tree, k: 1);
  }
  while ( state->ts.heap_len >= 2 );
  state->ts.heap[--state->ts.heap_max] = state->ts.heap[1];
  gen_bitlen(state, desc);
  gen_codes(state, tree: dyn_tree, max_code);
}

//------------------------------------------------------------------------------
// Address: 0x101FD3D0
// Name: void send_tree(class TState __near &,struct ct_data __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl send_tree(TState *state, ct_data *tree, int max_code)
{
  int dad; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // ecx
  ct_data::<unnamed_type_dl> *p_dl; // edx
  int v8; // edx
  unsigned int v9; // ebx
  bool v10; // zf
  int v11; // [esp+Ch] [ebp-8h]
  int prevlen; // [esp+10h] [ebp-4h]
  int nextlen; // [esp+20h] [ebp+Ch]
  ct_data::<unnamed_type_dl> *max_codea; // [esp+24h] [ebp+10h]

  dad = tree->dl.dad;
  v4 = 0;
  prevlen = -1;
  v5 = 7;
  v6 = 4;
  if ( tree->dl.dad == 0 )
  {
    v5 = 138;
    v6 = 3;
  }
  if ( max_code >= 0 )
  {
    p_dl = &tree[1].dl;
    v11 = max_code + 1;
    max_codea = &tree[1].dl;
    while ( 1 )
    {
      v8 = p_dl->dad;
      ++v4;
      nextlen = v8;
      if ( v4 >= v5 || dad != v8 )
      {
        if ( v4 >= v6 )
        {
          if ( dad != 0 )
          {
            if ( dad != prevlen )
            {
              send_bits(state, value: state->ts.bl_tree[dad].fc.freq, length: state->ts.bl_tree[dad].dl.dad);
              --v4;
            }
            v9 = v4 - 3;
            if ( v9 > 3 )
              state->err = " 3_6?";
            send_bits(state, value: state->ts.bl_tree[16].fc.freq, length: state->ts.bl_tree[16].dl.dad);
            send_bits(state, value: v9, length: 2);
          }
          else if ( v4 > 10 )
          {
            send_bits(state, value: state->ts.bl_tree[18].fc.freq, length: state->ts.bl_tree[18].dl.dad);
            send_bits(state, value: v4 - 11, length: 7);
          }
          else
          {
            send_bits(state, value: state->ts.bl_tree[17].fc.freq, length: state->ts.bl_tree[17].dl.dad);
            send_bits(state, value: v4 - 3, length: 3);
          }
        }
        else
        {
          do
          {
            send_bits(state, value: state->ts.bl_tree[dad].fc.freq, length: state->ts.bl_tree[dad].dl.dad);
            --v4;
          }
          while ( v4 != 0 );
        }
        v4 = 0;
        prevlen = dad;
        if ( nextlen != 0 )
        {
          if ( dad == nextlen )
          {
            v5 = 6;
            v6 = 3;
          }
          else
          {
            v5 = 7;
            v6 = 4;
          }
        }
        else
        {
          v5 = 138;
          v6 = 3;
        }
      }
      p_dl = max_codea + 2;
      v10 = v11-- == 1;
      max_codea += 2;
      if ( v10 )
        break;
      dad = nextlen;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD530
// Name: int build_bl_tree(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl build_bl_tree(TState *state)
{
  int result; // eax

  scan_tree(state, tree: state->ts.dyn_ltree, max_code: state->ts.l_desc.max_code);
  scan_tree(state, tree: state->ts.dyn_dtree, max_code: state->ts.d_desc.max_code);
  build_tree(state, desc: &state->ts.bl_desc);
  result = 18;
  while ( state->ts.bl_tree[bl_order[result]].dl.dad == 0 )
  {
    if ( state->ts.bl_tree[*((unsigned __int8 *)&extra_lbits[28] + result + 3)].dl.dad != 0 )
    {
      --result;
      state->ts.opt_len += 3 * result + 17;
      return result;
    }
    if ( state->ts.bl_tree[*((unsigned __int8 *)&extra_lbits[28] + result + 2)].dl.dad != 0 )
    {
      result -= 2;
      state->ts.opt_len += 3 * result + 17;
      return result;
    }
    if ( state->ts.bl_tree[*((unsigned __int8 *)&extra_lbits[28] + result + 1)].dl.dad != 0 )
    {
      result -= 3;
      break;
    }
    result -= 4;
    if ( result < 3 )
    {
      state->ts.opt_len += 3 * result + 17;
      return result;
    }
  }
  state->ts.opt_len += 3 * result + 17;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FD610
// Name: void send_all_trees(class TState __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl send_all_trees(TState *state, int lcodes, int dcodes, int blcodes)
{
  int i; // edi

  if ( lcodes < 257 || dcodes < 1 || blcodes < 4 )
    state->err = "not enough codes";
  if ( lcodes > 286 || dcodes > 30 || blcodes > 19 )
    state->err = "too many codes";
  send_bits(state, value: lcodes - 257, length: 5);
  send_bits(state, value: dcodes - 1, length: 5);
  send_bits(state, value: blcodes - 4, length: 4);
  for ( i = 0; i < blcodes; ++i )
    send_bits(state, value: state->ts.bl_tree[bl_order[i]].dl.dad, length: 3);
  send_tree(state, tree: state->ts.dyn_ltree, max_code: lcodes - 1);
  send_tree(state, tree: state->ts.dyn_dtree, max_code: dcodes - 1);
}

//------------------------------------------------------------------------------
// Address: 0x101FD6E0
// Name: void compress_block(class TState __near &,struct ct_data __near *,struct ct_data __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl compress_block(TState *state, ct_data *ltree, ct_data *dtree)
{
  unsigned int v3; // ebx
  int v5; // edi
  int v6; // ebx
  unsigned int v7; // ebx
  unsigned __int8 v8; // al
  int v9; // edi
  unsigned int lx; // [esp+8h] [ebp-Ch]
  unsigned int fx; // [esp+Ch] [ebp-8h]
  unsigned __int8 flag; // [esp+13h] [ebp-1h]
  unsigned __int16 *statea; // [esp+1Ch] [ebp+8h]

  v3 = 0;
  fx = 0;
  flag = 0;
  if ( state->ts.last_lit != 0 )
  {
    statea = state->ts.d_buf;
    do
    {
      if ( (v3 & 7) == 0 )
        flag = state->ts.flag_buf[fx++];
      v5 = state->ts.l_buf[v3++];
      lx = v3;
      if ( (flag & 1) != 0 )
      {
        v6 = state->ts.length_code[v5];
        send_bits(state, value: ltree[v6 + 257].fc.freq, length: ltree[v6 + 257].dl.dad);
        if ( extra_lbits[v6] != 0 )
          send_bits(state, value: v5 - state->ts.base_length[v6], length: extra_lbits[v6]);
        v7 = *statea++;
        if ( v7 >= 0x100 )
          v8 = state->ts.dist_code[(v7 >> 7) + 256];
        else
          v8 = state->ts.dist_code[v7];
        v9 = v8;
        if ( v8 >= 0x1Eu )
          state->err = "bad d_code";
        send_bits(state, value: dtree[v8].fc.freq, length: dtree[v8].dl.dad);
        if ( extra_dbits[v9] != 0 )
          send_bits(state, value: v7 - state->ts.base_dist[v9], length: extra_dbits[v9]);
        v3 = lx;
      }
      else
      {
        send_bits(state, value: ltree[v5].fc.freq, length: ltree[v5].dl.dad);
      }
      flag >>= 1;
    }
    while ( v3 < state->ts.last_lit );
  }
  send_bits(state, value: ltree[256].fc.freq, length: ltree[256].dl.dad);
}

//------------------------------------------------------------------------------
// Address: 0x101FD840
// Name: void lm_init(class TState __near &,int,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lm_init(TState *state, int pack_level, unsigned __int16 *flags)
{
  unsigned int (__cdecl *readfunc)(TState *, char *, unsigned int); // eax
  unsigned int v4; // eax
  unsigned int v5; // eax

  if ( (unsigned int)(pack_level - 1) > 7 )
    state->err = "bad pack level";
  state->ds.sliding = 0;
  if ( state->ds.window_size == 0 )
  {
    state->ds.sliding = 1;
    state->ds.window_size = 0x10000;
  }
  state->ds.head[0x7FFF] = 0;
  memset(dst: (unsigned __int8 *)state->ds.head, value: 0, count: 0x1FFFCu);
  state->ds.max_lazy_match = configuration_table[pack_level].max_lazy;
  state->ds.good_match = configuration_table[pack_level].good_length;
  state->ds.nice_match = configuration_table[pack_level].nice_length;
  state->ds.max_chain_length = configuration_table[pack_level].max_chain;
  if ( pack_level > 2 )
  {
    if ( pack_level >= 8 )
      *flags |= 2u;
  }
  else
  {
    *flags |= 4u;
  }
  readfunc = state->readfunc;
  state->ds.strstart = 0;
  state->ds.block_start = 0;
  v4 = readfunc(a1: state, a2: (char *)&state->ds, a3: 0x10000u);
  state->ds.lookahead = v4;
  if ( v4 == 0 || v4 == -1 )
  {
    state->ds.lookahead = 0;
    state->ds.eofile = 1;
  }
  else
  {
    state->ds.eofile = 0;
    if ( v4 < 0x106 )
      fill_window(state);
    state->ds.ins_h = 0;
    v5 = state->ds.window[0];
    state->ds.ins_h = v5;
    state->ds.ins_h = ((unsigned __int16)(32 * v5) ^ state->ds.window[1]) & 0x7FFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD990
// Name: public: static unsigned int TZip::sflush(void __near *,char const __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TZip::sflush(TZip *param, char *buf, unsigned int *size)
{
  unsigned int result; // eax

  result = *size;
  if ( *size != 0 )
  {
    result = TZip::write(this: param, buf, size: *size);
    if ( result != 0 )
      *size = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FD9C0
// Name: public: static unsigned int TZip::swrite(void __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TZip::swrite(TZip *param, char *buf, unsigned int size)
{
  unsigned int result; // eax

  result = size;
  if ( size != 0 )
    return TZip::write(this: param, buf, size);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FD9E0
// Name: public: unsigned long TZip::open_file(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::open_file(TZip *this, const char *fn)
{
  HANDLE FileA; // eax
  void *v5; // edi
  unsigned int res; // [esp+10h] [ebp+8h]

  this->hfin = nullptr;
  this->bufin = nullptr;
  this->selfclosehf = false;
  this->crc = 0;
  this->isize = 0;
  this->csize = 0;
  this->ired = 0;
  if ( fn == nullptr )
    return 0x10000;
  FileA = CreateFileA(
            lpFileName: fn,
            dwDesiredAccess: 0x80000000,
            dwShareMode: 1u,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 3u,
            dwFlagsAndAttributes: 0,
            hTemplateFile: nullptr);
  v5 = FileA;
  if ( FileA == (HANDLE)-1 )
    return 512;
  res = TZip::open_handle(this, hf: FileA, len: 0);
  if ( res != 0 )
  {
    CloseHandle(hObject: v5);
    return res;
  }
  else
  {
    this->selfclosehf = true;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FDA70
// Name: public: static unsigned int TZip::sread(class TState __near &,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TZip::sread(TState *s, char *buf, DWORD size)
{
  return TZip::read(this: (TZip *)s->param, buf, size);
}

//------------------------------------------------------------------------------
// Address: 0x101FDA90
// Name: public: unsigned long TZip::AddCentral(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::AddCentral(TZip *this)
{
  zlist *zfis; // esi
  unsigned int writ; // ecx
  zlist *nxt; // ebx
  unsigned int pos_at_start_of_central; // [esp+8h] [ebp-Ch]
  int numentries; // [esp+Ch] [ebp-8h]
  bool okay; // [esp+13h] [ebp-1h]

  zfis = this->zfis;
  writ = this->writ;
  numentries = 0;
  pos_at_start_of_central = writ;
  okay = true;
  if ( zfis != nullptr )
  {
    do
    {
      if ( okay
        && putcentral(
             z: zfis,
             wfunc: (unsigned int (__cdecl *)(void *, const char *, unsigned int))TZip::swrite,
             param: this) != 0 )
      {
        okay = false;
      }
      ++numentries;
      this->writ += zfis->cext + zfis->com + zfis->nam + 46;
      nxt = zfis->nxt;
      if ( zfis->cextra != nullptr )
        free(pMem: zfis->cextra);
      free(pMem: zfis);
      zfis = nxt;
    }
    while ( nxt != nullptr );
    writ = pos_at_start_of_central;
  }
  if ( !okay )
    return 1024;
  if ( putend(
         n: numentries,
         s: this->writ - writ,
         c: writ + this->ooffset,
         m: 0,
         z: nullptr,
         wfunc: (unsigned int (__cdecl *)(void *, const char *, unsigned int))TZip::swrite,
         param: this) != 0 )
    okay = false;
  this->writ += 22;
  if ( okay )
    return 0;
  else
    return 1024;
}

//------------------------------------------------------------------------------
// Address: 0x101FDB60
// Name: void ct_init(class TState __near &,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ct_init(TState *state, unsigned __int16 *attr)
{
  int v3; // edi
  int v4; // eax
  const int *v5; // edx
  int v6; // eax
  int v7; // edx
  const int *v8; // edi
  int v9; // eax
  const int *v10; // ecx
  int v11; // edi
  ct_data::<unnamed_type_dl> *p_dl; // eax
  int i; // ecx
  ct_data::<unnamed_type_dl> *v14; // eax
  int j; // ecx
  int v16; // ecx
  ct_data::<unnamed_type_dl> *v17; // eax
  ct_data::<unnamed_type_dl> *v18; // eax
  int k; // ecx
  ct_data *static_dtree; // ecx
  int v21; // edi
  int v22; // edx
  unsigned int v23; // ecx
  unsigned int v24; // eax
  int v25; // ebx
  unsigned __int8 n; // [esp+10h] [ebp+8h]
  int na; // [esp+10h] [ebp+8h]
  int *nb; // [esp+10h] [ebp+8h]
  ct_data *nc; // [esp+10h] [ebp+8h]
  int *attra; // [esp+14h] [ebp+Ch]
  int *attrb; // [esp+14h] [ebp+Ch]
  unsigned __int16 *attrc; // [esp+14h] [ebp+Ch]

  v3 = 0;
  state->ts.file_type = attr;
  state->ts.cmpr_len_bits = 0;
  state->ts.cmpr_bytelen = 0;
  state->ts.input_len = 0;
  if ( state->ts.static_dtree[0].dl.dad == 0 )
  {
    v4 = 0;
    n = 0;
    v5 = extra_lbits;
    attra = state->ts.base_length;
    while ( 1 )
    {
      *attra = v4;
      if ( 1 << *v5 > 0 )
      {
        do
        {
          state->ts.length_code[v4] = n;
          ++v3;
          ++v4;
        }
        while ( v3 < 1 << *v5 );
      }
      ++attra;
      ++n;
      if ( (int)++v5 >= (int)&extra_lbits[28] )
        break;
      v3 = 0;
    }
    if ( v4 != 256 )
      state->err = "ct_init: length != 256";
    state->ts.depth[v4 + 572] = n;
    v6 = 0;
    v7 = 0;
    v8 = extra_dbits;
    attrb = state->ts.base_dist;
    do
    {
      *attrb = v6;
      for ( na = 0; na < 1 << *v8; ++v6 )
      {
        ++na;
        state->ts.dist_code[v6] = v7;
      }
      ++attrb;
      ++v8;
      ++v7;
    }
    while ( (int)v8 < (int)&extra_dbits[16] );
    if ( v6 != 256 )
      state->err = "ct_init: dist != 256";
    v9 = v6 >> 7;
    if ( v7 < 30 )
    {
      v10 = &extra_dbits[v7];
      attrc = (unsigned __int16 *)v10;
      nb = &state->ts.base_dist[v7];
      do
      {
        *nb = v9 << 7;
        v11 = 0;
        if ( 1 << (*(_BYTE *)v10 - 7) > 0 )
        {
          do
          {
            state->ts.dist_code[v9 + 256] = v7;
            ++v11;
            ++v9;
          }
          while ( v11 < 1 << (*(_BYTE *)attrc - 7) );
        }
        ++nb;
        v10 = (const int *)(attrc + 2);
        LOBYTE(v7) = v7 + 1;
        attrc = (unsigned __int16 *)v10;
      }
      while ( (int)v10 < (int)extra_blbits );
    }
    if ( v9 != 256 )
      state->err = "ct_init: 256+dist != 512";
    *(_DWORD *)state->ts.bl_count = 0;
    *(_DWORD *)&state->ts.bl_count[2] = 0;
    *(_DWORD *)&state->ts.bl_count[4] = 0;
    *(_DWORD *)&state->ts.bl_count[6] = 0;
    *(_DWORD *)&state->ts.bl_count[8] = 0;
    *(_DWORD *)&state->ts.bl_count[10] = 0;
    *(_DWORD *)&state->ts.bl_count[12] = 0;
    *(_DWORD *)&state->ts.bl_count[14] = 0;
    p_dl = &state->ts.static_ltree[1].dl;
    for ( i = 24; i != 0; --i )
    {
      p_dl[-2].dad = 8;
      ++state->ts.bl_count[8];
      p_dl->dad = 8;
      ++state->ts.bl_count[8];
      p_dl[2].dad = 8;
      ++state->ts.bl_count[8];
      p_dl[4].dad = 8;
      ++state->ts.bl_count[8];
      p_dl[6].dad = 8;
      ++state->ts.bl_count[8];
      p_dl[8].dad = 8;
      ++state->ts.bl_count[8];
      p_dl += 12;
    }
    v14 = &state->ts.static_ltree[144].dl;
    for ( j = 112; j != 0; --j )
    {
      v14->dad = 9;
      ++state->ts.bl_count[9];
      v14 += 2;
    }
    v16 = 24;
    v17 = &state->ts.static_ltree[256].dl;
    do
    {
      v17->dad = 7;
      ++state->ts.bl_count[7];
      v17 += 2;
      --v16;
    }
    while ( v16 != 0 );
    v18 = &state->ts.static_ltree[280].dl;
    for ( k = 8; k != 0; --k )
    {
      v18->dad = 8;
      ++state->ts.bl_count[8];
      v18 += 2;
    }
    gen_codes(state, tree: state->ts.static_ltree, max_code: 287);
    static_dtree = state->ts.static_dtree;
    v21 = 0;
    nc = state->ts.static_dtree;
    do
    {
      v22 = 5;
      static_dtree->dl.dad = 5;
      v23 = v21;
      v24 = 0;
      do
      {
        v25 = v23 & 1;
        --v22;
        v23 >>= 1;
        v24 = 2 * (v25 | v24);
      }
      while ( v22 > 0 );
      nc->fc.freq = v24 >> 1;
      ++v21;
      static_dtree = ++nc;
    }
    while ( v21 < 30 );
    init_block(state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FDEA0
// Name: unsigned long flush_block(class TState __near &,char __near *,unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl flush_block(TState *state, char *buf, unsigned int stored_len, unsigned int eof)
{
  int v5; // eax
  unsigned int static_len; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  unsigned int opt_len; // ecx
  unsigned int v11; // eax
  int max_blindex; // [esp+Ch] [ebp+8h]

  state->ts.flag_buf[state->ts.last_flags] = state->ts.flags;
  if ( *state->ts.file_type == 0xFFFF )
    set_file_type(state);
  build_tree(state, desc: &state->ts.l_desc);
  build_tree(state, desc: &state->ts.d_desc);
  v5 = build_bl_tree(state);
  static_len = state->ts.static_len;
  state->ts.input_len += stored_len;
  max_blindex = v5;
  v7 = (state->ts.opt_len + 10) >> 3;
  v8 = (static_len + 10) >> 3;
  if ( v8 <= v7 )
    v7 = v8;
  if ( stored_len + 4 <= v7 && buf != nullptr )
  {
    v9 = eof;
    send_bits(state, value: eof, length: 3);
    state->ts.cmpr_bytelen += ((state->ts.cmpr_len_bits + 10) >> 3) + stored_len + 4;
    state->ts.cmpr_len_bits = 0;
    copy_block(state, block: buf, len: stored_len, header: 1);
  }
  else
  {
    v9 = eof;
    if ( v8 == v7 )
    {
      send_bits(state, value: eof + 2, length: 3);
      compress_block(state, ltree: state->ts.static_ltree, dtree: state->ts.static_dtree);
      opt_len = state->ts.static_len;
    }
    else
    {
      send_bits(state, value: eof + 4, length: 3);
      send_all_trees(
        state,
        lcodes: state->ts.l_desc.max_code + 1,
        dcodes: state->ts.d_desc.max_code + 1,
        blcodes: max_blindex + 1);
      compress_block(state, ltree: state->ts.dyn_ltree, dtree: state->ts.dyn_dtree);
      opt_len = state->ts.opt_len;
    }
    v11 = state->ts.cmpr_len_bits + opt_len + 3;
    state->ts.cmpr_bytelen += v11 >> 3;
    state->ts.cmpr_len_bits = v11 & 7;
  }
  if ( state->ts.cmpr_len_bits + 8 * state->ts.cmpr_bytelen != state->bs.bits_sent )
    state->err = "bad compressed size";
  init_block(state);
  if ( v9 != 0 )
  {
    bi_windup(state);
    state->ts.cmpr_len_bits += 7;
  }
  return state->ts.cmpr_bytelen + (state->ts.cmpr_len_bits >> 3);
}

//------------------------------------------------------------------------------
// Address: 0x101FE050
// Name: unsigned long deflate_fast(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl deflate_fast(TState *state)
{
  unsigned int v2; // ebx
  unsigned int v3; // edi
  unsigned int strstart; // ecx
  unsigned int v5; // eax
  unsigned int lookahead; // eax
  unsigned int v7; // ecx
  BOOL v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // ecx
  BOOL v13; // eax
  int block_start; // eax
  char *v15; // ecx
  int v16; // eax
  char *v17; // ecx
  int flush; // [esp+14h] [ebp+8h]

  v2 = 0;
  v3 = 0;
  state->ds.prev_length = 2;
  while ( state->ds.lookahead != 0 )
  {
    if ( state->ds.lookahead >= 3 )
    {
      strstart = state->ds.strstart;
      v5 = ((unsigned __int16)(32 * LOWORD(state->ds.ins_h)) ^ state->ds.window[strstart + 2]) & 0x7FFF;
      state->ds.ins_h = v5;
      v2 = state->ds.head[v5];
      state->ds.prev[strstart & 0x7FFF] = v2;
      state->ds.head[state->ds.ins_h] = state->ds.strstart;
    }
    if ( v2 != 0 && state->ds.strstart - v2 <= 0x7EFA )
    {
      lookahead = state->ds.lookahead;
      if ( state->ds.nice_match > lookahead )
        state->ds.nice_match = lookahead;
      v3 = longest_match(state, cur_match: v2);
      if ( v3 > state->ds.lookahead )
        v3 = state->ds.lookahead;
    }
    v7 = state->ds.strstart;
    if ( v3 < 3 )
    {
      v13 = ct_tally(state, dist: 0, lc: state->ds.window[v7]);
      --state->ds.lookahead;
      ++state->ds.strstart;
      flush = v13;
    }
    else
    {
      v8 = ct_tally(state, dist: v7 - state->ds.match_start, lc: v3 - 3);
      state->ds.lookahead -= v3;
      flush = v8;
      if ( v3 > state->ds.max_lazy_match || state->ds.lookahead < 3 )
      {
        state->ds.strstart += v3;
        v11 = state->ds.strstart;
        v12 = state->ds.window[v11];
        state->ds.ins_h = v12;
        v3 = 0;
        state->ds.ins_h = (32 * v12) ^ state->ds.window[v11 + 1];
      }
      else
      {
        --v3;
        do
        {
          v9 = ++state->ds.strstart;
          v10 = ((unsigned __int16)(32 * state->ds.ins_h) ^ state->ds.window[v9 + 2]) & 0x7FFF;
          state->ds.ins_h = v10;
          v2 = state->ds.head[v10];
          --v3;
          state->ds.prev[v9 & 0x7FFF] = v2;
          state->ds.head[state->ds.ins_h] = state->ds.strstart;
        }
        while ( v3 != 0 );
        ++state->ds.strstart;
      }
    }
    if ( flush != 0 )
    {
      block_start = state->ds.block_start;
      if ( block_start < 0 )
        v15 = nullptr;
      else
        v15 = (char *)&state->ds.window[block_start];
      flush_block(state, buf: v15, stored_len: state->ds.strstart - block_start, eof: 0);
      state->ds.block_start = state->ds.strstart;
    }
    if ( state->ds.lookahead < 0x106 )
      fill_window(state);
  }
  v16 = state->ds.block_start;
  if ( v16 < 0 )
    v17 = nullptr;
  else
    v17 = (char *)&state->ds.window[v16];
  return flush_block(state, buf: v17, stored_len: state->ds.strstart - v16, eof: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x101FE2A0
// Name: unsigned long deflate(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl deflate(TState *state)
{
  unsigned int v1; // edi
  unsigned int strstart; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int match_start; // ebx
  unsigned int lookahead; // eax
  unsigned int prev_length; // ecx
  unsigned int v9; // eax
  unsigned int v10; // edi
  BOOL v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  int v17; // eax
  char *v18; // edx
  int block_start; // eax
  char *v20; // ecx
  int v21; // eax
  char *v22; // ecx
  unsigned int hash_head; // [esp+8h] [ebp-8h]
  int match_available; // [esp+Ch] [ebp-4h]

  hash_head = 0;
  match_available = 0;
  v1 = 2;
  if ( state->level <= 3 )
    return deflate_fast(state);
  if ( state->ds.lookahead != 0 )
  {
    do
    {
      if ( state->ds.lookahead >= 3 )
      {
        strstart = state->ds.strstart;
        v4 = ((unsigned __int16)(32 * LOWORD(state->ds.ins_h)) ^ state->ds.window[strstart + 2]) & 0x7FFF;
        state->ds.ins_h = v4;
        v5 = state->ds.head[v4];
        state->ds.prev[strstart & 0x7FFF] = v5;
        hash_head = v5;
        state->ds.head[state->ds.ins_h] = state->ds.strstart;
      }
      match_start = state->ds.match_start;
      state->ds.prev_length = v1;
      v1 = 2;
      if ( hash_head != 0
        && state->ds.prev_length < state->ds.max_lazy_match
        && state->ds.strstart - hash_head <= 0x7EFA )
      {
        lookahead = state->ds.lookahead;
        if ( state->ds.nice_match > lookahead )
          state->ds.nice_match = lookahead;
        v1 = longest_match(state, cur_match: hash_head);
        if ( v1 > state->ds.lookahead )
          v1 = state->ds.lookahead;
        if ( v1 == 3 && state->ds.strstart - state->ds.match_start > 0x1000 )
          v1 = 2;
      }
      prev_length = state->ds.prev_length;
      if ( prev_length < 3 || v1 > prev_length )
      {
        if ( match_available != 0 )
        {
          if ( ct_tally(state, dist: 0, lc: *((unsigned __int8 *)&state->bs.bits_sent + state->ds.strstart + 3)) )
          {
            block_start = state->ds.block_start;
            if ( block_start < 0 )
              v20 = nullptr;
            else
              v20 = (char *)&state->ds.window[block_start];
            flush_block(state, buf: v20, stored_len: state->ds.strstart - block_start, eof: 0);
            state->ds.block_start = state->ds.strstart;
          }
          ++state->ds.strstart;
        }
        else
        {
          ++state->ds.strstart;
          match_available = 1;
        }
        --state->ds.lookahead;
      }
      else
      {
        v9 = state->ds.strstart;
        v10 = v9 + state->ds.lookahead - 3;
        v11 = ct_tally(state, dist: v9 - match_start - 1, lc: prev_length - 3);
        v12 = state->ds.prev_length;
        state->ds.lookahead += 1 - v12;
        state->ds.prev_length = v12 - 2;
        do
        {
          v13 = ++state->ds.strstart;
          if ( v13 <= v10 )
          {
            v14 = ((unsigned __int16)(32 * LOWORD(state->ds.ins_h)) ^ state->ds.window[v13 + 2]) & 0x7FFF;
            state->ds.ins_h = v14;
            v15 = state->ds.head[v14];
            state->ds.prev[v13 & 0x7FFF] = v15;
            hash_head = v15;
            state->ds.head[state->ds.ins_h] = state->ds.strstart;
          }
        }
        while ( state->ds.prev_length-- != 1 );
        ++state->ds.strstart;
        match_available = 0;
        v1 = 2;
        if ( v11 )
        {
          v17 = state->ds.block_start;
          if ( v17 < 0 )
            v18 = nullptr;
          else
            v18 = (char *)&state->ds.window[v17];
          flush_block(state, buf: v18, stored_len: state->ds.strstart - v17, eof: 0);
          state->ds.block_start = state->ds.strstart;
        }
      }
      if ( state->ds.lookahead < 0x106 )
        fill_window(state);
    }
    while ( state->ds.lookahead != 0 );
    if ( match_available != 0 )
      ct_tally(state, dist: 0, lc: *((unsigned __int8 *)&state->bs.bits_sent + state->ds.strstart + 3));
  }
  v21 = state->ds.block_start;
  if ( v21 < 0 )
    v22 = nullptr;
  else
    v22 = (char *)&state->ds.window[v21];
  return flush_block(state, buf: v22, stored_len: state->ds.strstart - v21, eof: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x101FE5B0
// Name: public: unsigned long TZip::Close(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::Close(TZip *this)
{
  unsigned int v2; // ebx
  char *obuf; // eax
  void *hmapout; // eax
  void *hfout; // eax

  v2 = 0;
  if ( !this->hasputcen )
    v2 = TZip::AddCentral(this);
  obuf = this->obuf;
  this->hasputcen = true;
  if ( obuf != nullptr && this->hmapout != nullptr )
    UnmapViewOfFile(lpBaseAddress: obuf);
  hmapout = this->hmapout;
  this->obuf = nullptr;
  if ( hmapout != nullptr )
    CloseHandle(hObject: hmapout);
  hfout = this->hfout;
  this->hmapout = nullptr;
  if ( hfout != nullptr )
    CloseHandle(hObject: hfout);
  this->hfout = nullptr;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101FE610
// Name: public: unsigned long TZip::ideflate(struct zlist __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TZip::ideflate(TZip *this, zlist *zfi)
{
  bool iseekable; // cl
  TState state; // [esp+8h] [ebp-6AFA8h] BYREF

  TTreeState::TTreeState(this: &state.ts);
  iseekable = this->iseekable;
  state.ts.static_dtree[0].dl.dad = 0;
  state.ds.window_size = 0;
  state.err = nullptr;
  state.bs.out_offset = 0;
  state.bs.bi_buf = 0;
  state.bs.bi_valid = 0;
  state.bs.bits_sent = 0;
  state.seekable = iseekable;
  state.readfunc = TZip::sread;
  state.flush_outbuf = (unsigned int (__cdecl *)(void *, const char *, unsigned int *))TZip::sflush;
  state.param = this;
  state.level = 8;
  state.bs.out_buf = this->buf;
  state.bs.out_size = 0x4000;
  state.bs.flush_flg = 1;
  ct_init(&state, attr: &zfi->att);
  lm_init(&state, pack_level: state.level, flags: &zfi->flg);
  this->csize = deflate(&state);
  return state.err != nullptr ? 0x5000000 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FE6F0
// Name: public: unsigned long TZip::Add(char const __near *,void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::Add(TZip *this, const char *odstzn, char *src, unsigned int len, unsigned int flags)
{
  unsigned int result; // eax
  char *v7; // eax
  bool v9; // dl
  int v10; // eax
  char v11; // cl
  char *v12; // edi
  char v13; // al
  unsigned int timestamp; // ecx
  unsigned int isize; // ecx
  unsigned int attr; // eax
  unsigned int mtime; // edi
  unsigned int v18; // ecx
  unsigned int mtime_high; // eax
  unsigned int v20; // ecx
  int atime; // edi
  int v22; // ecx
  char v23; // edx^3
  int ctime; // edi
  int v25; // esi
  int v26; // edi
  unsigned int csize; // ecx
  bool v28; // zf
  unsigned int crc; // edx
  unsigned int v30; // ecx
  bool v31; // al
  unsigned __int16 lflg; // dx
  unsigned __int8 *v33; // esi
  zlist *v34; // eax
  zlist *zfis; // ecx
  unsigned int v36; // [esp-Ch] [ebp-498h]
  char dstzn[260]; // [esp+4h] [ebp-488h] BYREF
  zlist zfi; // [esp+108h] [ebp-384h] BYREF
  char xcen[9]; // [esp+468h] [ebp-24h] BYREF
  char xloc[20]; // [esp+474h] [ebp-18h] BYREF
  int method; // [esp+488h] [ebp-4h]
  char needs_trailing_slash_3; // [esp+497h] [ebp+Bh]
  bool isdir_3; // [esp+4A3h] [ebp+17h]

  if ( this->oerr != 0 )
    return 0x40000;
  if ( this->hasputcen )
    return 327680;
  strcpy(dstzn, odstzn);
  if ( dstzn[0] == 0 )
    return 0x10000;
  v7 = dstzn;
  do
  {
    if ( *v7 == 92 )
      *v7 = 47;
    ++v7;
  }
  while ( *v7 != 0 );
  v9 = flags == 4;
  isdir_3 = v9;
  if ( !v9 || (needs_trailing_slash_3 = 1, dstzn[strlen(dstzn) - 1] == 47) )
    needs_trailing_slash_3 = 0;
  method = 8;
  if ( v9 || HasZipSuffix(fn: dstzn) )
    method = 0;
  switch ( flags )
  {
    case 2u:
      result = TZip::open_file(this, fn: src);
      break;
    case 1u:
      result = TZip::open_handle(this, hf: src, len);
      break;
    case 3u:
      result = TZip::open_mem(this, src, len);
      break;
    case 4u:
      result = TZip::open_dir(this);
      break;
    default:
      return 0x10000;
  }
  if ( result != 0 )
    return result;
  zfi.nxt = nullptr;
  zfi.name[0] = 0;
  v10 = 0;
  do
  {
    v11 = dstzn[v10];
    zfi.iname[v10++] = v11;
  }
  while ( v11 != 0 );
  zfi.nam = strlen(zfi.iname);
  if ( needs_trailing_slash_3 != 0 )
  {
    v12 = (char *)&zfi.comment + 3;
    do
      v13 = *++v12;
    while ( v13 != 0 );
    strcpy(v12, "/");
    ++zfi.nam;
  }
  zfi.lflg = 8;
  zfi.att = 0;
  timestamp = this->timestamp;
  zfi.zname[0] = 0;
  zfi.comment = nullptr;
  zfi.com = 0;
  zfi.mark = 1;
  zfi.dosflag = 0;
  *(_DWORD *)&zfi.vem = 1313559;
  zfi.tim = timestamp;
  zfi.crc = 0;
  zfi.flg = 8;
  zfi.how = method;
  if ( method != 0 || (zfi.siz = this->isize, (zfi.siz & 0x80000000) != 0) )
    zfi.siz = 0;
  isize = this->isize;
  attr = this->attr;
  mtime = this->times.mtime;
  zfi.dsk = 0;
  zfi.len = isize;
  v18 = this->writ + this->ooffset;
  zfi.atx = attr;
  zfi.off = v18;
  xloc[5] = this->times.mtime;
  zfi.cextra = xcen;
  mtime_high = HIDWORD(this->times.mtime);
  zfi.extra = xloc;
  xloc[6] = BYTE1(mtime);
  xloc[7] = BYTE2(mtime);
  v20 = mtime;
  atime = this->times.atime;
  v22 = __PAIR64__(mtime_high, v20) >> 24;
  xloc[9] = this->times.atime;
  xloc[10] = BYTE1(atime);
  xloc[11] = BYTE2(atime);
  v23 = HIBYTE(atime);
  ctime = this->times.ctime;
  LOBYTE(mtime_high) = this->times.ctime;
  xloc[12] = v23;
  *(_WORD *)&xloc[13] = __PAIR16__(BYTE1(ctime), mtime_high);
  xloc[15] = BYTE2(ctime);
  strcpy(xloc, "UT\r");
  *(_DWORD *)xcen = 349269;
  xloc[4] = 7;
  xloc[16] = HIBYTE(ctime);
  zfi.ext = 17;
  zfi.cext = 9;
  xloc[8] = v22;
  *(_DWORD *)&xcen[4] = *(_DWORD *)&xloc[4];
  xcen[8] = v22;
  if ( putlocal(z: &zfi, wfunc: (unsigned int (__cdecl *)(void *, const char *, unsigned int))TZip::swrite, param: this) != 0 )
  {
    TZip::iclose(this);
    return 1024;
  }
  this->writ += zfi.ext + zfi.nam + 30;
  v25 = 0;
  if ( this->oerr != 0 )
  {
    TZip::iclose(this);
    return this->oerr;
  }
  v26 = method;
  if ( isdir_3 )
  {
    this->csize = 0;
  }
  else if ( method == 8 )
  {
    v25 = TZip::ideflate(this, &zfi);
  }
  else if ( method == 0 )
  {
    v25 = TZip::istore(this);
  }
  TZip::iclose(this);
  csize = this->csize;
  result = this->oerr;
  this->writ += csize;
  if ( result == 0 )
  {
    if ( v25 != 0 )
      return 1024;
    v28 = zfi.siz == csize;
    crc = this->crc;
    zfi.siz = csize;
    v30 = this->isize;
    v31 = v28;
    v28 = !this->ocanseek;
    zfi.crc = crc;
    zfi.len = v30;
    if ( v28 )
    {
      if ( zfi.how != (_WORD)v26 || v26 == 0 && !v31 )
        return 0x4000000;
      if ( putextended(
             z: &zfi,
             wfunc: (unsigned int (__cdecl *)(void *, const char *, unsigned int))TZip::swrite,
             param: this) != 0 )
        return 1024;
      lflg = zfi.lflg;
      this->writ += 16;
      zfi.flg = lflg;
    }
    else
    {
      zfi.how = v26;
      if ( (zfi.flg & 1) == 0 )
        zfi.flg &= ~8u;
      v36 = zfi.off - this->ooffset;
      zfi.lflg = zfi.flg;
      if ( TZip::oseek(this, pos: v36) == 0 )
        return 0x2000000;
      if ( putlocal(
             z: &zfi,
             wfunc: (unsigned int (__cdecl *)(void *, const char *, unsigned int))TZip::swrite,
             param: this) != 0 )
        return 1024;
      if ( TZip::oseek(this, pos: this->writ) == 0 )
        return 0x2000000;
    }
    result = this->oerr;
    if ( result == 0 )
    {
      v33 = (unsigned __int8 *)MemAlloc_Alloc(nSize: zfi.cext);
      memcpy(dst: v33, src: (unsigned __int8 *)zfi.cextra, count: zfi.cext);
      zfi.cextra = (char *)v33;
      v34 = (zlist *)MemAlloc_Alloc(nSize: 0x360u);
      *v34 = zfi;
      zfis = this->zfis;
      if ( zfis != nullptr )
      {
        for ( ; zfis->nxt != nullptr; zfis = zfis->nxt )
          ;
        zfis->nxt = v34;
        return 0;
      }
      else
      {
        this->zfis = v34;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FEC40
// Name: struct HZIP__ __near * CreateZipZ(void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HZIP__ *__cdecl CreateZipZ(void *z, unsigned int len, unsigned int flags)
{
  TZip *v3; // eax
  TZip *v4; // esi
  void *v5; // eax
  HZIP__ *result; // eax

  _tzset();
  v3 = (TZip *)MemAlloc_Alloc(nSize: 0x4078u);
  if ( v3 != nullptr )
  {
    v3->hfout = nullptr;
    v3->hmapout = nullptr;
    v3->ooffset = 0;
    v3->oerr = 0;
    v3->writ = 0;
    v3->obuf = nullptr;
    v3->hasputcen = false;
    v3->zfis = nullptr;
    v3->hfin = nullptr;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (void *)TZip::Create(this: v4, z, len, flags);
  GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: v5);
  if ( GenericThreadLocals::CThreadLocalBase::Get(this: &lasterrorZ) != nullptr )
  {
    if ( v4 != nullptr )
      free(pMem: v4);
    return nullptr;
  }
  else
  {
    result = (HZIP__ *)MemAlloc_Alloc(nSize: 8u);
    *((_DWORD *)result + 1) = v4;
    *(_DWORD *)result = 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FECE0
// Name: unsigned long ZipAdd(struct HZIP__ __near *,char const __near *,void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ZipAdd(HZIP__ *hz, const char *dstzn, char *src, unsigned int len, unsigned int flags)
{
  TZip *v6; // esi
  void *v7; // eax
  char szDest[520]; // [esp+0h] [ebp-208h] BYREF

  if ( hz != nullptr )
  {
    if ( *(_DWORD *)hz == 2 )
    {
      v6 = *((TZip **)hz + 1);
      if ( flags == 2 )
      {
        memset(dst: (unsigned __int8 *)szDest, value: 0, count: sizeof(szDest));
        strcpy(szDest, dstzn);
        v7 = (void *)TZip::Add(this: v6, odstzn: szDest, src, len, flags: 2u);
      }
      else
      {
        v7 = (void *)TZip::Add(this: v6, odstzn: dstzn, src, len, flags);
      }
      GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: v7);
      return (unsigned int)GenericThreadLocals::CThreadLocalBase::Get(this: &lasterrorZ);
    }
    else
    {
      GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x80000);
      return 0x80000;
    }
  }
  else
  {
    GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x10000);
    return 0x10000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FEDA0
// Name: unsigned long ZipGetMemory(struct HZIP__ __near *,void __near * __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ZipGetMemory(HZIP__ *hz, void **buf, unsigned int *len)
{
  int v4; // esi

  if ( hz != nullptr )
  {
    if ( *(_DWORD *)hz == 2 )
    {
      v4 = *((_DWORD *)hz + 1);
      if ( *(_BYTE *)(v4 + 36) == 0 )
        TZip::AddCentral(this: *((TZip **)hz + 1));
      *(_BYTE *)(v4 + 36) = 1;
      if ( buf != nullptr )
        *buf = *(void **)(v4 + 24);
      if ( len != nullptr )
        *len = *(_DWORD *)(v4 + 16);
      GenericThreadLocals::CThreadLocalBase::Set(
        this: &lasterrorZ,
        a2: *(_DWORD *)(v4 + 24) != 0 ? nullptr : (void *)0x20000);
      return (unsigned int)GenericThreadLocals::CThreadLocalBase::Get(this: &lasterrorZ);
    }
    else
    {
      GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x80000);
      return 0x80000;
    }
  }
  else
  {
    if ( buf != nullptr )
      *buf = nullptr;
    if ( len != nullptr )
      *len = 0;
    GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x10000);
    return 0x10000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FEE50
// Name: unsigned long CloseZipZ(struct HZIP__ __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CloseZipZ(HZIP__ *hz)
{
  TZip *v2; // esi
  void *v3; // eax

  if ( hz != nullptr )
  {
    if ( *(_DWORD *)hz == 2 )
    {
      v2 = *((TZip **)hz + 1);
      v3 = (void *)TZip::Close(this: v2);
      GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: v3);
      if ( v2 != nullptr )
        free(pMem: v2);
      free(pMem: hz);
      return (unsigned int)GenericThreadLocals::CThreadLocalBase::Get(this: &lasterrorZ);
    }
    else
    {
      GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x80000);
      return 0x80000;
    }
  }
  else
  {
    GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x10000);
    return 0x10000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCC63
// Name: __write
// Source: json
//------------------------------------------------------------------------------
int __cdecl _write(int fh, char *buf, unsigned int cnt)
{
  ioinfo **v4; // edi
  int v5; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _write_nolock(fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x102FCD37
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_nolock(int fh)
{
  int osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(fh) == -1
    || (fh == 1 && (__pioinfo[0][2].osfile & 1) != 0 || fh == 2 && (__pioinfo[0][1].osfile & 1) != 0)
    && (osfhandle = _get_osfhandle(fh: 2), _get_osfhandle(fh: 1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(fh), CloseHandle(hObject: v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  __pioinfo[fh >> 5][fh & 0x1F].osfile = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101FB210
// Name: public: TTreeState::TTreeState(void)
// Source: json
//------------------------------------------------------------------------------
TTreeState *__thiscall TTreeState::TTreeState(TTreeState *this)
{
  tree_desc a; // 0:^8.28

  a.static_tree = this->static_ltree;
  a.dyn_tree = (ct_data *)this;
  a.extra_bits = extra_lbits;
  *(_QWORD *)&a.extra_base = 0x11E00000101LL;
  *(_QWORD *)&a.max_length = 15;
  this->l_desc = a;
  a.dyn_tree = this->dyn_dtree;
  a.static_tree = this->static_dtree;
  a.extra_bits = extra_dbits;
  a.extra_base = 0;
  a.elems = 30;
  this->d_desc = a;
  a.dyn_tree = this->bl_tree;
  a.static_tree = nullptr;
  a.extra_bits = extra_blbits;
  a.extra_base = 0;
  a.elems = 19;
  a.max_length = 7;
  this->bl_desc = a;
  this->last_lit = 0;
  this->last_dist = 0;
  this->last_flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FB2F0
// Name: void init_block(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl init_block(TState *state)
{
  TTreeState *p_ts; // ecx
  int i; // edx
  ct_data *dyn_dtree; // ecx
  int j; // edx
  ct_data *bl_tree; // ecx
  int k; // edx

  p_ts = &state->ts;
  for ( i = 286; i != 0; --i )
  {
    p_ts->dyn_ltree[0].fc.freq = 0;
    p_ts = (TTreeState *)((char *)p_ts + 4);
  }
  dyn_dtree = state->ts.dyn_dtree;
  for ( j = 30; j != 0; --j )
  {
    dyn_dtree->fc.freq = 0;
    ++dyn_dtree;
  }
  bl_tree = state->ts.bl_tree;
  for ( k = 19; k != 0; --k )
  {
    bl_tree->fc.freq = 0;
    ++bl_tree;
  }
  state->ts.dyn_ltree[256].fc.freq = 1;
  state->ts.static_len = 0;
  state->ts.opt_len = 0;
  state->ts.last_flags = 0;
  state->ts.last_dist = 0;
  state->ts.last_lit = 0;
  *(_WORD *)&state->ts.flags = 256;
}

//------------------------------------------------------------------------------
// Address: 0x101FB380
// Name: void pqdownheap(class TState __near &,struct ct_data __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl pqdownheap(TState *state, ct_data *tree, int k)
{
  int heap_len; // edx
  int v4; // edi
  int v5; // ecx
  bool v6; // cc
  int v7; // esi
  ct_data::<unnamed_type_fc> v8; // dx
  ct_data::<unnamed_type_fc> v9; // bx
  int v10; // esi
  ct_data::<unnamed_type_fc> v11; // dx
  ct_data::<unnamed_type_fc> v12; // bx
  int v13; // edx
  int v14; // edx
  int v15; // esi

  heap_len = state->ts.heap_len;
  v4 = state->ts.heap[k];
  v5 = 2 * k;
  v6 = 2 * k < heap_len;
  if ( 2 * k > heap_len )
  {
    state->ts.heap[k] = v4;
  }
  else
  {
    while ( 1 )
    {
      if ( v6 )
      {
        v7 = state->ts.heap[v5 + 1];
        v8.freq = (unsigned __int16)tree[v7].fc;
        v9.freq = (unsigned __int16)tree[state->ts.heap[v5]].fc;
        if ( v8.freq < v9.freq || v8.freq == v9.freq && state->ts.depth[v7] <= state->ts.depth[state->ts.heap[v5]] )
          ++v5;
      }
      v10 = state->ts.heap[v5];
      v11.freq = (unsigned __int16)tree[v4].fc;
      v12.freq = (unsigned __int16)tree[v10].fc;
      if ( v11.freq < v12.freq )
        break;
      if ( v11.freq == v12.freq )
      {
        v13 = v4;
        if ( state->ts.depth[v4] <= state->ts.depth[v10] )
          goto LABEL_13;
      }
      state->ts.heap[k] = v10;
      v14 = state->ts.heap_len;
      v15 = v5;
      v5 *= 2;
      k = v15;
      v6 = v5 < v14;
      if ( v5 > v14 )
      {
        state->ts.heap[v15] = v4;
        return;
      }
    }
    v13 = v4;
LABEL_13:
    state->ts.heap[k] = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB460
// Name: void gen_bitlen(class TState __near &,struct tree_desc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl gen_bitlen(TState *state, tree_desc *desc)
{
  int max_length; // esi
  ct_data *dyn_tree; // edi
  int v5; // ebx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // esi
  int freq; // ebx
  unsigned __int16 *v11; // esi
  int v12; // ecx
  _WORD *i; // edx
  int v14; // ebx
  int *v15; // edx
  int v16; // ecx
  int dad; // esi
  ct_data::<unnamed_type_dl> *p_dl; // edx
  unsigned __int16 v19; // di
  const int *extra; // [esp+Ch] [ebp-20h]
  const int *extraa; // [esp+Ch] [ebp-20h]
  int base; // [esp+10h] [ebp-1Ch]
  ct_data *tree; // [esp+14h] [ebp-18h]
  int max_code; // [esp+18h] [ebp-14h]
  int v25; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v26; // [esp+1Ch] [ebp-10h]
  ct_data *stree; // [esp+20h] [ebp-Ch]
  int h; // [esp+24h] [ebp-8h]
  int overflow; // [esp+28h] [ebp-4h]
  int *bits; // [esp+34h] [ebp+8h]
  int bitsa; // [esp+34h] [ebp+8h]
  int n; // [esp+38h] [ebp+Ch]
  int na; // [esp+38h] [ebp+Ch]

  extra = desc->extra_bits;
  max_code = desc->max_code;
  base = desc->extra_base;
  stree = desc->static_tree;
  max_length = desc->max_length;
  dyn_tree = desc->dyn_tree;
  *(_DWORD *)state->ts.bl_count = 0;
  *(_DWORD *)&state->ts.bl_count[2] = 0;
  *(_DWORD *)&state->ts.bl_count[4] = 0;
  *(_DWORD *)&state->ts.bl_count[6] = 0;
  *(_DWORD *)&state->ts.bl_count[8] = 0;
  *(_DWORD *)&state->ts.bl_count[10] = 0;
  *(_DWORD *)&state->ts.bl_count[12] = 0;
  *(_DWORD *)&state->ts.bl_count[14] = 0;
  dyn_tree[state->ts.heap[state->ts.heap_max]].dl.dad = 0;
  v5 = 0;
  v6 = state->ts.heap_max + 1;
  tree = dyn_tree;
  n = max_length;
  overflow = 0;
  if ( v6 < 573 )
  {
    bits = &state->ts.heap[v6];
    v25 = 573 - v6;
    h = 573;
    do
    {
      v7 = *bits;
      v8 = dyn_tree[dyn_tree[*bits].dl.dad].dl.dad + 1;
      if ( v8 > max_length )
      {
        ++v5;
        v8 = max_length;
        overflow = v5;
      }
      dyn_tree[v7].dl.dad = v8;
      if ( v7 <= max_code )
      {
        ++state->ts.bl_count[v8];
        v9 = 0;
        if ( v7 >= base )
          v9 = extra[v7 - base];
        freq = dyn_tree[v7].fc.freq;
        state->ts.opt_len += freq * (v9 + v8);
        if ( stree != nullptr )
          state->ts.static_len += freq * (v9 + stree[v7].dl.dad);
        max_length = n;
        v5 = overflow;
      }
      ++bits;
      --v25;
    }
    while ( v25 != 0 );
    if ( v5 != 0 )
    {
      v11 = &state->ts.bl_count[max_length];
      do
      {
        v12 = n - 1;
        for ( i = (_WORD *)&state->ts.bl_desc.max_code + n + 1; *i == 0; --v12 )
          --i;
        state->ts.bl_count[v12 + 1] += 2;
        --state->ts.bl_count[v12];
        --*v11;
        v5 -= 2;
      }
      while ( v5 > 0 );
      v14 = n;
      bitsa = n;
      if ( n != 0 )
      {
        v26 = v11;
        do
        {
          na = *v11;
          if ( *v11 != 0 )
          {
            v15 = &state->ts.heap[h];
            do
            {
              v16 = *(v15 - 1);
              --h;
              extraa = --v15;
              if ( v16 <= max_code )
              {
                dad = dyn_tree[v16].dl.dad;
                p_dl = &dyn_tree[v16].dl;
                v19 = v14;
                if ( (_WORD)dad != (_WORD)v14 )
                {
                  state->ts.opt_len += tree[v16].fc.freq * (v14 - dad);
                  v14 = bitsa;
                  p_dl->dad = v19;
                }
                --na;
                dyn_tree = tree;
                v15 = (int *)extraa;
              }
            }
            while ( na != 0 );
          }
          --v14;
          v11 = v26 - 1;
          bitsa = v14;
          --v26;
        }
        while ( v14 != 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB670
// Name: void scan_tree(class TState __near &,struct ct_data __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl scan_tree(TState *state, ct_data *tree, int max_code)
{
  int v3; // edx
  int v4; // ecx
  int v5; // esi
  int freq; // ebx
  int v7; // eax
  int nextlen; // [esp+Ch] [ebp-8h]
  int prevlen; // [esp+10h] [ebp-4h]
  ct_data *treea; // [esp+20h] [ebp+Ch]
  int max_codea; // [esp+24h] [ebp+10h]

  v3 = 0;
  prevlen = -1;
  nextlen = tree->dl.dad;
  v4 = 7;
  v5 = 4;
  if ( tree->dl.dad == 0 )
  {
    v4 = 138;
    v5 = 3;
  }
  tree[max_code + 1].dl.dad = -1;
  if ( max_code >= 0 )
  {
    freq = nextlen;
    treea = (ct_data *)((char *)tree + 6);
    max_codea = max_code + 1;
    do
    {
      v7 = freq;
      freq = treea->fc.freq;
      if ( ++v3 >= v4 || v7 != freq )
      {
        if ( v3 >= v5 )
        {
          if ( v7 != 0 )
          {
            if ( v7 != prevlen )
              ++state->ts.bl_tree[v7].fc.freq;
            ++state->ts.bl_tree[16].fc.freq;
          }
          else if ( v3 > 10 )
          {
            ++state->ts.bl_tree[18].fc.freq;
          }
          else
          {
            ++state->ts.bl_tree[17].fc.freq;
          }
        }
        else
        {
          state->ts.bl_tree[v7].fc.freq += v3;
        }
        v3 = 0;
        prevlen = v7;
        if ( freq != 0 )
        {
          if ( v7 == freq )
          {
            v4 = 6;
            v5 = 3;
          }
          else
          {
            v4 = 7;
            v5 = 4;
          }
        }
        else
        {
          v4 = 138;
          v5 = 3;
        }
      }
      ++treea;
      --max_codea;
    }
    while ( max_codea != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB750
// Name: int ct_tally(class TState __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ct_tally(TState *state, int dist, int lc)
{
  int v4; // eax
  unsigned __int8 v5; // bl
  unsigned __int8 v6; // dl
  unsigned __int8 flag_bit; // al
  unsigned int last_lit; // eax
  int v9; // edi
  const int *v10; // edx
  ct_data *v11; // esi
  unsigned int v12; // edi
  unsigned int in_length; // [esp+Ch] [ebp-4h]
  TState *statea; // [esp+18h] [ebp+8h]
  int lca; // [esp+20h] [ebp+10h]

  state->ts.l_buf[state->ts.last_lit++] = lc;
  if ( dist != 0 )
  {
    v4 = dist - 1;
    if ( (unsigned __int16)(dist - 1) >= 0x7EFAu
      || (unsigned __int16)lc > 0xFFu
      || (v4 >= 256 ? (v5 = state->ts.dist_code[(v4 >> 7) + 256]) : (v5 = state->ts.dist_code[v4]), v5 >= 0x1Eu) )
    {
      state->err = "ct_tally: bad match";
    }
    ++state->ts.dyn_ltree[state->ts.length_code[lc] + 257].fc.freq;
    if ( v4 >= 256 )
      v6 = state->ts.dist_code[(v4 >> 7) + 256];
    else
      v6 = state->ts.dist_code[v4];
    ++state->ts.dyn_dtree[v6].fc.freq;
    state->ts.d_buf[state->ts.last_dist] = v4;
    flag_bit = state->ts.flag_bit;
    ++state->ts.last_dist;
    state->ts.flags |= flag_bit;
  }
  else
  {
    ++state->ts.dyn_ltree[lc].fc.freq;
  }
  state->ts.flag_bit *= 2;
  if ( (state->ts.last_lit & 7) == 0 )
  {
    state->ts.flag_buf[state->ts.last_flags++] = state->ts.flags;
    *(_WORD *)&state->ts.flags = 256;
  }
  if ( state->level > 2 )
  {
    last_lit = state->ts.last_lit;
    if ( (last_lit & 0xFFF) == 0 )
    {
      v9 = 8 * last_lit;
      v10 = &extra_dbits[1];
      in_length = state->ds.strstart - state->ds.block_start;
      lca = 0;
      statea = nullptr;
      v11 = &state->ts.dyn_dtree[1];
      do
      {
        v9 += (*(v10 - 1) + 5) * v11[-1].fc.freq;
        statea = (TState *)((char *)statea + v11->fc.freq * (*v10 + 5));
        lca += (v10[1] + 5) * v11[1].fc.freq;
        v10 += 3;
        v11 += 3;
      }
      while ( (int)v10 < (int)&extra_blbits[1] );
      v12 = (unsigned int)statea + lca + v9;
      if ( state->ts.last_dist < state->ts.last_lit >> 1 && ((v12 >> 2) & 0x3FFFFFFE) < (in_length & 0xFFFFFFFE) )
        return true;
    }
  }
  return state->ts.last_lit == 0x7FFF || state->ts.last_dist == 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x101FB950
// Name: void set_file_type(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_file_type(TState *state)
{
  int v2; // ecx
  int v3; // edi
  int v4; // ebx
  ct_data *v5; // edx
  ct_data *v6; // edx
  int i; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]
  int statea; // [esp+1Ch] [ebp+8h]
  TState *stateb; // [esp+1Ch] [ebp+8h]

  v2 = state->ts.dyn_ltree[0].fc.freq
     + state->ts.dyn_ltree[1].fc.freq
     + state->ts.dyn_ltree[2].fc.freq
     + state->ts.dyn_ltree[3].fc.freq
     + state->ts.dyn_ltree[4].fc.freq
     + state->ts.dyn_ltree[5].fc.freq
     + state->ts.dyn_ltree[6].fc.freq;
  v3 = 0;
  v4 = 0;
  v5 = &state->ts.dyn_ltree[8];
  for ( statea = 60; statea != 0; --statea )
  {
    v3 += v5[-1].fc.freq;
    v4 += v5->fc.freq;
    v5 += 2;
  }
  stateb = nullptr;
  v8 = 0;
  v6 = &state->ts.dyn_ltree[129];
  for ( i = 64; i != 0; --i )
  {
    stateb = (TState *)((char *)stateb + v6[-1].fc.freq);
    v8 += v6->fc.freq;
    v6 += 2;
  }
  *state->ts.file_type = (v3 + v4 + (unsigned int)state->ts.dyn_ltree[127].fc.freq) >> 2 >= (unsigned int)stateb
                                                                                          + v8
                                                                                          + v2;
}

//------------------------------------------------------------------------------
// Address: 0x101FBA00
// Name: void send_bits(class TState __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl send_bits(TState *state, unsigned int value, int length)
{
  char v3; // dl
  int bi_valid; // ecx
  unsigned int *p_out_offset; // edi

  v3 = length;
  if ( (unsigned int)(length - 1) > 0xE )
    state->err = "invalid length";
  bi_valid = state->bs.bi_valid;
  state->bs.bits_sent += length;
  state->bs.bi_buf |= value << bi_valid;
  state->bs.bi_valid = bi_valid + length;
  if ( bi_valid + length > 16 )
  {
    p_out_offset = &state->bs.out_offset;
    if ( state->bs.out_offset >= state->bs.out_size - 1 )
    {
      state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
      v3 = length;
    }
    if ( *p_out_offset < state->bs.out_size - 1 )
    {
      state->bs.out_buf[*p_out_offset] = state->bs.bi_buf;
      state->bs.out_buf[++*p_out_offset] = BYTE1(state->bs.bi_buf);
      ++*p_out_offset;
      v3 = length;
    }
    state->bs.bi_valid -= 16;
    state->bs.bi_buf = value >> (v3 - LOBYTE(state->bs.bi_valid));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBBC0
// Name: void copy_block(class TState __near &,char __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl copy_block(TState *state, char *block, unsigned int len, int header)
{
  unsigned int *p_out_offset; // edi
  unsigned int (__cdecl *flush_outbuf)(void *, const char *, unsigned int *); // ecx
  unsigned int out_offset; // eax
  void *param; // [esp-18h] [ebp-24h]

  bi_windup(state);
  if ( header != 0 )
  {
    p_out_offset = &state->bs.out_offset;
    if ( state->bs.out_offset >= state->bs.out_size - 1 )
      state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
    if ( *p_out_offset < state->bs.out_size - 1 )
    {
      state->bs.out_buf[*p_out_offset] = len;
      state->bs.out_buf[++*p_out_offset] = BYTE1(len);
      ++*p_out_offset;
    }
    if ( *p_out_offset >= state->bs.out_size - 1 )
      state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
    if ( *p_out_offset < state->bs.out_size - 1 )
    {
      state->bs.out_buf[*p_out_offset] = ~(_BYTE)len;
      state->bs.out_buf[++*p_out_offset] = (unsigned __int16)~(_WORD)len >> 8;
      ++*p_out_offset;
    }
    state->bs.bits_sent += 32;
  }
  if ( state->bs.flush_flg != 0 )
  {
    state->flush_outbuf(a1: state->param, a2: state->bs.out_buf, a3: &state->bs.out_offset);
    flush_outbuf = state->flush_outbuf;
    param = state->param;
    state->bs.out_offset = len;
    flush_outbuf(a1: param, a2: block, a3: &state->bs.out_offset);
    state->bs.bits_sent += 8 * len;
  }
  else
  {
    out_offset = state->bs.out_offset;
    if ( out_offset + len <= state->bs.out_size )
    {
      memcpy(dst: (unsigned __int8 *)&state->bs.out_buf[out_offset], src: (unsigned __int8 *)block, count: len);
      state->bs.out_offset += len;
      state->bs.bits_sent += 8 * len;
    }
    else
    {
      state->bs.bits_sent += 8 * len;
      state->err = "output buffer too small for in-memory compression";
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBD20
// Name: int longest_match(class TState __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl longest_match(TState *state, unsigned int cur_match)
{
  unsigned int strstart; // eax
  unsigned int prev_length; // edi
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v7; // edx
  char *v8; // ecx
  unsigned __int8 *v9; // edx
  char v10; // bl
  char v11; // bl
  char v12; // bl
  char v13; // bl
  char v14; // bl
  char v15; // bl
  char v16; // bl
  char v17; // bl
  int v18; // edx
  unsigned int limit; // [esp+Ch] [ebp-Ch]
  unsigned int chain_length; // [esp+10h] [ebp-8h]
  unsigned __int8 scan_end; // [esp+17h] [ebp-1h]
  char scan_end1_3; // [esp+23h] [ebp+Bh]

  chain_length = state->ds.max_chain_length;
  strstart = state->ds.strstart;
  prev_length = state->ds.prev_length;
  v5 = &state->ds.window[strstart];
  if ( strstart <= 0x7EFA )
    limit = 0;
  else
    limit = strstart - 32506;
  scan_end1_3 = v5[prev_length - 1];
  scan_end = v5[prev_length];
  if ( prev_length >= state->ds.good_match )
    chain_length >>= 2;
  if ( strstart > state->ds.window_size - 262 )
    state->err = "insufficient lookahead";
  do
  {
    if ( cur_match >= state->ds.strstart )
      state->err = "no future";
    v7 = &state->ds.window[cur_match];
    if ( v7[prev_length] == scan_end
      && v7[prev_length - 1] == scan_end1_3
      && *v7 == *v5
      && state->ds.window[cur_match + 1] == v5[1] )
    {
      v8 = (char *)(v5 + 2);
      v9 = &state->ds.window[cur_match + 2];
      do
      {
        v10 = *++v8;
        if ( v10 != v9[1] )
          break;
        v11 = *++v8;
        if ( v11 != v9[2] )
          break;
        v12 = *++v8;
        if ( v12 != v9[3] )
          break;
        v13 = *++v8;
        if ( v13 != v9[4] )
          break;
        v14 = *++v8;
        if ( v14 != v9[5] )
          break;
        v15 = *++v8;
        if ( v15 != v9[6] )
          break;
        v16 = *++v8;
        if ( v16 != v9[7] )
          break;
        v17 = *++v8;
        v9 += 8;
        if ( v17 != *v9 )
          break;
      }
      while ( v8 < (char *)&state->ds.window[state->ds.strstart + 258] );
      if ( v8 > (char *)&state->bs.bits_sent + state->ds.window_size + 3 )
        state->err = "wild scan";
      v18 = v8 - (char *)&state->ds.window[state->ds.strstart + 258] + 258;
      v5 = &state->ds.window[state->ds.strstart];
      if ( v18 > (int)prev_length )
      {
        state->ds.match_start = cur_match;
        prev_length = v18;
        if ( v18 >= state->ds.nice_match )
          return prev_length;
        scan_end1_3 = v5[v18 - 1];
        scan_end = v5[v18];
      }
    }
    cur_match = state->ds.prev[cur_match & 0x7FFF];
    if ( cur_match <= limit )
      break;
    --chain_length;
  }
  while ( chain_length != 0 );
  return prev_length;
}

//------------------------------------------------------------------------------
// Address: 0x101FBED0
// Name: void fill_window(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl fill_window(TState *state)
{
  unsigned int strstart; // eax
  unsigned int v2; // edi
  unsigned int *head; // eax
  int i; // edx
  int v5; // ecx
  unsigned int *prev; // eax
  int j; // edx
  int v8; // ecx
  unsigned int v9; // eax

  do
  {
    strstart = state->ds.strstart;
    v2 = state->ds.window_size - strstart - state->ds.lookahead;
    if ( v2 == -1 )
    {
      v2 = -2;
    }
    else if ( strstart >= 0xFEFA && state->ds.sliding != 0 )
    {
      memcpy(dst: state->ds.window, src: &state->ds.window[0x8000], count: 0x8000u);
      state->ds.match_start -= 0x8000;
      state->ds.strstart -= 0x8000;
      state->ds.block_start -= 0x8000;
      head = state->ds.head;
      for ( i = 0x8000; i != 0; --i )
      {
        if ( *head < 0x8000 )
          v5 = 0;
        else
          v5 = *head - 0x8000;
        *head++ = v5;
      }
      prev = state->ds.prev;
      for ( j = 0x8000; j != 0; --j )
      {
        if ( *prev < 0x8000 )
          v8 = 0;
        else
          v8 = *prev - 0x8000;
        *prev++ = v8;
      }
      v2 += 0x8000;
    }
    if ( state->ds.eofile != 0 )
      break;
    if ( v2 < 2 )
      state->err = "more < 2";
    v9 = state->readfunc(a1: state, a2: (char *)&state->ds.window[state->ds.strstart + state->ds.lookahead], a3: v2);
    if ( v9 == 0 || v9 == -1 )
      state->ds.eofile = 1;
    else
      state->ds.lookahead += v9;
  }
  while ( state->ds.lookahead < 0x106 && state->ds.eofile == 0 );
}

//------------------------------------------------------------------------------
// Address: 0x101FC030
// Name: int putlocal(struct zlist __near *,unsigned int (*)(void __near *,char const __near *,unsigned int),void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl putlocal(zlist *z, unsigned int (__cdecl *wfunc)(void *, const char *, unsigned int), void *param)
{
  void *v3; // esi
  unsigned int (__cdecl *v4)(void *, const char *, unsigned int); // edi
  char _putsh_c; // [esp+Fh] [ebp-1h] BYREF

  v3 = param;
  v4 = wfunc;
  _putsh_c = 80;
  wfunc(a1: param, a2: &_putsh_c, a3: 1u);
  _putsh_c = 75;
  v4(a1: v3, a2: &_putsh_c, a3: 1u);
  HIBYTE(wfunc) = 3;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 4;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->ver;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->ver);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->lflg;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->lflg);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->how;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->how);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->tim;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->tim);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->tim);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->tim);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->crc;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->siz;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->len;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->nam;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->nam);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->ext;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->ext);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  if ( v4(a1: v3, a2: z->iname, a3: z->nam) == z->nam && (z->ext == 0 || v4(a1: v3, a2: z->extra, a3: z->ext) == z->ext) )
    return 0;
  else
    return 10;
}

//------------------------------------------------------------------------------
// Address: 0x101FC270
// Name: int putextended(struct zlist __near *,unsigned int (*)(void __near *,char const __near *,unsigned int),void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl putextended(zlist *z, unsigned int (__cdecl *wfunc)(void *, const char *, unsigned int), void *param)
{
  void *v3; // esi
  unsigned int (__cdecl *v4)(void *, const char *, unsigned int); // edi
  char _putsh_c; // [esp+Fh] [ebp-1h] BYREF

  v3 = param;
  v4 = wfunc;
  _putsh_c = 80;
  wfunc(a1: param, a2: &_putsh_c, a3: 1u);
  _putsh_c = 75;
  v4(a1: v3, a2: &_putsh_c, a3: 1u);
  HIBYTE(wfunc) = 7;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 8;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->crc;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->crc);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->siz;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->siz);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->len;
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->len);
  v4(a1: v3, a2: (const char *)&wfunc + 3, a3: 1u);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FC390
// Name: int putcentral(struct zlist __near *,unsigned int (*)(void __near *,char const __near *,unsigned int),void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl putcentral(zlist *z, unsigned int (__cdecl *wfunc)(void *, const char *, unsigned int), void *param)
{
  unsigned int (__cdecl *v3)(void *, const char *, unsigned int); // ebx
  void *v4; // edi
  char _putsh_c; // [esp+Fh] [ebp-1h] BYREF

  v3 = wfunc;
  v4 = param;
  _putsh_c = 80;
  wfunc(a1: param, a2: &_putsh_c, a3: 1u);
  _putsh_c = 75;
  v3(a1: v4, a2: &_putsh_c, a3: 1u);
  HIBYTE(wfunc) = 1;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 2;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->vem;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->vem);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->ver;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->ver);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->flg;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->flg);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->how;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->how);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->tim;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->tim);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->tim);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->tim);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->crc;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->crc);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->crc);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->crc);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->siz;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->siz);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->siz);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->siz);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->len;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->len);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->len);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->len);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->nam;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->nam);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->cext;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->cext);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->com;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->com);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->dsk;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->dsk);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->att;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->att);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->atx;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->atx);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->atx);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->atx);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = z->off;
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE1(z->off);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = BYTE2(z->off);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = HIBYTE(z->off);
  v3(a1: v4, a2: (const char *)&wfunc + 3, a3: 1u);
  if ( v3(a1: v4, a2: z->iname, a3: z->nam) == z->nam
    && (z->cext == 0 || v3(a1: v4, a2: z->cextra, a3: z->cext) == z->cext)
    && (z->com == 0 || v3(a1: v4, a2: z->comment, a3: z->com) == z->com) )
  {
    return 0;
  }
  else
  {
    return 10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FC6F0
// Name: int putend(int,unsigned long,unsigned long,unsigned int,char __near *,unsigned int (*)(void __near *,char const __near *,unsigned int),void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl putend(
        int n,
        unsigned int s,
        unsigned int c,
        unsigned int m,
        char *z,
        unsigned int (__cdecl *wfunc)(void *, const char *, unsigned int),
        void *param)
{
  void *v7; // esi
  unsigned int (__cdecl *v8)(void *, const char *, unsigned int); // edi
  int v9; // ebx
  unsigned int v10; // ebx
  unsigned int v11; // ebx
  unsigned int v12; // ebx
  char _putsh_c; // [esp+Fh] [ebp-1h] BYREF

  v7 = param;
  v8 = wfunc;
  _putsh_c = 80;
  wfunc(a1: param, a2: &_putsh_c, a3: 1u);
  _putsh_c = 75;
  v8(a1: v7, a2: &_putsh_c, a3: 1u);
  HIBYTE(wfunc) = 5;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 6;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 0;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 0;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 0;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(wfunc) = 0;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  v9 = n;
  HIBYTE(wfunc) = n;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  v9 >>= 8;
  HIBYTE(wfunc) = v9;
  v8(a1: v7, a2: (const char *)&wfunc + 3, a3: 1u);
  HIBYTE(n) = n;
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = v9;
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  v10 = s;
  HIBYTE(n) = s;
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = BYTE1(v10);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = BYTE2(v10);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = HIBYTE(v10);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  v11 = c;
  HIBYTE(n) = c;
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = BYTE1(v11);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = BYTE2(v11);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = HIBYTE(v11);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  v12 = m;
  HIBYTE(n) = m;
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  HIBYTE(n) = BYTE1(v12);
  v8(a1: v7, a2: (const char *)&n + 3, a3: 1u);
  if ( v12 == 0 || v8(a1: v7, a2: z, a3: v12) == v12 )
    return 0;
  else
    return 10;
}

//------------------------------------------------------------------------------
// Address: 0x101FC880
// Name: unsigned long crc32(unsigned long,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl crc32(unsigned int crc, const unsigned __int8 *buf, unsigned int len)
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
      v8 = crc_table_0[(unsigned __int8)(v6 ^ *v3)] ^ (v6 >> 8);
      v9 = crc_table_0[(unsigned __int8)(v8 ^ v3[1])] ^ (v8 >> 8);
      v10 = crc_table_0[(unsigned __int8)(v9 ^ v3[2])] ^ (v9 >> 8);
      v11 = crc_table_0[(unsigned __int8)(v10 ^ v3[3])] ^ (v10 >> 8);
      v12 = crc_table_0[(unsigned __int8)(v11 ^ v3[4])] ^ (v11 >> 8);
      v13 = crc_table_0[(unsigned __int8)(v12 ^ v3[5])] ^ (v12 >> 8);
      v14 = crc_table_0[(unsigned __int8)(v13 ^ v3[6])] ^ (v13 >> 8);
      v6 = crc_table_0[(unsigned __int8)(v14 ^ v3[7])] ^ (v14 >> 8);
      v3 += 8;
      v5 -= 8;
      --v7;
    }
    while ( v7 != 0 );
  }
  for ( ; v5 != 0; --v5 )
    v6 = crc_table_0[(unsigned __int8)(v6 ^ *v3++)] ^ (v6 >> 8);
  return ~v6;
}

//------------------------------------------------------------------------------
// Address: 0x101FC990
// Name: bool HasZipSuffix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HasZipSuffix(const char *fn)
{
  unsigned int v1; // eax
  const char *v2; // esi
  bool v3; // zf

  v1 = strlen(fn);
  v2 = &fn[v1];
  v3 = &fn[v1] == fn;
  if ( &fn[v1] > fn )
  {
    do
    {
      if ( *v2 == 46 )
        break;
      --v2;
    }
    while ( v2 > fn );
    v3 = v2 == fn;
  }
  if ( v3 && *v2 != 46 )
    return false;
  if ( _stricmp(dst: v2, src: ".Z") == 0
    || _stricmp(dst: v2, src: ".zip") == 0
    || _stricmp(dst: v2, src: ".zoo") == 0
    || _stricmp(dst: v2, src: ".arc") == 0
    || _stricmp(dst: v2, src: ".lzh") == 0
    || _stricmp(dst: v2, src: ".arj") == 0
    || _stricmp(dst: v2, src: ".gz") == 0 )
  {
    return true;
  }
  return _stricmp(dst: v2, src: ".tgz") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FCA70
// Name: __int64 filetime2timet(struct _FILETIME)
// Source: json
//------------------------------------------------------------------------------
int __cdecl filetime2timet(_FILETIME ft)
{
  _SYSTEMTIME st; // [esp+24h] [ebp-10h] BYREF

  FileTimeToSystemTime(lpFileTime: &ft, lpSystemTime: &st);
  if ( st.wYear >= 0x7B2u )
  {
    if ( st.wYear >= 0x7F6u )
    {
      *(_DWORD *)&st.wYear = 788469;
      st.wDay = 31;
    }
  }
  else
  {
    *(_DWORD *)&st.wYear = 67506;
    st.wDay = 1;
  }
  return _mktime64();
}

//------------------------------------------------------------------------------
// Address: 0x101FCB10
// Name: unsigned long GetFileInfo(void __near *,unsigned long __near *,long __near *,struct iztimes __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetFileInfo(void *hf, unsigned int *attr, int *size, iztimes *times, unsigned int *timestamp)
{
  int v6; // edi
  unsigned int v7; // edi
  int v8; // edi
  int v9; // eax
  unsigned int dwHighDateTime; // ecx
  int v11; // edx
  int v12; // eax
  unsigned int dwLowDateTime; // ecx
  int v14; // edx
  int v15; // edx
  _FILETIME v16; // [esp-18h] [ebp-68h]
  _FILETIME v17; // [esp-10h] [ebp-60h]
  _BY_HANDLE_FILE_INFORMATION bhi; // [esp+4h] [ebp-4Ch] BYREF
  unsigned int signature; // [esp+38h] [ebp-18h] BYREF
  unsigned int hpos; // [esp+3Ch] [ebp-14h] BYREF
  unsigned int hsize; // [esp+40h] [ebp-10h]
  unsigned int red; // [esp+44h] [ebp-Ch] BYREF
  int dostime; // [esp+48h] [ebp-8h] BYREF
  unsigned __int16 dosdate; // [esp+4Ch] [ebp-4h] BYREF

  if ( GetFileType(hFile: hf) != 1 )
    return 0x1000000;
  if ( !GetFileInformationByHandle(hFile: hf, lpFileInformation: &bhi) )
    return 512;
  FileTimeToLocalFileTime(lpFileTime: &bhi.ftLastAccessTime, lpLocalFileTime: &bhi.ftLastAccessTime);
  FileTimeToLocalFileTime(lpFileTime: &bhi.ftLastWriteTime, lpLocalFileTime: &bhi.ftLastWriteTime);
  FileTimeToLocalFileTime(lpFileTime: &bhi.ftCreationTime, lpLocalFileTime: &bhi.ftCreationTime);
  v6 = 0;
  if ( (bhi.dwFileAttributes & 1) != 0 )
  {
    dostime = 1;
    v6 = 1;
  }
  if ( (bhi.dwFileAttributes & 2) != 0 )
    v6 |= 2u;
  if ( (bhi.dwFileAttributes & 4) != 0 )
    v6 |= 4u;
  if ( (bhi.dwFileAttributes & 0x10) != 0 )
    v6 |= 0x10u;
  if ( (bhi.dwFileAttributes & 0x20) != 0 )
    v6 |= 0x20u;
  if ( (bhi.dwFileAttributes & 0x10) != 0 )
    v7 = v6 | 0x40000000;
  else
    v7 = v6 | 0x80000000;
  v8 = v7 | 0x1000000;
  dostime = v8;
  if ( (bhi.dwFileAttributes & 1) == 0 )
  {
    v8 |= 0x800000u;
    dostime = v8;
  }
  hsize = GetFileSize(hFile: hf, lpFileSizeHigh: nullptr);
  if ( hsize > 0x28 )
  {
    SetFilePointer(hFile: hf, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 0);
    ReadFile(hFile: hf, lpBuffer: &dosdate, nNumberOfBytesToRead: 2u, lpNumberOfBytesRead: &red, lpOverlapped: nullptr);
    SetFilePointer(hFile: hf, lDistanceToMove: 36, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 0);
    ReadFile(hFile: hf, lpBuffer: &hpos, nNumberOfBytesToRead: 4u, lpNumberOfBytesRead: &red, lpOverlapped: nullptr);
    if ( dosdate == 21677 && hsize > hpos + 52 )
    {
      SetFilePointer(hFile: hf, lDistanceToMove: hpos, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 0);
      ReadFile(
        hFile: hf,
        lpBuffer: &signature,
        nNumberOfBytesToRead: 4u,
        lpNumberOfBytesRead: &red,
        lpOverlapped: nullptr);
      if ( signature == 23117 || signature == 17742 || signature == 17740 || signature == 17744 )
        dostime |= 0x400000u;
    }
    v8 = dostime;
  }
  if ( attr != nullptr )
    *attr = v8;
  if ( size != nullptr )
    *size = hsize;
  if ( times != nullptr )
  {
    v9 = filetime2timet(ft: bhi.ftLastAccessTime);
    dwHighDateTime = bhi.ftLastWriteTime.dwHighDateTime;
    HIDWORD(times->atime) = v11;
    v17 = (_FILETIME)__PAIR64__(dwHighDateTime, bhi.ftLastWriteTime.dwLowDateTime);
    LODWORD(times->atime) = v9;
    v12 = filetime2timet(ft: v17);
    dwLowDateTime = bhi.ftCreationTime.dwLowDateTime;
    LODWORD(times->mtime) = v12;
    v16 = (_FILETIME)__PAIR64__(bhi.ftCreationTime.dwHighDateTime, dwLowDateTime);
    HIDWORD(times->mtime) = v14;
    LODWORD(times->ctime) = filetime2timet(ft: v16);
    HIDWORD(times->ctime) = v15;
  }
  if ( timestamp != nullptr )
  {
    FileTimeToDosDateTime(lpFileTime: &bhi.ftLastWriteTime, lpFatDate: &dosdate, lpFatTime: (LPWORD)&dostime);
    *timestamp = (unsigned __int16)dostime | (dosdate << 16);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FCD00
// Name: public: unsigned long TZip::Create(void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::Create(TZip *this, void *z, unsigned int len, unsigned int flags)
{
  HANDLE FileMappingA; // eax
  char *v7; // eax
  HANDLE v8; // eax
  DWORD FileType; // eax
  HANDLE FileA; // eax
  HANDLE CurrentProcess; // [esp-18h] [ebp-20h]

  if ( this->hfout != nullptr
    || this->hmapout != nullptr
    || this->obuf != nullptr
    || this->writ != 0
    || this->oerr != 0
    || this->hasputcen )
  {
    return 0x1000000;
  }
  if ( flags != 3 )
  {
    if ( flags == 1 )
    {
      CurrentProcess = GetCurrentProcess();
      v8 = GetCurrentProcess();
      if ( !DuplicateHandle(
              hSourceProcessHandle: v8,
              hSourceHandle: z,
              hTargetProcessHandle: CurrentProcess,
              lpTargetHandle: &this->hfout,
              dwDesiredAccess: 0,
              bInheritHandle: false,
              dwOptions: 2u) )
        return 256;
      FileType = GetFileType(hFile: this->hfout);
      this->ocanseek = FileType == 1;
      if ( FileType == 1 )
      {
        this->ooffset = SetFilePointer(
                          hFile: this->hfout,
                          lDistanceToMove: 0,
                          lpDistanceToMoveHigh: nullptr,
                          dwMoveMethod: 1u);
        return 0;
      }
    }
    else
    {
      if ( flags != 2 )
        return 0x10000;
      FileA = CreateFileA(
                lpFileName: (LPCSTR)z,
                dwDesiredAccess: 0x40000000u,
                dwShareMode: 0,
                lpSecurityAttributes: nullptr,
                dwCreationDisposition: 2u,
                dwFlagsAndAttributes: 0x80u,
                hTemplateFile: nullptr);
      this->hfout = FileA;
      if ( FileA == (HANDLE)-1 )
      {
        this->hfout = nullptr;
        return 512;
      }
      this->ocanseek = true;
    }
    this->ooffset = 0;
    return 0;
  }
  if ( len == 0 )
    return 196608;
  if ( z != nullptr )
  {
    this->obuf = (char *)z;
LABEL_12:
    this->mapsize = len;
    this->opos = 0;
    this->ocanseek = true;
    return 0;
  }
  FileMappingA = CreateFileMappingA(
                   hFile: (HANDLE)0xFFFFFFFF,
                   lpFileMappingAttributes: nullptr,
                   flProtect: 4u,
                   dwMaximumSizeHigh: 0,
                   dwMaximumSizeLow: len,
                   lpName: nullptr);
  this->hmapout = FileMappingA;
  if ( FileMappingA != nullptr )
  {
    v7 = (char *)MapViewOfFile(
                   hFileMappingObject: FileMappingA,
                   dwDesiredAccess: 0xF001Fu,
                   dwFileOffsetHigh: 0,
                   dwFileOffsetLow: 0,
                   dwNumberOfBytesToMap: len);
    this->obuf = v7;
    if ( v7 != nullptr )
      goto LABEL_12;
    CloseHandle(hObject: this->hmapout);
    this->hmapout = nullptr;
  }
  return 768;
}

//------------------------------------------------------------------------------
// Address: 0x101FCE80
// Name: public: unsigned int TZip::write(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::write(TZip *this, char *buf, unsigned int size)
{
  char *obuf; // ecx
  unsigned int opos; // eax
  unsigned int v6; // edi

  obuf = this->obuf;
  if ( obuf != nullptr )
  {
    opos = this->opos;
    v6 = size;
    if ( opos + size < this->mapsize )
    {
      memcpy(dst: (unsigned __int8 *)&obuf[opos], src: (unsigned __int8 *)buf, count: size);
      this->opos += v6;
      return v6;
    }
    else
    {
      this->oerr = 196608;
      return 0;
    }
  }
  else if ( this->hfout != nullptr )
  {
    WriteFile(
      hFile: this->hfout,
      lpBuffer: buf,
      nNumberOfBytesToWrite: size,
      lpNumberOfBytesWritten: &size,
      lpOverlapped: nullptr);
    return size;
  }
  else
  {
    this->oerr = 0x1000000;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCF00
// Name: public: bool TZip::oseek(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall TZip::oseek(TZip *this, unsigned int pos)
{
  if ( this->ocanseek )
  {
    if ( this->obuf != nullptr )
    {
      if ( pos < this->mapsize )
      {
        this->opos = pos;
        return 1;
      }
      else
      {
        this->oerr = 196608;
        return 0;
      }
    }
    else if ( this->hfout != nullptr )
    {
      SetFilePointer(
        hFile: this->hfout,
        lDistanceToMove: pos + this->ooffset,
        lpDistanceToMoveHigh: nullptr,
        dwMoveMethod: 0);
      return 1;
    }
    else
    {
      this->oerr = 0x1000000;
      return 0;
    }
  }
  else
  {
    this->oerr = 0x2000000;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCF70
// Name: public: unsigned long TZip::open_handle(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::open_handle(TZip *this, void *hf, unsigned int len)
{
  void *v4; // edi
  int *p_isize; // ebx
  unsigned int result; // eax
  unsigned int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  unsigned int v12; // edx
  _SYSTEMTIME st; // [esp+Ch] [ebp-18h] BYREF
  _FILETIME ft; // [esp+1Ch] [ebp-8h] BYREF

  v4 = hf;
  p_isize = &this->isize;
  this->hfin = nullptr;
  this->bufin = nullptr;
  this->selfclosehf = false;
  this->crc = 0;
  this->isize = 0;
  this->csize = 0;
  this->ired = 0;
  if ( v4 == nullptr || v4 == (void *)-1 )
    return 0x10000;
  if ( GetFileType(hFile: v4) == 1 )
  {
    result = GetFileInfo(hf: v4, attr: &this->attr, size: p_isize, times: &this->times, timestamp: &this->timestamp);
    if ( result == 0 )
    {
      SetFilePointer(hFile: v4, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 0);
      this->hfin = v4;
      this->iseekable = true;
      return 0;
    }
  }
  else
  {
    v7 = len;
    this->attr = 0x80000000;
    *p_isize = -1;
    if ( v7 != 0 )
      *p_isize = v7;
    this->iseekable = false;
    GetLocalTime(lpSystemTime: &st);
    SystemTimeToFileTime(lpSystemTime: &st, lpFileTime: &ft);
    FileTimeToDosDateTime(lpFileTime: &ft, lpFatDate: (LPWORD)&hf, lpFatTime: (LPWORD)&len);
    v8 = filetime2timet(ft);
    v10 = v9;
    HIDWORD(this->times.atime) = v9;
    v11 = (unsigned __int16)hf;
    LODWORD(this->times.atime) = v8;
    LODWORD(this->times.mtime) = v8;
    LODWORD(this->times.ctime) = v8;
    v12 = (unsigned __int16)len | (v11 << 16);
    this->hfin = v4;
    HIDWORD(this->times.mtime) = v10;
    HIDWORD(this->times.ctime) = v10;
    this->timestamp = v12;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FD090
// Name: public: unsigned long TZip::open_mem(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::open_mem(TZip *this, const char *src, unsigned int len)
{
  const char *v3; // edx
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  unsigned int v10; // edx
  _SYSTEMTIME st; // [esp+4h] [ebp-18h] BYREF
  _FILETIME ft; // [esp+14h] [ebp-8h] BYREF

  v3 = src;
  v5 = len;
  this->hfin = nullptr;
  this->bufin = v3;
  this->selfclosehf = false;
  this->crc = 0;
  this->csize = 0;
  this->ired = 0;
  this->lenin = v5;
  this->posin = 0;
  if ( v3 == nullptr || v5 == 0 )
    return 0x10000;
  this->attr = 0x80000000;
  this->isize = v5;
  this->iseekable = true;
  GetLocalTime(lpSystemTime: &st);
  SystemTimeToFileTime(lpSystemTime: &st, lpFileTime: &ft);
  FileTimeToDosDateTime(lpFileTime: &ft, lpFatDate: (LPWORD)&src, lpFatTime: (LPWORD)&len);
  v6 = filetime2timet(ft);
  v8 = v7;
  HIDWORD(this->times.atime) = v7;
  v9 = (unsigned __int16)src;
  LODWORD(this->times.atime) = v6;
  LODWORD(this->times.mtime) = v6;
  LODWORD(this->times.ctime) = v6;
  v10 = (unsigned __int16)len | (v9 << 16);
  HIDWORD(this->times.mtime) = v8;
  HIDWORD(this->times.ctime) = v8;
  this->timestamp = v10;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FD150
// Name: public: unsigned long TZip::open_dir(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::open_dir(TZip *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  unsigned int v6; // edx
  _SYSTEMTIME st; // [esp+4h] [ebp-20h] BYREF
  _FILETIME ft; // [esp+14h] [ebp-10h] BYREF
  unsigned __int16 dostime; // [esp+1Ch] [ebp-8h] BYREF
  unsigned __int16 dosdate; // [esp+20h] [ebp-4h] BYREF

  this->hfin = nullptr;
  this->bufin = nullptr;
  this->selfclosehf = false;
  this->crc = 0;
  this->csize = 0;
  this->ired = 0;
  this->isize = 0;
  this->iseekable = false;
  this->attr = 1103101968;
  GetLocalTime(lpSystemTime: &st);
  SystemTimeToFileTime(lpSystemTime: &st, lpFileTime: &ft);
  FileTimeToDosDateTime(lpFileTime: &ft, lpFatDate: &dosdate, lpFatTime: &dostime);
  v2 = filetime2timet(ft);
  v4 = v3;
  HIDWORD(this->times.atime) = v3;
  v5 = dosdate;
  LODWORD(this->times.atime) = v2;
  LODWORD(this->times.mtime) = v2;
  LODWORD(this->times.ctime) = v2;
  v6 = dostime | (v5 << 16);
  HIDWORD(this->times.mtime) = v4;
  HIDWORD(this->times.ctime) = v4;
  this->timestamp = v6;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FD1E0
// Name: public: unsigned int TZip::read(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::read(TZip *this, char *buf, DWORD size)
{
  const char *bufin; // ecx
  unsigned int posin; // eax
  unsigned int lenin; // edi
  unsigned int v7; // edi
  unsigned int v8; // eax
  void *hfin; // eax
  unsigned int v11; // edi
  unsigned int crc; // eax

  bufin = this->bufin;
  if ( bufin == nullptr )
  {
    hfin = this->hfin;
    if ( hfin != nullptr )
    {
      if ( ReadFile(
             hFile: hfin,
             lpBuffer: buf,
             nNumberOfBytesToRead: size,
             lpNumberOfBytesRead: &size,
             lpOverlapped: nullptr) )
      {
        v11 = size;
        crc = this->crc;
        this->ired += size;
        this->crc = crc32(crc, (const unsigned __int8 *)buf, len: v11);
        return v11;
      }
    }
    else
    {
      this->oerr = 0x1000000;
    }
    return 0;
  }
  posin = this->posin;
  lenin = this->lenin;
  if ( posin >= lenin )
    return 0;
  v7 = lenin - posin;
  if ( v7 > size )
    v7 = size;
  memcpy(dst: (unsigned __int8 *)buf, src: (unsigned __int8 *)&bufin[posin], count: v7);
  v8 = this->crc;
  this->posin += v7;
  this->ired += v7;
  this->crc = crc32(crc: v8, (const unsigned __int8 *)buf, len: v7);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101FD280
// Name: public: unsigned long TZip::iclose(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::iclose(TZip *this)
{
  int isize; // eax

  if ( this->selfclosehf && this->hfin != nullptr )
    CloseHandle(hObject: this->hfin);
  isize = this->isize;
  this->hfin = nullptr;
  if ( isize == -1 || isize == this->ired )
  {
    this->isize = this->ired;
    return 0;
  }
  else
  {
    this->isize = this->ired;
    return 393216;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD2E0
// Name: public: unsigned long TZip::istore(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::istore(TZip *this)
{
  char *buf; // ebx
  unsigned int i; // edi
  char *obuf; // ecx
  unsigned int opos; // eax
  unsigned int v6; // eax
  unsigned int NumberOfBytesWritten; // [esp+Ch] [ebp-8h] BYREF
  unsigned int size; // [esp+10h] [ebp-4h]

  buf = this->buf;
  size = 0;
  for ( i = TZip::read(this, buf: this->buf, size: 0x4000u); i != 0; i = TZip::read(this, buf, size: 0x4000u) )
  {
    if ( i == -1 )
      break;
    obuf = this->obuf;
    if ( obuf != nullptr )
    {
      opos = this->opos;
      if ( opos + i < this->mapsize )
      {
        memcpy(dst: (unsigned __int8 *)&obuf[opos], src: (unsigned __int8 *)buf, count: i);
        this->opos += i;
        goto LABEL_12;
      }
      this->oerr = 196608;
    }
    else
    {
      if ( this->hfout != nullptr )
      {
        WriteFile(
          hFile: this->hfout,
          lpBuffer: buf,
          nNumberOfBytesToWrite: i,
          lpNumberOfBytesWritten: &NumberOfBytesWritten,
          lpOverlapped: nullptr);
        v6 = NumberOfBytesWritten;
        goto LABEL_11;
      }
      this->oerr = 0x1000000;
    }
    v6 = 0;
LABEL_11:
    if ( v6 != i )
      return 393216;
LABEL_12:
    size += i;
  }
  this->csize = size;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FD390
// Name: void gen_codes(class TState __near &,struct ct_data __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl gen_codes(TState *state, ct_data *tree, int max_code)
{
  __int16 v3; // ax
  int v4; // ecx
  unsigned __int16 *bl_count; // edx
  unsigned __int16 v6; // di
  int i; // esi
  int dad; // edx
  unsigned int v9; // ecx
  unsigned int v10; // eax
  int v11; // ebx
  unsigned __int16 next_code[16]; // [esp+8h] [ebp-20h]

  v3 = 0;
  v4 = 1;
  bl_count = state->ts.bl_count;
  do
  {
    v6 = 2 * (v3 + *bl_count);
    v3 = v6;
    next_code[v4++] = v6;
    ++bl_count;
  }
  while ( v4 <= 15 );
  if ( state->ts.bl_count[15] + v6 != 0x8000 )
    state->err = "inconsistent bit counts";
  for ( i = 0; i <= max_code; ++i )
  {
    dad = tree[i].dl.dad;
    if ( tree[i].dl.dad != 0 )
    {
      v9 = next_code[dad];
      next_code[dad] = v9 + 1;
      v10 = 0;
      do
      {
        v11 = v9 & 1;
        --dad;
        v9 >>= 1;
        v10 = 2 * (v11 | v10);
      }
      while ( dad > 0 );
      tree[i].fc.freq = v10 >> 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD430
// Name: void build_tree(class TState __near &,struct tree_desc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl build_tree(TState *state, tree_desc *desc)
{
  tree_desc *v2; // edx
  int elems; // ecx
  ct_data *static_tree; // ebx
  ct_data *dyn_tree; // edi
  int v6; // eax
  int v7; // eax
  int i; // ebx
  int heap_len; // eax
  int v10; // ebx
  int v11; // eax
  unsigned __int8 v12; // dl
  int node; // [esp+Ch] [ebp-8h]
  int max_code; // [esp+10h] [ebp-4h]

  v2 = desc;
  elems = desc->elems;
  static_tree = desc->static_tree;
  dyn_tree = desc->dyn_tree;
  v6 = 0;
  max_code = -1;
  node = elems;
  state->ts.heap_len = 0;
  state->ts.heap_max = 573;
  if ( elems > 0 )
  {
    do
    {
      if ( dyn_tree[v6].fc.freq != 0 )
      {
        state->ts.heap[++state->ts.heap_len] = v6;
        max_code = v6;
        state->ts.depth[v6] = 0;
      }
      else
      {
        dyn_tree[v6].dl.dad = 0;
      }
      ++v6;
    }
    while ( v6 < elems );
    v2 = desc;
  }
  while ( state->ts.heap_len < 2 )
  {
    if ( max_code >= 2 )
      v7 = 0;
    else
      v7 = ++max_code;
    state->ts.heap[++state->ts.heap_len] = v7;
    dyn_tree[v7].fc.freq = 1;
    state->ts.depth[v7] = 0;
    --state->ts.opt_len;
    if ( static_tree != nullptr )
      state->ts.static_len -= static_tree[v7].dl.dad;
  }
  v2->max_code = max_code;
  for ( i = state->ts.heap_len / 2; i >= 1; --i )
    pqdownheap(state, tree: dyn_tree, k: i);
  do
  {
    heap_len = state->ts.heap_len;
    v10 = state->ts.heap[1];
    state->ts.heap[1] = state->ts.heap[heap_len];
    state->ts.heap_len = heap_len - 1;
    pqdownheap(state, tree: dyn_tree, k: 1);
    v11 = state->ts.heap[1];
    --state->ts.heap_max;
    state->ts.heap[state->ts.heap_max--] = v10;
    state->ts.heap[state->ts.heap_max] = v11;
    dyn_tree[node].fc.freq = dyn_tree[v10].fc.freq + dyn_tree[v11].fc.freq;
    v12 = state->ts.depth[v10];
    if ( v12 < state->ts.depth[v11] )
      v12 = state->ts.depth[v11];
    state->ts.depth[node] = v12 + 1;
    dyn_tree[v11].dl.dad = node;
    dyn_tree[v10].dl.dad = node;
    state->ts.heap[1] = node++;
    pqdownheap(state, tree: dyn_tree, k: 1);
  }
  while ( state->ts.heap_len >= 2 );
  state->ts.heap[--state->ts.heap_max] = state->ts.heap[1];
  gen_bitlen(state, desc);
  gen_codes(state, tree: dyn_tree, max_code);
}

//------------------------------------------------------------------------------
// Address: 0x101FD630
// Name: void send_tree(class TState __near &,struct ct_data __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl send_tree(TState *state, ct_data *tree, int max_code)
{
  int dad; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // ecx
  ct_data::<unnamed_type_dl> *p_dl; // edx
  int v8; // edx
  unsigned int v9; // ebx
  bool v10; // zf
  int v11; // [esp+Ch] [ebp-8h]
  int prevlen; // [esp+10h] [ebp-4h]
  int nextlen; // [esp+20h] [ebp+Ch]
  ct_data::<unnamed_type_dl> *max_codea; // [esp+24h] [ebp+10h]

  dad = tree->dl.dad;
  v4 = 0;
  prevlen = -1;
  v5 = 7;
  v6 = 4;
  if ( tree->dl.dad == 0 )
  {
    v5 = 138;
    v6 = 3;
  }
  if ( max_code >= 0 )
  {
    p_dl = &tree[1].dl;
    v11 = max_code + 1;
    max_codea = &tree[1].dl;
    while ( 1 )
    {
      v8 = p_dl->dad;
      ++v4;
      nextlen = v8;
      if ( v4 >= v5 || dad != v8 )
      {
        if ( v4 >= v6 )
        {
          if ( dad != 0 )
          {
            if ( dad != prevlen )
            {
              send_bits(state, value: state->ts.bl_tree[dad].fc.freq, length: state->ts.bl_tree[dad].dl.dad);
              --v4;
            }
            v9 = v4 - 3;
            if ( v9 > 3 )
              state->err = " 3_6?";
            send_bits(state, value: state->ts.bl_tree[16].fc.freq, length: state->ts.bl_tree[16].dl.dad);
            send_bits(state, value: v9, length: 2);
          }
          else if ( v4 > 10 )
          {
            send_bits(state, value: state->ts.bl_tree[18].fc.freq, length: state->ts.bl_tree[18].dl.dad);
            send_bits(state, value: v4 - 11, length: 7);
          }
          else
          {
            send_bits(state, value: state->ts.bl_tree[17].fc.freq, length: state->ts.bl_tree[17].dl.dad);
            send_bits(state, value: v4 - 3, length: 3);
          }
        }
        else
        {
          do
          {
            send_bits(state, value: state->ts.bl_tree[dad].fc.freq, length: state->ts.bl_tree[dad].dl.dad);
            --v4;
          }
          while ( v4 != 0 );
        }
        v4 = 0;
        prevlen = dad;
        if ( nextlen != 0 )
        {
          if ( dad == nextlen )
          {
            v5 = 6;
            v6 = 3;
          }
          else
          {
            v5 = 7;
            v6 = 4;
          }
        }
        else
        {
          v5 = 138;
          v6 = 3;
        }
      }
      p_dl = max_codea + 2;
      v10 = v11-- == 1;
      max_codea += 2;
      if ( v10 )
        break;
      dad = nextlen;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD790
// Name: int build_bl_tree(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl build_bl_tree(TState *state)
{
  int result; // eax

  scan_tree(state, tree: state->ts.dyn_ltree, max_code: state->ts.l_desc.max_code);
  scan_tree(state, tree: state->ts.dyn_dtree, max_code: state->ts.d_desc.max_code);
  build_tree(state, desc: &state->ts.bl_desc);
  result = 18;
  while ( state->ts.bl_tree[bl_order[result]].dl.dad == 0 )
  {
    if ( state->ts.bl_tree[*((unsigned __int8 *)&extra_lbits[28] + result + 3)].dl.dad != 0 )
    {
      --result;
      state->ts.opt_len += 3 * result + 17;
      return result;
    }
    if ( state->ts.bl_tree[*((unsigned __int8 *)&extra_lbits[28] + result + 2)].dl.dad != 0 )
    {
      result -= 2;
      state->ts.opt_len += 3 * result + 17;
      return result;
    }
    if ( state->ts.bl_tree[*((unsigned __int8 *)&extra_lbits[28] + result + 1)].dl.dad != 0 )
    {
      result -= 3;
      break;
    }
    result -= 4;
    if ( result < 3 )
    {
      state->ts.opt_len += 3 * result + 17;
      return result;
    }
  }
  state->ts.opt_len += 3 * result + 17;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FD870
// Name: void send_all_trees(class TState __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl send_all_trees(TState *state, int lcodes, int dcodes, int blcodes)
{
  int i; // edi

  if ( lcodes < 257 || dcodes < 1 || blcodes < 4 )
    state->err = "not enough codes";
  if ( lcodes > 286 || dcodes > 30 || blcodes > 19 )
    state->err = "too many codes";
  send_bits(state, value: lcodes - 257, length: 5);
  send_bits(state, value: dcodes - 1, length: 5);
  send_bits(state, value: blcodes - 4, length: 4);
  for ( i = 0; i < blcodes; ++i )
    send_bits(state, value: state->ts.bl_tree[bl_order[i]].dl.dad, length: 3);
  send_tree(state, tree: state->ts.dyn_ltree, max_code: lcodes - 1);
  send_tree(state, tree: state->ts.dyn_dtree, max_code: dcodes - 1);
}

//------------------------------------------------------------------------------
// Address: 0x101FD940
// Name: void compress_block(class TState __near &,struct ct_data __near *,struct ct_data __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl compress_block(TState *state, ct_data *ltree, ct_data *dtree)
{
  unsigned int v3; // ebx
  int v5; // edi
  int v6; // ebx
  unsigned int v7; // ebx
  unsigned __int8 v8; // al
  int v9; // edi
  unsigned int lx; // [esp+8h] [ebp-Ch]
  unsigned int fx; // [esp+Ch] [ebp-8h]
  unsigned __int8 flag; // [esp+13h] [ebp-1h]
  unsigned __int16 *statea; // [esp+1Ch] [ebp+8h]

  v3 = 0;
  fx = 0;
  flag = 0;
  if ( state->ts.last_lit != 0 )
  {
    statea = state->ts.d_buf;
    do
    {
      if ( (v3 & 7) == 0 )
        flag = state->ts.flag_buf[fx++];
      v5 = state->ts.l_buf[v3++];
      lx = v3;
      if ( (flag & 1) != 0 )
      {
        v6 = state->ts.length_code[v5];
        send_bits(state, value: ltree[v6 + 257].fc.freq, length: ltree[v6 + 257].dl.dad);
        if ( extra_lbits[v6] != 0 )
          send_bits(state, value: v5 - state->ts.base_length[v6], length: extra_lbits[v6]);
        v7 = *statea++;
        if ( v7 >= 0x100 )
          v8 = state->ts.dist_code[(v7 >> 7) + 256];
        else
          v8 = state->ts.dist_code[v7];
        v9 = v8;
        if ( v8 >= 0x1Eu )
          state->err = "bad d_code";
        send_bits(state, value: dtree[v8].fc.freq, length: dtree[v8].dl.dad);
        if ( extra_dbits[v9] != 0 )
          send_bits(state, value: v7 - state->ts.base_dist[v9], length: extra_dbits[v9]);
        v3 = lx;
      }
      else
      {
        send_bits(state, value: ltree[v5].fc.freq, length: ltree[v5].dl.dad);
      }
      flag >>= 1;
    }
    while ( v3 < state->ts.last_lit );
  }
  send_bits(state, value: ltree[256].fc.freq, length: ltree[256].dl.dad);
}

//------------------------------------------------------------------------------
// Address: 0x101FDAA0
// Name: void lm_init(class TState __near &,int,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lm_init(TState *state, int pack_level, unsigned __int16 *flags)
{
  unsigned int (__cdecl *readfunc)(TState *, char *, unsigned int); // eax
  unsigned int v4; // eax
  unsigned int v5; // eax

  if ( (unsigned int)(pack_level - 1) > 7 )
    state->err = "bad pack level";
  state->ds.sliding = 0;
  if ( state->ds.window_size == 0 )
  {
    state->ds.sliding = 1;
    state->ds.window_size = 0x10000;
  }
  state->ds.head[0x7FFF] = 0;
  memset(dst: (unsigned __int8 *)state->ds.head, value: 0, count: 0x1FFFCu);
  state->ds.max_lazy_match = configuration_table[pack_level].max_lazy;
  state->ds.good_match = configuration_table[pack_level].good_length;
  state->ds.nice_match = configuration_table[pack_level].nice_length;
  state->ds.max_chain_length = configuration_table[pack_level].max_chain;
  if ( pack_level > 2 )
  {
    if ( pack_level >= 8 )
      *flags |= 2u;
  }
  else
  {
    *flags |= 4u;
  }
  readfunc = state->readfunc;
  state->ds.strstart = 0;
  state->ds.block_start = 0;
  v4 = readfunc(a1: state, a2: (char *)&state->ds, a3: 0x10000u);
  state->ds.lookahead = v4;
  if ( v4 == 0 || v4 == -1 )
  {
    state->ds.lookahead = 0;
    state->ds.eofile = 1;
  }
  else
  {
    state->ds.eofile = 0;
    if ( v4 < 0x106 )
      fill_window(state);
    state->ds.ins_h = 0;
    v5 = state->ds.window[0];
    state->ds.ins_h = v5;
    state->ds.ins_h = ((unsigned __int16)(32 * v5) ^ state->ds.window[1]) & 0x7FFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FDBF0
// Name: public: static unsigned int TZip::sflush(void __near *,char const __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TZip::sflush(TZip *param, char *buf, unsigned int *size)
{
  unsigned int result; // eax

  result = *size;
  if ( *size != 0 )
  {
    result = TZip::write(this: param, buf, size: *size);
    if ( result != 0 )
      *size = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FDC20
// Name: public: static unsigned int TZip::swrite(void __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TZip::swrite(TZip *param, char *buf, unsigned int size)
{
  unsigned int result; // eax

  result = size;
  if ( size != 0 )
    return TZip::write(this: param, buf, size);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FDC40
// Name: public: unsigned long TZip::open_file(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::open_file(TZip *this, const char *fn)
{
  HANDLE FileA; // eax
  void *v5; // edi
  unsigned int res; // [esp+10h] [ebp+8h]

  this->hfin = nullptr;
  this->bufin = nullptr;
  this->selfclosehf = false;
  this->crc = 0;
  this->isize = 0;
  this->csize = 0;
  this->ired = 0;
  if ( fn == nullptr )
    return 0x10000;
  FileA = CreateFileA(
            lpFileName: fn,
            dwDesiredAccess: 0x80000000,
            dwShareMode: 1u,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 3u,
            dwFlagsAndAttributes: 0,
            hTemplateFile: nullptr);
  v5 = FileA;
  if ( FileA == (HANDLE)-1 )
    return 512;
  res = TZip::open_handle(this, hf: FileA, len: 0);
  if ( res != 0 )
  {
    CloseHandle(hObject: v5);
    return res;
  }
  else
  {
    this->selfclosehf = true;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FDCD0
// Name: public: static unsigned int TZip::sread(class TState __near &,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TZip::sread(TState *s, char *buf, DWORD size)
{
  return TZip::read(this: (TZip *)s->param, buf, size);
}

//------------------------------------------------------------------------------
// Address: 0x101FDCF0
// Name: public: unsigned long TZip::AddCentral(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::AddCentral(TZip *this)
{
  zlist *zfis; // esi
  unsigned int writ; // ecx
  zlist *nxt; // ebx
  unsigned int pos_at_start_of_central; // [esp+8h] [ebp-Ch]
  int numentries; // [esp+Ch] [ebp-8h]
  bool okay; // [esp+13h] [ebp-1h]

  zfis = this->zfis;
  writ = this->writ;
  numentries = 0;
  pos_at_start_of_central = writ;
  okay = true;
  if ( zfis != nullptr )
  {
    do
    {
      if ( okay
        && putcentral(
             z: zfis,
             wfunc: (unsigned int (__cdecl *)(void *, const char *, unsigned int))TZip::swrite,
             param: this) != 0 )
      {
        okay = false;
      }
      ++numentries;
      this->writ += zfis->cext + zfis->com + zfis->nam + 46;
      nxt = zfis->nxt;
      if ( zfis->cextra != nullptr )
        free(pMem: zfis->cextra);
      free(pMem: zfis);
      zfis = nxt;
    }
    while ( nxt != nullptr );
    writ = pos_at_start_of_central;
  }
  if ( !okay )
    return 1024;
  if ( putend(
         n: numentries,
         s: this->writ - writ,
         c: writ + this->ooffset,
         m: 0,
         z: nullptr,
         wfunc: (unsigned int (__cdecl *)(void *, const char *, unsigned int))TZip::swrite,
         param: this) != 0 )
    okay = false;
  this->writ += 22;
  if ( okay )
    return 0;
  else
    return 1024;
}

//------------------------------------------------------------------------------
// Address: 0x101FDDC0
// Name: void ct_init(class TState __near &,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ct_init(TState *state, unsigned __int16 *attr)
{
  int v3; // edi
  int v4; // eax
  const int *v5; // edx
  int v6; // eax
  int v7; // edx
  const int *v8; // edi
  int v9; // eax
  const int *v10; // ecx
  int v11; // edi
  ct_data::<unnamed_type_dl> *p_dl; // eax
  int i; // ecx
  ct_data::<unnamed_type_dl> *v14; // eax
  int j; // ecx
  int v16; // ecx
  ct_data::<unnamed_type_dl> *v17; // eax
  ct_data::<unnamed_type_dl> *v18; // eax
  int k; // ecx
  ct_data *static_dtree; // ecx
  int v21; // edi
  int v22; // edx
  unsigned int v23; // ecx
  unsigned int v24; // eax
  int v25; // ebx
  unsigned __int8 n; // [esp+10h] [ebp+8h]
  int na; // [esp+10h] [ebp+8h]
  int *nb; // [esp+10h] [ebp+8h]
  ct_data *nc; // [esp+10h] [ebp+8h]
  int *attra; // [esp+14h] [ebp+Ch]
  int *attrb; // [esp+14h] [ebp+Ch]
  unsigned __int16 *attrc; // [esp+14h] [ebp+Ch]

  v3 = 0;
  state->ts.file_type = attr;
  state->ts.cmpr_len_bits = 0;
  state->ts.cmpr_bytelen = 0;
  state->ts.input_len = 0;
  if ( state->ts.static_dtree[0].dl.dad == 0 )
  {
    v4 = 0;
    n = 0;
    v5 = extra_lbits;
    attra = state->ts.base_length;
    while ( 1 )
    {
      *attra = v4;
      if ( 1 << *v5 > 0 )
      {
        do
        {
          state->ts.length_code[v4] = n;
          ++v3;
          ++v4;
        }
        while ( v3 < 1 << *v5 );
      }
      ++attra;
      ++n;
      if ( (int)++v5 >= (int)&extra_lbits[28] )
        break;
      v3 = 0;
    }
    if ( v4 != 256 )
      state->err = "ct_init: length != 256";
    state->ts.depth[v4 + 572] = n;
    v6 = 0;
    v7 = 0;
    v8 = extra_dbits;
    attrb = state->ts.base_dist;
    do
    {
      *attrb = v6;
      for ( na = 0; na < 1 << *v8; ++v6 )
      {
        ++na;
        state->ts.dist_code[v6] = v7;
      }
      ++attrb;
      ++v8;
      ++v7;
    }
    while ( (int)v8 < (int)&extra_dbits[16] );
    if ( v6 != 256 )
      state->err = "ct_init: dist != 256";
    v9 = v6 >> 7;
    if ( v7 < 30 )
    {
      v10 = &extra_dbits[v7];
      attrc = (unsigned __int16 *)v10;
      nb = &state->ts.base_dist[v7];
      do
      {
        *nb = v9 << 7;
        v11 = 0;
        if ( 1 << (*(_BYTE *)v10 - 7) > 0 )
        {
          do
          {
            state->ts.dist_code[v9 + 256] = v7;
            ++v11;
            ++v9;
          }
          while ( v11 < 1 << (*(_BYTE *)attrc - 7) );
        }
        ++nb;
        v10 = (const int *)(attrc + 2);
        LOBYTE(v7) = v7 + 1;
        attrc = (unsigned __int16 *)v10;
      }
      while ( (int)v10 < (int)extra_blbits );
    }
    if ( v9 != 256 )
      state->err = "ct_init: 256+dist != 512";
    *(_DWORD *)state->ts.bl_count = 0;
    *(_DWORD *)&state->ts.bl_count[2] = 0;
    *(_DWORD *)&state->ts.bl_count[4] = 0;
    *(_DWORD *)&state->ts.bl_count[6] = 0;
    *(_DWORD *)&state->ts.bl_count[8] = 0;
    *(_DWORD *)&state->ts.bl_count[10] = 0;
    *(_DWORD *)&state->ts.bl_count[12] = 0;
    *(_DWORD *)&state->ts.bl_count[14] = 0;
    p_dl = &state->ts.static_ltree[1].dl;
    for ( i = 24; i != 0; --i )
    {
      p_dl[-2].dad = 8;
      ++state->ts.bl_count[8];
      p_dl->dad = 8;
      ++state->ts.bl_count[8];
      p_dl[2].dad = 8;
      ++state->ts.bl_count[8];
      p_dl[4].dad = 8;
      ++state->ts.bl_count[8];
      p_dl[6].dad = 8;
      ++state->ts.bl_count[8];
      p_dl[8].dad = 8;
      ++state->ts.bl_count[8];
      p_dl += 12;
    }
    v14 = &state->ts.static_ltree[144].dl;
    for ( j = 112; j != 0; --j )
    {
      v14->dad = 9;
      ++state->ts.bl_count[9];
      v14 += 2;
    }
    v16 = 24;
    v17 = &state->ts.static_ltree[256].dl;
    do
    {
      v17->dad = 7;
      ++state->ts.bl_count[7];
      v17 += 2;
      --v16;
    }
    while ( v16 != 0 );
    v18 = &state->ts.static_ltree[280].dl;
    for ( k = 8; k != 0; --k )
    {
      v18->dad = 8;
      ++state->ts.bl_count[8];
      v18 += 2;
    }
    gen_codes(state, tree: state->ts.static_ltree, max_code: 287);
    static_dtree = state->ts.static_dtree;
    v21 = 0;
    nc = state->ts.static_dtree;
    do
    {
      v22 = 5;
      static_dtree->dl.dad = 5;
      v23 = v21;
      v24 = 0;
      do
      {
        v25 = v23 & 1;
        --v22;
        v23 >>= 1;
        v24 = 2 * (v25 | v24);
      }
      while ( v22 > 0 );
      nc->fc.freq = v24 >> 1;
      ++v21;
      static_dtree = ++nc;
    }
    while ( v21 < 30 );
    init_block(state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE100
// Name: unsigned long flush_block(class TState __near &,char __near *,unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl flush_block(TState *state, char *buf, unsigned int stored_len, unsigned int eof)
{
  int v5; // eax
  unsigned int static_len; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  unsigned int opt_len; // ecx
  unsigned int v11; // eax
  int max_blindex; // [esp+Ch] [ebp+8h]

  state->ts.flag_buf[state->ts.last_flags] = state->ts.flags;
  if ( *state->ts.file_type == 0xFFFF )
    set_file_type(state);
  build_tree(state, desc: &state->ts.l_desc);
  build_tree(state, desc: &state->ts.d_desc);
  v5 = build_bl_tree(state);
  static_len = state->ts.static_len;
  state->ts.input_len += stored_len;
  max_blindex = v5;
  v7 = (state->ts.opt_len + 10) >> 3;
  v8 = (static_len + 10) >> 3;
  if ( v8 <= v7 )
    v7 = v8;
  if ( stored_len + 4 <= v7 && buf != nullptr )
  {
    v9 = eof;
    send_bits(state, value: eof, length: 3);
    state->ts.cmpr_bytelen += ((state->ts.cmpr_len_bits + 10) >> 3) + stored_len + 4;
    state->ts.cmpr_len_bits = 0;
    copy_block(state, block: buf, len: stored_len, header: 1);
  }
  else
  {
    v9 = eof;
    if ( v8 == v7 )
    {
      send_bits(state, value: eof + 2, length: 3);
      compress_block(state, ltree: state->ts.static_ltree, dtree: state->ts.static_dtree);
      opt_len = state->ts.static_len;
    }
    else
    {
      send_bits(state, value: eof + 4, length: 3);
      send_all_trees(
        state,
        lcodes: state->ts.l_desc.max_code + 1,
        dcodes: state->ts.d_desc.max_code + 1,
        blcodes: max_blindex + 1);
      compress_block(state, ltree: state->ts.dyn_ltree, dtree: state->ts.dyn_dtree);
      opt_len = state->ts.opt_len;
    }
    v11 = state->ts.cmpr_len_bits + opt_len + 3;
    state->ts.cmpr_bytelen += v11 >> 3;
    state->ts.cmpr_len_bits = v11 & 7;
  }
  if ( state->ts.cmpr_len_bits + 8 * state->ts.cmpr_bytelen != state->bs.bits_sent )
    state->err = "bad compressed size";
  init_block(state);
  if ( v9 != 0 )
  {
    bi_windup(state);
    state->ts.cmpr_len_bits += 7;
  }
  return state->ts.cmpr_bytelen + (state->ts.cmpr_len_bits >> 3);
}

//------------------------------------------------------------------------------
// Address: 0x101FE2B0
// Name: unsigned long deflate_fast(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl deflate_fast(TState *state)
{
  unsigned int v2; // ebx
  unsigned int v3; // edi
  unsigned int strstart; // ecx
  unsigned int v5; // eax
  unsigned int lookahead; // eax
  unsigned int v7; // ecx
  BOOL v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // ecx
  BOOL v13; // eax
  int block_start; // eax
  char *v15; // ecx
  int v16; // eax
  char *v17; // ecx
  int flush; // [esp+14h] [ebp+8h]

  v2 = 0;
  v3 = 0;
  state->ds.prev_length = 2;
  while ( state->ds.lookahead != 0 )
  {
    if ( state->ds.lookahead >= 3 )
    {
      strstart = state->ds.strstart;
      v5 = ((unsigned __int16)(32 * LOWORD(state->ds.ins_h)) ^ state->ds.window[strstart + 2]) & 0x7FFF;
      state->ds.ins_h = v5;
      v2 = state->ds.head[v5];
      state->ds.prev[strstart & 0x7FFF] = v2;
      state->ds.head[state->ds.ins_h] = state->ds.strstart;
    }
    if ( v2 != 0 && state->ds.strstart - v2 <= 0x7EFA )
    {
      lookahead = state->ds.lookahead;
      if ( state->ds.nice_match > lookahead )
        state->ds.nice_match = lookahead;
      v3 = longest_match(state, cur_match: v2);
      if ( v3 > state->ds.lookahead )
        v3 = state->ds.lookahead;
    }
    v7 = state->ds.strstart;
    if ( v3 < 3 )
    {
      v13 = ct_tally(state, dist: 0, lc: state->ds.window[v7]);
      --state->ds.lookahead;
      ++state->ds.strstart;
      flush = v13;
    }
    else
    {
      v8 = ct_tally(state, dist: v7 - state->ds.match_start, lc: v3 - 3);
      state->ds.lookahead -= v3;
      flush = v8;
      if ( v3 > state->ds.max_lazy_match || state->ds.lookahead < 3 )
      {
        state->ds.strstart += v3;
        v11 = state->ds.strstart;
        v12 = state->ds.window[v11];
        state->ds.ins_h = v12;
        v3 = 0;
        state->ds.ins_h = (32 * v12) ^ state->ds.window[v11 + 1];
      }
      else
      {
        --v3;
        do
        {
          v9 = ++state->ds.strstart;
          v10 = ((unsigned __int16)(32 * state->ds.ins_h) ^ state->ds.window[v9 + 2]) & 0x7FFF;
          state->ds.ins_h = v10;
          v2 = state->ds.head[v10];
          --v3;
          state->ds.prev[v9 & 0x7FFF] = v2;
          state->ds.head[state->ds.ins_h] = state->ds.strstart;
        }
        while ( v3 != 0 );
        ++state->ds.strstart;
      }
    }
    if ( flush != 0 )
    {
      block_start = state->ds.block_start;
      if ( block_start < 0 )
        v15 = nullptr;
      else
        v15 = (char *)&state->ds.window[block_start];
      flush_block(state, buf: v15, stored_len: state->ds.strstart - block_start, eof: 0);
      state->ds.block_start = state->ds.strstart;
    }
    if ( state->ds.lookahead < 0x106 )
      fill_window(state);
  }
  v16 = state->ds.block_start;
  if ( v16 < 0 )
    v17 = nullptr;
  else
    v17 = (char *)&state->ds.window[v16];
  return flush_block(state, buf: v17, stored_len: state->ds.strstart - v16, eof: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x101FE500
// Name: unsigned long deflate(class TState __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl deflate(TState *state)
{
  unsigned int v1; // edi
  unsigned int strstart; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int match_start; // ebx
  unsigned int lookahead; // eax
  unsigned int prev_length; // ecx
  unsigned int v9; // eax
  unsigned int v10; // edi
  BOOL v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  int v17; // eax
  char *v18; // edx
  int block_start; // eax
  char *v20; // ecx
  int v21; // eax
  char *v22; // ecx
  unsigned int hash_head; // [esp+8h] [ebp-8h]
  int match_available; // [esp+Ch] [ebp-4h]

  hash_head = 0;
  match_available = 0;
  v1 = 2;
  if ( state->level <= 3 )
    return deflate_fast(state);
  if ( state->ds.lookahead != 0 )
  {
    do
    {
      if ( state->ds.lookahead >= 3 )
      {
        strstart = state->ds.strstart;
        v4 = ((unsigned __int16)(32 * LOWORD(state->ds.ins_h)) ^ state->ds.window[strstart + 2]) & 0x7FFF;
        state->ds.ins_h = v4;
        v5 = state->ds.head[v4];
        state->ds.prev[strstart & 0x7FFF] = v5;
        hash_head = v5;
        state->ds.head[state->ds.ins_h] = state->ds.strstart;
      }
      match_start = state->ds.match_start;
      state->ds.prev_length = v1;
      v1 = 2;
      if ( hash_head != 0
        && state->ds.prev_length < state->ds.max_lazy_match
        && state->ds.strstart - hash_head <= 0x7EFA )
      {
        lookahead = state->ds.lookahead;
        if ( state->ds.nice_match > lookahead )
          state->ds.nice_match = lookahead;
        v1 = longest_match(state, cur_match: hash_head);
        if ( v1 > state->ds.lookahead )
          v1 = state->ds.lookahead;
        if ( v1 == 3 && state->ds.strstart - state->ds.match_start > 0x1000 )
          v1 = 2;
      }
      prev_length = state->ds.prev_length;
      if ( prev_length < 3 || v1 > prev_length )
      {
        if ( match_available != 0 )
        {
          if ( ct_tally(state, dist: 0, lc: *((unsigned __int8 *)&state->bs.bits_sent + state->ds.strstart + 3)) )
          {
            block_start = state->ds.block_start;
            if ( block_start < 0 )
              v20 = nullptr;
            else
              v20 = (char *)&state->ds.window[block_start];
            flush_block(state, buf: v20, stored_len: state->ds.strstart - block_start, eof: 0);
            state->ds.block_start = state->ds.strstart;
          }
          ++state->ds.strstart;
        }
        else
        {
          ++state->ds.strstart;
          match_available = 1;
        }
        --state->ds.lookahead;
      }
      else
      {
        v9 = state->ds.strstart;
        v10 = v9 + state->ds.lookahead - 3;
        v11 = ct_tally(state, dist: v9 - match_start - 1, lc: prev_length - 3);
        v12 = state->ds.prev_length;
        state->ds.lookahead += 1 - v12;
        state->ds.prev_length = v12 - 2;
        do
        {
          v13 = ++state->ds.strstart;
          if ( v13 <= v10 )
          {
            v14 = ((unsigned __int16)(32 * LOWORD(state->ds.ins_h)) ^ state->ds.window[v13 + 2]) & 0x7FFF;
            state->ds.ins_h = v14;
            v15 = state->ds.head[v14];
            state->ds.prev[v13 & 0x7FFF] = v15;
            hash_head = v15;
            state->ds.head[state->ds.ins_h] = state->ds.strstart;
          }
        }
        while ( state->ds.prev_length-- != 1 );
        ++state->ds.strstart;
        match_available = 0;
        v1 = 2;
        if ( v11 )
        {
          v17 = state->ds.block_start;
          if ( v17 < 0 )
            v18 = nullptr;
          else
            v18 = (char *)&state->ds.window[v17];
          flush_block(state, buf: v18, stored_len: state->ds.strstart - v17, eof: 0);
          state->ds.block_start = state->ds.strstart;
        }
      }
      if ( state->ds.lookahead < 0x106 )
        fill_window(state);
    }
    while ( state->ds.lookahead != 0 );
    if ( match_available != 0 )
      ct_tally(state, dist: 0, lc: *((unsigned __int8 *)&state->bs.bits_sent + state->ds.strstart + 3));
  }
  v21 = state->ds.block_start;
  if ( v21 < 0 )
    v22 = nullptr;
  else
    v22 = (char *)&state->ds.window[v21];
  return flush_block(state, buf: v22, stored_len: state->ds.strstart - v21, eof: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x101FE810
// Name: public: unsigned long TZip::Close(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::Close(TZip *this)
{
  unsigned int v2; // ebx
  char *obuf; // eax
  void *hmapout; // eax
  void *hfout; // eax

  v2 = 0;
  if ( !this->hasputcen )
    v2 = TZip::AddCentral(this);
  obuf = this->obuf;
  this->hasputcen = true;
  if ( obuf != nullptr && this->hmapout != nullptr )
    UnmapViewOfFile(lpBaseAddress: obuf);
  hmapout = this->hmapout;
  this->obuf = nullptr;
  if ( hmapout != nullptr )
    CloseHandle(hObject: hmapout);
  hfout = this->hfout;
  this->hmapout = nullptr;
  if ( hfout != nullptr )
    CloseHandle(hObject: hfout);
  this->hfout = nullptr;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101FE870
// Name: public: unsigned long TZip::ideflate(struct zlist __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TZip::ideflate(TZip *this, zlist *zfi)
{
  bool iseekable; // cl
  TState state; // [esp+8h] [ebp-6AFA8h] BYREF

  TTreeState::TTreeState(this: &state.ts);
  iseekable = this->iseekable;
  state.ts.static_dtree[0].dl.dad = 0;
  state.ds.window_size = 0;
  state.err = nullptr;
  state.bs.out_offset = 0;
  state.bs.bi_buf = 0;
  state.bs.bi_valid = 0;
  state.bs.bits_sent = 0;
  state.seekable = iseekable;
  state.readfunc = TZip::sread;
  state.flush_outbuf = (unsigned int (__cdecl *)(void *, const char *, unsigned int *))TZip::sflush;
  state.param = this;
  state.level = 8;
  state.bs.out_buf = this->buf;
  state.bs.out_size = 0x4000;
  state.bs.flush_flg = 1;
  ct_init(&state, attr: &zfi->att);
  lm_init(&state, pack_level: state.level, flags: &zfi->flg);
  this->csize = deflate(&state);
  return state.err != nullptr ? 0x5000000 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FE950
// Name: public: unsigned long TZip::Add(char const __near *,void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TZip::Add(TZip *this, const char *odstzn, char *src, unsigned int len, unsigned int flags)
{
  unsigned int result; // eax
  char *v7; // eax
  bool v9; // dl
  int v10; // eax
  char v11; // cl
  char *v12; // edi
  char v13; // al
  unsigned int timestamp; // ecx
  unsigned int isize; // ecx
  unsigned int attr; // eax
  unsigned int mtime; // edi
  unsigned int v18; // ecx
  unsigned int mtime_high; // eax
  unsigned int v20; // ecx
  int atime; // edi
  int v22; // ecx
  char v23; // edx^3
  int ctime; // edi
  int v25; // esi
  int v26; // edi
  unsigned int csize; // ecx
  bool v28; // zf
  unsigned int crc; // edx
  unsigned int v30; // ecx
  bool v31; // al
  unsigned __int16 lflg; // dx
  unsigned __int8 *v33; // esi
  zlist *v34; // eax
  zlist *zfis; // ecx
  unsigned int v36; // [esp-Ch] [ebp-498h]
  char dstzn[260]; // [esp+4h] [ebp-488h] BYREF
  zlist zfi; // [esp+108h] [ebp-384h] BYREF
  char xcen[9]; // [esp+468h] [ebp-24h] BYREF
  char xloc[20]; // [esp+474h] [ebp-18h] BYREF
  int method; // [esp+488h] [ebp-4h]
  char needs_trailing_slash_3; // [esp+497h] [ebp+Bh]
  bool isdir_3; // [esp+4A3h] [ebp+17h]

  if ( this->oerr != 0 )
    return 0x40000;
  if ( this->hasputcen )
    return 327680;
  strcpy(dstzn, odstzn);
  if ( dstzn[0] == 0 )
    return 0x10000;
  v7 = dstzn;
  do
  {
    if ( *v7 == 92 )
      *v7 = 47;
    ++v7;
  }
  while ( *v7 != 0 );
  v9 = flags == 4;
  isdir_3 = v9;
  if ( !v9 || (needs_trailing_slash_3 = 1, dstzn[strlen(dstzn) - 1] == 47) )
    needs_trailing_slash_3 = 0;
  method = 8;
  if ( v9 || HasZipSuffix(fn: dstzn) )
    method = 0;
  switch ( flags )
  {
    case 2u:
      result = TZip::open_file(this, fn: src);
      break;
    case 1u:
      result = TZip::open_handle(this, hf: src, len);
      break;
    case 3u:
      result = TZip::open_mem(this, src, len);
      break;
    case 4u:
      result = TZip::open_dir(this);
      break;
    default:
      return 0x10000;
  }
  if ( result != 0 )
    return result;
  zfi.nxt = nullptr;
  zfi.name[0] = 0;
  v10 = 0;
  do
  {
    v11 = dstzn[v10];
    zfi.iname[v10++] = v11;
  }
  while ( v11 != 0 );
  zfi.nam = strlen(zfi.iname);
  if ( needs_trailing_slash_3 != 0 )
  {
    v12 = (char *)&zfi.comment + 3;
    do
      v13 = *++v12;
    while ( v13 != 0 );
    strcpy(v12, "/");
    ++zfi.nam;
  }
  zfi.lflg = 8;
  zfi.att = 0;
  timestamp = this->timestamp;
  zfi.zname[0] = 0;
  zfi.comment = nullptr;
  zfi.com = 0;
  zfi.mark = 1;
  zfi.dosflag = 0;
  *(_DWORD *)&zfi.vem = 1313559;
  zfi.tim = timestamp;
  zfi.crc = 0;
  zfi.flg = 8;
  zfi.how = method;
  if ( method != 0 || (zfi.siz = this->isize, (zfi.siz & 0x80000000) != 0) )
    zfi.siz = 0;
  isize = this->isize;
  attr = this->attr;
  mtime = this->times.mtime;
  zfi.dsk = 0;
  zfi.len = isize;
  v18 = this->writ + this->ooffset;
  zfi.atx = attr;
  zfi.off = v18;
  xloc[5] = this->times.mtime;
  zfi.cextra = xcen;
  mtime_high = HIDWORD(this->times.mtime);
  zfi.extra = xloc;
  xloc[6] = BYTE1(mtime);
  xloc[7] = BYTE2(mtime);
  v20 = mtime;
  atime = this->times.atime;
  v22 = __PAIR64__(mtime_high, v20) >> 24;
  xloc[9] = this->times.atime;
  xloc[10] = BYTE1(atime);
  xloc[11] = BYTE2(atime);
  v23 = HIBYTE(atime);
  ctime = this->times.ctime;
  LOBYTE(mtime_high) = this->times.ctime;
  xloc[12] = v23;
  *(_WORD *)&xloc[13] = __PAIR16__(BYTE1(ctime), mtime_high);
  xloc[15] = BYTE2(ctime);
  strcpy(xloc, "UT\r");
  *(_DWORD *)xcen = 349269;
  xloc[4] = 7;
  xloc[16] = HIBYTE(ctime);
  zfi.ext = 17;
  zfi.cext = 9;
  xloc[8] = v22;
  *(_DWORD *)&xcen[4] = *(_DWORD *)&xloc[4];
  xcen[8] = v22;
  if ( putlocal(z: &zfi, wfunc: (unsigned int (__cdecl *)(void *, const char *, unsigned int))TZip::swrite, param: this) != 0 )
  {
    TZip::iclose(this);
    return 1024;
  }
  this->writ += zfi.ext + zfi.nam + 30;
  v25 = 0;
  if ( this->oerr != 0 )
  {
    TZip::iclose(this);
    return this->oerr;
  }
  v26 = method;
  if ( isdir_3 )
  {
    this->csize = 0;
  }
  else if ( method == 8 )
  {
    v25 = TZip::ideflate(this, &zfi);
  }
  else if ( method == 0 )
  {
    v25 = TZip::istore(this);
  }
  TZip::iclose(this);
  csize = this->csize;
  result = this->oerr;
  this->writ += csize;
  if ( result == 0 )
  {
    if ( v25 != 0 )
      return 1024;
    v28 = zfi.siz == csize;
    crc = this->crc;
    zfi.siz = csize;
    v30 = this->isize;
    v31 = v28;
    v28 = !this->ocanseek;
    zfi.crc = crc;
    zfi.len = v30;
    if ( v28 )
    {
      if ( zfi.how != (_WORD)v26 || v26 == 0 && !v31 )
        return 0x4000000;
      if ( putextended(
             z: &zfi,
             wfunc: (unsigned int (__cdecl *)(void *, const char *, unsigned int))TZip::swrite,
             param: this) != 0 )
        return 1024;
      lflg = zfi.lflg;
      this->writ += 16;
      zfi.flg = lflg;
    }
    else
    {
      zfi.how = v26;
      if ( (zfi.flg & 1) == 0 )
        zfi.flg &= ~8u;
      v36 = zfi.off - this->ooffset;
      zfi.lflg = zfi.flg;
      if ( TZip::oseek(this, pos: v36) == 0 )
        return 0x2000000;
      if ( putlocal(
             z: &zfi,
             wfunc: (unsigned int (__cdecl *)(void *, const char *, unsigned int))TZip::swrite,
             param: this) != 0 )
        return 1024;
      if ( TZip::oseek(this, pos: this->writ) == 0 )
        return 0x2000000;
    }
    result = this->oerr;
    if ( result == 0 )
    {
      v33 = (unsigned __int8 *)MemAlloc_Alloc(nSize: zfi.cext);
      memcpy(dst: v33, src: (unsigned __int8 *)zfi.cextra, count: zfi.cext);
      zfi.cextra = (char *)v33;
      v34 = (zlist *)MemAlloc_Alloc(nSize: 0x360u);
      *v34 = zfi;
      zfis = this->zfis;
      if ( zfis != nullptr )
      {
        for ( ; zfis->nxt != nullptr; zfis = zfis->nxt )
          ;
        zfis->nxt = v34;
        return 0;
      }
      else
      {
        this->zfis = v34;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FEEA0
// Name: struct HZIP__ __near * CreateZipZ(void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HZIP__ *__cdecl CreateZipZ(void *z, unsigned int len, unsigned int flags)
{
  TZip *v3; // eax
  TZip *v4; // esi
  void *v5; // eax
  HZIP__ *result; // eax

  _tzset();
  v3 = (TZip *)MemAlloc_Alloc(nSize: 0x4078u);
  if ( v3 != nullptr )
  {
    v3->hfout = nullptr;
    v3->hmapout = nullptr;
    v3->ooffset = 0;
    v3->oerr = 0;
    v3->writ = 0;
    v3->obuf = nullptr;
    v3->hasputcen = false;
    v3->zfis = nullptr;
    v3->hfin = nullptr;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (void *)TZip::Create(this: v4, z, len, flags);
  GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: v5);
  if ( GenericThreadLocals::CThreadLocalBase::Get(this: &lasterrorZ) != nullptr )
  {
    if ( v4 != nullptr )
      free(pMem: v4);
    return nullptr;
  }
  else
  {
    result = (HZIP__ *)MemAlloc_Alloc(nSize: 8u);
    *((_DWORD *)result + 1) = v4;
    *(_DWORD *)result = 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FEF40
// Name: unsigned long ZipAdd(struct HZIP__ __near *,char const __near *,void __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ZipAdd(HZIP__ *hz, const char *dstzn, char *src, unsigned int len, unsigned int flags)
{
  TZip *v6; // esi
  void *v7; // eax
  char szDest[520]; // [esp+0h] [ebp-208h] BYREF

  if ( hz != nullptr )
  {
    if ( *(_DWORD *)hz == 2 )
    {
      v6 = *((TZip **)hz + 1);
      if ( flags == 2 )
      {
        memset(dst: (unsigned __int8 *)szDest, value: 0, count: sizeof(szDest));
        strcpy(szDest, dstzn);
        v7 = (void *)TZip::Add(this: v6, odstzn: szDest, src, len, flags: 2u);
      }
      else
      {
        v7 = (void *)TZip::Add(this: v6, odstzn: dstzn, src, len, flags);
      }
      GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: v7);
      return (unsigned int)GenericThreadLocals::CThreadLocalBase::Get(this: &lasterrorZ);
    }
    else
    {
      GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x80000);
      return 0x80000;
    }
  }
  else
  {
    GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x10000);
    return 0x10000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF000
// Name: unsigned long ZipGetMemory(struct HZIP__ __near *,void __near * __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ZipGetMemory(HZIP__ *hz, void **buf, unsigned int *len)
{
  int v4; // esi

  if ( hz != nullptr )
  {
    if ( *(_DWORD *)hz == 2 )
    {
      v4 = *((_DWORD *)hz + 1);
      if ( *(_BYTE *)(v4 + 36) == 0 )
        TZip::AddCentral(this: *((TZip **)hz + 1));
      *(_BYTE *)(v4 + 36) = 1;
      if ( buf != nullptr )
        *buf = *(void **)(v4 + 24);
      if ( len != nullptr )
        *len = *(_DWORD *)(v4 + 16);
      GenericThreadLocals::CThreadLocalBase::Set(
        this: &lasterrorZ,
        a2: *(_DWORD *)(v4 + 24) != 0 ? nullptr : (void *)0x20000);
      return (unsigned int)GenericThreadLocals::CThreadLocalBase::Get(this: &lasterrorZ);
    }
    else
    {
      GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x80000);
      return 0x80000;
    }
  }
  else
  {
    if ( buf != nullptr )
      *buf = nullptr;
    if ( len != nullptr )
      *len = 0;
    GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x10000);
    return 0x10000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF0B0
// Name: unsigned long CloseZipZ(struct HZIP__ __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CloseZipZ(HZIP__ *hz)
{
  TZip *v2; // esi
  void *v3; // eax

  if ( hz != nullptr )
  {
    if ( *(_DWORD *)hz == 2 )
    {
      v2 = *((TZip **)hz + 1);
      v3 = (void *)TZip::Close(this: v2);
      GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: v3);
      if ( v2 != nullptr )
        free(pMem: v2);
      free(pMem: hz);
      return (unsigned int)GenericThreadLocals::CThreadLocalBase::Get(this: &lasterrorZ);
    }
    else
    {
      GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x80000);
      return 0x80000;
    }
  }
  else
  {
    GenericThreadLocals::CThreadLocalBase::Set(this: &lasterrorZ, a2: (void *)0x10000);
    return 0x10000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCE43
// Name: __write
// Source: json
//------------------------------------------------------------------------------
int __cdecl _write(int fh, char *buf, unsigned int cnt)
{
  ioinfo **v4; // edi
  int v5; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _write_nolock(fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x102FCF17
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_nolock(int fh)
{
  int osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(fh) == -1
    || (fh == 1 && (__pioinfo[0][2].osfile & 1) != 0 || fh == 2 && (__pioinfo[0][1].osfile & 1) != 0)
    && (osfhandle = _get_osfhandle(fh: 2), _get_osfhandle(fh: 1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(fh), CloseHandle(hObject: v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  __pioinfo[fh >> 5][fh & 0x1F].osfile = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

} // namespace engine_xlsp
