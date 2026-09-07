// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/lzma/lzma.cpp
// Functions: 7
// ============================================================

#include "utils\lzma\lzma.h"

//------------------------------------------------------------------------------
// Address: 0x10017B20
// Name: public: virtual long CInStreamRam::Read(void __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CInStreamRam::Read(CInStreamRam *this, _BYTE *data, unsigned int size, unsigned int *processedSize)
{
  unsigned int v4; // esi
  unsigned int i; // eax

  v4 = size;
  if ( size > this->Size - this->Pos )
    v4 = this->Size - this->Pos;
  for ( i = 0; i < v4; ++i )
    data[i] = this->Data[i + this->Pos];
  this->Pos += v4;
  if ( processedSize != nullptr )
    *processedSize = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10017B70
// Name: public: long COutStreamRam::WriteByte(unsigned char)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutStreamRam::WriteByte(COutStreamRam *this, unsigned __int8 b)
{
  unsigned int Pos; // eax

  Pos = this->Pos;
  if ( Pos < this->Size )
  {
    this->Data[Pos] = b;
    ++this->Pos;
    return 0;
  }
  else
  {
    this->Overflow = true;
    return -2147467259;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017BA0
// Name: public: virtual long COutStreamRam::Write(void const __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall COutStreamRam::Write(
        COutStreamRam *this,
        _BYTE *data,
        unsigned int size,
        unsigned int *processedSize)
{
  unsigned int i; // ecx
  unsigned int Pos; // esi

  for ( i = 0; i < size; ++i )
  {
    Pos = this->Pos;
    if ( Pos >= this->Size )
      break;
    this->Data[Pos] = data[i];
    ++this->Pos;
  }
  if ( processedSize != nullptr )
    *processedSize = i;
  if ( i == size )
    return 0;
  this->Overflow = true;
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10017C10
// Name: public: virtual unsigned long COutStreamRam::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall COutStreamRam::Release(CInStreamRam *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    free(pMem: this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017C30
// Name: public: virtual unsigned long CInStreamRam::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CInStreamRam::AddRef(CInStreamRam *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017C50
// Name: int LzmaEncode(unsigned char const __near *,unsigned int,unsigned char __near *,unsigned int,unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __usercall LzmaEncode@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const unsigned __int8 *inBuffer,
        unsigned int inSize,
        unsigned __int8 *outBuffer,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        unsigned int dictionarySize)
{
  NCompress::NLZMA::CEncoder *v10; // eax
  NCompress::NLZMA::CEncoder *v11; // eax
  _DWORD *v12; // ebx
  COutStreamRam *v13; // eax
  COutStreamRam *v14; // esi
  _DWORD *v15; // eax
  _DWORD *v16; // edi
  int v17; // eax
  tagPROPVARIANT properties[8]; // [esp+0h] [ebp-A0h] BYREF
  unsigned int propIDs[8]; // [esp+80h] [ebp-20h] BYREF
  int mainResult; // [esp+B4h] [ebp+14h]
  int mainResulta; // [esp+B4h] [ebp+14h]

  *outSizeProcessed = 0;
  if ( outSize < 0xD )
    return 3;
  v10 = (NCompress::NLZMA::CEncoder *)operator new(nSize: 0x33B28u);
  if ( v10 != nullptr )
  {
    v11 = NCompress::NLZMA::CEncoder::CEncoder(this: v10);
    v12 = &v11->ICompressCoder::IUnknown::__vftable;
    if ( v11 != nullptr )
      v11->AddRef(this: v11);
  }
  else
  {
    v12 = nullptr;
  }
  properties[1].vt = 19;
  properties[4].vt = 19;
  properties[0].vt = 19;
  properties[0].decVal.Lo32 = dictionarySize;
  properties[2].vt = 19;
  properties[5].vt = 19;
  properties[7].vt = 11;
  properties[3].vt = 19;
  properties[7].iVal = 0;
  propIDs[0] = 1024;
  propIDs[1] = 1088;
  propIDs[2] = 1089;
  propIDs[3] = 1090;
  propIDs[4] = 1136;
  propIDs[5] = 1104;
  propIDs[6] = 1105;
  propIDs[7] = 1168;
  properties[1].decVal.Lo32 = 2;
  properties[2].decVal.Lo32 = 3;
  properties[3].decVal.Lo32 = 0;
  properties[4].decVal.Lo32 = 2;
  properties[5].decVal.Lo32 = 64;
  properties[6].vt = 8;
  properties[6].decVal.Lo32 = (unsigned int)L"BT4";
  if ( (*(int (__stdcall **)(_DWORD *, unsigned int *, tagPROPVARIANT *, int, int, int))(v12[2] + 12))(
         a1: v12 + 2,
         a2: propIDs,
         a3: properties,
         a4: 8,
         a5: a2,
         a6: a1) != 0 )
  {
    (*(void (__stdcall **)(_DWORD *, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))(*v12 + 8))(
      a1: v12,
      a2: *(_DWORD *)&properties[0].vt,
      a3: properties[0].decVal.Hi32,
      a4: properties[0].decVal.Lo32,
      a5: properties[0].decVal.Mid32,
      a6: *(_DWORD *)&properties[1].vt,
      a7: properties[1].decVal.Hi32,
      a8: properties[1].decVal.Lo32,
      a9: properties[1].decVal.Mid32,
      a10: *(_DWORD *)&properties[2].vt,
      a11: properties[2].decVal.Hi32,
      a12: properties[2].decVal.Lo32,
      a13: properties[2].decVal.Mid32,
      a14: *(_DWORD *)&properties[3].vt,
      a15: properties[3].decVal.Hi32,
      a16: properties[3].decVal.Lo32,
      a17: properties[3].decVal.Mid32,
      a18: *(_DWORD *)&properties[4].vt,
      a19: properties[4].decVal.Hi32,
      a20: properties[4].decVal.Lo32,
      a21: properties[4].decVal.Mid32,
      a22: *(_DWORD *)&properties[5].vt,
      a23: properties[5].decVal.Hi32,
      a24: properties[5].decVal.Lo32,
      a25: properties[5].decVal.Mid32,
      a26: *(_DWORD *)&properties[6].vt,
      a27: properties[6].decVal.Hi32,
      a28: properties[6].decVal.Lo32,
      a29: properties[6].decVal.Mid32,
      a30: *(_DWORD *)&properties[7].vt,
      a31: properties[7].decVal.Hi32,
      a32: properties[7].decVal.Lo32,
      a33: properties[7].decVal.Mid32,
      a34: propIDs[0],
      a35: propIDs[1],
      a36: propIDs[2],
      a37: propIDs[3],
      a38: propIDs[4],
      a39: propIDs[5]);
    return 1;
  }
  v13 = (COutStreamRam *)operator new(nSize: 0x18u);
  v14 = v13;
  if ( v13 != nullptr )
  {
    v13->__m_RefCount = 0;
    v13->__vftable = (COutStreamRam_vtbl *)&COutStreamRam::`vftable';
    ((void (__stdcall *)(COutStreamRam *, int))v13->AddRef)(a1: v13, a2: a3);
    v15 = operator new(nSize: 0x14u);
    v16 = v15;
    if ( v15 != nullptr )
    {
      v15[1] = 0;
      *v15 = &CInStreamRam::`vftable';
      (*(void (__stdcall **)(_DWORD *))(*v15 + 4))(a1: v15);
      v14->Size = outSize;
      v14->Data = outBuffer;
      v14->Pos = 0;
      v14->Overflow = false;
      if ( (*(int (__stdcall **)(_DWORD *, COutStreamRam *))(v12[3] + 12))(a1: v12 + 3, a2: v14) != 0 )
      {
LABEL_12:
        (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
        ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
        (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
        return 3;
      }
      if ( v14->Pos == 5 )
      {
        mainResult = 0;
        while ( COutStreamRam::WriteByte(this: v14, b: (unsigned __int64)inSize >> mainResult) == 0 )
        {
          mainResult += 8;
          if ( mainResult >= 64 )
          {
            v14->Overflow = false;
            v16[3] = inSize;
            v16[2] = inBuffer;
            v16[4] = 0;
            mainResulta = 0;
            v17 = (*(int (__stdcall **)(_DWORD *, _DWORD *, COutStreamRam *, _DWORD, _DWORD, _DWORD))(*v12 + 12))(
                    a1: v12,
                    a2: v16,
                    a3: v14,
                    a4: 0,
                    a5: 0,
                    a6: 0);
            if ( v17 == -2147024882 )
              mainResulta = 2;
            if ( v14->Overflow )
            {
              mainResulta = 3;
            }
            else if ( v17 != 0 )
            {
              mainResulta = 1;
            }
            *outSizeProcessed = v14->Pos;
            (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
            ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
            (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
            return mainResulta;
          }
        }
        goto LABEL_12;
      }
      (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
      ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
      (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
      return 1;
    }
    else
    {
      ((void (__stdcall *)(COutStreamRam *, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))v14->Release)(
        a1: v14,
        a2: *(_DWORD *)&properties[0].vt,
        a3: properties[0].decVal.Hi32,
        a4: properties[0].decVal.Lo32,
        a5: properties[0].decVal.Mid32,
        a6: *(_DWORD *)&properties[1].vt,
        a7: properties[1].decVal.Hi32,
        a8: properties[1].decVal.Lo32,
        a9: properties[1].decVal.Mid32,
        a10: *(_DWORD *)&properties[2].vt,
        a11: properties[2].decVal.Hi32,
        a12: properties[2].decVal.Lo32,
        a13: properties[2].decVal.Mid32,
        a14: *(_DWORD *)&properties[3].vt,
        a15: properties[3].decVal.Hi32,
        a16: properties[3].decVal.Lo32,
        a17: properties[3].decVal.Mid32,
        a18: *(_DWORD *)&properties[4].vt,
        a19: properties[4].decVal.Hi32,
        a20: properties[4].decVal.Lo32,
        a21: properties[4].decVal.Mid32,
        a22: *(_DWORD *)&properties[5].vt,
        a23: properties[5].decVal.Hi32,
        a24: properties[5].decVal.Lo32,
        a25: properties[5].decVal.Mid32,
        a26: *(_DWORD *)&properties[6].vt,
        a27: properties[6].decVal.Hi32,
        a28: properties[6].decVal.Lo32,
        a29: properties[6].decVal.Mid32,
        a30: *(_DWORD *)&properties[7].vt,
        a31: properties[7].decVal.Hi32,
        a32: properties[7].decVal.Lo32,
        a33: properties[7].decVal.Mid32,
        a34: propIDs[0],
        a35: propIDs[1],
        a36: propIDs[2],
        a37: propIDs[3],
        a38: propIDs[4]);
      (*(void (__stdcall **)(_DWORD *))(*v12 + 8))(a1: v12);
      return 2;
    }
  }
  else
  {
    (*(void (__stdcall **)(_DWORD *, int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))(*v12 + 8))(
      a1: v12,
      a2: a3,
      a3: *(_DWORD *)&properties[0].vt,
      a4: properties[0].decVal.Hi32,
      a5: properties[0].decVal.Lo32,
      a6: properties[0].decVal.Mid32,
      a7: *(_DWORD *)&properties[1].vt,
      a8: properties[1].decVal.Hi32,
      a9: properties[1].decVal.Lo32,
      a10: properties[1].decVal.Mid32,
      a11: *(_DWORD *)&properties[2].vt,
      a12: properties[2].decVal.Hi32,
      a13: properties[2].decVal.Lo32,
      a14: properties[2].decVal.Mid32,
      a15: *(_DWORD *)&properties[3].vt,
      a16: properties[3].decVal.Hi32,
      a17: properties[3].decVal.Lo32,
      a18: properties[3].decVal.Mid32,
      a19: *(_DWORD *)&properties[4].vt,
      a20: properties[4].decVal.Hi32,
      a21: properties[4].decVal.Lo32,
      a22: properties[4].decVal.Mid32,
      a23: *(_DWORD *)&properties[5].vt,
      a24: properties[5].decVal.Hi32,
      a25: properties[5].decVal.Lo32,
      a26: properties[5].decVal.Mid32,
      a27: *(_DWORD *)&properties[6].vt,
      a28: properties[6].decVal.Hi32,
      a29: properties[6].decVal.Lo32,
      a30: properties[6].decVal.Mid32,
      a31: *(_DWORD *)&properties[7].vt,
      a32: properties[7].decVal.Hi32,
      a33: properties[7].decVal.Lo32,
      a34: properties[7].decVal.Mid32,
      a35: propIDs[0],
      a36: propIDs[1],
      a37: propIDs[2],
      a38: propIDs[3],
      a39: propIDs[4]);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017F40
// Name: unsigned char __near * LZMA_Compress(unsigned char __near *,unsigned int,unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl LZMA_Compress(
        unsigned __int8 *pInput,
        unsigned int inputSize,
        unsigned int *pOutputSize,
        char dictionarySize)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v5; // esi
  unsigned int v6; // edi
  unsigned __int8 v7; // dl
  unsigned int v8; // [esp-10h] [ebp-14h]
  unsigned int compressedSize; // [esp+0h] [ebp-4h] BYREF

  *pOutputSize = 0;
  if ( inputSize <= 0x11 )
    return nullptr;
  result = (unsigned __int8 *)operator new(nSize: 21 * (inputSize / 0x14) + 0x10000);
  v5 = result;
  if ( result != nullptr )
  {
    if ( LzmaEncode(
           a1: (int)(result + 17),
           a2: 21 * (inputSize / 0x14) + 65519,
           a3: (int)result,
           inBuffer: pInput,
           inSize: inputSize,
           outBuffer: result + 17,
           outSize: 21 * (inputSize / 0x14) + 65519,
           outSizeProcessed: &compressedSize,
           dictionarySize: 1 << dictionarySize) != 0
      || (v6 = compressedSize + 4, compressedSize + 4 >= inputSize) )
    {
      free(pMem: v5);
      return nullptr;
    }
    else
    {
      v7 = v5[21];
      v8 = compressedSize - 13;
      *((_DWORD *)v5 + 2) = compressedSize - 13;
      *((_DWORD *)v5 + 1) = inputSize;
      *((_DWORD *)v5 + 3) = *(_DWORD *)(v5 + 17);
      *(_DWORD *)v5 = 1095588428;
      v5[16] = v7;
      memcpy(dst: v5 + 17, src: v5 + 30, count: v8);
      *pOutputSize = v6;
      return v5;
    }
  }
  return result;
}

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004B6690
// Name: public: virtual long CInStreamRam::Read(void __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CInStreamRam::Read(CInStreamRam *this, _BYTE *data, unsigned int size, unsigned int *processedSize)
{
  unsigned int v4; // esi
  unsigned int i; // eax

  v4 = size;
  if ( size > this->Size - this->Pos )
    v4 = this->Size - this->Pos;
  for ( i = 0; i < v4; ++i )
    data[i] = this->Data[i + this->Pos];
  this->Pos += v4;
  if ( processedSize != nullptr )
    *processedSize = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B66E0
// Name: public: long COutStreamRam::WriteByte(unsigned char)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutStreamRam::WriteByte(COutStreamRam *this, unsigned __int8 b)
{
  unsigned int Pos; // eax

  Pos = this->Pos;
  if ( Pos < this->Size )
  {
    this->Data[Pos] = b;
    ++this->Pos;
    return 0;
  }
  else
  {
    this->Overflow = true;
    return -2147467259;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6710
// Name: public: virtual long COutStreamRam::Write(void const __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall COutStreamRam::Write(
        COutStreamRam *this,
        _BYTE *data,
        unsigned int size,
        unsigned int *processedSize)
{
  unsigned int i; // ecx
  unsigned int Pos; // esi

  for ( i = 0; i < size; ++i )
  {
    Pos = this->Pos;
    if ( Pos >= this->Size )
      break;
    this->Data[Pos] = data[i];
    ++this->Pos;
  }
  if ( processedSize != nullptr )
    *processedSize = i;
  if ( i == size )
    return 0;
  this->Overflow = true;
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x004B6770
// Name: public: virtual unsigned long CInStreamRam::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CInStreamRam::AddRef(CInStreamRam *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B6790
// Name: public: virtual unsigned long COutStreamRam::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall COutStreamRam::Release(CInStreamRam *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    free(pMem: this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B67B0
// Name: int LzmaEncode(unsigned char const __near *,unsigned int,unsigned char __near *,unsigned int,unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __usercall LzmaEncode@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const unsigned __int8 *inBuffer,
        unsigned int inSize,
        unsigned __int8 *outBuffer,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        unsigned int dictionarySize)
{
  NCompress::NLZMA::CEncoder *v10; // eax
  NCompress::NLZMA::CEncoder *v11; // eax
  _DWORD *v12; // ebx
  COutStreamRam *v13; // eax
  COutStreamRam *v14; // esi
  _DWORD *v15; // eax
  _DWORD *v16; // edi
  int v17; // eax
  tagPROPVARIANT properties[8]; // [esp+0h] [ebp-A0h] BYREF
  unsigned int propIDs[8]; // [esp+80h] [ebp-20h] BYREF
  int mainResult; // [esp+B4h] [ebp+14h]
  int mainResulta; // [esp+B4h] [ebp+14h]

  *outSizeProcessed = 0;
  if ( outSize < 0xD )
    return 3;
  v10 = (NCompress::NLZMA::CEncoder *)operator new(nSize: 0x33B28u);
  if ( v10 != nullptr )
  {
    v11 = NCompress::NLZMA::CEncoder::CEncoder(this: v10);
    v12 = &v11->ICompressCoder::IUnknown::__vftable;
    if ( v11 != nullptr )
      v11->AddRef(this: v11);
  }
  else
  {
    v12 = nullptr;
  }
  properties[1].vt = 19;
  properties[4].vt = 19;
  properties[0].vt = 19;
  properties[0].decVal.Lo32 = dictionarySize;
  properties[2].vt = 19;
  properties[5].vt = 19;
  properties[7].vt = 11;
  properties[3].vt = 19;
  properties[7].iVal = 0;
  propIDs[0] = 1024;
  propIDs[1] = 1088;
  propIDs[2] = 1089;
  propIDs[3] = 1090;
  propIDs[4] = 1136;
  propIDs[5] = 1104;
  propIDs[6] = 1105;
  propIDs[7] = 1168;
  properties[1].decVal.Lo32 = 2;
  properties[2].decVal.Lo32 = 3;
  properties[3].decVal.Lo32 = 0;
  properties[4].decVal.Lo32 = 2;
  properties[5].decVal.Lo32 = 64;
  properties[6].vt = 8;
  properties[6].decVal.Lo32 = (unsigned int)L"BT4";
  if ( (*(int (__stdcall **)(_DWORD *, unsigned int *, tagPROPVARIANT *, int, int, int))(v12[2] + 12))(
         a1: v12 + 2,
         a2: propIDs,
         a3: properties,
         a4: 8,
         a5: a2,
         a6: a1) != 0 )
  {
    (*(void (__stdcall **)(_DWORD *, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))(*v12 + 8))(
      a1: v12,
      a2: *(_DWORD *)&properties[0].vt,
      a3: properties[0].decVal.Hi32,
      a4: properties[0].decVal.Lo32,
      a5: properties[0].decVal.Mid32,
      a6: *(_DWORD *)&properties[1].vt,
      a7: properties[1].decVal.Hi32,
      a8: properties[1].decVal.Lo32,
      a9: properties[1].decVal.Mid32,
      a10: *(_DWORD *)&properties[2].vt,
      a11: properties[2].decVal.Hi32,
      a12: properties[2].decVal.Lo32,
      a13: properties[2].decVal.Mid32,
      a14: *(_DWORD *)&properties[3].vt,
      a15: properties[3].decVal.Hi32,
      a16: properties[3].decVal.Lo32,
      a17: properties[3].decVal.Mid32,
      a18: *(_DWORD *)&properties[4].vt,
      a19: properties[4].decVal.Hi32,
      a20: properties[4].decVal.Lo32,
      a21: properties[4].decVal.Mid32,
      a22: *(_DWORD *)&properties[5].vt,
      a23: properties[5].decVal.Hi32,
      a24: properties[5].decVal.Lo32,
      a25: properties[5].decVal.Mid32,
      a26: *(_DWORD *)&properties[6].vt,
      a27: properties[6].decVal.Hi32,
      a28: properties[6].decVal.Lo32,
      a29: properties[6].decVal.Mid32,
      a30: *(_DWORD *)&properties[7].vt,
      a31: properties[7].decVal.Hi32,
      a32: properties[7].decVal.Lo32,
      a33: properties[7].decVal.Mid32,
      a34: propIDs[0],
      a35: propIDs[1],
      a36: propIDs[2],
      a37: propIDs[3],
      a38: propIDs[4],
      a39: propIDs[5]);
    return 1;
  }
  v13 = (COutStreamRam *)operator new(nSize: 0x18u);
  v14 = v13;
  if ( v13 != nullptr )
  {
    v13->__m_RefCount = 0;
    v13->__vftable = (COutStreamRam_vtbl *)&COutStreamRam::`vftable';
    ((void (__stdcall *)(COutStreamRam *, int))v13->AddRef)(a1: v13, a2: a3);
    v15 = operator new(nSize: 0x14u);
    v16 = v15;
    if ( v15 != nullptr )
    {
      v15[1] = 0;
      *v15 = &CInStreamRam::`vftable';
      (*(void (__stdcall **)(_DWORD *))(*v15 + 4))(a1: v15);
      v14->Size = outSize;
      v14->Data = outBuffer;
      v14->Pos = 0;
      v14->Overflow = false;
      if ( (*(int (__stdcall **)(_DWORD *, COutStreamRam *))(v12[3] + 12))(a1: v12 + 3, a2: v14) != 0 )
      {
LABEL_12:
        (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
        ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
        (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
        return 3;
      }
      if ( v14->Pos == 5 )
      {
        mainResult = 0;
        while ( COutStreamRam::WriteByte(this: v14, b: (unsigned __int64)inSize >> mainResult) == 0 )
        {
          mainResult += 8;
          if ( mainResult >= 64 )
          {
            v14->Overflow = false;
            v16[3] = inSize;
            v16[2] = inBuffer;
            v16[4] = 0;
            mainResulta = 0;
            v17 = (*(int (__stdcall **)(_DWORD *, _DWORD *, COutStreamRam *, _DWORD, _DWORD, _DWORD))(*v12 + 12))(
                    a1: v12,
                    a2: v16,
                    a3: v14,
                    a4: 0,
                    a5: 0,
                    a6: 0);
            if ( v17 == -2147024882 )
              mainResulta = 2;
            if ( v14->Overflow )
            {
              mainResulta = 3;
            }
            else if ( v17 != 0 )
            {
              mainResulta = 1;
            }
            *outSizeProcessed = v14->Pos;
            (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
            ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
            (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
            return mainResulta;
          }
        }
        goto LABEL_12;
      }
      (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
      ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
      (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
      return 1;
    }
    else
    {
      ((void (__stdcall *)(COutStreamRam *, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))v14->Release)(
        a1: v14,
        a2: *(_DWORD *)&properties[0].vt,
        a3: properties[0].decVal.Hi32,
        a4: properties[0].decVal.Lo32,
        a5: properties[0].decVal.Mid32,
        a6: *(_DWORD *)&properties[1].vt,
        a7: properties[1].decVal.Hi32,
        a8: properties[1].decVal.Lo32,
        a9: properties[1].decVal.Mid32,
        a10: *(_DWORD *)&properties[2].vt,
        a11: properties[2].decVal.Hi32,
        a12: properties[2].decVal.Lo32,
        a13: properties[2].decVal.Mid32,
        a14: *(_DWORD *)&properties[3].vt,
        a15: properties[3].decVal.Hi32,
        a16: properties[3].decVal.Lo32,
        a17: properties[3].decVal.Mid32,
        a18: *(_DWORD *)&properties[4].vt,
        a19: properties[4].decVal.Hi32,
        a20: properties[4].decVal.Lo32,
        a21: properties[4].decVal.Mid32,
        a22: *(_DWORD *)&properties[5].vt,
        a23: properties[5].decVal.Hi32,
        a24: properties[5].decVal.Lo32,
        a25: properties[5].decVal.Mid32,
        a26: *(_DWORD *)&properties[6].vt,
        a27: properties[6].decVal.Hi32,
        a28: properties[6].decVal.Lo32,
        a29: properties[6].decVal.Mid32,
        a30: *(_DWORD *)&properties[7].vt,
        a31: properties[7].decVal.Hi32,
        a32: properties[7].decVal.Lo32,
        a33: properties[7].decVal.Mid32,
        a34: propIDs[0],
        a35: propIDs[1],
        a36: propIDs[2],
        a37: propIDs[3],
        a38: propIDs[4]);
      (*(void (__stdcall **)(_DWORD *))(*v12 + 8))(a1: v12);
      return 2;
    }
  }
  else
  {
    (*(void (__stdcall **)(_DWORD *, int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))(*v12 + 8))(
      a1: v12,
      a2: a3,
      a3: *(_DWORD *)&properties[0].vt,
      a4: properties[0].decVal.Hi32,
      a5: properties[0].decVal.Lo32,
      a6: properties[0].decVal.Mid32,
      a7: *(_DWORD *)&properties[1].vt,
      a8: properties[1].decVal.Hi32,
      a9: properties[1].decVal.Lo32,
      a10: properties[1].decVal.Mid32,
      a11: *(_DWORD *)&properties[2].vt,
      a12: properties[2].decVal.Hi32,
      a13: properties[2].decVal.Lo32,
      a14: properties[2].decVal.Mid32,
      a15: *(_DWORD *)&properties[3].vt,
      a16: properties[3].decVal.Hi32,
      a17: properties[3].decVal.Lo32,
      a18: properties[3].decVal.Mid32,
      a19: *(_DWORD *)&properties[4].vt,
      a20: properties[4].decVal.Hi32,
      a21: properties[4].decVal.Lo32,
      a22: properties[4].decVal.Mid32,
      a23: *(_DWORD *)&properties[5].vt,
      a24: properties[5].decVal.Hi32,
      a25: properties[5].decVal.Lo32,
      a26: properties[5].decVal.Mid32,
      a27: *(_DWORD *)&properties[6].vt,
      a28: properties[6].decVal.Hi32,
      a29: properties[6].decVal.Lo32,
      a30: properties[6].decVal.Mid32,
      a31: *(_DWORD *)&properties[7].vt,
      a32: properties[7].decVal.Hi32,
      a33: properties[7].decVal.Lo32,
      a34: properties[7].decVal.Mid32,
      a35: propIDs[0],
      a36: propIDs[1],
      a37: propIDs[2],
      a38: propIDs[3],
      a39: propIDs[4]);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6AA0
// Name: unsigned char __near * LZMA_Compress(unsigned char __near *,unsigned int,unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl LZMA_Compress(
        unsigned __int8 *pInput,
        unsigned int inputSize,
        unsigned int *pOutputSize,
        char dictionarySize)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v5; // esi
  unsigned int v6; // edi
  unsigned __int8 v7; // dl
  unsigned int v8; // [esp-10h] [ebp-14h]
  unsigned int compressedSize; // [esp+0h] [ebp-4h] BYREF

  *pOutputSize = 0;
  if ( inputSize <= 0x11 )
    return nullptr;
  result = (unsigned __int8 *)operator new(nSize: 21 * (inputSize / 0x14) + 0x10000);
  v5 = result;
  if ( result != nullptr )
  {
    if ( LzmaEncode(
           a1: (int)(result + 17),
           a2: 21 * (inputSize / 0x14) + 65519,
           a3: (int)result,
           inBuffer: pInput,
           inSize: inputSize,
           outBuffer: result + 17,
           outSize: 21 * (inputSize / 0x14) + 65519,
           outSizeProcessed: &compressedSize,
           dictionarySize: 1 << dictionarySize) != 0
      || (v6 = compressedSize + 4, compressedSize + 4 >= inputSize) )
    {
      free(pMem: v5);
      return nullptr;
    }
    else
    {
      v7 = v5[21];
      v8 = compressedSize - 13;
      *((_DWORD *)v5 + 2) = compressedSize - 13;
      *((_DWORD *)v5 + 1) = inputSize;
      *((_DWORD *)v5 + 3) = *(_DWORD *)(v5 + 17);
      *(_DWORD *)v5 = 1095588428;
      v5[16] = v7;
      memcpy(dst: v5 + 17, src: v5 + 30, count: v8);
      *pOutputSize = v6;
      return v5;
    }
  }
  return result;
}

} // namespace hlfaceposer

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x005201C0
// Name: public: virtual long CInStreamRam::Read(void __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CInStreamRam::Read(CInStreamRam *this, _BYTE *data, unsigned int size, unsigned int *processedSize)
{
  unsigned int v4; // esi
  unsigned int i; // eax

  v4 = size;
  if ( size > this->Size - this->Pos )
    v4 = this->Size - this->Pos;
  for ( i = 0; i < v4; ++i )
    data[i] = this->Data[i + this->Pos];
  this->Pos += v4;
  if ( processedSize != nullptr )
    *processedSize = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00520210
// Name: public: long COutStreamRam::WriteByte(unsigned char)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutStreamRam::WriteByte(COutStreamRam *this, unsigned __int8 b)
{
  unsigned int Pos; // eax

  Pos = this->Pos;
  if ( Pos < this->Size )
  {
    this->Data[Pos] = b;
    ++this->Pos;
    return 0;
  }
  else
  {
    this->Overflow = true;
    return -2147467259;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520240
// Name: public: virtual long COutStreamRam::Write(void const __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall COutStreamRam::Write(
        COutStreamRam *this,
        _BYTE *data,
        unsigned int size,
        unsigned int *processedSize)
{
  unsigned int i; // ecx
  unsigned int Pos; // esi

  for ( i = 0; i < size; ++i )
  {
    Pos = this->Pos;
    if ( Pos >= this->Size )
      break;
    this->Data[Pos] = data[i];
    ++this->Pos;
  }
  if ( processedSize != nullptr )
    *processedSize = i;
  if ( i == size )
    return 0;
  this->Overflow = true;
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x005202A0
// Name: bool LZMA_IsCompressed(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LZMA_IsCompressed(unsigned __int8 *pInput)
{
  return pInput != nullptr && *(_DWORD *)pInput == 1095588428;
}

//------------------------------------------------------------------------------
// Address: 0x005202C0
// Name: unsigned int LZMA_GetActualSize(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl LZMA_GetActualSize(unsigned __int8 *pInput)
{
  if ( pInput != nullptr && *(_DWORD *)pInput == 1095588428 )
    return *((_DWORD *)pInput + 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005202E0
// Name: public: virtual unsigned long CInStreamRam::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CInStreamRam::AddRef(CInStreamRam *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00520300
// Name: public: virtual unsigned long COutStreamRam::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall COutStreamRam::Release(CInStreamRam *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    free(pMem: this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00520320
// Name: int LzmaEncode(unsigned char const __near *,unsigned int,unsigned char __near *,unsigned int,unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __usercall LzmaEncode@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const unsigned __int8 *inBuffer,
        unsigned int inSize,
        unsigned __int8 *outBuffer,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        unsigned int dictionarySize)
{
  NCompress::NLZMA::CEncoder *v10; // eax
  NCompress::NLZMA::CEncoder *v11; // eax
  _DWORD *v12; // ebx
  COutStreamRam *v13; // eax
  COutStreamRam *v14; // esi
  _DWORD *v15; // eax
  _DWORD *v16; // edi
  int v17; // eax
  tagPROPVARIANT properties[8]; // [esp+0h] [ebp-A0h] BYREF
  unsigned int propIDs[8]; // [esp+80h] [ebp-20h] BYREF
  int mainResult; // [esp+B4h] [ebp+14h]
  int mainResulta; // [esp+B4h] [ebp+14h]

  *outSizeProcessed = 0;
  if ( outSize < 0xD )
    return 3;
  v10 = (NCompress::NLZMA::CEncoder *)MemAlloc_Alloc(nSize: 0x33B28u);
  if ( v10 != nullptr )
  {
    v11 = NCompress::NLZMA::CEncoder::CEncoder(this: v10);
    v12 = &v11->ICompressCoder::IUnknown::__vftable;
    if ( v11 != nullptr )
      v11->AddRef(a1: v11);
  }
  else
  {
    v12 = nullptr;
  }
  properties[1].vt = 19;
  properties[4].vt = 19;
  properties[0].vt = 19;
  properties[0].decVal.Lo32 = dictionarySize;
  properties[2].vt = 19;
  properties[5].vt = 19;
  properties[7].vt = 11;
  properties[3].vt = 19;
  properties[7].iVal = 0;
  propIDs[0] = 1024;
  propIDs[1] = 1088;
  propIDs[2] = 1089;
  propIDs[3] = 1090;
  propIDs[4] = 1136;
  propIDs[5] = 1104;
  propIDs[6] = 1105;
  propIDs[7] = 1168;
  properties[1].decVal.Lo32 = 2;
  properties[2].decVal.Lo32 = 3;
  properties[3].decVal.Lo32 = 0;
  properties[4].decVal.Lo32 = 2;
  properties[5].decVal.Lo32 = 64;
  properties[6].vt = 8;
  properties[6].decVal.Lo32 = (unsigned int)L"BT4";
  if ( (*(int (__stdcall **)(_DWORD *, unsigned int *, tagPROPVARIANT *, int, int, int))(v12[2] + 12))(
         a1: v12 + 2,
         a2: propIDs,
         a3: properties,
         a4: 8,
         a5: a2,
         a6: a1) != 0 )
  {
    (*(void (__stdcall **)(_DWORD *, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))(*v12 + 8))(
      a1: v12,
      a2: *(_DWORD *)&properties[0].vt,
      a3: properties[0].decVal.Hi32,
      a4: properties[0].decVal.Lo32,
      a5: properties[0].decVal.Mid32,
      a6: *(_DWORD *)&properties[1].vt,
      a7: properties[1].decVal.Hi32,
      a8: properties[1].decVal.Lo32,
      a9: properties[1].decVal.Mid32,
      a10: *(_DWORD *)&properties[2].vt,
      a11: properties[2].decVal.Hi32,
      a12: properties[2].decVal.Lo32,
      a13: properties[2].decVal.Mid32,
      a14: *(_DWORD *)&properties[3].vt,
      a15: properties[3].decVal.Hi32,
      a16: properties[3].decVal.Lo32,
      a17: properties[3].decVal.Mid32,
      a18: *(_DWORD *)&properties[4].vt,
      a19: properties[4].decVal.Hi32,
      a20: properties[4].decVal.Lo32,
      a21: properties[4].decVal.Mid32,
      a22: *(_DWORD *)&properties[5].vt,
      a23: properties[5].decVal.Hi32,
      a24: properties[5].decVal.Lo32,
      a25: properties[5].decVal.Mid32,
      a26: *(_DWORD *)&properties[6].vt,
      a27: properties[6].decVal.Hi32,
      a28: properties[6].decVal.Lo32,
      a29: properties[6].decVal.Mid32,
      a30: *(_DWORD *)&properties[7].vt,
      a31: properties[7].decVal.Hi32,
      a32: properties[7].decVal.Lo32,
      a33: properties[7].decVal.Mid32,
      a34: propIDs[0],
      a35: propIDs[1],
      a36: propIDs[2],
      a37: propIDs[3],
      a38: propIDs[4],
      a39: propIDs[5]);
    return 1;
  }
  v13 = (COutStreamRam *)MemAlloc_Alloc(nSize: 0x18u);
  v14 = v13;
  if ( v13 != nullptr )
  {
    v13->__m_RefCount = 0;
    v13->__vftable = (COutStreamRam_vtbl *)&COutStreamRam::`vftable';
    ((void (__stdcall *)(COutStreamRam *, int))v13->AddRef)(a1: v13, a2: a3);
    v15 = MemAlloc_Alloc(nSize: 0x14u);
    v16 = v15;
    if ( v15 != nullptr )
    {
      v15[1] = 0;
      *v15 = &CInStreamRam::`vftable';
      (*(void (__stdcall **)(_DWORD *))(*v15 + 4))(a1: v15);
      v14->Size = outSize;
      v14->Data = outBuffer;
      v14->Pos = 0;
      v14->Overflow = false;
      if ( (*(int (__stdcall **)(_DWORD *, COutStreamRam *))(v12[3] + 12))(a1: v12 + 3, a2: v14) != 0 )
      {
LABEL_12:
        (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
        ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
        (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
        return 3;
      }
      if ( v14->Pos == 5 )
      {
        mainResult = 0;
        while ( COutStreamRam::WriteByte(this: v14, b: (unsigned __int64)inSize >> mainResult) == 0 )
        {
          mainResult += 8;
          if ( mainResult >= 64 )
          {
            v14->Overflow = false;
            v16[3] = inSize;
            v16[2] = inBuffer;
            v16[4] = 0;
            mainResulta = 0;
            v17 = (*(int (__stdcall **)(_DWORD *, _DWORD *, COutStreamRam *, _DWORD, _DWORD, _DWORD))(*v12 + 12))(
                    a1: v12,
                    a2: v16,
                    a3: v14,
                    a4: 0,
                    a5: 0,
                    a6: 0);
            if ( v17 == -2147024882 )
              mainResulta = 2;
            if ( v14->Overflow )
            {
              mainResulta = 3;
            }
            else if ( v17 != 0 )
            {
              mainResulta = 1;
            }
            *outSizeProcessed = v14->Pos;
            (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
            ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
            (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
            return mainResulta;
          }
        }
        goto LABEL_12;
      }
      (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
      ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
      (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
      return 1;
    }
    else
    {
      ((void (__stdcall *)(COutStreamRam *, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))v14->Release)(
        a1: v14,
        a2: *(_DWORD *)&properties[0].vt,
        a3: properties[0].decVal.Hi32,
        a4: properties[0].decVal.Lo32,
        a5: properties[0].decVal.Mid32,
        a6: *(_DWORD *)&properties[1].vt,
        a7: properties[1].decVal.Hi32,
        a8: properties[1].decVal.Lo32,
        a9: properties[1].decVal.Mid32,
        a10: *(_DWORD *)&properties[2].vt,
        a11: properties[2].decVal.Hi32,
        a12: properties[2].decVal.Lo32,
        a13: properties[2].decVal.Mid32,
        a14: *(_DWORD *)&properties[3].vt,
        a15: properties[3].decVal.Hi32,
        a16: properties[3].decVal.Lo32,
        a17: properties[3].decVal.Mid32,
        a18: *(_DWORD *)&properties[4].vt,
        a19: properties[4].decVal.Hi32,
        a20: properties[4].decVal.Lo32,
        a21: properties[4].decVal.Mid32,
        a22: *(_DWORD *)&properties[5].vt,
        a23: properties[5].decVal.Hi32,
        a24: properties[5].decVal.Lo32,
        a25: properties[5].decVal.Mid32,
        a26: *(_DWORD *)&properties[6].vt,
        a27: properties[6].decVal.Hi32,
        a28: properties[6].decVal.Lo32,
        a29: properties[6].decVal.Mid32,
        a30: *(_DWORD *)&properties[7].vt,
        a31: properties[7].decVal.Hi32,
        a32: properties[7].decVal.Lo32,
        a33: properties[7].decVal.Mid32,
        a34: propIDs[0],
        a35: propIDs[1],
        a36: propIDs[2],
        a37: propIDs[3],
        a38: propIDs[4]);
      (*(void (__stdcall **)(_DWORD *))(*v12 + 8))(a1: v12);
      return 2;
    }
  }
  else
  {
    (*(void (__stdcall **)(_DWORD *, int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))(*v12 + 8))(
      a1: v12,
      a2: a3,
      a3: *(_DWORD *)&properties[0].vt,
      a4: properties[0].decVal.Hi32,
      a5: properties[0].decVal.Lo32,
      a6: properties[0].decVal.Mid32,
      a7: *(_DWORD *)&properties[1].vt,
      a8: properties[1].decVal.Hi32,
      a9: properties[1].decVal.Lo32,
      a10: properties[1].decVal.Mid32,
      a11: *(_DWORD *)&properties[2].vt,
      a12: properties[2].decVal.Hi32,
      a13: properties[2].decVal.Lo32,
      a14: properties[2].decVal.Mid32,
      a15: *(_DWORD *)&properties[3].vt,
      a16: properties[3].decVal.Hi32,
      a17: properties[3].decVal.Lo32,
      a18: properties[3].decVal.Mid32,
      a19: *(_DWORD *)&properties[4].vt,
      a20: properties[4].decVal.Hi32,
      a21: properties[4].decVal.Lo32,
      a22: properties[4].decVal.Mid32,
      a23: *(_DWORD *)&properties[5].vt,
      a24: properties[5].decVal.Hi32,
      a25: properties[5].decVal.Lo32,
      a26: properties[5].decVal.Mid32,
      a27: *(_DWORD *)&properties[6].vt,
      a28: properties[6].decVal.Hi32,
      a29: properties[6].decVal.Lo32,
      a30: properties[6].decVal.Mid32,
      a31: *(_DWORD *)&properties[7].vt,
      a32: properties[7].decVal.Hi32,
      a33: properties[7].decVal.Lo32,
      a34: properties[7].decVal.Mid32,
      a35: propIDs[0],
      a36: propIDs[1],
      a37: propIDs[2],
      a38: propIDs[3],
      a39: propIDs[4]);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520610
// Name: unsigned char __near * LZMA_Compress(unsigned char __near *,unsigned int,unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl LZMA_Compress(
        unsigned __int8 *pInput,
        unsigned int inputSize,
        unsigned int *pOutputSize,
        char dictionarySize)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v5; // esi
  unsigned int v6; // edi
  unsigned __int8 v7; // dl
  unsigned int v8; // [esp-10h] [ebp-14h]
  unsigned int compressedSize; // [esp+0h] [ebp-4h] BYREF

  *pOutputSize = 0;
  if ( inputSize <= 0x11 )
    return nullptr;
  result = (unsigned __int8 *)MemAlloc_Alloc(nSize: 21 * (inputSize / 0x14) + 0x10000);
  v5 = result;
  if ( result != nullptr )
  {
    if ( LzmaEncode(
           a1: (int)(result + 17),
           a2: 21 * (inputSize / 0x14) + 65519,
           a3: (int)result,
           inBuffer: pInput,
           inSize: inputSize,
           outBuffer: result + 17,
           outSize: 21 * (inputSize / 0x14) + 65519,
           outSizeProcessed: &compressedSize,
           dictionarySize: 1 << dictionarySize) != 0
      || (v6 = compressedSize + 4, compressedSize + 4 >= inputSize) )
    {
      free(pMem: v5);
      return nullptr;
    }
    else
    {
      v7 = v5[21];
      v8 = compressedSize - 13;
      *((_DWORD *)v5 + 2) = compressedSize - 13;
      *((_DWORD *)v5 + 1) = inputSize;
      *((_DWORD *)v5 + 3) = *(_DWORD *)(v5 + 17);
      *(_DWORD *)v5 = 1095588428;
      v5[16] = v7;
      memcpy(dst: v5 + 17, src: v5 + 30, count: v8);
      *pOutputSize = v6;
      return v5;
    }
  }
  return result;
}

} // namespace makegamedata

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10011730
// Name: public: virtual long CInStreamRam::Read(void __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CInStreamRam::Read(CInStreamRam *this, _BYTE *data, unsigned int size, unsigned int *processedSize)
{
  unsigned int v4; // esi
  unsigned int i; // eax

  v4 = size;
  if ( size > this->Size - this->Pos )
    v4 = this->Size - this->Pos;
  for ( i = 0; i < v4; ++i )
    data[i] = this->Data[i + this->Pos];
  this->Pos += v4;
  if ( processedSize != nullptr )
    *processedSize = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011780
// Name: public: long COutStreamRam::WriteByte(unsigned char)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutStreamRam::WriteByte(COutStreamRam *this, unsigned __int8 b)
{
  unsigned int Pos; // eax

  Pos = this->Pos;
  if ( Pos < this->Size )
  {
    this->Data[Pos] = b;
    ++this->Pos;
    return 0;
  }
  else
  {
    this->Overflow = true;
    return -2147467259;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100117B0
// Name: public: virtual long COutStreamRam::Write(void const __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall COutStreamRam::Write(
        COutStreamRam *this,
        _BYTE *data,
        unsigned int size,
        unsigned int *processedSize)
{
  unsigned int i; // ecx
  unsigned int Pos; // esi

  for ( i = 0; i < size; ++i )
  {
    Pos = this->Pos;
    if ( Pos >= this->Size )
      break;
    this->Data[Pos] = data[i];
    ++this->Pos;
  }
  if ( processedSize != nullptr )
    *processedSize = i;
  if ( i == size )
    return 0;
  this->Overflow = true;
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10011820
// Name: public: virtual unsigned long CInStreamRam::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CInStreamRam::AddRef(CInStreamRam *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011840
// Name: public: virtual unsigned long COutStreamRam::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall COutStreamRam::Release(CInStreamRam *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    free(pMem: this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011860
// Name: int LzmaEncode(unsigned char const __near *,unsigned int,unsigned char __near *,unsigned int,unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __usercall LzmaEncode@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const unsigned __int8 *inBuffer,
        unsigned int inSize,
        unsigned __int8 *outBuffer,
        unsigned int outSize,
        unsigned int *outSizeProcessed,
        unsigned int dictionarySize)
{
  NCompress::NLZMA::CEncoder *v10; // eax
  NCompress::NLZMA::CEncoder *v11; // eax
  _DWORD *v12; // ebx
  COutStreamRam *v13; // eax
  COutStreamRam *v14; // esi
  _DWORD *v15; // eax
  _DWORD *v16; // edi
  int v17; // eax
  tagPROPVARIANT properties[8]; // [esp+0h] [ebp-A0h] BYREF
  unsigned int propIDs[8]; // [esp+80h] [ebp-20h] BYREF
  int mainResult; // [esp+B4h] [ebp+14h]
  int mainResulta; // [esp+B4h] [ebp+14h]

  *outSizeProcessed = 0;
  if ( outSize < 0xD )
    return 3;
  v10 = (NCompress::NLZMA::CEncoder *)operator new(nSize: 0x33B28u);
  if ( v10 != nullptr )
  {
    v11 = NCompress::NLZMA::CEncoder::CEncoder(this: v10);
    v12 = &v11->ICompressCoder::IUnknown::__vftable;
    if ( v11 != nullptr )
      v11->AddRef(this: v11);
  }
  else
  {
    v12 = nullptr;
  }
  properties[1].vt = 19;
  properties[4].vt = 19;
  properties[0].vt = 19;
  properties[0].decVal.Lo32 = dictionarySize;
  properties[2].vt = 19;
  properties[5].vt = 19;
  properties[7].vt = 11;
  properties[3].vt = 19;
  properties[7].iVal = 0;
  propIDs[0] = 1024;
  propIDs[1] = 1088;
  propIDs[2] = 1089;
  propIDs[3] = 1090;
  propIDs[4] = 1136;
  propIDs[5] = 1104;
  propIDs[6] = 1105;
  propIDs[7] = 1168;
  properties[1].decVal.Lo32 = 2;
  properties[2].decVal.Lo32 = 3;
  properties[3].decVal.Lo32 = 0;
  properties[4].decVal.Lo32 = 2;
  properties[5].decVal.Lo32 = 64;
  properties[6].vt = 8;
  properties[6].decVal.Lo32 = (unsigned int)L"BT4";
  if ( (*(int (__stdcall **)(_DWORD *, unsigned int *, tagPROPVARIANT *, int, int, int))(v12[2] + 12))(
         a1: v12 + 2,
         a2: propIDs,
         a3: properties,
         a4: 8,
         a5: a2,
         a6: a1) != 0 )
  {
    (*(void (__stdcall **)(_DWORD *, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))(*v12 + 8))(
      a1: v12,
      a2: *(_DWORD *)&properties[0].vt,
      a3: properties[0].decVal.Hi32,
      a4: properties[0].decVal.Lo32,
      a5: properties[0].decVal.Mid32,
      a6: *(_DWORD *)&properties[1].vt,
      a7: properties[1].decVal.Hi32,
      a8: properties[1].decVal.Lo32,
      a9: properties[1].decVal.Mid32,
      a10: *(_DWORD *)&properties[2].vt,
      a11: properties[2].decVal.Hi32,
      a12: properties[2].decVal.Lo32,
      a13: properties[2].decVal.Mid32,
      a14: *(_DWORD *)&properties[3].vt,
      a15: properties[3].decVal.Hi32,
      a16: properties[3].decVal.Lo32,
      a17: properties[3].decVal.Mid32,
      a18: *(_DWORD *)&properties[4].vt,
      a19: properties[4].decVal.Hi32,
      a20: properties[4].decVal.Lo32,
      a21: properties[4].decVal.Mid32,
      a22: *(_DWORD *)&properties[5].vt,
      a23: properties[5].decVal.Hi32,
      a24: properties[5].decVal.Lo32,
      a25: properties[5].decVal.Mid32,
      a26: *(_DWORD *)&properties[6].vt,
      a27: properties[6].decVal.Hi32,
      a28: properties[6].decVal.Lo32,
      a29: properties[6].decVal.Mid32,
      a30: *(_DWORD *)&properties[7].vt,
      a31: properties[7].decVal.Hi32,
      a32: properties[7].decVal.Lo32,
      a33: properties[7].decVal.Mid32,
      a34: propIDs[0],
      a35: propIDs[1],
      a36: propIDs[2],
      a37: propIDs[3],
      a38: propIDs[4],
      a39: propIDs[5]);
    return 1;
  }
  v13 = (COutStreamRam *)operator new(nSize: 0x18u);
  v14 = v13;
  if ( v13 != nullptr )
  {
    v13->__m_RefCount = 0;
    v13->__vftable = (COutStreamRam_vtbl *)&COutStreamRam::`vftable';
    ((void (__stdcall *)(COutStreamRam *, int))v13->AddRef)(a1: v13, a2: a3);
    v15 = operator new(nSize: 0x14u);
    v16 = v15;
    if ( v15 != nullptr )
    {
      v15[1] = 0;
      *v15 = &CInStreamRam::`vftable';
      (*(void (__stdcall **)(_DWORD *))(*v15 + 4))(a1: v15);
      v14->Size = outSize;
      v14->Data = outBuffer;
      v14->Pos = 0;
      v14->Overflow = false;
      if ( (*(int (__stdcall **)(_DWORD *, COutStreamRam *))(v12[3] + 12))(a1: v12 + 3, a2: v14) != 0 )
      {
LABEL_12:
        (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
        ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
        (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
        return 3;
      }
      if ( v14->Pos == 5 )
      {
        mainResult = 0;
        while ( COutStreamRam::WriteByte(this: v14, b: (unsigned __int64)inSize >> mainResult) == 0 )
        {
          mainResult += 8;
          if ( mainResult >= 64 )
          {
            v14->Overflow = false;
            v16[3] = inSize;
            v16[2] = inBuffer;
            v16[4] = 0;
            mainResulta = 0;
            v17 = (*(int (__stdcall **)(_DWORD *, _DWORD *, COutStreamRam *, _DWORD, _DWORD, _DWORD))(*v12 + 12))(
                    a1: v12,
                    a2: v16,
                    a3: v14,
                    a4: 0,
                    a5: 0,
                    a6: 0);
            if ( v17 == -2147024882 )
              mainResulta = 2;
            if ( v14->Overflow )
            {
              mainResulta = 3;
            }
            else if ( v17 != 0 )
            {
              mainResulta = 1;
            }
            *outSizeProcessed = v14->Pos;
            (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
            ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
            (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
            return mainResulta;
          }
        }
        goto LABEL_12;
      }
      (*(void (__cdecl **)(_DWORD *))(*v16 + 8))(a1: v16);
      ((void (__cdecl *)(COutStreamRam *))v14->Release)(a1: v14);
      (*(void (__cdecl **)(_DWORD *))(*v12 + 8))(a1: v12);
      return 1;
    }
    else
    {
      ((void (__stdcall *)(COutStreamRam *, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))v14->Release)(
        a1: v14,
        a2: *(_DWORD *)&properties[0].vt,
        a3: properties[0].decVal.Hi32,
        a4: properties[0].decVal.Lo32,
        a5: properties[0].decVal.Mid32,
        a6: *(_DWORD *)&properties[1].vt,
        a7: properties[1].decVal.Hi32,
        a8: properties[1].decVal.Lo32,
        a9: properties[1].decVal.Mid32,
        a10: *(_DWORD *)&properties[2].vt,
        a11: properties[2].decVal.Hi32,
        a12: properties[2].decVal.Lo32,
        a13: properties[2].decVal.Mid32,
        a14: *(_DWORD *)&properties[3].vt,
        a15: properties[3].decVal.Hi32,
        a16: properties[3].decVal.Lo32,
        a17: properties[3].decVal.Mid32,
        a18: *(_DWORD *)&properties[4].vt,
        a19: properties[4].decVal.Hi32,
        a20: properties[4].decVal.Lo32,
        a21: properties[4].decVal.Mid32,
        a22: *(_DWORD *)&properties[5].vt,
        a23: properties[5].decVal.Hi32,
        a24: properties[5].decVal.Lo32,
        a25: properties[5].decVal.Mid32,
        a26: *(_DWORD *)&properties[6].vt,
        a27: properties[6].decVal.Hi32,
        a28: properties[6].decVal.Lo32,
        a29: properties[6].decVal.Mid32,
        a30: *(_DWORD *)&properties[7].vt,
        a31: properties[7].decVal.Hi32,
        a32: properties[7].decVal.Lo32,
        a33: properties[7].decVal.Mid32,
        a34: propIDs[0],
        a35: propIDs[1],
        a36: propIDs[2],
        a37: propIDs[3],
        a38: propIDs[4]);
      (*(void (__stdcall **)(_DWORD *))(*v12 + 8))(a1: v12);
      return 2;
    }
  }
  else
  {
    (*(void (__stdcall **)(_DWORD *, int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))(*v12 + 8))(
      a1: v12,
      a2: a3,
      a3: *(_DWORD *)&properties[0].vt,
      a4: properties[0].decVal.Hi32,
      a5: properties[0].decVal.Lo32,
      a6: properties[0].decVal.Mid32,
      a7: *(_DWORD *)&properties[1].vt,
      a8: properties[1].decVal.Hi32,
      a9: properties[1].decVal.Lo32,
      a10: properties[1].decVal.Mid32,
      a11: *(_DWORD *)&properties[2].vt,
      a12: properties[2].decVal.Hi32,
      a13: properties[2].decVal.Lo32,
      a14: properties[2].decVal.Mid32,
      a15: *(_DWORD *)&properties[3].vt,
      a16: properties[3].decVal.Hi32,
      a17: properties[3].decVal.Lo32,
      a18: properties[3].decVal.Mid32,
      a19: *(_DWORD *)&properties[4].vt,
      a20: properties[4].decVal.Hi32,
      a21: properties[4].decVal.Lo32,
      a22: properties[4].decVal.Mid32,
      a23: *(_DWORD *)&properties[5].vt,
      a24: properties[5].decVal.Hi32,
      a25: properties[5].decVal.Lo32,
      a26: properties[5].decVal.Mid32,
      a27: *(_DWORD *)&properties[6].vt,
      a28: properties[6].decVal.Hi32,
      a29: properties[6].decVal.Lo32,
      a30: properties[6].decVal.Mid32,
      a31: *(_DWORD *)&properties[7].vt,
      a32: properties[7].decVal.Hi32,
      a33: properties[7].decVal.Lo32,
      a34: properties[7].decVal.Mid32,
      a35: propIDs[0],
      a36: propIDs[1],
      a37: propIDs[2],
      a38: propIDs[3],
      a39: propIDs[4]);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011B50
// Name: unsigned char __near * LZMA_Compress(unsigned char __near *,unsigned int,unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl LZMA_Compress(
        unsigned __int8 *pInput,
        unsigned int inputSize,
        unsigned int *pOutputSize,
        char dictionarySize)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v5; // esi
  unsigned int v6; // edi
  unsigned __int8 v7; // dl
  unsigned int v8; // [esp-10h] [ebp-14h]
  unsigned int compressedSize; // [esp+0h] [ebp-4h] BYREF

  *pOutputSize = 0;
  if ( inputSize <= 0x11 )
    return nullptr;
  result = (unsigned __int8 *)operator new(nSize: 21 * (inputSize / 0x14) + 0x10000);
  v5 = result;
  if ( result != nullptr )
  {
    if ( LzmaEncode(
           a1: (int)(result + 17),
           a2: 21 * (inputSize / 0x14) + 65519,
           a3: (int)result,
           inBuffer: pInput,
           inSize: inputSize,
           outBuffer: result + 17,
           outSize: 21 * (inputSize / 0x14) + 65519,
           outSizeProcessed: &compressedSize,
           dictionarySize: 1 << dictionarySize) != 0
      || (v6 = compressedSize + 4, compressedSize + 4 >= inputSize) )
    {
      free(pMem: v5);
      return nullptr;
    }
    else
    {
      v7 = v5[21];
      v8 = compressedSize - 13;
      *((_DWORD *)v5 + 2) = compressedSize - 13;
      *((_DWORD *)v5 + 1) = inputSize;
      *((_DWORD *)v5 + 3) = *(_DWORD *)(v5 + 17);
      *(_DWORD *)v5 = 1095588428;
      v5[16] = v7;
      memcpy(dst: v5 + 17, src: v5 + 30, count: v8);
      *pOutputSize = v6;
      return v5;
    }
  }
  return result;
}

} // namespace shadercompile_dll
