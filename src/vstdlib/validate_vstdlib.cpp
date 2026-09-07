// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/validate_vstdlib.cpp
// Functions: 19
// ============================================================

#include "vstdlib\validate_vstdlib.h"

//------------------------------------------------------------------------------
// Address: 0x3F61AC60
// Name: public: virtual void CDLLValidate::Validate(class CValidator __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDLLValidate::Validate(CDLLValidate *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F61AC70
// Name: public: CDLLValidate::CDLLValidate(void)
// Source: json
//------------------------------------------------------------------------------
CDLLValidate *__usercall CDLLValidate::CDLLValidate@<eax>(CDLLValidate *this@<ecx>, int a2@<eax>)
{
  return (CDLLValidate *)(*(_BYTE *)(a2 + 31) & 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F61AC80
// Name: public: IValidate::IValidate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall IValidate::IValidate(IValidate *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)(a2 + 16) = 0;
  JUMPOUT(0x3F61AC8F);
}

//------------------------------------------------------------------------------
// Address: 0x3F61AC90
// Name: __CreateCDLLValidateIValidate_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CreateCDLLValidateIValidate_interface()
{
  JUMPOUT(0x3F61AC93);
}

//------------------------------------------------------------------------------
// Address: 0x3F61ACA2
// Name: LoadLibraryA(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName)
{
  int v1; // eax
  char v2; // ch

  *(_BYTE *)(v1 - 1189579775) ^= v2;
  JUMPOUT(0x3F61ACA8);
}

//------------------------------------------------------------------------------
// Address: 0x3F61ACB4
// Name: GetCurrentThreadId()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __stdcall GetCurrentThreadId()
{
  JUMPOUT(0x3F61ACBA);
}

//------------------------------------------------------------------------------
// Address: 0x3F61ACC6
// Name: GetProcessHeap()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __stdcall GetProcessHeap()
{
  HANDLE result; // eax

  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61ACD2
// Name: GetVersionExA(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall GetVersionExA(LPOSVERSIONINFOA lpVersionInformation)
{
  BOOL result; // eax

  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61ACD8
// Name: SetLastError(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SetLastError(DWORD dwErrCode)
{
  char v1; // cf
  char v2; // bl
  int v3; // esi

  *(_BYTE *)(v3 - 61) -= v1 + v2;
  __debugbreak();
  __debugbreak();
  __debugbreak();
  JUMPOUT(0x3F61ACDE);
}

//------------------------------------------------------------------------------
// Address: 0x3F61ACDE
// Name: FoldStringW(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall FoldStringW(DWORD dwMapFlags, LPCWCH lpSrcStr, int cchSrc, LPWSTR lpDestStr, int cchDest)
{
  _BYTE *v5; // eax

  __debugbreak();
  __debugbreak();
  *v5 = 0;
  JUMPOUT(0x3F61ACE4);
}

//------------------------------------------------------------------------------
// Address: 0x3F61ACE4
// Name: MultiByteToWideChar(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall MultiByteToWideChar(
        UINT CodePage,
        DWORD dwFlags,
        LPCCH lpMultiByteStr,
        int cbMultiByte,
        LPWSTR lpWideCharStr,
        int cchWideChar)
{
  int v6; // eax
  char v7; // cl

  *(_BYTE *)(v6 + 1) = v7;
  *(_BYTE *)(v6 + 2) = v7;
  JUMPOUT(0x3F61ACEA);
}

//------------------------------------------------------------------------------
// Address: 0x3F61ACEA
// Name: WideCharToMultiByte(x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall WideCharToMultiByte(
        UINT CodePage,
        DWORD dwFlags,
        LPCWCH lpWideCharStr,
        int cchWideChar,
        LPSTR lpMultiByteStr,
        int cbMultiByte,
        LPCCH lpDefaultChar,
        LPBOOL lpUsedDefaultChar)
{
  int result; // eax
  char v9; // cl

  *(_BYTE *)(result + 3) = v9;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61ACF0
// Name: CharLowerW(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPWSTR __stdcall CharLowerW(LPWSTR lpsz)
{
  int v1; // eax
  int v2; // ecx

  return (LPWSTR)(v2 + v1);
}

//------------------------------------------------------------------------------
// Address: 0x3F61ACF6
// Name: _AssertMsgImplementation
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void AssertMsgImplementation()
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  JUMPOUT(0x3F61ACFC);
}

//------------------------------------------------------------------------------
// Address: 0x3F61AD14
// Name: ?Pop@CValidator@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CValidator::Pop(CValidator *this)
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  Error(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x3F61AD1A
// Name: _Error
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void Error()
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  JUMPOUT(0x3F61AD20);
}

//------------------------------------------------------------------------------
// Address: 0x3F61AD32
// Name: _Plat_IsInDebugSession
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall Plat_IsInDebugSession(char a1@<cl>, int a2@<ebx>)
{
  *(_BYTE *)(a2 - 427751306) |= a1;
  JUMPOUT(0x3F61AD38);
}

//------------------------------------------------------------------------------
// Address: 0x3F61AD62
// Name: _CallAssertFailedNotifyFunc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CallAssertFailedNotifyFunc@<eax>(char a1@<cf>, char a2@<bl>, int a3@<esi>)
{
  *(_BYTE *)(a3 - 62) += a2 + a1;
  __debugbreak();
  return ShouldUseNewAssertDialog();
}

//------------------------------------------------------------------------------
// Address: 0x3F61AD68
// Name: _ShouldUseNewAssertDialog
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void ShouldUseNewAssertDialog()
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  JUMPOUT(0x3F61AD6E);
}
