// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/byteswap.cpp
// Functions: 3
// ============================================================

#include "tier1\byteswap.h"

//------------------------------------------------------------------------------
// Address: 0x10275CC0
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(__int64 *output, __int64 *input)
{
  int v2; // eax
  __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: output, src: &temp, count: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10275D20
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = (__int64 *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (__int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275D90
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  int *v7; // ebx
  int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (int *)&pBaseData[v6];
      v8 = (int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (__int16 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (int *)((char *)v8 + v10);
              v7 = (int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

// ============================================================
// Overlay from FileSystem_Stdio (Missing functions)
// ============================================================
namespace FileSystem_Stdio {

//------------------------------------------------------------------------------
// Address: 0x10028A10
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: (unsigned __int8 *)output, src: (unsigned __int8 *)&temp, count: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x10028A70
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028AE0
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (__int16 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace FileSystem_Stdio

// ============================================================
// Overlay from bsppack (Missing functions)
// ============================================================
namespace bsppack {

//------------------------------------------------------------------------------
// Address: 0x10001440
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropDictLump_t>(struct StaticPropDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropDictLump_t>(
        CByteswap *this,
        StaticPropDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001490
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropLeafLump_t>(struct StaticPropLeafLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropLeafLump_t>(
        CByteswap *this,
        StaticPropLeafLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropLeafLump_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100014E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailObjectDictLump_t>(struct DetailObjectDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailObjectDictLump_t>(
        CByteswap *this,
        DetailObjectDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailObjectDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001530
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailPropLightstylesLump_t>(struct DetailPropLightstylesLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailPropLightstylesLump_t>(
        CByteswap *this,
        DetailPropLightstylesLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailPropLightstylesLump_t::m_DataMap);
      v5 += 5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001580
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_t>(struct dworldlight_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_t>(
        CByteswap *this,
        dworldlight_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_t::m_DataMap);
      v5 += 100;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100015D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dgamelumpheader_t>(struct dgamelumpheader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dgamelumpheader_t>(
        CByteswap *this,
        dgamelumpheader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dgamelumpheader_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001620
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct BSPHeader_t>(struct BSPHeader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<BSPHeader_t>(
        CByteswap *this,
        BSPHeader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &BSPHeader_t::m_DataMap);
      v5 += 1036;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001670
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientlighting_t>(struct dleafambientlighting_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientlighting_t>(
        CByteswap *this,
        dleafambientlighting_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientlighting_t::m_DataMap);
      v5 += 28;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100016C0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientindex_t>(struct dleafambientindex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientindex_t>(
        CByteswap *this,
        dleafambientindex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientindex_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001710
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_version0_t>(struct dworldlight_version0_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_version0_t>(
        CByteswap *this,
        dworldlight_version0_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_version0_t::m_DataMap);
      v5 += 88;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001760
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dflagslump_t>(struct dflagslump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dflagslump_t>(
        CByteswap *this,
        dflagslump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dflagslump_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100017B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dface_t>(struct dface_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dface_t>(
        CByteswap *this,
        dface_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dface_t::m_DataMap);
      v5 += 56;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001800
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dmodel_t>(struct dmodel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dmodel_t>(
        CByteswap *this,
        dmodel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dmodel_t::m_DataMap);
      v5 += 48;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001850
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dvertex_t>(struct dvertex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dvertex_t>(
        CByteswap *this,
        dvertex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dvertex_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100018A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dplane_t>(struct dplane_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dplane_t>(
        CByteswap *this,
        dplane_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dplane_t::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100018F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dnode_t>(struct dnode_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dnode_t>(
        CByteswap *this,
        dnode_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dnode_t::m_DataMap);
      v5 += 32;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001940
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct texinfo_s>(struct texinfo_s __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<texinfo_s>(
        CByteswap *this,
        texinfo_s *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &texinfo_s::m_DataMap);
      v5 += 72;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001990
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dtexdata_t>(struct dtexdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dtexdata_t>(
        CByteswap *this,
        dtexdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dtexdata_t::m_DataMap);
      v5 += 32;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100019E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class ddispinfo_t>(class ddispinfo_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<ddispinfo_t>(
        CByteswap *this,
        ddispinfo_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &ddispinfo_t::m_DataMap);
      v5 += 176;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A30
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispVert>(class CDispVert __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispVert>(
        CByteswap *this,
        CDispVert *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispVert::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A80
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispTri>(class CDispTri __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispTri>(
        CByteswap *this,
        CDispTri *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispTri::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001AD0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CFaceMacroTextureInfo>(class CFaceMacroTextureInfo __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CFaceMacroTextureInfo>(
        CByteswap *this,
        CFaceMacroTextureInfo *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CFaceMacroTextureInfo::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B20
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimitive_t>(struct dprimitive_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimitive_t>(
        CByteswap *this,
        dprimitive_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimitive_t::m_DataMap);
      v5 += 10;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B70
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimvert_t>(struct dprimvert_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimvert_t>(
        CByteswap *this,
        dprimvert_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimvert_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001BC0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfacebrushlist_t>(struct dfacebrushlist_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfacebrushlist_t>(
        CByteswap *this,
        dfacebrushlist_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfacebrushlist_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001C10
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dedge_t>(struct dedge_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dedge_t>(
        CByteswap *this,
        dedge_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dedge_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001C60
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dbrush_t>(struct dbrush_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dbrush_t>(
        CByteswap *this,
        dbrush_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dbrush_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001CB0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dbrushside_t>(struct dbrushside_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dbrushside_t>(
        CByteswap *this,
        dbrushside_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dbrushside_t::m_DataMap);
      v5 += 8;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D00
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct darea_t>(struct darea_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<darea_t>(
        CByteswap *this,
        darea_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &darea_t::m_DataMap);
      v5 += 8;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D50
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dareaportal_t>(struct dareaportal_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dareaportal_t>(
        CByteswap *this,
        dareaportal_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dareaportal_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001DA0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafwaterdata_t>(struct dleafwaterdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafwaterdata_t>(
        CByteswap *this,
        dleafwaterdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafwaterdata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001DF0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dcubemapsample_t>(struct dcubemapsample_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dcubemapsample_t>(
        CByteswap *this,
        dcubemapsample_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dcubemapsample_t::m_DataMap);
      v5 += 16;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E40
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlay_t>(struct doverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlay_t>(
        CByteswap *this,
        doverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlay_t::m_DataMap);
      v5 += 352;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E90
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dwateroverlay_t>(struct dwateroverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dwateroverlay_t>(
        CByteswap *this,
        dwateroverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dwateroverlay_t::m_DataMap);
      v5 += 1120;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001EE0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlayfade_t>(struct doverlayfade_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlayfade_t>(
        CByteswap *this,
        doverlayfade_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlayfade_t::m_DataMap);
      v5 += 8;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlaysystemlevel_t>(struct doverlaysystemlevel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlaysystemlevel_t>(
        CByteswap *this,
        doverlaysystemlevel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlaysystemlevel_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F80
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderdata_t>(struct doccluderdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderdata_t>(
        CByteswap *this,
        doccluderdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderdata_t::m_DataMap);
      v5 += 40;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001FD0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderpolydata_t>(struct doccluderpolydata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderpolydata_t>(
        CByteswap *this,
        doccluderpolydata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderpolydata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002020
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispMultiBlend>(class CDispMultiBlend __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispMultiBlend>(
        CByteswap *this,
        CDispMultiBlend *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispMultiBlend::m_DataMap);
      v5 += 80;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002070
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfaceid_t>(struct dfaceid_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfaceid_t>(
        CByteswap *this,
        dfaceid_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfaceid_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002A70
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientlighting_t>(struct dleafambientlighting_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientlighting_t>(
        CByteswap *this,
        dleafambientlighting_t *pOutputBuffer,
        unsigned int objectCount)
{
  unsigned int i; // edi

  for ( i = objectCount; i != 0; --i )
  {
    CByteswap::SwapFieldsToTargetEndian(
      this,
      pOutputBuffer,
      pBaseData: pOutputBuffer,
      pDataMap: &dleafambientlighting_t::m_DataMap);
    ++pOutputBuffer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002AA0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientindex_t>(struct dleafambientindex_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientindex_t>(
        CByteswap *this,
        dleafambientindex_t *pOutputBuffer,
        unsigned int objectCount)
{
  unsigned int i; // edi

  for ( i = objectCount; i != 0; --i )
  {
    CByteswap::SwapFieldsToTargetEndian(
      this,
      pOutputBuffer,
      pBaseData: pOutputBuffer,
      pDataMap: &dleafambientindex_t::m_DataMap);
    ++pOutputBuffer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FC20
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: output, src: &temp, count: 8);
}

//------------------------------------------------------------------------------
// Address: 0x1001FC80
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        unsigned int *outputBuffer,
        unsigned int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  unsigned int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (int *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FD10
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FD80
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (unsigned __int8 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace bsppack

// ============================================================
// Overlay from bspzip (Missing functions)
// ============================================================
namespace bspzip {

//------------------------------------------------------------------------------
// Address: 0x00401180
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropDictLump_t>(struct StaticPropDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropDictLump_t>(
        CByteswap *this,
        StaticPropDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004011D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropLeafLump_t>(struct StaticPropLeafLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropLeafLump_t>(
        CByteswap *this,
        StaticPropLeafLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropLeafLump_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401220
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailObjectDictLump_t>(struct DetailObjectDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailObjectDictLump_t>(
        CByteswap *this,
        DetailObjectDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailObjectDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401270
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailPropLightstylesLump_t>(struct DetailPropLightstylesLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailPropLightstylesLump_t>(
        CByteswap *this,
        DetailPropLightstylesLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailPropLightstylesLump_t::m_DataMap);
      v5 += 5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012C0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_t>(struct dworldlight_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_t>(
        CByteswap *this,
        dworldlight_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_t::m_DataMap);
      v5 += 100;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401310
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dgamelumpheader_t>(struct dgamelumpheader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dgamelumpheader_t>(
        CByteswap *this,
        dgamelumpheader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dgamelumpheader_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401360
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct BSPHeader_t>(struct BSPHeader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<BSPHeader_t>(
        CByteswap *this,
        BSPHeader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &BSPHeader_t::m_DataMap);
      v5 += 1036;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004013B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientlighting_t>(struct dleafambientlighting_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientlighting_t>(
        CByteswap *this,
        dleafambientlighting_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientlighting_t::m_DataMap);
      v5 += 28;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401400
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientindex_t>(struct dleafambientindex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientindex_t>(
        CByteswap *this,
        dleafambientindex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientindex_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401450
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_version0_t>(struct dworldlight_version0_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_version0_t>(
        CByteswap *this,
        dworldlight_version0_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_version0_t::m_DataMap);
      v5 += 88;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004014A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dflagslump_t>(struct dflagslump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dflagslump_t>(
        CByteswap *this,
        dflagslump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dflagslump_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004014F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dface_t>(struct dface_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dface_t>(
        CByteswap *this,
        dface_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dface_t::m_DataMap);
      v5 += 56;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401540
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dmodel_t>(struct dmodel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dmodel_t>(
        CByteswap *this,
        dmodel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dmodel_t::m_DataMap);
      v5 += 48;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401590
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dvertex_t>(struct dvertex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dvertex_t>(
        CByteswap *this,
        dvertex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dvertex_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004015E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dplane_t>(struct dplane_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dplane_t>(
        CByteswap *this,
        dplane_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dplane_t::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401630
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct texinfo_s>(struct texinfo_s __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<texinfo_s>(
        CByteswap *this,
        texinfo_s *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &texinfo_s::m_DataMap);
      v5 += 72;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401680
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class ddispinfo_t>(class ddispinfo_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<ddispinfo_t>(
        CByteswap *this,
        ddispinfo_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &ddispinfo_t::m_DataMap);
      v5 += 176;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004016D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispVert>(class CDispVert __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispVert>(
        CByteswap *this,
        CDispVert *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispVert::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401720
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispTri>(class CDispTri __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispTri>(
        CByteswap *this,
        CDispTri *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispTri::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401770
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CFaceMacroTextureInfo>(class CFaceMacroTextureInfo __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CFaceMacroTextureInfo>(
        CByteswap *this,
        CFaceMacroTextureInfo *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CFaceMacroTextureInfo::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004017C0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimitive_t>(struct dprimitive_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimitive_t>(
        CByteswap *this,
        dprimitive_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimitive_t::m_DataMap);
      v5 += 10;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401810
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimvert_t>(struct dprimvert_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimvert_t>(
        CByteswap *this,
        dprimvert_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimvert_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401860
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfacebrushlist_t>(struct dfacebrushlist_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfacebrushlist_t>(
        CByteswap *this,
        dfacebrushlist_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfacebrushlist_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004018B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dbrush_t>(struct dbrush_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dbrush_t>(
        CByteswap *this,
        dbrush_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dbrush_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401900
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dareaportal_t>(struct dareaportal_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dareaportal_t>(
        CByteswap *this,
        dareaportal_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dareaportal_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401950
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafwaterdata_t>(struct dleafwaterdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafwaterdata_t>(
        CByteswap *this,
        dleafwaterdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafwaterdata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004019A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dcubemapsample_t>(struct dcubemapsample_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dcubemapsample_t>(
        CByteswap *this,
        dcubemapsample_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dcubemapsample_t::m_DataMap);
      v5 += 16;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004019F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlay_t>(struct doverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlay_t>(
        CByteswap *this,
        doverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlay_t::m_DataMap);
      v5 += 352;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401A40
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dwateroverlay_t>(struct dwateroverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dwateroverlay_t>(
        CByteswap *this,
        dwateroverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dwateroverlay_t::m_DataMap);
      v5 += 1120;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401A90
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlayfade_t>(struct doverlayfade_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlayfade_t>(
        CByteswap *this,
        doverlayfade_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlayfade_t::m_DataMap);
      v5 += 8;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401AE0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlaysystemlevel_t>(struct doverlaysystemlevel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlaysystemlevel_t>(
        CByteswap *this,
        doverlaysystemlevel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlaysystemlevel_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B30
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderdata_t>(struct doccluderdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderdata_t>(
        CByteswap *this,
        doccluderdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderdata_t::m_DataMap);
      v5 += 40;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B80
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderpolydata_t>(struct doccluderpolydata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderpolydata_t>(
        CByteswap *this,
        doccluderpolydata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderpolydata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401BD0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispMultiBlend>(class CDispMultiBlend __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispMultiBlend>(
        CByteswap *this,
        CDispMultiBlend *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispMultiBlend::m_DataMap);
      v5 += 80;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C20
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfaceid_t>(struct dfaceid_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfaceid_t>(
        CByteswap *this,
        dfaceid_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfaceid_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004158C0
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: output, src: &temp, count: 8);
}

//------------------------------------------------------------------------------
// Address: 0x00415920
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        unsigned int *outputBuffer,
        unsigned int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  unsigned int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (int *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004159B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415A20
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (unsigned __int8 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace bspzip

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10033C50
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: (unsigned __int8 *)output, src: (unsigned __int8 *)&temp, count: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x10033CB0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033D20
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  int *v7; // ebx
  int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (int *)&pBaseData[v6];
      v8 = (int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (__int16 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (int *)((char *)v8 + v10);
              v7 = (int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace dedicated

// ============================================================
// Overlay from FileSystem_Steam (Missing functions)
// ============================================================
namespace FileSystem_Steam {

//------------------------------------------------------------------------------
// Address: 0x10021CE0
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: (unsigned __int8 *)output, src: (unsigned __int8 *)&temp, count: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x10021D40
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021DB0
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (__int16 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace FileSystem_Steam

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10269500
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(__int64 *output, __int64 *input)
{
  int v2; // eax
  __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: output, src: &temp, count: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10275DA0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = (__int64 *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (__int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275E10
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  int *v7; // ebx
  int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (int *)&pBaseData[v6];
      v8 = (int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (__int16 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (int *)((char *)v8 + v10);
              v7 = (int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00530850
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: (unsigned __int8 *)output, src: (unsigned __int8 *)&temp, count: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x005308B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00530920
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  int *v7; // ebx
  int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (int *)&pBaseData[v6];
      v8 = (int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (unsigned __int8 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (int *)((char *)v8 + v10);
              v7 = (int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C4F90
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: (unsigned __int8 *)output, src: (unsigned __int8 *)&temp, count: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x005C4FF0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C5060
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (unsigned __int8 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005BDB90
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: (unsigned __int8 *)output, src: (unsigned __int8 *)&temp, count: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x005BDBF0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BDC60
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (unsigned __int8 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x004362B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropDictLump_t>(struct StaticPropDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropDictLump_t>(
        CByteswap *this,
        StaticPropDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436300
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropLeafLump_t>(struct StaticPropLeafLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropLeafLump_t>(
        CByteswap *this,
        StaticPropLeafLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropLeafLump_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436350
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailObjectDictLump_t>(struct DetailObjectDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailObjectDictLump_t>(
        CByteswap *this,
        DetailObjectDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailObjectDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004363A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailPropLightstylesLump_t>(struct DetailPropLightstylesLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailPropLightstylesLump_t>(
        CByteswap *this,
        DetailPropLightstylesLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailPropLightstylesLump_t::m_DataMap);
      v5 += 5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004363F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_t>(struct dworldlight_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_t>(
        CByteswap *this,
        dworldlight_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_t::m_DataMap);
      v5 += 100;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436440
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dgamelumpheader_t>(struct dgamelumpheader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dgamelumpheader_t>(
        CByteswap *this,
        dgamelumpheader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dgamelumpheader_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436490
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct BSPHeader_t>(struct BSPHeader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<BSPHeader_t>(
        CByteswap *this,
        BSPHeader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &BSPHeader_t::m_DataMap);
      v5 += 1036;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004364E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientlighting_t>(struct dleafambientlighting_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientlighting_t>(
        CByteswap *this,
        dleafambientlighting_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientlighting_t::m_DataMap);
      v5 += 28;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436530
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientindex_t>(struct dleafambientindex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientindex_t>(
        CByteswap *this,
        dleafambientindex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientindex_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436580
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_version0_t>(struct dworldlight_version0_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_version0_t>(
        CByteswap *this,
        dworldlight_version0_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_version0_t::m_DataMap);
      v5 += 88;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004365D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dflagslump_t>(struct dflagslump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dflagslump_t>(
        CByteswap *this,
        dflagslump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dflagslump_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436620
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dface_t>(struct dface_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dface_t>(
        CByteswap *this,
        dface_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dface_t::m_DataMap);
      v5 += 56;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436670
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dmodel_t>(struct dmodel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dmodel_t>(
        CByteswap *this,
        dmodel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dmodel_t::m_DataMap);
      v5 += 48;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004366C0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dvertex_t>(struct dvertex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dvertex_t>(
        CByteswap *this,
        dvertex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dvertex_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436710
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dplane_t>(struct dplane_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dplane_t>(
        CByteswap *this,
        dplane_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dplane_t::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436760
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct texinfo_s>(struct texinfo_s __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<texinfo_s>(
        CByteswap *this,
        texinfo_s *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &texinfo_s::m_DataMap);
      v5 += 72;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004367B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class ddispinfo_t>(class ddispinfo_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<ddispinfo_t>(
        CByteswap *this,
        ddispinfo_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &ddispinfo_t::m_DataMap);
      v5 += 176;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436800
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispVert>(class CDispVert __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispVert>(
        CByteswap *this,
        CDispVert *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispVert::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436850
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispTri>(class CDispTri __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispTri>(
        CByteswap *this,
        CDispTri *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispTri::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004368A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CFaceMacroTextureInfo>(class CFaceMacroTextureInfo __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CFaceMacroTextureInfo>(
        CByteswap *this,
        CFaceMacroTextureInfo *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CFaceMacroTextureInfo::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004368F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimitive_t>(struct dprimitive_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimitive_t>(
        CByteswap *this,
        dprimitive_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimitive_t::m_DataMap);
      v5 += 10;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436940
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimvert_t>(struct dprimvert_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimvert_t>(
        CByteswap *this,
        dprimvert_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimvert_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436990
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfacebrushlist_t>(struct dfacebrushlist_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfacebrushlist_t>(
        CByteswap *this,
        dfacebrushlist_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfacebrushlist_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004369E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dbrush_t>(struct dbrush_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dbrush_t>(
        CByteswap *this,
        dbrush_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dbrush_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436A30
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dareaportal_t>(struct dareaportal_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dareaportal_t>(
        CByteswap *this,
        dareaportal_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dareaportal_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436A80
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafwaterdata_t>(struct dleafwaterdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafwaterdata_t>(
        CByteswap *this,
        dleafwaterdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafwaterdata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436AD0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dcubemapsample_t>(struct dcubemapsample_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dcubemapsample_t>(
        CByteswap *this,
        dcubemapsample_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dcubemapsample_t::m_DataMap);
      v5 += 16;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436B20
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlay_t>(struct doverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlay_t>(
        CByteswap *this,
        doverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlay_t::m_DataMap);
      v5 += 352;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436B70
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dwateroverlay_t>(struct dwateroverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dwateroverlay_t>(
        CByteswap *this,
        dwateroverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dwateroverlay_t::m_DataMap);
      v5 += 1120;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436BC0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlayfade_t>(struct doverlayfade_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlayfade_t>(
        CByteswap *this,
        doverlayfade_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlayfade_t::m_DataMap);
      v5 += 8;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436C10
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlaysystemlevel_t>(struct doverlaysystemlevel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlaysystemlevel_t>(
        CByteswap *this,
        doverlaysystemlevel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlaysystemlevel_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436C60
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderdata_t>(struct doccluderdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderdata_t>(
        CByteswap *this,
        doccluderdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderdata_t::m_DataMap);
      v5 += 40;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436CB0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderpolydata_t>(struct doccluderpolydata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderpolydata_t>(
        CByteswap *this,
        doccluderpolydata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderpolydata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436D00
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispMultiBlend>(class CDispMultiBlend __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispMultiBlend>(
        CByteswap *this,
        CDispMultiBlend *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispMultiBlend::m_DataMap);
      v5 += 80;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436D50
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfaceid_t>(struct dfaceid_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfaceid_t>(
        CByteswap *this,
        dfaceid_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfaceid_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BD70
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: output, src: &temp, count: 8);
}

//------------------------------------------------------------------------------
// Address: 0x0045BDD0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BE40
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (__int16 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace vbsp

// ============================================================
// Overlay from vbspinfo (Missing functions)
// ============================================================
namespace vbspinfo {

//------------------------------------------------------------------------------
// Address: 0x004014B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropDictLump_t>(struct StaticPropDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropDictLump_t>(
        CByteswap *this,
        StaticPropDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401500
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropLeafLump_t>(struct StaticPropLeafLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropLeafLump_t>(
        CByteswap *this,
        StaticPropLeafLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropLeafLump_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401550
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailObjectDictLump_t>(struct DetailObjectDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailObjectDictLump_t>(
        CByteswap *this,
        DetailObjectDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailObjectDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004015A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailPropLightstylesLump_t>(struct DetailPropLightstylesLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailPropLightstylesLump_t>(
        CByteswap *this,
        DetailPropLightstylesLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailPropLightstylesLump_t::m_DataMap);
      v5 += 5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004015F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_t>(struct dworldlight_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_t>(
        CByteswap *this,
        dworldlight_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_t::m_DataMap);
      v5 += 100;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401640
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientlighting_t>(struct dleafambientlighting_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientlighting_t>(
        CByteswap *this,
        dleafambientlighting_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientlighting_t::m_DataMap);
      v5 += 28;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401690
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientindex_t>(struct dleafambientindex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientindex_t>(
        CByteswap *this,
        dleafambientindex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientindex_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004016E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_version0_t>(struct dworldlight_version0_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_version0_t>(
        CByteswap *this,
        dworldlight_version0_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_version0_t::m_DataMap);
      v5 += 88;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401730
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dflagslump_t>(struct dflagslump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dflagslump_t>(
        CByteswap *this,
        dflagslump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dflagslump_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401780
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dface_t>(struct dface_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dface_t>(
        CByteswap *this,
        dface_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dface_t::m_DataMap);
      v5 += 56;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004017D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dmodel_t>(struct dmodel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dmodel_t>(
        CByteswap *this,
        dmodel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dmodel_t::m_DataMap);
      v5 += 48;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401820
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dvertex_t>(struct dvertex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dvertex_t>(
        CByteswap *this,
        dvertex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dvertex_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401870
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dplane_t>(struct dplane_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dplane_t>(
        CByteswap *this,
        dplane_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dplane_t::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004018C0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct texinfo_s>(struct texinfo_s __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<texinfo_s>(
        CByteswap *this,
        texinfo_s *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &texinfo_s::m_DataMap);
      v5 += 72;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401910
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class ddispinfo_t>(class ddispinfo_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<ddispinfo_t>(
        CByteswap *this,
        ddispinfo_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &ddispinfo_t::m_DataMap);
      v5 += 176;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401960
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispVert>(class CDispVert __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispVert>(
        CByteswap *this,
        CDispVert *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispVert::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004019B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispTri>(class CDispTri __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispTri>(
        CByteswap *this,
        CDispTri *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispTri::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401A00
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CFaceMacroTextureInfo>(class CFaceMacroTextureInfo __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CFaceMacroTextureInfo>(
        CByteswap *this,
        CFaceMacroTextureInfo *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CFaceMacroTextureInfo::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401A50
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimitive_t>(struct dprimitive_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimitive_t>(
        CByteswap *this,
        dprimitive_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimitive_t::m_DataMap);
      v5 += 10;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401AA0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimvert_t>(struct dprimvert_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimvert_t>(
        CByteswap *this,
        dprimvert_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimvert_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401AF0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfacebrushlist_t>(struct dfacebrushlist_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfacebrushlist_t>(
        CByteswap *this,
        dfacebrushlist_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfacebrushlist_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B40
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dbrush_t>(struct dbrush_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dbrush_t>(
        CByteswap *this,
        dbrush_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dbrush_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B90
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dareaportal_t>(struct dareaportal_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dareaportal_t>(
        CByteswap *this,
        dareaportal_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dareaportal_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401BE0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafwaterdata_t>(struct dleafwaterdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafwaterdata_t>(
        CByteswap *this,
        dleafwaterdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafwaterdata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C30
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dcubemapsample_t>(struct dcubemapsample_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dcubemapsample_t>(
        CByteswap *this,
        dcubemapsample_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dcubemapsample_t::m_DataMap);
      v5 += 16;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C80
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlay_t>(struct doverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlay_t>(
        CByteswap *this,
        doverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlay_t::m_DataMap);
      v5 += 352;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401CD0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dwateroverlay_t>(struct dwateroverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dwateroverlay_t>(
        CByteswap *this,
        dwateroverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dwateroverlay_t::m_DataMap);
      v5 += 1120;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401D20
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlayfade_t>(struct doverlayfade_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlayfade_t>(
        CByteswap *this,
        doverlayfade_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlayfade_t::m_DataMap);
      v5 += 8;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401D70
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlaysystemlevel_t>(struct doverlaysystemlevel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlaysystemlevel_t>(
        CByteswap *this,
        doverlaysystemlevel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlaysystemlevel_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401DC0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispMultiBlend>(class CDispMultiBlend __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispMultiBlend>(
        CByteswap *this,
        CDispMultiBlend *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispMultiBlend::m_DataMap);
      v5 += 80;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401E10
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfaceid_t>(struct dfaceid_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfaceid_t>(
        CByteswap *this,
        dfaceid_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfaceid_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402520
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        unsigned int *outputBuffer,
        unsigned int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  unsigned int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (int *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004157D0
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: output, src: &temp, count: 8);
}

//------------------------------------------------------------------------------
// Address: 0x00415830
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004158A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (unsigned __int8 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace vbspinfo

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00440E20
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropDictLump_t>(struct StaticPropDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropDictLump_t>(
        CByteswap *this,
        StaticPropDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440E70
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropLeafLump_t>(struct StaticPropLeafLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropLeafLump_t>(
        CByteswap *this,
        StaticPropLeafLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropLeafLump_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440EC0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailObjectDictLump_t>(struct DetailObjectDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailObjectDictLump_t>(
        CByteswap *this,
        DetailObjectDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailObjectDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440F10
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailPropLightstylesLump_t>(struct DetailPropLightstylesLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailPropLightstylesLump_t>(
        CByteswap *this,
        DetailPropLightstylesLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailPropLightstylesLump_t::m_DataMap);
      v5 += 5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440F60
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_t>(struct dworldlight_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_t>(
        CByteswap *this,
        dworldlight_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_t::m_DataMap);
      v5 += 100;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440FB0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dgamelumpheader_t>(struct dgamelumpheader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dgamelumpheader_t>(
        CByteswap *this,
        dgamelumpheader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dgamelumpheader_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441000
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct BSPHeader_t>(struct BSPHeader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<BSPHeader_t>(
        CByteswap *this,
        BSPHeader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &BSPHeader_t::m_DataMap);
      v5 += 1036;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441050
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientlighting_t>(struct dleafambientlighting_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientlighting_t>(
        CByteswap *this,
        dleafambientlighting_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientlighting_t::m_DataMap);
      v5 += 28;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004410A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientindex_t>(struct dleafambientindex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientindex_t>(
        CByteswap *this,
        dleafambientindex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientindex_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004410F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_version0_t>(struct dworldlight_version0_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_version0_t>(
        CByteswap *this,
        dworldlight_version0_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_version0_t::m_DataMap);
      v5 += 88;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441140
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dflagslump_t>(struct dflagslump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dflagslump_t>(
        CByteswap *this,
        dflagslump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dflagslump_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441190
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dface_t>(struct dface_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dface_t>(
        CByteswap *this,
        dface_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dface_t::m_DataMap);
      v5 += 56;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004411E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dmodel_t>(struct dmodel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dmodel_t>(
        CByteswap *this,
        dmodel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dmodel_t::m_DataMap);
      v5 += 48;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441230
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dvertex_t>(struct dvertex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dvertex_t>(
        CByteswap *this,
        dvertex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dvertex_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441280
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dplane_t>(struct dplane_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dplane_t>(
        CByteswap *this,
        dplane_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dplane_t::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004412D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct texinfo_s>(struct texinfo_s __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<texinfo_s>(
        CByteswap *this,
        texinfo_s *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &texinfo_s::m_DataMap);
      v5 += 72;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441320
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class ddispinfo_t>(class ddispinfo_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<ddispinfo_t>(
        CByteswap *this,
        ddispinfo_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &ddispinfo_t::m_DataMap);
      v5 += 176;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441370
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispVert>(class CDispVert __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispVert>(
        CByteswap *this,
        CDispVert *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispVert::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004413C0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispTri>(class CDispTri __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispTri>(
        CByteswap *this,
        CDispTri *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispTri::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441410
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CFaceMacroTextureInfo>(class CFaceMacroTextureInfo __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CFaceMacroTextureInfo>(
        CByteswap *this,
        CFaceMacroTextureInfo *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CFaceMacroTextureInfo::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441460
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimitive_t>(struct dprimitive_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimitive_t>(
        CByteswap *this,
        dprimitive_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimitive_t::m_DataMap);
      v5 += 10;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004414B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimvert_t>(struct dprimvert_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimvert_t>(
        CByteswap *this,
        dprimvert_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimvert_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441500
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfacebrushlist_t>(struct dfacebrushlist_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfacebrushlist_t>(
        CByteswap *this,
        dfacebrushlist_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfacebrushlist_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441550
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dbrush_t>(struct dbrush_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dbrush_t>(
        CByteswap *this,
        dbrush_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dbrush_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004415A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dareaportal_t>(struct dareaportal_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dareaportal_t>(
        CByteswap *this,
        dareaportal_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dareaportal_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004415F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafwaterdata_t>(struct dleafwaterdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafwaterdata_t>(
        CByteswap *this,
        dleafwaterdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafwaterdata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441640
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dcubemapsample_t>(struct dcubemapsample_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dcubemapsample_t>(
        CByteswap *this,
        dcubemapsample_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dcubemapsample_t::m_DataMap);
      v5 += 16;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441690
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlay_t>(struct doverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlay_t>(
        CByteswap *this,
        doverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlay_t::m_DataMap);
      v5 += 352;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004416E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dwateroverlay_t>(struct dwateroverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dwateroverlay_t>(
        CByteswap *this,
        dwateroverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dwateroverlay_t::m_DataMap);
      v5 += 1120;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441730
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlayfade_t>(struct doverlayfade_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlayfade_t>(
        CByteswap *this,
        doverlayfade_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlayfade_t::m_DataMap);
      v5 += 8;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441780
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlaysystemlevel_t>(struct doverlaysystemlevel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlaysystemlevel_t>(
        CByteswap *this,
        doverlaysystemlevel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlaysystemlevel_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004417D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderdata_t>(struct doccluderdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderdata_t>(
        CByteswap *this,
        doccluderdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderdata_t::m_DataMap);
      v5 += 40;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441820
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderpolydata_t>(struct doccluderpolydata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderpolydata_t>(
        CByteswap *this,
        doccluderpolydata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderpolydata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441870
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispMultiBlend>(class CDispMultiBlend __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispMultiBlend>(
        CByteswap *this,
        CDispMultiBlend *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispMultiBlend::m_DataMap);
      v5 += 80;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004418C0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfaceid_t>(struct dfaceid_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfaceid_t>(
        CByteswap *this,
        dfaceid_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfaceid_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064BCF0
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: output, src: &temp, count: 8);
}

//------------------------------------------------------------------------------
// Address: 0x0064BD50
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064BDC0
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (unsigned __int8 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace vmap

// ============================================================
// Overlay from vphysics (Missing functions)
// ============================================================
namespace vphysics {

//------------------------------------------------------------------------------
// Address: 0x100AD4A0
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: (unsigned __int8 *)output, src: (unsigned __int8 *)&temp, count: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x100AD500
// Name: public: void CByteswap::SwapBufferToTargetEndian<short>(short __near *,short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        __int16 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = (unsigned __int8 *)inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: (unsigned __int8 *)&count, count: 2u);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD580
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (unsigned __int8 *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *(_DWORD *)v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5, src: (unsigned __int8 *)&count, count: 4u);
          v5 += 4;
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD610
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD680
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  int *v7; // ebx
  int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (int *)&pBaseData[v6];
      v8 = (int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (__int16 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (int *)((char *)v8 + v10);
              v7 = (int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace vphysics

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10035F90
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropDictLump_t>(struct StaticPropDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropDictLump_t>(
        CByteswap *this,
        StaticPropDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035FE0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropLeafLump_t>(struct StaticPropLeafLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropLeafLump_t>(
        CByteswap *this,
        StaticPropLeafLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropLeafLump_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036030
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailObjectDictLump_t>(struct DetailObjectDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailObjectDictLump_t>(
        CByteswap *this,
        DetailObjectDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailObjectDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036080
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailPropLightstylesLump_t>(struct DetailPropLightstylesLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailPropLightstylesLump_t>(
        CByteswap *this,
        DetailPropLightstylesLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailPropLightstylesLump_t::m_DataMap);
      v5 += 5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100360D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_t>(struct dworldlight_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_t>(
        CByteswap *this,
        dworldlight_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_t::m_DataMap);
      v5 += 100;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036120
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dgamelumpheader_t>(struct dgamelumpheader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dgamelumpheader_t>(
        CByteswap *this,
        dgamelumpheader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dgamelumpheader_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036170
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct BSPHeader_t>(struct BSPHeader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<BSPHeader_t>(
        CByteswap *this,
        BSPHeader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &BSPHeader_t::m_DataMap);
      v5 += 1036;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100361C0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientlighting_t>(struct dleafambientlighting_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientlighting_t>(
        CByteswap *this,
        dleafambientlighting_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientlighting_t::m_DataMap);
      v5 += 28;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036210
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientindex_t>(struct dleafambientindex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientindex_t>(
        CByteswap *this,
        dleafambientindex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientindex_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036260
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_version0_t>(struct dworldlight_version0_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_version0_t>(
        CByteswap *this,
        dworldlight_version0_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_version0_t::m_DataMap);
      v5 += 88;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100362B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dflagslump_t>(struct dflagslump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dflagslump_t>(
        CByteswap *this,
        dflagslump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dflagslump_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036300
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dface_t>(struct dface_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dface_t>(
        CByteswap *this,
        dface_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dface_t::m_DataMap);
      v5 += 56;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036350
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dmodel_t>(struct dmodel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dmodel_t>(
        CByteswap *this,
        dmodel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dmodel_t::m_DataMap);
      v5 += 48;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100363A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dvertex_t>(struct dvertex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dvertex_t>(
        CByteswap *this,
        dvertex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dvertex_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100363F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dplane_t>(struct dplane_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dplane_t>(
        CByteswap *this,
        dplane_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dplane_t::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036440
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct texinfo_s>(struct texinfo_s __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<texinfo_s>(
        CByteswap *this,
        texinfo_s *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &texinfo_s::m_DataMap);
      v5 += 72;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036490
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class ddispinfo_t>(class ddispinfo_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<ddispinfo_t>(
        CByteswap *this,
        ddispinfo_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &ddispinfo_t::m_DataMap);
      v5 += 176;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100364E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispVert>(class CDispVert __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispVert>(
        CByteswap *this,
        CDispVert *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispVert::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036530
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispTri>(class CDispTri __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispTri>(
        CByteswap *this,
        CDispTri *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispTri::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036580
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CFaceMacroTextureInfo>(class CFaceMacroTextureInfo __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CFaceMacroTextureInfo>(
        CByteswap *this,
        CFaceMacroTextureInfo *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CFaceMacroTextureInfo::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100365D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimitive_t>(struct dprimitive_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimitive_t>(
        CByteswap *this,
        dprimitive_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimitive_t::m_DataMap);
      v5 += 10;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036620
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimvert_t>(struct dprimvert_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimvert_t>(
        CByteswap *this,
        dprimvert_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimvert_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036670
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfacebrushlist_t>(struct dfacebrushlist_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfacebrushlist_t>(
        CByteswap *this,
        dfacebrushlist_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfacebrushlist_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100366C0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dbrush_t>(struct dbrush_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dbrush_t>(
        CByteswap *this,
        dbrush_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dbrush_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036710
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dareaportal_t>(struct dareaportal_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dareaportal_t>(
        CByteswap *this,
        dareaportal_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dareaportal_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036760
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafwaterdata_t>(struct dleafwaterdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafwaterdata_t>(
        CByteswap *this,
        dleafwaterdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafwaterdata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100367B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dcubemapsample_t>(struct dcubemapsample_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dcubemapsample_t>(
        CByteswap *this,
        dcubemapsample_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dcubemapsample_t::m_DataMap);
      v5 += 16;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036800
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlay_t>(struct doverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlay_t>(
        CByteswap *this,
        doverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlay_t::m_DataMap);
      v5 += 352;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036850
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dwateroverlay_t>(struct dwateroverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dwateroverlay_t>(
        CByteswap *this,
        dwateroverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dwateroverlay_t::m_DataMap);
      v5 += 1120;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100368A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlayfade_t>(struct doverlayfade_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlayfade_t>(
        CByteswap *this,
        doverlayfade_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlayfade_t::m_DataMap);
      v5 += 8;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100368F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlaysystemlevel_t>(struct doverlaysystemlevel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlaysystemlevel_t>(
        CByteswap *this,
        doverlaysystemlevel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlaysystemlevel_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036940
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderdata_t>(struct doccluderdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderdata_t>(
        CByteswap *this,
        doccluderdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderdata_t::m_DataMap);
      v5 += 40;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036990
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderpolydata_t>(struct doccluderpolydata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderpolydata_t>(
        CByteswap *this,
        doccluderpolydata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderpolydata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100369E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispMultiBlend>(class CDispMultiBlend __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispMultiBlend>(
        CByteswap *this,
        CDispMultiBlend *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispMultiBlend::m_DataMap);
      v5 += 80;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036A30
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfaceid_t>(struct dfaceid_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfaceid_t>(
        CByteswap *this,
        dfaceid_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfaceid_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080550
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: output, src: &temp, count: 8);
}

//------------------------------------------------------------------------------
// Address: 0x100805B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080620
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (unsigned __int8 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x100012F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropDictLump_t>(struct StaticPropDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropDictLump_t>(
        CByteswap *this,
        StaticPropDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001340
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct StaticPropLeafLump_t>(struct StaticPropLeafLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<StaticPropLeafLump_t>(
        CByteswap *this,
        StaticPropLeafLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &StaticPropLeafLump_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001390
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailObjectDictLump_t>(struct DetailObjectDictLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailObjectDictLump_t>(
        CByteswap *this,
        DetailObjectDictLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailObjectDictLump_t::m_DataMap);
      v5 += 128;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100013E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct DetailPropLightstylesLump_t>(struct DetailPropLightstylesLump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<DetailPropLightstylesLump_t>(
        CByteswap *this,
        DetailPropLightstylesLump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &DetailPropLightstylesLump_t::m_DataMap);
      v5 += 5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001430
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_t>(struct dworldlight_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_t>(
        CByteswap *this,
        dworldlight_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_t::m_DataMap);
      v5 += 100;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001480
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dgamelumpheader_t>(struct dgamelumpheader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dgamelumpheader_t>(
        CByteswap *this,
        dgamelumpheader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dgamelumpheader_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100014D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct BSPHeader_t>(struct BSPHeader_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<BSPHeader_t>(
        CByteswap *this,
        BSPHeader_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &BSPHeader_t::m_DataMap);
      v5 += 1036;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001520
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientlighting_t>(struct dleafambientlighting_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientlighting_t>(
        CByteswap *this,
        dleafambientlighting_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientlighting_t::m_DataMap);
      v5 += 28;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001570
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafambientindex_t>(struct dleafambientindex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafambientindex_t>(
        CByteswap *this,
        dleafambientindex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafambientindex_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100015C0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dworldlight_version0_t>(struct dworldlight_version0_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dworldlight_version0_t>(
        CByteswap *this,
        dworldlight_version0_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dworldlight_version0_t::m_DataMap);
      v5 += 88;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001610
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dflagslump_t>(struct dflagslump_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dflagslump_t>(
        CByteswap *this,
        dflagslump_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dflagslump_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001660
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dface_t>(struct dface_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dface_t>(
        CByteswap *this,
        dface_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dface_t::m_DataMap);
      v5 += 56;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100016B0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dmodel_t>(struct dmodel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dmodel_t>(
        CByteswap *this,
        dmodel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dmodel_t::m_DataMap);
      v5 += 48;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001700
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dvertex_t>(struct dvertex_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dvertex_t>(
        CByteswap *this,
        dvertex_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dvertex_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001750
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dplane_t>(struct dplane_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dplane_t>(
        CByteswap *this,
        dplane_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dplane_t::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100017A0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct texinfo_s>(struct texinfo_s __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<texinfo_s>(
        CByteswap *this,
        texinfo_s *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &texinfo_s::m_DataMap);
      v5 += 72;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100017F0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class ddispinfo_t>(class ddispinfo_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<ddispinfo_t>(
        CByteswap *this,
        ddispinfo_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &ddispinfo_t::m_DataMap);
      v5 += 176;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001840
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispVert>(class CDispVert __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispVert>(
        CByteswap *this,
        CDispVert *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispVert::m_DataMap);
      v5 += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispTri>(class CDispTri __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispTri>(
        CByteswap *this,
        CDispTri *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispTri::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100018E0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CFaceMacroTextureInfo>(class CFaceMacroTextureInfo __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CFaceMacroTextureInfo>(
        CByteswap *this,
        CFaceMacroTextureInfo *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CFaceMacroTextureInfo::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001930
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimitive_t>(struct dprimitive_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimitive_t>(
        CByteswap *this,
        dprimitive_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimitive_t::m_DataMap);
      v5 += 10;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001980
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dprimvert_t>(struct dprimvert_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dprimvert_t>(
        CByteswap *this,
        dprimvert_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dprimvert_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100019D0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfacebrushlist_t>(struct dfacebrushlist_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfacebrushlist_t>(
        CByteswap *this,
        dfacebrushlist_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfacebrushlist_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A20
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dbrush_t>(struct dbrush_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dbrush_t>(
        CByteswap *this,
        dbrush_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dbrush_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A70
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dareaportal_t>(struct dareaportal_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dareaportal_t>(
        CByteswap *this,
        dareaportal_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dareaportal_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001AC0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dleafwaterdata_t>(struct dleafwaterdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dleafwaterdata_t>(
        CByteswap *this,
        dleafwaterdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dleafwaterdata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B10
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dcubemapsample_t>(struct dcubemapsample_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dcubemapsample_t>(
        CByteswap *this,
        dcubemapsample_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dcubemapsample_t::m_DataMap);
      v5 += 16;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B60
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlay_t>(struct doverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlay_t>(
        CByteswap *this,
        doverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlay_t::m_DataMap);
      v5 += 352;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001BB0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dwateroverlay_t>(struct dwateroverlay_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dwateroverlay_t>(
        CByteswap *this,
        dwateroverlay_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dwateroverlay_t::m_DataMap);
      v5 += 1120;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001C00
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlayfade_t>(struct doverlayfade_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlayfade_t>(
        CByteswap *this,
        doverlayfade_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlayfade_t::m_DataMap);
      v5 += 8;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001C50
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doverlaysystemlevel_t>(struct doverlaysystemlevel_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doverlaysystemlevel_t>(
        CByteswap *this,
        doverlaysystemlevel_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doverlaysystemlevel_t::m_DataMap);
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001CA0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderdata_t>(struct doccluderdata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderdata_t>(
        CByteswap *this,
        doccluderdata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderdata_t::m_DataMap);
      v5 += 40;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001CF0
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct doccluderpolydata_t>(struct doccluderpolydata_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<doccluderpolydata_t>(
        CByteswap *this,
        doccluderpolydata_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &doccluderpolydata_t::m_DataMap);
      v5 += 12;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D40
// Name: public: void CByteswap::SwapFieldsToTargetEndian<class CDispMultiBlend>(class CDispMultiBlend __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<CDispMultiBlend>(
        CByteswap *this,
        CDispMultiBlend *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &CDispMultiBlend::m_DataMap);
      v5 += 80;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D90
// Name: public: void CByteswap::SwapFieldsToTargetEndian<struct dfaceid_t>(struct dfaceid_t __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian<dfaceid_t>(
        CByteswap *this,
        dfaceid_t *pOutputBuffer,
        char *pBaseData,
        unsigned int objectCount)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = objectCount;
  if ( objectCount != 0 )
  {
    v5 = pBaseData;
    do
    {
      CByteswap::SwapFieldsToTargetEndian(
        this,
        pOutputBuffer: &v5[(char *)pOutputBuffer - pBaseData],
        pBaseData: v5,
        pDataMap: &dfaceid_t::m_DataMap);
      v5 += 2;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100024A0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        unsigned int *outputBuffer,
        unsigned int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  unsigned int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (int *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D870
// Name: private: static void CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CByteswap::LowLevelByteSwap<unsigned __int64>(unsigned __int64 *output, unsigned __int64 *input)
{
  int v2; // eax
  unsigned __int64 temp; // [esp+0h] [ebp-8h] BYREF

  v2 = *(_DWORD *)output;
  HIDWORD(temp) = *((_DWORD *)output + 1);
  LODWORD(temp) = v2;
  LOBYTE(temp) = *((_BYTE *)input + 7);
  BYTE1(temp) = *((_BYTE *)input + 6);
  BYTE2(temp) = *((_BYTE *)input + 5);
  BYTE3(temp) = *((_BYTE *)input + 4);
  BYTE4(temp) = *((_BYTE *)input + 3);
  BYTE5(temp) = *((_BYTE *)input + 2);
  LOBYTE(v2) = *(_BYTE *)input;
  BYTE6(temp) = *((_BYTE *)input + 1);
  HIBYTE(temp) = v2;
  _V_memcpy(dest: output, src: &temp, count: 8);
}

//------------------------------------------------------------------------------
// Address: 0x1001D8D0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned __int64>(unsigned __int64 __near *,unsigned __int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
        CByteswap *this,
        unsigned __int64 *outputBuffer,
        unsigned __int64 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int64 *v5; // esi
  unsigned __int64 *v6; // edi
  int v7; // edi

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 - (char *)outputBuffer;
        do
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v5, input: (unsigned __int64 *)((char *)v5 + v7));
          ++v5;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 8 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D940
// Name: public: void CByteswap::SwapFieldsToTargetEndian(void __near *,void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapFieldsToTargetEndian(
        CByteswap *this,
        char *pOutputBuffer,
        char *pBaseData,
        datamap_t *pDataMap)
{
  datamap_t *baseMap; // eax
  unsigned __int16 *p_fieldSize; // esi
  int v6; // edi
  unsigned int *v7; // ebx
  unsigned int *v8; // edi
  signed int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int dataNumFields; // [esp+Ch] [ebp-8h]
  datamap_t *pDataMapa; // [esp+24h] [ebp+10h]

  baseMap = pDataMap->baseMap;
  if ( baseMap != nullptr )
    CByteswap::SwapFieldsToTargetEndian(this, pOutputBuffer, pBaseData, pDataMap: baseMap);
  if ( pDataMap->dataNumFields > 0 )
  {
    p_fieldSize = &pDataMap->dataDesc->fieldSize;
    dataNumFields = pDataMap->dataNumFields;
    do
    {
      v6 = *((_DWORD *)p_fieldSize - 1);
      v7 = (unsigned int *)&pBaseData[v6];
      v8 = (unsigned int *)&pOutputBuffer[v6];
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 5:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: *p_fieldSize);
          break;
        case 3:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 3 * *p_fieldSize);
          break;
        case 4:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 4 * *p_fieldSize);
          break;
        case 6:
        case 8:
          v9 = *p_fieldSize;
          goto LABEL_7;
        case 7:
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this,
            outputBuffer: (unsigned __int8 *)v8,
            inputBuffer: (unsigned __int8 *)v7,
            count: *p_fieldSize);
          break;
        case 9:
          v9 = 4 * *p_fieldSize;
LABEL_7:
          if ( v9 > 0 && v8 != nullptr && v7 != nullptr && v8 != v7 )
            memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)v7, count: v9);
          break;
        case 0xA:
          v11 = **((_DWORD **)p_fieldSize + 4);
          pDataMapa = nullptr;
          if ( *p_fieldSize != 0 )
          {
            do
            {
              CByteswap::SwapFieldsToTargetEndian(
                this,
                pOutputBuffer: (char *)v8 + *(_DWORD *)(v11 + 8),
                pBaseData: (char *)v7 + *(_DWORD *)(v11 + 8),
                pDataMap: *((datamap_t **)p_fieldSize + 4));
              v10 = *((_DWORD *)p_fieldSize + 5);
              v8 = (unsigned int *)((char *)v8 + v10);
              v7 = (unsigned int *)((char *)v7 + v10);
              pDataMapa = (datamap_t *)((char *)pDataMapa + 1);
            }
            while ( (int)pDataMapa < *p_fieldSize );
          }
          break;
        case 0x1C:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this,
            outputBuffer: v8,
            inputBuffer: v7,
            count: 2 * *p_fieldSize);
          break;
        case 0x1D:
          CByteswap::SwapBufferToTargetEndian<unsigned __int64>(
            this,
            outputBuffer: (unsigned __int64 *)v8,
            inputBuffer: (unsigned __int64 *)v7,
            count: *p_fieldSize);
          break;
        default:
          break;
      }
      p_fieldSize += 30;
      --dataNumFields;
    }
    while ( dataNumFields != 0 );
  }
}

} // namespace vvis_dll
