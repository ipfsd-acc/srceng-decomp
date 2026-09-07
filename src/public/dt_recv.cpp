// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/dt_recv.cpp
// Functions: 8
// ============================================================

#include "public\dt_recv.h"

//------------------------------------------------------------------------------
// Address: 0x10170280
// Name: public: RecvProp::RecvProp(void)
// Source: json
//------------------------------------------------------------------------------
RecvProp *__thiscall RecvProp::RecvProp(RecvProp *this)
{
  this->m_pExtraData = nullptr;
  this->m_pVarName = nullptr;
  this->m_Offset = 0;
  this->m_RecvType = DPT_Int;
  this->m_Flags = 0;
  this->m_ProxyFn = nullptr;
  this->m_DataTableProxyFn = nullptr;
  this->m_pDataTable = nullptr;
  this->m_nElements = 1;
  this->m_ElementStride = -1;
  this->m_pArrayProp = nullptr;
  this->m_ArrayLengthProxy = nullptr;
  this->m_bInsideArray = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101702C0
// Name: void RecvProxy_FloatToFloat(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_FloatToFloat(const CRecvProxyData *pData, void *pStruct, float *pOut)
{
  *pOut = pData->m_Value.m_Float;
}

//------------------------------------------------------------------------------
// Address: 0x101702D0
// Name: void RecvProxy_VectorToVector(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_VectorToVector(
        const CRecvProxyData *pData,
        void *pStruct,
        $5FB8512C96CD1B8867E59BA5A9F6C5D6 *pOut)
{
  *pOut = pData->m_Value.___u0;
}

//------------------------------------------------------------------------------
// Address: 0x101702F0
// Name: void RecvProxy_Int32ToInt8(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int32ToInt8(const CRecvProxyData *pData, void *pStruct, _BYTE *pOut)
{
  *pOut = LOBYTE(pData->m_Value.m_Float);
}

//------------------------------------------------------------------------------
// Address: 0x10170300
// Name: void RecvProxy_Int32ToInt16(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int32ToInt16(const CRecvProxyData *pData, void *pStruct, _WORD *pOut)
{
  *pOut = LOWORD(pData->m_Value.m_Float);
}

//------------------------------------------------------------------------------
// Address: 0x10170320
// Name: void RecvProxy_Int32ToInt32(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int32ToInt32(const CRecvProxyData *pData, void *pStruct, int *pOut)
{
  *pOut = pData->m_Value.m_Int;
}

//------------------------------------------------------------------------------
// Address: 0x10170330
// Name: void RecvProxy_Int64ToInt64(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int64ToInt64(const CRecvProxyData *pData, void *pStruct, __int64 *pOut)
{
  *pOut = pData->m_Value.m_Int64;
}

//------------------------------------------------------------------------------
// Address: 0x10170350
// Name: public: RecvTable::RecvTable(class RecvProp __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
RecvTable *__thiscall RecvTable::RecvTable(RecvTable *this, RecvProp *pProps, int nProps, char *pNetTableName)
{
  this->m_pProps = pProps;
  this->m_nProps = nProps;
  this->m_pDecoder = nullptr;
  this->m_pNetTableName = pNetTableName;
  *(_WORD *)&this->m_bInitialized = 0;
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10170430
// Name: public: RecvProp::RecvProp(void)
// Source: json
//------------------------------------------------------------------------------
RecvProp *__thiscall RecvProp::RecvProp(RecvProp *this)
{
  this->m_pExtraData = nullptr;
  this->m_pVarName = nullptr;
  this->m_Offset = 0;
  this->m_RecvType = DPT_Int;
  this->m_Flags = 0;
  this->m_ProxyFn = nullptr;
  this->m_DataTableProxyFn = nullptr;
  this->m_pDataTable = nullptr;
  this->m_nElements = 1;
  this->m_ElementStride = -1;
  this->m_pArrayProp = nullptr;
  this->m_ArrayLengthProxy = nullptr;
  this->m_bInsideArray = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10170470
// Name: void RecvProxy_FloatToFloat(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_FloatToFloat(const CRecvProxyData *pData, void *pStruct, float *pOut)
{
  *pOut = pData->m_Value.m_Float;
}

//------------------------------------------------------------------------------
// Address: 0x10170480
// Name: void RecvProxy_VectorToVector(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_VectorToVector(
        const CRecvProxyData *pData,
        void *pStruct,
        $5FB8512C96CD1B8867E59BA5A9F6C5D6 *pOut)
{
  *pOut = pData->m_Value.___u0;
}

//------------------------------------------------------------------------------
// Address: 0x101704A0
// Name: void RecvProxy_Int32ToInt8(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int32ToInt8(const CRecvProxyData *pData, void *pStruct, _BYTE *pOut)
{
  *pOut = LOBYTE(pData->m_Value.m_Float);
}

//------------------------------------------------------------------------------
// Address: 0x101704B0
// Name: void RecvProxy_Int32ToInt16(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int32ToInt16(const CRecvProxyData *pData, void *pStruct, _WORD *pOut)
{
  *pOut = LOWORD(pData->m_Value.m_Float);
}

//------------------------------------------------------------------------------
// Address: 0x101704D0
// Name: void RecvProxy_Int32ToInt32(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int32ToInt32(const CRecvProxyData *pData, void *pStruct, int *pOut)
{
  *pOut = pData->m_Value.m_Int;
}

//------------------------------------------------------------------------------
// Address: 0x101704E0
// Name: void RecvProxy_Int64ToInt64(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int64ToInt64(const CRecvProxyData *pData, void *pStruct, __int64 *pOut)
{
  *pOut = pData->m_Value.m_Int64;
}

//------------------------------------------------------------------------------
// Address: 0x10170500
// Name: public: RecvTable::RecvTable(class RecvProp __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
RecvTable *__thiscall RecvTable::RecvTable(RecvTable *this, RecvProp *pProps, int nProps, char *pNetTableName)
{
  this->m_pProps = pProps;
  this->m_nProps = nProps;
  this->m_pDecoder = nullptr;
  this->m_pNetTableName = pNetTableName;
  *(_WORD *)&this->m_bInitialized = 0;
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x100618D0
// Name: void RecvProxy_VectorToVector(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_VectorToVector(
        const CRecvProxyData *pData,
        void *pStruct,
        $5FB8512C96CD1B8867E59BA5A9F6C5D6 *pOut)
{
  *pOut = pData->m_Value.___u0;
}

//------------------------------------------------------------------------------
// Address: 0x100CFFF0
// Name: public: RecvProp::RecvProp(void)
// Source: json
//------------------------------------------------------------------------------
RecvProp *__thiscall RecvProp::RecvProp(RecvProp *this)
{
  this->m_pExtraData = nullptr;
  this->m_pVarName = nullptr;
  this->m_Offset = 0;
  this->m_RecvType = DPT_Int;
  this->m_Flags = 0;
  this->m_ProxyFn = nullptr;
  this->m_DataTableProxyFn = nullptr;
  this->m_pDataTable = nullptr;
  this->m_nElements = 1;
  this->m_ElementStride = -1;
  this->m_pArrayProp = nullptr;
  this->m_ArrayLengthProxy = nullptr;
  this->m_bInsideArray = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D0030
// Name: public: void RecvTable::Construct(class RecvProp __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RecvTable::Construct(RecvTable *this, RecvProp *pProps, int nProps, char *pNetTableName)
{
  this->m_pProps = pProps;
  this->m_nProps = nProps;
  this->m_pDecoder = nullptr;
  this->m_pNetTableName = pNetTableName;
  *(_WORD *)&this->m_bInitialized = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D0060
// Name: class RecvProp RecvPropFloat(char __near *,int,int,int,void (*)(class CRecvProxyData const __near *,void __near *,void __near *))
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropFloat(
        RecvProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int flags,
        void (__cdecl *varProxy)(const CRecvProxyData *, void *, void *))
{
  result->m_pExtraData = nullptr;
  result->m_DataTableProxyFn = nullptr;
  result->m_pDataTable = nullptr;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_bInsideArray = false;
  result->m_pVarName = pVarName;
  result->m_nElements = 1;
  result->m_Offset = offset;
  result->m_RecvType = DPT_Float;
  result->m_ElementStride = -1;
  result->m_Flags = flags;
  result->m_ProxyFn = varProxy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D00B0
// Name: class RecvProp RecvPropVector(char __near *,int,int,int,void (*)(class CRecvProxyData const __near *,void __near *,void __near *))
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropVector(
        RecvProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int flags,
        void (__cdecl *varProxy)(const CRecvProxyData *, void *, void *))
{
  result->m_pExtraData = nullptr;
  result->m_DataTableProxyFn = nullptr;
  result->m_pDataTable = nullptr;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_bInsideArray = false;
  result->m_pVarName = pVarName;
  result->m_Offset = offset;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_RecvType = DPT_Vector;
  result->m_Flags = flags;
  result->m_ProxyFn = varProxy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D0100
// Name: class RecvProp RecvPropVectorXY(char __near *,int,int,int,void (*)(class CRecvProxyData const __near *,void __near *,void __near *))
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropVectorXY(
        RecvProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int flags,
        void (__cdecl *varProxy)(const CRecvProxyData *, void *, void *))
{
  result->m_pExtraData = nullptr;
  result->m_DataTableProxyFn = nullptr;
  result->m_pDataTable = nullptr;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_bInsideArray = false;
  result->m_pVarName = pVarName;
  result->m_Offset = offset;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_RecvType = DPT_VectorXY;
  result->m_Flags = flags;
  result->m_ProxyFn = varProxy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D0150
// Name: class RecvProp RecvPropString(char __near *,int,int,int,void (*)(class CRecvProxyData const __near *,void __near *,void __near *))
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropString(
        RecvProp *result,
        char *pVarName,
        int offset,
        int bufferSize,
        int flags,
        void (__cdecl *varProxy)(const CRecvProxyData *, void *, void *))
{
  result->m_pExtraData = nullptr;
  result->m_DataTableProxyFn = nullptr;
  result->m_pDataTable = nullptr;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_bInsideArray = false;
  result->m_pVarName = pVarName;
  result->m_Offset = offset;
  result->m_Flags = flags;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_RecvType = DPT_String;
  result->m_StringBufferSize = bufferSize;
  result->m_ProxyFn = varProxy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D01A0
// Name: class RecvProp RecvPropDataTable(char __near *,int,int,class RecvTable __near *,void (*)(class RecvProp const __near *,void __near * __near *,void __near *,int))
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropDataTable(
        RecvProp *result,
        char *pVarName,
        int offset,
        int flags,
        RecvTable *pTable,
        void (__cdecl *varProxy)(const RecvProp *, void **, void *, int))
{
  result->m_pExtraData = nullptr;
  result->m_ProxyFn = nullptr;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_bInsideArray = false;
  result->m_pVarName = pVarName;
  result->m_Offset = offset;
  result->m_Flags = flags;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_RecvType = DPT_DataTable;
  result->m_DataTableProxyFn = varProxy;
  result->m_pDataTable = pTable;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D01F0
// Name: class RecvProp InternalRecvPropArray(int,int,char __near *,void (*)(void __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl InternalRecvPropArray(
        RecvProp *result,
        int elementCount,
        int elementStride,
        char *pName,
        void (__cdecl *proxy)(void *, int, int))
{
  result->m_pExtraData = nullptr;
  result->m_Offset = 0;
  result->m_Flags = 0;
  result->m_ProxyFn = nullptr;
  result->m_DataTableProxyFn = nullptr;
  result->m_pDataTable = nullptr;
  result->m_pArrayProp = nullptr;
  result->m_bInsideArray = false;
  result->m_nElements = elementCount;
  result->m_ElementStride = elementStride;
  result->m_RecvType = DPT_Array;
  result->m_pVarName = pName;
  result->m_ArrayLengthProxy = proxy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D0240
// Name: void RecvProxy_Int32ToInt8(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int32ToInt8(const CRecvProxyData *pData, void *pStruct, _BYTE *pOut)
{
  *pOut = LOBYTE(pData->m_Value.m_Float);
}

//------------------------------------------------------------------------------
// Address: 0x100D0250
// Name: void RecvProxy_Int32ToInt16(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int32ToInt16(const CRecvProxyData *pData, void *pStruct, _WORD *pOut)
{
  *pOut = LOWORD(pData->m_Value.m_Float);
}

//------------------------------------------------------------------------------
// Address: 0x100D0270
// Name: void RecvProxy_Int32ToInt32(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int32ToInt32(const CRecvProxyData *pData, void *pStruct, int *pOut)
{
  *pOut = pData->m_Value.m_Int;
}

//------------------------------------------------------------------------------
// Address: 0x100D0280
// Name: void RecvProxy_Int64ToInt64(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Int64ToInt64(const CRecvProxyData *pData, void *pStruct, __int64 *pOut)
{
  *pOut = pData->m_Value.m_Int64;
}

//------------------------------------------------------------------------------
// Address: 0x100D02A0
// Name: void RecvProxy_StringToString(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_StringToString(const CRecvProxyData *pData, void *pStruct, _BYTE *pOut)
{
  int v3; // eax
  char v4; // cl

  if ( pData->m_pRecvProp->m_StringBufferSize > 0 )
  {
    v3 = 0;
    do
    {
      v4 = *(_BYTE *)(v3 + pData->m_Value.m_Int);
      pOut[v3] = v4;
      if ( v4 == 0 )
        break;
      ++v3;
    }
    while ( v3 < pData->m_pRecvProp->m_StringBufferSize );
    pOut[pData->m_pRecvProp->m_StringBufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D02F0
// Name: void DataTableRecvProxy_StaticDataTable(class RecvProp const __near *,void __near * __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTableRecvProxy_StaticDataTable(const RecvProp *pProp, void **pOut, void *pData)
{
  *pOut = pData;
}

//------------------------------------------------------------------------------
// Address: 0x100D0300
// Name: public: RecvTable::RecvTable(void)
// Source: json
//------------------------------------------------------------------------------
RecvTable *__thiscall RecvTable::RecvTable(RecvTable *this)
{
  this->m_pProps = nullptr;
  this->m_nProps = 0;
  this->m_pDecoder = nullptr;
  this->m_pNetTableName = nullptr;
  *(_WORD *)&this->m_bInitialized = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D0320
// Name: public: RecvTable::RecvTable(class RecvProp __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
RecvTable *__thiscall RecvTable::RecvTable(RecvTable *this, RecvProp *pProps, int nProps, char *pNetTableName)
{
  this->m_pProps = pProps;
  this->m_nProps = nProps;
  this->m_pDecoder = nullptr;
  this->m_pNetTableName = pNetTableName;
  *(_WORD *)&this->m_bInitialized = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D0350
// Name: class RecvProp RecvPropInt(char __near *,int,int,int,void (*)(class CRecvProxyData const __near *,void __near *,void __near *))
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropInt(
        RecvProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int flags,
        void (__cdecl *varProxy)(const CRecvProxyData *, void *, void *))
{
  RecvProp *v6; // eax
  void (__cdecl *v7)(const CRecvProxyData *, void *, void *); // edx

  v6 = result;
  v7 = varProxy;
  result->m_pExtraData = nullptr;
  result->m_pVarName = nullptr;
  result->m_Offset = 0;
  result->m_RecvType = DPT_Int;
  result->m_Flags = 0;
  result->m_ProxyFn = nullptr;
  result->m_DataTableProxyFn = nullptr;
  result->m_pDataTable = nullptr;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_bInsideArray = false;
  if ( varProxy == nullptr )
  {
    if ( sizeofVar != 1 )
    {
      if ( sizeofVar == 2 )
      {
        v7 = (void (__cdecl *)(const CRecvProxyData *, void *, void *))RecvProxy_Int32ToInt16;
        goto LABEL_9;
      }
      if ( sizeofVar == 4 )
      {
        v7 = (void (__cdecl *)(const CRecvProxyData *, void *, void *))RecvProxy_Int32ToInt32;
        goto LABEL_9;
      }
      v7 = (void (__cdecl *)(const CRecvProxyData *, void *, void *))RecvProxy_Int64ToInt64;
      if ( sizeofVar == 8 )
        goto LABEL_9;
    }
    v7 = (void (__cdecl *)(const CRecvProxyData *, void *, void *))RecvProxy_Int32ToInt8;
  }
LABEL_9:
  result->m_pVarName = pVarName;
  result->m_Offset = offset;
  result->m_ProxyFn = v7;
  result->m_RecvType = sizeofVar != 8 ? DPT_Int : DPT_Int64;
  result->m_Flags = flags;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100D03F0
// Name: class RecvProp RecvPropArray3(char __near *,int,int,int,class RecvProp,void (*)(class RecvProp const __near *,void __near * __near *,void __near *,int))
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropArray3(
        RecvProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int elements,
        RecvProp pArrayProp,
        void (__cdecl *varProxy)(const RecvProp *, void **, void *, int))
{
  RecvProp *v8; // eax
  int v9; // edx
  int *p_m_Offset; // ecx
  int v11; // eax
  RecvProp *v12; // edx
  RecvTable *v13; // eax
  RecvProp *pProps; // [esp+14h] [ebp+8h]
  int offseta; // [esp+1Ch] [ebp+10h]
  const char *pParentArrayPropName; // [esp+64h] [ebp+58h]

  result->m_pExtraData = nullptr;
  result->m_Flags = 0;
  result->m_ProxyFn = nullptr;
  result->m_pDataTable = nullptr;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_bInsideArray = false;
  result->m_Offset = offset;
  result->m_pVarName = pVarName;
  result->m_DataTableProxyFn = varProxy;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_RecvType = DPT_DataTable;
  v8 = (RecvProp *)MemAlloc_Alloc(nSize: (60 * (unsigned __int64)(unsigned int)elements) >> 32 != 0 ? -1 : 60 * elements);
  if ( v8 != nullptr )
  {
    v9 = elements - 1;
    if ( elements - 1 >= 0 )
    {
      p_m_Offset = &v8->m_Offset;
      do
      {
        *(p_m_Offset - 6) = 0;
        *(p_m_Offset - 11) = 0;
        *p_m_Offset = 0;
        *(p_m_Offset - 10) = 0;
        *(p_m_Offset - 9) = 0;
        *(p_m_Offset - 3) = 0;
        *(p_m_Offset - 2) = 0;
        *(p_m_Offset - 1) = 0;
        p_m_Offset[2] = 1;
        p_m_Offset[1] = -1;
        *(p_m_Offset - 5) = 0;
        *(p_m_Offset - 4) = 0;
        *((_BYTE *)p_m_Offset - 28) = 0;
        p_m_Offset += 15;
        --v9;
      }
      while ( v9 >= 0 );
    }
    pProps = v8;
  }
  else
  {
    pProps = nullptr;
  }
  pParentArrayPropName = AllocateStringHelper(pFormat: "%s", pVarName);
  v11 = 0;
  if ( elements > 0 )
  {
    v12 = pProps;
    offseta = 0;
    do
    {
      *v12 = pArrayProp;
      v12->m_Offset = offseta;
      v12->m_pVarName = s_ClientElementNames[v11];
      v12->m_pParentArrayPropName = pParentArrayPropName;
      ++v11;
      ++v12;
      offseta += sizeofVar;
    }
    while ( v11 < elements );
  }
  v13 = (RecvTable *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v13 != nullptr )
  {
    v13->m_pProps = pProps;
    v13->m_pDecoder = nullptr;
    result->m_pDataTable = v13;
    v13->m_nProps = elements;
    v13->m_pNetTableName = pVarName;
    *(_WORD *)&v13->m_bInitialized = 0;
  }
  else
  {
    result->m_pDataTable = nullptr;
  }
  return result;
}

} // namespace client
