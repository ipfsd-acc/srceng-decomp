// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/stackstats.cpp
// Functions: 4
// ============================================================

#include "tier0\stackstats.h"

//------------------------------------------------------------------------------
// Address: 0x1000C4A0
// Name: bool _CCallStackStatsGatherer_Internal_DumpSubTree(class CCallStackStatsGatherer_Standardized_t const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl _CCallStackStatsGatherer_Internal_DumpSubTree(
        const CCallStackStatsGatherer_Standardized_t *StatsGatherer,
        unsigned __int8 **pDumpHelpers)
{
  const CCallStackStatsGatherer_FunctionTable_t *pFunctionTable; // ecx
  void *pGatherer; // eax
  unsigned int *v5; // esi
  unsigned __int8 *v6; // ebx
  _iobuf *v7; // edi
  void *v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  char *v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  unsigned int v19; // ebx
  int v20; // edi
  int v21; // edx
  int v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // ebx
  bool v25; // zf
  unsigned __int8 *v26; // ebx
  unsigned __int8 *v27; // ecx
  unsigned int v28; // ebx
  unsigned __int8 *v29; // ebx
  int k; // eax
  unsigned int v31; // eax
  _iobuf *v32; // ebx
  unsigned int v33; // eax
  unsigned int v34; // edi
  const void **v35; // edi
  unsigned int v36; // edi
  unsigned int v37; // eax
  unsigned int v38; // edi
  unsigned int v39; // eax
  unsigned int v40; // edi
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // edi
  unsigned __int8 *v44; // edi
  unsigned int v45; // eax
  int v46; // esi
  char szBuff[1024]; // [esp+4h] [ebp-448h] BYREF
  unsigned int iInfoPos; // [esp+404h] [ebp-48h]
  const char *szStructName; // [esp+408h] [ebp-44h] BYREF
  unsigned int iSubToolDataSize; // [esp+40Ch] [ebp-40h] BYREF
  CCallStackStatsGatherer_Standardized_t *pSubTrees; // [esp+410h] [ebp-3Ch] BYREF
  unsigned int iEntrySizeWithCallStack; // [esp+414h] [ebp-38h] BYREF
  unsigned int iSubTreeCount; // [esp+418h] [ebp-34h] BYREF
  unsigned int j; // [esp+41Ch] [ebp-30h] BYREF
  int i; // [esp+420h] [ebp-2Ch]
  void *pEntries; // [esp+424h] [ebp-28h] BYREF
  unsigned int CapturedCallStackLength; // [esp+428h] [ebp-24h] BYREF
  unsigned int iLine; // [esp+42Ch] [ebp-20h] BYREF
  unsigned int iEntryCount; // [esp+430h] [ebp-1Ch] BYREF
  unsigned __int8 *pEntryRead; // [esp+434h] [ebp-18h]
  unsigned int maxSize; // [esp+438h] [ebp-14h]
  int iUniqueAddresses; // [esp+43Ch] [ebp-10h] BYREF
  unsigned __int8 *pWriteBuffer; // [esp+440h] [ebp-Ch]
  void *pInsertAddress; // [esp+444h] [ebp-8h]
  unsigned int iWriteBufferSize; // [esp+448h] [ebp-4h]
  unsigned int pSortedAddresses; // [esp+454h] [ebp+8h]
  unsigned __int8 *pSortedAddressesa; // [esp+454h] [ebp+8h]

  pFunctionTable = StatsGatherer->pFunctionTable;
  pGatherer = StatsGatherer->pGatherer;
  CapturedCallStackLength = 0;
  iEntrySizeWithCallStack = 0;
  pEntries = nullptr;
  iEntryCount = 0;
  pSubTrees = nullptr;
  iSubTreeCount = 0;
  szStructName = (const char *)&unk_1002C436;
  pFunctionTable->pfn_GetDumpInfo(
    a1: pGatherer,
    a2: &szStructName,
    a3: &CapturedCallStackLength,
    a4: &iEntrySizeWithCallStack,
    a5: &pEntries,
    a6: &iEntryCount,
    a7: &pSubTrees,
    a8: &iSubTreeCount);
  if ( iEntryCount == 0 )
    return 0;
  v5 = (unsigned int *)pDumpHelpers[2];
  v6 = *pDumpHelpers;
  iWriteBufferSize = (unsigned int)pDumpHelpers[1];
  v7 = (_iobuf *)pDumpHelpers[3];
  pWriteBuffer = v6;
  iLine = (unsigned int)v7;
  i = (int)(szStructName + 1);
  pEntryRead = (unsigned __int8 *)szStructName;
  v8 = (void *)(strlen(szStructName) + 1);
  v9 = *v5;
  v10 = (unsigned int)v8 + *v5;
  pInsertAddress = v8;
  if ( v10 <= iWriteBufferSize )
    goto LABEL_8;
  if ( v9 != 0 )
  {
    fwrite(buffer: v6, size: 1u, count: v9, stream: v7);
    v8 = pInsertAddress;
    *v5 = 0;
  }
  if ( (unsigned int)v8 <= iWriteBufferSize )
  {
LABEL_8:
    memcpy(dst: &v6[*v5], src: pEntryRead, count: (unsigned int)pInsertAddress);
    *v5 += (unsigned int)pInsertAddress;
  }
  else
  {
    fwrite(buffer: pEntryRead, size: (unsigned int)pInsertAddress, count: 1u, stream: v7);
  }
  j = iSubTreeCount;
  v11 = *v5;
  if ( *v5 + 4 <= iWriteBufferSize )
    goto LABEL_14;
  if ( v11 != 0 )
  {
    fwrite(buffer: v6, size: 1u, count: v11, stream: v7);
    *v5 = 0;
  }
  if ( iWriteBufferSize >= 4 )
  {
LABEL_14:
    *(_DWORD *)&v6[*v5] = j;
    *v5 += 4;
  }
  else
  {
    fwrite(buffer: &j, size: 4u, count: 1u, stream: v7);
  }
  v12 = 0;
  for ( maxSize = 0; v12 != iSubTreeCount; maxSize = v12 )
  {
    pEntryRead = (unsigned __int8 *)&pSubTrees[v12];
    v13 = *v5;
    if ( *v5 + 4 <= iWriteBufferSize )
      goto LABEL_21;
    if ( v13 != 0 )
    {
      fwrite(buffer: v6, size: 1u, count: v13, stream: v7);
      *v5 = 0;
    }
    if ( iWriteBufferSize >= 4 )
    {
LABEL_21:
      *(_DWORD *)&v6[*v5] = *(_DWORD *)pEntryRead;
      *v5 += 4;
    }
    else
    {
      fwrite(buffer: pEntryRead, size: 4u, count: 1u, stream: v7);
    }
    v12 = maxSize + 1;
  }
  v14 = *v5;
  if ( *v5 + 4 <= iWriteBufferSize )
    goto LABEL_28;
  if ( v14 != 0 )
  {
    fwrite(buffer: v6, size: 1u, count: v14, stream: v7);
    *v5 = 0;
  }
  if ( iWriteBufferSize >= 4 )
  {
LABEL_28:
    *(_DWORD *)&v6[*v5] = CapturedCallStackLength;
    *v5 += 4;
  }
  else
  {
    fwrite(buffer: &CapturedCallStackLength, size: 4u, count: 1u, stream: v7);
  }
  v15 = *v5;
  if ( *v5 + 4 <= iWriteBufferSize )
    goto LABEL_34;
  if ( v15 != 0 )
  {
    fwrite(buffer: v6, size: 1u, count: v15, stream: v7);
    *v5 = 0;
  }
  if ( iWriteBufferSize >= 4 )
  {
LABEL_34:
    *(_DWORD *)&v6[*v5] = iEntrySizeWithCallStack;
    *v5 += 4;
  }
  else
  {
    fwrite(buffer: &iEntrySizeWithCallStack, size: 4u, count: 1u, stream: v7);
  }
  if ( *v5 != 0 )
  {
    fwrite(buffer: v6, size: 1u, count: *v5, stream: v7);
    *v5 = 0;
  }
  pInsertAddress = (void *)*v5;
  v16 = (char *)pInsertAddress + 4;
  *v5 = (unsigned int)pInsertAddress + 4;
  *v5 += StatsGatherer->pFunctionTable->pfn_DescribeCallStackStatStruct(
           a1: (unsigned __int8 *)&v16[(_DWORD)v6],
           a2: iWriteBufferSize - (_DWORD)v16);
  *(_DWORD *)&v6[(_DWORD)pInsertAddress] = *v5 - (_DWORD)pInsertAddress - 4;
  v17 = *v5;
  if ( *v5 + 4 <= iWriteBufferSize )
    goto LABEL_42;
  if ( v17 != 0 )
  {
    fwrite(buffer: v6, size: 1u, count: v17, stream: v7);
    *v5 = 0;
  }
  if ( iWriteBufferSize >= 4 )
  {
LABEL_42:
    *(_DWORD *)&v6[*v5] = iEntryCount;
    *v5 += 4;
  }
  else
  {
    fwrite(buffer: &iEntryCount, size: 4u, count: 1u, stream: v7);
  }
  pInsertAddress = (void *)*v5;
  v18 = ftell(stream: v7);
  iInfoPos = (unsigned int)pInsertAddress + v18;
  pSortedAddresses = iEntrySizeWithCallStack * iEntryCount;
  pEntryRead = (unsigned __int8 *)pEntries;
  if ( (unsigned int)pInsertAddress + iEntrySizeWithCallStack * iEntryCount <= iWriteBufferSize )
    goto LABEL_48;
  if ( pInsertAddress != nullptr )
  {
    fwrite(buffer: v6, size: 1u, count: (unsigned int)pInsertAddress, stream: v7);
    *v5 = 0;
  }
  if ( pSortedAddresses <= iWriteBufferSize )
  {
LABEL_48:
    memcpy(dst: &v6[*v5], src: pEntryRead, count: pSortedAddresses);
    *v5 += pSortedAddresses;
  }
  else
  {
    fwrite(buffer: pEntryRead, size: pSortedAddresses, count: 1u, stream: v7);
  }
  if ( *v5 != 0 )
  {
    fwrite(buffer: v6, size: 1u, count: *v5, stream: v7);
    *v5 = 0;
  }
  pSortedAddressesa = v6;
  v19 = iEntryCount;
  iUniqueAddresses = 0;
  maxSize = iWriteBufferSize >> 2;
  pEntryRead = (unsigned __int8 *)pEntries;
  i = 0;
  if ( iEntryCount == 0 )
  {
LABEL_82:
    pWriteBuffer += 4 * iUniqueAddresses;
    iWriteBufferSize -= 4 * iUniqueAddresses;
    goto LABEL_83;
  }
  do
  {
    j = 0;
    if ( CapturedCallStackLength == 0 )
      goto LABEL_80;
    do
    {
      pInsertAddress = *(void **)&pEntryRead[4 * j];
      if ( pInsertAddress == nullptr )
        break;
      v20 = 0;
      v21 = iUniqueAddresses - 1;
      if ( iUniqueAddresses - 1 >= 0 )
      {
        while ( 1 )
        {
          v22 = (v20 + v21) >> 1;
          v23 = *(_DWORD *)&pSortedAddressesa[4 * v22];
          if ( v23 <= (unsigned int)pInsertAddress )
            break;
          v21 = v22 - 1;
LABEL_59:
          if ( v21 < v20 )
            goto LABEL_62;
        }
        if ( v23 < (unsigned int)pInsertAddress )
        {
          v20 = v22 + 1;
          goto LABEL_59;
        }
        v20 = (v20 + v21) >> 1;
      }
LABEL_62:
      if ( v20 > iUniqueAddresses )
      {
        if ( iUniqueAddresses >= (int)maxSize )
        {
          v24 = 4 * CapturedCallStackLength * v19;
          v25 = *((_BYTE *)pDumpHelpers + 16) == 0;
          maxSize = v24;
          if ( v25 || (v26 = (unsigned __int8 *)operator new[](cb: 4 * v24)) == nullptr )
            v26 = (unsigned __int8 *)pEntries;
          memcpy(dst: v26, src: pSortedAddressesa, count: 4 * iUniqueAddresses);
          pSortedAddressesa = v26;
        }
        *(_DWORD *)&pSortedAddressesa[4 * v20] = pInsertAddress;
        ++iUniqueAddresses;
        goto LABEL_78;
      }
      v27 = pSortedAddressesa;
      if ( *(void **)&pSortedAddressesa[4 * v20] != pInsertAddress )
      {
        if ( iUniqueAddresses >= (int)maxSize )
        {
          v28 = 4 * CapturedCallStackLength * v19;
          v25 = *((_BYTE *)pDumpHelpers + 16) == 0;
          maxSize = v28;
          if ( v25 || (v29 = (unsigned __int8 *)operator new[](cb: 4 * v28)) == nullptr )
            v29 = (unsigned __int8 *)pEntries;
          memcpy(dst: v29, src: pSortedAddressesa, count: 4 * iUniqueAddresses);
          pSortedAddressesa = v29;
          v27 = v29;
        }
        for ( k = iUniqueAddresses - 1; k >= v20; --k )
          *(_DWORD *)&v27[4 * k + 4] = *(_DWORD *)&v27[4 * k];
        ++iUniqueAddresses;
        *(_DWORD *)&v27[4 * v20] = pInsertAddress;
LABEL_78:
        v19 = iEntryCount;
      }
      ++j;
    }
    while ( j != CapturedCallStackLength );
LABEL_80:
    pEntryRead += iEntrySizeWithCallStack;
    ++i;
  }
  while ( i != v19 );
  if ( pSortedAddressesa == pWriteBuffer )
    goto LABEL_82;
LABEL_83:
  v31 = *v5;
  if ( *v5 + 4 <= iWriteBufferSize )
    goto LABEL_88;
  if ( v31 != 0 )
  {
    fwrite(buffer: pWriteBuffer, size: 1u, count: v31, stream: (_iobuf *)iLine);
    *v5 = 0;
  }
  if ( iWriteBufferSize >= 4 )
  {
LABEL_88:
    v32 = (_iobuf *)iLine;
    *(_DWORD *)&pWriteBuffer[*v5] = iUniqueAddresses;
    *v5 += 4;
  }
  else
  {
    v32 = (_iobuf *)iLine;
    fwrite(buffer: &iUniqueAddresses, size: 4u, count: 1u, stream: (_iobuf *)iLine);
  }
  i = 0;
  if ( iUniqueAddresses != 0 )
  {
    pInsertAddress = pSortedAddressesa;
    do
    {
      v33 = *v5;
      v34 = iWriteBufferSize;
      if ( *v5 + 4 <= iWriteBufferSize )
        goto LABEL_96;
      if ( v33 != 0 )
      {
        fwrite(buffer: pWriteBuffer, size: 1u, count: v33, stream: v32);
        *v5 = 0;
      }
      if ( v34 >= 4 )
      {
LABEL_96:
        v35 = (const void **)pInsertAddress;
        *(_DWORD *)&pWriteBuffer[*v5] = *(_DWORD *)pInsertAddress;
        *v5 += 4;
      }
      else
      {
        v35 = (const void **)pInsertAddress;
        fwrite(buffer: pInsertAddress, size: 4u, count: 1u, stream: v32);
      }
      if ( !GetModuleNameFromAddress(pAddress: *v35, pModuleNameOut: szBuff, iMaxModuleNameLength: 1024) )
        szBuff[0] = 0;
      v36 = strlen(szBuff) + 1;
      v37 = *v5;
      if ( *v5 + v36 <= iWriteBufferSize )
        goto LABEL_104;
      if ( v37 != 0 )
      {
        fwrite(buffer: pWriteBuffer, size: 1u, count: v37, stream: v32);
        *v5 = 0;
      }
      if ( v36 <= iWriteBufferSize )
      {
LABEL_104:
        memcpy(dst: &pWriteBuffer[*v5], src: (unsigned __int8 *)szBuff, count: v36);
        *v5 += v36;
      }
      else
      {
        fwrite(buffer: szBuff, size: v36, count: 1u, stream: v32);
      }
      if ( !GetSymbolNameFromAddress(
              pAddress: *(const void **)pInsertAddress,
              pSymbolNameOut: szBuff,
              iMaxSymbolNameLength: 1024,
              pDisplacementOut: nullptr) )
        szBuff[0] = 0;
      v38 = strlen(szBuff) + 1;
      v39 = *v5;
      if ( *v5 + v38 <= iWriteBufferSize )
        goto LABEL_112;
      if ( v39 != 0 )
      {
        fwrite(buffer: pWriteBuffer, size: 1u, count: v39, stream: v32);
        *v5 = 0;
      }
      if ( v38 <= iWriteBufferSize )
      {
LABEL_112:
        memcpy(dst: &pWriteBuffer[*v5], src: (unsigned __int8 *)szBuff, count: v38);
        *v5 += v38;
      }
      else
      {
        fwrite(buffer: szBuff, size: v38, count: 1u, stream: v32);
      }
      if ( !GetFileAndLineFromAddress(
              pAddress: *(const void **)pInsertAddress,
              pFileNameOut: szBuff,
              iMaxFileNameLength: 1024,
              iLineNumberOut: &iLine,
              pDisplacementOut: nullptr) )
      {
        szBuff[0] = 0;
        iLine = 0;
      }
      v40 = strlen(szBuff) + 1;
      v41 = *v5;
      if ( *v5 + v40 <= iWriteBufferSize )
        goto LABEL_120;
      if ( v41 != 0 )
      {
        fwrite(buffer: pWriteBuffer, size: 1u, count: v41, stream: v32);
        *v5 = 0;
      }
      if ( v40 <= iWriteBufferSize )
      {
LABEL_120:
        memcpy(dst: &pWriteBuffer[*v5], src: (unsigned __int8 *)szBuff, count: v40);
        *v5 += v40;
      }
      else
      {
        fwrite(buffer: szBuff, size: v40, count: 1u, stream: v32);
      }
      v42 = *v5;
      v43 = iWriteBufferSize;
      if ( *v5 + 4 <= iWriteBufferSize )
        goto LABEL_126;
      if ( v42 != 0 )
      {
        fwrite(buffer: pWriteBuffer, size: 1u, count: v42, stream: v32);
        *v5 = 0;
      }
      if ( v43 >= 4 )
      {
LABEL_126:
        *(_DWORD *)&pWriteBuffer[*v5] = iLine;
        *v5 += 4;
      }
      else
      {
        fwrite(buffer: &iLine, size: 4u, count: 1u, stream: v32);
      }
      pInsertAddress = (char *)pInsertAddress + 4;
      ++i;
    }
    while ( i != iUniqueAddresses );
  }
  v44 = pWriteBuffer;
  iSubToolDataSize = 0;
  v45 = *v5;
  if ( *v5 + 4 <= iWriteBufferSize )
    goto LABEL_133;
  if ( v45 != 0 )
  {
    fwrite(buffer: pWriteBuffer, size: 1u, count: v45, stream: v32);
    *v5 = 0;
  }
  if ( iWriteBufferSize >= 4 )
  {
LABEL_133:
    *(_DWORD *)&v44[*v5] = iSubToolDataSize;
    *v5 += 4;
  }
  else
  {
    fwrite(buffer: &iSubToolDataSize, size: 4u, count: 1u, stream: v32);
  }
  if ( *v5 != 0 )
  {
    fwrite(buffer: v44, size: 1u, count: *v5, stream: v32);
    *v5 = 0;
  }
  if ( pSortedAddressesa == pEntries )
  {
    fseek(stream: v32, offset: iInfoPos, whence: 0);
    fread(buffer: pEntries, elementSize: 4 * iUniqueAddresses, count: 1u, stream: v32);
    fseek(stream: v32, offset: 0, whence: 2);
  }
  else if ( pSortedAddressesa != *pDumpHelpers )
  {
    operator delete[](p: pSortedAddressesa);
  }
  v46 = 0;
  if ( iSubTreeCount == 0 )
    return 1;
  while ( _CCallStackStatsGatherer_Internal_DumpSubTree(StatsGatherer: &pSubTrees[v46], pDumpHelpers) )
  {
    if ( ++v46 == iSubTreeCount )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CE80
// Name: public: virtual unsigned int BasicStatStructFieldDesc::DescribeField(unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall BasicStatStructFieldDesc::DescribeField(
        BasicStatStructFieldDesc *this,
        unsigned __int8 *pDescribeWriteBuffer,
        unsigned int iDescribeMaxLength)
{
  unsigned int v3; // eax
  unsigned int v4; // edi

  v3 = strlen(this->m_szFieldName);
  v4 = v3 + 8;
  if ( iDescribeMaxLength < v3 + 8 )
    return 0;
  *pDescribeWriteBuffer = 0;
  pDescribeWriteBuffer[1] = this->m_Type;
  pDescribeWriteBuffer[2] = this->m_Combine;
  *(_DWORD *)(pDescribeWriteBuffer + 3) = this->m_iFieldOffset;
  memcpy(dst: pDescribeWriteBuffer + 7, src: (unsigned __int8 *)this->m_szFieldName, count: v3 + 1);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1000CD60
// Name: __CCallStackStatsGatherer_Write_FieldDescriptions
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _CCallStackStatsGatherer_Write_FieldDescriptions(
        CallStackStatStructDescFuncs *pFieldDescriptions,
        unsigned __int8 *pWriteBuffer,
        unsigned int iWriteBufferSize)
{
  CallStackStatStructDescFuncs *v4; // esi
  int v5; // edi
  int v6; // eax
  unsigned int iNumFields; // [esp+18h] [ebp+Ch]

  v4 = pFieldDescriptions;
  *(_DWORD *)pWriteBuffer = 2;
  v5 = 12;
  for ( iNumFields = 0; v4 != nullptr; v5 += v6 )
  {
    v6 = v4->DescribeField(this: v4, a2: &pWriteBuffer[v5], a3: iWriteBufferSize - v5);
    if ( v6 != 0 )
      ++iNumFields;
    v4 = v4->m_pNext;
  }
  *((_DWORD *)pWriteBuffer + 2) = iNumFields;
  *((_DWORD *)pWriteBuffer + 1) = v5 - 8;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000CDC0
// Name: __CCallStackStatsGatherer_Internal_DumpStatsToFile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl _CCallStackStatsGatherer_Internal_DumpStatsToFile(
        char *szFileName,
        unsigned int StatsGatherer,
        bool bAllowMemoryAllocations)
{
  const CCallStackStatsGatherer_Standardized_t *v3; // edi
  unsigned __int8 *v5; // esi
  char v6; // bl
  char buffer; // [esp+4h] [ebp-40014h] BYREF
  int v8; // [esp+5h] [ebp-40013h]
  unsigned __int8 *pDumpHelpers[4]; // [esp+40004h] [ebp-14h] BYREF
  bool v10; // [esp+40014h] [ebp-4h]

  v3 = (const CCallStackStatsGatherer_Standardized_t *)StatsGatherer;
  if ( *(_DWORD *)StatsGatherer == 0 )
    return 0;
  v5 = (unsigned __int8 *)fopen(file: szFileName, mode: "wb");
  if ( v5 == nullptr )
    return 0;
  buffer = 3;
  pDumpHelpers[0] = (unsigned __int8 *)&buffer;
  v8 = 305419896;
  StatsGatherer = 5;
  pDumpHelpers[1] = (unsigned __int8 *)0x40000;
  pDumpHelpers[2] = (unsigned __int8 *)&StatsGatherer;
  pDumpHelpers[3] = v5;
  v10 = bAllowMemoryAllocations;
  v6 = _CCallStackStatsGatherer_Internal_DumpSubTree(StatsGatherer: v3, pDumpHelpers);
  if ( StatsGatherer != 0 )
  {
    fwrite(&buffer, size: 1u, count: StatsGatherer, stream: (_iobuf *)v5);
    StatsGatherer = 0;
  }
  fclose(stream: (_iobuf *)v5);
  return v6;
}
