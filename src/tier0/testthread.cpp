// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/testthread.cpp
// Functions: 25
// ============================================================

#include "tier0\testthread.h"

//------------------------------------------------------------------------------
// Address: 0x3F0072E0
// Name: public: void CTestHarness::Init(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CTestHarness::Init(CTestHarness *this@<ecx>, int a2@<ebx>)
{
  int v2; // ecx

  --*(_DWORD *)(a2 - 1207688116);
  MEMORY[0xA33F7706](a1: this);
  MEMORY[0] = v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F0073B0
// Name: public: void CTestHarness::TerminateThread(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CTestHarness::TerminateThread(CTestHarness *this@<ecx>, int a2@<eax>, int a3@<ebp>)
{
  void (__thiscall *v3)(void *); // [esp-Ch] [ebp-Ch]
  void (__thiscall *v4)(void *); // [esp-8h] [ebp-8h]

  dword_3F0A1DD8 = a2;
  dword_3F0A1DDC = a2;
  dword_3F0A1DE0 = a2;
  dword_3F0A1DE4 = a2;
  `eh vector constructor iterator'(a1: &unk_3F0A1DF8, a2: 0x18u, a3: 256, a4: v3, a5: v4);
  *(_DWORD *)(a3 - 4) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F007410
// Name: private: void CTestHarness::TestThread(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTestHarness::TestThread(CTestHarness *this@<ecx>, int a2@<ebp>)
{
  *(_DWORD *)(a2 - 16) = &unk_3F0A1DC8;
  *(_DWORD *)(a2 - 4) = 0;
  `eh vector destructor iterator'(
    a1: &unk_3F0A1DF8,
    a2: 0x18u,
    a3: 256,
    a4: (void (__thiscall *)(void *))Plat_RegisterThread);
  *(_DWORD *)(a2 - 4) = -1;
  sub_3F0043F0(this: (CSmallBlockHeap *)&dword_3F0A1DD0);
}

//------------------------------------------------------------------------------
// Address: 0x3F007490
// Name: private: static unsigned long CTestHarness::TestThreadProxy(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CTestHarness::TestThreadProxy(void *pvArg)
{
  dword_3F041DA0 = 0;
  JUMPOUT(0x3F00749E);
}

//------------------------------------------------------------------------------
// Address: 0x3F0074A0
// Name: _Test_RunTest
// Source: json
//------------------------------------------------------------------------------
void __usercall Test_RunTest(char a1@<cf>, int a2@<eax>, int a3@<ebp>)
{
  dword_3F041DA8 = a2 - (a1 + 1166622468);
  dword_3F041DAC = a2 - (a1 + 1166622468);
  dword_3F041DB0 = a2 - (a1 + 1166622468);
  dword_3F041DB4 = a2 - (a1 + 1166622468);
  `eh vector constructor iterator'(
    a1: &unk_3F041DC8,
    a2: 0x18u,
    a3: 0x4000,
    a4: (void (__thiscall *)(void *))Plat_GetCurrentThreadID,
    a5: (void (__thiscall *)(void *))Plat_RegisterThread);
  *(_DWORD *)(a3 - 4) = -1;
  JUMPOUT(0x3F0074F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F007500
// Name: _Test_RunFrame
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F007510
// Name: _TestThread_Yield
// Source: json
//------------------------------------------------------------------------------
void __usercall TestThread_Yield(int a1@<ebp>)
{
  *(_DWORD *)(a1 - 16) = &unk_3F041D98;
  *(_DWORD *)(a1 - 4) = 0;
  `eh vector destructor iterator'(
    a1: &unk_3F041DC8,
    a2: 0x18u,
    a3: 0x4000,
    a4: (void (__thiscall *)(void *))Plat_RegisterThread);
  *(_DWORD *)(a1 - 4) = -1;
  sub_3F0043F0(this: (CSmallBlockHeap *)&dword_3F041DA0);
}

//------------------------------------------------------------------------------
// Address: 0x3F007570
// Name: _Test_SetFailed
// Source: json
//------------------------------------------------------------------------------
void Test_SetFailed()
{
  JUMPOUT(0x3F007578);
}

//------------------------------------------------------------------------------
// Address: 0x3F007580
// Name: _Test_HasFailed
// Source: json
//------------------------------------------------------------------------------
void __usercall Test_HasFailed(int a1@<ebp>)
{
  *(_DWORD *)(a1 - 16) = &unk_3F041BE8;
  JUMPOUT(0x3F007587);
}

//------------------------------------------------------------------------------
// Address: 0x3F007590
// Name: _Test_HasFinished
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0075B0
// Name: _Test_IsActive
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0075C0
// Name: _Test_TerminateThread
// Source: json
//------------------------------------------------------------------------------
void __usercall Test_TerminateThread(char a1@<cf>, int a2@<eax>, int a3@<edi>)
{
  dword_3F041BFC = a2 - (a1 + *(_DWORD *)(2 * a3));
  JUMPOUT(0x3F0075C8);
}

//------------------------------------------------------------------------------
// Address: 0x3F00EED0
// Name: Test_RunTest
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_RunTest(int a1, int a2)
{
  CVProfNode *v2; // ecx

  ((void (__cdecl *)(int, int))loc_3F00ED10)(a1, a2);
  CVProfNode::Reset(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x3F00EEF0
// Name: Test_RunFrame
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall Test_RunFrame(CVProfNode *this, int a2, int a3)
{
  JUMPOUT(0x3F00ED70);
}

//------------------------------------------------------------------------------
// Address: 0x3F00EF70
// Name: Test_SetFailed
// Source: json
//------------------------------------------------------------------------------
void Test_SetFailed()
{
  byte_3F0415BB = 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EF80
// Name: Test_HasFailed
// Source: json
//------------------------------------------------------------------------------
char Test_HasFailed()
{
  return byte_3F0415BB;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EF90
// Name: Test_HasFinished
// Source: json
//------------------------------------------------------------------------------
void __thiscall Test_HasFinished(CVProfNode *this)
{
  if ( byte_3F0415B8 != 0 )
    JUMPOUT(0x3F00EFA8);
  CVProfNode::ResetPeak(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F00EFB0
// Name: Test_IsActive
// Source: json
//------------------------------------------------------------------------------
BOOL Test_IsActive()
{
  return dword_3F0415B4 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EFC0
// Name: Test_TerminateThread
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall Test_TerminateThread(CVProfNode *this)
{
  JUMPOUT(0x3F00EE40);
}

//------------------------------------------------------------------------------
// Address: 0x3F007360
// Name: sub_3F007360
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F007560
// Name: sub_3F007560
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F007560()
{
  Test_SetFailed();
}

//------------------------------------------------------------------------------
// Address: 0x3F00EEE0
// Name: ?Reset@CVProfNode@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfNode::Reset(CVProfNode *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EF30
// Name: ?MarkFrame@CVProfNode@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfNode::MarkFrame(CVProfNode *this)
{
  if ( byte_3F0415B9 != 0 )
    ExitThread(dwExitCode: 0);
  byte_3F0415BA = 1;
  WaitForSingleObject(hHandle: hEvent, dwMilliseconds: 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x3F00EFA0
// Name: ?ResetPeak@CVProfNode@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfNode::ResetPeak(CVProfNode *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EFD0
// Name: ?SetCurFrameTime@CVProfNode@@QAEXK@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfNode::SetCurFrameTime(CVProfNode *this, unsigned int milliseconds)
{
  JUMPOUT(0x3F00F017);
}
