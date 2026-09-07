// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/coding.cpp
// Functions: 2
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\coding.h"

//------------------------------------------------------------------------------
// Address: 0x0042F2F0
// Name: private: void TaoCrypt::HexDecoder::Decode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::HexDecoder::Decode(ICvar *this)
{
  unsigned int v2; // ebx
  CSplitScreenAddedConVar *v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // edx

  v2 = **((_DWORD **)this + 3);
  v3 = TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
         a1: (int)(this + 2),
         src: *((unsigned __int8 **)this + 1),
         a3: (unsigned int)this->__vftable,
         count: v2 >> 1,
         a5: 0);
  this->__vftable = (ICvar_vtbl *)(v2 >> 1);
  v4 = 0;
  for ( *((_DWORD *)this + 1) = v3; v2 != 0; v2 -= 2 )
  {
    v5 = *((_DWORD *)this + 3);
    v6 = *(_DWORD *)(v5 + 12);
    *(_DWORD *)(v5 + 12) = v6 + 1;
    LOBYTE(v5) = *(_BYTE *)(v6 + *(_DWORD *)(v5 + 4));
    v7 = *((_DWORD *)this + 3);
    v8 = *(_DWORD *)(v7 + 12);
    *(_DWORD *)(v7 + 12) = v8 + 1;
    *(_BYTE *)(v4 + *((_DWORD *)this + 1)) = hexDecode[(unsigned __int8)(*(_BYTE *)(*(_DWORD *)(v7 + 4) + v8) - 48)]
                                           | (16 * hexDecode[(unsigned __int8)(v5 - 48)]);
    ++v4;
  }
  TaoCrypt::Source::reset(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x0042F380
// Name: private: void TaoCrypt::Base64Decoder::Decode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Base64Decoder::Decode(ICvar::Iterator *this)
{
  unsigned int v2; // ebp
  int v3; // eax
  int v4; // ecx
  unsigned __int8 v5; // cl
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // edi
  unsigned __int8 v10; // bl
  int v11; // eax
  int v12; // edi
  unsigned __int8 v13; // al
  char v14; // dl
  unsigned __int8 v15; // cl
  char v16; // bl
  char *v17; // edi
  int v18; // eax
  int v19; // ecx
  char v20; // al
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // ecx
  unsigned __int8 e2; // [esp+11h] [ebp-Bh]
  unsigned __int8 e2a; // [esp+11h] [ebp-Bh]
  bool pad3; // [esp+12h] [ebp-Ah]
  ICvar::ICVarIteratorInternal *i; // [esp+14h] [ebp-8h]
  unsigned int j; // [esp+18h] [ebp-4h]

  v2 = **((_DWORD **)this + 3);
  *((_DWORD *)this + 1) = TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                            a1: (int)(this + 2),
                            src: *((unsigned __int8 **)this + 1),
                            a3: (unsigned int)this->m_pIter,
                            count: (3 * (v2 - ((v2 + 63) >> 6) + 1)) >> 2,
                            a5: 0);
  this->m_pIter = (ICvar::ICVarIteratorInternal *)((3 * (v2 - ((v2 + 63) >> 6) + 1)) >> 2);
  i = nullptr;
  j = 0;
  while ( v2 > 3 )
  {
    v3 = *((_DWORD *)this + 3);
    v4 = *(_DWORD *)(v3 + 12);
    *(_DWORD *)(v3 + 12) = v4 + 1;
    v5 = *(_BYTE *)(v4 + *(_DWORD *)(v3 + 4));
    v6 = *((_DWORD *)this + 3);
    v7 = *(_DWORD *)(v6 + 12);
    *(_DWORD *)(v6 + 12) = v7 + 1;
    LOBYTE(v7) = *(_BYTE *)(v7 + *(_DWORD *)(v6 + 4));
    v8 = *((_DWORD *)this + 3);
    v9 = *(_DWORD *)(v8 + 12);
    e2 = v7;
    *(_DWORD *)(v8 + 12) = v9 + 1;
    v10 = *(_BYTE *)(v9 + *(_DWORD *)(v8 + 4));
    v11 = *((_DWORD *)this + 3);
    v12 = *(_DWORD *)(v11 + 12);
    *(_DWORD *)(v11 + 12) = v12 + 1;
    v13 = *(_BYTE *)(v12 + *(_DWORD *)(v11 + 4));
    if ( v5 == 0 )
      break;
    pad3 = v10 == 61;
    v14 = byte_47C6C5[v5];
    e2a = byte_47C6C5[e2];
    if ( v10 == 61 )
      v15 = 0;
    else
      v15 = byte_47C6C5[v10];
    if ( v13 == 61 )
      v16 = 0;
    else
      v16 = byte_47C6C5[v13];
    *((_BYTE *)&i->__vftable + *((_DWORD *)this + 1)) = (4 * v14) | (e2a >> 4);
    v17 = (char *)&i->__vftable + 1;
    i = (ICvar::ICVarIteratorInternal *)((char *)i + 1);
    if ( !pad3 )
    {
      v17[*((_DWORD *)this + 1)] = (16 * e2a) | (v15 >> 2);
      i = (ICvar::ICVarIteratorInternal *)(v17 + 1);
    }
    if ( v13 == 61 )
      break;
    *((_BYTE *)&i->__vftable + *((_DWORD *)this + 1)) = v16 | (v15 << 6);
    v2 -= 4;
    i = (ICvar::ICVarIteratorInternal *)((char *)i + 1);
    if ( (++j & 0xF) == 0 )
    {
      v18 = *((_DWORD *)this + 3);
      v19 = *(_DWORD *)(v18 + 12);
      *(_DWORD *)(v18 + 12) = v19 + 1;
      v20 = *(_BYTE *)(v19 + *(_DWORD *)(v18 + 4));
      --v2;
      for ( ; v20 == 32; --v2 )
      {
        v21 = *((_DWORD *)this + 3);
        v22 = *(_DWORD *)(v21 + 12);
        *(_DWORD *)(v21 + 12) = v22 + 1;
        v20 = *(_BYTE *)(v22 + *(_DWORD *)(v21 + 4));
      }
      if ( v20 == 13 )
      {
        v23 = *((_DWORD *)this + 3);
        v24 = *(_DWORD *)(v23 + 12);
        *(_DWORD *)(v23 + 12) = v24 + 1;
        v20 = *(_BYTE *)(v24 + *(_DWORD *)(v23 + 4));
        --v2;
      }
      if ( v20 != 10 )
      {
        *(_DWORD *)(*((_DWORD *)this + 3) + 16) = 1041;
        return;
      }
    }
  }
  if ( i != this->m_pIter )
  {
    *((_DWORD *)this + 1) = TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                              a1: (int)(this + 2),
                              src: *((unsigned __int8 **)this + 1),
                              a3: (unsigned int)this->m_pIter,
                              count: (unsigned int)i,
                              a5: 1);
    this->m_pIter = i;
  }
  TaoCrypt::Source::reset(a1: this);
}
