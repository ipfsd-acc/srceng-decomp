// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/lightmappedpaint_dx9_helper.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1001A4C0
// Name: void DrawLightmappedPaint_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct LightmappedGeneric_DX9_Vars_t __near &,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawLightmappedPaint_DX9(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        LightmappedGeneric_DX9_Vars_t *info,
        CBasePerMaterialContextData **pContextDataPtr)
{
  CBasePerMaterialContextData *v9; // esi
  HDRType_t (__thiscall *GetHDRType)(IMaterialSystemHardwareConfig *); // eax
  int m_nValue; // eax
  CBasePerMaterialContextData *v12; // eax
  int m_nSelfShadowedBumpFlag; // eax
  bool v14; // zf
  int m_nBlendModulateTexture; // eax
  char v16; // cl
  IMaterialVar *v17; // edx
  int m_nEnvMapLightScale; // eax
  int v19; // eax
  int m_nSeamlessMappingScale; // eax
  IMaterialVar *v21; // edx
  unsigned __int8 *v22; // ecx
  float x; // xmm0_4
  unsigned __int8 *v24; // eax
  int v25; // esi
  IShaderShadow_vtbl *v26; // edx
  BOOL v27; // eax
  int Index; // eax
  IShaderShadow *v29; // esi
  int v30; // esi
  int v31; // edx
  int v32; // eax
  CBasePerMaterialContextData *v33; // eax
  unsigned int *p_m_nVarChangeID; // esi
  IMaterialVar *v35; // ecx
  IMaterialVar *v36; // ecx
  IMaterialVar *v37; // ecx
  IMaterialVar *v38; // ecx
  bool v39; // al
  CBasePerMaterialContextData *v40; // eax
  int m_nBumpTransform; // eax
  int v42; // eax
  bool v43; // al
  IMaterialVar *v44; // eax
  unsigned int v45; // ecx
  double y; // st7
  _DWORD *v47; // eax
  IMaterialVar *v48; // eax
  int m_nEnvmapContrast; // edx
  int m_nEnvmapSaturation; // ecx
  float z; // xmm1_4
  IMaterialVar *v52; // eax
  IMaterialVar *v53; // edx
  IMaterialVar *v54; // ecx
  IMaterialVar *v55; // eax
  float v56; // xmm1_4
  int v57; // eax
  bool v58; // dl
  bool v59; // cl
  bool v60; // al
  IMaterialVar *v61; // eax
  float *v62; // ecx
  double v63; // st7
  IMaterialVar *v64; // eax
  float *v65; // ecx
  double v66; // st7
  float v67; // xmm2_4
  unsigned int v68; // eax
  IMaterialVar *v69; // eax
  unsigned int v70; // ecx
  double v71; // st7
  int v72; // eax
  float v73; // xmm1_4
  float *v74; // eax
  _DWORD *v75; // eax
  int m_nPaintSplatNormal; // eax
  int ShaderAPITextureBindHandle; // eax
  int m_nPaintSplatBubbleLayout; // eax
  int v79; // eax
  int m_nPaintSplatBubble; // eax
  int v81; // eax
  int v82; // eax
  CBasePerMaterialContextData_vtbl *v83; // eax
  int m_nPaintEnvmap; // edi
  int m_nEnvmapFrame; // ebx
  unsigned int v86; // esi
  int v87; // eax
  unsigned __int8 m_bMaterialVarsChanged; // bl
  int v90; // xmm0_4
  int v91; // xmm1_4
  int v92; // xmm2_4
  void (__thiscall *GetMatrix)(IShaderDynamicAPI *, MaterialMatrixMode_t, float *); // edx
  const VMatrix *v94; // eax
  IShaderDynamicAPI_vtbl *v95; // edx
  BOOL v96; // edi
  int v97; // edx
  bool v98; // bl
  __int64 v99; // xmm0_8
  int v100; // edx
  bool v101; // al
  BOOL v102; // edi
  BOOL v103; // eax
  int v104; // ecx
  void (__thiscall *ExecuteCommandBuffer)(IShaderDynamicAPI *, unsigned __int8 *); // edx
  unsigned int v107; // [esp+38h] [ebp-1860h]
  unsigned __int8 src[4]; // [esp+40h] [ebp-1858h] BYREF
  int v109; // [esp+44h] [ebp-1854h]
  _BYTE v110[4992]; // [esp+48h] [ebp-1850h] BYREF
  unsigned __int8 *v111; // [esp+13C8h] [ebp-4D0h]
  VMatrix result; // [esp+13CCh] [ebp-4CCh] BYREF
  _DWORD v113[4]; // [esp+140Ch] [ebp-48Ch] BYREF
  char v114; // [esp+141Ch] [ebp-47Ch] BYREF
  char *v115; // [esp+17F4h] [ebp-A4h]
  _DWORD v116[4]; // [esp+17F8h] [ebp-A0h] BYREF
  VMatrix v117; // [esp+1808h] [ebp-90h] BYREF
  float v118[2]; // [esp+184Ch] [ebp-4Ch] BYREF
  float v119; // [esp+1854h] [ebp-44h]
  Vector vec; // [esp+185Ch] [ebp-3Ch] BYREF
  int v121; // [esp+1868h] [ebp-30h]
  __int64 v122; // [esp+186Ch] [ebp-2Ch]
  __int64 m_fValue_low; // [esp+1874h] [ebp-24h]
  float v124; // [esp+187Ch] [ebp-1Ch]
  float v125; // [esp+1880h] [ebp-18h]
  int v126; // [esp+1884h] [ebp-14h]
  bool v127; // [esp+1889h] [ebp-Fh]
  bool v128; // [esp+188Ah] [ebp-Eh]
  char v129; // [esp+188Bh] [ebp-Dh]
  CBasePerMaterialContextData *v130; // [esp+188Ch] [ebp-Ch]
  bool v131; // [esp+1893h] [ebp-5h]
  char v132; // [esp+1894h] [ebp-4h]
  bool v133; // [esp+1895h] [ebp-3h]
  bool v134; // [esp+1896h] [ebp-2h]
  unsigned __int8 v135; // [esp+1897h] [ebp-1h]
  int v136; // [esp+18A8h] [ebp+10h]
  float v137; // [esp+18A8h] [ebp+10h]
  float pShaderShadowa; // [esp+18ACh] [ebp+14h]
  bool pShaderShadow_3; // [esp+18AFh] [ebp+17h]
  bool pShaderShadow_3a; // [esp+18AFh] [ebp+17h]
  bool pShaderShadow_3b; // [esp+18AFh] [ebp+17h]
  int v142; // [esp+18B4h] [ebp+1Ch]
  unsigned __int8 v143; // [esp+18B7h] [ebp+1Fh]

  if ( pShaderShadow != nullptr )
    CBaseShader::SetInitialShadowState(this: pShader);
  v9 = *pContextDataPtr;
  GetHDRType = g_pHardwareConfig->GetHDRType;
  v130 = *pContextDataPtr;
  v128 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int, int, int))GetHDRType)(
           a1: g_pHardwareConfig,
           a2,
           a3,
           a4: a1) != 0;
  if ( pShaderShadow == nullptr && v9 != nullptr && !v9->m_bMaterialVarsChanged )
    goto LABEL_161;
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    ConVarRef::ConVarRef(this: &gpu_level, pName: "gpu_level");
  }
  m_nValue = gpu_level.m_pConVarState->m_Value.m_nValue;
  if ( v9 == nullptr || (v132 = 0, pShaderShadow != nullptr) )
    v132 = 1;
  v134 = m_nValue > 1;
  if ( v9 == nullptr )
  {
    v12 = (CBasePerMaterialContextData *)operator new(nSize: 0x39Cu);
    if ( v12 != nullptr )
    {
      v12->m_bMaterialVarsChanged = true;
      v12->m_nVarChangeID = -1;
      v12->__vftable = (CBasePerMaterialContextData_vtbl *)&CLightmappedGeneric_DX9_Context::`vftable';
      v12[76].m_nVarChangeID = (unsigned int)&v12[1].m_nVarChangeID;
      v12[1].__vftable = nullptr;
      v9 = v12;
      v130 = v12;
    }
    else
    {
      v9 = nullptr;
      v130 = nullptr;
    }
    *pContextDataPtr = v9;
  }
  m_nSelfShadowedBumpFlag = info->m_nSelfShadowedBumpFlag;
  if ( m_nSelfShadowedBumpFlag == -1 || (v14 = params[m_nSelfShadowedBumpFlag]->m_intVal == 0, v129 = 1, v14) )
    v129 = 0;
  m_nBlendModulateTexture = info->m_nBlendModulateTexture;
  v133 = ((*params)->m_intVal & 0x40) != 0;
  if ( m_nBlendModulateTexture == -1
    || (v16 = *((_BYTE *)params[m_nBlendModulateTexture] + 28) & 0xF, v135 = 1, v16 != 3) )
  {
    v135 = 0;
  }
  *((_WORD *)&v9[76].m_bMaterialVarsChanged + 1) = 0;
  v131 = (*((_BYTE *)params[info->m_nEnvmapMask] + 28) & 0xF) == 3;
  if ( pShaderShadow != nullptr || v132 != 0 )
  {
    v17 = params[info->m_nPaintEnvmap];
    v127 = ((*params)->m_intVal & 0x10) != 0;
    if ( (*((_BYTE *)v17 + 28) & 0xF) != 3
      || (m_nEnvMapLightScale = info->m_nEnvMapLightScale) == -1
      || params[m_nEnvMapLightScale]->m_VecVal.x <= 0.0
      || (v19 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig), v126 = 2, v19 < 92) )
    {
      v126 = 1;
    }
    m_nSeamlessMappingScale = info->m_nSeamlessMappingScale;
    if ( m_nSeamlessMappingScale == -1 || (v143 = 1, params[m_nSeamlessMappingScale]->m_VecVal.x == 0.0) )
      v143 = 0;
    if ( v132 != 0 )
    {
      if ( v9[1].__vftable != nullptr )
      {
        free(pMem: v9[1].__vftable);
        v9[1].__vftable = nullptr;
      }
      v21 = params[2];
      v22 = src;
      v111 = src;
      if ( ((v21->m_intVal & 0x100000) != 0) + 2 * ((v21->m_intVal & 0x200000) != 0) == 3 )
      {
        v22 = v110;
        *(_DWORD *)src = 16;
        v109 = 54;
        v111 = v110;
      }
      *(_DWORD *)v22 = 9;
      v111 += 4;
      *(_DWORD *)v111 = (v128 ? 0 : 0x80000000) | 1;
      v111 += 4;
      *(_DWORD *)v111 = 0;
      v111 += 4;
      *(_DWORD *)v111 = 9;
      v111 += 4;
      *(_DWORD *)v111 = 6;
      v111 += 4;
      *(_DWORD *)v111 = 20;
      v111 += 4;
      *(_DWORD *)v111 = 9;
      v111 += 4;
      *(_DWORD *)v111 = 9;
      v111 += 4;
      *(_DWORD *)v111 = 28;
      v111 += 4;
      if ( v143 != 0 )
      {
        x = params[info->m_nSeamlessMappingScale]->m_VecVal.x;
        *(_DWORD *)v111 = 4;
        v111 += 4;
        *(_DWORD *)v111 = 48;
        v111 += 4;
        *(_DWORD *)v111 = 1;
        v111 += 4;
        *(float *)v111 = x;
        v111 += 4;
        *(_DWORD *)v111 = 0;
        v111 += 4;
        *(_DWORD *)v111 = 0;
        v111 += 4;
        *(_DWORD *)v111 = 0;
        v111 += 4;
      }
      *(_DWORD *)v111 = 7;
      v111 += 4;
      *(_DWORD *)v111 = 10;
      v111 += 4;
      *(_DWORD *)v111 = 1065353216;
      v111 += 4;
      *(_DWORD *)v111 = 6;
      v111 += 4;
      *(_DWORD *)v111 = 11;
      v111 += 4;
      *(_DWORD *)v111 = 0;
      v111 += 4;
      v24 = (unsigned __int8 *)operator new(nSize: v111 - src);
      v107 = v111 - src;
      v9[1].__vftable = (CBasePerMaterialContextData_vtbl *)v24;
      memcpy(dst: v24, src, count: v107);
    }
    if ( pShaderShadow != nullptr )
    {
      CBaseShader::EnableAlphaBlending(
        this: pShader,
        src: SHADER_BLEND_SRC_ALPHA,
        dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
      v25 = 51;
      if ( v131 )
        pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: true);
      if ( v127 )
        v25 = 55;
      v26 = pShaderShadow->__vftable;
      LODWORD(v124) = ((params[2]->m_intVal & 0x100000) != 0) + 2 * ((params[2]->m_intVal & 0x200000) != 0);
      v26->VertexShaderVertexFormat(this: pShaderShadow, a2: v25, a3: 3, a4: nullptr, a5: 0);
      LODWORD(v125) = (v129 != 0) + 1;
      lightmappedgeneric_vs20_Static_Index::lightmappedgeneric_vs20_Static_Index(
        this: (lightmappedgeneric_vs20_Static_Index *)&v117.m[0][2],
        pShaderShadow,
        params);
      LODWORD(v117.m[0][2]) = v131;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "ENVMAP_MASK", v131, "hasEnvmapMask");
      LODWORD(v117.m[0][3]) = 1;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "TANGENTSPACE", 1, "1");
      LODWORD(v117.m[1][0]) = 1;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "BUMPMAP", 1, "hasBump");
      v27 = ((*params)->m_intVal & 0x10) != 0;
      LODWORD(v117.m[1][2]) = v27;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", v27, "IS_FLAG_SET( MATERIAL_VAR_VERTEXCOLOR )");
      v117.m[1][3] = 0.0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXALPHATEXBLENDFACTOR", 0, "0");
      v117.m[2][1] = 0.0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "BUMPMASK", 0, "0");
      v117.m[3][0] = v124;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "LIGHTING_PREVIEW", v124, "nLightingPreviewMode");
      LODWORD(v124) = v143 != 0;
      v117.m[2][0] = v124;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SEAMLESS", v143, "bSeamlessMapping");
      v117.m[1][1] = 0.0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "DETAILTEXTURE", 0, "0");
      LODWORD(v117.m[2][2]) = v135 != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FANCY_BLENDING", v135, "bHasBlendModulateTexture");
      LODWORD(v117.m[2][3]) = v133;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SELFILLUM", v133, "hasSelfIllum");
      LODWORD(v117.m[3][1]) = 1;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "PAINT", 1, "1");
      HIDWORD(m_fValue_low) = (IShaderShadow)pShaderShadow->__vftable;
      Index = lightmappedgeneric_vs20_Static_Index::GetIndex(this: (lightmappedgeneric_vs20_Static_Index *)&v117.m[0][2]);
      v29 = pShaderShadow;
      (*(void (__thiscall **)(IShaderShadow *, const char *, int))(HIDWORD(m_fValue_low) + 68))(
        a1: pShaderShadow,
        a2: "lightmappedgeneric_vs20",
        a3: Index);
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", v125, "bumpmap_variant");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", v126, "envmap_variant");
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS", v143, "bSeamlessMapping");
          }
        }
        LODWORD(v119) = v134;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "THICKPAINT", v134, "bThickPaint");
        v32 = LODWORD(v124) + 2 * LODWORD(v119) + v126 + 2 * (LODWORD(v124) + 2 * LODWORD(v119));
        pShaderShadow->SetPixelShader(
          this: pShaderShadow,
          a2: "lightmappedpaint_ps20",
          a3: 8 * (v32 + LODWORD(v125) + 2 * v32));
      }
      else
      {
        v30 = -((*params)->m_intVal < 0);
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", v125, "bumpmap_variant");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", v126, "envmap_variant");
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS", v143, "bSeamlessMapping");
          }
        }
        LODWORD(v119) = v134;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "THICKPAINT", v134, "bThickPaint");
        v31 = LODWORD(v124) + 2 * (LODWORD(v119) + 2 * v30 + 2);
        pShaderShadow->SetPixelShader(
          this: pShaderShadow,
          a2: "lightmappedpaint_ps20b",
          a3: 8 * (v31 + v126 + 2 * v31 + LODWORD(v125) + 2 * (v31 + v126 + 2 * v31)));
        v29 = pShaderShadow;
      }
      v29->EnableAlphaWrites(this: v29, a2: false);
      v29->EnableSRGBWrite(this: v29, a2: true);
      CBaseShader::DefaultFog(this: pShader);
      pShaderShadowa = v29->GetLightMapScaleFactor(this: v29);
      CBaseShader::PI_BeginCommandBuffer(this: pShader);
      CBaseShader::PI_SetModulationPixelShaderDynamicState(this: pShader, nRegister: 21);
      CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearScale_ScaleInW(
        this: pShader,
        nRegister: 12,
        scale: pShaderShadowa);
      CBaseShader::PI_SetModulationVertexShaderDynamicState_LinearScale(this: pShader, flScale: pShaderShadowa);
      CBaseShader::PI_EndCommandBuffer(this: pShader);
      v9 = v130;
    }
  }
  if ( pShaderAPI != nullptr )
  {
    if ( v9->m_bMaterialVarsChanged )
    {
      v33 = v130;
      p_m_nVarChangeID = &v130[1].m_nVarChangeID;
      v130[76].m_nVarChangeID = (unsigned int)&v130[1].m_nVarChangeID;
      v33->m_bMaterialVarsChanged = false;
      v35 = params[info->m_nBaseTextureTransform];
      v39 = true;
      if ( v35->MatrixIsIdentity(this: v35) )
      {
        v36 = params[info->m_nBumpTransform];
        if ( v36->MatrixIsIdentity(this: v36) )
        {
          v37 = params[info->m_nBumpTransform2];
          if ( v37->MatrixIsIdentity(this: v37) )
          {
            v38 = params[info->m_nEnvmapMaskTransform];
            if ( v38->MatrixIsIdentity(this: v38) )
              v39 = false;
          }
        }
      }
      v14 = !v39;
      v40 = v130;
      v130[76].m_bMaterialVarsChanged = v14;
      if ( (*((_BYTE *)params[info->m_nDetail] + 28) & 0xF) == 3 )
        v40[76].m_bMaterialVarsChanged = false;
      m_nBumpTransform = -1;
      if ( !v133 && v135 == 0 )
        m_nBumpTransform = info->m_nBumpTransform;
      CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(
        this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *)p_m_nVarChangeID,
        vertexReg: 14,
        transformVar: m_nBumpTransform);
      if ( !v130[76].m_bMaterialVarsChanged )
      {
        v42 = info->m_nSeamlessMappingScale;
        v43 = v42 != -1 && params[v42]->m_VecVal.x != 0.0;
        pShaderShadow_3 = (*((_BYTE *)params[info->m_nEnvmapMask] + 28) & 0xF) == 3;
        if ( !v43 )
          CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(
            this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *)p_m_nVarChangeID,
            vertexReg: 48,
            transformVar: info->m_nBaseTextureTransform);
        CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(
          this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *)p_m_nVarChangeID,
          vertexReg: 50,
          transformVar: info->m_nBumpTransform);
        if ( pShaderShadow_3 )
          CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(
            this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *)p_m_nVarChangeID,
            vertexReg: 52,
            transformVar: info->m_nEnvmapMaskTransform);
      }
      if ( !g_pConfig->bShowSpecular || g_pConfig->nFullbright == 2 )
      {
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 0;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v47 = (_DWORD *)p_m_nVarChangeID[225];
        v47[1] = 0;
        v47[2] = 0;
        v47[3] = 0;
        v47[4] = 0;
        p_m_nVarChangeID[225] = (unsigned int)(v47 + 5);
      }
      else
      {
        v44 = CBaseShader::s_ppParams[info->m_nEnvmapTint];
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 0;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v45 = p_m_nVarChangeID[225];
        *(float *)(v45 + 4) = v44->m_VecVal.x;
        v45 += 20;
        y = v44->m_VecVal.y;
        p_m_nVarChangeID[225] = v45;
        *(float *)(v45 - 12) = y;
        *(float *)(v45 - 8) = v44->m_VecVal.z;
        *(float *)(v45 - 4) = v44->m_VecVal.w;
      }
      v48 = params[info->m_nSelfIllumTint];
      m_nEnvmapContrast = info->m_nEnvmapContrast;
      m_nEnvmapSaturation = info->m_nEnvmapSaturation;
      vec.x = v48->m_VecVal.x;
      vec.y = v48->m_VecVal.y;
      z = v48->m_VecVal.z;
      v52 = params[m_nEnvmapContrast];
      v53 = params[m_nEnvmapSaturation];
      vec.z = z;
      v54 = params[info->m_nFresnelReflection];
      HIDWORD(m_fValue_low) = LODWORD(v52->m_VecVal.x);
      v55 = params[info->m_nPaintEnvmap];
      v124 = v53->m_VecVal.x;
      v56 = v54->m_VecVal.x;
      LOBYTE(v54) = *((_BYTE *)v55 + 28) & 0xF;
      v125 = v56;
      pShaderShadow_3a = (_BYTE)v54 == 3;
      if ( (_BYTE)v54 == 3 )
      {
        v57 = info->m_nEnvMapLightScale;
        if ( v57 == -1
          || params[v57]->m_VecVal.x <= 0.0
          || g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
        {
          v142 = 1;
        }
        else
        {
          v142 = 2;
        }
      }
      else
      {
        v142 = 0;
      }
      *(&v130[76].m_bMaterialVarsChanged + 1) = true;
      v58 = pShaderShadow_3a
         && (*((float *)&m_fValue_low + 1) != 0.0 && *((float *)&m_fValue_low + 1) != 1.0 || v124 != 1.0);
      v59 = pShaderShadow_3a && v125 != 1.0;
      v60 = ((*params)->m_intVal & 0x40) != 0 && (vec.x != 1.0 || vec.y != 1.0 || vec.z != 1.0);
      if ( v58 || v59 || v60 || !g_pConfig->bShowSpecular )
        *(&v130[76].m_bMaterialVarsChanged + 1) = false;
      if ( !*(&v130[76].m_bMaterialVarsChanged + 1) )
      {
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 2;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        v61 = params[info->m_nEnvmapContrast];
        v62 = (float *)p_m_nVarChangeID[225];
        *v62 = v61->m_VecVal.x;
        v62 += 4;
        v63 = v61->m_VecVal.y;
        p_m_nVarChangeID[225] = (unsigned int)v62;
        *(v62 - 3) = v63;
        *(v62 - 2) = v61->m_VecVal.z;
        *(v62 - 1) = v61->m_VecVal.w;
        v64 = params[info->m_nEnvmapSaturation];
        v65 = (float *)p_m_nVarChangeID[225];
        *v65 = v64->m_VecVal.x;
        v65 += 4;
        v66 = v64->m_VecVal.y;
        p_m_nVarChangeID[225] = (unsigned int)v65;
        *(v65 - 3) = v66;
        *(v65 - 2) = v64->m_VecVal.z;
        *(v65 - 1) = v64->m_VecVal.w;
        v67 = params[info->m_nFresnelReflection]->m_VecVal.x;
        v68 = p_m_nVarChangeID[225];
        *(_DWORD *)v68 = 0;
        *(_DWORD *)(v68 + 4) = 0;
        *(float *)(v68 + 8) = 1.0 - v67;
        *(float *)(v68 + 12) = v67;
        p_m_nVarChangeID[225] = v68 + 16;
        v69 = params[info->m_nSelfIllumTint];
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 7;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v70 = p_m_nVarChangeID[225];
        *(float *)(v70 + 4) = v69->m_VecVal.x;
        v70 += 20;
        v71 = v69->m_VecVal.y;
        p_m_nVarChangeID[225] = v70;
        *(float *)(v70 - 12) = v71;
        *(float *)(v70 - 8) = v69->m_VecVal.z;
        *(float *)(v70 - 4) = v69->m_VecVal.w;
      }
      if ( v142 == 2 )
      {
        v72 = info->m_nEnvMapLightScale;
        if ( v72 == -1 )
          v73 = 0.0;
        else
          v73 = params[v72]->m_VecVal.x;
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 20;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v74 = (float *)p_m_nVarChangeID[225];
        v74[1] = 0.0;
        v74[2] = v73;
        v74[3] = 0.0;
        v74[4] = 0.0;
        p_m_nVarChangeID[225] = (unsigned int)(v74 + 5);
      }
      if ( g_pConfig->nFullbright == 2 && ((*params)->m_intVal & 2) == 0 )
      {
        *(_DWORD *)p_m_nVarChangeID[225] = 4;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 47;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v75 = (_DWORD *)p_m_nVarChangeID[225];
        v75[1] = 0;
        v75[2] = 0;
        v75[3] = 0;
        v75[4] = 0;
        p_m_nVarChangeID[225] = (unsigned int)(v75 + 5);
      }
      m_nPaintSplatNormal = info->m_nPaintSplatNormal;
      if ( (*((_BYTE *)params[m_nPaintSplatNormal] + 28) & 0xF) == 3 )
      {
        ShaderAPITextureBindHandle = CBaseShader::GetShaderAPITextureBindHandle(
                                       this: pShader,
                                       nTextureVar: m_nPaintSplatNormal,
                                       nFrameVar: -1,
                                       nTextureChannel: 0);
        *(_DWORD *)p_m_nVarChangeID[225] = 10;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 7;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = ShaderAPITextureBindHandle;
      }
      else
      {
        *(_DWORD *)p_m_nVarChangeID[225] = 9;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 7;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 9;
      }
      p_m_nVarChangeID[225] += 4;
      m_nPaintSplatBubbleLayout = info->m_nPaintSplatBubbleLayout;
      if ( (*((_BYTE *)params[m_nPaintSplatBubbleLayout] + 28) & 0xF) == 3 )
      {
        v79 = CBaseShader::GetShaderAPITextureBindHandle(
                this: pShader,
                nTextureVar: m_nPaintSplatBubbleLayout,
                nFrameVar: -1,
                nTextureChannel: 0);
        *(_DWORD *)p_m_nVarChangeID[225] = 10;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 4;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = v79;
      }
      else
      {
        *(_DWORD *)p_m_nVarChangeID[225] = 9;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 4;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 5;
      }
      p_m_nVarChangeID[225] += 4;
      m_nPaintSplatBubble = info->m_nPaintSplatBubble;
      if ( (*((_BYTE *)params[m_nPaintSplatBubble] + 28) & 0xF) == 3 )
      {
        v81 = CBaseShader::GetShaderAPITextureBindHandle(
                this: pShader,
                nTextureVar: m_nPaintSplatBubble,
                nFrameVar: -1,
                nTextureChannel: 0);
        *(_DWORD *)p_m_nVarChangeID[225] = 10;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 5;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = v81;
      }
      else
      {
        *(_DWORD *)p_m_nVarChangeID[225] = 9;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 5;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 9;
      }
      p_m_nVarChangeID[225] += 4;
      if ( v135 != 0 )
      {
        v82 = CBaseShader::GetShaderAPITextureBindHandle(
                this: pShader,
                nTextureVar: info->m_nBlendModulateTexture,
                nFrameVar: -1,
                nTextureChannel: 0);
        *(_DWORD *)p_m_nVarChangeID[225] = 10;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = v82;
        p_m_nVarChangeID[225] += 4;
      }
      *(_DWORD *)p_m_nVarChangeID[225] = 0;
      p_m_nVarChangeID[225] += 4;
      v9 = v130;
    }
LABEL_161:
    if ( pShaderAPI != nullptr )
    {
      pShaderAPI->SetDefaultState(this: pShaderAPI);
      v83 = v9[1].__vftable;
      m_nPaintEnvmap = info->m_nPaintEnvmap;
      v113[0] = 2;
      v113[2] = 2;
      v115 = &v114;
      v113[1] = v83;
      v113[3] = (char *)v9 + 16;
      if ( (*((_BYTE *)params[m_nPaintEnvmap] + 28) & 0xF) == 3 )
      {
        m_nEnvmapFrame = info->m_nEnvmapFrame;
        v86 = v128 ? 0 : 0x80000000;
        if ( CBaseShader::s_ppParams[m_nPaintEnvmap]->IsTextureValueInternalEnvCubemap(this: CBaseShader::s_ppParams[m_nPaintEnvmap]) )
        {
          *(_DWORD *)v115 = 9;
          v115 += 4;
          *(_DWORD *)v115 = v86 | 2;
          v115 += 4;
          *(_DWORD *)v115 = 25;
        }
        else
        {
          v87 = CBaseShader::GetShaderAPITextureBindHandle(
                  this: pShader,
                  nTextureVar: m_nPaintEnvmap,
                  nFrameVar: m_nEnvmapFrame,
                  nTextureChannel: 0);
          *(_DWORD *)v115 = 10;
          v115 += 4;
          *(_DWORD *)v115 = v86 | 2;
          v115 += 4;
          *(_DWORD *)v115 = v87;
        }
        v115 += 4;
      }
      m_bMaterialVarsChanged = v130[76].m_bMaterialVarsChanged;
      v136 = pShaderAPI->GetIntRenderingParameter(this: pShaderAPI, a2: 0);
      if ( v136 != 0 )
        m_bMaterialVarsChanged = 0;
      pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: (float *)v116);
      v90 = v116[0];
      v91 = v116[1];
      v92 = v116[2];
      *(_DWORD *)v115 = 4;
      v115 += 4;
      *(_DWORD *)v115 = 12;
      v115 += 4;
      *(_DWORD *)v115 = 1;
      v115 += 4;
      *(_DWORD *)v115 = v90;
      GetMatrix = pShaderAPI->GetMatrix;
      v115 += 4;
      *(_DWORD *)v115 = v91;
      v115 += 4;
      *(_DWORD *)v115 = v92;
      v115 += 4;
      *(_DWORD *)v115 = 0;
      v115 += 4;
      GetMatrix(this: pShaderAPI, a2: MATERIAL_VIEW, a3: (float *)&v117);
      v94 = VMatrix::Transpose3x3(this: &v117, &result);
      VMatrix::operator=(this: &v117, mOther: v94);
      *(_QWORD *)&vec.x = *(_QWORD *)&v117.m[0][0];
      v121 = 0;
      vec.z = 0.0;
      VectorNormalize(&vec);
      v95 = pShaderAPI->__vftable;
      v118[0] = (float)(vec.z * 0.0) - vec.y;
      v118[1] = vec.x - (float)(vec.z * 0.0);
      v119 = (float)(vec.y * 0.0) - (float)(vec.x * 0.0);
      v95->SetPixelShaderConstant(this: pShaderAPI, a2: 22, a3: &vec.x, a4: 1, a5: false);
      pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 23, a3: v118, a4: 1, a5: false);
      pShaderAPI->GetSceneFogMode(this: pShaderAPI);
      v96 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      LODWORD(m_fValue_low) = m_bMaterialVarsChanged != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "FASTPATH", m_bMaterialVarsChanged, "bVertexShaderFastPath");
      v97 = m_fValue_low;
      *(_DWORD *)v115 = 12;
      v115 += 4;
      *(_DWORD *)v115 = v97 + 2 * v96;
      v115 += 4;
      v98 = *(&v130[76].m_bMaterialVarsChanged + 1);
      pShaderShadow_3b = v98;
      if ( v136 != 0 )
        v98 = false;
      if ( *(&v130[76].m_bMaterialVarsChanged + 2) )
        pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
      v14 = g_pConfig->nFullbright == 1;
      *(float *)&v122 = mat_ambient_light_r.m_pParent->m_Value.m_fValue;
      HIDWORD(v122) = LODWORD(mat_ambient_light_g.m_pParent->m_Value.m_fValue);
      m_fValue_low = LODWORD(mat_ambient_light_b.m_pParent->m_Value.m_fValue);
      if ( v14 )
      {
        LODWORD(m_fValue_low) = 0;
        v122 = 0;
      }
      v99 = v122;
      *(_DWORD *)v115 = 3;
      v115 += 4;
      *(_DWORD *)v115 = 31;
      v115 += 4;
      *(_DWORD *)v115 = 1;
      v115 += 4;
      *(_QWORD *)v115 = v99;
      *((_QWORD *)v115 + 1) = m_fValue_low;
      v100 = info->m_nEnvmapContrast;
      v115 += 16;
      v137 = params[v100]->m_VecVal.x;
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        HIDWORD(m_fValue_low) = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
        LODWORD(m_fValue_low) = v98;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "FASTPATH", v98, "bPixelShaderFastPath");
      }
      else
      {
        HIDWORD(m_fValue_low) = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
        LODWORD(m_fValue_low) = pShaderShadow_3b;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "FASTPATH", pShaderShadow_3b, "bFastPath");
      }
      v101 = v98 && v137 == 1.0;
      v102 = v101;
      if ( g_shaderConfigDumpEnable )
      {
        v103 = v98 && v137 == 1.0;
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "FASTPATHENVMAPCONTRAST",
          v103,
          "bPixelShaderFastPath && envmapContrast == 1.0f");
      }
      v104 = m_fValue_low;
      *(_DWORD *)v115 = 11;
      v115 += 4;
      *(_DWORD *)v115 = v102 + 2 * (v104 + 2 * HIDWORD(m_fValue_low));
      v115 += 4;
      *(_DWORD *)v115 = 0;
      ExecuteCommandBuffer = pShaderAPI->ExecuteCommandBuffer;
      v115 += 4;
      ExecuteCommandBuffer(this: pShaderAPI, a2: (unsigned __int8 *)v113);
    }
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
