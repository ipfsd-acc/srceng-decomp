// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/shaderapidx10.cpp
// Functions: 79
// ============================================================

#include "materialsystem\shaderapidx9\shaderapidx10.h"

//------------------------------------------------------------------------------
// Address: 0x10008910
// Name: private: virtual int CShaderAPIDx10::OcclusionQuery_GetNumPixelsRendered(struct ShaderAPIOcclusionQuery_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IVertexBuffer *__thiscall CShaderAPIDx10::OcclusionQuery_GetNumPixelsRendered(
        CMeshMgr *this,
        IMaterial *pMaterial,
        bool buffered)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10008FD0
// Name: private: virtual void CShaderAPIDx10::SetIntegerVertexShaderConstant(int,int const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::SetIntegerVertexShaderConstant(
        CMeshDx10 *this,
        bool bReadOnly,
        int nFirstIndex,
        int nIndexCount,
        IndexDesc_t *desc)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000D4A0
// Name: public: bool ShaderIndexBufferStateDx10_t::operator!=(struct ShaderIndexBufferStateDx10_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall ShaderIndexBufferStateDx10_t::operator!=(
        ShaderIndexBufferStateDx10_t *this,
        const ShaderIndexBufferStateDx10_t *src)
{
  unsigned int i; // edx
  int v4; // esi
  unsigned int v5; // edx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ecx
  unsigned int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // ecx
  int v13; // eax

  for ( i = 12; i >= 4; i -= 4 )
  {
    if ( this->m_pBuffer != src->m_pBuffer )
      goto LABEL_5;
    src = (const ShaderIndexBufferStateDx10_t *)((char *)src + 4);
    this = (ShaderIndexBufferStateDx10_t *)((char *)this + 4);
  }
  if ( i == 0 )
  {
LABEL_14:
    v13 = 0;
    return v13 != 0;
  }
LABEL_5:
  v4 = LOBYTE(this->m_pBuffer) - LOBYTE(src->m_pBuffer);
  if ( v4 == 0 )
  {
    v5 = i - 1;
    v6 = (unsigned __int8 *)&src->m_pBuffer + 1;
    v7 = (unsigned __int8 *)&this->m_pBuffer + 1;
    if ( v5 == 0 )
      goto LABEL_14;
    v4 = *v7 - *v6;
    if ( v4 == 0 )
    {
      v8 = v5 - 1;
      v9 = v6 + 1;
      v10 = v7 + 1;
      if ( v8 == 0 )
        goto LABEL_14;
      v4 = *v10 - *v9;
      if ( v4 == 0 )
      {
        v11 = v9 + 1;
        v12 = v10 + 1;
        if ( v8 == 1 )
          goto LABEL_14;
        v4 = *v12 - *v11;
        if ( v4 == 0 )
          goto LABEL_14;
      }
    }
  }
  v13 = 1;
  if ( v4 <= 0 )
    return 1;
  return v13 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D550
// Name: CommitSetTopology
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommitSetTopology(
        ID3D10Device *pDevice,
        const ShaderStateDx10_t *desiredState,
        ShaderStateDx10_t *currentState,
        bool bForce)
{
  if ( bForce || desiredState->m_Topology != currentState->m_Topology )
  {
    pDevice->IASetPrimitiveTopology(this: pDevice, a2: desiredState->m_Topology);
    currentState->m_Topology = desiredState->m_Topology;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D5A0
// Name: CommitSetVertexShader
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommitSetVertexShader(
        ID3D10Device *pDevice,
        const ShaderStateDx10_t *desiredState,
        ShaderStateDx10_t *currentState,
        bool bForce)
{
  if ( bForce || desiredState->m_pVertexShader != currentState->m_pVertexShader )
  {
    pDevice->VSSetShader(this: pDevice, a2: desiredState->m_pVertexShader);
    currentState->m_pVertexShader = desiredState->m_pVertexShader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D5F0
// Name: CommitSetGeometryShader
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommitSetGeometryShader(
        ID3D10Device *pDevice,
        const ShaderStateDx10_t *desiredState,
        ShaderStateDx10_t *currentState,
        bool bForce)
{
  if ( bForce || desiredState->m_pGeometryShader != currentState->m_pGeometryShader )
  {
    pDevice->GSSetShader(this: pDevice, a2: desiredState->m_pGeometryShader);
    currentState->m_pGeometryShader = desiredState->m_pGeometryShader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D640
// Name: CommitSetPixelShader
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommitSetPixelShader(
        ID3D10Device *pDevice,
        const ShaderStateDx10_t *desiredState,
        ShaderStateDx10_t *currentState,
        bool bForce)
{
  if ( bForce || desiredState->m_pPixelShader != currentState->m_pPixelShader )
  {
    pDevice->PSSetShader(this: pDevice, a2: desiredState->m_pPixelShader);
    currentState->m_pPixelShader = desiredState->m_pPixelShader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D690
// Name: CommitSetInputLayout
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommitSetInputLayout(
        ID3D10Device *pDevice,
        const ShaderStateDx10_t *desiredState,
        ShaderStateDx10_t *currentState,
        bool bForce)
{
  ShaderInputLayoutStateDx10_t *p_m_InputLayout; // esi
  ID3D10InputLayout *InputLayout; // eax

  p_m_InputLayout = &desiredState->m_InputLayout;
  if ( bForce || memcmp(&desiredState->m_InputLayout, &currentState->m_InputLayout, 0x88u) != 0 )
  {
    InputLayout = CShaderDeviceDx10::GetInputLayout(
                    this: g_pShaderDeviceDx10,
                    hShader: p_m_InputLayout->m_hVertexShader,
                    format: desiredState->m_InputLayout.m_pVertexDecl[0]);
    pDevice->IASetInputLayout(this: pDevice, a2: InputLayout);
    qmemcpy(&currentState->m_InputLayout, p_m_InputLayout, sizeof(currentState->m_InputLayout));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D870
// Name: CommitSetIndexBuffer
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommitSetIndexBuffer(
        ID3D10Device *pDevice,
        const ShaderStateDx10_t *desiredState,
        ShaderStateDx10_t *currentState,
        bool bForce)
{
  ShaderIndexBufferStateDx10_t *p_m_IndexBuffer; // edi

  p_m_IndexBuffer = &desiredState->m_IndexBuffer;
  if ( bForce || memcmp(&desiredState->m_IndexBuffer, &currentState->m_IndexBuffer, 0xCu) != 0 )
  {
    pDevice->IASetIndexBuffer(
      this: pDevice,
      a2: p_m_IndexBuffer->m_pBuffer,
      a3: desiredState->m_IndexBuffer.m_Format,
      a4: desiredState->m_IndexBuffer.m_nOffset);
    *(_QWORD *)&currentState->m_IndexBuffer.m_pBuffer = *(_QWORD *)&p_m_IndexBuffer->m_pBuffer;
    currentState->m_IndexBuffer.m_nOffset = desiredState->m_IndexBuffer.m_nOffset;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D950
// Name: CommitSetVertexBuffer
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommitSetVertexBuffer(
        ID3D10Device *pDevice,
        const ShaderStateDx10_t *desiredState,
        ShaderStateDx10_t *currentState,
        bool bForce)
{
  int v4; // ebp
  unsigned int v5; // ebx
  ShaderVertexBufferStateDx10_t *m_pVertexBuffer; // esi
  int v7; // edi
  _DWORD *v8; // edi
  unsigned int v9; // eax
  ShaderVertexBufferStateDx10_t *v10; // ecx
  _DWORD *v11; // edx
  int v12; // esi
  unsigned int v13; // eax
  unsigned __int8 *v14; // ecx
  unsigned __int8 *v15; // edx
  unsigned int v16; // eax
  unsigned __int8 *v17; // ecx
  unsigned __int8 *v18; // edx
  unsigned __int8 *v19; // ecx
  unsigned __int8 *v20; // edx
  bool v21; // cc
  int v22; // eax
  char v23; // al
  unsigned int v24; // edx
  __int64 v25; // xmm0_8
  unsigned int v26; // ecx
  unsigned int v27; // edx
  char nFirstBuffer_3; // [esp+19h] [ebp-D1h]
  unsigned int nBufferCount; // [esp+1Ah] [ebp-D0h]
  unsigned int v30; // [esp+1Eh] [ebp-CCh]
  ShaderVertexBufferStateDx10_t *v31; // [esp+22h] [ebp-C8h]
  unsigned int pOffsets[16]; // [esp+26h] [ebp-C4h] BYREF
  unsigned int pStrides[16]; // [esp+66h] [ebp-84h] BYREF
  ID3D10Buffer *ppVertexBuffers[16]; // [esp+A6h] [ebp-44h] BYREF

  v4 = 0;
  v5 = 0;
  m_pVertexBuffer = currentState->m_pVertexBuffer;
  v7 = (char *)desiredState - (char *)currentState;
  nBufferCount = 0;
  v30 = 0;
  nFirstBuffer_3 = 1;
  v31 = currentState->m_pVertexBuffer;
  while ( 1 )
  {
    v8 = (ID3D10Buffer **)((char *)&m_pVertexBuffer->m_pBuffer + v7);
    if ( bForce )
      goto LABEL_21;
    v9 = 12;
    v10 = m_pVertexBuffer;
    v11 = v8;
    do
    {
      if ( (ID3D10Buffer *)*v11 != v10->m_pBuffer )
        goto LABEL_8;
      v9 -= 4;
      v10 = (ShaderVertexBufferStateDx10_t *)((char *)v10 + 4);
      ++v11;
    }
    while ( v9 >= 4 );
    if ( v9 == 0 )
      goto LABEL_18;
LABEL_8:
    v12 = *(unsigned __int8 *)v11 - LOBYTE(v10->m_pBuffer);
    if ( v12 == 0 )
    {
      v13 = v9 - 1;
      v14 = (unsigned __int8 *)&v10->m_pBuffer + 1;
      v15 = (unsigned __int8 *)v11 + 1;
      if ( v13 == 0 )
        goto LABEL_17;
      v12 = *v15 - *v14;
      if ( v12 == 0 )
      {
        v16 = v13 - 1;
        v17 = v14 + 1;
        v18 = v15 + 1;
        if ( v16 == 0
          || (v12 = *v18 - *v17) == 0 && ((v19 = v17 + 1, v20 = v18 + 1, v16 == 1) || (v12 = *v20 - *v19) == 0) )
        {
LABEL_17:
          m_pVertexBuffer = v31;
LABEL_18:
          v5 = nBufferCount;
          v22 = 0;
          goto LABEL_19;
        }
      }
    }
    v5 = nBufferCount;
    v21 = v12 <= 0;
    m_pVertexBuffer = v31;
    v22 = 1;
    if ( v21 )
      v22 = -1;
LABEL_19:
    if ( v22 != 0 )
    {
LABEL_21:
      v24 = v8[1];
      v25 = *(_QWORD *)v8;
      ppVertexBuffers[v4 + 1] = (ID3D10Buffer *)*v8;
      v26 = v8[2];
      *(_QWORD *)&m_pVertexBuffer->m_pBuffer = v25;
      pStrides[v4 + 1] = v24;
      v27 = v8[2];
      v23 = 0;
      ++v30;
      pOffsets[v4 + 1] = v26;
      m_pVertexBuffer->m_nOffset = v27;
    }
    else
    {
      v23 = 1;
    }
    if ( nFirstBuffer_3 != 0 )
    {
      if ( v23 == 0 )
      {
        v5 = v4;
        nFirstBuffer_3 = 0;
        nBufferCount = v4;
      }
    }
    else if ( v23 != 0 )
    {
      nFirstBuffer_3 = 1;
      pDevice->IASetVertexBuffers(
        this: pDevice,
        a2: v5,
        a3: v30,
        a4: &ppVertexBuffers[v5 + 1],
        a5: &pStrides[v5 + 1],
        a6: &pOffsets[v5 + 1]);
      v30 = 0;
    }
    ++v4;
    v31 = ++m_pVertexBuffer;
    if ( v4 >= 16 )
      break;
    v7 = (char *)desiredState - (char *)currentState;
  }
  if ( nFirstBuffer_3 == 0 )
    pDevice->IASetVertexBuffers(
      this: pDevice,
      a2: v5,
      a3: v30,
      a4: &ppVertexBuffers[v5 + 1],
      a5: &pStrides[v5 + 1],
      a6: &pOffsets[v5 + 1]);
}

//------------------------------------------------------------------------------
// Address: 0x1000DB10
// Name: CommitSetRasterState
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommitSetRasterState(
        ID3D10Device *pDevice,
        const ShaderStateDx10_t *desiredState,
        ShaderStateDx10_t *currentState,
        ID3D10RasterizerState *bForce)
{
  ShaderStateDx10_t *v4; // ebp
  ShaderRasterState_t *p_m_RasterState; // edi
  ID3D10RasterizerState *m_pRasterState; // eax
  char v7; // al
  HRESULT (__stdcall *CreateRasterizerState)(ID3D10Device *, const D3D10_RASTERIZER_DESC *, ID3D10RasterizerState **); // eax
  D3D10_RASTERIZER_DESC desc; // [esp+Ch] [ebp-2Ch] BYREF
  int v10; // [esp+34h] [ebp-4h]

  v4 = currentState;
  p_m_RasterState = &desiredState->m_RasterState;
  if ( (_BYTE)bForce == 0 )
  {
    if ( memcmp(&desiredState->m_RasterState, &currentState->m_RasterState, 0xCu) == 0 )
      return;
    v4 = currentState;
  }
  m_pRasterState = v4->m_pRasterState;
  if ( m_pRasterState != nullptr )
    m_pRasterState->Release(this: v4->m_pRasterState);
  desc.CullMode = (p_m_RasterState->m_FillMode != SHADER_FILL_WIREFRAME) + 2;
  v7 = *((_BYTE *)&desiredState->m_RasterState + 8);
  if ( (v7 & 1) != 0 )
    desc.FrontCounterClockwise = 1;
  else
    desc.FrontCounterClockwise = 3 - (desiredState->m_RasterState.m_CullMode != MATERIAL_CULLMODE_CW);
  desc.DepthBias = 1;
  if ( (v7 & 2) == 0 )
    memset(&desc.DepthBiasClamp, 0, 16);
  desc.MultisampleEnable = (v7 & 4) != 0;
  desc.AntialiasedLineEnable = (v7 & 8) != 0;
  CreateRasterizerState = pDevice->CreateRasterizerState;
  v10 = 0;
  bForce = nullptr;
  if ( CreateRasterizerState(this: pDevice, a2: (const D3D10_RASTERIZER_DESC *)&desc.CullMode, a3: &bForce) >= 0 )
    _Warning(a1: "Unable to create rasterizer state object!\n");
  pDevice->RSSetState(this: pDevice, a2: bForce);
  v4->m_pRasterState = bForce;
  *(_QWORD *)&v4->m_RasterState.m_FillMode = *(_QWORD *)&p_m_RasterState->m_FillMode;
  *((_DWORD *)&v4->m_RasterState + 2) = *((_DWORD *)&desiredState->m_RasterState + 2);
}

//------------------------------------------------------------------------------
// Address: 0x1000DCD0
// Name: private: virtual void CShaderAPIDx10::ResetRenderState(bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CShaderAPIDx10::ResetRenderState(CShaderAPIDx10 *this, bool bFullReset)
{
  ID3D10RasterizerState *pRasterizerState; // [esp+30h] [ebp-BCh] BYREF
  ID3D10BlendState *pBlendState; // [esp+34h] [ebp-B8h] BYREF
  float pBlendFactor[4]; // [esp+38h] [ebp-B4h] BYREF
  _BYTE rDesc[164]; // [esp+48h] [ebp-A4h] OVERLAPPED BYREF

  memset(&rDesc[16], 0, 28);
  *(_DWORD *)&rDesc[4] = 3;
  *(_DWORD *)&rDesc[8] = 1;
  *(_DWORD *)&rDesc[12] = 1;
  g_pShaderDeviceDx10->m_pDevice->CreateRasterizerState(
    this: g_pShaderDeviceDx10->m_pDevice,
    a2: (const D3D10_RASTERIZER_DESC *)&rDesc[4],
    a3: (ID3D10RasterizerState **)&pBlendState);
  g_pShaderDeviceDx10->m_pDevice->RSSetState(
    this: g_pShaderDeviceDx10->m_pDevice,
    a2: (ID3D10RasterizerState *)pBlendState);
  memset(dst: &rDesc[112], value: 0, count: 0x34u);
  g_pShaderDeviceDx10->m_pDevice->CreateDepthStencilState(
    this: g_pShaderDeviceDx10->m_pDevice,
    a2: (const D3D10_DEPTH_STENCIL_DESC *)&rDesc[112],
    a3: (ID3D10DepthStencilState **)&pRasterizerState);
  g_pShaderDeviceDx10->m_pDevice->OMSetDepthStencilState(
    this: g_pShaderDeviceDx10->m_pDevice,
    a2: (ID3D10DepthStencilState *)pRasterizerState,
    a3: 0);
  memset(dst: &rDesc[44], value: 0, count: 0x44u);
  *(_DWORD *)&rDesc[80] = 2;
  *(_DWORD *)&rDesc[84] = 1;
  *(_DWORD *)&rDesc[88] = 1;
  *(_DWORD *)&rDesc[92] = 2;
  *(_DWORD *)&rDesc[96] = 1;
  *(_DWORD *)&rDesc[100] = 1;
  rDesc[104] = 15;
  pBlendFactor[1] = 1.0;
  pBlendFactor[2] = 1.0;
  pBlendFactor[3] = 1.0;
  *(_DWORD *)rDesc = 1065353216;
  g_pShaderDeviceDx10->m_pDevice->CreateBlendState(
    this: g_pShaderDeviceDx10->m_pDevice,
    a2: (const D3D10_BLEND_DESC *)&rDesc[44],
    a3: (ID3D10BlendState **)pBlendFactor);
  g_pShaderDeviceDx10->m_pDevice->OMSetBlendState(
    this: g_pShaderDeviceDx10->m_pDevice,
    a2: (ID3D10BlendState *)LODWORD(pBlendFactor[0]),
    a3: &pBlendFactor[1],
    a4: -1u);
}

//------------------------------------------------------------------------------
// Address: 0x1000DE40
// Name: public: virtual void CShaderAPIDx10::GetBackBufferDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::GetBackBufferDimensions(CShaderAPIDx10 *this, int *nWidth, int *nHeight)
{
  g_pShaderDeviceDx10->GetBackBufferDimensions(this: g_pShaderDeviceDx10, a2: nWidth, a3: nHeight);
}

//------------------------------------------------------------------------------
// Address: 0x1000DE50
// Name: public: virtual void CShaderAPIDx10::GetCurrentRenderTargetDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::GetCurrentRenderTargetDimensions(CShaderAPIDx10 *this, int *nWidth, int *nHeight)
{
  ITexture *v4; // eax
  ITexture *v5; // edi

  v4 = this->GetRenderTargetEx(this, a2: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    *nWidth = v4->GetActualWidth(this: v4);
    *nHeight = v5->GetActualHeight(this: v5);
  }
  else
  {
    this->GetBackBufferDimensions(this, a2: nWidth, a3: nHeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DEA0
// Name: public: virtual void CShaderAPIDx10::GetCurrentViewport(int __near &,int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::GetCurrentViewport(CShaderAPIDx10 *this, int *nX, int *nY, int *nWidth, int *nHeight)
{
  int (__thiscall *GetViewports)(struct CShaderAPIDx10 *, ShaderViewport_t *, int); // eax
  ShaderViewport_t viewport; // [esp+0h] [ebp-20h] BYREF

  GetViewports = this->GetViewports;
  viewport.m_nTopLeftX = 1;
  GetViewports(this, a2: (ShaderViewport_t *)&viewport.m_nTopLeftX, a3: 1);
  *nX = viewport.m_nTopLeftY;
  *nY = viewport.m_nWidth;
  *nWidth = viewport.m_nHeight;
  *nHeight = LODWORD(viewport.m_flMinZ);
}

//------------------------------------------------------------------------------
// Address: 0x1000DEF0
// Name: public: virtual int CShaderAPIDx10::GetViewports(struct ShaderViewport_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIDx10::GetViewports(CShaderAPIDx10 *this, ShaderViewport_t *pViewports, int nMax)
{
  int m_nViewportCount; // esi

  m_nViewportCount = this->m_DesiredState.m_nViewportCount;
  if ( pViewports != nullptr && nMax != 0 )
  {
    if ( m_nViewportCount >= nMax )
      m_nViewportCount = nMax;
    memcpy(
      dst: (unsigned __int8 *)pViewports,
      src: (unsigned __int8 *)this->m_DesiredState.m_pViewports,
      count: 28 * m_nViewportCount);
  }
  return m_nViewportCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF30
// Name: public: virtual void CShaderAPIDx10::ClearColor3ub(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::ClearColor3ub(
        CShaderAPIDx10 *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  this->m_DesiredState.m_ClearColor[0] = (float)r * 0.0039215689;
  this->m_DesiredState.m_ClearColor[1] = (float)g * 0.0039215689;
  this->m_DesiredState.m_ClearColor[2] = (float)b * 0.0039215689;
  this->m_DesiredState.m_ClearColor[3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF90
// Name: public: virtual void CShaderAPIDx10::ClearColor4ub(unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::ClearColor4ub(
        CShaderAPIDx10 *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a)
{
  this->m_DesiredState.m_ClearColor[0] = (float)r * 0.0039215689;
  this->m_DesiredState.m_ClearColor[1] = (float)g * 0.0039215689;
  this->m_DesiredState.m_ClearColor[2] = (float)b * 0.0039215689;
  this->m_DesiredState.m_ClearColor[3] = (float)a * 0.0039215689;
}

//------------------------------------------------------------------------------
// Address: 0x1000DFF0
// Name: public: virtual void CShaderAPIDx10::ClearBuffers(bool,bool,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::ClearBuffers(
        CShaderAPIDx10 *this,
        bool bClearColor,
        bool bClearDepth,
        bool bClearStencil,
        int renderTargetWidth,
        int renderTargetHeight)
{
  if ( bClearColor )
    g_pShaderDeviceDx10->m_pDevice->ClearRenderTargetView(
      this: g_pShaderDeviceDx10->m_pDevice,
      a2: g_pShaderDeviceDx10->m_pRenderTargetView,
      a3: this->m_DesiredState.m_ClearColor);
}

//------------------------------------------------------------------------------
// Address: 0x1000E020
// Name: private: virtual short CShaderAPIDx10::TakeSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIDx10::TakeSnapshot(CShaderAPIDx10 *this)
{
  int result; // eax

  result = g_pShaderShadowDx10->m_IsTranslucent;
  if ( g_pShaderShadowDx10->m_IsAlphaTested )
    result |= 2u;
  if ( g_pShaderShadowDx10->m_bUsesVertexAndPixelShaders )
    result |= 4u;
  if ( g_pShaderShadowDx10->m_bIsDepthWriteEnabled )
    return result | 8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E050
// Name: private: virtual bool CShaderAPIDx10::IsTranslucent(short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIDx10::IsTranslucent(CShaderAPIDx10 *this, __int16 id)
{
  return id & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E060
// Name: private: virtual bool CShaderAPIDx10::IsAlphaTested(short)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShaderAPIDx10::IsAlphaTested(CShaderAPIDx10 *this, __int16 id)
{
  return (id & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E070
// Name: private: virtual bool CShaderAPIDx10::IsDepthWriteEnabled(short)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShaderAPIDx10::IsDepthWriteEnabled(CShaderAPIDx10 *this, __int16 id)
{
  return (id & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E080
// Name: private: virtual bool CShaderAPIDx10::UsesVertexAndPixelShaders(short)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShaderAPIDx10::UsesVertexAndPixelShaders(CShaderAPIDx10 *this, __int16 id)
{
  return (id & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E090
// Name: private: virtual unsigned __int64 CShaderAPIDx10::ComputeVertexUsage(int,short __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CShaderAPIDx10::ComputeVertexUsage(CShaderAPIDx10 *this, int numSnapshots, __int16 *pIds)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E0B0
// Name: private: virtual class IMesh __near * CShaderAPIDx10::GetDynamicMesh(class IMaterial __near *,int,bool,class IMesh __near *,class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
CMeshDx10 *__thiscall CShaderAPIDx10::GetDynamicMesh(
        CShaderAPIDx10 *this,
        IMaterial *pMaterial,
        int nHWSkinBoneCount,
        bool buffered,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride)
{
  return &this->m_Mesh;
}

//------------------------------------------------------------------------------
// Address: 0x1000E0C0
// Name: private: virtual class IMesh __near * CShaderAPIDx10::GetDynamicMeshEx(class IMaterial __near *,unsigned __int64,int,bool,class IMesh __near *,class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
CMeshDx10 *__thiscall CShaderAPIDx10::GetDynamicMeshEx(
        CShaderAPIDx10 *this,
        IMaterial *pMaterial,
        unsigned __int64 fmt,
        int nHWSkinBoneCount,
        bool buffered,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride)
{
  return &this->m_Mesh;
}

//------------------------------------------------------------------------------
// Address: 0x1000E0D0
// Name: private: virtual class IMesh __near * CShaderAPIDx10::GetFlexMesh(void)
// Source: json
//------------------------------------------------------------------------------
CMeshDx10 *__thiscall CShaderAPIDx10::GetFlexMesh(CShaderAPIDx10 *this)
{
  return &this->m_Mesh;
}

//------------------------------------------------------------------------------
// Address: 0x1000E0E0
// Name: private: virtual void CShaderAPIDx10::Ortho(double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::Ortho(
        CShaderAPIDx10 *this,
        long double left,
        long double top,
        long double right,
        long double bottom,
        long double zNear,
        long double zFar)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000E0F0
// Name: private: virtual void CShaderAPIDx10::PerspectiveX(double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::PerspectiveX(
        CShaderAPIDx10 *this,
        long double fovx,
        long double aspect,
        long double zNear,
        long double zFar)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000E100
// Name: private: virtual void CShaderAPIDx10::PerspectiveOffCenterX(double,double,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::PerspectiveOffCenterX(
        CShaderAPIDx10 *this,
        long double fovx,
        long double aspect,
        long double zNear,
        long double zFar,
        long double bottom,
        long double top,
        long double left,
        long double right)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000E110
// Name: private: virtual enum ImageFormat CShaderAPIDx10::GetNearestSupportedFormat(enum ImageFormat,bool)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CShaderAPIDx10::GetNearestSupportedFormat(
        CShaderAPIDx10 *this,
        ImageFormat fmt,
        bool bFilteringRequired)
{
  return fmt;
}

//------------------------------------------------------------------------------
// Address: 0x1000E120
// Name: private: virtual enum ImageFormat CShaderAPIDx10::GetNearestRenderTargetFormat(enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CShaderAPIDx10::GetNearestRenderTargetFormat(CShaderAPIDx10 *this, ImageFormat fmt)
{
  return fmt;
}

//------------------------------------------------------------------------------
// Address: 0x1000E130
// Name: private: virtual void CShaderAPIDx10::TexImage2D(int,int,enum ImageFormat,int,int,int,enum ImageFormat,bool,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::TexImage2D(
        CShaderAPIDx10 *this,
        int level,
        int cubeFace,
        ImageFormat dstFormat,
        int zOffset,
        int width,
        int height,
        ImageFormat srcFormat,
        bool bSrcIsTiled,
        void *imageData)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000E140
// Name: private: virtual void CShaderAPIDx10::TexSubImage2D(int,int,int,int,int,int,int,enum ImageFormat,int,bool,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::TexSubImage2D(
        CShaderAPIDx10 *this,
        int level,
        int cubeFace,
        int xOffset,
        int yOffset,
        int zOffset,
        int width,
        int height,
        ImageFormat srcFormat,
        int srcStride,
        bool bSrcIsTiled,
        void *imageData)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000E150
// Name: private: virtual bool CShaderAPIDx10::TexLock(int,int,int,int,int,int,class CPixelWriter __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderAPIDx10::TexLock(
        CShaderAPIDx10 *this,
        int level,
        int cubeFaceID,
        int xOffset,
        int yOffset,
        int width,
        int height,
        CPixelWriter *writer)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1000E160
// Name: private: virtual int CShaderAPIDx10::CreateTexture(int,int,int,enum ImageFormat,int,int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CShaderAPIDx10::CreateTexture(
        CShaderAPIDx10 *this,
        int width,
        int height,
        int depth,
        ImageFormat dstImageFormat,
        int numMipLevels,
        int numCopies,
        int flags,
        const char *pDebugName,
        const char *pTextureGroupName)
{
  this->CreateTextures(
    this,
    a2: (int *)&pTextureGroupName,
    a3: 1,
    a4: width,
    a5: height,
    a6: depth,
    a7: dstImageFormat,
    a8: numMipLevels,
    a9: numCopies,
    a10: flags,
    a11: pDebugName,
    a12: pTextureGroupName);
  return pTextureGroupName;
}

//------------------------------------------------------------------------------
// Address: 0x1000E1B0
// Name: private: virtual void CShaderAPIDx10::CreateTextures(int __near *,int,int,int,int,enum ImageFormat,int,int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::CreateTextures(
        CShaderAPIDx10 *this,
        int *pHandles,
        int count,
        int width,
        int height,
        int depth,
        ImageFormat dstImageFormat,
        int numMipLevels,
        int numCopies,
        int flags,
        const char *pDebugName,
        const char *pTextureGroupName)
{
  if ( count > 0 )
    memset(pHandles, 0, 4 * count);
}

//------------------------------------------------------------------------------
// Address: 0x1000E200
// Name: private: virtual double CShaderAPIDx10::CurrentTime(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
long double __thiscall CShaderAPIDx10::CurrentTime(CShaderAPIDx10 *this)
{
  return _Plat_FloatTime(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000E210
// Name: public: void CFunctionCommit::CallCommitFuncs(struct ID3D10Device __near *,struct ShaderStateDx10_t const __near &,struct ShaderStateDx10_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctionCommit::CallCommitFuncs(
        CFunctionCommit *this,
        ID3D10Device *pDevice,
        const ShaderStateDx10_t *desiredState,
        ShaderStateDx10_t *currentState,
        BOOL bForce)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_CommitFuncs.m_Size;
  for ( i = 0; i < m_Size; ++i )
    this->m_CommitFuncs.m_Memory.m_pMemory[i](a1: pDevice, a2: desiredState, a3: currentState, a4: bForce);
  memset(dst: this->m_pCommitFlags, value: 0, count: this->m_nCommitBufferSize);
  this->m_CommitFuncs.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E270
// Name: public: void CShaderAPIDx10::Unbind(struct VertexShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::Unbind(CShaderAPIDx10 *this, ID3D10VertexShader **hShader)
{
  ID3D10VertexShader *v3; // edi

  if ( hShader != nullptr )
    v3 = *hShader;
  else
    v3 = nullptr;
  if ( this->m_DesiredState.m_pVertexShader == v3 )
    this->BindVertexShader(this, a2: nullptr);
  if ( this->m_CurrentState.m_pVertexShader == v3 && !g_pShaderDevice->IsDeactivated(this: g_pShaderDevice) )
    CFunctionCommit::CallCommitFuncs(
      this: &this->m_Commit,
      pDevice: g_pShaderDeviceDx10->m_pDevice,
      desiredState: &this->m_DesiredState,
      currentState: &this->m_CurrentState,
      bForce: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000E2E0
// Name: public: void CShaderAPIDx10::Unbind(struct GeometryShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::Unbind(CShaderAPIDx10 *this, ID3D10GeometryShader **hShader)
{
  ID3D10GeometryShader *v3; // edi

  if ( hShader != nullptr )
    v3 = *hShader;
  else
    v3 = nullptr;
  if ( this->m_DesiredState.m_pGeometryShader == v3 )
    this->BindGeometryShader(this, a2: nullptr);
  if ( this->m_CurrentState.m_pGeometryShader == v3 && !g_pShaderDevice->IsDeactivated(this: g_pShaderDevice) )
    CFunctionCommit::CallCommitFuncs(
      this: &this->m_Commit,
      pDevice: g_pShaderDeviceDx10->m_pDevice,
      desiredState: &this->m_DesiredState,
      currentState: &this->m_CurrentState,
      bForce: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000E350
// Name: public: void CShaderAPIDx10::Unbind(struct PixelShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::Unbind(CShaderAPIDx10 *this, ID3D10PixelShader **hShader)
{
  ID3D10PixelShader *v3; // edi

  if ( hShader != nullptr )
    v3 = *hShader;
  else
    v3 = nullptr;
  if ( this->m_DesiredState.m_pPixelShader == v3 )
    this->BindPixelShader(this, a2: nullptr);
  if ( this->m_CurrentState.m_pPixelShader == v3 && !g_pShaderDevice->IsDeactivated(this: g_pShaderDevice) )
    CFunctionCommit::CallCommitFuncs(
      this: &this->m_Commit,
      pDevice: g_pShaderDeviceDx10->m_pDevice,
      desiredState: &this->m_DesiredState,
      currentState: &this->m_CurrentState,
      bForce: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000E3C0
// Name: public: void CShaderAPIDx10::UnbindVertexBuffer(struct ID3D10Buffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::UnbindVertexBuffer(CShaderAPIDx10 *this, ID3D10Buffer *pBuffer)
{
  int v3; // esi
  ShaderVertexBufferStateDx10_t *m_pVertexBuffer; // ebx
  int v5; // eax
  ShaderVertexBufferStateDx10_t *i; // ecx

  v3 = 0;
  m_pVertexBuffer = this->m_DesiredState.m_pVertexBuffer;
  do
  {
    if ( m_pVertexBuffer->m_pBuffer == pBuffer )
      ((void (__thiscall *)(CShaderAPIDx10 *, int, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD))this->BindVertexBuffer)(
        a1: this,
        a2: v3,
        a3: 0,
        a4: 0,
        a5: 0,
        a6: 0,
        a7: 1,
        a8: 0,
        a9: 0);
    ++v3;
    ++m_pVertexBuffer;
  }
  while ( v3 < 16 );
  v5 = 0;
  for ( i = this->m_CurrentState.m_pVertexBuffer; i->m_pBuffer != pBuffer; ++i )
  {
    if ( ++v5 >= 16 )
      return;
  }
  if ( !g_pShaderDevice->IsDeactivated(this: g_pShaderDevice) )
    CFunctionCommit::CallCommitFuncs(
      this: &this->m_Commit,
      pDevice: g_pShaderDeviceDx10->m_pDevice,
      desiredState: &this->m_DesiredState,
      currentState: &this->m_CurrentState,
      bForce: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000E460
// Name: public: void CShaderAPIDx10::UnbindIndexBuffer(struct ID3D10Buffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::UnbindIndexBuffer(CShaderAPIDx10 *this, ID3D10Buffer *pBuffer)
{
  if ( this->m_DesiredState.m_IndexBuffer.m_pBuffer == pBuffer )
    this->BindIndexBuffer(this, a2: nullptr, a3: 0);
  if ( this->m_CurrentState.m_IndexBuffer.m_pBuffer == pBuffer && !g_pShaderDevice->IsDeactivated(this: g_pShaderDevice) )
    CFunctionCommit::CallCommitFuncs(
      this: &this->m_Commit,
      pDevice: g_pShaderDeviceDx10->m_pDevice,
      desiredState: &this->m_DesiredState,
      currentState: &this->m_CurrentState,
      bForce: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000E4C0
// Name: public: CShaderAPIDx10::CShaderAPIDx10(void)
// Source: json
//------------------------------------------------------------------------------
CShaderAPIDx10 *__thiscall CShaderAPIDx10::CShaderAPIDx10(CShaderAPIDx10 *this)
{
  unsigned __int8 *v2; // eax
  unsigned int m_nCommitBufferSize; // [esp-8h] [ebp-10h]

  CShaderAPIBase::CShaderAPIBase(this);
  this->IDebugTextureInfo::__vftable = (IDebugTextureInfo_vtbl *)&IDebugTextureInfo::`vftable';
  this->CShaderAPIBase::IShaderAPI::IShaderDynamicAPI::__vftable = (CShaderAPIDx10_vtbl *)&CShaderAPIDx10::`vftable'{for `CShaderAPIBase'};
  this->IDebugTextureInfo::__vftable = (IDebugTextureInfo_vtbl *)&CShaderAPIDx10::`vftable'{for `IDebugTextureInfo'};
  CMeshDx10::CMeshDx10(this: &this->m_Mesh);
  this->m_Commit.m_CommitFuncs.m_Memory.m_pMemory = nullptr;
  this->m_Commit.m_CommitFuncs.m_Memory.m_nAllocationCount = 0;
  this->m_Commit.m_CommitFuncs.m_Memory.m_nGrowSize = 0;
  this->m_Commit.m_CommitFuncs.m_Size = 0;
  this->m_Commit.m_CommitFuncs.m_pElements = nullptr;
  this->m_Commit.m_pCommitFlags = nullptr;
  this->m_Commit.m_nCommitBufferSize = 0;
  *((_BYTE *)this + 20) &= ~1u;
  this->m_Commit.m_nCommitBufferSize = 2;
  v2 = (unsigned __int8 *)operator new(nSize: 2u);
  m_nCommitBufferSize = this->m_Commit.m_nCommitBufferSize;
  this->m_Commit.m_pCommitFlags = v2;
  memset(dst: v2, value: 0, count: m_nCommitBufferSize);
  memset(dst: (unsigned __int8 *)&this->m_DesiredState, value: 0, count: sizeof(this->m_DesiredState));
  memset(dst: (unsigned __int8 *)&this->m_CurrentState, value: 0, count: sizeof(this->m_CurrentState));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E550
// Name: public: FlashlightState_t::FlashlightState_t(void)
// Source: json
//------------------------------------------------------------------------------
FlashlightState_t *__thiscall FlashlightState_t::FlashlightState_t(FlashlightState_t *this)
{
  this->m_uberlightState.m_fNearEdge = 2.0;
  this->m_uberlightState.m_fFarEdge = 100.0;
  this->m_uberlightState.m_fCutOn = 10.0;
  this->m_uberlightState.m_fWedge = 0.050000001;
  this->m_uberlightState.m_fHedge = 0.050000001;
  this->m_uberlightState.m_fCutOff = 650.0;
  this->m_uberlightState.m_fWidth = 0.30000001;
  this->m_uberlightState.m_fHeight = 0.30000001;
  this->m_uberlightState.m_fShearx = 0.0;
  this->m_uberlightState.m_fSheary = 0.0;
  this->m_uberlightState.m_fRoundness = 0.80000001;
  *((_BYTE *)this + 149) &= 0xF4u;
  this->m_flShadowMapResolution = 1024.0;
  this->m_flShadowFilterSize = 3.0;
  this->m_flShadowSlopeScaleDepthBias = 16.0;
  this->m_flShadowJitterSeed = 0.0;
  this->m_flShadowAtten = 0.0;
  this->m_flAmbientOcclusion = 0.0;
  this->m_flNoiseStrength = 0.80000001;
  this->m_flFlashlightTime = 0.0;
  this->m_flPlaneOffset = 0.0;
  this->m_bEnableShadows = false;
  this->m_bDrawShadowFrustum = false;
  this->m_flShadowDepthBias = 0.00050000002;
  this->m_nShadowQuality = 0;
  this->m_bShadowHighRes = false;
  this->m_bScissor = false;
  this->m_nLeft = -1;
  this->m_nTop = -1;
  this->m_nRight = -1;
  this->m_nBottom = -1;
  this->m_bVolumetric = false;
  this->m_nNumPlanes = 64;
  this->m_flVolumetricIntensity = 1.0;
  this->m_bOrtho = false;
  this->m_fOrthoLeft = -1.0;
  this->m_fOrthoRight = 1.0;
  this->m_fOrthoTop = -1.0;
  this->m_fOrthoBottom = 1.0;
  this->m_fBrightnessScale = 1.0;
  this->m_pSpotlightTexture = nullptr;
  this->m_pProjectedMaterial = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E6E0
// Name: public: virtual bool CShaderAPIDx10::OnDeviceInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderAPIDx10::OnDeviceInit(CShaderAPIDx10 *this)
{
  this->ResetRenderState(this, a2: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E6F0
// Name: private: virtual bool CShaderAPIDx10::SetMode(void __near *,int,struct ShaderDeviceInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderAPIDx10::SetMode(CShaderAPIDx10 *this, void *hwnd, int nAdapter, const ShaderDeviceInfo_t *info)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E700
// Name: private: virtual bool CShaderAPIDx10::SupportsCSAAMode(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderAPIDx10::SupportsCSAAMode(CShaderAPIDx10 *this, int nNumSamples, int nQualityLevel)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1000E710
// Name: private: virtual void CShaderAPIDx10::Translate(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::Translate(CMeshDx10 *this, int numVerts, int numIndices, const MeshDesc_t *desc)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000E720
// Name: private: virtual struct FlashlightState_t const __near & CShaderAPIDx10::GetFlashlightState(class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
const FlashlightState_t *__thiscall CShaderAPIDx10::GetFlashlightState(CShaderAPIDx10 *this, VMatrix *worldToTexture)
{
  if ( (`CShaderAPIDx10::GetFlashlightState'::`2'::`local static guard' & 1) == 0 )
  {
    `CShaderAPIDx10::GetFlashlightState'::`2'::`local static guard' |= 1u;
    FlashlightState_t::FlashlightState_t(this: &`CShaderAPIDx10::GetFlashlightState'::`2'::blah);
  }
  return &`CShaderAPIDx10::GetFlashlightState'::`2'::blah;
}

//------------------------------------------------------------------------------
// Address: 0x1000E750
// Name: private: virtual struct FlashlightState_t const __near & CShaderAPIDx10::GetFlashlightStateEx(class VMatrix __near &,class ITexture __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const FlashlightState_t *__thiscall CShaderAPIDx10::GetFlashlightStateEx(
        CShaderAPIDx10 *this,
        VMatrix *worldToTexture,
        ITexture **pFlashlightDepthTexture)
{
  if ( (`CShaderAPIDx10::GetFlashlightStateEx'::`2'::`local static guard' & 1) == 0 )
  {
    `CShaderAPIDx10::GetFlashlightStateEx'::`2'::`local static guard' |= 1u;
    FlashlightState_t::FlashlightState_t(this: &`CShaderAPIDx10::GetFlashlightStateEx'::`2'::blah);
  }
  return &`CShaderAPIDx10::GetFlashlightStateEx'::`2'::blah;
}

//------------------------------------------------------------------------------
// Address: 0x1000E780
// Name: private: virtual void CShaderAPIDx10::GetFlashlightShaderInfo(bool __near *,bool __near *,bool __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::GetFlashlightShaderInfo(
        CShaderAPIDx10 *this,
        bool *pShadowsEnabled,
        bool *pUberLight,
        bool *pGlobalLight)
{
  *pShadowsEnabled = false;
  *pUberLight = false;
  if ( pGlobalLight != nullptr )
    *pGlobalLight = false;
}

//------------------------------------------------------------------------------
// Address: 0x1000E7A0
// Name: private: virtual float CShaderAPIDx10::GetFlashlightAmbientOcclusion(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShaderAPIDx10::GetFlashlightAmbientOcclusion(CShaderAPIDx10 *this)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E7B0
// Name: private: virtual void CShaderAPIDx10::CopyRenderTargetToTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::CopyRenderTargetToTexture(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000E7C0
// Name: private: virtual class Vector const __near & CShaderAPIDx10::GetToneMappingScaleLinear(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CShaderAPIDx10::GetToneMappingScaleLinear(CShaderAPIDx10 *this)
{
  if ( (`CShaderAPIDx10::GetToneMappingScaleLinear'::`2'::`local static guard' & 1) == 0 )
    `CShaderAPIDx10::GetToneMappingScaleLinear'::`2'::`local static guard' |= 1u;
  return &`CShaderAPIDx10::GetToneMappingScaleLinear'::`2'::dummy;
}

//------------------------------------------------------------------------------
// Address: 0x1000E7E0
// Name: private: virtual float CShaderAPIDx10::GammaToLinear_HardwareSpecific(float)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShaderAPIDx10::GammaToLinear_HardwareSpecific(CShaderAPIDx10 *this, int parm_number)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E7F0
// Name: public: virtual int CShaderAPIDx10::GetTextureMemoryUsed(enum IDebugTextureInfo::TextureMemoryType)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CShaderAPIDx10::GetTextureMemoryUsed(CShaderAPIDx10 *this, int parm_number)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000E800
// Name: private: virtual class Vector CShaderAPIDx10::GetVectorRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CShaderAPIDx10::GetVectorRenderingParameter(CShaderAPIDx10 *this, Vector *result, int parm_number)
{
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E820
// Name: private: virtual void CShaderAPIDx10::ReadPixels(struct Rect_t __near *,struct Rect_t __near *,unsigned char __near *,enum ImageFormat,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::ReadPixels(
        CBaseMeshDX8 *this,
        int nFirstVertex,
        int nVertexCount,
        int nFirstIndex,
        int nIndexCount,
        MeshDesc_t *desc)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000E830
// Name: private: virtual void CShaderAPIDx10::GetMaxToRender(class IMesh __near *,bool,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::GetMaxToRender(
        CShaderAPIDx10 *this,
        IMesh *pMesh,
        bool bMaxUntilFlush,
        int *pMaxVerts,
        int *pMaxIndices)
{
  *pMaxVerts = 0x8000;
  *pMaxIndices = 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x1000E850
// Name: private: virtual int CShaderAPIDx10::GetMaxVerticesToRender(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIDx10::GetMaxVerticesToRender(CShaderAPIDx10 *this, IMaterial *pMaterial)
{
  return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x1000E860
// Name: private: virtual enum TessellationMode_t CShaderAPIDx10::GetTessellationMode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIDx10::GetTessellationMode(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E870
// Name: private: virtual int CShaderAPIDx10::GetPackedDeformationInformation(int,float __near *,int,int,int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIDx10::GetPackedDeformationInformation(
        CShaderAPIDx10 *this,
        int nMaskOfUnderstoodDeformations,
        float *pConstantValuesOut,
        int nBufferSize,
        int nMaximumDeformations,
        int *pNumDefsOut)
{
  *pNumDefsOut = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E880
// Name: public: virtual float CShaderAPIDx10::GetFarZ(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShaderAPIDx10::GetFarZ(CShaderAPIDx10 *this)
{
  return 1000.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E8F0
// Name: public: virtual void CShaderAPIDx10::SetViewports(int,struct ShaderViewport_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::SetViewports(CShaderAPIDx10 *this, int nCount, const ShaderViewport_t *pViewports)
{
  int v3; // edi
  CShaderAPIDx10 *v4; // ebp
  int v5; // esi
  unsigned int v6; // edx
  int *p_m_nTopLeftY; // ecx
  unsigned int *p_Width; // eax
  double v9; // st7
  int *v10; // ecx
  int v11; // eax
  int v12; // edi
  double v13; // st7
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<void (__cdecl*)(ID3D10Device *,ShaderStateDx10_t const &,ShaderStateDx10_t &,bool),CUtlMemory<void (__cdecl*)(ID3D10Device *,ShaderStateDx10_t const &,ShaderStateDx10_t &,bool),int> > *p_m_CommitFuncs; // esi
  void (__cdecl **m_pMemory)(ID3D10Device *, const ShaderStateDx10_t *, ShaderStateDx10_t *, bool); // ecx
  int v18; // eax
  bool v19; // zf
  void (__cdecl **v20)(ID3D10Device *, const ShaderStateDx10_t *, ShaderStateDx10_t *, bool); // eax

  v3 = nCount;
  v4 = this;
  if ( nCount >= 16 )
    v3 = 16;
  v5 = 0;
  this->m_DesiredState.m_nViewportCount = v3;
  if ( v3 >= 4 )
  {
    v6 = ((unsigned int)(v3 - 4) >> 2) + 1;
    p_m_nTopLeftY = &pViewports->m_nTopLeftY;
    p_Width = &v4->m_DesiredState.m_pViewports[0].Width;
    v5 = 4 * v6;
    do
    {
      *(p_Width - 2) = *(p_m_nTopLeftY - 1);
      *(p_Width - 1) = *p_m_nTopLeftY;
      *p_Width = p_m_nTopLeftY[1];
      p_Width[1] = p_m_nTopLeftY[2];
      p_Width[2] = *((unsigned int *)p_m_nTopLeftY + 3);
      p_Width += 24;
      v9 = *((float *)p_m_nTopLeftY + 4);
      p_m_nTopLeftY += 28;
      --v6;
      *((float *)p_Width - 21) = v9;
      *(p_Width - 20) = *(p_m_nTopLeftY - 22);
      *(p_Width - 19) = *(p_m_nTopLeftY - 21);
      *(p_Width - 18) = *(p_m_nTopLeftY - 20);
      *(p_Width - 17) = *(p_m_nTopLeftY - 19);
      *(p_Width - 16) = *((unsigned int *)p_m_nTopLeftY - 18);
      *(p_Width - 15) = *((unsigned int *)p_m_nTopLeftY - 17);
      *(p_Width - 14) = *(p_m_nTopLeftY - 15);
      *(p_Width - 13) = *(p_m_nTopLeftY - 14);
      *(p_Width - 12) = *(p_m_nTopLeftY - 13);
      *(p_Width - 11) = *(p_m_nTopLeftY - 12);
      *(p_Width - 10) = *((unsigned int *)p_m_nTopLeftY - 11);
      *(p_Width - 9) = *((unsigned int *)p_m_nTopLeftY - 10);
      *(p_Width - 8) = *(p_m_nTopLeftY - 8);
      *(p_Width - 7) = *(p_m_nTopLeftY - 7);
      *(p_Width - 6) = *(p_m_nTopLeftY - 6);
      *(p_Width - 5) = *(p_m_nTopLeftY - 5);
      *(p_Width - 4) = *((unsigned int *)p_m_nTopLeftY - 4);
      *(p_Width - 3) = *((unsigned int *)p_m_nTopLeftY - 3);
    }
    while ( v6 != 0 );
    v4 = this;
  }
  if ( v5 < v3 )
  {
    v10 = &pViewports[v5].m_nTopLeftY;
    v11 = (int)&v4->m_DesiredState.m_pViewports[v5].Width;
    v12 = v3 - v5;
    do
    {
      *(_DWORD *)(v11 - 8) = *(v10 - 1);
      *(_DWORD *)(v11 - 4) = *v10;
      *(_DWORD *)v11 = v10[1];
      *(_DWORD *)(v11 + 4) = v10[2];
      *(float *)(v11 + 8) = *((float *)v10 + 3);
      v11 += 24;
      v13 = *((float *)v10 + 4);
      v10 += 7;
      --v12;
      *(float *)(v11 - 12) = v13;
    }
    while ( v12 != 0 );
  }
  if ( (*v4->m_Commit.m_pCommitFlags & 1) == 0 )
  {
    m_Size = v4->m_Commit.m_CommitFuncs.m_Size;
    m_nAllocationCount = v4->m_Commit.m_CommitFuncs.m_Memory.m_nAllocationCount;
    p_m_CommitFuncs = &v4->m_Commit.m_CommitFuncs;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<void (__cdecl *)(ID3D10Device *,ShaderStateDx10_t const &,ShaderStateDx10_t &,bool),int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v4->m_Commit.m_CommitFuncs,
        num: m_Size - m_nAllocationCount + 1);
    ++v4->m_Commit.m_CommitFuncs.m_Size;
    m_pMemory = p_m_CommitFuncs->m_Memory.m_pMemory;
    v18 = v4->m_Commit.m_CommitFuncs.m_Size - m_Size - 1;
    v19 = v4->m_Commit.m_CommitFuncs.m_Size - m_Size == 1;
    v4->m_Commit.m_CommitFuncs.m_pElements = v4->m_Commit.m_CommitFuncs.m_Memory.m_pMemory;
    if ( v18 >= 0 && !v19 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v18);
    v20 = &p_m_CommitFuncs->m_Memory.m_pMemory[m_Size];
    if ( v20 != nullptr )
      *v20 = CommitSetViewports;
    *v4->m_Commit.m_pCommitFlags |= 1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EA90
// Name: public: virtual void CShaderAPIDx10::SetRasterState(struct ShaderRasterState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::SetRasterState(CShaderAPIDx10 *this, const ShaderRasterState_t *state)
{
  unsigned __int8 *m_pCommitFlags; // edx
  int m_Size; // [esp+0h] [ebp-10h]

  if ( memcmp(state, &this->m_DesiredState.m_RasterState, 0xCu) != 0 )
  {
    m_pCommitFlags = this->m_Commit.m_pCommitFlags;
    this->m_DesiredState.m_RasterState = *state;
    if ( (m_pCommitFlags[1] & 1) == 0 )
    {
      m_Size = this->m_Commit.m_CommitFuncs.m_Size;
      state = (const ShaderRasterState_t *)CommitSetRasterState;
      CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Commit.m_CommitFuncs,
        elem: m_Size,
        src: (CUtlSymbolTable::StringPool_t *const *)&state);
      this->m_Commit.m_pCommitFlags[1] |= 1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EB70
// Name: public: virtual void CShaderAPIDx10::BindVertexShader(struct VertexShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::BindVertexShader(CShaderAPIDx10 *this, VertexShaderHandle_t__ *hVertexShader)
{
  VertexShaderHandle_t__ *v2; // edi
  ID3D10VertexShader *v4; // eax
  int m_Size; // eax
  unsigned __int8 *m_pCommitFlags; // ecx
  int v7; // [esp-8h] [ebp-10h]

  v2 = hVertexShader;
  if ( hVertexShader != nullptr )
    v4 = *(ID3D10VertexShader **)hVertexShader;
  else
    v4 = nullptr;
  if ( (*((_BYTE *)this + 20) & 1) != 0 || this->m_DesiredState.m_pVertexShader != v4 )
  {
    this->m_DesiredState.m_pVertexShader = v4;
    if ( (*this->m_Commit.m_pCommitFlags & 2) == 0 )
    {
      m_Size = this->m_Commit.m_CommitFuncs.m_Size;
      hVertexShader = (VertexShaderHandle_t__ *)CommitSetVertexShader;
      CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Commit.m_CommitFuncs,
        elem: m_Size,
        src: (CUtlSymbolTable::StringPool_t *const *)&hVertexShader);
      *this->m_Commit.m_pCommitFlags |= 2u;
    }
  }
  if ( (*((_BYTE *)this + 20) & 1) != 0 || this->m_DesiredState.m_InputLayout.m_hVertexShader != v2 )
  {
    m_pCommitFlags = this->m_Commit.m_pCommitFlags;
    this->m_DesiredState.m_InputLayout.m_hVertexShader = v2;
    if ( (*m_pCommitFlags & 0x40) == 0 )
    {
      v7 = this->m_Commit.m_CommitFuncs.m_Size;
      hVertexShader = (VertexShaderHandle_t__ *)CommitSetInputLayout;
      CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Commit.m_CommitFuncs,
        elem: v7,
        src: (CUtlSymbolTable::StringPool_t *const *)&hVertexShader);
      *this->m_Commit.m_pCommitFlags |= 0x40u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EC00
// Name: public: virtual void CShaderAPIDx10::BindGeometryShader(struct GeometryShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::BindGeometryShader(CShaderAPIDx10 *this, ID3D10GeometryShader **hGeometryShader)
{
  ID3D10GeometryShader *v3; // eax
  int m_Size; // eax

  if ( hGeometryShader != nullptr )
    v3 = *hGeometryShader;
  else
    v3 = nullptr;
  if ( (*((_BYTE *)this + 20) & 1) != 0 || this->m_DesiredState.m_pGeometryShader != v3 )
  {
    this->m_DesiredState.m_pGeometryShader = v3;
    if ( (*this->m_Commit.m_pCommitFlags & 4) == 0 )
    {
      m_Size = this->m_Commit.m_CommitFuncs.m_Size;
      hGeometryShader = (ID3D10GeometryShader **)CommitSetGeometryShader;
      CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Commit.m_CommitFuncs,
        elem: m_Size,
        src: (CUtlSymbolTable::StringPool_t *const *)&hGeometryShader);
      *this->m_Commit.m_pCommitFlags |= 4u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EC50
// Name: public: virtual void CShaderAPIDx10::BindPixelShader(struct PixelShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::BindPixelShader(CShaderAPIDx10 *this, ID3D10PixelShader **hPixelShader)
{
  ID3D10PixelShader *v3; // eax
  int m_Size; // eax

  if ( hPixelShader != nullptr )
    v3 = *hPixelShader;
  else
    v3 = nullptr;
  if ( (*((_BYTE *)this + 20) & 1) != 0 || this->m_DesiredState.m_pPixelShader != v3 )
  {
    this->m_DesiredState.m_pPixelShader = v3;
    if ( (*this->m_Commit.m_pCommitFlags & 8) == 0 )
    {
      m_Size = this->m_Commit.m_CommitFuncs.m_Size;
      hPixelShader = (ID3D10PixelShader **)CommitSetPixelShader;
      CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Commit.m_CommitFuncs,
        elem: m_Size,
        src: (CUtlSymbolTable::StringPool_t *const *)&hPixelShader);
      *this->m_Commit.m_pCommitFlags |= 8u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ECA0
// Name: public: virtual void CShaderAPIDx10::BindVertexBuffer(int,class IVertexBuffer __near *,int,int,int,unsigned __int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::BindVertexBuffer(
        CShaderAPIDx10 *this,
        int nStreamID,
        IVertexBuffer *pVertexBuffer,
        int nOffsetInBytes,
        int nFirstVertex,
        int nVertexCount,
        unsigned __int64 fmt,
        int nRepetitions)
{
  bool v9; // zf
  unsigned int v10; // edx
  ShaderVertexBufferStateDx10_t *v11; // eax
  int v12; // eax
  unsigned __int64 v13; // [esp-8h] [ebp-1Ch]
  int m_Size; // [esp-8h] [ebp-1Ch]
  int v15; // [esp-8h] [ebp-1Ch]
  ShaderVertexBufferStateDx10_t state; // [esp+4h] [ebp-10h] BYREF
  int v17; // [esp+10h] [ebp-4h]

  if ( pVertexBuffer != nullptr )
  {
    v13 = *(_QWORD *)&pVertexBuffer[4].__vftable;
    state.m_nStride = (unsigned int)pVertexBuffer[2].__vftable;
    state.m_nOffset = CVertexBufferBase::VertexFormatSize(vertexFormat: v13);
  }
  else
  {
    state.m_nStride = 0;
    state.m_nOffset = 0;
  }
  v9 = (*((_BYTE *)this + 20) & 1) == 0;
  v17 = nOffsetInBytes;
  if ( !v9 || memcmp(&this->m_DesiredState.m_pVertexBuffer[nStreamID], &state.m_nStride, 0xCu) != 0 )
  {
    v10 = v17;
    v11 = &this->m_DesiredState.m_pVertexBuffer[nStreamID];
    *(_QWORD *)&v11->m_pBuffer = *(_QWORD *)&state.m_nStride;
    v11->m_nOffset = v10;
    if ( (*this->m_Commit.m_pCommitFlags & 0x10) == 0 )
    {
      m_Size = this->m_Commit.m_CommitFuncs.m_Size;
      pVertexBuffer = (IVertexBuffer *)CommitSetVertexBuffer;
      CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Commit.m_CommitFuncs,
        elem: m_Size,
        src: (CUtlSymbolTable::StringPool_t *const *)&pVertexBuffer);
      *this->m_Commit.m_pCommitFlags |= 0x10u;
    }
  }
  v12 = HIDWORD(fmt);
  if ( (*((_BYTE *)this + 20) & 1) != 0 || this->m_DesiredState.m_InputLayout.m_pVertexDecl[nStreamID] != fmt )
  {
    LODWORD(this->m_DesiredState.m_InputLayout.m_pVertexDecl[nStreamID]) = fmt;
    HIDWORD(this->m_DesiredState.m_InputLayout.m_pVertexDecl[nStreamID]) = v12;
    if ( (*this->m_Commit.m_pCommitFlags & 0x40) == 0 )
    {
      v15 = this->m_Commit.m_CommitFuncs.m_Size;
      pVertexBuffer = (IVertexBuffer *)CommitSetInputLayout;
      CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Commit.m_CommitFuncs,
        elem: v15,
        src: (CUtlSymbolTable::StringPool_t *const *)&pVertexBuffer);
      *this->m_Commit.m_pCommitFlags |= 0x40u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EE30
// Name: public: virtual void CShaderAPIDx10::BindIndexBuffer(class IIndexBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::BindIndexBuffer(CShaderAPIDx10 *this, IIndexBuffer *pIndexBuffer, int nOffsetInBytes)
{
  unsigned int v4; // edx
  bool v5; // zf
  unsigned int v6; // edi
  unsigned __int8 *m_pCommitFlags; // ecx
  int m_Size; // [esp-8h] [ebp-1Ch]
  ShaderIndexBufferStateDx10_t state; // [esp+4h] [ebp-10h] BYREF
  int v10; // [esp+10h] [ebp-4h]

  if ( pIndexBuffer != nullptr )
  {
    v4 = pIndexBuffer[3].__vftable != nullptr ? 42 : 57;
    state.m_Format = (DXGI_FORMAT)pIndexBuffer[2].__vftable;
    state.m_nOffset = v4;
  }
  else
  {
    state.m_Format = DXGI_FORMAT_UNKNOWN;
    state.m_nOffset = 57;
  }
  v5 = (*((_BYTE *)this + 20) & 1) == 0;
  v6 = nOffsetInBytes;
  v10 = nOffsetInBytes;
  if ( !v5
    || ShaderIndexBufferStateDx10_t::operator!=(
         this: &this->m_DesiredState.m_IndexBuffer,
         src: (const ShaderIndexBufferStateDx10_t *)&state.m_Format) != 0 )
  {
    m_pCommitFlags = this->m_Commit.m_pCommitFlags;
    *(_QWORD *)&this->m_DesiredState.m_IndexBuffer.m_pBuffer = *(_QWORD *)&state.m_Format;
    this->m_DesiredState.m_IndexBuffer.m_nOffset = v6;
    if ( (*m_pCommitFlags & 0x20) == 0 )
    {
      m_Size = this->m_Commit.m_CommitFuncs.m_Size;
      pIndexBuffer = (IIndexBuffer *)CommitSetIndexBuffer;
      CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Commit.m_CommitFuncs,
        elem: m_Size,
        src: (CUtlSymbolTable::StringPool_t *const *)&pIndexBuffer);
      *this->m_Commit.m_pCommitFlags |= 0x20u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EED0
// Name: private: void CShaderAPIDx10::SetTopology(enum MaterialPrimitiveType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::SetTopology(
        CShaderAPIDx10 *this,
        void (__cdecl *topology)(ID3D10Device *pDevice, const ShaderStateDx10_t *desiredState, ShaderStateDx10_t *currentState, bool bForce))
{
  D3D10_PRIMITIVE_TOPOLOGY v3; // eax
  int m_Size; // eax

  switch ( (unsigned int)topology )
  {
    case 0u:
      v3 = D3D10_PRIMITIVE_TOPOLOGY_POINTLIST;
      break;
    case 1u:
      v3 = D3D10_PRIMITIVE_TOPOLOGY_LINELIST;
      break;
    case 2u:
      v3 = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
      break;
    case 3u:
      v3 = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
      break;
    case 4u:
      v3 = D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP;
      break;
    default:
      v3 = D3D10_PRIMITIVE_TOPOLOGY_UNDEFINED;
      break;
  }
  if ( (*((_BYTE *)this + 20) & 1) != 0 || this->m_DesiredState.m_Topology != v3 )
  {
    this->m_DesiredState.m_Topology = v3;
    if ( *(char *)this->m_Commit.m_pCommitFlags >= 0 )
    {
      m_Size = this->m_Commit.m_CommitFuncs.m_Size;
      topology = CommitSetTopology;
      CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Commit.m_CommitFuncs,
        elem: m_Size,
        src: (CUtlSymbolTable::StringPool_t *const *)&topology);
      *this->m_Commit.m_pCommitFlags |= 0x80u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EF60
// Name: public: virtual void CShaderAPIDx10::Draw(enum MaterialPrimitiveType_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::Draw(
        CShaderAPIDx10 *this,
        void (__cdecl *primitiveType)(ID3D10Device *pDevice, const ShaderStateDx10_t *desiredState, ShaderStateDx10_t *currentState, bool bForce),
        unsigned int nFirstIndex,
        unsigned int nIndexCount)
{
  CShaderAPIDx10::SetTopology(this, topology: primitiveType);
  if ( !g_pShaderDevice->IsDeactivated(this: g_pShaderDevice) )
    CFunctionCommit::CallCommitFuncs(
      this: &this->m_Commit,
      pDevice: g_pShaderDeviceDx10->m_pDevice,
      desiredState: &this->m_DesiredState,
      currentState: &this->m_CurrentState,
      bForce: false);
  g_pShaderDeviceDx10->m_pDevice->DrawIndexed(
    this: g_pShaderDeviceDx10->m_pDevice,
    a2: nIndexCount,
    a3: nFirstIndex,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100154B0
// Name: private: virtual void CShaderAPIDx10::GetStandardTextureDimensions(int __near *,int __near *,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::GetStandardTextureDimensions(
        CShaderAPIDx10 *this,
        int *pWidth,
        int *pHeight,
        StandardTextureId_t id)
{
  g_pShaderUtil->GetStandardTextureDimensions(this: g_pShaderUtil, a2: pWidth, a3: pHeight, a4: id);
}

//------------------------------------------------------------------------------
// Address: 0x100294C0
// Name: private: virtual void CShaderAPIDx10::BindTexture(enum Sampler_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIDx10::BindTexture(CIndexBufferBase *this, int nIndexCount, const IndexDesc_t *desc)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000DCB0
// Name: __CreateCShaderAPIDx10IShaderAPI_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CShaderAPIDx10 *__cdecl _CreateCShaderAPIDx10IShaderAPI_interface()
{
  return &s_ShaderAPIDx10;
}

//------------------------------------------------------------------------------
// Address: 0x1000DCC0
// Name: __CreateCShaderAPIDx10IDebugTextureInfo_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDebugTextureInfo *__cdecl _CreateCShaderAPIDx10IDebugTextureInfo_interface()
{
  return &s_ShaderAPIDx10.IDebugTextureInfo;
}
