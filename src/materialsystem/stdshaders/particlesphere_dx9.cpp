// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/particlesphere_dx9.cpp
// Functions: 40
// ============================================================

#include "materialsystem\stdshaders\particlesphere_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10022330
// Name: public: virtual char const __near * ParticleSphere::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ParticleSphere::CShader::GetFallbackShader(ParticleSphere::CShader *this, IMaterialVar **params)
{
  return "ParticleSphere_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x10022340
// Name: public: virtual char const __near * ParticleSphere::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ParticleSphere::CShader::GetName(ParticleSphere::CShader *this)
{
  return s_Name_75;
}

//------------------------------------------------------------------------------
// Address: 0x10022350
// Name: public: virtual int ParticleSphere::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ParticleSphere::CShader::GetFlags(ParticleSphere::CShader *this)
{
  return s_nFlags_93;
}

//------------------------------------------------------------------------------
// Address: 0x10022360
// Name: public: virtual int ParticleSphere::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ParticleSphere::CShader::GetParamCount(ParticleSphere::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_76.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10022370
// Name: public: virtual void ParticleSphere_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParticleSphere_DX9::CShader::OnInitShaderParams(
        ParticleSphere_DX9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  IMaterialVar *v3; // ebx
  IMaterialVar_vtbl *v4; // esi
  int DefaultDepthFeatheringValue; // eax

  if ( !params[DEPTHBLEND.m_Index]->IsDefined(this: params[DEPTHBLEND.m_Index]) )
  {
    v3 = params[DEPTHBLEND.m_Index];
    v4 = v3->__vftable;
    DefaultDepthFeatheringValue = GetDefaultDepthFeatheringValue();
    v4->SetIntValue(this: v3, a2: DefaultDepthFeatheringValue);
  }
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    params[DEPTHBLEND.m_Index]->SetIntValue(this: params[DEPTHBLEND.m_Index], a2: 0);
  if ( !params[DEPTHBLENDSCALE.m_Index]->IsDefined(this: params[DEPTHBLENDSCALE.m_Index]) )
    ((void (__stdcall *)(int))params[DEPTHBLENDSCALE.m_Index]->SetFloatValue)(a1: 1112014848);
}

//------------------------------------------------------------------------------
// Address: 0x10022400
// Name: public: virtual char const __near * ParticleSphere_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ParticleSphere_DX9::CShader::GetName(ParticleSphere_DX9::CShader *this)
{
  return s_Name_76;
}

//------------------------------------------------------------------------------
// Address: 0x10022410
// Name: public: virtual int ParticleSphere_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ParticleSphere_DX9::CShader::GetFlags(ParticleSphere_DX9::CShader *this)
{
  return s_nFlags_28;
}

//------------------------------------------------------------------------------
// Address: 0x10022420
// Name: public: virtual void ParticleSphere_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParticleSphere_DX9::CShader::OnInitShaderInstance(
        ParticleSphere_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  params[USINGPIXELSHADER.m_Index]->SetIntValue(this: params[USINGPIXELSHADER.m_Index], a2: 1);
  if ( params[SCENEDEPTH.m_Index]->IsDefined(this: params[SCENEDEPTH.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: SCENEDEPTH.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadBumpMap(this, nTextureVar: BUMPMAP_3.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10022480
// Name: public: virtual int ParticleSphere_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ParticleSphere_DX9::CShader::GetParamCount(ParticleSphere_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_75.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10022490
// Name: public: virtual void ParticleSphere_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParticleSphere_DX9::CShader::OnDrawElements(
        ParticleSphere_DX9::CShader *this,
        IMaterialVar **params,
        int pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IMaterialVar **v6; // edi
  bool v7; // bl
  int v8; // esi
  void (__thiscall *v9)(int, int, int, int *, _DWORD); // edx
  IShaderDynamicAPI *v10; // esi
  float *v11; // eax
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v19)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v20; // edi
  int v21; // eax
  int v22; // eax
  const char *v23; // [esp+94h] [ebp-58h]
  float vEyePos_SpecExponent[4]; // [esp+A4h] [ebp-48h] BYREF
  float vViewportMad[4]; // [esp+B4h] [ebp-38h] BYREF
  float vScaleVec[3]; // [esp+C4h] [ebp-28h] BYREF
  Vector vLightColor; // [esp+D0h] [ebp-1Ch] BYREF
  int nViewportY; // [esp+DCh] [ebp-10h] BYREF
  int nViewportX; // [esp+E0h] [ebp-Ch] BYREF
  int nViewportHeight; // [esp+E4h] [ebp-8h] BYREF
  CBaseShader *v31; // [esp+E8h] [ebp-4h]

  v6 = params;
  v31 = this;
  v7 = params[DEPTHBLEND.m_Index]->m_intVal != 0
    && mat_depthfeather_enable.m_pParent != nullptr
    && mat_depthfeather_enable.m_pParent->m_Value.m_nValue != 0;
  v8 = pShaderShadow;
  if ( pShaderShadow != 0 )
  {
    (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)pShaderShadow + 84))(a1: pShaderShadow, a2: 0, a3: 1);
    if ( v7 )
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v8 + 84))(a1: v8, a2: 1, a3: 1);
    v9 = *(void (__thiscall **)(int, int, int, int *, _DWORD))(*(_DWORD *)v8 + 64);
    pShaderShadow = 2;
    v9(a1: v8, a2: 5, a3: 1, a4: &pShaderShadow, a5: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 28))(a1: v8, a2: 1);
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v8 + 36))(a1: v8, a2: 4, a3: 5);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 8))(a1: v8, a2: 0);
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 68))(a1: v8, a2: "particlesphere_vs20", a3: 0);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 72))(a1: v8, a2: "particlesphere_ps20", a3: 0);
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DEPTHBLEND", v7, "bDepthBlend");
      (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)v8 + 72))(
        a1: v8,
        a2: "particlesphere_ps20b",
        a3: 2 * v7);
      v6 = params;
    }
    CBaseShader::FogToFogColor(this: v31);
  }
  v10 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v31,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: BUMPMAP_3.m_Index,
      nFrameVar: -1);
    if ( v7 )
      v10->BindStandardTexture(
        this: v10,
        a2: SHADER_SAMPLER1,
        a3: TEXTURE_BINDFLAGS_NONE,
        a4: TEXTURE_FRAME_BUFFER_FULL_DEPTH);
    v10->SetVertexShaderConstant(this: v10, a2: 48, a3: &v6[LIGHT_POSITION.m_Index]->m_VecVal.x, a4: 1, a5: false);
    v11 = (float *)v6[LIGHT_COLOR.m_Index];
    v12 = v11[4];
    v13 = v11[5];
    v14 = v11[3];
    if ( v12 <= v13 )
      v15 = v11[5];
    else
      v15 = v11[4];
    if ( v14 <= v15 )
    {
      if ( v12 <= v13 )
        v16 = v11[5];
      else
        v16 = v11[4];
    }
    else
    {
      v16 = v11[3];
    }
    if ( v16 < 0.0099999998 )
      v16 = 0.0099999998;
    SetVertexShaderConstant = v10->SetVertexShaderConstant;
    vScaleVec[0] = v16;
    vScaleVec[1] = v16;
    vScaleVec[2] = v16;
    vLightColor.x = (float)(1.0 / v16) * v14;
    vLightColor.y = (float)(1.0 / v16) * v12;
    vLightColor.z = (float)(1.0 / v16) * v13;
    SetVertexShaderConstant(this: v10, a2: 49, a3: &vLightColor.x, a4: 1, a5: false);
    v10->SetVertexShaderConstant(this: v10, a2: 50, a3: vScaleVec, a4: 1, a5: false);
    v10->SetPixelShaderFogParams(this: v10, a2: 12);
    v10->GetWorldSpaceCameraPosition(this: v10, a2: vEyePos_SpecExponent);
    SetPixelShaderConstant = v10->SetPixelShaderConstant;
    vEyePos_SpecExponent[3] = 0.0;
    SetPixelShaderConstant(this: v10, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
    ((void (__thiscall *)(IShaderDynamicAPI *, _DWORD, _DWORD))v10->SetDepthFeatheringPixelShaderConstant)(
      a1: v10,
      a2: 0,
      a3: LODWORD(v6[DEPTHBLENDSCALE.m_Index]->m_VecVal.x));
    v10->GetCurrentViewport(this: v10, a2: &nViewportX, a3: &nViewportY, a4: &pShaderShadow, a5: &nViewportHeight);
    v10->GetCurrentRenderTargetDimensions(this: v10, a2: (int *)&params, a3: (int *)&pShaderAPI);
    v19 = v10->SetPixelShaderConstant;
    vViewportMad[0] = (float)((float)pShaderShadow / (float)(int)params) * 0.5;
    vViewportMad[1] = (float)((float)nViewportHeight / (float)(int)pShaderAPI) * -0.5;
    vViewportMad[2] = (float)((float)nViewportX / (float)(int)params) + vViewportMad[0];
    vViewportMad[3] = (float)((float)nViewportY / (float)(int)pShaderAPI) - vViewportMad[1];
    v19(this: v10, a2: 15, a3: vViewportMad, a4: 1, a5: false);
    v20 = CBaseShader::s_pShaderAPI->GetSceneFogMode(this: CBaseShader::s_pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    if ( g_shaderConfigDumpEnable )
    {
      v21 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))CBaseShader::s_pShaderAPI->GetSceneFogMode)(
              a1: CBaseShader::s_pShaderAPI,
              a2: "s_pShaderAPI->GetSceneFogMode() == MATERIAL_FOG_LINEAR_BELOW_FOG_Z");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "FOGTYPE", v21 == 2, v23);
    }
    v10->SetVertexShaderIndex(this: v10, a2: v20);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v22 = v10->GetSceneFogMode(this: v10);
    v10->SetPixelShaderIndex(this: v10, a2: v22 == 2);
  }
  CBaseShader::Draw(this: v31, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10022840
// Name: public: virtual struct ShaderParamInfo_t const __near & ParticleSphere::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ParticleSphere::CShaderParam *__thiscall ParticleSphere::CShader::GetParamInfo(
        ParticleSphere::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_76.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ParticleSphere::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10022870
// Name: public: virtual struct ShaderParamInfo_t const __near & ParticleSphere_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ParticleSphere_DX9::CShaderParam *__thiscall ParticleSphere_DX9::CShader::GetParamInfo(
        ParticleSphere_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_75.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ParticleSphere_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100228A0
// Name: public: ParticleSphere_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ParticleSphere_DX9::CShaderParam *__thiscall ParticleSphere_DX9::CShaderParam::CShaderParam(
        ParticleSphere_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  ParticleSphere_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  ParticleSphere_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_75.m_Size + 13;
  m_Size = s_ShaderParams_75.m_Size;
  v8 = s_ShaderParams_75.m_Size;
  if ( s_ShaderParams_75.m_Size + 1 > s_ShaderParams_75.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_75,
      num: s_ShaderParams_75.m_Size - s_ShaderParams_75.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_75.m_Size;
  }
  m_pMemory = s_ShaderParams_75.m_Memory.m_pMemory;
  s_ShaderParams_75.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_75.m_pElements = s_ShaderParams_75.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_75.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_75.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_75.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10064230
// Name: ParticleSphere::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ParticleSphere::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ParticleSphere::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064240
// Name: ParticleSphere::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ParticleSphere::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_76);
  s_ShaderInstance_76.__vftable = (ParticleSphere::CShader_vtbl *)&ParticleSphere::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064260
// Name: ParticleSphere_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ParticleSphere_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ParticleSphere_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064270
// Name: ParticleSphere_DX9::_dynamic_initializer_for__DEPTHBLEND__
// Source: json
//------------------------------------------------------------------------------
ParticleSphere_DX9::CShaderParam *ParticleSphere_DX9::_dynamic_initializer_for__DEPTHBLEND__()
{
  return ParticleSphere_DX9::CShaderParam::CShaderParam(
           this: &DEPTHBLEND,
           pName: "$DEPTHBLEND",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "fade at intersection boundaries",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064290
// Name: ParticleSphere_DX9::_dynamic_initializer_for__SCENEDEPTH__
// Source: json
//------------------------------------------------------------------------------
ParticleSphere_DX9::CShaderParam *ParticleSphere_DX9::_dynamic_initializer_for__SCENEDEPTH__()
{
  return ParticleSphere_DX9::CShaderParam::CShaderParam(
           this: &SCENEDEPTH,
           pName: "$SCENEDEPTH",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100642B0
// Name: ParticleSphere_DX9::_dynamic_initializer_for__DEPTHBLENDSCALE__
// Source: json
//------------------------------------------------------------------------------
ParticleSphere_DX9::CShaderParam *ParticleSphere_DX9::_dynamic_initializer_for__DEPTHBLENDSCALE__()
{
  return ParticleSphere_DX9::CShaderParam::CShaderParam(
           this: &DEPTHBLENDSCALE,
           pName: "$DEPTHBLENDSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "50.0",
           pHelp: "Amplify or reduce DEPTHBLEND fading. Lower values make harder edges.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100642D0
// Name: ParticleSphere_DX9::_dynamic_initializer_for__USINGPIXELSHADER__
// Source: json
//------------------------------------------------------------------------------
ParticleSphere_DX9::CShaderParam *ParticleSphere_DX9::_dynamic_initializer_for__USINGPIXELSHADER__()
{
  return ParticleSphere_DX9::CShaderParam::CShaderParam(
           this: &USINGPIXELSHADER,
           pName: "$USINGPIXELSHADER",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Tells to client code whether the shader is using DX8 vertex/pixel shaders or not",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100642F0
// Name: ParticleSphere_DX9::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
ParticleSphere_DX9::CShaderParam *ParticleSphere_DX9::_dynamic_initializer_for__BUMPMAP__()
{
  return ParticleSphere_DX9::CShaderParam::CShaderParam(
           this: &BUMPMAP_3,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064310
// Name: ParticleSphere_DX9::_dynamic_initializer_for__LIGHTS__
// Source: json
//------------------------------------------------------------------------------
ParticleSphere_DX9::CShaderParam *ParticleSphere_DX9::_dynamic_initializer_for__LIGHTS__()
{
  return ParticleSphere_DX9::CShaderParam::CShaderParam(
           this: &LIGHTS,
           pName: "$LIGHTS",
           type: SHADER_PARAM_TYPE_FOURCC,
           pDefaultParam: pDefaultParam,
           pHelp: "array of lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064330
// Name: ParticleSphere_DX9::_dynamic_initializer_for__LIGHT_POSITION__
// Source: json
//------------------------------------------------------------------------------
ParticleSphere_DX9::CShaderParam *ParticleSphere_DX9::_dynamic_initializer_for__LIGHT_POSITION__()
{
  return ParticleSphere_DX9::CShaderParam::CShaderParam(
           this: &LIGHT_POSITION,
           pName: "$LIGHT_POSITION",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "0 0 0",
           pHelp: "This is the directional light position.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064350
// Name: ParticleSphere_DX9::_dynamic_initializer_for__LIGHT_COLOR__
// Source: json
//------------------------------------------------------------------------------
ParticleSphere_DX9::CShaderParam *ParticleSphere_DX9::_dynamic_initializer_for__LIGHT_COLOR__()
{
  return ParticleSphere_DX9::CShaderParam::CShaderParam(
           this: &LIGHT_COLOR,
           pName: "$LIGHT_COLOR",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "1 1 1",
           pHelp: "This is the directional light color.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064370
// Name: ParticleSphere_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ParticleSphere_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_75);
  s_ShaderInstance_75.__vftable = (ParticleSphere_DX9::CShader_vtbl *)&ParticleSphere_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B4F0
// Name: ParticleSphere::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParticleSphere::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_76);
}

//------------------------------------------------------------------------------
// Address: 0x1006B500
// Name: ParticleSphere_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParticleSphere_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_75);
}

//------------------------------------------------------------------------------
// Address: 0x10064390
// Name: _dynamic_initializer_for__s_ConstructMe_phong_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_phong_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &phong_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100643B0
// Name: _dynamic_initializer_for__s_ConstructMe_phong_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_phong_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &phong_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100643D0
// Name: _dynamic_initializer_for__s_ConstructMe_phong_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_phong_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &phong_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100643F0
// Name: _dynamic_initializer_for__s_ConstructMe_phong_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_phong_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &phong_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064410
// Name: _dynamic_initializer_for__mat_displacementmap___2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_displacementmap___2()
{
  ConVar::ConVar(this: &mat_displacementmap_2, pName: "mat_displacementmap", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_displacementmap___2);
}

//------------------------------------------------------------------------------
// Address: 0x10064440
// Name: _dynamic_initializer_for__r_lightwarpidentity___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_lightwarpidentity___1()
{
  ConVar::ConVar(this: &r_lightwarpidentity_1, pName: "r_lightwarpidentity", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_lightwarpidentity___1);
}

//------------------------------------------------------------------------------
// Address: 0x10064470
// Name: _dynamic_initializer_for__r_rimlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_rimlight__()
{
  ConVar::ConVar(this: &r_rimlight, pName: "r_rimlight", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_rimlight__);
}

//------------------------------------------------------------------------------
// Address: 0x100644A0
// Name: _dynamic_initializer_for__s_ConstructMe_portal_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_portal_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &portal_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100644C0
// Name: _dynamic_initializer_for__s_ConstructMe_portal_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_portal_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &portal_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100644E0
// Name: _dynamic_initializer_for__s_ConstructMe_portal_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_portal_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &portal_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006B510
// Name: _dynamic_atexit_destructor_for__mat_displacementmap___2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_displacementmap___2()
{
  ConVar::~ConVar(this: &mat_displacementmap_2);
}

//------------------------------------------------------------------------------
// Address: 0x1006B520
// Name: _dynamic_atexit_destructor_for__r_lightwarpidentity___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_lightwarpidentity___1()
{
  ConVar::~ConVar(this: &r_lightwarpidentity_1);
}

//------------------------------------------------------------------------------
// Address: 0x1006B530
// Name: _dynamic_atexit_destructor_for__r_rimlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_rimlight__()
{
  ConVar::~ConVar(this: &r_rimlight);
}
