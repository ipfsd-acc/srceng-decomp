// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/renderer/scaleformrenderer.cpp
// Functions: 140
// ============================================================

#include "materialsystem\scaleformui\renderer\scaleformrenderer.h"

//------------------------------------------------------------------------------
// Address: 0x10001B40
// Name: public: GArrayDataBase<class GTexture::ChangeHandler __near *,struct GAllocatorGH<class GTexture::ChangeHandler __near *,2>,struct GArrayDefaultPolicy>::~GArrayDataBase<class GTexture::ChangeHandler __near *,struct GAllocatorGH<class GTexture::ChangeHandler __near *,2>,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy>::~GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy>(
        CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  return ((void *(__thiscall *)(GMemoryHeap *, CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x10002080
// Name: public: GLock::Locker::~Locker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GLock::Locker::~Locker(GLock::Locker *this)
{
  LeaveCriticalSection(lpCriticalSection: &this->pLock->cs);
}

//------------------------------------------------------------------------------
// Address: 0x10002090
// Name: public: void ScaleformRenderer::SetDevice(struct IDirect3DDevice9 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::SetDevice(ScaleformRenderer *this, IDirect3DDevice9 *pDevice)
{
  __int16 TextureCaps; // ax
  _D3DCAPS9 caps; // [esp+8h] [ebp-130h] BYREF

  this->m_pDevice = pDevice;
  pDevice->AddRef(this: pDevice);
  this->m_vertexStream.m_pDevice = this->m_pDevice;
  if ( GDynamicVertexStream::CreateDynamicBuffers(this: &this->m_vertexStream) == 0 )
    this->m_vertexStream.m_pDevice = nullptr;
  this->m_pDevice->CreateStateBlock(this: this->m_pDevice, a2: D3DSBT_ALL, a3: &this->m_pStateBlock);
  this->m_Viewport.m_flMinZ = 0.0;
  this->m_Viewport.m_nTopLeftX = 0;
  this->m_Viewport.m_nTopLeftY = 0;
  this->m_Viewport.m_flMaxZ = 1.0;
  g_pShaderAPI->GetBackBufferDimensions(
    this: g_pShaderAPI,
    a2: &this->m_Viewport.m_nWidth,
    a3: &this->m_Viewport.m_nHeight);
  ScaleformRenderer::InitShaders(this);
  this->m_pDevice->GetDeviceCaps(this: this->m_pDevice, a2: &caps);
  TextureCaps = caps.TextureCaps;
  this->m_texPowerOfTwoSupport = 0;
  if ( (TextureCaps & 2) == 0 )
    this->m_texPowerOfTwoSupport = 2 - ((TextureCaps & 0x100) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10002180
// Name: public: virtual void ScaleformRenderer::ReleaseResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::ReleaseResources(ScaleformRenderer *this)
{
  GRendererNode *pNext; // eax
  ScaleformTexture *v3; // ecx
  GRendererNode *v4; // eax
  ScaleformRenderTarget *v5; // ecx
  IDirect3DDevice9 *m_pDevice; // eax
  GLock *guard; // [esp+8h] [ebp-10h]

  guard = &this->m_texturesLock;
  EnterCriticalSection(lpCriticalSection: &this->m_texturesLock.cs);
  while ( this->m_textures.pNext != &this->m_textures )
  {
    pNext = this->m_textures.pNext;
    if ( pNext != nullptr )
      v3 = (ScaleformTexture *)&pNext[-1];
    else
      v3 = nullptr;
    ScaleformTexture::RemoveFromRenderer(this: v3);
  }
  while ( this->m_renderTargets.pNext != &this->m_renderTargets )
  {
    v4 = this->m_renderTargets.pNext;
    if ( v4 != nullptr )
      v5 = (ScaleformRenderTarget *)&v4[-1];
    else
      v5 = nullptr;
    ScaleformRenderTarget::RemoveFromRenderer(this: v5);
  }
  LeaveCriticalSection(lpCriticalSection: &guard->cs);
  ScaleformRenderer::ReleaseShaders(this);
  GDynamicVertexStream::ReleaseDynamicBuffers(this: &this->m_vertexStream, lostDevice: false);
  this->m_vertexStream.m_pDevice = nullptr;
  m_pDevice = this->m_pDevice;
  if ( m_pDevice != nullptr )
  {
    m_pDevice->Release(this: this->m_pDevice);
    this->m_pDevice = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002250
// Name: public: virtual bool ScaleformRenderer::GetRenderCaps(struct GRenderer::RenderCaps __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ScaleformRenderer::GetRenderCaps(ScaleformRenderer *this, GRenderer::RenderCaps *pcaps)
{
  ScaleformRenderer::TexPowerOfTwo::Support m_texPowerOfTwoSupport; // ecx

  pcaps->CapBits = 12596140;
  m_texPowerOfTwoSupport = this->m_texPowerOfTwoSupport;
  if ( m_texPowerOfTwoSupport == Full )
  {
    pcaps->CapBits = 13169580;
  }
  else if ( m_texPowerOfTwoSupport == NoRepeat )
  {
    pcaps->CapBits = 12612524;
  }
  pcaps->CapBits |= 0x10000u;
  pcaps->BlendModes = 891;
  pcaps->VertexFormats = 27;
  pcaps->MaxTextureSize = 2048;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100022A0
// Name: public: virtual void ScaleformRenderer::BeginFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::BeginFrame(ScaleformRenderer *this)
{
  ScaleformRenderTarget *m_pDisplayRenderTarget; // eax

  m_pDisplayRenderTarget = this->m_pDisplayRenderTarget;
  if ( m_pDisplayRenderTarget != nullptr )
    g_pShaderAPI->SetRenderTarget(this: g_pShaderAPI, a2: m_pDisplayRenderTarget->m_hRenderTargetTexture, a3: -1);
}

//------------------------------------------------------------------------------
// Address: 0x100022D0
// Name: public: virtual void ScaleformRenderer::EndFrame(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall ScaleformRenderer::EndFrame(ScaleformRenderer *this, int a2, int a3)
{
  GRenderer::EndFrame((CUtlMemory<char *,int> *)this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x100022E0
// Name: public: virtual void ScaleformRenderer::SetDisplayRenderTarget(class GRenderTarget __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::SetDisplayRenderTarget(
        ScaleformRenderer *this,
        ScaleformRenderTarget *prt,
        bool setstate)
{
  this->m_pDisplayRenderTarget = prt;
}

//------------------------------------------------------------------------------
// Address: 0x100022F0
// Name: public: virtual void ScaleformRenderer::EndDisplay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::EndDisplay(ScaleformRenderer *this)
{
  if ( this->m_pDevice != nullptr )
  {
    if ( this->m_pStateBlock != nullptr )
      this->m_pStateBlock->Apply(this: this->m_pStateBlock);
    g_pShaderAPI->ResetRenderState(this: g_pShaderAPI, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002320
// Name: public: virtual void ScaleformRenderer::SetMatrix(class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::SetMatrix(ScaleformRenderer *this, const GMatrix2D *m)
{
  this->m_currentMatrix = *m;
}

//------------------------------------------------------------------------------
// Address: 0x10002350
// Name: public: virtual void ScaleformRenderer::SetUserMatrix(class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::SetUserMatrix(ScaleformRenderer *this, const GMatrix2D *m)
{
  this->m_userMatrix = *m;
  this->m_matricesDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x100023A0
// Name: public: virtual void ScaleformRenderer::SetCxform(class GRenderer::Cxform const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::SetCxform(ScaleformRenderer *this, const GRenderer::Cxform *cx)
{
  this->m_currentCxform = *cx;
}

//------------------------------------------------------------------------------
// Address: 0x100023E0
// Name: public: virtual void ScaleformRenderer::SetPerspective3D(class GMatrix3D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::SetPerspective3D(ScaleformRenderer *this, const GMatrix3D *projMatIn)
{
  qmemcpy((void *)&this->m_projection, projMatIn, sizeof(this->m_projection));
  this->m_matricesDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x10002410
// Name: public: virtual void ScaleformRenderer::SetView3D(class GMatrix3D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::SetView3D(ScaleformRenderer *this, const GMatrix3D *viewMatIn)
{
  qmemcpy((void *)&this->m_view, viewMatIn, sizeof(this->m_view));
  this->m_matricesDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x10002440
// Name: public: virtual void ScaleformRenderer::SetWorld3D(class GMatrix3D const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::SetWorld3D(ScaleformRenderer *this, const GMatrix3D *pWorldMatIn)
{
  this->m_pWorld = pWorldMatIn;
}

//------------------------------------------------------------------------------
// Address: 0x10002450
// Name: public: virtual void ScaleformRenderer::SetVertexData(void const __near *,int,enum GRenderer::VertexFormat,class GRenderer::CacheProvider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::SetVertexData(
        ScaleformRenderer *this,
        const void *pvertices,
        unsigned int numVertices,
        GRenderer::VertexFormat vf,
        GRenderer::CacheProvider *pcache)
{
  GDynamicVertexStream::SetVertexData(this: &this->m_vertexStream, pVertices: pvertices, numVertices, vf);
}

//------------------------------------------------------------------------------
// Address: 0x10002470
// Name: public: virtual void ScaleformRenderer::SetIndexData(void const __near *,int,enum GRenderer::IndexFormat,class GRenderer::CacheProvider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::SetIndexData(
        ScaleformRenderer *this,
        const void *pindices,
        unsigned int numIndices,
        GRenderer::IndexFormat idxf,
        GRenderer::CacheProvider *pcache)
{
  GDynamicVertexStream::SetIndexData(this: &this->m_vertexStream, pIndices: pindices, numIndices, idxf);
}

//------------------------------------------------------------------------------
// Address: 0x10002490
// Name: public: virtual void ScaleformRenderer::LineStyleDisable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::LineStyleDisable(ScaleformRenderer *this)
{
  this->m_lineStyleEnabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x100024A0
// Name: public: virtual void ScaleformRenderer::LineStyleColor(class GColor)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::LineStyleColor(ScaleformRenderer *this, GColor color)
{
  this->m_lineStyleEnabled = true;
  this->m_lineStyleColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x100024C0
// Name: public: virtual void ScaleformRenderer::FillStyleDisable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::FillStyleDisable(ScaleformRenderer *this)
{
  this->m_fillStyle.m_style = 0;
  this->m_fillStyle.m_fillTexture.pTexture = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100024D0
// Name: public: virtual void ScaleformRenderer::FillStyleColor(class GColor)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::FillStyleColor(ScaleformRenderer *this, GColor color)
{
  this->m_fillStyle.m_style = Color;
  this->m_fillStyle.m_color = color;
  this->m_fillStyle.m_fillTexture.pTexture = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002500
// Name: public: virtual void ScaleformRenderer::FillStyleGouraud(enum GRenderer::GouraudFillType,struct GRenderer::FillTexture const __near *,struct GRenderer::FillTexture const __near *,struct GRenderer::FillTexture const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::FillStyleGouraud(
        ScaleformRenderer *this,
        GRenderer::GouraudFillType fillType,
        const GRenderer::FillTexture *pTexture0,
        const GRenderer::FillTexture *pTexture1,
        const GRenderer::FillTexture *ptexture2)
{
  GRenderer::FillTexture *v5; // eax

  this->m_fillStyle.m_gouraudFillType = fillType;
  v5 = pTexture0;
  this->m_fillStyle.m_style = Gouraud;
  if ( pTexture0 != nullptr || (v5 = pTexture1, pTexture1 != nullptr) )
    this->m_fillStyle.m_fillTexture = *v5;
  else
    this->m_fillStyle.m_fillTexture.pTexture = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002590
// Name: public: virtual void ScaleformRenderer::BeginSubmitMask(enum GRenderer::SubmitMaskMode)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ScaleformRenderer::BeginSubmitMask(
        ScaleformRenderer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        GRenderer::SubmitMaskMode maskMode)
{
  IDirect3DDevice9 *m_pDevice; // eax
  bool v6; // zf
  int v7; // eax
  int m_stencilCounter; // eax
  int v9; // [esp-4h] [ebp-2Ch]
  _D3DSURFACE_DESC sd; // [esp+4h] [ebp-24h] BYREF
  IDirect3DSurface9 *pDepthStencilSurface; // [esp+24h] [ebp-4h] BYREF

  m_pDevice = this->m_pDevice;
  if ( m_pDevice != nullptr )
  {
    v6 = !this->m_stencilAvailable;
    v9 = a2;
    this->m_drawingMask = true;
    if ( !v6 )
      goto LABEL_11;
    if ( !this->m_stencilChecked )
    {
      pDepthStencilSurface = nullptr;
      m_pDevice->GetDepthStencilSurface(this: m_pDevice, a2: &pDepthStencilSurface);
      if ( pDepthStencilSurface != nullptr )
      {
        ((void (__stdcall *)(IDirect3DSurface9 *, _D3DSURFACE_DESC *, int))pDepthStencilSurface->GetDesc)(
          a1: pDepthStencilSurface,
          a2: &sd,
          a3: a2);
        switch ( sd.Format )
        {
          case D3DFMT_D15S1:
          case D3DFMT_D24S8:
          case D3DFMT_D24X4S4:
          case D3DFMT_D24FS8:
            this->m_stencilAvailable = true;
            break;
          default:
            break;
        }
        ((void (__cdecl *)(IDirect3DSurface9 *))pDepthStencilSurface->Release)(a1: pDepthStencilSurface);
      }
      else
      {
        this->m_stencilAvailable = false;
      }
      this->m_stencilChecked = true;
    }
    if ( this->m_stencilAvailable )
    {
LABEL_11:
      ((void (__stdcall *)(IDirect3DDevice9 *, int, _DWORD, int, int))this->m_pDevice->SetRenderState)(
        a1: this->m_pDevice,
        a2: 168,
        a3: 0,
        a4: a3,
        a5: v9);
      this->m_StencilState.m_bEnable = true;
      this->m_StencilState.m_nTestMask = 255;
      this->m_StencilState.m_FailOp = SHADER_STENCILOP_KEEP;
      this->m_StencilState.m_ZFailOp = SHADER_STENCILOP_KEEP;
      if ( maskMode != Mask_Clear )
      {
        if ( maskMode == Mask_Increment )
        {
          m_stencilCounter = this->m_stencilCounter;
          this->m_StencilState.m_nReferenceValue = m_stencilCounter;
          this->m_StencilState.m_CompareFunc = SHADER_STENCILFUNC_EQUAL;
          this->m_StencilState.m_PassOp = SHADER_STENCILOP_INCREMENT_WRAP;
          this->m_stencilCounter = m_stencilCounter + 1;
        }
        else if ( maskMode == Mask_Decrement )
        {
          v7 = this->m_stencilCounter;
          this->m_StencilState.m_nReferenceValue = v7;
          this->m_StencilState.m_CompareFunc = SHADER_STENCILFUNC_EQUAL;
          this->m_StencilState.m_PassOp = SHADER_STENCILOP_DECREMENT_WRAP;
          this->m_stencilCounter = v7 - 1;
        }
      }
      else
      {
        g_pShaderAPI->ClearBuffers(this: g_pShaderAPI, a2: false, a3: false, a4: true, a5: -1, a6: -1);
        this->m_StencilState.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
        this->m_StencilState.m_PassOp = SHADER_STENCILOP_SET_TO_REFERENCE;
        this->m_StencilState.m_nReferenceValue = 1;
        this->m_stencilCounter = 1;
      }
      g_pShaderAPI->SetStencilState(this: g_pShaderAPI, a2: &this->m_StencilState);
      ((void (__cdecl *)(IDirect3DDevice9 *, int, int))this->m_pDevice->SetRenderState)(
        a1: this->m_pDevice,
        a2: 57,
        a3: this->m_StencilState.m_nReferenceValue);
      ++this->m_renderStats.Masks;
      ++this->m_statMaskCnt.Count;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002760
// Name: public: virtual void ScaleformRenderer::EndSubmitMask(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::EndSubmitMask(ScaleformRenderer *this)
{
  IDirect3DDevice9 *m_pDevice; // eax

  m_pDevice = this->m_pDevice;
  if ( m_pDevice != nullptr && this->m_stencilAvailable )
  {
    this->m_drawingMask = false;
    m_pDevice->SetRenderState(this: m_pDevice, a2: D3DRS_COLORWRITEENABLE, a3: 15u);
    this->m_StencilState.m_nReferenceValue = this->m_stencilCounter;
    this->m_StencilState.m_nTestMask = 255;
    this->m_StencilState.m_CompareFunc = SHADER_STENCILFUNC_EQUAL;
    this->m_StencilState.m_PassOp = SHADER_STENCILOP_KEEP;
    g_pShaderAPI->SetStencilState(this: g_pShaderAPI, a2: &this->m_StencilState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100027D0
// Name: public: virtual void ScaleformRenderer::DisableMask(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::DisableMask(ScaleformRenderer *this)
{
  if ( this->m_pDevice != nullptr && this->m_stencilAvailable )
  {
    this->m_StencilState.m_bEnable = false;
    this->m_stencilCounter = 0;
    g_pShaderAPI->SetStencilState(this: g_pShaderAPI, a2: &this->m_StencilState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002810
// Name: public: virtual void ScaleformRenderer::GetRenderStats(class GRenderer::Stats __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::GetRenderStats(ScaleformRenderer *this, GRenderer::Stats *pstats, bool resetStats)
{
  if ( pstats != nullptr )
    *pstats = this->m_renderStats;
  if ( resetStats )
  {
    this->m_renderStats.Triangles = 0;
    this->m_renderStats.Lines = 0;
    this->m_renderStats.Primitives = 0;
    this->m_renderStats.Masks = 0;
    this->m_renderStats.Filters = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002870
// Name: public: virtual void ScaleformRenderer::GetStats(class GStatBag __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::GetStats(
        ScaleformRenderer *this,
        CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pbag,
        bool reset)
{
  if ( pbag != nullptr )
  {
    GStatBag::Add(
      this: pbag,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x43);
    GStatBag::Add(
      this: pbag,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x44);
    GStatBag::Add(
      this: pbag,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x46);
    GStatBag::Add(
      this: pbag,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x47);
    GStatBag::Add(
      this: pbag,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x49);
    GStatBag::Add(
      this: pbag,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x4A);
    GStatBag::Add(
      this: pbag,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x4C);
    GStatBag::Add(
      this: pbag,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x4B);
    GStatBag::Add(
      this: pbag,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x4D);
    GStatBag::Add(
      this: pbag,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x4E);
  }
  if ( reset )
  {
    this->m_statTextureUploadCnt.Count = 0;
    this->m_statTextureUpdateCnt.Count = 0;
    this->m_statDPLineCnt.Count = 0;
    this->m_statDPTriangleCnt.Count = 0;
    this->m_statLineCnt.Count = 0;
    this->m_statTriangleCnt.Count = 0;
    this->m_statMaskCnt.Count = 0;
    this->m_statFilterCnt.Count = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002970
// Name: public: void ScaleformRenderer::ApplyBlendMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::ApplyBlendMode(ScaleformRenderer *this)
{
  IDirect3DDevice9 *m_pDevice; // ecx

  if ( this->m_blendMode >= (unsigned int)(Blend_HardLight|Blend_Normal) )
    this->m_blendMode = Blend_None;
  m_pDevice = this->m_pDevice;
  if ( m_pDevice != nullptr )
  {
    m_pDevice->SetRenderState(this: m_pDevice, a2: D3DRS_BLENDOP, a3: modes[this->m_blendMode].BlendOp);
    this->m_pDevice->SetRenderState(this: this->m_pDevice, a2: D3DRS_SEPARATEALPHABLENDENABLE, a3: 0);
    this->m_pDevice->SetRenderState(
      this: this->m_pDevice,
      a2: D3DRS_SRCBLEND,
      a3: dword_1028D894[3 * this->m_blendMode]);
    this->m_pDevice->SetRenderState(
      this: this->m_pDevice,
      a2: D3DRS_DESTBLEND,
      a3: dword_1028D898[3 * this->m_blendMode]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002A00
// Name: public: static void ScaleformRenderer::SoftwareResample(unsigned char __near *,int,int,int,unsigned char __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScaleformRenderer::SoftwareResample(
        unsigned __int8 *pDst,
        int dstWidth,
        int dstHeight,
        int dstPitch,
        unsigned __int8 *pSrc,
        int srcWidth,
        int srcHeight,
        int srcPitch,
        int srcBytesPerPixel,
        int destBytePerPixel)
{
  switch ( srcBytesPerPixel )
  {
    case 1:
      GRenderer::ResizeImage(
        a1: pDst,
        a2: dstWidth,
        a3: dstHeight,
        a4: dstPitch,
        a5: pSrc,
        a6: srcWidth,
        a7: srcHeight,
        a8: srcPitch,
        a9: ResizeGray);
      break;
    case 3:
      GRenderer::ResizeImage(
        a1: pDst,
        a2: dstWidth,
        a3: dstHeight,
        a4: dstPitch,
        a5: pSrc,
        a6: srcWidth,
        a7: srcHeight,
        a8: srcPitch,
        a9: destBytePerPixel != 4 ? ResizeRgbToRgb : ResizeRgbToRgba);
      break;
    case 4:
      GRenderer::ResizeImage(
        a1: pDst,
        a2: dstWidth,
        a3: dstHeight,
        a4: dstPitch,
        a5: pSrc,
        a6: srcWidth,
        a7: srcHeight,
        a8: srcPitch,
        a9: ResizeRgbaToRgba);
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002AC0
// Name: public: virtual class GTexture __near * ScaleformRenderer::CreateTexture(void)
// Source: json
//------------------------------------------------------------------------------
ScaleformTexture *__thiscall ScaleformRenderer::CreateTexture(ScaleformRenderer *this)
{
  GLock *p_m_texturesLock; // edi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  ScaleformTexture *v4; // eax
  ScaleformTexture *v5; // esi
  int v7; // [esp+10h] [ebp-10h] BYREF
  int v8; // [esp+1Ch] [ebp-4h]

  p_m_texturesLock = &this->m_texturesLock;
  EnterCriticalSection(lpCriticalSection: &this->m_texturesLock.cs);
  v7 = 65;
  Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
  v8 = 0;
  v4 = (ScaleformTexture *)Alloc_2(this: GMemory::pGlobalHeap, a2: 44u, a3: (const GAllocDebugInfo *)&v7);
  LOBYTE(v8) = 1;
  if ( v4 != nullptr )
    v5 = ScaleformTexture::ScaleformTexture(this: v4, pRenderer: this);
  else
    v5 = nullptr;
  LeaveCriticalSection(lpCriticalSection: &p_m_texturesLock->cs);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10002B40
// Name: public: virtual class GRenderTarget __near * ScaleformRenderer::CreateRenderTarget(void)
// Source: json
//------------------------------------------------------------------------------
ScaleformRenderTarget *__thiscall ScaleformRenderer::CreateRenderTarget(ScaleformRenderer *this)
{
  GLock *p_m_texturesLock; // edi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  ScaleformRenderTarget *v4; // eax
  ScaleformRenderTarget *v5; // esi
  int v7; // [esp+10h] [ebp-10h] BYREF
  int v8; // [esp+1Ch] [ebp-4h]

  p_m_texturesLock = &this->m_texturesLock;
  EnterCriticalSection(lpCriticalSection: &this->m_texturesLock.cs);
  v7 = 65;
  Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
  v8 = 0;
  v4 = (ScaleformRenderTarget *)Alloc_2(this: GMemory::pGlobalHeap, a2: 36u, a3: (const GAllocDebugInfo *)&v7);
  LOBYTE(v8) = 1;
  if ( v4 != nullptr )
    v5 = ScaleformRenderTarget::ScaleformRenderTarget(this: v4, pRenderer: this);
  else
    v5 = nullptr;
  v8 = -1;
  LeaveCriticalSection(lpCriticalSection: &p_m_texturesLock->cs);
  ScaleformRenderTarget::InitRenderTarget(this: v5);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10002BD0
// Name: public: virtual void ScaleformRenderer::FillStyleBitmap(struct GRenderer::FillTexture const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::FillStyleBitmap(ScaleformRenderer *this, const GRenderer::FillTexture *pfill)
{
  this->m_fillStyle.m_style = Bitmap;
  this->m_fillStyle.m_fillTexture = *pfill;
}

//------------------------------------------------------------------------------
// Address: 0x10002C40
// Name: public: void ScaleformRenderer::ApplyMatrix(class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::ApplyMatrix(ScaleformRenderer *this, const GMatrix2D *matIn)
{
  GMatrix3D resultMatrix; // [esp+4h] [ebp-98h] BYREF
  GMatrix3D m3d; // [esp+44h] [ebp-58h] BYREF
  GMatrix2D m; // [esp+84h] [ebp-18h] BYREF

  if ( this->m_pWorld != nullptr )
  {
    if ( this->m_matricesDirty )
    {
      this->m_matricesDirty = false;
      GMatrix3D::GMatrix3D(this: &resultMatrix, a2: &this->m_userMatrix);
      this->m_userViewProjection = resultMatrix;
      resultMatrix = this->m_userViewProjection;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&this->m_userViewProjection);
      resultMatrix = this->m_userViewProjection;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&this->m_userViewProjection);
    }
    GMatrix3D::GMatrix3D(this: &m3d, a2: matIn);
    resultMatrix = m3d;
    GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&m3d);
    resultMatrix = m3d;
    GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&m3d);
    GMatrix3D::Transpose(this: &m3d);
    this->m_pDevice->SetVertexShaderConstantF(this: this->m_pDevice, a2: 0, a3: (const float *)&m3d, a4: 4u);
  }
  else
  {
    m = this->m_userMatrix;
    GMatrix2D::Prepend(this: &m, a2: matIn);
    GMatrix3D::SetIdentity(this: &m3d);
    *(_QWORD *)&m3d.M_[0][0] = *(_QWORD *)&m.M_[0][0];
    *(_QWORD *)&m3d.M_[1][0] = *(_QWORD *)&m.M_[1][0];
    m3d.M_[0][3] = m.M_[0][2];
    m3d.M_[2][2] = 1.0;
    m3d.M_[1][3] = m.M_[1][2];
    m3d.M_[3][3] = 1.0;
    GMatrix3D::SetIdentity(this: &resultMatrix);
    GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&resultMatrix);
    this->m_pDevice->SetVertexShaderConstantF(this: this->m_pDevice, a2: 0, a3: (const float *)&resultMatrix, a4: 4u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E60
// Name: public: void ScaleformRenderer::ApplyColor(class GColor,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::ApplyColor(ScaleformRenderer *this, GColor c, bool force)
{
  float v3; // xmm4_4
  GRenderer::BlendType m_blendMode; // eax
  float rgba[4]; // [esp+0h] [ebp-10h] BYREF

  v3 = (float)c.Channels.Alpha * 0.0039215689;
  if ( c != this->m_currentColor.Raw || force )
  {
    this->m_currentColor = c;
    m_blendMode = this->m_blendMode;
    rgba[0] = (float)c.Channels.Red * 0.0039215689;
    rgba[1] = (float)c.Channels.Green * 0.0039215689;
    rgba[2] = (float)c.Channels.Blue * 0.0039215689;
    rgba[3] = (float)c.Channels.Alpha * 0.0039215689;
    if ( m_blendMode == Blend_Multiply || m_blendMode == Blend_Darken )
    {
      rgba[0] = (float)((float)((float)((float)c.Channels.Red * 0.0039215689) - 1.0) * v3) + 1.0;
      rgba[1] = (float)((float)((float)((float)c.Channels.Green * 0.0039215689) - 1.0) * v3) + 1.0;
      rgba[2] = (float)((float)((float)((float)c.Channels.Blue * 0.0039215689) - 1.0) * v3) + 1.0;
    }
    this->m_pDevice->SetPixelShaderConstantF(this: this->m_pDevice, a2: 0, a3: rgba, a4: 1u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F50
// Name: public: void GArrayDataBase<enum GRenderer::BlendType,struct GAllocatorLH<enum GRenderer::BlendType,2>,struct GArrayConstPolicy<0,4,1>>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1>>::Reserve(
        GArrayDataBase<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  GRenderer::BlendType *v5; // eax

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity != 0 )
    {
      v4 = 4 * ((newCapacity + 3) >> 2);
      if ( this->Data != nullptr )
      {
        v5 = (GRenderer::BlendType *)GMemory::pGlobalHeap->Realloc(
                                       this: GMemory::pGlobalHeap,
                                       a2: this->Data,
                                       a3: 16 * ((newCapacity + 3) >> 2));
      }
      else
      {
        newCapacity = 2;
        v5 = (GRenderer::BlendType *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                       this: GMemory::pGlobalHeap,
                                       a2: pheapAddr,
                                       a3: 4 * v4,
                                       a4: &newCapacity);
      }
      this->Policy.Capacity = v4;
      this->Data = v5;
    }
    else
    {
      if ( this->Data != nullptr )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->Data);
        this->Data = nullptr;
      }
      this->Policy.Capacity = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002FF0
// Name: public: virtual void ScaleformRenderer::DrawBitmaps(struct GRenderer::BitmapDesc __near *,int,int,int,class GTexture const __near *,class GMatrix2D const __near &,class GRenderer::CacheProvider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::DrawBitmaps(
        ScaleformRenderer *this,
        GRenderer::BitmapDesc *pbitmapList,
        int listSize,
        int startIndex,
        int count,
        GTextureImplNode *pti,
        const GMatrix2D *m,
        GRenderer::CacheProvider *pcache)
{
  float v9; // xmm1_4
  IDirect3DDevice9 *m_pDevice; // eax
  IDirect3DDevice9 *v11; // eax
  IDirect3DDevice9 *v12; // eax
  IDirect3DDevice9 *v13; // eax
  int v14; // edi
  int v15; // ecx
  int v16; // ebx
  int v17; // edx
  float *p_Top; // eax
  float *p_u; // ecx
  int v20; // edi
  int v21; // xmm0_4
  int v22; // xmm1_4
  int v23; // xmm2_4
  int v24; // edi
  int v25; // xmm0_4
  int v26; // xmm1_4
  int v27; // xmm2_4
  int v28; // edi
  int v29; // xmm0_4
  int v30; // xmm1_4
  int v31; // xmm2_4
  int v32; // edi
  int v33; // xmm0_4
  int v34; // xmm1_4
  int v35; // xmm2_4
  int v36; // edi
  int v37; // xmm0_4
  int v38; // xmm1_4
  int v39; // xmm2_4
  int v40; // edi
  int v41; // xmm0_4
  int v42; // xmm1_4
  int v43; // xmm2_4
  float v44[8]; // [esp+4h] [ebp-20h] BYREF
  int iBitmap; // [esp+3Ch] [ebp+18h]

  if ( this->m_pDevice != nullptr && (pti->IsDataValid(this: pti) || GTextureImplNode::CallRecreate(this: pti) != 0) )
  {
    v9 = this->m_currentCxform.M_[0][1];
    m_pDevice = this->m_pDevice;
    v44[0] = this->m_currentCxform.M_[0][0];
    v44[1] = this->m_currentCxform.M_[1][0];
    v44[2] = this->m_currentCxform.M_[2][0];
    v44[3] = this->m_currentCxform.M_[3][0];
    v44[4] = v9 * 0.0039215689;
    v44[5] = this->m_currentCxform.M_[1][1] * 0.0039215689;
    v44[6] = this->m_currentCxform.M_[2][1] * 0.0039215689;
    v44[7] = this->m_currentCxform.M_[3][1] * 0.0039215689;
    m_pDevice->SetPixelShaderConstantF(this: m_pDevice, a2: 2u, a3: v44, a4: 2u);
    ScaleformRenderer::ApplyBlendMode(this);
    this->m_pDevice->SetRenderState(this: this->m_pDevice, a2: D3DRS_ALPHABLENDENABLE, a3: 1u);
    ((void (__thiscall *)(GTextureImplNode *, _DWORD, int, int))pti->__vftable[1].InitTexture)(
      a1: pti,
      a2: 0,
      a3: 1,
      a4: 1);
    if ( this->m_currentPixelShaderType != PixelShader_TextTextureAlpha )
    {
      v11 = this->m_pDevice;
      this->m_currentPixelShaderType = PixelShader_TextTextureAlpha;
      v11->SetPixelShader(this: v11, a2: this->m_pPixelShaders[1].pObject);
    }
    if ( this->m_currentVertexDeclType != VertexDecl_Glyph )
    {
      v12 = this->m_pDevice;
      this->m_currentVertexDeclType = VertexDecl_Glyph;
      v12->SetVertexDeclaration(this: v12, a2: this->m_pVertexDecls[1].pObject);
    }
    if ( this->m_currentVertexShaderType != VertexShader_Glyph )
    {
      v13 = this->m_pDevice;
      this->m_currentVertexShaderType = VertexShader_Glyph;
      v13->SetVertexShader(this: v13, a2: this->m_pVertexShaders[1].pObject);
    }
    ScaleformRenderer::ApplyMatrix(this, matIn: m);
    v14 = count;
    v15 = 0;
    iBitmap = 0;
    while ( v15 < v14 )
    {
      v16 = 6 * (v14 - v15);
      if ( v16 >= 288 )
        v16 = 288;
      v17 = 0;
      if ( v16 > 0 )
      {
        p_Top = &pbitmapList[v15 + startIndex].Coords.Top;
        p_u = &this->m_glyphVertexBuffer[1].u;
        do
        {
          if ( iBitmap >= v14 )
            break;
          v20 = *((_DWORD *)p_Top + 7);
          v21 = *(_DWORD *)p_Top;
          v22 = *((_DWORD *)p_Top + 3);
          v23 = *((_DWORD *)p_Top + 4);
          *(p_u - 8) = *(p_Top - 1);
          *((_DWORD *)p_u - 7) = v21;
          *((_DWORD *)p_u - 5) = v22;
          *((_DWORD *)p_u - 4) = v23;
          *((_DWORD *)p_u - 6) = v20;
          v24 = *((_DWORD *)p_Top + 7);
          v25 = *(_DWORD *)p_Top;
          v26 = *((_DWORD *)p_Top + 5);
          v27 = *((_DWORD *)p_Top + 4);
          *(p_u - 3) = p_Top[1];
          *((_DWORD *)p_u - 2) = v25;
          *(_DWORD *)p_u = v26;
          *((_DWORD *)p_u + 1) = v27;
          *((_DWORD *)p_u - 1) = v24;
          v28 = *((_DWORD *)p_Top + 7);
          v29 = *((_DWORD *)p_Top + 2);
          v30 = *((_DWORD *)p_Top + 3);
          v31 = *((_DWORD *)p_Top + 6);
          p_u[2] = *(p_Top - 1);
          *((_DWORD *)p_u + 3) = v29;
          *((_DWORD *)p_u + 5) = v30;
          *((_DWORD *)p_u + 6) = v31;
          *((_DWORD *)p_u + 4) = v28;
          v32 = *((_DWORD *)p_Top + 7);
          v33 = *((_DWORD *)p_Top + 2);
          v34 = *((_DWORD *)p_Top + 3);
          v35 = *((_DWORD *)p_Top + 6);
          p_u[7] = *(p_Top - 1);
          ++iBitmap;
          *((_DWORD *)p_u + 8) = v33;
          *((_DWORD *)p_u + 10) = v34;
          *((_DWORD *)p_u + 11) = v35;
          *((_DWORD *)p_u + 9) = v32;
          v36 = *((_DWORD *)p_Top + 7);
          v37 = *(_DWORD *)p_Top;
          v38 = *((_DWORD *)p_Top + 5);
          v39 = *((_DWORD *)p_Top + 4);
          p_u[12] = p_Top[1];
          *((_DWORD *)p_u + 13) = v37;
          *((_DWORD *)p_u + 15) = v38;
          *((_DWORD *)p_u + 16) = v39;
          *((_DWORD *)p_u + 14) = v36;
          v40 = *((_DWORD *)p_Top + 7);
          v41 = *((_DWORD *)p_Top + 2);
          v42 = *((_DWORD *)p_Top + 5);
          v43 = *((_DWORD *)p_Top + 6);
          p_u[17] = p_Top[1];
          *((_DWORD *)p_u + 18) = v41;
          *((_DWORD *)p_u + 20) = v42;
          *((_DWORD *)p_u + 21) = v43;
          *((_DWORD *)p_u + 19) = v40;
          v14 = count;
          v17 += 6;
          p_Top += 9;
          p_u += 30;
        }
        while ( v17 < v16 );
        if ( v17 != 0 )
        {
          this->m_pDevice->DrawPrimitiveUP(
            this: this->m_pDevice,
            a2: D3DPT_TRIANGLELIST,
            a3: v17 / 3,
            a4: this->m_glyphVertexBuffer,
            a5: 20u);
          ++this->m_renderStats.Primitives;
          ++this->m_statDPTriangleCnt.Count;
        }
        v15 = iBitmap;
      }
    }
    this->m_renderStats.Triangles += 2 * v14;
    this->m_statTriangleCnt.Count += 2 * v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003320
// Name: public: virtual void ScaleformRenderer::DrawLineStrip(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::DrawLineStrip(ScaleformRenderer *this, int baseVertexIndex, unsigned int lineCount)
{
  IDirect3DDevice9 *m_pDevice; // eax
  IDirect3DDevice9 *v5; // eax
  IDirect3DDevice9 *v6; // eax

  if ( this->m_vertexStream.m_pVertexData != nullptr )
  {
    if ( this->m_currentVertexDeclType != VertexDecl_Strip )
    {
      m_pDevice = this->m_pDevice;
      this->m_currentVertexDeclType = VertexDecl_Strip;
      m_pDevice->SetVertexDeclaration(this: m_pDevice, a2: this->m_pVertexDecls[0].pObject);
    }
    if ( this->m_currentVertexShaderType != VertexShader_Strip )
    {
      v5 = this->m_pDevice;
      this->m_currentVertexShaderType = VertexShader_Strip;
      v5->SetVertexShader(this: v5, a2: this->m_pVertexShaders[0].pObject);
    }
    if ( this->m_currentPixelShaderType != PixelShader_SolidColor )
    {
      v6 = this->m_pDevice;
      this->m_currentPixelShaderType = PixelShader_SolidColor;
      v6->SetPixelShader(this: v6, a2: this->m_pPixelShaders[0].pObject);
    }
    ScaleformRenderer::ApplyColor(this, c: this->m_lineStyleColor, force: false);
    ScaleformRenderer::ApplyMatrix(this, matIn: &this->m_currentMatrix);
    this->m_pDevice->DrawPrimitiveUP(
      this: this->m_pDevice,
      a2: D3DPT_LINESTRIP,
      a3: lineCount,
      a4: (char *)this->m_vertexStream.m_pVertexData + baseVertexIndex * this->m_vertexStream.m_vertexSize,
      a5: this->m_vertexStream.m_vertexSize);
    this->m_renderStats.Lines += lineCount;
    ++this->m_renderStats.Primitives;
    ++this->m_statDPLineCnt.Count;
    this->m_statLineCnt.Count += lineCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003410
// Name: public: void ScaleformRenderer::ApplyCurrentStyle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::ApplyCurrentStyle(ScaleformRenderer *this)
{
  unsigned int v2; // ecx
  ScaleformRenderer::FillStyle::Style m_style; // eax
  HRESULT (__stdcall *SetRenderState)(IDirect3DDevice9 *, _D3DRENDERSTATETYPE, unsigned int); // edx
  IDirect3DPixelShader9 *pObject; // edx
  IDirect3DDevice9 *v6; // eax
  IDirect3DDevice9 *v7; // eax
  GRenderer::GouraudFillType m_gouraudFillType; // eax
  float v9; // xmm1_4
  float v10; // xmm1_4
  IDirect3DDevice9 *v11; // esi
  IDirect3DDevice9 *v12; // eax
  IDirect3DDevice9 *m_pDevice; // [esp-Ch] [ebp-34h]
  _DWORD v14[4]; // [esp+8h] [ebp-20h] BYREF
  float p[4]; // [esp+18h] [ebp-10h] BYREF

  ScaleformRenderer::ApplyBlendMode(this);
  v2 = this->m_blendMode > Blend_Normal
    || this->m_fillStyle.m_color.Channels.Alpha != 0xFF
    || this->m_fillStyle.m_style == Gouraud;
  this->m_pDevice->SetRenderState(this: this->m_pDevice, a2: D3DRS_ALPHABLENDENABLE, a3: v2);
  m_style = this->m_fillStyle.m_style;
  if ( m_style == Gouraud )
  {
    SetRenderState = this->m_pDevice->SetRenderState;
    m_pDevice = this->m_pDevice;
    if ( this->m_fillStyle.m_fillTexture.pTexture != nullptr )
    {
      SetRenderState(this: m_pDevice, a2: D3DRS_ALPHABLENDENABLE, a3: 1u);
      ((void (__thiscall *)(GTexture *, _DWORD, GRenderer::BitmapWrapMode, GRenderer::BitmapSampleMode))this->m_fillStyle.m_fillTexture.pTexture->__vftable[1].InitTexture)(
        a1: this->m_fillStyle.m_fillTexture.pTexture,
        a2: 0,
        a3: this->m_fillStyle.m_fillTexture.WrapMode,
        a4: this->m_fillStyle.m_fillTexture.SampleMode);
      v6 = this->m_pDevice;
      p[2] = 0.0;
      p[0] = this->m_fillStyle.m_fillTexture.TextureMatrix.M_[0][0];
      p[1] = this->m_fillStyle.m_fillTexture.TextureMatrix.M_[0][1];
      p[3] = this->m_fillStyle.m_fillTexture.TextureMatrix.M_[0][2];
      v6->SetVertexShaderConstantF(this: v6, a2: 4u, a3: p, a4: 1u);
      v7 = this->m_pDevice;
      p[0] = this->m_fillStyle.m_fillTexture.TextureMatrix.M_[1][0];
      p[1] = this->m_fillStyle.m_fillTexture.TextureMatrix.M_[1][1];
      p[3] = this->m_fillStyle.m_fillTexture.TextureMatrix.M_[1][2];
      v7->SetVertexShaderConstantF(this: v7, a2: 5u, a3: p, a4: 1u);
      m_gouraudFillType = this->m_fillStyle.m_gouraudFillType;
      if ( m_gouraudFillType != GFill_1TextureColor && m_gouraudFillType != GFill_1Texture
        || this->m_currentPixelShaderType == PixelShader_CxformGauraudTexture )
      {
        goto LABEL_18;
      }
      this->m_currentPixelShaderType = PixelShader_CxformGauraudTexture;
      pObject = this->m_pPixelShaders[4].pObject;
      goto LABEL_17;
    }
    SetRenderState(this: m_pDevice, a2: D3DRS_ALPHABLENDENABLE, a3: 1u);
    if ( this->m_vertexStream.m_vertexFmt == Vertex_XY16iC32 )
    {
      if ( this->m_currentPixelShaderType != PixelShader_CxformGauraudNoAddAlpha )
      {
        this->m_currentPixelShaderType = PixelShader_CxformGauraudNoAddAlpha;
        pObject = this->m_pPixelShaders[3].pObject;
LABEL_17:
        this->m_pDevice->SetPixelShader(this: this->m_pDevice, a2: pObject);
      }
    }
    else if ( this->m_currentPixelShaderType != PixelShader_CxformGauraud )
    {
      this->m_currentPixelShaderType = PixelShader_CxformGauraud;
      pObject = this->m_pPixelShaders[2].pObject;
      goto LABEL_17;
    }
LABEL_18:
    v9 = this->m_currentCxform.M_[0][1];
    v14[0] = LODWORD(this->m_currentCxform.M_[0][0]);
    v14[1] = LODWORD(this->m_currentCxform.M_[1][0]);
    v14[2] = LODWORD(this->m_currentCxform.M_[2][0]);
    v14[3] = LODWORD(this->m_currentCxform.M_[3][0]);
    p[0] = v9 * 0.0039215689;
    p[1] = this->m_currentCxform.M_[1][1] * 0.0039215689;
    p[2] = this->m_currentCxform.M_[2][1] * 0.0039215689;
    v10 = this->m_currentCxform.M_[3][1];
    v11 = this->m_pDevice;
    p[3] = v10 * 0.0039215689;
    v11->SetPixelShaderConstantF(this: v11, a2: 2u, a3: (const float *)v14, a4: 2u);
    return;
  }
  if ( m_style == Color )
  {
    if ( this->m_currentPixelShaderType != PixelShader_SolidColor )
    {
      v12 = this->m_pDevice;
      this->m_currentPixelShaderType = PixelShader_SolidColor;
      v12->SetPixelShader(this: v12, a2: this->m_pPixelShaders[0].pObject);
    }
    ScaleformRenderer::ApplyColor(this, c: this->m_fillStyle.m_color, force: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003680
// Name: public: void ScaleformRenderer::DeviceLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::DeviceLost(ScaleformRenderer *this)
{
  ScaleformRenderer *v1; // esi
  GRendererNode *v2; // ebx
  ScaleformTexture *v3; // ebx
  GRendererNode *v4; // eax
  LONG Value; // esi
  LONG *p_Value; // edi
  GRendererNode *v7; // eax
  ScaleformRenderTarget *v8; // ebx
  GRendererNode *v9; // eax
  LONG v10; // esi
  LONG *v11; // edi
  IDirect3DStateBlock9 *m_pStateBlock; // eax
  GLock *guard; // [esp+Ch] [ebp-1Ch]
  GRendererNode *p_m_renderTargets; // [esp+10h] [ebp-18h]
  ScaleformRenderTarget *pNext; // [esp+14h] [ebp-14h]
  ScaleformRenderTarget *pNexta; // [esp+14h] [ebp-14h]

  v1 = this;
  guard = &this->m_texturesLock;
  EnterCriticalSection(lpCriticalSection: &this->m_texturesLock.cs);
  v2 = v1->m_textures.pNext;
  if ( v2 != nullptr )
  {
    v3 = (ScaleformTexture *)&v2[-1];
    if ( v3 != nullptr )
    {
      do
      {
        if ( &v3->GRendererNode == &v1->m_textures )
          break;
        v4 = v3->pNext;
        if ( v4 != nullptr )
          pNext = (ScaleformRenderTarget *)&v4[-1];
        else
          pNext = nullptr;
        Value = v3->RefCount.Value;
        p_Value = (LONG *)&v3->RefCount.Value;
        if ( Value != 0 )
        {
          while ( InterlockedCompareExchange(Destination: &v3->RefCount.Value, Exchange: Value + 1, Comperand: Value) != Value )
          {
            Value = *p_Value;
            if ( *p_Value == 0 )
              goto LABEL_13;
          }
          ScaleformTexture::ReleaseTexture(this: v3);
          GTextureImplNode::CallHandlers(this: v3, event: Event_DataLost);
          if ( InterlockedExchangeAdd(Addend: &v3->RefCount.Value, Value: -1) == 1 )
            ((void (__thiscall *)(ScaleformTexture *, int))v3->dtr_GTexture)(a1: v3, a2: 1);
        }
LABEL_13:
        v3 = (ScaleformTexture *)pNext;
        v1 = this;
      }
      while ( pNext != nullptr );
    }
  }
  v7 = v1->m_renderTargets.pNext;
  if ( v7 != nullptr )
  {
    v8 = (ScaleformRenderTarget *)&v7[-1];
    if ( v7 != (GRendererNode *)8 )
    {
      p_m_renderTargets = &v1->m_renderTargets;
      do
      {
        if ( &v8->GRendererNode == p_m_renderTargets )
          break;
        v9 = v8->pNext;
        if ( v9 != nullptr )
          pNexta = (ScaleformRenderTarget *)&v9[-1];
        else
          pNexta = nullptr;
        v10 = v8->RefCount.Value;
        v11 = (LONG *)&v8->RefCount.Value;
        if ( v10 != 0 )
        {
          while ( InterlockedCompareExchange(Destination: &v8->RefCount.Value, Exchange: v10 + 1, Comperand: v10) != v10 )
          {
            v10 = *v11;
            if ( *v11 == 0 )
              goto LABEL_29;
          }
          if ( v8->m_hRenderTargetTexture != 0 )
          {
            ScaleformRenderTarget::ReleaseResources(this: v8);
            GRenderTargetImplNode::CallHandlers(this: v8, event: Event_DataLost);
          }
          if ( InterlockedExchangeAdd(Addend: &v8->RefCount.Value, Value: -1) == 1 )
            ((void (__thiscall *)(ScaleformRenderTarget *, int))v8->dtr_GRenderTarget)(a1: v8, a2: 1);
        }
LABEL_29:
        v8 = pNexta;
        v1 = this;
      }
      while ( pNexta != nullptr );
    }
  }
  LeaveCriticalSection(lpCriticalSection: &guard->cs);
  ScaleformRenderer::ReleaseShaders(this: v1);
  GDynamicVertexStream::ReleaseDynamicBuffers(this: &v1->m_vertexStream, lostDevice: true);
  m_pStateBlock = v1->m_pStateBlock;
  if ( m_pStateBlock != nullptr )
  {
    m_pStateBlock->Release(this: v1->m_pStateBlock);
    v1->m_pStateBlock = nullptr;
  }
  v1->m_pDevice->Release(this: v1->m_pDevice);
  v1->m_pDevice = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003830
// Name: public: virtual void ScaleformRenderer::DrawIndexedTriList(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::DrawIndexedTriList(
        ScaleformRenderer *this,
        int baseVertexIndex,
        int minVertexIndex,
        int numVertices,
        int startIndex,
        int triangleCount)
{
  IDirect3DDevice9 *m_pDevice; // eax
  __int32 v8; // ecx
  __int32 v9; // ecx
  IDirect3DVertexShader9 *pObject; // edx
  GDynamicVertexStream::PrimitiveDesc prim; // [esp+8h] [ebp-14h] BYREF

  m_pDevice = this->m_pDevice;
  if ( m_pDevice != nullptr
    && this->m_vertexStream.m_pVertexData != nullptr
    && this->m_vertexStream.m_pIndexData != nullptr
    && this->m_vertexStream.m_indexFmt != D3DFMT_UNKNOWN )
  {
    v8 = this->m_vertexStream.m_vertexFmt - 1;
    if ( v8 != 0 )
    {
      v9 = v8 - 2;
      if ( v9 != 0 )
      {
        if ( v9 != 1 )
          goto LABEL_21;
        if ( this->m_currentVertexDeclType != VertexDecl_XY16iCF32 )
        {
          this->m_currentVertexDeclType = VertexDecl_XY16iCF32;
          m_pDevice->SetVertexDeclaration(this: m_pDevice, a2: this->m_pVertexDecls[3].pObject);
        }
        if ( this->m_currentVertexShaderType == VertexShader_XY16iCF32 )
          goto LABEL_21;
        this->m_currentVertexShaderType = VertexShader_XY16iCF32;
        pObject = this->m_pVertexShaders[3].pObject;
      }
      else
      {
        if ( this->m_currentVertexDeclType != VertexDecl_XY16iC32 )
        {
          this->m_currentVertexDeclType = VertexDecl_XY16iC32;
          m_pDevice->SetVertexDeclaration(this: m_pDevice, a2: this->m_pVertexDecls[2].pObject);
        }
        if ( this->m_currentVertexShaderType == VertexShader_XY16iC32 )
          goto LABEL_21;
        this->m_currentVertexShaderType = VertexShader_XY16iC32;
        pObject = this->m_pVertexShaders[2].pObject;
      }
    }
    else
    {
      if ( this->m_currentVertexDeclType != VertexDecl_Strip )
      {
        this->m_currentVertexDeclType = VertexDecl_Strip;
        m_pDevice->SetVertexDeclaration(this: m_pDevice, a2: this->m_pVertexDecls[0].pObject);
      }
      if ( this->m_currentVertexShaderType == VertexShader_Strip )
        goto LABEL_21;
      this->m_currentVertexShaderType = VertexShader_Strip;
      pObject = this->m_pVertexShaders[0].pObject;
    }
    this->m_pDevice->SetVertexShader(this: this->m_pDevice, a2: pObject);
LABEL_21:
    ScaleformRenderer::ApplyCurrentStyle(this);
    ScaleformRenderer::ApplyMatrix(this, matIn: &this->m_currentMatrix);
    prim.m_minVertexIndex = minVertexIndex;
    prim.m_baseVertexIndex = baseVertexIndex;
    prim.m_numVertices = numVertices;
    prim.m_startIndex = startIndex;
    prim.m_triangleCount = triangleCount;
    if ( GDynamicVertexStream::PrepareVertexData(this: &this->m_vertexStream, &prim) != 0 )
    {
      GDynamicVertexStream::DrawTriangles(this: &this->m_vertexStream);
      this->m_renderStats.Triangles += triangleCount;
      ++this->m_renderStats.Primitives;
      ++this->m_statDPTriangleCnt.Count;
      this->m_statTriangleCnt.Count += triangleCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100039C0
// Name: public: virtual ScaleformRenderer::~ScaleformRenderer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::~ScaleformRenderer(ScaleformRenderer *this)
{
  int v2; // [esp+0h] [ebp-14h]

  this->__vftable = (ScaleformRenderer_vtbl *)&ScaleformRenderer::`vftable';
  ScaleformRenderer::ReleaseResources(this);
  if ( this->m_pSavedRenderStates != nullptr )
  {
    free(pMem: this->m_pSavedRenderStates);
    this->m_pSavedRenderStates = nullptr;
  }
  `eh vector destructor iterator'(
    ptr: this->m_pVertexDecls,
    size: 4u,
    count: 4,
    pDtor: (void (__thiscall *)(void *))GPtr<IDirect3DVertexShader9>::~GPtr<IDirect3DVertexShader9>);
  `eh vector destructor iterator'(
    ptr: this->m_pVertexShaders,
    size: 4u,
    count: 4,
    pDtor: (void (__thiscall *)(void *))GPtr<IDirect3DVertexShader9>::~GPtr<IDirect3DVertexShader9>);
  `eh vector destructor iterator'(
    ptr: this->m_pPixelShaders,
    size: 4u,
    count: 5,
    pDtor: (void (__thiscall *)(void *))GPtr<IDirect3DVertexShader9>::~GPtr<IDirect3DVertexShader9>);
  GDynamicVertexStream::~GDynamicVertexStream(this: &this->m_vertexStream);
  GLock::~GLock(lpCriticalSection: &this->m_texturesLock.cs);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->m_blendModeStack.Data.Data);
  GRenderer::~GRenderer((CUtlMemory<char *,int> *)this, a2: v2, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x10003AB0
// Name: public: virtual void GRenderer::SetStereoParams(struct GRenderer::StereoParams)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderer::SetStereoParams(GRenderer *this, GRenderer::StereoParams sParams)
{
  this->S3DParams = sParams;
  if ( this->S3DParams.DisplayWidthCm == 0.0 )
    this->S3DParams.DisplayWidthCm = (float)(sParams.DisplayDiagInches
                                           / fsqrt(
                                               (float)((float)(1.0 / sParams.DisplayAspectRatio)
                                                     * (float)(1.0 / sParams.DisplayAspectRatio))
                                             + 1.0))
                                   * 2.54;
}

//------------------------------------------------------------------------------
// Address: 0x10003B30
// Name: public: virtual void ScaleformRenderer::BeginDisplay(class GColor,class GViewport const __near &,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall ScaleformRenderer::BeginDisplay(
        ScaleformRenderer *this,
        GColor backgroundColor,
        float vpin,
        float x0,
        float x1,
        float y0,
        float y1)
{
  IDirect3DStateBlock9 *m_pStateBlock; // eax
  const GViewport *v9; // esi
  unsigned int Height; // ecx
  IDirect3DDevice9 *m_pDevice; // eax
  HRESULT (__stdcall *GetRenderTarget)(IDirect3DDevice9 *, unsigned int, IDirect3DSurface9 **); // edx
  const GViewport *v13; // eax
  float v14; // xmm4_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm5_4
  int Top; // ecx
  int Left; // eax
  int Width; // edi
  int ScissorHeight; // edx
  int v22; // ecx
  int v23; // edx
  float v24; // xmm2_4
  float v25; // xmm1_4
  bool v26; // sf
  double v27; // st7
  float v28; // xmm4_4
  float v29; // xmm3_4
  int v30; // esi
  int v31; // eax
  float v32; // xmm4_4
  int m_nWidth; // eax
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  int m_nHeight; // eax
  float v38; // xmm2_4
  float v39; // xmm4_4
  float v40; // xmm0_4
  GArrayLH<enum GRenderer::BlendType,2,GArrayConstPolicy<0,4,1> > *p_m_blendModeStack; // esi
  unsigned int Capacity; // eax
  GRenderer::BlendType *v43; // eax
  IDirect3DDevice9 *v44; // eax
  IDirect3DDevice9 *v45; // ebx
  void *v46; // [esp-8h] [ebp-E4h] BYREF
  int p_m_userMatrix; // [esp-4h] [ebp-E0h]
  GMatrix3D v48; // [esp+Ch] [ebp-D0h] BYREF
  _D3DSURFACE_DESC surfaceDesc; // [esp+4Ch] [ebp-90h] BYREF
  ScaleformRenderer::BeginDisplay::__l51::Vertex strip[4]; // [esp+6Ch] [ebp-70h] BYREF
  _BYTE v51[64]; // [esp+7Ch] [ebp-60h] OVERLAPPED BYREF
  int viewportY0_save; // [esp+BCh] [ebp-20h]
  int viewportX0_save; // [esp+C0h] [ebp-1Ch]
  int scissorY0_save; // [esp+C4h] [ebp-18h]
  float dy; // [esp+C8h] [ebp-14h]
  int scissorX0_save; // [esp+CCh] [ebp-10h]
  int v57; // [esp+D8h] [ebp-4h]

  if ( this->m_pDevice != nullptr )
  {
    g_pShaderAPI->ResetRenderState(this: g_pShaderAPI, a2: false);
    m_pStateBlock = this->m_pStateBlock;
    if ( m_pStateBlock != nullptr )
      m_pStateBlock->Capture(this: this->m_pStateBlock);
    g_pShaderAPI->SetSRGBWrite(this: g_pShaderAPI, a2: false);
    g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: SHADER_SAMPLER0, a3: TEXTURE_BINDFLAGS_NONE, a4: 0);
    g_pShaderAPI->SceneFogMode(this: g_pShaderAPI, a2: MATERIAL_FOG_NONE);
    g_pShaderAPI->ShadeMode(this: g_pShaderAPI, a2: SHADER_SMOOTH);
    g_pShaderAPI->SetRenderTarget(this: g_pShaderAPI, a2: -1, a3: -1);
    v9 = (const GViewport *)LODWORD(vpin);
    this->m_currentVertexDeclType = VertexDecl_Count;
    this->m_currentVertexShaderType = VertexShader_Count;
    this->m_currentPixelShaderType = PixelShader_Count;
    this->m_currentColor.Raw = 0;
    Height = v9->Height;
    surfaceDesc.Width = v9->Width;
    surfaceDesc.Height = Height;
    vpin = 0.0;
    m_pDevice = this->m_pDevice;
    GetRenderTarget = m_pDevice->GetRenderTarget;
    v57 = 0;
    GetRenderTarget(this: m_pDevice, a2: 0, a3: (IDirect3DSurface9 **)&vpin);
    v13 = (const GViewport *)LODWORD(vpin);
    if ( vpin != 0.0 )
    {
      (*(void (__stdcall **)(float, _D3DSURFACE_DESC *))(*(_DWORD *)LODWORD(vpin) + 48))(
        a1: COERCE_FLOAT(LODWORD(vpin)),
        a2: &surfaceDesc);
      v13 = (const GViewport *)LODWORD(vpin);
    }
    v57 = -1;
    if ( v13 != nullptr )
      (*(void (__stdcall **)(const GViewport *))(v13->BufferWidth + 8))(a1: v13);
    v14 = x1;
    v15 = y1;
    v16 = x1 - x0;
    v17 = y1 - y0;
    vpin = x1 - x0;
    dy = y1 - y0;
    if ( (float)(x1 - x0) < 1.0 )
    {
      v16 = 1.0;
      vpin = 1.0;
    }
    if ( v17 < 1.0 )
    {
      v17 = 1.0;
      dy = 1.0;
    }
    Top = v9->Top;
    Left = v9->Left;
    Width = v9->Width;
    *(_DWORD *)&v51[60] = v9->Flags;
    *(_DWORD *)&v51[36] = v9->ScissorLeft;
    *(_DWORD *)&v51[40] = v9->ScissorTop;
    *(_DWORD *)&v51[44] = v9->ScissorWidth;
    ScissorHeight = v9->ScissorHeight;
    *(_DWORD *)&v51[24] = Top;
    v22 = v9->Height;
    *(_DWORD *)&v51[48] = ScissorHeight;
    viewportY0_save = *(_DWORD *)&v51[24];
    v23 = Width;
    v24 = x0;
    v25 = y0;
    viewportX0_save = Left;
    scissorX0_save = Width;
    scissorY0_save = v22;
    if ( Left < 0 )
    {
      v24 = (float)((float)((float)-Left * v16) / (float)Width) + x0;
      if ( -Left < Width )
        Width += Left;
      else
        *(float *)&Width = 0.0;
      Left = 0;
    }
    if ( v23 + viewportX0_save > (int)surfaceDesc.Width )
    {
      v26 = (signed int)(surfaceDesc.Width - viewportX0_save) < 0;
      viewportX0_save = surfaceDesc.Width - viewportX0_save;
      v27 = (double)viewportX0_save;
      if ( v26 )
        v27 = v27 + 4294967300.0;
      Width = surfaceDesc.Width - Left;
      *(float *)&scissorX0_save = v27 * vpin / (double)scissorX0_save + x0;
      v14 = *(float *)&scissorX0_save;
    }
    if ( *(int *)&v51[24] < 0 )
    {
      v25 = (float)((float)((float)-*(_DWORD *)&v51[24] * v17) / (float)v22) + y0;
      if ( -*(_DWORD *)&v51[24] < v22 )
        v22 += *(_DWORD *)&v51[24];
      else
        v22 = 0;
      *(_DWORD *)&v51[24] = 0;
    }
    if ( scissorY0_save + viewportY0_save > (int)surfaceDesc.Height )
    {
      v22 = surfaceDesc.Height - *(_DWORD *)&v51[24];
      *(float *)&scissorX0_save = (double)(surfaceDesc.Height - viewportY0_save) * dy / (double)scissorY0_save + y0;
      v15 = *(float *)&scissorX0_save;
    }
    v28 = v14 - v24;
    v29 = v15 - v25;
    vpin = v28;
    dy = v29;
    if ( (v51[60] & 4) != 0 )
    {
      v30 = *(_DWORD *)&v51[40];
      scissorX0_save = *(int *)&v51[36];
      if ( *(int *)&v51[36] < Left )
        *(_DWORD *)&v51[36] = Left;
      if ( *(int *)&v51[40] < *(int *)&v51[24] )
        *(_DWORD *)&v51[40] = *(_DWORD *)&v51[24];
      *(_DWORD *)&v51[44] += scissorX0_save - *(_DWORD *)&v51[36];
      *(_DWORD *)&v51[48] += v30 - *(_DWORD *)&v51[40];
      if ( *(_DWORD *)&v51[36] + *(_DWORD *)&v51[44] > Width + Left )
        *(_DWORD *)&v51[44] = Left + Width - *(_DWORD *)&v51[36];
      v31 = *(_DWORD *)&v51[48];
      if ( *(_DWORD *)&v51[48] + *(_DWORD *)&v51[40] > v22 + *(_DWORD *)&v51[24] )
        v31 = *(_DWORD *)&v51[24] + v22 - *(_DWORD *)&v51[40];
      this->m_Viewport.m_nTopLeftX = *(_DWORD *)&v51[36];
      this->m_Viewport.m_nTopLeftY = *(_DWORD *)&v51[40];
      v32 = (float)(v28 / (float)Width) * (float)*(int *)&v51[44];
      this->m_Viewport.m_nWidth = *(_DWORD *)&v51[44];
      this->m_Viewport.m_nHeight = v31;
      vpin = v32;
      dy = (float)(v29 / (float)v22) * (float)v31;
    }
    else
    {
      this->m_Viewport.m_nTopLeftX = Left;
      this->m_Viewport.m_nTopLeftY = *(_DWORD *)&v51[24];
      this->m_Viewport.m_nWidth = Width;
      this->m_Viewport.m_nHeight = v22;
    }
    g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: &this->m_Viewport, a4: true);
    GMatrix3D::SetIdentity(this: &this->m_viewportMatrix);
    m_nWidth = this->m_Viewport.m_nWidth;
    v34 = 1.0 / vpin;
    this->m_viewportMatrix.M_[0][0] = (float)(1.0 / vpin) * 2.0;
    v35 = 1.0 / dy;
    this->m_viewportMatrix.M_[1][1] = (float)(1.0 / dy) * -2.0;
    this->m_viewportMatrix.M_[2][2] = -1.0;
    if ( m_nWidth <= 0 )
      v36 = 0.0;
    else
      v36 = 1.0 / (float)m_nWidth;
    m_nHeight = this->m_Viewport.m_nHeight;
    if ( m_nHeight <= 0 )
      v38 = 0.0;
    else
      v38 = 1.0 / (float)m_nHeight;
    v39 = (float)(x0 + x1) * v34;
    v40 = (float)((float)(y0 + y1) * v35) + v38;
    p_m_userMatrix = (int)&this->m_userMatrix;
    this->m_viewportMatrix.M_[0][3] = COERCE_FLOAT(LODWORD(v39) ^ _mask__NegFloat_) - v36;
    this->m_viewportMatrix.M_[1][3] = v40;
    GMatrix3D::GMatrix3D(this: &v48, a2: (const struct GMatrix2D *)p_m_userMatrix);
    qmemcpy(v51, &this->m_viewportMatrix, sizeof(v51));
    p_m_userMatrix = (int)v51;
    v46 = (void *)&v48;
    GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&this->m_viewportMatrix);
    p_m_blendModeStack = &this->m_blendModeStack;
    if ( this->m_blendModeStack.Data.Size != 0 )
    {
      Capacity = this->m_blendModeStack.Data.Policy.Capacity;
      if ( (Capacity & 0xFFFFFFFE) != 0 && Capacity == 0 )
      {
        if ( p_m_blendModeStack->Data.Data != nullptr )
        {
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: p_m_blendModeStack->Data.Data);
          p_m_blendModeStack->Data.Data = nullptr;
        }
        this->m_blendModeStack.Data.Policy.Capacity = 0;
      }
    }
    else if ( this->m_blendModeStack.Data.Policy.Capacity == 0 )
    {
      GArrayDataBase<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1>>::Reserve(
        this: &this->m_blendModeStack.Data,
        pheapAddr: &this->m_blendModeStack,
        newCapacity: 0);
    }
    this->m_blendModeStack.Data.Size = 0;
    if ( this->m_blendModeStack.Data.Policy.Capacity < 0x10 )
    {
      if ( p_m_blendModeStack->Data.Data != nullptr )
      {
        v43 = (GRenderer::BlendType *)GMemory::pGlobalHeap->Realloc(
                                        this: GMemory::pGlobalHeap,
                                        a2: p_m_blendModeStack->Data.Data,
                                        a3: 64);
      }
      else
      {
        LODWORD(vpin) = 2;
        v43 = (GRenderer::BlendType *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                        this: GMemory::pGlobalHeap,
                                        a2: &this->m_blendModeStack,
                                        a3: 64,
                                        a4: &vpin);
      }
      p_m_blendModeStack->Data.Data = v43;
      this->m_blendModeStack.Data.Policy.Capacity = 16;
    }
    v44 = this->m_pDevice;
    p_m_userMatrix = 1;
    this->m_blendMode = Blend_None;
    v44->SetRenderState(this: v44, a2: D3DRS_ALPHABLENDENABLE, a3: p_m_userMatrix);
    ScaleformRenderer::ApplyBlendMode(this);
    this->m_pDevice->SetRenderState(this: this->m_pDevice, a2: D3DRS_ALPHATESTENABLE, a3: 0);
    g_pShaderAPI->SetScissorRect(this: g_pShaderAPI, a2: 0, a3: 0, a4: 0, a5: 0, a6: false);
    this->m_pDevice->SetRenderState(this: this->m_pDevice, a2: D3DRS_ZWRITEENABLE, a3: 0);
    this->m_pDevice->SetRenderState(this: this->m_pDevice, a2: D3DRS_ZENABLE, a3: 0);
    this->m_pDevice->SetRenderState(this: this->m_pDevice, a2: D3DRS_COLORWRITEENABLE, a3: 15u);
    this->m_pDevice->SetRenderState(this: this->m_pDevice, a2: D3DRS_CULLMODE, a3: 1u);
    this->m_pDevice->SetRenderState(this: this->m_pDevice, a2: D3DRS_ZFUNC, a3: 8u);
    GDynamicVertexStream::BeginDisplay(this: &this->m_vertexStream);
    *(_WORD *)&this->m_stencilAvailable = 0;
    this->m_stencilCounter = 0;
    this->m_drawingMask = false;
    if ( backgroundColor.Channels.Alpha != 0 )
    {
      vpin = COERCE_FLOAT(&v46);
      ScaleformRenderer::ApplyColor(this, c: backgroundColor, force: false);
      this->SetMatrix(this, a2: &GMatrix2D::Identity);
      this->SetWorld3D(this, a2: nullptr);
      ScaleformRenderer::ApplyMatrix(this, matIn: &this->m_currentMatrix);
      this->m_pDevice->SetRenderState(
        this: this->m_pDevice,
        a2: D3DRS_ALPHABLENDENABLE,
        a3: backgroundColor.Channels.Alpha != 0xFF);
      v45 = this->m_pDevice;
      p_m_userMatrix = 4;
      strip[0].y = (int)y0;
      strip[1].y = strip[0].y;
      v46 = strip;
      strip[0].x = (int)x0;
      strip[2].x = strip[0].x;
      strip[1].x = (int)x1;
      strip[3].x = strip[1].x;
      strip[2].y = (int)y1;
      strip[3].y = strip[2].y;
      v45->DrawPrimitiveUP(this: v45, a2: D3DPT_TRIANGLESTRIP, a3: 2u, a4: strip, a5: 4u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100041B0
// Name: public: virtual void ScaleformRenderer::PushBlendMode(enum GRenderer::BlendType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::PushBlendMode(ScaleformRenderer *this, GRenderer::BlendType mode)
{
  GArrayLH<enum GRenderer::BlendType,2,GArrayConstPolicy<0,4,1> > *p_m_blendModeStack; // edi
  unsigned int v4; // esi
  GRenderer::BlendType *v5; // eax

  p_m_blendModeStack = &this->m_blendModeStack;
  v4 = this->m_blendModeStack.Data.Size + 1;
  if ( v4 >= this->m_blendModeStack.Data.Size )
  {
    if ( v4 >= this->m_blendModeStack.Data.Policy.Capacity )
      GArrayDataBase<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1>>::Reserve(
        this: &p_m_blendModeStack->Data,
        pheapAddr: p_m_blendModeStack,
        newCapacity: v4 + (v4 >> 2));
  }
  else if ( v4 < this->m_blendModeStack.Data.Policy.Capacity >> 1 )
  {
    GArrayDataBase<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1>>::Reserve(
      this: &p_m_blendModeStack->Data,
      pheapAddr: p_m_blendModeStack,
      newCapacity: this->m_blendModeStack.Data.Size + 1);
  }
  v5 = &p_m_blendModeStack->Data.Data[v4 - 1];
  p_m_blendModeStack->Data.Size = v4;
  if ( v5 != nullptr )
    *v5 = this->m_blendMode;
  if ( mode > Blend_Layer && this->m_blendMode != mode )
  {
    this->m_blendMode = mode;
    ScaleformRenderer::ApplyBlendMode(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004220
// Name: public: virtual void ScaleformRenderer::PopBlendMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::PopBlendMode(ScaleformRenderer *this)
{
  unsigned int Size; // eax
  int v3; // eax
  GRenderer::BlendType *Data; // edx
  int *v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // edi
  GRenderer::BlendType newBlendMode; // [esp+4h] [ebp-4h]

  Size = this->m_blendModeStack.Data.Size;
  if ( Size != 0 )
  {
    v3 = Size - 1;
    newBlendMode = Blend_None;
    if ( v3 >= 0 )
    {
      Data = this->m_blendModeStack.Data.Data;
      v5 = (int *)&Data[v3];
      while ( *v5 <= 2 )
      {
        --v5;
        if ( --v3 < 0 )
          goto LABEL_8;
      }
      newBlendMode = Data[v3];
    }
LABEL_8:
    v6 = this->m_blendModeStack.Data.Size;
    v7 = v6 - 1;
    if ( v6 != 0 )
    {
      if ( v7 < this->m_blendModeStack.Data.Policy.Capacity >> 1 )
        GArrayDataBase<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1>>::Reserve(
          this: &this->m_blendModeStack.Data,
          pheapAddr: &this->m_blendModeStack,
          newCapacity: v6 - 1);
    }
    else if ( v7 >= this->m_blendModeStack.Data.Policy.Capacity )
    {
      GArrayDataBase<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1>>::Reserve(
        this: &this->m_blendModeStack.Data,
        pheapAddr: &this->m_blendModeStack,
        newCapacity: v7 + (v7 >> 2));
    }
    this->m_blendModeStack.Data.Size = v7;
    if ( newBlendMode != this->m_blendMode )
    {
      this->m_blendMode = newBlendMode;
      ScaleformRenderer::ApplyBlendMode(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100042A0
// Name: public: ScaleformRenderer::ScaleformRenderer(void)
// Source: json
//------------------------------------------------------------------------------
ScaleformRenderer *__thiscall ScaleformRenderer::ScaleformRenderer(ScaleformRenderer *this)
{
  const CMaterialDict::MissingMaterial_t *v3; // [esp+0h] [ebp-18h]
  const CMaterialDict::MissingMaterial_t *v4; // [esp+0h] [ebp-18h]
  const CMaterialDict::MissingMaterial_t *v5; // [esp+0h] [ebp-18h]

  GRenderer::GRenderer(this);
  this->__vftable = (ScaleformRenderer_vtbl *)&ScaleformRenderer::`vftable';
  this->m_blendModeStack.Data.Data = nullptr;
  this->m_blendModeStack.Data.Size = 0;
  this->m_blendModeStack.Data.Policy.Capacity = 0;
  this->m_textures.pPrev = &this->m_textures;
  this->m_textures.pNext = &this->m_textures;
  this->m_renderTargets.pPrev = &this->m_renderTargets;
  this->m_renderTargets.pNext = &this->m_renderTargets;
  GLock::GLock(lpCriticalSection: &this->m_texturesLock.cs, spinCount: 0);
  GMatrix2D::SetIdentity(result: v3);
  GMatrix2D::SetIdentity(result: v4);
  GMatrix3D::SetIdentity(this: &this->m_viewportMatrix);
  GRenderer::Cxform::Cxform();
  GMatrix3D::SetIdentity(this: &this->m_projection);
  GMatrix3D::SetIdentity(this: &this->m_view);
  GMatrix3D::SetIdentity(this: &this->m_userViewProjection);
  GDynamicVertexStream::GDynamicVertexStream(this: &this->m_vertexStream);
  `eh vector constructor iterator'(
    ptr: this->m_pPixelShaders,
    size: 4u,
    count: 5,
    pCtor: (void (__thiscall *)(void *))CTextureReference::CTextureReference,
    pDtor: (void (__thiscall *)(void *))GPtr<IDirect3DVertexShader9>::~GPtr<IDirect3DVertexShader9>);
  `eh vector constructor iterator'(
    ptr: this->m_pVertexShaders,
    size: 4u,
    count: 4,
    pCtor: (void (__thiscall *)(void *))CTextureReference::CTextureReference,
    pDtor: (void (__thiscall *)(void *))GPtr<IDirect3DVertexShader9>::~GPtr<IDirect3DVertexShader9>);
  `eh vector constructor iterator'(
    ptr: this->m_pVertexDecls,
    size: 4u,
    count: 4,
    pCtor: (void (__thiscall *)(void *))CTextureReference::CTextureReference,
    pDtor: (void (__thiscall *)(void *))GPtr<IDirect3DVertexShader9>::~GPtr<IDirect3DVertexShader9>);
  GMatrix2D::SetIdentity(result: v5);
  this->m_Viewport.m_nVersion = 1;
  this->m_StencilState.m_ZFailOp = SHADER_STENCILOP_KEEP;
  this->m_StencilState.m_FailOp = SHADER_STENCILOP_KEEP;
  this->m_StencilState.m_PassOp = SHADER_STENCILOP_KEEP;
  this->m_StencilState.m_bEnable = false;
  this->m_StencilState.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
  this->m_StencilState.m_nReferenceValue = 0;
  this->m_StencilState.m_nWriteMask = -1;
  this->m_StencilState.m_nTestMask = -1;
  this->m_renderStats.Triangles = 0;
  this->m_renderStats.Lines = 0;
  this->m_renderStats.Primitives = 0;
  this->m_renderStats.Masks = 0;
  this->m_renderStats.Filters = 0;
  this->m_statTextureVMem.Allocated = 0;
  this->m_statTextureVMem.Used = 0;
  this->m_statTextureVMem.AllocCount = 0;
  this->m_statBufferVMem.Allocated = 0;
  this->m_statBufferVMem.Used = 0;
  this->m_statBufferVMem.AllocCount = 0;
  this->m_statTextureUploadCnt.Count = 0;
  this->m_statTextureUpdateCnt.Count = 0;
  this->m_statDPLineCnt.Count = 0;
  this->m_statDPTriangleCnt.Count = 0;
  this->m_statLineCnt.Count = 0;
  this->m_statTriangleCnt.Count = 0;
  this->m_statMaskCnt.Count = 0;
  this->m_statFilterCnt.Count = 0;
  this->m_pDevice = nullptr;
  this->m_blendMode = Blend_None;
  this->m_pWorld = nullptr;
  this->m_pSavedRenderStates = nullptr;
  this->m_pSavedPixelShader = nullptr;
  this->m_pSavedVertexShader = nullptr;
  this->m_matricesDirty = true;
  this->m_currentVertexDeclType = VertexDecl_Count;
  this->m_currentVertexShaderType = VertexShader_Count;
  this->m_currentPixelShaderType = PixelShader_Count;
  this->m_currentColor.Raw = 0;
  this->m_pDisplayRenderTarget = nullptr;
  this->m_texPowerOfTwoSupport = Full;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004510
// Name: public: static class ScaleformRenderer __near * ScaleformRenderer::CreateRenderer(void)
// Source: json
//------------------------------------------------------------------------------
ScaleformRenderer *__stdcall ScaleformRenderer::CreateRenderer()
{
  ScaleformRenderer *v0; // eax
  CUtlDict<int,unsigned short> *v2[4]; // [esp+4h] [ebp-10h] BYREF

  v2[0] = (CUtlDict<int,unsigned short> *)65;
  v0 = (ScaleformRenderer *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 6616, a3: v2);
  v2[3] = nullptr;
  if ( v0 != nullptr )
    return ScaleformRenderer::ScaleformRenderer(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10069DC0
// Name: public: void GArrayDataBase<class GFxValue,struct GAllocatorGH_CPP<class GFxValue,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__userpurge GArrayDataBase<GFxValue,GAllocatorGH_CPP<GFxValue,2>,GArrayDefaultPolicy>::Reserve@<eax>(
        int *a1@<ecx>,
        int a2@<esi>,
        int a3,
        int a4)
{
  void *result; // eax
  unsigned int v6; // ebx
  bool v7; // zf
  int v8; // esi
  int v9; // eax
  StringPoolCase_t v10; // ebx
  int v11; // [esp+8h] [ebp-10h]
  int v12; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  if ( a4 != 0 )
  {
    v6 = 4 * ((unsigned int)(a4 + 3) >> 2);
    v7 = *a1 == 0;
    a4 = v6;
    if ( v7 )
    {
      a4 = 2;
      result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 16 * v6, a3: &a4);
      a1[2] = v6;
      *a1 = (int)result;
    }
    else
    {
      v12 = 2;
      v8 = ((int (__thiscall *)(GMemoryHeap *, unsigned int, int *, int))GMemory::pGlobalHeap->Alloc_2)(
             a1: GMemory::pGlobalHeap,
             a2: 16 * v6,
             a3: &v12,
             a4: a2);
      v11 = v8;
      v13 = 0;
      if ( a1[1] != 0 )
      {
        v14 = 0;
        do
        {
          v9 = v14 + *a1;
          if ( v8 != 0 )
          {
            *(_DWORD *)v8 = 0;
            *(_DWORD *)(v8 + 4) = *(_DWORD *)(v9 + 4);
            *(_DWORD *)(v8 + 8) = *(_DWORD *)(v9 + 8);
            *(_DWORD *)(v8 + 12) = *(_DWORD *)(v9 + 12);
            if ( (*(_DWORD *)(v9 + 4) & 0x40) != 0 )
              GFxValue::AcquireManagedValue(this: (GFxValue *)v8, src: (const GFxValue *)v9);
          }
          v10 = v14 + *a1;
          if ( (*(_DWORD *)(v10 + 4) & 0x40) != 0 )
          {
            GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v10, val: v10);
            *(_DWORD *)v10 = 0;
          }
          v14 += 16;
          v8 += 16;
          ++v13;
        }
        while ( v13 < a1[1] );
        v8 = v11;
        v6 = a4;
      }
      result = (void *)((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *a1);
      *a1 = v8;
      a1[2] = v6;
    }
  }
  else
  {
    result = (void *)*a1;
    if ( *a1 != 0 )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *a1);
      *a1 = 0;
    }
    a1[2] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006BB10
// Name: public: void GArrayDataBase<class GPtr<class GFxResource>,struct GAllocatorGH<class GPtr<class GFxResource>,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GArrayDataBase<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        CVertexBuilder *this,
        int a2,
        unsigned int a3)
{
  unsigned int result; // eax

  result = this->m_VertexSize_BoneWeight;
  if ( a3 >= result )
  {
    if ( a3 >= this->m_VertexSize_BoneMatrixIndex )
      result = GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(this);
  }
  else
  {
    result = GConstructorMov<GPtr<GFxResource>>::DestructArray(
               a1: this->m_VertexSize_Position + 4 * a3,
               a2: result - a3);
    if ( a3 < (unsigned int)this->m_VertexSize_BoneMatrixIndex >> 1 )
    {
      result = GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(this);
      this->m_VertexSize_BoneWeight = a3;
      return result;
    }
  }
  this->m_VertexSize_BoneWeight = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006DBE0
// Name: public: void GArrayDataBase<class GPtr<class GFxMovieDefImpl>,struct GAllocatorGH<class GPtr<class GFxMovieDefImpl>,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,2>,GArrayDefaultPolicy>::ResizeNoConstruct@<eax>(
        CVertexBuilder *this@<ecx>,
        VertexShaderHandle_t__ *a2@<ebx>,
        int a3,
        unsigned int a4)
{
  unsigned int result; // eax
  int v7; // eax
  IShaderDevice **v8; // ebx
  VertexShaderHandle_t__ *v9; // [esp-4h] [ebp-Ch]
  int i; // [esp+14h] [ebp+Ch]

  result = this->m_VertexSize_BoneWeight;
  if ( a4 >= result )
  {
    if ( a4 >= this->m_VertexSize_BoneMatrixIndex )
      result = GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(this);
  }
  else
  {
    v7 = result - a4;
    v9 = a2;
    v8 = (IShaderDevice **)(this->m_VertexSize_Position + 4 * (v7 + a4) - 4);
    if ( v7 != 0 )
    {
      for ( i = v7; i != 0; --i )
      {
        if ( *v8 != nullptr )
          GFxResource::Release(this: *v8, a2: v9);
        --v8;
      }
    }
    result = (unsigned int)this->m_VertexSize_BoneMatrixIndex >> 1;
    if ( a4 < result )
    {
      result = GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(this);
      this->m_VertexSize_BoneWeight = a4;
      return result;
    }
  }
  this->m_VertexSize_BoneWeight = a4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100755F0
// Name: public: void GArrayDataBase<unsigned char,struct GAllocatorGH<unsigned char,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<unsigned char,GAllocatorGH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *this, a3: v5);
    }
    else
    {
      newCapacity = 2;
      result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: v5, a3: &newCapacity);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100758E0
// Name: public: void GArrayDataBase<class GRenderer __near *,struct GAllocatorGH<class GRenderer __near *,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        CVertexBuilder *this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  void *result; // eax
  int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( this->m_VertexSize_Position != 0 )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: this->m_VertexSize_Position,
                 a3: 16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * v5, a3: &newCapacity);
    }
    this->m_VertexSize_BoneMatrixIndex = v5;
    this->m_VertexSize_Position = (int)result;
  }
  else
  {
    result = (void *)this->m_VertexSize_Position;
    if ( this->m_VertexSize_Position != 0 )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: this->m_VertexSize_Position);
      this->m_VertexSize_Position = 0;
    }
    this->m_VertexSize_BoneMatrixIndex = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10075B40
// Name: public: void GArrayDataBase<class GString,struct GAllocatorGH<class GString,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GArrayDataBase<GString,GAllocatorGH<GString,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        CVertexBuilder *this,
        ButtonCode_t a2,
        unsigned int a3)
{
  char *result; // eax

  result = (char *)this->m_VertexSize_BoneWeight;
  if ( a3 >= (unsigned int)result )
  {
    if ( a3 >= this->m_VertexSize_BoneMatrixIndex )
      result = (char *)GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                         this,
                         pheapAddr: a2,
                         newCapacity: a3 + (a3 >> 2));
  }
  else
  {
    result = (char *)GConstructorMov<GString>::DestructArray(a1: this->m_VertexSize_Position + 4 * a3, a2: &result[-a3]);
    if ( a3 < (unsigned int)this->m_VertexSize_BoneMatrixIndex >> 1 )
    {
      result = (char *)GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                         this,
                         pheapAddr: a2,
                         newCapacity: a3);
      this->m_VertexSize_BoneWeight = a3;
      return result;
    }
  }
  this->m_VertexSize_BoneWeight = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B7E0
// Name: public: void GArrayDataBase<struct CSSToken<wchar_t>,struct GAllocatorGH<struct CSSToken<wchar_t>,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *this, a3: 48 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 12 * v5, a3: &newCapacity);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10084300
// Name: public: void GArrayDataBase<class GASValue,struct GAllocatorLH<class GASValue,323>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>::Reserve(
        IGameEventManager2 *this,
        IGameEvent *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  IGameEventManager2_vtbl *v5; // eax

  if ( newCapacity != 0 )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->__vftable != nullptr )
    {
      v5 = (IGameEventManager2_vtbl *)GMemory::pGlobalHeap->Realloc(
                                        this: GMemory::pGlobalHeap,
                                        a2: this->__vftable,
                                        a3: (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 323;
      v5 = (IGameEventManager2_vtbl *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                        this: GMemory::pGlobalHeap,
                                        a2: pheapAddr,
                                        a3: 16 * v4,
                                        a4: &newCapacity);
    }
    *((_DWORD *)this + 2) = v4;
    this->__vftable = v5;
  }
  else
  {
    if ( this->__vftable != nullptr )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->__vftable);
      this->__vftable = nullptr;
    }
    *((_DWORD *)this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084950
// Name: public: void GArrayDataBase<class GASValue,struct GAllocatorLH<class GASValue,323>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
        IGameEventManager2 *this,
        IGameEvent *pheapAddr,
        unsigned int newSize)
{
  unsigned int v5; // eax
  unsigned int v6; // eax
  GASValue *v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  v5 = *((_DWORD *)this + 1);
  if ( newSize >= v5 )
  {
    if ( newSize >= *((_DWORD *)this + 2) )
      GArrayDataBase<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = v5 - newSize;
    v7 = (GASValue *)((char *)this->__vftable + 16 * v6 + 16 * newSize - 16);
    if ( v6 != 0 )
    {
      for ( newSizea = v6; newSizea != 0; --newSizea )
      {
        GASValue::~GASValue(this: v7);
        v7 -= 4;
      }
    }
    if ( newSize < *((_DWORD *)this + 2) >> 1 )
    {
      GArrayDataBase<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize);
      *((_DWORD *)this + 1) = newSize;
      return;
    }
  }
  *((_DWORD *)this + 1) = newSize;
}

//------------------------------------------------------------------------------
// Address: 0x10085370
// Name: public: void GArrayDataBase<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::Reserve(
        CMatQueuedMesh *this,
        unsigned __int64 pheapAddr)
{
  int v3; // esi
  CMatQueuedMesh_vtbl *v4; // eax

  if ( HIDWORD(pheapAddr) != 0 )
  {
    v3 = 4 * ((unsigned int)(HIDWORD(pheapAddr) + 3) >> 2);
    if ( this->IMesh::IVertexBuffer::__vftable != nullptr )
    {
      v4 = (CMatQueuedMesh_vtbl *)GMemory::pGlobalHeap->Realloc(
                                    this: GMemory::pGlobalHeap,
                                    a2: this->IMesh::IVertexBuffer::__vftable,
                                    a3: 624 * ((unsigned int)(HIDWORD(pheapAddr) + 3) >> 2));
    }
    else
    {
      HIDWORD(pheapAddr) = 2;
      v4 = (CMatQueuedMesh_vtbl *)GMemory::pGlobalHeap->Alloc_2(
                                    this: GMemory::pGlobalHeap,
                                    a2: 156 * v3,
                                    a3: (char *)&pheapAddr + 4);
    }
    this->m_nMSTActualVertexOffsetInBytes = v3;
    this->IMesh::IVertexBuffer::__vftable = v4;
  }
  else
  {
    if ( this->IMesh::IVertexBuffer::__vftable != nullptr )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->IMesh::IVertexBuffer::__vftable);
      this->IMesh::IVertexBuffer::__vftable = nullptr;
    }
    this->m_nMSTActualVertexOffsetInBytes = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C080
// Name: public: void GArrayDataBase<unsigned __int64,struct GAllocatorLH<unsigned __int64,2>,struct GArrayConstPolicy<0,4,1>>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayConstPolicy<0,4,1>>::Reserve(
        void **this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  void *result; // eax
  unsigned int v5; // esi

  result = (void *)newCapacity;
  if ( newCapacity >= (unsigned int)*(this + 2) )
  {
    if ( newCapacity != 0 )
    {
      v5 = 4 * ((newCapacity + 3) >> 2);
      if ( *this != nullptr )
      {
        result = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *this, a3: 32 * ((newCapacity + 3) >> 2));
      }
      else
      {
        newCapacity = 2;
        result = GMemory::pGlobalHeap->AllocAutoHeap_2(
                   this: GMemory::pGlobalHeap,
                   a2: pheapAddr,
                   a3: 8 * v5,
                   a4: &newCapacity);
      }
      *(this + 2) = (void *)v5;
      *this = result;
    }
    else
    {
      result = *this;
      if ( *this != nullptr )
      {
        result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                           a1: GMemory::pGlobalHeap,
                           a2: *this);
        *this = nullptr;
      }
      *(this + 2) = nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008C2E0
// Name: public: void GArrayDataBase<class GPtr<struct GFxMovieStats::MarkerInfo>,struct GAllocatorLH<class GPtr<struct GFxMovieStats::MarkerInfo>,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CSchemaClassBinding<CResourceEnumIntrospection> *__thiscall GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        GRenderer::CachedData *this,
        const CSchemaClassBinding<CResourceEnumIntrospection> *result,
        unsigned int newSize)
{
  const CSchemaClassBinding<CResourceEnumIntrospection> *hData; // eax
  char *v6; // eax
  IShaderAPI **v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  hData = (const CSchemaClassBinding<CResourceEnumIntrospection> *)this->hData;
  if ( newSize >= (unsigned int)hData )
  {
    if ( newSize >= *((_DWORD *)this + 2) )
      hData = (const CSchemaClassBinding<CResourceEnumIntrospection> *)GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
                                                                         this,
                                                                         pheapAddr: (unsigned int)result);
  }
  else
  {
    v6 = (char *)hData - newSize;
    v7 = (IShaderAPI **)((char *)this->pRenderer + 4 * (_DWORD)&v6[newSize] - 4);
    if ( v6 != nullptr )
    {
      for ( newSizea = (unsigned int)v6; newSizea != 0; --newSizea )
      {
        if ( *v7 != nullptr )
          GRefCountImpl::Release(this: *v7);
        --v7;
      }
    }
    hData = (const CSchemaClassBinding<CResourceEnumIntrospection> *)(*((_DWORD *)this + 2) >> 1);
    if ( newSize < (unsigned int)hData )
    {
      hData = (const CSchemaClassBinding<CResourceEnumIntrospection> *)GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
                                                                         this,
                                                                         pheapAddr: (unsigned int)result);
      this->hData = (void *)newSize;
      return hData;
    }
  }
  this->hData = (void *)newSize;
  return hData;
}

//------------------------------------------------------------------------------
// Address: 0x1008E6A0
// Name: public: class GArrayLH<unsigned __int64,2,struct GArrayDefaultPolicy> __near & GFxAmpViewStats::LockBufferInstructionTimes(unsigned long,unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxAmpViewStats::LockBufferInstructionTimes(int this, unsigned int a2, int a3, unsigned int a4)
{
  unsigned __int64 *v5; // eax
  unsigned int *v6; // ecx
  GFxAmpViewStats::GFxAmpBufferInstructionTimes *v7; // eax
  IShaderAPI *v8; // eax
  unsigned __int64 *v10; // [esp+8h] [ebp-10h] BYREF
  unsigned int *v11; // [esp+Ch] [ebp-Ch]
  unsigned __int64 v12; // [esp+10h] [ebp-8h] BYREF

  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 40));
  v12 = (unsigned int)a3 + __PAIR64__(a2, 0);
  GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::FindAlt<unsigned __int64>(
    a1: &v10,
    a2: &v12);
  v5 = v10;
  if ( v10 == nullptr || *(_DWORD *)v10 == 0 || (v6 = v11, (int)v11 > *(_DWORD *)(*(_DWORD *)v10 + 4)) )
  {
    a2 = 2;
    v7 = (GFxAmpViewStats::GFxAmpBufferInstructionTimes *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                            this: GMemory::pGlobalHeap,
                                                            a2: this,
                                                            a3: 20,
                                                            a4: &a2);
    if ( v7 != nullptr )
      v8 = (IShaderAPI *)GFxAmpViewStats::GFxAmpBufferInstructionTimes::GFxAmpBufferInstructionTimes(this: v7, a2: a4);
    else
      v8 = nullptr;
    a2 = (unsigned int)v8;
    v10 = &v12;
    v11 = &a2;
    GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeRef>(
      a1: this + 28,
      a2: this + 28,
      a3: &v10);
    if ( a2 != 0 )
      GRefCountImpl::Release(this: (IShaderAPI *)a2);
    GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::FindAlt<unsigned __int64>(
      a1: &v10,
      a2: &v12);
    v5 = v10;
    v6 = v11;
  }
  return *(_DWORD *)(*(_DWORD *)v5 + 8 * (3 * (_DWORD)v6 + 3)) + 8;
}

//------------------------------------------------------------------------------
// Address: 0x10091250
// Name: public: void GArrayDataBase<class GPtr<class GASObject>,struct GAllocatorLH<class GPtr<class GASObject>,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GArrayDataBase<GPtr<GASObject>,GAllocatorLH<GPtr<GASObject>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        GRenderer::CachedData *this,
        ButtonCode_t pheapAddr,
        unsigned int newSize)
{
  char *result; // eax
  unsigned int v6; // eax
  GRenderer *v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  result = (char *)this->hData;
  if ( newSize >= (unsigned int)result )
  {
    if ( newSize >= *((_DWORD *)this + 2) )
      result = (char *)GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
                         this,
                         pheapAddr);
  }
  else
  {
    v6 = (unsigned int)&result[-newSize];
    v7 = (GRenderer *)((char *)this->pRenderer + 4 * v6 + 4 * newSize - 4);
    if ( v6 != 0 )
    {
      for ( newSizea = v6; newSizea != 0; --newSizea )
      {
        if ( v7->__vftable != nullptr )
          GRefCountBaseGC<323>::Release();
        v7 = (GRenderer *)((char *)v7 - 4);
      }
    }
    result = (char *)(*((_DWORD *)this + 2) >> 1);
    if ( newSize < (unsigned int)result )
    {
      result = (char *)GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
                         this,
                         pheapAddr);
      this->hData = (void *)newSize;
      return result;
    }
  }
  this->hData = (void *)newSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10094910
// Name: public: void GArrayDataBase<class GASString,struct GAllocatorLH<class GASString,323>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>::Reserve(
        GStatBag *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  unsigned __int8 *v5; // eax

  if ( newCapacity != 0 )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->pMem != nullptr )
    {
      v5 = (unsigned __int8 *)GMemory::pGlobalHeap->Realloc(
                                this: GMemory::pGlobalHeap,
                                a2: this->pMem,
                                a3: 16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 323;
      v5 = (unsigned __int8 *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                this: GMemory::pGlobalHeap,
                                a2: pheapAddr,
                                a3: 4 * v4,
                                a4: &newCapacity);
    }
    this->MemAllocOffset = v4;
    this->pMem = v5;
  }
  else
  {
    if ( this->pMem != nullptr )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->pMem);
      this->pMem = nullptr;
    }
    this->MemAllocOffset = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100949A0
// Name: public: void GArrayDataBase<struct GFxFontData::AdvanceEntry,struct GAllocatorLH<struct GFxFontData::AdvanceEntry,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  wchar_t *result; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( *this != nullptr )
    {
      result = (wchar_t *)GMemory::pGlobalHeap->Realloc(
                            this: GMemory::pGlobalHeap,
                            a2: *this,
                            a3: 48 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      result = (wchar_t *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                            this: GMemory::pGlobalHeap,
                            a2: pheapAddr,
                            a3: 12 * v5,
                            a4: &newCapacity);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = (wchar_t *)*this;
    if ( *this != nullptr )
    {
      result = (wchar_t *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                            a1: GMemory::pGlobalHeap,
                            a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10094A30
// Name: public: void GArrayDataBase<struct GASAsFunctionObject::ArgSpec,struct GAllocatorLH<struct GASAsFunctionObject::ArgSpec,323>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::Reserve(
        AvatarImageLoaded_t *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  int v4; // esi
  void *v5; // eax

  if ( newCapacity != 0 )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->m_steamID.m_steamid.m_comp != 0 )
    {
      v5 = GMemory::pGlobalHeap->Realloc(
             this: GMemory::pGlobalHeap,
             a2: *(_DWORD *)&this->m_steamID.m_steamid.m_comp,
             a3: 32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 323;
      v5 = GMemory::pGlobalHeap->AllocAutoHeap_2(
             this: GMemory::pGlobalHeap,
             a2: pheapAddr,
             a3: 8 * v4,
             a4: &newCapacity);
    }
    this->m_iImage = v4;
    *(_DWORD *)&this->m_steamID.m_steamid.m_comp = v5;
  }
  else
  {
    if ( this->m_steamID.m_steamid.m_comp != 0 )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)&this->m_steamID.m_steamid.m_comp);
      *(_DWORD *)&this->m_steamID.m_steamid.m_comp = 0;
    }
    this->m_iImage = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094AC0
// Name: public: void GArrayDataBase<class GASExecuteTag __near *,struct GAllocatorGH<class GASExecuteTag __near *,2>,struct GArrayConstPolicy<32,16,0>>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
D3DXVECTOR4 *__thiscall GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        int this,
        D3DXVECTOR4 *result,
        unsigned int newCapacity)
{
  unsigned int v3; // eax
  unsigned int v5; // esi
  D3DXVECTOR4 *v6; // eax

  v3 = newCapacity;
  if ( newCapacity < 0x20 )
    v3 = 32;
  v5 = (v3 + 15) & 0xFFFFFFF0;
  if ( *(_DWORD *)this != 0 )
  {
    v6 = (D3DXVECTOR4 *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *(_DWORD *)this, a3: 4 * v5);
  }
  else
  {
    newCapacity = 2;
    v6 = (D3DXVECTOR4 *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * v5, a3: &newCapacity);
  }
  *(_DWORD *)(this + 8) = v5;
  *(_DWORD *)this = v6;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10095450
// Name: public: void GArrayDataBase<class GASString,struct GAllocatorLH<class GASString,323>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
        GStatBag *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int MemSize; // eax
  unsigned int v6; // eax
  unsigned __int8 *v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  MemSize = this->MemSize;
  if ( newSize >= MemSize )
  {
    if ( newSize >= this->MemAllocOffset )
      GArrayDataBase<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = MemSize - newSize;
    v7 = &this->pMem[4 * v6 - 4 + 4 * newSize];
    if ( v6 != 0 )
    {
      for ( newSizea = v6; newSizea != 0; --newSizea )
      {
        if ( (*(_DWORD *)(*(_DWORD *)v7 + 8))-- == 1 )
          GASStringNode::ReleaseNode();
        v7 -= 4;
      }
    }
    if ( newSize < this->MemAllocOffset >> 1 )
    {
      GArrayDataBase<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize);
      this->MemSize = newSize;
      return;
    }
  }
  this->MemSize = newSize;
}

//------------------------------------------------------------------------------
// Address: 0x100954D0
// Name: public: void GArrayDataBase<class GASValue,struct GAllocatorLH<class GASValue,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        unsigned int *this,
        ButtonCode_t pheapAddr,
        unsigned int newSize)
{
  unsigned int result; // eax
  unsigned int v6; // eax
  GASValue *v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  result = *(this + 1);
  if ( newSize >= result )
  {
    if ( newSize >= *(this + 2) )
      result = GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
                 pheapAddr,
                 newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = result - newSize;
    v7 = (GASValue *)(*this + 16 * (v6 + newSize) - 16);
    if ( v6 != 0 )
    {
      for ( newSizea = v6; newSizea != 0; --newSizea )
      {
        GASValue::~GASValue(this: v7);
        v7 -= 4;
      }
    }
    result = *(this + 2) >> 1;
    if ( newSize < result )
    {
      result = GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
                 pheapAddr,
                 newCapacity: newSize);
      *(this + 1) = newSize;
      return result;
    }
  }
  *(this + 1) = newSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10095550
// Name: public: void GArrayDataBase<struct GASAsFunctionObject::ArgSpec,struct GAllocatorLH<struct GASAsFunctionObject::ArgSpec,323>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
        AvatarImageLoaded_t *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int m_unAll64Bits_high; // eax
  unsigned int v6; // eax
  int v7; // edi
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  m_unAll64Bits_high = HIDWORD(this->m_steamID.m_steamid.m_unAll64Bits);
  if ( newSize >= m_unAll64Bits_high )
  {
    if ( newSize >= this->m_iImage )
      GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = m_unAll64Bits_high - newSize;
    v7 = *(_DWORD *)&this->m_steamID.m_steamid.m_comp + 8 * (v6 + newSize) - 4;
    if ( v6 != 0 )
    {
      for ( newSizea = v6; newSizea != 0; --newSizea )
      {
        if ( (*(_DWORD *)(*(_DWORD *)v7 + 8))-- == 1 )
          GASStringNode::ReleaseNode();
        v7 -= 8;
      }
    }
    if ( newSize < (unsigned int)this->m_iImage >> 1 )
    {
      GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize);
      *((_DWORD *)&this->m_steamID.m_steamid.m_comp + 1) = newSize;
      return;
    }
  }
  *((_DWORD *)&this->m_steamID.m_steamid.m_comp + 1) = newSize;
}

//------------------------------------------------------------------------------
// Address: 0x100A8B60
// Name: public: void GArrayDataBase<class GASArraySortFunctor,struct GAllocatorGH<class GASArraySortFunctor,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IGameEventListener_vtbl *__thiscall GArrayDataBase<GASArraySortFunctor,GAllocatorGH<GASArraySortFunctor,2>,GArrayDefaultPolicy>::Reserve(
        IGameEventListener *this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  IGameEventListener_vtbl *result; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( this->__vftable != nullptr )
    {
      result = (IGameEventListener_vtbl *)GMemory::pGlobalHeap->Realloc(
                                            this: GMemory::pGlobalHeap,
                                            a2: this->__vftable,
                                            a3: 112 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      result = (IGameEventListener_vtbl *)GMemory::pGlobalHeap->Alloc_2(
                                            this: GMemory::pGlobalHeap,
                                            a2: 28 * v5,
                                            a3: &newCapacity);
    }
    *((_DWORD *)this + 2) = v5;
    this->__vftable = result;
  }
  else
  {
    result = this->__vftable;
    if ( this->__vftable != nullptr )
    {
      result = (IGameEventListener_vtbl *)((int (__thiscall *)(GMemoryHeap *, IGameEventListener_vtbl *))GMemory::pGlobalHeap->Free)(
                                            a1: GMemory::pGlobalHeap,
                                            a2: this->__vftable);
      this->__vftable = nullptr;
    }
    *((_DWORD *)this + 2) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8F70
// Name: public: void GArrayDataBase<class GASArraySortFunctor,struct GAllocatorGH<class GASArraySortFunctor,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IGameEventListener_vtbl *__thiscall GArrayDataBase<GASArraySortFunctor,GAllocatorGH<GASArraySortFunctor,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        IGameEventListener *this,
        ButtonCode_t pheapAddr,
        unsigned int newSize)
{
  IGameEventListener_vtbl *result; // eax

  result = *((IGameEventListener_vtbl **)this + 1);
  if ( newSize >= (unsigned int)result )
  {
    if ( newSize >= *((_DWORD *)this + 2) )
      result = GArrayDataBase<GASArraySortFunctor,GAllocatorGH<GASArraySortFunctor,2>,GArrayDefaultPolicy>::Reserve(
                 this,
                 pheapAddr,
                 newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    GConstructorMov<GASArraySortFunctor>::DestructArray(
      a1: (char *)this->__vftable + 28 * newSize,
      a2: (char *)result - newSize);
    result = (IGameEventListener_vtbl *)(*((_DWORD *)this + 2) >> 1);
    if ( newSize < (unsigned int)result )
    {
      result = GArrayDataBase<GASArraySortFunctor,GAllocatorGH<GASArraySortFunctor,2>,GArrayDefaultPolicy>::Reserve(
                 this,
                 pheapAddr,
                 newCapacity: newSize);
      *((_DWORD *)this + 1) = newSize;
      return result;
    }
  }
  *((_DWORD *)this + 1) = newSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AB970
// Name: public: GArrayDataBase<struct GASAsFunctionObject::ArgSpec,struct GAllocatorLH<struct GASAsFunctionObject::ArgSpec,323>,struct GArrayDefaultPolicy>::~GArrayDataBase<struct GASAsFunctionObject::ArgSpec,struct GAllocatorLH<struct GASAsFunctionObject::ArgSpec,323>,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::~GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>(
        _DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // esi
  int i; // edi

  v2 = *(this + 1);
  v3 = *this + 8 * v2 - 8;
  if ( v2 != 0 )
  {
    v4 = v3 + 4;
    for ( i = v2; i != 0; --i )
    {
      if ( (*(_DWORD *)(*(_DWORD *)v4 + 8))-- == 1 )
        GASStringNode::ReleaseNode();
      v4 -= 8;
    }
  }
  return ((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: *this);
}

//------------------------------------------------------------------------------
// Address: 0x100AFE60
// Name: public: void GArrayDataBase<struct GFxTimelineDef::Frame,struct GAllocatorLH<struct GFxTimelineDef::Frame,265>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
INetChannel_vtbl *__thiscall GArrayDataBase<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,265>,GArrayDefaultPolicy>::Reserve(
        INetChannel *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  INetChannel_vtbl *result; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( this->__vftable != nullptr )
    {
      result = (INetChannel_vtbl *)GMemory::pGlobalHeap->Realloc(
                                     this: GMemory::pGlobalHeap,
                                     a2: this->__vftable,
                                     a3: 32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 265;
      result = (INetChannel_vtbl *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                     this: GMemory::pGlobalHeap,
                                     a2: pheapAddr,
                                     a3: 8 * v5,
                                     a4: &newCapacity);
    }
    *((_DWORD *)this + 2) = v5;
    this->__vftable = result;
  }
  else
  {
    result = this->__vftable;
    if ( this->__vftable != nullptr )
    {
      result = (INetChannel_vtbl *)((int (__thiscall *)(GMemoryHeap *, INetChannel_vtbl *))GMemory::pGlobalHeap->Free)(
                                     a1: GMemory::pGlobalHeap,
                                     a2: this->__vftable);
      this->__vftable = nullptr;
    }
    *((_DWORD *)this + 2) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AFEF0
// Name: public: void GArrayDataBase<struct GFxTextKeyMap::KeyMapEntry,struct GAllocatorGH<struct GFxTextKeyMap::KeyMapEntry,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystem_vtbl *__thiscall GArrayDataBase<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy>::Reserve(
        IMaterialSystem *this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  IMaterialSystem_vtbl *result; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( this->__vftable != nullptr )
    {
      result = (IMaterialSystem_vtbl *)GMemory::pGlobalHeap->Realloc(
                                         this: GMemory::pGlobalHeap,
                                         a2: this->__vftable,
                                         a3: (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 2;
      result = (IMaterialSystem_vtbl *)GMemory::pGlobalHeap->Alloc_2(
                                         this: GMemory::pGlobalHeap,
                                         a2: 16 * v5,
                                         a3: &newCapacity);
    }
    *((_DWORD *)this + 2) = v5;
    this->__vftable = result;
  }
  else
  {
    result = this->__vftable;
    if ( this->__vftable != nullptr )
    {
      result = (IMaterialSystem_vtbl *)((int (__thiscall *)(GMemoryHeap *, IMaterialSystem_vtbl *))GMemory::pGlobalHeap->Free)(
                                         a1: GMemory::pGlobalHeap,
                                         a2: this->__vftable);
      this->__vftable = nullptr;
    }
    *((_DWORD *)this + 2) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AFF80
// Name: public: void GArrayDataBase<class GPtr<class GFxASCharacter>,struct GAllocatorDH<class GPtr<class GFxASCharacter>,326>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const GStatInfo *__thiscall GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
        GStatBag::Iterator *this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  const GStatInfo *result; // eax
  GStatBag *v5; // esi
  int (__thiscall *v6)(ButtonCode_t, int, unsigned int *); // edx

  if ( newCapacity != 0 )
  {
    v5 = (GStatBag *)(4 * ((newCapacity + 3) >> 2));
    if ( this->Id != 0 )
    {
      result = (const GStatInfo *)GMemory::pGlobalHeap->Realloc(
                                    this: GMemory::pGlobalHeap,
                                    a2: this->Id,
                                    a3: 16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      v6 = *(int (__thiscall **)(ButtonCode_t, int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 326;
      result = (const GStatInfo *)v6(a1: pheapAddr, a2: 4 * (_DWORD)v5, a3: &newCapacity);
    }
    this->pBag = v5;
    this->Id = (unsigned int)result;
  }
  else
  {
    result = (const GStatInfo *)this->Id;
    if ( this->Id != 0 )
    {
      result = (const GStatInfo *)((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
                                    a1: GMemory::pGlobalHeap,
                                    a2: this->Id);
      this->Id = 0;
    }
    this->pBag = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B0010
// Name: public: void GArrayDataBase<class GFxCharacter __near *,struct GAllocatorDH<class GFxCharacter __near *,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxCharacter *,GAllocatorDH<GFxCharacter *,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        int a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi
  int (__thiscall *v6)(int, unsigned int, int *); // edx

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 16 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      v6 = *(int (__thiscall **)(int, unsigned int, int *))(*(_DWORD *)a2 + 40);
      a3 = 2;
      result = (void *)v6(a1: a2, a2: 4 * v5, &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2900
// Name: public: void GArrayDataBase<class GFxDisplayList::DisplayEntry,struct GAllocatorLH<class GFxDisplayList::DisplayEntry,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        CMatNullRenderContext *this@<ecx>,
        IMorph *pheapAddr,
        unsigned int newSize,
        const MorphWeight_t *a4)
{
  CRefCountServiceBase<1,CRefMT>_vtbl *v6; // eax
  unsigned int v7; // eax
  GRefCountNTSImpl **v8; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  v6 = this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
  if ( newSize >= (unsigned int)v6 )
  {
    if ( newSize >= this->m_iRefs )
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        (GRenderer::CachedData *)this,
        (unsigned int)pheapAddr);
  }
  else
  {
    v7 = (unsigned int)v6 - newSize;
    v8 = (GRefCountNTSImpl **)((char *)this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
                             + 4 * v7
                             + 4 * newSize
                             - 4);
    if ( v7 != 0 )
    {
      for ( newSizea = v7; newSizea != 0; --newSizea )
      {
        if ( *v8 != nullptr )
          GRefCountNTSImpl::Release(this: *v8);
        --v8;
      }
    }
    if ( newSize < (unsigned int)this->m_iRefs >> 1 )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        (GRenderer::CachedData *)this,
        (unsigned int)pheapAddr);
      this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)newSize;
      return;
    }
  }
  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)newSize;
}

//------------------------------------------------------------------------------
// Address: 0x100B2980
// Name: public: void GArrayDataBase<class GASValue,struct GAllocatorGH<class GASValue,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystem_vtbl *__thiscall GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        GPtr<IDirect3DPixelShader9> *this,
        ButtonCode_t pheapAddr,
        unsigned int newSize)
{
  IMaterialSystem_vtbl *result; // eax
  char *v6; // eax
  GASValue *v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  result = *((IMaterialSystem_vtbl **)this + 1);
  if ( newSize >= (unsigned int)result )
  {
    if ( newSize >= *((_DWORD *)this + 2) )
      result = GArrayDataBase<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy>::Reserve(
                 (IMaterialSystem *)this,
                 pheapAddr,
                 newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = (char *)result - newSize;
    v7 = (GASValue *)&this->pObject[4 * (_DWORD)&v6[newSize] - 4];
    if ( v6 != nullptr )
    {
      for ( newSizea = (unsigned int)v6; newSizea != 0; --newSizea )
      {
        GASValue::~GASValue(this: v7);
        v7 -= 4;
      }
    }
    result = (IMaterialSystem_vtbl *)(*((_DWORD *)this + 2) >> 1);
    if ( newSize < (unsigned int)result )
    {
      result = GArrayDataBase<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy>::Reserve(
                 (IMaterialSystem *)this,
                 pheapAddr,
                 newCapacity: newSize);
      *((_DWORD *)this + 1) = newSize;
      return result;
    }
  }
  *((_DWORD *)this + 1) = newSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2A00
// Name: public: void GArrayDataBase<class GPtr<class GFxASCharacter>,struct GAllocatorDH<class GPtr<class GFxASCharacter>,326>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const GStatInfo *__thiscall GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
        GStatBag::Iterator *this,
        ButtonCode_t pheapAddr,
        unsigned int newSize)
{
  const GStatInfo *result; // eax
  char *v6; // eax
  GRefCountNTSImpl **v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  result = (const GStatInfo *)this->GroupId;
  if ( newSize >= (unsigned int)result )
  {
    if ( (GStatBag *)newSize >= this->pBag )
      result = GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
                 this,
                 pheapAddr,
                 newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = (char *)result - newSize;
    v7 = (GRefCountNTSImpl **)(this->Id + 4 * (_DWORD)&v6[newSize] - 4);
    if ( v6 != nullptr )
    {
      for ( newSizea = (unsigned int)v6; newSizea != 0; --newSizea )
      {
        if ( *v7 != nullptr )
          GRefCountNTSImpl::Release(this: *v7);
        --v7;
      }
    }
    result = (const GStatInfo *)((unsigned int)this->pBag >> 1);
    if ( newSize < (unsigned int)result )
    {
      result = GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
                 this,
                 pheapAddr,
                 newCapacity: newSize);
      this->GroupId = newSize;
      return result;
    }
  }
  this->GroupId = newSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2A80
// Name: public: void GArrayDataBase<class GPtr<struct GFxSprite::ActiveSoundItem>,struct GAllocatorGH<class GPtr<struct GFxSprite::ActiveSoundItem>,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GArrayDataBase<GPtr<GFxSprite::ActiveSoundItem>,GAllocatorGH<GPtr<GFxSprite::ActiveSoundItem>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        CVertexBuilder *this,
        ButtonCode_t a2,
        unsigned int a3)
{
  char *result; // eax
  char *v6; // eax
  GRefCountNTSImpl **v7; // ebx
  int i; // [esp+14h] [ebp+Ch]

  result = (char *)this->m_VertexSize_BoneWeight;
  if ( a3 >= (unsigned int)result )
  {
    if ( a3 >= this->m_VertexSize_BoneMatrixIndex )
      result = (char *)GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                         this,
                         pheapAddr: a2,
                         newCapacity: a3 + (a3 >> 2));
  }
  else
  {
    v6 = &result[-a3];
    v7 = (GRefCountNTSImpl **)(this->m_VertexSize_Position + 4 * (_DWORD)&v6[a3] - 4);
    if ( v6 != nullptr )
    {
      for ( i = (int)v6; i != 0; --i )
      {
        if ( *v7 != nullptr )
          GRefCountNTSImpl::Release(this: *v7);
        --v7;
      }
    }
    result = (char *)((unsigned int)this->m_VertexSize_BoneMatrixIndex >> 1);
    if ( a3 < (unsigned int)result )
    {
      result = (char *)GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                         this,
                         pheapAddr: a2,
                         newCapacity: a3);
      this->m_VertexSize_BoneWeight = a3;
      return result;
    }
  }
  this->m_VertexSize_BoneWeight = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BECC0
// Name: public: void GArrayDataBase<class GPtr<class GFxASCharacter>,struct GAllocatorLH<class GPtr<class GFxASCharacter>,326>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorLH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
        ScaleformUIImpl *this@<ecx>,
        const void *pheapAddr,
        unsigned int newCapacity,
        int a4,
        int a5)
{
  GFxLoader *v6; // esi
  ScaleformUIImpl_vtbl *v7; // eax

  if ( newCapacity != 0 )
  {
    v6 = (GFxLoader *)(4 * ((newCapacity + 3) >> 2));
    if ( this->__vftable != nullptr )
    {
      v7 = (ScaleformUIImpl_vtbl *)GMemory::pGlobalHeap->Realloc(
                                     this: GMemory::pGlobalHeap,
                                     a2: this->__vftable,
                                     a3: 16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 326;
      v7 = (ScaleformUIImpl_vtbl *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                     this: GMemory::pGlobalHeap,
                                     a2: pheapAddr,
                                     a3: 4 * (_DWORD)v6,
                                     a4: &newCapacity);
    }
    this->m_pLoader = v6;
    this->__vftable = v7;
  }
  else
  {
    if ( this->__vftable != nullptr )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->__vftable);
      this->__vftable = nullptr;
    }
    this->m_pLoader = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BED50
// Name: public: void GArrayDataBase<class GFxSwfEvent __near *,struct GAllocatorLH<class GFxSwfEvent __near *,260>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxSwfEvent *,GAllocatorLH<GFxSwfEvent *,260>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 16 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 260;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 4 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C08B0
// Name: public: void GArrayDataBase<class GPtr<class GFxSprite>,struct GAllocatorLH<class GPtr<class GFxSprite>,326>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayDataBase<GPtr<GFxSprite>,GAllocatorLH<GPtr<GFxSprite>,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
        ScaleformUIImpl *this@<ecx>,
        const void *pheapAddr,
        unsigned int newSize,
        int a4,
        int a5)
{
  GFxSystem *m_pSystem; // eax
  unsigned int v8; // eax
  GRefCountNTSImpl **v9; // ebx
  int v10; // [esp+0h] [ebp-8h]
  int v11; // [esp+4h] [ebp-4h]
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  m_pSystem = this->m_pSystem;
  if ( newSize >= (unsigned int)m_pSystem )
  {
    if ( (GFxLoader *)newSize >= this->m_pLoader )
      GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorLH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize + (newSize >> 2),
        a4: v10,
        a5: v11);
  }
  else
  {
    v8 = (unsigned int)&m_pSystem[-newSize];
    v9 = (GRefCountNTSImpl **)((char *)this->__vftable + 4 * v8 + 4 * newSize - 4);
    if ( v8 != 0 )
    {
      for ( newSizea = v8; newSizea != 0; --newSizea )
      {
        if ( *v9 != nullptr )
          GRefCountNTSImpl::Release(this: *v9);
        --v9;
      }
    }
    if ( newSize < (unsigned int)this->m_pLoader >> 1 )
    {
      GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorLH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize,
        a4: v10,
        a5: v11);
      this->m_pSystem = (GFxSystem *)newSize;
      return;
    }
  }
  this->m_pSystem = (GFxSystem *)newSize;
}

//------------------------------------------------------------------------------
// Address: 0x100C0950
// Name: public: void GArrayDataBase<struct GFxMovieRoot::LevelInfo,struct GAllocatorLH<struct GFxMovieRoot::LevelInfo,326>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxTestStream *__thiscall GArrayDataBase<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>::Reserve(
        void **this,
        GFxTestStream *result,
        unsigned int newCapacity)
{
  GFxTestStream *v4; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( *this != nullptr )
    {
      v4 = (GFxTestStream *)GMemory::pGlobalHeap->Realloc(
                              this: GMemory::pGlobalHeap,
                              a2: *this,
                              a3: 32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 326;
      v4 = (GFxTestStream *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                              this: GMemory::pGlobalHeap,
                              a2: result,
                              a3: 8 * v5,
                              a4: &newCapacity);
    }
    *(this + 2) = (void *)v5;
    *this = v4;
  }
  else
  {
    v4 = (GFxTestStream *)*this;
    if ( *this != nullptr )
    {
      v4 = (GFxTestStream *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                              a1: GMemory::pGlobalHeap,
                              a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100C0AC0
// Name: void G_QuickSortSliced<class GArrayDH<class GPtr<class GFxASCharacter>,326,struct GArrayDefaultPolicy>,class GASTabIndexSortFunctor>(class GArrayDH<class GPtr<class GFxASCharacter>,326,struct GArrayDefaultPolicy> __near &,unsigned int,unsigned int,class GASTabIndexSortFunctor)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl G_QuickSortSliced<GArrayDH<GPtr<GFxASCharacter>,326,GArrayDefaultPolicy>,GASTabIndexSortFunctor>(
        int *a1,
        int a2,
        _DWORD *a3)
{
  int v3; // ecx
  _DWORD *result; // eax
  int v5; // esi
  GRefCountNTSImpl **v6; // edi
  int v7; // eax
  GRefCountNTSImpl *v8; // ebx
  int v9; // esi
  int v10; // edi
  __int16 v11; // ax
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  GRefCountNTSImpl *v16; // edi
  int v17; // esi
  int v18; // eax
  int v19; // eax
  GRefCountNTSImpl *v20; // edi
  int v21; // esi
  int v22; // eax
  GRefCountNTSImpl *v23; // edi
  int v24; // edx
  int v25; // eax
  int v26; // ebx
  GRefCountNTSImpl *v27; // ecx
  GRefCountNTSImpl *v28; // ecx
  int v29; // ebx
  int v30; // edx
  int v31; // esi
  __int16 v32; // cx
  int v33; // eax
  int v34; // edi
  int v35; // eax
  int v36; // edi
  int v37; // eax
  int v38; // eax
  GRefCountNTSImpl *v39; // edi
  GRefCountNTSImpl *v40; // ecx
  GRefCountNTSImpl *v41; // ecx
  int v42; // esi
  int v43; // eax
  int v44; // eax
  GRefCountNTSImpl *v45; // edi
  GRefCountNTSImpl *v46; // ecx
  GRefCountNTSImpl *v47; // ecx
  _DWORD *v48; // eax
  int v49; // ebx
  int v50; // ecx
  GRefCountNTSImpl **v51; // esi
  GRefCountNTSImpl *v52; // eax
  GRefCountNTSImpl *v53; // edi
  GRefCountNTSImpl *v54; // ecx
  int v55; // edx
  _DWORD *v56; // [esp+0h] [ebp-15Ch]
  int v57; // [esp+4h] [ebp-158h]
  int v58; // [esp+Ch] [ebp-150h]
  int i; // [esp+Ch] [ebp-150h]
  int v60; // [esp+10h] [ebp-14Ch]
  int v61; // [esp+14h] [ebp-148h]
  _DWORD v62[80]; // [esp+18h] [ebp-144h] BYREF

  v3 = a2;
  result = a3;
  if ( (unsigned int)a3 - a2 >= 2 )
  {
    v56 = v62;
    v61 = a2;
    while ( 1 )
    {
      v57 = (int)result;
      while ( v57 - v3 > 9 )
      {
        v5 = *a1;
        v6 = (GRefCountNTSImpl **)(*a1 + 4 * (v3 + (v57 - v3) / 2));
        v7 = *(_DWORD *)(*a1 + 4 * v3);
        if ( v7 != 0 )
          ++*(_DWORD *)(v7 + 4);
        v8 = *(GRefCountNTSImpl **)(v5 + 4 * v3);
        if ( *v6 != nullptr )
          ++(*v6)->RefCount;
        if ( *(_DWORD *)(v5 + 4 * v3) != 0 )
        {
          GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)(v5 + 4 * v3));
          v3 = v61;
        }
        *(_DWORD *)(v5 + 4 * v3) = *v6;
        if ( v8 != nullptr )
          ++v8->RefCount;
        if ( *v6 != nullptr )
        {
          GRefCountNTSImpl::Release(this: *v6);
          v3 = v61;
        }
        *v6 = v8;
        if ( v8 != nullptr )
        {
          GRefCountNTSImpl::Release(this: v8);
          v3 = v61;
        }
        v9 = *a1;
        v10 = *(_DWORD *)(*a1 + 4 * v3 + 4);
        v11 = *(_WORD *)(*(_DWORD *)(*a1 + 4 * v57 - 4) + 164);
        v12 = v57 - 1;
        v13 = v3 + 1;
        v58 = v3 + 1;
        v60 = v57 - 1;
        if ( v11 < *(__int16 *)(v10 + 164) )
        {
          v14 = *(_DWORD *)(v9 + 4 * v12);
          if ( v14 != 0 )
            ++*(_DWORD *)(v14 + 4);
          v15 = *(_DWORD *)(v9 + 4 * v13);
          v16 = *(GRefCountNTSImpl **)(v9 + 4 * v12);
          if ( v15 != 0 )
            ++*(_DWORD *)(v15 + 4);
          if ( *(_DWORD *)(v9 + 4 * v12) != 0 )
          {
            GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)(v9 + 4 * v12));
            v3 = v61;
            v12 = v60;
          }
          *(_DWORD *)(v9 + 4 * v12) = *(_DWORD *)(v9 + 4 * v13);
          if ( v16 != nullptr )
            ++v16->RefCount;
          if ( *(_DWORD *)(v9 + 4 * v13) != 0 )
          {
            GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)(v9 + 4 * v13));
            v3 = v61;
            v12 = v60;
          }
          *(_DWORD *)(v9 + 4 * v13) = v16;
          if ( v16 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v16);
            v3 = v61;
            v12 = v60;
          }
        }
        v17 = *a1;
        if ( *(_WORD *)(*(_DWORD *)(*a1 + 4 * v3) + 164) < *(_WORD *)(*(_DWORD *)(*a1 + 4 * v13) + 164) )
        {
          v18 = *(_DWORD *)(v17 + 4 * v3);
          if ( v18 != 0 )
            ++*(_DWORD *)(v18 + 4);
          v19 = *(_DWORD *)(v17 + 4 * v13);
          v20 = *(GRefCountNTSImpl **)(v17 + 4 * v3);
          if ( v19 != 0 )
            ++*(_DWORD *)(v19 + 4);
          if ( *(_DWORD *)(v17 + 4 * v3) != 0 )
          {
            GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)(v17 + 4 * v3));
            v3 = v61;
            v12 = v60;
          }
          *(_DWORD *)(v17 + 4 * v3) = *(_DWORD *)(v17 + 4 * v13);
          if ( v20 != nullptr )
            ++v20->RefCount;
          if ( *(_DWORD *)(v17 + 4 * v13) != 0 )
          {
            GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)(v17 + 4 * v13));
            v3 = v61;
            v12 = v60;
          }
          *(_DWORD *)(v17 + 4 * v13) = v20;
          if ( v20 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v20);
            v3 = v61;
            v12 = v60;
          }
        }
        v21 = *a1;
        if ( *(_WORD *)(*(_DWORD *)(*a1 + 4 * v12) + 164) < *(_WORD *)(*(_DWORD *)(*a1 + 4 * v3) + 164) )
        {
          v22 = *(_DWORD *)(v21 + 4 * v12);
          if ( v22 != 0 )
            ++*(_DWORD *)(v22 + 4);
          v23 = *(GRefCountNTSImpl **)(v21 + 4 * v12);
          v24 = v61;
          v25 = *(_DWORD *)(v21 + 4 * v61);
          if ( v25 != 0 )
            ++*(_DWORD *)(v25 + 4);
          v26 = v60;
          v27 = *(GRefCountNTSImpl **)(v21 + 4 * v60);
          if ( v27 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v27);
            v24 = v61;
          }
          *(_DWORD *)(v21 + 4 * v26) = *(_DWORD *)(v21 + 4 * v24);
          if ( v23 != nullptr )
            ++v23->RefCount;
          v28 = *(GRefCountNTSImpl **)(v21 + 4 * v24);
          if ( v28 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v28);
            v24 = v61;
          }
          *(_DWORD *)(v21 + 4 * v24) = v23;
          if ( v23 != nullptr )
            GRefCountNTSImpl::Release(this: v23);
        }
        v29 = v61;
LABEL_57:
        v30 = v60;
        while ( 1 )
        {
          v31 = *a1;
          v32 = *(_WORD *)(*(_DWORD *)(*a1 + 4 * v29) + 164);
          v33 = *a1 + 4 * v58;
          do
          {
            v34 = *(_DWORD *)(v33 + 4);
            ++v58;
            v33 += 4;
          }
          while ( *(__int16 *)(v34 + 164) < v32 );
          v35 = v31 + 4 * v30;
          do
          {
            v36 = *(_DWORD *)(v35 - 4);
            v35 -= 4;
            --v30;
          }
          while ( v32 < *(__int16 *)(v36 + 164) );
          v60 = v30;
          if ( v58 > v30 )
            break;
          v37 = *(_DWORD *)(v31 + 4 * v58);
          if ( v37 != 0 )
            ++*(_DWORD *)(v37 + 4);
          v38 = *(_DWORD *)(v31 + 4 * v30);
          v39 = *(GRefCountNTSImpl **)(v31 + 4 * v58);
          if ( v38 != 0 )
            ++*(_DWORD *)(v38 + 4);
          v40 = *(GRefCountNTSImpl **)(v31 + 4 * v58);
          if ( v40 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v40);
            v30 = v60;
          }
          *(_DWORD *)(v31 + 4 * v58) = *(_DWORD *)(v31 + 4 * v30);
          if ( v39 != nullptr )
            ++v39->RefCount;
          v41 = *(GRefCountNTSImpl **)(v31 + 4 * v30);
          if ( v41 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v41);
            v30 = v60;
          }
          *(_DWORD *)(v31 + 4 * v30) = v39;
          if ( v39 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v39);
            goto LABEL_57;
          }
        }
        v42 = *a1;
        v43 = *(_DWORD *)(*a1 + 4 * v29);
        if ( v43 != 0 )
          ++*(_DWORD *)(v43 + 4);
        v44 = *(_DWORD *)(v42 + 4 * v30);
        v45 = *(GRefCountNTSImpl **)(v42 + 4 * v29);
        if ( v44 != 0 )
          ++*(_DWORD *)(v44 + 4);
        v46 = *(GRefCountNTSImpl **)(v42 + 4 * v29);
        if ( v46 != nullptr )
        {
          GRefCountNTSImpl::Release(this: v46);
          v30 = v60;
        }
        *(_DWORD *)(v42 + 4 * v29) = *(_DWORD *)(v42 + 4 * v30);
        if ( v45 != nullptr )
          ++v45->RefCount;
        v47 = *(GRefCountNTSImpl **)(v42 + 4 * v30);
        if ( v47 != nullptr )
        {
          GRefCountNTSImpl::Release(this: v47);
          v30 = v60;
        }
        *(_DWORD *)(v42 + 4 * v30) = v45;
        if ( v45 != nullptr )
        {
          GRefCountNTSImpl::Release(this: v45);
          v30 = v60;
        }
        if ( v30 - v29 <= v57 - v58 )
        {
          v56[1] = v57;
          v3 = v61;
          *v56 = v58;
          v48 = v56 + 2;
          v57 = v30;
        }
        else
        {
          v3 = v58;
          *v56 = v29;
          v56[1] = v30;
          v48 = v56 + 2;
          v61 = v58;
        }
        v56 = v48;
      }
      v49 = v3;
      v50 = v3 + 1;
      for ( i = v50; v50 < v57; i = v50 )
      {
        v51 = (GRefCountNTSImpl **)(*a1 + 4 * v49);
        if ( SLOWORD(v51[1][20].RefCount) < SLOWORD((*v51)[20].RefCount) )
        {
          do
          {
            v52 = v51[1];
            if ( v52 != nullptr )
              ++v52->RefCount;
            v53 = v51[1];
            if ( *v51 != nullptr )
              ++(*v51)->RefCount;
            v54 = v51[1];
            if ( v54 != nullptr )
              GRefCountNTSImpl::Release(this: v54);
            v51[1] = *v51;
            if ( v53 != nullptr )
              ++v53->RefCount;
            if ( *v51 != nullptr )
              GRefCountNTSImpl::Release(this: *v51);
            *v51 = v53;
            if ( v53 != nullptr )
              GRefCountNTSImpl::Release(this: v53);
            if ( v49 == v61 )
              break;
            --v49;
            v51 = (GRefCountNTSImpl **)(*a1 + 4 * v49);
          }
          while ( SLOWORD(v51[1][20].RefCount) < SLOWORD((*v51)[20].RefCount) );
          v50 = i;
        }
        v49 = v50++;
      }
      result = v56;
      if ( v56 <= v62 )
        break;
      v55 = *(v56 - 2);
      v56 -= 2;
      result = (_DWORD *)v56[1];
      v61 = v55;
      v3 = v55;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C0FE0
// Name: void G_QuickSortSliced<class GArrayDH<class GPtr<class GFxASCharacter>,326,struct GArrayDefaultPolicy>,class GASAutoTabSortFunctor>(class GArrayDH<class GPtr<class GFxASCharacter>,326,struct GArrayDefaultPolicy> __near &,unsigned int,unsigned int,class GASAutoTabSortFunctor)
// Source: json
//------------------------------------------------------------------------------
GRefCountNTSImpl **G_QuickSortSliced<GArrayDH<GPtr<GFxASCharacter>,326,GArrayDefaultPolicy>,GASAutoTabSortFunctor>(
        _DWORD *a1,
        GRefCountNTSImpl *a2,
        GRefCountNTSImpl **a3,
        ...)
{
  GRefCountNTSImpl **result; // eax
  GRefCountNTSImpl *v4; // ebx
  int v5; // esi
  GRefCountNTSImpl **v6; // edi
  int v7; // eax
  GRefCountNTSImpl *v8; // ecx
  GRefCountNTSImpl *v9; // eax
  GRefCountNTSImpl *v10; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // esi
  int v14; // eax
  GRefCountNTSImpl *v15; // edx
  int v16; // ecx
  GRefCountNTSImpl *v17; // eax
  GRefCountNTSImpl *v18; // ecx
  GRefCountNTSImpl *v19; // ecx
  int v20; // esi
  int v21; // eax
  GRefCountNTSImpl *v22; // edx
  int v23; // ecx
  GRefCountNTSImpl *v24; // eax
  GRefCountNTSImpl *v25; // ecx
  GRefCountNTSImpl *v26; // ecx
  int v27; // esi
  int v28; // eax
  int v29; // ecx
  GRefCountNTSImpl *v30; // eax
  GRefCountNTSImpl *v31; // ecx
  GRefCountNTSImpl *v32; // ecx
  _DWORD *v33; // esi
  int v34; // ecx
  int v35; // esi
  int v36; // eax
  int v37; // eax
  GRefCountNTSImpl *v38; // edx
  GRefCountNTSImpl *v39; // ebx
  GRefCountNTSImpl *v40; // ecx
  GRefCountNTSImpl *v41; // ecx
  int v42; // eax
  int v43; // ecx
  GRefCountNTSImpl *v44; // eax
  GRefCountNTSImpl *v45; // ecx
  GRefCountNTSImpl *v46; // ecx
  GRefCountNTSImpl *v47; // ecx
  GRefCountNTSImpl **v48; // eax
  int k; // esi
  GRefCountNTSImpl **v50; // esi
  GRefCountNTSImpl *v51; // eax
  GRefCountNTSImpl *v52; // edi
  GRefCountNTSImpl *v53; // ecx
  int v54; // [esp-10h] [ebp-170h]
  int v55; // [esp-Ch] [ebp-16Ch]
  GRefCountNTSImpl **i; // [esp+4h] [ebp-15Ch]
  int v57; // [esp+8h] [ebp-158h]
  GRefCountNTSImpl *v58; // [esp+Ch] [ebp-154h]
  GRefCountNTSImpl *v59; // [esp+Ch] [ebp-154h]
  GRefCountNTSImpl *v60; // [esp+10h] [ebp-150h]
  GRefCountNTSImpl *v61; // [esp+10h] [ebp-150h]
  GRefCountNTSImpl *v62; // [esp+10h] [ebp-150h]
  GRefCountNTSImpl *v63; // [esp+10h] [ebp-150h]
  _DWORD *v64; // [esp+14h] [ebp-14Ch]
  GRefCountNTSImpl *j; // [esp+18h] [ebp-148h]
  _BYTE v66[320]; // [esp+1Ch] [ebp-144h] BYREF
  va_list va; // [esp+174h] [ebp+14h] BYREF

  va_start(va, a3);
  v64 = a1;
  result = a3;
  v4 = a2;
  if ( (unsigned int)((char *)a3 - (char *)a2) >= 2 )
  {
    for ( i = (GRefCountNTSImpl **)v66; ; result = (GRefCountNTSImpl **)i[1] )
    {
      v57 = (int)result;
      v58 = v4;
      while ( v57 - (int)v4 > 9 )
      {
        v5 = *v64;
        v6 = (GRefCountNTSImpl **)(*v64 + 4 * ((_DWORD)v4 + (v57 - (int)v4) / 2));
        v7 = *(_DWORD *)(*v64 + 4 * (_DWORD)v4);
        if ( v7 != 0 )
          ++*(_DWORD *)(v7 + 4);
        v8 = *v6;
        v9 = *(GRefCountNTSImpl **)(v5 + 4 * (_DWORD)v4);
        j = v9;
        if ( v8 != nullptr )
          ++v8->RefCount;
        v10 = *(GRefCountNTSImpl **)(v5 + 4 * (_DWORD)v4);
        if ( v10 != nullptr )
        {
          GRefCountNTSImpl::Release(this: v10);
          v9 = j;
        }
        *(_DWORD *)(v5 + 4 * (_DWORD)v4) = *v6;
        if ( v9 != nullptr )
          ++v9->RefCount;
        if ( *v6 != nullptr )
        {
          GRefCountNTSImpl::Release(this: *v6);
          v9 = j;
        }
        *v6 = v9;
        if ( v9 != nullptr )
          GRefCountNTSImpl::Release(this: j);
        v11 = *v64;
        j = (GRefCountNTSImpl *)((char *)&v4->__vftable + 1);
        v12 = v57 - 1;
        if ( (unsigned __int8)GASAutoTabSortFunctor::operator()(
                                a1: va,
                                a2: *(_DWORD *)(v11 + 4 * v57 - 4),
                                a3: *(_DWORD *)(v11 + 4 * ((_DWORD)&v4->__vftable + 1))) != 0 )
        {
          v13 = *v64;
          v14 = *(_DWORD *)(*v64 + 4 * v12);
          if ( v14 != 0 )
            ++*(_DWORD *)(v14 + 4);
          v15 = j;
          v16 = *(_DWORD *)(v13 + 4 * (_DWORD)j);
          v17 = *(GRefCountNTSImpl **)(v13 + 4 * v12);
          v60 = v17;
          if ( v16 != 0 )
            ++*(_DWORD *)(v16 + 4);
          v18 = *(GRefCountNTSImpl **)(v13 + 4 * v12);
          if ( v18 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v18);
            v17 = v60;
            v15 = j;
          }
          *(_DWORD *)(v13 + 4 * v12) = *(_DWORD *)(v13 + 4 * (_DWORD)v15);
          if ( v17 != nullptr )
            ++v17->RefCount;
          v19 = *(GRefCountNTSImpl **)(v13 + 4 * (_DWORD)v15);
          if ( v19 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v19);
            v17 = v60;
            v15 = j;
          }
          *(_DWORD *)(v13 + 4 * (_DWORD)v15) = v17;
          if ( v17 != nullptr )
            GRefCountNTSImpl::Release(this: v60);
        }
        if ( (unsigned __int8)GASAutoTabSortFunctor::operator()(
                                a1: va,
                                a2: *(_DWORD *)(*v64 + 4 * (_DWORD)v4),
                                a3: *(_DWORD *)(*v64 + 4 * (_DWORD)j)) != 0 )
        {
          v20 = *v64;
          v21 = *(_DWORD *)(*v64 + 4 * (_DWORD)v4);
          if ( v21 != 0 )
            ++*(_DWORD *)(v21 + 4);
          v22 = j;
          v23 = *(_DWORD *)(v20 + 4 * (_DWORD)j);
          v24 = *(GRefCountNTSImpl **)(v20 + 4 * (_DWORD)v4);
          v61 = v24;
          if ( v23 != 0 )
            ++*(_DWORD *)(v23 + 4);
          v25 = *(GRefCountNTSImpl **)(v20 + 4 * (_DWORD)v4);
          if ( v25 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v25);
            v24 = v61;
            v22 = j;
          }
          *(_DWORD *)(v20 + 4 * (_DWORD)v4) = *(_DWORD *)(v20 + 4 * (_DWORD)v22);
          if ( v24 != nullptr )
            ++v24->RefCount;
          v26 = *(GRefCountNTSImpl **)(v20 + 4 * (_DWORD)v22);
          if ( v26 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v26);
            v24 = v61;
            v22 = j;
          }
          *(_DWORD *)(v20 + 4 * (_DWORD)v22) = v24;
          if ( v24 != nullptr )
            GRefCountNTSImpl::Release(this: v61);
        }
        if ( (unsigned __int8)GASAutoTabSortFunctor::operator()(
                                a1: va,
                                a2: *(_DWORD *)(*v64 + 4 * v12),
                                a3: *(_DWORD *)(*v64 + 4 * (_DWORD)v4)) != 0 )
        {
          v27 = *v64;
          v28 = *(_DWORD *)(*v64 + 4 * v12);
          if ( v28 != 0 )
            ++*(_DWORD *)(v28 + 4);
          v29 = *(_DWORD *)(v27 + 4 * (_DWORD)v4);
          v30 = *(GRefCountNTSImpl **)(v27 + 4 * v12);
          v62 = v30;
          if ( v29 != 0 )
            ++*(_DWORD *)(v29 + 4);
          v31 = *(GRefCountNTSImpl **)(v27 + 4 * v12);
          if ( v31 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v31);
            v30 = v62;
          }
          *(_DWORD *)(v27 + 4 * v12) = *(_DWORD *)(v27 + 4 * (_DWORD)v4);
          if ( v30 != nullptr )
            ++v30->RefCount;
          v32 = *(GRefCountNTSImpl **)(v27 + 4 * (_DWORD)v4);
          if ( v32 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v32);
            v30 = v62;
          }
          *(_DWORD *)(v27 + 4 * (_DWORD)v4) = v30;
          if ( v30 != nullptr )
            GRefCountNTSImpl::Release(this: v62);
        }
        while ( 1 )
        {
          v33 = v64;
          do
          {
            v55 = *(_DWORD *)(*v33 + 4 * (_DWORD)v4);
            v54 = *(_DWORD *)(*v33 + 4 * (_DWORD)j + 4);
            j = (GRefCountNTSImpl *)((char *)j + 1);
          }
          while ( (unsigned __int8)GASAutoTabSortFunctor::operator()(a1: va, a2: v54, a3: v55) != 0 );
          do
            v34 = *(_DWORD *)(*v33 + 4 * v12-- - 4);
          while ( (unsigned __int8)GASAutoTabSortFunctor::operator()(
                                     a1: va,
                                     a2: *(_DWORD *)(*v33 + 4 * (_DWORD)v4),
                                     a3: v34) != 0 );
          v35 = *v64;
          if ( (int)j > v12 )
            break;
          v36 = *(_DWORD *)(v35 + 4 * (_DWORD)j);
          if ( v36 != 0 )
            ++*(_DWORD *)(v36 + 4);
          v37 = *(_DWORD *)(v35 + 4 * v12);
          v38 = j;
          v39 = *(GRefCountNTSImpl **)(v35 + 4 * (_DWORD)j);
          if ( v37 != 0 )
            ++*(_DWORD *)(v37 + 4);
          v40 = *(GRefCountNTSImpl **)(v35 + 4 * (_DWORD)v38);
          if ( v40 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v40);
            v38 = j;
          }
          *(_DWORD *)(v35 + 4 * (_DWORD)v38) = *(_DWORD *)(v35 + 4 * v12);
          if ( v39 != nullptr )
            ++v39->RefCount;
          v41 = *(GRefCountNTSImpl **)(v35 + 4 * v12);
          if ( v41 != nullptr )
            GRefCountNTSImpl::Release(this: v41);
          *(_DWORD *)(v35 + 4 * v12) = v39;
          if ( v39 != nullptr )
            GRefCountNTSImpl::Release(this: v39);
          v4 = v58;
        }
        v42 = *(_DWORD *)(v35 + 4 * (_DWORD)v4);
        if ( v42 != 0 )
          ++*(_DWORD *)(v42 + 4);
        v43 = *(_DWORD *)(v35 + 4 * v12);
        v44 = *(GRefCountNTSImpl **)(v35 + 4 * (_DWORD)v4);
        v63 = v44;
        if ( v43 != 0 )
          ++*(_DWORD *)(v43 + 4);
        v45 = *(GRefCountNTSImpl **)(v35 + 4 * (_DWORD)v4);
        if ( v45 != nullptr )
        {
          GRefCountNTSImpl::Release(this: v45);
          v44 = v63;
        }
        *(_DWORD *)(v35 + 4 * (_DWORD)v4) = *(_DWORD *)(v35 + 4 * v12);
        if ( v44 != nullptr )
          ++v44->RefCount;
        v46 = *(GRefCountNTSImpl **)(v35 + 4 * v12);
        if ( v46 != nullptr )
        {
          GRefCountNTSImpl::Release(this: v46);
          v44 = v63;
        }
        *(_DWORD *)(v35 + 4 * v12) = v44;
        if ( v44 != nullptr )
          GRefCountNTSImpl::Release(this: v63);
        v47 = j;
        if ( v12 - (int)v4 <= v57 - (int)j )
        {
          *i = j;
          i[1] = (GRefCountNTSImpl *)v57;
          v48 = i + 2;
          v57 = v12;
        }
        else
        {
          *i = v4;
          i[1] = (GRefCountNTSImpl *)v12;
          v4 = v47;
          v48 = i + 2;
          v58 = v47;
        }
        i = v48;
      }
      v59 = v4;
      for ( j = (GRefCountNTSImpl *)((char *)&v4->__vftable + 1); (int)j < v57; j = (GRefCountNTSImpl *)((char *)j + 1) )
      {
        for ( k = 4 * (_DWORD)v59;
              (unsigned __int8)GASAutoTabSortFunctor::operator()(
                                 a1: va,
                                 a2: *(_DWORD *)(*v64 + k + 4),
                                 a3: *(_DWORD *)(*v64 + k)) != 0;
              v59 = (GRefCountNTSImpl *)((char *)v59 - 1) )
        {
          v50 = (GRefCountNTSImpl **)(*v64 + k);
          v51 = v50[1];
          if ( v51 != nullptr )
            ++v51->RefCount;
          v52 = v50[1];
          if ( *v50 != nullptr )
            ++(*v50)->RefCount;
          v53 = v50[1];
          if ( v53 != nullptr )
            GRefCountNTSImpl::Release(this: v53);
          v50[1] = *v50;
          if ( v52 != nullptr )
            ++v52->RefCount;
          if ( *v50 != nullptr )
            GRefCountNTSImpl::Release(this: *v50);
          *v50 = v52;
          if ( v52 != nullptr )
            GRefCountNTSImpl::Release(this: v52);
          if ( v59 == v4 )
            break;
          k = 4 * ((_DWORD)v59 - 1);
        }
        v59 = j;
      }
      result = i;
      if ( i <= (GRefCountNTSImpl **)v66 )
        break;
      v4 = *(i - 2);
      i -= 2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C3420
// Name: public: void GArrayDataBase<struct GFxMovieRoot::LevelInfo,struct GAllocatorLH<struct GFxMovieRoot::LevelInfo,326>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxTestStream *__thiscall GArrayDataBase<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
        int this,
        GFxTestStream *result,
        unsigned int newSize)
{
  GFxTestStream *v4; // eax
  char *v6; // eax
  GRefCountNTSImpl **v7; // edi
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  v4 = *(GFxTestStream **)(this + 4);
  if ( newSize >= (unsigned int)v4 )
  {
    if ( newSize >= *(_DWORD *)(this + 8) )
      v4 = GArrayDataBase<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>::Reserve(
             (void **)this,
             result,
             newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = (char *)v4 - newSize;
    v7 = (GRefCountNTSImpl **)(*(_DWORD *)this + 8 * (_DWORD)&v6[newSize] - 4);
    if ( v6 != nullptr )
    {
      for ( newSizea = (unsigned int)v6; newSizea != 0; --newSizea )
      {
        if ( *v7 != nullptr )
          GRefCountNTSImpl::Release(this: *v7);
        v7 -= 2;
      }
    }
    v4 = (GFxTestStream *)(*(_DWORD *)(this + 8) >> 1);
    if ( newSize < (unsigned int)v4 )
    {
      v4 = GArrayDataBase<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>::Reserve(
             (void **)this,
             result,
             newCapacity: newSize);
      *(_DWORD *)(this + 4) = newSize;
      return v4;
    }
  }
  *(_DWORD *)(this + 4) = newSize;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100C8680
// Name: public: virtual class GArrayLH<class GFxSwfEvent __near *,260,struct GArrayDefaultPolicy> __near * GFxPlaceObject2::UnpackEventHandlers(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxPlaceObject2::UnpackEventHandlers(
        CMemberFuncProxy4<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *,bool),int,enum MaterialIndexFormat_t,void *,bool,CFuncMemPolicyNone> *this)
{
  void *result; // eax
  int m_pfnProxied; // edx
  void (__thiscall *v4)(CMemberFuncProxy4<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *,bool),int,enum MaterialIndexFormat_t,void *,bool,CFuncMemPolicyNone> *, float *); // edx
  float v5; // esi
  const CMaterialDict::MissingMaterial_t *v6; // [esp+0h] [ebp-6Ch]
  float v7[24]; // [esp+8h] [ebp-64h] BYREF

  result = nullptr;
  if ( SBYTE4(this->m_pfnProxied) < 0 )
  {
    result = *(void **)((char *)&this->m_pfnProxied + 5);
    if ( result == nullptr )
    {
      memset(v7, 0, 12);
      GRenderer::Cxform::Cxform();
      GMatrix2D::SetIdentity(result: v6);
      m_pfnProxied = this->m_pfnProxied;
      v7[17] = 0.0;
      v4 = *(void (__thiscall **)(CMemberFuncProxy4<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *,bool),int,enum MaterialIndexFormat_t,void *,bool,CFuncMemPolicyNone> *, float *))(m_pfnProxied + 32);
      v7[20] = 0.0;
      LODWORD(v7[19]) = 0x40000;
      v7[18] = 0.0;
      v4(a1: this, a2: v7);
      v5 = v7[21];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)LODWORD(v7[0]));
      return (void *)LODWORD(v5);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D1E90
// Name: public: void GArrayDataBase<class GWaitable::HandlerStruct,struct GAllocatorGH<class GWaitable::HandlerStruct,2>,struct GArrayConstPolicy<0,16,1>>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GWaitable::HandlerStruct,GAllocatorGH<GWaitable::HandlerStruct,2>,GArrayConstPolicy<0,16,1>>::Reserve(
        CThreadFastMutex *this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  void *result; // eax
  unsigned int v5; // esi

  result = (void *)newCapacity;
  if ( newCapacity >= *((_DWORD *)this + 2) )
  {
    if ( newCapacity != 0 )
    {
      v5 = (newCapacity + 15) & 0xFFFFFFF0;
      if ( this->m_ownerID != 0 )
      {
        result = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: this->m_ownerID, a3: 8 * v5);
      }
      else
      {
        newCapacity = 2;
        result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 8 * v5, a3: &newCapacity);
      }
      *((_DWORD *)this + 2) = v5;
      this->m_ownerID = (volatile unsigned int)result;
    }
    else
    {
      result = (void *)this->m_ownerID;
      if ( this->m_ownerID != 0 )
      {
        result = (void *)((int (__thiscall *)(GMemoryHeap *, volatile unsigned int))GMemory::pGlobalHeap->Free)(
                           a1: GMemory::pGlobalHeap,
                           a2: this->m_ownerID);
        this->m_ownerID = 0;
      }
      *((_DWORD *)this + 2) = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D4B40
// Name: public: void GArrayDataBase<class GPtr<class GFxMovieDefImpl>,struct GAllocatorLH<class GPtr<class GFxMovieDefImpl>,265>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxLoader::LoaderConfig *__thiscall GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorLH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::Reserve(
        GFxLoader::LoaderConfig *this,
        const GFxLoader::LoaderConfig *pheapAddr,
        unsigned int newCapacity)
{
  GFxLoader::LoaderConfig *result; // eax
  GFxZlibSupportBase *v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = (GFxZlibSupportBase *)(4 * ((newCapacity + 3) >> 2));
    if ( this->DefLoadFlags != 0 )
    {
      result = (GFxLoader::LoaderConfig *)GMemory::pGlobalHeap->Realloc(
                                            this: GMemory::pGlobalHeap,
                                            a2: this->DefLoadFlags,
                                            a3: 16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 265;
      result = (GFxLoader::LoaderConfig *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                            this: GMemory::pGlobalHeap,
                                            a2: pheapAddr,
                                            a3: 4 * (_DWORD)v5,
                                            a4: &newCapacity);
    }
    this->pZLibSupport.pObject = v5;
    this->DefLoadFlags = (unsigned int)result;
  }
  else
  {
    result = (GFxLoader::LoaderConfig *)this->DefLoadFlags;
    if ( this->DefLoadFlags != 0 )
    {
      result = (GFxLoader::LoaderConfig *)((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
                                            a1: GMemory::pGlobalHeap,
                                            a2: this->DefLoadFlags);
      this->DefLoadFlags = 0;
    }
    this->pZLibSupport.pObject = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D54A0
// Name: public: void GArrayDataBase<class GPtr<class GFxMovieDefImpl>,struct GAllocatorLH<class GPtr<class GFxMovieDefImpl>,265>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxLoader::LoaderConfig *__userpurge GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorLH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::ResizeNoConstruct@<eax>(
        GFxLoader::LoaderConfig *this@<ecx>,
        VertexShaderHandle_t__ *a2@<ebx>,
        const GFxLoader::LoaderConfig *pheapAddr,
        unsigned int newSize)
{
  GFxLoader::LoaderConfig *result; // eax
  char *v7; // eax
  IShaderDevice **v8; // ebx
  VertexShaderHandle_t__ *v9; // [esp-4h] [ebp-Ch]
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  result = (GFxLoader::LoaderConfig *)this->pFileOpener.pObject;
  if ( newSize >= (unsigned int)result )
  {
    if ( (GFxZlibSupportBase *)newSize >= this->pZLibSupport.pObject )
      result = GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorLH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::Reserve(
                 this,
                 pheapAddr,
                 newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v7 = (char *)result - newSize;
    v9 = a2;
    v8 = (IShaderDevice **)(this->DefLoadFlags + 4 * (_DWORD)&v7[newSize] - 4);
    if ( v7 != nullptr )
    {
      for ( newSizea = (unsigned int)v7; newSizea != 0; --newSizea )
      {
        if ( *v8 != nullptr )
          GFxResource::Release(this: *v8, a2: v9);
        --v8;
      }
    }
    result = (GFxLoader::LoaderConfig *)((unsigned int)this->pZLibSupport.pObject >> 1);
    if ( newSize < (unsigned int)result )
    {
      result = GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorLH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::Reserve(
                 this,
                 pheapAddr,
                 newCapacity: newSize);
      this->pFileOpener.pObject = (GFxFileOpenerBase *)newSize;
      return result;
    }
  }
  this->pFileOpener.pObject = (GFxFileOpenerBase *)newSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D5520
// Name: public: void GArrayDataBase<class GPtr<class GFxMovieDefImpl>,struct GAllocatorGH<class GPtr<class GFxMovieDefImpl>,265>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::Reserve(
        void **this,
        int a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 16 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 265;
      result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * v5, &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D55B0
// Name: public: void GArrayDataBase<class GPtr<class GFxMovieDefImpl>,struct GAllocatorGH<class GPtr<class GFxMovieDefImpl>,265>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__userpurge GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::ResizeNoConstruct@<eax>(
        int a1@<ecx>,
        VertexShaderHandle_t__ *a2@<ebx>,
        int a3,
        unsigned int a4)
{
  char *result; // eax
  char *v7; // eax
  IShaderDevice **v8; // ebx
  VertexShaderHandle_t__ *v9; // [esp-4h] [ebp-Ch]
  char *i; // [esp+14h] [ebp+Ch]

  result = *(char **)(a1 + 4);
  if ( a4 >= (unsigned int)result )
  {
    if ( a4 >= *(_DWORD *)(a1 + 8) )
      result = (char *)GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::Reserve(
                         this: (void **)a1,
                         a2: a3,
                         a3: a4 + (a4 >> 2));
  }
  else
  {
    v7 = &result[-a4];
    v9 = a2;
    v8 = (IShaderDevice **)(*(_DWORD *)a1 + 4 * (_DWORD)&v7[a4] - 4);
    if ( v7 != nullptr )
    {
      for ( i = v7; i != nullptr; --i )
      {
        if ( *v8 != nullptr )
          GFxResource::Release(this: *v8, a2: v9);
        --v8;
      }
    }
    result = (char *)(*(_DWORD *)(a1 + 8) >> 1);
    if ( a4 < (unsigned int)result )
    {
      result = (char *)GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::Reserve(
                         this: (void **)a1,
                         a2: a3,
                         a3: a4);
      *(_DWORD *)(a1 + 4) = a4;
      return result;
    }
  }
  *(_DWORD *)(a1 + 4) = a4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DF450
// Name: public: void GArrayDataBase<class GFxTextureGlyph,struct GAllocatorLH<class GFxTextureGlyph,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GFxTextureGlyph,GAllocatorLH<GFxTextureGlyph,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        CMorph *this,
        const GRenderer::FillTexture *pheapAddr,
        unsigned int newSize)
{
  ITextureRegenerator_vtbl *v4; // eax
  unsigned int v6; // eax
  char *v7; // esi
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  v4 = this->ITextureRegenerator::__vftable;
  if ( newSize >= (unsigned int)v4 )
  {
    if ( (CVertexMorphDict::MorphVertexList_t *)newSize >= this->m_MorphDict.m_MorphLists.m_Memory.m_pMemory )
      GArrayDataBase<GFxTextHighlightDesc,GAllocatorLH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>::Reserve(
        (GRenderer::FillTexture *)this,
        pheapAddr);
  }
  else
  {
    v6 = (unsigned int)v4 - newSize;
    v7 = (char *)&this->IMorphInternal::IMorph::__vftable[-1] + 40 * v6 + 40 * newSize - 16;
    if ( v6 != 0 )
    {
      for ( newSizea = v6; newSizea != 0; --newSizea )
      {
        (**(void (__thiscall ***)(char *, _DWORD))v7)(a1: v7, a2: 0);
        v7 -= 40;
      }
    }
    if ( newSize < (unsigned int)this->m_MorphDict.m_MorphLists.m_Memory.m_pMemory >> 1 )
    {
      GArrayDataBase<GFxTextHighlightDesc,GAllocatorLH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>::Reserve(
        (GRenderer::FillTexture *)this,
        pheapAddr);
      this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)newSize;
      return;
    }
  }
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)newSize;
}

//------------------------------------------------------------------------------
// Address: 0x100E6CB0
// Name: public: GArrayDataBase<struct GFxTextDocView::ImageSubstitutor::Element,struct GAllocatorLH<struct GFxTextDocView::ImageSubstitutor::Element,2>,struct GArrayDefaultPolicy>::~GArrayDataBase<struct GFxTextDocView::ImageSubstitutor::Element,struct GAllocatorLH<struct GFxTextDocView::ImageSubstitutor::Element,2>,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayDataBase<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>::~GArrayDataBase<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>(
        _DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  GRefCountNTSImpl **v4; // esi
  int i; // edi

  v2 = *(this + 1);
  v3 = *this + 48 * v2 - 48;
  if ( v2 != 0 )
  {
    v4 = (GRefCountNTSImpl **)(v3 + 40);
    for ( i = v2; i != 0; --i )
    {
      if ( *v4 != nullptr )
        GRefCountNTSImpl::Release(this: *v4);
      v4 -= 12;
    }
  }
  return ((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: *this);
}

//------------------------------------------------------------------------------
// Address: 0x100E7B80
// Name: public: GArrayDataBase<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,struct GAllocatorGH<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,2>,struct GArrayDefaultPolicy>::~GArrayDataBase<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,struct GAllocatorGH<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,2>,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>::~GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>(
        _DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  GRefCountNTSImpl **v4; // esi
  int i; // edi

  v2 = *(this + 1);
  v3 = *this + 20 * v2 - 20;
  if ( v2 != 0 )
  {
    v4 = (GRefCountNTSImpl **)(v3 + 8);
    for ( i = v2; i != 0; --i )
    {
      if ( *v4 != nullptr )
        GRefCountNTSImpl::Release(this: *v4);
      v4 -= 5;
    }
  }
  return ((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: *this);
}

//------------------------------------------------------------------------------
// Address: 0x100F0DA0
// Name: public: void GArrayDataBase<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,struct GAllocatorGH<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        unsigned int *this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  unsigned int result; // eax
  unsigned int v6; // eax
  GRefCountNTSImpl **v7; // ebx
  unsigned int newCapacitya; // [esp+14h] [ebp+Ch]

  result = *(this + 1);
  if ( newCapacity >= result )
  {
    if ( newCapacity >= *(this + 2) )
      result = GArrayDataBase<GFxPathPacker::Edge,GAllocatorGH<GFxPathPacker::Edge,2>,GArrayDefaultPolicy>::Reserve(
                 pheapAddr,
                 newCapacity: newCapacity + (newCapacity >> 2));
  }
  else
  {
    v6 = result - newCapacity;
    v7 = (GRefCountNTSImpl **)(*this + 20 * (v6 + newCapacity) - 12);
    if ( v6 != 0 )
    {
      for ( newCapacitya = v6; newCapacitya != 0; --newCapacitya )
      {
        if ( *v7 != nullptr )
          GRefCountNTSImpl::Release(this: *v7);
        v7 -= 5;
      }
    }
    result = *(this + 2) >> 1;
    if ( newCapacity < result )
    {
      result = GArrayDataBase<GFxPathPacker::Edge,GAllocatorGH<GFxPathPacker::Edge,2>,GArrayDefaultPolicy>::Reserve(
                 pheapAddr,
                 newCapacity);
      *(this + 1) = newCapacity;
      return result;
    }
  }
  *(this + 1) = newCapacity;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F4B20
// Name: public: void GArrayDataBase<struct GFxBatchPackageData::GlyphVerifier,struct GAllocatorLH<struct GFxBatchPackageData::GlyphVerifier,194>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxBatchPackageData::GlyphVerifier,GAllocatorLH<GFxBatchPackageData::GlyphVerifier,194>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: (unsigned int)(a3 + 3) >> 2 << 7);
    }
    else
    {
      a3 = 194;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 32 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F57A0
// Name: public: void GArrayDataBase<struct GRenderer::BitmapDesc,struct GAllocatorLH<struct GRenderer::BitmapDesc,194>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GRenderer::BitmapDesc,GAllocatorLH<GRenderer::BitmapDesc,194>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 144 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 194;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 36 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FE0D0
// Name: public: void GArrayDataBase<unsigned char,struct GAllocatorLH<unsigned char,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
        ICvar *this@<ecx>,
        ConVar *pheapAddr,
        int newCapacity,
        float a4)
{
  unsigned int v5; // esi
  ICvar_vtbl *v6; // eax

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((unsigned int)(newCapacity + 3) >> 2);
    if ( this->__vftable != nullptr )
    {
      v6 = (ICvar_vtbl *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: this->__vftable, a3: v5);
    }
    else
    {
      newCapacity = 2;
      v6 = (ICvar_vtbl *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                           this: GMemory::pGlobalHeap,
                           a2: pheapAddr,
                           a3: v5,
                           a4: &newCapacity);
    }
    *((_DWORD *)this + 2) = v5;
    this->__vftable = v6;
  }
  else
  {
    if ( this->__vftable != nullptr )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->__vftable);
      this->__vftable = nullptr;
    }
    *((_DWORD *)this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF490
// Name: public: void GArrayDataBase<struct GFxAmpMemSegment,struct GAllocatorLH<struct GFxAmpMemSegment,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
mstudiobonecontroller_t *__thiscall GArrayDataBase<GFxAmpMemSegment,GAllocatorLH<GFxAmpMemSegment,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        mstudiobonecontroller_t *result,
        unsigned int newCapacity)
{
  mstudiobonecontroller_t *v4; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( *this != nullptr )
    {
      v4 = (mstudiobonecontroller_t *)GMemory::pGlobalHeap->Realloc(
                                        this: GMemory::pGlobalHeap,
                                        a2: *this,
                                        a3: (newCapacity + 3) >> 2 << 7);
    }
    else
    {
      newCapacity = 2;
      v4 = (mstudiobonecontroller_t *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                        this: GMemory::pGlobalHeap,
                                        a2: result,
                                        a3: 32 * v5,
                                        a4: &newCapacity);
    }
    *(this + 2) = (void *)v5;
    *this = v4;
  }
  else
  {
    v4 = (mstudiobonecontroller_t *)*this;
    if ( *this != nullptr )
    {
      v4 = (mstudiobonecontroller_t *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                                        a1: GMemory::pGlobalHeap,
                                        a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10102130
// Name: public: void GArrayDataBase<class GPtr<struct StatsUpdate::HeapStats>,struct GAllocatorGH<class GPtr<struct StatsUpdate::HeapStats>,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GArrayDataBase<GPtr<StatsUpdate::HeapStats>,GAllocatorGH<GPtr<StatsUpdate::HeapStats>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        CVertexBuilder *this,
        ButtonCode_t a2,
        unsigned int a3)
{
  char *result; // eax
  char *v6; // eax
  IShaderAPI **v7; // ebx
  int i; // [esp+14h] [ebp+Ch]

  result = (char *)this->m_VertexSize_BoneWeight;
  if ( a3 >= (unsigned int)result )
  {
    if ( a3 >= this->m_VertexSize_BoneMatrixIndex )
      result = (char *)GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                         this,
                         pheapAddr: a2,
                         newCapacity: a3 + (a3 >> 2));
  }
  else
  {
    v6 = &result[-a3];
    v7 = (IShaderAPI **)(this->m_VertexSize_Position + 4 * (_DWORD)&v6[a3] - 4);
    if ( v6 != nullptr )
    {
      for ( i = (int)v6; i != 0; --i )
      {
        if ( *v7 != nullptr )
          GRefCountImpl::Release(this: *v7);
        --v7;
      }
    }
    result = (char *)((unsigned int)this->m_VertexSize_BoneMatrixIndex >> 1);
    if ( a3 < (unsigned int)result )
    {
      result = (char *)GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                         this,
                         pheapAddr: a2,
                         newCapacity: a3);
      this->m_VertexSize_BoneWeight = a3;
      return result;
    }
  }
  this->m_VertexSize_BoneWeight = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10105810
// Name: public: void GArrayDataBase<struct GFxScale9GridInfo::ImgAdjust,struct GAllocatorGH<struct GFxScale9GridInfo::ImgAdjust,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxScale9GridInfo::ImgAdjust,GAllocatorGH<GFxScale9GridInfo::ImgAdjust,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *this, a3: 160 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40 * v5, a3: &newCapacity);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010D5B0
// Name: public: void GArrayDataBase<class GPtr<struct GFxAmpMovieInstructionStats::ScriptBufferStats>,struct GAllocatorLH<class GPtr<struct GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GRenderer *__thiscall GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        GRenderer::CachedData *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  GRenderer *result; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( this->pRenderer != nullptr )
    {
      result = (GRenderer *)GMemory::pGlobalHeap->Realloc(
                              this: GMemory::pGlobalHeap,
                              a2: this->pRenderer,
                              a3: 16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      result = (GRenderer *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                              this: GMemory::pGlobalHeap,
                              a2: pheapAddr,
                              a3: 4 * v5,
                              a4: &newCapacity);
    }
    *((_DWORD *)this + 2) = v5;
    this->pRenderer = result;
  }
  else
  {
    result = this->pRenderer;
    if ( this->pRenderer != nullptr )
    {
      result = (GRenderer *)((int (__thiscall *)(GMemoryHeap *, GRenderer *))GMemory::pGlobalHeap->Free)(
                              a1: GMemory::pGlobalHeap,
                              a2: this->pRenderer);
      this->pRenderer = nullptr;
    }
    *((_DWORD *)this + 2) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010E550
// Name: public: GArrayDataBase<class GFxButtonRecord,struct GAllocatorLH<class GFxButtonRecord,258>,struct GArrayDefaultPolicy>::~GArrayDataBase<class GFxButtonRecord,struct GAllocatorLH<class GFxButtonRecord,258>,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayDataBase<GFxButtonRecord,GAllocatorLH<GFxButtonRecord,258>,GArrayDefaultPolicy>::~GArrayDataBase<GFxButtonRecord,GAllocatorLH<GFxButtonRecord,258>,GArrayDefaultPolicy>(
        _DWORD *this)
{
  int v2; // edi
  void **i; // esi

  v2 = *(this + 1);
  for ( i = (void **)(84 * v2 + *this - 84); v2 != 0; --v2 )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *i);
    i -= 21;
  }
  return ((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: *this);
}

//------------------------------------------------------------------------------
// Address: 0x10110D30
// Name: public: void GArrayDataBase<class GFxButtonAction,struct GAllocatorLH<class GFxButtonAction,258>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GFxButtonAction,GAllocatorLH<GFxButtonAction,258>,GArrayDefaultPolicy>::Reserve(
        CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this,
        const CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *pheapAddr,
        unsigned int newCapacity)
{
  CRefCountServiceBase<1,CRefMT>_vtbl *v4; // esi
  CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > >_vtbl *v5; // eax

  if ( newCapacity != 0 )
  {
    v4 = (CRefCountServiceBase<1,CRefMT>_vtbl *)(4 * ((newCapacity + 3) >> 2));
    if ( this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable != nullptr )
    {
      v5 = (CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > >_vtbl *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable, a3: (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 258;
      v5 = (CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > >_vtbl *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: pheapAddr, a3: 16 * (_DWORD)v4, a4: &newCapacity);
    }
    this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = v4;
    this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = v5;
  }
  else
  {
    if ( this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable != nullptr )
    {
      GMemory::pGlobalHeap->Free(
        this: GMemory::pGlobalHeap,
        a2: this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable);
      this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = nullptr;
    }
    this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110DC0
// Name: public: void GArrayDataBase<class GFxButtonAction,struct GAllocatorLH<class GFxButtonAction,258>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayDataBase<GFxButtonAction,GAllocatorLH<GFxButtonAction,258>,GArrayDefaultPolicy>::ResizeNoConstruct(
        CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this@<ecx>,
        const char *a2@<ebx>,
        const CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *pheapAddr,
        unsigned int newSize)
{
  unsigned int m_nUserID; // eax
  unsigned int v7; // eax
  CSchemaClassBindingBase *v8; // ebx
  const char *v9; // [esp-4h] [ebp-Ch]
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  m_nUserID = this->m_nUserID;
  if ( newSize >= m_nUserID )
  {
    if ( (CRefCountServiceBase<1,CRefMT>_vtbl *)newSize >= this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable )
      GArrayDataBase<GFxButtonAction,GAllocatorLH<GFxButtonAction,258>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v7 = m_nUserID - newSize;
    v9 = a2;
    v8 = (CSchemaClassBindingBase *)&this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable[v7 - 1 + newSize];
    if ( v7 != 0 )
    {
      for ( newSizea = v7; newSizea != 0; --newSizea )
        GFxButtonAction::~GFxButtonAction(this: v8--, a2: v9);
    }
    if ( newSize < (unsigned int)this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable >> 1 )
    {
      GArrayDataBase<GFxButtonAction,GAllocatorLH<GFxButtonAction,258>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize);
      this->m_nUserID = newSize;
      return;
    }
  }
  this->m_nUserID = newSize;
}

//------------------------------------------------------------------------------
// Address: 0x10110E40
// Name: public: void GArrayDataBase<class GFxButtonRecord,struct GAllocatorLH<class GFxButtonRecord,258>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GFxButtonRecord,GAllocatorLH<GFxButtonRecord,258>,GArrayDefaultPolicy>::Reserve(
        CUtlNoEscConversion *this,
        const CUtlNoEscConversion *pheapAddr,
        unsigned int newCapacity)
{
  const char *v4; // esi
  CUtlNoEscConversion_vtbl *v5; // eax

  if ( newCapacity != 0 )
  {
    v4 = (const char *)(4 * ((newCapacity + 3) >> 2));
    if ( this->__vftable != nullptr )
    {
      v5 = (CUtlNoEscConversion_vtbl *)GMemory::pGlobalHeap->Realloc(
                                         this: GMemory::pGlobalHeap,
                                         a2: this->__vftable,
                                         a3: 336 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 258;
      v5 = (CUtlNoEscConversion_vtbl *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                         this: GMemory::pGlobalHeap,
                                         a2: pheapAddr,
                                         a3: 84 * (_DWORD)v4,
                                         a4: &newCapacity);
    }
    this->m_pDelimiter = v4;
    this->__vftable = v5;
  }
  else
  {
    if ( this->__vftable != nullptr )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->__vftable);
      this->__vftable = nullptr;
    }
    this->m_pDelimiter = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137F50
// Name: public: void GArrayDataBase<struct GFxStaticTextSnapshotData::CharRef,struct GAllocatorLH<struct GFxStaticTextSnapshotData::CharRef,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
        CStudioHdr *this,
        const CStudioHdr *pheapAddr,
        unsigned int newCapacity)
{
  const studiohdr_t **v4; // esi
  const studiohdr_t *v5; // eax

  if ( newCapacity != 0 )
  {
    v4 = (const studiohdr_t **)(4 * ((newCapacity + 3) >> 2));
    if ( this->m_pStudioHdr != nullptr )
    {
      v5 = (const studiohdr_t *)GMemory::pGlobalHeap->Realloc(
                                  this: GMemory::pGlobalHeap,
                                  a2: this->m_pStudioHdr,
                                  a3: 32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (const studiohdr_t *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                  this: GMemory::pGlobalHeap,
                                  a2: pheapAddr,
                                  a3: 8 * (_DWORD)v4,
                                  a4: &newCapacity);
    }
    this->m_pStudioHdrCache.m_Memory.m_pMemory = v4;
    this->m_pStudioHdr = v5;
  }
  else
  {
    if ( this->m_pStudioHdr != nullptr )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)this->m_pStudioHdr);
      this->m_pStudioHdr = nullptr;
    }
    this->m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137FE0
// Name: public: void GArrayDataBase<class GFxStaticTextRecord __near *,struct GAllocatorLH<class GFxStaticTextRecord __near *,258>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *__thiscall GArrayDataBase<GFxStaticTextRecord *,GAllocatorLH<GFxStaticTextRecord *,258>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *result,
        unsigned int newCapacity)
{
  GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *v4; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( *this != nullptr )
    {
      v4 = (GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *)GMemory::pGlobalHeap->Realloc(
                                                                                    this: GMemory::pGlobalHeap,
                                                                                    a2: *this,
                                                                                    a3: 16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 258;
      v4 = (GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                                                    this: GMemory::pGlobalHeap,
                                                                                    a2: result,
                                                                                    a3: 4 * v5,
                                                                                    a4: &newCapacity);
    }
    *(this + 2) = (void *)v5;
    *this = v4;
  }
  else
  {
    v4 = (GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *)*this;
    if ( *this != nullptr )
    {
      v4 = (GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                                                                                    a1: GMemory::pGlobalHeap,
                                                                                    a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10138560
// Name: public: void GArrayDataBase<struct GFxStaticTextSnapshotData::CharRef,struct GAllocatorLH<struct GFxStaticTextSnapshotData::CharRef,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        GPtr<GFxAmpProfileFrame> *this,
        const CStudioHdr *pheapAddr,
        unsigned int newSize)
{
  unsigned int v5; // eax
  unsigned int v6; // eax
  GRefCountNTSImpl **v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  v5 = *((_DWORD *)this + 1);
  if ( newSize >= v5 )
  {
    if ( newSize >= *((_DWORD *)this + 2) )
      GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
        (CStudioHdr *)this,
        pheapAddr,
        newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = v5 - newSize;
    v7 = (GRefCountNTSImpl **)((char *)this->pObject + 8 * v6 + 8 * newSize - 8);
    if ( v6 != 0 )
    {
      for ( newSizea = v6; newSizea != 0; --newSizea )
      {
        if ( *v7 != nullptr )
          GRefCountNTSImpl::Release(this: *v7);
        v7 -= 2;
      }
    }
    if ( newSize < *((_DWORD *)this + 2) >> 1 )
    {
      GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
        (CStudioHdr *)this,
        pheapAddr,
        newCapacity: newSize);
      *((_DWORD *)this + 1) = newSize;
      return;
    }
  }
  *((_DWORD *)this + 1) = newSize;
}

//------------------------------------------------------------------------------
// Address: 0x1013A730
// Name: public: void GArrayDataBase<class GFxFillStyle,struct GAllocatorLH<class GFxFillStyle,259>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
        GAtomicOpsRawBase::AcquireSync *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  void *v5; // eax

  if ( newCapacity != 0 )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( *(_DWORD *)this != 0 )
    {
      v5 = GMemory::pGlobalHeap->Realloc(
             this: GMemory::pGlobalHeap,
             a2: *(_DWORD *)this,
             a3: 160 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 259;
      v5 = GMemory::pGlobalHeap->AllocAutoHeap_2(
             this: GMemory::pGlobalHeap,
             a2: pheapAddr,
             a3: 40 * v4,
             a4: &newCapacity);
    }
    *((_DWORD *)this + 2) = v4;
    *(_DWORD *)this = v5;
  }
  else
  {
    if ( *(_DWORD *)this != 0 )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)this);
      *(_DWORD *)this = 0;
    }
    *((_DWORD *)this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013A7D0
// Name: public: void GArrayDataBase<class GFxLineStyle,struct GAllocatorLH<class GFxLineStyle,259>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxLineStyle,GAllocatorLH<GFxLineStyle,259>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 96 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 259;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 24 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013A870
// Name: public: void GArrayDataBase<class GFxFillStyle,struct GAllocatorLH<class GFxFillStyle,259>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
        GAtomicOpsRawBase::AcquireSync *this@<ecx>,
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *a2@<ebx>,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int v6; // eax
  unsigned int v7; // eax
  int v8; // ebx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v9; // [esp-4h] [ebp-Ch]
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  v6 = *((_DWORD *)this + 1);
  if ( newSize >= v6 )
  {
    if ( newSize >= *((_DWORD *)this + 2) )
      GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v7 = v6 - newSize;
    v9 = a2;
    v8 = *(_DWORD *)this + 40 * (v7 + newSize) - 40;
    if ( v7 != 0 )
    {
      for ( newSizea = v7; newSizea != 0; --newSizea )
      {
        GFxFillStyle::~GFxFillStyle(result: v9);
        v8 -= 40;
      }
    }
    if ( newSize < *((_DWORD *)this + 2) >> 1 )
    {
      GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newCapacity: newSize);
      *((_DWORD *)this + 1) = newSize;
      return;
    }
  }
  *((_DWORD *)this + 1) = newSize;
}

//------------------------------------------------------------------------------
// Address: 0x1013A8F0
// Name: public: void GArrayDataBase<class GFxLineStyle,struct GAllocatorLH<class GFxLineStyle,259>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GArrayDataBase<GFxLineStyle,GAllocatorLH<GFxLineStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
        int this,
        const void *a2,
        unsigned int a3)
{
  char *result; // eax
  char *v6; // eax
  void (__thiscall ***v7)(_DWORD, _DWORD); // esi
  char *i; // [esp+14h] [ebp+Ch]

  result = *(char **)(this + 4);
  if ( a3 >= (unsigned int)result )
  {
    if ( a3 >= *(_DWORD *)(this + 8) )
      result = (char *)GArrayDataBase<GFxLineStyle,GAllocatorLH<GFxLineStyle,259>,GArrayDefaultPolicy>::Reserve(
                         (void **)this,
                         a2,
                         a3: a3 + (a3 >> 2));
  }
  else
  {
    v6 = &result[-a3];
    v7 = (void (__thiscall ***)(_DWORD, _DWORD))(*(_DWORD *)this + 24 * (_DWORD)&v6[a3] - 24);
    if ( v6 != nullptr )
    {
      for ( i = v6; i != nullptr; --i )
      {
        (**v7)(a1: v7, a2: 0);
        v7 -= 6;
      }
    }
    result = (char *)(*(_DWORD *)(this + 8) >> 1);
    if ( a3 < (unsigned int)result )
    {
      result = (char *)GArrayDataBase<GFxLineStyle,GAllocatorLH<GFxLineStyle,259>,GArrayDefaultPolicy>::Reserve(
                         (void **)this,
                         a2,
                         a3);
      *(_DWORD *)(this + 4) = a3;
      return result;
    }
  }
  *(_DWORD *)(this + 4) = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10147A70
// Name: public: void GArrayDataBase<struct GFxPathPacker::Edge,struct GAllocatorGH<struct GFxPathPacker::Edge,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxPathPacker::Edge,GAllocatorGH<GFxPathPacker::Edge,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *this, a3: 80 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 20 * v5, a3: &newCapacity);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10147B00
// Name: public: void GArrayDataBase<class GFxLineStyle,struct GAllocatorGH<class GFxLineStyle,259>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxLineStyle,GAllocatorGH<GFxLineStyle,259>,GArrayDefaultPolicy>::Reserve(
        void **this,
        int a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 96 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 259;
      result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 24 * v5, &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10148790
// Name: public: void GArrayDataBase<class GFxLineStyle,struct GAllocatorGH<class GFxLineStyle,259>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GArrayDataBase<GFxLineStyle,GAllocatorGH<GFxLineStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
        int this,
        int a2,
        unsigned int a3)
{
  char *result; // eax
  char *v6; // eax
  void (__thiscall ***v7)(_DWORD, _DWORD); // esi
  char *i; // [esp+14h] [ebp+Ch]

  result = *(char **)(this + 4);
  if ( a3 >= (unsigned int)result )
  {
    if ( a3 >= *(_DWORD *)(this + 8) )
      result = (char *)GArrayDataBase<GFxLineStyle,GAllocatorGH<GFxLineStyle,259>,GArrayDefaultPolicy>::Reserve(
                         (void **)this,
                         a2,
                         a3: a3 + (a3 >> 2));
  }
  else
  {
    v6 = &result[-a3];
    v7 = (void (__thiscall ***)(_DWORD, _DWORD))(*(_DWORD *)this + 24 * (_DWORD)&v6[a3] - 24);
    if ( v6 != nullptr )
    {
      for ( i = v6; i != nullptr; --i )
      {
        (**v7)(a1: v7, a2: 0);
        v7 -= 6;
      }
    }
    result = (char *)(*(_DWORD *)(this + 8) >> 1);
    if ( a3 < (unsigned int)result )
    {
      result = (char *)GArrayDataBase<GFxLineStyle,GAllocatorGH<GFxLineStyle,259>,GArrayDefaultPolicy>::Reserve(
                         (void **)this,
                         a2,
                         a3);
      *(_DWORD *)(this + 4) = a3;
      return result;
    }
  }
  *(_DWORD *)(this + 4) = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10148810
// Name: public: void GArrayDataBase<class GFxFillStyle,struct GAllocatorGH<class GFxFillStyle,259>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxFillStyle,GAllocatorGH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
        void **this,
        int a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 160 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 259;
      result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40 * v5, &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10149F10
// Name: public: void GArrayDataBase<class GFxFillStyle,struct GAllocatorGH<class GFxFillStyle,259>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__userpurge GArrayDataBase<GFxFillStyle,GAllocatorGH<GFxFillStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct@<eax>(
        int a1@<ecx>,
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *a2@<ebx>,
        int a3,
        unsigned int a4)
{
  char *result; // eax
  char *v7; // eax
  int v8; // ebx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v9; // [esp-4h] [ebp-Ch]
  char *i; // [esp+14h] [ebp+Ch]

  result = *(char **)(a1 + 4);
  if ( a4 >= (unsigned int)result )
  {
    if ( a4 >= *(_DWORD *)(a1 + 8) )
      result = (char *)GArrayDataBase<GFxFillStyle,GAllocatorGH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
                         this: (void **)a1,
                         a2: a3,
                         a3: a4 + (a4 >> 2));
  }
  else
  {
    v7 = &result[-a4];
    v9 = a2;
    v8 = *(_DWORD *)a1 + 40 * (_DWORD)&v7[a4] - 40;
    if ( v7 != nullptr )
    {
      for ( i = v7; i != nullptr; --i )
      {
        GFxFillStyle::~GFxFillStyle(result: v9);
        v8 -= 40;
      }
    }
    result = (char *)(*(_DWORD *)(a1 + 8) >> 1);
    if ( a4 < (unsigned int)result )
    {
      result = (char *)GArrayDataBase<GFxFillStyle,GAllocatorGH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
                         this: (void **)a1,
                         a2: a3,
                         a3: a4);
      *(_DWORD *)(a1 + 4) = a4;
      return result;
    }
  }
  *(_DWORD *)(a1 + 4) = a4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10152490
// Name: public: void GArrayDataBase<class GPtr<class GFxShapeBase>,struct GAllocatorLH<class GPtr<class GFxShapeBase>,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GPtr<GFxShapeBase>,GAllocatorLH<GPtr<GFxShapeBase>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        GStatInfo *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  GStatInfo::StatInterface *pInterface; // eax
  char *v6; // eax
  GFxShapeBase **v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  pInterface = this->pInterface;
  if ( newSize >= (unsigned int)pInterface )
  {
    if ( (GStat *)newSize >= this->pData )
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        (GRenderer::CachedData *)this,
        pheapAddr,
        newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = (char *)pInterface - newSize;
    v7 = (GFxShapeBase **)(this->StatId + 4 * (_DWORD)&v6[newSize] - 4);
    if ( v6 != nullptr )
    {
      for ( newSizea = (unsigned int)v6; newSizea != 0; --newSizea )
      {
        if ( *v7 != nullptr )
          GFxShapeBase::Release(this: *v7);
        --v7;
      }
    }
    if ( newSize < (unsigned int)this->pData >> 1 )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        (GRenderer::CachedData *)this,
        pheapAddr,
        newCapacity: newSize);
      this->pInterface = (GStatInfo::StatInterface *)newSize;
      return;
    }
  }
  this->pInterface = (GStatInfo::StatInterface *)newSize;
}

//------------------------------------------------------------------------------
// Address: 0x101581E0
// Name: public: void GArrayDataBase<class GASValue,struct GAllocatorLH<class GASValue,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        ButtonCode_t pheapAddr,
        unsigned int newCapacity)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *this, a3: (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 2;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(
                 this: GMemory::pGlobalHeap,
                 a2: pheapAddr,
                 a3: 16 * v5,
                 a4: &newCapacity);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10159870
// Name: public: GArrayDataBase<class GFxMorphCharacterDef::Path,struct GAllocatorLH<class GFxMorphCharacterDef::Path,2>,struct GArrayDefaultPolicy>::~GArrayDataBase<class GFxMorphCharacterDef::Path,struct GAllocatorLH<class GFxMorphCharacterDef::Path,2>,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayDataBase<GFxMorphCharacterDef::Path,GAllocatorLH<GFxMorphCharacterDef::Path,2>,GArrayDefaultPolicy>::~GArrayDataBase<GFxMorphCharacterDef::Path,GAllocatorLH<GFxMorphCharacterDef::Path,2>,GArrayDefaultPolicy>(
        _DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  void **v4; // esi
  int i; // edi

  v2 = *(this + 1);
  v3 = *this + 36 * v2 - 36;
  if ( v2 != 0 )
  {
    v4 = (void **)(v3 + 20);
    for ( i = v2; i != 0; --i )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v4);
      v4 -= 9;
    }
  }
  return ((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: *this);
}

//------------------------------------------------------------------------------
// Address: 0x101598C0
// Name: public: void GArrayDataBase<class GFxMorphCharacterDef::Path,struct GAllocatorLH<class GFxMorphCharacterDef::Path,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxMorphCharacterDef::Path,GAllocatorLH<GFxMorphCharacterDef::Path,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 144 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 2;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 36 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10159950
// Name: public: void GArrayDataBase<class GFxMorphCharacterDef::Path,struct GAllocatorLH<class GFxMorphCharacterDef::Path,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GArrayDataBase<GFxMorphCharacterDef::Path,GAllocatorLH<GFxMorphCharacterDef::Path,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        int this,
        const void *a2,
        unsigned int a3)
{
  char *result; // eax
  int v6; // ecx
  _DWORD *v7; // edi
  char *i; // [esp+14h] [ebp+Ch]

  result = *(char **)(this + 4);
  if ( a3 >= (unsigned int)result )
  {
    if ( a3 >= *(_DWORD *)(this + 8) )
      result = (char *)GArrayDataBase<GFxMorphCharacterDef::Path,GAllocatorLH<GFxMorphCharacterDef::Path,2>,GArrayDefaultPolicy>::Reserve(
                         (void **)this,
                         a2,
                         a3: a3 + (a3 >> 2));
  }
  else
  {
    result -= a3;
    v6 = *(_DWORD *)this + 36 * (_DWORD)&result[a3] - 36;
    if ( result != nullptr )
    {
      v7 = (_DWORD *)(v6 + 20);
      for ( i = result; i != nullptr; --i )
      {
        result = (char *)((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(
                           a1: GMemory::pGlobalHeap,
                           a2: *v7);
        v7 -= 9;
      }
    }
    if ( a3 < *(_DWORD *)(this + 8) >> 1 )
    {
      result = (char *)GArrayDataBase<GFxMorphCharacterDef::Path,GAllocatorLH<GFxMorphCharacterDef::Path,2>,GArrayDefaultPolicy>::Reserve(
                         (void **)this,
                         a2,
                         a3);
      *(_DWORD *)(this + 4) = a3;
      return result;
    }
  }
  *(_DWORD *)(this + 4) = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015AE10
// Name: public: void GArrayDataBase<unsigned short,struct GAllocatorLH<unsigned short,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 8 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 2;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 2 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015AEA0
// Name: public: void GArrayDataBase<struct GFxMeshSet::MeshSubShape,struct GAllocatorLH<struct GFxMeshSet::MeshSubShape,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxMeshSet::MeshSubShape,GAllocatorLH<GFxMeshSet::MeshSubShape,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 80 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 2;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 20 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015B3C0
// Name: public: void GArrayDataBase<struct MovieSourceLineStats::SourceStats,struct GAllocatorLH<struct MovieSourceLineStats::SourceStats,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<MovieSourceLineStats::SourceStats,GAllocatorLH<MovieSourceLineStats::SourceStats,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 96 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 2;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 24 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015B4D0
// Name: public: void GArrayDataBase<struct GFxTexture9Grid,struct GAllocatorLH<struct GFxTexture9Grid,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxTexture9Grid,GAllocatorLH<GFxTexture9Grid,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 1360 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 2;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 340 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015D390
// Name: public: void GArrayDataBase<class GFxMesh,struct GAllocatorLH<class GFxMesh,131>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxMesh,GAllocatorLH<GFxMesh,131>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 160 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 131;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 40 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015D430
// Name: public: void GArrayDataBase<class GFxCachedStroke,struct GAllocatorLH<class GFxCachedStroke,132>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxCachedStroke,GAllocatorLH<GFxCachedStroke,132>,GArrayDefaultPolicy>::Reserve(
        void **this,
        const void *a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 352 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      a3 = 132;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: 88 * v5, a4: &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015F940
// Name: public: GArrayDataBase<class GRangeData<class GPtr<class GFxTextFormat>>,struct GAllocatorLH<class GRangeData<class GPtr<class GFxTextFormat>>,2>,struct GArrayDefaultPolicy>::~GArrayDataBase<class GRangeData<class GPtr<class GFxTextFormat>>,struct GAllocatorLH<class GRangeData<class GPtr<class GFxTextFormat>>,2>,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
wchar_t __thiscall GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::~GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>(
        _DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  IShaderAPI **v4; // esi
  int i; // edi

  v2 = *(this + 1);
  v3 = *this + 12 * v2 - 12;
  if ( v2 != 0 )
  {
    v4 = (IShaderAPI **)(v3 + 8);
    for ( i = v2; i != 0; --i )
    {
      if ( *v4 != nullptr )
        GRefCountImpl::Release(this: *v4);
      v4 -= 3;
    }
  }
  return ((wchar_t (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: *this);
}

//------------------------------------------------------------------------------
// Address: 0x1015F9C0
// Name: public: void GArrayDataBase<struct GFxStyledText::HTMLImageTagInfo,struct GAllocatorDH<struct GFxStyledText::HTMLImageTagInfo,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxStyledText::HTMLImageTagInfo,GAllocatorDH<GFxStyledText::HTMLImageTagInfo,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        int a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi
  int (__thiscall *v6)(int, unsigned int, int *); // edx

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 176 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      v6 = *(int (__thiscall **)(int, unsigned int, int *))(*(_DWORD *)a2 + 40);
      a3 = 2;
      result = (void *)v6(a1: a2, a2: 44 * v5, &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101611B0
// Name: public: void GArrayDataBase<class GRangeData<class GPtr<class GFxTextFormat>>,struct GAllocatorLH<class GRangeData<class GPtr<class GFxTextFormat>>,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        int this,
        const void *pheapAddr,
        unsigned int newSize)
{
  const wchar_t *result; // eax
  char *v6; // eax
  IShaderAPI **v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  result = *(const wchar_t **)(this + 4);
  if ( newSize >= (unsigned int)result )
  {
    if ( newSize >= *(_DWORD *)(this + 8) )
      result = GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
                 (void **)this,
                 pheapAddr,
                 newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = (char *)result - newSize;
    v7 = (IShaderAPI **)(*(_DWORD *)this + 12 * (_DWORD)&v6[newSize] - 4);
    if ( v6 != nullptr )
    {
      for ( newSizea = (unsigned int)v6; newSizea != 0; --newSizea )
      {
        if ( *v7 != nullptr )
          GRefCountImpl::Release(this: *v7);
        v7 -= 3;
      }
    }
    result = (const wchar_t *)(*(_DWORD *)(this + 8) >> 1);
    if ( newSize < (unsigned int)result )
    {
      result = GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
                 (void **)this,
                 pheapAddr,
                 newCapacity: newSize);
      *(_DWORD *)(this + 4) = newSize;
      return result;
    }
  }
  *(_DWORD *)(this + 4) = newSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10162B00
// Name: public: void GArrayDataBase<struct GFxSGMLStackElemDesc<wchar_t>,struct GAllocatorDH<struct GFxSGMLStackElemDesc<wchar_t>,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<GFxSGMLStackElemDesc<wchar_t>,GAllocatorDH<GFxSGMLStackElemDesc<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        int a2,
        int a3)
{
  void *result; // eax
  unsigned int v5; // esi
  int (__thiscall *v6)(int, unsigned int, int *); // edx

  if ( a3 != 0 )
  {
    v5 = 4 * ((unsigned int)(a3 + 3) >> 2);
    if ( *this != nullptr )
    {
      result = GMemory::pGlobalHeap->Realloc(
                 this: GMemory::pGlobalHeap,
                 a2: *this,
                 a3: 336 * ((unsigned int)(a3 + 3) >> 2));
    }
    else
    {
      v6 = *(int (__thiscall **)(int, unsigned int, int *))(*(_DWORD *)a2 + 40);
      a3 = 2;
      result = (void *)v6(a1: a2, a2: 84 * v5, &a3);
    }
    *(this + 2) = (void *)v5;
    *this = result;
  }
  else
  {
    result = *this;
    if ( *this != nullptr )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101686D0
// Name: public: void GArrayDataBase<struct GFxTextDocView::ImageSubstitutor::Element,struct GAllocatorLH<struct GFxTextDocView::ImageSubstitutor::Element,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *__thiscall GArrayDataBase<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>::Reserve(
        void **this,
        GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *result,
        unsigned int newCapacity)
{
  GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *v4; // eax
  unsigned int v5; // esi

  if ( newCapacity != 0 )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( *this != nullptr )
    {
      v4 = (GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *)GMemory::pGlobalHeap->Realloc(
                                                                                                    this: GMemory::pGlobalHeap,
                                                                                                    a2: *this,
                                                                                                    a3: 192 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v4 = (GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                                                                    this: GMemory::pGlobalHeap,
                                                                                                    a2: result,
                                                                                                    a3: 48 * v5,
                                                                                                    a4: &newCapacity);
    }
    *(this + 2) = (void *)v5;
    *this = v4;
  }
  else
  {
    v4 = (GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *)*this;
    if ( *this != nullptr )
    {
      v4 = (GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                                                                                                    a1: GMemory::pGlobalHeap,
                                                                                                    a2: *this);
      *this = nullptr;
    }
    *(this + 2) = nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10168A70
// Name: public: void GArrayDataBase<struct GFxTextDocView::ImageSubstitutor::Element,struct GAllocatorLH<struct GFxTextDocView::ImageSubstitutor::Element,2>,struct GArrayDefaultPolicy>::ResizeNoConstruct(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *__thiscall GArrayDataBase<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        int this,
        GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *result,
        unsigned int newSize)
{
  GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *v5; // eax
  char *v6; // eax
  GRefCountNTSImpl **v7; // ebx
  unsigned int newSizea; // [esp+14h] [ebp+Ch]

  v5 = *(GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > **)(this + 4);
  if ( newSize >= (unsigned int)v5 )
  {
    if ( newSize >= *(_DWORD *)(this + 8) )
      v5 = GArrayDataBase<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>::Reserve(
             (void **)this,
             result,
             newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    v6 = (char *)v5 - newSize;
    v7 = (GRefCountNTSImpl **)(*(_DWORD *)this + 48 * (_DWORD)&v6[newSize] - 8);
    if ( v6 != nullptr )
    {
      for ( newSizea = (unsigned int)v6; newSizea != 0; --newSizea )
      {
        if ( *v7 != nullptr )
          GRefCountNTSImpl::Release(this: *v7);
        v7 -= 12;
      }
    }
    v5 = (GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *)(*(_DWORD *)(this + 8) >> 1);
    if ( newSize < (unsigned int)v5 )
    {
      v5 = GArrayDataBase<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>::Reserve(
             (void **)this,
             result,
             newCapacity: newSize);
      *(_DWORD *)(this + 4) = newSize;
      return v5;
    }
  }
  *(_DWORD *)(this + 4) = newSize;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1017B2D0
// Name: public: void GArrayDataBase<struct GFxTextHighlightDesc,struct GAllocatorLH<struct GFxTextHighlightDesc,2>,struct GArrayDefaultPolicy>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayDataBase<GFxTextHighlightDesc,GAllocatorLH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>::Reserve(
        GRenderer::FillTexture *this,
        const GRenderer::FillTexture *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  GTexture *v5; // eax

  if ( newCapacity != 0 )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->pTexture != nullptr )
    {
      v5 = (GTexture *)GMemory::pGlobalHeap->Realloc(
                         this: GMemory::pGlobalHeap,
                         a2: this->pTexture,
                         a3: 160 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (GTexture *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                         this: GMemory::pGlobalHeap,
                         a2: pheapAddr,
                         a3: 40 * v4,
                         a4: &newCapacity);
    }
    LODWORD(this->TextureMatrix.M_[0][1]) = v4;
    this->pTexture = v5;
  }
  else
  {
    if ( this->pTexture != nullptr )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->pTexture);
      this->pTexture = nullptr;
    }
    this->TextureMatrix.M_[0][1] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184720
// Name: public: void GArrayDataBase<unsigned char,struct GAllocatorLH<unsigned char,2>,struct GArrayConstPolicy<0,4,1>>::Reserve(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayConstPolicy<0,4,1>>::Reserve(
        void **this,
        const void *a2,
        unsigned int a3)
{
  void *result; // eax
  unsigned int v5; // esi

  result = (void *)a3;
  if ( a3 >= (unsigned int)*(this + 2) )
  {
    if ( a3 != 0 )
    {
      v5 = 4 * ((a3 + 3) >> 2);
      if ( *this != nullptr )
      {
        result = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *this, a3: v5);
      }
      else
      {
        a3 = 2;
        result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2, a3: v5, a4: &a3);
      }
      *(this + 2) = (void *)v5;
      *this = result;
    }
    else
    {
      result = *this;
      if ( *this != nullptr )
      {
        result = (void *)((int (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
                           a1: GMemory::pGlobalHeap,
                           a2: *this);
        *this = nullptr;
      }
      *(this + 2) = nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8C00
// Name: bool G_QuickSortSlicedSafe<class GArrayAdaptor<class GASValue __near *>,class GASArraySortFunctor>(class GArrayAdaptor<class GASValue __near *> __near &,unsigned int,unsigned int,class GASArraySortFunctor)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl G_QuickSortSlicedSafe<GArrayAdaptor<GASValue *>,GASArraySortFunctor>(
        int *a1,
        int a2,
        int a3,
        char a4,
        int a5,
        int a6,
        int a7,
        char a8)
{
  int v8; // ebx
  _BYTE *v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  _DWORD *v14; // eax
  const struct GASValue *v15; // ecx
  int v16; // edi
  int v17; // ebx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // ecx
  int v25; // edx
  int v26; // eax
  _DWORD *v27; // ecx
  _DWORD *v28; // eax
  int v29; // edx
  int v30; // edi
  _DWORD *v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // [esp+8h] [ebp-154h]
  int v36; // [esp+8h] [ebp-154h]
  _BYTE *v37; // [esp+Ch] [ebp-150h]
  int v38; // [esp+10h] [ebp-14Ch]
  int v39; // [esp+14h] [ebp-148h]
  _BYTE v40[320]; // [esp+18h] [ebp-144h] BYREF

  v8 = a2;
  if ( (unsigned int)(a3 - a2) >= 2 )
  {
    v10 = v40;
    v39 = a2;
    v38 = a3;
    while ( 1 )
    {
      v37 = v10;
LABEL_11:
      if ( v38 - v8 > 9 )
        break;
      v30 = v8;
      v39 = v8 + 1;
      if ( v8 + 1 < v38 )
      {
        do
        {
          for ( ;
                GASArraySortFunctor::Compare(
                  this: (GASArraySortFunctor *)&a4,
                  a2: *(const struct GASValue **)(*a1 + 4 * v30 + 4),
                  a3: *(const struct GASValue **)(*a1 + 4 * v30)) < 0;
                --v30 )
          {
            v31 = (_DWORD *)(*a1 + 4 * v30);
            v32 = v31[1];
            v31[1] = *v31;
            *v31 = v32;
            if ( v30 == v8 )
              break;
          }
          v30 = v39++;
        }
        while ( v39 < v38 );
        v10 = v37;
      }
      if ( v10 <= v40 )
      {
        if ( (a8 & 2) == 0 && a6 != 0 )
          GRefCountBaseGC<323>::Release();
        a6 = 0;
        if ( (a8 & 1) == 0 && a7 != 0 )
          GRefCountBaseGC<323>::Release();
        return 1;
      }
      v33 = *((_DWORD *)v10 - 2);
      v34 = *((_DWORD *)v10 - 1);
      v10 -= 8;
      v39 = v33;
      v38 = v34;
      v8 = v33;
    }
    v11 = *(_DWORD *)(*a1 + 4 * v8);
    v12 = v8 + (v38 - v8) / 2;
    v13 = *(_DWORD *)(*a1 + 4 * v12);
    v14 = (_DWORD *)(*a1 + 4 * v12);
    *(_DWORD *)(*a1 + 4 * v8) = v13;
    *v14 = v11;
    v15 = *(const struct GASValue **)(*a1 + 4 * v8 + 4);
    v16 = v8 + 1;
    v17 = v38 - 1;
    if ( GASArraySortFunctor::Compare(
           this: (GASArraySortFunctor *)&a4,
           a2: *(const struct GASValue **)(*a1 + 4 * v38 - 4),
           a3: v15) < 0 )
    {
      v18 = *a1;
      v19 = *(_DWORD *)(*a1 + 4 * v17);
      *(_DWORD *)(v18 + 4 * v17) = *(_DWORD *)(*a1 + 4 * v16);
      *(_DWORD *)(v18 + 4 * v16) = v19;
    }
    if ( GASArraySortFunctor::Compare(
           this: (GASArraySortFunctor *)&a4,
           a2: *(const struct GASValue **)(*a1 + 4 * v39),
           a3: *(const struct GASValue **)(*a1 + 4 * v16)) < 0 )
    {
      v20 = *a1;
      v35 = *(_DWORD *)(*a1 + 4 * v39);
      *(_DWORD *)(v20 + 4 * v39) = *(_DWORD *)(*a1 + 4 * v16);
      *(_DWORD *)(v20 + 4 * v16) = v35;
    }
    if ( GASArraySortFunctor::Compare(
           this: (GASArraySortFunctor *)&a4,
           a2: *(const struct GASValue **)(*a1 + 4 * v17),
           a3: *(const struct GASValue **)(*a1 + 4 * v39)) < 0 )
    {
      v21 = *a1;
      v22 = *(_DWORD *)(*a1 + 4 * v17);
      *(_DWORD *)(v21 + 4 * v17) = *(_DWORD *)(v21 + 4 * v39);
      *(_DWORD *)(v21 + 4 * v39) = v22;
    }
LABEL_18:
    while ( ++v16 < v38 )
    {
      if ( GASArraySortFunctor::Compare(
             this: (GASArraySortFunctor *)&a4,
             a2: *(const struct GASValue **)(*a1 + 4 * v16),
             a3: *(const struct GASValue **)(*a1 + 4 * v39)) >= 0 )
      {
        while ( --v17 >= 0 )
        {
          if ( GASArraySortFunctor::Compare(
                 this: (GASArraySortFunctor *)&a4,
                 a2: *(const struct GASValue **)(*a1 + 4 * v39),
                 a3: *(const struct GASValue **)(*a1 + 4 * v17)) >= 0 )
          {
            v23 = *a1;
            if ( v16 <= v17 )
            {
              v24 = *(_DWORD *)(v23 + 4 * v16);
              *(_DWORD *)(v23 + 4 * v16) = *(_DWORD *)(v23 + 4 * v17);
              *(_DWORD *)(v23 + 4 * v17) = v24;
              goto LABEL_18;
            }
            v36 = *(_DWORD *)(v23 + 4 * v39);
            *(_DWORD *)(v23 + 4 * v39) = *(_DWORD *)(v23 + 4 * v17);
            v25 = v38;
            *(_DWORD *)(v23 + 4 * v17) = v36;
            v26 = v39;
            if ( v17 - v39 <= v25 - v16 )
            {
              v28 = v37;
              v29 = v38;
              v37 += 8;
              v10 = v37;
              v38 = v17;
              v8 = v39;
              *v28 = v16;
              v28[1] = v29;
            }
            else
            {
              v27 = v37;
              v37 += 8;
              v27[1] = v17;
              *v27 = v26;
              v10 = v37;
              v39 = v16;
              v8 = v16;
            }
            goto LABEL_11;
          }
        }
        break;
      }
    }
    if ( (a8 & 2) == 0 && a6 != 0 )
      GRefCountBaseGC<323>::Release();
    a6 = 0;
    if ( (a8 & 1) == 0 && a7 != 0 )
      GRefCountBaseGC<323>::Release();
    return 0;
  }
  else
  {
    if ( (a8 & 2) == 0 && a6 != 0 )
      GRefCountBaseGC<323>::Release();
    a6 = 0;
    if ( (a8 & 1) == 0 && a7 != 0 )
      GRefCountBaseGC<323>::Release();
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8FE0
// Name: bool G_QuickSortSafe<class GArrayAdaptor<class GASValue __near *>,class GASArraySortFunctor>(class GArrayAdaptor<class GASValue __near *> __near &,class GASArraySortFunctor)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl G_QuickSortSafe<GArrayAdaptor<GASValue *>,GASArraySortFunctor>(
        int *a1,
        char a2,
        int a3,
        int a4,
        tagIMECHARPOSITION *result,
        char a6)
{
  char v6; // bl

  if ( a4 != 0 )
  {
    ++*(_DWORD *)(a4 + 8);
    *(_DWORD *)(a4 + 8) &= 0x8FFFFFFF;
  }
  if ( result != nullptr )
    GASFunctionRefBase::SetLocalFrame(result);
  v6 = G_QuickSortSlicedSafe<GArrayAdaptor<GASValue *>,GASArraySortFunctor>(
         a1,
         a2: 0,
         a3: a1[1],
         a4: a2,
         a5: a3,
         a6: a4,
         a7: 0,
         a8: 0);
  if ( (a6 & 2) == 0 && a4 != 0 )
    GRefCountBaseGC<323>::Release();
  if ( (a6 & 1) == 0 && result != nullptr )
    GRefCountBaseGC<323>::Release();
  return v6;
}
