// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/shaderdevicedx10.cpp
// Functions: 45
// ============================================================

#include "materialsystem\shaderapidx9\shaderdevicedx10.h"

//------------------------------------------------------------------------------
// Address: 0x1000E1D0
// Name: public: virtual class IMesh __near * CShaderDeviceDx10::CreateStaticMesh(unsigned __int64,char const __near *,class IMaterial __near *,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceDx10::CreateStaticMesh(
        CShaderAPIDx10 *this,
        ImageFormat renderFormat,
        int width,
        int height,
        const char *pDebugName,
        bool bTexture)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10028FE0
// Name: private: static bool CShaderDeviceDx10::InputLayoutLessFunc(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CShaderDeviceDx10::InputLayoutLessFunc(
        const CShaderDeviceDx10::InputLayout_t *lhs,
        const CShaderDeviceDx10::InputLayout_t *rhs)
{
  return lhs->m_VertexFormat < rhs->m_VertexFormat;
}

//------------------------------------------------------------------------------
// Address: 0x10029050
// Name: public: virtual enum InitReturnVal_t CShaderDeviceMgrDx10::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceMgrDx10::Init(CShaderAPIDx10 *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029060
// Name: public: virtual void CShaderDeviceMgrDx10::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx10::Shutdown(CShaderDeviceMgrDx10 *this)
{
  if ( g_pShaderDevice != nullptr )
  {
    g_pShaderDevice->ShutdownDevice(this: g_pShaderDevice);
    g_pShaderDevice = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029080
// Name: private: bool CShaderDeviceMgrDx10::ComputeCapsFromD3D(struct HardwareCaps_t __near *,struct IDXGIAdapter __near *,struct IDXGIOutput __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrDx10::ComputeCapsFromD3D(
        CShaderDeviceMgrDx10 *this,
        HardwareCaps_t *pCaps,
        IDXGIAdapter *pAdapter,
        IDXGIOutput *pOutput)
{
  int v5; // ecx
  int v6; // eax
  bool v7; // bl
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // edx
  char v11; // cl
  int v12; // eax
  float v13; // xmm0_4
  wchar_t pUnicode[128]; // [esp+1Ch] [ebp-1138h] BYREF
  unsigned int v15; // [esp+11Ch] [ebp-1038h]
  unsigned int v16; // [esp+120h] [ebp-1034h]
  unsigned int v17; // [esp+124h] [ebp-1030h]
  unsigned int v18; // [esp+128h] [ebp-102Ch]
  int v19; // [esp+12Ch] [ebp-1028h]
  _BYTE v20[4]; // [esp+140h] [ebp-1014h] BYREF
  float v21; // [esp+144h] [ebp-1010h]
  float v22; // [esp+148h] [ebp-100Ch]
  int v23; // [esp+14Ch] [ebp-1008h]

  if ( pAdapter->CheckInterfaceSupport(this: pAdapter, a2: &_GUID_9b7e4c0f_342c_4106_a19f_4f2704f689f0, a3: nullptr) != 0
    || pAdapter->GetDesc(this: pAdapter, a2: (DXGI_ADAPTER_DESC *)pUnicode) < 0 )
  {
    return 0;
  }
  v6 = _CommandLine(a1: v5);
  v7 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-floathdr", a3: 0) != 0;
  V_UnicodeToUTF8(pUnicode, pUTF8: pCaps->m_pDriverName, cubDestSizeInBytes: 512);
  v8 = v16;
  v9 = v15;
  pCaps->m_SubSysID = v17;
  pCaps->m_DeviceID = v8;
  v10 = v18;
  pCaps->m_NumSamplers = 16;
  pCaps->m_nMaxAnisotropy = 16;
  v11 = *((_BYTE *)pCaps + 716) & 1 | 0xF2;
  pCaps->m_Revision = v10;
  pCaps->m_TextureMemorySize = v19;
  *((_BYTE *)pCaps + 720) |= 3u;
  *((_BYTE *)pCaps + 716) = v11;
  pCaps->m_nDXSupportLevel = 100;
  pCaps->m_nMaxDXSupportLevel = 100;
  pCaps->m_VendorID = v9;
  pCaps->m_HDRType = v7 + 1;
  *((_BYTE *)pCaps + 717) = *((_BYTE *)pCaps + 717) & 0x20 | ((v9 == 4318) << 7) | 0x45;
  LOBYTE(v9) = *((_BYTE *)pCaps + 718) & 0xE5 | (8 * (v9 == 4098));
  pCaps->m_MaxTextureAspectRatio = 1024;
  pCaps->m_NumPixelShaderConstants = 1024;
  pCaps->m_NumVertexShaderConstants = 1024;
  pCaps->m_SupportsCompressedTextures = COMPRESSED_TEXTURES_ON;
  pCaps->m_SupportsCompressedVertices = VERTEX_COMPRESSION_ON;
  pCaps->m_MaxTextureWidth = 0x2000;
  pCaps->m_MaxTextureHeight = 0x2000;
  pCaps->m_MaxTextureDepth = 2048;
  pCaps->m_MaxPrimitiveCount = 0x10000;
  pCaps->m_MaxNumLights = 4;
  pCaps->m_MaxVertexShaderBlendMatrices = 53;
  pCaps->m_MaxUserClipPlanes = 6;
  pCaps->m_pShaderDLL[0] = 0;
  pCaps->m_nMinDXSupportLevel = 92;
  pCaps->m_NumVertexSamplers = 4;
  pCaps->m_nMaxVertexTextureDimension = 0x2000;
  *((_BYTE *)pCaps + 718) = v9 | 0x84;
  pCaps->m_ShadowDepthTextureFormat = IMAGE_FORMAT_UNKNOWN;
  pCaps->m_nMaxViewports = 4;
  pOutput->GetGammaControlCapabilities(this: pOutput, a2: (DXGI_GAMMA_CONTROL_CAPABILITIES *)v20);
  v12 = v23;
  pCaps->m_flMinGammaControlPoint = v22;
  v13 = v21;
  pCaps->m_nGammaControlPointCount = v12;
  pCaps->m_flMaxGammaControlPoint = v13;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100292C0
// Name: private: virtual void CShaderDeviceMgrDx10::GetDesktopResolution(int __near *,int __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx10::GetDesktopResolution(
        CShaderDeviceMgrDx10 *this,
        int *pWidth,
        int *pHeight,
        int nAdapter)
{
  *pWidth = 1024;
  *pHeight = 768;
}

//------------------------------------------------------------------------------
// Address: 0x100292E0
// Name: private: virtual int CShaderDeviceMgrDx10::GetVidMemBytes(int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShaderDeviceMgrDx10::GetVidMemBytes(CShaderDeviceMgrDx10 *this, unsigned int nAdapter)
{
  int v2; // eax
  int v3; // eax
  DXGI_ADAPTER_DESC desc; // [esp+Ch] [ebp-128h] BYREF

  v2 = this->m_pDXGIFactory->EnumAdapters(this: this->m_pDXGIFactory, a2: nAdapter, a3: (IDXGIAdapter **)&desc);
  v3 = v2 < 0 ? 0 : *(_DWORD *)desc.Description;
  if ( v3 == 0 )
    return 0;
  (*(void (__stdcall **)(int, wchar_t *))(*(_DWORD *)v3 + 32))(a1: v3, a2: &desc.Description[2]);
  return desc.DedicatedSystemMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10029340
// Name: private: struct IDXGIOutput __near * CShaderDeviceMgrDx10::GetAdapterOutput(int)const
// Source: json
//------------------------------------------------------------------------------
IDXGIOutput *__thiscall CShaderDeviceMgrDx10::GetAdapterOutput(CShaderDeviceMgrDx10 *this, IDXGIOutput *nAdapter)
{
  int v2; // eax
  int v3; // esi
  int v5; // edi
  DXGI_OUTPUT_DESC desc; // [esp+14h] [ebp-60h] BYREF

  v2 = this->m_pDXGIFactory->EnumAdapters(
         this: this->m_pDXGIFactory,
         a2: (unsigned int)nAdapter,
         a3: (IDXGIAdapter **)&desc);
  v3 = v2 < 0 ? 0 : *(_DWORD *)desc.DeviceName;
  if ( v3 == 0 )
    return nullptr;
  v5 = 0;
  if ( (*(int (__stdcall **)(int, _DWORD, IDXGIOutput **))(*(_DWORD *)v3 + 28))(a1: v3, a2: 0, a3: &nAdapter) == -2005270526 )
    return nullptr;
  while ( nAdapter->GetDesc(this: nAdapter, a2: (DXGI_OUTPUT_DESC *)&desc.DeviceName[2]) < 0
       || desc.Rotation == DXGI_MODE_ROTATION_UNSPECIFIED )
  {
    if ( (*(int (__stdcall **)(int, int, IDXGIOutput **))(*(_DWORD *)v3 + 28))(a1: v3, a2: ++v5, a3: &nAdapter) == -2005270526 )
      return nullptr;
  }
  return nAdapter;
}

//------------------------------------------------------------------------------
// Address: 0x100293E0
// Name: public: virtual int CShaderDeviceMgrDx10::GetModeCount(int)const
// Source: json
//------------------------------------------------------------------------------
IDXGIOutput *__thiscall CShaderDeviceMgrDx10::GetModeCount(CShaderDeviceMgrDx10 *this, IDXGIOutput *nAdapter)
{
  IDXGIOutput *result; // eax
  int v3; // eax

  result = CShaderDeviceMgrDx10::GetAdapterOutput(this, nAdapter);
  if ( result != nullptr )
  {
    nAdapter = nullptr;
    v3 = result->GetDisplayModeList(
           this: result,
           a2: DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
           a3: 0,
           a4: (unsigned int *)&nAdapter,
           a5: nullptr);
    return v3 < 0 ? nullptr : nAdapter;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029420
// Name: public: virtual void CShaderDeviceMgrDx10::GetModeInfo(struct ShaderDisplayMode_t __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx10::GetModeInfo(
        CShaderDeviceMgrDx10 *this,
        unsigned int pInfo,
        IDXGIOutput *nAdapter,
        unsigned int nMode)
{
  ShaderDisplayMode_t *v4; // esi
  IDXGIOutput *AdapterOutput; // eax
  IDXGIOutput *v6; // edi
  void *v7; // esp
  int *v8; // eax
  IDXGIOutput *v9; // [esp-4h] [ebp-10h]
  _DWORD v10[3]; // [esp+0h] [ebp-Ch] BYREF

  v4 = (ShaderDisplayMode_t *)pInfo;
  v9 = nAdapter;
  *(_DWORD *)(pInfo + 8) = 0;
  v4->m_nWidth = 0;
  v4->m_Format = IMAGE_FORMAT_UNKNOWN;
  v4->m_nRefreshRateDenominator = 0;
  v4->m_nRefreshRateNumerator = 0;
  AdapterOutput = CShaderDeviceMgrDx10::GetAdapterOutput(this, nAdapter: v9);
  v6 = AdapterOutput;
  if ( AdapterOutput != nullptr )
  {
    pInfo = 0;
    AdapterOutput->GetDisplayModeList(
      this: AdapterOutput,
      a2: DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
      a3: 1u,
      a4: &pInfo,
      a5: nullptr);
    if ( nMode < pInfo )
    {
      v7 = alloca(28 * pInfo);
      v6->GetDisplayModeList(
        this: v6,
        a2: DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
        a3: 1u,
        a4: &pInfo,
        a5: (DXGI_MODE_DESC *)v10);
      v8 = &v10[7 * nMode];
      v4->m_nWidth = *v8;
      v4->m_nHeight = v8[1];
      v4->m_nRefreshRateNumerator = v8[2];
      v4->m_nRefreshRateDenominator = v8[3];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100294D0
// Name: public: virtual bool CShaderDeviceMgrDx10::SetAdapter(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrDx10::SetAdapter(CBaseMeshDX8 *this, int nVertexCount, int nIndexCount)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100294E0
// Name: public: virtual bool CShaderDeviceDx10::InitDevice(void __near *,int,struct ShaderDeviceInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CShaderDeviceDx10::InitDevice(
        CShaderDeviceDx10 *this,
        void *hWnd,
        IDXGIOutput *nAdapter,
        const ShaderDeviceInfo_t *mode)
{
  int v6; // eax
  IDXGIOutput *AdapterOutput; // eax
  int m_nWidth; // edx
  int m_nRefreshRateNumerator; // ecx
  char v11; // al
  int m_nBackBufferCount; // ecx
  ID3D10Device **p_m_pDevice; // ebx
  void (__thiscall *GetWindowSize)(struct CShaderDeviceDx10 *, int *, int *); // eax
  CShaderDeviceMgrBase::AdapterInfo_t *HardwareCaps; // eax
  ID3D10Resource *v16; // [esp+30h] [ebp-48h] BYREF
  IDXGIAdapter *pAdapter; // [esp+34h] [ebp-44h] BYREF
  _BYTE sd[64]; // [esp+38h] [ebp-40h] OVERLAPPED BYREF
  HRESULT hr; // [esp+84h] [ebp+Ch]

  if ( this->m_nAdapter == -1 )
  {
    v6 = g_ShaderDeviceMgrDx10.m_pDXGIFactory->EnumAdapters(
           this: g_ShaderDeviceMgrDx10.m_pDXGIFactory,
           a2: (unsigned int)nAdapter,
           a3: &pAdapter);
    *(_DWORD *)sd = v6 < 0 ? nullptr : pAdapter;
    if ( *(_DWORD *)sd != 0
      && (AdapterOutput = CShaderDeviceMgrDx10::GetAdapterOutput(this: &g_ShaderDeviceMgrDx10, nAdapter),
          this->m_pOutput = AdapterOutput,
          AdapterOutput != nullptr) )
    {
      AdapterOutput->AddRef(this: AdapterOutput);
      memset(dst: &sd[4], value: 0, count: 0x3Cu);
      m_nWidth = mode->m_DisplayMode.m_nWidth;
      m_nRefreshRateNumerator = mode->m_DisplayMode.m_nRefreshRateNumerator;
      *(_DWORD *)&sd[8] = mode->m_DisplayMode.m_nHeight;
      *(_DWORD *)&sd[48] = hWnd;
      v11 = *((_BYTE *)mode + 52);
      *(_DWORD *)&sd[4] = m_nWidth;
      *(_DWORD *)&sd[16] = mode->m_DisplayMode.m_nRefreshRateDenominator;
      *(_DWORD *)&sd[12] = m_nRefreshRateNumerator;
      m_nBackBufferCount = mode->m_nBackBufferCount;
      *(_DWORD *)&sd[20] = 28;
      *(_DWORD *)&sd[40] = 32;
      *(_DWORD *)&sd[60] = 2 * ((v11 & 1) == 0);
      *(_DWORD *)&sd[44] = m_nBackBufferCount;
      *(_DWORD *)&sd[52] = v11 & 1;
      *(_DWORD *)&sd[56] = m_nBackBufferCount > 1;
      *(_DWORD *)&sd[32] = mode->m_nAASamples;
      if ( *(_DWORD *)&sd[32] == 0 )
        *(_DWORD *)&sd[32] = 1;
      p_m_pDevice = &this->m_pDevice;
      *(_DWORD *)&sd[36] = mode->m_nAAQuality;
      if ( D3D10CreateDeviceAndSwapChain(
             pAdapter: *(IDXGIAdapter **)sd,
             DriverType: D3D10_DRIVER_TYPE_HARDWARE,
             Software: nullptr,
             Flags: 0,
             SDKVersion: 0x1Du,
             pSwapChainDesc: (DXGI_SWAP_CHAIN_DESC *)&sd[4],
             ppSwapChain: &this->m_pSwapChain,
             ppDevice: &this->m_pDevice) >= 0
        && this->m_pSwapChain->GetBuffer(
             this: this->m_pSwapChain,
             a2: 0,
             a3: &_GUID_9b7e4c04_342c_4106_a19f_4f2704f689f0,
             a4: (void **)&v16) >= 0
        && (hr = (*p_m_pDevice)->CreateRenderTargetView(
                   this: *p_m_pDevice,
                   a2: v16,
                   a3: nullptr,
                   a4: &this->m_pRenderTargetView),
            v16->Release(this: v16),
            hr >= 0) )
      {
        (*p_m_pDevice)->OMSetRenderTargets(this: *p_m_pDevice, a2: 1u, a3: &this->m_pRenderTargetView, a4: nullptr);
        this->m_hWnd = hWnd;
        this->m_ViewHWnd = hWnd;
        GetWindowSize = this->GetWindowSize;
        this->m_nAdapter = (int)nAdapter;
        GetWindowSize(this, a2: &this->m_nWindowWidth, a3: &this->m_nWindowHeight);
        HardwareCaps = CShaderDeviceMgrBase::GetHardwareCaps(this: &g_ShaderDeviceMgrDx10, (int)nAdapter);
        CHardwareConfig::SetupHardwareCaps(this: g_pHardwareConfig, mode, actualCaps: &HardwareCaps->m_ActualCaps);
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    _Warning(a1: "CShaderDeviceDx10::SetMode: Previous mode has not been shut down!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100296C0
// Name: public: virtual void CShaderDeviceDx10::ShutdownDevice(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::ShutdownDevice(CShaderDeviceDx10 *this)
{
  ID3D10RenderTargetView *m_pRenderTargetView; // eax
  ID3D10Device *m_pDevice; // eax
  IDXGISwapChain *m_pSwapChain; // eax
  IDXGIOutput *m_pOutput; // eax

  m_pRenderTargetView = this->m_pRenderTargetView;
  if ( m_pRenderTargetView != nullptr )
  {
    m_pRenderTargetView->Release(this: m_pRenderTargetView);
    this->m_pRenderTargetView = nullptr;
  }
  m_pDevice = this->m_pDevice;
  if ( m_pDevice != nullptr )
  {
    m_pDevice->Release(this: this->m_pDevice);
    this->m_pDevice = nullptr;
  }
  m_pSwapChain = this->m_pSwapChain;
  if ( m_pSwapChain != nullptr )
  {
    m_pSwapChain->Release(this: this->m_pSwapChain);
    this->m_pSwapChain = nullptr;
  }
  m_pOutput = this->m_pOutput;
  if ( m_pOutput != nullptr )
  {
    m_pOutput->Release(this: this->m_pOutput);
    this->m_pOutput = nullptr;
  }
  this->m_hWnd = nullptr;
  this->m_nAdapter = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10029720
// Name: public: virtual bool CShaderDeviceDx10::IsUsingGraphics(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShaderDeviceDx10::IsUsingGraphics(CShaderDeviceDx10 *this)
{
  return this->m_nAdapter >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10029730
// Name: public: virtual int CShaderDeviceDx10::GetCurrentAdapter(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceDx10::GetCurrentAdapter(CShaderDeviceDx10 *this)
{
  return this->m_nAdapter;
}

//------------------------------------------------------------------------------
// Address: 0x10029740
// Name: public: virtual enum ImageFormat CShaderDeviceDx10::GetBackBufferFormat(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceDx10::GetBackBufferFormat(CShaderDeviceDx10 *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10029750
// Name: public: virtual void CShaderDeviceDx10::GetBackBufferDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::GetBackBufferDimensions(CShaderDeviceDx10 *this, int *width, int *height)
{
  *width = 1024;
  *height = 768;
}

//------------------------------------------------------------------------------
// Address: 0x10029770
// Name: public: virtual void CShaderDeviceDx10::SpewDriverInfo(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::SpewDriverInfo(CShaderDeviceDx10 *this)
{
  _Warning(a1: "Dx10 Driver!\n");
}

//------------------------------------------------------------------------------
// Address: 0x10029780
// Name: public: virtual void CShaderDeviceDx10::Present(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::Present(CShaderDeviceDx10 *this)
{
  this->m_pSwapChain->Present(this: this->m_pSwapChain, a2: 0, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10029790
// Name: public: virtual void CShaderDeviceDx10::SetHardwareGammaRamp(float,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShaderDeviceDx10::SetHardwareGammaRamp(
        CShaderDeviceDx10 *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>,
        float fGamma,
        float fGammaTVRangeMin,
        float fGammaTVRangeMax,
        float fGammaTVExponent,
        bool bTVEnabled)
{
  int m_nGammaControlPointCount; // ebx
  int v12; // edi
  float *v13; // esi
  float v14; // xmm1_4
  float v15; // xmm0_4
  long double v16; // [esp-4h] [ebp-3044h]
  long double v17; // [esp+4h] [ebp-303Ch]
  float m_flMaxGammaControlPoint; // [esp+Ch] [ebp-3034h]
  float m_flMinGammaControlPoint; // [esp+14h] [ebp-302Ch]
  _DWORD v20[7]; // [esp+1Ch] [ebp-3024h] BYREF
  char v21; // [esp+38h] [ebp-3008h] BYREF

  HIDWORD(v17) = a3;
  DevMsg(a1: "SetHardwareGammaRamp( %f )\n", fGamma);
  if ( this->m_pOutput != nullptr )
  {
    LODWORD(v17) = a2;
    m_nGammaControlPointCount = g_pHardwareConfig->m_Caps.m_nGammaControlPointCount;
    m_flMinGammaControlPoint = g_pHardwareConfig->m_Caps.m_flMinGammaControlPoint;
    m_flMaxGammaControlPoint = g_pHardwareConfig->m_Caps.m_flMaxGammaControlPoint;
    HIDWORD(v16) = a4;
    memset(&v20[3], 0, 12);
    v20[2] = 1065353216;
    v20[1] = 1065353216;
    v20[0] = 1065353216;
    v12 = 0;
    if ( m_nGammaControlPointCount > 0 )
    {
      LODWORD(v16) = a5;
      v13 = (float *)&v21;
      do
      {
        __libm_sse2_pow(x: v16, y: v17);
        v14 = m_flMaxGammaControlPoint;
        v15 = (float)v12 * (float)(1.0 / (float)(m_nGammaControlPointCount - 1));
        if ( v15 > m_flMaxGammaControlPoint || (v14 = m_flMinGammaControlPoint, m_flMinGammaControlPoint > v15) )
          v15 = v14;
        *(v13 - 1) = v15;
        *v13 = v15;
        v13[1] = v15;
        ++v12;
        v13 += 3;
      }
      while ( v12 < m_nGammaControlPointCount );
    }
    if ( this->m_pOutput->SetGammaControl(this: this->m_pOutput, a2: (const DXGI_GAMMA_CONTROL *)v20) < 0 )
      _Warning(a1: "CShaderDeviceDx10::SetHardwareGammaRamp: Unable to set gamma controls!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100298E0
// Name: public: virtual class IVertexBuffer __near * CShaderDeviceDx10::CreateVertexBuffer(enum ShaderBufferType_t,unsigned __int64,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVertexBufferDx10 *__thiscall CShaderDeviceDx10::CreateVertexBuffer(
        CShaderDeviceDx10 *this,
        ShaderBufferType_t type,
        unsigned __int64 fmt,
        int nVertexCount,
        const char *pBudgetGroup)
{
  CVertexBufferDx10 *v5; // eax

  v5 = (CVertexBufferDx10 *)operator new(nSize: 0x28u);
  if ( v5 != nullptr )
    return CVertexBufferDx10::CVertexBufferDx10(this: v5, type, fmt, nVertexCount, pBudgetGroupName: pBudgetGroup);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10029920
// Name: public: virtual void CShaderDeviceDx10::DestroyVertexBuffer(class IVertexBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::DestroyVertexBuffer(CShaderDeviceDx10 *this, IVertexBuffer *pVertexBuffer)
{
  if ( pVertexBuffer != nullptr )
  {
    CShaderAPIDx10::UnbindVertexBuffer(this: g_pShaderAPIDx10, pBuffer: (ID3D10Buffer *)pVertexBuffer[2].__vftable);
    ((void (__thiscall *)(IVertexBuffer *, int))pVertexBuffer->__vftable[1].VertexCount)(a1: pVertexBuffer, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029950
// Name: public: virtual class IIndexBuffer __near * CShaderDeviceDx10::CreateIndexBuffer(enum ShaderBufferType_t,enum MaterialIndexFormat_t,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CIndexBufferDx10 *__thiscall CShaderDeviceDx10::CreateIndexBuffer(
        CShaderDeviceDx10 *this,
        ShaderBufferType_t type,
        MaterialIndexFormat_t fmt,
        int nIndexCount,
        const char *pBudgetGroup)
{
  CIndexBufferDx10 *v5; // eax

  v5 = (CIndexBufferDx10 *)operator new(nSize: 0x20u);
  if ( v5 != nullptr )
    return CIndexBufferDx10::CIndexBufferDx10(this: v5, type, fmt, nIndexCount, pBudgetGroupName: pBudgetGroup);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10029970
// Name: public: virtual void CShaderDeviceDx10::DestroyIndexBuffer(class IIndexBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::DestroyIndexBuffer(CShaderDeviceDx10 *this, IIndexBuffer *pIndexBuffer)
{
  if ( pIndexBuffer != nullptr )
  {
    CShaderAPIDx10::UnbindIndexBuffer(this: g_pShaderAPIDx10, pBuffer: (ID3D10Buffer *)pIndexBuffer[2].__vftable);
    ((void (__thiscall *)(IIndexBuffer *, int))pIndexBuffer->__vftable[1].IndexCount)(a1: pIndexBuffer, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100299A0
// Name: public: virtual class IVertexBuffer __near * CShaderDeviceDx10::GetDynamicVertexBuffer(int,unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
IVertexBuffer *__thiscall CShaderDeviceDx10::GetDynamicVertexBuffer(
        CShaderDeviceDx10 *this,
        int nStreamID,
        unsigned __int64 vertexFormat,
        bool bBuffered)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10029AB0
// Name: public: virtual class IShaderBuffer __near * CShaderDeviceDx10::CompileShader(char const __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IShaderBuffer *__thiscall CShaderDeviceDx10::CompileShader(
        CShaderDeviceDx10 *this,
        const char *pProgram,
        ID3D10Blob *nBufLen,
        ID3D10Blob *pShaderVersion)
{
  const char *v4; // eax
  _DWORD *v6; // eax
  unsigned int v7; // ecx
  _DWORD *v8; // esi

  if ( D3DX10CompileFromMemory(
         a1: pProgram,
         a2: nBufLen,
         a3: str,
         a4: 0,
         a5: 0,
         a6: "main",
         a7: pShaderVersion,
         a8: 4608,
         a9: 0,
         a10: 0,
         a11: &nBufLen,
         a12: &pShaderVersion,
         a13: 0) >= 0 )
  {
    v6 = operator new(nSize: 8u);
    if ( v6 != nullptr )
    {
      v7 = (unsigned int)nBufLen;
      *v6 = &CShaderBuffer<ID3D10Blob>::`vftable';
      v6[1] = v7;
      v8 = v6;
    }
    else
    {
      v8 = nullptr;
    }
    if ( pShaderVersion != nullptr )
      pShaderVersion->Release(this: pShaderVersion);
    return (IShaderBuffer *)v8;
  }
  else
  {
    if ( pShaderVersion != nullptr )
    {
      v4 = (const char *)pShaderVersion->GetBufferPointer(this: pShaderVersion);
      _Warning(a1: "Vertex shader compilation failed! Reported the following errors:\n%s\n", v4);
      pShaderVersion->Release(this: pShaderVersion);
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029D10
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
// Address: 0x10029DA0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                              this: _g_pMemAlloc,
                                                                                              a2: m_pMemory,
                                                                                              a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                              this: _g_pMemAlloc,
                                                                                              a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029E50
// Name: public: virtual void CShaderDeviceMgrDx10::GetAdapterInfo(int,struct MaterialAdapterInfo_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx10::GetAdapterInfo(
        CShaderDeviceMgrDx10 *this,
        int nAdapter,
        MaterialAdapterInfo_t *info)
{
  *info = this->m_Adapters.m_Memory.m_pMemory[nAdapter].m_ActualCaps.MaterialAdapterInfo_t;
}

//------------------------------------------------------------------------------
// Address: 0x10029E70
// Name: public: virtual void __near * (*CShaderDeviceMgrDx10::SetMode(void __near *,int,struct ShaderDeviceInfo_t const __near &))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CShaderAPIBase *(__cdecl *__thiscall CShaderDeviceMgrDx10::SetMode(
        CShaderDeviceMgrDx10 *this,
        void *hWnd,
        int nAdapter,
        const ShaderDeviceInfo_t *mode))(const char *pInterfaceName, int *pReturnCode)
{
  int m_nDXLevel; // eax
  CShaderDeviceMgrBase::AdapterInfo_t *m_pMemory; // ebp
  int ClosestActualDXLevel; // ebp
  ShaderDeviceInfo_t adjustedMode_4; // [esp+10h] [ebp-38h] OVERLAPPED BYREF

  m_nDXLevel = mode->m_nDXLevel;
  if ( m_nDXLevel == 0 )
    m_nDXLevel = this->m_Adapters.m_Memory.m_pMemory[nAdapter].m_ActualCaps.m_nDXSupportLevel;
  m_pMemory = this->m_Adapters.m_Memory.m_pMemory;
  if ( m_nDXLevel > m_pMemory[nAdapter].m_ActualCaps.m_nMaxDXSupportLevel )
    m_nDXLevel = m_pMemory[nAdapter].m_ActualCaps.m_nMaxDXSupportLevel;
  ClosestActualDXLevel = CShaderDeviceMgrBase::GetClosestActualDXLevel(this, nDxLevel: m_nDXLevel);
  if ( ClosestActualDXLevel < 100 )
    return (CShaderAPIBase *(__cdecl *)(const char *, int *))g_pShaderDeviceMgrDx8->SetMode(
                                                               this: g_pShaderDeviceMgrDx8,
                                                               a2: hWnd,
                                                               a3: nAdapter,
                                                               a4: mode);
  if ( g_pShaderAPI != nullptr )
  {
    g_pShaderAPI->OnDeviceShutdown(this: g_pShaderAPI);
    g_pShaderAPI = nullptr;
  }
  if ( g_pShaderDevice != nullptr )
  {
    g_pShaderDevice->ShutdownDevice(this: g_pShaderDevice);
    g_pShaderDevice = nullptr;
  }
  g_pShaderShadow = nullptr;
  adjustedMode_4 = *mode;
  adjustedMode_4.m_nDXLevel = ClosestActualDXLevel;
  if ( !g_pShaderDeviceDx10->InitDevice(this: g_pShaderDeviceDx10, a2: hWnd, a3: nAdapter, a4: &adjustedMode_4)
    || !g_pShaderAPIDx10->OnDeviceInit(this: g_pShaderAPIDx10) )
  {
    return nullptr;
  }
  g_pShaderDevice = g_pShaderDeviceDx10;
  g_pShaderAPI = g_pShaderAPIDx10;
  g_pShaderShadow = g_pShaderShadowDx10;
  return CShaderDeviceMgrBase::ShaderInterfaceFactory;
}

//------------------------------------------------------------------------------
// Address: 0x1002B390
// Name: private: void CShaderDeviceDx10::ReleaseInputLayouts(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::ReleaseInputLayouts(CShaderDeviceDx10 *this, int nIndex)
{
  unsigned __int16 i; // di
  int v3; // esi
  int v4; // eax

  for ( i = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *)(nIndex + 16));
        i != 0xFFFF;
        i = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::NextInorder(
              this: (CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *)(nIndex + 16),
              i) )
  {
    v3 = 24 * i;
    v4 = *(_DWORD *)(v3 + *(_DWORD *)(nIndex + 20) + 8);
    if ( v4 != 0 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(a1: *(_DWORD *)(v3 + *(_DWORD *)(nIndex + 20) + 8));
      *(_DWORD *)(v3 + *(_DWORD *)(nIndex + 20) + 8) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B470
// Name: public: virtual void CShaderDeviceDx10::DestroyGeometryShader(struct GeometryShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::DestroyGeometryShader(CShaderDeviceDx10 *this, ID3D10GeometryShader **hShader)
{
  CUtlFixedLinkedList<CShaderDeviceDx10::GeometryShader_t> *p_m_GeometryShaderDict; // edi

  if ( hShader != nullptr )
  {
    CShaderAPIDx10::Unbind(this: g_pShaderAPIDx10, hShader);
    (*hShader)->Release(this: *hShader);
    hShader[1]->Release(this: hShader[1]);
    p_m_GeometryShaderDict = &this->m_GeometryShaderDict;
    CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::Unlink(
      this: (CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > > *)p_m_GeometryShaderDict,
      elem: (unsigned int)hShader);
    hShader[3] = (ID3D10GeometryShader *)p_m_GeometryShaderDict->m_FirstFree;
    p_m_GeometryShaderDict->m_FirstFree = (int)hShader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B4C0
// Name: public: virtual void CShaderDeviceDx10::DestroyPixelShader(struct PixelShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::DestroyPixelShader(CShaderDeviceDx10 *this, ID3D10PixelShader **hShader)
{
  CUtlFixedLinkedList<CShaderDeviceDx10::PixelShader_t> *p_m_PixelShaderDict; // edi

  if ( hShader != nullptr )
  {
    CShaderAPIDx10::Unbind(this: g_pShaderAPIDx10, hShader);
    (*hShader)->Release(this: *hShader);
    hShader[1]->Release(this: hShader[1]);
    p_m_PixelShaderDict = &this->m_PixelShaderDict;
    CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::Unlink(
      this: p_m_PixelShaderDict,
      elem: (unsigned int)hShader);
    hShader[3] = (ID3D10PixelShader *)p_m_PixelShaderDict->m_FirstFree;
    p_m_PixelShaderDict->m_FirstFree = (int)hShader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B610
// Name: private: void CShaderDeviceMgrDx10::InitAdapterInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrDx10::InitAdapterInfo(CShaderDeviceMgrDx10 *this)
{
  IDXGIOutput *v2; // ebx
  CUtlVector<CShaderDeviceMgrBase::AdapterInfo_t,CUtlMemory<CShaderDeviceMgrBase::AdapterInfo_t,int> > *p_m_Adapters; // edi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CShaderDeviceMgrBase::AdapterInfo_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  int v9; // esi
  IDXGIOutput *AdapterOutput; // eax
  int v11; // ecx
  int v12; // eax
  const char *v13; // eax
  IDXGIAdapter *v14; // [esp+14h] [ebp-4h] BYREF

  v2 = nullptr;
  p_m_Adapters = &this->m_Adapters;
  for ( this->m_Adapters.m_Size = 0;
        this->m_pDXGIFactory->EnumAdapters(this: this->m_pDXGIFactory, a2: (unsigned int)v2, a3: &v14) != -2005270526;
        v2 = (IDXGIOutput *)((char *)v2 + 1) )
  {
    m_Size = p_m_Adapters->m_Size;
    m_nAllocationCount = p_m_Adapters->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CShaderDeviceMgrBase::AdapterInfo_t,int>::Grow(
        this: &p_m_Adapters->m_Memory,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_Adapters->m_Size;
    m_pMemory = p_m_Adapters->m_Memory.m_pMemory;
    v7 = p_m_Adapters->m_Size - m_Size - 1;
    v8 = p_m_Adapters->m_Size - m_Size == 1;
    p_m_Adapters->m_pElements = p_m_Adapters->m_Memory.m_pMemory;
    if ( v7 >= 0 && !v8 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 728 * v7);
    v9 = (int)&p_m_Adapters->m_Memory.m_pMemory[m_Size];
    AdapterOutput = CShaderDeviceMgrDx10::GetAdapterOutput(this, nAdapter: v2);
    *(_BYTE *)(v9 + 716) ^= (CShaderDeviceMgrDx10::ComputeCapsFromD3D(
                               this,
                               pCaps: (HardwareCaps_t *)v9,
                               pAdapter: v14,
                               pOutput: AdapterOutput)
                           ^ *(_BYTE *)(v9 + 716))
                          & 1;
    if ( (*(_BYTE *)(v9 + 716) & 1) != 0 )
    {
      CShaderDeviceMgrBase::ReadDXSupportLevels(this, caps: (HardwareCaps_t *)v9);
      CShaderDeviceMgrBase::ReadHardwareCaps(this, caps: (HardwareCaps_t *)v9, nDxLevel: *(KeyValues **)(v9 + 536));
      v12 = _CommandLine(a1: v11);
      v13 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v12 + 32))(
                            a1: v12,
                            a2: "-shader",
                            a3: 0);
      if ( v13 != nullptr )
        V_strncpy(pDest: (char *)(v9 + 632), pSrc: v13, maxLen: 32);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B740
// Name: public: virtual struct GeometryShaderHandle_t__ __near * CShaderDeviceDx10::CreateGeometryShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *__thiscall CShaderDeviceDx10::CreateGeometryShader(
        CShaderDeviceDx10 *this,
        ID3D10ShaderReflection *pShaderBuffer)
{
  IShaderBuffer *v2; // esi
  ID3D10Device *m_pDevice; // edi
  unsigned int (__thiscall *QueryInterface)(IShaderBuffer *); // eax
  ID3D10Device_vtbl *v6; // ebp
  int v7; // eax
  int v8; // eax
  const void *v9; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *result; // eax
  SIZE_T v11; // [esp-8h] [ebp-1Ch]
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *v12; // [esp+10h] [ebp-4h] BYREF

  v2 = (IShaderBuffer *)pShaderBuffer;
  m_pDevice = this->m_pDevice;
  QueryInterface = (unsigned int (__thiscall *)(IShaderBuffer *))pShaderBuffer->QueryInterface;
  v12 = nullptr;
  v6 = m_pDevice->__vftable;
  v7 = ((int (__thiscall *)(ID3D10ShaderReflection *, CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t **))QueryInterface)(
         a1: pShaderBuffer,
         a2: &v12);
  v8 = ((int (__thiscall *)(IShaderBuffer *, int))v2->GetBits)(a1: v2, a2: v7);
  if ( ((int (__stdcall *)(ID3D10Device *, int))v6->CreateGeometryShader)(a1: m_pDevice, a2: v8) >= 0 && v12 != nullptr )
  {
    v11 = v2->GetSize(this: v2);
    v9 = v2->GetBits(this: v2);
    if ( D3D10ReflectShader(pShaderBytecode: v9, BytecodeLength: v11, ppReflector: &pShaderBuffer) >= 0
      && pShaderBuffer != nullptr )
    {
      result = CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::AddToTail(this: &this->m_GeometryShaderDict);
      result->m_pNext = v12;
      result->m_nBlockSize = (int)pShaderBuffer;
      return result;
    }
    ((void (__stdcall *)(CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *))v12->m_pNext[1].m_pNext)(a1: v12);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002B7E0
// Name: public: virtual struct PixelShaderHandle_t__ __near * CShaderDeviceDx10::CreatePixelShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *__thiscall CShaderDeviceDx10::CreatePixelShader(
        CShaderDeviceDx10 *this,
        ID3D10ShaderReflection *pShaderBuffer)
{
  IShaderBuffer *v2; // esi
  ID3D10Device *m_pDevice; // edi
  unsigned int (__thiscall *QueryInterface)(IShaderBuffer *); // eax
  ID3D10Device_vtbl *v6; // ebp
  int v7; // eax
  int v8; // eax
  const void *v9; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *result; // eax
  SIZE_T v11; // [esp-8h] [ebp-1Ch]
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *v12; // [esp+10h] [ebp-4h] BYREF

  v2 = (IShaderBuffer *)pShaderBuffer;
  m_pDevice = this->m_pDevice;
  QueryInterface = (unsigned int (__thiscall *)(IShaderBuffer *))pShaderBuffer->QueryInterface;
  v12 = nullptr;
  v6 = m_pDevice->__vftable;
  v7 = ((int (__thiscall *)(ID3D10ShaderReflection *, CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t **))QueryInterface)(
         a1: pShaderBuffer,
         a2: &v12);
  v8 = ((int (__thiscall *)(IShaderBuffer *, int))v2->GetBits)(a1: v2, a2: v7);
  if ( ((int (__stdcall *)(ID3D10Device *, int))v6->CreatePixelShader)(a1: m_pDevice, a2: v8) >= 0 && v12 != nullptr )
  {
    v11 = v2->GetSize(this: v2);
    v9 = v2->GetBits(this: v2);
    if ( D3D10ReflectShader(pShaderBytecode: v9, BytecodeLength: v11, ppReflector: &pShaderBuffer) >= 0
      && pShaderBuffer != nullptr )
    {
      result = CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int>>>::AddToTail(this: &this->m_PixelShaderDict);
      result->m_pNext = v12;
      result->m_nBlockSize = (int)pShaderBuffer;
      return result;
    }
    ((void (__stdcall *)(CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *))v12->m_pNext[1].m_pNext)(a1: v12);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002B900
// Name: public: virtual bool CShaderDeviceMgrDx10::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrDx10::Connect(
        CShaderDeviceMgrDx10 *this,
        void *(__cdecl *factory)(const char *, int *))
{
  if ( CShaderDeviceMgrBase::Connect(this, factory) == 0 )
    return 0;
  if ( CreateDXGIFactory(riid: &_GUID_7b7166ec_21c7_44ae_b21a_c9ae321ae369, ppFactory: (void **)&this->m_pDXGIFactory) < 0 )
  {
    _Warning(a1: "Failed to create the DXGI Factory!\n");
    return 0;
  }
  CShaderDeviceMgrDx10::InitAdapterInfo(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B950
// Name: public: struct ID3D10InputLayout __near * CShaderDeviceDx10::GetInputLayout(struct VertexShaderHandle_t__ __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
ID3D10InputLayout *__thiscall CShaderDeviceDx10::GetInputLayout(
        CShaderDeviceDx10 *this,
        VertexShaderHandle_t__ *hShader,
        unsigned __int64 format)
{
  unsigned __int16 v4; // ax
  CShaderDeviceDx10::InputLayout_t insert_4; // [esp+4h] [ebp-10h] OVERLAPPED BYREF

  if ( hShader == nullptr )
    return nullptr;
  insert_4.m_VertexFormat = format;
  v4 = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Find(
         this: (CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *)(hShader + 4),
         search: &insert_4);
  if ( v4 != 0xFFFF )
    return *(ID3D10InputLayout **)(*((_DWORD *)hShader + 5) + 24 * v4 + 8);
  insert_4.m_pInputLayout = CreateInputLayout(
                              fmt: format,
                              pReflection: *((ID3D10ShaderReflection **)hShader + 1),
                              pByteCode: *((const void **)hShader + 2),
                              nByteCodeLen: *((_DWORD *)hShader + 3));
  CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Insert(
    this: (CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *)(hShader + 4),
    insert: &insert_4);
  return insert_4.m_pInputLayout;
}

//------------------------------------------------------------------------------
// Address: 0x1002BB50
// Name: public: virtual struct VertexShaderHandle_t__ __near * CShaderDeviceDx10::CreateVertexShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
VertexShaderHandle_t__ *__thiscall CShaderDeviceDx10::CreateVertexShader(
        CShaderDeviceDx10 *this,
        ID3D10ShaderReflection *pShaderBuffer)
{
  IShaderBuffer *v2; // edi
  ID3D10Device *m_pDevice; // esi
  unsigned int (__thiscall *QueryInterface)(IShaderBuffer *); // eax
  ID3D10Device_vtbl *v6; // ebp
  int v7; // eax
  int v8; // eax
  const void *v9; // eax
  int v10; // esi
  unsigned int v11; // eax
  void *v12; // eax
  unsigned int v13; // ecx
  unsigned __int8 *v14; // eax
  SIZE_T v16; // [esp-8h] [ebp-1Ch]
  unsigned int v17; // [esp-4h] [ebp-18h]
  int v18; // [esp+10h] [ebp-4h] BYREF

  v2 = (IShaderBuffer *)pShaderBuffer;
  m_pDevice = this->m_pDevice;
  QueryInterface = (unsigned int (__thiscall *)(IShaderBuffer *))pShaderBuffer->QueryInterface;
  v18 = 0;
  v6 = m_pDevice->__vftable;
  v7 = ((int (__thiscall *)(ID3D10ShaderReflection *, int *))QueryInterface)(a1: pShaderBuffer, a2: &v18);
  v8 = ((int (__thiscall *)(IShaderBuffer *, int))v2->GetBits)(a1: v2, a2: v7);
  if ( ((int (__stdcall *)(ID3D10Device *, int))v6->CreateVertexShader)(a1: m_pDevice, a2: v8) >= 0 && v18 != 0 )
  {
    v16 = v2->GetSize(this: v2);
    v9 = v2->GetBits(this: v2);
    if ( D3D10ReflectShader(pShaderBytecode: v9, BytecodeLength: v16, ppReflector: &pShaderBuffer) >= 0
      && pShaderBuffer != nullptr )
    {
      v10 = CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>>::InsertBefore(
              this: &this->m_VertexShaderDict,
              before: 0);
      *(_DWORD *)v10 = v18;
      *(_DWORD *)(v10 + 4) = pShaderBuffer;
      v11 = v2->GetSize(this: v2);
      *(_DWORD *)(v10 + 12) = v11;
      v12 = operator new(nSize: v11);
      v13 = *(_DWORD *)(v10 + 12);
      *(_DWORD *)(v10 + 8) = v12;
      v17 = v13;
      v14 = (unsigned __int8 *)v2->GetBits(this: v2);
      memcpy(dst: *(unsigned __int8 **)(v10 + 8), src: v14, count: v17);
      return (VertexShaderHandle_t__ *)v10;
    }
    (*(void (__stdcall **)(int))(*(_DWORD *)v18 + 8))(a1: v18);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002BC30
// Name: public: virtual CShaderDeviceDx10::~CShaderDeviceDx10(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::~CShaderDeviceDx10(CShaderDeviceDx10 *this)
{
  CUtlFixedLinkedList<CShaderDeviceDx10::PixelShader_t> *p_m_PixelShaderDict; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *v4; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *v5; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *v6; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *v7; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *v8; // eax

  p_m_PixelShaderDict = &this->m_PixelShaderDict;
  this->__vftable = (CShaderDeviceDx10_vtbl *)&CShaderDeviceDx10::`vftable';
  CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::RemoveAll(this: &this->m_PixelShaderDict);
  m_pBlocks = p_m_PixelShaderDict->m_Memory.m_pBlocks;
  if ( p_m_PixelShaderDict->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v4 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
    }
    while ( m_pBlocks != nullptr );
    p_m_PixelShaderDict->m_Memory.m_pBlocks = nullptr;
    p_m_PixelShaderDict->m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::RemoveAll(this: (CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > > *)&this->m_GeometryShaderDict);
  v5 = this->m_GeometryShaderDict.m_Memory.m_pBlocks;
  if ( v5 != nullptr )
  {
    do
    {
      v6 = v5;
      v5 = v5->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
    }
    while ( v5 != nullptr );
    this->m_GeometryShaderDict.m_Memory.m_pBlocks = nullptr;
    this->m_GeometryShaderDict.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>>::RemoveAll(this: &this->m_VertexShaderDict);
  v7 = this->m_VertexShaderDict.m_Memory.m_pBlocks;
  if ( v7 != nullptr )
  {
    do
    {
      v8 = v7;
      v7 = v7->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
    }
    while ( v7 != nullptr );
    this->m_VertexShaderDict.m_Memory.m_pBlocks = nullptr;
    this->m_VertexShaderDict.m_Memory.m_nAllocationCount = 0;
  }
  CShaderDeviceBase::~CShaderDeviceBase(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002BCE0
// Name: public: virtual void CShaderDeviceDx10::DestroyVertexShader(struct VertexShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceDx10::DestroyVertexShader(CShaderDeviceDx10 *this, VertexShaderHandle_t__ *hShader)
{
  CUtlFixedLinkedList<CShaderDeviceDx10::VertexShader_t> *p_m_VertexShaderDict; // edi

  if ( hShader != nullptr )
  {
    CShaderAPIDx10::Unbind(this: g_pShaderAPIDx10, (ID3D10VertexShader **)hShader);
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)hShader + 8))(a1: *(_DWORD *)hShader);
    (*(void (__stdcall **)(_DWORD))(**((_DWORD **)hShader + 1) + 8))(a1: *((_DWORD *)hShader + 1));
    free(pMem: *((void **)hShader + 2));
    CShaderDeviceDx10::ReleaseInputLayouts(this, nIndex: (int)hShader);
    p_m_VertexShaderDict = &this->m_VertexShaderDict;
    CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::Unlink(
      this: p_m_VertexShaderDict,
      elem: (unsigned int)hShader);
    CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::~CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>(this: (CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *)(hShader + 4));
    hShader[12] = (VertexShaderHandle_t__)p_m_VertexShaderDict->m_FirstFree;
    p_m_VertexShaderDict->m_FirstFree = (int)hShader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BD50
// Name: public: CShaderDeviceDx10::CShaderDeviceDx10(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceDx10 *__thiscall CShaderDeviceDx10::CShaderDeviceDx10(CShaderDeviceDx10 *this)
{
  CShaderDeviceBase::CShaderDeviceBase(this);
  this->__vftable = (CShaderDeviceDx10_vtbl *)&CShaderDeviceDx10::`vftable';
  this->m_VertexShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_VertexShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_VertexShaderDict.m_Memory.m_nGrowSize = 0;
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::Init(
    this: &this->m_VertexShaderDict.m_Memory,
    nGrowSize: 0,
    nInitSize: 0);
  this->m_VertexShaderDict.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_VertexShaderDict.m_LastAlloc.m_nIndex = -1;
  this->m_VertexShaderDict.m_Head = 0;
  this->m_VertexShaderDict.m_Tail = 0;
  this->m_VertexShaderDict.m_FirstFree = 0;
  this->m_VertexShaderDict.m_ElementCount = 0;
  this->m_VertexShaderDict.m_NumAlloced = 0;
  this->m_VertexShaderDict.m_pElements = nullptr;
  this->m_GeometryShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_GeometryShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_GeometryShaderDict.m_Memory.m_nGrowSize = 0;
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int>>::Init(
    this: (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > *)&this->m_GeometryShaderDict,
    nGrowSize: 0,
    nInitSize: 0);
  this->m_GeometryShaderDict.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_GeometryShaderDict.m_LastAlloc.m_nIndex = -1;
  this->m_GeometryShaderDict.m_Head = 0;
  this->m_GeometryShaderDict.m_Tail = 0;
  this->m_GeometryShaderDict.m_FirstFree = 0;
  this->m_GeometryShaderDict.m_ElementCount = 0;
  this->m_GeometryShaderDict.m_NumAlloced = 0;
  this->m_GeometryShaderDict.m_pElements = nullptr;
  this->m_PixelShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_PixelShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_PixelShaderDict.m_Memory.m_nGrowSize = 0;
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int>>::Init(
    this: &this->m_PixelShaderDict.m_Memory,
    nGrowSize: 0,
    nInitSize: 0);
  this->m_PixelShaderDict.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_PixelShaderDict.m_LastAlloc.m_nIndex = -1;
  this->m_PixelShaderDict.m_Head = 0;
  this->m_PixelShaderDict.m_Tail = 0;
  this->m_PixelShaderDict.m_FirstFree = 0;
  this->m_PixelShaderDict.m_ElementCount = 0;
  this->m_PixelShaderDict.m_NumAlloced = 0;
  this->m_PixelShaderDict.m_pElements = nullptr;
  this->m_pDevice = nullptr;
  this->m_pOutput = nullptr;
  this->m_pSwapChain = nullptr;
  this->m_pRenderTargetView = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D110
// Name: public: class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>::Iterator_t CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>::Next(class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *__thiscall CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>::Next(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *result,
        const CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *it)
{
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *v3; // eax

  v3 = result;
  if ( (unsigned __int16)(it->index + 1) >= this->m_nAllocationCount )
    result->index = -1;
  else
    result->index = it->index + 1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10029010
// Name: __CreateCShaderDeviceMgrDx10IShaderDeviceMgr_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CShaderDeviceMgrDx10 *__cdecl _CreateCShaderDeviceMgrDx10IShaderDeviceMgr_interface()
{
  return &g_ShaderDeviceMgrDx10;
}

//------------------------------------------------------------------------------
// Address: 0x10029B60
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *__thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}
