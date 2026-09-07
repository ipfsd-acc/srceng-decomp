// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/renderer/scaleformshaders.cpp
// Functions: 2
// ============================================================

#include "materialsystem\scaleformui\renderer\scaleformshaders.h"

//------------------------------------------------------------------------------
// Address: 0x10004810
// Name: public: void ScaleformRenderer::InitShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::InitShaders(ScaleformRenderer *this)
{
  const _D3DVERTEXELEMENT9 **v2; // edi
  GPtr<IDirect3DVertexDeclaration9> *m_pVertexDecls; // ebx
  const unsigned int *v4; // eax
  const unsigned int *v5; // eax
  const unsigned int *v6; // eax
  const unsigned int *v7; // eax
  const unsigned int *v8; // eax
  const unsigned int *v9; // eax
  const unsigned int *v10; // eax
  const unsigned int *v11; // eax
  const unsigned int *v12; // eax
  struct ID3DXBuffer *v13; // [esp+10h] [ebp-10h] BYREF
  struct ID3DXBuffer *v14; // [esp+14h] [ebp-Ch] BYREF
  int v15; // [esp+18h] [ebp-8h] BYREF
  int v16; // [esp+1Ch] [ebp-4h] BYREF

  v2 = cVertexDeclTypeTable;
  m_pVertexDecls = this->m_pVertexDecls;
  do
    this->m_pDevice->CreateVertexDeclaration(
      this: this->m_pDevice,
      a2: *v2++,
      a3: (IDirect3DVertexDeclaration9 **)m_pVertexDecls++);
  while ( (int)v2 < (int)VertexDeclStrip );
  v14 = nullptr;
  v16 = 0;
  if ( D3DXCompileShader(
         a1: (void *)pVS_StripText,
         a2: strlen(pVS_StripText),
         a3: nullptr,
         a4: nullptr,
         a5: (int)"main",
         a6: (int)"vs_2_0",
         a7: 0,
         a8: (int)&v16,
         a9: &v14,
         a10: 0) >= 0 )
  {
    v4 = (const unsigned int *)(*(int (__stdcall **)(int))(*(_DWORD *)v16 + 12))(a1: v16);
    this->m_pDevice->CreateVertexShader(
      this: this->m_pDevice,
      a2: v4,
      a3: (IDirect3DVertexShader9 **)this->m_pVertexShaders);
    (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(a1: v16);
    v16 = 0;
    if ( v14 != nullptr )
    {
      v14->Release(this: v14);
      v14 = nullptr;
    }
  }
  v13 = nullptr;
  v15 = 0;
  if ( D3DXCompileShader(
         a1: (void *)pVS_GlyphText,
         a2: strlen(pVS_GlyphText),
         a3: nullptr,
         a4: nullptr,
         a5: (int)"main",
         a6: (int)"vs_2_0",
         a7: 0,
         a8: (int)&v15,
         a9: &v13,
         a10: 0) >= 0 )
  {
    v5 = (const unsigned int *)(*(int (__stdcall **)(int))(*(_DWORD *)v15 + 12))(a1: v15);
    this->m_pDevice->CreateVertexShader(
      this: this->m_pDevice,
      a2: v5,
      a3: (IDirect3DVertexShader9 **)&this->m_pVertexShaders[1]);
    (*(void (__stdcall **)(int))(*(_DWORD *)v15 + 8))(a1: v15);
    v15 = 0;
    if ( v13 != nullptr )
    {
      v13->Release(this: v13);
      v13 = nullptr;
    }
  }
  v14 = nullptr;
  v16 = 0;
  if ( D3DXCompileShader(
         a1: (void *)pVS_XY16iC32Text,
         a2: strlen(pVS_XY16iC32Text),
         a3: nullptr,
         a4: nullptr,
         a5: (int)"main",
         a6: (int)"vs_2_0",
         a7: 0,
         a8: (int)&v16,
         a9: &v14,
         a10: 0) >= 0 )
  {
    v6 = (const unsigned int *)(*(int (__stdcall **)(int))(*(_DWORD *)v16 + 12))(a1: v16);
    this->m_pDevice->CreateVertexShader(
      this: this->m_pDevice,
      a2: v6,
      a3: (IDirect3DVertexShader9 **)&this->m_pVertexShaders[2]);
    (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(a1: v16);
    v16 = 0;
    if ( v14 != nullptr )
    {
      v14->Release(this: v14);
      v14 = nullptr;
    }
  }
  v13 = nullptr;
  v15 = 0;
  if ( D3DXCompileShader(
         a1: (void *)pVS_XY16iCF32Text,
         a2: strlen(pVS_XY16iCF32Text),
         a3: nullptr,
         a4: nullptr,
         a5: (int)"main",
         a6: (int)"vs_2_0",
         a7: 0,
         a8: (int)&v15,
         a9: &v13,
         a10: 0) >= 0 )
  {
    v7 = (const unsigned int *)(*(int (__stdcall **)(int))(*(_DWORD *)v15 + 12))(a1: v15);
    this->m_pDevice->CreateVertexShader(
      this: this->m_pDevice,
      a2: v7,
      a3: (IDirect3DVertexShader9 **)&this->m_pVertexShaders[3]);
    (*(void (__stdcall **)(int))(*(_DWORD *)v15 + 8))(a1: v15);
    v15 = 0;
    if ( v13 != nullptr )
    {
      v13->Release(this: v13);
      v13 = nullptr;
    }
  }
  v14 = nullptr;
  v16 = 0;
  if ( D3DXCompileShader(
         a1: (void *)pPS_SolidColorText,
         a2: strlen(pPS_SolidColorText),
         a3: nullptr,
         a4: nullptr,
         a5: (int)"main",
         a6: (int)"ps_2_0",
         a7: 0,
         a8: (int)&v16,
         a9: &v14,
         a10: 0) >= 0 )
  {
    v8 = (const unsigned int *)(*(int (__stdcall **)(int))(*(_DWORD *)v16 + 12))(a1: v16);
    this->m_pDevice->CreatePixelShader(
      this: this->m_pDevice,
      a2: v8,
      a3: (IDirect3DPixelShader9 **)this->m_pPixelShaders);
    (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(a1: v16);
    v16 = 0;
    if ( v14 != nullptr )
    {
      v14->Release(this: v14);
      v14 = nullptr;
    }
  }
  v13 = nullptr;
  v15 = 0;
  if ( D3DXCompileShader(
         a1: (void *)pPS_TextTextureAlphaText,
         a2: strlen(pPS_TextTextureAlphaText),
         a3: nullptr,
         a4: nullptr,
         a5: (int)"main",
         a6: (int)"ps_2_0",
         a7: 0,
         a8: (int)&v15,
         a9: &v13,
         a10: 0) >= 0 )
  {
    v9 = (const unsigned int *)(*(int (__stdcall **)(int))(*(_DWORD *)v15 + 12))(a1: v15);
    this->m_pDevice->CreatePixelShader(
      this: this->m_pDevice,
      a2: v9,
      a3: (IDirect3DPixelShader9 **)&this->m_pPixelShaders[1]);
    (*(void (__stdcall **)(int))(*(_DWORD *)v15 + 8))(a1: v15);
    v15 = 0;
    if ( v13 != nullptr )
    {
      v13->Release(this: v13);
      v13 = nullptr;
    }
  }
  v14 = nullptr;
  v16 = 0;
  if ( D3DXCompileShader(
         a1: (void *)pPS_CxformGauraudText,
         a2: strlen(pPS_CxformGauraudText),
         a3: nullptr,
         a4: nullptr,
         a5: (int)"main",
         a6: (int)"ps_2_0",
         a7: 0,
         a8: (int)&v16,
         a9: &v14,
         a10: 0) >= 0 )
  {
    v10 = (const unsigned int *)(*(int (__stdcall **)(int))(*(_DWORD *)v16 + 12))(a1: v16);
    this->m_pDevice->CreatePixelShader(
      this: this->m_pDevice,
      a2: v10,
      a3: (IDirect3DPixelShader9 **)&this->m_pPixelShaders[2]);
    (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(a1: v16);
    v16 = 0;
    if ( v14 != nullptr )
    {
      v14->Release(this: v14);
      v14 = nullptr;
    }
  }
  v13 = nullptr;
  v15 = 0;
  if ( D3DXCompileShader(
         a1: (void *)pPS_CxformGauraudNoAddAlphaText,
         a2: strlen(pPS_CxformGauraudNoAddAlphaText),
         a3: nullptr,
         a4: nullptr,
         a5: (int)"main",
         a6: (int)"ps_2_0",
         a7: 0,
         a8: (int)&v15,
         a9: &v13,
         a10: 0) >= 0 )
  {
    v11 = (const unsigned int *)(*(int (__stdcall **)(int))(*(_DWORD *)v15 + 12))(a1: v15);
    this->m_pDevice->CreatePixelShader(
      this: this->m_pDevice,
      a2: v11,
      a3: (IDirect3DPixelShader9 **)&this->m_pPixelShaders[3]);
    (*(void (__stdcall **)(int))(*(_DWORD *)v15 + 8))(a1: v15);
    v15 = 0;
    if ( v13 != nullptr )
    {
      v13->Release(this: v13);
      v13 = nullptr;
    }
  }
  v14 = nullptr;
  v16 = 0;
  if ( D3DXCompileShader(
         a1: (void *)pPS_CxformGauraudTextureText,
         a2: strlen(pPS_CxformGauraudTextureText),
         a3: nullptr,
         a4: nullptr,
         a5: (int)"main",
         a6: (int)"ps_2_0",
         a7: 0,
         a8: (int)&v16,
         a9: &v14,
         a10: 0) >= 0 )
  {
    v12 = (const unsigned int *)(*(int (__stdcall **)(int))(*(_DWORD *)v16 + 12))(a1: v16);
    this->m_pDevice->CreatePixelShader(
      this: this->m_pDevice,
      a2: v12,
      a3: (IDirect3DPixelShader9 **)&this->m_pPixelShaders[4]);
    (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(a1: v16);
    v16 = 0;
    if ( v14 != nullptr )
      v14->Release(this: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004CE0
// Name: public: void ScaleformRenderer::ReleaseShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderer::ReleaseShaders(ScaleformRenderer *this)
{
  GPtr<IDirect3DVertexDeclaration9> *m_pVertexDecls; // esi
  int i; // edi
  GPtr<IDirect3DVertexShader9> *m_pVertexShaders; // esi
  int j; // edi
  GPtr<IDirect3DPixelShader9> *m_pPixelShaders; // esi
  int k; // edi

  m_pVertexDecls = this->m_pVertexDecls;
  for ( i = 4; i != 0; --i )
  {
    if ( m_pVertexDecls->pObject != nullptr )
      m_pVertexDecls->pObject->Release(this: m_pVertexDecls->pObject);
    m_pVertexDecls->pObject = nullptr;
    ++m_pVertexDecls;
  }
  m_pVertexShaders = this->m_pVertexShaders;
  for ( j = 4; j != 0; --j )
  {
    if ( m_pVertexShaders->pObject != nullptr )
      m_pVertexShaders->pObject->Release(this: m_pVertexShaders->pObject);
    m_pVertexShaders->pObject = nullptr;
    ++m_pVertexShaders;
  }
  m_pPixelShaders = this->m_pPixelShaders;
  for ( k = 5; k != 0; --k )
  {
    if ( m_pPixelShaders->pObject != nullptr )
      m_pPixelShaders->pObject->Release(this: m_pPixelShaders->pObject);
    m_pPixelShaders->pObject = nullptr;
    ++m_pPixelShaders;
  }
}
