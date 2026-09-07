// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/shaderdevicedx8.cpp
// Functions: 66
// ============================================================

#include "materialsystem\shaderapidx9\shaderdevicedx8.h"

//------------------------------------------------------------------------------
// Address: 0x10025410
// Name: public: virtual bool CShaderDeviceMgrDx8::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrDx8::Connect(CShaderDeviceMgrDx8 *this, void *(__cdecl *factory)(const char *, int *))
{
  IDirect3D9 *v3; // eax

  if ( CShaderDeviceMgrBase::Connect(this, factory) == 0 )
    return 0;
  v3 = Direct3DCreate9(SDKVersion: 0x20u);
  this->m_pD3D = v3;
  if ( v3 == nullptr )
  {
    _Warning(a1: "Failed to create D3D9!\n");
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025450
// Name: public: virtual void CShaderDeviceMgrDx8::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::Disconnect(CShaderDeviceMgrDx8 *this)
{
  IDirect3D9 *m_pD3D; // eax

  m_pD3D = this->m_pD3D;
  if ( m_pD3D != nullptr )
  {
    m_pD3D->Release(this: m_pD3D);
    this->m_pD3D = nullptr;
  }
  CShaderDeviceMgrBase::Disconnect(this);
}

//------------------------------------------------------------------------------
// Address: 0x10025480
// Name: public: virtual void CShaderDeviceMgrDx8::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::Shutdown(CShaderDeviceMgrDx8 *this)
{
  if ( g_pShaderAPI != nullptr )
    g_pShaderAPI->OnDeviceShutdown(this: g_pShaderAPI);
  if ( g_pShaderDevice != nullptr )
  {
    g_pShaderDevice->ShutdownDevice(this: g_pShaderDevice);
    g_pMaterialSystemHardwareConfig = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100254C0
// Name: private: void CShaderDeviceMgrDx8::ComputeDXSupportLevel(struct HardwareCaps_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::ComputeDXSupportLevel(CShaderDeviceMgrDx8 *this, HardwareCaps_t *caps)
{
  char v2; // cl

  v2 = *((_BYTE *)caps + 716);
  if ( (v2 & 8) != 0 )
  {
    caps->m_nMinDXSupportLevel = 90;
    caps->m_nMaxDXSupportLevel = 95;
  }
  else
  {
    caps->m_nMinDXSupportLevel = 90;
    if ( (v2 & 4) != 0 )
      caps->m_nMaxDXSupportLevel = 92;
    else
      caps->m_nMaxDXSupportLevel = 90;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025520
// Name: public: virtual bool CShaderDeviceMgrDx8::SetAdapter(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceMgrDx8::SetAdapter(CShaderDeviceMgrDx8 *this, unsigned int nAdapter, char nAdapterFlags)
{
  CShaderDeviceDx8 *v3; // esi
  bool result; // al

  g_pShaderDeviceDx8->m_DeviceType = ((nAdapterFlags & 4) != 0) + 1;
  g_pShaderDeviceDx8->m_DisplayAdapter = nAdapter;
  v3 = g_pShaderDeviceDx8;
  if ( v3->m_DisplayAdapter >= this->GetAdapterCount(this) )
    v3->m_DisplayAdapter = 0;
  result = g_pShaderDeviceDx8->OnAdapterSet(this: g_pShaderDeviceDx8);
  if ( result )
  {
    g_pShaderDevice = g_pShaderDeviceDx8;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025590
// Name: private: virtual void CShaderDeviceMgrDx8::GetDesktopResolution(int __near *,int __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::GetDesktopResolution(
        CShaderDeviceMgrDx8 *this,
        int *pWidth,
        int *pHeight,
        unsigned int nAdapter)
{
  HMONITOR v4; // eax
  int v5; // ecx
  tagMONITORINFO monitorInfo; // [esp+0h] [ebp-28h] BYREF

  v4 = this->m_pD3D->GetAdapterMonitor(this: this->m_pD3D, a2: nAdapter);
  memset((void *)&monitorInfo.rcMonitor, 0, 36);
  monitorInfo.cbSize = 40;
  GetMonitorInfoA(hMonitor: v4, lpmi: &monitorInfo);
  v5 = monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top;
  *pWidth = monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left;
  *pHeight = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100255F0
// Name: public: virtual int CShaderDeviceMgrDx8::GetModeCount(int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShaderDeviceMgrDx8::GetModeCount(CShaderDeviceMgrDx8 *this, unsigned int nAdapter)
{
  return this->m_pD3D->GetAdapterModeCount(this: this->m_pD3D, a2: nAdapter, a3: D3DFMT_X8R8G8B8);
}

//------------------------------------------------------------------------------
// Address: 0x10025610
// Name: public: virtual void CShaderDeviceMgrDx8::GetModeInfo(struct ShaderDisplayMode_t __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::GetModeInfo(
        CShaderDeviceMgrDx8 *this,
        ShaderDisplayMode_t *pInfo,
        unsigned int nAdapter,
        unsigned int nMode)
{
  unsigned int Height; // edx
  ImageFormat v5; // eax
  unsigned int RefreshRate; // ecx
  _D3DFORMAT Format; // [esp-4h] [ebp-18h]
  _D3DDISPLAYMODE d3dInfo; // [esp+4h] [ebp-10h] BYREF

  this->m_pD3D->EnumAdapterModes(this: this->m_pD3D, a2: nAdapter, a3: D3DFMT_X8R8G8B8, a4: nMode, a5: &d3dInfo);
  Height = d3dInfo.Height;
  Format = d3dInfo.Format;
  pInfo->m_nWidth = d3dInfo.Width;
  pInfo->m_nHeight = Height;
  v5 = ImageLoader::D3DFormatToImageFormat(format: Format);
  RefreshRate = d3dInfo.RefreshRate;
  pInfo->m_Format = v5;
  pInfo->m_nRefreshRateNumerator = RefreshRate;
  pInfo->m_nRefreshRateDenominator = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025670
// Name: public: virtual void CShaderDeviceMgrDx8::GetCurrentModeInfo(struct ShaderDisplayMode_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::GetCurrentModeInfo(
        CShaderDeviceMgrDx8 *this,
        ShaderDisplayMode_t *pInfo,
        unsigned int nAdapter)
{
  unsigned int Height; // edx
  ImageFormat v4; // eax
  unsigned int RefreshRate; // ecx
  _D3DFORMAT Format; // [esp-4h] [ebp-18h]
  _D3DDISPLAYMODE mode; // [esp+4h] [ebp-10h] BYREF

  this->m_pD3D->GetAdapterDisplayMode(this: this->m_pD3D, a2: nAdapter, a3: &mode);
  Height = mode.Height;
  Format = mode.Format;
  pInfo->m_nWidth = mode.Width;
  pInfo->m_nHeight = Height;
  v4 = ImageLoader::D3DFormatToImageFormat(format: Format);
  RefreshRate = mode.RefreshRate;
  pInfo->m_Format = v4;
  pInfo->m_nRefreshRateNumerator = RefreshRate;
  pInfo->m_nRefreshRateDenominator = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100256C0
// Name: public: bool CShaderDeviceMgrDx8::ValidateMode(int,struct ShaderDeviceInfo_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceMgrDx8::ValidateMode(
        CShaderDeviceMgrDx8 *this,
        int nAdapter,
        const ShaderDeviceInfo_t *info)
{
  bool result; // al
  void (__thiscall *GetCurrentModeInfo)(IShaderDeviceMgr *, ShaderDisplayMode_t *, int); // edx
  ShaderDisplayMode_t displayMode; // [esp+8h] [ebp-18h] BYREF

  result = nAdapter < (int)this->m_pD3D->GetAdapterCount(this: this->m_pD3D)
        && ((GetCurrentModeInfo = this->GetCurrentModeInfo,
             memset(&displayMode.m_nWidth, 0, 20),
             displayMode.m_nVersion = 1,
             GetCurrentModeInfo(this, a2: &displayMode, a3: nAdapter),
             (*((_BYTE *)info + 52) & 1) == 0)
         || info->m_DisplayMode.m_nWidth <= displayMode.m_nWidth
         && info->m_DisplayMode.m_nHeight <= displayMode.m_nHeight)
        && FindNearestSupportedBackBufferFormat(
             displayAdapter: nAdapter,
             deviceType: D3DDEVTYPE_HAL,
             displayFormat: displayMode.m_Format,
             backBufferFormat: info->m_DisplayMode.m_Format,
             bIsWindowed: *((_BYTE *)info + 52) & 1) != -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025750
// Name: public: virtual int CShaderDeviceMgrDx8::GetVidMemBytes(int)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CShaderDeviceMgrDx8::GetVidMemBytes(CShaderDeviceMgrDx8 *this, int nAdapter)
{
  return GetVidMemBytes();
}

//------------------------------------------------------------------------------
// Address: 0x10025760
// Name: public: CShaderDeviceDx8::CShaderDeviceDx8(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceDx8 *__thiscall CShaderDeviceDx8::CShaderDeviceDx8(CShaderDeviceDx8 *this)
{
  unsigned int v2; // eax
  IDirect3DQuery9 **m_pFrameSyncQueryObject; // ecx

  CShaderDeviceBase::CShaderDeviceBase(this);
  this->__vftable = (CShaderDeviceDx8_vtbl *)&CShaderDeviceDx8::`vftable';
  *(_QWORD *)&this->m_PendingVideoModeChangeConfig.m_DisplayMode.m_nVersion = 0;
  *(_QWORD *)&this->m_PendingVideoModeChangeConfig.m_DisplayMode.m_nHeight = 0;
  *(_QWORD *)&this->m_PendingVideoModeChangeConfig.m_DisplayMode.m_nRefreshRateNumerator = 0;
  this->m_PendingVideoModeChangeConfig.m_DisplayMode.m_nVersion = 1;
  memset(
    dst: (unsigned __int8 *)&this->m_PendingVideoModeChangeConfig,
    value: 0,
    count: sizeof(this->m_PendingVideoModeChangeConfig));
  this->m_PendingVideoModeChangeConfig.m_nVersion = 1;
  this->m_PendingVideoModeChangeConfig.m_DisplayMode.m_nVersion = 1;
  this->m_AspectRatioInfo.m_flFrameBufferAspectRatio = 1.3333334;
  this->m_AspectRatioInfo.m_flPhysicalAspectRatio = 1.3333334;
  *(_WORD *)&this->m_AspectRatioInfo.m_bIsWidescreen = 0;
  this->m_AspectRatioInfo.m_flFrameBuffertoPhysicalScalar = 1.0;
  this->m_AspectRatioInfo.m_flPhysicalToFrameBufferScalar = 1.0;
  this->m_AspectRatioInfo.m_bInitialized = false;
  this->m_nonInteractiveModeMutex.m_ownerID = 0;
  this->m_nonInteractiveModeMutex.m_depth = 0;
  this->m_pD3DDevice = nullptr;
  v2 = 0;
  m_pFrameSyncQueryObject = this->m_pFrameSyncQueryObject;
  do
  {
    *m_pFrameSyncQueryObject = nullptr;
    this->m_bQueryIssued[v2++] = false;
    ++m_pFrameSyncQueryObject;
  }
  while ( v2 < 2 );
  *((_BYTE *)this + 172) &= 0xC0u;
  this->m_DeviceSupportsCreateQuery = -1;
  this->m_NonInteractiveRefresh.m_Mode = MATERIAL_NON_INTERACTIVE_MODE_NONE;
  this->m_pFrameSyncTexture = nullptr;
  this->m_DeviceState = DEVICE_STATE_OK;
  this->m_iStencilBufferBits = 0;
  this->m_NonInteractiveRefresh.m_pVertexShader = nullptr;
  this->m_NonInteractiveRefresh.m_pPixelShader = nullptr;
  this->m_NonInteractiveRefresh.m_pPixelShaderStartup = nullptr;
  this->m_NonInteractiveRefresh.m_pPixelShaderStartupPass2 = nullptr;
  this->m_NonInteractiveRefresh.m_pVertexDecl = nullptr;
  this->m_NonInteractiveRefresh.m_nPacifierFrame = 0;
  this->m_numReleaseResourcesRefCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10025870
// Name: public: virtual CShaderDeviceDx8::~CShaderDeviceDx8(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::~CShaderDeviceDx8(CShaderDeviceDx8 *this)
{
  this->__vftable = (CShaderDeviceDx8_vtbl *)&CShaderDeviceDx8::`vftable';
  CShaderDeviceBase::~CShaderDeviceBase(this);
}

//------------------------------------------------------------------------------
// Address: 0x10025880
// Name: protected: enum _D3DMULTISAMPLE_TYPE CShaderDeviceDx8::ComputeMultisampleType(int)
// Source: json
//------------------------------------------------------------------------------
_D3DMULTISAMPLE_TYPE __thiscall CShaderDeviceDx8::ComputeMultisampleType(CShaderDeviceDx8 *this, int nSampleCount)
{
  _D3DMULTISAMPLE_TYPE result; // eax

  switch ( nSampleCount )
  {
    case 2:
      result = D3DMULTISAMPLE_2_SAMPLES;
      break;
    case 3:
      result = D3DMULTISAMPLE_3_SAMPLES;
      break;
    case 4:
      result = D3DMULTISAMPLE_4_SAMPLES;
      break;
    case 5:
      result = D3DMULTISAMPLE_5_SAMPLES;
      break;
    case 6:
      result = D3DMULTISAMPLE_6_SAMPLES;
      break;
    case 7:
      result = D3DMULTISAMPLE_7_SAMPLES;
      break;
    case 8:
      result = D3DMULTISAMPLE_8_SAMPLES;
      break;
    case 9:
      result = D3DMULTISAMPLE_9_SAMPLES;
      break;
    case 10:
      result = D3DMULTISAMPLE_10_SAMPLES;
      break;
    case 11:
      result = D3DMULTISAMPLE_11_SAMPLES;
      break;
    case 12:
      result = D3DMULTISAMPLE_12_SAMPLES;
      break;
    case 13:
      result = D3DMULTISAMPLE_13_SAMPLES;
      break;
    case 14:
      result = D3DMULTISAMPLE_14_SAMPLES;
      break;
    case 15:
      result = D3DMULTISAMPLE_15_SAMPLES;
      break;
    case 16:
      result = D3DMULTISAMPLE_16_SAMPLES;
      break;
    default:
      result = D3DMULTISAMPLE_NONE;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025970
// Name: protected: void CShaderDeviceDx8::CalcBackBufferDimensions(struct ShaderDisplayMode_t const __near &,struct ShaderDeviceInfo_t const __near &,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::CalcBackBufferDimensions(
        CShaderDeviceDx8 *this,
        const ShaderDisplayMode_t *mode,
        const ShaderDeviceInfo_t *info,
        int *pBackBufferWidth,
        int *pBackBufferHeight)
{
  char v5; // cl
  int m_nWidth; // ecx
  char v7; // dl
  int m_nWindowedSizeLimitWidth; // ecx

  v5 = *((_BYTE *)info + 52);
  if ( (v5 & 1) == 0 )
  {
    m_nWidth = info->m_DisplayMode.m_nWidth;
    if ( m_nWidth != 0 && info->m_DisplayMode.m_nHeight != 0 )
    {
      v7 = 0;
    }
    else
    {
      m_nWidth = mode->m_nWidth;
      v7 = 1;
    }
    *pBackBufferWidth = m_nWidth;
    if ( v7 != 0 )
    {
      *pBackBufferHeight = mode->m_nHeight;
      return;
    }
    goto LABEL_15;
  }
  if ( (v5 & 2) == 0 )
  {
    *pBackBufferWidth = info->m_DisplayMode.m_nWidth;
LABEL_15:
    *pBackBufferHeight = info->m_DisplayMode.m_nHeight;
    return;
  }
  if ( (v5 & 8) != 0
    && ((m_nWindowedSizeLimitWidth = info->m_nWindowedSizeLimitWidth) < mode->m_nWidth
     || info->m_nWindowedSizeLimitHeight < mode->m_nHeight) )
  {
    *pBackBufferWidth = m_nWindowedSizeLimitWidth;
    *pBackBufferHeight = info->m_nWindowedSizeLimitHeight;
  }
  else
  {
    *pBackBufferWidth = mode->m_nWidth;
    *pBackBufferHeight = mode->m_nHeight;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025A10
// Name: protected: void CShaderDeviceDx8::SetPresentParameters(void __near *,int,struct ShaderDeviceInfo_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::SetPresentParameters(
        CShaderDeviceDx8 *this,
        HWND__ *hWnd,
        int nAdapter,
        const ShaderDeviceInfo_t *info,
        ImageFormat bSetSymbolsOnly)
{
  int v7; // eax
  float v8; // xmm0_4
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  ImageFormat NearestSupportedBackBufferFormat; // ecx
  char v17; // al
  bool v18; // cc
  _D3DFORMAT NearestSupportedDepthFormat; // eax
  __int32 v20; // eax
  __int32 v21; // eax
  unsigned int m_nWidth; // eax
  char v23; // cl
  unsigned int m_nHeight; // eax
  int v25; // ecx
  int v26; // eax
  bool v27; // zf
  int m_nRefreshRateDenominator; // ecx
  char v29; // al
  unsigned int v30; // edx
  signed int m_nWindowedSizeLimitWidth; // eax
  _D3DMULTISAMPLE_TYPE v32; // edi
  CShaderDeviceMgrBase::AdapterInfo_t *HardwareCaps; // eax
  int v34; // eax
  unsigned int v35; // ecx
  ImageFormat v36; // [esp-4h] [ebp-30h]
  ShaderDisplayMode_t mode; // [esp+Ch] [ebp-20h] BYREF
  int backBufferHeight; // [esp+24h] [ebp-8h] BYREF
  int backBufferWidth; // [esp+28h] [ebp-4h] BYREF
  BOOL infoa; // [esp+3Ch] [ebp+10h]
  BOOL infob; // [esp+3Ch] [ebp+10h]
  BOOL infoc; // [esp+3Ch] [ebp+10h]

  memset(&mode.m_nWidth, 0, 20);
  mode.m_nVersion = 1;
  g_pShaderDeviceMgr->GetCurrentModeInfo(this: g_pShaderDeviceMgr, a2: &mode, a3: nAdapter);
  backBufferWidth = 0;
  backBufferHeight = 0;
  CShaderDeviceDx8::CalcBackBufferDimensions(
    this,
    &mode,
    info,
    pBackBufferWidth: &backBufferWidth,
    pBackBufferHeight: &backBufferHeight);
  v7 = backBufferHeight;
  v8 = (float)backBufferWidth / (float)backBufferHeight;
  this->m_AspectRatioInfo.m_flFrameBufferAspectRatio = v8;
  this->m_AspectRatioInfo.m_flPhysicalAspectRatio = v8;
  this->m_AspectRatioInfo.m_flFrameBuffertoPhysicalScalar = 1.0;
  this->m_AspectRatioInfo.m_flPhysicalToFrameBufferScalar = 1.0;
  infoa = v8 >= 1.5999;
  this->m_AspectRatioInfo.m_bIsWidescreen = infoa;
  this->m_AspectRatioInfo.m_bIsHidef = v7 >= 720;
  this->m_AspectRatioInfo.m_bInitialized = true;
  v9 = _KeyValuesSystem();
  (*(void (__thiscall **)(int, const char *, BOOL))(*(_DWORD *)v9 + 28))(a1: v9, a2: "WIN32WIDE", a3: infoa);
  infob = this->m_AspectRatioInfo.m_bIsHidef;
  v10 = _KeyValuesSystem();
  (*(void (__thiscall **)(int, const char *, BOOL))(*(_DWORD *)v10 + 28))(a1: v10, a2: "WIN32HIDEF", a3: infob);
  infoc = !this->m_AspectRatioInfo.m_bIsHidef;
  v11 = _KeyValuesSystem();
  (*(void (__thiscall **)(int, const char *, BOOL))(*(_DWORD *)v11 + 28))(a1: v11, a2: "WIN32LODEF", a3: infoc);
  v12 = _KeyValuesSystem();
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v12 + 28))(a1: v12, a2: "GAMECONSOLEWIDE", a3: 0);
  v13 = _KeyValuesSystem();
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v13 + 28))(a1: v13, a2: "GAMECONSOLEHIDEF", a3: 0);
  v14 = _KeyValuesSystem();
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v14 + 28))(a1: v14, a2: "GAMECONSOLELODEF", a3: 0);
  v15 = _KeyValuesSystem();
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v15 + 28))(a1: v15, a2: "ANAMORPHIC", a3: 0);
  if ( (_BYTE)bSetSymbolsOnly == IMAGE_FORMAT_RGBA8888 )
  {
    memset(dst: (unsigned __int8 *)&this->m_PresentParameters, value: 0, count: sizeof(this->m_PresentParameters));
    this->m_PresentParameters.Windowed = *((_BYTE *)info + 52) & 1;
    this->m_PresentParameters.SwapEffect = (*((unsigned __int8 *)info + 52) | 0x40u) >> 6;
    this->m_PresentParameters.EnableAutoDepthStencil = 1;
    NearestSupportedBackBufferFormat = FindNearestSupportedBackBufferFormat(
                                         displayAdapter: nAdapter,
                                         deviceType: D3DDEVTYPE_HAL,
                                         displayFormat: this->m_AdapterFormat,
                                         backBufferFormat: info->m_DisplayMode.m_Format,
                                         bIsWindowed: *((_BYTE *)info + 52) & 1);
    *((_BYTE *)this + 172) ^= (*((_BYTE *)this + 172) ^ (4 * *((_BYTE *)info + 52))) & 0x10;
    v17 = *((_BYTE *)this + 172);
    v18 = info->m_nDXLevel < 80;
    bSetSymbolsOnly = NearestSupportedBackBufferFormat;
    if ( !v18 )
      *((_BYTE *)this + 172) = v17 | 0x10;
    NearestSupportedDepthFormat = FindNearestSupportedDepthFormat(
                                    nAdapter,
                                    displayFormat: this->m_AdapterFormat,
                                    renderTargetFormat: NearestSupportedBackBufferFormat,
                                    depthFormat: (_D3DFORMAT)(2 * ((*((_BYTE *)this + 172) & 0x10) == 0) + 75));
    this->m_PresentParameters.AutoDepthStencilFormat = NearestSupportedDepthFormat;
    v20 = NearestSupportedDepthFormat - 73;
    this->m_PresentParameters.hDeviceWindow = hWnd;
    if ( v20 != 0 )
    {
      v21 = v20 - 2;
      if ( v21 != 0 )
      {
        if ( v21 == 4 )
        {
          this->m_iStencilBufferBits = 4;
        }
        else
        {
          *((_BYTE *)this + 172) &= ~0x10u;
          this->m_iStencilBufferBits = 0;
        }
      }
      else
      {
        this->m_iStencilBufferBits = 8;
      }
    }
    else
    {
      this->m_iStencilBufferBits = 1;
    }
    if ( (*((_BYTE *)info + 52) & 1) == 0 )
    {
      m_nWidth = info->m_DisplayMode.m_nWidth;
      if ( m_nWidth != 0 && info->m_DisplayMode.m_nHeight != 0 )
      {
        v23 = 0;
      }
      else
      {
        m_nWidth = mode.m_nWidth;
        v23 = 1;
      }
      this->m_PresentParameters.BackBufferWidth = m_nWidth;
      m_nHeight = mode.m_nHeight;
      if ( v23 == 0 )
        m_nHeight = info->m_DisplayMode.m_nHeight;
      v36 = bSetSymbolsOnly;
      this->m_PresentParameters.BackBufferHeight = m_nHeight;
      this->m_PresentParameters.BackBufferFormat = ImageLoader::ImageFormatToD3DFormat(format: v36);
      if ( (*((_BYTE *)info + 52) & 0x10) == 0
        || (v26 = _CommandLine(a1: v25),
            (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v26 + 40))(a1: v26, a2: "-forcenovsync") != 0) )
      {
        this->m_PresentParameters.BackBufferCount = 1;
        this->m_PresentParameters.PresentationInterval = 0x80000000;
      }
      else
      {
        if ( (_S1_3 & 1) == 0 )
        {
          _S1_3 |= 1u;
          ConVarRef::ConVarRef(this: &mat_triplebuffered, pName: "mat_triplebuffered");
        }
        v27 = mat_triplebuffered.m_pConVarState->m_Value.m_nValue == 0;
        this->m_PresentParameters.PresentationInterval = 1;
        this->m_PresentParameters.BackBufferCount = !v27 + 1;
      }
      m_nRefreshRateDenominator = info->m_DisplayMode.m_nRefreshRateDenominator;
      if ( m_nRefreshRateDenominator != 0 )
        this->m_PresentParameters.FullScreen_RefreshRateInHz = info->m_DisplayMode.m_nRefreshRateNumerator
                                                             / m_nRefreshRateDenominator;
      else
        this->m_PresentParameters.FullScreen_RefreshRateInHz = 0;
LABEL_36:
      if ( info->m_nAASamples <= 0 || this->m_PresentParameters.SwapEffect != D3DSWAPEFFECT_DISCARD )
      {
        this->m_PresentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
        this->m_PresentParameters.MultiSampleQuality = 0;
        return;
      }
      v32 = CShaderDeviceDx8::ComputeMultisampleType(this, nSampleCount: info->m_nAASamples);
      HardwareCaps = CShaderDeviceMgrBase::GetHardwareCaps(this: &g_ShaderDeviceMgrDx8, nAdapter);
      if ( info->m_nAASamples == 16 && HardwareCaps->m_ActualCaps.m_VendorID == 4318 )
      {
        v32 = D3DMULTISAMPLE_4_SAMPLES;
        v34 = g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceMultiSampleType(
                this: g_pShaderDeviceMgrDx8->m_pD3D,
                a2: nAdapter,
                a3: D3DDEVTYPE_HAL,
                a4: this->m_PresentParameters.BackBufferFormat,
                a5: this->m_PresentParameters.Windowed,
                a6: D3DMULTISAMPLE_4_SAMPLES,
                a7: (unsigned int *)&bSetSymbolsOnly);
        if ( v34 >= 0 && bSetSymbolsOnly == IMAGE_FORMAT_BGRX8888 )
        {
          v35 = 15;
          goto LABEL_45;
        }
      }
      else
      {
        v34 = g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceMultiSampleType(
                this: g_pShaderDeviceMgrDx8->m_pD3D,
                a2: nAdapter,
                a3: D3DDEVTYPE_HAL,
                a4: this->m_PresentParameters.BackBufferFormat,
                a5: this->m_PresentParameters.Windowed,
                a6: v32,
                a7: (unsigned int *)&bSetSymbolsOnly);
      }
      v35 = 0;
LABEL_45:
      if ( v34 >= 0 )
      {
        this->m_PresentParameters.MultiSampleType = v32;
        this->m_PresentParameters.MultiSampleQuality = v35;
      }
      return;
    }
    this->m_PresentParameters.PresentationInterval = 0x80000000;
    v29 = *((_BYTE *)info + 52);
    if ( (v29 & 2) != 0 )
    {
      v30 = mode.m_nHeight;
      if ( (v29 & 8) != 0 )
      {
        m_nWindowedSizeLimitWidth = info->m_nWindowedSizeLimitWidth;
        if ( m_nWindowedSizeLimitWidth < mode.m_nWidth || info->m_nWindowedSizeLimitHeight < mode.m_nHeight )
        {
          this->m_PresentParameters.BackBufferWidth = m_nWindowedSizeLimitWidth;
          this->m_PresentParameters.BackBufferHeight = info->m_nWindowedSizeLimitHeight;
LABEL_35:
          this->m_PresentParameters.BackBufferFormat = ImageLoader::ImageFormatToD3DFormat(format: bSetSymbolsOnly);
          this->m_PresentParameters.BackBufferCount = 1;
          goto LABEL_36;
        }
      }
      this->m_PresentParameters.BackBufferWidth = mode.m_nWidth;
    }
    else
    {
      this->m_PresentParameters.BackBufferWidth = info->m_DisplayMode.m_nWidth;
      v30 = info->m_DisplayMode.m_nHeight;
    }
    this->m_PresentParameters.BackBufferHeight = v30;
    goto LABEL_35;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025E40
// Name: public: virtual void CShaderDeviceDx8::ShutdownDevice(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::ShutdownDevice(CShaderDeviceDx8 *this)
{
  D3DDeviceWrapper *v2; // edi
  D3DDeviceWrapper *v3; // eax

  if ( Dx9Device()->m_pD3DDevice != nullptr )
  {
    v2 = Dx9Device();
    D3DDeviceWrapper::Synchronize(this: v2);
    v2->m_pD3DDevice->Release(this: v2->m_pD3DDevice);
    v3 = Dx9Device();
    v3->m_pD3DDevice = nullptr;
    v3->m_pPresentParameters = nullptr;
    v3->m_pHWnd = nullptr;
    CShaderDeviceBase::RemoveWindowHook(this, hWnd: (HWND)this->m_hWnd);
    this->m_hWnd = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025EA0
// Name: public: virtual bool CShaderDeviceDx8::IsUsingGraphics(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceDx8::IsUsingGraphics(CShaderDeviceDx8 *this)
{
  return Dx9Device()->m_pD3DDevice != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10025EB0
// Name: public: virtual int CShaderDeviceDx8::GetCurrentAdapter(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShaderDeviceDx8::GetCurrentAdapter(CShaderDeviceDx8 *this)
{
  return this->m_DisplayAdapter;
}

//------------------------------------------------------------------------------
// Address: 0x10025EC0
// Name: public: virtual void CShaderDeviceDx8::SpewDriverInfo(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::SpewDriverInfo(CShaderDeviceDx8 *this)
{
  D3DDeviceWrapper *v2; // esi
  int m_nAdapter; // edx
  const ImageFormatInfo_t *v4; // eax
  const char *v5; // edx
  const char *v6; // ecx
  const char *v7; // eax
  const char *v8; // edx
  const char *v9; // ecx
  const char *v10; // eax
  const char *v11; // edx
  const char *v12; // ecx
  const char *v13; // eax
  const char *v14; // edx
  const char *v15; // ecx
  const char *v16; // eax
  const char *v17; // edx
  const char *v18; // ecx
  const char *v19; // eax
  const char *v20; // edx
  const char *v21; // ecx
  const char *v22; // eax
  const char *v23; // ebx
  const char *v24; // edi
  const char *v25; // edx
  const char *v26; // ecx
  const char *v27; // eax
  const char *v28; // edi
  const char *v29; // edx
  const char *v30; // ecx
  const char *v31; // eax
  const char *v32; // edi
  const char *v33; // edx
  const char *v34; // ecx
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  const char *v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  const char *v42; // eax
  const char *v43; // eax
  HDRType_t m_HDRType; // eax
  __int32 v45; // eax
  const char *v46; // eax
  const char *v47; // eax
  const char *v48; // eax
  const char *v49; // eax
  const char *v50; // eax
  const char *v51; // eax
  const char *v52; // eax
  const char *v53; // eax
  _D3DADAPTER_IDENTIFIER9 ident; // [esp+8h] [ebp-594h] BYREF
  _D3DCAPS9 caps; // [esp+454h] [ebp-148h] BYREF
  ShaderDisplayMode_t mode; // [esp+584h] [ebp-18h] BYREF

  v2 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v2);
  v2->m_pD3DDevice->GetDeviceCaps(this: v2->m_pD3DDevice, a2: &caps);
  g_pShaderDeviceMgrDx8->m_pD3D->GetAdapterIdentifier(
    this: g_pShaderDeviceMgrDx8->m_pD3D,
    a2: this->m_nAdapter,
    a3: 2u,
    a4: &ident);
  _Warning(a1: "Shader API Driver Info:\n\nDriver : %s Version : %lld\n", ident.Driver, ident.DriverVersion.QuadPart);
  _Warning(a1: "Driver Description :  %s\n", ident.Description);
  _Warning(a1: "Chipset version %d %d %d %d\n\n", ident.VendorId, ident.DeviceId, ident.SubSysId, ident.Revision);
  m_nAdapter = this->m_nAdapter;
  memset(&mode.m_nWidth, 0, 20);
  mode.m_nVersion = 1;
  g_pShaderDeviceMgr->GetCurrentModeInfo(this: g_pShaderDeviceMgr, a2: &mode, a3: m_nAdapter);
  v4 = ImageLoader::ImageFormatInfo(fmt: mode.m_Format);
  _Warning(
    a1: "Display mode : %d x %d @%dHz (%s)\n",
    mode.m_nWidth,
    mode.m_nHeight,
    mode.m_nRefreshRateNumerator,
    v4->m_pName);
  _Warning(
    a1: "Vertex Shader Version : %d.%d Pixel Shader Version : %d.%d\n",
    BYTE1(caps.VertexShaderVersion),
    LOBYTE(caps.VertexShaderVersion),
    BYTE1(caps.PixelShaderVersion),
    LOBYTE(caps.PixelShaderVersion));
  _Warning(a1: "\nDevice Caps :\n");
  v5 = " Y ";
  if ( (caps.DevCaps & 0x80000) == 0 )
    v5 = "*N*";
  v6 = " Y ";
  if ( (caps.DevCaps & 0x800) == 0 )
    v6 = " N ";
  v7 = " Y ";
  if ( (caps.DevCaps & 0x20000) == 0 )
    v7 = " N ";
  _Warning(a1: "CANBLTSYSTONONLOCAL %s CANRENDERAFTERFLIP %s HWRASTERIZATION %s\n", v7, v6, v5);
  v8 = " Y ";
  if ( (caps.DevCaps & 0x100000) == 0 )
    v8 = " N ";
  v9 = " Y ";
  if ( (caps.DevCaps & 0x1000000) == 0 )
    v9 = " N ";
  v10 = " Y ";
  if ( (caps.DevCaps & 0x10000) == 0 )
    v10 = " N ";
  _Warning(a1: "HWTRANSFORMANDLIGHT %s NPATCHES %s PUREDEVICE %s\n", v10, v9, v8);
  v11 = " Y ";
  if ( (caps.DevCaps & 0x100) == 0 )
    v11 = " N ";
  v12 = " Y ";
  if ( (caps.DevCaps & 0x1000) == 0 )
    v12 = " N ";
  v13 = "*Y*";
  if ( (caps.DevCaps & 0x4000) == 0 )
    v13 = " N ";
  _Warning(a1: "SEPARATETEXTUREMEMORIES %s TEXTURENONLOCALVIDMEM %s TEXTURESYSTEMMEMORY %s\n", v13, v12, v11);
  v14 = " Y ";
  if ( SLOBYTE(caps.DevCaps) >= 0 )
    v14 = " N ";
  v15 = " Y ";
  if ( (caps.DevCaps & 0x40) == 0 )
    v15 = "*N*";
  v16 = " Y ";
  if ( (caps.DevCaps & 0x200) == 0 )
    v16 = "*N*";
  _Warning(a1: "TEXTUREVIDEOMEMORY %s TLVERTEXSYSTEMMEMORY %s TLVERTEXVIDEOMEMORY %s\n", v16, v15, v14);
  _Warning(a1: "\nPrimitive Caps :\n");
  v17 = " Y ";
  if ( (caps.PrimitiveMiscCaps & 0x200) == 0 )
    v17 = " N ";
  v18 = " Y ";
  if ( (caps.PrimitiveMiscCaps & 0x100) == 0 )
    v18 = " N ";
  v19 = " Y ";
  if ( (caps.PrimitiveMiscCaps & 0x800) == 0 )
    v19 = " N ";
  _Warning(a1: "BLENDOP %s CLIPPLANESCALEDPOINTS %s CLIPTLVERTS %s\n", v19, v18, v17);
  v20 = " Y ";
  if ( (caps.PrimitiveMiscCaps & 0x400) == 0 )
    v20 = " N ";
  v21 = " Y ";
  if ( (caps.PrimitiveMiscCaps & 2) == 0 )
    v21 = "*N*";
  v22 = " Y ";
  if ( SLOBYTE(caps.PrimitiveMiscCaps) >= 0 )
    v22 = " N ";
  _Warning(a1: "COLORWRITEENABLE %s MASKZ %s TSSARGTEMP %s\n", v22, v21, v20);
  _Warning(a1: "\nRaster Caps :\n");
  v23 = " Y ";
  if ( (caps.RasterCaps & 0x100000) == 0 )
    v23 = " N ";
  v24 = " Y ";
  if ( (caps.RasterCaps & 0x200000) == 0 )
    v24 = " N ";
  v25 = " Y ";
  if ( SLOBYTE(caps.RasterCaps) >= 0 )
    v25 = " N ";
  v26 = " Y ";
  if ( (caps.RasterCaps & 0x100) == 0 )
    v26 = " N ";
  v27 = " Y ";
  if ( (caps.RasterCaps & 0x10000) == 0 )
    v27 = " N ";
  _Warning(a1: "FOGRANGE %s FOGTABLE %s FOGVERTEX %s ZFOG %s WFOG %s\n", v27, v26, v25, v24, v23);
  v28 = " Y ";
  if ( (caps.RasterCaps & 0x10) == 0 )
    v28 = "*N*";
  v29 = " Y ";
  if ( (caps.RasterCaps & 0x4000000) == 0 )
    v29 = " N ";
  v30 = " Y ";
  if ( (caps.RasterCaps & 0x40000) == 0 )
    v30 = " N ";
  v31 = " Y ";
  if ( (caps.RasterCaps & 0x2000) == 0 )
    v31 = " N ";
  _Warning(a1: "MIPMAPLODBIAS %s WBUFFER %s ZBIAS %s ZTEST %s\n", v31, v30, v29, v28);
  _Warning(a1: "Size of Texture Memory : %d kb\n", g_pHardwareConfig->m_Caps.m_TextureMemorySize / 1024);
  _Warning(a1: "Max Texture Dimensions : %d x %d\n", caps.MaxTextureWidth, caps.MaxTextureHeight);
  if ( caps.MaxTextureAspectRatio != 0 )
    _Warning(a1: "Max Texture Aspect Ratio : *%d*\n", caps.MaxTextureAspectRatio);
  _Warning(a1: "Max Textures : %d\n", caps.MaxSimultaneousTextures);
  _Warning(a1: "\nTexture Caps :\n");
  v32 = "*Y*";
  if ( (caps.TextureCaps & 0x20) == 0 )
    v32 = " N ";
  v33 = " Y ";
  if ( (caps.TextureCaps & 0x10000) == 0 )
    v33 = " N ";
  v34 = " Y ";
  if ( (caps.TextureCaps & 0x800) == 0 )
    v34 = " N ";
  v35 = " Y ";
  if ( (caps.TextureCaps & 4) == 0 )
    v35 = " N ";
  _Warning(a1: "ALPHA %s CUBEMAP %s MIPCUBEMAP %s SQUAREONLY %s\n", v35, v34, v33, v32);
  _Warning(a1: "vendor id: 0x%x\n", g_pHardwareConfig->m_ActualCaps.m_VendorID);
  _Warning(a1: "device id: 0x%x\n", g_pHardwareConfig->m_ActualCaps.m_DeviceID);
  _Warning(a1: "SHADERAPI CAPS:\n");
  _Warning(a1: "m_NumSamplers: %d\n", g_pHardwareConfig->m_Caps.m_NumSamplers);
  _Warning(a1: "m_NumVertexSamplers: %d\n", g_pHardwareConfig->m_Caps.m_NumVertexSamplers);
  v36 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 716) & 2) == 0 )
    v36 = "no";
  _Warning(a1: "m_HasSetDeviceGammaRamp: %s\n", v36);
  v37 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 716) & 4) == 0 )
    v37 = "no";
  _Warning(a1: "m_SupportsPixelShaders_2_b: %s\n", v37);
  v38 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 716) & 8) == 0 )
    v38 = "no";
  _Warning(a1: "m_SupportsShaderModel_3_0: %s\n", v38);
  _Warning(a1: "m_SupportsCompressedVertices: %d\n", g_pHardwareConfig->m_Caps.m_SupportsCompressedVertices);
  v39 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 716) & 0x10) == 0 )
    v39 = "no";
  _Warning(a1: "m_bSupportsAnisotropicFiltering: %s\n", v39);
  _Warning(a1: "m_nMaxAnisotropy: %d\n", g_pHardwareConfig->m_Caps.m_nMaxAnisotropy);
  _Warning(a1: "m_MaxTextureWidth: %d\n", g_pHardwareConfig->m_Caps.m_MaxTextureWidth);
  _Warning(a1: "m_MaxTextureHeight: %d\n", g_pHardwareConfig->m_Caps.m_MaxTextureHeight);
  _Warning(a1: "m_MaxTextureAspectRatio: %d\n", g_pHardwareConfig->m_Caps.m_MaxTextureAspectRatio);
  _Warning(a1: "m_MaxPrimitiveCount: %d\n", g_pHardwareConfig->m_Caps.m_MaxPrimitiveCount);
  v40 = "yes";
  if ( *((char *)&g_pHardwareConfig->m_Caps + 716) >= 0 )
    v40 = "no";
  _Warning(a1: "m_ZBiasAndSlopeScaledDepthBiasSupported: %s\n", v40);
  _Warning(a1: "m_NumPixelShaderConstants: %d\n", g_pHardwareConfig->m_Caps.m_NumPixelShaderConstants);
  _Warning(a1: "m_NumVertexShaderConstants: %d\n", g_pHardwareConfig->m_Caps.m_NumVertexShaderConstants);
  _Warning(a1: "m_NumBooleanVertexShaderConstants: %d\n", g_pHardwareConfig->m_Caps.m_NumBooleanVertexShaderConstants);
  _Warning(a1: "m_NumIntegerVertexShaderConstants: %d\n", g_pHardwareConfig->m_Caps.m_NumIntegerVertexShaderConstants);
  _Warning(a1: "m_TextureMemorySize: %d\n", g_pHardwareConfig->m_Caps.m_TextureMemorySize);
  _Warning(a1: "m_MaxNumLights: %d\n", g_pHardwareConfig->m_Caps.m_MaxNumLights);
  _Warning(a1: "m_MaxVertexShaderBlendMatrices: %d\n", g_pHardwareConfig->m_Caps.m_MaxVertexShaderBlendMatrices);
  v41 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 1) == 0 )
    v41 = "no";
  _Warning(a1: "m_SupportsMipmappedCubemaps: %s\n", v41);
  _Warning(a1: "m_nDXSupportLevel: %d\n", g_pHardwareConfig->m_Caps.m_nDXSupportLevel);
  v42 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 2) == 0 )
    v42 = "no";
  _Warning(a1: "m_PreferDynamicTextures: %s\n", v42);
  _Warning(a1: "m_MaxUserClipPlanes: %d\n", g_pHardwareConfig->m_Caps.m_MaxUserClipPlanes);
  v43 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 4) == 0 )
    v43 = "no";
  _Warning(a1: "m_SupportsSRGB: %s\n", v43);
  m_HDRType = g_pHardwareConfig->m_Caps.m_HDRType;
  if ( m_HDRType != HDR_TYPE_NONE )
  {
    v45 = m_HDRType - 1;
    if ( v45 != 0 )
    {
      if ( v45 == 1 )
        _Warning(a1: "m_HDRType: HDR_TYPE_FLOAT\n");
    }
    else
    {
      _Warning(a1: "m_HDRType: HDR_TYPE_INTEGER\n");
    }
  }
  else
  {
    _Warning(a1: "m_HDRType: HDR_TYPE_NONE\n");
  }
  v46 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 8) == 0 )
    v46 = "no";
  _Warning(a1: "m_UseFastClipping: %s\n", v46);
  _Warning(a1: "m_pShaderDLL: %s\n", g_pHardwareConfig->m_Caps.m_pShaderDLL);
  v47 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 0x10) == 0 )
    v47 = "no";
  _Warning(a1: "m_bNeedsATICentroidHack: %s\n", v47);
  v48 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 0x20) == 0 )
    v48 = "no";
  _Warning(a1: "m_bDisableShaderOptimizations: %s\n", v48);
  _Warning(a1: "m_MaxSimultaneousRenderTargets: %d\n", g_pHardwareConfig->m_Caps.m_MaxSimultaneousRenderTargets);
  v49 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 8) == 0 )
    v49 = "no";
  _Warning(a1: "m_bPreferZPrepass: %s\n", v49);
  v50 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 0x10) == 0 )
    v50 = "no";
  _Warning(a1: "m_bSuppressPixelShaderCentroidHackFixup: %s\n", v50);
  v51 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 0x20) == 0 )
    v51 = "no";
  _Warning(a1: "m_bPreferTexturesInHWMemory: %s\n", v51);
  v52 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 0x40) == 0 )
    v52 = "no";
  _Warning(a1: "m_bPreferHardwareSync: %s\n", v52);
  v53 = "yes";
  if ( *((char *)&g_pHardwareConfig->m_Caps + 719) >= 0 )
    v53 = "no";
  _Warning(a1: "m_bUnsupported: %s\n", v53);
}

//------------------------------------------------------------------------------
// Address: 0x10026710
// Name: public: virtual enum ImageFormat CShaderDeviceDx8::GetBackBufferFormat(void)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CShaderDeviceDx8::GetBackBufferFormat(CShaderDeviceDx8 *this)
{
  return ImageLoader::D3DFormatToImageFormat(format: this->m_PresentParameters.BackBufferFormat);
}

//------------------------------------------------------------------------------
// Address: 0x10026720
// Name: public: virtual void CShaderDeviceDx8::GetBackBufferDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::GetBackBufferDimensions(CShaderDeviceDx8 *this, int *width, int *height)
{
  *width = this->m_PresentParameters.BackBufferWidth;
  *height = this->m_PresentParameters.BackBufferHeight;
}

//------------------------------------------------------------------------------
// Address: 0x10026740
// Name: public: virtual struct AspectRatioInfo_t const __near & CShaderDeviceDx8::GetAspectRatioInfo(void)const
// Source: json
//------------------------------------------------------------------------------
const AspectRatioInfo_t *__thiscall CShaderDeviceDx8::GetAspectRatioInfo(CShaderDeviceDx8 *this)
{
  if ( !this->m_AspectRatioInfo.m_bInitialized )
    _Error(a1: "GetAspectRatioInfo called before aspect ratio is initialized!\n");
  return &this->m_AspectRatioInfo;
}

//------------------------------------------------------------------------------
// Address: 0x10026770
// Name: protected: void CShaderDeviceDx8::DetectQuerySupport(struct IDirect3DDevice9 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DetectQuerySupport(CShaderDeviceDx8 *this, IDirect3DDevice9 *pD3DDevice)
{
  HRESULT (__stdcall *CreateQuery)(IDirect3DDevice9 *, _D3DQUERYTYPE, IDirect3DQuery9 **); // eax
  IDirect3DQuery9 *pQueryObject; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_DeviceSupportsCreateQuery == -1 )
  {
    CreateQuery = pD3DDevice->CreateQuery;
    pQueryObject = nullptr;
    if ( CreateQuery(this: pD3DDevice, a2: D3DQUERYTYPE_EVENT, a3: &pQueryObject) >= 0 && pQueryObject != nullptr )
    {
      pQueryObject->Release(this: pQueryObject);
      this->m_DeviceSupportsCreateQuery = 1;
    }
    else
    {
      this->m_DeviceSupportsCreateQuery = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100267D0
// Name: protected: struct IDirect3DDevice9 __near * CShaderDeviceDx8::InvokeCreateDevice(void __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
IDirect3DDevice9 *__thiscall CShaderDeviceDx8::InvokeCreateDevice(
        CShaderDeviceDx8 *this,
        HWND__ *hWnd,
        unsigned int nAdapter,
        unsigned int deviceCreationFlags)
{
  int m_nValue; // eax
  unsigned int v6; // ebx
  _D3DPRESENT_PARAMETERS_ *p_m_PresentParameters; // esi
  int v8; // eax
  IDirect3DDevice9 *v9; // edx
  CShaderDeviceDx8 *v10; // ecx
  ConVarRef mat_queue_mode; // [esp+Ch] [ebp-10h] BYREF
  CShaderDeviceDx8 *v13; // [esp+14h] [ebp-8h]
  IDirect3DDevice9 *pD3DDevice; // [esp+18h] [ebp-4h] BYREF

  v13 = this;
  pD3DDevice = nullptr;
  ConVarRef::ConVarRef(this: &mat_queue_mode, pName: "mat_queue_mode");
  m_nValue = mat_queue_mode.m_pConVarState->m_Value.m_nValue;
  if ( m_nValue == 2
    || m_nValue == -2 && *(_BYTE *)(_GetCPUInformation() + 6) >= 2u
    || mat_queue_mode.m_pConVarState->m_Value.m_nValue == -1 && *(_BYTE *)(_GetCPUInformation() + 6) >= 2u )
  {
    v6 = deviceCreationFlags | 4;
  }
  else
  {
    v6 = deviceCreationFlags;
  }
  p_m_PresentParameters = &this->m_PresentParameters;
  v8 = g_pShaderDeviceMgrDx8->m_pD3D->CreateDevice(
         this: g_pShaderDeviceMgrDx8->m_pD3D,
         a2: nAdapter,
         a3: D3DDEVTYPE_HAL,
         a4: hWnd,
         a5: v6,
         a6: p_m_PresentParameters,
         a7: &pD3DDevice);
  if ( v8 < 0 || (v9 = pD3DDevice, pD3DDevice == nullptr) )
  {
    Sleep(dwMilliseconds: 0x3E8u);
    v8 = g_pShaderDeviceMgrDx8->m_pD3D->CreateDevice(
           this: g_pShaderDeviceMgrDx8->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: hWnd,
           a5: v6,
           a6: p_m_PresentParameters,
           a7: &pD3DDevice);
    v9 = pD3DDevice;
    if ( v8 < 0 || pD3DDevice == nullptr )
    {
      v10 = v13;
      if ( v13->m_PresentParameters.Windowed != 0 )
      {
        v13->m_PresentParameters.SwapEffect = D3DSWAPEFFECT_COPY;
        v10->m_PresentParameters.BackBufferCount = 0;
        v8 = g_pShaderDeviceMgrDx8->m_pD3D->CreateDevice(
               this: g_pShaderDeviceMgrDx8->m_pD3D,
               a2: nAdapter,
               a3: D3DDEVTYPE_HAL,
               a4: hWnd,
               a5: v6,
               a6: p_m_PresentParameters,
               a7: &pD3DDevice);
        v9 = pD3DDevice;
      }
    }
  }
  if ( v8 >= 0 && v9 != nullptr )
  {
    g_pShaderDeviceMgr->InvokeDeviceResetNotifications(
      this: g_pShaderDeviceMgr,
      a2: v9,
      a3: p_m_PresentParameters,
      a4: hWnd);
    return pD3DDevice;
  }
  else
  {
    pD3DDevice = nullptr;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_EngineInitialization, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_EngineInitialization,
        a2: 1,
        a3: "Failed to create %s device! Please see the following for more info.\nhttp://support.steampowered.com\n",
        "D3D");
    return pD3DDevice;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026930
// Name: public: virtual void CShaderDeviceDx8::HandleThreadEvent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::HandleThreadEvent(CShaderDeviceDx8 *this, unsigned int threadEvent)
{
  switch ( threadEvent )
  {
    case 1u:
      this->ReleaseResources(this, a2: true);
      break;
    case 2u:
      this->ReacquireResources(this);
      break;
    case 4u:
      this->EvictManagedResourcesInternal(this);
      break;
    case 5u:
      this->OtherAppInitializing(this, a2: true);
      break;
    case 6u:
      this->OtherAppInitializing(this, a2: false);
      break;
    case 7u:
      this->ResetRenderState(this, a2: true);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100269C0
// Name: protected: bool CShaderDeviceDx8::TryDeviceReset(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceDx8::TryDeviceReset(CShaderDeviceDx8 *this)
{
  D3DDeviceWrapper *v3; // esi
  int v4; // eax
  bool v5; // bl
  D3DDeviceWrapper *v6; // eax

  if ( (*((_BYTE *)this + 172) & 0x20) == 0 )
    return false;
  v3 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v3);
  v4 = v3->m_pD3DDevice->Reset(this: v3->m_pD3DDevice, a2: &this->m_PresentParameters);
  v5 = v4 >= 0;
  if ( v4 >= 0 )
  {
    *((_BYTE *)this + 172) &= ~0x20u;
    v6 = Dx9Device();
    g_pShaderDeviceMgr->InvokeDeviceResetNotifications(
      this: g_pShaderDeviceMgr,
      a2: v6->m_pD3DDevice,
      a3: v6->m_pPresentParameters,
      a4: v6->m_pHWnd);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10026A30
// Name: protected: void CShaderDeviceDx8::MarkDeviceLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::MarkDeviceLost(CShaderDeviceDx8 *this)
{
  *((_BYTE *)this + 172) |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x10026A40
// Name: protected: void CShaderDeviceDx8::FreeNonInteractiveRefreshObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::FreeNonInteractiveRefreshObjects(CShaderDeviceDx8 *this)
{
  IDirect3DVertexShader9 *m_pVertexShader; // eax
  IDirect3DPixelShader9 *m_pPixelShader; // eax
  IDirect3DPixelShader9 *m_pPixelShaderStartup; // eax
  IDirect3DPixelShader9 *m_pPixelShaderStartupPass2; // eax
  IDirect3DVertexDeclaration9 *m_pVertexDecl; // eax

  m_pVertexShader = this->m_NonInteractiveRefresh.m_pVertexShader;
  if ( m_pVertexShader != nullptr )
  {
    m_pVertexShader->Release(this: m_pVertexShader);
    this->m_NonInteractiveRefresh.m_pVertexShader = nullptr;
  }
  m_pPixelShader = this->m_NonInteractiveRefresh.m_pPixelShader;
  if ( m_pPixelShader != nullptr )
  {
    m_pPixelShader->Release(this: this->m_NonInteractiveRefresh.m_pPixelShader);
    this->m_NonInteractiveRefresh.m_pPixelShader = nullptr;
  }
  m_pPixelShaderStartup = this->m_NonInteractiveRefresh.m_pPixelShaderStartup;
  if ( m_pPixelShaderStartup != nullptr )
  {
    m_pPixelShaderStartup->Release(this: this->m_NonInteractiveRefresh.m_pPixelShaderStartup);
    this->m_NonInteractiveRefresh.m_pPixelShaderStartup = nullptr;
  }
  m_pPixelShaderStartupPass2 = this->m_NonInteractiveRefresh.m_pPixelShaderStartupPass2;
  if ( m_pPixelShaderStartupPass2 != nullptr )
  {
    m_pPixelShaderStartupPass2->Release(this: this->m_NonInteractiveRefresh.m_pPixelShaderStartupPass2);
    this->m_NonInteractiveRefresh.m_pPixelShaderStartupPass2 = nullptr;
  }
  m_pVertexDecl = this->m_NonInteractiveRefresh.m_pVertexDecl;
  if ( m_pVertexDecl != nullptr )
  {
    m_pVertexDecl->Release(this: this->m_NonInteractiveRefresh.m_pVertexDecl);
    this->m_NonInteractiveRefresh.m_pVertexDecl = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026AD0
// Name: public: virtual class IShaderBuffer __near * CShaderDeviceDx8::CompileShader(char const __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IShaderBuffer *__thiscall CShaderDeviceDx8::CompileShader(
        CShaderDeviceDx8 *this,
        const char *pProgram,
        unsigned int nBufLen,
        const char *pShaderVersion)
{
  return g_pShaderManager->CompileShader(this: g_pShaderManager, a2: pProgram, a3: nBufLen, a4: pShaderVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10026AF0
// Name: public: virtual struct VertexShaderHandle_t__ __near * CShaderDeviceDx8::CreateVertexShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
VertexShaderHandle_t__ *__thiscall CShaderDeviceDx8::CreateVertexShader(CShaderDeviceDx8 *this, IShaderBuffer *pBuffer)
{
  return g_pShaderManager->CreateVertexShader_2(this: g_pShaderManager, a2: pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10026B10
// Name: public: virtual void CShaderDeviceDx8::DestroyVertexShader(struct VertexShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DestroyVertexShader(CShaderDeviceDx8 *this, VertexShaderHandle_t__ *hShader)
{
  g_pShaderManager->DestroyVertexShader(this: g_pShaderManager, a2: hShader);
}

//------------------------------------------------------------------------------
// Address: 0x10026B30
// Name: public: virtual struct GeometryShaderHandle_t__ __near * CShaderDeviceDx8::CreateGeometryShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
GeometryShaderHandle_t__ *__thiscall CShaderDeviceDx8::CreateGeometryShader(
        CShaderDeviceDx8 *this,
        IShaderBuffer *pShaderBuffer)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10026B40
// Name: public: virtual struct PixelShaderHandle_t__ __near * CShaderDeviceDx8::CreatePixelShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
PixelShaderHandle_t__ *__thiscall CShaderDeviceDx8::CreatePixelShader(CShaderDeviceDx8 *this, IShaderBuffer *pBuffer)
{
  return g_pShaderManager->CreatePixelShader_2(this: g_pShaderManager, a2: pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10026B60
// Name: public: virtual void CShaderDeviceDx8::DestroyPixelShader(struct PixelShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DestroyPixelShader(CShaderDeviceDx8 *this, PixelShaderHandle_t__ *hShader)
{
  g_pShaderManager->DestroyPixelShader(this: g_pShaderManager, a2: hShader);
}

//------------------------------------------------------------------------------
// Address: 0x10026B80
// Name: public: virtual class IMesh __near * CShaderDeviceDx8::CreateStaticMesh(unsigned __int64,char const __near *,class IMaterial __near *,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
IMesh *__thiscall CShaderDeviceDx8::CreateStaticMesh(
        CShaderDeviceDx8 *this,
        unsigned __int64 vertexFormat,
        const char *pTextureBudgetGroup,
        IMaterial *pMaterial,
        VertexStreamSpec_t *pStreamSpec)
{
  CMeshMgr *v5; // eax

  v5 = MeshMgr();
  return ((IMesh *(__thiscall *)(CMeshMgr *, _DWORD, _DWORD, const char *, IMaterial *, VertexStreamSpec_t *))v5->CreateStaticMesh)(
           a1: v5,
           a2: vertexFormat,
           a3: HIDWORD(vertexFormat),
           a4: pTextureBudgetGroup,
           a5: pMaterial,
           a6: pStreamSpec);
}

//------------------------------------------------------------------------------
// Address: 0x10026BB0
// Name: public: virtual void CShaderDeviceDx8::DestroyStaticMesh(class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DestroyStaticMesh(CShaderDeviceDx8 *this, IMesh *pMesh)
{
  CMeshMgr *v2; // eax

  v2 = MeshMgr();
  v2->DestroyStaticMesh(this: v2, a2: pMesh);
}

//------------------------------------------------------------------------------
// Address: 0x10026BD0
// Name: public: virtual class IVertexBuffer __near * CShaderDeviceDx8::CreateVertexBuffer(enum ShaderBufferType_t,unsigned __int64,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IVertexBuffer *__thiscall CShaderDeviceDx8::CreateVertexBuffer(
        CShaderDeviceDx8 *this,
        ShaderBufferType_t type,
        unsigned __int64 fmt,
        int nVertexCount,
        const char *pBudgetGroup)
{
  CMeshMgr *v5; // eax

  v5 = MeshMgr();
  return ((IVertexBuffer *(__thiscall *)(CMeshMgr *, ShaderBufferType_t, _DWORD, _DWORD, int, const char *))v5->CreateVertexBuffer)(
           a1: v5,
           a2: type,
           a3: fmt,
           a4: HIDWORD(fmt),
           a5: nVertexCount,
           a6: pBudgetGroup);
}

//------------------------------------------------------------------------------
// Address: 0x10026C00
// Name: public: virtual void CShaderDeviceDx8::DestroyVertexBuffer(class IVertexBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DestroyVertexBuffer(CShaderDeviceDx8 *this, IVertexBuffer *pVertexBuffer)
{
  CMeshMgr *v2; // eax

  v2 = MeshMgr();
  v2->DestroyVertexBuffer(this: v2, a2: pVertexBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10026C20
// Name: public: virtual class IIndexBuffer __near * CShaderDeviceDx8::CreateIndexBuffer(enum ShaderBufferType_t,enum MaterialIndexFormat_t,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IIndexBuffer *__thiscall CShaderDeviceDx8::CreateIndexBuffer(
        CShaderDeviceDx8 *this,
        ShaderBufferType_t bufferType,
        MaterialIndexFormat_t fmt,
        int nIndexCount,
        const char *pBudgetGroup)
{
  CMeshMgr *v5; // eax

  v5 = MeshMgr();
  return v5->CreateIndexBuffer(this: v5, a2: bufferType, a3: fmt, a4: nIndexCount, a5: pBudgetGroup);
}

//------------------------------------------------------------------------------
// Address: 0x10026C40
// Name: public: virtual void CShaderDeviceDx8::DestroyIndexBuffer(class IIndexBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DestroyIndexBuffer(CShaderDeviceDx8 *this, IIndexBuffer *pIndexBuffer)
{
  CMeshMgr *v2; // eax

  v2 = MeshMgr();
  v2->DestroyIndexBuffer(this: v2, a2: pIndexBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10026C60
// Name: public: virtual class IVertexBuffer __near * CShaderDeviceDx8::GetDynamicVertexBuffer(int,unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
IVertexBuffer *__thiscall CShaderDeviceDx8::GetDynamicVertexBuffer(
        CShaderDeviceDx8 *this,
        int streamID,
        unsigned __int64 vertexFormat,
        int bBuffered)
{
  CMeshMgr *v4; // eax

  v4 = MeshMgr();
  return ((IVertexBuffer *(__thiscall *)(CMeshMgr *, int, _DWORD, _DWORD, int))v4->GetDynamicVertexBuffer_2)(
           a1: v4,
           a2: streamID,
           a3: vertexFormat,
           a4: HIDWORD(vertexFormat),
           a5: bBuffered);
}

//------------------------------------------------------------------------------
// Address: 0x10026C90
// Name: public: virtual class IIndexBuffer __near * CShaderDeviceDx8::GetDynamicIndexBuffer(void)
// Source: json
//------------------------------------------------------------------------------
IIndexBuffer *__thiscall CShaderDeviceDx8::GetDynamicIndexBuffer(CShaderDeviceDx8 *this)
{
  CMeshMgr *v1; // eax

  v1 = MeshMgr();
  return v1->GetDynamicIndexBuffer(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10026CD0
// Name: private: void CShaderDeviceMgrDx8::CheckVendorDependentShadowMappingSupport(struct HardwareCaps_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::CheckVendorDependentShadowMappingSupport(
        CShaderDeviceMgrDx8 *this,
        HardwareCaps_t *pCaps,
        unsigned int nAdapter)
{
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  unsigned int m_VendorID; // eax
  char v10; // al
  char v11; // al
  char v12; // cl
  char bFound16Bit_3; // [esp+17h] [ebp+Bh]
  bool bToolsMode_3; // [esp+1Bh] [ebp+Fh]

  pCaps->m_NullTextureFormat = IMAGE_FORMAT_ARGB8888;
  if ( this->m_pD3D->CheckDeviceFormat(
         this: this->m_pD3D,
         a2: nAdapter,
         a3: D3DDEVTYPE_HAL,
         a4: D3DFMT_X8R8G8B8,
         a5: 1u,
         a6: D3DRTYPE_TEXTURE,
         a7: D3DFMT_R5G6B5) == 0 )
    pCaps->m_NullTextureFormat = IMAGE_FORMAT_RGB565;
  v7 = _CommandLine(a1: v6);
  v8 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v7 + 12))(a1: v7, a2: "-tools", a3: 0) == 0;
  m_VendorID = pCaps->m_VendorID;
  bToolsMode_3 = !v8;
  bFound16Bit_3 = 0;
  if ( m_VendorID == 4318
    && ((*((_BYTE *)pCaps + 716) & 8) != 0
     || r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0) )
  {
    if ( this->m_pD3D->CheckDeviceFormat(
           this: this->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: D3DFMT_X8R8G8B8,
           a5: 1u,
           a6: D3DRTYPE_TEXTURE,
           a7: (_D3DFORMAT)1280070990) == 0 )
      pCaps->m_NullTextureFormat = IMAGE_FORMAT_NULL;
    if ( this->m_pD3D->CheckDeviceFormat(
           this: this->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: D3DFMT_X8R8G8B8,
           a5: 2u,
           a6: D3DRTYPE_TEXTURE,
           a7: D3DFMT_D16) != 0
      || (v10 = *((_BYTE *)pCaps + 718) & 0xF3 | 4,
          pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_D16_SHADOW,
          *((_BYTE *)pCaps + 718) = v10,
          bFound16Bit_3 = 1,
          bToolsMode_3) )
    {
      if ( this->m_pD3D->CheckDeviceFormat(
             this: this->m_pD3D,
             a2: nAdapter,
             a3: D3DDEVTYPE_HAL,
             a4: D3DFMT_X8R8G8B8,
             a5: 2u,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_D24S8) == 0 )
      {
        v11 = *((_BYTE *)pCaps + 718) & 0xF3 | 4;
        pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_D24X8_SHADOW;
        *((_BYTE *)pCaps + 718) = v11;
        return;
      }
      goto LABEL_23;
    }
  }
  else
  {
    if ( m_VendorID != 4098 || (*((_BYTE *)pCaps + 716) & 4) == 0 )
    {
      if ( m_VendorID == 32902
        && (*((_BYTE *)pCaps + 716) & 4) != 0
        && this->m_pD3D->CheckDeviceFormat(
             this: this->m_pD3D,
             a2: nAdapter,
             a3: D3DDEVTYPE_HAL,
             a4: D3DFMT_X8R8G8B8,
             a5: 2u,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_D24S8) == 0 )
      {
        v12 = *((_BYTE *)pCaps + 718) & 0xF3 | 4;
        pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_D24X8_SHADOW;
        *((_BYTE *)pCaps + 718) = v12;
        return;
      }
LABEL_24:
      *((_BYTE *)pCaps + 718) &= 0xF3u;
      pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_UNKNOWN;
      return;
    }
    *((_BYTE *)pCaps + 718) &= ~8u;
    if ( this->m_pD3D->CheckDeviceFormat(
           this: this->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: D3DFMT_X8R8G8B8,
           a5: 2u,
           a6: D3DRTYPE_TEXTURE,
           a7: (_D3DFORMAT)875710020) == 0 )
      *((_BYTE *)pCaps + 718) |= 8u;
    if ( (*((_BYTE *)pCaps + 719) & 1) != 0 )
      *((_BYTE *)pCaps + 718) &= ~8u;
    if ( this->m_pD3D->CheckDeviceFormat(
           this: this->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: D3DFMT_X8R8G8B8,
           a5: 2u,
           a6: D3DRTYPE_TEXTURE,
           a7: (_D3DFORMAT)909198916) != 0
      || (*((_BYTE *)pCaps + 718) |= 4u,
          pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_D16_SHADOW,
          bFound16Bit_3 = 1,
          bToolsMode_3) )
    {
      if ( this->m_pD3D->CheckDeviceFormat(
             this: this->m_pD3D,
             a2: nAdapter,
             a3: D3DDEVTYPE_HAL,
             a4: D3DFMT_X8R8G8B8,
             a5: 2u,
             a6: D3DRTYPE_TEXTURE,
             a7: (_D3DFORMAT)875710020) == 0 )
      {
        *((_BYTE *)pCaps + 718) |= 4u;
        pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_D24X8_SHADOW;
        return;
      }
LABEL_23:
      if ( bFound16Bit_3 != 0 )
        return;
      goto LABEL_24;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026F30
// Name: private: void CShaderDeviceMgrDx8::CheckVendorDependentAlphaToCoverage(struct HardwareCaps_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShaderDeviceMgrDx8::CheckVendorDependentAlphaToCoverage(
        CShaderDeviceMgrDx8 *this@<ecx>,
        int a2@<ebx>,
        HardwareCaps_t *pCaps,
        int nAdapter)
{
  char v4; // al
  unsigned int m_VendorID; // ecx
  bool v7; // bl

  *((_BYTE *)pCaps + 718) &= ~2u;
  v4 = *((_BYTE *)pCaps + 718);
  if ( r_emulategl.m_pParent == nullptr || r_emulategl.m_pParent->m_Value.m_nValue == 0 )
  {
    m_VendorID = pCaps->m_VendorID;
    if ( m_VendorID == 4318 )
    {
      v7 = ((int (__stdcall *)(IDirect3D9 *, int, int, int, _DWORD, int, int, int))this->m_pD3D->CheckDeviceFormat)(
             a1: this->m_pD3D,
             a2: nAdapter,
             a3: 1,
             a4: 22,
             a5: 0,
             a6: 1,
             a7: 1129272385,
             a8: a2) == 0;
      ((void (__stdcall *)(IDirect3D9 *, int, int, int, _DWORD, int))this->m_pD3D->CheckDeviceFormat)(
        a1: this->m_pD3D,
        a2: nAdapter,
        a3: 1,
        a4: 22,
        a5: 0,
        a6: 1);
      if ( v7 )
      {
        *((_BYTE *)pCaps + 718) |= 2u;
        pCaps->m_AlphaToCoverageEnableValue = 1129272385;
        pCaps->m_AlphaToCoverageState = 181;
        pCaps->m_AlphaToCoverageDisableValue = 0;
      }
    }
    else if ( m_VendorID == 4098 )
    {
      pCaps->m_AlphaToCoverageState = 154;
      pCaps->m_AlphaToCoverageEnableValue = 827142721;
      pCaps->m_AlphaToCoverageDisableValue = 810365505;
      *((_BYTE *)pCaps + 718) = v4 | 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027010
// Name: public: bool CShaderDeviceMgrDx8::ComputeCapsFromD3D(struct HardwareCaps_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrDx8::ComputeCapsFromD3D(CShaderDeviceMgrDx8 *this, HardwareCaps_t *pCaps, int nAdapter)
{
  unsigned int VendorId; // edx
  unsigned int Caps2; // eax
  unsigned int SubSysId; // ecx
  unsigned __int16 PixelShaderVersion; // ax
  char v10; // bl
  char v11; // cl
  bool v12; // dl
  char v13; // al
  char v14; // cl
  ConVar *m_pParent; // ecx
  bool v16; // zf
  unsigned int MaxPixelShader30InstructionSlots; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int m_nValue; // eax
  unsigned __int8 v22; // dl
  int v23; // ecx
  unsigned int MaxAnisotropy; // eax
  int v25; // eax
  int m_NumVertexShaderConstants; // eax
  signed int MaxActiveLights; // eax
  unsigned int MaxVolumeExtent; // eax
  signed int MaxTextureWidth; // edx
  signed int MaxTextureHeight; // ebx
  unsigned int MaxTextureAspectRatio; // eax
  int v32; // eax
  unsigned int MaxPrimitiveCount; // eax
  char v34; // dl
  unsigned int RasterCaps; // eax
  char v36; // al
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  HRESULT v41; // eax
  HRESULT (__stdcall *CheckDeviceFormat)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, _D3DFORMAT, unsigned int, _D3DRESOURCETYPE, _D3DFORMAT); // edx
  int v43; // eax
  HRESULT (__stdcall *v44)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, _D3DFORMAT, unsigned int, _D3DRESOURCETYPE, _D3DFORMAT); // edx
  int v45; // eax
  HRESULT (__stdcall *v46)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, _D3DFORMAT, unsigned int, _D3DRESOURCETYPE, _D3DFORMAT); // edx
  int v47; // eax
  char v48; // dl
  char v49; // cl
  char v50; // al
  char v51; // dl
  unsigned int m_VendorID; // ebx
  char v53; // al
  char v54; // dl
  unsigned int m_DeviceID; // edx
  bool v56; // dl
  bool v57; // dl
  bool v58; // al
  int v59; // ecx
  int v60; // eax
  IDirect3D9 *m_pD3D; // [esp+F8h] [ebp-5A4h]
  IDirect3D9 *v62; // [esp+F8h] [ebp-5A4h]
  IDirect3D9 *v63; // [esp+F8h] [ebp-5A4h]
  _D3DADAPTER_IDENTIFIER9 ident; // [esp+11Ch] [ebp-580h] BYREF
  _D3DCAPS9 caps; // [esp+568h] [ebp-134h] BYREF
  char v66; // [esp+698h] [ebp-4h]
  bool bSupportsFloat16RenderTargets; // [esp+699h] [ebp-3h]
  bool bSupportsInteger16Textures; // [esp+69Ah] [ebp-2h]
  bool bGLSLControlFlow; // [esp+69Bh] [ebp-1h]
  unsigned __int8 pCaps_3b; // [esp+6A7h] [ebp+Bh]
  char pCaps_3; // [esp+6A7h] [ebp+Bh]
  char pCaps_3a; // [esp+6A7h] [ebp+Bh]

  if ( this->m_pD3D->GetDeviceCaps(this: this->m_pD3D, a2: nAdapter, a3: D3DDEVTYPE_HAL, a4: &caps) < 0
    || this->m_pD3D->GetAdapterIdentifier(this: this->m_pD3D, a2: nAdapter, a3: 2u, a4: &ident) < 0 )
  {
    return 0;
  }
  V_strncpy(pDest: pCaps->m_pDriverName, pSrc: ident.Description, maxLen: 512);
  VendorId = ident.VendorId;
  pCaps->m_DeviceID = ident.DeviceId;
  pCaps->m_nDriverVersionHigh = ident.DriverVersion.HighPart;
  Caps2 = caps.Caps2;
  SubSysId = ident.SubSysId;
  pCaps->m_VendorID = VendorId;
  pCaps->m_Revision = ident.Revision;
  *((_BYTE *)pCaps + 716) ^= (*((_BYTE *)pCaps + 716) ^ (2 * (Caps2 >> 20))) & 2;
  LOBYTE(VendorId) = *((_BYTE *)pCaps + 717) ^ (2 * (Caps2 >> 29));
  *((_BYTE *)pCaps + 718) ^= (*((_BYTE *)pCaps + 718) ^ (32 * HIBYTE(caps.RasterCaps))) & 0x20;
  PixelShaderVersion = caps.PixelShaderVersion;
  *((_BYTE *)pCaps + 717) ^= VendorId & 2;
  v10 = *((_BYTE *)pCaps + 717);
  pCaps->m_SubSysID = SubSysId;
  pCaps->m_nDriverVersionLow = ident.DriverVersion.LowPart;
  v11 = *((_BYTE *)pCaps + 716);
  pCaps->m_pShaderDLL[0] = 0;
  pCaps->m_nMaxViewports = 1;
  v12 = PixelShaderVersion >= 0x200u && caps.PS20Caps.NumInstructionSlots >= 512;
  v13 = v11 & 0xF3 | (4 * (v12 | (2 * (PixelShaderVersion >= 0x300u))));
  v14 = v10 ^ (v10 ^ BYTE2(caps.TextureCaps)) & 1;
  *((_BYTE *)pCaps + 716) = v13;
  *((_BYTE *)pCaps + 717) = v14;
  m_pParent = r_emulategl.m_pParent;
  if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    *((_BYTE *)pCaps + 716) = v13 & 0xF7;
  if ( ident.VendorId == 32902 )
    *((_BYTE *)pCaps + 716) &= ~8u;
  v16 = (*((_BYTE *)pCaps + 716) & 8) == 0;
  pCaps->m_MaxVertexShader30InstructionSlots = 0;
  pCaps->m_MaxPixelShader30InstructionSlots = 0;
  if ( !v16 )
  {
    MaxPixelShader30InstructionSlots = caps.MaxPixelShader30InstructionSlots;
    pCaps->m_MaxVertexShader30InstructionSlots = caps.MaxVertexShader30InstructionSlots;
    pCaps->m_MaxPixelShader30InstructionSlots = MaxPixelShader30InstructionSlots;
  }
  *((_BYTE *)pCaps + 718) &= ~0x10u;
  v18 = _CommandLine(a1: m_pParent);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v18 + 12))(a1: v18, a2: "-mat_softwaretl", a3: 0) != 0 )
    *((_BYTE *)pCaps + 718) |= 0x10u;
  if ( (caps.DevCaps & 0x10000) == 0 )
    *((_BYTE *)pCaps + 718) |= 0x10u;
  if ( (*((_BYTE *)pCaps + 718) & 0x10) != 0 )
    ConVar::SetValue(this: (ConVar *)&mat_forcedynamic.IConVar, value: 1);
  v20 = _CommandLine(a1: v19);
  bGLSLControlFlow = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v20 + 12))(
                       a1: v20,
                       a2: "-glslcontrolflow",
                       a3: 0) != 0;
  if ( r_emulategl.m_pParent != nullptr )
    m_nValue = r_emulategl.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v22 = 16 * (((caps.TextureFilterCaps & 0x400) != 0) | (2 * ((caps.TextureFilterCaps & 0x4000000) != 0)));
  pCaps_3b = *((_BYTE *)pCaps + 716) & 0xCF;
  *((_BYTE *)pCaps + 720) ^= (*((_BYTE *)pCaps + 720) ^ (m_nValue == 0)) & 1;
  v23 = 16;
  *((_BYTE *)pCaps + 716) = pCaps_3b | v22;
  MaxAnisotropy = caps.MaxAnisotropy;
  pCaps->m_NumSamplers = 16;
  pCaps->m_SupportsCompressedTextures = COMPRESSED_TEXTURES_ON;
  if ( ((pCaps_3b | v22) & 0x10) == 0 )
    MaxAnisotropy = 1;
  pCaps->m_nMaxAnisotropy = MaxAnisotropy;
  if ( (*((_BYTE *)pCaps + 718) & 0x10) != 0 )
  {
    pCaps->m_NumVertexShaderConstants = 256;
    pCaps->m_NumBooleanVertexShaderConstants = 16;
    pCaps->m_NumBooleanPixelShaderConstants = 16;
    pCaps->m_NumIntegerVertexShaderConstants = 16;
    pCaps->m_NumIntegerPixelShaderConstants = 16;
  }
  else
  {
    pCaps->m_NumVertexShaderConstants = caps.MaxVertexShaderConst;
    v25 = _CommandLine(a1: 16);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v25 + 40))(a1: v25, a2: "-limitvsconst") != 0 )
    {
      m_NumVertexShaderConstants = pCaps->m_NumVertexShaderConstants;
      if ( m_NumVertexShaderConstants > 256 )
        m_NumVertexShaderConstants = 256;
      pCaps->m_NumVertexShaderConstants = m_NumVertexShaderConstants;
    }
    pCaps->m_NumBooleanVertexShaderConstants = 16;
    pCaps->m_NumBooleanPixelShaderConstants = 16;
    pCaps->m_NumIntegerVertexShaderConstants = 16;
    pCaps->m_NumIntegerPixelShaderConstants = 16;
  }
  LOBYTE(v23) = *((_BYTE *)pCaps + 716);
  pCaps->m_NumPixelShaderConstants = (v23 & 8) != 0 ? 224 : 32;
  MaxActiveLights = caps.MaxActiveLights;
  pCaps->m_MaxNumLights = caps.MaxActiveLights;
  if ( MaxActiveLights > 4 )
    pCaps->m_MaxNumLights = 4;
  if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    pCaps->m_MaxNumLights = 2 * bGLSLControlFlow + 2;
  if ( (*((_BYTE *)pCaps + 718) & 0x10) != 0 )
    pCaps->m_MaxNumLights = 2;
  MaxVolumeExtent = caps.MaxVolumeExtent;
  MaxTextureWidth = caps.MaxTextureWidth;
  MaxTextureHeight = caps.MaxTextureHeight;
  pCaps->m_MaxTextureWidth = caps.MaxTextureWidth;
  pCaps->m_MaxTextureHeight = MaxTextureHeight;
  if ( MaxVolumeExtent == 0 )
    MaxVolumeExtent = 1;
  pCaps->m_MaxTextureDepth = MaxVolumeExtent;
  MaxTextureAspectRatio = caps.MaxTextureAspectRatio;
  pCaps->m_MaxTextureAspectRatio = caps.MaxTextureAspectRatio;
  if ( MaxTextureAspectRatio == 0 )
  {
    v32 = MaxTextureWidth;
    if ( MaxTextureWidth <= MaxTextureHeight )
      v32 = MaxTextureHeight;
    pCaps->m_MaxTextureAspectRatio = v32;
  }
  MaxPrimitiveCount = caps.MaxPrimitiveCount;
  v34 = *((_BYTE *)pCaps + 719);
  *((_BYTE *)pCaps + 717) &= 0xCFu;
  pCaps->m_MaxPrimitiveCount = MaxPrimitiveCount;
  RasterCaps = caps.RasterCaps;
  *((_BYTE *)pCaps + 719) = v34 & 7 | 0x60;
  v36 = (RasterCaps & 0x4000000) != 0 && (RasterCaps & 0x2000000) != 0;
  LOBYTE(v23) = v23 & 0x7F;
  *((_BYTE *)pCaps + 716) = v23 | (v36 << 7);
  pCaps->m_MaxUserClipPlanes = caps.MaxUserClipPlanes;
  v37 = _CommandLine(a1: v23);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v37 + 12))(a1: v37, a2: "-nouserclip", a3: 0) != 0 )
    pCaps->m_MaxUserClipPlanes = 0;
  if ( pCaps->m_MaxUserClipPlanes > 6 )
    pCaps->m_MaxUserClipPlanes = 6;
  *((_BYTE *)pCaps + 720) = *((_BYTE *)pCaps + 720) & 0xF1 | 4;
  LOBYTE(v38) = (*((_BYTE *)pCaps + 717)
               ^ (4
                * (this->m_pD3D->CheckDeviceFormat(
                     this: this->m_pD3D,
                     a2: nAdapter,
                     a3: D3DDEVTYPE_HAL,
                     a4: D3DFMT_X8R8G8B8,
                     a5: 0x10000u,
                     a6: D3DRTYPE_TEXTURE,
                     a7: D3DFMT_DXT1) == 0)))
              & 4;
  *((_BYTE *)pCaps + 717) ^= v38;
  if ( (*((_BYTE *)pCaps + 717) & 4) != 0 )
  {
    LOBYTE(v38) = (*((_BYTE *)pCaps + 717)
                 ^ (4
                  * (this->m_pD3D->CheckDeviceFormat(
                       this: this->m_pD3D,
                       a2: nAdapter,
                       a3: D3DDEVTYPE_HAL,
                       a4: D3DFMT_X8R8G8B8,
                       a5: 327680u,
                       a6: D3DRTYPE_TEXTURE,
                       a7: D3DFMT_A8R8G8B8) == 0)))
                & 4;
    *((_BYTE *)pCaps + 717) ^= v38;
  }
  v39 = _CommandLine(a1: v38);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v39 + 12))(a1: v39, a2: "-nosrgb", a3: 0) != 0 )
    *((_BYTE *)pCaps + 717) &= ~4u;
  *((_BYTE *)pCaps + 716) ^= (*((_BYTE *)pCaps + 716)
                            ^ ((this->m_pD3D->CheckDeviceFormat(
                                  this: this->m_pD3D,
                                  a2: nAdapter,
                                  a3: D3DDEVTYPE_HAL,
                                  a4: D3DFMT_X8R8G8B8,
                                  a5: 0x100000u,
                                  a6: D3DRTYPE_TEXTURE,
                                  a7: D3DFMT_R32F) == 0) << 6))
                           & 0x40;
  if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    *((_BYTE *)pCaps + 716) &= ~0x40u;
  v40 = (*((_BYTE *)pCaps + 716) & 0x40) != 0;
  pCaps->m_nMaxVertexTextureDimension = v40 << 12;
  pCaps->m_NumVertexSamplers = 4 * v40;
  v41 = this->m_pD3D->CheckDeviceFormat(
          this: this->m_pD3D,
          a2: nAdapter,
          a3: D3DDEVTYPE_HAL,
          a4: D3DFMT_X8R8G8B8,
          a5: 0x20000u,
          a6: D3DRTYPE_TEXTURE,
          a7: D3DFMT_A16B16G16R16);
  CheckDeviceFormat = this->m_pD3D->CheckDeviceFormat;
  m_pD3D = this->m_pD3D;
  bSupportsInteger16Textures = v41 == 0;
  v43 = CheckDeviceFormat(
          this: m_pD3D,
          a2: nAdapter,
          a3: D3DDEVTYPE_HAL,
          a4: D3DFMT_X8R8G8B8,
          a5: 0x20000u,
          a6: D3DRTYPE_TEXTURE,
          a7: D3DFMT_A16B16G16R16F);
  v44 = this->m_pD3D->CheckDeviceFormat;
  v62 = this->m_pD3D;
  bGLSLControlFlow = v43 == 0;
  v45 = v44(
          this: v62,
          a2: nAdapter,
          a3: D3DDEVTYPE_HAL,
          a4: D3DFMT_X8R8G8B8,
          a5: 524289u,
          a6: D3DRTYPE_TEXTURE,
          a7: D3DFMT_A16B16G16R16F);
  v46 = this->m_pD3D->CheckDeviceFormat;
  v63 = this->m_pD3D;
  bSupportsFloat16RenderTargets = v45 == 0;
  v47 = v46(
          this: v63,
          a2: nAdapter,
          a3: D3DDEVTYPE_HAL,
          a4: D3DFMT_X8R8G8B8,
          a5: 524289u,
          a6: D3DRTYPE_TEXTURE,
          a7: D3DFMT_A32B32G32R32F);
  *((_BYTE *)pCaps + 717) &= ~0x80u;
  v48 = *((_BYTE *)pCaps + 718);
  v49 = *((_BYTE *)pCaps + 717);
  *((_BYTE *)pCaps + 719) &= 0xFCu;
  v50 = v48 & 0xBE | ((v47 == 0) << 6);
  v51 = *((_BYTE *)pCaps + 719);
  *((_BYTE *)pCaps + 718) = v50;
  v66 = v51;
  if ( (v49 & 4) != 0 )
  {
    m_VendorID = pCaps->m_VendorID;
    switch ( m_VendorID )
    {
      case 0x10DEu:
        *((_BYTE *)pCaps + 717) = v49 | 0x80;
        if ( (v50 & 0x40) == 0 )
          goto LABEL_82;
        v53 = v50 | 1;
        *((_BYTE *)pCaps + 719) = v51 | 3;
        goto LABEL_81;
      case 0x1002u:
        if ( (*((_BYTE *)pCaps + 716) & 8) == 0
          || pCaps->m_MaxVertexShader30InstructionSlots <= 1024
          || (pCaps_3 = 1, pCaps->m_MaxPixelShader30InstructionSlots <= 512) )
        {
          pCaps_3 = 0;
        }
        v54 = v66 ^ (pCaps_3 ^ v51) & 1 ^ (v66 ^ (pCaps_3 ^ v51) & 1 ^ (2 * (v66 ^ (pCaps_3 ^ v51) & 1))) & 2;
        break;
      case 0x8086u:
        pCaps_3a = v51 & 0xFE;
        *((_BYTE *)pCaps + 719) = v51 & 0xFE;
        m_DeviceID = pCaps->m_DeviceID;
        v56 = m_DeviceID >= 0x29A2 && m_DeviceID <= 0x2A43 || m_DeviceID >= 0x42 && m_DeviceID <= 0x2500;
        v54 = pCaps_3a ^ (pCaps_3a ^ (2 * v56)) & 2;
        break;
      default:
        goto LABEL_82;
    }
    *((_BYTE *)pCaps + 719) = v54;
    if ( (v54 & 2) != 0 )
    {
      v53 = v50 | 1;
      *((_BYTE *)pCaps + 717) = v49 | 0x80;
LABEL_81:
      *((_BYTE *)pCaps + 718) = v53;
    }
  }
LABEL_82:
  v57 = (bSupportsInteger16Textures || bGLSLControlFlow) && (*((_BYTE *)pCaps + 717) & 4) != 0;
  v58 = (*((_BYTE *)pCaps + 716) & 8) != 0
     && bGLSLControlFlow
     && bSupportsFloat16RenderTargets
     && (*((_BYTE *)pCaps + 717) & 4) != 0;
  pCaps->m_MaxHDRType = HDR_TYPE_NONE;
  if ( v58 )
  {
    pCaps->m_MaxHDRType = HDR_TYPE_FLOAT;
    if ( mat_hdr_level.m_pParent != nullptr && mat_hdr_level.m_pParent->m_Value.m_nValue == 3 )
    {
      pCaps->m_HDRType = HDR_TYPE_FLOAT;
      goto LABEL_102;
    }
  }
  else
  {
    if ( !v57 )
      goto LABEL_101;
    pCaps->m_MaxHDRType = HDR_TYPE_INTEGER;
  }
  if ( v57 )
  {
    pCaps->m_HDRType = HDR_TYPE_INTEGER;
    goto LABEL_102;
  }
LABEL_101:
  pCaps->m_HDRType = HDR_TYPE_NONE;
LABEL_102:
  *((_BYTE *)pCaps + 717) ^= (*((_BYTE *)pCaps + 717) ^ (LOBYTE(caps.DevCaps2) << 6)) & 0x40;
  if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    *((_BYTE *)pCaps + 717) |= 0x40u;
  pCaps->m_flMinGammaControlPoint = 0.0;
  pCaps->m_flMaxGammaControlPoint = 65535.0;
  pCaps->m_nGammaControlPointCount = 256;
  CShaderDeviceMgrDx8::ComputeDXSupportLevel(this, caps: pCaps);
  pCaps->m_nDXSupportLevel = pCaps->m_nMaxDXSupportLevel;
  v59 = pCaps->m_NumVertexShaderConstants - 58;
  pCaps->m_MaxVertexShaderBlendMatrices = v59 / 3;
  if ( v59 / 3 > 53 )
    pCaps->m_MaxVertexShaderBlendMatrices = 53;
  *((_BYTE *)pCaps + 718) &= ~0x80u;
  pCaps->m_SupportsCompressedVertices = VERTEX_COMPRESSION_ON;
  v60 = _CommandLine(a1: v59);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v60 + 12))(
         a1: v60,
         a2: "-no_compressed_verts",
         a3: 0) != 0 )
    pCaps->m_SupportsCompressedVertices = VERTEX_COMPRESSION_NONE;
  CShaderDeviceMgrDx8::CheckVendorDependentAlphaToCoverage(this, a2: nAdapter, pCaps, nAdapter);
  CShaderDeviceMgrDx8::CheckVendorDependentShadowMappingSupport(this, pCaps, nAdapter);
  if ( (*((_BYTE *)pCaps + 716) & 8) == 0 )
  {
    ConVar::SetValue(this: (ConVar *)&mat_slopescaledepthbias_shadowmap.IConVar, value: 5.9000001);
    ConVar::SetValue(this: (ConVar *)&mat_depthbias_shadowmap.IConVar, value: 0.003);
  }
  if ( pCaps->m_MaxUserClipPlanes == 0 )
    *((_BYTE *)pCaps + 717) |= 8u;
  pCaps->m_MaxSimultaneousRenderTargets = caps.NumSimultaneousRTs;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027930
// Name: protected: bool CShaderDeviceDx8::CreateD3DDevice(void __near *,int,struct ShaderDeviceInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceDx8::CreateD3DDevice(
        CShaderDeviceDx8 *this,
        HWND__ *pHWnd,
        nv::stereo::HL2Stereo<nv::stereo::D3D9Type> *nAdapter,
        const ShaderDeviceInfo_t *info)
{
  int v7; // eax
  _DWORD *v8; // ebx
  IDirect3DDevice9 *v9; // eax
  IUnknown *v10; // ebx
  D3DDeviceWrapper *v11; // eax
  char v12; // cl
  char v13; // al
  bool v14; // al
  void (__thiscall *GetWindowSize)(struct CShaderDeviceDx8 *, int *, int *); // eax
  CShaderDeviceMgrBase::AdapterInfo_t *HardwareCaps; // eax
  ImageFormat m_Format; // [esp-4h] [ebp-158h]
  _D3DCAPS9 caps; // [esp+8h] [ebp-14Ch] BYREF
  ShaderDisplayMode_t mode; // [esp+138h] [ebp-1Ch] BYREF
  unsigned int deviceCreationFlags; // [esp+150h] [ebp-4h]
  nv::stereo::HL2Stereo<nv::stereo::D3D9Type> *pStereoD3D9; // [esp+160h] [ebp+Ch]

  D3DPERF_SetOptions(a1: 1);
  if ( g_pShaderDeviceMgrDx8->m_pD3D->GetDeviceCaps(
         this: g_pShaderDeviceMgrDx8->m_pD3D,
         a2: (unsigned int)nAdapter,
         a3: D3DDEVTYPE_HAL,
         a4: &caps) < 0 )
    return 0;
  memset(&mode.m_nWidth, 0, 20);
  mode.m_nVersion = 1;
  g_pShaderDeviceMgrDx8->GetCurrentModeInfo(this: g_pShaderDeviceMgrDx8, a2: &mode, a3: (int)nAdapter);
  m_Format = mode.m_Format;
  this->m_AdapterFormat = mode.m_Format;
  InitializeColorInformation(displayAdapter: (int)nAdapter, deviceType: D3DDEVTYPE_HAL, displayFormat: m_Format);
  if ( (*((_BYTE *)&CShaderDeviceMgrBase::GetHardwareCaps(this: &g_ShaderDeviceMgrDx8, (int)nAdapter)->m_ActualCaps + 718)
      & 0x10) != 0 )
  {
    v7 = 32;
  }
  else
  {
    v7 = 64;
    if ( (caps.DevCaps & 0x100000) != 0 )
      v7 = 80;
  }
  deviceCreationFlags = v7 | 2;
  CShaderDeviceDx8::SetPresentParameters(this, hWnd: pHWnd, (int)nAdapter, info, bSetSymbolsOnly: IMAGE_FORMAT_RGBA8888);
  CShaderDeviceBase::SendIPCMessage(this, msg: 1584664032);
  v8 = operator new(nSize: 0x14u);
  if ( v8 != nullptr )
  {
    *v8 = 0;
    v8[1] = 0;
    v8[2] = 0;
    v8[3] = 0;
    *((_WORD *)v8 + 8) = 0;
    *((_BYTE *)v8 + 18) = 1;
    NvAPI_Initialize();
    NvAPI_Stereo_CreateConfigurationProfileRegistryKey(registryProfileType: NVAPI_STEREO_DX9_REGISTRY_PROFILE);
    pStereoD3D9 = (nv::stereo::HL2Stereo<nv::stereo::D3D9Type> *)v8;
  }
  else
  {
    pStereoD3D9 = nullptr;
  }
  v9 = CShaderDeviceDx8::InvokeCreateDevice(this, hWnd: pHWnd, (unsigned int)nAdapter, deviceCreationFlags);
  v10 = v9;
  if ( v9 != nullptr )
  {
    CShaderDeviceDx8::DetectQuerySupport(this, pD3DDevice: v9);
    NvAPI_Stereo_CreateHandleFromIUnknown(pDevice: v10, pStereoHandle: &pStereoD3D9->mStereoHandle);
    pStereoD3D9->mInitialized = true;
    v11 = Dx9Device();
    v11->m_pD3DDevice = (IDirect3DDevice9 *)v10;
    v11->m_pPresentParameters = &this->m_PresentParameters;
    v11->m_pHWnd = pHWnd;
    Dx9Device()->m_pStereoTexUpdater = pStereoD3D9;
    CShaderDeviceBase::SendIPCMessage(this, msg: 1584664033);
    *((_BYTE *)this + 172) &= ~2u;
    *((_BYTE *)&this->CShaderDeviceBase + 16) &= ~2u;
    v12 = *((_BYTE *)this + 172);
    this->m_hWnd = pHWnd;
    this->m_DisplayAdapter = (unsigned int)nAdapter;
    this->m_nAdapter = (int)nAdapter;
    this->m_DeviceState = DEVICE_STATE_OK;
    v13 = *((_BYTE *)info + 52);
    v14 = (v13 & 1) != 0 && (v13 & 2) != 0;
    *((_BYTE *)this + 172) = v12 ^ (v12 ^ (4 * v14)) & 4;
    GetWindowSize = this->GetWindowSize;
    this->m_ViewHWnd = pHWnd;
    GetWindowSize(this, a2: &this->m_nWindowWidth, a3: &this->m_nWindowHeight);
    HardwareCaps = CShaderDeviceMgrBase::GetHardwareCaps(this: &g_ShaderDeviceMgrDx8, (int)nAdapter);
    CHardwareConfig::SetupHardwareCaps(this: g_pHardwareConfig, mode: info, actualCaps: &HardwareCaps->m_ActualCaps);
    g_pHardwareConfig->m_Caps.m_SupportsCompressedTextures = COMPRESSED_TEXTURES_ON;
    return 1;
  }
  else
  {
    if ( pStereoD3D9 != nullptr )
    {
      if ( pStereoD3D9->mStereoHandle != nullptr )
      {
        NvAPI_Stereo_DestroyHandle(stereoHandle: pStereoD3D9->mStereoHandle);
        pStereoD3D9->mStereoHandle = nullptr;
      }
      free(pMem: pStereoD3D9);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027B70
// Name: protected: void CShaderDeviceDx8::AllocFrameSyncTextureObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::AllocFrameSyncTextureObject(CShaderDeviceDx8 *this)
{
  IDirect3DTexture9 *m_pFrameSyncTexture; // eax
  IDirect3DTexture9 **p_m_pFrameSyncTexture; // esi
  D3DDeviceWrapper *v3; // edi

  m_pFrameSyncTexture = this->m_pFrameSyncTexture;
  p_m_pFrameSyncTexture = &this->m_pFrameSyncTexture;
  if ( m_pFrameSyncTexture != nullptr )
  {
    m_pFrameSyncTexture->Release(this: m_pFrameSyncTexture);
    *p_m_pFrameSyncTexture = nullptr;
  }
  v3 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v3);
  if ( v3->m_pD3DDevice->CreateTexture(
         this: v3->m_pD3DDevice,
         a2: 1u,
         a3: 1u,
         a4: 0,
         a5: 512u,
         a6: D3DFMT_A8R8G8B8,
         a7: D3DPOOL_DEFAULT,
         a8: p_m_pFrameSyncTexture,
         a9: nullptr) < 0 )
    *p_m_pFrameSyncTexture = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10027BD0
// Name: protected: void CShaderDeviceDx8::AllocFrameSyncObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::AllocFrameSyncObjects(CShaderDeviceDx8 *this)
{
  unsigned int v1; // ebx
  unsigned int v3; // eax
  IDirect3DQuery9 **v4; // ecx
  IDirect3DQuery9 **m_pFrameSyncQueryObject; // edi
  D3DDeviceWrapper *v6; // esi

  v1 = 0;
  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: CShaderAPIDX8::AllocFrameSyncObjects\n");
  CShaderDeviceDx8::AllocFrameSyncTextureObject(this);
  if ( this->m_DeviceSupportsCreateQuery != 0 )
  {
    m_pFrameSyncQueryObject = this->m_pFrameSyncQueryObject;
    do
    {
      v6 = Dx9Device();
      D3DDeviceWrapper::Synchronize(this: v6);
      if ( v6->m_pD3DDevice->CreateQuery(this: v6->m_pD3DDevice, a2: D3DQUERYTYPE_EVENT, a3: m_pFrameSyncQueryObject) == -2005530518 )
      {
        _Warning(a1: "D3DQUERYTYPE_EVENT not available on this driver\n");
      }
      else
      {
        (*m_pFrameSyncQueryObject)->Issue(this: *m_pFrameSyncQueryObject, a2: 1u);
        this->m_bQueryIssued[v1] = true;
      }
      ++v1;
      ++m_pFrameSyncQueryObject;
    }
    while ( v1 < 2 );
  }
  else
  {
    v3 = 0;
    v4 = this->m_pFrameSyncQueryObject;
    do
    {
      *v4 = nullptr;
      this->m_bQueryIssued[v3++] = false;
      ++v4;
    }
    while ( v3 < 2 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027C90
// Name: protected: void CShaderDeviceDx8::FreeFrameSyncObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::FreeFrameSyncObjects(CShaderDeviceDx8 *this)
{
  unsigned int v1; // ebx
  CShaderDeviceDx8 *v2; // edi
  IDirect3DTexture9 *m_pFrameSyncTexture; // eax
  IDirect3DQuery9 **m_pFrameSyncQueryObject; // esi
  int v5; // edi
  double flStartTime; // [esp+Ch] [ebp-10h]
  int dummyData; // [esp+18h] [ebp-4h] BYREF

  v1 = 0;
  v2 = this;
  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: CShaderAPIDX8::FreeFrameSyncObjects\n");
  m_pFrameSyncTexture = v2->m_pFrameSyncTexture;
  if ( m_pFrameSyncTexture != nullptr )
  {
    m_pFrameSyncTexture->Release(this: v2->m_pFrameSyncTexture);
    v2->m_pFrameSyncTexture = nullptr;
  }
  m_pFrameSyncQueryObject = v2->m_pFrameSyncQueryObject;
  do
  {
    if ( *m_pFrameSyncQueryObject != nullptr )
    {
      if ( v2->m_bQueryIssued[v1] )
      {
        flStartTime = _Plat_FloatTime();
        dummyData = 0;
        do
          v5 = (*m_pFrameSyncQueryObject)->GetData(this: *m_pFrameSyncQueryObject, a2: &dummyData, a3: 4u, a4: 1u);
        while ( _Plat_FloatTime() - flStartTime <= 2.0 && v5 == 1 );
        v2 = this;
      }
      (*m_pFrameSyncQueryObject)->Release(this: *m_pFrameSyncQueryObject);
      *m_pFrameSyncQueryObject = nullptr;
      v2->m_bQueryIssued[v1] = false;
    }
    ++v1;
    ++m_pFrameSyncQueryObject;
  }
  while ( v1 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x10027D60
// Name: public: virtual void CShaderDeviceDx8::ReleaseResources(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::ReleaseResources(CShaderDeviceDx8 *this, BOOL bReleaseManagedResources)
{
  int m_numReleaseResourcesRefCount; // eax
  CMeshMgr *v4; // eax

  if ( CShaderDeviceBase::ThreadOwnsDevice(this) && (unsigned __int8)_ThreadInMainThread() != 0 )
  {
    m_numReleaseResourcesRefCount = this->m_numReleaseResourcesRefCount;
    this->m_numReleaseResourcesRefCount = m_numReleaseResourcesRefCount + 1;
    if ( m_numReleaseResourcesRefCount != 0 )
    {
      _Warning(a1: "ReleaseResources has no effect, now at level %d.\n", m_numReleaseResourcesRefCount + 1);
      DevWarning(a1: "ReleaseResources called twice is a bug: use IsDeactivated to check for a valid device.\n");
    }
    else
    {
      if ( g_pShaderAPI != nullptr )
      {
        g_pShaderAPI->BeginPIXEvent(this: g_pShaderAPI, a2: -682993u, a3: "ReleaseResources");
        if ( g_pShaderAPI != nullptr )
          g_pShaderAPI->EndPIXEvent(this: g_pShaderAPI);
      }
      CShaderDeviceDx8::FreeFrameSyncObjects(this);
      CShaderDeviceDx8::FreeNonInteractiveRefreshObjects(this);
      g_pShaderUtil->ReleaseShaderObjects(this: g_pShaderUtil, a2: bReleaseManagedResources ? 2 : 0);
      v4 = MeshMgr();
      v4->ReleaseBuffers(this: v4);
      g_pShaderAPI->ReleaseShaderObjects(this: g_pShaderAPI, a2: bReleaseManagedResources);
      *((_BYTE *)this + 172) |= 0x20u;
    }
  }
  else
  {
    *((_BYTE *)this + 172) &= ~0x20u;
    g_pShaderUtil->OnThreadEvent(this: g_pShaderUtil, a2: 1u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027E60
// Name: protected: void CShaderDeviceDx8::ReacquireResourcesInternal(bool,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::ReacquireResourcesInternal(
        CShaderDeviceDx8 *this,
        bool bResetState,
        bool bForceReacquire,
        const char *pszForceReason)
{
  const char *v5; // ecx
  CShaderAPIBase *v6; // ecx
  CMeshMgr *v7; // eax

  if ( CShaderDeviceBase::ThreadOwnsDevice(this) && (unsigned __int8)_ThreadInMainThread() != 0 )
  {
    if ( bForceReacquire )
    {
      if ( this->m_numReleaseResourcesRefCount > 1 )
      {
        v5 = pszForceReason;
        if ( pszForceReason == nullptr )
          v5 = "unspecified";
        _Warning(
          a1: "Forcefully resetting device (%s), resources release level was %d.\n",
          v5,
          this->m_numReleaseResourcesRefCount);
      }
      this->m_numReleaseResourcesRefCount = 0;
      goto LABEL_9;
    }
    if ( this->m_numReleaseResourcesRefCount-- == 1 )
    {
LABEL_9:
      if ( bResetState )
        this->ResetRenderState(this, a2: true);
      v6 = g_pShaderAPI;
      if ( g_pShaderAPI != nullptr )
      {
        g_pShaderAPI->BeginPIXEvent(this: g_pShaderAPI, a2: -682993u, a3: "ReacquireResources");
        v6 = g_pShaderAPI;
      }
      v6->RestoreShaderObjects(this: v6);
      CShaderDeviceDx8::AllocFrameSyncObjects(this);
      v7 = MeshMgr();
      v7->RestoreBuffers(this: v7);
      g_pShaderUtil->RestoreShaderObjects(
        this: g_pShaderUtil,
        a2: (void *(__cdecl *)(const char *, int *))CShaderDeviceMgrBase::ShaderInterfaceFactory,
        a3: 0);
      if ( g_pShaderAPI != nullptr )
        g_pShaderAPI->EndPIXEvent(this: g_pShaderAPI);
      return;
    }
    _Warning(a1: "ReacquireResources has no effect, now at level %d.\n", this->m_numReleaseResourcesRefCount);
    DevWarning(a1: "ReacquireResources being discarded is a bug: use IsDeactivated to check for a valid device.\n");
    if ( this->m_numReleaseResourcesRefCount < 0 )
      this->m_numReleaseResourcesRefCount = 0;
  }
  else
  {
    if ( bResetState )
      g_pShaderUtil->OnThreadEvent(this: g_pShaderUtil, a2: 7u);
    g_pShaderUtil->OnThreadEvent(this: g_pShaderUtil, a2: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027FC0
// Name: protected: bool CShaderDeviceDx8::ResizeWindow(struct ShaderDeviceInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceDx8::ResizeWindow(CShaderDeviceDx8 *this, const ShaderDeviceInfo_t *info)
{
  D3DDeviceWrapper *v3; // ebx
  int v4; // eax

  *((_BYTE *)this + 172) &= ~8u;
  if ( (*((_BYTE *)info + 52) & 2) != 0 )
    return 0;
  CShaderDeviceDx8::SetPresentParameters(
    this,
    hWnd: (HWND__ *)this->m_hWnd,
    nAdapter: this->m_DisplayAdapter,
    info,
    bSetSymbolsOnly: IMAGE_FORMAT_ABGR8888);
  CShaderDeviceMgrBase::InvokeModeChangeCallbacks(
    this: g_pShaderDeviceMgr,
    screenWidth: this->m_PresentParameters.BackBufferWidth,
    screenHeight: this->m_PresentParameters.BackBufferHeight);
  this->ReleaseResources(this, a2: true);
  CShaderDeviceDx8::SetPresentParameters(
    this,
    hWnd: (HWND__ *)this->m_hWnd,
    nAdapter: this->m_DisplayAdapter,
    info,
    bSetSymbolsOnly: IMAGE_FORMAT_RGBA8888);
  v3 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v3);
  v4 = v3->m_pD3DDevice->Reset(this: v3->m_pD3DDevice, a2: &this->m_PresentParameters);
  if ( v4 < 0 )
  {
    _Warning(a1: "ResizeWindow: Reset failed, hr = 0x%08X.\n", v4);
    return 0;
  }
  CShaderDeviceDx8::ReacquireResourcesInternal(
    this,
    bResetState: true,
    bForceReacquire: true,
    pszForceReason: "ResizeWindow");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028070
// Name: protected: void CShaderDeviceDx8::CheckDeviceLost(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::CheckDeviceLost(CShaderDeviceDx8 *this, bool bOtherAppInitializing)
{
  BOOL v3; // eax
  char v4; // dl
  D3DDeviceWrapper *v5; // edi
  int v6; // edi
  char v7; // al
  bool bReleaseManagedResources; // [esp+Ch] [ebp-4h]

  v3 = IsIconic(hWnd: (HWND)this->m_hWnd);
  v4 = bOtherAppInitializing ^ *((_BYTE *)this + 172);
  *((_BYTE *)&this->CShaderDeviceBase + 16) ^= (*((_BYTE *)&this->CShaderDeviceBase + 16) ^ (2 * v3)) & 2;
  *((_BYTE *)this + 172) ^= v4 & 1;
  v5 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v5);
  v6 = v5->m_pD3DDevice->TestCooperativeLevel(this: v5->m_pD3DDevice);
  v7 = *((_BYTE *)this + 172);
  if ( (v7 & 2) != 0 )
  {
    if ( v6 == 0 )
      v6 = -2005530519;
    *((_BYTE *)this + 172) = v7 & 0xFD;
  }
  if ( this->m_DeviceState == DEVICE_STATE_OK )
  {
    bReleaseManagedResources = g_pShaderUtil->GetThreadMode(this: g_pShaderUtil) != MATERIAL_QUEUED_THREADED;
    if ( v6 != 0 || (*((_BYTE *)&this->CShaderDeviceBase + 16) & 2) != 0 )
    {
      g_pShaderUtil->UncacheUnusedMaterials(this: g_pShaderUtil, a2: true);
      g_pShaderDeviceMgr->InvokeDeviceLostNotifications(this: g_pShaderDeviceMgr);
      this->ReleaseResources(this, a2: bReleaseManagedResources);
      this->m_DeviceState = DEVICE_STATE_LOST_DEVICE;
    }
    else if ( bOtherAppInitializing )
    {
      g_pShaderUtil->UncacheUnusedMaterials(this: g_pShaderUtil, a2: true);
      g_pShaderDeviceMgr->InvokeDeviceLostNotifications(this: g_pShaderDeviceMgr);
      this->ReleaseResources(this, a2: bReleaseManagedResources);
      this->m_DeviceState = DEVICE_STATE_OTHER_APP_INIT;
    }
  }
  if ( this->m_DeviceState == DEVICE_STATE_LOST_DEVICE
    && (*((_BYTE *)&this->CShaderDeviceBase + 16) & 2) == 0
    && v6 != -2005530520 )
  {
    this->m_DeviceState = DEVICE_STATE_NEEDS_RESET;
  }
  if ( this->m_DeviceState == DEVICE_STATE_NEEDS_RESET )
  {
    if ( v6 == -2005530520 || (*((_BYTE *)&this->CShaderDeviceBase + 16) & 2) != 0 )
    {
      this->m_DeviceState = DEVICE_STATE_LOST_DEVICE;
    }
    else if ( CShaderDeviceDx8::TryDeviceReset(this) )
    {
      if ( bOtherAppInitializing )
      {
        this->m_DeviceState = DEVICE_STATE_OTHER_APP_INIT;
      }
      else
      {
        this->m_DeviceState = DEVICE_STATE_OK;
        CShaderDeviceDx8::ReacquireResourcesInternal(
          this,
          bResetState: true,
          bForceReacquire: true,
          pszForceReason: "NeedsReset");
      }
    }
  }
  if ( this->m_DeviceState == DEVICE_STATE_OTHER_APP_INIT )
  {
    if ( v6 != 0 || (*((_BYTE *)&this->CShaderDeviceBase + 16) & 2) != 0 )
    {
      this->m_DeviceState = DEVICE_STATE_LOST_DEVICE;
    }
    else if ( !bOtherAppInitializing )
    {
      this->m_DeviceState = DEVICE_STATE_OK;
      CShaderDeviceDx8::ReacquireResourcesInternal(
        this,
        bResetState: true,
        bForceReacquire: true,
        pszForceReason: "OtherAppInit");
    }
  }
  if ( (*((_BYTE *)this + 172) & 8) != 0 && !this->IsDeactivated(this) )
  {
    g_pShaderUtil->UncacheUnusedMaterials(this: g_pShaderUtil, a2: true);
    CShaderDeviceDx8::ResizeWindow(this, info: &this->m_PendingVideoModeChangeConfig);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028270
// Name: protected: void CShaderDeviceDx8::UpdatePresentStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::UpdatePresentStats(CShaderDeviceDx8 *this)
{
  float v2; // xmm0_4
  float m_flTotalDt; // xmm1_4
  float flActualDta; // [esp+4h] [ebp-4h]
  float flActualDt; // [esp+4h] [ebp-4h]

  flActualDta = _Plat_FloatTime();
  flActualDt = flActualDta - this->m_NonInteractiveRefresh.m_flLastPresentTime;
  v2 = flActualDt;
  if ( flActualDt > this->m_NonInteractiveRefresh.m_flPeakDt )
    this->m_NonInteractiveRefresh.m_flPeakDt = flActualDt;
  if ( flActualDt > 0.066 )
  {
    ++this->m_NonInteractiveRefresh.m_nCountAbove66;
    if ( mat_spew_long_frames.m_pParent != nullptr && mat_spew_long_frames.m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(a1: "****LONG FRAME: %04d>66ms\n", (int)(float)(flActualDt * 1000.0));
      v2 = flActualDt;
    }
  }
  m_flTotalDt = this->m_NonInteractiveRefresh.m_flTotalDt;
  ++this->m_NonInteractiveRefresh.m_nSamples;
  this->m_NonInteractiveRefresh.m_flTotalDt = m_flTotalDt + v2;
  this->m_NonInteractiveRefresh.m_flLastPresentTime = _Plat_FloatTime();
}

//------------------------------------------------------------------------------
// Address: 0x10028310
// Name: public: virtual void CShaderDeviceDx8::Present(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::Present(CShaderDeviceDx8 *this)
{
  D3DDeviceWrapper *v2; // eax
  D3DDeviceWrapper *v3; // esi
  unsigned int *m_pOutputPtr; // eax
  int v5; // esi
  bool v6; // bl
  D3DDeviceWrapper *v7; // eax
  D3DDeviceWrapper *v8; // esi
  unsigned int *v9; // ecx
  int v10; // eax
  HWND__ *m_ViewHWnd; // eax
  D3DDeviceWrapper *v12; // eax
  CMeshMgr *v13; // eax
  D3DDeviceWrapper *v14; // eax
  D3DDeviceWrapper *v15; // esi
  unsigned int *v16; // eax
  HWND__ *v17; // [esp-Ch] [ebp-54h]
  ShaderViewport_t viewport; // [esp+8h] [ebp-40h] BYREF
  tagRECT destRect; // [esp+24h] [ebp-24h] BYREF
  tagRECT srcRect; // [esp+34h] [ebp-14h] BYREF
  bool bInMainThread; // [esp+47h] [ebp-1h]

  g_pShaderAPI->OnPresent(this: g_pShaderAPI);
  if ( !this->IsDeactivated(this) )
  {
    v2 = Dx9Device();
    v3 = v2;
    if ( v2->m_pASyncThreadHandle != nullptr )
    {
      if ( v2->m_PushBufferFreeSlots == 0 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v2);
      m_pOutputPtr = v3->m_pOutputPtr;
      --v3->m_PushBufferFreeSlots;
      *m_pOutputPtr = 24;
      ++v3->m_pOutputPtr;
    }
    else
    {
      v2->m_pD3DDevice->EndScene(this: v2->m_pD3DDevice);
    }
  }
  v5 = 0;
  v6 = true;
  bInMainThread = _ThreadInMainThread();
  if ( !bInMainThread )
  {
    v6 = this->m_DeviceState == DEVICE_STATE_OK;
    CShaderDeviceDx8::CheckDeviceLost(this, bOtherAppInitializing: *((_BYTE *)this + 172) & 1);
    if ( this->m_DeviceState != DEVICE_STATE_OK )
      v6 = false;
  }
  if ( this->m_NonInteractiveRefresh.m_Mode == MATERIAL_NON_INTERACTIVE_MODE_LEVEL_LOAD )
    g_pShaderAPI->CopyRenderTargetToTextureEx(
      this: g_pShaderAPI,
      a2: this->m_NonInteractiveRefresh.m_Info.m_hTempFullscreenTexture,
      a3: 0,
      a4: nullptr,
      a5: nullptr);
  if ( !IsIconic(hWnd: (HWND)this->m_hWnd) && v6 )
  {
    if ( (*((_BYTE *)this + 172) & 4) != 0 || this->m_ViewHWnd != this->m_hWnd )
    {
      GetClientRect(hWnd: (HWND)this->m_ViewHWnd, lpRect: &destRect);
      viewport.m_nVersion = 1;
      g_pShaderAPI->GetViewports(this: g_pShaderAPI, a2: &viewport, a3: 1);
      srcRect.left = viewport.m_nTopLeftX;
      srcRect.top = viewport.m_nTopLeftY;
      m_ViewHWnd = (HWND__ *)this->m_ViewHWnd;
      srcRect.right = viewport.m_nTopLeftX + viewport.m_nWidth;
      v17 = m_ViewHWnd;
      srcRect.bottom = viewport.m_nTopLeftY + viewport.m_nHeight;
      v12 = Dx9Device();
      v10 = D3DDeviceWrapper::Present(
              this: v12,
              pSourceRect: &srcRect,
              pDestRect: &destRect,
              hDestWindowOverride: v17,
              pDirtyRegion: nullptr);
    }
    else
    {
      g_pShaderAPI->OwnGPUResources(this: g_pShaderAPI, a2: false);
      v7 = Dx9Device();
      v8 = v7;
      if ( v7->m_pASyncThreadHandle != nullptr )
      {
        if ( v7->m_PushBufferFreeSlots < 0x16 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v7);
        v9 = v8->m_pOutputPtr;
        v8->m_PushBufferFreeSlots -= 22;
        *v9 = 25;
        *++v8->m_pOutputPtr = 0;
        v8->m_pOutputPtr += 5;
        *v8->m_pOutputPtr = 0;
        v8->m_pOutputPtr += 5;
        *v8->m_pOutputPtr++ = 0;
        *v8->m_pOutputPtr = 0;
        v8->m_pOutputPtr += 10;
        v5 = 0;
        goto LABEL_23;
      }
      v10 = v7->m_pD3DDevice->Present(this: v7->m_pD3DDevice, a2: nullptr, a3: nullptr, a4: nullptr, a5: nullptr);
    }
    v5 = v10;
  }
LABEL_23:
  CShaderDeviceDx8::UpdatePresentStats(this);
  if ( v5 == -2005530585 )
  {
    _Error(
      a1: "Internal driver error at Present.\n"
      "You're likely out of OS Paged Pool Memory! For more info, see\n"
      "http://support.steampowered.com\n");
  }
  else if ( v5 == -2005530520 )
  {
    *((_BYTE *)this + 172) |= 2u;
  }
  v13 = MeshMgr();
  v13->DiscardVertexBuffers(this: v13);
  if ( bInMainThread )
    CShaderDeviceDx8::CheckDeviceLost(this, bOtherAppInitializing: *((_BYTE *)this + 172) & 1);
  g_pShaderAPI->AdvancePIXFrame(this: g_pShaderAPI);
  if ( !this->IsDeactivated(this) )
  {
    if ( g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bMeasureFillRate
      || g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bVisualizeFillRate )
    {
      g_pShaderAPI->ClearBuffers(this: g_pShaderAPI, a2: true, a3: true, a4: true, a5: -1, a6: -1);
    }
    v14 = Dx9Device();
    v15 = v14;
    if ( v14->m_pASyncThreadHandle != nullptr )
    {
      if ( v14->m_PushBufferFreeSlots == 0 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v14);
      v16 = v15->m_pOutputPtr;
      --v15->m_PushBufferFreeSlots;
      *v16 = 23;
      ++v15->m_pOutputPtr;
    }
    else
    {
      v14->m_pD3DDevice->BeginScene(this: v14->m_pD3DDevice);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100285F0
// Name: public: virtual void CShaderDeviceDx8::SetHardwareGammaRamp(float,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100287F0
// Name: public: void CUtlMemory<struct CShaderDeviceMgrBase::AdapterInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CShaderDeviceMgrBase::AdapterInfo_t,int>::Grow(
        CUtlMemory<CShaderDeviceMgrBase::AdapterInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CShaderDeviceMgrBase::AdapterInfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 728 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CShaderDeviceMgrBase::AdapterInfo_t *)_g_pMemAlloc->Realloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: m_pMemory,
                                                                 a3: v7);
    else
      this->m_pMemory = (CShaderDeviceMgrBase::AdapterInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028890
// Name: public: virtual void __near * (*CShaderDeviceMgrDx8::SetMode(void __near *,int,struct ShaderDeviceInfo_t const __near &))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CShaderAPIBase *(__cdecl *__thiscall CShaderDeviceMgrDx8::SetMode(
        CShaderDeviceMgrDx8 *this,
        void *hWnd,
        int nAdapter,
        const ShaderDeviceInfo_t *mode))(const char *pInterfaceName, int *pReturnCode)
{
  int m_nDXLevel; // eax
  CShaderDeviceMgrBase::AdapterInfo_t *m_pMemory; // ebx
  int ClosestActualDXLevel; // ebx
  CShaderDeviceBase *v9; // ecx
  ShaderDeviceInfo_t adjustedMode; // [esp+Ch] [ebp-38h] BYREF
  char bReacquireResourcesNeeded_3; // [esp+57h] [ebp+13h]

  m_nDXLevel = mode->m_nDXLevel;
  if ( m_nDXLevel == 0 )
    m_nDXLevel = this->m_Adapters.m_Memory.m_pMemory[nAdapter].m_ActualCaps.m_nDXSupportLevel;
  m_pMemory = this->m_Adapters.m_Memory.m_pMemory;
  if ( m_nDXLevel > m_pMemory[nAdapter].m_ActualCaps.m_nMaxDXSupportLevel )
    m_nDXLevel = m_pMemory[nAdapter].m_ActualCaps.m_nMaxDXSupportLevel;
  ClosestActualDXLevel = CShaderDeviceMgrBase::GetClosestActualDXLevel(this, nDxLevel: m_nDXLevel);
  if ( ClosestActualDXLevel > 100 )
    return nullptr;
  v9 = g_pShaderDevice;
  bReacquireResourcesNeeded_3 = 0;
  if ( g_pShaderDevice != nullptr )
  {
    bReacquireResourcesNeeded_3 = 1;
    g_pShaderDevice->ReleaseResources(this: g_pShaderDevice, a2: true);
    v9 = g_pShaderDevice;
  }
  if ( g_pShaderAPI != nullptr )
  {
    g_pShaderAPI->OnDeviceShutdown(this: g_pShaderAPI);
    v9 = g_pShaderDevice;
    g_pShaderAPI = nullptr;
  }
  if ( v9 != nullptr )
  {
    v9->ShutdownDevice(this: v9);
    g_pShaderDevice = nullptr;
  }
  g_pShaderShadow = nullptr;
  adjustedMode = *mode;
  adjustedMode.m_nDXLevel = ClosestActualDXLevel;
  if ( !g_pShaderDeviceDx8->InitDevice(this: g_pShaderDeviceDx8, a2: hWnd, a3: nAdapter, a4: &adjustedMode)
    || !g_pShaderAPIDX8->OnDeviceInit(this: g_pShaderAPIDX8) )
  {
    return nullptr;
  }
  g_pShaderDevice = g_pShaderDeviceDx8;
  g_pShaderAPI = g_pShaderAPIDX8;
  g_pShaderShadow = g_pShaderShadowDx8;
  if ( bReacquireResourcesNeeded_3 != 0 )
    g_pShaderDeviceDx8->ReacquireResources(this: g_pShaderDeviceDx8);
  return CShaderDeviceMgrBase::ShaderInterfaceFactory;
}

//------------------------------------------------------------------------------
// Address: 0x100289D0
// Name: public: virtual bool CShaderDeviceDx8::InitDevice(void __near *,int,struct ShaderDeviceInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceDx8::InitDevice(
        CShaderDeviceDx8 *this,
        HWND__ *hwnd,
        nv::stereo::HL2Stereo<nv::stereo::D3D9Type> *nAdapter,
        const ShaderDeviceInfo_t *info)
{
  char result; // al

  result = CShaderDeviceDx8::CreateD3DDevice(this, pHWnd: hwnd, nAdapter, info);
  if ( result != 0 )
  {
    CShaderDeviceBase::InstallWindowHook(this, hWnd: (HWND)this->m_hWnd);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028A10
// Name: public: virtual void CShaderDeviceDx8::OtherAppInitializing(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::OtherAppInitializing(CShaderDeviceDx8 *this, bool initializing)
{
  D3DDeviceWrapper *v3; // eax
  D3DDeviceWrapper *v4; // esi
  unsigned int *m_pOutputPtr; // eax
  D3DDeviceWrapper *v6; // eax
  D3DDeviceWrapper *v7; // esi
  unsigned int *v8; // ecx
  void (__thiscall *OnThreadEvent)(IShaderUtil *, unsigned int); // eax

  if ( CShaderDeviceBase::ThreadOwnsDevice(this) && (unsigned __int8)_ThreadInMainThread() != 0 )
  {
    if ( !this->IsDeactivated(this) )
    {
      v3 = Dx9Device();
      v4 = v3;
      if ( v3->m_pASyncThreadHandle != nullptr )
      {
        if ( v3->m_PushBufferFreeSlots == 0 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v3);
        m_pOutputPtr = v4->m_pOutputPtr;
        --v4->m_PushBufferFreeSlots;
        *m_pOutputPtr = 24;
        ++v4->m_pOutputPtr;
      }
      else
      {
        v3->m_pD3DDevice->EndScene(this: v3->m_pD3DDevice);
      }
    }
    CShaderDeviceDx8::CheckDeviceLost(this, bOtherAppInitializing: initializing);
    if ( !this->IsDeactivated(this) )
    {
      v6 = Dx9Device();
      v7 = v6;
      if ( v6->m_pASyncThreadHandle != nullptr )
      {
        if ( v6->m_PushBufferFreeSlots == 0 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v6);
        v8 = v7->m_pOutputPtr;
        --v7->m_PushBufferFreeSlots;
        *v8 = 23;
        ++v7->m_pOutputPtr;
      }
      else
      {
        v6->m_pD3DDevice->BeginScene(this: v6->m_pD3DDevice);
      }
    }
  }
  else
  {
    OnThreadEvent = g_pShaderUtil->OnThreadEvent;
    if ( initializing )
      ((void (__stdcall *)(int))OnThreadEvent)(a1: 5);
    else
      ((void (__stdcall *)(int))OnThreadEvent)(a1: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028B00
// Name: public: virtual void CShaderDeviceDx8::ReacquireResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::ReacquireResources(CShaderDeviceDx8 *this)
{
  CShaderDeviceDx8::ReacquireResourcesInternal(
    this,
    bResetState: false,
    bForceReacquire: false,
    pszForceReason: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10028B10
// Name: private: void CShaderDeviceMgrDx8::InitAdapterInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::InitAdapterInfo(CShaderDeviceMgrDx8 *this)
{
  char v2; // al
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CShaderDeviceMgrBase::AdapterInfo_t *m_pMemory; // ecx
  int v6; // eax
  CShaderDeviceMgrBase::AdapterInfo_t *v7; // esi
  int v8; // ecx
  int v9; // eax
  const char *v10; // eax
  int nCount; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = *((_BYTE *)this + 72);
  if ( (v2 & 1) == 0 )
  {
    *((_BYTE *)this + 72) = v2 | 1;
    this->m_Adapters.m_Size = 0;
    nCount = this->m_pD3D->GetAdapterCount(this: this->m_pD3D);
    for ( i = 0; i < nCount; ++i )
    {
      m_Size = this->m_Adapters.m_Size;
      m_nAllocationCount = this->m_Adapters.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CShaderDeviceMgrBase::AdapterInfo_t,int>::Grow(
          this: &this->m_Adapters.m_Memory,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Adapters.m_Size;
      m_pMemory = this->m_Adapters.m_Memory.m_pMemory;
      v6 = this->m_Adapters.m_Size - m_Size - 1;
      this->m_Adapters.m_pElements = m_pMemory;
      if ( v6 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 728 * v6);
      v7 = &this->m_Adapters.m_Memory.m_pMemory[m_Size];
      *((_BYTE *)&v7->m_ActualCaps + 716) ^= (CShaderDeviceMgrDx8::ComputeCapsFromD3D(
                                                this,
                                                pCaps: &v7->m_ActualCaps,
                                                nAdapter: i)
                                            ^ *((_BYTE *)&v7->m_ActualCaps + 716))
                                           & 1;
      if ( (*((_BYTE *)&v7->m_ActualCaps + 716) & 1) != 0 )
      {
        CShaderDeviceMgrBase::ReadDXSupportLevels(this, caps: &v7->m_ActualCaps);
        CShaderDeviceMgrBase::ReadHardwareCaps(
          this,
          caps: &v7->m_ActualCaps,
          nDxLevel: (HardwareCaps_t *)v7->m_ActualCaps.m_nMaxDXSupportLevel);
        v9 = _CommandLine(a1: v8);
        v10 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v9 + 32))(
                              a1: v9,
                              a2: "-shader",
                              a3: 0);
        if ( v10 != nullptr )
          V_strncpy(pDest: v7->m_ActualCaps.m_pShaderDLL, pSrc: v10, maxLen: 32);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028C30
// Name: public: virtual int CShaderDeviceMgrDx8::GetAdapterCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceMgrDx8::GetAdapterCount(CShaderDeviceMgrDx8 *this)
{
  CShaderDeviceMgrDx8::InitAdapterInfo(this);
  return this->m_Adapters.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10028C40
// Name: public: virtual void CShaderDeviceMgrDx8::GetAdapterInfo(int,struct MaterialAdapterInfo_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::GetAdapterInfo(
        CShaderDeviceMgrDx8 *this,
        int nAdapter,
        MaterialAdapterInfo_t *info)
{
  CShaderDeviceMgrDx8::InitAdapterInfo(this);
  *info = this->m_Adapters.m_Memory.m_pMemory[nAdapter].m_ActualCaps.MaterialAdapterInfo_t;
}

//------------------------------------------------------------------------------
// Address: 0x10028C70
// Name: public: virtual enum InitReturnVal_t CShaderDeviceMgrDx8::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceMgrDx8::Init(CShaderDeviceMgrDx8 *this)
{
  CShaderDeviceMgrDx8::InitAdapterInfo(this);
  return 1;
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10029020
// Name: public: virtual void CShaderDeviceMgrDx8::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::Disconnect(CShaderDeviceMgrDx10 *this)
{
  IDXGIFactory *m_pDXGIFactory; // eax

  m_pDXGIFactory = this->m_pDXGIFactory;
  if ( m_pDXGIFactory != nullptr )
  {
    m_pDXGIFactory->Release(this: m_pDXGIFactory);
    this->m_pDXGIFactory = nullptr;
  }
  CShaderDeviceMgrBase::Disconnect(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002BE30
// Name: public: virtual bool CShaderDeviceMgrDx8::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrDx8::Connect(CShaderDeviceMgrDx8 *this, void *(__cdecl *factory)(const char *, int *))
{
  IDirect3D9 *v3; // eax

  if ( CShaderDeviceMgrBase::Connect(this, factory) == 0 )
    return 0;
  v3 = Direct3DCreate9(SDKVersion: 0x20u);
  this->m_pD3D = v3;
  if ( v3 == nullptr )
  {
    _Warning(a1: "Failed to create D3D9!\n");
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002BE70
// Name: public: virtual void CShaderDeviceMgrDx8::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::Shutdown(CShaderDeviceMgrDx8 *this)
{
  if ( g_pShaderAPI != nullptr )
    g_pShaderAPI->OnDeviceShutdown(this: g_pShaderAPI);
  if ( g_pShaderDevice != nullptr )
  {
    g_pShaderDevice->ShutdownDevice(this: g_pShaderDevice);
    g_pMaterialSystemHardwareConfig = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BEB0
// Name: private: void CShaderDeviceMgrDx8::CheckVendorDependentShadowMappingSupport(struct HardwareCaps_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::CheckVendorDependentShadowMappingSupport(
        CShaderDeviceMgrDx8 *this,
        HardwareCaps_t *pCaps,
        unsigned int nAdapter)
{
  int v5; // ecx
  int v6; // eax
  bool v7; // zf
  unsigned int m_VendorID; // eax
  bool v9; // bl
  char v10; // al
  char bFound16Bit; // [esp+78h] [ebp+4h]

  pCaps->m_NullTextureFormat = IMAGE_FORMAT_ARGB8888;
  if ( this->m_pD3D->CheckDeviceFormat(
         this: this->m_pD3D,
         a2: nAdapter,
         a3: D3DDEVTYPE_HAL,
         a4: D3DFMT_X8R8G8B8,
         a5: 1u,
         a6: D3DRTYPE_TEXTURE,
         a7: D3DFMT_R5G6B5) == 0 )
    pCaps->m_NullTextureFormat = IMAGE_FORMAT_RGB565;
  v6 = _CommandLine(a1: v5);
  v7 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-tools", a3: 0) == 0;
  m_VendorID = pCaps->m_VendorID;
  v9 = !v7;
  bFound16Bit = 0;
  if ( m_VendorID == 4318 && (*((_BYTE *)pCaps + 716) & 8) != 0 )
  {
    if ( this->m_pD3D->CheckDeviceFormat(
           this: this->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: D3DFMT_X8R8G8B8,
           a5: 1u,
           a6: D3DRTYPE_TEXTURE,
           a7: (_D3DFORMAT)1280070990) == 0 )
      pCaps->m_NullTextureFormat = IMAGE_FORMAT_NULL;
    if ( this->m_pD3D->CheckDeviceFormat(
           this: this->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: D3DFMT_X8R8G8B8,
           a5: 2u,
           a6: D3DRTYPE_TEXTURE,
           a7: D3DFMT_D16) != 0
      || (v10 = *((_BYTE *)pCaps + 718) & 0xF3 | 4,
          pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_D16_SHADOW,
          *((_BYTE *)pCaps + 718) = v10,
          bFound16Bit = 1,
          v9) )
    {
      if ( this->m_pD3D->CheckDeviceFormat(
             this: this->m_pD3D,
             a2: nAdapter,
             a3: D3DDEVTYPE_HAL,
             a4: D3DFMT_X8R8G8B8,
             a5: 2u,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_D24S8) == 0 )
      {
        *((_BYTE *)pCaps + 718) = *((_BYTE *)pCaps + 718) & 0xF3 | 4;
        pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_D24X8_SHADOW;
        return;
      }
      goto LABEL_19;
    }
  }
  else
  {
    if ( m_VendorID != 4098 || (*((_BYTE *)pCaps + 716) & 4) == 0 )
    {
LABEL_20:
      *((_BYTE *)pCaps + 718) &= 0xF3u;
      pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_UNKNOWN;
      return;
    }
    *((_BYTE *)pCaps + 718) &= ~8u;
    if ( this->m_pD3D->CheckDeviceFormat(
           this: this->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: D3DFMT_X8R8G8B8,
           a5: 2u,
           a6: D3DRTYPE_TEXTURE,
           a7: (_D3DFORMAT)875710020) == 0 )
      *((_BYTE *)pCaps + 718) |= 8u;
    if ( this->m_pD3D->CheckDeviceFormat(
           this: this->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: D3DFMT_X8R8G8B8,
           a5: 2u,
           a6: D3DRTYPE_TEXTURE,
           a7: (_D3DFORMAT)909198916) != 0
      || (*((_BYTE *)pCaps + 718) |= 4u, pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_D16_SHADOW,
                                         bFound16Bit = 1,
                                         v9) )
    {
      if ( this->m_pD3D->CheckDeviceFormat(
             this: this->m_pD3D,
             a2: nAdapter,
             a3: D3DDEVTYPE_HAL,
             a4: D3DFMT_X8R8G8B8,
             a5: 2u,
             a6: D3DRTYPE_TEXTURE,
             a7: (_D3DFORMAT)875710020) == 0 )
      {
        *((_BYTE *)pCaps + 718) |= 4u;
        pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_D24X8_SHADOW;
        return;
      }
LABEL_19:
      if ( bFound16Bit != 0 )
        return;
      goto LABEL_20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C0A0
// Name: public: virtual bool CShaderDeviceMgrDx8::SetAdapter(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceMgrDx8::SetAdapter(CShaderDeviceMgrDx8 *this, unsigned int nAdapter, char nAdapterFlags)
{
  unsigned int *p_m_DisplayAdapter; // esi
  bool result; // al

  g_pShaderDeviceDx8->m_DeviceType = ((nAdapterFlags & 4) != 0) + 1;
  g_pShaderDeviceDx8->m_DisplayAdapter = nAdapter;
  p_m_DisplayAdapter = &g_pShaderDeviceDx8->m_DisplayAdapter;
  if ( *p_m_DisplayAdapter >= this->GetAdapterCount(this) )
    *p_m_DisplayAdapter = 0;
  result = g_pShaderDeviceDx8->OnAdapterSet(this: g_pShaderDeviceDx8);
  if ( result )
  {
    g_pShaderDevice = g_pShaderDeviceDx8;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002C110
// Name: private: virtual void CShaderDeviceMgrDx8::GetDesktopResolution(int __near *,int __near *,int)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CShaderDeviceMgrDx8::GetDesktopResolution(
        CShaderDeviceMgrDx8 *this,
        int *pWidth,
        int *pHeight,
        unsigned int nAdapter)
{
  HMONITOR v4; // eax
  int v5; // ecx
  tagMONITORINFO monitorInfo_4; // [esp+8h] [ebp-28h] OVERLAPPED BYREF

  v4 = this->m_pD3D->GetAdapterMonitor(this: this->m_pD3D, a2: nAdapter);
  memset((void *)&monitorInfo_4.rcMonitor, 0, 36);
  monitorInfo_4.cbSize = 40;
  GetMonitorInfoA(hMonitor: v4, lpmi: &monitorInfo_4);
  v5 = monitorInfo_4.rcMonitor.bottom - monitorInfo_4.rcMonitor.top;
  *pWidth = monitorInfo_4.rcMonitor.right - monitorInfo_4.rcMonitor.left;
  *pHeight = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002C180
// Name: public: virtual int CShaderDeviceMgrDx8::GetModeCount(int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShaderDeviceMgrDx8::GetModeCount(CShaderDeviceMgrDx8 *this, unsigned int nAdapter)
{
  return this->m_pD3D->GetAdapterModeCount(this: this->m_pD3D, a2: nAdapter, a3: D3DFMT_X8R8G8B8);
}

//------------------------------------------------------------------------------
// Address: 0x1002C1A0
// Name: public: virtual void CShaderDeviceMgrDx8::GetModeInfo(struct ShaderDisplayMode_t __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::GetModeInfo(
        CShaderDeviceMgrDx8 *this,
        ShaderDisplayMode_t *pInfo,
        unsigned int nAdapter,
        unsigned int nMode)
{
  unsigned int RefreshRate; // edx
  ImageFormat v5; // eax
  _D3DFORMAT v6; // ecx
  _D3DFORMAT v7; // [esp+Ch] [ebp-18h]
  _D3DDISPLAYMODE d3dInfo; // [esp+10h] [ebp-14h] BYREF
  _D3DFORMAT format; // [esp+20h] [ebp-4h]

  this->m_pD3D->EnumAdapterModes(
    this: this->m_pD3D,
    a2: nAdapter,
    a3: D3DFMT_X8R8G8B8,
    a4: nMode,
    a5: (_D3DDISPLAYMODE *)&d3dInfo.Height);
  RefreshRate = d3dInfo.RefreshRate;
  v7 = format;
  pInfo->m_nWidth = d3dInfo.Height;
  pInfo->m_nHeight = RefreshRate;
  v5 = ImageLoader::D3DFormatToImageFormat(format: v7);
  v6 = d3dInfo.Format;
  pInfo->m_Format = v5;
  pInfo->m_nRefreshRateNumerator = v6;
  pInfo->m_nRefreshRateDenominator = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002C200
// Name: public: virtual void CShaderDeviceMgrDx8::GetCurrentModeInfo(struct ShaderDisplayMode_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::GetCurrentModeInfo(
        CShaderDeviceMgrDx8 *this,
        ShaderDisplayMode_t *pInfo,
        unsigned int nAdapter)
{
  unsigned int RefreshRate; // edx
  ImageFormat v4; // eax
  _D3DFORMAT v5; // ecx
  _D3DFORMAT v6; // [esp+4h] [ebp-18h]
  _D3DDISPLAYMODE mode; // [esp+8h] [ebp-14h] BYREF
  _D3DFORMAT format; // [esp+18h] [ebp-4h]

  this->m_pD3D->GetAdapterDisplayMode(this: this->m_pD3D, a2: nAdapter, a3: (_D3DDISPLAYMODE *)&mode.Height);
  RefreshRate = mode.RefreshRate;
  v6 = format;
  pInfo->m_nWidth = mode.Height;
  pInfo->m_nHeight = RefreshRate;
  v4 = ImageLoader::D3DFormatToImageFormat(format: v6);
  v5 = mode.Format;
  pInfo->m_Format = v4;
  pInfo->m_nRefreshRateNumerator = v5;
  pInfo->m_nRefreshRateDenominator = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002C250
// Name: public: bool CShaderDeviceMgrDx8::ValidateMode(int,struct ShaderDeviceInfo_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __thiscall CShaderDeviceMgrDx8::ValidateMode(
        CShaderDeviceMgrDx8 *this,
        int nAdapter,
        const ShaderDeviceInfo_t *info)
{
  bool result; // al
  void (__thiscall *GetCurrentModeInfo)(IShaderDeviceMgr *, ShaderDisplayMode_t *, int); // edx
  ShaderDisplayMode_t displayMode_4; // [esp+8h] [ebp-18h] OVERLAPPED BYREF

  result = nAdapter < (int)this->m_pD3D->GetAdapterCount(this: this->m_pD3D)
        && ((GetCurrentModeInfo = this->GetCurrentModeInfo,
             memset(&displayMode_4.m_nWidth, 0, 20),
             displayMode_4.m_nVersion = 1,
             GetCurrentModeInfo(this, a2: &displayMode_4, a3: nAdapter),
             (*((_BYTE *)info + 52) & 1) == 0)
         || info->m_DisplayMode.m_nWidth <= displayMode_4.m_nWidth
         && info->m_DisplayMode.m_nHeight <= displayMode_4.m_nHeight)
        && FindNearestSupportedBackBufferFormat(
             displayAdapter: nAdapter,
             deviceType: D3DDEVTYPE_HAL,
             displayFormat: displayMode_4.m_Format,
             backBufferFormat: info->m_DisplayMode.m_Format,
             bIsWindowed: *((_BYTE *)info + 52) & 1) != IMAGE_FORMAT_UNKNOWN;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002C2F0
// Name: public: virtual int CShaderDeviceMgrDx8::GetVidMemBytes(int)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CShaderDeviceMgrDx8::GetVidMemBytes(CShaderDeviceMgrDx8 *this, int nAdapter)
{
  return GetVidMemBytes();
}

//------------------------------------------------------------------------------
// Address: 0x1002C300
// Name: public: CShaderDeviceDx8::CShaderDeviceDx8(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceDx8 *__thiscall CShaderDeviceDx8::CShaderDeviceDx8(CShaderDeviceDx8 *this)
{
  unsigned int v2; // eax
  IDirect3DQuery9 **m_pFrameSyncQueryObject; // ecx

  CShaderDeviceBase::CShaderDeviceBase(this);
  this->__vftable = (CShaderDeviceDx8_vtbl *)&CShaderDeviceDx8::`vftable';
  *(_QWORD *)&this->m_PendingVideoModeChangeConfig.m_DisplayMode.m_nVersion = 0;
  *(_QWORD *)&this->m_PendingVideoModeChangeConfig.m_DisplayMode.m_nHeight = 0;
  *(_QWORD *)&this->m_PendingVideoModeChangeConfig.m_DisplayMode.m_nRefreshRateNumerator = 0;
  this->m_PendingVideoModeChangeConfig.m_DisplayMode.m_nVersion = 1;
  memset(
    dst: (unsigned __int8 *)&this->m_PendingVideoModeChangeConfig,
    value: 0,
    count: sizeof(this->m_PendingVideoModeChangeConfig));
  this->m_PendingVideoModeChangeConfig.m_nVersion = 1;
  this->m_PendingVideoModeChangeConfig.m_DisplayMode.m_nVersion = 1;
  this->m_nonInteractiveModeMutex.m_ownerID = 0;
  this->m_nonInteractiveModeMutex.m_depth = 0;
  this->m_pD3DDevice = nullptr;
  v2 = 0;
  m_pFrameSyncQueryObject = this->m_pFrameSyncQueryObject;
  do
  {
    *m_pFrameSyncQueryObject = nullptr;
    this->m_bQueryIssued[v2++] = false;
    ++m_pFrameSyncQueryObject;
  }
  while ( v2 < 2 );
  *((_BYTE *)this + 172) &= 0xC0u;
  this->m_DeviceSupportsCreateQuery = -1;
  this->m_NonInteractiveRefresh.m_Mode = MATERIAL_NON_INTERACTIVE_MODE_NONE;
  this->m_pFrameSyncTexture = nullptr;
  this->m_DeviceState = DEVICE_STATE_OK;
  this->m_iStencilBufferBits = 0;
  this->m_NonInteractiveRefresh.m_pVertexShader = nullptr;
  this->m_NonInteractiveRefresh.m_pPixelShader = nullptr;
  this->m_NonInteractiveRefresh.m_pPixelShaderStartup = nullptr;
  this->m_NonInteractiveRefresh.m_pPixelShaderStartupPass2 = nullptr;
  this->m_NonInteractiveRefresh.m_pVertexDecl = nullptr;
  this->m_NonInteractiveRefresh.m_nPacifierFrame = 0;
  this->m_numReleaseResourcesRefCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002C3D0
// Name: public: virtual CShaderDeviceDx8::~CShaderDeviceDx8(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::~CShaderDeviceDx8(CShaderDeviceDx8 *this)
{
  this->__vftable = (CShaderDeviceDx8_vtbl *)&CShaderDeviceDx8::`vftable';
  CShaderDeviceBase::~CShaderDeviceBase(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002C3E0
// Name: protected: enum _D3DMULTISAMPLE_TYPE CShaderDeviceDx8::ComputeMultisampleType(int)
// Source: json
//------------------------------------------------------------------------------
_D3DMULTISAMPLE_TYPE __thiscall CShaderDeviceDx8::ComputeMultisampleType(CShaderDeviceDx8 *this, int nSampleCount)
{
  _D3DMULTISAMPLE_TYPE result; // eax

  switch ( nSampleCount )
  {
    case 2:
      result = D3DMULTISAMPLE_2_SAMPLES;
      break;
    case 3:
      result = D3DMULTISAMPLE_3_SAMPLES;
      break;
    case 4:
      result = D3DMULTISAMPLE_4_SAMPLES;
      break;
    case 5:
      result = D3DMULTISAMPLE_5_SAMPLES;
      break;
    case 6:
      result = D3DMULTISAMPLE_6_SAMPLES;
      break;
    case 7:
      result = D3DMULTISAMPLE_7_SAMPLES;
      break;
    case 8:
      result = D3DMULTISAMPLE_8_SAMPLES;
      break;
    case 9:
      result = D3DMULTISAMPLE_9_SAMPLES;
      break;
    case 10:
      result = D3DMULTISAMPLE_10_SAMPLES;
      break;
    case 11:
      result = D3DMULTISAMPLE_11_SAMPLES;
      break;
    case 12:
      result = D3DMULTISAMPLE_12_SAMPLES;
      break;
    case 13:
      result = D3DMULTISAMPLE_13_SAMPLES;
      break;
    case 14:
      result = D3DMULTISAMPLE_14_SAMPLES;
      break;
    case 15:
      result = D3DMULTISAMPLE_15_SAMPLES;
      break;
    case 16:
      result = D3DMULTISAMPLE_16_SAMPLES;
      break;
    default:
      result = D3DMULTISAMPLE_NONE;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002C4B0
// Name: protected: void CShaderDeviceDx8::CalcBackBufferDimensions(struct ShaderDisplayMode_t const __near &,struct ShaderDeviceInfo_t const __near &,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::CalcBackBufferDimensions(
        CShaderDeviceDx8 *this,
        const ShaderDisplayMode_t *mode,
        const ShaderDeviceInfo_t *info,
        int *pBackBufferWidth,
        int *pBackBufferHeight)
{
  char v5; // cl
  int m_nWidth; // ecx
  char v7; // dl
  int m_nWindowedSizeLimitWidth; // ecx

  v5 = *((_BYTE *)info + 52);
  if ( (v5 & 1) == 0 )
  {
    m_nWidth = info->m_DisplayMode.m_nWidth;
    if ( m_nWidth != 0 && info->m_DisplayMode.m_nHeight != 0 )
    {
      v7 = 0;
    }
    else
    {
      m_nWidth = mode->m_nWidth;
      v7 = 1;
    }
    *pBackBufferWidth = m_nWidth;
    if ( v7 != 0 )
    {
      *pBackBufferHeight = mode->m_nHeight;
      return;
    }
    goto LABEL_15;
  }
  if ( (v5 & 2) == 0 )
  {
    *pBackBufferWidth = info->m_DisplayMode.m_nWidth;
LABEL_15:
    *pBackBufferHeight = info->m_DisplayMode.m_nHeight;
    return;
  }
  if ( (v5 & 8) != 0
    && ((m_nWindowedSizeLimitWidth = info->m_nWindowedSizeLimitWidth) < mode->m_nWidth
     || info->m_nWindowedSizeLimitHeight < mode->m_nHeight) )
  {
    *pBackBufferWidth = m_nWindowedSizeLimitWidth;
    *pBackBufferHeight = info->m_nWindowedSizeLimitHeight;
  }
  else
  {
    *pBackBufferWidth = mode->m_nWidth;
    *pBackBufferHeight = mode->m_nHeight;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C550
// Name: protected: void CShaderDeviceDx8::SetPresentParameters(void __near *,int,struct ShaderDeviceInfo_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CShaderDeviceDx8::SetPresentParameters(
        CShaderDeviceDx8 *this,
        HWND__ *hWnd,
        int nAdapter,
        const ShaderDeviceInfo_t *info,
        ImageFormat bSetSymbolsOnly)
{
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  _D3DPRESENT_PARAMETERS_ *p_m_PresentParameters; // ebp
  ImageFormat m_AdapterFormat; // ecx
  ImageFormat NearestSupportedBackBufferFormat; // ecx
  char v16; // al
  bool v17; // cc
  _D3DFORMAT NearestSupportedDepthFormat; // eax
  __int32 v19; // eax
  __int32 v20; // eax
  int m_nWidth; // eax
  char v22; // cl
  unsigned int m_nHeight; // eax
  int v24; // ecx
  int v25; // eax
  bool v26; // zf
  int m_nRefreshRateDenominator; // ecx
  char v28; // al
  unsigned int v29; // edx
  int m_nWindowedSizeLimitWidth; // eax
  _D3DMULTISAMPLE_TYPE v31; // ebp
  CShaderDeviceMgrBase::AdapterInfo_t *HardwareCaps; // eax
  int v33; // eax
  unsigned int v34; // ecx
  ImageFormat v35; // [esp+0h] [ebp-34h]
  int backBufferHeight; // [esp+14h] [ebp-20h] BYREF
  _BYTE mode[28]; // [esp+18h] [ebp-1Ch] OVERLAPPED BYREF
  BOOL infoa; // [esp+40h] [ebp+Ch]

  memset(&mode[8], 0, 20);
  *(_DWORD *)&mode[4] = 1;
  g_pShaderDeviceMgr->GetCurrentModeInfo(this: g_pShaderDeviceMgr, a2: (ShaderDisplayMode_t *)&mode[4], a3: nAdapter);
  backBufferHeight = 0;
  *(_DWORD *)mode = 0;
  CShaderDeviceDx8::CalcBackBufferDimensions(
    this,
    mode: (const ShaderDisplayMode_t *)&mode[4],
    info,
    pBackBufferWidth: &backBufferHeight,
    pBackBufferHeight: (int *)mode);
  v7 = *(_DWORD *)mode;
  infoa = (float)((float)backBufferHeight / (float)*(int *)mode) >= 1.5999;
  v8 = _KeyValuesSystem();
  (*(void (__thiscall **)(int, const char *, BOOL))(*(_DWORD *)v8 + 28))(a1: v8, a2: "WIN32WIDE", a3: infoa);
  v9 = _KeyValuesSystem();
  LOBYTE(v10) = v7 >= 720;
  (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 28))(a1: v9, a2: "WIN32HIDEF", a3: v10);
  v11 = _KeyValuesSystem();
  LOBYTE(v12) = v7 < 720;
  (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)v11 + 28))(a1: v11, a2: "WIN32LODEF", a3: v12);
  if ( (_BYTE)bSetSymbolsOnly == IMAGE_FORMAT_RGBA8888 )
  {
    p_m_PresentParameters = &this->m_PresentParameters;
    memset(dst: (unsigned __int8 *)&this->m_PresentParameters, value: 0, count: sizeof(this->m_PresentParameters));
    this->m_PresentParameters.Windowed = *((_BYTE *)info + 52) & 1;
    this->m_PresentParameters.SwapEffect = (*((unsigned __int8 *)info + 52) | 0x40u) >> 6;
    m_AdapterFormat = this->m_AdapterFormat;
    this->m_PresentParameters.EnableAutoDepthStencil = 1;
    NearestSupportedBackBufferFormat = FindNearestSupportedBackBufferFormat(
                                         displayAdapter: nAdapter,
                                         deviceType: D3DDEVTYPE_HAL,
                                         displayFormat: m_AdapterFormat,
                                         backBufferFormat: info->m_DisplayMode.m_Format,
                                         bIsWindowed: *((_BYTE *)info + 52) & 1);
    *((_BYTE *)this + 172) ^= (*((_BYTE *)this + 172) ^ (4 * *((_BYTE *)info + 52))) & 0x10;
    v16 = *((_BYTE *)this + 172);
    v17 = info->m_nDXLevel < 80;
    bSetSymbolsOnly = NearestSupportedBackBufferFormat;
    if ( !v17 )
      *((_BYTE *)this + 172) = v16 | 0x10;
    NearestSupportedDepthFormat = FindNearestSupportedDepthFormat(
                                    nAdapter,
                                    displayFormat: this->m_AdapterFormat,
                                    renderTargetFormat: NearestSupportedBackBufferFormat,
                                    depthFormat: (_D3DFORMAT)((*((_BYTE *)this + 172) & 0x10) != 0 ? D3DFMT_D24S8 : D3DFMT_D24X8));
    this->m_PresentParameters.AutoDepthStencilFormat = NearestSupportedDepthFormat;
    v19 = NearestSupportedDepthFormat - 73;
    this->m_PresentParameters.hDeviceWindow = hWnd;
    if ( v19 != 0 )
    {
      v20 = v19 - 2;
      if ( v20 != 0 )
      {
        if ( v20 == 4 )
        {
          this->m_iStencilBufferBits = 4;
        }
        else
        {
          *((_BYTE *)this + 172) &= ~0x10u;
          this->m_iStencilBufferBits = 0;
        }
      }
      else
      {
        this->m_iStencilBufferBits = 8;
      }
    }
    else
    {
      this->m_iStencilBufferBits = 1;
    }
    if ( (*((_BYTE *)info + 52) & 1) == 0 )
    {
      m_nWidth = info->m_DisplayMode.m_nWidth;
      if ( m_nWidth != 0 && info->m_DisplayMode.m_nHeight != 0 )
      {
        v22 = 0;
      }
      else
      {
        m_nWidth = *(_DWORD *)&mode[8];
        v22 = 1;
      }
      p_m_PresentParameters->BackBufferWidth = m_nWidth;
      m_nHeight = *(_DWORD *)&mode[12];
      if ( v22 == 0 )
        m_nHeight = info->m_DisplayMode.m_nHeight;
      v35 = bSetSymbolsOnly;
      this->m_PresentParameters.BackBufferHeight = m_nHeight;
      this->m_PresentParameters.BackBufferFormat = ImageLoader::ImageFormatToD3DFormat(format: v35);
      if ( (*((_BYTE *)info + 52) & 0x10) == 0
        || (v25 = _CommandLine(a1: v24),
            (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v25 + 40))(a1: v25, a2: "-forcenovsync") != 0) )
      {
        this->m_PresentParameters.BackBufferCount = 1;
        this->m_PresentParameters.PresentationInterval = 0x80000000;
      }
      else
      {
        if ( (_S1_3 & 1) == 0 )
        {
          _S1_3 |= 1u;
          ConVarRef::ConVarRef(this: &mat_triplebuffered, pName: "mat_triplebuffered");
        }
        v26 = mat_triplebuffered.m_pConVarState->m_Value.m_nValue == 0;
        this->m_PresentParameters.PresentationInterval = 1;
        this->m_PresentParameters.BackBufferCount = !v26 + 1;
      }
      m_nRefreshRateDenominator = info->m_DisplayMode.m_nRefreshRateDenominator;
      if ( m_nRefreshRateDenominator != 0 )
        this->m_PresentParameters.FullScreen_RefreshRateInHz = info->m_DisplayMode.m_nRefreshRateNumerator
                                                             / m_nRefreshRateDenominator;
      else
        this->m_PresentParameters.FullScreen_RefreshRateInHz = 0;
LABEL_36:
      if ( info->m_nAASamples <= 0 || this->m_PresentParameters.SwapEffect != D3DSWAPEFFECT_DISCARD )
      {
        this->m_PresentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
        this->m_PresentParameters.MultiSampleQuality = 0;
        return;
      }
      v31 = CShaderDeviceDx8::ComputeMultisampleType(this, nSampleCount: info->m_nAASamples);
      HardwareCaps = CShaderDeviceMgrBase::GetHardwareCaps(this: &g_ShaderDeviceMgrDx8, nAdapter);
      if ( info->m_nAASamples == 16 && HardwareCaps->m_ActualCaps.m_VendorID == 4318 )
      {
        v31 = D3DMULTISAMPLE_4_SAMPLES;
        v33 = g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceMultiSampleType(
                this: g_pShaderDeviceMgrDx8->m_pD3D,
                a2: nAdapter,
                a3: D3DDEVTYPE_HAL,
                a4: this->m_PresentParameters.BackBufferFormat,
                a5: this->m_PresentParameters.Windowed,
                a6: D3DMULTISAMPLE_4_SAMPLES,
                a7: (unsigned int *)&bSetSymbolsOnly);
        if ( v33 >= 0 && bSetSymbolsOnly == IMAGE_FORMAT_BGRX8888 )
        {
          v34 = 15;
          goto LABEL_45;
        }
      }
      else
      {
        v33 = g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceMultiSampleType(
                this: g_pShaderDeviceMgrDx8->m_pD3D,
                a2: nAdapter,
                a3: D3DDEVTYPE_HAL,
                a4: this->m_PresentParameters.BackBufferFormat,
                a5: this->m_PresentParameters.Windowed,
                a6: v31,
                a7: (unsigned int *)&bSetSymbolsOnly);
      }
      v34 = 0;
LABEL_45:
      if ( v33 >= 0 )
      {
        this->m_PresentParameters.MultiSampleType = v31;
        this->m_PresentParameters.MultiSampleQuality = v34;
      }
      return;
    }
    this->m_PresentParameters.PresentationInterval = 0x80000000;
    v28 = *((_BYTE *)info + 52);
    if ( (v28 & 2) != 0 )
    {
      v29 = *(_DWORD *)&mode[12];
      if ( (v28 & 8) != 0 )
      {
        m_nWindowedSizeLimitWidth = info->m_nWindowedSizeLimitWidth;
        if ( m_nWindowedSizeLimitWidth < *(int *)&mode[8] || info->m_nWindowedSizeLimitHeight < *(int *)&mode[12] )
        {
          p_m_PresentParameters->BackBufferWidth = m_nWindowedSizeLimitWidth;
          this->m_PresentParameters.BackBufferHeight = info->m_nWindowedSizeLimitHeight;
LABEL_35:
          this->m_PresentParameters.BackBufferFormat = ImageLoader::ImageFormatToD3DFormat(format: bSetSymbolsOnly);
          this->m_PresentParameters.BackBufferCount = 1;
          goto LABEL_36;
        }
      }
      p_m_PresentParameters->BackBufferWidth = *(_DWORD *)&mode[8];
    }
    else
    {
      p_m_PresentParameters->BackBufferWidth = info->m_DisplayMode.m_nWidth;
      v29 = info->m_DisplayMode.m_nHeight;
    }
    this->m_PresentParameters.BackBufferHeight = v29;
    goto LABEL_35;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C900
// Name: public: virtual void CShaderDeviceDx8::ShutdownDevice(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::ShutdownDevice(CShaderDeviceDx8 *this)
{
  D3DDeviceWrapper *v2; // edi
  D3DDeviceWrapper *v3; // eax

  if ( Dx9Device()->m_pD3DDevice != nullptr )
  {
    v2 = Dx9Device();
    D3DDeviceWrapper::Synchronize(this: v2);
    v2->m_pD3DDevice->Release(this: v2->m_pD3DDevice);
    v3 = Dx9Device();
    v3->m_pD3DDevice = nullptr;
    v3->m_pPresentParameters = nullptr;
    v3->m_pHWnd = nullptr;
    CShaderDeviceBase::RemoveWindowHook(this, hWnd: (HWND)this->m_hWnd);
    this->m_hWnd = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C960
// Name: public: virtual bool CShaderDeviceDx8::IsUsingGraphics(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceDx8::IsUsingGraphics(CShaderDeviceDx8 *this)
{
  return Dx9Device()->m_pD3DDevice != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002C970
// Name: public: virtual int CShaderDeviceDx8::GetCurrentAdapter(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShaderDeviceDx8::GetCurrentAdapter(CShaderDeviceDx8 *this)
{
  return this->m_DisplayAdapter;
}

//------------------------------------------------------------------------------
// Address: 0x1002C980
// Name: public: virtual void CShaderDeviceDx8::SpewDriverInfo(void)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CShaderDeviceDx8::SpewDriverInfo(CShaderDeviceDx8 *this)
{
  D3DDeviceWrapper *v2; // esi
  int m_nAdapter; // edx
  const ImageFormatInfo_t *v4; // eax
  const char *v5; // edx
  const char *v6; // ecx
  const char *v7; // eax
  const char *v8; // edx
  const char *v9; // ecx
  const char *v10; // eax
  const char *v11; // edx
  const char *v12; // ecx
  const char *v13; // eax
  const char *v14; // edx
  const char *v15; // ecx
  const char *v16; // eax
  const char *v17; // edx
  const char *v18; // ecx
  const char *v19; // eax
  const char *v20; // edx
  const char *v21; // ecx
  const char *v22; // eax
  const char *v23; // ebp
  const char *v24; // edi
  const char *v25; // edx
  const char *v26; // ecx
  const char *v27; // eax
  const char *v28; // edi
  const char *v29; // edx
  const char *v30; // ecx
  const char *v31; // eax
  const char *v32; // edi
  const char *v33; // edx
  const char *v34; // ecx
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  const char *v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  const char *v42; // eax
  const char *v43; // eax
  HDRType_t m_HDRType; // eax
  __int32 v45; // eax
  const char *v46; // eax
  const char *v47; // eax
  const char *v48; // eax
  const char *v49; // eax
  const char *v50; // eax
  const char *v51; // eax
  const char *v52; // eax
  const char *v53; // eax
  _BYTE mode_4[230]; // [esp+1Ch] [ebp-594h] OVERLAPPED BYREF
  _D3DADAPTER_IDENTIFIER9 ident; // [esp+160h] [ebp-450h] BYREF

  v2 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v2);
  v2->m_pD3DDevice->GetDeviceCaps(this: v2->m_pD3DDevice, a2: (_D3DCAPS9 *)&mode_4[24]);
  g_pShaderDeviceMgrDx8->m_pD3D->GetAdapterIdentifier(
    this: g_pShaderDeviceMgrDx8->m_pD3D,
    a2: this->m_nAdapter,
    a3: 2u,
    a4: (_D3DADAPTER_IDENTIFIER9 *)&ident.Driver[4]);
  _Warning(a1: "Shader API Driver Info:\n\nDriver : %s Version : %d\n", &ident.Driver[4], ident.DriverVersion.HighPart);
  _Warning(a1: "Driver Description :  %s\n", &ident.Description[4]);
  _Warning(
    a1: "Chipset version %d %d %d %d\n\n",
    ident.DeviceId,
    ident.SubSysId,
    ident.Revision,
    ident.DeviceIdentifier.Data1);
  m_nAdapter = this->m_nAdapter;
  memset(&mode_4[4], 0, 20);
  *(_DWORD *)mode_4 = 1;
  g_pShaderDeviceMgr->GetCurrentModeInfo(this: g_pShaderDeviceMgr, a2: (ShaderDisplayMode_t *)mode_4, a3: m_nAdapter);
  v4 = ImageLoader::ImageFormatInfo(fmt: *(ImageFormat *)&mode_4[12]);
  _Warning(
    a1: "Display mode : %d x %d @%dHz (%s)\n",
    *(_DWORD *)&mode_4[4],
    *(_DWORD *)&mode_4[8],
    *(_DWORD *)&mode_4[16],
    v4->m_pName);
  _Warning(
    a1: "Vertex Shader Version : %d.%d Pixel Shader Version : %d.%d\n",
    mode_4[221],
    mode_4[220],
    mode_4[229],
    mode_4[228]);
  _Warning(a1: "\nDevice Caps :\n");
  v5 = " Y ";
  if ( (*(_DWORD *)&mode_4[52] & 0x80000) == 0 )
    v5 = "*N*";
  v6 = " Y ";
  if ( (*(_WORD *)&mode_4[52] & 0x800) == 0 )
    v6 = " N ";
  v7 = " Y ";
  if ( (*(_DWORD *)&mode_4[52] & 0x20000) == 0 )
    v7 = " N ";
  _Warning(a1: "CANBLTSYSTONONLOCAL %s CANRENDERAFTERFLIP %s HWRASTERIZATION %s\n", v7, v6, v5);
  v8 = " Y ";
  if ( (*(_DWORD *)&mode_4[52] & 0x100000) == 0 )
    v8 = " N ";
  v9 = " Y ";
  if ( (*(_DWORD *)&mode_4[52] & 0x1000000) == 0 )
    v9 = " N ";
  v10 = " Y ";
  if ( (*(_DWORD *)&mode_4[52] & 0x10000) == 0 )
    v10 = " N ";
  _Warning(a1: "HWTRANSFORMANDLIGHT %s NPATCHES %s PUREDEVICE %s\n", v10, v9, v8);
  v11 = " Y ";
  if ( (*(_WORD *)&mode_4[52] & 0x100) == 0 )
    v11 = " N ";
  v12 = " Y ";
  if ( (*(_WORD *)&mode_4[52] & 0x1000) == 0 )
    v12 = " N ";
  v13 = "*Y*";
  if ( (*(_WORD *)&mode_4[52] & 0x4000) == 0 )
    v13 = " N ";
  _Warning(a1: "SEPARATETEXTUREMEMORIES %s TEXTURENONLOCALVIDMEM %s TEXTURESYSTEMMEMORY %s\n", v13, v12, v11);
  v14 = " Y ";
  if ( mode_4[52] >= 0 )
    v14 = " N ";
  v15 = " Y ";
  if ( (mode_4[52] & 0x40) == 0 )
    v15 = "*N*";
  v16 = " Y ";
  if ( (*(_WORD *)&mode_4[52] & 0x200) == 0 )
    v16 = "*N*";
  _Warning(a1: "TEXTUREVIDEOMEMORY %s TLVERTEXSYSTEMMEMORY %s TLVERTEXVIDEOMEMORY %s\n", v16, v15, v14);
  _Warning(a1: "\nPrimitive Caps :\n");
  v17 = " Y ";
  if ( (*(_WORD *)&mode_4[56] & 0x200) == 0 )
    v17 = " N ";
  v18 = " Y ";
  if ( (*(_WORD *)&mode_4[56] & 0x100) == 0 )
    v18 = " N ";
  v19 = " Y ";
  if ( (*(_WORD *)&mode_4[56] & 0x800) == 0 )
    v19 = " N ";
  _Warning(a1: "BLENDOP %s CLIPPLANESCALEDPOINTS %s CLIPTLVERTS %s\n", v19, v18, v17);
  v20 = " Y ";
  if ( (*(_WORD *)&mode_4[56] & 0x400) == 0 )
    v20 = " N ";
  v21 = " Y ";
  if ( (mode_4[56] & 2) == 0 )
    v21 = "*N*";
  v22 = " Y ";
  if ( mode_4[56] >= 0 )
    v22 = " N ";
  _Warning(a1: "COLORWRITEENABLE %s MASKZ %s TSSARGTEMP %s\n", v22, v21, v20);
  _Warning(a1: "\nRaster Caps :\n");
  v23 = " Y ";
  if ( (*(_DWORD *)&mode_4[60] & 0x100000) == 0 )
    v23 = " N ";
  v24 = " Y ";
  if ( (*(_DWORD *)&mode_4[60] & 0x200000) == 0 )
    v24 = " N ";
  v25 = " Y ";
  if ( mode_4[60] >= 0 )
    v25 = " N ";
  v26 = " Y ";
  if ( (*(_WORD *)&mode_4[60] & 0x100) == 0 )
    v26 = " N ";
  v27 = " Y ";
  if ( (*(_DWORD *)&mode_4[60] & 0x10000) == 0 )
    v27 = " N ";
  _Warning(a1: "FOGRANGE %s FOGTABLE %s FOGVERTEX %s ZFOG %s WFOG %s\n", v27, v26, v25, v24, v23);
  v28 = " Y ";
  if ( (mode_4[60] & 0x10) == 0 )
    v28 = "*N*";
  v29 = " Y ";
  if ( (*(_DWORD *)&mode_4[60] & 0x4000000) == 0 )
    v29 = " N ";
  v30 = " Y ";
  if ( (*(_DWORD *)&mode_4[60] & 0x40000) == 0 )
    v30 = " N ";
  v31 = " Y ";
  if ( (*(_WORD *)&mode_4[60] & 0x2000) == 0 )
    v31 = " N ";
  _Warning(a1: "MIPMAPLODBIAS %s WBUFFER %s ZBIAS %s ZTEST %s\n", v31, v30, v29, v28);
  _Warning(a1: "Size of Texture Memory : %d kb\n", g_pHardwareConfig->m_Caps.m_TextureMemorySize / 1024);
  _Warning(a1: "Max Texture Dimensions : %d x %d\n", *(_DWORD *)&mode_4[112], *(_DWORD *)&mode_4[116]);
  if ( *(_DWORD *)&mode_4[128] != 0 )
    _Warning(a1: "Max Texture Aspect Ratio : *%d*\n", *(_DWORD *)&mode_4[128]);
  _Warning(a1: "Max Textures : %d\n", *(_DWORD *)&mode_4[176]);
  _Warning(a1: "\nTexture Caps :\n");
  v32 = "*Y*";
  if ( (mode_4[84] & 0x20) == 0 )
    v32 = " N ";
  v33 = " Y ";
  if ( (*(_DWORD *)&mode_4[84] & 0x10000) == 0 )
    v33 = " N ";
  v34 = " Y ";
  if ( (*(_WORD *)&mode_4[84] & 0x800) == 0 )
    v34 = " N ";
  v35 = " Y ";
  if ( (mode_4[84] & 4) == 0 )
    v35 = " N ";
  _Warning(a1: "ALPHA %s CUBEMAP %s MIPCUBEMAP %s SQUAREONLY %s\n", v35, v34, v33, v32);
  _Warning(a1: "vendor id: 0x%x\n", g_pHardwareConfig->m_ActualCaps.m_VendorID);
  _Warning(a1: "device id: 0x%x\n", g_pHardwareConfig->m_ActualCaps.m_DeviceID);
  _Warning(a1: "SHADERAPI CAPS:\n");
  _Warning(a1: "m_NumSamplers: %d\n", g_pHardwareConfig->m_Caps.m_NumSamplers);
  _Warning(a1: "m_NumVertexSamplers: %d\n", g_pHardwareConfig->m_Caps.m_NumVertexSamplers);
  v36 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 716) & 2) == 0 )
    v36 = "no";
  _Warning(a1: "m_HasSetDeviceGammaRamp: %s\n", v36);
  v37 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 716) & 4) == 0 )
    v37 = "no";
  _Warning(a1: "m_SupportsPixelShaders_2_b: %s\n", v37);
  v38 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 716) & 8) == 0 )
    v38 = "no";
  _Warning(a1: "m_SupportsShaderModel_3_0: %s\n", v38);
  _Warning(a1: "m_SupportsCompressedVertices: %d\n", g_pHardwareConfig->m_Caps.m_SupportsCompressedVertices);
  v39 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 716) & 0x10) == 0 )
    v39 = "no";
  _Warning(a1: "m_bSupportsAnisotropicFiltering: %s\n", v39);
  _Warning(a1: "m_nMaxAnisotropy: %d\n", g_pHardwareConfig->m_Caps.m_nMaxAnisotropy);
  _Warning(a1: "m_MaxTextureWidth: %d\n", g_pHardwareConfig->m_Caps.m_MaxTextureWidth);
  _Warning(a1: "m_MaxTextureHeight: %d\n", g_pHardwareConfig->m_Caps.m_MaxTextureHeight);
  _Warning(a1: "m_MaxTextureAspectRatio: %d\n", g_pHardwareConfig->m_Caps.m_MaxTextureAspectRatio);
  _Warning(a1: "m_MaxPrimitiveCount: %d\n", g_pHardwareConfig->m_Caps.m_MaxPrimitiveCount);
  v40 = "yes";
  if ( *((char *)&g_pHardwareConfig->m_Caps + 716) >= 0 )
    v40 = "no";
  _Warning(a1: "m_ZBiasAndSlopeScaledDepthBiasSupported: %s\n", v40);
  _Warning(a1: "m_NumPixelShaderConstants: %d\n", g_pHardwareConfig->m_Caps.m_NumPixelShaderConstants);
  _Warning(a1: "m_NumVertexShaderConstants: %d\n", g_pHardwareConfig->m_Caps.m_NumVertexShaderConstants);
  _Warning(a1: "m_NumBooleanVertexShaderConstants: %d\n", g_pHardwareConfig->m_Caps.m_NumBooleanVertexShaderConstants);
  _Warning(a1: "m_NumIntegerVertexShaderConstants: %d\n", g_pHardwareConfig->m_Caps.m_NumIntegerVertexShaderConstants);
  _Warning(a1: "m_TextureMemorySize: %d\n", g_pHardwareConfig->m_Caps.m_TextureMemorySize);
  _Warning(a1: "m_MaxNumLights: %d\n", g_pHardwareConfig->m_Caps.m_MaxNumLights);
  _Warning(a1: "m_MaxVertexShaderBlendMatrices: %d\n", g_pHardwareConfig->m_Caps.m_MaxVertexShaderBlendMatrices);
  v41 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 1) == 0 )
    v41 = "no";
  _Warning(a1: "m_SupportsMipmappedCubemaps: %s\n", v41);
  _Warning(a1: "m_nDXSupportLevel: %d\n", g_pHardwareConfig->m_Caps.m_nDXSupportLevel);
  v42 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 2) == 0 )
    v42 = "no";
  _Warning(a1: "m_PreferDynamicTextures: %s\n", v42);
  _Warning(a1: "m_MaxUserClipPlanes: %d\n", g_pHardwareConfig->m_Caps.m_MaxUserClipPlanes);
  v43 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 4) == 0 )
    v43 = "no";
  _Warning(a1: "m_SupportsSRGB: %s\n", v43);
  m_HDRType = g_pHardwareConfig->m_Caps.m_HDRType;
  if ( m_HDRType != HDR_TYPE_NONE )
  {
    v45 = m_HDRType - 1;
    if ( v45 != 0 )
    {
      if ( v45 == 1 )
        _Warning(a1: "m_HDRType: HDR_TYPE_FLOAT\n");
    }
    else
    {
      _Warning(a1: "m_HDRType: HDR_TYPE_INTEGER\n");
    }
  }
  else
  {
    _Warning(a1: "m_HDRType: HDR_TYPE_NONE\n");
  }
  v46 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 8) == 0 )
    v46 = "no";
  _Warning(a1: "m_UseFastClipping: %s\n", v46);
  _Warning(a1: "m_pShaderDLL: %s\n", g_pHardwareConfig->m_Caps.m_pShaderDLL);
  v47 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 0x10) == 0 )
    v47 = "no";
  _Warning(a1: "m_bNeedsATICentroidHack: %s\n", v47);
  v48 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 717) & 0x20) == 0 )
    v48 = "no";
  _Warning(a1: "m_bDisableShaderOptimizations: %s\n", v48);
  _Warning(a1: "m_MaxSimultaneousRenderTargets: %d\n", g_pHardwareConfig->m_Caps.m_MaxSimultaneousRenderTargets);
  v49 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 4) == 0 )
    v49 = "no";
  _Warning(a1: "m_bPreferZPrepass: %s\n", v49);
  v50 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 8) == 0 )
    v50 = "no";
  _Warning(a1: "m_bSuppressPixelShaderCentroidHackFixup: %s\n", v50);
  v51 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 0x10) == 0 )
    v51 = "no";
  _Warning(a1: "m_bPreferTexturesInHWMemory: %s\n", v51);
  v52 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 0x20) == 0 )
    v52 = "no";
  _Warning(a1: "m_bPreferHardwareSync: %s\n", v52);
  v53 = "yes";
  if ( (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 0x40) == 0 )
    v53 = "no";
  _Warning(a1: "m_bUnsupported: %s\n", v53);
}

//------------------------------------------------------------------------------
// Address: 0x1002D1D0
// Name: public: virtual enum ImageFormat CShaderDeviceDx8::GetBackBufferFormat(void)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CShaderDeviceDx8::GetBackBufferFormat(CShaderDeviceDx8 *this)
{
  return ImageLoader::D3DFormatToImageFormat(format: this->m_PresentParameters.BackBufferFormat);
}

//------------------------------------------------------------------------------
// Address: 0x1002D1E0
// Name: public: virtual void CShaderDeviceDx8::GetBackBufferDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::GetBackBufferDimensions(CShaderDeviceDx8 *this, int *width, int *height)
{
  *width = this->m_PresentParameters.BackBufferWidth;
  *height = this->m_PresentParameters.BackBufferHeight;
}

//------------------------------------------------------------------------------
// Address: 0x1002D200
// Name: protected: void CShaderDeviceDx8::DetectQuerySupport(struct IDirect3DDevice9 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DetectQuerySupport(CShaderDeviceDx8 *this, IDirect3DDevice9 *pD3DDevice)
{
  HRESULT (__stdcall *CreateQuery)(IDirect3DDevice9 *, _D3DQUERYTYPE, IDirect3DQuery9 **); // eax
  int v4; // [esp+Ch] [ebp-4h] BYREF

  if ( this->m_DeviceSupportsCreateQuery == -1 )
  {
    CreateQuery = pD3DDevice->CreateQuery;
    v4 = 0;
    if ( CreateQuery(this: pD3DDevice, a2: D3DQUERYTYPE_EVENT, a3: (IDirect3DQuery9 **)&v4) >= 0 && v4 != 0 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
      this->m_DeviceSupportsCreateQuery = 1;
    }
    else
    {
      this->m_DeviceSupportsCreateQuery = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D260
// Name: protected: struct IDirect3DDevice9 __near * CShaderDeviceDx8::InvokeCreateDevice(void __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
IDirect3DDevice9 *__thiscall CShaderDeviceDx8::InvokeCreateDevice(
        CShaderDeviceDx8 *this,
        HWND__ *hWnd,
        unsigned int nAdapter,
        unsigned int deviceCreationFlags)
{
  int v5; // eax
  unsigned int v6; // ebx
  _D3DPRESENT_PARAMETERS_ *p_m_PresentParameters; // esi
  int v8; // eax
  IDirect3DDevice9 *v9; // edx
  IConVar *m_pConVar; // ecx
  IDirect3DDevice9 *v12; // [esp+60h] [ebp-10h] BYREF
  ConVarRef mat_queue_mode; // [esp+64h] [ebp-Ch] BYREF
  int v14; // [esp+6Ch] [ebp-4h]

  mat_queue_mode.m_pConVar = (IConVar *)this;
  v12 = nullptr;
  ConVarRef::ConVarRef(this: (ConVarRef *)&mat_queue_mode.m_pConVarState, pName: "mat_queue_mode");
  v5 = *(_DWORD *)(v14 + 48);
  if ( v5 == 2
    || v5 == -2 && *(_BYTE *)(_GetCPUInformation() + 6) >= 2u
    || *(_DWORD *)(v14 + 48) == -1 && *(_BYTE *)(_GetCPUInformation() + 6) >= 2u )
  {
    v6 = deviceCreationFlags | 4;
  }
  else
  {
    v6 = deviceCreationFlags;
  }
  p_m_PresentParameters = &this->m_PresentParameters;
  v8 = g_pShaderDeviceMgrDx8->m_pD3D->CreateDevice(
         this: g_pShaderDeviceMgrDx8->m_pD3D,
         a2: nAdapter,
         a3: D3DDEVTYPE_HAL,
         a4: hWnd,
         a5: v6,
         a6: p_m_PresentParameters,
         a7: &v12);
  if ( v8 < 0 || (v9 = v12, v12 == nullptr) )
  {
    Sleep(dwMilliseconds: 0x3E8u);
    v8 = g_pShaderDeviceMgrDx8->m_pD3D->CreateDevice(
           this: g_pShaderDeviceMgrDx8->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: hWnd,
           a5: v6,
           a6: p_m_PresentParameters,
           a7: &v12);
    v9 = v12;
    if ( v8 < 0 || v12 == nullptr )
    {
      m_pConVar = mat_queue_mode.m_pConVar;
      if ( mat_queue_mode.m_pConVar[20].__vftable != nullptr )
      {
        mat_queue_mode.m_pConVar[18].__vftable = (IConVar_vtbl *)3;
        m_pConVar[15].__vftable = nullptr;
        v8 = g_pShaderDeviceMgrDx8->m_pD3D->CreateDevice(
               this: g_pShaderDeviceMgrDx8->m_pD3D,
               a2: nAdapter,
               a3: D3DDEVTYPE_HAL,
               a4: hWnd,
               a5: v6,
               a6: p_m_PresentParameters,
               a7: &v12);
        v9 = v12;
      }
    }
  }
  if ( v8 >= 0 && v9 != nullptr )
  {
    g_pShaderDeviceMgr->InvokeDeviceResetNotifications(
      this: g_pShaderDeviceMgr,
      a2: v9,
      a3: p_m_PresentParameters,
      a4: hWnd);
    return v12;
  }
  else
  {
    v12 = nullptr;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_EngineInitialization, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_EngineInitialization,
        a2: 1,
        a3: "Failed to create %s device! Please see the following for more info.\n"
        "http://support.steampowered.com/cgi-bin/steampowered.cfg/php/enduser/std_adp.php?p_faqid=772\n",
        "D3D");
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D3D0
// Name: protected: bool CShaderDeviceDx8::CreateD3DDevice(void __near *,int,struct ShaderDeviceInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CShaderDeviceDx8::CreateD3DDevice(
        CShaderDeviceDx8 *this,
        HWND__ *pHWnd,
        int nAdapter,
        const ShaderDeviceInfo_t *info)
{
  int v6; // ebx
  IDirect3DDevice9 *v7; // eax
  IDirect3DDevice9 *v8; // ebx
  D3DDeviceWrapper *v9; // eax
  char v10; // cl
  char v11; // al
  bool v12; // al
  void (__thiscall *GetWindowSize)(struct CShaderDeviceDx8 *, int *, int *); // eax
  CShaderDeviceMgrBase::AdapterInfo_t *HardwareCaps; // eax
  ImageFormat v15; // [esp+0h] [ebp-158h]
  _BYTE mode_4[56]; // [esp+10h] [ebp-148h] OVERLAPPED BYREF

  D3DPERF_SetOptions(a1: 1);
  if ( g_pShaderDeviceMgrDx8->m_pD3D->GetDeviceCaps(
         this: g_pShaderDeviceMgrDx8->m_pD3D,
         a2: nAdapter,
         a3: D3DDEVTYPE_HAL,
         a4: (_D3DCAPS9 *)&mode_4[24]) < 0 )
    return 0;
  memset(&mode_4[4], 0, 20);
  *(_DWORD *)mode_4 = 1;
  g_pShaderDeviceMgrDx8->GetCurrentModeInfo(
    this: g_pShaderDeviceMgrDx8,
    a2: (ShaderDisplayMode_t *)mode_4,
    a3: nAdapter);
  v15 = *(_DWORD *)&mode_4[12];
  this->m_AdapterFormat = *(_DWORD *)&mode_4[12];
  InitializeColorInformation(displayAdapter: nAdapter, deviceType: D3DDEVTYPE_HAL, displayFormat: v15);
  if ( (*((_BYTE *)&CShaderDeviceMgrBase::GetHardwareCaps(this: &g_ShaderDeviceMgrDx8, nAdapter)->m_ActualCaps + 718)
      & 0x10) != 0 )
  {
    v6 = 32;
  }
  else
  {
    v6 = 64;
    if ( (*(_DWORD *)&mode_4[52] & 0x100000) != 0 )
      v6 = 80;
  }
  CShaderDeviceDx8::SetPresentParameters(this, hWnd: pHWnd, nAdapter, info, bSetSymbolsOnly: IMAGE_FORMAT_RGBA8888);
  CShaderDeviceBase::SendIPCMessage(this, msg: 1584664032);
  v7 = CShaderDeviceDx8::InvokeCreateDevice(this, hWnd: pHWnd, nAdapter, deviceCreationFlags: v6 | 2);
  v8 = v7;
  if ( v7 == nullptr )
    return 0;
  CShaderDeviceDx8::DetectQuerySupport(this, pD3DDevice: v7);
  v9 = Dx9Device();
  v9->m_pD3DDevice = v8;
  v9->m_pPresentParameters = &this->m_PresentParameters;
  v9->m_pHWnd = pHWnd;
  CShaderDeviceBase::SendIPCMessage(this, msg: 1584664033);
  *((_BYTE *)this + 172) &= ~2u;
  *((_BYTE *)&this->CShaderDeviceBase + 16) &= ~2u;
  v10 = *((_BYTE *)this + 172);
  this->m_hWnd = pHWnd;
  this->m_DisplayAdapter = nAdapter;
  this->m_nAdapter = nAdapter;
  this->m_DeviceState = DEVICE_STATE_OK;
  v11 = *((_BYTE *)info + 52);
  v12 = (v11 & 1) != 0 && (v11 & 2) != 0;
  *((_BYTE *)this + 172) = v10 ^ (v10 ^ (4 * v12)) & 4;
  GetWindowSize = this->GetWindowSize;
  this->m_ViewHWnd = pHWnd;
  GetWindowSize(this, a2: &this->m_nWindowWidth, a3: &this->m_nWindowHeight);
  HardwareCaps = CShaderDeviceMgrBase::GetHardwareCaps(this: &g_ShaderDeviceMgrDx8, nAdapter);
  CHardwareConfig::SetupHardwareCaps(this: g_pHardwareConfig, mode: info, actualCaps: &HardwareCaps->m_ActualCaps);
  g_pHardwareConfig->m_Caps.m_SupportsCompressedTextures = COMPRESSED_TEXTURES_ON;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002D590
// Name: public: virtual void CShaderDeviceDx8::HandleThreadEvent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::HandleThreadEvent(CShaderDeviceDx8 *this, unsigned int threadEvent)
{
  switch ( threadEvent )
  {
    case 1u:
      this->ReleaseResources(this, a2: true);
      break;
    case 2u:
      this->ReacquireResources(this);
      break;
    case 4u:
      this->EvictManagedResourcesInternal(this);
      break;
    case 5u:
      this->OtherAppInitializing(this, a2: true);
      break;
    case 6u:
      this->OtherAppInitializing(this, a2: false);
      break;
    case 7u:
      this->ResetRenderState(this, a2: true);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D620
// Name: protected: bool CShaderDeviceDx8::TryDeviceReset(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceDx8::TryDeviceReset(CShaderDeviceDx8 *this)
{
  D3DDeviceWrapper *v3; // esi
  int v4; // eax
  bool v5; // bl
  D3DDeviceWrapper *v6; // eax

  if ( (*((_BYTE *)this + 172) & 0x20) == 0 )
    return false;
  v3 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v3);
  v4 = v3->m_pD3DDevice->Reset(this: v3->m_pD3DDevice, a2: &this->m_PresentParameters);
  v5 = v4 >= 0;
  if ( v4 >= 0 )
  {
    *((_BYTE *)this + 172) &= ~0x20u;
    v6 = Dx9Device();
    g_pShaderDeviceMgr->InvokeDeviceResetNotifications(
      this: g_pShaderDeviceMgr,
      a2: v6->m_pD3DDevice,
      a3: v6->m_pPresentParameters,
      a4: v6->m_pHWnd);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002D690
// Name: protected: void CShaderDeviceDx8::MarkDeviceLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::MarkDeviceLost(CShaderDeviceDx8 *this)
{
  *((_BYTE *)this + 172) |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x1002D6A0
// Name: protected: void CShaderDeviceDx8::FreeNonInteractiveRefreshObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::FreeNonInteractiveRefreshObjects(CShaderDeviceDx8 *this)
{
  IDirect3DVertexShader9 *m_pVertexShader; // eax
  IDirect3DPixelShader9 *m_pPixelShader; // eax
  IDirect3DPixelShader9 *m_pPixelShaderStartup; // eax
  IDirect3DPixelShader9 *m_pPixelShaderStartupPass2; // eax
  IDirect3DVertexDeclaration9 *m_pVertexDecl; // eax

  m_pVertexShader = this->m_NonInteractiveRefresh.m_pVertexShader;
  if ( m_pVertexShader != nullptr )
  {
    m_pVertexShader->Release(this: m_pVertexShader);
    this->m_NonInteractiveRefresh.m_pVertexShader = nullptr;
  }
  m_pPixelShader = this->m_NonInteractiveRefresh.m_pPixelShader;
  if ( m_pPixelShader != nullptr )
  {
    m_pPixelShader->Release(this: this->m_NonInteractiveRefresh.m_pPixelShader);
    this->m_NonInteractiveRefresh.m_pPixelShader = nullptr;
  }
  m_pPixelShaderStartup = this->m_NonInteractiveRefresh.m_pPixelShaderStartup;
  if ( m_pPixelShaderStartup != nullptr )
  {
    m_pPixelShaderStartup->Release(this: this->m_NonInteractiveRefresh.m_pPixelShaderStartup);
    this->m_NonInteractiveRefresh.m_pPixelShaderStartup = nullptr;
  }
  m_pPixelShaderStartupPass2 = this->m_NonInteractiveRefresh.m_pPixelShaderStartupPass2;
  if ( m_pPixelShaderStartupPass2 != nullptr )
  {
    m_pPixelShaderStartupPass2->Release(this: this->m_NonInteractiveRefresh.m_pPixelShaderStartupPass2);
    this->m_NonInteractiveRefresh.m_pPixelShaderStartupPass2 = nullptr;
  }
  m_pVertexDecl = this->m_NonInteractiveRefresh.m_pVertexDecl;
  if ( m_pVertexDecl != nullptr )
  {
    m_pVertexDecl->Release(this: this->m_NonInteractiveRefresh.m_pVertexDecl);
    this->m_NonInteractiveRefresh.m_pVertexDecl = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D730
// Name: public: virtual void CShaderDeviceDx8::SetHardwareGammaRamp(float,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CShaderDeviceDx8::SetHardwareGammaRamp(
        CShaderDeviceDx8 *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<esi>,
        float fGamma,
        float fGammaTVRangeMin,
        float fGammaTVRangeMax,
        float fGammaTVExponent,
        bool bTVEnabled)
{
  int i; // esi
  int v9; // ecx
  int v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // eax
  D3DDeviceWrapper *v15; // esi
  long double v16; // [esp+0h] [ebp-61Ch]
  long double y; // [esp+8h] [ebp-614h]
  _BYTE v18[1031]; // [esp+14h] [ebp-608h] OVERLAPPED BYREF

  _DevMsg(a1: 2, a2: "SetHardwareGammaRamp( %f )\n", fGamma);
  if ( Dx9Device() != nullptr )
  {
    v16 = COERCE_DOUBLE(__PAIR64__(a2, a3));
    for ( i = 0; i < 256; *(_WORD *)&v18[2 * i + 1030] = *(_WORD *)v18 )
    {
      __libm_sse2_pow(x: v16, y);
      *(float *)&v10 = 1.0;
      v11 = (float)i * 0.0039215689;
      *(float *)&y = v11;
      if ( v11 > 1.0 || (*(float *)&v10 = 0.0, v11 < 0.0) )
      {
        v11 = *(float *)&v10;
        LODWORD(y) = v10;
      }
      if ( bTVEnabled )
      {
        __libm_sse2_pow(x: v16, y);
        v12 = v11;
        if ( v11 <= 1.0 )
        {
          if ( v11 < 0.0 )
            v12 = 0.0;
        }
        else
        {
          v12 = 1.0;
        }
        v13 = (float)((float)((float)(fGammaTVRangeMax - fGammaTVRangeMin) * v12) * 0.0039215689)
            + (float)(fGammaTVRangeMin * 0.0039215689);
        *(float *)&y = v13;
        if ( v13 <= 1.0 )
        {
          if ( v13 < 0.0 )
            LODWORD(y) = 0;
        }
        else
        {
          LODWORD(y) = 1065353216;
        }
      }
      ++i;
      *(_QWORD *)v18 = (__int64)(*(float *)&y * 65535.0);
      *(_WORD *)&v18[2 * i + 6] = *(_WORD *)v18;
      *(_WORD *)&v18[2 * i + 518] = *(_WORD *)v18;
    }
    v14 = _CommandLine(a1: v9);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-nogammaramp") == 0 )
    {
      v15 = Dx9Device();
      D3DDeviceWrapper::Synchronize(this: v15);
      v15->m_pD3DDevice->SetGammaRamp(this: v15->m_pD3DDevice, a2: 0, a3: 0, a4: (const _D3DGAMMARAMP *)&v18[8]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D900
// Name: public: virtual class IShaderBuffer __near * CShaderDeviceDx8::CompileShader(char const __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IShaderBuffer *__thiscall CShaderDeviceDx8::CompileShader(
        CShaderDeviceDx8 *this,
        const char *pProgram,
        unsigned int nBufLen,
        const char *pShaderVersion)
{
  return g_pShaderManager->CompileShader(this: g_pShaderManager, a2: pProgram, a3: nBufLen, a4: pShaderVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1002D910
// Name: public: virtual struct VertexShaderHandle_t__ __near * CShaderDeviceDx8::CreateVertexShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
VertexShaderHandle_t__ *__thiscall CShaderDeviceDx8::CreateVertexShader(CShaderDeviceDx8 *this, IShaderBuffer *pBuffer)
{
  return g_pShaderManager->CreateVertexShader_2(this: g_pShaderManager, a2: pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x1002D920
// Name: public: virtual void CShaderDeviceDx8::DestroyVertexShader(struct VertexShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DestroyVertexShader(CShaderDeviceDx8 *this, VertexShaderHandle_t__ *hShader)
{
  g_pShaderManager->DestroyVertexShader(this: g_pShaderManager, a2: hShader);
}

//------------------------------------------------------------------------------
// Address: 0x1002D930
// Name: public: virtual struct PixelShaderHandle_t__ __near * CShaderDeviceDx8::CreatePixelShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
PixelShaderHandle_t__ *__thiscall CShaderDeviceDx8::CreatePixelShader(CShaderDeviceDx8 *this, IShaderBuffer *pBuffer)
{
  return g_pShaderManager->CreatePixelShader_2(this: g_pShaderManager, a2: pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x1002D940
// Name: public: virtual void CShaderDeviceDx8::DestroyPixelShader(struct PixelShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DestroyPixelShader(CShaderDeviceDx8 *this, PixelShaderHandle_t__ *hShader)
{
  g_pShaderManager->DestroyPixelShader(this: g_pShaderManager, a2: hShader);
}

//------------------------------------------------------------------------------
// Address: 0x1002D950
// Name: public: virtual class IMesh __near * CShaderDeviceDx8::CreateStaticMesh(unsigned __int64,char const __near *,class IMaterial __near *,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
IMesh *__thiscall CShaderDeviceDx8::CreateStaticMesh(
        CShaderDeviceDx8 *this,
        unsigned __int64 vertexFormat,
        const char *pTextureBudgetGroup,
        IMaterial *pMaterial,
        VertexStreamSpec_t *pStreamSpec)
{
  CMeshMgr *v5; // eax

  v5 = MeshMgr();
  return ((IMesh *(__thiscall *)(CMeshMgr *, _DWORD, _DWORD, const char *, IMaterial *, VertexStreamSpec_t *))v5->CreateStaticMesh)(
           a1: v5,
           a2: vertexFormat,
           a3: HIDWORD(vertexFormat),
           a4: pTextureBudgetGroup,
           a5: pMaterial,
           a6: pStreamSpec);
}

//------------------------------------------------------------------------------
// Address: 0x1002D980
// Name: public: virtual void CShaderDeviceDx8::DestroyStaticMesh(class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DestroyStaticMesh(CShaderDeviceDx8 *this, IMesh *pMesh)
{
  CMeshMgr *v2; // eax

  v2 = MeshMgr();
  v2->DestroyStaticMesh(this: v2, a2: pMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1002D990
// Name: public: virtual class IVertexBuffer __near * CShaderDeviceDx8::CreateVertexBuffer(enum ShaderBufferType_t,unsigned __int64,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IVertexBuffer *__thiscall CShaderDeviceDx8::CreateVertexBuffer(
        CShaderDeviceDx8 *this,
        ShaderBufferType_t type,
        unsigned __int64 fmt,
        int nVertexCount,
        const char *pBudgetGroup)
{
  CMeshMgr *v5; // eax

  v5 = MeshMgr();
  return ((IVertexBuffer *(__thiscall *)(CMeshMgr *, ShaderBufferType_t, _DWORD, _DWORD, int, const char *))v5->CreateVertexBuffer)(
           a1: v5,
           a2: type,
           a3: fmt,
           a4: HIDWORD(fmt),
           a5: nVertexCount,
           a6: pBudgetGroup);
}

//------------------------------------------------------------------------------
// Address: 0x1002D9C0
// Name: public: virtual void CShaderDeviceDx8::DestroyVertexBuffer(class IVertexBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DestroyVertexBuffer(CShaderDeviceDx8 *this, IVertexBuffer *pVertexBuffer)
{
  CMeshMgr *v2; // eax

  v2 = MeshMgr();
  v2->DestroyVertexBuffer(this: v2, a2: pVertexBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x1002D9D0
// Name: public: virtual class IIndexBuffer __near * CShaderDeviceDx8::CreateIndexBuffer(enum ShaderBufferType_t,enum MaterialIndexFormat_t,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IIndexBuffer *__thiscall CShaderDeviceDx8::CreateIndexBuffer(
        CShaderDeviceDx8 *this,
        ShaderBufferType_t bufferType,
        MaterialIndexFormat_t fmt,
        int nIndexCount,
        const char *pBudgetGroup)
{
  CMeshMgr *v5; // eax

  v5 = MeshMgr();
  return v5->CreateIndexBuffer(this: v5, a2: bufferType, a3: fmt, a4: nIndexCount, a5: pBudgetGroup);
}

//------------------------------------------------------------------------------
// Address: 0x1002D9E0
// Name: public: virtual void CShaderDeviceDx8::DestroyIndexBuffer(class IIndexBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::DestroyIndexBuffer(CShaderDeviceDx8 *this, IIndexBuffer *pIndexBuffer)
{
  CMeshMgr *v2; // eax

  v2 = MeshMgr();
  v2->DestroyIndexBuffer(this: v2, a2: pIndexBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x1002D9F0
// Name: public: virtual class IVertexBuffer __near * CShaderDeviceDx8::GetDynamicVertexBuffer(int,unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
IVertexBuffer *__thiscall CShaderDeviceDx8::GetDynamicVertexBuffer(
        CShaderDeviceDx8 *this,
        int streamID,
        unsigned __int64 vertexFormat,
        int bBuffered)
{
  CMeshMgr *v4; // eax

  v4 = MeshMgr();
  return ((IVertexBuffer *(__thiscall *)(CMeshMgr *, int, _DWORD, _DWORD, int))v4->GetDynamicVertexBuffer_2)(
           a1: v4,
           a2: streamID,
           a3: vertexFormat,
           a4: HIDWORD(vertexFormat),
           a5: bBuffered);
}

//------------------------------------------------------------------------------
// Address: 0x1002DA20
// Name: public: virtual class IIndexBuffer __near * CShaderDeviceDx8::GetDynamicIndexBuffer(void)
// Source: json
//------------------------------------------------------------------------------
IIndexBuffer *__thiscall CShaderDeviceDx8::GetDynamicIndexBuffer(CShaderDeviceDx8 *this)
{
  CMeshMgr *v1; // eax

  v1 = MeshMgr();
  return v1->GetDynamicIndexBuffer(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1002DA60
// Name: private: void CShaderDeviceMgrDx8::CheckVendorDependentAlphaToCoverage(struct HardwareCaps_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShaderDeviceMgrDx8::CheckVendorDependentAlphaToCoverage(
        CShaderDeviceMgrDx8 *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        HardwareCaps_t *pCaps,
        int nAdapter)
{
  char v5; // al
  unsigned int m_VendorID; // ecx
  bool v8; // bl

  *((_BYTE *)pCaps + 718) &= ~2u;
  v5 = *((_BYTE *)pCaps + 718);
  if ( r_emulategl.m_pParent->m_Value.m_nValue == 0 )
  {
    m_VendorID = pCaps->m_VendorID;
    if ( m_VendorID == 4318 )
    {
      v8 = ((int (__stdcall *)(IDirect3D9 *, int, int, int, _DWORD, int, int, int, int))this->m_pD3D->CheckDeviceFormat)(
             a1: this->m_pD3D,
             a2: nAdapter,
             a3: 1,
             a4: 22,
             a5: 0,
             a6: 1,
             a7: 1129272385,
             a8: a3,
             a9: a2) == 0;
      ((void (__stdcall *)(IDirect3D9 *, int, int, int, _DWORD))this->m_pD3D->CheckDeviceFormat)(
        a1: this->m_pD3D,
        a2: nAdapter,
        a3: 1,
        a4: 22,
        a5: 0);
      if ( v8 )
      {
        *((_BYTE *)pCaps + 718) |= 2u;
        pCaps->m_AlphaToCoverageEnableValue = 1129272385;
        pCaps->m_AlphaToCoverageState = 181;
        pCaps->m_AlphaToCoverageDisableValue = 0;
      }
    }
    else if ( m_VendorID == 4098 )
    {
      pCaps->m_AlphaToCoverageState = 154;
      pCaps->m_AlphaToCoverageEnableValue = 827142721;
      pCaps->m_AlphaToCoverageDisableValue = 810365505;
      *((_BYTE *)pCaps + 718) = v5 | 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DB40
// Name: private: void CShaderDeviceMgrDx8::ComputeDXSupportLevel(struct HardwareCaps_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::ComputeDXSupportLevel(CShaderDeviceMgrDx8 *this, HardwareCaps_t *caps)
{
  char v2; // cl

  if ( (*((_BYTE *)caps + 719) & 1) == 0 || r_emulategl.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = *((_BYTE *)caps + 716);
    if ( (v2 & 8) != 0 )
    {
      caps->m_nMinDXSupportLevel = 90;
      caps->m_nMaxDXSupportLevel = 95;
    }
    else
    {
      caps->m_nMinDXSupportLevel = 90;
      if ( (v2 & 4) != 0 )
        caps->m_nMaxDXSupportLevel = 92;
      else
        caps->m_nMaxDXSupportLevel = 90;
    }
  }
  else
  {
    caps->m_nMinDXSupportLevel = 92;
    caps->m_nMaxDXSupportLevel = 100;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DC00
// Name: public: virtual bool CShaderDeviceDx8::InitDevice(void __near *,int,struct ShaderDeviceInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceDx8::InitDevice(
        CShaderDeviceDx8 *this,
        HWND__ *hwnd,
        int nAdapter,
        const ShaderDeviceInfo_t *info)
{
  char result; // al

  result = CShaderDeviceDx8::CreateD3DDevice(this, pHWnd: hwnd, nAdapter, info);
  if ( result != 0 )
  {
    CShaderDeviceBase::InstallWindowHook(this, hWnd: (HWND)this->m_hWnd);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002DC40
// Name: protected: void CShaderDeviceDx8::AllocFrameSyncTextureObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::AllocFrameSyncTextureObject(CShaderDeviceDx8 *this)
{
  IDirect3DTexture9 *m_pFrameSyncTexture; // eax
  IDirect3DTexture9 **p_m_pFrameSyncTexture; // esi
  D3DDeviceWrapper *v3; // edi

  m_pFrameSyncTexture = this->m_pFrameSyncTexture;
  p_m_pFrameSyncTexture = &this->m_pFrameSyncTexture;
  if ( m_pFrameSyncTexture != nullptr )
  {
    m_pFrameSyncTexture->Release(this: m_pFrameSyncTexture);
    *p_m_pFrameSyncTexture = nullptr;
  }
  v3 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v3);
  if ( v3->m_pD3DDevice->CreateTexture(
         this: v3->m_pD3DDevice,
         a2: 1u,
         a3: 1u,
         a4: 0,
         a5: 512u,
         a6: D3DFMT_A8R8G8B8,
         a7: D3DPOOL_DEFAULT,
         a8: p_m_pFrameSyncTexture,
         a9: nullptr) < 0 )
    *p_m_pFrameSyncTexture = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DCA0
// Name: protected: void CShaderDeviceDx8::AllocFrameSyncObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::AllocFrameSyncObjects(CShaderDeviceDx8 *this)
{
  unsigned int v1; // ebx
  unsigned int v3; // eax
  IDirect3DQuery9 **v4; // ecx
  IDirect3DQuery9 **m_pFrameSyncQueryObject; // edi
  D3DDeviceWrapper *v6; // esi

  v1 = 0;
  if ( mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: CShaderAPIDX8::AllocFrameSyncObjects\n");
  CShaderDeviceDx8::AllocFrameSyncTextureObject(this);
  if ( this->m_DeviceSupportsCreateQuery != 0 )
  {
    m_pFrameSyncQueryObject = this->m_pFrameSyncQueryObject;
    do
    {
      v6 = Dx9Device();
      D3DDeviceWrapper::Synchronize(this: v6);
      if ( v6->m_pD3DDevice->CreateQuery(this: v6->m_pD3DDevice, a2: D3DQUERYTYPE_EVENT, a3: m_pFrameSyncQueryObject) == -2005530518 )
      {
        _Warning(a1: "D3DQUERYTYPE_EVENT not available on this driver\n");
      }
      else
      {
        (*m_pFrameSyncQueryObject)->Issue(this: *m_pFrameSyncQueryObject, a2: 1u);
        this->m_bQueryIssued[v1] = true;
      }
      ++v1;
      ++m_pFrameSyncQueryObject;
    }
    while ( v1 < 2 );
  }
  else
  {
    v3 = 0;
    v4 = this->m_pFrameSyncQueryObject;
    do
    {
      *v4 = nullptr;
      this->m_bQueryIssued[v3++] = false;
      ++v4;
    }
    while ( v3 < 2 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DD50
// Name: protected: void CShaderDeviceDx8::FreeFrameSyncObjects(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CShaderDeviceDx8::FreeFrameSyncObjects(CShaderDeviceDx8 *this)
{
  IDirect3DTexture9 *m_pFrameSyncTexture; // eax
  unsigned int v3; // ebp
  IDirect3DQuery9 **m_pFrameSyncQueryObject; // esi
  int v5; // edi
  _DWORD dummyData[3]; // [esp+14h] [ebp-Ch] OVERLAPPED BYREF

  if ( mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: CShaderAPIDX8::FreeFrameSyncObjects\n");
  m_pFrameSyncTexture = this->m_pFrameSyncTexture;
  if ( m_pFrameSyncTexture != nullptr )
  {
    m_pFrameSyncTexture->Release(this: this->m_pFrameSyncTexture);
    this->m_pFrameSyncTexture = nullptr;
  }
  v3 = 0;
  m_pFrameSyncQueryObject = this->m_pFrameSyncQueryObject;
  do
  {
    if ( *m_pFrameSyncQueryObject != nullptr )
    {
      if ( this->m_bQueryIssued[v3] )
      {
        *(double *)&dummyData[1] = _Plat_FloatTime();
        dummyData[0] = 0;
        do
          v5 = (*m_pFrameSyncQueryObject)->GetData(this: *m_pFrameSyncQueryObject, a2: dummyData, a3: 4u, a4: 1u);
        while ( _Plat_FloatTime() - *(double *)&dummyData[1] <= 2.0 && v5 == 1 );
      }
      (*m_pFrameSyncQueryObject)->Release(this: *m_pFrameSyncQueryObject);
      *m_pFrameSyncQueryObject = nullptr;
      this->m_bQueryIssued[v3] = false;
    }
    ++v3;
    ++m_pFrameSyncQueryObject;
  }
  while ( v3 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x1002DE20
// Name: public: virtual void CShaderDeviceDx8::ReleaseResources(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::ReleaseResources(CShaderDeviceDx8 *this, BOOL bReleaseManagedResources)
{
  int m_numReleaseResourcesRefCount; // eax
  CMeshMgr *v4; // eax

  if ( CShaderDeviceBase::ThreadOwnsDevice(this) && (unsigned __int8)_ThreadInMainThread() != 0 )
  {
    m_numReleaseResourcesRefCount = this->m_numReleaseResourcesRefCount;
    this->m_numReleaseResourcesRefCount = m_numReleaseResourcesRefCount + 1;
    if ( m_numReleaseResourcesRefCount != 0 )
    {
      _Warning(a1: "ReleaseResources has no effect, now at level %d.\n", m_numReleaseResourcesRefCount + 1);
      DevWarning(a1: "ReleaseResources called twice is a bug: use IsDeactivated to check for a valid device.\n");
    }
    else
    {
      if ( g_pShaderAPI != nullptr )
      {
        g_pShaderAPI->BeginPIXEvent(this: g_pShaderAPI, a2: -682993u, a3: "ReleaseResources");
        if ( g_pShaderAPI != nullptr )
          g_pShaderAPI->EndPIXEvent(this: g_pShaderAPI);
      }
      CShaderDeviceDx8::FreeFrameSyncObjects(this);
      CShaderDeviceDx8::FreeNonInteractiveRefreshObjects(this);
      g_pShaderUtil->ReleaseShaderObjects(this: g_pShaderUtil, a2: bReleaseManagedResources ? 2 : 0);
      v4 = MeshMgr();
      v4->ReleaseBuffers(this: v4);
      g_pShaderAPI->ReleaseShaderObjects(this: g_pShaderAPI, a2: bReleaseManagedResources);
      *((_BYTE *)this + 172) |= 0x20u;
    }
  }
  else
  {
    *((_BYTE *)this + 172) &= ~0x20u;
    g_pShaderUtil->OnThreadEvent(this: g_pShaderUtil, a2: 1u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DF20
// Name: protected: void CShaderDeviceDx8::ReacquireResourcesInternal(bool,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::ReacquireResourcesInternal(
        CShaderDeviceDx8 *this,
        bool bResetState,
        bool bForceReacquire,
        const char *pszForceReason)
{
  const char *v5; // ecx
  CShaderAPIBase *v6; // ecx
  CMeshMgr *v7; // eax

  if ( CShaderDeviceBase::ThreadOwnsDevice(this) && (unsigned __int8)_ThreadInMainThread() != 0 )
  {
    if ( bForceReacquire )
    {
      if ( this->m_numReleaseResourcesRefCount > 1 )
      {
        v5 = pszForceReason;
        if ( pszForceReason == nullptr )
          v5 = "unspecified";
        _Warning(
          a1: "Forcefully resetting device (%s), resources release level was %d.\n",
          v5,
          this->m_numReleaseResourcesRefCount);
      }
      this->m_numReleaseResourcesRefCount = 0;
      goto LABEL_9;
    }
    if ( this->m_numReleaseResourcesRefCount-- == 1 )
    {
LABEL_9:
      if ( bResetState )
        this->ResetRenderState(this, a2: true);
      v6 = g_pShaderAPI;
      if ( g_pShaderAPI != nullptr )
      {
        g_pShaderAPI->BeginPIXEvent(this: g_pShaderAPI, a2: -682993u, a3: "ReacquireResources");
        v6 = g_pShaderAPI;
      }
      v6->RestoreShaderObjects(this: v6);
      CShaderDeviceDx8::AllocFrameSyncObjects(this);
      v7 = MeshMgr();
      v7->RestoreBuffers(this: v7);
      g_pShaderUtil->RestoreShaderObjects(
        this: g_pShaderUtil,
        a2: (void *(__cdecl *)(const char *, int *))CShaderDeviceMgrBase::ShaderInterfaceFactory,
        a3: 0);
      if ( g_pShaderAPI != nullptr )
        g_pShaderAPI->EndPIXEvent(this: g_pShaderAPI);
      return;
    }
    _Warning(a1: "ReacquireResources has no effect, now at level %d.\n", this->m_numReleaseResourcesRefCount);
    DevWarning(a1: "ReacquireResources being discarded is a bug: use IsDeactivated to check for a valid device.\n");
    if ( this->m_numReleaseResourcesRefCount < 0 )
      this->m_numReleaseResourcesRefCount = 0;
  }
  else
  {
    if ( bResetState )
      g_pShaderUtil->OnThreadEvent(this: g_pShaderUtil, a2: 7u);
    g_pShaderUtil->OnThreadEvent(this: g_pShaderUtil, a2: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E080
// Name: protected: bool CShaderDeviceDx8::ResizeWindow(struct ShaderDeviceInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceDx8::ResizeWindow(CShaderDeviceDx8 *this, const ShaderDeviceInfo_t *info)
{
  D3DDeviceWrapper *v3; // ebx
  int v4; // eax

  *((_BYTE *)this + 172) &= ~8u;
  if ( (*((_BYTE *)info + 52) & 2) != 0 )
    return 0;
  CShaderDeviceDx8::SetPresentParameters(
    this,
    hWnd: (HWND__ *)this->m_hWnd,
    nAdapter: this->m_DisplayAdapter,
    info,
    bSetSymbolsOnly: IMAGE_FORMAT_ABGR8888);
  CShaderDeviceMgrBase::InvokeModeChangeCallbacks(
    this: g_pShaderDeviceMgr,
    screenWidth: this->m_PresentParameters.BackBufferWidth,
    screenHeight: this->m_PresentParameters.BackBufferHeight);
  this->ReleaseResources(this, a2: true);
  CShaderDeviceDx8::SetPresentParameters(
    this,
    hWnd: (HWND__ *)this->m_hWnd,
    nAdapter: this->m_DisplayAdapter,
    info,
    bSetSymbolsOnly: IMAGE_FORMAT_RGBA8888);
  v3 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v3);
  v4 = v3->m_pD3DDevice->Reset(this: v3->m_pD3DDevice, a2: &this->m_PresentParameters);
  if ( v4 < 0 )
  {
    _Warning(a1: "ResizeWindow: Reset failed, hr = 0x%08X.\n", v4);
    return 0;
  }
  CShaderDeviceDx8::ReacquireResourcesInternal(
    this,
    bResetState: true,
    bForceReacquire: true,
    pszForceReason: "ResizeWindow");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002E130
// Name: protected: void CShaderDeviceDx8::CheckDeviceLost(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::CheckDeviceLost(CShaderDeviceDx8 *this, bool bOtherAppInitializing)
{
  BOOL v3; // eax
  char v4; // dl
  D3DDeviceWrapper *v5; // edi
  int v6; // edi
  char v7; // al
  bool v8; // [esp+Ch] [ebp-4h]

  v3 = IsIconic(hWnd: (HWND)this->m_hWnd);
  v4 = bOtherAppInitializing ^ *((_BYTE *)this + 172);
  *((_BYTE *)&this->CShaderDeviceBase + 16) ^= (*((_BYTE *)&this->CShaderDeviceBase + 16) ^ (2 * v3)) & 2;
  *((_BYTE *)this + 172) ^= v4 & 1;
  v5 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v5);
  v6 = v5->m_pD3DDevice->TestCooperativeLevel(this: v5->m_pD3DDevice);
  v7 = *((_BYTE *)this + 172);
  if ( (v7 & 2) != 0 )
  {
    if ( v6 == 0 )
      v6 = -2005530519;
    *((_BYTE *)this + 172) = v7 & 0xFD;
  }
  if ( this->m_DeviceState == DEVICE_STATE_OK )
  {
    v8 = g_pShaderUtil->GetThreadMode(this: g_pShaderUtil) != MATERIAL_QUEUED_THREADED;
    if ( v6 != 0 || (*((_BYTE *)&this->CShaderDeviceBase + 16) & 2) != 0 )
    {
      g_pShaderUtil->UncacheUnusedMaterials(this: g_pShaderUtil, a2: true);
      g_pShaderDeviceMgr->InvokeDeviceLostNotifications(this: g_pShaderDeviceMgr);
      this->ReleaseResources(this, a2: v8);
      this->m_DeviceState = DEVICE_STATE_LOST_DEVICE;
    }
    else if ( bOtherAppInitializing )
    {
      g_pShaderUtil->UncacheUnusedMaterials(this: g_pShaderUtil, a2: true);
      g_pShaderDeviceMgr->InvokeDeviceLostNotifications(this: g_pShaderDeviceMgr);
      this->ReleaseResources(this, a2: v8);
      this->m_DeviceState = DEVICE_STATE_OTHER_APP_INIT;
    }
  }
  if ( this->m_DeviceState == DEVICE_STATE_LOST_DEVICE
    && (*((_BYTE *)&this->CShaderDeviceBase + 16) & 2) == 0
    && v6 != -2005530520 )
  {
    this->m_DeviceState = DEVICE_STATE_NEEDS_RESET;
  }
  if ( this->m_DeviceState == DEVICE_STATE_NEEDS_RESET )
  {
    if ( v6 == -2005530520 || (*((_BYTE *)&this->CShaderDeviceBase + 16) & 2) != 0 )
    {
      this->m_DeviceState = DEVICE_STATE_LOST_DEVICE;
    }
    else if ( CShaderDeviceDx8::TryDeviceReset(this) )
    {
      if ( bOtherAppInitializing )
      {
        this->m_DeviceState = DEVICE_STATE_OTHER_APP_INIT;
      }
      else
      {
        this->m_DeviceState = DEVICE_STATE_OK;
        CShaderDeviceDx8::ReacquireResourcesInternal(
          this,
          bResetState: true,
          bForceReacquire: true,
          pszForceReason: "NeedsReset");
      }
    }
  }
  if ( this->m_DeviceState == DEVICE_STATE_OTHER_APP_INIT )
  {
    if ( v6 != 0 || (*((_BYTE *)&this->CShaderDeviceBase + 16) & 2) != 0 )
    {
      this->m_DeviceState = DEVICE_STATE_LOST_DEVICE;
    }
    else if ( !bOtherAppInitializing )
    {
      this->m_DeviceState = DEVICE_STATE_OK;
      CShaderDeviceDx8::ReacquireResourcesInternal(
        this,
        bResetState: true,
        bForceReacquire: true,
        pszForceReason: "OtherAppInit");
    }
  }
  if ( (*((_BYTE *)this + 172) & 8) != 0 && !this->IsDeactivated(this) )
  {
    g_pShaderUtil->UncacheUnusedMaterials(this: g_pShaderUtil, a2: true);
    CShaderDeviceDx8::ResizeWindow(this, info: &this->m_PendingVideoModeChangeConfig);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E330
// Name: protected: void CShaderDeviceDx8::UpdatePresentStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::UpdatePresentStats(CShaderDeviceDx8 *this)
{
  float v2; // xmm0_4
  float m_flTotalDt; // xmm1_4
  float v4; // [esp+4h] [ebp-4h]
  float v5; // [esp+4h] [ebp-4h]

  v4 = _Plat_FloatTime();
  v5 = v4 - this->m_NonInteractiveRefresh.m_flLastPresentTime;
  v2 = v5;
  if ( v5 > this->m_NonInteractiveRefresh.m_flPeakDt )
    this->m_NonInteractiveRefresh.m_flPeakDt = v5;
  if ( v5 > 0.066 )
  {
    ++this->m_NonInteractiveRefresh.m_nCountAbove66;
    if ( mat_spew_long_frames.m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(a1: "****LONG FRAME: %04d>66ms\n", (int)(float)(v5 * 1000.0));
      v2 = v5;
    }
  }
  m_flTotalDt = this->m_NonInteractiveRefresh.m_flTotalDt;
  ++this->m_NonInteractiveRefresh.m_nSamples;
  this->m_NonInteractiveRefresh.m_flTotalDt = m_flTotalDt + v2;
  this->m_NonInteractiveRefresh.m_flLastPresentTime = _Plat_FloatTime();
}

//------------------------------------------------------------------------------
// Address: 0x1002E3D0
// Name: public: virtual void CShaderDeviceDx8::Present(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::Present(CShaderDeviceDx8 *this)
{
  D3DDeviceWrapper *v2; // eax
  D3DDeviceWrapper *v3; // esi
  unsigned int *m_pOutputPtr; // eax
  int v5; // esi
  bool v6; // bl
  D3DDeviceWrapper *v7; // eax
  D3DDeviceWrapper *v8; // esi
  unsigned int *v9; // ecx
  int v10; // eax
  HWND__ *m_ViewHWnd; // eax
  D3DDeviceWrapper *v12; // eax
  CMeshMgr *v13; // eax
  D3DDeviceWrapper *v14; // eax
  D3DDeviceWrapper *v15; // esi
  unsigned int *v16; // ecx
  HWND__ *v17; // [esp+6h] [ebp-54h]
  tagRECT srcRect; // [esp+1Ah] [ebp-40h] BYREF
  tagRECT destRect; // [esp+2Ah] [ebp-30h] BYREF
  ShaderViewport_t viewport; // [esp+3Ah] [ebp-20h] BYREF

  g_pShaderAPI->OnPresent(this: g_pShaderAPI);
  if ( !this->IsDeactivated(this) )
  {
    v2 = Dx9Device();
    v3 = v2;
    if ( v2->m_pASyncThreadHandle != nullptr )
    {
      if ( v2->m_PushBufferFreeSlots == 0 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v2);
      m_pOutputPtr = v3->m_pOutputPtr;
      --v3->m_PushBufferFreeSlots;
      *m_pOutputPtr = 24;
      ++v3->m_pOutputPtr;
    }
    else
    {
      v2->m_pD3DDevice->EndScene(this: v2->m_pD3DDevice);
    }
  }
  v5 = 0;
  v6 = true;
  HIBYTE(srcRect.left) = _ThreadInMainThread();
  if ( HIBYTE(srcRect.left) == 0 )
  {
    v6 = this->m_DeviceState == DEVICE_STATE_OK;
    CShaderDeviceDx8::CheckDeviceLost(this, bOtherAppInitializing: *((_BYTE *)this + 172) & 1);
    if ( this->m_DeviceState != DEVICE_STATE_OK )
      v6 = false;
  }
  if ( this->m_NonInteractiveRefresh.m_Mode == MATERIAL_NON_INTERACTIVE_MODE_LEVEL_LOAD )
    g_pShaderAPI->CopyRenderTargetToTextureEx(
      this: g_pShaderAPI,
      a2: this->m_NonInteractiveRefresh.m_Info.m_hTempFullscreenTexture,
      a3: 0,
      a4: nullptr,
      a5: nullptr);
  if ( !IsIconic(hWnd: (HWND)this->m_hWnd) && v6 )
  {
    if ( (*((_BYTE *)this + 172) & 4) != 0 || this->m_ViewHWnd != this->m_hWnd )
    {
      GetClientRect(hWnd: (HWND)this->m_ViewHWnd, lpRect: (LPRECT)&destRect.top);
      viewport.m_nTopLeftX = 1;
      g_pShaderAPI->GetViewports(this: g_pShaderAPI, a2: (ShaderViewport_t *)&viewport.m_nTopLeftX, a3: 1);
      srcRect.top = viewport.m_nTopLeftY;
      srcRect.right = viewport.m_nWidth;
      m_ViewHWnd = (HWND__ *)this->m_ViewHWnd;
      srcRect.bottom = viewport.m_nTopLeftY + viewport.m_nHeight;
      v17 = m_ViewHWnd;
      destRect.left = viewport.m_nWidth + LODWORD(viewport.m_flMinZ);
      v12 = Dx9Device();
      v10 = D3DDeviceWrapper::Present(
              this: v12,
              pSourceRect: (const tagRECT *)&srcRect.top,
              pDestRect: (const tagRECT *)&destRect.top,
              hDestWindowOverride: v17,
              pDirtyRegion: nullptr);
    }
    else
    {
      g_pShaderAPI->OwnGPUResources(this: g_pShaderAPI, a2: false);
      v7 = Dx9Device();
      v8 = v7;
      if ( v7->m_pASyncThreadHandle != nullptr )
      {
        if ( v7->m_PushBufferFreeSlots < 0x16 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v7);
        v9 = v8->m_pOutputPtr;
        v8->m_PushBufferFreeSlots -= 22;
        *v9 = 25;
        *++v8->m_pOutputPtr = 0;
        v8->m_pOutputPtr += 5;
        *v8->m_pOutputPtr = 0;
        v8->m_pOutputPtr += 5;
        *v8->m_pOutputPtr++ = 0;
        *v8->m_pOutputPtr = 0;
        v8->m_pOutputPtr += 10;
        v5 = 0;
        goto LABEL_23;
      }
      v10 = v7->m_pD3DDevice->Present(this: v7->m_pD3DDevice, a2: nullptr, a3: nullptr, a4: nullptr, a5: nullptr);
    }
    v5 = v10;
  }
LABEL_23:
  CShaderDeviceDx8::UpdatePresentStats(this);
  if ( v5 == -2005530585 )
  {
    _Error(
      a1: "Internal driver error at Present.\n"
      "You're likely out of OS Paged Pool Memory! For more info, see\n"
      "http://support.steampowered.com/cgi-bin/steampowered.cfg/php/enduser/std_adp.php?p_faqid=150\n");
  }
  else if ( v5 == -2005530520 )
  {
    *((_BYTE *)this + 172) |= 2u;
  }
  v13 = MeshMgr();
  v13->DiscardVertexBuffers(this: v13);
  if ( HIBYTE(srcRect.left) != 0 )
    CShaderDeviceDx8::CheckDeviceLost(this, bOtherAppInitializing: *((_BYTE *)this + 172) & 1);
  g_pShaderAPI->AdvancePIXFrame(this: g_pShaderAPI);
  if ( !this->IsDeactivated(this) )
  {
    if ( g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bMeasureFillRate
      || g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bVisualizeFillRate )
    {
      g_pShaderAPI->ClearBuffers(this: g_pShaderAPI, a2: true, a3: true, a4: true, a5: -1, a6: -1);
    }
    v14 = Dx9Device();
    v15 = v14;
    if ( v14->m_pASyncThreadHandle != nullptr )
    {
      if ( v14->m_PushBufferFreeSlots == 0 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v14);
      v16 = v15->m_pOutputPtr;
      --v15->m_PushBufferFreeSlots;
      *v16 = 23;
      ++v15->m_pOutputPtr;
    }
    else
    {
      v14->m_pD3DDevice->BeginScene(this: v14->m_pD3DDevice);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E6D0
// Name: public: bool CShaderDeviceMgrDx8::ComputeCapsFromD3D(struct HardwareCaps_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrDx8::ComputeCapsFromD3D(CShaderDeviceMgrDx8 *this, HardwareCaps_t *pCaps, int nAdapter)
{
  unsigned int DeviceId; // edx
  unsigned int Caps3; // eax
  unsigned int Revision; // ecx
  unsigned __int16 PixelShader1xMaxValue_low; // ax
  char v9; // bl
  char v10; // cl
  bool v11; // dl
  char v12; // al
  unsigned int TextureFilterCaps_high; // ecx
  bool v14; // zf
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  char v18; // al
  char v19; // dl
  unsigned int v20; // ecx
  char v21; // al
  int GuardBandTop_low; // eax
  int v23; // eax
  int m_NumVertexShaderConstants; // eax
  signed int MaxVertexBlendMatrixIndex; // eax
  unsigned int MaxAnisotropy; // eax
  signed int MaxTextureRepeat; // edx
  signed int MaxTextureAspectRatio; // ebx
  int v29; // eax
  unsigned int MaxStreamStride; // eax
  char v31; // dl
  unsigned int DestBlendCaps; // eax
  char v33; // al
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // eax
  HRESULT v38; // eax
  HRESULT (__stdcall *CheckDeviceFormat)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, _D3DFORMAT, unsigned int, _D3DRESOURCETYPE, _D3DFORMAT); // edx
  int v40; // eax
  HRESULT (__stdcall *v41)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, _D3DFORMAT, unsigned int, _D3DRESOURCETYPE, _D3DFORMAT); // edx
  int v42; // eax
  HRESULT (__stdcall *v43)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, _D3DFORMAT, unsigned int, _D3DRESOURCETYPE, _D3DFORMAT); // edx
  int v44; // eax
  char v45; // dl
  char v46; // cl
  char v47; // al
  char v48; // dl
  unsigned int m_VendorID; // ebx
  bool v50; // dl
  bool v51; // cl
  bool v52; // al
  int v53; // ecx
  int v54; // eax
  IDirect3D9 *m_pD3D; // [esp+100h] [ebp-5A4h]
  IDirect3D9 *v56; // [esp+100h] [ebp-5A4h]
  IDirect3D9 *v57; // [esp+100h] [ebp-5A4h]
  _D3DCAPS9 caps; // [esp+124h] [ebp-580h] BYREF
  _D3DADAPTER_IDENTIFIER9 ident; // [esp+254h] [ebp-450h] BYREF

  if ( this->m_pD3D->GetDeviceCaps(
         this: this->m_pD3D,
         a2: nAdapter,
         a3: D3DDEVTYPE_HAL,
         a4: (_D3DCAPS9 *)&caps.AdapterOrdinal) < 0
    || this->m_pD3D->GetAdapterIdentifier(
         this: this->m_pD3D,
         a2: nAdapter,
         a3: 2u,
         a4: (_D3DADAPTER_IDENTIFIER9 *)&ident.Driver[4]) < 0 )
  {
    return 0;
  }
  V_strncpy(pDest: pCaps->m_pDriverName, pSrc: &ident.Description[4], maxLen: 512);
  DeviceId = ident.DeviceId;
  pCaps->m_DeviceID = ident.SubSysId;
  pCaps->m_nDriverVersionHigh = ident.VendorId;
  Caps3 = caps.Caps3;
  Revision = ident.Revision;
  pCaps->m_VendorID = DeviceId;
  pCaps->m_Revision = ident.DeviceIdentifier.Data1;
  *((_BYTE *)pCaps + 716) ^= (*((_BYTE *)pCaps + 716) ^ (2 * (Caps3 >> 20))) & 2;
  LOBYTE(DeviceId) = *((_BYTE *)pCaps + 717) ^ (2 * (Caps3 >> 29));
  *((_BYTE *)pCaps + 718) ^= (*((_BYTE *)pCaps + 718) ^ (32 * HIBYTE(caps.ZCmpCaps))) & 0x20;
  PixelShader1xMaxValue_low = LOWORD(caps.PixelShader1xMaxValue);
  *((_BYTE *)pCaps + 717) ^= DeviceId & 2;
  v9 = *((_BYTE *)pCaps + 717);
  pCaps->m_SubSysID = Revision;
  pCaps->m_nDriverVersionLow = ident.DriverVersion.HighPart;
  v10 = *((_BYTE *)pCaps + 716);
  pCaps->m_pShaderDLL[0] = 0;
  pCaps->m_nMaxViewports = 1;
  v11 = PixelShader1xMaxValue_low >= 0x200u && (int)caps.VertexTextureFilterCaps >= 512;
  v12 = v10 & 0xF3 | (4 * (v11 | (2 * (PixelShader1xMaxValue_low >= 0x300u))));
  TextureFilterCaps_high = HIWORD(caps.TextureFilterCaps);
  LOBYTE(TextureFilterCaps_high) = v9 ^ (v9 ^ BYTE2(caps.TextureFilterCaps)) & 1;
  *((_BYTE *)pCaps + 716) = v12;
  *((_BYTE *)pCaps + 717) = TextureFilterCaps_high;
  if ( r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    *((_BYTE *)pCaps + 716) = v12 & 0xF7;
  v14 = (*((_BYTE *)pCaps + 716) & 8) == 0;
  pCaps->m_MaxVertexShader30InstructionSlots = 0;
  pCaps->m_MaxPixelShader30InstructionSlots = 0;
  if ( !v14 )
  {
    TextureFilterCaps_high = *(_DWORD *)ident.Driver;
    pCaps->m_MaxVertexShader30InstructionSlots = caps.MaxPixelShader30InstructionSlots;
    pCaps->m_MaxPixelShader30InstructionSlots = TextureFilterCaps_high;
  }
  *((_BYTE *)pCaps + 718) &= ~0x10u;
  v15 = _CommandLine(a1: TextureFilterCaps_high);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v15 + 12))(a1: v15, a2: "-mat_softwaretl", a3: 0) != 0 )
    *((_BYTE *)pCaps + 718) |= 0x10u;
  if ( (caps.ZCmpCaps & 0x10000) == 0 )
    *((_BYTE *)pCaps + 718) |= 0x10u;
  if ( (*((_BYTE *)pCaps + 718) & 0x10) != 0 )
    ConVar::SetValue(this: (ConVar *)&mat_forcedynamic.IConVar, value: 1);
  v17 = _CommandLine(a1: v16);
  v14 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v17 + 12))(a1: v17, a2: "-glslcontrolflow", a3: 0) == 0;
  v18 = *((_BYTE *)pCaps + 719);
  LOBYTE(caps.Caps) = !v14;
  v19 = v18 & 0x7F | ((r_emulategl.m_pParent->m_Value.m_nValue == 0) << 7);
  v20 = caps.TextureAddressCaps >> 10;
  LOBYTE(v20) = *((_BYTE *)pCaps + 716) & 0xCF;
  v21 = v20 | (16 * (((caps.TextureAddressCaps & 0x400) != 0) | (2 * ((caps.TextureAddressCaps & 0x4000000) != 0))));
  *((_BYTE *)pCaps + 716) = v21;
  v14 = (v21 & 0x10) == 0;
  GuardBandTop_low = LODWORD(caps.GuardBandTop);
  *((_BYTE *)pCaps + 719) = v19;
  pCaps->m_NumSamplers = 16;
  pCaps->m_SupportsCompressedTextures = COMPRESSED_TEXTURES_ON;
  if ( v14 )
    GuardBandTop_low = 1;
  v14 = (*((_BYTE *)pCaps + 718) & 0x10) == 0;
  pCaps->m_nMaxAnisotropy = GuardBandTop_low;
  if ( v14 )
  {
    pCaps->m_NumVertexShaderConstants = caps.DevCaps2;
    v23 = _CommandLine(a1: v20);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v23 + 40))(a1: v23, a2: "-limitvsconst") != 0 )
    {
      m_NumVertexShaderConstants = pCaps->m_NumVertexShaderConstants;
      if ( m_NumVertexShaderConstants > 256 )
        m_NumVertexShaderConstants = 256;
      pCaps->m_NumVertexShaderConstants = m_NumVertexShaderConstants;
    }
  }
  else
  {
    pCaps->m_NumVertexShaderConstants = 256;
  }
  LOBYTE(v20) = *((_BYTE *)pCaps + 716);
  MaxVertexBlendMatrixIndex = caps.MaxVertexBlendMatrixIndex;
  pCaps->m_NumIntegerPixelShaderConstants = 16;
  pCaps->m_NumIntegerVertexShaderConstants = 16;
  pCaps->m_NumBooleanPixelShaderConstants = 16;
  pCaps->m_NumBooleanVertexShaderConstants = 16;
  pCaps->m_MaxNumLights = MaxVertexBlendMatrixIndex;
  pCaps->m_NumPixelShaderConstants = (v20 & 8) != 0 ? 224 : 32;
  if ( MaxVertexBlendMatrixIndex > 4 )
    pCaps->m_MaxNumLights = 4;
  if ( r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    pCaps->m_MaxNumLights = 2 * (LOBYTE(caps.Caps) != 0) + 2;
  if ( (*((_BYTE *)pCaps + 718) & 0x10) != 0 )
    pCaps->m_MaxNumLights = 2;
  MaxAnisotropy = caps.MaxAnisotropy;
  v14 = caps.MaxAnisotropy == 0;
  MaxTextureRepeat = caps.MaxTextureRepeat;
  MaxTextureAspectRatio = caps.MaxTextureAspectRatio;
  pCaps->m_MaxTextureWidth = caps.MaxTextureRepeat;
  pCaps->m_MaxTextureHeight = MaxTextureAspectRatio;
  if ( v14 )
    MaxAnisotropy = 1;
  pCaps->m_MaxTextureDepth = MaxAnisotropy;
  v14 = LODWORD(caps.GuardBandLeft) == 0;
  pCaps->m_MaxTextureAspectRatio = LODWORD(caps.GuardBandLeft);
  if ( v14 )
  {
    v29 = MaxTextureRepeat;
    if ( MaxTextureRepeat <= MaxTextureAspectRatio )
      v29 = MaxTextureAspectRatio;
    pCaps->m_MaxTextureAspectRatio = v29;
  }
  MaxStreamStride = caps.MaxStreamStride;
  v31 = *((_BYTE *)pCaps + 719);
  *((_BYTE *)pCaps + 717) &= 0xCFu;
  pCaps->m_MaxPrimitiveCount = MaxStreamStride;
  DestBlendCaps = caps.DestBlendCaps;
  v14 = (caps.DestBlendCaps & 0x4000000) == 0;
  *((_BYTE *)pCaps + 719) = v31 & 0x83 | 0x30;
  v33 = !v14 && (DestBlendCaps & 0x2000000) != 0;
  LOBYTE(v20) = v20 & 0x7F;
  *((_BYTE *)pCaps + 716) = v20 | (v33 << 7);
  pCaps->m_MaxUserClipPlanes = LODWORD(caps.MaxPointSize);
  v34 = _CommandLine(a1: v20);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v34 + 12))(a1: v34, a2: "-nouserclip", a3: 0) != 0 )
    pCaps->m_MaxUserClipPlanes = 0;
  if ( pCaps->m_MaxUserClipPlanes > 6 )
    pCaps->m_MaxUserClipPlanes = 6;
  *((_BYTE *)pCaps + 720) = *((_BYTE *)pCaps + 720) & 0xF8 | 2;
  LOBYTE(v35) = (*((_BYTE *)pCaps + 717)
               ^ (4
                * (this->m_pD3D->CheckDeviceFormat(
                     this: this->m_pD3D,
                     a2: nAdapter,
                     a3: D3DDEVTYPE_HAL,
                     a4: D3DFMT_X8R8G8B8,
                     a5: 0x10000u,
                     a6: D3DRTYPE_TEXTURE,
                     a7: D3DFMT_DXT1) == 0)))
              & 4;
  *((_BYTE *)pCaps + 717) ^= v35;
  if ( (*((_BYTE *)pCaps + 717) & 4) != 0 )
  {
    LOBYTE(v35) = (*((_BYTE *)pCaps + 717)
                 ^ (4
                  * (this->m_pD3D->CheckDeviceFormat(
                       this: this->m_pD3D,
                       a2: nAdapter,
                       a3: D3DDEVTYPE_HAL,
                       a4: D3DFMT_X8R8G8B8,
                       a5: 327680u,
                       a6: D3DRTYPE_TEXTURE,
                       a7: D3DFMT_A8R8G8B8) == 0)))
                & 4;
    *((_BYTE *)pCaps + 717) ^= v35;
  }
  v36 = _CommandLine(a1: v35);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v36 + 12))(a1: v36, a2: "-nosrgb", a3: 0) != 0 )
    *((_BYTE *)pCaps + 717) &= ~4u;
  *((_BYTE *)pCaps + 716) ^= (*((_BYTE *)pCaps + 716)
                            ^ ((this->m_pD3D->CheckDeviceFormat(
                                  this: this->m_pD3D,
                                  a2: nAdapter,
                                  a3: D3DDEVTYPE_HAL,
                                  a4: D3DFMT_X8R8G8B8,
                                  a5: 0x100000u,
                                  a6: D3DRTYPE_TEXTURE,
                                  a7: D3DFMT_R32F) == 0) << 6))
                           & 0x40;
  if ( r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    *((_BYTE *)pCaps + 716) &= ~0x40u;
  v37 = (*((_BYTE *)pCaps + 716) & 0x40) != 0;
  pCaps->m_NumVertexSamplers = 4 * v37;
  pCaps->m_nMaxVertexTextureDimension = v37 << 12;
  v38 = this->m_pD3D->CheckDeviceFormat(
          this: this->m_pD3D,
          a2: nAdapter,
          a3: D3DDEVTYPE_HAL,
          a4: D3DFMT_X8R8G8B8,
          a5: 0x20000u,
          a6: D3DRTYPE_TEXTURE,
          a7: D3DFMT_A16B16G16R16);
  CheckDeviceFormat = this->m_pD3D->CheckDeviceFormat;
  m_pD3D = this->m_pD3D;
  BYTE2(caps.Caps) = v38 == 0;
  v40 = CheckDeviceFormat(
          this: m_pD3D,
          a2: nAdapter,
          a3: D3DDEVTYPE_HAL,
          a4: D3DFMT_X8R8G8B8,
          a5: 0x20000u,
          a6: D3DRTYPE_TEXTURE,
          a7: D3DFMT_A16B16G16R16F);
  v41 = this->m_pD3D->CheckDeviceFormat;
  v56 = this->m_pD3D;
  LOBYTE(caps.Caps) = v40 == 0;
  v42 = v41(
          this: v56,
          a2: nAdapter,
          a3: D3DDEVTYPE_HAL,
          a4: D3DFMT_X8R8G8B8,
          a5: 524289u,
          a6: D3DRTYPE_TEXTURE,
          a7: D3DFMT_A16B16G16R16F);
  v43 = this->m_pD3D->CheckDeviceFormat;
  v57 = this->m_pD3D;
  HIBYTE(caps.Caps) = v42 == 0;
  v44 = v43(
          this: v57,
          a2: nAdapter,
          a3: D3DDEVTYPE_HAL,
          a4: D3DFMT_X8R8G8B8,
          a5: 524289u,
          a6: D3DRTYPE_TEXTURE,
          a7: D3DFMT_A32B32G32R32F);
  *((_BYTE *)pCaps + 717) &= ~0x80u;
  v45 = *((_BYTE *)pCaps + 718);
  v46 = *((_BYTE *)pCaps + 717);
  *((_BYTE *)pCaps + 719) &= ~1u;
  v47 = v45 & 0xBE | ((v44 == 0) << 6);
  v48 = *((_BYTE *)pCaps + 719);
  *((_BYTE *)pCaps + 718) = v47;
  BYTE1(caps.Caps) = v48;
  if ( (v46 & 4) != 0 )
  {
    m_VendorID = pCaps->m_VendorID;
    if ( m_VendorID == 4318 )
    {
      *((_BYTE *)pCaps + 717) = v46 | 0x80;
      if ( (v47 & 0x40) == 0 )
        goto LABEL_65;
    }
    else
    {
      if ( m_VendorID != 4098 )
        goto LABEL_65;
      v50 = (*((_BYTE *)pCaps + 716) & 8) != 0
         && pCaps->m_MaxVertexShader30InstructionSlots > 1024
         && pCaps->m_MaxPixelShader30InstructionSlots > 512;
      v48 = BYTE1(caps.Caps) ^ (BYTE1(caps.Caps) ^ v50) & 1;
      *((_BYTE *)pCaps + 719) = v48;
      if ( (v48 & 1) == 0 )
        goto LABEL_65;
      *((_BYTE *)pCaps + 717) = v46 | 0x80;
    }
    *((_BYTE *)pCaps + 719) = v48 | 1;
    *((_BYTE *)pCaps + 718) = v47 | 1;
  }
LABEL_65:
  v51 = (BYTE2(caps.Caps) != 0 || LOBYTE(caps.Caps) != 0) && (*((_BYTE *)pCaps + 717) & 4) != 0;
  v52 = (*((_BYTE *)pCaps + 716) & 8) != 0
     && LOBYTE(caps.Caps) != 0
     && HIBYTE(caps.Caps) != 0
     && (*((_BYTE *)pCaps + 717) & 4) != 0;
  pCaps->m_MaxHDRType = HDR_TYPE_NONE;
  if ( !v52 )
  {
    if ( v51 )
    {
      pCaps->m_MaxHDRType = HDR_TYPE_INTEGER;
LABEL_81:
      if ( v51 )
      {
        pCaps->m_HDRType = HDR_TYPE_INTEGER;
        goto LABEL_84;
      }
    }
    pCaps->m_HDRType = HDR_TYPE_NONE;
    goto LABEL_84;
  }
  pCaps->m_MaxHDRType = HDR_TYPE_FLOAT;
  if ( mat_hdr_level.m_pParent->m_Value.m_nValue != 3 )
    goto LABEL_81;
  pCaps->m_HDRType = HDR_TYPE_FLOAT;
LABEL_84:
  *((_BYTE *)pCaps + 717) ^= (*((_BYTE *)pCaps + 717) ^ (LOBYTE(caps.MasterAdapterOrdinal) << 6)) & 0x40;
  if ( r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    *((_BYTE *)pCaps + 717) |= 0x40u;
  pCaps->m_flMinGammaControlPoint = 0.0;
  pCaps->m_flMaxGammaControlPoint = 65535.0;
  pCaps->m_nGammaControlPointCount = 256;
  CShaderDeviceMgrDx8::ComputeDXSupportLevel(this, caps: pCaps);
  v53 = pCaps->m_NumVertexShaderConstants - 58;
  pCaps->m_nDXSupportLevel = pCaps->m_nMaxDXSupportLevel;
  pCaps->m_MaxVertexShaderBlendMatrices = v53 / 3;
  if ( v53 / 3 > 53 )
    pCaps->m_MaxVertexShaderBlendMatrices = 53;
  *((_BYTE *)pCaps + 718) &= ~0x80u;
  pCaps->m_SupportsCompressedVertices = VERTEX_COMPRESSION_ON;
  v54 = _CommandLine(a1: v53);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v54 + 12))(
         a1: v54,
         a2: "-no_compressed_verts",
         a3: 0) != 0 )
    pCaps->m_SupportsCompressedVertices = VERTEX_COMPRESSION_NONE;
  CShaderDeviceMgrDx8::CheckVendorDependentAlphaToCoverage(this, a2: 0, a3: nAdapter, pCaps, nAdapter);
  CShaderDeviceMgrDx8::CheckVendorDependentShadowMappingSupport(this, pCaps, nAdapter);
  if ( (*((_BYTE *)pCaps + 716) & 8) == 0 )
  {
    ConVar::SetValue(this: (ConVar *)&mat_slopescaledepthbias_shadowmap.IConVar, value: 5.9000001);
    ConVar::SetValue(this: (ConVar *)&mat_depthbias_shadowmap.IConVar, value: 0.003);
  }
  if ( pCaps->m_MaxUserClipPlanes == 0 )
    *((_BYTE *)pCaps + 717) |= 8u;
  pCaps->m_MaxSimultaneousRenderTargets = caps.StretchRectFilterCaps;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002EF30
// Name: public: virtual void __near * (*CShaderDeviceMgrDx8::SetMode(void __near *,int,struct ShaderDeviceInfo_t const __near &))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CShaderAPIBase *(__cdecl *__thiscall CShaderDeviceMgrDx8::SetMode(
        CShaderDeviceMgrDx8 *this,
        void *hWnd,
        int nAdapter,
        const ShaderDeviceInfo_t *mode))(const char *pInterfaceName, int *pReturnCode)
{
  int m_nDXLevel; // eax
  CShaderDeviceMgrBase::AdapterInfo_t *m_pMemory; // ebx
  int ClosestActualDXLevel; // ebp
  CShaderDeviceBase *v8; // ecx
  char v9; // bl
  ShaderDeviceInfo_t adjustedMode_4; // [esp+10h] [ebp-38h] OVERLAPPED BYREF

  m_nDXLevel = mode->m_nDXLevel;
  if ( m_nDXLevel == 0 )
    m_nDXLevel = this->m_Adapters.m_Memory.m_pMemory[nAdapter].m_ActualCaps.m_nDXSupportLevel;
  m_pMemory = this->m_Adapters.m_Memory.m_pMemory;
  if ( m_nDXLevel > m_pMemory[nAdapter].m_ActualCaps.m_nMaxDXSupportLevel )
    m_nDXLevel = m_pMemory[nAdapter].m_ActualCaps.m_nMaxDXSupportLevel;
  ClosestActualDXLevel = CShaderDeviceMgrBase::GetClosestActualDXLevel(this, nDxLevel: m_nDXLevel);
  if ( ClosestActualDXLevel > 100 )
    return nullptr;
  v8 = g_pShaderDevice;
  v9 = 0;
  if ( g_pShaderDevice != nullptr )
  {
    v9 = 1;
    g_pShaderDevice->ReleaseResources(this: g_pShaderDevice, a2: true);
    v8 = g_pShaderDevice;
  }
  if ( g_pShaderAPI != nullptr )
  {
    g_pShaderAPI->OnDeviceShutdown(this: g_pShaderAPI);
    v8 = g_pShaderDevice;
    g_pShaderAPI = nullptr;
  }
  if ( v8 != nullptr )
  {
    v8->ShutdownDevice(this: v8);
    g_pShaderDevice = nullptr;
  }
  g_pShaderShadow = nullptr;
  adjustedMode_4 = *mode;
  adjustedMode_4.m_nDXLevel = ClosestActualDXLevel;
  if ( !g_pShaderDeviceDx8->InitDevice(this: g_pShaderDeviceDx8, a2: hWnd, a3: nAdapter, a4: &adjustedMode_4)
    || !g_pShaderAPIDX8->OnDeviceInit(this: g_pShaderAPIDX8) )
  {
    return nullptr;
  }
  g_pShaderDevice = g_pShaderDeviceDx8;
  g_pShaderAPI = g_pShaderAPIDX8;
  g_pShaderShadow = g_pShaderShadowDx8;
  if ( v9 != 0 )
    g_pShaderDeviceDx8->ReacquireResources(this: g_pShaderDeviceDx8);
  return CShaderDeviceMgrBase::ShaderInterfaceFactory;
}

//------------------------------------------------------------------------------
// Address: 0x1002F070
// Name: public: virtual void CShaderDeviceDx8::OtherAppInitializing(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::OtherAppInitializing(CShaderDeviceDx8 *this, bool initializing)
{
  D3DDeviceWrapper *v3; // eax
  D3DDeviceWrapper *v4; // esi
  unsigned int *m_pOutputPtr; // eax
  D3DDeviceWrapper *v6; // eax
  D3DDeviceWrapper *v7; // esi
  unsigned int *v8; // ecx
  IShaderUtil_vtbl *v9; // edx

  if ( CShaderDeviceBase::ThreadOwnsDevice(this) && (unsigned __int8)_ThreadInMainThread() != 0 )
  {
    if ( !this->IsDeactivated(this) )
    {
      v3 = Dx9Device();
      v4 = v3;
      if ( v3->m_pASyncThreadHandle != nullptr )
      {
        if ( v3->m_PushBufferFreeSlots == 0 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v3);
        m_pOutputPtr = v4->m_pOutputPtr;
        --v4->m_PushBufferFreeSlots;
        *m_pOutputPtr = 24;
        ++v4->m_pOutputPtr;
      }
      else
      {
        v3->m_pD3DDevice->EndScene(this: v3->m_pD3DDevice);
      }
    }
    CShaderDeviceDx8::CheckDeviceLost(this, bOtherAppInitializing: initializing);
    if ( !this->IsDeactivated(this) )
    {
      v6 = Dx9Device();
      v7 = v6;
      if ( v6->m_pASyncThreadHandle != nullptr )
      {
        if ( v6->m_PushBufferFreeSlots == 0 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v6);
        v8 = v7->m_pOutputPtr;
        --v7->m_PushBufferFreeSlots;
        *v8 = 23;
        ++v7->m_pOutputPtr;
      }
      else
      {
        ((void (*)(void))v6->m_pD3DDevice->BeginScene)();
      }
    }
  }
  else
  {
    v9 = g_pShaderUtil->__vftable;
    if ( initializing )
      ((void (__stdcall *)(int))v9->OnThreadEvent)(a1: 5);
    else
      ((void (__stdcall *)(int))v9->OnThreadEvent)(a1: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F170
// Name: public: virtual void CShaderDeviceDx8::ReacquireResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx8::ReacquireResources(CShaderDeviceDx8 *this)
{
  CShaderDeviceDx8::ReacquireResourcesInternal(
    this,
    bResetState: false,
    bForceReacquire: false,
    pszForceReason: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002F180
// Name: private: void CShaderDeviceMgrDx8::InitAdapterInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::InitAdapterInfo(CShaderDeviceMgrDx8 *this)
{
  char v2; // al
  CUtlVector<CShaderDeviceMgrBase::AdapterInfo_t,CUtlMemory<CShaderDeviceMgrBase::AdapterInfo_t,int> > *p_m_Adapters; // edi
  int v4; // ebx
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CShaderDeviceMgrBase::AdapterInfo_t *m_pMemory; // ecx
  int v8; // eax
  bool v9; // zf
  int v10; // esi
  int v11; // ecx
  int v12; // eax
  const char *v13; // eax
  int v14; // [esp+Ch] [ebp-4h]

  v2 = *((_BYTE *)this + 72);
  if ( (v2 & 1) == 0 )
  {
    *((_BYTE *)this + 72) = v2 | 1;
    p_m_Adapters = &this->m_Adapters;
    v4 = 0;
    this->m_Adapters.m_Size = 0;
    v14 = this->m_pD3D->GetAdapterCount(this: this->m_pD3D);
    if ( v14 > 0 )
    {
      do
      {
        m_Size = this->m_Adapters.m_Size;
        m_nAllocationCount = this->m_Adapters.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CShaderDeviceMgrBase::AdapterInfo_t,int>::Grow(
            this: &this->m_Adapters.m_Memory,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_Adapters.m_Size;
        m_pMemory = p_m_Adapters->m_Memory.m_pMemory;
        v8 = this->m_Adapters.m_Size - m_Size - 1;
        v9 = this->m_Adapters.m_Size - m_Size == 1;
        this->m_Adapters.m_pElements = this->m_Adapters.m_Memory.m_pMemory;
        if ( v8 >= 0 && !v9 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 728 * v8);
        v10 = (int)&p_m_Adapters->m_Memory.m_pMemory[m_Size];
        *(_BYTE *)(v10 + 716) ^= (CShaderDeviceMgrDx8::ComputeCapsFromD3D(
                                    this,
                                    pCaps: (HardwareCaps_t *)v10,
                                    nAdapter: v4)
                                ^ *(_BYTE *)(v10 + 716))
                               & 1;
        if ( (*(_BYTE *)(v10 + 716) & 1) != 0 )
        {
          CShaderDeviceMgrBase::ReadDXSupportLevels(this, caps: (HardwareCaps_t *)v10);
          CShaderDeviceMgrBase::ReadHardwareCaps(
            this,
            caps: (HardwareCaps_t *)v10,
            nDxLevel: *(KeyValues **)(v10 + 536));
          v12 = _CommandLine(a1: v11);
          v13 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v12 + 32))(
                                a1: v12,
                                a2: "-shader",
                                a3: 0);
          if ( v13 != nullptr )
            V_strncpy(pDest: (char *)(v10 + 632), pSrc: v13, maxLen: 32);
        }
        ++v4;
      }
      while ( v4 < v14 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F290
// Name: public: virtual int CShaderDeviceMgrDx8::GetAdapterCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceMgrDx8::GetAdapterCount(CShaderDeviceMgrDx8 *this)
{
  CShaderDeviceMgrDx8::InitAdapterInfo(this);
  return this->m_Adapters.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1002F2A0
// Name: public: virtual void CShaderDeviceMgrDx8::GetAdapterInfo(int,struct MaterialAdapterInfo_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx8::GetAdapterInfo(
        CShaderDeviceMgrDx8 *this,
        int nAdapter,
        MaterialAdapterInfo_t *info)
{
  CShaderDeviceMgrDx8::InitAdapterInfo(this);
  *info = this->m_Adapters.m_Memory.m_pMemory[nAdapter].m_ActualCaps.MaterialAdapterInfo_t;
}

//------------------------------------------------------------------------------
// Address: 0x1002F2D0
// Name: public: virtual enum InitReturnVal_t CShaderDeviceMgrDx8::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceMgrDx8::Init(CShaderDeviceMgrDx8 *this)
{
  CShaderDeviceMgrDx8::InitAdapterInfo(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002F2E0
// Name: __CreateCShaderShadowDx10IShaderShadow_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CShaderShadowDx10 *__cdecl _CreateCShaderShadowDx10IShaderShadow_interface()
{
  return &s_ShaderShadow;
}

} // namespace shaderapidx10
