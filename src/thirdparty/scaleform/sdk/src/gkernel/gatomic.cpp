// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gatomic.cpp
// Functions: 2
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gatomic.h"

//------------------------------------------------------------------------------
// Address: 0x10064600
// Name: public: GLock::GLock(unsigned int)
// Source: json
//------------------------------------------------------------------------------
GLock *__thiscall GLock::GLock(LPCRITICAL_SECTION lpCriticalSection, DWORD spinCount)
{
  HMODULE LibraryA; // eax
  BOOL (__stdcall *InitializeCriticalSectionAndSpinCount)(LPCRITICAL_SECTION, DWORD); // eax

  if ( initTried )
  {
    InitializeCriticalSectionAndSpinCount = *(BOOL (__stdcall **)(LPCRITICAL_SECTION, DWORD))pInitFn;
  }
  else
  {
    LibraryA = LoadLibraryA(lpLibFileName: "kernel32.dll");
    InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))GetProcAddress(
                                                                                             hModule: LibraryA,
                                                                                             lpProcName: "InitializeCriticalSectionAndSpinCount");
    *(_DWORD *)pInitFn = InitializeCriticalSectionAndSpinCount;
    initTried = true;
  }
  if ( InitializeCriticalSectionAndSpinCount != nullptr )
    InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount: spinCount);
  else
    InitializeCriticalSection(lpCriticalSection);
  return (GLock *)lpCriticalSection;
}

//------------------------------------------------------------------------------
// Address: 0x10064660
// Name: public: GLock::~GLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GLock::~GLock(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}
