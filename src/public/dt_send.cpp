// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/dt_send.cpp
// Functions: 12
// ============================================================

#include "public\dt_send.h"

//------------------------------------------------------------------------------
// Address: 0x10173060
// Name: void SendProxy_FloatToFloat(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_FloatToFloat(const SendProp *pProp, const void *pStruct, float *pData, DVariant *pOut)
{
  pOut->m_Float = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10173070
// Name: void SendProxy_VectorToVector(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_VectorToVector(
        const SendProp *pProp,
        const void *pStruct,
        $5FB8512C96CD1B8867E59BA5A9F6C5D6 *pData,
        DVariant *pOut)
{
  pOut->___u0 = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10173090
// Name: void SendProxy_Int8ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int8ToInt32(const SendProp *pProp, const void *pStruct, char *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x101730A0
// Name: void SendProxy_Int16ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int16ToInt32(const SendProp *pProp, const void *pStruct, __int16 *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x101730B0
// Name: void SendProxy_Int64ToInt64(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int64ToInt64(const SendProp *pProp, const void *pStruct, __int64 *pData, DVariant *pOut)
{
  pOut->m_Int64 = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x101730D0
// Name: void SendProxy_UInt8ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_UInt8ToInt32(const SendProp *pProp, const void *pStruct, unsigned __int8 *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x101730E0
// Name: void SendProxy_UInt16ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_UInt16ToInt32(
        const SendProp *pProp,
        const void *pStruct,
        unsigned __int16 *pData,
        DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x101730F0
// Name: void SendProxy_Int32ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int32ToInt32(const SendProp *pProp, const void *pStruct, int *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10173110
// Name: public: SendProp::SendProp(void)
// Source: json
//------------------------------------------------------------------------------
SendProp *__thiscall SendProp::SendProp(SendProp *this)
{
  this->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  this->m_pVarName = nullptr;
  this->m_Offset = 0;
  this->m_pDataTable = nullptr;
  this->m_ProxyFn = nullptr;
  this->m_pExcludeDTName = nullptr;
  this->m_pParentArrayPropName = nullptr;
  this->m_Type = DPT_Int;
  this->m_Flags = 0;
  this->m_nBits = 0;
  this->m_fLowValue = 0.0;
  this->m_fHighValue = 0.0;
  this->m_fHighLowMul = 0.0;
  this->m_pArrayProp = nullptr;
  this->m_ArrayLengthProxy = nullptr;
  this->m_nElements = 1;
  this->m_ElementStride = -1;
  this->m_DataTableProxyFn = nullptr;
  this->m_pMatchingRecvProp = nullptr;
  this->m_priority = 0x80;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10173170
// Name: public: virtual SendProp::~SendProp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SendProp::~SendProp(SendProp *this)
{
  this->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10173180
// Name: public: int SendProp::GetNumArrayLengthBits(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SendProp::GetNumArrayLengthBits(SendProp *this)
{
  return Q_log2(val: this->m_nElements) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10173190
// Name: public: SendTable::SendTable(void)
// Source: json
//------------------------------------------------------------------------------
SendTable *__thiscall SendTable::SendTable(SendTable *this)
{
  *((_BYTE *)this + 16) &= 0xF8u;
  this->m_pProps = nullptr;
  this->m_nProps = 0;
  this->m_pNetTableName = nullptr;
  this->m_pPrecalc = nullptr;
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101733E0
// Name: void SendProxy_FloatToFloat(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_FloatToFloat(const SendProp *pProp, const void *pStruct, float *pData, DVariant *pOut)
{
  pOut->m_Float = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x101733F0
// Name: void SendProxy_VectorToVector(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_VectorToVector(
        const SendProp *pProp,
        const void *pStruct,
        $5FB8512C96CD1B8867E59BA5A9F6C5D6 *pData,
        DVariant *pOut)
{
  pOut->___u0 = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10173410
// Name: void SendProxy_Int8ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int8ToInt32(const SendProp *pProp, const void *pStruct, char *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10173420
// Name: void SendProxy_Int16ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int16ToInt32(const SendProp *pProp, const void *pStruct, __int16 *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10173430
// Name: void SendProxy_Int64ToInt64(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int64ToInt64(const SendProp *pProp, const void *pStruct, __int64 *pData, DVariant *pOut)
{
  pOut->m_Int64 = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10173450
// Name: void SendProxy_UInt8ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_UInt8ToInt32(const SendProp *pProp, const void *pStruct, unsigned __int8 *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10173460
// Name: void SendProxy_UInt16ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_UInt16ToInt32(
        const SendProp *pProp,
        const void *pStruct,
        unsigned __int16 *pData,
        DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10173470
// Name: void SendProxy_Int32ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int32ToInt32(const SendProp *pProp, const void *pStruct, int *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10173480
// Name: public: SendProp::SendProp(void)
// Source: json
//------------------------------------------------------------------------------
SendProp *__thiscall SendProp::SendProp(SendProp *this)
{
  this->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  this->m_pVarName = nullptr;
  this->m_Offset = 0;
  this->m_pDataTable = nullptr;
  this->m_ProxyFn = nullptr;
  this->m_pExcludeDTName = nullptr;
  this->m_pParentArrayPropName = nullptr;
  this->m_Type = DPT_Int;
  this->m_Flags = 0;
  this->m_nBits = 0;
  this->m_fLowValue = 0.0;
  this->m_fHighValue = 0.0;
  this->m_fHighLowMul = 0.0;
  this->m_pArrayProp = nullptr;
  this->m_ArrayLengthProxy = nullptr;
  this->m_nElements = 1;
  this->m_ElementStride = -1;
  this->m_DataTableProxyFn = nullptr;
  this->m_pMatchingRecvProp = nullptr;
  this->m_priority = 0x80;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101734E0
// Name: public: virtual SendProp::~SendProp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SendProp::~SendProp(SendProp *this)
{
  this->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101734F0
// Name: public: int SendProp::GetNumArrayLengthBits(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SendProp::GetNumArrayLengthBits(SendProp *this)
{
  return Q_log2(val: this->m_nElements) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10173500
// Name: public: SendTable::SendTable(void)
// Source: json
//------------------------------------------------------------------------------
SendTable *__thiscall SendTable::SendTable(SendTable *this)
{
  *((_BYTE *)this + 16) &= 0xF8u;
  this->m_pProps = nullptr;
  this->m_nProps = 0;
  this->m_pNetTableName = nullptr;
  this->m_pPrecalc = nullptr;
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10101D60
// Name: public: CNonModifiedPointerProxy::CNonModifiedPointerProxy(void __near * (*)(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int))
// Source: json
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *__thiscall CNonModifiedPointerProxy::CNonModifiedPointerProxy(
        CNonModifiedPointerProxy *this,
        void *(__cdecl *fn)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))
{
  this->m_pNext = s_pNonModifiedPointerProxyHead;
  s_pNonModifiedPointerProxyHead = this;
  this->m_Fn = fn;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10101D80
// Name: void SendProxy_AngleToFloat(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_AngleToFloat(const SendProp *pProp, const void *pStruct, float *pData, DVariant *pOut)
{
  pOut->m_Float = (float)(unsigned __int16)(int)(float)(*pData * 182.04445) * 0.0054931641;
}

//------------------------------------------------------------------------------
// Address: 0x10101DC0
// Name: void SendProxy_FloatToFloat(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_FloatToFloat(const SendProp *pProp, const void *pStruct, float *pData, DVariant *pOut)
{
  pOut->m_Float = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10101DD0
// Name: void SendProxy_QAngles(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_QAngles(const SendProp *pProp, const void *pStruct, float *pData, DVariant *pOut)
{
  pOut->m_Float = (float)(unsigned __int16)(int)(float)(*pData * 182.04445) * 0.0054931641;
  pOut->m_Vector[1] = (float)(unsigned __int16)(int)(float)(pData[1] * 182.04445) * 0.0054931641;
  pOut->m_Vector[2] = (float)(unsigned __int16)(int)(float)(pData[2] * 182.04445) * 0.0054931641;
}

//------------------------------------------------------------------------------
// Address: 0x10101E80
// Name: void SendProxy_Int8ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int8ToInt32(const SendProp *pProp, const void *pStruct, char *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10101E90
// Name: void SendProxy_Int16ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int16ToInt32(const SendProp *pProp, const void *pStruct, __int16 *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10101EA0
// Name: void SendProxy_Int32ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int32ToInt32(const SendProp *pProp, const void *pStruct, int *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10101EB0
// Name: void SendProxy_Int64ToInt64(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Int64ToInt64(const SendProp *pProp, const void *pStruct, __int64 *pData, DVariant *pOut)
{
  pOut->m_Int64 = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10101ED0
// Name: void SendProxy_UInt8ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_UInt8ToInt32(const SendProp *pProp, const void *pStruct, unsigned __int8 *pData, DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10101EE0
// Name: void SendProxy_UInt16ToInt32(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_UInt16ToInt32(
        const SendProp *pProp,
        const void *pStruct,
        unsigned __int16 *pData,
        DVariant *pOut)
{
  pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x10101EF0
// Name: void SendProxy_StringToString(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_StringToString(const SendProp *pProp, const void *pStruct, const void *pData, DVariant *pOut)
{
  pOut->m_Int = (int)pData;
}

//------------------------------------------------------------------------------
// Address: 0x10101F00
// Name: void __near * SendProxy_DataTableToDataTable(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_DataTableToDataTable(const SendProp *pProp, const void *pStructBase, const void *pData)
{
  return (void *)pData;
}

//------------------------------------------------------------------------------
// Address: 0x10101F10
// Name: void __near * SendProxy_DataTablePtrToDataTable(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_DataTablePtrToDataTable(const SendProp *pProp, const void *pStructBase, const void *pData)
{
  return *(void **)pData;
}

//------------------------------------------------------------------------------
// Address: 0x10101F20
// Name: float AssignRangeMultiplier(int,double)
// Source: json
//------------------------------------------------------------------------------
double __cdecl AssignRangeMultiplier(int nBits, long double range)
{
  unsigned int v2; // edx
  double v3; // xmm3_8
  float v4; // xmm2_4
  double result; // st7
  unsigned int i; // ecx
  float v7; // xmm2_4
  double v8; // xmm0_8
  float multipliers[5]; // [esp+0h] [ebp-20h]
  long double v10; // [esp+14h] [ebp-Ch]
  float fHighLowMul; // [esp+1Ch] [ebp-4h]

  if ( nBits == 32 )
    v2 = -2;
  else
    v2 = (1 << nBits) - 1;
  v3 = (double)v2;
  v4 = (double)v2 / range;
  fHighLowMul = v4;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(range) & _mask__AbsFloat_) > 0.001 )
    result = fHighLowMul;
  else
    result = (double)v2;
  v10 = range * result;
  if ( (unsigned int)(__int64)v10 > v2 || v10 > v3 )
  {
    multipliers[0] = 0.99989998;
    multipliers[1] = 0.99000001;
    multipliers[2] = 0.89999998;
    multipliers[3] = 0.80000001;
    multipliers[4] = 0.69999999;
    for ( i = 0; i < 5; ++i )
    {
      v7 = (double)v2 / range;
      fHighLowMul = multipliers[i] * v7;
      v8 = fHighLowMul * range;
      v10 = v8;
      if ( (unsigned int)(__int64)v8 <= v2 && v8 <= v3 )
        break;
    }
    if ( i == 5 )
      return 0.0;
    else
      return fHighLowMul;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10102080
// Name: public: class SendProp __near & SendProp::operator=(class SendProp const __near &)
// Source: json
//------------------------------------------------------------------------------
SendProp *__thiscall SendProp::operator=(SendProp *this, const SendProp *__that)
{
  this->m_pMatchingRecvProp = __that->m_pMatchingRecvProp;
  this->m_Type = __that->m_Type;
  this->m_nBits = __that->m_nBits;
  this->m_fLowValue = __that->m_fLowValue;
  this->m_fHighValue = __that->m_fHighValue;
  this->m_pArrayProp = __that->m_pArrayProp;
  this->m_ArrayLengthProxy = __that->m_ArrayLengthProxy;
  this->m_nElements = __that->m_nElements;
  this->m_ElementStride = __that->m_ElementStride;
  this->m_pExcludeDTName = __that->m_pExcludeDTName;
  this->m_pParentArrayPropName = __that->m_pParentArrayPropName;
  this->m_pVarName = __that->m_pVarName;
  this->m_fHighLowMul = __that->m_fHighLowMul;
  this->m_priority = __that->m_priority;
  this->m_Flags = __that->m_Flags;
  this->m_ProxyFn = __that->m_ProxyFn;
  this->m_DataTableProxyFn = __that->m_DataTableProxyFn;
  this->m_pDataTable = __that->m_pDataTable;
  this->m_Offset = __that->m_Offset;
  this->m_pExtraData = __that->m_pExtraData;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10102110
// Name: public: SendProp::SendProp(void)
// Source: json
//------------------------------------------------------------------------------
SendProp *__thiscall SendProp::SendProp(SendProp *this)
{
  this->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  this->m_pVarName = nullptr;
  this->m_Offset = 0;
  this->m_pDataTable = nullptr;
  this->m_ProxyFn = nullptr;
  this->m_pExcludeDTName = nullptr;
  this->m_pParentArrayPropName = nullptr;
  this->m_Type = DPT_Int;
  this->m_Flags = 0;
  this->m_nBits = 0;
  this->m_fLowValue = 0.0;
  this->m_fHighValue = 0.0;
  this->m_fHighLowMul = 0.0;
  this->m_pArrayProp = nullptr;
  this->m_ArrayLengthProxy = nullptr;
  this->m_nElements = 1;
  this->m_ElementStride = -1;
  this->m_DataTableProxyFn = nullptr;
  this->m_pMatchingRecvProp = nullptr;
  this->m_priority = 0x80;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10102170
// Name: public: virtual SendProp::~SendProp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SendProp::~SendProp(SendProp *this)
{
  this->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10102180
// Name: public: void SendTable::Construct(class SendProp __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SendTable::Construct(SendTable *this, SendProp *pProps, int nProps, char *pNetTableName)
{
  *((_BYTE *)this + 16) &= 0xF8u;
  this->m_pProps = pProps;
  this->m_nProps = nProps;
  this->m_pNetTableName = pNetTableName;
  this->m_pPrecalc = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101021B0
// Name: class SendProp SendPropFloat(char __near *,int,int,int,int,float,float,void (*)(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int),unsigned char)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropFloat(
        SendProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int nBits,
        int flags,
        float fLowValue,
        float fHighValue,
        void (__cdecl *varProxy)(const SendProp *, const void *, const void *, DVariant *, int, int),
        unsigned __int8 priority)
{
  float v10; // xmm5_4
  float v11; // xmm6_4
  int v12; // ecx

  v10 = 0.0;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_pVarName = nullptr;
  result->m_Offset = 0;
  result->m_pDataTable = nullptr;
  result->m_ProxyFn = nullptr;
  result->m_pExcludeDTName = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_Type = DPT_Int;
  result->m_Flags = 0;
  result->m_nBits = 0;
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_DataTableProxyFn = nullptr;
  result->m_pMatchingRecvProp = nullptr;
  result->m_priority = 0x80;
  if ( nBits <= 0 || nBits == 32 )
  {
    v12 = flags | 4;
    v11 = 0.0;
    result->m_fHighLowMul = 0.0;
  }
  else
  {
    v11 = fHighValue;
    if ( fHighValue == -121121.12 )
      v11 = (float)(1 << nBits);
    if ( (flags & 8) != 0 )
    {
      v10 = fLowValue;
      v11 = v11 - (float)((float)(v11 - fLowValue) / (float)(1 << nBits));
    }
    else if ( (flags & 0x10) != 0 )
    {
      v10 = (float)((float)(v11 - fLowValue) / (float)(1 << nBits)) + fLowValue;
    }
    else
    {
      v10 = fLowValue;
    }
    result->m_fHighLowMul = AssignRangeMultiplier(nBits, range: (float)(v11 - v10));
    v12 = flags;
  }
  result->m_pVarName = pVarName;
  result->m_ProxyFn = varProxy;
  result->m_Type = DPT_Float;
  result->m_Offset = offset;
  result->m_nBits = nBits;
  result->m_Flags = v12;
  result->m_fLowValue = v10;
  result->m_fHighValue = v11;
  result->m_priority = priority;
  if ( (v12 & 0x7026) != 0 )
    result->m_nBits = 0;
  if ( ((offset >> 20) & 1) == 1 && ((offset >> 20) & 2) != 2 && ((offset >> 20) & 4) != 4 )
    _Error(this: (ISceneTokenProcessor *)&stru_1045CE38, a2: pVarName);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10102350
// Name: class SendProp SendPropVector(char __near *,int,int,int,int,float,float,void (*)(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int),unsigned char)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropVector(
        SendProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int nBits,
        int flags,
        float fLowValue,
        float fHighValue,
        void (__cdecl *varProxy)(const SendProp *, const void *, const void *, DVariant *, int, int),
        unsigned __int8 priority)
{
  int v10; // ebx
  SendProp *v11; // eax

  v10 = flags;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_pVarName = nullptr;
  result->m_Offset = 0;
  result->m_pDataTable = nullptr;
  result->m_ProxyFn = nullptr;
  result->m_pExcludeDTName = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_Type = DPT_Int;
  result->m_Flags = 0;
  result->m_nBits = 0;
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_DataTableProxyFn = nullptr;
  result->m_pMatchingRecvProp = nullptr;
  result->m_priority = 0x80;
  if ( nBits == 32 )
    v10 = flags | 4;
  result->m_fHighValue = fHighValue;
  result->m_Type = DPT_Vector;
  result->m_pVarName = pVarName;
  result->m_Offset = offset;
  result->m_nBits = nBits;
  result->m_Flags = v10;
  result->m_fLowValue = fLowValue;
  result->m_fHighLowMul = AssignRangeMultiplier(nBits, range: (float)(fHighValue - fLowValue));
  result->m_ProxyFn = varProxy;
  result->m_priority = priority;
  v11 = result;
  if ( (v10 & 0x7026) != 0 )
    result->m_nBits = 0;
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10102420
// Name: class SendProp SendPropVectorXY(char __near *,int,int,int,int,float,float,void (*)(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int),unsigned char)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropVectorXY(
        SendProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int nBits,
        int flags,
        float fLowValue,
        float fHighValue,
        void (__cdecl *varProxy)(const SendProp *, const void *, const void *, DVariant *, int, int),
        unsigned __int8 priority)
{
  int v10; // ebx
  SendProp *v11; // eax

  v10 = flags;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_pVarName = nullptr;
  result->m_Offset = 0;
  result->m_pDataTable = nullptr;
  result->m_ProxyFn = nullptr;
  result->m_pExcludeDTName = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_Type = DPT_Int;
  result->m_Flags = 0;
  result->m_nBits = 0;
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_DataTableProxyFn = nullptr;
  result->m_pMatchingRecvProp = nullptr;
  result->m_priority = 0x80;
  if ( nBits == 32 )
    v10 = flags | 4;
  result->m_fHighValue = fHighValue;
  result->m_Type = DPT_VectorXY;
  result->m_pVarName = pVarName;
  result->m_Offset = offset;
  result->m_nBits = nBits;
  result->m_Flags = v10;
  result->m_fLowValue = fLowValue;
  result->m_fHighLowMul = AssignRangeMultiplier(nBits, range: (float)(fHighValue - fLowValue));
  result->m_ProxyFn = varProxy;
  result->m_priority = priority;
  v11 = result;
  if ( (v10 & 0x7026) != 0 )
    result->m_nBits = 0;
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x101024F0
// Name: class SendProp SendPropAngle(char __near *,int,int,int,int,void (*)(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int),unsigned char)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropAngle(
        SendProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int nBits,
        int flags,
        void (__cdecl *varProxy)(const SendProp *, const void *, const void *, DVariant *, int, int),
        unsigned __int8 priority)
{
  int v8; // eax
  int v9; // eax

  result->m_pVarName = nullptr;
  result->m_Offset = 0;
  result->m_pDataTable = nullptr;
  result->m_ProxyFn = nullptr;
  result->m_pExcludeDTName = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_Type = DPT_Int;
  result->m_Flags = 0;
  result->m_nBits = 0;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_DataTableProxyFn = nullptr;
  result->m_pMatchingRecvProp = nullptr;
  v8 = flags;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_priority = 0x80;
  if ( nBits == 32 )
    v8 = flags | 4;
  result->m_pVarName = pVarName;
  v9 = v8 | 8;
  result->m_fLowValue = 0.0;
  result->m_Offset = offset;
  result->m_Type = DPT_Float;
  result->m_nBits = nBits;
  result->m_Flags = v9;
  result->m_fHighValue = 360.0;
  if ( (v9 & 4) == 0 )
  {
    if ( (v9 & 0x10) != 0 )
    {
      result->m_fLowValue = 360.0 / (float)(1 << nBits);
    }
    else if ( (v9 & 8) != 0 )
    {
      result->m_fHighValue = 360.0 - (float)(360.0 / (float)(1 << nBits));
    }
  }
  result->m_fHighLowMul = AssignRangeMultiplier(nBits, range: (float)(result->m_fHighValue - result->m_fLowValue));
  result->m_ProxyFn = varProxy;
  result->m_priority = priority;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101025F0
// Name: class SendProp SendPropQAngles(char __near *,int,int,int,int,void (*)(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int),unsigned char)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropQAngles(
        SendProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int nBits,
        int flags,
        void (__cdecl *varProxy)(const SendProp *, const void *, const void *, DVariant *, int, int),
        unsigned __int8 priority)
{
  int v8; // eax
  int v9; // eax

  result->m_pVarName = nullptr;
  result->m_Offset = 0;
  result->m_pDataTable = nullptr;
  result->m_ProxyFn = nullptr;
  result->m_pExcludeDTName = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_Type = DPT_Int;
  result->m_Flags = 0;
  result->m_nBits = 0;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_DataTableProxyFn = nullptr;
  result->m_pMatchingRecvProp = nullptr;
  v8 = flags;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_priority = 0x80;
  if ( nBits == 32 )
    v8 = flags | 4;
  v9 = v8 | 8;
  result->m_pVarName = pVarName;
  result->m_fLowValue = 0.0;
  result->m_Type = DPT_Vector;
  result->m_Offset = offset;
  result->m_nBits = nBits;
  result->m_Flags = v9;
  result->m_fHighValue = 360.0;
  if ( (v9 & 4) == 0 )
  {
    if ( (v9 & 0x10) != 0 )
    {
      result->m_fLowValue = 360.0 / (float)(1 << nBits);
    }
    else if ( (v9 & 8) != 0 )
    {
      result->m_fHighValue = 360.0 - (float)(360.0 / (float)(1 << nBits));
    }
  }
  result->m_fHighLowMul = AssignRangeMultiplier(nBits, range: (float)(result->m_fHighValue - result->m_fLowValue));
  result->m_ProxyFn = varProxy;
  result->m_priority = priority;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10102700
// Name: class SendProp SendPropInt(char __near *,int,int,int,int,void (*)(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int),unsigned char)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropInt(
        SendProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int nBits,
        int flags,
        void (__cdecl *varProxy)(const SendProp *, const void *, const void *, DVariant *, int, int),
        unsigned __int8 priority)
{
  SendProp *v8; // eax
  void (__cdecl *v9)(const SendProp *, const void *, const void *, DVariant *, int, int); // edx
  int v10; // esi

  v8 = result;
  v9 = varProxy;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_pVarName = nullptr;
  result->m_Offset = 0;
  result->m_pDataTable = nullptr;
  result->m_ProxyFn = nullptr;
  result->m_pExcludeDTName = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_Type = DPT_Int;
  result->m_Flags = 0;
  result->m_nBits = 0;
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_DataTableProxyFn = nullptr;
  result->m_pMatchingRecvProp = nullptr;
  result->m_priority = 0x80;
  if ( varProxy == nullptr )
  {
    switch ( sizeofVar )
    {
      case 1:
        goto LABEL_8;
      case 2:
        v9 = (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Int16ToInt32;
        goto LABEL_9;
      case 4:
        v9 = (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Int32ToInt32;
        goto LABEL_9;
      default:
        break;
    }
    v9 = (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Int64ToInt64;
    if ( sizeofVar != 8 )
LABEL_8:
      v9 = (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Int8ToInt32;
  }
LABEL_9:
  v10 = nBits;
  if ( nBits <= 0 )
    v10 = 8 * sizeofVar;
  result->m_nBits = v10;
  result->m_priority = priority;
  result->m_ProxyFn = v9;
  result->m_Type = sizeofVar != 8 ? DPT_Int : DPT_Int64;
  result->m_pVarName = pVarName;
  result->m_Offset = offset;
  result->m_Flags = flags;
  if ( (flags & 1) != 0 )
  {
    if ( (char *)v9 == (char *)SendProxy_Int8ToInt32 )
    {
      result->m_ProxyFn = (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_UInt8ToInt32;
    }
    else if ( (char *)v9 == (char *)SendProxy_Int16ToInt32 )
    {
      result->m_ProxyFn = (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_UInt16ToInt32;
    }
    else if ( (char *)v9 == (char *)SendProxy_Int32ToInt32 )
    {
      result->m_ProxyFn = (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Int32ToInt32;
    }
    else if ( (char *)v9 == (char *)SendProxy_Int64ToInt64 )
    {
      result->m_ProxyFn = (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Int64ToInt64;
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10102820
// Name: class SendProp SendPropString(char __near *,int,int,int,void (*)(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int),unsigned char)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropString(
        SendProp *result,
        char *pVarName,
        int offset,
        int bufferLen,
        int flags,
        void (__cdecl *varProxy)(const SendProp *, const void *, const void *, DVariant *, int, int),
        unsigned __int8 priority)
{
  result->m_pDataTable = nullptr;
  result->m_pExcludeDTName = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_nBits = 0;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_DataTableProxyFn = nullptr;
  result->m_pMatchingRecvProp = nullptr;
  result->m_pVarName = pVarName;
  result->m_Offset = offset;
  result->m_Flags = flags;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_Type = DPT_String;
  result->m_ProxyFn = varProxy;
  result->m_priority = priority;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101028F0
// Name: class SendProp SendPropDataTable(char __near *,int,class SendTable __near *,void __near * (*)(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int),unsigned char)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropDataTable(
        SendProp *result,
        char *pVarName,
        int offset,
        SendTable *pTable,
        void *(__cdecl *varProxy)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int),
        unsigned __int8 priority)
{
  SendProp *v6; // eax

  v6 = result;
  result->m_pVarName = pVarName;
  result->m_pDataTable = pTable;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_ProxyFn = nullptr;
  result->m_pExcludeDTName = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_Flags = 0;
  result->m_nBits = 0;
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_pMatchingRecvProp = nullptr;
  result->m_Type = DPT_DataTable;
  result->m_Offset = offset;
  result->m_DataTableProxyFn = varProxy;
  result->m_priority = priority;
  if ( (char *)varProxy == (char *)SendProxy_DataTableToDataTable
    || (char *)varProxy == (char *)SendProxy_DataTablePtrToDataTable )
  {
    result->m_Flags = 512;
  }
  if ( (char *)varProxy == (char *)SendProxy_DataTableToDataTable && offset == 0 )
    result->m_Flags = 2048;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10102990
// Name: class SendProp InternalSendPropArray(int,int,char __near *,int (*)(void const __near *,int),unsigned char)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl InternalSendPropArray(
        SendProp *result,
        int elementCount,
        int elementStride,
        char *pName,
        int (__cdecl *arrayLengthFn)(const void *, int),
        unsigned __int8 priority)
{
  result->m_nElements = elementCount;
  result->m_ElementStride = elementStride;
  result->m_Offset = 0;
  result->m_pDataTable = nullptr;
  result->m_pExcludeDTName = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_Flags = 0;
  result->m_nBits = 0;
  result->m_DataTableProxyFn = nullptr;
  result->m_pMatchingRecvProp = nullptr;
  result->m_pVarName = pName;
  result->m_pArrayProp = nullptr;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_Type = DPT_Array;
  result->m_ProxyFn = (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))CAI_BaseNPC::OnSetSchedule;
  result->m_ArrayLengthProxy = arrayLengthFn;
  result->m_priority = priority;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10102A00
// Name: class SendProp SendPropExclude(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropExclude(SendProp *result, char *pDataTableName, char *pPropName)
{
  result->m_Offset = 0;
  result->m_pDataTable = nullptr;
  result->m_ProxyFn = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_Type = DPT_Int;
  result->m_nBits = 0;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_DataTableProxyFn = nullptr;
  result->m_pMatchingRecvProp = nullptr;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_priority = 0x80;
  result->m_Flags = 64;
  result->m_pExcludeDTName = pDataTableName;
  result->m_pVarName = pPropName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10102A70
// Name: public: SendTable::SendTable(void)
// Source: json
//------------------------------------------------------------------------------
SendTable *__thiscall SendTable::SendTable(SendTable *this)
{
  *((_BYTE *)this + 16) &= 0xF8u;
  this->m_pProps = nullptr;
  this->m_nProps = 0;
  this->m_pNetTableName = nullptr;
  this->m_pPrecalc = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10102A90
// Name: public: SendTable::SendTable(class SendProp __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
SendTable *__thiscall SendTable::SendTable(SendTable *this, SendProp *pProps, int nProps, char *pNetTableName)
{
  *((_BYTE *)this + 16) &= 0xF8u;
  this->m_pProps = pProps;
  this->m_nProps = nProps;
  this->m_pNetTableName = pNetTableName;
  this->m_pPrecalc = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10102AC0
// Name: class SendProp SendPropArray3(char __near *,int,int,int,class SendProp,void __near * (*)(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int),unsigned char)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropArray3(
        SendProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int elements,
        SendProp pArrayProp,
        void *(__cdecl *varProxy)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int),
        unsigned __int8 priority)
{
  void *(__cdecl *v8)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // edx
  SendProp *v10; // eax
  SendProp *v11; // ebx
  void *(__cdecl *v12)(const SendProp *, const void *, const void *); // eax
  int v13; // ebx
  int v14; // ecx
  _DWORD *v15; // eax
  int v16; // ecx
  SendProp *v17; // edx
  _DWORD *i; // eax
  int v19; // edx
  int v20; // ecx
  SendPropType *p_m_Type; // eax
  int v22; // edx
  int v23; // eax
  void *(__cdecl *v24)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // ebx
  SendTable *v25; // eax
  int v27; // [esp+0h] [ebp-4h]
  SendProp *pProps; // [esp+Ch] [ebp+8h]
  int offseta; // [esp+14h] [ebp+10h]

  v8 = varProxy;
  result->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
  result->m_pDataTable = nullptr;
  result->m_ProxyFn = nullptr;
  result->m_pExcludeDTName = nullptr;
  result->m_pParentArrayPropName = nullptr;
  result->m_Flags = 0;
  result->m_nBits = 0;
  result->m_fLowValue = 0.0;
  result->m_fHighValue = 0.0;
  result->m_fHighLowMul = 0.0;
  result->m_pArrayProp = nullptr;
  result->m_ArrayLengthProxy = nullptr;
  result->m_nElements = 1;
  result->m_ElementStride = -1;
  result->m_pMatchingRecvProp = nullptr;
  result->m_priority = 0x80;
  result->m_Type = DPT_DataTable;
  result->m_pVarName = pVarName;
  result->m_Offset = offset;
  result->m_DataTableProxyFn = v8;
  v10 = (SendProp *)operator new(nSize: 0x54u);
  if ( v10 != nullptr )
  {
    v10->m_nElements = 1;
    v10->__vftable = (SendProp_vtbl *)&SendProp::`vftable';
    v10->m_pVarName = nullptr;
    v10->m_Offset = 0;
    v10->m_pDataTable = nullptr;
    v10->m_ProxyFn = nullptr;
    v10->m_pExcludeDTName = nullptr;
    v10->m_pParentArrayPropName = nullptr;
    v10->m_Type = DPT_Int;
    v10->m_Flags = 0;
    v10->m_nBits = 0;
    v10->m_fLowValue = 0.0;
    v10->m_fHighValue = 0.0;
    v10->m_fHighLowMul = 0.0;
    v10->m_pArrayProp = nullptr;
    v10->m_ArrayLengthProxy = nullptr;
    v10->m_ElementStride = -1;
    v10->m_DataTableProxyFn = nullptr;
    v10->m_pMatchingRecvProp = nullptr;
    v10->m_priority = 0x80;
    v11 = v10;
  }
  else
  {
    v11 = nullptr;
  }
  SendProp::operator=(this: v11, __that: &pArrayProp);
  v12 = (void *(__cdecl *)(const SendProp *, const void *, const void *))varProxy;
  result->m_pArrayProp = v11;
  if ( v12 == SendProxy_DataTableToDataTable || v12 == SendProxy_DataTablePtrToDataTable )
    result->m_Flags = 512;
  v13 = elements;
  v14 = (84 * (unsigned __int64)(unsigned int)elements) >> 32 != 0 ? -1 : 84 * elements;
  v15 = operator new(nSize: __CFADD__(v14, 4) ? -1 : v14 + 4);
  if ( v15 != nullptr )
  {
    v16 = elements - 1;
    v17 = (SendProp *)(v15 + 1);
    *v15 = elements;
    for ( i = v15 + 1; v16 >= 0; --v16 )
    {
      *i = &SendProp::`vftable';
      i[12] = 0;
      i[19] = 0;
      i[18] = 0;
      i[16] = 0;
      i[10] = 0;
      i[11] = 0;
      i[2] = 0;
      i[15] = 0;
      i[3] = 0;
      i[4] = 0;
      i[5] = 0;
      i[13] = 0;
      i[6] = 0;
      i[7] = 0;
      i[8] = 1;
      i[9] = -1;
      i[17] = 0;
      i[1] = 0;
      *((_BYTE *)i + 56) = 0x80;
      i += 21;
    }
    pProps = v17;
  }
  else
  {
    pProps = nullptr;
  }
  v19 = sizeofVar;
  v20 = 0;
  if ( elements >= 4 )
  {
    v27 = 3 * sizeofVar;
    offseta = 2 * sizeofVar;
    varProxy = nullptr;
    p_m_Type = &pProps[1].m_Type;
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
      *((_DWORD *)p_m_Type - 4) = varProxy;
      *((_DWORD *)p_m_Type - 11) = s_ElementNames[v20];
      *((_DWORD *)p_m_Type - 12) = pVarName;
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
      *((_DWORD *)p_m_Type + 17) = (char *)varProxy + v19;
      *((_DWORD *)p_m_Type + 10) = off_1057C07C[v20];
      *((_DWORD *)p_m_Type + 9) = pVarName;
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
      *((_DWORD *)p_m_Type + 38) = offseta;
      *((_DWORD *)p_m_Type + 31) = off_1057C080[v20];
      *((_DWORD *)p_m_Type + 30) = pVarName;
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
      *((_DWORD *)p_m_Type + 59) = v27;
      *((_DWORD *)p_m_Type + 52) = off_1057C084[v20];
      v22 = 4 * v19;
      varProxy = (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))((char *)varProxy + v22);
      offseta += v22;
      v27 += v22;
      *((_DWORD *)p_m_Type + 51) = pVarName;
      v13 = elements;
      v20 += 4;
      p_m_Type += 84;
      v19 = sizeofVar;
    }
    while ( v20 < elements - 3 );
  }
  if ( v20 < v13 )
  {
    varProxy = (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))(v19 * v20);
    v23 = (int)&pProps[v20].m_Type;
    do
    {
      *(_DWORD *)(v23 - 4) = pArrayProp.m_pMatchingRecvProp;
      *(_DWORD *)v23 = pArrayProp.m_Type;
      *(_DWORD *)(v23 + 4) = pArrayProp.m_nBits;
      *(float *)(v23 + 8) = pArrayProp.m_fLowValue;
      *(float *)(v23 + 12) = pArrayProp.m_fHighValue;
      *(_DWORD *)(v23 + 16) = pArrayProp.m_pArrayProp;
      *(_DWORD *)(v23 + 20) = pArrayProp.m_ArrayLengthProxy;
      *(_DWORD *)(v23 + 24) = pArrayProp.m_nElements;
      *(_DWORD *)(v23 + 28) = pArrayProp.m_ElementStride;
      *(_DWORD *)(v23 + 32) = pArrayProp.m_pExcludeDTName;
      *(_DWORD *)(v23 + 36) = pArrayProp.m_pParentArrayPropName;
      *(_DWORD *)(v23 + 40) = pArrayProp.m_pVarName;
      *(float *)(v23 + 44) = pArrayProp.m_fHighLowMul;
      *(_BYTE *)(v23 + 48) = pArrayProp.m_priority;
      *(_DWORD *)(v23 + 52) = pArrayProp.m_Flags;
      *(_DWORD *)(v23 + 56) = pArrayProp.m_ProxyFn;
      *(_DWORD *)(v23 + 60) = pArrayProp.m_DataTableProxyFn;
      *(_DWORD *)(v23 + 64) = pArrayProp.m_pDataTable;
      *(_DWORD *)(v23 + 68) = pArrayProp.m_Offset;
      *(_DWORD *)(v23 + 72) = pArrayProp.m_pExtraData;
      v24 = varProxy;
      varProxy = (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))((char *)varProxy + v19);
      *(_DWORD *)(v23 + 68) = v24;
      *(_DWORD *)(v23 + 40) = s_ElementNames[v20];
      *(_DWORD *)(v23 + 36) = pVarName;
      v13 = elements;
      ++v20;
      v23 += 84;
    }
    while ( v20 < elements );
  }
  v25 = (SendTable *)operator new(nSize: 0x14u);
  if ( v25 != nullptr )
  {
    *((_BYTE *)v25 + 16) &= 0xF8u;
    v25->m_nProps = v13;
    v25->m_pPrecalc = nullptr;
    result->m_pDataTable = v25;
    v25->m_pProps = pProps;
    v25->m_pNetTableName = pVarName;
  }
  else
  {
    result->m_pDataTable = nullptr;
  }
  result->m_priority = priority;
  return result;
}

} // namespace server
