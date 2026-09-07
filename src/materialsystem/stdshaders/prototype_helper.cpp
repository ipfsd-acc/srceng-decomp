// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/prototype_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100291B0
// Name: void InitParamsPrototype(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct PrototypeVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsPrototype(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        PrototypeVars_t *info)
{
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  if ( info->m_nBaseTextureFrame != -1 )
  {
    v5 = params[info->m_nBaseTextureFrame];
    if ( !v5->IsDefined(this: v5) )
    {
      v6 = params[info->m_nBaseTextureFrame];
      v6->SetIntValue(this: v6, a2: 0);
    }
  }
  if ( info->m_nBumpFrame != -1 )
  {
    v7 = params[info->m_nBumpFrame];
    if ( !v7->IsDefined(this: v7) )
    {
      v8 = params[info->m_nBumpFrame];
      v8->SetIntValue(this: v8, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029250
// Name: void InitPrototype(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct PrototypeVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPrototype(CBaseVSShader *pShader, IMaterialVar **params, ProtoIceVars_t *info)
{
  IMaterialVar *v3; // ecx

  if ( info->m_nBaseTexture != -1 && params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0);
  if ( info->m_nBumpmap != -1 )
  {
    v3 = params[info->m_nBumpmap];
    if ( v3->IsDefined(this: v3) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBumpmap, nAdditionalCreationFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100292B0
// Name: void DrawPrototype(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct PrototypeVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawPrototype(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        PrototypeVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  bool v7; // bl
  unsigned int v8; // ecx
  bool v9; // cl
  bool v10; // al
  BOOL v11; // eax
  BOOL v12; // edi
  bool v13; // al
  BOOL v14; // edi
  BOOL v15; // eax
  CBaseVSShader *v16; // edi
  int (__thiscall *GetCurrentNumBones)(IShaderDynamicAPI *); // edx
  int v18; // eax
  int m_nNumLights; // edi
  int v20; // ebx
  BOOL m_bAmbientLight; // edi
  int m_nBumpmap; // eax
  const VMatrix *v23; // eax
  void (__thiscall *GetWorldSpaceCameraPosition)(IShaderDynamicAPI *, float *); // edx
  const char *v25; // [esp-4h] [ebp-140h]
  VMatrix result; // [esp+Ch] [ebp-130h] BYREF
  VMatrix mView; // [esp+4Ch] [ebp-F0h] BYREF
  VMatrix mProj; // [esp+8Ch] [ebp-B0h] BYREF
  VMatrix mViewProj; // [esp+CCh] [ebp-70h] BYREF
  prototype_vs20_Dynamic_Index _vshIndex; // [esp+10Ch] [ebp-30h]
  float vEyePos[4]; // [esp+120h] [ebp-1Ch] BYREF
  LightState_t lightState; // [esp+130h] [ebp-Ch] BYREF
  bool bFlattenStaticControlFlow; // [esp+13Bh] [ebp-1h]
  bool bHasVertexAlpha_3; // [esp+153h] [ebp+17h]

  if ( pShaderShadow != nullptr )
  {
    v7 = ((*params)->m_intVal & 0x10) != 0;
    v8 = 1027;
    bHasVertexAlpha_3 = ((*params)->m_intVal & 0x20) != 0;
    if ( ((*params)->m_intVal & 0x10) != 0 || ((*params)->m_intVal & 0x20) != 0 )
      v8 = 1031;
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: v8, a3: 1, a4: nullptr, a5: 0);
    v9 = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
    bFlattenStaticControlFlow = v9;
    v10 = v7 || bHasVertexAlpha_3;
    lightState.m_nNumLights = v10;
    if ( g_shaderConfigDumpEnable )
    {
      v11 = v7 || bHasVertexAlpha_3;
      printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", v11, "bHasVertexColor || bHasVertexAlpha");
      v9 = bFlattenStaticControlFlow;
    }
    v12 = v9;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "FLATTEN_STATIC_CONTROL_FLOW", v9, "bFlattenStaticControlFlow");
    pShaderShadow->SetVertexShader(
      this: pShaderShadow,
      a2: "prototype_vs20",
      a3: 80 * (lightState.m_nNumLights + 2 * v12));
    v13 = v7 || bHasVertexAlpha_3;
    v14 = v13;
    if ( g_shaderConfigDumpEnable )
    {
      v15 = v7 || bHasVertexAlpha_3;
      printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", v15, "bHasVertexColor || bHasVertexAlpha");
    }
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "prototype_ps20b", a3: 10 * v14);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    v16 = pShader;
    CBaseShader::PI_BeginCommandBuffer(this: pShader);
    CBaseShader::PI_SetPixelShaderAmbientLightCube(this: pShader, nFirstRegister: 3);
    CBaseShader::PI_SetPixelShaderLocalLighting(this: pShader, nFirstRegister: 9);
    CBaseShader::PI_SetVertexShaderAmbientLightCube(this: pShader);
    CBaseShader::PI_EndCommandBuffer(this: pShader);
  }
  else
  {
    v16 = pShader;
  }
  if ( pShaderAPI != nullptr )
  {
    GetCurrentNumBones = pShaderAPI->GetCurrentNumBones;
    lightState.m_nNumLights = 0;
    *(_WORD *)&lightState.m_bAmbientLight = 0;
    _vshIndex.m_nSKINNING = GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v18 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v18 > 0, v25);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    m_nNumLights = lightState.m_nNumLights;
    if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   VS dyn  var %s = %d (%s)", "DYNAMIC_LIGHT", 0, "lightState.HasDynamicLight()");
      m_nNumLights = lightState.m_nNumLights;
    }
    if ( g_shaderConfigDumpEnable )
    {
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "STATIC_LIGHT",
        lightState.m_bStaticLight,
        "lightState.m_bStaticLight ? 1 : 0");
      m_nNumLights = lightState.m_nNumLights;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          lightState.m_nNumLights,
          "lightState.m_nNumLights");
    }
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: _vshIndex.m_nSKINNING + 2 * (vertexCompression + 4 * (lightState.m_bStaticLight + 2 * m_nNumLights)));
    pShaderAPI->GetDX9LightState(this: pShaderAPI, a2: &lightState);
    v20 = lightState.m_nNumLights;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LIGHTS", lightState.m_nNumLights, "lightState.m_nNumLights");
    m_bAmbientLight = lightState.m_bAmbientLight;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "AMBIENT_LIGHT",
        lightState.m_bAmbientLight,
        "lightState.m_bAmbientLight ? 1 : 0");
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: m_bAmbientLight + v20 + 4 * m_bAmbientLight);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nBaseTexture,
      nFrameVar: info->m_nBaseTextureFrame);
    m_nBumpmap = info->m_nBumpmap;
    if ( m_nBumpmap != -1 && (*((_BYTE *)params[m_nBumpmap] + 28) & 0xF) == 3 )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: m_nBumpmap,
        nFrameVar: info->m_nBumpFrame);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_VIEW, a3: (float *)&mView);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_PROJECTION, a3: (float *)&mProj);
    VMatrix::operator*(this: &mView, result: &mViewProj, vm: &mProj);
    v23 = VMatrix::Transpose3x3(this: &mViewProj, &result);
    VMatrix::operator=(this: &mViewProj, mOther: v23);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: (const float *)&mViewProj, a4: 2, a5: false);
    GetWorldSpaceCameraPosition = pShaderAPI->GetWorldSpaceCameraPosition;
    memset(vEyePos, 0, sizeof(vEyePos));
    GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 2, a3: vEyePos, a4: 1, a5: false);
    v16 = pShader;
  }
  CBaseShader::Draw(this: v16, bMakeActualDrawCall: true);
}
