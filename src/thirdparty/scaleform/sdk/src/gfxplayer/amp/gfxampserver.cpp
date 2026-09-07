// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/amp/gfxampserver.cpp
// Functions: 44
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\amp\gfxampserver.h"

//------------------------------------------------------------------------------
// Address: 0x10074F50
// Name: public: static class GFxAmpServer __near & GFxAmpServer::GetInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxAmpServer::GetInstance(void *this)
{
  return *(void **)GFxAmpServer::AmpServerSingleton;
}

//------------------------------------------------------------------------------
// Address: 0x10074F60
// Name: public: static void GFxAmpServer::Uninit(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GFxAmpServer::Uninit()
{
  GRefCountImpl::Release(this: (IShaderAPI *)GFxAmpServer::AmpServerSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x10074F70
// Name: public: bool GFxAmpServer::IsState(enum AmpServerStateType)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::IsState(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *state)
{
  _RTL_CRITICAL_SECTION *v2; // edi

  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 104);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 104));
  LeaveCriticalSection(lpCriticalSection: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10074FA0
// Name: public: unsigned long GFxAmpServer::GetNextSwdHandle(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::GetNextSwdHandle(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  _RTL_CRITICAL_SECTION *v1; // esi

  v1 = (_RTL_CRITICAL_SECTION *)((char *)this + 320);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 320));
  ++lastSwdHandle;
  LeaveCriticalSection(lpCriticalSection: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10074FD0
// Name: public: bool GFxAmpServer::IsProfiling(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxAmpServer::IsProfiling(int this)
{
  _RTL_CRITICAL_SECTION *v2; // esi
  char v3; // bl
  GFxAmpThreadMgr *v4; // ecx
  GFxAmpThreadMgr *v5; // edi
  bool v6; // al
  bool v7; // [esp+Fh] [ebp-1h]

  v2 = (_RTL_CRITICAL_SECTION *)(this + 104);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 104));
  v7 = (*(_DWORD *)(this + 32) & 2) != 0;
  LeaveCriticalSection(lpCriticalSection: v2);
  v6 = false;
  if ( !v7 )
  {
    EnterCriticalSection(lpCriticalSection: v2);
    v3 = *(_BYTE *)(this + 32);
    LeaveCriticalSection(lpCriticalSection: v2);
    if ( (v3 & 1) == 0 )
    {
      v4 = *(GFxAmpThreadMgr **)(this + 164);
      if ( v4 != nullptr && GFxAmpThreadMgr::IsValidSocket(this: v4) )
      {
        v5 = *(GFxAmpThreadMgr **)(this + 164);
        if ( v5 != nullptr && GFxAmpThreadMgr::IsValidConnection(this: v5) )
          return true;
      }
    }
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10075050
// Name: public: bool GFxAmpServer::HandleNextMessage(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpServer::HandleNextMessage(GFxAmpServer *this)
{
  GFxAmpThreadMgr *pObject; // ecx
  char v3; // bl
  IShaderAPI *v5; // [esp+4h] [ebp-4h] BYREF

  pObject = this->ThreadMgr.pObject;
  if ( pObject == nullptr )
    return 0;
  GFxAmpThreadMgr::GetNextReceivedMessage(this: (int)pObject, a2: &v5);
  if ( v5 == nullptr )
    return 0;
  v3 = ((int (__thiscall *)(IShaderAPI *, GFxAmpServer *))v5->GetLightmapDimensions)(a1: v5, a2: this);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100750A0
// Name: public: void GFxAmpServer::SendCurrentState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::SendCurrentState(GFxAmpServer *this)
{
  struct GFxAmpMessage *v2; // eax
  int v3; // [esp+4h] [ebp-4h] BYREF

  if ( this->ThreadMgr.pObject != nullptr )
  {
    EnterCriticalSection(lpCriticalSection: &this->CurrentStateLock.cs);
    GFxAmpThreadMgr::SetBroadcastInfo(
      this: this->ThreadMgr.pObject,
      a2: (const char *)((this->CurrentState.ConnectedApp.HeapTypeBits & 0xFFFFFFFC) + 8),
      a3: (const char *)((this->CurrentState.ConnectedFile.HeapTypeBits & 0xFFFFFFFC) + 8));
    v3 = 2;
    if ( GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 28, a4: &v3) != nullptr )
      v2 = (struct GFxAmpMessage *)GFxAmpMessageCurrentState::GFxAmpMessageCurrentState(a1: (unsigned int)&this->CurrentState);
    else
      v2 = nullptr;
    GFxAmpThreadMgr::SendAmpMessage(this: this->ThreadMgr.pObject, a2: v2);
    LeaveCriticalSection(lpCriticalSection: &this->CurrentStateLock.cs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075130
// Name: public: void GFxAmpServer::SendAppControlCaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::SendAppControlCaps(GFxAmpServer *this)
{
  ICachedPerFrameMeshData *v2; // edi
  struct GFxAmpMessage *v3; // eax
  int v4; // [esp+8h] [ebp-4h] BYREF

  v4 = 2;
  v2 = (ICachedPerFrameMeshData *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                    this: GMemory::pGlobalHeap,
                                    a2: this,
                                    a3: 32,
                                    a4: &v4);
  if ( v2 != nullptr )
  {
    GFILEFile::GetErrorCode(this: (CVTFTexture *)this->AppControlCaps.pObject);
    GFxAmpMessageAppControl::GFxAmpMessageAppControl(this: v2);
    GFxAmpThreadMgr::SendAmpMessage(this: this->ThreadMgr.pObject, a2: v3);
  }
  else
  {
    GFxAmpThreadMgr::SendAmpMessage(this: this->ThreadMgr.pObject, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100751A0
// Name: public: virtual bool GFxAmpServer::HandleAppControl(class GFxAmpMessageAppControl const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpServer::HandleAppControl(GFxAmpServer *this, const struct GFxAmpMessageAppControl *a2)
{
  const struct GFxAmpMessageAppControl *v3; // edi
  unsigned int v4; // ebx
  GFxAmpAppControlInterface *AppControlCallback; // esi
  const CThreadEvent *v7; // [esp+0h] [ebp-10h]
  const CThreadEvent *v8; // [esp+0h] [ebp-10h]
  const CThreadEvent *v9; // [esp+0h] [ebp-10h]
  GLock *lpCriticalSection; // [esp+Ch] [ebp-4h]

  lpCriticalSection = &this->ToggleStateLock;
  EnterCriticalSection(lpCriticalSection: &this->ToggleStateLock.cs);
  v3 = a2;
  this->ToggleState = 0;
  if ( (unsigned __int8)CTexture::IsPreloaded(this: a2) != 0 )
    this->ToggleState |= 1u;
  if ( (unsigned __int8)GFxAmpMessageAppControl::IsToggleInstructionProfile(result: v7) != 0 )
    this->ToggleState |= 4u;
  if ( (unsigned __int8)GFxAmpMessageAppControl::IsToggleMemReport(result: v8) != 0 )
    this->ToggleState |= 0x20u;
  if ( (unsigned __int8)GFxAmpMessageAppControl::IsForceInstructionProfile(result: v9) != 0 )
  {
    EnterCriticalSection(lpCriticalSection: &this->CurrentStateLock.cs);
    v4 = this->CurrentState.StateFlags >> 2;
    LeaveCriticalSection(lpCriticalSection: &this->CurrentStateLock.cs);
    v3 = a2;
    if ( (v4 & 1) == 0 )
      this->ToggleState |= 4u;
  }
  AppControlCallback = this->AppControlCallback;
  if ( AppControlCallback != nullptr )
    AppControlCallback->HandleAmpRequest(this: AppControlCallback, a2: v3);
  LeaveCriticalSection(lpCriticalSection: &lpCriticalSection->cs);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10075260
// Name: public: bool GFxAmpServer::OpenConnection(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpServer::OpenConnection(GFxAmpServer *this)
{
  GLock *p_CurrentStateLock; // edi
  unsigned int v3; // ebx
  GFxAmpThreadMgr *v4; // eax
  GFxAmpStatusChangedCallback *pObject; // edx
  struct GFxAmpConnStatusInterface *v6; // ecx
  GFxAmpSendThreadCallback *v7; // edx
  struct GFxAmpSendInterface *v8; // edx
  GFxAmpThreadMgr *v9; // ebx
  IShaderAPI *v10; // ecx
  GFxAmpThreadMgr *v11; // ecx
  int v13; // [esp+Ch] [ebp-4h] BYREF

  p_CurrentStateLock = &this->CurrentStateLock;
  EnterCriticalSection(lpCriticalSection: &this->CurrentStateLock.cs);
  v3 = this->CurrentState.StateFlags >> 1;
  LeaveCriticalSection(lpCriticalSection: &p_CurrentStateLock->cs);
  if ( (v3 & 1) != 0 )
    return 1;
  EnterCriticalSection(lpCriticalSection: &this->ConnectionLock.cs);
  if ( this->ThreadMgr.pObject == nullptr )
  {
    v13 = 2;
    v4 = (GFxAmpThreadMgr *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                              this: GMemory::pGlobalHeap,
                              a2: this,
                              a3: 312,
                              a4: &v13);
    if ( v4 != nullptr )
    {
      pObject = this->StatusChangedCallback.pObject;
      if ( pObject != nullptr )
        v6 = (struct GFxAmpConnStatusInterface *)((char *)pObject + 8);
      else
        v6 = nullptr;
      v7 = this->SendThreadCallback.pObject;
      if ( v7 != nullptr )
        v8 = (struct GFxAmpSendInterface *)((char *)v7 + 8);
      else
        v8 = nullptr;
      v9 = GFxAmpThreadMgr::GFxAmpThreadMgr(
             this: v4,
             a2: this,
             a3: v8,
             a4: v6,
             a5: &this->SendingEvent,
             a6: this->SocketImplFactory);
    }
    else
    {
      v9 = nullptr;
    }
    v10 = (IShaderAPI *)this->ThreadMgr.pObject;
    if ( v10 != nullptr )
      GRefCountImpl::Release(this: v10);
    this->ThreadMgr.pObject = v9;
  }
  LeaveCriticalSection(lpCriticalSection: &this->ConnectionLock.cs);
  v11 = this->ThreadMgr.pObject;
  if ( v11 != nullptr && GFxAmpThreadMgr::InitAmp(this: v11, a2: nullptr, a3: this->Port, a4: this->BroadcastPort) )
  {
    GEvent::Wait(this: (CDbgFmtMsg *)&this->ConnectedEvent);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10075370
// Name: public: void GFxAmpServer::CloseConnection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::CloseConnection(GFxAmpServer *this)
{
  GLock *p_ConnectionLock; // edi
  IShaderAPI *pObject; // ecx

  p_ConnectionLock = &this->ConnectionLock;
  EnterCriticalSection(lpCriticalSection: &this->ConnectionLock.cs);
  pObject = (IShaderAPI *)this->ThreadMgr.pObject;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
  this->ThreadMgr.pObject = nullptr;
  LeaveCriticalSection(lpCriticalSection: &p_ConnectionLock->cs);
}

//------------------------------------------------------------------------------
// Address: 0x100753B0
// Name: private: void GFxAmpServer::ClearRendererData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::ClearRendererData(GFxAmpServer *this)
{
  GLock *p_LoaderLock; // ebx
  unsigned int v3; // eax
  GFxLoader *v4; // ecx
  int v5; // eax
  IShaderAPI *v6; // ebx
  IShaderAPI *v7; // edi
  unsigned int j; // edi
  GAmpRenderer *v9; // ecx
  GLock *v10; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  p_LoaderLock = &this->LoaderLock;
  this->NumFontCacheTextureUpdates = 0;
  v10 = &this->LoaderLock;
  EnterCriticalSection(lpCriticalSection: &this->LoaderLock.cs);
  v3 = 0;
  i = 0;
  if ( this->Loaders.Data.Size != 0 )
  {
    do
    {
      v4 = this->Loaders.Data.Data[v3];
      v5 = (int)v4->GetStateAddRef(this: v4, a2: State_RenderConfig);
      v6 = (IShaderAPI *)v5;
      if ( v5 != 0 )
      {
        v7 = *(IShaderAPI **)(v5 + 12);
        if ( v7 != nullptr )
          GRefCountImpl::AddRef(this: *(IShaderDevice **)(v5 + 12));
        GRefCountImpl::Release(this: v6);
        if ( v7 != nullptr )
        {
          GRefCountImpl::Release(this: v7);
          ((void (__thiscall *)(IShaderAPI *, _DWORD, int))v7->GetNumActiveDeformations)(a1: v7, a2: 0, a3: 1);
        }
      }
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < this->Loaders.Data.Size );
    p_LoaderLock = v10;
  }
  for ( j = 0; j < this->AmpRenderers.Data.Size; ++j )
  {
    v9 = this->AmpRenderers.Data.Data[j];
    (*(void (__thiscall **)(GAmpRenderer *, _DWORD, int))(*(_DWORD *)v9 + 12))(a1: v9, a2: 0, a3: 1);
  }
  LeaveCriticalSection(lpCriticalSection: &p_LoaderLock->cs);
}

//------------------------------------------------------------------------------
// Address: 0x10075480
// Name: public: void GFxAmpServer::ViewStats::CollectStats(class GFxAmpProfileFrame __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxAmpServer::ViewStats::CollectStats@<eax>(
        CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > *this@<ecx>,
        double a2@<st0>,
        struct GFxAmpProfileFrame *frameProfile,
        unsigned int index)
{
  int v5; // eax
  int v6; // esi
  unsigned int CurrentFrame; // eax
  _DWORD *v8; // eax
  IShaderAPI **v9; // edi
  int result; // eax
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // eax
  ID3D11DeviceContext *v14; // [esp+0h] [ebp-10h]
  unsigned int v15; // [esp+0h] [ebp-10h]
  unsigned int v16; // [esp+0h] [ebp-10h]
  unsigned int v17; // [esp+0h] [ebp-10h]
  unsigned int v18; // [esp+0h] [ebp-10h]
  GTexture *v19; // [esp+0h] [ebp-10h]
  int v20; // [esp+0h] [ebp-10h]
  const GImageInfo *v21; // [esp+0h] [ebp-10h]
  const GImageInfo *v22; // [esp+0h] [ebp-10h]
  const GImageInfo *v23; // [esp+0h] [ebp-10h]
  unsigned int v24; // [esp+4h] [ebp-Ch]
  unsigned int v25; // [esp+4h] [ebp-Ch]
  unsigned int v26; // [esp+4h] [ebp-Ch]
  unsigned int v27; // [esp+4h] [ebp-Ch]
  unsigned int v28; // [esp+4h] [ebp-Ch]
  unsigned int v29; // [esp+8h] [ebp-8h]
  int v30; // [esp+Ch] [ebp-4h] BYREF

  v30 = 2;
  if ( GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 68, a4: &v30) != nullptr )
  {
    GFxMovieStats::GFxMovieStats(this: v14, a2: v24, a3: v29, a4: (ID3D11SamplerState **)v30);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  GFxAmpViewStats::CollectTimingStats(this: (GFxAmpViewStats *)this->m_Size, a2: frameProfile);
  GFxAmpViewStats::CollectAmpInstructionStats(
    this: (GImageInfo *)this->m_Size,
    movieProfile: (GImage *)v6,
    locker: (unsigned int)v14,
    it: v24);
  GFxAmpViewStats::CollectAmpFunctionStats(
    this: (GImageInfo *)this->m_Size,
    movieProfile: (GImage *)v6,
    locker: v15,
    funcTimeIter: v25);
  GFxAmpViewStats::CollectAmpSourceLineStats(
    this: (GImageInfo *)this->m_Size,
    movieProfile: (GImage *)v6,
    sourceTimeIter: v16,
    locker: v26);
  GFxAmpViewStats::CollectMarkers(this: (GImageInfo *)this->m_Size, movieProfile: (GImage *)v6, locker: v17, it: v27);
  GFxAmpViewStats::CollectTimingStats(this: (GFxAmpViewStats *)this->m_Memory.m_nGrowSize, a2: frameProfile);
  GFxAmpViewStats::CollectAmpFunctionStats(
    this: (GImageInfo *)this->m_Memory.m_nGrowSize,
    movieProfile: (GImage *)v6,
    locker: v18,
    funcTimeIter: v28);
  *(_DWORD *)(v6 + 8) = GFxAmpViewStats::GetViewHandle(this: (GFxAmpViewStats *)this->m_Size);
  CurrentFrame = GFxAmpViewStats::GetCurrentFrame(this: (GFxAmpViewStats *)this->m_Size);
  *(_DWORD *)(v6 + 16) = CurrentFrame;
  *(_DWORD *)(v6 + 12) = CurrentFrame;
  GFxAmpViewStats::GetName(this: (GImageInfo *)this->m_Size, a2: v19);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v6 + 20),
    src: v8,
    a3: v20);
  *(_DWORD *)(v6 + 24) = GFxAmpViewStats::GetVersion(this: (GFxAmpViewStats *)this->m_Size);
  GFxAmpViewStats::GetWidth(result: v21);
  *(float *)(v6 + 28) = a2;
  GFxAmpViewStats::GetHeight(result: v22);
  *(float *)(v6 + 32) = a2;
  GFxAmpViewStats::GetFrameRate(result: v23);
  *(float *)(v6 + 36) = a2;
  *(_DWORD *)(v6 + 40) = GFxAmpViewStats::GetFrameCount(this: (GFxAmpViewStats *)this->m_Size);
  v9 = (IShaderAPI **)((char *)frameProfile->MovieStats.Data.Data + 4 * index);
  if ( *v9 != nullptr )
    GRefCountImpl::Release(this: *v9);
  *v9 = (IShaderAPI *)v6;
  result = *(_DWORD *)(v6 + 60);
  v11 = 0;
  if ( *(_DWORD *)(result + 12) != 0 )
  {
    v12 = 0;
    do
    {
      v13 = *(_DWORD *)(*(_DWORD *)(v6 + 60) + 8);
      if ( *(_DWORD *)(v13 + v12) == 31 && *(_DWORD *)(v13 + v12 + 4) == 1 )
        frameProfile->GradientFillCount += *(_DWORD *)(v13 + v12 + 16);
      result = *(_DWORD *)(v6 + 60);
      ++v11;
      v12 += 32;
    }
    while ( v11 < *(_DWORD *)(result + 12) );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100757B0
// Name: public: void GFxAmpServer::ToggleAmpState(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::ToggleAmpState(GFxAmpServer *this, unsigned int a2)
{
  GLock *p_CurrentStateLock; // ebx
  char v4; // al
  unsigned int v5; // edi
  GAmpRenderer *v6; // ecx
  GAmpRenderer *v7; // ecx
  bool v8; // [esp+Fh] [ebp-1h]
  bool v9; // [esp+1Bh] [ebp+Bh]

  p_CurrentStateLock = &this->CurrentStateLock;
  EnterCriticalSection(lpCriticalSection: &this->CurrentStateLock.cs);
  v4 = a2;
  this->CurrentState.StateFlags ^= a2;
  if ( a2 != 0 )
  {
    if ( (a2 & 2) != 0 )
    {
      EnterCriticalSection(lpCriticalSection: &p_CurrentStateLock->cs);
      v8 = (this->CurrentState.StateFlags & 2) != 0;
      LeaveCriticalSection(lpCriticalSection: &p_CurrentStateLock->cs);
      if ( v8 )
        GFxAmpServer::CloseConnection(this);
      else
        GFxAmpServer::OpenConnection(this);
      v4 = a2;
    }
    if ( (v4 & 8) != 0 )
    {
      EnterCriticalSection(lpCriticalSection: &p_CurrentStateLock->cs);
      v9 = (this->CurrentState.StateFlags & 8) != 0;
      LeaveCriticalSection(lpCriticalSection: &p_CurrentStateLock->cs);
      v5 = 0;
      if ( v9 )
      {
        if ( this->AmpRenderers.Data.Size != 0 )
        {
          do
          {
            v6 = this->AmpRenderers.Data.Data[v5];
            (*(void (__thiscall **)(GAmpRenderer *, int, _DWORD))(*(_DWORD *)v6 + 8))(a1: v6, a2: 17826336, a3: 0);
            ++v5;
          }
          while ( v5 < this->AmpRenderers.Data.Size );
        }
      }
      else if ( this->AmpRenderers.Data.Size != 0 )
      {
        do
        {
          v7 = this->AmpRenderers.Data.Data[v5];
          (*(void (__thiscall **)(GAmpRenderer *))(*(_DWORD *)v7 + 4))(a1: v7);
          ++v5;
        }
        while ( v5 < this->AmpRenderers.Data.Size );
      }
    }
    GFxAmpServer::SendCurrentState(this);
  }
  LeaveCriticalSection(lpCriticalSection: &p_CurrentStateLock->cs);
}

//------------------------------------------------------------------------------
// Address: 0x10075AA0
// Name: public: GFxAmpServer::ViewStats::ViewStats(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > *__thiscall GFxAmpServer::ViewStats::ViewStats(
        CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > *this,
        int a2)
{
  IShaderDevice *v3; // ecx
  IShaderDevice *v4; // ecx

  this->m_Memory.m_pMemory = (CMatRenderContextBase::PlaneStackElement *)&GRefCountImplCore::`vftable';
  this->m_Memory.m_nAllocationCount = 1;
  this->m_Memory.m_pMemory = (CMatRenderContextBase::PlaneStackElement *)&GFxAmpServer::ViewStats::`vftable';
  v3 = *(IShaderDevice **)(a2 + 10312);
  if ( v3 != nullptr )
    GRefCountImpl::AddRef(this: v3);
  this->m_Memory.m_nGrowSize = *(_DWORD *)(a2 + 10312);
  v4 = *(IShaderDevice **)(a2 + 10308);
  if ( v4 != nullptr )
    GRefCountImpl::AddRef(this: v4);
  this->m_Size = *(_DWORD *)(a2 + 10308);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10075C20
// Name: public: void GMsgFormat::FormatD1<char const __near *>(char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GMsgFormat::FormatD1<char const *>(
        CMatQueuedRenderContext::CCallQueueExternal *this,
        const CMatQueuedRenderContext::CCallQueueExternal *v)
{
  bool result; // al
  GMemoryHeap **v4; // esi
  GStrFormatter *v5; // eax
  unsigned int v6; // edx
  GMemoryHeap *v7; // ecx
  struct GFormatter *v8; // eax

  result = GMsgFormat::NextFormatter((GMsgFormat *)this);
  if ( result )
  {
    v4 = (GMemoryHeap **)(this + 61);
    do
    {
      if ( *((_DWORD *)this + 191) < 0x14u )
      {
        v7 = *v4;
        if ( *v4 == nullptr )
          v7 = GMemory::pGlobalHeap;
        v5 = (GStrFormatter *)v7->Alloc(this: v7, a2: 20u, a3: 4u, a4: nullptr);
      }
      else
      {
        v5 = *((GStrFormatter **)this + 190);
        *((_DWORD *)this + 190) = (((unsigned int)v5 + 19) & 0xFFFFFFFC) + 4;
        v6 = (((unsigned int)v5 + 19) & 0xFFFFFFFC) - (_DWORD)v4;
        if ( v6 >= 0x200 )
          *((_DWORD *)this + 191) = 0;
        else
          *((_DWORD *)this + 191) = 512 - v6;
      }
      if ( v5 != nullptr )
        v8 = (struct GFormatter *)GStrFormatter::GStrFormatter(
                                    this: v5,
                                    a2: (struct GMsgFormat *)this,
                                    a3: (const char *)v->__vftable);
      else
        v8 = nullptr;
      GMsgFormat::Bind((GMsgFormat *)this, a2: v8, a3: true);
      result = GMsgFormat::NextFormatter((GMsgFormat *)this);
    }
    while ( result );
  }
  ++*((_BYTE *)this + 5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10075FA0
// Name: public: void GFxAmpServer::AddMovie(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::AddMovie(ConVar *this, GRenderer_vtbl *movie)
{
  GRenderer::CachedData *v3; // edi
  unsigned int v4; // esi
  GRenderer *pRenderer; // edx
  GRenderer *v6; // esi
  CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > *v7; // eax
  CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > *v8; // edi
  CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > **v9; // esi
  int v10; // [esp+8h] [ebp-4h] BYREF

  if ( (*(_DWORD *)((*((int (__thiscall **)(GRenderer_vtbl *))movie->dtr_GRefCountImplCore + 61))(a1: movie) + 28)
      & 0x1000) == 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244));
    if ( *((_DWORD *)this + 41) != 0 )
    {
      if ( *((_DWORD *)this + 55) == 0 )
        *((_BYTE *)this + 228) = 0;
    }
    else
    {
      GFxAmpServer::OpenConnection((GFxAmpServer *)this);
    }
    v3 = (GRenderer::CachedData *)((char *)this + 216);
    v4 = *((_DWORD *)this + 55) + 1;
    if ( v4 >= *((_DWORD *)this + 55) )
    {
      if ( v4 >= *((_DWORD *)this + 56) )
        GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
          this: v3,
          pheapAddr: v3,
          newCapacity: v4 + (v4 >> 2));
    }
    else if ( v4 < *((_DWORD *)this + 56) >> 1 )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v3,
        pheapAddr: v3,
        newCapacity: v4);
    }
    pRenderer = v3->pRenderer;
    *((_DWORD *)this + 55) = v4;
    v6 = (GRenderer *)((char *)pRenderer + 4 * v4 - 4);
    if ( v6 != nullptr )
      v6->__vftable = movie;
    v10 = 2;
    v7 = (CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 16, a4: &v10);
    if ( v7 != nullptr )
      v8 = GFxAmpServer::ViewStats::ViewStats(this: v7, a2: (int)movie);
    else
      v8 = nullptr;
    GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (GRenderer::CachedData *)this + 29,
      result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)((char *)this + 232),
      newSize: *((_DWORD *)this + 59) + 1);
    v9 = (CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > **)(*((_DWORD *)this + 58) + 4 * *((_DWORD *)this + 59) - 4);
    if ( *((_DWORD *)this + 58) + 4 * *((_DWORD *)this + 59) != 4 )
    {
      if ( v8 != nullptr )
        GRefCountImpl::AddRef(this: (IShaderDevice *)v8);
      *v9 = v8;
    }
    if ( v8 != nullptr )
      GRefCountImpl::Release(this: (IShaderAPI *)v8);
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100760C0
// Name: public: void GFxAmpServer::RefreshMovieStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::RefreshMovieStats(GFxAmpServer *this)
{
  GLock *p_MovieLock; // esi
  bool v3; // zf
  IShaderDevice *v4; // eax
  IShaderDevice *v5; // esi
  struct GFxMovieRoot *v6; // edi
  IShaderDevice *v7; // ecx
  IShaderDevice *v8; // ecx
  IShaderDevice *v9; // edi
  IShaderDevice **v10; // esi
  GLock *v11; // [esp+8h] [ebp-Ch]
  int v12; // [esp+Ch] [ebp-8h] BYREF
  unsigned int i; // [esp+10h] [ebp-4h]

  p_MovieLock = &this->MovieLock;
  v11 = &this->MovieLock;
  EnterCriticalSection(lpCriticalSection: &this->MovieLock.cs);
  GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GRenderer::CachedData *)&this->MovieStats,
    result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)&this->MovieStats,
    newSize: 0);
  v3 = this->Movies.Data.Size == 0;
  i = 0;
  if ( !v3 )
  {
    do
    {
      v12 = 2;
      v4 = (IShaderDevice *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                              this: GMemory::pGlobalHeap,
                              a2: this,
                              a3: 16,
                              a4: &v12);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v6 = this->Movies.Data.Data[i];
        v4->__vftable = (IShaderDevice_vtbl *)&GRefCountImplCore::`vftable';
        v4[1].__vftable = (IShaderDevice_vtbl *)1;
        v4->__vftable = (IShaderDevice_vtbl *)&GFxAmpServer::ViewStats::`vftable';
        v7 = *((IShaderDevice **)v6 + 2578);
        if ( v7 != nullptr )
          GRefCountImpl::AddRef(this: v7);
        v5[2].__vftable = *(IShaderDevice_vtbl **)((char *)v6 + 10312);
        v8 = *((IShaderDevice **)v6 + 2577);
        if ( v8 != nullptr )
          GRefCountImpl::AddRef(this: v8);
        v5[3].__vftable = *(IShaderDevice_vtbl **)((char *)v6 + 10308);
        v9 = v5;
      }
      else
      {
        v9 = nullptr;
      }
      GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: (GRenderer::CachedData *)&this->MovieStats,
        result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)&this->MovieStats,
        newSize: this->MovieStats.Data.Size + 1);
      v10 = (IShaderDevice **)((char *)this->MovieStats.Data.Data + 4 * this->MovieStats.Data.Size - 4);
      if ( (GPtr<GFxAmpServer::ViewStats> *)((char *)this->MovieStats.Data.Data + 4 * this->MovieStats.Data.Size) != (GPtr<GFxAmpServer::ViewStats> *)4 )
      {
        if ( v9 != nullptr )
          GRefCountImpl::AddRef(this: v9);
        *v10 = v9;
      }
      if ( v9 != nullptr )
        GRefCountImpl::Release(this: (IShaderAPI *)v9);
      ++i;
    }
    while ( i < this->Movies.Data.Size );
    p_MovieLock = v11;
  }
  LeaveCriticalSection(lpCriticalSection: &p_MovieLock->cs);
}

//------------------------------------------------------------------------------
// Address: 0x100761E0
// Name: public: void GFxAmpServer::AddLoader(class GFxLoader __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::AddLoader(ConVar *this, GRenderer_vtbl *a2)
{
  _RTL_CRITICAL_SECTION *v3; // ebx
  GRenderer::CachedData *v4; // edi
  unsigned int v5; // esi
  GRenderer *v6; // eax

  v3 = (_RTL_CRITICAL_SECTION *)((char *)this + 292);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 292));
  v4 = (GRenderer::CachedData *)((char *)this + 268);
  v5 = *((_DWORD *)this + 68) + 1;
  if ( (void *)v5 >= v4->hData )
  {
    if ( (GRenderer *)v5 >= v4[1].pRenderer )
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v4,
        pheapAddr: v4,
        newCapacity: v5 + (v5 >> 2));
  }
  else if ( v5 < (unsigned int)v4[1].pRenderer >> 1 )
  {
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v4,
      pheapAddr: v4,
      newCapacity: v5);
  }
  v6 = (GRenderer *)((char *)v4->pRenderer + 4 * v5 - 4);
  v4->hData = (void *)v5;
  if ( v6 != nullptr )
    v6->__vftable = a2;
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10076250
// Name: private: void GFxAmpServer::ClearMovieData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::ClearMovieData(GFxAmpServer *this)
{
  GLock *p_MovieLock; // esi
  unsigned int v3; // ebx
  int v4; // esi
  const GImageInfo *v5; // [esp+0h] [ebp-10h]
  const GImageInfo *v6; // [esp+0h] [ebp-10h]
  const GImageInfo *v7; // [esp+0h] [ebp-10h]
  const GImageInfo *v8; // [esp+0h] [ebp-10h]
  const GImageInfo *v9; // [esp+0h] [ebp-10h]
  const GImageInfo *v10; // [esp+0h] [ebp-10h]

  GFxAmpServer::RefreshMovieStats(this);
  p_MovieLock = &this->MovieLock;
  EnterCriticalSection(lpCriticalSection: &this->MovieLock.cs);
  v3 = 0;
  if ( this->MovieStats.Data.Size != 0 )
  {
    do
    {
      v4 = *((_DWORD *)this->MovieStats.Data.Data + v3);
      GFxAmpViewStats::ClearAmpFunctionStats(this: *(GImageInfo **)(v4 + 12), locker: v5);
      GFxAmpViewStats::ClearAmpInstructionStats(this: *(GImageInfo **)(v4 + 12), a2: v6);
      GFxAmpViewStats::ClearAmpSourceLineStats(this: *(GImageInfo **)(v4 + 12), locker: v7);
      GFxAmpViewStats::ClearMarkers(this: *(GImageInfo **)(v4 + 12), a2: v8);
      GFxAmpViewStats::ClearAmpFunctionStats(this: *(GImageInfo **)(v4 + 8), locker: v9);
      GFxAmpViewStats::ClearAmpInstructionStats(this: *(GImageInfo **)(v4 + 8), a2: v10);
      ++v3;
    }
    while ( v3 < this->MovieStats.Data.Size );
    p_MovieLock = &this->MovieLock;
  }
  LeaveCriticalSection(lpCriticalSection: &p_MovieLock->cs);
}

//------------------------------------------------------------------------------
// Address: 0x100762E0
// Name: private: void GFxAmpServer::CollectRendererData(class GFxAmpProfileFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpServer::CollectRendererData(ConVar *this@<ecx>, const char *frameProfile, float renderers)
{
  GFxAmpServer *v5; // ebx
  GLock *p_CurrentStateLock; // edi
  unsigned int v7; // ebx
  GFxLoader *v8; // ecx
  int v9; // eax
  IShaderAPI *v10; // edi
  IShaderAPI *v11; // ebx
  int v12; // eax
  unsigned int v13; // edi
  IShaderAPI **v14; // edi
  GFxLoader *v15; // ecx
  IShaderAPI *v16; // eax
  IShaderAPI *v17; // ebx
  int v18; // eax
  unsigned int v19; // edi
  IShaderAPI **v20; // edi
  GFxLoader *v21; // ecx
  IShaderAPI *v22; // eax
  IShaderAPI *v23; // edi
  _DWORD *v24; // edx
  int v25; // eax
  unsigned int v26; // ebx
  unsigned int v27; // edi
  _DWORD *v28; // eax
  unsigned int v29; // edi
  int *v30; // edx
  GFxAmpServer *v31; // ebx
  GLock *v32; // edi
  unsigned int v33; // ebx
  int v34; // eax
  unsigned int v35; // ebx
  int v36; // edi
  unsigned int v37; // edi
  GAmpRenderer **v38; // eax
  unsigned int v39; // eax
  GAmpRenderer **v40; // ebx
  unsigned int j; // edi
  int v42; // edx
  int v43; // ecx
  int v44; // edx
  unsigned int k; // edi
  int v46; // ecx
  int v47; // eax
  int v48; // ecx
  unsigned int m; // edi
  unsigned int v50; // edi
  Vector **n; // ebx
  int v52; // eax
  int v53; // eax
  float v54; // [esp+0h] [ebp-60h]
  float v55; // [esp+0h] [ebp-60h]
  float v56; // [esp+4h] [ebp-5Ch]
  float v57; // [esp+4h] [ebp-5Ch]
  float v58; // [esp+8h] [ebp-58h]
  float v59; // [esp+8h] [ebp-58h]
  int v60; // [esp+Ch] [ebp-54h] BYREF
  int v61; // [esp+10h] [ebp-50h]
  int v62; // [esp+14h] [ebp-4Ch]
  int v63; // [esp+18h] [ebp-48h]
  int v64; // [esp+1Ch] [ebp-44h]
  IShaderAPI **v65; // [esp+20h] [ebp-40h] BYREF
  unsigned int v66; // [esp+24h] [ebp-3Ch]
  unsigned int v67; // [esp+28h] [ebp-38h]
  _DWORD *v68; // [esp+2Ch] [ebp-34h] BYREF
  unsigned int v69; // [esp+30h] [ebp-30h]
  unsigned int v70; // [esp+34h] [ebp-2Ch]
  _DWORD *v71; // [esp+38h] [ebp-28h]
  unsigned int v72; // [esp+3Ch] [ebp-24h]
  unsigned int v73; // [esp+40h] [ebp-20h]
  GAmpRenderer **v74; // [esp+44h] [ebp-1Ch]
  unsigned int v75; // [esp+48h] [ebp-18h]
  unsigned int v76; // [esp+4Ch] [ebp-14h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+50h] [ebp-10h]
  int v78; // [esp+54h] [ebp-Ch] BYREF
  int v79; // [esp+58h] [ebp-8h] BYREF
  GFxAmpServer *v80; // [esp+5Ch] [ebp-4h]
  unsigned int i; // [esp+68h] [ebp+8h]
  unsigned int ia; // [esp+68h] [ebp+8h]

  *((_DWORD *)frameProfile + 28) = *((_DWORD *)this + 115);
  v80 = (GFxAmpServer *)this;
  v65 = nullptr;
  v66 = 0;
  v67 = 0;
  v74 = nullptr;
  v75 = 0;
  v76 = 0;
  v68 = nullptr;
  v69 = 0;
  v70 = 0;
  v71 = nullptr;
  v72 = 0;
  v73 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)((char *)this + 292);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 292));
  i = 0;
  if ( *((_DWORD *)this + 68) != 0 )
  {
    while ( 1 )
    {
      v5 = v80;
      p_CurrentStateLock = &v80->CurrentStateLock;
      EnterCriticalSection(lpCriticalSection: &v80->CurrentStateLock.cs);
      v7 = v5->CurrentState.StateFlags >> 3;
      LeaveCriticalSection(lpCriticalSection: &p_CurrentStateLock->cs);
      if ( (v7 & 1) == 0 )
      {
        v8 = v80->Loaders.Data.Data[i];
        v9 = (int)v8->GetStateAddRef(this: v8, a2: State_RenderConfig);
        v10 = (IShaderAPI *)v9;
        if ( v9 != 0 )
        {
          v11 = *(IShaderAPI **)(v9 + 12);
          if ( v11 != nullptr )
            GRefCountImpl::AddRef(this: *(IShaderDevice **)(v9 + 12));
          GRefCountImpl::Release(this: v10);
          if ( v11 != nullptr )
          {
            GRefCountImpl::Release(this: v11);
            v12 = 0;
            if ( v66 != 0 )
            {
              while ( v65[v12] != v11 )
              {
                if ( ++v12 >= v66 )
                  goto LABEL_10;
              }
            }
            else
            {
LABEL_10:
              v13 = v66 + 1;
              if ( v66 + 1 >= v66 )
              {
                if ( v13 >= v67 )
                  GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                    this: (CVertexBuilder *)&v65,
                    pheapAddr: (ButtonCode_t)&v65,
                    newCapacity: v13 + (v13 >> 2));
              }
              else if ( v13 < v67 >> 1 )
              {
                GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                  this: (CVertexBuilder *)&v65,
                  pheapAddr: (ButtonCode_t)&v65,
                  newCapacity: v66 + 1);
              }
              v66 = v13;
              v14 = &v65[v13 - 1];
              if ( v14 != nullptr )
                *v14 = v11;
            }
          }
        }
      }
      v15 = v80->Loaders.Data.Data[i];
      v16 = (IShaderAPI *)v15->GetStateAddRef(this: v15, a2: State_MeshCacheManager);
      v17 = v16;
      if ( v16 != nullptr )
      {
        GRefCountImpl::Release(this: v16);
        v18 = 0;
        if ( v69 != 0 )
        {
          while ( (IShaderAPI *)v68[v18] != v17 )
          {
            if ( ++v18 >= v69 )
              goto LABEL_21;
          }
        }
        else
        {
LABEL_21:
          v19 = v69 + 1;
          if ( v69 + 1 >= v69 )
          {
            if ( v19 >= v70 )
              GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                this: (CVertexBuilder *)&v68,
                pheapAddr: (ButtonCode_t)&v68,
                newCapacity: v19 + (v19 >> 2));
          }
          else if ( v19 < v70 >> 1 )
          {
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&v68,
              pheapAddr: (ButtonCode_t)&v68,
              newCapacity: v69 + 1);
          }
          v69 = v19;
          v20 = (IShaderAPI **)&v68[v19 - 1];
          if ( v20 != nullptr )
            *v20 = v17;
        }
      }
      v21 = v80->Loaders.Data.Data[i];
      v22 = (IShaderAPI *)v21->GetStateAddRef(this: v21, a2: State_FontCacheManager);
      v23 = v22;
      v78 = (int)v22;
      if ( v22 == nullptr )
        goto LABEL_51;
      GRefCountImpl::Release(this: v22);
      v24 = v71;
      v25 = 0;
      if ( v72 != 0 )
      {
        while ( (IShaderAPI *)v71[v25] != v23 )
        {
          if ( ++v25 >= v72 )
            goto LABEL_32;
        }
        goto LABEL_51;
      }
LABEL_32:
      v26 = v72 + 1;
      if ( v72 + 1 >= v72 )
        break;
      if ( v26 >= v73 >> 1 )
        goto LABEL_49;
      if ( v72 != -1 )
      {
        v27 = 4 * ((v72 + 4) >> 2);
        if ( v71 != nullptr )
        {
          v28 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v71, a3: 16 * ((v72 + 4) >> 2));
LABEL_47:
          v24 = v28;
          v73 = v27;
          goto LABEL_48;
        }
        goto LABEL_46;
      }
      if ( v71 == nullptr )
        goto LABEL_43;
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v71);
      v24 = nullptr;
      v73 = 0;
LABEL_48:
      v71 = v24;
LABEL_49:
      v30 = &v24[v26 - 1];
      v72 = v26;
      if ( v30 != nullptr )
        *v30 = v78;
LABEL_51:
      if ( ++i >= v80->Loaders.Data.Size )
        goto LABEL_52;
    }
    if ( v26 < v73 )
      goto LABEL_49;
    v29 = v26 + (v26 >> 2);
    if ( v29 == 0 )
    {
      if ( v71 != nullptr )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v71);
        v24 = nullptr;
        v71 = nullptr;
      }
LABEL_43:
      v73 = 0;
      goto LABEL_49;
    }
    v27 = 4 * ((v29 + 3) >> 2);
    if ( v71 != nullptr )
    {
      v28 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v71, a3: 4 * v27);
      goto LABEL_47;
    }
LABEL_46:
    v79 = 2;
    v28 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * v27, a3: &v79);
    goto LABEL_47;
  }
LABEL_52:
  v31 = v80;
  v32 = &v80->CurrentStateLock;
  EnterCriticalSection(lpCriticalSection: &v80->CurrentStateLock.cs);
  v33 = v31->CurrentState.StateFlags >> 3;
  LeaveCriticalSection(lpCriticalSection: &v32->cs);
  if ( (v33 & 1) != 0 )
  {
    for ( ia = 0; ia < v80->AmpRenderers.Data.Size; ++ia )
    {
      v34 = 0;
      if ( v75 != 0 )
      {
        while ( v74[v34] != v80->AmpRenderers.Data.Data[ia] )
        {
          if ( ++v34 >= v75 )
            goto LABEL_57;
        }
        continue;
      }
LABEL_57:
      v79 = (int)&v80->AmpRenderers.Data.Data[ia];
      v35 = v75 + 1;
      if ( v75 + 1 >= v75 )
      {
        if ( v35 < v76 )
          goto LABEL_73;
        v39 = v35 + (v35 >> 2);
        if ( v39 != 0 )
        {
          v37 = v39 + 3;
          goto LABEL_63;
        }
        v36 = 0;
        if ( v74 != nullptr )
        {
LABEL_61:
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v74);
          v74 = nullptr;
        }
      }
      else
      {
        if ( v35 >= v76 >> 1 )
          goto LABEL_73;
        v36 = 0;
        if ( v75 != -1 )
        {
          v37 = v75 + 4;
LABEL_63:
          v36 = 4 * (v37 >> 2);
          if ( v74 != nullptr )
          {
            v38 = (GAmpRenderer **)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v74, a3: 4 * v36);
          }
          else
          {
            v78 = 2;
            v38 = (GAmpRenderer **)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * v36, a3: &v78);
          }
          v74 = v38;
          goto LABEL_72;
        }
        if ( v74 != nullptr )
          goto LABEL_61;
      }
LABEL_72:
      v76 = v36;
LABEL_73:
      v75 = v35;
      v40 = &v74[v35 - 1];
      if ( v40 != nullptr )
        *v40 = *(GAmpRenderer **)v79;
    }
  }
  for ( j = 0; j < v66; ++j )
  {
    v60 = 0;
    v61 = 0;
    v62 = 0;
    v63 = 0;
    v64 = 0;
    ((void (__thiscall *)(IShaderAPI *, int *, _DWORD))v65[j]->GetNumActiveDeformations)(a1: v65[j], a2: &v60, a3: 0);
    v42 = v63;
    *((_DWORD *)frameProfile + 21) += v60;
    *((_DWORD *)frameProfile + 19) += v42;
    v43 = v61;
    v44 = v62;
    *((_DWORD *)frameProfile + 20) += v64;
    *((_DWORD *)frameProfile + 18) += v43;
    *((_DWORD *)frameProfile + 22) += v44;
  }
  for ( k = 0; k < v75; ++k )
  {
    v60 = 0;
    v61 = 0;
    v62 = 0;
    v63 = 0;
    v64 = 0;
    (*(void (__thiscall **)(GAmpRenderer *, int *, _DWORD))(*(_DWORD *)v74[k] + 12))(a1: v74[k], a2: &v60, a3: 0);
    v46 = v63;
    *((_DWORD *)frameProfile + 21) += v60;
    *((_DWORD *)frameProfile + 19) += v46;
    v47 = v61;
    v48 = v62;
    *((_DWORD *)frameProfile + 20) += v64;
    *((_DWORD *)frameProfile + 18) += v47;
    *((_DWORD *)frameProfile + 22) += v48;
  }
  for ( m = 0; m < v69; ++m )
  {
    *((_DWORD *)frameProfile + 23) += GFxMeshCacheManager::GetNumStrokes(this: (GFxMeshCacheManager *)v68[m]);
    *((_DWORD *)frameProfile + 25) += GFxMeshCacheManager::GetMeshThrashing(this: (GFxMeshCacheManager *)v68[m]);
  }
  v50 = 0;
  for ( n = (Vector **)v71; v50 < v72; ++v50 )
  {
    GFxFontCacheManager::GetNumRasterizedGlyphs(this: n[v50], a2: v54, a3: v56, a4: v58);
    *((_DWORD *)frameProfile + 26) += v52;
    GFxFontCacheManager::GetNumTextures(this: n[v50], a2: v55, a3: v57, a4: v59);
    *((_DWORD *)frameProfile + 27) += v53;
  }
  GFxAmpServer::ClearRendererData(this: v80);
  LeaveCriticalSection(lpCriticalSection);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: n);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v68);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v74);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v65);
}

//------------------------------------------------------------------------------
// Address: 0x10076A70
// Name: public: GFxAmpMemItem::GFxAmpMemItem(unsigned long)
// Source: json
//------------------------------------------------------------------------------
CFunctorCallbackBase *__thiscall GFxAmpMemItem::GFxAmpMemItem(char *this, CFunctorCallbackBase *result)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxAmpMemItem::`vftable';
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(this + 8));
  *((_DWORD *)this + 3) = 0;
  *((_WORD *)this + 8) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 5) = result;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  return (CFunctorCallbackBase *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10076AC0
// Name: public: virtual GFxAmpMemItem::~GFxAmpMemItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMemItem::~GFxAmpMemItem(GFxAmpMemItem *this)
{
  unsigned int Size; // eax
  IShaderAPI **v3; // esi
  unsigned int v4; // ebx
  volatile LONG *v5; // esi

  Size = this->Children.Data.Size;
  v3 = (IShaderAPI **)&this->Children.Data.Data[Size - 1];
  if ( Size != 0 )
  {
    v4 = this->Children.Data.Size;
    do
    {
      if ( *v3 != nullptr )
        GRefCountImpl::Release(this: *v3);
      --v3;
      --v4;
    }
    while ( v4 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->Children.Data.Data);
  v5 = (volatile LONG *)(this->Name.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v5 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v5);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10076B60
// Name: public: void GFxAmpServer::RemoveMovie(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::RemoveMovie(ConVar *this, int movie)
{
  unsigned int v3; // edx
  const char *v4; // eax
  _DWORD *v5; // edi
  IShaderAPI *v6; // ecx

  if ( (*(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)movie + 244))(a1: movie) + 28) & 0x1000) == 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244));
    v3 = *((_DWORD *)this + 55);
    v4 = nullptr;
    if ( v3 != 0 )
    {
      v5 = *((_DWORD **)this + 54);
      while ( *v5 != movie )
      {
        ++v4;
        ++v5;
        if ( (unsigned int)v4 >= v3 )
          goto LABEL_8;
      }
      GArrayBase<GArrayDataDH<GFxTimelineSnapshot::SnapshotElement *,GAllocatorDH_POD<GFxTimelineSnapshot::SnapshotElement *,2>,GArrayDefaultPolicy>>::RemoveAt(
        this: (CThread *)((char *)this + 216),
        index: v4);
    }
LABEL_8:
    if ( *((_DWORD *)this + 55) == 0 && *((_BYTE *)this + 228) != 0 )
    {
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this + 7);
      v6 = *((IShaderAPI **)this + 41);
      if ( v6 != nullptr )
        GRefCountImpl::Release(this: v6);
      *((_DWORD *)this + 41) = 0;
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this + 7);
    }
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076C20
// Name: public: void GFxAmpServer::RemoveLoader(class GFxLoader __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::RemoveLoader(ConVar *this, int a2)
{
  unsigned int v3; // ecx
  unsigned int v4; // eax
  _DWORD *v5; // edx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+4h] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 292);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 292));
  v3 = *((_DWORD *)this + 68);
  v4 = 0;
  if ( v3 == 0 )
    goto LABEL_13;
  v5 = *((_DWORD **)this + 67);
  while ( *v5 != a2 )
  {
    ++v4;
    ++v5;
    if ( v4 >= v3 )
      goto LABEL_13;
  }
  if ( v3 != 1 )
  {
    memmove(
      dst: (unsigned __int8 *)(*((_DWORD *)this + 67) + 4 * v4),
      src: (unsigned __int8 *)(*((_DWORD *)this + 67) + 4 * v4 + 4),
      count: 4 * (v3 - v4) - 4);
    --*((_DWORD *)this + 68);
LABEL_13:
    LeaveCriticalSection(lpCriticalSection);
    return;
  }
  if ( (*((_DWORD *)this + 69) & 0xFFFFFFFE) != 0 )
  {
    if ( *((_DWORD *)this + 67) != 0 )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 67));
      *((_DWORD *)this + 67) = 0;
    }
    *((_DWORD *)this + 69) = 0;
  }
  *((_DWORD *)this + 68) = 0;
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x10076D10
// Name: public: class GString GFxAmpServer::GetSwdFilename(unsigned long)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::GetSwdFilename(
        ConVar *this,
        CCountedStringPoolBase<unsigned int> *handle,
        unsigned int handlea)
{
  _RTL_CRITICAL_SECTION *v4; // edi
  int **v5; // eax
  int *v6; // ecx
  int v7; // eax
  int v8; // ecx
  int *v9; // [esp+8h] [ebp-8h] BYREF

  v4 = (_RTL_CRITICAL_SECTION *)((char *)this + 320);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 320));
  v5 = GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF>>::FindAlt<unsigned long>(
         this: (int *)this + 79,
         a2: &v9,
         a3: &handlea);
  v6 = *v5;
  v7 = (int)v5[1];
  if ( v6 != nullptr && (v8 = *v6) != 0 && v7 <= *(_DWORD *)(v8 + 4) )
  {
    GString::GString(this: handle, result: (CImagePacker *)(*(_DWORD *)(v8 + 16 * v7 + 20) + 12));
    LeaveCriticalSection(lpCriticalSection: v4);
  }
  else
  {
    GString::GString(this: (GString *)handle, src: (int)&pMem);
    LeaveCriticalSection(lpCriticalSection: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076DA0
// Name: public: class GString GFxAmpServer::GetSourceFilename(unsigned __int64)const
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned int> *__thiscall GFxAmpServer::GetSourceFilename(
        ConVar *this,
        CCountedStringPoolBase<unsigned int> *handle,
        unsigned __int64 handlea)
{
  _RTL_CRITICAL_SECTION *v4; // edi
  int **v5; // eax
  int *v6; // ecx
  int v7; // eax
  int v8; // ecx
  int *v10; // [esp+8h] [ebp-8h] BYREF

  v4 = (_RTL_CRITICAL_SECTION *)((char *)this + 348);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 348));
  v5 = GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::FindAlt<unsigned __int64>(
         this: (int *)this + 86,
         a2: &v10,
         a3: &handlea);
  v6 = *v5;
  v7 = (int)v5[1];
  if ( v6 != nullptr && (v8 = *v6) != 0 && v7 <= *(_DWORD *)(v8 + 4) )
  {
    GString::GString(this: handle, result: (CImagePacker *)(*(_DWORD *)(v8 + 8 * (3 * v7 + 3)) + 8));
    LeaveCriticalSection(lpCriticalSection: v4);
    return handle;
  }
  else
  {
    GString::GString(this: (GString *)handle, src: (int)&pMem);
    LeaveCriticalSection(lpCriticalSection: v4);
    return handle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076E30
// Name: public: virtual void GFxAmpImageVisitor::Visit(class GFxMovieDef __near *,class GFxResource __near *,class GFxResourceId,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpImageVisitor::Visit(
        GFxAmpImageVisitor *this,
        struct GFxMovieDef *a2,
        IShaderDevice *a3,
        struct GFxResourceId a4,
        const char *a5)
{
  int v6; // eax
  CVertexBuilder *v7; // esi
  IShaderDevice **v8; // esi

  if ( (a3->GetBackBufferFormat(this: a3) & 0xFF00) == 0x100 )
  {
    GRefCountImpl::AddRef(this: a3);
    v6 = *((_DWORD *)this + 2);
    v7 = (CVertexBuilder *)((char *)this + 4);
    GArrayDataBase<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v7,
      a2: (int)v7,
      a3: v6 + 1);
    v8 = (IShaderDevice **)(v7->m_VertexSize_Position + 4 * v7->m_VertexSize_BoneWeight - 4);
    if ( v8 != nullptr )
    {
      GRefCountImpl::AddRef(this: a3);
      *v8 = a3;
    }
    GFxResource::Release(this: a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076E90
// Name: public: virtual GFxAmpImageVisitor::~GFxAmpImageVisitor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpImageVisitor::~GFxAmpImageVisitor(GFxAmpImageVisitor *this)
{
  int v2; // eax
  IShaderDevice **v3; // esi
  int v4; // ebx

  v2 = *((_DWORD *)this + 2);
  v3 = (IShaderDevice **)(*((_DWORD *)this + 1) + 4 * v2 - 4);
  if ( v2 != 0 )
  {
    v4 = *((_DWORD *)this + 2);
    do
    {
      if ( *v3 != nullptr )
        GFxResource::Release(this: *v3);
      --v3;
      --v4;
    }
    while ( v4 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 1));
  *(_DWORD *)this = &GString::InitStruct::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10076F10
// Name: private: void GFxAmpServer::CollectMovieData(class GFxAmpProfileFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpServer::CollectMovieData(
        ConVar *this@<ecx>,
        double a2@<st0>,
        GRenderer::CachedData *frameProfile,
        float lock)
{
  unsigned int v5; // esi
  unsigned int v6; // esi
  GRenderer_vtbl **i; // eax
  unsigned int j; // esi
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-8h]
  void *hData; // [esp+10h] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 244);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244));
  v5 = *((_DWORD *)this + 59);
  hData = frameProfile[19].hData;
  GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: frameProfile + 19,
    result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)&frameProfile[19],
    newSize: v5);
  if ( v5 > (unsigned int)hData )
  {
    v6 = v5 - (_DWORD)hData;
    for ( i = &frameProfile[19].pRenderer->__vftable + (_DWORD)hData; v6 != 0; --v6 )
    {
      if ( i != nullptr )
        *i = nullptr;
      ++i;
    }
  }
  for ( j = 0; j < *((_DWORD *)this + 59); ++j )
    GFxAmpServer::ViewStats::CollectStats(
      this: *(CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > **)(*((_DWORD *)this + 58) + 4 * j),
      a2,
      (struct GFxAmpProfileFrame *)frameProfile,
      index: j);
  GFxAmpServer::ClearMovieData((GFxAmpServer *)this);
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x100772D0
// Name: public: virtual bool GFxAmpServer::HandleSwdRequest(class GFxAmpMessageSwdRequest const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpServer::HandleSwdRequest(
        ConVar *this@<ecx>,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > msg)
{
  int v3; // edi
  int v4; // ecx
  IShaderDevice *v5; // eax
  IShaderAPI *v6; // esi
  void (__cdecl **m_pMemory)(int); // esi
  ImageFormat ErrorCode; // edi
  int v9; // eax
  unsigned int Length; // eax
  unsigned int v11; // edi
  void (__cdecl **v12)(int); // esi
  struct GString v13; // eax
  void *v14; // esi
  volatile LONG *v15; // esi
  void (__thiscall *GetLightmapDimensions)(struct IShaderAPI *, int *, int *); // eax
  int v17; // eax
  IShaderAPI *v18; // esi
  unsigned int v19; // eax
  int v20; // edi
  struct GFxAmpMessage *v21; // eax
  struct GFxAmpMessage *v22; // eax
  void *v23; // esi
  void *v24; // esi
  int v25; // [esp+0h] [ebp-2Ch]
  void *v26; // [esp+10h] [ebp-1Ch] BYREF
  int *v27; // [esp+14h] [ebp-18h] BYREF
  GString v28; // [esp+18h] [ebp-14h] BYREF
  unsigned int handle; // [esp+1Ch] [ebp-10h] BYREF
  int v30; // [esp+20h] [ebp-Ch] BYREF
  IShaderAPI *v31; // [esp+24h] [ebp-8h]
  GString v32; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  v31 = nullptr;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 292));
  if ( *((_DWORD *)this + 68) != 0 )
  {
    while ( 1 )
    {
      v4 = *(_DWORD *)(*((_DWORD *)this + 67) + 4 * v3);
      v5 = (IShaderDevice *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 12))(a1: v4, a2: 10);
      v6 = (IShaderAPI *)v5;
      if ( v5 != nullptr )
        GRefCountImpl::AddRef(this: v5);
      v31 = v6;
      if ( v6 != nullptr )
        break;
      if ( (unsigned int)++v3 >= *((_DWORD *)this + 68) )
        goto LABEL_8;
    }
    GRefCountImpl::Release(this: v6);
  }
LABEL_8:
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 292));
  if ( v31 != nullptr )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 320));
    m_pMemory = msg.m_Memory.m_pMemory;
    ErrorCode = GFILEFile::GetErrorCode(this: (CVTFTexture *)msg.m_Memory.m_pMemory);
    handle = ErrorCode;
    GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF>>::FindAlt<unsigned long>(
      this: (int *)this + 79,
      a2: &v27,
      a3: &handle);
    if ( v27 != nullptr && *v27 != 0 && (int)v28.pData <= *(_DWORD *)(*v27 + 4) )
    {
      GFxAmpServer::GetSwdFilename(this, handle: (CCountedStringPoolBase<unsigned int> *)&v30, handlea: ErrorCode);
      v9 = v30;
      if ( (*(_DWORD *)(v30 & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
      {
        if ( GFxAmpMessageSwdRequest::IsRequestContents(this: (GFxAmpMessageSwdRequest *)m_pMemory) )
        {
          GString::GString(this: (CCountedStringPoolBase<unsigned int> *)&v32, result: (CImagePacker *)&v30);
          Length = GString::GetLength(this: &v32);
          if ( Length > 4 )
          {
            v11 = Length - 4;
            GString::Substring(this: &v32, a2: (GString *)&msg, a3: Length - 4, a4: Length);
            v12 = msg.m_Memory.m_pMemory;
            if ( strcmp((const char *)(((int)msg.m_Memory.m_pMemory & 0xFFFFFFFC) + 8), ".swf") == 0
              || GString::operator==(this: &msg, a2: ".gfx") )
            {
              v13.pData = GString::Substring(this: &v32, a2: &v28, a3: 0, a4: v11).pData;
              GString::operator=(
                this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v32,
                src: v13.pData,
                a3: v25);
              v14 = (void *)(v28.HeapTypeBits & 0xFFFFFFFC);
              if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v28.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
                GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
              v12 = msg.m_Memory.m_pMemory;
            }
            v15 = (volatile LONG *)((unsigned int)v12 & 0xFFFFFFFC);
            if ( InterlockedExchangeAdd(Addend: v15 + 1, Value: -1) == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v15);
          }
          GString::AppendString(
            this: (CUtlMemory<CImagePacker,int> *)&v32,
            putf8str: (CImagePacker *)".swd",
            utf8StrSz: -1);
          GetLightmapDimensions = v31->GetLightmapDimensions;
          HIBYTE(msg.m_Memory.m_pMemory) = 0;
          v17 = ((int (__thiscall *)(IShaderAPI *, unsigned int, int, int))GetLightmapDimensions)(
                  a1: v31,
                  a2: (v32.HeapTypeBits & 0xFFFFFFFC) + 8,
                  a3: 33,
                  a4: 438);
          v18 = (IShaderAPI *)v17;
          if ( v17 == 0 || (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 24))(a1: v17) <= 0 )
            goto LABEL_30;
          v19 = ((int (__thiscall *)(IShaderAPI *))v18->SetDefaultState)(a1: v18);
          GArray<unsigned char,2,GArrayDefaultPolicy>::GArray<unsigned char,2,GArrayDefaultPolicy>(
            this: &v26,
            size: v19);
          v20 = ((int (__thiscall *)(IShaderAPI *, void *, int *))v18->GetCurrentFogType)(a1: v18, a2: v26, a3: v27);
          if ( v20 == ((int (__thiscall *)(IShaderAPI *))v18->SetDefaultState)(a1: v18) )
          {
            msg.m_Memory.m_pMemory = (void (__cdecl **)(int))2;
            if ( GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 44, a4: &msg) != nullptr )
              v21 = (struct GFxAmpMessage *)GFxAmpMessageSwdFile::GFxAmpMessageSwdFile(result: (const CJob *)handle);
            else
              v21 = nullptr;
            GFxAmpThreadMgr::SendAmpMessage(this: *((GFxAmpThreadMgr **)this + 41), a2: v21);
            HIBYTE(msg.m_Memory.m_pMemory) = 1;
          }
          v18->InFlashlightMode(this: v18);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v26);
          if ( HIBYTE(msg.m_Memory.m_pMemory) == 0 )
          {
LABEL_30:
            msg.m_Memory.m_pMemory = (void (__cdecl **)(int))2;
            if ( GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 44, a4: &msg) != nullptr )
              v22 = (struct GFxAmpMessage *)GFxAmpMessageSwdFile::GFxAmpMessageSwdFile(result: (const CJob *)handle);
            else
              v22 = nullptr;
            GFxAmpThreadMgr::SendAmpMessage(this: *((GFxAmpThreadMgr **)this + 41), a2: v22);
          }
          if ( v18 != nullptr )
            GRefCountImpl::Release(this: v18);
          v23 = (void *)(v32.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v32.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v23);
        }
        v9 = v30;
      }
      v24 = (void *)(v9 & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v9 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v24);
    }
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 320));
    GRefCountImpl::Release(this: v31);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077650
// Name: public: virtual bool GFxAmpServer::HandleSourceRequest(class GFxAmpMessageSourceRequest const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpServer::HandleSourceRequest(ConVar *this@<ecx>, int msg, const char *fileOpener, int handle)
{
  int v5; // ebx
  int v6; // ecx
  IShaderDevice *v7; // eax
  IShaderAPI *v8; // edi
  unsigned __int64 v9; // rax
  unsigned int v10; // edi
  unsigned int v11; // ebx
  int v12; // eax
  void (__thiscall *GetLightmapDimensions)(struct IShaderAPI *, int *, int *); // eax
  int v14; // eax
  IShaderAPI *v15; // edi
  unsigned int v16; // eax
  int v17; // ebx
  GFxAmpMessageSourceFile *v18; // eax
  GFxAmpMessageSourceFile *v19; // eax
  char v20; // bl
  GFxAmpMessageSourceFile *v21; // eax
  GFxAmpMessageSourceFile *v22; // eax
  void *v23; // esi
  const TableVector *v24; // [esp+0h] [ebp-30h]
  unsigned __int8 *v25; // [esp+Ch] [ebp-24h] BYREF
  unsigned int v26; // [esp+10h] [ebp-20h]
  unsigned __int64 handlea; // [esp+18h] [ebp-18h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+20h] [ebp-10h]
  IShaderAPI *v29; // [esp+24h] [ebp-Ch]
  VProfReportType_t it; // [esp+28h] [ebp-8h] BYREF
  int v31; // [esp+2Ch] [ebp-4h] BYREF

  v5 = 0;
  v29 = nullptr;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 292));
  if ( *((_DWORD *)this + 68) != 0 )
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(*((_DWORD *)this + 67) + 4 * v5);
      v7 = (IShaderDevice *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 12))(a1: v6, a2: 10);
      v8 = (IShaderAPI *)v7;
      if ( v7 != nullptr )
        GRefCountImpl::AddRef(this: v7);
      v29 = v8;
      if ( v8 != nullptr )
        break;
      if ( (unsigned int)++v5 >= *((_DWORD *)this + 68) )
        goto LABEL_8;
    }
    GRefCountImpl::Release(this: v8);
  }
LABEL_8:
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 292));
  if ( v29 != nullptr )
  {
    lpCriticalSection = (LPCRITICAL_SECTION)((char *)this + 348);
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 348));
    LODWORD(v9) = GFxAmpMessageSourceRequest::GetFileHandle(result: v24);
    v10 = HIDWORD(v9);
    v11 = v9;
    handlea = v9;
    GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::FindAlt<unsigned __int64>(
      this: (int *)this + 86,
      a2: (int **)&it,
      a3: &handlea);
    if ( it == 0 || *(_DWORD *)it == 0 || v31 > *(_DWORD *)(*(_DWORD *)it + 4) )
      goto LABEL_33;
    GFxAmpServer::GetSourceFilename(
      this,
      handle: (CCountedStringPoolBase<unsigned int> *)&v31,
      handlea: __PAIR64__(v10, v11));
    v12 = v31;
    if ( (*(_DWORD *)(v31 & 0xFFFFFFFC) & 0x7FFFFFFF) == 0 )
    {
LABEL_31:
      v23 = (void *)(v12 & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v12 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v23);
LABEL_33:
      LeaveCriticalSection(lpCriticalSection);
      GRefCountImpl::Release(this: v29);
      return;
    }
    if ( (unsigned __int8)GFxAmpMessageSourceRequest::IsRequestContents(this: (TableVector *)msg) == 0 )
    {
LABEL_30:
      v12 = v31;
      goto LABEL_31;
    }
    GetLightmapDimensions = v29->GetLightmapDimensions;
    HIBYTE(msg) = 0;
    v14 = ((int (__thiscall *)(IShaderAPI *, unsigned int, int, int))GetLightmapDimensions)(
            a1: v29,
            a2: (v31 & 0xFFFFFFFC) + 8,
            a3: 33,
            a4: 438);
    v15 = (IShaderAPI *)v14;
    if ( v14 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 24))(a1: v14) > 0 )
    {
      v16 = ((int (__thiscall *)(IShaderAPI *))v15->SetDefaultState)(a1: v15);
      GArray<unsigned char,2,GArrayDefaultPolicy>::GArray<unsigned char,2,GArrayDefaultPolicy>(this: &v25, size: v16);
      v17 = ((int (__thiscall *)(IShaderAPI *, unsigned __int8 *, unsigned int))v15->GetCurrentFogType)(
              a1: v15,
              a2: v25,
              a3: v26);
      if ( v17 == ((int (__thiscall *)(IShaderAPI *))v15->SetDefaultState)(a1: v15) )
      {
        msg = 2;
        v18 = (GFxAmpMessageSourceFile *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                           this: GMemory::pGlobalHeap,
                                           a2: this,
                                           a3: 48,
                                           a4: &msg);
        if ( v18 != nullptr )
        {
          v19 = GFxAmpMessageSourceFile::GFxAmpMessageSourceFile(
                  this: v18,
                  a2: handlea,
                  a3: v25,
                  a4: v26,
                  pdata: (const char *)((v31 & 0xFFFFFFFC) + 8));
          GFxAmpThreadMgr::SendAmpMessage(this: *((GFxAmpThreadMgr **)this + 41), a2: &v19->GFxAmpMessage);
        }
        else
        {
          GFxAmpThreadMgr::SendAmpMessage(this: *((GFxAmpThreadMgr **)this + 41), a2: nullptr);
        }
        v20 = 1;
      }
      else
      {
        v20 = HIBYTE(msg);
      }
      v15->InFlashlightMode(this: v15);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v25);
      if ( v20 != 0 )
        goto LABEL_28;
      v11 = handlea;
    }
    msg = 2;
    v21 = (GFxAmpMessageSourceFile *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                       this: GMemory::pGlobalHeap,
                                       a2: this,
                                       a3: 48,
                                       a4: &msg);
    if ( v21 != nullptr )
      v22 = GFxAmpMessageSourceFile::GFxAmpMessageSourceFile(
              this: v21,
              a2: __PAIR64__(HIDWORD(handlea), v11),
              a3: nullptr,
              a4: 0,
              pdata: (const char *)((v31 & 0xFFFFFFFC) + 8));
    else
      v22 = nullptr;
    GFxAmpThreadMgr::SendAmpMessage(this: *((GFxAmpThreadMgr **)this + 41), a2: &v22->GFxAmpMessage);
LABEL_28:
    if ( v15 != nullptr )
      GRefCountImpl::Release(this: v15);
    goto LABEL_30;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100778E0
// Name: public: virtual GFxAmpCurrentState::~GFxAmpCurrentState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpCurrentState::~GFxAmpCurrentState(int this)
{
  volatile LONG *v2; // edi
  volatile LONG *v3; // edi
  volatile LONG *v4; // edi
  volatile LONG *v5; // edi
  volatile LONG *v6; // edi

  GConstructorMov<GString>::DestructArray(a1: *(_DWORD *)(this + 32), a2: *(_DWORD *)(this + 36));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 32));
  v2 = (volatile LONG *)(*(_DWORD *)(this + 28) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (volatile LONG *)(*(_DWORD *)(this + 24) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  v4 = (volatile LONG *)(*(_DWORD *)(this + 20) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
  v5 = (volatile LONG *)(*(_DWORD *)(this + 16) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v5 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v5);
  v6 = (volatile LONG *)(*(_DWORD *)(this + 12) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v6 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v6);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100779C0
// Name: unsigned int G_sprintf(char __near *,unsigned int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __thiscall G_sprintf(unsigned __int16 dest, char *destsize, unsigned int destsizea, char *format, char ap)
{
  vsnprintf_s(string: destsize, sizeInBytes: destsizea, count: 0xFFFFFFFF, format, &ap);
}

//------------------------------------------------------------------------------
// Address: 0x100779E0
// Name: public: virtual void GFxAmpFontVisitor::Visit(class GFxMovieDef __near *,class GFxResource __near *,class GFxResourceId,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpFontVisitor::Visit(
        GFxAmpFontVisitor *this,
        struct GFxMovieDef *a2,
        struct GFxResource *a3,
        IVirtualMemorySection a4,
        const char *a5)
{
  unsigned __int8 *v6; // eax
  GFxResource_vtbl *v7; // eax
  char v8; // al
  unsigned int v9; // esi
  unsigned int v10; // eax
  CVertexBuilder *v11; // edi
  unsigned int v12; // esi
  CCountedStringPoolBase<unsigned int> *v13; // ecx
  void *v14; // esi
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > v15[5]; // [esp+8h] [ebp-6Ch] BYREF

  GString::GString(this: (CUtlMemory<CImagePacker,int> *)v15);
  v6 = (unsigned __int8 *)(*((int (__thiscall **)(GFxResource_vtbl *))a3[1].dtr_GFxResource + 15))(a1: a3[1].__vftable);
  GString::operator=(this: v15, a2: v6);
  v7 = a3[1].__vftable;
  if ( ((int)v7[1].GetKey & 2) != 0 )
  {
    GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)v15, putf8str: (CImagePacker *)" - Bold", utf8StrSz: -1);
  }
  else if ( ((int)v7[1].GetKey & 1) != 0 )
  {
    GString::AppendString(
      this: (CUtlMemory<CImagePacker,int> *)v15,
      putf8str: (CImagePacker *)" - Italic",
      utf8StrSz: -1);
  }
  v8 = (*((int (__thiscall **)(GFxResource_vtbl *))a3[1].dtr_GFxResource + 14))(a1: a3[1].__vftable);
  G_sprintf(
    dest: (unsigned __int16)&v15[0].m_Memory.m_nAllocationCount,
    destsize: (char *)&v15[0].m_Memory.m_nAllocationCount,
    destsizea: 0x64u,
    format: ", %d glyphs",
    ap: v8);
  GString::AppendString(
    this: (CUtlMemory<CImagePacker,int> *)v15,
    putf8str: (CImagePacker *)&v15[0].m_Memory.m_nAllocationCount,
    utf8StrSz: -1);
  if ( ((int)a3[1].__vftable[1].GetKey & 0x2000) == 0 )
    GString::AppendString(
      this: (CUtlMemory<CImagePacker,int> *)v15,
      putf8str: (CImagePacker *)", static only",
      utf8StrSz: -1);
  GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)v15, putf8str: (CImagePacker *)" (", utf8StrSz: -1);
  GFxResourceId::GenerateIdString(
    this: &a4,
    pbuffer: (char *)&v15[0].m_Memory.m_nAllocationCount,
    bufferSize: 9u,
    suffixLetter: 0);
  GString::AppendString(
    this: (CUtlMemory<CImagePacker,int> *)v15,
    putf8str: (CImagePacker *)&v15[0].m_Memory.m_nAllocationCount,
    utf8StrSz: -1);
  GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)v15, putf8str: (CImagePacker *)")", utf8StrSz: -1);
  v9 = *((_DWORD *)this + 2);
  v10 = v9;
  v11 = (CVertexBuilder *)((char *)this + 4);
  v12 = v9 + 1;
  if ( v12 >= v10 )
  {
    if ( v12 >= v11->m_VertexSize_BoneMatrixIndex )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: v11,
        pheapAddr: (ButtonCode_t)v11,
        newCapacity: v12 + (v12 >> 2));
  }
  else
  {
    GConstructorMov<GString>::DestructArray(a1: v11->m_VertexSize_Position + 4 * v12, a2: v10 - v12);
    if ( v12 < (unsigned int)v11->m_VertexSize_BoneMatrixIndex >> 1 )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: v11,
        pheapAddr: (ButtonCode_t)v11,
        newCapacity: v12);
  }
  v13 = (CCountedStringPoolBase<unsigned int> *)(v11->m_VertexSize_Position + 4 * v12 - 4);
  v11->m_VertexSize_BoneWeight = v12;
  if ( v13 != nullptr )
    GString::GString(this: v13, result: (CImagePacker *)v15);
  v14 = (void *)((int)v15[0].m_Memory.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v15[0].m_Memory.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
}

//------------------------------------------------------------------------------
// Address: 0x10077D80
// Name: private: GFxAmpServer::GFxAmpServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::GFxAmpServer(ConVar *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ebx
  IShaderAPI *v4; // ecx
  GFxAmpStatusChangedCallback *v5; // eax
  GFxAmpStatusChangedCallback *v6; // ebx
  IShaderAPI *v7; // ecx
  ICachedPerFrameMeshData *v8; // eax
  int v9; // eax
  int v10; // ebx
  IShaderAPI *v11; // ecx
  int v12; // [esp+Ch] [ebp-Ch] BYREF
  int v13; // [esp+10h] [ebp-8h] BYREF
  int v14; // [esp+14h] [ebp-4h] BYREF

  this->ConCommandBase::__vftable = (ConVar_vtbl *)&GRefCountImplCore::`vftable';
  this->m_pNext = (ConCommandBase *)1;
  this->ConCommandBase::__vftable = (ConVar_vtbl *)&GFxAmpMsgHandler::`vftable';
  *(_DWORD *)&this->m_bRegistered = 0;
  this->m_pszName = nullptr;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&this->m_pszHelpString);
  this->ConCommandBase::__vftable = (ConVar_vtbl *)&GFxAmpServer::`vftable';
  GFxAmpCurrentState::GFxAmpCurrentState(this: (GFxAmpCurrentState *)&this->IConVar);
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 104), spinCount: 0);
  *((_DWORD *)this + 32) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 132), spinCount: 0);
  *((_DWORD *)this + 39) = 7534;
  *((_DWORD *)this + 40) = 7533;
  *((_DWORD *)this + 41) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)this + 7, spinCount: 0);
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)this + 8, spinCount: 0);
  *((_DWORD *)this + 54) = 0;
  *((_DWORD *)this + 55) = 0;
  *((_DWORD *)this + 56) = 0;
  *((_BYTE *)this + 228) = 1;
  *((_DWORD *)this + 58) = 0;
  *((_DWORD *)this + 59) = 0;
  *((_DWORD *)this + 60) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244), spinCount: 0);
  *((_DWORD *)this + 67) = 0;
  *((_DWORD *)this + 68) = 0;
  *((_DWORD *)this + 69) = 0;
  *((_DWORD *)this + 70) = 0;
  *((_DWORD *)this + 71) = 0;
  *((_DWORD *)this + 72) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 292), spinCount: 0);
  *((_DWORD *)this + 79) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 320), spinCount: 0);
  *((_DWORD *)this + 86) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 348), spinCount: 0);
  GEvent::GEvent(this: nullptr, setInitially: nullptr);
  GEvent::GEvent(this: nullptr, setInitially: nullptr);
  *((_DWORD *)this + 115) = 0;
  *((_DWORD *)this + 116) = 0;
  *((_BYTE *)this + 468) = 1;
  *((_DWORD *)this + 118) = 0;
  *((_DWORD *)this + 119) = 0;
  *((_DWORD *)this + 120) = 0;
  *((_DWORD *)this + 121) = 0;
  *((_DWORD *)this + 122) = 0;
  v14 = 2;
  v2 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 12, a4: &v14);
  if ( v2 != nullptr )
  {
    *v2 = &GRefCountImplCore::`vftable';
    v2[1] = 1;
    v2[2] = &GString::InitStruct::`vftable';
    *v2 = &GFxAmpSendThreadCallback::`vftable'{for `GRefCountBase<GFxAmpSendThreadCallback,2>'};
    v2[2] = &GFxAmpSendThreadCallback::`vftable'{for `GFxAmpSendInterface'};
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = *((IShaderAPI **)this + 120);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  *((_DWORD *)this + 120) = v3;
  v13 = 2;
  v5 = (GFxAmpStatusChangedCallback *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                        this: GMemory::pGlobalHeap,
                                        a2: this,
                                        a3: 16,
                                        a4: &v13);
  if ( v5 != nullptr )
    v6 = GFxAmpStatusChangedCallback::GFxAmpStatusChangedCallback(this: v5, a2: (struct GEvent *)((char *)this + 372));
  else
    v6 = nullptr;
  v7 = *((IShaderAPI **)this + 121);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  *((_DWORD *)this + 121) = v6;
  v12 = 2;
  v8 = (ICachedPerFrameMeshData *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                    this: GMemory::pGlobalHeap,
                                    a2: this,
                                    a3: 32,
                                    a4: &v12);
  if ( v8 != nullptr )
  {
    GFxAmpMessageAppControl::GFxAmpMessageAppControl(this: v8);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  v11 = *((IShaderAPI **)this + 122);
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  *((_DWORD *)this + 122) = v10;
}

//------------------------------------------------------------------------------
// Address: 0x10077FD0
// Name: public: virtual bool GFxAmpServer::IsInitSocketLib(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpServer::IsInitSocketLib(_BYTE *this)
{
  return *(this + 468);
}

//------------------------------------------------------------------------------
// Address: 0x10077FE0
// Name: private: virtual GFxAmpServer::~GFxAmpServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::~GFxAmpServer(GFxAmpServer *this)
{
  IShaderAPI *pObject; // ecx
  IShaderAPI *v3; // ecx
  IShaderAPI *v4; // ecx
  IShaderAPI *v5; // ecx
  unsigned int Size; // eax
  IShaderAPI **v7; // edi
  unsigned int v8; // ebx
  IShaderAPI *v9; // ecx
  volatile LONG *v10; // edi
  const CDbgFmtMsg *v11; // [esp+0h] [ebp-8h]
  const CDbgFmtMsg *v12; // [esp+0h] [ebp-8h]

  this->__vftable = (GFxAmpServer_vtbl *)&GFxAmpServer::`vftable';
  pObject = (IShaderAPI *)this->ThreadMgr.pObject;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
  this->ThreadMgr.pObject = nullptr;
  v3 = (IShaderAPI *)this->AppControlCaps.pObject;
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = (IShaderAPI *)this->StatusChangedCallback.pObject;
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  v5 = (IShaderAPI *)this->SendThreadCallback.pObject;
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  GEvent::~GEvent(result: v11);
  GEvent::~GEvent(result: v12);
  GLock::~GLock(lpCriticalSection: &this->SourceFileLock.cs);
  GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(this: (int *)&this->HandleToSourceFileMap);
  GLock::~GLock(lpCriticalSection: &this->SwfLock.cs);
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF>>::~GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF>>(this: &this->HandleToSwdIdMap.Hash.pTable);
  GLock::~GLock(lpCriticalSection: &this->LoaderLock.cs);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->AmpRenderers.Data.Data);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->Loaders.Data.Data);
  GLock::~GLock(lpCriticalSection: &this->MovieLock.cs);
  Size = this->MovieStats.Data.Size;
  v7 = (IShaderAPI **)((char *)this->MovieStats.Data.Data + 4 * Size - 4);
  if ( Size != 0 )
  {
    v8 = this->MovieStats.Data.Size;
    do
    {
      if ( *v7 != nullptr )
        GRefCountImpl::Release(this: *v7);
      --v7;
      --v8;
    }
    while ( v8 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->MovieStats.Data.Data);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->Movies.Data.Data);
  GLock::~GLock(lpCriticalSection: &this->FrameDataLock.cs);
  GLock::~GLock(lpCriticalSection: &this->ConnectionLock.cs);
  v9 = (IShaderAPI *)this->ThreadMgr.pObject;
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  GLock::~GLock(lpCriticalSection: &this->ToggleStateLock.cs);
  GLock::~GLock(lpCriticalSection: &this->CurrentStateLock.cs);
  GFxAmpCurrentState::~GFxAmpCurrentState(this: (int)&this->CurrentState);
  v10 = (volatile LONG *)(this->RecvName.HeapTypeBits & 0xFFFFFFFC);
  this->__vftable = (GFxAmpServer_vtbl *)&GFxAmpMsgHandler::`vftable';
  if ( InterlockedExchangeAdd(Addend: v10 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v10);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100781D0
// Name: public: static void GFxAmpServer::Init(unsigned int,class GSysAllocPaged __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GFxAmpServer::Init(unsigned int a1, struct GSysAllocPaged *a2)
{
  unsigned int v2; // esi
  GMemoryHeap *v3; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  ConVar *v5; // eax
  void *v6; // eax
  _DWORD v7[8]; // [esp+4h] [ebp-20h] BYREF

  v2 = a1;
  if ( a1 != 0 )
    GMemory::pGlobalHeap->CreateArena(this: GMemory::pGlobalHeap, a2: a1, a3: a2);
  v7[1] = 16;
  v7[4] = -1;
  v7[6] = 0;
  v7[0] = 4096;
  v7[2] = 0x4000;
  v7[3] = 0x40000;
  v7[5] = 0x100000;
  v7[7] = v2;
  v3 = GMemory::pGlobalHeap->CreateHeap(this: GMemory::pGlobalHeap, a2: "AMP", a3: v7);
  Alloc_2 = v3->Alloc_2;
  a1 = 2;
  v5 = (ConVar *)Alloc_2(this: v3, a2: 496u, a3: (const GAllocDebugInfo *)&a1);
  if ( v5 != nullptr )
  {
    GFxAmpServer::GFxAmpServer(this: v5);
    *(_DWORD *)GFxAmpServer::AmpServerSingleton = v6;
    GMemoryHeap::ReleaseOnFree(this: v3, ptr: v6);
  }
  else
  {
    *(_DWORD *)GFxAmpServer::AmpServerSingleton = 0;
    GMemoryHeap::ReleaseOnFree(this: v3, ptr: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078440
// Name: public: unsigned long GFxAmpServer::AddSwf(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpServer::AddSwf(
        ConVar *this,
        void (__cdecl *swdId)(IConVar *, const char *, float),
        unsigned __int8 *filename)
{
  char *v4; // eax
  char *v5; // edi
  _DWORD v6[2]; // [esp+Ch] [ebp-14h] BYREF
  int v7; // [esp+14h] [ebp-Ch] BYREF
  unsigned int swdHandle; // [esp+18h] [ebp-8h] BYREF
  IShaderAPI *v9; // [esp+1Ch] [ebp-4h] BYREF
  void (__cdecl *swdIda)(IConVar *, const char *, float); // [esp+28h] [ebp+8h]

  v7 = 2;
  v4 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 16, a4: &v7);
  v5 = v4;
  if ( v4 != nullptr )
  {
    *(_DWORD *)v4 = &GRefCountImplCore::`vftable';
    *((_DWORD *)v4 + 1) = 1;
    *(_DWORD *)v4 = &GFxAmpServer::SwdInfo::`vftable';
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v4 + 8));
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v5 + 12));
  }
  else
  {
    v5 = nullptr;
  }
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v5 + 8),
    a2: (unsigned __int8 *)swdId);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v5 + 12),
    a2: filename);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 320));
  swdIda = (void (__cdecl *)(IConVar *, const char *, float))++lastSwdHandle;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 320));
  swdHandle = (unsigned int)swdIda;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 320));
  v6[0] = &swdHandle;
  v9 = (IShaderAPI *)v5;
  v6[1] = &v9;
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF>>::Set<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeRef>(
    a1: (void **)this + 79,
    a2: (int)v6,
    a3: (char *)this + 316,
    a4: (int)v6);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 320));
}

//------------------------------------------------------------------------------
// Address: 0x10078C10
// Name: private: void GFxAmpServer::CollectImageData(class GStringHash<class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GAllocatorGH<class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,2>> __near *,class GStringHash<class GArray<class GString,2,struct GArrayDefaultPolicy>,struct GAllocatorGH<class GArray<class GString,2,struct GArrayDefaultPolicy>,2>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpServer::CollectImageData(
        CMemberFuncProxy5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CFuncMemPolicyNone> *this@<ecx>,
        ITexture **resourceMap,
        CUtlMemory<CImagePacker,int> fontMap,
        const float *a4)
{
  CMemberFuncProxy5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CFuncMemPolicyNone> *v4; // ebx
  unsigned int v5; // eax
  char *v6; // esi
  unsigned int v7; // edi
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  unsigned int v11; // esi
  int *v12; // esi
  bool v13; // zf
  int *v14; // edi
  unsigned int v15; // esi
  int v16; // esi
  int v17; // eax
  int v18; // eax
  int v19; // esi
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  IShaderDevice **v24; // edi
  CVertexBuilder *v25; // esi
  int m_VertexSize_BoneWeight; // ebx
  IShaderDevice **v27; // esi
  int j; // ebx
  char *v29; // edi
  unsigned int v30; // esi
  int v31; // eax
  CImagePacker *m_pMemory; // edi
  int v33; // eax
  int v34; // eax
  int v35; // esi
  int v36; // eax
  int v37; // eax
  int m_MaxLightmapWidth; // esi
  unsigned int v39; // edi
  int v40; // eax
  unsigned int v41; // ebx
  CVertexBuilder *v42; // esi
  unsigned int v43; // edi
  unsigned int m; // edi
  int v45; // eax
  CVertexBuilder *v46; // esi
  unsigned int v47; // ebx
  unsigned int v48; // edi
  int v49; // eax
  int m_VertexSize_Position; // ecx
  CImagePacker *m_nGrowSize; // edi
  CCountedStringPoolBase<unsigned int> *v52; // esi
  int k; // ebx
  void *v54; // esi
  _DWORD *v55; // edi
  volatile LONG *v56; // esi
  void *v57; // esi
  IShaderDevice **v58; // esi
  unsigned int n; // ebx
  CMemberFuncProxy5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CFuncMemPolicyNone> *v60; // ebx
  CImagePacker *v61; // eax
  char *v62; // esi
  unsigned int v63; // edi
  GString *v64; // ecx
  int v65; // eax
  unsigned int v66; // ebx
  unsigned int v67; // edi
  int v68; // edi
  char *v69; // eax
  unsigned int v70; // edi
  int v71; // esi
  int v72; // eax
  int v73; // eax
  unsigned int v74; // edi
  int *v75; // ebx
  int v76; // eax
  int v77; // eax
  int v78; // ecx
  int v79; // eax
  IShaderDevice **v80; // edi
  unsigned int ii; // ebx
  unsigned int v82; // eax
  CVertexBuilder *v83; // esi
  _DWORD *v84; // esi
  IShaderDevice **v85; // esi
  unsigned int jj; // edi
  void *v87; // esi
  unsigned int v88; // [esp-8h] [ebp-9Ch]
  unsigned int v89; // [esp-8h] [ebp-9Ch]
  unsigned int v90; // [esp-8h] [ebp-9Ch]
  int v91; // [esp+0h] [ebp-94h]
  _DWORD v92[8]; // [esp+Ch] [ebp-88h] BYREF
  int v93; // [esp+2Ch] [ebp-68h]
  CUtlMemory<CImagePacker,int> *v94; // [esp+34h] [ebp-60h] BYREF
  int *v95; // [esp+38h] [ebp-5Ch]
  GString *v96; // [esp+3Ch] [ebp-58h] BYREF
  int *v97; // [esp+40h] [ebp-54h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+44h] [ebp-50h] BYREF
  void **v99; // [esp+48h] [ebp-4Ch] BYREF
  int v100; // [esp+4Ch] [ebp-48h] BYREF
  unsigned int v101; // [esp+50h] [ebp-44h]
  int v102; // [esp+54h] [ebp-40h]
  void **v103; // [esp+58h] [ebp-3Ch] BYREF
  int v104; // [esp+5Ch] [ebp-38h] BYREF
  unsigned int v105; // [esp+60h] [ebp-34h]
  int v106; // [esp+64h] [ebp-30h]
  int p_fontMap; // [esp+68h] [ebp-2Ch] BYREF
  GString v108; // [esp+6Ch] [ebp-28h] BYREF
  GString *v109; // [esp+70h] [ebp-24h] BYREF
  CUtlMemory<CImagePacker,int> v110; // [esp+74h] [ebp-20h] BYREF
  CMemberFuncProxy5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CFuncMemPolicyNone> *v111; // [esp+80h] [ebp-14h]
  char *v112; // [esp+84h] [ebp-10h] BYREF
  unsigned int v113; // [esp+88h] [ebp-Ch]
  unsigned int v114; // [esp+8Ch] [ebp-8h]
  unsigned int i; // [esp+90h] [ebp-4h]

  v4 = this;
  v111 = this;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 244));
  v5 = 0;
  v6 = nullptr;
  v7 = 0;
  v112 = nullptr;
  v113 = 0;
  v114 = 0;
  i = 0;
  if ( DWORD1(v4[9].m_pfnProxied) != 0 )
  {
    while ( 1 )
    {
      v8 = *(_DWORD *)(LODWORD(v4[9].m_pfnProxied) + 4 * v5);
      v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
      if ( v9 != 0 )
      {
        v10 = 0;
        if ( v7 != 0 )
        {
          while ( *(_DWORD *)&v6[4 * v10] != v9 )
          {
            if ( ++v10 >= v7 )
              goto LABEL_8;
          }
        }
        else
        {
LABEL_8:
          v11 = v7 + 1;
          if ( v7 + 1 >= v7 )
          {
            if ( v11 >= v114 )
              GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                this: (CVertexBuilder *)&v112,
                pheapAddr: (ButtonCode_t)&v112,
                newCapacity: v11 + (v11 >> 2));
          }
          else if ( v11 < v114 >> 1 )
          {
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&v112,
              pheapAddr: (ButtonCode_t)&v112,
              newCapacity: v7 + 1);
          }
          ++v7;
          v12 = (int *)&v112[4 * v11 - 4];
          v113 = v7;
          if ( v12 != nullptr )
            *v12 = v9;
        }
      }
      v4 = v111;
      v5 = i + 1;
      i = v5;
      if ( v5 >= DWORD1(v111[9].m_pfnProxied) )
        break;
      v6 = v112;
    }
  }
  v13 = v7 == 0;
  v14 = (int *)resourceMap;
  i = 0;
  if ( !v13 )
  {
    lpCriticalSection = (LPCRITICAL_SECTION)&v110;
    v109 = &v108;
    while ( 1 )
    {
      v15 = i;
      v103 = &GFxAmpImageVisitor::`vftable';
      v104 = 0;
      v105 = 0;
      v106 = 0;
      (*(void (__thiscall **)(_DWORD, void ***, int))(**(_DWORD **)&v112[4 * i] + 104))(
        a1: *(_DWORD *)&v112[4 * i],
        a2: &v103,
        a3: 32774);
      v16 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&v112[4 * v15] + 76))(a1: *(_DWORD *)&v112[4 * v15]);
      v92[0] = 0;
      v92[1] = 16;
      v92[2] = 0x2000;
      v92[3] = 0x2000;
      v92[4] = -1;
      memset(&v92[5], 0, 12);
      GMemoryHeap::GetHeapInfo(this: v16, a2: v92);
      GString::GString(this: (GString *)&v110, src: (int)"[Heap] ");
      GString::AppendString(this: &v110, putf8str: *(CImagePacker **)(v16 + 64), utf8StrSz: -1);
      if ( v93 != 0 && (GMemoryHeap *)v93 != GMemory::pGlobalHeap )
        GString::AppendString(this: &v110, putf8str: *(CImagePacker **)(v93 + 64), utf8StrSz: -1);
      if ( *v14 != 0
        && (v17 = GString::BernsteinHashFunctionCIS(
                    result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)v110.m_pMemory & 0xFFFFFFFC) + 8),
                    size: *(_DWORD *)((int)v110.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF,
                    seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505),
            (v18 = GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
                     this: v14,
                     a2: (_DWORD **)&lpCriticalSection,
                     a3: v17 & *(_DWORD *)(*v14 + 4))) >= 0)
        && (v19 = *v14, *v14 != 0)
        && v18 <= *(_DWORD *)(v19 + 4) )
      {
        v24 = (IShaderDevice **)v104;
        v25 = (CVertexBuilder *)(v19 + 24 * v18 + 20);
        v110.m_nGrowSize = v105;
        if ( v105 != 0 )
        {
          m_VertexSize_BoneWeight = v25->m_VertexSize_BoneWeight;
          GArrayDataBase<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
            this: v25,
            a2: (int)v25,
            a3: m_VertexSize_BoneWeight + v105);
          v27 = (IShaderDevice **)(v25->m_VertexSize_Position + 4 * m_VertexSize_BoneWeight);
          if ( v110.m_nGrowSize != 0 )
          {
            for ( j = v110.m_nGrowSize; j != 0; --j )
            {
              if ( v27 != nullptr )
              {
                if ( *v24 != nullptr )
                  GRefCountImpl::AddRef(this: *v24);
                *v27 = *v24;
              }
              ++v24;
              ++v27;
            }
          }
        }
      }
      else
      {
        v110.m_nGrowSize = (int)&v110;
        if ( *v14 != 0
          && (v20 = GString::BernsteinHashFunctionCIS(
                      result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)v110.m_pMemory & 0xFFFFFFFC) + 8),
                      size: *(_DWORD *)((int)v110.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF,
                      seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505),
              (v21 = GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
                       this: v14,
                       a2: (_DWORD **)&v110.m_nGrowSize,
                       a3: v20 & *(_DWORD *)(*v14 + 4))) >= 0)
          && (v22 = *v14, *v14 != 0)
          && v21 <= *(_DWORD *)(v22 + 4) )
        {
          GArrayBase<GArrayData<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>>::operator=(
            this: (CVertexBuilder *)(v22 + 24 * v21 + 20),
            a2: &v104);
        }
        else
        {
          v94 = &v110;
          v88 = *(_DWORD *)((int)v110.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF;
          v95 = &v104;
          v23 = GString::BernsteinHashFunctionCIS(
                  result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)v110.m_pMemory
                                                                                                  & 0xFFFFFFFC)
                                                                                                 + 8),
                  size: v88,
                  seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
          GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::add<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeRef>(
            this: v14,
            a2: (int)v14,
            a3: (int)&v94,
            a4: v23);
        }
      }
      v29 = v112;
      v30 = i;
      v99 = &GFxAmpFontVisitor::`vftable';
      v100 = 0;
      v101 = 0;
      v102 = 0;
      (*(void (__thiscall **)(_DWORD, void ***, int))(**(_DWORD **)&v112[4 * i] + 104))(
        a1: *(_DWORD *)&v112[4 * i],
        a2: &v99,
        a3: 1);
      v31 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&v29[4 * v30] + 48))(a1: *(_DWORD *)&v29[4 * v30]);
      GString::GString(this: &v108, src: v31);
      m_pMemory = fontMap.m_pMemory;
      if ( fontMap.m_pMemory->m_MaxLightmapWidth == 0 )
        goto LABEL_149;
      v33 = GString::BernsteinHashFunctionCIS(
              result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v108.HeapTypeBits
                                                                                              & 0xFFFFFFFC)
                                                                                             + 8),
              size: *(_DWORD *)(v108.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
              seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
      v34 = GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
              this: m_pMemory,
              a2: (_DWORD **)&v109,
              a3: v33 & *(_DWORD *)(m_pMemory->m_MaxLightmapWidth + 4));
      if ( v34 >= 0
        && (v35 = m_pMemory->m_MaxLightmapWidth, m_pMemory->m_MaxLightmapWidth != 0)
        && v34 <= *(_DWORD *)(v35 + 4) )
      {
        v46 = (CVertexBuilder *)(v35 + 24 * v34 + 20);
        p_fontMap = v101;
        v110.m_nGrowSize = v100;
        if ( v101 != 0 )
        {
          v47 = v46->m_VertexSize_BoneWeight;
          v48 = v47 + v101;
          if ( v47 + v101 >= v47 )
          {
            if ( v48 >= v46->m_VertexSize_BoneMatrixIndex )
              GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                this: v46,
                pheapAddr: (ButtonCode_t)v46,
                newCapacity: v48 + (v48 >> 2));
          }
          else
          {
            GConstructorMov<GString>::DestructArray(a1: v46->m_VertexSize_Position + 4 * (v47 + v101), a2: -v101);
            if ( v48 < (unsigned int)v46->m_VertexSize_BoneMatrixIndex >> 1 )
              GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                this: v46,
                pheapAddr: (ButtonCode_t)v46,
                newCapacity: v48);
          }
          v49 = p_fontMap;
          m_VertexSize_Position = v46->m_VertexSize_Position;
          v46->m_VertexSize_BoneWeight = v48;
          m_nGrowSize = (CImagePacker *)v110.m_nGrowSize;
          v52 = (CCountedStringPoolBase<unsigned int> *)(m_VertexSize_Position + 4 * v47);
          if ( v49 != 0 )
          {
            for ( k = v49; k != 0; --k )
            {
              if ( v52 != nullptr )
                GString::GString(this: v52, result: m_nGrowSize);
              m_nGrowSize = (CImagePacker *)((char *)m_nGrowSize + 4);
              v52 = (CCountedStringPoolBase<unsigned int> *)((char *)v52 + 4);
            }
          }
        }
      }
      else
      {
LABEL_149:
        v110.m_nGrowSize = (int)&v108;
        if ( m_pMemory->m_MaxLightmapWidth != 0
          && (v36 = GString::BernsteinHashFunctionCIS(
                      result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v108.HeapTypeBits & 0xFFFFFFFC) + 8),
                      size: *(_DWORD *)(v108.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
                      seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505),
              (v37 = GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
                       this: m_pMemory,
                       a2: (_DWORD **)&v110.m_nGrowSize,
                       a3: v36 & *(_DWORD *)(m_pMemory->m_MaxLightmapWidth + 4))) >= 0)
          && (m_MaxLightmapWidth = m_pMemory->m_MaxLightmapWidth, m_pMemory->m_MaxLightmapWidth != 0)
          && v37 <= *(_DWORD *)(m_MaxLightmapWidth + 4) )
        {
          v39 = v101;
          v40 = 3 * v37;
          v41 = *(_DWORD *)(m_MaxLightmapWidth + 8 * v40 + 24);
          v42 = (CVertexBuilder *)(m_MaxLightmapWidth + 8 * v40 + 20);
          if ( v101 >= v41 )
          {
            if ( v101 >= v42->m_VertexSize_BoneMatrixIndex )
              GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                this: v42,
                pheapAddr: (ButtonCode_t)v42,
                newCapacity: v101 + (v101 >> 2));
          }
          else
          {
            GConstructorMov<GString>::DestructArray(a1: v42->m_VertexSize_Position + 4 * v101, a2: v41 - v101);
            if ( v39 < (unsigned int)v42->m_VertexSize_BoneMatrixIndex >> 1 )
              GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                this: v42,
                pheapAddr: (ButtonCode_t)v42,
                newCapacity: v39);
          }
          v42->m_VertexSize_BoneWeight = v39;
          if ( v39 > v41 )
          {
            v43 = v39 - v41;
            for ( v110.m_nGrowSize = v42->m_VertexSize_Position + 4 * v41; v43 != 0; --v43 )
            {
              if ( v110.m_nGrowSize != 0 )
                GString::GString(this: (CUtlMemory<CImagePacker,int> *)v110.m_nGrowSize);
              v110.m_nGrowSize += 4;
            }
          }
          for ( m = 0; m < v42->m_VertexSize_BoneWeight; ++m )
            GString::operator=(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(4 * m
                                                                                       + v42->m_VertexSize_Position),
              src: (_DWORD *)(4 * m + v100),
              a3: v91);
        }
        else
        {
          v97 = &v100;
          v89 = *(_DWORD *)(v108.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF;
          v96 = &v108;
          v45 = GString::BernsteinHashFunctionCIS(
                  result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v108.HeapTypeBits
                                                                                                  & 0xFFFFFFFC)
                                                                                                 + 8),
                  size: v89,
                  seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
          GHashSetBase<GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GString,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::add<GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeRef>(
            this: (void **)m_pMemory,
            a2: (int)m_pMemory,
            a3: (int)&v96,
            a4: v45);
        }
      }
      v54 = (void *)(v108.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v108.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v54);
      v55 = (_DWORD *)(v100 + 4 * v101 - 4);
      if ( v101 != 0 )
      {
        v110.m_nGrowSize = v101;
        do
        {
          v56 = (volatile LONG *)(*v55 & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd(Addend: v56 + 1, Value: -1) == 1 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v56);
          --v55;
          --v110.m_nGrowSize;
        }
        while ( v110.m_nGrowSize != 0 );
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v100);
      v57 = (void *)((int)v110.m_pMemory & 0xFFFFFFFC);
      v99 = &GString::InitStruct::`vftable';
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v110.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v57);
      v58 = (IShaderDevice **)(v104 + 4 * v105 - 4);
      if ( v105 != 0 )
      {
        for ( n = v105; n != 0; --n )
        {
          if ( *v58 != nullptr )
            GFxResource::Release(this: *v58);
          --v58;
        }
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v104);
      v103 = &GString::InitStruct::`vftable';
      if ( ++i >= v113 )
        break;
      v14 = (int *)resourceMap;
    }
  }
  v60 = v111;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v112);
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)&v60[10].m_pfnProxied + 4));
  lpCriticalSection = (LPCRITICAL_SECTION)((char *)&v60[12].m_pfnProxied + 4);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)&v60[12].m_pfnProxied + 4));
  v61 = nullptr;
  v62 = nullptr;
  v63 = 0;
  v112 = nullptr;
  v113 = 0;
  v114 = 0;
  fontMap.m_pMemory = nullptr;
  if ( DWORD2(v60[11].m_pfnProxied) != 0 )
  {
    while ( 1 )
    {
      v64 = (GString *)CSubDMgr::SubDTexture(this: *(CMaterial **)(DWORD1(v60[11].m_pfnProxied) + 4 * (_DWORD)v61));
      v109 = v64;
      if ( v64 != nullptr )
        break;
LABEL_111:
      v60 = v111;
      v61 = (CImagePacker *)((char *)&fontMap.m_pMemory->m_MaxLightmapWidth + 1);
      fontMap.m_pMemory = v61;
      if ( (unsigned int)v61 >= DWORD2(v111[11].m_pfnProxied) )
      {
        v113 = v63;
        v112 = v62;
        goto LABEL_113;
      }
    }
    v65 = 0;
    if ( v63 != 0 )
    {
      while ( *(GString **)&v62[4 * v65] != v64 )
      {
        if ( ++v65 >= v63 )
          goto LABEL_93;
      }
      goto LABEL_111;
    }
LABEL_93:
    v66 = v63 + 1;
    if ( v63 + 1 >= v63 )
    {
      if ( v66 < v114 )
        goto LABEL_109;
      v70 = v66 + (v66 >> 2);
      if ( v70 == 0 )
      {
        if ( v62 != nullptr )
        {
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v62);
          v62 = nullptr;
        }
LABEL_105:
        v114 = 0;
        goto LABEL_109;
      }
      v67 = v70 + 3;
    }
    else
    {
      if ( v66 >= v114 >> 1 )
        goto LABEL_109;
      if ( v63 == -1 )
      {
        if ( v62 != nullptr )
        {
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v62);
          v62 = nullptr;
          v114 = 0;
          goto LABEL_109;
        }
        goto LABEL_105;
      }
      v67 = v63 + 4;
    }
    v68 = 4 * (v67 >> 2);
    if ( v62 != nullptr )
    {
      v69 = (char *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v62, a3: 4 * v68);
    }
    else
    {
      p_fontMap = 2;
      v69 = (char *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * v68, a3: &p_fontMap);
    }
    v62 = v69;
    v114 = v68;
LABEL_109:
    v63 = v66;
    if ( &v62[4 * v66] != (char *)4 )
      *(_DWORD *)&v62[4 * v66 - 4] = v109;
    goto LABEL_111;
  }
LABEL_113:
  v111 = nullptr;
  if ( v63 != 0 )
  {
    p_fontMap = (int)&fontMap;
    do
    {
      v71 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&v112[4 * (_DWORD)v111] + 8) + 40);
      GString::GString(this: (GString *)&fontMap, src: (int)"[Heap] ");
      GString::AppendString(this: &fontMap, putf8str: *(CImagePacker **)(v71 + 64), utf8StrSz: -1);
      if ( *resourceMap == nullptr
        || (v72 = GString::BernsteinHashFunctionCIS(
                    result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)fontMap.m_pMemory & 0xFFFFFFFC) + 8),
                    size: *(_DWORD *)((int)fontMap.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF,
                    seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505),
            (v73 = GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
                     this: resourceMap,
                     a2: (_DWORD **)&p_fontMap,
                     a3: v72 & (int)(*resourceMap)[1].__vftable)) < 0)
        || (v110.m_nAllocationCount = (int)resourceMap, v74 = 0, v75 = (int *)v73, *resourceMap == nullptr)
        || v73 > (int)(*resourceMap)[1].__vftable )
      {
        v100 = 0;
        v101 = 0;
        v102 = 0;
        v109 = (GString *)&fontMap;
        if ( *resourceMap != nullptr
          && (v76 = GString::BernsteinHashFunctionCIS(
                      result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)fontMap.m_pMemory & 0xFFFFFFFC) + 8),
                      size: *(_DWORD *)((int)fontMap.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF,
                      seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505),
              (v77 = GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
                       this: resourceMap,
                       a2: (_DWORD **)&v109,
                       a3: v76 & (int)(*resourceMap)[1].__vftable)) >= 0)
          && (v78 = (int)*resourceMap, *resourceMap != nullptr)
          && v77 <= *(_DWORD *)(v78 + 4) )
        {
          GArrayBase<GArrayData<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>>::operator=(
            this: (CVertexBuilder *)(v78 + 24 * v77 + 20),
            a2: &v100);
        }
        else
        {
          v96 = (GString *)&fontMap;
          v90 = *(_DWORD *)((int)fontMap.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF;
          v97 = &v100;
          v79 = GString::BernsteinHashFunctionCIS(
                  result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)fontMap.m_pMemory
                                                                                                  & 0xFFFFFFFC)
                                                                                                 + 8),
                  size: v90,
                  seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
          GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::add<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeRef>(
            this: (int *)resourceMap,
            a2: (int)resourceMap,
            a3: (int)&v96,
            a4: v79);
        }
        v80 = (IShaderDevice **)(v100 + 4 * v101 - 4);
        if ( v101 != 0 )
        {
          for ( ii = v101; ii != 0; --ii )
          {
            if ( *v80 != nullptr )
              GFxResource::Release(this: *v80);
            --v80;
          }
        }
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v100);
        v109 = (GString *)&fontMap;
        GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::FindAlt<GString::NoCaseKey>(
          this: resourceMap,
          a2: &v94,
          a3: (_DWORD **)&v109);
        v75 = v95;
        v110.m_nAllocationCount = (int)v94;
        v74 = 0;
      }
      v104 = 0;
      v105 = 0;
      v106 = 0;
      GFxResourceWeakLib::GetResourceArray(
        this: *(_DWORD *)(*(_DWORD *)&v112[4 * (_DWORD)v111] + 8),
        a2: (CVertexBuilder *)&v104);
      v82 = v105;
      if ( v105 != 0 )
      {
        do
        {
          if ( ((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v104 + 4 * v74) + 8))(a1: *(_DWORD *)(v104 + 4 * v74))
              & 0xFF00) == 0x100 )
          {
            i = v104 + 4 * v74;
            v83 = (CVertexBuilder *)(*(_DWORD *)v110.m_nAllocationCount + 24 * (_DWORD)v75 + 20);
            GArrayDataBase<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
              this: v83,
              a2: (int)v83,
              a3: *(_DWORD *)(*(_DWORD *)v110.m_nAllocationCount + 24 * (_DWORD)v75 + 24) + 1);
            v84 = (_DWORD *)(v83->m_VertexSize_Position + 4 * v83->m_VertexSize_BoneWeight - 4);
            if ( v84 != nullptr )
            {
              if ( *(_DWORD *)i != 0 )
                GRefCountImpl::AddRef(this: *(IShaderDevice **)i);
              *v84 = *(_DWORD *)i;
            }
          }
          v82 = v105;
          ++v74;
        }
        while ( v74 < v105 );
      }
      v85 = (IShaderDevice **)(v104 + 4 * v82 - 4);
      if ( v82 != 0 )
      {
        for ( jj = v82; jj != 0; --jj )
        {
          if ( *v85 != nullptr )
            GFxResource::Release(this: *v85);
          --v85;
        }
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v104);
      v87 = (void *)((int)fontMap.m_pMemory & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)fontMap.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v87);
      v111 = (CMemberFuncProxy5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CFuncMemPolicyNone> *)((char *)v111 + 1);
    }
    while ( (unsigned int)v111 < v113 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v112);
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x10079610
// Name: private: void GFxAmpServer::CollectMemoryData(class GFxAmpProfileFrame __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge GFxAmpServer::CollectMemoryData(ConVar *this@<ecx>, const char *frameProfile, float imageMap)
{
  ConVar *v3; // ebx
  void (__thiscall *GetRootStats)(GMemoryHeap *, GMemoryHeap::RootStats *); // eax
  unsigned int m_pfnProxied_high; // esi
  int v6; // ecx
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v7; // eax
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v8; // eax
  int v9; // eax
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v10; // eax
  int v11; // eax
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v12; // eax
  int v13; // eax
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v14; // eax
  int v15; // eax
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v16; // eax
  int v17; // eax
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v18; // eax
  int v19; // eax
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  int m_nGrowSize; // esi
  CMemberFuncProxy5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CFuncMemPolicyNone> *v24; // ecx
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *MaxId; // edi
  void *(__thiscall *AllocAutoHeap_2)(GMemoryHeap *, const void *, unsigned int, const GAllocDebugInfo *); // eax
  int v27; // eax
  int v28; // esi
  unsigned int v29; // edi
  ITexture **p_resourceMap; // ecx
  ITexture_vtbl *v31; // eax
  ITexture *v32; // ecx
  ITexture *v33; // ecx
  unsigned int v34; // eax
  bool v35; // zf
  _DWORD *v36; // esi
  int v37; // ecx
  int v38; // eax
  unsigned int v39; // ebx
  int v40; // ecx
  int v41; // eax
  int *v42; // eax
  void *v43; // edi
  int v44; // ecx
  int v45; // ecx
  IShaderDevice *v46; // edi
  GRenderer::CachedData *v47; // esi
  GRenderer *pRenderer; // edx
  IShaderDevice **v49; // esi
  void *v50; // esi
  void *v51; // esi
  void *v52; // esi
  ITexture *v53; // ecx
  unsigned int v54; // eax
  unsigned int v55; // edx
  ITexture *v56; // ecx
  unsigned int v57; // esi
  CFunctorCallbackBase *v58; // edi
  GRenderer::CachedData *v59; // esi
  GRenderer *v60; // ecx
  CFunctorCallbackBase **v61; // esi
  const char *v62; // ebx
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v63; // eax
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v64; // esi
  unsigned int v65; // edi
  ITexture *v66; // edx
  unsigned int v67; // edx
  int v68; // eax
  int v69; // eax
  unsigned int v70; // ecx
  int v71; // eax
  _DWORD *v72; // esi
  int v73; // ecx
  unsigned int v74; // ebx
  int v75; // ecx
  int v76; // eax
  int *v77; // eax
  void *v78; // edi
  int v79; // ecx
  int v80; // ecx
  IShaderDevice *v81; // ebx
  int v82; // esi
  unsigned int v83; // edi
  unsigned int v84; // eax
  GRenderer::CachedData *v85; // esi
  unsigned int v86; // edi
  unsigned int v87; // eax
  GRenderer *v88; // eax
  IShaderDevice **v89; // esi
  void *v90; // esi
  void *v91; // esi
  void *v92; // esi
  CFunctorCallbackBase *v93; // ecx
  unsigned int v94; // eax
  CRefCountServiceBase<1,CRefMT>_vtbl *v95; // edx
  int m_iRefs; // esi
  _DWORD *p_fontMap; // ecx
  GFxAmpMemItem *v98; // eax
  _DWORD *v99; // ecx
  char *v100; // eax
  char *v101; // esi
  unsigned int v102; // edi
  char *v103; // ebx
  int v104; // esi
  _DWORD *v105; // ecx
  unsigned int v106; // edi
  int v107; // esi
  unsigned int v108; // edi
  unsigned int v109; // eax
  GRenderer::CachedData *v110; // esi
  unsigned int v111; // edi
  unsigned int v112; // eax
  GRenderer *v113; // edx
  GRenderer *v114; // edi
  int v115; // ecx
  unsigned int v116; // eax
  GFxAmpMemItem *v117; // edx
  _DWORD *v118; // ecx
  const char *v119; // esi
  IShaderAPI *v120; // ecx
  unsigned int v121; // [esp-14h] [ebp-6E8h]
  int v122; // [esp-Ch] [ebp-6E0h]
  unsigned __int16 v123; // [esp-Ch] [ebp-6E0h]
  unsigned __int16 v124; // [esp-Ch] [ebp-6E0h]
  CUtlMemory<CImagePacker,int> v125; // [esp-4h] [ebp-6D8h]
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v126; // [esp+0h] [ebp-6D4h]
  const float *v127; // [esp+8h] [ebp-6CCh]
  _DWORD v128[3]; // [esp+Ch] [ebp-6C8h] BYREF
  _DWORD v129[3]; // [esp+18h] [ebp-6BCh] BYREF
  CUtlMemory<CImagePacker,int> v130; // [esp+24h] [ebp-6B0h] BYREF
  CMatQueuedRenderContext::CCallQueueExternal v131; // [esp+30h] [ebp-6A4h] BYREF
  CUtlMemory<CImagePacker,int> v132; // [esp+34h] [ebp-6A0h] BYREF
  int v133; // [esp+40h] [ebp-694h] BYREF
  int v134; // [esp+44h] [ebp-690h]
  int v135; // [esp+48h] [ebp-68Ch] BYREF
  int v136; // [esp+4Ch] [ebp-688h] BYREF
  int v137; // [esp+50h] [ebp-684h] BYREF
  CUtlMemory<CImagePacker,int> v138; // [esp+54h] [ebp-680h] BYREF
  char v139; // [esp+63h] [ebp-671h]
  GString v140; // [esp+64h] [ebp-670h] BYREF
  GString v141; // [esp+68h] [ebp-66Ch] BYREF
  CFunctorCallbackBase *v142; // [esp+6Ch] [ebp-668h]
  _DWORD *fontMap; // [esp+70h] [ebp-664h] BYREF
  int v144; // [esp+74h] [ebp-660h] BYREF
  int v145; // [esp+78h] [ebp-65Ch] BYREF
  unsigned int j; // [esp+7Ch] [ebp-658h]
  ITexture **v147; // [esp+80h] [ebp-654h]
  int imageMem; // [esp+84h] [ebp-650h] OVERLAPPED BYREF
  unsigned int i; // [esp+88h] [ebp-64Ch]
  const char *v150; // [esp+8Ch] [ebp-648h]
  _DWORD *v151; // [esp+90h] [ebp-644h]
  GFxAmpMemItem *v152; // [esp+94h] [ebp-640h]
  unsigned int lastItemId; // [esp+98h] [ebp-63Ch]
  unsigned int extImageSize; // [esp+9Ch] [ebp-638h]
  bool v155; // [esp+A3h] [ebp-631h]
  ITexture *resourceMap; // [esp+A4h] [ebp-630h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v157[27]; // [esp+A8h] [ebp-62Ch] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v158[27]; // [esp+3A8h] [ebp-32Ch] BYREF
  CMatRenderContextBase::RenderTargetStackElement_t stats; // [esp+6A8h] [ebp-2Ch] BYREF

  v3 = this;
  GetRootStats = GMemory::pGlobalHeap->GetRootStats;
  v138.m_nGrowSize = (int)this;
  v150 = frameProfile;
  GetRootStats(this: GMemory::pGlobalHeap, a2: (GMemoryHeap::RootStats *)&stats);
  v3 = (ConVar *)((char *)v3 + 104);
  *((_DWORD *)frameProfile + 29) = (char *)stats.m_pRenderTargets[0] - stats.m_nViewY - stats.m_nViewH;
  m_pfnProxied_high = 0;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)v3);
  v155 = (*(_DWORD *)(v138.m_nGrowSize + 32) & 0x20) != 0;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)v3);
  v6 = *((_DWORD *)frameProfile + 47);
  if ( v155 )
  {
    GMemoryHeap::MemReport(this: GMemory::pGlobalHeap, rootItem: (ConCommandBase *)v6, a3: MemReportSimple);
    GMemoryHeap::MemReport(
      this: GMemory::pGlobalHeap,
      rootItem: *((ConCommandBase **)frameProfile + 48),
      a3: MemReportFull);
  }
  else
  {
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v6 + 8),
      a2: "Toggle the i button to enable detailed memory reports");
    GMemoryHeap::MemReport(
      this: GMemory::pGlobalHeap,
      rootItem: *((ConCommandBase **)frameProfile + 48),
      a3: MemReportBrief);
  }
  if ( GFxAmpMemItem::SearchForName(result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *)"Summary") != nullptr )
  {
    v7 = GFxAmpMemItem::SearchForName(result: &stru_10299D8C);
    if ( v7 != nullptr )
    {
      m_pfnProxied_high = HIDWORD(v7->m_pfnProxied);
      *((_DWORD *)frameProfile + 30) = m_pfnProxied_high;
    }
    v8 = GFxAmpMemItem::SearchForName(result: &stru_10299DA4);
    if ( v8 != nullptr )
    {
      v9 = HIDWORD(v8->m_pfnProxied);
      *((_DWORD *)frameProfile + 35) = v9;
      m_pfnProxied_high += v9;
    }
    v10 = GFxAmpMemItem::SearchForName(result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *)((char *)&stru_10299D8C.m_pfnProxied + 8));
    if ( v10 != nullptr )
    {
      v11 = HIDWORD(v10->m_pfnProxied);
      *((_DWORD *)frameProfile + 36) = v11;
      m_pfnProxied_high += v11;
    }
    v12 = GFxAmpMemItem::SearchForName(result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *)"Movie Data");
    if ( v12 != nullptr )
    {
      v13 = HIDWORD(v12->m_pfnProxied);
      *((_DWORD *)frameProfile + 31) = v13;
      m_pfnProxied_high += v13;
    }
    v14 = GFxAmpMemItem::SearchForName(result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *)"Movie View");
    if ( v14 != nullptr )
    {
      v15 = HIDWORD(v14->m_pfnProxied);
      *((_DWORD *)frameProfile + 32) = v15;
      m_pfnProxied_high += v15;
    }
    v16 = GFxAmpMemItem::SearchForName(result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *)"Mesh Cache");
    if ( v16 != nullptr )
    {
      v17 = HIDWORD(v16->m_pfnProxied);
      *((_DWORD *)frameProfile + 33) = v17;
      m_pfnProxied_high += v17;
    }
    v18 = GFxAmpMemItem::SearchForName(result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *)&result.m_pObject);
    if ( v18 != nullptr )
    {
      v19 = HIDWORD(v18->m_pfnProxied);
      *((_DWORD *)frameProfile + 34) = v19;
      m_pfnProxied_high += v19;
    }
  }
  v20 = GFxAmpMemItem::SearchForName(result: &result);
  if ( v20 != nullptr )
    m_pfnProxied_high += HIDWORD(v20->m_pfnProxied);
  v21 = *((_DWORD *)frameProfile + 29);
  if ( m_pfnProxied_high >= v21 )
    v21 = m_pfnProxied_high;
  v22 = v21 - m_pfnProxied_high;
  m_nGrowSize = v138.m_nGrowSize;
  v125.m_pMemory = (CImagePacker *)&fontMap;
  v24 = (CMemberFuncProxy5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CFuncMemPolicyNone> *)v138.m_nGrowSize;
  *((_DWORD *)frameProfile + 37) = v22;
  resourceMap = nullptr;
  fontMap = nullptr;
  GFxAmpServer::CollectImageData(this: v24, &resourceMap, fontMap: v125, a4: v127);
  MaxId = GFxAmpMemItem::GetMaxId(result: v126);
  lastItemId = (unsigned int)MaxId;
  v132.m_nAllocationCount = 2;
  AllocAutoHeap_2 = GMemory::pGlobalHeap->AllocAutoHeap_2;
  v122 = m_nGrowSize;
  extImageSize = 0;
  v27 = ((int (__thiscall *)(GMemoryHeap *))AllocAutoHeap_2)(a1: GMemory::pGlobalHeap);
  v28 = v27;
  if ( v27 != 0 )
  {
    v29 = (unsigned int)&MaxId->m_pfnProxied + 1;
    *(_DWORD *)v27 = &GRefCountImplCore::`vftable';
    lastItemId = v29;
    *(_DWORD *)(v27 + 4) = 1;
    *(_DWORD *)v27 = &GFxAmpMemItem::`vftable';
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v27 + 8));
    *(_DWORD *)(v28 + 12) = 0;
    *(_WORD *)(v28 + 16) = 0;
    *(_DWORD *)(v28 + 20) = v29;
    *(_DWORD *)(v28 + 24) = 0;
    *(_DWORD *)(v28 + 28) = 0;
    *(_DWORD *)(v28 + 32) = 0;
    *(_DWORD *)(v28 + 36) = 0;
    v142 = (CFunctorCallbackBase *)v28;
  }
  else
  {
    v142 = nullptr;
  }
  if ( resourceMap != nullptr )
  {
    v31 = nullptr;
    v32 = resourceMap + 2;
    do
    {
      if ( v32->__vftable != (ITexture_vtbl *)-2 )
        break;
      v31 = (ITexture_vtbl *)((char *)v31 + 1);
      v32 += 6;
    }
    while ( v31 <= resourceMap[1].__vftable );
    p_resourceMap = &resourceMap;
  }
  else
  {
    p_resourceMap = nullptr;
    v31 = nullptr;
  }
  v147 = p_resourceMap;
  imageMem = (int)v31;
  while ( v147 != nullptr )
  {
    v33 = *v147;
    if ( *v147 == nullptr || imageMem > (int)v33[1].__vftable )
      break;
    i = 24 * imageMem;
    v34 = (unsigned int)&v33[6 * imageMem];
    v35 = *(_DWORD *)(v34 + 24) == 0;
    j = 0;
    if ( !v35 )
    {
      do
      {
        v36 = *(_DWORD **)(*(_DWORD *)(v34 + 20) + 4 * j);
        v37 = v36[3];
        if ( v37 != 0 )
        {
          v38 = (*(int (__thiscall **)(int))(*(_DWORD *)v37 + 16))(a1: v37);
          v39 = v38;
          if ( v38 != 0 )
          {
            extImageSize += v38;
            GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v145);
            v40 = v36[4];
            if ( v40 != 0 )
              v41 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v40 + 24))(a1: v40, a2: v36[5]);
            else
              v41 = 0;
            GString::GString(this: &v141, src: v41);
            if ( (*(_DWORD *)(v141.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
            {
              v42 = (int *)GString::operator+(result: (CImagePacker *)&v141, a2: &v132, putf8str: (CImagePacker *)" ");
              GString::operator+=(
                this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v145,
                src: v42,
                srcSize: v122);
              v43 = (void *)((int)v132.m_pMemory & 0xFFFFFFFC);
              if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v132.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
                GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v43);
            }
            if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v36 + 8))(a1: v36) == 2 )
            {
              GString::AppendString(
                this: (CUtlMemory<CImagePacker,int> *)&v145,
                putf8str: (CImagePacker *)&stru_1029D98C.m_FirstFree,
                utf8StrSz: -1);
            }
            else if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v36 + 8))(a1: v36) == 1 )
            {
              GString::AppendString(
                this: (CUtlMemory<CImagePacker,int> *)&v145,
                putf8str: (CImagePacker *)&stru_1029D98C.m_Elements.m_nGrowSize,
                utf8StrSz: -1);
            }
            GString::GString(this: &v138);
            v44 = v36[3];
            if ( v44 != 0 )
              v137 = (*(int (__thiscall **)(int))(*(_DWORD *)v44 + 8))(a1: v44);
            else
              v137 = 0;
            v45 = v36[3];
            if ( v45 != 0 )
              v133 = (*(int (__thiscall **)(int))(*(_DWORD *)v45 + 4))(a1: v45);
            else
              v133 = 0;
            v130.m_nAllocationCount = (v145 & 0xFFFFFFFC) + 8;
            v128[0] = 0;
            v128[1] = &v138;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)v158, a2: (const struct GMsgFormat::Sink *)v128);
            GMsgFormat::Parse(result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_1029D98C);
            GMsgFormat::FormatD1<char const *>(
              this: (CMatQueuedRenderContext::CCallQueueExternal *)v158,
              v: (const CMatQueuedRenderContext::CCallQueueExternal *)&v130.m_nAllocationCount);
            GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)v158, a2: (int)&v133);
            GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)v158, a2: (int)&v137);
            GMsgFormat::FinishFormatD(this: v158, a2: v122);
            GMsgFormat::~GMsgFormat(this: v158, data_size: v123);
            v46 = (IShaderDevice *)GFxAmpMemItem::AddChild(
                                     this: (GFxAmpMemItem *)v142,
                                     id: ++lastItemId,
                                     a3: (const char *)(((int)v138.m_pMemory & 0xFFFFFFFC) + 8),
                                     a4: v39);
            v46[6].__vftable = (IShaderDevice_vtbl *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)v36[3] + 36))(a1: v36[3]);
            GRefCountImpl::AddRef(this: v46);
            v47 = *((GRenderer::CachedData **)v150 + 49);
            pRenderer = v47[4].pRenderer;
            v47 = (GRenderer::CachedData *)((char *)v47 + 28);
            GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
              this: v47,
              result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)v47,
              newSize: (unsigned int)&pRenderer->__vftable + 1);
            v49 = (IShaderDevice **)((char *)v47->pRenderer + 4 * (int)v47->hData - 4);
            if ( v49 != nullptr )
            {
              GRefCountImpl::AddRef(this: v46);
              *v49 = v46;
            }
            GRefCountImpl::Release(this: (IShaderAPI *)v46);
            v50 = (void *)((int)v138.m_pMemory & 0xFFFFFFFC);
            if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v138.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v50);
            v51 = (void *)(v141.HeapTypeBits & 0xFFFFFFFC);
            if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v141.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v51);
            v52 = (void *)(v145 & 0xFFFFFFFC);
            if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v145 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v52);
          }
        }
        v34 = (unsigned int)*v147 + i;
        ++j;
      }
      while ( j < *(_DWORD *)(v34 + 24) );
    }
    v53 = *v147;
    v54 = (unsigned int)(*v147)[1].__vftable;
    if ( imageMem <= (int)v54 )
    {
      v55 = imageMem + 1;
      imageMem = v55;
      if ( v55 <= v54 )
      {
        v56 = &v53[6 * v55 + 2];
        do
        {
          if ( v56->__vftable != (ITexture_vtbl *)-2 )
            break;
          v56 += 6;
          ++imageMem;
        }
        while ( imageMem <= v54 );
      }
    }
  }
  v57 = extImageSize;
  if ( extImageSize != 0 )
  {
    v58 = v142;
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v142->m_iRefs,
      a2: "External Images");
    GFxAmpMemItem::SetValue(this: v58, memValue: v57);
    v59 = *((GRenderer::CachedData **)v150 + 47);
    v60 = v59[4].pRenderer;
    v59 = (GRenderer::CachedData *)((char *)v59 + 28);
    GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v59,
      result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)v59,
      newSize: (unsigned int)&v60->__vftable + 1);
    v61 = (CFunctorCallbackBase **)((char *)v59->pRenderer + 4 * (int)v59->hData - 4);
    if ( v61 != nullptr )
    {
      if ( v58 != nullptr )
        GRefCountImpl::AddRef(this: (IShaderDevice *)v58);
      *v61 = v58;
    }
  }
  v62 = v150;
  v63 = GFxAmpMemItem::SearchForName(result: &stru_10299D8C);
  v64 = v63;
  imageMem = (int)v63;
  if ( v63 != nullptr )
  {
    v65 = 0;
    i = 0;
    if ( DWORD2(v63[1].m_pfnProxied) != 0 )
    {
      v66 = resourceMap;
      do
      {
        v152 = *(GFxAmpMemItem **)(DWORD1(v64[1].m_pfnProxied) + 4 * v65);
        v130.m_nGrowSize = (int)&v152->Name;
        if ( v66 != nullptr )
        {
          v67 = v152->Name.HeapTypeBits & 0xFFFFFFFC;
          v121 = *(_DWORD *)v67 & 0x7FFFFFFF;
          v155 = false;
          v139 = 0;
          v68 = GString::BernsteinHashFunctionCIS(
                  result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v67 + 8),
                  size: v121,
                  seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
          v69 = GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
                  this: &resourceMap,
                  a2: (_DWORD **)&v130.m_nGrowSize,
                  a3: v68 & (int)resourceMap[1].__vftable);
          v66 = resourceMap;
          if ( v69 >= 0 && resourceMap != nullptr && v69 <= (int)resourceMap[1].__vftable )
          {
            v70 = 0;
            v71 = 24 * v69;
            v132.m_nGrowSize = 0;
            v134 = v71;
            if ( *(ITexture_vtbl **)((char *)&resourceMap[6].__vftable + v71) != nullptr )
            {
              do
              {
                v72 = *((_DWORD **)&(*(ITexture_vtbl **)((char *)&v66[5].__vftable + v71))->GetName + v70);
                v73 = v72[3];
                if ( v73 != 0 )
                {
                  v74 = (*(int (__thiscall **)(int))(*(_DWORD *)v73 + 12))(a1: v73);
                  if ( v74 != 0 )
                  {
                    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v144);
                    v75 = v72[4];
                    if ( v75 != 0 )
                      v76 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v75 + 24))(a1: v75, a2: v72[5]);
                    else
                      v76 = 0;
                    GString::GString(this: &v140, src: v76);
                    if ( (*(_DWORD *)(v140.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
                    {
                      v77 = (int *)GString::operator+(
                                     result: (CImagePacker *)&v140,
                                     a2: &v130,
                                     putf8str: (CImagePacker *)" ");
                      GString::operator+=(
                        this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v144,
                        src: v77,
                        srcSize: v122);
                      v78 = (void *)((int)v130.m_pMemory & 0xFFFFFFFC);
                      if ( InterlockedExchangeAdd(
                             Addend: (volatile LONG *)(((int)v130.m_pMemory & 0xFFFFFFFC) + 4),
                             Value: -1) == 1 )
                        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v78);
                    }
                    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v72 + 8))(a1: v72) == 2 )
                    {
                      GString::AppendString(
                        this: (CUtlMemory<CImagePacker,int> *)&v144,
                        putf8str: (CImagePacker *)&stru_1029D98C.m_FirstFree,
                        utf8StrSz: -1);
                    }
                    else if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v72 + 8))(a1: v72) == 1 )
                    {
                      GString::AppendString(
                        this: (CUtlMemory<CImagePacker,int> *)&v144,
                        putf8str: (CImagePacker *)&stru_1029D98C.m_Elements.m_nGrowSize,
                        utf8StrSz: -1);
                    }
                    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v138.m_nAllocationCount);
                    v79 = v72[3];
                    if ( v79 != 0 )
                      v135 = (*(int (__thiscall **)(int))(*(_DWORD *)v79 + 8))(a1: v79);
                    else
                      v135 = 0;
                    v80 = v72[3];
                    if ( v80 != 0 )
                      v136 = (*(int (__thiscall **)(int))(*(_DWORD *)v80 + 4))(a1: v80);
                    else
                      v136 = 0;
                    v131.__vftable = (CMatQueuedRenderContext::CCallQueueExternal_vtbl *)((v144 & 0xFFFFFFFC) + 8);
                    v129[0] = 0;
                    v129[1] = &v138.m_nAllocationCount;
                    GMsgFormat::GMsgFormat(this: (GMsgFormat *)v157, a2: (const struct GMsgFormat::Sink *)v129);
                    GMsgFormat::Parse(result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_1029D98C);
                    GMsgFormat::FormatD1<char const *>(
                      this: (CMatQueuedRenderContext::CCallQueueExternal *)v157,
                      v: &v131);
                    GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)v157, a2: (int)&v136);
                    GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)v157, a2: (int)&v135);
                    GMsgFormat::FinishFormatD(this: v157, a2: v122);
                    GMsgFormat::~GMsgFormat(this: v157, data_size: v124);
                    v81 = (IShaderDevice *)GFxAmpMemItem::AddChild(
                                             this: v152,
                                             id: ++lastItemId,
                                             a3: (const char *)((v138.m_nAllocationCount & 0xFFFFFFFC) + 8),
                                             a4: v74);
                    v81[6].__vftable = (IShaderDevice_vtbl *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)v72[3] + 36))(a1: v72[3]);
                    GRefCountImpl::AddRef(this: v81);
                    v82 = *((_DWORD *)v150 + 49);
                    v83 = *(_DWORD *)(v82 + 32);
                    v84 = v83;
                    v85 = (GRenderer::CachedData *)(v82 + 28);
                    v86 = v83 + 1;
                    if ( v86 >= v84 )
                    {
                      if ( (GRenderer *)v86 >= v85[1].pRenderer )
                        GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
                          this: v85,
                          pheapAddr: v85,
                          newCapacity: v86 + (v86 >> 2));
                    }
                    else
                    {
                      v87 = v84 - v86;
                      extImageSize = (unsigned int)v85->pRenderer + 4 * v87 + 4 * v86 - 4;
                      if ( v87 != 0 )
                      {
                        for ( j = v87; j != 0; --j )
                        {
                          if ( *(_DWORD *)extImageSize != 0 )
                            GRefCountImpl::Release(this: *(IShaderAPI **)extImageSize);
                          extImageSize -= 4;
                        }
                      }
                      if ( v86 < (unsigned int)v85[1].pRenderer >> 1 )
                        GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
                          this: v85,
                          pheapAddr: v85,
                          newCapacity: v86);
                    }
                    v88 = v85->pRenderer;
                    v85->hData = (void *)v86;
                    v89 = (IShaderDevice **)((char *)v88 + 4 * v86 - 4);
                    if ( (GRenderer *)((char *)v88 + 4 * v86) != (GRenderer *)4 )
                    {
                      GRefCountImpl::AddRef(this: v81);
                      *v89 = v81;
                    }
                    GRefCountImpl::Release(this: (IShaderAPI *)v81);
                    v90 = (void *)(v138.m_nAllocationCount & 0xFFFFFFFC);
                    if ( InterlockedExchangeAdd(
                           Addend: (volatile LONG *)((v138.m_nAllocationCount & 0xFFFFFFFC) + 4),
                           Value: -1) == 1 )
                      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v90);
                    v91 = (void *)(v140.HeapTypeBits & 0xFFFFFFFC);
                    if ( InterlockedExchangeAdd(
                           Addend: (volatile LONG *)((v140.HeapTypeBits & 0xFFFFFFFC) + 4),
                           Value: -1) == 1 )
                      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v91);
                    v92 = (void *)(v144 & 0xFFFFFFFC);
                    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v144 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
                      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v92);
                  }
                  v71 = v134;
                  v66 = resourceMap;
                }
                v70 = v132.m_nGrowSize + 1;
                v132.m_nGrowSize = v70;
              }
              while ( (ITexture_vtbl *)v70 < *(ITexture_vtbl **)((char *)&v66[6].__vftable + v71) );
              v64 = (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *)imageMem;
              v62 = v150;
              v65 = i;
            }
          }
        }
        i = ++v65;
      }
      while ( v65 < DWORD2(v64[1].m_pfnProxied) );
    }
  }
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(*((_DWORD *)v62 + 49) + 8),
    a2: "Images");
  *(_BYTE *)(*((_DWORD *)v62 + 49) + 17) = 1;
  v93 = *((CFunctorCallbackBase **)v62 + 49);
  v94 = 0;
  if ( v93[2].m_iRefs != 0 )
  {
    v95 = v93[2].CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
    m_iRefs = v93[2].m_iRefs;
    do
    {
      v94 += *((_DWORD *)v95->dtr_CRefCountServiceBase<1,CRefMT> + 3);
      v95 = (CRefCountServiceBase<1,CRefMT>_vtbl *)((char *)v95 + 4);
      --m_iRefs;
    }
    while ( m_iRefs != 0 );
    if ( v94 != 0 )
      GFxAmpMemItem::SetValue(this: v93, memValue: v94);
  }
  p_fontMap = fontMap;
  if ( fontMap != nullptr )
  {
    v98 = nullptr;
    v99 = fontMap + 2;
    do
    {
      if ( *v99 != -2 )
        break;
      v98 = (GFxAmpMemItem *)((char *)v98 + 1);
      v99 += 6;
    }
    while ( (unsigned int)v98 <= fontMap[1] );
    p_fontMap = &fontMap;
  }
  else
  {
    v98 = nullptr;
  }
  v151 = p_fontMap;
  v152 = v98;
  while ( v151 != nullptr && *v151 != 0 && (int)v152 <= *(_DWORD *)(*v151 + 4) )
  {
    imageMem = 2;
    v100 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                     this: GMemory::pGlobalHeap,
                     a2: v138.m_nGrowSize,
                     a3: 40,
                     a4: &imageMem);
    v101 = v100;
    if ( v100 != nullptr )
    {
      v102 = lastItemId;
      *(_DWORD *)v100 = &GRefCountImplCore::`vftable';
      lastItemId = ++v102;
      *((_DWORD *)v100 + 1) = 1;
      *(_DWORD *)v100 = &GFxAmpMemItem::`vftable';
      GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v100 + 8));
      *((_DWORD *)v101 + 3) = 0;
      *((_WORD *)v101 + 8) = 0;
      *((_DWORD *)v101 + 5) = v102;
      *((_DWORD *)v101 + 6) = 0;
      *((_DWORD *)v101 + 7) = 0;
      *((_DWORD *)v101 + 8) = 0;
      *((_DWORD *)v101 + 9) = 0;
      v103 = v101;
    }
    else
    {
      v103 = nullptr;
    }
    v104 = 24 * (_DWORD)v152;
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v103 + 8),
      src: (_DWORD *)(24 * (_DWORD)v152 + *v151 + 16),
      a3: v122);
    v105 = v151;
    v103[17] = 1;
    v106 = 0;
    if ( *(_DWORD *)(v104 + *v105 + 24) != 0 )
    {
      do
      {
        GFxAmpMemItem::AddChild(a1: (CFunctor *)++lastItemId);
        ++v106;
      }
      while ( v106 < *(_DWORD *)(v104 + *v151 + 24) );
    }
    v107 = *((_DWORD *)v150 + 50);
    v108 = *(_DWORD *)(v107 + 32);
    v109 = v108;
    v110 = (GRenderer::CachedData *)(v107 + 28);
    v111 = v108 + 1;
    if ( v111 >= v109 )
    {
      if ( (GRenderer *)v111 >= v110[1].pRenderer )
        GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
          this: v110,
          pheapAddr: v110,
          newCapacity: v111 + (v111 >> 2));
    }
    else
    {
      v112 = v109 - v111;
      extImageSize = (unsigned int)v110->pRenderer + 4 * v112 + 4 * v111 - 4;
      if ( v112 != 0 )
      {
        for ( i = v112; i != 0; --i )
        {
          if ( *(_DWORD *)extImageSize != 0 )
            GRefCountImpl::Release(this: *(IShaderAPI **)extImageSize);
          extImageSize -= 4;
        }
      }
      if ( v111 < (unsigned int)v110[1].pRenderer >> 1 )
        GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
          this: v110,
          pheapAddr: v110,
          newCapacity: v111);
    }
    v113 = v110->pRenderer;
    v110->hData = (void *)v111;
    v114 = (GRenderer *)((char *)v113 + 4 * v111 - 4);
    if ( v114 != nullptr )
    {
      GRefCountImpl::AddRef(this: (IShaderDevice *)v103);
      v114->__vftable = (GRenderer_vtbl *)v103;
    }
    GRefCountImpl::Release(this: (IShaderAPI *)v103);
    v115 = *v151;
    v116 = *(_DWORD *)(*v151 + 4);
    if ( (int)v152 <= (int)v116 )
    {
      v117 = (GFxAmpMemItem *)((char *)&v152->__vftable + 1);
      v152 = v117;
      if ( (unsigned int)v117 <= v116 )
      {
        v118 = (_DWORD *)(v115 + 24 * (_DWORD)v117 + 8);
        do
        {
          if ( *v118 != -2 )
            break;
          v118 += 6;
          v152 = (GFxAmpMemItem *)((char *)v152 + 1);
        }
        while ( (unsigned int)v152 <= v116 );
      }
    }
  }
  v119 = v150;
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(*((_DWORD *)v150 + 50) + 8),
    a2: "Fonts");
  v120 = (IShaderAPI *)v142;
  *(_BYTE *)(*((_DWORD *)v119 + 50) + 17) = 1;
  if ( v120 != nullptr )
    GRefCountImpl::Release(this: v120);
  GHashSetBase<GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GString,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GString,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>(this: &fontMap);
  GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2>,GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>>(this: (int *)&resourceMap);
}

//------------------------------------------------------------------------------
// Address: 0x1007A370
// Name: private: void GFxAmpServer::SendFrameStats(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxAmpServer::SendFrameStats(GFxAmpServer *this@<ecx>, double a2@<st0>)
{
  GFxAmpServer *v2; // esi
  CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v3; // eax
  float v4; // ecx
  char *v5; // eax
  char *v6; // edi
  unsigned int v7; // ecx
  int v8; // eax
  int v9; // edx
  unsigned __int64 v10; // kr00_8
  int v11; // ecx
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *pTable; // eax
  __int32 p_HandleToSwdIdMap; // edx
  unsigned int v14; // ebx
  unsigned int v15; // edx
  _DWORD *v16; // eax
  int v17; // ecx
  int v18; // esi
  GRenderer::CachedData *v19; // edi
  GRenderer_vtbl **v20; // eax
  unsigned int v21; // esi
  GRenderer *pRenderer; // ecx
  GRenderer *v23; // esi
  unsigned int v24; // eax
  _DWORD *v25; // ecx
  struct GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v26; // eax
  __int32 p_HandleToSourceFileMap; // edx
  unsigned int v28; // edi
  unsigned int v29; // ecx
  _DWORD *v30; // eax
  int v31; // eax
  char *v32; // ebx
  unsigned int v33; // esi
  int v34; // eax
  _DWORD *v35; // esi
  int v36; // eax
  unsigned int v37; // eax
  _DWORD *v38; // ecx
  char *v39; // edi
  void *v40; // eax
  struct GFxAmpMessage *v41; // eax
  GFxAmpViewStats *v42; // edi
  float v43; // ecx
  float v44; // ecx
  float v45; // [esp+0h] [ebp-3Ch]
  float v46; // [esp+0h] [ebp-3Ch]
  float v47; // [esp+0h] [ebp-3Ch]
  float v48; // [esp+0h] [ebp-3Ch]
  float v49; // [esp+0h] [ebp-3Ch]
  float *v50; // [esp+4h] [ebp-38h]
  float *v51; // [esp+4h] [ebp-38h]
  bool v52; // [esp+8h] [ebp-34h]
  VProfReportType_t it; // [esp+24h] [ebp-18h]
  VProfReportType_t ita; // [esp+24h] [ebp-18h]
  GLock *lpCriticalSection; // [esp+2Ch] [ebp-10h]
  int v56; // [esp+30h] [ebp-Ch] BYREF
  GFxAmpServer *v57; // [esp+34h] [ebp-8h]
  char *frameProfile; // [esp+38h] [ebp-4h]

  v2 = this;
  v57 = this;
  lpCriticalSection = &this->FrameDataLock;
  EnterCriticalSection(lpCriticalSection: &this->FrameDataLock.cs);
  v56 = 2;
  v3 = (CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v2, a3: 208, a4: &v56);
  if ( v3 != nullptr )
  {
    GFxAmpProfileFrame::GFxAmpProfileFrame(this: v3, a2: LOWORD(v45), a3: (unsigned __int16)v50, a4: v52);
    v6 = v5;
    frameProfile = v5;
  }
  else
  {
    frameProfile = nullptr;
    v6 = nullptr;
  }
  GTimer::GetProfileTicks(a1: v4, a2: v45, a3: v50);
  v7 = lastTick;
  *((_DWORD *)v6 + 2) = v8;
  *((_DWORD *)v6 + 3) = v9;
  if ( __PAIR64__(v7, dword_103593E4) != 0 )
  {
    v10 = *((_QWORD *)v6 + 1) - __PAIR64__(dword_103593E4, v7);
    if ( v10 != 0 )
      *((_DWORD *)v6 + 4) = 0xF4240 / v10;
  }
  v11 = *((_DWORD *)v6 + 3);
  LODWORD(lastTick) = *((_DWORD *)v6 + 2);
  dword_103593E4 = v11;
  EnterCriticalSection(lpCriticalSection: &v2->SwfLock.cs);
  pTable = v2->HandleToSwdIdMap.Hash.pTable;
  if ( pTable != nullptr )
  {
    v15 = *((_DWORD *)pTable + 1);
    v14 = 0;
    v16 = (_DWORD *)((char *)pTable + 8);
    do
    {
      if ( *v16 != -2 )
        break;
      ++v14;
      v16 += 4;
    }
    while ( v14 <= v15 );
    it = (VProfReportType_t)&v2->HandleToSwdIdMap;
    p_HandleToSwdIdMap = (__int32)&v2->HandleToSwdIdMap;
  }
  else
  {
    p_HandleToSwdIdMap = 0;
    it = 0;
    v14 = 0;
  }
  while ( p_HandleToSwdIdMap != 0 )
  {
    v17 = *(_DWORD *)p_HandleToSwdIdMap;
    if ( *(_DWORD *)p_HandleToSwdIdMap == 0 || (signed int)v14 > *(_DWORD *)(v17 + 4) )
      break;
    v18 = *((_DWORD *)v6 + 42);
    v19 = (GRenderer::CachedData *)(v6 + 164);
    v20 = (GRenderer_vtbl **)(v17 + 16 * (v14 + 1));
    v21 = v18 + 1;
    v56 = (int)v20;
    if ( (void *)v21 >= v19->hData )
    {
      if ( (GRenderer *)v21 < v19[1].pRenderer )
        goto LABEL_23;
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v19,
        pheapAddr: v19,
        newCapacity: v21 + (v21 >> 2));
    }
    else
    {
      if ( v21 >= (unsigned int)v19[1].pRenderer >> 1 )
        goto LABEL_23;
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v19,
        pheapAddr: v19,
        newCapacity: v21);
    }
    v20 = (GRenderer_vtbl **)v56;
    p_HandleToSwdIdMap = it;
LABEL_23:
    pRenderer = v19->pRenderer;
    v19->hData = (void *)v21;
    v23 = (GRenderer *)((char *)pRenderer + 4 * v21 - 4);
    if ( v23 != nullptr )
      v23->__vftable = *v20;
    v24 = *(_DWORD *)(*(_DWORD *)p_HandleToSwdIdMap + 4);
    if ( (int)v14 <= (int)v24 && ++v14 <= v24 )
    {
      v25 = (_DWORD *)(*(_DWORD *)p_HandleToSwdIdMap + 16 * v14 + 8);
      do
      {
        if ( *v25 != -2 )
          break;
        ++v14;
        v25 += 4;
      }
      while ( v14 <= v24 );
    }
    v6 = frameProfile;
    v2 = v57;
  }
  LeaveCriticalSection(lpCriticalSection: &v2->SwfLock.cs);
  EnterCriticalSection(lpCriticalSection: &v2->SourceFileLock.cs);
  v26 = v2->HandleToSourceFileMap.Hash.pTable;
  p_HandleToSourceFileMap = (__int32)&v2->HandleToSourceFileMap;
  if ( v26 != nullptr )
  {
    v29 = *((_DWORD *)v26 + 1);
    v28 = 0;
    v30 = (_DWORD *)((char *)v26 + 8);
    do
    {
      if ( *v30 != -2 )
        break;
      ++v28;
      v30 += 6;
    }
    while ( v28 <= v29 );
    ita = (VProfReportType_t)&v2->HandleToSourceFileMap;
  }
  else
  {
    p_HandleToSourceFileMap = 0;
    ita = 0;
    v28 = 0;
  }
  while ( p_HandleToSourceFileMap != 0 )
  {
    v31 = *(_DWORD *)p_HandleToSourceFileMap;
    if ( *(_DWORD *)p_HandleToSourceFileMap == 0 || (signed int)v28 > *(_DWORD *)(v31 + 4) )
      break;
    v32 = frameProfile + 176;
    v33 = *((_DWORD *)frameProfile + 45) + 1;
    v56 = v31 + 24 * v28 + 16;
    if ( v33 >= *((_DWORD *)frameProfile + 45) )
    {
      if ( v33 < *((_DWORD *)frameProfile + 46) )
        goto LABEL_47;
      GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
        this: (CStudioHdr *)(frameProfile + 176),
        pheapAddr: (const CStudioHdr *)(frameProfile + 176),
        newCapacity: v33 + (v33 >> 2));
    }
    else
    {
      if ( v33 >= *((_DWORD *)frameProfile + 46) >> 1 )
        goto LABEL_47;
      GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
        this: (CStudioHdr *)(frameProfile + 176),
        pheapAddr: (const CStudioHdr *)(frameProfile + 176),
        newCapacity: v33);
    }
    p_HandleToSourceFileMap = ita;
LABEL_47:
    v34 = *(_DWORD *)v32;
    *((_DWORD *)v32 + 1) = v33;
    v35 = (_DWORD *)(v34 + 8 * v33 - 8);
    if ( v35 != nullptr )
    {
      v36 = v56;
      *v35 = *(_DWORD *)v56;
      v35[1] = *(_DWORD *)(v36 + 4);
    }
    v37 = *(_DWORD *)(*(_DWORD *)p_HandleToSourceFileMap + 4);
    if ( (int)v28 <= (int)v37 && ++v28 <= v37 )
    {
      v38 = (_DWORD *)(*(_DWORD *)p_HandleToSourceFileMap + 24 * v28 + 8);
      do
      {
        if ( *v38 != -2 )
          break;
        ++v28;
        v38 += 6;
      }
      while ( v28 <= v37 );
    }
    v2 = v57;
  }
  LeaveCriticalSection(lpCriticalSection: &v2->SourceFileLock.cs);
  v39 = frameProfile;
  GFxAmpServer::CollectMovieData(this: (ConVar *)v2, a2, (GRenderer::CachedData *)frameProfile, lock: v46);
  GFxAmpServer::CollectRendererData(this: (ConVar *)v2, frameProfile: v39, renderers: v47);
  GFxAmpServer::CollectMemoryData(this: (ConVar *)v2, frameProfile: v39, imageMap: v48);
  v56 = 2;
  v40 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v2, a3: 28, a4: &v56);
  if ( v40 != nullptr )
    v41 = (struct GFxAmpMessage *)GFxAmpMessageProfileFrame::GFxAmpMessageProfileFrame(a1: v40, a2: v39);
  else
    v41 = nullptr;
  GFxAmpThreadMgr::SendAmpMessage(this: v2->ThreadMgr.pObject, a2: v41);
  if ( v2->MovieStats.Data.Size != 0 )
  {
    v42 = *(GFxAmpViewStats **)(*(_DWORD *)v2->MovieStats.Data.Data + 8);
    if ( v42 != nullptr )
    {
      GFxAmpViewStats::PushCallstack(this: v42, swdHandle: 1u, a3: 0x41u);
      GTimer::GetRawTicks(li: v43, a2: v49, a3: v51);
    }
    GEvent::Wait(this: (CDbgFmtMsg *)&v2->SendingEvent);
    if ( v42 != nullptr )
    {
      GTimer::GetRawTicks(li: v44, a2: v49, a3: v51);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
  }
  LeaveCriticalSection(lpCriticalSection: &lpCriticalSection->cs);
}

//------------------------------------------------------------------------------
// Address: 0x1007A6E0
// Name: public: void GFxAmpServer::AdvanceFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxAmpServer::AdvanceFrame(GFxAmpServer *this@<ecx>, double a2@<st0>)
{
  if ( GFxAmpServer::IsProfiling((int)this) )
  {
    GFxAmpServer::SendFrameStats(this, a2);
  }
  else
  {
    GFxAmpServer::ClearMovieData(this);
    GFxAmpServer::ClearRendererData(this);
  }
  EnterCriticalSection(lpCriticalSection: &this->ToggleStateLock.cs);
  if ( this->ToggleState != 0 )
  {
    GFxAmpServer::ToggleAmpState(this, a2: this->ToggleState);
    this->ToggleState = 0;
  }
  LeaveCriticalSection(lpCriticalSection: &this->ToggleStateLock.cs);
}
