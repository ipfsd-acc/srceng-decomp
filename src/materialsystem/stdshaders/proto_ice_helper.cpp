// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/proto_ice_helper.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10028950
// Name: void InitParamsProtoIce(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct ProtoIceVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsProtoIce(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        ProtoIceVars_t *info)
{
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx
  IMaterialVar *v9; // ecx
  IMaterialVar *v10; // ecx

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
  if ( info->m_nSsBump != -1 )
  {
    v9 = params[info->m_nSsBump];
    if ( !v9->IsDefined(this: v9) )
    {
      v10 = params[info->m_nSsBump];
      v10->SetIntValue(this: v10, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028A10
// Name: void DrawProtoIce(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct ProtoIceVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawProtoIce(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        ProtoIceVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  bool v7; // bl
  bool v8; // al
  unsigned int v9; // edi
  int m_nSsBump; // eax
  unsigned __int8 v11; // dl
  bool v12; // cl
  bool v13; // al
  BOOL v14; // ebx
  BOOL v15; // eax
  BOOL v16; // edi
  bool v17; // al
  BOOL v18; // edi
  BOOL v19; // eax
  CBaseVSShader *v20; // edi
  int (__thiscall *GetCurrentNumBones)(IShaderDynamicAPI *); // edx
  int v22; // eax
  int v23; // edi
  int v24; // ebx
  BOOL v25; // edi
  int m_nBumpmap; // eax
  const VMatrix *v27; // eax
  void (__thiscall *GetWorldSpaceCameraPosition)(IShaderDynamicAPI *, float *); // edx
  const char *v29; // [esp-4h] [ebp-140h]
  VMatrix result; // [esp+Ch] [ebp-130h] BYREF
  VMatrix mView; // [esp+4Ch] [ebp-F0h] BYREF
  VMatrix mProj; // [esp+8Ch] [ebp-B0h] BYREF
  VMatrix mViewProj; // [esp+CCh] [ebp-70h] BYREF
  proto_ice_vs20_Dynamic_Index _vshIndex; // [esp+10Ch] [ebp-30h]
  float vEyePos[4]; // [esp+120h] [ebp-1Ch] BYREF
  int v36; // [esp+130h] [ebp-Ch] BYREF
  int combo_BUMPMAP; // [esp+134h] [ebp-8h]
  bool bFlattenStaticControlFlow; // [esp+13Ah] [ebp-2h]
  bool bHasVertexColor; // [esp+13Bh] [ebp-1h]
  bool bHasVertexAlpha_3; // [esp+153h] [ebp+17h]

  if ( pShaderShadow == nullptr )
  {
    v20 = pShader;
    goto LABEL_37;
  }
  v7 = ((*params)->m_intVal & 0x10) != 0;
  v8 = ((*params)->m_intVal & 0x20) != 0;
  v9 = 1027;
  bHasVertexColor = v7;
  bHasVertexAlpha_3 = v8;
  if ( v7 || v8 )
    v9 = 1031;
  if ( (*((_BYTE *)params[info->m_nBumpmap] + 28) & 0xF) != 3 || (g_pConfig->m_Flags & 0x100) != 0 )
  {
    v11 = 0;
  }
  else
  {
    m_nSsBump = info->m_nSsBump;
    v11 = 1;
    if ( m_nSsBump != -1 && params[m_nSsBump]->m_intVal != 0 )
    {
      combo_BUMPMAP = 2;
      goto LABEL_12;
    }
  }
  combo_BUMPMAP = v11;
LABEL_12:
  pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: v9, a3: 1, a4: nullptr, a5: 0);
  v12 = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
  bFlattenStaticControlFlow = v12;
  v13 = v7 || bHasVertexAlpha_3;
  v14 = v13;
  if ( g_shaderConfigDumpEnable )
  {
    v15 = bHasVertexColor || bHasVertexAlpha_3;
    printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", v15, "bHasVertexColor || bHasVertexAlpha");
    v12 = bFlattenStaticControlFlow;
  }
  v16 = v12;
  if ( g_shaderConfigDumpEnable )
    printf(format: "\n   VS stat var %s = %d (%s)", "FLATTEN_STATIC_CONTROL_FLOW", v12, "bFlattenStaticControlFlow");
  pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "proto_ice_vs20", a3: 80 * (v14 + 2 * v16));
  v17 = bHasVertexColor || bHasVertexAlpha_3;
  v18 = v17;
  if ( g_shaderConfigDumpEnable )
  {
    v19 = bHasVertexColor || bHasVertexAlpha_3;
    printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", v19, "bHasVertexColor || bHasVertexAlpha");
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", combo_BUMPMAP, "combo_BUMPMAP");
  }
  pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "proto_ice_ps20b", a3: 10 * (v18 + 2 * combo_BUMPMAP));
  pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
  pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
  pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
  pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
  pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
  v20 = pShader;
  CBaseShader::PI_BeginCommandBuffer(this: pShader);
  CBaseShader::PI_SetPixelShaderAmbientLightCube(this: pShader, nFirstRegister: 3);
  CBaseShader::PI_SetPixelShaderLocalLighting(this: pShader, nFirstRegister: 9);
  CBaseShader::PI_SetVertexShaderAmbientLightCube(this: pShader);
  CBaseShader::PI_EndCommandBuffer(this: pShader);
LABEL_37:
  if ( pShaderAPI != nullptr )
  {
    GetCurrentNumBones = pShaderAPI->GetCurrentNumBones;
    v36 = 0;
    LOWORD(combo_BUMPMAP) = 0;
    _vshIndex.m_nSKINNING = GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v22 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v22 > 0, v29);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    v23 = v36;
    if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   VS dyn  var %s = %d (%s)", "DYNAMIC_LIGHT", 0, "lightState.HasDynamicLight()");
      v23 = v36;
    }
    if ( g_shaderConfigDumpEnable )
    {
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "STATIC_LIGHT",
        BYTE1(combo_BUMPMAP) != 0,
        "lightState.m_bStaticLight ? 1 : 0");
      v23 = v36;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "NUM_LIGHTS", v36, "lightState.m_nNumLights");
    }
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: _vshIndex.m_nSKINNING + 2 * (vertexCompression + 4 * ((BYTE1(combo_BUMPMAP) != 0) + 2 * v23)));
    pShaderAPI->GetDX9LightState(this: pShaderAPI, a2: (LightState_t *)&v36);
    v24 = v36;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LIGHTS", v36, "lightState.m_nNumLights");
    v25 = (_BYTE)combo_BUMPMAP != 0;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "AMBIENT_LIGHT",
        (_BYTE)combo_BUMPMAP != 0,
        "lightState.m_bAmbientLight ? 1 : 0");
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v25 + v24 + 4 * v25);
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
    v27 = VMatrix::Transpose3x3(this: &mViewProj, &result);
    VMatrix::operator=(this: &mViewProj, mOther: v27);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: (const float *)&mViewProj, a4: 2, a5: false);
    GetWorldSpaceCameraPosition = pShaderAPI->GetWorldSpaceCameraPosition;
    memset(vEyePos, 0, sizeof(vEyePos));
    GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 2, a3: vEyePos, a4: 1, a5: false);
    v20 = pShader;
  }
  CBaseShader::Draw(this: v20, bMakeActualDrawCall: true);
}
