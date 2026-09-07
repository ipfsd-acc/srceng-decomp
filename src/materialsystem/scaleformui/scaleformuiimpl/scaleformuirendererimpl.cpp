// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuirendererimpl.cpp
// Functions: 8
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuirendererimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10013AB0
// Name: public: virtual void DeviceCallbacks::ScreenSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DeviceCallbacks::ScreenSizeChanged(DeviceCallbacks *this, int width, int height)
{
  ScaleformUIImpl::SetScreenSize(this: this->m_pScaleform, x: width, y: height);
}

//------------------------------------------------------------------------------
// Address: 0x10013AC0
// Name: protected: void ScaleformUIImpl::InitRendererImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::InitRendererImpl(ScaleformUIImpl *this)
{
  DeviceCallbacks *v2; // eax

  if ( this->m_pShaderDeviceMgr != nullptr )
  {
    v2 = (DeviceCallbacks *)MemAlloc_Alloc(nSize: 0xCu);
    if ( v2 != nullptr )
    {
      v2->__vftable = (DeviceCallbacks_vtbl *)&DeviceCallbacks::`vftable';
      v2->m_iRefCount = 1;
      v2->m_pScaleform = nullptr;
    }
    else
    {
      v2 = nullptr;
    }
    this->m_pDeviceCallbacks = v2;
    v2->m_pScaleform = this;
    this->m_pShaderDeviceMgr->AddDeviceDependentObject(this: this->m_pShaderDeviceMgr, a2: this->m_pDeviceCallbacks);
  }
  this->m_iScreenWidth = 1024;
  this->m_iScreenHeight = 768;
}

//------------------------------------------------------------------------------
// Address: 0x10013B20
// Name: public: void ScaleformUIImpl::FinishInitializingRenderer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::FinishInitializingRenderer(ScaleformUIImpl *this)
{
  GFxRenderConfig *v2; // edi
  IShaderAPI *pObject; // ecx
  void *v4; // [esp+8h] [ebp-14h]
  int v5; // [esp+Ch] [ebp-10h] BYREF
  int v6; // [esp+18h] [ebp-4h]

  v5 = 2;
  v4 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 36, a3: &v5);
  v6 = 0;
  if ( v4 != nullptr )
    v2 = (GFxRenderConfig *)GFxRenderConfig::GFxRenderConfig();
  else
    v2 = nullptr;
  pObject = (IShaderAPI *)this->m_pRenderConfig.pObject;
  v6 = -1;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
  this->m_pRenderConfig.pObject = v2;
  v2->RenderFlags = 16;
  this->m_pLoader->SetState(this: this->m_pLoader, a2: State_RenderConfig, a3: this->m_pRenderConfig.pObject);
  ScaleformUIImpl::InitFonts(this, a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x10013BC0
// Name: public: void ScaleformUIImpl::SetRenderingDevice(struct IDirect3DDevice9 __near *,struct _D3DPRESENT_PARAMETERS_ __near *,struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::SetRenderingDevice(
        ScaleformUIImpl *this,
        IDirect3DDevice9 *pDevice,
        _D3DPRESENT_PARAMETERS_ *pPresentParameters,
        HWND__ *hWnd)
{
  ScaleformRenderer *Renderer; // eax
  IShaderAPI *pObject; // ecx
  GRenderer *v7; // edi
  unsigned int Width; // eax
  unsigned int Height; // [esp-4h] [ebp-24h]
  _D3DVIEWPORT9 viewport; // [esp+8h] [ebp-18h] BYREF

  if ( this->m_pRenderer.pObject == nullptr )
  {
    Renderer = ScaleformRenderer::CreateRenderer();
    pObject = (IShaderAPI *)this->m_pRenderer.pObject;
    v7 = Renderer;
    if ( pObject != nullptr )
      GRefCountImpl::Release(this: pObject);
    this->m_pRenderer.pObject = v7;
  }
  ScaleformRenderer::SetDevice(this: (ScaleformRenderer *)this->m_pRenderer.pObject, pDevice);
  if ( this->m_pRenderConfig.pObject == nullptr )
    ScaleformUIImpl::FinishInitializingRenderer(this);
  ScaleformUIImpl::InitFonts(this, a2: (int)this);
  pDevice->GetViewport(this: pDevice, a2: &viewport);
  Width = viewport.Width;
  Height = viewport.Height;
  this->m_iScreenHeight = viewport.Height;
  this->m_iScreenWidth = Width;
  ScaleformUIImpl::SetScreenSize(this, x: Width, y: Height);
}

//------------------------------------------------------------------------------
// Address: 0x10013C40
// Name: public: virtual void DeviceCallbacks::DeviceReset(void __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DeviceCallbacks::DeviceReset(
        DeviceCallbacks *this,
        IDirect3DDevice9 *pDevice,
        _D3DPRESENT_PARAMETERS_ *pPresentParameters,
        HWND__ *pHWnd)
{
  ScaleformUIImpl::SetRenderingDevice(this: this->m_pScaleform, pDevice, pPresentParameters, hWnd: pHWnd);
}

//------------------------------------------------------------------------------
// Address: 0x10013C50
// Name: protected: void ScaleformUIImpl::ShutdownRendererImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ShutdownRendererImpl(ScaleformUIImpl *this)
{
  IShaderDeviceMgr *m_pShaderDeviceMgr; // ecx
  GRenderer *pObject; // ecx
  GRenderTarget *v4; // edi

  m_pShaderDeviceMgr = this->m_pShaderDeviceMgr;
  if ( m_pShaderDeviceMgr != nullptr && this->m_pDeviceCallbacks != nullptr )
  {
    m_pShaderDeviceMgr->RemoveDeviceDependentObject(this: m_pShaderDeviceMgr, a2: this->m_pDeviceCallbacks);
    free(pMem: this->m_pDeviceCallbacks);
    this->m_pShaderDeviceMgr = nullptr;
  }
  if ( this->m_pScreenRenderTarget.pObject != nullptr )
  {
    pObject = this->m_pRenderer.pObject;
    if ( pObject != nullptr )
    {
      pObject->SetDisplayRenderTarget(this: pObject, a2: nullptr, a3: true);
      v4 = this->m_pScreenRenderTarget.pObject;
      if ( v4 != nullptr && InterlockedExchangeAdd(Addend: &v4->RefCount.Value, Value: -1) == 1 )
        ((void (__thiscall *)(GRenderTarget *, int))v4->dtr_GRenderTarget)(a1: v4, a2: 1);
      this->m_pScreenRenderTarget.pObject = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013CD0
// Name: public: void ScaleformUIImpl::NotifyRenderingDeviceLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::NotifyRenderingDeviceLost(ScaleformUIImpl *this)
{
  GRenderTarget *pObject; // edi
  IShaderAPI *v3; // ecx
  IShaderAPI *v4; // ecx

  ScaleformRenderer::DeviceLost(this: (ScaleformRenderer *)this->m_pRenderer.pObject);
  this->m_pRenderer.pObject->SetDisplayRenderTarget(this: this->m_pRenderer.pObject, a2: nullptr, a3: true);
  pObject = this->m_pScreenRenderTarget.pObject;
  if ( pObject != nullptr && InterlockedExchangeAdd(Addend: &pObject->RefCount.Value, Value: -1) == 1 )
    ((void (__thiscall *)(GRenderTarget *, int))pObject->dtr_GRenderTarget)(a1: pObject, a2: 1);
  this->m_pScreenRenderTarget.pObject = nullptr;
  v3 = (IShaderAPI *)this->m_pRenderConfig.pObject;
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  this->m_pRenderConfig.pObject = nullptr;
  v4 = (IShaderAPI *)this->m_pRenderer.pObject;
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  this->m_pRenderer.pObject = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10013D40
// Name: public: virtual void DeviceCallbacks::DeviceLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DeviceCallbacks::DeviceLost(DeviceCallbacks *this)
{
  ScaleformUIImpl::NotifyRenderingDeviceLost(this: this->m_pScaleform);
}
