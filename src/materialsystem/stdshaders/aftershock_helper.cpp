// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/aftershock_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10001990
// Name: void InitParamsAftershock(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct AftershockVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsAftershock(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        AftershockVars_t *info)
{
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx
  IMaterialVar *v9; // ecx
  IMaterialVar *v10; // ecx
  IMaterialVar *v11; // ecx
  IMaterialVar *v12; // ecx
  IMaterialVar *v13; // ecx
  IMaterialVar *v14; // ecx

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x200000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x4000);
  if ( info->m_nRefractAmount != -1 )
  {
    v5 = params[info->m_nRefractAmount];
    if ( !v5->IsDefined(this: v5) )
      ((void (__stdcall *)(int))params[info->m_nRefractAmount]->SetFloatValue)(a1: 1036831949);
  }
  if ( info->m_nColorTint != -1 && !params[info->m_nColorTint]->IsDefined(this: params[info->m_nColorTint]) )
    ((void (__thiscall *)(IMaterialVar *, int, int, int, int))params[info->m_nColorTint]->SetVecValue)(
      a1: params[info->m_nColorTint],
      a2: 1065353216,
      a3: 1065353216,
      a4: 1065353216,
      a5: 1065353216);
  if ( info->m_nBumpFrame != -1 )
  {
    v6 = params[info->m_nBumpFrame];
    if ( !v6->IsDefined(this: v6) )
    {
      v7 = params[info->m_nBumpFrame];
      v7->SetIntValue(this: v7, a2: 0);
    }
  }
  if ( info->m_nSilhouetteThickness != -1 )
  {
    v8 = params[info->m_nSilhouetteThickness];
    if ( !v8->IsDefined(this: v8) )
      ((void (__stdcall *)(int))params[info->m_nSilhouetteThickness]->SetFloatValue)(a1: 1045220557);
  }
  if ( info->m_nSilhouetteColor != -1 )
  {
    v9 = params[info->m_nSilhouetteColor];
    if ( !v9->IsDefined(this: v9) )
    {
      v10 = params[info->m_nSilhouetteColor];
      ((void (__thiscall *)(IMaterialVar *, int, int, int, int))v10->SetVecValue)(
        a1: v10,
        a2: 1050253722,
        a3: 1050253722,
        a4: 1056964608,
        a5: 1065353216);
    }
  }
  if ( info->m_nGroundMin != -1 )
  {
    v11 = params[info->m_nGroundMin];
    if ( !v11->IsDefined(this: v11) )
      ((void (__stdcall *)(int))params[info->m_nGroundMin]->SetFloatValue)(a1: -1097229926);
  }
  if ( info->m_nGroundMax != -1 )
  {
    v12 = params[info->m_nGroundMax];
    if ( !v12->IsDefined(this: v12) )
      ((void (__stdcall *)(int))params[info->m_nGroundMax]->SetFloatValue)(a1: -1110651699);
  }
  if ( info->m_nBlurAmount != -1 )
  {
    v13 = params[info->m_nBlurAmount];
    if ( !v13->IsDefined(this: v13) )
      ((void (__stdcall *)(int))params[info->m_nBlurAmount]->SetFloatValue)(a1: 1008981770);
  }
  if ( info->m_nTime != -1 )
  {
    v14 = params[info->m_nTime];
    if ( !v14->IsDefined(this: v14) )
      ((void (__stdcall *)(_DWORD))params[info->m_nTime]->SetFloatValue)(a1: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001BD0
// Name: void InitAftershock(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct AftershockVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitAftershock(CBaseVSShader *pShader, IMaterialVar **params, AftershockVars_t *info)
{
  IMaterialVar *v3; // ecx

  if ( info->m_nBumpmap != -1 )
  {
    v3 = params[info->m_nBumpmap];
    if ( v3->IsDefined(this: v3) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBumpmap, nAdditionalCreationFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001C10
// Name: void DrawAftershock(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct AftershockVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawAftershock(
        int a1@<ebx>,
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        AftershockVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  int m_nBumpmap; // eax
  bool v9; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // eax
  BOOL v11; // ebx
  int v12; // eax
  bool v13; // sf
  IMaterialVar *v14; // ecx
  float x; // xmm0_4
  double v16; // xmm0_8
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v18; // xmm0_4
  void (__thiscall *GetWorldSpaceCameraPosition)(IShaderDynamicAPI *, float *); // edx
  IMaterialVar *v20; // ecx
  float v21; // xmm0_4
  IMaterialVar *v22; // ecx
  float v23; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  Vector4D *p_m_VecVal; // eax
  IMaterialVar *v26; // ecx
  float v27; // xmm0_4
  IMaterialVar *v28; // ecx
  float y; // xmm0_4
  IMaterialVar *v30; // ecx
  float z; // xmm0_4
  IMaterialVar *v32; // ecx
  float v33; // xmm0_4
  void (__thiscall *v34)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v35; // ecx
  float v36; // xmm0_4
  IMaterialVar *v37; // ecx
  float v38; // xmm0_4
  void (__thiscall *v39)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const VMatrix *v40; // eax
  const char *v41; // [esp-4h] [ebp-164h]
  int v42; // [esp+0h] [ebp-160h]
  VMatrix result; // [esp+8h] [ebp-158h] BYREF
  VMatrix mProj; // [esp+48h] [ebp-118h] BYREF
  VMatrix mView; // [esp+88h] [ebp-D8h] BYREF
  VMatrix mViewProj; // [esp+C8h] [ebp-98h] BYREF
  long double v47; // [esp+108h] [ebp-58h]
  float vEyePos[4]; // [esp+110h] [ebp-50h] BYREF
  float vPackedVsConst1[4]; // [esp+120h] [ebp-40h] BYREF
  float vPackedConst9[4]; // [esp+130h] [ebp-30h] BYREF
  float vPackedConst1[4]; // [esp+140h] [ebp-20h] BYREF
  float vPackedConst8[4]; // [esp+150h] [ebp-10h] BYREF
  char bBumpMapping_3; // [esp+17Bh] [ebp+1Bh]

  m_nBumpmap = info->m_nBumpmap;
  if ( m_nBumpmap == -1 || (bBumpMapping_3 = 1, (*((_BYTE *)params[m_nBumpmap] + 28) & 0xF) != 3) )
    bBumpMapping_3 = 0;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "aftershock_vs20", a3: 0);
    v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    SetPixelShader = pShaderShadow->SetPixelShader;
    v42 = 0;
    if ( v9 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "aftershock_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "aftershock_ps20b");
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    CBaseShader::EnableAlphaBlending(this: pShader, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
  }
  if ( pShaderAPI != nullptr )
  {
    v11 = ((int (__thiscall *)(IShaderDynamicAPI *, int))pShaderAPI->GetCurrentNumBones)(a1: pShaderAPI, a2: a1) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v12 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *, int))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0",
              a3: v42);
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v12 > 0, v41);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * v11);
    if ( info->m_nBumpTransform != -1 )
      CBaseVSShader::SetVertexShaderTextureTransform(this: pShader, vertexReg: 49, transformVar: info->m_nBumpTransform);
    v13 = info->m_nTime < 0;
    memset(vPackedVsConst1, 0, sizeof(vPackedVsConst1));
    if ( v13
      || (v14 = params[info->m_nTime], !v14->IsDefined(this: v14))
      || (x = params[info->m_nTime]->m_VecVal.x) <= 0.0 )
    {
      v47 = pShaderAPI->CurrentTime(this: pShaderAPI);
      v16 = v47;
    }
    else
    {
      v16 = x;
    }
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    v18 = v16;
    vPackedVsConst1[0] = v18 - (float)((float)(int)(float)(v18 * 0.001) * 1000.0);
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: vPackedVsConst1, a4: 1, a5: false);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER0,
      a3: TEXTURE_BINDFLAGS_SRGBREAD,
      a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
    if ( bBumpMapping_3 != 0 )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: info->m_nBumpmap,
        nFrameVar: info->m_nBumpFrame);
    GetWorldSpaceCameraPosition = pShaderAPI->GetWorldSpaceCameraPosition;
    memset(vEyePos, 0, sizeof(vEyePos));
    GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 5, a3: vEyePos, a4: 1, a5: false);
    v13 = info->m_nBlurAmount < 0;
    memset(vPackedConst1, 0, sizeof(vPackedConst1));
    if ( v13 || (v20 = params[info->m_nBlurAmount], !v20->IsDefined(this: v20)) )
      v21 = 0.0099999998;
    else
      v21 = params[info->m_nBlurAmount]->m_VecVal.x;
    v13 = info->m_nRefractAmount < 0;
    vPackedConst1[0] = v21;
    if ( v13 || (v22 = params[info->m_nRefractAmount], !v22->IsDefined(this: v22)) )
      v23 = 0.1;
    else
      v23 = params[info->m_nRefractAmount]->m_VecVal.x;
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    vPackedConst1[1] = v23;
    vPackedConst1[3] = vPackedVsConst1[0];
    SetPixelShaderConstant(this: pShaderAPI, a2: 6, a3: vPackedConst1, a4: 1, a5: false);
    if ( info->m_nColorTint >= 0 && params[info->m_nColorTint]->IsDefined(this: params[info->m_nColorTint]) )
      p_m_VecVal = &params[info->m_nColorTint]->m_VecVal;
    else
      p_m_VecVal = (Vector4D *)kDefaultColorTint;
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 7, a3: (const float *)p_m_VecVal, a4: 1, a5: false);
    v13 = info->m_nSilhouetteColor < 0;
    memset(vPackedConst8, 0, sizeof(vPackedConst8));
    if ( v13 || (v26 = params[info->m_nSilhouetteColor], !v26->IsDefined(this: v26)) )
      v27 = 0.30000001;
    else
      v27 = params[info->m_nSilhouetteColor]->m_VecVal.x;
    v13 = info->m_nSilhouetteColor < 0;
    vPackedConst8[0] = v27;
    if ( v13 || (v28 = params[info->m_nSilhouetteColor], !v28->IsDefined(this: v28)) )
      y = 0.30000001;
    else
      y = params[info->m_nSilhouetteColor]->m_VecVal.y;
    v13 = info->m_nSilhouetteColor < 0;
    vPackedConst8[1] = y;
    if ( v13 || (v30 = params[info->m_nSilhouetteColor], !v30->IsDefined(this: v30)) )
      z = 0.5;
    else
      z = params[info->m_nSilhouetteColor]->m_VecVal.z;
    v13 = info->m_nSilhouetteThickness < 0;
    vPackedConst8[2] = z;
    if ( v13 || (v32 = params[info->m_nSilhouetteThickness], !v32->IsDefined(this: v32)) )
      v33 = 0.2;
    else
      v33 = params[info->m_nSilhouetteThickness]->m_VecVal.x;
    v34 = pShaderAPI->SetPixelShaderConstant;
    vPackedConst8[3] = v33;
    v34(this: pShaderAPI, a2: 8, a3: vPackedConst8, a4: 1, a5: false);
    v13 = info->m_nGroundMin < 0;
    memset(vPackedConst9, 0, sizeof(vPackedConst9));
    if ( v13 || (v35 = params[info->m_nGroundMin], !v35->IsDefined(this: v35)) )
      v36 = -0.30000001;
    else
      v36 = params[info->m_nGroundMin]->m_VecVal.x;
    v13 = info->m_nGroundMax < 0;
    vPackedConst9[0] = v36;
    if ( v13 || (v37 = params[info->m_nGroundMax], !v37->IsDefined(this: v37)) )
      v38 = -0.1;
    else
      v38 = params[info->m_nGroundMax]->m_VecVal.x;
    v39 = pShaderAPI->SetPixelShaderConstant;
    vPackedConst9[1] = v38;
    ((void (__thiscall *)(IShaderDynamicAPI *, int, float *, int))v39)(a1: pShaderAPI, a2: 9, a3: vPackedConst9, a4: 1);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_VIEW, a3: (float *)&mView);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_PROJECTION, a3: (float *)&mProj);
    VMatrix::operator*(this: &mView, result: &mViewProj, vm: &mProj);
    v40 = VMatrix::Transpose3x3(this: &mViewProj, &result);
    VMatrix::operator=(this: &mViewProj, mOther: v40);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: (const float *)&mViewProj, a4: 2, a5: false);
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
