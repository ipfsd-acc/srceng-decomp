// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/arc4.cpp
// Functions: 3
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\arc4.h"

//------------------------------------------------------------------------------
// Address: 0x0044AFF0
// Name: public: void TaoCrypt::ARC4::SetKey(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ARC4::SetKey(TaoCrypt::ARC4 *this, const unsigned __int8 *a2, unsigned int a3)
{
  unsigned int v3; // eax
  char *v4; // esi
  unsigned int v5; // ecx
  int v6; // eax
  char *v7; // edi
  char v8; // dl
  int i; // [esp+10h] [ebp-4h]

  *(_BYTE *)this = 1;
  *((_BYTE *)this + 1) = 0;
  v3 = 0;
  v4 = (char *)this + 2;
  do
  {
    v4[v3] = v3;
    ++v3;
  }
  while ( v3 < 0x100 );
  v5 = 0;
  LOBYTE(v6) = 0;
  v7 = v4;
  for ( i = 256; i != 0; --i )
  {
    v8 = *v7;
    v6 = (unsigned __int8)(v6 + *v7 + a2[v5++]);
    *v7 = v4[v6];
    v4[v6] = v8;
    if ( v5 >= a3 )
      v5 = 0;
    ++v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B060
// Name: private: void TaoCrypt::ARC4::AsmProcess(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::ARC4::AsmProcess(
        TaoCrypt::ARC4 *this@<ecx>,
        int _EBX@<ebx>,
        int _EDI@<edi>,
        int _ESI@<esi>,
        unsigned __int8 *out,
        const LoggingContext_t *in,
        unsigned int length)
{
  int v14; // edx
  char *v15; // ebp
  int v16; // ecx
  char v17; // al
  char v18; // bl
  char v19; // bl
  unsigned __int8 v20; // bl
  unsigned int v25; // [esp+0h] [ebp-4h]
  char vars0; // [esp+4h] [ebp+0h] BYREF

  _EBP = &vars0;
  __asm
  {
    movd    mm3, edi
    movd    mm4, ebx
    movd    mm5, esi
    movd    mm6, ebp
  }
  if ( length != 0 )
  {
    v25 = length;
    LOBYTE(v14) = *((_BYTE *)this + 1);
    v15 = (char *)this + 2;
    v16 = *(unsigned __int8 *)this;
    v17 = v15[v16];
    do
    {
      v14 = (unsigned __int8)(v17 + v14);
      v18 = v15[v14];
      v15[v16] = v18;
      v15[v14] = v17;
      v16 = (unsigned __int8)(v16 + 1);
      v19 = v15[(unsigned __int8)(v18 + v17)];
      v17 = v15[v16];
      v20 = LOBYTE(in->m_ChannelID) ^ v19;
      in = (const LoggingContext_t *)((char *)in + 1);
      *out++ = v20;
      --v25;
    }
    while ( v25 != 0 );
    *(v15 - 2) = v16;
    *(v15 - 1) = v14;
  }
  __asm
  {
    movd    ebp, mm6
    movd    esi, mm5
    movd    ebx, mm4
    movd    edi, mm3
  }
  _m_empty();
}

//------------------------------------------------------------------------------
// Address: 0x0044B0F0
// Name: public: void TaoCrypt::ARC4::Process(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::ARC4::Process(
        TaoCrypt::ARC4 *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        unsigned __int8 *x,
        const LoggingContext_t *in,
        unsigned int length)
{
  unsigned int v7; // ebp
  int v8; // eax
  int v9; // esi
  unsigned __int8 *v10; // edi
  char v11; // dl
  char v12; // dl
  char ina; // [esp+10h] [ebp+8h]
  char lengtha; // [esp+14h] [ebp+Ch]

  v7 = length;
  if ( length != 0 )
  {
    if ( TaoCrypt::isMMX )
    {
      TaoCrypt::ARC4::AsmProcess(this, _EBX: a2, _EDI: a3, _ESI: a4, out: x, in, length);
    }
    else
    {
      LOBYTE(v8) = *((_BYTE *)this + 1);
      v9 = *(unsigned __int8 *)this;
      v10 = x;
      if ( in == (const LoggingContext_t *)x )
      {
        while ( 1 )
        {
          ina = *((_BYTE *)this + v9 + 2);
          v8 = (unsigned __int8)(ina + v8);
          v11 = *((_BYTE *)this + v8 + 2);
          *((_BYTE *)this + v9 + 2) = v11;
          *((_BYTE *)this + v8 + 2) = ina;
          *v10 ^= *((_BYTE *)this + (unsigned __int8)(ina + v11) + 2);
          --v7;
          ++v10;
          if ( v7 == 0 )
            break;
          v9 = (unsigned __int8)(v9 + 1);
        }
        *(_BYTE *)this = v9 + 1;
        *((_BYTE *)this + 1) = v8;
      }
      else
      {
        while ( 1 )
        {
          lengtha = *((_BYTE *)this + v9 + 2);
          v8 = (unsigned __int8)(lengtha + v8);
          v12 = *((_BYTE *)this + v8 + 2);
          *((_BYTE *)this + v9 + 2) = v12;
          *((_BYTE *)this + v8 + 2) = lengtha;
          --v7;
          *v10++ = LOBYTE(in->m_ChannelID) ^ *((_BYTE *)this + (unsigned __int8)(lengtha + v12) + 2);
          in = (const LoggingContext_t *)((char *)in + 1);
          if ( v7 == 0 )
            break;
          v9 = (unsigned __int8)(v9 + 1);
        }
        *(_BYTE *)this = v9 + 1;
        *((_BYTE *)this + 1) = v8;
      }
    }
  }
}
