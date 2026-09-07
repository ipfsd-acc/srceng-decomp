// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/dmxedit/winstuff.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040C250
// Name: void MyGetUserName(char __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MyGetUserName(char *pszBuf, unsigned int *pBufSiz)
{
  GetUserNameA(lpBuffer: pszBuf, pcbBuffer: pBufSiz);
}

//------------------------------------------------------------------------------
// Address: 0x0040C270
// Name: void MyGetComputerName(char __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MyGetComputerName(char *pszBuf, unsigned int *pBufSiz)
{
  GetComputerNameA(lpBuffer: pszBuf, nSize: pBufSiz);
}
