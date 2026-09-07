// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/bitmap/stb_image.c
// Functions: 126
// ============================================================

#include "public\bitmap\stb_image.h"

//------------------------------------------------------------------------------
// Address: 0x00401E80
// Name: refill_buffer
// Source: json
//------------------------------------------------------------------------------
void __usercall refill_buffer(stbi *s@<esi>)
{
  unsigned int v1; // eax
  unsigned __int8 *v2; // eax

  v1 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
  if ( v1 != 0 )
  {
    s->img_buffer = s->buffer_start;
    s->img_buffer_end = &s->buffer_start[v1];
  }
  else
  {
    s->from_file = 0;
    v2 = s->img_buffer_end - 1;
    s->img_buffer = v2;
    *v2 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401ED0
// Name: skip
// Source: json
//------------------------------------------------------------------------------
void __fastcall skip(int n, stbi *s)
{
  _iobuf *img_file; // edi
  int v3; // eax

  img_file = s->img_file;
  if ( img_file != nullptr && (v3 = s->img_buffer_end - s->img_buffer) < n )
  {
    s->img_buffer = s->img_buffer_end;
    fseek(stream: img_file, offset: n - v3, whence: 1);
  }
  else
  {
    s->img_buffer += n;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401F10
// Name: getn
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall getn@<eax>(stbi *s@<esi>, unsigned __int8 *buffer, int n)
{
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // edi
  unsigned int v5; // eax
  unsigned __int8 *img_buffer; // eax

  if ( s->img_file != nullptr && (v3 = s->img_buffer, (int)(v4 = (unsigned __int8 *)(s->img_buffer_end - v3)) < n) )
  {
    memcpy(dst: buffer, src: v3, count: s->img_buffer_end - v3);
    v5 = fread(buffer: &v4[(_DWORD)buffer], elementSize: 1u, count: n - (_DWORD)v4, stream: s->img_file);
    s->img_buffer = s->img_buffer_end;
    return v5 == n - (_DWORD)v4;
  }
  else
  {
    img_buffer = s->img_buffer;
    if ( &img_buffer[n] > s->img_buffer_end )
    {
      return false;
    }
    else
    {
      memcpy(dst: buffer, src: img_buffer, count: n);
      s->img_buffer += n;
      return true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401FA0
// Name: get16
// Source: json
//------------------------------------------------------------------------------
int __usercall get16@<eax>(stbi *s@<eax>)
{
  unsigned __int8 *img_buffer; // eax
  int v3; // edi
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // ecx

  img_buffer = s->img_buffer;
  if ( img_buffer >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v4 = s->img_buffer;
      v3 = *v4;
      s->img_buffer = v4 + 1;
    }
    else
    {
      v3 = 0;
    }
  }
  else
  {
    v3 = *img_buffer;
    s->img_buffer = img_buffer + 1;
  }
  v5 = s->img_buffer;
  if ( v5 < s->img_buffer_end )
    goto LABEL_9;
  if ( s->from_file != 0 )
  {
    refill_buffer(s);
    v5 = s->img_buffer;
LABEL_9:
    v6 = *v5;
    s->img_buffer = v5 + 1;
    return v6 + (v3 << 8);
  }
  return v3 << 8;
}

//------------------------------------------------------------------------------
// Address: 0x00402030
// Name: get32
// Source: json
//------------------------------------------------------------------------------
int __usercall get32@<eax>(stbi *s@<edi>)
{
  int v1; // esi

  v1 = get16(s);
  return (v1 << 16) + get16(s);
}

//------------------------------------------------------------------------------
// Address: 0x00402050
// Name: get16le
// Source: json
//------------------------------------------------------------------------------
int __usercall get16le@<eax>(stbi *s@<eax>)
{
  unsigned __int8 *img_buffer; // eax
  int v3; // edi
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // ecx
  int result; // eax

  img_buffer = s->img_buffer;
  if ( img_buffer >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v4 = s->img_buffer;
      v3 = *v4;
      s->img_buffer = v4 + 1;
    }
    else
    {
      v3 = 0;
    }
  }
  else
  {
    v3 = *img_buffer;
    s->img_buffer = img_buffer + 1;
  }
  v5 = s->img_buffer;
  if ( v5 < s->img_buffer_end )
    goto LABEL_9;
  if ( s->from_file != 0 )
  {
    refill_buffer(s);
    v5 = s->img_buffer;
LABEL_9:
    result = v3 + (*v5 << 8);
    s->img_buffer = v5 + 1;
    return result;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004020D0
// Name: get32le
// Source: json
//------------------------------------------------------------------------------
int __usercall get32le@<eax>(stbi *s@<esi>)
{
  int v1; // edi

  v1 = get16le(s);
  return v1 + (get16le(s) << 16);
}

//------------------------------------------------------------------------------
// Address: 0x004020F0
// Name: convert_format
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall convert_format@<eax>(
        int img_n@<ecx>,
        int req_comp@<eax>,
        unsigned __int8 *data,
        unsigned int x,
        signed int y)
{
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // ecx
  int v10; // edx
  unsigned int v11; // edi
  int i; // esi
  int j; // esi
  unsigned __int8 v14; // dl
  int k; // esi
  unsigned __int8 v16; // dl
  int m; // esi
  int n; // esi
  unsigned __int8 v19; // dl
  int ii; // esi
  unsigned __int8 v21; // dl
  int jj; // esi
  int v23; // esi
  int v24; // esi
  int v25; // esi
  int v26; // esi
  int kk; // esi
  bool v28; // zf
  unsigned __int8 *good; // [esp+Ch] [ebp-1Ch]
  unsigned int v30; // [esp+10h] [ebp-18h]
  unsigned int v31; // [esp+14h] [ebp-14h]
  int v32; // [esp+18h] [ebp-10h]
  signed int v33; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 *v34; // [esp+20h] [ebp-8h]
  unsigned __int8 *v35; // [esp+24h] [ebp-4h]

  if ( req_comp == img_n )
    return data;
  v30 = x * req_comp;
  v8 = (unsigned __int8 *)operator new(nSize: y * x * req_comp);
  good = v8;
  if ( v8 != nullptr )
  {
    if ( y > 0 )
    {
      v9 = data;
      v10 = req_comp + 8 * img_n - 10;
      v11 = x;
      v33 = y;
      v32 = v10;
      v31 = x * img_n;
      v34 = v8;
      v35 = data;
      while ( 1 )
      {
        switch ( v10 )
        {
          case 0:
            for ( i = v11 - 1; i >= 0; --i )
            {
              *v8 = *v9;
              v8[1] = -1;
              ++v9;
              v8 += 2;
            }
            break;
          case 1:
            for ( j = v11 - 1; j >= 0; --j )
            {
              v14 = *v9;
              v8[2] = *v9;
              v8[1] = v14;
              *v8 = v14;
              ++v9;
              v8 += 3;
            }
            break;
          case 2:
            for ( k = v11 - 1; k >= 0; --k )
            {
              v16 = *v9;
              v8[2] = *v9;
              v8[1] = v16;
              *v8 = v16;
              v8[3] = -1;
              ++v9;
              v8 += 4;
            }
            break;
          case 7:
            for ( m = v11 - 1; m >= 0; --m )
            {
              *v8 = *v9;
              v9 += 2;
              ++v8;
            }
            break;
          case 9:
            for ( n = v11 - 1; n >= 0; --n )
            {
              v19 = *v9;
              v8[2] = *v9;
              v8[1] = v19;
              *v8 = v19;
              v9 += 2;
              v8 += 3;
            }
            break;
          case 10:
            for ( ii = v11 - 1; ii >= 0; --ii )
            {
              v21 = *v9;
              v8[2] = *v9;
              v8[1] = v21;
              *v8 = v21;
              v8[3] = v9[1];
              v9 += 2;
              v8 += 4;
            }
            break;
          case 15:
            v23 = v11 - 1;
            if ( (int)(v11 - 1) >= 0 )
            {
              do
              {
                *v8 = (unsigned __int16)(77 * *v9 + 29 * v9[2] + 150 * v9[1]) >> 8;
                v9 += 3;
                ++v8;
                --v23;
              }
              while ( v23 >= 0 );
              v11 = x;
            }
            break;
          case 16:
            v24 = v11 - 1;
            if ( (int)(v11 - 1) >= 0 )
            {
              do
              {
                *v8 = (unsigned __int16)(77 * *v9 + 29 * v9[2] + 150 * v9[1]) >> 8;
                v8[1] = -1;
                v9 += 3;
                v8 += 2;
                --v24;
              }
              while ( v24 >= 0 );
              v11 = x;
            }
            break;
          case 18:
            for ( jj = v11 - 1; jj >= 0; --jj )
            {
              *v8 = *v9;
              v8[1] = v9[1];
              v8[2] = v9[2];
              v8[3] = -1;
              v9 += 3;
              v8 += 4;
            }
            break;
          case 23:
            v25 = v11 - 1;
            if ( (int)(v11 - 1) >= 0 )
            {
              do
              {
                *v8 = (unsigned __int16)(77 * *v9 + 29 * v9[2] + 150 * v9[1]) >> 8;
                v9 += 4;
                ++v8;
                --v25;
              }
              while ( v25 >= 0 );
              v11 = x;
            }
            break;
          case 24:
            v26 = v11 - 1;
            if ( (int)(v11 - 1) >= 0 )
            {
              do
              {
                *v8 = (unsigned __int16)(77 * *v9 + 29 * v9[2] + 150 * v9[1]) >> 8;
                v8[1] = v9[3];
                v9 += 4;
                v8 += 2;
                --v26;
              }
              while ( v26 >= 0 );
              v11 = x;
            }
            break;
          case 25:
            for ( kk = v11 - 1; kk >= 0; --kk )
            {
              *v8 = *v9;
              v8[1] = v9[1];
              v8[2] = v9[2];
              v9 += 4;
              v8 += 3;
            }
            break;
          default:
            break;
        }
        v9 = &v35[v31];
        v8 = &v34[v30];
        v28 = v33-- == 1;
        v35 += v31;
        v34 += v30;
        if ( v28 )
          break;
        v10 = v32;
      }
    }
    free(pMem: data);
    return good;
  }
  else
  {
    free(pMem: data);
    failure_reason = "outofmem";
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402430
// Name: hdr_to_ldr
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall hdr_to_ldr@<eax>(int x@<eax>, float *data, int y, int comp)
{
  int v4; // ebx
  int v5; // esi
  unsigned __int8 *v6; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  float *v11; // edi
  unsigned __int8 *v12; // ebx
  float v13; // xmm0_4
  float v14; // xmm0_4
  int v15; // esi
  float v16; // xmm0_4
  bool v17; // zf
  long double v18; // [esp+0h] [ebp-20h]
  long double v19; // [esp+8h] [ebp-18h]
  int v20; // [esp+10h] [ebp-10h]
  float *v21; // [esp+14h] [ebp-Ch]
  int v22; // [esp+18h] [ebp-8h]
  unsigned __int8 *output; // [esp+1Ch] [ebp-4h]
  int n; // [esp+2Ch] [ebp+Ch]

  v4 = comp;
  v5 = y * x;
  v6 = (unsigned __int8 *)operator new(nSize: comp * y * x);
  output = v6;
  if ( v6 != nullptr )
  {
    if ( (comp & 1) != 0 )
      n = comp;
    else
      n = comp - 1;
    if ( v5 > 0 )
    {
      HIDWORD(v19) = 4 * comp;
      v8 = data;
      v9 = 0;
      v22 = 0;
      v21 = data;
      v20 = v5;
      do
      {
        v10 = 0;
        if ( n > 0 )
        {
          v11 = v8;
          v12 = &output[v9];
          do
          {
            v13 = *v11 * h2l_scale_i;
            __libm_sse2_pow(x: v18, y: v19);
            v14 = (float)(v13 * 255.0) + 0.5;
            if ( v14 >= 0.0 )
            {
              if ( v14 > 255.0 )
                v14 = 255.0;
            }
            else
            {
              v14 = 0.0;
            }
            v12[v10++] = (int)v14;
            ++v11;
          }
          while ( v10 < n );
          v4 = comp;
          v9 = v22;
          v6 = output;
        }
        if ( v10 < v4 )
        {
          v15 = v9 + v10;
          v16 = (float)(data[v15] * 255.0) + 0.5;
          if ( v16 >= 0.0 )
          {
            if ( v16 > 255.0 )
              v16 = 255.0;
          }
          else
          {
            v16 = 0.0;
          }
          v6[v15] = (int)v16;
        }
        v8 = (float *)((char *)v21 + HIDWORD(v19));
        v9 += v4;
        v17 = v20-- == 1;
        v22 = v9;
        v21 = (float *)((char *)v21 + HIDWORD(v19));
      }
      while ( !v17 );
    }
    free(pMem: data);
    return v6;
  }
  else
  {
    free(pMem: data);
    failure_reason = "outofmem";
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004025A0
// Name: build_huffman
// Source: json
//------------------------------------------------------------------------------
int __cdecl build_huffman(huffman *h)
{
  int *count; // ecx
  int v2; // eax
  int v3; // edx
  int *v4; // esi
  int v5; // ecx
  unsigned __int8 v6; // dl
  int v7; // eax
  int v8; // esi
  unsigned __int8 *size; // edx
  unsigned int *v10; // ebx
  int v11; // edi
  unsigned __int16 *v12; // ecx
  unsigned int v13; // ebx
  bool v14; // sf
  int v15; // edi
  unsigned __int16 *code; // ebx
  unsigned int v17; // eax
  char v18; // cl
  signed int v19; // eax
  unsigned int *v21; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int ia; // [esp+14h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  i = 0;
  v4 = count;
  do
  {
    v5 = 0;
    if ( *v4 > 0 )
    {
      v6 = v3 + 1;
      do
      {
        h->size[v2] = v6;
        ++v5;
        ++v2;
      }
      while ( v5 < *v4 );
      v3 = i;
    }
    ++v3;
    ++v4;
    i = v3;
  }
  while ( v3 < 16 );
  h->size[v2] = 0;
  v7 = 0;
  v8 = 0;
  size = h->size;
  v10 = &h->maxcode[1];
  v11 = 1;
  ia = 15;
  v21 = &h->maxcode[1];
  do
  {
    v10[18] = v8 - v7;
    if ( *size == v11 )
    {
      v12 = &h->code[v8];
      do
      {
        ++v8;
        *v12 = v7;
        size = &h->size[v8];
        ++v12;
        ++v7;
      }
      while ( *size == v11 );
      if ( v7 - 1 >= 1 << v11 )
      {
        failure_reason = "bad code lengths";
        return 0;
      }
    }
    v13 = v7 << ia;
    v7 *= 2;
    ++v11;
    *v21 = v13;
    v10 = v21 + 1;
    v14 = --ia < 0;
    ++v21;
  }
  while ( !v14 );
  h->maxcode[v11] = -1;
  memset(dst: h->fast, value: 0xFFu, count: sizeof(h->fast));
  v15 = 0;
  if ( v8 > 0 )
  {
    code = h->code;
    do
    {
      v17 = h->size[v15];
      if ( v17 <= 9 )
      {
        v18 = 9 - v17;
        v19 = 1 << (9 - v17);
        if ( v19 > 0 )
          memset(dst: &h->fast[*code << v18], value: v15, count: v19);
      }
      ++v15;
      ++code;
    }
    while ( v15 < v8 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402700
// Name: grow_buffer_unsafe
// Source: json
//------------------------------------------------------------------------------
void __usercall grow_buffer_unsafe(jpeg *j@<esi>)
{
  unsigned __int8 *img_buffer; // eax
  int v2; // ebx
  unsigned __int8 *buffer_start; // edi
  unsigned int v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // edi
  unsigned int v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // ecx
  int code_bits; // eax
  int v13; // ebx

  while ( 1 )
  {
    if ( j->nomore != 0 )
      goto LABEL_9;
    img_buffer = j->s.img_buffer;
    if ( img_buffer >= j->s.img_buffer_end )
    {
      if ( j->s.from_file != 0 )
      {
        buffer_start = j->s.buffer_start;
        v4 = fread(buffer: j->s.buffer_start, elementSize: 1u, count: j->s.buflen, stream: j->s.img_file);
        if ( v4 != 0 )
        {
          j->s.img_buffer = buffer_start;
          j->s.img_buffer_end = &buffer_start[v4];
        }
        else
        {
          j->s.from_file = 0;
          v5 = j->s.img_buffer_end - 1;
          j->s.img_buffer = v5;
          *v5 = 0;
        }
        v6 = j->s.img_buffer;
        v2 = *v6;
        j->s.img_buffer = v6 + 1;
        goto LABEL_10;
      }
LABEL_9:
      v2 = 0;
      goto LABEL_10;
    }
    v2 = *img_buffer;
    j->s.img_buffer = img_buffer + 1;
LABEL_10:
    if ( v2 == 255 )
    {
      v7 = j->s.img_buffer;
      if ( v7 < j->s.img_buffer_end )
        goto LABEL_17;
      if ( j->s.from_file != 0 )
        break;
    }
LABEL_18:
    code_bits = j->code_bits;
    v13 = v2 << (24 - code_bits);
    code_bits += 8;
    j->code_bits = code_bits;
    j->code_buffer |= v13;
    if ( code_bits > 24 )
      return;
  }
  v8 = j->s.buffer_start;
  v9 = fread(buffer: j->s.buffer_start, elementSize: 1u, count: j->s.buflen, stream: j->s.img_file);
  if ( v9 != 0 )
  {
    j->s.img_buffer = v8;
    j->s.img_buffer_end = &v8[v9];
  }
  else
  {
    j->s.from_file = 0;
    v10 = j->s.img_buffer_end - 1;
    j->s.img_buffer = v10;
    *v10 = 0;
  }
  v7 = j->s.img_buffer;
LABEL_17:
  v11 = *v7;
  j->s.img_buffer = v7 + 1;
  if ( v11 == 0 )
    goto LABEL_18;
  j->marker = v11;
  j->nomore = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402840
// Name: decode_block
// Source: json
//------------------------------------------------------------------------------
int __usercall decode_block@<eax>(jpeg *j@<eax>, __int16 *data, huffman *hdc, huffman *hac, int b)
{
  unsigned int code_buffer; // eax
  int v7; // edx
  int v8; // ecx
  int code_bits; // edi
  int v10; // ebx
  unsigned int *v11; // edi
  int v12; // edx
  unsigned int v13; // edi
  int v14; // eax
  unsigned int v15; // eax
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  unsigned int *v21; // edi
  int v22; // eax
  unsigned int v23; // edi
  int v24; // ebx
  int v25; // eax
  unsigned int v26; // eax
  int v28; // [esp+Ch] [ebp-4h]
  int k; // [esp+1Ch] [ebp+Ch]
  int ka; // [esp+1Ch] [ebp+Ch]

  if ( j->code_bits < 16 )
    grow_buffer_unsafe(j);
  code_buffer = j->code_buffer;
  v7 = hdc->fast[code_buffer >> 23];
  if ( v7 != 255 )
  {
    v8 = hdc->size[v7];
    code_bits = j->code_bits;
    if ( v8 <= code_bits )
    {
      j->code_bits = code_bits - v8;
      j->code_buffer = code_buffer << v8;
      v10 = hdc->values[v7];
      goto LABEL_11;
    }
    goto LABEL_39;
  }
  v11 = &hdc->maxcode[10];
  v12 = 10;
  if ( HIWORD(code_buffer) >= hdc->maxcode[10] )
  {
    do
    {
      ++v11;
      ++v12;
    }
    while ( HIWORD(code_buffer) >= *v11 );
    if ( v12 == 17 )
    {
LABEL_38:
      j->code_bits -= 16;
      goto LABEL_39;
    }
  }
  if ( v12 > j->code_bits )
  {
LABEL_39:
    failure_reason = "bad huffman code";
    return 0;
  }
  v13 = hdc->delta[v12] + (bmask[v12] & (code_buffer >> (32 - v12)));
  j->code_bits -= v12;
  j->code_buffer = code_buffer << v12;
  v10 = hdc->values[v13];
LABEL_11:
  memset(dst: (unsigned __int8 *)data, value: 0, count: 0x80u);
  if ( v10 != 0 )
  {
    if ( j->code_bits < v10 )
      grow_buffer_unsafe(j);
    v14 = __ROL4__(j->code_buffer, v10);
    j->code_buffer = v14 & ~bmask[v10];
    v15 = bmask[v10] & v14;
    j->code_bits -= v10;
    if ( v15 < 1 << (v10 - 1) )
      v15 = v15 - (1 << v10) + 1;
  }
  else
  {
    v15 = 0;
  }
  v16 = v15 + j->img_comp[b].dc_pred;
  j->img_comp[b].dc_pred = v16;
  *data = v16;
  k = 1;
  do
  {
    if ( j->code_bits < 16 )
      grow_buffer_unsafe(j);
    v17 = j->code_buffer;
    v28 = hac->fast[v17 >> 23];
    if ( v28 == 255 )
    {
      v21 = &hac->maxcode[10];
      v22 = 10;
      if ( HIWORD(v17) >= hac->maxcode[10] )
      {
        do
        {
          ++v21;
          ++v22;
        }
        while ( HIWORD(v17) >= *v21 );
        if ( v22 == 17 )
          goto LABEL_38;
      }
      if ( v22 > j->code_bits )
        goto LABEL_39;
      v23 = hac->delta[v22] + (bmask[v22] & (v17 >> (32 - v22)));
      j->code_bits -= v22;
      j->code_buffer = v17 << v22;
      v20 = hac->values[v23];
    }
    else
    {
      v18 = hac->size[hac->fast[j->code_buffer >> 23]];
      v19 = j->code_bits;
      if ( v18 > v19 )
        goto LABEL_39;
      j->code_bits = v19 - v18;
      j->code_buffer = v17 << v18;
      v20 = hac->values[v28];
    }
    v24 = v20 & 0xF;
    if ( (v20 & 0xF) != 0 )
    {
      ka = (v20 >> 4) + k;
      if ( j->code_bits < v24 )
        grow_buffer_unsafe(j);
      v25 = __ROL4__(j->code_buffer, v24);
      j->code_buffer = v25 & ~bmask[v24];
      v26 = bmask[v24] & v25;
      j->code_bits -= v24;
      if ( v26 < 1 << (v24 - 1) )
        LOWORD(v26) = v26 - (1 << v24) + 1;
      data[dezigzag[ka]] = v26;
      k = ka + 1;
    }
    else
    {
      if ( v20 != 240 )
        return 1;
      k += 16;
    }
  }
  while ( k < 64 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402B30
// Name: idct_block
// Source: json
//------------------------------------------------------------------------------
void __usercall idct_block(
        __int16 *data@<edx>,
        unsigned __int8 *dequantize@<eax>,
        unsigned __int8 *out,
        int out_stride)
{
  int *v4; // edi
  unsigned __int8 *v5; // esi
  __int16 *v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // ebx
  int v13; // edi
  int v14; // ebx
  int v15; // ecx
  int v16; // ecx
  int v17; // eax
  int v18; // edi
  int v19; // ecx
  int v20; // eax
  int v21; // edi
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // ecx
  int v26; // edx
  int v27; // esi
  int v28; // edi
  int v29; // ebx
  int v30; // edi
  int v31; // edx
  int v32; // ecx
  int v33; // ebx
  int v34; // eax
  int v35; // eax
  int v36; // ecx
  int v37; // esi
  int v38; // ebx
  int v39; // esi
  int v40; // ecx
  int v41; // eax
  bool v42; // zf
  int *v43; // esi
  int v44; // eax
  int v45; // ebx
  int v46; // edx
  int v47; // edi
  int v48; // ecx
  int v49; // edx
  int v50; // eax
  int v51; // ecx
  int v52; // ebx
  int v53; // eax
  int v54; // edx
  int v55; // eax
  int v56; // ecx
  int v57; // edx
  int v58; // esi
  int v59; // edi
  int v60; // ebx
  int v61; // esi
  int v62; // edx
  int v63; // ebx
  int v64; // eax
  int v65; // ecx
  char v66; // dl
  unsigned __int8 *v67; // ebx
  int v68; // edi
  char v69; // dl
  int v70; // esi
  int v71; // edx
  int v72; // eax
  int v73; // edx
  int v74; // eax
  int v75; // ecx
  int v76; // edx
  int v77; // eax
  int v78; // ecx
  int v79; // esi
  int val[64]; // [esp+Ch] [ebp-134h] BYREF
  unsigned __int8 *v81; // [esp+10Ch] [ebp-34h]
  int x1; // [esp+110h] [ebp-30h]
  int x0; // [esp+114h] [ebp-2Ch]
  int t1; // [esp+118h] [ebp-28h]
  int t0; // [esp+11Ch] [ebp-24h]
  int v86; // [esp+120h] [ebp-20h]
  int p2; // [esp+124h] [ebp-1Ch]
  int x2; // [esp+128h] [ebp-18h]
  int v89; // [esp+12Ch] [ebp-14h]
  unsigned __int8 *v90; // [esp+130h] [ebp-10h]
  int p4; // [esp+134h] [ebp-Ch]
  int p1; // [esp+138h] [ebp-8h]
  int p3; // [esp+13Ch] [ebp-4h]
  unsigned __int8 *outa; // [esp+148h] [ebp+8h]

  v4 = &val[8];
  v5 = dequantize + 48;
  v6 = data + 48;
  v86 = (int)&val[8];
  v81 = dequantize + 48;
  v90 = (unsigned __int8 *)v6;
  v89 = 8;
  do
  {
    p1 = (unsigned __int16)*(v6 - 40);
    if ( (_WORD)p1 != 0
      || *(v6 - 32) != 0
      || *(v6 - 24) != 0
      || *(v6 - 16) != 0
      || *(v6 - 8) != 0
      || *v6 != 0
      || v6[8] != 0 )
    {
      v8 = *(v5 - 32) * *(v6 - 32);
      v9 = *v6 * *v5;
      v10 = 2217 * (v9 + v8);
      v11 = v10 + 3135 * v8;
      v12 = v10;
      v13 = *(v5 - 16);
      v14 = v12 - 7567 * v9;
      v15 = *(v6 - 48);
      p3 = v11;
      v16 = *(v5 - 48) * v15;
      v17 = v13 * *(v6 - 16);
      v18 = (v17 + v16) << 12;
      v19 = v16 - v17;
      v20 = v18 + p3;
      v19 <<= 12;
      p2 = v18 - p3;
      v21 = *(v5 - 8);
      x0 = v20;
      v22 = v19 + v14;
      t1 = v19 - v14;
      v23 = v5[8];
      x1 = v22;
      v24 = v23 * v6[8];
      v25 = v21 * *(v6 - 8);
      v26 = *(v5 - 24) * *(v6 - 24);
      v27 = (__int16)p1 * *(v5 - 40);
      v28 = 4816 * (v24 + v26 + v25 + v27);
      v29 = v28 - 10497 * (v25 + v26);
      p1 = -8034 * (v24 + v26);
      p4 = -1597 * (v25 + v27);
      v30 = v28 - 3685 * (v24 + v27);
      p3 = v30 + p4 + 6149 * v27;
      x2 = v29 + p1 + 12586 * v26;
      v31 = t1;
      v32 = v29 + p4 + 8410 * v25;
      v33 = x0 + 512 - p3;
      v34 = v30 + 1223 * v24;
      v4 = (int *)v86;
      v35 = p1 + v34;
      t0 = v32;
      v36 = x1 + 512;
      *(_DWORD *)(v86 - 32) = (x0 + 512 + p3) >> 10;
      v37 = x2;
      v4[48] = v33 >> 10;
      v38 = v36 + v37;
      v31 += 512;
      v4[40] = (v36 - v37) >> 10;
      v39 = v31 + t0;
      p1 = v35;
      v40 = v35;
      v41 = p2 + 512;
      v4[32] = (v31 - t0) >> 10;
      v4[8] = v39 >> 10;
      v5 = v81;
      v4[16] = (v41 + v40) >> 10;
      v6 = (__int16 *)v90;
      *v4 = v38 >> 10;
      v7 = (v41 - v40) >> 10;
    }
    else
    {
      v7 = 4 * *(v5 - 48) * *(v6 - 48);
      v4[48] = v7;
      v4[40] = v7;
      v4[32] = v7;
      v4[16] = v7;
      v4[8] = v7;
      *v4 = v7;
      *(v4 - 8) = v7;
    }
    v4[24] = v7;
    ++v6;
    ++v5;
    ++v4;
    v42 = v89-- == 1;
    v90 = (unsigned __int8 *)v6;
    v81 = v5;
    v86 = (int)v4;
  }
  while ( !v42 );
  v43 = &val[6];
  v90 = out + 1;
  v89 = (int)&val[6];
  v86 = 8;
  do
  {
    v44 = *(v43 - 4);
    v45 = *(v43 - 2);
    v46 = 2217 * (*v43 + v44);
    v47 = v46 - 7567 * *v43;
    v48 = *(v43 - 6);
    v49 = 3135 * v44 + v46;
    v50 = v45 + v48;
    v51 = v48 - v45;
    v50 <<= 12;
    v52 = v50 + v49;
    v53 = v50 - v49;
    v51 <<= 12;
    v54 = v51 + v47;
    p4 = v53;
    v55 = v43[1];
    x2 = v51 - v47;
    v56 = *(v43 - 1);
    x0 = v54;
    v57 = *(v43 - 3);
    v58 = *(v43 - 5);
    x1 = v52;
    v59 = 4816 * (v55 + v57 + v56 + v58);
    p1 = v59 - 3685 * (v55 + v58);
    v60 = v59 - 10497 * (v56 + v57);
    p4 += 16842752;
    p3 = -8034 * (v55 + v57);
    outa = (unsigned __int8 *)(-1597 * (v56 + v58));
    v61 = (int)&outa[6149 * v58 + p1];
    v62 = v60 + p3 + 12586 * v57;
    t1 = (int)&outa[8410 * v56 + v60];
    t0 = p3 + p1 + 1223 * v55;
    v63 = (x1 + 16842752 + v61) >> 17;
    v64 = x0 + 16842752;
    v65 = x2 + 16842752;
    p2 = v62;
    if ( (unsigned int)v63 <= 0xFF )
    {
      v66 = (x1 + 16842752 + v61) >> 17;
    }
    else if ( v63 >= 0 )
    {
      v66 = -1;
    }
    else
    {
      v66 = 0;
    }
    v67 = v90;
    v68 = (x1 + 16842752 - v61) >> 17;
    *(v90 - 1) = v66;
    if ( (unsigned int)v68 <= 0xFF )
    {
      v69 = v68;
    }
    else if ( v68 >= 0 )
    {
      v69 = -1;
    }
    else
    {
      v69 = 0;
    }
    v70 = p2;
    v67[6] = v69;
    v71 = (v64 + v70) >> 17;
    if ( (unsigned int)v71 <= 0xFF )
    {
      v67 = v90;
    }
    else if ( v71 >= 0 )
    {
      LOBYTE(v71) = -1;
    }
    else
    {
      LOBYTE(v71) = 0;
    }
    v72 = (v64 - v70) >> 17;
    *v67 = v71;
    if ( (unsigned int)v72 > 0xFF )
    {
      if ( v72 >= 0 )
        LOBYTE(v72) = -1;
      else
        LOBYTE(v72) = 0;
    }
    v73 = t1;
    v67[5] = v72;
    v74 = (v65 + v73) >> 17;
    if ( (unsigned int)v74 > 0xFF )
    {
      if ( v74 >= 0 )
        LOBYTE(v74) = -1;
      else
        LOBYTE(v74) = 0;
    }
    v75 = (v65 - v73) >> 17;
    v67[1] = v74;
    if ( (unsigned int)v75 > 0xFF )
    {
      if ( v75 >= 0 )
        LOBYTE(v75) = -1;
      else
        LOBYTE(v75) = 0;
    }
    v76 = t0;
    v67[4] = v75;
    v77 = (p4 + v76) >> 17;
    if ( (unsigned int)v77 > 0xFF )
    {
      if ( v77 >= 0 )
        LOBYTE(v77) = -1;
      else
        LOBYTE(v77) = 0;
    }
    v78 = (p4 - v76) >> 17;
    v67[2] = v77;
    if ( (unsigned int)v78 > 0xFF )
    {
      if ( v78 >= 0 )
        LOBYTE(v78) = -1;
      else
        LOBYTE(v78) = 0;
    }
    v79 = v89;
    v67[3] = v78;
    v43 = (int *)(v79 + 32);
    v42 = v86-- == 1;
    v89 = (int)v43;
    v90 = &v67[out_stride];
  }
  while ( !v42 );
}

//------------------------------------------------------------------------------
// Address: 0x00403000
// Name: get_marker
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall get_marker@<al>(jpeg *j@<eax>)
{
  unsigned __int8 result; // al
  unsigned __int8 *img_buffer; // eax
  unsigned __int8 v4; // dl
  unsigned __int8 *v5; // ecx
  unsigned __int8 *buffer_start; // edi
  unsigned int v7; // eax
  unsigned __int8 *v8; // eax

  result = j->marker;
  if ( result != 0xFF )
  {
    j->marker = -1;
    return result;
  }
  img_buffer = j->s.img_buffer;
  if ( img_buffer >= j->s.img_buffer_end )
  {
    if ( j->s.from_file == 0 )
      return -1;
    refill_buffer(s: &j->s);
    img_buffer = j->s.img_buffer;
  }
  v4 = *img_buffer;
  v5 = img_buffer + 1;
  j->s.img_buffer = img_buffer + 1;
  if ( v4 != 0xFF )
    return -1;
  while ( v5 < j->s.img_buffer_end )
  {
LABEL_14:
    result = *v5++;
    j->s.img_buffer = v5;
    if ( result != 0xFF )
      return result;
  }
  if ( j->s.from_file != 0 )
  {
    buffer_start = j->s.buffer_start;
    v7 = fread(buffer: j->s.buffer_start, elementSize: 1u, count: j->s.buflen, stream: j->s.img_file);
    if ( v7 != 0 )
    {
      j->s.img_buffer = buffer_start;
      j->s.img_buffer_end = &buffer_start[v7];
    }
    else
    {
      j->s.from_file = 0;
      v8 = j->s.img_buffer_end - 1;
      j->s.img_buffer = v8;
      *v8 = 0;
    }
    v5 = j->s.img_buffer;
    goto LABEL_14;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004030C0
// Name: parse_entropy_coded_data
// Source: json
//------------------------------------------------------------------------------
int __cdecl parse_entropy_coded_data(jpeg *z)
{
  int restart_interval; // eax
  int v3; // esi
  bool v4; // zf
  unsigned int *v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // ecx
  unsigned __int8 v9; // al
  int v10; // eax
  int v12; // ecx
  int v13; // edx
  bool v14; // cc
  unsigned int *v15; // esi
  int v16; // eax
  int v17; // edi
  unsigned int v18; // edx
  int v19; // edi
  unsigned __int8 marker; // al
  int v21; // eax
  __int16 data[64]; // [esp+Ch] [ebp-A0h] BYREF
  int x2; // [esp+8Ch] [ebp-20h]
  int *p_h; // [esp+90h] [ebp-1Ch]
  int y; // [esp+94h] [ebp-18h]
  int *order; // [esp+98h] [ebp-14h]
  int k; // [esp+9Ch] [ebp-10h]
  int n; // [esp+A0h] [ebp-Ch]
  int i; // [esp+A4h] [ebp-8h]
  int w; // [esp+A8h] [ebp-4h]
  int x; // [esp+B4h] [ebp+8h]
  int xa; // [esp+B4h] [ebp+8h]

  restart_interval = z->restart_interval;
  v3 = 0;
  z->code_bits = 0;
  z->code_buffer = 0;
  z->nomore = 0;
  z->img_comp[2].dc_pred = 0;
  z->img_comp[1].dc_pred = 0;
  z->img_comp[0].dc_pred = 0;
  z->marker = -1;
  if ( restart_interval == 0 )
    restart_interval = 0x7FFFFFFF;
  v4 = z->scan_n == 1;
  z->todo = restart_interval;
  if ( !v4 )
  {
    i = 0;
    if ( z->img_mcu_y > 0 )
    {
      while ( 1 )
      {
        w = 0;
        if ( z->img_mcu_x > 0 )
          break;
LABEL_39:
        if ( ++i >= z->img_mcu_y )
          return 1;
      }
      while ( 1 )
      {
        k = 0;
        if ( z->scan_n > 0 )
          break;
LABEL_30:
        if ( --z->todo <= 0 )
        {
          if ( z->code_bits < 24 )
            grow_buffer_unsafe(j: z);
          marker = z->marker;
          if ( marker < 0xD0u || marker > 0xD7u )
            return 1;
          v21 = z->restart_interval;
          z->code_bits = 0;
          z->code_buffer = 0;
          z->nomore = 0;
          z->img_comp[2].dc_pred = 0;
          z->img_comp[1].dc_pred = 0;
          z->img_comp[0].dc_pred = 0;
          z->marker = -1;
          if ( v21 == 0 )
            v21 = 0x7FFFFFFF;
          z->todo = v21;
        }
        if ( ++w >= z->img_mcu_x )
          goto LABEL_39;
      }
      order = z->order;
      while ( 1 )
      {
        v12 = *order;
        v13 = 7 * *order;
        v14 = z->img_comp[*order].v <= 0;
        y = 0;
        v15 = &z->s.img_x + 2 * v13;
        n = v12;
        if ( !v14 )
          break;
LABEL_29:
        ++order;
        if ( ++k >= z->scan_n )
          goto LABEL_30;
      }
      p_h = &z->img_comp[v12].h;
      while ( 1 )
      {
        v16 = *p_h;
        xa = 0;
        if ( *p_h > 0 )
          break;
LABEL_28:
        if ( ++y >= (int)v15[3473] )
          goto LABEL_29;
      }
      while ( 1 )
      {
        v17 = y + i * v15[3473];
        v18 = v15[3475];
        x2 = 8 * (xa + w * v16);
        v19 = 8 * v17;
        if ( decode_block(j: z, data, hdc: &z->huff_dc[v18], hac: &z->huff_ac[v15[3476]], b: v12) == 0 )
          return 0;
        idct_block(
          data,
          dequantize: z->dequant[v15[3474]],
          out: (unsigned __int8 *)(x2 + v15[3482] + v19 * v15[3480]),
          out_stride: v15[3480]);
        v16 = *p_h;
        ++xa;
        v12 = n;
        if ( xa >= *p_h )
          goto LABEL_28;
      }
    }
    return 1;
  }
  v5 = &z->s.img_x + 14 * z->order[0];
  v6 = v5[3478];
  k = z->order[0];
  v7 = (int)(v5[3479] + 7) >> 3;
  v8 = (int)(v6 + 7) >> 3;
  w = v8;
  n = v7;
  x = 0;
  if ( v7 <= 0 )
    return 1;
  while ( 1 )
  {
    i = 0;
    if ( v8 > 0 )
      break;
LABEL_17:
    if ( ++x >= v7 )
      return 1;
  }
  while ( decode_block(j: z, data, hdc: &z->huff_dc[v5[3475]], hac: &z->huff_ac[v5[3476]], b: k) != 0 )
  {
    idct_block(
      data,
      dequantize: z->dequant[v5[3474]],
      out: (unsigned __int8 *)(v5[3482] + 8 * (v3 + x * v5[3480])),
      out_stride: v5[3480]);
    if ( --z->todo <= 0 )
    {
      if ( z->code_bits < 24 )
      {
        grow_buffer_unsafe(j: z);
        v3 = i;
      }
      v9 = z->marker;
      if ( v9 < 0xD0u || v9 > 0xD7u )
        return 1;
      v10 = z->restart_interval;
      z->code_bits = 0;
      z->code_buffer = 0;
      z->nomore = 0;
      z->img_comp[2].dc_pred = 0;
      z->img_comp[1].dc_pred = 0;
      z->img_comp[0].dc_pred = 0;
      z->marker = -1;
      if ( v10 == 0 )
        v10 = 0x7FFFFFFF;
      z->todo = v10;
    }
    i = ++v3;
    if ( v3 >= w )
    {
      v8 = w;
      v7 = n;
      v3 = 0;
      goto LABEL_17;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004034C0
// Name: process_marker
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall process_marker@<eax>(jpeg *z@<eax>, int m@<ecx>)
{
  int v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // ecx
  unsigned __int8 *v7; // eax
  int v8; // edi
  int v9; // ebx
  unsigned __int8 *v10; // ecx
  unsigned __int8 v11; // al
  unsigned __int8 *v12; // ecx
  int v13; // ecx
  unsigned __int8 *img_buffer; // ecx
  int v15; // edi
  int v16; // eax
  unsigned __int8 *v17; // ecx
  int v18; // ebx
  int v19; // eax
  int v20; // ebx
  unsigned __int8 *v21; // edx
  unsigned __int8 *v22; // ecx
  int v23; // eax
  unsigned __int8 *v24; // ecx
  char *v25; // edi
  unsigned __int8 *v26; // edi
  int v27; // edx
  int v28; // ebx
  unsigned __int8 *v29; // ecx
  unsigned __int8 v30; // al
  unsigned __int8 *buffer_start; // edi
  unsigned int v32; // eax
  unsigned __int8 *v33; // eax
  unsigned __int8 *v34; // ecx
  int v35; // eax
  int v36; // eax
  _iobuf *img_file; // edi
  int v38; // eax
  int v39; // ecx
  int sizes[16]; // [esp+Ch] [ebp-4Ch]
  unsigned __int8 *v; // [esp+4Ch] [ebp-Ch]
  int v42; // [esp+50h] [ebp-8h]
  int L; // [esp+54h] [ebp-4h]

  switch ( m )
  {
    case 194:
      failure_reason = "progressive jpeg";
      return 0;
    case 196:
      v4 = get16(s: &z->s) - 2;
      L = v4;
      if ( v4 <= 0 )
        return v4 == 0;
      while ( 1 )
      {
        img_buffer = z->s.img_buffer;
        v15 = 0;
        v42 = 0;
        if ( img_buffer >= z->s.img_buffer_end )
        {
          if ( z->s.from_file != 0 )
          {
            refill_buffer(s: &z->s);
            v17 = z->s.img_buffer;
            v16 = *v17;
            z->s.img_buffer = v17 + 1;
          }
          else
          {
            v16 = 0;
          }
        }
        else
        {
          v16 = *img_buffer;
          z->s.img_buffer = img_buffer + 1;
        }
        v18 = v16;
        v19 = v16 & 0xF;
        v20 = v18 >> 4;
        v21 = (unsigned __int8 *)v19;
        v = (unsigned __int8 *)v19;
        if ( v20 > 1 || v19 > 3 )
          break;
        do
        {
          v22 = z->s.img_buffer;
          if ( v22 >= z->s.img_buffer_end )
          {
            if ( z->s.from_file != 0 )
            {
              refill_buffer(s: &z->s);
              v24 = z->s.img_buffer;
              v23 = *v24;
              v21 = v;
              z->s.img_buffer = v24 + 1;
            }
            else
            {
              v23 = 0;
            }
          }
          else
          {
            v23 = *v22;
            z->s.img_buffer = v22 + 1;
          }
          v42 += v23;
          sizes[v15++] = v23;
        }
        while ( v15 < 16 );
        L -= 17;
        v25 = (char *)z + 1680 * (_DWORD)v21;
        if ( v20 != 0 )
        {
          if ( build_huffman(h: (huffman *)(v25 + 6884)) == 0 )
            return 0;
          v26 = (unsigned __int8 *)(v25 + 7908);
        }
        else
        {
          if ( build_huffman(h: (huffman *)(v25 + 164)) == 0 )
            return 0;
          v26 = (unsigned __int8 *)(v25 + 1188);
        }
        v27 = v42;
        v28 = 0;
        for ( v = v26; v28 < v27; ++v28 )
        {
          v29 = z->s.img_buffer;
          if ( v29 >= z->s.img_buffer_end )
          {
            if ( z->s.from_file != 0 )
            {
              buffer_start = z->s.buffer_start;
              v32 = fread(buffer: z->s.buffer_start, elementSize: 1u, count: z->s.buflen, stream: z->s.img_file);
              if ( v32 != 0 )
              {
                z->s.img_buffer = buffer_start;
                z->s.img_buffer_end = &buffer_start[v32];
              }
              else
              {
                z->s.from_file = 0;
                v33 = z->s.img_buffer_end - 1;
                z->s.img_buffer = v33;
                *v33 = 0;
              }
              v34 = z->s.img_buffer;
              v30 = *v34;
              v27 = v42;
              z->s.img_buffer = v34 + 1;
            }
            else
            {
              v30 = 0;
            }
          }
          else
          {
            v30 = *v29;
            z->s.img_buffer = v29 + 1;
          }
          v[v28] = v30;
        }
        v35 = L - v27;
        L = v35;
        if ( v35 <= 0 )
          return v35 == 0;
      }
      failure_reason = "bad DHT header";
      return 0;
    case 219:
      v4 = get16(s: &z->s) - 2;
      L = v4;
      if ( v4 <= 0 )
        return v4 == 0;
      break;
    case 221:
      if ( get16(s: &z->s) == 4 )
      {
        z->restart_interval = get16(s: &z->s);
        return 1;
      }
      else
      {
        failure_reason = "bad DRI len";
        return 0;
      }
    case 255:
      failure_reason = "expected marker";
      return 0;
    default:
      if ( (m < 224 || m > 239) && m != 254 )
        return 0;
      v36 = get16(s: &z->s);
      img_file = z->s.img_file;
      v38 = v36 - 2;
      if ( img_file != nullptr && (v39 = z->s.img_buffer_end - z->s.img_buffer) < v38 )
      {
        z->s.img_buffer = z->s.img_buffer_end;
        fseek(stream: img_file, offset: v38 - v39, whence: 1);
        return 1;
      }
      else
      {
        z->s.img_buffer += v38;
        return 1;
      }
  }
  while ( 1 )
  {
    v5 = z->s.img_buffer;
    if ( v5 >= z->s.img_buffer_end )
    {
      if ( z->s.from_file != 0 )
      {
        refill_buffer(s: &z->s);
        v7 = z->s.img_buffer;
        v6 = *v7;
        z->s.img_buffer = v7 + 1;
      }
      else
      {
        v6 = 0;
      }
    }
    else
    {
      v6 = *v5;
      z->s.img_buffer = v5 + 1;
    }
    if ( (v6 & 0xFFFFFFF0) != 0 )
    {
      failure_reason = "bad DQT type";
      return 0;
    }
    if ( (v6 & 0xFu) > 3 )
      break;
    v8 = 0;
    v9 = (v6 & 0xF) << 6;
    do
    {
      v10 = z->s.img_buffer;
      if ( v10 >= z->s.img_buffer_end )
      {
        if ( z->s.from_file != 0 )
        {
          refill_buffer(s: &z->s);
          v12 = z->s.img_buffer;
          v11 = *v12;
          z->s.img_buffer = v12 + 1;
        }
        else
        {
          v11 = 0;
        }
      }
      else
      {
        v11 = *v10;
        z->s.img_buffer = v10 + 1;
      }
      v13 = v9 + dezigzag[v8++];
      z->dequant[0][v13] = v11;
    }
    while ( v8 < 64 );
    v4 = L - 65;
    L = v4;
    if ( v4 <= 0 )
      return v4 == 0;
  }
  failure_reason = "bad DQT table";
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403910
// Name: process_scan_header
// Source: json
//------------------------------------------------------------------------------
int __usercall process_scan_header@<eax>(jpeg *z@<eax>)
{
  int v2; // eax
  unsigned __int8 *img_buffer; // ecx
  int v4; // edi
  int v5; // eax
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // edi
  unsigned __int8 *v13; // eax
  int img_n; // edx
  int v15; // eax
  jpeg::<unnamed_type_img_comp> *img_comp; // ecx
  char *v17; // edx
  unsigned int v18; // ecx
  unsigned __int8 *v19; // eax
  int v20; // ecx
  unsigned __int8 *v21; // eax
  unsigned __int8 *v22; // eax
  int v23; // ecx
  int *order; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = get16(s: &z->s);
  img_buffer = z->s.img_buffer;
  v4 = v2;
  if ( img_buffer >= z->s.img_buffer_end )
  {
    if ( z->s.from_file != 0 )
    {
      refill_buffer(s: &z->s);
      v6 = z->s.img_buffer;
      v5 = *v6;
      z->s.img_buffer = v6 + 1;
    }
    else
    {
      v5 = 0;
    }
  }
  else
  {
    v5 = *img_buffer;
    z->s.img_buffer = img_buffer + 1;
  }
  z->scan_n = v5;
  if ( v5 >= 1 && v5 <= 4 && v5 <= z->s.img_n )
  {
    if ( v4 != 2 * v5 + 6 )
    {
      failure_reason = "bad SOS len";
      return 0;
    }
    i = 0;
    order = z->order;
    do
    {
      v8 = z->s.img_buffer;
      if ( v8 >= z->s.img_buffer_end )
      {
        if ( z->s.from_file != 0 )
        {
          refill_buffer(s: &z->s);
          v10 = z->s.img_buffer;
          v9 = *v10;
          z->s.img_buffer = v10 + 1;
        }
        else
        {
          v9 = 0;
        }
      }
      else
      {
        v9 = *v8;
        z->s.img_buffer = v8 + 1;
      }
      v11 = z->s.img_buffer;
      if ( v11 >= z->s.img_buffer_end )
      {
        if ( z->s.from_file != 0 )
        {
          refill_buffer(s: &z->s);
          v13 = z->s.img_buffer;
          v12 = *v13;
          z->s.img_buffer = v13 + 1;
        }
        else
        {
          v12 = 0;
        }
      }
      else
      {
        v12 = *v11;
        z->s.img_buffer = v11 + 1;
      }
      img_n = z->s.img_n;
      v15 = 0;
      if ( img_n > 0 )
      {
        img_comp = z->img_comp;
        do
        {
          if ( img_comp->id == v9 )
            break;
          ++v15;
          ++img_comp;
        }
        while ( v15 < img_n );
      }
      if ( v15 == img_n )
        return 0;
      v17 = (char *)z + 56 * v15;
      *((_DWORD *)v17 + 3475) = v12 >> 4;
      if ( v12 >> 4 > 3 )
      {
        failure_reason = "bad DC huff";
        return 0;
      }
      v18 = v12 & 0xF;
      *((_DWORD *)v17 + 3476) = v18;
      if ( v18 > 3 )
      {
        failure_reason = "bad AC huff";
        return 0;
      }
      *order = v15;
      ++i;
      ++order;
    }
    while ( i < z->scan_n );
    v19 = z->s.img_buffer;
    if ( v19 >= z->s.img_buffer_end )
    {
      if ( z->s.from_file == 0 )
        goto LABEL_35;
      refill_buffer(s: &z->s);
      v19 = z->s.img_buffer;
    }
    v20 = *v19;
    z->s.img_buffer = v19 + 1;
    if ( v20 != 0 )
    {
LABEL_46:
      failure_reason = "bad SOS";
      return 0;
    }
LABEL_35:
    v21 = z->s.img_buffer;
    if ( v21 >= z->s.img_buffer_end )
    {
      if ( z->s.from_file != 0 )
      {
        refill_buffer(s: &z->s);
        ++z->s.img_buffer;
      }
    }
    else
    {
      z->s.img_buffer = v21 + 1;
    }
    v22 = z->s.img_buffer;
    if ( v22 >= z->s.img_buffer_end )
    {
      if ( z->s.from_file == 0 )
        return 1;
      refill_buffer(s: &z->s);
      v22 = z->s.img_buffer;
    }
    v23 = *v22;
    z->s.img_buffer = v22 + 1;
    if ( v23 != 0 )
      goto LABEL_46;
    return 1;
  }
  failure_reason = "bad SOS component count";
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403B80
// Name: process_frame_header
// Source: json
//------------------------------------------------------------------------------
int __usercall process_frame_header@<eax>(jpeg *z@<eax>, int scan)
{
  int v3; // edi
  unsigned __int8 *img_buffer; // eax
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned __int8 *v9; // eax
  int v10; // ecx
  unsigned __int8 **p_linebuf; // eax
  int img_n; // eax
  int v13; // edi
  int *p_h; // ebx
  unsigned __int8 *v15; // ecx
  int v16; // eax
  unsigned __int8 *v17; // ecx
  unsigned __int8 *v18; // eax
  int v19; // ecx
  unsigned __int8 *v20; // eax
  int v21; // ecx
  unsigned __int8 *v22; // ecx
  int v23; // eax
  unsigned __int8 *v24; // ecx
  int v25; // ebx
  int v26; // edx
  int *p_v; // eax
  unsigned int v28; // eax
  int *j; // edi
  int v30; // ecx
  int v31; // eax
  void *v32; // eax
  int v33; // edi
  unsigned __int8 **p_data; // esi
  unsigned int v35; // [esp-8h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-Ch]
  int ia; // [esp+8h] [ebp-Ch]
  int v_max; // [esp+Ch] [ebp-8h]
  int h_max; // [esp+10h] [ebp-4h]

  h_max = 1;
  v_max = 1;
  v3 = get16(s: &z->s);
  if ( v3 < 11 )
  {
    failure_reason = "bad SOF len";
    return 0;
  }
  img_buffer = z->s.img_buffer;
  if ( img_buffer >= z->s.img_buffer_end )
  {
    if ( z->s.from_file == 0 )
    {
LABEL_7:
      failure_reason = "only 8-bit";
      return 0;
    }
    refill_buffer(s: &z->s);
    img_buffer = z->s.img_buffer;
  }
  v6 = *img_buffer;
  z->s.img_buffer = img_buffer + 1;
  if ( v6 != 8 )
    goto LABEL_7;
  v7 = get16(s: &z->s);
  z->s.img_y = v7;
  if ( v7 == 0 )
  {
    failure_reason = "no header height";
    return 0;
  }
  v8 = get16(s: &z->s);
  z->s.img_x = v8;
  if ( v8 == 0 )
  {
    failure_reason = "0 width";
    return 0;
  }
  v9 = z->s.img_buffer;
  if ( v9 >= z->s.img_buffer_end )
  {
    if ( z->s.from_file == 0 )
    {
LABEL_17:
      failure_reason = "bad component count";
      return 0;
    }
    refill_buffer(s: &z->s);
    v9 = z->s.img_buffer;
  }
  v10 = *v9;
  z->s.img_buffer = v9 + 1;
  if ( v10 != 3 && v10 != 1 )
    goto LABEL_17;
  z->s.img_n = v10;
  p_linebuf = &z->img_comp[0].linebuf;
  do
  {
    *(p_linebuf - 2) = nullptr;
    *p_linebuf = nullptr;
    p_linebuf += 14;
    --v10;
  }
  while ( v10 != 0 );
  img_n = z->s.img_n;
  if ( v3 != 3 * img_n + 8 )
  {
    failure_reason = "bad SOF len";
    return 0;
  }
  v13 = 0;
  if ( img_n <= 0 )
  {
LABEL_48:
    if ( scan != 0 )
      return 1;
    v25 = z->s.img_n;
    if ( 0x40000000 / z->s.img_x / v25 < z->s.img_y )
    {
      failure_reason = "too large";
      return 0;
    }
    if ( v25 > 0 )
    {
      v26 = z->s.img_n;
      p_v = &z->img_comp[0].v;
      do
      {
        if ( *(p_v - 1) > h_max )
          h_max = *(p_v - 1);
        if ( *p_v > v_max )
          v_max = *p_v;
        p_v += 14;
        --v26;
      }
      while ( v26 != 0 );
    }
    z->img_h_max = h_max;
    z->img_v_max = v_max;
    v28 = (z->s.img_x + 8 * h_max - 1) / (8 * h_max);
    z->img_mcu_w = 8 * h_max;
    z->img_mcu_h = 8 * v_max;
    ia = 0;
    z->img_mcu_x = v28;
    z->img_mcu_y = (z->s.img_y + 8 * v_max - 1) / (8 * v_max);
    if ( v25 <= 0 )
    {
      return 1;
    }
    else
    {
      for ( j = &z->img_comp[0].h; ; j += 14 )
      {
        v30 = *j;
        j[6] = (*j * z->s.img_x + h_max - 1) / h_max;
        j[7] = (j[1] * z->s.img_y + v_max - 1) / v_max;
        j[8] = 8 * v30 * z->img_mcu_x;
        v31 = 8 * j[1] * z->img_mcu_y;
        v35 = v31 * j[8] + 15;
        j[9] = v31;
        v32 = operator new(nSize: v35);
        j[11] = (int)v32;
        if ( v32 == nullptr )
          break;
        j[10] = ((unsigned int)v32 + 15) & 0xFFFFFFF0;
        j[12] = 0;
        if ( ++ia >= z->s.img_n )
          return 1;
      }
      v33 = ia - 1;
      if ( ia - 1 >= 0 )
      {
        p_data = &z->img_comp[v33].data;
        do
        {
          free(pMem: p_data[1]);
          *p_data = nullptr;
          p_data -= 14;
          --v33;
        }
        while ( v33 >= 0 );
      }
      failure_reason = "outofmem";
      return 0;
    }
  }
  else
  {
    p_h = &z->img_comp[0].h;
    while ( 1 )
    {
      v15 = z->s.img_buffer;
      if ( v15 >= z->s.img_buffer_end )
      {
        if ( z->s.from_file != 0 )
        {
          refill_buffer(s: &z->s);
          v17 = z->s.img_buffer;
          v16 = *v17;
          z->s.img_buffer = v17 + 1;
        }
        else
        {
          v16 = 0;
        }
      }
      else
      {
        v16 = *v15;
        z->s.img_buffer = v15 + 1;
      }
      *(p_h - 1) = v16;
      i = v13 + 1;
      if ( v16 != v13 + 1 && v16 != v13 )
      {
        failure_reason = "bad component ID";
        return 0;
      }
      v18 = z->s.img_buffer;
      if ( v18 >= z->s.img_buffer_end )
      {
        if ( z->s.from_file != 0 )
        {
          refill_buffer(s: &z->s);
          v20 = z->s.img_buffer;
          v19 = *v20;
          z->s.img_buffer = v20 + 1;
        }
        else
        {
          v19 = 0;
        }
      }
      else
      {
        v19 = *v18;
        z->s.img_buffer = v18 + 1;
      }
      *p_h = v19 >> 4;
      if ( v19 >> 4 == 0 || v19 >> 4 > 4 )
        break;
      v21 = v19 & 0xF;
      p_h[1] = v21;
      if ( v21 == 0 || v21 > 4 )
      {
        failure_reason = "bad V";
        return 0;
      }
      v22 = z->s.img_buffer;
      if ( v22 >= z->s.img_buffer_end )
      {
        if ( z->s.from_file != 0 )
        {
          refill_buffer(s: &z->s);
          v24 = z->s.img_buffer;
          v23 = *v24;
          z->s.img_buffer = v24 + 1;
        }
        else
        {
          v23 = 0;
        }
      }
      else
      {
        v23 = *v22;
        z->s.img_buffer = v22 + 1;
      }
      p_h[2] = v23;
      if ( v23 > 3 )
      {
        failure_reason = "bad TQ";
        return 0;
      }
      ++v13;
      p_h += 14;
      if ( i >= z->s.img_n )
        goto LABEL_48;
    }
    failure_reason = "bad H";
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403FC0
// Name: decode_jpeg_header
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall decode_jpeg_header@<eax>(jpeg *z@<esi>, int scan@<edi>)
{
  int marker; // ecx

  z->marker = -1;
  if ( get_marker(j: z) != 0xD8 )
  {
    failure_reason = "no SOI";
    return 0;
  }
  if ( scan == 1 )
    return 1;
  marker = get_marker(j: z);
  if ( marker == 192 )
    return process_frame_header(z, scan) != 0;
  while ( 1 )
  {
    if ( marker == 193 )
      return process_frame_header(z, scan) != 0;
    if ( !process_marker(z, m: marker) )
      return 0;
    marker = get_marker(j: z);
    if ( marker == 255 )
      break;
LABEL_15:
    if ( marker == 192 )
      return process_frame_header(z, scan) != 0;
  }
  while ( z->s.img_file != nullptr )
  {
    if ( feof(stream: z->s.img_file) != 0 )
    {
      if ( z->s.from_file == 0 )
        goto LABEL_17;
      break;
    }
LABEL_14:
    marker = get_marker(j: z);
    if ( marker != 255 )
      goto LABEL_15;
  }
  if ( z->s.img_buffer < z->s.img_buffer_end )
    goto LABEL_14;
LABEL_17:
  failure_reason = "no SOF";
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404090
// Name: decode_jpeg_image
// Source: json
//------------------------------------------------------------------------------
int __usercall decode_jpeg_image@<eax>(jpeg *j@<eax>)
{
  int marker; // ecx
  unsigned __int8 *img_buffer; // eax
  unsigned __int8 *buffer_start; // edi
  unsigned int v6; // eax
  unsigned __int8 *v7; // eax
  int v8; // ecx
  unsigned __int8 *v9; // eax
  unsigned __int8 v10; // cl
  unsigned __int8 *v11; // eax
  unsigned __int8 v12; // cl

  j->restart_interval = 0;
  if ( !decode_jpeg_header(z: j, scan: 0) )
    return 0;
  marker = get_marker(j);
  if ( marker == 217 )
    return 1;
  do
  {
    if ( marker != 218 )
    {
      if ( process_marker(z: j, m: marker) )
        goto LABEL_27;
      return 0;
    }
    if ( process_scan_header(z: j) == 0 || parse_entropy_coded_data(z: j) == 0 )
      return 0;
    if ( j->marker != 0xFF )
      goto LABEL_27;
    while ( 1 )
    {
      do
      {
        if ( j->s.img_file != nullptr )
        {
          if ( feof(stream: j->s.img_file) == 0 )
            goto LABEL_12;
          if ( j->s.from_file == 0 )
            goto LABEL_27;
        }
        if ( j->s.img_buffer >= j->s.img_buffer_end )
          goto LABEL_27;
LABEL_12:
        img_buffer = j->s.img_buffer;
        if ( img_buffer < j->s.img_buffer_end )
          goto LABEL_18;
      }
      while ( j->s.from_file == 0 );
      buffer_start = j->s.buffer_start;
      v6 = fread(buffer: j->s.buffer_start, elementSize: 1u, count: j->s.buflen, stream: j->s.img_file);
      if ( v6 != 0 )
      {
        j->s.img_buffer = buffer_start;
        j->s.img_buffer_end = &buffer_start[v6];
      }
      else
      {
        v7 = j->s.img_buffer_end - 1;
        j->s.from_file = 0;
        j->s.img_buffer = v7;
        *v7 = 0;
      }
      img_buffer = j->s.img_buffer;
LABEL_18:
      v8 = *img_buffer;
      v9 = img_buffer + 1;
      j->s.img_buffer = v9;
      if ( v8 == 255 )
        break;
      if ( v8 != 0 )
        return 0;
    }
    if ( v9 >= j->s.img_buffer_end )
    {
      if ( j->s.from_file != 0 )
      {
        refill_buffer(s: &j->s);
        v11 = j->s.img_buffer;
        v12 = *v11;
        j->s.img_buffer = v11 + 1;
        j->marker = v12;
      }
      else
      {
        j->marker = 0;
      }
    }
    else
    {
      v10 = *v9;
      j->s.img_buffer = v9 + 1;
      j->marker = v10;
    }
LABEL_27:
    marker = get_marker(j);
  }
  while ( marker != 217 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404230
// Name: resample_row_1
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl resample_row_1(unsigned __int8 *out, unsigned __int8 *in_near)
{
  return in_near;
}

//------------------------------------------------------------------------------
// Address: 0x00404240
// Name: resample_row_v_2
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl resample_row_v_2(
        unsigned __int8 *out,
        unsigned __int8 *in_near,
        unsigned __int8 *in_far,
        int w)
{
  int v4; // ebx
  unsigned __int8 *v5; // ecx

  v4 = w;
  if ( w > 0 )
  {
    v5 = in_far;
    do
    {
      v5[out - in_far] = (3 * v5[in_near - in_far] + *v5 + 2) >> 2;
      ++v5;
      --v4;
    }
    while ( v4 != 0 );
  }
  return out;
}

//------------------------------------------------------------------------------
// Address: 0x00404280
// Name: resample_row_h_2
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl resample_row_h_2(
        unsigned __int8 *out,
        unsigned __int8 *in_near,
        unsigned __int8 *in_far,
        int w)
{
  int v4; // edi
  unsigned __int8 v5; // cl
  int v7; // ecx
  int v8; // edi
  unsigned __int8 *v9; // eax

  v4 = w;
  if ( w == 1 )
  {
    v5 = *in_near;
    out[1] = *in_near;
    *out = v5;
    return out;
  }
  else
  {
    *out = *in_near;
    v7 = 1;
    out[1] = (3 * *in_near + in_near[1] + 2) >> 2;
    if ( w - 1 > 1 )
    {
      do
      {
        v8 = 3 * in_near[v7] + 2;
        out[2 * v7] = (v8 + in_near[v7 - 1]) >> 2;
        out[2 * v7 + 1] = (v8 + in_near[v7 + 1]) >> 2;
        ++v7;
      }
      while ( v7 < w - 1 );
      v4 = w;
    }
    v9 = &in_near[v4 - 1];
    out[2 * v7] = (3 * in_near[v4 - 2] + *v9 + 2) >> 2;
    out[2 * v7 + 1] = *v9;
    return out;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404330
// Name: resample_row_hv_2
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl resample_row_hv_2(
        unsigned __int8 *out,
        unsigned __int8 *in_near,
        unsigned __int8 *in_far,
        int w)
{
  int v4; // esi
  unsigned __int8 *result; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // edx
  unsigned __int8 *v9; // edi
  int i; // ebx
  int v11; // esi
  int v12; // ebx

  v4 = w;
  if ( w == 1 )
  {
    v6 = (3 * *in_near + *in_far + 2) >> 2;
    out[1] = v6;
    *out = v6;
    return out;
  }
  else
  {
    result = out;
    v7 = *in_far + 3 * *in_near;
    *out = (v7 + 2) >> 2;
    v8 = 1;
    if ( w > 1 )
    {
      v9 = in_far + 1;
      for ( i = in_near - in_far; ; i = in_near - in_far )
      {
        v11 = v7;
        v7 = *v9 + 3 * v9[i];
        out[2 * v8 - 1] = (v11 + v7 + 2 * v11 + 8) >> 4;
        v12 = v7 + v11 + 2 * v7 + 8;
        v4 = w;
        out[2 * v8++] = v12 >> 4;
        ++v9;
        if ( v8 >= w )
          break;
      }
    }
    out[2 * v4 - 1] = (v7 + 2) >> 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004043E0
// Name: resample_row_generic
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl resample_row_generic(
        unsigned __int8 *out,
        unsigned __int8 *in_near,
        unsigned __int8 *in_far,
        int w,
        int hs)
{
  int v5; // edx
  unsigned __int8 *v6; // edi
  int i; // ecx

  v5 = 0;
  if ( w > 0 )
  {
    v6 = out;
    do
    {
      for ( i = 0; i < hs; ++i )
        v6[i] = in_near[v5];
      ++v5;
      v6 += hs;
    }
    while ( v5 < w );
  }
  return out;
}

//------------------------------------------------------------------------------
// Address: 0x00404420
// Name: YCbCr_to_RGB_row
// Source: json
//------------------------------------------------------------------------------
void __usercall YCbCr_to_RGB_row(
        unsigned __int8 *out@<eax>,
        int count@<edx>,
        const unsigned __int8 *y,
        const unsigned __int8 *pcb,
        const unsigned __int8 *pcr,
        int step)
{
  const unsigned __int8 *v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // edx
  int v11; // eax
  int v12; // ebx
  int v13; // esi
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  bool v17; // zf
  int v18; // [esp+Ch] [ebp-8h]
  unsigned __int8 *v19; // [esp+10h] [ebp-4h]

  v6 = pcr;
  if ( count > 0 )
  {
    v19 = out + 2;
    v7 = y - pcr;
    v8 = pcb - pcr;
    v18 = count;
    while ( 1 )
    {
      v9 = v6[v7];
      v10 = *v6 - 128;
      v11 = -46802 * v10;
      v12 = v6[v8] - 128;
      v13 = (v9 << 16) + 0x8000;
      v14 = (v13 + 91881 * v10) >> 16;
      v15 = (v13 + v11 - 22554 * v12) >> 16;
      v16 = (v13 + 116130 * v12) >> 16;
      if ( (unsigned int)v14 > 0xFF )
        LOBYTE(v14) = (v14 < 0) - 1;
      if ( (unsigned int)v15 > 0xFF )
        LOBYTE(v15) = (v15 < 0) - 1;
      if ( (unsigned int)v16 > 0xFF )
        LOBYTE(v16) = (v16 < 0) - 1;
      *(v19 - 2) = v14;
      *(v19 - 1) = v15;
      *v19 = v16;
      v19[1] = -1;
      ++v6;
      v17 = v18-- == 1;
      v19 += step;
      if ( v17 )
        break;
      v7 = y - pcr;
      v8 = pcb - pcr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404510
// Name: cleanup_jpeg
// Source: json
//------------------------------------------------------------------------------
void __cdecl cleanup_jpeg(jpeg *j)
{
  int v1; // edi
  void **p_linebuf; // esi

  v1 = 0;
  if ( j->s.img_n > 0 )
  {
    p_linebuf = (void **)&j->img_comp[0].linebuf;
    do
    {
      if ( *(p_linebuf - 2) != nullptr )
      {
        free(pMem: *(p_linebuf - 1));
        *(p_linebuf - 2) = nullptr;
      }
      if ( *p_linebuf != nullptr )
      {
        free(pMem: *p_linebuf);
        *p_linebuf = nullptr;
      }
      ++v1;
      p_linebuf += 14;
    }
    while ( v1 < j->s.img_n );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404570
// Name: load_jpeg_image
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall load_jpeg_image@<eax>(
        unsigned int req_comp@<eax>,
        jpeg *z,
        int *out_x,
        int *out_y,
        int *comp)
{
  int img_n; // eax
  int *p_h; // edi
  int *p_vs; // esi
  void *v10; // eax
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // edi
  unsigned int img_x; // eax
  int *v16; // edx
  int v17; // eax
  unsigned int img_y; // esi
  unsigned __int8 *v19; // edi
  unsigned int v20; // eax
  int v21; // esi
  unsigned __int8 *v22; // edi
  int *p_ystep; // esi
  int v24; // ecx
  int v25; // eax
  unsigned __int8 *v26; // eax
  int v27; // eax
  int v28; // ecx
  int *v29; // edx
  int v30; // eax
  unsigned int v31; // edx
  unsigned __int8 *v32; // eax
  unsigned __int8 v33; // cl
  unsigned int v34; // eax
  unsigned __int8 *v35; // esi
  stbi_resample res_comp[4]; // [esp+8h] [ebp-A8h] BYREF
  unsigned __int8 *coutput[4]; // [esp+88h] [ebp-28h]
  unsigned __int8 *output; // [esp+98h] [ebp-18h]
  unsigned int j; // [esp+9Ch] [ebp-14h]
  int decode_n; // [esp+A0h] [ebp-10h]
  int n; // [esp+A4h] [ebp-Ch]
  int k; // [esp+A8h] [ebp-8h]
  int *i; // [esp+ACh] [ebp-4h]

  if ( req_comp > 4 )
  {
    failure_reason = "bad req_comp";
    return nullptr;
  }
  else
  {
    z->s.img_n = 0;
    if ( decode_jpeg_image(j: z) == 0 )
    {
      cleanup_jpeg(j: z);
      return nullptr;
    }
    if ( req_comp != 0 )
      n = req_comp;
    else
      n = z->s.img_n;
    img_n = z->s.img_n;
    if ( img_n != 3 || (decode_n = 1, n >= 3) )
      decode_n = img_n;
    k = 0;
    if ( decode_n > 0 )
    {
      p_h = &z->img_comp[0].h;
      p_vs = &res_comp[0].vs;
      for ( i = &z->img_comp[0].h; ; p_h = i )
      {
        v10 = operator new(nSize: z->s.img_x + 3);
        p_h[12] = (int)v10;
        if ( v10 == nullptr )
          goto LABEL_27;
        v11 = z->img_h_max / *p_h;
        p_vs[3] = 0;
        v12 = v11;
        v13 = z->img_v_max / p_h[1];
        *(p_vs - 1) = v12;
        v14 = v13;
        img_x = z->s.img_x;
        p_vs[2] = v14 >> 1;
        v16 = i;
        *p_vs = v14;
        p_vs[1] = (v12 + img_x - 1) / v12;
        v17 = v16[10];
        *(p_vs - 2) = v17;
        *(p_vs - 3) = v17;
        if ( v12 == 1 )
        {
          if ( v14 == 1 )
          {
            *(p_vs - 4) = (int)resample_row_1;
            goto LABEL_25;
          }
          if ( v14 == 2 )
          {
            *(p_vs - 4) = (int)resample_row_v_2;
            goto LABEL_25;
          }
        }
        if ( v12 != 2 )
          goto LABEL_24;
        if ( v14 == 1 )
        {
          *(p_vs - 4) = (int)resample_row_h_2;
          goto LABEL_25;
        }
        if ( v14 == 2 )
          *(p_vs - 4) = (int)resample_row_hv_2;
        else
LABEL_24:
          *(p_vs - 4) = (int)resample_row_generic;
LABEL_25:
        i += 14;
        p_vs += 8;
        if ( ++k >= decode_n )
          break;
      }
    }
    img_y = z->s.img_y;
    v19 = (unsigned __int8 *)operator new(nSize: n * img_y * z->s.img_x + 1);
    output = v19;
    if ( v19 != nullptr )
    {
      v20 = 0;
      j = 0;
      if ( img_y != 0 )
      {
        do
        {
          v21 = n;
          v22 = &output[n * v20 * z->s.img_x];
          k = 0;
          if ( decode_n > 0 )
          {
            i = &z->img_comp[0].y;
            p_ystep = &res_comp[0].ystep;
            do
            {
              if ( *p_ystep < *(p_ystep - 2) >> 1 )
              {
                v24 = *(p_ystep - 4);
                v25 = *(p_ystep - 5);
              }
              else
              {
                v24 = *(p_ystep - 5);
                v25 = *(p_ystep - 4);
              }
              v26 = (unsigned __int8 *)((int (__cdecl *)(int, int, int, _DWORD, _DWORD))*(p_ystep - 6))(
                                         a1: i[5],
                                         a2: v25,
                                         a3: v24,
                                         a4: *(p_ystep - 1),
                                         a5: *(p_ystep - 3));
              coutput[k] = v26;
              v27 = *p_ystep + 1;
              *p_ystep = v27;
              if ( v27 >= *(p_ystep - 2) )
              {
                v28 = ++p_ystep[1];
                v29 = i;
                v30 = *(p_ystep - 4);
                *p_ystep = 0;
                *(p_ystep - 5) = v30;
                if ( v28 < *v29 )
                  *(p_ystep - 4) = v30 + v29[1];
              }
              i += 14;
              p_ystep += 8;
              ++k;
            }
            while ( k < decode_n );
            v21 = n;
          }
          if ( v21 < 3 )
          {
            v34 = 0;
            if ( v21 == 1 )
            {
              if ( z->s.img_x != 0 )
              {
                v35 = (unsigned __int8 *)(coutput[0] - v22);
                do
                {
                  *v22 = v22[(_DWORD)v35];
                  ++v34;
                  ++v22;
                }
                while ( v34 < z->s.img_x );
              }
            }
            else if ( z->s.img_x != 0 )
            {
              do
              {
                *v22 = coutput[0][v34];
                v22[1] = -1;
                ++v34;
                v22 += 2;
              }
              while ( v34 < z->s.img_x );
            }
          }
          else if ( z->s.img_n == 3 )
          {
            YCbCr_to_RGB_row(out: v22, count: z->s.img_x, y: coutput[0], pcb: coutput[1], pcr: coutput[2], step: v21);
          }
          else
          {
            v31 = 0;
            if ( z->s.img_x != 0 )
            {
              v32 = v22 + 1;
              do
              {
                v33 = coutput[0][v31];
                v32[1] = v33;
                *v32 = v33;
                *(v32 - 1) = v33;
                v32[2] = -1;
                ++v31;
                v32 += v21;
              }
              while ( v31 < z->s.img_x );
            }
          }
          v20 = j + 1;
          j = v20;
        }
        while ( v20 < z->s.img_y );
        v19 = output;
      }
      cleanup_jpeg(j: z);
      *out_x = z->s.img_x;
      *out_y = z->s.img_y;
      if ( comp != nullptr )
        *comp = z->s.img_n;
      return v19;
    }
    else
    {
LABEL_27:
      cleanup_jpeg(j: z);
      failure_reason = "outofmem";
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404880
// Name: unsigned char __near * stbi_jpeg_load_from_file(struct _iobuf __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl stbi_jpeg_load_from_file(_iobuf *f, int *x, int *y, int *comp, unsigned int req_comp)
{
  jpeg z; // [esp+0h] [ebp-3748h] BYREF

  z.s.img_file = f;
  z.s.img_buffer_end = (unsigned __int8 *)&z.s.from_file;
  z.s.img_buffer = (unsigned __int8 *)&z.s.from_file;
  z.s.buflen = 128;
  z.s.from_file = 1;
  return load_jpeg_image(req_comp, &z, out_x: x, out_y: y, comp);
}

//------------------------------------------------------------------------------
// Address: 0x004048E0
// Name: int stbi_jpeg_test_file(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl stbi_jpeg_test_file(_iobuf *f)
{
  int v1; // ebx
  int v2; // edi
  jpeg j; // [esp+Ch] [ebp-3748h] BYREF

  v1 = ftell(stream: f);
  j.s.img_buffer_end = (unsigned __int8 *)&j.s.from_file;
  v2 = 1;
  j.s.img_file = f;
  j.s.buflen = 128;
  j.s.img_buffer = (unsigned __int8 *)&j.s.from_file;
  j.s.from_file = 1;
  j.marker = -1;
  if ( get_marker(&j) != 0xD8 )
  {
    failure_reason = "no SOI";
    v2 = 0;
  }
  fseek(stream: f, offset: v1, whence: 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00404970
// Name: zbuild_huffman
// Source: json
//------------------------------------------------------------------------------
int __cdecl zbuild_huffman(zhuffman *z, unsigned __int8 *sizelist, int num)
{
  int j; // eax
  int v4; // eax
  unsigned __int16 *v5; // ecx
  int v6; // ebx
  int v7; // edi
  int v8; // edx
  int *v9; // eax
  int v10; // esi
  int v11; // ecx
  int *v12; // esi
  int v13; // ecx
  int v14; // ebx
  int v15; // edi
  int v16; // esi
  int v17; // esi
  int v18; // edx
  int next_code[16]; // [esp+Ch] [ebp-94h] BYREF
  int sizes[17]; // [esp+4Ch] [ebp-54h] BYREF
  unsigned __int16 *v22; // [esp+90h] [ebp-10h]
  int *v23; // [esp+94h] [ebp-Ch]
  int *v24; // [esp+98h] [ebp-8h]
  int i; // [esp+9Ch] [ebp-4h]

  i = 0;
  memset(dst: (unsigned __int8 *)sizes, value: 0, count: sizeof(sizes));
  memset(dst: (unsigned __int8 *)z, value: 0xFFu, count: 0x400u);
  for ( j = 0; j < num; ++j )
    ++sizes[sizelist[j]];
  v4 = 0;
  v5 = &z->firstsymbol[1];
  sizes[0] = 0;
  v6 = 1;
  v7 = 15;
  v23 = &z->maxcode[1];
  v22 = &z->firstsymbol[1];
  do
  {
    *v5 = i;
    v8 = sizes[v6];
    next_code[v6] = v4;
    *(v5 - 50) = v4;
    v9 = (int *)(v8 + v4);
    if ( v8 != 0 && (int)v9 - 1 >= 1 << v6 )
    {
      failure_reason = "bad codelengths";
      return 0;
    }
    i += v8;
    v10 = (_DWORD)v9 << v7;
    v24 = v9;
    --v7;
    v4 = 2 * (_DWORD)v9;
    v11 = v10;
    v12 = v23;
    *v23 = v11;
    v5 = v22 + 1;
    ++v6;
    ++v22;
    v23 = v12 + 1;
  }
  while ( v7 > 0 );
  v13 = 0;
  z->maxcode[16] = 0x10000;
  for ( i = 0; v13 < num; i = v13 )
  {
    v14 = sizelist[v13];
    if ( sizelist[v13] != 0 )
    {
      v15 = next_code[v14];
      v16 = z->firstsymbol[v14];
      v24 = &next_code[v14];
      v17 = v15 + v16 - z->firstcode[v14];
      z->size[v17] = v14;
      z->value[v17] = v13;
      if ( v14 <= 9 )
      {
        v18 = (((unsigned __int8)((16
                                 * ((4 * ((2 * (v15 & 0x55)) & 0x33 | (v15 >> 1) & 0x11)) & 0xF
                                  | (((2 * (v15 & 0x5555)) | (v15 >> 1) & 0x5555) >> 2) & 3))
                                | (((4 * ((2 * (v15 & 0x5555)) & 0x3333 | (v15 >> 1) & 0x1111))
                                  | (((2 * (v15 & 0x5555)) | (v15 >> 1) & 0x5555) >> 2) & 0x3333) >> 4)
                                & 0xF) << 8)
             | (unsigned __int8)((unsigned __int16)((16
                                                   * ((4 * ((2 * (v15 & 0x5555)) & 0x3333 | (v15 >> 1) & 0x1111))
                                                    & 0xF0F
                                                    | (((2 * (v15 & 0x5555)) | (v15 >> 1) & 0x5555) >> 2) & 0x303))
                                                  | (((4 * ((2 * (v15 & 0x5555)) & 0x3333 | (v15 >> 1) & 0x1111))
                                                    | (((2 * (v15 & 0x5555)) | (v15 >> 1) & 0x5555) >> 2) & 0x3333) >> 4)
                                                  & 0xF0F) >> 8)) >> (16 - v14);
        if ( (unsigned int)v18 < 0x200 )
        {
          do
          {
            z->fast[v18] = v17;
            v18 += 1 << v14;
          }
          while ( v18 < 512 );
        }
        v13 = i;
      }
      *v24 = v15 + 1;
    }
    ++v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404B60
// Name: fill_bits
// Source: json
//------------------------------------------------------------------------------
void __fastcall fill_bits(int a1, zbuf *z)
{
  int num_bits; // ecx
  unsigned __int8 *zbuffer_end; // ebx
  unsigned int code_buffer; // edi
  unsigned __int8 *zbuffer; // esi
  int v6; // eax
  int v7; // eax

  num_bits = z->num_bits;
  zbuffer_end = z->zbuffer_end;
  code_buffer = z->code_buffer;
  do
  {
    zbuffer = z->zbuffer;
    if ( z->zbuffer < zbuffer_end )
    {
      v6 = *zbuffer;
      z->zbuffer = zbuffer + 1;
    }
    else
    {
      v6 = 0;
    }
    v7 = v6 << num_bits;
    num_bits += 8;
    z->num_bits = num_bits;
    code_buffer |= v7;
    z->code_buffer = code_buffer;
  }
  while ( num_bits <= 24 );
}

//------------------------------------------------------------------------------
// Address: 0x00404BA0
// Name: expand
// Source: json
//------------------------------------------------------------------------------
int __usercall expand@<eax>(zbuf *z@<edi>, int n@<ecx>)
{
  int result; // eax
  char *zout_start; // eax
  char *v4; // ebx
  signed int v5; // esi
  char *i; // ecx

  if ( z->z_expandable != 0 )
  {
    zout_start = z->zout_start;
    v4 = (char *)(z->zout - zout_start);
    v5 = z->zout_end - zout_start;
    for ( i = &v4[n]; (int)i > v5; v5 *= 2 )
      ;
    result = (int)_realloc_crt(ptr: zout_start, size: v5);
    if ( result != 0 )
    {
      z->zout_start = (char *)result;
      z->zout_end = (char *)(v5 + result);
      z->zout = &v4[result];
      return 1;
    }
    else
    {
      failure_reason = "outofmem";
    }
  }
  else
  {
    failure_reason = "output buffer limit";
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404C10
// Name: parse_huffman_block
// Source: json
//------------------------------------------------------------------------------
int __usercall parse_huffman_block@<eax>(zbuf *a@<eax>)
{
  int num_bits; // ecx
  unsigned __int8 *zbuffer_end; // ebx
  unsigned int code_buffer; // esi
  unsigned __int8 *zbuffer; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // ebx
  signed int v11; // ecx
  int v12; // ecx
  int v13; // edx
  int *v14; // ecx
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  char *zout_end; // esi
  char *zout; // eax
  char *zout_start; // ecx
  signed int v21; // esi
  int i; // eax
  char *v23; // eax
  int v24; // edx
  int v25; // ebx
  unsigned int v26; // ebx
  unsigned __int8 *v27; // edx
  int v28; // eax
  int v29; // eax
  unsigned int v30; // edx
  int v31; // ecx
  unsigned __int8 *v32; // esi
  unsigned int v33; // ebx
  unsigned __int8 *v34; // edx
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  signed int v40; // ecx
  int v41; // ecx
  int v42; // edx
  int *v43; // ecx
  int v44; // eax
  int v45; // edx
  int v46; // ecx
  unsigned int v47; // ebx
  int v48; // esi
  unsigned __int8 *v49; // edx
  int v50; // eax
  int v51; // eax
  unsigned int v52; // edx
  char v53; // cl
  int v54; // esi
  char *j; // eax
  int dist; // [esp+Ch] [ebp-8h]
  int dista; // [esp+Ch] [ebp-8h]
  int distb; // [esp+Ch] [ebp-8h]
  int len; // [esp+10h] [ebp-4h]

  while ( 1 )
  {
    while ( 1 )
    {
      num_bits = a->num_bits;
      if ( num_bits < 16 )
      {
        zbuffer_end = a->zbuffer_end;
        code_buffer = a->code_buffer;
        do
        {
          zbuffer = a->zbuffer;
          if ( a->zbuffer < zbuffer_end )
          {
            v6 = *zbuffer;
            a->zbuffer = zbuffer + 1;
          }
          else
          {
            v6 = 0;
          }
          v7 = v6 << num_bits;
          num_bits += 8;
          a->num_bits = num_bits;
          code_buffer |= v7;
          a->code_buffer = code_buffer;
        }
        while ( num_bits <= 24 );
      }
      v8 = a->z_length.fast[a->code_buffer & 0x1FF];
      if ( v8 == 0xFFFF )
      {
        v11 = (2 * (a->code_buffer & 0x5555)) | ((int)a->code_buffer >> 1) & 0x5555;
        v12 = (4 * (v11 & 0x3333)) | (v11 >> 2) & 0x3333;
        v13 = ((unsigned __int8)((16 * (v12 & 0xF)) | (v12 >> 4) & 0xF) << 8)
            | (unsigned __int8)((unsigned __int16)((16 * (v12 & 0xF0F)) | (v12 >> 4) & 0xF0F) >> 8);
        v14 = &a->z_length.maxcode[10];
        v15 = 10;
        if ( v13 >= a->z_length.maxcode[10] )
        {
          do
          {
            ++v14;
            ++v15;
          }
          while ( v13 >= *v14 );
          if ( v15 == 16 )
          {
LABEL_60:
            failure_reason = "bad huffman code";
            return 0;
          }
        }
        v16 = a->z_length.firstsymbol[v15] + (v13 >> (16 - v15)) - a->z_length.firstcode[v15];
        a->code_buffer >>= v15;
        a->num_bits -= v15;
        v10 = a->z_length.value[v16];
      }
      else
      {
        v9 = a->z_length.size[v8];
        a->code_buffer >>= v9;
        a->num_bits -= v9;
        v10 = a->z_length.value[v8];
      }
      v17 = a->num_bits;
      if ( v10 >= 256 )
        break;
      zout_end = a->zout_end;
      zout = a->zout;
      if ( zout >= zout_end )
      {
        if ( a->z_expandable == 0 )
        {
          failure_reason = "output buffer limit";
          return 0;
        }
        zout_start = a->zout_start;
        dist = zout - zout_start;
        v21 = zout_end - zout_start;
        for ( i = zout - zout_start + 1; i > v21; v21 *= 2 )
          ;
        v23 = (char *)_realloc_crt(ptr: zout_start, size: v21);
        if ( v23 == nullptr )
        {
          failure_reason = "outofmem";
          return 0;
        }
        a->zout_start = v23;
        a->zout = &v23[dist];
        a->zout_end = &v23[v21];
      }
      *a->zout++ = v10;
    }
    if ( v10 == 256 )
      return 1;
    v24 = *((_DWORD *)&vec2_invalid.x + v10);
    v25 = *((_DWORD *)&g_bindings[7].pKeyString + v10);
    len = v24;
    dista = v25;
    if ( v25 != 0 )
    {
      if ( v17 < v25 )
      {
        v26 = a->code_buffer;
        do
        {
          v27 = a->zbuffer;
          if ( a->zbuffer < a->zbuffer_end )
          {
            v28 = *v27;
            a->zbuffer = v27 + 1;
          }
          else
          {
            v28 = 0;
          }
          v29 = v28 << v17;
          v17 += 8;
          a->num_bits = v17;
          v26 |= v29;
          a->code_buffer = v26;
        }
        while ( v17 <= 24 );
      }
      v30 = a->code_buffer;
      a->num_bits -= dista;
      len += v30 & ((1 << dista) - 1);
      a->code_buffer = v30 >> dista;
      v24 = len;
    }
    v31 = a->num_bits;
    if ( v31 < 16 )
    {
      v32 = a->zbuffer_end;
      v33 = a->code_buffer;
      do
      {
        v34 = a->zbuffer;
        if ( a->zbuffer < v32 )
        {
          v35 = *v34;
          a->zbuffer = v34 + 1;
        }
        else
        {
          v35 = 0;
        }
        v36 = v35 << v31;
        v31 += 8;
        a->num_bits = v31;
        v33 |= v36;
        a->code_buffer = v33;
      }
      while ( v31 <= 24 );
      v24 = len;
    }
    v37 = a->z_distance.fast[a->code_buffer & 0x1FF];
    if ( v37 == 0xFFFF )
    {
      v40 = (2 * (a->code_buffer & 0x5555)) | ((int)a->code_buffer >> 1) & 0x5555;
      v41 = (4 * (v40 & 0x3333)) | (v40 >> 2) & 0x3333;
      v42 = ((unsigned __int8)((16 * (v41 & 0xF)) | (v41 >> 4) & 0xF) << 8)
          | (unsigned __int8)((unsigned __int16)((16 * (v41 & 0xF0F)) | (v41 >> 4) & 0xF0F) >> 8);
      v43 = &a->z_distance.maxcode[10];
      v44 = 10;
      if ( v42 >= a->z_distance.maxcode[10] )
      {
        do
        {
          ++v43;
          ++v44;
        }
        while ( v42 >= *v43 );
        if ( v44 == 16 )
          goto LABEL_60;
      }
      v45 = a->z_distance.firstsymbol[v44] + (v42 >> (16 - v44)) - a->z_distance.firstcode[v44];
      a->code_buffer >>= v44;
      a->num_bits -= v44;
      v39 = a->z_distance.value[v45];
      v24 = len;
    }
    else
    {
      v38 = a->z_distance.size[v37];
      a->code_buffer >>= v38;
      a->num_bits -= v38;
      v39 = a->z_distance.value[v37];
    }
    v46 = a->num_bits;
    v47 = a->code_buffer;
    distb = dist_base[v39];
    v48 = dist_extra[v39];
    if ( v48 != 0 )
    {
      if ( v46 < v48 )
      {
        do
        {
          v49 = a->zbuffer;
          if ( a->zbuffer < a->zbuffer_end )
          {
            v50 = *v49;
            a->zbuffer = v49 + 1;
          }
          else
          {
            v50 = 0;
          }
          v51 = v50 << v46;
          v46 += 8;
          a->num_bits = v46;
          v47 |= v51;
          a->code_buffer = v47;
        }
        while ( v46 <= 24 );
      }
      v52 = a->code_buffer;
      a->num_bits -= v48;
      v53 = v48;
      v54 = (v52 & ((1 << v48) - 1)) + distb;
      a->code_buffer = v52 >> v53;
      v24 = len;
    }
    else
    {
      v54 = dist_base[v39];
    }
    if ( a->zout - a->zout_start < v54 )
      break;
    if ( &a->zout[v24] > a->zout_end )
    {
      if ( expand(z: a, n: v24) == 0 )
        return 0;
      v24 = len;
    }
    for ( j = &a->zout[-v54]; v24 != 0; --v24 )
      *a->zout++ = *j++;
  }
  failure_reason = "bad dist";
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405020
// Name: compute_huffman_codes
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall compute_huffman_codes@<eax>(zbuf *a@<eax>, int a2@<ecx>)
{
  unsigned int code_buffer; // eax
  int v4; // edi
  bool v5; // cc
  unsigned int v6; // eax
  unsigned int v7; // eax
  int num_bits; // ecx
  int v9; // edx
  unsigned int v10; // eax
  int v11; // ebx
  unsigned int v12; // edx
  unsigned __int8 *zbuffer; // edi
  int v14; // eax
  int v15; // eax
  char v16; // dl
  int v17; // edi
  int v18; // eax
  int v19; // ebx
  int v20; // edi
  unsigned __int8 *zbuffer_end; // edx
  unsigned __int8 *v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // edx
  int v28; // eax
  int v29; // ecx
  int v30; // ecx
  unsigned int v31; // eax
  int v32; // ecx
  int v33; // ecx
  unsigned __int8 *v34; // ebx
  int v35; // eax
  int v36; // eax
  int v37; // eax
  unsigned __int8 *v38; // eax
  int v39; // ecx
  unsigned __int8 *v40; // ebx
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // ecx
  unsigned __int8 *v46; // ebx
  int v47; // eax
  int v48; // eax
  int v49; // eax
  unsigned __int8 v51; // [esp-8h] [ebp-9ECh]
  unsigned int v52; // [esp-4h] [ebp-9E8h]
  zhuffman z_codelength; // [esp+Ch] [ebp-9D8h] BYREF
  unsigned __int8 lencodes[456]; // [esp+7F0h] [ebp-1F4h] BYREF
  unsigned __int8 codelength_sizes[20]; // [esp+9B8h] [ebp-2Ch] BYREF
  int v56; // [esp+9CCh] [ebp-18h]
  int v57; // [esp+9D0h] [ebp-14h]
  int hdist; // [esp+9D4h] [ebp-10h]
  int hlit; // [esp+9D8h] [ebp-Ch]
  int c; // [esp+9DCh] [ebp-8h]
  int n; // [esp+9E0h] [ebp-4h]

  if ( a->num_bits < 5 )
    fill_bits(a1: a2, z: a);
  code_buffer = a->code_buffer;
  a->num_bits -= 5;
  v4 = (code_buffer & 0x1F) + 257;
  v5 = a->num_bits < 5;
  a->code_buffer = code_buffer >> 5;
  hlit = v4;
  if ( v5 )
    fill_bits(a1: a2, z: a);
  v6 = a->code_buffer;
  a->num_bits -= 5;
  v5 = a->num_bits < 4;
  a->code_buffer = v6 >> 5;
  hdist = (v6 & 0x1F) + 1;
  if ( v5 )
    fill_bits(a1: (v6 & 0x1F) + 1, z: a);
  v7 = a->code_buffer;
  a->num_bits -= 4;
  num_bits = a->num_bits;
  v9 = (v7 & 0xF) + 4;
  v10 = v7 >> 4;
  v11 = 0;
  a->code_buffer = v10;
  c = v9;
  memset(codelength_sizes, 0, 19);
  if ( v9 != 0 )
  {
    do
    {
      if ( num_bits < 3 )
      {
        v12 = v10;
        do
        {
          zbuffer = a->zbuffer;
          if ( a->zbuffer < a->zbuffer_end )
          {
            v14 = *zbuffer;
            a->zbuffer = zbuffer + 1;
          }
          else
          {
            v14 = 0;
          }
          v15 = v14 << num_bits;
          num_bits += 8;
          a->num_bits = num_bits;
          v12 |= v15;
          v10 = v12;
          a->code_buffer = v12;
        }
        while ( num_bits <= 24 );
      }
      v16 = v10;
      v10 >>= 3;
      num_bits -= 3;
      a->code_buffer = v10;
      a->num_bits = num_bits;
      v17 = length_dezigzag[v11++];
      codelength_sizes[v17] = v16 & 7;
    }
    while ( v11 < c );
    v4 = hlit;
  }
  if ( zbuild_huffman(z: &z_codelength, sizelist: codelength_sizes, num: 19) == 0 )
    return false;
  v18 = v4 + hdist;
  n = 0;
  v56 = v4 + hdist;
  if ( v4 + hdist <= 0 )
    goto LABEL_61;
  v19 = a->num_bits;
  v20 = a->code_buffer;
  do
  {
    if ( v19 < 16 )
    {
      zbuffer_end = a->zbuffer_end;
      do
      {
        v22 = a->zbuffer;
        if ( a->zbuffer < zbuffer_end )
        {
          v23 = *v22;
          a->zbuffer = v22 + 1;
        }
        else
        {
          v23 = 0;
        }
        v24 = v23 << v19;
        v19 += 8;
        a->num_bits = v19;
        v20 |= v24;
        a->code_buffer = v20;
      }
      while ( v19 <= 24 );
    }
    v25 = z_codelength.fast[v20 & 0x1FF];
    if ( v25 == 0xFFFF )
    {
      v28 = ((unsigned __int8)((16
                              * ((4 * ((2 * (v20 & 0x55)) & 0x33 | (v20 >> 1) & 0x11)) & 0xF
                               | (((2 * (v20 & 0x5555)) | (v20 >> 1) & 0x5555) >> 2) & 3))
                             | (((4 * ((2 * (v20 & 0x5555)) & 0x3333 | (v20 >> 1) & 0x1111))
                               | (((2 * (v20 & 0x5555)) | (v20 >> 1) & 0x5555) >> 2) & 0x3333) >> 4)
                             & 0xF) << 8)
          | (unsigned __int8)((unsigned __int16)((16
                                                * ((4 * ((2 * (v20 & 0x5555)) & 0x3333 | (v20 >> 1) & 0x1111)) & 0xF0F
                                                 | (((2 * (v20 & 0x5555)) | (v20 >> 1) & 0x5555) >> 2) & 0x303))
                                               | (((4 * ((2 * (v20 & 0x5555)) & 0x3333 | (v20 >> 1) & 0x1111))
                                                 | (((2 * (v20 & 0x5555)) | (v20 >> 1) & 0x5555) >> 2) & 0x3333) >> 4)
                                               & 0xF0F) >> 8);
      v29 = 10;
      c = 10;
      if ( v28 >= z_codelength.maxcode[10] )
      {
        do
          ++v29;
        while ( v28 >= z_codelength.maxcode[v29] );
        c = v29;
        if ( v29 == 16 )
        {
          v30 = n;
          lencodes[n] = -1;
          n = v30 + 1;
          goto LABEL_59;
        }
      }
      v20 = (unsigned int)v20 >> v29;
      v19 -= v29;
      v57 = v20;
      v25 = z_codelength.firstsymbol[c] + (v28 >> (16 - c)) - z_codelength.firstcode[c];
      v27 = v20;
    }
    else
    {
      v26 = z_codelength.size[v25];
      v20 = (unsigned int)v20 >> v26;
      v19 -= v26;
      v27 = v20;
    }
    v31 = z_codelength.value[v25];
    a->num_bits = v19;
    a->code_buffer = v20;
    if ( v31 >= 0x10 )
    {
      if ( v31 == 16 )
      {
        if ( v19 < 2 )
        {
          v33 = v19;
          v20 = v27;
          do
          {
            v34 = a->zbuffer;
            if ( a->zbuffer < a->zbuffer_end )
            {
              v35 = *v34;
              a->zbuffer = v34 + 1;
            }
            else
            {
              v35 = 0;
            }
            v36 = v35 << v33;
            v33 += 8;
            v19 = v33;
            a->num_bits = v33;
            v20 |= v36;
            a->code_buffer = v20;
          }
          while ( v33 <= 24 );
        }
        v37 = v20 & 3;
        v20 = (unsigned int)v20 >> 2;
        v19 -= 2;
        v52 = v37 + 3;
        c = v37 + 3;
        v51 = *((_BYTE *)&z_codelength.value[287] + n + 1);
        v38 = &lencodes[n];
      }
      else
      {
        if ( v31 == 17 )
        {
          if ( v19 < 3 )
          {
            v39 = v19;
            v20 = v27;
            do
            {
              v40 = a->zbuffer;
              if ( a->zbuffer < a->zbuffer_end )
              {
                v41 = *v40;
                a->zbuffer = v40 + 1;
              }
              else
              {
                v41 = 0;
              }
              v42 = v41 << v39;
              v39 += 8;
              v19 = v39;
              a->num_bits = v39;
              v20 |= v42;
              a->code_buffer = v20;
            }
            while ( v39 <= 24 );
          }
          v43 = v20 & 7;
          v20 = (unsigned int)v20 >> 3;
          v19 -= 3;
          v44 = v43 + 3;
        }
        else
        {
          if ( v19 < 7 )
          {
            v45 = v19;
            v20 = v27;
            do
            {
              v46 = a->zbuffer;
              if ( a->zbuffer < a->zbuffer_end )
              {
                v47 = *v46;
                a->zbuffer = v46 + 1;
              }
              else
              {
                v47 = 0;
              }
              v48 = v47 << v45;
              v45 += 8;
              v19 = v45;
              a->num_bits = v45;
              v20 |= v48;
              a->code_buffer = v20;
            }
            while ( v45 <= 24 );
          }
          v49 = v20 & 0x7F;
          v20 = (unsigned int)v20 >> 7;
          v19 -= 7;
          v44 = v49 + 11;
        }
        v52 = v44;
        c = v44;
        v38 = &lencodes[n];
        v51 = 0;
      }
      a->code_buffer = v20;
      a->num_bits = v19;
      memset(dst: v38, value: v51, count: v52);
      n += c;
    }
    else
    {
      v32 = n;
      lencodes[n] = v31;
      n = v32 + 1;
    }
LABEL_59:
    v18 = v56;
  }
  while ( n < v56 );
  v4 = hlit;
LABEL_61:
  if ( n != v18 )
  {
    failure_reason = "bad codelengths";
    return false;
  }
  if ( zbuild_huffman(z: &a->z_length, sizelist: lencodes, num: v4) == 0 )
    return false;
  return zbuild_huffman(z: &a->z_distance, sizelist: &lencodes[v4], num: hdist) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004053F0
// Name: parse_uncompressed_block
// Source: json
//------------------------------------------------------------------------------
int __usercall parse_uncompressed_block@<eax>(zbuf *a@<eax>, int a2@<ecx>)
{
  int num_bits; // eax
  int v4; // esi
  int v5; // esi
  int v6; // eax
  unsigned int code_buffer; // ecx
  unsigned __int8 *zbuffer_end; // esi
  unsigned __int8 *zbuffer; // ecx
  unsigned __int8 v10; // dl
  unsigned int v11; // esi
  unsigned __int8 header[4]; // [esp+8h] [ebp-4h]

  num_bits = a->num_bits;
  v4 = num_bits & 7;
  if ( (num_bits & 7) != 0 )
  {
    if ( num_bits < v4 )
      fill_bits(a1: a2, z: a);
    a->code_buffer >>= v4;
    a->num_bits -= v4;
  }
  v5 = a->num_bits;
  v6 = 0;
  if ( v5 <= 0 )
    goto LABEL_9;
  code_buffer = a->code_buffer;
  do
  {
    v5 -= 8;
    header[v6] = a->code_buffer;
    code_buffer >>= 8;
    ++v6;
    a->code_buffer = code_buffer;
  }
  while ( v5 > 0 );
  a->num_bits = v5;
  if ( v6 < 4 )
  {
LABEL_9:
    zbuffer_end = a->zbuffer_end;
    do
    {
      zbuffer = a->zbuffer;
      if ( a->zbuffer < zbuffer_end )
      {
        v10 = *zbuffer;
        a->zbuffer = zbuffer + 1;
      }
      else
      {
        v10 = 0;
      }
      header[v6++] = v10;
    }
    while ( v6 < 4 );
  }
  v11 = header[0] + (header[1] << 8);
  if ( header[2] + (header[3] << 8) != (v11 ^ 0xFFFF) )
  {
    failure_reason = "zlib corrupt";
    return 0;
  }
  if ( &a->zbuffer[v11] <= a->zbuffer_end )
  {
    if ( &a->zout[v11] > a->zout_end && expand(z: a, n: header[0] + (header[1] << 8)) == 0 )
      return 0;
    memcpy(dst: (unsigned __int8 *)a->zout, src: a->zbuffer, count: v11);
    a->zbuffer += v11;
    a->zout += v11;
    return 1;
  }
  else
  {
    failure_reason = "read past buffer";
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004054F0
// Name: parse_zlib_header
// Source: json
//------------------------------------------------------------------------------
int __thiscall parse_zlib_header(zbuf *a)
{
  unsigned __int8 *zbuffer; // edx
  unsigned __int8 *zbuffer_end; // edi
  int v3; // eax
  unsigned __int8 *v4; // edx
  int v5; // ebx

  zbuffer = a->zbuffer;
  zbuffer_end = a->zbuffer_end;
  if ( a->zbuffer < zbuffer_end )
  {
    v3 = *zbuffer;
    a->zbuffer = zbuffer + 1;
  }
  else
  {
    v3 = 0;
  }
  v4 = a->zbuffer;
  if ( a->zbuffer < zbuffer_end )
  {
    v5 = *v4;
    a->zbuffer = v4 + 1;
  }
  else
  {
    v5 = 0;
  }
  if ( (v5 + (v3 << 8)) % 31 != 0 )
  {
    failure_reason = "bad zlib header";
    return 0;
  }
  else if ( (v5 & 0x20) != 0 )
  {
    failure_reason = "no preset dict";
    return 0;
  }
  else if ( (v3 & 0xF) == 8 )
  {
    return 1;
  }
  else
  {
    failure_reason = "bad compression";
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405570
// Name: init_defaults
// Source: json
//------------------------------------------------------------------------------
int init_defaults()
{
  memset(dst: default_length, value: 8u, count: 0x90u);
  memset(dst: &default_length[144], value: 9u, count: 0x70u);
  *(_DWORD *)&default_length[256] = 117901063;
  *(_DWORD *)&default_length[260] = 117901063;
  *(_DWORD *)&default_length[264] = 117901063;
  *(_DWORD *)&default_length[268] = 117901063;
  *(_DWORD *)&default_length[272] = 117901063;
  *(_DWORD *)&default_length[276] = 117901063;
  *(_DWORD *)&default_length[280] = 134744072;
  *(_DWORD *)&default_length[284] = 134744072;
  *(_DWORD *)default_distance = 84215045;
  *(_DWORD *)&default_distance[4] = 84215045;
  *(_DWORD *)&default_distance[8] = 84215045;
  *(_DWORD *)&default_distance[12] = 84215045;
  *(_DWORD *)&default_distance[16] = 84215045;
  *(_DWORD *)&default_distance[20] = 84215045;
  *(_DWORD *)&default_distance[24] = 84215045;
  *(_DWORD *)&default_distance[28] = 84215045;
  return 84215045;
}

//------------------------------------------------------------------------------
// Address: 0x00405600
// Name: parse_zlib
// Source: json
//------------------------------------------------------------------------------
int __usercall parse_zlib@<eax>(zbuf *a@<esi>, int parse_header)
{
  int result; // eax
  int num_bits; // ecx
  unsigned __int8 *zbuffer_end; // ebx
  unsigned int code_buffer; // edi
  unsigned __int8 *zbuffer; // edx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int v10; // ecx
  unsigned int v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned int v13; // edi
  unsigned __int8 *v14; // edx
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int parse_headera; // [esp+Ch] [ebp+8h]

  if ( parse_header == 0 || (result = parse_zlib_header(a)) != 0 )
  {
    a->num_bits = 0;
    a->code_buffer = 0;
    while ( 1 )
    {
      num_bits = a->num_bits;
      if ( num_bits < 1 )
      {
        zbuffer_end = a->zbuffer_end;
        code_buffer = a->code_buffer;
        do
        {
          zbuffer = a->zbuffer;
          if ( a->zbuffer < zbuffer_end )
          {
            v7 = *zbuffer;
            a->zbuffer = zbuffer + 1;
          }
          else
          {
            v7 = 0;
          }
          v8 = v7 << num_bits;
          num_bits += 8;
          a->num_bits = num_bits;
          code_buffer |= v8;
          a->code_buffer = code_buffer;
        }
        while ( num_bits <= 24 );
      }
      v9 = a->code_buffer;
      --a->num_bits;
      parse_headera = v9 & 1;
      v10 = a->num_bits;
      v11 = v9 >> 1;
      a->code_buffer = v11;
      if ( v10 < 2 )
      {
        v12 = a->zbuffer_end;
        v13 = v11;
        do
        {
          v14 = a->zbuffer;
          if ( a->zbuffer < v12 )
          {
            v15 = *v14;
            a->zbuffer = v14 + 1;
          }
          else
          {
            v15 = 0;
          }
          v16 = v15 << v10;
          v10 += 8;
          a->num_bits = v10;
          v13 |= v16;
          a->code_buffer = v13;
        }
        while ( v10 <= 24 );
      }
      v17 = a->code_buffer;
      a->num_bits -= 2;
      v18 = v17 & 3;
      a->code_buffer = v17 >> 2;
      if ( (v17 & 3) != 0 )
      {
        if ( v18 == 3 )
          return 0;
        if ( v18 == 1 )
        {
          if ( default_distance[31] == 0 )
            init_defaults();
          if ( zbuild_huffman(z: &a->z_length, sizelist: default_length, num: 288) == 0 )
            return 0;
          v20 = zbuild_huffman(z: &a->z_distance, sizelist: default_distance, num: 32);
        }
        else
        {
          v20 = compute_huffman_codes(a, a2: v18);
        }
        if ( v20 == 0 )
          return 0;
        v19 = parse_huffman_block(a);
      }
      else
      {
        v19 = parse_uncompressed_block(a, a2: 0);
      }
      if ( v19 == 0 )
        return 0;
      if ( stbi_png_partial != 0 && a->zout - a->zout_start > 0x10000 || parse_headera != 0 )
        return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405750
// Name: char __near * stbi_zlib_decode_malloc_guesssize_headerflag(char const __near *,int,int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl stbi_zlib_decode_malloc_guesssize_headerflag(
        char *buffer,
        int len,
        unsigned int initial_size,
        int *outlen,
        int parse_header)
{
  char *v5; // eax
  bool v6; // zf
  char *result; // eax
  zbuf a; // [esp+4h] [ebp-FE8h] BYREF

  v5 = (char *)operator new(nSize: initial_size);
  if ( v5 == nullptr )
    return nullptr;
  a.zout_start = v5;
  a.zout = v5;
  a.zbuffer = (unsigned __int8 *)buffer;
  a.zout_end = &v5[initial_size];
  a.zbuffer_end = (unsigned __int8 *)&buffer[len];
  a.z_expandable = 1;
  v6 = parse_zlib(&a, parse_header) == 0;
  result = a.zout_start;
  if ( v6 )
  {
    free(pMem: a.zout_start);
    return nullptr;
  }
  if ( outlen != nullptr )
    *outlen = a.zout - a.zout_start;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004057E0
// Name: check_png_header
// Source: json
//------------------------------------------------------------------------------
int __usercall check_png_header@<eax>(stbi *s@<esi>)
{
  int v1; // ebx
  unsigned __int8 *img_buffer; // ecx
  int v3; // eax
  unsigned __int8 *buffer_start; // edi
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ecx

  v1 = 0;
  while ( 1 )
  {
    img_buffer = s->img_buffer;
    if ( img_buffer >= s->img_buffer_end )
    {
      if ( s->from_file != 0 )
      {
        buffer_start = s->buffer_start;
        v5 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
        if ( v5 != 0 )
        {
          s->img_buffer = buffer_start;
          s->img_buffer_end = &buffer_start[v5];
        }
        else
        {
          s->from_file = 0;
          v6 = s->img_buffer_end - 1;
          s->img_buffer = v6;
          *v6 = 0;
        }
        v7 = s->img_buffer;
        v3 = *v7;
        s->img_buffer = v7 + 1;
      }
      else
      {
        v3 = 0;
      }
    }
    else
    {
      v3 = *img_buffer;
      s->img_buffer = img_buffer + 1;
    }
    if ( v3 != png_sig[v1] )
      break;
    if ( ++v1 >= 8 )
      return 1;
  }
  failure_reason = "bad png sig";
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004058A0
// Name: paeth
// Source: json
//------------------------------------------------------------------------------
int __cdecl paeth(int a, int b, int c)
{
  signed int v3; // esi
  signed int v4; // edi
  signed int v5; // eax
  int result; // eax
  bool v7; // cc

  v3 = abs32(b - c);
  v4 = abs32(a - c);
  v5 = abs32(b + a - c - c);
  if ( v3 <= v4 && v3 <= v5 )
    return a;
  v7 = v4 <= v5;
  result = b;
  if ( !v7 )
    return c;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405900
// Name: create_png_image_raw
// Source: json
//------------------------------------------------------------------------------
int __cdecl create_png_image_raw(
        png *a,
        unsigned __int8 *raw,
        unsigned int raw_len,
        int out_n,
        unsigned int x,
        unsigned int y)
{
  int img_n; // esi
  unsigned int v8; // edi
  int result; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // edx
  unsigned int v13; // ecx
  unsigned __int8 *v14; // eax
  int v15; // edx
  unsigned int v16; // kr00_4
  char v17; // al
  char v18; // dl
  bool v19; // zf
  unsigned __int8 *v20; // edx
  unsigned __int8 *v21; // edi
  _BYTE *v22; // eax
  int v23; // eax
  unsigned __int8 *m; // edx
  unsigned __int8 v25; // cl
  int v26; // edx
  unsigned __int8 *v27; // eax
  unsigned __int8 v28; // dl
  int v29; // ecx
  unsigned __int8 *v30; // eax
  unsigned __int8 v31; // dl
  int v32; // ecx
  signed int v33; // ebx
  signed int v34; // eax
  unsigned __int8 v35; // cl
  int v36; // eax
  int n; // ecx
  unsigned __int8 v38; // al
  _BYTE *v39; // eax
  int v40; // eax
  unsigned __int8 *jj; // edx
  unsigned __int8 v42; // cl
  int v43; // edx
  unsigned __int8 *v44; // eax
  unsigned __int8 v45; // dl
  int v46; // ecx
  unsigned __int8 *v47; // eax
  unsigned __int8 v48; // cl
  int v49; // ebx
  int v50; // ecx
  signed int v51; // ebx
  signed int v52; // eax
  unsigned __int8 v53; // al
  bool v54; // cc
  int v55; // eax
  int kk; // ecx
  unsigned __int8 v57; // al
  int v58; // [esp+Ch] [ebp-34h]
  int v59; // [esp+Ch] [ebp-34h]
  int ii; // [esp+Ch] [ebp-34h]
  int v61; // [esp+Ch] [ebp-34h]
  int v62; // [esp+Ch] [ebp-34h]
  int v63; // [esp+Ch] [ebp-34h]
  signed int v64; // [esp+Ch] [ebp-34h]
  int v65; // [esp+Ch] [ebp-34h]
  int v66; // [esp+10h] [ebp-30h]
  int v67; // [esp+10h] [ebp-30h]
  int v68; // [esp+10h] [ebp-30h]
  int v69; // [esp+10h] [ebp-30h]
  int v70; // [esp+14h] [ebp-2Ch]
  int v71; // [esp+14h] [ebp-2Ch]
  int v72; // [esp+14h] [ebp-2Ch]
  int v73; // [esp+14h] [ebp-2Ch]
  signed int v74; // [esp+18h] [ebp-28h]
  int v75; // [esp+18h] [ebp-28h]
  unsigned int v76; // [esp+1Ch] [ebp-24h]
  int v77; // [esp+20h] [ebp-20h]
  int i; // [esp+20h] [ebp-20h]
  int v79; // [esp+20h] [ebp-20h]
  int v80; // [esp+20h] [ebp-20h]
  unsigned __int8 *v81; // [esp+20h] [ebp-20h]
  unsigned __int8 *v82; // [esp+20h] [ebp-20h]
  unsigned __int8 *v83; // [esp+20h] [ebp-20h]
  int v84; // [esp+24h] [ebp-1Ch]
  int v85; // [esp+24h] [ebp-1Ch]
  int v86; // [esp+24h] [ebp-1Ch]
  unsigned __int8 *v87; // [esp+24h] [ebp-1Ch]
  unsigned __int8 *v88; // [esp+24h] [ebp-1Ch]
  unsigned __int8 *v89; // [esp+24h] [ebp-1Ch]
  unsigned __int8 *v90; // [esp+24h] [ebp-1Ch]
  int v91; // [esp+24h] [ebp-1Ch]
  unsigned int j; // [esp+28h] [ebp-18h]
  int filter; // [esp+2Ch] [ebp-14h]
  int filtera; // [esp+2Ch] [ebp-14h]
  int filterb; // [esp+2Ch] [ebp-14h]
  unsigned __int8 *filterc; // [esp+2Ch] [ebp-14h]
  int filterd; // [esp+2Ch] [ebp-14h]
  unsigned __int8 *filtere; // [esp+2Ch] [ebp-14h]
  int filterf; // [esp+2Ch] [ebp-14h]
  unsigned __int8 *v100; // [esp+30h] [ebp-10h]
  unsigned __int8 *k; // [esp+34h] [ebp-Ch]
  int ka; // [esp+34h] [ebp-Ch]
  unsigned __int8 *kb; // [esp+34h] [ebp-Ch]
  int kc; // [esp+34h] [ebp-Ch]
  int kd; // [esp+34h] [ebp-Ch]
  int ke; // [esp+34h] [ebp-Ch]
  int kf; // [esp+34h] [ebp-Ch]
  unsigned int v108; // [esp+38h] [ebp-8h]
  int v109; // [esp+38h] [ebp-8h]
  int v110; // [esp+38h] [ebp-8h]
  int v111; // [esp+38h] [ebp-8h]
  unsigned __int8 *prior; // [esp+3Ch] [ebp-4h]
  unsigned __int8 *rawa; // [esp+4Ch] [ebp+Ch]

  img_n = a->s.img_n;
  v8 = y;
  v76 = x * out_n;
  if ( stbi_png_partial != 0 )
  {
    v8 = 1;
    y = 1;
  }
  result = (int)operator new(nSize: v8 * x * out_n);
  a->out = (unsigned __int8 *)result;
  if ( result == 0 )
  {
    failure_reason = "outofmem";
    return result;
  }
  if ( stbi_png_partial == 0 )
  {
    if ( a->s.img_x == x && a->s.img_y == v8 )
    {
      if ( raw_len != v8 * (x * img_n + 1) )
      {
LABEL_9:
        failure_reason = "not enough pixels";
        return 0;
      }
    }
    else if ( raw_len < v8 * (x * img_n + 1) )
    {
      goto LABEL_9;
    }
  }
  j = 0;
  if ( v8 == 0 )
    return 1;
  while ( 1 )
  {
    v10 = &a->out[v76 * j];
    v11 = raw + 1;
    v12 = &v10[-v76];
    v13 = *(v11 - 1);
    filter = v13;
    if ( v13 > 4 )
      break;
    if ( j == 0 )
    {
      v13 = first_row_filter[v13];
      filter = v13;
    }
    if ( img_n > 0 )
    {
      v108 = v12 - v11;
      v14 = v11;
      v15 = v10 - v11;
      k = v11;
      v77 = img_n;
      do
      {
        v16 = v13;
        v13 = filter;
        switch ( filter )
        {
          case 0:
          case 1:
          case 5:
          case 6:
            LOBYTE(v13) = *v14;
            goto LABEL_22;
          case 2:
            v13 = v108;
            LOBYTE(v13) = *v14 + v14[v108];
            goto LABEL_22;
          case 3:
            v13 = v108;
            LOBYTE(v13) = *v14 + (v14[v108] >> 1);
LABEL_22:
            v14[v15] = v13;
            break;
          case 4:
            v17 = paeth(a: 0, b: k[v108], c: 0);
            v13 = v10 - v11;
            v18 = v17;
            v14 = k;
            k[v10 - v11] = *k + v18;
            v15 = v10 - v11;
            break;
          default:
            v13 = v16;
            break;
        }
        ++v14;
        v19 = v77-- == 1;
        k = v14;
      }
      while ( !v19 );
      v13 = filter;
      v12 = &v10[-v76];
    }
    if ( img_n != out_n )
      v10[img_n] = -1;
    raw = &v11[img_n];
    v20 = &v12[out_n];
    v21 = &v10[out_n];
    rawa = raw;
    prior = v20;
    if ( img_n == out_n )
    {
      switch ( v13 )
      {
        case 0u:
          if ( x != 1 )
          {
            v84 = x - 1;
            do
            {
              if ( img_n > 0 )
              {
                v22 = v21;
                for ( i = img_n; i != 0; --i )
                {
                  *v22 = v22[raw - v21];
                  ++v22;
                }
              }
              raw += img_n;
              v21 += img_n;
              --v84;
            }
            while ( v84 != 0 );
          }
          break;
        case 1u:
          if ( x != 1 )
          {
            filtera = (int)&v21[-img_n];
            v79 = x - 1;
            do
            {
              v23 = 0;
              if ( img_n > 0 )
              {
                for ( m = (unsigned __int8 *)(raw - v21); ; m = (unsigned __int8 *)(raw - v21) )
                {
                  v25 = *(_BYTE *)(filtera + v23) + v21[v23 + (_DWORD)m];
                  v21[v23++] = v25;
                  if ( v23 >= img_n )
                    break;
                }
              }
              filtera += img_n;
              raw += img_n;
              v21 += img_n;
              --v79;
            }
            while ( v79 != 0 );
          }
          break;
        case 2u:
          if ( x != 1 )
          {
            v85 = x - 1;
            do
            {
              if ( img_n > 0 )
              {
                v26 = v20 - raw;
                v27 = raw;
                v109 = v26;
                v80 = img_n;
                while ( 1 )
                {
                  v28 = *v27 + v27[v26];
                  ++v27;
                  v19 = v80-- == 1;
                  v27[v21 - raw - 1] = v28;
                  if ( v19 )
                    break;
                  v26 = v109;
                }
                v20 = prior;
              }
              v20 += img_n;
              raw += img_n;
              v21 += img_n;
              v19 = v85-- == 1;
              prior = v20;
            }
            while ( !v19 );
          }
          break;
        case 3u:
          if ( x != 1 )
          {
            filterb = (int)&v21[-img_n];
            v86 = x - 1;
            do
            {
              v29 = 0;
              ka = 0;
              if ( img_n > 0 )
              {
                v110 = v20 - raw;
                v30 = raw;
                v81 = raw;
                do
                {
                  v31 = *v81 + ((*(unsigned __int8 *)(filterb + v29) + v30[v110]) >> 1);
                  v30 = v81 + 1;
                  v81[v21 - raw] = v31;
                  v29 = ka + 1;
                  ka = v29;
                  ++v81;
                }
                while ( v29 < img_n );
                v20 = prior;
              }
              filterb += img_n;
              v20 += img_n;
              raw += img_n;
              v21 += img_n;
              v19 = v86-- == 1;
              prior = v20;
            }
            while ( !v19 );
          }
          break;
        case 4u:
          if ( x != 1 )
          {
            v87 = &v21[-img_n];
            v58 = x - 1;
            do
            {
              if ( img_n > 0 )
              {
                filterc = v87;
                kb = rawa;
                v82 = (unsigned __int8 *)(prior - v21);
                v66 = img_n;
                do
                {
                  v32 = kb[prior - rawa] + *filterc - filterc[(_DWORD)v82];
                  v70 = filterc[(_DWORD)v82];
                  v33 = abs32(v32 - *filterc);
                  v74 = abs32(*filterc - v70);
                  v34 = abs32(v32 - v70);
                  if ( v33 > v74 || v33 > v34 )
                  {
                    v35 = kb[prior - rawa];
                    if ( v74 > v34 )
                      v35 = v70;
                  }
                  else
                  {
                    v35 = *filterc;
                  }
                  filterc[img_n] = v35 + *kb;
                  v19 = v66-- == 1;
                  ++filterc;
                  ++kb;
                }
                while ( !v19 );
              }
              rawa += img_n;
              v87 += img_n;
              prior += img_n;
              v21 += img_n;
              --v58;
            }
            while ( v58 != 0 );
            raw = rawa;
          }
          break;
        case 5u:
          if ( x != 1 )
          {
            v88 = &v21[-img_n];
            v59 = x - 1;
            do
            {
              v36 = 0;
              for ( kc = 0; v36 < img_n; kc = v36 )
              {
                v21[v36] = raw[v36] + (v88[v36] >> 1);
                v36 = kc + 1;
              }
              v88 += img_n;
              raw += img_n;
              v21 += img_n;
              --v59;
            }
            while ( v59 != 0 );
          }
          break;
        case 6u:
          if ( x != 1 )
          {
            filterd = (int)&v21[-img_n];
            v71 = x - 1;
            do
            {
              for ( n = 0; n < img_n; v21[n - 1] = v38 )
              {
                v38 = *(_BYTE *)(filterd + n) + raw[n];
                ++n;
              }
              filterd += img_n;
              raw += img_n;
              v21 += img_n;
              --v71;
            }
            while ( v71 != 0 );
          }
          break;
        default:
          break;
      }
    }
    else
    {
      switch ( v13 )
      {
        case 0u:
          if ( x != 1 )
          {
            v67 = x - 1;
            do
            {
              if ( img_n > 0 )
              {
                v39 = v21;
                for ( ii = img_n; ii != 0; --ii )
                {
                  *v39 = v39[raw - v21];
                  ++v39;
                }
              }
              v21[img_n] = -1;
              v21 += out_n;
              raw += img_n;
              --v67;
            }
            while ( v67 != 0 );
          }
          break;
        case 1u:
          if ( x != 1 )
          {
            v61 = x - 1;
            v89 = &v21[-out_n];
            do
            {
              v40 = 0;
              if ( img_n > 0 )
              {
                for ( jj = (unsigned __int8 *)(raw - v21); ; jj = (unsigned __int8 *)(raw - v21) )
                {
                  v42 = v89[v40] + v21[v40 + (_DWORD)jj];
                  v21[v40++] = v42;
                  if ( v40 >= img_n )
                    break;
                }
              }
              v89 += out_n;
              v21[img_n] = -1;
              raw += img_n;
              v21 += out_n;
              --v61;
            }
            while ( v61 != 0 );
          }
          break;
        case 2u:
          if ( x != 1 )
          {
            v68 = x - 1;
            do
            {
              if ( img_n > 0 )
              {
                v43 = v20 - raw;
                v44 = raw;
                v111 = v43;
                v62 = img_n;
                while ( 1 )
                {
                  v45 = *v44 + v44[v43];
                  ++v44;
                  v19 = v62-- == 1;
                  v44[v21 - raw - 1] = v45;
                  if ( v19 )
                    break;
                  v43 = v111;
                }
                v20 = prior;
              }
              v21[img_n] = -1;
              v20 += out_n;
              raw += img_n;
              v21 += out_n;
              v19 = v68-- == 1;
              prior = v20;
            }
            while ( !v19 );
          }
          break;
        case 3u:
          if ( x != 1 )
          {
            v90 = &v21[-out_n];
            v63 = x - 1;
            do
            {
              v46 = 0;
              kd = 0;
              if ( img_n > 0 )
              {
                v47 = raw;
                do
                {
                  v48 = *v47 + ((v47[v20 - raw] + v90[v46]) >> 1);
                  (++v47)[v21 - raw - 1] = v48;
                  v46 = kd + 1;
                  kd = v46;
                }
                while ( v46 < img_n );
                v20 = prior;
              }
              v90 += out_n;
              v21[img_n] = -1;
              v20 += out_n;
              raw += img_n;
              v21 += out_n;
              v19 = v63-- == 1;
              prior = v20;
            }
            while ( !v19 );
          }
          break;
        case 4u:
          if ( x != 1 )
          {
            v75 = x - 1;
            ke = (int)&v21[-out_n];
            do
            {
              if ( img_n > 0 )
              {
                filtere = (unsigned __int8 *)ke;
                v100 = rawa;
                v72 = img_n;
                do
                {
                  v49 = filtere[prior - v21];
                  v91 = v100[prior - rawa];
                  v50 = v91 + *filtere - v49;
                  v69 = v49;
                  v51 = abs32(v91 - v49);
                  v64 = abs32(v50 - v91);
                  v52 = abs32(v50 - v69);
                  if ( v51 > v64 || v51 > v52 )
                  {
                    v54 = v64 <= v52;
                    v53 = v100[prior - rawa];
                    if ( !v54 )
                      v53 = v69;
                  }
                  else
                  {
                    v53 = *filtere;
                  }
                  filtere[out_n] = v53 + *v100;
                  v19 = v72-- == 1;
                  ++filtere;
                  ++v100;
                }
                while ( !v19 );
              }
              rawa += img_n;
              ke += out_n;
              prior += out_n;
              v21[img_n] = -1;
              v21 += out_n;
              --v75;
            }
            while ( v75 != 0 );
            raw = rawa;
          }
          break;
        case 5u:
          if ( x != 1 )
          {
            v65 = x - 1;
            v83 = &v21[-out_n];
            do
            {
              v55 = 0;
              for ( kf = 0; v55 < img_n; kf = v55 )
              {
                v21[v55] = raw[v55] + (v83[v55] >> 1);
                v55 = kf + 1;
              }
              v83 += out_n;
              v21[img_n] = -1;
              raw += img_n;
              v21 += out_n;
              --v65;
            }
            while ( v65 != 0 );
          }
          break;
        case 6u:
          if ( x != 1 )
          {
            v73 = x - 1;
            filterf = (int)&v21[-out_n];
            do
            {
              for ( kk = 0; kk < img_n; v21[kk - 1] = v57 )
              {
                v57 = *(_BYTE *)(filterf + kk) + raw[kk];
                ++kk;
              }
              filterf += out_n;
              v21[img_n] = -1;
              raw += img_n;
              v21 += out_n;
              --v73;
            }
            while ( v73 != 0 );
          }
          break;
        default:
          break;
      }
    }
    if ( ++j >= y )
      return 1;
  }
  failure_reason = "invalid filter";
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406160
// Name: create_png_image
// Source: json
//------------------------------------------------------------------------------
int __usercall create_png_image@<eax>(
        png *a@<edi>,
        unsigned int out_n@<esi>,
        unsigned __int8 *raw,
        unsigned int raw_len,
        int interlaced)
{
  int v6; // ecx
  unsigned __int8 *v7; // eax
  int v8; // ecx
  unsigned int img_x; // edx
  unsigned int v10; // eax
  int v11; // ebx
  unsigned int v12; // eax
  int v13; // ecx
  unsigned int v14; // eax
  int v15; // eax
  int v16; // ebx
  int v17; // ebx
  int v18; // eax
  unsigned int v19; // [esp-4h] [ebp-ACh]
  int yspc[7]; // [esp+4h] [ebp-A4h]
  int xspc[7]; // [esp+20h] [ebp-88h]
  int xorig[7]; // [esp+3Ch] [ebp-6Ch]
  int yorig[7]; // [esp+58h] [ebp-50h]
  int save; // [esp+74h] [ebp-34h]
  int v25; // [esp+78h] [ebp-30h]
  int v26; // [esp+7Ch] [ebp-2Ch]
  int v27; // [esp+80h] [ebp-28h]
  int v28; // [esp+84h] [ebp-24h]
  int x; // [esp+88h] [ebp-20h]
  int i; // [esp+8Ch] [ebp-1Ch]
  unsigned int v31; // [esp+90h] [ebp-18h]
  int y; // [esp+94h] [ebp-14h]
  unsigned __int8 *final; // [esp+98h] [ebp-10h]
  int v34; // [esp+9Ch] [ebp-Ch]
  int v35; // [esp+A0h] [ebp-8h]
  int v36; // [esp+A4h] [ebp-4h]
  int interlaceda; // [esp+B8h] [ebp+10h]

  if ( interlaced == 0 )
    return create_png_image_raw(a, raw, raw_len, out_n, x: a->s.img_x, y: a->s.img_y);
  v6 = stbi_png_partial;
  stbi_png_partial = 0;
  v19 = out_n * a->s.img_y * a->s.img_x;
  save = v6;
  v7 = (unsigned __int8 *)operator new(nSize: v19);
  v8 = 0;
  final = v7;
  for ( interlaceda = 0; ; v8 = interlaceda * 4 )
  {
    yorig[2] = 4;
    xspc[2] = 4;
    xspc[3] = 4;
    xorig[1] = 4;
    xorig[3] = 2;
    yorig[4] = 2;
    xspc[4] = 2;
    xspc[5] = 2;
    yspc[3] = 4;
    yspc[4] = 4;
    yspc[5] = 2;
    yspc[6] = 2;
    img_x = a->s.img_x;
    xorig[0] = 0;
    xorig[2] = 0;
    xorig[4] = 0;
    xorig[6] = 0;
    yorig[0] = 0;
    yorig[1] = 0;
    yorig[3] = 0;
    yorig[5] = 0;
    xorig[5] = 1;
    v25 = *(int *)((char *)xorig + v8);
    yspc[0] = 8;
    yspc[1] = 8;
    yspc[2] = 8;
    xspc[0] = 8;
    xspc[1] = 8;
    xspc[6] = 1;
    v10 = (img_x - v25 + *(int *)((char *)xspc + v8) - 1) / *(int *)((char *)xspc + v8);
    v27 = *(int *)((char *)xspc + v8);
    yorig[6] = 1;
    v11 = v10;
    v12 = *(int *)((char *)yspc + v8);
    v13 = *(int *)((char *)yorig + v8);
    v31 = v12;
    v14 = (v12 - v13 + a->s.img_y - 1) / v12;
    x = v11;
    y = v14;
    if ( v11 == 0 || v14 == 0 )
      goto LABEL_16;
    if ( create_png_image_raw(a, raw, raw_len, out_n, x: v11, y: v14) == 0 )
      break;
    if ( y > 0 )
    {
      v36 = yorig[interlaceda];
      v15 = out_n * v11;
      v35 = 0;
      v26 = out_n * v11;
      for ( i = y; i != 0; --i )
      {
        if ( v11 > 0 )
        {
          v16 = v35;
          v34 = 0;
          v28 = x;
          do
          {
            memcpy(dst: &final[out_n * (v34 + v25 + v36 * a->s.img_x)], src: &a->out[v16], count: out_n);
            v34 += v27;
            v16 += out_n;
            --v28;
          }
          while ( v28 != 0 );
          v11 = x;
          v15 = v26;
        }
        v36 += v31;
        v35 += v15;
      }
    }
    free(pMem: a->out);
    v17 = y * (out_n * v11 + 1);
    raw += v17;
    raw_len -= v17;
LABEL_16:
    if ( ++interlaceda >= 7 )
    {
      v18 = save;
      a->out = final;
      stbi_png_partial = v18;
      return 1;
    }
  }
  free(pMem: final);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004063A0
// Name: compute_transparency
// Source: json
//------------------------------------------------------------------------------
int __usercall compute_transparency@<eax>(png *z@<eax>, unsigned __int8 *tc@<esi>, int out_n)
{
  unsigned int v3; // ecx
  unsigned __int8 *out; // eax

  v3 = z->s.img_x * z->s.img_y;
  out = z->out;
  if ( out_n != 2 )
  {
    for ( ; v3 != 0; --v3 )
    {
      if ( *out == *tc && out[1] == tc[1] && out[2] == tc[2] )
        out[3] = 0;
      out += 4;
    }
  }
  else if ( v3 != 0 )
  {
    do
    {
      out[1] = -(*tc != *out);
      out += 2;
      --v3;
    }
    while ( v3 != 0 );
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406410
// Name: expand_palette
// Source: json
//------------------------------------------------------------------------------
int __usercall expand_palette@<eax>(unsigned __int8 *palette@<esi>, png *a, int len)
{
  png *v3; // ebx
  unsigned int v4; // edi
  int result; // eax
  unsigned int v6; // edx
  _BYTE *v7; // ecx
  int v8; // eax
  _BYTE *v9; // ecx
  int v10; // eax
  unsigned __int8 *p; // [esp+8h] [ebp-8h]
  unsigned __int8 *orig; // [esp+Ch] [ebp-4h]

  v3 = a;
  v4 = a->s.img_x * a->s.img_y;
  orig = a->out;
  result = (int)operator new(nSize: len * v4);
  p = (unsigned __int8 *)result;
  if ( result == 0 )
  {
    failure_reason = "outofmem";
    return result;
  }
  v6 = 0;
  if ( len == 3 )
  {
    if ( v4 != 0 )
    {
      v7 = (_BYTE *)(result + 2);
      do
      {
        v8 = 4 * orig[v6];
        *(v7 - 2) = palette[v8];
        *(v7 - 1) = palette[v8 + 1];
        *v7 = palette[v8 + 2];
        ++v6;
        v7 += 3;
      }
      while ( v6 < v4 );
LABEL_11:
      v3 = a;
    }
  }
  else if ( v4 != 0 )
  {
    v9 = (_BYTE *)(result + 2);
    do
    {
      v10 = 4 * orig[v6];
      *(v9 - 2) = palette[v10];
      *(v9 - 1) = palette[v10 + 1];
      *v9 = palette[v10 + 2];
      v9[1] = palette[v10 + 3];
      ++v6;
      v9 += 4;
    }
    while ( v6 < v4 );
    goto LABEL_11;
  }
  free(pMem: v3->out);
  v3->out = p;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004064F0
// Name: stbi_de_iphone
// Source: json
//------------------------------------------------------------------------------
void __fastcall stbi_de_iphone(int a1, png *z)
{
  unsigned int v2; // eax
  unsigned __int8 *out; // ecx
  unsigned int v4; // esi
  unsigned __int8 v5; // dl
  unsigned int v6; // edi
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  unsigned int v9; // esi
  unsigned __int8 v10; // dl

  v2 = z->s.img_x * z->s.img_y;
  out = z->out;
  if ( z->s.img_out_n == 3 )
  {
    if ( v2 != 0 )
    {
      v4 = z->s.img_x * z->s.img_y;
      do
      {
        v5 = *out;
        *out = out[2];
        out[2] = v5;
        out += 3;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( stbi_unpremultiply_on_load != 0 )
  {
    if ( v2 != 0 )
    {
      v6 = z->s.img_x * z->s.img_y;
      do
      {
        v7 = out[3];
        v8 = *out;
        if ( v7 != 0 )
        {
          *out = 255 * out[2] / v7;
          out[1] = 255 * out[1] / v7;
          out[2] = 255 * v8 / v7;
        }
        else
        {
          *out = out[2];
          out[2] = v8;
        }
        out += 4;
        --v6;
      }
      while ( v6 != 0 );
    }
  }
  else if ( v2 != 0 )
  {
    v9 = z->s.img_x * z->s.img_y;
    do
    {
      v10 = *out;
      *out = out[2];
      out[2] = v10;
      out += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004065A0
// Name: parse_png_file
// Source: json
//------------------------------------------------------------------------------
int __usercall parse_png_file@<eax>(png *z@<eax>, int scan, int req_comp)
{
  int result; // eax
  int v5; // ebx
  unsigned int v6; // ebx
  int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned __int8 *v11; // eax
  _iobuf *img_file; // edx
  int v13; // eax
  int v14; // esi
  unsigned int v15; // eax
  int v16; // esi
  unsigned int v17; // eax
  unsigned __int8 *v18; // eax
  int v19; // ecx
  unsigned __int8 *v20; // eax
  unsigned int v21; // ebx
  unsigned __int8 *v22; // eax
  int v23; // ecx
  unsigned __int8 *v24; // eax
  int v25; // ecx
  unsigned __int8 *v26; // eax
  bool v27; // cc
  unsigned int img_y; // esi
  unsigned int v29; // eax
  unsigned int v30; // ecx
  unsigned int v31; // edx
  unsigned __int8 *v32; // ecx
  unsigned __int8 v33; // al
  unsigned __int8 *v34; // ecx
  int img_n; // eax
  int v36; // esi
  unsigned int v37; // edx
  unsigned int i; // ebx
  unsigned __int8 *img_buffer; // ecx
  unsigned __int8 v40; // al
  unsigned __int8 *v41; // ecx
  unsigned __int8 *v42; // eax
  unsigned __int8 v43; // cl
  unsigned __int8 *v44; // eax
  unsigned __int8 *v45; // eax
  unsigned __int8 v46; // cl
  unsigned __int8 *v47; // eax
  unsigned __int8 *v48; // eax
  int v49; // eax
  unsigned __int8 v50; // bl
  int v51; // ecx
  unsigned __int8 palette[1024]; // [esp+Ch] [ebp-424h] BYREF
  unsigned __int8 tc[4]; // [esp+40Ch] [ebp-24h] BYREF
  int iphone; // [esp+410h] [ebp-20h]
  unsigned int ioff; // [esp+414h] [ebp-1Ch]
  unsigned int idata_limit; // [esp+418h] [ebp-18h]
  int interlace; // [esp+41Ch] [ebp-14h]
  unsigned int raw_len; // [esp+420h] [ebp-10h] BYREF
  unsigned int pal_len; // [esp+424h] [ebp-Ch]
  int first; // [esp+428h] [ebp-8h]
  unsigned __int8 has_trans; // [esp+42Eh] [ebp-2h]
  unsigned __int8 pal_img_n; // [esp+42Fh] [ebp-1h]

  pal_img_n = 0;
  has_trans = 0;
  ioff = 0;
  idata_limit = 0;
  pal_len = 0;
  first = 1;
  interlace = 0;
  iphone = 0;
  if ( check_png_header(s: &z->s) == 0 )
    return 0;
  if ( scan == 1 )
    return 1;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v5 = get16(s: &z->s);
        v6 = get16(s: &z->s) + (v5 << 16);
        v7 = get16(s: &z->s);
        v8 = (v7 << 16) + get16(s: &z->s);
        if ( v8 <= 0x49484452 )
          break;
        if ( v8 == 1347179589 )
        {
          if ( first != 0 )
            goto LABEL_10;
          if ( v6 > 0x300 || (v37 = v6 / 3, pal_len = v6 / 3, 3 * (v6 / 3) != v6) )
          {
            failure_reason = "invalid PLTE";
            return 0;
          }
          for ( i = 0; i < v37; ++i )
          {
            img_buffer = z->s.img_buffer;
            if ( img_buffer >= z->s.img_buffer_end )
            {
              if ( z->s.from_file != 0 )
              {
                refill_buffer(s: &z->s);
                v41 = z->s.img_buffer;
                v40 = *v41;
                v37 = pal_len;
                z->s.img_buffer = v41 + 1;
              }
              else
              {
                v40 = 0;
              }
            }
            else
            {
              v40 = *img_buffer;
              z->s.img_buffer = img_buffer + 1;
            }
            palette[4 * i] = v40;
            v42 = z->s.img_buffer;
            if ( v42 >= z->s.img_buffer_end )
            {
              if ( z->s.from_file != 0 )
              {
                refill_buffer(s: &z->s);
                v44 = z->s.img_buffer;
                v43 = *v44;
                v37 = pal_len;
                z->s.img_buffer = v44 + 1;
              }
              else
              {
                v43 = 0;
              }
            }
            else
            {
              v43 = *v42;
              z->s.img_buffer = v42 + 1;
            }
            v45 = z->s.img_buffer;
            palette[4 * i + 1] = v43;
            if ( v45 >= z->s.img_buffer_end )
            {
              if ( z->s.from_file != 0 )
              {
                refill_buffer(s: &z->s);
                v47 = z->s.img_buffer;
                v46 = *v47;
                v37 = pal_len;
                z->s.img_buffer = v47 + 1;
              }
              else
              {
                v46 = 0;
              }
            }
            else
            {
              v46 = *v45;
              z->s.img_buffer = v45 + 1;
            }
            palette[4 * i + 2] = v46;
            palette[4 * i + 3] = -1;
          }
          goto LABEL_92;
        }
        if ( v8 == 1951551059 )
        {
          if ( first != 0 )
            goto LABEL_10;
          if ( z->idata != nullptr )
          {
            failure_reason = "tRNS after IDAT";
            return 0;
          }
          if ( pal_img_n != 0 )
          {
            if ( scan == 2 )
            {
              z->s.img_n = 4;
              return 1;
            }
            if ( pal_len == 0 )
            {
              failure_reason = "tRNS before PLTE";
              return 0;
            }
            if ( v6 > pal_len )
              goto LABEL_154;
            v31 = 0;
            pal_img_n = 4;
            for ( raw_len = 0; v31 < v6; raw_len = v31 )
            {
              v32 = z->s.img_buffer;
              if ( v32 >= z->s.img_buffer_end )
              {
                if ( z->s.from_file != 0 )
                {
                  refill_buffer(s: &z->s);
                  v34 = z->s.img_buffer;
                  v33 = *v34;
                  v31 = raw_len;
                  z->s.img_buffer = v34 + 1;
                }
                else
                {
                  v33 = 0;
                }
              }
              else
              {
                v33 = *v32;
                z->s.img_buffer = v32 + 1;
              }
              palette[4 * v31++ + 3] = v33;
            }
          }
          else
          {
            img_n = z->s.img_n;
            if ( (img_n & 1) == 0 )
            {
              failure_reason = "tRNS with alpha";
              return 0;
            }
            if ( v6 != 2 * img_n )
            {
LABEL_154:
              failure_reason = "bad tRNS len";
              return 0;
            }
            v36 = 0;
            has_trans = 1;
            if ( img_n > 0 )
            {
              do
                tc[v36++] = get16(s: &z->s);
              while ( v36 < z->s.img_n );
            }
          }
LABEL_92:
          get16(s: &z->s);
          get16(s: &z->s);
        }
        else
        {
LABEL_71:
          if ( first != 0 )
            goto LABEL_10;
          if ( (v8 & 0x20000000) == 0 )
          {
            byte_465634 = HIBYTE(v8);
            byte_465637 = v8;
            byte_465635 = BYTE2(v8);
            byte_465636 = BYTE1(v8);
            failure_reason = &byte_465634;
            return 0;
          }
          skip(n: v6, s: &z->s);
          get16(s: &z->s);
          get16(s: &z->s);
        }
      }
      if ( v8 == 1229472850 )
      {
        if ( first == 0 )
        {
          failure_reason = "multiple IHDR";
          return 0;
        }
        first = 0;
        if ( v6 != 13 )
        {
          failure_reason = "bad IHDR len";
          return 0;
        }
        v14 = get16(s: &z->s);
        v15 = (v14 << 16) + get16(s: &z->s);
        z->s.img_x = v15;
        if ( v15 > 0x1000000
          || (v16 = get16(s: &z->s), v17 = (v16 << 16) + get16(s: &z->s), z->s.img_y = v17, v17 > 0x1000000) )
        {
LABEL_68:
          failure_reason = "too large";
          return 0;
        }
        v18 = z->s.img_buffer;
        if ( v18 >= z->s.img_buffer_end )
        {
          if ( z->s.from_file == 0 )
            goto LABEL_143;
          refill_buffer(s: &z->s);
          v18 = z->s.img_buffer;
        }
        v19 = *v18;
        v20 = v18 + 1;
        z->s.img_buffer = v20;
        if ( v19 != 8 )
        {
LABEL_143:
          failure_reason = "8bit only";
          return 0;
        }
        if ( v20 >= z->s.img_buffer_end )
        {
          if ( z->s.from_file == 0 )
          {
            LOBYTE(v21) = 0;
            goto LABEL_46;
          }
          refill_buffer(s: &z->s);
          v20 = z->s.img_buffer;
        }
        v21 = *v20;
        z->s.img_buffer = v20 + 1;
        if ( v21 > 6 )
          goto LABEL_144;
        if ( v21 == 3 )
        {
          pal_img_n = 3;
          goto LABEL_47;
        }
LABEL_46:
        if ( (v21 & 1) != 0 )
        {
LABEL_144:
          failure_reason = "bad ctype";
          return 0;
        }
LABEL_47:
        v22 = z->s.img_buffer;
        if ( v22 >= z->s.img_buffer_end )
        {
          if ( z->s.from_file == 0 )
            goto LABEL_51;
          refill_buffer(s: &z->s);
          v22 = z->s.img_buffer;
        }
        v23 = *v22;
        z->s.img_buffer = v22 + 1;
        if ( v23 != 0 )
        {
          failure_reason = "bad comp method";
          return 0;
        }
LABEL_51:
        v24 = z->s.img_buffer;
        if ( v24 >= z->s.img_buffer_end )
        {
          if ( z->s.from_file == 0 )
            goto LABEL_55;
          refill_buffer(s: &z->s);
          v24 = z->s.img_buffer;
        }
        v25 = *v24;
        z->s.img_buffer = v24 + 1;
        if ( v25 != 0 )
        {
          failure_reason = "bad filter method";
          return 0;
        }
LABEL_55:
        v26 = z->s.img_buffer;
        if ( v26 >= z->s.img_buffer_end )
        {
          if ( z->s.from_file == 0 )
          {
            interlace = 0;
            goto LABEL_58;
          }
          refill_buffer(s: &z->s);
          v26 = z->s.img_buffer;
          interlace = *v26;
        }
        else
        {
          interlace = *v26;
        }
        v27 = interlace <= 1;
        z->s.img_buffer = v26 + 1;
        if ( !v27 )
        {
          failure_reason = "bad interlace method";
          return 0;
        }
LABEL_58:
        if ( z->s.img_x == 0 || (img_y = z->s.img_y) == 0 )
        {
          failure_reason = "0-pixel image";
          return 0;
        }
        v29 = 0x40000000 / z->s.img_x;
        if ( pal_img_n != 0 )
        {
          z->s.img_n = 1;
          if ( v29 >> 2 < img_y )
            goto LABEL_68;
        }
        else
        {
          v30 = (v21 & 2 | 1) + ((v21 & 4) != 0);
          z->s.img_n = v30;
          if ( v29 / v30 < img_y )
            goto LABEL_68;
          if ( scan == 2 )
            return 1;
        }
        goto LABEL_92;
      }
      if ( v8 != 1130840649 )
        break;
      img_file = z->s.img_file;
      iphone = stbi_de_iphone_flag;
      if ( img_file != nullptr && (v13 = z->s.img_buffer_end - z->s.img_buffer) < (int)v6 )
      {
        z->s.img_buffer = z->s.img_buffer_end;
        fseek(stream: img_file, offset: v6 - v13, whence: 1);
        get16(s: &z->s);
        get16(s: &z->s);
      }
      else
      {
        z->s.img_buffer += v6;
        get16(s: &z->s);
        get16(s: &z->s);
      }
    }
    if ( v8 != 1229209940 )
      break;
    if ( first != 0 )
      goto LABEL_10;
    if ( pal_img_n != 0 && pal_len == 0 )
    {
      failure_reason = "no PLTE";
      return 0;
    }
    if ( scan == 2 )
    {
      z->s.img_n = pal_img_n;
      return 1;
    }
    v9 = v6 + ioff;
    v10 = idata_limit;
    raw_len = v6 + ioff;
    if ( v6 + ioff > idata_limit )
    {
      if ( idata_limit == 0 )
      {
        v10 = v6;
        if ( v6 <= 0x1000 )
          v10 = 4096;
        idata_limit = v10;
      }
      if ( v9 > v10 )
      {
        do
          v10 *= 2;
        while ( v9 > v10 );
        idata_limit = v10;
      }
      v11 = (unsigned __int8 *)_realloc_crt(ptr: z->idata, size: v10);
      if ( v11 == nullptr )
      {
        failure_reason = "outofmem";
        return 0;
      }
      z->idata = v11;
    }
    if ( !getn(s: &z->s, buffer: &z->idata[ioff], n: v6) )
    {
      failure_reason = "outofdata";
      return 0;
    }
    ioff = raw_len;
    get16(s: &z->s);
    get16(s: &z->s);
  }
  if ( v8 != 1229278788 )
    goto LABEL_71;
  if ( first != 0 )
  {
LABEL_10:
    failure_reason = "first not IHDR";
    return 0;
  }
  if ( scan != 0 )
    return 1;
  result = (int)z->idata;
  if ( result == 0 )
  {
    failure_reason = "no IDAT";
    return result;
  }
  v48 = (unsigned __int8 *)stbi_zlib_decode_malloc_guesssize_headerflag(
                             buffer: (char *)result,
                             len: ioff,
                             initial_size: 0x4000u,
                             outlen: (int *)&raw_len,
                             parse_header: iphone == 0);
  z->expanded = v48;
  if ( v48 != nullptr )
  {
    free(pMem: z->idata);
    v49 = z->s.img_n;
    z->idata = nullptr;
    if ( req_comp != v49 + 1 || req_comp == 3 )
    {
      v50 = pal_img_n;
      goto LABEL_123;
    }
    v50 = pal_img_n;
    if ( pal_img_n != 0 )
    {
LABEL_123:
      if ( has_trans != 0 )
        goto LABEL_124;
      z->s.img_out_n = v49;
    }
    else
    {
LABEL_124:
      z->s.img_out_n = v49 + 1;
    }
    if ( create_png_image(a: z, out_n: z->s.img_out_n, raw: z->expanded, raw_len, interlaced: interlace) != 0
      && (has_trans == 0 || compute_transparency(z, tc, out_n: z->s.img_out_n) != 0) )
    {
      if ( iphone != 0 && z->s.img_out_n > 2 )
        stbi_de_iphone(a1: v51, z);
      if ( v50 == 0 )
        goto LABEL_136;
      z->s.img_n = v50;
      z->s.img_out_n = v50;
      if ( req_comp >= 3 )
        z->s.img_out_n = req_comp;
      if ( expand_palette(palette, a: z, len: z->s.img_out_n) != 0 )
      {
LABEL_136:
        free(pMem: z->expanded);
        z->expanded = nullptr;
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406ED0
// Name: do_png
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall do_png@<eax>(png *p@<esi>, unsigned int req_comp@<eax>, int *x, int *y, int *n)
{
  unsigned __int8 *out; // ebx
  int img_out_n; // ecx
  unsigned __int8 *idata; // [esp-Ch] [ebp-14h]
  unsigned __int8 *expanded; // [esp-8h] [ebp-10h]

  out = nullptr;
  p->expanded = nullptr;
  p->idata = nullptr;
  p->out = nullptr;
  if ( req_comp > 4 )
  {
    failure_reason = "bad req_comp";
  }
  else
  {
    if ( parse_png_file(z: p, scan: 0, req_comp) == 0 )
    {
LABEL_8:
      free(pMem: p->out);
      expanded = p->expanded;
      p->out = nullptr;
      free(pMem: expanded);
      idata = p->idata;
      p->expanded = nullptr;
      free(pMem: idata);
      p->idata = nullptr;
      return out;
    }
    out = p->out;
    p->out = nullptr;
    if ( req_comp == 0
      || (img_out_n = p->s.img_out_n, req_comp == img_out_n)
      || (out = convert_format(img_n: img_out_n, req_comp, data: out, x: p->s.img_x, y: p->s.img_y),
          p->s.img_out_n = req_comp,
          out != nullptr) )
    {
      *x = p->s.img_x;
      *y = p->s.img_y;
      if ( n != nullptr )
        *n = p->s.img_n;
      goto LABEL_8;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00406FB0
// Name: int stbi_png_test_file(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl stbi_png_test_file(_iobuf *f)
{
  int v1; // edi
  int v2; // ebx
  png p; // [esp+Ch] [ebp-B0h] BYREF

  v1 = ftell(stream: f);
  p.s.img_buffer_end = (unsigned __int8 *)&p.s.from_file;
  p.s.img_file = f;
  p.s.buflen = 128;
  p.s.img_buffer = (unsigned __int8 *)&p.s.from_file;
  p.s.from_file = 1;
  v2 = parse_png_file(z: &p, scan: 1, req_comp: 0);
  fseek(stream: f, offset: v1, whence: 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00407010
// Name: bmp_test
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall bmp_test@<eax>(stbi *s@<eax>)
{
  unsigned __int8 *img_buffer; // eax
  int v3; // ecx
  unsigned __int8 *v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // eax

  img_buffer = s->img_buffer;
  if ( img_buffer >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      return false;
    refill_buffer(s);
    img_buffer = s->img_buffer;
  }
  v3 = *img_buffer;
  v4 = img_buffer + 1;
  s->img_buffer = v4;
  if ( v3 != 66 )
    return false;
  if ( v4 >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      return false;
    refill_buffer(s);
    v4 = s->img_buffer;
  }
  v6 = *v4;
  s->img_buffer = v4 + 1;
  if ( v6 != 77 )
    return false;
  get16le(s);
  get16le(s);
  get16le(s);
  get16le(s);
  get16le(s);
  get16le(s);
  v7 = get16le(s);
  v8 = v7 + (get16le(s) << 16);
  return v8 == 12 || v8 == 40 || v8 == 56 || v8 == 108;
}

//------------------------------------------------------------------------------
// Address: 0x004070E0
// Name: int stbi_bmp_test_file(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl stbi_bmp_test_file(_iobuf *f)
{
  int v1; // edi
  BOOL v2; // ebx
  stbi s; // [esp+Ch] [ebp-A4h] BYREF

  v1 = ftell(stream: f);
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_file = f;
  s.buflen = 128;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.from_file = 1;
  v2 = bmp_test(&s);
  fseek(stream: f, offset: v1, whence: 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00407140
// Name: high_bit
// Source: json
//------------------------------------------------------------------------------
int __fastcall high_bit(unsigned int z)
{
  int result; // eax

  result = 0;
  if ( z == 0 )
    return -1;
  if ( z >= 0x10000 )
  {
    result = 16;
    z >>= 16;
  }
  if ( z >= 0x100 )
  {
    result += 8;
    z >>= 8;
  }
  if ( z >= 0x10 )
  {
    result += 4;
    z >>= 4;
  }
  if ( z >= 4 )
  {
    result += 2;
    z >>= 2;
  }
  if ( z >= 2 )
    ++result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407190
// Name: bitcount
// Source: json
//------------------------------------------------------------------------------
int __fastcall bitcount(unsigned int a)
{
  unsigned int v1; // ecx

  v1 = ((((a & 0x55555555) + ((a >> 1) & 0x55555555)) & 0x33333333)
      + ((((a & 0x55555555) + ((a >> 1) & 0x55555555)) >> 2) & 0x33333333)
      + (((((a & 0x55555555) + ((a >> 1) & 0x55555555)) & 0x33333333)
        + ((((a & 0x55555555) + ((a >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4))
     & 0xF0F0F0F;
  return (unsigned __int8)(BYTE1(v1) + v1 + (((v1 >> 8) + v1) >> 16));
}

//------------------------------------------------------------------------------
// Address: 0x004071E0
// Name: shiftsigned
// Source: json
//------------------------------------------------------------------------------
int __usercall shiftsigned@<eax>(int v@<edx>, int shift@<ecx>, int bits@<esi>)
{
  int v3; // edx
  int result; // eax
  int i; // ecx
  int v6; // edi

  if ( shift >= 0 )
    v3 = v >> shift;
  else
    v3 = v << -(char)shift;
  result = v3;
  for ( i = bits; i < 8; result += v6 )
  {
    v6 = v3 >> i;
    i += bits;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407210
// Name: bmp_load
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall bmp_load@<eax>(stbi *s@<edi>, int *x, int *y, int *comp, int req_comp)
{
  unsigned __int8 *img_buffer; // eax
  int v6; // ecx
  unsigned __int8 *v7; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // esi
  int v11; // ebx
  unsigned __int8 *result; // eax
  unsigned int v13; // eax
  int v14; // esi
  int v15; // esi
  int v16; // esi
  signed int img_y; // eax
  int v18; // eax
  int v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  int v22; // ebx
  int v23; // eax
  int v24; // edx
  unsigned __int8 *v25; // ecx
  unsigned __int8 v26; // al
  unsigned __int8 *v27; // ecx
  unsigned __int8 *v28; // eax
  unsigned __int8 v29; // cl
  unsigned __int8 *v30; // eax
  unsigned __int8 *v31; // eax
  unsigned __int8 v32; // cl
  unsigned __int8 *v33; // eax
  bool v34; // zf
  unsigned __int8 *v35; // eax
  unsigned int img_x; // eax
  unsigned __int8 *v37; // esi
  bool v38; // cc
  unsigned __int8 *v39; // ecx
  int v40; // eax
  unsigned __int8 *v41; // ecx
  int v42; // ecx
  unsigned __int8 v43; // dl
  unsigned __int8 v44; // al
  unsigned __int8 *v45; // ecx
  int v46; // eax
  unsigned __int8 *v47; // ecx
  unsigned __int8 v48; // cl
  unsigned __int8 v49; // dl
  unsigned __int8 v50; // al
  _iobuf *img_file; // edx
  int v52; // eax
  unsigned int v53; // eax
  unsigned __int8 *v54; // ecx
  unsigned __int8 v55; // al
  unsigned int v56; // edx
  unsigned int v57; // edx
  int v58; // edx
  int v59; // edx
  int v60; // edx
  unsigned __int8 *v61; // ecx
  unsigned __int8 *v62; // eax
  unsigned __int8 v63; // cl
  unsigned __int8 *v64; // eax
  unsigned __int8 *v65; // eax
  unsigned __int8 v66; // cl
  unsigned __int8 *v67; // eax
  unsigned __int8 *v68; // ecx
  unsigned __int8 v69; // al
  unsigned __int8 *v70; // ecx
  unsigned int v71; // eax
  unsigned __int8 v72; // al
  int v73; // esi
  int v74; // ecx
  unsigned __int8 v75; // al
  unsigned int v76; // edx
  int v77; // esi
  unsigned __int8 v78; // al
  int v79; // ebx
  int v80; // esi
  unsigned __int8 *v81; // ecx
  unsigned __int8 *v82; // edx
  signed int v83; // ebx
  int v84; // edx
  unsigned __int8 v85; // al
  int v86; // ebx
  int v87; // edx
  unsigned __int8 pal[256][4]; // [esp+8h] [ebp-454h]
  int flip_vertically; // [esp+408h] [ebp-54h]
  int bcount; // [esp+40Ch] [ebp-50h]
  int gcount; // [esp+410h] [ebp-4Ch]
  int ashift; // [esp+414h] [ebp-48h]
  int gshift; // [esp+418h] [ebp-44h]
  int acount; // [esp+41Ch] [ebp-40h]
  int rshift; // [esp+420h] [ebp-3Ch]
  int bshift; // [esp+424h] [ebp-38h]
  int rcount; // [esp+428h] [ebp-34h]
  int target; // [esp+42Ch] [ebp-30h]
  unsigned int ma; // [esp+430h] [ebp-2Ch]
  unsigned int mb; // [esp+434h] [ebp-28h]
  unsigned int mr; // [esp+438h] [ebp-24h]
  int bpp; // [esp+43Ch] [ebp-20h]
  unsigned int v; // [esp+440h] [ebp-1Ch]
  int easy; // [esp+444h] [ebp-18h]
  unsigned int mg; // [esp+448h] [ebp-14h]
  int pad; // [esp+44Ch] [ebp-10h]
  int hsz; // [esp+450h] [ebp-Ch]
  unsigned __int8 *out; // [esp+454h] [ebp-8h]
  int i; // [esp+458h] [ebp-4h]

  img_buffer = s->img_buffer;
  mr = 0;
  mg = 0;
  mb = 0;
  ma = 0;
  pad = 0;
  if ( img_buffer >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      goto LABEL_181;
    refill_buffer(s);
    img_buffer = s->img_buffer;
  }
  v6 = *img_buffer;
  v7 = img_buffer + 1;
  s->img_buffer = v7;
  if ( v6 != 66 )
    goto LABEL_181;
  if ( v7 >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
    {
LABEL_181:
      failure_reason = "not BMP";
      return nullptr;
    }
    refill_buffer(s);
    v7 = s->img_buffer;
  }
  v8 = *v7;
  s->img_buffer = v7 + 1;
  if ( v8 != 77 )
    goto LABEL_181;
  get16le(s);
  get16le(s);
  get16le(s);
  get16le(s);
  v9 = get16le(s);
  v = v9 + (get16le(s) << 16);
  v10 = get16le(s);
  v11 = v10 + (get16le(s) << 16);
  hsz = v11;
  if ( v11 == 12 )
  {
    s->img_x = get16le(s);
    v13 = get16le(s);
  }
  else
  {
    if ( v11 != 40 && v11 != 56 && v11 != 108 )
    {
      failure_reason = "unknown BMP";
      return nullptr;
    }
    v14 = get16le(s);
    s->img_x = v14 + (get16le(s) << 16);
    v15 = get16le(s);
    v13 = v15 + (get16le(s) << 16);
  }
  s->img_y = v13;
  if ( get16le(s) != 1 )
    goto LABEL_17;
  v16 = get16le(s);
  bpp = v16;
  if ( v16 == 1 )
  {
    failure_reason = "monochrome";
    return nullptr;
  }
  img_y = s->img_y;
  s->img_y = abs32(img_y);
  flip_vertically = img_y > 0;
  if ( v11 == 12 )
  {
    if ( v16 >= 24 )
      goto LABEL_43;
    v18 = (int)(v - 38) / 3;
    goto LABEL_42;
  }
  v19 = get32le(s);
  easy = v19;
  if ( v19 == 1 || v19 == 2 )
  {
    failure_reason = "BMP RLE";
    return nullptr;
  }
  get32le(s);
  get32le(s);
  get32le(s);
  get32le(s);
  get32le(s);
  if ( v11 == 40 )
    goto LABEL_31;
  if ( v11 == 56 )
  {
    get32le(s);
    get32le(s);
    get32le(s);
    get32le(s);
LABEL_31:
    if ( bpp == 16 || bpp == 32 )
    {
      if ( easy != 0 )
      {
        if ( easy != 3 || (mr = get32le(s), mg = get32le(s), v20 = get32le(s), mb = v20, mr == mg) && mg == v20 )
        {
LABEL_17:
          failure_reason = "bad BMP";
          return nullptr;
        }
      }
      else
      {
        if ( bpp == 32 )
        {
          mr = 16711680;
          mg = 65280;
          mb = 255;
          ma = -16777216;
          goto LABEL_43;
        }
        mr = 31744;
        mg = 992;
        mb = 31;
      }
    }
    goto LABEL_40;
  }
  mr = get32le(s);
  mg = get32le(s);
  mb = get32le(s);
  ma = get32le(s);
  get32le(s);
  for ( easy = 12; easy != 0; --easy )
    get32le(s);
LABEL_40:
  if ( bpp < 16 )
  {
    v18 = (int)(v - v11 - 14) >> 2;
LABEL_42:
    pad = v18;
  }
LABEL_43:
  v21 = (ma != 0) + 3;
  s->img_n = v21;
  if ( req_comp <= 2 )
  {
    target = v21;
  }
  else
  {
    v21 = req_comp;
    target = req_comp;
  }
  result = (unsigned __int8 *)operator new(nSize: s->img_y * v21 * s->img_x);
  out = result;
  if ( result == nullptr )
  {
    failure_reason = "outofmem";
    return result;
  }
  v22 = 0;
  if ( bpp >= 16 )
  {
    rshift = 0;
    gshift = 0;
    bshift = 0;
    ashift = 0;
    rcount = 0;
    gcount = 0;
    bcount = 0;
    acount = 0;
    easy = 0;
    skip(n: v - hsz - 14, s);
    if ( bpp == 24 )
    {
      v53 = 3 * s->img_x;
    }
    else if ( bpp == 16 )
    {
      v53 = 2 * s->img_x;
    }
    else
    {
      v53 = 0;
    }
    pad = -v53 & 3;
    if ( bpp == 24 )
    {
      easy = 1;
      goto LABEL_115;
    }
    if ( bpp == 32 && mb == 255 && mg == 65280 && (v56 = mr, mr == -16777216) )
    {
      if ( ma == -16777216 )
      {
        easy = 2;
        goto LABEL_115;
      }
    }
    else
    {
      v56 = mr;
      if ( mr == 0 || mg == 0 || mb == 0 )
      {
        failure_reason = "bad masks";
        return nullptr;
      }
    }
    rshift = high_bit(z: v56) - 7;
    rcount = bitcount(a: v57);
    gshift = high_bit(z: mg) - 7;
    gcount = v58;
    bshift = high_bit(z: mb) - 7;
    bcount = v59;
    ashift = high_bit(z: ma) - 7;
    acount = v60;
LABEL_115:
    for ( hsz = 0; hsz < (signed int)s->img_y; ++hsz )
    {
      i = 0;
      if ( easy != 0 )
      {
        if ( (int)s->img_x > 0 )
        {
          do
          {
            v54 = s->img_buffer;
            if ( v54 >= s->img_buffer_end )
            {
              if ( s->from_file != 0 )
              {
                refill_buffer(s);
                v61 = s->img_buffer;
                v55 = *v61;
                s->img_buffer = v61 + 1;
              }
              else
              {
                v55 = 0;
              }
            }
            else
            {
              v55 = *v54;
              s->img_buffer = v54 + 1;
            }
            out[v22 + 2] = v55;
            v62 = s->img_buffer;
            if ( v62 >= s->img_buffer_end )
            {
              if ( s->from_file != 0 )
              {
                refill_buffer(s);
                v64 = s->img_buffer;
                v63 = *v64;
                s->img_buffer = v64 + 1;
              }
              else
              {
                v63 = 0;
              }
            }
            else
            {
              v63 = *v62;
              s->img_buffer = v62 + 1;
            }
            out[v22 + 1] = v63;
            v65 = s->img_buffer;
            if ( v65 >= s->img_buffer_end )
            {
              if ( s->from_file != 0 )
              {
                refill_buffer(s);
                v67 = s->img_buffer;
                v66 = *v67;
                s->img_buffer = v67 + 1;
              }
              else
              {
                v66 = 0;
              }
            }
            else
            {
              v66 = *v65;
              s->img_buffer = v65 + 1;
            }
            out[v22] = v66;
            v22 += 3;
            if ( easy == 2 )
            {
              v68 = s->img_buffer;
              if ( v68 >= s->img_buffer_end )
              {
                if ( s->from_file != 0 )
                {
                  refill_buffer(s);
                  v70 = s->img_buffer;
                  v69 = *v70;
                  s->img_buffer = v70 + 1;
                }
                else
                {
                  v69 = 0;
                }
              }
              else
              {
                v69 = *v68;
                s->img_buffer = v68 + 1;
              }
            }
            else
            {
              v69 = -1;
            }
            if ( target == 4 )
              out[v22++] = v69;
            ++i;
          }
          while ( i < (signed int)s->img_x );
        }
      }
      else if ( (int)s->img_x > 0 )
      {
        do
        {
          if ( bpp == 16 )
            v71 = get16le(s);
          else
            v71 = get32le(s);
          v = v71;
          v72 = shiftsigned(v: mr & v71, shift: rshift, bits: rcount);
          v73 = gcount;
          v74 = gshift;
          out[v22] = v72;
          v75 = shiftsigned(v: mg & v, shift: v74, bits: v73);
          v76 = mb & v;
          v77 = bcount;
          out[v22 + 1] = v75;
          out[v22 + 2] = shiftsigned(v: v76, shift: bshift, bits: v77);
          v22 += 3;
          if ( ma != 0 )
            v78 = shiftsigned(v: ma & v, shift: ashift, bits: acount);
          else
            v78 = -1;
          if ( target == 4 )
            out[v22++] = v78;
          ++i;
        }
        while ( i < (signed int)s->img_x );
      }
      skip(n: pad, s);
    }
    goto LABEL_166;
  }
  v23 = pad;
  if ( pad == 0 || pad > 256 )
  {
    free(pMem: out);
    failure_reason = "invalid";
    return nullptr;
  }
  v24 = 0;
  i = 0;
  if ( pad > 0 )
  {
    do
    {
      v25 = s->img_buffer;
      if ( v25 >= s->img_buffer_end )
      {
        if ( s->from_file != 0 )
        {
          refill_buffer(s);
          v27 = s->img_buffer;
          v26 = *v27;
          v24 = i;
          s->img_buffer = v27 + 1;
        }
        else
        {
          v26 = 0;
        }
      }
      else
      {
        v26 = *v25;
        s->img_buffer = v25 + 1;
      }
      pal[v24][2] = v26;
      v28 = s->img_buffer;
      if ( v28 >= s->img_buffer_end )
      {
        if ( s->from_file != 0 )
        {
          refill_buffer(s);
          v30 = s->img_buffer;
          v29 = *v30;
          v24 = i;
          s->img_buffer = v30 + 1;
        }
        else
        {
          v29 = 0;
        }
      }
      else
      {
        v29 = *v28;
        s->img_buffer = v28 + 1;
      }
      v31 = s->img_buffer;
      pal[v24][1] = v29;
      if ( v31 >= s->img_buffer_end )
      {
        if ( s->from_file != 0 )
        {
          refill_buffer(s);
          v33 = s->img_buffer;
          v32 = *v33;
          v24 = i;
          s->img_buffer = v33 + 1;
        }
        else
        {
          v32 = 0;
        }
      }
      else
      {
        v32 = *v31;
        s->img_buffer = v31 + 1;
      }
      v34 = hsz == 12;
      pal[v24][0] = v32;
      if ( !v34 )
      {
        v35 = s->img_buffer;
        if ( v35 >= s->img_buffer_end )
        {
          if ( s->from_file != 0 )
          {
            refill_buffer(s);
            ++s->img_buffer;
            v24 = i;
          }
        }
        else
        {
          s->img_buffer = v35 + 1;
        }
      }
      v23 = pad;
      pal[v24++][3] = -1;
      i = v24;
    }
    while ( v24 < v23 );
  }
  skip(n: v - v23 * ((hsz != 12) + 3) - hsz - 14, s);
  if ( bpp == 4 )
  {
    img_x = (s->img_x + 1) >> 1;
  }
  else
  {
    if ( bpp != 8 )
    {
      free(pMem: out);
      failure_reason = "bad bpp";
      return nullptr;
    }
    img_x = s->img_x;
  }
  pad = -img_x & 3;
  hsz = 0;
  if ( (int)s->img_y > 0 )
  {
    v37 = out;
    do
    {
      v38 = (signed int)s->img_x <= 0;
      i = 0;
      if ( !v38 )
      {
        do
        {
          v39 = s->img_buffer;
          if ( v39 >= s->img_buffer_end )
          {
            if ( s->from_file != 0 )
            {
              refill_buffer(s);
              v41 = s->img_buffer;
              v40 = *v41;
              v37 = out;
              s->img_buffer = v41 + 1;
            }
            else
            {
              v40 = 0;
            }
          }
          else
          {
            v40 = *v39;
            s->img_buffer = v39 + 1;
          }
          v42 = 0;
          if ( bpp == 4 )
          {
            v42 = v40 & 0xF;
            v40 >>= 4;
          }
          v37[v22] = pal[v40][0];
          v43 = pal[v40][1];
          v44 = pal[v40][2];
          v37[v22 + 1] = v43;
          v37[v22 + 2] = v44;
          v22 += 3;
          if ( target == 4 )
            v37[v22++] = -1;
          if ( i + 1 == s->img_x )
            break;
          if ( bpp == 8 )
          {
            v45 = s->img_buffer;
            if ( v45 >= s->img_buffer_end )
            {
              if ( s->from_file != 0 )
              {
                refill_buffer(s);
                v47 = s->img_buffer;
                v46 = *v47;
                v37 = out;
                s->img_buffer = v47 + 1;
              }
              else
              {
                v46 = 0;
              }
            }
            else
            {
              v46 = *v45;
              s->img_buffer = v45 + 1;
            }
          }
          else
          {
            v46 = v42;
          }
          v48 = pal[v46][0];
          v49 = pal[v46][1];
          v50 = pal[v46][2];
          v37[v22] = v48;
          v37[v22 + 1] = v49;
          v37[v22 + 2] = v50;
          v22 += 3;
          if ( target == 4 )
            v37[v22++] = -1;
          i += 2;
        }
        while ( i < (signed int)s->img_x );
      }
      img_file = s->img_file;
      if ( img_file != nullptr && (v52 = s->img_buffer_end - s->img_buffer) < pad )
      {
        s->img_buffer = s->img_buffer_end;
        fseek(stream: img_file, offset: pad - v52, whence: 1);
      }
      else
      {
        s->img_buffer += pad;
      }
      ++hsz;
    }
    while ( hsz < (signed int)s->img_y );
  }
LABEL_166:
  if ( flip_vertically == 0
    || (v79 = 0, v38 = (s->img_y & 0x80000000) != 0 || (s->img_y & 0xFFFFFFFE) == 0, hsz = 0, v38) )
  {
    v80 = target;
  }
  else
  {
    v80 = target;
    do
    {
      v81 = &out[s->img_x * v80 * (s->img_y - v79 - 1)];
      v82 = &out[s->img_x * v80 * v79];
      v83 = s->img_x * v80;
      i = 0;
      if ( v83 > 0 )
      {
        v84 = v82 - v81;
        do
        {
          v85 = v81[v84];
          v81[v84] = *v81;
          *v81 = v85;
          v86 = v80 * s->img_x;
          ++v81;
          ++i;
        }
        while ( i < v86 );
      }
      v79 = hsz + 1;
      v87 = (int)s->img_y >> 1;
      hsz = v79;
    }
    while ( v79 < v87 );
  }
  result = out;
  if ( req_comp != 0 && req_comp != v80 )
  {
    result = convert_format(img_n: v80, req_comp, data: out, x: s->img_x, y: s->img_y);
    if ( result == nullptr )
      return nullptr;
  }
  *x = s->img_x;
  *y = s->img_y;
  if ( comp != nullptr )
    *comp = v80;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407CC0
// Name: unsigned char __near * stbi_bmp_load_from_file(struct _iobuf __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl stbi_bmp_load_from_file(_iobuf *f, int *x, int *y, int *comp, int req_comp)
{
  stbi s; // [esp+4h] [ebp-A4h] BYREF

  s.img_file = f;
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.buflen = 128;
  s.from_file = 1;
  return bmp_load(&s, x, y, comp, req_comp);
}

//------------------------------------------------------------------------------
// Address: 0x00407D20
// Name: tga_test
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall tga_test@<eax>(stbi *s@<eax>)
{
  unsigned __int8 *img_buffer; // eax
  unsigned __int8 *v3; // eax
  unsigned __int8 v4; // cl
  unsigned __int8 *v6; // ecx
  unsigned __int8 v7; // al
  unsigned __int8 *v8; // ecx
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // ecx
  int v11; // eax

  img_buffer = s->img_buffer;
  if ( img_buffer >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      ++s->img_buffer;
    }
  }
  else
  {
    s->img_buffer = img_buffer + 1;
  }
  v3 = s->img_buffer;
  if ( v3 >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      goto LABEL_10;
    refill_buffer(s);
    v3 = s->img_buffer;
  }
  v4 = *v3;
  s->img_buffer = v3 + 1;
  if ( v4 > 1u )
    return false;
LABEL_10:
  v6 = s->img_buffer;
  if ( v6 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v8 = s->img_buffer;
      v7 = *v8;
      s->img_buffer = v8 + 1;
    }
    else
    {
      v7 = 0;
    }
  }
  else
  {
    v7 = *v6;
    s->img_buffer = v6 + 1;
  }
  if ( v7 != 1 && v7 != 2 && v7 != 3 && v7 != 9 && v7 != 10 && v7 != 11 )
    return false;
  get16(s);
  get16(s);
  v9 = s->img_buffer;
  if ( v9 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      ++s->img_buffer;
    }
  }
  else
  {
    s->img_buffer = v9 + 1;
  }
  get16(s);
  get16(s);
  if ( get16(s) < 1 || get16(s) < 1 )
    return false;
  v10 = s->img_buffer;
  if ( v10 >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      return false;
    refill_buffer(s);
    v10 = s->img_buffer;
  }
  v11 = *v10;
  s->img_buffer = v10 + 1;
  return v11 == 8 || v11 == 16 || v11 == 24 || v11 == 32;
}

//------------------------------------------------------------------------------
// Address: 0x00407EA0
// Name: int stbi_tga_test_file(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl stbi_tga_test_file(_iobuf *f)
{
  int v1; // edi
  BOOL v2; // ebx
  stbi s; // [esp+Ch] [ebp-A4h] BYREF

  v1 = ftell(stream: f);
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_file = f;
  s.buflen = 128;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.from_file = 1;
  v2 = tga_test(&s);
  fseek(stream: f, offset: v1, whence: 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00407F00
// Name: tga_load
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall tga_load@<eax>(stbi *s@<eax>, int *x, int *y, int *comp, int req_comp)
{
  unsigned __int8 *img_buffer; // eax
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  unsigned __int8 v10; // cl
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // ecx
  unsigned __int8 v13; // al
  unsigned __int8 *v14; // ecx
  int v15; // edi
  unsigned __int8 *v16; // eax
  unsigned __int8 v17; // cl
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // eax
  unsigned __int8 v20; // cl
  unsigned __int8 *v21; // eax
  int v22; // ebx
  unsigned __int8 *v23; // ecx
  unsigned __int8 v24; // al
  unsigned __int8 *v25; // ecx
  unsigned __int8 v26; // dl
  int v27; // ecx
  _BYTE *v28; // edi
  __int16 v29; // bx
  unsigned __int8 *v30; // ecx
  unsigned __int8 v31; // al
  unsigned __int8 *v32; // ecx
  unsigned __int8 *v33; // ecx
  unsigned __int8 v34; // al
  unsigned __int8 *v35; // ecx
  int v36; // ecx
  int v37; // edi
  unsigned __int8 *v38; // eax
  unsigned __int8 *v39; // ecx
  int v40; // edi
  unsigned __int8 *v41; // ebx
  unsigned __int8 *v42; // ecx
  unsigned __int8 v43; // al
  unsigned __int8 *v44; // ecx
  bool v45; // zf
  int v46; // esi
  int v47; // edx
  int v48; // edi
  unsigned __int8 *v49; // ecx
  unsigned __int8 *v50; // eax
  unsigned __int8 v51; // dl
  int tga_inverted; // [esp+Ch] [ebp-44h]
  int tga_offset; // [esp+10h] [ebp-40h]
  int tga_offseta; // [esp+10h] [ebp-40h]
  int tga_offsetb; // [esp+10h] [ebp-40h]
  int tga_palette_start; // [esp+14h] [ebp-3Ch]
  int tga_palette_starta; // [esp+14h] [ebp-3Ch]
  int read_next_pixel; // [esp+18h] [ebp-38h]
  int v60; // [esp+1Ch] [ebp-34h]
  int tga_palette_len; // [esp+20h] [ebp-30h]
  int RLE_repeating; // [esp+24h] [ebp-2Ch]
  int tga_is_RLE; // [esp+28h] [ebp-28h]
  unsigned __int8 *tga_data; // [esp+2Ch] [ebp-24h]
  unsigned __int8 *tga_palette; // [esp+30h] [ebp-20h]
  int tga_indexed; // [esp+34h] [ebp-1Ch]
  int RLE_count; // [esp+38h] [ebp-18h]
  int tga_height; // [esp+3Ch] [ebp-14h]
  int tga_width; // [esp+40h] [ebp-10h]
  int tga_bits_per_pixel; // [esp+44h] [ebp-Ch]
  unsigned __int8 raw_data[4]; // [esp+48h] [ebp-8h] BYREF
  unsigned __int8 trans_data[4]; // [esp+4Ch] [ebp-4h]

  img_buffer = s->img_buffer;
  if ( img_buffer >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v8 = s->img_buffer;
      v7 = *v8;
      s->img_buffer = v8 + 1;
    }
    else
    {
      v7 = 0;
    }
  }
  else
  {
    v7 = *img_buffer;
    s->img_buffer = img_buffer + 1;
  }
  tga_offset = v7;
  v9 = s->img_buffer;
  if ( v9 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v11 = s->img_buffer;
      v10 = *v11;
      s->img_buffer = v11 + 1;
    }
    else
    {
      v10 = 0;
    }
  }
  else
  {
    v10 = *v9;
    s->img_buffer = v9 + 1;
  }
  tga_indexed = v10;
  v12 = s->img_buffer;
  if ( v12 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v14 = s->img_buffer;
      v13 = *v14;
      s->img_buffer = v14 + 1;
    }
    else
    {
      v13 = 0;
    }
  }
  else
  {
    v13 = *v12;
    s->img_buffer = v12 + 1;
  }
  v15 = v13;
  tga_is_RLE = 0;
  tga_palette_start = get16le(s);
  tga_palette_len = get16le(s);
  v16 = s->img_buffer;
  if ( v16 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v18 = s->img_buffer;
      v17 = *v18;
      s->img_buffer = v18 + 1;
    }
    else
    {
      v17 = 0;
    }
  }
  else
  {
    v17 = *v16;
    s->img_buffer = v16 + 1;
  }
  *(_DWORD *)raw_data = v17;
  get16le(s);
  get16le(s);
  tga_width = get16le(s);
  tga_height = get16le(s);
  v19 = s->img_buffer;
  if ( v19 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v21 = s->img_buffer;
      v20 = *v21;
      s->img_buffer = v21 + 1;
    }
    else
    {
      v20 = 0;
    }
  }
  else
  {
    v20 = *v19;
    s->img_buffer = v19 + 1;
  }
  v22 = v20;
  v23 = s->img_buffer;
  tga_bits_per_pixel = v22;
  if ( v23 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v25 = s->img_buffer;
      v24 = *v25;
      s->img_buffer = v25 + 1;
    }
    else
    {
      v24 = 0;
    }
  }
  else
  {
    v24 = *v23;
    s->img_buffer = v23 + 1;
  }
  tga_palette = nullptr;
  RLE_count = 0;
  RLE_repeating = 0;
  read_next_pixel = 1;
  if ( v15 >= 8 )
  {
    v15 -= 8;
    tga_is_RLE = 1;
  }
  tga_inverted = 1 - (((int)v24 >> 5) & 1);
  if ( tga_width < 1 || tga_height < 1 || (unsigned int)(v15 - 1) > 2 || v22 != 8 && v22 != 16 && v22 != 24 && v22 != 32 )
    return nullptr;
  if ( tga_indexed != 0 )
  {
    v22 = *(_DWORD *)raw_data;
    tga_bits_per_pixel = *(_DWORD *)raw_data;
  }
  *x = tga_width;
  *y = tga_height;
  if ( (unsigned int)(req_comp - 1) > 3 )
    req_comp = v22 / 8;
  *comp = v22 / 8;
  v60 = v22 / 8;
  tga_data = (unsigned __int8 *)operator new(nSize: req_comp * tga_width * tga_height);
  skip(n: tga_offset, s);
  if ( tga_indexed != 0 )
  {
    skip(n: tga_palette_start, s);
    tga_palette = (unsigned __int8 *)operator new(nSize: tga_palette_len * *(_DWORD *)raw_data / 8);
    if ( !getn(s, buffer: tga_palette, n: tga_palette_len * *(_DWORD *)raw_data / 8) )
      return nullptr;
  }
  v26 = 0;
  *(_DWORD *)trans_data = 0;
  if ( tga_width * tga_height > 0 )
  {
    v27 = req_comp;
    v28 = tga_data + 1;
    tga_offseta = tga_width * tga_height;
    v29 = *(_WORD *)raw_data;
    tga_palette_starta = (int)(tga_data + 1);
    while ( 1 )
    {
      if ( tga_is_RLE != 0 )
      {
        if ( RLE_count != 0 )
        {
          if ( RLE_repeating != 0 && read_next_pixel == 0 )
            goto LABEL_87;
        }
        else
        {
          v30 = s->img_buffer;
          if ( v30 >= s->img_buffer_end )
          {
            if ( s->from_file != 0 )
            {
              refill_buffer(s);
              v32 = s->img_buffer;
              v31 = *v32;
              s->img_buffer = v32 + 1;
            }
            else
            {
              v31 = 0;
            }
          }
          else
          {
            v31 = *v30;
            s->img_buffer = v30 + 1;
          }
          RLE_count = (v31 & 0x7F) + 1;
          RLE_repeating = (int)v31 >> 7;
        }
      }
      if ( tga_indexed != 0 )
        break;
      if ( tga_bits_per_pixel > 0 )
      {
        v40 = 0;
        v41 = raw_data;
        do
        {
          v42 = s->img_buffer;
          if ( v42 >= s->img_buffer_end )
          {
            if ( s->from_file != 0 )
            {
              refill_buffer(s);
              v44 = s->img_buffer;
              v43 = *v44;
              s->img_buffer = v44 + 1;
            }
            else
            {
              v43 = 0;
            }
          }
          else
          {
            v43 = *v42;
            s->img_buffer = v42 + 1;
          }
          *v41 = v43;
          v40 += 8;
          ++v41;
        }
        while ( v40 < tga_bits_per_pixel );
LABEL_79:
        v29 = *(_WORD *)raw_data;
      }
LABEL_80:
      switch ( tga_bits_per_pixel )
      {
        case 8:
          v26 = v29;
          trans_data[0] = v29;
          trans_data[1] = v29;
          trans_data[2] = v29;
          trans_data[3] = -1;
          break;
        case 16:
          v26 = v29;
          trans_data[0] = v29;
          trans_data[1] = v29;
          *(_WORD *)&trans_data[2] = v29;
          break;
        case 24:
          v26 = raw_data[2];
          trans_data[0] = raw_data[2];
          trans_data[1] = HIBYTE(v29);
          trans_data[2] = v29;
          trans_data[3] = -1;
          break;
        case 32:
          v26 = raw_data[2];
          trans_data[0] = raw_data[2];
          trans_data[1] = HIBYTE(v29);
          trans_data[2] = v29;
          trans_data[3] = raw_data[3];
          break;
        default:
          v26 = trans_data[0];
          break;
      }
      v28 = (_BYTE *)tga_palette_starta;
      v27 = req_comp;
      read_next_pixel = 0;
LABEL_87:
      switch ( v27 )
      {
        case 1:
          *(v28 - 1) = (unsigned __int16)(29 * trans_data[2] + 77 * v26 + 150 * trans_data[1]) >> 8;
          break;
        case 2:
          *(v28 - 1) = (unsigned __int16)(29 * trans_data[2] + 77 * v26 + 150 * trans_data[1]) >> 8;
          *v28 = trans_data[3];
          break;
        case 3:
          *(v28 - 1) = v26;
          *v28 = trans_data[1];
          goto LABEL_92;
        case 4:
          *(v28 - 1) = v26;
          *v28 = trans_data[1];
          v28[2] = trans_data[3];
LABEL_92:
          v28[1] = trans_data[2];
          break;
        default:
          break;
      }
      --RLE_count;
      v28 += v27;
      v45 = tga_offseta-- == 1;
      tga_palette_starta = (int)v28;
      if ( v45 )
        goto LABEL_94;
      v26 = trans_data[0];
    }
    v33 = s->img_buffer;
    if ( v33 >= s->img_buffer_end )
    {
      if ( s->from_file != 0 )
      {
        refill_buffer(s);
        v35 = s->img_buffer;
        v34 = *v35;
        s->img_buffer = v35 + 1;
      }
      else
      {
        v34 = 0;
      }
    }
    else
    {
      v34 = *v33;
      s->img_buffer = v33 + 1;
    }
    v36 = v34;
    if ( v34 >= tga_palette_len )
      v36 = 0;
    if ( tga_bits_per_pixel <= 0 )
      goto LABEL_80;
    v37 = 0;
    v38 = &tga_palette[v36 * v60];
    v39 = raw_data;
    do
    {
      *v39 = *v38;
      v37 += 8;
      ++v38;
      ++v39;
    }
    while ( v37 < tga_bits_per_pixel );
    goto LABEL_79;
  }
LABEL_94:
  if ( tga_inverted != 0 )
  {
    tga_offsetb = 0;
    v46 = req_comp * tga_width;
    v47 = 0;
    v48 = 0;
    do
    {
      if ( v46 > 0 )
      {
        v49 = &tga_data[v48];
        v50 = &tga_data[v48 + req_comp * tga_width * (tga_height - v47 - 1)];
        do
        {
          v51 = *v49;
          *v49 = *v50;
          *v50 = v51;
          --v46;
          ++v49;
          ++v50;
        }
        while ( v46 > 0 );
        v46 = req_comp * tga_width;
      }
      v47 = 2 * (tga_offsetb + 1);
      v48 += v46;
      ++tga_offsetb;
    }
    while ( v47 < tga_height );
  }
  if ( tga_palette != nullptr )
    free(pMem: tga_palette);
  return tga_data;
}

//------------------------------------------------------------------------------
// Address: 0x00408510
// Name: unsigned char __near * stbi_tga_load_from_file(struct _iobuf __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl stbi_tga_load_from_file(_iobuf *f, int *x, int *y, int *comp, int req_comp)
{
  stbi s; // [esp+0h] [ebp-A4h] BYREF

  s.img_file = f;
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.buflen = 128;
  s.from_file = 1;
  return tga_load(&s, x, y, comp, req_comp);
}

//------------------------------------------------------------------------------
// Address: 0x00408560
// Name: int stbi_psd_test_file(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl stbi_psd_test_file(_iobuf *f)
{
  int v1; // ebx
  int v2; // esi
  BOOL v3; // esi
  stbi s; // [esp+Ch] [ebp-A4h] BYREF

  v1 = ftell(stream: f);
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_file = f;
  s.buflen = 128;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.from_file = 1;
  v2 = get16(&s);
  v3 = (v2 << 16) + get16(&s) == 943870035;
  fseek(stream: f, offset: v1, whence: 0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004085E0
// Name: psd_load
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall psd_load@<eax>(stbi *s@<eax>, int *x, int *y, int *comp, int req_comp)
{
  int v6; // edi
  unsigned __int8 *result; // eax
  _iobuf *img_file; // edx
  int v9; // eax
  int v10; // ebx
  int v11; // ebx
  int v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // edx
  unsigned __int8 *v18; // ebx
  int v19; // ecx
  unsigned __int8 *img_buffer; // eax
  unsigned int v21; // edi
  unsigned __int8 *v22; // eax
  unsigned int v23; // edi
  unsigned __int8 *v24; // ecx
  unsigned __int8 v25; // al
  unsigned __int8 *v26; // ecx
  int v27; // edi
  unsigned __int8 v28; // cl
  unsigned __int8 *v29; // eax
  int v30; // edx
  unsigned __int8 *v31; // ebx
  int v32; // ecx
  int i; // edi
  unsigned __int8 *v34; // ecx
  unsigned __int8 v35; // al
  unsigned __int8 *v36; // ecx
  signed int h; // [esp+8h] [ebp-1Ch]
  unsigned int w; // [esp+Ch] [ebp-18h]
  int channelCount; // [esp+10h] [ebp-14h]
  unsigned __int8 *out; // [esp+14h] [ebp-10h]
  int channel; // [esp+18h] [ebp-Ch]
  int channela; // [esp+18h] [ebp-Ch]
  int count; // [esp+1Ch] [ebp-8h]
  int v44; // [esp+20h] [ebp-4h]

  v6 = get16(s);
  if ( (v6 << 16) + get16(s) != 943870035 )
  {
    failure_reason = "not PSD";
    return nullptr;
  }
  if ( get16(s) != 1 )
  {
    failure_reason = "wrong version";
    return nullptr;
  }
  img_file = s->img_file;
  if ( img_file != nullptr && (v9 = s->img_buffer_end - s->img_buffer) < 6 )
  {
    s->img_buffer = s->img_buffer_end;
    fseek(stream: img_file, offset: 6 - v9, whence: 1);
  }
  else
  {
    s->img_buffer += 6;
  }
  channelCount = get16(s);
  if ( (unsigned int)channelCount > 0x10 )
  {
    failure_reason = "wrong channel count";
    return nullptr;
  }
  else
  {
    v10 = get16(s);
    v11 = get16(s) + (v10 << 16);
    h = v11;
    v12 = get16(s);
    w = (v12 << 16) + get16(s);
    if ( get16(s) != 8 )
    {
      failure_reason = "unsupported bit depth";
      return nullptr;
    }
    if ( get16(s) != 3 )
    {
      failure_reason = "wrong color format";
      return nullptr;
    }
    v13 = get32(s);
    skip(n: v13, s);
    v14 = get32(s);
    skip(n: v14, s);
    v15 = get32(s);
    skip(n: v15, s);
    v16 = get16(s);
    if ( v16 > 1 )
    {
      failure_reason = "bad compression";
      return nullptr;
    }
    v44 = v11 * w;
    result = (unsigned __int8 *)operator new(nSize: 4 * v11 * w);
    out = result;
    if ( result == nullptr )
    {
      failure_reason = "outofmem";
      return result;
    }
    if ( v16 != 0 )
    {
      skip(n: 2 * channelCount * v11, s);
      v17 = 0;
      channel = 0;
      while ( 1 )
      {
        v18 = &out[v17];
        if ( v17 < channelCount )
          break;
        v19 = v44;
        if ( v44 > 0 )
        {
          do
          {
            *v18 = (v17 != 3) - 1;
            v18 += 4;
            --v19;
          }
          while ( v19 != 0 );
        }
LABEL_49:
        channel = ++v17;
        if ( v17 >= 4 )
          goto LABEL_66;
      }
      count = 0;
      if ( v44 <= 0 )
        goto LABEL_49;
      while ( 1 )
      {
        img_buffer = s->img_buffer;
        if ( img_buffer >= s->img_buffer_end )
        {
          if ( s->from_file == 0 )
          {
            v21 = 0;
LABEL_31:
            v23 = v21 + 1;
            for ( count += v23; v23 != 0; --v23 )
            {
              v24 = s->img_buffer;
              if ( v24 >= s->img_buffer_end )
              {
                if ( s->from_file != 0 )
                {
                  refill_buffer(s);
                  v26 = s->img_buffer;
                  v25 = *v26;
                  s->img_buffer = v26 + 1;
                }
                else
                {
                  v25 = 0;
                }
              }
              else
              {
                v25 = *v24;
                s->img_buffer = v24 + 1;
              }
              *v18 = v25;
              v18 += 4;
            }
            goto LABEL_47;
          }
          refill_buffer(s);
          img_buffer = s->img_buffer;
        }
        v21 = *img_buffer;
        v22 = img_buffer + 1;
        s->img_buffer = v22;
        if ( v21 != 128 )
        {
          if ( v21 >= 0x80 )
          {
            v27 = (v21 ^ 0xFF) + 2;
            if ( v22 >= s->img_buffer_end )
            {
              if ( s->from_file != 0 )
              {
                refill_buffer(s);
                v29 = s->img_buffer;
                v28 = *v29;
                s->img_buffer = v29 + 1;
              }
              else
              {
                v28 = 0;
              }
            }
            else
            {
              v28 = *v22;
              s->img_buffer = v22 + 1;
            }
            for ( count += v27; v27 != 0; --v27 )
            {
              *v18 = v28;
              v18 += 4;
            }
            goto LABEL_47;
          }
          goto LABEL_31;
        }
LABEL_47:
        if ( count >= v44 )
        {
          v17 = channel;
          goto LABEL_49;
        }
      }
    }
    v30 = 0;
    channela = 0;
    while ( 1 )
    {
      v31 = &result[v30];
      if ( v30 <= channelCount )
      {
        if ( v44 > 0 )
        {
          for ( i = v44; i != 0; --i )
          {
            v34 = s->img_buffer;
            if ( v34 >= s->img_buffer_end )
            {
              if ( s->from_file != 0 )
              {
                refill_buffer(s);
                v36 = s->img_buffer;
                v35 = *v36;
                v30 = channela;
                s->img_buffer = v36 + 1;
              }
              else
              {
                v35 = 0;
              }
            }
            else
            {
              v35 = *v34;
              s->img_buffer = v34 + 1;
            }
            *v31 = v35;
            v31 += 4;
          }
        }
      }
      else
      {
        v32 = v44;
        if ( v44 > 0 )
        {
          do
          {
            *v31 = (v30 != 3) - 1;
            v31 += 4;
            --v32;
          }
          while ( v32 != 0 );
        }
      }
      channela = ++v30;
      if ( v30 >= 4 )
        break;
      result = out;
    }
LABEL_66:
    if ( req_comp != 0 && req_comp != 4 )
    {
      out = convert_format(img_n: 4, req_comp, data: out, x: w, y: h);
      if ( out == nullptr )
        return nullptr;
    }
    if ( comp != nullptr )
      *comp = channelCount;
    *y = h;
    *x = w;
    return out;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004089E0
// Name: unsigned char __near * stbi_psd_load_from_file(struct _iobuf __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl stbi_psd_load_from_file(_iobuf *f, int *x, int *y, int *comp, int req_comp)
{
  stbi s; // [esp+0h] [ebp-A4h] BYREF

  s.img_file = f;
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.buflen = 128;
  s.from_file = 1;
  return psd_load(&s, x, y, comp, req_comp);
}

//------------------------------------------------------------------------------
// Address: 0x00408A30
// Name: pic_is4
// Source: json
//------------------------------------------------------------------------------
int __usercall pic_is4@<eax>(stbi *s@<esi>, const char *str)
{
  int v2; // ebx
  unsigned __int8 *img_buffer; // ecx
  int v4; // eax
  unsigned __int8 *buffer_start; // edi
  unsigned int v6; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx

  v2 = 0;
  while ( 1 )
  {
    img_buffer = s->img_buffer;
    if ( img_buffer >= s->img_buffer_end )
    {
      if ( s->from_file != 0 )
      {
        buffer_start = s->buffer_start;
        v6 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
        if ( v6 != 0 )
        {
          s->img_buffer = buffer_start;
          s->img_buffer_end = &buffer_start[v6];
        }
        else
        {
          s->from_file = 0;
          v7 = s->img_buffer_end - 1;
          s->img_buffer = v7;
          *v7 = 0;
        }
        v8 = s->img_buffer;
        v4 = *v8;
        s->img_buffer = v8 + 1;
      }
      else
      {
        v4 = 0;
      }
    }
    else
    {
      v4 = *img_buffer;
      s->img_buffer = img_buffer + 1;
    }
    if ( v4 != (unsigned __int8)str[v2] )
      break;
    if ( ++v2 >= 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408AE0
// Name: pic_test
// Source: json
//------------------------------------------------------------------------------
int __usercall pic_test@<eax>(stbi *s@<eax>)
{
  int result; // eax
  unsigned __int8 *img_buffer; // eax
  unsigned __int8 *buffer_start; // edi
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax
  int i; // [esp+4h] [ebp-4h]

  result = pic_is4(s, str: str);
  if ( result != 0 )
  {
    for ( i = 84; i != 0; --i )
    {
      img_buffer = s->img_buffer;
      if ( img_buffer >= s->img_buffer_end )
      {
        if ( s->from_file != 0 )
        {
          buffer_start = s->buffer_start;
          v5 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
          if ( v5 != 0 )
          {
            s->img_buffer = buffer_start;
            s->img_buffer_end = &buffer_start[v5];
          }
          else
          {
            s->from_file = 0;
            v6 = s->img_buffer_end - 1;
            s->img_buffer = v6;
            *v6 = 0;
          }
          ++s->img_buffer;
        }
      }
      else
      {
        s->img_buffer = img_buffer + 1;
      }
    }
    return pic_is4(s, str: "PICT") != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408BA0
// Name: pic_readval
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall pic_readval@<eax>(stbi *s@<esi>, int channel, unsigned __int8 *dest)
{
  int v3; // ebx
  unsigned __int8 *img_buffer; // ecx
  unsigned __int8 v5; // al
  unsigned __int8 *buffer_start; // edi
  unsigned int v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // ecx
  int mask; // [esp+8h] [ebp-4h]

  mask = 128;
  v3 = 0;
  while ( (channel & mask) == 0 )
  {
LABEL_16:
    mask >>= 1;
    if ( ++v3 >= 4 )
      return dest;
  }
  if ( s->img_file != nullptr )
  {
    if ( feof(stream: s->img_file) == 0 )
    {
LABEL_7:
      img_buffer = s->img_buffer;
      if ( img_buffer >= s->img_buffer_end )
      {
        if ( s->from_file != 0 )
        {
          buffer_start = s->buffer_start;
          v7 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
          if ( v7 != 0 )
          {
            s->img_buffer = buffer_start;
            s->img_buffer_end = &buffer_start[v7];
          }
          else
          {
            s->from_file = 0;
            v8 = s->img_buffer_end - 1;
            s->img_buffer = v8;
            *v8 = 0;
          }
          v9 = s->img_buffer;
          v5 = *v9;
          s->img_buffer = v9 + 1;
        }
        else
        {
          v5 = 0;
        }
      }
      else
      {
        v5 = *img_buffer;
        s->img_buffer = img_buffer + 1;
      }
      dest[v3] = v5;
      goto LABEL_16;
    }
    if ( s->from_file == 0 )
      goto LABEL_18;
  }
  if ( s->img_buffer < s->img_buffer_end )
    goto LABEL_7;
LABEL_18:
  failure_reason = "bad file";
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00408CA0
// Name: pic_load2
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall pic_load2@<eax>(stbi *s@<eax>, int width, int height, int *comp, unsigned __int8 *result)
{
  int v6; // ecx
  pic_packet_t *i; // eax
  unsigned __int8 *img_buffer; // eax
  unsigned __int8 *buffer_start; // edi
  unsigned int v10; // eax
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 v14; // bl
  unsigned __int8 *v15; // edi
  unsigned int v16; // eax
  unsigned __int8 *v17; // eax
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // eax
  unsigned __int8 v20; // cl
  unsigned __int8 *v21; // edi
  unsigned int v22; // eax
  unsigned __int8 *v23; // eax
  unsigned __int8 *v24; // eax
  unsigned __int8 *v25; // ecx
  unsigned __int8 v26; // al
  unsigned __int8 *v27; // edi
  unsigned int v28; // eax
  unsigned __int8 *v29; // eax
  unsigned __int8 *v30; // ecx
  unsigned __int8 *v32; // edi
  unsigned __int8 *v33; // eax
  int v34; // ebx
  unsigned __int8 *v35; // ebx
  unsigned int v36; // eax
  unsigned __int8 *v37; // eax
  unsigned __int8 *v38; // eax
  int v39; // ebx
  unsigned __int8 *v40; // edx
  int v41; // ecx
  unsigned __int8 *v42; // eax
  int k; // edi
  bool v44; // zf
  int v45; // ebx
  unsigned __int8 *v46; // eax
  unsigned __int8 v47; // bl
  unsigned __int8 *v48; // ebx
  unsigned int v49; // eax
  unsigned __int8 *v50; // eax
  unsigned __int8 *v51; // eax
  _iobuf *img_file; // eax
  int v53; // ebx
  int v54; // eax
  unsigned __int8 *v55; // edx
  int v56; // ecx
  unsigned __int8 *v57; // eax
  int j; // edi
  int v59; // ebx
  pic_packet_t packets[10]; // [esp+Ch] [ebp-50h] BYREF
  unsigned __int8 value[4]; // [esp+2Ch] [ebp-30h] BYREF
  unsigned __int8 dest[4]; // [esp+30h] [ebp-2Ch] BYREF
  int y; // [esp+34h] [ebp-28h]
  int packet_idx; // [esp+38h] [ebp-24h]
  int channel; // [esp+3Ch] [ebp-20h]
  unsigned __int8 *v66; // [esp+40h] [ebp-1Ch]
  int num_packets; // [esp+44h] [ebp-18h]
  int left; // [esp+48h] [ebp-14h]
  int chained; // [esp+4Ch] [ebp-10h]
  int act_comp; // [esp+50h] [ebp-Ch]
  unsigned __int8 *p_channel; // [esp+54h] [ebp-8h]
  unsigned __int8 count; // [esp+5Bh] [ebp-1h]

  act_comp = 0;
  v6 = 0;
  for ( i = packets; ; i = (pic_packet_t *)y )
  {
    if ( v6 == 10 )
    {
LABEL_42:
      failure_reason = "bad format";
      return nullptr;
    }
    left = (int)i;
    y = (int)&i[1];
    img_buffer = s->img_buffer;
    num_packets = v6 + 1;
    if ( img_buffer >= s->img_buffer_end )
    {
      if ( s->from_file != 0 )
      {
        buffer_start = s->buffer_start;
        v10 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
        if ( v10 != 0 )
        {
          s->img_buffer = buffer_start;
          s->img_buffer_end = &buffer_start[v10];
        }
        else
        {
          v11 = s->img_buffer_end - 1;
          s->from_file = 0;
          s->img_buffer = v11;
          *v11 = 0;
        }
        v12 = s->img_buffer;
        chained = *v12;
        s->img_buffer = v12 + 1;
      }
      else
      {
        chained = 0;
      }
    }
    else
    {
      chained = *img_buffer;
      s->img_buffer = img_buffer + 1;
    }
    v13 = s->img_buffer;
    if ( v13 >= s->img_buffer_end )
    {
      if ( s->from_file != 0 )
      {
        v15 = s->buffer_start;
        v16 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
        if ( v16 != 0 )
        {
          s->img_buffer = v15;
          s->img_buffer_end = &v15[v16];
        }
        else
        {
          v17 = s->img_buffer_end - 1;
          s->from_file = 0;
          s->img_buffer = v17;
          *v17 = 0;
        }
        v18 = s->img_buffer;
        v14 = *v18;
        s->img_buffer = v18 + 1;
      }
      else
      {
        v14 = 0;
      }
    }
    else
    {
      v14 = *v13;
      s->img_buffer = v13 + 1;
    }
    v19 = s->img_buffer;
    *(_BYTE *)left = v14;
    if ( v19 >= s->img_buffer_end )
    {
      if ( s->from_file != 0 )
      {
        v21 = s->buffer_start;
        v22 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
        if ( v22 != 0 )
        {
          s->img_buffer = v21;
          s->img_buffer_end = &v21[v22];
        }
        else
        {
          s->from_file = 0;
          v23 = s->img_buffer_end - 1;
          s->img_buffer = v23;
          *v23 = 0;
        }
        v24 = s->img_buffer;
        v20 = *v24;
        s->img_buffer = v24 + 1;
      }
      else
      {
        v20 = 0;
      }
    }
    else
    {
      v20 = *v19;
      s->img_buffer = v19 + 1;
    }
    *(_BYTE *)(left + 1) = v20;
    v25 = s->img_buffer;
    if ( v25 >= s->img_buffer_end )
    {
      if ( s->from_file != 0 )
      {
        v27 = s->buffer_start;
        v28 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
        if ( v28 != 0 )
        {
          s->img_buffer = v27;
          s->img_buffer_end = &v27[v28];
        }
        else
        {
          s->from_file = 0;
          v29 = s->img_buffer_end - 1;
          s->img_buffer = v29;
          *v29 = 0;
        }
        v30 = s->img_buffer;
        v26 = *v30;
        s->img_buffer = v30 + 1;
      }
      else
      {
        v26 = 0;
      }
    }
    else
    {
      v26 = *v25;
      s->img_buffer = v25 + 1;
    }
    *(_BYTE *)(left + 2) = v26;
    act_comp |= v26;
    if ( s->img_file != nullptr )
    {
      if ( feof(stream: s->img_file) == 0 )
        goto LABEL_39;
      if ( s->from_file == 0 )
        goto LABEL_44;
    }
    if ( s->img_buffer >= s->img_buffer_end )
    {
LABEL_44:
      failure_reason = "bad file";
      return nullptr;
    }
LABEL_39:
    if ( v14 != 8 )
      goto LABEL_42;
    if ( chained == 0 )
      break;
    v6 = num_packets;
  }
  y = 0;
  *comp = ((act_comp & 0x10) != 0) + 3;
  if ( height <= 0 )
    return result;
  v66 = result;
  while ( 2 )
  {
    packet_idx = 0;
    if ( num_packets <= 0 )
    {
LABEL_117:
      v66 += 4 * width;
      if ( ++y >= height )
        return result;
      continue;
    }
    break;
  }
  p_channel = &packets[0].channel;
  while ( 2 )
  {
    v32 = v66;
    if ( *(p_channel - 1) == 0 )
    {
      v59 = 0;
      if ( width > 0 )
      {
        channel = *p_channel;
        do
        {
          if ( pic_readval(s, channel, dest: v32) == nullptr )
            return nullptr;
          ++v59;
          v32 += 4;
        }
        while ( v59 < width );
      }
      goto LABEL_116;
    }
    if ( *(p_channel - 1) == 1 )
    {
      left = width;
      if ( width <= 0 )
        goto LABEL_116;
      while ( 1 )
      {
        v46 = s->img_buffer;
        if ( v46 >= s->img_buffer_end )
        {
          if ( s->from_file != 0 )
          {
            v48 = s->buffer_start;
            v49 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
            if ( v49 != 0 )
            {
              s->img_buffer = v48;
              s->img_buffer_end = &v48[v49];
            }
            else
            {
              s->from_file = 0;
              v50 = s->img_buffer_end - 1;
              s->img_buffer = v50;
              *v50 = 0;
            }
            v51 = s->img_buffer;
            v47 = *v51;
            s->img_buffer = v51 + 1;
          }
          else
          {
            v47 = 0;
          }
        }
        else
        {
          v47 = *v46;
          s->img_buffer = v46 + 1;
        }
        img_file = s->img_file;
        count = v47;
        if ( img_file == nullptr )
          goto LABEL_98;
        if ( feof(stream: img_file) != 0 )
          break;
LABEL_99:
        if ( v47 > left )
          count = left;
        v53 = *p_channel;
        chained = v53;
        if ( pic_readval(s, channel: v53, dest: value) == nullptr )
          return nullptr;
        v54 = count;
        act_comp = count;
        if ( count != 0 )
        {
          v55 = (unsigned __int8 *)(value - v32);
          channel = count;
          do
          {
            v56 = 128;
            v57 = v32;
            for ( j = 4; j != 0; --j )
            {
              if ( (v56 & v53) != 0 )
              {
                *v57 = v57[(_DWORD)v55];
                v53 = chained;
              }
              ++v57;
              v56 >>= 1;
            }
            v55 -= 4;
            v44 = channel-- == 1;
            v32 = v57;
          }
          while ( !v44 );
          v54 = act_comp;
        }
        left -= v54;
        if ( left <= 0 )
          goto LABEL_116;
      }
      if ( s->from_file == 0 )
        goto LABEL_44;
LABEL_98:
      if ( s->img_buffer >= s->img_buffer_end )
        goto LABEL_44;
      goto LABEL_99;
    }
    if ( *(p_channel - 1) != 2 )
      goto LABEL_42;
    left = width;
    if ( width <= 0 )
    {
LABEL_116:
      p_channel += 3;
      if ( ++packet_idx >= num_packets )
        goto LABEL_117;
      continue;
    }
    break;
  }
  while ( 1 )
  {
    v33 = s->img_buffer;
    if ( v33 >= s->img_buffer_end )
    {
      if ( s->from_file != 0 )
      {
        v35 = s->buffer_start;
        v36 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
        if ( v36 != 0 )
        {
          s->img_buffer = v35;
          s->img_buffer_end = &v35[v36];
        }
        else
        {
          s->from_file = 0;
          v37 = s->img_buffer_end - 1;
          s->img_buffer = v37;
          *v37 = 0;
        }
        v38 = s->img_buffer;
        v34 = *v38;
        s->img_buffer = v38 + 1;
      }
      else
      {
        v34 = 0;
      }
    }
    else
    {
      v34 = *v33;
      s->img_buffer = v33 + 1;
    }
    if ( s->img_file != nullptr )
    {
      if ( feof(stream: s->img_file) == 0 )
        goto LABEL_65;
      if ( s->from_file == 0 )
        goto LABEL_44;
    }
    if ( s->img_buffer >= s->img_buffer_end )
      goto LABEL_44;
LABEL_65:
    if ( v34 < 128 )
      break;
    if ( v34 == 128 )
      v39 = get16(s);
    else
      v39 = v34 - 127;
    act_comp = v39;
    if ( v39 > left )
      goto LABEL_44;
    chained = *p_channel;
    if ( pic_readval(s, channel: chained, dest) == nullptr )
      return nullptr;
    if ( v39 > 0 )
    {
      v40 = (unsigned __int8 *)(dest - v32);
      channel = act_comp;
      do
      {
        v41 = 128;
        v42 = v32;
        for ( k = 4; k != 0; --k )
        {
          if ( (v41 & chained) != 0 )
            *v42 = v40[(_DWORD)v42];
          ++v42;
          v41 >>= 1;
        }
        v40 -= 4;
        v44 = channel-- == 1;
        v32 = v42;
      }
      while ( !v44 );
    }
LABEL_84:
    left -= act_comp;
    if ( left <= 0 )
      goto LABEL_116;
  }
  act_comp = v34 + 1;
  if ( v34 + 1 > left )
    goto LABEL_44;
  v45 = 0;
  if ( act_comp <= 0 )
    goto LABEL_84;
  chained = *p_channel;
  while ( pic_readval(s, channel: chained, dest: v32) != nullptr )
  {
    ++v45;
    v32 += 4;
    if ( v45 >= act_comp )
      goto LABEL_84;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004092E0
// Name: pic_load
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall pic_load@<eax>(stbi *s@<esi>, int *px, int *py, int *comp, int req_comp)
{
  int i; // ebx
  unsigned __int8 *img_buffer; // eax
  unsigned __int8 *buffer_start; // edi
  unsigned int v8; // eax
  unsigned __int8 *v9; // eax
  int v10; // ebx
  int v11; // edi
  _iobuf *img_file; // eax
  unsigned int v14; // edi
  int y; // [esp+8h] [ebp-8h]
  unsigned __int8 *v16; // [esp+Ch] [ebp-4h]

  for ( i = 92; i != 0; --i )
  {
    img_buffer = s->img_buffer;
    if ( img_buffer >= s->img_buffer_end )
    {
      if ( s->from_file != 0 )
      {
        buffer_start = s->buffer_start;
        v8 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
        if ( v8 != 0 )
        {
          s->img_buffer = buffer_start;
          s->img_buffer_end = &buffer_start[v8];
        }
        else
        {
          s->from_file = 0;
          v9 = s->img_buffer_end - 1;
          s->img_buffer = v9;
          *v9 = 0;
        }
        ++s->img_buffer;
      }
    }
    else
    {
      s->img_buffer = img_buffer + 1;
    }
  }
  v10 = get16(s);
  v11 = get16(s);
  img_file = s->img_file;
  y = v11;
  if ( img_file != nullptr )
  {
    if ( feof(stream: img_file) == 0 )
      goto LABEL_15;
    if ( s->from_file == 0 )
    {
LABEL_14:
      failure_reason = "bad file";
      return nullptr;
    }
  }
  if ( s->img_buffer >= s->img_buffer_end )
    goto LABEL_14;
LABEL_15:
  if ( 0x10000000 / v10 >= v11 )
  {
    get16(s);
    get16(s);
    get16(s);
    get16(s);
    v14 = 4 * v10 * v11;
    v16 = (unsigned __int8 *)operator new(nSize: v14);
    memset(dst: v16, value: 0xFFu, count: v14);
    if ( pic_load2(s, width: v10, height: y, comp, result: v16) == nullptr )
    {
      free(pMem: v16);
      v16 = nullptr;
    }
    *px = v10;
    *py = y;
    if ( req_comp == 0 )
      req_comp = *comp;
    return convert_format(img_n: 4, req_comp, data: v16, x: v10, y);
  }
  else
  {
    failure_reason = "too large";
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409470
// Name: int stbi_pic_test_file(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl stbi_pic_test_file(_iobuf *f)
{
  int v1; // edi
  int v2; // ebx
  stbi s; // [esp+Ch] [ebp-A4h] BYREF

  v1 = ftell(stream: f);
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_file = f;
  s.buflen = 128;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.from_file = 1;
  v2 = pic_test(&s);
  fseek(stream: f, offset: v1, whence: 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004094D0
// Name: unsigned char __near * stbi_pic_load_from_file(struct _iobuf __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl stbi_pic_load_from_file(_iobuf *f, int *x, int *y, int *comp, int req_comp)
{
  stbi s; // [esp+4h] [ebp-A4h] BYREF

  s.img_file = f;
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.buflen = 128;
  s.from_file = 1;
  return pic_load(&s, px: x, py: y, comp, req_comp);
}

//------------------------------------------------------------------------------
// Address: 0x00409530
// Name: gif_test
// Source: json
//------------------------------------------------------------------------------
int __usercall gif_test@<eax>(stbi *s@<eax>)
{
  unsigned __int8 *img_buffer; // eax
  int v3; // ecx
  unsigned __int8 *v4; // eax
  int v5; // ecx
  unsigned __int8 *v6; // eax
  int v7; // ecx
  unsigned __int8 *v8; // eax
  int v9; // ecx
  unsigned __int8 *v10; // eax
  int v11; // ecx
  unsigned __int8 *v12; // eax
  int v13; // ecx

  img_buffer = s->img_buffer;
  if ( img_buffer >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      return 0;
    refill_buffer(s);
    img_buffer = s->img_buffer;
  }
  v3 = *img_buffer;
  v4 = img_buffer + 1;
  s->img_buffer = v4;
  if ( v3 == 71 )
  {
    if ( v4 >= s->img_buffer_end )
    {
      if ( s->from_file == 0 )
        return 0;
      refill_buffer(s);
      v4 = s->img_buffer;
    }
    v5 = *v4;
    v6 = v4 + 1;
    s->img_buffer = v6;
    if ( v5 == 73 )
    {
      if ( v6 >= s->img_buffer_end )
      {
        if ( s->from_file == 0 )
          return 0;
        refill_buffer(s);
        v6 = s->img_buffer;
      }
      v7 = *v6;
      v8 = v6 + 1;
      s->img_buffer = v8;
      if ( v7 == 70 )
      {
        if ( v8 >= s->img_buffer_end )
        {
          if ( s->from_file == 0 )
            return 0;
          refill_buffer(s);
          v8 = s->img_buffer;
        }
        v9 = *v8;
        v10 = v8 + 1;
        s->img_buffer = v10;
        if ( v9 == 56 )
        {
          if ( v10 >= s->img_buffer_end )
          {
            if ( s->from_file == 0 )
              return 0;
            refill_buffer(s);
            v10 = s->img_buffer;
          }
          v11 = *v10;
          v12 = v10 + 1;
          s->img_buffer = v12;
          if ( v11 != 57 && v11 != 55 )
            return 0;
          if ( v12 >= s->img_buffer_end )
          {
            if ( s->from_file == 0 )
              return 0;
            refill_buffer(s);
            v12 = s->img_buffer;
          }
          v13 = *v12;
          s->img_buffer = v12 + 1;
          if ( v13 == 97 )
            return 1;
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409670
// Name: int stbi_gif_test_file(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl stbi_gif_test_file(_iobuf *f)
{
  int v1; // edi
  int v2; // ebx
  stbi s; // [esp+Ch] [ebp-A4h] BYREF

  v1 = ftell(stream: f);
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_file = f;
  s.buflen = 128;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.from_file = 1;
  v2 = gif_test(&s);
  fseek(stream: f, offset: v1, whence: 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004096D0
// Name: stbi_gif_parse_colortable
// Source: json
//------------------------------------------------------------------------------
void __usercall stbi_gif_parse_colortable(stbi *s@<esi>, int num_entries@<eax>, unsigned __int8 (*pal)[4], int transp)
{
  unsigned __int8 *v4; // ebx
  unsigned __int8 *img_buffer; // ecx
  unsigned __int8 v6; // al
  unsigned __int8 *buffer_start; // edi
  unsigned int v8; // eax
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 v12; // cl
  unsigned __int8 *v13; // edi
  unsigned int v14; // eax
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // ecx
  unsigned __int8 v18; // al
  unsigned __int8 *v19; // edi
  unsigned int v20; // eax
  unsigned __int8 *v21; // eax
  unsigned __int8 *v22; // ecx
  int i; // [esp+0h] [ebp-8h]

  if ( num_entries > 0 )
  {
    v4 = &(*pal)[1];
    for ( i = num_entries; i != 0; --i )
    {
      img_buffer = s->img_buffer;
      if ( img_buffer >= s->img_buffer_end )
      {
        if ( s->from_file != 0 )
        {
          buffer_start = s->buffer_start;
          v8 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
          if ( v8 != 0 )
          {
            s->img_buffer = buffer_start;
            s->img_buffer_end = &buffer_start[v8];
          }
          else
          {
            s->from_file = 0;
            v9 = s->img_buffer_end - 1;
            s->img_buffer = v9;
            *v9 = 0;
          }
          v10 = s->img_buffer;
          v6 = *v10;
          s->img_buffer = v10 + 1;
        }
        else
        {
          v6 = 0;
        }
      }
      else
      {
        v6 = *img_buffer;
        s->img_buffer = img_buffer + 1;
      }
      v4[1] = v6;
      v11 = s->img_buffer;
      if ( v11 >= s->img_buffer_end )
      {
        if ( s->from_file != 0 )
        {
          v13 = s->buffer_start;
          v14 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
          if ( v14 != 0 )
          {
            s->img_buffer = v13;
            s->img_buffer_end = &v13[v14];
          }
          else
          {
            s->from_file = 0;
            v15 = s->img_buffer_end - 1;
            s->img_buffer = v15;
            *v15 = 0;
          }
          v16 = s->img_buffer;
          v12 = *v16;
          s->img_buffer = v16 + 1;
        }
        else
        {
          v12 = 0;
        }
      }
      else
      {
        v12 = *v11;
        s->img_buffer = v11 + 1;
      }
      *v4 = v12;
      v17 = s->img_buffer;
      if ( v17 >= s->img_buffer_end )
      {
        if ( s->from_file != 0 )
        {
          v19 = s->buffer_start;
          v20 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
          if ( v20 != 0 )
          {
            s->img_buffer = v19;
            s->img_buffer_end = &v19[v20];
          }
          else
          {
            s->from_file = 0;
            v21 = s->img_buffer_end - 1;
            s->img_buffer = v21;
            *v21 = 0;
          }
          v22 = s->img_buffer;
          v18 = *v22;
          s->img_buffer = v22 + 1;
        }
        else
        {
          v18 = 0;
        }
      }
      else
      {
        v18 = *v17;
        s->img_buffer = v17 + 1;
      }
      *(v4 - 1) = v18;
      v4[2] = (transp != 0) - 1;
      v4 += 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409890
// Name: stbi_gif_header
// Source: json
//------------------------------------------------------------------------------
int __usercall stbi_gif_header@<eax>(stbi *s@<ecx>, stbi_gif_struct *g@<eax>, int *comp, int is_info)
{
  unsigned __int8 *img_buffer; // eax
  int v7; // ecx
  unsigned __int8 *v8; // eax
  int v9; // ecx
  unsigned __int8 *v10; // eax
  int v11; // ecx
  unsigned __int8 *v12; // eax
  int v13; // ecx
  unsigned __int8 *v14; // eax
  unsigned __int8 v15; // cl
  unsigned __int8 *v16; // eax
  int v17; // ecx
  unsigned __int8 *v18; // ecx
  int v19; // eax
  unsigned __int8 *v20; // ecx
  unsigned __int8 *v21; // eax
  int v22; // ecx
  unsigned __int8 *v23; // eax
  unsigned __int8 *v24; // eax
  int v25; // ecx
  unsigned __int8 *v26; // eax
  int flags; // ecx

  img_buffer = s->img_buffer;
  if ( img_buffer >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      goto LABEL_47;
    refill_buffer(s);
    img_buffer = s->img_buffer;
  }
  v7 = *img_buffer;
  v8 = img_buffer + 1;
  s->img_buffer = v8;
  if ( v7 != 71 )
    goto LABEL_47;
  if ( v8 >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      goto LABEL_47;
    refill_buffer(s);
    v8 = s->img_buffer;
  }
  v9 = *v8;
  v10 = v8 + 1;
  s->img_buffer = v10;
  if ( v9 != 73 )
    goto LABEL_47;
  if ( v10 >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      goto LABEL_47;
    refill_buffer(s);
    v10 = s->img_buffer;
  }
  v11 = *v10;
  v12 = v10 + 1;
  s->img_buffer = v12;
  if ( v11 != 70 )
    goto LABEL_47;
  if ( v12 >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      goto LABEL_47;
    refill_buffer(s);
    v12 = s->img_buffer;
  }
  v13 = *v12;
  v14 = v12 + 1;
  s->img_buffer = v14;
  if ( v13 != 56 )
    goto LABEL_47;
  if ( v14 >= s->img_buffer_end )
  {
    if ( s->from_file == 0 )
      goto LABEL_47;
    refill_buffer(s);
    v14 = s->img_buffer;
  }
  v15 = *v14;
  v16 = v14 + 1;
  s->img_buffer = v16;
  if ( v15 != 55 && v15 != 57 )
    goto LABEL_47;
  if ( v16 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v16 = s->img_buffer;
      goto LABEL_25;
    }
LABEL_47:
    failure_reason = "not GIF";
    return 0;
  }
LABEL_25:
  v17 = *v16;
  s->img_buffer = v16 + 1;
  if ( v17 != 97 )
    goto LABEL_47;
  failure_reason = &defValue;
  g->w = get16le(s);
  g->h = get16le(s);
  v18 = s->img_buffer;
  if ( v18 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v20 = s->img_buffer;
      v19 = *v20;
      s->img_buffer = v20 + 1;
    }
    else
    {
      v19 = 0;
    }
  }
  else
  {
    v19 = *v18;
    s->img_buffer = v18 + 1;
  }
  g->flags = v19;
  v21 = s->img_buffer;
  if ( v21 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v23 = s->img_buffer;
      v22 = *v23;
      s->img_buffer = v23 + 1;
    }
    else
    {
      v22 = 0;
    }
  }
  else
  {
    v22 = *v21;
    s->img_buffer = v21 + 1;
  }
  g->bgindex = v22;
  v24 = s->img_buffer;
  if ( v24 >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v26 = s->img_buffer;
      v25 = *v26;
      s->img_buffer = v26 + 1;
    }
    else
    {
      v25 = 0;
    }
  }
  else
  {
    v25 = *v24;
    s->img_buffer = v24 + 1;
  }
  g->ratio = v25;
  g->transparent = -1;
  if ( comp != nullptr )
    *comp = 4;
  if ( is_info == 0 )
  {
    flags = g->flags;
    if ( (flags & 0x80u) != 0 )
      stbi_gif_parse_colortable(s, num_entries: 2 << (flags & 7), pal: g->pal, transp: -1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409B10
// Name: stbi_out_gif_code
// Source: json
//------------------------------------------------------------------------------
void __cdecl stbi_out_gif_code(stbi_gif_struct *g, unsigned __int16 code)
{
  int cur_y; // ecx
  unsigned __int8 *color_table; // edx
  unsigned __int8 *v4; // eax
  int suffix; // ecx
  bool v6; // cf
  unsigned __int8 *v7; // ecx
  int v8; // eax
  int parse; // ecx
  int v10; // eax
  int v11; // eax

  if ( g->codes[code].prefix >= 0 )
    stbi_out_gif_code(g, code: g->codes[code].prefix);
  cur_y = g->cur_y;
  if ( cur_y < g->max_y )
  {
    color_table = g->color_table;
    v4 = &g->out[g->cur_x + cur_y];
    suffix = g->codes[code].suffix;
    v6 = color_table[4 * suffix + 3] < 0x80u;
    v7 = &color_table[4 * suffix];
    if ( !v6 )
    {
      *v4 = v7[2];
      v4[1] = v7[1];
      v4[2] = *v7;
      v4[3] = v7[3];
    }
    g->cur_x += 4;
    if ( g->cur_x >= g->max_x )
    {
      g->cur_y += g->step;
      v8 = g->cur_y;
      g->cur_x = g->start_x;
      if ( v8 >= g->max_y )
      {
        do
        {
          parse = g->parse;
          if ( parse <= 0 )
            break;
          g->parse = parse - 1;
          v10 = g->line_size * (1 << parse);
          g->step = v10;
          v11 = g->start_y + (v10 >> 1);
          g->cur_y = v11;
        }
        while ( v11 >= g->max_y );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409C00
// Name: stbi_process_gif_raster
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall stbi_process_gif_raster@<eax>(stbi *s@<eax>, stbi_gif_struct *g)
{
  unsigned __int8 *img_buffer; // ecx
  unsigned __int8 v4; // al
  unsigned __int8 *v5; // ecx
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // ecx
  int v10; // edi
  unsigned __int8 *p_first; // edx
  unsigned __int8 *v12; // ecx
  int v13; // edx
  unsigned __int8 *buffer_start; // ebx
  unsigned int v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // eax
  unsigned __int8 *v18; // ecx
  int v19; // edx
  unsigned __int8 *v20; // ebx
  unsigned int v21; // eax
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // eax
  int v24; // edx
  int v25; // ebx
  stbi_gif_lzw_struct *v26; // edx
  int v27; // eax
  unsigned __int8 v28; // cl
  int v29; // edi
  _iobuf *img_file; // edi
  int v32; // ecx
  unsigned __int8 *v33; // ecx
  unsigned __int8 *v34; // edi
  unsigned int v35; // eax
  unsigned __int8 *v36; // eax
  int v37; // eax
  unsigned __int8 *v38; // edx
  _iobuf *v39; // ebx
  unsigned __int8 *v40; // ecx
  int v41; // [esp+Ch] [ebp-24h]
  unsigned int first; // [esp+10h] [ebp-20h]
  int clear; // [esp+14h] [ebp-1Ch]
  int p; // [esp+18h] [ebp-18h]
  int avail; // [esp+1Ch] [ebp-14h]
  int bits; // [esp+20h] [ebp-10h]
  int codesize; // [esp+24h] [ebp-Ch]
  int valid_bits; // [esp+28h] [ebp-8h]
  int len; // [esp+2Ch] [ebp-4h]

  img_buffer = s->img_buffer;
  if ( img_buffer >= s->img_buffer_end )
  {
    if ( s->from_file != 0 )
    {
      refill_buffer(s);
      v5 = s->img_buffer;
      v4 = *v5;
      s->img_buffer = v5 + 1;
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v4 = *img_buffer;
    s->img_buffer = img_buffer + 1;
  }
  v6 = v4;
  v7 = 1 << v4;
  v8 = 1 << ++v6;
  v41 = v6;
  codesize = v6;
  v9 = 0;
  v10 = v8 - 1;
  clear = v7;
  first = 1;
  bits = 0;
  valid_bits = 0;
  if ( v7 > 0 )
  {
    p_first = &g->codes[0].first;
    do
    {
      *p_first = v9;
      p_first[1] = v9;
      *((_WORD *)p_first - 1) = -1;
      ++v9;
      p_first += 4;
    }
    while ( v9 < v7 );
  }
  len = 0;
LABEL_10:
  p = -1;
  avail = v7 + 2;
  while ( 1 )
  {
    while ( valid_bits < codesize )
    {
      if ( len == 0 )
      {
        v12 = s->img_buffer;
        if ( v12 >= s->img_buffer_end )
        {
          if ( s->from_file == 0 )
            return g->out;
          buffer_start = s->buffer_start;
          v15 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
          if ( v15 != 0 )
          {
            s->img_buffer = buffer_start;
            s->img_buffer_end = &buffer_start[v15];
          }
          else
          {
            s->from_file = 0;
            v16 = s->img_buffer_end - 1;
            s->img_buffer = v16;
            *v16 = 0;
          }
          v17 = s->img_buffer;
          v13 = *v17;
          s->img_buffer = v17 + 1;
          v7 = clear;
        }
        else
        {
          v13 = *v12;
          s->img_buffer = v12 + 1;
        }
        len = v13;
        if ( v13 == 0 )
          return g->out;
      }
      v18 = s->img_buffer;
      --len;
      if ( v18 >= s->img_buffer_end )
      {
        if ( s->from_file != 0 )
        {
          v20 = s->buffer_start;
          v21 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
          if ( v21 != 0 )
          {
            s->img_buffer = v20;
            s->img_buffer_end = &v20[v21];
          }
          else
          {
            s->from_file = 0;
            v22 = s->img_buffer_end - 1;
            s->img_buffer = v22;
            *v22 = 0;
          }
          v23 = s->img_buffer;
          v24 = *v23 << valid_bits;
          s->img_buffer = v23 + 1;
          v7 = clear;
          bits |= v24;
          valid_bits += 8;
        }
        else
        {
          valid_bits += 8;
        }
      }
      else
      {
        v19 = *v18;
        s->img_buffer = v18 + 1;
        bits |= v19 << valid_bits;
        valid_bits += 8;
      }
    }
    v25 = v10 & bits;
    bits >>= codesize;
    valid_bits -= codesize;
    if ( v25 == v7 )
    {
      codesize = v41;
      first = 0;
      v10 = (1 << v41) - 1;
      goto LABEL_10;
    }
    if ( v25 == v7 + 1 )
    {
      img_file = s->img_file;
      if ( img_file != nullptr && (v32 = s->img_buffer_end - s->img_buffer) < len )
      {
        s->img_buffer = s->img_buffer_end;
        fseek(stream: img_file, offset: len - v32, whence: 1);
      }
      else
      {
        s->img_buffer += len;
      }
      while ( 1 )
      {
        v33 = s->img_buffer;
        if ( v33 >= s->img_buffer_end )
        {
          if ( s->from_file == 0 )
            return g->out;
          v34 = s->buffer_start;
          v35 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
          if ( v35 != 0 )
          {
            s->img_buffer = v34;
            s->img_buffer_end = &v34[v35];
          }
          else
          {
            s->from_file = 0;
            v36 = s->img_buffer_end - 1;
            s->img_buffer = v36;
            *v36 = 0;
          }
          v33 = s->img_buffer;
        }
        v37 = *v33;
        v38 = v33 + 1;
        s->img_buffer = v33 + 1;
        if ( v37 == 0 )
          break;
        v39 = s->img_file;
        if ( v39 != nullptr && (int)(v40 = (unsigned __int8 *)(s->img_buffer_end - v38)) < v37 )
        {
          s->img_buffer = s->img_buffer_end;
          fseek(stream: v39, offset: v37 - (_DWORD)v40, whence: 1);
        }
        else
        {
          s->img_buffer = &v38[v37];
        }
      }
      return g->out;
    }
    if ( v25 > avail )
      goto LABEL_62;
    if ( first != 0 )
    {
      failure_reason = "no clear code";
      return nullptr;
    }
    if ( p < 0 )
      break;
    v26 = &g->codes[avail];
    v27 = avail + 1;
    avail = v27;
    if ( v27 > 4096 )
    {
      failure_reason = "too many codes";
      return nullptr;
    }
    v26->prefix = p;
    v28 = g->codes[p].first;
    v26->first = v28;
    if ( v25 != v27 )
      v28 = g->codes[v25].first;
    v26->suffix = v28;
LABEL_40:
    stbi_out_gif_code(g, code: v25);
    if ( (avail & v10) == 0 && avail <= 4095 )
    {
      v29 = 1 << ++codesize;
      v10 = v29 - 1;
    }
    v7 = clear;
    p = v25;
  }
  if ( v25 != avail )
    goto LABEL_40;
LABEL_62:
  failure_reason = "illegal code in raster";
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040A010
// Name: stbi_fill_gif_background
// Source: json
//------------------------------------------------------------------------------
void __usercall stbi_fill_gif_background(stbi_gif_struct *g@<esi>)
{
  int v1; // edi
  unsigned __int8 *i; // ecx
  unsigned __int8 *v3; // eax

  v1 = 0;
  for ( i = g->pal[g->bgindex]; v1 < 4 * g->w * g->h; v1 += 4 )
  {
    v3 = &g->out[v1];
    *v3 = i[2];
    v3[1] = i[1];
    v3[2] = *i;
    v3[3] = i[3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A070
// Name: stbi_gif_load_next
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall stbi_gif_load_next@<eax>(stbi *s@<edi>, int *comp@<eax>, stbi_gif_struct *g, int req_comp)
{
  unsigned __int8 *out; // ebx
  unsigned __int8 *v5; // eax
  unsigned __int8 *result; // eax
  unsigned int v7; // esi
  unsigned __int8 *v8; // eax
  unsigned __int8 *img_buffer; // eax
  unsigned __int8 *buffer_start; // esi
  unsigned int v11; // eax
  unsigned __int8 *v12; // eax
  int v13; // ecx
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // esi
  unsigned int v16; // eax
  unsigned __int8 *v17; // eax
  int v18; // ecx
  unsigned __int8 *v19; // eax
  unsigned __int8 *v20; // ecx
  unsigned __int8 *v21; // esi
  unsigned int v22; // eax
  unsigned __int8 *v23; // eax
  int v24; // eax
  unsigned __int8 *v25; // ecx
  int v26; // eax
  _iobuf *img_file; // esi
  int v28; // ecx
  unsigned __int8 *v29; // esi
  unsigned int v30; // eax
  unsigned __int8 *v31; // eax
  unsigned __int8 *v32; // ecx
  unsigned __int8 *v33; // eax
  int v34; // ecx
  unsigned __int8 *v35; // esi
  unsigned int v36; // eax
  unsigned __int8 *v37; // eax
  unsigned __int8 *v38; // eax
  unsigned __int8 *v39; // ecx
  unsigned __int8 *v40; // esi
  unsigned int v41; // eax
  unsigned __int8 *v42; // eax
  int v43; // eax
  unsigned __int8 *v44; // edx
  _iobuf *v45; // ebx
  unsigned __int8 *v46; // ecx
  int v47; // esi
  int v48; // ebx
  int v49; // ecx
  int v50; // esi
  unsigned __int8 *v51; // eax
  int v52; // ecx
  unsigned __int8 *v53; // eax
  int v54; // eax
  unsigned __int8 *v55; // eax
  int i; // ecx
  int transparent; // eax
  int y; // [esp+8h] [ebp-8h]
  int h; // [esp+Ch] [ebp-4h]

  out = g->out;
  if ( out == nullptr )
  {
    if ( stbi_gif_header(s, g, comp, is_info: 0) != 0 )
    {
      v5 = (unsigned __int8 *)operator new(nSize: 4 * g->w * g->h);
      g->out = v5;
      if ( v5 != nullptr )
      {
        stbi_fill_gif_background(g);
        goto LABEL_9;
      }
LABEL_4:
      failure_reason = "outofmem";
      return nullptr;
    }
    return nullptr;
  }
  if ( (g->eflags & 0x1C) != 0xC )
    goto LABEL_9;
  v7 = 4 * g->w * g->h;
  v8 = (unsigned __int8 *)operator new(nSize: v7);
  g->out = v8;
  if ( v8 == nullptr )
    goto LABEL_4;
  memcpy(dst: v8, src: out, count: v7);
  while ( 1 )
  {
LABEL_9:
    img_buffer = s->img_buffer;
    if ( img_buffer >= s->img_buffer_end )
    {
      if ( s->from_file == 0 )
        goto LABEL_65;
      buffer_start = s->buffer_start;
      v11 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
      if ( v11 != 0 )
      {
        s->img_buffer = buffer_start;
        s->img_buffer_end = &buffer_start[v11];
      }
      else
      {
        s->from_file = 0;
        v12 = s->img_buffer_end - 1;
        s->img_buffer = v12;
        *v12 = 0;
      }
      img_buffer = s->img_buffer;
    }
    v13 = *img_buffer;
    v14 = img_buffer + 1;
    s->img_buffer = v14;
    if ( v13 != 33 )
      break;
    if ( v14 >= s->img_buffer_end )
    {
      if ( s->from_file == 0 )
        goto LABEL_51;
      v15 = s->buffer_start;
      v16 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
      if ( v16 != 0 )
      {
        s->img_buffer = v15;
        s->img_buffer_end = &v15[v16];
      }
      else
      {
        s->from_file = 0;
        v17 = s->img_buffer_end - 1;
        s->img_buffer = v17;
        *v17 = 0;
      }
      v14 = s->img_buffer;
    }
    v18 = *v14;
    v19 = v14 + 1;
    s->img_buffer = v19;
    if ( v18 == 249 )
    {
      v20 = v19;
      if ( v19 >= s->img_buffer_end )
      {
        if ( s->from_file == 0 )
        {
          v24 = 0;
          goto LABEL_33;
        }
        v21 = s->buffer_start;
        v22 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
        if ( v22 != 0 )
        {
          s->img_buffer = v21;
          s->img_buffer_end = &v21[v22];
        }
        else
        {
          s->from_file = 0;
          v23 = s->img_buffer_end - 1;
          s->img_buffer = v23;
          *v23 = 0;
        }
        v20 = s->img_buffer;
      }
      v24 = *v20;
      v25 = v20 + 1;
      s->img_buffer = v25;
      if ( v24 == 4 )
      {
        if ( v25 >= s->img_buffer_end )
        {
          if ( s->from_file != 0 )
          {
            v29 = s->buffer_start;
            v30 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
            if ( v30 != 0 )
            {
              s->img_buffer = v29;
              s->img_buffer_end = &v29[v30];
            }
            else
            {
              s->from_file = 0;
              v31 = s->img_buffer_end - 1;
              s->img_buffer = v31;
              *v31 = 0;
            }
            v32 = s->img_buffer;
            v26 = *v32;
            s->img_buffer = v32 + 1;
          }
          else
          {
            v26 = 0;
          }
        }
        else
        {
          v26 = *v25;
          s->img_buffer = v25 + 1;
        }
        g->eflags = v26;
        get16le(s);
        v33 = s->img_buffer;
        if ( v33 >= s->img_buffer_end )
        {
          if ( s->from_file != 0 )
          {
            v35 = s->buffer_start;
            v36 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
            if ( v36 != 0 )
            {
              s->img_buffer = v35;
              s->img_buffer_end = &v35[v36];
            }
            else
            {
              s->from_file = 0;
              v37 = s->img_buffer_end - 1;
              s->img_buffer = v37;
              *v37 = 0;
            }
            v38 = s->img_buffer;
            v34 = *v38;
            s->img_buffer = v38 + 1;
          }
          else
          {
            v34 = 0;
          }
        }
        else
        {
          v34 = *v33;
          s->img_buffer = v33 + 1;
        }
        g->transparent = v34;
        goto LABEL_51;
      }
LABEL_33:
      img_file = s->img_file;
      if ( img_file != nullptr && (v28 = s->img_buffer_end - s->img_buffer) < v24 )
      {
        s->img_buffer = s->img_buffer_end;
        fseek(stream: img_file, offset: v24 - v28, whence: 1);
      }
      else
      {
        s->img_buffer += v24;
      }
    }
    else
    {
      while ( 1 )
      {
LABEL_51:
        v39 = s->img_buffer;
        if ( v39 >= s->img_buffer_end )
        {
          if ( s->from_file == 0 )
            goto LABEL_9;
          v40 = s->buffer_start;
          v41 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
          if ( v41 != 0 )
          {
            s->img_buffer = v40;
            s->img_buffer_end = &v40[v41];
          }
          else
          {
            s->from_file = 0;
            v42 = s->img_buffer_end - 1;
            s->img_buffer = v42;
            *v42 = 0;
          }
          v39 = s->img_buffer;
        }
        v43 = *v39;
        v44 = v39 + 1;
        s->img_buffer = v39 + 1;
        if ( v43 == 0 )
          break;
        v45 = s->img_file;
        if ( v45 != nullptr && (int)(v46 = (unsigned __int8 *)(s->img_buffer_end - v44)) < v43 )
        {
          s->img_buffer = s->img_buffer_end;
          fseek(stream: v45, offset: v43 - (_DWORD)v46, whence: 1);
        }
        else
        {
          s->img_buffer = &v44[v43];
        }
      }
    }
  }
  if ( v13 == 44 )
  {
    v47 = get16le(s);
    y = get16le(s);
    v48 = get16le(s);
    h = get16le(s);
    if ( v48 + v47 > g->w || y + h > g->h )
    {
      failure_reason = "bad Image Descriptor";
    }
    else
    {
      v49 = 4 * g->w;
      g->line_size = v49;
      v50 = 4 * v47;
      g->start_x = v50;
      g->start_y = y * v49;
      g->max_x = v50 + 4 * v48;
      g->max_y = y * v49 + h * v49;
      g->cur_x = v50;
      g->cur_y = y * v49;
      v51 = s->img_buffer;
      if ( v51 >= s->img_buffer_end )
      {
        if ( s->from_file != 0 )
        {
          refill_buffer(s);
          v53 = s->img_buffer;
          v52 = *v53;
          s->img_buffer = v53 + 1;
        }
        else
        {
          v52 = 0;
        }
      }
      else
      {
        v52 = *v51;
        s->img_buffer = v51 + 1;
      }
      g->lflags = v52;
      if ( (v52 & 0x40) != 0 )
      {
        g->step = 8 * g->line_size;
        g->parse = 3;
      }
      else
      {
        g->step = g->line_size;
        g->parse = 0;
      }
      if ( (v52 & 0x80u) == 0 )
      {
        if ( SLOBYTE(g->flags) >= 0 )
        {
          failure_reason = "missing color table";
          return nullptr;
        }
        v55 = &g->pal[0][3];
        for ( i = 256; i != 0; --i )
        {
          *v55 = -1;
          v55 += 4;
        }
        transparent = g->transparent;
        if ( transparent >= 0 && (g->eflags & 1) != 0 )
          g->pal[transparent][3] = 0;
        g->color_table = g->pal[0];
      }
      else
      {
        if ( (g->eflags & 1) != 0 )
          v54 = g->transparent;
        else
          v54 = -1;
        stbi_gif_parse_colortable(s, num_entries: 2 << (v52 & 7), pal: g->lpal, transp: v54);
        g->color_table = g->lpal[0];
      }
      result = stbi_process_gif_raster(s, g);
      if ( result != nullptr )
      {
        if ( req_comp != 0 && req_comp != 4 )
          return convert_format(img_n: 4, req_comp, data: result, x: g->w, y: g->h);
        return result;
      }
    }
    return nullptr;
  }
  if ( v13 != 59 )
  {
LABEL_65:
    failure_reason = "unknown code";
    return nullptr;
  }
  return (unsigned __int8 *)1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A650
// Name: unsigned char __near * stbi_gif_load_from_file(struct _iobuf __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl stbi_gif_load_from_file(_iobuf *f, int *x, int *y, int *comp, int req_comp)
{
  unsigned __int8 *result; // eax
  stbi_gif_struct g; // [esp+4h] [ebp-48F0h] BYREF
  stbi s; // [esp+4850h] [ebp-A4h] BYREF

  memset(&g, 0, sizeof(g));
  s.img_file = f;
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.buflen = 128;
  s.from_file = 1;
  result = stbi_gif_load_next(&s, comp, &g, req_comp);
  if ( result == (unsigned __int8 *)1 )
    return nullptr;
  if ( result != nullptr )
  {
    *x = g.w;
    *y = g.h;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A6F0
// Name: hdr_test
// Source: json
//------------------------------------------------------------------------------
int __usercall hdr_test@<eax>(stbi *s@<esi>)
{
  const char *v1; // ebx
  unsigned __int8 *img_buffer; // ecx
  int v3; // eax
  unsigned __int8 *buffer_start; // edi
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ecx

  v1 = "#?RADIANCE\n";
  while ( 1 )
  {
    img_buffer = s->img_buffer;
    if ( img_buffer >= s->img_buffer_end )
    {
      if ( s->from_file != 0 )
      {
        buffer_start = s->buffer_start;
        v5 = fread(buffer: s->buffer_start, elementSize: 1u, count: s->buflen, stream: s->img_file);
        if ( v5 != 0 )
        {
          s->img_buffer = buffer_start;
          s->img_buffer_end = &buffer_start[v5];
        }
        else
        {
          s->from_file = 0;
          v6 = s->img_buffer_end - 1;
          s->img_buffer = v6;
          *v6 = 0;
        }
        v7 = s->img_buffer;
        v3 = *v7;
        s->img_buffer = v7 + 1;
      }
      else
      {
        v3 = 0;
      }
    }
    else
    {
      v3 = *img_buffer;
      s->img_buffer = img_buffer + 1;
    }
    if ( v3 != *v1 )
      break;
    if ( *++v1 == 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A7A0
// Name: int stbi_hdr_test_file(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl stbi_hdr_test_file(_iobuf *f)
{
  int v1; // ebx
  int v2; // esi
  stbi s; // [esp+Ch] [ebp-A4h] BYREF

  v1 = ftell(stream: f);
  s.img_file = f;
  s.buflen = 128;
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.from_file = 1;
  v2 = hdr_test(&s);
  fseek(stream: f, offset: v1, whence: 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0040A800
// Name: hdr_gettoken
// Source: json
//------------------------------------------------------------------------------
char *__usercall hdr_gettoken@<eax>(stbi *z@<eax>, char *buffer)
{
  unsigned __int8 *img_buffer; // eax
  int v4; // edi
  unsigned __int8 v5; // cl
  unsigned __int8 *v6; // eax
  char v7; // bl
  unsigned __int8 *v8; // ecx
  unsigned __int8 v9; // al
  unsigned __int8 *v10; // edi
  unsigned int v11; // eax
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // ecx
  char v14; // al
  unsigned __int8 *v15; // eax
  unsigned __int8 *buffer_start; // edi
  unsigned int v17; // eax
  unsigned __int8 *v18; // eax
  int v19; // ecx
  int len; // [esp+Ch] [ebp-4h]

  img_buffer = z->img_buffer;
  v4 = 0;
  if ( img_buffer >= z->img_buffer_end )
  {
    if ( z->from_file != 0 )
    {
      refill_buffer(s: z);
      v6 = z->img_buffer;
      v5 = *v6;
      z->img_buffer = v6 + 1;
    }
    else
    {
      v5 = 0;
    }
  }
  else
  {
    v5 = *img_buffer;
    z->img_buffer = img_buffer + 1;
  }
  v7 = v5;
  while ( 1 )
  {
    if ( z->img_file != nullptr )
    {
      if ( feof(stream: z->img_file) == 0 )
        goto LABEL_11;
      if ( z->from_file == 0 )
        break;
    }
    if ( z->img_buffer >= z->img_buffer_end )
      break;
LABEL_11:
    if ( v7 == 10 )
      break;
    buffer[v4] = v7;
    len = ++v4;
    if ( v4 == 1023 )
    {
      while ( 1 )
      {
        if ( z->img_file == nullptr )
          goto LABEL_24;
        if ( feof(stream: z->img_file) != 0 )
          break;
LABEL_25:
        v15 = z->img_buffer;
        if ( v15 < z->img_buffer_end )
        {
LABEL_31:
          v19 = *v15;
          z->img_buffer = v15 + 1;
          if ( v19 == 10 )
            goto LABEL_32;
        }
        else if ( z->from_file != 0 )
        {
          buffer_start = z->buffer_start;
          v17 = fread(buffer: z->buffer_start, elementSize: 1u, count: z->buflen, stream: z->img_file);
          if ( v17 != 0 )
          {
            z->img_buffer = buffer_start;
            z->img_buffer_end = &buffer_start[v17];
          }
          else
          {
            z->from_file = 0;
            v18 = z->img_buffer_end - 1;
            z->img_buffer = v18;
            *v18 = 0;
          }
          v15 = z->img_buffer;
          v4 = len;
          goto LABEL_31;
        }
      }
      if ( z->from_file == 0 )
        break;
LABEL_24:
      if ( z->img_buffer >= z->img_buffer_end )
        break;
      goto LABEL_25;
    }
    v8 = z->img_buffer;
    if ( v8 >= z->img_buffer_end )
    {
      if ( z->from_file != 0 )
      {
        v10 = z->buffer_start;
        v11 = fread(buffer: z->buffer_start, elementSize: 1u, count: z->buflen, stream: z->img_file);
        if ( v11 != 0 )
        {
          z->img_buffer = v10;
          z->img_buffer_end = &v10[v11];
        }
        else
        {
          z->from_file = 0;
          v12 = z->img_buffer_end - 1;
          z->img_buffer = v12;
          *v12 = 0;
        }
        v13 = z->img_buffer;
        v14 = *v13;
        v4 = len;
        z->img_buffer = v13 + 1;
        v7 = v14;
      }
      else
      {
        v7 = 0;
      }
    }
    else
    {
      v9 = *v8;
      z->img_buffer = v8 + 1;
      v7 = v9;
    }
  }
LABEL_32:
  buffer[v4] = 0;
  return buffer;
}

//------------------------------------------------------------------------------
// Address: 0x0040A9E0
// Name: hdr_convert
// Source: json
//------------------------------------------------------------------------------
void __usercall hdr_convert(float *output@<edi>, unsigned __int8 *input@<esi>, int req_comp)
{
  unsigned __int8 v3; // al
  float f1; // [esp+10h] [ebp-4h]

  v3 = input[3];
  if ( v3 != 0 )
  {
    f1 = ldexp(x: 1.0, exp: (unsigned int)v3 - 136);
    if ( req_comp > 2 )
    {
      *output = (float)*input * f1;
      output[1] = (float)input[1] * f1;
      output[2] = (float)input[2] * f1;
    }
    else
    {
      *output = (float)((float)(*input + input[1] + input[2]) * f1) * 0.33333334;
    }
    if ( req_comp == 2 )
    {
      output[1] = 1.0;
    }
    else if ( req_comp == 4 )
    {
      output[3] = 1.0;
    }
  }
  else
  {
    switch ( req_comp )
    {
      case 1:
        goto $LN1;
      case 2:
        output[1] = 1.0;
$LN1:
        *output = 0.0;
        return;
      case 3:
        goto $LN3_0;
      case 4:
        output[3] = 1.0;
$LN3_0:
        *(_QWORD *)(output + 1) = 0;
        *output = 0.0;
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AB10
// Name: hdr_load
// Source: json
//------------------------------------------------------------------------------
float *__cdecl hdr_load(stbi *s, int *x, int *y, int *comp, int req_comp)
{
  int v5; // edi
  char *v7; // eax
  int v8; // edi
  char *v9; // eax
  bool v10; // zf
  int v11; // eax
  int v12; // esi
  unsigned __int8 *img_buffer; // eax
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // eax
  int v18; // edx
  unsigned __int8 *v19; // eax
  unsigned __int8 *v20; // ecx
  int v21; // edx
  int v22; // eax
  unsigned __int8 *v23; // ecx
  unsigned __int8 *v24; // eax
  int v25; // ecx
  unsigned __int8 *v26; // eax
  unsigned __int8 v27; // dl
  unsigned __int8 *v28; // eax
  unsigned __int8 *v29; // edi
  unsigned __int8 *v30; // ecx
  unsigned __int8 v31; // al
  unsigned __int8 *v32; // eax
  unsigned __int8 v33; // cl
  int v34; // esi
  unsigned __int8 *v35; // eax
  unsigned __int8 *v36; // ecx
  unsigned __int8 *v37; // esi
  float *v38; // edi
  unsigned __int8 *v39; // ecx
  unsigned __int8 v40; // al
  unsigned __int8 *v41; // ecx
  char buffer[1024]; // [esp+Ch] [ebp-42Ch] BYREF
  int height; // [esp+40Ch] [ebp-2Ch]
  float *output; // [esp+410h] [ebp-28h]
  unsigned __int8 rgbe[4]; // [esp+414h] [ebp-24h] BYREF
  float *hdr_data; // [esp+418h] [ebp-20h]
  int width; // [esp+41Ch] [ebp-1Ch]
  unsigned __int8 *scanline; // [esp+420h] [ebp-18h]
  int j; // [esp+424h] [ebp-14h]
  char *token; // [esp+428h] [ebp-10h] BYREF
  int c2; // [esp+42Ch] [ebp-Ch]
  int i; // [esp+430h] [ebp-8h]
  int c1; // [esp+434h] [ebp-4h] BYREF

  v5 = 0;
  if ( strcmp(hdr_gettoken(z: s, buffer), "#?RADIANCE") != 0 )
  {
    failure_reason = "not HDR";
    return nullptr;
  }
  v7 = hdr_gettoken(z: s, buffer);
  token = v7;
  if ( *v7 != 0 )
  {
    do
    {
      if ( strcmp(v7, "FORMAT=32-bit_rle_rgbe") == 0 )
        v5 = 1;
      v7 = hdr_gettoken(z: s, buffer);
      token = v7;
    }
    while ( *v7 != 0 );
    if ( v5 != 0 )
    {
      token = hdr_gettoken(z: s, buffer);
      if ( strncmp(first: token, last: "-Y ", count: 3u) != 0 )
        goto LABEL_10;
      token += 3;
      v8 = strtol(nptr: token, endptr: &token, ibase: 10);
      v9 = token;
      v10 = *token == 32;
      height = v8;
      if ( v10 )
      {
        do
          token = ++v9;
        while ( *v9 == 32 );
      }
      if ( strncmp(first: v9, last: "+X ", count: 3u) == 0 )
      {
        token += 3;
        v11 = strtol(nptr: token, endptr: nullptr, ibase: 10);
        v12 = v11;
        *x = v11;
        *y = v8;
        width = v11;
        *comp = 3;
        if ( req_comp == 0 )
          req_comp = 3;
        hdr_data = (float *)operator new(nSize: 4 * req_comp * v8 * v11);
        if ( (unsigned int)(v12 - 8) > 0x7FF7 )
        {
          j = 0;
          goto LABEL_86;
        }
        scanline = nullptr;
        j = 0;
        if ( v8 <= 0 )
        {
LABEL_76:
          free(pMem: scanline);
          return hdr_data;
        }
        else
        {
          *(_DWORD *)rgbe = 4 * req_comp * v12;
          output = hdr_data;
          while ( 1 )
          {
            img_buffer = s->img_buffer;
            if ( img_buffer >= s->img_buffer_end )
            {
              if ( s->from_file != 0 )
              {
                refill_buffer(s);
                v14 = s->img_buffer;
                c1 = *v14;
                s->img_buffer = v14 + 1;
              }
              else
              {
                c1 = 0;
              }
            }
            else
            {
              c1 = *img_buffer;
              s->img_buffer = img_buffer + 1;
            }
            v15 = s->img_buffer;
            if ( v15 >= s->img_buffer_end )
            {
              if ( s->from_file != 0 )
              {
                refill_buffer(s);
                v16 = s->img_buffer;
                c2 = *v16;
                s->img_buffer = v16 + 1;
              }
              else
              {
                c2 = 0;
              }
            }
            else
            {
              c2 = *v15;
              s->img_buffer = v15 + 1;
            }
            v17 = s->img_buffer;
            if ( v17 >= s->img_buffer_end )
            {
              if ( s->from_file != 0 )
              {
                refill_buffer(s);
                v19 = s->img_buffer;
                v18 = *v19;
                i = v18;
                s->img_buffer = v19 + 1;
              }
              else
              {
                v18 = 0;
              }
            }
            else
            {
              v18 = *v17;
              s->img_buffer = v17 + 1;
            }
            if ( c1 != 2 || c2 != 2 || (v18 & 0x80u) != 0 )
            {
              BYTE1(c1) = c2;
              v39 = s->img_buffer;
              BYTE2(c1) = v18;
              if ( v39 >= s->img_buffer_end )
              {
                if ( s->from_file != 0 )
                {
                  refill_buffer(s);
                  v41 = s->img_buffer;
                  v40 = *v41;
                  s->img_buffer = v41 + 1;
                }
                else
                {
                  v40 = 0;
                }
              }
              else
              {
                v40 = *v39;
                s->img_buffer = v39 + 1;
              }
              HIBYTE(c1) = v40;
              hdr_convert(output: hdr_data, input: (unsigned __int8 *)&c1, req_comp);
              i = 1;
              j = 0;
              free(pMem: scanline);
              while ( 1 )
              {
                getn(s, buffer: rgbe, n: 4);
                hdr_convert(output: &hdr_data[req_comp * (i + width * j)], input: rgbe, req_comp);
                v8 = height;
                v12 = width;
                ++i;
                while ( i >= v12 )
                {
                  ++j;
LABEL_86:
                  if ( j >= v8 )
                    return hdr_data;
                  i = 0;
                }
              }
            }
            v20 = s->img_buffer;
            v21 = v18 << 8;
            i = v21;
            if ( v20 >= s->img_buffer_end )
            {
              if ( s->from_file != 0 )
              {
                refill_buffer(s);
                v23 = s->img_buffer;
                v22 = *v23;
                v21 = i;
                s->img_buffer = v23 + 1;
              }
              else
              {
                v22 = 0;
              }
            }
            else
            {
              v22 = *v20;
              s->img_buffer = v20 + 1;
            }
            if ( (v21 | v22) != width )
              break;
            if ( scanline == nullptr )
              scanline = (unsigned __int8 *)operator new(nSize: 4 * width);
            for ( c2 = 0; c2 < 4; ++c2 )
            {
              i = 0;
              while ( i < width )
              {
                v24 = s->img_buffer;
                if ( v24 >= s->img_buffer_end )
                {
                  if ( s->from_file == 0 )
                  {
                    c1 = 0;
                    LOBYTE(v25) = 0;
LABEL_55:
                    if ( (_BYTE)v25 != 0 )
                    {
                      v29 = &scanline[4 * i + c2];
                      c1 = (unsigned __int8)v25;
                      i += (unsigned __int8)v25;
                      do
                      {
                        v30 = s->img_buffer;
                        if ( v30 >= s->img_buffer_end )
                        {
                          if ( s->from_file != 0 )
                          {
                            refill_buffer(s);
                            v36 = s->img_buffer;
                            v31 = *v36;
                            s->img_buffer = v36 + 1;
                          }
                          else
                          {
                            v31 = 0;
                          }
                        }
                        else
                        {
                          v31 = *v30;
                          s->img_buffer = v30 + 1;
                        }
                        *v29 = v31;
                        v29 += 4;
                        --c1;
                      }
                      while ( c1 != 0 );
                    }
                    continue;
                  }
                  refill_buffer(s);
                  v28 = s->img_buffer;
                  v25 = *v28;
                  v26 = v28 + 1;
                  c1 = v25;
                  s->img_buffer = v26;
                }
                else
                {
                  v25 = *v24;
                  v26 = v24 + 1;
                  c1 = v25;
                  s->img_buffer = v26;
                }
                if ( (unsigned __int8)v25 <= 0x80u )
                  goto LABEL_55;
                if ( v26 >= s->img_buffer_end )
                {
                  if ( s->from_file != 0 )
                  {
                    refill_buffer(s);
                    v32 = s->img_buffer;
                    v27 = *v32;
                    LOBYTE(v25) = c1;
                    s->img_buffer = v32 + 1;
                  }
                  else
                  {
                    v27 = 0;
                  }
                }
                else
                {
                  v27 = *v26;
                  s->img_buffer = v26 + 1;
                }
                v33 = v25 + 0x80;
                v34 = v33;
                if ( v33 != 0 )
                {
                  v35 = &scanline[4 * i + c2];
                  i += v33;
                  do
                  {
                    *v35 = v27;
                    v35 += 4;
                    --v34;
                  }
                  while ( v34 != 0 );
                }
              }
            }
            if ( width > 0 )
            {
              v37 = scanline;
              v38 = output;
              for ( c2 = width; c2 != 0; --c2 )
              {
                hdr_convert(output: v38, input: v37, req_comp);
                v38 += req_comp;
                v37 += 4;
              }
            }
            output = (float *)((char *)output + *(_DWORD *)rgbe);
            if ( ++j >= height )
              goto LABEL_76;
          }
          free(pMem: hdr_data);
          free(pMem: scanline);
          failure_reason = "invalid decoded scanline length";
          return nullptr;
        }
      }
      else
      {
LABEL_10:
        failure_reason = "unsupported data layout";
        return nullptr;
      }
    }
  }
  failure_reason = "unsupported format";
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040B120
// Name: float __near * stbi_hdr_load_from_file(struct _iobuf __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
float *__cdecl stbi_hdr_load_from_file(_iobuf *f, int *x, int *y, int *comp, int req_comp)
{
  stbi s; // [esp+0h] [ebp-A4h] BYREF

  s.img_file = f;
  s.img_buffer_end = (unsigned __int8 *)&s.from_file;
  s.img_buffer = (unsigned __int8 *)&s.from_file;
  s.buflen = 128;
  s.from_file = 1;
  return hdr_load(&s, x, y, comp, req_comp);
}

//------------------------------------------------------------------------------
// Address: 0x0040B180
// Name: writefv
// Source: json
//------------------------------------------------------------------------------
void __usercall writefv(_iobuf *f@<esi>, char *v@<ecx>, char *fmt)
{
  char v3; // al
  char *v4; // edi
  char v5; // dl
  __int16 v6; // bx
  int v7; // ebx
  char buffer; // [esp+1h] [ebp-1h] BYREF

  buffer = HIBYTE(v);
  v3 = *fmt;
  if ( *fmt != 0 )
  {
    v4 = v - 4;
    while ( 2 )
    {
      ++fmt;
      switch ( v3 )
      {
        case ' ':
          goto $LN6_0;
        case '1':
          v5 = v4[4];
          v4 += 4;
          buffer = v5;
          fwrite(&buffer, size: 1u, count: 1u, stream: f);
          goto $LN6_0;
        case '2':
          v6 = *((_WORD *)v4 + 2);
          v4 += 4;
          buffer = v6;
          fwrite(&buffer, size: 1u, count: 1u, stream: f);
          buffer = HIBYTE(v6);
          fwrite(&buffer, size: 1u, count: 1u, stream: f);
          goto $LN6_0;
        case '4':
          v7 = *((_DWORD *)v4 + 1);
          v4 += 4;
          buffer = v7;
          fwrite(&buffer, size: 1u, count: 1u, stream: f);
          buffer = BYTE1(v7);
          fwrite(&buffer, size: 1u, count: 1u, stream: f);
          buffer = BYTE2(v7);
          fwrite(&buffer, size: 1u, count: 1u, stream: f);
          buffer = HIBYTE(v7);
          fwrite(&buffer, size: 1u, count: 1u, stream: f);
$LN6_0:
          v3 = *fmt;
          if ( *fmt == 0 )
            return;
          continue;
        default:
          return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B2A0
// Name: writef
// Source: json
//------------------------------------------------------------------------------
void __usercall writef(_iobuf *f@<esi>, char *fmt, ...)
{
  va_list v; // [esp+Ch] [ebp+Ch] BYREF

  va_start(v, fmt);
  writefv(f, v, fmt);
}

//------------------------------------------------------------------------------
// Address: 0x0040B2C0
// Name: write_pixels
// Source: json
//------------------------------------------------------------------------------
void __usercall write_pixels(
        int y@<eax>,
        char *data@<edx>,
        _iobuf *f,
        int rgb_dir,
        int vdir,
        int x,
        int comp,
        int write_alpha,
        unsigned int scanline_pad)
{
  int v9; // edi
  int v10; // ecx
  int v11; // ebx
  int v12; // esi
  char *v13; // edi
  int v14; // ebx
  int v15; // esi
  unsigned int v16; // ecx
  bool v17; // zf
  unsigned int zero; // [esp+8h] [ebp-20h] BYREF
  int v19; // [esp+Ch] [ebp-1Ch]
  int v20; // [esp+10h] [ebp-18h]
  int v21; // [esp+14h] [ebp-14h]
  int j_end; // [esp+18h] [ebp-10h]
  char *v23; // [esp+1Ch] [ebp-Ch]
  int j; // [esp+20h] [ebp-8h]
  unsigned __int8 px[4]; // [esp+24h] [ebp-4h]

  zero = 0;
  if ( vdir >= 0 )
  {
    j_end = y;
    j = 0;
    v9 = 0;
  }
  else
  {
    v9 = y - 1;
    j_end = -1;
    j = y - 1;
  }
  if ( v9 != j_end )
  {
    v10 = x;
    v11 = comp;
    v12 = comp * x * vdir;
    v19 = v12;
    v23 = &data[comp * x * v9 + 3];
    while ( 1 )
    {
      if ( v10 > 0 )
      {
        v13 = v23;
        v21 = v10;
        v20 = -1 - rgb_dir;
        while ( 2 )
        {
          if ( write_alpha < 0 )
            fwrite(buffer: &v13[v11 - 4], size: 1u, count: 1u, stream: f);
          v14 = v11 - 1;
          switch ( v14 )
          {
            case 0:
            case 1:
              writef(
                f,
                fmt: "111",
                (unsigned __int8)*(v13 - 3),
                (unsigned __int8)*(v13 - 3),
                (unsigned __int8)*(v13 - 3));
              goto LABEL_16;
            case 2:
              goto $LN6_1;
            case 3:
              if ( write_alpha != 0 )
              {
$LN6_1:
                writef(
                  f,
                  fmt: "111",
                  (unsigned __int8)v13[v20 - 1],
                  (unsigned __int8)*(v13 - 2),
                  (unsigned __int8)v13[rgb_dir - 2]);
LABEL_16:
                if ( write_alpha > 0 )
                  fwrite(buffer: &v13[v14 - 3], size: 1u, count: 1u, stream: f);
              }
              else
              {
                v15 = (unsigned __int8)*v13;
                v16 = v15 * (unsigned __int8)*(v13 - 2);
                px[0] = v15 * ((unsigned __int8)*(v13 - 3) - 255) / 255 - 1;
                px[2] = v15 * ((unsigned __int8)*(v13 - 1) - 255) / 255 - 1;
                px[1] = v16 / 0xFF;
                writef(f, fmt: "111", px[-rgb_dir + 1], px[1], px[rgb_dir + 1]);
              }
              v13 += comp;
              v17 = v21-- == 1;
              v11 = comp;
              if ( !v17 )
                continue;
              v12 = v19;
              v9 = j;
              break;
            default:
              goto LABEL_16;
          }
          break;
        }
      }
      fwrite(buffer: &zero, size: scanline_pad, count: 1u, stream: f);
      v9 += vdir;
      v23 += v12;
      j = v9;
      if ( v9 == j_end )
        break;
      v10 = x;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B4A0
// Name: outfile
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall outfile@<eax>(
        const char *filename@<eax>,
        int rgb_dir,
        int vdir,
        int x,
        int y,
        int comp,
        char *data,
        int alpha,
        unsigned int pad,
        char *fmt,
        ...)
{
  _iobuf *v10; // esi
  va_list v; // [esp+30h] [ebp+2Ch] BYREF

  va_start(v, fmt);
  v10 = fopen(file: filename, mode: "wb");
  if ( v10 != nullptr )
  {
    writefv(f: v10, v, fmt);
    write_pixels(y, data, f: v10, rgb_dir, vdir, x, comp, write_alpha: alpha, scanline_pad: pad);
    fclose(stream: v10);
  }
  return v10 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040B500
// Name: int stbi_write_bmp(char const __near *,int,int,int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl stbi_write_bmp(const char *filename, int x, int y, int comp, char *data)
{
  return outfile(
           filename,
           rgb_dir: -1,
           vdir: -1,
           x,
           y,
           comp,
           data,
           alpha: 0,
           pad: x & 3,
           fmt: "11 4 22 44 44 22 444444",
           66,
           77,
           y * (x + (x & 3) + 2 * x) + 54,
           0,
           0,
           54,
           40,
           x,
           y,
           1,
           24,
           0,
           0,
           0,
           0,
           0,
           0);
}

//------------------------------------------------------------------------------
// Address: 0x0040B560
// Name: char const __near * GetSubmissionURL(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetSubmissionURL(int bugid)
{
  char *result; // eax
  const char *v2; // eax

  result = (char *)g_bug_pReporter->GetSubmissionURL(this: g_bug_pReporter);
  if ( result == nullptr )
  {
    v2 = g_bug_pReporter->GetRepositoryURL(this: g_bug_pReporter);
    if ( v2 == nullptr )
      v2 = "\\\\fileserver\\bugs";
    V_snprintf(pDest: url, maxLen: 260, pFormat: "%s/%i", v2, bugid);
    return url;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B5B0
// Name: class IBugReporter __near * BugReporter_LoadDLL(char const __near *,struct HINSTANCE__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
IBugReporter *__cdecl BugReporter_LoadDLL(const char *pDLLName, HINSTANCE__ **phModule)
{
  HMODULE LibraryA; // eax
  HINSTANCE__ *v3; // edi
  FARPROC CreateInterface; // eax
  int v6; // eax
  int v7; // esi

  *phModule = nullptr;
  LibraryA = LoadLibraryA(lpLibFileName: pDLLName);
  v3 = LibraryA;
  if ( LibraryA == nullptr )
  {
    Sys_MessageBox(title: "Bug Error", format: "Could not open '%s'\n", pDLLName);
    return nullptr;
  }
  CreateInterface = GetProcAddress(hModule: LibraryA, lpProcName: "CreateInterface");
  if ( CreateInterface == nullptr )
  {
    Sys_MessageBox(title: "Bug Error", format: "Missing '%s' interface for '%s'\n", "CreateInterface", pDLLName);
    return nullptr;
  }
  v6 = ((int (__cdecl *)(const char *, _DWORD))CreateInterface)(a1: "BugReporter005", a2: 0);
  v7 = v6;
  if ( v6 == 0 )
  {
    Sys_MessageBox(title: "Bug Error", format: "Missing interface '%s' for '%s'\n", "BugReporter005", pDLLName);
    return nullptr;
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 4))(a1: v6, a2: 0) == 0 )
    return nullptr;
  *phModule = v3;
  return (IBugReporter *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x0040B670
// Name: bool BugReporter_GetInterfaces(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BugReporter_GetInterfaces()
{
  IBugReporter *DLL; // eax
  const char *v1; // eax
  _iobuf *v2; // esi
  const char *v3; // eax
  int v5; // [esp-4h] [ebp-108h]
  char fn[260]; // [esp+0h] [ebp-104h] BYREF

  DLL = g_bug_pReporter2;
  if ( g_bug_pReporter2 == nullptr )
  {
    DLL = BugReporter_LoadDLL(pDLLName: "bugreporter_filequeue.dll", phModule: &g_bug_hBugReporter2);
    g_bug_pReporter2 = DLL;
    if ( DLL == nullptr )
    {
      Sys_MessageBox(title: "Bug Error", format: "BugBait intialization failed!\n");
      DLL = g_bug_pReporter2;
    }
  }
  g_bug_pReporter = DLL;
  v1 = DLL->GetRepositoryURL(this: DLL);
  if ( v1 == nullptr )
    v1 = "\\\\fileserver\\bugs";
  V_snprintf(pDest: fn, maxLen: 260, pFormat: "%s/%s", v1, "info.txt");
  Sys_NormalizePath(path: fn, forceToLower: false);
  v2 = fopen(file: fn, mode: "rb");
  if ( v2 != nullptr )
  {
    v3 = (const char *)((int (__thiscall *)(IBugReporter *, int))g_bug_pReporter->GetRepositoryURL)(
                         a1: g_bug_pReporter,
                         a2: v5);
    if ( v3 == nullptr )
      v3 = "\\\\fileserver\\bugs";
    ConsoleWindowPrintf(rgb: 0xFFFF00u, strFormat: "*** Bug Reporter: Repository: '%s'\n", v3);
    fclose(stream: v2);
    return 1;
  }
  else
  {
    Sys_MessageBox(title: "Bug Error", format: "Unable to see '%s', check permissions and network connectivity.\n", fn);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B770
// Name: void BugReporter_FreeInterfaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugReporter_FreeInterfaces()
{
  if ( g_bug_pReporter2 != nullptr )
  {
    g_bug_pReporter2->Shutdown(this: g_bug_pReporter2);
    g_bug_pReporter2 = nullptr;
    FreeLibrary(hLibModule: g_bug_hBugReporter2);
    g_bug_hBugReporter2 = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B7B0
// Name: void BugReporter_DetermineSubmitter(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugReporter_DetermineSubmitter()
{
  const char *v0; // eax
  const char *v1; // eax

  if ( g_bug_szSubmitter[0] == 0 )
  {
    if ( g_bug_pReporter2 == nullptr )
      return;
    v0 = g_bug_pReporter2->GetUserDisplayName(this: g_bug_pReporter2);
    V_strncpy(pDest: g_bug_szSubmitter, pSrc: v0, maxLen: 128);
  }
  if ( g_bug_pReporter2 != nullptr )
  {
    v1 = g_bug_pReporter2->GetUserNameForDisplayName(this: g_bug_pReporter2, a2: g_bug_szSubmitter);
    ConsoleWindowPrintf(
      rgb: 0xFFFF00u,
      strFormat: "*** Bug Reporter: BugBait Username: '%s' Display As: '%s'\n",
      g_bug_szSubmitter,
      v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B810
// Name: void init_destination(struct jpeg_compress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl init_destination(jpeg_common_struct *cinfo)
{
  jpeg_destination_mgr *err; // esi
  int v2; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 4096);
  err[1].free_in_buffer = v2;
  err->next_output_byte = (unsigned __int8 *)v2;
  err->free_in_buffer = 4096;
}

//------------------------------------------------------------------------------
// Address: 0x0040B840
// Name: unsigned char empty_output_buffer(struct jpeg_compress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl empty_output_buffer(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // esi

  dest = cinfo->dest;
  CUtlBuffer::Put(this: (CUtlBuffer *)dest[1].next_output_byte, pMem: (const void *)dest[1].free_in_buffer, size: 4096);
  dest->next_output_byte = (unsigned __int8 *)dest[1].free_in_buffer;
  dest->free_in_buffer = 4096;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B870
// Name: void term_destination(struct jpeg_compress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl term_destination(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // eax

  dest = cinfo->dest;
  if ( dest->free_in_buffer != 4096 )
    CUtlBuffer::Put(
      this: (CUtlBuffer *)dest[1].next_output_byte,
      pMem: (const void *)dest[1].free_in_buffer,
      size: 4096 - dest->free_in_buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0040B8A0
// Name: void jpeg_UtlBuffer_dest(struct jpeg_compress_struct __near *,class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_UtlBuffer_dest(jpeg_common_struct *cinfo, CUtlBuffer *pBuffer)
{
  jpeg_destination_mgr *err; // eax

  if ( cinfo[1].err == nullptr )
    cinfo[1].err = (jpeg_error_mgr *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 28);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  err->init_destination = (void (__cdecl *)(jpeg_compress_struct *))init_destination;
  err->empty_output_buffer = empty_output_buffer;
  err->term_destination = term_destination;
  err[1].next_output_byte = (unsigned __int8 *)pBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x0040B8E0
// Name: void BugDlg_GetAppData(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_GetAppData(HWND__ *hWnd)
{
  HWND DlgItem; // eax
  HWND v2; // eax

  memset(dst: (unsigned __int8 *)&g_bug_mapInfo, value: 0, count: sizeof(g_bug_mapInfo));
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1073, lpString: &defValue);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1074, lpString: &defValue);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1075, lpString: &defValue);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1076, lpString: &defValue);
  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1061);
  EnableWindow(hWnd: DlgItem, bEnable: false);
  v2 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1060);
  EnableWindow(hWnd: v2, bEnable: false);
  if ( g_connectedToApp )
  {
    if ( g_bug_bFirstCommand )
    {
      ProcessCommand(strCmdIn: "vx_mapinfo");
    }
    else
    {
      g_bug_bFirstCommand = true;
      ProcessCommand(strCmdIn: "cmd bugpause ; vx_mapinfo");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B9A0
// Name: void BugDlg_GetDataFileBase(char const __near *,bool,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_GetDataFileBase(char *suffix, bool bLocalPath, char *buf, int bufsize)
{
  int v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  char filename[260]; // [esp+0h] [ebp-2ACh] BYREF
  char who[128]; // [esp+104h] [ebp-1A8h] BYREF
  char filepath[260]; // [esp+184h] [ebp-128h] BYREF
  tm t; // [esp+288h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &t);
  strncpy(dest: (unsigned __int8 *)who, source: (unsigned __int8 *)suffix, count: 0x80u);
  strlwr(string: who);
  if ( bLocalPath )
  {
    v4 = 0;
    do
    {
      v5 = g_localPath[v4];
      filepath[v4++] = v5;
    }
    while ( v5 != 0 );
    Sys_AddFileSeperator(path: filepath, pathLen: 260);
    v6 = &who[127];
    do
      v7 = *++v6;
    while ( v7 != 0 );
    strcpy(v6, "bug/");
    Sys_NormalizePath(path: filepath, forceToLower: false);
    Sys_CreatePath(pInPath: filepath);
  }
  else
  {
    filepath[0] = 0;
  }
  sprintf(string: filename, format: "%i_%02i_%02i_%s", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, who);
  V_snprintf(pDest: buf, maxLen: bufsize, pFormat: "%s%s", filepath, filename);
}

//------------------------------------------------------------------------------
// Address: 0x0040BAB0
// Name: bool BugDlg_CheckSubmit(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl BugDlg_CheckSubmit(HWND__ *hWnd)
{
  bool v1; // bl
  HWND DlgItem; // eax

  v1 = false;
  if ( g_bug_szTitle[0] != 0
    && g_bug_szDescription[0] != 0
    && g_bug_szSeverity[0] != 0
    && g_bug_szOwner[0] != 0
    && g_bug_szSubmitter[0] != 0
    && g_bug_szArea[0] != 0
    && g_bug_szMapNumber[0] != 0 )
  {
    v1 = g_bug_szCategory[0] != 0;
  }
  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1079);
  EnableWindow(hWnd: DlgItem, bEnable: v1);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0040BB20
// Name: bool BugDlg_GetChanges(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BugDlg_GetChanges(HWND__ *hWnd)
{
  LRESULT v1; // eax
  unsigned __int8 *v2; // eax
  LRESULT v3; // eax
  unsigned __int8 *v4; // eax
  LRESULT v5; // eax
  const char *v6; // eax
  LRESULT v7; // eax
  const char *v8; // eax

  GetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1057, lpString: g_bug_szTitle, cchMax: 512);
  GetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1058, lpString: g_bug_szDescription, cchMax: 4096);
  v1 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1080, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v1 == -1
    || (v2 = (unsigned __int8 *)g_bug_pReporter->GetDisplayName(this: g_bug_pReporter, a2: v1),
        strncpy(dest: (unsigned __int8 *)g_bug_szOwner, source: v2, count: 0x80u),
        byte_468C87 = 0,
        V_stristr(pStr: g_bug_szOwner, pSearch: "unassigned") != nullptr) )
  {
    g_bug_szOwner[0] = 0;
  }
  v3 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1081, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v3 == -1 )
  {
    g_bug_szSubmitter[0] = 0;
  }
  else
  {
    v4 = (unsigned __int8 *)g_bug_pReporter->GetDisplayName(this: g_bug_pReporter, a2: v3);
    strncpy(dest: (unsigned __int8 *)g_bug_szSubmitter, source: v4, count: 0x80u);
    byte_468D87 = 0;
  }
  v5 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1065, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v5 == -1 )
  {
    g_bug_szSeverity[0] = 0;
  }
  else
  {
    v6 = g_bug_pReporter->GetSeverity(this: g_bug_pReporter, a2: v5);
    V_strncpy(pDest: g_bug_szSeverity, pSrc: v6, maxLen: 128);
  }
  v7 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1082, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v7 == -1 )
  {
    g_bug_szCategory[0] = 0;
  }
  else
  {
    v8 = g_bug_pReporter->GetReportType(this: g_bug_pReporter, a2: v7);
    V_strncpy(pDest: g_bug_szCategory, pSrc: v8, maxLen: 128);
  }
  g_bug_bCompressScreenshot = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1083) != 0;
  g_bug_bLowerQualityScreenshot = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1084) != 0;
  BugDlg_CheckSubmit(hWnd);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040BCB0
// Name: bool BugDlg_OnAreaChanged(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl BugDlg_OnAreaChanged(HWND__ *hWnd)
{
  LRESULT v1; // eax
  const char *v2; // eax
  char szOldArea[260]; // [esp+0h] [ebp-104h] BYREF

  V_strncpy(pDest: szOldArea, pSrc: g_bug_szArea, maxLen: 260);
  v1 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1068, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v1 == -1 )
  {
    g_bug_szArea[0] = 0;
  }
  else
  {
    v2 = g_bug_pReporter->GetArea(this: g_bug_pReporter, a2: v1);
    V_strncpy(pDest: g_bug_szArea, pSrc: v2, maxLen: 128);
  }
  return _V_stricmp(s1: g_bug_szArea, s2: szOldArea) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040BD40
// Name: bool BugDlg_OnMapChanged(struct HWND__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BugDlg_OnMapChanged(HWND__ *hWnd, bool forceRefresh)
{
  LRESULT v2; // eax
  LRESULT v3; // esi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  WPARAM v8; // eax
  char szOldMap[260]; // [esp+Ch] [ebp-108h] BYREF
  int areaIndex; // [esp+110h] [ebp-4h]

  areaIndex = 0;
  v2 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1068, Msg: 0x158u, wParam: 0xFFFFFFFF, lParam: (LPARAM)g_bug_szArea);
  if ( v2 != -1 )
    areaIndex = v2;
  V_strncpy(pDest: szOldMap, pSrc: g_bug_szMapNumber, maxLen: 260);
  v3 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1078, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v3 == -1 )
  {
    g_bug_szMapNumber[0] = 0;
    return 0;
  }
  else
  {
    v5 = g_bug_pReporter->GetLevel(this: g_bug_pReporter, a2: areaIndex, a3: v3);
    V_strncpy(pDest: g_bug_szMapNumber, pSrc: v5, maxLen: 128);
    if ( forceRefresh || _V_stricmp(s1: g_bug_szMapNumber, s2: szOldMap) != 0 )
    {
      v6 = g_bug_pReporter->GetLevelOwner(this: g_bug_pReporter, a2: areaIndex, a3: v3);
      v7 = g_bug_pReporter->GetDisplayNameForUserName(this: g_bug_pReporter, a2: v6);
      v8 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1080, Msg: 0x158u, wParam: 0xFFFFFFFF, lParam: (LPARAM)v7);
      if ( v8 != -1 )
        SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1080, Msg: 0x14Eu, wParam: v8, lParam: 0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BE60
// Name: void BugDlg_SaveGame(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_SaveGame(HWND__ *hWnd)
{
  char *v1; // eax
  int i; // esi
  char buff[1024]; // [esp+0h] [ebp-724h] BYREF
  _DM_FILE_ATTRIBUTES fileAttributes; // [esp+400h] [ebp-324h] BYREF
  char savename[260]; // [esp+51Ch] [ebp-208h] BYREF
  char remoteFile[260]; // [esp+620h] [ebp-104h] BYREF

  if ( g_bug_mapInfo.savePath[0] != 0 )
  {
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1070, lpString: "Working...");
    v1 = (char *)g_bug_pReporter->GetUserNameA_2(this: g_bug_pReporter);
    BugDlg_GetDataFileBase(suffix: v1, bLocalPath: true, buf: g_bug_szSavegame, bufsize: 260);
    Sys_StripPath(inpath: g_bug_szSavegame, outpath: savename, outPathLen: 260);
    strcat(g_bug_szSavegame, ".360.sav");
    sprintf(string: remoteFile, format: "%s\\%s.360.sav", g_bug_mapInfo.savePath, savename);
    unlink(path: g_bug_szSavegame);
    DmDeleteFile(a1: remoteFile, a2: 0);
    sprintf(string: buff, format: "save \"%s\" notmostrecent wait", savename);
    if ( !ProcessCommand(strCmdIn: buff) )
      goto LABEL_7;
    for ( i = 0; i < 5; ++i )
    {
      if ( DmGetFileAttributes(a1: remoteFile, a2: &fileAttributes) == 47841280 )
        break;
      Sleep(dwMilliseconds: 0x3E8u);
    }
    if ( DmReceiveFileA(a1: g_bug_szSavegame, a2: remoteFile) != 47841280 )
LABEL_7:
      g_bug_szSavegame[0] = 0;
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1070, lpString: g_bug_szSavegame);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BFC0
// Name: void BugDlg_IncludeBSP(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_IncludeBSP(HWND__ *hWnd)
{
  char *v1; // eax

  if ( g_bug_mapInfo.mapPath[0] != 0 )
  {
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1071, lpString: "Working...");
    v1 = (char *)g_bug_pReporter->GetUserNameA_2(this: g_bug_pReporter);
    BugDlg_GetDataFileBase(suffix: v1, bLocalPath: true, buf: g_bug_szBSPName, bufsize: 260);
    strcat(g_bug_szBSPName, ".360.bsp");
    unlink(path: g_bug_szBSPName);
    if ( DmReceiveFileA(a1: g_bug_szBSPName, a2: g_bug_mapInfo.mapPath) != 47841280 )
      g_bug_szBSPName[0] = 0;
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1071, lpString: g_bug_szBSPName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C070
// Name: bool BugDlg_UploadFile(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BugDlg_UploadFile(const char *pLocalName, const char *pRemoteName, bool bDeleteLocal)
{
  int v3; // eax
  unsigned int v4; // ebx
  _iobuf *v5; // eax
  _iobuf *v6; // esi
  void *pLocalData; // [esp+Ch] [ebp-4h] BYREF

  ConsoleWindowPrintf(rgb: 0xFFFF00u, strFormat: "*** Bug Reporter: Uploading %s to %s\n", pLocalName, pRemoteName);
  v3 = Sys_LoadFile(filename: pLocalName, bufferptr: &pLocalData, bText: false);
  v4 = v3;
  if ( pLocalData != nullptr && v3 != 0 )
  {
    Sys_CreatePath(pInPath: pRemoteName);
    v5 = fopen(file: pRemoteName, mode: "wb");
    v6 = v5;
    if ( v5 != nullptr )
    {
      fwrite(buffer: pLocalData, size: v4, count: 1u, stream: v5);
      fclose(stream: v6);
      Sys_Free(ptr: pLocalData);
      if ( bDeleteLocal )
        unlink(path: pLocalName);
      return 1;
    }
    else
    {
      ConsoleWindowPrintf(
        rgb: 0xFFu,
        strFormat: "*** Bug Reporter: UploadFile: Unable to open remote path '%s'\n",
        pRemoteName);
      Sys_Free(ptr: pLocalData);
      return 0;
    }
  }
  else
  {
    ConsoleWindowPrintf(
      rgb: 0xFFu,
      strFormat: "*** Bug Reporter: UploadFile: Unable to open local path '%s'\n",
      pLocalName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C140
// Name: bool BugDlg_UploadBugSubmission(int,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BugDlg_UploadBugSubmission(
        int bugID,
        const char *pSavefile,
        const char *pScreenshot,
        const char *pBspFile)
{
  bool v4; // bl
  char *SubmissionURL; // eax
  char *v6; // eax
  char *v7; // eax
  char result; // al
  char szFilename[260]; // [esp+Ch] [ebp-30Ch] BYREF
  char szRemotefile[260]; // [esp+110h] [ebp-208h] BYREF
  char szLocalfile[260]; // [esp+214h] [ebp-104h] BYREF

  v4 = true;
  if ( pSavefile != nullptr && *pSavefile != 0 )
  {
    V_snprintf(pDest: szLocalfile, maxLen: 260, pFormat: "%s", pSavefile);
    Sys_StripPath(inpath: pSavefile, outpath: szFilename, outPathLen: 260);
    SubmissionURL = GetSubmissionURL(bugid: bugID);
    V_snprintf(pDest: szRemotefile, maxLen: 260, pFormat: "%s/%s", SubmissionURL, szFilename);
    Sys_NormalizePath(path: szLocalfile, forceToLower: false);
    Sys_NormalizePath(path: szRemotefile, forceToLower: false);
    v4 = BugDlg_UploadFile(pLocalName: szLocalfile, pRemoteName: szRemotefile, bDeleteLocal: false) != 0;
  }
  if ( pScreenshot != nullptr && *pScreenshot != 0 )
  {
    V_snprintf(pDest: szLocalfile, maxLen: 260, pFormat: "%s", pScreenshot);
    Sys_StripPath(inpath: pScreenshot, outpath: szFilename, outPathLen: 260);
    v6 = GetSubmissionURL(bugid: bugID);
    V_snprintf(pDest: szRemotefile, maxLen: 260, pFormat: "%s/%s", v6, szFilename);
    Sys_NormalizePath(path: szLocalfile, forceToLower: false);
    Sys_NormalizePath(path: szRemotefile, forceToLower: false);
    if ( BugDlg_UploadFile(pLocalName: szLocalfile, pRemoteName: szRemotefile, bDeleteLocal: true) == 0 )
      v4 = false;
  }
  if ( pBspFile == nullptr )
    return v4;
  if ( *pBspFile == 0 )
    return v4;
  V_snprintf(pDest: szLocalfile, maxLen: 260, pFormat: "%s", pBspFile);
  Sys_StripPath(inpath: pBspFile, outpath: szFilename, outPathLen: 260);
  v7 = GetSubmissionURL(bugid: bugID);
  V_snprintf(pDest: szRemotefile, maxLen: 260, pFormat: "%s/%s", v7, szFilename);
  Sys_NormalizePath(path: szLocalfile, forceToLower: false);
  Sys_NormalizePath(path: szRemotefile, forceToLower: false);
  result = BugDlg_UploadFile(pLocalName: szLocalfile, pRemoteName: szRemotefile, bDeleteLocal: true);
  if ( result != 0 )
    return v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C350
// Name: void BugDlg_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_SaveConfig()
{
  Sys_SetRegistryString(keyName: "bug_submitter", value: g_bug_szSubmitter);
  Sys_SetRegistryString(keyName: "bug_severity", value: g_bug_szSeverity);
  Sys_SetRegistryString(keyName: "bug_area", value: g_bug_szArea);
  Sys_SetRegistryInteger(keyName: "bug_compress", value: g_bug_bCompressScreenshot);
  Sys_SetRegistryInteger(keyName: "bug_lowerquality", value: g_bug_bLowerQualityScreenshot);
}

//------------------------------------------------------------------------------
// Address: 0x0040C3B0
// Name: void BugDlg_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_LoadConfig()
{
  Sys_GetRegistryString(keyName: "bug_submitter", value: g_bug_szSubmitter, defValue: &defValue, valueLen: 128);
  Sys_GetRegistryString(keyName: "bug_severity", value: g_bug_szSeverity, defValue: &defValue, valueLen: 128);
  Sys_GetRegistryString(keyName: "bug_area", value: g_bug_szArea, defValue: "Portal 2", valueLen: 128);
  Sys_GetRegistryInteger(keyName: "bug_compress", defValue: 1, value: &g_bug_bCompressScreenshot);
  Sys_GetRegistryInteger(keyName: "bug_lowerquality", defValue: 1, value: &g_bug_bLowerQualityScreenshot);
  V_strncpy(pDest: g_bug_szCategory, pSrc: "MAP", maxLen: 128);
  BugReporter_DetermineSubmitter();
}

//------------------------------------------------------------------------------
// Address: 0x0040C440
// Name: bool BugDlg_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BugDlg_Init()
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040C450
// Name: int rc_BugReporter(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_BugReporter()
{
  DebugCommand(pStrFormat: "0x%8.8x = BugReporter()\n", 0);
  if ( g_bug_hWnd == nullptr )
    PostMessageA(hWnd: g_hDlgMain, Msg: 0x111u, wParam: 0xC578u, lParam: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040C490
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x0040C4A0
// Name: _stbi_load_from_file
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl stbi_load_from_file(_iobuf *f, int *x, int *y, int *comp, int req_comp)
{
  int v6; // edi
  float *v7; // eax
  int v8; // edi
  png p; // [esp+4h] [ebp-B0h] BYREF

  if ( stbi_jpeg_test_file(f) != 0 )
    return stbi_jpeg_load_from_file(f, x, y, comp, req_comp);
  if ( stbi_png_test_file(f) != 0 )
  {
    p.s.img_buffer_end = (unsigned __int8 *)&p.s.from_file;
    p.s.img_buffer = (unsigned __int8 *)&p.s.from_file;
    p.s.img_file = f;
    p.s.buflen = 128;
    p.s.from_file = 1;
    return do_png(&p, req_comp, x, y, n: comp);
  }
  else if ( stbi_bmp_test_file(f) )
  {
    return stbi_bmp_load_from_file(f, x, y, comp, req_comp);
  }
  else if ( stbi_gif_test_file(f) != 0 )
  {
    return stbi_gif_load_from_file(f, x, y, comp, req_comp);
  }
  else if ( stbi_psd_test_file(f) )
  {
    return stbi_psd_load_from_file(f, x, y, comp, req_comp);
  }
  else if ( stbi_pic_test_file(f) != 0 )
  {
    return stbi_pic_load_from_file(f, x, y, comp, req_comp);
  }
  else if ( stbi_hdr_test_file(f) != 0 )
  {
    v6 = req_comp;
    v7 = stbi_hdr_load_from_file(f, x, y, comp, req_comp);
    if ( req_comp == 0 )
      v6 = *comp;
    return hdr_to_ldr(x: *x, data: v7, y: *y, comp: v6);
  }
  else
  {
    v8 = 0;
    if ( max_loaders <= 0 )
    {
LABEL_20:
      if ( stbi_tga_test_file(f) )
      {
        return stbi_tga_load_from_file(f, x, y, comp, req_comp);
      }
      else
      {
        failure_reason = "unknown image type";
        return nullptr;
      }
    }
    else
    {
      while ( loaders[v8]->test_file(a1: f) == 0 )
      {
        if ( ++v8 >= max_loaders )
          goto LABEL_20;
      }
      return loaders[v8]->load_from_file(a1: f, a2: x, a3: y, a4: comp, a5: req_comp);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C6C0
// Name: int rc_MapInfo(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_MapInfo(char *commandPtr)
{
  const char *Token; // eax
  const char *v2; // eax
  void (__stdcall *v3)(HWND, int, LPCSTR); // esi
  char *v4; // eax
  char *v5; // eax
  WPARAM v6; // eax
  BOOL v7; // eax
  HWND DlgItem; // eax
  HWND v9; // eax
  BOOL v11; // [esp+14h] [ebp-9Ch]
  BOOL v12; // [esp+14h] [ebp-9Ch]
  char buff[128]; // [esp+20h] [ebp-90h] BYREF
  int retVal; // [esp+A0h] [ebp-10h]
  int xboxRetVal; // [esp+A4h] [ebp-Ch] BYREF
  int retAddr; // [esp+A8h] [ebp-8h] BYREF
  int infoAddr; // [esp+ACh] [ebp-4h] BYREF

  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token != 0 )
  {
    sscanf(string: Token, format: "%x", &infoAddr);
    v2 = GetToken(ppTokenStream: &commandPtr);
    if ( *v2 != 0 )
    {
      sscanf(string: v2, format: "%x", &retAddr);
      DmGetMemory(a1: infoAddr, a2: 1568, a3: &g_bug_mapInfo, a4: 0);
      LODWORD(g_bug_mapInfo.position[0]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.position[0]));
      LODWORD(g_bug_mapInfo.position[1]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.position[1]));
      LODWORD(g_bug_mapInfo.position[2]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.position[2]));
      LODWORD(g_bug_mapInfo.angle[0]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.angle[0]));
      LODWORD(g_bug_mapInfo.angle[1]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.angle[1]));
      LODWORD(g_bug_mapInfo.angle[2]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.angle[2]));
      g_bug_mapInfo.build = _byteswap_ulong(g_bug_mapInfo.build);
      g_bug_mapInfo.skill = _byteswap_ulong(g_bug_mapInfo.skill);
      Sys_NormalizePath(path: g_bug_mapInfo.savePath, forceToLower: false);
      Sys_NormalizePath(path: g_bug_mapInfo.mapPath, forceToLower: false);
      if ( g_bug_hWnd != nullptr )
      {
        if ( g_bug_mapInfo.mapPath[0] != 0 )
        {
          Sys_StripPath(inpath: g_bug_mapInfo.mapPath, outpath: buff, outPathLen: 128);
          v3 = (void (__stdcall *)(HWND, int, LPCSTR))SetDlgItemTextA;
          SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1075, lpString: buff);
          v4 = V_stristr(pStr: buff, pSearch: ".bsp");
          if ( v4 != nullptr )
            *v4 = 0;
          v5 = V_stristr(pStr: buff, pSearch: ".360");
          if ( v5 != nullptr )
            *v5 = 0;
          v6 = SendDlgItemMessageA(
                 hDlg: g_bug_hWnd,
                 nIDDlgItem: 1078,
                 Msg: 0x158u,
                 wParam: 0xFFFFFFFF,
                 lParam: (LPARAM)buff);
          if ( v6 == -1 )
            v6 = 0;
          SendDlgItemMessageA(hDlg: g_bug_hWnd, nIDDlgItem: 1078, Msg: 0x14Eu, wParam: v6, lParam: 0);
          BugDlg_OnMapChanged(hWnd: g_bug_hWnd, forceRefresh: true);
          sprintf(
            string: buff,
            format: "%.2f %.2f %.2f",
            g_bug_mapInfo.position[0],
            g_bug_mapInfo.position[1],
            g_bug_mapInfo.position[2]);
          SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1073, lpString: buff);
          sprintf(
            string: buff,
            format: "%.2f %.2f %.2f",
            g_bug_mapInfo.angle[0],
            g_bug_mapInfo.angle[1],
            g_bug_mapInfo.angle[2]);
          SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1074, lpString: buff);
        }
        else
        {
          v3 = (void (__stdcall *)(HWND, int, LPCSTR))SetDlgItemTextA;
          SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1075, lpString: &defValue);
          SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1073, lpString: &defValue);
          SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1074, lpString: &defValue);
        }
        sprintf(string: buff, format: "%d", g_bug_mapInfo.build);
        v3(hDlg: g_bug_hWnd, nIDDlgItem: 1076, lpString: buff);
        v7 = g_bug_mapInfo.savePath[0] != 0 && g_bug_mapInfo.mapPath[0] != 0;
        v11 = v7;
        DlgItem = GetDlgItem(hDlg: g_bug_hWnd, nIDDlgItem: 1061);
        EnableWindow(hWnd: DlgItem, bEnable: v11);
        v12 = g_bug_mapInfo.mapPath[0] != 0;
        v9 = GetDlgItem(hDlg: g_bug_hWnd, nIDDlgItem: 1060);
        EnableWindow(hWnd: v9, bEnable: v12);
      }
      retVal = 0;
      xboxRetVal = 0;
      DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
      DebugCommand(pStrFormat: "0x%8.8x = MapInfo( 0x%8.8x )\n", 0, infoAddr);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040CA30
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0040CAA0
// Name: void BugDlg_TakeScreenshot(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_TakeScreenshot(HWND__ *hWnd)
{
  const char *v1; // eax
  CFmtStrN<256> *v2; // eax
  char v3; // bl
  int v4; // esi
  char *v5; // eax
  char *v6; // eax
  char v7; // cl
  _iobuf *v8; // esi
  char *v9; // edi
  char *v10; // eax
  char *v11; // eax
  char buff[1024]; // [esp+0h] [ebp-634h] BYREF
  _DM_FILE_ATTRIBUTES fileAttributes; // [esp+400h] [ebp-234h] BYREF
  CFmtStrN<256> v14; // [esp+51Ch] [ebp-118h] BYREF
  int nComps; // [esp+628h] [ebp-Ch] BYREF
  int nWidth; // [esp+62Ch] [ebp-8h] BYREF
  int nHeight; // [esp+630h] [ebp-4h] BYREF

  v1 = &defValue;
  if ( g_bug_bLowerQualityScreenshot == 0 )
    v1 = "Hiqher Quality - Please Wait";
  v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v14, pszFormat: "Working...%s", v1);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1069, lpString: v2->m_szBuf);
  v3 = 0;
  if ( g_bug_bLowerQualityScreenshot != 0 )
    goto LABEL_18;
  DmDeleteFile(a1: "d:\\_bug_.tga", a2: 0);
  sprintf(string: buff, format: "screenshot \"%s\"", "d:\\_bug_.tga");
  if ( !ProcessCommand(strCmdIn: buff) )
    goto LABEL_18;
  v4 = 0;
  while ( DmGetFileAttributes(a1: "d:\\_bug_.tga", a2: &fileAttributes) != 47841280 )
  {
    Sleep(dwMilliseconds: 0x3E8u);
    if ( ++v4 >= 10 )
      goto LABEL_18;
  }
  v5 = (char *)g_bug_pReporter->GetUserNameA_2(this: g_bug_pReporter);
  BugDlg_GetDataFileBase(suffix: v5, bLocalPath: true, buf: &v14.m_szBuf[3], bufsize: 260);
  v6 = &v14.m_szBuf[2];
  do
    v7 = *++v6;
  while ( v7 != 0 );
  strcpy(v6, ".tga");
  unlink(path: &v14.m_szBuf[3]);
  if ( DmReceiveFileA(a1: &v14.m_szBuf[3], a2: "d:\\_bug_.tga") < 0 )
    goto LABEL_18;
  nWidth = 0;
  nHeight = 0;
  nComps = 0;
  v8 = fopen(file: &v14.m_szBuf[3], mode: "rb");
  if ( v8 == nullptr )
  {
    failure_reason = "can't fopen";
LABEL_18:
    v11 = (char *)g_bug_pReporter->GetUserNameA_2(this: g_bug_pReporter);
    BugDlg_GetDataFileBase(suffix: v11, bLocalPath: true, buf: g_bug_szScreenshot, bufsize: 260);
    strcat(g_bug_szScreenshot, ".bmp");
    unlink(path: g_bug_szScreenshot);
    sprintf(string: buff, format: "*screenshot \"%s\"", g_bug_szScreenshot);
    if ( !ProcessCommand(strCmdIn: buff) )
      g_bug_szScreenshot[0] = 0;
    goto LABEL_20;
  }
  v9 = (char *)stbi_load_from_file(f: v8, x: &nWidth, y: &nHeight, comp: &nComps, req_comp: 4);
  fclose(stream: v8);
  if ( v9 == nullptr )
    goto LABEL_18;
  v10 = (char *)g_bug_pReporter->GetUserNameA_2(this: g_bug_pReporter);
  BugDlg_GetDataFileBase(suffix: v10, bLocalPath: true, buf: g_bug_szScreenshot, bufsize: 260);
  strcat(g_bug_szScreenshot, ".bmp");
  if ( stbi_write_bmp(filename: g_bug_szScreenshot, x: nWidth, y: nHeight, comp: 4, data: v9) )
  {
    remove(path: &v14.m_szBuf[3]);
    v3 = 1;
  }
  free(pMem: v9);
  if ( v3 == 0 )
    goto LABEL_18;
LABEL_20:
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1069, lpString: g_bug_szScreenshot);
}

//------------------------------------------------------------------------------
// Address: 0x0040CD40
// Name: void BugDlg_Populate(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_Populate(HWND__ *hWnd)
{
  int v1; // ebx
  bool v2; // zf
  const char *v3; // eax
  WPARAM v4; // eax
  int v5; // ebx
  bool v6; // zf
  const char *v7; // eax
  WPARAM v8; // eax
  int v9; // ebx
  bool v10; // zf
  const char *v11; // eax
  WPARAM v12; // eax
  int v13; // ebx
  bool v14; // zf
  const char *v15; // eax
  WPARAM v16; // eax
  int v17; // ebx
  bool v18; // zf
  const char *v19; // eax
  WPARAM v20; // eax
  WPARAM v21; // ebx
  HWND DlgItem; // eax
  int v23; // ebx
  bool v24; // zf
  const char *v25; // eax
  HWND v26; // eax
  WPARAM v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  bool v31; // al
  HWND v32; // eax
  BOOL v33; // [esp-4h] [ebp-18h]
  BOOL v34; // [esp-4h] [ebp-18h]
  BOOL v35; // [esp-4h] [ebp-18h]
  int areaIndex; // [esp+Ch] [ebp-8h]
  int count; // [esp+10h] [ebp-4h]
  int counta; // [esp+10h] [ebp-4h]
  int countb; // [esp+10h] [ebp-4h]
  int countc; // [esp+10h] [ebp-4h]
  int countd; // [esp+10h] [ebp-4h]
  int counte; // [esp+10h] [ebp-4h]

  g_bug_bActive = false;
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1057, Msg: 0xC5u, wParam: 0x1FFu, lParam: 0);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1057, lpString: g_bug_szTitle);
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1058, Msg: 0xC5u, wParam: 0xFFFu, lParam: 0);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1058, lpString: g_bug_szDescription);
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1080, Msg: 0x14Bu, wParam: 0, lParam: 0);
  v1 = 0;
  count = g_bug_pReporter->GetDisplayNameCount(this: g_bug_pReporter);
  v2 = count == 0;
  if ( count > 0 )
  {
    do
    {
      v3 = g_bug_pReporter->GetDisplayName(this: g_bug_pReporter, a2: v1);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1080, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v3);
      ++v1;
    }
    while ( v1 < count );
    v2 = count == 0;
  }
  if ( !v2 )
  {
    v4 = SendDlgItemMessageA(
           hDlg: hWnd,
           nIDDlgItem: 1080,
           Msg: 0x158u,
           wParam: 0xFFFFFFFF,
           lParam: (LPARAM)g_bug_szOwner);
    if ( v4 != -1 )
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1080, Msg: 0x14Eu, wParam: v4, lParam: 0);
  }
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1081, Msg: 0x14Bu, wParam: 0, lParam: 0);
  v5 = 0;
  counta = g_bug_pReporter->GetDisplayNameCount(this: g_bug_pReporter);
  v6 = counta == 0;
  if ( counta > 0 )
  {
    do
    {
      v7 = g_bug_pReporter->GetDisplayName(this: g_bug_pReporter, a2: v5);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1081, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v7);
      ++v5;
    }
    while ( v5 < counta );
    v6 = counta == 0;
  }
  if ( !v6 )
  {
    v8 = SendDlgItemMessageA(
           hDlg: hWnd,
           nIDDlgItem: 1081,
           Msg: 0x158u,
           wParam: 0xFFFFFFFF,
           lParam: (LPARAM)g_bug_szSubmitter);
    if ( v8 != -1 )
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1081, Msg: 0x14Eu, wParam: v8, lParam: 0);
  }
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1065, Msg: 0x14Bu, wParam: 0, lParam: 0);
  v9 = 0;
  countb = g_bug_pReporter->GetSeverityCount(this: g_bug_pReporter);
  v10 = countb == 0;
  if ( countb > 0 )
  {
    do
    {
      v11 = g_bug_pReporter->GetSeverity(this: g_bug_pReporter, a2: v9);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1065, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v11);
      ++v9;
    }
    while ( v9 < countb );
    v10 = countb == 0;
  }
  if ( !v10 )
  {
    v12 = SendDlgItemMessageA(
            hDlg: hWnd,
            nIDDlgItem: 1065,
            Msg: 0x158u,
            wParam: 0xFFFFFFFF,
            lParam: (LPARAM)g_bug_szSeverity);
    if ( v12 != -1 )
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1065, Msg: 0x14Eu, wParam: v12, lParam: 0);
  }
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1082, Msg: 0x14Bu, wParam: 0, lParam: 0);
  v13 = 0;
  countc = g_bug_pReporter->GetReportTypeCount(this: g_bug_pReporter);
  v14 = countc == 0;
  if ( countc > 0 )
  {
    do
    {
      v15 = g_bug_pReporter->GetReportType(this: g_bug_pReporter, a2: v13);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1082, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v15);
      ++v13;
    }
    while ( v13 < countc );
    v14 = countc == 0;
  }
  if ( !v14 )
  {
    v16 = SendDlgItemMessageA(
            hDlg: hWnd,
            nIDDlgItem: 1082,
            Msg: 0x158u,
            wParam: 0xFFFFFFFF,
            lParam: (LPARAM)g_bug_szCategory);
    if ( v16 != -1 )
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1082, Msg: 0x14Eu, wParam: v16, lParam: 0);
  }
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1068, Msg: 0x14Bu, wParam: 0, lParam: 0);
  v17 = 0;
  countd = g_bug_pReporter->GetAreaCount(this: g_bug_pReporter);
  areaIndex = 0;
  v18 = countd == 0;
  if ( countd > 0 )
  {
    do
    {
      v19 = g_bug_pReporter->GetArea(this: g_bug_pReporter, a2: v17);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1068, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v19);
      ++v17;
    }
    while ( v17 < countd );
    v18 = countd == 0;
  }
  if ( !v18 )
  {
    v20 = SendDlgItemMessageA(
            hDlg: hWnd,
            nIDDlgItem: 1068,
            Msg: 0x158u,
            wParam: 0xFFFFFFFF,
            lParam: (LPARAM)g_bug_szArea);
    v21 = v20;
    if ( v20 != -1 )
    {
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1068, Msg: 0x14Eu, wParam: v20, lParam: 0);
      areaIndex = v21;
    }
  }
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1078, Msg: 0x14Bu, wParam: 0, lParam: 0);
  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1078);
  EnableWindow(hWnd: DlgItem, bEnable: false);
  v23 = 0;
  counte = g_bug_pReporter->GetLevelCount(this: g_bug_pReporter, a2: areaIndex);
  v24 = counte == 0;
  if ( counte > 0 )
  {
    do
    {
      v25 = g_bug_pReporter->GetLevel(this: g_bug_pReporter, a2: areaIndex, a3: v23);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1078, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v25);
      ++v23;
    }
    while ( v23 < counte );
    v24 = counte == 0;
  }
  if ( !v24 )
  {
    v26 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1078);
    EnableWindow(hWnd: v26, bEnable: true);
    v27 = SendDlgItemMessageA(
            hDlg: hWnd,
            nIDDlgItem: 1078,
            Msg: 0x158u,
            wParam: 0xFFFFFFFF,
            lParam: (LPARAM)g_bug_szMapNumber);
    if ( v27 != -1 )
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1078, Msg: 0x14Eu, wParam: v27, lParam: 0);
  }
  CheckDlgButton(hDlg: hWnd, nIDButton: 1083, uCheck: g_bug_bCompressScreenshot != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1084, uCheck: g_bug_bLowerQualityScreenshot != 0);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1069, lpString: g_bug_szScreenshot);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1070, lpString: g_bug_szSavegame);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1071, lpString: g_bug_szBSPName);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1072, lpString: &defValue);
  v33 = g_connectedToApp;
  v28 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1063);
  EnableWindow(hWnd: v28, bEnable: v33);
  v29 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1062);
  EnableWindow(hWnd: v29, bEnable: false);
  v34 = g_connectedToApp;
  v30 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1059);
  EnableWindow(hWnd: v30, bEnable: v34);
  if ( g_connectedToApp )
    BugDlg_TakeScreenshot(hWnd);
  BugDlg_GetAppData(hWnd);
  v31 = false;
  if ( g_bug_szTitle[0] != 0
    && g_bug_szDescription[0] != 0
    && g_bug_szSeverity[0] != 0
    && g_bug_szOwner[0] != 0
    && g_bug_szSubmitter[0] != 0
    && g_bug_szArea[0] != 0
    && g_bug_szMapNumber[0] != 0 )
  {
    v31 = g_bug_szCategory[0] != 0;
  }
  v35 = v31;
  v32 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1079);
  EnableWindow(hWnd: v32, bEnable: v35);
  g_bug_bActive = true;
}

//------------------------------------------------------------------------------
// Address: 0x0040D200
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D240
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D290
// Name: bool BugDlg_CompressScreenshot(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl BugDlg_CompressScreenshot()
{
  HBITMAP__ *ImageA; // ebx
  HDC__ *CompatibleDC; // esi
  int v3; // esi
  int biWidth; // edi
  void *v5; // esp
  unsigned int next_scanline; // edx
  char *v7; // ecx
  int v8; // ebx
  int v9; // eax
  char *v10; // eax
  int v11; // esi
  _BYTE *v12; // ecx
  _BYTE *v13; // eax
  int v14; // eax
  char v15; // cl
  _BYTE v16[12]; // [esp+0h] [ebp-378h] BYREF
  jpeg_error_mgr jerr; // [esp+Ch] [ebp-36Ch] BYREF
  char jpgFilename[260]; // [esp+90h] [ebp-2E8h] BYREF
  jpeg_compress_struct cinfo; // [esp+194h] [ebp-1E4h] BYREF
  CUtlBuffer buf; // [esp+2FCh] [ebp-7Ch] BYREF
  tagBITMAPINFO bitmapInfo; // [esp+32Ch] [ebp-4Ch] BYREF
  HBITMAP__ *hBitmap; // [esp+358h] [ebp-20h]
  int nHeight; // [esp+35Ch] [ebp-1Ch]
  int nBitCount; // [esp+360h] [ebp-18h]
  char *pRowBuffer; // [esp+364h] [ebp-14h]
  unsigned __int8 *row_pointer[1]; // [esp+368h] [ebp-10h] BYREF
  HDC__ *hDC; // [esp+36Ch] [ebp-Ch]
  char *pBMPBits; // [esp+370h] [ebp-8h]
  bool bSuccess; // [esp+377h] [ebp-1h]

  if ( g_bug_szScreenshot[0] == 0 )
    return false;
  bSuccess = false;
  pBMPBits = nullptr;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  ImageA = (HBITMAP__ *)LoadImageA(hInst: nullptr, name: g_bug_szScreenshot, type: 0, cx: 0, cy: 0, fuLoad: 0x2050u);
  hBitmap = ImageA;
  if ( ImageA != nullptr )
  {
    CompatibleDC = CreateCompatibleDC(hdc: nullptr);
    hDC = CompatibleDC;
    if ( CompatibleDC != nullptr )
    {
      memset(dst: (unsigned __int8 *)&bitmapInfo, value: 0, count: sizeof(bitmapInfo));
      bitmapInfo.bmiHeader.biSize = 40;
      if ( GetDIBits(
             hdc: CompatibleDC,
             hbm: ImageA,
             start: 0,
             cLines: 0,
             lpvBits: nullptr,
             lpbmi: &bitmapInfo,
             usage: 0) != 0 )
      {
        pBMPBits = (char *)Sys_Alloc(size: bitmapInfo.bmiHeader.biSizeImage);
        if ( pBMPBits != nullptr )
        {
          v3 = abs32(bitmapInfo.bmiHeader.biHeight);
          nHeight = v3;
          nBitCount = bitmapInfo.bmiHeader.biBitCount;
          if ( (bitmapInfo.bmiHeader.biBitCount == 24 || bitmapInfo.bmiHeader.biBitCount == 32)
            && (bitmapInfo.bmiHeader.biCompression == 0 || bitmapInfo.bmiHeader.biCompression == 3) )
          {
            bitmapInfo.bmiHeader.biCompression = 0;
            if ( GetDIBits(hdc: hDC, hbm: ImageA, start: 0, cLines: v3, lpvBits: pBMPBits, lpbmi: &bitmapInfo, usage: 0) != 0 )
            {
              memset(dst: (unsigned __int8 *)&cinfo, value: 0, count: sizeof(cinfo));
              cinfo.err = jpeg_std_error(err: &jerr);
              jpeg_CreateCompress(&cinfo, version: 62, structsize: 0x168u);
              jpeg_UtlBuffer_dest((jpeg_common_struct *)&cinfo, pBuffer: &buf);
              cinfo.image_width = bitmapInfo.bmiHeader.biWidth;
              cinfo.image_height = v3;
              cinfo.input_components = 3;
              cinfo.in_color_space = JCS_RGB;
              jpeg_set_defaults(&cinfo);
              jpeg_set_quality(&cinfo, quality: 86, force_baseline: 1u);
              jpeg_start_compress(&cinfo, write_all_tables: 1u);
              biWidth = bitmapInfo.bmiHeader.biWidth;
              v5 = alloca(3 * bitmapInfo.bmiHeader.biWidth);
              next_scanline = cinfo.next_scanline;
              v7 = v16;
              pRowBuffer = v16;
              row_pointer[0] = v16;
              if ( cinfo.next_scanline < cinfo.image_height )
              {
                v8 = nBitCount >> 3;
                while ( 1 )
                {
                  if ( bitmapInfo.bmiHeader.biHeight >= 0 )
                    v9 = v8 * (v3 - next_scanline - 1);
                  else
                    v9 = next_scanline * v8;
                  v10 = &pBMPBits[biWidth * v9];
                  v11 = 0;
                  if ( biWidth > 0 )
                  {
                    v12 = v7 + 2;
                    v13 = v10 + 1;
                    do
                    {
                      *(v12 - 2) = v13[1];
                      *(v12 - 1) = *v13;
                      *v12 = *(v13 - 1);
                      ++v11;
                      v13 += v8;
                      v12 += 3;
                    }
                    while ( v11 < bitmapInfo.bmiHeader.biWidth );
                  }
                  jpeg_write_scanlines(&cinfo, scanlines: row_pointer, num_lines: 1u);
                  next_scanline = cinfo.next_scanline;
                  if ( cinfo.next_scanline >= cinfo.image_height )
                    break;
                  biWidth = bitmapInfo.bmiHeader.biWidth;
                  v3 = nHeight;
                  v7 = pRowBuffer;
                }
                ImageA = hBitmap;
              }
              jpeg_finish_compress(&cinfo);
              Sys_StripExtension(inpath: g_bug_szScreenshot, outpath: jpgFilename, outPathLen: 260);
              Sys_AddExtension(extension: ".jpg", outpath: jpgFilename, outPathLen: 260, bForce: true);
              if ( Sys_SaveFile(
                     filename: jpgFilename,
                     buffer: buf.m_Memory.m_pMemory,
                     count: buf.m_nMaxPut,
                     bText: false) )
              {
                unlink(path: g_bug_szScreenshot);
                v14 = 0;
                do
                {
                  v15 = jpgFilename[v14];
                  g_bug_szScreenshot[v14++] = v15;
                }
                while ( v15 != 0 );
                bSuccess = true;
              }
            }
          }
          CompatibleDC = hDC;
        }
      }
    }
    DeleteObject(ho: ImageA);
    if ( CompatibleDC != nullptr )
      DeleteDC(hdc: CompatibleDC);
    if ( pBMPBits != nullptr )
      Sys_Free(ptr: pBMPBits);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return bSuccess;
}

//------------------------------------------------------------------------------
// Address: 0x0040D5C0
// Name: bool BugDlg_Submit(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
bool __usercall BugDlg_Submit@<al>(int a1@<edi>, int a2@<esi>)
{
  char *v2; // eax
  char *v3; // eax
  const char *updated; // eax
  LRESULT v5; // esi
  LRESULT v6; // esi
  unsigned __int8 *m_pMemory; // edx
  LRESULT v8; // eax
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // cl
  IBugReporter_vtbl *v11; // esi
  const char *v12; // eax
  IBugReporter_vtbl *v13; // esi
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  bool v18; // bl
  char *SubmissionURL; // eax
  _iobuf *v21; // esi
  char v23[32768]; // [esp+20h] [ebp-10C6Ch] BYREF
  char buffer[32768]; // [esp+8020h] [ebp-8C6Ch] BYREF
  char v25[1024]; // [esp+10020h] [ebp-C6Ch] BYREF
  char String[260]; // [esp+10420h] [ebp-86Ch] BYREF
  char string[260]; // [esp+10524h] [ebp-768h] BYREF
  char file[260]; // [esp+10628h] [ebp-664h] BYREF
  char v29[260]; // [esp+1072Ch] [ebp-560h] BYREF
  char pDest[256]; // [esp+10830h] [ebp-45Ch] BYREF
  char out[260]; // [esp+10930h] [ebp-35Ch] BYREF
  char outpath[260]; // [esp+10A34h] [ebp-258h] BYREF
  char path[260]; // [esp+10B38h] [ebp-154h] BYREF
  _DWORD v34[5]; // [esp+10C3Ch] [ebp-50h] BYREF
  WPARAM wParam[2]; // [esp+10C50h] [ebp-3Ch] BYREF
  CUtlBuffer v36; // [esp+10C58h] [ebp-34h] BYREF
  int bugID; // [esp+10C88h] [ebp-4h] BYREF

  sprintf(string, format: "%f %f %f", g_bug_mapInfo.position[0], g_bug_mapInfo.position[1], g_bug_mapInfo.position[2]);
  SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1073, lpString: string);
  sprintf(string: String, format: "%f %f %f", g_bug_mapInfo.angle[0], g_bug_mapInfo.angle[1], g_bug_mapInfo.angle[2]);
  SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1074, lpString: String);
  sprintf(string: v29, format: "%d", g_bug_mapInfo.build);
  SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1076, lpString: v29);
  V_FileBase(in: g_bug_mapInfo.mapPath, out, maxlen: 260);
  v2 = V_stristr(pStr: out, pSearch: ".bsp");
  if ( v2 != nullptr )
    *v2 = 0;
  v3 = V_stristr(pStr: out, pSearch: ".360");
  if ( v3 != nullptr )
    *v3 = 0;
  updated = UpdateCurrentImageVersionString();
  if ( g_nActiveVersion == 0 || g_nActiveVersion == g_nImageVersion )
  {
    if ( *updated != 0 )
      FormatImageVersionString(pVersion: updated, pOutString: pDest, outSize: 256);
    else
      V_strncpy(pDest, pSrc: "Unknown Image Version", maxLen: 256);
  }
  else
  {
    V_snprintf(pDest, maxLen: 256, pFormat: "Active Image: %d\n", g_nActiveVersion);
  }
  v23[0] = 0;
  wParam[0] = 20;
  wParam[1] = 0;
  v5 = SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1010, Msg: 0x45Fu, (WPARAM)wParam, lParam: 0);
  if ( v5 != -2147024809 )
  {
    CUtlBuffer::CUtlBuffer(this: &v36, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::EnsureCapacity(this: &v36, num: v5);
    if ( (v36.m_Flags & 1) != 0 && v36.m_Put != 0 && v36.m_Memory.m_pMemory[v36.m_Put - v36.m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: &v36);
    if ( CUtlBuffer::CheckPut(this: &v36, nSize: 1) )
    {
      v36.m_Memory.m_pMemory[v36.m_Put - v36.m_nOffset] = 0;
      CUtlBuffer::AddNullTermination(this: &v36, nPut: ++v36.m_Put);
    }
    v34[0] = v5;
    memset(&v34[1], 0, 16);
    v6 = SendDlgItemMessageA(
           hDlg: g_hDlgMain,
           nIDDlgItem: 1010,
           Msg: 0x45Eu,
           wParam: (WPARAM)v34,
           lParam: (LPARAM)v36.m_Memory.m_pMemory);
    CUtlBuffer::SeekPut(this: &v36, type: SEEK_CURRENT, offset: v6);
    m_pMemory = v36.m_Memory.m_pMemory;
    v8 = 0;
    if ( (unsigned int)v6 > 0x8000 )
    {
      v8 = v6 - 0x8000;
      if ( v6 - 0x8000 >= v6 )
        goto LABEL_33;
      while ( 1 )
      {
        v9 = v36.m_Memory.m_pMemory[v8];
        if ( v9 == 0 || v9 == 10 || v9 == 13 )
          break;
        if ( ++v8 >= v6 )
          goto LABEL_33;
      }
      if ( v8 >= v6 )
        goto LABEL_33;
      while ( 1 )
      {
        v10 = v36.m_Memory.m_pMemory[v8];
        if ( v10 == 0 || v10 != 10 && v10 != 13 )
          break;
        if ( ++v8 >= v6 )
          goto LABEL_33;
      }
    }
    if ( v8 < v6 )
    {
      V_strncpy(pDest: v23, pSrc: (const char *)&v36.m_Memory.m_pMemory[v8], maxLen: 0x8000);
      m_pMemory = v36.m_Memory.m_pMemory;
    }
LABEL_33:
    if ( v36.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  V_snprintf(pDest: buffer, maxLen: 0x8000, pFormat: "\n*** Xbox 360 ***\n%s\n\n%s\n", pDest, g_bug_mapInfo.details);
  ((void (__thiscall *)(IBugReporter *, int, int))g_bug_pReporter->StartNewBugReport)(
    a1: g_bug_pReporter,
    a2: a1,
    a3: a2);
  v11 = g_bug_pReporter->__vftable;
  v12 = g_bug_pReporter->GetUserNameForDisplayName(this: g_bug_pReporter, a2: g_bug_szOwner);
  v11->SetOwner(this: g_bug_pReporter, a2: v12);
  v13 = g_bug_pReporter->__vftable;
  v14 = g_bug_pReporter->GetUserNameForDisplayName(this: g_bug_pReporter, a2: g_bug_szSubmitter);
  v13->SetSubmitter(this: g_bug_pReporter, a2: v14);
  if ( out[0] != 0 )
    V_snprintf(pDest: v25, maxLen: 1024, pFormat: "%s: %s", out, g_bug_szTitle);
  else
    V_snprintf(pDest: v25, maxLen: 1024, pFormat: "%s", g_bug_szTitle);
  g_bug_pReporter->SetTitle(this: g_bug_pReporter, a2: v25);
  g_bug_pReporter->SetDescription(this: g_bug_pReporter, a2: g_bug_szDescription);
  g_bug_pReporter->SetLevel(this: g_bug_pReporter, a2: out);
  g_bug_pReporter->SetPosition(this: g_bug_pReporter, a2: string);
  g_bug_pReporter->SetOrientation(this: g_bug_pReporter, a2: String);
  g_bug_pReporter->SetBuildNumber(this: g_bug_pReporter, a2: v29);
  g_bug_pReporter->SetSeverity(this: g_bug_pReporter, a2: g_bug_szSeverity);
  g_bug_pReporter->SetReportType(this: g_bug_pReporter, a2: g_bug_szCategory);
  g_bug_pReporter->SetArea(this: g_bug_pReporter, a2: g_bug_szArea);
  g_bug_pReporter->SetMapNumber(this: g_bug_pReporter, a2: g_bug_szMapNumber);
  g_bug_pReporter->SetMiscInfo(this: g_bug_pReporter, a2: buffer);
  g_bug_pReporter->SetDriverInfo(this: g_bug_pReporter, a2: &defValue);
  g_bug_pReporter->SetExeName(this: g_bug_pReporter, a2: &defValue);
  g_bug_pReporter->SetGameDirectory(this: g_bug_pReporter, a2: &defValue);
  g_bug_pReporter->SetRAM(this: g_bug_pReporter, a2: 0);
  g_bug_pReporter->SetCPU(this: g_bug_pReporter, a2: 0);
  g_bug_pReporter->SetProcessor(this: g_bug_pReporter, a2: &defValue);
  g_bug_pReporter->SetDXVersion(this: g_bug_pReporter, a2: 0, a3: 0, a4: 0, a5: 0);
  g_bug_pReporter->SetOSVersion(this: g_bug_pReporter, a2: "Xbox 360");
  g_bug_pReporter->ResetIncludedFiles(this: g_bug_pReporter);
  g_bug_pReporter->SetZipAttachmentName(this: g_bug_pReporter, a2: &defValue);
  if ( g_bug_szScreenshot[0] != 0 )
  {
    if ( g_bug_bCompressScreenshot != 0 )
      BugDlg_CompressScreenshot();
    Sys_StripPath(inpath: g_bug_szScreenshot, outpath, outPathLen: 260);
    v15 = g_bug_pReporter->GetRepositoryURL(this: g_bug_pReporter);
    if ( v15 == nullptr )
      v15 = "\\\\fileserver\\bugs";
    V_snprintf(pDest: path, maxLen: 260, pFormat: "%s/BugId/%s", v15, outpath);
    Sys_NormalizePath(path, forceToLower: false);
    g_bug_pReporter->SetScreenShot(this: g_bug_pReporter, a2: path);
  }
  if ( g_bug_szSavegame[0] != 0 )
  {
    Sys_StripPath(inpath: g_bug_szSavegame, outpath, outPathLen: 260);
    v16 = g_bug_pReporter->GetRepositoryURL(this: g_bug_pReporter);
    if ( v16 == nullptr )
      v16 = "\\\\fileserver\\bugs";
    V_snprintf(pDest: path, maxLen: 260, pFormat: "%s/BugId/%s", v16, outpath);
    Sys_NormalizePath(path, forceToLower: false);
    g_bug_pReporter->SetSaveGame(this: g_bug_pReporter, a2: path);
  }
  if ( g_bug_szBSPName[0] != 0 )
  {
    Sys_StripPath(inpath: g_bug_szBSPName, outpath, outPathLen: 260);
    v17 = g_bug_pReporter->GetRepositoryURL(this: g_bug_pReporter);
    if ( v17 == nullptr )
      v17 = "\\\\fileserver\\bugs";
    V_snprintf(pDest: path, maxLen: 260, pFormat: "%s/BugId/%s", v17, outpath);
    Sys_NormalizePath(path, forceToLower: false);
    g_bug_pReporter->SetBSPName(this: g_bug_pReporter, a2: path);
  }
  bugID = -1;
  v18 = g_bug_pReporter->CommitBugReport(this: g_bug_pReporter, a2: &bugID);
  if ( !v18 )
  {
    Sys_MessageBox(title: "Bug Error", format: "Unable to post bug report to database!\n");
    goto LABEL_56;
  }
  if ( BugDlg_UploadBugSubmission(
         bugID,
         pSavefile: g_bug_szSavegame,
         pScreenshot: g_bug_szScreenshot,
         pBspFile: g_bug_szBSPName) == 0 )
  {
    Sys_MessageBox(title: "Bug Error", format: "Unable to upload files to bug repository!\n");
LABEL_56:
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Bug Reporter: BugBait submission failed\n");
    return false;
  }
  SubmissionURL = GetSubmissionURL(bugid: bugID);
  V_snprintf(pDest: file, maxLen: 260, pFormat: "%s/%s", SubmissionURL, "vxconsolespew.txt");
  Sys_NormalizePath(path: file, forceToLower: false);
  v21 = fopen(file, mode: "wt");
  if ( v21 != nullptr )
  {
    fwrite(buffer, size: 1u, count: strlen(buffer), stream: v21);
    fwrite(buffer: "\n\n", size: 1u, count: 2u, stream: v21);
    fwrite(buffer: v23, size: 1u, count: strlen(v23), stream: v21);
    fclose(stream: v21);
  }
  else
  {
    Sys_MessageBox(title: "Bug Error", format: "Unable to upload console spew to bug repository!\n");
  }
  ConsoleWindowPrintf(rgb: 0xFFFF00u, strFormat: "*** Bug Reporter: BugBait submission succeeded!\n");
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x0040DE30
// Name: int BugDlg_Proc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall BugDlg_Proc(HWND hwnd, unsigned int message, unsigned int wParam, int lParam)
{
  int result; // eax

  if ( message == 272 )
  {
    g_bug_hWnd = hwnd;
    g_bug_bFirstCommand = false;
    g_bug_szTitle[0] = 0;
    g_bug_szDescription[0] = 0;
    g_bug_szScreenshot[0] = 0;
    g_bug_szSavegame[0] = 0;
    g_bug_szBSPName[0] = 0;
    memset(dst: (unsigned __int8 *)&g_bug_mapInfo, value: 0, count: sizeof(g_bug_mapInfo));
    BugDlg_Populate(hWnd: hwnd);
    return 1;
  }
  else if ( message == 273 )
  {
    if ( (unsigned __int16)wParam > 0x3FCu )
    {
      switch ( (__int16)wParam )
      {
        case 1056:
          g_bug_szTitle[0] = 0;
          g_bug_szDescription[0] = 0;
          g_bug_szOwner[0] = 0;
          g_bug_szSeverity[0] = 0;
          g_bug_szMapNumber[0] = 0;
          g_bug_szScreenshot[0] = 0;
          g_bug_szSavegame[0] = 0;
          g_bug_szBSPName[0] = 0;
          memset(dst: (unsigned __int8 *)&g_bug_mapInfo, value: 0, count: sizeof(g_bug_mapInfo));
          BugDlg_Populate(hWnd: hwnd);
          return 1;
        case 1057:
        case 1058:
          if ( !g_bug_bActive || HIWORD(wParam) != 768 )
            return 0;
          goto LABEL_21;
        case 1059:
          BugDlg_GetAppData(hWnd: hwnd);
          return 1;
        case 1060:
          BugDlg_IncludeBSP(hWnd: hwnd);
          return 0;
        case 1061:
          BugDlg_SaveGame(hWnd: hwnd);
          return 0;
        case 1063:
          BugDlg_TakeScreenshot(hWnd: hwnd);
          return 0;
        case 1065:
        case 1080:
        case 1081:
        case 1082:
          if ( !g_bug_bActive || HIWORD(wParam) != 8 )
            return 0;
          BugDlg_GetChanges(hWnd: hwnd);
          goto LABEL_17;
        case 1068:
          if ( HIWORD(wParam) != 8 )
            return 0;
          if ( !BugDlg_OnAreaChanged(hWnd: hwnd) )
            goto LABEL_17;
          g_bug_szOwner[0] = 0;
          g_bug_szSeverity[0] = 0;
          g_bug_szMapNumber[0] = 0;
          memset(dst: (unsigned __int8 *)&g_bug_mapInfo, value: 0, count: sizeof(g_bug_mapInfo));
          BugDlg_Populate(hWnd: hwnd);
          result = 1;
          break;
        case 1078:
          if ( !g_bug_bActive || HIWORD(wParam) != 8 )
            return 0;
          if ( BugDlg_OnMapChanged(hWnd: hwnd, forceRefresh: false) != 0 )
            goto LABEL_21;
LABEL_17:
          result = 1;
          break;
        case 1079:
          if ( BugDlg_Submit(a1: (int)hwnd, a2: wParam) )
            goto LABEL_29;
          return 0;
        case 1083:
        case 1084:
LABEL_21:
          BugDlg_GetChanges(hWnd: hwnd);
          result = 1;
          break;
        default:
          return 0;
      }
    }
    else if ( (unsigned __int16)wParam == 1020 || (unsigned __int16)wParam == 2 )
    {
LABEL_29:
      if ( g_connectedToApp && g_bug_bFirstCommand )
        ProcessCommand(strCmdIn: "cmd bugunpause");
      EndDialog(hDlg: hwnd, nResult: wParam);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E110
// Name: void BugDlg_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_Open()
{
  if ( g_bug_hWnd == nullptr && BugReporter_GetInterfaces() != 0 )
  {
    BugDlg_LoadConfig();
    if ( (unsigned __int16)DialogBoxParamA(
                             hInstance: g_hInstance,
                             lpTemplateName: (LPCSTR)0x80,
                             hWndParent: g_hDlgMain,
                             lpDialogFunc: BugDlg_Proc,
                             dwInitParam: 0) == 1079 )
      BugDlg_SaveConfig();
    g_bug_hWnd = nullptr;
  }
}
