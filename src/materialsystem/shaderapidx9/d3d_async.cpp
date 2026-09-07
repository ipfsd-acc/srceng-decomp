// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/d3d_async.cpp
// Functions: 13
// ============================================================

#include "materialsystem\shaderapidx9\d3d_async.h"

//------------------------------------------------------------------------------
// Address: 0x10002C70
// Name: public: static struct IDirect3DSurface9 __near * nv::stereo::D3D9Type::CreateStagingResource(struct IDirect3DDevice9 __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
IDirect3DSurface9 *__cdecl nv::stereo::D3D9Type::CreateStagingResource(
        IDirect3DDevice9 *pDevice,
        float eyeSep,
        float sep,
        float conv)
{
  HRESULT (__stdcall *CreateOffscreenPlainSurface)(IDirect3DDevice9 *, unsigned int, unsigned int, _D3DFORMAT, _D3DPOOL, IDirect3DSurface9 **, void **); // eax
  IDirect3DSurface9 *result; // eax
  float *pBits; // eax
  _D3DLOCKED_RECT lr; // [esp+0h] [ebp-Ch] BYREF
  IDirect3DSurface9 *staging; // [esp+8h] [ebp-4h] BYREF

  CreateOffscreenPlainSurface = pDevice->CreateOffscreenPlainSurface;
  staging = nullptr;
  CreateOffscreenPlainSurface(
    this: pDevice,
    a2: 16u,
    a3: 2u,
    a4: D3DFMT_R32F,
    a5: D3DPOOL_SYSTEMMEM,
    a6: &staging,
    a7: nullptr);
  result = staging;
  if ( staging != nullptr )
  {
    staging->LockRect(this: staging, a2: &lr, a3: nullptr, a4: 0);
    pBits = (float *)lr.pBits;
    *(float *)lr.pBits = -(float)((float)(eyeSep * sep) * 0.0049999999);
    pBits[1] = conv;
    pBits[2] = -1.0;
    pBits[8] = -*pBits;
    pBits[9] = pBits[1];
    pBits[10] = -pBits[2];
    pBits[16] = 717.34851;
    *((_DWORD *)pBits + 17) = 16;
    *((_DWORD *)pBits + 18) = 2;
    *((_DWORD *)pBits + 19) = 32;
    pBits[20] = 0.0;
    staging->UnlockRect(this: staging);
    return staging;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002D50
// Name: public: static void nv::stereo::D3D9Type::UpdateTextureFromStaging(struct IDirect3DDevice9 __near *,struct IDirect3DTexture9 __near *,struct IDirect3DSurface9 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl nv::stereo::D3D9Type::UpdateTextureFromStaging(
        IDirect3DDevice9 *pDevice,
        IDirect3DSurface9 *tex,
        IDirect3DSurface9 *staging)
{
  HRESULT (__stdcall *AddRef)(IDirect3DTexture9 *, unsigned int, IDirect3DSurface9 **); // eax
  tagRECT stereoSrcRect; // [esp+4h] [ebp-18h] BYREF
  tagPOINT stereoDstPoint; // [esp+14h] [ebp-8h] BYREF

  AddRef = (HRESULT (__stdcall *)(IDirect3DTexture9 *, unsigned int, IDirect3DSurface9 **))tex->__vftable[1].AddRef;
  stereoSrcRect.top = 0;
  stereoSrcRect.bottom = 1;
  stereoSrcRect.left = 0;
  stereoSrcRect.right = 8;
  stereoDstPoint.x = 0;
  stereoDstPoint.y = 0;
  AddRef(this: (IDirect3DTexture9 *)tex, a2: 0, a3: &tex);
  pDevice->UpdateSurface(this: pDevice, a2: staging, a3: &stereoSrcRect, a4: tex, a5: &stereoDstPoint);
  tex->Release(this: tex);
}

//------------------------------------------------------------------------------
// Address: 0x10002DB0
// Name: private: class PushBuffer __near * D3DDeviceWrapper::FindFreePushBuffer(enum PushBufferState)
// Source: json
//------------------------------------------------------------------------------
PushBuffer *__thiscall D3DDeviceWrapper::FindFreePushBuffer(D3DDeviceWrapper *this, volatile PushBufferState newstate)
{
  int v3; // eax

LABEL_1:
  v3 = 0;
  while ( PushBuffers[v3]->m_State != PUSHBUFFER_AVAILABLE )
  {
    if ( ++v3 >= 500 )
    {
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this);
      Sleep(dwMilliseconds: 0);
      goto LABEL_1;
    }
  }
  PushBuffers[v3]->m_State = newstate;
  return (PushBuffer *)PushBuffers[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10002E00
// Name: public: bool nv::stereo::HL2Stereo<struct nv::stereo::D3D9Type>::RequiresUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall nv::stereo::HL2Stereo<nv::stereo::D3D9Type>::RequiresUpdate(
        nv::stereo::HL2Stereo<nv::stereo::D3D9Type> *this,
        bool deviceLost)
{
  bool v3; // bl
  bool mActive; // al
  char v5; // al
  float v6; // xmm0_4
  void *mStereoHandle; // [esp-8h] [ebp-20h]
  float conv; // [esp+8h] [ebp-10h] BYREF
  float sep; // [esp+Ch] [ebp-Ch] BYREF
  float eyeSep; // [esp+10h] [ebp-8h] BYREF
  unsigned __int8 pIsStereoOn; // [esp+17h] [ebp-1h] BYREF

  mStereoHandle = this->mStereoHandle;
  pIsStereoOn = 0;
  if ( NvAPI_Stereo_IsActivated(stereoHandle: mStereoHandle, &pIsStereoOn) != NVAPI_OK )
  {
    v3 = false;
    goto LABEL_3;
  }
  v3 = pIsStereoOn != 0;
  if ( pIsStereoOn == 0 )
  {
LABEL_3:
    mActive = this->mActive;
    conv = 0.0;
    sep = 0.0;
    eyeSep = 0.0;
    if ( mActive )
      goto LABEL_15;
    goto LABEL_4;
  }
  if ( NvAPI_Stereo_GetEyeSeparation(hStereoHandle: this->mStereoHandle, pSeparation: &eyeSep) != NVAPI_OK
    || NvAPI_Stereo_GetSeparation(stereoHandle: this->mStereoHandle, pSeparationPercentage: &sep) != NVAPI_OK
    || NvAPI_Stereo_GetConvergence(stereoHandle: this->mStereoHandle, pConvergence: &conv) != NVAPI_OK )
  {
    return 0;
  }
  if ( eyeSep == this->mEyeSeparation && sep == this->mSeparation && conv == this->mConvergence && v3 == this->mActive )
  {
LABEL_4:
    if ( deviceLost || !this->mDeviceLost )
    {
      v5 = 0;
      goto LABEL_16;
    }
  }
LABEL_15:
  v5 = 1;
LABEL_16:
  this->mDeviceLost = deviceLost;
  if ( v5 != 0 )
  {
    _Msg(a1: "*** NV_STEREO - UpdateRequired == true\n");
    this->mEyeSeparation = eyeSep;
    this->mSeparation = sep;
    v6 = conv;
    this->mActive = v3;
    this->mConvergence = v6;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002F30
// Name: public: void nv::stereo::HL2Stereo<struct nv::stereo::D3D9Type>::UpdateStereoTexture(struct IDirect3DDevice9 __near *,struct IDirect3DTexture9 __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall nv::stereo::HL2Stereo<nv::stereo::D3D9Type>::UpdateStereoTexture(
        nv::stereo::HL2Stereo<nv::stereo::D3D9Type> *this,
        IDirect3DDevice9 *dev,
        IDirect3DSurface9 *tex,
        bool deviceLost)
{
  IDirect3DSurface9 *StagingResource; // eax
  IDirect3DSurface9 *v6; // esi

  if ( !this->mInitialized )
  {
    NvAPI_Stereo_CreateHandleFromIUnknown(pDevice: dev, pStereoHandle: &this->mStereoHandle);
    this->mInitialized = true;
  }
  if ( nv::stereo::HL2Stereo<nv::stereo::D3D9Type>::RequiresUpdate(this, deviceLost) != 0 )
  {
    DevWarning(
      a1: "UpdateStereoTexture: EyeSep: %.2f, Sep: %.2f, Conv: %.2f\n",
      this->mEyeSeparation,
      this->mSeparation,
      this->mConvergence);
    StagingResource = nv::stereo::D3D9Type::CreateStagingResource(
                        pDevice: dev,
                        eyeSep: this->mEyeSeparation,
                        sep: this->mSeparation,
                        conv: this->mConvergence);
    v6 = StagingResource;
    if ( StagingResource != nullptr )
    {
      nv::stereo::D3D9Type::UpdateTextureFromStaging(pDevice: dev, tex, staging: StagingResource);
      v6->Release(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002FF0
// Name: public: void FixedWorkQueue<class PushBuffer __near *,500>::AddWorkUnit(class PushBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FixedWorkQueue<PushBuffer *,500>::AddWorkUnit(FixedWorkQueue<PushBuffer *,500> *this, PushBuffer *unit)
{
  while ( this->n_added - this->n_removed >= 500 )
    Sleep(dwMilliseconds: 0);
  this->Data[this->write_index] = unit;
  ++this->n_added;
  this->write_index = (this->write_index + 1) % 500;
}

//------------------------------------------------------------------------------
// Address: 0x10003060
// Name: private: void D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(D3DDeviceWrapper *this)
{
  PushBuffer *m_pCurPushBuffer; // ecx
  unsigned int *m_pOutputPtr; // eax
  PushBuffer *FreePushBuffer; // eax

  m_pCurPushBuffer = this->m_pCurPushBuffer;
  if ( m_pCurPushBuffer != nullptr )
  {
    m_pOutputPtr = this->m_pOutputPtr;
    if ( m_pOutputPtr == m_pCurPushBuffer->m_BufferData )
      return;
    *m_pOutputPtr = 0;
    this->m_pCurPushBuffer->m_State = PUSHBUFFER_SUBMITTED;
    FixedWorkQueue<PushBuffer *,500>::AddWorkUnit(this: &PBQueue, unit: this->m_pCurPushBuffer);
  }
  FreePushBuffer = D3DDeviceWrapper::FindFreePushBuffer(this, newstate: PUSHBUFFER_BEING_FILLED);
  this->m_pCurPushBuffer = FreePushBuffer;
  this->m_pOutputPtr = FreePushBuffer->m_BufferData;
  this->m_PushBufferFreeSlots = 4095;
}

//------------------------------------------------------------------------------
// Address: 0x100030B0
// Name: private: void D3DDeviceWrapper::SubmitIfNotBusy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::SubmitIfNotBusy(D3DDeviceWrapper *this)
{
  PushBuffer *m_pCurPushBuffer; // ecx
  unsigned int *m_pOutputPtr; // eax
  PushBuffer *FreePushBuffer; // eax

  if ( PBQueue.n_added == PBQueue.n_removed )
  {
    m_pCurPushBuffer = this->m_pCurPushBuffer;
    if ( m_pCurPushBuffer != nullptr )
    {
      m_pOutputPtr = this->m_pOutputPtr;
      if ( m_pOutputPtr == m_pCurPushBuffer->m_BufferData )
        return;
      *m_pOutputPtr = 0;
      this->m_pCurPushBuffer->m_State = PUSHBUFFER_SUBMITTED;
      FixedWorkQueue<PushBuffer *,500>::AddWorkUnit(this: &PBQueue, unit: this->m_pCurPushBuffer);
    }
    FreePushBuffer = D3DDeviceWrapper::FindFreePushBuffer(this, newstate: PUSHBUFFER_BEING_FILLED);
    this->m_pCurPushBuffer = FreePushBuffer;
    this->m_pOutputPtr = FreePushBuffer->m_BufferData;
    this->m_PushBufferFreeSlots = 4095;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003110
// Name: public: void D3DDeviceWrapper::UpdateStereoTexture(struct IDirect3DTexture9 __near *,bool,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::UpdateStereoTexture(
        D3DDeviceWrapper *this,
        IDirect3DSurface9 *pTex,
        bool devLost,
        bool *pStereoActiveThisFrame)
{
  nv::stereo::HL2Stereo<nv::stereo::D3D9Type> *m_pStereoTexUpdater; // eax
  bool *v6; // edi
  bool v7; // al
  void *mStereoHandle; // [esp-Ch] [ebp-10h]

  m_pStereoTexUpdater = this->m_pStereoTexUpdater;
  if ( m_pStereoTexUpdater != nullptr )
  {
    v6 = pStereoActiveThisFrame;
    if ( pStereoActiveThisFrame != nullptr )
    {
      mStereoHandle = m_pStereoTexUpdater->mStereoHandle;
      HIBYTE(pStereoActiveThisFrame) = 0;
      v7 = NvAPI_Stereo_IsActivated(
             stereoHandle: mStereoHandle,
             pIsStereoOn: (unsigned __int8 *)&pStereoActiveThisFrame + 3) == NVAPI_OK
        && HIBYTE(pStereoActiveThisFrame) != 0;
      *v6 = v7;
    }
    nv::stereo::HL2Stereo<nv::stereo::D3D9Type>::UpdateStereoTexture(
      this: this->m_pStereoTexUpdater,
      dev: this->m_pD3DDevice,
      tex: pTex,
      deviceLost: devLost);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003170
// Name: private: void D3DDeviceWrapper::Synchronize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::Synchronize(D3DDeviceWrapper *this)
{
  PushBuffer *m_pCurPushBuffer; // ecx
  unsigned int *m_pOutputPtr; // eax
  PushBuffer *FreePushBuffer; // eax

  if ( this->m_pASyncThreadHandle != nullptr )
  {
    m_pCurPushBuffer = this->m_pCurPushBuffer;
    if ( m_pCurPushBuffer != nullptr )
    {
      m_pOutputPtr = this->m_pOutputPtr;
      if ( m_pOutputPtr == m_pCurPushBuffer->m_BufferData )
        goto LABEL_6;
      *m_pOutputPtr = 0;
      this->m_pCurPushBuffer->m_State = PUSHBUFFER_SUBMITTED;
      FixedWorkQueue<PushBuffer *,500>::AddWorkUnit(this: &PBQueue, unit: this->m_pCurPushBuffer);
    }
    FreePushBuffer = D3DDeviceWrapper::FindFreePushBuffer(this, newstate: PUSHBUFFER_BEING_FILLED);
    this->m_pCurPushBuffer = FreePushBuffer;
    this->m_pOutputPtr = FreePushBuffer->m_BufferData;
    this->m_PushBufferFreeSlots = 4095;
LABEL_6:
    while ( PBQueue.n_added != PBQueue.n_removed )
      ;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100031E0
// Name: private: void D3DDeviceWrapper::AsynchronousLock(struct IDirect3DIndexBuffer9 __near *,unsigned int,unsigned int,void __near * __near *,unsigned long,struct LockedBufferContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::AsynchronousLock(
        D3DDeviceWrapper *this,
        IDirect3DIndexBuffer9 *ib,
        unsigned int offset,
        unsigned int size,
        void **ptr,
        unsigned int flags,
        LockedBufferContext *lb)
{
  PushBuffer *FreePushBuffer; // eax
  void *v9; // eax
  PushBuffer *m_pCurPushBuffer; // ecx
  unsigned int *m_pOutputPtr; // eax
  PushBuffer *v12; // eax
  unsigned int *v13; // ecx

  if ( size > 0x4000 )
  {
    lb->m_pPushBuffer = nullptr;
    v9 = operator new(nSize: size);
    lb->m_pMallocedMemory = v9;
    *ptr = v9;
  }
  else
  {
    FreePushBuffer = D3DDeviceWrapper::FindFreePushBuffer(this, newstate: PUSHBUFFER_BEING_USED_FOR_LOCKEDDATA);
    lb->m_pPushBuffer = FreePushBuffer;
    *ptr = FreePushBuffer->m_BufferData;
    lb->m_pMallocedMemory = nullptr;
  }
  if ( this->m_PushBufferFreeSlots < 5 )
  {
    m_pCurPushBuffer = this->m_pCurPushBuffer;
    if ( m_pCurPushBuffer == nullptr )
    {
LABEL_8:
      v12 = D3DDeviceWrapper::FindFreePushBuffer(this, newstate: PUSHBUFFER_BEING_FILLED);
      this->m_pCurPushBuffer = v12;
      this->m_pOutputPtr = v12->m_BufferData;
      this->m_PushBufferFreeSlots = 4095;
      goto LABEL_9;
    }
    m_pOutputPtr = this->m_pOutputPtr;
    if ( m_pOutputPtr != m_pCurPushBuffer->m_BufferData )
    {
      *m_pOutputPtr = 0;
      this->m_pCurPushBuffer->m_State = PUSHBUFFER_SUBMITTED;
      FixedWorkQueue<PushBuffer *,500>::AddWorkUnit(this: &PBQueue, unit: this->m_pCurPushBuffer);
      goto LABEL_8;
    }
  }
LABEL_9:
  v13 = this->m_pOutputPtr;
  this->m_PushBufferFreeSlots -= 5;
  *v13 = 30;
  *++this->m_pOutputPtr = (unsigned int)ib;
  *++this->m_pOutputPtr = offset;
  *++this->m_pOutputPtr = size;
  *++this->m_pOutputPtr = flags;
  ++this->m_pOutputPtr;
}

//------------------------------------------------------------------------------
// Address: 0x100032C0
// Name: private: void D3DDeviceWrapper::AsynchronousLock(struct IDirect3DVertexBuffer9 __near *,unsigned int,unsigned int,void __near * __near *,unsigned long,struct LockedBufferContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::AsynchronousLock(
        D3DDeviceWrapper *this,
        IDirect3DVertexBuffer9 *vb,
        unsigned int offset,
        unsigned int size,
        void **ptr,
        unsigned int flags,
        LockedBufferContext *lb)
{
  PushBuffer *FreePushBuffer; // eax
  void *v9; // eax
  PushBuffer *m_pCurPushBuffer; // ecx
  unsigned int *m_pOutputPtr; // eax
  PushBuffer *v12; // eax
  unsigned int *v13; // ecx

  if ( size > 0x4000 )
  {
    lb->m_pPushBuffer = nullptr;
    v9 = operator new(nSize: size);
    lb->m_pMallocedMemory = v9;
    *ptr = v9;
  }
  else
  {
    FreePushBuffer = D3DDeviceWrapper::FindFreePushBuffer(this, newstate: PUSHBUFFER_BEING_USED_FOR_LOCKEDDATA);
    lb->m_pPushBuffer = FreePushBuffer;
    *ptr = FreePushBuffer->m_BufferData;
    lb->m_pMallocedMemory = nullptr;
  }
  if ( this->m_PushBufferFreeSlots < 5 )
  {
    m_pCurPushBuffer = this->m_pCurPushBuffer;
    if ( m_pCurPushBuffer == nullptr )
    {
LABEL_8:
      v12 = D3DDeviceWrapper::FindFreePushBuffer(this, newstate: PUSHBUFFER_BEING_FILLED);
      this->m_pCurPushBuffer = v12;
      this->m_pOutputPtr = v12->m_BufferData;
      this->m_PushBufferFreeSlots = 4095;
      goto LABEL_9;
    }
    m_pOutputPtr = this->m_pOutputPtr;
    if ( m_pOutputPtr != m_pCurPushBuffer->m_BufferData )
    {
      *m_pOutputPtr = 0;
      this->m_pCurPushBuffer->m_State = PUSHBUFFER_SUBMITTED;
      FixedWorkQueue<PushBuffer *,500>::AddWorkUnit(this: &PBQueue, unit: this->m_pCurPushBuffer);
      goto LABEL_8;
    }
  }
LABEL_9:
  v13 = this->m_pOutputPtr;
  this->m_PushBufferFreeSlots -= 5;
  *v13 = 28;
  *++this->m_pOutputPtr = (unsigned int)vb;
  *++this->m_pOutputPtr = offset;
  *++this->m_pOutputPtr = size;
  *++this->m_pOutputPtr = flags;
  ++this->m_pOutputPtr;
}

//------------------------------------------------------------------------------
// Address: 0x100033A0
// Name: __CreateCHardwareConfigIMaterialSystemHardwareConfig_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHardwareConfig *__cdecl _CreateCHardwareConfigIMaterialSystemHardwareConfig_interface()
{
  return &s_HardwareConfig;
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10002CE0
// Name: private: class PushBuffer __near * D3DDeviceWrapper::FindFreePushBuffer(enum PushBufferState)
// Source: json
//------------------------------------------------------------------------------
PushBuffer *__thiscall D3DDeviceWrapper::FindFreePushBuffer(D3DDeviceWrapper *this, volatile PushBufferState newstate)
{
  int v3; // eax

LABEL_1:
  v3 = 0;
  while ( PushBuffers[v3]->m_State != PUSHBUFFER_AVAILABLE )
  {
    if ( ++v3 >= 500 )
    {
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this);
      Sleep(dwMilliseconds: 0);
      goto LABEL_1;
    }
  }
  PushBuffers[v3]->m_State = newstate;
  return (PushBuffer *)PushBuffers[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10002D30
// Name: public: void FixedWorkQueue<class PushBuffer __near *,500>::AddWorkUnit(class PushBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FixedWorkQueue<PushBuffer *,500>::AddWorkUnit(FixedWorkQueue<PushBuffer *,500> *this, PushBuffer *unit)
{
  while ( this->n_added - this->n_removed >= 500 )
    Sleep(dwMilliseconds: 0);
  this->Data[this->write_index] = unit;
  ++this->n_added;
  this->write_index = (this->write_index + 1) % 500;
}

//------------------------------------------------------------------------------
// Address: 0x10002DA0
// Name: private: void D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(D3DDeviceWrapper *this)
{
  PushBuffer *m_pCurPushBuffer; // ecx
  unsigned int *m_pOutputPtr; // eax
  PushBuffer *FreePushBuffer; // eax

  m_pCurPushBuffer = this->m_pCurPushBuffer;
  if ( m_pCurPushBuffer != nullptr )
  {
    m_pOutputPtr = this->m_pOutputPtr;
    if ( m_pOutputPtr == m_pCurPushBuffer->m_BufferData )
      return;
    *m_pOutputPtr = 0;
    this->m_pCurPushBuffer->m_State = PUSHBUFFER_SUBMITTED;
    FixedWorkQueue<PushBuffer *,500>::AddWorkUnit(this: &PBQueue, unit: this->m_pCurPushBuffer);
  }
  FreePushBuffer = D3DDeviceWrapper::FindFreePushBuffer(this, newstate: PUSHBUFFER_BEING_FILLED);
  this->m_pCurPushBuffer = FreePushBuffer;
  this->m_pOutputPtr = FreePushBuffer->m_BufferData;
  this->m_PushBufferFreeSlots = 4095;
}

//------------------------------------------------------------------------------
// Address: 0x10002DF0
// Name: private: void D3DDeviceWrapper::SubmitIfNotBusy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::SubmitIfNotBusy(D3DDeviceWrapper *this)
{
  if ( PBQueue.n_added == PBQueue.n_removed )
    D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this);
}

//------------------------------------------------------------------------------
// Address: 0x10002E10
// Name: private: void D3DDeviceWrapper::Synchronize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::Synchronize(D3DDeviceWrapper *this)
{
  if ( this->m_pASyncThreadHandle != nullptr )
  {
    D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this);
    while ( PBQueue.n_added != PBQueue.n_removed )
      ;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E30
// Name: private: void D3DDeviceWrapper::AsynchronousLock(struct IDirect3DIndexBuffer9 __near *,unsigned int,unsigned int,void __near * __near *,unsigned long,struct LockedBufferContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::AsynchronousLock(
        D3DDeviceWrapper *this,
        IDirect3DIndexBuffer9 *ib,
        unsigned int offset,
        unsigned int size,
        void **ptr,
        unsigned int flags,
        LockedBufferContext *lb)
{
  PushBuffer *FreePushBuffer; // eax
  void *v9; // eax
  unsigned int *m_pOutputPtr; // edx

  if ( size > 0x4000 )
  {
    lb->m_pPushBuffer = nullptr;
    v9 = operator new(nSize: size);
    lb->m_pMallocedMemory = v9;
    *ptr = v9;
  }
  else
  {
    FreePushBuffer = D3DDeviceWrapper::FindFreePushBuffer(this, newstate: PUSHBUFFER_BEING_USED_FOR_LOCKEDDATA);
    lb->m_pPushBuffer = FreePushBuffer;
    *ptr = FreePushBuffer->m_BufferData;
    lb->m_pMallocedMemory = nullptr;
  }
  if ( this->m_PushBufferFreeSlots < 5 )
    D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this);
  m_pOutputPtr = this->m_pOutputPtr;
  this->m_PushBufferFreeSlots -= 5;
  *m_pOutputPtr = 30;
  *++this->m_pOutputPtr = (unsigned int)ib;
  *++this->m_pOutputPtr = offset;
  *++this->m_pOutputPtr = size;
  *++this->m_pOutputPtr = flags;
  ++this->m_pOutputPtr;
}

//------------------------------------------------------------------------------
// Address: 0x10002ED0
// Name: private: void D3DDeviceWrapper::AsynchronousLock(struct IDirect3DVertexBuffer9 __near *,unsigned int,unsigned int,void __near * __near *,unsigned long,struct LockedBufferContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DDeviceWrapper::AsynchronousLock(
        D3DDeviceWrapper *this,
        IDirect3DVertexBuffer9 *vb,
        unsigned int offset,
        unsigned int size,
        void **ptr,
        unsigned int flags,
        LockedBufferContext *lb)
{
  PushBuffer *FreePushBuffer; // eax
  void *v9; // eax
  unsigned int *m_pOutputPtr; // edx

  if ( size > 0x4000 )
  {
    lb->m_pPushBuffer = nullptr;
    v9 = operator new(nSize: size);
    lb->m_pMallocedMemory = v9;
    *ptr = v9;
  }
  else
  {
    FreePushBuffer = D3DDeviceWrapper::FindFreePushBuffer(this, newstate: PUSHBUFFER_BEING_USED_FOR_LOCKEDDATA);
    lb->m_pPushBuffer = FreePushBuffer;
    *ptr = FreePushBuffer->m_BufferData;
    lb->m_pMallocedMemory = nullptr;
  }
  if ( this->m_PushBufferFreeSlots < 5 )
    D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this);
  m_pOutputPtr = this->m_pOutputPtr;
  this->m_PushBufferFreeSlots -= 5;
  *m_pOutputPtr = 28;
  *++this->m_pOutputPtr = (unsigned int)vb;
  *++this->m_pOutputPtr = offset;
  *++this->m_pOutputPtr = size;
  *++this->m_pOutputPtr = flags;
  ++this->m_pOutputPtr;
}

//------------------------------------------------------------------------------
// Address: 0x10002F70
// Name: __CreateCHardwareConfigIMaterialSystemHardwareConfig_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHardwareConfig *__cdecl _CreateCHardwareConfigIMaterialSystemHardwareConfig_interface()
{
  return &s_HardwareConfig;
}

} // namespace shaderapidx10
