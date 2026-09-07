// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shader_dll_verify.cpp
// Functions: 5
// ============================================================

#include "materialsystem\shader_dll_verify.h"

//------------------------------------------------------------------------------
// Address: 0x100025E0
// Name: DllMain(x,x,x)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  g_hDLLInst = hinstDLL;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10002610
// Name: public: virtual unsigned long CShaderDLLVerification::Function1(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CShaderDLLVerification::Function1(CShaderDLLVerification *this, unsigned __int8 *pData)
{
  unsigned __int8 *v2; // esi
  void *pVerifyPtr1; // [esp+4h] [ebp-4h] BYREF

  v2 = pData + 43;
  g_pLastInputData = pData + 43;
  pVerifyPtr1 = &g_Blah;
  CRC32_Init(pulCRC: (unsigned int *)&pData);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pData, pBuffer: v2, nBuffer: 4101);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pData, pBuffer: &g_hDLLInst, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pData, pBuffer: &pVerifyPtr1, nBuffer: 4);
  CRC32_Final(pulCRC: (unsigned int *)&pData);
  return pData;
}

//------------------------------------------------------------------------------
// Address: 0x10002680
// Name: public: virtual void CShaderDLLVerification::Function2(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLLVerification::Function2(CShaderDLLVerification *this, int a, int b, int c)
{
  MD5Context_t md5Context; // [esp+0h] [ebp-58h] BYREF

  MD5Init(ctx: &md5Context);
  MD5Update(ctx: &md5Context, buf: g_pLastInputData + 43, len: 0xFDAu);
  MD5Final(digest: g_pLastInputData, ctx: &md5Context);
}

//------------------------------------------------------------------------------
// Address: 0x100026C0
// Name: public: virtual unsigned long CShaderDLLVerification::Function5(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShaderDLLVerification::Function5(CShaderDLLVerification *this)
{
  return 32423;
}

//------------------------------------------------------------------------------
// Address: 0x10002600
// Name: __ftol3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ftol3(char *pData)
{
  *(_DWORD *)(pData + 43) = &g_Blah;
}

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x10047C40
// Name: DllMain(x,x,x)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  g_hDLLInst = hinstDLL;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10047C70
// Name: public: virtual unsigned long CShaderDLLVerification::Function1(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CShaderDLLVerification::Function1(CShaderDLLVerification *this, unsigned __int8 *pData)
{
  unsigned __int8 *v2; // esi
  void *pVerifyPtr1; // [esp+4h] [ebp-4h] BYREF

  v2 = pData + 43;
  g_pLastInputData = pData + 43;
  pVerifyPtr1 = &g_Blah;
  CRC32_Init(pulCRC: (unsigned int *)&pData);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pData, pBuffer: v2, nBuffer: 4101);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pData, pBuffer: &g_hDLLInst, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pData, pBuffer: &pVerifyPtr1, nBuffer: 4);
  CRC32_Final(pulCRC: (unsigned int *)&pData);
  return pData;
}

//------------------------------------------------------------------------------
// Address: 0x10047CE0
// Name: public: virtual void CShaderDLLVerification::Function2(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLLVerification::Function2(CShaderDLLVerification *this, int a, int b, int c)
{
  MD5Context_t md5Context; // [esp+0h] [ebp-58h] BYREF

  MD5Init(ctx: &md5Context);
  MD5Update(ctx: &md5Context, buf: g_pLastInputData + 43, len: 0xFDAu);
  MD5Final(digest: g_pLastInputData, ctx: &md5Context);
}

//------------------------------------------------------------------------------
// Address: 0x10047D20
// Name: public: virtual unsigned long CShaderDLLVerification::Function5(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShaderDLLVerification::Function5(CShaderDLLVerification *this)
{
  return 32423;
}

//------------------------------------------------------------------------------
// Address: 0x10047C60
// Name: __ftol3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ftol3(char *pData)
{
  *(_DWORD *)(pData + 43) = &g_Blah;
}

} // namespace stdshader_dx9
