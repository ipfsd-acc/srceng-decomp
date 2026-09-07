// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/md2.cpp
// Functions: 6
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\md2.h"

//------------------------------------------------------------------------------
// Address: 0x00425080
// Name: public: virtual unsigned int TaoCrypt::MD2::getDigestSize(void)const
// Source: json
//------------------------------------------------------------------------------
int TaoCrypt::MD2::getDigestSize()
{
  return 16;
}

//------------------------------------------------------------------------------
// Address: 0x00451FD0
// Name: public: virtual void TaoCrypt::MD2::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::MD2::Init(unsigned __int8 **this)
{
  _DWORD *v2; // ecx
  _DWORD *v4; // ecx

  memset(dst: *(this + 2), value: 0, count: 0x30u);
  v2 = *(this + 5);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v4 = *(this + 8);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  *(this + 10) = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00452010
// Name: public: virtual void TaoCrypt::MD2::Update(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::MD2::Update(TaoCrypt::MD2 *this, const LoggingContext_t *data, unsigned int len)
{
  unsigned int v3; // ebp
  unsigned int v5; // edi
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  unsigned __int8 v8; // dl
  int i; // eax
  int v10; // ecx
  unsigned __int8 v11; // dl
  int j; // ebx
  int k; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // edx

  v3 = len;
  while ( v3 != 0 )
  {
    v5 = 16 - *((_DWORD *)this + 10);
    if ( v5 >= v3 )
      v5 = v3;
    memcpy(
      dst: (unsigned __int8 *)(*((_DWORD *)this + 10) + *((_DWORD *)this + 8)),
      src: (unsigned __int8 *)data,
      count: v5);
    *((_DWORD *)this + 10) += v5;
    v3 -= v5;
    data = (const LoggingContext_t *)((char *)data + v5);
    if ( *((_DWORD *)this + 10) == 16 )
    {
      v6 = *((_DWORD **)this + 8);
      v7 = *((_DWORD **)this + 2);
      *((_DWORD *)this + 10) = 0;
      v7[4] = *v6;
      v7 += 4;
      v7[1] = v6[1];
      v7[2] = v6[2];
      v7[3] = v6[3];
      v8 = *(_BYTE *)(*((_DWORD *)this + 5) + 15);
      for ( i = 0; i < 16; ++i )
      {
        *(_BYTE *)(i + *((_DWORD *)this + 2) + 32) = *(_BYTE *)(*((_DWORD *)this + 2) + i)
                                                   ^ *(_BYTE *)(*((_DWORD *)this + 2) + i + 16);
        v10 = *((_DWORD *)this + 5);
        *(_BYTE *)(v10 + i) ^= *((_BYTE *)S + (v8 ^ *(unsigned __int8 *)(*((_DWORD *)this + 8) + i)));
        v8 = *(_BYTE *)(v10 + i);
      }
      v11 = 0;
      for ( j = 0; j < 18; ++j )
      {
        for ( k = 0; k < 48; k += 8 )
        {
          v14 = *((_DWORD *)this + 2);
          *(_BYTE *)(v14 + k) ^= *((_BYTE *)S + v11);
          v15 = *((_DWORD *)this + 2);
          *(_BYTE *)(v15 + k + 1) ^= *((_BYTE *)S + *(unsigned __int8 *)(k + v14));
          v16 = *((_DWORD *)this + 2);
          *(_BYTE *)(v16 + k + 2) ^= *((_BYTE *)S + *(unsigned __int8 *)(v15 + k + 1));
          v17 = *((_DWORD *)this + 2);
          *(_BYTE *)(v17 + k + 3) ^= *((_BYTE *)S + *(unsigned __int8 *)(v16 + k + 2));
          v18 = *((_DWORD *)this + 2);
          *(_BYTE *)(v18 + k + 4) ^= *((_BYTE *)S + *(unsigned __int8 *)(v17 + k + 3));
          v19 = *((_DWORD *)this + 2);
          *(_BYTE *)(v19 + k + 5) ^= *((_BYTE *)S + *(unsigned __int8 *)(v18 + k + 4));
          v20 = *((_DWORD *)this + 2);
          *(_BYTE *)(v20 + k + 6) ^= *((_BYTE *)S + *(unsigned __int8 *)(v19 + k + 5));
          v21 = *((_DWORD *)this + 2);
          *(_BYTE *)(v21 + k + 7) ^= *((_BYTE *)S + *(unsigned __int8 *)(v20 + k + 6));
          v11 = *(_BYTE *)(v21 + k + 7);
        }
        v11 += j;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004521B0
// Name: public: virtual void TaoCrypt::MD2::Final(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::MD2::Final(TaoCrypt::MD2 *this, unsigned __int8 *a2)
{
  int v3; // ebx
  _DWORD *v4; // eax
  unsigned __int8 dst[16]; // [esp+Ch] [ebp-14h] BYREF

  v3 = 16 - *((_DWORD *)this + 10);
  if ( *((_DWORD *)this + 10) != 16 )
    memset(dst, value: v3, count: 16 - *((_DWORD *)this + 10));
  (*(void (__thiscall **)(TaoCrypt::MD2 *, unsigned __int8 *, int))(*(_DWORD *)this + 4))(a1: this, a2: dst, a3: v3);
  (*(void (__thiscall **)(TaoCrypt::MD2 *, _DWORD, int))(*(_DWORD *)this + 4))(
    a1: this,
    a2: *((_DWORD *)this + 5),
    a3: 16);
  v4 = *((_DWORD **)this + 2);
  *(_DWORD *)a2 = *v4;
  *((_DWORD *)a2 + 1) = v4[1];
  *((_DWORD *)a2 + 2) = v4[2];
  *((_DWORD *)a2 + 3) = v4[3];
  (*(void (__thiscall **)(TaoCrypt::MD2 *))(*(_DWORD *)this + 12))(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x00452240
// Name: public: TaoCrypt::MD2::MD2(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlMemory<unsigned short,int> *__thiscall TaoCrypt::MD2::MD2(int this)
{
  unsigned __int8 *v2; // eax
  unsigned int v3; // edi
  unsigned __int8 *v4; // eax
  const CSplitScreenAddedConVar *v5; // ecx
  unsigned __int8 *v6; // eax
  unsigned int v7; // edi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  unsigned int v10; // edi
  unsigned __int8 *v11; // eax

  *(_DWORD *)this = &TaoCrypt::MD2::`vftable';
  *(_DWORD *)(this + 4) = 48;
  v2 = (unsigned __int8 *)operator new[](
                            sz: (const CSplitScreenAddedConVar *)this,
                            sza: (const CSplitScreenAddedConVar *)0x30);
  v3 = *(_DWORD *)(this + 4);
  *(_DWORD *)(this + 8) = v2;
  v4 = (unsigned __int8 *)TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                            a1: this + 12,
                            src: v2,
                            a3: v3,
                            count: v3,
                            a5: 0);
  *(_DWORD *)(this + 8) = v4;
  *(_DWORD *)(this + 4) = v3;
  memset(dst: v4, value: 0, count: v3);
  *(_DWORD *)(this + 16) = 16;
  v6 = (unsigned __int8 *)operator new[](sz: v5, sza: (const CSplitScreenAddedConVar *)0x10);
  v7 = *(_DWORD *)(this + 16);
  *(_DWORD *)(this + 20) = v6;
  v8 = (unsigned __int8 *)TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                            a1: this + 24,
                            src: v6,
                            a3: v7,
                            count: v7,
                            a5: 0);
  *(_DWORD *)(this + 20) = v8;
  *(_DWORD *)(this + 16) = v7;
  memset(dst: v8, value: 0, count: v7);
  *(_DWORD *)(this + 28) = 16;
  v9 = (unsigned __int8 *)operator new[](
                            sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc,
                            sza: (const CSplitScreenAddedConVar *)0x10);
  v10 = *(_DWORD *)(this + 28);
  *(_DWORD *)(this + 32) = v9;
  v11 = (unsigned __int8 *)TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                             a1: this + 36,
                             src: v9,
                             a3: v10,
                             count: v10,
                             a5: 0);
  *(_DWORD *)(this + 32) = v11;
  *(_DWORD *)(this + 28) = v10;
  memset(dst: v11, value: 0, count: v10);
  TaoCrypt::MD2::Init((unsigned __int8 **)this);
  return (const CUtlMemory<unsigned short,int> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x00452310
// Name: public: virtual TaoCrypt::MD2::~MD2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::MD2::~MD2(TaoCrypt::MD2 *this)
{
  unsigned __int8 *v2; // edi
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // edi

  v2 = *((unsigned __int8 **)this + 8);
  memset(dst: v2, value: 0, count: *((_DWORD *)this + 7));
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: v2);
  v3 = *((unsigned __int8 **)this + 5);
  memset(dst: v3, value: 0, count: *((_DWORD *)this + 4));
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: v3);
  v4 = *((unsigned __int8 **)this + 2);
  memset(dst: v4, value: 0, count: *((_DWORD *)this + 1));
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: v4);
  *(_DWORD *)this = &TaoCrypt::HASH::`vftable';
}
