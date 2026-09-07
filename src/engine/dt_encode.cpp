// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/dt_encode.cpp
// Functions: 64
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10168FC0
// Name: EncodeSpecialFloat
// Source: json
//------------------------------------------------------------------------------
char __fastcall EncodeSpecialFloat(bf_write *pOut, const SendProp *pProp, float fVal)
{
  int m_Flags; // eax

  m_Flags = pProp->m_Flags;
  if ( (m_Flags & 2) != 0 )
  {
    bf_write::WriteBitCoord(this: pOut, f: fVal);
    return 1;
  }
  else if ( (m_Flags & 0x1000) != 0 )
  {
    bf_write::WriteBitCoordMP(this: pOut, f: fVal, coordType: kCW_None);
    return 1;
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    bf_write::WriteBitCoordMP(this: pOut, f: fVal, coordType: kCW_LowPrecision);
    return 1;
  }
  else if ( (m_Flags & 0x4000) != 0 )
  {
    bf_write::WriteBitCoordMP(this: pOut, f: fVal, coordType: kCW_Integral);
    return 1;
  }
  else if ( (m_Flags & 4) != 0 )
  {
    bf_write::WriteBitFloat(this: pOut, val: LODWORD(fVal));
    return 1;
  }
  else if ( (m_Flags & 0x20) != 0 )
  {
    bf_write::WriteBitNormal(this: pOut, f: fVal);
    return 1;
  }
  else if ( (m_Flags & 0x8000) != 0 )
  {
    bf_write::WriteBitCellCoord(this: pOut, f: fVal, bits: pProp->m_nBits, coordType: kCW_None);
    return 1;
  }
  else if ( (m_Flags & 0x10000) != 0 )
  {
    bf_write::WriteBitCellCoord(this: pOut, f: fVal, bits: pProp->m_nBits, coordType: kCW_LowPrecision);
    return 1;
  }
  else if ( (m_Flags & 0x20000) != 0 )
  {
    bf_write::WriteBitCellCoord(this: pOut, f: fVal, bits: pProp->m_nBits, coordType: kCW_Integral);
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101690B0
// Name: EncodeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall EncodeFloat(const SendProp *pProp@<esi>, float fVal, bf_write *pOut, int objectID)
{
  float m_fLowValue; // xmm1_4
  unsigned int v5; // edi
  const char *v6; // eax
  const char *ObjectClassName; // eax
  char *v8; // [esp+8h] [ebp-18h]
  char *m_pVarName; // [esp+8h] [ebp-18h]

  if ( EncodeSpecialFloat(pOut, pProp, fVal) == 0 )
  {
    m_fLowValue = pProp->m_fLowValue;
    if ( m_fLowValue <= fVal )
    {
      if ( fVal <= pProp->m_fHighValue )
      {
        v5 = (__int64)(float)((float)(fVal - m_fLowValue) * pProp->m_fHighLowMul);
      }
      else
      {
        v5 = (1 << pProp->m_nBits) - 1;
        if ( (pProp->m_Flags & 8) == 0 )
        {
          m_pVarName = pProp->m_pVarName;
          ObjectClassName = GetObjectClassName(objectID);
          DataTable_Warning(
            pInMessage: "%s: Out-of-range value (%f) in SendPropFloat '%s', clamping.\n",
            ObjectClassName,
            fVal,
            m_pVarName);
        }
      }
    }
    else
    {
      v5 = 0;
      if ( (pProp->m_Flags & 0x10) == 0 )
      {
        v8 = pProp->m_pVarName;
        v6 = GetObjectClassName(objectID);
        DataTable_Warning(
          pInMessage: "(class %s): Out-of-range value (%f) in SendPropFloat '%s', clamping.\n",
          v6,
          fVal,
          v8);
      }
    }
    bf_write::WriteUBitLong(this: pOut, curData: v5, numbits: pProp->m_nBits, bCheckRange: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169180
// Name: DecodeSpecialFloat
// Source: json
//------------------------------------------------------------------------------
char __usercall DecodeSpecialFloat@<al>(const SendProp *pProp@<edx>, bf_read *pIn@<eax>, float *fVal)
{
  int m_Flags; // ecx
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v9; // ecx
  int v10; // edx
  const unsigned int *v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // esi
  unsigned int v14; // ebx
  double BitCellCoord; // st7
  int v16; // [esp+0h] [ebp-4h]

  m_Flags = pProp->m_Flags;
  if ( (m_Flags & 2) != 0 )
  {
    *fVal = CBitRead::ReadBitCoord(this: pIn);
    return 1;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    *fVal = CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_None);
    return 1;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    *fVal = CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_LowPrecision);
    return 1;
  }
  if ( (m_Flags & 0x4000) != 0 )
  {
    *fVal = CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_Integral);
    return 1;
  }
  if ( (m_Flags & 4) != 0 )
  {
    m_nBitsAvail = pIn->m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = pIn->m_nInBufWord;
      pIn->m_nBitsAvail = m_nBitsAvail - 32;
      if ( m_nBitsAvail == 32 )
      {
        m_pDataIn = pIn->m_pDataIn;
        m_pBufferEnd = pIn->m_pBufferEnd;
        pIn->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          pIn->m_nBitsAvail = 1;
          pIn->m_nInBufWord = 0;
          pIn->m_pDataIn = m_pDataIn + 1;
          v16 = m_nInBufWord;
LABEL_27:
          *(_DWORD *)fVal = v16;
          return 1;
        }
        if ( m_pDataIn <= m_pBufferEnd )
        {
          pIn->m_nInBufWord = *m_pDataIn;
          pIn->m_pDataIn = m_pDataIn + 1;
          v16 = m_nInBufWord;
          goto LABEL_27;
        }
        pIn->m_bOverflow = true;
      }
      pIn->m_nInBufWord = 0;
      v16 = m_nInBufWord;
      goto LABEL_27;
    }
    v9 = pIn->m_pDataIn;
    v10 = 32 - m_nBitsAvail;
    v11 = pIn->m_pBufferEnd;
    v12 = pIn->m_nInBufWord;
    if ( v9 == v11 )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_bOverflow = true;
    }
    else
    {
      if ( v9 > v11 )
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
        goto LABEL_24;
      }
      pIn->m_nInBufWord = *v9;
    }
    pIn->m_pDataIn = v9 + 1;
LABEL_24:
    if ( pIn->m_bOverflow )
    {
      v16 = 0;
    }
    else
    {
      v13 = pIn->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v10]) << pIn->m_nBitsAvail;
      pIn->m_nBitsAvail = 32 - v10;
      v16 = v14 | v12;
      pIn->m_nInBufWord = v13 >> v10;
    }
    goto LABEL_27;
  }
  if ( (m_Flags & 0x20) != 0 )
  {
    *fVal = CBitRead::ReadBitNormal(this: pIn);
    return 1;
  }
  if ( (m_Flags & 0x8000) != 0 )
  {
    BitCellCoord = CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_None);
LABEL_32:
    *fVal = BitCellCoord;
    return 1;
  }
  if ( (m_Flags & 0x10000) != 0 )
  {
    BitCellCoord = CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_LowPrecision);
    goto LABEL_32;
  }
  if ( (m_Flags & 0x20000) != 0 )
  {
    BitCellCoord = CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_Integral);
    goto LABEL_32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10169340
// Name: DecodeFloat
// Source: json
//------------------------------------------------------------------------------
double __usercall DecodeFloat@<st0>(bf_read *pIn@<esi>, const SendProp *pProp)
{
  const SendProp *v2; // ebx
  int m_nBits; // eax
  int m_nBitsAvail; // ecx
  unsigned int v6; // edx
  unsigned int v7; // edi
  int v8; // ecx
  const unsigned int *v9; // eax
  const unsigned int *v10; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v13; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  double m_fLowValue; // st7
  int fVal; // [esp+0h] [ebp-4h] BYREF

  v2 = pProp;
  *(float *)&fVal = 0.0;
  if ( DecodeSpecialFloat(pProp, pIn, (float *)&fVal) != 0 )
    return *(float *)&fVal;
  m_nBits = pProp->m_nBits;
  m_nBitsAvail = pIn->m_nBitsAvail;
  if ( m_nBitsAvail < m_nBits )
  {
    m_pBufferEnd = pIn->m_pBufferEnd;
    m_nInBufWord = pIn->m_nInBufWord;
    v13 = m_nBits - m_nBitsAvail;
    m_pDataIn = pIn->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
LABEL_17:
        if ( pIn->m_bOverflow )
        {
          v7 = 0;
        }
        else
        {
          v15 = pIn->m_nInBufWord;
          v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << pIn->m_nBitsAvail;
          pIn->m_nBitsAvail = 32 - v13;
          v7 = v16 | m_nInBufWord;
          pIn->m_nInBufWord = v15 >> v13;
        }
        v2 = pProp;
        goto LABEL_21;
      }
      pIn->m_nInBufWord = *m_pDataIn;
    }
    pIn->m_pDataIn = m_pDataIn + 1;
    goto LABEL_17;
  }
  v6 = pIn->m_nInBufWord;
  v7 = v6 & CBitBuffer::s_nMaskTable[m_nBits];
  v8 = m_nBitsAvail - m_nBits;
  pIn->m_nBitsAvail = v8;
  if ( v8 != 0 )
  {
    pIn->m_nInBufWord = v6 >> m_nBits;
  }
  else
  {
    v9 = pIn->m_pDataIn;
    v10 = pIn->m_pBufferEnd;
    pIn->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_pDataIn = v9 + 1;
    }
    else if ( v9 <= v10 )
    {
      pIn->m_nInBufWord = *v9;
      pIn->m_pDataIn = v9 + 1;
    }
    else
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
    }
  }
LABEL_21:
  m_fLowValue = v2->m_fLowValue;
  fVal = v7;
  fVal = (1 << v2->m_nBits) - 1;
  return m_fLowValue + (double)v7 / (double)fVal * (v2->m_fHighValue - m_fLowValue);
}

//------------------------------------------------------------------------------
// Address: 0x10169480
// Name: DecodeVector
// Source: json
//------------------------------------------------------------------------------
void __usercall DecodeVector(const SendProp *pProp@<ecx>, bf_read *pIn@<eax>, float *v)
{
  unsigned int m_nInBufWord; // eax
  int v7; // edx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  float v0v0v1v1; // [esp+14h] [ebp+8h]

  *v = DecodeFloat(pIn, pProp);
  v[1] = DecodeFloat(pIn, pProp);
  if ( (pProp->m_Flags & 0x20) != 0 )
  {
    m_nInBufWord = pIn->m_nInBufWord;
    v7 = m_nInBufWord & 1;
    if ( pIn->m_nBitsAvail-- == 1 )
    {
      m_pDataIn = pIn->m_pDataIn;
      pIn->m_nBitsAvail = 32;
      m_pBufferEnd = pIn->m_pBufferEnd;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pIn->m_nBitsAvail = 1;
        pIn->m_nInBufWord = 0;
        pIn->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        pIn->m_nInBufWord = *m_pDataIn;
        pIn->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
      }
    }
    else
    {
      pIn->m_nInBufWord = m_nInBufWord >> 1;
    }
    v0v0v1v1 = (float)(*v * *v) + (float)(v[1] * v[1]);
    if ( v0v0v1v1 >= 1.0 )
      v[2] = 0.0;
    else
      v[2] = sqrt(1.0 - v0v0v1v1);
    if ( v7 != 0 )
      v[2] = v[2] * -1.0;
  }
  else
  {
    v[2] = DecodeFloat(pIn, pProp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169560
// Name: void Int_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int_Encode(const unsigned __int8 *pStruct, DVariant *pVar, const SendProp *pProp, bf_write *pOut)
{
  int m_Int; // ecx

  m_Int = pVar->m_Int;
  if ( (pProp->m_Flags & 1) != 0 )
    bf_write::WriteUBitLong(this: pOut, curData: m_Int, numbits: pProp->m_nBits, bCheckRange: true);
  else
    bf_write::WriteSBitLong(this: pOut, data: m_Int, numbits: pProp->m_nBits);
}

//------------------------------------------------------------------------------
// Address: 0x101695A0
// Name: void Int_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int_Decode(DecodeInfo *pInfo)
{
  const SendProp *m_pProp; // eax
  int v2; // edx
  bf_read *v3; // eax
  int v4; // ecx
  unsigned int v5; // esi
  unsigned int v6; // edi
  int v7; // ecx
  DecodeInfo *v8; // ecx
  const unsigned int *v9; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // edx
  const unsigned int *v12; // esi
  unsigned int v13; // edi
  int v14; // edx
  const unsigned int *v15; // ecx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  int m_nBits; // edi
  bf_read *m_pIn; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  unsigned int v22; // esi
  int v23; // ecx
  int v24; // eax
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v27; // edx
  const unsigned int *v28; // esi
  int v29; // edx
  const unsigned int *v30; // ecx
  unsigned int v31; // esi
  unsigned int v32; // ebx
  unsigned int v33; // [esp+Ch] [ebp-8h]

  m_pProp = pInfo->m_pProp;
  if ( (m_pProp->m_Flags & 1) == 0 )
  {
    m_nBits = m_pProp->m_nBits;
    m_pIn = pInfo->m_pIn;
    m_nBitsAvail = m_pIn->m_nBitsAvail;
    m_nInBufWord = m_pIn->m_nInBufWord;
    if ( m_nBitsAvail >= m_nBits )
    {
      v22 = m_nInBufWord & CBitBuffer::s_nMaskTable[m_nBits];
      v23 = m_nBitsAvail - m_nBits;
      m_pIn->m_nBitsAvail = v23;
      if ( v23 != 0 )
      {
        m_pIn->m_nInBufWord = m_nInBufWord >> m_nBits;
        v24 = v22;
      }
      else
      {
        m_pDataIn = m_pIn->m_pDataIn;
        m_pBufferEnd = m_pIn->m_pBufferEnd;
        m_pIn->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          m_pIn->m_nBitsAvail = 1;
          m_pIn->m_nInBufWord = 0;
          m_pIn->m_pDataIn = m_pDataIn + 1;
          v24 = v22;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            v27 = *m_pDataIn;
            m_pIn->m_pDataIn = m_pDataIn + 1;
            m_pIn->m_nInBufWord = v27;
          }
          else
          {
            m_pIn->m_bOverflow = true;
            m_pIn->m_nInBufWord = 0;
          }
          v24 = v22;
        }
      }
      goto LABEL_38;
    }
    v28 = m_pIn->m_pBufferEnd;
    v33 = m_pIn->m_nInBufWord;
    v29 = m_nBits - m_nBitsAvail;
    v30 = m_pIn->m_pDataIn;
    if ( v30 == v28 )
    {
      m_pIn->m_nBitsAvail = 1;
      m_pIn->m_nInBufWord = 0;
      m_pIn->m_bOverflow = true;
    }
    else
    {
      if ( v30 > v28 )
      {
        m_pIn->m_bOverflow = true;
        m_pIn->m_nInBufWord = 0;
        goto LABEL_35;
      }
      m_pIn->m_nInBufWord = *v30;
    }
    m_pIn->m_pDataIn = v30 + 1;
LABEL_35:
    if ( m_pIn->m_bOverflow )
    {
      v24 = 0;
    }
    else
    {
      v31 = m_pIn->m_nInBufWord;
      v32 = (v31 & CBitBuffer::s_nMaskTable[v29]) << m_pIn->m_nBitsAvail;
      m_pIn->m_nBitsAvail = 32 - v29;
      m_pIn->m_nInBufWord = v31 >> v29;
      v24 = v32 | v33;
    }
LABEL_38:
    v8 = pInfo;
    pInfo->m_Value.m_Int = v24 << (32 - m_nBits) >> (32 - m_nBits);
    goto LABEL_39;
  }
  v2 = m_pProp->m_nBits;
  v3 = pInfo->m_pIn;
  v4 = v3->m_nBitsAvail;
  if ( v4 < v2 )
  {
    v12 = v3->m_pBufferEnd;
    v13 = v3->m_nInBufWord;
    v14 = v2 - v4;
    v15 = v3->m_pDataIn;
    if ( v15 == v12 )
    {
      v3->m_nBitsAvail = 1;
      v3->m_nInBufWord = 0;
      v3->m_bOverflow = true;
    }
    else
    {
      if ( v15 > v12 )
      {
        v3->m_bOverflow = true;
        v3->m_nInBufWord = 0;
        goto LABEL_17;
      }
      v3->m_nInBufWord = *v15;
    }
    v3->m_pDataIn = v15 + 1;
LABEL_17:
    if ( v3->m_bOverflow )
    {
      v8 = pInfo;
      pInfo->m_Value.m_Int = 0;
    }
    else
    {
      v16 = v3->m_nInBufWord;
      v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << v3->m_nBitsAvail;
      v3->m_nBitsAvail = 32 - v14;
      v8 = pInfo;
      v3->m_nInBufWord = v16 >> v14;
      pInfo->m_Value.m_Int = v17 | v13;
    }
    goto LABEL_39;
  }
  v5 = v3->m_nInBufWord;
  v6 = v5 & CBitBuffer::s_nMaskTable[v2];
  v7 = v4 - v2;
  v3->m_nBitsAvail = v7;
  if ( v7 != 0 )
  {
    v8 = pInfo;
    v3->m_nInBufWord = v5 >> v2;
    pInfo->m_Value.m_Int = v6;
  }
  else
  {
    v9 = v3->m_pDataIn;
    v10 = v3->m_pBufferEnd;
    v3->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      v3->m_pDataIn = v9 + 1;
      v8 = pInfo;
      v3->m_nBitsAvail = 1;
      v3->m_nInBufWord = 0;
      pInfo->m_Value.m_Int = v6;
    }
    else
    {
      if ( v9 <= v10 )
      {
        v11 = *v9;
        v3->m_pDataIn = v9 + 1;
        v8 = pInfo;
        v3->m_nInBufWord = v11;
      }
      else
      {
        v8 = pInfo;
        v3->m_bOverflow = true;
        v3->m_nInBufWord = 0;
      }
      v8->m_Value.m_Int = v6;
    }
  }
LABEL_39:
  if ( v8->m_pRecvProp != nullptr )
    v8->m_pRecvProp->m_ProxyFn(a1: v8, a2: v8->m_pStruct, a3: v8->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x101697F0
// Name: int Int_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Int_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  int m_nBits; // edx
  int m_nBitsAvail; // ecx
  unsigned int v5; // esi
  unsigned int v6; // edi
  int v7; // ecx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  const unsigned int *m_pDataIn; // ecx
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // edi
  int v17; // ecx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edx
  const unsigned int *v21; // esi
  unsigned int v22; // edi
  const unsigned int *v23; // ecx
  bf_read *p1a; // [esp+18h] [ebp+Ch]

  m_nBits = pProp->m_nBits;
  m_nBitsAvail = p1->m_nBitsAvail;
  if ( m_nBitsAvail < m_nBits )
  {
    m_pBufferEnd = p1->m_pBufferEnd;
    m_nInBufWord = p1->m_nInBufWord;
    m_nBits -= m_nBitsAvail;
    m_pDataIn = p1->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
LABEL_14:
        if ( p1->m_bOverflow )
        {
          p1a = nullptr;
          goto LABEL_19;
        }
        v5 = p1->m_nInBufWord;
        v6 = ((v5 & CBitBuffer::s_nMaskTable[m_nBits]) << p1->m_nBitsAvail) | m_nInBufWord;
        p1->m_nBitsAvail = 32 - m_nBits;
        goto LABEL_17;
      }
      p1->m_nInBufWord = *m_pDataIn;
    }
    p1->m_pDataIn = m_pDataIn + 1;
    goto LABEL_14;
  }
  v5 = p1->m_nInBufWord;
  v6 = v5 & CBitBuffer::s_nMaskTable[m_nBits];
  v7 = m_nBitsAvail - m_nBits;
  p1->m_nBitsAvail = v7;
  if ( v7 == 0 )
  {
    v8 = p1->m_pDataIn;
    v9 = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      p1->m_nInBufWord = *v8;
      p1->m_pDataIn = v8 + 1;
    }
    else
    {
      p1->m_bOverflow = true;
      p1->m_nInBufWord = 0;
    }
    goto LABEL_18;
  }
LABEL_17:
  p1->m_nInBufWord = v5 >> m_nBits;
LABEL_18:
  p1a = (bf_read *)v6;
LABEL_19:
  v13 = pProp->m_nBits;
  v14 = p2->m_nBitsAvail;
  if ( v14 < v13 )
  {
    v21 = p2->m_pBufferEnd;
    v22 = p2->m_nInBufWord;
    v13 -= v14;
    v23 = p2->m_pDataIn;
    if ( v23 == v21 )
    {
      p2->m_nBitsAvail = 1;
      p2->m_nInBufWord = 0;
      p2->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v21 )
      {
        p2->m_bOverflow = true;
        p2->m_nInBufWord = 0;
LABEL_33:
        if ( p2->m_bOverflow )
          return p1a != nullptr;
        v15 = p2->m_nInBufWord;
        v16 = ((v15 & CBitBuffer::s_nMaskTable[v13]) << p2->m_nBitsAvail) | v22;
        p2->m_nBitsAvail = 32 - v13;
        goto LABEL_36;
      }
      p2->m_nInBufWord = *v23;
    }
    p2->m_pDataIn = v23 + 1;
    goto LABEL_33;
  }
  v15 = p2->m_nInBufWord;
  v16 = v15 & CBitBuffer::s_nMaskTable[v13];
  v17 = v14 - v13;
  p2->m_nBitsAvail = v17;
  if ( v17 != 0 )
  {
LABEL_36:
    p2->m_nInBufWord = v15 >> v13;
    return p1a != (bf_read *)v16;
  }
  v18 = p2->m_pDataIn;
  v19 = p2->m_pBufferEnd;
  p2->m_nBitsAvail = 32;
  if ( v18 == v19 )
  {
    p2->m_nBitsAvail = 1;
    p2->m_nInBufWord = 0;
    p2->m_pDataIn = v18 + 1;
    return p1a != (bf_read *)v16;
  }
  else
  {
    if ( v18 <= v19 )
    {
      p2->m_nInBufWord = *v18;
      p2->m_pDataIn = v18 + 1;
    }
    else
    {
      p2->m_bOverflow = true;
      p2->m_nInBufWord = 0;
    }
    return p1a != (bf_read *)v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101699F0
// Name: char const __near * Int_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Int_GetTypeNameString()
{
  return "DPT_Int";
}

//------------------------------------------------------------------------------
// Address: 0x10169A00
// Name: bool Int_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Int_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return pVar->m_Int == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10169A10
// Name: void Int_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int_DecodeZero(DecodeInfo *pInfo)
{
  const RecvProp *m_pRecvProp; // ecx

  m_pRecvProp = pInfo->m_pRecvProp;
  pInfo->m_Value.m_Int = 0;
  if ( m_pRecvProp != nullptr )
    m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x10169A40
// Name: bool Int_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Int_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  int m_nBits; // edx
  int m_nBitsAvail; // ecx
  unsigned int v4; // esi
  unsigned int v5; // edi
  int v6; // ecx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx

  m_nBits = pProp->m_nBits;
  m_nBitsAvail = pIn->m_nBitsAvail;
  if ( m_nBitsAvail < m_nBits )
  {
    m_pBufferEnd = pIn->m_pBufferEnd;
    m_nInBufWord = pIn->m_nInBufWord;
    v12 = m_nBits - m_nBitsAvail;
    m_pDataIn = pIn->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
        goto LABEL_16;
      }
      pIn->m_nInBufWord = *m_pDataIn;
    }
    pIn->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( pIn->m_bOverflow )
      return 1;
    v14 = pIn->m_nInBufWord;
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << pIn->m_nBitsAvail;
    pIn->m_nBitsAvail = 32 - v12;
    pIn->m_nInBufWord = v14 >> v12;
    return (v15 | m_nInBufWord) == 0;
  }
  v4 = pIn->m_nInBufWord;
  v5 = v4 & CBitBuffer::s_nMaskTable[m_nBits];
  v6 = m_nBitsAvail - m_nBits;
  pIn->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    pIn->m_nInBufWord = v4 >> m_nBits;
    return v5 == 0;
  }
  else
  {
    v8 = pIn->m_pDataIn;
    v9 = pIn->m_pBufferEnd;
    pIn->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_pDataIn = v8 + 1;
      return v5 == 0;
    }
    else
    {
      if ( v8 <= v9 )
      {
        pIn->m_nInBufWord = *v8;
        pIn->m_pDataIn = v8 + 1;
      }
      else
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
      }
      return v5 == 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169B60
// Name: void Float_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Float_Encode(
        const unsigned __int8 *pStruct,
        DVariant *pVar,
        const SendProp *pProp,
        bf_write *pOut,
        DVariant *objectID)
{
  EncodeFloat(pProp, fVal: pVar->m_Float, pOut, (int)objectID);
}

//------------------------------------------------------------------------------
// Address: 0x10169B90
// Name: void Float_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Float_Decode(DecodeInfo *pInfo)
{
  pInfo->m_Value.m_Float = DecodeFloat(pIn: pInfo->m_pIn, pProp: pInfo->m_pProp);
  if ( pInfo->m_pRecvProp != nullptr )
    pInfo->m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x10169BD0
// Name: int Float_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Float_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  int m_Flags; // eax
  double BitCoord; // st7
  double v6; // st6
  int v8; // esi
  unsigned int v9; // ecx
  const unsigned int *v10; // edx
  const unsigned int *v11; // esi
  const unsigned int *v12; // ecx
  unsigned int v13; // edi
  int v14; // edx
  const unsigned int *v15; // esi
  unsigned int v16; // esi
  unsigned int v17; // ebx
  bf_read *v18; // eax
  int v19; // esi
  unsigned int v20; // ecx
  const unsigned int *v21; // edx
  const unsigned int *v22; // esi
  const unsigned int *v23; // ecx
  unsigned int v24; // edi
  int v25; // edx
  const unsigned int *v26; // esi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v29; // esi
  int v30; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v33; // edx
  const unsigned int *v34; // esi
  unsigned int v35; // edi
  int v36; // edx
  const unsigned int *v37; // ecx
  unsigned int v38; // esi
  unsigned int v39; // ebx
  int v40; // ecx
  unsigned int v41; // edx
  int v42; // edi
  int v43; // ecx
  const unsigned int *v44; // ecx
  const unsigned int *v45; // edx
  unsigned int v46; // edx
  const unsigned int *v47; // esi
  const unsigned int *v48; // ecx
  unsigned int v49; // esi
  unsigned int v50; // ebx
  double BitCellCoord; // st7
  double v52; // st6
  int m_nBits; // edx
  int v54; // ecx
  unsigned int v55; // esi
  unsigned int v56; // edi
  int v57; // ecx
  const unsigned int *v58; // ecx
  const unsigned int *v59; // edx
  const unsigned int *v60; // esi
  unsigned int v61; // edi
  const unsigned int *v62; // ecx
  int v63; // edx
  int v64; // ecx
  unsigned int v65; // esi
  unsigned int v66; // edi
  int v67; // ecx
  const unsigned int *v68; // ecx
  const unsigned int *v69; // edx
  const unsigned int *v70; // esi
  unsigned int v71; // edi
  const unsigned int *v72; // ecx
  unsigned int v73; // [esp+4h] [ebp-4h]
  float pPropb; // [esp+10h] [ebp+8h]
  float pPropc; // [esp+10h] [ebp+8h]
  float pPropd; // [esp+10h] [ebp+8h]
  float pPrope; // [esp+10h] [ebp+8h]
  const SendProp *pPropa; // [esp+10h] [ebp+8h]
  float pPropf; // [esp+10h] [ebp+8h]
  float pPropg; // [esp+10h] [ebp+8h]
  float pProph; // [esp+10h] [ebp+8h]

  m_Flags = pProp->m_Flags;
  if ( (m_Flags & 2) != 0 )
  {
    pPropb = CBitRead::ReadBitCoord(this: p1);
    BitCoord = CBitRead::ReadBitCoord(this: p2);
    v6 = pPropb;
    return v6 != BitCoord;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    pPropc = CBitRead::ReadBitCoordMP(this: p1, coordType: kCW_None);
    BitCoord = CBitRead::ReadBitCoordMP(this: p2, coordType: kCW_None);
    v6 = pPropc;
    return v6 != BitCoord;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    pPropd = CBitRead::ReadBitCoordMP(this: p1, coordType: kCW_LowPrecision);
    BitCoord = CBitRead::ReadBitCoordMP(this: p2, coordType: kCW_LowPrecision);
    v6 = pPropd;
    return v6 != BitCoord;
  }
  if ( (m_Flags & 0x4000) != 0 )
  {
    pPrope = CBitRead::ReadBitCoordMP(this: p1, coordType: kCW_Integral);
    BitCoord = CBitRead::ReadBitCoordMP(this: p2, coordType: kCW_Integral);
    v6 = pPrope;
    return v6 != BitCoord;
  }
  if ( (m_Flags & 4) == 0 )
  {
    if ( (m_Flags & 0x20) != 0 )
    {
      m_nBitsAvail = p1->m_nBitsAvail;
      if ( m_nBitsAvail >= 12 )
      {
        m_nInBufWord = p1->m_nInBufWord;
        v29 = m_nInBufWord & 0xFFF;
        v30 = m_nBitsAvail - 12;
        p1->m_nBitsAvail = v30;
        if ( v30 != 0 )
        {
          p1->m_nInBufWord = m_nInBufWord >> 12;
          pPropa = (const SendProp *)(m_nInBufWord & 0xFFF);
        }
        else
        {
          m_pDataIn = p1->m_pDataIn;
          m_pBufferEnd = p1->m_pBufferEnd;
          p1->m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            p1->m_nBitsAvail = 1;
            p1->m_nInBufWord = 0;
            p1->m_pDataIn = m_pDataIn + 1;
            pPropa = (const SendProp *)v29;
          }
          else
          {
            if ( m_pDataIn <= m_pBufferEnd )
            {
              v33 = *m_pDataIn;
              p1->m_pDataIn = m_pDataIn + 1;
              p1->m_nInBufWord = v33;
            }
            else
            {
              p1->m_bOverflow = true;
              p1->m_nInBufWord = 0;
            }
            pPropa = (const SendProp *)v29;
          }
        }
LABEL_64:
        v18 = p2;
        v40 = p2->m_nBitsAvail;
        if ( v40 >= 12 )
        {
          v41 = p2->m_nInBufWord;
          v42 = v41 & 0xFFF;
          v43 = v40 - 12;
          p2->m_nBitsAvail = v43;
          if ( v43 != 0 )
          {
            p2->m_nInBufWord = v41 >> 12;
            return pPropa != (const SendProp *)v42;
          }
          else
          {
            v44 = p2->m_pDataIn;
            v45 = p2->m_pBufferEnd;
            p2->m_nBitsAvail = 32;
            if ( v44 == v45 )
            {
              p2->m_nBitsAvail = 1;
              p2->m_nInBufWord = 0;
              p2->m_pDataIn = v44 + 1;
              return pPropa != (const SendProp *)v42;
            }
            else
            {
              if ( v44 <= v45 )
              {
                v46 = *v44;
                p2->m_pDataIn = v44 + 1;
                p2->m_nInBufWord = v46;
              }
              else
              {
                p2->m_bOverflow = true;
                p2->m_nInBufWord = 0;
              }
              return pPropa != (const SendProp *)v42;
            }
          }
        }
        v47 = p2->m_pBufferEnd;
        v24 = p2->m_nInBufWord;
        v25 = 12 - v40;
        v48 = p2->m_pDataIn;
        if ( v48 == v47 )
        {
          p2->m_nBitsAvail = 1;
          p2->m_nInBufWord = 0;
          p2->m_bOverflow = true;
        }
        else
        {
          if ( v48 > v47 )
          {
            p2->m_bOverflow = true;
            p2->m_nInBufWord = 0;
            goto LABEL_79;
          }
          p2->m_nInBufWord = *v48;
        }
        p2->m_pDataIn = v48 + 1;
LABEL_79:
        if ( p2->m_bOverflow )
          return pPropa != nullptr;
        goto LABEL_81;
      }
      v34 = p1->m_pBufferEnd;
      v35 = p1->m_nInBufWord;
      v36 = 12 - m_nBitsAvail;
      v37 = p1->m_pDataIn;
      if ( v37 == v34 )
      {
        p1->m_nBitsAvail = 1;
        p1->m_nInBufWord = 0;
        p1->m_bOverflow = true;
      }
      else
      {
        if ( v37 > v34 )
        {
          p1->m_bOverflow = true;
          p1->m_nInBufWord = 0;
          goto LABEL_61;
        }
        p1->m_nInBufWord = *v37;
      }
      p1->m_pDataIn = v37 + 1;
LABEL_61:
      if ( p1->m_bOverflow )
      {
        pPropa = nullptr;
      }
      else
      {
        v38 = p1->m_nInBufWord;
        v39 = (v38 & CBitBuffer::s_nMaskTable[v36]) << p1->m_nBitsAvail;
        p1->m_nBitsAvail = 32 - v36;
        pPropa = (const SendProp *)(v39 | v35);
        p1->m_nInBufWord = v38 >> v36;
      }
      goto LABEL_64;
    }
    if ( (m_Flags & 0x8000) != 0 )
    {
      pPropf = CBitRead::ReadBitCellCoord(this: p1, bits: pProp->m_nBits, coordType: kCW_None);
      BitCellCoord = CBitRead::ReadBitCellCoord(this: p2, bits: pProp->m_nBits, coordType: kCW_None);
      v52 = pPropf;
      return v52 != BitCellCoord;
    }
    if ( (m_Flags & 0x10000) != 0 )
    {
      pPropg = CBitRead::ReadBitCellCoord(this: p1, bits: pProp->m_nBits, coordType: kCW_LowPrecision);
      BitCellCoord = CBitRead::ReadBitCellCoord(this: p2, bits: pProp->m_nBits, coordType: kCW_LowPrecision);
      v52 = pPropg;
      return v52 != BitCellCoord;
    }
    if ( (m_Flags & 0x20000) != 0 )
    {
      pProph = CBitRead::ReadBitCellCoord(this: p1, bits: pProp->m_nBits, coordType: kCW_Integral);
      BitCellCoord = CBitRead::ReadBitCellCoord(this: p2, bits: pProp->m_nBits, coordType: kCW_Integral);
      v52 = pProph;
      return v52 != BitCellCoord;
    }
    m_nBits = pProp->m_nBits;
    v54 = p1->m_nBitsAvail;
    if ( v54 >= m_nBits )
    {
      v55 = p1->m_nInBufWord;
      v56 = v55 & CBitBuffer::s_nMaskTable[m_nBits];
      v57 = v54 - m_nBits;
      p1->m_nBitsAvail = v57;
      if ( v57 == 0 )
      {
        v58 = p1->m_pDataIn;
        v59 = p1->m_pBufferEnd;
        p1->m_nBitsAvail = 32;
        if ( v58 == v59 )
        {
          p1->m_nBitsAvail = 1;
          p1->m_nInBufWord = 0;
          p1->m_pDataIn = v58 + 1;
        }
        else if ( v58 <= v59 )
        {
          p1->m_nInBufWord = *v58;
          p1->m_pDataIn = v58 + 1;
        }
        else
        {
          p1->m_bOverflow = true;
          p1->m_nInBufWord = 0;
        }
        goto LABEL_106;
      }
LABEL_105:
      p1->m_nInBufWord = v55 >> m_nBits;
LABEL_106:
      v73 = v56;
LABEL_107:
      v63 = pProp->m_nBits;
      v64 = p2->m_nBitsAvail;
      if ( v64 >= v63 )
      {
        v65 = p2->m_nInBufWord;
        v66 = v65 & CBitBuffer::s_nMaskTable[v63];
        v67 = v64 - v63;
        p2->m_nBitsAvail = v67;
        if ( v67 == 0 )
        {
          v68 = p2->m_pDataIn;
          v69 = p2->m_pBufferEnd;
          p2->m_nBitsAvail = 32;
          if ( v68 == v69 )
          {
            p2->m_nBitsAvail = 1;
            p2->m_nInBufWord = 0;
            p2->m_pDataIn = v68 + 1;
            return v73 != v66;
          }
          else
          {
            if ( v68 <= v69 )
            {
              p2->m_nInBufWord = *v68;
              p2->m_pDataIn = v68 + 1;
            }
            else
            {
              p2->m_bOverflow = true;
              p2->m_nInBufWord = 0;
            }
            return v73 != v66;
          }
        }
LABEL_124:
        p2->m_nInBufWord = v65 >> v63;
        return v73 != v66;
      }
      v70 = p2->m_pBufferEnd;
      v71 = p2->m_nInBufWord;
      v63 -= v64;
      v72 = p2->m_pDataIn;
      if ( v72 == v70 )
      {
        p2->m_nBitsAvail = 1;
        p2->m_nInBufWord = 0;
        p2->m_bOverflow = true;
      }
      else
      {
        if ( v72 > v70 )
        {
          p2->m_bOverflow = true;
          p2->m_nInBufWord = 0;
LABEL_121:
          if ( p2->m_bOverflow )
            return v73 != 0;
          v65 = p2->m_nInBufWord;
          v66 = ((v65 & CBitBuffer::s_nMaskTable[v63]) << p2->m_nBitsAvail) | v71;
          p2->m_nBitsAvail = 32 - v63;
          goto LABEL_124;
        }
        p2->m_nInBufWord = *v72;
      }
      p2->m_pDataIn = v72 + 1;
      goto LABEL_121;
    }
    v60 = p1->m_pBufferEnd;
    v61 = p1->m_nInBufWord;
    m_nBits -= v54;
    v62 = p1->m_pDataIn;
    if ( v62 == v60 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( v62 > v60 )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
LABEL_102:
        if ( p1->m_bOverflow )
        {
          v73 = 0;
          goto LABEL_107;
        }
        v55 = p1->m_nInBufWord;
        v56 = ((v55 & CBitBuffer::s_nMaskTable[m_nBits]) << p1->m_nBitsAvail) | v61;
        p1->m_nBitsAvail = 32 - m_nBits;
        goto LABEL_105;
      }
      p1->m_nInBufWord = *v62;
    }
    p1->m_pDataIn = v62 + 1;
    goto LABEL_102;
  }
  v8 = p1->m_nBitsAvail;
  if ( v8 < 32 )
  {
    v12 = p1->m_pDataIn;
    v13 = p1->m_nInBufWord;
    v14 = 32 - v8;
    v15 = p1->m_pBufferEnd;
    if ( v12 == v15 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( v12 > v15 )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
        goto LABEL_26;
      }
      p1->m_nInBufWord = *v12;
    }
    p1->m_pDataIn = v12 + 1;
LABEL_26:
    if ( p1->m_bOverflow )
    {
      pPropa = nullptr;
    }
    else
    {
      v16 = p1->m_nInBufWord;
      v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << p1->m_nBitsAvail;
      p1->m_nBitsAvail = 32 - v14;
      pPropa = (const SendProp *)(v17 | v13);
      p1->m_nInBufWord = v16 >> v14;
    }
    goto LABEL_29;
  }
  v9 = p1->m_nInBufWord;
  p1->m_nBitsAvail = v8 - 32;
  if ( v8 == 32 )
  {
    v10 = p1->m_pDataIn;
    v11 = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( v10 == v11 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_pDataIn = v10 + 1;
      pPropa = (const SendProp *)v9;
    }
    else
    {
      if ( v10 <= v11 )
      {
        p1->m_nInBufWord = *v10;
        p1->m_pDataIn = v10 + 1;
      }
      else
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
      }
      pPropa = (const SendProp *)v9;
    }
  }
  else
  {
    p1->m_nInBufWord = 0;
    pPropa = (const SendProp *)v9;
  }
LABEL_29:
  v18 = p2;
  v19 = p2->m_nBitsAvail;
  if ( v19 < 32 )
  {
    v23 = p2->m_pDataIn;
    v24 = p2->m_nInBufWord;
    v25 = 32 - v19;
    v26 = p2->m_pBufferEnd;
    if ( v23 == v26 )
    {
      p2->m_nBitsAvail = 1;
      p2->m_nInBufWord = 0;
      p2->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v26 )
      {
        p2->m_bOverflow = true;
        p2->m_nInBufWord = 0;
        goto LABEL_43;
      }
      p2->m_nInBufWord = *v23;
    }
    p2->m_pDataIn = v23 + 1;
LABEL_43:
    if ( p2->m_bOverflow )
      return pPropa != nullptr;
LABEL_81:
    v49 = v18->m_nInBufWord;
    v50 = (v49 & CBitBuffer::s_nMaskTable[v25]) << v18->m_nBitsAvail;
    v18->m_nBitsAvail = 32 - v25;
    v18->m_nInBufWord = v49 >> v25;
    return pPropa != (const SendProp *)(v50 | v24);
  }
  v20 = p2->m_nInBufWord;
  p2->m_nBitsAvail = v19 - 32;
  if ( v19 != 32 )
  {
LABEL_35:
    p2->m_nInBufWord = 0;
    return pPropa != (const SendProp *)v20;
  }
  v21 = p2->m_pDataIn;
  v22 = p2->m_pBufferEnd;
  p2->m_nBitsAvail = 32;
  if ( v21 == v22 )
  {
    p2->m_nInBufWord = 0;
    p2->m_nBitsAvail = 1;
    p2->m_pDataIn = v21 + 1;
    return pPropa != (const SendProp *)v20;
  }
  if ( v21 > v22 )
  {
    p2->m_bOverflow = true;
    goto LABEL_35;
  }
  p2->m_nInBufWord = *v21;
  p2->m_pDataIn = v21 + 1;
  return pPropa != (const SendProp *)v20;
}

//------------------------------------------------------------------------------
// Address: 0x1016A300
// Name: char const __near * Float_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Float_GetTypeNameString()
{
  return "DPT_Float";
}

//------------------------------------------------------------------------------
// Address: 0x1016A310
// Name: bool Float_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Float_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return pVar->m_Float == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A340
// Name: void Float_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Float_DecodeZero(DecodeInfo *pInfo)
{
  const RecvProp *m_pRecvProp; // ecx

  m_pRecvProp = pInfo->m_pRecvProp;
  pInfo->m_Value.m_Int = 0;
  if ( m_pRecvProp != nullptr )
    m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016A370
// Name: bool Float_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Float_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  return DecodeFloat(pIn, pProp) == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A3A0
// Name: void Vector_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector_Decode(DecodeInfo *pInfo)
{
  DecodeVector(pProp: pInfo->m_pProp, pIn: pInfo->m_pIn, v: &pInfo->m_Value.m_Float);
  if ( pInfo->m_pRecvProp != nullptr )
    pInfo->m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016A3E0
// Name: int Vector_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Vector_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  unsigned int m_nInBufWord; // eax
  int v5; // ebx
  bool v6; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v9; // eax
  int v10; // esi
  const unsigned int *v11; // eax
  const unsigned int *v12; // ecx
  unsigned int v14; // edx
  BOOL c1; // [esp+Ch] [ebp-4h]
  BOOL c2; // [esp+18h] [ebp+8h]

  c1 = Float_CompareDeltas(pProp, p1, p2);
  c2 = Float_CompareDeltas(pProp, p1, p2);
  if ( (pProp->m_Flags & 0x20) == 0 )
    return c1 | c2 | Float_CompareDeltas(pProp, p1, p2);
  m_nInBufWord = p1->m_nInBufWord;
  v5 = m_nInBufWord & 1;
  v6 = p1->m_nBitsAvail-- == 1;
  if ( v6 )
  {
    m_pDataIn = p1->m_pDataIn;
    m_pBufferEnd = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      p1->m_nInBufWord = *m_pDataIn;
      p1->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      p1->m_bOverflow = true;
      p1->m_nInBufWord = 0;
    }
  }
  else
  {
    p1->m_nInBufWord = m_nInBufWord >> 1;
  }
  v9 = p2->m_nInBufWord;
  v10 = v9 & 1;
  v6 = p2->m_nBitsAvail-- == 1;
  if ( v6 )
  {
    v11 = p2->m_pDataIn;
    v12 = p2->m_pBufferEnd;
    p2->m_nBitsAvail = 32;
    if ( v11 == v12 )
    {
      p2->m_pDataIn = v11 + 1;
      p2->m_nBitsAvail = 1;
      p2->m_nInBufWord = 0;
      return c1 || c2 || v5 != v10;
    }
    else
    {
      if ( v11 <= v12 )
      {
        v14 = *v11;
        p2->m_pDataIn = v11 + 1;
        p2->m_nInBufWord = v14;
      }
      else
      {
        p2->m_bOverflow = true;
        p2->m_nInBufWord = 0;
      }
      return c1 || c2 || v5 != v10;
    }
  }
  else
  {
    p2->m_nInBufWord = v9 >> 1;
    return c1 || c2 || v5 != v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016A520
// Name: char const __near * Vector_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Vector_GetTypeNameString()
{
  return "DPT_Vector";
}

//------------------------------------------------------------------------------
// Address: 0x1016A530
// Name: bool Vector_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Vector_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return pVar->m_Float == 0.0 && pVar->m_Vector[1] == 0.0 && pVar->m_Vector[2] == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A570
// Name: void Vector_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector_DecodeZero(DecodeInfo *pInfo)
{
  const RecvProp *m_pRecvProp; // ecx

  m_pRecvProp = pInfo->m_pRecvProp;
  pInfo->m_Value.m_Int64 = 0;
  pInfo->m_Value.m_Vector[2] = 0.0;
  if ( m_pRecvProp != nullptr )
    m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016A5B0
// Name: bool Vector_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Vector_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  float v[3]; // [esp+0h] [ebp-Ch] BYREF

  DecodeVector(pProp, pIn, v);
  return v[0] == 0.0 && v[1] == 0.0 && v[2] == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A610
// Name: void VectorXY_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorXY_Encode(
        const unsigned __int8 *pStruct,
        DVariant *pVar,
        const SendProp *pProp,
        bf_write *pOut,
        DVariant *objectID)
{
  EncodeFloat(pProp, fVal: pVar->m_Float, pOut, (int)objectID);
  EncodeFloat(pProp, fVal: pVar->m_Vector[1], pOut, (int)objectID);
}

//------------------------------------------------------------------------------
// Address: 0x1016A650
// Name: void VectorXY_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorXY_Decode(DecodeInfo *pInfo)
{
  pInfo->m_Value.m_Float = DecodeFloat(pIn: pInfo->m_pIn, pProp: pInfo->m_pProp);
  pInfo->m_Value.m_Vector[1] = DecodeFloat(pIn: pInfo->m_pIn, pProp: pInfo->m_pProp);
  if ( pInfo->m_pRecvProp != nullptr )
    pInfo->m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016A6A0
// Name: int VectorXY_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorXY_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  BOOL c1; // [esp+Ch] [ebp-4h]

  c1 = Float_CompareDeltas(pProp, p1, p2);
  return c1 | Float_CompareDeltas(pProp, p1, p2);
}

//------------------------------------------------------------------------------
// Address: 0x1016A6D0
// Name: char const __near * VectorXY_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl VectorXY_GetTypeNameString()
{
  return "DPT_VectorXY";
}

//------------------------------------------------------------------------------
// Address: 0x1016A6E0
// Name: bool VectorXY_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VectorXY_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return pVar->m_Float == 0.0 && pVar->m_Vector[1] == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A710
// Name: void VectorXY_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorXY_DecodeZero(DecodeInfo *pInfo)
{
  const RecvProp *m_pRecvProp; // ecx

  m_pRecvProp = pInfo->m_pRecvProp;
  pInfo->m_Value.m_Int64 = 0;
  if ( m_pRecvProp != nullptr )
    m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016A740
// Name: bool VectorXY_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VectorXY_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  float v; // [esp+8h] [ebp-8h]
  float v_4; // [esp+Ch] [ebp-4h]

  v = DecodeFloat(pIn, pProp);
  v_4 = DecodeFloat(pIn, pProp);
  return v == 0.0 && v_4 == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A7A0
// Name: void String_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl String_Encode(const unsigned __int8 *pStruct, DVariant *pVar, const SendProp *pProp, bf_write *pOut)
{
  int i; // esi
  bf_write *v5; // edi
  int m_iCurBit; // eax
  int m_nDataBits; // ecx
  int v8; // edx
  int v9; // eax

  for ( i = 0; i < 511; ++i )
  {
    if ( *(_BYTE *)(pVar->m_Int + i) == 0 )
      break;
  }
  v5 = pOut;
  m_iCurBit = pOut->m_iCurBit;
  m_nDataBits = pOut->m_nDataBits;
  if ( m_iCurBit + 9 <= m_nDataBits )
  {
    v8 = pOut->m_iCurBit >> 5;
    *(_DWORD *)&pOut->m_pData[4 * v8] = (i << (pOut->m_iCurBit & 0x1F))
                                      | *(_DWORD *)&pOut->m_pData[4 * v8]
                                      & dword_106C73EC[33 * (pOut->m_iCurBit & 0x1F)];
    v5 = pOut;
    v9 = 32 - (m_iCurBit & 0x1F);
    if ( v9 - 9 < 0 )
      *(_DWORD *)&pOut->m_pData[4 * v8 + 4] = ((unsigned int)i >> v9)
                                            | *(_DWORD *)&pOut->m_pData[4 * v8 + 4] & dword_106C73EC[-v9];
    pOut->m_iCurBit += 9;
  }
  else
  {
    pOut->m_iCurBit = m_nDataBits;
    pOut->m_bOverflow = true;
  }
  bf_write::WriteBits(this: v5, pInData: pVar->m_Int, nBits: 8 * i);
}

//------------------------------------------------------------------------------
// Address: 0x1016A860
// Name: void String_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl String_Decode(DecodeInfo *pInfo)
{
  DecodeInfo *v1; // ebx
  bf_read *m_pIn; // eax
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  unsigned int v10; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v13; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  int v17; // edi
  int v18; // edi
  char *m_TempStr; // esi
  const char **p_m_pVarName; // eax

  v1 = pInfo;
  m_pIn = pInfo->m_pIn;
  m_nBitsAvail = m_pIn->m_nBitsAvail;
  if ( m_nBitsAvail < 9 )
  {
    m_pBufferEnd = m_pIn->m_pBufferEnd;
    m_nInBufWord = m_pIn->m_nInBufWord;
    v13 = 9 - m_nBitsAvail;
    m_pDataIn = m_pIn->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      m_pIn->m_nBitsAvail = 1;
      m_pIn->m_nInBufWord = 0;
      m_pIn->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        m_pIn->m_bOverflow = true;
        m_pIn->m_nInBufWord = 0;
        goto LABEL_16;
      }
      m_pIn->m_nInBufWord = *m_pDataIn;
    }
    m_pIn->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( m_pIn->m_bOverflow )
    {
      v7 = 0;
    }
    else
    {
      v15 = m_pIn->m_nInBufWord;
      v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << m_pIn->m_nBitsAvail;
      m_pIn->m_nBitsAvail = 32 - v13;
      v17 = v16 | m_nInBufWord;
      v1 = pInfo;
      m_pIn->m_nInBufWord = v15 >> v13;
      v7 = v17;
    }
    goto LABEL_19;
  }
  v4 = m_pIn->m_nInBufWord;
  v5 = v4 & 0x1FF;
  v6 = m_nBitsAvail - 9;
  m_pIn->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    m_pIn->m_nInBufWord = v4 >> 9;
    v7 = v4 & 0x1FF;
  }
  else
  {
    v8 = m_pIn->m_pDataIn;
    v9 = m_pIn->m_pBufferEnd;
    m_pIn->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      m_pIn->m_nBitsAvail = 1;
      m_pIn->m_nInBufWord = 0;
      m_pIn->m_pDataIn = v8 + 1;
      v7 = v5;
    }
    else
    {
      if ( v8 <= v9 )
      {
        v10 = *v8;
        m_pIn->m_pDataIn = v8 + 1;
        m_pIn->m_nInBufWord = v10;
      }
      else
      {
        m_pIn->m_bOverflow = true;
        m_pIn->m_nInBufWord = 0;
      }
      v7 = v5;
    }
  }
LABEL_19:
  v18 = v7;
  m_TempStr = v1->m_TempStr;
  if ( v7 >= 512 )
  {
    _Warning(a1: "String_Decode( %s ) invalid length (%d)\n", v1->m_pRecvProp->m_pVarName, v7);
    v18 = 511;
  }
  CBitRead::ReadBits(this: v1->m_pIn, pOutData: v1->m_TempStr, nBits: 8 * v18);
  m_TempStr[v18] = 0;
  p_m_pVarName = (const char **)&v1->m_pRecvProp->m_pVarName;
  v1->m_Value.m_Int = (int)m_TempStr;
  if ( p_m_pVarName != nullptr )
    ((void (__cdecl *)(DecodeInfo *, void *, void *))p_m_pVarName[8])(a1: v1, a2: v1->m_pStruct, a3: v1->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016A9B0
// Name: AreBitsDifferent
// Source: json
//------------------------------------------------------------------------------
int __usercall AreBitsDifferent@<eax>(bf_read *pBuf1@<edx>, bf_read *pBuf2@<esi>, int nBits)
{
  int v3; // edi
  int v4; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v7; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edi
  int v10; // edi
  const unsigned int *v11; // ecx
  const unsigned int *v12; // eax
  unsigned int v13; // ebx
  unsigned int v14; // eax
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // ecx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edi
  int v20; // edi
  const unsigned int *v21; // ecx
  const unsigned int *v22; // eax
  unsigned int v23; // ebx
  unsigned int v24; // eax
  int v25; // edi
  int v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // ebx
  int v29; // ecx
  char v30; // cl
  const unsigned int *v31; // eax
  const unsigned int *v32; // ecx
  const unsigned int *v33; // ebx
  int v34; // eax
  const unsigned int *v35; // ecx
  int v36; // ecx
  unsigned int v37; // eax
  unsigned int v38; // edx
  int v39; // ecx
  const unsigned int *v40; // eax
  const unsigned int *v41; // ecx
  int v43; // eax
  BOOL v44; // edx
  unsigned int v45; // ecx
  const unsigned int *v46; // eax
  unsigned int v47; // edx
  const unsigned int *v48; // ecx
  unsigned int v49; // [esp+10h] [ebp-10h]
  int v50; // [esp+14h] [ebp-Ch]
  unsigned int v51; // [esp+18h] [ebp-8h]
  unsigned int v52; // [esp+18h] [ebp-8h]
  int diff; // [esp+1Ch] [ebp-4h]
  unsigned int nBitsa; // [esp+28h] [ebp+8h]
  int nBitsb; // [esp+28h] [ebp+8h]

  v3 = nBits;
  v4 = nBits >> 5;
  diff = 0;
  if ( nBits >> 5 > 0 )
  {
    v50 = nBits >> 5;
    while ( 1 )
    {
      m_nBitsAvail = pBuf1->m_nBitsAvail;
      m_nInBufWord = pBuf1->m_nInBufWord;
      if ( m_nBitsAvail >= 32 )
      {
        v7 = m_nBitsAvail - 32;
        pBuf1->m_nBitsAvail = v7;
        if ( v7 != 0 )
        {
          pBuf1->m_nInBufWord = 0;
        }
        else
        {
          m_pDataIn = pBuf1->m_pDataIn;
          pBuf1->m_nBitsAvail = 32;
          m_pBufferEnd = pBuf1->m_pBufferEnd;
          if ( m_pDataIn == m_pBufferEnd )
          {
            pBuf1->m_nBitsAvail = 1;
            pBuf1->m_nInBufWord = 0;
            pBuf1->m_pDataIn = m_pDataIn + 1;
          }
          else if ( m_pDataIn <= m_pBufferEnd )
          {
            pBuf1->m_nInBufWord = *m_pDataIn;
            pBuf1->m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            pBuf1->m_bOverflow = true;
            pBuf1->m_nInBufWord = 0;
          }
        }
        goto LABEL_20;
      }
      v10 = 32 - m_nBitsAvail;
      v11 = pBuf1->m_pBufferEnd;
      v51 = pBuf1->m_nInBufWord;
      v12 = pBuf1->m_pDataIn;
      if ( v12 == v11 )
        break;
      if ( v12 <= v11 )
      {
        pBuf1->m_nInBufWord = *v12;
        goto LABEL_16;
      }
      pBuf1->m_bOverflow = true;
      pBuf1->m_nInBufWord = 0;
LABEL_17:
      if ( pBuf1->m_bOverflow )
      {
        v52 = 0;
        goto LABEL_21;
      }
      v13 = pBuf1->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v10]) << pBuf1->m_nBitsAvail;
      pBuf1->m_nBitsAvail = 32 - v10;
      m_nInBufWord = v14 | v51;
      pBuf1->m_nInBufWord = v13 >> v10;
LABEL_20:
      v52 = m_nInBufWord;
LABEL_21:
      v15 = pBuf2->m_nBitsAvail;
      v16 = pBuf2->m_nInBufWord;
      if ( v15 < 32 )
      {
        v20 = 32 - v15;
        v21 = pBuf2->m_pBufferEnd;
        v49 = pBuf2->m_nInBufWord;
        v22 = pBuf2->m_pDataIn;
        if ( v22 == v21 )
        {
          pBuf2->m_nBitsAvail = 1;
          pBuf2->m_nInBufWord = 0;
          pBuf2->m_bOverflow = true;
          goto LABEL_34;
        }
        if ( v22 <= v21 )
        {
          pBuf2->m_nInBufWord = *v22;
LABEL_34:
          pBuf2->m_pDataIn = v22 + 1;
        }
        else
        {
          pBuf2->m_bOverflow = true;
          pBuf2->m_nInBufWord = 0;
        }
        if ( pBuf2->m_bOverflow )
        {
          v16 = 0;
        }
        else
        {
          v23 = pBuf2->m_nInBufWord;
          v24 = (v23 & CBitBuffer::s_nMaskTable[v20]) << pBuf2->m_nBitsAvail;
          pBuf2->m_nBitsAvail = 32 - v20;
          v16 = v24 | v49;
          pBuf2->m_nInBufWord = v23 >> v20;
        }
        goto LABEL_38;
      }
      v17 = v15 - 32;
      pBuf2->m_nBitsAvail = v17;
      if ( v17 != 0 )
      {
        pBuf2->m_nInBufWord = 0;
      }
      else
      {
        v18 = pBuf2->m_pDataIn;
        pBuf2->m_nBitsAvail = 32;
        v19 = pBuf2->m_pBufferEnd;
        if ( v18 == v19 )
        {
          pBuf2->m_nBitsAvail = 1;
          pBuf2->m_nInBufWord = 0;
          pBuf2->m_pDataIn = v18 + 1;
        }
        else if ( v18 <= v19 )
        {
          pBuf2->m_nInBufWord = *v18;
          pBuf2->m_pDataIn = v18 + 1;
        }
        else
        {
          pBuf2->m_bOverflow = true;
          pBuf2->m_nInBufWord = 0;
        }
      }
LABEL_38:
      diff |= v52 != v16;
      if ( --v50 == 0 )
      {
        v4 = nBits >> 5;
        v3 = nBits;
        goto LABEL_40;
      }
    }
    pBuf1->m_nBitsAvail = 1;
    pBuf1->m_nInBufWord = 0;
    pBuf1->m_bOverflow = true;
LABEL_16:
    pBuf1->m_pDataIn = v12 + 1;
    goto LABEL_17;
  }
LABEL_40:
  v25 = v3 - 32 * v4;
  if ( v25 <= 0 )
    return diff;
  v26 = pBuf1->m_nBitsAvail;
  v27 = pBuf1->m_nInBufWord;
  if ( v26 < v25 )
  {
    v33 = pBuf1->m_pBufferEnd;
    nBitsa = pBuf1->m_nInBufWord;
    v34 = v25 - v26;
    v35 = pBuf1->m_pDataIn;
    if ( v35 == v33 )
    {
      pBuf1->m_nBitsAvail = 1;
      pBuf1->m_nInBufWord = 0;
      pBuf1->m_bOverflow = true;
    }
    else
    {
      if ( v35 > v33 )
      {
        pBuf1->m_bOverflow = true;
        pBuf1->m_nInBufWord = 0;
LABEL_55:
        if ( pBuf1->m_bOverflow )
        {
          nBitsb = 0;
          goto LABEL_60;
        }
        v28 = ((pBuf1->m_nInBufWord & CBitBuffer::s_nMaskTable[v34]) << pBuf1->m_nBitsAvail) | nBitsa;
        pBuf1->m_nBitsAvail = 32 - v34;
        v30 = v34;
        v27 = pBuf1->m_nInBufWord;
        goto LABEL_58;
      }
      pBuf1->m_nInBufWord = *v35;
    }
    pBuf1->m_pDataIn = v35 + 1;
    goto LABEL_55;
  }
  v28 = v27 & CBitBuffer::s_nMaskTable[v25];
  v29 = v26 - v25;
  pBuf1->m_nBitsAvail = v29;
  if ( v29 == 0 )
  {
    v31 = pBuf1->m_pDataIn;
    v32 = pBuf1->m_pBufferEnd;
    pBuf1->m_nBitsAvail = 32;
    if ( v31 == v32 )
    {
      pBuf1->m_nBitsAvail = 1;
      pBuf1->m_nInBufWord = 0;
      pBuf1->m_pDataIn = v31 + 1;
    }
    else if ( v31 <= v32 )
    {
      pBuf1->m_nInBufWord = *v31;
      pBuf1->m_pDataIn = v31 + 1;
    }
    else
    {
      pBuf1->m_bOverflow = true;
      pBuf1->m_nInBufWord = 0;
    }
    goto LABEL_59;
  }
  v30 = v25;
LABEL_58:
  pBuf1->m_nInBufWord = v27 >> v30;
LABEL_59:
  nBitsb = v28;
LABEL_60:
  v36 = pBuf2->m_nBitsAvail;
  if ( v36 < v25 )
  {
    v46 = pBuf2->m_pDataIn;
    v47 = pBuf2->m_nInBufWord;
    v25 -= v36;
    v48 = pBuf2->m_pBufferEnd;
    if ( v46 == v48 )
    {
      pBuf2->m_nBitsAvail = 1;
      pBuf2->m_nInBufWord = 0;
      pBuf2->m_bOverflow = true;
    }
    else
    {
      if ( v46 > v48 )
      {
        pBuf2->m_bOverflow = true;
        pBuf2->m_nInBufWord = 0;
LABEL_74:
        if ( pBuf2->m_bOverflow )
          return (nBitsb != 0) | diff;
        v37 = pBuf2->m_nInBufWord;
        v38 = ((v37 & CBitBuffer::s_nMaskTable[v25]) << pBuf2->m_nBitsAvail) | v47;
        pBuf2->m_nBitsAvail = 32 - v25;
        goto LABEL_77;
      }
      pBuf2->m_nInBufWord = *v46;
    }
    pBuf2->m_pDataIn = v46 + 1;
    goto LABEL_74;
  }
  v37 = pBuf2->m_nInBufWord;
  v38 = v37 & CBitBuffer::s_nMaskTable[v25];
  v39 = v36 - v25;
  pBuf2->m_nBitsAvail = v39;
  if ( v39 != 0 )
  {
LABEL_77:
    pBuf2->m_nInBufWord = v37 >> v25;
    return (nBitsb != v38) | diff;
  }
  v40 = pBuf2->m_pDataIn;
  v41 = pBuf2->m_pBufferEnd;
  pBuf2->m_nBitsAvail = 32;
  if ( v40 == v41 )
  {
    pBuf2->m_pDataIn = v40 + 1;
    pBuf2->m_nBitsAvail = 1;
    pBuf2->m_nInBufWord = 0;
    return (nBitsb != v38) | diff;
  }
  else
  {
    if ( v40 <= v41 )
    {
      v45 = *v40;
      pBuf2->m_pDataIn = v40 + 1;
      v43 = diff;
      v44 = nBitsb != v38;
      pBuf2->m_nInBufWord = v45;
    }
    else
    {
      v43 = diff;
      v44 = nBitsb != v38;
      pBuf2->m_bOverflow = true;
      pBuf2->m_nInBufWord = 0;
    }
    return v44 | v43;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016ADC0
// Name: char const __near * String_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl String_GetTypeNameString()
{
  return "DPT_String";
}

//------------------------------------------------------------------------------
// Address: 0x1016ADD0
// Name: bool String_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl String_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return *pVar->m_pString == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016ADF0
// Name: void String_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl String_DecodeZero(DecodeInfo *pInfo)
{
  pInfo->m_Value.m_Int = (int)pInfo->m_TempStr;
  pInfo->m_TempStr[0] = 0;
  if ( pInfo->m_pRecvProp != nullptr )
    pInfo->m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016AE20
// Name: void Array_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Array_Encode(
        const unsigned __int8 *pStruct,
        DVariant *pVar,
        SendProp *pProp,
        bf_write *pOut,
        int objectID)
{
  int (__cdecl *m_ArrayLengthProxy)(const void *, int); // eax
  SendProp *m_pArrayProp; // edi
  int m_nElements; // eax
  unsigned int NumArrayLengthBits; // eax
  const unsigned __int8 *v9; // esi
  int i; // ebx
  void (__cdecl *m_ProxyFn)(const SendProp *, const void *, const void *, DVariant *, int, int); // edx
  DVariant var; // [esp+Ch] [ebp-1Ch] BYREF
  int nElements; // [esp+24h] [ebp-4h]

  m_ArrayLengthProxy = pProp->m_ArrayLengthProxy;
  m_pArrayProp = pProp->m_pArrayProp;
  if ( m_ArrayLengthProxy != nullptr )
  {
    m_nElements = m_ArrayLengthProxy(a1: pStruct, a2: objectID);
    if ( m_nElements > pProp->m_nElements )
      m_nElements = pProp->m_nElements;
  }
  else
  {
    m_nElements = pProp->m_nElements;
  }
  nElements = m_nElements;
  NumArrayLengthBits = SendProp::GetNumArrayLengthBits(this: pProp);
  bf_write::WriteUBitLong(this: pOut, curData: nElements, numbits: NumArrayLengthBits, bCheckRange: true);
  v9 = &pStruct[m_pArrayProp->m_Offset & 0xFFFFF];
  for ( i = 0; i < nElements; ++i )
  {
    m_ProxyFn = m_pArrayProp->m_ProxyFn;
    var.m_Type = DPT_Float;
    m_ProxyFn(a1: m_pArrayProp, a2: pStruct, a3: v9, a4: &var, a5: i, a6: objectID);
    ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *))g_PropTypeFns[m_pArrayProp->m_Type].Encode)(
      pStruct,
      pVar: &var,
      pProp: m_pArrayProp,
      pOut);
    v9 += pProp->m_ElementStride;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016AEE0
// Name: int Array_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Array_CompareDeltas(SendProp *pProp, bf_read *p1, bf_read *p2)
{
  signed int NumArrayLengthBits; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  unsigned int v7; // esi
  int v8; // ecx
  int v9; // ebx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v12; // edx
  const unsigned int *v13; // esi
  int v14; // edx
  const unsigned int *v15; // ecx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  bf_read *v18; // esi
  int v19; // ecx
  unsigned int v20; // edx
  unsigned int v21; // ebx
  int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  const unsigned int *v25; // eax
  const unsigned int *v26; // ecx
  unsigned int v27; // edx
  int v28; // eax
  const unsigned int *v29; // ecx
  const unsigned int *v30; // edx
  unsigned int v31; // edx
  unsigned int v32; // ebx
  unsigned int v33; // edx
  BOOL v34; // edx
  int v35; // ecx
  int i; // ebx
  int v37; // eax
  int j; // ebx
  const SendProp *v40; // [esp+0h] [ebp-14h]
  bf_write *v41; // [esp+4h] [ebp-10h]
  DVariant *v42; // [esp+8h] [ebp-Ch]
  SendProp *pArrayProp; // [esp+Ch] [ebp-8h]
  int nSame; // [esp+10h] [ebp-4h]
  const SendProp *pPropa; // [esp+1Ch] [ebp+8h]
  unsigned int p1a; // [esp+20h] [ebp+Ch]
  bf_read *p1b; // [esp+20h] [ebp+Ch]
  unsigned int bDifferent; // [esp+24h] [ebp+10h]
  int bDifferenta; // [esp+24h] [ebp+10h]

  pArrayProp = pProp->m_pArrayProp;
  NumArrayLengthBits = SendProp::GetNumArrayLengthBits(this: pProp);
  m_nBitsAvail = p1->m_nBitsAvail;
  m_nInBufWord = p1->m_nInBufWord;
  if ( m_nBitsAvail >= NumArrayLengthBits )
  {
    v7 = m_nInBufWord & CBitBuffer::s_nMaskTable[NumArrayLengthBits];
    v8 = m_nBitsAvail - NumArrayLengthBits;
    p1->m_nBitsAvail = v8;
    if ( v8 != 0 )
    {
      v9 = v7;
      p1->m_nInBufWord = m_nInBufWord >> NumArrayLengthBits;
    }
    else
    {
      m_pDataIn = p1->m_pDataIn;
      m_pBufferEnd = p1->m_pBufferEnd;
      p1->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        p1->m_nBitsAvail = 1;
        p1->m_nInBufWord = 0;
        p1->m_pDataIn = m_pDataIn + 1;
        v9 = v7;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v12 = *m_pDataIn;
          p1->m_pDataIn = m_pDataIn + 1;
          p1->m_nInBufWord = v12;
        }
        else
        {
          p1->m_bOverflow = true;
          p1->m_nInBufWord = 0;
        }
        v9 = v7;
      }
    }
    goto LABEL_19;
  }
  v13 = p1->m_pBufferEnd;
  p1a = p1->m_nInBufWord;
  v14 = NumArrayLengthBits - m_nBitsAvail;
  v15 = p1->m_pDataIn;
  if ( v15 == v13 )
  {
    p1->m_nBitsAvail = 1;
    p1->m_nInBufWord = 0;
    p1->m_bOverflow = true;
LABEL_15:
    p1->m_pDataIn = v15 + 1;
    goto LABEL_16;
  }
  if ( v15 <= v13 )
  {
    p1->m_nInBufWord = *v15;
    goto LABEL_15;
  }
  p1->m_bOverflow = true;
  p1->m_nInBufWord = 0;
LABEL_16:
  if ( p1->m_bOverflow )
  {
    pPropa = nullptr;
    v9 = 0;
    goto LABEL_20;
  }
  v16 = p1->m_nInBufWord;
  v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << p1->m_nBitsAvail;
  p1->m_nBitsAvail = 32 - v14;
  v9 = v17 | p1a;
  p1->m_nInBufWord = v16 >> v14;
LABEL_19:
  pPropa = (const SendProp *)v9;
LABEL_20:
  v18 = p2;
  v19 = p2->m_nBitsAvail;
  v20 = p2->m_nInBufWord;
  if ( v19 >= NumArrayLengthBits )
  {
    v21 = v20 & CBitBuffer::s_nMaskTable[NumArrayLengthBits];
    v22 = v19 - NumArrayLengthBits;
    p2->m_nBitsAvail = v22;
    if ( v22 != 0 )
    {
      v23 = v20 >> NumArrayLengthBits;
      v24 = v21;
      p1b = (bf_read *)v21;
      p2->m_nInBufWord = v23;
    }
    else
    {
      v25 = p2->m_pDataIn;
      v26 = p2->m_pBufferEnd;
      p2->m_nBitsAvail = 32;
      if ( v25 == v26 )
      {
        p2->m_pDataIn = v25 + 1;
        v24 = v21;
        p2->m_nBitsAvail = 1;
        p2->m_nInBufWord = 0;
        p1b = (bf_read *)v21;
      }
      else
      {
        if ( v25 <= v26 )
        {
          v27 = *v25;
          p2->m_pDataIn = v25 + 1;
          v24 = v21;
          p2->m_nInBufWord = v27;
        }
        else
        {
          v24 = v21;
          p2->m_bOverflow = true;
          p2->m_nInBufWord = 0;
        }
        p1b = (bf_read *)v21;
      }
    }
    goto LABEL_38;
  }
  v28 = NumArrayLengthBits - v19;
  v29 = p2->m_pDataIn;
  bDifferent = p2->m_nInBufWord;
  v30 = v18->m_pBufferEnd;
  if ( v29 == v30 )
  {
    v18->m_nBitsAvail = 1;
    v18->m_nInBufWord = 0;
    v18->m_bOverflow = true;
LABEL_34:
    v18->m_pDataIn = v29 + 1;
    goto LABEL_35;
  }
  if ( v29 <= v30 )
  {
    v18->m_nInBufWord = *v29;
    goto LABEL_34;
  }
  v18->m_bOverflow = true;
  v18->m_nInBufWord = 0;
LABEL_35:
  if ( v18->m_bOverflow )
  {
    p1b = nullptr;
    v24 = 0;
    goto LABEL_39;
  }
  v31 = v18->m_nInBufWord;
  v32 = (v31 & CBitBuffer::s_nMaskTable[v28]) << v18->m_nBitsAvail;
  v18->m_nBitsAvail = 32 - v28;
  v33 = v31 >> v28;
  p1b = (bf_read *)(v32 | bDifferent);
  v24 = v32 | bDifferent;
  v18->m_nInBufWord = v33;
LABEL_38:
  v9 = (int)pPropa;
LABEL_39:
  v34 = v9 != v24;
  bDifferenta = v34;
  if ( v9 >= v24 )
  {
    nSame = v24;
    v35 = v24;
  }
  else
  {
    v35 = v9;
    nSame = v9;
  }
  if ( v35 > 0 )
  {
    for ( i = v35; i != 0; --i )
      bDifferenta |= (*(&funcs_1016B133 + 9 * pArrayProp->m_Type))(pProp: pArrayProp, p1, p2: v18);
    v24 = (int)p1b;
    v9 = (int)pPropa;
    v35 = nSame;
    v34 = bDifferenta;
  }
  if ( v9 == v24 )
    return v34;
  if ( v9 > v24 )
  {
    v18 = p1;
    v24 = v9;
  }
  v37 = v24 - v35;
  if ( v37 <= 0 )
    return v34;
  for ( j = v37; j != 0; --j )
    ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B172[9 * pArrayProp->m_Type])(
      pStruct: (const unsigned __int8 *)pArrayProp,
      pVar: (DVariant *)v18,
      pProp: v40,
      pOut: v41,
      objectID: v42);
  return bDifferenta;
}

//------------------------------------------------------------------------------
// Address: 0x1016B190
// Name: void Array_FastCopy(class SendProp const __near *,class RecvProp const __near *,unsigned char const __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Array_FastCopy(
        const SendProp *pSendProp,
        const RecvProp *pRecvProp,
        const unsigned __int8 *pSendData,
        unsigned __int8 *pRecvData,
        int objectID)
{
  int v5; // ecx
  SendProp *m_pArrayProp; // ebx
  RecvProp *v7; // edi
  int (__cdecl *m_ArrayLengthProxy)(const void *, int); // eax
  int m_nElements; // eax
  void (__cdecl *v10)(void *, int, int); // eax
  unsigned __int8 *v11; // edi
  const unsigned __int8 *v12; // esi
  int v13; // eax
  CRecvProxyData recvProxyData; // [esp+Ch] [ebp-30h] BYREF
  const RecvProp *pArrayRecvProp; // [esp+34h] [ebp-8h]
  int nElements; // [esp+38h] [ebp-4h]

  v5 = objectID;
  m_pArrayProp = pSendProp->m_pArrayProp;
  v7 = pRecvProp->m_pArrayProp;
  m_ArrayLengthProxy = pSendProp->m_ArrayLengthProxy;
  pArrayRecvProp = v7;
  recvProxyData.m_Value.m_Type = DPT_Float;
  recvProxyData.m_pRecvProp = v7;
  recvProxyData.m_ObjectID = objectID;
  if ( m_ArrayLengthProxy != nullptr )
  {
    m_nElements = m_ArrayLengthProxy(a1: pSendData, a2: objectID);
    v5 = objectID;
    if ( m_nElements > pSendProp->m_nElements )
      m_nElements = pSendProp->m_nElements;
    nElements = m_nElements;
  }
  else
  {
    nElements = pSendProp->m_nElements;
  }
  v10 = pRecvProp->m_ArrayLengthProxy;
  if ( v10 != nullptr )
    v10(a1: pRecvData, a2: v5, a3: nElements);
  v11 = &pRecvData[v7->m_Offset];
  v12 = &pSendData[m_pArrayProp->m_Offset & 0xFFFFF];
  v13 = 0;
  for ( recvProxyData.m_iElement = 0; v13 < nElements; recvProxyData.m_iElement = v13 )
  {
    m_pArrayProp->m_ProxyFn(a1: m_pArrayProp, a2: pSendData, a3: v12, a4: &recvProxyData.m_Value, a5: v13, a6: objectID);
    v12 += pSendProp->m_ElementStride;
    pArrayRecvProp->m_ProxyFn(a1: &recvProxyData, a2: pRecvData, a3: v11);
    v11 += pRecvProp->m_ElementStride;
    v13 = recvProxyData.m_iElement + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B260
// Name: char const __near * Array_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Array_GetTypeNameString()
{
  return "DPT_Array";
}

//------------------------------------------------------------------------------
// Address: 0x1016B270
// Name: bool Array_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Array_IsZero(const unsigned __int8 *pStruct, DVariant *pVar, const SendProp *pProp)
{
  int (__cdecl *m_ArrayLengthProxy)(const void *, int); // eax
  int m_nElements; // eax

  m_ArrayLengthProxy = pProp->m_ArrayLengthProxy;
  if ( m_ArrayLengthProxy != nullptr )
  {
    m_nElements = m_ArrayLengthProxy(a1: pStruct, a2: -1);
    if ( m_nElements > pProp->m_nElements )
      m_nElements = pProp->m_nElements;
    LOBYTE(m_nElements) = m_nElements == 0;
  }
  else
  {
    return pProp->m_nElements == 0;
  }
  return m_nElements;
}

//------------------------------------------------------------------------------
// Address: 0x1016B2B0
// Name: void Array_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Array_DecodeZero(DecodeInfo *pInfo)
{
  void (__cdecl *m_ArrayLengthProxy)(void *, int, int); // ecx

  m_ArrayLengthProxy = pInfo->m_pRecvProp->m_ArrayLengthProxy;
  if ( m_ArrayLengthProxy != nullptr )
    m_ArrayLengthProxy(a1: pInfo->m_pStruct, a2: pInfo->m_ObjectID, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1016B2D0
// Name: bool Array_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Array_IsEncodedZero(SendProp *pProp, bf_read *pIn)
{
  signed int NumArrayLengthBits; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  unsigned int v6; // edi
  int v7; // ecx
  int v8; // ebx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v11; // edx
  unsigned int v12; // edi
  int v13; // eax
  const unsigned int *v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int i; // edi
  SendProp *pArrayProp; // [esp+14h] [ebp+8h]

  pArrayProp = pProp->m_pArrayProp;
  NumArrayLengthBits = SendProp::GetNumArrayLengthBits(this: pProp);
  m_nBitsAvail = pIn->m_nBitsAvail;
  if ( m_nBitsAvail >= NumArrayLengthBits )
  {
    m_nInBufWord = pIn->m_nInBufWord;
    v6 = m_nInBufWord & CBitBuffer::s_nMaskTable[NumArrayLengthBits];
    v7 = m_nBitsAvail - NumArrayLengthBits;
    pIn->m_nBitsAvail = v7;
    if ( v7 != 0 )
    {
      v8 = v6;
      pIn->m_nInBufWord = m_nInBufWord >> NumArrayLengthBits;
    }
    else
    {
      m_pDataIn = pIn->m_pDataIn;
      m_pBufferEnd = pIn->m_pBufferEnd;
      pIn->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pIn->m_nBitsAvail = 1;
        pIn->m_nInBufWord = 0;
        pIn->m_pDataIn = m_pDataIn + 1;
        v8 = v6;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          pIn->m_nInBufWord = *m_pDataIn;
          pIn->m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          pIn->m_bOverflow = true;
          pIn->m_nInBufWord = 0;
        }
        v8 = v6;
      }
    }
    goto LABEL_19;
  }
  v11 = pIn->m_pBufferEnd;
  v12 = pIn->m_nInBufWord;
  v13 = NumArrayLengthBits - m_nBitsAvail;
  v14 = pIn->m_pDataIn;
  if ( v14 == v11 )
  {
    pIn->m_nBitsAvail = 1;
    pIn->m_nInBufWord = 0;
    pIn->m_bOverflow = true;
  }
  else
  {
    if ( v14 > v11 )
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
      goto LABEL_16;
    }
    pIn->m_nInBufWord = *v14;
  }
  pIn->m_pDataIn = v14 + 1;
LABEL_16:
  if ( pIn->m_bOverflow )
  {
    v8 = 0;
  }
  else
  {
    v15 = pIn->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << pIn->m_nBitsAvail;
    pIn->m_nBitsAvail = 32 - v13;
    v8 = v12 | v16;
    pIn->m_nInBufWord = v15 >> v13;
  }
LABEL_19:
  if ( v8 > 0 )
  {
    for ( i = v8; i != 0; --i )
      (*(&funcs_1016B3E2 + 9 * pArrayProp->m_Type))(pProp: pArrayProp, pIn);
  }
  return v8 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016B400
// Name: void Array_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Array_SkipProp(SendProp *pProp, DVariant *pIn)
{
  signed int NumArrayLengthBits; // eax
  int v4; // ecx
  unsigned int v5; // edx
  int v6; // edi
  int v7; // ecx
  unsigned int v8; // edx
  const unsigned int *v9; // eax
  const unsigned int *v10; // ecx
  const unsigned int *v11; // edx
  unsigned int m_Type; // edi
  int v13; // eax
  const unsigned int *m_Int; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  const SendProp *v17; // [esp+0h] [ebp-Ch]
  bf_write *v18; // [esp+4h] [ebp-8h]
  DVariant *v19; // [esp+8h] [ebp-4h]
  SendProp *pArrayProp; // [esp+14h] [ebp+8h]

  pArrayProp = pProp->m_pArrayProp;
  NumArrayLengthBits = SendProp::GetNumArrayLengthBits(this: pProp);
  v4 = *((_DWORD *)&pIn->m_Type + 1);
  if ( v4 < NumArrayLengthBits )
  {
    v11 = (const unsigned int *)LODWORD(pIn[1].m_Vector[1]);
    m_Type = pIn->m_Type;
    v13 = NumArrayLengthBits - v4;
    m_Int = (const unsigned int *)pIn[1].m_Int;
    if ( m_Int == v11 )
    {
      *((_DWORD *)&pIn->m_Type + 1) = 1;
      pIn->m_Type = DPT_Int;
      *((_BYTE *)&pIn->m_pData + 4) = 1;
    }
    else
    {
      if ( m_Int > v11 )
      {
        *((_BYTE *)&pIn->m_pData + 4) = 1;
        pIn->m_Type = DPT_Int;
LABEL_15:
        if ( *((_BYTE *)&pIn->m_pData + 4) != 0 )
        {
          v6 = 0;
          goto LABEL_19;
        }
        v15 = pIn->m_Type;
        v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << *((_DWORD *)&pIn->m_Type + 1);
        *((_DWORD *)&pIn->m_Type + 1) = 32 - v13;
        v6 = v16 | m_Type;
        v8 = v15 >> v13;
        goto LABEL_18;
      }
      pIn->m_Type = *m_Int;
    }
    pIn[1].m_Int = (int)(m_Int + 1);
    goto LABEL_15;
  }
  v5 = pIn->m_Type;
  v6 = v5 & CBitBuffer::s_nMaskTable[NumArrayLengthBits];
  v7 = v4 - NumArrayLengthBits;
  *((_DWORD *)&pIn->m_Type + 1) = v7;
  if ( v7 != 0 )
  {
    v8 = v5 >> NumArrayLengthBits;
LABEL_18:
    pIn->m_Type = v8;
    goto LABEL_19;
  }
  v9 = (const unsigned int *)pIn[1].m_Int;
  v10 = (const unsigned int *)LODWORD(pIn[1].m_Vector[1]);
  *((_DWORD *)&pIn->m_Type + 1) = 32;
  if ( v9 == v10 )
  {
    *((_DWORD *)&pIn->m_Type + 1) = 1;
    pIn->m_Type = DPT_Int;
    pIn[1].m_Int = (int)(v9 + 1);
  }
  else if ( v9 <= v10 )
  {
    pIn->m_Type = *v9;
    pIn[1].m_Int = (int)(v9 + 1);
  }
  else
  {
    *((_BYTE *)&pIn->m_pData + 4) = 1;
    pIn->m_Type = DPT_Int;
  }
LABEL_19:
  if ( v6 > 0 )
  {
    do
    {
      ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B172[9 * pArrayProp->m_Type])(
        pStruct: (const unsigned __int8 *)pArrayProp,
        pVar: pIn,
        pProp: v17,
        pOut: v18,
        objectID: v19);
      --v6;
    }
    while ( v6 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B510
// Name: char const __near * DataTable_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl DataTable_GetTypeNameString()
{
  return "DPT_DataTable";
}

//------------------------------------------------------------------------------
// Address: 0x1016B520
// Name: void Int64_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int64_Decode(DecodeInfo *pInfo)
{
  DecodeInfo *v1; // edi
  bf_read *m_pIn; // eax
  unsigned int v3; // ecx
  int v4; // edx
  const unsigned int *v6; // ecx
  const unsigned int *v7; // esi
  bf_read *v8; // eax
  int v9; // ecx
  unsigned int v10; // edx
  const unsigned int *v11; // ecx
  const unsigned int *v12; // esi
  const unsigned int *v13; // esi
  unsigned int v14; // edi
  int v15; // edx
  const unsigned int *v16; // ecx
  unsigned int v17; // esi
  unsigned int v18; // edi
  bf_read *v19; // eax
  int v20; // ecx
  int v21; // edx
  unsigned int v22; // esi
  unsigned int v23; // edi
  int v24; // ecx
  const unsigned int *v25; // ecx
  const unsigned int *v26; // edx
  const unsigned int *v27; // esi
  unsigned int v28; // edi
  const unsigned int *v29; // ecx
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v34; // ecx
  unsigned int v35; // edi
  int v36; // edx
  const unsigned int *v37; // esi
  unsigned int v38; // esi
  unsigned int v39; // ebx
  int v40; // ecx
  int v41; // ecx
  const unsigned int *v42; // edx
  const unsigned int *v43; // esi
  float v44; // eax
  unsigned int v45; // ebx
  unsigned int lowInt; // [esp+Ch] [ebp-8h]
  bool bNeg; // [esp+13h] [ebp-1h]

  v1 = pInfo;
  m_pIn = pInfo->m_pIn;
  bNeg = false;
  if ( (pInfo->m_pProp->m_Flags & 1) != 0 )
  {
    m_nBitsAvail = m_pIn->m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = m_pIn->m_nInBufWord;
      m_pIn->m_nBitsAvail = m_nBitsAvail - 32;
      if ( m_nBitsAvail == 32 )
      {
        m_pDataIn = m_pIn->m_pDataIn;
        m_pBufferEnd = m_pIn->m_pBufferEnd;
        m_pIn->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          m_pIn->m_nBitsAvail = 1;
          m_pIn->m_nInBufWord = 0;
          m_pIn->m_pDataIn = m_pDataIn + 1;
          lowInt = m_nInBufWord;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            m_pIn->m_nInBufWord = *m_pDataIn;
            m_pIn->m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            m_pIn->m_bOverflow = true;
            m_pIn->m_nInBufWord = 0;
          }
          lowInt = m_nInBufWord;
        }
      }
      else
      {
        m_pIn->m_nInBufWord = 0;
        lowInt = m_nInBufWord;
      }
      goto LABEL_58;
    }
    v34 = m_pIn->m_pDataIn;
    v35 = m_pIn->m_nInBufWord;
    v36 = 32 - m_nBitsAvail;
    v37 = m_pIn->m_pBufferEnd;
    if ( v34 == v37 )
    {
      m_pIn->m_nBitsAvail = 1;
      m_pIn->m_nInBufWord = 0;
      m_pIn->m_bOverflow = true;
    }
    else
    {
      if ( v34 > v37 )
      {
        m_pIn->m_bOverflow = true;
        m_pIn->m_nInBufWord = 0;
LABEL_54:
        if ( m_pIn->m_bOverflow )
        {
          lowInt = 0;
        }
        else
        {
          v38 = m_pIn->m_nInBufWord;
          v39 = (v38 & CBitBuffer::s_nMaskTable[v36]) << m_pIn->m_nBitsAvail;
          m_pIn->m_nBitsAvail = 32 - v36;
          lowInt = v39 | v35;
          m_pIn->m_nInBufWord = v38 >> v36;
        }
        v1 = pInfo;
LABEL_58:
        v19 = v1->m_pIn;
        v40 = v19->m_nBitsAvail;
        v21 = v1->m_pProp->m_nBits - 32;
        if ( v40 >= v21 )
        {
          v22 = v19->m_nInBufWord;
          v23 = v22 & CBitBuffer::s_nMaskTable[v21];
          v41 = v40 - v21;
          v19->m_nBitsAvail = v41;
          if ( v41 == 0 )
          {
            v25 = v19->m_pDataIn;
            v42 = v19->m_pBufferEnd;
            v19->m_nBitsAvail = 32;
            if ( v25 == v42 )
            {
              v19->m_nBitsAvail = 1;
              v19->m_nInBufWord = 0;
              v19->m_pDataIn = v25 + 1;
              goto LABEL_74;
            }
            if ( v25 > v42 )
            {
              v19->m_bOverflow = true;
              v19->m_nInBufWord = 0;
              goto LABEL_74;
            }
            goto LABEL_34;
          }
LABEL_73:
          v19->m_nInBufWord = v22 >> v21;
          goto LABEL_74;
        }
        v43 = v19->m_pBufferEnd;
        v28 = v19->m_nInBufWord;
        v21 -= v40;
        v29 = v19->m_pDataIn;
        if ( v29 == v43 )
        {
          v19->m_nBitsAvail = 1;
          v19->m_nInBufWord = 0;
          v19->m_bOverflow = true;
          goto LABEL_69;
        }
        if ( v29 > v43 )
        {
          v19->m_bOverflow = true;
          v19->m_nInBufWord = 0;
          goto LABEL_70;
        }
LABEL_68:
        v19->m_nInBufWord = *v29;
        goto LABEL_69;
      }
      m_pIn->m_nInBufWord = *v34;
    }
    m_pIn->m_pDataIn = v34 + 1;
    goto LABEL_54;
  }
  v3 = m_pIn->m_nInBufWord;
  v4 = v3 & 1;
  if ( m_pIn->m_nBitsAvail-- == 1 )
  {
    v6 = m_pIn->m_pDataIn;
    v7 = m_pIn->m_pBufferEnd;
    m_pIn->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      m_pIn->m_nBitsAvail = 1;
      m_pIn->m_nInBufWord = 0;
      m_pIn->m_pDataIn = v6 + 1;
    }
    else if ( v6 <= v7 )
    {
      m_pIn->m_nInBufWord = *v6;
      m_pIn->m_pDataIn = v6 + 1;
    }
    else
    {
      m_pIn->m_bOverflow = true;
      m_pIn->m_nInBufWord = 0;
    }
  }
  else
  {
    m_pIn->m_nInBufWord = v3 >> 1;
  }
  v8 = pInfo->m_pIn;
  v9 = v8->m_nBitsAvail;
  bNeg = v4 != 0;
  if ( v9 >= 32 )
  {
    v10 = v8->m_nInBufWord;
    v8->m_nBitsAvail = v9 - 32;
    if ( v9 == 32 )
    {
      v11 = v8->m_pDataIn;
      v12 = v8->m_pBufferEnd;
      v8->m_nBitsAvail = 32;
      if ( v11 == v12 )
      {
        v8->m_nBitsAvail = 1;
        v8->m_nInBufWord = 0;
        v8->m_pDataIn = v11 + 1;
        lowInt = v10;
      }
      else
      {
        if ( v11 <= v12 )
        {
          v8->m_nInBufWord = *v11;
          v8->m_pDataIn = v11 + 1;
        }
        else
        {
          v8->m_bOverflow = true;
          v8->m_nInBufWord = 0;
        }
        lowInt = v10;
      }
    }
    else
    {
      v8->m_nInBufWord = 0;
      lowInt = v10;
    }
    goto LABEL_28;
  }
  v13 = v8->m_pBufferEnd;
  v14 = v8->m_nInBufWord;
  v15 = 32 - v9;
  v16 = v8->m_pDataIn;
  if ( v16 == v13 )
  {
    v8->m_nBitsAvail = 1;
    v8->m_nInBufWord = 0;
    v8->m_bOverflow = true;
LABEL_23:
    v8->m_pDataIn = v16 + 1;
    goto LABEL_24;
  }
  if ( v16 <= v13 )
  {
    v8->m_nInBufWord = *v16;
    goto LABEL_23;
  }
  v8->m_bOverflow = true;
  v8->m_nInBufWord = 0;
LABEL_24:
  if ( v8->m_bOverflow )
  {
    lowInt = 0;
  }
  else
  {
    v17 = v8->m_nInBufWord;
    v18 = ((v17 & CBitBuffer::s_nMaskTable[v15]) << v8->m_nBitsAvail) | v14;
    v8->m_nBitsAvail = 32 - v15;
    lowInt = v18;
    v8->m_nInBufWord = v17 >> v15;
  }
  v1 = pInfo;
LABEL_28:
  v19 = v1->m_pIn;
  v20 = v19->m_nBitsAvail;
  v21 = v1->m_pProp->m_nBits - 33;
  if ( v20 < v21 )
  {
    v27 = v19->m_pBufferEnd;
    v28 = v19->m_nInBufWord;
    v21 -= v20;
    v29 = v19->m_pDataIn;
    if ( v29 == v27 )
    {
      v19->m_nBitsAvail = 1;
      v19->m_nInBufWord = 0;
      v19->m_bOverflow = true;
LABEL_69:
      v19->m_pDataIn = v29 + 1;
      goto LABEL_70;
    }
    if ( v29 > v27 )
    {
      v19->m_bOverflow = true;
      v19->m_nInBufWord = 0;
LABEL_70:
      if ( v19->m_bOverflow )
      {
        v44 = 0.0;
        goto LABEL_75;
      }
      v22 = v19->m_nInBufWord;
      v45 = (v22 & CBitBuffer::s_nMaskTable[v21]) << v19->m_nBitsAvail;
      v19->m_nBitsAvail = 32 - v21;
      v23 = v45 | v28;
      goto LABEL_73;
    }
    goto LABEL_68;
  }
  v22 = v19->m_nInBufWord;
  v23 = v22 & CBitBuffer::s_nMaskTable[v21];
  v24 = v20 - v21;
  v19->m_nBitsAvail = v24;
  if ( v24 != 0 )
    goto LABEL_73;
  v25 = v19->m_pDataIn;
  v26 = v19->m_pBufferEnd;
  v19->m_nBitsAvail = 32;
  if ( v25 != v26 )
  {
    if ( v25 > v26 )
    {
      v19->m_bOverflow = true;
      v19->m_nInBufWord = 0;
      goto LABEL_74;
    }
LABEL_34:
    v19->m_nInBufWord = *v25;
    v19->m_pDataIn = v25 + 1;
    goto LABEL_74;
  }
  v19->m_nBitsAvail = 1;
  v19->m_nInBufWord = 0;
  v19->m_pDataIn = v25 + 1;
LABEL_74:
  v44 = *(float *)&v23;
LABEL_75:
  pInfo->m_Value.m_Int = lowInt;
  pInfo->m_Value.m_Vector[1] = v44;
  if ( bNeg )
    pInfo->m_Value.m_Int64 = -pInfo->m_Value.m_Int64;
  if ( pInfo->m_pRecvProp != nullptr )
    pInfo->m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016B940
// Name: int Int64_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Int64_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  int m_nBitsAvail; // ecx
  int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // edi
  int v8; // ecx
  unsigned int v9; // esi
  const unsigned int *v10; // ecx
  const unsigned int *v11; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v14; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  int v18; // esi
  unsigned int v19; // ecx
  const unsigned int *v20; // edx
  const unsigned int *v21; // esi
  const unsigned int *v22; // ecx
  unsigned int v23; // edi
  int v24; // edx
  const unsigned int *v25; // esi
  unsigned int v26; // esi
  unsigned int v27; // ebx
  int v28; // ecx
  int v29; // edx
  unsigned int v30; // esi
  unsigned int v31; // edi
  int v32; // ecx
  unsigned int v33; // esi
  const unsigned int *v34; // ecx
  const unsigned int *v35; // edx
  const unsigned int *v36; // esi
  unsigned int v37; // edi
  int v38; // edx
  const unsigned int *v39; // ecx
  unsigned int v40; // esi
  unsigned int v41; // ebx
  int v42; // esi
  unsigned int v43; // ecx
  int v44; // edi
  const unsigned int *v45; // edx
  const unsigned int *v46; // esi
  const unsigned int *v47; // ecx
  unsigned int v48; // edi
  int v49; // edx
  const unsigned int *v50; // esi
  unsigned int v51; // esi
  unsigned int v52; // ebx
  unsigned int lowInt1; // [esp+Ch] [ebp-4h]
  unsigned int highInt2; // [esp+18h] [ebp+8h]
  unsigned int highInt1; // [esp+1Ch] [ebp+Ch]

  m_nBitsAvail = p1->m_nBitsAvail;
  v5 = pProp->m_nBits - 32;
  if ( m_nBitsAvail < v5 )
  {
    m_pBufferEnd = p1->m_pBufferEnd;
    m_nInBufWord = p1->m_nInBufWord;
    v14 = v5 - m_nBitsAvail;
    m_pDataIn = p1->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
LABEL_15:
        if ( p1->m_bOverflow )
        {
          highInt1 = 0;
          goto LABEL_20;
        }
        v16 = p1->m_nInBufWord;
        v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << p1->m_nBitsAvail;
        p1->m_nBitsAvail = 32 - v14;
        v7 = v17 | m_nInBufWord;
        v9 = v16 >> v14;
        goto LABEL_18;
      }
      p1->m_nInBufWord = *m_pDataIn;
    }
    p1->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v6 = p1->m_nInBufWord;
  v7 = v6 & CBitBuffer::s_nMaskTable[v5];
  v8 = m_nBitsAvail - v5;
  p1->m_nBitsAvail = v8;
  if ( v8 == 0 )
  {
    v10 = p1->m_pDataIn;
    v11 = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( v10 == v11 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_pDataIn = v10 + 1;
    }
    else if ( v10 <= v11 )
    {
      p1->m_nInBufWord = *v10;
      p1->m_pDataIn = v10 + 1;
    }
    else
    {
      p1->m_bOverflow = true;
      p1->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v9 = v6 >> v5;
LABEL_18:
  p1->m_nInBufWord = v9;
LABEL_19:
  highInt1 = v7;
LABEL_20:
  v18 = p1->m_nBitsAvail;
  if ( v18 < 32 )
  {
    v22 = p1->m_pDataIn;
    v23 = p1->m_nInBufWord;
    v24 = 32 - v18;
    v25 = p1->m_pBufferEnd;
    if ( v22 == v25 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( v22 > v25 )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
        goto LABEL_35;
      }
      p1->m_nInBufWord = *v22;
    }
    p1->m_pDataIn = v22 + 1;
LABEL_35:
    if ( p1->m_bOverflow )
    {
      lowInt1 = 0;
    }
    else
    {
      v26 = p1->m_nInBufWord;
      v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << p1->m_nBitsAvail;
      p1->m_nBitsAvail = 32 - v24;
      lowInt1 = v27 | v23;
      p1->m_nInBufWord = v26 >> v24;
    }
    goto LABEL_38;
  }
  v19 = p1->m_nInBufWord;
  p1->m_nBitsAvail = v18 - 32;
  if ( v18 == 32 )
  {
    v20 = p1->m_pDataIn;
    v21 = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( v20 == v21 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_pDataIn = v20 + 1;
      lowInt1 = v19;
    }
    else
    {
      if ( v20 <= v21 )
      {
        p1->m_nInBufWord = *v20;
        p1->m_pDataIn = v20 + 1;
      }
      else
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
      }
      lowInt1 = v19;
    }
  }
  else
  {
    p1->m_nInBufWord = 0;
    lowInt1 = v19;
  }
LABEL_38:
  v28 = p2->m_nBitsAvail;
  v29 = pProp->m_nBits - 32;
  if ( v28 < v29 )
  {
    v36 = p2->m_pBufferEnd;
    v37 = p2->m_nInBufWord;
    v38 = v29 - v28;
    v39 = p2->m_pDataIn;
    if ( v39 == v36 )
    {
      p2->m_nBitsAvail = 1;
      p2->m_nInBufWord = 0;
      p2->m_bOverflow = true;
    }
    else
    {
      if ( v39 > v36 )
      {
        p2->m_bOverflow = true;
        p2->m_nInBufWord = 0;
LABEL_52:
        if ( p2->m_bOverflow )
        {
          highInt2 = 0;
          goto LABEL_57;
        }
        v40 = p2->m_nInBufWord;
        v41 = (v40 & CBitBuffer::s_nMaskTable[v38]) << p2->m_nBitsAvail;
        p2->m_nBitsAvail = 32 - v38;
        v31 = v41 | v37;
        v33 = v40 >> v38;
        goto LABEL_55;
      }
      p2->m_nInBufWord = *v39;
    }
    p2->m_pDataIn = v39 + 1;
    goto LABEL_52;
  }
  v30 = p2->m_nInBufWord;
  v31 = v30 & CBitBuffer::s_nMaskTable[v29];
  v32 = v28 - v29;
  p2->m_nBitsAvail = v32;
  if ( v32 == 0 )
  {
    v34 = p2->m_pDataIn;
    v35 = p2->m_pBufferEnd;
    p2->m_nBitsAvail = 32;
    if ( v34 == v35 )
    {
      p2->m_nBitsAvail = 1;
      p2->m_nInBufWord = 0;
      p2->m_pDataIn = v34 + 1;
    }
    else if ( v34 <= v35 )
    {
      p2->m_nInBufWord = *v34;
      p2->m_pDataIn = v34 + 1;
    }
    else
    {
      p2->m_bOverflow = true;
      p2->m_nInBufWord = 0;
    }
    goto LABEL_56;
  }
  v33 = v30 >> v29;
LABEL_55:
  p2->m_nInBufWord = v33;
LABEL_56:
  highInt2 = v31;
LABEL_57:
  v42 = p2->m_nBitsAvail;
  if ( v42 >= 32 )
  {
    v43 = p2->m_nInBufWord;
    p2->m_nBitsAvail = v42 - 32;
    if ( v42 == 32 )
    {
      v45 = p2->m_pDataIn;
      v46 = p2->m_pBufferEnd;
      p2->m_nBitsAvail = 32;
      if ( v45 == v46 )
      {
        p2->m_nBitsAvail = 1;
        p2->m_nInBufWord = 0;
        p2->m_pDataIn = v45 + 1;
        v44 = v43;
      }
      else
      {
        if ( v45 <= v46 )
        {
          p2->m_nInBufWord = *v45;
          p2->m_pDataIn = v45 + 1;
        }
        else
        {
          p2->m_bOverflow = true;
          p2->m_nInBufWord = 0;
        }
        v44 = v43;
      }
    }
    else
    {
      p2->m_nInBufWord = 0;
      v44 = v43;
    }
    return highInt1 != highInt2 || lowInt1 != v44;
  }
  v47 = p2->m_pDataIn;
  v48 = p2->m_nInBufWord;
  v49 = 32 - v42;
  v50 = p2->m_pBufferEnd;
  if ( v47 == v50 )
  {
    p2->m_nBitsAvail = 1;
    p2->m_nInBufWord = 0;
    p2->m_bOverflow = true;
  }
  else
  {
    if ( v47 > v50 )
    {
      p2->m_bOverflow = true;
      p2->m_nInBufWord = 0;
      goto LABEL_72;
    }
    p2->m_nInBufWord = *v47;
  }
  p2->m_pDataIn = v47 + 1;
LABEL_72:
  if ( p2->m_bOverflow )
  {
    v44 = 0;
  }
  else
  {
    v51 = p2->m_nInBufWord;
    v52 = (v51 & CBitBuffer::s_nMaskTable[v49]) << p2->m_nBitsAvail;
    p2->m_nBitsAvail = 32 - v49;
    v44 = v52 | v48;
    p2->m_nInBufWord = v51 >> v49;
  }
  return highInt1 != highInt2 || lowInt1 != v44;
}

//------------------------------------------------------------------------------
// Address: 0x1016BCC0
// Name: char const __near * Int64_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Int64_GetTypeNameString()
{
  return "DPT_Int64";
}

//------------------------------------------------------------------------------
// Address: 0x1016BCD0
// Name: bool Int64_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Int64_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return pVar->m_Int64 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016BCF0
// Name: void Int64_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int64_DecodeZero(DecodeInfo *pInfo)
{
  const RecvProp *m_pRecvProp; // ecx

  m_pRecvProp = pInfo->m_pRecvProp;
  pInfo->m_Value.m_Int64 = 0;
  if ( m_pRecvProp != nullptr )
    m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016BD20
// Name: bool Int64_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Int64_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  int m_nBitsAvail; // ecx
  int v3; // edx
  unsigned int v4; // esi
  unsigned int v5; // edi
  int v6; // ecx
  unsigned int v7; // esi
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // esi
  unsigned int v17; // ecx
  int v18; // edi
  const unsigned int *v19; // edx
  const unsigned int *v20; // esi
  const unsigned int *v21; // ecx
  unsigned int v22; // edi
  int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // esi
  unsigned int v26; // ebx
  unsigned int highInt1; // [esp+14h] [ebp+8h]

  m_nBitsAvail = pIn->m_nBitsAvail;
  v3 = pProp->m_nBits - 32;
  if ( m_nBitsAvail < v3 )
  {
    m_pBufferEnd = pIn->m_pBufferEnd;
    m_nInBufWord = pIn->m_nInBufWord;
    v12 = v3 - m_nBitsAvail;
    m_pDataIn = pIn->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
LABEL_15:
        if ( pIn->m_bOverflow )
        {
          highInt1 = 0;
          goto LABEL_20;
        }
        v14 = pIn->m_nInBufWord;
        v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << pIn->m_nBitsAvail;
        pIn->m_nBitsAvail = 32 - v12;
        v5 = v15 | m_nInBufWord;
        v7 = v14 >> v12;
        goto LABEL_18;
      }
      pIn->m_nInBufWord = *m_pDataIn;
    }
    pIn->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v4 = pIn->m_nInBufWord;
  v5 = v4 & CBitBuffer::s_nMaskTable[v3];
  v6 = m_nBitsAvail - v3;
  pIn->m_nBitsAvail = v6;
  if ( v6 == 0 )
  {
    v8 = pIn->m_pDataIn;
    v9 = pIn->m_pBufferEnd;
    pIn->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      pIn->m_nInBufWord = *v8;
      pIn->m_pDataIn = v8 + 1;
    }
    else
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v7 = v4 >> v3;
LABEL_18:
  pIn->m_nInBufWord = v7;
LABEL_19:
  highInt1 = v5;
LABEL_20:
  v16 = pIn->m_nBitsAvail;
  if ( v16 >= 32 )
  {
    v17 = pIn->m_nInBufWord;
    pIn->m_nBitsAvail = v16 - 32;
    if ( v16 == 32 )
    {
      v19 = pIn->m_pDataIn;
      v20 = pIn->m_pBufferEnd;
      pIn->m_nBitsAvail = 32;
      if ( v19 == v20 )
      {
        pIn->m_nBitsAvail = 1;
        pIn->m_nInBufWord = 0;
        pIn->m_pDataIn = v19 + 1;
        v18 = v17;
      }
      else
      {
        if ( v19 <= v20 )
        {
          pIn->m_nInBufWord = *v19;
          pIn->m_pDataIn = v19 + 1;
        }
        else
        {
          pIn->m_bOverflow = true;
          pIn->m_nInBufWord = 0;
        }
        v18 = v17;
      }
    }
    else
    {
      pIn->m_nInBufWord = 0;
      v18 = v17;
    }
    return highInt1 == 0 && v18 == 0;
  }
  v21 = pIn->m_pDataIn;
  v22 = pIn->m_nInBufWord;
  v23 = 32 - v16;
  v24 = pIn->m_pBufferEnd;
  if ( v21 == v24 )
  {
    pIn->m_nBitsAvail = 1;
    pIn->m_nInBufWord = 0;
    pIn->m_bOverflow = true;
  }
  else
  {
    if ( v21 > v24 )
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
      goto LABEL_35;
    }
    pIn->m_nInBufWord = *v21;
  }
  pIn->m_pDataIn = v21 + 1;
LABEL_35:
  if ( pIn->m_bOverflow )
  {
    v18 = 0;
  }
  else
  {
    v25 = pIn->m_nInBufWord;
    v26 = (v25 & CBitBuffer::s_nMaskTable[v23]) << pIn->m_nBitsAvail;
    pIn->m_nBitsAvail = 32 - v23;
    v18 = v26 | v22;
    pIn->m_nInBufWord = v25 >> v23;
  }
  return highInt1 == 0 && v18 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016BEF0
// Name: void Generic_FastCopy(class SendProp const __near *,class RecvProp const __near *,unsigned char const __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Generic_FastCopy(
        const SendProp *pSendProp,
        const RecvProp *pRecvProp,
        const unsigned __int8 *pSendData,
        unsigned __int8 *pRecvData,
        int objectID)
{
  void (__cdecl *m_ProxyFn)(const SendProp *, const void *, const void *, DVariant *, int, int); // eax
  void (__cdecl *v6)(const CRecvProxyData *, void *, void *); // edx
  unsigned __int8 *v7; // [esp-1Ch] [ebp-48h]
  const unsigned __int8 *v8; // [esp-10h] [ebp-3Ch]
  CRecvProxyData recvProxyData; // [esp+4h] [ebp-28h] BYREF

  v8 = &pSendData[pSendProp->m_Offset & 0xFFFFF];
  m_ProxyFn = pSendProp->m_ProxyFn;
  recvProxyData.m_Value.m_Type = DPT_Float;
  m_ProxyFn(a1: pSendProp, a2: pSendData, a3: v8, a4: &recvProxyData.m_Value, a5: 0, a6: objectID);
  v7 = &pRecvData[pRecvProp->m_Offset];
  v6 = pRecvProp->m_ProxyFn;
  recvProxyData.m_pRecvProp = pRecvProp;
  recvProxyData.m_iElement = 0;
  recvProxyData.m_ObjectID = objectID;
  v6(a1: &recvProxyData, a2: pRecvData, a3: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1016BF50
// Name: void Int_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int_SkipProp(const SendProp *pProp, bf_read *pIn)
{
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax

  m_pData = pIn->m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
    if ( m_nDataBits >= pIn->m_nDataBits )
      m_nDataBits = pIn->m_nDataBits;
    CBitRead::Seek(this: pIn, nPosition: pProp->m_nBits + m_nDataBits);
  }
  else
  {
    CBitRead::Seek(this: pIn, nPosition: pProp->m_nBits);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016BFA0
// Name: void Float_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Float_SkipProp(const SendProp *pProp, bf_read *pIn)
{
  int m_Flags; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v10; // edx
  const unsigned int *v11; // esi
  unsigned int v12; // edi
  int v13; // edx
  const unsigned int *v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  int v17; // esi
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx
  const unsigned int *v20; // eax
  int v21; // eax
  const unsigned int *v22; // eax
  int v23; // eax
  int m_nBits; // esi
  const unsigned int *v25; // eax
  int v26; // eax

  m_Flags = pProp->m_Flags;
  if ( (m_Flags & 2) != 0 )
  {
    m_nBitsAvail = pIn->m_nBitsAvail;
    if ( m_nBitsAvail >= 2 )
    {
      m_nInBufWord = pIn->m_nInBufWord;
      v5 = m_nInBufWord & 3;
      v6 = m_nBitsAvail - 2;
      pIn->m_nBitsAvail = v6;
      if ( v6 != 0 )
      {
        pIn->m_nInBufWord = m_nInBufWord >> 2;
        v7 = m_nInBufWord & 3;
      }
      else
      {
        m_pDataIn = pIn->m_pDataIn;
        m_pBufferEnd = pIn->m_pBufferEnd;
        pIn->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          pIn->m_pDataIn = m_pDataIn + 1;
          pIn->m_nBitsAvail = 1;
          pIn->m_nInBufWord = 0;
          v7 = v5;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            v10 = *m_pDataIn;
            pIn->m_pDataIn = m_pDataIn + 1;
            pIn->m_nInBufWord = v10;
          }
          else
          {
            pIn->m_bOverflow = true;
            pIn->m_nInBufWord = 0;
          }
          v7 = v5;
        }
      }
LABEL_19:
      if ( v7 != 0 )
      {
        v17 = 1;
        if ( (v7 & 1) != 0 )
          v17 = 15;
        if ( (v7 & 2) != 0 )
          v17 += 5;
        m_pData = pIn->m_pData;
        if ( m_pData != nullptr )
        {
          m_nDataBits = 32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
          if ( m_nDataBits >= pIn->m_nDataBits )
            m_nDataBits = pIn->m_nDataBits;
          CBitRead::Seek(this: pIn, nPosition: v17 + m_nDataBits);
        }
        else
        {
          CBitRead::Seek(this: pIn, nPosition: v17);
        }
      }
      return;
    }
    v11 = pIn->m_pBufferEnd;
    v12 = pIn->m_nInBufWord;
    v13 = 2 - m_nBitsAvail;
    v14 = pIn->m_pDataIn;
    if ( v14 == v11 )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_bOverflow = true;
    }
    else
    {
      if ( v14 > v11 )
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
LABEL_17:
        if ( pIn->m_bOverflow )
          return;
        v15 = pIn->m_nInBufWord;
        v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << pIn->m_nBitsAvail;
        pIn->m_nBitsAvail = 32 - v13;
        v7 = v16 | v12;
        pIn->m_nInBufWord = v15 >> v13;
        goto LABEL_19;
      }
      pIn->m_nInBufWord = *v14;
    }
    pIn->m_pDataIn = v14 + 1;
    goto LABEL_17;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_None);
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_LowPrecision);
  }
  else if ( (m_Flags & 0x4000) != 0 )
  {
    CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_Integral);
  }
  else if ( (m_Flags & 4) != 0 )
  {
    v20 = pIn->m_pData;
    if ( v20 != nullptr )
    {
      v21 = 32 * (pIn->m_pDataIn - v20) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
      if ( v21 >= pIn->m_nDataBits )
        v21 = pIn->m_nDataBits;
      CBitRead::Seek(this: pIn, nPosition: v21 + 32);
    }
    else
    {
      CBitRead::Seek(this: pIn, nPosition: 32);
    }
  }
  else if ( (m_Flags & 0x20) != 0 )
  {
    v22 = pIn->m_pData;
    if ( v22 != nullptr )
    {
      v23 = 32 * (pIn->m_pDataIn - v22) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
      if ( v23 >= pIn->m_nDataBits )
        v23 = pIn->m_nDataBits;
      CBitRead::Seek(this: pIn, nPosition: v23 + 12);
    }
    else
    {
      CBitRead::Seek(this: pIn, nPosition: 12);
    }
  }
  else if ( (m_Flags & 0x8000) != 0 )
  {
    CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_None);
  }
  else if ( (m_Flags & 0x10000) != 0 )
  {
    CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_LowPrecision);
  }
  else if ( (m_Flags & 0x20000) != 0 )
  {
    CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_Integral);
  }
  else
  {
    m_nBits = pProp->m_nBits;
    v25 = pIn->m_pData;
    if ( v25 != nullptr )
    {
      v26 = 32 * (pIn->m_pDataIn - v25) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
      if ( v26 >= pIn->m_nDataBits )
        v26 = pIn->m_nDataBits;
      CBitRead::Seek(this: pIn, nPosition: m_nBits + v26);
    }
    else
    {
      CBitRead::Seek(this: pIn, nPosition: m_nBits);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C270
// Name: void Vector_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector_Encode(
        const unsigned __int8 *pStruct,
        DVariant *pVar,
        const SendProp *pProp,
        bf_write *pOut,
        DVariant *objectID)
{
  BOOL v5; // eax
  int m_iCurBit; // ecx
  unsigned __int8 *m_pData; // esi

  EncodeFloat(pProp, fVal: pVar->m_Float, pOut, (int)objectID);
  EncodeFloat(pProp, fVal: pVar->m_Vector[1], pOut, (int)objectID);
  if ( (pProp->m_Flags & 0x20) != 0 )
  {
    v5 = pVar->m_Vector[2] <= -0.0004885197850512946;
    m_iCurBit = pOut->m_iCurBit;
    if ( m_iCurBit + 1 > pOut->m_nDataBits )
      pOut->m_bOverflow = true;
    if ( !pOut->m_bOverflow )
    {
      m_pData = pOut->m_pData;
      if ( v5 )
        m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      else
        m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++pOut->m_iCurBit;
    }
  }
  else
  {
    EncodeFloat(pProp, fVal: pVar->m_Vector[2], pOut, (int)objectID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C330
// Name: void Vector_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector_SkipProp(const SendProp *pProp, bf_read *pIn)
{
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax

  Float_SkipProp(pProp, pIn);
  Float_SkipProp(pProp, pIn);
  if ( (pProp->m_Flags & 0x20) != 0 )
  {
    m_pData = pIn->m_pData;
    if ( m_pData != nullptr )
    {
      m_nDataBits = 32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
      if ( m_nDataBits >= pIn->m_nDataBits )
        m_nDataBits = pIn->m_nDataBits;
      CBitRead::Seek(this: pIn, nPosition: m_nDataBits + 1);
    }
    else
    {
      CBitRead::Seek(this: pIn, nPosition: 1);
    }
  }
  else
  {
    Float_SkipProp(pProp, pIn);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C3B0
// Name: void VectorXY_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorXY_SkipProp(const SendProp *pProp, bf_read *pIn)
{
  Float_SkipProp(pProp, pIn);
  Float_SkipProp(pProp, pIn);
}

//------------------------------------------------------------------------------
// Address: 0x1016C3D0
// Name: int String_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl String_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  int m_nBitsAvail; // ecx
  unsigned int v5; // esi
  int v6; // ebx
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v11; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // edi
  const unsigned int *v18; // eax
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edi
  int v21; // eax
  const unsigned int *v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ebx
  const unsigned int *m_pData; // eax
  const unsigned int *m_nDataBits; // eax
  unsigned int v28; // [esp+Ch] [ebp-4h]
  bf_read *p1a; // [esp+1Ch] [ebp+Ch]

  m_nBitsAvail = p1->m_nBitsAvail;
  if ( m_nBitsAvail < 9 )
  {
    m_pBufferEnd = p1->m_pBufferEnd;
    m_nInBufWord = p1->m_nInBufWord;
    v11 = 9 - m_nBitsAvail;
    m_pDataIn = p1->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
        goto LABEL_16;
      }
      p1->m_nInBufWord = *m_pDataIn;
    }
    p1->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( p1->m_bOverflow )
    {
      v6 = 0;
      p1a = nullptr;
    }
    else
    {
      v13 = p1->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << p1->m_nBitsAvail;
      p1->m_nBitsAvail = 32 - v11;
      v6 = v14 | m_nInBufWord;
      p1a = (bf_read *)v6;
      p1->m_nInBufWord = v13 >> v11;
    }
    goto LABEL_19;
  }
  v5 = p1->m_nInBufWord;
  p1->m_nBitsAvail = m_nBitsAvail - 9;
  if ( m_nBitsAvail == 9 )
  {
    v7 = p1->m_pDataIn;
    v8 = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      p1->m_nInBufWord = 0;
      v6 = v5 & 0x1FF;
      p1->m_nBitsAvail = 1;
      p1->m_pDataIn = v7 + 1;
      p1a = (bf_read *)v6;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v6 = v5 & 0x1FF;
        p1->m_nInBufWord = *v7;
        p1->m_pDataIn = v7 + 1;
      }
      else
      {
        p1->m_nInBufWord = 0;
        v6 = v5 & 0x1FF;
        p1->m_bOverflow = true;
      }
      p1a = (bf_read *)(v5 & 0x1FF);
    }
  }
  else
  {
    v6 = v5 & 0x1FF;
    p1->m_nInBufWord = v5 >> 9;
    p1a = (bf_read *)v6;
  }
LABEL_19:
  v15 = p2->m_nBitsAvail;
  v16 = p2->m_nInBufWord;
  if ( v15 >= 9 )
  {
    v17 = p2->m_nInBufWord & 0x1FF;
    p2->m_nBitsAvail = v15 - 9;
    if ( v15 == 9 )
    {
      v18 = p2->m_pDataIn;
      v19 = p2->m_pBufferEnd;
      p2->m_nBitsAvail = 32;
      if ( v18 == v19 )
      {
        p2->m_nBitsAvail = 1;
        p2->m_nInBufWord = 0;
        p2->m_pDataIn = v18 + 1;
      }
      else if ( v18 <= v19 )
      {
        p2->m_nInBufWord = *v18;
        p2->m_pDataIn = v18 + 1;
      }
      else
      {
        p2->m_bOverflow = true;
        p2->m_nInBufWord = 0;
      }
    }
    else
    {
      p2->m_nInBufWord = v16 >> 9;
    }
    goto LABEL_36;
  }
  v20 = p2->m_pBufferEnd;
  v28 = p2->m_nInBufWord;
  v21 = 9 - v15;
  v22 = p2->m_pDataIn;
  if ( v22 == v20 )
  {
    p2->m_nBitsAvail = 1;
    p2->m_nInBufWord = 0;
    p2->m_bOverflow = true;
  }
  else
  {
    if ( v22 > v20 )
    {
      p2->m_bOverflow = true;
      p2->m_nInBufWord = 0;
      goto LABEL_33;
    }
    p2->m_nInBufWord = *v22;
  }
  p2->m_pDataIn = v22 + 1;
LABEL_33:
  if ( p2->m_bOverflow )
  {
    v17 = 0;
  }
  else
  {
    v23 = p2->m_nInBufWord;
    v24 = (v23 & CBitBuffer::s_nMaskTable[v21]) << p2->m_nBitsAvail;
    p2->m_nBitsAvail = 32 - v21;
    p2->m_nInBufWord = v23 >> v21;
    v17 = v24 | v28;
    v6 = (int)p1a;
  }
LABEL_36:
  if ( v6 == v17 )
  {
    if ( v6 != 0 )
      return AreBitsDifferent(pBuf1: p1, pBuf2: p2, nBits: 8 * v6);
    else
      return 0;
  }
  else
  {
    m_pData = p1->m_pData;
    if ( m_pData != nullptr )
    {
      m_pData = (const unsigned int *)(32 * (p1->m_pDataIn - m_pData) - p1->m_nBitsAvail + 8 * (p1->m_nDataBytes & 3));
      if ( (int)m_pData >= p1->m_nDataBits )
        m_pData = (const unsigned int *)p1->m_nDataBits;
    }
    CBitRead::Seek(this: p1, nPosition: (int)&m_pData[2 * v6]);
    m_nDataBits = p2->m_pData;
    if ( m_nDataBits != nullptr )
    {
      m_nDataBits = (const unsigned int *)(32 * (p2->m_pDataIn - m_nDataBits)
                                         - p2->m_nBitsAvail
                                         + 8 * (p2->m_nDataBytes & 3));
      if ( (int)m_nDataBits >= p2->m_nDataBits )
        m_nDataBits = (const unsigned int *)p2->m_nDataBits;
    }
    CBitRead::Seek(this: p2, nPosition: (int)&m_nDataBits[2 * v17]);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C670
// Name: bool String_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl String_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v8; // edx
  const unsigned int *v9; // esi
  unsigned int v10; // edi
  int v11; // edx
  const unsigned int *v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  const unsigned int *m_pData; // ecx

  m_nBitsAvail = pIn->m_nBitsAvail;
  if ( m_nBitsAvail >= 9 )
  {
    m_nInBufWord = pIn->m_nInBufWord;
    v4 = m_nInBufWord & 0x1FF;
    v5 = m_nBitsAvail - 9;
    pIn->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      pIn->m_nInBufWord = m_nInBufWord >> 9;
    }
    else
    {
      m_pDataIn = pIn->m_pDataIn;
      m_pBufferEnd = pIn->m_pBufferEnd;
      pIn->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pIn->m_nBitsAvail = 1;
        pIn->m_nInBufWord = 0;
        pIn->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v8 = *m_pDataIn;
        pIn->m_pDataIn = m_pDataIn + 1;
        pIn->m_nInBufWord = v8;
      }
      else
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
      }
    }
    goto LABEL_18;
  }
  v9 = pIn->m_pBufferEnd;
  v10 = pIn->m_nInBufWord;
  v11 = 9 - m_nBitsAvail;
  v12 = pIn->m_pDataIn;
  if ( v12 == v9 )
  {
    pIn->m_nBitsAvail = 1;
    pIn->m_nInBufWord = 0;
    pIn->m_bOverflow = true;
  }
  else
  {
    if ( v12 > v9 )
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
      goto LABEL_15;
    }
    pIn->m_nInBufWord = *v12;
  }
  pIn->m_pDataIn = v12 + 1;
LABEL_15:
  if ( pIn->m_bOverflow )
  {
    v4 = 0;
  }
  else
  {
    v13 = pIn->m_nInBufWord;
    v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << pIn->m_nBitsAvail;
    pIn->m_nBitsAvail = 32 - v11;
    pIn->m_nInBufWord = v13 >> v11;
    v4 = v14 | v10;
  }
LABEL_18:
  m_pData = pIn->m_pData;
  if ( m_pData != nullptr )
  {
    m_pData = (const unsigned int *)(32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3));
    if ( (int)m_pData >= pIn->m_nDataBits )
      m_pData = (const unsigned int *)pIn->m_nDataBits;
  }
  CBitRead::Seek(this: pIn, nPosition: (int)&m_pData[2 * v4]);
  return v4 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016C7A0
// Name: void String_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl String_SkipProp(const SendProp *pProp, bf_read *pIn)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v8; // edx
  const unsigned int *v9; // esi
  unsigned int v10; // edi
  int v11; // edx
  const unsigned int *v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = pIn->m_nBitsAvail;
  if ( m_nBitsAvail >= 9 )
  {
    m_nInBufWord = pIn->m_nInBufWord;
    v4 = m_nInBufWord & 0x1FF;
    v5 = m_nBitsAvail - 9;
    pIn->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      pIn->m_nInBufWord = m_nInBufWord >> 9;
    }
    else
    {
      m_pDataIn = pIn->m_pDataIn;
      m_pBufferEnd = pIn->m_pBufferEnd;
      pIn->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pIn->m_nBitsAvail = 1;
        pIn->m_nInBufWord = 0;
        pIn->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v8 = *m_pDataIn;
        pIn->m_pDataIn = m_pDataIn + 1;
        pIn->m_nInBufWord = v8;
      }
      else
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
      }
    }
    goto LABEL_18;
  }
  v9 = pIn->m_pBufferEnd;
  v10 = pIn->m_nInBufWord;
  v11 = 9 - m_nBitsAvail;
  v12 = pIn->m_pDataIn;
  if ( v12 == v9 )
  {
    pIn->m_nBitsAvail = 1;
    pIn->m_nInBufWord = 0;
    pIn->m_bOverflow = true;
  }
  else
  {
    if ( v12 > v9 )
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
      goto LABEL_15;
    }
    pIn->m_nInBufWord = *v12;
  }
  pIn->m_pDataIn = v12 + 1;
LABEL_15:
  if ( pIn->m_bOverflow )
  {
    v4 = 0;
  }
  else
  {
    v13 = pIn->m_nInBufWord;
    v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << pIn->m_nBitsAvail;
    pIn->m_nBitsAvail = 32 - v11;
    pIn->m_nInBufWord = v13 >> v11;
    v4 = v14 | v10;
  }
LABEL_18:
  m_pData = pIn->m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
    if ( m_nDataBits >= pIn->m_nDataBits )
      m_nDataBits = pIn->m_nDataBits;
    CBitRead::Seek(this: pIn, nPosition: m_nDataBits + 8 * v4);
  }
  else
  {
    CBitRead::Seek(this: pIn, nPosition: 8 * v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C8E0
// Name: void Array_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Array_Decode(SendProp *pInfo)
{
  SendProp *v2; // ebx
  char *m_pExcludeDTName; // ecx
  const RecvProp *v4; // eax
  char *m_pParentArrayPropName; // ecx
  void (__cdecl *m_ArrayLengthProxy)(void *, int, int); // edx
  signed int NumArrayLengthBits; // eax
  bf_read *m_fHighLowMul_low; // edx
  signed int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edi
  unsigned int v11; // ebx
  int v12; // ecx
  const unsigned int *v13; // eax
  const unsigned int *v14; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edi
  int v17; // edi
  DecodeInfo subDecodeInfo; // [esp+Ch] [ebp-248h] BYREF
  unsigned int v19; // [esp+244h] [ebp-10h]
  int elementStride; // [esp+248h] [ebp-Ch]
  void (__cdecl *lengthProxy)(void *, int, int); // [esp+24Ch] [ebp-8h]
  unsigned int v22; // [esp+250h] [ebp-4h]
  SendProp *pArrayProp; // [esp+25Ch] [ebp+8h]

  v2 = *((SendProp **)pInfo->m_pVarName + 6);
  m_pExcludeDTName = pInfo->m_pExcludeDTName;
  v4 = (const RecvProp *)pInfo->__vftable;
  subDecodeInfo.m_pIn = (bf_read *)LODWORD(pInfo->m_fHighLowMul);
  subDecodeInfo.m_ObjectID = pInfo->m_ElementStride;
  subDecodeInfo.m_iElement = pInfo->m_nElements;
  subDecodeInfo.m_pStruct = m_pExcludeDTName;
  m_pParentArrayPropName = pInfo->m_pParentArrayPropName;
  pArrayProp = v2;
  subDecodeInfo.m_Value.m_Type = DPT_Float;
  subDecodeInfo.m_pData = m_pParentArrayPropName;
  subDecodeInfo.m_pRecvProp = v4;
  subDecodeInfo.m_pProp = v2;
  elementStride = 0;
  lengthProxy = nullptr;
  if ( v4 != nullptr )
  {
    subDecodeInfo.m_pRecvProp = v4->m_pArrayProp;
    subDecodeInfo.m_pData = &m_pParentArrayPropName[subDecodeInfo.m_pRecvProp->m_Offset];
    m_ArrayLengthProxy = v4->m_ArrayLengthProxy;
    elementStride = v4->m_ElementStride;
    lengthProxy = m_ArrayLengthProxy;
  }
  NumArrayLengthBits = SendProp::GetNumArrayLengthBits(this: (SendProp *)pInfo->m_pVarName);
  m_fHighLowMul_low = (bf_read *)LODWORD(pInfo->m_fHighLowMul);
  m_nBitsAvail = m_fHighLowMul_low->m_nBitsAvail;
  m_nInBufWord = m_fHighLowMul_low->m_nInBufWord;
  if ( m_nBitsAvail < NumArrayLengthBits )
  {
    NumArrayLengthBits -= m_nBitsAvail;
    m_pDataIn = m_fHighLowMul_low->m_pDataIn;
    v19 = m_fHighLowMul_low->m_nInBufWord;
    m_pBufferEnd = m_fHighLowMul_low->m_pBufferEnd;
    if ( m_pDataIn == m_pBufferEnd )
    {
      m_fHighLowMul_low->m_nBitsAvail = 1;
      m_fHighLowMul_low->m_nInBufWord = 0;
      m_fHighLowMul_low->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        m_fHighLowMul_low->m_bOverflow = true;
        m_fHighLowMul_low->m_nInBufWord = 0;
LABEL_16:
        if ( m_fHighLowMul_low->m_bOverflow )
        {
          v17 = 0;
          goto LABEL_21;
        }
        m_nInBufWord = m_fHighLowMul_low->m_nInBufWord;
        v22 = (m_nInBufWord & CBitBuffer::s_nMaskTable[NumArrayLengthBits]) << m_fHighLowMul_low->m_nBitsAvail;
        v11 = v22 | v19;
        m_fHighLowMul_low->m_nBitsAvail = 32 - NumArrayLengthBits;
        goto LABEL_19;
      }
      m_fHighLowMul_low->m_nInBufWord = *m_pDataIn;
    }
    m_fHighLowMul_low->m_pDataIn = m_pDataIn + 1;
    goto LABEL_16;
  }
  v11 = m_nInBufWord & CBitBuffer::s_nMaskTable[NumArrayLengthBits];
  v12 = m_nBitsAvail - NumArrayLengthBits;
  m_fHighLowMul_low->m_nBitsAvail = v12;
  if ( v12 == 0 )
  {
    v13 = m_fHighLowMul_low->m_pDataIn;
    v14 = m_fHighLowMul_low->m_pBufferEnd;
    m_fHighLowMul_low->m_nBitsAvail = 32;
    if ( v13 == v14 )
    {
      m_fHighLowMul_low->m_nBitsAvail = 1;
      m_fHighLowMul_low->m_nInBufWord = 0;
      m_fHighLowMul_low->m_pDataIn = v13 + 1;
    }
    else if ( v13 <= v14 )
    {
      m_fHighLowMul_low->m_nInBufWord = *v13;
      m_fHighLowMul_low->m_pDataIn = v13 + 1;
    }
    else
    {
      m_fHighLowMul_low->m_bOverflow = true;
      m_fHighLowMul_low->m_nInBufWord = 0;
    }
    goto LABEL_20;
  }
LABEL_19:
  m_fHighLowMul_low->m_nInBufWord = m_nInBufWord >> NumArrayLengthBits;
LABEL_20:
  v17 = v11;
  v2 = pArrayProp;
LABEL_21:
  if ( lengthProxy != nullptr )
    lengthProxy(a1: pInfo->m_pExcludeDTName, a2: pInfo->m_ElementStride, a3: v17);
  for ( subDecodeInfo.m_iElement = 0; subDecodeInfo.m_iElement < v17; ++subDecodeInfo.m_iElement )
  {
    (*(&funcs_1016CA94 + 9 * v2->m_Type))(pInfo: &subDecodeInfo);
    subDecodeInfo.m_pData = (char *)subDecodeInfo.m_pData + elementStride;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CAC0
// Name: void Int64_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int64_Encode(const unsigned __int8 *pStruct, DVariant *pVar, const SendProp *pProp, bf_write *pOut)
{
  unsigned int m_Int; // ecx
  int v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // edi
  int m_iCurBit; // ecx
  char v9; // dl

  m_Int = pVar->m_Int;
  v5 = LODWORD(pVar->m_Vector[1]);
  if ( v5 < 0 )
  {
    m_Int = -m_Int;
    v9 = 1;
    v5 = (unsigned __int64)-__SPAIR64__(v5, m_Int) >> 32;
  }
  else
  {
    v9 = 0;
  }
  v6 = v5;
  v7 = m_Int;
  if ( (pProp->m_Flags & 1) != 0 )
  {
    bf_write::WriteUBitLong(this: pOut, curData: m_Int, numbits: 32, bCheckRange: true);
    bf_write::WriteUBitLong(this: pOut, curData: v6, numbits: pProp->m_nBits - 32, bCheckRange: true);
  }
  else
  {
    m_iCurBit = pOut->m_iCurBit;
    if ( m_iCurBit + 1 > pOut->m_nDataBits )
      pOut->m_bOverflow = true;
    if ( !pOut->m_bOverflow )
    {
      if ( v9 != 0 )
        pOut->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      else
        pOut->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++pOut->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: pOut, curData: v7, numbits: 32, bCheckRange: true);
    bf_write::WriteUBitLong(this: pOut, curData: v6, numbits: pProp->m_nBits - 33, bCheckRange: true);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101691A0
// Name: EncodeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall EncodeFloat(const SendProp *pProp@<esi>, float fVal, bf_write *pOut, int objectID)
{
  float m_fLowValue; // xmm1_4
  unsigned int v5; // edi
  const char *v6; // eax
  const char *ObjectClassName; // eax
  char *v8; // [esp+8h] [ebp-18h]
  char *m_pVarName; // [esp+8h] [ebp-18h]

  if ( !EncodeSpecialFloat(pProp, fVal, pOut) )
  {
    m_fLowValue = pProp->m_fLowValue;
    if ( m_fLowValue <= fVal )
    {
      if ( fVal <= pProp->m_fHighValue )
      {
        v5 = (__int64)(float)((float)(fVal - m_fLowValue) * pProp->m_fHighLowMul);
      }
      else
      {
        v5 = (1 << pProp->m_nBits) - 1;
        if ( (pProp->m_Flags & 8) == 0 )
        {
          m_pVarName = pProp->m_pVarName;
          ObjectClassName = GetObjectClassName(objectID);
          DataTable_Warning(
            pInMessage: "%s: Out-of-range value (%f) in SendPropFloat '%s', clamping.\n",
            ObjectClassName,
            fVal,
            m_pVarName);
        }
      }
    }
    else
    {
      v5 = 0;
      if ( (pProp->m_Flags & 0x10) == 0 )
      {
        v8 = pProp->m_pVarName;
        v6 = GetObjectClassName(objectID);
        DataTable_Warning(
          pInMessage: "(class %s): Out-of-range value (%f) in SendPropFloat '%s', clamping.\n",
          v6,
          fVal,
          v8);
      }
    }
    bf_write::WriteUBitLong(this: pOut, curData: v5, numbits: pProp->m_nBits, bCheckRange: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169270
// Name: DecodeSpecialFloat
// Source: json
//------------------------------------------------------------------------------
char __usercall DecodeSpecialFloat@<al>(const SendProp *pProp@<edx>, bf_read *pIn@<eax>, float *fVal)
{
  int m_Flags; // ecx
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v9; // ecx
  int v10; // edx
  const unsigned int *v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // esi
  unsigned int v14; // ebx
  double BitCellCoord; // st7
  int v16; // [esp+0h] [ebp-4h]

  m_Flags = pProp->m_Flags;
  if ( (m_Flags & 2) != 0 )
  {
    *fVal = CBitRead::ReadBitCoord(this: pIn);
    return 1;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    *fVal = CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_None);
    return 1;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    *fVal = CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_LowPrecision);
    return 1;
  }
  if ( (m_Flags & 0x4000) != 0 )
  {
    *fVal = CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_Integral);
    return 1;
  }
  if ( (m_Flags & 4) != 0 )
  {
    m_nBitsAvail = pIn->m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = pIn->m_nInBufWord;
      pIn->m_nBitsAvail = m_nBitsAvail - 32;
      if ( m_nBitsAvail == 32 )
      {
        m_pDataIn = pIn->m_pDataIn;
        m_pBufferEnd = pIn->m_pBufferEnd;
        pIn->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          pIn->m_nBitsAvail = 1;
          pIn->m_nInBufWord = 0;
          pIn->m_pDataIn = m_pDataIn + 1;
          v16 = m_nInBufWord;
LABEL_27:
          *(_DWORD *)fVal = v16;
          return 1;
        }
        if ( m_pDataIn <= m_pBufferEnd )
        {
          pIn->m_nInBufWord = *m_pDataIn;
          pIn->m_pDataIn = m_pDataIn + 1;
          v16 = m_nInBufWord;
          goto LABEL_27;
        }
        pIn->m_bOverflow = true;
      }
      pIn->m_nInBufWord = 0;
      v16 = m_nInBufWord;
      goto LABEL_27;
    }
    v9 = pIn->m_pDataIn;
    v10 = 32 - m_nBitsAvail;
    v11 = pIn->m_pBufferEnd;
    v12 = pIn->m_nInBufWord;
    if ( v9 == v11 )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_bOverflow = true;
    }
    else
    {
      if ( v9 > v11 )
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
        goto LABEL_24;
      }
      pIn->m_nInBufWord = *v9;
    }
    pIn->m_pDataIn = v9 + 1;
LABEL_24:
    if ( pIn->m_bOverflow )
    {
      v16 = 0;
    }
    else
    {
      v13 = pIn->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v10]) << pIn->m_nBitsAvail;
      pIn->m_nBitsAvail = 32 - v10;
      v16 = v14 | v12;
      pIn->m_nInBufWord = v13 >> v10;
    }
    goto LABEL_27;
  }
  if ( (m_Flags & 0x20) != 0 )
  {
    *fVal = CBitRead::ReadBitNormal(this: pIn);
    return 1;
  }
  if ( (m_Flags & 0x8000) != 0 )
  {
    BitCellCoord = CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_None);
LABEL_32:
    *fVal = BitCellCoord;
    return 1;
  }
  if ( (m_Flags & 0x10000) != 0 )
  {
    BitCellCoord = CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_LowPrecision);
    goto LABEL_32;
  }
  if ( (m_Flags & 0x20000) != 0 )
  {
    BitCellCoord = CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_Integral);
    goto LABEL_32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10169430
// Name: DecodeFloat
// Source: json
//------------------------------------------------------------------------------
double __usercall DecodeFloat@<st0>(bf_read *pIn@<esi>, const SendProp *pProp)
{
  const SendProp *v2; // ebx
  int m_nBits; // eax
  int m_nBitsAvail; // ecx
  unsigned int v6; // edx
  unsigned int v7; // edi
  int v8; // ecx
  const unsigned int *v9; // eax
  const unsigned int *v10; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v13; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  double m_fLowValue; // st7
  int fVal; // [esp+0h] [ebp-4h] BYREF

  v2 = pProp;
  *(float *)&fVal = 0.0;
  if ( DecodeSpecialFloat(pProp, pIn, (float *)&fVal) != 0 )
    return *(float *)&fVal;
  m_nBits = pProp->m_nBits;
  m_nBitsAvail = pIn->m_nBitsAvail;
  if ( m_nBitsAvail < m_nBits )
  {
    m_pBufferEnd = pIn->m_pBufferEnd;
    m_nInBufWord = pIn->m_nInBufWord;
    v13 = m_nBits - m_nBitsAvail;
    m_pDataIn = pIn->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
LABEL_17:
        if ( pIn->m_bOverflow )
        {
          v7 = 0;
        }
        else
        {
          v15 = pIn->m_nInBufWord;
          v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << pIn->m_nBitsAvail;
          pIn->m_nBitsAvail = 32 - v13;
          v7 = v16 | m_nInBufWord;
          pIn->m_nInBufWord = v15 >> v13;
        }
        v2 = pProp;
        goto LABEL_21;
      }
      pIn->m_nInBufWord = *m_pDataIn;
    }
    pIn->m_pDataIn = m_pDataIn + 1;
    goto LABEL_17;
  }
  v6 = pIn->m_nInBufWord;
  v7 = v6 & CBitBuffer::s_nMaskTable[m_nBits];
  v8 = m_nBitsAvail - m_nBits;
  pIn->m_nBitsAvail = v8;
  if ( v8 != 0 )
  {
    pIn->m_nInBufWord = v6 >> m_nBits;
  }
  else
  {
    v9 = pIn->m_pDataIn;
    v10 = pIn->m_pBufferEnd;
    pIn->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_pDataIn = v9 + 1;
    }
    else if ( v9 <= v10 )
    {
      pIn->m_nInBufWord = *v9;
      pIn->m_pDataIn = v9 + 1;
    }
    else
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
    }
  }
LABEL_21:
  m_fLowValue = v2->m_fLowValue;
  fVal = v7;
  fVal = (1 << v2->m_nBits) - 1;
  return m_fLowValue + (double)v7 / (double)fVal * (v2->m_fHighValue - m_fLowValue);
}

//------------------------------------------------------------------------------
// Address: 0x10169570
// Name: DecodeVector
// Source: json
//------------------------------------------------------------------------------
void __usercall DecodeVector(const SendProp *pProp@<ecx>, bf_read *pIn@<eax>, float *v)
{
  unsigned int m_nInBufWord; // eax
  int v7; // edx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  float v0v0v1v1; // [esp+14h] [ebp+8h]

  *v = DecodeFloat(pIn, pProp);
  v[1] = DecodeFloat(pIn, pProp);
  if ( (pProp->m_Flags & 0x20) != 0 )
  {
    m_nInBufWord = pIn->m_nInBufWord;
    v7 = m_nInBufWord & 1;
    if ( pIn->m_nBitsAvail-- == 1 )
    {
      m_pDataIn = pIn->m_pDataIn;
      pIn->m_nBitsAvail = 32;
      m_pBufferEnd = pIn->m_pBufferEnd;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pIn->m_nBitsAvail = 1;
        pIn->m_nInBufWord = 0;
        pIn->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        pIn->m_nInBufWord = *m_pDataIn;
        pIn->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
      }
    }
    else
    {
      pIn->m_nInBufWord = m_nInBufWord >> 1;
    }
    v0v0v1v1 = (float)(*v * *v) + (float)(v[1] * v[1]);
    if ( v0v0v1v1 >= 1.0 )
      v[2] = 0.0;
    else
      v[2] = sqrt(1.0 - v0v0v1v1);
    if ( v7 != 0 )
      v[2] = v[2] * -1.0;
  }
  else
  {
    v[2] = DecodeFloat(pIn, pProp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169650
// Name: void Int_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int_Encode(const unsigned __int8 *pStruct, DVariant *pVar, const SendProp *pProp, bf_write *pOut)
{
  int m_Int; // ecx

  m_Int = pVar->m_Int;
  if ( (pProp->m_Flags & 1) != 0 )
    bf_write::WriteUBitLong(this: pOut, curData: m_Int, numbits: pProp->m_nBits, bCheckRange: true);
  else
    bf_write::WriteSBitLong(this: pOut, data: m_Int, numbits: pProp->m_nBits);
}

//------------------------------------------------------------------------------
// Address: 0x10169690
// Name: void Int_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int_Decode(DecodeInfo *pInfo)
{
  const SendProp *m_pProp; // eax
  int v2; // edx
  bf_read *v3; // eax
  int v4; // ecx
  unsigned int v5; // esi
  unsigned int v6; // edi
  int v7; // ecx
  DecodeInfo *v8; // ecx
  const unsigned int *v9; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // edx
  const unsigned int *v12; // esi
  unsigned int v13; // edi
  int v14; // edx
  const unsigned int *v15; // ecx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  int m_nBits; // edi
  bf_read *m_pIn; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  unsigned int v22; // esi
  int v23; // ecx
  int v24; // eax
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v27; // edx
  const unsigned int *v28; // esi
  int v29; // edx
  const unsigned int *v30; // ecx
  unsigned int v31; // esi
  unsigned int v32; // ebx
  unsigned int v33; // [esp+Ch] [ebp-8h]

  m_pProp = pInfo->m_pProp;
  if ( (m_pProp->m_Flags & 1) == 0 )
  {
    m_nBits = m_pProp->m_nBits;
    m_pIn = pInfo->m_pIn;
    m_nBitsAvail = m_pIn->m_nBitsAvail;
    m_nInBufWord = m_pIn->m_nInBufWord;
    if ( m_nBitsAvail >= m_nBits )
    {
      v22 = m_nInBufWord & CBitBuffer::s_nMaskTable[m_nBits];
      v23 = m_nBitsAvail - m_nBits;
      m_pIn->m_nBitsAvail = v23;
      if ( v23 != 0 )
      {
        m_pIn->m_nInBufWord = m_nInBufWord >> m_nBits;
        v24 = v22;
      }
      else
      {
        m_pDataIn = m_pIn->m_pDataIn;
        m_pBufferEnd = m_pIn->m_pBufferEnd;
        m_pIn->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          m_pIn->m_nBitsAvail = 1;
          m_pIn->m_nInBufWord = 0;
          m_pIn->m_pDataIn = m_pDataIn + 1;
          v24 = v22;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            v27 = *m_pDataIn;
            m_pIn->m_pDataIn = m_pDataIn + 1;
            m_pIn->m_nInBufWord = v27;
          }
          else
          {
            m_pIn->m_bOverflow = true;
            m_pIn->m_nInBufWord = 0;
          }
          v24 = v22;
        }
      }
      goto LABEL_38;
    }
    v28 = m_pIn->m_pBufferEnd;
    v33 = m_pIn->m_nInBufWord;
    v29 = m_nBits - m_nBitsAvail;
    v30 = m_pIn->m_pDataIn;
    if ( v30 == v28 )
    {
      m_pIn->m_nBitsAvail = 1;
      m_pIn->m_nInBufWord = 0;
      m_pIn->m_bOverflow = true;
    }
    else
    {
      if ( v30 > v28 )
      {
        m_pIn->m_bOverflow = true;
        m_pIn->m_nInBufWord = 0;
        goto LABEL_35;
      }
      m_pIn->m_nInBufWord = *v30;
    }
    m_pIn->m_pDataIn = v30 + 1;
LABEL_35:
    if ( m_pIn->m_bOverflow )
    {
      v24 = 0;
    }
    else
    {
      v31 = m_pIn->m_nInBufWord;
      v32 = (v31 & CBitBuffer::s_nMaskTable[v29]) << m_pIn->m_nBitsAvail;
      m_pIn->m_nBitsAvail = 32 - v29;
      m_pIn->m_nInBufWord = v31 >> v29;
      v24 = v32 | v33;
    }
LABEL_38:
    v8 = pInfo;
    pInfo->m_Value.m_Int = v24 << (32 - m_nBits) >> (32 - m_nBits);
    goto LABEL_39;
  }
  v2 = m_pProp->m_nBits;
  v3 = pInfo->m_pIn;
  v4 = v3->m_nBitsAvail;
  if ( v4 < v2 )
  {
    v12 = v3->m_pBufferEnd;
    v13 = v3->m_nInBufWord;
    v14 = v2 - v4;
    v15 = v3->m_pDataIn;
    if ( v15 == v12 )
    {
      v3->m_nBitsAvail = 1;
      v3->m_nInBufWord = 0;
      v3->m_bOverflow = true;
    }
    else
    {
      if ( v15 > v12 )
      {
        v3->m_bOverflow = true;
        v3->m_nInBufWord = 0;
        goto LABEL_17;
      }
      v3->m_nInBufWord = *v15;
    }
    v3->m_pDataIn = v15 + 1;
LABEL_17:
    if ( v3->m_bOverflow )
    {
      v8 = pInfo;
      pInfo->m_Value.m_Int = 0;
    }
    else
    {
      v16 = v3->m_nInBufWord;
      v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << v3->m_nBitsAvail;
      v3->m_nBitsAvail = 32 - v14;
      v8 = pInfo;
      v3->m_nInBufWord = v16 >> v14;
      pInfo->m_Value.m_Int = v17 | v13;
    }
    goto LABEL_39;
  }
  v5 = v3->m_nInBufWord;
  v6 = v5 & CBitBuffer::s_nMaskTable[v2];
  v7 = v4 - v2;
  v3->m_nBitsAvail = v7;
  if ( v7 != 0 )
  {
    v8 = pInfo;
    v3->m_nInBufWord = v5 >> v2;
    pInfo->m_Value.m_Int = v6;
  }
  else
  {
    v9 = v3->m_pDataIn;
    v10 = v3->m_pBufferEnd;
    v3->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      v3->m_pDataIn = v9 + 1;
      v8 = pInfo;
      v3->m_nBitsAvail = 1;
      v3->m_nInBufWord = 0;
      pInfo->m_Value.m_Int = v6;
    }
    else
    {
      if ( v9 <= v10 )
      {
        v11 = *v9;
        v3->m_pDataIn = v9 + 1;
        v8 = pInfo;
        v3->m_nInBufWord = v11;
      }
      else
      {
        v8 = pInfo;
        v3->m_bOverflow = true;
        v3->m_nInBufWord = 0;
      }
      v8->m_Value.m_Int = v6;
    }
  }
LABEL_39:
  if ( v8->m_pRecvProp != nullptr )
    v8->m_pRecvProp->m_ProxyFn(a1: v8, a2: v8->m_pStruct, a3: v8->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x101698E0
// Name: int Int_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Int_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  int m_nBits; // edx
  int m_nBitsAvail; // ecx
  unsigned int v5; // esi
  unsigned int v6; // edi
  int v7; // ecx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  const unsigned int *m_pDataIn; // ecx
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // edi
  int v17; // ecx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edx
  const unsigned int *v21; // esi
  unsigned int v22; // edi
  const unsigned int *v23; // ecx
  bf_read *p1a; // [esp+18h] [ebp+Ch]

  m_nBits = pProp->m_nBits;
  m_nBitsAvail = p1->m_nBitsAvail;
  if ( m_nBitsAvail < m_nBits )
  {
    m_pBufferEnd = p1->m_pBufferEnd;
    m_nInBufWord = p1->m_nInBufWord;
    m_nBits -= m_nBitsAvail;
    m_pDataIn = p1->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
LABEL_14:
        if ( p1->m_bOverflow )
        {
          p1a = nullptr;
          goto LABEL_19;
        }
        v5 = p1->m_nInBufWord;
        v6 = ((v5 & CBitBuffer::s_nMaskTable[m_nBits]) << p1->m_nBitsAvail) | m_nInBufWord;
        p1->m_nBitsAvail = 32 - m_nBits;
        goto LABEL_17;
      }
      p1->m_nInBufWord = *m_pDataIn;
    }
    p1->m_pDataIn = m_pDataIn + 1;
    goto LABEL_14;
  }
  v5 = p1->m_nInBufWord;
  v6 = v5 & CBitBuffer::s_nMaskTable[m_nBits];
  v7 = m_nBitsAvail - m_nBits;
  p1->m_nBitsAvail = v7;
  if ( v7 == 0 )
  {
    v8 = p1->m_pDataIn;
    v9 = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      p1->m_nInBufWord = *v8;
      p1->m_pDataIn = v8 + 1;
    }
    else
    {
      p1->m_bOverflow = true;
      p1->m_nInBufWord = 0;
    }
    goto LABEL_18;
  }
LABEL_17:
  p1->m_nInBufWord = v5 >> m_nBits;
LABEL_18:
  p1a = (bf_read *)v6;
LABEL_19:
  v13 = pProp->m_nBits;
  v14 = p2->m_nBitsAvail;
  if ( v14 < v13 )
  {
    v21 = p2->m_pBufferEnd;
    v22 = p2->m_nInBufWord;
    v13 -= v14;
    v23 = p2->m_pDataIn;
    if ( v23 == v21 )
    {
      p2->m_nBitsAvail = 1;
      p2->m_nInBufWord = 0;
      p2->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v21 )
      {
        p2->m_bOverflow = true;
        p2->m_nInBufWord = 0;
LABEL_33:
        if ( p2->m_bOverflow )
          return p1a != nullptr;
        v15 = p2->m_nInBufWord;
        v16 = ((v15 & CBitBuffer::s_nMaskTable[v13]) << p2->m_nBitsAvail) | v22;
        p2->m_nBitsAvail = 32 - v13;
        goto LABEL_36;
      }
      p2->m_nInBufWord = *v23;
    }
    p2->m_pDataIn = v23 + 1;
    goto LABEL_33;
  }
  v15 = p2->m_nInBufWord;
  v16 = v15 & CBitBuffer::s_nMaskTable[v13];
  v17 = v14 - v13;
  p2->m_nBitsAvail = v17;
  if ( v17 != 0 )
  {
LABEL_36:
    p2->m_nInBufWord = v15 >> v13;
    return p1a != (bf_read *)v16;
  }
  v18 = p2->m_pDataIn;
  v19 = p2->m_pBufferEnd;
  p2->m_nBitsAvail = 32;
  if ( v18 == v19 )
  {
    p2->m_nBitsAvail = 1;
    p2->m_nInBufWord = 0;
    p2->m_pDataIn = v18 + 1;
    return p1a != (bf_read *)v16;
  }
  else
  {
    if ( v18 <= v19 )
    {
      p2->m_nInBufWord = *v18;
      p2->m_pDataIn = v18 + 1;
    }
    else
    {
      p2->m_bOverflow = true;
      p2->m_nInBufWord = 0;
    }
    return p1a != (bf_read *)v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169AE0
// Name: char const __near * Int_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Int_GetTypeNameString()
{
  return "DPT_Int";
}

//------------------------------------------------------------------------------
// Address: 0x10169AF0
// Name: bool Int_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Int_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return pVar->m_Int == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10169B00
// Name: void Int_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int_DecodeZero(DecodeInfo *pInfo)
{
  const RecvProp *m_pRecvProp; // ecx

  m_pRecvProp = pInfo->m_pRecvProp;
  pInfo->m_Value.m_Int = 0;
  if ( m_pRecvProp != nullptr )
    m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x10169B30
// Name: bool Int_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Int_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  int m_nBits; // edx
  int m_nBitsAvail; // ecx
  unsigned int v4; // esi
  unsigned int v5; // edi
  int v6; // ecx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx

  m_nBits = pProp->m_nBits;
  m_nBitsAvail = pIn->m_nBitsAvail;
  if ( m_nBitsAvail < m_nBits )
  {
    m_pBufferEnd = pIn->m_pBufferEnd;
    m_nInBufWord = pIn->m_nInBufWord;
    v12 = m_nBits - m_nBitsAvail;
    m_pDataIn = pIn->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
        goto LABEL_16;
      }
      pIn->m_nInBufWord = *m_pDataIn;
    }
    pIn->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( pIn->m_bOverflow )
      return 1;
    v14 = pIn->m_nInBufWord;
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << pIn->m_nBitsAvail;
    pIn->m_nBitsAvail = 32 - v12;
    pIn->m_nInBufWord = v14 >> v12;
    return (v15 | m_nInBufWord) == 0;
  }
  v4 = pIn->m_nInBufWord;
  v5 = v4 & CBitBuffer::s_nMaskTable[m_nBits];
  v6 = m_nBitsAvail - m_nBits;
  pIn->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    pIn->m_nInBufWord = v4 >> m_nBits;
    return v5 == 0;
  }
  else
  {
    v8 = pIn->m_pDataIn;
    v9 = pIn->m_pBufferEnd;
    pIn->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_pDataIn = v8 + 1;
      return v5 == 0;
    }
    else
    {
      if ( v8 <= v9 )
      {
        pIn->m_nInBufWord = *v8;
        pIn->m_pDataIn = v8 + 1;
      }
      else
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
      }
      return v5 == 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169C50
// Name: void Float_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Float_Encode(
        const unsigned __int8 *pStruct,
        DVariant *pVar,
        const SendProp *pProp,
        bf_write *pOut,
        DVariant *objectID)
{
  EncodeFloat(pProp, fVal: pVar->m_Float, pOut, (int)objectID);
}

//------------------------------------------------------------------------------
// Address: 0x10169C80
// Name: void Float_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Float_Decode(DecodeInfo *pInfo)
{
  pInfo->m_Value.m_Float = DecodeFloat(pIn: pInfo->m_pIn, pProp: pInfo->m_pProp);
  if ( pInfo->m_pRecvProp != nullptr )
    pInfo->m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x10169CC0
// Name: int Float_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Float_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  int m_Flags; // eax
  double BitCoord; // st7
  double v6; // st6
  int v8; // esi
  unsigned int v9; // ecx
  const unsigned int *v10; // edx
  const unsigned int *v11; // esi
  const unsigned int *v12; // ecx
  unsigned int v13; // edi
  int v14; // edx
  const unsigned int *v15; // esi
  unsigned int v16; // esi
  unsigned int v17; // ebx
  bf_read *v18; // eax
  int v19; // esi
  unsigned int v20; // ecx
  const unsigned int *v21; // edx
  const unsigned int *v22; // esi
  const unsigned int *v23; // ecx
  unsigned int v24; // edi
  int v25; // edx
  const unsigned int *v26; // esi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v29; // esi
  int v30; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v33; // edx
  const unsigned int *v34; // esi
  unsigned int v35; // edi
  int v36; // edx
  const unsigned int *v37; // ecx
  unsigned int v38; // esi
  unsigned int v39; // ebx
  int v40; // ecx
  unsigned int v41; // edx
  int v42; // edi
  int v43; // ecx
  const unsigned int *v44; // ecx
  const unsigned int *v45; // edx
  unsigned int v46; // edx
  const unsigned int *v47; // esi
  const unsigned int *v48; // ecx
  unsigned int v49; // esi
  unsigned int v50; // ebx
  double BitCellCoord; // st7
  double v52; // st6
  int m_nBits; // edx
  int v54; // ecx
  unsigned int v55; // esi
  unsigned int v56; // edi
  int v57; // ecx
  const unsigned int *v58; // ecx
  const unsigned int *v59; // edx
  const unsigned int *v60; // esi
  unsigned int v61; // edi
  const unsigned int *v62; // ecx
  int v63; // edx
  int v64; // ecx
  unsigned int v65; // esi
  unsigned int v66; // edi
  int v67; // ecx
  const unsigned int *v68; // ecx
  const unsigned int *v69; // edx
  const unsigned int *v70; // esi
  unsigned int v71; // edi
  const unsigned int *v72; // ecx
  unsigned int v73; // [esp+4h] [ebp-4h]
  float pPropb; // [esp+10h] [ebp+8h]
  float pPropc; // [esp+10h] [ebp+8h]
  float pPropd; // [esp+10h] [ebp+8h]
  float pPrope; // [esp+10h] [ebp+8h]
  const SendProp *pPropa; // [esp+10h] [ebp+8h]
  float pPropf; // [esp+10h] [ebp+8h]
  float pPropg; // [esp+10h] [ebp+8h]
  float pProph; // [esp+10h] [ebp+8h]

  m_Flags = pProp->m_Flags;
  if ( (m_Flags & 2) != 0 )
  {
    pPropb = CBitRead::ReadBitCoord(this: p1);
    BitCoord = CBitRead::ReadBitCoord(this: p2);
    v6 = pPropb;
    return v6 != BitCoord;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    pPropc = CBitRead::ReadBitCoordMP(this: p1, coordType: kCW_None);
    BitCoord = CBitRead::ReadBitCoordMP(this: p2, coordType: kCW_None);
    v6 = pPropc;
    return v6 != BitCoord;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    pPropd = CBitRead::ReadBitCoordMP(this: p1, coordType: kCW_LowPrecision);
    BitCoord = CBitRead::ReadBitCoordMP(this: p2, coordType: kCW_LowPrecision);
    v6 = pPropd;
    return v6 != BitCoord;
  }
  if ( (m_Flags & 0x4000) != 0 )
  {
    pPrope = CBitRead::ReadBitCoordMP(this: p1, coordType: kCW_Integral);
    BitCoord = CBitRead::ReadBitCoordMP(this: p2, coordType: kCW_Integral);
    v6 = pPrope;
    return v6 != BitCoord;
  }
  if ( (m_Flags & 4) == 0 )
  {
    if ( (m_Flags & 0x20) != 0 )
    {
      m_nBitsAvail = p1->m_nBitsAvail;
      if ( m_nBitsAvail >= 12 )
      {
        m_nInBufWord = p1->m_nInBufWord;
        v29 = m_nInBufWord & 0xFFF;
        v30 = m_nBitsAvail - 12;
        p1->m_nBitsAvail = v30;
        if ( v30 != 0 )
        {
          p1->m_nInBufWord = m_nInBufWord >> 12;
          pPropa = (const SendProp *)(m_nInBufWord & 0xFFF);
        }
        else
        {
          m_pDataIn = p1->m_pDataIn;
          m_pBufferEnd = p1->m_pBufferEnd;
          p1->m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            p1->m_nBitsAvail = 1;
            p1->m_nInBufWord = 0;
            p1->m_pDataIn = m_pDataIn + 1;
            pPropa = (const SendProp *)v29;
          }
          else
          {
            if ( m_pDataIn <= m_pBufferEnd )
            {
              v33 = *m_pDataIn;
              p1->m_pDataIn = m_pDataIn + 1;
              p1->m_nInBufWord = v33;
            }
            else
            {
              p1->m_bOverflow = true;
              p1->m_nInBufWord = 0;
            }
            pPropa = (const SendProp *)v29;
          }
        }
LABEL_64:
        v18 = p2;
        v40 = p2->m_nBitsAvail;
        if ( v40 >= 12 )
        {
          v41 = p2->m_nInBufWord;
          v42 = v41 & 0xFFF;
          v43 = v40 - 12;
          p2->m_nBitsAvail = v43;
          if ( v43 != 0 )
          {
            p2->m_nInBufWord = v41 >> 12;
            return pPropa != (const SendProp *)v42;
          }
          else
          {
            v44 = p2->m_pDataIn;
            v45 = p2->m_pBufferEnd;
            p2->m_nBitsAvail = 32;
            if ( v44 == v45 )
            {
              p2->m_nBitsAvail = 1;
              p2->m_nInBufWord = 0;
              p2->m_pDataIn = v44 + 1;
              return pPropa != (const SendProp *)v42;
            }
            else
            {
              if ( v44 <= v45 )
              {
                v46 = *v44;
                p2->m_pDataIn = v44 + 1;
                p2->m_nInBufWord = v46;
              }
              else
              {
                p2->m_bOverflow = true;
                p2->m_nInBufWord = 0;
              }
              return pPropa != (const SendProp *)v42;
            }
          }
        }
        v47 = p2->m_pBufferEnd;
        v24 = p2->m_nInBufWord;
        v25 = 12 - v40;
        v48 = p2->m_pDataIn;
        if ( v48 == v47 )
        {
          p2->m_nBitsAvail = 1;
          p2->m_nInBufWord = 0;
          p2->m_bOverflow = true;
        }
        else
        {
          if ( v48 > v47 )
          {
            p2->m_bOverflow = true;
            p2->m_nInBufWord = 0;
            goto LABEL_79;
          }
          p2->m_nInBufWord = *v48;
        }
        p2->m_pDataIn = v48 + 1;
LABEL_79:
        if ( p2->m_bOverflow )
          return pPropa != nullptr;
        goto LABEL_81;
      }
      v34 = p1->m_pBufferEnd;
      v35 = p1->m_nInBufWord;
      v36 = 12 - m_nBitsAvail;
      v37 = p1->m_pDataIn;
      if ( v37 == v34 )
      {
        p1->m_nBitsAvail = 1;
        p1->m_nInBufWord = 0;
        p1->m_bOverflow = true;
      }
      else
      {
        if ( v37 > v34 )
        {
          p1->m_bOverflow = true;
          p1->m_nInBufWord = 0;
          goto LABEL_61;
        }
        p1->m_nInBufWord = *v37;
      }
      p1->m_pDataIn = v37 + 1;
LABEL_61:
      if ( p1->m_bOverflow )
      {
        pPropa = nullptr;
      }
      else
      {
        v38 = p1->m_nInBufWord;
        v39 = (v38 & CBitBuffer::s_nMaskTable[v36]) << p1->m_nBitsAvail;
        p1->m_nBitsAvail = 32 - v36;
        pPropa = (const SendProp *)(v39 | v35);
        p1->m_nInBufWord = v38 >> v36;
      }
      goto LABEL_64;
    }
    if ( (m_Flags & 0x8000) != 0 )
    {
      pPropf = CBitRead::ReadBitCellCoord(this: p1, bits: pProp->m_nBits, coordType: kCW_None);
      BitCellCoord = CBitRead::ReadBitCellCoord(this: p2, bits: pProp->m_nBits, coordType: kCW_None);
      v52 = pPropf;
      return v52 != BitCellCoord;
    }
    if ( (m_Flags & 0x10000) != 0 )
    {
      pPropg = CBitRead::ReadBitCellCoord(this: p1, bits: pProp->m_nBits, coordType: kCW_LowPrecision);
      BitCellCoord = CBitRead::ReadBitCellCoord(this: p2, bits: pProp->m_nBits, coordType: kCW_LowPrecision);
      v52 = pPropg;
      return v52 != BitCellCoord;
    }
    if ( (m_Flags & 0x20000) != 0 )
    {
      pProph = CBitRead::ReadBitCellCoord(this: p1, bits: pProp->m_nBits, coordType: kCW_Integral);
      BitCellCoord = CBitRead::ReadBitCellCoord(this: p2, bits: pProp->m_nBits, coordType: kCW_Integral);
      v52 = pProph;
      return v52 != BitCellCoord;
    }
    m_nBits = pProp->m_nBits;
    v54 = p1->m_nBitsAvail;
    if ( v54 >= m_nBits )
    {
      v55 = p1->m_nInBufWord;
      v56 = v55 & CBitBuffer::s_nMaskTable[m_nBits];
      v57 = v54 - m_nBits;
      p1->m_nBitsAvail = v57;
      if ( v57 == 0 )
      {
        v58 = p1->m_pDataIn;
        v59 = p1->m_pBufferEnd;
        p1->m_nBitsAvail = 32;
        if ( v58 == v59 )
        {
          p1->m_nBitsAvail = 1;
          p1->m_nInBufWord = 0;
          p1->m_pDataIn = v58 + 1;
        }
        else if ( v58 <= v59 )
        {
          p1->m_nInBufWord = *v58;
          p1->m_pDataIn = v58 + 1;
        }
        else
        {
          p1->m_bOverflow = true;
          p1->m_nInBufWord = 0;
        }
        goto LABEL_106;
      }
LABEL_105:
      p1->m_nInBufWord = v55 >> m_nBits;
LABEL_106:
      v73 = v56;
LABEL_107:
      v63 = pProp->m_nBits;
      v64 = p2->m_nBitsAvail;
      if ( v64 >= v63 )
      {
        v65 = p2->m_nInBufWord;
        v66 = v65 & CBitBuffer::s_nMaskTable[v63];
        v67 = v64 - v63;
        p2->m_nBitsAvail = v67;
        if ( v67 == 0 )
        {
          v68 = p2->m_pDataIn;
          v69 = p2->m_pBufferEnd;
          p2->m_nBitsAvail = 32;
          if ( v68 == v69 )
          {
            p2->m_nBitsAvail = 1;
            p2->m_nInBufWord = 0;
            p2->m_pDataIn = v68 + 1;
            return v73 != v66;
          }
          else
          {
            if ( v68 <= v69 )
            {
              p2->m_nInBufWord = *v68;
              p2->m_pDataIn = v68 + 1;
            }
            else
            {
              p2->m_bOverflow = true;
              p2->m_nInBufWord = 0;
            }
            return v73 != v66;
          }
        }
LABEL_124:
        p2->m_nInBufWord = v65 >> v63;
        return v73 != v66;
      }
      v70 = p2->m_pBufferEnd;
      v71 = p2->m_nInBufWord;
      v63 -= v64;
      v72 = p2->m_pDataIn;
      if ( v72 == v70 )
      {
        p2->m_nBitsAvail = 1;
        p2->m_nInBufWord = 0;
        p2->m_bOverflow = true;
      }
      else
      {
        if ( v72 > v70 )
        {
          p2->m_bOverflow = true;
          p2->m_nInBufWord = 0;
LABEL_121:
          if ( p2->m_bOverflow )
            return v73 != 0;
          v65 = p2->m_nInBufWord;
          v66 = ((v65 & CBitBuffer::s_nMaskTable[v63]) << p2->m_nBitsAvail) | v71;
          p2->m_nBitsAvail = 32 - v63;
          goto LABEL_124;
        }
        p2->m_nInBufWord = *v72;
      }
      p2->m_pDataIn = v72 + 1;
      goto LABEL_121;
    }
    v60 = p1->m_pBufferEnd;
    v61 = p1->m_nInBufWord;
    m_nBits -= v54;
    v62 = p1->m_pDataIn;
    if ( v62 == v60 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( v62 > v60 )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
LABEL_102:
        if ( p1->m_bOverflow )
        {
          v73 = 0;
          goto LABEL_107;
        }
        v55 = p1->m_nInBufWord;
        v56 = ((v55 & CBitBuffer::s_nMaskTable[m_nBits]) << p1->m_nBitsAvail) | v61;
        p1->m_nBitsAvail = 32 - m_nBits;
        goto LABEL_105;
      }
      p1->m_nInBufWord = *v62;
    }
    p1->m_pDataIn = v62 + 1;
    goto LABEL_102;
  }
  v8 = p1->m_nBitsAvail;
  if ( v8 < 32 )
  {
    v12 = p1->m_pDataIn;
    v13 = p1->m_nInBufWord;
    v14 = 32 - v8;
    v15 = p1->m_pBufferEnd;
    if ( v12 == v15 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( v12 > v15 )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
        goto LABEL_26;
      }
      p1->m_nInBufWord = *v12;
    }
    p1->m_pDataIn = v12 + 1;
LABEL_26:
    if ( p1->m_bOverflow )
    {
      pPropa = nullptr;
    }
    else
    {
      v16 = p1->m_nInBufWord;
      v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << p1->m_nBitsAvail;
      p1->m_nBitsAvail = 32 - v14;
      pPropa = (const SendProp *)(v17 | v13);
      p1->m_nInBufWord = v16 >> v14;
    }
    goto LABEL_29;
  }
  v9 = p1->m_nInBufWord;
  p1->m_nBitsAvail = v8 - 32;
  if ( v8 == 32 )
  {
    v10 = p1->m_pDataIn;
    v11 = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( v10 == v11 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_pDataIn = v10 + 1;
      pPropa = (const SendProp *)v9;
    }
    else
    {
      if ( v10 <= v11 )
      {
        p1->m_nInBufWord = *v10;
        p1->m_pDataIn = v10 + 1;
      }
      else
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
      }
      pPropa = (const SendProp *)v9;
    }
  }
  else
  {
    p1->m_nInBufWord = 0;
    pPropa = (const SendProp *)v9;
  }
LABEL_29:
  v18 = p2;
  v19 = p2->m_nBitsAvail;
  if ( v19 < 32 )
  {
    v23 = p2->m_pDataIn;
    v24 = p2->m_nInBufWord;
    v25 = 32 - v19;
    v26 = p2->m_pBufferEnd;
    if ( v23 == v26 )
    {
      p2->m_nBitsAvail = 1;
      p2->m_nInBufWord = 0;
      p2->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v26 )
      {
        p2->m_bOverflow = true;
        p2->m_nInBufWord = 0;
        goto LABEL_43;
      }
      p2->m_nInBufWord = *v23;
    }
    p2->m_pDataIn = v23 + 1;
LABEL_43:
    if ( p2->m_bOverflow )
      return pPropa != nullptr;
LABEL_81:
    v49 = v18->m_nInBufWord;
    v50 = (v49 & CBitBuffer::s_nMaskTable[v25]) << v18->m_nBitsAvail;
    v18->m_nBitsAvail = 32 - v25;
    v18->m_nInBufWord = v49 >> v25;
    return pPropa != (const SendProp *)(v50 | v24);
  }
  v20 = p2->m_nInBufWord;
  p2->m_nBitsAvail = v19 - 32;
  if ( v19 != 32 )
  {
LABEL_35:
    p2->m_nInBufWord = 0;
    return pPropa != (const SendProp *)v20;
  }
  v21 = p2->m_pDataIn;
  v22 = p2->m_pBufferEnd;
  p2->m_nBitsAvail = 32;
  if ( v21 == v22 )
  {
    p2->m_nInBufWord = 0;
    p2->m_nBitsAvail = 1;
    p2->m_pDataIn = v21 + 1;
    return pPropa != (const SendProp *)v20;
  }
  if ( v21 > v22 )
  {
    p2->m_bOverflow = true;
    goto LABEL_35;
  }
  p2->m_nInBufWord = *v21;
  p2->m_pDataIn = v21 + 1;
  return pPropa != (const SendProp *)v20;
}

//------------------------------------------------------------------------------
// Address: 0x1016A3F0
// Name: char const __near * Float_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Float_GetTypeNameString()
{
  return "DPT_Float";
}

//------------------------------------------------------------------------------
// Address: 0x1016A400
// Name: bool Float_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Float_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return pVar->m_Float == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A430
// Name: void Float_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Float_DecodeZero(DecodeInfo *pInfo)
{
  const RecvProp *m_pRecvProp; // ecx

  m_pRecvProp = pInfo->m_pRecvProp;
  pInfo->m_Value.m_Int = 0;
  if ( m_pRecvProp != nullptr )
    m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016A460
// Name: bool Float_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Float_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  return DecodeFloat(pIn, pProp) == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A490
// Name: void Vector_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector_Decode(DecodeInfo *pInfo)
{
  DecodeVector(pProp: pInfo->m_pProp, pIn: pInfo->m_pIn, v: &pInfo->m_Value.m_Float);
  if ( pInfo->m_pRecvProp != nullptr )
    pInfo->m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016A4D0
// Name: int Vector_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Vector_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  unsigned int m_nInBufWord; // eax
  int v5; // ebx
  bool v6; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v9; // eax
  int v10; // esi
  const unsigned int *v11; // eax
  const unsigned int *v12; // ecx
  unsigned int v14; // edx
  BOOL c1; // [esp+Ch] [ebp-4h]
  BOOL c2; // [esp+18h] [ebp+8h]

  c1 = Float_CompareDeltas(pProp, p1, p2);
  c2 = Float_CompareDeltas(pProp, p1, p2);
  if ( (pProp->m_Flags & 0x20) == 0 )
    return c1 | c2 | Float_CompareDeltas(pProp, p1, p2);
  m_nInBufWord = p1->m_nInBufWord;
  v5 = m_nInBufWord & 1;
  v6 = p1->m_nBitsAvail-- == 1;
  if ( v6 )
  {
    m_pDataIn = p1->m_pDataIn;
    m_pBufferEnd = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      p1->m_nInBufWord = *m_pDataIn;
      p1->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      p1->m_bOverflow = true;
      p1->m_nInBufWord = 0;
    }
  }
  else
  {
    p1->m_nInBufWord = m_nInBufWord >> 1;
  }
  v9 = p2->m_nInBufWord;
  v10 = v9 & 1;
  v6 = p2->m_nBitsAvail-- == 1;
  if ( v6 )
  {
    v11 = p2->m_pDataIn;
    v12 = p2->m_pBufferEnd;
    p2->m_nBitsAvail = 32;
    if ( v11 == v12 )
    {
      p2->m_pDataIn = v11 + 1;
      p2->m_nBitsAvail = 1;
      p2->m_nInBufWord = 0;
      return c1 || c2 || v5 != v10;
    }
    else
    {
      if ( v11 <= v12 )
      {
        v14 = *v11;
        p2->m_pDataIn = v11 + 1;
        p2->m_nInBufWord = v14;
      }
      else
      {
        p2->m_bOverflow = true;
        p2->m_nInBufWord = 0;
      }
      return c1 || c2 || v5 != v10;
    }
  }
  else
  {
    p2->m_nInBufWord = v9 >> 1;
    return c1 || c2 || v5 != v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016A620
// Name: bool Vector_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Vector_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return pVar->m_Float == 0.0 && pVar->m_Vector[1] == 0.0 && pVar->m_Vector[2] == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A660
// Name: void Vector_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector_DecodeZero(DecodeInfo *pInfo)
{
  const RecvProp *m_pRecvProp; // ecx

  m_pRecvProp = pInfo->m_pRecvProp;
  pInfo->m_Value.m_Int64 = 0;
  pInfo->m_Value.m_Vector[2] = 0.0;
  if ( m_pRecvProp != nullptr )
    m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016A700
// Name: void VectorXY_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorXY_Encode(
        const unsigned __int8 *pStruct,
        DVariant *pVar,
        const SendProp *pProp,
        bf_write *pOut,
        DVariant *objectID)
{
  EncodeFloat(pProp, fVal: pVar->m_Float, pOut, (int)objectID);
  EncodeFloat(pProp, fVal: pVar->m_Vector[1], pOut, (int)objectID);
}

//------------------------------------------------------------------------------
// Address: 0x1016A790
// Name: int VectorXY_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorXY_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  BOOL c1; // [esp+Ch] [ebp-4h]

  c1 = Float_CompareDeltas(pProp, p1, p2);
  return c1 | Float_CompareDeltas(pProp, p1, p2);
}

//------------------------------------------------------------------------------
// Address: 0x1016A7C0
// Name: char const __near * VectorXY_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl VectorXY_GetTypeNameString()
{
  return "DPT_VectorXY";
}

//------------------------------------------------------------------------------
// Address: 0x1016A7D0
// Name: bool VectorXY_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VectorXY_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return pVar->m_Float == 0.0 && pVar->m_Vector[1] == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A800
// Name: void VectorXY_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorXY_DecodeZero(DecodeInfo *pInfo)
{
  const RecvProp *m_pRecvProp; // ecx

  m_pRecvProp = pInfo->m_pRecvProp;
  pInfo->m_Value.m_Int64 = 0;
  if ( m_pRecvProp != nullptr )
    m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016A830
// Name: bool VectorXY_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VectorXY_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  float v; // [esp+8h] [ebp-8h]
  float v_4; // [esp+Ch] [ebp-4h]

  v = DecodeFloat(pIn, pProp);
  v_4 = DecodeFloat(pIn, pProp);
  return v == 0.0 && v_4 == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A890
// Name: void String_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl String_Encode(const unsigned __int8 *pStruct, DVariant *pVar, const SendProp *pProp, bf_write *pOut)
{
  int i; // esi
  bf_write *v5; // edi
  int m_iCurBit; // eax
  int m_nDataBits; // ecx
  int v8; // edx
  int v9; // eax

  for ( i = 0; i < 511; ++i )
  {
    if ( *(_BYTE *)(pVar->m_Int + i) == 0 )
      break;
  }
  v5 = pOut;
  m_iCurBit = pOut->m_iCurBit;
  m_nDataBits = pOut->m_nDataBits;
  if ( m_iCurBit + 9 <= m_nDataBits )
  {
    v8 = pOut->m_iCurBit >> 5;
    *(_DWORD *)&pOut->m_pData[4 * v8] = (i << (pOut->m_iCurBit & 0x1F))
                                      | *(_DWORD *)&pOut->m_pData[4 * v8]
                                      & dword_106C73EC[33 * (pOut->m_iCurBit & 0x1F)];
    v5 = pOut;
    v9 = 32 - (m_iCurBit & 0x1F);
    if ( v9 - 9 < 0 )
      *(_DWORD *)&pOut->m_pData[4 * v8 + 4] = ((unsigned int)i >> v9)
                                            | *(_DWORD *)&pOut->m_pData[4 * v8 + 4] & dword_106C73EC[-v9];
    pOut->m_iCurBit += 9;
  }
  else
  {
    pOut->m_iCurBit = m_nDataBits;
    pOut->m_bOverflow = true;
  }
  bf_write::WriteBits(this: v5, pInData: pVar->m_pString, nBits: 8 * i);
}

//------------------------------------------------------------------------------
// Address: 0x1016A950
// Name: void String_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl String_Decode(DecodeInfo *pInfo)
{
  DecodeInfo *v1; // ebx
  bf_read *m_pIn; // eax
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  unsigned int v10; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v13; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  int v17; // edi
  int v18; // edi
  char *m_TempStr; // esi
  const char **p_m_pVarName; // eax

  v1 = pInfo;
  m_pIn = pInfo->m_pIn;
  m_nBitsAvail = m_pIn->m_nBitsAvail;
  if ( m_nBitsAvail < 9 )
  {
    m_pBufferEnd = m_pIn->m_pBufferEnd;
    m_nInBufWord = m_pIn->m_nInBufWord;
    v13 = 9 - m_nBitsAvail;
    m_pDataIn = m_pIn->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      m_pIn->m_nBitsAvail = 1;
      m_pIn->m_nInBufWord = 0;
      m_pIn->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        m_pIn->m_bOverflow = true;
        m_pIn->m_nInBufWord = 0;
        goto LABEL_16;
      }
      m_pIn->m_nInBufWord = *m_pDataIn;
    }
    m_pIn->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( m_pIn->m_bOverflow )
    {
      v7 = 0;
    }
    else
    {
      v15 = m_pIn->m_nInBufWord;
      v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << m_pIn->m_nBitsAvail;
      m_pIn->m_nBitsAvail = 32 - v13;
      v17 = v16 | m_nInBufWord;
      v1 = pInfo;
      m_pIn->m_nInBufWord = v15 >> v13;
      v7 = v17;
    }
    goto LABEL_19;
  }
  v4 = m_pIn->m_nInBufWord;
  v5 = v4 & 0x1FF;
  v6 = m_nBitsAvail - 9;
  m_pIn->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    m_pIn->m_nInBufWord = v4 >> 9;
    v7 = v4 & 0x1FF;
  }
  else
  {
    v8 = m_pIn->m_pDataIn;
    v9 = m_pIn->m_pBufferEnd;
    m_pIn->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      m_pIn->m_nBitsAvail = 1;
      m_pIn->m_nInBufWord = 0;
      m_pIn->m_pDataIn = v8 + 1;
      v7 = v5;
    }
    else
    {
      if ( v8 <= v9 )
      {
        v10 = *v8;
        m_pIn->m_pDataIn = v8 + 1;
        m_pIn->m_nInBufWord = v10;
      }
      else
      {
        m_pIn->m_bOverflow = true;
        m_pIn->m_nInBufWord = 0;
      }
      v7 = v5;
    }
  }
LABEL_19:
  v18 = v7;
  m_TempStr = v1->m_TempStr;
  if ( v7 >= 512 )
  {
    _Warning(a1: "String_Decode( %s ) invalid length (%d)\n", v1->m_pRecvProp->m_pVarName, v7);
    v18 = 511;
  }
  CBitRead::ReadBits(this: v1->m_pIn, pOutData: v1->m_TempStr, nBits: 8 * v18);
  m_TempStr[v18] = 0;
  p_m_pVarName = (const char **)&v1->m_pRecvProp->m_pVarName;
  v1->m_Value.m_Int = (int)m_TempStr;
  if ( p_m_pVarName != nullptr )
    ((void (__cdecl *)(DecodeInfo *, void *, void *))p_m_pVarName[8])(a1: v1, a2: v1->m_pStruct, a3: v1->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016AAA0
// Name: AreBitsDifferent
// Source: json
//------------------------------------------------------------------------------
int __usercall AreBitsDifferent@<eax>(bf_read *pBuf1@<edx>, bf_read *pBuf2@<esi>, int nBits)
{
  int v3; // edi
  int v4; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v7; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edi
  int v10; // edi
  const unsigned int *v11; // ecx
  const unsigned int *v12; // eax
  unsigned int v13; // ebx
  unsigned int v14; // eax
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // ecx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edi
  int v20; // edi
  const unsigned int *v21; // ecx
  const unsigned int *v22; // eax
  unsigned int v23; // ebx
  unsigned int v24; // eax
  int v25; // edi
  int v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // ebx
  int v29; // ecx
  char v30; // cl
  const unsigned int *v31; // eax
  const unsigned int *v32; // ecx
  const unsigned int *v33; // ebx
  int v34; // eax
  const unsigned int *v35; // ecx
  int v36; // ecx
  unsigned int v37; // eax
  unsigned int v38; // edx
  int v39; // ecx
  const unsigned int *v40; // eax
  const unsigned int *v41; // ecx
  int v43; // eax
  BOOL v44; // edx
  unsigned int v45; // ecx
  const unsigned int *v46; // eax
  unsigned int v47; // edx
  const unsigned int *v48; // ecx
  unsigned int v49; // [esp+10h] [ebp-10h]
  int v50; // [esp+14h] [ebp-Ch]
  unsigned int v51; // [esp+18h] [ebp-8h]
  unsigned int v52; // [esp+18h] [ebp-8h]
  int diff; // [esp+1Ch] [ebp-4h]
  unsigned int nBitsa; // [esp+28h] [ebp+8h]
  int nBitsb; // [esp+28h] [ebp+8h]

  v3 = nBits;
  v4 = nBits >> 5;
  diff = 0;
  if ( nBits >> 5 > 0 )
  {
    v50 = nBits >> 5;
    while ( 1 )
    {
      m_nBitsAvail = pBuf1->m_nBitsAvail;
      m_nInBufWord = pBuf1->m_nInBufWord;
      if ( m_nBitsAvail >= 32 )
      {
        v7 = m_nBitsAvail - 32;
        pBuf1->m_nBitsAvail = v7;
        if ( v7 != 0 )
        {
          pBuf1->m_nInBufWord = 0;
        }
        else
        {
          m_pDataIn = pBuf1->m_pDataIn;
          pBuf1->m_nBitsAvail = 32;
          m_pBufferEnd = pBuf1->m_pBufferEnd;
          if ( m_pDataIn == m_pBufferEnd )
          {
            pBuf1->m_nBitsAvail = 1;
            pBuf1->m_nInBufWord = 0;
            pBuf1->m_pDataIn = m_pDataIn + 1;
          }
          else if ( m_pDataIn <= m_pBufferEnd )
          {
            pBuf1->m_nInBufWord = *m_pDataIn;
            pBuf1->m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            pBuf1->m_bOverflow = true;
            pBuf1->m_nInBufWord = 0;
          }
        }
        goto LABEL_20;
      }
      v10 = 32 - m_nBitsAvail;
      v11 = pBuf1->m_pBufferEnd;
      v51 = pBuf1->m_nInBufWord;
      v12 = pBuf1->m_pDataIn;
      if ( v12 == v11 )
        break;
      if ( v12 <= v11 )
      {
        pBuf1->m_nInBufWord = *v12;
        goto LABEL_16;
      }
      pBuf1->m_bOverflow = true;
      pBuf1->m_nInBufWord = 0;
LABEL_17:
      if ( pBuf1->m_bOverflow )
      {
        v52 = 0;
        goto LABEL_21;
      }
      v13 = pBuf1->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v10]) << pBuf1->m_nBitsAvail;
      pBuf1->m_nBitsAvail = 32 - v10;
      m_nInBufWord = v14 | v51;
      pBuf1->m_nInBufWord = v13 >> v10;
LABEL_20:
      v52 = m_nInBufWord;
LABEL_21:
      v15 = pBuf2->m_nBitsAvail;
      v16 = pBuf2->m_nInBufWord;
      if ( v15 < 32 )
      {
        v20 = 32 - v15;
        v21 = pBuf2->m_pBufferEnd;
        v49 = pBuf2->m_nInBufWord;
        v22 = pBuf2->m_pDataIn;
        if ( v22 == v21 )
        {
          pBuf2->m_nBitsAvail = 1;
          pBuf2->m_nInBufWord = 0;
          pBuf2->m_bOverflow = true;
          goto LABEL_34;
        }
        if ( v22 <= v21 )
        {
          pBuf2->m_nInBufWord = *v22;
LABEL_34:
          pBuf2->m_pDataIn = v22 + 1;
        }
        else
        {
          pBuf2->m_bOverflow = true;
          pBuf2->m_nInBufWord = 0;
        }
        if ( pBuf2->m_bOverflow )
        {
          v16 = 0;
        }
        else
        {
          v23 = pBuf2->m_nInBufWord;
          v24 = (v23 & CBitBuffer::s_nMaskTable[v20]) << pBuf2->m_nBitsAvail;
          pBuf2->m_nBitsAvail = 32 - v20;
          v16 = v24 | v49;
          pBuf2->m_nInBufWord = v23 >> v20;
        }
        goto LABEL_38;
      }
      v17 = v15 - 32;
      pBuf2->m_nBitsAvail = v17;
      if ( v17 != 0 )
      {
        pBuf2->m_nInBufWord = 0;
      }
      else
      {
        v18 = pBuf2->m_pDataIn;
        pBuf2->m_nBitsAvail = 32;
        v19 = pBuf2->m_pBufferEnd;
        if ( v18 == v19 )
        {
          pBuf2->m_nBitsAvail = 1;
          pBuf2->m_nInBufWord = 0;
          pBuf2->m_pDataIn = v18 + 1;
        }
        else if ( v18 <= v19 )
        {
          pBuf2->m_nInBufWord = *v18;
          pBuf2->m_pDataIn = v18 + 1;
        }
        else
        {
          pBuf2->m_bOverflow = true;
          pBuf2->m_nInBufWord = 0;
        }
      }
LABEL_38:
      diff |= v52 != v16;
      if ( --v50 == 0 )
      {
        v4 = nBits >> 5;
        v3 = nBits;
        goto LABEL_40;
      }
    }
    pBuf1->m_nBitsAvail = 1;
    pBuf1->m_nInBufWord = 0;
    pBuf1->m_bOverflow = true;
LABEL_16:
    pBuf1->m_pDataIn = v12 + 1;
    goto LABEL_17;
  }
LABEL_40:
  v25 = v3 - 32 * v4;
  if ( v25 <= 0 )
    return diff;
  v26 = pBuf1->m_nBitsAvail;
  v27 = pBuf1->m_nInBufWord;
  if ( v26 < v25 )
  {
    v33 = pBuf1->m_pBufferEnd;
    nBitsa = pBuf1->m_nInBufWord;
    v34 = v25 - v26;
    v35 = pBuf1->m_pDataIn;
    if ( v35 == v33 )
    {
      pBuf1->m_nBitsAvail = 1;
      pBuf1->m_nInBufWord = 0;
      pBuf1->m_bOverflow = true;
    }
    else
    {
      if ( v35 > v33 )
      {
        pBuf1->m_bOverflow = true;
        pBuf1->m_nInBufWord = 0;
LABEL_55:
        if ( pBuf1->m_bOverflow )
        {
          nBitsb = 0;
          goto LABEL_60;
        }
        v28 = ((pBuf1->m_nInBufWord & CBitBuffer::s_nMaskTable[v34]) << pBuf1->m_nBitsAvail) | nBitsa;
        pBuf1->m_nBitsAvail = 32 - v34;
        v30 = v34;
        v27 = pBuf1->m_nInBufWord;
        goto LABEL_58;
      }
      pBuf1->m_nInBufWord = *v35;
    }
    pBuf1->m_pDataIn = v35 + 1;
    goto LABEL_55;
  }
  v28 = v27 & CBitBuffer::s_nMaskTable[v25];
  v29 = v26 - v25;
  pBuf1->m_nBitsAvail = v29;
  if ( v29 == 0 )
  {
    v31 = pBuf1->m_pDataIn;
    v32 = pBuf1->m_pBufferEnd;
    pBuf1->m_nBitsAvail = 32;
    if ( v31 == v32 )
    {
      pBuf1->m_nBitsAvail = 1;
      pBuf1->m_nInBufWord = 0;
      pBuf1->m_pDataIn = v31 + 1;
    }
    else if ( v31 <= v32 )
    {
      pBuf1->m_nInBufWord = *v31;
      pBuf1->m_pDataIn = v31 + 1;
    }
    else
    {
      pBuf1->m_bOverflow = true;
      pBuf1->m_nInBufWord = 0;
    }
    goto LABEL_59;
  }
  v30 = v25;
LABEL_58:
  pBuf1->m_nInBufWord = v27 >> v30;
LABEL_59:
  nBitsb = v28;
LABEL_60:
  v36 = pBuf2->m_nBitsAvail;
  if ( v36 < v25 )
  {
    v46 = pBuf2->m_pDataIn;
    v47 = pBuf2->m_nInBufWord;
    v25 -= v36;
    v48 = pBuf2->m_pBufferEnd;
    if ( v46 == v48 )
    {
      pBuf2->m_nBitsAvail = 1;
      pBuf2->m_nInBufWord = 0;
      pBuf2->m_bOverflow = true;
    }
    else
    {
      if ( v46 > v48 )
      {
        pBuf2->m_bOverflow = true;
        pBuf2->m_nInBufWord = 0;
LABEL_74:
        if ( pBuf2->m_bOverflow )
          return (nBitsb != 0) | diff;
        v37 = pBuf2->m_nInBufWord;
        v38 = ((v37 & CBitBuffer::s_nMaskTable[v25]) << pBuf2->m_nBitsAvail) | v47;
        pBuf2->m_nBitsAvail = 32 - v25;
        goto LABEL_77;
      }
      pBuf2->m_nInBufWord = *v46;
    }
    pBuf2->m_pDataIn = v46 + 1;
    goto LABEL_74;
  }
  v37 = pBuf2->m_nInBufWord;
  v38 = v37 & CBitBuffer::s_nMaskTable[v25];
  v39 = v36 - v25;
  pBuf2->m_nBitsAvail = v39;
  if ( v39 != 0 )
  {
LABEL_77:
    pBuf2->m_nInBufWord = v37 >> v25;
    return (nBitsb != v38) | diff;
  }
  v40 = pBuf2->m_pDataIn;
  v41 = pBuf2->m_pBufferEnd;
  pBuf2->m_nBitsAvail = 32;
  if ( v40 == v41 )
  {
    pBuf2->m_pDataIn = v40 + 1;
    pBuf2->m_nBitsAvail = 1;
    pBuf2->m_nInBufWord = 0;
    return (nBitsb != v38) | diff;
  }
  else
  {
    if ( v40 <= v41 )
    {
      v45 = *v40;
      pBuf2->m_pDataIn = v40 + 1;
      v43 = diff;
      v44 = nBitsb != v38;
      pBuf2->m_nInBufWord = v45;
    }
    else
    {
      v43 = diff;
      v44 = nBitsb != v38;
      pBuf2->m_bOverflow = true;
      pBuf2->m_nInBufWord = 0;
    }
    return v44 | v43;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016AEB0
// Name: char const __near * String_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl String_GetTypeNameString()
{
  return "DPT_String";
}

//------------------------------------------------------------------------------
// Address: 0x1016AEC0
// Name: bool String_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl String_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return *pVar->m_pString == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016AF10
// Name: void Array_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Array_Encode(
        const unsigned __int8 *pStruct,
        DVariant *pVar,
        SendProp *pProp,
        bf_write *pOut,
        int objectID)
{
  int (__cdecl *m_ArrayLengthProxy)(const void *, int); // eax
  SendProp *m_pArrayProp; // edi
  int m_nElements; // eax
  int NumArrayLengthBits; // eax
  const unsigned __int8 *v9; // esi
  int i; // ebx
  void (__cdecl *m_ProxyFn)(const SendProp *, const void *, const void *, DVariant *, int, int); // edx
  DVariant var; // [esp+Ch] [ebp-1Ch] BYREF
  int nElements; // [esp+24h] [ebp-4h]

  m_ArrayLengthProxy = pProp->m_ArrayLengthProxy;
  m_pArrayProp = pProp->m_pArrayProp;
  if ( m_ArrayLengthProxy != nullptr )
  {
    m_nElements = m_ArrayLengthProxy(a1: pStruct, a2: objectID);
    if ( m_nElements > pProp->m_nElements )
      m_nElements = pProp->m_nElements;
  }
  else
  {
    m_nElements = pProp->m_nElements;
  }
  nElements = m_nElements;
  NumArrayLengthBits = SendProp::GetNumArrayLengthBits(this: pProp);
  bf_write::WriteUBitLong(this: pOut, curData: nElements, numbits: NumArrayLengthBits, bCheckRange: true);
  v9 = &pStruct[m_pArrayProp->m_Offset & 0xFFFFF];
  for ( i = 0; i < nElements; ++i )
  {
    m_ProxyFn = m_pArrayProp->m_ProxyFn;
    var.m_Type = DPT_Float;
    m_ProxyFn(a1: m_pArrayProp, a2: pStruct, a3: v9, a4: &var, a5: i, a6: objectID);
    ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *))g_PropTypeFns[m_pArrayProp->m_Type].Encode)(
      pStruct,
      pVar: &var,
      pProp: m_pArrayProp,
      pOut);
    v9 += pProp->m_ElementStride;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016AFD0
// Name: int Array_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Array_CompareDeltas(SendProp *pProp, bf_read *p1, bf_read *p2)
{
  int NumArrayLengthBits; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  unsigned int v7; // esi
  int v8; // ecx
  int v9; // ebx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v12; // edx
  const unsigned int *v13; // esi
  int v14; // edx
  const unsigned int *v15; // ecx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  bf_read *v18; // esi
  int v19; // ecx
  unsigned int v20; // edx
  unsigned int v21; // ebx
  int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  const unsigned int *v25; // eax
  const unsigned int *v26; // ecx
  unsigned int v27; // edx
  int v28; // eax
  const unsigned int *v29; // ecx
  const unsigned int *v30; // edx
  unsigned int v31; // edx
  unsigned int v32; // ebx
  unsigned int v33; // edx
  BOOL v34; // edx
  int v35; // ecx
  int i; // ebx
  int v37; // eax
  int j; // ebx
  const SendProp *v40; // [esp+0h] [ebp-14h]
  bf_write *v41; // [esp+4h] [ebp-10h]
  DVariant *v42; // [esp+8h] [ebp-Ch]
  SendProp *pArrayProp; // [esp+Ch] [ebp-8h]
  int nSame; // [esp+10h] [ebp-4h]
  const SendProp *pPropa; // [esp+1Ch] [ebp+8h]
  unsigned int p1a; // [esp+20h] [ebp+Ch]
  bf_read *p1b; // [esp+20h] [ebp+Ch]
  unsigned int bDifferent; // [esp+24h] [ebp+10h]
  int bDifferenta; // [esp+24h] [ebp+10h]

  pArrayProp = pProp->m_pArrayProp;
  NumArrayLengthBits = SendProp::GetNumArrayLengthBits(this: pProp);
  m_nBitsAvail = p1->m_nBitsAvail;
  m_nInBufWord = p1->m_nInBufWord;
  if ( m_nBitsAvail >= NumArrayLengthBits )
  {
    v7 = m_nInBufWord & CBitBuffer::s_nMaskTable[NumArrayLengthBits];
    v8 = m_nBitsAvail - NumArrayLengthBits;
    p1->m_nBitsAvail = v8;
    if ( v8 != 0 )
    {
      v9 = v7;
      p1->m_nInBufWord = m_nInBufWord >> NumArrayLengthBits;
    }
    else
    {
      m_pDataIn = p1->m_pDataIn;
      m_pBufferEnd = p1->m_pBufferEnd;
      p1->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        p1->m_nBitsAvail = 1;
        p1->m_nInBufWord = 0;
        p1->m_pDataIn = m_pDataIn + 1;
        v9 = v7;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v12 = *m_pDataIn;
          p1->m_pDataIn = m_pDataIn + 1;
          p1->m_nInBufWord = v12;
        }
        else
        {
          p1->m_bOverflow = true;
          p1->m_nInBufWord = 0;
        }
        v9 = v7;
      }
    }
    goto LABEL_19;
  }
  v13 = p1->m_pBufferEnd;
  p1a = p1->m_nInBufWord;
  v14 = NumArrayLengthBits - m_nBitsAvail;
  v15 = p1->m_pDataIn;
  if ( v15 == v13 )
  {
    p1->m_nBitsAvail = 1;
    p1->m_nInBufWord = 0;
    p1->m_bOverflow = true;
LABEL_15:
    p1->m_pDataIn = v15 + 1;
    goto LABEL_16;
  }
  if ( v15 <= v13 )
  {
    p1->m_nInBufWord = *v15;
    goto LABEL_15;
  }
  p1->m_bOverflow = true;
  p1->m_nInBufWord = 0;
LABEL_16:
  if ( p1->m_bOverflow )
  {
    pPropa = nullptr;
    v9 = 0;
    goto LABEL_20;
  }
  v16 = p1->m_nInBufWord;
  v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << p1->m_nBitsAvail;
  p1->m_nBitsAvail = 32 - v14;
  v9 = v17 | p1a;
  p1->m_nInBufWord = v16 >> v14;
LABEL_19:
  pPropa = (const SendProp *)v9;
LABEL_20:
  v18 = p2;
  v19 = p2->m_nBitsAvail;
  v20 = p2->m_nInBufWord;
  if ( v19 >= NumArrayLengthBits )
  {
    v21 = v20 & CBitBuffer::s_nMaskTable[NumArrayLengthBits];
    v22 = v19 - NumArrayLengthBits;
    p2->m_nBitsAvail = v22;
    if ( v22 != 0 )
    {
      v23 = v20 >> NumArrayLengthBits;
      v24 = v21;
      p1b = (bf_read *)v21;
      p2->m_nInBufWord = v23;
    }
    else
    {
      v25 = p2->m_pDataIn;
      v26 = p2->m_pBufferEnd;
      p2->m_nBitsAvail = 32;
      if ( v25 == v26 )
      {
        p2->m_pDataIn = v25 + 1;
        v24 = v21;
        p2->m_nBitsAvail = 1;
        p2->m_nInBufWord = 0;
        p1b = (bf_read *)v21;
      }
      else
      {
        if ( v25 <= v26 )
        {
          v27 = *v25;
          p2->m_pDataIn = v25 + 1;
          v24 = v21;
          p2->m_nInBufWord = v27;
        }
        else
        {
          v24 = v21;
          p2->m_bOverflow = true;
          p2->m_nInBufWord = 0;
        }
        p1b = (bf_read *)v21;
      }
    }
    goto LABEL_38;
  }
  v28 = NumArrayLengthBits - v19;
  v29 = p2->m_pDataIn;
  bDifferent = p2->m_nInBufWord;
  v30 = v18->m_pBufferEnd;
  if ( v29 == v30 )
  {
    v18->m_nBitsAvail = 1;
    v18->m_nInBufWord = 0;
    v18->m_bOverflow = true;
LABEL_34:
    v18->m_pDataIn = v29 + 1;
    goto LABEL_35;
  }
  if ( v29 <= v30 )
  {
    v18->m_nInBufWord = *v29;
    goto LABEL_34;
  }
  v18->m_bOverflow = true;
  v18->m_nInBufWord = 0;
LABEL_35:
  if ( v18->m_bOverflow )
  {
    p1b = nullptr;
    v24 = 0;
    goto LABEL_39;
  }
  v31 = v18->m_nInBufWord;
  v32 = (v31 & CBitBuffer::s_nMaskTable[v28]) << v18->m_nBitsAvail;
  v18->m_nBitsAvail = 32 - v28;
  v33 = v31 >> v28;
  p1b = (bf_read *)(v32 | bDifferent);
  v24 = v32 | bDifferent;
  v18->m_nInBufWord = v33;
LABEL_38:
  v9 = (int)pPropa;
LABEL_39:
  v34 = v9 != v24;
  bDifferenta = v34;
  if ( v9 >= v24 )
  {
    nSame = v24;
    v35 = v24;
  }
  else
  {
    v35 = v9;
    nSame = v9;
  }
  if ( v35 > 0 )
  {
    for ( i = v35; i != 0; --i )
      bDifferenta |= (*(&funcs_1016B223 + 9 * pArrayProp->m_Type))(pProp: pArrayProp, p1, p2: v18);
    v24 = (int)p1b;
    v9 = (int)pPropa;
    v35 = nSame;
    v34 = bDifferenta;
  }
  if ( v9 == v24 )
    return v34;
  if ( v9 > v24 )
  {
    v18 = p1;
    v24 = v9;
  }
  v37 = v24 - v35;
  if ( v37 <= 0 )
    return v34;
  for ( j = v37; j != 0; --j )
    ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B262[9 * pArrayProp->m_Type])(
      pStruct: (const unsigned __int8 *)pArrayProp,
      pVar: (DVariant *)v18,
      pProp: v40,
      pOut: v41,
      objectID: v42);
  return bDifferenta;
}

//------------------------------------------------------------------------------
// Address: 0x1016B280
// Name: void Array_FastCopy(class SendProp const __near *,class RecvProp const __near *,unsigned char const __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Array_FastCopy(
        const SendProp *pSendProp,
        const RecvProp *pRecvProp,
        const unsigned __int8 *pSendData,
        unsigned __int8 *pRecvData,
        int objectID)
{
  int v5; // ecx
  SendProp *m_pArrayProp; // ebx
  RecvProp *v7; // edi
  int (__cdecl *m_ArrayLengthProxy)(const void *, int); // eax
  int m_nElements; // eax
  void (__cdecl *v10)(void *, int, int); // eax
  unsigned __int8 *v11; // edi
  const unsigned __int8 *v12; // esi
  int v13; // eax
  CRecvProxyData recvProxyData; // [esp+Ch] [ebp-30h] BYREF
  const RecvProp *pArrayRecvProp; // [esp+34h] [ebp-8h]
  int nElements; // [esp+38h] [ebp-4h]

  v5 = objectID;
  m_pArrayProp = pSendProp->m_pArrayProp;
  v7 = pRecvProp->m_pArrayProp;
  m_ArrayLengthProxy = pSendProp->m_ArrayLengthProxy;
  pArrayRecvProp = v7;
  recvProxyData.m_Value.m_Type = DPT_Float;
  recvProxyData.m_pRecvProp = v7;
  recvProxyData.m_ObjectID = objectID;
  if ( m_ArrayLengthProxy != nullptr )
  {
    m_nElements = m_ArrayLengthProxy(a1: pSendData, a2: objectID);
    v5 = objectID;
    if ( m_nElements > pSendProp->m_nElements )
      m_nElements = pSendProp->m_nElements;
    nElements = m_nElements;
  }
  else
  {
    nElements = pSendProp->m_nElements;
  }
  v10 = pRecvProp->m_ArrayLengthProxy;
  if ( v10 != nullptr )
    v10(a1: pRecvData, a2: v5, a3: nElements);
  v11 = &pRecvData[v7->m_Offset];
  v12 = &pSendData[m_pArrayProp->m_Offset & 0xFFFFF];
  v13 = 0;
  for ( recvProxyData.m_iElement = 0; v13 < nElements; recvProxyData.m_iElement = v13 )
  {
    m_pArrayProp->m_ProxyFn(a1: m_pArrayProp, a2: pSendData, a3: v12, a4: &recvProxyData.m_Value, a5: v13, a6: objectID);
    v12 += pSendProp->m_ElementStride;
    pArrayRecvProp->m_ProxyFn(a1: &recvProxyData, a2: pRecvData, a3: v11);
    v11 += pRecvProp->m_ElementStride;
    v13 = recvProxyData.m_iElement + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B350
// Name: char const __near * Array_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Array_GetTypeNameString()
{
  return "DPT_Array";
}

//------------------------------------------------------------------------------
// Address: 0x1016B360
// Name: bool Array_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Array_IsZero(const unsigned __int8 *pStruct, DVariant *pVar, const SendProp *pProp)
{
  int (__cdecl *m_ArrayLengthProxy)(const void *, int); // eax
  int m_nElements; // eax

  m_ArrayLengthProxy = pProp->m_ArrayLengthProxy;
  if ( m_ArrayLengthProxy != nullptr )
  {
    m_nElements = m_ArrayLengthProxy(a1: pStruct, a2: -1);
    if ( m_nElements > pProp->m_nElements )
      m_nElements = pProp->m_nElements;
    LOBYTE(m_nElements) = m_nElements == 0;
  }
  else
  {
    return pProp->m_nElements == 0;
  }
  return m_nElements;
}

//------------------------------------------------------------------------------
// Address: 0x1016B3A0
// Name: void Array_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Array_DecodeZero(DecodeInfo *pInfo)
{
  void (__cdecl *m_ArrayLengthProxy)(void *, int, int); // ecx

  m_ArrayLengthProxy = pInfo->m_pRecvProp->m_ArrayLengthProxy;
  if ( m_ArrayLengthProxy != nullptr )
    m_ArrayLengthProxy(a1: pInfo->m_pStruct, a2: pInfo->m_ObjectID, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1016B3C0
// Name: bool Array_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Array_IsEncodedZero(SendProp *pProp, bf_read *pIn)
{
  int NumArrayLengthBits; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  unsigned int v6; // edi
  int v7; // ecx
  int v8; // ebx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v11; // edx
  unsigned int v12; // edi
  int v13; // eax
  const unsigned int *v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int i; // edi
  SendProp *pArrayProp; // [esp+14h] [ebp+8h]

  pArrayProp = pProp->m_pArrayProp;
  NumArrayLengthBits = SendProp::GetNumArrayLengthBits(this: pProp);
  m_nBitsAvail = pIn->m_nBitsAvail;
  if ( m_nBitsAvail >= NumArrayLengthBits )
  {
    m_nInBufWord = pIn->m_nInBufWord;
    v6 = m_nInBufWord & CBitBuffer::s_nMaskTable[NumArrayLengthBits];
    v7 = m_nBitsAvail - NumArrayLengthBits;
    pIn->m_nBitsAvail = v7;
    if ( v7 != 0 )
    {
      v8 = v6;
      pIn->m_nInBufWord = m_nInBufWord >> NumArrayLengthBits;
    }
    else
    {
      m_pDataIn = pIn->m_pDataIn;
      m_pBufferEnd = pIn->m_pBufferEnd;
      pIn->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pIn->m_nBitsAvail = 1;
        pIn->m_nInBufWord = 0;
        pIn->m_pDataIn = m_pDataIn + 1;
        v8 = v6;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          pIn->m_nInBufWord = *m_pDataIn;
          pIn->m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          pIn->m_bOverflow = true;
          pIn->m_nInBufWord = 0;
        }
        v8 = v6;
      }
    }
    goto LABEL_19;
  }
  v11 = pIn->m_pBufferEnd;
  v12 = pIn->m_nInBufWord;
  v13 = NumArrayLengthBits - m_nBitsAvail;
  v14 = pIn->m_pDataIn;
  if ( v14 == v11 )
  {
    pIn->m_nBitsAvail = 1;
    pIn->m_nInBufWord = 0;
    pIn->m_bOverflow = true;
  }
  else
  {
    if ( v14 > v11 )
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
      goto LABEL_16;
    }
    pIn->m_nInBufWord = *v14;
  }
  pIn->m_pDataIn = v14 + 1;
LABEL_16:
  if ( pIn->m_bOverflow )
  {
    v8 = 0;
  }
  else
  {
    v15 = pIn->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << pIn->m_nBitsAvail;
    pIn->m_nBitsAvail = 32 - v13;
    v8 = v12 | v16;
    pIn->m_nInBufWord = v15 >> v13;
  }
LABEL_19:
  if ( v8 > 0 )
  {
    for ( i = v8; i != 0; --i )
      (*(&funcs_1016B4D2 + 9 * pArrayProp->m_Type))(pProp: pArrayProp, pIn);
  }
  return v8 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016B4F0
// Name: void Array_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Array_SkipProp(SendProp *pProp, DVariant *pIn)
{
  int NumArrayLengthBits; // eax
  int v4; // ecx
  unsigned int v5; // edx
  int v6; // edi
  int v7; // ecx
  unsigned int v8; // edx
  const unsigned int *v9; // eax
  const unsigned int *v10; // ecx
  const unsigned int *v11; // edx
  unsigned int m_Type; // edi
  int v13; // eax
  const unsigned int *m_Int; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  const SendProp *v17; // [esp+0h] [ebp-Ch]
  bf_write *v18; // [esp+4h] [ebp-8h]
  DVariant *v19; // [esp+8h] [ebp-4h]
  SendProp *pArrayProp; // [esp+14h] [ebp+8h]

  pArrayProp = pProp->m_pArrayProp;
  NumArrayLengthBits = SendProp::GetNumArrayLengthBits(this: pProp);
  v4 = *((_DWORD *)&pIn->m_Type + 1);
  if ( v4 < NumArrayLengthBits )
  {
    v11 = (const unsigned int *)LODWORD(pIn[1].m_Vector[1]);
    m_Type = pIn->m_Type;
    v13 = NumArrayLengthBits - v4;
    m_Int = (const unsigned int *)pIn[1].m_Int;
    if ( m_Int == v11 )
    {
      *((_DWORD *)&pIn->m_Type + 1) = 1;
      pIn->m_Type = DPT_Int;
      *((_BYTE *)&pIn->m_pData + 4) = 1;
    }
    else
    {
      if ( m_Int > v11 )
      {
        *((_BYTE *)&pIn->m_pData + 4) = 1;
        pIn->m_Type = DPT_Int;
LABEL_15:
        if ( *((_BYTE *)&pIn->m_pData + 4) != 0 )
        {
          v6 = 0;
          goto LABEL_19;
        }
        v15 = pIn->m_Type;
        v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << *((_DWORD *)&pIn->m_Type + 1);
        *((_DWORD *)&pIn->m_Type + 1) = 32 - v13;
        v6 = v16 | m_Type;
        v8 = v15 >> v13;
        goto LABEL_18;
      }
      pIn->m_Type = *m_Int;
    }
    pIn[1].m_Int = (int)(m_Int + 1);
    goto LABEL_15;
  }
  v5 = pIn->m_Type;
  v6 = v5 & CBitBuffer::s_nMaskTable[NumArrayLengthBits];
  v7 = v4 - NumArrayLengthBits;
  *((_DWORD *)&pIn->m_Type + 1) = v7;
  if ( v7 != 0 )
  {
    v8 = v5 >> NumArrayLengthBits;
LABEL_18:
    pIn->m_Type = v8;
    goto LABEL_19;
  }
  v9 = (const unsigned int *)pIn[1].m_Int;
  v10 = (const unsigned int *)LODWORD(pIn[1].m_Vector[1]);
  *((_DWORD *)&pIn->m_Type + 1) = 32;
  if ( v9 == v10 )
  {
    *((_DWORD *)&pIn->m_Type + 1) = 1;
    pIn->m_Type = DPT_Int;
    pIn[1].m_Int = (int)(v9 + 1);
  }
  else if ( v9 <= v10 )
  {
    pIn->m_Type = *v9;
    pIn[1].m_Int = (int)(v9 + 1);
  }
  else
  {
    *((_BYTE *)&pIn->m_pData + 4) = 1;
    pIn->m_Type = DPT_Int;
  }
LABEL_19:
  if ( v6 > 0 )
  {
    do
    {
      ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B262[9 * pArrayProp->m_Type])(
        pStruct: (const unsigned __int8 *)pArrayProp,
        pVar: pIn,
        pProp: v17,
        pOut: v18,
        objectID: v19);
      --v6;
    }
    while ( v6 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B600
// Name: char const __near * DataTable_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl DataTable_GetTypeNameString()
{
  return "DPT_DataTable";
}

//------------------------------------------------------------------------------
// Address: 0x1016B610
// Name: void Int64_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int64_Decode(DecodeInfo *pInfo)
{
  DecodeInfo *v1; // edi
  bf_read *m_pIn; // eax
  unsigned int v3; // ecx
  int v4; // edx
  const unsigned int *v6; // ecx
  const unsigned int *v7; // esi
  bf_read *v8; // eax
  int v9; // ecx
  unsigned int v10; // edx
  const unsigned int *v11; // ecx
  const unsigned int *v12; // esi
  const unsigned int *v13; // esi
  unsigned int v14; // edi
  int v15; // edx
  const unsigned int *v16; // ecx
  unsigned int v17; // esi
  unsigned int v18; // edi
  bf_read *v19; // eax
  int v20; // ecx
  int v21; // edx
  unsigned int v22; // esi
  unsigned int v23; // edi
  int v24; // ecx
  const unsigned int *v25; // ecx
  const unsigned int *v26; // edx
  const unsigned int *v27; // esi
  unsigned int v28; // edi
  const unsigned int *v29; // ecx
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v34; // ecx
  unsigned int v35; // edi
  int v36; // edx
  const unsigned int *v37; // esi
  unsigned int v38; // esi
  unsigned int v39; // ebx
  int v40; // ecx
  int v41; // ecx
  const unsigned int *v42; // edx
  const unsigned int *v43; // esi
  float v44; // eax
  unsigned int v45; // ebx
  unsigned int lowInt; // [esp+Ch] [ebp-8h]
  bool bNeg; // [esp+13h] [ebp-1h]

  v1 = pInfo;
  m_pIn = pInfo->m_pIn;
  bNeg = false;
  if ( (pInfo->m_pProp->m_Flags & 1) != 0 )
  {
    m_nBitsAvail = m_pIn->m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = m_pIn->m_nInBufWord;
      m_pIn->m_nBitsAvail = m_nBitsAvail - 32;
      if ( m_nBitsAvail == 32 )
      {
        m_pDataIn = m_pIn->m_pDataIn;
        m_pBufferEnd = m_pIn->m_pBufferEnd;
        m_pIn->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          m_pIn->m_nBitsAvail = 1;
          m_pIn->m_nInBufWord = 0;
          m_pIn->m_pDataIn = m_pDataIn + 1;
          lowInt = m_nInBufWord;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            m_pIn->m_nInBufWord = *m_pDataIn;
            m_pIn->m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            m_pIn->m_bOverflow = true;
            m_pIn->m_nInBufWord = 0;
          }
          lowInt = m_nInBufWord;
        }
      }
      else
      {
        m_pIn->m_nInBufWord = 0;
        lowInt = m_nInBufWord;
      }
      goto LABEL_58;
    }
    v34 = m_pIn->m_pDataIn;
    v35 = m_pIn->m_nInBufWord;
    v36 = 32 - m_nBitsAvail;
    v37 = m_pIn->m_pBufferEnd;
    if ( v34 == v37 )
    {
      m_pIn->m_nBitsAvail = 1;
      m_pIn->m_nInBufWord = 0;
      m_pIn->m_bOverflow = true;
    }
    else
    {
      if ( v34 > v37 )
      {
        m_pIn->m_bOverflow = true;
        m_pIn->m_nInBufWord = 0;
LABEL_54:
        if ( m_pIn->m_bOverflow )
        {
          lowInt = 0;
        }
        else
        {
          v38 = m_pIn->m_nInBufWord;
          v39 = (v38 & CBitBuffer::s_nMaskTable[v36]) << m_pIn->m_nBitsAvail;
          m_pIn->m_nBitsAvail = 32 - v36;
          lowInt = v39 | v35;
          m_pIn->m_nInBufWord = v38 >> v36;
        }
        v1 = pInfo;
LABEL_58:
        v19 = v1->m_pIn;
        v40 = v19->m_nBitsAvail;
        v21 = v1->m_pProp->m_nBits - 32;
        if ( v40 >= v21 )
        {
          v22 = v19->m_nInBufWord;
          v23 = v22 & CBitBuffer::s_nMaskTable[v21];
          v41 = v40 - v21;
          v19->m_nBitsAvail = v41;
          if ( v41 == 0 )
          {
            v25 = v19->m_pDataIn;
            v42 = v19->m_pBufferEnd;
            v19->m_nBitsAvail = 32;
            if ( v25 == v42 )
            {
              v19->m_nBitsAvail = 1;
              v19->m_nInBufWord = 0;
              v19->m_pDataIn = v25 + 1;
              goto LABEL_74;
            }
            if ( v25 > v42 )
            {
              v19->m_bOverflow = true;
              v19->m_nInBufWord = 0;
              goto LABEL_74;
            }
            goto LABEL_34;
          }
LABEL_73:
          v19->m_nInBufWord = v22 >> v21;
          goto LABEL_74;
        }
        v43 = v19->m_pBufferEnd;
        v28 = v19->m_nInBufWord;
        v21 -= v40;
        v29 = v19->m_pDataIn;
        if ( v29 == v43 )
        {
          v19->m_nBitsAvail = 1;
          v19->m_nInBufWord = 0;
          v19->m_bOverflow = true;
          goto LABEL_69;
        }
        if ( v29 > v43 )
        {
          v19->m_bOverflow = true;
          v19->m_nInBufWord = 0;
          goto LABEL_70;
        }
LABEL_68:
        v19->m_nInBufWord = *v29;
        goto LABEL_69;
      }
      m_pIn->m_nInBufWord = *v34;
    }
    m_pIn->m_pDataIn = v34 + 1;
    goto LABEL_54;
  }
  v3 = m_pIn->m_nInBufWord;
  v4 = v3 & 1;
  if ( m_pIn->m_nBitsAvail-- == 1 )
  {
    v6 = m_pIn->m_pDataIn;
    v7 = m_pIn->m_pBufferEnd;
    m_pIn->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      m_pIn->m_nBitsAvail = 1;
      m_pIn->m_nInBufWord = 0;
      m_pIn->m_pDataIn = v6 + 1;
    }
    else if ( v6 <= v7 )
    {
      m_pIn->m_nInBufWord = *v6;
      m_pIn->m_pDataIn = v6 + 1;
    }
    else
    {
      m_pIn->m_bOverflow = true;
      m_pIn->m_nInBufWord = 0;
    }
  }
  else
  {
    m_pIn->m_nInBufWord = v3 >> 1;
  }
  v8 = pInfo->m_pIn;
  v9 = v8->m_nBitsAvail;
  bNeg = v4 != 0;
  if ( v9 >= 32 )
  {
    v10 = v8->m_nInBufWord;
    v8->m_nBitsAvail = v9 - 32;
    if ( v9 == 32 )
    {
      v11 = v8->m_pDataIn;
      v12 = v8->m_pBufferEnd;
      v8->m_nBitsAvail = 32;
      if ( v11 == v12 )
      {
        v8->m_nBitsAvail = 1;
        v8->m_nInBufWord = 0;
        v8->m_pDataIn = v11 + 1;
        lowInt = v10;
      }
      else
      {
        if ( v11 <= v12 )
        {
          v8->m_nInBufWord = *v11;
          v8->m_pDataIn = v11 + 1;
        }
        else
        {
          v8->m_bOverflow = true;
          v8->m_nInBufWord = 0;
        }
        lowInt = v10;
      }
    }
    else
    {
      v8->m_nInBufWord = 0;
      lowInt = v10;
    }
    goto LABEL_28;
  }
  v13 = v8->m_pBufferEnd;
  v14 = v8->m_nInBufWord;
  v15 = 32 - v9;
  v16 = v8->m_pDataIn;
  if ( v16 == v13 )
  {
    v8->m_nBitsAvail = 1;
    v8->m_nInBufWord = 0;
    v8->m_bOverflow = true;
LABEL_23:
    v8->m_pDataIn = v16 + 1;
    goto LABEL_24;
  }
  if ( v16 <= v13 )
  {
    v8->m_nInBufWord = *v16;
    goto LABEL_23;
  }
  v8->m_bOverflow = true;
  v8->m_nInBufWord = 0;
LABEL_24:
  if ( v8->m_bOverflow )
  {
    lowInt = 0;
  }
  else
  {
    v17 = v8->m_nInBufWord;
    v18 = ((v17 & CBitBuffer::s_nMaskTable[v15]) << v8->m_nBitsAvail) | v14;
    v8->m_nBitsAvail = 32 - v15;
    lowInt = v18;
    v8->m_nInBufWord = v17 >> v15;
  }
  v1 = pInfo;
LABEL_28:
  v19 = v1->m_pIn;
  v20 = v19->m_nBitsAvail;
  v21 = v1->m_pProp->m_nBits - 33;
  if ( v20 < v21 )
  {
    v27 = v19->m_pBufferEnd;
    v28 = v19->m_nInBufWord;
    v21 -= v20;
    v29 = v19->m_pDataIn;
    if ( v29 == v27 )
    {
      v19->m_nBitsAvail = 1;
      v19->m_nInBufWord = 0;
      v19->m_bOverflow = true;
LABEL_69:
      v19->m_pDataIn = v29 + 1;
      goto LABEL_70;
    }
    if ( v29 > v27 )
    {
      v19->m_bOverflow = true;
      v19->m_nInBufWord = 0;
LABEL_70:
      if ( v19->m_bOverflow )
      {
        v44 = 0.0;
        goto LABEL_75;
      }
      v22 = v19->m_nInBufWord;
      v45 = (v22 & CBitBuffer::s_nMaskTable[v21]) << v19->m_nBitsAvail;
      v19->m_nBitsAvail = 32 - v21;
      v23 = v45 | v28;
      goto LABEL_73;
    }
    goto LABEL_68;
  }
  v22 = v19->m_nInBufWord;
  v23 = v22 & CBitBuffer::s_nMaskTable[v21];
  v24 = v20 - v21;
  v19->m_nBitsAvail = v24;
  if ( v24 != 0 )
    goto LABEL_73;
  v25 = v19->m_pDataIn;
  v26 = v19->m_pBufferEnd;
  v19->m_nBitsAvail = 32;
  if ( v25 != v26 )
  {
    if ( v25 > v26 )
    {
      v19->m_bOverflow = true;
      v19->m_nInBufWord = 0;
      goto LABEL_74;
    }
LABEL_34:
    v19->m_nInBufWord = *v25;
    v19->m_pDataIn = v25 + 1;
    goto LABEL_74;
  }
  v19->m_nBitsAvail = 1;
  v19->m_nInBufWord = 0;
  v19->m_pDataIn = v25 + 1;
LABEL_74:
  v44 = *(float *)&v23;
LABEL_75:
  pInfo->m_Value.m_Int = lowInt;
  pInfo->m_Value.m_Vector[1] = v44;
  if ( bNeg )
    pInfo->m_Value.m_Int64 = -pInfo->m_Value.m_Int64;
  if ( pInfo->m_pRecvProp != nullptr )
    pInfo->m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016BA30
// Name: int Int64_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Int64_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  int m_nBitsAvail; // ecx
  int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // edi
  int v8; // ecx
  unsigned int v9; // esi
  const unsigned int *v10; // ecx
  const unsigned int *v11; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v14; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  int v18; // esi
  unsigned int v19; // ecx
  const unsigned int *v20; // edx
  const unsigned int *v21; // esi
  const unsigned int *v22; // ecx
  unsigned int v23; // edi
  int v24; // edx
  const unsigned int *v25; // esi
  unsigned int v26; // esi
  unsigned int v27; // ebx
  int v28; // ecx
  int v29; // edx
  unsigned int v30; // esi
  unsigned int v31; // edi
  int v32; // ecx
  unsigned int v33; // esi
  const unsigned int *v34; // ecx
  const unsigned int *v35; // edx
  const unsigned int *v36; // esi
  unsigned int v37; // edi
  int v38; // edx
  const unsigned int *v39; // ecx
  unsigned int v40; // esi
  unsigned int v41; // ebx
  int v42; // esi
  unsigned int v43; // ecx
  int v44; // edi
  const unsigned int *v45; // edx
  const unsigned int *v46; // esi
  const unsigned int *v47; // ecx
  unsigned int v48; // edi
  int v49; // edx
  const unsigned int *v50; // esi
  unsigned int v51; // esi
  unsigned int v52; // ebx
  unsigned int lowInt1; // [esp+Ch] [ebp-4h]
  unsigned int highInt2; // [esp+18h] [ebp+8h]
  unsigned int highInt1; // [esp+1Ch] [ebp+Ch]

  m_nBitsAvail = p1->m_nBitsAvail;
  v5 = pProp->m_nBits - 32;
  if ( m_nBitsAvail < v5 )
  {
    m_pBufferEnd = p1->m_pBufferEnd;
    m_nInBufWord = p1->m_nInBufWord;
    v14 = v5 - m_nBitsAvail;
    m_pDataIn = p1->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
LABEL_15:
        if ( p1->m_bOverflow )
        {
          highInt1 = 0;
          goto LABEL_20;
        }
        v16 = p1->m_nInBufWord;
        v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << p1->m_nBitsAvail;
        p1->m_nBitsAvail = 32 - v14;
        v7 = v17 | m_nInBufWord;
        v9 = v16 >> v14;
        goto LABEL_18;
      }
      p1->m_nInBufWord = *m_pDataIn;
    }
    p1->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v6 = p1->m_nInBufWord;
  v7 = v6 & CBitBuffer::s_nMaskTable[v5];
  v8 = m_nBitsAvail - v5;
  p1->m_nBitsAvail = v8;
  if ( v8 == 0 )
  {
    v10 = p1->m_pDataIn;
    v11 = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( v10 == v11 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_pDataIn = v10 + 1;
    }
    else if ( v10 <= v11 )
    {
      p1->m_nInBufWord = *v10;
      p1->m_pDataIn = v10 + 1;
    }
    else
    {
      p1->m_bOverflow = true;
      p1->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v9 = v6 >> v5;
LABEL_18:
  p1->m_nInBufWord = v9;
LABEL_19:
  highInt1 = v7;
LABEL_20:
  v18 = p1->m_nBitsAvail;
  if ( v18 < 32 )
  {
    v22 = p1->m_pDataIn;
    v23 = p1->m_nInBufWord;
    v24 = 32 - v18;
    v25 = p1->m_pBufferEnd;
    if ( v22 == v25 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( v22 > v25 )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
        goto LABEL_35;
      }
      p1->m_nInBufWord = *v22;
    }
    p1->m_pDataIn = v22 + 1;
LABEL_35:
    if ( p1->m_bOverflow )
    {
      lowInt1 = 0;
    }
    else
    {
      v26 = p1->m_nInBufWord;
      v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << p1->m_nBitsAvail;
      p1->m_nBitsAvail = 32 - v24;
      lowInt1 = v27 | v23;
      p1->m_nInBufWord = v26 >> v24;
    }
    goto LABEL_38;
  }
  v19 = p1->m_nInBufWord;
  p1->m_nBitsAvail = v18 - 32;
  if ( v18 == 32 )
  {
    v20 = p1->m_pDataIn;
    v21 = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( v20 == v21 )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_pDataIn = v20 + 1;
      lowInt1 = v19;
    }
    else
    {
      if ( v20 <= v21 )
      {
        p1->m_nInBufWord = *v20;
        p1->m_pDataIn = v20 + 1;
      }
      else
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
      }
      lowInt1 = v19;
    }
  }
  else
  {
    p1->m_nInBufWord = 0;
    lowInt1 = v19;
  }
LABEL_38:
  v28 = p2->m_nBitsAvail;
  v29 = pProp->m_nBits - 32;
  if ( v28 < v29 )
  {
    v36 = p2->m_pBufferEnd;
    v37 = p2->m_nInBufWord;
    v38 = v29 - v28;
    v39 = p2->m_pDataIn;
    if ( v39 == v36 )
    {
      p2->m_nBitsAvail = 1;
      p2->m_nInBufWord = 0;
      p2->m_bOverflow = true;
    }
    else
    {
      if ( v39 > v36 )
      {
        p2->m_bOverflow = true;
        p2->m_nInBufWord = 0;
LABEL_52:
        if ( p2->m_bOverflow )
        {
          highInt2 = 0;
          goto LABEL_57;
        }
        v40 = p2->m_nInBufWord;
        v41 = (v40 & CBitBuffer::s_nMaskTable[v38]) << p2->m_nBitsAvail;
        p2->m_nBitsAvail = 32 - v38;
        v31 = v41 | v37;
        v33 = v40 >> v38;
        goto LABEL_55;
      }
      p2->m_nInBufWord = *v39;
    }
    p2->m_pDataIn = v39 + 1;
    goto LABEL_52;
  }
  v30 = p2->m_nInBufWord;
  v31 = v30 & CBitBuffer::s_nMaskTable[v29];
  v32 = v28 - v29;
  p2->m_nBitsAvail = v32;
  if ( v32 == 0 )
  {
    v34 = p2->m_pDataIn;
    v35 = p2->m_pBufferEnd;
    p2->m_nBitsAvail = 32;
    if ( v34 == v35 )
    {
      p2->m_nBitsAvail = 1;
      p2->m_nInBufWord = 0;
      p2->m_pDataIn = v34 + 1;
    }
    else if ( v34 <= v35 )
    {
      p2->m_nInBufWord = *v34;
      p2->m_pDataIn = v34 + 1;
    }
    else
    {
      p2->m_bOverflow = true;
      p2->m_nInBufWord = 0;
    }
    goto LABEL_56;
  }
  v33 = v30 >> v29;
LABEL_55:
  p2->m_nInBufWord = v33;
LABEL_56:
  highInt2 = v31;
LABEL_57:
  v42 = p2->m_nBitsAvail;
  if ( v42 >= 32 )
  {
    v43 = p2->m_nInBufWord;
    p2->m_nBitsAvail = v42 - 32;
    if ( v42 == 32 )
    {
      v45 = p2->m_pDataIn;
      v46 = p2->m_pBufferEnd;
      p2->m_nBitsAvail = 32;
      if ( v45 == v46 )
      {
        p2->m_nBitsAvail = 1;
        p2->m_nInBufWord = 0;
        p2->m_pDataIn = v45 + 1;
        v44 = v43;
      }
      else
      {
        if ( v45 <= v46 )
        {
          p2->m_nInBufWord = *v45;
          p2->m_pDataIn = v45 + 1;
        }
        else
        {
          p2->m_bOverflow = true;
          p2->m_nInBufWord = 0;
        }
        v44 = v43;
      }
    }
    else
    {
      p2->m_nInBufWord = 0;
      v44 = v43;
    }
    return highInt1 != highInt2 || lowInt1 != v44;
  }
  v47 = p2->m_pDataIn;
  v48 = p2->m_nInBufWord;
  v49 = 32 - v42;
  v50 = p2->m_pBufferEnd;
  if ( v47 == v50 )
  {
    p2->m_nBitsAvail = 1;
    p2->m_nInBufWord = 0;
    p2->m_bOverflow = true;
  }
  else
  {
    if ( v47 > v50 )
    {
      p2->m_bOverflow = true;
      p2->m_nInBufWord = 0;
      goto LABEL_72;
    }
    p2->m_nInBufWord = *v47;
  }
  p2->m_pDataIn = v47 + 1;
LABEL_72:
  if ( p2->m_bOverflow )
  {
    v44 = 0;
  }
  else
  {
    v51 = p2->m_nInBufWord;
    v52 = (v51 & CBitBuffer::s_nMaskTable[v49]) << p2->m_nBitsAvail;
    p2->m_nBitsAvail = 32 - v49;
    v44 = v52 | v48;
    p2->m_nInBufWord = v51 >> v49;
  }
  return highInt1 != highInt2 || lowInt1 != v44;
}

//------------------------------------------------------------------------------
// Address: 0x1016BDB0
// Name: char const __near * Int64_GetTypeNameString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Int64_GetTypeNameString()
{
  return "DPT_Int64";
}

//------------------------------------------------------------------------------
// Address: 0x1016BDC0
// Name: bool Int64_IsZero(unsigned char const __near *,class DVariant __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Int64_IsZero(const unsigned __int8 *pStruct, DVariant *pVar)
{
  return pVar->m_Int64 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016BDE0
// Name: void Int64_DecodeZero(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int64_DecodeZero(DecodeInfo *pInfo)
{
  const RecvProp *m_pRecvProp; // ecx

  m_pRecvProp = pInfo->m_pRecvProp;
  pInfo->m_Value.m_Int64 = 0;
  if ( m_pRecvProp != nullptr )
    m_pRecvProp->m_ProxyFn(a1: pInfo, a2: pInfo->m_pStruct, a3: pInfo->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1016BE10
// Name: bool Int64_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Int64_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  int m_nBitsAvail; // ecx
  int v3; // edx
  unsigned int v4; // esi
  unsigned int v5; // edi
  int v6; // ecx
  unsigned int v7; // esi
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // esi
  unsigned int v17; // ecx
  int v18; // edi
  const unsigned int *v19; // edx
  const unsigned int *v20; // esi
  const unsigned int *v21; // ecx
  unsigned int v22; // edi
  int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // esi
  unsigned int v26; // ebx
  unsigned int highInt1; // [esp+14h] [ebp+8h]

  m_nBitsAvail = pIn->m_nBitsAvail;
  v3 = pProp->m_nBits - 32;
  if ( m_nBitsAvail < v3 )
  {
    m_pBufferEnd = pIn->m_pBufferEnd;
    m_nInBufWord = pIn->m_nInBufWord;
    v12 = v3 - m_nBitsAvail;
    m_pDataIn = pIn->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
LABEL_15:
        if ( pIn->m_bOverflow )
        {
          highInt1 = 0;
          goto LABEL_20;
        }
        v14 = pIn->m_nInBufWord;
        v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << pIn->m_nBitsAvail;
        pIn->m_nBitsAvail = 32 - v12;
        v5 = v15 | m_nInBufWord;
        v7 = v14 >> v12;
        goto LABEL_18;
      }
      pIn->m_nInBufWord = *m_pDataIn;
    }
    pIn->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v4 = pIn->m_nInBufWord;
  v5 = v4 & CBitBuffer::s_nMaskTable[v3];
  v6 = m_nBitsAvail - v3;
  pIn->m_nBitsAvail = v6;
  if ( v6 == 0 )
  {
    v8 = pIn->m_pDataIn;
    v9 = pIn->m_pBufferEnd;
    pIn->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      pIn->m_nInBufWord = *v8;
      pIn->m_pDataIn = v8 + 1;
    }
    else
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v7 = v4 >> v3;
LABEL_18:
  pIn->m_nInBufWord = v7;
LABEL_19:
  highInt1 = v5;
LABEL_20:
  v16 = pIn->m_nBitsAvail;
  if ( v16 >= 32 )
  {
    v17 = pIn->m_nInBufWord;
    pIn->m_nBitsAvail = v16 - 32;
    if ( v16 == 32 )
    {
      v19 = pIn->m_pDataIn;
      v20 = pIn->m_pBufferEnd;
      pIn->m_nBitsAvail = 32;
      if ( v19 == v20 )
      {
        pIn->m_nBitsAvail = 1;
        pIn->m_nInBufWord = 0;
        pIn->m_pDataIn = v19 + 1;
        v18 = v17;
      }
      else
      {
        if ( v19 <= v20 )
        {
          pIn->m_nInBufWord = *v19;
          pIn->m_pDataIn = v19 + 1;
        }
        else
        {
          pIn->m_bOverflow = true;
          pIn->m_nInBufWord = 0;
        }
        v18 = v17;
      }
    }
    else
    {
      pIn->m_nInBufWord = 0;
      v18 = v17;
    }
    return highInt1 == 0 && v18 == 0;
  }
  v21 = pIn->m_pDataIn;
  v22 = pIn->m_nInBufWord;
  v23 = 32 - v16;
  v24 = pIn->m_pBufferEnd;
  if ( v21 == v24 )
  {
    pIn->m_nBitsAvail = 1;
    pIn->m_nInBufWord = 0;
    pIn->m_bOverflow = true;
  }
  else
  {
    if ( v21 > v24 )
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
      goto LABEL_35;
    }
    pIn->m_nInBufWord = *v21;
  }
  pIn->m_pDataIn = v21 + 1;
LABEL_35:
  if ( pIn->m_bOverflow )
  {
    v18 = 0;
  }
  else
  {
    v25 = pIn->m_nInBufWord;
    v26 = (v25 & CBitBuffer::s_nMaskTable[v23]) << pIn->m_nBitsAvail;
    pIn->m_nBitsAvail = 32 - v23;
    v18 = v26 | v22;
    pIn->m_nInBufWord = v25 >> v23;
  }
  return highInt1 == 0 && v18 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016BFE0
// Name: void Generic_FastCopy(class SendProp const __near *,class RecvProp const __near *,unsigned char const __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Generic_FastCopy(
        const SendProp *pSendProp,
        const RecvProp *pRecvProp,
        const unsigned __int8 *pSendData,
        unsigned __int8 *pRecvData,
        int objectID)
{
  void (__cdecl *m_ProxyFn)(const SendProp *, const void *, const void *, DVariant *, int, int); // eax
  void (__cdecl *v6)(const CRecvProxyData *, void *, void *); // edx
  unsigned __int8 *v7; // [esp-1Ch] [ebp-48h]
  const unsigned __int8 *v8; // [esp-10h] [ebp-3Ch]
  CRecvProxyData recvProxyData; // [esp+4h] [ebp-28h] BYREF

  v8 = &pSendData[pSendProp->m_Offset & 0xFFFFF];
  m_ProxyFn = pSendProp->m_ProxyFn;
  recvProxyData.m_Value.m_Type = DPT_Float;
  m_ProxyFn(a1: pSendProp, a2: pSendData, a3: v8, a4: &recvProxyData.m_Value, a5: 0, a6: objectID);
  v7 = &pRecvData[pRecvProp->m_Offset];
  v6 = pRecvProp->m_ProxyFn;
  recvProxyData.m_pRecvProp = pRecvProp;
  recvProxyData.m_iElement = 0;
  recvProxyData.m_ObjectID = objectID;
  v6(a1: &recvProxyData, a2: pRecvData, a3: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1016C040
// Name: void Int_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int_SkipProp(const SendProp *pProp, bf_read *pIn)
{
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax

  m_pData = pIn->m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
    if ( m_nDataBits >= pIn->m_nDataBits )
      m_nDataBits = pIn->m_nDataBits;
    CBitRead::Seek(this: pIn, nPosition: pProp->m_nBits + m_nDataBits);
  }
  else
  {
    CBitRead::Seek(this: pIn, nPosition: pProp->m_nBits);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C090
// Name: void Float_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Float_SkipProp(const SendProp *pProp, bf_read *pIn)
{
  int m_Flags; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v10; // edx
  const unsigned int *v11; // esi
  unsigned int v12; // edi
  int v13; // edx
  const unsigned int *v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  int v17; // esi
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx
  const unsigned int *v20; // eax
  int v21; // eax
  const unsigned int *v22; // eax
  int v23; // eax
  int m_nBits; // esi
  const unsigned int *v25; // eax
  int v26; // eax

  m_Flags = pProp->m_Flags;
  if ( (m_Flags & 2) != 0 )
  {
    m_nBitsAvail = pIn->m_nBitsAvail;
    if ( m_nBitsAvail >= 2 )
    {
      m_nInBufWord = pIn->m_nInBufWord;
      v5 = m_nInBufWord & 3;
      v6 = m_nBitsAvail - 2;
      pIn->m_nBitsAvail = v6;
      if ( v6 != 0 )
      {
        pIn->m_nInBufWord = m_nInBufWord >> 2;
        v7 = m_nInBufWord & 3;
      }
      else
      {
        m_pDataIn = pIn->m_pDataIn;
        m_pBufferEnd = pIn->m_pBufferEnd;
        pIn->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          pIn->m_pDataIn = m_pDataIn + 1;
          pIn->m_nBitsAvail = 1;
          pIn->m_nInBufWord = 0;
          v7 = v5;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            v10 = *m_pDataIn;
            pIn->m_pDataIn = m_pDataIn + 1;
            pIn->m_nInBufWord = v10;
          }
          else
          {
            pIn->m_bOverflow = true;
            pIn->m_nInBufWord = 0;
          }
          v7 = v5;
        }
      }
LABEL_19:
      if ( v7 != 0 )
      {
        v17 = 1;
        if ( (v7 & 1) != 0 )
          v17 = 15;
        if ( (v7 & 2) != 0 )
          v17 += 5;
        m_pData = pIn->m_pData;
        if ( m_pData != nullptr )
        {
          m_nDataBits = 32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
          if ( m_nDataBits >= pIn->m_nDataBits )
            m_nDataBits = pIn->m_nDataBits;
          CBitRead::Seek(this: pIn, nPosition: v17 + m_nDataBits);
        }
        else
        {
          CBitRead::Seek(this: pIn, nPosition: v17);
        }
      }
      return;
    }
    v11 = pIn->m_pBufferEnd;
    v12 = pIn->m_nInBufWord;
    v13 = 2 - m_nBitsAvail;
    v14 = pIn->m_pDataIn;
    if ( v14 == v11 )
    {
      pIn->m_nBitsAvail = 1;
      pIn->m_nInBufWord = 0;
      pIn->m_bOverflow = true;
    }
    else
    {
      if ( v14 > v11 )
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
LABEL_17:
        if ( pIn->m_bOverflow )
          return;
        v15 = pIn->m_nInBufWord;
        v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << pIn->m_nBitsAvail;
        pIn->m_nBitsAvail = 32 - v13;
        v7 = v16 | v12;
        pIn->m_nInBufWord = v15 >> v13;
        goto LABEL_19;
      }
      pIn->m_nInBufWord = *v14;
    }
    pIn->m_pDataIn = v14 + 1;
    goto LABEL_17;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_None);
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_LowPrecision);
  }
  else if ( (m_Flags & 0x4000) != 0 )
  {
    CBitRead::ReadBitCoordMP(this: pIn, coordType: kCW_Integral);
  }
  else if ( (m_Flags & 4) != 0 )
  {
    v20 = pIn->m_pData;
    if ( v20 != nullptr )
    {
      v21 = 32 * (pIn->m_pDataIn - v20) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
      if ( v21 >= pIn->m_nDataBits )
        v21 = pIn->m_nDataBits;
      CBitRead::Seek(this: pIn, nPosition: v21 + 32);
    }
    else
    {
      CBitRead::Seek(this: pIn, nPosition: 32);
    }
  }
  else if ( (m_Flags & 0x20) != 0 )
  {
    v22 = pIn->m_pData;
    if ( v22 != nullptr )
    {
      v23 = 32 * (pIn->m_pDataIn - v22) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
      if ( v23 >= pIn->m_nDataBits )
        v23 = pIn->m_nDataBits;
      CBitRead::Seek(this: pIn, nPosition: v23 + 12);
    }
    else
    {
      CBitRead::Seek(this: pIn, nPosition: 12);
    }
  }
  else if ( (m_Flags & 0x8000) != 0 )
  {
    CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_None);
  }
  else if ( (m_Flags & 0x10000) != 0 )
  {
    CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_LowPrecision);
  }
  else if ( (m_Flags & 0x20000) != 0 )
  {
    CBitRead::ReadBitCellCoord(this: pIn, bits: pProp->m_nBits, coordType: kCW_Integral);
  }
  else
  {
    m_nBits = pProp->m_nBits;
    v25 = pIn->m_pData;
    if ( v25 != nullptr )
    {
      v26 = 32 * (pIn->m_pDataIn - v25) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
      if ( v26 >= pIn->m_nDataBits )
        v26 = pIn->m_nDataBits;
      CBitRead::Seek(this: pIn, nPosition: m_nBits + v26);
    }
    else
    {
      CBitRead::Seek(this: pIn, nPosition: m_nBits);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C360
// Name: void Vector_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector_Encode(
        const unsigned __int8 *pStruct,
        DVariant *pVar,
        const SendProp *pProp,
        bf_write *pOut,
        DVariant *objectID)
{
  BOOL v5; // eax
  int m_iCurBit; // ecx
  unsigned __int8 *m_pData; // esi

  EncodeFloat(pProp, fVal: pVar->m_Float, pOut, (int)objectID);
  EncodeFloat(pProp, fVal: pVar->m_Vector[1], pOut, (int)objectID);
  if ( (pProp->m_Flags & 0x20) != 0 )
  {
    v5 = pVar->m_Vector[2] <= -0.0004885197850512946;
    m_iCurBit = pOut->m_iCurBit;
    if ( m_iCurBit + 1 > pOut->m_nDataBits )
      pOut->m_bOverflow = true;
    if ( !pOut->m_bOverflow )
    {
      m_pData = pOut->m_pData;
      if ( v5 )
        m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      else
        m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++pOut->m_iCurBit;
    }
  }
  else
  {
    EncodeFloat(pProp, fVal: pVar->m_Vector[2], pOut, (int)objectID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C420
// Name: void Vector_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector_SkipProp(const SendProp *pProp, bf_read *pIn)
{
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax

  Float_SkipProp(pProp, pIn);
  Float_SkipProp(pProp, pIn);
  if ( (pProp->m_Flags & 0x20) != 0 )
  {
    m_pData = pIn->m_pData;
    if ( m_pData != nullptr )
    {
      m_nDataBits = 32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
      if ( m_nDataBits >= pIn->m_nDataBits )
        m_nDataBits = pIn->m_nDataBits;
      CBitRead::Seek(this: pIn, nPosition: m_nDataBits + 1);
    }
    else
    {
      CBitRead::Seek(this: pIn, nPosition: 1);
    }
  }
  else
  {
    Float_SkipProp(pProp, pIn);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C4A0
// Name: void VectorXY_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorXY_SkipProp(const SendProp *pProp, bf_read *pIn)
{
  Float_SkipProp(pProp, pIn);
  Float_SkipProp(pProp, pIn);
}

//------------------------------------------------------------------------------
// Address: 0x1016C4C0
// Name: int String_CompareDeltas(class SendProp const __near *,class bf_read __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl String_CompareDeltas(const SendProp *pProp, bf_read *p1, bf_read *p2)
{
  int m_nBitsAvail; // ecx
  unsigned int v5; // esi
  int v6; // ebx
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v11; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // edi
  const unsigned int *v18; // eax
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edi
  int v21; // eax
  const unsigned int *v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ebx
  const unsigned int *m_pData; // eax
  const unsigned int *m_nDataBits; // eax
  unsigned int v28; // [esp+Ch] [ebp-4h]
  bf_read *p1a; // [esp+1Ch] [ebp+Ch]

  m_nBitsAvail = p1->m_nBitsAvail;
  if ( m_nBitsAvail < 9 )
  {
    m_pBufferEnd = p1->m_pBufferEnd;
    m_nInBufWord = p1->m_nInBufWord;
    v11 = 9 - m_nBitsAvail;
    m_pDataIn = p1->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      p1->m_nBitsAvail = 1;
      p1->m_nInBufWord = 0;
      p1->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        p1->m_bOverflow = true;
        p1->m_nInBufWord = 0;
        goto LABEL_16;
      }
      p1->m_nInBufWord = *m_pDataIn;
    }
    p1->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( p1->m_bOverflow )
    {
      v6 = 0;
      p1a = nullptr;
    }
    else
    {
      v13 = p1->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << p1->m_nBitsAvail;
      p1->m_nBitsAvail = 32 - v11;
      v6 = v14 | m_nInBufWord;
      p1a = (bf_read *)v6;
      p1->m_nInBufWord = v13 >> v11;
    }
    goto LABEL_19;
  }
  v5 = p1->m_nInBufWord;
  p1->m_nBitsAvail = m_nBitsAvail - 9;
  if ( m_nBitsAvail == 9 )
  {
    v7 = p1->m_pDataIn;
    v8 = p1->m_pBufferEnd;
    p1->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      p1->m_nInBufWord = 0;
      v6 = v5 & 0x1FF;
      p1->m_nBitsAvail = 1;
      p1->m_pDataIn = v7 + 1;
      p1a = (bf_read *)v6;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v6 = v5 & 0x1FF;
        p1->m_nInBufWord = *v7;
        p1->m_pDataIn = v7 + 1;
      }
      else
      {
        p1->m_nInBufWord = 0;
        v6 = v5 & 0x1FF;
        p1->m_bOverflow = true;
      }
      p1a = (bf_read *)(v5 & 0x1FF);
    }
  }
  else
  {
    v6 = v5 & 0x1FF;
    p1->m_nInBufWord = v5 >> 9;
    p1a = (bf_read *)v6;
  }
LABEL_19:
  v15 = p2->m_nBitsAvail;
  v16 = p2->m_nInBufWord;
  if ( v15 >= 9 )
  {
    v17 = p2->m_nInBufWord & 0x1FF;
    p2->m_nBitsAvail = v15 - 9;
    if ( v15 == 9 )
    {
      v18 = p2->m_pDataIn;
      v19 = p2->m_pBufferEnd;
      p2->m_nBitsAvail = 32;
      if ( v18 == v19 )
      {
        p2->m_nBitsAvail = 1;
        p2->m_nInBufWord = 0;
        p2->m_pDataIn = v18 + 1;
      }
      else if ( v18 <= v19 )
      {
        p2->m_nInBufWord = *v18;
        p2->m_pDataIn = v18 + 1;
      }
      else
      {
        p2->m_bOverflow = true;
        p2->m_nInBufWord = 0;
      }
    }
    else
    {
      p2->m_nInBufWord = v16 >> 9;
    }
    goto LABEL_36;
  }
  v20 = p2->m_pBufferEnd;
  v28 = p2->m_nInBufWord;
  v21 = 9 - v15;
  v22 = p2->m_pDataIn;
  if ( v22 == v20 )
  {
    p2->m_nBitsAvail = 1;
    p2->m_nInBufWord = 0;
    p2->m_bOverflow = true;
  }
  else
  {
    if ( v22 > v20 )
    {
      p2->m_bOverflow = true;
      p2->m_nInBufWord = 0;
      goto LABEL_33;
    }
    p2->m_nInBufWord = *v22;
  }
  p2->m_pDataIn = v22 + 1;
LABEL_33:
  if ( p2->m_bOverflow )
  {
    v17 = 0;
  }
  else
  {
    v23 = p2->m_nInBufWord;
    v24 = (v23 & CBitBuffer::s_nMaskTable[v21]) << p2->m_nBitsAvail;
    p2->m_nBitsAvail = 32 - v21;
    p2->m_nInBufWord = v23 >> v21;
    v17 = v24 | v28;
    v6 = (int)p1a;
  }
LABEL_36:
  if ( v6 == v17 )
  {
    if ( v6 != 0 )
      return AreBitsDifferent(pBuf1: p1, pBuf2: p2, nBits: 8 * v6);
    else
      return 0;
  }
  else
  {
    m_pData = p1->m_pData;
    if ( m_pData != nullptr )
    {
      m_pData = (const unsigned int *)(32 * (p1->m_pDataIn - m_pData) - p1->m_nBitsAvail + 8 * (p1->m_nDataBytes & 3));
      if ( (int)m_pData >= p1->m_nDataBits )
        m_pData = (const unsigned int *)p1->m_nDataBits;
    }
    CBitRead::Seek(this: p1, nPosition: (int)&m_pData[2 * v6]);
    m_nDataBits = p2->m_pData;
    if ( m_nDataBits != nullptr )
    {
      m_nDataBits = (const unsigned int *)(32 * (p2->m_pDataIn - m_nDataBits)
                                         - p2->m_nBitsAvail
                                         + 8 * (p2->m_nDataBytes & 3));
      if ( (int)m_nDataBits >= p2->m_nDataBits )
        m_nDataBits = (const unsigned int *)p2->m_nDataBits;
    }
    CBitRead::Seek(this: p2, nPosition: (int)&m_nDataBits[2 * v17]);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C760
// Name: bool String_IsEncodedZero(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl String_IsEncodedZero(const SendProp *pProp, bf_read *pIn)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v8; // edx
  const unsigned int *v9; // esi
  unsigned int v10; // edi
  int v11; // edx
  const unsigned int *v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  const unsigned int *m_pData; // ecx

  m_nBitsAvail = pIn->m_nBitsAvail;
  if ( m_nBitsAvail >= 9 )
  {
    m_nInBufWord = pIn->m_nInBufWord;
    v4 = m_nInBufWord & 0x1FF;
    v5 = m_nBitsAvail - 9;
    pIn->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      pIn->m_nInBufWord = m_nInBufWord >> 9;
    }
    else
    {
      m_pDataIn = pIn->m_pDataIn;
      m_pBufferEnd = pIn->m_pBufferEnd;
      pIn->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pIn->m_nBitsAvail = 1;
        pIn->m_nInBufWord = 0;
        pIn->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v8 = *m_pDataIn;
        pIn->m_pDataIn = m_pDataIn + 1;
        pIn->m_nInBufWord = v8;
      }
      else
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
      }
    }
    goto LABEL_18;
  }
  v9 = pIn->m_pBufferEnd;
  v10 = pIn->m_nInBufWord;
  v11 = 9 - m_nBitsAvail;
  v12 = pIn->m_pDataIn;
  if ( v12 == v9 )
  {
    pIn->m_nBitsAvail = 1;
    pIn->m_nInBufWord = 0;
    pIn->m_bOverflow = true;
  }
  else
  {
    if ( v12 > v9 )
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
      goto LABEL_15;
    }
    pIn->m_nInBufWord = *v12;
  }
  pIn->m_pDataIn = v12 + 1;
LABEL_15:
  if ( pIn->m_bOverflow )
  {
    v4 = 0;
  }
  else
  {
    v13 = pIn->m_nInBufWord;
    v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << pIn->m_nBitsAvail;
    pIn->m_nBitsAvail = 32 - v11;
    pIn->m_nInBufWord = v13 >> v11;
    v4 = v14 | v10;
  }
LABEL_18:
  m_pData = pIn->m_pData;
  if ( m_pData != nullptr )
  {
    m_pData = (const unsigned int *)(32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3));
    if ( (int)m_pData >= pIn->m_nDataBits )
      m_pData = (const unsigned int *)pIn->m_nDataBits;
  }
  CBitRead::Seek(this: pIn, nPosition: (int)&m_pData[2 * v4]);
  return v4 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016C890
// Name: void String_SkipProp(class SendProp const __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl String_SkipProp(const SendProp *pProp, bf_read *pIn)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v8; // edx
  const unsigned int *v9; // esi
  unsigned int v10; // edi
  int v11; // edx
  const unsigned int *v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = pIn->m_nBitsAvail;
  if ( m_nBitsAvail >= 9 )
  {
    m_nInBufWord = pIn->m_nInBufWord;
    v4 = m_nInBufWord & 0x1FF;
    v5 = m_nBitsAvail - 9;
    pIn->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      pIn->m_nInBufWord = m_nInBufWord >> 9;
    }
    else
    {
      m_pDataIn = pIn->m_pDataIn;
      m_pBufferEnd = pIn->m_pBufferEnd;
      pIn->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pIn->m_nBitsAvail = 1;
        pIn->m_nInBufWord = 0;
        pIn->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v8 = *m_pDataIn;
        pIn->m_pDataIn = m_pDataIn + 1;
        pIn->m_nInBufWord = v8;
      }
      else
      {
        pIn->m_bOverflow = true;
        pIn->m_nInBufWord = 0;
      }
    }
    goto LABEL_18;
  }
  v9 = pIn->m_pBufferEnd;
  v10 = pIn->m_nInBufWord;
  v11 = 9 - m_nBitsAvail;
  v12 = pIn->m_pDataIn;
  if ( v12 == v9 )
  {
    pIn->m_nBitsAvail = 1;
    pIn->m_nInBufWord = 0;
    pIn->m_bOverflow = true;
  }
  else
  {
    if ( v12 > v9 )
    {
      pIn->m_bOverflow = true;
      pIn->m_nInBufWord = 0;
      goto LABEL_15;
    }
    pIn->m_nInBufWord = *v12;
  }
  pIn->m_pDataIn = v12 + 1;
LABEL_15:
  if ( pIn->m_bOverflow )
  {
    v4 = 0;
  }
  else
  {
    v13 = pIn->m_nInBufWord;
    v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << pIn->m_nBitsAvail;
    pIn->m_nBitsAvail = 32 - v11;
    pIn->m_nInBufWord = v13 >> v11;
    v4 = v14 | v10;
  }
LABEL_18:
  m_pData = pIn->m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
    if ( m_nDataBits >= pIn->m_nDataBits )
      m_nDataBits = pIn->m_nDataBits;
    CBitRead::Seek(this: pIn, nPosition: m_nDataBits + 8 * v4);
  }
  else
  {
    CBitRead::Seek(this: pIn, nPosition: 8 * v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C9D0
// Name: void Array_Decode(class DecodeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Array_Decode(SendProp *pInfo)
{
  SendProp *v2; // ebx
  char *m_pExcludeDTName; // ecx
  const RecvProp *v4; // eax
  char *m_pParentArrayPropName; // ecx
  void (__cdecl *m_ArrayLengthProxy)(void *, int, int); // edx
  int NumArrayLengthBits; // eax
  bf_read *m_fHighLowMul_low; // edx
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edi
  unsigned int v11; // ebx
  int v12; // ecx
  const unsigned int *v13; // eax
  const unsigned int *v14; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edi
  int v17; // edi
  DecodeInfo subDecodeInfo; // [esp+Ch] [ebp-248h] BYREF
  unsigned int v19; // [esp+244h] [ebp-10h]
  int elementStride; // [esp+248h] [ebp-Ch]
  void (__cdecl *lengthProxy)(void *, int, int); // [esp+24Ch] [ebp-8h]
  unsigned int v22; // [esp+250h] [ebp-4h]
  SendProp *pArrayProp; // [esp+25Ch] [ebp+8h]

  v2 = *((SendProp **)pInfo->m_pVarName + 6);
  m_pExcludeDTName = pInfo->m_pExcludeDTName;
  v4 = (const RecvProp *)pInfo->__vftable;
  subDecodeInfo.m_pIn = (bf_read *)LODWORD(pInfo->m_fHighLowMul);
  subDecodeInfo.m_ObjectID = pInfo->m_ElementStride;
  subDecodeInfo.m_iElement = pInfo->m_nElements;
  subDecodeInfo.m_pStruct = m_pExcludeDTName;
  m_pParentArrayPropName = pInfo->m_pParentArrayPropName;
  pArrayProp = v2;
  subDecodeInfo.m_Value.m_Type = DPT_Float;
  subDecodeInfo.m_pData = m_pParentArrayPropName;
  subDecodeInfo.m_pRecvProp = v4;
  subDecodeInfo.m_pProp = v2;
  elementStride = 0;
  lengthProxy = nullptr;
  if ( v4 != nullptr )
  {
    subDecodeInfo.m_pRecvProp = v4->m_pArrayProp;
    subDecodeInfo.m_pData = &m_pParentArrayPropName[subDecodeInfo.m_pRecvProp->m_Offset];
    m_ArrayLengthProxy = v4->m_ArrayLengthProxy;
    elementStride = v4->m_ElementStride;
    lengthProxy = m_ArrayLengthProxy;
  }
  NumArrayLengthBits = SendProp::GetNumArrayLengthBits(this: (SendProp *)pInfo->m_pVarName);
  m_fHighLowMul_low = (bf_read *)LODWORD(pInfo->m_fHighLowMul);
  m_nBitsAvail = m_fHighLowMul_low->m_nBitsAvail;
  m_nInBufWord = m_fHighLowMul_low->m_nInBufWord;
  if ( m_nBitsAvail < NumArrayLengthBits )
  {
    NumArrayLengthBits -= m_nBitsAvail;
    m_pDataIn = m_fHighLowMul_low->m_pDataIn;
    v19 = m_fHighLowMul_low->m_nInBufWord;
    m_pBufferEnd = m_fHighLowMul_low->m_pBufferEnd;
    if ( m_pDataIn == m_pBufferEnd )
    {
      m_fHighLowMul_low->m_nBitsAvail = 1;
      m_fHighLowMul_low->m_nInBufWord = 0;
      m_fHighLowMul_low->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        m_fHighLowMul_low->m_bOverflow = true;
        m_fHighLowMul_low->m_nInBufWord = 0;
LABEL_16:
        if ( m_fHighLowMul_low->m_bOverflow )
        {
          v17 = 0;
          goto LABEL_21;
        }
        m_nInBufWord = m_fHighLowMul_low->m_nInBufWord;
        v22 = (m_nInBufWord & CBitBuffer::s_nMaskTable[NumArrayLengthBits]) << m_fHighLowMul_low->m_nBitsAvail;
        v11 = v22 | v19;
        m_fHighLowMul_low->m_nBitsAvail = 32 - NumArrayLengthBits;
        goto LABEL_19;
      }
      m_fHighLowMul_low->m_nInBufWord = *m_pDataIn;
    }
    m_fHighLowMul_low->m_pDataIn = m_pDataIn + 1;
    goto LABEL_16;
  }
  v11 = m_nInBufWord & CBitBuffer::s_nMaskTable[NumArrayLengthBits];
  v12 = m_nBitsAvail - NumArrayLengthBits;
  m_fHighLowMul_low->m_nBitsAvail = v12;
  if ( v12 == 0 )
  {
    v13 = m_fHighLowMul_low->m_pDataIn;
    v14 = m_fHighLowMul_low->m_pBufferEnd;
    m_fHighLowMul_low->m_nBitsAvail = 32;
    if ( v13 == v14 )
    {
      m_fHighLowMul_low->m_nBitsAvail = 1;
      m_fHighLowMul_low->m_nInBufWord = 0;
      m_fHighLowMul_low->m_pDataIn = v13 + 1;
    }
    else if ( v13 <= v14 )
    {
      m_fHighLowMul_low->m_nInBufWord = *v13;
      m_fHighLowMul_low->m_pDataIn = v13 + 1;
    }
    else
    {
      m_fHighLowMul_low->m_bOverflow = true;
      m_fHighLowMul_low->m_nInBufWord = 0;
    }
    goto LABEL_20;
  }
LABEL_19:
  m_fHighLowMul_low->m_nInBufWord = m_nInBufWord >> NumArrayLengthBits;
LABEL_20:
  v17 = v11;
  v2 = pArrayProp;
LABEL_21:
  if ( lengthProxy != nullptr )
    lengthProxy(a1: pInfo->m_pExcludeDTName, a2: pInfo->m_ElementStride, a3: v17);
  for ( subDecodeInfo.m_iElement = 0; subDecodeInfo.m_iElement < v17; ++subDecodeInfo.m_iElement )
  {
    (*(&funcs_1016CB84 + 9 * v2->m_Type))(pInfo: &subDecodeInfo);
    subDecodeInfo.m_pData = (char *)subDecodeInfo.m_pData + elementStride;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CBB0
// Name: void Int64_Encode(unsigned char const __near *,class DVariant __near *,class SendProp const __near *,class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Int64_Encode(const unsigned __int8 *pStruct, DVariant *pVar, const SendProp *pProp, bf_write *pOut)
{
  unsigned int m_Int; // ecx
  int v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // edi
  int m_iCurBit; // ecx
  char v9; // dl

  m_Int = pVar->m_Int;
  v5 = LODWORD(pVar->m_Vector[1]);
  if ( v5 < 0 )
  {
    m_Int = -m_Int;
    v9 = 1;
    v5 = (unsigned __int64)-__SPAIR64__(v5, m_Int) >> 32;
  }
  else
  {
    v9 = 0;
  }
  v6 = v5;
  v7 = m_Int;
  if ( (pProp->m_Flags & 1) != 0 )
  {
    bf_write::WriteUBitLong(this: pOut, curData: m_Int, numbits: 32, bCheckRange: true);
    bf_write::WriteUBitLong(this: pOut, curData: v6, numbits: pProp->m_nBits - 32, bCheckRange: true);
  }
  else
  {
    m_iCurBit = pOut->m_iCurBit;
    if ( m_iCurBit + 1 > pOut->m_nDataBits )
      pOut->m_bOverflow = true;
    if ( !pOut->m_bOverflow )
    {
      if ( v9 != 0 )
        pOut->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      else
        pOut->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++pOut->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: pOut, curData: v7, numbits: 32, bCheckRange: true);
    bf_write::WriteUBitLong(this: pOut, curData: v6, numbits: pProp->m_nBits - 33, bCheckRange: true);
  }
}

} // namespace engine_xlsp
