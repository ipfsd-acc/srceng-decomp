// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/amp/gfxampthreadmgr.cpp
// Functions: 21
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\amp\gfxampthreadmgr.h"

//------------------------------------------------------------------------------
// Address: 0x100FC120
// Name: public: void GFxAmpThreadMgr::SetBroadcastInfo(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpThreadMgr::SetBroadcastInfo(GFxAmpThreadMgr *this, char *a2, char *a3)
{
  _RTL_CRITICAL_SECTION *v4; // edi

  v4 = (_RTL_CRITICAL_SECTION *)((char *)this + 24);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this + 1);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 52),
    (unsigned __int8 *)a2);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 56),
    a2: (unsigned __int8 *)a3);
  LeaveCriticalSection(lpCriticalSection: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100FC160
// Name: public: bool GFxAmpThreadMgr::IsValidSocket(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxAmpThreadMgr::IsValidSocket(CMaterial_QueueFriendly *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  bool IsValid; // bl

  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 140);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
  IsValid = GFxSocket::IsValid(this: this + 4);
  LeaveCriticalSection(lpCriticalSection: v2);
  return IsValid;
}

//------------------------------------------------------------------------------
// Address: 0x100FC190
// Name: private: void GFxAmpThreadMgr::GFxAmpMsgQueue::CheckSize(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall GFxAmpThreadMgr::GFxAmpMsgQueue::CheckSize(
        GFxAmpThreadMgr::GFxAmpMsgQueue *this,
        struct GMemoryHeap *a2)
{
  unsigned int Limit; // edi
  unsigned int v4; // edi
  const CDbgFmtMsg *v5; // [esp-Ch] [ebp-10h]

  if ( *((_DWORD *)this + 9) != 0 )
  {
    Limit = a2->Info.Desc.Limit;
    if ( Limit != 0 )
    {
      if ( 100 * (int)a2->GetFootprint(this: a2) >= Limit * *((_DWORD *)this + 10) )
      {
        v4 = a2->Info.Desc.Limit;
        if ( a2->GetFootprint(this: a2) > v4 )
          GEvent::ResetEvent(this: *((_DWORD *)this + 9), result: v5);
      }
      else
      {
        GEvent::SetEvent(a1: *((_DWORD *)this + 9), a2: (CMatLightmaps *)Limit);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC1F0
// Name: private: bool GFxAmpThreadMgr::BroadcastRecvLoop(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpThreadMgr::BroadcastRecvLoop(GFxAmpThreadMgr *this)
{
  char v2; // al
  char v4; // bl
  signed int v5; // edi
  GFxAmpStream *v6; // eax
  struct GFxAmpStream *v7; // ebx
  int v8; // eax
  unsigned int v9; // edx
  struct GMemoryHeap *v10; // eax
  IShaderAPI *Message; // edi
  char v12; // bl
  struct GFxSocketImplFactory *v13; // [esp-4h] [ebp-324h]
  int v14; // [esp+4h] [ebp-31Ch] BYREF
  _BYTE v15[12]; // [esp+8h] [ebp-318h] BYREF
  unsigned int v16; // [esp+14h] [ebp-30Ch] BYREF
  unsigned int v17; // [esp+18h] [ebp-308h] BYREF
  char v18[512]; // [esp+1Ch] [ebp-304h] BYREF
  char v19[256]; // [esp+21Ch] [ebp-104h] BYREF

  v13 = *((struct GFxSocketImplFactory **)this + 77);
  v2 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 76) + 40))(a1: *((_DWORD *)this + 76));
  GFxBroadcastSocket::GFxBroadcastSocket(this: (GFxBroadcastSocket *)v15, a2: v2, a3: v13);
  if ( GFxBroadcastSocket::Create(this: (GFxBroadcastSocket *)v15, a2: *((_DWORD *)this + 15), a3: false) != 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
    v4 = *((_BYTE *)this + 164);
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
    if ( v4 == 0 )
    {
      do
      {
        v5 = GFxBroadcastSocket::Receive(this: (GFxBroadcastSocket *)v15, a2: v18, a3: 512);
        if ( v5 <= 0 )
        {
          GThread::MSleep(msecs: 0x64u);
        }
        else
        {
          v14 = 2;
          v6 = (GFxAmpStream *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: this,
                                 a3: 24,
                                 a4: &v14);
          if ( v6 != nullptr )
            v7 = GFxAmpStream::GFxAmpStream(this: v6, a2: (unsigned __int8 *)v18, a3: v5);
          else
            v7 = nullptr;
          if ( GFxAmpStream::FirstMessageSize(this: v7) == v5 )
          {
            GFxBroadcastSocket::GetName(this: (GFxBroadcastSocket *)v15, a2: &v17, a3: &v16, a4: v19, a5: 0x100u);
            v8 = *((_DWORD *)this + 76);
            v9 = v17;
            *(_DWORD *)(v8 + 12) = v16;
            *(_DWORD *)(v8 + 8) = v9;
            GString::operator=(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v8 + 16),
              a2: (unsigned __int8 *)v19);
            v10 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
            Message = (IShaderAPI *)GFxAmpMessage::CreateAndReadMessage(a1: v7, a2: v10);
            if ( Message != nullptr )
            {
              ((void (__thiscall *)(IShaderAPI *, _DWORD))Message->GetLightmapDimensions)(
                a1: Message,
                a2: *((_DWORD *)this + 76));
              GRefCountImpl::Release(this: Message);
            }
          }
          if ( v7 != nullptr )
            GRefCountImpl::Release(this: (IShaderAPI *)v7);
        }
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
        v12 = *((_BYTE *)this + 164);
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
      }
      while ( v12 == 0 );
    }
    GFxBroadcastSocket::~GFxBroadcastSocket(this: (GFxBroadcastSocket *)v15);
    return 1;
  }
  else
  {
    GFxBroadcastSocket::~GFxBroadcastSocket(this: (GFxBroadcastSocket *)v15);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC3D0
// Name: private: static int GFxAmpThreadMgr::BroadcastRecvThreadLoop(class GThread __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl GFxAmpThreadMgr::BroadcastRecvThreadLoop(struct GThread *a1, GFxAmpThreadMgr *a2)
{
  if ( a2 == nullptr )
    return 1;
  GFxAmpThreadMgr::BroadcastRecvLoop(this: a2);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FC3F0
// Name: public: void GFxAmpThreadMgr::StartBroadcastRecv(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpThreadMgr::StartBroadcastRecv(GFxAmpThreadMgr *this, unsigned int a2)
{
  unsigned int v2; // eax
  GThread *v4; // eax
  GThread *v5; // edi
  IShaderAPI *v6; // ecx
  int v7; // ecx

  v2 = a2;
  *((_DWORD *)this + 15) = a2;
  if ( v2 != 0 && *((_DWORD *)this + 4) == 0 )
  {
    a2 = 2;
    v4 = (GThread *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 52, a4: &a2);
    if ( v4 != nullptr )
      v5 = GThread::GThread(
             this: v4,
             a2: (int (__cdecl *)(struct GThread *, void *))GFxAmpThreadMgr::BroadcastRecvThreadLoop,
             a3: this,
             a4: 0x20000u,
             a5: -1,
             a6: NotRunning);
    else
      v5 = nullptr;
    v6 = *((IShaderAPI **)this + 4);
    if ( v6 != nullptr )
      GRefCountImpl::Release(this: v6);
    *((_DWORD *)this + 4) = v5;
    if ( v5 != nullptr )
    {
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
      v7 = *((_DWORD *)this + 4);
      *((_BYTE *)this + 164) = 0;
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 20))(a1: v7, a2: 1);
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC490
// Name: public: void GFxAmpThreadMgr::GFxAmpMsgQueue::PushBack(class GFxAmpMessage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpThreadMgr::GFxAmpMsgQueue::PushBack(
        LPCRITICAL_SECTION lpCriticalSection,
        struct GFxAmpMessage *a2)
{
  GMemoryHeap *v3; // eax
  CMatLightmaps *v4; // edi
  unsigned int Limit; // ebx
  unsigned int m_pElements; // ebx
  const CDbgFmtMsg *v7; // [esp-8h] [ebp-10h]

  EnterCriticalSection(lpCriticalSection);
  a2->pPrev = *((GFxAmpMessage **)lpCriticalSection + 6);
  a2->pNext = (GFxAmpMessage *)&lpCriticalSection->LockSemaphore;
  *(_DWORD *)(*((_DWORD *)lpCriticalSection + 6) + 12) = a2;
  *((_DWORD *)lpCriticalSection + 6) = a2;
  InterlockedExchangeAdd(Addend: (volatile LONG *)lpCriticalSection + 8, Value: 1);
  v3 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2);
  v4 = (CMatLightmaps *)v3;
  if ( *((_DWORD *)lpCriticalSection + 9) != 0 )
  {
    Limit = v3->Info.Desc.Limit;
    if ( Limit != 0 )
    {
      if ( 100 * (int)v3->GetFootprint(this: v3) < Limit * *((_DWORD *)lpCriticalSection + 10) )
      {
        GEvent::SetEvent(a1: *((_DWORD *)lpCriticalSection + 9), a2: v4);
        LeaveCriticalSection(lpCriticalSection);
        return;
      }
      m_pElements = (unsigned int)v4->m_LightmapPageTextureHandles.m_pElements;
      if ( ((int (__thiscall *)(CMatLightmaps *))v4->m_ImagePackers.m_Memory.m_pMemory->m_pLightmapWavefront[18])(a1: v4) > m_pElements )
        GEvent::ResetEvent(this: *((_DWORD *)lpCriticalSection + 9), result: v7);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x100FC5B0
// Name: private: class GFxAmpMessage __near * GFxAmpThreadMgr::RetrieveMessageFromSendQueue(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxAmpMessage *__thiscall GFxAmpThreadMgr::RetrieveMessageFromSendQueue(GFxAmpThreadMgr *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ebx
  unsigned int v4; // edx
  struct GFxAmpMessage *result; // eax
  int v6; // edx
  CMemberFuncProxy4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int),int,int,int,int,CFuncMemPolicyNone> *v7; // [esp+0h] [ebp-1Ch]
  unsigned int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+18h] [ebp-4h] BYREF

  GTimer::GetTicks(this);
  v3 = v2;
  v8 = v4;
  result = GFxAmpThreadMgr::GFxAmpMsgQueue::PopFront(this: (GFxAmpThreadMgr *)((char *)this + 244));
  if ( result != nullptr )
    goto LABEL_6;
  v6 = *((_DWORD *)this + 28);
  if ( v6 != 0 && __PAIR64__(v8, v3) - *((_QWORD *)this + 21) > (unsigned int)(1000 * v6) )
  {
    v9 = 2;
    if ( GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 24, a4: &v9) == nullptr )
      return nullptr;
    result = (struct GFxAmpMessage *)GFxAmpMessageHeartbeat::GFxAmpMessageHeartbeat(result: v7);
    if ( result != nullptr )
    {
LABEL_6:
      *((_DWORD *)this + 42) = v3;
      *((_DWORD *)this + 43) = v8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FC650
// Name: public: void GFxAmpThreadMgr::SendAmpMessage(class GFxAmpMessage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpThreadMgr::SendAmpMessage(GFxAmpThreadMgr *this, struct GFxAmpMessage *a2)
{
  GFxAmpThreadMgr::GFxAmpMsgQueue::PushBack(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244), a2);
}

//------------------------------------------------------------------------------
// Address: 0x100FC660
// Name: public: void GFxAmpThreadMgr::SendLog(class GString const __near &,enum GFxLogConstants::LogMessageType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpThreadMgr::SendLog(GFxAmpThreadMgr *this, const struct GString *logText, float logCategory)
{
  IColorCorrectionSystem *v4; // eax
  struct GFxAmpMessage *v5; // eax
  __int64 timeptr; // [esp+4h] [ebp-Ch] BYREF
  int v7; // [esp+Ch] [ebp-4h] BYREF

  _time64(&timeptr);
  v7 = 2;
  v4 = (IColorCorrectionSystem *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                   this: GMemory::pGlobalHeap,
                                   a2: this,
                                   a3: 36,
                                   a4: &v7);
  if ( v4 != nullptr )
  {
    GFxAmpMessageLog::GFxAmpMessageLog(this: v4, (unsigned int)logText, logCategory);
    GFxAmpThreadMgr::GFxAmpMsgQueue::PushBack(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244), a2: v5);
  }
  else
  {
    GFxAmpThreadMgr::GFxAmpMsgQueue::PushBack(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244), a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC700
// Name: public: void GFxAmpThreadMgr::GFxAmpMsgQueue::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpThreadMgr::GFxAmpMsgQueue::Clear(LPCRITICAL_SECTION lpCriticalSection)
{
  void **v2; // eax
  IShaderAPI *v3; // ecx
  int v4; // ecx

  EnterCriticalSection(lpCriticalSection);
  while ( 1 )
  {
    v2 = lpCriticalSection == (LPCRITICAL_SECTION)-24 ? nullptr : &lpCriticalSection->LockSemaphore;
    if ( *((void ***)lpCriticalSection + 7) == v2 )
      break;
    v3 = *((IShaderAPI **)lpCriticalSection + 7);
    v3[2].GetSceneFogColor = (void (__thiscall *)(struct IShaderAPI *, unsigned __int8 *))v3[3].__vftable;
    v3[3].GetSceneFogMode = (MaterialFogMode_t (__thiscall *)(struct IShaderAPI *))v3[2].__vftable;
    GRefCountImpl::Release(this: v3);
  }
  InterlockedExchange(Target: (volatile LONG *)lpCriticalSection + 8, Value: 0);
  v4 = *((_DWORD *)lpCriticalSection + 9);
  if ( v4 != 0 )
    GEvent::SetEvent(a1: v4, a2: (CMatLightmaps *)lpCriticalSection);
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x100FC760
// Name: public: GFxAmpThreadMgr::GFxAmpThreadMgr(class GFxAmpMsgHandler __near *,class GFxAmpSendInterface __near *,class GFxAmpConnStatusInterface __near *,class GEvent __near *,class GFxSocketImplFactory __near *)
// Source: json
//------------------------------------------------------------------------------
GFxAmpThreadMgr *__thiscall GFxAmpThreadMgr::GFxAmpThreadMgr(
        GFxAmpThreadMgr *this,
        struct GFxAmpMsgHandler *a2,
        struct GFxAmpSendInterface *a3,
        struct GFxAmpConnStatusInterface *a4,
        struct GEvent *a5,
        struct GFxSocketImplFactory *a6)
{
  bool v7; // al
  char *v8; // ecx
  char *v9; // ecx
  struct GEvent *v10; // ecx

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxAmpThreadMgr::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)this + 1, spinCount: 0);
  *((_DWORD *)this + 12) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)((char *)this + 52));
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)((char *)this + 56));
  *((_DWORD *)this + 15) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)this + 4);
  *((_BYTE *)this + 68) = 1;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)this + 3, spinCount: 0);
  v7 = a2->IsInitSocketLib(this: a2);
  GFxSocket::GFxSocket(this: (GFxAmpThreadMgr *)((char *)this + 96), a2: v7, a3: a6);
  *((_DWORD *)this + 28) = 1000;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 116), spinCount: 0);
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140), spinCount: 0);
  *((_BYTE *)this + 164) = 1;
  *((_DWORD *)this + 42) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_DWORD *)this + 44) = 0;
  *((_DWORD *)this + 45) = 0;
  *((_DWORD *)this + 46) = 0;
  *((_BYTE *)this + 188) = 0;
  InterlockedExchange(Target: (volatile LONG *)this + 48, Value: 0);
  InterlockedExchange(Target: (volatile LONG *)this + 49, Value: 0);
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 200), spinCount: 0);
  if ( this == (GFxAmpThreadMgr *)-224 )
    v8 = nullptr;
  else
    v8 = (char *)this + 216;
  *((_DWORD *)this + 56) = v8;
  *((_DWORD *)this + 57) = v8;
  InterlockedExchange(Target: (volatile LONG *)this + 58, Value: 0);
  *((_DWORD *)this + 59) = 0;
  *((_DWORD *)this + 60) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244), spinCount: 0);
  if ( this == (GFxAmpThreadMgr *)-268 )
    v9 = nullptr;
  else
    v9 = (char *)this + 260;
  *((_DWORD *)this + 67) = v9;
  *((_DWORD *)this + 68) = v9;
  InterlockedExchange(Target: (volatile LONG *)this + 69, Value: 0);
  v10 = a5;
  *((_DWORD *)this + 70) = a5;
  *((_DWORD *)this + 71) = 90;
  if ( a5 != nullptr )
  {
    GEvent::SetEvent(a1: (int)a5, a2: (CMatLightmaps *)InterlockedExchange);
    v10 = a5;
  }
  *((_DWORD *)this + 74) = a3;
  *((_DWORD *)this + 72) = v10;
  *((_DWORD *)this + 77) = a6;
  *((_DWORD *)this + 75) = a4;
  *((_DWORD *)this + 73) = 11;
  *((_DWORD *)this + 76) = a2;
  CMatRenderContextBase::SetCurrentMaterialInternal(this: (CMaterial *)((char *)this + 96), pageID: (int)this + 72);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FC910
// Name: public: void GFxAmpThreadMgr::UninitAmp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpThreadMgr::UninitAmp(GFxAmpThreadMgr *this)
{
  GWaitable *v2; // ecx
  IShaderAPI *v3; // ecx
  GWaitable *v4; // ecx
  IShaderAPI *v5; // ecx
  GWaitable *v6; // ecx
  IShaderAPI *v7; // ecx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 116);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 116));
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
  *((_BYTE *)this + 164) = 1;
  GFxSocket::Destroy(this: (GFxAmpThreadMgr *)((char *)this + 96));
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
  v2 = *((GWaitable **)this + 3);
  if ( v2 != nullptr )
  {
    GWaitable::Wait(this: v2, result: 0xFFFFFFFF);
    v3 = *((IShaderAPI **)this + 3);
    if ( v3 != nullptr )
      GRefCountImpl::Release(this: v3);
    *((_DWORD *)this + 3) = 0;
  }
  v4 = *((GWaitable **)this + 4);
  if ( v4 != nullptr )
  {
    GWaitable::Wait(this: v4, result: 0xFFFFFFFF);
    v5 = *((IShaderAPI **)this + 4);
    if ( v5 != nullptr )
      GRefCountImpl::Release(this: v5);
    *((_DWORD *)this + 4) = 0;
  }
  v6 = *((GWaitable **)this + 2);
  if ( v6 != nullptr )
  {
    GWaitable::Wait(this: v6, result: 0xFFFFFFFF);
    v7 = *((IShaderAPI **)this + 2);
    if ( v7 != nullptr )
      GRefCountImpl::Release(this: v7);
    *((_DWORD *)this + 2) = 0;
  }
  GFxAmpThreadMgr::GFxAmpMsgQueue::Clear(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244));
  GFxAmpThreadMgr::GFxAmpMsgQueue::Clear(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 200));
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x100FC9D0
// Name: public: bool GFxAmpThreadMgr::IsValidConnection(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpThreadMgr::IsValidConnection(GFxAmpThreadMgr *this)
{
  void *v2; // ecx
  __int64 v3; // rax
  _RTL_CRITICAL_SECTION *v4; // edi
  unsigned int v5; // ebx
  int v6; // ecx
  unsigned __int64 v7; // rax
  char m_nAllocationCount_high; // bl
  int v9; // eax
  int v10; // ecx
  void *v11; // edi
  _RTL_CRITICAL_SECTION *v13; // [esp-4h] [ebp-28h]
  IFileSystem v14; // [esp+Ch] [ebp-18h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+18h] [ebp-Ch]
  CUtlMemory<CImagePacker,int> var8; // [esp+1Ch] [ebp-8h] BYREF

  lpCriticalSection = (LPCRITICAL_SECTION)((char *)this + 140);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
  GTimer::GetTicks(this: v2);
  v4 = *((_RTL_CRITICAL_SECTION **)this + 44);
  v5 = *((_DWORD *)this + 45);
  HIBYTE(var8.m_nAllocationCount) = *((_QWORD *)this + 22) != 0;
  v6 = *((_DWORD *)this + 28);
  if ( v6 == 0 )
  {
    if ( HIBYTE(var8.m_nAllocationCount) != 0 )
    {
LABEL_10:
      m_nAllocationCount_high = HIBYTE(var8.m_nAllocationCount);
      goto LABEL_11;
    }
LABEL_6:
    v4 = lpCriticalSection;
    EnterCriticalSection(lpCriticalSection);
    v9 = *((_DWORD *)this + 46);
    if ( v9 != 1 )
    {
      v10 = *((_DWORD *)this + 75);
      *((_DWORD *)this + 46) = 1;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v10 + 4))(a1: v10, a2: 1, a3: v9, a4: 0);
    }
    LeaveCriticalSection(lpCriticalSection: v4);
    goto LABEL_10;
  }
  v7 = v3 - __PAIR64__(v5, (unsigned int)v4);
  v4 = nullptr;
  if ( v7 >= (unsigned int)(2000 * v6) )
  {
    HIBYTE(var8.m_nAllocationCount) = 0;
    goto LABEL_6;
  }
  m_nAllocationCount_high = 1;
LABEL_11:
  if ( *((_BYTE *)this + 188) == 0 && m_nAllocationCount_high != 0 )
  {
    GString::GString(this: &var8);
    v14.IAppSystem::__vftable = nullptr;
    v14.IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&var8;
    G_SPrintF(a1: (const char *const *)v4, result: &v14, a3: "Established AMP connection on port %d\n");
    GFxAmpThreadMgr::SendLog(this, logText: (const struct GString *)&var8, logCategory: COERCE_FLOAT(18));
    v11 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
  }
  v13 = lpCriticalSection;
  *((_BYTE *)this + 188) = m_nAllocationCount_high;
  LeaveCriticalSection(lpCriticalSection: v13);
  return m_nAllocationCount_high;
}

//------------------------------------------------------------------------------
// Address: 0x100FCB00
// Name: private: bool GFxAmpThreadMgr::BroadcastLoop(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall GFxAmpThreadMgr::BroadcastLoop@<al>(GFxAmpThreadMgr *this@<ecx>, float a2@<ebx>, int BaseImage@<edi>)
{
  char v4; // al
  char v6; // bl
  GFxAmpStream *v7; // eax
  CThreadEvent *v8; // eax
  IShaderAPI *v9; // edi
  float y; // ebx
  float *v11; // eax
  char v12; // bl
  struct GFxSocketImplFactory *v14; // [esp-4h] [ebp-1Ch]
  CMaterial_QueueFriendly var14; // [esp+4h] [ebp-14h] BYREF

  v14 = *((struct GFxSocketImplFactory **)this + 77);
  v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 76) + 40))(a1: *((_DWORD *)this + 76));
  GFxBroadcastSocket::GFxBroadcastSocket(this: (GFxBroadcastSocket *)&var14, a2: v4, a3: v14);
  if ( GFxBroadcastSocket::Create(this: (GFxBroadcastSocket *)&var14, a2: *((_DWORD *)this + 12), a3: true) != 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
    v6 = *((_BYTE *)this + 164);
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
    if ( v6 == 0 )
    {
      do
      {
        if ( GFxAmpThreadMgr::IsValidConnection(this) == 0 )
        {
          LODWORD(var14.m_vColorModulationOnQueueCompletion.y) = 2;
          v7 = (GFxAmpStream *)((int (__thiscall *)(GMemoryHeap *, GFxAmpThreadMgr *, int, float *, int, _DWORD))GMemory::pGlobalHeap->AllocAutoHeap_2)(
                                 a1: GMemory::pGlobalHeap,
                                 a2: this,
                                 a3: 24,
                                 a4: &var14.m_vColorModulationOnQueueCompletion.y,
                                 a5: BaseImage,
                                 a6: LODWORD(a2));
          if ( v7 != nullptr )
            LODWORD(var14.m_vColorModulationOnQueueCompletion.y) = GFxAmpStream::GFxAmpStream(this: v7);
          else
            var14.m_vColorModulationOnQueueCompletion.y = 0.0;
          EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this + 1);
          LODWORD(var14.m_vColorModulationOnQueueCompletion.x) = 2;
          v8 = (CThreadEvent *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: this,
                                 a3: 40,
                                 a4: &var14.m_vColorModulationOnQueueCompletion);
          if ( v8 != nullptr )
            v9 = (IShaderAPI *)GFxAmpMessagePort::GFxAmpMessagePort(this: v8, port: *((_DWORD *)this + 5));
          else
            v9 = nullptr;
          LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this + 1);
          y = var14.m_vColorModulationOnQueueCompletion.y;
          a2 = var14.m_vColorModulationOnQueueCompletion.y;
          ((void (__thiscall *)(IShaderAPI *))v9->SetVertexShaderConstant)(a1: v9);
          BaseImage = GSubImageInfo::GetBaseImage(this: (CVTFTexture *)LODWORD(y));
          v11 = (float *)CSubDMgr::SubDTexture(this: (CMaterial *)LODWORD(y));
          CMaterial_QueueFriendly::GetMaterialScale(this: &var14, pScale: v11);
          GRefCountImpl::Release(this: v9);
          if ( y != 0.0 )
            GRefCountImpl::Release(this: (IShaderAPI *)LODWORD(y));
        }
        GThread::Sleep(secs: 1u);
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
        v12 = *((_BYTE *)this + 164);
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
      }
      while ( v12 == 0 );
    }
    GFxBroadcastSocket::~GFxBroadcastSocket(this: (GFxBroadcastSocket *)&var14);
    return 1;
  }
  else
  {
    GFxBroadcastSocket::~GFxBroadcastSocket(this: (GFxBroadcastSocket *)&var14);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FCC80
// Name: private: static int GFxAmpThreadMgr::BroadcastThreadLoop(class GThread __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
static int __usercall GFxAmpThreadMgr::BroadcastThreadLoop@<eax>(
        float a1@<ebx>,
        int a2@<edi>,
        struct GThread *a3,
        GFxAmpThreadMgr *a4)
{
  if ( a4 == nullptr )
    return 1;
  GFxAmpThreadMgr::BroadcastLoop(this: a4, a2: a1, BaseImage: a2);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FCCA0
// Name: public: virtual GFxAmpThreadMgr::~GFxAmpThreadMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpThreadMgr::~GFxAmpThreadMgr(GFxAmpThreadMgr *this)
{
  volatile LONG *v2; // edi
  volatile LONG *v3; // edi
  volatile LONG *v4; // edi
  IShaderAPI *v5; // ecx
  IShaderAPI *v6; // ecx
  IShaderAPI *v7; // ecx

  *(_DWORD *)this = &GFxAmpThreadMgr::`vftable';
  GFxAmpThreadMgr::UninitAmp(this);
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244));
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 200));
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 116));
  GFxSocket::~GFxSocket(this: (GFxAmpThreadMgr *)((char *)this + 96));
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)this + 3);
  v2 = (volatile LONG *)(*((_DWORD *)this + 16) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (volatile LONG *)(*((_DWORD *)this + 14) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  v4 = (volatile LONG *)(*((_DWORD *)this + 13) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)this + 1);
  v5 = *((IShaderAPI **)this + 4);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  v6 = *((IShaderAPI **)this + 3);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  v7 = *((IShaderAPI **)this + 2);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100FCD90
// Name: private: bool GFxAmpThreadMgr::SocketConnect(class GString __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpThreadMgr::SocketConnect(GFxAmpThreadMgr *this, int a2)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  int v5; // eax
  int v6; // ecx
  char v7; // al
  void *v8; // ecx
  int v9; // eax
  int v10; // edx
  GThread *v11; // eax
  GThread *v12; // ebx
  IShaderAPI *v13; // ecx
  _RTL_CRITICAL_SECTION *v14; // [esp-4h] [ebp-18h]
  char v15; // [esp+13h] [ebp-1h]

  v3 = (_RTL_CRITICAL_SECTION *)((char *)this + 140);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
  EnterCriticalSection(lpCriticalSection: v3);
  v15 = *((_BYTE *)this + 164);
  LeaveCriticalSection(lpCriticalSection: v3);
  if ( v15 != 0 )
  {
    GFxSocket::Destroy(this: (GFxAmpThreadMgr *)((char *)this + 96));
    v14 = v3;
LABEL_3:
    LeaveCriticalSection(lpCriticalSection: v14);
    return 0;
  }
  EnterCriticalSection(lpCriticalSection: v3);
  v5 = *((_DWORD *)this + 46);
  if ( v5 != 1 )
  {
    v6 = *((_DWORD *)this + 75);
    *((_DWORD *)this + 46) = 1;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int, int, int, const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *))(*(_DWORD *)v6 + 4))(
        a1: v6,
        a2: 1,
        a3: v5,
        a4: &pMem);
  }
  LeaveCriticalSection(lpCriticalSection: v3);
  if ( *((_BYTE *)this + 68) != 0 )
  {
    if ( GFxSocket::Create(
           this: (GFxAmpThreadMgr *)((char *)this + 96),
           a2: nullptr,
           a3: *((_DWORD *)this + 5),
           a4: (IBaseFileSystem_vtbl *)a2) == 0 )
    {
      EnterCriticalSection(lpCriticalSection: v3);
      *((_BYTE *)this + 164) = 1;
      GFxSocket::Destroy(this: (GFxAmpThreadMgr *)((char *)this + 96));
      LeaveCriticalSection(lpCriticalSection: v3);
      LeaveCriticalSection(lpCriticalSection: v3);
      return 0;
    }
  }
  else
  {
    v7 = GFxSocket::Create(
           this: (GFxAmpThreadMgr *)((char *)this + 96),
           a2: (const char *)((*((_DWORD *)this + 16) & 0xFFFFFFFC) + 8),
           a3: *((_DWORD *)this + 5),
           a4: (IBaseFileSystem_vtbl *)a2);
    v14 = v3;
    if ( v7 == 0 )
      goto LABEL_3;
    EnterCriticalSection(lpCriticalSection: v3);
    GTimer::GetTicks(this: v8);
    *((_DWORD *)this + 44) = v9;
    *((_DWORD *)this + 45) = v10;
    LeaveCriticalSection(lpCriticalSection: v3);
  }
  if ( *((_DWORD *)this + 12) != 0 && *((_DWORD *)this + 3) == 0 )
  {
    a2 = 2;
    v11 = (GThread *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 52, a4: &a2);
    if ( v11 != nullptr )
      v12 = GThread::GThread(
              this: v11,
              a2: (int (__cdecl *)(struct GThread *, void *))GFxAmpThreadMgr::BroadcastThreadLoop,
              a3: this,
              a4: 0x20000u,
              a5: -1,
              a6: NotRunning);
    else
      v12 = nullptr;
    v13 = *((IShaderAPI **)this + 3);
    if ( v13 != nullptr )
      GRefCountImpl::Release(this: v13);
    *((_DWORD *)this + 3) = v12;
    if ( v12 != nullptr )
      v12->Start(this: v12, a2: Running);
  }
  LeaveCriticalSection(lpCriticalSection: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FCF20
// Name: private: bool GFxAmpThreadMgr::SendReceiveLoop(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall GFxAmpThreadMgr::SendReceiveLoop@<eax>(GFxAmpThreadMgr *this@<ecx>, CMatLightmaps *a2@<edi>)
{
  int v3; // ecx
  ConVar *v4; // edi
  struct GFxAmpMessage *v5; // eax
  GFxAmpStream *v6; // eax
  int v7; // eax
  int v8; // ecx
  void *v9; // ecx
  int v10; // eax
  int v11; // edx
  void *v12; // ecx
  int v13; // eax
  GFxAmpStream *v14; // eax
  IShaderAPI *v15; // eax
  unsigned int BaseImage; // edi
  int v17; // ecx
  IShaderAPI *MessageFromSendQueue; // ebx
  GFxAmpStream *v19; // eax
  IShaderAPI *v20; // edi
  IShaderAPI v21; // edx
  void (__thiscall *SetVertexShaderConstant)(struct IShaderAPI *, int, const float *, int, bool); // eax
  unsigned int v23; // eax
  int v24; // eax
  signed int v25; // eax
  void *v26; // ecx
  unsigned int v27; // ebx
  void *v28; // ecx
  int v29; // eax
  int v30; // edx
  struct GMemoryHeap *v31; // eax
  struct GFxAmpMessage *Message; // edi
  unsigned int Version; // eax
  int v34; // eax
  int v35; // ebx
  unsigned int v36; // edi
  char v37; // bl
  char v38; // bl
  CMemberFuncProxy4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int),int,int,int,int,CFuncMemPolicyNone> *v40; // [esp+0h] [ebp-23Ch]
  int v41; // [esp+14h] [ebp-228h]
  char *v42; // [esp+1Ch] [ebp-220h]
  int v43; // [esp+20h] [ebp-21Ch]
  int v44; // [esp+24h] [ebp-218h]
  GFxAmpStream *v45; // [esp+28h] [ebp-214h]
  int v46; // [esp+2Ch] [ebp-210h] BYREF
  IShaderAPI *v47; // [esp+30h] [ebp-20Ch] BYREF
  char v48; // [esp+37h] [ebp-205h]
  char v49[512]; // [esp+38h] [ebp-204h] BYREF

  v3 = *((_DWORD *)this + 72);
  if ( v3 != 0 )
    GEvent::SetEvent(a1: v3, a2);
  if ( GFxAmpThreadMgr::SocketConnect(this, a2: 0) != 0 )
  {
    v4 = (ConVar *)((char *)this + 96);
    do
    {
      if ( GFxSocket::Accept(this: (GFxSocket *)v4, a2: 1) != 0 )
      {
        ConVar::SetValue(this: v4, value: 0);
        *((_DWORD *)this + 73) = 11;
        v47 = (IShaderAPI *)2;
        if ( GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 24, a4: &v47) != nullptr )
          v5 = (struct GFxAmpMessage *)GFxAmpMessageHeartbeat::GFxAmpMessageHeartbeat(result: v40);
        else
          v5 = nullptr;
        GFxAmpThreadMgr::GFxAmpMsgQueue::PushBack(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244), a2: v5);
        v47 = (IShaderAPI *)2;
        v6 = (GFxAmpStream *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                               this: GMemory::pGlobalHeap,
                               a2: this,
                               a3: 24,
                               a4: &v47);
        if ( v6 != nullptr )
          v45 = GFxAmpStream::GFxAmpStream(this: v6);
        else
          v45 = nullptr;
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
        v7 = *((_DWORD *)this + 46);
        if ( v7 != 2 )
        {
          v8 = *((_DWORD *)this + 75);
          *((_DWORD *)this + 46) = 2;
          if ( v8 != 0 )
            (*(void (__thiscall **)(int, int, int, const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *))(*(_DWORD *)v8 + 4))(
              a1: v8,
              a2: 2,
              a3: v7,
              a4: &pMem);
        }
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
        GTimer::GetTicks(this: v9);
        *((_DWORD *)this + 44) = v10;
        *((_DWORD *)this + 45) = v11;
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
        GTimer::GetProfileTicks(this: v12);
        v41 = v13;
        v47 = (IShaderAPI *)2;
        v44 = 0;
        v43 = 0;
        v14 = (GFxAmpStream *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                this: GMemory::pGlobalHeap,
                                a2: this,
                                a3: 24,
                                a4: &v47);
        if ( v14 != nullptr )
          v15 = (IShaderAPI *)GFxAmpStream::GFxAmpStream(this: v14);
        else
          v15 = nullptr;
        v47 = v15;
        BaseImage = GSubImageInfo::GetBaseImage(this: (CVTFTexture *)v15);
        v46 = BaseImage;
        v42 = nullptr;
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
        v48 = *((_BYTE *)this + 164);
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
        if ( v48 == 0 )
        {
          while ( GFxAmpThreadMgr::IsValidConnection(this) != 0
               && !CMaterialSubRect::UsesEnvCubemap(this: (CMaterial_QueueFriendly *)this + 4) )
          {
            v17 = *((_DWORD *)this + 74);
            v48 = 0;
            if ( v17 != 0 )
              v48 = (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v17 + 4))(a1: v17) != 0;
            if ( BaseImage != 0 )
              goto LABEL_33;
            MessageFromSendQueue = (IShaderAPI *)GFxAmpThreadMgr::RetrieveMessageFromSendQueue(this);
            if ( MessageFromSendQueue != nullptr )
            {
              v46 = 2;
              v19 = (GFxAmpStream *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                      this: GMemory::pGlobalHeap,
                                      a2: this,
                                      a3: 24,
                                      a4: &v46);
              if ( v19 != nullptr )
                v20 = (IShaderAPI *)GFxAmpStream::GFxAmpStream(this: v19);
              else
                v20 = nullptr;
              if ( v47 != nullptr )
                GRefCountImpl::Release(this: v47);
              v21.__vftable = MessageFromSendQueue->__vftable;
              MessageFromSendQueue[5].__vftable = *(IShaderAPI_vtbl **)((char *)this + 292);
              SetVertexShaderConstant = v21.SetVertexShaderConstant;
              v47 = v20;
              ((void (__thiscall *)(IShaderAPI *, IShaderAPI *))SetVertexShaderConstant)(
                a1: MessageFromSendQueue,
                a2: v20);
              v46 = GSubImageInfo::GetBaseImage(this: (CVTFTexture *)v20);
              v42 = (char *)CSubDMgr::SubDTexture(this: (CMaterial *)v20);
              GRefCountImpl::Release(this: MessageFromSendQueue);
              BaseImage = v46;
              if ( v46 != 0 )
              {
LABEL_33:
                v23 = BaseImage;
                if ( BaseImage > 0x200 )
                  v23 = 512;
                v24 = GFxSocket::Send(this: (GFxAmpThreadMgr *)((char *)this + 96), a2: v42, a3: v23);
                if ( v24 > 0 )
                {
                  v44 += v24;
                  v42 += v24;
                  v46 = BaseImage - v24;
                  v48 = 1;
                }
              }
            }
            v25 = GFxSocket::Receive(this: (GFxAmpThreadMgr *)((char *)this + 96), a2: v49, a3: 512);
            if ( v25 > 0 )
            {
              v43 += v25;
              v48 = 1;
              GFxAmpStream::Append(this: v45, a2: (unsigned __int8 *)v49, a3: v25);
            }
            v27 = GSubImageInfo::GetBaseImage(this: (CVTFTexture *)v45);
            if ( v27 != 0 && v27 >= GFxAmpStream::FirstMessageSize(this: v45) )
            {
              EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
              GTimer::GetTicks(this: v28);
              *((_DWORD *)this + 44) = v29;
              *((_DWORD *)this + 45) = v30;
              LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
              v31 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
              Message = GFxAmpMessage::CreateAndReadMessage(a1: v45, a2: v31);
              GFxAmpStream::PopFirstMessage(this: v45);
              if ( Message != nullptr )
              {
                Version = Message->Version;
                if ( Version < *((_DWORD *)this + 73) )
                  *((_DWORD *)this + 73) = Version;
                if ( Message->ShouldQueue(this: Message) || *((_DWORD *)this + 76) == 0 )
                {
                  GFxAmpThreadMgr::GFxAmpMsgQueue::PushBack(
                    lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 200),
                    a2: Message);
                }
                else
                {
                  Message->AcceptHandler(this: Message, a2: *((GFxAmpMsgHandler **)this + 76));
                  GRefCountImpl::Release(this: (IShaderAPI *)Message);
                }
              }
            }
            if ( v48 == 0 )
              GThread::MSleep(msecs: 0xAu);
            GTimer::GetProfileTicks(this: v26);
            v35 = v34;
            v36 = v34 - v41;
            if ( (unsigned int)(v34 - v41) > 0xF4240 )
            {
              InterlockedExchange(Target: (volatile LONG *)this + 48, Value: 1000000 * v44 / v36);
              InterlockedExchange(Target: (volatile LONG *)this + 49, Value: 1000000 * v43 / v36);
              v41 = v35;
              v44 = 0;
              v43 = 0;
            }
            EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
            v37 = *((_BYTE *)this + 164);
            LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
            if ( v37 != 0 )
              break;
            BaseImage = v46;
          }
        }
        if ( v47 != nullptr )
          GRefCountImpl::Release(this: v47);
        if ( v45 != nullptr )
          GRefCountImpl::Release(this: (IShaderAPI *)v45);
      }
      v4 = (ConVar *)((char *)this + 96);
      GFxSocket::Destroy(this: (GFxAmpThreadMgr *)((char *)this + 96));
    }
    while ( GFxAmpThreadMgr::SocketConnect(this, a2: 0) != 0 );
  }
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
  v38 = *((_BYTE *)this + 164);
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 140));
  return v38 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FD420
// Name: private: static int GFxAmpThreadMgr::SocketThreadLoop(class GThread __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
static int __usercall GFxAmpThreadMgr::SocketThreadLoop@<eax>(
        CMatLightmaps *a1@<edi>,
        struct GThread *a2,
        GFxAmpThreadMgr *a3)
{
  if ( a3 == nullptr )
    return 1;
  while ( GFxAmpThreadMgr::SendReceiveLoop(this: a3, a2: a1) )
    GThread::Sleep(secs: 1u);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FD490
// Name: public: bool GFxAmpThreadMgr::InitAmp(char const __near *,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpThreadMgr::InitAmp(GFxAmpThreadMgr *this, char *a2, unsigned int a3, unsigned int a4)
{
  GThread *v5; // ecx
  unsigned int v6; // ebx
  BOOL v7; // eax
  GThread *v8; // eax
  GThread *v9; // edi
  IShaderAPI *v10; // ecx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 116);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 116));
  v5 = *((GThread **)this + 2);
  v6 = a3;
  if ( v5 != nullptr && !GThread::IsFinished(this: v5) )
  {
    if ( *((_BYTE *)this + 68) != 0 )
      v7 = a2 == nullptr;
    else
      v7 = strcmp((const char *)((*((_DWORD *)this + 16) & 0xFFFFFFFC) + 8), a2) == 0;
    if ( v7 && v6 == *((_DWORD *)this + 5) )
      goto LABEL_21;
    GFxAmpThreadMgr::UninitAmp(this);
  }
  *((_DWORD *)this + 12) = a4;
  *((_BYTE *)this + 164) = 0;
  *((_DWORD *)this + 5) = v6;
  *((_BYTE *)this + 68) = a2 == nullptr;
  if ( a2 != nullptr )
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 64),
      (unsigned __int8 *)a2);
  if ( *((_DWORD *)this + 5) != 0 )
  {
    a3 = 2;
    v8 = (GThread *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 52, a4: &a3);
    v9 = v8 != nullptr
       ? GThread::GThread(
           this: v8,
           a2: (int (__cdecl *)(struct GThread *, void *))GFxAmpThreadMgr::SocketThreadLoop,
           a3: this,
           a4: 0x20000u,
           a5: -1,
           a6: NotRunning)
       : nullptr;
    v10 = *((IShaderAPI **)this + 2);
    if ( v10 != nullptr )
      GRefCountImpl::Release(this: v10);
    *((_DWORD *)this + 2) = v9;
    if ( v9 == nullptr || !v9->Start(this: v9, a2: Running) )
    {
      LeaveCriticalSection(lpCriticalSection);
      return 0;
    }
  }
  GFxAmpThreadMgr::StartBroadcastRecv(this, a2: *((_DWORD *)this + 15));
LABEL_21:
  LeaveCriticalSection(lpCriticalSection);
  return 1;
}
