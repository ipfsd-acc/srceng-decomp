// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: _libs/mod0326_Import:IPHLPAPI.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10211EA4
// Name: GetAdaptersInfo(x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
ULONG __stdcall GetAdaptersInfo(PIP_ADAPTER_INFO AdapterInfo, PULONG SizePointer)
{
  return __imp__GetAdaptersInfo@8(AdapterInfo, SizePointer);
}
