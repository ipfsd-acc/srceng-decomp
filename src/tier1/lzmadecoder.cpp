// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/lzmadecoder.cpp
// Functions: 6
// ============================================================

#include "tier1\lzmadecoder.h"

//------------------------------------------------------------------------------
// Address: 0x10270AC0
// Name: int LzmaDecodeProperties(struct _CLzmaProperties __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeProperties(_CLzmaProperties *propsRes, unsigned __int8 *propsData, int size)
{
  unsigned __int8 v4; // cl
  unsigned int v5; // eax
  int v6; // edx
  unsigned int v7; // eax
  int v8; // edx

  if ( size < 5 )
    return 1;
  v4 = *propsData;
  if ( *propsData >= 0xE1u )
    return 1;
  propsRes->pb = 0;
  if ( v4 >= 0x2Du )
  {
    v5 = v4 / 0x2Du;
    v6 = v5;
    do
    {
      v4 -= 45;
      --v5;
    }
    while ( v5 != 0 );
    propsRes->pb = v6;
  }
  propsRes->lp = 0;
  if ( v4 >= 9u )
  {
    v7 = v4 / 9u;
    v8 = v7;
    do
    {
      v4 -= 9;
      --v7;
    }
    while ( v7 != 0 );
    propsRes->lp = v8;
  }
  propsRes->lc = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10270B50
// Name: int LzmaDecodeWithCallback(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeWithCallback(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        const unsigned __int8 *inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int *Probs; // edi
  int v9; // edx
  int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // esi
  int j; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // eax
  int k; // ebx
  int v19; // ebx
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v25; // eax
  unsigned int v26; // esi
  unsigned int v27; // edx
  unsigned int v28; // ebx
  unsigned int v29; // esi
  int v30; // edx
  unsigned int *v31; // eax
  unsigned int v32; // esi
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned int v35; // esi
  unsigned int *v36; // ebx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  unsigned int v39; // ecx
  unsigned __int8 v40; // dl
  unsigned int v41; // esi
  unsigned int v42; // edx
  unsigned int v43; // ebx
  unsigned int v44; // ebx
  unsigned int v45; // edx
  unsigned int v46; // esi
  unsigned int v47; // edx
  unsigned int v48; // ebx
  unsigned int v49; // ebx
  const unsigned __int8 *v50; // ebx
  unsigned int v51; // ecx
  unsigned int v52; // edx
  int v53; // ecx
  unsigned int v54; // esi
  unsigned int v55; // ecx
  unsigned int v56; // edx
  int v57; // ebx
  unsigned int v58; // eax
  unsigned int v59; // edx
  int v60; // ebx
  int v61; // ebx
  int v62; // eax
  unsigned int v63; // ecx
  unsigned int v64; // edx
  int v65; // eax
  int v66; // edx
  int v67; // ecx
  int v68; // ebx
  const unsigned __int8 *v69; // eax
  int v70; // edx
  int v71; // ecx
  unsigned int v72; // eax
  unsigned int v73; // edx
  unsigned int v74; // ebx
  unsigned __int8 *v75; // ecx
  unsigned __int8 v76; // al
  unsigned int literalPosMask; // [esp+Ch] [ebp-34h]
  unsigned int posStateMask; // [esp+10h] [ebp-30h]
  char lc; // [esp+14h] [ebp-2Ch]
  int offset; // [esp+18h] [ebp-28h]
  int offseta; // [esp+18h] [ebp-28h]
  int offsetb; // [esp+18h] [ebp-28h]
  int offsetc; // [esp+18h] [ebp-28h]
  unsigned int rep3; // [esp+1Ch] [ebp-24h]
  unsigned int *p; // [esp+20h] [ebp-20h]
  unsigned int rep1; // [esp+24h] [ebp-1Ch]
  unsigned int rep2; // [esp+28h] [ebp-18h]
  unsigned int *i; // [esp+2Ch] [ebp-14h]
  int ia; // [esp+2Ch] [ebp-14h]
  unsigned int *ib; // [esp+2Ch] [ebp-14h]
  int ic; // [esp+2Ch] [ebp-14h]
  int id; // [esp+2Ch] [ebp-14h]
  int ie; // [esp+2Ch] [ebp-14h]
  unsigned int nowPos; // [esp+30h] [ebp-10h]
  int state; // [esp+34h] [ebp-Ch]
  const unsigned __int8 *BufferLim; // [esp+38h] [ebp-8h]
  unsigned int rep0; // [esp+3Ch] [ebp-4h]
  unsigned int rep0a; // [esp+3Ch] [ebp-4h]
  unsigned int rep0b; // [esp+3Ch] [ebp-4h]
  unsigned int *numDirectBits; // [esp+48h] [ebp+8h]
  int numDirectBitsa; // [esp+48h] [ebp+8h]
  int numDirectBitsb; // [esp+48h] [ebp+8h]
  int numDirectBitsc; // [esp+48h] [ebp+8h]
  unsigned __int8 numDirectBits_3; // [esp+4Bh] [ebp+Bh]
  const unsigned __int8 *Buffer; // [esp+50h] [ebp+10h]

  posStateMask = (1 << vs->Properties.pb) - 1;
  Probs = vs->Probs;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v9 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v10 = v9 + vs->Properties.lp;
  p = Probs;
  nowPos = 0;
  numDirectBits_3 = 0;
  lc = v9;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v10 != -1846 )
    memset32(Probs, 1024, (768 << v10) + 1846);
  v11 = inStream;
  v12 = 0;
  v13 = -1;
  BufferLim = &inSize[(_DWORD)inStream];
  for ( j = 0; j < 5; ++j )
  {
    if ( v11 == &inSize[(_DWORD)inStream] )
      return 1;
    v12 = *v11++ | (v12 << 8);
  }
  Buffer = v11;
  if ( outSize == 0 )
    goto LABEL_41;
  do
  {
    offset = nowPos & posStateMask;
    i = &p[16 * state + (nowPos & posStateMask)];
    if ( v13 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v13 <<= 8;
      v12 = *Buffer++ | (v12 << 8);
    }
    v15 = *i;
    v16 = *i * (v13 >> 11);
    if ( v12 >= v16 )
    {
      v26 = v13 - v16;
      v12 -= v16;
      *i = v15 - (v15 >> 5);
      if ( v26 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v26 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v27 = p[state + 192];
      v28 = v27 * (v26 >> 11);
      if ( v12 >= v28 )
      {
        v32 = v26 - v28;
        v12 -= v28;
        p[state + 192] = v27 - (v27 >> 5);
        if ( v32 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v32 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v33 = p[state + 204];
        v34 = v33 * (v32 >> 11);
        if ( v12 >= v34 )
        {
          v41 = v32 - v34;
          v12 -= v34;
          p[state + 204] = v33 - (v33 >> 5);
          if ( v41 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v41 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v42 = p[state + 216];
          v43 = v42 * (v41 >> 11);
          if ( v12 >= v43 )
          {
            v46 = v41 - v43;
            v12 -= v43;
            p[state + 216] = v42 - (v42 >> 5);
            if ( v46 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v46 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v47 = p[state + 228];
            v48 = v47 * (v46 >> 11);
            if ( v12 >= v48 )
            {
              v29 = v46 - v48;
              v12 -= v48;
              p[state + 228] = v47 - (v47 >> 5);
              v45 = rep3;
              rep3 = rep2;
            }
            else
            {
              v29 = v47 * (v46 >> 11);
              v49 = v47 + ((2048 - v47) >> 5);
              v45 = rep2;
              p[state + 228] = v49;
            }
            rep2 = rep1;
          }
          else
          {
            v29 = v42 * (v41 >> 11);
            v44 = v42 + ((2048 - v42) >> 5);
            v45 = rep1;
            p[state + 216] = v44;
          }
          rep1 = rep0;
          rep0 = v45;
        }
        else
        {
          v35 = v33 * (v32 >> 11);
          p[state + 204] = v33 + ((2048 - v33) >> 5);
          v36 = &p[16 * state + 240 + offset];
          ib = v36;
          if ( v35 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v35 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v37 = *v36;
          v38 = *v36 * (v35 >> 11);
          if ( v12 < v38 )
          {
            v13 = v38;
            *ib = v37 + ((2048 - v37) >> 5);
            if ( nowPos != 0 )
            {
              state = 2 * (state >= 7) + 9;
              v39 = nowPos + 1;
              v40 = outStream[nowPos - rep0];
              outStream[v39 - 1] = v40;
              numDirectBits_3 = v40;
              ++nowPos;
              if ( v39 % 0x7A120 == 0 )
                pCallbackFunc();
              continue;
            }
            return 1;
          }
          v29 = v35 - v38;
          v12 -= v38;
          *ib = v37 - (v37 >> 5);
        }
        v30 = state >= 7 ? 11 : 8;
        v31 = p + 1332;
      }
      else
      {
        v29 = v27 * (v26 >> 11);
        rep3 = rep2;
        rep2 = rep1;
        rep1 = rep0;
        p[state + 192] = v27 + ((2048 - v27) >> 5);
        v30 = state < 7 ? 0 : 3;
        v31 = p + 818;
      }
      v50 = Buffer;
      state = v30;
      if ( v29 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v29 <<= 8;
        v12 = *Buffer | (v12 << 8);
        v50 = ++Buffer;
      }
      v51 = *v31;
      v52 = *v31 * (v29 >> 11);
      if ( v12 >= v52 )
      {
        v54 = v29 - v52;
        v12 -= v52;
        *v31 = v51 - (v51 >> 5);
        if ( v54 < 0x1000000 )
        {
          if ( v50 == BufferLim )
            return 1;
          v54 <<= 8;
          v12 = *v50 | (v12 << 8);
          Buffer = v50 + 1;
        }
        v55 = v31[1];
        v56 = v55 * (v54 >> 11);
        if ( v12 >= v56 )
        {
          v13 = v54 - v56;
          v12 -= v56;
          v31[1] = v55 - (v55 >> 5);
          v53 = (int)(v31 + 258);
          offsetb = 16;
          numDirectBitsa = 8;
        }
        else
        {
          v13 = v55 * (v54 >> 11);
          v31[1] = v55 + ((2048 - v55) >> 5);
          v53 = (int)&v31[8 * offset + 130];
          offsetb = 8;
          numDirectBitsa = 3;
        }
      }
      else
      {
        v13 = *v31 * (v29 >> 11);
        *v31 = v51 + ((2048 - v51) >> 5);
        v53 = (int)&v31[8 * offset + 2];
        offsetb = 0;
        numDirectBitsa = 3;
      }
      ic = numDirectBitsa;
      v57 = 1;
      do
      {
        if ( v13 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v13 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v58 = *(_DWORD *)(v53 + 4 * v57);
        v59 = v58 * (v13 >> 11);
        if ( v12 >= v59 )
        {
          v13 -= v59;
          v12 -= v59;
          *(_DWORD *)(v53 + 4 * v57) = v58 - (v58 >> 5);
          v57 = 2 * v57 + 1;
        }
        else
        {
          v13 = v58 * (v13 >> 11);
          *(_DWORD *)(v53 + 4 * v57) = v58 + ((2048 - v58) >> 5);
          v57 *= 2;
        }
        --ic;
      }
      while ( ic != 0 );
      v60 = offsetb - (1 << numDirectBitsa) + v57;
      id = v60;
      if ( state < 4 )
      {
        state += 7;
        if ( v60 >= 4 )
          v60 = 3;
        v61 = (int)&p[64 * v60 + 432];
        numDirectBitsb = 6;
        v62 = 1;
        do
        {
          if ( v13 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v13 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v63 = *(_DWORD *)(v61 + 4 * v62);
          v64 = v63 * (v13 >> 11);
          if ( v12 >= v64 )
          {
            v13 -= v64;
            v12 -= v64;
            *(_DWORD *)(v61 + 4 * v62) = v63 - (v63 >> 5);
            v62 = 2 * v62 + 1;
          }
          else
          {
            v13 = v63 * (v13 >> 11);
            *(_DWORD *)(v61 + 4 * v62) = v63 + ((2048 - v63) >> 5);
            v62 *= 2;
          }
          --numDirectBitsb;
        }
        while ( numDirectBitsb != 0 );
        v65 = v62 - 64;
        if ( v65 < 4 )
        {
          rep0a = v65;
        }
        else
        {
          v66 = (v65 >> 1) - 1;
          v67 = v65 & 1 | 2;
          numDirectBitsc = v66;
          if ( v65 >= 14 )
          {
            v69 = Buffer;
            v70 = v66 - 4;
            do
            {
              if ( v13 < 0x1000000 )
              {
                if ( v69 == BufferLim )
                  return 1;
                v13 <<= 8;
                v12 = *v69++ | (v12 << 8);
                Buffer = v69;
              }
              v13 >>= 1;
              v67 *= 2;
              rep0b = v67;
              if ( v12 >= v13 )
              {
                v12 -= v13;
                v67 |= 1u;
                rep0b = v67;
              }
              --v70;
            }
            while ( v70 != 0 );
            v68 = (int)(p + 802);
            rep0a = 16 * rep0b;
            numDirectBitsc = 4;
          }
          else
          {
            rep0a = (v65 & 1 | 2) << v66;
            v68 = (int)&p[rep0a - v65 + 687];
          }
          v71 = 1;
          offsetc = 1;
          do
          {
            if ( v13 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v13 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v72 = *(_DWORD *)(v68 + 4 * v71);
            v73 = v72 * (v13 >> 11);
            if ( v12 >= v73 )
            {
              v13 -= v73;
              v12 -= v73;
              *(_DWORD *)(v68 + 4 * v71) = v72 - (v72 >> 5);
              rep0a |= offsetc;
              v71 = 2 * v71 + 1;
            }
            else
            {
              v13 = v72 * (v13 >> 11);
              *(_DWORD *)(v68 + 4 * v71) = v72 + ((2048 - v72) >> 5);
              v71 *= 2;
            }
            offsetc *= 2;
            --numDirectBitsc;
          }
          while ( numDirectBitsc != 0 );
        }
        rep0 = rep0a + 1;
        if ( rep0 == 0 )
          break;
      }
      v74 = nowPos;
      ie = id + 2;
      if ( rep0 <= nowPos )
      {
        v75 = &outStream[-rep0];
        do
        {
          v76 = v75[v74];
          outStream[v74] = v76;
          --ie;
          numDirectBits_3 = v76;
          nowPos = ++v74;
          if ( v74 % 0x7A120 == 0 )
          {
            pCallbackFunc();
            v75 = &outStream[-rep0];
          }
          if ( ie == 0 )
            goto LABEL_37;
        }
        while ( v74 < outSize );
        break;
      }
      return 1;
    }
    *i = v15 + ((2048 - v15) >> 5);
    v13 = v16;
    v17 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (numDirectBits_3 >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_19;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v19 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v19 + v17) + 1024);
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v20 = *numDirectBits;
      v21 = *numDirectBits * (v13 >> 11);
      if ( v12 >= v21 )
        break;
      v13 = *numDirectBits * (v13 >> 11);
      v17 *= 2;
      *numDirectBits = v20 + ((2048 - v20) >> 5);
      if ( v19 != 0 )
        goto LABEL_18;
LABEL_26:
      if ( v17 >= 256 )
        goto LABEL_30;
    }
    v13 -= v21;
    v12 -= v21;
    *numDirectBits = v20 - (v20 >> 5);
    v17 = 2 * v17 + 1;
    if ( v19 != 0 )
      goto LABEL_26;
LABEL_18:
    while ( v17 < 256 )
    {
LABEL_19:
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v22 = *(_DWORD *)(ia + 4 * v17);
      v23 = v22 * (v13 >> 11);
      if ( v12 >= v23 )
      {
        v13 -= v23;
        v12 -= v23;
        *(_DWORD *)(ia + 4 * v17) = v22 - (v22 >> 5);
        v17 = 2 * v17 + 1;
      }
      else
      {
        v13 = v22 * (v13 >> 11);
        *(_DWORD *)(ia + 4 * v17) = v22 + ((2048 - v22) >> 5);
        v17 *= 2;
      }
    }
LABEL_30:
    outStream[nowPos] = v17;
    numDirectBits_3 = v17;
    if ( ++nowPos % 0x7A120 == 0 )
      pCallbackFunc();
    if ( state >= 4 )
    {
      if ( state >= 10 )
        v25 = state - 6;
      else
        v25 = state - 3;
      state = v25;
    }
    else
    {
      state = 0;
    }
LABEL_37:
    ;
  }
  while ( nowPos < outSize );
  if ( v13 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_41:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10271470
// Name: int LzmaDecode(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecode(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        unsigned int inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int v8; // esi
  unsigned int *Probs; // edi
  int v11; // edx
  int v12; // ecx
  const unsigned __int8 *v13; // ecx
  unsigned int v14; // eax
  int j; // edx
  const unsigned __int8 *v16; // edx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  int v19; // edx
  int k; // ebx
  int v21; // ebx
  unsigned int v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ecx
  unsigned int v25; // edi
  int v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int *v31; // ecx
  int v32; // edx
  unsigned int v33; // eax
  unsigned int v34; // edi
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int *v37; // ebx
  unsigned int v38; // edx
  unsigned int v39; // edi
  unsigned int v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // edx
  unsigned int v43; // edi
  unsigned int v44; // edi
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // edx
  unsigned int v48; // edi
  unsigned int v49; // edi
  unsigned int v50; // edx
  unsigned int v51; // edi
  int v52; // ecx
  unsigned int v53; // eax
  unsigned int v54; // edx
  unsigned int v55; // edi
  int v56; // ebx
  unsigned int v57; // edx
  unsigned int v58; // edi
  int v59; // edx
  int v60; // ebx
  int v61; // ebx
  unsigned int v62; // ecx
  unsigned int v63; // edi
  int v64; // edx
  int v65; // edi
  int v66; // ecx
  int v67; // ebx
  const unsigned __int8 *v68; // edx
  int v69; // edi
  int v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // edi
  unsigned int v73; // ecx
  int v74; // ebx
  unsigned __int8 *m; // edx
  unsigned __int8 v76; // dl
  unsigned int literalPosMask; // [esp+4h] [ebp-38h]
  unsigned int posStateMask; // [esp+8h] [ebp-34h]
  char lc; // [esp+Ch] [ebp-30h]
  unsigned int rep3; // [esp+10h] [ebp-2Ch]
  int offset; // [esp+14h] [ebp-28h]
  int offseta; // [esp+14h] [ebp-28h]
  int offsetb; // [esp+14h] [ebp-28h]
  int offsetc; // [esp+14h] [ebp-28h]
  unsigned int rep1; // [esp+18h] [ebp-24h]
  unsigned int rep2; // [esp+1Ch] [ebp-20h]
  unsigned int *i; // [esp+20h] [ebp-1Ch]
  int ia; // [esp+20h] [ebp-1Ch]
  int ib; // [esp+20h] [ebp-1Ch]
  int ic; // [esp+20h] [ebp-1Ch]
  unsigned int *p; // [esp+24h] [ebp-18h]
  int state; // [esp+28h] [ebp-14h]
  unsigned int nowPos; // [esp+2Ch] [ebp-10h]
  const unsigned __int8 *BufferLim; // [esp+30h] [ebp-Ch]
  unsigned int rep0; // [esp+34h] [ebp-8h]
  unsigned int rep0a; // [esp+34h] [ebp-8h]
  unsigned int rep0b; // [esp+34h] [ebp-8h]
  const unsigned __int8 *Buffer; // [esp+38h] [ebp-4h]
  unsigned int *numDirectBits; // [esp+60h] [ebp+24h]
  int numDirectBitsa; // [esp+60h] [ebp+24h]
  int numDirectBitsb; // [esp+60h] [ebp+24h]
  int numDirectBitsc; // [esp+60h] [ebp+24h]

  v8 = 0;
  if ( pCallbackFunc != nullptr )
    return LzmaDecodeWithCallback(
             vs,
             inStream,
             (const unsigned __int8 *)inSize,
             inSizeProcessed,
             outStream,
             outSize,
             outSizeProcessed,
             pCallbackFunc);
  Probs = vs->Probs;
  posStateMask = (1 << vs->Properties.pb) - 1;
  p = Probs;
  nowPos = 0;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v11 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v12 = v11 + vs->Properties.lp;
  lc = v11;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v12 != -1846 )
    memset32(Probs, 1024, (768 << v12) + 1846);
  v13 = inStream;
  v14 = -1;
  BufferLim = &inStream[inSize];
  for ( j = 0; j < 5; ++j )
  {
    if ( v13 == &inStream[inSize] )
      return 1;
    v8 = *v13++ | (v8 << 8);
  }
  Buffer = v13;
  if ( outSize == 0 )
    goto LABEL_131;
LABEL_9:
  offset = nowPos & posStateMask;
  i = &p[16 * state + (nowPos & posStateMask)];
  v16 = Buffer;
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v14 <<= 8;
    v8 = *Buffer | (v8 << 8);
    v16 = ++Buffer;
  }
  v17 = *i;
  v18 = *i * (v14 >> 11);
  if ( v8 < v18 )
  {
    *i = v17 + ((2048 - v17) >> 5);
    v14 = v18;
    v19 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (HIBYTE(pCallbackFunc) >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_21;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v21 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v21 + v19) + 1024);
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v22 = *numDirectBits;
      v23 = *numDirectBits * (v14 >> 11);
      if ( v8 >= v23 )
      {
        v14 -= v23;
        v8 -= v23;
        *numDirectBits = v22 - (v22 >> 5);
        v19 = 2 * v19 + 1;
        if ( v21 == 0 )
        {
LABEL_20:
          while ( v19 < 256 )
          {
LABEL_21:
            if ( v14 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v14 <<= 8;
              v8 = *Buffer++ | (v8 << 8);
            }
            v24 = *(_DWORD *)(ia + 4 * v19);
            v25 = v24 * (v14 >> 11);
            if ( v8 >= v25 )
            {
              v14 -= v25;
              v8 -= v25;
              *(_DWORD *)(ia + 4 * v19) = v24 - (v24 >> 5);
              v19 = 2 * v19 + 1;
            }
            else
            {
              v14 = v24 * (v14 >> 11);
              *(_DWORD *)(ia + 4 * v19) = v24 + ((2048 - v24) >> 5);
              v19 *= 2;
            }
          }
LABEL_32:
          outStream[nowPos++] = v19;
          HIBYTE(pCallbackFunc) = v19;
          if ( state >= 4 )
          {
            if ( state >= 10 )
              v26 = state - 6;
            else
              v26 = state - 3;
            state = v26;
          }
          else
          {
            state = 0;
          }
LABEL_37:
          if ( nowPos >= outSize )
            goto LABEL_38;
          goto LABEL_9;
        }
      }
      else
      {
        v14 = *numDirectBits * (v14 >> 11);
        v19 *= 2;
        *numDirectBits = v22 + ((2048 - v22) >> 5);
        if ( v21 != 0 )
          goto LABEL_20;
      }
      if ( v19 >= 256 )
        goto LABEL_32;
    }
  }
  v27 = v14 - v18;
  v8 -= v18;
  *i = v17 - (v17 >> 5);
  if ( v27 < 0x1000000 )
  {
    if ( v16 == BufferLim )
      return 1;
    v27 <<= 8;
    v8 = *v16 | (v8 << 8);
    Buffer = v16 + 1;
  }
  v28 = p[state + 192];
  v29 = v28 * (v27 >> 11);
  if ( v8 < v29 )
  {
    rep3 = rep2;
    rep2 = rep1;
    rep1 = rep0;
    v30 = v28 * (v27 >> 11);
    p[state + 192] = v28 + ((2048 - v28) >> 5);
    v31 = p + 818;
    v32 = state < 7 ? 0 : 3;
    goto LABEL_72;
  }
  v33 = v27 - v29;
  v8 -= v29;
  p[state + 192] = v28 - (v28 >> 5);
  if ( v33 < 0x1000000 )
  {
    if ( Buffer != BufferLim )
    {
      v33 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
      goto LABEL_50;
    }
    return 1;
  }
LABEL_50:
  v34 = p[state + 204];
  v35 = v34 * (v33 >> 11);
  if ( v8 >= v35 )
  {
    v41 = v33 - v35;
    v8 -= v35;
    p[state + 204] = v34 - (v34 >> 5);
    if ( v41 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v41 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v42 = p[state + 216];
    v43 = v42 * (v41 >> 11);
    if ( v8 >= v43 )
    {
      v46 = v41 - v43;
      v8 -= v43;
      p[state + 216] = v42 - (v42 >> 5);
      if ( v46 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v46 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v47 = p[state + 228];
      v48 = v47 * (v46 >> 11);
      if ( v8 >= v48 )
      {
        v30 = v46 - v48;
        v8 -= v48;
        p[state + 228] = v47 - (v47 >> 5);
        v45 = rep3;
        rep3 = rep2;
      }
      else
      {
        v30 = v47 * (v46 >> 11);
        v49 = v47 + ((2048 - v47) >> 5);
        v45 = rep2;
        p[state + 228] = v49;
      }
      rep2 = rep1;
    }
    else
    {
      v30 = v42 * (v41 >> 11);
      v44 = v42 + ((2048 - v42) >> 5);
      v45 = rep1;
      p[state + 216] = v44;
    }
    rep1 = rep0;
    rep0 = v45;
  }
  else
  {
    p[state + 204] = v34 + ((2048 - v34) >> 5);
    v36 = v34 * (v33 >> 11);
    v37 = &p[16 * state + 240 + offset];
    if ( v35 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v36 = v35 << 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v38 = *v37;
    v39 = *v37 * (v36 >> 11);
    if ( v8 < v39 )
    {
      v14 = *v37 * (v36 >> 11);
      *v37 = v38 + ((2048 - v38) >> 5);
      if ( nowPos != 0 )
      {
        v40 = nowPos - rep0;
        ++nowPos;
        state = 2 * (state >= 7) + 9;
        LOBYTE(v40) = outStream[v40];
        outStream[nowPos - 1] = v40;
        HIBYTE(pCallbackFunc) = v40;
        goto LABEL_37;
      }
      return 1;
    }
    v30 = v36 - v39;
    v8 -= v39;
    *v37 = v38 - (v38 >> 5);
  }
  v32 = state >= 7 ? 11 : 8;
  v31 = p + 1332;
LABEL_72:
  state = v32;
  if ( v30 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v30 <<= 8;
    v8 = *Buffer++ | (v8 << 8);
  }
  v50 = *v31;
  v51 = *v31 * (v30 >> 11);
  if ( v8 >= v51 )
  {
    v53 = v30 - v51;
    v8 -= v51;
    *v31 = v50 - (v50 >> 5);
    if ( v53 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v53 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v54 = v31[1];
    v55 = v54 * (v53 >> 11);
    if ( v8 >= v55 )
    {
      v14 = v53 - v55;
      v8 -= v55;
      v31[1] = v54 - (v54 >> 5);
      v52 = (int)(v31 + 258);
      offsetb = 16;
      numDirectBitsa = 8;
    }
    else
    {
      v14 = v54 * (v53 >> 11);
      v31[1] = v54 + ((2048 - v54) >> 5);
      v52 = (int)&v31[8 * offset + 130];
      offsetb = 8;
      numDirectBitsa = 3;
    }
  }
  else
  {
    v14 = *v31 * (v30 >> 11);
    *v31 = v50 + ((2048 - v50) >> 5);
    v52 = (int)&v31[8 * offset + 2];
    offsetb = 0;
    numDirectBitsa = 3;
  }
  ib = numDirectBitsa;
  v56 = 1;
  do
  {
    if ( v14 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v14 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v57 = *(_DWORD *)(v52 + 4 * v56);
    v58 = v57 * (v14 >> 11);
    if ( v8 >= v58 )
    {
      v14 -= v58;
      v8 -= v58;
      *(_DWORD *)(v52 + 4 * v56) = v57 - (v57 >> 5);
      v56 = 2 * v56 + 1;
    }
    else
    {
      v14 = v57 * (v14 >> 11);
      *(_DWORD *)(v52 + 4 * v56) = v57 + ((2048 - v57) >> 5);
      v56 *= 2;
    }
    v59 = 1;
    --ib;
  }
  while ( ib != 0 );
  v60 = offsetb - (1 << numDirectBitsa) + v56;
  ic = v60;
  if ( state < 4 )
  {
    state += 7;
    if ( v60 >= 4 )
      v60 = 3;
    v61 = (int)&p[64 * v60 + 432];
    for ( numDirectBitsb = 6; numDirectBitsb != 0; --numDirectBitsb )
    {
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v62 = *(_DWORD *)(v61 + 4 * v59);
      v63 = v62 * (v14 >> 11);
      if ( v8 >= v63 )
      {
        v14 -= v63;
        v8 -= v63;
        *(_DWORD *)(v61 + 4 * v59) = v62 - (v62 >> 5);
        v59 = 2 * v59 + 1;
      }
      else
      {
        v14 = v62 * (v14 >> 11);
        *(_DWORD *)(v61 + 4 * v59) = v62 + ((2048 - v62) >> 5);
        v59 *= 2;
      }
    }
    v64 = v59 - 64;
    if ( v64 < 4 )
    {
      rep0a = v64;
    }
    else
    {
      v65 = (v64 >> 1) - 1;
      v66 = v64 & 1 | 2;
      numDirectBitsc = v65;
      if ( v64 >= 14 )
      {
        v68 = Buffer;
        v69 = v65 - 4;
        do
        {
          if ( v14 < 0x1000000 )
          {
            if ( v68 == BufferLim )
              return 1;
            v14 <<= 8;
            v8 = *v68++ | (v8 << 8);
            Buffer = v68;
          }
          v14 >>= 1;
          v66 *= 2;
          rep0b = v66;
          if ( v8 >= v14 )
          {
            v8 -= v14;
            v66 |= 1u;
            rep0b = v66;
          }
          --v69;
        }
        while ( v69 != 0 );
        v67 = (int)(p + 802);
        rep0a = 16 * rep0b;
        numDirectBitsc = 4;
      }
      else
      {
        rep0a = (v64 & 1 | 2) << v65;
        v67 = (int)&p[rep0a - v64 + 687];
      }
      v70 = 1;
      offsetc = 1;
      do
      {
        if ( v14 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v14 <<= 8;
          v8 = *Buffer++ | (v8 << 8);
        }
        v71 = *(_DWORD *)(v67 + 4 * v70);
        v72 = v71 * (v14 >> 11);
        if ( v8 >= v72 )
        {
          v14 -= v72;
          v8 -= v72;
          *(_DWORD *)(v67 + 4 * v70) = v71 - (v71 >> 5);
          rep0a |= offsetc;
          v70 = 2 * v70 + 1;
        }
        else
        {
          v14 = v71 * (v14 >> 11);
          *(_DWORD *)(v67 + 4 * v70) = v71 + ((2048 - v71) >> 5);
          v70 *= 2;
        }
        offsetc *= 2;
        --numDirectBitsc;
      }
      while ( numDirectBitsc != 0 );
    }
    rep0 = rep0a + 1;
    if ( rep0 == 0 )
      goto LABEL_38;
    v60 = ic;
  }
  v73 = nowPos;
  v74 = v60 + 2;
  if ( rep0 > nowPos )
    return 1;
  for ( m = &outStream[-rep0]; ; m = &outStream[-rep0] )
  {
    v76 = m[v73];
    outStream[v73++] = v76;
    --v74;
    HIBYTE(pCallbackFunc) = v76;
    nowPos = v73;
    if ( v74 == 0 )
      goto LABEL_37;
    if ( v73 >= outSize )
      break;
  }
LABEL_38:
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_131:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10271D50
// Name: public: bool CLZMA::IsCompressed(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLZMA::IsCompressed(CLZMA *this, unsigned __int8 *pInput)
{
  return pInput != nullptr && *(_DWORD *)pInput == 1095588428;
}

//------------------------------------------------------------------------------
// Address: 0x10271D70
// Name: public: unsigned int CLZMA::GetActualSize(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZMA::GetActualSize(CLZMA *this, unsigned __int8 *pInput)
{
  if ( pInput != nullptr && *(_DWORD *)pInput == 1095588428 )
    return *((_DWORD *)pInput + 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10271D90
// Name: public: unsigned int CLZMA::Uncompress(unsigned char __near *,unsigned char __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZMA::Uncompress(
        CLZMA *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        void (__cdecl *pCallback)())
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ebx
  unsigned int *v6; // edi
  int v7; // esi
  unsigned __int8 *result; // eax
  unsigned int v9; // [esp-1Ch] [ebp-34h]
  _CLzmaDecoderState state; // [esp+8h] [ebp-10h] BYREF

  v4 = pInput;
  if ( pInput == nullptr )
    return nullptr;
  if ( *(_DWORD *)pInput != 1095588428 )
    return nullptr;
  v5 = *((unsigned __int8 **)pInput + 1);
  if ( v5 == nullptr )
    return nullptr;
  LzmaDecodeProperties(propsRes: &state.Properties, propsData: pInput + 12, size: 5);
  v6 = (unsigned int *)_g_pMemAlloc->Alloc_2(
                         this: _g_pMemAlloc,
                         a2: 4 * (768 << (LOBYTE(state.Properties.lp) + LOBYTE(state.Properties.lc))) + 7384);
  v9 = *((_DWORD *)v4 + 2);
  state.Probs = v6;
  v7 = LzmaDecode(
         vs: &state,
         inStream: v4 + 17,
         inSize: v9,
         inSizeProcessed: (unsigned int *)&pCallback,
         outStream: pOutput,
         outSize: (unsigned int)v5,
         outSizeProcessed: (unsigned int *)&pInput,
         pCallbackFunc: pCallback);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  if ( v7 != 0 )
    return nullptr;
  result = pInput;
  if ( pInput != v5 )
    return nullptr;
  return result;
}

// ============================================================
// Overlay from FileSystem_Stdio (Missing functions)
// ============================================================
namespace FileSystem_Stdio {

//------------------------------------------------------------------------------
// Address: 0x1002A8D0
// Name: int LzmaDecodeProperties(struct _CLzmaProperties __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeProperties(_CLzmaProperties *propsRes, unsigned __int8 *propsData, int size)
{
  unsigned __int8 v4; // cl
  unsigned int v5; // eax
  int v6; // edx
  unsigned int v7; // eax
  int v8; // edx

  if ( size < 5 )
    return 1;
  v4 = *propsData;
  if ( *propsData >= 0xE1u )
    return 1;
  propsRes->pb = 0;
  if ( v4 >= 0x2Du )
  {
    v5 = v4 / 0x2Du;
    v6 = v5;
    do
    {
      v4 -= 45;
      --v5;
    }
    while ( v5 != 0 );
    propsRes->pb = v6;
  }
  propsRes->lp = 0;
  if ( v4 >= 9u )
  {
    v7 = v4 / 9u;
    v8 = v7;
    do
    {
      v4 -= 9;
      --v7;
    }
    while ( v7 != 0 );
    propsRes->lp = v8;
  }
  propsRes->lc = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A960
// Name: int LzmaDecodeWithCallback(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeWithCallback(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        const unsigned __int8 *inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int *Probs; // edi
  int v9; // edx
  int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // esi
  int j; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // eax
  int k; // ebx
  int v19; // ebx
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v25; // eax
  unsigned int v26; // esi
  unsigned int v27; // edx
  unsigned int v28; // ebx
  unsigned int v29; // esi
  int v30; // edx
  unsigned int *v31; // eax
  unsigned int v32; // esi
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned int v35; // esi
  unsigned int *v36; // ebx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  unsigned int v39; // ecx
  unsigned __int8 v40; // dl
  unsigned int v41; // esi
  unsigned int v42; // edx
  unsigned int v43; // ebx
  unsigned int v44; // ebx
  unsigned int v45; // edx
  unsigned int v46; // esi
  unsigned int v47; // edx
  unsigned int v48; // ebx
  unsigned int v49; // ebx
  const unsigned __int8 *v50; // ebx
  unsigned int v51; // ecx
  unsigned int v52; // edx
  int v53; // ecx
  unsigned int v54; // esi
  unsigned int v55; // ecx
  unsigned int v56; // edx
  int v57; // ebx
  unsigned int v58; // eax
  unsigned int v59; // edx
  int v60; // ebx
  int v61; // ebx
  int v62; // eax
  unsigned int v63; // ecx
  unsigned int v64; // edx
  int v65; // eax
  int v66; // edx
  int v67; // ecx
  int v68; // ebx
  const unsigned __int8 *v69; // eax
  int v70; // edx
  int v71; // ecx
  unsigned int v72; // eax
  unsigned int v73; // edx
  unsigned int v74; // ebx
  unsigned __int8 *v75; // ecx
  unsigned __int8 v76; // al
  unsigned int literalPosMask; // [esp+Ch] [ebp-34h]
  unsigned int posStateMask; // [esp+10h] [ebp-30h]
  char lc; // [esp+14h] [ebp-2Ch]
  int offset; // [esp+18h] [ebp-28h]
  int offseta; // [esp+18h] [ebp-28h]
  int offsetb; // [esp+18h] [ebp-28h]
  int offsetc; // [esp+18h] [ebp-28h]
  unsigned int rep3; // [esp+1Ch] [ebp-24h]
  unsigned int *p; // [esp+20h] [ebp-20h]
  unsigned int rep1; // [esp+24h] [ebp-1Ch]
  unsigned int rep2; // [esp+28h] [ebp-18h]
  unsigned int *i; // [esp+2Ch] [ebp-14h]
  int ia; // [esp+2Ch] [ebp-14h]
  unsigned int *ib; // [esp+2Ch] [ebp-14h]
  int ic; // [esp+2Ch] [ebp-14h]
  int id; // [esp+2Ch] [ebp-14h]
  int ie; // [esp+2Ch] [ebp-14h]
  unsigned int nowPos; // [esp+30h] [ebp-10h]
  int state; // [esp+34h] [ebp-Ch]
  const unsigned __int8 *BufferLim; // [esp+38h] [ebp-8h]
  unsigned int rep0; // [esp+3Ch] [ebp-4h]
  unsigned int rep0a; // [esp+3Ch] [ebp-4h]
  unsigned int rep0b; // [esp+3Ch] [ebp-4h]
  unsigned int *numDirectBits; // [esp+48h] [ebp+8h]
  int numDirectBitsa; // [esp+48h] [ebp+8h]
  int numDirectBitsb; // [esp+48h] [ebp+8h]
  int numDirectBitsc; // [esp+48h] [ebp+8h]
  unsigned __int8 numDirectBits_3; // [esp+4Bh] [ebp+Bh]
  const unsigned __int8 *Buffer; // [esp+50h] [ebp+10h]

  posStateMask = (1 << vs->Properties.pb) - 1;
  Probs = vs->Probs;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v9 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v10 = v9 + vs->Properties.lp;
  p = Probs;
  nowPos = 0;
  numDirectBits_3 = 0;
  lc = v9;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v10 != -1846 )
    memset32(Probs, 1024, (768 << v10) + 1846);
  v11 = inStream;
  v12 = 0;
  v13 = -1;
  BufferLim = &inSize[(_DWORD)inStream];
  for ( j = 0; j < 5; ++j )
  {
    if ( v11 == &inSize[(_DWORD)inStream] )
      return 1;
    v12 = *v11++ | (v12 << 8);
  }
  Buffer = v11;
  if ( outSize == 0 )
    goto LABEL_41;
  do
  {
    offset = nowPos & posStateMask;
    i = &p[16 * state + (nowPos & posStateMask)];
    if ( v13 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v13 <<= 8;
      v12 = *Buffer++ | (v12 << 8);
    }
    v15 = *i;
    v16 = *i * (v13 >> 11);
    if ( v12 >= v16 )
    {
      v26 = v13 - v16;
      v12 -= v16;
      *i = v15 - (v15 >> 5);
      if ( v26 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v26 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v27 = p[state + 192];
      v28 = v27 * (v26 >> 11);
      if ( v12 >= v28 )
      {
        v32 = v26 - v28;
        v12 -= v28;
        p[state + 192] = v27 - (v27 >> 5);
        if ( v32 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v32 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v33 = p[state + 204];
        v34 = v33 * (v32 >> 11);
        if ( v12 >= v34 )
        {
          v41 = v32 - v34;
          v12 -= v34;
          p[state + 204] = v33 - (v33 >> 5);
          if ( v41 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v41 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v42 = p[state + 216];
          v43 = v42 * (v41 >> 11);
          if ( v12 >= v43 )
          {
            v46 = v41 - v43;
            v12 -= v43;
            p[state + 216] = v42 - (v42 >> 5);
            if ( v46 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v46 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v47 = p[state + 228];
            v48 = v47 * (v46 >> 11);
            if ( v12 >= v48 )
            {
              v29 = v46 - v48;
              v12 -= v48;
              p[state + 228] = v47 - (v47 >> 5);
              v45 = rep3;
              rep3 = rep2;
            }
            else
            {
              v29 = v47 * (v46 >> 11);
              v49 = v47 + ((2048 - v47) >> 5);
              v45 = rep2;
              p[state + 228] = v49;
            }
            rep2 = rep1;
          }
          else
          {
            v29 = v42 * (v41 >> 11);
            v44 = v42 + ((2048 - v42) >> 5);
            v45 = rep1;
            p[state + 216] = v44;
          }
          rep1 = rep0;
          rep0 = v45;
        }
        else
        {
          v35 = v33 * (v32 >> 11);
          p[state + 204] = v33 + ((2048 - v33) >> 5);
          v36 = &p[16 * state + 240 + offset];
          ib = v36;
          if ( v35 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v35 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v37 = *v36;
          v38 = *v36 * (v35 >> 11);
          if ( v12 < v38 )
          {
            v13 = v38;
            *ib = v37 + ((2048 - v37) >> 5);
            if ( nowPos != 0 )
            {
              state = 2 * (state >= 7) + 9;
              v39 = nowPos + 1;
              v40 = outStream[nowPos - rep0];
              outStream[v39 - 1] = v40;
              numDirectBits_3 = v40;
              ++nowPos;
              if ( v39 % 0x7A120 == 0 )
                pCallbackFunc();
              continue;
            }
            return 1;
          }
          v29 = v35 - v38;
          v12 -= v38;
          *ib = v37 - (v37 >> 5);
        }
        v30 = state >= 7 ? 11 : 8;
        v31 = p + 1332;
      }
      else
      {
        v29 = v27 * (v26 >> 11);
        rep3 = rep2;
        rep2 = rep1;
        rep1 = rep0;
        p[state + 192] = v27 + ((2048 - v27) >> 5);
        v30 = state < 7 ? 0 : 3;
        v31 = p + 818;
      }
      v50 = Buffer;
      state = v30;
      if ( v29 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v29 <<= 8;
        v12 = *Buffer | (v12 << 8);
        v50 = ++Buffer;
      }
      v51 = *v31;
      v52 = *v31 * (v29 >> 11);
      if ( v12 >= v52 )
      {
        v54 = v29 - v52;
        v12 -= v52;
        *v31 = v51 - (v51 >> 5);
        if ( v54 < 0x1000000 )
        {
          if ( v50 == BufferLim )
            return 1;
          v54 <<= 8;
          v12 = *v50 | (v12 << 8);
          Buffer = v50 + 1;
        }
        v55 = v31[1];
        v56 = v55 * (v54 >> 11);
        if ( v12 >= v56 )
        {
          v13 = v54 - v56;
          v12 -= v56;
          v31[1] = v55 - (v55 >> 5);
          v53 = (int)(v31 + 258);
          offsetb = 16;
          numDirectBitsa = 8;
        }
        else
        {
          v13 = v55 * (v54 >> 11);
          v31[1] = v55 + ((2048 - v55) >> 5);
          v53 = (int)&v31[8 * offset + 130];
          offsetb = 8;
          numDirectBitsa = 3;
        }
      }
      else
      {
        v13 = *v31 * (v29 >> 11);
        *v31 = v51 + ((2048 - v51) >> 5);
        v53 = (int)&v31[8 * offset + 2];
        offsetb = 0;
        numDirectBitsa = 3;
      }
      ic = numDirectBitsa;
      v57 = 1;
      do
      {
        if ( v13 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v13 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v58 = *(_DWORD *)(v53 + 4 * v57);
        v59 = v58 * (v13 >> 11);
        if ( v12 >= v59 )
        {
          v13 -= v59;
          v12 -= v59;
          *(_DWORD *)(v53 + 4 * v57) = v58 - (v58 >> 5);
          v57 = 2 * v57 + 1;
        }
        else
        {
          v13 = v58 * (v13 >> 11);
          *(_DWORD *)(v53 + 4 * v57) = v58 + ((2048 - v58) >> 5);
          v57 *= 2;
        }
        --ic;
      }
      while ( ic != 0 );
      v60 = offsetb - (1 << numDirectBitsa) + v57;
      id = v60;
      if ( state < 4 )
      {
        state += 7;
        if ( v60 >= 4 )
          v60 = 3;
        v61 = (int)&p[64 * v60 + 432];
        numDirectBitsb = 6;
        v62 = 1;
        do
        {
          if ( v13 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v13 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v63 = *(_DWORD *)(v61 + 4 * v62);
          v64 = v63 * (v13 >> 11);
          if ( v12 >= v64 )
          {
            v13 -= v64;
            v12 -= v64;
            *(_DWORD *)(v61 + 4 * v62) = v63 - (v63 >> 5);
            v62 = 2 * v62 + 1;
          }
          else
          {
            v13 = v63 * (v13 >> 11);
            *(_DWORD *)(v61 + 4 * v62) = v63 + ((2048 - v63) >> 5);
            v62 *= 2;
          }
          --numDirectBitsb;
        }
        while ( numDirectBitsb != 0 );
        v65 = v62 - 64;
        if ( v65 < 4 )
        {
          rep0a = v65;
        }
        else
        {
          v66 = (v65 >> 1) - 1;
          v67 = v65 & 1 | 2;
          numDirectBitsc = v66;
          if ( v65 >= 14 )
          {
            v69 = Buffer;
            v70 = v66 - 4;
            do
            {
              if ( v13 < 0x1000000 )
              {
                if ( v69 == BufferLim )
                  return 1;
                v13 <<= 8;
                v12 = *v69++ | (v12 << 8);
                Buffer = v69;
              }
              v13 >>= 1;
              v67 *= 2;
              rep0b = v67;
              if ( v12 >= v13 )
              {
                v12 -= v13;
                v67 |= 1u;
                rep0b = v67;
              }
              --v70;
            }
            while ( v70 != 0 );
            v68 = (int)(p + 802);
            rep0a = 16 * rep0b;
            numDirectBitsc = 4;
          }
          else
          {
            rep0a = (v65 & 1 | 2) << v66;
            v68 = (int)&p[rep0a - v65 + 687];
          }
          v71 = 1;
          offsetc = 1;
          do
          {
            if ( v13 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v13 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v72 = *(_DWORD *)(v68 + 4 * v71);
            v73 = v72 * (v13 >> 11);
            if ( v12 >= v73 )
            {
              v13 -= v73;
              v12 -= v73;
              *(_DWORD *)(v68 + 4 * v71) = v72 - (v72 >> 5);
              rep0a |= offsetc;
              v71 = 2 * v71 + 1;
            }
            else
            {
              v13 = v72 * (v13 >> 11);
              *(_DWORD *)(v68 + 4 * v71) = v72 + ((2048 - v72) >> 5);
              v71 *= 2;
            }
            offsetc *= 2;
            --numDirectBitsc;
          }
          while ( numDirectBitsc != 0 );
        }
        rep0 = rep0a + 1;
        if ( rep0 == 0 )
          break;
      }
      v74 = nowPos;
      ie = id + 2;
      if ( rep0 <= nowPos )
      {
        v75 = &outStream[-rep0];
        do
        {
          v76 = v75[v74];
          outStream[v74] = v76;
          --ie;
          numDirectBits_3 = v76;
          nowPos = ++v74;
          if ( v74 % 0x7A120 == 0 )
          {
            pCallbackFunc();
            v75 = &outStream[-rep0];
          }
          if ( ie == 0 )
            goto LABEL_37;
        }
        while ( v74 < outSize );
        break;
      }
      return 1;
    }
    *i = v15 + ((2048 - v15) >> 5);
    v13 = v16;
    v17 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (numDirectBits_3 >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_19;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v19 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v19 + v17) + 1024);
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v20 = *numDirectBits;
      v21 = *numDirectBits * (v13 >> 11);
      if ( v12 >= v21 )
        break;
      v13 = *numDirectBits * (v13 >> 11);
      v17 *= 2;
      *numDirectBits = v20 + ((2048 - v20) >> 5);
      if ( v19 != 0 )
        goto LABEL_18;
LABEL_26:
      if ( v17 >= 256 )
        goto LABEL_30;
    }
    v13 -= v21;
    v12 -= v21;
    *numDirectBits = v20 - (v20 >> 5);
    v17 = 2 * v17 + 1;
    if ( v19 != 0 )
      goto LABEL_26;
LABEL_18:
    while ( v17 < 256 )
    {
LABEL_19:
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v22 = *(_DWORD *)(ia + 4 * v17);
      v23 = v22 * (v13 >> 11);
      if ( v12 >= v23 )
      {
        v13 -= v23;
        v12 -= v23;
        *(_DWORD *)(ia + 4 * v17) = v22 - (v22 >> 5);
        v17 = 2 * v17 + 1;
      }
      else
      {
        v13 = v22 * (v13 >> 11);
        *(_DWORD *)(ia + 4 * v17) = v22 + ((2048 - v22) >> 5);
        v17 *= 2;
      }
    }
LABEL_30:
    outStream[nowPos] = v17;
    numDirectBits_3 = v17;
    if ( ++nowPos % 0x7A120 == 0 )
      pCallbackFunc();
    if ( state >= 4 )
    {
      if ( state >= 10 )
        v25 = state - 6;
      else
        v25 = state - 3;
      state = v25;
    }
    else
    {
      state = 0;
    }
LABEL_37:
    ;
  }
  while ( nowPos < outSize );
  if ( v13 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_41:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B280
// Name: int LzmaDecode(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecode(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        unsigned int inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int v8; // esi
  unsigned int *Probs; // edi
  int v11; // edx
  int v12; // ecx
  const unsigned __int8 *v13; // ecx
  unsigned int v14; // eax
  int j; // edx
  const unsigned __int8 *v16; // edx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  int v19; // edx
  int k; // ebx
  int v21; // ebx
  unsigned int v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ecx
  unsigned int v25; // edi
  int v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int *v31; // ecx
  int v32; // edx
  unsigned int v33; // eax
  unsigned int v34; // edi
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int *v37; // ebx
  unsigned int v38; // edx
  unsigned int v39; // edi
  unsigned int v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // edx
  unsigned int v43; // edi
  unsigned int v44; // edi
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // edx
  unsigned int v48; // edi
  unsigned int v49; // edi
  unsigned int v50; // edx
  unsigned int v51; // edi
  int v52; // ecx
  unsigned int v53; // eax
  unsigned int v54; // edx
  unsigned int v55; // edi
  int v56; // ebx
  unsigned int v57; // edx
  unsigned int v58; // edi
  int v59; // edx
  int v60; // ebx
  int v61; // ebx
  unsigned int v62; // ecx
  unsigned int v63; // edi
  int v64; // edx
  int v65; // edi
  int v66; // ecx
  int v67; // ebx
  const unsigned __int8 *v68; // edx
  int v69; // edi
  int v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // edi
  unsigned int v73; // ecx
  int v74; // ebx
  unsigned __int8 *m; // edx
  unsigned __int8 v76; // dl
  unsigned int literalPosMask; // [esp+4h] [ebp-38h]
  unsigned int posStateMask; // [esp+8h] [ebp-34h]
  char lc; // [esp+Ch] [ebp-30h]
  unsigned int rep3; // [esp+10h] [ebp-2Ch]
  int offset; // [esp+14h] [ebp-28h]
  int offseta; // [esp+14h] [ebp-28h]
  int offsetb; // [esp+14h] [ebp-28h]
  int offsetc; // [esp+14h] [ebp-28h]
  unsigned int rep1; // [esp+18h] [ebp-24h]
  unsigned int rep2; // [esp+1Ch] [ebp-20h]
  unsigned int *i; // [esp+20h] [ebp-1Ch]
  int ia; // [esp+20h] [ebp-1Ch]
  int ib; // [esp+20h] [ebp-1Ch]
  int ic; // [esp+20h] [ebp-1Ch]
  unsigned int *p; // [esp+24h] [ebp-18h]
  int state; // [esp+28h] [ebp-14h]
  unsigned int nowPos; // [esp+2Ch] [ebp-10h]
  const unsigned __int8 *BufferLim; // [esp+30h] [ebp-Ch]
  unsigned int rep0; // [esp+34h] [ebp-8h]
  unsigned int rep0a; // [esp+34h] [ebp-8h]
  unsigned int rep0b; // [esp+34h] [ebp-8h]
  const unsigned __int8 *Buffer; // [esp+38h] [ebp-4h]
  unsigned int *numDirectBits; // [esp+60h] [ebp+24h]
  int numDirectBitsa; // [esp+60h] [ebp+24h]
  int numDirectBitsb; // [esp+60h] [ebp+24h]
  int numDirectBitsc; // [esp+60h] [ebp+24h]

  v8 = 0;
  if ( pCallbackFunc != nullptr )
    return LzmaDecodeWithCallback(
             vs,
             inStream,
             (const unsigned __int8 *)inSize,
             inSizeProcessed,
             outStream,
             outSize,
             outSizeProcessed,
             pCallbackFunc);
  Probs = vs->Probs;
  posStateMask = (1 << vs->Properties.pb) - 1;
  p = Probs;
  nowPos = 0;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v11 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v12 = v11 + vs->Properties.lp;
  lc = v11;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v12 != -1846 )
    memset32(Probs, 1024, (768 << v12) + 1846);
  v13 = inStream;
  v14 = -1;
  BufferLim = &inStream[inSize];
  for ( j = 0; j < 5; ++j )
  {
    if ( v13 == &inStream[inSize] )
      return 1;
    v8 = *v13++ | (v8 << 8);
  }
  Buffer = v13;
  if ( outSize == 0 )
    goto LABEL_131;
LABEL_9:
  offset = nowPos & posStateMask;
  i = &p[16 * state + (nowPos & posStateMask)];
  v16 = Buffer;
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v14 <<= 8;
    v8 = *Buffer | (v8 << 8);
    v16 = ++Buffer;
  }
  v17 = *i;
  v18 = *i * (v14 >> 11);
  if ( v8 < v18 )
  {
    *i = v17 + ((2048 - v17) >> 5);
    v14 = v18;
    v19 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (HIBYTE(pCallbackFunc) >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_21;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v21 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v21 + v19) + 1024);
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v22 = *numDirectBits;
      v23 = *numDirectBits * (v14 >> 11);
      if ( v8 >= v23 )
      {
        v14 -= v23;
        v8 -= v23;
        *numDirectBits = v22 - (v22 >> 5);
        v19 = 2 * v19 + 1;
        if ( v21 == 0 )
        {
LABEL_20:
          while ( v19 < 256 )
          {
LABEL_21:
            if ( v14 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v14 <<= 8;
              v8 = *Buffer++ | (v8 << 8);
            }
            v24 = *(_DWORD *)(ia + 4 * v19);
            v25 = v24 * (v14 >> 11);
            if ( v8 >= v25 )
            {
              v14 -= v25;
              v8 -= v25;
              *(_DWORD *)(ia + 4 * v19) = v24 - (v24 >> 5);
              v19 = 2 * v19 + 1;
            }
            else
            {
              v14 = v24 * (v14 >> 11);
              *(_DWORD *)(ia + 4 * v19) = v24 + ((2048 - v24) >> 5);
              v19 *= 2;
            }
          }
LABEL_32:
          outStream[nowPos++] = v19;
          HIBYTE(pCallbackFunc) = v19;
          if ( state >= 4 )
          {
            if ( state >= 10 )
              v26 = state - 6;
            else
              v26 = state - 3;
            state = v26;
          }
          else
          {
            state = 0;
          }
LABEL_37:
          if ( nowPos >= outSize )
            goto LABEL_38;
          goto LABEL_9;
        }
      }
      else
      {
        v14 = *numDirectBits * (v14 >> 11);
        v19 *= 2;
        *numDirectBits = v22 + ((2048 - v22) >> 5);
        if ( v21 != 0 )
          goto LABEL_20;
      }
      if ( v19 >= 256 )
        goto LABEL_32;
    }
  }
  v27 = v14 - v18;
  v8 -= v18;
  *i = v17 - (v17 >> 5);
  if ( v27 < 0x1000000 )
  {
    if ( v16 == BufferLim )
      return 1;
    v27 <<= 8;
    v8 = *v16 | (v8 << 8);
    Buffer = v16 + 1;
  }
  v28 = p[state + 192];
  v29 = v28 * (v27 >> 11);
  if ( v8 < v29 )
  {
    rep3 = rep2;
    rep2 = rep1;
    rep1 = rep0;
    v30 = v28 * (v27 >> 11);
    p[state + 192] = v28 + ((2048 - v28) >> 5);
    v31 = p + 818;
    v32 = state < 7 ? 0 : 3;
    goto LABEL_72;
  }
  v33 = v27 - v29;
  v8 -= v29;
  p[state + 192] = v28 - (v28 >> 5);
  if ( v33 < 0x1000000 )
  {
    if ( Buffer != BufferLim )
    {
      v33 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
      goto LABEL_50;
    }
    return 1;
  }
LABEL_50:
  v34 = p[state + 204];
  v35 = v34 * (v33 >> 11);
  if ( v8 >= v35 )
  {
    v41 = v33 - v35;
    v8 -= v35;
    p[state + 204] = v34 - (v34 >> 5);
    if ( v41 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v41 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v42 = p[state + 216];
    v43 = v42 * (v41 >> 11);
    if ( v8 >= v43 )
    {
      v46 = v41 - v43;
      v8 -= v43;
      p[state + 216] = v42 - (v42 >> 5);
      if ( v46 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v46 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v47 = p[state + 228];
      v48 = v47 * (v46 >> 11);
      if ( v8 >= v48 )
      {
        v30 = v46 - v48;
        v8 -= v48;
        p[state + 228] = v47 - (v47 >> 5);
        v45 = rep3;
        rep3 = rep2;
      }
      else
      {
        v30 = v47 * (v46 >> 11);
        v49 = v47 + ((2048 - v47) >> 5);
        v45 = rep2;
        p[state + 228] = v49;
      }
      rep2 = rep1;
    }
    else
    {
      v30 = v42 * (v41 >> 11);
      v44 = v42 + ((2048 - v42) >> 5);
      v45 = rep1;
      p[state + 216] = v44;
    }
    rep1 = rep0;
    rep0 = v45;
  }
  else
  {
    p[state + 204] = v34 + ((2048 - v34) >> 5);
    v36 = v34 * (v33 >> 11);
    v37 = &p[16 * state + 240 + offset];
    if ( v35 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v36 = v35 << 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v38 = *v37;
    v39 = *v37 * (v36 >> 11);
    if ( v8 < v39 )
    {
      v14 = *v37 * (v36 >> 11);
      *v37 = v38 + ((2048 - v38) >> 5);
      if ( nowPos != 0 )
      {
        v40 = nowPos - rep0;
        ++nowPos;
        state = 2 * (state >= 7) + 9;
        LOBYTE(v40) = outStream[v40];
        outStream[nowPos - 1] = v40;
        HIBYTE(pCallbackFunc) = v40;
        goto LABEL_37;
      }
      return 1;
    }
    v30 = v36 - v39;
    v8 -= v39;
    *v37 = v38 - (v38 >> 5);
  }
  v32 = state >= 7 ? 11 : 8;
  v31 = p + 1332;
LABEL_72:
  state = v32;
  if ( v30 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v30 <<= 8;
    v8 = *Buffer++ | (v8 << 8);
  }
  v50 = *v31;
  v51 = *v31 * (v30 >> 11);
  if ( v8 >= v51 )
  {
    v53 = v30 - v51;
    v8 -= v51;
    *v31 = v50 - (v50 >> 5);
    if ( v53 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v53 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v54 = v31[1];
    v55 = v54 * (v53 >> 11);
    if ( v8 >= v55 )
    {
      v14 = v53 - v55;
      v8 -= v55;
      v31[1] = v54 - (v54 >> 5);
      v52 = (int)(v31 + 258);
      offsetb = 16;
      numDirectBitsa = 8;
    }
    else
    {
      v14 = v54 * (v53 >> 11);
      v31[1] = v54 + ((2048 - v54) >> 5);
      v52 = (int)&v31[8 * offset + 130];
      offsetb = 8;
      numDirectBitsa = 3;
    }
  }
  else
  {
    v14 = *v31 * (v30 >> 11);
    *v31 = v50 + ((2048 - v50) >> 5);
    v52 = (int)&v31[8 * offset + 2];
    offsetb = 0;
    numDirectBitsa = 3;
  }
  ib = numDirectBitsa;
  v56 = 1;
  do
  {
    if ( v14 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v14 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v57 = *(_DWORD *)(v52 + 4 * v56);
    v58 = v57 * (v14 >> 11);
    if ( v8 >= v58 )
    {
      v14 -= v58;
      v8 -= v58;
      *(_DWORD *)(v52 + 4 * v56) = v57 - (v57 >> 5);
      v56 = 2 * v56 + 1;
    }
    else
    {
      v14 = v57 * (v14 >> 11);
      *(_DWORD *)(v52 + 4 * v56) = v57 + ((2048 - v57) >> 5);
      v56 *= 2;
    }
    v59 = 1;
    --ib;
  }
  while ( ib != 0 );
  v60 = offsetb - (1 << numDirectBitsa) + v56;
  ic = v60;
  if ( state < 4 )
  {
    state += 7;
    if ( v60 >= 4 )
      v60 = 3;
    v61 = (int)&p[64 * v60 + 432];
    for ( numDirectBitsb = 6; numDirectBitsb != 0; --numDirectBitsb )
    {
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v62 = *(_DWORD *)(v61 + 4 * v59);
      v63 = v62 * (v14 >> 11);
      if ( v8 >= v63 )
      {
        v14 -= v63;
        v8 -= v63;
        *(_DWORD *)(v61 + 4 * v59) = v62 - (v62 >> 5);
        v59 = 2 * v59 + 1;
      }
      else
      {
        v14 = v62 * (v14 >> 11);
        *(_DWORD *)(v61 + 4 * v59) = v62 + ((2048 - v62) >> 5);
        v59 *= 2;
      }
    }
    v64 = v59 - 64;
    if ( v64 < 4 )
    {
      rep0a = v64;
    }
    else
    {
      v65 = (v64 >> 1) - 1;
      v66 = v64 & 1 | 2;
      numDirectBitsc = v65;
      if ( v64 >= 14 )
      {
        v68 = Buffer;
        v69 = v65 - 4;
        do
        {
          if ( v14 < 0x1000000 )
          {
            if ( v68 == BufferLim )
              return 1;
            v14 <<= 8;
            v8 = *v68++ | (v8 << 8);
            Buffer = v68;
          }
          v14 >>= 1;
          v66 *= 2;
          rep0b = v66;
          if ( v8 >= v14 )
          {
            v8 -= v14;
            v66 |= 1u;
            rep0b = v66;
          }
          --v69;
        }
        while ( v69 != 0 );
        v67 = (int)(p + 802);
        rep0a = 16 * rep0b;
        numDirectBitsc = 4;
      }
      else
      {
        rep0a = (v64 & 1 | 2) << v65;
        v67 = (int)&p[rep0a - v64 + 687];
      }
      v70 = 1;
      offsetc = 1;
      do
      {
        if ( v14 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v14 <<= 8;
          v8 = *Buffer++ | (v8 << 8);
        }
        v71 = *(_DWORD *)(v67 + 4 * v70);
        v72 = v71 * (v14 >> 11);
        if ( v8 >= v72 )
        {
          v14 -= v72;
          v8 -= v72;
          *(_DWORD *)(v67 + 4 * v70) = v71 - (v71 >> 5);
          rep0a |= offsetc;
          v70 = 2 * v70 + 1;
        }
        else
        {
          v14 = v71 * (v14 >> 11);
          *(_DWORD *)(v67 + 4 * v70) = v71 + ((2048 - v71) >> 5);
          v70 *= 2;
        }
        offsetc *= 2;
        --numDirectBitsc;
      }
      while ( numDirectBitsc != 0 );
    }
    rep0 = rep0a + 1;
    if ( rep0 == 0 )
      goto LABEL_38;
    v60 = ic;
  }
  v73 = nowPos;
  v74 = v60 + 2;
  if ( rep0 > nowPos )
    return 1;
  for ( m = &outStream[-rep0]; ; m = &outStream[-rep0] )
  {
    v76 = m[v73];
    outStream[v73++] = v76;
    --v74;
    HIBYTE(pCallbackFunc) = v76;
    nowPos = v73;
    if ( v74 == 0 )
      goto LABEL_37;
    if ( v73 >= outSize )
      break;
  }
LABEL_38:
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_131:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002BB60
// Name: public: bool CLZMA::IsCompressed(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLZMA::IsCompressed(CLZMA *this, unsigned __int8 *pInput)
{
  return pInput != nullptr && *(_DWORD *)pInput == 1095588428;
}

//------------------------------------------------------------------------------
// Address: 0x1002BB80
// Name: public: unsigned int CLZMA::GetActualSize(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZMA::GetActualSize(CLZMA *this, unsigned __int8 *pInput)
{
  if ( pInput != nullptr && *(_DWORD *)pInput == 1095588428 )
    return *((_DWORD *)pInput + 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002BBA0
// Name: public: unsigned int CLZMA::Uncompress(unsigned char __near *,unsigned char __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZMA::Uncompress(
        CLZMA *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        void (__cdecl *pCallback)())
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ebx
  unsigned int *v6; // edi
  int v7; // esi
  unsigned __int8 *result; // eax
  unsigned int v9; // [esp-1Ch] [ebp-34h]
  _CLzmaDecoderState state; // [esp+8h] [ebp-10h] BYREF

  v4 = pInput;
  if ( pInput == nullptr )
    return nullptr;
  if ( *(_DWORD *)pInput != 1095588428 )
    return nullptr;
  v5 = *((unsigned __int8 **)pInput + 1);
  if ( v5 == nullptr )
    return nullptr;
  LzmaDecodeProperties(propsRes: &state.Properties, propsData: pInput + 12, size: 5);
  v6 = (unsigned int *)_g_pMemAlloc->Alloc_2(
                         this: _g_pMemAlloc,
                         a2: 4 * (768 << (LOBYTE(state.Properties.lp) + LOBYTE(state.Properties.lc))) + 7384);
  v9 = *((_DWORD *)v4 + 2);
  state.Probs = v6;
  v7 = LzmaDecode(
         vs: &state,
         inStream: v4 + 17,
         inSize: v9,
         inSizeProcessed: (unsigned int *)&pCallback,
         outStream: pOutput,
         outSize: (unsigned int)v5,
         outSizeProcessed: (unsigned int *)&pInput,
         pCallbackFunc: pCallback);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  if ( v7 != 0 )
    return nullptr;
  result = pInput;
  if ( pInput != v5 )
    return nullptr;
  return result;
}

} // namespace FileSystem_Stdio

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x100D81E0
// Name: int LzmaDecodeProperties(struct _CLzmaProperties __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeProperties(_CLzmaProperties *propsRes, unsigned __int8 *propsData, int size)
{
  unsigned __int8 v4; // cl
  unsigned int v5; // eax
  int v6; // edx
  unsigned int v7; // eax
  int v8; // edx

  if ( size < 5 )
    return 1;
  v4 = *propsData;
  if ( *propsData >= 0xE1u )
    return 1;
  propsRes->pb = 0;
  if ( v4 >= 0x2Du )
  {
    v5 = v4 / 0x2Du;
    v6 = v5;
    do
    {
      v4 -= 45;
      --v5;
    }
    while ( v5 != 0 );
    propsRes->pb = v6;
  }
  propsRes->lp = 0;
  if ( v4 >= 9u )
  {
    v7 = v4 / 9u;
    v8 = v7;
    do
    {
      v4 -= 9;
      --v7;
    }
    while ( v7 != 0 );
    propsRes->lp = v8;
  }
  propsRes->lc = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D8270
// Name: int LzmaDecodeWithCallback(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeWithCallback(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        const unsigned __int8 *inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int *Probs; // edi
  int v9; // edx
  int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // esi
  int j; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // eax
  int k; // ebx
  int v19; // ebx
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v25; // eax
  unsigned int v26; // esi
  unsigned int v27; // edx
  unsigned int v28; // ebx
  unsigned int v29; // esi
  int v30; // edx
  unsigned int *v31; // eax
  unsigned int v32; // esi
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned int v35; // esi
  unsigned int *v36; // ebx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  unsigned int v39; // ecx
  unsigned __int8 v40; // dl
  unsigned int v41; // esi
  unsigned int v42; // edx
  unsigned int v43; // ebx
  unsigned int v44; // ebx
  unsigned int v45; // edx
  unsigned int v46; // esi
  unsigned int v47; // edx
  unsigned int v48; // ebx
  unsigned int v49; // ebx
  const unsigned __int8 *v50; // ebx
  unsigned int v51; // ecx
  unsigned int v52; // edx
  int v53; // ecx
  unsigned int v54; // esi
  unsigned int v55; // ecx
  unsigned int v56; // edx
  int v57; // ebx
  unsigned int v58; // eax
  unsigned int v59; // edx
  int v60; // ebx
  int v61; // ebx
  int v62; // eax
  unsigned int v63; // ecx
  unsigned int v64; // edx
  int v65; // eax
  int v66; // edx
  int v67; // ecx
  int v68; // ebx
  const unsigned __int8 *v69; // eax
  int v70; // edx
  int v71; // ecx
  unsigned int v72; // eax
  unsigned int v73; // edx
  unsigned int v74; // ebx
  unsigned __int8 *v75; // ecx
  unsigned __int8 v76; // al
  unsigned int literalPosMask; // [esp+Ch] [ebp-34h]
  unsigned int posStateMask; // [esp+10h] [ebp-30h]
  char lc; // [esp+14h] [ebp-2Ch]
  int offset; // [esp+18h] [ebp-28h]
  int offseta; // [esp+18h] [ebp-28h]
  int offsetb; // [esp+18h] [ebp-28h]
  int offsetc; // [esp+18h] [ebp-28h]
  unsigned int rep3; // [esp+1Ch] [ebp-24h]
  unsigned int *p; // [esp+20h] [ebp-20h]
  unsigned int rep1; // [esp+24h] [ebp-1Ch]
  unsigned int rep2; // [esp+28h] [ebp-18h]
  unsigned int *i; // [esp+2Ch] [ebp-14h]
  int ia; // [esp+2Ch] [ebp-14h]
  unsigned int *ib; // [esp+2Ch] [ebp-14h]
  int ic; // [esp+2Ch] [ebp-14h]
  int id; // [esp+2Ch] [ebp-14h]
  int ie; // [esp+2Ch] [ebp-14h]
  unsigned int nowPos; // [esp+30h] [ebp-10h]
  int state; // [esp+34h] [ebp-Ch]
  const unsigned __int8 *BufferLim; // [esp+38h] [ebp-8h]
  unsigned int rep0; // [esp+3Ch] [ebp-4h]
  unsigned int rep0a; // [esp+3Ch] [ebp-4h]
  unsigned int rep0b; // [esp+3Ch] [ebp-4h]
  unsigned int *numDirectBits; // [esp+48h] [ebp+8h]
  int numDirectBitsa; // [esp+48h] [ebp+8h]
  int numDirectBitsb; // [esp+48h] [ebp+8h]
  int numDirectBitsc; // [esp+48h] [ebp+8h]
  unsigned __int8 numDirectBits_3; // [esp+4Bh] [ebp+Bh]
  const unsigned __int8 *Buffer; // [esp+50h] [ebp+10h]

  posStateMask = (1 << vs->Properties.pb) - 1;
  Probs = vs->Probs;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v9 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v10 = v9 + vs->Properties.lp;
  p = Probs;
  nowPos = 0;
  numDirectBits_3 = 0;
  lc = v9;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v10 != -1846 )
    memset32(Probs, 1024, (768 << v10) + 1846);
  v11 = inStream;
  v12 = 0;
  v13 = -1;
  BufferLim = &inSize[(_DWORD)inStream];
  for ( j = 0; j < 5; ++j )
  {
    if ( v11 == &inSize[(_DWORD)inStream] )
      return 1;
    v12 = *v11++ | (v12 << 8);
  }
  Buffer = v11;
  if ( outSize == 0 )
    goto LABEL_41;
  do
  {
    offset = nowPos & posStateMask;
    i = &p[16 * state + (nowPos & posStateMask)];
    if ( v13 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v13 <<= 8;
      v12 = *Buffer++ | (v12 << 8);
    }
    v15 = *i;
    v16 = *i * (v13 >> 11);
    if ( v12 >= v16 )
    {
      v26 = v13 - v16;
      v12 -= v16;
      *i = v15 - (v15 >> 5);
      if ( v26 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v26 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v27 = p[state + 192];
      v28 = v27 * (v26 >> 11);
      if ( v12 >= v28 )
      {
        v32 = v26 - v28;
        v12 -= v28;
        p[state + 192] = v27 - (v27 >> 5);
        if ( v32 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v32 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v33 = p[state + 204];
        v34 = v33 * (v32 >> 11);
        if ( v12 >= v34 )
        {
          v41 = v32 - v34;
          v12 -= v34;
          p[state + 204] = v33 - (v33 >> 5);
          if ( v41 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v41 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v42 = p[state + 216];
          v43 = v42 * (v41 >> 11);
          if ( v12 >= v43 )
          {
            v46 = v41 - v43;
            v12 -= v43;
            p[state + 216] = v42 - (v42 >> 5);
            if ( v46 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v46 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v47 = p[state + 228];
            v48 = v47 * (v46 >> 11);
            if ( v12 >= v48 )
            {
              v29 = v46 - v48;
              v12 -= v48;
              p[state + 228] = v47 - (v47 >> 5);
              v45 = rep3;
              rep3 = rep2;
            }
            else
            {
              v29 = v47 * (v46 >> 11);
              v49 = v47 + ((2048 - v47) >> 5);
              v45 = rep2;
              p[state + 228] = v49;
            }
            rep2 = rep1;
          }
          else
          {
            v29 = v42 * (v41 >> 11);
            v44 = v42 + ((2048 - v42) >> 5);
            v45 = rep1;
            p[state + 216] = v44;
          }
          rep1 = rep0;
          rep0 = v45;
        }
        else
        {
          v35 = v33 * (v32 >> 11);
          p[state + 204] = v33 + ((2048 - v33) >> 5);
          v36 = &p[16 * state + 240 + offset];
          ib = v36;
          if ( v35 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v35 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v37 = *v36;
          v38 = *v36 * (v35 >> 11);
          if ( v12 < v38 )
          {
            v13 = v38;
            *ib = v37 + ((2048 - v37) >> 5);
            if ( nowPos != 0 )
            {
              state = 2 * (state >= 7) + 9;
              v39 = nowPos + 1;
              v40 = outStream[nowPos - rep0];
              outStream[v39 - 1] = v40;
              numDirectBits_3 = v40;
              ++nowPos;
              if ( v39 % 0x7A120 == 0 )
                pCallbackFunc();
              continue;
            }
            return 1;
          }
          v29 = v35 - v38;
          v12 -= v38;
          *ib = v37 - (v37 >> 5);
        }
        v30 = state >= 7 ? 11 : 8;
        v31 = p + 1332;
      }
      else
      {
        v29 = v27 * (v26 >> 11);
        rep3 = rep2;
        rep2 = rep1;
        rep1 = rep0;
        p[state + 192] = v27 + ((2048 - v27) >> 5);
        v30 = state < 7 ? 0 : 3;
        v31 = p + 818;
      }
      v50 = Buffer;
      state = v30;
      if ( v29 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v29 <<= 8;
        v12 = *Buffer | (v12 << 8);
        v50 = ++Buffer;
      }
      v51 = *v31;
      v52 = *v31 * (v29 >> 11);
      if ( v12 >= v52 )
      {
        v54 = v29 - v52;
        v12 -= v52;
        *v31 = v51 - (v51 >> 5);
        if ( v54 < 0x1000000 )
        {
          if ( v50 == BufferLim )
            return 1;
          v54 <<= 8;
          v12 = *v50 | (v12 << 8);
          Buffer = v50 + 1;
        }
        v55 = v31[1];
        v56 = v55 * (v54 >> 11);
        if ( v12 >= v56 )
        {
          v13 = v54 - v56;
          v12 -= v56;
          v31[1] = v55 - (v55 >> 5);
          v53 = (int)(v31 + 258);
          offsetb = 16;
          numDirectBitsa = 8;
        }
        else
        {
          v13 = v55 * (v54 >> 11);
          v31[1] = v55 + ((2048 - v55) >> 5);
          v53 = (int)&v31[8 * offset + 130];
          offsetb = 8;
          numDirectBitsa = 3;
        }
      }
      else
      {
        v13 = *v31 * (v29 >> 11);
        *v31 = v51 + ((2048 - v51) >> 5);
        v53 = (int)&v31[8 * offset + 2];
        offsetb = 0;
        numDirectBitsa = 3;
      }
      ic = numDirectBitsa;
      v57 = 1;
      do
      {
        if ( v13 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v13 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v58 = *(_DWORD *)(v53 + 4 * v57);
        v59 = v58 * (v13 >> 11);
        if ( v12 >= v59 )
        {
          v13 -= v59;
          v12 -= v59;
          *(_DWORD *)(v53 + 4 * v57) = v58 - (v58 >> 5);
          v57 = 2 * v57 + 1;
        }
        else
        {
          v13 = v58 * (v13 >> 11);
          *(_DWORD *)(v53 + 4 * v57) = v58 + ((2048 - v58) >> 5);
          v57 *= 2;
        }
        --ic;
      }
      while ( ic != 0 );
      v60 = offsetb - (1 << numDirectBitsa) + v57;
      id = v60;
      if ( state < 4 )
      {
        state += 7;
        if ( v60 >= 4 )
          v60 = 3;
        v61 = (int)&p[64 * v60 + 432];
        numDirectBitsb = 6;
        v62 = 1;
        do
        {
          if ( v13 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v13 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v63 = *(_DWORD *)(v61 + 4 * v62);
          v64 = v63 * (v13 >> 11);
          if ( v12 >= v64 )
          {
            v13 -= v64;
            v12 -= v64;
            *(_DWORD *)(v61 + 4 * v62) = v63 - (v63 >> 5);
            v62 = 2 * v62 + 1;
          }
          else
          {
            v13 = v63 * (v13 >> 11);
            *(_DWORD *)(v61 + 4 * v62) = v63 + ((2048 - v63) >> 5);
            v62 *= 2;
          }
          --numDirectBitsb;
        }
        while ( numDirectBitsb != 0 );
        v65 = v62 - 64;
        if ( v65 < 4 )
        {
          rep0a = v65;
        }
        else
        {
          v66 = (v65 >> 1) - 1;
          v67 = v65 & 1 | 2;
          numDirectBitsc = v66;
          if ( v65 >= 14 )
          {
            v69 = Buffer;
            v70 = v66 - 4;
            do
            {
              if ( v13 < 0x1000000 )
              {
                if ( v69 == BufferLim )
                  return 1;
                v13 <<= 8;
                v12 = *v69++ | (v12 << 8);
                Buffer = v69;
              }
              v13 >>= 1;
              v67 *= 2;
              rep0b = v67;
              if ( v12 >= v13 )
              {
                v12 -= v13;
                v67 |= 1u;
                rep0b = v67;
              }
              --v70;
            }
            while ( v70 != 0 );
            v68 = (int)(p + 802);
            rep0a = 16 * rep0b;
            numDirectBitsc = 4;
          }
          else
          {
            rep0a = (v65 & 1 | 2) << v66;
            v68 = (int)&p[rep0a - v65 + 687];
          }
          v71 = 1;
          offsetc = 1;
          do
          {
            if ( v13 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v13 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v72 = *(_DWORD *)(v68 + 4 * v71);
            v73 = v72 * (v13 >> 11);
            if ( v12 >= v73 )
            {
              v13 -= v73;
              v12 -= v73;
              *(_DWORD *)(v68 + 4 * v71) = v72 - (v72 >> 5);
              rep0a |= offsetc;
              v71 = 2 * v71 + 1;
            }
            else
            {
              v13 = v72 * (v13 >> 11);
              *(_DWORD *)(v68 + 4 * v71) = v72 + ((2048 - v72) >> 5);
              v71 *= 2;
            }
            offsetc *= 2;
            --numDirectBitsc;
          }
          while ( numDirectBitsc != 0 );
        }
        rep0 = rep0a + 1;
        if ( rep0 == 0 )
          break;
      }
      v74 = nowPos;
      ie = id + 2;
      if ( rep0 <= nowPos )
      {
        v75 = &outStream[-rep0];
        do
        {
          v76 = v75[v74];
          outStream[v74] = v76;
          --ie;
          numDirectBits_3 = v76;
          nowPos = ++v74;
          if ( v74 % 0x7A120 == 0 )
          {
            pCallbackFunc();
            v75 = &outStream[-rep0];
          }
          if ( ie == 0 )
            goto LABEL_37;
        }
        while ( v74 < outSize );
        break;
      }
      return 1;
    }
    *i = v15 + ((2048 - v15) >> 5);
    v13 = v16;
    v17 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (numDirectBits_3 >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_19;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v19 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v19 + v17) + 1024);
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v20 = *numDirectBits;
      v21 = *numDirectBits * (v13 >> 11);
      if ( v12 >= v21 )
        break;
      v13 = *numDirectBits * (v13 >> 11);
      v17 *= 2;
      *numDirectBits = v20 + ((2048 - v20) >> 5);
      if ( v19 != 0 )
        goto LABEL_18;
LABEL_26:
      if ( v17 >= 256 )
        goto LABEL_30;
    }
    v13 -= v21;
    v12 -= v21;
    *numDirectBits = v20 - (v20 >> 5);
    v17 = 2 * v17 + 1;
    if ( v19 != 0 )
      goto LABEL_26;
LABEL_18:
    while ( v17 < 256 )
    {
LABEL_19:
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v22 = *(_DWORD *)(ia + 4 * v17);
      v23 = v22 * (v13 >> 11);
      if ( v12 >= v23 )
      {
        v13 -= v23;
        v12 -= v23;
        *(_DWORD *)(ia + 4 * v17) = v22 - (v22 >> 5);
        v17 = 2 * v17 + 1;
      }
      else
      {
        v13 = v22 * (v13 >> 11);
        *(_DWORD *)(ia + 4 * v17) = v22 + ((2048 - v22) >> 5);
        v17 *= 2;
      }
    }
LABEL_30:
    outStream[nowPos] = v17;
    numDirectBits_3 = v17;
    if ( ++nowPos % 0x7A120 == 0 )
      pCallbackFunc();
    if ( state >= 4 )
    {
      if ( state >= 10 )
        v25 = state - 6;
      else
        v25 = state - 3;
      state = v25;
    }
    else
    {
      state = 0;
    }
LABEL_37:
    ;
  }
  while ( nowPos < outSize );
  if ( v13 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_41:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D8B90
// Name: int LzmaDecode(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecode(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        unsigned int inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int v8; // esi
  unsigned int *Probs; // edi
  int v11; // edx
  int v12; // ecx
  const unsigned __int8 *v13; // ecx
  unsigned int v14; // eax
  int j; // edx
  const unsigned __int8 *v16; // edx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  int v19; // edx
  int k; // ebx
  int v21; // ebx
  unsigned int v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ecx
  unsigned int v25; // edi
  int v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int *v31; // ecx
  int v32; // edx
  unsigned int v33; // eax
  unsigned int v34; // edi
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int *v37; // ebx
  unsigned int v38; // edx
  unsigned int v39; // edi
  unsigned int v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // edx
  unsigned int v43; // edi
  unsigned int v44; // edi
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // edx
  unsigned int v48; // edi
  unsigned int v49; // edi
  unsigned int v50; // edx
  unsigned int v51; // edi
  int v52; // ecx
  unsigned int v53; // eax
  unsigned int v54; // edx
  unsigned int v55; // edi
  int v56; // ebx
  unsigned int v57; // edx
  unsigned int v58; // edi
  int v59; // edx
  int v60; // ebx
  int v61; // ebx
  unsigned int v62; // ecx
  unsigned int v63; // edi
  int v64; // edx
  int v65; // edi
  int v66; // ecx
  int v67; // ebx
  const unsigned __int8 *v68; // edx
  int v69; // edi
  int v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // edi
  unsigned int v73; // ecx
  int v74; // ebx
  unsigned __int8 *m; // edx
  unsigned __int8 v76; // dl
  unsigned int literalPosMask; // [esp+4h] [ebp-38h]
  unsigned int posStateMask; // [esp+8h] [ebp-34h]
  char lc; // [esp+Ch] [ebp-30h]
  unsigned int rep3; // [esp+10h] [ebp-2Ch]
  int offset; // [esp+14h] [ebp-28h]
  int offseta; // [esp+14h] [ebp-28h]
  int offsetb; // [esp+14h] [ebp-28h]
  int offsetc; // [esp+14h] [ebp-28h]
  unsigned int rep1; // [esp+18h] [ebp-24h]
  unsigned int rep2; // [esp+1Ch] [ebp-20h]
  unsigned int *i; // [esp+20h] [ebp-1Ch]
  int ia; // [esp+20h] [ebp-1Ch]
  int ib; // [esp+20h] [ebp-1Ch]
  int ic; // [esp+20h] [ebp-1Ch]
  unsigned int *p; // [esp+24h] [ebp-18h]
  int state; // [esp+28h] [ebp-14h]
  unsigned int nowPos; // [esp+2Ch] [ebp-10h]
  const unsigned __int8 *BufferLim; // [esp+30h] [ebp-Ch]
  unsigned int rep0; // [esp+34h] [ebp-8h]
  unsigned int rep0a; // [esp+34h] [ebp-8h]
  unsigned int rep0b; // [esp+34h] [ebp-8h]
  const unsigned __int8 *Buffer; // [esp+38h] [ebp-4h]
  unsigned int *numDirectBits; // [esp+60h] [ebp+24h]
  int numDirectBitsa; // [esp+60h] [ebp+24h]
  int numDirectBitsb; // [esp+60h] [ebp+24h]
  int numDirectBitsc; // [esp+60h] [ebp+24h]

  v8 = 0;
  if ( pCallbackFunc != nullptr )
    return LzmaDecodeWithCallback(
             vs,
             inStream,
             (const unsigned __int8 *)inSize,
             inSizeProcessed,
             outStream,
             outSize,
             outSizeProcessed,
             pCallbackFunc);
  Probs = vs->Probs;
  posStateMask = (1 << vs->Properties.pb) - 1;
  p = Probs;
  nowPos = 0;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v11 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v12 = v11 + vs->Properties.lp;
  lc = v11;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v12 != -1846 )
    memset32(Probs, 1024, (768 << v12) + 1846);
  v13 = inStream;
  v14 = -1;
  BufferLim = &inStream[inSize];
  for ( j = 0; j < 5; ++j )
  {
    if ( v13 == &inStream[inSize] )
      return 1;
    v8 = *v13++ | (v8 << 8);
  }
  Buffer = v13;
  if ( outSize == 0 )
    goto LABEL_131;
LABEL_9:
  offset = nowPos & posStateMask;
  i = &p[16 * state + (nowPos & posStateMask)];
  v16 = Buffer;
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v14 <<= 8;
    v8 = *Buffer | (v8 << 8);
    v16 = ++Buffer;
  }
  v17 = *i;
  v18 = *i * (v14 >> 11);
  if ( v8 < v18 )
  {
    *i = v17 + ((2048 - v17) >> 5);
    v14 = v18;
    v19 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (HIBYTE(pCallbackFunc) >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_21;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v21 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v21 + v19) + 1024);
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v22 = *numDirectBits;
      v23 = *numDirectBits * (v14 >> 11);
      if ( v8 >= v23 )
      {
        v14 -= v23;
        v8 -= v23;
        *numDirectBits = v22 - (v22 >> 5);
        v19 = 2 * v19 + 1;
        if ( v21 == 0 )
        {
LABEL_20:
          while ( v19 < 256 )
          {
LABEL_21:
            if ( v14 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v14 <<= 8;
              v8 = *Buffer++ | (v8 << 8);
            }
            v24 = *(_DWORD *)(ia + 4 * v19);
            v25 = v24 * (v14 >> 11);
            if ( v8 >= v25 )
            {
              v14 -= v25;
              v8 -= v25;
              *(_DWORD *)(ia + 4 * v19) = v24 - (v24 >> 5);
              v19 = 2 * v19 + 1;
            }
            else
            {
              v14 = v24 * (v14 >> 11);
              *(_DWORD *)(ia + 4 * v19) = v24 + ((2048 - v24) >> 5);
              v19 *= 2;
            }
          }
LABEL_32:
          outStream[nowPos++] = v19;
          HIBYTE(pCallbackFunc) = v19;
          if ( state >= 4 )
          {
            if ( state >= 10 )
              v26 = state - 6;
            else
              v26 = state - 3;
            state = v26;
          }
          else
          {
            state = 0;
          }
LABEL_37:
          if ( nowPos >= outSize )
            goto LABEL_38;
          goto LABEL_9;
        }
      }
      else
      {
        v14 = *numDirectBits * (v14 >> 11);
        v19 *= 2;
        *numDirectBits = v22 + ((2048 - v22) >> 5);
        if ( v21 != 0 )
          goto LABEL_20;
      }
      if ( v19 >= 256 )
        goto LABEL_32;
    }
  }
  v27 = v14 - v18;
  v8 -= v18;
  *i = v17 - (v17 >> 5);
  if ( v27 < 0x1000000 )
  {
    if ( v16 == BufferLim )
      return 1;
    v27 <<= 8;
    v8 = *v16 | (v8 << 8);
    Buffer = v16 + 1;
  }
  v28 = p[state + 192];
  v29 = v28 * (v27 >> 11);
  if ( v8 < v29 )
  {
    rep3 = rep2;
    rep2 = rep1;
    rep1 = rep0;
    v30 = v28 * (v27 >> 11);
    p[state + 192] = v28 + ((2048 - v28) >> 5);
    v31 = p + 818;
    v32 = state < 7 ? 0 : 3;
    goto LABEL_72;
  }
  v33 = v27 - v29;
  v8 -= v29;
  p[state + 192] = v28 - (v28 >> 5);
  if ( v33 < 0x1000000 )
  {
    if ( Buffer != BufferLim )
    {
      v33 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
      goto LABEL_50;
    }
    return 1;
  }
LABEL_50:
  v34 = p[state + 204];
  v35 = v34 * (v33 >> 11);
  if ( v8 >= v35 )
  {
    v41 = v33 - v35;
    v8 -= v35;
    p[state + 204] = v34 - (v34 >> 5);
    if ( v41 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v41 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v42 = p[state + 216];
    v43 = v42 * (v41 >> 11);
    if ( v8 >= v43 )
    {
      v46 = v41 - v43;
      v8 -= v43;
      p[state + 216] = v42 - (v42 >> 5);
      if ( v46 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v46 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v47 = p[state + 228];
      v48 = v47 * (v46 >> 11);
      if ( v8 >= v48 )
      {
        v30 = v46 - v48;
        v8 -= v48;
        p[state + 228] = v47 - (v47 >> 5);
        v45 = rep3;
        rep3 = rep2;
      }
      else
      {
        v30 = v47 * (v46 >> 11);
        v49 = v47 + ((2048 - v47) >> 5);
        v45 = rep2;
        p[state + 228] = v49;
      }
      rep2 = rep1;
    }
    else
    {
      v30 = v42 * (v41 >> 11);
      v44 = v42 + ((2048 - v42) >> 5);
      v45 = rep1;
      p[state + 216] = v44;
    }
    rep1 = rep0;
    rep0 = v45;
  }
  else
  {
    p[state + 204] = v34 + ((2048 - v34) >> 5);
    v36 = v34 * (v33 >> 11);
    v37 = &p[16 * state + 240 + offset];
    if ( v35 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v36 = v35 << 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v38 = *v37;
    v39 = *v37 * (v36 >> 11);
    if ( v8 < v39 )
    {
      v14 = *v37 * (v36 >> 11);
      *v37 = v38 + ((2048 - v38) >> 5);
      if ( nowPos != 0 )
      {
        v40 = nowPos - rep0;
        ++nowPos;
        state = 2 * (state >= 7) + 9;
        LOBYTE(v40) = outStream[v40];
        outStream[nowPos - 1] = v40;
        HIBYTE(pCallbackFunc) = v40;
        goto LABEL_37;
      }
      return 1;
    }
    v30 = v36 - v39;
    v8 -= v39;
    *v37 = v38 - (v38 >> 5);
  }
  v32 = state >= 7 ? 11 : 8;
  v31 = p + 1332;
LABEL_72:
  state = v32;
  if ( v30 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v30 <<= 8;
    v8 = *Buffer++ | (v8 << 8);
  }
  v50 = *v31;
  v51 = *v31 * (v30 >> 11);
  if ( v8 >= v51 )
  {
    v53 = v30 - v51;
    v8 -= v51;
    *v31 = v50 - (v50 >> 5);
    if ( v53 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v53 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v54 = v31[1];
    v55 = v54 * (v53 >> 11);
    if ( v8 >= v55 )
    {
      v14 = v53 - v55;
      v8 -= v55;
      v31[1] = v54 - (v54 >> 5);
      v52 = (int)(v31 + 258);
      offsetb = 16;
      numDirectBitsa = 8;
    }
    else
    {
      v14 = v54 * (v53 >> 11);
      v31[1] = v54 + ((2048 - v54) >> 5);
      v52 = (int)&v31[8 * offset + 130];
      offsetb = 8;
      numDirectBitsa = 3;
    }
  }
  else
  {
    v14 = *v31 * (v30 >> 11);
    *v31 = v50 + ((2048 - v50) >> 5);
    v52 = (int)&v31[8 * offset + 2];
    offsetb = 0;
    numDirectBitsa = 3;
  }
  ib = numDirectBitsa;
  v56 = 1;
  do
  {
    if ( v14 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v14 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v57 = *(_DWORD *)(v52 + 4 * v56);
    v58 = v57 * (v14 >> 11);
    if ( v8 >= v58 )
    {
      v14 -= v58;
      v8 -= v58;
      *(_DWORD *)(v52 + 4 * v56) = v57 - (v57 >> 5);
      v56 = 2 * v56 + 1;
    }
    else
    {
      v14 = v57 * (v14 >> 11);
      *(_DWORD *)(v52 + 4 * v56) = v57 + ((2048 - v57) >> 5);
      v56 *= 2;
    }
    v59 = 1;
    --ib;
  }
  while ( ib != 0 );
  v60 = offsetb - (1 << numDirectBitsa) + v56;
  ic = v60;
  if ( state < 4 )
  {
    state += 7;
    if ( v60 >= 4 )
      v60 = 3;
    v61 = (int)&p[64 * v60 + 432];
    for ( numDirectBitsb = 6; numDirectBitsb != 0; --numDirectBitsb )
    {
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v62 = *(_DWORD *)(v61 + 4 * v59);
      v63 = v62 * (v14 >> 11);
      if ( v8 >= v63 )
      {
        v14 -= v63;
        v8 -= v63;
        *(_DWORD *)(v61 + 4 * v59) = v62 - (v62 >> 5);
        v59 = 2 * v59 + 1;
      }
      else
      {
        v14 = v62 * (v14 >> 11);
        *(_DWORD *)(v61 + 4 * v59) = v62 + ((2048 - v62) >> 5);
        v59 *= 2;
      }
    }
    v64 = v59 - 64;
    if ( v64 < 4 )
    {
      rep0a = v64;
    }
    else
    {
      v65 = (v64 >> 1) - 1;
      v66 = v64 & 1 | 2;
      numDirectBitsc = v65;
      if ( v64 >= 14 )
      {
        v68 = Buffer;
        v69 = v65 - 4;
        do
        {
          if ( v14 < 0x1000000 )
          {
            if ( v68 == BufferLim )
              return 1;
            v14 <<= 8;
            v8 = *v68++ | (v8 << 8);
            Buffer = v68;
          }
          v14 >>= 1;
          v66 *= 2;
          rep0b = v66;
          if ( v8 >= v14 )
          {
            v8 -= v14;
            v66 |= 1u;
            rep0b = v66;
          }
          --v69;
        }
        while ( v69 != 0 );
        v67 = (int)(p + 802);
        rep0a = 16 * rep0b;
        numDirectBitsc = 4;
      }
      else
      {
        rep0a = (v64 & 1 | 2) << v65;
        v67 = (int)&p[rep0a - v64 + 687];
      }
      v70 = 1;
      offsetc = 1;
      do
      {
        if ( v14 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v14 <<= 8;
          v8 = *Buffer++ | (v8 << 8);
        }
        v71 = *(_DWORD *)(v67 + 4 * v70);
        v72 = v71 * (v14 >> 11);
        if ( v8 >= v72 )
        {
          v14 -= v72;
          v8 -= v72;
          *(_DWORD *)(v67 + 4 * v70) = v71 - (v71 >> 5);
          rep0a |= offsetc;
          v70 = 2 * v70 + 1;
        }
        else
        {
          v14 = v71 * (v14 >> 11);
          *(_DWORD *)(v67 + 4 * v70) = v71 + ((2048 - v71) >> 5);
          v70 *= 2;
        }
        offsetc *= 2;
        --numDirectBitsc;
      }
      while ( numDirectBitsc != 0 );
    }
    rep0 = rep0a + 1;
    if ( rep0 == 0 )
      goto LABEL_38;
    v60 = ic;
  }
  v73 = nowPos;
  v74 = v60 + 2;
  if ( rep0 > nowPos )
    return 1;
  for ( m = &outStream[-rep0]; ; m = &outStream[-rep0] )
  {
    v76 = m[v73];
    outStream[v73++] = v76;
    --v74;
    HIBYTE(pCallbackFunc) = v76;
    nowPos = v73;
    if ( v74 == 0 )
      goto LABEL_37;
    if ( v73 >= outSize )
      break;
  }
LABEL_38:
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_131:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D9470
// Name: public: unsigned int CLZMA::Uncompress(unsigned char __near *,unsigned char __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZMA::Uncompress(
        CLZMA *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        void (__cdecl *pCallback)())
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ebx
  unsigned int *v6; // edi
  int v7; // esi
  unsigned __int8 *result; // eax
  unsigned int v9; // [esp-1Ch] [ebp-34h]
  _CLzmaDecoderState state; // [esp+8h] [ebp-10h] BYREF

  v4 = pInput;
  if ( pInput == nullptr )
    return nullptr;
  if ( *(_DWORD *)pInput != 1095588428 )
    return nullptr;
  v5 = *((unsigned __int8 **)pInput + 1);
  if ( v5 == nullptr )
    return nullptr;
  LzmaDecodeProperties(propsRes: &state.Properties, propsData: pInput + 12, size: 5);
  v6 = (unsigned int *)_g_pMemAlloc->Alloc_2(
                         this: _g_pMemAlloc,
                         a2: 4 * (768 << (LOBYTE(state.Properties.lp) + LOBYTE(state.Properties.lc))) + 7384);
  v9 = *((_DWORD *)v4 + 2);
  state.Probs = v6;
  v7 = LzmaDecode(
         vs: &state,
         inStream: v4 + 17,
         inSize: v9,
         inSizeProcessed: (unsigned int *)&pCallback,
         outStream: pOutput,
         outSize: (unsigned int)v5,
         outSizeProcessed: (unsigned int *)&pInput,
         pCallbackFunc: pCallback);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  if ( v7 != 0 )
    return nullptr;
  result = pInput;
  if ( pInput != v5 )
    return nullptr;
  return result;
}

} // namespace shaderapidx9

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10034DB0
// Name: int LzmaDecodeProperties(struct _CLzmaProperties __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeProperties(_CLzmaProperties *propsRes, unsigned __int8 *propsData, int size)
{
  unsigned __int8 v4; // cl
  unsigned int v5; // eax
  int v6; // edx
  unsigned int v7; // eax
  int v8; // edx

  if ( size < 5 )
    return 1;
  v4 = *propsData;
  if ( *propsData >= 0xE1u )
    return 1;
  propsRes->pb = 0;
  if ( v4 >= 0x2Du )
  {
    v5 = v4 / 0x2Du;
    v6 = v5;
    do
    {
      v4 -= 45;
      --v5;
    }
    while ( v5 != 0 );
    propsRes->pb = v6;
  }
  propsRes->lp = 0;
  if ( v4 >= 9u )
  {
    v7 = v4 / 9u;
    v8 = v7;
    do
    {
      v4 -= 9;
      --v7;
    }
    while ( v7 != 0 );
    propsRes->lp = v8;
  }
  propsRes->lc = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10034E40
// Name: int LzmaDecodeWithCallback(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeWithCallback(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        const unsigned __int8 *inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int *Probs; // edi
  int v9; // edx
  int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // esi
  int j; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // eax
  int k; // ebx
  int v19; // ebx
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v25; // eax
  unsigned int v26; // esi
  unsigned int v27; // edx
  unsigned int v28; // ebx
  unsigned int v29; // esi
  int v30; // edx
  unsigned int *v31; // eax
  unsigned int v32; // esi
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned int v35; // esi
  unsigned int *v36; // ebx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  unsigned int v39; // ecx
  unsigned __int8 v40; // dl
  unsigned int v41; // esi
  unsigned int v42; // edx
  unsigned int v43; // ebx
  unsigned int v44; // ebx
  unsigned int v45; // edx
  unsigned int v46; // esi
  unsigned int v47; // edx
  unsigned int v48; // ebx
  unsigned int v49; // ebx
  const unsigned __int8 *v50; // ebx
  unsigned int v51; // ecx
  unsigned int v52; // edx
  int v53; // ecx
  unsigned int v54; // esi
  unsigned int v55; // ecx
  unsigned int v56; // edx
  int v57; // ebx
  unsigned int v58; // eax
  unsigned int v59; // edx
  int v60; // ebx
  int v61; // ebx
  int v62; // eax
  unsigned int v63; // ecx
  unsigned int v64; // edx
  int v65; // eax
  int v66; // edx
  int v67; // ecx
  int v68; // ebx
  const unsigned __int8 *v69; // eax
  int v70; // edx
  int v71; // ecx
  unsigned int v72; // eax
  unsigned int v73; // edx
  unsigned int v74; // ebx
  unsigned __int8 *v75; // ecx
  unsigned __int8 v76; // al
  unsigned int literalPosMask; // [esp+Ch] [ebp-34h]
  unsigned int posStateMask; // [esp+10h] [ebp-30h]
  char lc; // [esp+14h] [ebp-2Ch]
  int offset; // [esp+18h] [ebp-28h]
  int offseta; // [esp+18h] [ebp-28h]
  int offsetb; // [esp+18h] [ebp-28h]
  int offsetc; // [esp+18h] [ebp-28h]
  unsigned int rep3; // [esp+1Ch] [ebp-24h]
  unsigned int *p; // [esp+20h] [ebp-20h]
  unsigned int rep1; // [esp+24h] [ebp-1Ch]
  unsigned int rep2; // [esp+28h] [ebp-18h]
  unsigned int *i; // [esp+2Ch] [ebp-14h]
  int ia; // [esp+2Ch] [ebp-14h]
  unsigned int *ib; // [esp+2Ch] [ebp-14h]
  int ic; // [esp+2Ch] [ebp-14h]
  int id; // [esp+2Ch] [ebp-14h]
  int ie; // [esp+2Ch] [ebp-14h]
  unsigned int nowPos; // [esp+30h] [ebp-10h]
  int state; // [esp+34h] [ebp-Ch]
  const unsigned __int8 *BufferLim; // [esp+38h] [ebp-8h]
  unsigned int rep0; // [esp+3Ch] [ebp-4h]
  unsigned int rep0a; // [esp+3Ch] [ebp-4h]
  unsigned int rep0b; // [esp+3Ch] [ebp-4h]
  unsigned int *numDirectBits; // [esp+48h] [ebp+8h]
  int numDirectBitsa; // [esp+48h] [ebp+8h]
  int numDirectBitsb; // [esp+48h] [ebp+8h]
  int numDirectBitsc; // [esp+48h] [ebp+8h]
  unsigned __int8 numDirectBits_3; // [esp+4Bh] [ebp+Bh]
  const unsigned __int8 *Buffer; // [esp+50h] [ebp+10h]

  posStateMask = (1 << vs->Properties.pb) - 1;
  Probs = vs->Probs;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v9 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v10 = v9 + vs->Properties.lp;
  p = Probs;
  nowPos = 0;
  numDirectBits_3 = 0;
  lc = v9;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v10 != -1846 )
    memset32(Probs, 1024, (768 << v10) + 1846);
  v11 = inStream;
  v12 = 0;
  v13 = -1;
  BufferLim = &inSize[(_DWORD)inStream];
  for ( j = 0; j < 5; ++j )
  {
    if ( v11 == &inSize[(_DWORD)inStream] )
      return 1;
    v12 = *v11++ | (v12 << 8);
  }
  Buffer = v11;
  if ( outSize == 0 )
    goto LABEL_41;
  do
  {
    offset = nowPos & posStateMask;
    i = &p[16 * state + (nowPos & posStateMask)];
    if ( v13 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v13 <<= 8;
      v12 = *Buffer++ | (v12 << 8);
    }
    v15 = *i;
    v16 = *i * (v13 >> 11);
    if ( v12 >= v16 )
    {
      v26 = v13 - v16;
      v12 -= v16;
      *i = v15 - (v15 >> 5);
      if ( v26 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v26 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v27 = p[state + 192];
      v28 = v27 * (v26 >> 11);
      if ( v12 >= v28 )
      {
        v32 = v26 - v28;
        v12 -= v28;
        p[state + 192] = v27 - (v27 >> 5);
        if ( v32 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v32 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v33 = p[state + 204];
        v34 = v33 * (v32 >> 11);
        if ( v12 >= v34 )
        {
          v41 = v32 - v34;
          v12 -= v34;
          p[state + 204] = v33 - (v33 >> 5);
          if ( v41 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v41 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v42 = p[state + 216];
          v43 = v42 * (v41 >> 11);
          if ( v12 >= v43 )
          {
            v46 = v41 - v43;
            v12 -= v43;
            p[state + 216] = v42 - (v42 >> 5);
            if ( v46 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v46 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v47 = p[state + 228];
            v48 = v47 * (v46 >> 11);
            if ( v12 >= v48 )
            {
              v29 = v46 - v48;
              v12 -= v48;
              p[state + 228] = v47 - (v47 >> 5);
              v45 = rep3;
              rep3 = rep2;
            }
            else
            {
              v29 = v47 * (v46 >> 11);
              v49 = v47 + ((2048 - v47) >> 5);
              v45 = rep2;
              p[state + 228] = v49;
            }
            rep2 = rep1;
          }
          else
          {
            v29 = v42 * (v41 >> 11);
            v44 = v42 + ((2048 - v42) >> 5);
            v45 = rep1;
            p[state + 216] = v44;
          }
          rep1 = rep0;
          rep0 = v45;
        }
        else
        {
          v35 = v33 * (v32 >> 11);
          p[state + 204] = v33 + ((2048 - v33) >> 5);
          v36 = &p[16 * state + 240 + offset];
          ib = v36;
          if ( v35 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v35 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v37 = *v36;
          v38 = *v36 * (v35 >> 11);
          if ( v12 < v38 )
          {
            v13 = v38;
            *ib = v37 + ((2048 - v37) >> 5);
            if ( nowPos != 0 )
            {
              state = 2 * (state >= 7) + 9;
              v39 = nowPos + 1;
              v40 = outStream[nowPos - rep0];
              outStream[v39 - 1] = v40;
              numDirectBits_3 = v40;
              ++nowPos;
              if ( v39 % 0x7A120 == 0 )
                pCallbackFunc();
              continue;
            }
            return 1;
          }
          v29 = v35 - v38;
          v12 -= v38;
          *ib = v37 - (v37 >> 5);
        }
        v30 = state >= 7 ? 11 : 8;
        v31 = p + 1332;
      }
      else
      {
        v29 = v27 * (v26 >> 11);
        rep3 = rep2;
        rep2 = rep1;
        rep1 = rep0;
        p[state + 192] = v27 + ((2048 - v27) >> 5);
        v30 = state < 7 ? 0 : 3;
        v31 = p + 818;
      }
      v50 = Buffer;
      state = v30;
      if ( v29 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v29 <<= 8;
        v12 = *Buffer | (v12 << 8);
        v50 = ++Buffer;
      }
      v51 = *v31;
      v52 = *v31 * (v29 >> 11);
      if ( v12 >= v52 )
      {
        v54 = v29 - v52;
        v12 -= v52;
        *v31 = v51 - (v51 >> 5);
        if ( v54 < 0x1000000 )
        {
          if ( v50 == BufferLim )
            return 1;
          v54 <<= 8;
          v12 = *v50 | (v12 << 8);
          Buffer = v50 + 1;
        }
        v55 = v31[1];
        v56 = v55 * (v54 >> 11);
        if ( v12 >= v56 )
        {
          v13 = v54 - v56;
          v12 -= v56;
          v31[1] = v55 - (v55 >> 5);
          v53 = (int)(v31 + 258);
          offsetb = 16;
          numDirectBitsa = 8;
        }
        else
        {
          v13 = v55 * (v54 >> 11);
          v31[1] = v55 + ((2048 - v55) >> 5);
          v53 = (int)&v31[8 * offset + 130];
          offsetb = 8;
          numDirectBitsa = 3;
        }
      }
      else
      {
        v13 = *v31 * (v29 >> 11);
        *v31 = v51 + ((2048 - v51) >> 5);
        v53 = (int)&v31[8 * offset + 2];
        offsetb = 0;
        numDirectBitsa = 3;
      }
      ic = numDirectBitsa;
      v57 = 1;
      do
      {
        if ( v13 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v13 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v58 = *(_DWORD *)(v53 + 4 * v57);
        v59 = v58 * (v13 >> 11);
        if ( v12 >= v59 )
        {
          v13 -= v59;
          v12 -= v59;
          *(_DWORD *)(v53 + 4 * v57) = v58 - (v58 >> 5);
          v57 = 2 * v57 + 1;
        }
        else
        {
          v13 = v58 * (v13 >> 11);
          *(_DWORD *)(v53 + 4 * v57) = v58 + ((2048 - v58) >> 5);
          v57 *= 2;
        }
        --ic;
      }
      while ( ic != 0 );
      v60 = offsetb - (1 << numDirectBitsa) + v57;
      id = v60;
      if ( state < 4 )
      {
        state += 7;
        if ( v60 >= 4 )
          v60 = 3;
        v61 = (int)&p[64 * v60 + 432];
        numDirectBitsb = 6;
        v62 = 1;
        do
        {
          if ( v13 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v13 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v63 = *(_DWORD *)(v61 + 4 * v62);
          v64 = v63 * (v13 >> 11);
          if ( v12 >= v64 )
          {
            v13 -= v64;
            v12 -= v64;
            *(_DWORD *)(v61 + 4 * v62) = v63 - (v63 >> 5);
            v62 = 2 * v62 + 1;
          }
          else
          {
            v13 = v63 * (v13 >> 11);
            *(_DWORD *)(v61 + 4 * v62) = v63 + ((2048 - v63) >> 5);
            v62 *= 2;
          }
          --numDirectBitsb;
        }
        while ( numDirectBitsb != 0 );
        v65 = v62 - 64;
        if ( v65 < 4 )
        {
          rep0a = v65;
        }
        else
        {
          v66 = (v65 >> 1) - 1;
          v67 = v65 & 1 | 2;
          numDirectBitsc = v66;
          if ( v65 >= 14 )
          {
            v69 = Buffer;
            v70 = v66 - 4;
            do
            {
              if ( v13 < 0x1000000 )
              {
                if ( v69 == BufferLim )
                  return 1;
                v13 <<= 8;
                v12 = *v69++ | (v12 << 8);
                Buffer = v69;
              }
              v13 >>= 1;
              v67 *= 2;
              rep0b = v67;
              if ( v12 >= v13 )
              {
                v12 -= v13;
                v67 |= 1u;
                rep0b = v67;
              }
              --v70;
            }
            while ( v70 != 0 );
            v68 = (int)(p + 802);
            rep0a = 16 * rep0b;
            numDirectBitsc = 4;
          }
          else
          {
            rep0a = (v65 & 1 | 2) << v66;
            v68 = (int)&p[rep0a - v65 + 687];
          }
          v71 = 1;
          offsetc = 1;
          do
          {
            if ( v13 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v13 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v72 = *(_DWORD *)(v68 + 4 * v71);
            v73 = v72 * (v13 >> 11);
            if ( v12 >= v73 )
            {
              v13 -= v73;
              v12 -= v73;
              *(_DWORD *)(v68 + 4 * v71) = v72 - (v72 >> 5);
              rep0a |= offsetc;
              v71 = 2 * v71 + 1;
            }
            else
            {
              v13 = v72 * (v13 >> 11);
              *(_DWORD *)(v68 + 4 * v71) = v72 + ((2048 - v72) >> 5);
              v71 *= 2;
            }
            offsetc *= 2;
            --numDirectBitsc;
          }
          while ( numDirectBitsc != 0 );
        }
        rep0 = rep0a + 1;
        if ( rep0 == 0 )
          break;
      }
      v74 = nowPos;
      ie = id + 2;
      if ( rep0 <= nowPos )
      {
        v75 = &outStream[-rep0];
        do
        {
          v76 = v75[v74];
          outStream[v74] = v76;
          --ie;
          numDirectBits_3 = v76;
          nowPos = ++v74;
          if ( v74 % 0x7A120 == 0 )
          {
            pCallbackFunc();
            v75 = &outStream[-rep0];
          }
          if ( ie == 0 )
            goto LABEL_37;
        }
        while ( v74 < outSize );
        break;
      }
      return 1;
    }
    *i = v15 + ((2048 - v15) >> 5);
    v13 = v16;
    v17 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (numDirectBits_3 >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_19;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v19 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v19 + v17) + 1024);
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v20 = *numDirectBits;
      v21 = *numDirectBits * (v13 >> 11);
      if ( v12 >= v21 )
        break;
      v13 = *numDirectBits * (v13 >> 11);
      v17 *= 2;
      *numDirectBits = v20 + ((2048 - v20) >> 5);
      if ( v19 != 0 )
        goto LABEL_18;
LABEL_26:
      if ( v17 >= 256 )
        goto LABEL_30;
    }
    v13 -= v21;
    v12 -= v21;
    *numDirectBits = v20 - (v20 >> 5);
    v17 = 2 * v17 + 1;
    if ( v19 != 0 )
      goto LABEL_26;
LABEL_18:
    while ( v17 < 256 )
    {
LABEL_19:
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v22 = *(_DWORD *)(ia + 4 * v17);
      v23 = v22 * (v13 >> 11);
      if ( v12 >= v23 )
      {
        v13 -= v23;
        v12 -= v23;
        *(_DWORD *)(ia + 4 * v17) = v22 - (v22 >> 5);
        v17 = 2 * v17 + 1;
      }
      else
      {
        v13 = v22 * (v13 >> 11);
        *(_DWORD *)(ia + 4 * v17) = v22 + ((2048 - v22) >> 5);
        v17 *= 2;
      }
    }
LABEL_30:
    outStream[nowPos] = v17;
    numDirectBits_3 = v17;
    if ( ++nowPos % 0x7A120 == 0 )
      pCallbackFunc();
    if ( state >= 4 )
    {
      if ( state >= 10 )
        v25 = state - 6;
      else
        v25 = state - 3;
      state = v25;
    }
    else
    {
      state = 0;
    }
LABEL_37:
    ;
  }
  while ( nowPos < outSize );
  if ( v13 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_41:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035760
// Name: int LzmaDecode(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecode(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        unsigned int inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int v8; // esi
  unsigned int *Probs; // edi
  int v11; // edx
  int v12; // ecx
  const unsigned __int8 *v13; // ecx
  unsigned int v14; // eax
  int j; // edx
  const unsigned __int8 *v16; // edx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  int v19; // edx
  int k; // ebx
  int v21; // ebx
  unsigned int v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ecx
  unsigned int v25; // edi
  int v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int *v31; // ecx
  int v32; // edx
  unsigned int v33; // eax
  unsigned int v34; // edi
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int *v37; // ebx
  unsigned int v38; // edx
  unsigned int v39; // edi
  unsigned int v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // edx
  unsigned int v43; // edi
  unsigned int v44; // edi
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // edx
  unsigned int v48; // edi
  unsigned int v49; // edi
  unsigned int v50; // edx
  unsigned int v51; // edi
  int v52; // ecx
  unsigned int v53; // eax
  unsigned int v54; // edx
  unsigned int v55; // edi
  int v56; // ebx
  unsigned int v57; // edx
  unsigned int v58; // edi
  int v59; // edx
  int v60; // ebx
  int v61; // ebx
  unsigned int v62; // ecx
  unsigned int v63; // edi
  int v64; // edx
  int v65; // edi
  int v66; // ecx
  int v67; // ebx
  const unsigned __int8 *v68; // edx
  int v69; // edi
  int v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // edi
  unsigned int v73; // ecx
  int v74; // ebx
  unsigned __int8 *m; // edx
  unsigned __int8 v76; // dl
  unsigned int literalPosMask; // [esp+4h] [ebp-38h]
  unsigned int posStateMask; // [esp+8h] [ebp-34h]
  char lc; // [esp+Ch] [ebp-30h]
  unsigned int rep3; // [esp+10h] [ebp-2Ch]
  int offset; // [esp+14h] [ebp-28h]
  int offseta; // [esp+14h] [ebp-28h]
  int offsetb; // [esp+14h] [ebp-28h]
  int offsetc; // [esp+14h] [ebp-28h]
  unsigned int rep1; // [esp+18h] [ebp-24h]
  unsigned int rep2; // [esp+1Ch] [ebp-20h]
  unsigned int *i; // [esp+20h] [ebp-1Ch]
  int ia; // [esp+20h] [ebp-1Ch]
  int ib; // [esp+20h] [ebp-1Ch]
  int ic; // [esp+20h] [ebp-1Ch]
  unsigned int *p; // [esp+24h] [ebp-18h]
  int state; // [esp+28h] [ebp-14h]
  unsigned int nowPos; // [esp+2Ch] [ebp-10h]
  const unsigned __int8 *BufferLim; // [esp+30h] [ebp-Ch]
  unsigned int rep0; // [esp+34h] [ebp-8h]
  unsigned int rep0a; // [esp+34h] [ebp-8h]
  unsigned int rep0b; // [esp+34h] [ebp-8h]
  const unsigned __int8 *Buffer; // [esp+38h] [ebp-4h]
  unsigned int *numDirectBits; // [esp+60h] [ebp+24h]
  int numDirectBitsa; // [esp+60h] [ebp+24h]
  int numDirectBitsb; // [esp+60h] [ebp+24h]
  int numDirectBitsc; // [esp+60h] [ebp+24h]

  v8 = 0;
  if ( pCallbackFunc != nullptr )
    return LzmaDecodeWithCallback(
             vs,
             inStream,
             (const unsigned __int8 *)inSize,
             inSizeProcessed,
             outStream,
             outSize,
             outSizeProcessed,
             pCallbackFunc);
  Probs = vs->Probs;
  posStateMask = (1 << vs->Properties.pb) - 1;
  p = Probs;
  nowPos = 0;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v11 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v12 = v11 + vs->Properties.lp;
  lc = v11;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v12 != -1846 )
    memset32(Probs, 1024, (768 << v12) + 1846);
  v13 = inStream;
  v14 = -1;
  BufferLim = &inStream[inSize];
  for ( j = 0; j < 5; ++j )
  {
    if ( v13 == &inStream[inSize] )
      return 1;
    v8 = *v13++ | (v8 << 8);
  }
  Buffer = v13;
  if ( outSize == 0 )
    goto LABEL_131;
LABEL_9:
  offset = nowPos & posStateMask;
  i = &p[16 * state + (nowPos & posStateMask)];
  v16 = Buffer;
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v14 <<= 8;
    v8 = *Buffer | (v8 << 8);
    v16 = ++Buffer;
  }
  v17 = *i;
  v18 = *i * (v14 >> 11);
  if ( v8 < v18 )
  {
    *i = v17 + ((2048 - v17) >> 5);
    v14 = v18;
    v19 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (HIBYTE(pCallbackFunc) >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_21;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v21 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v21 + v19) + 1024);
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v22 = *numDirectBits;
      v23 = *numDirectBits * (v14 >> 11);
      if ( v8 >= v23 )
      {
        v14 -= v23;
        v8 -= v23;
        *numDirectBits = v22 - (v22 >> 5);
        v19 = 2 * v19 + 1;
        if ( v21 == 0 )
        {
LABEL_20:
          while ( v19 < 256 )
          {
LABEL_21:
            if ( v14 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v14 <<= 8;
              v8 = *Buffer++ | (v8 << 8);
            }
            v24 = *(_DWORD *)(ia + 4 * v19);
            v25 = v24 * (v14 >> 11);
            if ( v8 >= v25 )
            {
              v14 -= v25;
              v8 -= v25;
              *(_DWORD *)(ia + 4 * v19) = v24 - (v24 >> 5);
              v19 = 2 * v19 + 1;
            }
            else
            {
              v14 = v24 * (v14 >> 11);
              *(_DWORD *)(ia + 4 * v19) = v24 + ((2048 - v24) >> 5);
              v19 *= 2;
            }
          }
LABEL_32:
          outStream[nowPos++] = v19;
          HIBYTE(pCallbackFunc) = v19;
          if ( state >= 4 )
          {
            if ( state >= 10 )
              v26 = state - 6;
            else
              v26 = state - 3;
            state = v26;
          }
          else
          {
            state = 0;
          }
LABEL_37:
          if ( nowPos >= outSize )
            goto LABEL_38;
          goto LABEL_9;
        }
      }
      else
      {
        v14 = *numDirectBits * (v14 >> 11);
        v19 *= 2;
        *numDirectBits = v22 + ((2048 - v22) >> 5);
        if ( v21 != 0 )
          goto LABEL_20;
      }
      if ( v19 >= 256 )
        goto LABEL_32;
    }
  }
  v27 = v14 - v18;
  v8 -= v18;
  *i = v17 - (v17 >> 5);
  if ( v27 < 0x1000000 )
  {
    if ( v16 == BufferLim )
      return 1;
    v27 <<= 8;
    v8 = *v16 | (v8 << 8);
    Buffer = v16 + 1;
  }
  v28 = p[state + 192];
  v29 = v28 * (v27 >> 11);
  if ( v8 < v29 )
  {
    rep3 = rep2;
    rep2 = rep1;
    rep1 = rep0;
    v30 = v28 * (v27 >> 11);
    p[state + 192] = v28 + ((2048 - v28) >> 5);
    v31 = p + 818;
    v32 = state < 7 ? 0 : 3;
    goto LABEL_72;
  }
  v33 = v27 - v29;
  v8 -= v29;
  p[state + 192] = v28 - (v28 >> 5);
  if ( v33 < 0x1000000 )
  {
    if ( Buffer != BufferLim )
    {
      v33 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
      goto LABEL_50;
    }
    return 1;
  }
LABEL_50:
  v34 = p[state + 204];
  v35 = v34 * (v33 >> 11);
  if ( v8 >= v35 )
  {
    v41 = v33 - v35;
    v8 -= v35;
    p[state + 204] = v34 - (v34 >> 5);
    if ( v41 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v41 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v42 = p[state + 216];
    v43 = v42 * (v41 >> 11);
    if ( v8 >= v43 )
    {
      v46 = v41 - v43;
      v8 -= v43;
      p[state + 216] = v42 - (v42 >> 5);
      if ( v46 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v46 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v47 = p[state + 228];
      v48 = v47 * (v46 >> 11);
      if ( v8 >= v48 )
      {
        v30 = v46 - v48;
        v8 -= v48;
        p[state + 228] = v47 - (v47 >> 5);
        v45 = rep3;
        rep3 = rep2;
      }
      else
      {
        v30 = v47 * (v46 >> 11);
        v49 = v47 + ((2048 - v47) >> 5);
        v45 = rep2;
        p[state + 228] = v49;
      }
      rep2 = rep1;
    }
    else
    {
      v30 = v42 * (v41 >> 11);
      v44 = v42 + ((2048 - v42) >> 5);
      v45 = rep1;
      p[state + 216] = v44;
    }
    rep1 = rep0;
    rep0 = v45;
  }
  else
  {
    p[state + 204] = v34 + ((2048 - v34) >> 5);
    v36 = v34 * (v33 >> 11);
    v37 = &p[16 * state + 240 + offset];
    if ( v35 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v36 = v35 << 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v38 = *v37;
    v39 = *v37 * (v36 >> 11);
    if ( v8 < v39 )
    {
      v14 = *v37 * (v36 >> 11);
      *v37 = v38 + ((2048 - v38) >> 5);
      if ( nowPos != 0 )
      {
        v40 = nowPos - rep0;
        ++nowPos;
        state = 2 * (state >= 7) + 9;
        LOBYTE(v40) = outStream[v40];
        outStream[nowPos - 1] = v40;
        HIBYTE(pCallbackFunc) = v40;
        goto LABEL_37;
      }
      return 1;
    }
    v30 = v36 - v39;
    v8 -= v39;
    *v37 = v38 - (v38 >> 5);
  }
  v32 = state >= 7 ? 11 : 8;
  v31 = p + 1332;
LABEL_72:
  state = v32;
  if ( v30 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v30 <<= 8;
    v8 = *Buffer++ | (v8 << 8);
  }
  v50 = *v31;
  v51 = *v31 * (v30 >> 11);
  if ( v8 >= v51 )
  {
    v53 = v30 - v51;
    v8 -= v51;
    *v31 = v50 - (v50 >> 5);
    if ( v53 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v53 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v54 = v31[1];
    v55 = v54 * (v53 >> 11);
    if ( v8 >= v55 )
    {
      v14 = v53 - v55;
      v8 -= v55;
      v31[1] = v54 - (v54 >> 5);
      v52 = (int)(v31 + 258);
      offsetb = 16;
      numDirectBitsa = 8;
    }
    else
    {
      v14 = v54 * (v53 >> 11);
      v31[1] = v54 + ((2048 - v54) >> 5);
      v52 = (int)&v31[8 * offset + 130];
      offsetb = 8;
      numDirectBitsa = 3;
    }
  }
  else
  {
    v14 = *v31 * (v30 >> 11);
    *v31 = v50 + ((2048 - v50) >> 5);
    v52 = (int)&v31[8 * offset + 2];
    offsetb = 0;
    numDirectBitsa = 3;
  }
  ib = numDirectBitsa;
  v56 = 1;
  do
  {
    if ( v14 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v14 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v57 = *(_DWORD *)(v52 + 4 * v56);
    v58 = v57 * (v14 >> 11);
    if ( v8 >= v58 )
    {
      v14 -= v58;
      v8 -= v58;
      *(_DWORD *)(v52 + 4 * v56) = v57 - (v57 >> 5);
      v56 = 2 * v56 + 1;
    }
    else
    {
      v14 = v57 * (v14 >> 11);
      *(_DWORD *)(v52 + 4 * v56) = v57 + ((2048 - v57) >> 5);
      v56 *= 2;
    }
    v59 = 1;
    --ib;
  }
  while ( ib != 0 );
  v60 = offsetb - (1 << numDirectBitsa) + v56;
  ic = v60;
  if ( state < 4 )
  {
    state += 7;
    if ( v60 >= 4 )
      v60 = 3;
    v61 = (int)&p[64 * v60 + 432];
    for ( numDirectBitsb = 6; numDirectBitsb != 0; --numDirectBitsb )
    {
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v62 = *(_DWORD *)(v61 + 4 * v59);
      v63 = v62 * (v14 >> 11);
      if ( v8 >= v63 )
      {
        v14 -= v63;
        v8 -= v63;
        *(_DWORD *)(v61 + 4 * v59) = v62 - (v62 >> 5);
        v59 = 2 * v59 + 1;
      }
      else
      {
        v14 = v62 * (v14 >> 11);
        *(_DWORD *)(v61 + 4 * v59) = v62 + ((2048 - v62) >> 5);
        v59 *= 2;
      }
    }
    v64 = v59 - 64;
    if ( v64 < 4 )
    {
      rep0a = v64;
    }
    else
    {
      v65 = (v64 >> 1) - 1;
      v66 = v64 & 1 | 2;
      numDirectBitsc = v65;
      if ( v64 >= 14 )
      {
        v68 = Buffer;
        v69 = v65 - 4;
        do
        {
          if ( v14 < 0x1000000 )
          {
            if ( v68 == BufferLim )
              return 1;
            v14 <<= 8;
            v8 = *v68++ | (v8 << 8);
            Buffer = v68;
          }
          v14 >>= 1;
          v66 *= 2;
          rep0b = v66;
          if ( v8 >= v14 )
          {
            v8 -= v14;
            v66 |= 1u;
            rep0b = v66;
          }
          --v69;
        }
        while ( v69 != 0 );
        v67 = (int)(p + 802);
        rep0a = 16 * rep0b;
        numDirectBitsc = 4;
      }
      else
      {
        rep0a = (v64 & 1 | 2) << v65;
        v67 = (int)&p[rep0a - v64 + 687];
      }
      v70 = 1;
      offsetc = 1;
      do
      {
        if ( v14 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v14 <<= 8;
          v8 = *Buffer++ | (v8 << 8);
        }
        v71 = *(_DWORD *)(v67 + 4 * v70);
        v72 = v71 * (v14 >> 11);
        if ( v8 >= v72 )
        {
          v14 -= v72;
          v8 -= v72;
          *(_DWORD *)(v67 + 4 * v70) = v71 - (v71 >> 5);
          rep0a |= offsetc;
          v70 = 2 * v70 + 1;
        }
        else
        {
          v14 = v71 * (v14 >> 11);
          *(_DWORD *)(v67 + 4 * v70) = v71 + ((2048 - v71) >> 5);
          v70 *= 2;
        }
        offsetc *= 2;
        --numDirectBitsc;
      }
      while ( numDirectBitsc != 0 );
    }
    rep0 = rep0a + 1;
    if ( rep0 == 0 )
      goto LABEL_38;
    v60 = ic;
  }
  v73 = nowPos;
  v74 = v60 + 2;
  if ( rep0 > nowPos )
    return 1;
  for ( m = &outStream[-rep0]; ; m = &outStream[-rep0] )
  {
    v76 = m[v73];
    outStream[v73++] = v76;
    --v74;
    HIBYTE(pCallbackFunc) = v76;
    nowPos = v73;
    if ( v74 == 0 )
      goto LABEL_37;
    if ( v73 >= outSize )
      break;
  }
LABEL_38:
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_131:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10036040
// Name: public: bool CLZMA::IsCompressed(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLZMA::IsCompressed(CLZMA *this, unsigned __int8 *pInput)
{
  return pInput != nullptr && *(_DWORD *)pInput == 1095588428;
}

//------------------------------------------------------------------------------
// Address: 0x10036060
// Name: public: unsigned int CLZMA::GetActualSize(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZMA::GetActualSize(CLZMA *this, unsigned __int8 *pInput)
{
  if ( pInput != nullptr && *(_DWORD *)pInput == 1095588428 )
    return *((_DWORD *)pInput + 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10036080
// Name: public: unsigned int CLZMA::Uncompress(unsigned char __near *,unsigned char __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZMA::Uncompress(
        CLZMA *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        void (__cdecl *pCallback)())
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ebx
  unsigned int *v6; // edi
  int v7; // esi
  unsigned __int8 *result; // eax
  unsigned int v9; // [esp-1Ch] [ebp-34h]
  _CLzmaDecoderState state; // [esp+8h] [ebp-10h] BYREF

  v4 = pInput;
  if ( pInput == nullptr )
    return nullptr;
  if ( *(_DWORD *)pInput != 1095588428 )
    return nullptr;
  v5 = *((unsigned __int8 **)pInput + 1);
  if ( v5 == nullptr )
    return nullptr;
  LzmaDecodeProperties(propsRes: &state.Properties, propsData: pInput + 12, size: 5);
  v6 = (unsigned int *)_g_pMemAlloc->Alloc_2(
                         this: _g_pMemAlloc,
                         a2: 4 * (768 << (LOBYTE(state.Properties.lp) + LOBYTE(state.Properties.lc))) + 7384);
  v9 = *((_DWORD *)v4 + 2);
  state.Probs = v6;
  v7 = LzmaDecode(
         vs: &state,
         inStream: v4 + 17,
         inSize: v9,
         inSizeProcessed: (unsigned int *)&pCallback,
         outStream: pOutput,
         outSize: (unsigned int)v5,
         outSizeProcessed: (unsigned int *)&pInput,
         pCallbackFunc: pCallback);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  if ( v7 != 0 )
    return nullptr;
  result = pInput;
  if ( pInput != v5 )
    return nullptr;
  return result;
}

} // namespace dedicated

// ============================================================
// Overlay from FileSystem_Steam (Missing functions)
// ============================================================
namespace FileSystem_Steam {

//------------------------------------------------------------------------------
// Address: 0x10023B50
// Name: int LzmaDecodeProperties(struct _CLzmaProperties __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeProperties(_CLzmaProperties *propsRes, unsigned __int8 *propsData, int size)
{
  unsigned __int8 v4; // cl
  unsigned int v5; // eax
  int v6; // edx
  unsigned int v7; // eax
  int v8; // edx

  if ( size < 5 )
    return 1;
  v4 = *propsData;
  if ( *propsData >= 0xE1u )
    return 1;
  propsRes->pb = 0;
  if ( v4 >= 0x2Du )
  {
    v5 = v4 / 0x2Du;
    v6 = v5;
    do
    {
      v4 -= 45;
      --v5;
    }
    while ( v5 != 0 );
    propsRes->pb = v6;
  }
  propsRes->lp = 0;
  if ( v4 >= 9u )
  {
    v7 = v4 / 9u;
    v8 = v7;
    do
    {
      v4 -= 9;
      --v7;
    }
    while ( v7 != 0 );
    propsRes->lp = v8;
  }
  propsRes->lc = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10023BE0
// Name: int LzmaDecodeWithCallback(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeWithCallback(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        const unsigned __int8 *inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int *Probs; // edi
  int v9; // edx
  int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // esi
  int j; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // eax
  int k; // ebx
  int v19; // ebx
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v25; // eax
  unsigned int v26; // esi
  unsigned int v27; // edx
  unsigned int v28; // ebx
  unsigned int v29; // esi
  int v30; // edx
  unsigned int *v31; // eax
  unsigned int v32; // esi
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned int v35; // esi
  unsigned int *v36; // ebx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  unsigned int v39; // ecx
  unsigned __int8 v40; // dl
  unsigned int v41; // esi
  unsigned int v42; // edx
  unsigned int v43; // ebx
  unsigned int v44; // ebx
  unsigned int v45; // edx
  unsigned int v46; // esi
  unsigned int v47; // edx
  unsigned int v48; // ebx
  unsigned int v49; // ebx
  const unsigned __int8 *v50; // ebx
  unsigned int v51; // ecx
  unsigned int v52; // edx
  int v53; // ecx
  unsigned int v54; // esi
  unsigned int v55; // ecx
  unsigned int v56; // edx
  int v57; // ebx
  unsigned int v58; // eax
  unsigned int v59; // edx
  int v60; // ebx
  int v61; // ebx
  int v62; // eax
  unsigned int v63; // ecx
  unsigned int v64; // edx
  int v65; // eax
  int v66; // edx
  int v67; // ecx
  int v68; // ebx
  const unsigned __int8 *v69; // eax
  int v70; // edx
  int v71; // ecx
  unsigned int v72; // eax
  unsigned int v73; // edx
  unsigned int v74; // ebx
  unsigned __int8 *v75; // ecx
  unsigned __int8 v76; // al
  unsigned int literalPosMask; // [esp+Ch] [ebp-34h]
  unsigned int posStateMask; // [esp+10h] [ebp-30h]
  char lc; // [esp+14h] [ebp-2Ch]
  int offset; // [esp+18h] [ebp-28h]
  int offseta; // [esp+18h] [ebp-28h]
  int offsetb; // [esp+18h] [ebp-28h]
  int offsetc; // [esp+18h] [ebp-28h]
  unsigned int rep3; // [esp+1Ch] [ebp-24h]
  unsigned int *p; // [esp+20h] [ebp-20h]
  unsigned int rep1; // [esp+24h] [ebp-1Ch]
  unsigned int rep2; // [esp+28h] [ebp-18h]
  unsigned int *i; // [esp+2Ch] [ebp-14h]
  int ia; // [esp+2Ch] [ebp-14h]
  unsigned int *ib; // [esp+2Ch] [ebp-14h]
  int ic; // [esp+2Ch] [ebp-14h]
  int id; // [esp+2Ch] [ebp-14h]
  int ie; // [esp+2Ch] [ebp-14h]
  unsigned int nowPos; // [esp+30h] [ebp-10h]
  int state; // [esp+34h] [ebp-Ch]
  const unsigned __int8 *BufferLim; // [esp+38h] [ebp-8h]
  unsigned int rep0; // [esp+3Ch] [ebp-4h]
  unsigned int rep0a; // [esp+3Ch] [ebp-4h]
  unsigned int rep0b; // [esp+3Ch] [ebp-4h]
  unsigned int *numDirectBits; // [esp+48h] [ebp+8h]
  int numDirectBitsa; // [esp+48h] [ebp+8h]
  int numDirectBitsb; // [esp+48h] [ebp+8h]
  int numDirectBitsc; // [esp+48h] [ebp+8h]
  unsigned __int8 numDirectBits_3; // [esp+4Bh] [ebp+Bh]
  const unsigned __int8 *Buffer; // [esp+50h] [ebp+10h]

  posStateMask = (1 << vs->Properties.pb) - 1;
  Probs = vs->Probs;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v9 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v10 = v9 + vs->Properties.lp;
  p = Probs;
  nowPos = 0;
  numDirectBits_3 = 0;
  lc = v9;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v10 != -1846 )
    memset32(Probs, 1024, (768 << v10) + 1846);
  v11 = inStream;
  v12 = 0;
  v13 = -1;
  BufferLim = &inSize[(_DWORD)inStream];
  for ( j = 0; j < 5; ++j )
  {
    if ( v11 == &inSize[(_DWORD)inStream] )
      return 1;
    v12 = *v11++ | (v12 << 8);
  }
  Buffer = v11;
  if ( outSize == 0 )
    goto LABEL_41;
  do
  {
    offset = nowPos & posStateMask;
    i = &p[16 * state + (nowPos & posStateMask)];
    if ( v13 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v13 <<= 8;
      v12 = *Buffer++ | (v12 << 8);
    }
    v15 = *i;
    v16 = *i * (v13 >> 11);
    if ( v12 >= v16 )
    {
      v26 = v13 - v16;
      v12 -= v16;
      *i = v15 - (v15 >> 5);
      if ( v26 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v26 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v27 = p[state + 192];
      v28 = v27 * (v26 >> 11);
      if ( v12 >= v28 )
      {
        v32 = v26 - v28;
        v12 -= v28;
        p[state + 192] = v27 - (v27 >> 5);
        if ( v32 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v32 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v33 = p[state + 204];
        v34 = v33 * (v32 >> 11);
        if ( v12 >= v34 )
        {
          v41 = v32 - v34;
          v12 -= v34;
          p[state + 204] = v33 - (v33 >> 5);
          if ( v41 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v41 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v42 = p[state + 216];
          v43 = v42 * (v41 >> 11);
          if ( v12 >= v43 )
          {
            v46 = v41 - v43;
            v12 -= v43;
            p[state + 216] = v42 - (v42 >> 5);
            if ( v46 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v46 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v47 = p[state + 228];
            v48 = v47 * (v46 >> 11);
            if ( v12 >= v48 )
            {
              v29 = v46 - v48;
              v12 -= v48;
              p[state + 228] = v47 - (v47 >> 5);
              v45 = rep3;
              rep3 = rep2;
            }
            else
            {
              v29 = v47 * (v46 >> 11);
              v49 = v47 + ((2048 - v47) >> 5);
              v45 = rep2;
              p[state + 228] = v49;
            }
            rep2 = rep1;
          }
          else
          {
            v29 = v42 * (v41 >> 11);
            v44 = v42 + ((2048 - v42) >> 5);
            v45 = rep1;
            p[state + 216] = v44;
          }
          rep1 = rep0;
          rep0 = v45;
        }
        else
        {
          v35 = v33 * (v32 >> 11);
          p[state + 204] = v33 + ((2048 - v33) >> 5);
          v36 = &p[16 * state + 240 + offset];
          ib = v36;
          if ( v35 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v35 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v37 = *v36;
          v38 = *v36 * (v35 >> 11);
          if ( v12 < v38 )
          {
            v13 = v38;
            *ib = v37 + ((2048 - v37) >> 5);
            if ( nowPos != 0 )
            {
              state = 2 * (state >= 7) + 9;
              v39 = nowPos + 1;
              v40 = outStream[nowPos - rep0];
              outStream[v39 - 1] = v40;
              numDirectBits_3 = v40;
              ++nowPos;
              if ( v39 % 0x7A120 == 0 )
                pCallbackFunc();
              continue;
            }
            return 1;
          }
          v29 = v35 - v38;
          v12 -= v38;
          *ib = v37 - (v37 >> 5);
        }
        v30 = state >= 7 ? 11 : 8;
        v31 = p + 1332;
      }
      else
      {
        v29 = v27 * (v26 >> 11);
        rep3 = rep2;
        rep2 = rep1;
        rep1 = rep0;
        p[state + 192] = v27 + ((2048 - v27) >> 5);
        v30 = state < 7 ? 0 : 3;
        v31 = p + 818;
      }
      v50 = Buffer;
      state = v30;
      if ( v29 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v29 <<= 8;
        v12 = *Buffer | (v12 << 8);
        v50 = ++Buffer;
      }
      v51 = *v31;
      v52 = *v31 * (v29 >> 11);
      if ( v12 >= v52 )
      {
        v54 = v29 - v52;
        v12 -= v52;
        *v31 = v51 - (v51 >> 5);
        if ( v54 < 0x1000000 )
        {
          if ( v50 == BufferLim )
            return 1;
          v54 <<= 8;
          v12 = *v50 | (v12 << 8);
          Buffer = v50 + 1;
        }
        v55 = v31[1];
        v56 = v55 * (v54 >> 11);
        if ( v12 >= v56 )
        {
          v13 = v54 - v56;
          v12 -= v56;
          v31[1] = v55 - (v55 >> 5);
          v53 = (int)(v31 + 258);
          offsetb = 16;
          numDirectBitsa = 8;
        }
        else
        {
          v13 = v55 * (v54 >> 11);
          v31[1] = v55 + ((2048 - v55) >> 5);
          v53 = (int)&v31[8 * offset + 130];
          offsetb = 8;
          numDirectBitsa = 3;
        }
      }
      else
      {
        v13 = *v31 * (v29 >> 11);
        *v31 = v51 + ((2048 - v51) >> 5);
        v53 = (int)&v31[8 * offset + 2];
        offsetb = 0;
        numDirectBitsa = 3;
      }
      ic = numDirectBitsa;
      v57 = 1;
      do
      {
        if ( v13 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v13 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v58 = *(_DWORD *)(v53 + 4 * v57);
        v59 = v58 * (v13 >> 11);
        if ( v12 >= v59 )
        {
          v13 -= v59;
          v12 -= v59;
          *(_DWORD *)(v53 + 4 * v57) = v58 - (v58 >> 5);
          v57 = 2 * v57 + 1;
        }
        else
        {
          v13 = v58 * (v13 >> 11);
          *(_DWORD *)(v53 + 4 * v57) = v58 + ((2048 - v58) >> 5);
          v57 *= 2;
        }
        --ic;
      }
      while ( ic != 0 );
      v60 = offsetb - (1 << numDirectBitsa) + v57;
      id = v60;
      if ( state < 4 )
      {
        state += 7;
        if ( v60 >= 4 )
          v60 = 3;
        v61 = (int)&p[64 * v60 + 432];
        numDirectBitsb = 6;
        v62 = 1;
        do
        {
          if ( v13 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v13 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v63 = *(_DWORD *)(v61 + 4 * v62);
          v64 = v63 * (v13 >> 11);
          if ( v12 >= v64 )
          {
            v13 -= v64;
            v12 -= v64;
            *(_DWORD *)(v61 + 4 * v62) = v63 - (v63 >> 5);
            v62 = 2 * v62 + 1;
          }
          else
          {
            v13 = v63 * (v13 >> 11);
            *(_DWORD *)(v61 + 4 * v62) = v63 + ((2048 - v63) >> 5);
            v62 *= 2;
          }
          --numDirectBitsb;
        }
        while ( numDirectBitsb != 0 );
        v65 = v62 - 64;
        if ( v65 < 4 )
        {
          rep0a = v65;
        }
        else
        {
          v66 = (v65 >> 1) - 1;
          v67 = v65 & 1 | 2;
          numDirectBitsc = v66;
          if ( v65 >= 14 )
          {
            v69 = Buffer;
            v70 = v66 - 4;
            do
            {
              if ( v13 < 0x1000000 )
              {
                if ( v69 == BufferLim )
                  return 1;
                v13 <<= 8;
                v12 = *v69++ | (v12 << 8);
                Buffer = v69;
              }
              v13 >>= 1;
              v67 *= 2;
              rep0b = v67;
              if ( v12 >= v13 )
              {
                v12 -= v13;
                v67 |= 1u;
                rep0b = v67;
              }
              --v70;
            }
            while ( v70 != 0 );
            v68 = (int)(p + 802);
            rep0a = 16 * rep0b;
            numDirectBitsc = 4;
          }
          else
          {
            rep0a = (v65 & 1 | 2) << v66;
            v68 = (int)&p[rep0a - v65 + 687];
          }
          v71 = 1;
          offsetc = 1;
          do
          {
            if ( v13 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v13 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v72 = *(_DWORD *)(v68 + 4 * v71);
            v73 = v72 * (v13 >> 11);
            if ( v12 >= v73 )
            {
              v13 -= v73;
              v12 -= v73;
              *(_DWORD *)(v68 + 4 * v71) = v72 - (v72 >> 5);
              rep0a |= offsetc;
              v71 = 2 * v71 + 1;
            }
            else
            {
              v13 = v72 * (v13 >> 11);
              *(_DWORD *)(v68 + 4 * v71) = v72 + ((2048 - v72) >> 5);
              v71 *= 2;
            }
            offsetc *= 2;
            --numDirectBitsc;
          }
          while ( numDirectBitsc != 0 );
        }
        rep0 = rep0a + 1;
        if ( rep0 == 0 )
          break;
      }
      v74 = nowPos;
      ie = id + 2;
      if ( rep0 <= nowPos )
      {
        v75 = &outStream[-rep0];
        do
        {
          v76 = v75[v74];
          outStream[v74] = v76;
          --ie;
          numDirectBits_3 = v76;
          nowPos = ++v74;
          if ( v74 % 0x7A120 == 0 )
          {
            pCallbackFunc();
            v75 = &outStream[-rep0];
          }
          if ( ie == 0 )
            goto LABEL_37;
        }
        while ( v74 < outSize );
        break;
      }
      return 1;
    }
    *i = v15 + ((2048 - v15) >> 5);
    v13 = v16;
    v17 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (numDirectBits_3 >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_19;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v19 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v19 + v17) + 1024);
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v20 = *numDirectBits;
      v21 = *numDirectBits * (v13 >> 11);
      if ( v12 >= v21 )
        break;
      v13 = *numDirectBits * (v13 >> 11);
      v17 *= 2;
      *numDirectBits = v20 + ((2048 - v20) >> 5);
      if ( v19 != 0 )
        goto LABEL_18;
LABEL_26:
      if ( v17 >= 256 )
        goto LABEL_30;
    }
    v13 -= v21;
    v12 -= v21;
    *numDirectBits = v20 - (v20 >> 5);
    v17 = 2 * v17 + 1;
    if ( v19 != 0 )
      goto LABEL_26;
LABEL_18:
    while ( v17 < 256 )
    {
LABEL_19:
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v22 = *(_DWORD *)(ia + 4 * v17);
      v23 = v22 * (v13 >> 11);
      if ( v12 >= v23 )
      {
        v13 -= v23;
        v12 -= v23;
        *(_DWORD *)(ia + 4 * v17) = v22 - (v22 >> 5);
        v17 = 2 * v17 + 1;
      }
      else
      {
        v13 = v22 * (v13 >> 11);
        *(_DWORD *)(ia + 4 * v17) = v22 + ((2048 - v22) >> 5);
        v17 *= 2;
      }
    }
LABEL_30:
    outStream[nowPos] = v17;
    numDirectBits_3 = v17;
    if ( ++nowPos % 0x7A120 == 0 )
      pCallbackFunc();
    if ( state >= 4 )
    {
      if ( state >= 10 )
        v25 = state - 6;
      else
        v25 = state - 3;
      state = v25;
    }
    else
    {
      state = 0;
    }
LABEL_37:
    ;
  }
  while ( nowPos < outSize );
  if ( v13 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_41:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10024500
// Name: int LzmaDecode(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecode(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        unsigned int inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int v8; // esi
  unsigned int *Probs; // edi
  int v11; // edx
  int v12; // ecx
  const unsigned __int8 *v13; // ecx
  unsigned int v14; // eax
  int j; // edx
  const unsigned __int8 *v16; // edx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  int v19; // edx
  int k; // ebx
  int v21; // ebx
  unsigned int v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ecx
  unsigned int v25; // edi
  int v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int *v31; // ecx
  int v32; // edx
  unsigned int v33; // eax
  unsigned int v34; // edi
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int *v37; // ebx
  unsigned int v38; // edx
  unsigned int v39; // edi
  unsigned int v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // edx
  unsigned int v43; // edi
  unsigned int v44; // edi
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // edx
  unsigned int v48; // edi
  unsigned int v49; // edi
  unsigned int v50; // edx
  unsigned int v51; // edi
  int v52; // ecx
  unsigned int v53; // eax
  unsigned int v54; // edx
  unsigned int v55; // edi
  int v56; // ebx
  unsigned int v57; // edx
  unsigned int v58; // edi
  int v59; // edx
  int v60; // ebx
  int v61; // ebx
  unsigned int v62; // ecx
  unsigned int v63; // edi
  int v64; // edx
  int v65; // edi
  int v66; // ecx
  int v67; // ebx
  const unsigned __int8 *v68; // edx
  int v69; // edi
  int v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // edi
  unsigned int v73; // ecx
  int v74; // ebx
  unsigned __int8 *m; // edx
  unsigned __int8 v76; // dl
  unsigned int literalPosMask; // [esp+4h] [ebp-38h]
  unsigned int posStateMask; // [esp+8h] [ebp-34h]
  char lc; // [esp+Ch] [ebp-30h]
  unsigned int rep3; // [esp+10h] [ebp-2Ch]
  int offset; // [esp+14h] [ebp-28h]
  int offseta; // [esp+14h] [ebp-28h]
  int offsetb; // [esp+14h] [ebp-28h]
  int offsetc; // [esp+14h] [ebp-28h]
  unsigned int rep1; // [esp+18h] [ebp-24h]
  unsigned int rep2; // [esp+1Ch] [ebp-20h]
  unsigned int *i; // [esp+20h] [ebp-1Ch]
  int ia; // [esp+20h] [ebp-1Ch]
  int ib; // [esp+20h] [ebp-1Ch]
  int ic; // [esp+20h] [ebp-1Ch]
  unsigned int *p; // [esp+24h] [ebp-18h]
  int state; // [esp+28h] [ebp-14h]
  unsigned int nowPos; // [esp+2Ch] [ebp-10h]
  const unsigned __int8 *BufferLim; // [esp+30h] [ebp-Ch]
  unsigned int rep0; // [esp+34h] [ebp-8h]
  unsigned int rep0a; // [esp+34h] [ebp-8h]
  unsigned int rep0b; // [esp+34h] [ebp-8h]
  const unsigned __int8 *Buffer; // [esp+38h] [ebp-4h]
  unsigned int *numDirectBits; // [esp+60h] [ebp+24h]
  int numDirectBitsa; // [esp+60h] [ebp+24h]
  int numDirectBitsb; // [esp+60h] [ebp+24h]
  int numDirectBitsc; // [esp+60h] [ebp+24h]

  v8 = 0;
  if ( pCallbackFunc != nullptr )
    return LzmaDecodeWithCallback(
             vs,
             inStream,
             (const unsigned __int8 *)inSize,
             inSizeProcessed,
             outStream,
             outSize,
             outSizeProcessed,
             pCallbackFunc);
  Probs = vs->Probs;
  posStateMask = (1 << vs->Properties.pb) - 1;
  p = Probs;
  nowPos = 0;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v11 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v12 = v11 + vs->Properties.lp;
  lc = v11;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v12 != -1846 )
    memset32(Probs, 1024, (768 << v12) + 1846);
  v13 = inStream;
  v14 = -1;
  BufferLim = &inStream[inSize];
  for ( j = 0; j < 5; ++j )
  {
    if ( v13 == &inStream[inSize] )
      return 1;
    v8 = *v13++ | (v8 << 8);
  }
  Buffer = v13;
  if ( outSize == 0 )
    goto LABEL_131;
LABEL_9:
  offset = nowPos & posStateMask;
  i = &p[16 * state + (nowPos & posStateMask)];
  v16 = Buffer;
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v14 <<= 8;
    v8 = *Buffer | (v8 << 8);
    v16 = ++Buffer;
  }
  v17 = *i;
  v18 = *i * (v14 >> 11);
  if ( v8 < v18 )
  {
    *i = v17 + ((2048 - v17) >> 5);
    v14 = v18;
    v19 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (HIBYTE(pCallbackFunc) >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_21;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v21 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v21 + v19) + 1024);
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v22 = *numDirectBits;
      v23 = *numDirectBits * (v14 >> 11);
      if ( v8 >= v23 )
      {
        v14 -= v23;
        v8 -= v23;
        *numDirectBits = v22 - (v22 >> 5);
        v19 = 2 * v19 + 1;
        if ( v21 == 0 )
        {
LABEL_20:
          while ( v19 < 256 )
          {
LABEL_21:
            if ( v14 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v14 <<= 8;
              v8 = *Buffer++ | (v8 << 8);
            }
            v24 = *(_DWORD *)(ia + 4 * v19);
            v25 = v24 * (v14 >> 11);
            if ( v8 >= v25 )
            {
              v14 -= v25;
              v8 -= v25;
              *(_DWORD *)(ia + 4 * v19) = v24 - (v24 >> 5);
              v19 = 2 * v19 + 1;
            }
            else
            {
              v14 = v24 * (v14 >> 11);
              *(_DWORD *)(ia + 4 * v19) = v24 + ((2048 - v24) >> 5);
              v19 *= 2;
            }
          }
LABEL_32:
          outStream[nowPos++] = v19;
          HIBYTE(pCallbackFunc) = v19;
          if ( state >= 4 )
          {
            if ( state >= 10 )
              v26 = state - 6;
            else
              v26 = state - 3;
            state = v26;
          }
          else
          {
            state = 0;
          }
LABEL_37:
          if ( nowPos >= outSize )
            goto LABEL_38;
          goto LABEL_9;
        }
      }
      else
      {
        v14 = *numDirectBits * (v14 >> 11);
        v19 *= 2;
        *numDirectBits = v22 + ((2048 - v22) >> 5);
        if ( v21 != 0 )
          goto LABEL_20;
      }
      if ( v19 >= 256 )
        goto LABEL_32;
    }
  }
  v27 = v14 - v18;
  v8 -= v18;
  *i = v17 - (v17 >> 5);
  if ( v27 < 0x1000000 )
  {
    if ( v16 == BufferLim )
      return 1;
    v27 <<= 8;
    v8 = *v16 | (v8 << 8);
    Buffer = v16 + 1;
  }
  v28 = p[state + 192];
  v29 = v28 * (v27 >> 11);
  if ( v8 < v29 )
  {
    rep3 = rep2;
    rep2 = rep1;
    rep1 = rep0;
    v30 = v28 * (v27 >> 11);
    p[state + 192] = v28 + ((2048 - v28) >> 5);
    v31 = p + 818;
    v32 = state < 7 ? 0 : 3;
    goto LABEL_72;
  }
  v33 = v27 - v29;
  v8 -= v29;
  p[state + 192] = v28 - (v28 >> 5);
  if ( v33 < 0x1000000 )
  {
    if ( Buffer != BufferLim )
    {
      v33 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
      goto LABEL_50;
    }
    return 1;
  }
LABEL_50:
  v34 = p[state + 204];
  v35 = v34 * (v33 >> 11);
  if ( v8 >= v35 )
  {
    v41 = v33 - v35;
    v8 -= v35;
    p[state + 204] = v34 - (v34 >> 5);
    if ( v41 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v41 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v42 = p[state + 216];
    v43 = v42 * (v41 >> 11);
    if ( v8 >= v43 )
    {
      v46 = v41 - v43;
      v8 -= v43;
      p[state + 216] = v42 - (v42 >> 5);
      if ( v46 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v46 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v47 = p[state + 228];
      v48 = v47 * (v46 >> 11);
      if ( v8 >= v48 )
      {
        v30 = v46 - v48;
        v8 -= v48;
        p[state + 228] = v47 - (v47 >> 5);
        v45 = rep3;
        rep3 = rep2;
      }
      else
      {
        v30 = v47 * (v46 >> 11);
        v49 = v47 + ((2048 - v47) >> 5);
        v45 = rep2;
        p[state + 228] = v49;
      }
      rep2 = rep1;
    }
    else
    {
      v30 = v42 * (v41 >> 11);
      v44 = v42 + ((2048 - v42) >> 5);
      v45 = rep1;
      p[state + 216] = v44;
    }
    rep1 = rep0;
    rep0 = v45;
  }
  else
  {
    p[state + 204] = v34 + ((2048 - v34) >> 5);
    v36 = v34 * (v33 >> 11);
    v37 = &p[16 * state + 240 + offset];
    if ( v35 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v36 = v35 << 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v38 = *v37;
    v39 = *v37 * (v36 >> 11);
    if ( v8 < v39 )
    {
      v14 = *v37 * (v36 >> 11);
      *v37 = v38 + ((2048 - v38) >> 5);
      if ( nowPos != 0 )
      {
        v40 = nowPos - rep0;
        ++nowPos;
        state = 2 * (state >= 7) + 9;
        LOBYTE(v40) = outStream[v40];
        outStream[nowPos - 1] = v40;
        HIBYTE(pCallbackFunc) = v40;
        goto LABEL_37;
      }
      return 1;
    }
    v30 = v36 - v39;
    v8 -= v39;
    *v37 = v38 - (v38 >> 5);
  }
  v32 = state >= 7 ? 11 : 8;
  v31 = p + 1332;
LABEL_72:
  state = v32;
  if ( v30 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v30 <<= 8;
    v8 = *Buffer++ | (v8 << 8);
  }
  v50 = *v31;
  v51 = *v31 * (v30 >> 11);
  if ( v8 >= v51 )
  {
    v53 = v30 - v51;
    v8 -= v51;
    *v31 = v50 - (v50 >> 5);
    if ( v53 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v53 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v54 = v31[1];
    v55 = v54 * (v53 >> 11);
    if ( v8 >= v55 )
    {
      v14 = v53 - v55;
      v8 -= v55;
      v31[1] = v54 - (v54 >> 5);
      v52 = (int)(v31 + 258);
      offsetb = 16;
      numDirectBitsa = 8;
    }
    else
    {
      v14 = v54 * (v53 >> 11);
      v31[1] = v54 + ((2048 - v54) >> 5);
      v52 = (int)&v31[8 * offset + 130];
      offsetb = 8;
      numDirectBitsa = 3;
    }
  }
  else
  {
    v14 = *v31 * (v30 >> 11);
    *v31 = v50 + ((2048 - v50) >> 5);
    v52 = (int)&v31[8 * offset + 2];
    offsetb = 0;
    numDirectBitsa = 3;
  }
  ib = numDirectBitsa;
  v56 = 1;
  do
  {
    if ( v14 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v14 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v57 = *(_DWORD *)(v52 + 4 * v56);
    v58 = v57 * (v14 >> 11);
    if ( v8 >= v58 )
    {
      v14 -= v58;
      v8 -= v58;
      *(_DWORD *)(v52 + 4 * v56) = v57 - (v57 >> 5);
      v56 = 2 * v56 + 1;
    }
    else
    {
      v14 = v57 * (v14 >> 11);
      *(_DWORD *)(v52 + 4 * v56) = v57 + ((2048 - v57) >> 5);
      v56 *= 2;
    }
    v59 = 1;
    --ib;
  }
  while ( ib != 0 );
  v60 = offsetb - (1 << numDirectBitsa) + v56;
  ic = v60;
  if ( state < 4 )
  {
    state += 7;
    if ( v60 >= 4 )
      v60 = 3;
    v61 = (int)&p[64 * v60 + 432];
    for ( numDirectBitsb = 6; numDirectBitsb != 0; --numDirectBitsb )
    {
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v62 = *(_DWORD *)(v61 + 4 * v59);
      v63 = v62 * (v14 >> 11);
      if ( v8 >= v63 )
      {
        v14 -= v63;
        v8 -= v63;
        *(_DWORD *)(v61 + 4 * v59) = v62 - (v62 >> 5);
        v59 = 2 * v59 + 1;
      }
      else
      {
        v14 = v62 * (v14 >> 11);
        *(_DWORD *)(v61 + 4 * v59) = v62 + ((2048 - v62) >> 5);
        v59 *= 2;
      }
    }
    v64 = v59 - 64;
    if ( v64 < 4 )
    {
      rep0a = v64;
    }
    else
    {
      v65 = (v64 >> 1) - 1;
      v66 = v64 & 1 | 2;
      numDirectBitsc = v65;
      if ( v64 >= 14 )
      {
        v68 = Buffer;
        v69 = v65 - 4;
        do
        {
          if ( v14 < 0x1000000 )
          {
            if ( v68 == BufferLim )
              return 1;
            v14 <<= 8;
            v8 = *v68++ | (v8 << 8);
            Buffer = v68;
          }
          v14 >>= 1;
          v66 *= 2;
          rep0b = v66;
          if ( v8 >= v14 )
          {
            v8 -= v14;
            v66 |= 1u;
            rep0b = v66;
          }
          --v69;
        }
        while ( v69 != 0 );
        v67 = (int)(p + 802);
        rep0a = 16 * rep0b;
        numDirectBitsc = 4;
      }
      else
      {
        rep0a = (v64 & 1 | 2) << v65;
        v67 = (int)&p[rep0a - v64 + 687];
      }
      v70 = 1;
      offsetc = 1;
      do
      {
        if ( v14 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v14 <<= 8;
          v8 = *Buffer++ | (v8 << 8);
        }
        v71 = *(_DWORD *)(v67 + 4 * v70);
        v72 = v71 * (v14 >> 11);
        if ( v8 >= v72 )
        {
          v14 -= v72;
          v8 -= v72;
          *(_DWORD *)(v67 + 4 * v70) = v71 - (v71 >> 5);
          rep0a |= offsetc;
          v70 = 2 * v70 + 1;
        }
        else
        {
          v14 = v71 * (v14 >> 11);
          *(_DWORD *)(v67 + 4 * v70) = v71 + ((2048 - v71) >> 5);
          v70 *= 2;
        }
        offsetc *= 2;
        --numDirectBitsc;
      }
      while ( numDirectBitsc != 0 );
    }
    rep0 = rep0a + 1;
    if ( rep0 == 0 )
      goto LABEL_38;
    v60 = ic;
  }
  v73 = nowPos;
  v74 = v60 + 2;
  if ( rep0 > nowPos )
    return 1;
  for ( m = &outStream[-rep0]; ; m = &outStream[-rep0] )
  {
    v76 = m[v73];
    outStream[v73++] = v76;
    --v74;
    HIBYTE(pCallbackFunc) = v76;
    nowPos = v73;
    if ( v74 == 0 )
      goto LABEL_37;
    if ( v73 >= outSize )
      break;
  }
LABEL_38:
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_131:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10024DE0
// Name: public: bool CLZMA::IsCompressed(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLZMA::IsCompressed(CLZMA *this, unsigned __int8 *pInput)
{
  return pInput != nullptr && *(_DWORD *)pInput == 1095588428;
}

//------------------------------------------------------------------------------
// Address: 0x10024E00
// Name: public: unsigned int CLZMA::GetActualSize(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZMA::GetActualSize(CLZMA *this, unsigned __int8 *pInput)
{
  if ( pInput != nullptr && *(_DWORD *)pInput == 1095588428 )
    return *((_DWORD *)pInput + 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10024E20
// Name: public: unsigned int CLZMA::Uncompress(unsigned char __near *,unsigned char __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZMA::Uncompress(
        CLZMA *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        void (__cdecl *pCallback)())
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ebx
  unsigned int *v6; // edi
  int v7; // esi
  unsigned __int8 *result; // eax
  unsigned int v9; // [esp-1Ch] [ebp-34h]
  _CLzmaDecoderState state; // [esp+8h] [ebp-10h] BYREF

  v4 = pInput;
  if ( pInput == nullptr )
    return nullptr;
  if ( *(_DWORD *)pInput != 1095588428 )
    return nullptr;
  v5 = *((unsigned __int8 **)pInput + 1);
  if ( v5 == nullptr )
    return nullptr;
  LzmaDecodeProperties(propsRes: &state.Properties, propsData: pInput + 12, size: 5);
  v6 = (unsigned int *)_g_pMemAlloc->Alloc_2(
                         this: _g_pMemAlloc,
                         a2: 4 * (768 << (LOBYTE(state.Properties.lp) + LOBYTE(state.Properties.lc))) + 7384);
  v9 = *((_DWORD *)v4 + 2);
  state.Probs = v6;
  v7 = LzmaDecode(
         vs: &state,
         inStream: v4 + 17,
         inSize: v9,
         inSizeProcessed: (unsigned int *)&pCallback,
         outStream: pOutput,
         outSize: (unsigned int)v5,
         outSizeProcessed: (unsigned int *)&pInput,
         pCallbackFunc: pCallback);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  if ( v7 != 0 )
    return nullptr;
  result = pInput;
  if ( pInput != v5 )
    return nullptr;
  return result;
}

} // namespace FileSystem_Steam

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10270BE0
// Name: int LzmaDecodeWithCallback(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeWithCallback(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        const unsigned __int8 *inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int *Probs; // edi
  int v9; // edx
  int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // esi
  int j; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // eax
  int k; // ebx
  int v19; // ebx
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v25; // eax
  unsigned int v26; // esi
  unsigned int v27; // edx
  unsigned int v28; // ebx
  unsigned int v29; // esi
  int v30; // edx
  unsigned int *v31; // eax
  unsigned int v32; // esi
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned int v35; // esi
  unsigned int *v36; // ebx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  unsigned int v39; // ecx
  unsigned __int8 v40; // dl
  unsigned int v41; // esi
  unsigned int v42; // edx
  unsigned int v43; // ebx
  unsigned int v44; // ebx
  unsigned int v45; // edx
  unsigned int v46; // esi
  unsigned int v47; // edx
  unsigned int v48; // ebx
  unsigned int v49; // ebx
  const unsigned __int8 *v50; // ebx
  unsigned int v51; // ecx
  unsigned int v52; // edx
  int v53; // ecx
  unsigned int v54; // esi
  unsigned int v55; // ecx
  unsigned int v56; // edx
  int v57; // ebx
  unsigned int v58; // eax
  unsigned int v59; // edx
  int v60; // ebx
  int v61; // ebx
  int v62; // eax
  unsigned int v63; // ecx
  unsigned int v64; // edx
  int v65; // eax
  int v66; // edx
  int v67; // ecx
  int v68; // ebx
  const unsigned __int8 *v69; // eax
  int v70; // edx
  int v71; // ecx
  unsigned int v72; // eax
  unsigned int v73; // edx
  unsigned int v74; // ebx
  unsigned __int8 *v75; // ecx
  unsigned __int8 v76; // al
  unsigned int literalPosMask; // [esp+Ch] [ebp-34h]
  unsigned int posStateMask; // [esp+10h] [ebp-30h]
  char lc; // [esp+14h] [ebp-2Ch]
  int offset; // [esp+18h] [ebp-28h]
  int offseta; // [esp+18h] [ebp-28h]
  int offsetb; // [esp+18h] [ebp-28h]
  int offsetc; // [esp+18h] [ebp-28h]
  unsigned int rep3; // [esp+1Ch] [ebp-24h]
  unsigned int *p; // [esp+20h] [ebp-20h]
  unsigned int rep1; // [esp+24h] [ebp-1Ch]
  unsigned int rep2; // [esp+28h] [ebp-18h]
  unsigned int *i; // [esp+2Ch] [ebp-14h]
  int ia; // [esp+2Ch] [ebp-14h]
  unsigned int *ib; // [esp+2Ch] [ebp-14h]
  int ic; // [esp+2Ch] [ebp-14h]
  int id; // [esp+2Ch] [ebp-14h]
  int ie; // [esp+2Ch] [ebp-14h]
  unsigned int nowPos; // [esp+30h] [ebp-10h]
  int state; // [esp+34h] [ebp-Ch]
  const unsigned __int8 *BufferLim; // [esp+38h] [ebp-8h]
  unsigned int rep0; // [esp+3Ch] [ebp-4h]
  unsigned int rep0a; // [esp+3Ch] [ebp-4h]
  unsigned int rep0b; // [esp+3Ch] [ebp-4h]
  unsigned int *numDirectBits; // [esp+48h] [ebp+8h]
  int numDirectBitsa; // [esp+48h] [ebp+8h]
  int numDirectBitsb; // [esp+48h] [ebp+8h]
  int numDirectBitsc; // [esp+48h] [ebp+8h]
  unsigned __int8 numDirectBits_3; // [esp+4Bh] [ebp+Bh]
  const unsigned __int8 *Buffer; // [esp+50h] [ebp+10h]

  posStateMask = (1 << vs->Properties.pb) - 1;
  Probs = vs->Probs;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v9 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v10 = v9 + vs->Properties.lp;
  p = Probs;
  nowPos = 0;
  numDirectBits_3 = 0;
  lc = v9;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v10 != -1846 )
    memset32(Probs, 1024, (768 << v10) + 1846);
  v11 = inStream;
  v12 = 0;
  v13 = -1;
  BufferLim = &inSize[(_DWORD)inStream];
  for ( j = 0; j < 5; ++j )
  {
    if ( v11 == &inSize[(_DWORD)inStream] )
      return 1;
    v12 = *v11++ | (v12 << 8);
  }
  Buffer = v11;
  if ( outSize == 0 )
    goto LABEL_41;
  do
  {
    offset = nowPos & posStateMask;
    i = &p[16 * state + (nowPos & posStateMask)];
    if ( v13 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v13 <<= 8;
      v12 = *Buffer++ | (v12 << 8);
    }
    v15 = *i;
    v16 = *i * (v13 >> 11);
    if ( v12 >= v16 )
    {
      v26 = v13 - v16;
      v12 -= v16;
      *i = v15 - (v15 >> 5);
      if ( v26 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v26 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v27 = p[state + 192];
      v28 = v27 * (v26 >> 11);
      if ( v12 >= v28 )
      {
        v32 = v26 - v28;
        v12 -= v28;
        p[state + 192] = v27 - (v27 >> 5);
        if ( v32 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v32 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v33 = p[state + 204];
        v34 = v33 * (v32 >> 11);
        if ( v12 >= v34 )
        {
          v41 = v32 - v34;
          v12 -= v34;
          p[state + 204] = v33 - (v33 >> 5);
          if ( v41 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v41 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v42 = p[state + 216];
          v43 = v42 * (v41 >> 11);
          if ( v12 >= v43 )
          {
            v46 = v41 - v43;
            v12 -= v43;
            p[state + 216] = v42 - (v42 >> 5);
            if ( v46 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v46 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v47 = p[state + 228];
            v48 = v47 * (v46 >> 11);
            if ( v12 >= v48 )
            {
              v29 = v46 - v48;
              v12 -= v48;
              p[state + 228] = v47 - (v47 >> 5);
              v45 = rep3;
              rep3 = rep2;
            }
            else
            {
              v29 = v47 * (v46 >> 11);
              v49 = v47 + ((2048 - v47) >> 5);
              v45 = rep2;
              p[state + 228] = v49;
            }
            rep2 = rep1;
          }
          else
          {
            v29 = v42 * (v41 >> 11);
            v44 = v42 + ((2048 - v42) >> 5);
            v45 = rep1;
            p[state + 216] = v44;
          }
          rep1 = rep0;
          rep0 = v45;
        }
        else
        {
          v35 = v33 * (v32 >> 11);
          p[state + 204] = v33 + ((2048 - v33) >> 5);
          v36 = &p[16 * state + 240 + offset];
          ib = v36;
          if ( v35 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v35 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v37 = *v36;
          v38 = *v36 * (v35 >> 11);
          if ( v12 < v38 )
          {
            v13 = v38;
            *ib = v37 + ((2048 - v37) >> 5);
            if ( nowPos != 0 )
            {
              state = 2 * (state >= 7) + 9;
              v39 = nowPos + 1;
              v40 = outStream[nowPos - rep0];
              outStream[v39 - 1] = v40;
              numDirectBits_3 = v40;
              ++nowPos;
              if ( v39 % 0x7A120 == 0 )
                pCallbackFunc();
              continue;
            }
            return 1;
          }
          v29 = v35 - v38;
          v12 -= v38;
          *ib = v37 - (v37 >> 5);
        }
        v30 = state >= 7 ? 11 : 8;
        v31 = p + 1332;
      }
      else
      {
        v29 = v27 * (v26 >> 11);
        rep3 = rep2;
        rep2 = rep1;
        rep1 = rep0;
        p[state + 192] = v27 + ((2048 - v27) >> 5);
        v30 = state < 7 ? 0 : 3;
        v31 = p + 818;
      }
      v50 = Buffer;
      state = v30;
      if ( v29 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v29 <<= 8;
        v12 = *Buffer | (v12 << 8);
        v50 = ++Buffer;
      }
      v51 = *v31;
      v52 = *v31 * (v29 >> 11);
      if ( v12 >= v52 )
      {
        v54 = v29 - v52;
        v12 -= v52;
        *v31 = v51 - (v51 >> 5);
        if ( v54 < 0x1000000 )
        {
          if ( v50 == BufferLim )
            return 1;
          v54 <<= 8;
          v12 = *v50 | (v12 << 8);
          Buffer = v50 + 1;
        }
        v55 = v31[1];
        v56 = v55 * (v54 >> 11);
        if ( v12 >= v56 )
        {
          v13 = v54 - v56;
          v12 -= v56;
          v31[1] = v55 - (v55 >> 5);
          v53 = (int)(v31 + 258);
          offsetb = 16;
          numDirectBitsa = 8;
        }
        else
        {
          v13 = v55 * (v54 >> 11);
          v31[1] = v55 + ((2048 - v55) >> 5);
          v53 = (int)&v31[8 * offset + 130];
          offsetb = 8;
          numDirectBitsa = 3;
        }
      }
      else
      {
        v13 = *v31 * (v29 >> 11);
        *v31 = v51 + ((2048 - v51) >> 5);
        v53 = (int)&v31[8 * offset + 2];
        offsetb = 0;
        numDirectBitsa = 3;
      }
      ic = numDirectBitsa;
      v57 = 1;
      do
      {
        if ( v13 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v13 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v58 = *(_DWORD *)(v53 + 4 * v57);
        v59 = v58 * (v13 >> 11);
        if ( v12 >= v59 )
        {
          v13 -= v59;
          v12 -= v59;
          *(_DWORD *)(v53 + 4 * v57) = v58 - (v58 >> 5);
          v57 = 2 * v57 + 1;
        }
        else
        {
          v13 = v58 * (v13 >> 11);
          *(_DWORD *)(v53 + 4 * v57) = v58 + ((2048 - v58) >> 5);
          v57 *= 2;
        }
        --ic;
      }
      while ( ic != 0 );
      v60 = offsetb - (1 << numDirectBitsa) + v57;
      id = v60;
      if ( state < 4 )
      {
        state += 7;
        if ( v60 >= 4 )
          v60 = 3;
        v61 = (int)&p[64 * v60 + 432];
        numDirectBitsb = 6;
        v62 = 1;
        do
        {
          if ( v13 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v13 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v63 = *(_DWORD *)(v61 + 4 * v62);
          v64 = v63 * (v13 >> 11);
          if ( v12 >= v64 )
          {
            v13 -= v64;
            v12 -= v64;
            *(_DWORD *)(v61 + 4 * v62) = v63 - (v63 >> 5);
            v62 = 2 * v62 + 1;
          }
          else
          {
            v13 = v63 * (v13 >> 11);
            *(_DWORD *)(v61 + 4 * v62) = v63 + ((2048 - v63) >> 5);
            v62 *= 2;
          }
          --numDirectBitsb;
        }
        while ( numDirectBitsb != 0 );
        v65 = v62 - 64;
        if ( v65 < 4 )
        {
          rep0a = v65;
        }
        else
        {
          v66 = (v65 >> 1) - 1;
          v67 = v65 & 1 | 2;
          numDirectBitsc = v66;
          if ( v65 >= 14 )
          {
            v69 = Buffer;
            v70 = v66 - 4;
            do
            {
              if ( v13 < 0x1000000 )
              {
                if ( v69 == BufferLim )
                  return 1;
                v13 <<= 8;
                v12 = *v69++ | (v12 << 8);
                Buffer = v69;
              }
              v13 >>= 1;
              v67 *= 2;
              rep0b = v67;
              if ( v12 >= v13 )
              {
                v12 -= v13;
                v67 |= 1u;
                rep0b = v67;
              }
              --v70;
            }
            while ( v70 != 0 );
            v68 = (int)(p + 802);
            rep0a = 16 * rep0b;
            numDirectBitsc = 4;
          }
          else
          {
            rep0a = (v65 & 1 | 2) << v66;
            v68 = (int)&p[rep0a - v65 + 687];
          }
          v71 = 1;
          offsetc = 1;
          do
          {
            if ( v13 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v13 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v72 = *(_DWORD *)(v68 + 4 * v71);
            v73 = v72 * (v13 >> 11);
            if ( v12 >= v73 )
            {
              v13 -= v73;
              v12 -= v73;
              *(_DWORD *)(v68 + 4 * v71) = v72 - (v72 >> 5);
              rep0a |= offsetc;
              v71 = 2 * v71 + 1;
            }
            else
            {
              v13 = v72 * (v13 >> 11);
              *(_DWORD *)(v68 + 4 * v71) = v72 + ((2048 - v72) >> 5);
              v71 *= 2;
            }
            offsetc *= 2;
            --numDirectBitsc;
          }
          while ( numDirectBitsc != 0 );
        }
        rep0 = rep0a + 1;
        if ( rep0 == 0 )
          break;
      }
      v74 = nowPos;
      ie = id + 2;
      if ( rep0 <= nowPos )
      {
        v75 = &outStream[-rep0];
        do
        {
          v76 = v75[v74];
          outStream[v74] = v76;
          --ie;
          numDirectBits_3 = v76;
          nowPos = ++v74;
          if ( v74 % 0x7A120 == 0 )
          {
            pCallbackFunc();
            v75 = &outStream[-rep0];
          }
          if ( ie == 0 )
            goto LABEL_37;
        }
        while ( v74 < outSize );
        break;
      }
      return 1;
    }
    *i = v15 + ((2048 - v15) >> 5);
    v13 = v16;
    v17 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (numDirectBits_3 >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_19;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v19 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v19 + v17) + 1024);
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v20 = *numDirectBits;
      v21 = *numDirectBits * (v13 >> 11);
      if ( v12 >= v21 )
        break;
      v13 = *numDirectBits * (v13 >> 11);
      v17 *= 2;
      *numDirectBits = v20 + ((2048 - v20) >> 5);
      if ( v19 != 0 )
        goto LABEL_18;
LABEL_26:
      if ( v17 >= 256 )
        goto LABEL_30;
    }
    v13 -= v21;
    v12 -= v21;
    *numDirectBits = v20 - (v20 >> 5);
    v17 = 2 * v17 + 1;
    if ( v19 != 0 )
      goto LABEL_26;
LABEL_18:
    while ( v17 < 256 )
    {
LABEL_19:
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v22 = *(_DWORD *)(ia + 4 * v17);
      v23 = v22 * (v13 >> 11);
      if ( v12 >= v23 )
      {
        v13 -= v23;
        v12 -= v23;
        *(_DWORD *)(ia + 4 * v17) = v22 - (v22 >> 5);
        v17 = 2 * v17 + 1;
      }
      else
      {
        v13 = v22 * (v13 >> 11);
        *(_DWORD *)(ia + 4 * v17) = v22 + ((2048 - v22) >> 5);
        v17 *= 2;
      }
    }
LABEL_30:
    outStream[nowPos] = v17;
    numDirectBits_3 = v17;
    if ( ++nowPos % 0x7A120 == 0 )
      pCallbackFunc();
    if ( state >= 4 )
    {
      if ( state >= 10 )
        v25 = state - 6;
      else
        v25 = state - 3;
      state = v25;
    }
    else
    {
      state = 0;
    }
LABEL_37:
    ;
  }
  while ( nowPos < outSize );
  if ( v13 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_41:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10271500
// Name: int LzmaDecode(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecode(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        unsigned int inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int v8; // esi
  unsigned int *Probs; // edi
  int v11; // edx
  int v12; // ecx
  const unsigned __int8 *v13; // ecx
  unsigned int v14; // eax
  int j; // edx
  const unsigned __int8 *v16; // edx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  int v19; // edx
  int k; // ebx
  int v21; // ebx
  unsigned int v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ecx
  unsigned int v25; // edi
  int v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int *v31; // ecx
  int v32; // edx
  unsigned int v33; // eax
  unsigned int v34; // edi
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int *v37; // ebx
  unsigned int v38; // edx
  unsigned int v39; // edi
  unsigned int v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // edx
  unsigned int v43; // edi
  unsigned int v44; // edi
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // edx
  unsigned int v48; // edi
  unsigned int v49; // edi
  unsigned int v50; // edx
  unsigned int v51; // edi
  int v52; // ecx
  unsigned int v53; // eax
  unsigned int v54; // edx
  unsigned int v55; // edi
  int v56; // ebx
  unsigned int v57; // edx
  unsigned int v58; // edi
  int v59; // edx
  int v60; // ebx
  int v61; // ebx
  unsigned int v62; // ecx
  unsigned int v63; // edi
  int v64; // edx
  int v65; // edi
  int v66; // ecx
  int v67; // ebx
  const unsigned __int8 *v68; // edx
  int v69; // edi
  int v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // edi
  unsigned int v73; // ecx
  int v74; // ebx
  unsigned __int8 *m; // edx
  unsigned __int8 v76; // dl
  unsigned int literalPosMask; // [esp+4h] [ebp-38h]
  unsigned int posStateMask; // [esp+8h] [ebp-34h]
  char lc; // [esp+Ch] [ebp-30h]
  unsigned int rep3; // [esp+10h] [ebp-2Ch]
  int offset; // [esp+14h] [ebp-28h]
  int offseta; // [esp+14h] [ebp-28h]
  int offsetb; // [esp+14h] [ebp-28h]
  int offsetc; // [esp+14h] [ebp-28h]
  unsigned int rep1; // [esp+18h] [ebp-24h]
  unsigned int rep2; // [esp+1Ch] [ebp-20h]
  unsigned int *i; // [esp+20h] [ebp-1Ch]
  int ia; // [esp+20h] [ebp-1Ch]
  int ib; // [esp+20h] [ebp-1Ch]
  int ic; // [esp+20h] [ebp-1Ch]
  unsigned int *p; // [esp+24h] [ebp-18h]
  int state; // [esp+28h] [ebp-14h]
  unsigned int nowPos; // [esp+2Ch] [ebp-10h]
  const unsigned __int8 *BufferLim; // [esp+30h] [ebp-Ch]
  unsigned int rep0; // [esp+34h] [ebp-8h]
  unsigned int rep0a; // [esp+34h] [ebp-8h]
  unsigned int rep0b; // [esp+34h] [ebp-8h]
  const unsigned __int8 *Buffer; // [esp+38h] [ebp-4h]
  unsigned int *numDirectBits; // [esp+60h] [ebp+24h]
  int numDirectBitsa; // [esp+60h] [ebp+24h]
  int numDirectBitsb; // [esp+60h] [ebp+24h]
  int numDirectBitsc; // [esp+60h] [ebp+24h]

  v8 = 0;
  if ( pCallbackFunc != nullptr )
    return LzmaDecodeWithCallback(
             vs,
             inStream,
             (const unsigned __int8 *)inSize,
             inSizeProcessed,
             outStream,
             outSize,
             outSizeProcessed,
             pCallbackFunc);
  Probs = vs->Probs;
  posStateMask = (1 << vs->Properties.pb) - 1;
  p = Probs;
  nowPos = 0;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v11 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v12 = v11 + vs->Properties.lp;
  lc = v11;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v12 != -1846 )
    memset32(Probs, 1024, (768 << v12) + 1846);
  v13 = inStream;
  v14 = -1;
  BufferLim = &inStream[inSize];
  for ( j = 0; j < 5; ++j )
  {
    if ( v13 == &inStream[inSize] )
      return 1;
    v8 = *v13++ | (v8 << 8);
  }
  Buffer = v13;
  if ( outSize == 0 )
    goto LABEL_131;
LABEL_9:
  offset = nowPos & posStateMask;
  i = &p[16 * state + (nowPos & posStateMask)];
  v16 = Buffer;
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v14 <<= 8;
    v8 = *Buffer | (v8 << 8);
    v16 = ++Buffer;
  }
  v17 = *i;
  v18 = *i * (v14 >> 11);
  if ( v8 < v18 )
  {
    *i = v17 + ((2048 - v17) >> 5);
    v14 = v18;
    v19 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (HIBYTE(pCallbackFunc) >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_21;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v21 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v21 + v19) + 1024);
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v22 = *numDirectBits;
      v23 = *numDirectBits * (v14 >> 11);
      if ( v8 >= v23 )
      {
        v14 -= v23;
        v8 -= v23;
        *numDirectBits = v22 - (v22 >> 5);
        v19 = 2 * v19 + 1;
        if ( v21 == 0 )
        {
LABEL_20:
          while ( v19 < 256 )
          {
LABEL_21:
            if ( v14 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v14 <<= 8;
              v8 = *Buffer++ | (v8 << 8);
            }
            v24 = *(_DWORD *)(ia + 4 * v19);
            v25 = v24 * (v14 >> 11);
            if ( v8 >= v25 )
            {
              v14 -= v25;
              v8 -= v25;
              *(_DWORD *)(ia + 4 * v19) = v24 - (v24 >> 5);
              v19 = 2 * v19 + 1;
            }
            else
            {
              v14 = v24 * (v14 >> 11);
              *(_DWORD *)(ia + 4 * v19) = v24 + ((2048 - v24) >> 5);
              v19 *= 2;
            }
          }
LABEL_32:
          outStream[nowPos++] = v19;
          HIBYTE(pCallbackFunc) = v19;
          if ( state >= 4 )
          {
            if ( state >= 10 )
              v26 = state - 6;
            else
              v26 = state - 3;
            state = v26;
          }
          else
          {
            state = 0;
          }
LABEL_37:
          if ( nowPos >= outSize )
            goto LABEL_38;
          goto LABEL_9;
        }
      }
      else
      {
        v14 = *numDirectBits * (v14 >> 11);
        v19 *= 2;
        *numDirectBits = v22 + ((2048 - v22) >> 5);
        if ( v21 != 0 )
          goto LABEL_20;
      }
      if ( v19 >= 256 )
        goto LABEL_32;
    }
  }
  v27 = v14 - v18;
  v8 -= v18;
  *i = v17 - (v17 >> 5);
  if ( v27 < 0x1000000 )
  {
    if ( v16 == BufferLim )
      return 1;
    v27 <<= 8;
    v8 = *v16 | (v8 << 8);
    Buffer = v16 + 1;
  }
  v28 = p[state + 192];
  v29 = v28 * (v27 >> 11);
  if ( v8 < v29 )
  {
    rep3 = rep2;
    rep2 = rep1;
    rep1 = rep0;
    v30 = v28 * (v27 >> 11);
    p[state + 192] = v28 + ((2048 - v28) >> 5);
    v31 = p + 818;
    v32 = state < 7 ? 0 : 3;
    goto LABEL_72;
  }
  v33 = v27 - v29;
  v8 -= v29;
  p[state + 192] = v28 - (v28 >> 5);
  if ( v33 < 0x1000000 )
  {
    if ( Buffer != BufferLim )
    {
      v33 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
      goto LABEL_50;
    }
    return 1;
  }
LABEL_50:
  v34 = p[state + 204];
  v35 = v34 * (v33 >> 11);
  if ( v8 >= v35 )
  {
    v41 = v33 - v35;
    v8 -= v35;
    p[state + 204] = v34 - (v34 >> 5);
    if ( v41 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v41 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v42 = p[state + 216];
    v43 = v42 * (v41 >> 11);
    if ( v8 >= v43 )
    {
      v46 = v41 - v43;
      v8 -= v43;
      p[state + 216] = v42 - (v42 >> 5);
      if ( v46 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v46 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v47 = p[state + 228];
      v48 = v47 * (v46 >> 11);
      if ( v8 >= v48 )
      {
        v30 = v46 - v48;
        v8 -= v48;
        p[state + 228] = v47 - (v47 >> 5);
        v45 = rep3;
        rep3 = rep2;
      }
      else
      {
        v30 = v47 * (v46 >> 11);
        v49 = v47 + ((2048 - v47) >> 5);
        v45 = rep2;
        p[state + 228] = v49;
      }
      rep2 = rep1;
    }
    else
    {
      v30 = v42 * (v41 >> 11);
      v44 = v42 + ((2048 - v42) >> 5);
      v45 = rep1;
      p[state + 216] = v44;
    }
    rep1 = rep0;
    rep0 = v45;
  }
  else
  {
    p[state + 204] = v34 + ((2048 - v34) >> 5);
    v36 = v34 * (v33 >> 11);
    v37 = &p[16 * state + 240 + offset];
    if ( v35 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v36 = v35 << 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v38 = *v37;
    v39 = *v37 * (v36 >> 11);
    if ( v8 < v39 )
    {
      v14 = *v37 * (v36 >> 11);
      *v37 = v38 + ((2048 - v38) >> 5);
      if ( nowPos != 0 )
      {
        v40 = nowPos - rep0;
        ++nowPos;
        state = 2 * (state >= 7) + 9;
        LOBYTE(v40) = outStream[v40];
        outStream[nowPos - 1] = v40;
        HIBYTE(pCallbackFunc) = v40;
        goto LABEL_37;
      }
      return 1;
    }
    v30 = v36 - v39;
    v8 -= v39;
    *v37 = v38 - (v38 >> 5);
  }
  v32 = state >= 7 ? 11 : 8;
  v31 = p + 1332;
LABEL_72:
  state = v32;
  if ( v30 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v30 <<= 8;
    v8 = *Buffer++ | (v8 << 8);
  }
  v50 = *v31;
  v51 = *v31 * (v30 >> 11);
  if ( v8 >= v51 )
  {
    v53 = v30 - v51;
    v8 -= v51;
    *v31 = v50 - (v50 >> 5);
    if ( v53 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v53 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v54 = v31[1];
    v55 = v54 * (v53 >> 11);
    if ( v8 >= v55 )
    {
      v14 = v53 - v55;
      v8 -= v55;
      v31[1] = v54 - (v54 >> 5);
      v52 = (int)(v31 + 258);
      offsetb = 16;
      numDirectBitsa = 8;
    }
    else
    {
      v14 = v54 * (v53 >> 11);
      v31[1] = v54 + ((2048 - v54) >> 5);
      v52 = (int)&v31[8 * offset + 130];
      offsetb = 8;
      numDirectBitsa = 3;
    }
  }
  else
  {
    v14 = *v31 * (v30 >> 11);
    *v31 = v50 + ((2048 - v50) >> 5);
    v52 = (int)&v31[8 * offset + 2];
    offsetb = 0;
    numDirectBitsa = 3;
  }
  ib = numDirectBitsa;
  v56 = 1;
  do
  {
    if ( v14 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v14 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v57 = *(_DWORD *)(v52 + 4 * v56);
    v58 = v57 * (v14 >> 11);
    if ( v8 >= v58 )
    {
      v14 -= v58;
      v8 -= v58;
      *(_DWORD *)(v52 + 4 * v56) = v57 - (v57 >> 5);
      v56 = 2 * v56 + 1;
    }
    else
    {
      v14 = v57 * (v14 >> 11);
      *(_DWORD *)(v52 + 4 * v56) = v57 + ((2048 - v57) >> 5);
      v56 *= 2;
    }
    v59 = 1;
    --ib;
  }
  while ( ib != 0 );
  v60 = offsetb - (1 << numDirectBitsa) + v56;
  ic = v60;
  if ( state < 4 )
  {
    state += 7;
    if ( v60 >= 4 )
      v60 = 3;
    v61 = (int)&p[64 * v60 + 432];
    for ( numDirectBitsb = 6; numDirectBitsb != 0; --numDirectBitsb )
    {
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v62 = *(_DWORD *)(v61 + 4 * v59);
      v63 = v62 * (v14 >> 11);
      if ( v8 >= v63 )
      {
        v14 -= v63;
        v8 -= v63;
        *(_DWORD *)(v61 + 4 * v59) = v62 - (v62 >> 5);
        v59 = 2 * v59 + 1;
      }
      else
      {
        v14 = v62 * (v14 >> 11);
        *(_DWORD *)(v61 + 4 * v59) = v62 + ((2048 - v62) >> 5);
        v59 *= 2;
      }
    }
    v64 = v59 - 64;
    if ( v64 < 4 )
    {
      rep0a = v64;
    }
    else
    {
      v65 = (v64 >> 1) - 1;
      v66 = v64 & 1 | 2;
      numDirectBitsc = v65;
      if ( v64 >= 14 )
      {
        v68 = Buffer;
        v69 = v65 - 4;
        do
        {
          if ( v14 < 0x1000000 )
          {
            if ( v68 == BufferLim )
              return 1;
            v14 <<= 8;
            v8 = *v68++ | (v8 << 8);
            Buffer = v68;
          }
          v14 >>= 1;
          v66 *= 2;
          rep0b = v66;
          if ( v8 >= v14 )
          {
            v8 -= v14;
            v66 |= 1u;
            rep0b = v66;
          }
          --v69;
        }
        while ( v69 != 0 );
        v67 = (int)(p + 802);
        rep0a = 16 * rep0b;
        numDirectBitsc = 4;
      }
      else
      {
        rep0a = (v64 & 1 | 2) << v65;
        v67 = (int)&p[rep0a - v64 + 687];
      }
      v70 = 1;
      offsetc = 1;
      do
      {
        if ( v14 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v14 <<= 8;
          v8 = *Buffer++ | (v8 << 8);
        }
        v71 = *(_DWORD *)(v67 + 4 * v70);
        v72 = v71 * (v14 >> 11);
        if ( v8 >= v72 )
        {
          v14 -= v72;
          v8 -= v72;
          *(_DWORD *)(v67 + 4 * v70) = v71 - (v71 >> 5);
          rep0a |= offsetc;
          v70 = 2 * v70 + 1;
        }
        else
        {
          v14 = v71 * (v14 >> 11);
          *(_DWORD *)(v67 + 4 * v70) = v71 + ((2048 - v71) >> 5);
          v70 *= 2;
        }
        offsetc *= 2;
        --numDirectBitsc;
      }
      while ( numDirectBitsc != 0 );
    }
    rep0 = rep0a + 1;
    if ( rep0 == 0 )
      goto LABEL_38;
    v60 = ic;
  }
  v73 = nowPos;
  v74 = v60 + 2;
  if ( rep0 > nowPos )
    return 1;
  for ( m = &outStream[-rep0]; ; m = &outStream[-rep0] )
  {
    v76 = m[v73];
    outStream[v73++] = v76;
    --v74;
    HIBYTE(pCallbackFunc) = v76;
    nowPos = v73;
    if ( v74 == 0 )
      goto LABEL_37;
    if ( v73 >= outSize )
      break;
  }
LABEL_38:
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_131:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10271DE0
// Name: public: bool CLZMA::IsCompressed(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLZMA::IsCompressed(CLZMA *this, unsigned __int8 *pInput)
{
  return pInput != nullptr && *(_DWORD *)pInput == 1095588428;
}

//------------------------------------------------------------------------------
// Address: 0x10271E00
// Name: public: unsigned int CLZMA::GetActualSize(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZMA::GetActualSize(CLZMA *this, unsigned __int8 *pInput)
{
  if ( pInput != nullptr && *(_DWORD *)pInput == 1095588428 )
    return *((_DWORD *)pInput + 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10271E20
// Name: public: unsigned int CLZMA::Uncompress(unsigned char __near *,unsigned char __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZMA::Uncompress(
        CLZMA *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        void (__cdecl *pCallback)())
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ebx
  unsigned int *v6; // edi
  int v7; // esi
  unsigned __int8 *result; // eax
  unsigned int v9; // [esp-1Ch] [ebp-34h]
  _CLzmaDecoderState state; // [esp+8h] [ebp-10h] BYREF

  v4 = pInput;
  if ( pInput == nullptr )
    return nullptr;
  if ( *(_DWORD *)pInput != 1095588428 )
    return nullptr;
  v5 = *((unsigned __int8 **)pInput + 1);
  if ( v5 == nullptr )
    return nullptr;
  LzmaDecodeProperties(propsRes: &state.Properties, propsData: pInput + 12, size: 5);
  v6 = (unsigned int *)_g_pMemAlloc->Alloc_2(
                         this: _g_pMemAlloc,
                         a2: 4 * (768 << (LOBYTE(state.Properties.lp) + LOBYTE(state.Properties.lc))) + 7384);
  v9 = *((_DWORD *)v4 + 2);
  state.Probs = v6;
  v7 = LzmaDecode(
         vs: &state,
         inStream: v4 + 17,
         inSize: v9,
         inSizeProcessed: (unsigned int *)&pCallback,
         outStream: pOutput,
         outSize: (unsigned int)v5,
         outSizeProcessed: (unsigned int *)&pInput,
         pCallbackFunc: pCallback);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  if ( v7 != 0 )
    return nullptr;
  result = pInput;
  if ( pInput != v5 )
    return nullptr;
  return result;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from scenefilecache (Missing functions)
// ============================================================
namespace scenefilecache {

//------------------------------------------------------------------------------
// Address: 0x10001B80
// Name: int LzmaDecodeProperties(struct _CLzmaProperties __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeProperties(_CLzmaProperties *propsRes, unsigned __int8 *propsData, int size)
{
  unsigned __int8 v4; // cl
  unsigned int v5; // eax
  int v6; // edx
  unsigned int v7; // eax
  int v8; // edx

  if ( size < 5 )
    return 1;
  v4 = *propsData;
  if ( *propsData >= 0xE1u )
    return 1;
  propsRes->pb = 0;
  if ( v4 >= 0x2Du )
  {
    v5 = v4 / 0x2Du;
    v6 = v5;
    do
    {
      v4 -= 45;
      --v5;
    }
    while ( v5 != 0 );
    propsRes->pb = v6;
  }
  propsRes->lp = 0;
  if ( v4 >= 9u )
  {
    v7 = v4 / 9u;
    v8 = v7;
    do
    {
      v4 -= 9;
      --v7;
    }
    while ( v7 != 0 );
    propsRes->lp = v8;
  }
  propsRes->lc = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001C10
// Name: int LzmaDecodeWithCallback(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeWithCallback(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        const unsigned __int8 *inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int *Probs; // edi
  int v9; // edx
  int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // esi
  int j; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // eax
  int k; // ebx
  int v19; // ebx
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v25; // eax
  unsigned int v26; // esi
  unsigned int v27; // edx
  unsigned int v28; // ebx
  unsigned int v29; // esi
  int v30; // edx
  unsigned int *v31; // eax
  unsigned int v32; // esi
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned int v35; // esi
  unsigned int *v36; // ebx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  unsigned int v39; // ecx
  unsigned __int8 v40; // dl
  unsigned int v41; // esi
  unsigned int v42; // edx
  unsigned int v43; // ebx
  unsigned int v44; // ebx
  unsigned int v45; // edx
  unsigned int v46; // esi
  unsigned int v47; // edx
  unsigned int v48; // ebx
  unsigned int v49; // ebx
  const unsigned __int8 *v50; // ebx
  unsigned int v51; // ecx
  unsigned int v52; // edx
  int v53; // ecx
  unsigned int v54; // esi
  unsigned int v55; // ecx
  unsigned int v56; // edx
  int v57; // ebx
  unsigned int v58; // eax
  unsigned int v59; // edx
  int v60; // ebx
  int v61; // ebx
  int v62; // eax
  unsigned int v63; // ecx
  unsigned int v64; // edx
  int v65; // eax
  int v66; // edx
  int v67; // ecx
  int v68; // ebx
  const unsigned __int8 *v69; // eax
  int v70; // edx
  int v71; // ecx
  unsigned int v72; // eax
  unsigned int v73; // edx
  unsigned int v74; // ebx
  unsigned __int8 *v75; // ecx
  unsigned __int8 v76; // al
  unsigned int literalPosMask; // [esp+Ch] [ebp-34h]
  unsigned int posStateMask; // [esp+10h] [ebp-30h]
  char lc; // [esp+14h] [ebp-2Ch]
  int offset; // [esp+18h] [ebp-28h]
  int offseta; // [esp+18h] [ebp-28h]
  int offsetb; // [esp+18h] [ebp-28h]
  int offsetc; // [esp+18h] [ebp-28h]
  unsigned int rep3; // [esp+1Ch] [ebp-24h]
  unsigned int *p; // [esp+20h] [ebp-20h]
  unsigned int rep1; // [esp+24h] [ebp-1Ch]
  unsigned int rep2; // [esp+28h] [ebp-18h]
  unsigned int *i; // [esp+2Ch] [ebp-14h]
  int ia; // [esp+2Ch] [ebp-14h]
  unsigned int *ib; // [esp+2Ch] [ebp-14h]
  int ic; // [esp+2Ch] [ebp-14h]
  int id; // [esp+2Ch] [ebp-14h]
  int ie; // [esp+2Ch] [ebp-14h]
  unsigned int nowPos; // [esp+30h] [ebp-10h]
  int state; // [esp+34h] [ebp-Ch]
  const unsigned __int8 *BufferLim; // [esp+38h] [ebp-8h]
  unsigned int rep0; // [esp+3Ch] [ebp-4h]
  unsigned int rep0a; // [esp+3Ch] [ebp-4h]
  unsigned int rep0b; // [esp+3Ch] [ebp-4h]
  unsigned int *numDirectBits; // [esp+48h] [ebp+8h]
  int numDirectBitsa; // [esp+48h] [ebp+8h]
  int numDirectBitsb; // [esp+48h] [ebp+8h]
  int numDirectBitsc; // [esp+48h] [ebp+8h]
  unsigned __int8 numDirectBits_3; // [esp+4Bh] [ebp+Bh]
  const unsigned __int8 *Buffer; // [esp+50h] [ebp+10h]

  posStateMask = (1 << vs->Properties.pb) - 1;
  Probs = vs->Probs;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v9 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v10 = v9 + vs->Properties.lp;
  p = Probs;
  nowPos = 0;
  numDirectBits_3 = 0;
  lc = v9;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v10 != -1846 )
    memset32(Probs, 1024, (768 << v10) + 1846);
  v11 = inStream;
  v12 = 0;
  v13 = -1;
  BufferLim = &inSize[(_DWORD)inStream];
  for ( j = 0; j < 5; ++j )
  {
    if ( v11 == &inSize[(_DWORD)inStream] )
      return 1;
    v12 = *v11++ | (v12 << 8);
  }
  Buffer = v11;
  if ( outSize == 0 )
    goto LABEL_41;
  do
  {
    offset = nowPos & posStateMask;
    i = &p[16 * state + (nowPos & posStateMask)];
    if ( v13 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v13 <<= 8;
      v12 = *Buffer++ | (v12 << 8);
    }
    v15 = *i;
    v16 = *i * (v13 >> 11);
    if ( v12 >= v16 )
    {
      v26 = v13 - v16;
      v12 -= v16;
      *i = v15 - (v15 >> 5);
      if ( v26 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v26 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v27 = p[state + 192];
      v28 = v27 * (v26 >> 11);
      if ( v12 >= v28 )
      {
        v32 = v26 - v28;
        v12 -= v28;
        p[state + 192] = v27 - (v27 >> 5);
        if ( v32 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v32 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v33 = p[state + 204];
        v34 = v33 * (v32 >> 11);
        if ( v12 >= v34 )
        {
          v41 = v32 - v34;
          v12 -= v34;
          p[state + 204] = v33 - (v33 >> 5);
          if ( v41 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v41 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v42 = p[state + 216];
          v43 = v42 * (v41 >> 11);
          if ( v12 >= v43 )
          {
            v46 = v41 - v43;
            v12 -= v43;
            p[state + 216] = v42 - (v42 >> 5);
            if ( v46 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v46 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v47 = p[state + 228];
            v48 = v47 * (v46 >> 11);
            if ( v12 >= v48 )
            {
              v29 = v46 - v48;
              v12 -= v48;
              p[state + 228] = v47 - (v47 >> 5);
              v45 = rep3;
              rep3 = rep2;
            }
            else
            {
              v29 = v47 * (v46 >> 11);
              v49 = v47 + ((2048 - v47) >> 5);
              v45 = rep2;
              p[state + 228] = v49;
            }
            rep2 = rep1;
          }
          else
          {
            v29 = v42 * (v41 >> 11);
            v44 = v42 + ((2048 - v42) >> 5);
            v45 = rep1;
            p[state + 216] = v44;
          }
          rep1 = rep0;
          rep0 = v45;
        }
        else
        {
          v35 = v33 * (v32 >> 11);
          p[state + 204] = v33 + ((2048 - v33) >> 5);
          v36 = &p[16 * state + 240 + offset];
          ib = v36;
          if ( v35 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v35 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v37 = *v36;
          v38 = *v36 * (v35 >> 11);
          if ( v12 < v38 )
          {
            v13 = v38;
            *ib = v37 + ((2048 - v37) >> 5);
            if ( nowPos != 0 )
            {
              state = 2 * (state >= 7) + 9;
              v39 = nowPos + 1;
              v40 = outStream[nowPos - rep0];
              outStream[v39 - 1] = v40;
              numDirectBits_3 = v40;
              ++nowPos;
              if ( v39 % 0x7A120 == 0 )
                pCallbackFunc();
              continue;
            }
            return 1;
          }
          v29 = v35 - v38;
          v12 -= v38;
          *ib = v37 - (v37 >> 5);
        }
        v30 = state >= 7 ? 11 : 8;
        v31 = p + 1332;
      }
      else
      {
        v29 = v27 * (v26 >> 11);
        rep3 = rep2;
        rep2 = rep1;
        rep1 = rep0;
        p[state + 192] = v27 + ((2048 - v27) >> 5);
        v30 = state < 7 ? 0 : 3;
        v31 = p + 818;
      }
      v50 = Buffer;
      state = v30;
      if ( v29 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v29 <<= 8;
        v12 = *Buffer | (v12 << 8);
        v50 = ++Buffer;
      }
      v51 = *v31;
      v52 = *v31 * (v29 >> 11);
      if ( v12 >= v52 )
      {
        v54 = v29 - v52;
        v12 -= v52;
        *v31 = v51 - (v51 >> 5);
        if ( v54 < 0x1000000 )
        {
          if ( v50 == BufferLim )
            return 1;
          v54 <<= 8;
          v12 = *v50 | (v12 << 8);
          Buffer = v50 + 1;
        }
        v55 = v31[1];
        v56 = v55 * (v54 >> 11);
        if ( v12 >= v56 )
        {
          v13 = v54 - v56;
          v12 -= v56;
          v31[1] = v55 - (v55 >> 5);
          v53 = (int)(v31 + 258);
          offsetb = 16;
          numDirectBitsa = 8;
        }
        else
        {
          v13 = v55 * (v54 >> 11);
          v31[1] = v55 + ((2048 - v55) >> 5);
          v53 = (int)&v31[8 * offset + 130];
          offsetb = 8;
          numDirectBitsa = 3;
        }
      }
      else
      {
        v13 = *v31 * (v29 >> 11);
        *v31 = v51 + ((2048 - v51) >> 5);
        v53 = (int)&v31[8 * offset + 2];
        offsetb = 0;
        numDirectBitsa = 3;
      }
      ic = numDirectBitsa;
      v57 = 1;
      do
      {
        if ( v13 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v13 <<= 8;
          v12 = *Buffer++ | (v12 << 8);
        }
        v58 = *(_DWORD *)(v53 + 4 * v57);
        v59 = v58 * (v13 >> 11);
        if ( v12 >= v59 )
        {
          v13 -= v59;
          v12 -= v59;
          *(_DWORD *)(v53 + 4 * v57) = v58 - (v58 >> 5);
          v57 = 2 * v57 + 1;
        }
        else
        {
          v13 = v58 * (v13 >> 11);
          *(_DWORD *)(v53 + 4 * v57) = v58 + ((2048 - v58) >> 5);
          v57 *= 2;
        }
        --ic;
      }
      while ( ic != 0 );
      v60 = offsetb - (1 << numDirectBitsa) + v57;
      id = v60;
      if ( state < 4 )
      {
        state += 7;
        if ( v60 >= 4 )
          v60 = 3;
        v61 = (int)&p[64 * v60 + 432];
        numDirectBitsb = 6;
        v62 = 1;
        do
        {
          if ( v13 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v13 <<= 8;
            v12 = *Buffer++ | (v12 << 8);
          }
          v63 = *(_DWORD *)(v61 + 4 * v62);
          v64 = v63 * (v13 >> 11);
          if ( v12 >= v64 )
          {
            v13 -= v64;
            v12 -= v64;
            *(_DWORD *)(v61 + 4 * v62) = v63 - (v63 >> 5);
            v62 = 2 * v62 + 1;
          }
          else
          {
            v13 = v63 * (v13 >> 11);
            *(_DWORD *)(v61 + 4 * v62) = v63 + ((2048 - v63) >> 5);
            v62 *= 2;
          }
          --numDirectBitsb;
        }
        while ( numDirectBitsb != 0 );
        v65 = v62 - 64;
        if ( v65 < 4 )
        {
          rep0a = v65;
        }
        else
        {
          v66 = (v65 >> 1) - 1;
          v67 = v65 & 1 | 2;
          numDirectBitsc = v66;
          if ( v65 >= 14 )
          {
            v69 = Buffer;
            v70 = v66 - 4;
            do
            {
              if ( v13 < 0x1000000 )
              {
                if ( v69 == BufferLim )
                  return 1;
                v13 <<= 8;
                v12 = *v69++ | (v12 << 8);
                Buffer = v69;
              }
              v13 >>= 1;
              v67 *= 2;
              rep0b = v67;
              if ( v12 >= v13 )
              {
                v12 -= v13;
                v67 |= 1u;
                rep0b = v67;
              }
              --v70;
            }
            while ( v70 != 0 );
            v68 = (int)(p + 802);
            rep0a = 16 * rep0b;
            numDirectBitsc = 4;
          }
          else
          {
            rep0a = (v65 & 1 | 2) << v66;
            v68 = (int)&p[rep0a - v65 + 687];
          }
          v71 = 1;
          offsetc = 1;
          do
          {
            if ( v13 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v13 <<= 8;
              v12 = *Buffer++ | (v12 << 8);
            }
            v72 = *(_DWORD *)(v68 + 4 * v71);
            v73 = v72 * (v13 >> 11);
            if ( v12 >= v73 )
            {
              v13 -= v73;
              v12 -= v73;
              *(_DWORD *)(v68 + 4 * v71) = v72 - (v72 >> 5);
              rep0a |= offsetc;
              v71 = 2 * v71 + 1;
            }
            else
            {
              v13 = v72 * (v13 >> 11);
              *(_DWORD *)(v68 + 4 * v71) = v72 + ((2048 - v72) >> 5);
              v71 *= 2;
            }
            offsetc *= 2;
            --numDirectBitsc;
          }
          while ( numDirectBitsc != 0 );
        }
        rep0 = rep0a + 1;
        if ( rep0 == 0 )
          break;
      }
      v74 = nowPos;
      ie = id + 2;
      if ( rep0 <= nowPos )
      {
        v75 = &outStream[-rep0];
        do
        {
          v76 = v75[v74];
          outStream[v74] = v76;
          --ie;
          numDirectBits_3 = v76;
          nowPos = ++v74;
          if ( v74 % 0x7A120 == 0 )
          {
            pCallbackFunc();
            v75 = &outStream[-rep0];
          }
          if ( ie == 0 )
            goto LABEL_37;
        }
        while ( v74 < outSize );
        break;
      }
      return 1;
    }
    *i = v15 + ((2048 - v15) >> 5);
    v13 = v16;
    v17 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (numDirectBits_3 >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_19;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v19 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v19 + v17) + 1024);
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v20 = *numDirectBits;
      v21 = *numDirectBits * (v13 >> 11);
      if ( v12 >= v21 )
        break;
      v13 = *numDirectBits * (v13 >> 11);
      v17 *= 2;
      *numDirectBits = v20 + ((2048 - v20) >> 5);
      if ( v19 != 0 )
        goto LABEL_18;
LABEL_26:
      if ( v17 >= 256 )
        goto LABEL_30;
    }
    v13 -= v21;
    v12 -= v21;
    *numDirectBits = v20 - (v20 >> 5);
    v17 = 2 * v17 + 1;
    if ( v19 != 0 )
      goto LABEL_26;
LABEL_18:
    while ( v17 < 256 )
    {
LABEL_19:
      if ( v13 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v13 <<= 8;
        v12 = *Buffer++ | (v12 << 8);
      }
      v22 = *(_DWORD *)(ia + 4 * v17);
      v23 = v22 * (v13 >> 11);
      if ( v12 >= v23 )
      {
        v13 -= v23;
        v12 -= v23;
        *(_DWORD *)(ia + 4 * v17) = v22 - (v22 >> 5);
        v17 = 2 * v17 + 1;
      }
      else
      {
        v13 = v22 * (v13 >> 11);
        *(_DWORD *)(ia + 4 * v17) = v22 + ((2048 - v22) >> 5);
        v17 *= 2;
      }
    }
LABEL_30:
    outStream[nowPos] = v17;
    numDirectBits_3 = v17;
    if ( ++nowPos % 0x7A120 == 0 )
      pCallbackFunc();
    if ( state >= 4 )
    {
      if ( state >= 10 )
        v25 = state - 6;
      else
        v25 = state - 3;
      state = v25;
    }
    else
    {
      state = 0;
    }
LABEL_37:
    ;
  }
  while ( nowPos < outSize );
  if ( v13 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_41:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002530
// Name: int LzmaDecode(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecode(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        unsigned int inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int v8; // esi
  unsigned int *Probs; // edi
  int v11; // edx
  int v12; // ecx
  const unsigned __int8 *v13; // ecx
  unsigned int v14; // eax
  int j; // edx
  const unsigned __int8 *v16; // edx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  int v19; // edx
  int k; // ebx
  int v21; // ebx
  unsigned int v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ecx
  unsigned int v25; // edi
  int v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int *v31; // ecx
  int v32; // edx
  unsigned int v33; // eax
  unsigned int v34; // edi
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int *v37; // ebx
  unsigned int v38; // edx
  unsigned int v39; // edi
  unsigned int v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // edx
  unsigned int v43; // edi
  unsigned int v44; // edi
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // edx
  unsigned int v48; // edi
  unsigned int v49; // edi
  unsigned int v50; // edx
  unsigned int v51; // edi
  int v52; // ecx
  unsigned int v53; // eax
  unsigned int v54; // edx
  unsigned int v55; // edi
  int v56; // ebx
  unsigned int v57; // edx
  unsigned int v58; // edi
  int v59; // edx
  int v60; // ebx
  int v61; // ebx
  unsigned int v62; // ecx
  unsigned int v63; // edi
  int v64; // edx
  int v65; // edi
  int v66; // ecx
  int v67; // ebx
  const unsigned __int8 *v68; // edx
  int v69; // edi
  int v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // edi
  unsigned int v73; // ecx
  int v74; // ebx
  unsigned __int8 *m; // edx
  unsigned __int8 v76; // dl
  unsigned int literalPosMask; // [esp+4h] [ebp-38h]
  unsigned int posStateMask; // [esp+8h] [ebp-34h]
  char lc; // [esp+Ch] [ebp-30h]
  unsigned int rep3; // [esp+10h] [ebp-2Ch]
  int offset; // [esp+14h] [ebp-28h]
  int offseta; // [esp+14h] [ebp-28h]
  int offsetb; // [esp+14h] [ebp-28h]
  int offsetc; // [esp+14h] [ebp-28h]
  unsigned int rep1; // [esp+18h] [ebp-24h]
  unsigned int rep2; // [esp+1Ch] [ebp-20h]
  unsigned int *i; // [esp+20h] [ebp-1Ch]
  int ia; // [esp+20h] [ebp-1Ch]
  int ib; // [esp+20h] [ebp-1Ch]
  int ic; // [esp+20h] [ebp-1Ch]
  unsigned int *p; // [esp+24h] [ebp-18h]
  int state; // [esp+28h] [ebp-14h]
  unsigned int nowPos; // [esp+2Ch] [ebp-10h]
  const unsigned __int8 *BufferLim; // [esp+30h] [ebp-Ch]
  unsigned int rep0; // [esp+34h] [ebp-8h]
  unsigned int rep0a; // [esp+34h] [ebp-8h]
  unsigned int rep0b; // [esp+34h] [ebp-8h]
  const unsigned __int8 *Buffer; // [esp+38h] [ebp-4h]
  unsigned int *numDirectBits; // [esp+60h] [ebp+24h]
  int numDirectBitsa; // [esp+60h] [ebp+24h]
  int numDirectBitsb; // [esp+60h] [ebp+24h]
  int numDirectBitsc; // [esp+60h] [ebp+24h]

  v8 = 0;
  if ( pCallbackFunc != nullptr )
    return LzmaDecodeWithCallback(
             vs,
             inStream,
             (const unsigned __int8 *)inSize,
             inSizeProcessed,
             outStream,
             outSize,
             outSizeProcessed,
             pCallbackFunc);
  Probs = vs->Probs;
  posStateMask = (1 << vs->Properties.pb) - 1;
  p = Probs;
  nowPos = 0;
  literalPosMask = (1 << vs->Properties.lp) - 1;
  v11 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v12 = v11 + vs->Properties.lp;
  lc = v11;
  state = 0;
  rep0 = 1;
  rep1 = 1;
  rep2 = 1;
  rep3 = 1;
  if ( 768 << v12 != -1846 )
    memset32(Probs, 1024, (768 << v12) + 1846);
  v13 = inStream;
  v14 = -1;
  BufferLim = &inStream[inSize];
  for ( j = 0; j < 5; ++j )
  {
    if ( v13 == &inStream[inSize] )
      return 1;
    v8 = *v13++ | (v8 << 8);
  }
  Buffer = v13;
  if ( outSize == 0 )
    goto LABEL_131;
LABEL_9:
  offset = nowPos & posStateMask;
  i = &p[16 * state + (nowPos & posStateMask)];
  v16 = Buffer;
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v14 <<= 8;
    v8 = *Buffer | (v8 << 8);
    v16 = ++Buffer;
  }
  v17 = *i;
  v18 = *i * (v14 >> 11);
  if ( v8 < v18 )
  {
    *i = v17 + ((2048 - v17) >> 5);
    v14 = v18;
    v19 = 1;
    ia = (int)&p[768 * ((nowPos & literalPosMask) << lc) + 1846 + 768 * (HIBYTE(pCallbackFunc) >> (8 - lc))];
    if ( state < 7 )
      goto LABEL_21;
    for ( k = outStream[nowPos - rep0]; ; k = offseta )
    {
      offseta = 2 * k;
      v21 = (2 * k) & 0x100;
      numDirectBits = (unsigned int *)(ia + 4 * (v21 + v19) + 1024);
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v22 = *numDirectBits;
      v23 = *numDirectBits * (v14 >> 11);
      if ( v8 >= v23 )
      {
        v14 -= v23;
        v8 -= v23;
        *numDirectBits = v22 - (v22 >> 5);
        v19 = 2 * v19 + 1;
        if ( v21 == 0 )
        {
LABEL_20:
          while ( v19 < 256 )
          {
LABEL_21:
            if ( v14 < 0x1000000 )
            {
              if ( Buffer == BufferLim )
                return 1;
              v14 <<= 8;
              v8 = *Buffer++ | (v8 << 8);
            }
            v24 = *(_DWORD *)(ia + 4 * v19);
            v25 = v24 * (v14 >> 11);
            if ( v8 >= v25 )
            {
              v14 -= v25;
              v8 -= v25;
              *(_DWORD *)(ia + 4 * v19) = v24 - (v24 >> 5);
              v19 = 2 * v19 + 1;
            }
            else
            {
              v14 = v24 * (v14 >> 11);
              *(_DWORD *)(ia + 4 * v19) = v24 + ((2048 - v24) >> 5);
              v19 *= 2;
            }
          }
LABEL_32:
          outStream[nowPos++] = v19;
          HIBYTE(pCallbackFunc) = v19;
          if ( state >= 4 )
          {
            if ( state >= 10 )
              v26 = state - 6;
            else
              v26 = state - 3;
            state = v26;
          }
          else
          {
            state = 0;
          }
LABEL_37:
          if ( nowPos >= outSize )
            goto LABEL_38;
          goto LABEL_9;
        }
      }
      else
      {
        v14 = *numDirectBits * (v14 >> 11);
        v19 *= 2;
        *numDirectBits = v22 + ((2048 - v22) >> 5);
        if ( v21 != 0 )
          goto LABEL_20;
      }
      if ( v19 >= 256 )
        goto LABEL_32;
    }
  }
  v27 = v14 - v18;
  v8 -= v18;
  *i = v17 - (v17 >> 5);
  if ( v27 < 0x1000000 )
  {
    if ( v16 == BufferLim )
      return 1;
    v27 <<= 8;
    v8 = *v16 | (v8 << 8);
    Buffer = v16 + 1;
  }
  v28 = p[state + 192];
  v29 = v28 * (v27 >> 11);
  if ( v8 < v29 )
  {
    rep3 = rep2;
    rep2 = rep1;
    rep1 = rep0;
    v30 = v28 * (v27 >> 11);
    p[state + 192] = v28 + ((2048 - v28) >> 5);
    v31 = p + 818;
    v32 = state < 7 ? 0 : 3;
    goto LABEL_72;
  }
  v33 = v27 - v29;
  v8 -= v29;
  p[state + 192] = v28 - (v28 >> 5);
  if ( v33 < 0x1000000 )
  {
    if ( Buffer != BufferLim )
    {
      v33 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
      goto LABEL_50;
    }
    return 1;
  }
LABEL_50:
  v34 = p[state + 204];
  v35 = v34 * (v33 >> 11);
  if ( v8 >= v35 )
  {
    v41 = v33 - v35;
    v8 -= v35;
    p[state + 204] = v34 - (v34 >> 5);
    if ( v41 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v41 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v42 = p[state + 216];
    v43 = v42 * (v41 >> 11);
    if ( v8 >= v43 )
    {
      v46 = v41 - v43;
      v8 -= v43;
      p[state + 216] = v42 - (v42 >> 5);
      if ( v46 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v46 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v47 = p[state + 228];
      v48 = v47 * (v46 >> 11);
      if ( v8 >= v48 )
      {
        v30 = v46 - v48;
        v8 -= v48;
        p[state + 228] = v47 - (v47 >> 5);
        v45 = rep3;
        rep3 = rep2;
      }
      else
      {
        v30 = v47 * (v46 >> 11);
        v49 = v47 + ((2048 - v47) >> 5);
        v45 = rep2;
        p[state + 228] = v49;
      }
      rep2 = rep1;
    }
    else
    {
      v30 = v42 * (v41 >> 11);
      v44 = v42 + ((2048 - v42) >> 5);
      v45 = rep1;
      p[state + 216] = v44;
    }
    rep1 = rep0;
    rep0 = v45;
  }
  else
  {
    p[state + 204] = v34 + ((2048 - v34) >> 5);
    v36 = v34 * (v33 >> 11);
    v37 = &p[16 * state + 240 + offset];
    if ( v35 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v36 = v35 << 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v38 = *v37;
    v39 = *v37 * (v36 >> 11);
    if ( v8 < v39 )
    {
      v14 = *v37 * (v36 >> 11);
      *v37 = v38 + ((2048 - v38) >> 5);
      if ( nowPos != 0 )
      {
        v40 = nowPos - rep0;
        ++nowPos;
        state = 2 * (state >= 7) + 9;
        LOBYTE(v40) = outStream[v40];
        outStream[nowPos - 1] = v40;
        HIBYTE(pCallbackFunc) = v40;
        goto LABEL_37;
      }
      return 1;
    }
    v30 = v36 - v39;
    v8 -= v39;
    *v37 = v38 - (v38 >> 5);
  }
  v32 = state >= 7 ? 11 : 8;
  v31 = p + 1332;
LABEL_72:
  state = v32;
  if ( v30 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    v30 <<= 8;
    v8 = *Buffer++ | (v8 << 8);
  }
  v50 = *v31;
  v51 = *v31 * (v30 >> 11);
  if ( v8 >= v51 )
  {
    v53 = v30 - v51;
    v8 -= v51;
    *v31 = v50 - (v50 >> 5);
    if ( v53 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v53 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v54 = v31[1];
    v55 = v54 * (v53 >> 11);
    if ( v8 >= v55 )
    {
      v14 = v53 - v55;
      v8 -= v55;
      v31[1] = v54 - (v54 >> 5);
      v52 = (int)(v31 + 258);
      offsetb = 16;
      numDirectBitsa = 8;
    }
    else
    {
      v14 = v54 * (v53 >> 11);
      v31[1] = v54 + ((2048 - v54) >> 5);
      v52 = (int)&v31[8 * offset + 130];
      offsetb = 8;
      numDirectBitsa = 3;
    }
  }
  else
  {
    v14 = *v31 * (v30 >> 11);
    *v31 = v50 + ((2048 - v50) >> 5);
    v52 = (int)&v31[8 * offset + 2];
    offsetb = 0;
    numDirectBitsa = 3;
  }
  ib = numDirectBitsa;
  v56 = 1;
  do
  {
    if ( v14 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v14 <<= 8;
      v8 = *Buffer++ | (v8 << 8);
    }
    v57 = *(_DWORD *)(v52 + 4 * v56);
    v58 = v57 * (v14 >> 11);
    if ( v8 >= v58 )
    {
      v14 -= v58;
      v8 -= v58;
      *(_DWORD *)(v52 + 4 * v56) = v57 - (v57 >> 5);
      v56 = 2 * v56 + 1;
    }
    else
    {
      v14 = v57 * (v14 >> 11);
      *(_DWORD *)(v52 + 4 * v56) = v57 + ((2048 - v57) >> 5);
      v56 *= 2;
    }
    v59 = 1;
    --ib;
  }
  while ( ib != 0 );
  v60 = offsetb - (1 << numDirectBitsa) + v56;
  ic = v60;
  if ( state < 4 )
  {
    state += 7;
    if ( v60 >= 4 )
      v60 = 3;
    v61 = (int)&p[64 * v60 + 432];
    for ( numDirectBitsb = 6; numDirectBitsb != 0; --numDirectBitsb )
    {
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v8 = *Buffer++ | (v8 << 8);
      }
      v62 = *(_DWORD *)(v61 + 4 * v59);
      v63 = v62 * (v14 >> 11);
      if ( v8 >= v63 )
      {
        v14 -= v63;
        v8 -= v63;
        *(_DWORD *)(v61 + 4 * v59) = v62 - (v62 >> 5);
        v59 = 2 * v59 + 1;
      }
      else
      {
        v14 = v62 * (v14 >> 11);
        *(_DWORD *)(v61 + 4 * v59) = v62 + ((2048 - v62) >> 5);
        v59 *= 2;
      }
    }
    v64 = v59 - 64;
    if ( v64 < 4 )
    {
      rep0a = v64;
    }
    else
    {
      v65 = (v64 >> 1) - 1;
      v66 = v64 & 1 | 2;
      numDirectBitsc = v65;
      if ( v64 >= 14 )
      {
        v68 = Buffer;
        v69 = v65 - 4;
        do
        {
          if ( v14 < 0x1000000 )
          {
            if ( v68 == BufferLim )
              return 1;
            v14 <<= 8;
            v8 = *v68++ | (v8 << 8);
            Buffer = v68;
          }
          v14 >>= 1;
          v66 *= 2;
          rep0b = v66;
          if ( v8 >= v14 )
          {
            v8 -= v14;
            v66 |= 1u;
            rep0b = v66;
          }
          --v69;
        }
        while ( v69 != 0 );
        v67 = (int)(p + 802);
        rep0a = 16 * rep0b;
        numDirectBitsc = 4;
      }
      else
      {
        rep0a = (v64 & 1 | 2) << v65;
        v67 = (int)&p[rep0a - v64 + 687];
      }
      v70 = 1;
      offsetc = 1;
      do
      {
        if ( v14 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v14 <<= 8;
          v8 = *Buffer++ | (v8 << 8);
        }
        v71 = *(_DWORD *)(v67 + 4 * v70);
        v72 = v71 * (v14 >> 11);
        if ( v8 >= v72 )
        {
          v14 -= v72;
          v8 -= v72;
          *(_DWORD *)(v67 + 4 * v70) = v71 - (v71 >> 5);
          rep0a |= offsetc;
          v70 = 2 * v70 + 1;
        }
        else
        {
          v14 = v71 * (v14 >> 11);
          *(_DWORD *)(v67 + 4 * v70) = v71 + ((2048 - v71) >> 5);
          v70 *= 2;
        }
        offsetc *= 2;
        --numDirectBitsc;
      }
      while ( numDirectBitsc != 0 );
    }
    rep0 = rep0a + 1;
    if ( rep0 == 0 )
      goto LABEL_38;
    v60 = ic;
  }
  v73 = nowPos;
  v74 = v60 + 2;
  if ( rep0 > nowPos )
    return 1;
  for ( m = &outStream[-rep0]; ; m = &outStream[-rep0] )
  {
    v76 = m[v73];
    outStream[v73++] = v76;
    --v74;
    HIBYTE(pCallbackFunc) = v76;
    nowPos = v73;
    if ( v74 == 0 )
      goto LABEL_37;
    if ( v73 >= outSize )
      break;
  }
LABEL_38:
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_131:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = nowPos;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002E10
// Name: public: bool CLZMA::IsCompressed(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLZMA::IsCompressed(CLZMA *this, unsigned __int8 *pInput)
{
  return pInput != nullptr && *(_DWORD *)pInput == 1095588428;
}

//------------------------------------------------------------------------------
// Address: 0x10002E30
// Name: public: unsigned int CLZMA::GetActualSize(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZMA::GetActualSize(CLZMA *this, unsigned __int8 *pInput)
{
  if ( pInput != nullptr && *(_DWORD *)pInput == 1095588428 )
    return *((_DWORD *)pInput + 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002E50
// Name: public: unsigned int CLZMA::Uncompress(unsigned char __near *,unsigned char __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZMA::Uncompress(
        CLZMA *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        void (__cdecl *pCallback)())
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ebx
  unsigned int *v6; // edi
  int v7; // esi
  unsigned __int8 *result; // eax
  unsigned int v9; // [esp-1Ch] [ebp-34h]
  _CLzmaDecoderState state; // [esp+8h] [ebp-10h] BYREF

  v4 = pInput;
  if ( pInput == nullptr )
    return nullptr;
  if ( *(_DWORD *)pInput != 1095588428 )
    return nullptr;
  v5 = *((unsigned __int8 **)pInput + 1);
  if ( v5 == nullptr )
    return nullptr;
  LzmaDecodeProperties(propsRes: &state.Properties, propsData: pInput + 12, size: 5);
  v6 = (unsigned int *)_g_pMemAlloc->Alloc_2(
                         this: _g_pMemAlloc,
                         a2: 4 * (768 << (LOBYTE(state.Properties.lp) + LOBYTE(state.Properties.lc))) + 7384);
  v9 = *((_DWORD *)v4 + 2);
  state.Probs = v6;
  v7 = LzmaDecode(
         vs: &state,
         inStream: v4 + 17,
         inSize: v9,
         inSizeProcessed: (unsigned int *)&pCallback,
         outStream: pOutput,
         outSize: (unsigned int)v5,
         outSizeProcessed: (unsigned int *)&pInput,
         pCallbackFunc: pCallback);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  if ( v7 != 0 )
    return nullptr;
  result = pInput;
  if ( pInput != v5 )
    return nullptr;
  return result;
}

} // namespace scenefilecache

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x1003F3B0
// Name: int LzmaDecodeProperties(struct _CLzmaProperties __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeProperties(_CLzmaProperties *propsRes, unsigned __int8 *propsData, int size)
{
  unsigned __int8 v4; // cl
  unsigned int v5; // eax
  int v6; // edx
  unsigned int v7; // eax
  int v8; // edx

  if ( size < 5 )
    return 1;
  v4 = *propsData;
  if ( *propsData >= 0xE1u )
    return 1;
  propsRes->pb = 0;
  if ( v4 >= 0x2Du )
  {
    v5 = v4 / 0x2Du;
    v6 = v5;
    do
    {
      v4 -= 45;
      --v5;
    }
    while ( v5 != 0 );
    propsRes->pb = v6;
  }
  propsRes->lp = 0;
  if ( v4 >= 9u )
  {
    v7 = v4 / 9u;
    v8 = v7;
    do
    {
      v4 -= 9;
      --v7;
    }
    while ( v7 != 0 );
    propsRes->lp = v8;
  }
  propsRes->lc = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F440
// Name: int LzmaDecodeWithCallback(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecodeWithCallback(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        const unsigned __int8 *inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int *Probs; // edi
  int v9; // edx
  int v10; // ecx
  unsigned __int8 v11; // bl
  const unsigned __int8 *v12; // eax
  unsigned int v13; // edi
  unsigned int v14; // esi
  int j; // ecx
  const unsigned __int8 *v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // edx
  int v19; // eax
  unsigned int *v20; // ebx
  unsigned int v21; // ecx
  unsigned int v22; // edx
  const unsigned __int8 *v23; // ebp
  unsigned int v24; // ecx
  unsigned int v25; // edx
  int v27; // eax
  unsigned int v28; // esi
  unsigned int v29; // eax
  unsigned int v30; // ecx
  unsigned int v31; // esi
  int v32; // ebx
  unsigned int v33; // ecx
  unsigned int v34; // eax
  unsigned int *v35; // eax
  const unsigned __int8 *v36; // ebx
  unsigned int v37; // esi
  unsigned int v38; // ecx
  unsigned int v39; // eax
  unsigned int v40; // esi
  unsigned int v41; // eax
  unsigned int v42; // ecx
  unsigned int v43; // ecx
  unsigned int v44; // esi
  unsigned int v45; // eax
  unsigned int v46; // ecx
  unsigned int v47; // ecx
  unsigned int v48; // eax
  unsigned int v49; // esi
  unsigned int v50; // eax
  unsigned int v51; // ecx
  unsigned int v52; // ecx
  unsigned int v53; // ecx
  unsigned int v54; // edx
  int v55; // ebp
  int v56; // ecx
  unsigned int v57; // esi
  unsigned int v58; // ecx
  unsigned int v59; // edx
  int v60; // ebx
  unsigned int v61; // eax
  unsigned int v62; // edx
  int v63; // ebx
  int v64; // ebp
  int v65; // ebx
  int v66; // eax
  unsigned int v67; // ecx
  unsigned int v68; // edx
  int v69; // eax
  int v70; // ebx
  int v71; // ebp
  int v72; // ecx
  int v73; // ebx
  int v74; // ecx
  const unsigned __int8 *v75; // eax
  int v76; // ecx
  int v77; // ecx
  unsigned int v78; // eax
  unsigned int v79; // edx
  unsigned __int8 *v80; // ecx
  unsigned int state; // [esp+10h] [ebp-30h]
  int i; // [esp+14h] [ebp-2Ch]
  unsigned int *numDirectBits; // [esp+18h] [ebp-28h]
  int numDirectBitsa; // [esp+18h] [ebp-28h]
  unsigned int *numDirectBitsb; // [esp+18h] [ebp-28h]
  int numDirectBitsc; // [esp+18h] [ebp-28h]
  int numDirectBitsd; // [esp+18h] [ebp-28h]
  int numDirectBitse; // [esp+18h] [ebp-28h]
  unsigned int p; // [esp+1Ch] [ebp-24h]
  int pa; // [esp+1Ch] [ebp-24h]
  unsigned int rep2; // [esp+20h] [ebp-20h]
  unsigned int rep1; // [esp+24h] [ebp-1Ch]
  unsigned int rep3; // [esp+28h] [ebp-18h]
  int offset; // [esp+2Ch] [ebp-14h]
  __int16 lc; // [esp+30h] [ebp-10h]
  int lca; // [esp+30h] [ebp-10h]
  int lcb; // [esp+30h] [ebp-10h]
  int lcc; // [esp+30h] [ebp-10h]
  char posStateMask; // [esp+34h] [ebp-Ch]
  unsigned int literalPosMask; // [esp+38h] [ebp-8h]
  int v101; // [esp+3Ch] [ebp-4h]
  const unsigned __int8 *Buffer; // [esp+44h] [ebp+4h]
  const unsigned __int8 *BufferLim; // [esp+4Ch] [ebp+Ch]

  literalPosMask = (1 << vs->Properties.pb) - 1;
  Probs = vs->Probs;
  v101 = (1 << vs->Properties.lp) - 1;
  v9 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v10 = v9 + vs->Properties.lp;
  v11 = 0;
  rep2 = (unsigned int)Probs;
  state = 0;
  posStateMask = v9;
  i = 0;
  p = 1;
  rep3 = 1;
  rep1 = 1;
  offset = 1;
  if ( 768 << v10 != -1846 )
    memset32(Probs, 1024, (768 << v10) + 1846);
  v12 = inStream;
  BufferLim = &inSize[(_DWORD)inStream];
  v13 = 0;
  v14 = -1;
  for ( j = 0; j < 5; ++j )
  {
    if ( v12 == BufferLim )
      return 1;
    v13 = *v12++ | (v13 << 8);
  }
  Buffer = v12;
  if ( outSize == 0 )
    goto LABEL_42;
  do
  {
    numDirectBits = (unsigned int *)(rep2 + 4 * ((state & literalPosMask) + 16 * i));
    v16 = Buffer;
    if ( v14 < 0x1000000 )
    {
      if ( Buffer == BufferLim )
        return 1;
      v14 <<= 8;
      v13 = *Buffer | (v13 << 8);
      v16 = ++Buffer;
    }
    v17 = *numDirectBits;
    v18 = *numDirectBits * (v14 >> 11);
    if ( v13 >= v18 )
    {
      v28 = v14 - v18;
      v13 -= v18;
      *numDirectBits = v17 - (v17 >> 5);
      if ( v28 < 0x1000000 )
      {
        if ( v16 == BufferLim )
          return 1;
        v28 <<= 8;
        v13 = *v16 | (v13 << 8);
        Buffer = v16 + 1;
      }
      v29 = *(_DWORD *)(rep2 + 4 * i + 768);
      v30 = v29 * (v28 >> 11);
      if ( v13 >= v30 )
      {
        v36 = Buffer;
        v37 = v28 - v30;
        v13 -= v30;
        *(_DWORD *)(rep2 + 4 * i + 768) = v29 - (v29 >> 5);
        if ( v37 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v37 <<= 8;
          v13 = *Buffer | (v13 << 8);
          v36 = ++Buffer;
        }
        v38 = *(_DWORD *)(rep2 + 4 * i + 816);
        v39 = v38 * (v37 >> 11);
        if ( v13 >= v39 )
        {
          v44 = v37 - v39;
          v13 -= v39;
          *(_DWORD *)(rep2 + 4 * i + 816) = v38 - (v38 >> 5);
          if ( v44 < 0x1000000 )
          {
            if ( v36 == BufferLim )
              return 1;
            v44 <<= 8;
            v13 = *v36++ | (v13 << 8);
            Buffer = v36;
          }
          v45 = *(_DWORD *)(rep2 + 4 * i + 864);
          v46 = v45 * (v44 >> 11);
          if ( v13 >= v46 )
          {
            v49 = v44 - v46;
            v13 -= v46;
            *(_DWORD *)(rep2 + 4 * i + 864) = v45 - (v45 >> 5);
            if ( v49 < 0x1000000 )
            {
              if ( v36 == BufferLim )
                return 1;
              v49 <<= 8;
              v13 = *v36 | (v13 << 8);
              Buffer = v36 + 1;
            }
            v50 = *(_DWORD *)(rep2 + 4 * i + 912);
            v51 = v50 * (v49 >> 11);
            if ( v13 >= v51 )
            {
              v31 = v49 - v51;
              v13 -= v51;
              *(_DWORD *)(rep2 + 4 * i + 912) = v50 - (v50 >> 5);
              v48 = offset;
              offset = rep1;
            }
            else
            {
              v31 = v50 * (v49 >> 11);
              v52 = v50 + ((2048 - v50) >> 5);
              v48 = rep1;
              *(_DWORD *)(rep2 + 4 * i + 912) = v52;
            }
            rep1 = rep3;
          }
          else
          {
            v31 = v45 * (v44 >> 11);
            v47 = v45 + ((2048 - v45) >> 5);
            v48 = rep3;
            *(_DWORD *)(rep2 + 4 * i + 864) = v47;
          }
          v32 = state & literalPosMask;
          rep3 = p;
          p = v48;
        }
        else
        {
          *(_DWORD *)(rep2 + 4 * i + 816) = v38 + ((2048 - v38) >> 5);
          v32 = state & literalPosMask;
          v40 = v38 * (v37 >> 11);
          numDirectBitsb = (unsigned int *)(rep2 + 4 * ((state & literalPosMask) + 16 * (i + 15)));
          if ( v39 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v40 = v39 << 8;
            v13 = *Buffer++ | (v13 << 8);
          }
          v41 = *numDirectBitsb;
          v42 = *numDirectBitsb * (v40 >> 11);
          if ( v13 < v42 )
          {
            v14 = *numDirectBitsb * (v40 >> 11);
            *numDirectBitsb = v41 + ((2048 - v41) >> 5);
            if ( state != 0 )
            {
              i = 2 * (i >= 7) + 9;
              v43 = state + 1;
              v11 = outStream[state - p];
              outStream[v43 - 1] = v11;
              ++state;
              if ( v43 % 0x7A120 == 0 )
                pCallbackFunc();
              continue;
            }
            return 1;
          }
          v31 = v40 - v42;
          v13 -= v42;
          *numDirectBitsb = v41 - (v41 >> 5);
        }
        i = i >= 7 ? 11 : 8;
        v35 = (unsigned int *)(rep2 + 5328);
      }
      else
      {
        v31 = v29 * (v28 >> 11);
        v32 = state & literalPosMask;
        v33 = v29 + ((2048 - v29) >> 5);
        v34 = rep1;
        *(_DWORD *)(rep2 + 4 * i + 768) = v33;
        rep1 = rep3;
        offset = v34;
        rep3 = p;
        v35 = (unsigned int *)(rep2 + 3272);
        i = i < 7 ? 0 : 3;
      }
      if ( v31 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v31 <<= 8;
        v13 = *Buffer++ | (v13 << 8);
      }
      v53 = *v35;
      v54 = *v35 * (v31 >> 11);
      if ( v13 >= v54 )
      {
        v57 = v31 - v54;
        v13 -= v54;
        *v35 = v53 - (v53 >> 5);
        if ( v57 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v57 <<= 8;
          v13 = *Buffer++ | (v13 << 8);
        }
        v58 = v35[1];
        v59 = v58 * (v57 >> 11);
        if ( v13 >= v59 )
        {
          v14 = v57 - v59;
          v13 -= v59;
          v35[1] = v58 - (v58 >> 5);
          v55 = (int)(v35 + 258);
          lca = 16;
          v56 = 8;
        }
        else
        {
          v14 = v58 * (v57 >> 11);
          v35[1] = v58 + ((2048 - v58) >> 5);
          v55 = (int)&v35[8 * v32 + 130];
          lca = 8;
          v56 = 3;
        }
      }
      else
      {
        v14 = *v35 * (v31 >> 11);
        *v35 = v53 + ((2048 - v53) >> 5);
        v55 = (int)&v35[8 * v32 + 2];
        lca = 0;
        v56 = 3;
      }
      numDirectBitsc = v56;
      v60 = 1;
      do
      {
        if ( v14 < 0x1000000 )
        {
          if ( Buffer == BufferLim )
            return 1;
          v14 <<= 8;
          v13 = *Buffer++ | (v13 << 8);
        }
        v61 = *(_DWORD *)(v55 + 4 * v60);
        v62 = v61 * (v14 >> 11);
        if ( v13 >= v62 )
        {
          v14 -= v62;
          v13 -= v62;
          *(_DWORD *)(v55 + 4 * v60) = v61 - (v61 >> 5);
          v60 = 2 * v60 + 1;
        }
        else
        {
          v14 = v61 * (v14 >> 11);
          *(_DWORD *)(v55 + 4 * v60) = v61 + ((2048 - v61) >> 5);
          v60 *= 2;
        }
        --numDirectBitsc;
      }
      while ( numDirectBitsc != 0 );
      v63 = lca - (1 << v56) + v60;
      numDirectBitsd = v63;
      if ( i < 4 )
      {
        i += 7;
        if ( v63 >= 4 )
          v63 = 3;
        v64 = (v63 << 8) + rep2 + 1728;
        v65 = 6;
        v66 = 1;
        do
        {
          if ( v14 < 0x1000000 )
          {
            if ( Buffer == BufferLim )
              return 1;
            v14 <<= 8;
            v13 = *Buffer++ | (v13 << 8);
          }
          v67 = *(_DWORD *)(v64 + 4 * v66);
          v68 = v67 * (v14 >> 11);
          if ( v13 >= v68 )
          {
            v14 -= v68;
            v13 -= v68;
            *(_DWORD *)(v64 + 4 * v66) = v67 - (v67 >> 5);
            v66 = 2 * v66 + 1;
          }
          else
          {
            v14 = v67 * (v14 >> 11);
            *(_DWORD *)(v64 + 4 * v66) = v67 + ((2048 - v67) >> 5);
            v66 *= 2;
          }
          --v65;
        }
        while ( v65 != 0 );
        v69 = v66 - 64;
        v70 = v69;
        if ( v69 >= 4 )
        {
          v71 = 1;
          v72 = (v69 >> 1) - 1;
          v73 = v69 & 1 | 2;
          pa = v72;
          if ( v69 < 14 )
          {
            v70 = v73 << v72;
            lcb = 1;
            v74 = v70 - v69;
            v75 = Buffer;
            v76 = rep2 + 4 * v74 + 2748;
            goto LABEL_117;
          }
          v75 = Buffer;
          v77 = v72 - 4;
          do
          {
            if ( v14 < 0x1000000 )
            {
              if ( v75 == BufferLim )
                return 1;
              v14 <<= 8;
              v13 = *v75++ | (v13 << 8);
              Buffer = v75;
            }
            v14 >>= 1;
            v73 *= 2;
            if ( v13 >= v14 )
            {
              v13 -= v14;
              v73 |= 1u;
            }
            --v77;
          }
          while ( v77 != 0 );
          v76 = rep2 + 3208;
          v70 = 16 * v73;
          pa = 4;
          lcb = 1;
          while ( 1 )
          {
LABEL_117:
            if ( v14 < 0x1000000 )
            {
              if ( v75 == BufferLim )
                return 1;
              v14 <<= 8;
              v13 = *v75 | (v13 << 8);
              Buffer = v75 + 1;
            }
            v78 = *(_DWORD *)(v76 + 4 * v71);
            v79 = v78 * (v14 >> 11);
            if ( v13 >= v79 )
            {
              v14 -= v79;
              v13 -= v79;
              v70 |= lcb;
              *(_DWORD *)(v76 + 4 * v71) = v78 - (v78 >> 5);
              v71 = 2 * v71 + 1;
            }
            else
            {
              v14 = v78 * (v14 >> 11);
              *(_DWORD *)(v76 + 4 * v71) = v78 + ((2048 - v78) >> 5);
              v71 *= 2;
            }
            lcb *= 2;
            if ( --pa == 0 )
              break;
            v75 = Buffer;
          }
        }
        p = v70 + 1;
        if ( v70 == -1 )
          break;
        v63 = numDirectBitsd;
      }
      numDirectBitse = v63 + 2;
      if ( p <= state )
      {
        v80 = &outStream[state - p];
        do
        {
          v11 = *v80;
          --numDirectBitse;
          outStream[state++] = *v80++;
          lcc = (int)v80;
          if ( state % 0x7A120 == 0 )
          {
            pCallbackFunc();
            v80 = (unsigned __int8 *)lcc;
          }
          if ( numDirectBitse == 0 )
            goto LABEL_38;
        }
        while ( state < outSize );
        break;
      }
      return 1;
    }
    v14 = *numDirectBits * (v14 >> 11);
    *numDirectBits = v17 + ((2048 - v17) >> 5);
    v19 = 1;
    numDirectBitsa = 3072 * (((state & v101) << posStateMask) + (v11 >> (8 - posStateMask))) + rep2 + 7384;
    if ( i < 7 )
    {
LABEL_19:
      v23 = Buffer;
      do
      {
        if ( v14 < 0x1000000 )
        {
          if ( v23 == BufferLim )
            return 1;
          v14 <<= 8;
          v13 = *v23++ | (v13 << 8);
          Buffer = v23;
        }
        v24 = *(_DWORD *)(numDirectBitsa + 4 * v19);
        v25 = v24 * (v14 >> 11);
        if ( v13 >= v25 )
        {
          v14 -= v25;
          v13 -= v25;
          *(_DWORD *)(numDirectBitsa + 4 * v19) = v24 - (v24 >> 5);
          v19 = 2 * v19 + 1;
        }
        else
        {
          v14 = v24 * (v14 >> 11);
          *(_DWORD *)(numDirectBitsa + 4 * v19) = v24 + ((2048 - v24) >> 5);
          v19 *= 2;
        }
      }
      while ( v19 < 256 );
      goto LABEL_31;
    }
    lc = outStream[state - p];
    while ( 1 )
    {
      lc *= 2;
      v20 = (unsigned int *)(numDirectBitsa + 4 * (v19 + (lc & 0x100)) + 1024);
      if ( v14 < 0x1000000 )
      {
        if ( Buffer == BufferLim )
          return 1;
        v14 <<= 8;
        v13 = *Buffer++ | (v13 << 8);
      }
      v21 = *v20;
      v22 = *v20 * (v14 >> 11);
      if ( v13 >= v22 )
        break;
      v14 = *v20 * (v14 >> 11);
      v19 *= 2;
      *v20 = v21 + ((2048 - v21) >> 5);
      if ( (lc & 0x100) != 0 )
        goto LABEL_18;
LABEL_27:
      if ( v19 >= 256 )
        goto LABEL_31;
    }
    v14 -= v22;
    v13 -= v22;
    *v20 = v21 - (v21 >> 5);
    v19 = 2 * v19 + 1;
    if ( (lc & 0x100) != 0 )
      goto LABEL_27;
LABEL_18:
    if ( v19 < 256 )
      goto LABEL_19;
LABEL_31:
    outStream[state] = v19;
    v11 = v19;
    if ( ++state % 0x7A120 == 0 )
      pCallbackFunc();
    if ( i >= 4 )
    {
      if ( i >= 10 )
        v27 = i - 6;
      else
        v27 = i - 3;
      i = v27;
    }
    else
    {
      i = 0;
    }
LABEL_38:
    ;
  }
  while ( state < outSize );
  if ( v14 < 0x1000000 )
  {
    if ( Buffer == BufferLim )
      return 1;
    ++Buffer;
  }
LABEL_42:
  *inSizeProcessed = Buffer - inStream;
  *outSizeProcessed = state;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003FE10
// Name: int LzmaDecode(struct _CLzmaDecoderState __near *,unsigned char const __near *,unsigned int,unsigned int __near *,unsigned char __near *,unsigned int,unsigned int __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
int __cdecl LzmaDecode(
        _CLzmaDecoderState *vs,
        const unsigned __int8 *inStream,
        unsigned int inSize,
        unsigned int *inSizeProcessed,
        unsigned __int8 *outStream,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        void (__cdecl *pCallbackFunc)())
{
  unsigned int v8; // esi
  unsigned int *Probs; // edi
  int v11; // edx
  int v12; // ecx
  const unsigned __int8 *v13; // ecx
  unsigned int v14; // eax
  int j; // edx
  const unsigned __int8 *v16; // edx
  unsigned int v17; // ecx
  unsigned int v18; // edi
  int v19; // edx
  unsigned int *v20; // ebp
  unsigned int v21; // ecx
  unsigned int v22; // edi
  unsigned int v23; // ecx
  unsigned int v24; // edi
  signed int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // ecx
  unsigned int *v32; // ecx
  const unsigned __int8 *v33; // edi
  unsigned int v34; // eax
  unsigned int v35; // edx
  unsigned int v36; // ecx
  unsigned int v37; // eax
  unsigned int *v38; // edi
  unsigned int v39; // ecx
  unsigned int v40; // edx
  unsigned __int8 v41; // dl
  unsigned int v42; // eax
  unsigned int v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // edx
  unsigned int v46; // ecx
  unsigned int v47; // eax
  unsigned int v48; // ecx
  unsigned int v49; // edx
  unsigned int v50; // edx
  const unsigned __int8 *v51; // ebp
  unsigned int v52; // edx
  unsigned int v53; // ebx
  int v54; // ecx
  int v55; // ebx
  unsigned int v56; // eax
  unsigned int v57; // edx
  unsigned int v58; // edi
  int v59; // ebp
  unsigned int v60; // edx
  unsigned int v61; // edi
  int v62; // ebp
  int v63; // ebx
  const unsigned __int8 *v64; // ebp
  int v65; // ebx
  int v66; // edx
  unsigned int v67; // ecx
  unsigned int v68; // edi
  int v69; // edx
  int v70; // ebp
  int v71; // ecx
  int v72; // ebp
  int v73; // ecx
  const unsigned __int8 *v74; // edx
  int v75; // ecx
  int v76; // ebx
  unsigned int v77; // edx
  unsigned int v78; // edi
  unsigned int v79; // edi
  int v80; // ebp
  unsigned __int8 *v81; // ecx
  unsigned __int8 v82; // dl
  const unsigned __int8 *BufferLim; // [esp+4h] [ebp-38h]
  const unsigned __int8 *nowPos; // [esp+8h] [ebp-34h]
  unsigned int state; // [esp+Ch] [ebp-30h]
  signed int rep0; // [esp+10h] [ebp-2Ch]
  unsigned int prob; // [esp+14h] [ebp-28h]
  unsigned int *rep2; // [esp+18h] [ebp-24h]
  unsigned int rep2a; // [esp+18h] [ebp-24h]
  unsigned int rep2b; // [esp+18h] [ebp-24h]
  unsigned int rep1; // [esp+1Ch] [ebp-20h]
  int p; // [esp+20h] [ebp-1Ch]
  int numDirectBits; // [esp+24h] [ebp-18h]
  unsigned int rep3; // [esp+28h] [ebp-14h]
  unsigned int rep3a; // [esp+28h] [ebp-14h]
  unsigned int rep3b; // [esp+28h] [ebp-14h]
  int lc; // [esp+2Ch] [ebp-10h]
  char posStateMask; // [esp+30h] [ebp-Ch]
  unsigned int literalPosMask; // [esp+34h] [ebp-8h]
  int v100; // [esp+38h] [ebp-4h]
  unsigned __int8 i; // [esp+5Ch] [ebp+20h]
  __int16 ia; // [esp+5Ch] [ebp+20h]
  int ib; // [esp+5Ch] [ebp+20h]
  int ic; // [esp+5Ch] [ebp+20h]
  int id; // [esp+5Ch] [ebp+20h]

  v8 = 0;
  if ( pCallbackFunc != nullptr )
    return LzmaDecodeWithCallback(
             vs,
             inStream,
             (const unsigned __int8 *)inSize,
             inSizeProcessed,
             outStream,
             outSize,
             outSizeProcessed,
             pCallbackFunc);
  Probs = vs->Probs;
  literalPosMask = (1 << vs->Properties.pb) - 1;
  numDirectBits = (int)Probs;
  state = 0;
  v100 = (1 << vs->Properties.lp) - 1;
  v11 = vs->Properties.lc;
  *inSizeProcessed = 0;
  *outSizeProcessed = 0;
  v12 = v11 + vs->Properties.lp;
  i = 0;
  posStateMask = v11;
  rep0 = 0;
  prob = 1;
  p = 1;
  rep1 = 1;
  lc = 1;
  if ( 768 << v12 != -1846 )
    memset32(Probs, 1024, (768 << v12) + 1846);
  v13 = inStream;
  v14 = -1;
  nowPos = &inStream[inSize];
  for ( j = 0; j < 5; ++j )
  {
    if ( v13 == &inStream[inSize] )
      return 1;
    v8 = *v13++ | (v8 << 8);
  }
  BufferLim = v13;
  if ( outSize == 0 )
    goto LABEL_129;
LABEL_9:
  rep3 = state & literalPosMask;
  v16 = BufferLim;
  rep2 = (unsigned int *)(numDirectBits + 4 * ((state & literalPosMask) + 16 * rep0));
  if ( v14 < 0x1000000 )
  {
    if ( BufferLim == nowPos )
      return 1;
    v14 <<= 8;
    v8 = *BufferLim | (v8 << 8);
    v16 = ++BufferLim;
  }
  v17 = *rep2;
  v18 = *rep2 * (v14 >> 11);
  if ( v8 < v18 )
  {
    v14 = *rep2 * (v14 >> 11);
    *rep2 = v17 + ((2048 - v17) >> 5);
    v19 = 1;
    rep2a = 3072 * (((state & v100) << posStateMask) + (i >> (8 - posStateMask))) + numDirectBits + 7384;
    if ( rep0 < 7 )
      goto LABEL_21;
    ia = outStream[state - prob];
    while ( 1 )
    {
      ia *= 2;
      v20 = (unsigned int *)(rep2a + 4 * ((ia & 0x100) + v19) + 1024);
      if ( v14 < 0x1000000 )
      {
        if ( BufferLim == nowPos )
          return 1;
        v14 <<= 8;
        v8 = *BufferLim++ | (v8 << 8);
      }
      v21 = *v20;
      v22 = *v20 * (v14 >> 11);
      if ( v8 >= v22 )
      {
        v14 -= v22;
        v8 -= v22;
        *v20 = v21 - (v21 >> 5);
        v19 = 2 * v19 + 1;
        if ( (ia & 0x100) == 0 )
        {
LABEL_20:
          while ( v19 < 256 )
          {
LABEL_21:
            if ( v14 < 0x1000000 )
            {
              if ( BufferLim == nowPos )
                return 1;
              v14 <<= 8;
              v8 = *BufferLim++ | (v8 << 8);
            }
            v23 = *(_DWORD *)(rep2a + 4 * v19);
            v24 = v23 * (v14 >> 11);
            if ( v8 >= v24 )
            {
              v14 -= v24;
              v8 -= v24;
              *(_DWORD *)(rep2a + 4 * v19) = v23 - (v23 >> 5);
              v19 = 2 * v19 + 1;
            }
            else
            {
              v14 = v23 * (v14 >> 11);
              *(_DWORD *)(rep2a + 4 * v19) = v23 + ((2048 - v23) >> 5);
              v19 *= 2;
            }
          }
LABEL_32:
          outStream[state++] = v19;
          i = v19;
          if ( rep0 >= 4 )
          {
            if ( rep0 >= 10 )
              v25 = rep0 - 6;
            else
              v25 = rep0 - 3;
            rep0 = v25;
          }
          else
          {
            rep0 = 0;
          }
LABEL_37:
          if ( state >= outSize )
            goto LABEL_38;
          goto LABEL_9;
        }
      }
      else
      {
        v14 = *v20 * (v14 >> 11);
        v19 *= 2;
        *v20 = v21 + ((2048 - v21) >> 5);
        if ( (ia & 0x100) != 0 )
          goto LABEL_20;
      }
      if ( v19 >= 256 )
        goto LABEL_32;
    }
  }
  v26 = v14 - v18;
  v8 -= v18;
  *rep2 = v17 - (v17 >> 5);
  if ( v26 < 0x1000000 )
  {
    if ( v16 == nowPos )
      return 1;
    v26 <<= 8;
    v8 = *v16 | (v8 << 8);
    BufferLim = v16 + 1;
  }
  v27 = *(_DWORD *)(numDirectBits + 4 * rep0 + 768);
  v28 = v27 * (v26 >> 11);
  if ( v8 < v28 )
  {
    v29 = v27 * (v26 >> 11);
    v30 = v27 + ((2048 - v27) >> 5);
    v31 = rep1;
    *(_DWORD *)(numDirectBits + 4 * rep0 + 768) = v30;
    rep1 = p;
    lc = v31;
    p = prob;
    v32 = (unsigned int *)(numDirectBits + 3272);
    rep0 = rep0 < 7 ? 0 : 3;
    goto LABEL_72;
  }
  v33 = BufferLim;
  v34 = v26 - v28;
  v8 -= v28;
  *(_DWORD *)(numDirectBits + 4 * rep0 + 768) = v27 - (v27 >> 5);
  if ( v34 < 0x1000000 )
  {
    if ( BufferLim != nowPos )
    {
      v34 <<= 8;
      v8 = *BufferLim | (v8 << 8);
      v33 = ++BufferLim;
      goto LABEL_50;
    }
    return 1;
  }
LABEL_50:
  v35 = *(_DWORD *)(numDirectBits + 4 * rep0 + 816);
  v36 = v35 * (v34 >> 11);
  if ( v8 >= v36 )
  {
    v42 = v34 - v36;
    v8 -= v36;
    *(_DWORD *)(numDirectBits + 4 * rep0 + 816) = v35 - (v35 >> 5);
    if ( v42 < 0x1000000 )
    {
      if ( v33 == nowPos )
        return 1;
      v42 <<= 8;
      v8 = *v33++ | (v8 << 8);
      BufferLim = v33;
    }
    v43 = *(_DWORD *)(numDirectBits + 4 * rep0 + 864);
    v44 = v43 * (v42 >> 11);
    if ( v8 >= v44 )
    {
      v47 = v42 - v44;
      v8 -= v44;
      *(_DWORD *)(numDirectBits + 4 * rep0 + 864) = v43 - (v43 >> 5);
      if ( v47 < 0x1000000 )
      {
        if ( v33 == nowPos )
          return 1;
        v47 <<= 8;
        v8 = *v33 | (v8 << 8);
        BufferLim = v33 + 1;
      }
      v48 = *(_DWORD *)(numDirectBits + 4 * rep0 + 912);
      v49 = v48 * (v47 >> 11);
      if ( v8 >= v49 )
      {
        v29 = v47 - v49;
        v8 -= v49;
        *(_DWORD *)(numDirectBits + 4 * rep0 + 912) = v48 - (v48 >> 5);
        v46 = lc;
        lc = rep1;
      }
      else
      {
        v29 = v48 * (v47 >> 11);
        v50 = v48 + ((2048 - v48) >> 5);
        v46 = rep1;
        *(_DWORD *)(numDirectBits + 4 * rep0 + 912) = v50;
      }
      rep1 = p;
    }
    else
    {
      v29 = v43 * (v42 >> 11);
      v45 = v43 + ((2048 - v43) >> 5);
      v46 = p;
      *(_DWORD *)(numDirectBits + 4 * rep0 + 864) = v45;
    }
    p = prob;
    prob = v46;
  }
  else
  {
    *(_DWORD *)(numDirectBits + 4 * rep0 + 816) = v35 + ((2048 - v35) >> 5);
    v37 = v35 * (v34 >> 11);
    v38 = (unsigned int *)(numDirectBits + 4 * (rep3 + 16 * (rep0 + 15)));
    if ( v36 < 0x1000000 )
    {
      if ( BufferLim == nowPos )
        return 1;
      v37 = v36 << 8;
      v8 = *BufferLim++ | (v8 << 8);
    }
    v39 = *v38;
    v40 = *v38 * (v37 >> 11);
    if ( v8 < v40 )
    {
      v14 = *v38 * (v37 >> 11);
      *v38 = v39 + ((2048 - v39) >> 5);
      if ( state != 0 )
      {
        rep0 = 2 * (rep0 >= 7) + 9;
        v41 = outStream[state - prob];
        outStream[state] = v41;
        i = v41;
        ++state;
        goto LABEL_37;
      }
      return 1;
    }
    v29 = v37 - v40;
    v8 -= v40;
    *v38 = v39 - (v39 >> 5);
  }
  rep0 = rep0 >= 7 ? 11 : 8;
  v32 = (unsigned int *)(numDirectBits + 5328);
LABEL_72:
  v51 = BufferLim;
  if ( v29 < 0x1000000 )
  {
    if ( BufferLim == nowPos )
      return 1;
    v29 <<= 8;
    v8 = *BufferLim | (v8 << 8);
    v51 = ++BufferLim;
  }
  v52 = *v32;
  v53 = *v32 * (v29 >> 11);
  if ( v8 >= v53 )
  {
    v56 = v29 - v53;
    v8 -= v53;
    *v32 = v52 - (v52 >> 5);
    if ( v56 < 0x1000000 )
    {
      if ( v51 == nowPos )
        return 1;
      v56 <<= 8;
      v8 = *v51 | (v8 << 8);
      BufferLim = v51 + 1;
    }
    v57 = v32[1];
    v58 = v57 * (v56 >> 11);
    if ( v8 >= v58 )
    {
      v14 = v56 - v58;
      v8 -= v58;
      v32[1] = v57 - (v57 >> 5);
      v54 = (int)(v32 + 258);
      v55 = 16;
      ib = 8;
    }
    else
    {
      v14 = v57 * (v56 >> 11);
      v32[1] = v57 + ((2048 - v57) >> 5);
      v54 = (int)&v32[8 * rep3 + 130];
      v55 = 8;
      ib = 3;
    }
  }
  else
  {
    v14 = *v32 * (v29 >> 11);
    *v32 = v52 + ((2048 - v52) >> 5);
    v54 = (int)&v32[8 * rep3 + 2];
    v55 = 0;
    ib = 3;
  }
  rep3a = ib;
  v59 = 1;
  do
  {
    if ( v14 < 0x1000000 )
    {
      if ( BufferLim == nowPos )
        return 1;
      v14 <<= 8;
      v8 = *BufferLim++ | (v8 << 8);
    }
    v60 = *(_DWORD *)(v54 + 4 * v59);
    v61 = v60 * (v14 >> 11);
    if ( v8 >= v61 )
    {
      v14 -= v61;
      v8 -= v61;
      *(_DWORD *)(v54 + 4 * v59) = v60 - (v60 >> 5);
      v59 = 2 * v59 + 1;
    }
    else
    {
      v14 = v60 * (v14 >> 11);
      *(_DWORD *)(v54 + 4 * v59) = v60 + ((2048 - v60) >> 5);
      v59 *= 2;
    }
    --rep3a;
  }
  while ( rep3a != 0 );
  v62 = v55 - (1 << ib) + v59;
  rep2b = v62;
  if ( rep0 < 4 )
  {
    rep0 += 7;
    v63 = v62;
    if ( v62 >= 4 )
      v63 = 3;
    v64 = BufferLim;
    v65 = (v63 << 8) + numDirectBits + 1728;
    ic = 6;
    v66 = 1;
    do
    {
      if ( v14 < 0x1000000 )
      {
        if ( v64 == nowPos )
          return 1;
        v14 <<= 8;
        v8 = *v64++ | (v8 << 8);
        BufferLim = v64;
      }
      v67 = *(_DWORD *)(v65 + 4 * v66);
      v68 = v67 * (v14 >> 11);
      if ( v8 >= v68 )
      {
        v14 -= v68;
        v8 -= v68;
        *(_DWORD *)(v65 + 4 * v66) = v67 - (v67 >> 5);
        v66 = 2 * v66 + 1;
      }
      else
      {
        v14 = v67 * (v14 >> 11);
        *(_DWORD *)(v65 + 4 * v66) = v67 + ((2048 - v67) >> 5);
        v66 *= 2;
      }
      --ic;
    }
    while ( ic != 0 );
    v69 = v66 - 64;
    v70 = v69;
    if ( v69 >= 4 )
    {
      v71 = (v69 >> 1) - 1;
      v72 = v69 & 1 | 2;
      rep3b = v71;
      if ( v69 >= 14 )
      {
        v74 = BufferLim;
        v75 = v71 - 4;
        do
        {
          if ( v14 < 0x1000000 )
          {
            if ( v74 == nowPos )
              return 1;
            v14 <<= 8;
            v8 = *v74++ | (v8 << 8);
            BufferLim = v74;
          }
          v14 >>= 1;
          v72 *= 2;
          if ( v8 >= v14 )
          {
            v8 -= v14;
            v72 |= 1u;
          }
          --v75;
        }
        while ( v75 != 0 );
        v73 = numDirectBits + 3208;
        v70 = 16 * v72;
        rep3b = 4;
      }
      else
      {
        v70 = v72 << v71;
        v73 = numDirectBits + 4 * (v70 - v69) + 2748;
      }
      v76 = 1;
      id = 1;
      do
      {
        if ( v14 < 0x1000000 )
        {
          if ( BufferLim == nowPos )
            return 1;
          v14 <<= 8;
          v8 = *BufferLim++ | (v8 << 8);
        }
        v77 = *(_DWORD *)(v73 + 4 * v76);
        v78 = v77 * (v14 >> 11);
        if ( v8 >= v78 )
        {
          v14 -= v78;
          v8 -= v78;
          v70 |= id;
          *(_DWORD *)(v73 + 4 * v76) = v77 - (v77 >> 5);
          v76 = 2 * v76 + 1;
        }
        else
        {
          v14 = v77 * (v14 >> 11);
          *(_DWORD *)(v73 + 4 * v76) = v77 + ((2048 - v77) >> 5);
          v76 *= 2;
        }
        id *= 2;
        --rep3b;
      }
      while ( rep3b != 0 );
    }
    prob = v70 + 1;
    if ( v70 == -1 )
      goto LABEL_38;
    v62 = rep2b;
  }
  v79 = state;
  v80 = v62 + 2;
  if ( prob > state )
    return 1;
  v81 = &outStream[state - prob];
  do
  {
    v82 = *v81;
    --v80;
    outStream[v79++] = *v81++;
    i = v82;
    state = v79;
    if ( v80 == 0 )
      goto LABEL_37;
  }
  while ( v79 < outSize );
LABEL_38:
  if ( v14 < 0x1000000 )
  {
    if ( BufferLim == nowPos )
      return 1;
    ++BufferLim;
  }
LABEL_129:
  *inSizeProcessed = BufferLim - inStream;
  *outSizeProcessed = state;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10040790
// Name: public: unsigned int CLZMA::Uncompress(unsigned char __near *,unsigned char __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZMA::Uncompress(
        CLZMA *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        void (__cdecl *pCallback)())
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ebx
  void *v6; // edi
  int v7; // esi
  unsigned __int8 *result; // eax
  unsigned int v9; // [esp-1Ch] [ebp-34h]
  _CLzmaDecoderState state; // [esp+4h] [ebp-14h] BYREF
  void *v11; // [esp+14h] [ebp-4h]

  v4 = pInput;
  if ( pInput == nullptr )
    return nullptr;
  if ( *(_DWORD *)pInput != 1095588428 )
    return nullptr;
  v5 = *((unsigned __int8 **)pInput + 1);
  if ( v5 == nullptr )
    return nullptr;
  LzmaDecodeProperties(propsRes: (_CLzmaProperties *)&state.Properties.lp, propsData: pInput + 12, size: 5);
  v6 = _g_pMemAlloc->Alloc_2(
         this: _g_pMemAlloc,
         a2: 4 * (768 << (LOBYTE(state.Properties.pb) + LOBYTE(state.Properties.lp))) + 7384);
  v9 = *((_DWORD *)v4 + 2);
  v11 = v6;
  v7 = LzmaDecode(
         vs: (_CLzmaDecoderState *)&state.Properties.lp,
         inStream: v4 + 17,
         inSize: v9,
         inSizeProcessed: (unsigned int *)&pCallback,
         outStream: pOutput,
         outSize: (unsigned int)v5,
         outSizeProcessed: (unsigned int *)&pInput,
         pCallbackFunc: pCallback);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  if ( v7 != 0 )
    return nullptr;
  result = pInput;
  if ( pInput != v5 )
    return nullptr;
  return result;
}

} // namespace shaderapidx10
