// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/dt_utlvector_recv.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100D05F0
// Name: void RecvProxy_UtlVectorLength(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_UtlVectorLength(const CRecvProxyData *pData, void *pStruct)
{
  (*((void (__cdecl **)(void *, _DWORD, int))pData->m_pRecvProp->m_pExtraData + 2))(
    a1: pStruct,
    a2: *((_DWORD *)pData->m_pRecvProp->m_pExtraData + 5),
    a3: pData->m_Value.m_Int);
}

//------------------------------------------------------------------------------
// Address: 0x100D0620
// Name: void DataTableRecvProxy_LengthProxy(class RecvProp const __near *,void __near * __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTableRecvProxy_LengthProxy(const RecvProp *pProp, void **pOut, void *pData)
{
  (*((void (__cdecl **)(void *, _DWORD, _DWORD))pProp->m_pExtraData + 3))(
    a1: pData,
    a2: *((_DWORD *)pProp->m_pExtraData + 5),
    a3: *((_DWORD *)pProp->m_pExtraData + 6));
  *pOut = pData;
}

//------------------------------------------------------------------------------
// Address: 0x100D0650
// Name: void RecvProxy_UtlVectorElement(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_UtlVectorElement(const CRecvProxyData *pData, char *pStruct, void *pOut)
{
  (*((void (__cdecl **)(const CRecvProxyData *, void *, int))pData->m_pRecvProp->m_pExtraData + 1))(
    a1: pData,
    a2: pOut,
    a3: *(_DWORD *)&pStruct[*((_DWORD *)pData->m_pRecvProp->m_pExtraData + 5)]
  + *((_DWORD *)pData->m_pRecvProp->m_pExtraData + 4) * pData->m_pRecvProp->m_ElementStride);
}

//------------------------------------------------------------------------------
// Address: 0x100D0680
// Name: void RecvProxy_UtlVectorElement_DataTable(class RecvProp const __near *,void __near * __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_UtlVectorElement_DataTable(const RecvProp *pProp, void **pOut, char *pData, int objectID)
{
  (*(void (__cdecl **)(const RecvProp *, void **, int, int))pProp->m_pExtraData)(
    a1: pProp,
    a2: pOut,
    a3: *(_DWORD *)&pData[*((_DWORD *)pProp->m_pExtraData + 5)]
  + *((_DWORD *)pProp->m_pExtraData + 4) * pProp->m_ElementStride,
    a4: objectID);
}

//------------------------------------------------------------------------------
// Address: 0x100D06B0
// Name: class RecvProp RecvPropUtlVector(char __near *,int,int,void (*)(void __near *,int,int),void (*)(void __near *,int,int),int,class RecvProp)
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropUtlVector(
        RecvProp *result,
        char *pVarName,
        int offset,
        RecvProp *sizeofVar,
        void (__cdecl *fn)(void *, int, int),
        void (__cdecl *ensureFn)(void *, int, int),
        int nMaxElements,
        RecvProp pArrayProp)
{
  RecvProp *v8; // eax
  RecvProp *v9; // ebx
  int v10; // edi
  RecvProp *i; // esi
  CRecvPropExtra_UtlVector *v12; // ebx
  RecvProp *v13; // eax
  char *StringHelper; // eax
  char *UniqueDataTableName; // esi
  RecvTable *v16; // eax
  RecvTable *v17; // eax
  RecvProp *v18; // esi
  RecvProp *v19; // eax
  int v20; // ebx
  _DWORD *p_m_pExtraData; // eax
  CRecvPropExtra_UtlVector *v22; // edx
  RecvTable *v23; // esi
  char *v24; // eax
  RecvProp v26; // [esp+Ch] [ebp-48h] BYREF
  CRecvPropExtra_UtlVector *pExtraData; // [esp+48h] [ebp-Ch]
  int nProps; // [esp+4Ch] [ebp-8h]
  RecvProp *pProps; // [esp+50h] [ebp-4h]
  RecvProp *pLengthProp; // [esp+68h] [ebp+14h]
  RecvProp *pLengthPropa; // [esp+68h] [ebp+14h]

  RecvProp::RecvProp(this: result);
  result->m_pVarName = pVarName;
  result->m_RecvType = DPT_DataTable;
  result->m_Offset = 0;
  result->m_DataTableProxyFn = (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable;
  nProps = nMaxElements + 1;
  v8 = (RecvProp *)MemAlloc_Alloc(nSize: (60 * (unsigned __int64)(unsigned int)(nMaxElements + 1)) >> 32 != 0 ? -1 : 60 * (nMaxElements + 1));
  v9 = v8;
  if ( v8 != nullptr )
  {
    v10 = nMaxElements;
    for ( i = v8; v10 >= 0; --v10 )
      RecvProp::RecvProp(this: i++);
    pProps = v9;
  }
  else
  {
    pProps = nullptr;
  }
  v12 = (CRecvPropExtra_UtlVector *)MemAlloc_Alloc(nSize: 0x1Cu);
  v12->m_ElementStride = (int)sizeofVar;
  v12->m_nMaxElements = nMaxElements;
  v12->m_ResizeFn = fn;
  v12->m_EnsureCapacityFn = ensureFn;
  v12->m_Offset = offset;
  pExtraData = v12;
  if ( pArrayProp.m_RecvType == DPT_DataTable )
    v12->m_DataTableProxyFn = pArrayProp.m_DataTableProxyFn;
  else
    v12->m_ProxyFn = pArrayProp.m_ProxyFn;
  v13 = (RecvProp *)MemAlloc_Alloc(nSize: 0x3Cu);
  if ( v13 != nullptr )
    pLengthProp = RecvProp::RecvProp(this: v13);
  else
    pLengthProp = nullptr;
  StringHelper = AllocateStringHelper(pFormat: "lengthprop%d", nMaxElements);
  qmemcpy(
    pLengthProp,
    RecvPropInt(
      result: &v26,
      pVarName: StringHelper,
      offset: 0,
      sizeofVar: 0,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))RecvProxy_UtlVectorLength),
    sizeof(RecvProp));
  pLengthProp->m_pExtraData = v12;
  UniqueDataTableName = AllocateUniqueDataTableName(bSendTable: false, pFormat: "_LPT_%s_%d", pVarName, nMaxElements);
  v16 = (RecvTable *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v16 != nullptr )
    v17 = RecvTable::RecvTable(this: v16, pProps: pLengthProp, nProps: 1, pNetTableName: UniqueDataTableName);
  else
    v17 = nullptr;
  v18 = RecvPropDataTable(
          result: &v26,
          pVarName: "lengthproxy",
          offset: 0,
          flags: 0,
          pTable: v17,
          varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_LengthProxy);
  v19 = pProps;
  *pProps = *v18;
  v19->m_pExtraData = v12;
  v20 = 1;
  if ( nProps > 1 )
  {
    p_m_pExtraData = &v19[1].m_pExtraData;
    pLengthPropa = (RecvProp *)s_ClientElementNames;
    do
    {
      v22 = pExtraData;
      *(RecvProp *)(p_m_pExtraData - 5) = pArrayProp;
      p_m_pExtraData[6] = 0;
      *(p_m_pExtraData - 5) = pLengthPropa->m_pVarName;
      *p_m_pExtraData = v22;
      p_m_pExtraData[7] = v20 - 1;
      if ( pArrayProp.m_RecvType == DPT_DataTable )
        p_m_pExtraData[4] = RecvProxy_UtlVectorElement_DataTable;
      else
        p_m_pExtraData[3] = RecvProxy_UtlVectorElement;
      pLengthPropa = (RecvProp *)((char *)pLengthPropa + 4);
      ++v20;
      p_m_pExtraData += 15;
    }
    while ( v20 < nProps );
  }
  v23 = (RecvTable *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v23 != nullptr )
  {
    v24 = AllocateUniqueDataTableName(bSendTable: false, pFormat: "_ST_%s_%d", pVarName, nMaxElements);
    result->m_pDataTable = RecvTable::RecvTable(this: v23, pProps, nProps, pNetTableName: v24);
  }
  else
  {
    result->m_pDataTable = nullptr;
  }
  return result;
}
