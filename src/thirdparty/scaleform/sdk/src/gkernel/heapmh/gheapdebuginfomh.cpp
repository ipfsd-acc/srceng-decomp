// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/heapmh/gheapdebuginfomh.cpp
// Functions: 16
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\heapmh\gheapdebuginfomh.h"

//------------------------------------------------------------------------------
// Address: 0x100D2CC0
// Name: private: void GHeapDebugStorageMH::unlinkDebugData(struct GHeapPageInfoMH __near *,struct GHeapDebugStorageMH::DebugDataPtr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapDebugStorageMH::unlinkDebugData(
        GHeapDebugStorageMH *this,
        struct GHeapPageInfoMH *a2,
        struct GHeapDebugStorageMH::DebugDataPtr *a3)
{
  int v3; // ecx
  int v4; // ecx
  int v5; // edx
  _DWORD *v6; // eax
  _DWORD *v7; // ecx

  --*(_WORD *)(*(_DWORD *)a3 + 8);
  v3 = *((_DWORD *)a3 + 3);
  if ( v3 != 0 )
  {
    *(_DWORD *)(v3 + 20) = *(_DWORD *)(*((_DWORD *)a3 + 2) + 20);
  }
  else
  {
    v4 = *(_DWORD *)(*((_DWORD *)a3 + 2) + 20);
    if ( v4 != 0 )
      *(_WORD *)(v4 + 8) = *(_WORD *)(*(_DWORD *)a3 + 8);
    v5 = *(_DWORD *)(*((_DWORD *)a3 + 2) + 20);
    if ( *(_DWORD *)a2 != 0 )
      **(_DWORD **)a2 = v5;
    v6 = *((_DWORD **)a2 + 1);
    if ( v6 != nullptr )
      *v6 = v5;
    v7 = *((_DWORD **)a2 + 2);
    if ( v7 != nullptr )
      *v7 = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2D20
// Name: private: void GHeapDebugStorageMH::linkDebugData(struct GHeapPageInfoMH __near *,struct GHeapDebugDataMH __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__stdcall GHeapDebugStorageMH::linkDebugData(int a1, int a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax
  _DWORD *result; // eax
  _DWORD *v6; // ecx

  v2 = 0;
  while ( *(_DWORD *)(a1 + 4 * v2) == 0 )
  {
    if ( ++v2 >= 3 )
    {
      v3 = a2;
      *(_DWORD *)(a2 + 20) = 0;
      goto LABEL_9;
    }
  }
  v4 = **(_DWORD **)(a1 + 4 * v2);
  if ( v4 != 0 )
  {
    v3 = a2;
    if ( a2 != v4 )
    {
      *(_DWORD *)(a2 + 20) = v4;
      *(_WORD *)(a2 + 8) = *(_WORD *)(v4 + 8);
    }
  }
  else
  {
    v3 = a2;
    *(_DWORD *)(a2 + 20) = 0;
  }
LABEL_9:
  if ( *(_DWORD *)a1 != 0 )
    **(_DWORD **)a1 = v3;
  result = *(_DWORD **)(a1 + 4);
  if ( result != nullptr )
    *result = v3;
  v6 = *(_DWORD **)(a1 + 8);
  if ( v6 != nullptr )
    *v6 = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D2D90
// Name: private: void GHeapDebugStorageMH::findDebugData(struct GHeapPageInfoMH __near *,unsigned int,struct GHeapDebugStorageMH::DebugDataPtr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapDebugStorageMH::findDebugData(
        GHeapDebugStorageMH *this,
        struct GHeapPageInfoMH *a2,
        unsigned int a3,
        struct GHeapDebugStorageMH::DebugDataPtr *a4)
{
  int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  unsigned int v7; // ecx

  v4 = 0;
  while ( *((_DWORD *)a2 + v4) == 0 )
  {
    if ( ++v4 >= 3 )
    {
      v5 = nullptr;
      goto LABEL_5;
    }
  }
  v5 = **((_DWORD ***)a2 + v4);
LABEL_5:
  v6 = nullptr;
  *(_DWORD *)a4 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      v7 = v5[7];
      if ( a3 >= v7 && a3 < v7 + v5[8] )
        break;
      v6 = v5;
      v5 = (_DWORD *)v5[5];
      if ( v5 == nullptr )
        return;
    }
    *((_DWORD *)a4 + 2) = v5;
    *((_DWORD *)a4 + 3) = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2DF0
// Name: public: void GHeapDebugStorageMH::RelinkAlloc(struct GHeapDebugStorageMH::DebugDataPtr __near *,unsigned int,unsigned int,unsigned int,struct GHeapPageInfoMH __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall GHeapDebugStorageMH::RelinkAlloc(
        _SECURITY_IMPERSONATION_LEVEL ptr,
        unsigned int oldAddr,
        unsigned int newAddr,
        unsigned int newSize,
        int a5)
{
  int v5; // esi
  unsigned int v6; // ecx
  unsigned int result; // eax
  int i; // edi

  *(_DWORD *)(*(_DWORD *)(ptr + 8) + 32) = newSize;
  *(_DWORD *)(*(_DWORD *)(ptr + 8) + 28) = newAddr;
  *(_WORD *)(*(_DWORD *)(ptr + 8) + 8) = 0;
  GHeapDebugStorageMH::linkDebugData(a1: a5, a2: *(_DWORD *)(ptr + 8));
  v5 = *(_DWORD *)(ptr + 8);
  v6 = *(_DWORD *)(a5 + 20);
  result = *(_DWORD *)(v5 + 32);
  for ( i = *(_DWORD *)(v5 + 28); result < v6; ++result )
    *(_BYTE *)(result + i) = result - 127;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D2E50
// Name: public: GHeapDebugStorageMH::GHeapDebugStorageMH(class GSysAlloc __near *,class GLockSafe __near *)
// Source: json
//------------------------------------------------------------------------------
IClientMaterialSystem_vtbl **__thiscall GHeapDebugStorageMH::GHeapDebugStorageMH(
        IClientMaterialSystem_vtbl **this,
        IClientMaterialSystem rootLocker,
        IClientMaterialSystem_vtbl *a3)
{
  IClientMaterialSystem_vtbl **result; // eax
  _DWORD *v4; // ecx

  result = this;
  *this = rootLocker.__vftable;
  v4 = this + 1;
  *v4 = v4;
  v4[1] = v4;
  result[3] = (IClientMaterialSystem_vtbl *)(result + 3);
  result[4] = (IClientMaterialSystem_vtbl *)(result + 3);
  result[5] = (IClientMaterialSystem_vtbl *)(result + 5);
  result[6] = (IClientMaterialSystem_vtbl *)(result + 5);
  result[7] = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D2E80
// Name: private: bool GHeapDebugStorageMH::allocDataPool(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GHeapDebugStorageMH::allocDataPool(_RTL_CRITICAL_SECTION **this)
{
  _RTL_CRITICAL_SECTION *v2; // ebx
  _RTL_CRITICAL_SECTION_DEBUG *v3; // esi
  _DWORD *v4; // eax
  unsigned int *p_EntryCount; // ecx
  int i; // edi
  _DWORD *v7; // edx

  v2 = *(this + 7);
  EnterCriticalSection(lpCriticalSection: v2);
  v3 = (_RTL_CRITICAL_SECTION_DEBUG *)((int (__thiscall *)(_RTL_CRITICAL_SECTION *, int, int))(*this)->DebugInfo->ProcessLocksList.Blink)(
                                        a1: *this,
                                        a2: 2048,
                                        a3: 4);
  LeaveCriticalSection(lpCriticalSection: v2);
  if ( v3 == nullptr )
    return 0;
  v3->ProcessLocksList.Flink = nullptr;
  v3->CriticalSection = *(this + 2);
  *(_DWORD *)&v3->Type = this + 1;
  (*(this + 2))->DebugInfo = v3;
  *(this + 2) = (_RTL_CRITICAL_SECTION *)v3;
  v4 = this + 5;
  p_EntryCount = &v3->EntryCount;
  for ( i = 10; i != 0; --i )
  {
    p_EntryCount[2] = (unsigned int)v3;
    *(p_EntryCount - 1) = *v4;
    *p_EntryCount = (unsigned int)v4;
    *(_DWORD *)(*v4 + 4) = p_EntryCount - 1;
    *v4 = p_EntryCount - 1;
    p_EntryCount[12] = (unsigned int)v3;
    p_EntryCount[9] = *v4;
    p_EntryCount[10] = (unsigned int)v4;
    *(_DWORD *)(*v4 + 4) = p_EntryCount + 9;
    *v4 = p_EntryCount + 9;
    p_EntryCount[22] = (unsigned int)v3;
    p_EntryCount[19] = *v4;
    p_EntryCount[20] = (unsigned int)v4;
    *(_DWORD *)(*v4 + 4) = p_EntryCount + 19;
    *v4 = p_EntryCount + 19;
    p_EntryCount[32] = (unsigned int)v3;
    p_EntryCount[29] = *v4;
    p_EntryCount[30] = (unsigned int)v4;
    *(_DWORD *)(*v4 + 4) = p_EntryCount + 29;
    *v4 = p_EntryCount + 29;
    p_EntryCount[42] = (unsigned int)v3;
    v7 = p_EntryCount + 39;
    p_EntryCount[39] = *v4;
    p_EntryCount[40] = (unsigned int)v4;
    p_EntryCount += 50;
    *(_DWORD *)(*v4 + 4) = v7;
    *v4 = v7;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D2F60
// Name: private: void GHeapDebugStorageMH::freeDataPool(struct GHeapDebugDataPoolMH<struct GHeapDebugDataMH> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapDebugStorageMH::freeDataPool(_RTL_CRITICAL_SECTION **this, _DWORD *a2)
{
  _DWORD *v3; // eax
  int i; // ecx
  _DWORD *v5; // edx
  int v6; // edi
  _RTL_CRITICAL_SECTION *v7; // edi

  v3 = a2 + 14;
  for ( i = 10; i != 0; --i )
  {
    *(_DWORD *)(*(v3 - 11) + 4) = *(v3 - 10);
    *(_DWORD *)*(v3 - 10) = *(v3 - 11);
    *(_DWORD *)(*(v3 - 1) + 4) = *v3;
    *(_DWORD *)*v3 = *(v3 - 1);
    *(_DWORD *)(v3[9] + 4) = v3[10];
    *(_DWORD *)v3[10] = v3[9];
    *(_DWORD *)(v3[19] + 4) = v3[20];
    *(_DWORD *)v3[20] = v3[19];
    *(_DWORD *)(v3[29] + 4) = v3[30];
    v5 = (_DWORD *)v3[30];
    v6 = v3[29];
    v3 += 50;
    *v5 = v6;
  }
  *(_DWORD *)(*a2 + 4) = a2[1];
  *(_DWORD *)a2[1] = *a2;
  v7 = *(this + 7);
  EnterCriticalSection(lpCriticalSection: v7);
  ((void (__thiscall *)(_RTL_CRITICAL_SECTION *, _DWORD *, int, int))(*this)->DebugInfo->EntryCount)(
    a1: *this,
    a2,
    a3: 2048,
    a4: 4);
  LeaveCriticalSection(lpCriticalSection: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100D3010
// Name: private: struct GHeapDebugDataMH __near * GHeapDebugStorageMH::allocDebugData(void)
// Source: json
//------------------------------------------------------------------------------
struct GHeapDebugDataMH *__thiscall GHeapDebugStorageMH::allocDebugData(GHeapDebugStorageMH **this)
{
  struct GHeapDebugDataMH *result; // eax
  int v3; // edx

  if ( *(this + 6) == (GHeapDebugStorageMH *)(this + 5)
    && GHeapDebugStorageMH::allocDataPool((_RTL_CRITICAL_SECTION **)this) == 0 )
  {
    return nullptr;
  }
  result = *(this + 6);
  *(_DWORD *)(*(_DWORD *)result + 4) = *((_DWORD *)result + 1);
  **((_DWORD **)result + 1) = *(_DWORD *)result;
  *((_DWORD *)result + 2) = 0;
  *((_DWORD *)result + 4) = 0;
  *((_DWORD *)result + 5) = 0;
  *((_DWORD *)result + 6) = 0;
  *((_DWORD *)result + 7) = 0;
  *((_DWORD *)result + 8) = 0;
  *((_DWORD *)result + 9) = 0;
  v3 = (int)*(this + 3);
  *((_DWORD *)result + 1) = this + 3;
  *(_DWORD *)result = v3;
  *((_DWORD *)*(this + 3) + 1) = result;
  *(this + 3) = result;
  ++*(_DWORD *)(*((_DWORD *)result + 3) + 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D3070
// Name: public: bool GHeapDebugStorageMH::AddAlloc(unsigned int,unsigned int,struct GHeapPageInfoMH __near *,struct GAllocDebugInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GHeapDebugStorageMH::AddAlloc(
        GHeapDebugStorageMH **this,
        unsigned int a2,
        unsigned int a3,
        struct GHeapPageInfoMH *a4,
        const struct GAllocDebugInfo *a5)
{
  struct GHeapDebugDataMH *v5; // eax
  struct GHeapDebugDataMH *v6; // esi
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int i; // edi
  unsigned int StatId; // [esp+10h] [ebp+8h]

  v5 = GHeapDebugStorageMH::allocDebugData(this);
  v6 = v5;
  if ( v5 == nullptr )
    return 0;
  *((_DWORD *)v5 + 7) = a2;
  *((_DWORD *)v5 + 6) = 1;
  *((_DWORD *)v5 + 8) = a3;
  if ( a5 != nullptr )
    StatId = a5->StatId;
  else
    StatId = 2;
  *((_DWORD *)v5 + 9) = StatId;
  GHeapDebugStorageMH::linkDebugData(a1: (int)a4, a2: (int)v5);
  v7 = *((_DWORD *)a4 + 5);
  v8 = *((_DWORD *)v6 + 8);
  for ( i = *((_DWORD *)v6 + 7); v8 < v7; ++v8 )
    *(_BYTE *)(v8 + i) = v8 - 127;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D30F0
// Name: public: bool GHeapDebugStorageMH::AddAlloc(struct GHeapPageInfoMH __near *,unsigned int,unsigned int,unsigned int,struct GHeapPageInfoMH __near *,struct GAllocDebugInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GHeapDebugStorageMH::AddAlloc(
        GHeapDebugStorageMH **this,
        struct GHeapPageInfoMH *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        struct GHeapPageInfoMH *a6,
        const struct GAllocDebugInfo *a7)
{
  struct GHeapDebugDataMH *v8; // eax
  struct GHeapDebugDataMH *v9; // esi
  unsigned int v10; // ecx
  unsigned int v11; // eax
  int i; // edi
  int v13; // eax
  _BYTE v15[8]; // [esp+8h] [ebp-10h] BYREF
  int v16; // [esp+10h] [ebp-8h]
  unsigned int StatId; // [esp+28h] [ebp+10h]

  v8 = GHeapDebugStorageMH::allocDebugData(this);
  v9 = v8;
  if ( v8 == nullptr )
    return 0;
  *((_DWORD *)v8 + 7) = a4;
  *((_DWORD *)v8 + 6) = 1;
  *((_DWORD *)v8 + 8) = a5;
  if ( a7 != nullptr )
    StatId = a7->StatId;
  else
    StatId = 2;
  *((_DWORD *)v8 + 9) = StatId;
  GHeapDebugStorageMH::linkDebugData(a1: (int)a6, a2: (int)v8);
  v10 = *((_DWORD *)a6 + 5);
  v11 = *((_DWORD *)v9 + 8);
  for ( i = *((_DWORD *)v9 + 7); v11 < v10; ++v11 )
    *(_BYTE *)(v11 + i) = v11 - 127;
  v16 = 0;
  GHeapDebugStorageMH::findDebugData(
    (GHeapDebugStorageMH *)this,
    a2,
    a3,
    a4: (struct GHeapDebugStorageMH::DebugDataPtr *)v15);
  v13 = v16;
  if ( *((_DWORD *)v9 + 9) == 2 )
    *((_DWORD *)v9 + 9) = *(_DWORD *)(v16 + 36);
  if ( *(_WORD *)(v13 + 10) > 0xBu )
    v13 = *(_DWORD *)(v13 + 16);
  *((_DWORD *)v9 + 4) = v13;
  *((_WORD *)v9 + 5) = *(_WORD *)(v13 + 10) + 1;
  ++*(_DWORD *)(v13 + 24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D31C0
// Name: public: void GHeapDebugStorageMH::RemoveAlloc(unsigned int,struct GHeapPageInfoMH __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapDebugStorageMH::RemoveAlloc(
        GHeapDebugStorageMH *this,
        unsigned int a2,
        struct GHeapPageInfoMH *a3)
{
  _DWORD *v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // edx
  _DWORD *v8; // ecx
  _DWORD *v9; // esi
  bool v10; // zf
  int v11; // edx
  _DWORD *v12; // esi
  int v13; // ecx
  int v14; // [esp+Ch] [ebp-10h] BYREF
  _DWORD *v15; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  v14 = 0;
  v15 = nullptr;
  v16 = 0;
  GHeapDebugStorageMH::findDebugData(this, a2: a3, a3: a2, a4: (struct GHeapDebugStorageMH::DebugDataPtr *)&v14);
  v4 = v15;
  *(_DWORD *)(*v15 + 4) = v15[1];
  *(_DWORD *)v4[1] = *v4;
  v5 = v14;
  --*(_WORD *)(v14 + 8);
  if ( v16 != 0 )
  {
    *(_DWORD *)(v16 + 20) = v4[5];
  }
  else
  {
    v6 = v4[5];
    if ( v6 != 0 )
      *(_WORD *)(v6 + 8) = *(_WORD *)(v5 + 8);
    v7 = v4[5];
    if ( *(_DWORD *)a3 != 0 )
      **(_DWORD **)a3 = v7;
    v8 = *((_DWORD **)a3 + 1);
    if ( v8 != nullptr )
      *v8 = v7;
    v9 = *((_DWORD **)a3 + 2);
    if ( v9 != nullptr )
      *v9 = v7;
  }
  do
  {
    v10 = v4[6]-- == 1;
    if ( !v10 )
      break;
    v11 = *((_DWORD *)this + 6);
    v12 = (_DWORD *)v4[4];
    *v4 = (char *)this + 20;
    v4[1] = v11;
    **((_DWORD **)this + 6) = v4;
    *((_DWORD *)this + 6) = v4;
    v13 = v4[3];
    v10 = (*(_DWORD *)(v13 + 8))-- == 1;
    if ( v10 )
      GHeapDebugStorageMH::freeDataPool((_RTL_CRITICAL_SECTION **)this, a2: (_DWORD *)v4[3]);
    v4 = v12;
  }
  while ( v12 != nullptr );
}

//------------------------------------------------------------------------------
// Address: 0x100D3290
// Name: public: void GHeapDebugStorageMH::UnlinkAlloc(unsigned int,struct GHeapPageInfoMH __near *,struct GHeapDebugStorageMH::DebugDataPtr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapDebugStorageMH::UnlinkAlloc(
        GHeapDebugStorageMH *this,
        unsigned int a2,
        struct GHeapPageInfoMH *a3,
        struct GHeapDebugStorageMH::DebugDataPtr *a4)
{
  GHeapDebugStorageMH::findDebugData(this, a2: a3, a3: a2, a4);
  GHeapDebugStorageMH::unlinkDebugData(this, a2: a3, a3: a4);
}

//------------------------------------------------------------------------------
// Address: 0x100D32C0
// Name: public: void GHeapDebugStorageMH::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapDebugStorageMH::FreeAll(GHeapDebugStorageMH *this)
{
  char **v2; // edi
  _DWORD *v3; // eax

  v2 = (char **)((char *)this + 4);
  if ( *((GHeapDebugStorageMH **)this + 2) != (GHeapDebugStorageMH *)((char *)this + 4) )
  {
    do
    {
      v3 = *((_DWORD **)this + 2);
      *(_DWORD *)(*v3 + 4) = v3[1];
      *(_DWORD *)v3[1] = *v3;
      (*(void (__thiscall **)(_DWORD, _DWORD *, int, _DWORD))(**(_DWORD **)this + 16))(
        a1: *(_DWORD *)this,
        a2: v3,
        a3: 2048,
        a4: 0);
    }
    while ( v2[1] != (char *)v2 );
  }
  *((_DWORD *)this + 3) = (char *)this + 12;
  *((_DWORD *)this + 4) = (char *)this + 12;
  *((_DWORD *)this + 5) = (char *)this + 20;
  *((_DWORD *)this + 6) = (char *)this + 20;
}

//------------------------------------------------------------------------------
// Address: 0x100D3310
// Name: public: void GHeapDebugStorageMH::GetStats(class GHeapAllocEngineMH __near *,class GStatBag __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapDebugStorageMH::GetStats(_DWORD *this, GHeapAllocEngineMH *a2, GStatBag *bag)
{
  _DWORD *v3; // esi
  _DWORD *i; // edi
  unsigned int v5; // eax

  v3 = (_DWORD *)*(this + 4);
  for ( i = this + 3; v3 != i; v3 = (_DWORD *)v3[1] )
  {
    GHeapAllocEngineMH::GetUsableSize(this: a2, addr: v3[7]);
    GStatBag::IncrementMemoryStat(this: bag, statId: v3[9], a3: v3[8], a4: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3350
// Name: public: bool GHeapDebugStorageMH::DumpMemoryLeaks(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GHeapDebugStorageMH::DumpMemoryLeaks(_DWORD *this, int a2)
{
  _DWORD *v2; // edx
  _DWORD *v3; // ecx
  char result; // al

  v2 = (_DWORD *)*(this + 4);
  v3 = this + 3;
  result = 0;
  if ( v2 != v3 )
  {
    result = 1;
    do
      v2 = (_DWORD *)v2[1];
    while ( v2 != v3 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D3370
// Name: public: unsigned int GHeapDebugStorageMH::GetUsedSpace(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GHeapDebugStorageMH::GetUsedSpace(GHeapDebugStorageMH *this)
{
  int v1; // edx
  char *v2; // ecx
  unsigned int result; // eax

  v1 = *((_DWORD *)this + 2);
  v2 = (char *)this + 4;
  for ( result = 0; (char *)v1 != v2; result += 2048 )
    v1 = *(_DWORD *)(v1 + 4);
  return result;
}
