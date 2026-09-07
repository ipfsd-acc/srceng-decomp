// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/dt_utlvector_send.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10103140
// Name: void __near * SendProxy_LengthTable(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_LengthTable(const SendProp *pProp, const void *pStructBase, const void *pData)
{
  (*((void (__cdecl **)(const void *, _DWORD, _DWORD))pProp->m_pExtraData + 2))(
    a1: pStructBase,
    a2: *((_DWORD *)pProp->m_pExtraData + 4),
    a3: *((_DWORD *)pProp->m_pExtraData + 5));
  return (void *)pData;
}

//------------------------------------------------------------------------------
// Address: 0x10103170
// Name: void SendProxy_UtlVectorLength(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_UtlVectorLength(const SendProp *pProp, char *pStruct, const void *pData, DVariant *pOut)
{
  _DWORD *m_pExtraData; // eax
  int v5; // ecx
  int v6; // eax

  m_pExtraData = pProp->m_pExtraData;
  v5 = *(_DWORD *)&pStruct[m_pExtraData[4] + 12];
  pOut->m_Int = v5;
  v6 = m_pExtraData[5];
  if ( v5 > v6 )
    pOut->m_Int = v6;
}

//------------------------------------------------------------------------------
// Address: 0x101031A0
// Name: void SendProxy_UtlVectorElement(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_UtlVectorElement(
        const SendProp *pProp,
        char *pStruct,
        const void *pData,
        DVariant *pOut,
        int iElement,
        int objectID)
{
  _DWORD *m_pExtraData; // ecx
  char *v7; // eax
  int m_ElementStride; // esi

  m_pExtraData = pProp->m_pExtraData;
  v7 = &pStruct[m_pExtraData[4]];
  m_ElementStride = pProp->m_ElementStride;
  if ( m_ElementStride < *((_DWORD *)v7 + 3) )
  {
    ((void (__cdecl *)(const SendProp *, const void *, int, DVariant *, _DWORD, int))m_pExtraData[1])(
      a1: pProp,
      a2: pData,
      a3: *(_DWORD *)v7 + m_ElementStride * m_pExtraData[3],
      a4: pOut,
      a5: 0,
      a6: objectID);
  }
  else
  {
    pOut->m_Int64 = 0;
    *(&pOut->m_Int64 + 1) = 0;
    *(_QWORD *)&pOut->m_Type = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103200
// Name: void __near * SendProxy_UtlVectorElement_DataTable(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_UtlVectorElement_DataTable(
        const SendProp *pProp,
        char *pStructBase,
        const void *pData,
        CSendProxyRecipients *pRecipients,
        int objectID)
{
  return (*(void *(__cdecl **)(const SendProp *, const void *, int, CSendProxyRecipients *, int))pProp->m_pExtraData)(
           a1: pProp,
           a2: pData,
           a3: *(_DWORD *)&pStructBase[*((_DWORD *)pProp->m_pExtraData + 4)]
         + pProp->m_ElementStride * *((_DWORD *)pProp->m_pExtraData + 3),
           a4: pRecipients,
           a5: objectID);
}

//------------------------------------------------------------------------------
// Address: 0x10103240
// Name: class SendProp SendPropUtlVector(char __near *,int,int,void (*)(void __near *,int,int),int,class SendProp,void __near * (*)(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int))
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropUtlVector(
        SendProp *result,
        char *pVarName,
        void *(__cdecl *offset)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int),
        char *sizeofVar,
        void (__cdecl *ensureFn)(void *, int, int),
        void *(__cdecl *nMaxElements)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int),
        SendProp pArrayProp,
        SendProp *varProxy)
{
  void *(__cdecl *v8)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // eax
  void *(__cdecl **v9)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // edi
  void *(__cdecl **v10)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // eax
  int v11; // ebx
  int v12; // ecx
  _DWORD *v13; // eax
  void *(__cdecl *v14)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // eax
  SendProp *v15; // esi
  SendProp *v16; // eax
  SendProp *v17; // esi
  int v18; // eax
  int i; // ecx
  char *StringHelper; // eax
  const SendProp *v21; // eax
  SendTable *v22; // eax
  SendTable *v23; // eax
  const SendProp *v24; // eax
  SendProp *v25; // esi
  int v26; // ecx
  int v27; // ebx
  int v28; // esi
  SendPropType *p_m_Type; // eax
  int *v30; // esi
  SendPropType *v31; // eax
  SendTable *v32; // esi
  char *UniqueDataTableName; // eax
  SendTable *v34; // eax
  int v36; // [esp-10h] [ebp-70h]
  SendProp v37; // [esp+Ch] [ebp-54h] BYREF
  char *pLengthProxyTableName; // [esp+74h] [ebp+14h]

  SendProp::SendProp(this: result);
  result->m_pVarName = pVarName;
  v8 = (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))varProxy;
  v9 = nullptr;
  result->m_Type = DPT_DataTable;
  result->m_Offset = 0;
  result->m_DataTableProxyFn = v8;
  if ( (char *)v8 == (char *)SendProxy_DataTableToDataTable || (char *)v8 == (char *)SendProxy_DataTablePtrToDataTable )
    result->m_Flags = 512;
  v10 = (void *(__cdecl **)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))operator new(nSize: 0x18u);
  if ( v10 != nullptr )
  {
    *v10 = nullptr;
    v10[1] = nullptr;
    v10[2] = nullptr;
    v10[3] = nullptr;
    v10[4] = nullptr;
    v10[5] = nullptr;
    v9 = v10;
  }
  v11 = (int)nMaxElements;
  v9[5] = nMaxElements;
  v9[3] = (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))sizeofVar;
  v9[2] = (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))ensureFn;
  v9[4] = offset;
  if ( pArrayProp.m_Type == DPT_DataTable )
    *v9 = pArrayProp.m_DataTableProxyFn;
  else
    v9[1] = (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))pArrayProp.m_ProxyFn;
  v12 = (84 * (unsigned __int64)((unsigned int)nMaxElements + 1)) >> 32 != 0 ? -1 : 84 * ((_DWORD)nMaxElements + 1);
  v13 = operator new(nSize: __CFADD__(v12, 4) ? -1 : v12 + 4);
  if ( v13 != nullptr )
  {
    *v13 = (char *)nMaxElements + 1;
    v14 = (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))(v13 + 1);
    varProxy = (SendProp *)v14;
    v15 = (SendProp *)v14;
    if ( (int)nMaxElements >= 0 )
    {
      do
      {
        SendProp::SendProp(this: v15++);
        --v11;
      }
      while ( v11 >= 0 );
      v14 = (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))varProxy;
    }
    v11 = (int)nMaxElements;
    varProxy = (SendProp *)v14;
  }
  else
  {
    varProxy = nullptr;
  }
  v16 = (SendProp *)operator new(nSize: 0x54u);
  if ( v16 != nullptr )
    v17 = SendProp::SendProp(this: v16);
  else
    v17 = nullptr;
  v18 = 0;
  for ( i = v11; i > 0; ++v18 )
    i >>= 1;
  v36 = v18;
  StringHelper = AllocateStringHelper(pFormat: "lengthprop%d", v11);
  v21 = SendPropInt(
          result: &v37,
          pVarName: StringHelper,
          offset: 0,
          sizeofVar: 0,
          nBits: v36,
          flags: 1,
          varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_UtlVectorLength,
          priority: 0x80u);
  SendProp::operator=(this: v17, __that: v21);
  SendProp::~SendProp(this: &v37);
  v17->m_pExtraData = v9;
  pLengthProxyTableName = AllocateUniqueDataTableName(bSendTable: true, pFormat: "_LPT_%s_%d", pVarName, v11);
  v22 = (SendTable *)operator new(nSize: 0x14u);
  if ( v22 != nullptr )
    v23 = SendTable::SendTable(this: v22, pProps: v17, nProps: 1, pNetTableName: pLengthProxyTableName);
  else
    v23 = nullptr;
  v24 = SendPropDataTable(
          result: &v37,
          pVarName: "lengthproxy",
          offset: 0,
          pTable: v23,
          varProxy: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_LengthTable,
          priority: 0x80u);
  v25 = varProxy;
  SendProp::operator=(this: varProxy, __that: v24);
  SendProp::~SendProp(this: &v37);
  v26 = 1;
  v27 = v11 + 1;
  v25->m_pExtraData = v9;
  if ( v27 > 1 )
  {
    if ( v27 - 1 >= 4 )
    {
      v28 = 2;
      p_m_Type = &varProxy[2].m_Type;
      do
      {
        *(p_m_Type - 22) = (SendPropType)pArrayProp.m_pMatchingRecvProp;
        *(p_m_Type - 21) = pArrayProp.m_Type;
        *(p_m_Type - 20) = (SendPropType)pArrayProp.m_nBits;
        *(p_m_Type - 19) = SLODWORD(pArrayProp.m_fLowValue);
        *(p_m_Type - 18) = SLODWORD(pArrayProp.m_fHighValue);
        *(p_m_Type - 17) = (SendPropType)pArrayProp.m_pArrayProp;
        *(p_m_Type - 16) = (SendPropType)pArrayProp.m_ArrayLengthProxy;
        *(p_m_Type - 15) = (SendPropType)pArrayProp.m_nElements;
        *(p_m_Type - 14) = (SendPropType)pArrayProp.m_ElementStride;
        *(p_m_Type - 13) = (SendPropType)pArrayProp.m_pExcludeDTName;
        *(p_m_Type - 12) = (SendPropType)pArrayProp.m_pParentArrayPropName;
        *(p_m_Type - 11) = (SendPropType)pArrayProp.m_pVarName;
        *(p_m_Type - 10) = SLODWORD(pArrayProp.m_fHighLowMul);
        *((_BYTE *)p_m_Type - 36) = pArrayProp.m_priority;
        *(p_m_Type - 8) = (SendPropType)pArrayProp.m_Flags;
        *(p_m_Type - 7) = (SendPropType)pArrayProp.m_ProxyFn;
        *(p_m_Type - 6) = (SendPropType)pArrayProp.m_DataTableProxyFn;
        *(p_m_Type - 5) = (SendPropType)pArrayProp.m_pDataTable;
        *(p_m_Type - 4) = (SendPropType)pArrayProp.m_Offset;
        *(p_m_Type - 3) = (SendPropType)pArrayProp.m_pExtraData;
        *((_DWORD *)p_m_Type - 4) = 0;
        *(p_m_Type - 11) = (SendPropType)dataDesc_125[41].flatOffset[v26 + 2];
        *((_DWORD *)p_m_Type - 3) = v9;
        *((_DWORD *)p_m_Type - 14) = v28 - 2;
        if ( pArrayProp.m_Type == DPT_DataTable )
        {
          *((_DWORD *)p_m_Type - 6) = SendProxy_UtlVectorElement_DataTable;
          *((_DWORD *)p_m_Type - 8) = 512;
        }
        else
        {
          *((_DWORD *)p_m_Type - 7) = SendProxy_UtlVectorElement;
        }
        *(p_m_Type - 1) = (SendPropType)pArrayProp.m_pMatchingRecvProp;
        *p_m_Type = pArrayProp.m_Type;
        p_m_Type[1] = (SendPropType)pArrayProp.m_nBits;
        p_m_Type[2] = SLODWORD(pArrayProp.m_fLowValue);
        p_m_Type[3] = SLODWORD(pArrayProp.m_fHighValue);
        p_m_Type[4] = (SendPropType)pArrayProp.m_pArrayProp;
        p_m_Type[5] = (SendPropType)pArrayProp.m_ArrayLengthProxy;
        p_m_Type[6] = (SendPropType)pArrayProp.m_nElements;
        p_m_Type[7] = (SendPropType)pArrayProp.m_ElementStride;
        p_m_Type[8] = (SendPropType)pArrayProp.m_pExcludeDTName;
        p_m_Type[9] = (SendPropType)pArrayProp.m_pParentArrayPropName;
        p_m_Type[10] = (SendPropType)pArrayProp.m_pVarName;
        p_m_Type[11] = SLODWORD(pArrayProp.m_fHighLowMul);
        *((_BYTE *)p_m_Type + 48) = pArrayProp.m_priority;
        p_m_Type[13] = (SendPropType)pArrayProp.m_Flags;
        p_m_Type[14] = (SendPropType)pArrayProp.m_ProxyFn;
        p_m_Type[15] = (SendPropType)pArrayProp.m_DataTableProxyFn;
        p_m_Type[16] = (SendPropType)pArrayProp.m_pDataTable;
        p_m_Type[17] = (SendPropType)pArrayProp.m_Offset;
        p_m_Type[18] = (SendPropType)pArrayProp.m_pExtraData;
        *((_DWORD *)p_m_Type + 17) = 0;
        *((_DWORD *)p_m_Type + 10) = s_ElementNames[v26];
        *((_DWORD *)p_m_Type + 18) = v9;
        *((_DWORD *)p_m_Type + 7) = v26;
        if ( pArrayProp.m_Type == DPT_DataTable )
        {
          *((_DWORD *)p_m_Type + 15) = SendProxy_UtlVectorElement_DataTable;
          *((_DWORD *)p_m_Type + 13) = 512;
        }
        else
        {
          *((_DWORD *)p_m_Type + 14) = SendProxy_UtlVectorElement;
        }
        p_m_Type[20] = (SendPropType)pArrayProp.m_pMatchingRecvProp;
        p_m_Type[21] = pArrayProp.m_Type;
        p_m_Type[22] = (SendPropType)pArrayProp.m_nBits;
        p_m_Type[23] = SLODWORD(pArrayProp.m_fLowValue);
        p_m_Type[24] = SLODWORD(pArrayProp.m_fHighValue);
        p_m_Type[25] = (SendPropType)pArrayProp.m_pArrayProp;
        p_m_Type[26] = (SendPropType)pArrayProp.m_ArrayLengthProxy;
        p_m_Type[27] = (SendPropType)pArrayProp.m_nElements;
        p_m_Type[28] = (SendPropType)pArrayProp.m_ElementStride;
        p_m_Type[29] = (SendPropType)pArrayProp.m_pExcludeDTName;
        p_m_Type[30] = (SendPropType)pArrayProp.m_pParentArrayPropName;
        p_m_Type[31] = (SendPropType)pArrayProp.m_pVarName;
        p_m_Type[32] = SLODWORD(pArrayProp.m_fHighLowMul);
        *((_BYTE *)p_m_Type + 132) = pArrayProp.m_priority;
        p_m_Type[34] = (SendPropType)pArrayProp.m_Flags;
        p_m_Type[35] = (SendPropType)pArrayProp.m_ProxyFn;
        p_m_Type[36] = (SendPropType)pArrayProp.m_DataTableProxyFn;
        p_m_Type[37] = (SendPropType)pArrayProp.m_pDataTable;
        p_m_Type[38] = (SendPropType)pArrayProp.m_Offset;
        p_m_Type[39] = (SendPropType)pArrayProp.m_pExtraData;
        *((_DWORD *)p_m_Type + 38) = 0;
        *((_DWORD *)p_m_Type + 31) = off_1057C07C[v26];
        *((_DWORD *)p_m_Type + 39) = v9;
        *((_DWORD *)p_m_Type + 28) = v28;
        if ( pArrayProp.m_Type == DPT_DataTable )
        {
          *((_DWORD *)p_m_Type + 36) = SendProxy_UtlVectorElement_DataTable;
          *((_DWORD *)p_m_Type + 34) = 512;
        }
        else
        {
          *((_DWORD *)p_m_Type + 35) = SendProxy_UtlVectorElement;
        }
        p_m_Type[41] = (SendPropType)pArrayProp.m_pMatchingRecvProp;
        p_m_Type[42] = pArrayProp.m_Type;
        p_m_Type[43] = (SendPropType)pArrayProp.m_nBits;
        p_m_Type[44] = SLODWORD(pArrayProp.m_fLowValue);
        p_m_Type[45] = SLODWORD(pArrayProp.m_fHighValue);
        p_m_Type[46] = (SendPropType)pArrayProp.m_pArrayProp;
        p_m_Type[47] = (SendPropType)pArrayProp.m_ArrayLengthProxy;
        p_m_Type[48] = (SendPropType)pArrayProp.m_nElements;
        p_m_Type[49] = (SendPropType)pArrayProp.m_ElementStride;
        p_m_Type[50] = (SendPropType)pArrayProp.m_pExcludeDTName;
        p_m_Type[51] = (SendPropType)pArrayProp.m_pParentArrayPropName;
        p_m_Type[52] = (SendPropType)pArrayProp.m_pVarName;
        p_m_Type[53] = SLODWORD(pArrayProp.m_fHighLowMul);
        *((_BYTE *)p_m_Type + 216) = pArrayProp.m_priority;
        p_m_Type[55] = (SendPropType)pArrayProp.m_Flags;
        p_m_Type[56] = (SendPropType)pArrayProp.m_ProxyFn;
        p_m_Type[57] = (SendPropType)pArrayProp.m_DataTableProxyFn;
        p_m_Type[58] = (SendPropType)pArrayProp.m_pDataTable;
        p_m_Type[59] = (SendPropType)pArrayProp.m_Offset;
        p_m_Type[60] = (SendPropType)pArrayProp.m_pExtraData;
        *((_DWORD *)p_m_Type + 59) = 0;
        *((_DWORD *)p_m_Type + 52) = off_1057C080[v26];
        *((_DWORD *)p_m_Type + 60) = v9;
        *((_DWORD *)p_m_Type + 49) = v28 + 1;
        if ( pArrayProp.m_Type == DPT_DataTable )
        {
          *((_DWORD *)p_m_Type + 57) = SendProxy_UtlVectorElement_DataTable;
          *((_DWORD *)p_m_Type + 55) = 512;
        }
        else
        {
          *((_DWORD *)p_m_Type + 56) = SendProxy_UtlVectorElement;
        }
        v26 += 4;
        v28 += 4;
        p_m_Type += 84;
      }
      while ( v26 < v27 - 3 );
    }
    v27 = (int)nMaxElements + 1;
    if ( v26 < (int)nMaxElements + 1 )
    {
      v30 = &dataDesc_125[41].flatOffset[v26 + 2];
      v31 = &varProxy[v26].m_Type;
      do
      {
        *(v31 - 1) = (SendPropType)pArrayProp.m_pMatchingRecvProp;
        *v31 = pArrayProp.m_Type;
        v31[1] = (SendPropType)pArrayProp.m_nBits;
        v31[2] = SLODWORD(pArrayProp.m_fLowValue);
        v31[3] = SLODWORD(pArrayProp.m_fHighValue);
        v31[4] = (SendPropType)pArrayProp.m_pArrayProp;
        v31[5] = (SendPropType)pArrayProp.m_ArrayLengthProxy;
        v31[6] = (SendPropType)pArrayProp.m_nElements;
        v31[7] = (SendPropType)pArrayProp.m_ElementStride;
        v31[8] = (SendPropType)pArrayProp.m_pExcludeDTName;
        v31[9] = (SendPropType)pArrayProp.m_pParentArrayPropName;
        v31[10] = (SendPropType)pArrayProp.m_pVarName;
        v31[11] = SLODWORD(pArrayProp.m_fHighLowMul);
        *((_BYTE *)v31 + 48) = pArrayProp.m_priority;
        v31[13] = (SendPropType)pArrayProp.m_Flags;
        v31[14] = (SendPropType)pArrayProp.m_ProxyFn;
        v31[15] = (SendPropType)pArrayProp.m_DataTableProxyFn;
        v31[16] = (SendPropType)pArrayProp.m_pDataTable;
        v31[17] = (SendPropType)pArrayProp.m_Offset;
        v31[18] = (SendPropType)pArrayProp.m_pExtraData;
        *((_DWORD *)v31 + 17) = 0;
        *((_DWORD *)v31 + 10) = *v30;
        *((_DWORD *)v31 + 18) = v9;
        *((_DWORD *)v31 + 7) = v26 - 1;
        if ( pArrayProp.m_Type == DPT_DataTable )
        {
          *((_DWORD *)v31 + 15) = SendProxy_UtlVectorElement_DataTable;
          *((_DWORD *)v31 + 13) = 512;
        }
        else
        {
          *((_DWORD *)v31 + 14) = SendProxy_UtlVectorElement;
        }
        ++v26;
        ++v30;
        v31 += 21;
      }
      while ( v26 < v27 );
    }
  }
  v32 = (SendTable *)operator new(nSize: 0x14u);
  if ( v32 != nullptr )
  {
    UniqueDataTableName = AllocateUniqueDataTableName(bSendTable: true, pFormat: "_ST_%s_%d", pVarName, nMaxElements);
    v34 = SendTable::SendTable(this: v32, pProps: varProxy, nProps: v27, pNetTableName: UniqueDataTableName);
  }
  else
  {
    v34 = nullptr;
  }
  result->m_pDataTable = v34;
  SendProp::~SendProp(this: &pArrayProp);
  return result;
}
