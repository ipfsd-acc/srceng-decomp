// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/sfm_ambientocclusion.cpp
// Functions: 22
// ============================================================

#include "materialsystem\stdshaders\sfm_ambientocclusion.h"

//------------------------------------------------------------------------------
// Address: 0x1002BD80
// Name: public: virtual char const __near * sfm_ambientocclusion_shader::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall sfm_ambientocclusion_shader::CShader::GetName(sfm_ambientocclusion_shader::CShader *this)
{
  return s_Name_94;
}

//------------------------------------------------------------------------------
// Address: 0x1002BD90
// Name: public: virtual int sfm_ambientocclusion_shader::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_ambientocclusion_shader::CShader::GetFlags(sfm_ambientocclusion_shader::CShader *this)
{
  return s_nFlags_31;
}

//------------------------------------------------------------------------------
// Address: 0x1002BDA0
// Name: public: virtual void sfm_ambientocclusion_shader::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sfm_ambientocclusion_shader::CShader::OnInitShaderInstance(
        sfm_ambientocclusion_shader::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: FRONTNDTEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002BDB0
// Name: public: virtual void sfm_ambientocclusion_shader::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge sfm_ambientocclusion_shader::CShader::OnDrawElements(
        sfm_ambientocclusion_shader::CShader *this@<ecx>,
        int a2@<edi>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  void (__thiscall *VertexShaderVertexFormat)(IShaderShadow *, unsigned int, int, int *, int); // edx
  float v9; // xmm0_4
  int v10; // edi
  float *v11; // eax
  int v12; // ecx
  int v13; // edi
  double v14; // xmm0_8
  double v15; // xmm0_8
  double v16; // xmm0_8
  double v17; // xmm0_8
  double v18; // xmm0_8
  float *v19; // eax
  float *v20; // ecx
  float *p_z; // edi
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float x; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const VMatrix *v29; // eax
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  IShaderDynamicAPI_vtbl *v33; // edx
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  void (__thiscall *v43)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v44)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v45)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v46)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v47; // eax
  long double v48; // [esp+E0h] [ebp-ECh]
  long double v49; // [esp+E0h] [ebp-ECh]
  long double v50; // [esp+E0h] [ebp-ECh]
  long double v51; // [esp+E0h] [ebp-ECh]
  long double v52; // [esp+E0h] [ebp-ECh]
  Vector4D vMatrixRows[4]; // [esp+E8h] [ebp-E4h] BYREF
  float vSampleRadiusNBias[4]; // [esp+128h] [ebp-A4h] BYREF
  float vRandSampleScale[4]; // [esp+138h] [ebp-94h] BYREF
  float vScreenSize[4]; // [esp+148h] [ebp-84h] BYREF
  Vector4D vEyeDirection; // [esp+158h] [ebp-74h] BYREF
  Vector4D vEyePosZNear; // [esp+168h] [ebp-64h] BYREF
  float vNoiseOffset[4]; // [esp+178h] [ebp-54h] BYREF
  float *v60; // [esp+188h] [ebp-44h]
  float *v61; // [esp+18Ch] [ebp-40h]
  int nTexHeight; // [esp+190h] [ebp-3Ch] BYREF
  int v63; // [esp+194h] [ebp-38h]
  int nTexWidth; // [esp+198h] [ebp-34h] BYREF
  float v65; // [esp+19Ch] [ebp-30h]
  Vector vec; // [esp+1A0h] [ebp-2Ch] BYREF
  int nScreenHeight; // [esp+1ACh] [ebp-20h] BYREF
  float phi; // [esp+1B0h] [ebp-1Ch]
  float theta; // [esp+1B4h] [ebp-18h]
  int nScreenWidth; // [esp+1B8h] [ebp-14h] BYREF
  float v71; // [esp+1BCh] [ebp-10h]
  int nSqrtNumSamples; // [esp+1C0h] [ebp-Ch]
  float *v73; // [esp+1C4h] [ebp-8h]
  CBaseShader *v74; // [esp+1C8h] [ebp-4h]
  int a; // [esp+1D8h] [ebp+Ch]
  float *aa; // [esp+1D8h] [ebp+Ch]
  float oneoverN; // [esp+1DCh] [ebp+10h]

  v74 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: false);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
    LODWORD(vec.x) = 2;
    LODWORD(vec.y) = 3;
    LODWORD(vec.z) = 3;
    VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 3, a4: (int *)&vec, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "sfm_ambientocclusion_vs30", a3: 0);
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "sfm_ambientocclusion_ps30", a3: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    LODWORD(v48) = a2;
    if ( !s_bInited )
    {
      v9 = sqrt(9.0);
      v10 = (int)v9;
      nSqrtNumSamples = (int)v9;
      v11 = (float *)operator new(nSize: 12 * v10 * v10);
      v61 = v11;
      oneoverN = 1.0 / (float)(int)v9;
      a = 0;
      if ( (int)v9 > 0 )
      {
        v12 = 12 * v10;
        v63 = 12 * v10;
        while ( 1 )
        {
          v13 = 0;
          v73 = v11;
          v65 = (float)a;
          v60 = (float *)((char *)v11 + v12);
          do
          {
            v14 = fsqrt(
                    1.0
                  - (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(rand() - 0x3FFF) * 0.000061038882) & _mask__AbsFloat_)
                                  + v65)
                          * oneoverN));
            __libm_sse2_acos(x: v48);
            *(float *)&v14 = v14;
            theta = *(float *)&v14 * 2.0;
            *(float *)&v14 = (float)((float)(COERCE_FLOAT(
                                               COERCE_UNSIGNED_INT((float)(rand() - 0x3FFF) * 0.000061038882)
                                             & _mask__AbsFloat_)
                                           + (float)v13)
                                   * oneoverN)
                           * 6.283185307179586;
            phi = *(float *)&v14;
            v15 = theta;
            __libm_sse2_sin(x: v49);
            *(float *)&v15 = v15;
            v71 = *(float *)&v15;
            v16 = phi;
            __libm_sse2_cos(x: v50);
            *(float *)&v16 = v16;
            vec.x = *(float *)&v16 * v71;
            v17 = phi;
            __libm_sse2_sin(x: v51);
            *(float *)&v17 = v17;
            vec.y = *(float *)&v17 * v71;
            v18 = theta;
            __libm_sse2_cos(x: v52);
            v19 = v73;
            v20 = v73 + 3;
            ++v13;
            *v73 = vec.x;
            *(float *)&v18 = v18;
            v73 = v20;
            v19[1] = vec.y;
            v19[2] = *(float *)&v18;
          }
          while ( v13 < nSqrtNumSamples );
          if ( ++a >= nSqrtNumSamples )
            break;
          v12 = v63;
          v11 = v60;
        }
        v11 = v61;
      }
      p_z = &s_vSphereSamples[0].z;
      aa = v11 + 2;
      do
      {
        v22 = (float)rand() * 0.000030518509;
        v23 = *(aa - 1) * v22;
        v24 = *aa * v22;
        *(p_z - 2) = *(aa - 2) * v22;
        *(p_z - 1) = v23;
        *p_z = v24;
        p_z[1] = 1.0;
        p_z += 4;
        aa += 3;
      }
      while ( (int)p_z < (int)&AOMODE.m_Info.m_pHelp );
      s_bInited = true;
    }
    x = params[FARZ.m_Index]->m_VecVal.x;
    v26 = params[BIAS.m_Index]->m_VecVal.x;
    v27 = params[STRENGTH.m_Index]->m_VecVal.x;
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    vSampleRadiusNBias[0] = params[RADIUS.m_Index]->m_VecVal.x;
    vSampleRadiusNBias[1] = x / (float)(vSampleRadiusNBias[0] * v27);
    vSampleRadiusNBias[2] = x;
    vSampleRadiusNBias[3] = v26 * x;
    ((void (__thiscall *)(IShaderDynamicAPI *, int, float *, int, _DWORD, _DWORD))SetPixelShaderConstant)(
      a1: pShaderAPI,
      a2: 10,
      a3: vSampleRadiusNBias,
      a4: 1,
      a5: 0,
      a6: LODWORD(v48));
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 11, a3: (const float *)s_vSphereSamples, a4: 9, a5: false);
    v29 = params[VIEWPROJ.m_Index]->GetMatrixValue(this: params[VIEWPROJ.m_Index]);
    v30 = v29->m[1][0];
    v31 = v29->m[2][0];
    v32 = v29->m[3][0];
    v33 = pShaderAPI->__vftable;
    vMatrixRows[0].x = v29->m[0][0];
    vMatrixRows[0].y = v30;
    vMatrixRows[0].z = v31;
    vMatrixRows[0].w = v32;
    v34 = v29->m[1][1];
    v35 = v29->m[2][1];
    v36 = v29->m[3][1];
    vMatrixRows[1].x = v29->m[0][1];
    vMatrixRows[1].y = v34;
    vMatrixRows[1].z = v35;
    vMatrixRows[1].w = v36;
    v37 = v29->m[1][2];
    v38 = v29->m[2][2];
    v39 = v29->m[3][2];
    vMatrixRows[2].x = v29->m[0][2];
    vMatrixRows[2].y = v37;
    vMatrixRows[2].z = v38;
    vMatrixRows[2].w = v39;
    v40 = v29->m[1][3];
    v41 = v29->m[2][3];
    v42 = v29->m[3][3];
    vMatrixRows[3].x = v29->m[0][3];
    vMatrixRows[3].y = v40;
    vMatrixRows[3].z = v41;
    vMatrixRows[3].w = v42;
    v33->SetPixelShaderConstant(this: pShaderAPI, a2: 5, a3: &vMatrixRows[0].x, a4: 4, a5: false);
    pShaderAPI->GetCurrentRenderTargetDimensions(this: pShaderAPI, a2: &nScreenWidth, a3: &nScreenHeight);
    v43 = pShaderAPI->SetPixelShaderConstant;
    vScreenSize[1] = 1.0 / (float)nScreenHeight;
    vScreenSize[0] = 1.0 / (float)nScreenWidth;
    vScreenSize[2] = 0.0;
    vScreenSize[3] = 0.0;
    v43(this: pShaderAPI, a2: 2, a3: vScreenSize, a4: 1, a5: false);
    v44 = pShaderAPI->SetPixelShaderConstant;
    vEyePosZNear = params[EYEPOSZNEAR.m_Index]->m_VecVal;
    v44(this: pShaderAPI, a2: 3, a3: &vEyePosZNear.x, a4: 1, a5: false);
    v45 = pShaderAPI->SetPixelShaderConstant;
    vEyeDirection = params[EYEDIR.m_Index]->m_VecVal;
    v45(this: pShaderAPI, a2: 4, a3: &vEyeDirection.x, a4: 1, a5: false);
    CBaseShader::BindTexture(
      this: v74,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: FRONTNDTEXTURE.m_Index,
      nFrameVar: -1);
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER1,
      a3: TEXTURE_BINDFLAGS_NONE,
      a4: TEXTURE_SSAO_NOISE_2D);
    pShaderAPI->GetStandardTextureDimensions(
      this: pShaderAPI,
      a2: &nTexWidth,
      a3: &nTexHeight,
      a4: TEXTURE_SSAO_NOISE_2D);
    v46 = pShaderAPI->SetPixelShaderConstant;
    vRandSampleScale[0] = 1.0 / (float)nTexWidth;
    vRandSampleScale[1] = 1.0 / (float)nTexHeight;
    vRandSampleScale[2] = (float)(0.5 / (float)nScreenWidth) + 0.5;
    vRandSampleScale[3] = (float)(0.5 / (float)nScreenHeight) + 0.5;
    v46(this: pShaderAPI, a2: 9, a3: vRandSampleScale, a4: 1, a5: false);
    v47 = params[JITTERSEED.m_Index];
    memset(vNoiseOffset, 0, sizeof(vNoiseOffset));
    CBaseVSShader::HashShadow2DJitter(
      this: (CBaseVSShader *)v74,
      fJitterSeed: v47->m_VecVal.x,
      fU: vNoiseOffset,
      fV: &vNoiseOffset[1]);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 1, a3: vNoiseOffset, a4: 1, a5: false);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "AO_MODE",
        params[AOMODE.m_Index]->m_intVal,
        "params[AOMODE]->GetIntValue()");
    ((void (__thiscall *)(IShaderDynamicAPI *))pShaderAPI->SetPixelShaderIndex)(a1: pShaderAPI);
  }
  CBaseShader::Draw(this: v74, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002C480
// Name: public: virtual int sfm_ambientocclusion_shader::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_ambientocclusion_shader::CShader::GetParamCount(sfm_ambientocclusion_shader::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_94.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002C490
// Name: public: virtual struct ShaderParamInfo_t const __near & sfm_ambientocclusion_shader::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *__thiscall sfm_ambientocclusion_shader::CShader::GetParamInfo(
        sfm_ambientocclusion_shader::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_94.m_Memory.m_pMemory[param - ParamCount];
  else
    return (sfm_ambientocclusion_shader::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002C4C0
// Name: public: sfm_ambientocclusion_shader::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *__thiscall sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
        sfm_ambientocclusion_shader::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  sfm_ambientocclusion_shader::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  sfm_ambientocclusion_shader::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_94.m_Size + 13;
  m_Size = s_ShaderParams_94.m_Size;
  v8 = s_ShaderParams_94.m_Size;
  if ( s_ShaderParams_94.m_Size + 1 > s_ShaderParams_94.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_94,
      num: s_ShaderParams_94.m_Size - s_ShaderParams_94.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_94.m_Size;
  }
  m_pMemory = s_ShaderParams_94.m_Memory.m_pMemory;
  s_ShaderParams_94.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_94.m_pElements = s_ShaderParams_94.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_94.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_94.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_94.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10065A40
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int sfm_ambientocclusion_shader::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: sfm_ambientocclusion_shader::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10065A50
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__FRONTNDTEXTURE__
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *sfm_ambientocclusion_shader::_dynamic_initializer_for__FRONTNDTEXTURE__()
{
  return sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
           this: &FRONTNDTEXTURE,
           pName: "$FRONTNDTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065A70
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__JITTERSEED__
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *sfm_ambientocclusion_shader::_dynamic_initializer_for__JITTERSEED__()
{
  return sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
           this: &JITTERSEED,
           pName: "$JITTERSEED",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065A90
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__EYEPOSZNEAR__
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *sfm_ambientocclusion_shader::_dynamic_initializer_for__EYEPOSZNEAR__()
{
  return sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
           this: &EYEPOSZNEAR,
           pName: "$EYEPOSZNEAR",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065AB0
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__EYEDIR__
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *sfm_ambientocclusion_shader::_dynamic_initializer_for__EYEDIR__()
{
  return sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
           this: &EYEDIR,
           pName: "$EYEDIR",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065AD0
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__FARZ__
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *sfm_ambientocclusion_shader::_dynamic_initializer_for__FARZ__()
{
  return sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
           this: &FARZ,
           pName: "$FARZ",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065AF0
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__BIAS__
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *sfm_ambientocclusion_shader::_dynamic_initializer_for__BIAS__()
{
  return sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
           this: &BIAS,
           pName: "$BIAS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065B10
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__STRENGTH__
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *sfm_ambientocclusion_shader::_dynamic_initializer_for__STRENGTH__()
{
  return sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
           this: &STRENGTH,
           pName: "$STRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065B30
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__RADIUS__
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *sfm_ambientocclusion_shader::_dynamic_initializer_for__RADIUS__()
{
  return sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
           this: &RADIUS,
           pName: "$RADIUS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065B50
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__VIEWPROJ__
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *sfm_ambientocclusion_shader::_dynamic_initializer_for__VIEWPROJ__()
{
  return sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
           this: &VIEWPROJ,
           pName: "$VIEWPROJ",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065B70
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__AOMODE__
// Source: json
//------------------------------------------------------------------------------
sfm_ambientocclusion_shader::CShaderParam *sfm_ambientocclusion_shader::_dynamic_initializer_for__AOMODE__()
{
  return sfm_ambientocclusion_shader::CShaderParam::CShaderParam(
           this: &AOMODE,
           pName: "$AOMODE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065B90
// Name: sfm_ambientocclusion_shader::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *sfm_ambientocclusion_shader::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_94);
  s_ShaderInstance_94.__vftable = (sfm_ambientocclusion_shader::CShader_vtbl *)&sfm_ambientocclusion_shader::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B650
// Name: sfm_ambientocclusion_shader::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl sfm_ambientocclusion_shader::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_94);
}

//------------------------------------------------------------------------------
// Address: 0x10065BB0
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_ao_blur_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_ao_blur_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_ao_blur_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10065BD0
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_ao_blur_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_ao_blur_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_ao_blur_ps30_combos);
}
