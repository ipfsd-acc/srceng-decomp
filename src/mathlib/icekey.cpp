// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/icekey.cpp
// Functions: 8
// ============================================================

#include "mathlib\icekey.h"

//------------------------------------------------------------------------------
// Address: 0x1025E150
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025E1E0
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025E320
// Name: public: IceKey::IceKey(int)
// Source: json
//------------------------------------------------------------------------------
IceKey *__thiscall IceKey::IceKey(IceKey *this, int n)
{
  if ( ice_sboxes_initialised == 0 )
  {
    ice_sboxes_init();
    ice_sboxes_initialised = 1;
  }
  if ( n >= 1 )
  {
    this->_size = n;
    this->_rounds = 16 * n;
  }
  else
  {
    this->_size = 1;
    this->_rounds = 8;
  }
  this->_keysched = (IceSubkey *)MemAlloc_Alloc(
                                   nSize: (12 * (unsigned __int64)(unsigned int)this->_rounds) >> 32 != 0
                                 ? -1
                                 : 12 * this->_rounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1025E390
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x1025E3E0
// Name: public: void IceKey::encrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::encrypt(IceKey *this, const unsigned __int8 *ptext, unsigned __int8 *ctext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int rounds; // edx
  unsigned int *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  IceSubkey *ptexta; // [esp+18h] [ebp+8h]

  v3 = ptext[3] | ((ptext[2] | ((ptext[1] | (*ptext << 8)) << 8)) << 8);
  v4 = ptext[7] | ((ptext[6] | ((ptext[5] | (ptext[4] << 8)) << 8)) << 8);
  rounds = this->_rounds;
  l = v3;
  if ( rounds > 0 )
  {
    ptexta = this->_keysched;
    v6 = &ptexta[1].val[1];
    v17 = ((unsigned int)(rounds - 1) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *(v6 - 2) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 += 6;
      v9 = *(v6 - 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ ptexta->val[0]) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ v8 ^ ptexta->val[0]) >> 10]
          | ice_sbox[2][v9 >> 10];
      ptexta += 2;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *(v6 - 5) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *(v6 - 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *(v6 - 7)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *(v6 - 7)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ctext[3] = v4;
  ctext[7] = v3;
  v15 = v4 >> 8;
  ctext[2] = v15;
  v16 = v3 >> 8;
  ctext[6] = v16;
  v15 >>= 8;
  ctext[1] = v15;
  v16 >>= 8;
  ctext[5] = v16;
  *ctext = BYTE1(v15);
  ctext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x1025E590
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  const unsigned __int8 *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+18h] [ebp+8h]

  v3 = ctext[3] | ((ctext[2] | ((ctext[1] | (*ctext << 8)) << 8)) << 8);
  v4 = ctext[7] | ((ctext[6] | ((ctext[5] | (ctext[4] << 8)) << 8)) << 8);
  v5 = this->_rounds - 1;
  l = v3;
  if ( v5 > 0 )
  {
    ctexta = (const unsigned __int8 *)&this->_keysched[v5];
    v6 = ctexta - 8;
    v17 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *((_DWORD *)v6 + 4) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 -= 24;
      v9 = *((_DWORD *)v6 + 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ *(_DWORD *)ctexta) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ (unsigned int)v8 ^ *(_DWORD *)ctexta) >> 10]
          | ice_sbox[2][v9 >> 10];
      ctexta -= 24;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *((_DWORD *)v6 + 7) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *((_DWORD *)v6 + 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ptext[3] = v4;
  ptext[7] = v3;
  v15 = v4 >> 8;
  ptext[2] = v15;
  v16 = v3 >> 8;
  ptext[6] = v16;
  v15 >>= 8;
  ptext[1] = v15;
  v16 >>= 8;
  ptext[5] = v16;
  *ptext = BYTE1(v15);
  ptext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x1025E740
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x1025E880
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0047E1A0
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047E230
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047E370
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x0047E3C0
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  const unsigned __int8 *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+18h] [ebp+8h]

  v3 = ctext[3] | ((ctext[2] | ((ctext[1] | (*ctext << 8)) << 8)) << 8);
  v4 = ctext[7] | ((ctext[6] | ((ctext[5] | (ctext[4] << 8)) << 8)) << 8);
  v5 = this->_rounds - 1;
  l = v3;
  if ( v5 > 0 )
  {
    ctexta = (const unsigned __int8 *)&this->_keysched[v5];
    v6 = ctexta - 8;
    v17 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *((_DWORD *)v6 + 4) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 -= 24;
      v9 = *((_DWORD *)v6 + 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ *(_DWORD *)ctexta) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ (unsigned int)v8 ^ *(_DWORD *)ctexta) >> 10]
          | ice_sbox[2][v9 >> 10];
      ctexta -= 24;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *((_DWORD *)v6 + 7) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *((_DWORD *)v6 + 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ptext[3] = v4;
  ptext[7] = v3;
  v15 = v4 >> 8;
  ptext[2] = v15;
  v16 = v3 >> 8;
  ptext[6] = v16;
  v15 >>= 8;
  ptext[1] = v15;
  v16 >>= 8;
  ptext[5] = v16;
  *ptext = BYTE1(v15);
  ptext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x0047E570
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x0047E6B0
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E8F0
// Name: void DecodeICE(unsigned char __near *,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecodeICE(unsigned __int8 *pBuffer, unsigned int nSize, const unsigned __int8 *pKey)
{
  void *v3; // esp
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // ecx
  unsigned int v7; // ebx
  int v8; // eax
  _BYTE v9[12]; // [esp+0h] [ebp-20h] BYREF
  IceKey ice; // [esp+Ch] [ebp-14h] BYREF
  int nBytesLeft; // [esp+18h] [ebp-8h]
  unsigned __int8 *pTemp; // [esp+1Ch] [ebp-4h]

  if ( pKey != nullptr )
  {
    if ( ice_sboxes_initialised == 0 )
    {
      ice_sboxes_init();
      ice_sboxes_initialised = 1;
    }
    ice._size = 1;
    ice._rounds = 8;
    ice._keysched = (IceSubkey *)operator new(nSize: 0x60u);
    IceKey::set(this: &ice, key: pKey);
    v3 = alloca(8 * ((int)(nSize + 7) / 8));
    v4 = pBuffer;
    v5 = v9;
    pTemp = v9;
    v6 = nSize;
    if ( (int)nSize >= 8 )
    {
      v7 = nSize >> 3;
      v8 = v9 - pBuffer;
      nBytesLeft = nSize - 8 * (nSize >> 3);
      while ( 1 )
      {
        IceKey::decrypt(this: &ice, ctext: v4, ptext: &v4[v8]);
        v4 += 8;
        if ( --v7 == 0 )
          break;
        v8 = v9 - pBuffer;
      }
      v4 = pBuffer;
      v5 = pTemp;
      v6 = nBytesLeft;
    }
    _V_memcpy(dest: v4, src: v5, count: nSize - v6);
    IceKey::~IceKey(this: &ice);
  }
}

} // namespace avitest

// ============================================================
// Overlay from bugreporter_public (Missing functions)
// ============================================================
namespace bugreporter_public {

//------------------------------------------------------------------------------
// Address: 0x10003F80
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004010
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004150
// Name: public: IceKey::IceKey(int)
// Source: json
//------------------------------------------------------------------------------
IceKey *__thiscall IceKey::IceKey(IceKey *this, int n)
{
  if ( ice_sboxes_initialised == 0 )
  {
    ice_sboxes_init();
    ice_sboxes_initialised = 1;
  }
  if ( n >= 1 )
  {
    this->_size = n;
    this->_rounds = 16 * n;
  }
  else
  {
    this->_size = 1;
    this->_rounds = 8;
  }
  this->_keysched = (IceSubkey *)operator new(nSize: 12 * this->_rounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100041C0
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x10004210
// Name: public: void IceKey::encrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::encrypt(IceKey *this, const unsigned __int8 *ptext, unsigned __int8 *ctext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int rounds; // edx
  unsigned int *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  IceSubkey *ptexta; // [esp+18h] [ebp+8h]

  v3 = ptext[3] | ((ptext[2] | ((ptext[1] | (*ptext << 8)) << 8)) << 8);
  v4 = ptext[7] | ((ptext[6] | ((ptext[5] | (ptext[4] << 8)) << 8)) << 8);
  rounds = this->_rounds;
  l = v3;
  if ( rounds > 0 )
  {
    ptexta = this->_keysched;
    v6 = &ptexta[1].val[1];
    v17 = ((unsigned int)(rounds - 1) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *(v6 - 2) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 += 6;
      v9 = *(v6 - 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ ptexta->val[0]) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ v8 ^ ptexta->val[0]) >> 10]
          | ice_sbox[2][v9 >> 10];
      ptexta += 2;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *(v6 - 5) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *(v6 - 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *(v6 - 7)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *(v6 - 7)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ctext[3] = v4;
  ctext[7] = v3;
  v15 = v4 >> 8;
  ctext[2] = v15;
  v16 = v3 >> 8;
  ctext[6] = v16;
  v15 >>= 8;
  ctext[1] = v15;
  v16 >>= 8;
  ctext[5] = v16;
  *ctext = BYTE1(v15);
  ctext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x100043C0
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x10004500
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

} // namespace bugreporter_public

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x006786E0
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00678770
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006788B0
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x00678900
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  const unsigned __int8 *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+18h] [ebp+8h]

  v3 = ctext[3] | ((ctext[2] | ((ctext[1] | (*ctext << 8)) << 8)) << 8);
  v4 = ctext[7] | ((ctext[6] | ((ctext[5] | (ctext[4] << 8)) << 8)) << 8);
  v5 = this->_rounds - 1;
  l = v3;
  if ( v5 > 0 )
  {
    ctexta = (const unsigned __int8 *)&this->_keysched[v5];
    v6 = ctexta - 8;
    v17 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *((_DWORD *)v6 + 4) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 -= 24;
      v9 = *((_DWORD *)v6 + 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ *(_DWORD *)ctexta) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ (unsigned int)v8 ^ *(_DWORD *)ctexta) >> 10]
          | ice_sbox[2][v9 >> 10];
      ctexta -= 24;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *((_DWORD *)v6 + 7) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *((_DWORD *)v6 + 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ptext[3] = v4;
  ptext[7] = v3;
  v15 = v4 >> 8;
  ptext[2] = v15;
  v16 = v3 >> 8;
  ptext[6] = v16;
  v15 >>= 8;
  ptext[1] = v15;
  v16 >>= 8;
  ptext[5] = v16;
  *ptext = BYTE1(v15);
  ptext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x00678AB0
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x00678BF0
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00678E30
// Name: void DecodeICE(unsigned char __near *,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecodeICE(unsigned __int8 *pBuffer, unsigned int nSize, const unsigned __int8 *pKey)
{
  void *v3; // esp
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // ecx
  unsigned int v7; // ebx
  int v8; // eax
  _BYTE v9[12]; // [esp+0h] [ebp-20h] BYREF
  IceKey ice; // [esp+Ch] [ebp-14h] BYREF
  int nBytesLeft; // [esp+18h] [ebp-8h]
  unsigned __int8 *pTemp; // [esp+1Ch] [ebp-4h]

  if ( pKey != nullptr )
  {
    if ( ice_sboxes_initialised == 0 )
    {
      ice_sboxes_init();
      ice_sboxes_initialised = 1;
    }
    ice._size = 1;
    ice._rounds = 8;
    ice._keysched = (IceSubkey *)MemAlloc_Alloc(nSize: 0x60u);
    IceKey::set(this: &ice, key: pKey);
    v3 = alloca(8 * ((int)(nSize + 7) / 8));
    v4 = pBuffer;
    v5 = v9;
    pTemp = v9;
    v6 = nSize;
    if ( (int)nSize >= 8 )
    {
      v7 = nSize >> 3;
      v8 = v9 - pBuffer;
      nBytesLeft = nSize - 8 * (nSize >> 3);
      while ( 1 )
      {
        IceKey::decrypt(this: &ice, ctext: v4, ptext: &v4[v8]);
        v4 += 8;
        if ( --v7 == 0 )
          break;
        v8 = v9 - pBuffer;
      }
      v4 = pBuffer;
      v5 = pTemp;
      v6 = nBytesLeft;
    }
    _V_memcpy(dest: v4, src: v5, count: nSize - v6);
    IceKey::~IceKey(this: &ice);
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1025E180
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025E210
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025E350
// Name: public: IceKey::IceKey(int)
// Source: json
//------------------------------------------------------------------------------
IceKey *__thiscall IceKey::IceKey(IceKey *this, int n)
{
  if ( ice_sboxes_initialised == 0 )
  {
    ice_sboxes_init();
    ice_sboxes_initialised = 1;
  }
  if ( n >= 1 )
  {
    this->_size = n;
    this->_rounds = 16 * n;
  }
  else
  {
    this->_size = 1;
    this->_rounds = 8;
  }
  this->_keysched = (IceSubkey *)MemAlloc_Alloc(
                                   nSize: (12 * (unsigned __int64)(unsigned int)this->_rounds) >> 32 != 0
                                 ? -1
                                 : 12 * this->_rounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1025E3C0
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x1025E410
// Name: public: void IceKey::encrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::encrypt(IceKey *this, const unsigned __int8 *ptext, unsigned __int8 *ctext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int rounds; // edx
  unsigned int *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  IceSubkey *ptexta; // [esp+18h] [ebp+8h]

  v3 = ptext[3] | ((ptext[2] | ((ptext[1] | (*ptext << 8)) << 8)) << 8);
  v4 = ptext[7] | ((ptext[6] | ((ptext[5] | (ptext[4] << 8)) << 8)) << 8);
  rounds = this->_rounds;
  l = v3;
  if ( rounds > 0 )
  {
    ptexta = this->_keysched;
    v6 = &ptexta[1].val[1];
    v17 = ((unsigned int)(rounds - 1) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *(v6 - 2) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 += 6;
      v9 = *(v6 - 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ ptexta->val[0]) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ v8 ^ ptexta->val[0]) >> 10]
          | ice_sbox[2][v9 >> 10];
      ptexta += 2;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *(v6 - 5) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *(v6 - 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *(v6 - 7)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *(v6 - 7)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ctext[3] = v4;
  ctext[7] = v3;
  v15 = v4 >> 8;
  ctext[2] = v15;
  v16 = v3 >> 8;
  ctext[6] = v16;
  v15 >>= 8;
  ctext[1] = v15;
  v16 >>= 8;
  ctext[5] = v16;
  *ctext = BYTE1(v15);
  ctext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x1025E5C0
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  const unsigned __int8 *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+18h] [ebp+8h]

  v3 = ctext[3] | ((ctext[2] | ((ctext[1] | (*ctext << 8)) << 8)) << 8);
  v4 = ctext[7] | ((ctext[6] | ((ctext[5] | (ctext[4] << 8)) << 8)) << 8);
  v5 = this->_rounds - 1;
  l = v3;
  if ( v5 > 0 )
  {
    ctexta = (const unsigned __int8 *)&this->_keysched[v5];
    v6 = ctexta - 8;
    v17 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *((_DWORD *)v6 + 4) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 -= 24;
      v9 = *((_DWORD *)v6 + 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ *(_DWORD *)ctexta) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ (unsigned int)v8 ^ *(_DWORD *)ctexta) >> 10]
          | ice_sbox[2][v9 >> 10];
      ctexta -= 24;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *((_DWORD *)v6 + 7) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *((_DWORD *)v6 + 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ptext[3] = v4;
  ptext[7] = v3;
  v15 = v4 >> 8;
  ptext[2] = v15;
  v16 = v3 >> 8;
  ptext[6] = v16;
  v15 >>= 8;
  ptext[1] = v15;
  v16 >>= 8;
  ptext[5] = v16;
  *ptext = BYTE1(v15);
  ptext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x1025E770
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x1025E8B0
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004B4590
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B4620
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B4760
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x004B47B0
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  const unsigned __int8 *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+18h] [ebp+8h]

  v3 = ctext[3] | ((ctext[2] | ((ctext[1] | (*ctext << 8)) << 8)) << 8);
  v4 = ctext[7] | ((ctext[6] | ((ctext[5] | (ctext[4] << 8)) << 8)) << 8);
  v5 = this->_rounds - 1;
  l = v3;
  if ( v5 > 0 )
  {
    ctexta = (const unsigned __int8 *)&this->_keysched[v5];
    v6 = ctexta - 8;
    v17 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *((_DWORD *)v6 + 4) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 -= 24;
      v9 = *((_DWORD *)v6 + 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ *(_DWORD *)ctexta) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ (unsigned int)v8 ^ *(_DWORD *)ctexta) >> 10]
          | ice_sbox[2][v9 >> 10];
      ctexta -= 24;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *((_DWORD *)v6 + 7) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *((_DWORD *)v6 + 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ptext[3] = v4;
  ptext[7] = v3;
  v15 = v4 >> 8;
  ptext[2] = v15;
  v16 = v3 >> 8;
  ptext[6] = v16;
  v15 >>= 8;
  ptext[1] = v15;
  v16 >>= 8;
  ptext[5] = v16;
  *ptext = BYTE1(v15);
  ptext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x004B4960
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x004B4AA0
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B4CE0
// Name: void DecodeICE(unsigned char __near *,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecodeICE(unsigned __int8 *pBuffer, unsigned int nSize, const unsigned __int8 *pKey)
{
  void *v3; // esp
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // ecx
  unsigned int v7; // ebx
  int v8; // eax
  _BYTE v9[12]; // [esp+0h] [ebp-20h] BYREF
  IceKey ice; // [esp+Ch] [ebp-14h] BYREF
  int nBytesLeft; // [esp+18h] [ebp-8h]
  unsigned __int8 *pTemp; // [esp+1Ch] [ebp-4h]

  if ( pKey != nullptr )
  {
    if ( ice_sboxes_initialised == 0 )
    {
      ice_sboxes_init();
      ice_sboxes_initialised = 1;
    }
    ice._size = 1;
    ice._rounds = 8;
    ice._keysched = (IceSubkey *)operator new(nSize: 0x60u);
    IceKey::set(this: &ice, key: pKey);
    v3 = alloca(8 * ((int)(nSize + 7) / 8));
    v4 = pBuffer;
    v5 = v9;
    pTemp = v9;
    v6 = nSize;
    if ( (int)nSize >= 8 )
    {
      v7 = nSize >> 3;
      v8 = v9 - pBuffer;
      nBytesLeft = nSize - 8 * (nSize >> 3);
      while ( 1 )
      {
        IceKey::decrypt(this: &ice, ctext: v4, ptext: &v4[v8]);
        v4 += 8;
        if ( --v7 == 0 )
          break;
        v8 = v9 - pBuffer;
      }
      v4 = pBuffer;
      v5 = pTemp;
      v6 = nBytesLeft;
    }
    _V_memcpy(dest: v4, src: v5, count: nSize - v6);
    IceKey::~IceKey(this: &ice);
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006A7590
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006A7620
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006A7760
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x006A77B0
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  const unsigned __int8 *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+18h] [ebp+8h]

  v3 = ctext[3] | ((ctext[2] | ((ctext[1] | (*ctext << 8)) << 8)) << 8);
  v4 = ctext[7] | ((ctext[6] | ((ctext[5] | (ctext[4] << 8)) << 8)) << 8);
  v5 = this->_rounds - 1;
  l = v3;
  if ( v5 > 0 )
  {
    ctexta = (const unsigned __int8 *)&this->_keysched[v5];
    v6 = ctexta - 8;
    v17 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *((_DWORD *)v6 + 4) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 -= 24;
      v9 = *((_DWORD *)v6 + 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ *(_DWORD *)ctexta) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ (unsigned int)v8 ^ *(_DWORD *)ctexta) >> 10]
          | ice_sbox[2][v9 >> 10];
      ctexta -= 24;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *((_DWORD *)v6 + 7) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *((_DWORD *)v6 + 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ptext[3] = v4;
  ptext[7] = v3;
  v15 = v4 >> 8;
  ptext[2] = v15;
  v16 = v3 >> 8;
  ptext[6] = v16;
  v15 >>= 8;
  ptext[1] = v15;
  v16 >>= 8;
  ptext[5] = v16;
  *ptext = BYTE1(v15);
  ptext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x006A7960
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x006A7AA0
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A7CE0
// Name: void DecodeICE(unsigned char __near *,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecodeICE(unsigned __int8 *pBuffer, unsigned int nSize, const unsigned __int8 *pKey)
{
  void *v3; // esp
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // ecx
  unsigned int v7; // ebx
  int v8; // eax
  _BYTE v9[12]; // [esp+0h] [ebp-20h] BYREF
  IceKey ice; // [esp+Ch] [ebp-14h] BYREF
  int nBytesLeft; // [esp+18h] [ebp-8h]
  unsigned __int8 *pTemp; // [esp+1Ch] [ebp-4h]

  if ( pKey != nullptr )
  {
    if ( ice_sboxes_initialised == 0 )
    {
      ice_sboxes_init();
      ice_sboxes_initialised = 1;
    }
    ice._size = 1;
    ice._rounds = 8;
    ice._keysched = (IceSubkey *)MemAlloc_Alloc(nSize: 0x60u);
    IceKey::set(this: &ice, key: pKey);
    v3 = alloca(8 * ((int)(nSize + 7) / 8));
    v4 = pBuffer;
    v5 = v9;
    pTemp = v9;
    v6 = nSize;
    if ( (int)nSize >= 8 )
    {
      v7 = nSize >> 3;
      v8 = v9 - pBuffer;
      nBytesLeft = nSize - 8 * (nSize >> 3);
      while ( 1 )
      {
        IceKey::decrypt(this: &ice, ctext: v4, ptext: &v4[v8]);
        v4 += 8;
        if ( --v7 == 0 )
          break;
        v8 = v9 - pBuffer;
      }
      v4 = pBuffer;
      v5 = pTemp;
      v6 = nBytesLeft;
    }
    _V_memcpy(dest: v4, src: v5, count: nSize - v6);
    IceKey::~IceKey(this: &ice);
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004919C0
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00491A50
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00491B90
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x00491BE0
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  const unsigned __int8 *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+18h] [ebp+8h]

  v3 = ctext[3] | ((ctext[2] | ((ctext[1] | (*ctext << 8)) << 8)) << 8);
  v4 = ctext[7] | ((ctext[6] | ((ctext[5] | (ctext[4] << 8)) << 8)) << 8);
  v5 = this->_rounds - 1;
  l = v3;
  if ( v5 > 0 )
  {
    ctexta = (const unsigned __int8 *)&this->_keysched[v5];
    v6 = ctexta - 8;
    v17 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *((_DWORD *)v6 + 4) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 -= 24;
      v9 = *((_DWORD *)v6 + 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ *(_DWORD *)ctexta) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ (unsigned int)v8 ^ *(_DWORD *)ctexta) >> 10]
          | ice_sbox[2][v9 >> 10];
      ctexta -= 24;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *((_DWORD *)v6 + 7) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *((_DWORD *)v6 + 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ptext[3] = v4;
  ptext[7] = v3;
  v15 = v4 >> 8;
  ptext[2] = v15;
  v16 = v3 >> 8;
  ptext[6] = v16;
  v15 >>= 8;
  ptext[1] = v15;
  v16 >>= 8;
  ptext[5] = v16;
  *ptext = BYTE1(v15);
  ptext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x00491D90
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x00491ED0
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492110
// Name: void DecodeICE(unsigned char __near *,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecodeICE(unsigned __int8 *pBuffer, unsigned int nSize, const unsigned __int8 *pKey)
{
  void *v3; // esp
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // ecx
  unsigned int v7; // ebx
  int v8; // eax
  _BYTE v9[12]; // [esp+0h] [ebp-20h] BYREF
  IceKey ice; // [esp+Ch] [ebp-14h] BYREF
  int nBytesLeft; // [esp+18h] [ebp-8h]
  unsigned __int8 *pTemp; // [esp+1Ch] [ebp-4h]

  if ( pKey != nullptr )
  {
    if ( ice_sboxes_initialised == 0 )
    {
      ice_sboxes_init();
      ice_sboxes_initialised = 1;
    }
    ice._size = 1;
    ice._rounds = 8;
    ice._keysched = (IceSubkey *)operator new(nSize: 0x60u);
    IceKey::set(this: &ice, key: pKey);
    v3 = alloca(8 * ((int)(nSize + 7) / 8));
    v4 = pBuffer;
    v5 = v9;
    pTemp = v9;
    v6 = nSize;
    if ( (int)nSize >= 8 )
    {
      v7 = nSize >> 3;
      v8 = v9 - pBuffer;
      nBytesLeft = nSize - 8 * (nSize >> 3);
      while ( 1 )
      {
        IceKey::decrypt(this: &ice, ctext: v4, ptext: &v4[v8]);
        v4 += 8;
        if ( --v7 == 0 )
          break;
        v8 = v9 - pBuffer;
      }
      v4 = pBuffer;
      v5 = pTemp;
      v6 = nBytesLeft;
    }
    _V_memcpy(dest: v4, src: v5, count: nSize - v6);
    IceKey::~IceKey(this: &ice);
  }
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00530650
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005306E0
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
unsigned int ice_sboxes_init()
{
  int i; // ebp
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int result; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx

  for ( i = 0; i < 1024; ++i )
  {
    v1 = i & 1 | (i >> 8) & 2;
    v2 = (unsigned __int8)(i >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    result = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; result != 0; result >>= 1 )
    {
      if ( (result & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00530800
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x00530850
// Name: ice_f
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall ice_f@<eax>(unsigned int p@<ecx>, const IceSubkey *sk@<edi>)
{
  unsigned int v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // ecx

  v2 = HIWORD(p) & 0x3FF | __ROR4__(p, 14) & 0xFFC00;
  v3 = sk->val[2] & (v2 ^ (p & 0x3FF | (4 * (p & 0x3FF00))));
  v4 = sk->val[1] ^ (p & 0x3FF | (4 * (p & 0x3FF00))) ^ v3;
  return ice_sbox[1][(v2 ^ v3 ^ sk->val[0]) & 0x3FF]
       | ice_sbox[3][v4 & 0x3FF]
       | ice_sbox[0][(v2 ^ v3 ^ sk->val[0]) >> 10]
       | ice_sbox[2][v4 >> 10];
}

//------------------------------------------------------------------------------
// Address: 0x005308D0
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned __int16 v3; // dx
  unsigned __int16 v4; // bx
  unsigned int v5; // edx
  unsigned int v6; // ebx
  const IceSubkey *v7; // esi
  unsigned int v8; // ebp
  unsigned int v9; // eax
  unsigned int v10; // ebx
  unsigned int v11; // edx
  unsigned int v12; // [esp+8h] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+10h] [ebp+4h]

  HIBYTE(v3) = *ctext;
  HIBYTE(v4) = ctext[4];
  LOBYTE(v3) = ctext[1];
  LOBYTE(v4) = ctext[5];
  v5 = ctext[3] | ((ctext[2] | (v3 << 8)) << 8);
  v6 = ctext[7] | ((ctext[6] | (v4 << 8)) << 8);
  v12 = v5;
  if ( this->_rounds - 1 > 0 )
  {
    v7 = &this->_keysched[this->_rounds - 1];
    ctexta = (const unsigned __int8 *)&v7[-1];
    v8 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v12 ^= ice_f(p: v6, sk: v7);
      v9 = ice_f(p: v12, sk: (const IceSubkey *)ctexta);
      ctexta -= 24;
      v6 ^= v9;
      v7 -= 2;
      --v8;
    }
    while ( v8 != 0 );
    v5 = v12;
  }
  ptext[3] = v6;
  ptext[7] = v5;
  v10 = v6 >> 8;
  ptext[2] = v10;
  v11 = v5 >> 8;
  ptext[6] = v11;
  v10 >>= 8;
  ptext[1] = v10;
  v11 >>= 8;
  ptext[5] = v11;
  *ptext = BYTE1(v10);
  ptext[4] = BYTE1(v11);
}

//------------------------------------------------------------------------------
// Address: 0x005309A0
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // eax
  int v5; // esi
  int v6; // eax
  char *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  unsigned __int16 *v11; // ebp
  int *v12; // eax
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // edx
  bool v17; // cc
  int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  char *v21; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+28h] [ebp+8h]

  v4 = 0;
  v5 = 12 * n;
  v18 = 0;
  v19 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    v7 = (char *)this->_keysched + v5;
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    v11 = &kb[((_BYTE)v6 - 2) & 3];
    *(_QWORD *)v7 = 0;
    v21 = v7;
    *((_DWORD *)v7 + 2) = 0;
    na = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v12 = (int *)&v7[4 * (v8 % 3)];
      v13 = *(_BYTE *)v9 & 1;
      *v12 = v13 | (2 * *v12);
      *v9 = (*v9 >> 1) | (~(_WORD)v13 << 15);
      v14 = *(_BYTE *)v10 & 1;
      *v12 = v14 | (2 * *v12);
      *v10 = (*v10 >> 1) | (~(_WORD)v14 << 15);
      v15 = *(_BYTE *)v11 & 1;
      *v12 = v15 | (2 * *v12);
      *v11 = (*v11 >> 1) | (~(_WORD)v15 << 15);
      v16 = *(_BYTE *)na & 1;
      *v12 = v16 | (2 * *v12);
      ++v8;
      *na = (*na >> 1) | (~(_WORD)v16 << 15);
      if ( v8 >= 15 )
        break;
      v7 = v21;
    }
    v4 = v18 + 1;
    v5 = v19 + 12;
    v17 = ++v18 < 8;
    v19 += 12;
  }
  while ( v17 );
}

//------------------------------------------------------------------------------
// Address: 0x00530AF0
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  unsigned __int16 v3; // cx
  unsigned __int16 v4; // dx
  int v5; // ebx
  const unsigned __int8 *v6; // esi
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // ax
  int i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 kb[4]; // [esp+10h] [ebp-8h] BYREF

  if ( this->_rounds == 8 )
  {
    HIBYTE(v3) = *key;
    HIBYTE(v4) = key[2];
    LOBYTE(v3) = key[1];
    LOBYTE(v4) = key[3];
    kb[3] = v3;
    HIBYTE(v3) = key[4];
    kb[2] = v4;
    HIBYTE(v4) = key[6];
    LOBYTE(v3) = key[5];
    LOBYTE(v4) = key[7];
    kb[1] = v3;
    kb[0] = v4;
    IceKey::scheduleBuild(this, kb, n: 0, keyrot: ice_keyrot);
  }
  else
  {
    v5 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v6 = key + 2;
      do
      {
        LOBYTE(v7) = v6[1];
        HIBYTE(v8) = *(v6 - 2);
        HIBYTE(v7) = *v6;
        HIBYTE(v9) = v6[2];
        LOBYTE(v8) = *(v6 - 1);
        kb[2] = v7;
        LOBYTE(v9) = v6[3];
        kb[3] = v8;
        HIBYTE(v8) = v6[4];
        kb[1] = v9;
        LOBYTE(v8) = v6[5];
        kb[0] = v8;
        IceKey::scheduleBuild(this, kb, n: v5, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this, kb, n: this->_rounds - v5 - 8, keyrot: &ice_keyrot[8]);
        v6 += 8;
        v5 += 8;
        ++i;
      }
      while ( i < this->_size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00530BF0
// Name: void DecodeICE(unsigned char __near *,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecodeICE(unsigned __int8 *pBuffer, unsigned int nSize, const unsigned __int8 *pKey)
{
  void *v3; // esp
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // ecx
  unsigned int v7; // ebx
  int v8; // eax
  _BYTE v9[12]; // [esp+0h] [ebp-20h] BYREF
  IceKey ice; // [esp+Ch] [ebp-14h] BYREF
  int nBytesLeft; // [esp+18h] [ebp-8h]
  unsigned __int8 *pTemp; // [esp+1Ch] [ebp-4h]

  if ( pKey != nullptr )
  {
    if ( ice_sboxes_initialised == 0 )
    {
      ice_sboxes_init();
      ice_sboxes_initialised = 1;
    }
    ice._size = 1;
    ice._rounds = 8;
    ice._keysched = (IceSubkey *)MemAlloc_Alloc(nSize: 0x60u);
    IceKey::set(this: &ice, key: pKey);
    v3 = alloca(8 * ((int)(nSize + 7) / 8));
    v4 = pBuffer;
    v5 = v9;
    pTemp = v9;
    v6 = nSize;
    if ( (int)nSize >= 8 )
    {
      v7 = nSize >> 3;
      v8 = v9 - pBuffer;
      nBytesLeft = nSize - 8 * (nSize >> 3);
      while ( 1 )
      {
        IceKey::decrypt(this: &ice, ctext: v4, ptext: &v4[v8]);
        v4 += 8;
        if ( --v7 == 0 )
          break;
        v8 = v9 - pBuffer;
      }
      v4 = pBuffer;
      v5 = pTemp;
      v6 = nBytesLeft;
    }
    _V_memcpy(dest: v4, src: v5, count: nSize - v6);
    IceKey::~IceKey(this: &ice);
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vice (Missing functions)
// ============================================================
namespace vice {

//------------------------------------------------------------------------------
// Address: 0x00403C20
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403CB0
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403DF0
// Name: public: IceKey::IceKey(int)
// Source: json
//------------------------------------------------------------------------------
IceKey *__thiscall IceKey::IceKey(IceKey *this, int n)
{
  if ( ice_sboxes_initialised == 0 )
  {
    ice_sboxes_init();
    ice_sboxes_initialised = 1;
  }
  if ( n >= 1 )
  {
    this->_size = n;
    this->_rounds = 16 * n;
  }
  else
  {
    this->_size = 1;
    this->_rounds = 8;
  }
  this->_keysched = (IceSubkey *)operator new(nSize: 12 * this->_rounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403E60
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x00403EB0
// Name: public: void IceKey::encrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::encrypt(IceKey *this, const unsigned __int8 *ptext, unsigned __int8 *ctext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int rounds; // edx
  unsigned int *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  IceSubkey *ptexta; // [esp+18h] [ebp+8h]

  v3 = ptext[3] | ((ptext[2] | ((ptext[1] | (*ptext << 8)) << 8)) << 8);
  v4 = ptext[7] | ((ptext[6] | ((ptext[5] | (ptext[4] << 8)) << 8)) << 8);
  rounds = this->_rounds;
  l = v3;
  if ( rounds > 0 )
  {
    ptexta = this->_keysched;
    v6 = &ptexta[1].val[1];
    v17 = ((unsigned int)(rounds - 1) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *(v6 - 2) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 += 6;
      v9 = *(v6 - 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ ptexta->val[0]) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ v8 ^ ptexta->val[0]) >> 10]
          | ice_sbox[2][v9 >> 10];
      ptexta += 2;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *(v6 - 5) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *(v6 - 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *(v6 - 7)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *(v6 - 7)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ctext[3] = v4;
  ctext[7] = v3;
  v15 = v4 >> 8;
  ctext[2] = v15;
  v16 = v3 >> 8;
  ctext[6] = v16;
  v15 >>= 8;
  ctext[1] = v15;
  v16 >>= 8;
  ctext[5] = v16;
  *ctext = BYTE1(v15);
  ctext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x00404060
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  const unsigned __int8 *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+18h] [ebp+8h]

  v3 = ctext[3] | ((ctext[2] | ((ctext[1] | (*ctext << 8)) << 8)) << 8);
  v4 = ctext[7] | ((ctext[6] | ((ctext[5] | (ctext[4] << 8)) << 8)) << 8);
  v5 = this->_rounds - 1;
  l = v3;
  if ( v5 > 0 )
  {
    ctexta = (const unsigned __int8 *)&this->_keysched[v5];
    v6 = ctexta - 8;
    v17 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *((_DWORD *)v6 + 4) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 -= 24;
      v9 = *((_DWORD *)v6 + 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ *(_DWORD *)ctexta) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ (unsigned int)v8 ^ *(_DWORD *)ctexta) >> 10]
          | ice_sbox[2][v9 >> 10];
      ctexta -= 24;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *((_DWORD *)v6 + 7) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *((_DWORD *)v6 + 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ptext[3] = v4;
  ptext[7] = v3;
  v15 = v4 >> 8;
  ptext[2] = v15;
  v16 = v3 >> 8;
  ptext[6] = v16;
  v15 >>= 8;
  ptext[1] = v15;
  v16 >>= 8;
  ptext[5] = v16;
  *ptext = BYTE1(v15);
  ptext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x00404210
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x00404350
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404590
// Name: public: int IceKey::blockSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IceKey::blockSize(IceKey *this)
{
  return 8;
}

} // namespace vice

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102CA770
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CA800
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CA940
// Name: public: IceKey::IceKey(int)
// Source: json
//------------------------------------------------------------------------------
IceKey *__thiscall IceKey::IceKey(IceKey *this, int n)
{
  if ( ice_sboxes_initialised == 0 )
  {
    ice_sboxes_init();
    ice_sboxes_initialised = 1;
  }
  if ( n >= 1 )
  {
    this->_size = n;
    this->_rounds = 16 * n;
  }
  else
  {
    this->_size = 1;
    this->_rounds = 8;
  }
  this->_keysched = (IceSubkey *)MemAlloc_Alloc(
                                   nSize: (12 * (unsigned __int64)(unsigned int)this->_rounds) >> 32 != 0
                                 ? -1
                                 : 12 * this->_rounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CA9B0
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  C_BaseEntity::operator delete(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x102CAA00
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  const unsigned __int8 *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+18h] [ebp+8h]

  v3 = ctext[3] | ((ctext[2] | ((ctext[1] | (*ctext << 8)) << 8)) << 8);
  v4 = ctext[7] | ((ctext[6] | ((ctext[5] | (ctext[4] << 8)) << 8)) << 8);
  v5 = this->_rounds - 1;
  l = v3;
  if ( v5 > 0 )
  {
    ctexta = (const unsigned __int8 *)&this->_keysched[v5];
    v6 = ctexta - 8;
    v17 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *((_DWORD *)v6 + 4) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 -= 24;
      v9 = *((_DWORD *)v6 + 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ *(_DWORD *)ctexta) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ (unsigned int)v8 ^ *(_DWORD *)ctexta) >> 10]
          | ice_sbox[2][v9 >> 10];
      ctexta -= 24;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *((_DWORD *)v6 + 7) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *((_DWORD *)v6 + 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ptext[3] = v4;
  ptext[7] = v3;
  v15 = v4 >> 8;
  ptext[2] = v15;
  v16 = v3 >> 8;
  ptext[6] = v16;
  v15 >>= 8;
  ptext[1] = v15;
  v16 >>= 8;
  ptext[5] = v16;
  *ptext = BYTE1(v15);
  ptext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x102CABB0
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x102CACF0
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CAF30
// Name: void DecodeICE(unsigned char __near *,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecodeICE(unsigned __int8 *pBuffer, unsigned int nSize, const unsigned __int8 *pKey)
{
  void *v3; // esp
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // ecx
  unsigned int v7; // ebx
  int v8; // eax
  _BYTE v9[12]; // [esp+0h] [ebp-20h] BYREF
  IceKey ice; // [esp+Ch] [ebp-14h] BYREF
  int nBytesLeft; // [esp+18h] [ebp-8h]
  unsigned __int8 *pTemp; // [esp+1Ch] [ebp-4h]

  if ( pKey != nullptr )
  {
    if ( ice_sboxes_initialised == 0 )
    {
      ice_sboxes_init();
      ice_sboxes_initialised = 1;
    }
    ice._size = 1;
    ice._rounds = 8;
    ice._keysched = (IceSubkey *)MemAlloc_Alloc(nSize: 0x60u);
    IceKey::set(this: &ice, key: pKey);
    v3 = alloca(8 * ((int)(nSize + 7) / 8));
    v4 = pBuffer;
    v5 = v9;
    pTemp = v9;
    v6 = nSize;
    if ( (int)nSize >= 8 )
    {
      v7 = nSize >> 3;
      v8 = v9 - pBuffer;
      nBytesLeft = nSize - 8 * (nSize >> 3);
      while ( 1 )
      {
        IceKey::decrypt(this: &ice, ctext: v4, ptext: &v4[v8]);
        v4 += 8;
        if ( --v7 == 0 )
          break;
        v8 = v9 - pBuffer;
      }
      v4 = pBuffer;
      v5 = pTemp;
      v6 = nBytesLeft;
    }
    _V_memcpy(dest: v4, src: v5, count: nSize - v6);
    IceKey::~IceKey(this: &ice);
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1035A0C0
// Name: gf_exp7
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall gf_exp7@<eax>(unsigned int b@<ecx>, unsigned int m@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // eax

  if ( b == 0 )
    return 0;
  v3 = b;
  v4 = b;
  v5 = 0;
  do
  {
    if ( (v3 & 1) != 0 )
      v5 ^= v4;
    v4 *= 2;
    v3 >>= 1;
    if ( v4 >= 0x100 )
      v4 ^= m;
  }
  while ( v3 != 0 );
  v6 = 0;
  v7 = b;
  while ( v5 != 0 )
  {
    if ( (v5 & 1) != 0 )
      v6 ^= v7;
    v7 *= 2;
    v5 >>= 1;
    if ( v7 >= 0x100 )
      v7 ^= m;
  }
  v8 = 0;
  v9 = v6;
  v10 = v6;
  while ( v9 != 0 )
  {
    if ( (v9 & 1) != 0 )
      v8 ^= v10;
    v10 *= 2;
    v9 >>= 1;
    if ( v10 >= 0x100 )
      v10 ^= m;
  }
  result = 0;
  while ( v8 != 0 )
  {
    if ( (v8 & 1) != 0 )
      result ^= b;
    b *= 2;
    v8 >>= 1;
    if ( b >= 0x100 )
      b ^= m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035A150
// Name: ice_sboxes_init
// Source: json
//------------------------------------------------------------------------------
int ice_sboxes_init()
{
  int result; // eax
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  const unsigned int *j; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  const unsigned int *k; // edx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const unsigned int *m; // edx
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  const unsigned int *n; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = 0;
  i = 0;
  do
  {
    v1 = result & 1 | (result >> 8) & 2;
    v2 = (unsigned __int8)(result >> 1);
    v3 = gf_exp7(b: v2 ^ ice_sxor[0][v1], m: ice_smod[0][v1]) << 24;
    v4 = 0;
    for ( j = ice_pbox; v3 != 0; v3 >>= 1 )
    {
      if ( (v3 & 1) != 0 )
        v4 |= *j;
      ++j;
    }
    v6 = ice_smod[1][v1];
    ice_sbox[0][i] = v4;
    v7 = gf_exp7(b: v2 ^ ice_sxor[1][v1], m: v6) << 16;
    v8 = 0;
    for ( k = ice_pbox; v7 != 0; v7 >>= 1 )
    {
      if ( (v7 & 1) != 0 )
        v8 |= *k;
      ++k;
    }
    v10 = ice_smod[2][v1];
    ice_sbox[1][i] = v8;
    v11 = gf_exp7(b: v2 ^ ice_sxor[2][v1], m: v10) << 8;
    v12 = 0;
    for ( m = ice_pbox; v11 != 0; v11 >>= 1 )
    {
      if ( (v11 & 1) != 0 )
        v12 |= *m;
      ++m;
    }
    v14 = ice_smod[3][v1];
    ice_sbox[2][i] = v12;
    v15 = gf_exp7(b: v2 ^ ice_sxor[3][v1], m: v14);
    v16 = 0;
    for ( n = ice_pbox; v15 != 0; v15 >>= 1 )
    {
      if ( (v15 & 1) != 0 )
        v16 |= *n;
      ++n;
    }
    ice_sbox[3][i] = v16;
    result = i + 1;
    i = result;
  }
  while ( result < 1024 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035A290
// Name: public: IceKey::IceKey(int)
// Source: json
//------------------------------------------------------------------------------
IceKey *__thiscall IceKey::IceKey(IceKey *this, int n)
{
  if ( ice_sboxes_initialised == 0 )
  {
    ice_sboxes_init();
    ice_sboxes_initialised = 1;
  }
  if ( n >= 1 )
  {
    this->_size = n;
    this->_rounds = 16 * n;
  }
  else
  {
    this->_size = 1;
    this->_rounds = 8;
  }
  this->_keysched = (IceSubkey *)operator new(nSize: 12 * this->_rounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035A300
// Name: public: IceKey::~IceKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::~IceKey(IceKey *this)
{
  int v1; // edx
  int v2; // eax
  IceSubkey *keysched; // [esp-4h] [ebp-8h]

  v1 = 0;
  if ( this->_rounds > 0 )
  {
    v2 = 0;
    do
    {
      this->_keysched[v2].val[0] = 0;
      this->_keysched[v2].val[1] = 0;
      this->_keysched[v2].val[2] = 0;
      ++v1;
      ++v2;
    }
    while ( v1 < this->_rounds );
  }
  keysched = this->_keysched;
  this->_size = 0;
  this->_rounds = 0;
  free(pMem: keysched);
}

//------------------------------------------------------------------------------
// Address: 0x1035A350
// Name: public: void IceKey::decrypt(unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::decrypt(IceKey *this, const unsigned __int8 *ctext, unsigned __int8 *ptext)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  const unsigned __int8 *v6; // esi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *ctexta; // [esp+18h] [ebp+8h]

  v3 = ctext[3] | ((ctext[2] | ((ctext[1] | (*ctext << 8)) << 8)) << 8);
  v4 = ctext[7] | ((ctext[6] | ((ctext[5] | (ctext[4] << 8)) << 8)) << 8);
  v5 = this->_rounds - 1;
  l = v3;
  if ( v5 > 0 )
  {
    ctexta = (const unsigned __int8 *)&this->_keysched[v5];
    v6 = ctexta - 8;
    v17 = ((unsigned int)(this->_rounds - 2) >> 1) + 1;
    do
    {
      v7 = HIWORD(v4) & 0x3FF | __ROR4__(v4, 14) & 0xFFC00;
      v8 = *((_DWORD *)v6 + 4) & (v7 ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))));
      v6 -= 24;
      v9 = *((_DWORD *)v6 + 9) ^ (v4 & 0x3FF | (4 * (v4 & 0x3FF00))) ^ v8;
      v10 = ice_sbox[1][(v7 ^ v8 ^ *(_DWORD *)ctexta) & 0x3FF]
          | ice_sbox[3][v9 & 0x3FF]
          | ice_sbox[0][(v7 ^ (unsigned int)v8 ^ *(_DWORD *)ctexta) >> 10]
          | ice_sbox[2][v9 >> 10];
      ctexta -= 24;
      v11 = v10 ^ l;
      v12 = ((v10 ^ l) >> 16) & 0x3FF | __ROR4__(v10 ^ l, 14) & 0xFFC00;
      l = v11;
      v13 = *((_DWORD *)v6 + 7) & (v12 ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))));
      v14 = *((_DWORD *)v6 + 6) ^ (v11 & 0x3FF | (4 * (v11 & 0x3FF00))) ^ v13;
      v4 ^= ice_sbox[1][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) & 0x3FF]
          | ice_sbox[3][v14 & 0x3FF]
          | ice_sbox[0][(v12 ^ v13 ^ *((_DWORD *)v6 + 5)) >> 10]
          | ice_sbox[2][v14 >> 10];
      --v17;
    }
    while ( v17 != 0 );
    v3 = l;
  }
  ptext[3] = v4;
  ptext[7] = v3;
  v15 = v4 >> 8;
  ptext[2] = v15;
  v16 = v3 >> 8;
  ptext[6] = v16;
  v15 >>= 8;
  ptext[1] = v15;
  v16 >>= 8;
  ptext[5] = v16;
  *ptext = BYTE1(v15);
  ptext[4] = BYTE1(v16);
}

//------------------------------------------------------------------------------
// Address: 0x1035A500
// Name: private: void IceKey::scheduleBuild(unsigned short __near *,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::scheduleBuild(IceKey *this, unsigned __int16 *kb, int n, const int *keyrot)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edx
  IceSubkey *v7; // ecx
  int v8; // esi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // ebx
  int *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  IceSubkey *isk; // [esp+Ch] [ebp-14h]
  int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int16 *kr; // [esp+1Ch] [ebp-4h]
  unsigned __int16 *na; // [esp+2Ch] [ebp+Ch]

  v4 = 0;
  v5 = 12 * n;
  i = 0;
  v18 = 12 * n;
  do
  {
    v6 = keyrot[v4];
    na = &kb[((_BYTE)v6 - 2) & 3];
    v7 = (IceSubkey *)((char *)this->_keysched + v5);
    v8 = 0;
    v9 = &kb[v6 & 3];
    v10 = &kb[((_BYTE)v6 + 1) & 3];
    *(_QWORD *)v7->val = 0;
    isk = v7;
    v7->val[2] = 0;
    kr = &kb[((_BYTE)v6 - 1) & 3];
    while ( 1 )
    {
      v11 = (int *)&v7->val[v8 % 3u];
      v12 = *v9 & 1;
      *v11 = v12 | (2 * *v11);
      *v9 = (*v9 >> 1) | (~(_WORD)v12 << 15);
      v13 = *v10 & 1;
      *v11 = v13 | (2 * *v11);
      *v10 = (*v10 >> 1) | (~(_WORD)v13 << 15);
      v14 = *na & 1;
      *v11 = v14 | (2 * *v11);
      *na = (*na >> 1) | (~(_WORD)v14 << 15);
      v15 = *kr & 1;
      *v11 = v15 | (2 * *v11);
      ++v8;
      *kr = (*kr >> 1) | (~(_WORD)v15 << 15);
      if ( v8 >= 15 )
        break;
      v7 = isk;
    }
    v4 = i + 1;
    v5 = v18 + 12;
    i = v4;
    v18 += 12;
  }
  while ( v4 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x1035A640
// Name: public: void IceKey::set(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceKey::set(IceKey *this, const unsigned __int8 *key)
{
  IceKey *v2; // edi
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // cx
  __int16 v6; // dx
  unsigned __int16 v7; // cx
  __int16 v8; // dx
  const int *v9; // eax
  int v10; // eax
  const unsigned __int8 *v11; // edi
  int v12; // esi
  int *v13; // eax
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  unsigned __int16 v17; // cx
  unsigned __int16 *v18; // edx
  int v19; // ebx
  const unsigned __int8 *v20; // esi
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // ax
  unsigned __int16 kb[4]; // [esp+Ch] [ebp-20h] BYREF
  IceKey *v25; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned __int16 *v28; // [esp+20h] [ebp-Ch]
  unsigned __int16 *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *v30; // [esp+28h] [ebp-4h]
  const unsigned __int8 *keya; // [esp+34h] [ebp+8h]

  v2 = this;
  v3 = this->_rounds == 8;
  v25 = this;
  if ( v3 )
  {
    v4 = key[3];
    kb[3] = _byteswap_ushort(*(_WORD *)key);
    v5 = v4 | (key[2] << 8);
    v6 = key[5];
    kb[2] = v5;
    v7 = v6 | (key[4] << 8);
    v8 = key[7];
    kb[1] = v7;
    v9 = ice_keyrot;
    kb[0] = v8 | (key[6] << 8);
    keya = nullptr;
    i = (int)ice_keyrot;
    while ( 1 )
    {
      v10 = *v9;
      v11 = &keya[(unsigned int)v2->_keysched->val];
      v30 = &kb[v10 & 3];
      v12 = 0;
      v29 = &kb[((_BYTE)v10 + 1) & 3];
      *(_QWORD *)v11 = 0;
      *((_DWORD *)v11 + 2) = 0;
      v28 = &kb[((_BYTE)v10 - 2) & 3];
      v27 = &kb[((_BYTE)v10 - 1) & 3];
      do
      {
        v13 = (int *)&v11[4 * (v12 % 3u)];
        v14 = *v30 & 1 | (2 * *v13);
        *v30 = (*v30 >> 1) | (~(*v30 & 1) << 15);
        v15 = *v29 & 1 | (2 * v14);
        *v29 = (*v29 >> 1) | (~(*v29 & 1) << 15);
        v16 = *v28 & 1 | (2 * v15);
        *v28 = (*v28 >> 1) | (~(*v28 & 1) << 15);
        v17 = (*v27 >> 1) | (~(*v27 & 1) << 15);
        v18 = v27;
        ++v12;
        *v13 = *v27 & 1 | (2 * v16);
        *v18 = v17;
      }
      while ( v12 < 15 );
      keya += 12;
      v9 = (const int *)(i + 4);
      i = (int)v9;
      if ( (int)v9 >= (int)&ice_keyrot[8] )
        break;
      v2 = v25;
    }
  }
  else
  {
    v19 = 0;
    i = 0;
    if ( this->_size > 0 )
    {
      v20 = key + 2;
      do
      {
        v21 = v20[1];
        v22 = v20[2];
        kb[3] = _byteswap_ushort(*((_WORD *)v20 - 1));
        v23 = v20[4];
        kb[2] = (*v20 << 8) | v21;
        kb[1] = v20[3] | (unsigned __int16)(v22 << 8);
        kb[0] = v20[5] | (unsigned __int16)(v23 << 8);
        IceKey::scheduleBuild(this: v2, kb, n: v19, keyrot: ice_keyrot);
        IceKey::scheduleBuild(this: v2, kb, n: v2->_rounds - v19 - 8, keyrot: &ice_keyrot[8]);
        v20 += 8;
        v19 += 8;
        ++i;
      }
      while ( i < v2->_size );
    }
  }
}

} // namespace server
