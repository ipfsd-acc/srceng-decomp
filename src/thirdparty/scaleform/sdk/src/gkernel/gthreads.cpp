// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gthreads.cpp
// Functions: 20
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gthreads.h"

//------------------------------------------------------------------------------
// Address: 0x100D1DA0
// Name: public: bool GEvent::Wait(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GEvent::Wait(CDbgFmtMsg *this, DWORD delay)
{
  CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CFuncMemPolicyNone> *v3; // edi
  char v4; // bl

  v3 = (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CFuncMemPolicyNone> *)&this->m_szBuf[20];
  GMutex::Lock(this: (IMatRenderContextInternal *)&this->m_szBuf[20]);
  if ( delay != 0 )
  {
    if ( delay == -1 )
    {
      while ( this->m_szBuf[16] == 0 )
        GWaitCondition::Wait(
          this: (GWaitCondition *)&this->m_szBuf[40],
          a2: (const MaterialNonInteractiveMode_t *)this,
          a3: v3,
          a4: 0xFFFFFFFF);
    }
    else if ( this->m_szBuf[16] == 0 )
    {
      GWaitCondition::Wait(
        this: (GWaitCondition *)&this->m_szBuf[40],
        a2: (const MaterialNonInteractiveMode_t *)this,
        a3: v3,
        a4: delay);
    }
  }
  v4 = this->m_szBuf[16];
  if ( this->m_szBuf[17] != 0 )
  {
    this->m_szBuf[17] = 0;
    this->m_szBuf[16] = 0;
  }
  GMutex::Unlock(this: (IMatRenderContextInternal *)v3);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100D1E20
// Name: public: void GEvent::ResetEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEvent::ResetEvent(int this, const CDbgFmtMsg *result)
{
  GMutex::Lock(this: (IMatRenderContextInternal *)(this + 20));
  *(_BYTE *)(this + 16) = 0;
  *(_BYTE *)(this + 17) = 0;
  JUMPOUT(0x100D1770);
}

//------------------------------------------------------------------------------
// Address: 0x100D1E40
// Name: public: virtual bool GEvent::IsSignaled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GEvent::IsSignaled(GEvent *this)
{
  return this->State;
}

//------------------------------------------------------------------------------
// Address: 0x100D1E50
// Name: public: virtual bool GEvent::CanAcquire(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEvent::CanAcquire(_DWORD *this, int a2)
{
  (*(void (__thiscall **)(_DWORD *, int))(*(this - 3) + 4))(a1: this - 3, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100D1E60
// Name: public: virtual bool GEvent::TryAcquireCommit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GEvent::TryAcquireCommit(int this)
{
  GMutex::Lock(this: (IMatRenderContextInternal *)(this + 8));
  if ( *(_BYTE *)(this + 5) != 0 )
  {
    *(_BYTE *)(this + 5) = 0;
    *(_BYTE *)(this + 4) = 0;
  }
  GMutex::Unlock(this: (IMatRenderContextInternal *)(this + 8));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D1F20
// Name: public: virtual class GAcquireInterface __near * GWaitable::GetAcquireInterface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GWaitable::GetAcquireInterface(CThreadFastMutex *this)
{
  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    dword_10359410 = (int)&GAcquireInterface::`vftable';
    atexit(func: (void (__cdecl *)())GDefaultAcquireInterface::GetDefaultAcquireInterface_::_2_::_dynamic_atexit_destructor_for__di__);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2020
// Name: public: GWaitable::GWaitable(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GWaitable::GWaitable(
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CFuncMemPolicyNone> *this@<ecx>,
        CMatRenderContextBase *enable,
        __int128 a3)
{
  char *v4; // eax
  _DWORD *v5; // edi
  int v6; // [esp+4h] [ebp-4h] BYREF

  LODWORD(this->m_pfnProxied) = &GRefCountImplCore::`vftable';
  DWORD1(this->m_pfnProxied) = 1;
  LODWORD(this->m_pfnProxied) = &GWaitable::`vftable';
  if ( (_BYTE)enable != 0 )
  {
    v6 = 2;
    v4 = (char *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &v6);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *((_DWORD *)v4 + 1) = 0;
      *((_DWORD *)v4 + 2) = 0;
      *((_DWORD *)v4 + 3) = 0;
      GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)(v4 + 16), spinCount: 0);
      *v5 = 1;
      DWORD2(this->m_pfnProxied) = v5;
    }
    else
    {
      DWORD2(this->m_pfnProxied) = 0;
    }
  }
  else
  {
    DWORD2(this->m_pfnProxied) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D20B0
// Name: public: bool GWaitable::AddWaitHandler(void (*)(void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GWaitable::AddWaitHandler(GWaitable *this, void (__cdecl *a2)(void *), void *pdata)
{
  GWaitable::HandlerArray *pHandlers; // eax
  _RTL_CRITICAL_SECTION *p_cs; // ebx
  GWaitable::HandlerArray *v7; // esi
  unsigned int Size; // edi
  CThreadFastMutex *p_Handlers; // esi
  unsigned int v10; // edi
  _DWORD *v11; // eax

  pHandlers = this->pHandlers;
  if ( pHandlers == nullptr )
    return 0;
  p_cs = &pHandlers->HandlersLock.cs;
  EnterCriticalSection(lpCriticalSection: &pHandlers->HandlersLock.cs);
  v7 = this->pHandlers;
  Size = v7->Handlers.Data.Size;
  p_Handlers = (CThreadFastMutex *)&v7->Handlers;
  v10 = Size + 1;
  if ( v10 >= p_Handlers->m_depth )
  {
    if ( v10 >= p_Handlers[1].m_ownerID )
      GArrayDataBase<GWaitable::HandlerStruct,GAllocatorGH<GWaitable::HandlerStruct,2>,GArrayConstPolicy<0,16,1>>::Reserve(
        this: p_Handlers,
        pheapAddr: (ButtonCode_t)p_Handlers,
        newCapacity: v10 + (v10 >> 2));
  }
  else if ( v10 < p_Handlers[1].m_ownerID >> 1 )
  {
    GArrayDataBase<GWaitable::HandlerStruct,GAllocatorGH<GWaitable::HandlerStruct,2>,GArrayConstPolicy<0,16,1>>::Reserve(
      this: p_Handlers,
      pheapAddr: (ButtonCode_t)p_Handlers,
      newCapacity: v10);
  }
  v11 = (_DWORD *)(p_Handlers->m_ownerID + 8 * v10 - 8);
  p_Handlers->m_depth = v10;
  if ( v11 != nullptr )
  {
    *v11 = a2;
    v11[1] = pdata;
  }
  LeaveCriticalSection(lpCriticalSection: p_cs);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D2130
// Name: public: bool GWaitable::RemoveWaitHandler(void (*)(void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GWaitable::RemoveWaitHandler(GWaitable *this, void (__cdecl *a2)(void *), void *pdata)
{
  GWaitable::HandlerArray *pHandlers; // eax
  _RTL_CRITICAL_SECTION *p_cs; // edi
  GWaitable::HandlerArray *v7; // ecx
  unsigned int Size; // edx
  unsigned int v9; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),CFuncMemPolicyNone> *p_Handlers; // esi
  GWaitable::HandlerStruct *Data; // ecx
  int v12; // ecx

  pHandlers = this->pHandlers;
  if ( pHandlers == nullptr )
    return 0;
  p_cs = &pHandlers->HandlersLock.cs;
  EnterCriticalSection(lpCriticalSection: &pHandlers->HandlersLock.cs);
  v7 = this->pHandlers;
  Size = v7->Handlers.Data.Size;
  v9 = 0;
  if ( Size != 0 )
  {
    p_Handlers = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),CFuncMemPolicyNone> *)&v7->Handlers;
    Data = v7->Handlers.Data.Data;
    while ( Data->Handler != a2 || Data->pUserData != pdata )
    {
      ++v9;
      ++Data;
      if ( v9 >= Size )
        goto LABEL_8;
    }
    v12 = DWORD1(p_Handlers->m_pfnProxied);
    if ( v12 == 1 )
    {
      GArrayData<GWaitable::HandlerStruct,GAllocatorGH<GWaitable::HandlerStruct,2>,GArrayConstPolicy<0,16,1>>::Resize(
        this: p_Handlers,
        newSize: 0);
    }
    else
    {
      memmove(
        dst: (unsigned __int8 *)(LODWORD(p_Handlers->m_pfnProxied) + 8 * v9),
        src: (unsigned __int8 *)(LODWORD(p_Handlers->m_pfnProxied) + 8 * v9 + 8),
        count: 8 * (v12 - v9) - 8);
      --DWORD1(p_Handlers->m_pfnProxied);
    }
    LeaveCriticalSection(lpCriticalSection: p_cs);
    return 1;
  }
  else
  {
LABEL_8:
    LeaveCriticalSection(lpCriticalSection: p_cs);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2200
// Name: public: void GWaitable::HandlerArray::Release(void)
// Source: json
//------------------------------------------------------------------------------
CMatLightmaps *__thiscall GWaitable::HandlerArray::Release(int this)
{
  CMatLightmaps *v2; // eax

  v2 = (CMatLightmaps *)(InterlockedExchangeAdd(Addend: (volatile LONG *)this, Value: -1) - 1);
  if ( v2 == nullptr && this != 0 )
  {
    GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)(this + 16));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 4));
    return ((CMatLightmaps *(__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: this);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100D2240
// Name: public: void GWaitable::HandlerArray::CallWaitHandlers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GWaitable::HandlerArray::CallWaitHandlers(int this)
{
  _RTL_CRITICAL_SECTION *v2; // ebx
  int v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // ebx
  void (__cdecl **v6)(_DWORD); // edi
  _DWORD *v7; // [esp-8h] [ebp-24h]
  unsigned int v8; // [esp-4h] [ebp-20h]
  void (__cdecl **v9)(_DWORD); // [esp+Ch] [ebp-10h] BYREF
  unsigned int v10; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h]
  _RTL_CRITICAL_SECTION *v12; // [esp+18h] [ebp-4h]

  v2 = (_RTL_CRITICAL_SECTION *)(this + 16);
  v12 = (_RTL_CRITICAL_SECTION *)(this + 16);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 16));
  v3 = *(_DWORD *)(this + 8);
  v4 = 0;
  if ( v3 != 0 )
  {
    if ( v3 == 1 )
    {
      (**(void (__cdecl ***)(_DWORD))(this + 4))(a1: *(_DWORD *)(*(_DWORD *)(this + 4) + 4));
      LeaveCriticalSection(lpCriticalSection: v2);
      return;
    }
    v8 = *(_DWORD *)(this + 8);
    v7 = *(_DWORD **)(this + 4);
    v9 = nullptr;
    v10 = 0;
    v11 = 0;
    GArrayData<GWaitable::HandlerStruct,GAllocatorGH<GWaitable::HandlerStruct,2>,GArrayConstPolicy<0,16,1>>::Append(
      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),CFuncMemPolicyNone> *)&v9,
      other: v7,
      count: v8);
    v5 = v10;
    v6 = v9;
    if ( v10 != 0 )
    {
      do
      {
        v6[2 * v4](a1: v6[2 * v4 + 1]);
        ++v4;
      }
      while ( v4 < v5 );
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
    v2 = v12;
  }
  LeaveCriticalSection(lpCriticalSection: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100D22E0
// Name: public: void GWaitable::CallWaitHandlers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GWaitable::CallWaitHandlers(
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CFuncMemPolicyNone> *this)
{
  int v1; // ecx

  v1 = DWORD2(this->m_pfnProxied);
  if ( v1 != 0 )
    GWaitable::HandlerArray::CallWaitHandlers(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100D22F0
// Name: public: virtual GWaitable::~GWaitable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GWaitable::~GWaitable(
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CFuncMemPolicyNone> *this)
{
  int v2; // esi

  v2 = DWORD2(this->m_pfnProxied);
  LODWORD(this->m_pfnProxied) = &GWaitable::`vftable';
  if ( v2 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)v2, Value: -1) == 1 )
  {
    GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)(v2 + 16));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(v2 + 4));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  }
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100D2350
// Name: public: GEvent::GEvent(bool,bool)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100D23B0
// Name: public: virtual GEvent::~GEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEvent::~GEvent(int this)
{
  int v2; // edi
  const MaterialNonInteractiveMode_t *v3; // [esp+0h] [ebp-8h]

  *(_DWORD *)this = &GEvent::`vftable'{for `GWaitable'};
  *(_DWORD *)(this + 12) = &GEvent::`vftable'{for `GAcquireInterface'};
  GWaitCondition::~GWaitCondition(this: (CUtlVector<int,CUtlMemory<int,int> > *)(this + 40));
  GMutex::~GMutex(this: (IMatRenderContextInternal *)(this + 20), a2: v3);
  v2 = *(_DWORD *)(this + 8);
  *(_DWORD *)(this + 12) = &GAcquireInterface::`vftable';
  *(_DWORD *)this = &GWaitable::`vftable';
  if ( v2 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)v2, Value: -1) == 1 )
  {
    GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)(v2 + 16));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(v2 + 4));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  }
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100D2430
// Name: public: void GEvent::PulseEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GEvent::PulseEvent(int a1@<ecx>, CMatLightmaps *a2@<edi>)
{
  volatile LONG *v3; // esi
  volatile LONG *Addend; // [esp+8h] [ebp-4h] BYREF

  GMutex::Lock(this: (IMatRenderContextInternal *)(a1 + 20));
  *(_BYTE *)(a1 + 16) = 1;
  *(_BYTE *)(a1 + 17) = 1;
  GWaitCondition::Notify(this: (CUtlVector<int,CUtlMemory<int,int> > *)(a1 + 40));
  Addend = nullptr;
  GWaitable::GetCallableHandlers(this: (GWaitable *)a1, a2, a3: (struct GWaitable::CallableHandlers *)&Addend);
  GMutex::Unlock(this: (IMatRenderContextInternal *)(a1 + 20));
  v3 = Addend;
  if ( Addend != nullptr )
  {
    GWaitable::HandlerArray::CallWaitHandlers(this: (int)Addend);
    if ( InterlockedExchangeAdd(Addend: v3, Value: -1) == 1 )
    {
      GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)(v3 + 4));
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)v3 + 1));
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2530
// Name: void GWaitable_SingleWaitHandler(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall GWaitable_SingleWaitHandler(CMatLightmaps *a1@<edi>, int *hdataa)
{
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)*hdataa + 4))(a1: *hdataa) != 0 )
    GEvent::PulseEvent(a1: hdataa[1], a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x100D2560
// Name: public: bool GWaitable::Wait(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GWaitable::Wait(GWaitable *this, DWORD result)
{
  bool (__thiscall *IsSignaled)(GWaitable *); // edx
  int v6; // ebx
  void *v7; // ecx
  DWORD v8; // edi
  int v9; // eax
  int v10; // edx
  void *v11; // ecx
  int v12; // eax
  DWORD v13; // eax
  CMemberFuncProxyBase<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(void),CFuncMemPolicyNone> *event; // [esp+4h] [ebp-40h] BYREF
  int v15; // [esp+8h] [ebp-3Ch]
  int v16; // [esp+Ch] [ebp-38h]
  void **v17; // [esp+10h] [ebp-34h]
  char v18; // [esp+14h] [ebp-30h]
  char v19; // [esp+15h] [ebp-2Fh]
  IMatRenderContextInternal v20; // [esp+18h] [ebp-2Ch] BYREF
  CUtlVector<int,CUtlMemory<int,int> > v21; // [esp+2Ch] [ebp-18h] BYREF
  GWaitable *v22; // [esp+40h] [ebp-4h]
  char result_3; // [esp+4Fh] [ebp+Bh]

  IsSignaled = this->IsSignaled;
  v22 = this;
  if ( ((unsigned __int8 (__fastcall *)(GWaitable *))IsSignaled)(a1: this) != 0 )
    return 1;
  v6 = 0;
  if ( result == 0 )
    return 0;
  v15 = 1;
  v16 = 0;
  event = (CMemberFuncProxyBase<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(void),CFuncMemPolicyNone> *)&GEvent::`vftable'{for `GWaitable'};
  v17 = &GEvent::`vftable'{for `GAcquireInterface'};
  GMutex::GMutex(this: &v20, recursive: 1);
  GWaitCondition::GWaitCondition(this: &v21);
  v18 = 0;
  v19 = 0;
  v21.m_Size = (int)this;
  v21.m_pElements = (int *)&event;
  if ( GWaitable::AddWaitHandler(this, a2: (void (__cdecl *)(void *))GWaitable_SingleWaitHandler, pdata: &v21.m_Size) == 0 )
  {
    GEvent::~GEvent(this: (int)&event);
    return 0;
  }
  if ( this->IsSignaled(this) )
  {
    GWaitable::RemoveWaitHandler(this, a2: (void (__cdecl *)(void *))GWaitable_SingleWaitHandler, pdata: &v21.m_Size);
    GEvent::~GEvent(this: (int)&event);
    return 1;
  }
  else
  {
    result_3 = 0;
    v21.m_Memory.m_nGrowSize = 0;
    v8 = result;
    if ( result != -1 )
    {
      GTimer::GetTicks(this: v7);
      v6 = v9;
      v21.m_Memory.m_nGrowSize = v10;
    }
    if ( GEvent::Wait(this: (CDbgFmtMsg *)&event, delay: result) != 0 )
    {
      while ( !v22->IsSignaled(this: v22) )
      {
        if ( result != -1 )
        {
          GTimer::GetTicks(this: v11);
          v13 = v12 - v6;
          if ( v13 >= result )
            goto LABEL_19;
          v8 = result - v13;
        }
        if ( GEvent::Wait(this: (CDbgFmtMsg *)&event, delay: v8) == 0 )
          goto LABEL_19;
      }
      result_3 = 1;
    }
LABEL_19:
    GWaitable::RemoveWaitHandler(
      this: v22,
      a2: (void (__cdecl *)(void *))GWaitable_SingleWaitHandler,
      pdata: &v21.m_Size);
    GEvent::~GEvent(this: (int)&event);
    return result_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D26E0
// Name: public: void GEvent::SetEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GEvent::SetEvent(int a1@<ecx>, CMatLightmaps *a2@<edi>)
{
  volatile LONG *v3; // esi
  volatile LONG *Addend; // [esp+8h] [ebp-4h] BYREF

  GMutex::Lock(this: (IMatRenderContextInternal *)(a1 + 20));
  *(_BYTE *)(a1 + 16) = 1;
  *(_BYTE *)(a1 + 17) = 0;
  GWaitCondition::NotifyAll(this: (CUtlVector<int,CUtlMemory<int,int> > *)(a1 + 40));
  Addend = nullptr;
  GWaitable::GetCallableHandlers(this: (GWaitable *)a1, a2, a3: (struct GWaitable::CallableHandlers *)&Addend);
  GMutex::Unlock(this: (IMatRenderContextInternal *)(a1 + 20));
  v3 = Addend;
  if ( Addend != nullptr )
  {
    GWaitable::HandlerArray::CallWaitHandlers(this: (int)Addend);
    if ( InterlockedExchangeAdd(Addend: v3, Value: -1) == 1 )
    {
      GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)(v3 + 4));
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)v3 + 1));
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028CAB0
// Name: _GDefaultAcquireInterface::GetDefaultAcquireInterface_::_2_::_dynamic_atexit_destructor_for__di__
// Source: json
//------------------------------------------------------------------------------
void GDefaultAcquireInterface::GetDefaultAcquireInterface_::_2_::_dynamic_atexit_destructor_for__di__()
{
  dword_10359410 = (int)&GAcquireInterface::`vftable';
}
