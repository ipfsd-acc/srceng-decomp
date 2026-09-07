// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/checksum_crc.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10271EA0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10271EB0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10271EC0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_52;
      case 1:
        goto $LN9_50;
      case 2:
        goto $LN27_8;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_8:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_50:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_52:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_43;
      case 5:
        goto $LN26_13;
      case 6:
        goto $LN25_15;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_15:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_13:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_43:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

// ============================================================
// Overlay from FileSystem_Stdio (Missing functions)
// ============================================================
namespace FileSystem_Stdio {

//------------------------------------------------------------------------------
// Address: 0x10027050
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10027060
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10027070
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_1;
      case 1:
        goto $LN9_1;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_1:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace FileSystem_Stdio

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x1025C4D0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1025C4E0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1025C4F0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_28;
      case 1:
        goto $LN9_24;
      case 2:
        goto $LN27_5;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_5:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_24:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_28:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_19;
      case 5:
        goto $LN26_10;
      case 6:
        goto $LN25_10;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_10:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_10:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_19:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace MaterialSystem

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x100D7E90
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100D7EA0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x100D7EC0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_14;
      case 1:
        goto $LN9_9;
      case 2:
        goto $LN27_3;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_9:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_14:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_10;
      case 5:
        goto $LN26_2;
      case 6:
        goto $LN25_2;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_2:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_2:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_10:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace shaderapidx9

// ============================================================
// Overlay from bsppack (Missing functions)
// ============================================================
namespace bsppack {

//------------------------------------------------------------------------------
// Address: 0x1001FA30
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001FA40
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1001FA50
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_0;
      case 1:
        goto $LN9_1;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_0:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_0;
      case 5:
        goto $LN26_0;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_0:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace bsppack

// ============================================================
// Overlay from bspzip (Missing functions)
// ============================================================
namespace bspzip {

//------------------------------------------------------------------------------
// Address: 0x004156D0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004156E0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x004156F0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8;
      case 1:
        goto $LN9;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace bspzip

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10033A60
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10033A70
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10033A80
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_6;
      case 1:
        goto $LN9_4;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_4:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_6:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_1;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_1:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace dedicated

// ============================================================
// Overlay from FileSystem_Steam (Missing functions)
// ============================================================
namespace FileSystem_Steam {

//------------------------------------------------------------------------------
// Address: 0x10020320
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10020330
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10020340
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8;
      case 1:
        goto $LN9;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_0;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_0:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace FileSystem_Steam

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10271F30
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10271F40
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10271F50
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_52;
      case 1:
        goto $LN9_50;
      case 2:
        goto $LN27_8;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_8:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_50:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_52:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_43;
      case 5:
        goto $LN26_13;
      case 6:
        goto $LN25_15;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_15:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_13:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_43:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004CAA50
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004CAA60
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x004CAA70
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_23;
      case 1:
        goto $LN9_16;
      case 2:
        goto $LN27_6;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_6:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_16:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_23:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_11;
      case 5:
        goto $LN26_8;
      case 6:
        goto $LN25_6;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_6:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_8:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_11:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace hlfaceposer

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x0042AC10
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042AC20
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x0042AC30
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_0;
      case 1:
        goto $LN9_0;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_0:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace localization_check

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x0052E480
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052E490
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x0052E4A0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_14;
      case 1:
        goto $LN9_19;
      case 2:
        goto $LN27_1;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_19:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_14:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_8;
      case 5:
        goto $LN26_3;
      case 6:
        goto $LN25_2;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_2:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_8:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from networksystem (Missing functions)
// ============================================================
namespace networksystem {

//------------------------------------------------------------------------------
// Address: 0x1001AAF0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001AB00
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1001AB10
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_0;
      case 1:
        goto $LN9_0;
      case 2:
        goto $LN10_0;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN10_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_0:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_0;
      case 5:
        goto $LN13_0;
      case 6:
        goto $LN14_0;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN14_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN13_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_0:
        v18 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v19 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; v4 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8) )
        {
          --i;
          v11 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = (v13 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v13];
          v15 = pulCRCTable[(unsigned __int8)v14] ^ (v14 >> 8);
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace networksystem

// ============================================================
// Overlay from scenefilecache (Missing functions)
// ============================================================
namespace scenefilecache {

//------------------------------------------------------------------------------
// Address: 0x10001720
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001730
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10001740
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8;
      case 1:
        goto $LN9;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace scenefilecache

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x1003F040
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003F050
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1003F060
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_13;
      case 1:
        goto $LN9_7;
      case 2:
        goto $LN10_4;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN10_4:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_13:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_2;
      case 5:
        goto $LN13_2;
      case 6:
        goto $LN14_2;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN14_2:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN13_2:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_2:
        v18 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v19 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; v4 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8) )
        {
          --i;
          v11 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = (v13 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v13];
          v15 = pulCRCTable[(unsigned __int8)v14] ^ (v14 >> 8);
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace shaderapidx10

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x1001A0D0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001A0E0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1001A0F0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_1;
      case 1:
        goto $LN9_1;
      case 2:
        goto $LN27_0;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_1:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_3;
      case 5:
        goto $LN26_2;
      case 6:
        goto $LN25_0;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_2:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_3:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace shadercompile_dll

// ============================================================
// Overlay from SoundEmitterSystem (Missing functions)
// ============================================================
namespace SoundEmitterSystem {

//------------------------------------------------------------------------------
// Address: 0x1000A890
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A8A0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1000A8B0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_0;
      case 1:
        goto $LN9_0;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_0:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace SoundEmitterSystem

// ============================================================
// Overlay from stdshader_dbg (Missing functions)
// ============================================================
namespace stdshader_dbg {

//------------------------------------------------------------------------------
// Address: 0x10004890
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100048A0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x100048B0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8;
      case 1:
        goto $LN9;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace stdshader_dbg

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x10047250
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10047260
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10047270
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8;
      case 1:
        goto $LN9;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_0;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_0:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace stdshader_dx9

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10036DE0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10036DF0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10036E00
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_14;
      case 1:
        goto $LN9_9;
      case 2:
        goto $LN27_3;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_9:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_14:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_11;
      case 5:
        goto $LN26_1;
      case 6:
        goto $LN25_4;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_4:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_11:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0045C640
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0045C650
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x0045C660
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_3;
      case 1:
        goto $LN9_4;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_4:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_3:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_1;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_1:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace vbsp

// ============================================================
// Overlay from vbspinfo (Missing functions)
// ============================================================
namespace vbspinfo {

//------------------------------------------------------------------------------
// Address: 0x004155E0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004155F0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x00415600
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8;
      case 1:
        goto $LN9;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace vbspinfo

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10048820
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10048830
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10048840
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_7;
      case 1:
        goto $LN9_5;
      case 2:
        goto $LN27_0;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_5:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_7:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_3;
      case 5:
        goto $LN26_1;
      case 6:
        goto $LN25_1;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_3:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00530E60
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00530E70
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x00530E80
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_39;
      case 1:
        goto $LN9_42;
      case 2:
        goto $LN10_38;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN10_38:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_42:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_39:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_32;
      case 5:
        goto $LN13_34;
      case 6:
        goto $LN14_29;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN14_29:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN13_34:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_32:
        v18 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v19 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; v4 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8) )
        {
          --i;
          v11 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = (v13 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v13];
          v15 = pulCRCTable[(unsigned __int8)v14] ^ (v14 >> 8);
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0064BF90
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0064BFA0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x0064BFC0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_16;
      case 1:
        goto $LN9_17;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_17:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_16:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_18;
      case 5:
        goto $LN26_0;
      case 6:
        goto $LN25_14;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_14:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_18:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x100807F0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10080800
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10080810
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_4;
      case 1:
        goto $LN9_5;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_5:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_4:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_5;
      case 5:
        goto $LN26_1;
      case 6:
        goto $LN25_1;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_5:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vstdlib_s (Missing functions)
// ============================================================
namespace vstdlib_s {

//------------------------------------------------------------------------------
// Address: 0x3F601000
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void CRC32_Init()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F601010
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void CRC32_Final()
{
  JUMPOUT(0x3F60101A);
}

//------------------------------------------------------------------------------
// Address: 0x3F601030
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CRC32_ProcessBuffer(int a1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F601050
// Name: sub_3F601050
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F601050(_DWORD *this, int a2)
{
  return *(_DWORD *)(*(this + 260) + 16 * a2 + 4);
}

} // namespace vstdlib_s

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1009CB80
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1009CB90
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1009CBA0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_12;
      case 1:
        goto $LN9_15;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_15:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_12:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_8;
      case 5:
        goto $LN26_2;
      case 6:
        goto $LN25_5;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_5:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_2:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_8:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace vtex_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1001D680
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001D690
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1001D6A0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_0;
      case 1:
        goto $LN9;
      case 2:
        goto $LN27;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_0:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12;
      case 5:
        goto $LN26;
      case 6:
        goto $LN25;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace vvis_dll

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00439EA0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00439EB0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x00439EC0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_9;
      case 1:
        goto $LN9_11;
      case 2:
        goto $LN27_0;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_0:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_11:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_9:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_13;
      case 5:
        goto $LN26_2;
      case 6:
        goto $LN25_4;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_4:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_2:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_13:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace VXConsole

// ============================================================
// Overlay from XLSPMaster (Missing functions)
// ============================================================
namespace XLSPMaster {

//------------------------------------------------------------------------------
// Address: 0x004553C0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004553D0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x004553E0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_5;
      case 1:
        goto $LN9_3;
      case 2:
        goto $LN27_1;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_5:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_6;
      case 5:
        goto $LN26_1;
      case 6:
        goto $LN25_1;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_1:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_6:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace XLSPMaster

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1036BCD0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1036BCE0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1036BCF0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_42;
      case 1:
        goto $LN9_42;
      case 2:
        goto $LN27_7;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_42:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_42:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_32;
      case 5:
        goto $LN26_12;
      case 6:
        goto $LN25_10;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_10:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_12:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_32:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10377EA0
// Name: void CRC32_Init(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Init(unsigned int *pulCRC)
{
  *pulCRC = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10377EB0
// Name: void CRC32_Final(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_Final(unsigned int *pulCRC)
{
  *pulCRC = ~*pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10377EC0
// Name: void CRC32_ProcessBuffer(unsigned long __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRC32_ProcessBuffer(unsigned int *pulCRC, _DWORD *pBuffer, int nBuffer)
{
  unsigned int v4; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int i; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax

  v4 = *pulCRC;
  while ( 1 )
  {
    switch ( nBuffer )
    {
      case 0:
        goto $LN8_55;
      case 1:
        goto $LN9_52;
      case 2:
        goto $LN27_9;
      case 3:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN27_9:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN9_52:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
$LN8_55:
        *pulCRC = v4;
        return;
      case 4:
        goto $LN12_32;
      case 5:
        goto $LN26_10;
      case 6:
        goto $LN25_15;
      case 7:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN25_15:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN26_10:
        v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
        pBuffer = (_DWORD *)((char *)pBuffer + 1);
$LN12_32:
        v19 = pulCRCTable[(unsigned __int8)(*(_BYTE *)pBuffer ^ v4)] ^ ((*pBuffer ^ v4) >> 8);
        v20 = pulCRCTable[(unsigned __int8)v19] ^ (v19 >> 8);
        v21 = pulCRCTable[(unsigned __int8)v20] ^ (v20 >> 8);
        *pulCRC = pulCRCTable[(unsigned __int8)v21] ^ (v21 >> 8);
        return;
      default:
        v6 = (unsigned __int8)pBuffer & 3;
        v7 = nBuffer - v6;
        v8 = v6 - 1;
        if ( v8 == 0 )
          goto LABEL_8;
        v9 = v8 - 1;
        if ( v9 == 0 )
          goto LABEL_7;
        if ( v9 == 1 )
        {
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_7:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
LABEL_8:
          v4 = pulCRCTable[(unsigned __int8)v4 ^ *(unsigned __int8 *)pBuffer] ^ (v4 >> 8);
          pBuffer = (_DWORD *)((char *)pBuffer + 1);
        }
        for ( i = v7 >> 3; i != 0; --i )
        {
          v11 = *pBuffer ^ v4;
          pBuffer += 2;
          v12 = pulCRCTable[(unsigned __int8)v11] ^ (v11 >> 8);
          v13 = pulCRCTable[(unsigned __int8)v12] ^ (v12 >> 8);
          v14 = pulCRCTable[(unsigned __int8)v13] ^ (v13 >> 8);
          v15 = (v14 >> 8) ^ *(pBuffer - 1) ^ pulCRCTable[(unsigned __int8)v14];
          v16 = pulCRCTable[(unsigned __int8)v15] ^ (v15 >> 8);
          v17 = pulCRCTable[(unsigned __int8)v16] ^ (v16 >> 8);
          v18 = pulCRCTable[(unsigned __int8)v17] ^ (v17 >> 8);
          v4 = pulCRCTable[(unsigned __int8)v18] ^ (v18 >> 8);
        }
        nBuffer = v7 & 7;
        break;
    }
  }
}

} // namespace server
