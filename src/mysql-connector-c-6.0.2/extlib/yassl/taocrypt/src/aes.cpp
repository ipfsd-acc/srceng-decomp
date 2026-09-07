// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/aes.cpp
// Functions: 8
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\aes.h"

//------------------------------------------------------------------------------
// Address: 0x00425D20
// Name: void yaSSL::ysDelete<struct yaSSL::AES::AESImpl>(struct yaSSL::AES::AESImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ysDelete<yaSSL::AES::AESImpl>(void *ptr, _DWORD *ptra)
{
  if ( ptra != nullptr )
  {
    ptra[75] = &TaoCrypt::Mode_BASE::`vftable';
    *ptra = &TaoCrypt::Mode_BASE::`vftable';
  }
  operator delete(ptr: (KeyValues *)*(unsigned __int8 *)yaSSL::ys, ptra);
}

//------------------------------------------------------------------------------
// Address: 0x00449720
// Name: private: void TaoCrypt::AES::AsmEncrypt(unsigned char const __near *,unsigned char __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int32 __userpurge TaoCrypt::AES::AsmEncrypt@<eax>(
        _DWORD *a1@<ecx>,
        int _EBX@<ebx>,
        int _EDI@<edi>,
        unsigned int *inBlock,
        unsigned __int8 *outBlock,
        _DWORD *boxes)
{
  unsigned __int32 v14; // eax
  unsigned __int32 v15; // ebx
  unsigned __int32 v16; // ecx
  unsigned __int32 v17; // edx
  int v24; // edx
  unsigned int v36; // edx
  unsigned int v41; // ecx
  unsigned int v42; // edx
  unsigned __int32 result; // eax
  unsigned __int32 v45; // ebx
  unsigned __int32 *v46; // esi
  int vars0; // [esp+4h] [ebp+0h] BYREF

  _EBP = &vars0;
  __asm
  {
    movd    mm3, edi
    movd    mm4, ebx
  }
  __asm { movd    mm7, ebp }
  _EDI = a1 + 15;
  _EDX = a1[14] - 1;
  __asm
  {
    movd    mm6, edi
    movd    mm5, edx
  }
  v14 = a1[15] ^ _byteswap_ulong(*inBlock);
  v15 = a1[16] ^ _byteswap_ulong(inBlock[1]);
  v16 = a1[17] ^ _byteswap_ulong(inBlock[2]);
  v17 = _EDI[3] ^ _byteswap_ulong(inBlock[3]);
  do
  {
    _ESI = boxes[(unsigned __int8)v17 + 768] ^ boxes[BYTE1(v16) + 512] ^ boxes[BYTE2(v15) + 256] ^ boxes[HIBYTE(v14)];
    __asm { movd    mm0, esi }
    _ESI = boxes[(unsigned __int8)v14 + 768] ^ boxes[BYTE1(v17) + 512] ^ boxes[BYTE2(v16) + 256] ^ boxes[HIBYTE(v15)];
    __asm { movd    mm1, esi }
    _ESI = boxes[(unsigned __int8)v15 + 768] ^ boxes[BYTE1(v14) + 512] ^ boxes[BYTE2(v17) + 256] ^ boxes[HIBYTE(v16)];
    __asm { movd    mm2, esi }
    v24 = boxes[(unsigned __int8)v16 + 768] ^ boxes[BYTE1(v15) + 512] ^ boxes[BYTE2(v14) + 256] ^ boxes[HIBYTE(v17)];
    __asm
    {
      movd    esi, mm6
      movd    eax, mm0
    }
    _ESI += 4;
    __asm
    {
      movd    ebx, mm1
      movd    mm6, esi
      movd    this, mm2
    }
    v14 = *_ESI ^ _EAX;
    v15 = _ESI[1] ^ _EBX;
    __asm { movd    edi, mm5 }
    v16 = _ESI[2] ^ _ECX;
    v17 = _ESI[3] ^ v24;
    --_EDI;
    __asm { movd    mm5, edi }
  }
  while ( _EDI != 0 );
  _ESI = (unsigned __int8)boxes[(unsigned __int8)v17 + 1024]
       ^ boxes[BYTE1(v16) + 1024]
       & 0xFF00
       ^ boxes[BYTE2(v15) + 1024]
       & 0xFF0000
       ^ boxes[HIBYTE(v14) + 1024]
       & 0xFF000000;
  __asm { movd    mm0, esi }
  _ESI = (unsigned __int8)boxes[(unsigned __int8)v14 + 1024]
       ^ boxes[BYTE1(v17) + 1024]
       & 0xFF00
       ^ boxes[BYTE2(v16) + 1024]
       & 0xFF0000
       ^ boxes[HIBYTE(v15) + 1024]
       & 0xFF000000;
  __asm { movd    mm1, esi }
  _ESI = (unsigned __int8)boxes[(unsigned __int8)v15 + 1024]
       ^ boxes[BYTE1(v14) + 1024]
       & 0xFF00
       ^ boxes[BYTE2(v17) + 1024]
       & 0xFF0000
       ^ boxes[HIBYTE(v16) + 1024]
       & 0xFF000000;
  __asm { movd    mm2, esi }
  v36 = (unsigned __int8)boxes[(unsigned __int8)v16 + 1024]
      ^ boxes[BYTE1(v15) + 1024]
      & 0xFF00
      ^ boxes[BYTE2(v14) + 1024]
      & 0xFF0000
      ^ boxes[HIBYTE(v17) + 1024]
      & 0xFF000000;
  __asm
  {
    movd    eax, mm0
    movd    esi, mm6
    movd    ebx, mm1
  }
  _ESI += 4;
  __asm { movd    this, mm2 }
  v41 = _ESI[2] ^ _ECX;
  v42 = _ESI[3] ^ v36;
  __asm { movd    ebp, mm7 }
  result = _byteswap_ulong(*_ESI ^ _EAX);
  v45 = _byteswap_ulong(_ESI[1] ^ _EBX);
  v46 = *(unsigned __int32 **)(_EBP + 12);
  *v46 = result;
  v46[1] = v45;
  v46[2] = _byteswap_ulong(v41);
  v46[3] = _byteswap_ulong(v42);
  __asm
  {
    movd    ebx, mm4
    movd    edi, mm3
  }
  _m_empty();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004499E0
// Name: private: void TaoCrypt::AES::AsmDecrypt(unsigned char const __near *,unsigned char __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int32 __userpurge TaoCrypt::AES::AsmDecrypt@<eax>(
        _DWORD *a1@<ecx>,
        int _EBX@<ebx>,
        int _EDI@<edi>,
        unsigned int *inBlock,
        unsigned __int8 *outBlock,
        _DWORD *boxes)
{
  unsigned __int32 v14; // eax
  unsigned __int32 v15; // ebx
  unsigned __int32 v16; // ecx
  unsigned __int32 v17; // edx
  int v24; // edx
  unsigned int v36; // edx
  unsigned __int32 result; // eax
  unsigned __int32 v43; // ebx
  unsigned __int32 v44; // ecx
  unsigned __int32 v45; // edx
  unsigned __int32 *v46; // esi
  int vars0; // [esp+4h] [ebp+0h] BYREF

  _EBP = &vars0;
  __asm
  {
    movd    mm3, edi
    movd    mm4, ebx
  }
  __asm { movd    mm7, ebp }
  _EDI = a1 + 15;
  _EDX = a1[14] - 1;
  __asm
  {
    movd    mm6, edi
    movd    mm5, edx
  }
  v14 = a1[15] ^ _byteswap_ulong(*inBlock);
  v15 = a1[16] ^ _byteswap_ulong(inBlock[1]);
  v16 = a1[17] ^ _byteswap_ulong(inBlock[2]);
  v17 = _EDI[3] ^ _byteswap_ulong(inBlock[3]);
  do
  {
    _ESI = boxes[(unsigned __int8)v15 + 768] ^ boxes[BYTE1(v16) + 512] ^ boxes[BYTE2(v17) + 256] ^ boxes[HIBYTE(v14)];
    __asm { movd    mm0, esi }
    _ESI = boxes[(unsigned __int8)v16 + 768] ^ boxes[BYTE1(v17) + 512] ^ boxes[BYTE2(v14) + 256] ^ boxes[HIBYTE(v15)];
    __asm { movd    mm1, esi }
    _ESI = boxes[(unsigned __int8)v17 + 768] ^ boxes[BYTE1(v14) + 512] ^ boxes[BYTE2(v15) + 256] ^ boxes[HIBYTE(v16)];
    __asm { movd    mm2, esi }
    v24 = boxes[(unsigned __int8)v14 + 768] ^ boxes[BYTE1(v15) + 512] ^ boxes[BYTE2(v16) + 256] ^ boxes[HIBYTE(v17)];
    __asm { movd    esi, mm6 }
    _ESI += 4;
    __asm
    {
      movd    mm6, esi
      movd    eax, mm0
      movd    ebx, mm1
      movd    this, mm2
    }
    v14 = *_ESI ^ _EAX;
    v15 = _ESI[1] ^ _EBX;
    v16 = _ESI[2] ^ _ECX;
    v17 = _ESI[3] ^ v24;
    __asm { movd    edi, mm5 }
    --_EDI;
    __asm { movd    mm5, edi }
  }
  while ( _EDI != 0 );
  _ESI = (unsigned __int8)boxes[(unsigned __int8)v15 + 1024]
       ^ boxes[BYTE1(v16) + 1024]
       & 0xFF00
       ^ boxes[BYTE2(v17) + 1024]
       & 0xFF0000
       ^ boxes[HIBYTE(v14) + 1024]
       & 0xFF000000;
  __asm { movd    mm0, esi }
  _ESI = (unsigned __int8)boxes[(unsigned __int8)v16 + 1024]
       ^ boxes[BYTE1(v17) + 1024]
       & 0xFF00
       ^ boxes[BYTE2(v14) + 1024]
       & 0xFF0000
       ^ boxes[HIBYTE(v15) + 1024]
       & 0xFF000000;
  __asm { movd    mm1, esi }
  _ESI = (unsigned __int8)boxes[(unsigned __int8)v17 + 1024]
       ^ boxes[BYTE1(v14) + 1024]
       & 0xFF00
       ^ boxes[BYTE2(v15) + 1024]
       & 0xFF0000
       ^ boxes[HIBYTE(v16) + 1024]
       & 0xFF000000;
  __asm { movd    mm2, esi }
  v36 = (unsigned __int8)boxes[(unsigned __int8)v14 + 1024]
      ^ boxes[BYTE1(v15) + 1024]
      & 0xFF00
      ^ boxes[BYTE2(v16) + 1024]
      & 0xFF0000
      ^ boxes[HIBYTE(v17) + 1024]
      & 0xFF000000;
  __asm { movd    esi, mm6 }
  _ESI += 4;
  __asm
  {
    movd    eax, mm0
    movd    ebx, mm1
    movd    this, mm2
  }
  __asm { movd    ebp, mm7 }
  result = _byteswap_ulong(*_ESI ^ _EAX);
  v43 = _byteswap_ulong(_ESI[1] ^ _EBX);
  v44 = _byteswap_ulong(_ESI[2] ^ _ECX);
  v45 = _byteswap_ulong(_ESI[3] ^ v36);
  v46 = *(unsigned __int32 **)(_EBP + 12);
  *v46 = result;
  v46[1] = v43;
  v46[2] = v44;
  v46[3] = v45;
  __asm
  {
    movd    ebx, mm4
    movd    edi, mm3
  }
  _m_empty();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449CA0
// Name: public: virtual void TaoCrypt::AES::Process(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::AES::Process(
        TaoCrypt::AES *this@<ecx>,
        unsigned int a2@<ebp>,
        unsigned __int8 *out,
        const LoggingContext_t *a4,
        unsigned int a5)
{
  CUtlSymbolTable::StringPool_t **m_pElements; // eax
  unsigned int v7; // ebp
  unsigned int *v8; // ebx
  unsigned __int8 *v9; // edi
  unsigned __int8 *v10; // ebx
  unsigned __int16 *p_m_Root; // edi
  unsigned __int8 *v12; // ebx
  unsigned __int8 *v13; // edi
  int v14; // edx

  m_pElements = this->m_StringPools.m_pElements;
  if ( TaoCrypt::isMMX )
  {
    v7 = a5 >> 4;
    if ( m_pElements != nullptr )
    {
      if ( m_pElements == (CUtlSymbolTable::StringPool_t **)1 )
      {
        if ( this->m_StringPools.m_Size != 0 )
        {
          if ( v7 != 0 )
          {
            v12 = (unsigned __int8 *)a4;
            v13 = out;
            do
            {
              --v7;
              TaoCrypt::AES::AsmDecrypt(
                a1: this,
                _EBX: (int)v12,
                _EDI: (int)v13,
                inBlock: (unsigned int *)v12,
                outBlock: v13,
                boxes: TaoCrypt::AES::Td0);
              *(_DWORD *)v13 ^= *(_DWORD *)&this->m_Lookup.m_Root;
              *((_DWORD *)v13 + 1) ^= *(_DWORD *)&this->m_Lookup.m_FirstFree;
              *((_DWORD *)v13 + 2) ^= (unsigned int)this->m_Lookup.m_pElements;
              *((_DWORD *)v13 + 3) ^= *(_DWORD *)&this->m_bInsensitive;
              *(_DWORD *)&this->m_Lookup.m_Root = *(_DWORD *)v12;
              *(_DWORD *)&this->m_Lookup.m_FirstFree = *((_DWORD *)v12 + 1);
              this->m_Lookup.m_pElements = *((UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> **)v12
                                           + 2);
              v14 = *((_DWORD *)v12 + 3);
              v13 += 16;
              v12 += 16;
              *(_DWORD *)&this->m_bInsensitive = v14;
            }
            while ( v7 != 0 );
          }
        }
        else if ( v7 != 0 )
        {
          v10 = out;
          p_m_Root = &this->m_Lookup.m_Root;
          do
          {
            *(_DWORD *)p_m_Root ^= a4->m_ChannelID;
            *(_DWORD *)&this->m_Lookup.m_FirstFree ^= a4->m_Flags;
            this->m_Lookup.m_pElements = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)((int)this->m_Lookup.m_pElements ^ a4->m_Severity);
            *(_DWORD *)&this->m_bInsensitive ^= *(_DWORD *)&a4->m_Color;
            --v7;
            TaoCrypt::AES::AsmEncrypt(
              a1: this,
              _EBX: (int)v10,
              _EDI: (int)p_m_Root,
              inBlock: (unsigned int *)&this->m_Lookup.m_Root,
              outBlock: (unsigned __int8 *)&this->m_Lookup.m_Root,
              boxes: TaoCrypt::AES::Te0);
            ++a4;
            *(_DWORD *)v10 = *(_DWORD *)p_m_Root;
            *((_DWORD *)v10 + 1) = *(_DWORD *)&this->m_Lookup.m_FirstFree;
            *((_DWORD *)v10 + 2) = this->m_Lookup.m_pElements;
            *((_DWORD *)v10 + 3) = *(_DWORD *)&this->m_bInsensitive;
            v10 += 16;
          }
          while ( v7 != 0 );
        }
      }
    }
    else if ( v7 != 0 )
    {
      v8 = (unsigned int *)a4;
      v9 = out;
      do
      {
        --v7;
        if ( this->m_StringPools.m_Size != 0 )
          TaoCrypt::AES::AsmDecrypt(
            a1: this,
            _EBX: (int)v8,
            _EDI: (int)v9,
            inBlock: v8,
            outBlock: v9,
            boxes: TaoCrypt::AES::Td0);
        else
          TaoCrypt::AES::AsmEncrypt(
            a1: this,
            _EBX: (int)v8,
            _EDI: (int)v9,
            inBlock: v8,
            outBlock: v9,
            boxes: TaoCrypt::AES::Te0);
        v9 += 16;
        v8 += 4;
      }
      while ( v7 != 0 );
    }
  }
  else if ( m_pElements != nullptr )
  {
    if ( m_pElements == (CUtlSymbolTable::StringPool_t **)1 )
    {
      if ( this->m_StringPools.m_Size != 0 )
        TaoCrypt::Mode_BASE::CBC_Decrypt(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          a2,
          out,
          in: (unsigned __int8 *)a4,
          sz: a5);
      else
        TaoCrypt::Mode_BASE::CBC_Encrypt(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          a2,
          out,
          in: (unsigned __int8 *)a4,
          sz: a5);
    }
  }
  else
  {
    TaoCrypt::Mode_BASE::ECB_Process((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, out, in: a4, sz: a5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449E30
// Name: public: void TaoCrypt::AES::SetKey(unsigned char const __near *,unsigned int,enum TaoCrypt::CipherDir)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::AES::SetKey(
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *this,
        unsigned __int8 *userKey,
        unsigned int keylen,
        int a4)
{
  CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *v5; // ebx
  CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *v6; // esi
  int result; // eax
  int v8; // ebp
  unsigned int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  unsigned int v14; // eax
  int v15; // ecx
  int m_nAllocationCount; // eax
  int v17; // eax
  int v18; // ecx
  unsigned int v19; // eax
  int v20; // eax
  int v21; // ecx
  int v22; // ebp
  unsigned int v23; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  unsigned int m_nGrowSize; // ecx
  unsigned int v29; // eax
  int v30; // eax
  int v31; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // ecx
  unsigned int v33; // eax
  int *p_m_nAllocationCount; // edi
  int v35; // edx
  int v36; // eax
  int v37; // ebp
  unsigned int v38; // ecx
  int v39; // ecx
  int v40; // edx
  int v41; // ecx
  unsigned int v42; // ebp
  unsigned int v43; // esi
  int *v44; // edx
  int *p_m_nGrowSize; // ecx
  int v46; // edi
  int v47; // ebx
  int v48; // edi
  int v49; // ebx
  int v50; // edi
  int v51; // ebx
  int v52; // edi
  unsigned int v53; // edi
  unsigned int v54; // ecx
  int v55; // edx
  unsigned int v56; // ecx
  int v57; // edx
  unsigned int v58; // ecx
  int v59; // edx
  unsigned int v60; // ecx

  v5 = this;
  v6 = this + 5;
  *((_DWORD *)this + 14) = (keylen >> 2) + 6;
  memcpy(dst: (unsigned __int8 *)this + 60, src: userKey, count: keylen);
  memset(dst: (unsigned __int8 *)v6 + keylen, value: 0, count: 4 * (keylen >> 2) - keylen);
  result = TaoCrypt::ByteReverse<unsigned int>(
             out: (unsigned int *)&v5[5],
             a2: (int)&v5[5],
             byteCount: keylen + 3 - (((_BYTE)keylen + 3) & 3));
  switch ( keylen )
  {
    case 0x10u:
      m_pMemory = v5[6].m_pMemory;
      v33 = (int)v6->m_pMemory
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)m_pMemory)
          & 0xFF00
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE2(v6[1].m_pMemory))
          & 0xFF000000
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE1(v6[1].m_pMemory))
          & 0xFF0000
          ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * ((unsigned int)v6[1].m_pMemory >> 24))
          ^ 0x1000000;
      p_m_nAllocationCount = &v5[6].m_nAllocationCount;
      v35 = v33 ^ v5[5].m_nAllocationCount;
      v5[6].m_nAllocationCount = v33;
      v36 = v35 ^ v5[5].m_nGrowSize;
      v5[7].m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)v36;
      v5[6].m_nGrowSize = v35;
      v5[7].m_nAllocationCount = (unsigned int)m_pMemory ^ v36;
      v37 = 4;
      do
      {
        result = (int)p_m_nAllocationCount;
        v38 = *(_DWORD *)((char *)TaoCrypt::AES::rcon_ + v37)
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)p_m_nAllocationCount[3])
            & 0xFF00
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE2(p_m_nAllocationCount[3]))
            & 0xFF000000
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE1(p_m_nAllocationCount[3]))
            & 0xFF0000
            ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(p_m_nAllocationCount[3]));
        p_m_nAllocationCount += 4;
        v39 = *(_DWORD *)result ^ v38;
        v37 += 4;
        *p_m_nAllocationCount = v39;
        v40 = v39 ^ *(_DWORD *)(result + 4);
        *(_DWORD *)(result + 20) = v40;
        v41 = v40 ^ *(_DWORD *)(result + 8);
        *(_DWORD *)(result + 24) = v41;
        *(_DWORD *)(result + 28) = v41 ^ *(_DWORD *)(result + 12);
      }
      while ( v37 != 40 );
      v5 = this;
      break;
    case 0x18u:
      v22 = 4;
      v23 = (int)v6->m_pMemory
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)v5[6].m_nGrowSize)
          & 0xFF00
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE2(v6[1].m_nGrowSize))
          & 0xFF000000
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE1(v6[1].m_nGrowSize))
          & 0xFF0000
          ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(v6[1].m_nGrowSize))
          ^ 0x1000000;
      v24 = v23 ^ v5[5].m_nAllocationCount;
      v5[7].m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)v23;
      v25 = v24 ^ v5[5].m_nGrowSize;
      v5[7].m_nAllocationCount = v24;
      v26 = v25 ^ (int)v5[6].m_pMemory;
      v5[7].m_nGrowSize = v25;
      v5[8].m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)v26;
      do
      {
        v27 = (int)v6[3].m_pMemory ^ v6[1].m_nAllocationCount;
        v6[3].m_nGrowSize = v27 ^ v6[1].m_nGrowSize;
        v6[3].m_nAllocationCount = v27;
        m_nGrowSize = v6[3].m_nGrowSize;
        v6 += 2;
        v29 = *(_DWORD *)((char *)TaoCrypt::AES::rcon_ + v22)
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)m_nGrowSize)
            & 0xFF00
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE2(m_nGrowSize))
            & 0xFF000000
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE1(m_nGrowSize))
            & 0xFF0000
            ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(m_nGrowSize));
        v22 += 4;
        v30 = (int)v6->m_pMemory ^ v29;
        v6[2].m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)v30;
        v31 = v30 ^ v6->m_nAllocationCount;
        v6[2].m_nAllocationCount = v31;
        result = v31 ^ v6->m_nGrowSize;
        v6[2].m_nGrowSize = result;
        v6[3].m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)(result ^ (int)v6[1].m_pMemory);
      }
      while ( v22 != 32 );
      break;
    case 0x20u:
      v8 = 4;
      v9 = (int)v6->m_pMemory
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)v5[7].m_nAllocationCount)
         & 0xFF00
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE2(v6[2].m_nAllocationCount))
         & 0xFF000000
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE1(v6[2].m_nAllocationCount))
         & 0xFF0000
         ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(v6[2].m_nAllocationCount))
         ^ 0x1000000;
      v10 = v9 ^ v5[5].m_nAllocationCount;
      v5[7].m_nGrowSize = v9;
      v11 = v10 ^ v5[5].m_nGrowSize;
      v5[8].m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)v10;
      v12 = v11 ^ (int)v5[6].m_pMemory;
      v5[8].m_nAllocationCount = v11;
      v5[8].m_nGrowSize = v12;
      do
      {
        v13 = v6[1].m_nGrowSize;
        v14 = v6[1].m_nAllocationCount
            ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)v6[3].m_nGrowSize)
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE1(v6[3].m_nGrowSize))
            & 0xFF00
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(v6[3].m_nGrowSize))
            & 0xFF000000
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE2(v6[3].m_nGrowSize))
            & 0xFF0000;
        v6 = (CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *)((char *)v6 + 32);
        v6[1].m_nAllocationCount = v14;
        v15 = v14 ^ v13;
        m_nAllocationCount = v6[-1].m_nAllocationCount;
        v6[1].m_nGrowSize = v15;
        v17 = v15 ^ m_nAllocationCount;
        v18 = v6[-1].m_nGrowSize;
        v6[2].m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)v17;
        v6[2].m_nAllocationCount = v17 ^ v18;
        v19 = *(_DWORD *)((char *)TaoCrypt::AES::rcon_ + v8)
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)v6[2].m_nAllocationCount)
            & 0xFF00
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE2(v6[2].m_nAllocationCount))
            & 0xFF000000
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)BYTE1(v6[2].m_nAllocationCount))
            & 0xFF0000
            ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(v6[2].m_nAllocationCount));
        v8 += 4;
        v20 = (int)v6->m_pMemory ^ v19;
        v6[2].m_nGrowSize = v20;
        v21 = v20 ^ v6->m_nAllocationCount;
        v6[3].m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)v21;
        result = v21 ^ v6->m_nGrowSize;
        v6[3].m_nAllocationCount = result;
        v6[3].m_nGrowSize = result ^ (int)v6[1].m_pMemory;
      }
      while ( v8 != 28 );
      break;
    default:
      break;
  }
  if ( v5[4].m_pMemory == (CUtlVector<int,CUtlMemory<int,int> > *)1 )
  {
    v42 = 0;
    v43 = 4 * v5[4].m_nGrowSize;
    result = (int)&v5[5];
    if ( v43 != 0 )
    {
      v44 = (int *)(result + 16 * v5[4].m_nGrowSize + 8);
      p_m_nGrowSize = &v5[5].m_nGrowSize;
      do
      {
        v46 = *(p_m_nGrowSize - 2);
        *(p_m_nGrowSize - 2) = *(v44 - 2);
        v47 = *(v44 - 1);
        *(v44 - 2) = v46;
        v48 = *(p_m_nGrowSize - 1);
        *(p_m_nGrowSize - 1) = v47;
        v49 = *v44;
        *(v44 - 1) = v48;
        v50 = *p_m_nGrowSize;
        *p_m_nGrowSize = v49;
        v51 = v44[1];
        *v44 = v50;
        v52 = p_m_nGrowSize[1];
        p_m_nGrowSize[1] = v51;
        v44[1] = v52;
        v42 += 4;
        v43 -= 4;
        p_m_nGrowSize += 4;
        v44 -= 4;
      }
      while ( v42 < v43 );
      v5 = this;
    }
    v53 = 1;
    if ( v5[4].m_nGrowSize > 1u )
    {
      do
      {
        v54 = *(_DWORD *)(result + 16);
        result += 16;
        v55 = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3
                        + 4
                        * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * *(unsigned __int8 *)result))
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0
                        + 4 * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(v54)))
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1
                        + 4 * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE2(v54)))
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2
                        + 4 * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE1(v54)));
        v56 = *(_DWORD *)(result + 4);
        *(_DWORD *)result = v55;
        v57 = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3
                        + 4
                        * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4
                                                     + 4 * *(unsigned __int8 *)(result + 4)))
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0
                        + 4 * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(v56)))
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1
                        + 4 * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE2(v56)))
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2
                        + 4 * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE1(v56)));
        v58 = *(_DWORD *)(result + 8);
        *(_DWORD *)(result + 4) = v57;
        v59 = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3
                        + 4
                        * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4
                                                     + 4 * *(unsigned __int8 *)(result + 8)))
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0
                        + 4 * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(v58)))
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1
                        + 4 * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE2(v58)))
            ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2
                        + 4 * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE1(v58)));
        v60 = *(_DWORD *)(result + 12);
        *(_DWORD *)(result + 8) = v59;
        ++v53;
        *(_DWORD *)(result + 12) = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3
                                             + 4
                                             * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4
                                                                          + 4 * *(unsigned __int8 *)(result + 12)))
                                 ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0
                                             + 4
                                             * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4
                                                                          + 4 * HIBYTE(v60)))
                                 ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1
                                             + 4
                                             * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4
                                                                          + 4 * BYTE2(v60)))
                                 ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2
                                             + 4
                                             * (unsigned __int8)*(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4
                                                                          + 4 * BYTE1(v60)));
      }
      while ( v53 < *((_DWORD *)this + 14) );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A420
// Name: private: void TaoCrypt::AES::encrypt(unsigned char const __near *,unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *__thiscall TaoCrypt::AES::encrypt(
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *this,
        int *s0,
        const LoggingContext_t *xorBlock,
        unsigned __int8 *outBlock)
{
  int v5; // ecx
  int v6; // edx
  int v7; // edi
  int v8; // ebx
  int v9; // ebx
  int v10; // ebp
  unsigned int v11; // esi
  unsigned int v12; // edx
  unsigned int v13; // ebp
  int v14; // esi
  unsigned int v15; // ecx
  unsigned int v16; // edx
  char *v17; // eax
  int v18; // edi
  unsigned int v19; // edx
  int v20; // ecx
  bool v21; // zf
  unsigned int v22; // edi
  unsigned int v23; // ebp
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *v24; // eax
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *v25; // eax
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *v26; // eax
  unsigned int v28; // [esp-4h] [ebp-30h]
  unsigned int t1; // [esp+10h] [ebp-1Ch]
  unsigned int t2; // [esp+14h] [ebp-18h]
  unsigned int s2; // [esp+18h] [ebp-14h]
  unsigned int s2a; // [esp+18h] [ebp-14h]
  unsigned int s3; // [esp+1Ch] [ebp-10h]
  unsigned int s3a; // [esp+1Ch] [ebp-10h]
  unsigned int s3b; // [esp+1Ch] [ebp-10h]
  unsigned int s3c; // [esp+1Ch] [ebp-10h]
  unsigned int ra; // [esp+20h] [ebp-Ch]
  unsigned int r; // [esp+20h] [ebp-Ch]
  _DWORD v39[2]; // [esp+24h] [ebp-8h] BYREF
  unsigned int s0a; // [esp+30h] [ebp+4h]
  unsigned int s0b; // [esp+30h] [ebp+4h]
  unsigned int s0c; // [esp+30h] [ebp+4h]

  v5 = *s0;
  v6 = s0[1];
  v7 = s0[3];
  v8 = *s0;
  s0a = s0[2];
  v39[0] = this;
  this += 5;
  v9 = __ROR4__(v8, 8);
  v10 = __ROR4__(v6, 8);
  ra = __ROR4__(s0a, 8);
  v11 = s0a;
  s3 = __ROR4__(v7, 8);
  s0b = v9 ^ (int)this->m_pMemory ^ (v9 ^ __ROL4__(v5, 8)) & 0xFF00FF;
  v12 = v10 ^ this->m_nAllocationCount ^ (v10 ^ __ROL4__(v6, 8)) & 0xFF00FF;
  v13 = ra ^ this->m_nGrowSize ^ (ra ^ __ROL4__(v11, 8)) & 0xFF00FF;
  v14 = *(_DWORD *)TaoCrypt::AES::Te2;
  s3a = s3 ^ *((_DWORD *)this + 3) ^ (s3 ^ __ROL4__(v7, 8)) & 0xFF00FF;
  v15 = *((_DWORD *)this + 4)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)s3a)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(s0b))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(v12))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te2 + 4 * BYTE1(v13));
  t1 = *((_DWORD *)this + 5)
     ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)s0b)
     ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(v12))
     ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(v13))
     ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te2 + 4 * BYTE1(s3a));
  t2 = *((_DWORD *)this + 6)
     ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)v12)
     ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(v13))
     ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te2 + 4 * BYTE1(s0b))
     ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(s3a));
  v16 = *((_DWORD *)this + 7)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)v13)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(s0b))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(s3a))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te2 + 4 * BYTE1(v12));
  v17 = (char *)this + 32;
  r = (*(_DWORD *)(v39[0] + 56) >> 1) - 1;
  if ( *(_DWORD *)(v39[0] + 56) >> 1 != 1 )
  {
    BYTE1(v18) = BYTE1(t2);
    do
    {
      s0c = *(_DWORD *)v17
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)v16)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(v15))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(t1))
          ^ *(_DWORD *)(v14 + 4 * BYTE1(v18));
      v39[0] = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(t2)) ^ *(_DWORD *)(v14 + 4 * BYTE1(v16));
      s3b = *((_DWORD *)v17 + 1)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)v15)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(t1))
          ^ v39[0];
      s2 = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te2 + 4 * BYTE1(v15))
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(t2))
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(v16));
      v14 = *(_DWORD *)TaoCrypt::AES::Te2;
      v19 = *((_DWORD *)v17 + 3)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)t2)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(v15))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te2 + 4 * BYTE1(t1))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(v16));
      v20 = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te2
                      + 4
                      * (unsigned __int8)((unsigned __int16)(*((_WORD *)v17 + 4)
                                                           ^ *(_WORD *)(*(_DWORD *)TaoCrypt::AES::Te3
                                                                      + 4 * (unsigned __int8)t1)
                                                           ^ s2) >> 8));
      s2a = *((_DWORD *)v17 + 2) ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)t1) ^ s2;
      t1 = *((_DWORD *)v17 + 5)
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)s0c)
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(s3b))
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(s2a))
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te2 + 4 * BYTE1(v19));
      v18 = *((_DWORD *)v17 + 6)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)s3b)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(s2a))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te2 + 4 * BYTE1(s0c))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(v19));
      v15 = *((_DWORD *)v17 + 4)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)v19)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(s0c))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(s3b))
          ^ v20;
      v17 += 32;
      v21 = r-- == 1;
      t2 = v18;
      v16 = *((_DWORD *)v17 - 1)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te3 + 4 * (unsigned __int8)s2a)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te1 + 4 * BYTE2(s0c))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te0 + 4 * HIBYTE(v19))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te2 + 4 * BYTE1(s3b));
    }
    while ( !v21 );
  }
  s3c = *((_DWORD *)v17 + 1)
      ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)v15)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(t1))
      & 0xFF000000
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE1(v16))
      & 0xFF00
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE2(t2))
      & 0xFF0000;
  v22 = *(_DWORD *)v17
      ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)v16)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(v15))
      & 0xFF000000
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE1(t2))
      & 0xFF00
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE2(t1))
      & 0xFF0000;
  v23 = *((_DWORD *)v17 + 2)
      ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)t1)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE1(v15))
      & 0xFF00
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(t2))
      & 0xFF000000
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE2(v16))
      & 0xFF0000;
  v28 = *((_DWORD *)v17 + 3)
      ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * (unsigned __int8)t2)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE1(t1))
      & 0xFF00
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * HIBYTE(v16))
      & 0xFF000000
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Te4 + 4 * BYTE2(v15))
      & 0xFF0000;
  v39[0] = xorBlock;
  v39[1] = outBlock;
  v24 = TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
          this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)v39,
          x: v22);
  v25 = TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
          this: v24,
          x: s3c);
  v26 = TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
          this: v25,
          x: v23);
  return TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
           this: v26,
           x: v28);
}

//------------------------------------------------------------------------------
// Address: 0x0044A970
// Name: private: void TaoCrypt::AES::decrypt(unsigned char const __near *,unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *__thiscall TaoCrypt::AES::decrypt(
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *this,
        _DWORD *t2,
        const LoggingContext_t *xorBlock,
        unsigned __int8 *outBlock)
{
  int v4; // edx
  int v5; // edi
  CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *v6; // eax
  int v7; // ebx
  int v8; // ecx
  unsigned int v9; // ebx
  int v10; // ebp
  int v11; // esi
  int v12; // edi
  int v13; // edx
  int v14; // edi
  int v15; // ecx
  CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // ecx
  int v19; // esi
  unsigned int v20; // edx
  int *p_m_nGrowSize; // eax
  int v22; // esi
  unsigned int v23; // ebx
  int v24; // ecx
  int v25; // edx
  bool v26; // zf
  unsigned int v27; // edi
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *v28; // eax
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *v29; // eax
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *v30; // eax
  unsigned int v32; // [esp-Ch] [ebp-3Ch]
  unsigned int v33; // [esp-8h] [ebp-38h]
  unsigned int v34; // [esp-4h] [ebp-34h]
  unsigned int t0; // [esp+10h] [ebp-20h]
  unsigned int s3; // [esp+14h] [ebp-1Ch]
  unsigned int s3a; // [esp+14h] [ebp-1Ch]
  unsigned int s3b; // [esp+14h] [ebp-1Ch]
  unsigned int s0; // [esp+18h] [ebp-18h]
  unsigned int s2; // [esp+1Ch] [ebp-14h]
  unsigned int s2a; // [esp+1Ch] [ebp-14h]
  unsigned int ra; // [esp+20h] [ebp-10h]
  unsigned int r; // [esp+20h] [ebp-10h]
  _DWORD v45[2]; // [esp+28h] [ebp-8h] BYREF
  unsigned int t2b; // [esp+34h] [ebp+4h]
  CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *t2c; // [esp+34h] [ebp+4h]
  unsigned int t2a; // [esp+34h] [ebp+4h]

  v4 = t2[1];
  v5 = t2[3];
  v6 = this + 5;
  v7 = __ROR4__(*t2, 8);
  v8 = *((_DWORD *)this + 15) ^ (v7 ^ __ROL4__(*t2, 8)) & 0xFF00FF;
  t2b = t2[2];
  v9 = v7 ^ v8;
  v10 = __ROR4__(v4, 8);
  ra = __ROR4__(t2b, 8);
  v11 = v6->m_nGrowSize ^ (ra ^ __ROL4__(t2b, 8)) & 0xFF00FF;
  s3 = __ROR4__(v5, 8);
  v12 = s3 ^ (int)v6[1].m_pMemory ^ (s3 ^ __ROL4__(v5, 8)) & 0xFF00FF;
  v13 = v6->m_nAllocationCount ^ (v10 ^ __ROL4__(v4, 8)) & 0xFF00FF;
  t2c = v6;
  BYTE2(v6) = BYTE2(v12);
  s2 = ra ^ v11;
  s3a = v12;
  v14 = *(_DWORD *)TaoCrypt::AES::Td1;
  v15 = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(v6))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * (unsigned __int8)((unsigned __int16)(ra ^ v11) >> 8));
  v16 = t2c;
  v17 = v10 ^ v13;
  t0 = t2c[1].m_nAllocationCount
     ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)v17)
     ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(v9))
     ^ v15;
  v18 = t2c[1].m_nGrowSize
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)(ra ^ v11))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(v17))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(v9))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(s3a));
  v19 = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(v9));
  v45[0] = v18;
  t2a = (int)t2c[2].m_pMemory
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)s3a)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(s2))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(v17))
      ^ v19;
  v20 = v16[2].m_nAllocationCount
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)v9)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(s3a))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(s2))
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(v17));
  p_m_nGrowSize = &v16[2].m_nGrowSize;
  r = (*((_DWORD *)this + 14) >> 1) - 1;
  if ( *((_DWORD *)this + 14) >> 1 != 1 )
  {
    do
    {
      v45[0] = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(t2a)) ^ *(_DWORD *)(v14 + 4 * BYTE2(v20));
      s0 = *p_m_nGrowSize
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)v18)
         ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(t0))
         ^ v45[0];
      s2a = p_m_nGrowSize[1]
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)t2a)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(t0))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(v18))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(v20));
      v45[0] = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(v18))
             ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(t2a));
      v22 = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(v20));
      v45[0] ^= p_m_nGrowSize[2]
              ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)v20)
              ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(t0));
      v23 = v45[0];
      s3b = p_m_nGrowSize[3]
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)t0)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(v18))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(t2a))
          ^ v22;
      v14 = *(_DWORD *)TaoCrypt::AES::Td1;
      v24 = p_m_nGrowSize[4]
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)s2a)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(s0))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(s3b))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(v45[0]));
      p_m_nGrowSize += 8;
      t0 = v24;
      v25 = *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(s0));
      v45[0] = *(p_m_nGrowSize - 3)
             ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * LOBYTE(v45[0]))
             ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(s2a))
             ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(s0))
             ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(s3b));
      v18 = v45[0];
      t2a = *(p_m_nGrowSize - 2)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)s3b)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(v23))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(s2a))
          ^ v25;
      v26 = r-- == 1;
      v20 = *(p_m_nGrowSize - 1)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td3 + 4 * (unsigned __int8)s0)
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td0 + 4 * HIBYTE(s3b))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td1 + 4 * BYTE2(v23))
          ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td2 + 4 * BYTE1(s2a));
    }
    while ( !v26 );
  }
  v27 = *p_m_nGrowSize
      ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * (unsigned __int8)v18)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * HIBYTE(t0))
      & 0xFF000000
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * BYTE1(t2a))
      & 0xFF00
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * BYTE2(v20))
      & 0xFF0000;
  v34 = p_m_nGrowSize[3]
      ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * (unsigned __int8)t0)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * BYTE1(v18))
      & 0xFF00
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * HIBYTE(v20))
      & 0xFF000000
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * BYTE2(t2a))
      & 0xFF0000;
  v33 = p_m_nGrowSize[2]
      ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * (unsigned __int8)v20)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * BYTE1(t0))
      & 0xFF00
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * HIBYTE(t2a))
      & 0xFF000000
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * BYTE2(v18))
      & 0xFF0000;
  v32 = p_m_nGrowSize[1]
      ^ *(unsigned __int8 *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * (unsigned __int8)t2a)
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * HIBYTE(v18))
      & 0xFF000000
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * BYTE1(v20))
      & 0xFF00
      ^ *(_DWORD *)(*(_DWORD *)TaoCrypt::AES::Td4 + 4 * BYTE2(t0))
      & 0xFF0000;
  v45[1] = outBlock;
  v45[0] = xorBlock;
  v28 = TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
          this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)v45,
          x: v27);
  v29 = TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
          this: v28,
          x: v32);
  v30 = TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
          this: v29,
          x: v33);
  return TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
           this: v30,
           x: v34);
}

//------------------------------------------------------------------------------
// Address: 0x0044AED0
// Name: private: virtual void TaoCrypt::AES::ProcessAndXorBlock(unsigned char const __near *,unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *__thiscall TaoCrypt::AES::ProcessAndXorBlock(
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *this,
        int *s0,
        const LoggingContext_t *xorBlock,
        unsigned __int8 *outBlock)
{
  if ( *((_DWORD *)this + 12) != 0 )
    return TaoCrypt::AES::decrypt(this, t2: s0, xorBlock, outBlock);
  else
    return TaoCrypt::AES::encrypt(this, s0, xorBlock, outBlock);
}
