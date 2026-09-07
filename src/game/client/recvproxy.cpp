// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/recvproxy.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10163AD0
// Name: void RecvProxy_IntSubOne(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_IntSubOne(const CRecvProxyData *pData, void *pStruct, _DWORD *pOut)
{
  *pOut = pData->m_Value.m_Int - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10163AF0
// Name: void RecvProxy_ShortSubOne(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_ShortSubOne(const CRecvProxyData *pData, void *pStruct, _WORD *pOut)
{
  *pOut = LOWORD(pData->m_Value.m_Float) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10163B10
// Name: class RecvProp RecvPropEHandle(char __near *,int,int,void (*)(class CRecvProxyData const __near *,void __near *,void __near *))
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropEHandle(
        RecvProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        void (__cdecl *proxyFn)(const CRecvProxyData *, void *, void *))
{
  RecvPropInt(result, pVarName, offset, sizeofVar, flags: 0, varProxy: proxyFn);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163B40
// Name: class RecvProp RecvPropBool(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropBool(RecvProp *result, char *pVarName, int offset, int sizeofVar)
{
  RecvPropInt(result, pVarName, offset, sizeofVar, flags: 0, varProxy: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163B70
// Name: class RecvProp RecvPropTime(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
RecvProp *__cdecl RecvPropTime(RecvProp *result, char *pVarName, int offset, int sizeofVar)
{
  RecvPropFloat(
    result,
    pVarName,
    offset,
    sizeofVar,
    flags: 0,
    varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163BA0
// Name: void RecvProxy_IntToEHandle(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_IntToEHandle(const CRecvProxyData *pData, void *pStruct, int *pOut)
{
  if ( pData->m_Value.m_Int == 0x1FFFFF )
    *pOut = -1;
  else
    *pOut = pData->m_Value.m_Int & 0x7FF | (pData->m_Value.m_Int >> 11 << 16);
}

//------------------------------------------------------------------------------
// Address: 0x10163BE0
// Name: void RecvProxy_InterpolationAmountChanged(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_InterpolationAmountChanged(const CRecvProxyData *pData, C_BaseEntity *pStruct, _BYTE *pOut)
{
  if ( *pOut != (pData->m_Value.m_Int != 0) )
  {
    RecvProxy_Int32ToInt8(pData, pStruct, pOut);
    C_BaseEntity::Interp_UpdateInterpolationAmounts(this: pStruct, map: &pStruct->m_VarMap);
  }
}
