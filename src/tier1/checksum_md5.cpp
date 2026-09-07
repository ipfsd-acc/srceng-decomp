// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/checksum_md5.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10275F60
// Name: MD5Transform
// Source: json
//------------------------------------------------------------------------------
void __usercall MD5Transform(const unsigned int *in@<eax>, unsigned int *buf)
{
  unsigned int v2; // edx
  unsigned int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // esi
  int v16; // edi
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edi
  int v21; // ecx
  int v22; // edx
  unsigned int v23; // esi
  int v24; // edx
  int v25; // esi
  int v26; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // esi
  int v30; // edi
  int v31; // ecx
  int v32; // edx
  int v33; // esi
  int v34; // edi
  int v35; // ecx
  int v36; // edx
  int v37; // esi
  int v38; // edi
  int v39; // ecx
  int v40; // edx
  unsigned int v41; // edi
  unsigned int v42; // ecx
  unsigned int v43; // esi
  int v44; // edx
  int v45; // ebx
  int v46; // edx
  int v47; // ecx
  int v48; // esi
  int v49; // edi
  unsigned int v50; // ebx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // edx
  int v56; // ecx
  int v57; // esi
  int v58; // edi
  int v59; // eax
  int v60; // ecx
  int v61; // edx
  int v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // esi
  int v67; // eax
  int v68; // ecx
  int v69; // edx
  int v70; // esi
  int v71; // edi
  unsigned int v72; // ebx
  unsigned int v73; // ecx
  unsigned int v74; // [esp+10h] [ebp-40h]
  unsigned int v75; // [esp+14h] [ebp-3Ch]
  unsigned int v76; // [esp+18h] [ebp-38h]
  unsigned int v77; // [esp+1Ch] [ebp-34h]
  unsigned int v78; // [esp+20h] [ebp-30h]
  unsigned int v79; // [esp+24h] [ebp-2Ch]
  unsigned int v80; // [esp+28h] [ebp-28h]
  unsigned int v81; // [esp+2Ch] [ebp-24h]
  unsigned int v82; // [esp+30h] [ebp-20h]
  unsigned int v83; // [esp+3Ch] [ebp-14h]
  unsigned int v84; // [esp+44h] [ebp-Ch]
  unsigned int d; // [esp+48h] [ebp-8h]
  unsigned int da; // [esp+48h] [ebp-8h]
  unsigned int b; // [esp+4Ch] [ebp-4h]
  unsigned int ba; // [esp+4Ch] [ebp-4h]
  unsigned int bb; // [esp+4Ch] [ebp-4h]

  v2 = buf[3];
  v3 = buf[1];
  v4 = buf[2];
  v5 = v3 + __ROL4__(*in + (v2 ^ v3 & (v4 ^ v2)) + *buf - 680876936, 7);
  v6 = v5 + __ROL4__(in[1] + (v4 ^ v5 & (v3 ^ v4)) + v2 - 389564586, 12);
  v7 = v6 + __ROR4__(in[2] + (v3 ^ v6 & (v5 ^ v3)) + v4 + 606105819, 15);
  v8 = v7 + __ROR4__(in[3] + (v5 ^ v7 & (v5 ^ v6)) + buf[1] - 1044525330, 10);
  v9 = v8 + __ROL4__(in[4] + (v6 ^ v8 & (v7 ^ v6)) + v5 - 176418897, 7);
  v10 = v9 + __ROL4__(in[5] + (v7 ^ v9 & (v8 ^ v7)) + v6 + 1200080426, 12);
  v11 = v10 + __ROR4__(in[6] + (v8 ^ v10 & (v9 ^ v8)) + v7 - 1473231341, 15);
  v83 = in[7];
  v12 = v11 + __ROR4__(v83 + (v9 ^ v11 & (v9 ^ v10)) + v8 - 45705983, 10);
  v13 = v12 + __ROL4__(in[8] + (v10 ^ v12 & (v11 ^ v10)) + v9 + 1770035416, 7);
  v14 = v13 + __ROL4__(in[9] + (v11 ^ v13 & (v12 ^ v11)) + v10 - 1958414417, 12);
  v15 = v14 + __ROR4__(in[10] + (v12 ^ v14 & (v13 ^ v12)) + v11 - 42063, 15);
  v16 = v15 + __ROR4__(in[11] + (v13 ^ v15 & (v13 ^ v14)) + v12 - 1990404162, 10);
  v17 = v16 + __ROL4__(in[12] + (v14 ^ v16 & (v15 ^ v14)) + v13 + 1804603682, 7);
  v18 = v17 + __ROL4__(in[13] + (v15 ^ v17 & (v16 ^ v15)) + v14 - 40341101, 12);
  v19 = v18 + __ROR4__(in[14] + (v16 ^ v18 & (v17 ^ v16)) + v15 - 1502002290, 15);
  v20 = v19 + __ROR4__(in[15] + (v17 ^ v19 & (v17 ^ v18)) + v16 + 1236535329, 10);
  v21 = v20 + __ROL4__(in[1] + (v19 ^ v18 & (v20 ^ v19)) + v17 - 165796510, 5);
  v22 = __ROL4__(in[6] + (v20 ^ v19 & (v21 ^ v20)) + v18 - 1069501632, 9);
  v23 = in[11] + (v21 ^ v20 & (v21 ^ (v21 + v22))) + v19 + 643717713;
  v24 = v21 + v22;
  v25 = v24 + __ROL4__(v23, 14);
  v26 = v25 + __ROR4__(*in + (v24 ^ v21 & (v25 ^ v24)) + v20 - 373897302, 12);
  v27 = v26 + __ROL4__(in[5] + (v25 ^ v24 & (v26 ^ v25)) + v21 - 701558691, 5);
  v28 = v27 + __ROL4__(in[10] + (v26 ^ v25 & (v27 ^ v26)) + v24 + 38016083, 9);
  v29 = v28 + __ROL4__(in[15] + (v27 ^ v26 & (v27 ^ v28)) + v25 - 660478335, 14);
  v30 = v29 + __ROR4__(in[4] + (v28 ^ v27 & (v29 ^ v28)) + v26 - 405537848, 12);
  v31 = v30 + __ROL4__(in[9] + (v29 ^ v28 & (v30 ^ v29)) + v27 + 568446438, 5);
  v32 = v31 + __ROL4__(in[14] + (v30 ^ v29 & (v31 ^ v30)) + v28 - 1019803690, 9);
  v33 = v32 + __ROL4__(in[3] + (v31 ^ v30 & (v31 ^ v32)) + v29 - 187363961, 14);
  v34 = v33 + __ROR4__(in[8] + (v32 ^ v31 & (v33 ^ v32)) + v30 + 1163531501, 12);
  v35 = v34 + __ROL4__(in[13] + (v33 ^ v32 & (v34 ^ v33)) + v31 - 1444681467, 5);
  v36 = v35 + __ROL4__(in[2] + (v34 ^ v33 & (v35 ^ v34)) + v32 - 51403784, 9);
  v84 = in[2];
  v37 = v36 + __ROL4__(v83 + (v35 ^ v34 & (v35 ^ v36)) + v33 + 1735328473, 14);
  v38 = v37 + __ROR4__(in[12] + (v36 ^ v35 & (v37 ^ v36)) + v34 - 1926607734, 12);
  v39 = v38 + __ROL4__(in[5] + (v38 ^ v37 ^ v36) + v35 - 378558, 4);
  v40 = v39 + __ROL4__(in[8] + (v39 ^ v38 ^ v37) + v36 - 2022574463, 11);
  v79 = in[8];
  v74 = in[11];
  b = v40 + __ROL4__(v74 + (v39 ^ v38 ^ v40) + v37 + 1839030562, 16);
  v41 = b + __ROR4__(in[14] + (v39 ^ b ^ v40) + v38 - 35309556, 9);
  v80 = in[1];
  v42 = v41 + __ROL4__(v80 + (v41 ^ b ^ v40) + v39 - 1530992060, 4);
  v75 = in[4];
  v43 = v42 + __ROL4__(v75 + (v42 ^ v41 ^ b) + v40 + 1272893353, 11);
  v44 = __ROL4__(v83 + (v42 ^ v41 ^ v43) + b - 155497632, 16);
  ba = v43 + v44;
  v45 = (v43 + v44) ^ v43;
  v81 = in[10];
  v46 = v43 + v44 + __ROR4__(v81 + (v42 ^ v45) + v41 - 1094730640, 9);
  v76 = in[13];
  v47 = v46 + __ROL4__(v76 + (v46 ^ v45) + v42 + 681279174, 4);
  v48 = v47 + __ROL4__(*in + (v47 ^ v46 ^ ba) + v43 - 358537222, 11);
  v82 = in[3];
  v49 = __ROL4__(v82 + (v47 ^ v46 ^ v48) + ba - 722521979, 16);
  bb = v48 + v49;
  d = (v48 + v49) ^ v48;
  v50 = in[9];
  v51 = v48 + v49 + __ROR4__(in[6] + (v47 ^ d) + v46 + 76029189, 9);
  v77 = in[6];
  v52 = v51 + __ROL4__(v50 + (v51 ^ d) + v47 - 640364487, 4);
  da = in[12];
  v78 = in[15];
  v53 = v52 + __ROL4__(da + (v52 ^ v51 ^ (v48 + v49)) + v48 - 421815835, 11);
  v54 = v53 + __ROL4__(v78 + (v52 ^ v51 ^ v53) + bb + 530742520, 16);
  v55 = v54 + __ROR4__(v84 + (v52 ^ v54 ^ v53) + v51 - 995338651, 9);
  v56 = v55 + __ROL4__(*in + (v54 ^ (v55 | ~v53)) + v52 - 198630844, 6);
  v57 = v56 + __ROL4__(v83 + (v55 ^ (v56 | ~v54)) + v53 + 1126891415, 10);
  v58 = v57 + __ROL4__(in[14] + (v56 ^ (v57 | ~v55)) + v54 - 1416354905, 15);
  v59 = v58 + __ROR4__(in[5] + (v57 ^ (v58 | ~v56)) + v55 - 57434055, 11);
  v60 = v59 + __ROL4__(da + (v58 ^ (v59 | ~v57)) + v56 + 1700485571, 6);
  v61 = v60 + __ROL4__(v82 + (v59 ^ (v60 | ~v58)) + v57 - 1894986606, 10);
  v62 = v61 + __ROL4__(v81 + (v60 ^ (v61 | ~v59)) + v58 - 1051523, 15);
  v63 = v62 + __ROR4__(v80 + (v61 ^ (v62 | ~v60)) + v59 - 2054922799, 11);
  v64 = v63 + __ROL4__(v79 + (v62 ^ (v63 | ~v61)) + v60 + 1873313359, 6);
  v65 = v64 + __ROL4__(v78 + (v63 ^ (v64 | ~v62)) + v61 - 30611744, 10);
  v66 = v65 + __ROL4__(v77 + (v64 ^ (v65 | ~v63)) + v62 - 1560198380, 15);
  v67 = v66 + __ROR4__(v76 + (v65 ^ (v66 | ~v64)) + v63 + 1309151649, 11);
  v68 = v67 + __ROL4__(v75 + (v66 ^ (v67 | ~v65)) + v64 - 145523070, 6);
  v69 = v68 + __ROL4__(v74 + (v67 ^ (v68 | ~v66)) + v65 - 1120210379, 10);
  v70 = v69 + __ROL4__(v84 + (v68 ^ (v69 | ~v67)) + v66 + 718787259, 15);
  v71 = v50 + (v69 ^ (v70 | ~v68)) + v67 - 343485551;
  v72 = v68 + *buf;
  buf[1] += v70 + __ROR4__(v71, 11);
  v73 = v70 + buf[2];
  *buf = v72;
  buf[2] = v73;
  buf[3] += v69;
}

//------------------------------------------------------------------------------
// Address: 0x102765E0
// Name: void MD5Init(struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Init(MD5Context_t *ctx)
{
  ctx->buf[0] = 1732584193;
  ctx->buf[1] = -271733879;
  ctx->buf[2] = -1732584194;
  ctx->buf[3] = 271733878;
  ctx->bits[0] = 0;
  ctx->bits[1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10276610
// Name: void MD5Update(struct MD5Context_t __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Update(MD5Context_t *ctx, unsigned __int8 *buf, unsigned int len)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // esi
  MD5Context_t *ctxa; // [esp+14h] [ebp+8h]

  v4 = ctx->bits[0];
  v5 = len;
  v6 = v4 + 8 * len;
  ctx->bits[0] = v6;
  if ( v6 < v4 )
    ++ctx->bits[1];
  ctx->bits[1] += len >> 29;
  v7 = (v4 >> 3) & 0x3F;
  if ( v7 != 0 )
  {
    v8 = 64 - v7;
    if ( len < 64 - v7 )
    {
      memcpy(dst: &ctx->in[v7], src: buf, count: len);
      return;
    }
    memcpy(dst: &ctx->in[v7], src: buf, count: v8);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    buf += v8;
    v5 = len - v8;
    len -= v8;
  }
  if ( v5 >= 0x40 )
  {
    ctxa = (MD5Context_t *)(v5 >> 6);
    do
    {
      qmemcpy(ctx->in, buf, sizeof(ctx->in));
      MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
      buf += 64;
      len -= 64;
      ctxa = (MD5Context_t *)((char *)ctxa - 1);
    }
    while ( ctxa != nullptr );
    v5 = len;
  }
  memcpy(dst: ctx->in, src: buf, count: v5);
}

//------------------------------------------------------------------------------
// Address: 0x102766D0
// Name: void MD5Final(unsigned char __near * const,struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Final(unsigned __int8 *digest, MD5Context_t *ctx)
{
  unsigned int v2; // eax
  unsigned __int8 *v3; // edx
  unsigned int v4; // ecx

  v2 = (ctx->bits[0] >> 3) & 0x3F;
  ctx->in[v2] = 0x80;
  v3 = &ctx->in[v2 + 1];
  if ( 63 - v2 >= 8 )
  {
    memset(dst: v3, value: 0, count: 63 - v2 - 8);
  }
  else
  {
    memset(dst: v3, value: 0, count: 63 - v2);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    memset(dst: ctx->in, value: 0, count: 0x38u);
  }
  v4 = ctx->bits[1];
  *(_DWORD *)&ctx->in[56] = ctx->bits[0];
  *(_DWORD *)&ctx->in[60] = v4;
  MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
  *(_QWORD *)digest = *(_QWORD *)ctx->buf;
  *((_QWORD *)digest + 1) = *(_QWORD *)&ctx->buf[2];
  ctx->buf[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10276760
// Name: char __near * MD5_Print(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MD5_Print(unsigned __int8 *hash, int hashlen)
{
  V_binarytohex(in: hash, inputbytes: hashlen, out: szReturn, outsize: 0x40u);
  return szReturn;
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x1025BCD0
// Name: MD5Transform
// Source: json
//------------------------------------------------------------------------------
void __usercall MD5Transform(const unsigned int *in@<eax>, unsigned int *buf)
{
  unsigned int v2; // edx
  unsigned int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // esi
  int v16; // edi
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edi
  int v21; // ecx
  int v22; // edx
  unsigned int v23; // esi
  int v24; // edx
  int v25; // esi
  int v26; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // esi
  int v30; // edi
  int v31; // ecx
  int v32; // edx
  int v33; // esi
  int v34; // edi
  int v35; // ecx
  int v36; // edx
  int v37; // esi
  int v38; // edi
  int v39; // ecx
  int v40; // edx
  unsigned int v41; // edi
  unsigned int v42; // ecx
  unsigned int v43; // esi
  int v44; // edx
  int v45; // ebx
  int v46; // edx
  int v47; // ecx
  int v48; // esi
  int v49; // edi
  unsigned int v50; // ebx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // edx
  int v56; // ecx
  int v57; // esi
  int v58; // edi
  int v59; // eax
  int v60; // ecx
  int v61; // edx
  int v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // esi
  int v67; // eax
  int v68; // ecx
  int v69; // edx
  int v70; // esi
  int v71; // edi
  unsigned int v72; // ebx
  unsigned int v73; // ecx
  unsigned int v74; // [esp+10h] [ebp-40h]
  unsigned int v75; // [esp+14h] [ebp-3Ch]
  unsigned int v76; // [esp+18h] [ebp-38h]
  unsigned int v77; // [esp+1Ch] [ebp-34h]
  unsigned int v78; // [esp+20h] [ebp-30h]
  unsigned int v79; // [esp+24h] [ebp-2Ch]
  unsigned int v80; // [esp+28h] [ebp-28h]
  unsigned int v81; // [esp+2Ch] [ebp-24h]
  unsigned int v82; // [esp+30h] [ebp-20h]
  unsigned int v83; // [esp+3Ch] [ebp-14h]
  unsigned int v84; // [esp+44h] [ebp-Ch]
  unsigned int d; // [esp+48h] [ebp-8h]
  unsigned int da; // [esp+48h] [ebp-8h]
  unsigned int b; // [esp+4Ch] [ebp-4h]
  unsigned int ba; // [esp+4Ch] [ebp-4h]
  unsigned int bb; // [esp+4Ch] [ebp-4h]

  v2 = buf[3];
  v3 = buf[1];
  v4 = buf[2];
  v5 = v3 + __ROL4__(*in + (v2 ^ v3 & (v4 ^ v2)) + *buf - 680876936, 7);
  v6 = v5 + __ROL4__(in[1] + (v4 ^ v5 & (v3 ^ v4)) + v2 - 389564586, 12);
  v7 = v6 + __ROR4__(in[2] + (v3 ^ v6 & (v5 ^ v3)) + v4 + 606105819, 15);
  v8 = v7 + __ROR4__(in[3] + (v5 ^ v7 & (v5 ^ v6)) + buf[1] - 1044525330, 10);
  v9 = v8 + __ROL4__(in[4] + (v6 ^ v8 & (v7 ^ v6)) + v5 - 176418897, 7);
  v10 = v9 + __ROL4__(in[5] + (v7 ^ v9 & (v8 ^ v7)) + v6 + 1200080426, 12);
  v11 = v10 + __ROR4__(in[6] + (v8 ^ v10 & (v9 ^ v8)) + v7 - 1473231341, 15);
  v83 = in[7];
  v12 = v11 + __ROR4__(v83 + (v9 ^ v11 & (v9 ^ v10)) + v8 - 45705983, 10);
  v13 = v12 + __ROL4__(in[8] + (v10 ^ v12 & (v11 ^ v10)) + v9 + 1770035416, 7);
  v14 = v13 + __ROL4__(in[9] + (v11 ^ v13 & (v12 ^ v11)) + v10 - 1958414417, 12);
  v15 = v14 + __ROR4__(in[10] + (v12 ^ v14 & (v13 ^ v12)) + v11 - 42063, 15);
  v16 = v15 + __ROR4__(in[11] + (v13 ^ v15 & (v13 ^ v14)) + v12 - 1990404162, 10);
  v17 = v16 + __ROL4__(in[12] + (v14 ^ v16 & (v15 ^ v14)) + v13 + 1804603682, 7);
  v18 = v17 + __ROL4__(in[13] + (v15 ^ v17 & (v16 ^ v15)) + v14 - 40341101, 12);
  v19 = v18 + __ROR4__(in[14] + (v16 ^ v18 & (v17 ^ v16)) + v15 - 1502002290, 15);
  v20 = v19 + __ROR4__(in[15] + (v17 ^ v19 & (v17 ^ v18)) + v16 + 1236535329, 10);
  v21 = v20 + __ROL4__(in[1] + (v19 ^ v18 & (v20 ^ v19)) + v17 - 165796510, 5);
  v22 = __ROL4__(in[6] + (v20 ^ v19 & (v21 ^ v20)) + v18 - 1069501632, 9);
  v23 = in[11] + (v21 ^ v20 & (v21 ^ (v21 + v22))) + v19 + 643717713;
  v24 = v21 + v22;
  v25 = v24 + __ROL4__(v23, 14);
  v26 = v25 + __ROR4__(*in + (v24 ^ v21 & (v25 ^ v24)) + v20 - 373897302, 12);
  v27 = v26 + __ROL4__(in[5] + (v25 ^ v24 & (v26 ^ v25)) + v21 - 701558691, 5);
  v28 = v27 + __ROL4__(in[10] + (v26 ^ v25 & (v27 ^ v26)) + v24 + 38016083, 9);
  v29 = v28 + __ROL4__(in[15] + (v27 ^ v26 & (v27 ^ v28)) + v25 - 660478335, 14);
  v30 = v29 + __ROR4__(in[4] + (v28 ^ v27 & (v29 ^ v28)) + v26 - 405537848, 12);
  v31 = v30 + __ROL4__(in[9] + (v29 ^ v28 & (v30 ^ v29)) + v27 + 568446438, 5);
  v32 = v31 + __ROL4__(in[14] + (v30 ^ v29 & (v31 ^ v30)) + v28 - 1019803690, 9);
  v33 = v32 + __ROL4__(in[3] + (v31 ^ v30 & (v31 ^ v32)) + v29 - 187363961, 14);
  v34 = v33 + __ROR4__(in[8] + (v32 ^ v31 & (v33 ^ v32)) + v30 + 1163531501, 12);
  v35 = v34 + __ROL4__(in[13] + (v33 ^ v32 & (v34 ^ v33)) + v31 - 1444681467, 5);
  v36 = v35 + __ROL4__(in[2] + (v34 ^ v33 & (v35 ^ v34)) + v32 - 51403784, 9);
  v84 = in[2];
  v37 = v36 + __ROL4__(v83 + (v35 ^ v34 & (v35 ^ v36)) + v33 + 1735328473, 14);
  v38 = v37 + __ROR4__(in[12] + (v36 ^ v35 & (v37 ^ v36)) + v34 - 1926607734, 12);
  v39 = v38 + __ROL4__(in[5] + (v38 ^ v37 ^ v36) + v35 - 378558, 4);
  v40 = v39 + __ROL4__(in[8] + (v39 ^ v38 ^ v37) + v36 - 2022574463, 11);
  v79 = in[8];
  v74 = in[11];
  b = v40 + __ROL4__(v74 + (v39 ^ v38 ^ v40) + v37 + 1839030562, 16);
  v41 = b + __ROR4__(in[14] + (v39 ^ b ^ v40) + v38 - 35309556, 9);
  v80 = in[1];
  v42 = v41 + __ROL4__(v80 + (v41 ^ b ^ v40) + v39 - 1530992060, 4);
  v75 = in[4];
  v43 = v42 + __ROL4__(v75 + (v42 ^ v41 ^ b) + v40 + 1272893353, 11);
  v44 = __ROL4__(v83 + (v42 ^ v41 ^ v43) + b - 155497632, 16);
  ba = v43 + v44;
  v45 = (v43 + v44) ^ v43;
  v81 = in[10];
  v46 = v43 + v44 + __ROR4__(v81 + (v42 ^ v45) + v41 - 1094730640, 9);
  v76 = in[13];
  v47 = v46 + __ROL4__(v76 + (v46 ^ v45) + v42 + 681279174, 4);
  v48 = v47 + __ROL4__(*in + (v47 ^ v46 ^ ba) + v43 - 358537222, 11);
  v82 = in[3];
  v49 = __ROL4__(v82 + (v47 ^ v46 ^ v48) + ba - 722521979, 16);
  bb = v48 + v49;
  d = (v48 + v49) ^ v48;
  v50 = in[9];
  v51 = v48 + v49 + __ROR4__(in[6] + (v47 ^ d) + v46 + 76029189, 9);
  v77 = in[6];
  v52 = v51 + __ROL4__(v50 + (v51 ^ d) + v47 - 640364487, 4);
  da = in[12];
  v78 = in[15];
  v53 = v52 + __ROL4__(da + (v52 ^ v51 ^ (v48 + v49)) + v48 - 421815835, 11);
  v54 = v53 + __ROL4__(v78 + (v52 ^ v51 ^ v53) + bb + 530742520, 16);
  v55 = v54 + __ROR4__(v84 + (v52 ^ v54 ^ v53) + v51 - 995338651, 9);
  v56 = v55 + __ROL4__(*in + (v54 ^ (v55 | ~v53)) + v52 - 198630844, 6);
  v57 = v56 + __ROL4__(v83 + (v55 ^ (v56 | ~v54)) + v53 + 1126891415, 10);
  v58 = v57 + __ROL4__(in[14] + (v56 ^ (v57 | ~v55)) + v54 - 1416354905, 15);
  v59 = v58 + __ROR4__(in[5] + (v57 ^ (v58 | ~v56)) + v55 - 57434055, 11);
  v60 = v59 + __ROL4__(da + (v58 ^ (v59 | ~v57)) + v56 + 1700485571, 6);
  v61 = v60 + __ROL4__(v82 + (v59 ^ (v60 | ~v58)) + v57 - 1894986606, 10);
  v62 = v61 + __ROL4__(v81 + (v60 ^ (v61 | ~v59)) + v58 - 1051523, 15);
  v63 = v62 + __ROR4__(v80 + (v61 ^ (v62 | ~v60)) + v59 - 2054922799, 11);
  v64 = v63 + __ROL4__(v79 + (v62 ^ (v63 | ~v61)) + v60 + 1873313359, 6);
  v65 = v64 + __ROL4__(v78 + (v63 ^ (v64 | ~v62)) + v61 - 30611744, 10);
  v66 = v65 + __ROL4__(v77 + (v64 ^ (v65 | ~v63)) + v62 - 1560198380, 15);
  v67 = v66 + __ROR4__(v76 + (v65 ^ (v66 | ~v64)) + v63 + 1309151649, 11);
  v68 = v67 + __ROL4__(v75 + (v66 ^ (v67 | ~v65)) + v64 - 145523070, 6);
  v69 = v68 + __ROL4__(v74 + (v67 ^ (v68 | ~v66)) + v65 - 1120210379, 10);
  v70 = v69 + __ROL4__(v84 + (v68 ^ (v69 | ~v67)) + v66 + 718787259, 15);
  v71 = v50 + (v69 ^ (v70 | ~v68)) + v67 - 343485551;
  v72 = v68 + *buf;
  buf[1] += v70 + __ROR4__(v71, 11);
  v73 = v70 + buf[2];
  *buf = v72;
  buf[2] = v73;
  buf[3] += v69;
}

//------------------------------------------------------------------------------
// Address: 0x1025C350
// Name: void MD5Init(struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Init(MD5Context_t *ctx)
{
  ctx->buf[0] = 1732584193;
  ctx->buf[1] = -271733879;
  ctx->buf[2] = -1732584194;
  ctx->buf[3] = (unsigned int)&stru_10325460.nIPMapEntries + 2;
  ctx->bits[0] = 0;
  ctx->bits[1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1025C380
// Name: void MD5Update(struct MD5Context_t __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Update(MD5Context_t *ctx, unsigned __int8 *buf, unsigned int len)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // esi
  MD5Context_t *ctxa; // [esp+14h] [ebp+8h]

  v4 = ctx->bits[0];
  v5 = len;
  v6 = v4 + 8 * len;
  ctx->bits[0] = v6;
  if ( v6 < v4 )
    ++ctx->bits[1];
  ctx->bits[1] += len >> 29;
  v7 = (v4 >> 3) & 0x3F;
  if ( v7 != 0 )
  {
    v8 = 64 - v7;
    if ( len < 64 - v7 )
    {
      memcpy(dst: &ctx->in[v7], src: buf, count: len);
      return;
    }
    memcpy(dst: &ctx->in[v7], src: buf, count: v8);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    buf += v8;
    v5 = len - v8;
    len -= v8;
  }
  if ( v5 >= 0x40 )
  {
    ctxa = (MD5Context_t *)(v5 >> 6);
    do
    {
      qmemcpy(ctx->in, buf, sizeof(ctx->in));
      MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
      buf += 64;
      len -= 64;
      ctxa = (MD5Context_t *)((char *)ctxa - 1);
    }
    while ( ctxa != nullptr );
    v5 = len;
  }
  memcpy(dst: ctx->in, src: buf, count: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1025C440
// Name: void MD5Final(unsigned char __near * const,struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Final(unsigned __int8 *digest, MD5Context_t *ctx)
{
  unsigned int v2; // eax
  unsigned __int8 *v3; // edx
  unsigned int v4; // ecx

  v2 = (ctx->bits[0] >> 3) & 0x3F;
  ctx->in[v2] = 0x80;
  v3 = &ctx->in[v2 + 1];
  if ( 63 - v2 >= 8 )
  {
    memset(dst: v3, value: 0, count: 63 - v2 - 8);
  }
  else
  {
    memset(dst: v3, value: 0, count: 63 - v2);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    memset(dst: ctx->in, value: 0, count: 0x38u);
  }
  v4 = ctx->bits[1];
  *(_DWORD *)&ctx->in[56] = ctx->bits[0];
  *(_DWORD *)&ctx->in[60] = v4;
  MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
  *(_QWORD *)digest = *(_QWORD *)ctx->buf;
  *((_QWORD *)digest + 1) = *(_QWORD *)&ctx->buf[2];
  ctx->buf[0] = 0;
}

} // namespace MaterialSystem

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10275FE0
// Name: MD5Transform
// Source: json
//------------------------------------------------------------------------------
void __usercall MD5Transform(const unsigned int *in@<eax>, unsigned int *buf)
{
  unsigned int v2; // edx
  unsigned int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // esi
  int v16; // edi
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edi
  int v21; // ecx
  int v22; // edx
  unsigned int v23; // esi
  int v24; // edx
  int v25; // esi
  int v26; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // esi
  int v30; // edi
  int v31; // ecx
  int v32; // edx
  int v33; // esi
  int v34; // edi
  int v35; // ecx
  int v36; // edx
  int v37; // esi
  int v38; // edi
  int v39; // ecx
  int v40; // edx
  unsigned int v41; // edi
  unsigned int v42; // ecx
  unsigned int v43; // esi
  int v44; // edx
  int v45; // ebx
  int v46; // edx
  int v47; // ecx
  int v48; // esi
  int v49; // edi
  unsigned int v50; // ebx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // edx
  int v56; // ecx
  int v57; // esi
  int v58; // edi
  int v59; // eax
  int v60; // ecx
  int v61; // edx
  int v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // esi
  int v67; // eax
  int v68; // ecx
  int v69; // edx
  int v70; // esi
  int v71; // edi
  unsigned int v72; // ebx
  unsigned int v73; // ecx
  unsigned int v74; // [esp+10h] [ebp-40h]
  unsigned int v75; // [esp+14h] [ebp-3Ch]
  unsigned int v76; // [esp+18h] [ebp-38h]
  unsigned int v77; // [esp+1Ch] [ebp-34h]
  unsigned int v78; // [esp+20h] [ebp-30h]
  unsigned int v79; // [esp+24h] [ebp-2Ch]
  unsigned int v80; // [esp+28h] [ebp-28h]
  unsigned int v81; // [esp+2Ch] [ebp-24h]
  unsigned int v82; // [esp+30h] [ebp-20h]
  unsigned int v83; // [esp+3Ch] [ebp-14h]
  unsigned int v84; // [esp+44h] [ebp-Ch]
  unsigned int d; // [esp+48h] [ebp-8h]
  unsigned int da; // [esp+48h] [ebp-8h]
  unsigned int b; // [esp+4Ch] [ebp-4h]
  unsigned int ba; // [esp+4Ch] [ebp-4h]
  unsigned int bb; // [esp+4Ch] [ebp-4h]

  v2 = buf[3];
  v3 = buf[1];
  v4 = buf[2];
  v5 = v3 + __ROL4__(*in + (v2 ^ v3 & (v4 ^ v2)) + *buf - 680876936, 7);
  v6 = v5 + __ROL4__(in[1] + (v4 ^ v5 & (v3 ^ v4)) + v2 - 389564586, 12);
  v7 = v6 + __ROR4__(in[2] + (v3 ^ v6 & (v5 ^ v3)) + v4 + 606105819, 15);
  v8 = v7 + __ROR4__(in[3] + (v5 ^ v7 & (v5 ^ v6)) + buf[1] - 1044525330, 10);
  v9 = v8 + __ROL4__(in[4] + (v6 ^ v8 & (v7 ^ v6)) + v5 - 176418897, 7);
  v10 = v9 + __ROL4__(in[5] + (v7 ^ v9 & (v8 ^ v7)) + v6 + 1200080426, 12);
  v11 = v10 + __ROR4__(in[6] + (v8 ^ v10 & (v9 ^ v8)) + v7 - 1473231341, 15);
  v83 = in[7];
  v12 = v11 + __ROR4__(v83 + (v9 ^ v11 & (v9 ^ v10)) + v8 - 45705983, 10);
  v13 = v12 + __ROL4__(in[8] + (v10 ^ v12 & (v11 ^ v10)) + v9 + 1770035416, 7);
  v14 = v13 + __ROL4__(in[9] + (v11 ^ v13 & (v12 ^ v11)) + v10 - 1958414417, 12);
  v15 = v14 + __ROR4__(in[10] + (v12 ^ v14 & (v13 ^ v12)) + v11 - 42063, 15);
  v16 = v15 + __ROR4__(in[11] + (v13 ^ v15 & (v13 ^ v14)) + v12 - 1990404162, 10);
  v17 = v16 + __ROL4__(in[12] + (v14 ^ v16 & (v15 ^ v14)) + v13 + 1804603682, 7);
  v18 = v17 + __ROL4__(in[13] + (v15 ^ v17 & (v16 ^ v15)) + v14 - 40341101, 12);
  v19 = v18 + __ROR4__(in[14] + (v16 ^ v18 & (v17 ^ v16)) + v15 - 1502002290, 15);
  v20 = v19 + __ROR4__(in[15] + (v17 ^ v19 & (v17 ^ v18)) + v16 + 1236535329, 10);
  v21 = v20 + __ROL4__(in[1] + (v19 ^ v18 & (v20 ^ v19)) + v17 - 165796510, 5);
  v22 = __ROL4__(in[6] + (v20 ^ v19 & (v21 ^ v20)) + v18 - 1069501632, 9);
  v23 = in[11] + (v21 ^ v20 & (v21 ^ (v21 + v22))) + v19 + 643717713;
  v24 = v21 + v22;
  v25 = v24 + __ROL4__(v23, 14);
  v26 = v25 + __ROR4__(*in + (v24 ^ v21 & (v25 ^ v24)) + v20 - 373897302, 12);
  v27 = v26 + __ROL4__(in[5] + (v25 ^ v24 & (v26 ^ v25)) + v21 - 701558691, 5);
  v28 = v27 + __ROL4__(in[10] + (v26 ^ v25 & (v27 ^ v26)) + v24 + 38016083, 9);
  v29 = v28 + __ROL4__(in[15] + (v27 ^ v26 & (v27 ^ v28)) + v25 - 660478335, 14);
  v30 = v29 + __ROR4__(in[4] + (v28 ^ v27 & (v29 ^ v28)) + v26 - 405537848, 12);
  v31 = v30 + __ROL4__(in[9] + (v29 ^ v28 & (v30 ^ v29)) + v27 + 568446438, 5);
  v32 = v31 + __ROL4__(in[14] + (v30 ^ v29 & (v31 ^ v30)) + v28 - 1019803690, 9);
  v33 = v32 + __ROL4__(in[3] + (v31 ^ v30 & (v31 ^ v32)) + v29 - 187363961, 14);
  v34 = v33 + __ROR4__(in[8] + (v32 ^ v31 & (v33 ^ v32)) + v30 + 1163531501, 12);
  v35 = v34 + __ROL4__(in[13] + (v33 ^ v32 & (v34 ^ v33)) + v31 - 1444681467, 5);
  v36 = v35 + __ROL4__(in[2] + (v34 ^ v33 & (v35 ^ v34)) + v32 - 51403784, 9);
  v84 = in[2];
  v37 = v36 + __ROL4__(v83 + (v35 ^ v34 & (v35 ^ v36)) + v33 + 1735328473, 14);
  v38 = v37 + __ROR4__(in[12] + (v36 ^ v35 & (v37 ^ v36)) + v34 - 1926607734, 12);
  v39 = v38 + __ROL4__(in[5] + (v38 ^ v37 ^ v36) + v35 - 378558, 4);
  v40 = v39 + __ROL4__(in[8] + (v39 ^ v38 ^ v37) + v36 - 2022574463, 11);
  v79 = in[8];
  v74 = in[11];
  b = v40 + __ROL4__(v74 + (v39 ^ v38 ^ v40) + v37 + 1839030562, 16);
  v41 = b + __ROR4__(in[14] + (v39 ^ b ^ v40) + v38 - 35309556, 9);
  v80 = in[1];
  v42 = v41 + __ROL4__(v80 + (v41 ^ b ^ v40) + v39 - 1530992060, 4);
  v75 = in[4];
  v43 = v42 + __ROL4__(v75 + (v42 ^ v41 ^ b) + v40 + 1272893353, 11);
  v44 = __ROL4__(v83 + (v42 ^ v41 ^ v43) + b - 155497632, 16);
  ba = v43 + v44;
  v45 = (v43 + v44) ^ v43;
  v81 = in[10];
  v46 = v43 + v44 + __ROR4__(v81 + (v42 ^ v45) + v41 - 1094730640, 9);
  v76 = in[13];
  v47 = v46 + __ROL4__(v76 + (v46 ^ v45) + v42 + 681279174, 4);
  v48 = v47 + __ROL4__(*in + (v47 ^ v46 ^ ba) + v43 - 358537222, 11);
  v82 = in[3];
  v49 = __ROL4__(v82 + (v47 ^ v46 ^ v48) + ba - 722521979, 16);
  bb = v48 + v49;
  d = (v48 + v49) ^ v48;
  v50 = in[9];
  v51 = v48 + v49 + __ROR4__(in[6] + (v47 ^ d) + v46 + 76029189, 9);
  v77 = in[6];
  v52 = v51 + __ROL4__(v50 + (v51 ^ d) + v47 - 640364487, 4);
  da = in[12];
  v78 = in[15];
  v53 = v52 + __ROL4__(da + (v52 ^ v51 ^ (v48 + v49)) + v48 - 421815835, 11);
  v54 = v53 + __ROL4__(v78 + (v52 ^ v51 ^ v53) + bb + 530742520, 16);
  v55 = v54 + __ROR4__(v84 + (v52 ^ v54 ^ v53) + v51 - 995338651, 9);
  v56 = v55 + __ROL4__(*in + (v54 ^ (v55 | ~v53)) + v52 - 198630844, 6);
  v57 = v56 + __ROL4__(v83 + (v55 ^ (v56 | ~v54)) + v53 + 1126891415, 10);
  v58 = v57 + __ROL4__(in[14] + (v56 ^ (v57 | ~v55)) + v54 - 1416354905, 15);
  v59 = v58 + __ROR4__(in[5] + (v57 ^ (v58 | ~v56)) + v55 - 57434055, 11);
  v60 = v59 + __ROL4__(da + (v58 ^ (v59 | ~v57)) + v56 + 1700485571, 6);
  v61 = v60 + __ROL4__(v82 + (v59 ^ (v60 | ~v58)) + v57 - 1894986606, 10);
  v62 = v61 + __ROL4__(v81 + (v60 ^ (v61 | ~v59)) + v58 - 1051523, 15);
  v63 = v62 + __ROR4__(v80 + (v61 ^ (v62 | ~v60)) + v59 - 2054922799, 11);
  v64 = v63 + __ROL4__(v79 + (v62 ^ (v63 | ~v61)) + v60 + 1873313359, 6);
  v65 = v64 + __ROL4__(v78 + (v63 ^ (v64 | ~v62)) + v61 - 30611744, 10);
  v66 = v65 + __ROL4__(v77 + (v64 ^ (v65 | ~v63)) + v62 - 1560198380, 15);
  v67 = v66 + __ROR4__(v76 + (v65 ^ (v66 | ~v64)) + v63 + 1309151649, 11);
  v68 = v67 + __ROL4__(v75 + (v66 ^ (v67 | ~v65)) + v64 - 145523070, 6);
  v69 = v68 + __ROL4__(v74 + (v67 ^ (v68 | ~v66)) + v65 - 1120210379, 10);
  v70 = v69 + __ROL4__(v84 + (v68 ^ (v69 | ~v67)) + v66 + 718787259, 15);
  v71 = v50 + (v69 ^ (v70 | ~v68)) + v67 - 343485551;
  v72 = v68 + *buf;
  buf[1] += v70 + __ROR4__(v71, 11);
  v73 = v70 + buf[2];
  *buf = v72;
  buf[2] = v73;
  buf[3] += v69;
}

//------------------------------------------------------------------------------
// Address: 0x10276660
// Name: void MD5Init(struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Init(MD5Context_t *ctx)
{
  ctx->buf[0] = 1732584193;
  ctx->buf[1] = -271733879;
  ctx->buf[2] = -1732584194;
  ctx->buf[3] = 271733878;
  ctx->bits[0] = 0;
  ctx->bits[1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10276690
// Name: void MD5Update(struct MD5Context_t __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Update(MD5Context_t *ctx, unsigned __int8 *buf, unsigned int len)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // esi
  MD5Context_t *ctxa; // [esp+14h] [ebp+8h]

  v4 = ctx->bits[0];
  v5 = len;
  v6 = v4 + 8 * len;
  ctx->bits[0] = v6;
  if ( v6 < v4 )
    ++ctx->bits[1];
  ctx->bits[1] += len >> 29;
  v7 = (v4 >> 3) & 0x3F;
  if ( v7 != 0 )
  {
    v8 = 64 - v7;
    if ( len < 64 - v7 )
    {
      memcpy(dst: &ctx->in[v7], src: buf, count: len);
      return;
    }
    memcpy(dst: &ctx->in[v7], src: buf, count: v8);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    buf += v8;
    v5 = len - v8;
    len -= v8;
  }
  if ( v5 >= 0x40 )
  {
    ctxa = (MD5Context_t *)(v5 >> 6);
    do
    {
      qmemcpy(ctx->in, buf, sizeof(ctx->in));
      MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
      buf += 64;
      len -= 64;
      ctxa = (MD5Context_t *)((char *)ctxa - 1);
    }
    while ( ctxa != nullptr );
    v5 = len;
  }
  memcpy(dst: ctx->in, src: buf, count: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10276750
// Name: void MD5Final(unsigned char __near * const,struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Final(unsigned __int8 *digest, MD5Context_t *ctx)
{
  unsigned int v2; // eax
  unsigned __int8 *v3; // edx
  unsigned int v4; // ecx

  v2 = (ctx->bits[0] >> 3) & 0x3F;
  ctx->in[v2] = 0x80;
  v3 = &ctx->in[v2 + 1];
  if ( 63 - v2 >= 8 )
  {
    memset(dst: v3, value: 0, count: 63 - v2 - 8);
  }
  else
  {
    memset(dst: v3, value: 0, count: 63 - v2);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    memset(dst: ctx->in, value: 0, count: 0x38u);
  }
  v4 = ctx->bits[1];
  *(_DWORD *)&ctx->in[56] = ctx->bits[0];
  *(_DWORD *)&ctx->in[60] = v4;
  MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
  *(_QWORD *)digest = *(_QWORD *)ctx->buf;
  *((_QWORD *)digest + 1) = *(_QWORD *)&ctx->buf[2];
  ctx->buf[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102767E0
// Name: char __near * MD5_Print(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MD5_Print(unsigned __int8 *hash, int hashlen)
{
  V_binarytohex(in: hash, inputbytes: hashlen, out: szReturn, outsize: 64);
  return szReturn;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from newdat (Missing functions)
// ============================================================
namespace newdat {

//------------------------------------------------------------------------------
// Address: 0x004012E0
// Name: MD5Transform
// Source: json
//------------------------------------------------------------------------------
void __usercall MD5Transform(const unsigned int *in@<eax>, unsigned int *buf)
{
  unsigned int v2; // edx
  unsigned int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // esi
  int v16; // edi
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edi
  int v21; // ecx
  int v22; // edx
  unsigned int v23; // esi
  int v24; // edx
  int v25; // esi
  int v26; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // esi
  int v30; // edi
  int v31; // ecx
  int v32; // edx
  int v33; // esi
  int v34; // edi
  int v35; // ecx
  int v36; // edx
  int v37; // esi
  int v38; // edi
  int v39; // ecx
  int v40; // edx
  unsigned int v41; // edi
  unsigned int v42; // ecx
  unsigned int v43; // esi
  int v44; // edx
  int v45; // ebx
  int v46; // edx
  int v47; // ecx
  int v48; // esi
  int v49; // edi
  unsigned int v50; // ebx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // edx
  int v56; // ecx
  int v57; // esi
  int v58; // edi
  int v59; // eax
  int v60; // ecx
  int v61; // edx
  int v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // esi
  int v67; // eax
  int v68; // ecx
  int v69; // edx
  int v70; // esi
  int v71; // edi
  unsigned int v72; // ebx
  unsigned int v73; // ecx
  unsigned int v74; // [esp+10h] [ebp-40h]
  unsigned int v75; // [esp+14h] [ebp-3Ch]
  unsigned int v76; // [esp+18h] [ebp-38h]
  unsigned int v77; // [esp+1Ch] [ebp-34h]
  unsigned int v78; // [esp+20h] [ebp-30h]
  unsigned int v79; // [esp+24h] [ebp-2Ch]
  unsigned int v80; // [esp+28h] [ebp-28h]
  unsigned int v81; // [esp+2Ch] [ebp-24h]
  unsigned int v82; // [esp+30h] [ebp-20h]
  unsigned int v83; // [esp+3Ch] [ebp-14h]
  unsigned int v84; // [esp+44h] [ebp-Ch]
  unsigned int d; // [esp+48h] [ebp-8h]
  unsigned int da; // [esp+48h] [ebp-8h]
  unsigned int b; // [esp+4Ch] [ebp-4h]
  unsigned int ba; // [esp+4Ch] [ebp-4h]
  unsigned int bb; // [esp+4Ch] [ebp-4h]

  v2 = buf[3];
  v3 = buf[1];
  v4 = buf[2];
  v5 = v3 + __ROL4__(*in + (v2 ^ v3 & (v4 ^ v2)) + *buf - 680876936, 7);
  v6 = v5 + __ROL4__(in[1] + (v4 ^ v5 & (v3 ^ v4)) + v2 - 389564586, 12);
  v7 = v6 + __ROR4__(in[2] + (v3 ^ v6 & (v5 ^ v3)) + v4 + 606105819, 15);
  v8 = v7 + __ROR4__(in[3] + (v5 ^ v7 & (v5 ^ v6)) + buf[1] - 1044525330, 10);
  v9 = v8 + __ROL4__(in[4] + (v6 ^ v8 & (v7 ^ v6)) + v5 - 176418897, 7);
  v10 = v9 + __ROL4__(in[5] + (v7 ^ v9 & (v8 ^ v7)) + v6 + 1200080426, 12);
  v11 = v10 + __ROR4__(in[6] + (v8 ^ v10 & (v9 ^ v8)) + v7 - 1473231341, 15);
  v83 = in[7];
  v12 = v11 + __ROR4__(v83 + (v9 ^ v11 & (v9 ^ v10)) + v8 - 45705983, 10);
  v13 = v12 + __ROL4__(in[8] + (v10 ^ v12 & (v11 ^ v10)) + v9 + 1770035416, 7);
  v14 = v13 + __ROL4__(in[9] + (v11 ^ v13 & (v12 ^ v11)) + v10 - 1958414417, 12);
  v15 = v14 + __ROR4__(in[10] + (v12 ^ v14 & (v13 ^ v12)) + v11 - 42063, 15);
  v16 = v15 + __ROR4__(in[11] + (v13 ^ v15 & (v13 ^ v14)) + v12 - 1990404162, 10);
  v17 = v16 + __ROL4__(in[12] + (v14 ^ v16 & (v15 ^ v14)) + v13 + 1804603682, 7);
  v18 = v17 + __ROL4__(in[13] + (v15 ^ v17 & (v16 ^ v15)) + v14 - 40341101, 12);
  v19 = v18 + __ROR4__(in[14] + (v16 ^ v18 & (v17 ^ v16)) + v15 - 1502002290, 15);
  v20 = v19 + __ROR4__(in[15] + (v17 ^ v19 & (v17 ^ v18)) + v16 + 1236535329, 10);
  v21 = v20 + __ROL4__(in[1] + (v19 ^ v18 & (v20 ^ v19)) + v17 - 165796510, 5);
  v22 = __ROL4__(in[6] + (v20 ^ v19 & (v21 ^ v20)) + v18 - 1069501632, 9);
  v23 = in[11] + (v21 ^ v20 & (v21 ^ (v21 + v22))) + v19 + 643717713;
  v24 = v21 + v22;
  v25 = v24 + __ROL4__(v23, 14);
  v26 = v25 + __ROR4__(*in + (v24 ^ v21 & (v25 ^ v24)) + v20 - 373897302, 12);
  v27 = v26 + __ROL4__(in[5] + (v25 ^ v24 & (v26 ^ v25)) + v21 - 701558691, 5);
  v28 = v27 + __ROL4__(in[10] + (v26 ^ v25 & (v27 ^ v26)) + v24 + 38016083, 9);
  v29 = v28 + __ROL4__(in[15] + (v27 ^ v26 & (v27 ^ v28)) + v25 - 660478335, 14);
  v30 = v29 + __ROR4__(in[4] + (v28 ^ v27 & (v29 ^ v28)) + v26 - 405537848, 12);
  v31 = v30 + __ROL4__(in[9] + (v29 ^ v28 & (v30 ^ v29)) + v27 + 568446438, 5);
  v32 = v31 + __ROL4__(in[14] + (v30 ^ v29 & (v31 ^ v30)) + v28 - 1019803690, 9);
  v33 = v32 + __ROL4__(in[3] + (v31 ^ v30 & (v31 ^ v32)) + v29 - 187363961, 14);
  v34 = v33 + __ROR4__(in[8] + (v32 ^ v31 & (v33 ^ v32)) + v30 + 1163531501, 12);
  v35 = v34 + __ROL4__(in[13] + (v33 ^ v32 & (v34 ^ v33)) + v31 - 1444681467, 5);
  v36 = v35 + __ROL4__(in[2] + (v34 ^ v33 & (v35 ^ v34)) + v32 - 51403784, 9);
  v84 = in[2];
  v37 = v36 + __ROL4__(v83 + (v35 ^ v34 & (v35 ^ v36)) + v33 + 1735328473, 14);
  v38 = v37 + __ROR4__(in[12] + (v36 ^ v35 & (v37 ^ v36)) + v34 - 1926607734, 12);
  v39 = v38 + __ROL4__(in[5] + (v38 ^ v37 ^ v36) + v35 - 378558, 4);
  v40 = v39 + __ROL4__(in[8] + (v39 ^ v38 ^ v37) + v36 - 2022574463, 11);
  v79 = in[8];
  v74 = in[11];
  b = v40 + __ROL4__(v74 + (v39 ^ v38 ^ v40) + v37 + 1839030562, 16);
  v41 = b + __ROR4__(in[14] + (v39 ^ b ^ v40) + v38 - 35309556, 9);
  v80 = in[1];
  v42 = v41 + __ROL4__(v80 + (v41 ^ b ^ v40) + v39 - 1530992060, 4);
  v75 = in[4];
  v43 = v42 + __ROL4__(v75 + (v42 ^ v41 ^ b) + v40 + 1272893353, 11);
  v44 = __ROL4__(v83 + (v42 ^ v41 ^ v43) + b - 155497632, 16);
  ba = v43 + v44;
  v45 = (v43 + v44) ^ v43;
  v81 = in[10];
  v46 = v43 + v44 + __ROR4__(v81 + (v42 ^ v45) + v41 - 1094730640, 9);
  v76 = in[13];
  v47 = v46 + __ROL4__(v76 + (v46 ^ v45) + v42 + 681279174, 4);
  v48 = v47 + __ROL4__(*in + (v47 ^ v46 ^ ba) + v43 - 358537222, 11);
  v82 = in[3];
  v49 = __ROL4__(v82 + (v47 ^ v46 ^ v48) + ba - 722521979, 16);
  bb = v48 + v49;
  d = (v48 + v49) ^ v48;
  v50 = in[9];
  v51 = v48 + v49 + __ROR4__(in[6] + (v47 ^ d) + v46 + 76029189, 9);
  v77 = in[6];
  v52 = v51 + __ROL4__(v50 + (v51 ^ d) + v47 - 640364487, 4);
  da = in[12];
  v78 = in[15];
  v53 = v52 + __ROL4__(da + (v52 ^ v51 ^ (v48 + v49)) + v48 - 421815835, 11);
  v54 = v53 + __ROL4__(v78 + (v52 ^ v51 ^ v53) + bb + 530742520, 16);
  v55 = v54 + __ROR4__(v84 + (v52 ^ v54 ^ v53) + v51 - 995338651, 9);
  v56 = v55 + __ROL4__(*in + (v54 ^ (v55 | ~v53)) + v52 - 198630844, 6);
  v57 = v56 + __ROL4__(v83 + (v55 ^ (v56 | ~v54)) + v53 + 1126891415, 10);
  v58 = v57 + __ROL4__(in[14] + (v56 ^ (v57 | ~v55)) + v54 - 1416354905, 15);
  v59 = v58 + __ROR4__(in[5] + (v57 ^ (v58 | ~v56)) + v55 - 57434055, 11);
  v60 = v59 + __ROL4__(da + (v58 ^ (v59 | ~v57)) + v56 + 1700485571, 6);
  v61 = v60 + __ROL4__(v82 + (v59 ^ (v60 | ~v58)) + v57 - 1894986606, 10);
  v62 = v61 + __ROL4__(v81 + (v60 ^ (v61 | ~v59)) + v58 - 1051523, 15);
  v63 = v62 + __ROR4__(v80 + (v61 ^ (v62 | ~v60)) + v59 - 2054922799, 11);
  v64 = v63 + __ROL4__(v79 + (v62 ^ (v63 | ~v61)) + v60 + 1873313359, 6);
  v65 = v64 + __ROL4__(v78 + (v63 ^ (v64 | ~v62)) + v61 - 30611744, 10);
  v66 = v65 + __ROL4__(v77 + (v64 ^ (v65 | ~v63)) + v62 - 1560198380, 15);
  v67 = v66 + __ROR4__(v76 + (v65 ^ (v66 | ~v64)) + v63 + 1309151649, 11);
  v68 = v67 + __ROL4__(v75 + (v66 ^ (v67 | ~v65)) + v64 - 145523070, 6);
  v69 = v68 + __ROL4__(v74 + (v67 ^ (v68 | ~v66)) + v65 - 1120210379, 10);
  v70 = v69 + __ROL4__(v84 + (v68 ^ (v69 | ~v67)) + v66 + 718787259, 15);
  v71 = v50 + (v69 ^ (v70 | ~v68)) + v67 - 343485551;
  v72 = v68 + *buf;
  buf[1] += v70 + __ROR4__(v71, 11);
  v73 = v70 + buf[2];
  *buf = v72;
  buf[2] = v73;
  buf[3] += v69;
}

//------------------------------------------------------------------------------
// Address: 0x00401960
// Name: void MD5Init(struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Init(MD5Context_t *ctx)
{
  ctx->buf[0] = 1732584193;
  ctx->buf[1] = -271733879;
  ctx->buf[2] = -1732584194;
  ctx->buf[3] = 271733878;
  ctx->bits[0] = 0;
  ctx->bits[1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401990
// Name: void MD5Update(struct MD5Context_t __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Update(MD5Context_t *ctx, unsigned __int8 *buf, unsigned int len)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // esi
  MD5Context_t *ctxa; // [esp+14h] [ebp+8h]

  v4 = ctx->bits[0];
  v5 = len;
  v6 = v4 + 8 * len;
  ctx->bits[0] = v6;
  if ( v6 < v4 )
    ++ctx->bits[1];
  ctx->bits[1] += len >> 29;
  v7 = (v4 >> 3) & 0x3F;
  if ( v7 != 0 )
  {
    v8 = 64 - v7;
    if ( len < 64 - v7 )
    {
      memcpy(dst: &ctx->in[v7], src: buf, count: len);
      return;
    }
    memcpy(dst: &ctx->in[v7], src: buf, count: v8);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    buf += v8;
    v5 = len - v8;
    len -= v8;
  }
  if ( v5 >= 0x40 )
  {
    ctxa = (MD5Context_t *)(v5 >> 6);
    do
    {
      qmemcpy(ctx->in, buf, sizeof(ctx->in));
      MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
      buf += 64;
      len -= 64;
      ctxa = (MD5Context_t *)((char *)ctxa - 1);
    }
    while ( ctxa != nullptr );
    v5 = len;
  }
  memcpy(dst: ctx->in, src: buf, count: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00401A50
// Name: void MD5Final(unsigned char __near * const,struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Final(unsigned __int8 *digest, MD5Context_t *ctx)
{
  unsigned int v2; // eax
  unsigned __int8 *v3; // edx
  unsigned int v4; // ecx

  v2 = (ctx->bits[0] >> 3) & 0x3F;
  ctx->in[v2] = 0x80;
  v3 = &ctx->in[v2 + 1];
  if ( 63 - v2 >= 8 )
  {
    memset(dst: v3, value: 0, count: 63 - v2 - 8);
  }
  else
  {
    memset(dst: v3, value: 0, count: 63 - v2);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    memset(dst: ctx->in, value: 0, count: 0x38u);
  }
  v4 = ctx->bits[1];
  *(_DWORD *)&ctx->in[56] = ctx->bits[0];
  *(_DWORD *)&ctx->in[60] = v4;
  MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
  *(_QWORD *)digest = *(_QWORD *)ctx->buf;
  *((_QWORD *)digest + 1) = *(_QWORD *)&ctx->buf[2];
  ctx->buf[0] = 0;
}

} // namespace newdat

// ============================================================
// Overlay from stdshader_dbg (Missing functions)
// ============================================================
namespace stdshader_dbg {

//------------------------------------------------------------------------------
// Address: 0x10004A80
// Name: MD5Transform
// Source: json
//------------------------------------------------------------------------------
void __usercall MD5Transform(const unsigned int *in@<eax>, unsigned int *buf)
{
  unsigned int v2; // edx
  unsigned int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // esi
  int v16; // edi
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edi
  int v21; // ecx
  int v22; // edx
  unsigned int v23; // esi
  int v24; // edx
  int v25; // esi
  int v26; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // esi
  int v30; // edi
  int v31; // ecx
  int v32; // edx
  int v33; // esi
  int v34; // edi
  int v35; // ecx
  int v36; // edx
  int v37; // esi
  int v38; // edi
  int v39; // ecx
  int v40; // edx
  unsigned int v41; // edi
  unsigned int v42; // ecx
  unsigned int v43; // esi
  int v44; // edx
  int v45; // ebx
  int v46; // edx
  int v47; // ecx
  int v48; // esi
  int v49; // edi
  unsigned int v50; // ebx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // edx
  int v56; // ecx
  int v57; // esi
  int v58; // edi
  int v59; // eax
  int v60; // ecx
  int v61; // edx
  int v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // esi
  int v67; // eax
  int v68; // ecx
  int v69; // edx
  int v70; // esi
  int v71; // edi
  unsigned int v72; // ebx
  unsigned int v73; // ecx
  unsigned int v74; // [esp+10h] [ebp-40h]
  unsigned int v75; // [esp+14h] [ebp-3Ch]
  unsigned int v76; // [esp+18h] [ebp-38h]
  unsigned int v77; // [esp+1Ch] [ebp-34h]
  unsigned int v78; // [esp+20h] [ebp-30h]
  unsigned int v79; // [esp+24h] [ebp-2Ch]
  unsigned int v80; // [esp+28h] [ebp-28h]
  unsigned int v81; // [esp+2Ch] [ebp-24h]
  unsigned int v82; // [esp+30h] [ebp-20h]
  unsigned int v83; // [esp+3Ch] [ebp-14h]
  unsigned int v84; // [esp+44h] [ebp-Ch]
  unsigned int d; // [esp+48h] [ebp-8h]
  unsigned int da; // [esp+48h] [ebp-8h]
  unsigned int b; // [esp+4Ch] [ebp-4h]
  unsigned int ba; // [esp+4Ch] [ebp-4h]
  unsigned int bb; // [esp+4Ch] [ebp-4h]

  v2 = buf[3];
  v3 = buf[1];
  v4 = buf[2];
  v5 = v3 + __ROL4__(*in + (v2 ^ v3 & (v4 ^ v2)) + *buf - 680876936, 7);
  v6 = v5 + __ROL4__(in[1] + (v4 ^ v5 & (v3 ^ v4)) + v2 - 389564586, 12);
  v7 = v6 + __ROR4__(in[2] + (v3 ^ v6 & (v5 ^ v3)) + v4 + 606105819, 15);
  v8 = v7 + __ROR4__(in[3] + (v5 ^ v7 & (v5 ^ v6)) + buf[1] - 1044525330, 10);
  v9 = v8 + __ROL4__(in[4] + (v6 ^ v8 & (v7 ^ v6)) + v5 - 176418897, 7);
  v10 = v9 + __ROL4__(in[5] + (v7 ^ v9 & (v8 ^ v7)) + v6 + 1200080426, 12);
  v11 = v10 + __ROR4__(in[6] + (v8 ^ v10 & (v9 ^ v8)) + v7 - 1473231341, 15);
  v83 = in[7];
  v12 = v11 + __ROR4__(v83 + (v9 ^ v11 & (v9 ^ v10)) + v8 - 45705983, 10);
  v13 = v12 + __ROL4__(in[8] + (v10 ^ v12 & (v11 ^ v10)) + v9 + 1770035416, 7);
  v14 = v13 + __ROL4__(in[9] + (v11 ^ v13 & (v12 ^ v11)) + v10 - 1958414417, 12);
  v15 = v14 + __ROR4__(in[10] + (v12 ^ v14 & (v13 ^ v12)) + v11 - 42063, 15);
  v16 = v15 + __ROR4__(in[11] + (v13 ^ v15 & (v13 ^ v14)) + v12 - 1990404162, 10);
  v17 = v16 + __ROL4__(in[12] + (v14 ^ v16 & (v15 ^ v14)) + v13 + 1804603682, 7);
  v18 = v17 + __ROL4__(in[13] + (v15 ^ v17 & (v16 ^ v15)) + v14 - 40341101, 12);
  v19 = v18 + __ROR4__(in[14] + (v16 ^ v18 & (v17 ^ v16)) + v15 - 1502002290, 15);
  v20 = v19 + __ROR4__(in[15] + (v17 ^ v19 & (v17 ^ v18)) + v16 + 1236535329, 10);
  v21 = v20 + __ROL4__(in[1] + (v19 ^ v18 & (v20 ^ v19)) + v17 - 165796510, 5);
  v22 = __ROL4__(in[6] + (v20 ^ v19 & (v21 ^ v20)) + v18 - 1069501632, 9);
  v23 = in[11] + (v21 ^ v20 & (v21 ^ (v21 + v22))) + v19 + 643717713;
  v24 = v21 + v22;
  v25 = v24 + __ROL4__(v23, 14);
  v26 = v25 + __ROR4__(*in + (v24 ^ v21 & (v25 ^ v24)) + v20 - 373897302, 12);
  v27 = v26 + __ROL4__(in[5] + (v25 ^ v24 & (v26 ^ v25)) + v21 - 701558691, 5);
  v28 = v27 + __ROL4__(in[10] + (v26 ^ v25 & (v27 ^ v26)) + v24 + 38016083, 9);
  v29 = v28 + __ROL4__(in[15] + (v27 ^ v26 & (v27 ^ v28)) + v25 - 660478335, 14);
  v30 = v29 + __ROR4__(in[4] + (v28 ^ v27 & (v29 ^ v28)) + v26 - 405537848, 12);
  v31 = v30 + __ROL4__(in[9] + (v29 ^ v28 & (v30 ^ v29)) + v27 + 568446438, 5);
  v32 = v31 + __ROL4__(in[14] + (v30 ^ v29 & (v31 ^ v30)) + v28 - 1019803690, 9);
  v33 = v32 + __ROL4__(in[3] + (v31 ^ v30 & (v31 ^ v32)) + v29 - 187363961, 14);
  v34 = v33 + __ROR4__(in[8] + (v32 ^ v31 & (v33 ^ v32)) + v30 + 1163531501, 12);
  v35 = v34 + __ROL4__(in[13] + (v33 ^ v32 & (v34 ^ v33)) + v31 - 1444681467, 5);
  v36 = v35 + __ROL4__(in[2] + (v34 ^ v33 & (v35 ^ v34)) + v32 - 51403784, 9);
  v84 = in[2];
  v37 = v36 + __ROL4__(v83 + (v35 ^ v34 & (v35 ^ v36)) + v33 + 1735328473, 14);
  v38 = v37 + __ROR4__(in[12] + (v36 ^ v35 & (v37 ^ v36)) + v34 - 1926607734, 12);
  v39 = v38 + __ROL4__(in[5] + (v38 ^ v37 ^ v36) + v35 - 378558, 4);
  v40 = v39 + __ROL4__(in[8] + (v39 ^ v38 ^ v37) + v36 - 2022574463, 11);
  v79 = in[8];
  v74 = in[11];
  b = v40 + __ROL4__(v74 + (v39 ^ v38 ^ v40) + v37 + 1839030562, 16);
  v41 = b + __ROR4__(in[14] + (v39 ^ b ^ v40) + v38 - 35309556, 9);
  v80 = in[1];
  v42 = v41 + __ROL4__(v80 + (v41 ^ b ^ v40) + v39 - 1530992060, 4);
  v75 = in[4];
  v43 = v42 + __ROL4__(v75 + (v42 ^ v41 ^ b) + v40 + 1272893353, 11);
  v44 = __ROL4__(v83 + (v42 ^ v41 ^ v43) + b - 155497632, 16);
  ba = v43 + v44;
  v45 = (v43 + v44) ^ v43;
  v81 = in[10];
  v46 = v43 + v44 + __ROR4__(v81 + (v42 ^ v45) + v41 - 1094730640, 9);
  v76 = in[13];
  v47 = v46 + __ROL4__(v76 + (v46 ^ v45) + v42 + 681279174, 4);
  v48 = v47 + __ROL4__(*in + (v47 ^ v46 ^ ba) + v43 - 358537222, 11);
  v82 = in[3];
  v49 = __ROL4__(v82 + (v47 ^ v46 ^ v48) + ba - 722521979, 16);
  bb = v48 + v49;
  d = (v48 + v49) ^ v48;
  v50 = in[9];
  v51 = v48 + v49 + __ROR4__(in[6] + (v47 ^ d) + v46 + 76029189, 9);
  v77 = in[6];
  v52 = v51 + __ROL4__(v50 + (v51 ^ d) + v47 - 640364487, 4);
  da = in[12];
  v78 = in[15];
  v53 = v52 + __ROL4__(da + (v52 ^ v51 ^ (v48 + v49)) + v48 - 421815835, 11);
  v54 = v53 + __ROL4__(v78 + (v52 ^ v51 ^ v53) + bb + 530742520, 16);
  v55 = v54 + __ROR4__(v84 + (v52 ^ v54 ^ v53) + v51 - 995338651, 9);
  v56 = v55 + __ROL4__(*in + (v54 ^ (v55 | ~v53)) + v52 - 198630844, 6);
  v57 = v56 + __ROL4__(v83 + (v55 ^ (v56 | ~v54)) + v53 + 1126891415, 10);
  v58 = v57 + __ROL4__(in[14] + (v56 ^ (v57 | ~v55)) + v54 - 1416354905, 15);
  v59 = v58 + __ROR4__(in[5] + (v57 ^ (v58 | ~v56)) + v55 - 57434055, 11);
  v60 = v59 + __ROL4__(da + (v58 ^ (v59 | ~v57)) + v56 + 1700485571, 6);
  v61 = v60 + __ROL4__(v82 + (v59 ^ (v60 | ~v58)) + v57 - 1894986606, 10);
  v62 = v61 + __ROL4__(v81 + (v60 ^ (v61 | ~v59)) + v58 - 1051523, 15);
  v63 = v62 + __ROR4__(v80 + (v61 ^ (v62 | ~v60)) + v59 - 2054922799, 11);
  v64 = v63 + __ROL4__(v79 + (v62 ^ (v63 | ~v61)) + v60 + 1873313359, 6);
  v65 = v64 + __ROL4__(v78 + (v63 ^ (v64 | ~v62)) + v61 - 30611744, 10);
  v66 = v65 + __ROL4__(v77 + (v64 ^ (v65 | ~v63)) + v62 - 1560198380, 15);
  v67 = v66 + __ROR4__(v76 + (v65 ^ (v66 | ~v64)) + v63 + 1309151649, 11);
  v68 = v67 + __ROL4__(v75 + (v66 ^ (v67 | ~v65)) + v64 - 145523070, 6);
  v69 = v68 + __ROL4__(v74 + (v67 ^ (v68 | ~v66)) + v65 - 1120210379, 10);
  v70 = v69 + __ROL4__(v84 + (v68 ^ (v69 | ~v67)) + v66 + 718787259, 15);
  v71 = v50 + (v69 ^ (v70 | ~v68)) + v67 - 343485551;
  v72 = v68 + *buf;
  buf[1] += v70 + __ROR4__(v71, 11);
  v73 = v70 + buf[2];
  *buf = v72;
  buf[2] = v73;
  buf[3] += v69;
}

//------------------------------------------------------------------------------
// Address: 0x10005100
// Name: void MD5Init(struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Init(MD5Context_t *ctx)
{
  ctx->buf[0] = 1732584193;
  ctx->buf[1] = -271733879;
  ctx->buf[2] = -1732584194;
  ctx->buf[3] = 271733878;
  ctx->bits[0] = 0;
  ctx->bits[1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10005130
// Name: void MD5Update(struct MD5Context_t __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Update(MD5Context_t *ctx, unsigned __int8 *buf, unsigned int len)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // esi
  MD5Context_t *ctxa; // [esp+14h] [ebp+8h]

  v4 = ctx->bits[0];
  v5 = len;
  v6 = v4 + 8 * len;
  ctx->bits[0] = v6;
  if ( v6 < v4 )
    ++ctx->bits[1];
  ctx->bits[1] += len >> 29;
  v7 = (v4 >> 3) & 0x3F;
  if ( v7 != 0 )
  {
    v8 = 64 - v7;
    if ( len < 64 - v7 )
    {
      memcpy(dst: &ctx->in[v7], src: buf, count: len);
      return;
    }
    memcpy(dst: &ctx->in[v7], src: buf, count: v8);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    buf += v8;
    v5 = len - v8;
    len -= v8;
  }
  if ( v5 >= 0x40 )
  {
    ctxa = (MD5Context_t *)(v5 >> 6);
    do
    {
      qmemcpy(ctx->in, buf, sizeof(ctx->in));
      MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
      buf += 64;
      len -= 64;
      ctxa = (MD5Context_t *)((char *)ctxa - 1);
    }
    while ( ctxa != nullptr );
    v5 = len;
  }
  memcpy(dst: ctx->in, src: buf, count: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100051F0
// Name: void MD5Final(unsigned char __near * const,struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Final(unsigned __int8 *digest, MD5Context_t *ctx)
{
  unsigned int v2; // eax
  unsigned __int8 *v3; // edx
  unsigned int v4; // ecx

  v2 = (ctx->bits[0] >> 3) & 0x3F;
  ctx->in[v2] = 0x80;
  v3 = &ctx->in[v2 + 1];
  if ( 63 - v2 >= 8 )
  {
    memset(dst: v3, value: 0, count: 63 - v2 - 8);
  }
  else
  {
    memset(dst: v3, value: 0, count: 63 - v2);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    memset(dst: ctx->in, value: 0, count: 0x38u);
  }
  v4 = ctx->bits[1];
  *(_DWORD *)&ctx->in[56] = ctx->bits[0];
  *(_DWORD *)&ctx->in[60] = v4;
  MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
  *(_QWORD *)digest = *(_QWORD *)ctx->buf;
  *((_QWORD *)digest + 1) = *(_QWORD *)&ctx->buf[2];
  ctx->buf[0] = 0;
}

} // namespace stdshader_dbg

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x10047440
// Name: MD5Transform
// Source: json
//------------------------------------------------------------------------------
void __usercall MD5Transform(const unsigned int *in@<eax>, unsigned int *buf)
{
  unsigned int v2; // edx
  unsigned int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // esi
  int v16; // edi
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edi
  int v21; // ecx
  int v22; // edx
  unsigned int v23; // esi
  int v24; // edx
  int v25; // esi
  int v26; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // esi
  int v30; // edi
  int v31; // ecx
  int v32; // edx
  int v33; // esi
  int v34; // edi
  int v35; // ecx
  int v36; // edx
  int v37; // esi
  int v38; // edi
  int v39; // ecx
  int v40; // edx
  unsigned int v41; // edi
  unsigned int v42; // ecx
  unsigned int v43; // esi
  int v44; // edx
  int v45; // ebx
  int v46; // edx
  int v47; // ecx
  int v48; // esi
  int v49; // edi
  unsigned int v50; // ebx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // edx
  int v56; // ecx
  int v57; // esi
  int v58; // edi
  int v59; // eax
  int v60; // ecx
  int v61; // edx
  int v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // esi
  int v67; // eax
  int v68; // ecx
  int v69; // edx
  int v70; // esi
  int v71; // edi
  unsigned int v72; // ebx
  unsigned int v73; // ecx
  unsigned int v74; // [esp+10h] [ebp-40h]
  unsigned int v75; // [esp+14h] [ebp-3Ch]
  unsigned int v76; // [esp+18h] [ebp-38h]
  unsigned int v77; // [esp+1Ch] [ebp-34h]
  unsigned int v78; // [esp+20h] [ebp-30h]
  unsigned int v79; // [esp+24h] [ebp-2Ch]
  unsigned int v80; // [esp+28h] [ebp-28h]
  unsigned int v81; // [esp+2Ch] [ebp-24h]
  unsigned int v82; // [esp+30h] [ebp-20h]
  unsigned int v83; // [esp+3Ch] [ebp-14h]
  unsigned int v84; // [esp+44h] [ebp-Ch]
  unsigned int d; // [esp+48h] [ebp-8h]
  unsigned int da; // [esp+48h] [ebp-8h]
  unsigned int b; // [esp+4Ch] [ebp-4h]
  unsigned int ba; // [esp+4Ch] [ebp-4h]
  unsigned int bb; // [esp+4Ch] [ebp-4h]

  v2 = buf[3];
  v3 = buf[1];
  v4 = buf[2];
  v5 = v3 + __ROL4__(*in + (v2 ^ v3 & (v4 ^ v2)) + *buf - 680876936, 7);
  v6 = v5 + __ROL4__(in[1] + (v4 ^ v5 & (v3 ^ v4)) + v2 - 389564586, 12);
  v7 = v6 + __ROR4__(in[2] + (v3 ^ v6 & (v5 ^ v3)) + v4 + 606105819, 15);
  v8 = v7 + __ROR4__(in[3] + (v5 ^ v7 & (v5 ^ v6)) + buf[1] - 1044525330, 10);
  v9 = v8 + __ROL4__(in[4] + (v6 ^ v8 & (v7 ^ v6)) + v5 - 176418897, 7);
  v10 = v9 + __ROL4__(in[5] + (v7 ^ v9 & (v8 ^ v7)) + v6 + 1200080426, 12);
  v11 = v10 + __ROR4__(in[6] + (v8 ^ v10 & (v9 ^ v8)) + v7 - 1473231341, 15);
  v83 = in[7];
  v12 = v11 + __ROR4__(v83 + (v9 ^ v11 & (v9 ^ v10)) + v8 - 45705983, 10);
  v13 = v12 + __ROL4__(in[8] + (v10 ^ v12 & (v11 ^ v10)) + v9 + 1770035416, 7);
  v14 = v13 + __ROL4__(in[9] + (v11 ^ v13 & (v12 ^ v11)) + v10 - 1958414417, 12);
  v15 = v14 + __ROR4__(in[10] + (v12 ^ v14 & (v13 ^ v12)) + v11 - 42063, 15);
  v16 = v15 + __ROR4__(in[11] + (v13 ^ v15 & (v13 ^ v14)) + v12 - 1990404162, 10);
  v17 = v16 + __ROL4__(in[12] + (v14 ^ v16 & (v15 ^ v14)) + v13 + 1804603682, 7);
  v18 = v17 + __ROL4__(in[13] + (v15 ^ v17 & (v16 ^ v15)) + v14 - 40341101, 12);
  v19 = v18 + __ROR4__(in[14] + (v16 ^ v18 & (v17 ^ v16)) + v15 - 1502002290, 15);
  v20 = v19 + __ROR4__(in[15] + (v17 ^ v19 & (v17 ^ v18)) + v16 + 1236535329, 10);
  v21 = v20 + __ROL4__(in[1] + (v19 ^ v18 & (v20 ^ v19)) + v17 - 165796510, 5);
  v22 = __ROL4__(in[6] + (v20 ^ v19 & (v21 ^ v20)) + v18 - 1069501632, 9);
  v23 = in[11] + (v21 ^ v20 & (v21 ^ (v21 + v22))) + v19 + 643717713;
  v24 = v21 + v22;
  v25 = v24 + __ROL4__(v23, 14);
  v26 = v25 + __ROR4__(*in + (v24 ^ v21 & (v25 ^ v24)) + v20 - 373897302, 12);
  v27 = v26 + __ROL4__(in[5] + (v25 ^ v24 & (v26 ^ v25)) + v21 - 701558691, 5);
  v28 = v27 + __ROL4__(in[10] + (v26 ^ v25 & (v27 ^ v26)) + v24 + 38016083, 9);
  v29 = v28 + __ROL4__(in[15] + (v27 ^ v26 & (v27 ^ v28)) + v25 - 660478335, 14);
  v30 = v29 + __ROR4__(in[4] + (v28 ^ v27 & (v29 ^ v28)) + v26 - 405537848, 12);
  v31 = v30 + __ROL4__(in[9] + (v29 ^ v28 & (v30 ^ v29)) + v27 + 568446438, 5);
  v32 = v31 + __ROL4__(in[14] + (v30 ^ v29 & (v31 ^ v30)) + v28 - 1019803690, 9);
  v33 = v32 + __ROL4__(in[3] + (v31 ^ v30 & (v31 ^ v32)) + v29 - 187363961, 14);
  v34 = v33 + __ROR4__(in[8] + (v32 ^ v31 & (v33 ^ v32)) + v30 + 1163531501, 12);
  v35 = v34 + __ROL4__(in[13] + (v33 ^ v32 & (v34 ^ v33)) + v31 - 1444681467, 5);
  v36 = v35 + __ROL4__(in[2] + (v34 ^ v33 & (v35 ^ v34)) + v32 - 51403784, 9);
  v84 = in[2];
  v37 = v36 + __ROL4__(v83 + (v35 ^ v34 & (v35 ^ v36)) + v33 + 1735328473, 14);
  v38 = v37 + __ROR4__(in[12] + (v36 ^ v35 & (v37 ^ v36)) + v34 - 1926607734, 12);
  v39 = v38 + __ROL4__(in[5] + (v38 ^ v37 ^ v36) + v35 - 378558, 4);
  v40 = v39 + __ROL4__(in[8] + (v39 ^ v38 ^ v37) + v36 - 2022574463, 11);
  v79 = in[8];
  v74 = in[11];
  b = v40 + __ROL4__(v74 + (v39 ^ v38 ^ v40) + v37 + 1839030562, 16);
  v41 = b + __ROR4__(in[14] + (v39 ^ b ^ v40) + v38 - 35309556, 9);
  v80 = in[1];
  v42 = v41 + __ROL4__(v80 + (v41 ^ b ^ v40) + v39 - 1530992060, 4);
  v75 = in[4];
  v43 = v42 + __ROL4__(v75 + (v42 ^ v41 ^ b) + v40 + 1272893353, 11);
  v44 = __ROL4__(v83 + (v42 ^ v41 ^ v43) + b - 155497632, 16);
  ba = v43 + v44;
  v45 = (v43 + v44) ^ v43;
  v81 = in[10];
  v46 = v43 + v44 + __ROR4__(v81 + (v42 ^ v45) + v41 - 1094730640, 9);
  v76 = in[13];
  v47 = v46 + __ROL4__(v76 + (v46 ^ v45) + v42 + 681279174, 4);
  v48 = v47 + __ROL4__(*in + (v47 ^ v46 ^ ba) + v43 - 358537222, 11);
  v82 = in[3];
  v49 = __ROL4__(v82 + (v47 ^ v46 ^ v48) + ba - 722521979, 16);
  bb = v48 + v49;
  d = (v48 + v49) ^ v48;
  v50 = in[9];
  v51 = v48 + v49 + __ROR4__(in[6] + (v47 ^ d) + v46 + 76029189, 9);
  v77 = in[6];
  v52 = v51 + __ROL4__(v50 + (v51 ^ d) + v47 - 640364487, 4);
  da = in[12];
  v78 = in[15];
  v53 = v52 + __ROL4__(da + (v52 ^ v51 ^ (v48 + v49)) + v48 - 421815835, 11);
  v54 = v53 + __ROL4__(v78 + (v52 ^ v51 ^ v53) + bb + 530742520, 16);
  v55 = v54 + __ROR4__(v84 + (v52 ^ v54 ^ v53) + v51 - 995338651, 9);
  v56 = v55 + __ROL4__(*in + (v54 ^ (v55 | ~v53)) + v52 - 198630844, 6);
  v57 = v56 + __ROL4__(v83 + (v55 ^ (v56 | ~v54)) + v53 + 1126891415, 10);
  v58 = v57 + __ROL4__(in[14] + (v56 ^ (v57 | ~v55)) + v54 - 1416354905, 15);
  v59 = v58 + __ROR4__(in[5] + (v57 ^ (v58 | ~v56)) + v55 - 57434055, 11);
  v60 = v59 + __ROL4__(da + (v58 ^ (v59 | ~v57)) + v56 + 1700485571, 6);
  v61 = v60 + __ROL4__(v82 + (v59 ^ (v60 | ~v58)) + v57 - 1894986606, 10);
  v62 = v61 + __ROL4__(v81 + (v60 ^ (v61 | ~v59)) + v58 - 1051523, 15);
  v63 = v62 + __ROR4__(v80 + (v61 ^ (v62 | ~v60)) + v59 - 2054922799, 11);
  v64 = v63 + __ROL4__(v79 + (v62 ^ (v63 | ~v61)) + v60 + 1873313359, 6);
  v65 = v64 + __ROL4__(v78 + (v63 ^ (v64 | ~v62)) + v61 - 30611744, 10);
  v66 = v65 + __ROL4__(v77 + (v64 ^ (v65 | ~v63)) + v62 - 1560198380, 15);
  v67 = v66 + __ROR4__(v76 + (v65 ^ (v66 | ~v64)) + v63 + 1309151649, 11);
  v68 = v67 + __ROL4__(v75 + (v66 ^ (v67 | ~v65)) + v64 - 145523070, 6);
  v69 = v68 + __ROL4__(v74 + (v67 ^ (v68 | ~v66)) + v65 - 1120210379, 10);
  v70 = v69 + __ROL4__(v84 + (v68 ^ (v69 | ~v67)) + v66 + 718787259, 15);
  v71 = v50 + (v69 ^ (v70 | ~v68)) + v67 - 343485551;
  v72 = v68 + *buf;
  buf[1] += v70 + __ROR4__(v71, 11);
  v73 = v70 + buf[2];
  *buf = v72;
  buf[2] = v73;
  buf[3] += v69;
}

//------------------------------------------------------------------------------
// Address: 0x10047AC0
// Name: void MD5Init(struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Init(MD5Context_t *ctx)
{
  ctx->buf[0] = 1732584193;
  ctx->buf[1] = -271733879;
  ctx->buf[2] = -1732584194;
  ctx->buf[3] = 271733878;
  ctx->bits[0] = 0;
  ctx->bits[1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10047AF0
// Name: void MD5Update(struct MD5Context_t __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Update(MD5Context_t *ctx, unsigned __int8 *buf, unsigned int len)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // esi
  MD5Context_t *ctxa; // [esp+14h] [ebp+8h]

  v4 = ctx->bits[0];
  v5 = len;
  v6 = v4 + 8 * len;
  ctx->bits[0] = v6;
  if ( v6 < v4 )
    ++ctx->bits[1];
  ctx->bits[1] += len >> 29;
  v7 = (v4 >> 3) & 0x3F;
  if ( v7 != 0 )
  {
    v8 = 64 - v7;
    if ( len < 64 - v7 )
    {
      memcpy(dst: &ctx->in[v7], src: buf, count: len);
      return;
    }
    memcpy(dst: &ctx->in[v7], src: buf, count: v8);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    buf += v8;
    v5 = len - v8;
    len -= v8;
  }
  if ( v5 >= 0x40 )
  {
    ctxa = (MD5Context_t *)(v5 >> 6);
    do
    {
      qmemcpy(ctx->in, buf, sizeof(ctx->in));
      MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
      buf += 64;
      len -= 64;
      ctxa = (MD5Context_t *)((char *)ctxa - 1);
    }
    while ( ctxa != nullptr );
    v5 = len;
  }
  memcpy(dst: ctx->in, src: buf, count: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10047BB0
// Name: void MD5Final(unsigned char __near * const,struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Final(unsigned __int8 *digest, MD5Context_t *ctx)
{
  unsigned int v2; // eax
  unsigned __int8 *v3; // edx
  unsigned int v4; // ecx

  v2 = (ctx->bits[0] >> 3) & 0x3F;
  ctx->in[v2] = 0x80;
  v3 = &ctx->in[v2 + 1];
  if ( 63 - v2 >= 8 )
  {
    memset(dst: v3, value: 0, count: 63 - v2 - 8);
  }
  else
  {
    memset(dst: v3, value: 0, count: 63 - v2);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    memset(dst: ctx->in, value: 0, count: 0x38u);
  }
  v4 = ctx->bits[1];
  *(_DWORD *)&ctx->in[56] = ctx->bits[0];
  *(_DWORD *)&ctx->in[60] = v4;
  MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
  *(_QWORD *)digest = *(_QWORD *)ctx->buf;
  *((_QWORD *)digest + 1) = *(_QWORD *)&ctx->buf[2];
  ctx->buf[0] = 0;
}

} // namespace stdshader_dx9

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1036D0C0
// Name: MD5Transform
// Source: json
//------------------------------------------------------------------------------
void __usercall MD5Transform(const unsigned int *in@<eax>, unsigned int *buf)
{
  unsigned int v2; // edx
  unsigned int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // esi
  int v16; // edi
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edi
  int v21; // ecx
  int v22; // edx
  unsigned int v23; // esi
  int v24; // edx
  int v25; // esi
  int v26; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // esi
  int v30; // edi
  int v31; // ecx
  int v32; // edx
  int v33; // esi
  int v34; // edi
  int v35; // ecx
  int v36; // edx
  int v37; // esi
  int v38; // edi
  int v39; // ecx
  int v40; // edx
  unsigned int v41; // edi
  unsigned int v42; // ecx
  unsigned int v43; // esi
  int v44; // edx
  int v45; // ebx
  int v46; // edx
  int v47; // ecx
  int v48; // esi
  int v49; // edi
  unsigned int v50; // ebx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // edx
  int v56; // ecx
  int v57; // esi
  int v58; // edi
  int v59; // eax
  int v60; // ecx
  int v61; // edx
  int v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // esi
  int v67; // eax
  int v68; // ecx
  int v69; // edx
  int v70; // esi
  int v71; // edi
  unsigned int v72; // ebx
  unsigned int v73; // ecx
  unsigned int v74; // [esp+10h] [ebp-40h]
  unsigned int v75; // [esp+14h] [ebp-3Ch]
  unsigned int v76; // [esp+18h] [ebp-38h]
  unsigned int v77; // [esp+1Ch] [ebp-34h]
  unsigned int v78; // [esp+20h] [ebp-30h]
  unsigned int v79; // [esp+24h] [ebp-2Ch]
  unsigned int v80; // [esp+28h] [ebp-28h]
  unsigned int v81; // [esp+2Ch] [ebp-24h]
  unsigned int v82; // [esp+30h] [ebp-20h]
  unsigned int v83; // [esp+3Ch] [ebp-14h]
  unsigned int v84; // [esp+44h] [ebp-Ch]
  unsigned int d; // [esp+48h] [ebp-8h]
  unsigned int da; // [esp+48h] [ebp-8h]
  unsigned int b; // [esp+4Ch] [ebp-4h]
  unsigned int ba; // [esp+4Ch] [ebp-4h]
  unsigned int bb; // [esp+4Ch] [ebp-4h]

  v2 = buf[3];
  v3 = buf[1];
  v4 = buf[2];
  v5 = v3 + __ROL4__(*in + (v2 ^ v3 & (v4 ^ v2)) + *buf - 680876936, 7);
  v6 = v5 + __ROL4__(in[1] + (v4 ^ v5 & (v3 ^ v4)) + v2 - 389564586, 12);
  v7 = v6 + __ROR4__(in[2] + (v3 ^ v6 & (v5 ^ v3)) + v4 + 606105819, 15);
  v8 = v7 + __ROR4__(in[3] + (v5 ^ v7 & (v5 ^ v6)) + buf[1] - 1044525330, 10);
  v9 = v8 + __ROL4__(in[4] + (v6 ^ v8 & (v7 ^ v6)) + v5 - 176418897, 7);
  v10 = v9 + __ROL4__(in[5] + (v7 ^ v9 & (v8 ^ v7)) + v6 + 1200080426, 12);
  v11 = v10 + __ROR4__(in[6] + (v8 ^ v10 & (v9 ^ v8)) + v7 - 1473231341, 15);
  v83 = in[7];
  v12 = v11 + __ROR4__(v83 + (v9 ^ v11 & (v9 ^ v10)) + v8 - 45705983, 10);
  v13 = v12 + __ROL4__(in[8] + (v10 ^ v12 & (v11 ^ v10)) + v9 + 1770035416, 7);
  v14 = v13 + __ROL4__(in[9] + (v11 ^ v13 & (v12 ^ v11)) + v10 - 1958414417, 12);
  v15 = v14 + __ROR4__(in[10] + (v12 ^ v14 & (v13 ^ v12)) + v11 - 42063, 15);
  v16 = v15 + __ROR4__(in[11] + (v13 ^ v15 & (v13 ^ v14)) + v12 - 1990404162, 10);
  v17 = v16 + __ROL4__(in[12] + (v14 ^ v16 & (v15 ^ v14)) + v13 + 1804603682, 7);
  v18 = v17 + __ROL4__(in[13] + (v15 ^ v17 & (v16 ^ v15)) + v14 - 40341101, 12);
  v19 = v18 + __ROR4__(in[14] + (v16 ^ v18 & (v17 ^ v16)) + v15 - 1502002290, 15);
  v20 = v19 + __ROR4__(in[15] + (v17 ^ v19 & (v17 ^ v18)) + v16 + 1236535329, 10);
  v21 = v20 + __ROL4__(in[1] + (v19 ^ v18 & (v20 ^ v19)) + v17 - 165796510, 5);
  v22 = __ROL4__(in[6] + (v20 ^ v19 & (v21 ^ v20)) + v18 - 1069501632, 9);
  v23 = in[11] + (v21 ^ v20 & (v21 ^ (v21 + v22))) + v19 + 643717713;
  v24 = v21 + v22;
  v25 = v24 + __ROL4__(v23, 14);
  v26 = v25 + __ROR4__(*in + (v24 ^ v21 & (v25 ^ v24)) + v20 - 373897302, 12);
  v27 = v26 + __ROL4__(in[5] + (v25 ^ v24 & (v26 ^ v25)) + v21 - 701558691, 5);
  v28 = v27 + __ROL4__(in[10] + (v26 ^ v25 & (v27 ^ v26)) + v24 + 38016083, 9);
  v29 = v28 + __ROL4__(in[15] + (v27 ^ v26 & (v27 ^ v28)) + v25 - 660478335, 14);
  v30 = v29 + __ROR4__(in[4] + (v28 ^ v27 & (v29 ^ v28)) + v26 - 405537848, 12);
  v31 = v30 + __ROL4__(in[9] + (v29 ^ v28 & (v30 ^ v29)) + v27 + 568446438, 5);
  v32 = v31 + __ROL4__(in[14] + (v30 ^ v29 & (v31 ^ v30)) + v28 - 1019803690, 9);
  v33 = v32 + __ROL4__(in[3] + (v31 ^ v30 & (v31 ^ v32)) + v29 - 187363961, 14);
  v34 = v33 + __ROR4__(in[8] + (v32 ^ v31 & (v33 ^ v32)) + v30 + 1163531501, 12);
  v35 = v34 + __ROL4__(in[13] + (v33 ^ v32 & (v34 ^ v33)) + v31 - 1444681467, 5);
  v36 = v35 + __ROL4__(in[2] + (v34 ^ v33 & (v35 ^ v34)) + v32 - 51403784, 9);
  v84 = in[2];
  v37 = v36 + __ROL4__(v83 + (v35 ^ v34 & (v35 ^ v36)) + v33 + 1735328473, 14);
  v38 = v37 + __ROR4__(in[12] + (v36 ^ v35 & (v37 ^ v36)) + v34 - 1926607734, 12);
  v39 = v38 + __ROL4__(in[5] + (v38 ^ v37 ^ v36) + v35 - 378558, 4);
  v40 = v39 + __ROL4__(in[8] + (v39 ^ v38 ^ v37) + v36 - 2022574463, 11);
  v79 = in[8];
  v74 = in[11];
  b = v40 + __ROL4__(v74 + (v39 ^ v38 ^ v40) + v37 + 1839030562, 16);
  v41 = b + __ROR4__(in[14] + (v39 ^ b ^ v40) + v38 - 35309556, 9);
  v80 = in[1];
  v42 = v41 + __ROL4__(v80 + (v41 ^ b ^ v40) + v39 - 1530992060, 4);
  v75 = in[4];
  v43 = v42 + __ROL4__(v75 + (v42 ^ v41 ^ b) + v40 + 1272893353, 11);
  v44 = __ROL4__(v83 + (v42 ^ v41 ^ v43) + b - 155497632, 16);
  ba = v43 + v44;
  v45 = (v43 + v44) ^ v43;
  v81 = in[10];
  v46 = v43 + v44 + __ROR4__(v81 + (v42 ^ v45) + v41 - 1094730640, 9);
  v76 = in[13];
  v47 = v46 + __ROL4__(v76 + (v46 ^ v45) + v42 + 681279174, 4);
  v48 = v47 + __ROL4__(*in + (v47 ^ v46 ^ ba) + v43 - 358537222, 11);
  v82 = in[3];
  v49 = __ROL4__(v82 + (v47 ^ v46 ^ v48) + ba - 722521979, 16);
  bb = v48 + v49;
  d = (v48 + v49) ^ v48;
  v50 = in[9];
  v51 = v48 + v49 + __ROR4__(in[6] + (v47 ^ d) + v46 + 76029189, 9);
  v77 = in[6];
  v52 = v51 + __ROL4__(v50 + (v51 ^ d) + v47 - 640364487, 4);
  da = in[12];
  v78 = in[15];
  v53 = v52 + __ROL4__(da + (v52 ^ v51 ^ (v48 + v49)) + v48 - 421815835, 11);
  v54 = v53 + __ROL4__(v78 + (v52 ^ v51 ^ v53) + bb + 530742520, 16);
  v55 = v54 + __ROR4__(v84 + (v52 ^ v54 ^ v53) + v51 - 995338651, 9);
  v56 = v55 + __ROL4__(*in + (v54 ^ (v55 | ~v53)) + v52 - 198630844, 6);
  v57 = v56 + __ROL4__(v83 + (v55 ^ (v56 | ~v54)) + v53 + 1126891415, 10);
  v58 = v57 + __ROL4__(in[14] + (v56 ^ (v57 | ~v55)) + v54 - 1416354905, 15);
  v59 = v58 + __ROR4__(in[5] + (v57 ^ (v58 | ~v56)) + v55 - 57434055, 11);
  v60 = v59 + __ROL4__(da + (v58 ^ (v59 | ~v57)) + v56 + 1700485571, 6);
  v61 = v60 + __ROL4__(v82 + (v59 ^ (v60 | ~v58)) + v57 - 1894986606, 10);
  v62 = v61 + __ROL4__(v81 + (v60 ^ (v61 | ~v59)) + v58 - 1051523, 15);
  v63 = v62 + __ROR4__(v80 + (v61 ^ (v62 | ~v60)) + v59 - 2054922799, 11);
  v64 = v63 + __ROL4__(v79 + (v62 ^ (v63 | ~v61)) + v60 + 1873313359, 6);
  v65 = v64 + __ROL4__(v78 + (v63 ^ (v64 | ~v62)) + v61 - 30611744, 10);
  v66 = v65 + __ROL4__(v77 + (v64 ^ (v65 | ~v63)) + v62 - 1560198380, 15);
  v67 = v66 + __ROR4__(v76 + (v65 ^ (v66 | ~v64)) + v63 + 1309151649, 11);
  v68 = v67 + __ROL4__(v75 + (v66 ^ (v67 | ~v65)) + v64 - 145523070, 6);
  v69 = v68 + __ROL4__(v74 + (v67 ^ (v68 | ~v66)) + v65 - 1120210379, 10);
  v70 = v69 + __ROL4__(v84 + (v68 ^ (v69 | ~v67)) + v66 + 718787259, 15);
  v71 = v50 + (v69 ^ (v70 | ~v68)) + v67 - 343485551;
  v72 = v68 + *buf;
  buf[1] += v70 + __ROR4__(v71, 11);
  v73 = v70 + buf[2];
  *buf = v72;
  buf[2] = v73;
  buf[3] += v69;
}

//------------------------------------------------------------------------------
// Address: 0x1036D740
// Name: void MD5Update(struct MD5Context_t __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Update(MD5Context_t *ctx, unsigned __int8 *buf, unsigned int len)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // esi
  MD5Context_t *ctxa; // [esp+14h] [ebp+8h]

  v4 = ctx->bits[0];
  v5 = len;
  v6 = v4 + 8 * len;
  ctx->bits[0] = v6;
  if ( v6 < v4 )
    ++ctx->bits[1];
  ctx->bits[1] += len >> 29;
  v7 = (v4 >> 3) & 0x3F;
  if ( v7 != 0 )
  {
    v8 = 64 - v7;
    if ( len < 64 - v7 )
    {
      memcpy(dst: &ctx->in[v7], src: buf, count: len);
      return;
    }
    memcpy(dst: &ctx->in[v7], src: buf, count: v8);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    buf += v8;
    v5 = len - v8;
    len -= v8;
  }
  if ( v5 >= 0x40 )
  {
    ctxa = (MD5Context_t *)(v5 >> 6);
    do
    {
      qmemcpy(ctx->in, buf, sizeof(ctx->in));
      MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
      buf += 64;
      len -= 64;
      ctxa = (MD5Context_t *)((char *)ctxa - 1);
    }
    while ( ctxa != nullptr );
    v5 = len;
  }
  memcpy(dst: ctx->in, src: buf, count: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1036D800
// Name: void MD5Final(unsigned char __near * const,struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Final(unsigned __int8 *digest, MD5Context_t *ctx)
{
  unsigned int v2; // eax
  unsigned __int8 *v3; // edx
  unsigned int v4; // ecx

  v2 = (ctx->bits[0] >> 3) & 0x3F;
  ctx->in[v2] = 0x80;
  v3 = &ctx->in[v2 + 1];
  if ( 63 - v2 >= 8 )
  {
    memset(dst: v3, value: 0, count: 63 - v2 - 8);
  }
  else
  {
    memset(dst: v3, value: 0, count: 63 - v2);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    memset(dst: ctx->in, value: 0, count: 0x38u);
  }
  v4 = ctx->bits[1];
  *(_DWORD *)&ctx->in[56] = ctx->bits[0];
  *(_DWORD *)&ctx->in[60] = v4;
  MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
  *(_QWORD *)digest = *(_QWORD *)ctx->buf;
  *((_QWORD *)digest + 1) = *(_QWORD *)&ctx->buf[2];
  ctx->buf[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036D890
// Name: unsigned int MD5_PseudoRandom(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl MD5_PseudoRandom(unsigned int nSeed)
{
  MD5Context_t ctx; // [esp+0h] [ebp-68h] BYREF
  unsigned __int8 digest[16]; // [esp+58h] [ebp-10h] BYREF

  memset(dst: (unsigned __int8 *)&ctx, value: 0, count: sizeof(ctx));
  ctx.buf[0] = 1732584193;
  ctx.buf[1] = -271733879;
  ctx.buf[2] = -1732584194;
  ctx.buf[3] = 271733878;
  ctx.bits[0] = 0;
  ctx.bits[1] = 0;
  MD5Update(&ctx, buf: (unsigned __int8 *)&nSeed, len: 4u);
  MD5Final(digest, &ctx);
  return *(_DWORD *)&digest[6];
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037CC30
// Name: MD5Transform
// Source: json
//------------------------------------------------------------------------------
void __usercall MD5Transform(const unsigned int *in@<eax>, unsigned int *buf)
{
  unsigned int v2; // edx
  unsigned int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // esi
  int v16; // edi
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edi
  int v21; // ecx
  int v22; // edx
  unsigned int v23; // esi
  int v24; // edx
  int v25; // esi
  int v26; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // esi
  int v30; // edi
  int v31; // ecx
  int v32; // edx
  int v33; // esi
  int v34; // edi
  int v35; // ecx
  int v36; // edx
  int v37; // esi
  int v38; // edi
  int v39; // ecx
  int v40; // edx
  unsigned int v41; // edi
  unsigned int v42; // ecx
  unsigned int v43; // esi
  int v44; // edx
  int v45; // ebx
  int v46; // edx
  int v47; // ecx
  int v48; // esi
  int v49; // edi
  unsigned int v50; // ebx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // edx
  int v56; // ecx
  int v57; // esi
  int v58; // edi
  int v59; // eax
  int v60; // ecx
  int v61; // edx
  int v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // esi
  int v67; // eax
  int v68; // ecx
  int v69; // edx
  int v70; // esi
  int v71; // edi
  unsigned int v72; // ebx
  unsigned int v73; // ecx
  unsigned int v74; // [esp+10h] [ebp-40h]
  unsigned int v75; // [esp+14h] [ebp-3Ch]
  unsigned int v76; // [esp+18h] [ebp-38h]
  unsigned int v77; // [esp+1Ch] [ebp-34h]
  unsigned int v78; // [esp+20h] [ebp-30h]
  unsigned int v79; // [esp+24h] [ebp-2Ch]
  unsigned int v80; // [esp+28h] [ebp-28h]
  unsigned int v81; // [esp+2Ch] [ebp-24h]
  unsigned int v82; // [esp+30h] [ebp-20h]
  unsigned int v83; // [esp+3Ch] [ebp-14h]
  unsigned int v84; // [esp+44h] [ebp-Ch]
  unsigned int d; // [esp+48h] [ebp-8h]
  unsigned int da; // [esp+48h] [ebp-8h]
  unsigned int b; // [esp+4Ch] [ebp-4h]
  unsigned int ba; // [esp+4Ch] [ebp-4h]
  unsigned int bb; // [esp+4Ch] [ebp-4h]

  v2 = buf[3];
  v3 = buf[1];
  v4 = buf[2];
  v5 = v3 + __ROL4__(*in + (v2 ^ v3 & (v4 ^ v2)) + *buf - 680876936, 7);
  v6 = v5 + __ROL4__(in[1] + (v4 ^ v5 & (v3 ^ v4)) + v2 - 389564586, 12);
  v7 = v6 + __ROR4__(in[2] + (v3 ^ v6 & (v5 ^ v3)) + v4 + 606105819, 15);
  v8 = v7 + __ROR4__(in[3] + (v5 ^ v7 & (v5 ^ v6)) + buf[1] - 1044525330, 10);
  v9 = v8 + __ROL4__(in[4] + (v6 ^ v8 & (v7 ^ v6)) + v5 - 176418897, 7);
  v10 = v9 + __ROL4__(in[5] + (v7 ^ v9 & (v8 ^ v7)) + v6 + 1200080426, 12);
  v11 = v10 + __ROR4__(in[6] + (v8 ^ v10 & (v9 ^ v8)) + v7 - 1473231341, 15);
  v83 = in[7];
  v12 = v11 + __ROR4__(v83 + (v9 ^ v11 & (v9 ^ v10)) + v8 - 45705983, 10);
  v13 = v12 + __ROL4__(in[8] + (v10 ^ v12 & (v11 ^ v10)) + v9 + 1770035416, 7);
  v14 = v13 + __ROL4__(in[9] + (v11 ^ v13 & (v12 ^ v11)) + v10 - 1958414417, 12);
  v15 = v14 + __ROR4__(in[10] + (v12 ^ v14 & (v13 ^ v12)) + v11 - 42063, 15);
  v16 = v15 + __ROR4__(in[11] + (v13 ^ v15 & (v13 ^ v14)) + v12 - 1990404162, 10);
  v17 = v16 + __ROL4__(in[12] + (v14 ^ v16 & (v15 ^ v14)) + v13 + 1804603682, 7);
  v18 = v17 + __ROL4__(in[13] + (v15 ^ v17 & (v16 ^ v15)) + v14 - 40341101, 12);
  v19 = v18 + __ROR4__(in[14] + (v16 ^ v18 & (v17 ^ v16)) + v15 - 1502002290, 15);
  v20 = v19 + __ROR4__(in[15] + (v17 ^ v19 & (v17 ^ v18)) + v16 + 1236535329, 10);
  v21 = v20 + __ROL4__(in[1] + (v19 ^ v18 & (v20 ^ v19)) + v17 - 165796510, 5);
  v22 = __ROL4__(in[6] + (v20 ^ v19 & (v21 ^ v20)) + v18 - 1069501632, 9);
  v23 = in[11] + (v21 ^ v20 & (v21 ^ (v21 + v22))) + v19 + 643717713;
  v24 = v21 + v22;
  v25 = v24 + __ROL4__(v23, 14);
  v26 = v25 + __ROR4__(*in + (v24 ^ v21 & (v25 ^ v24)) + v20 - 373897302, 12);
  v27 = v26 + __ROL4__(in[5] + (v25 ^ v24 & (v26 ^ v25)) + v21 - 701558691, 5);
  v28 = v27 + __ROL4__(in[10] + (v26 ^ v25 & (v27 ^ v26)) + v24 + 38016083, 9);
  v29 = v28 + __ROL4__(in[15] + (v27 ^ v26 & (v27 ^ v28)) + v25 - 660478335, 14);
  v30 = v29 + __ROR4__(in[4] + (v28 ^ v27 & (v29 ^ v28)) + v26 - 405537848, 12);
  v31 = v30 + __ROL4__(in[9] + (v29 ^ v28 & (v30 ^ v29)) + v27 + 568446438, 5);
  v32 = v31 + __ROL4__(in[14] + (v30 ^ v29 & (v31 ^ v30)) + v28 - 1019803690, 9);
  v33 = v32 + __ROL4__(in[3] + (v31 ^ v30 & (v31 ^ v32)) + v29 - 187363961, 14);
  v34 = v33 + __ROR4__(in[8] + (v32 ^ v31 & (v33 ^ v32)) + v30 + 1163531501, 12);
  v35 = v34 + __ROL4__(in[13] + (v33 ^ v32 & (v34 ^ v33)) + v31 - 1444681467, 5);
  v36 = v35 + __ROL4__(in[2] + (v34 ^ v33 & (v35 ^ v34)) + v32 - 51403784, 9);
  v84 = in[2];
  v37 = v36 + __ROL4__(v83 + (v35 ^ v34 & (v35 ^ v36)) + v33 + 1735328473, 14);
  v38 = v37 + __ROR4__(in[12] + (v36 ^ v35 & (v37 ^ v36)) + v34 - 1926607734, 12);
  v39 = v38 + __ROL4__(in[5] + (v38 ^ v37 ^ v36) + v35 - 378558, 4);
  v40 = v39 + __ROL4__(in[8] + (v39 ^ v38 ^ v37) + v36 - 2022574463, 11);
  v79 = in[8];
  v74 = in[11];
  b = v40 + __ROL4__(v74 + (v39 ^ v38 ^ v40) + v37 + 1839030562, 16);
  v41 = b + __ROR4__(in[14] + (v39 ^ b ^ v40) + v38 - 35309556, 9);
  v80 = in[1];
  v42 = v41 + __ROL4__(v80 + (v41 ^ b ^ v40) + v39 - 1530992060, 4);
  v75 = in[4];
  v43 = v42 + __ROL4__(v75 + (v42 ^ v41 ^ b) + v40 + 1272893353, 11);
  v44 = __ROL4__(v83 + (v42 ^ v41 ^ v43) + b - 155497632, 16);
  ba = v43 + v44;
  v45 = (v43 + v44) ^ v43;
  v81 = in[10];
  v46 = v43 + v44 + __ROR4__(v81 + (v42 ^ v45) + v41 - 1094730640, 9);
  v76 = in[13];
  v47 = v46 + __ROL4__(v76 + (v46 ^ v45) + v42 + 681279174, 4);
  v48 = v47 + __ROL4__(*in + (v47 ^ v46 ^ ba) + v43 - 358537222, 11);
  v82 = in[3];
  v49 = __ROL4__(v82 + (v47 ^ v46 ^ v48) + ba - 722521979, 16);
  bb = v48 + v49;
  d = (v48 + v49) ^ v48;
  v50 = in[9];
  v51 = v48 + v49 + __ROR4__(in[6] + (v47 ^ d) + v46 + 76029189, 9);
  v77 = in[6];
  v52 = v51 + __ROL4__(v50 + (v51 ^ d) + v47 - 640364487, 4);
  da = in[12];
  v78 = in[15];
  v53 = v52 + __ROL4__(da + (v52 ^ v51 ^ (v48 + v49)) + v48 - 421815835, 11);
  v54 = v53 + __ROL4__(v78 + (v52 ^ v51 ^ v53) + bb + 530742520, 16);
  v55 = v54 + __ROR4__(v84 + (v52 ^ v54 ^ v53) + v51 - 995338651, 9);
  v56 = v55 + __ROL4__(*in + (v54 ^ (v55 | ~v53)) + v52 - 198630844, 6);
  v57 = v56 + __ROL4__(v83 + (v55 ^ (v56 | ~v54)) + v53 + 1126891415, 10);
  v58 = v57 + __ROL4__(in[14] + (v56 ^ (v57 | ~v55)) + v54 - 1416354905, 15);
  v59 = v58 + __ROR4__(in[5] + (v57 ^ (v58 | ~v56)) + v55 - 57434055, 11);
  v60 = v59 + __ROL4__(da + (v58 ^ (v59 | ~v57)) + v56 + 1700485571, 6);
  v61 = v60 + __ROL4__(v82 + (v59 ^ (v60 | ~v58)) + v57 - 1894986606, 10);
  v62 = v61 + __ROL4__(v81 + (v60 ^ (v61 | ~v59)) + v58 - 1051523, 15);
  v63 = v62 + __ROR4__(v80 + (v61 ^ (v62 | ~v60)) + v59 - 2054922799, 11);
  v64 = v63 + __ROL4__(v79 + (v62 ^ (v63 | ~v61)) + v60 + 1873313359, 6);
  v65 = v64 + __ROL4__(v78 + (v63 ^ (v64 | ~v62)) + v61 - 30611744, 10);
  v66 = v65 + __ROL4__(v77 + (v64 ^ (v65 | ~v63)) + v62 - 1560198380, 15);
  v67 = v66 + __ROR4__(v76 + (v65 ^ (v66 | ~v64)) + v63 + 1309151649, 11);
  v68 = v67 + __ROL4__(v75 + (v66 ^ (v67 | ~v65)) + v64 - 145523070, 6);
  v69 = v68 + __ROL4__(v74 + (v67 ^ (v68 | ~v66)) + v65 - 1120210379, 10);
  v70 = v69 + __ROL4__(v84 + (v68 ^ (v69 | ~v67)) + v66 + 718787259, 15);
  v71 = v50 + (v69 ^ (v70 | ~v68)) + v67 - 343485551;
  v72 = v68 + *buf;
  buf[1] += v70 + __ROR4__(v71, 11);
  v73 = v70 + buf[2];
  *buf = v72;
  buf[2] = v73;
  buf[3] += v69;
}

//------------------------------------------------------------------------------
// Address: 0x1037D2B0
// Name: void MD5Update(struct MD5Context_t __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Update(MD5Context_t *ctx, unsigned __int8 *buf, unsigned int len)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // esi
  MD5Context_t *ctxa; // [esp+14h] [ebp+8h]

  v4 = ctx->bits[0];
  v5 = len;
  v6 = v4 + 8 * len;
  ctx->bits[0] = v6;
  if ( v6 < v4 )
    ++ctx->bits[1];
  ctx->bits[1] += len >> 29;
  v7 = (v4 >> 3) & 0x3F;
  if ( v7 != 0 )
  {
    v8 = 64 - v7;
    if ( len < 64 - v7 )
    {
      memcpy(dst: &ctx->in[v7], src: buf, count: len);
      return;
    }
    memcpy(dst: &ctx->in[v7], src: buf, count: v8);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    buf += v8;
    v5 = len - v8;
    len -= v8;
  }
  if ( v5 >= 0x40 )
  {
    ctxa = (MD5Context_t *)(v5 >> 6);
    do
    {
      qmemcpy(ctx->in, buf, sizeof(ctx->in));
      MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
      buf += 64;
      len -= 64;
      ctxa = (MD5Context_t *)((char *)ctxa - 1);
    }
    while ( ctxa != nullptr );
    v5 = len;
  }
  memcpy(dst: ctx->in, src: buf, count: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1037D370
// Name: void MD5Final(unsigned char __near * const,struct MD5Context_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MD5Final(unsigned __int8 *digest, MD5Context_t *ctx)
{
  unsigned int v2; // eax
  unsigned __int8 *v3; // edx
  unsigned int v4; // ecx

  v2 = (ctx->bits[0] >> 3) & 0x3F;
  ctx->in[v2] = 0x80;
  v3 = &ctx->in[v2 + 1];
  if ( 63 - v2 >= 8 )
  {
    memset(dst: (int)v3, value: nullptr, count: 63 - v2 - 8);
  }
  else
  {
    memset(dst: (int)v3, value: nullptr, count: 63 - v2);
    MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
    memset(dst: (int)ctx->in, value: nullptr, count: 0x38u);
  }
  v4 = ctx->bits[1];
  *(_DWORD *)&ctx->in[56] = ctx->bits[0];
  *(_DWORD *)&ctx->in[60] = v4;
  MD5Transform(in: (const unsigned int *)ctx->in, buf: ctx->buf);
  *(_QWORD *)digest = *(_QWORD *)ctx->buf;
  *((_QWORD *)digest + 1) = *(_QWORD *)&ctx->buf[2];
  ctx->buf[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037D400
// Name: unsigned int MD5_PseudoRandom(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl MD5_PseudoRandom(unsigned int nSeed)
{
  MD5Context_t ctx; // [esp+0h] [ebp-68h] BYREF
  unsigned __int8 digest[16]; // [esp+58h] [ebp-10h] BYREF

  memset(dst: (int)&ctx, value: nullptr, count: sizeof(ctx));
  ctx.buf[0] = 1732584193;
  ctx.buf[1] = -271733879;
  ctx.buf[2] = -1732584194;
  ctx.buf[3] = 271733878;
  ctx.bits[0] = 0;
  ctx.bits[1] = 0;
  MD5Update(&ctx, buf: (unsigned __int8 *)&nSeed, len: 4u);
  MD5Final(digest, &ctx);
  return *(_DWORD *)&digest[6];
}

} // namespace server
