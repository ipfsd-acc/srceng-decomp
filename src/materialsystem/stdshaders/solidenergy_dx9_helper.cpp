// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/solidenergy_dx9_helper.cpp
// Functions: 4
// ============================================================

#include "materialsystem\stdshaders\solidenergy_dx9_helper.h"

//------------------------------------------------------------------------------
// Address: 0x100302F0
// Name: public: solidenergy_vs20_Static_Index::solidenergy_vs20_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
solidenergy_vs20_Static_Index *__thiscall solidenergy_vs20_Static_Index::solidenergy_vs20_Static_Index(
        solidenergy_vs20_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  BOOL v4; // ecx

  this->m_nDETAIL1 = 0;
  this->m_nDETAIL2 = 0;
  this->m_nTANGENTTOPACITY = 0;
  this->m_nTANGENTSOPACITY = 0;
  this->m_nFRESNELOPACITY = 0;
  this->m_nVERTEXCOLOR = 0;
  this->m_nFLOWMAP = 0;
  this->m_nMODELFORMAT = 0;
  this->m_nDOPIXELFOG = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
  v4 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  this->m_nHARDWAREFOGBLEND = v4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10030350
// Name: void InitParamsSolidEnergy(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct SolidEnergyVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsSolidEnergy(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        SolidEnergyVars_t *info)
{
  IMaterialVar *v4; // ecx
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
  IMaterialVar *v15; // ecx
  IMaterialVar *v16; // ecx
  int v17; // eax
  IMaterialVar *v18; // ecx
  IMaterialVar *v19; // ecx
  IMaterialVar *v20; // ecx
  int v21; // eax
  IMaterialVar *v22; // ecx
  IMaterialVar *v23; // ecx
  IMaterialVar *v24; // ecx
  int v25; // eax
  IMaterialVar *v26; // ecx
  IMaterialVar *v27; // ecx
  IMaterialVar *v28; // ecx
  IMaterialVar *v29; // ecx
  IMaterialVar *v30; // ecx
  IMaterialVar *v31; // ecx
  IMaterialVar *v32; // ecx
  IMaterialVar *v33; // ecx
  IMaterialVar *v34; // ecx
  IMaterialVar *v35; // ecx
  IMaterialVar *v36; // ecx
  IMaterialVar *v37; // ecx
  IMaterialVar *v38; // ecx
  IMaterialVar *v39; // ecx
  IMaterialVar *v40; // ecx
  IMaterialVar *v41; // ecx
  IMaterialVar *v42; // ecx
  IMaterialVar *v43; // ecx
  IMaterialVar *v44; // ecx
  int nGPULevel; // [esp+70h] [ebp-4h]

  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    ConVarRef::ConVarRef(this: &gpu_level_0, pName: "gpu_level");
  }
  nGPULevel = gpu_level_0.m_pConVarState->m_Value.m_nValue;
  if ( info->m_nDetail1Scale != -1 )
  {
    v4 = params[info->m_nDetail1Scale];
    if ( !v4->IsDefined(this: v4) )
      ((void (__stdcall *)(int))params[info->m_nDetail1Scale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nDetail1Frame != -1 )
  {
    v5 = params[info->m_nDetail1Frame];
    if ( !v5->IsDefined(this: v5) )
    {
      v6 = params[info->m_nDetail1Frame];
      v6->SetIntValue(this: v6, a2: 0);
    }
  }
  if ( info->m_nDetail1BlendMode != -1 )
  {
    v7 = params[info->m_nDetail1BlendMode];
    if ( !v7->IsDefined(this: v7) )
    {
      v8 = params[info->m_nDetail1BlendMode];
      v8->SetIntValue(this: v8, a2: 0);
    }
  }
  if ( info->m_nDetail2Scale != -1 )
  {
    v9 = params[info->m_nDetail2Scale];
    if ( !v9->IsDefined(this: v9) )
      ((void (__stdcall *)(int))params[info->m_nDetail2Scale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nDetail2Frame != -1 )
  {
    v10 = params[info->m_nDetail2Frame];
    if ( !v10->IsDefined(this: v10) )
    {
      v11 = params[info->m_nDetail2Frame];
      v11->SetIntValue(this: v11, a2: 0);
    }
  }
  if ( info->m_nDetail2BlendMode != -1 )
  {
    v12 = params[info->m_nDetail2BlendMode];
    if ( !v12->IsDefined(this: v12) )
    {
      v13 = params[info->m_nDetail2BlendMode];
      v13->SetIntValue(this: v13, a2: 0);
    }
  }
  if ( info->m_nDepthBlendScale != -1 )
  {
    v14 = params[info->m_nDepthBlendScale];
    if ( !v14->IsDefined(this: v14) )
      ((void (__stdcall *)(int))params[info->m_nDepthBlendScale]->SetFloatValue)(a1: 1112014848);
  }
  if ( info->m_nNeedsTangentT != -1 )
  {
    v15 = params[info->m_nNeedsTangentT];
    if ( !v15->IsDefined(this: v15) )
    {
      if ( info->m_nTangentTOpacityRanges < 0
        || (v16 = params[info->m_nTangentTOpacityRanges], !v16->IsDefined(this: v16))
        || (v17 = 1, nGPULevel <= 1) )
      {
        v17 = 0;
      }
      v18 = params[info->m_nNeedsTangentT];
      v18->SetIntValue(this: v18, a2: v17);
    }
  }
  if ( info->m_nNeedsTangentS != -1 )
  {
    v19 = params[info->m_nNeedsTangentS];
    if ( !v19->IsDefined(this: v19) )
    {
      if ( info->m_nTangentSOpacityRanges < 0
        || (v20 = params[info->m_nTangentSOpacityRanges], !v20->IsDefined(this: v20))
        || (v21 = 1, nGPULevel <= 1) )
      {
        v21 = 0;
      }
      v22 = params[info->m_nNeedsTangentS];
      v22->SetIntValue(this: v22, a2: v21);
    }
  }
  if ( info->m_nNeedsNormals != -1 )
  {
    v23 = params[info->m_nNeedsNormals];
    if ( !v23->IsDefined(this: v23) )
    {
      if ( info->m_nFresnelOpacityRanges < 0
        || (v24 = params[info->m_nFresnelOpacityRanges], !v24->IsDefined(this: v24))
        || (v25 = 1, nGPULevel <= 1) )
      {
        v25 = 0;
      }
      v26 = params[info->m_nNeedsNormals];
      v26->SetIntValue(this: v26, a2: v25);
    }
  }
  if ( info->m_nFlowWorldUVScale != -1 )
  {
    v27 = params[info->m_nFlowWorldUVScale];
    if ( !v27->IsDefined(this: v27) )
      ((void (__stdcall *)(int))params[info->m_nFlowWorldUVScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nFlowNormalUVScale != -1 )
  {
    v28 = params[info->m_nFlowNormalUVScale];
    if ( !v28->IsDefined(this: v28) )
      ((void (__stdcall *)(int))params[info->m_nFlowNormalUVScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nFlowTimeIntervalInSeconds != -1 )
  {
    v29 = params[info->m_nFlowTimeIntervalInSeconds];
    if ( !v29->IsDefined(this: v29) )
      ((void (__stdcall *)(int))params[info->m_nFlowTimeIntervalInSeconds]->SetFloatValue)(a1: 1053609165);
  }
  if ( info->m_nFlowUVScrollDistance != -1 )
  {
    v30 = params[info->m_nFlowUVScrollDistance];
    if ( !v30->IsDefined(this: v30) )
      ((void (__stdcall *)(int))params[info->m_nFlowUVScrollDistance]->SetFloatValue)(a1: 1045220557);
  }
  if ( info->m_nFlowNoiseScale != -1 )
  {
    v31 = params[info->m_nFlowNoiseScale];
    if ( !v31->IsDefined(this: v31) )
      ((void (__stdcall *)(int))params[info->m_nFlowNoiseScale]->SetFloatValue)(a1: 961656599);
  }
  if ( info->m_nPowerUp != -1 )
  {
    v32 = params[info->m_nPowerUp];
    if ( !v32->IsDefined(this: v32) )
      ((void (__stdcall *)(int))params[info->m_nPowerUp]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nFlowColorIntensity != -1 )
  {
    v33 = params[info->m_nFlowColorIntensity];
    if ( !v33->IsDefined(this: v33) )
      ((void (__stdcall *)(int))params[info->m_nFlowColorIntensity]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nFlowVortexSize != -1 )
  {
    v34 = params[info->m_nFlowVortexSize];
    if ( !v34->IsDefined(this: v34) )
      ((void (__stdcall *)(int))params[info->m_nFlowVortexSize]->SetFloatValue)(a1: 1106247680);
  }
  if ( info->m_nFlowColor != -1 )
  {
    v35 = params[info->m_nFlowColor];
    if ( !v35->IsDefined(this: v35) )
    {
      v36 = params[info->m_nFlowColor];
      v36->SetVecValue_4(this: v36, a2: kDefaultFieldColor, a3: 3);
    }
  }
  if ( info->m_nFlowVortexColor != -1 )
  {
    v37 = params[info->m_nFlowVortexColor];
    if ( !v37->IsDefined(this: v37) )
    {
      v38 = params[info->m_nFlowVortexColor];
      v38->SetVecValue_4(this: v38, a2: kDefaultVortexColor, a3: 3);
    }
  }
  if ( info->m_nFlowCheap != -1 )
  {
    v39 = params[info->m_nFlowCheap];
    if ( !v39->IsDefined(this: v39) )
    {
      v40 = params[info->m_nFlowCheap];
      v40->SetIntValue(this: v40, a2: nGPULevel < 2);
    }
  }
  if ( info->m_nModel != -1 )
  {
    v41 = params[info->m_nModel];
    if ( !v41->IsDefined(this: v41) )
    {
      v42 = params[info->m_nModel];
      v42->SetIntValue(this: v42, a2: 0);
    }
  }
  if ( info->m_nOutputIntensity != -1 )
  {
    v43 = params[info->m_nOutputIntensity];
    if ( !v43->IsDefined(this: v43) )
      ((void (__stdcall *)(int))params[info->m_nOutputIntensity]->SetFloatValue)(a1: 1065353216);
  }
  if ( nGPULevel < 2 )
  {
    v44 = params[info->m_nDetail2Texture];
    v44->SetUndefined(this: v44);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030850
// Name: void InitSolidEnergy(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct SolidEnergyVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitSolidEnergy(CBaseVSShader *pShader, IMaterialVar **params, SolidEnergyVars_t *info)
{
  IMaterialVar *v3; // ecx
  IMaterialVar *v4; // ecx
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  int m_nModel; // esi

  if ( info->m_nBaseTexture != -1 && params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0x80000);
  if ( info->m_nDetail1Texture != -1 )
  {
    v3 = params[info->m_nDetail1Texture];
    if ( v3->IsDefined(this: v3) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nDetail1Texture, nAdditionalCreationFlags: 0x80000);
  }
  if ( info->m_nDetail2Texture != -1 )
  {
    v4 = params[info->m_nDetail2Texture];
    if ( v4->IsDefined(this: v4) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nDetail2Texture, nAdditionalCreationFlags: 0x80000);
  }
  if ( info->m_nFlowMap != -1 )
  {
    v5 = params[info->m_nFlowMap];
    if ( v5->IsDefined(this: v5) )
    {
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFlowMap, nAdditionalCreationFlags: 0);
      if ( info->m_nFlowNoiseTexture != -1 )
      {
        v6 = params[info->m_nFlowNoiseTexture];
        if ( v6->IsDefined(this: v6) )
          CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFlowNoiseTexture, nAdditionalCreationFlags: 0);
      }
      if ( info->m_nFlowBoundsTexture != -1 )
      {
        v7 = params[info->m_nFlowBoundsTexture];
        if ( v7->IsDefined(this: v7) )
          CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFlowBoundsTexture, nAdditionalCreationFlags: 0);
      }
    }
  }
  m_nModel = info->m_nModel;
  if ( m_nModel != -1 && params[m_nModel]->m_intVal != 0 )
    ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x800);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
}

//------------------------------------------------------------------------------
// Address: 0x10030980
// Name: void DrawSolidEnergy(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct SolidEnergyVars_t __near &,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSolidEnergy(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        SolidEnergyVars_t *info,
        VertexCompressionType_t vertexCompression,
        CSolidEnergy_DX9_Context **pContextDataPtr)
{
  IMaterialVar *v7; // eax
  int m_intVal; // ecx
  int m_nDetail1Texture; // eax
  int m_nDetail2Texture; // eax
  char v12; // al
  int m_nDepthBlend; // eax
  bool v14; // zf
  int m_nFlowMap; // eax
  IShaderDynamicAPI *v16; // esi
  int m_nNeedsTangentT; // eax
  bool v18; // cl
  int m_nNeedsTangentS; // eax
  int m_nNeedsNormals; // eax
  int m_nDetail1BlendMode; // eax
  int v22; // eax
  int m_nDetail2BlendMode; // eax
  int v24; // eax
  int v25; // ecx
  unsigned int v26; // eax
  bool v27; // al
  BOOL v28; // eax
  BOOL v29; // ebx
  bool v30; // al
  BOOL v31; // eax
  int v32; // eax
  int v33; // ecx
  bool v34; // al
  BOOL v35; // eax
  BOOL v36; // ebx
  bool v37; // al
  BOOL v38; // eax
  BOOL v39; // ebx
  bool v40; // bl
  int v41; // eax
  CSolidEnergy_DX9_Context *v42; // eax
  CSolidEnergy_DX9_Context *v43; // esi
  CCommandBufferBuilder<CFixedCommandStorageBuffer<800> > *p_m_SemiStaticCmdsOut; // esi
  IMaterialVar *v45; // ecx
  IMaterialVar *v46; // ecx
  int ShaderAPITextureBindHandle; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  IMaterialVar *v51; // ecx
  __int64 v52; // xmm0_8
  unsigned __int8 *m_pDataOut; // eax
  IMaterialVar *v54; // ecx
  __int64 v55; // xmm0_8
  unsigned __int8 *v56; // eax
  IMaterialVar *v57; // ecx
  IMaterialVar **v58; // ecx
  __int64 v59; // xmm1_8
  __int64 v60; // xmm0_8
  unsigned __int8 *v61; // eax
  float x; // xmm0_4
  unsigned __int8 *v63; // eax
  float v64; // xmm1_4
  unsigned __int8 *v65; // eax
  IMaterialVar *v66; // eax
  float v67; // xmm0_4
  IMaterialVar *v68; // eax
  float v69; // xmm0_4
  unsigned __int8 *v70; // eax
  IMaterialVar *v71; // eax
  float z; // xmm0_4
  unsigned __int8 *v73; // eax
  IMaterialVar *v74; // eax
  float v75; // xmm0_4
  IMaterialVar *v76; // ecx
  unsigned __int8 *v77; // eax
  float v78; // xmm0_4
  unsigned __int8 *v79; // eax
  unsigned __int8 *v80; // eax
  __int64 v81; // xmm0_8
  unsigned __int8 *v82; // eax
  IShaderDynamicAPI_vtbl *v83; // edx
  bool (__thiscall *ShouldWriteDepthToDestAlpha)(IShaderDynamicAPI *); // eax
  float v85; // xmm0_4
  bool v86; // cl
  int m_nFlowVortex1; // eax
  int m_nFlowVortex2; // eax
  int v89; // eax
  void (__thiscall *GetCurrentViewport)(IShaderDynamicAPI *, int *, int *, int *, int *); // eax
  int m_nFlowNoiseScale; // ecx
  IMaterialVar *v92; // eax
  float v93; // xmm0_4
  IMaterialVar *v94; // eax
  float v95; // xmm0_4
  int m_nFlowVortexPos2; // eax
  IMaterialVar *v97; // eax
  IMaterialVar *v98; // edx
  float v99; // xmm0_4
  int v100; // eax
  int v101; // eax
  float v102; // xmm0_4
  long double (__thiscall *CurrentTime)(IShaderDynamicAPI *); // eax
  int m_nFlowColorIntensity; // ecx
  void (__thiscall *ExecuteCommandBuffer)(IShaderDynamicAPI *, unsigned __int8 *); // edx
  const char *v106; // [esp-4h] [ebp-218h]
  CCommandBufferBuilder<CFixedCommandStorageBuffer<400> > DynamicCmdsOut; // [esp+Ch] [ebp-208h] BYREF
  int v108; // [esp+1A0h] [ebp-74h]
  solidenergy_vs20_Dynamic_Index _vshIndex; // [esp+1A8h] [ebp-6Ch] BYREF
  BOOL v110; // [esp+1BCh] [ebp-58h]
  float vFlowConst2[4]; // [esp+1C0h] [ebp-54h]
  CSolidEnergy_DX9_Context *pContextData; // [esp+1D0h] [ebp-44h]
  int nRtWidth; // [esp+1D4h] [ebp-40h] BYREF
  int nViewportWidth; // [esp+1D8h] [ebp-3Ch] BYREF
  int nViewportHeight; // [esp+1DCh] [ebp-38h] BYREF
  int nRtHeight; // [esp+1E0h] [ebp-34h] BYREF
  int nViewportX; // [esp+1E4h] [ebp-30h] BYREF
  int nViewportY; // [esp+1E8h] [ebp-2Ch] BYREF
  BOOL v119; // [esp+1ECh] [ebp-28h]
  BOOL v120; // [esp+1F0h] [ebp-24h]
  bool bModel; // [esp+1F6h] [ebp-1Eh]
  bool bAdditiveBlend; // [esp+1F7h] [ebp-1Dh]
  Vector4D flConsts; // [esp+1F8h] [ebp-1Ch] BYREF
  bool bHasVertexColor; // [esp+20Ah] [ebp-Ah]
  bool bWriteDepthToAlpha; // [esp+20Bh] [ebp-9h]
  bool bDepthBlend; // [esp+20Ch] [ebp-8h]
  bool bDetail2; // [esp+20Dh] [ebp-7h]
  bool bTangentT; // [esp+20Eh] [ebp-6h]
  bool bTangentS; // [esp+20Fh] [ebp-5h]
  bool bHasVertexAlpha; // [esp+210h] [ebp-4h]
  bool bDetail1; // [esp+211h] [ebp-3h]
  bool bPowerup; // [esp+212h] [ebp-2h]
  bool bActive; // [esp+213h] [ebp-1h]
  unsigned __int8 bVortex1_3; // [esp+227h] [ebp+13h]
  unsigned __int8 bHasFlowmap_3; // [esp+22Fh] [ebp+1Bh]
  unsigned __int8 bVortex2_3; // [esp+237h] [ebp+23h]

  v7 = *params;
  pContextData = *pContextDataPtr;
  m_intVal = v7->m_intVal;
  m_nDetail1Texture = info->m_nDetail1Texture;
  bWriteDepthToAlpha = (m_intVal & 0x200000) != 0;
  if ( m_nDetail1Texture == -1 || (*((_BYTE *)params[m_nDetail1Texture] + 28) & 0xF) != 3 )
  {
    bDetail1 = false;
LABEL_5:
    bDetail2 = false;
    goto LABEL_6;
  }
  m_nDetail2Texture = info->m_nDetail2Texture;
  bDetail1 = true;
  if ( m_nDetail2Texture == -1 )
    goto LABEL_5;
  v12 = *((_BYTE *)params[m_nDetail2Texture] + 28) & 0xF;
  bDetail2 = true;
  if ( v12 != 3 )
    goto LABEL_5;
LABEL_6:
  if ( (m_intVal & 0x200000) == 0
    || (m_nDepthBlend = info->m_nDepthBlend) == -1
    || (v14 = params[m_nDepthBlend]->m_intVal == 0, bDepthBlend = true, v14) )
  {
    bDepthBlend = false;
  }
  if ( bDetail1 || (m_nFlowMap = info->m_nFlowMap) == -1 || (*((_BYTE *)params[m_nFlowMap] + 28) & 0xF) != 3 )
  {
    bHasFlowmap_3 = 0;
    goto LABEL_14;
  }
  v14 = params[info->m_nFlowCheap]->m_intVal == 0;
  bHasFlowmap_3 = 1;
  bPowerup = true;
  if ( v14 )
LABEL_14:
    bPowerup = false;
  v16 = pShaderAPI;
  if ( CBaseShader::s_pShaderShadow == nullptr && pContextData != nullptr && !pContextData->m_bMaterialVarsChanged )
    goto LABEL_223;
  bAdditiveBlend = (m_intVal & 0x80) != 0;
  bHasVertexColor = (m_intVal & 0x10) != 0;
  bHasVertexAlpha = (m_intVal & 0x20) != 0;
  m_nNeedsTangentT = info->m_nNeedsTangentT;
  bModel = (m_intVal & 0x800) != 0;
  v18 = m_nNeedsTangentT != -1 && params[m_nNeedsTangentT]->m_intVal != 0;
  m_nNeedsTangentS = info->m_nNeedsTangentS;
  bTangentT = v18;
  if ( m_nNeedsTangentS != -1 && params[m_nNeedsTangentS]->m_intVal != 0 && (bTangentS = true, !v18)
    || (bTangentS = false, v18)
    || (m_nNeedsNormals = info->m_nNeedsNormals) == -1
    || (v14 = params[m_nNeedsNormals]->m_intVal == 0, bActive = true, v14) )
  {
    bActive = false;
  }
  m_nDetail1BlendMode = info->m_nDetail1BlendMode;
  if ( m_nDetail1BlendMode == -1 )
    v22 = 0;
  else
    v22 = params[m_nDetail1BlendMode]->m_intVal;
  if ( bDetail1 && v22 >= 0 )
  {
    if ( v22 <= 1 )
      nViewportX = v22;
    else
      nViewportX = 1;
  }
  else
  {
    nViewportX = 0;
  }
  m_nDetail2BlendMode = info->m_nDetail2BlendMode;
  if ( m_nDetail2BlendMode == -1 )
    v24 = 0;
  else
    v24 = params[m_nDetail2BlendMode]->m_intVal;
  v25 = 0;
  if ( bDetail2 && v24 >= 0 )
  {
    if ( v24 <= 1 )
      nViewportY = v24;
    else
      nViewportY = 1;
  }
  else
  {
    nViewportY = 0;
  }
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    v26 = 1025;
    if ( bModel )
    {
      if ( bTangentS || bTangentT || bHasFlowmap_3 != 0 )
      {
        v26 = 132097;
        v25 = 4;
      }
    }
    else
    {
      if ( bTangentS || bTangentT || bHasFlowmap_3 != 0 )
        v26 = 1073;
      if ( !bActive && !bTangentS && !bTangentT && bHasFlowmap_3 == 0 )
        goto LABEL_60;
    }
    v26 |= 2u;
LABEL_60:
    if ( bHasVertexColor || bHasVertexAlpha )
      v26 |= 4u;
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: v26, a3: 1, a4: nullptr, a5: v25);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 95 )
    {
      LODWORD(vFlowConst2[2]) = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v30 = bHasVertexColor || bHasVertexAlpha;
      v110 = v30;
      if ( g_shaderConfigDumpEnable )
      {
        v31 = bHasVertexColor || bHasVertexAlpha;
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", v31, "bHasVertexColor || bHasVertexAlpha");
      }
      v120 = bDetail1;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "DETAIL1", bDetail1, "bDetail1");
      v119 = bDetail2;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "DETAIL2", bDetail2, "bDetail2");
      nRtWidth = bTangentT;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "TANGENTTOPACITY", bTangentT, "bTangentT");
      nViewportWidth = bTangentS;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "TANGENTSOPACITY", bTangentS, "bTangentS");
      nRtHeight = bActive;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FRESNELOPACITY", bActive, "bFresnel");
      nViewportHeight = bHasFlowmap_3 != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FLOWMAP", bHasFlowmap_3, "bHasFlowmap");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "MODELFORMAT", bModel, "bModel");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "solidenergy_vs30",
        a3: 32
      * (v120
       + 2
       * (v119
        + 2
        * (nRtWidth
         + 2
         * (nViewportWidth
          + 2 * (nRtHeight + 2 * (v110 + 2 * (nViewportHeight + 2 * (bModel + 2 * LODWORD(vFlowConst2[2]))))))))));
    }
    else
    {
      solidenergy_vs20_Static_Index::solidenergy_vs20_Static_Index(
        this: (solidenergy_vs20_Static_Index *)&_vshIndex,
        pShaderShadow,
        params);
      v27 = bHasVertexColor || bHasVertexAlpha;
      v110 = v27;
      if ( g_shaderConfigDumpEnable )
      {
        v28 = bHasVertexColor || bHasVertexAlpha;
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", v28, "bHasVertexColor || bHasVertexAlpha");
      }
      v120 = bDetail1;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "DETAIL1", bDetail1, "bDetail1");
      v119 = bDetail2;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "DETAIL2", bDetail2, "bDetail2");
      nRtWidth = bTangentT;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "TANGENTTOPACITY", bTangentT, "bTangentT");
      nViewportWidth = bTangentS;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "TANGENTSOPACITY", bTangentS, "bTangentS");
      nRtHeight = bActive;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FRESNELOPACITY", bActive, "bFresnel");
      nViewportHeight = bHasFlowmap_3 != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FLOWMAP", bHasFlowmap_3, "bHasFlowmap");
      v29 = bModel;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "MODELFORMAT", bModel, "bModel");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "solidenergy_vs20",
        a3: 32
      * (v120
       + 2
       * (v119
        + 2
        * (nRtWidth
         + 2
         * (nViewportWidth
          + 2
          * (nRtHeight
           + 2
           * (v110 + 2 * (nViewportHeight + 2 * (v29 + 2 * (LODWORD(vFlowConst2[2]) + 2 * LODWORD(vFlowConst2[3])))))))))));
    }
    v32 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v33 = 0;
    if ( v32 >= 95 )
    {
      LOBYTE(v33) = bAdditiveBlend;
      v108 = v33;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "ADDITIVE", bAdditiveBlend, "bAdditiveBlend");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL1", bDetail1, "bDetail1");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL2", bDetail2, "bDetail2");
            if ( g_shaderConfigDumpEnable )
            {
              printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL1BLENDMODE", nViewportX, "nDetail1BlendMode");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL2BLENDMODE", nViewportY, "nDetail2BlendMode");
            }
          }
        }
      }
      v37 = bHasVertexColor || bHasVertexAlpha;
      LODWORD(vFlowConst2[1]) = v37;
      if ( g_shaderConfigDumpEnable )
      {
        v38 = bHasVertexColor || bHasVertexAlpha;
        printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", v38, "( bHasVertexColor || bHasVertexAlpha )");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "TANGENTTOPACITY", bTangentT, "bTangentT");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "TANGENTSOPACITY", bTangentS, "bTangentS");
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "FRESNELOPACITY", bActive, "bFresnel");
          }
        }
      }
      LODWORD(vFlowConst2[0]) = bDepthBlend;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "DEPTHBLEND", bDepthBlend, "bDepthBlend");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "FLOWMAP", bHasFlowmap_3, "bHasFlowmap");
      }
      v39 = bPowerup;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLOW_CHEAP", bPowerup, "bHasCheapFlow");
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "solidenergy_ps30",
        a3: 32
      * (v108
       + 2
       * (v120
        + 2
        * (nViewportX
         + 2
         * (v119
          + 2
          * (nViewportY
           + 2
           * (nRtWidth
            + 2
            * (nViewportWidth
             + 2
             * (nRtHeight + 2 * (LODWORD(vFlowConst2[0]) + LODWORD(vFlowConst2[1]) + 2 * (nViewportHeight + 2 * v39)))))))))));
    }
    else
    {
      LOBYTE(v33) = bAdditiveBlend;
      v108 = v33;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "ADDITIVE", bAdditiveBlend, "bAdditiveBlend");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL1", bDetail1, "bDetail1");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL2", bDetail2, "bDetail2");
            if ( g_shaderConfigDumpEnable )
            {
              printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL1BLENDMODE", nViewportX, "nDetail1BlendMode");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL2BLENDMODE", nViewportY, "nDetail2BlendMode");
            }
          }
        }
      }
      v34 = bHasVertexColor || bHasVertexAlpha;
      LODWORD(vFlowConst2[1]) = v34;
      if ( g_shaderConfigDumpEnable )
      {
        v35 = bHasVertexColor || bHasVertexAlpha;
        printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", v35, "( bHasVertexColor || bHasVertexAlpha )");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "TANGENTTOPACITY", bTangentT, "bTangentT");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "TANGENTSOPACITY", bTangentS, "bTangentS");
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "FRESNELOPACITY", bActive, "bFresnel");
          }
        }
      }
      LODWORD(vFlowConst2[0]) = bDepthBlend;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "DEPTHBLEND", bDepthBlend, "bDepthBlend");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "FLOWMAP", bHasFlowmap_3, "bHasFlowmap");
      }
      v36 = bPowerup;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLOW_CHEAP", bPowerup, "bHasCheapFlow");
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "solidenergy_ps20b",
        a3: 32
      * (v108
       + 2
       * (v120
        + 2
        * (nViewportX
         + 2
         * (v119
          + 2
          * (nViewportY
           + 2
           * (nRtWidth
            + 2
            * (nViewportWidth
             + 2
             * (nRtHeight + 2 * (LODWORD(vFlowConst2[0]) + LODWORD(vFlowConst2[1]) + 2 * (nViewportHeight + 2 * v36)))))))))));
    }
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    if ( bDetail1 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    }
    if ( bDetail2 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    }
    if ( bDepthBlend )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: false);
    }
    if ( bHasFlowmap_3 != 0 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: false);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: false);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: false);
    }
    if ( bWriteDepthToAlpha )
    {
      v40 = bAdditiveBlend;
      if ( bAdditiveBlend )
        CBaseShader::EnableAlphaBlending(this: pShader, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE);
      else
        CBaseShader::EnableAlphaBlending(
          this: pShader,
          src: SHADER_BLEND_SRC_ALPHA,
          dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
      v41 = ((int (__thiscall *)(IShaderShadow *, _DWORD))pShaderShadow->EnableAlphaWrites)(a1: pShaderShadow, a2: 0);
      if ( bDepthBlend || v40 )
      {
        LOBYTE(v41) = 0;
        pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: v41);
      }
      else
      {
        LOBYTE(v41) = 1;
        pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: v41);
      }
    }
    else
    {
      CBaseShader::DisableAlphaBlending(this: pShader);
      pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
      pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: true);
    }
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    v16 = pShaderAPI;
  }
  if ( v16 == nullptr )
    goto LABEL_273;
  if ( pContextData != nullptr )
  {
    if ( !pContextData->m_bMaterialVarsChanged )
      goto LABEL_223;
  }
  else
  {
    v42 = (CSolidEnergy_DX9_Context *)operator new(nSize: 0x330u);
    if ( v42 != nullptr )
    {
      v42->m_bMaterialVarsChanged = true;
      v42->m_nVarChangeID = -1;
      v42->__vftable = (CSolidEnergy_DX9_Context_vtbl *)&CSolidEnergy_DX9_Context::`vftable';
      v42->m_SemiStaticCmdsOut.m_Storage.m_pDataOut = v42->m_SemiStaticCmdsOut.m_Storage.m_Data;
    }
    else
    {
      v42 = nullptr;
    }
    pContextData = v42;
    *pContextDataPtr = v42;
  }
  v43 = pContextData;
  pContextData->m_bMaterialVarsChanged = false;
  p_m_SemiStaticCmdsOut = &v43->m_SemiStaticCmdsOut;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = (unsigned __int8 *)p_m_SemiStaticCmdsOut;
  if ( info->m_nBaseTextureTransform != -1 )
    CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureTransform(
      this: p_m_SemiStaticCmdsOut,
      vertexReg: 48,
      transformVar: info->m_nBaseTextureTransform);
  if ( info->m_nDetail1TextureTransform >= 0
    && (v45 = params[info->m_nDetail1TextureTransform], v45->IsDefined(this: v45)) )
  {
    CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureScaledTransform(
      this: p_m_SemiStaticCmdsOut,
      vertexReg: 50,
      transformVar: info->m_nDetail1TextureTransform,
      scaleVar: info->m_nDetail1Scale);
  }
  else
  {
    CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureScaledTransform(
      this: p_m_SemiStaticCmdsOut,
      vertexReg: 50,
      transformVar: info->m_nBaseTextureTransform,
      scaleVar: info->m_nDetail1Scale);
  }
  if ( info->m_nDetail2TextureTransform >= 0
    && (v46 = params[info->m_nDetail2TextureTransform], v46->IsDefined(this: v46)) )
  {
    CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureScaledTransform(
      this: p_m_SemiStaticCmdsOut,
      vertexReg: 54,
      transformVar: info->m_nDetail2TextureTransform,
      scaleVar: info->m_nDetail2Scale);
  }
  else
  {
    CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureScaledTransform(
      this: p_m_SemiStaticCmdsOut,
      vertexReg: 54,
      transformVar: info->m_nBaseTextureTransform,
      scaleVar: info->m_nDetail2Scale);
  }
  ShaderAPITextureBindHandle = CBaseShader::GetShaderAPITextureBindHandle(
                                 this: pShader,
                                 nTextureVar: 6,
                                 nFrameVar: -1,
                                 nTextureChannel: 0);
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 0x80000000;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = ShaderAPITextureBindHandle;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  if ( bHasFlowmap_3 != 0 )
  {
    v48 = CBaseShader::GetShaderAPITextureBindHandle(
            this: pShader,
            nTextureVar: info->m_nFlowMap,
            nFrameVar: info->m_nFlowMapFrame,
            nTextureChannel: 0);
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 5;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v48;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v49 = CBaseShader::GetShaderAPITextureBindHandle(
            this: pShader,
            nTextureVar: info->m_nFlowNoiseTexture,
            nFrameVar: -1,
            nTextureChannel: 0);
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 6;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v49;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v50 = CBaseShader::GetShaderAPITextureBindHandle(
            this: pShader,
            nTextureVar: info->m_nFlowBoundsTexture,
            nFrameVar: -1,
            nTextureChannel: 0);
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 7;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v50;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  }
  if ( info->m_nTangentTOpacityRanges >= 0 && (v51 = params[info->m_nTangentTOpacityRanges], v51->IsDefined(this: v51)) )
  {
    flConsts = params[info->m_nTangentTOpacityRanges]->m_VecVal;
  }
  else
  {
    *(_QWORD *)&flConsts.x = 0x3F6666663F800000LL;
    *(_QWORD *)&flConsts.z = *(_QWORD *)&kDefaultFalloffRanges[2];
  }
  v52 = *(_QWORD *)&flConsts.x;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 0;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  m_pDataOut = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
  *(_QWORD *)m_pDataOut = v52;
  *((_QWORD *)m_pDataOut + 1) = *(_QWORD *)&flConsts.z;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
  if ( info->m_nTangentSOpacityRanges >= 0 && (v54 = params[info->m_nTangentSOpacityRanges], v54->IsDefined(this: v54)) )
  {
    flConsts = params[info->m_nTangentSOpacityRanges]->m_VecVal;
  }
  else
  {
    *(_QWORD *)&flConsts.x = 0x3F6666663F800000LL;
    *(_QWORD *)&flConsts.z = *(_QWORD *)&kDefaultFalloffRanges[2];
  }
  v55 = *(_QWORD *)&flConsts.x;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  v56 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
  *(_QWORD *)v56 = v55;
  *((_QWORD *)v56 + 1) = *(_QWORD *)&flConsts.z;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
  if ( info->m_nFresnelOpacityRanges >= 0 && (v57 = params[info->m_nFresnelOpacityRanges], v57->IsDefined(this: v57)) )
  {
    v58 = params;
    flConsts = params[info->m_nFresnelOpacityRanges]->m_VecVal;
    v59 = *(_QWORD *)&flConsts.z;
    v60 = *(_QWORD *)&flConsts.x;
  }
  else
  {
    v60 = *(_QWORD *)kDefaultFalloffRanges;
    v59 = *(_QWORD *)&kDefaultFalloffRanges[2];
    v58 = params;
  }
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 2;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  v61 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
  *(_QWORD *)v61 = v60;
  *((_QWORD *)v61 + 1) = v59;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
  x = v58[info->m_nDepthBlendScale]->m_VecVal.x;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 8;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 4;
  v63 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
  *((float *)v63 + 1) = x;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v63 + 8;
  flConsts.w = v58[info->m_nOutputIntensity]->m_VecVal.x;
  if ( bHasFlowmap_3 != 0 )
  {
    v64 = v58[info->m_nFlowWorldUVScale]->m_VecVal.x;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 6;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v65 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    *(_QWORD *)&flConsts.x = LODWORD(v64);
    *(_QWORD *)v65 = LODWORD(v64);
    flConsts.z = 0.0;
    *((_QWORD *)v65 + 1) = *(_QWORD *)&flConsts.z;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
    v66 = v58[info->m_nFlowUVScrollDistance];
    flConsts.x = v58[info->m_nFlowTimeIntervalInSeconds]->m_VecVal.x;
    v67 = v66->m_VecVal.x;
    v68 = v58[info->m_nFlowLerpExp];
    flConsts.y = v67;
    v69 = v68->m_VecVal.x;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 7;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v70 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    flConsts.w = v69;
    *(_QWORD *)v70 = *(_QWORD *)&flConsts.x;
    flConsts.z = 0.0;
    *((_QWORD *)v70 + 1) = *(_QWORD *)&flConsts.z;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
    v71 = v58[info->m_nFlowColor];
    *(_QWORD *)&flConsts.x = *(_QWORD *)&v71->m_VecVal.x;
    z = v71->m_VecVal.z;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 8;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v73 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    flConsts.z = z;
    *(_QWORD *)v73 = *(_QWORD *)&flConsts.x;
    flConsts.w = 0.0;
    *((_QWORD *)v73 + 1) = LODWORD(flConsts.z);
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
    v74 = v58[info->m_nFlowVortexColor];
    flConsts.x = v74->m_VecVal.x;
    flConsts.y = v74->m_VecVal.y;
    v75 = v74->m_VecVal.z;
    v76 = v58[info->m_nFlowVortexSize];
    v77 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    flConsts.z = v75;
    v78 = v76->m_VecVal.x;
    *(_DWORD *)v77 = 3;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v79 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    flConsts.w = v78;
    *(_DWORD *)v79 = 9;
  }
  else
  {
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v80 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    memset(&flConsts, 0, 12);
    *(_DWORD *)v80 = 6;
  }
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  v81 = *(_QWORD *)&flConsts.x;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  v82 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
  *(_QWORD *)v82 = v81;
  *((_QWORD *)v82 + 1) = *(_QWORD *)&flConsts.z;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 0;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  v16 = pShaderAPI;
LABEL_223:
  if ( v16 != nullptr )
  {
    if ( v16->InFlashlightMode(this: v16) )
    {
      CBaseShader::Draw(this: pShader, bMakeActualDrawCall: false);
      return;
    }
    v83 = v16->__vftable;
    *(_DWORD *)&DynamicCmdsOut.m_Storage.m_Data[4] = &pContextData->m_SemiStaticCmdsOut;
    DynamicCmdsOut.m_Storage.m_pDataOut = &DynamicCmdsOut.m_Storage.m_Data[8];
    ShouldWriteDepthToDestAlpha = v83->ShouldWriteDepthToDestAlpha;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_Data = 2;
    if ( !ShouldWriteDepthToDestAlpha(this: v16) || (v14 = !bWriteDepthToAlpha, bWriteDepthToAlpha = true, !v14) )
      bWriteDepthToAlpha = false;
    v85 = params[info->m_nPowerUp]->m_VecVal.x;
    v86 = params[info->m_nFlowColorIntensity]->m_VecVal.x > 0.0;
    bActive = v86;
    if ( bHasFlowmap_3 != 0 && v85 <= 0.0 )
    {
      v86 = false;
      bActive = false;
    }
    else if ( v86 && bHasFlowmap_3 != 0 && v85 > 0.0 )
    {
      bPowerup = true;
      if ( v85 < 1.0 )
        goto LABEL_237;
    }
    bPowerup = false;
LABEL_237:
    if ( !v86
      || bHasFlowmap_3 == 0
      || (m_nFlowVortex1 = info->m_nFlowVortex1) == -1
      || (bVortex1_3 = 1, params[m_nFlowVortex1]->m_intVal == 0) )
    {
      bVortex1_3 = 0;
    }
    if ( !v86
      || bHasFlowmap_3 == 0
      || (m_nFlowVortex2 = info->m_nFlowVortex2) == -1
      || (bVortex2_3 = 1, params[m_nFlowVortex2]->m_intVal == 0) )
    {
      bVortex2_3 = 0;
    }
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    LODWORD(vFlowConst2[3]) = v16->GetSceneFogMode(this: v16) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    LODWORD(vFlowConst2[0]) = v16->GetCurrentNumBones(this: v16) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v89 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))v16->GetCurrentNumBones)(
              a1: v16,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v89 > 0, v106);
    }
    v119 = bVortex1_3 != 0;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "VORTEX1", bVortex1_3, "bVortex1");
    v120 = bVortex2_3 != 0;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "VORTEX2", bVortex2_3, "bVortex2");
    v16->SetVertexShaderIndex(
      this: v16,
      a2: vertexCompression + 2 * (LODWORD(vFlowConst2[0]) + 2 * (v119 + 2 * (v120 + 2 * LODWORD(vFlowConst2[3])))));
    GetCurrentViewport = v16->GetCurrentViewport;
    memset(&flConsts, 0, sizeof(flConsts));
    GetCurrentViewport(this: v16, a2: &nViewportX, a3: &nViewportY, a4: &nViewportWidth, a5: &nViewportHeight);
    v16->GetCurrentRenderTargetDimensions(this: v16, a2: &nRtWidth, a3: &nRtHeight);
    v16->GetWorldSpaceCameraPosition(this: v16, a2: &flConsts.x);
    flConsts.w = 0.0;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 4;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 52;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = *(_QWORD *)&flConsts.x;
    *((_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut + 1) = *(_QWORD *)&flConsts.z;
    DynamicCmdsOut.m_Storage.m_pDataOut += 16;
    flConsts.x = (float)((float)nViewportWidth / (float)nRtWidth) * 0.5;
    flConsts.y = (float)((float)nViewportHeight / (float)nRtHeight) * -0.5;
    flConsts.z = (float)((float)nViewportX / (float)nRtWidth) + flConsts.x;
    flConsts.w = (float)((float)nViewportY / (float)nRtHeight) - flConsts.y;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 3;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 15;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = *(_QWORD *)&flConsts.x;
    *((_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut + 1) = *(_QWORD *)&flConsts.z;
    DynamicCmdsOut.m_Storage.m_pDataOut += 16;
    if ( bHasFlowmap_3 != 0 )
    {
      m_nFlowNoiseScale = info->m_nFlowNoiseScale;
      v92 = params[info->m_nFlowVortexPos1];
      *(_QWORD *)vFlowConst2 = *(_QWORD *)&v92->m_VecVal.x;
      v93 = v92->m_VecVal.z;
      v94 = params[m_nFlowNoiseScale];
      vFlowConst2[2] = v93;
      v95 = v94->m_VecVal.x;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 4;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 57;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      vFlowConst2[3] = v95;
      *(_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = *(_QWORD *)vFlowConst2;
      *((_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut + 1) = *(_QWORD *)&vFlowConst2[2];
      m_nFlowVortexPos2 = info->m_nFlowVortexPos2;
      DynamicCmdsOut.m_Storage.m_pDataOut += 16;
      v97 = params[m_nFlowVortexPos2];
      *(_QWORD *)vFlowConst2 = *(_QWORD *)&v97->m_VecVal.x;
      v98 = params[info->m_nFlowNormalUVScale];
      vFlowConst2[2] = v97->m_VecVal.z;
      v99 = v98->m_VecVal.x;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 4;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 14;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      vFlowConst2[3] = v99;
      *(_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = *(_QWORD *)vFlowConst2;
      *((_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut + 1) = *(_QWORD *)&vFlowConst2[2];
      DynamicCmdsOut.m_Storage.m_pDataOut += 16;
    }
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    LODWORD(vFlowConst2[3]) = v16->GetSceneFogMode(this: v16) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v110 = bActive;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "ACTIVE", bActive, "bActive");
    LODWORD(vFlowConst2[0]) = bPowerup;
    if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   PS dyn  var %s = %d (%s)", "POWERUP", bPowerup, "bPowerup");
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS dyn  var %s = %d (%s)", "VORTEX1", bVortex1_3, "bVortex1");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "VORTEX2", bVortex2_3, "bVortex2");
      }
    }
    v16->SetPixelShaderIndex(
      this: v16,
      a2: v110 + 2 * (LODWORD(vFlowConst2[0]) + 2 * (v119 + 2 * (v120 + 2 * LODWORD(vFlowConst2[3])))));
    if ( bDetail1 )
    {
      v100 = CBaseShader::GetShaderAPITextureBindHandle(
               this: pShader,
               nTextureVar: info->m_nDetail1Texture,
               nFrameVar: info->m_nDetail1Frame,
               nTextureChannel: 0);
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 10;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = -2147483647;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v100;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    }
    if ( bDetail2 )
    {
      v101 = CBaseShader::GetShaderAPITextureBindHandle(
               this: pShader,
               nTextureVar: info->m_nDetail2Texture,
               nFrameVar: info->m_nDetail2Frame,
               nTextureChannel: 0);
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 10;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = -2147483644;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v101;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    }
    if ( bDepthBlend )
    {
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 9;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 3;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 23;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    }
    if ( bWriteDepthToAlpha )
      v102 = 1.0;
    else
      v102 = 0.0;
    CurrentTime = v16->CurrentTime;
    flConsts.x = v102;
    flConsts.y = CurrentTime(this: v16);
    m_nFlowColorIntensity = info->m_nFlowColorIntensity;
    flConsts.z = params[info->m_nPowerUp]->m_VecVal.x;
    flConsts.w = params[m_nFlowColorIntensity]->m_VecVal.x;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 3;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 3;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = *(_QWORD *)&flConsts.x;
    *((_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut + 1) = *(_QWORD *)&flConsts.z;
    DynamicCmdsOut.m_Storage.m_pDataOut += 16;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 0;
    ExecuteCommandBuffer = v16->ExecuteCommandBuffer;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    ExecuteCommandBuffer(this: v16, a2: DynamicCmdsOut.m_Storage.m_Data);
  }
LABEL_273:
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
