// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/newbitbuf.cpp
// Functions: 13
// ============================================================

#include "tier1\newbitbuf.h"

//------------------------------------------------------------------------------
// Address: 0x102736D0
// Name: public: bool CBitRead::Seek(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBitRead::Seek(CBitRead *this, int nPosition)
{
  int m_nDataBits; // ecx
  signed int v4; // edi
  int v5; // ebx
  const unsigned int *v6; // ecx
  const unsigned int *v7; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int v9; // ecx
  int v10; // eax
  int m_nBitsAvail; // ecx
  const unsigned int *m_pData; // eax
  unsigned int v14; // edx
  int v15; // ecx
  bool bSucc; // [esp+Bh] [ebp-1h]

  m_nDataBits = nPosition;
  bSucc = true;
  if ( nPosition < 0 || nPosition > this->m_nDataBits )
  {
    m_nDataBits = this->m_nDataBits;
    this->m_bOverflow = true;
    bSucc = false;
  }
  v4 = this->m_nDataBytes & 3;
  if ( this->m_nDataBytes < 4 || v4 != 0 && m_nDataBits / 8 < v4 )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      v14 = *(unsigned __int8 *)m_pData;
      m_pData = (const unsigned int *)((char *)m_pData + 1);
      this->m_nInBufWord = v14;
      if ( v4 > 1 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 8;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
      if ( v4 > 2 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 16;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
    }
    this->m_pDataIn = m_pData;
    v15 = m_nDataBits & 0x1F;
    this->m_nInBufWord >>= v15;
    v10 = 8 * v4 - v15;
    goto LABEL_23;
  }
  v5 = m_nDataBits - 8 * v4;
  v6 = this->m_pData;
  v7 = (const unsigned int *)((char *)&v6[v5 / 32] + v4);
  this->m_pDataIn = v7;
  if ( v6 == nullptr )
    goto LABEL_10;
  m_pBufferEnd = this->m_pBufferEnd;
  this->m_nBitsAvail = 32;
  if ( v7 == m_pBufferEnd )
  {
    this->m_pDataIn = v7 + 1;
LABEL_10:
    this->m_nBitsAvail = 1;
LABEL_11:
    this->m_nInBufWord = 0;
    goto LABEL_12;
  }
  if ( v7 > m_pBufferEnd )
  {
    this->m_bOverflow = true;
    goto LABEL_11;
  }
  this->m_nInBufWord = *v7;
  this->m_pDataIn = v7 + 1;
LABEL_12:
  v9 = v5 & 0x1F;
  this->m_nInBufWord >>= v9;
  v10 = 32 - v9;
  m_nBitsAvail = this->m_nBitsAvail;
  if ( m_nBitsAvail < v10 )
  {
    this->m_nBitsAvail = m_nBitsAvail;
    return bSucc;
  }
LABEL_23:
  this->m_nBitsAvail = v10;
  return bSucc;
}

//------------------------------------------------------------------------------
// Address: 0x102737F0
// Name: public: void CBitRead::StartReading(void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::StartReading(
        CBitRead *this,
        const unsigned int *pData,
        unsigned int nBytes,
        int iStartBit,
        int nBits)
{
  int v5; // esi

  v5 = nBits;
  this->m_pData = pData;
  this->m_pDataIn = pData;
  this->m_nDataBytes = nBytes;
  if ( nBits == -1 )
    v5 = 8 * nBytes;
  this->m_nDataBits = v5;
  this->m_bOverflow = false;
  this->m_pBufferEnd = (const unsigned int *)((char *)pData + nBytes);
  if ( pData != nullptr )
    CBitRead::Seek(this, nPosition: iStartBit);
}

//------------------------------------------------------------------------------
// Address: 0x10273830
// Name: public: bool CBitRead::ReadString(char __near *,int,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadString(CBitRead *this, char *pStr, int maxLen, bool bLine, int *pOutNumChars)
{
  int v6; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v9; // ecx
  char v10; // si
  char v11; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v14; // edx
  const unsigned int *v15; // esi
  unsigned int v16; // edi
  int v17; // edx
  const unsigned int *v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // ebx
  int iChar; // [esp+Ch] [ebp-8h]
  bool bTooSmall; // [esp+13h] [ebp-1h]

  bTooSmall = false;
  v6 = 0;
LABEL_2:
  iChar = v6;
  while ( 1 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail < 8 )
      break;
    m_nInBufWord = this->m_nInBufWord;
    v9 = m_nBitsAvail - 8;
    v10 = m_nInBufWord;
    this->m_nBitsAvail = v9;
    if ( v9 != 0 )
    {
      this->m_nInBufWord = m_nInBufWord >> 8;
      v11 = m_nInBufWord;
    }
    else
    {
      m_pDataIn = this->m_pDataIn;
      m_pBufferEnd = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        this->m_pDataIn = m_pDataIn + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v11 = v10;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v14 = *m_pDataIn;
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nInBufWord = v14;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v11 = v10;
      }
    }
LABEL_20:
    if ( v11 == 0 || bLine && v11 == 10 )
      goto LABEL_27;
    if ( v6 < maxLen - 1 )
    {
      pStr[v6++] = v11;
      goto LABEL_2;
    }
    bTooSmall = true;
  }
  v15 = this->m_pBufferEnd;
  v16 = this->m_nInBufWord;
  v17 = 8 - m_nBitsAvail;
  v18 = this->m_pDataIn;
  if ( v18 == v15 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
  }
  else
  {
    if ( v18 > v15 )
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
      goto LABEL_18;
    }
    this->m_nInBufWord = *v18;
  }
  this->m_pDataIn = v18 + 1;
LABEL_18:
  if ( !this->m_bOverflow )
  {
    v19 = this->m_nInBufWord;
    v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v17;
    v11 = v20 | v16;
    v6 = iChar;
    this->m_nInBufWord = v19 >> v17;
    goto LABEL_20;
  }
  v6 = iChar;
LABEL_27:
  pStr[v6] = 0;
  if ( pOutNumChars != nullptr )
    *pOutNumChars = v6;
  return !this->m_bOverflow && !bTooSmall;
}

//------------------------------------------------------------------------------
// Address: 0x10273980
// Name: public: char __near * CBitRead::ReadAndAllocateString(bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBitRead::ReadAndAllocateString(CBitRead *this, bool *pOverflow)
{
  bool v2; // al
  int v3; // ebx
  unsigned int v4; // esi
  char *result; // eax
  char *v6; // edi
  char str[2048]; // [esp+0h] [ebp-804h] BYREF
  int nChars; // [esp+800h] [ebp-4h] BYREF

  v2 = !CBitRead::ReadString(this, pStr: str, maxLen: 2048, bLine: false, pOutNumChars: &nChars);
  if ( pOverflow != nullptr )
    *pOverflow = v2;
  v3 = nChars;
  v4 = nChars + 1;
  result = (char *)MemAlloc_Alloc(nSize: nChars + 1);
  v6 = result;
  if ( v3 >= 0 )
  {
    memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)str, count: v4);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102739F0
// Name: public: __int64 CBitRead::ReadLongLong(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBitRead::ReadLongLong(CBitRead *this)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // esi
  const unsigned int *v4; // eax
  const unsigned int *v5; // ecx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v8; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v10; // esi
  unsigned int v11; // ebx
  int v12; // ecx
  int v13; // ecx
  const unsigned int *v14; // ecx
  const unsigned int *v15; // eax
  const unsigned int *v17; // edi
  int v18; // esi
  const unsigned int *v19; // ecx
  unsigned int v20; // edi
  int v21; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = this->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pBufferEnd = this->m_pBufferEnd;
    m_nInBufWord = this->m_nInBufWord;
    v8 = 32 - m_nBitsAvail;
    m_pDataIn = this->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
        goto LABEL_16;
      }
      this->m_nInBufWord = *m_pDataIn;
    }
    this->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( this->m_bOverflow )
    {
      v21 = 0;
    }
    else
    {
      v10 = this->m_nInBufWord;
      v11 = (v10 & CBitBuffer::s_nMaskTable[v8]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v8;
      v21 = v11 | m_nInBufWord;
      this->m_nInBufWord = v10 >> v8;
    }
    goto LABEL_19;
  }
  v3 = this->m_nInBufWord;
  this->m_nBitsAvail = m_nBitsAvail - 32;
  if ( m_nBitsAvail == 32 )
  {
    v4 = this->m_pDataIn;
    v5 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v4 == v5 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v4 + 1;
      v21 = v3;
    }
    else
    {
      if ( v4 <= v5 )
      {
        this->m_nInBufWord = *v4;
        this->m_pDataIn = v4 + 1;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
      v21 = v3;
    }
  }
  else
  {
    this->m_nInBufWord = 0;
    v21 = v3;
  }
LABEL_19:
  v12 = this->m_nBitsAvail;
  if ( v12 < 32 )
  {
    v17 = this->m_pBufferEnd;
    v18 = 32 - v12;
    v19 = this->m_pDataIn;
    if ( v19 == v17 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v19 > v17 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_33:
        if ( !this->m_bOverflow )
        {
          v20 = this->m_nInBufWord;
          this->m_nBitsAvail = 32 - v18;
          this->m_nInBufWord = v20 >> v18;
        }
        return v21;
      }
      this->m_nInBufWord = *v19;
    }
    this->m_pDataIn = v19 + 1;
    goto LABEL_33;
  }
  v13 = v12 - 32;
  this->m_nBitsAvail = v13;
  if ( v13 != 0 )
  {
LABEL_25:
    this->m_nInBufWord = 0;
    return v21;
  }
  v14 = this->m_pDataIn;
  v15 = this->m_pBufferEnd;
  this->m_nBitsAvail = 32;
  if ( v14 == v15 )
  {
    this->m_nInBufWord = 0;
    this->m_nBitsAvail = 1;
    this->m_pDataIn = v14 + 1;
    return v21;
  }
  if ( v14 > v15 )
  {
    this->m_bOverflow = true;
    goto LABEL_25;
  }
  this->m_nInBufWord = *v14;
  this->m_pDataIn = v14 + 1;
  return v21;
}

//------------------------------------------------------------------------------
// Address: 0x10273BC0
// Name: public: void CBitRead::ReadBits(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::ReadBits(CBitRead *this, char *pOutData, int nBits)
{
  int v4; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v7; // ecx
  char v8; // si
  char v9; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v12; // edx
  const unsigned int *v13; // esi
  unsigned int v14; // edi
  int v15; // edx
  const unsigned int *v16; // ecx
  unsigned int v17; // esi
  unsigned int v18; // ebx
  int v19; // ebx
  int v20; // ecx
  unsigned int v21; // esi
  int v22; // ecx
  unsigned int v23; // ecx
  const unsigned int *v24; // ecx
  const unsigned int *v25; // edx
  unsigned int v26; // edx
  const unsigned int *v27; // esi
  unsigned int v28; // edi
  int v29; // edx
  const unsigned int *v30; // ecx
  unsigned int v31; // esi
  unsigned int v32; // ebx
  int v33; // edi
  unsigned int *v34; // edx
  int v35; // ebx
  int v36; // ecx
  unsigned int v37; // edx
  int v38; // ecx
  char v39; // si
  char v40; // cl
  const unsigned int *v41; // ecx
  const unsigned int *v42; // edx
  unsigned int v43; // edx
  const unsigned int *v44; // esi
  unsigned int v45; // edi
  int v46; // edx
  const unsigned int *v47; // ecx
  unsigned int v48; // esi
  unsigned int v49; // ebx
  char v50; // di
  int v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // esi
  int v54; // ecx
  const unsigned int *v55; // ecx
  const unsigned int *v56; // edx
  _BYTE *v57; // edx
  const unsigned int *v58; // edx
  unsigned int v59; // edi
  int v60; // esi
  const unsigned int *v61; // ecx
  unsigned int v62; // edx
  unsigned int v63; // ebx
  int nBitsLeft; // [esp+18h] [ebp+8h]
  int nBitsa; // [esp+1Ch] [ebp+Ch]
  int nBitsb; // [esp+1Ch] [ebp+Ch]

  v4 = nBits;
  nBitsLeft = nBits;
  if ( ((unsigned __int8)pOutData & 3) != 0 )
  {
    while ( 1 )
    {
      if ( v4 < 8 )
        goto LABEL_23;
      m_nBitsAvail = this->m_nBitsAvail;
      if ( m_nBitsAvail < 8 )
        break;
      m_nInBufWord = this->m_nInBufWord;
      v7 = m_nBitsAvail - 8;
      v8 = m_nInBufWord;
      this->m_nBitsAvail = v7;
      if ( v7 != 0 )
      {
        this->m_nInBufWord = m_nInBufWord >> 8;
        v9 = m_nInBufWord;
      }
      else
      {
        m_pDataIn = this->m_pDataIn;
        m_pBufferEnd = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          v9 = v8;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            v12 = *m_pDataIn;
            this->m_pDataIn = m_pDataIn + 1;
            this->m_nInBufWord = v12;
          }
          else
          {
            this->m_bOverflow = true;
            this->m_nInBufWord = 0;
          }
          v9 = v8;
        }
      }
LABEL_22:
      *pOutData = v9;
      v4 -= 8;
      ++pOutData;
      nBitsLeft = v4;
      if ( ((unsigned __int8)pOutData & 3) == 0 )
        goto LABEL_23;
    }
    v13 = this->m_pBufferEnd;
    v14 = this->m_nInBufWord;
    v15 = 8 - m_nBitsAvail;
    v16 = this->m_pDataIn;
    if ( v16 == v13 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v16 > v13 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_18:
        if ( this->m_bOverflow )
        {
          v9 = 0;
        }
        else
        {
          v17 = this->m_nInBufWord;
          v18 = (v17 & CBitBuffer::s_nMaskTable[v15]) << this->m_nBitsAvail;
          this->m_nBitsAvail = 32 - v15;
          v9 = v18 | v14;
          this->m_nInBufWord = v17 >> v15;
        }
        v4 = nBitsLeft;
        goto LABEL_22;
      }
      this->m_nInBufWord = *v16;
    }
    this->m_pDataIn = v16 + 1;
    goto LABEL_18;
  }
LABEL_23:
  if ( v4 < 32 )
    goto LABEL_45;
  v19 = (unsigned int)v4 >> 5;
  nBitsa = (unsigned int)v4 >> 5;
  nBitsLeft = -32 * ((unsigned int)v4 >> 5) + v4;
  do
  {
    v20 = this->m_nBitsAvail;
    if ( v20 < 32 )
    {
      v27 = this->m_pBufferEnd;
      v28 = this->m_nInBufWord;
      v29 = 32 - v20;
      v30 = this->m_pDataIn;
      if ( v30 == v27 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v30 > v27 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_40;
        }
        this->m_nInBufWord = *v30;
      }
      this->m_pDataIn = v30 + 1;
LABEL_40:
      if ( this->m_bOverflow )
      {
        v23 = 0;
      }
      else
      {
        v31 = this->m_nInBufWord;
        v32 = (v31 & CBitBuffer::s_nMaskTable[v29]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v29;
        v33 = v32 | v28;
        v19 = nBitsa;
        v23 = v33;
        this->m_nInBufWord = v31 >> v29;
      }
      goto LABEL_43;
    }
    v21 = this->m_nInBufWord;
    v22 = v20 - 32;
    this->m_nBitsAvail = v22;
    if ( v22 != 0 )
    {
      this->m_nInBufWord = 0;
      v23 = v21;
    }
    else
    {
      v24 = this->m_pDataIn;
      v25 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v24 == v25 )
      {
        this->m_pDataIn = v24 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v23 = v21;
      }
      else
      {
        if ( v24 <= v25 )
        {
          v26 = *v24;
          this->m_pDataIn = v24 + 1;
          this->m_nInBufWord = v26;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v23 = v21;
      }
    }
LABEL_43:
    v34 = (unsigned int *)pOutData;
    pOutData += 4;
    --v19;
    *v34 = v23;
    nBitsa = v19;
  }
  while ( v19 != 0 );
  v4 = nBitsLeft;
LABEL_45:
  if ( v4 < 8 )
    goto LABEL_67;
  v35 = (unsigned int)v4 >> 3;
  nBitsb = (unsigned int)v4 >> 3;
  nBitsLeft = v4 - 8 * ((unsigned int)v4 >> 3);
  while ( 2 )
  {
    v36 = this->m_nBitsAvail;
    if ( v36 < 8 )
    {
      v44 = this->m_pBufferEnd;
      v45 = this->m_nInBufWord;
      v46 = 8 - v36;
      v47 = this->m_pDataIn;
      if ( v47 == v44 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v47 > v44 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_62;
        }
        this->m_nInBufWord = *v47;
      }
      this->m_pDataIn = v47 + 1;
LABEL_62:
      if ( this->m_bOverflow )
      {
        v40 = 0;
      }
      else
      {
        v48 = this->m_nInBufWord;
        v49 = (v48 & CBitBuffer::s_nMaskTable[v46]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v46;
        v50 = v49 | v45;
        v35 = nBitsb;
        v40 = v50;
        this->m_nInBufWord = v48 >> v46;
      }
      goto LABEL_65;
    }
    v37 = this->m_nInBufWord;
    v38 = v36 - 8;
    v39 = v37;
    this->m_nBitsAvail = v38;
    if ( v38 != 0 )
    {
      this->m_nInBufWord = v37 >> 8;
      v40 = v37;
    }
    else
    {
      v41 = this->m_pDataIn;
      v42 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v41 == v42 )
      {
        this->m_pDataIn = v41 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v40 = v39;
      }
      else
      {
        if ( v41 <= v42 )
        {
          v43 = *v41;
          this->m_pDataIn = v41 + 1;
          this->m_nInBufWord = v43;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v40 = v39;
      }
    }
LABEL_65:
    *pOutData = v40;
    --v35;
    ++pOutData;
    nBitsb = v35;
    if ( v35 != 0 )
      continue;
    break;
  }
  v4 = nBitsLeft;
LABEL_67:
  if ( v4 != 0 )
  {
    v51 = this->m_nBitsAvail;
    if ( v51 >= v4 )
    {
      v52 = this->m_nInBufWord;
      v53 = v52 & CBitBuffer::s_nMaskTable[v4];
      v54 = v51 - v4;
      this->m_nBitsAvail = v54;
      if ( v54 != 0 )
      {
        this->m_nInBufWord = v52 >> v4;
        *pOutData = v53;
      }
      else
      {
        v55 = this->m_pDataIn;
        v56 = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( v55 == v56 )
        {
          this->m_nInBufWord = 0;
          this->m_nBitsAvail = 1;
          this->m_pDataIn = v55 + 1;
          *pOutData = v53;
        }
        else
        {
          if ( v55 <= v56 )
          {
            this->m_nInBufWord = *v55;
            v57 = pOutData;
            this->m_pDataIn = v55 + 1;
          }
          else
          {
            v57 = pOutData;
            this->m_nInBufWord = 0;
            this->m_bOverflow = true;
          }
          *v57 = v53;
        }
      }
      return;
    }
    v58 = this->m_pBufferEnd;
    v59 = this->m_nInBufWord;
    v60 = nBitsLeft - v51;
    v61 = this->m_pDataIn;
    if ( v61 == v58 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
      goto LABEL_82;
    }
    if ( v61 <= v58 )
    {
      this->m_nInBufWord = *v61;
LABEL_82:
      this->m_pDataIn = v61 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
    if ( this->m_bOverflow )
    {
      *pOutData = 0;
    }
    else
    {
      v62 = this->m_nInBufWord;
      v63 = (v62 & CBitBuffer::s_nMaskTable[v60]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v60;
      this->m_nInBufWord = v62 >> v60;
      *pOutData = v63 | v59;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10274030
// Name: public: bool CBitRead::ReadBytes(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadBytes(CBitRead *this, char *pOut, int nBytes)
{
  CBitRead::ReadBits(this, pOutData: pOut, nBits: 8 * nBytes);
  return !this->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x10274060
// Name: public: float CBitRead::ReadBitAngle(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitAngle(CBitRead *this, int numbits)
{
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // edx
  signed int v5; // edi
  int v6; // esi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  double v10; // st7
  unsigned int v11; // edx
  const unsigned int *v12; // edx
  unsigned int v13; // edi
  int v14; // esi
  const unsigned int *v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // ebx
  float shift; // [esp+4h] [ebp-4h]
  int numbitsa; // [esp+10h] [ebp+8h]
  int numbitsb; // [esp+10h] [ebp+8h]

  m_nBitsAvail = this->m_nBitsAvail;
  shift = (float)`GetBitForBitnum'::`2'::bitsForBitnum[numbits & 0x1F];
  if ( m_nBitsAvail >= numbits )
  {
    m_nInBufWord = this->m_nInBufWord;
    v5 = m_nInBufWord & CBitBuffer::s_nMaskTable[numbits];
    v6 = m_nBitsAvail - numbits;
    this->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      this->m_nInBufWord = m_nInBufWord >> numbits;
      return 360.0 / shift * (double)v5;
    }
    else
    {
      m_pDataIn = this->m_pDataIn;
      m_pBufferEnd = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = m_pDataIn + 1;
        return 360.0 / shift * (double)v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v11 = *m_pDataIn;
          v10 = 360.0 / shift;
          numbitsa = v5;
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nInBufWord = v11;
        }
        else
        {
          numbitsa = v5;
          v10 = 360.0 / shift;
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        return v10 * (double)numbitsa;
      }
    }
  }
  v12 = this->m_pBufferEnd;
  v13 = this->m_nInBufWord;
  v14 = numbits - m_nBitsAvail;
  v15 = this->m_pDataIn;
  if ( v15 == v12 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
LABEL_15:
    this->m_pDataIn = v15 + 1;
    goto LABEL_16;
  }
  if ( v15 <= v12 )
  {
    this->m_nInBufWord = *v15;
    goto LABEL_15;
  }
  this->m_bOverflow = true;
  this->m_nInBufWord = 0;
LABEL_16:
  if ( this->m_bOverflow )
  {
    numbitsb = 0;
  }
  else
  {
    v16 = this->m_nInBufWord;
    v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v14;
    numbitsb = v17 | v13;
    this->m_nInBufWord = v16 >> v14;
  }
  return 360.0 / shift * (double)numbitsb;
}

//------------------------------------------------------------------------------
// Address: 0x102741C0
// Name: public: float CBitRead::ReadBitCoord(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitCoord(CBitRead *this)
{
  unsigned int m_nInBufWord; // ecx
  int v3; // esi
  bool v4; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v7; // ecx
  int v8; // ebx
  const unsigned int *v9; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // ecx
  const unsigned int *v12; // ecx
  const unsigned int *v13; // edx
  int m_nBitsAvail; // ecx
  unsigned int v15; // edx
  int v16; // ecx
  unsigned int v17; // esi
  int v18; // edi
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edx
  unsigned int v21; // edx
  const unsigned int *v22; // esi
  unsigned int v23; // edi
  int v24; // edx
  const unsigned int *v25; // ecx
  unsigned int v26; // esi
  unsigned int v27; // ebx
  int v28; // ecx
  unsigned int v29; // edx
  int v30; // ecx
  int v31; // edi
  const unsigned int *v32; // ecx
  const unsigned int *v33; // edx
  unsigned int v34; // edx
  const unsigned int *v35; // esi
  unsigned int v36; // edi
  int v37; // edx
  const unsigned int *v38; // ecx
  unsigned int v39; // esi
  unsigned int v40; // ebx
  float v41; // xmm0_4
  int v43; // [esp+0h] [ebp-14h]
  int fractval; // [esp+4h] [ebp-10h]
  int v45; // [esp+8h] [ebp-Ch]
  int intval; // [esp+Ch] [ebp-8h]
  float value; // [esp+10h] [ebp-4h]

  m_nInBufWord = this->m_nInBufWord;
  v3 = m_nInBufWord & 1;
  v4 = this->m_nBitsAvail-- == 1;
  value = 0.0;
  if ( v4 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  v7 = this->m_nInBufWord;
  v8 = v7 & 1;
  v4 = this->m_nBitsAvail-- == 1;
  intval = v3;
  v45 = v8;
  if ( v4 )
  {
    v9 = this->m_pDataIn;
    v10 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v9 + 1;
    }
    else if ( v9 <= v10 )
    {
      this->m_nInBufWord = *v9;
      this->m_pDataIn = v9 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v7 >> 1;
  }
  fractval = v8;
  if ( v3 == 0 && v8 == 0 )
    return value;
  v11 = this->m_nInBufWord;
  v4 = this->m_nBitsAvail-- == 1;
  v43 = v11 & 1;
  if ( v4 )
  {
    v12 = this->m_pDataIn;
    v13 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v12 == v13 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v12 + 1;
    }
    else if ( v12 <= v13 )
    {
      this->m_nInBufWord = *v12;
      this->m_pDataIn = v12 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v11 >> 1;
  }
  if ( v3 != 0 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail >= 14 )
    {
      v15 = this->m_nInBufWord;
      v16 = m_nBitsAvail - 14;
      v17 = 0;
      v18 = v15 & 0x3FFF;
      this->m_nBitsAvail = v16;
      if ( v16 != 0 )
      {
        this->m_nInBufWord = v15 >> 14;
LABEL_43:
        intval = v18 + 1;
        goto LABEL_44;
      }
      v19 = this->m_pDataIn;
      v20 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v19 == v20 )
      {
        this->m_nBitsAvail = 1;
        this->m_pDataIn = v19 + 1;
      }
      else
      {
        if ( v19 <= v20 )
        {
          v21 = *v19;
          this->m_pDataIn = v19 + 1;
          this->m_nInBufWord = v21;
          goto LABEL_43;
        }
        this->m_bOverflow = true;
      }
LABEL_42:
      this->m_nInBufWord = v17;
      goto LABEL_43;
    }
    v22 = this->m_pBufferEnd;
    v23 = this->m_nInBufWord;
    v24 = 14 - m_nBitsAvail;
    v25 = this->m_pDataIn;
    if ( v25 == v22 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v22 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_39:
        if ( this->m_bOverflow )
        {
          v18 = 0;
          goto LABEL_43;
        }
        v26 = this->m_nInBufWord;
        v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v24;
        v18 = v27 | v23;
        v8 = v45;
        v17 = v26 >> v24;
        goto LABEL_42;
      }
      this->m_nInBufWord = *v25;
    }
    this->m_pDataIn = v25 + 1;
    goto LABEL_39;
  }
LABEL_44:
  if ( v8 == 0 )
  {
    v31 = fractval;
    goto LABEL_63;
  }
  v28 = this->m_nBitsAvail;
  if ( v28 >= 5 )
  {
    v29 = this->m_nInBufWord;
    v30 = v28 - 5;
    v31 = v29 & 0x1F;
    this->m_nBitsAvail = v30;
    if ( v30 != 0 )
    {
      this->m_nInBufWord = v29 >> 5;
    }
    else
    {
      v32 = this->m_pDataIn;
      v33 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v32 == v33 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v32 + 1;
      }
      else if ( v32 <= v33 )
      {
        v34 = *v32;
        this->m_pDataIn = v32 + 1;
        this->m_nInBufWord = v34;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
    }
    goto LABEL_63;
  }
  v35 = this->m_pBufferEnd;
  v36 = this->m_nInBufWord;
  v37 = 5 - v28;
  v38 = this->m_pDataIn;
  if ( v38 == v35 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
  }
  else
  {
    if ( v38 > v35 )
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
      goto LABEL_59;
    }
    this->m_nInBufWord = *v38;
  }
  this->m_pDataIn = v38 + 1;
LABEL_59:
  if ( this->m_bOverflow )
  {
    v31 = 0;
  }
  else
  {
    v39 = this->m_nInBufWord;
    v40 = (v39 & CBitBuffer::s_nMaskTable[v37]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v37;
    v31 = v40 | v36;
    this->m_nInBufWord = v39 >> v37;
  }
LABEL_63:
  v41 = (float)((float)v31 * 0.03125) + (double)intval;
  value = v41;
  if ( v43 != 0 )
    LODWORD(value) = LODWORD(v41) ^ _mask__NegFloat_;
  return value;
}

//------------------------------------------------------------------------------
// Address: 0x10274500
// Name: public: float CBitRead::ReadBitCoordMP(enum EBitCoordType)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitCoordMP(CBitRead *this, EBitCoordType coordType)
{
  bool v3; // bl
  unsigned int m_nInBufWord; // ecx
  int v5; // edx
  bool v6; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int v9; // ecx
  unsigned int v10; // esi
  const unsigned int *v11; // ecx
  const unsigned int *v12; // edx
  unsigned int v13; // ecx
  int v14; // edx
  const unsigned int *v15; // ecx
  const unsigned int *v16; // esi
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // ecx
  int v20; // esi
  int v21; // edi
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edx
  const unsigned int *v25; // esi
  unsigned int v26; // edi
  int v27; // edx
  const unsigned int *v28; // ecx
  unsigned int v29; // esi
  unsigned int v30; // ebx
  double v31; // st7
  float v32; // xmm0_4
  unsigned int v33; // edx
  int v34; // ecx
  int v35; // esi
  int v36; // edi
  const unsigned int *v37; // ecx
  const unsigned int *v38; // edx
  unsigned int v39; // edx
  const unsigned int *v40; // esi
  unsigned int v41; // edi
  int v42; // edx
  const unsigned int *v43; // ecx
  unsigned int v44; // esi
  unsigned int v45; // ebx
  unsigned int v46; // edi
  const unsigned int *v47; // ecx
  const unsigned int *v48; // edx
  unsigned int v49; // ecx
  int v50; // edx
  const unsigned int *v51; // ecx
  const unsigned int *v52; // esi
  int v53; // ecx
  unsigned int v54; // edx
  int v55; // ecx
  int v56; // edi
  const unsigned int *v57; // ecx
  const unsigned int *v58; // edx
  int v59; // edx
  unsigned int v60; // edx
  int v61; // ecx
  unsigned int v62; // edx
  const unsigned int *v63; // esi
  unsigned int v64; // edi
  int v65; // edx
  const unsigned int *v66; // ecx
  unsigned int v67; // esi
  unsigned int v68; // ebx
  int m_nBitsAvail; // ecx
  int v70; // edx
  unsigned int v71; // esi
  signed int v72; // edi
  int v73; // ecx
  const unsigned int *v74; // ecx
  const unsigned int *v75; // edx
  const unsigned int *v76; // esi
  unsigned int v77; // edi
  const unsigned int *v78; // ecx
  double v79; // xmm0_8
  int signbit; // [esp+0h] [ebp-10h]
  int intval; // [esp+4h] [ebp-Ch]
  float value; // [esp+8h] [ebp-8h]
  bool bLowPrecision; // [esp+Fh] [ebp-1h]
  bool bInBounds_3; // [esp+1Bh] [ebp+Bh]

  v3 = coordType == kCW_Integral;
  m_nInBufWord = this->m_nInBufWord;
  bLowPrecision = coordType == kCW_LowPrecision;
  v5 = m_nInBufWord & 1;
  v6 = this->m_nBitsAvail-- == 1;
  value = 0.0;
  if ( v6 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  v9 = this->m_nInBufWord;
  bInBounds_3 = v5 != 0;
  if ( !v3 )
  {
    v46 = this->m_nInBufWord & 1;
    v6 = this->m_nBitsAvail-- == 1;
    if ( v6 )
    {
      v47 = this->m_pDataIn;
      v48 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v47 == v48 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v47 + 1;
      }
      else if ( v47 <= v48 )
      {
        this->m_nInBufWord = *v47;
        this->m_pDataIn = v47 + 1;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
    }
    else
    {
      this->m_nInBufWord = v9 >> 1;
    }
    v49 = this->m_nInBufWord;
    v50 = v49 & 1;
    v6 = this->m_nBitsAvail-- == 1;
    intval = v46;
    if ( v6 )
    {
      v51 = this->m_pDataIn;
      v52 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v51 == v52 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v51 + 1;
      }
      else if ( v51 <= v52 )
      {
        this->m_nInBufWord = *v51;
        this->m_pDataIn = v51 + 1;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
    }
    else
    {
      this->m_nInBufWord = v49 >> 1;
    }
    signbit = v50;
    if ( v46 == 0 )
    {
LABEL_104:
      m_nBitsAvail = this->m_nBitsAvail;
      v70 = 2 * !bLowPrecision + 3;
      if ( m_nBitsAvail >= v70 )
      {
        v71 = this->m_nInBufWord;
        v72 = v71 & CBitBuffer::s_nMaskTable[v70];
        v73 = m_nBitsAvail - v70;
        this->m_nBitsAvail = v73;
        if ( v73 == 0 )
        {
          v74 = this->m_pDataIn;
          v75 = this->m_pBufferEnd;
          this->m_nBitsAvail = 32;
          if ( v74 == v75 )
          {
            this->m_nBitsAvail = 1;
            this->m_nInBufWord = 0;
            this->m_pDataIn = v74 + 1;
          }
          else if ( v74 <= v75 )
          {
            this->m_nInBufWord = *v74;
            this->m_pDataIn = v74 + 1;
          }
          else
          {
            this->m_bOverflow = true;
            this->m_nInBufWord = 0;
          }
LABEL_121:
          if ( bLowPrecision )
            v79 = 0.125;
          else
            v79 = 0.03125;
          v32 = (float)v72 * v79 + (double)intval;
          value = v32;
          goto LABEL_125;
        }
        goto LABEL_120;
      }
      v76 = this->m_pBufferEnd;
      v77 = this->m_nInBufWord;
      v70 -= m_nBitsAvail;
      v78 = this->m_pDataIn;
      if ( v78 == v76 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v78 > v76 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
LABEL_117:
          if ( this->m_bOverflow )
          {
            v72 = 0;
            goto LABEL_121;
          }
          v71 = this->m_nInBufWord;
          v72 = ((v71 & CBitBuffer::s_nMaskTable[v70]) << this->m_nBitsAvail) | v77;
          this->m_nBitsAvail = 32 - v70;
LABEL_120:
          this->m_nInBufWord = v71 >> v70;
          goto LABEL_121;
        }
        this->m_nInBufWord = *v78;
      }
      this->m_pDataIn = v78 + 1;
      goto LABEL_117;
    }
    v53 = this->m_nBitsAvail;
    if ( bInBounds_3 )
    {
      if ( v53 >= 11 )
      {
        v54 = this->m_nInBufWord;
        v55 = v53 - 11;
        v56 = v54 & 0x7FF;
        this->m_nBitsAvail = v55;
        if ( v55 != 0 )
        {
          this->m_nInBufWord = v54 >> 11;
LABEL_103:
          intval = v56 + 1;
          goto LABEL_104;
        }
        goto LABEL_84;
      }
      v59 = 11;
    }
    else
    {
      if ( v53 >= 14 )
      {
        v60 = this->m_nInBufWord;
        v61 = v53 - 14;
        v56 = v60 & 0x3FFF;
        this->m_nBitsAvail = v61;
        if ( v61 != 0 )
        {
          this->m_nInBufWord = v60 >> 14;
          goto LABEL_103;
        }
LABEL_84:
        v57 = this->m_pDataIn;
        v58 = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( v57 == v58 )
        {
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          this->m_pDataIn = v57 + 1;
        }
        else if ( v57 <= v58 )
        {
          v62 = *v57;
          this->m_pDataIn = v57 + 1;
          this->m_nInBufWord = v62;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        goto LABEL_103;
      }
      v59 = 14;
    }
    v63 = this->m_pBufferEnd;
    v64 = this->m_nInBufWord;
    v65 = v59 - v53;
    v66 = this->m_pDataIn;
    if ( v66 == v63 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v66 > v63 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
        goto LABEL_100;
      }
      this->m_nInBufWord = *v66;
    }
    this->m_pDataIn = v66 + 1;
LABEL_100:
    if ( this->m_bOverflow )
    {
      v56 = 0;
    }
    else
    {
      v67 = this->m_nInBufWord;
      v68 = (v67 & CBitBuffer::s_nMaskTable[v65]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v65;
      v56 = v68 | v64;
      this->m_nInBufWord = v67 >> v65;
    }
    goto LABEL_103;
  }
  v10 = this->m_nInBufWord & 1;
  v6 = this->m_nBitsAvail-- == 1;
  if ( v6 )
  {
    v11 = this->m_pDataIn;
    v12 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v11 == v12 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v11 + 1;
    }
    else if ( v11 <= v12 )
    {
      this->m_nInBufWord = *v11;
      this->m_pDataIn = v11 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v9 >> 1;
  }
  if ( v10 != 0 )
  {
    v13 = this->m_nInBufWord;
    v14 = v13 & 1;
    v6 = this->m_nBitsAvail-- == 1;
    if ( v6 )
    {
      v15 = this->m_pDataIn;
      v16 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v15 == v16 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v15 + 1;
      }
      else if ( v15 <= v16 )
      {
        this->m_nInBufWord = *v15;
        this->m_pDataIn = v15 + 1;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
    }
    else
    {
      this->m_nInBufWord = v13 >> 1;
    }
    v17 = this->m_nBitsAvail;
    signbit = v14;
    if ( bInBounds_3 )
    {
      if ( v17 >= 11 )
      {
        v18 = this->m_nInBufWord;
        v19 = v17 - 11;
        v20 = v18 & 0x7FF;
        this->m_nBitsAvail = v19;
        if ( v19 != 0 )
        {
          this->m_nInBufWord = v18 >> 11;
          v21 = v18 & 0x7FF;
        }
        else
        {
          v22 = this->m_pDataIn;
          v23 = this->m_pBufferEnd;
          this->m_nBitsAvail = 32;
          if ( v22 == v23 )
          {
            this->m_nBitsAvail = 1;
            this->m_nInBufWord = 0;
            this->m_pDataIn = v22 + 1;
            v21 = v20;
          }
          else
          {
            if ( v22 <= v23 )
            {
              v24 = *v22;
              this->m_pDataIn = v22 + 1;
              this->m_nInBufWord = v24;
            }
            else
            {
              this->m_bOverflow = true;
              this->m_nInBufWord = 0;
            }
            v21 = v20;
          }
        }
LABEL_43:
        v31 = (double)(v21 + 1);
        if ( v21 + 1 < 0 )
        {
          value = v31 + 4294967300.0;
          v32 = value;
          goto LABEL_125;
        }
LABEL_64:
        value = v31;
        v32 = value;
LABEL_125:
        if ( signbit != 0 )
          LODWORD(value) = LODWORD(v32) ^ _mask__NegFloat_;
        return value;
      }
      v25 = this->m_pBufferEnd;
      v26 = this->m_nInBufWord;
      v27 = 11 - v17;
      v28 = this->m_pDataIn;
      if ( v28 == v25 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v28 > v25 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_40;
        }
        this->m_nInBufWord = *v28;
      }
      this->m_pDataIn = v28 + 1;
LABEL_40:
      if ( this->m_bOverflow )
      {
        v21 = 0;
      }
      else
      {
        v29 = this->m_nInBufWord;
        v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v27;
        v21 = v30 | v26;
        this->m_nInBufWord = v29 >> v27;
      }
      goto LABEL_43;
    }
    if ( v17 >= 14 )
    {
      v33 = this->m_nInBufWord;
      v34 = v17 - 14;
      v35 = v33 & 0x3FFF;
      this->m_nBitsAvail = v34;
      if ( v34 != 0 )
      {
        this->m_nInBufWord = v33 >> 14;
        v36 = v33 & 0x3FFF;
      }
      else
      {
        v37 = this->m_pDataIn;
        v38 = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( v37 == v38 )
        {
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          this->m_pDataIn = v37 + 1;
          v36 = v35;
        }
        else
        {
          if ( v37 <= v38 )
          {
            v39 = *v37;
            this->m_pDataIn = v37 + 1;
            this->m_nInBufWord = v39;
          }
          else
          {
            this->m_bOverflow = true;
            this->m_nInBufWord = 0;
          }
          v36 = v35;
        }
      }
      goto LABEL_63;
    }
    v40 = this->m_pBufferEnd;
    v41 = this->m_nInBufWord;
    v42 = 14 - v17;
    v43 = this->m_pDataIn;
    if ( v43 == v40 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v43 > v40 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
        goto LABEL_60;
      }
      this->m_nInBufWord = *v43;
    }
    this->m_pDataIn = v43 + 1;
LABEL_60:
    if ( this->m_bOverflow )
    {
      v36 = 0;
    }
    else
    {
      v44 = this->m_nInBufWord;
      v45 = (v44 & CBitBuffer::s_nMaskTable[v42]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v42;
      v36 = v45 | v41;
      this->m_nInBufWord = v44 >> v42;
    }
LABEL_63:
    v31 = (double)(unsigned int)(v36 + 1);
    goto LABEL_64;
  }
  return value;
}

//------------------------------------------------------------------------------
// Address: 0x10274B10
// Name: public: float CBitRead::ReadBitCellCoord(int,enum EBitCoordType)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitCellCoord(CBitRead *this, int bits, EBitCoordType coordType)
{
  int m_nBitsAvail; // esi
  bool v6; // zf
  char v7; // cl
  unsigned int m_nInBufWord; // edx
  unsigned int v9; // edi
  int v10; // esi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v13; // edx
  const unsigned int *v14; // edx
  unsigned int v15; // edi
  int v16; // esi
  const unsigned int *v17; // ecx
  unsigned int v19; // edx
  unsigned int v20; // edi
  int v21; // esi
  unsigned int v22; // edx
  const unsigned int *v23; // ecx
  const unsigned int *v24; // edx
  const unsigned int *v25; // edx
  unsigned int v26; // edi
  int v27; // esi
  const unsigned int *v28; // ecx
  unsigned int v29; // edx
  unsigned int v30; // ebx
  int v31; // ecx
  int v32; // edx
  unsigned int v33; // esi
  int v34; // edi
  int v35; // ecx
  unsigned int v36; // esi
  const unsigned int *v37; // ecx
  const unsigned int *v38; // edx
  const unsigned int *v39; // esi
  unsigned int v40; // edi
  int v41; // edx
  const unsigned int *v42; // ecx
  unsigned int v43; // esi
  unsigned int v44; // ebx
  double v45; // xmm0_8
  int value; // [esp+14h] [ebp+8h]
  bool bLowPrecision_3; // [esp+1Bh] [ebp+Fh]

  m_nBitsAvail = this->m_nBitsAvail;
  bLowPrecision_3 = coordType == kCW_LowPrecision;
  v6 = coordType == kCW_Integral;
  v7 = bits;
  if ( v6 )
  {
    if ( m_nBitsAvail >= bits )
    {
      m_nInBufWord = this->m_nInBufWord;
      v9 = m_nInBufWord & CBitBuffer::s_nMaskTable[bits];
      v10 = m_nBitsAvail - bits;
      this->m_nBitsAvail = v10;
      if ( v10 == 0 )
      {
        m_pDataIn = this->m_pDataIn;
        m_pBufferEnd = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          this->m_pDataIn = m_pDataIn + 1;
          return (double)v9;
        }
        if ( m_pDataIn > m_pBufferEnd )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          return (double)v9;
        }
        v13 = *m_pDataIn;
        this->m_pDataIn = m_pDataIn + 1;
LABEL_19:
        this->m_nInBufWord = v13;
        return (double)v9;
      }
LABEL_18:
      v13 = m_nInBufWord >> v7;
      goto LABEL_19;
    }
    v14 = this->m_pBufferEnd;
    v15 = this->m_nInBufWord;
    v16 = bits - m_nBitsAvail;
    v17 = this->m_pDataIn;
    if ( v17 == v14 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v17 > v14 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_15:
        if ( this->m_bOverflow )
          return (double)0;
        m_nInBufWord = this->m_nInBufWord;
        v9 = ((m_nInBufWord & CBitBuffer::s_nMaskTable[v16]) << this->m_nBitsAvail) | v15;
        this->m_nBitsAvail = 32 - v16;
        v7 = v16;
        goto LABEL_18;
      }
      this->m_nInBufWord = *v17;
    }
    this->m_pDataIn = v17 + 1;
    goto LABEL_15;
  }
  if ( m_nBitsAvail < bits )
  {
    v25 = this->m_pBufferEnd;
    v26 = this->m_nInBufWord;
    v27 = bits - m_nBitsAvail;
    v28 = this->m_pDataIn;
    if ( v28 == v25 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_35:
        if ( this->m_bOverflow )
        {
          value = 0;
          goto LABEL_40;
        }
        v29 = this->m_nInBufWord;
        v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v27;
        v20 = v30 | v26;
        v22 = v29 >> v27;
        goto LABEL_38;
      }
      this->m_nInBufWord = *v28;
    }
    this->m_pDataIn = v28 + 1;
    goto LABEL_35;
  }
  v19 = this->m_nInBufWord;
  v20 = v19 & CBitBuffer::s_nMaskTable[bits];
  v21 = m_nBitsAvail - bits;
  this->m_nBitsAvail = v21;
  if ( v21 != 0 )
  {
    v22 = v19 >> bits;
LABEL_38:
    this->m_nInBufWord = v22;
    goto LABEL_39;
  }
  v23 = this->m_pDataIn;
  v24 = this->m_pBufferEnd;
  this->m_nBitsAvail = 32;
  if ( v23 == v24 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_pDataIn = v23 + 1;
  }
  else
  {
    if ( v23 <= v24 )
    {
      v22 = *v23;
      this->m_pDataIn = v23 + 1;
      goto LABEL_38;
    }
    this->m_bOverflow = true;
    this->m_nInBufWord = 0;
  }
LABEL_39:
  value = v20;
LABEL_40:
  v31 = this->m_nBitsAvail;
  v32 = 2 * !bLowPrecision_3 + 3;
  if ( v31 >= v32 )
  {
    v33 = this->m_nInBufWord;
    v34 = v33 & CBitBuffer::s_nMaskTable[v32];
    v35 = v31 - v32;
    this->m_nBitsAvail = v35;
    if ( v35 != 0 )
    {
      v36 = v33 >> v32;
LABEL_57:
      this->m_nInBufWord = v36;
      goto LABEL_58;
    }
    v37 = this->m_pDataIn;
    v38 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v37 == v38 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v37 + 1;
    }
    else if ( v37 <= v38 )
    {
      this->m_nInBufWord = *v37;
      this->m_pDataIn = v37 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
    goto LABEL_58;
  }
  v39 = this->m_pBufferEnd;
  v40 = this->m_nInBufWord;
  v41 = v32 - v31;
  v42 = this->m_pDataIn;
  if ( v42 == v39 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
LABEL_53:
    this->m_pDataIn = v42 + 1;
    goto LABEL_54;
  }
  if ( v42 <= v39 )
  {
    this->m_nInBufWord = *v42;
    goto LABEL_53;
  }
  this->m_bOverflow = true;
  this->m_nInBufWord = 0;
LABEL_54:
  if ( !this->m_bOverflow )
  {
    v43 = this->m_nInBufWord;
    v44 = (v43 & CBitBuffer::s_nMaskTable[v41]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v41;
    v34 = v44 | v40;
    v36 = v43 >> v41;
    goto LABEL_57;
  }
  v34 = 0;
LABEL_58:
  if ( bLowPrecision_3 )
    v45 = 0.125;
  else
    v45 = 0.03125;
  return (float)((float)v34 * v45 + (double)value);
}

//------------------------------------------------------------------------------
// Address: 0x10274DF0
// Name: public: void CBitRead::ReadBitVec3Coord(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::ReadBitVec3Coord(CBitRead *this, Vector *fa)
{
  unsigned int m_nInBufWord; // eax
  bool v5; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v8; // eax
  const unsigned int *v9; // eax
  const unsigned int *v10; // ecx
  unsigned int v11; // eax
  int v12; // edi
  const unsigned int *v13; // eax
  const unsigned int *v14; // ecx
  int v15; // [esp+0h] [ebp-4h]
  int v16; // [esp+Ch] [ebp+8h]

  fa->x = 0.0;
  fa->y = 0.0;
  fa->z = 0.0;
  m_nInBufWord = this->m_nInBufWord;
  v5 = this->m_nBitsAvail-- == 1;
  v16 = m_nInBufWord & 1;
  if ( v5 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  v8 = this->m_nInBufWord;
  v5 = this->m_nBitsAvail-- == 1;
  v15 = v8 & 1;
  if ( v5 )
  {
    v9 = this->m_pDataIn;
    v10 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v9 + 1;
    }
    else if ( v9 <= v10 )
    {
      this->m_nInBufWord = *v9;
      this->m_pDataIn = v9 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v8 >> 1;
  }
  v11 = this->m_nInBufWord;
  v12 = v11 & 1;
  v5 = this->m_nBitsAvail-- == 1;
  if ( v5 )
  {
    v13 = this->m_pDataIn;
    v14 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v13 == v14 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v13 + 1;
    }
    else if ( v13 <= v14 )
    {
      this->m_nInBufWord = *v13;
      this->m_pDataIn = v13 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v11 >> 1;
  }
  if ( v16 != 0 )
    fa->x = CBitRead::ReadBitCoord(this);
  if ( v15 != 0 )
    fa->y = CBitRead::ReadBitCoord(this);
  if ( v12 != 0 )
    fa->z = CBitRead::ReadBitCoord(this);
}

//------------------------------------------------------------------------------
// Address: 0x10274F40
// Name: public: float CBitRead::ReadBitNormal(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitNormal(CBitRead *this)
{
  unsigned int m_nInBufWord; // ecx
  int v3; // edi
  bool v4; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  int m_nBitsAvail; // ecx
  unsigned int v8; // edx
  int v9; // esi
  int v10; // eax
  const unsigned int *v11; // ecx
  const unsigned int *v12; // edx
  unsigned int v13; // edx
  const unsigned int *v14; // esi
  unsigned int v15; // edi
  int v16; // edx
  const unsigned int *v17; // ecx
  unsigned int v18; // esi
  unsigned int v19; // ebx
  double result; // st7
  int value; // [esp+Ch] [ebp-4h]
  float valuea; // [esp+Ch] [ebp-4h]

  m_nInBufWord = this->m_nInBufWord;
  v3 = m_nInBufWord & 1;
  v4 = this->m_nBitsAvail-- == 1;
  value = v3;
  if ( v4 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  m_nBitsAvail = this->m_nBitsAvail;
  if ( m_nBitsAvail >= 11 )
  {
    v8 = this->m_nInBufWord;
    v9 = v8 & 0x7FF;
    this->m_nBitsAvail = m_nBitsAvail - 11;
    if ( m_nBitsAvail == 11 )
    {
      v11 = this->m_pDataIn;
      v12 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v11 == v12 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v11 + 1;
        v10 = v9;
      }
      else
      {
        if ( v11 <= v12 )
        {
          v13 = *v11;
          this->m_pDataIn = v11 + 1;
          this->m_nInBufWord = v13;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v10 = v9;
      }
    }
    else
    {
      this->m_nInBufWord = v8 >> 11;
      v10 = v8 & 0x7FF;
    }
    goto LABEL_27;
  }
  v14 = this->m_pBufferEnd;
  v15 = this->m_nInBufWord;
  v16 = 11 - m_nBitsAvail;
  v17 = this->m_pDataIn;
  if ( v17 == v14 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
LABEL_22:
    this->m_pDataIn = v17 + 1;
    goto LABEL_23;
  }
  if ( v17 <= v14 )
  {
    this->m_nInBufWord = *v17;
    goto LABEL_22;
  }
  this->m_bOverflow = true;
  this->m_nInBufWord = 0;
LABEL_23:
  if ( this->m_bOverflow )
  {
    v10 = 0;
  }
  else
  {
    v18 = this->m_nInBufWord;
    v19 = (v18 & CBitBuffer::s_nMaskTable[v16]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v16;
    this->m_nInBufWord = v18 >> v16;
    v10 = v19 | v15;
  }
  v3 = value;
LABEL_27:
  result = (double)(unsigned int)v10 * 0.0004885197850512946;
  if ( v3 != 0 )
  {
    valuea = result;
    return COERCE_FLOAT(LODWORD(valuea) ^ _mask__NegFloat_);
  }
  return result;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10273770
// Name: public: bool CBitRead::Seek(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBitRead::Seek(CBitRead *this, int nPosition)
{
  int m_nDataBits; // ecx
  signed int v4; // edi
  int v5; // ebx
  const unsigned int *v6; // ecx
  const unsigned int *v7; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int v9; // ecx
  int v10; // eax
  int m_nBitsAvail; // ecx
  const unsigned int *m_pData; // eax
  unsigned int v14; // edx
  int v15; // ecx
  bool bSucc; // [esp+Bh] [ebp-1h]

  m_nDataBits = nPosition;
  bSucc = true;
  if ( nPosition < 0 || nPosition > this->m_nDataBits )
  {
    m_nDataBits = this->m_nDataBits;
    this->m_bOverflow = true;
    bSucc = false;
  }
  v4 = this->m_nDataBytes & 3;
  if ( this->m_nDataBytes < 4 || v4 != 0 && m_nDataBits / 8 < v4 )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      v14 = *(unsigned __int8 *)m_pData;
      m_pData = (const unsigned int *)((char *)m_pData + 1);
      this->m_nInBufWord = v14;
      if ( v4 > 1 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 8;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
      if ( v4 > 2 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 16;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
    }
    this->m_pDataIn = m_pData;
    v15 = m_nDataBits & 0x1F;
    this->m_nInBufWord >>= v15;
    v10 = 8 * v4 - v15;
    goto LABEL_23;
  }
  v5 = m_nDataBits - 8 * v4;
  v6 = this->m_pData;
  v7 = (const unsigned int *)((char *)&v6[v5 / 32] + v4);
  this->m_pDataIn = v7;
  if ( v6 == nullptr )
    goto LABEL_10;
  m_pBufferEnd = this->m_pBufferEnd;
  this->m_nBitsAvail = 32;
  if ( v7 == m_pBufferEnd )
  {
    this->m_pDataIn = v7 + 1;
LABEL_10:
    this->m_nBitsAvail = 1;
LABEL_11:
    this->m_nInBufWord = 0;
    goto LABEL_12;
  }
  if ( v7 > m_pBufferEnd )
  {
    this->m_bOverflow = true;
    goto LABEL_11;
  }
  this->m_nInBufWord = *v7;
  this->m_pDataIn = v7 + 1;
LABEL_12:
  v9 = v5 & 0x1F;
  this->m_nInBufWord >>= v9;
  v10 = 32 - v9;
  m_nBitsAvail = this->m_nBitsAvail;
  if ( m_nBitsAvail < v10 )
  {
    this->m_nBitsAvail = m_nBitsAvail;
    return bSucc;
  }
LABEL_23:
  this->m_nBitsAvail = v10;
  return bSucc;
}

//------------------------------------------------------------------------------
// Address: 0x10273890
// Name: public: void CBitRead::StartReading(void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::StartReading(
        CBitRead *this,
        const unsigned int *pData,
        unsigned int nBytes,
        int iStartBit,
        int nBits)
{
  int v5; // esi

  v5 = nBits;
  this->m_pData = pData;
  this->m_pDataIn = pData;
  this->m_nDataBytes = nBytes;
  if ( nBits == -1 )
    v5 = 8 * nBytes;
  this->m_nDataBits = v5;
  this->m_bOverflow = false;
  this->m_pBufferEnd = (const unsigned int *)((char *)pData + nBytes);
  if ( pData != nullptr )
    CBitRead::Seek(this, nPosition: iStartBit);
}

//------------------------------------------------------------------------------
// Address: 0x102738D0
// Name: public: bool CBitRead::ReadString(char __near *,int,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadString(CBitRead *this, char *pStr, int maxLen, bool bLine, int *pOutNumChars)
{
  int v6; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v9; // ecx
  char v10; // si
  char v11; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v14; // edx
  const unsigned int *v15; // esi
  unsigned int v16; // edi
  int v17; // edx
  const unsigned int *v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // ebx
  int iChar; // [esp+Ch] [ebp-8h]
  bool bTooSmall; // [esp+13h] [ebp-1h]

  bTooSmall = false;
  v6 = 0;
LABEL_2:
  iChar = v6;
  while ( 1 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail < 8 )
      break;
    m_nInBufWord = this->m_nInBufWord;
    v9 = m_nBitsAvail - 8;
    v10 = m_nInBufWord;
    this->m_nBitsAvail = v9;
    if ( v9 != 0 )
    {
      this->m_nInBufWord = m_nInBufWord >> 8;
      v11 = m_nInBufWord;
    }
    else
    {
      m_pDataIn = this->m_pDataIn;
      m_pBufferEnd = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        this->m_pDataIn = m_pDataIn + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v11 = v10;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v14 = *m_pDataIn;
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nInBufWord = v14;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v11 = v10;
      }
    }
LABEL_20:
    if ( v11 == 0 || bLine && v11 == 10 )
      goto LABEL_27;
    if ( v6 < maxLen - 1 )
    {
      pStr[v6++] = v11;
      goto LABEL_2;
    }
    bTooSmall = true;
  }
  v15 = this->m_pBufferEnd;
  v16 = this->m_nInBufWord;
  v17 = 8 - m_nBitsAvail;
  v18 = this->m_pDataIn;
  if ( v18 == v15 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
  }
  else
  {
    if ( v18 > v15 )
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
      goto LABEL_18;
    }
    this->m_nInBufWord = *v18;
  }
  this->m_pDataIn = v18 + 1;
LABEL_18:
  if ( !this->m_bOverflow )
  {
    v19 = this->m_nInBufWord;
    v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v17;
    v11 = v20 | v16;
    v6 = iChar;
    this->m_nInBufWord = v19 >> v17;
    goto LABEL_20;
  }
  v6 = iChar;
LABEL_27:
  pStr[v6] = 0;
  if ( pOutNumChars != nullptr )
    *pOutNumChars = v6;
  return !this->m_bOverflow && !bTooSmall;
}

//------------------------------------------------------------------------------
// Address: 0x10273A20
// Name: public: char __near * CBitRead::ReadAndAllocateString(bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBitRead::ReadAndAllocateString(CBitRead *this, bool *pOverflow)
{
  bool v2; // al
  int v3; // ebx
  unsigned int v4; // esi
  char *result; // eax
  char *v6; // edi
  char str[2048]; // [esp+0h] [ebp-804h] BYREF
  int nChars; // [esp+800h] [ebp-4h] BYREF

  v2 = !CBitRead::ReadString(this, pStr: str, maxLen: 2048, bLine: false, pOutNumChars: &nChars);
  if ( pOverflow != nullptr )
    *pOverflow = v2;
  v3 = nChars;
  v4 = nChars + 1;
  result = (char *)MemAlloc_Alloc(nSize: nChars + 1);
  v6 = result;
  if ( v3 >= 0 )
  {
    memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)str, count: v4);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10273A90
// Name: public: __int64 CBitRead::ReadLongLong(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBitRead::ReadLongLong(CBitRead *this)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // esi
  const unsigned int *v4; // eax
  const unsigned int *v5; // ecx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v8; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v10; // esi
  unsigned int v11; // ebx
  int v12; // ecx
  int v13; // ecx
  const unsigned int *v14; // ecx
  const unsigned int *v15; // eax
  const unsigned int *v17; // edi
  int v18; // esi
  const unsigned int *v19; // ecx
  unsigned int v20; // edi
  int v21; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = this->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pBufferEnd = this->m_pBufferEnd;
    m_nInBufWord = this->m_nInBufWord;
    v8 = 32 - m_nBitsAvail;
    m_pDataIn = this->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
        goto LABEL_16;
      }
      this->m_nInBufWord = *m_pDataIn;
    }
    this->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( this->m_bOverflow )
    {
      v21 = 0;
    }
    else
    {
      v10 = this->m_nInBufWord;
      v11 = (v10 & CBitBuffer::s_nMaskTable[v8]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v8;
      v21 = v11 | m_nInBufWord;
      this->m_nInBufWord = v10 >> v8;
    }
    goto LABEL_19;
  }
  v3 = this->m_nInBufWord;
  this->m_nBitsAvail = m_nBitsAvail - 32;
  if ( m_nBitsAvail == 32 )
  {
    v4 = this->m_pDataIn;
    v5 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v4 == v5 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v4 + 1;
      v21 = v3;
    }
    else
    {
      if ( v4 <= v5 )
      {
        this->m_nInBufWord = *v4;
        this->m_pDataIn = v4 + 1;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
      v21 = v3;
    }
  }
  else
  {
    this->m_nInBufWord = 0;
    v21 = v3;
  }
LABEL_19:
  v12 = this->m_nBitsAvail;
  if ( v12 < 32 )
  {
    v17 = this->m_pBufferEnd;
    v18 = 32 - v12;
    v19 = this->m_pDataIn;
    if ( v19 == v17 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v19 > v17 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_33:
        if ( !this->m_bOverflow )
        {
          v20 = this->m_nInBufWord;
          this->m_nBitsAvail = 32 - v18;
          this->m_nInBufWord = v20 >> v18;
        }
        return v21;
      }
      this->m_nInBufWord = *v19;
    }
    this->m_pDataIn = v19 + 1;
    goto LABEL_33;
  }
  v13 = v12 - 32;
  this->m_nBitsAvail = v13;
  if ( v13 != 0 )
  {
LABEL_25:
    this->m_nInBufWord = 0;
    return v21;
  }
  v14 = this->m_pDataIn;
  v15 = this->m_pBufferEnd;
  this->m_nBitsAvail = 32;
  if ( v14 == v15 )
  {
    this->m_nInBufWord = 0;
    this->m_nBitsAvail = 1;
    this->m_pDataIn = v14 + 1;
    return v21;
  }
  if ( v14 > v15 )
  {
    this->m_bOverflow = true;
    goto LABEL_25;
  }
  this->m_nInBufWord = *v14;
  this->m_pDataIn = v14 + 1;
  return v21;
}

//------------------------------------------------------------------------------
// Address: 0x10273C60
// Name: public: void CBitRead::ReadBits(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::ReadBits(CBitRead *this, char *pOutData, int nBits)
{
  int v4; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v7; // ecx
  char v8; // si
  char v9; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v12; // edx
  const unsigned int *v13; // esi
  unsigned int v14; // edi
  int v15; // edx
  const unsigned int *v16; // ecx
  unsigned int v17; // esi
  unsigned int v18; // ebx
  int v19; // ebx
  int v20; // ecx
  unsigned int v21; // esi
  int v22; // ecx
  unsigned int v23; // ecx
  const unsigned int *v24; // ecx
  const unsigned int *v25; // edx
  unsigned int v26; // edx
  const unsigned int *v27; // esi
  unsigned int v28; // edi
  int v29; // edx
  const unsigned int *v30; // ecx
  unsigned int v31; // esi
  unsigned int v32; // ebx
  int v33; // edi
  unsigned int *v34; // edx
  int v35; // ebx
  int v36; // ecx
  unsigned int v37; // edx
  int v38; // ecx
  char v39; // si
  char v40; // cl
  const unsigned int *v41; // ecx
  const unsigned int *v42; // edx
  unsigned int v43; // edx
  const unsigned int *v44; // esi
  unsigned int v45; // edi
  int v46; // edx
  const unsigned int *v47; // ecx
  unsigned int v48; // esi
  unsigned int v49; // ebx
  char v50; // di
  int v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // esi
  int v54; // ecx
  const unsigned int *v55; // ecx
  const unsigned int *v56; // edx
  _BYTE *v57; // edx
  const unsigned int *v58; // edx
  unsigned int v59; // edi
  int v60; // esi
  const unsigned int *v61; // ecx
  unsigned int v62; // edx
  unsigned int v63; // ebx
  int nBitsLeft; // [esp+18h] [ebp+8h]
  int nBitsa; // [esp+1Ch] [ebp+Ch]
  int nBitsb; // [esp+1Ch] [ebp+Ch]

  v4 = nBits;
  nBitsLeft = nBits;
  if ( ((unsigned __int8)pOutData & 3) != 0 )
  {
    while ( 1 )
    {
      if ( v4 < 8 )
        goto LABEL_23;
      m_nBitsAvail = this->m_nBitsAvail;
      if ( m_nBitsAvail < 8 )
        break;
      m_nInBufWord = this->m_nInBufWord;
      v7 = m_nBitsAvail - 8;
      v8 = m_nInBufWord;
      this->m_nBitsAvail = v7;
      if ( v7 != 0 )
      {
        this->m_nInBufWord = m_nInBufWord >> 8;
        v9 = m_nInBufWord;
      }
      else
      {
        m_pDataIn = this->m_pDataIn;
        m_pBufferEnd = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          v9 = v8;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            v12 = *m_pDataIn;
            this->m_pDataIn = m_pDataIn + 1;
            this->m_nInBufWord = v12;
          }
          else
          {
            this->m_bOverflow = true;
            this->m_nInBufWord = 0;
          }
          v9 = v8;
        }
      }
LABEL_22:
      *pOutData = v9;
      v4 -= 8;
      ++pOutData;
      nBitsLeft = v4;
      if ( ((unsigned __int8)pOutData & 3) == 0 )
        goto LABEL_23;
    }
    v13 = this->m_pBufferEnd;
    v14 = this->m_nInBufWord;
    v15 = 8 - m_nBitsAvail;
    v16 = this->m_pDataIn;
    if ( v16 == v13 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v16 > v13 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_18:
        if ( this->m_bOverflow )
        {
          v9 = 0;
        }
        else
        {
          v17 = this->m_nInBufWord;
          v18 = (v17 & CBitBuffer::s_nMaskTable[v15]) << this->m_nBitsAvail;
          this->m_nBitsAvail = 32 - v15;
          v9 = v18 | v14;
          this->m_nInBufWord = v17 >> v15;
        }
        v4 = nBitsLeft;
        goto LABEL_22;
      }
      this->m_nInBufWord = *v16;
    }
    this->m_pDataIn = v16 + 1;
    goto LABEL_18;
  }
LABEL_23:
  if ( v4 < 32 )
    goto LABEL_45;
  v19 = (unsigned int)v4 >> 5;
  nBitsa = (unsigned int)v4 >> 5;
  nBitsLeft = -32 * ((unsigned int)v4 >> 5) + v4;
  do
  {
    v20 = this->m_nBitsAvail;
    if ( v20 < 32 )
    {
      v27 = this->m_pBufferEnd;
      v28 = this->m_nInBufWord;
      v29 = 32 - v20;
      v30 = this->m_pDataIn;
      if ( v30 == v27 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v30 > v27 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_40;
        }
        this->m_nInBufWord = *v30;
      }
      this->m_pDataIn = v30 + 1;
LABEL_40:
      if ( this->m_bOverflow )
      {
        v23 = 0;
      }
      else
      {
        v31 = this->m_nInBufWord;
        v32 = (v31 & CBitBuffer::s_nMaskTable[v29]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v29;
        v33 = v32 | v28;
        v19 = nBitsa;
        v23 = v33;
        this->m_nInBufWord = v31 >> v29;
      }
      goto LABEL_43;
    }
    v21 = this->m_nInBufWord;
    v22 = v20 - 32;
    this->m_nBitsAvail = v22;
    if ( v22 != 0 )
    {
      this->m_nInBufWord = 0;
      v23 = v21;
    }
    else
    {
      v24 = this->m_pDataIn;
      v25 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v24 == v25 )
      {
        this->m_pDataIn = v24 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v23 = v21;
      }
      else
      {
        if ( v24 <= v25 )
        {
          v26 = *v24;
          this->m_pDataIn = v24 + 1;
          this->m_nInBufWord = v26;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v23 = v21;
      }
    }
LABEL_43:
    v34 = (unsigned int *)pOutData;
    pOutData += 4;
    --v19;
    *v34 = v23;
    nBitsa = v19;
  }
  while ( v19 != 0 );
  v4 = nBitsLeft;
LABEL_45:
  if ( v4 < 8 )
    goto LABEL_67;
  v35 = (unsigned int)v4 >> 3;
  nBitsb = (unsigned int)v4 >> 3;
  nBitsLeft = v4 - 8 * ((unsigned int)v4 >> 3);
  while ( 2 )
  {
    v36 = this->m_nBitsAvail;
    if ( v36 < 8 )
    {
      v44 = this->m_pBufferEnd;
      v45 = this->m_nInBufWord;
      v46 = 8 - v36;
      v47 = this->m_pDataIn;
      if ( v47 == v44 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v47 > v44 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_62;
        }
        this->m_nInBufWord = *v47;
      }
      this->m_pDataIn = v47 + 1;
LABEL_62:
      if ( this->m_bOverflow )
      {
        v40 = 0;
      }
      else
      {
        v48 = this->m_nInBufWord;
        v49 = (v48 & CBitBuffer::s_nMaskTable[v46]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v46;
        v50 = v49 | v45;
        v35 = nBitsb;
        v40 = v50;
        this->m_nInBufWord = v48 >> v46;
      }
      goto LABEL_65;
    }
    v37 = this->m_nInBufWord;
    v38 = v36 - 8;
    v39 = v37;
    this->m_nBitsAvail = v38;
    if ( v38 != 0 )
    {
      this->m_nInBufWord = v37 >> 8;
      v40 = v37;
    }
    else
    {
      v41 = this->m_pDataIn;
      v42 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v41 == v42 )
      {
        this->m_pDataIn = v41 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v40 = v39;
      }
      else
      {
        if ( v41 <= v42 )
        {
          v43 = *v41;
          this->m_pDataIn = v41 + 1;
          this->m_nInBufWord = v43;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v40 = v39;
      }
    }
LABEL_65:
    *pOutData = v40;
    --v35;
    ++pOutData;
    nBitsb = v35;
    if ( v35 != 0 )
      continue;
    break;
  }
  v4 = nBitsLeft;
LABEL_67:
  if ( v4 != 0 )
  {
    v51 = this->m_nBitsAvail;
    if ( v51 >= v4 )
    {
      v52 = this->m_nInBufWord;
      v53 = v52 & CBitBuffer::s_nMaskTable[v4];
      v54 = v51 - v4;
      this->m_nBitsAvail = v54;
      if ( v54 != 0 )
      {
        this->m_nInBufWord = v52 >> v4;
        *pOutData = v53;
      }
      else
      {
        v55 = this->m_pDataIn;
        v56 = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( v55 == v56 )
        {
          this->m_nInBufWord = 0;
          this->m_nBitsAvail = 1;
          this->m_pDataIn = v55 + 1;
          *pOutData = v53;
        }
        else
        {
          if ( v55 <= v56 )
          {
            this->m_nInBufWord = *v55;
            v57 = pOutData;
            this->m_pDataIn = v55 + 1;
          }
          else
          {
            v57 = pOutData;
            this->m_nInBufWord = 0;
            this->m_bOverflow = true;
          }
          *v57 = v53;
        }
      }
      return;
    }
    v58 = this->m_pBufferEnd;
    v59 = this->m_nInBufWord;
    v60 = nBitsLeft - v51;
    v61 = this->m_pDataIn;
    if ( v61 == v58 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
      goto LABEL_82;
    }
    if ( v61 <= v58 )
    {
      this->m_nInBufWord = *v61;
LABEL_82:
      this->m_pDataIn = v61 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
    if ( this->m_bOverflow )
    {
      *pOutData = 0;
    }
    else
    {
      v62 = this->m_nInBufWord;
      v63 = (v62 & CBitBuffer::s_nMaskTable[v60]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v60;
      this->m_nInBufWord = v62 >> v60;
      *pOutData = v63 | v59;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102740D0
// Name: public: bool CBitRead::ReadBytes(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadBytes(CBitRead *this, char *pOut, int nBytes)
{
  CBitRead::ReadBits(this, pOutData: pOut, nBits: 8 * nBytes);
  return !this->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x10274100
// Name: public: float CBitRead::ReadBitAngle(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitAngle(CBitRead *this, int numbits)
{
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // edx
  signed int v5; // edi
  int v6; // esi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  double v10; // st7
  unsigned int v11; // edx
  const unsigned int *v12; // edx
  unsigned int v13; // edi
  int v14; // esi
  const unsigned int *v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // ebx
  float shift; // [esp+4h] [ebp-4h]
  int numbitsa; // [esp+10h] [ebp+8h]
  int numbitsb; // [esp+10h] [ebp+8h]

  m_nBitsAvail = this->m_nBitsAvail;
  shift = (float)`GetBitForBitnum'::`2'::bitsForBitnum[numbits & 0x1F];
  if ( m_nBitsAvail >= numbits )
  {
    m_nInBufWord = this->m_nInBufWord;
    v5 = m_nInBufWord & CBitBuffer::s_nMaskTable[numbits];
    v6 = m_nBitsAvail - numbits;
    this->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      this->m_nInBufWord = m_nInBufWord >> numbits;
      return 360.0 / shift * (double)v5;
    }
    else
    {
      m_pDataIn = this->m_pDataIn;
      m_pBufferEnd = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = m_pDataIn + 1;
        return 360.0 / shift * (double)v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v11 = *m_pDataIn;
          v10 = 360.0 / shift;
          numbitsa = v5;
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nInBufWord = v11;
        }
        else
        {
          numbitsa = v5;
          v10 = 360.0 / shift;
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        return v10 * (double)numbitsa;
      }
    }
  }
  v12 = this->m_pBufferEnd;
  v13 = this->m_nInBufWord;
  v14 = numbits - m_nBitsAvail;
  v15 = this->m_pDataIn;
  if ( v15 == v12 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
LABEL_15:
    this->m_pDataIn = v15 + 1;
    goto LABEL_16;
  }
  if ( v15 <= v12 )
  {
    this->m_nInBufWord = *v15;
    goto LABEL_15;
  }
  this->m_bOverflow = true;
  this->m_nInBufWord = 0;
LABEL_16:
  if ( this->m_bOverflow )
  {
    numbitsb = 0;
  }
  else
  {
    v16 = this->m_nInBufWord;
    v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v14;
    numbitsb = v17 | v13;
    this->m_nInBufWord = v16 >> v14;
  }
  return 360.0 / shift * (double)numbitsb;
}

//------------------------------------------------------------------------------
// Address: 0x10274260
// Name: public: float CBitRead::ReadBitCoord(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitCoord(CBitRead *this)
{
  unsigned int m_nInBufWord; // ecx
  int v3; // esi
  bool v4; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v7; // ecx
  int v8; // ebx
  const unsigned int *v9; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // ecx
  const unsigned int *v12; // ecx
  const unsigned int *v13; // edx
  int m_nBitsAvail; // ecx
  unsigned int v15; // edx
  int v16; // ecx
  unsigned int v17; // esi
  int v18; // edi
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edx
  unsigned int v21; // edx
  const unsigned int *v22; // esi
  unsigned int v23; // edi
  int v24; // edx
  const unsigned int *v25; // ecx
  unsigned int v26; // esi
  unsigned int v27; // ebx
  int v28; // ecx
  unsigned int v29; // edx
  int v30; // ecx
  int v31; // edi
  const unsigned int *v32; // ecx
  const unsigned int *v33; // edx
  unsigned int v34; // edx
  const unsigned int *v35; // esi
  unsigned int v36; // edi
  int v37; // edx
  const unsigned int *v38; // ecx
  unsigned int v39; // esi
  unsigned int v40; // ebx
  float v41; // xmm0_4
  int v43; // [esp+0h] [ebp-14h]
  int fractval; // [esp+4h] [ebp-10h]
  int v45; // [esp+8h] [ebp-Ch]
  int intval; // [esp+Ch] [ebp-8h]
  float value; // [esp+10h] [ebp-4h]

  m_nInBufWord = this->m_nInBufWord;
  v3 = m_nInBufWord & 1;
  v4 = this->m_nBitsAvail-- == 1;
  value = 0.0;
  if ( v4 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  v7 = this->m_nInBufWord;
  v8 = v7 & 1;
  v4 = this->m_nBitsAvail-- == 1;
  intval = v3;
  v45 = v8;
  if ( v4 )
  {
    v9 = this->m_pDataIn;
    v10 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v9 + 1;
    }
    else if ( v9 <= v10 )
    {
      this->m_nInBufWord = *v9;
      this->m_pDataIn = v9 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v7 >> 1;
  }
  fractval = v8;
  if ( v3 == 0 && v8 == 0 )
    return value;
  v11 = this->m_nInBufWord;
  v4 = this->m_nBitsAvail-- == 1;
  v43 = v11 & 1;
  if ( v4 )
  {
    v12 = this->m_pDataIn;
    v13 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v12 == v13 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v12 + 1;
    }
    else if ( v12 <= v13 )
    {
      this->m_nInBufWord = *v12;
      this->m_pDataIn = v12 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v11 >> 1;
  }
  if ( v3 != 0 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail >= 14 )
    {
      v15 = this->m_nInBufWord;
      v16 = m_nBitsAvail - 14;
      v17 = 0;
      v18 = v15 & 0x3FFF;
      this->m_nBitsAvail = v16;
      if ( v16 != 0 )
      {
        this->m_nInBufWord = v15 >> 14;
LABEL_43:
        intval = v18 + 1;
        goto LABEL_44;
      }
      v19 = this->m_pDataIn;
      v20 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v19 == v20 )
      {
        this->m_nBitsAvail = 1;
        this->m_pDataIn = v19 + 1;
      }
      else
      {
        if ( v19 <= v20 )
        {
          v21 = *v19;
          this->m_pDataIn = v19 + 1;
          this->m_nInBufWord = v21;
          goto LABEL_43;
        }
        this->m_bOverflow = true;
      }
LABEL_42:
      this->m_nInBufWord = v17;
      goto LABEL_43;
    }
    v22 = this->m_pBufferEnd;
    v23 = this->m_nInBufWord;
    v24 = 14 - m_nBitsAvail;
    v25 = this->m_pDataIn;
    if ( v25 == v22 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v22 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_39:
        if ( this->m_bOverflow )
        {
          v18 = 0;
          goto LABEL_43;
        }
        v26 = this->m_nInBufWord;
        v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v24;
        v18 = v27 | v23;
        v8 = v45;
        v17 = v26 >> v24;
        goto LABEL_42;
      }
      this->m_nInBufWord = *v25;
    }
    this->m_pDataIn = v25 + 1;
    goto LABEL_39;
  }
LABEL_44:
  if ( v8 == 0 )
  {
    v31 = fractval;
    goto LABEL_63;
  }
  v28 = this->m_nBitsAvail;
  if ( v28 >= 5 )
  {
    v29 = this->m_nInBufWord;
    v30 = v28 - 5;
    v31 = v29 & 0x1F;
    this->m_nBitsAvail = v30;
    if ( v30 != 0 )
    {
      this->m_nInBufWord = v29 >> 5;
    }
    else
    {
      v32 = this->m_pDataIn;
      v33 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v32 == v33 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v32 + 1;
      }
      else if ( v32 <= v33 )
      {
        v34 = *v32;
        this->m_pDataIn = v32 + 1;
        this->m_nInBufWord = v34;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
    }
    goto LABEL_63;
  }
  v35 = this->m_pBufferEnd;
  v36 = this->m_nInBufWord;
  v37 = 5 - v28;
  v38 = this->m_pDataIn;
  if ( v38 == v35 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
  }
  else
  {
    if ( v38 > v35 )
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
      goto LABEL_59;
    }
    this->m_nInBufWord = *v38;
  }
  this->m_pDataIn = v38 + 1;
LABEL_59:
  if ( this->m_bOverflow )
  {
    v31 = 0;
  }
  else
  {
    v39 = this->m_nInBufWord;
    v40 = (v39 & CBitBuffer::s_nMaskTable[v37]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v37;
    v31 = v40 | v36;
    this->m_nInBufWord = v39 >> v37;
  }
LABEL_63:
  v41 = (float)((float)v31 * 0.03125) + (double)intval;
  value = v41;
  if ( v43 != 0 )
    LODWORD(value) = LODWORD(v41) ^ _mask__NegFloat_;
  return value;
}

//------------------------------------------------------------------------------
// Address: 0x102745A0
// Name: public: float CBitRead::ReadBitCoordMP(enum EBitCoordType)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitCoordMP(CBitRead *this, EBitCoordType coordType)
{
  bool v3; // bl
  unsigned int m_nInBufWord; // ecx
  int v5; // edx
  bool v6; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int v9; // ecx
  unsigned int v10; // esi
  const unsigned int *v11; // ecx
  const unsigned int *v12; // edx
  unsigned int v13; // ecx
  int v14; // edx
  const unsigned int *v15; // ecx
  const unsigned int *v16; // esi
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // ecx
  int v20; // esi
  int v21; // edi
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edx
  const unsigned int *v25; // esi
  unsigned int v26; // edi
  int v27; // edx
  const unsigned int *v28; // ecx
  unsigned int v29; // esi
  unsigned int v30; // ebx
  double v31; // st7
  float v32; // xmm0_4
  unsigned int v33; // edx
  int v34; // ecx
  int v35; // esi
  int v36; // edi
  const unsigned int *v37; // ecx
  const unsigned int *v38; // edx
  unsigned int v39; // edx
  const unsigned int *v40; // esi
  unsigned int v41; // edi
  int v42; // edx
  const unsigned int *v43; // ecx
  unsigned int v44; // esi
  unsigned int v45; // ebx
  unsigned int v46; // edi
  const unsigned int *v47; // ecx
  const unsigned int *v48; // edx
  unsigned int v49; // ecx
  int v50; // edx
  const unsigned int *v51; // ecx
  const unsigned int *v52; // esi
  int v53; // ecx
  unsigned int v54; // edx
  int v55; // ecx
  int v56; // edi
  const unsigned int *v57; // ecx
  const unsigned int *v58; // edx
  int v59; // edx
  unsigned int v60; // edx
  int v61; // ecx
  unsigned int v62; // edx
  const unsigned int *v63; // esi
  unsigned int v64; // edi
  int v65; // edx
  const unsigned int *v66; // ecx
  unsigned int v67; // esi
  unsigned int v68; // ebx
  int m_nBitsAvail; // ecx
  int v70; // edx
  unsigned int v71; // esi
  signed int v72; // edi
  int v73; // ecx
  const unsigned int *v74; // ecx
  const unsigned int *v75; // edx
  const unsigned int *v76; // esi
  unsigned int v77; // edi
  const unsigned int *v78; // ecx
  double v79; // xmm0_8
  int signbit; // [esp+0h] [ebp-10h]
  int intval; // [esp+4h] [ebp-Ch]
  float value; // [esp+8h] [ebp-8h]
  bool bLowPrecision; // [esp+Fh] [ebp-1h]
  bool bInBounds_3; // [esp+1Bh] [ebp+Bh]

  v3 = coordType == kCW_Integral;
  m_nInBufWord = this->m_nInBufWord;
  bLowPrecision = coordType == kCW_LowPrecision;
  v5 = m_nInBufWord & 1;
  v6 = this->m_nBitsAvail-- == 1;
  value = 0.0;
  if ( v6 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  v9 = this->m_nInBufWord;
  bInBounds_3 = v5 != 0;
  if ( !v3 )
  {
    v46 = this->m_nInBufWord & 1;
    v6 = this->m_nBitsAvail-- == 1;
    if ( v6 )
    {
      v47 = this->m_pDataIn;
      v48 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v47 == v48 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v47 + 1;
      }
      else if ( v47 <= v48 )
      {
        this->m_nInBufWord = *v47;
        this->m_pDataIn = v47 + 1;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
    }
    else
    {
      this->m_nInBufWord = v9 >> 1;
    }
    v49 = this->m_nInBufWord;
    v50 = v49 & 1;
    v6 = this->m_nBitsAvail-- == 1;
    intval = v46;
    if ( v6 )
    {
      v51 = this->m_pDataIn;
      v52 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v51 == v52 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v51 + 1;
      }
      else if ( v51 <= v52 )
      {
        this->m_nInBufWord = *v51;
        this->m_pDataIn = v51 + 1;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
    }
    else
    {
      this->m_nInBufWord = v49 >> 1;
    }
    signbit = v50;
    if ( v46 == 0 )
    {
LABEL_104:
      m_nBitsAvail = this->m_nBitsAvail;
      v70 = 2 * !bLowPrecision + 3;
      if ( m_nBitsAvail >= v70 )
      {
        v71 = this->m_nInBufWord;
        v72 = v71 & CBitBuffer::s_nMaskTable[v70];
        v73 = m_nBitsAvail - v70;
        this->m_nBitsAvail = v73;
        if ( v73 == 0 )
        {
          v74 = this->m_pDataIn;
          v75 = this->m_pBufferEnd;
          this->m_nBitsAvail = 32;
          if ( v74 == v75 )
          {
            this->m_nBitsAvail = 1;
            this->m_nInBufWord = 0;
            this->m_pDataIn = v74 + 1;
          }
          else if ( v74 <= v75 )
          {
            this->m_nInBufWord = *v74;
            this->m_pDataIn = v74 + 1;
          }
          else
          {
            this->m_bOverflow = true;
            this->m_nInBufWord = 0;
          }
LABEL_121:
          if ( bLowPrecision )
            v79 = 0.125;
          else
            v79 = 0.03125;
          v32 = (float)v72 * v79 + (double)intval;
          value = v32;
          goto LABEL_125;
        }
        goto LABEL_120;
      }
      v76 = this->m_pBufferEnd;
      v77 = this->m_nInBufWord;
      v70 -= m_nBitsAvail;
      v78 = this->m_pDataIn;
      if ( v78 == v76 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v78 > v76 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
LABEL_117:
          if ( this->m_bOverflow )
          {
            v72 = 0;
            goto LABEL_121;
          }
          v71 = this->m_nInBufWord;
          v72 = ((v71 & CBitBuffer::s_nMaskTable[v70]) << this->m_nBitsAvail) | v77;
          this->m_nBitsAvail = 32 - v70;
LABEL_120:
          this->m_nInBufWord = v71 >> v70;
          goto LABEL_121;
        }
        this->m_nInBufWord = *v78;
      }
      this->m_pDataIn = v78 + 1;
      goto LABEL_117;
    }
    v53 = this->m_nBitsAvail;
    if ( bInBounds_3 )
    {
      if ( v53 >= 11 )
      {
        v54 = this->m_nInBufWord;
        v55 = v53 - 11;
        v56 = v54 & 0x7FF;
        this->m_nBitsAvail = v55;
        if ( v55 != 0 )
        {
          this->m_nInBufWord = v54 >> 11;
LABEL_103:
          intval = v56 + 1;
          goto LABEL_104;
        }
        goto LABEL_84;
      }
      v59 = 11;
    }
    else
    {
      if ( v53 >= 14 )
      {
        v60 = this->m_nInBufWord;
        v61 = v53 - 14;
        v56 = v60 & 0x3FFF;
        this->m_nBitsAvail = v61;
        if ( v61 != 0 )
        {
          this->m_nInBufWord = v60 >> 14;
          goto LABEL_103;
        }
LABEL_84:
        v57 = this->m_pDataIn;
        v58 = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( v57 == v58 )
        {
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          this->m_pDataIn = v57 + 1;
        }
        else if ( v57 <= v58 )
        {
          v62 = *v57;
          this->m_pDataIn = v57 + 1;
          this->m_nInBufWord = v62;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        goto LABEL_103;
      }
      v59 = 14;
    }
    v63 = this->m_pBufferEnd;
    v64 = this->m_nInBufWord;
    v65 = v59 - v53;
    v66 = this->m_pDataIn;
    if ( v66 == v63 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v66 > v63 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
        goto LABEL_100;
      }
      this->m_nInBufWord = *v66;
    }
    this->m_pDataIn = v66 + 1;
LABEL_100:
    if ( this->m_bOverflow )
    {
      v56 = 0;
    }
    else
    {
      v67 = this->m_nInBufWord;
      v68 = (v67 & CBitBuffer::s_nMaskTable[v65]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v65;
      v56 = v68 | v64;
      this->m_nInBufWord = v67 >> v65;
    }
    goto LABEL_103;
  }
  v10 = this->m_nInBufWord & 1;
  v6 = this->m_nBitsAvail-- == 1;
  if ( v6 )
  {
    v11 = this->m_pDataIn;
    v12 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v11 == v12 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v11 + 1;
    }
    else if ( v11 <= v12 )
    {
      this->m_nInBufWord = *v11;
      this->m_pDataIn = v11 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v9 >> 1;
  }
  if ( v10 != 0 )
  {
    v13 = this->m_nInBufWord;
    v14 = v13 & 1;
    v6 = this->m_nBitsAvail-- == 1;
    if ( v6 )
    {
      v15 = this->m_pDataIn;
      v16 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v15 == v16 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v15 + 1;
      }
      else if ( v15 <= v16 )
      {
        this->m_nInBufWord = *v15;
        this->m_pDataIn = v15 + 1;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
    }
    else
    {
      this->m_nInBufWord = v13 >> 1;
    }
    v17 = this->m_nBitsAvail;
    signbit = v14;
    if ( bInBounds_3 )
    {
      if ( v17 >= 11 )
      {
        v18 = this->m_nInBufWord;
        v19 = v17 - 11;
        v20 = v18 & 0x7FF;
        this->m_nBitsAvail = v19;
        if ( v19 != 0 )
        {
          this->m_nInBufWord = v18 >> 11;
          v21 = v18 & 0x7FF;
        }
        else
        {
          v22 = this->m_pDataIn;
          v23 = this->m_pBufferEnd;
          this->m_nBitsAvail = 32;
          if ( v22 == v23 )
          {
            this->m_nBitsAvail = 1;
            this->m_nInBufWord = 0;
            this->m_pDataIn = v22 + 1;
            v21 = v20;
          }
          else
          {
            if ( v22 <= v23 )
            {
              v24 = *v22;
              this->m_pDataIn = v22 + 1;
              this->m_nInBufWord = v24;
            }
            else
            {
              this->m_bOverflow = true;
              this->m_nInBufWord = 0;
            }
            v21 = v20;
          }
        }
LABEL_43:
        v31 = (double)(v21 + 1);
        if ( v21 + 1 < 0 )
        {
          value = v31 + 4294967300.0;
          v32 = value;
          goto LABEL_125;
        }
LABEL_64:
        value = v31;
        v32 = value;
LABEL_125:
        if ( signbit != 0 )
          LODWORD(value) = LODWORD(v32) ^ _mask__NegFloat_;
        return value;
      }
      v25 = this->m_pBufferEnd;
      v26 = this->m_nInBufWord;
      v27 = 11 - v17;
      v28 = this->m_pDataIn;
      if ( v28 == v25 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v28 > v25 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_40;
        }
        this->m_nInBufWord = *v28;
      }
      this->m_pDataIn = v28 + 1;
LABEL_40:
      if ( this->m_bOverflow )
      {
        v21 = 0;
      }
      else
      {
        v29 = this->m_nInBufWord;
        v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v27;
        v21 = v30 | v26;
        this->m_nInBufWord = v29 >> v27;
      }
      goto LABEL_43;
    }
    if ( v17 >= 14 )
    {
      v33 = this->m_nInBufWord;
      v34 = v17 - 14;
      v35 = v33 & 0x3FFF;
      this->m_nBitsAvail = v34;
      if ( v34 != 0 )
      {
        this->m_nInBufWord = v33 >> 14;
        v36 = v33 & 0x3FFF;
      }
      else
      {
        v37 = this->m_pDataIn;
        v38 = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( v37 == v38 )
        {
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          this->m_pDataIn = v37 + 1;
          v36 = v35;
        }
        else
        {
          if ( v37 <= v38 )
          {
            v39 = *v37;
            this->m_pDataIn = v37 + 1;
            this->m_nInBufWord = v39;
          }
          else
          {
            this->m_bOverflow = true;
            this->m_nInBufWord = 0;
          }
          v36 = v35;
        }
      }
      goto LABEL_63;
    }
    v40 = this->m_pBufferEnd;
    v41 = this->m_nInBufWord;
    v42 = 14 - v17;
    v43 = this->m_pDataIn;
    if ( v43 == v40 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v43 > v40 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
        goto LABEL_60;
      }
      this->m_nInBufWord = *v43;
    }
    this->m_pDataIn = v43 + 1;
LABEL_60:
    if ( this->m_bOverflow )
    {
      v36 = 0;
    }
    else
    {
      v44 = this->m_nInBufWord;
      v45 = (v44 & CBitBuffer::s_nMaskTable[v42]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v42;
      v36 = v45 | v41;
      this->m_nInBufWord = v44 >> v42;
    }
LABEL_63:
    v31 = (double)(unsigned int)(v36 + 1);
    goto LABEL_64;
  }
  return value;
}

//------------------------------------------------------------------------------
// Address: 0x10274BB0
// Name: public: float CBitRead::ReadBitCellCoord(int,enum EBitCoordType)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitCellCoord(CBitRead *this, int bits, EBitCoordType coordType)
{
  int m_nBitsAvail; // esi
  bool v6; // zf
  char v7; // cl
  unsigned int m_nInBufWord; // edx
  unsigned int v9; // edi
  int v10; // esi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v13; // edx
  const unsigned int *v14; // edx
  unsigned int v15; // edi
  int v16; // esi
  const unsigned int *v17; // ecx
  unsigned int v19; // edx
  unsigned int v20; // edi
  int v21; // esi
  unsigned int v22; // edx
  const unsigned int *v23; // ecx
  const unsigned int *v24; // edx
  const unsigned int *v25; // edx
  unsigned int v26; // edi
  int v27; // esi
  const unsigned int *v28; // ecx
  unsigned int v29; // edx
  unsigned int v30; // ebx
  int v31; // ecx
  int v32; // edx
  unsigned int v33; // esi
  int v34; // edi
  int v35; // ecx
  unsigned int v36; // esi
  const unsigned int *v37; // ecx
  const unsigned int *v38; // edx
  const unsigned int *v39; // esi
  unsigned int v40; // edi
  int v41; // edx
  const unsigned int *v42; // ecx
  unsigned int v43; // esi
  unsigned int v44; // ebx
  double v45; // xmm0_8
  int value; // [esp+14h] [ebp+8h]
  bool bLowPrecision_3; // [esp+1Bh] [ebp+Fh]

  m_nBitsAvail = this->m_nBitsAvail;
  bLowPrecision_3 = coordType == kCW_LowPrecision;
  v6 = coordType == kCW_Integral;
  v7 = bits;
  if ( v6 )
  {
    if ( m_nBitsAvail >= bits )
    {
      m_nInBufWord = this->m_nInBufWord;
      v9 = m_nInBufWord & CBitBuffer::s_nMaskTable[bits];
      v10 = m_nBitsAvail - bits;
      this->m_nBitsAvail = v10;
      if ( v10 == 0 )
      {
        m_pDataIn = this->m_pDataIn;
        m_pBufferEnd = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          this->m_pDataIn = m_pDataIn + 1;
          return (double)v9;
        }
        if ( m_pDataIn > m_pBufferEnd )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          return (double)v9;
        }
        v13 = *m_pDataIn;
        this->m_pDataIn = m_pDataIn + 1;
LABEL_19:
        this->m_nInBufWord = v13;
        return (double)v9;
      }
LABEL_18:
      v13 = m_nInBufWord >> v7;
      goto LABEL_19;
    }
    v14 = this->m_pBufferEnd;
    v15 = this->m_nInBufWord;
    v16 = bits - m_nBitsAvail;
    v17 = this->m_pDataIn;
    if ( v17 == v14 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v17 > v14 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_15:
        if ( this->m_bOverflow )
          return (double)0;
        m_nInBufWord = this->m_nInBufWord;
        v9 = ((m_nInBufWord & CBitBuffer::s_nMaskTable[v16]) << this->m_nBitsAvail) | v15;
        this->m_nBitsAvail = 32 - v16;
        v7 = v16;
        goto LABEL_18;
      }
      this->m_nInBufWord = *v17;
    }
    this->m_pDataIn = v17 + 1;
    goto LABEL_15;
  }
  if ( m_nBitsAvail < bits )
  {
    v25 = this->m_pBufferEnd;
    v26 = this->m_nInBufWord;
    v27 = bits - m_nBitsAvail;
    v28 = this->m_pDataIn;
    if ( v28 == v25 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_35:
        if ( this->m_bOverflow )
        {
          value = 0;
          goto LABEL_40;
        }
        v29 = this->m_nInBufWord;
        v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v27;
        v20 = v30 | v26;
        v22 = v29 >> v27;
        goto LABEL_38;
      }
      this->m_nInBufWord = *v28;
    }
    this->m_pDataIn = v28 + 1;
    goto LABEL_35;
  }
  v19 = this->m_nInBufWord;
  v20 = v19 & CBitBuffer::s_nMaskTable[bits];
  v21 = m_nBitsAvail - bits;
  this->m_nBitsAvail = v21;
  if ( v21 != 0 )
  {
    v22 = v19 >> bits;
LABEL_38:
    this->m_nInBufWord = v22;
    goto LABEL_39;
  }
  v23 = this->m_pDataIn;
  v24 = this->m_pBufferEnd;
  this->m_nBitsAvail = 32;
  if ( v23 == v24 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_pDataIn = v23 + 1;
  }
  else
  {
    if ( v23 <= v24 )
    {
      v22 = *v23;
      this->m_pDataIn = v23 + 1;
      goto LABEL_38;
    }
    this->m_bOverflow = true;
    this->m_nInBufWord = 0;
  }
LABEL_39:
  value = v20;
LABEL_40:
  v31 = this->m_nBitsAvail;
  v32 = 2 * !bLowPrecision_3 + 3;
  if ( v31 >= v32 )
  {
    v33 = this->m_nInBufWord;
    v34 = v33 & CBitBuffer::s_nMaskTable[v32];
    v35 = v31 - v32;
    this->m_nBitsAvail = v35;
    if ( v35 != 0 )
    {
      v36 = v33 >> v32;
LABEL_57:
      this->m_nInBufWord = v36;
      goto LABEL_58;
    }
    v37 = this->m_pDataIn;
    v38 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v37 == v38 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v37 + 1;
    }
    else if ( v37 <= v38 )
    {
      this->m_nInBufWord = *v37;
      this->m_pDataIn = v37 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
    goto LABEL_58;
  }
  v39 = this->m_pBufferEnd;
  v40 = this->m_nInBufWord;
  v41 = v32 - v31;
  v42 = this->m_pDataIn;
  if ( v42 == v39 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
LABEL_53:
    this->m_pDataIn = v42 + 1;
    goto LABEL_54;
  }
  if ( v42 <= v39 )
  {
    this->m_nInBufWord = *v42;
    goto LABEL_53;
  }
  this->m_bOverflow = true;
  this->m_nInBufWord = 0;
LABEL_54:
  if ( !this->m_bOverflow )
  {
    v43 = this->m_nInBufWord;
    v44 = (v43 & CBitBuffer::s_nMaskTable[v41]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v41;
    v34 = v44 | v40;
    v36 = v43 >> v41;
    goto LABEL_57;
  }
  v34 = 0;
LABEL_58:
  if ( bLowPrecision_3 )
    v45 = 0.125;
  else
    v45 = 0.03125;
  return (float)((float)v34 * v45 + (double)value);
}

//------------------------------------------------------------------------------
// Address: 0x10274E90
// Name: public: void CBitRead::ReadBitVec3Coord(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::ReadBitVec3Coord(CBitRead *this, Vector *fa)
{
  unsigned int m_nInBufWord; // eax
  bool v5; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v8; // eax
  const unsigned int *v9; // eax
  const unsigned int *v10; // ecx
  unsigned int v11; // eax
  int v12; // edi
  const unsigned int *v13; // eax
  const unsigned int *v14; // ecx
  int v15; // [esp+0h] [ebp-4h]
  int v16; // [esp+Ch] [ebp+8h]

  fa->x = 0.0;
  fa->y = 0.0;
  fa->z = 0.0;
  m_nInBufWord = this->m_nInBufWord;
  v5 = this->m_nBitsAvail-- == 1;
  v16 = m_nInBufWord & 1;
  if ( v5 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  v8 = this->m_nInBufWord;
  v5 = this->m_nBitsAvail-- == 1;
  v15 = v8 & 1;
  if ( v5 )
  {
    v9 = this->m_pDataIn;
    v10 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v9 + 1;
    }
    else if ( v9 <= v10 )
    {
      this->m_nInBufWord = *v9;
      this->m_pDataIn = v9 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v8 >> 1;
  }
  v11 = this->m_nInBufWord;
  v12 = v11 & 1;
  v5 = this->m_nBitsAvail-- == 1;
  if ( v5 )
  {
    v13 = this->m_pDataIn;
    v14 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v13 == v14 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v13 + 1;
    }
    else if ( v13 <= v14 )
    {
      this->m_nInBufWord = *v13;
      this->m_pDataIn = v13 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v11 >> 1;
  }
  if ( v16 != 0 )
    fa->x = CBitRead::ReadBitCoord(this);
  if ( v15 != 0 )
    fa->y = CBitRead::ReadBitCoord(this);
  if ( v12 != 0 )
    fa->z = CBitRead::ReadBitCoord(this);
}

//------------------------------------------------------------------------------
// Address: 0x10274FE0
// Name: public: float CBitRead::ReadBitNormal(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitNormal(CBitRead *this)
{
  unsigned int m_nInBufWord; // ecx
  int v3; // edi
  bool v4; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  int m_nBitsAvail; // ecx
  unsigned int v8; // edx
  int v9; // esi
  int v10; // eax
  const unsigned int *v11; // ecx
  const unsigned int *v12; // edx
  unsigned int v13; // edx
  const unsigned int *v14; // esi
  unsigned int v15; // edi
  int v16; // edx
  const unsigned int *v17; // ecx
  unsigned int v18; // esi
  unsigned int v19; // ebx
  double result; // st7
  int value; // [esp+Ch] [ebp-4h]
  float valuea; // [esp+Ch] [ebp-4h]

  m_nInBufWord = this->m_nInBufWord;
  v3 = m_nInBufWord & 1;
  v4 = this->m_nBitsAvail-- == 1;
  value = v3;
  if ( v4 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  m_nBitsAvail = this->m_nBitsAvail;
  if ( m_nBitsAvail >= 11 )
  {
    v8 = this->m_nInBufWord;
    v9 = v8 & 0x7FF;
    this->m_nBitsAvail = m_nBitsAvail - 11;
    if ( m_nBitsAvail == 11 )
    {
      v11 = this->m_pDataIn;
      v12 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v11 == v12 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v11 + 1;
        v10 = v9;
      }
      else
      {
        if ( v11 <= v12 )
        {
          v13 = *v11;
          this->m_pDataIn = v11 + 1;
          this->m_nInBufWord = v13;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v10 = v9;
      }
    }
    else
    {
      this->m_nInBufWord = v8 >> 11;
      v10 = v8 & 0x7FF;
    }
    goto LABEL_27;
  }
  v14 = this->m_pBufferEnd;
  v15 = this->m_nInBufWord;
  v16 = 11 - m_nBitsAvail;
  v17 = this->m_pDataIn;
  if ( v17 == v14 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
LABEL_22:
    this->m_pDataIn = v17 + 1;
    goto LABEL_23;
  }
  if ( v17 <= v14 )
  {
    this->m_nInBufWord = *v17;
    goto LABEL_22;
  }
  this->m_bOverflow = true;
  this->m_nInBufWord = 0;
LABEL_23:
  if ( this->m_bOverflow )
  {
    v10 = 0;
  }
  else
  {
    v18 = this->m_nInBufWord;
    v19 = (v18 & CBitBuffer::s_nMaskTable[v16]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v16;
    this->m_nInBufWord = v18 >> v16;
    v10 = v19 | v15;
  }
  v3 = value;
LABEL_27:
  result = (double)(unsigned int)v10 * 0.0004885197850512946;
  if ( v3 != 0 )
  {
    valuea = result;
    return COERCE_FLOAT(LODWORD(valuea) ^ _mask__NegFloat_);
  }
  return result;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x1000AF20
// Name: public: void CBitRead::ReadBits(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::ReadBits(CBitRead *this, int pOutData, int nBits)
{
  int v4; // edi
  bool v5; // zf
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v8; // ecx
  char v9; // si
  char v10; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v13; // edx
  const unsigned int *v14; // esi
  unsigned int v15; // edi
  int v16; // edx
  const unsigned int *v17; // ecx
  unsigned int v18; // esi
  unsigned int v19; // ebp
  unsigned int v20; // ebp
  int v21; // ecx
  unsigned int v22; // esi
  int v23; // ecx
  int v24; // ecx
  const unsigned int *v25; // ecx
  const unsigned int *v26; // edx
  unsigned int v27; // edx
  const unsigned int *v28; // esi
  unsigned int v29; // edi
  int v30; // edx
  const unsigned int *v31; // ecx
  unsigned int v32; // esi
  unsigned int v33; // ebx
  int *v34; // edx
  unsigned int v35; // ebp
  int v36; // ecx
  unsigned int v37; // edx
  int v38; // ecx
  char v39; // si
  char v40; // cl
  const unsigned int *v41; // ecx
  const unsigned int *v42; // edx
  unsigned int v43; // edx
  const unsigned int *v44; // esi
  unsigned int v45; // edi
  int v46; // edx
  const unsigned int *v47; // ecx
  unsigned int v48; // esi
  unsigned int v49; // ebx
  int v50; // ecx
  unsigned int v51; // edx
  unsigned int v52; // esi
  int v53; // ecx
  const unsigned int *v54; // ecx
  const unsigned int *v55; // edx
  int *v56; // edx
  const unsigned int *v57; // edx
  unsigned int v58; // edi
  int v59; // esi
  const unsigned int *v60; // ecx
  unsigned int v61; // edx
  unsigned int v62; // ebx
  int *v63; // [esp+10h] [ebp-4h]
  int nBitsLeft; // [esp+18h] [ebp+4h]

  v4 = nBits;
  v5 = (pOutData & 3) == 0;
  v63 = (int *)pOutData;
  nBitsLeft = nBits;
  if ( !v5 )
  {
    do
    {
      if ( v4 < 8 )
        break;
      m_nBitsAvail = this->m_nBitsAvail;
      if ( m_nBitsAvail >= 8 )
      {
        m_nInBufWord = this->m_nInBufWord;
        v8 = m_nBitsAvail - 8;
        v9 = m_nInBufWord;
        this->m_nBitsAvail = v8;
        if ( v8 != 0 )
        {
          this->m_nInBufWord = m_nInBufWord >> 8;
          v10 = m_nInBufWord;
        }
        else
        {
          m_pDataIn = this->m_pDataIn;
          m_pBufferEnd = this->m_pBufferEnd;
          this->m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            this->m_pDataIn = m_pDataIn + 1;
            this->m_nBitsAvail = 1;
            this->m_nInBufWord = 0;
            v10 = v9;
          }
          else
          {
            if ( m_pDataIn <= m_pBufferEnd )
            {
              v13 = *m_pDataIn;
              this->m_pDataIn = m_pDataIn + 1;
              this->m_nInBufWord = v13;
            }
            else
            {
              this->m_bOverflow = true;
              this->m_nInBufWord = 0;
            }
            v10 = v9;
          }
        }
        goto LABEL_21;
      }
      v14 = this->m_pBufferEnd;
      v15 = this->m_nInBufWord;
      v16 = 8 - m_nBitsAvail;
      v17 = this->m_pDataIn;
      if ( v17 == v14 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v17 > v14 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_18;
        }
        this->m_nInBufWord = *v17;
      }
      this->m_pDataIn = v17 + 1;
LABEL_18:
      if ( this->m_bOverflow )
      {
        v10 = 0;
      }
      else
      {
        v18 = this->m_nInBufWord;
        v19 = (v18 & CBitBuffer::s_nMaskTable[v16]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v16;
        v10 = v19 | v15;
        this->m_nInBufWord = v18 >> v16;
      }
LABEL_21:
      nBitsLeft -= 8;
      v4 = nBitsLeft;
      *(_BYTE *)v63 = v10;
      v63 = (int *)((char *)v63 + 1);
    }
    while ( ((unsigned __int8)v63 & 3) != 0 );
  }
  if ( v4 < 32 )
    goto LABEL_44;
  v20 = (unsigned int)v4 >> 5;
  nBitsLeft = -32 * ((unsigned int)v4 >> 5) + v4;
  do
  {
    v21 = this->m_nBitsAvail;
    if ( v21 < 32 )
    {
      v28 = this->m_pBufferEnd;
      v29 = this->m_nInBufWord;
      v30 = 32 - v21;
      v31 = this->m_pDataIn;
      if ( v31 == v28 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v31 > v28 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_39;
        }
        this->m_nInBufWord = *v31;
      }
      this->m_pDataIn = v31 + 1;
LABEL_39:
      if ( this->m_bOverflow )
      {
        v24 = 0;
      }
      else
      {
        v32 = this->m_nInBufWord;
        v33 = (v32 & CBitBuffer::s_nMaskTable[v30]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v30;
        v24 = v33 | v29;
        this->m_nInBufWord = v32 >> v30;
      }
      goto LABEL_42;
    }
    v22 = this->m_nInBufWord;
    v23 = v21 - 32;
    this->m_nBitsAvail = v23;
    if ( v23 != 0 )
    {
      this->m_nInBufWord = 0;
      v24 = v22;
    }
    else
    {
      v25 = this->m_pDataIn;
      v26 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v25 == v26 )
      {
        this->m_pDataIn = v25 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v24 = v22;
      }
      else
      {
        if ( v25 <= v26 )
        {
          v27 = *v25;
          this->m_pDataIn = v25 + 1;
          this->m_nInBufWord = v27;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v24 = v22;
      }
    }
LABEL_42:
    v34 = v63++;
    --v20;
    *v34 = v24;
  }
  while ( v20 != 0 );
  v4 = nBitsLeft;
LABEL_44:
  if ( v4 < 8 )
    goto LABEL_66;
  v35 = (unsigned int)v4 >> 3;
  nBitsLeft = v4 - 8 * ((unsigned int)v4 >> 3);
  while ( 2 )
  {
    v36 = this->m_nBitsAvail;
    if ( v36 < 8 )
    {
      v44 = this->m_pBufferEnd;
      v45 = this->m_nInBufWord;
      v46 = 8 - v36;
      v47 = this->m_pDataIn;
      if ( v47 == v44 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v47 > v44 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_61;
        }
        this->m_nInBufWord = *v47;
      }
      this->m_pDataIn = v47 + 1;
LABEL_61:
      if ( this->m_bOverflow )
      {
        v40 = 0;
      }
      else
      {
        v48 = this->m_nInBufWord;
        v49 = (v48 & CBitBuffer::s_nMaskTable[v46]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v46;
        v40 = v49 | v45;
        this->m_nInBufWord = v48 >> v46;
      }
      goto LABEL_64;
    }
    v37 = this->m_nInBufWord;
    v38 = v36 - 8;
    v39 = v37;
    this->m_nBitsAvail = v38;
    if ( v38 != 0 )
    {
      this->m_nInBufWord = v37 >> 8;
      v40 = v37;
    }
    else
    {
      v41 = this->m_pDataIn;
      v42 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v41 == v42 )
      {
        this->m_pDataIn = v41 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v40 = v39;
      }
      else
      {
        if ( v41 <= v42 )
        {
          v43 = *v41;
          this->m_pDataIn = v41 + 1;
          this->m_nInBufWord = v43;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v40 = v39;
      }
    }
LABEL_64:
    *(_BYTE *)v63 = v40;
    --v35;
    v63 = (int *)((char *)v63 + 1);
    if ( v35 != 0 )
      continue;
    break;
  }
  v4 = nBitsLeft;
LABEL_66:
  if ( v4 != 0 )
  {
    v50 = this->m_nBitsAvail;
    if ( v50 >= v4 )
    {
      v51 = this->m_nInBufWord;
      v52 = v51 & CBitBuffer::s_nMaskTable[v4];
      v53 = v50 - v4;
      this->m_nBitsAvail = v53;
      if ( v53 != 0 )
      {
        this->m_nInBufWord = v51 >> v4;
        *(_BYTE *)v63 = v52;
      }
      else
      {
        v54 = this->m_pDataIn;
        v55 = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( v54 == v55 )
        {
          this->m_nInBufWord = 0;
          this->m_nBitsAvail = 1;
          this->m_pDataIn = v54 + 1;
          *(_BYTE *)v63 = v52;
        }
        else
        {
          if ( v54 <= v55 )
          {
            this->m_nInBufWord = *v54;
            v56 = v63;
            this->m_pDataIn = v54 + 1;
          }
          else
          {
            v56 = v63;
            this->m_nInBufWord = 0;
            this->m_bOverflow = true;
          }
          *(_BYTE *)v56 = v52;
        }
      }
      return;
    }
    v57 = this->m_pBufferEnd;
    v58 = this->m_nInBufWord;
    v59 = nBitsLeft - v50;
    v60 = this->m_pDataIn;
    if ( v60 == v57 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
      goto LABEL_81;
    }
    if ( v60 <= v57 )
    {
      this->m_nInBufWord = *v60;
LABEL_81:
      this->m_pDataIn = v60 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
    if ( this->m_bOverflow )
    {
      *(_BYTE *)v63 = 0;
    }
    else
    {
      v61 = this->m_nInBufWord;
      v62 = (v61 & CBitBuffer::s_nMaskTable[v59]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v59;
      this->m_nInBufWord = v61 >> v59;
      *(_BYTE *)v63 = v62 | v58;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B370
// Name: public: bool CBitRead::ReadBytes(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadBytes(CBitRead *this, void *pOut, int nBytes)
{
  CBitRead::ReadBits(this, pOutData: (int)pOut, nBits: 8 * nBytes);
  return !this->m_bOverflow;
}

} // namespace matchmaking_ds

// ============================================================
// Overlay from networksystem (Missing functions)
// ============================================================
namespace networksystem {

//------------------------------------------------------------------------------
// Address: 0x10018A10
// Name: public: bool CBitRead::Seek(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBitRead::Seek(CBitRead *this, int nPosition)
{
  int m_nDataBits; // ecx
  signed int v4; // edi
  int v5; // ecx
  const unsigned int *v6; // ebp
  const unsigned int *v7; // eax
  const unsigned int *m_pBufferEnd; // edx
  int v9; // ecx
  int v10; // eax
  int m_nBitsAvail; // ecx
  const unsigned int *m_pData; // eax
  unsigned int v14; // edx
  unsigned __int16 v15; // dx
  int v16; // ecx
  char v17; // [esp+Fh] [ebp-1h]

  m_nDataBits = nPosition;
  v17 = 1;
  if ( nPosition < 0 || nPosition > this->m_nDataBits )
  {
    m_nDataBits = this->m_nDataBits;
    this->m_bOverflow = true;
    v17 = 0;
  }
  v4 = this->m_nDataBytes & 3;
  if ( this->m_nDataBytes < 4 || v4 != 0 && m_nDataBits / 8 < v4 )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      v14 = *(unsigned __int8 *)m_pData;
      m_pData = (const unsigned int *)((char *)m_pData + 1);
      this->m_nInBufWord = v14;
      if ( v4 > 1 )
      {
        LOBYTE(v15) = 0;
        HIBYTE(v15) = *(_BYTE *)m_pData;
        this->m_nInBufWord |= v15;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
      if ( v4 > 2 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 16;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
    }
    this->m_pDataIn = m_pData;
    v16 = m_nDataBits & 0x1F;
    this->m_nInBufWord >>= v16;
    v10 = 8 * v4 - v16;
    goto LABEL_23;
  }
  v5 = m_nDataBits - 8 * v4;
  v6 = this->m_pData;
  v7 = (const unsigned int *)((char *)&v6[v5 / 32] + v4);
  this->m_pDataIn = v7;
  if ( v6 == nullptr )
    goto LABEL_10;
  m_pBufferEnd = this->m_pBufferEnd;
  this->m_nBitsAvail = 32;
  if ( v7 == m_pBufferEnd )
  {
    this->m_pDataIn = v7 + 1;
LABEL_10:
    this->m_nBitsAvail = 1;
LABEL_11:
    this->m_nInBufWord = 0;
    goto LABEL_12;
  }
  if ( v7 > m_pBufferEnd )
  {
    this->m_bOverflow = true;
    goto LABEL_11;
  }
  this->m_nInBufWord = *v7;
  this->m_pDataIn = v7 + 1;
LABEL_12:
  v9 = v5 & 0x1F;
  this->m_nInBufWord >>= v9;
  v10 = 32 - v9;
  m_nBitsAvail = this->m_nBitsAvail;
  if ( m_nBitsAvail < v10 )
  {
    this->m_nBitsAvail = m_nBitsAvail;
    return v17;
  }
LABEL_23:
  this->m_nBitsAvail = v10;
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x10018B30
// Name: public: void CBitRead::StartReading(void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::StartReading(
        CBitRead *this,
        const unsigned int *pData,
        unsigned int nBytes,
        int iStartBit,
        int nBits)
{
  int v5; // esi

  v5 = nBits;
  this->m_pData = pData;
  this->m_pDataIn = pData;
  this->m_nDataBytes = nBytes;
  if ( nBits == -1 )
    v5 = 8 * nBytes;
  this->m_nDataBits = v5;
  this->m_bOverflow = false;
  this->m_pBufferEnd = (const unsigned int *)((char *)pData + nBytes);
  if ( pData != nullptr )
    CBitRead::Seek(this, nPosition: iStartBit);
}

//------------------------------------------------------------------------------
// Address: 0x10018B70
// Name: public: bool CBitRead::ReadString(char __near *,int,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadString(CBitRead *this, char *pStr, int maxLen, bool bLine, int *pOutNumChars)
{
  int v6; // ebp
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v9; // ecx
  char v10; // si
  char v11; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v14; // edx
  const unsigned int *v15; // esi
  unsigned int v16; // edi
  int v17; // edx
  const unsigned int *v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // ebp
  char v21; // di
  char iChar_3; // [esp+13h] [ebp-5h]
  int v24; // [esp+14h] [ebp-4h]

  iChar_3 = 0;
  v6 = 0;
LABEL_2:
  v24 = v6;
  while ( 1 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail >= 8 )
    {
      m_nInBufWord = this->m_nInBufWord;
      v9 = m_nBitsAvail - 8;
      v10 = m_nInBufWord;
      this->m_nBitsAvail = v9;
      if ( v9 != 0 )
      {
        this->m_nInBufWord = m_nInBufWord >> 8;
        v11 = m_nInBufWord;
      }
      else
      {
        m_pDataIn = this->m_pDataIn;
        m_pBufferEnd = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          v11 = v10;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            v14 = *m_pDataIn;
            this->m_pDataIn = m_pDataIn + 1;
            this->m_nInBufWord = v14;
          }
          else
          {
            this->m_bOverflow = true;
            this->m_nInBufWord = 0;
          }
          v11 = v10;
        }
      }
      goto LABEL_20;
    }
    v15 = this->m_pBufferEnd;
    v16 = this->m_nInBufWord;
    v17 = 8 - m_nBitsAvail;
    v18 = this->m_pDataIn;
    if ( v18 == v15 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
LABEL_17:
      this->m_pDataIn = v18 + 1;
      goto LABEL_18;
    }
    if ( v18 <= v15 )
    {
      this->m_nInBufWord = *v18;
      goto LABEL_17;
    }
    this->m_bOverflow = true;
    this->m_nInBufWord = 0;
LABEL_18:
    if ( this->m_bOverflow )
      break;
    v19 = this->m_nInBufWord;
    v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v17;
    v21 = v20 | v16;
    v6 = v24;
    v11 = v21;
    this->m_nInBufWord = v19 >> v17;
LABEL_20:
    if ( v11 == 0 || bLine && v11 == 10 )
      break;
    if ( v6 < maxLen - 1 )
    {
      pStr[v6++] = v11;
      goto LABEL_2;
    }
    iChar_3 = 1;
  }
  pStr[v6] = 0;
  if ( pOutNumChars != nullptr )
    *pOutNumChars = v6;
  return !this->m_bOverflow && iChar_3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018CC0
// Name: public: void CBitRead::ReadBits(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::ReadBits(CBitRead *this, int pOutData, int nBits)
{
  int v4; // edi
  bool v5; // zf
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v8; // ecx
  char v9; // si
  char v10; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v13; // edx
  const unsigned int *v14; // esi
  unsigned int v15; // edi
  int v16; // edx
  const unsigned int *v17; // ecx
  unsigned int v18; // esi
  unsigned int v19; // ebp
  unsigned int v20; // ebp
  int v21; // ecx
  unsigned int v22; // esi
  int v23; // ecx
  int v24; // ecx
  const unsigned int *v25; // ecx
  const unsigned int *v26; // edx
  unsigned int v27; // edx
  const unsigned int *v28; // esi
  unsigned int v29; // edi
  int v30; // edx
  const unsigned int *v31; // ecx
  unsigned int v32; // esi
  unsigned int v33; // ebx
  int *v34; // edx
  unsigned int v35; // ebp
  int v36; // ecx
  unsigned int v37; // edx
  int v38; // ecx
  char v39; // si
  char v40; // cl
  const unsigned int *v41; // ecx
  const unsigned int *v42; // edx
  unsigned int v43; // edx
  const unsigned int *v44; // esi
  unsigned int v45; // edi
  int v46; // edx
  const unsigned int *v47; // ecx
  unsigned int v48; // esi
  unsigned int v49; // ebx
  int v50; // ecx
  unsigned int v51; // edx
  unsigned int v52; // esi
  int v53; // ecx
  const unsigned int *v54; // ecx
  const unsigned int *v55; // edx
  int *v56; // edx
  const unsigned int *v57; // edx
  unsigned int v58; // edi
  int v59; // esi
  const unsigned int *v60; // ecx
  unsigned int v61; // edx
  unsigned int v62; // ebx
  int *v63; // [esp+10h] [ebp-4h]
  int nBitsLeft; // [esp+18h] [ebp+4h]

  v4 = nBits;
  v5 = (pOutData & 3) == 0;
  v63 = (int *)pOutData;
  nBitsLeft = nBits;
  if ( !v5 )
  {
    do
    {
      if ( v4 < 8 )
        break;
      m_nBitsAvail = this->m_nBitsAvail;
      if ( m_nBitsAvail >= 8 )
      {
        m_nInBufWord = this->m_nInBufWord;
        v8 = m_nBitsAvail - 8;
        v9 = m_nInBufWord;
        this->m_nBitsAvail = v8;
        if ( v8 != 0 )
        {
          this->m_nInBufWord = m_nInBufWord >> 8;
          v10 = m_nInBufWord;
        }
        else
        {
          m_pDataIn = this->m_pDataIn;
          m_pBufferEnd = this->m_pBufferEnd;
          this->m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            this->m_pDataIn = m_pDataIn + 1;
            this->m_nBitsAvail = 1;
            this->m_nInBufWord = 0;
            v10 = v9;
          }
          else
          {
            if ( m_pDataIn <= m_pBufferEnd )
            {
              v13 = *m_pDataIn;
              this->m_pDataIn = m_pDataIn + 1;
              this->m_nInBufWord = v13;
            }
            else
            {
              this->m_bOverflow = true;
              this->m_nInBufWord = 0;
            }
            v10 = v9;
          }
        }
        goto LABEL_21;
      }
      v14 = this->m_pBufferEnd;
      v15 = this->m_nInBufWord;
      v16 = 8 - m_nBitsAvail;
      v17 = this->m_pDataIn;
      if ( v17 == v14 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v17 > v14 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_18;
        }
        this->m_nInBufWord = *v17;
      }
      this->m_pDataIn = v17 + 1;
LABEL_18:
      if ( this->m_bOverflow )
      {
        v10 = 0;
      }
      else
      {
        v18 = this->m_nInBufWord;
        v19 = (v18 & CBitBuffer::s_nMaskTable[v16]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v16;
        v10 = v19 | v15;
        this->m_nInBufWord = v18 >> v16;
      }
LABEL_21:
      nBitsLeft -= 8;
      v4 = nBitsLeft;
      *(_BYTE *)v63 = v10;
      v63 = (int *)((char *)v63 + 1);
    }
    while ( ((unsigned __int8)v63 & 3) != 0 );
  }
  if ( v4 < 32 )
    goto LABEL_44;
  v20 = (unsigned int)v4 >> 5;
  nBitsLeft = -32 * ((unsigned int)v4 >> 5) + v4;
  do
  {
    v21 = this->m_nBitsAvail;
    if ( v21 < 32 )
    {
      v28 = this->m_pBufferEnd;
      v29 = this->m_nInBufWord;
      v30 = 32 - v21;
      v31 = this->m_pDataIn;
      if ( v31 == v28 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v31 > v28 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_39;
        }
        this->m_nInBufWord = *v31;
      }
      this->m_pDataIn = v31 + 1;
LABEL_39:
      if ( this->m_bOverflow )
      {
        v24 = 0;
      }
      else
      {
        v32 = this->m_nInBufWord;
        v33 = (v32 & CBitBuffer::s_nMaskTable[v30]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v30;
        v24 = v33 | v29;
        this->m_nInBufWord = v32 >> v30;
      }
      goto LABEL_42;
    }
    v22 = this->m_nInBufWord;
    v23 = v21 - 32;
    this->m_nBitsAvail = v23;
    if ( v23 != 0 )
    {
      this->m_nInBufWord = 0;
      v24 = v22;
    }
    else
    {
      v25 = this->m_pDataIn;
      v26 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v25 == v26 )
      {
        this->m_pDataIn = v25 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v24 = v22;
      }
      else
      {
        if ( v25 <= v26 )
        {
          v27 = *v25;
          this->m_pDataIn = v25 + 1;
          this->m_nInBufWord = v27;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v24 = v22;
      }
    }
LABEL_42:
    v34 = v63++;
    --v20;
    *v34 = v24;
  }
  while ( v20 != 0 );
  v4 = nBitsLeft;
LABEL_44:
  if ( v4 < 8 )
    goto LABEL_66;
  v35 = (unsigned int)v4 >> 3;
  nBitsLeft = v4 - 8 * ((unsigned int)v4 >> 3);
  while ( 2 )
  {
    v36 = this->m_nBitsAvail;
    if ( v36 < 8 )
    {
      v44 = this->m_pBufferEnd;
      v45 = this->m_nInBufWord;
      v46 = 8 - v36;
      v47 = this->m_pDataIn;
      if ( v47 == v44 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v47 > v44 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_61;
        }
        this->m_nInBufWord = *v47;
      }
      this->m_pDataIn = v47 + 1;
LABEL_61:
      if ( this->m_bOverflow )
      {
        v40 = 0;
      }
      else
      {
        v48 = this->m_nInBufWord;
        v49 = (v48 & CBitBuffer::s_nMaskTable[v46]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v46;
        v40 = v49 | v45;
        this->m_nInBufWord = v48 >> v46;
      }
      goto LABEL_64;
    }
    v37 = this->m_nInBufWord;
    v38 = v36 - 8;
    v39 = v37;
    this->m_nBitsAvail = v38;
    if ( v38 != 0 )
    {
      this->m_nInBufWord = v37 >> 8;
      v40 = v37;
    }
    else
    {
      v41 = this->m_pDataIn;
      v42 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v41 == v42 )
      {
        this->m_pDataIn = v41 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v40 = v39;
      }
      else
      {
        if ( v41 <= v42 )
        {
          v43 = *v41;
          this->m_pDataIn = v41 + 1;
          this->m_nInBufWord = v43;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v40 = v39;
      }
    }
LABEL_64:
    *(_BYTE *)v63 = v40;
    --v35;
    v63 = (int *)((char *)v63 + 1);
    if ( v35 != 0 )
      continue;
    break;
  }
  v4 = nBitsLeft;
LABEL_66:
  if ( v4 != 0 )
  {
    v50 = this->m_nBitsAvail;
    if ( v50 >= v4 )
    {
      v51 = this->m_nInBufWord;
      v52 = v51 & CBitBuffer::s_nMaskTable[v4];
      v53 = v50 - v4;
      this->m_nBitsAvail = v53;
      if ( v53 != 0 )
      {
        this->m_nInBufWord = v51 >> v4;
        *(_BYTE *)v63 = v52;
      }
      else
      {
        v54 = this->m_pDataIn;
        v55 = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( v54 == v55 )
        {
          this->m_nInBufWord = 0;
          this->m_nBitsAvail = 1;
          this->m_pDataIn = v54 + 1;
          *(_BYTE *)v63 = v52;
        }
        else
        {
          if ( v54 <= v55 )
          {
            this->m_nInBufWord = *v54;
            v56 = v63;
            this->m_pDataIn = v54 + 1;
          }
          else
          {
            v56 = v63;
            this->m_nInBufWord = 0;
            this->m_bOverflow = true;
          }
          *(_BYTE *)v56 = v52;
        }
      }
      return;
    }
    v57 = this->m_pBufferEnd;
    v58 = this->m_nInBufWord;
    v59 = nBitsLeft - v50;
    v60 = this->m_pDataIn;
    if ( v60 == v57 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
      goto LABEL_81;
    }
    if ( v60 <= v57 )
    {
      this->m_nInBufWord = *v60;
LABEL_81:
      this->m_pDataIn = v60 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
    if ( this->m_bOverflow )
    {
      *(_BYTE *)v63 = 0;
    }
    else
    {
      v61 = this->m_nInBufWord;
      v62 = (v61 & CBitBuffer::s_nMaskTable[v59]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v59;
      this->m_nInBufWord = v61 >> v59;
      *(_BYTE *)v63 = v62 | v58;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019110
// Name: public: bool CBitRead::ReadBytes(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadBytes(CBitRead *this, void *pOut, int nBytes)
{
  CBitRead::ReadBits(this, pOutData: (int)pOut, nBits: 8 * nBytes);
  return !this->m_bOverflow;
}

} // namespace networksystem

// ============================================================
// Overlay from vmpi_service (Missing functions)
// ============================================================
namespace vmpi_service {

//------------------------------------------------------------------------------
// Address: 0x0040A530
// Name: public: bool CBitRead::Seek(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBitRead::Seek(CBitRead *this, int nPosition)
{
  int m_nDataBits; // ecx
  signed int v4; // edi
  int v5; // ebx
  const unsigned int *v6; // ecx
  const unsigned int *v7; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int v9; // ecx
  int v10; // eax
  int m_nBitsAvail; // ecx
  const unsigned int *m_pData; // eax
  unsigned int v14; // edx
  int v15; // ecx
  bool bSucc; // [esp+Bh] [ebp-1h]

  m_nDataBits = nPosition;
  bSucc = true;
  if ( nPosition < 0 || nPosition > this->m_nDataBits )
  {
    m_nDataBits = this->m_nDataBits;
    this->m_bOverflow = true;
    bSucc = false;
  }
  v4 = this->m_nDataBytes & 3;
  if ( this->m_nDataBytes < 4 || v4 != 0 && m_nDataBits / 8 < v4 )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      v14 = *(unsigned __int8 *)m_pData;
      m_pData = (const unsigned int *)((char *)m_pData + 1);
      this->m_nInBufWord = v14;
      if ( v4 > 1 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 8;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
      if ( v4 > 2 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 16;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
    }
    this->m_pDataIn = m_pData;
    v15 = m_nDataBits & 0x1F;
    this->m_nInBufWord >>= v15;
    v10 = 8 * v4 - v15;
    goto LABEL_23;
  }
  v5 = m_nDataBits - 8 * v4;
  v6 = this->m_pData;
  v7 = (const unsigned int *)((char *)&v6[v5 / 32] + v4);
  this->m_pDataIn = v7;
  if ( v6 == nullptr )
    goto LABEL_10;
  m_pBufferEnd = this->m_pBufferEnd;
  this->m_nBitsAvail = 32;
  if ( v7 == m_pBufferEnd )
  {
    this->m_pDataIn = v7 + 1;
LABEL_10:
    this->m_nBitsAvail = 1;
LABEL_11:
    this->m_nInBufWord = 0;
    goto LABEL_12;
  }
  if ( v7 > m_pBufferEnd )
  {
    this->m_bOverflow = true;
    goto LABEL_11;
  }
  this->m_nInBufWord = *v7;
  this->m_pDataIn = v7 + 1;
LABEL_12:
  v9 = v5 & 0x1F;
  this->m_nInBufWord >>= v9;
  v10 = 32 - v9;
  m_nBitsAvail = this->m_nBitsAvail;
  if ( m_nBitsAvail < v10 )
  {
    this->m_nBitsAvail = m_nBitsAvail;
    return bSucc;
  }
LABEL_23:
  this->m_nBitsAvail = v10;
  return bSucc;
}

//------------------------------------------------------------------------------
// Address: 0x0040A650
// Name: public: void CBitRead::StartReading(void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::StartReading(
        CBitRead *this,
        const unsigned int *pData,
        unsigned int nBytes,
        int iStartBit,
        int nBits)
{
  int v5; // esi

  v5 = nBits;
  this->m_pData = pData;
  this->m_pDataIn = pData;
  this->m_nDataBytes = nBytes;
  if ( nBits == -1 )
    v5 = 8 * nBytes;
  this->m_nDataBits = v5;
  this->m_bOverflow = false;
  this->m_pBufferEnd = (const unsigned int *)((char *)pData + nBytes);
  if ( pData != nullptr )
    CBitRead::Seek(this, nPosition: iStartBit);
}

//------------------------------------------------------------------------------
// Address: 0x0040A690
// Name: public: bool CBitRead::ReadString(char __near *,int,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadString(CBitRead *this, char *pStr, int maxLen, bool bLine, int *pOutNumChars)
{
  int v6; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v9; // ecx
  char v10; // si
  char v11; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v14; // edx
  const unsigned int *v15; // esi
  unsigned int v16; // edi
  int v17; // edx
  const unsigned int *v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // ebx
  int iChar; // [esp+Ch] [ebp-8h]
  bool bTooSmall; // [esp+13h] [ebp-1h]

  bTooSmall = false;
  v6 = 0;
LABEL_2:
  iChar = v6;
  while ( 1 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail < 8 )
      break;
    m_nInBufWord = this->m_nInBufWord;
    v9 = m_nBitsAvail - 8;
    v10 = m_nInBufWord;
    this->m_nBitsAvail = v9;
    if ( v9 != 0 )
    {
      this->m_nInBufWord = m_nInBufWord >> 8;
      v11 = m_nInBufWord;
    }
    else
    {
      m_pDataIn = this->m_pDataIn;
      m_pBufferEnd = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        this->m_pDataIn = m_pDataIn + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v11 = v10;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v14 = *m_pDataIn;
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nInBufWord = v14;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v11 = v10;
      }
    }
LABEL_20:
    if ( v11 == 0 || bLine && v11 == 10 )
      goto LABEL_27;
    if ( v6 < maxLen - 1 )
    {
      pStr[v6++] = v11;
      goto LABEL_2;
    }
    bTooSmall = true;
  }
  v15 = this->m_pBufferEnd;
  v16 = this->m_nInBufWord;
  v17 = 8 - m_nBitsAvail;
  v18 = this->m_pDataIn;
  if ( v18 == v15 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
  }
  else
  {
    if ( v18 > v15 )
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
      goto LABEL_18;
    }
    this->m_nInBufWord = *v18;
  }
  this->m_pDataIn = v18 + 1;
LABEL_18:
  if ( !this->m_bOverflow )
  {
    v19 = this->m_nInBufWord;
    v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v17;
    v11 = v20 | v16;
    v6 = iChar;
    this->m_nInBufWord = v19 >> v17;
    goto LABEL_20;
  }
  v6 = iChar;
LABEL_27:
  pStr[v6] = 0;
  if ( pOutNumChars != nullptr )
    *pOutNumChars = v6;
  return !this->m_bOverflow && !bTooSmall;
}

} // namespace vmpi_service

// ============================================================
// Overlay from vmpi_services_watch (Missing functions)
// ============================================================
namespace vmpi_services_watch {

//------------------------------------------------------------------------------
// Address: 0x004068C0
// Name: public: bool CBitRead::Seek(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBitRead::Seek(CBitRead *this, int nPosition)
{
  int m_nDataBits; // ecx
  signed int v4; // edi
  int v5; // ebx
  const unsigned int *v6; // ecx
  const unsigned int *v7; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int v9; // ecx
  int v10; // eax
  int m_nBitsAvail; // ecx
  const unsigned int *m_pData; // eax
  unsigned int v14; // edx
  int v15; // ecx
  bool bSucc; // [esp+Bh] [ebp-1h]

  m_nDataBits = nPosition;
  bSucc = true;
  if ( nPosition < 0 || nPosition > this->m_nDataBits )
  {
    m_nDataBits = this->m_nDataBits;
    this->m_bOverflow = true;
    bSucc = false;
  }
  v4 = this->m_nDataBytes & 3;
  if ( this->m_nDataBytes < 4 || v4 != 0 && m_nDataBits / 8 < v4 )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      v14 = *(unsigned __int8 *)m_pData;
      m_pData = (const unsigned int *)((char *)m_pData + 1);
      this->m_nInBufWord = v14;
      if ( v4 > 1 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 8;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
      if ( v4 > 2 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 16;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
    }
    this->m_pDataIn = m_pData;
    v15 = m_nDataBits & 0x1F;
    this->m_nInBufWord >>= v15;
    v10 = 8 * v4 - v15;
    goto LABEL_23;
  }
  v5 = m_nDataBits - 8 * v4;
  v6 = this->m_pData;
  v7 = (const unsigned int *)((char *)&v6[v5 / 32] + v4);
  this->m_pDataIn = v7;
  if ( v6 == nullptr )
    goto LABEL_10;
  m_pBufferEnd = this->m_pBufferEnd;
  this->m_nBitsAvail = 32;
  if ( v7 == m_pBufferEnd )
  {
    this->m_pDataIn = v7 + 1;
LABEL_10:
    this->m_nBitsAvail = 1;
LABEL_11:
    this->m_nInBufWord = 0;
    goto LABEL_12;
  }
  if ( v7 > m_pBufferEnd )
  {
    this->m_bOverflow = true;
    goto LABEL_11;
  }
  this->m_nInBufWord = *v7;
  this->m_pDataIn = v7 + 1;
LABEL_12:
  v9 = v5 & 0x1F;
  this->m_nInBufWord >>= v9;
  v10 = 32 - v9;
  m_nBitsAvail = this->m_nBitsAvail;
  if ( m_nBitsAvail < v10 )
  {
    this->m_nBitsAvail = m_nBitsAvail;
    return bSucc;
  }
LABEL_23:
  this->m_nBitsAvail = v10;
  return bSucc;
}

//------------------------------------------------------------------------------
// Address: 0x004069E0
// Name: public: void CBitRead::StartReading(void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::StartReading(
        CBitRead *this,
        const unsigned int *pData,
        unsigned int nBytes,
        int iStartBit,
        int nBits)
{
  int v5; // esi

  v5 = nBits;
  this->m_pData = pData;
  this->m_pDataIn = pData;
  this->m_nDataBytes = nBytes;
  if ( nBits == -1 )
    v5 = 8 * nBytes;
  this->m_nDataBits = v5;
  this->m_bOverflow = false;
  this->m_pBufferEnd = (const unsigned int *)((char *)pData + nBytes);
  if ( pData != nullptr )
    CBitRead::Seek(this, nPosition: iStartBit);
}

//------------------------------------------------------------------------------
// Address: 0x00406A20
// Name: public: bool CBitRead::ReadString(char __near *,int,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadString(CBitRead *this, char *pStr, int maxLen, bool bLine, int *pOutNumChars)
{
  int v6; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v9; // ecx
  char v10; // si
  char v11; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v14; // edx
  const unsigned int *v15; // esi
  unsigned int v16; // edi
  int v17; // edx
  const unsigned int *v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // ebx
  int iChar; // [esp+Ch] [ebp-8h]
  bool bTooSmall; // [esp+13h] [ebp-1h]

  bTooSmall = false;
  v6 = 0;
LABEL_2:
  iChar = v6;
  while ( 1 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail < 8 )
      break;
    m_nInBufWord = this->m_nInBufWord;
    v9 = m_nBitsAvail - 8;
    v10 = m_nInBufWord;
    this->m_nBitsAvail = v9;
    if ( v9 != 0 )
    {
      this->m_nInBufWord = m_nInBufWord >> 8;
      v11 = m_nInBufWord;
    }
    else
    {
      m_pDataIn = this->m_pDataIn;
      m_pBufferEnd = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        this->m_pDataIn = m_pDataIn + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v11 = v10;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v14 = *m_pDataIn;
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nInBufWord = v14;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v11 = v10;
      }
    }
LABEL_20:
    if ( v11 == 0 || bLine && v11 == 10 )
      goto LABEL_27;
    if ( v6 < maxLen - 1 )
    {
      pStr[v6++] = v11;
      goto LABEL_2;
    }
    bTooSmall = true;
  }
  v15 = this->m_pBufferEnd;
  v16 = this->m_nInBufWord;
  v17 = 8 - m_nBitsAvail;
  v18 = this->m_pDataIn;
  if ( v18 == v15 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
  }
  else
  {
    if ( v18 > v15 )
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
      goto LABEL_18;
    }
    this->m_nInBufWord = *v18;
  }
  this->m_pDataIn = v18 + 1;
LABEL_18:
  if ( !this->m_bOverflow )
  {
    v19 = this->m_nInBufWord;
    v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v17;
    v11 = v20 | v16;
    v6 = iChar;
    this->m_nInBufWord = v19 >> v17;
    goto LABEL_20;
  }
  v6 = iChar;
LABEL_27:
  pStr[v6] = 0;
  if ( pOutNumChars != nullptr )
    *pOutNumChars = v6;
  return !this->m_bOverflow && !bTooSmall;
}

//------------------------------------------------------------------------------
// Address: 0x0041C32F
// Name: public: virtual long CArchiveStream::Seek(union _LARGE_INTEGER,unsigned long,union _ULARGE_INTEGER __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CArchiveStream::Seek(
        CArchiveStream *this,
        _LARGE_INTEGER uliOffset,
        unsigned int dwOrigin,
        _ULARGE_INTEGER *puliNew)
{
  CArchive *m_pArchive; // ecx
  CFile *m_pFile; // esi
  unsigned __int64 v7; // rax

  m_pArchive = this->m_pArchive;
  m_pFile = m_pArchive->m_pFile;
  if ( m_pFile == nullptr )
    return -2147467263;
  CArchive::Flush(this: m_pArchive);
  LODWORD(v7) = ((int (__thiscall *)(CFile *, unsigned int, int, unsigned int))m_pFile->Seek)(
                  a1: m_pFile,
                  a2: uliOffset.LowPart,
                  a3: uliOffset.HighPart,
                  a4: dwOrigin);
  if ( puliNew != nullptr )
    puliNew->QuadPart = v7;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004215F6
// Name: public: virtual unsigned __int64 CFile::Seek(__int64,unsigned int)
// Source: json
//------------------------------------------------------------------------------
_LARGE_INTEGER __thiscall CFile::Seek(CFile *this, __int64 lOff, DWORD nFrom)
{
  DWORD LastError; // eax
  void *m_hFile; // [esp-10h] [ebp-1Ch]
  char *m_pszData; // [esp-8h] [ebp-14h]
  _LARGE_INTEGER liOff; // [esp+4h] [ebp-8h] BYREF

  m_hFile = this->m_hFile;
  liOff.HighPart = HIDWORD(lOff);
  liOff.LowPart = SetFilePointer(
                    hFile: m_hFile,
                    lDistanceToMove: lOff,
                    lpDistanceToMoveHigh: &liOff.HighPart,
                    dwMoveMethod: nFrom);
  if ( liOff.LowPart == -1 && GetLastError() != 0 )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
  return liOff;
}

//------------------------------------------------------------------------------
// Address: 0x0042A3FB
// Name: public: virtual unsigned __int64 CMemFile::Seek(__int64,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMemFile::Seek(CMemFile *this, __int64 lOff, unsigned int nFrom)
{
  unsigned int m_nPosition; // esi
  int v5; // eax

  m_nPosition = this->m_nPosition;
  if ( nFrom != 0 )
  {
    if ( nFrom != 1 )
    {
      if ( nFrom != 2 )
        return m_nPosition;
      if ( lOff > 0 )
LABEL_6:
        AfxThrowFileException(cause: 9, lOsError: -1, lpszFileName: nullptr);
      m_nPosition = this->m_nFileSize;
    }
    v5 = (lOff + (unsigned __int64)m_nPosition) >> 32;
    m_nPosition += lOff;
  }
  else
  {
    v5 = HIDWORD(lOff);
    m_nPosition = lOff;
  }
  if ( v5 < 0 )
    goto LABEL_6;
  if ( m_nPosition > this->m_nFileSize )
    this->GrowFile(this, a2: m_nPosition);
  this->m_nPosition = m_nPosition;
  return m_nPosition;
}

//------------------------------------------------------------------------------
// Address: 0x004ED68B
// Name: public: virtual unsigned __int64 COleStreamFile::Seek(__int64,unsigned int)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall COleStreamFile::Seek(COleStreamFile *this, _ULARGE_INTEGER lOff, unsigned int nFrom)
{
  int v3; // eax

  v3 = ((int (__stdcall *)(IStream *, unsigned int, unsigned int, unsigned int, _ULARGE_INTEGER *))this->m_lpStream->Seek)(
         a1: this->m_lpStream,
         a2: lOff.LowPart,
         a3: lOff.HighPart,
         a4: nFrom,
         a5: &lOff);
  if ( v3 != 0 )
    _AfxThrowOleFileException(sc: v3);
  return lOff.QuadPart;
}

//------------------------------------------------------------------------------
// Address: 0x0041C397
// Name: public: CArchiveStream::CArchiveStream(class CArchive __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CArchiveStream *__thiscall CArchiveStream::CArchiveStream(CArchiveStream *this, CArchive *pArchive)
{
  this->__vftable = (CArchiveStream_vtbl *)&CArchiveStream::`vftable';
  this->m_pArchive = pArchive;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041C3AE
// Name: void AfxWingdixTerm(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl AfxWingdixTerm()
{
  AfxDeleteObject(pObject: (void **)&_afxHalftoneBrush);
}

//------------------------------------------------------------------------------
// Address: 0x0041C3B9
// Name: public: void CDC::FillSolidRect(struct tagRECT const __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::FillSolidRect(CDC *this, const tagRECT *lpRect, COLORREF clr)
{
  HDC__ *m_hDC; // eax

  if ( this == nullptr || (m_hDC = this->m_hDC) == nullptr || lpRect == nullptr )
    AfxThrowInvalidArgException();
  SetBkColor(hdc: m_hDC, color: clr);
  ExtTextOutA(hdc: this->m_hDC, x: 0, y: 0, options: 2u, lprect: lpRect, lpString: nullptr, c: 0, lpDx: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0041C3FC
// Name: public: int CRgn::CombineRgn(class CRgn const __near *,class CRgn const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CRgn::CombineRgn(CRgn *this, CRgn *pRgn1, const CRgn *pRgn2, int nCombineMode)
{
  HRGN m_hObject; // edx
  HRGN v5; // eax

  if ( pRgn2 != nullptr )
    m_hObject = (HRGN)pRgn2->m_hObject;
  else
    m_hObject = nullptr;
  v5 = (HRGN)pRgn1;
  if ( pRgn1 != nullptr )
    v5 = (HRGN)pRgn1->m_hObject;
  return CombineRgn(hrgnDst: (HRGN)this->m_hObject, hrgnSrc1: v5, hrgnSrc2: m_hObject, iMode: nCombineMode);
}

//------------------------------------------------------------------------------
// Address: 0x0041C42B
// Name: public: void CDC::DPtoHIMETRIC(struct tagSIZE __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::DPtoHIMETRIC(CDC *this, tagSIZE *lpSize)
{
  int MapMode; // eax
  int v4; // edi
  int DeviceCaps; // ebx
  int cyPixelsPerInch; // eax
  int cyPerInch; // [esp+Ch] [ebp-4h]

  if ( this != nullptr )
  {
    MapMode = GetMapMode(hdc: this->m_hAttribDC);
    v4 = MapMode;
    if ( MapMode < 7 && MapMode != 1 )
    {
      this->SetMapMode(this, a2: 3);
      CDC::DPtoLP(this, lpSize);
      this->SetMapMode(this, a2: v4);
      return;
    }
    DeviceCaps = GetDeviceCaps(hdc: this->m_hAttribDC, index: 88);
    cyPixelsPerInch = GetDeviceCaps(hdc: this->m_hAttribDC, index: 90);
  }
  else
  {
    DeviceCaps = afxData.cxPixelsPerInch;
    cyPixelsPerInch = afxData.cyPixelsPerInch;
  }
  cyPerInch = cyPixelsPerInch;
  lpSize->cx = MulDiv(nNumber: lpSize->cx, nNumerator: 2540, nDenominator: DeviceCaps);
  lpSize->cy = MulDiv(nNumber: lpSize->cy, nNumerator: 2540, nDenominator: cyPerInch);
}

//------------------------------------------------------------------------------
// Address: 0x0041C4BB
// Name: public: void CDC::HIMETRICtoDP(struct tagSIZE __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::HIMETRICtoDP(CDC *this, tagSIZE *lpSize)
{
  int MapMode; // eax
  int v4; // edi
  int DeviceCaps; // edi
  int cyPixelsPerInch; // eax
  int cyPerInch; // [esp+Ch] [ebp-4h]

  if ( this != nullptr )
  {
    MapMode = GetMapMode(hdc: this->m_hAttribDC);
    v4 = MapMode;
    if ( MapMode < 7 && MapMode != 1 )
    {
      this->SetMapMode(this, a2: 3);
      CDC::LPtoDP(this, lpSize);
      this->SetMapMode(this, a2: v4);
      return;
    }
    DeviceCaps = GetDeviceCaps(hdc: this->m_hAttribDC, index: 88);
    cyPixelsPerInch = GetDeviceCaps(hdc: this->m_hAttribDC, index: 90);
  }
  else
  {
    DeviceCaps = afxData.cxPixelsPerInch;
    cyPixelsPerInch = afxData.cyPixelsPerInch;
  }
  cyPerInch = cyPixelsPerInch;
  lpSize->cx = MulDiv(nNumber: lpSize->cx, nNumerator: DeviceCaps, nDenominator: 2540);
  lpSize->cy = MulDiv(nNumber: lpSize->cy, nNumerator: cyPerInch, nDenominator: 2540);
}

//------------------------------------------------------------------------------
// Address: 0x0041C54B
// Name: public: static class CBrush __near * CDC::GetHalftoneBrush(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBrush *__stdcall CDC::GetHalftoneBrush()
{
  int i; // eax
  unsigned __int16 v1; // dx
  HBITMAP Bitmap; // eax
  HBITMAP v3; // esi
  unsigned __int16 grayPattern[8]; // [esp+2h] [ebp-14h] BYREF

  AfxLockGlobals(nLockType: 8u);
  if ( _afxHalftoneBrush == nullptr )
  {
    for ( i = 0; i < 8; grayPattern[i - 1] = v1 )
      v1 = 21845 << (i++ & 1);
    Bitmap = CreateBitmap(nWidth: 8, nHeight: 8, nPlanes: 1u, nBitCount: 1u, lpBits: grayPattern);
    v3 = Bitmap;
    if ( Bitmap != nullptr )
    {
      _afxHalftoneBrush = CreatePatternBrush(hbm: Bitmap);
      DeleteObject(ho: v3);
    }
  }
  if ( _afxWingdixTerm == 0 )
    _afxWingdixTerm = atexit(func: AfxWingdixTerm) == 0;
  AfxUnlockGlobals(nLockType: 8u);
  return (CBrush *)CGdiObject::FromHandle(h: _afxHalftoneBrush);
}

//------------------------------------------------------------------------------
// Address: 0x0041C5F1
// Name: public: void CDC::FillSolidRect(int,int,int,int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::FillSolidRect(CDC *this, int x, int y, int cx, int cy, COLORREF clr)
{
  CRect rect; // [esp+4h] [ebp-14h] BYREF

  SetBkColor(hdc: this->m_hDC, color: clr);
  rect.left = x;
  rect.top = y;
  rect.right = cx + x;
  rect.bottom = cy + y;
  ExtTextOutA(hdc: this->m_hDC, x: 0, y: 0, options: 2u, lprect: &rect, lpString: nullptr, c: 0, lpDx: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0041C64F
// Name: public: void CDC::Draw3dRect(int,int,int,int,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::Draw3dRect(CDC *this, int x, int y, int cx, int cy, COLORREF clrTopLeft, COLORREF clrBottomRight)
{
  CDC::FillSolidRect(this, x, y, cx: cx - 1, cy: 1, clr: clrTopLeft);
  CDC::FillSolidRect(this, x, y, cx: 1, cy: cy - 1, clr: clrTopLeft);
  CDC::FillSolidRect(this, x: cx + x, y, cx: -1, cy, clr: clrBottomRight);
  CDC::FillSolidRect(this, x, y: cy + y, cx, cy: -1, clr: clrBottomRight);
}

//------------------------------------------------------------------------------
// Address: 0x0041C6BB
// Name: public: void CDC::Draw3dRect(struct tagRECT const __near *,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::Draw3dRect(CDC *this, const tagRECT *lpRect, COLORREF clrTopLeft, COLORREF clrBottomRight)
{
  CDC::Draw3dRect(
    this,
    x: lpRect->left,
    y: lpRect->top,
    cx: lpRect->right - lpRect->left,
    cy: lpRect->bottom - lpRect->top,
    clrTopLeft,
    clrBottomRight);
}

//------------------------------------------------------------------------------
// Address: 0x0041C6E9
// Name: public: void CDC::DrawDragRect(struct tagRECT const __near *,struct tagSIZE,struct tagRECT const __near *,struct tagSIZE,class CBrush __near *,class CBrush __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::DrawDragRect(
        CDC *this,
        const tagRECT *lpRect,
        tagSIZE size,
        const tagRECT *lpRectLast,
        tagSIZE sizeLast,
        CFont *pBrush,
        CFont *pBrushLast)
{
  HRGN RectRgnIndirect; // eax
  HRGN v9; // eax
  HRGN RectRgn; // eax
  HRGN v11; // eax
  HRGN v12; // eax
  CFont *v13; // ebx
  CRgn *v14; // eax
  CFont *v15; // ebx
  CGdiObject v16; // [esp+14h] [ebp-50h] BYREF
  CGdiObject v17; // [esp+1Ch] [ebp-48h] BYREF
  CGdiObject v18; // [esp+24h] [ebp-40h] BYREF
  CGdiObject v19; // [esp+2Ch] [ebp-38h] BYREF
  CGdiObject v20; // [esp+34h] [ebp-30h] BYREF
  CFont *pFont; // [esp+3Ch] [ebp-28h]
  CFont *HalftoneBrush; // [esp+40h] [ebp-24h]
  tagRECT rcDst; // [esp+44h] [ebp-20h] BYREF
  int v24; // [esp+60h] [ebp-4h]

  HalftoneBrush = pBrush;
  pFont = pBrushLast;
  v16.m_hObject = nullptr;
  v16.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  v24 = 2;
  v19.m_hObject = nullptr;
  v19.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  v18.m_hObject = nullptr;
  v18.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  RectRgnIndirect = CreateRectRgnIndirect(lprect: lpRect);
  CGdiObject::Attach(this: &v19, hObject: RectRgnIndirect);
  CopyRect(lprcDst: &rcDst, lprcSrc: lpRect);
  InflateRect(lprc: &rcDst, dx: -size.cx, dy: -size.cy);
  IntersectRect(lprcDst: &rcDst, lprcSrc1: &rcDst, lprcSrc2: lpRect);
  v9 = CreateRectRgnIndirect(lprect: &rcDst);
  CGdiObject::Attach(this: &v18, hObject: v9);
  RectRgn = CreateRectRgn(x1: 0, y1: 0, x2: 0, y2: 0);
  CGdiObject::Attach(this: &v16, hObject: RectRgn);
  CRgn::CombineRgn(this: (CRgn *)&v16, pRgn1: (CRgn *)&v19, pRgn2: (const CRgn *)&v18, nCombineMode: 3);
  if ( HalftoneBrush == nullptr )
    HalftoneBrush = (CFont *)CDC::GetHalftoneBrush();
  if ( HalftoneBrush == nullptr )
    AfxThrowInvalidArgException();
  if ( pFont == nullptr )
    pFont = HalftoneBrush;
  v20.m_hObject = nullptr;
  v20.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  v17.m_hObject = nullptr;
  v17.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  LOBYTE(v24) = 4;
  if ( lpRectLast != nullptr )
  {
    v11 = CreateRectRgn(x1: 0, y1: 0, x2: 0, y2: 0);
    CGdiObject::Attach(this: &v20, hObject: v11);
    SetRectRgn(
      hrgn: (HRGN)v19.m_hObject,
      left: lpRectLast->left,
      top: lpRectLast->top,
      right: lpRectLast->right,
      bottom: lpRectLast->bottom);
    CopyRect(lprcDst: &rcDst, lprcSrc: lpRectLast);
    InflateRect(lprc: &rcDst, dx: -sizeLast.cx, dy: -sizeLast.cy);
    IntersectRect(lprcDst: &rcDst, lprcSrc1: &rcDst, lprcSrc2: lpRectLast);
    SetRectRgn(hrgn: (HRGN)v18.m_hObject, left: rcDst.left, top: rcDst.top, right: rcDst.right, bottom: rcDst.bottom);
    CRgn::CombineRgn(this: (CRgn *)&v20, pRgn1: (CRgn *)&v19, pRgn2: (const CRgn *)&v18, nCombineMode: 3);
    if ( HalftoneBrush->m_hObject == pFont->m_hObject )
    {
      v12 = CreateRectRgn(x1: 0, y1: 0, x2: 0, y2: 0);
      CGdiObject::Attach(this: &v17, hObject: v12);
      CRgn::CombineRgn(this: (CRgn *)&v17, pRgn1: (CRgn *)&v20, pRgn2: (const CRgn *)&v16, nCombineMode: 3);
    }
  }
  if ( HalftoneBrush->m_hObject != pFont->m_hObject && lpRectLast != nullptr )
  {
    CDC::SelectClipRgn(this, pRgn: (CRgn *)&v20);
    this->GetClipBox(this, a2: &rcDst);
    v13 = CDC::SelectObject(this, pFont);
    PatBlt(
      hdc: this->m_hDC,
      x: rcDst.left,
      y: rcDst.top,
      w: rcDst.right - rcDst.left,
      h: rcDst.bottom - rcDst.top,
      rop: 0x5A0049u);
    CDC::SelectObject(this, pFont: v13);
  }
  v14 = (CRgn *)&v17;
  if ( v17.m_hObject == nullptr )
    v14 = (CRgn *)&v16;
  CDC::SelectClipRgn(this, pRgn: v14);
  this->GetClipBox(this, a2: &rcDst);
  v15 = CDC::SelectObject(this, pFont: HalftoneBrush);
  PatBlt(
    hdc: this->m_hDC,
    x: rcDst.left,
    y: rcDst.top,
    w: rcDst.right - rcDst.left,
    h: rcDst.bottom - rcDst.top,
    rop: 0x5A0049u);
  if ( v15 != nullptr )
    CDC::SelectObject(this, pFont: v15);
  CDC::SelectClipRgn(this, pRgn: nullptr);
  LOBYTE(v24) = 3;
  v17.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &v17);
  LOBYTE(v24) = 2;
  v20.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &v20);
  LOBYTE(v24) = 1;
  v18.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &v18);
  LOBYTE(v24) = 0;
  v19.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &v19);
  v24 = -1;
  v16.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &v16);
}

//------------------------------------------------------------------------------
// Address: 0x00421649
// Name: public: virtual unsigned __int64 CFile::GetPosition(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LARGE_INTEGER __thiscall CFile::GetPosition(CFile *this)
{
  DWORD LastError; // eax
  void *m_hFile; // [esp-10h] [ebp-1Ch]
  char *m_pszData; // [esp-8h] [ebp-14h]
  _LARGE_INTEGER liPos; // [esp+4h] [ebp-8h] BYREF

  m_hFile = this->m_hFile;
  liPos.HighPart = 0;
  liPos.LowPart = SetFilePointer(
                    hFile: m_hFile,
                    lDistanceToMove: 0,
                    lpDistanceToMoveHigh: &liPos.HighPart,
                    dwMoveMethod: 1u);
  if ( liPos.LowPart == -1 && GetLastError() != 0 )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
  return liPos;
}

//------------------------------------------------------------------------------
// Address: 0x00421695
// Name: public: virtual void CFile::Flush(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFile::Flush(CFile *this)
{
  DWORD LastError; // eax
  char *m_pszData; // [esp-4h] [ebp-8h]

  if ( this->m_hFile != (void *)-1 && !FlushFileBuffers(hFile: this->m_hFile) )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004216BE
// Name: public: virtual void CFile::LockRange(unsigned __int64,unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFile::LockRange(CFile *this, unsigned __int64 dwPos, unsigned __int64 dwCount)
{
  DWORD LastError; // eax
  char *m_pszData; // [esp-4h] [ebp-8h]

  if ( !LockFile(
          hFile: this->m_hFile,
          dwFileOffsetLow: dwPos,
          dwFileOffsetHigh: HIDWORD(dwPos),
          nNumberOfBytesToLockLow: dwCount,
          nNumberOfBytesToLockHigh: HIDWORD(dwCount)) )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004216F3
// Name: public: virtual void CFile::UnlockRange(unsigned __int64,unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFile::UnlockRange(CFile *this, unsigned __int64 dwPos, unsigned __int64 dwCount)
{
  DWORD LastError; // eax
  char *m_pszData; // [esp-4h] [ebp-8h]

  if ( !UnlockFile(
          hFile: this->m_hFile,
          dwFileOffsetLow: dwPos,
          dwFileOffsetHigh: HIDWORD(dwPos),
          nNumberOfBytesToUnlockLow: dwCount,
          nNumberOfBytesToUnlockHigh: HIDWORD(dwCount)) )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A469
// Name: public: virtual void CMemFile::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMemFile::Close(CMemFile *this)
{
  unsigned __int8 *m_lpBuffer; // eax

  m_lpBuffer = this->m_lpBuffer;
  this->m_nGrowBytes = 0;
  this->m_nPosition = 0;
  this->m_nBufferSize = 0;
  this->m_nFileSize = 0;
  if ( m_lpBuffer != nullptr && this->m_bAutoDelete != 0 )
    this->Free(this, a2: m_lpBuffer);
  this->m_lpBuffer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042A495
// Name: public: virtual void CMemFile::Abort(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMemFile::Abort(CMemFile *this)
{
  this->Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042A49A
// Name: public: virtual void CMemFile::UnlockRange(unsigned __int64,unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall __noreturn CMemFile::UnlockRange(
        CMemFile *this,
        unsigned __int64 __formal,
        unsigned __int64 __formal_4)
{
  AfxThrowNotSupportedException();
}

//------------------------------------------------------------------------------
// Address: 0x0042A4A0
// Name: public: virtual class CFile __near * CMemFile::Duplicate(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall __noreturn CMemFile::Duplicate(CMemFile *this)
{
  AfxThrowNotSupportedException();
}

//------------------------------------------------------------------------------
// Address: 0x0042A4A5
// Name: public: virtual unsigned int CMemFile::GetBufferPtr(unsigned int,unsigned int,void __near * __near *,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMemFile::GetBufferPtr(
        CMemFile *this,
        unsigned int nCommand,
        unsigned int nCount,
        void **ppBufStart,
        void **ppBufMax)
{
  unsigned int m_nPosition; // eax
  void **v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // ecx
  unsigned int m_nBufferSize; // eax
  unsigned int m_nFileSize; // eax
  unsigned __int8 *v14; // eax

  if ( nCommand == 3 )
    return this->m_nGrowBytes != 0;
  if ( nCommand == 2 )
  {
    this->m_nPosition += nCount;
    m_nPosition = this->m_nPosition;
    if ( m_nPosition > this->m_nFileSize )
      this->m_nFileSize = m_nPosition;
    return 0;
  }
  else if ( ppBufStart != nullptr && (v8 = ppBufMax, ppBufMax != nullptr) )
  {
    v9 = nCount;
    if ( nCommand == 1 )
    {
      v10 = this->m_nPosition;
      v11 = v10 + nCount;
      if ( v10 + nCount < v10 || v11 < nCount )
        AfxThrowInvalidArgException();
      if ( v11 > this->m_nBufferSize )
      {
        this->GrowFile(this, a2: v11);
        v8 = ppBufMax;
      }
    }
    *ppBufStart = &this->m_lpBuffer[this->m_nPosition];
    if ( nCommand == 1 )
    {
      m_nBufferSize = nCount + this->m_nPosition;
      if ( this->m_nBufferSize < m_nBufferSize )
        m_nBufferSize = this->m_nBufferSize;
      *v8 = &this->m_lpBuffer[m_nBufferSize];
    }
    else
    {
      if ( nCount == -1 )
        v9 = this->m_nBufferSize - this->m_nPosition;
      m_nFileSize = v9 + this->m_nPosition;
      if ( this->m_nFileSize < m_nFileSize )
        m_nFileSize = this->m_nFileSize;
      v14 = &this->m_lpBuffer[m_nFileSize];
      *v8 = v14;
      this->m_nPosition += v14 - (_BYTE *)*ppBufStart;
    }
    return (_BYTE *)*v8 - (_BYTE *)*ppBufStart;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A576
// Name: public: virtual struct CRuntimeClass __near * CMemFile::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMemFile::GetRuntimeClass(CMemFile *this)
{
  return &CMemFile::classCMemFile;
}

//------------------------------------------------------------------------------
// Address: 0x0042A57C
// Name: public: virtual CMemFile::~CMemFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMemFile::~CMemFile(CMemFile *this)
{
  this->__vftable = (CMemFile_vtbl *)&CMemFile::`vftable';
  if ( this->m_lpBuffer != nullptr )
    CMemFile::Close(this);
  this->m_nGrowBytes = 0;
  this->m_nPosition = 0;
  this->m_nBufferSize = 0;
  this->m_nFileSize = 0;
  CFile::~CFile(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042A5BF
// Name: protected: virtual unsigned char __near * CMemFile::Memcpy(unsigned char __near *,unsigned char const __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CMemFile::Memcpy(
        CMemFile *this,
        unsigned __int8 *lpMemTarget,
        const unsigned __int8 *lpMemSource,
        unsigned int nBytes)
{
  ATL::Checked::memcpy_s(_S1: lpMemTarget, _S1max: nBytes, _S2: lpMemSource, _N: nBytes);
  return lpMemTarget;
}

//------------------------------------------------------------------------------
// Address: 0x0042A600
// Name: public: virtual struct CRuntimeClass __near * CObArray::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CObArray::GetRuntimeClass(CObArray *this)
{
  return &CObArray::classCObArray;
}

//------------------------------------------------------------------------------
// Address: 0x0042A606
// Name: public: CObArray::CObArray(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CObArray *__thiscall CObArray::CObArray(CObArray *this)
{
  this->__vftable = (CObArray_vtbl *)&CObArray::`vftable';
  this->m_pData = nullptr;
  this->m_nGrowBy = 0;
  this->m_nMaxSize = 0;
  this->m_nSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042A61D
// Name: public: virtual CObArray::~CObArray(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CObArray::~CObArray(CObArray *this)
{
  CObject **m_pData; // [esp-4h] [ebp-4h]

  m_pData = this->m_pData;
  this->__vftable = (CObArray_vtbl *)&CObArray::`vftable';
  operator delete(p: m_pData);
}

} // namespace vmpi_services_watch

// ============================================================
// Overlay from xlspmastertest (Missing functions)
// ============================================================
namespace xlspmastertest {

//------------------------------------------------------------------------------
// Address: 0x00402CD0
// Name: public: bool CBitRead::Seek(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBitRead::Seek(CBitRead *this, int nPosition)
{
  int m_nDataBits; // ecx
  signed int v4; // edi
  int v5; // ebx
  const unsigned int *v6; // ecx
  const unsigned int *v7; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int v9; // ecx
  int v10; // eax
  int m_nBitsAvail; // ecx
  const unsigned int *m_pData; // eax
  unsigned int v14; // edx
  int v15; // ecx
  bool bSucc; // [esp+Bh] [ebp-1h]

  m_nDataBits = nPosition;
  bSucc = true;
  if ( nPosition < 0 || nPosition > this->m_nDataBits )
  {
    m_nDataBits = this->m_nDataBits;
    this->m_bOverflow = true;
    bSucc = false;
  }
  v4 = this->m_nDataBytes & 3;
  if ( this->m_nDataBytes < 4 || v4 != 0 && m_nDataBits / 8 < v4 )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      v14 = *(unsigned __int8 *)m_pData;
      m_pData = (const unsigned int *)((char *)m_pData + 1);
      this->m_nInBufWord = v14;
      if ( v4 > 1 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 8;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
      if ( v4 > 2 )
      {
        this->m_nInBufWord |= *(unsigned __int8 *)m_pData << 16;
        m_pData = (const unsigned int *)((char *)m_pData + 1);
      }
    }
    this->m_pDataIn = m_pData;
    v15 = m_nDataBits & 0x1F;
    this->m_nInBufWord >>= v15;
    v10 = 8 * v4 - v15;
    goto LABEL_23;
  }
  v5 = m_nDataBits - 8 * v4;
  v6 = this->m_pData;
  v7 = (const unsigned int *)((char *)&v6[v5 / 32] + v4);
  this->m_pDataIn = v7;
  if ( v6 == nullptr )
    goto LABEL_10;
  m_pBufferEnd = this->m_pBufferEnd;
  this->m_nBitsAvail = 32;
  if ( v7 == m_pBufferEnd )
  {
    this->m_pDataIn = v7 + 1;
LABEL_10:
    this->m_nBitsAvail = 1;
LABEL_11:
    this->m_nInBufWord = 0;
    goto LABEL_12;
  }
  if ( v7 > m_pBufferEnd )
  {
    this->m_bOverflow = true;
    goto LABEL_11;
  }
  this->m_nInBufWord = *v7;
  this->m_pDataIn = v7 + 1;
LABEL_12:
  v9 = v5 & 0x1F;
  this->m_nInBufWord >>= v9;
  v10 = 32 - v9;
  m_nBitsAvail = this->m_nBitsAvail;
  if ( m_nBitsAvail < v10 )
  {
    this->m_nBitsAvail = m_nBitsAvail;
    return bSucc;
  }
LABEL_23:
  this->m_nBitsAvail = v10;
  return bSucc;
}

//------------------------------------------------------------------------------
// Address: 0x00402DF0
// Name: public: void CBitRead::StartReading(void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::StartReading(
        CBitRead *this,
        const unsigned int *pData,
        unsigned int nBytes,
        int iStartBit,
        int nBits)
{
  int v5; // esi

  v5 = nBits;
  this->m_pData = pData;
  this->m_pDataIn = pData;
  this->m_nDataBytes = nBytes;
  if ( nBits == -1 )
    v5 = 8 * nBytes;
  this->m_nDataBits = v5;
  this->m_bOverflow = false;
  this->m_pBufferEnd = (const unsigned int *)((char *)pData + nBytes);
  if ( pData != nullptr )
    CBitRead::Seek(this, nPosition: iStartBit);
}

//------------------------------------------------------------------------------
// Address: 0x00402E30
// Name: public: bool CBitRead::ReadString(char __near *,int,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadString(CBitRead *this, char *pStr, int maxLen, bool bLine, int *pOutNumChars)
{
  int v6; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v9; // ecx
  char v10; // si
  char v11; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v14; // edx
  const unsigned int *v15; // esi
  unsigned int v16; // edi
  int v17; // edx
  const unsigned int *v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // ebx
  int iChar; // [esp+Ch] [ebp-8h]
  bool bTooSmall; // [esp+13h] [ebp-1h]

  bTooSmall = false;
  v6 = 0;
LABEL_2:
  iChar = v6;
  while ( 1 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail < 8 )
      break;
    m_nInBufWord = this->m_nInBufWord;
    v9 = m_nBitsAvail - 8;
    v10 = m_nInBufWord;
    this->m_nBitsAvail = v9;
    if ( v9 != 0 )
    {
      this->m_nInBufWord = m_nInBufWord >> 8;
      v11 = m_nInBufWord;
    }
    else
    {
      m_pDataIn = this->m_pDataIn;
      m_pBufferEnd = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        this->m_pDataIn = m_pDataIn + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v11 = v10;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v14 = *m_pDataIn;
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nInBufWord = v14;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v11 = v10;
      }
    }
LABEL_20:
    if ( v11 == 0 || bLine && v11 == 10 )
      goto LABEL_27;
    if ( v6 < maxLen - 1 )
    {
      pStr[v6++] = v11;
      goto LABEL_2;
    }
    bTooSmall = true;
  }
  v15 = this->m_pBufferEnd;
  v16 = this->m_nInBufWord;
  v17 = 8 - m_nBitsAvail;
  v18 = this->m_pDataIn;
  if ( v18 == v15 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
  }
  else
  {
    if ( v18 > v15 )
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
      goto LABEL_18;
    }
    this->m_nInBufWord = *v18;
  }
  this->m_pDataIn = v18 + 1;
LABEL_18:
  if ( !this->m_bOverflow )
  {
    v19 = this->m_nInBufWord;
    v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v17;
    v11 = v20 | v16;
    v6 = iChar;
    this->m_nInBufWord = v19 >> v17;
    goto LABEL_20;
  }
  v6 = iChar;
LABEL_27:
  pStr[v6] = 0;
  if ( pOutNumChars != nullptr )
    *pOutNumChars = v6;
  return !this->m_bOverflow && !bTooSmall;
}

} // namespace xlspmastertest

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10361E30
// Name: public: bool CBitRead::ReadString(char __near *,int,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadString(CBitRead *this, char *pStr, int maxLen, bool bLine, int *pOutNumChars)
{
  int v6; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v9; // ecx
  char v10; // si
  char v11; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v14; // edx
  const unsigned int *v15; // esi
  unsigned int v16; // edi
  int v17; // edx
  const unsigned int *v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // ebx
  int iChar; // [esp+Ch] [ebp-8h]
  bool bTooSmall; // [esp+13h] [ebp-1h]

  bTooSmall = false;
  v6 = 0;
LABEL_2:
  iChar = v6;
  while ( 1 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail < 8 )
      break;
    m_nInBufWord = this->m_nInBufWord;
    v9 = m_nBitsAvail - 8;
    v10 = m_nInBufWord;
    this->m_nBitsAvail = v9;
    if ( v9 != 0 )
    {
      this->m_nInBufWord = m_nInBufWord >> 8;
      v11 = m_nInBufWord;
    }
    else
    {
      m_pDataIn = this->m_pDataIn;
      m_pBufferEnd = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        this->m_pDataIn = m_pDataIn + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v11 = v10;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v14 = *m_pDataIn;
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nInBufWord = v14;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v11 = v10;
      }
    }
LABEL_20:
    if ( v11 == 0 || bLine && v11 == 10 )
      goto LABEL_27;
    if ( v6 < maxLen - 1 )
    {
      pStr[v6++] = v11;
      goto LABEL_2;
    }
    bTooSmall = true;
  }
  v15 = this->m_pBufferEnd;
  v16 = this->m_nInBufWord;
  v17 = 8 - m_nBitsAvail;
  v18 = this->m_pDataIn;
  if ( v18 == v15 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
  }
  else
  {
    if ( v18 > v15 )
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
      goto LABEL_18;
    }
    this->m_nInBufWord = *v18;
  }
  this->m_pDataIn = v18 + 1;
LABEL_18:
  if ( !this->m_bOverflow )
  {
    v19 = this->m_nInBufWord;
    v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v17;
    v11 = v20 | v16;
    v6 = iChar;
    this->m_nInBufWord = v19 >> v17;
    goto LABEL_20;
  }
  v6 = iChar;
LABEL_27:
  pStr[v6] = 0;
  if ( pOutNumChars != nullptr )
    *pOutNumChars = v6;
  return !this->m_bOverflow && !bTooSmall;
}

//------------------------------------------------------------------------------
// Address: 0x10361F80
// Name: public: float CBitRead::ReadBitAngle(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitAngle(CBitRead *this, int numbits)
{
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // edx
  signed int v5; // edi
  int v6; // esi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  double v10; // st7
  unsigned int v11; // edx
  const unsigned int *v12; // edx
  unsigned int v13; // edi
  int v14; // esi
  const unsigned int *v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // ebx
  float shift; // [esp+4h] [ebp-4h]
  int numbitsa; // [esp+10h] [ebp+8h]
  int numbitsb; // [esp+10h] [ebp+8h]

  m_nBitsAvail = this->m_nBitsAvail;
  shift = (float)`GetBitForBitnum'::`2'::bitsForBitnum[numbits & 0x1F];
  if ( m_nBitsAvail >= numbits )
  {
    m_nInBufWord = this->m_nInBufWord;
    v5 = m_nInBufWord & CBitBuffer::s_nMaskTable[numbits];
    v6 = m_nBitsAvail - numbits;
    this->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      this->m_nInBufWord = m_nInBufWord >> numbits;
      return 360.0 / shift * (double)v5;
    }
    else
    {
      m_pDataIn = this->m_pDataIn;
      m_pBufferEnd = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = m_pDataIn + 1;
        return 360.0 / shift * (double)v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v11 = *m_pDataIn;
          v10 = 360.0 / shift;
          numbitsa = v5;
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nInBufWord = v11;
        }
        else
        {
          numbitsa = v5;
          v10 = 360.0 / shift;
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        return v10 * (double)numbitsa;
      }
    }
  }
  v12 = this->m_pBufferEnd;
  v13 = this->m_nInBufWord;
  v14 = numbits - m_nBitsAvail;
  v15 = this->m_pDataIn;
  if ( v15 == v12 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
LABEL_15:
    this->m_pDataIn = v15 + 1;
    goto LABEL_16;
  }
  if ( v15 <= v12 )
  {
    this->m_nInBufWord = *v15;
    goto LABEL_15;
  }
  this->m_bOverflow = true;
  this->m_nInBufWord = 0;
LABEL_16:
  if ( this->m_bOverflow )
  {
    numbitsb = 0;
  }
  else
  {
    v16 = this->m_nInBufWord;
    v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v14;
    numbitsb = v17 | v13;
    this->m_nInBufWord = v16 >> v14;
  }
  return 360.0 / shift * (double)numbitsb;
}

//------------------------------------------------------------------------------
// Address: 0x103620E0
// Name: public: float CBitRead::ReadBitCoord(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitCoord(CBitRead *this)
{
  unsigned int m_nInBufWord; // ecx
  int v3; // esi
  bool v4; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v7; // ecx
  int v8; // ebx
  const unsigned int *v9; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // ecx
  const unsigned int *v12; // ecx
  const unsigned int *v13; // edx
  int m_nBitsAvail; // ecx
  unsigned int v15; // edx
  int v16; // ecx
  unsigned int v17; // esi
  int v18; // edi
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edx
  unsigned int v21; // edx
  const unsigned int *v22; // esi
  unsigned int v23; // edi
  int v24; // edx
  const unsigned int *v25; // ecx
  unsigned int v26; // esi
  unsigned int v27; // ebx
  int v28; // ecx
  unsigned int v29; // edx
  int v30; // ecx
  int v31; // edi
  const unsigned int *v32; // ecx
  const unsigned int *v33; // edx
  unsigned int v34; // edx
  const unsigned int *v35; // esi
  unsigned int v36; // edi
  int v37; // edx
  const unsigned int *v38; // ecx
  unsigned int v39; // esi
  unsigned int v40; // ebx
  float v41; // xmm0_4
  int v43; // [esp+0h] [ebp-14h]
  int fractval; // [esp+4h] [ebp-10h]
  int v45; // [esp+8h] [ebp-Ch]
  int intval; // [esp+Ch] [ebp-8h]
  float value; // [esp+10h] [ebp-4h]

  m_nInBufWord = this->m_nInBufWord;
  v3 = m_nInBufWord & 1;
  v4 = this->m_nBitsAvail-- == 1;
  value = 0.0;
  if ( v4 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  v7 = this->m_nInBufWord;
  v8 = v7 & 1;
  v4 = this->m_nBitsAvail-- == 1;
  intval = v3;
  v45 = v8;
  if ( v4 )
  {
    v9 = this->m_pDataIn;
    v10 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v9 + 1;
    }
    else if ( v9 <= v10 )
    {
      this->m_nInBufWord = *v9;
      this->m_pDataIn = v9 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v7 >> 1;
  }
  fractval = v8;
  if ( v3 == 0 && v8 == 0 )
    return value;
  v11 = this->m_nInBufWord;
  v4 = this->m_nBitsAvail-- == 1;
  v43 = v11 & 1;
  if ( v4 )
  {
    v12 = this->m_pDataIn;
    v13 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v12 == v13 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v12 + 1;
    }
    else if ( v12 <= v13 )
    {
      this->m_nInBufWord = *v12;
      this->m_pDataIn = v12 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v11 >> 1;
  }
  if ( v3 != 0 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail >= 14 )
    {
      v15 = this->m_nInBufWord;
      v16 = m_nBitsAvail - 14;
      v17 = 0;
      v18 = v15 & 0x3FFF;
      this->m_nBitsAvail = v16;
      if ( v16 != 0 )
      {
        this->m_nInBufWord = v15 >> 14;
LABEL_43:
        intval = v18 + 1;
        goto LABEL_44;
      }
      v19 = this->m_pDataIn;
      v20 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v19 == v20 )
      {
        this->m_nBitsAvail = 1;
        this->m_pDataIn = v19 + 1;
      }
      else
      {
        if ( v19 <= v20 )
        {
          v21 = *v19;
          this->m_pDataIn = v19 + 1;
          this->m_nInBufWord = v21;
          goto LABEL_43;
        }
        this->m_bOverflow = true;
      }
LABEL_42:
      this->m_nInBufWord = v17;
      goto LABEL_43;
    }
    v22 = this->m_pBufferEnd;
    v23 = this->m_nInBufWord;
    v24 = 14 - m_nBitsAvail;
    v25 = this->m_pDataIn;
    if ( v25 == v22 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v22 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_39:
        if ( this->m_bOverflow )
        {
          v18 = 0;
          goto LABEL_43;
        }
        v26 = this->m_nInBufWord;
        v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v24;
        v18 = v27 | v23;
        v8 = v45;
        v17 = v26 >> v24;
        goto LABEL_42;
      }
      this->m_nInBufWord = *v25;
    }
    this->m_pDataIn = v25 + 1;
    goto LABEL_39;
  }
LABEL_44:
  if ( v8 == 0 )
  {
    v31 = fractval;
    goto LABEL_63;
  }
  v28 = this->m_nBitsAvail;
  if ( v28 >= 5 )
  {
    v29 = this->m_nInBufWord;
    v30 = v28 - 5;
    v31 = v29 & 0x1F;
    this->m_nBitsAvail = v30;
    if ( v30 != 0 )
    {
      this->m_nInBufWord = v29 >> 5;
    }
    else
    {
      v32 = this->m_pDataIn;
      v33 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v32 == v33 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v32 + 1;
      }
      else if ( v32 <= v33 )
      {
        v34 = *v32;
        this->m_pDataIn = v32 + 1;
        this->m_nInBufWord = v34;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
    }
    goto LABEL_63;
  }
  v35 = this->m_pBufferEnd;
  v36 = this->m_nInBufWord;
  v37 = 5 - v28;
  v38 = this->m_pDataIn;
  if ( v38 == v35 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
  }
  else
  {
    if ( v38 > v35 )
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
      goto LABEL_59;
    }
    this->m_nInBufWord = *v38;
  }
  this->m_pDataIn = v38 + 1;
LABEL_59:
  if ( this->m_bOverflow )
  {
    v31 = 0;
  }
  else
  {
    v39 = this->m_nInBufWord;
    v40 = (v39 & CBitBuffer::s_nMaskTable[v37]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v37;
    v31 = v40 | v36;
    this->m_nInBufWord = v39 >> v37;
  }
LABEL_63:
  v41 = (float)((float)v31 * 0.03125) + (double)intval;
  value = v41;
  if ( v43 != 0 )
    LODWORD(value) = LODWORD(v41) ^ _mask__NegFloat_;
  return value;
}

//------------------------------------------------------------------------------
// Address: 0x10362420
// Name: public: void CBitRead::ReadBitVec3Coord(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::ReadBitVec3Coord(CBitRead *this, Vector *fa)
{
  unsigned int m_nInBufWord; // eax
  bool v5; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v8; // eax
  const unsigned int *v9; // eax
  const unsigned int *v10; // ecx
  unsigned int v11; // eax
  int v12; // edi
  const unsigned int *v13; // eax
  const unsigned int *v14; // ecx
  int v15; // [esp+0h] [ebp-4h]
  Vector *faa; // [esp+Ch] [ebp+8h]

  fa->x = 0.0;
  fa->y = 0.0;
  fa->z = 0.0;
  m_nInBufWord = this->m_nInBufWord;
  v5 = this->m_nBitsAvail-- == 1;
  faa = (Vector *)(m_nInBufWord & 1);
  if ( v5 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  v8 = this->m_nInBufWord;
  v5 = this->m_nBitsAvail-- == 1;
  v15 = v8 & 1;
  if ( v5 )
  {
    v9 = this->m_pDataIn;
    v10 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v9 + 1;
    }
    else if ( v9 <= v10 )
    {
      this->m_nInBufWord = *v9;
      this->m_pDataIn = v9 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v8 >> 1;
  }
  v11 = this->m_nInBufWord;
  v12 = v11 & 1;
  v5 = this->m_nBitsAvail-- == 1;
  if ( v5 )
  {
    v13 = this->m_pDataIn;
    v14 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v13 == v14 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v13 + 1;
    }
    else if ( v13 <= v14 )
    {
      this->m_nInBufWord = *v13;
      this->m_pDataIn = v13 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v11 >> 1;
  }
  if ( faa != nullptr )
    fa->x = CBitRead::ReadBitCoord(this);
  if ( v15 != 0 )
    fa->y = CBitRead::ReadBitCoord(this);
  if ( v12 != 0 )
    fa->z = CBitRead::ReadBitCoord(this);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037C640
// Name: public: float CBitRead::ReadBitAngle(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitAngle(CBitRead *this, int numbits)
{
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // edx
  signed int v5; // edi
  int v6; // esi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  double v10; // st7
  unsigned int v11; // edx
  const unsigned int *v12; // edx
  unsigned int v13; // edi
  int v14; // esi
  const unsigned int *v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // ebx
  float shift; // [esp+4h] [ebp-4h]
  int numbitsa; // [esp+10h] [ebp+8h]
  int numbitsb; // [esp+10h] [ebp+8h]

  m_nBitsAvail = this->m_nBitsAvail;
  shift = (float)`GetBitForBitnum'::`2'::bitsForBitnum[numbits & 0x1F];
  if ( m_nBitsAvail >= numbits )
  {
    m_nInBufWord = this->m_nInBufWord;
    v5 = m_nInBufWord & CBitBuffer::s_nMaskTable[numbits];
    v6 = m_nBitsAvail - numbits;
    this->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      this->m_nInBufWord = m_nInBufWord >> numbits;
      return 360.0 / shift * (double)v5;
    }
    else
    {
      m_pDataIn = this->m_pDataIn;
      m_pBufferEnd = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = m_pDataIn + 1;
        return 360.0 / shift * (double)v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v11 = *m_pDataIn;
          v10 = 360.0 / shift;
          numbitsa = v5;
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nInBufWord = v11;
        }
        else
        {
          numbitsa = v5;
          v10 = 360.0 / shift;
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        return v10 * (double)numbitsa;
      }
    }
  }
  v12 = this->m_pBufferEnd;
  v13 = this->m_nInBufWord;
  v14 = numbits - m_nBitsAvail;
  v15 = this->m_pDataIn;
  if ( v15 == v12 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
LABEL_15:
    this->m_pDataIn = v15 + 1;
    goto LABEL_16;
  }
  if ( v15 <= v12 )
  {
    this->m_nInBufWord = *v15;
    goto LABEL_15;
  }
  this->m_bOverflow = true;
  this->m_nInBufWord = 0;
LABEL_16:
  if ( this->m_bOverflow )
  {
    numbitsb = 0;
  }
  else
  {
    v16 = this->m_nInBufWord;
    v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v14;
    numbitsb = v17 | v13;
    this->m_nInBufWord = v16 >> v14;
  }
  return 360.0 / shift * (double)numbitsb;
}

//------------------------------------------------------------------------------
// Address: 0x1037C7A0
// Name: public: float CBitRead::ReadBitCoord(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBitRead::ReadBitCoord(CBitRead *this)
{
  unsigned int m_nInBufWord; // ecx
  int v3; // esi
  bool v4; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v7; // ecx
  int v8; // ebx
  const unsigned int *v9; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // ecx
  const unsigned int *v12; // ecx
  const unsigned int *v13; // edx
  int m_nBitsAvail; // ecx
  unsigned int v15; // edx
  int v16; // ecx
  unsigned int v17; // esi
  int v18; // edi
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edx
  unsigned int v21; // edx
  const unsigned int *v22; // esi
  unsigned int v23; // edi
  int v24; // edx
  const unsigned int *v25; // ecx
  unsigned int v26; // esi
  unsigned int v27; // ebx
  int v28; // ecx
  unsigned int v29; // edx
  int v30; // ecx
  int v31; // edi
  const unsigned int *v32; // ecx
  const unsigned int *v33; // edx
  unsigned int v34; // edx
  const unsigned int *v35; // esi
  unsigned int v36; // edi
  int v37; // edx
  const unsigned int *v38; // ecx
  unsigned int v39; // esi
  unsigned int v40; // ebx
  float v41; // xmm0_4
  int v43; // [esp+0h] [ebp-14h]
  int fractval; // [esp+4h] [ebp-10h]
  int v45; // [esp+8h] [ebp-Ch]
  int intval; // [esp+Ch] [ebp-8h]
  float value; // [esp+10h] [ebp-4h]

  m_nInBufWord = this->m_nInBufWord;
  v3 = m_nInBufWord & 1;
  v4 = this->m_nBitsAvail-- == 1;
  value = 0.0;
  if ( v4 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  v7 = this->m_nInBufWord;
  v8 = v7 & 1;
  v4 = this->m_nBitsAvail-- == 1;
  intval = v3;
  v45 = v8;
  if ( v4 )
  {
    v9 = this->m_pDataIn;
    v10 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v9 + 1;
    }
    else if ( v9 <= v10 )
    {
      this->m_nInBufWord = *v9;
      this->m_pDataIn = v9 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v7 >> 1;
  }
  fractval = v8;
  if ( v3 == 0 && v8 == 0 )
    return value;
  v11 = this->m_nInBufWord;
  v4 = this->m_nBitsAvail-- == 1;
  v43 = v11 & 1;
  if ( v4 )
  {
    v12 = this->m_pDataIn;
    v13 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v12 == v13 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v12 + 1;
    }
    else if ( v12 <= v13 )
    {
      this->m_nInBufWord = *v12;
      this->m_pDataIn = v12 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v11 >> 1;
  }
  if ( v3 != 0 )
  {
    m_nBitsAvail = this->m_nBitsAvail;
    if ( m_nBitsAvail >= 14 )
    {
      v15 = this->m_nInBufWord;
      v16 = m_nBitsAvail - 14;
      v17 = 0;
      v18 = v15 & 0x3FFF;
      this->m_nBitsAvail = v16;
      if ( v16 != 0 )
      {
        this->m_nInBufWord = v15 >> 14;
LABEL_43:
        intval = v18 + 1;
        goto LABEL_44;
      }
      v19 = this->m_pDataIn;
      v20 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v19 == v20 )
      {
        this->m_nBitsAvail = 1;
        this->m_pDataIn = v19 + 1;
      }
      else
      {
        if ( v19 <= v20 )
        {
          v21 = *v19;
          this->m_pDataIn = v19 + 1;
          this->m_nInBufWord = v21;
          goto LABEL_43;
        }
        this->m_bOverflow = true;
      }
LABEL_42:
      this->m_nInBufWord = v17;
      goto LABEL_43;
    }
    v22 = this->m_pBufferEnd;
    v23 = this->m_nInBufWord;
    v24 = 14 - m_nBitsAvail;
    v25 = this->m_pDataIn;
    if ( v25 == v22 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v22 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_39:
        if ( this->m_bOverflow )
        {
          v18 = 0;
          goto LABEL_43;
        }
        v26 = this->m_nInBufWord;
        v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v24;
        v18 = v27 | v23;
        v8 = v45;
        v17 = v26 >> v24;
        goto LABEL_42;
      }
      this->m_nInBufWord = *v25;
    }
    this->m_pDataIn = v25 + 1;
    goto LABEL_39;
  }
LABEL_44:
  if ( v8 == 0 )
  {
    v31 = fractval;
    goto LABEL_63;
  }
  v28 = this->m_nBitsAvail;
  if ( v28 >= 5 )
  {
    v29 = this->m_nInBufWord;
    v30 = v28 - 5;
    v31 = v29 & 0x1F;
    this->m_nBitsAvail = v30;
    if ( v30 != 0 )
    {
      this->m_nInBufWord = v29 >> 5;
    }
    else
    {
      v32 = this->m_pDataIn;
      v33 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v32 == v33 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_pDataIn = v32 + 1;
      }
      else if ( v32 <= v33 )
      {
        v34 = *v32;
        this->m_pDataIn = v32 + 1;
        this->m_nInBufWord = v34;
      }
      else
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
      }
    }
    goto LABEL_63;
  }
  v35 = this->m_pBufferEnd;
  v36 = this->m_nInBufWord;
  v37 = 5 - v28;
  v38 = this->m_pDataIn;
  if ( v38 == v35 )
  {
    this->m_nBitsAvail = 1;
    this->m_nInBufWord = 0;
    this->m_bOverflow = true;
  }
  else
  {
    if ( v38 > v35 )
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
      goto LABEL_59;
    }
    this->m_nInBufWord = *v38;
  }
  this->m_pDataIn = v38 + 1;
LABEL_59:
  if ( this->m_bOverflow )
  {
    v31 = 0;
  }
  else
  {
    v39 = this->m_nInBufWord;
    v40 = (v39 & CBitBuffer::s_nMaskTable[v37]) << this->m_nBitsAvail;
    this->m_nBitsAvail = 32 - v37;
    v31 = v40 | v36;
    this->m_nInBufWord = v39 >> v37;
  }
LABEL_63:
  v41 = (float)((float)v31 * 0.03125) + (double)intval;
  value = v41;
  if ( v43 != 0 )
    LODWORD(value) = LODWORD(v41) ^ _mask__NegFloat_;
  return value;
}

//------------------------------------------------------------------------------
// Address: 0x1037CAE0
// Name: public: void CBitRead::ReadBitVec3Coord(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::ReadBitVec3Coord(CBitRead *this, Vector *fa)
{
  unsigned int m_nInBufWord; // eax
  bool v5; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v8; // eax
  const unsigned int *v9; // eax
  const unsigned int *v10; // ecx
  unsigned int v11; // eax
  int v12; // edi
  const unsigned int *v13; // eax
  const unsigned int *v14; // ecx
  int v15; // [esp+0h] [ebp-4h]
  Vector *faa; // [esp+Ch] [ebp+8h]

  fa->x = 0.0;
  fa->y = 0.0;
  fa->z = 0.0;
  m_nInBufWord = this->m_nInBufWord;
  v5 = this->m_nBitsAvail-- == 1;
  faa = (Vector *)(m_nInBufWord & 1);
  if ( v5 )
  {
    m_pDataIn = this->m_pDataIn;
    m_pBufferEnd = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      this->m_nInBufWord = *m_pDataIn;
      this->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = m_nInBufWord >> 1;
  }
  v8 = this->m_nInBufWord;
  v5 = this->m_nBitsAvail-- == 1;
  v15 = v8 & 1;
  if ( v5 )
  {
    v9 = this->m_pDataIn;
    v10 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v9 + 1;
    }
    else if ( v9 <= v10 )
    {
      this->m_nInBufWord = *v9;
      this->m_pDataIn = v9 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v8 >> 1;
  }
  v11 = this->m_nInBufWord;
  v12 = v11 & 1;
  v5 = this->m_nBitsAvail-- == 1;
  if ( v5 )
  {
    v13 = this->m_pDataIn;
    v14 = this->m_pBufferEnd;
    this->m_nBitsAvail = 32;
    if ( v13 == v14 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_pDataIn = v13 + 1;
    }
    else if ( v13 <= v14 )
    {
      this->m_nInBufWord = *v13;
      this->m_pDataIn = v13 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
  }
  else
  {
    this->m_nInBufWord = v11 >> 1;
  }
  if ( faa != nullptr )
    fa->x = CBitRead::ReadBitCoord(this);
  if ( v15 != 0 )
    fa->y = CBitRead::ReadBitCoord(this);
  if ( v12 != 0 )
    fa->z = CBitRead::ReadBitCoord(this);
}

} // namespace server

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1003BA30
// Name: public: void CBitRead::ReadBits(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::ReadBits(CBitRead *this, char *pOutData, int nBits)
{
  int v4; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v7; // ecx
  char v8; // si
  char v9; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v12; // edx
  const unsigned int *v13; // esi
  unsigned int v14; // edi
  int v15; // edx
  const unsigned int *v16; // ecx
  unsigned int v17; // esi
  unsigned int v18; // ebx
  int v19; // ebx
  int v20; // ecx
  unsigned int v21; // esi
  int v22; // ecx
  unsigned int v23; // ecx
  const unsigned int *v24; // ecx
  const unsigned int *v25; // edx
  unsigned int v26; // edx
  const unsigned int *v27; // esi
  unsigned int v28; // edi
  int v29; // edx
  const unsigned int *v30; // ecx
  unsigned int v31; // esi
  unsigned int v32; // ebx
  int v33; // edi
  unsigned int *v34; // edx
  int v35; // ebx
  int v36; // ecx
  unsigned int v37; // edx
  int v38; // ecx
  char v39; // si
  char v40; // cl
  const unsigned int *v41; // ecx
  const unsigned int *v42; // edx
  unsigned int v43; // edx
  const unsigned int *v44; // esi
  unsigned int v45; // edi
  int v46; // edx
  const unsigned int *v47; // ecx
  unsigned int v48; // esi
  unsigned int v49; // ebx
  char v50; // di
  int v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // esi
  int v54; // ecx
  const unsigned int *v55; // ecx
  const unsigned int *v56; // edx
  _BYTE *v57; // edx
  const unsigned int *v58; // edx
  unsigned int v59; // edi
  int v60; // esi
  const unsigned int *v61; // ecx
  unsigned int v62; // edx
  unsigned int v63; // ebx
  int nBitsLeft; // [esp+18h] [ebp+8h]
  int nBitsa; // [esp+1Ch] [ebp+Ch]
  int nBitsb; // [esp+1Ch] [ebp+Ch]

  v4 = nBits;
  nBitsLeft = nBits;
  if ( ((unsigned __int8)pOutData & 3) != 0 )
  {
    while ( 1 )
    {
      if ( v4 < 8 )
        goto LABEL_23;
      m_nBitsAvail = this->m_nBitsAvail;
      if ( m_nBitsAvail < 8 )
        break;
      m_nInBufWord = this->m_nInBufWord;
      v7 = m_nBitsAvail - 8;
      v8 = m_nInBufWord;
      this->m_nBitsAvail = v7;
      if ( v7 != 0 )
      {
        this->m_nInBufWord = m_nInBufWord >> 8;
        v9 = m_nInBufWord;
      }
      else
      {
        m_pDataIn = this->m_pDataIn;
        m_pBufferEnd = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          v9 = v8;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            v12 = *m_pDataIn;
            this->m_pDataIn = m_pDataIn + 1;
            this->m_nInBufWord = v12;
          }
          else
          {
            this->m_bOverflow = true;
            this->m_nInBufWord = 0;
          }
          v9 = v8;
        }
      }
LABEL_22:
      *pOutData = v9;
      v4 -= 8;
      ++pOutData;
      nBitsLeft = v4;
      if ( ((unsigned __int8)pOutData & 3) == 0 )
        goto LABEL_23;
    }
    v13 = this->m_pBufferEnd;
    v14 = this->m_nInBufWord;
    v15 = 8 - m_nBitsAvail;
    v16 = this->m_pDataIn;
    if ( v16 == v13 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v16 > v13 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_18:
        if ( this->m_bOverflow )
        {
          v9 = 0;
        }
        else
        {
          v17 = this->m_nInBufWord;
          v18 = (v17 & CBitBuffer::s_nMaskTable[v15]) << this->m_nBitsAvail;
          this->m_nBitsAvail = 32 - v15;
          v9 = v18 | v14;
          this->m_nInBufWord = v17 >> v15;
        }
        v4 = nBitsLeft;
        goto LABEL_22;
      }
      this->m_nInBufWord = *v16;
    }
    this->m_pDataIn = v16 + 1;
    goto LABEL_18;
  }
LABEL_23:
  if ( v4 < 32 )
    goto LABEL_45;
  v19 = (unsigned int)v4 >> 5;
  nBitsa = (unsigned int)v4 >> 5;
  nBitsLeft = -32 * ((unsigned int)v4 >> 5) + v4;
  do
  {
    v20 = this->m_nBitsAvail;
    if ( v20 < 32 )
    {
      v27 = this->m_pBufferEnd;
      v28 = this->m_nInBufWord;
      v29 = 32 - v20;
      v30 = this->m_pDataIn;
      if ( v30 == v27 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v30 > v27 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_40;
        }
        this->m_nInBufWord = *v30;
      }
      this->m_pDataIn = v30 + 1;
LABEL_40:
      if ( this->m_bOverflow )
      {
        v23 = 0;
      }
      else
      {
        v31 = this->m_nInBufWord;
        v32 = (v31 & CBitBuffer::s_nMaskTable[v29]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v29;
        v33 = v32 | v28;
        v19 = nBitsa;
        v23 = v33;
        this->m_nInBufWord = v31 >> v29;
      }
      goto LABEL_43;
    }
    v21 = this->m_nInBufWord;
    v22 = v20 - 32;
    this->m_nBitsAvail = v22;
    if ( v22 != 0 )
    {
      this->m_nInBufWord = 0;
      v23 = v21;
    }
    else
    {
      v24 = this->m_pDataIn;
      v25 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v24 == v25 )
      {
        this->m_pDataIn = v24 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v23 = v21;
      }
      else
      {
        if ( v24 <= v25 )
        {
          v26 = *v24;
          this->m_pDataIn = v24 + 1;
          this->m_nInBufWord = v26;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v23 = v21;
      }
    }
LABEL_43:
    v34 = (unsigned int *)pOutData;
    pOutData += 4;
    --v19;
    *v34 = v23;
    nBitsa = v19;
  }
  while ( v19 != 0 );
  v4 = nBitsLeft;
LABEL_45:
  if ( v4 < 8 )
    goto LABEL_67;
  v35 = (unsigned int)v4 >> 3;
  nBitsb = (unsigned int)v4 >> 3;
  nBitsLeft = v4 - 8 * ((unsigned int)v4 >> 3);
  while ( 2 )
  {
    v36 = this->m_nBitsAvail;
    if ( v36 < 8 )
    {
      v44 = this->m_pBufferEnd;
      v45 = this->m_nInBufWord;
      v46 = 8 - v36;
      v47 = this->m_pDataIn;
      if ( v47 == v44 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v47 > v44 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_62;
        }
        this->m_nInBufWord = *v47;
      }
      this->m_pDataIn = v47 + 1;
LABEL_62:
      if ( this->m_bOverflow )
      {
        v40 = 0;
      }
      else
      {
        v48 = this->m_nInBufWord;
        v49 = (v48 & CBitBuffer::s_nMaskTable[v46]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v46;
        v50 = v49 | v45;
        v35 = nBitsb;
        v40 = v50;
        this->m_nInBufWord = v48 >> v46;
      }
      goto LABEL_65;
    }
    v37 = this->m_nInBufWord;
    v38 = v36 - 8;
    v39 = v37;
    this->m_nBitsAvail = v38;
    if ( v38 != 0 )
    {
      this->m_nInBufWord = v37 >> 8;
      v40 = v37;
    }
    else
    {
      v41 = this->m_pDataIn;
      v42 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v41 == v42 )
      {
        this->m_pDataIn = v41 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v40 = v39;
      }
      else
      {
        if ( v41 <= v42 )
        {
          v43 = *v41;
          this->m_pDataIn = v41 + 1;
          this->m_nInBufWord = v43;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v40 = v39;
      }
    }
LABEL_65:
    *pOutData = v40;
    --v35;
    ++pOutData;
    nBitsb = v35;
    if ( v35 != 0 )
      continue;
    break;
  }
  v4 = nBitsLeft;
LABEL_67:
  if ( v4 != 0 )
  {
    v51 = this->m_nBitsAvail;
    if ( v51 >= v4 )
    {
      v52 = this->m_nInBufWord;
      v53 = v52 & CBitBuffer::s_nMaskTable[v4];
      v54 = v51 - v4;
      this->m_nBitsAvail = v54;
      if ( v54 != 0 )
      {
        this->m_nInBufWord = v52 >> v4;
        *pOutData = v53;
      }
      else
      {
        v55 = this->m_pDataIn;
        v56 = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( v55 == v56 )
        {
          this->m_nInBufWord = 0;
          this->m_nBitsAvail = 1;
          this->m_pDataIn = v55 + 1;
          *pOutData = v53;
        }
        else
        {
          if ( v55 <= v56 )
          {
            this->m_nInBufWord = *v55;
            v57 = pOutData;
            this->m_pDataIn = v55 + 1;
          }
          else
          {
            v57 = pOutData;
            this->m_nInBufWord = 0;
            this->m_bOverflow = true;
          }
          *v57 = v53;
        }
      }
      return;
    }
    v58 = this->m_pBufferEnd;
    v59 = this->m_nInBufWord;
    v60 = nBitsLeft - v51;
    v61 = this->m_pDataIn;
    if ( v61 == v58 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
      goto LABEL_82;
    }
    if ( v61 <= v58 )
    {
      this->m_nInBufWord = *v61;
LABEL_82:
      this->m_pDataIn = v61 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
    if ( this->m_bOverflow )
    {
      *pOutData = 0;
    }
    else
    {
      v62 = this->m_nInBufWord;
      v63 = (v62 & CBitBuffer::s_nMaskTable[v60]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v60;
      this->m_nInBufWord = v62 >> v60;
      *pOutData = v63 | v59;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BEA0
// Name: public: bool CBitRead::ReadBytes(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadBytes(CBitRead *this, char *pOut, int nBytes)
{
  CBitRead::ReadBits(this, pOutData: pOut, nBits: 8 * nBytes);
  return !this->m_bOverflow;
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x100107B0
// Name: public: void CBitRead::ReadBits(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitRead::ReadBits(CBitRead *this, char *pOutData, int nBits)
{
  int v4; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v7; // ecx
  char v8; // si
  char v9; // cl
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v12; // edx
  const unsigned int *v13; // esi
  unsigned int v14; // edi
  int v15; // edx
  const unsigned int *v16; // ecx
  unsigned int v17; // esi
  unsigned int v18; // ebx
  int v19; // ebx
  int v20; // ecx
  unsigned int v21; // esi
  int v22; // ecx
  unsigned int v23; // ecx
  const unsigned int *v24; // ecx
  const unsigned int *v25; // edx
  unsigned int v26; // edx
  const unsigned int *v27; // esi
  unsigned int v28; // edi
  int v29; // edx
  const unsigned int *v30; // ecx
  unsigned int v31; // esi
  unsigned int v32; // ebx
  int v33; // edi
  unsigned int *v34; // edx
  int v35; // ebx
  int v36; // ecx
  unsigned int v37; // edx
  int v38; // ecx
  char v39; // si
  char v40; // cl
  const unsigned int *v41; // ecx
  const unsigned int *v42; // edx
  unsigned int v43; // edx
  const unsigned int *v44; // esi
  unsigned int v45; // edi
  int v46; // edx
  const unsigned int *v47; // ecx
  unsigned int v48; // esi
  unsigned int v49; // ebx
  char v50; // di
  int v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // esi
  int v54; // ecx
  const unsigned int *v55; // ecx
  const unsigned int *v56; // edx
  _BYTE *v57; // edx
  const unsigned int *v58; // edx
  unsigned int v59; // edi
  int v60; // esi
  const unsigned int *v61; // ecx
  unsigned int v62; // edx
  unsigned int v63; // ebx
  int nBitsLeft; // [esp+18h] [ebp+8h]
  int nBitsa; // [esp+1Ch] [ebp+Ch]
  int nBitsb; // [esp+1Ch] [ebp+Ch]

  v4 = nBits;
  nBitsLeft = nBits;
  if ( ((unsigned __int8)pOutData & 3) != 0 )
  {
    while ( 1 )
    {
      if ( v4 < 8 )
        goto LABEL_23;
      m_nBitsAvail = this->m_nBitsAvail;
      if ( m_nBitsAvail < 8 )
        break;
      m_nInBufWord = this->m_nInBufWord;
      v7 = m_nBitsAvail - 8;
      v8 = m_nInBufWord;
      this->m_nBitsAvail = v7;
      if ( v7 != 0 )
      {
        this->m_nInBufWord = m_nInBufWord >> 8;
        v9 = m_nInBufWord;
      }
      else
      {
        m_pDataIn = this->m_pDataIn;
        m_pBufferEnd = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          this->m_pDataIn = m_pDataIn + 1;
          this->m_nBitsAvail = 1;
          this->m_nInBufWord = 0;
          v9 = v8;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            v12 = *m_pDataIn;
            this->m_pDataIn = m_pDataIn + 1;
            this->m_nInBufWord = v12;
          }
          else
          {
            this->m_bOverflow = true;
            this->m_nInBufWord = 0;
          }
          v9 = v8;
        }
      }
LABEL_22:
      *pOutData = v9;
      v4 -= 8;
      ++pOutData;
      nBitsLeft = v4;
      if ( ((unsigned __int8)pOutData & 3) == 0 )
        goto LABEL_23;
    }
    v13 = this->m_pBufferEnd;
    v14 = this->m_nInBufWord;
    v15 = 8 - m_nBitsAvail;
    v16 = this->m_pDataIn;
    if ( v16 == v13 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
    }
    else
    {
      if ( v16 > v13 )
      {
        this->m_bOverflow = true;
        this->m_nInBufWord = 0;
LABEL_18:
        if ( this->m_bOverflow )
        {
          v9 = 0;
        }
        else
        {
          v17 = this->m_nInBufWord;
          v18 = (v17 & CBitBuffer::s_nMaskTable[v15]) << this->m_nBitsAvail;
          this->m_nBitsAvail = 32 - v15;
          v9 = v18 | v14;
          this->m_nInBufWord = v17 >> v15;
        }
        v4 = nBitsLeft;
        goto LABEL_22;
      }
      this->m_nInBufWord = *v16;
    }
    this->m_pDataIn = v16 + 1;
    goto LABEL_18;
  }
LABEL_23:
  if ( v4 < 32 )
    goto LABEL_45;
  v19 = (unsigned int)v4 >> 5;
  nBitsa = (unsigned int)v4 >> 5;
  nBitsLeft = -32 * ((unsigned int)v4 >> 5) + v4;
  do
  {
    v20 = this->m_nBitsAvail;
    if ( v20 < 32 )
    {
      v27 = this->m_pBufferEnd;
      v28 = this->m_nInBufWord;
      v29 = 32 - v20;
      v30 = this->m_pDataIn;
      if ( v30 == v27 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v30 > v27 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_40;
        }
        this->m_nInBufWord = *v30;
      }
      this->m_pDataIn = v30 + 1;
LABEL_40:
      if ( this->m_bOverflow )
      {
        v23 = 0;
      }
      else
      {
        v31 = this->m_nInBufWord;
        v32 = (v31 & CBitBuffer::s_nMaskTable[v29]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v29;
        v33 = v32 | v28;
        v19 = nBitsa;
        v23 = v33;
        this->m_nInBufWord = v31 >> v29;
      }
      goto LABEL_43;
    }
    v21 = this->m_nInBufWord;
    v22 = v20 - 32;
    this->m_nBitsAvail = v22;
    if ( v22 != 0 )
    {
      this->m_nInBufWord = 0;
      v23 = v21;
    }
    else
    {
      v24 = this->m_pDataIn;
      v25 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v24 == v25 )
      {
        this->m_pDataIn = v24 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v23 = v21;
      }
      else
      {
        if ( v24 <= v25 )
        {
          v26 = *v24;
          this->m_pDataIn = v24 + 1;
          this->m_nInBufWord = v26;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v23 = v21;
      }
    }
LABEL_43:
    v34 = (unsigned int *)pOutData;
    pOutData += 4;
    --v19;
    *v34 = v23;
    nBitsa = v19;
  }
  while ( v19 != 0 );
  v4 = nBitsLeft;
LABEL_45:
  if ( v4 < 8 )
    goto LABEL_67;
  v35 = (unsigned int)v4 >> 3;
  nBitsb = (unsigned int)v4 >> 3;
  nBitsLeft = v4 - 8 * ((unsigned int)v4 >> 3);
  while ( 2 )
  {
    v36 = this->m_nBitsAvail;
    if ( v36 < 8 )
    {
      v44 = this->m_pBufferEnd;
      v45 = this->m_nInBufWord;
      v46 = 8 - v36;
      v47 = this->m_pDataIn;
      if ( v47 == v44 )
      {
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        this->m_bOverflow = true;
      }
      else
      {
        if ( v47 > v44 )
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
          goto LABEL_62;
        }
        this->m_nInBufWord = *v47;
      }
      this->m_pDataIn = v47 + 1;
LABEL_62:
      if ( this->m_bOverflow )
      {
        v40 = 0;
      }
      else
      {
        v48 = this->m_nInBufWord;
        v49 = (v48 & CBitBuffer::s_nMaskTable[v46]) << this->m_nBitsAvail;
        this->m_nBitsAvail = 32 - v46;
        v50 = v49 | v45;
        v35 = nBitsb;
        v40 = v50;
        this->m_nInBufWord = v48 >> v46;
      }
      goto LABEL_65;
    }
    v37 = this->m_nInBufWord;
    v38 = v36 - 8;
    v39 = v37;
    this->m_nBitsAvail = v38;
    if ( v38 != 0 )
    {
      this->m_nInBufWord = v37 >> 8;
      v40 = v37;
    }
    else
    {
      v41 = this->m_pDataIn;
      v42 = this->m_pBufferEnd;
      this->m_nBitsAvail = 32;
      if ( v41 == v42 )
      {
        this->m_pDataIn = v41 + 1;
        this->m_nBitsAvail = 1;
        this->m_nInBufWord = 0;
        v40 = v39;
      }
      else
      {
        if ( v41 <= v42 )
        {
          v43 = *v41;
          this->m_pDataIn = v41 + 1;
          this->m_nInBufWord = v43;
        }
        else
        {
          this->m_bOverflow = true;
          this->m_nInBufWord = 0;
        }
        v40 = v39;
      }
    }
LABEL_65:
    *pOutData = v40;
    --v35;
    ++pOutData;
    nBitsb = v35;
    if ( v35 != 0 )
      continue;
    break;
  }
  v4 = nBitsLeft;
LABEL_67:
  if ( v4 != 0 )
  {
    v51 = this->m_nBitsAvail;
    if ( v51 >= v4 )
    {
      v52 = this->m_nInBufWord;
      v53 = v52 & CBitBuffer::s_nMaskTable[v4];
      v54 = v51 - v4;
      this->m_nBitsAvail = v54;
      if ( v54 != 0 )
      {
        this->m_nInBufWord = v52 >> v4;
        *pOutData = v53;
      }
      else
      {
        v55 = this->m_pDataIn;
        v56 = this->m_pBufferEnd;
        this->m_nBitsAvail = 32;
        if ( v55 == v56 )
        {
          this->m_nInBufWord = 0;
          this->m_nBitsAvail = 1;
          this->m_pDataIn = v55 + 1;
          *pOutData = v53;
        }
        else
        {
          if ( v55 <= v56 )
          {
            this->m_nInBufWord = *v55;
            v57 = pOutData;
            this->m_pDataIn = v55 + 1;
          }
          else
          {
            v57 = pOutData;
            this->m_nInBufWord = 0;
            this->m_bOverflow = true;
          }
          *v57 = v53;
        }
      }
      return;
    }
    v58 = this->m_pBufferEnd;
    v59 = this->m_nInBufWord;
    v60 = nBitsLeft - v51;
    v61 = this->m_pDataIn;
    if ( v61 == v58 )
    {
      this->m_nBitsAvail = 1;
      this->m_nInBufWord = 0;
      this->m_bOverflow = true;
      goto LABEL_82;
    }
    if ( v61 <= v58 )
    {
      this->m_nInBufWord = *v61;
LABEL_82:
      this->m_pDataIn = v61 + 1;
    }
    else
    {
      this->m_bOverflow = true;
      this->m_nInBufWord = 0;
    }
    if ( this->m_bOverflow )
    {
      *pOutData = 0;
    }
    else
    {
      v62 = this->m_nInBufWord;
      v63 = (v62 & CBitBuffer::s_nMaskTable[v60]) << this->m_nBitsAvail;
      this->m_nBitsAvail = 32 - v60;
      this->m_nInBufWord = v62 >> v60;
      *pOutData = v63 | v59;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010C20
// Name: public: bool CBitRead::ReadBytes(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBitRead::ReadBytes(CBitRead *this, char *pOut, int nBytes)
{
  CBitRead::ReadBits(this, pOutData: pOut, nBits: 8 * nBytes);
  return !this->m_bOverflow;
}

} // namespace matchmaking_ds
