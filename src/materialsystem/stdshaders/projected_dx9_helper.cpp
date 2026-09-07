// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/projected_dx9_helper.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100010C0
// Name: void InitParamsProjected_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct Projected_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsProjected_DX9()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10028250
// Name: void InitProjected_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct Projected_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitProjected_DX9(CBaseVSShader *pShader, IMaterialVar **params, Projected_DX9_Vars_t *info)
{
  IMaterialVar *v3; // ecx

  v3 = params[info->m_nBaseTexture];
  if ( v3->IsDefined(this: v3) )
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10028280
// Name: void DrawProjected_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct Projected_DX9_Vars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawProjected_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        Projected_DX9_Vars_t *info)
{
  bool v5; // bl
  CBaseVSShader *v6; // edi
  bool v7; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  MaterialFogMode_t v9; // eax
  MaterialFogMode_t v10; // eax
  MaterialFogMode_t v11; // eax
  FlashlightState_t *v12; // esi
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v14)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const VMatrix *v15; // eax
  int v16; // [esp+0h] [ebp-274h]
  VMatrix result; // [esp+Ch] [ebp-268h] BYREF
  VMatrix worldToTexture; // [esp+4Ch] [ebp-228h] BYREF
  FlashlightState_t state; // [esp+8Ch] [ebp-1E8h] BYREF
  VMatrix matProj; // [esp+188h] [ebp-ECh] BYREF
  VMatrix matViewProj; // [esp+1C8h] [ebp-ACh] BYREF
  VMatrix matView; // [esp+208h] [ebp-6Ch] BYREF
  Vector4D vLightDir; // [esp+248h] [ebp-2Ch] BYREF
  Vector4D vProjectionSize; // [esp+258h] [ebp-1Ch] BYREF
  LightState_t lightState; // [esp+268h] [ebp-Ch] BYREF
  BOOL v26; // [esp+270h] [ebp-4h]

  v5 = ((*params)->m_intVal & 0x800) != 0;
  v6 = pShader;
  if ( pShaderShadow != nullptr )
  {
    CBaseShader::SetInitialShadowState(this: pShader);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1025u, a3: 0, a4: nullptr, a5: 0);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      *(_DWORD *)&lightState.m_bAmbientLight = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      lightState.m_nNumLights = v5;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "MODEL", v5, "bIsModel");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "projected_vs30",
        a3: 2 * (lightState.m_nNumLights + 2 * *(_DWORD *)&lightState.m_bAmbientLight));
      v16 = 0;
      ((void (__stdcall *)(const char *))pShaderShadow->SetPixelShader)(a1: "projected_ps30");
    }
    else
    {
      *(_DWORD *)&lightState.m_bAmbientLight = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v26 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      lightState.m_nNumLights = v5;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "MODEL", v5, "bIsModel");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "projected_vs20",
        a3: 2 * (lightState.m_nNumLights + 2 * (*(_DWORD *)&lightState.m_bAmbientLight + 2 * v26)));
      v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      SetPixelShader = pShaderShadow->SetPixelShader;
      v16 = 0;
      if ( v7 )
        ((void (__stdcall *)(const char *))SetPixelShader)(a1: "projected_ps20");
      else
        ((void (__stdcall *)(const char *))SetPixelShader)(a1: "projected_ps20b");
    }
    CBaseShader::DefaultFog(this: pShader);
    CBaseShader::SetAdditiveBlendingShadowState(this: pShader, textureVar: info->m_nBaseTexture, isBaseTexture: true);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
    CBaseShader::PI_BeginCommandBuffer(this: pShader);
    CBaseShader::PI_SetPixelShaderAmbientLightCube(this: pShader, nFirstRegister: 4);
    CBaseShader::PI_SetPixelShaderLocalLighting(this: pShader, nFirstRegister: 20);
    CBaseShader::PI_EndCommandBuffer(this: pShader);
  }
  if ( pShaderAPI != nullptr )
  {
    ((void (__thiscall *)(IShaderDynamicAPI *, int))pShaderAPI->SetDefaultState)(a1: pShaderAPI, a2: v16);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nBaseTexture,
      nFrameVar: -1);
    pShaderAPI->GetDX9LightState(this: pShaderAPI, a2: (LightState_t *)&lightState.m_bAmbientLight);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      v10 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v10 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    }
    else
    {
      v9 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v9 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
      g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    }
    v11 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v11 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    CBaseVSShader::SetVertexShaderTextureTransform(
      this: pShader,
      vertexReg: 54,
      transformVar: info->m_nBaseTextureTransform);
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
    v12 = pShaderAPI->GetFlashlightState(this: pShaderAPI, a2: &worldToTexture);
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    state = *v12;
    vLightDir.x = state.m_vecLightOrigin.x;
    vLightDir.y = state.m_vecLightOrigin.y;
    vLightDir.z = state.m_vecLightOrigin.z;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: &vLightDir.x, a4: 1, a5: false);
    v14 = pShaderAPI->SetVertexShaderConstant;
    vProjectionSize.x = state.m_flProjectionSize;
    vProjectionSize.y = state.m_flProjectionRotation;
    vProjectionSize.z = 0.0;
    vProjectionSize.w = 0.0;
    v14(this: pShaderAPI, a2: 49, a3: &vProjectionSize.x, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 28, a3: state.m_Color, a4: 1, a5: false);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_VIEW, a3: (float *)&matView);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_PROJECTION, a3: (float *)&matProj);
    v15 = VMatrix::operator*(this: &matView, &result, vm: &matProj);
    VMatrix::operator=(this: &matViewProj, mOther: v15);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: (const float *)&matViewProj, a4: 2, a5: false);
    v6 = pShader;
  }
  CBaseShader::Draw(this: v6, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _calloc_crt(unsigned int count, unsigned int size)
{
  unsigned __int8 *v2; // edi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * count);
  memset(dst: v2, value: 0, count: size * count);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10001050
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: v3, value: 0, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001090
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x100010B0
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100010D0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
