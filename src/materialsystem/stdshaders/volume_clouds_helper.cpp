// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/volume_clouds_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100401D0
// Name: void InitParamsVolumeClouds(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct VolumeCloudsVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsVolumeClouds(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        VolumeCloudsVars_t *info)
{
  IMaterialVar *v5; // ecx

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x200000);
  if ( info->m_nTime != -1 )
  {
    v5 = params[info->m_nTime];
    if ( !v5->IsDefined(this: v5) )
      ((void (__stdcall *)(_DWORD))params[info->m_nTime]->SetFloatValue)(a1: 0);
  }
  if ( info->m_nRefractAmount != -1 && !params[info->m_nRefractAmount]->IsDefined(this: params[info->m_nRefractAmount]) )
    ((void (__stdcall *)(int))params[info->m_nRefractAmount]->SetFloatValue)(a1: 1036831949);
}

//------------------------------------------------------------------------------
// Address: 0x10040280
// Name: void InitVolumeClouds(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct VolumeCloudsVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitVolumeClouds(CBaseVSShader *pShader, IMaterialVar **params, VolumeCloudsVars_t *info)
{
  IMaterialVar *v3; // ecx
  IMaterialVar *v4; // ecx
  IMaterialVar *v5; // ecx

  if ( info->m_nTexture1 != -1 )
  {
    v3 = params[info->m_nTexture1];
    if ( v3->IsDefined(this: v3) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nTexture1, nAdditionalCreationFlags: 0x80000);
  }
  if ( info->m_nTexture2 != -1 )
  {
    v4 = params[info->m_nTexture2];
    if ( v4->IsDefined(this: v4) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nTexture2, nAdditionalCreationFlags: 0x80000);
  }
  if ( info->m_nTexture3 != -1 )
  {
    v5 = params[info->m_nTexture3];
    if ( v5->IsDefined(this: v5) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nTexture3, nAdditionalCreationFlags: 0x80000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040310
// Name: void DrawVolumeClouds(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct VolumeCloudsVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawVolumeClouds(
        int a1@<edi>,
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        VolumeCloudsVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  bool v7; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  BOOL v9; // edi
  int v10; // eax
  bool v11; // sf
  IMaterialVar *v12; // ecx
  float x; // xmm0_4
  double v14; // xmm0_8
  float v15; // xmm2_4
  IShaderDynamicAPI_vtbl *v16; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int m_nRefractAmount; // eax
  float v19; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const char *v21; // [esp-4h] [ebp-44h]
  int v22; // [esp+0h] [ebp-40h]
  float vEyePos[4]; // [esp+8h] [ebp-38h] BYREF
  float vPackedConst6[4]; // [esp+18h] [ebp-28h] BYREF
  float vPackedVsConst1[4]; // [esp+28h] [ebp-18h] BYREF
  long double v26; // [esp+38h] [ebp-8h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "volume_clouds_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    SetPixelShader = pShaderShadow->SetPixelShader;
    v22 = 0;
    if ( v7 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "volume_clouds_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "volume_clouds_ps20b");
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    CBaseShader::EnableAlphaBlending(this: pShader, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
  }
  if ( pShaderAPI != nullptr )
  {
    v9 = ((int (__thiscall *)(IShaderDynamicAPI *, int))pShaderAPI->GetCurrentNumBones)(a1: pShaderAPI, a2: a1) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v10 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *, int))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0",
              a3: v22);
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v10 > 0, v21);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * v9);
    v11 = info->m_nTime < 0;
    memset(vPackedVsConst1, 0, sizeof(vPackedVsConst1));
    if ( v11
      || (v12 = params[info->m_nTime], !v12->IsDefined(this: v12))
      || (x = params[info->m_nTime]->m_VecVal.x) <= 0.0 )
    {
      v26 = pShaderAPI->CurrentTime(this: pShaderAPI);
      v14 = v26;
    }
    else
    {
      v14 = x;
    }
    v15 = (float)v14 * 0.064999998;
    v16 = pShaderAPI->__vftable;
    vPackedVsConst1[0] = v15 - (float)((float)((float)(int)(float)(v15 * 0.15915507) * 2.0) * 3.1415901);
    vPackedVsConst1[1] = (float)(v15 * 2.0)
                       - (float)((float)((float)(int)(float)((float)(v15 * 2.0) * 0.15915507) * 2.0) * 3.1415901);
    SetVertexShaderConstant = v16->SetVertexShaderConstant;
    vPackedVsConst1[2] = (float)(v15 * 4.0)
                       - (float)((float)((float)(int)(float)((float)(v15 * 4.0) * 0.15915507) * 2.0) * 3.1415901);
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: vPackedVsConst1, a4: 1, a5: false);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nTexture1,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nTexture2,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nTexture3,
      nFrameVar: -1);
    memset(vEyePos, 0, sizeof(vEyePos));
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 5, a3: vEyePos, a4: 1, a5: false);
    m_nRefractAmount = info->m_nRefractAmount;
    memset(vPackedConst6, 0, sizeof(vPackedConst6));
    if ( m_nRefractAmount >= 0 && params[m_nRefractAmount]->IsDefined(this: params[m_nRefractAmount]) )
      v19 = params[info->m_nRefractAmount]->m_VecVal.x;
    else
      v19 = 0.1;
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    vPackedConst6[0] = v19;
    vPackedConst6[1] = vPackedVsConst1[0];
    ((void (__thiscall *)(IShaderDynamicAPI *, int, float *, int))SetPixelShaderConstant)(
      a1: pShaderAPI,
      a2: 6,
      a3: vPackedConst6,
      a4: 1);
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
