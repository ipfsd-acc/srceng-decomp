// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/decalmodulate_dx9.cpp
// Functions: 29
// ============================================================

#include "materialsystem\stdshaders\decalmodulate_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1000AAC0
// Name: public: virtual char const __near * DecalModulate::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DecalModulate::CShader::GetFallbackShader(DecalModulate::CShader *this, IMaterialVar **params)
{
  return "DecalModulate_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x1000AAD0
// Name: public: virtual char const __near * DecalModulate::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DecalModulate::CShader::GetName(DecalModulate::CShader *this)
{
  return s_Name_21;
}

//------------------------------------------------------------------------------
// Address: 0x1000AAE0
// Name: public: virtual int DecalModulate::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DecalModulate::CShader::GetFlags(DecalModulate::CShader *this)
{
  return s_nFlags_59;
}

//------------------------------------------------------------------------------
// Address: 0x1000AAF0
// Name: public: virtual int DecalModulate::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DecalModulate::CShader::GetParamCount(DecalModulate::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_21.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000AB00
// Name: public: decalmodulate_vs30_Dynamic_Index::decalmodulate_vs30_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
decalmodulate_vs30_Dynamic_Index *__thiscall decalmodulate_vs30_Dynamic_Index::decalmodulate_vs30_Dynamic_Index(
        decalmodulate_vs30_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  MaterialFogMode_t v3; // eax

  this->m_nCOMPRESSED_VERTS = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
  this->m_nSKINNING = 0;
  this->m_nDOWATERFOG = v3 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nMORPHING = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000AB50
// Name: public: virtual void DecalModulate_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DecalModulate_dx9::CShader::OnInitShaderParams(
        DecalModulate_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( !params[FOGEXPONENT.m_Index]->IsDefined(this: params[FOGEXPONENT.m_Index]) )
    ((void (__stdcall *)(int))params[FOGEXPONENT.m_Index]->SetFloatValue)(a1: 1053609165);
  if ( !params[FOGSCALE.m_Index]->IsDefined(this: params[FOGSCALE.m_Index]) )
    ((void (__stdcall *)(int))params[FOGSCALE.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[FOGFADESTART.m_Index]->IsDefined(this: params[FOGFADESTART.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[FOGFADESTART.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[FOGFADEEND.m_Index]->IsDefined(this: params[FOGFADEEND.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[FOGFADEEND.m_Index]->SetFloatValue)(a1: 0);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 2);
  if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
  {
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AC70
// Name: public: virtual char const __near * DecalModulate_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DecalModulate_dx9::CShader::GetName(DecalModulate_dx9::CShader *this)
{
  return s_Name_22;
}

//------------------------------------------------------------------------------
// Address: 0x1000AC80
// Name: public: virtual int DecalModulate_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DecalModulate_dx9::CShader::GetFlags(DecalModulate_dx9::CShader *this)
{
  return s_nFlags_60;
}

//------------------------------------------------------------------------------
// Address: 0x1000ACA0
// Name: public: virtual void DecalModulate_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DecalModulate_dx9::CShader::OnDrawElements(
        DecalModulate_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IShaderShadow *v6; // esi
  DecalModulate_dx9::CShader *v7; // edi
  int v8; // edi
  bool v9; // bl
  BOOL v10; // edi
  BOOL v11; // edi
  BOOL v12; // edi
  BOOL v13; // edi
  BOOL v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // ebx
  IShaderDynamicAPI *v18; // esi
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v21; // edx
  float x; // xmm0_4
  IMaterialVar *v23; // edx
  int x_low; // xmm0_4
  IMaterialVar *v25; // edx
  int v26; // xmm0_4
  IMaterialVar *v27; // edx
  IShaderDynamicAPI_vtbl *v28; // eax
  int v29; // xmm0_4
  void (__thiscall *v30)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v31; // ebx
  int v32; // eax
  int v33; // eax
  VertexCompressionType_t v34; // ebx
  BOOL v35; // edi
  int v36; // eax
  int v37; // eax
  bool (__thiscall *IsHWMorphingEnabled)(IShaderDynamicAPI *); // eax
  bool v39; // al
  void (__thiscall *MarkUnusedVertexFields)(IShaderDynamicAPI *, unsigned int, int, bool *); // edx
  const char *v41; // [esp+4h] [ebp-68h]
  Vector4D transformation[2]; // [esp+14h] [ebp-58h] BYREF
  decalmodulate_vs30_Dynamic_Index _vshIndex; // [esp+34h] [ebp-38h] BYREF
  float vEyePos_SpecExponent[4]; // [esp+44h] [ebp-28h] BYREF
  float v45; // [esp+54h] [ebp-18h] BYREF
  int pTexCoordDim[3]; // [esp+58h] [ebp-14h] BYREF
  DecalModulate_dx9::CShader *v47; // [esp+64h] [ebp-8h]
  BOOL v48; // [esp+68h] [ebp-4h]

  v6 = pShaderShadow;
  v7 = this;
  v47 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: true);
    ((void (__thiscall *)(IShaderShadow *, int, _DWORD))v6->AlphaFunc)(a1: v6, a2: 4, a3: 0);
    v6->EnableDepthWrites(this: v6, a2: false);
    v6->EnablePolyOffset(this: v6, a2: SHADER_POLYOFFSET_DECAL);
    v6->EnableTexture(this: v6, a2: SHADER_SAMPLER0, a3: true);
    v6->EnableAlphaWrites(this: v6, a2: false);
    v6->EnableSRGBRead(this: v6, a2: SHADER_SAMPLER0, a3: false);
    v6->EnableSRGBWrite(this: v6, a2: false);
    v6->EnableBlending(this: v6, a2: true);
    v6->BlendFunc(this: v6, a2: SHADER_BLEND_DST_COLOR, a3: SHADER_BLEND_SRC_COLOR);
    v6->DisableFogGammaCorrection(this: v6, a2: true);
    CBaseShader::FogToGrey(this: v7);
    v8 = ((params[2]->m_intVal & 0x100000) != 0) + 2 * ((params[2]->m_intVal & 0x200000) != 0);
    v9 = ((*params)->m_intVal & 0x10) != 0 && ((*params)->m_intVal & 0x20) != 0;
    HIBYTE(pShaderShadow) = params[FOGFADEEND.m_Index]->m_VecVal.x > 0.0;
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      _vshIndex.m_nSKINNING = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v48 = v9;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", v9, "bHasVertexAlpha");
      v13 = v8 != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "LIGHTING_PREVIEW", v13, "nLightingPreviewMode != 0");
      v6->SetVertexShader(this: v6, a2: "decalmodulate_vs30", a3: 16 * (v48 + 2 * (v13 + 2 * _vshIndex.m_nSKINNING)));
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXALPHA", v9, "bHasVertexAlpha");
      v14 = HIBYTE(pShaderShadow) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FOGFADE", HIBYTE(pShaderShadow), "bHasFogFade");
      v6->SetPixelShader(this: v6, a2: "decalmodulate_ps30", a3: 2 * (v48 + 2 * v14));
    }
    else
    {
      LODWORD(vEyePos_SpecExponent[2]) = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      LODWORD(vEyePos_SpecExponent[3]) = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      v48 = v9;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", v9, "bHasVertexAlpha");
      v10 = v8 != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "LIGHTING_PREVIEW", v10, "nLightingPreviewMode != 0");
      v6->SetVertexShader(
        this: v6,
        a2: "decalmodulate_vs20",
        a3: 4 * (v48 + 2 * (v10 + 2 * (LODWORD(vEyePos_SpecExponent[2]) + 2 * LODWORD(vEyePos_SpecExponent[3])))));
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXALPHA", v9, "bHasVertexAlpha");
        v12 = HIBYTE(pShaderShadow) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "FOGFADE", HIBYTE(pShaderShadow), "bHasFogFade");
        v6->SetPixelShader(this: v6, a2: "decalmodulate_ps20", a3: 2 * (v48 + 2 * v12));
      }
      else
      {
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXALPHA", v9, "bHasVertexAlpha");
        v11 = HIBYTE(pShaderShadow) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "FOGFADE", HIBYTE(pShaderShadow), "bHasFogFade");
        v6->SetPixelShader(this: v6, a2: "decalmodulate_ps20b", a3: 2 * (v48 + 2 * v11));
      }
    }
    v15 = 1025;
    if ( v9 )
      v15 = 1029;
    v16 = (g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) ? 2 : 0) | v15;
    pTexCoordDim[0] = 2;
    pTexCoordDim[1] = 0;
    pTexCoordDim[2] = 3;
    v17 = 1;
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
      v17 = 3;
    v6->VertexShaderVertexFormat(this: v6, a2: v16, a3: v17, a4: pTexCoordDim, a5: 0);
    v7 = v47;
  }
  v18 = pShaderAPI;
  if ( pShaderAPI == nullptr )
    goto LABEL_48;
  if ( pShaderAPI->InFlashlightMode(this: pShaderAPI) )
  {
    CBaseShader::Draw(this: v7, bMakeActualDrawCall: false);
    return;
  }
  CBaseShader::BindTexture(
    this: v7,
    sampler1: SHADER_SAMPLER0,
    nBindFlags: TEXTURE_BINDFLAGS_NONE,
    nTextureVar: 6,
    nFrameVar: 7);
  SetVertexShaderConstant = v18->SetVertexShaderConstant;
  transformation[0].x = 1.0;
  transformation[0].y = 0.0;
  transformation[0].z = 0.0;
  transformation[0].w = 0.0;
  transformation[1].x = 0.0;
  transformation[1].y = 1.0;
  transformation[1].z = 0.0;
  transformation[1].w = 0.0;
  SetVertexShaderConstant(this: v18, a2: 48, a3: &transformation[0].x, a4: 2, a5: false);
  v18->SetPixelShaderFogParams(this: v18, a2: 12);
  v18->GetWorldSpaceCameraPosition(this: v18, a2: vEyePos_SpecExponent);
  SetPixelShaderConstant = v18->SetPixelShaderConstant;
  vEyePos_SpecExponent[3] = 0.0;
  SetPixelShaderConstant(this: v18, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
  v21 = params[FOGEXPONENT.m_Index];
  v45 = 0.0;
  memset(pTexCoordDim, 0, sizeof(pTexCoordDim));
  x = v21->m_VecVal.x;
  v23 = params[FOGSCALE.m_Index];
  v45 = x;
  x_low = LODWORD(v23->m_VecVal.x);
  v25 = params[FOGFADESTART.m_Index];
  pTexCoordDim[0] = x_low;
  v26 = LODWORD(v25->m_VecVal.x);
  v27 = params[FOGFADEEND.m_Index];
  v28 = v18->__vftable;
  pTexCoordDim[1] = v26;
  v29 = LODWORD(v27->m_VecVal.x);
  v30 = v28->SetPixelShaderConstant;
  pTexCoordDim[2] = v29;
  v30(this: v18, a2: 0, a3: &v45, a4: 1, a5: false);
  if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
  {
    CBaseVSShader::SetHWMorphVertexShaderState(
      this: v7,
      nDimConst: 54,
      nSubrectConst: 55,
      morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
    decalmodulate_vs30_Dynamic_Index::decalmodulate_vs30_Dynamic_Index(this: &_vshIndex, pShaderAPI: v18);
    v33 = v18->GetCurrentNumBones(this: v18);
    v34 = vertexCompression;
    v35 = v33 > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v36 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))v18->GetCurrentNumBones)(
              a1: v18,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v36 > 0, v41);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", v34, "(int)vertexCompression");
    }
    v18->SetVertexShaderIndex(
      this: v18,
      a2: v34 + 2 * (_vshIndex.m_nDOWATERFOG + 2 * (v35 + 2 * _vshIndex.m_nMORPHING)));
    v37 = v18->GetSceneFogMode(this: v18);
    v18->SetPixelShaderIndex(this: v18, a2: v37 == 2);
    IsHWMorphingEnabled = v18->IsHWMorphingEnabled;
    LOWORD(params) = 0;
    v39 = IsHWMorphingEnabled(this: v18);
    MarkUnusedVertexFields = v18->MarkUnusedVertexFields;
    BYTE2(params) = !v39;
    MarkUnusedVertexFields(this: v18, a2: 0, a3: 3, a4: (bool *)&params);
    v7 = v47;
LABEL_48:
    CBaseShader::Draw(this: v7, bMakeActualDrawCall: true);
    return;
  }
  v31 = v18->GetSceneFogMode(this: v18) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  if ( g_shaderConfigDumpEnable )
  {
    printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", 0, "0");
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
  }
  v18->SetVertexShaderIndex(this: v18, a2: vertexCompression + 2 * v31);
  g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
  v32 = v18->GetSceneFogMode(this: v18);
  v18->SetPixelShaderIndex(this: v18, a2: v32 == 2);
  CBaseShader::Draw(this: v7, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000B3A0
// Name: public: virtual int DecalModulate_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DecalModulate_dx9::CShader::GetParamCount(DecalModulate_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_22.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000B3B0
// Name: public: virtual struct ShaderParamInfo_t const __near & DecalModulate::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DecalModulate::CShaderParam *__thiscall DecalModulate::CShader::GetParamInfo(DecalModulate::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_21.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DecalModulate::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000B3E0
// Name: public: virtual struct ShaderParamInfo_t const __near & DecalModulate_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DecalModulate_dx9::CShaderParam *__thiscall DecalModulate_dx9::CShader::GetParamInfo(
        DecalModulate_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_22.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DecalModulate_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000B410
// Name: public: DecalModulate_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DecalModulate_dx9::CShaderParam *__thiscall DecalModulate_dx9::CShaderParam::CShaderParam(
        DecalModulate_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  DecalModulate_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  DecalModulate_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_22.m_Size + 13;
  m_Size = s_ShaderParams_22.m_Size;
  v8 = s_ShaderParams_22.m_Size;
  if ( s_ShaderParams_22.m_Size + 1 > s_ShaderParams_22.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_22,
      num: s_ShaderParams_22.m_Size - s_ShaderParams_22.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_22.m_Size;
  }
  m_pMemory = s_ShaderParams_22.m_Memory.m_pMemory;
  s_ShaderParams_22.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_22.m_pElements = s_ShaderParams_22.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_22.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_22.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_22.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005F940
// Name: DecalModulate::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DecalModulate::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DecalModulate::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005F950
// Name: DecalModulate::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DecalModulate::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_21);
  s_ShaderInstance_21.__vftable = (DecalModulate::CShader_vtbl *)&DecalModulate::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005F970
// Name: DecalModulate_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DecalModulate_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DecalModulate_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005F980
// Name: DecalModulate_dx9::_dynamic_initializer_for__FOGEXPONENT__
// Source: json
//------------------------------------------------------------------------------
DecalModulate_dx9::CShaderParam *DecalModulate_dx9::_dynamic_initializer_for__FOGEXPONENT__()
{
  return DecalModulate_dx9::CShaderParam::CShaderParam(
           this: &FOGEXPONENT,
           pName: "$FOGEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.4",
           pHelp: "exponent to tweak fog fade",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F9A0
// Name: DecalModulate_dx9::_dynamic_initializer_for__FOGSCALE__
// Source: json
//------------------------------------------------------------------------------
DecalModulate_dx9::CShaderParam *DecalModulate_dx9::_dynamic_initializer_for__FOGSCALE__()
{
  return DecalModulate_dx9::CShaderParam::CShaderParam(
           this: &FOGSCALE,
           pName: "$FOGSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "scale to tweak fog fade",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F9C0
// Name: DecalModulate_dx9::_dynamic_initializer_for__FOGFADESTART__
// Source: json
//------------------------------------------------------------------------------
DecalModulate_dx9::CShaderParam *DecalModulate_dx9::_dynamic_initializer_for__FOGFADESTART__()
{
  return DecalModulate_dx9::CShaderParam::CShaderParam(
           this: &FOGFADESTART,
           pName: "$FOGFADESTART",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "fog amount at which to start fading decal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F9E0
// Name: DecalModulate_dx9::_dynamic_initializer_for__FOGFADEEND__
// Source: json
//------------------------------------------------------------------------------
DecalModulate_dx9::CShaderParam *DecalModulate_dx9::_dynamic_initializer_for__FOGFADEEND__()
{
  return DecalModulate_dx9::CShaderParam::CShaderParam(
           this: &FOGFADEEND,
           pName: "$FOGFADEEND",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "fog amount at which to end fading decal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FA00
// Name: DecalModulate_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DecalModulate_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_22);
  s_ShaderInstance_22.__vftable = (DecalModulate_dx9::CShader_vtbl *)&DecalModulate_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AFD0
// Name: DecalModulate::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalModulate::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_21);
}

//------------------------------------------------------------------------------
// Address: 0x1006AFE0
// Name: DecalModulate_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalModulate_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_22);
}

//------------------------------------------------------------------------------
// Address: 0x1005FA20
// Name: _dynamic_initializer_for__s_ConstructMe_depth_of_field_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_depth_of_field_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &depth_of_field_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005FA40
// Name: _dynamic_initializer_for__s_ConstructMe_depth_of_field_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_depth_of_field_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &depth_of_field_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005FA60
// Name: _dynamic_initializer_for__mat_dof_max_blur_radius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_max_blur_radius__()
{
  ConVar::ConVar(this: &mat_dof_max_blur_radius, pName: "mat_dof_max_blur_radius", pDefaultValue: "10", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_max_blur_radius__);
}

//------------------------------------------------------------------------------
// Address: 0x1005FA90
// Name: _dynamic_initializer_for__mat_dof_quality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_quality__()
{
  ConVar::ConVar(this: &mat_dof_quality, pName: "mat_dof_quality", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_quality__);
}

//------------------------------------------------------------------------------
// Address: 0x1006AFF0
// Name: _dynamic_atexit_destructor_for__mat_dof_max_blur_radius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_max_blur_radius__()
{
  ConVar::~ConVar(this: &mat_dof_max_blur_radius);
}

//------------------------------------------------------------------------------
// Address: 0x1006B000
// Name: _dynamic_atexit_destructor_for__mat_dof_quality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_quality__()
{
  ConVar::~ConVar(this: &mat_dof_quality);
}
