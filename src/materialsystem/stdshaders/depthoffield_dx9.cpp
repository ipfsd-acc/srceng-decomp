// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/depthoffield_dx9.cpp
// Functions: 37
// ============================================================

#include "materialsystem\stdshaders\depthoffield_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1000B4B0
// Name: public: virtual char const __near * DepthOfField::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DepthOfField::CShader::GetFallbackShader(DepthOfField::CShader *this, IMaterialVar **params)
{
  return "DepthOfField_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x1000B4C0
// Name: public: virtual char const __near * DepthOfField::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DepthOfField::CShader::GetName(DepthOfField::CShader *this)
{
  return s_Name_23;
}

//------------------------------------------------------------------------------
// Address: 0x1000B4D0
// Name: public: virtual int DepthOfField::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DepthOfField::CShader::GetFlags(DepthOfField::CShader *this)
{
  return s_nFlags_61;
}

//------------------------------------------------------------------------------
// Address: 0x1000B4E0
// Name: public: virtual int DepthOfField::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DepthOfField::CShader::GetParamCount(DepthOfField::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_23.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000B4F0
// Name: public: virtual void DepthOfField_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DepthOfField_dx9::CShader::OnInitShaderParams(
        DepthOfField_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( SMALLFB.m_Index != -1 && !params[SMALLFB.m_Index]->IsDefined(this: params[SMALLFB.m_Index]) )
    params[SMALLFB.m_Index]->SetStringValue(this: params[SMALLFB.m_Index], a2: "_rt_SmallFB1");
  if ( NEARPLANE.m_Index != -1 && !params[NEARPLANE.m_Index]->IsDefined(this: params[NEARPLANE.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[NEARPLANE.m_Index]->SetFloatValue)(a1: 0);
  if ( FARPLANE.m_Index != -1 && !params[FARPLANE.m_Index]->IsDefined(this: params[FARPLANE.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[FARPLANE.m_Index]->SetFloatValue)(a1: 0);
  if ( NEARBLURDEPTH.m_Index != -1 && !params[NEARBLURDEPTH.m_Index]->IsDefined(this: params[NEARBLURDEPTH.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[NEARBLURDEPTH.m_Index]->SetFloatValue)(a1: 0);
  if ( NEARFOCUSDEPTH.m_Index != -1 && !params[NEARFOCUSDEPTH.m_Index]->IsDefined(this: params[NEARFOCUSDEPTH.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[NEARFOCUSDEPTH.m_Index]->SetFloatValue)(a1: 0);
  if ( FARFOCUSDEPTH.m_Index != -1 && !params[FARFOCUSDEPTH.m_Index]->IsDefined(this: params[FARFOCUSDEPTH.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[FARFOCUSDEPTH.m_Index]->SetFloatValue)(a1: 0);
  if ( FARBLURDEPTH.m_Index != -1 && !params[FARBLURDEPTH.m_Index]->IsDefined(this: params[FARBLURDEPTH.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[FARBLURDEPTH.m_Index]->SetFloatValue)(a1: 0);
  if ( NEARBLURRADIUS.m_Index != -1 && !params[NEARBLURRADIUS.m_Index]->IsDefined(this: params[NEARBLURRADIUS.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[NEARBLURRADIUS.m_Index]->SetFloatValue)(a1: 0);
  if ( FARBLURRADIUS.m_Index != -1 && !params[FARBLURRADIUS.m_Index]->IsDefined(this: params[FARBLURRADIUS.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[FARBLURRADIUS.m_Index]->SetFloatValue)(a1: 0);
  if ( QUALITY.m_Index != -1 && !params[QUALITY.m_Index]->IsDefined(this: params[QUALITY.m_Index]) )
    params[QUALITY.m_Index]->SetIntValue(this: params[QUALITY.m_Index], a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000B6E0
// Name: public: virtual char const __near * DepthOfField_dx9::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall DepthOfField_dx9::CShader::GetFallbackShader(DepthOfField_dx9::CShader *this, IMaterialVar **params)
{
  return g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 ? nullptr : "Wireframe";
}

//------------------------------------------------------------------------------
// Address: 0x1000B700
// Name: public: virtual char const __near * DepthOfField_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DepthOfField_dx9::CShader::GetName(DepthOfField_dx9::CShader *this)
{
  return s_Name_24;
}

//------------------------------------------------------------------------------
// Address: 0x1000B710
// Name: public: virtual int DepthOfField_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DepthOfField_dx9::CShader::GetFlags(DepthOfField_dx9::CShader *this)
{
  return s_nFlags_8;
}

//------------------------------------------------------------------------------
// Address: 0x1000B720
// Name: public: virtual void DepthOfField_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DepthOfField_dx9::CShader::OnInitShaderInstance(
        DepthOfField_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
  if ( params[SMALLFB.m_Index]->IsDefined(this: params[SMALLFB.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: SMALLFB.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000B770
// Name: public: virtual void DepthOfField_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge DepthOfField_dx9::CShader::OnDrawElements(
        DepthOfField_dx9::CShader *this@<ecx>,
        int a2@<ebx>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  DepthOfField_dx9::CShader *v7; // edi
  IMaterialVar *v8; // edx
  IMaterialVar *v9; // ecx
  float x; // xmm2_4
  IMaterialVar *v11; // eax
  float v12; // xmm5_4
  IMaterialVar *v13; // edx
  float v14; // xmm6_4
  float v15; // xmm3_4
  IMaterialVar *v16; // edx
  float m_fValue; // xmm1_4
  float v18; // xmm4_4
  IMaterialVar *v19; // ecx
  float v20; // xmm0_4
  IMaterialVar *v21; // eax
  IMaterialVar *v22; // edx
  float v23; // xmm1_4
  IShaderDynamicAPI_vtbl *v24; // eax
  float v25; // xmm4_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v27; // xmm2_4
  float v28; // xmm3_4
  const float *v29; // esi
  int v30; // ebx
  float v31; // xmm1_4
  int (__thiscall *v32)(int); // eax
  int v33; // eax
  int v34; // ecx
  float v35; // xmm0_4
  float v36; // xmm1_4
  float *v37; // eax
  char *v38; // ebx
  int v39; // edx
  float *v40; // eax
  int v41; // edx
  int i; // eax
  float v43; // xmm0_4
  int m_intVal; // edi
  float vPoissonConst[64]; // [esp+8h] [ebp-158h] BYREF
  float vConst[16]; // [esp+108h] [ebp-58h] BYREF
  char *v47; // [esp+148h] [ebp-18h]
  char *v48; // [esp+14Ch] [ebp-14h]
  char *v49; // [esp+150h] [ebp-10h]
  char *v50; // [esp+154h] [ebp-Ch]
  DepthOfField_dx9::CShader *v51; // [esp+158h] [ebp-8h]
  float flInvTexWidth; // [esp+15Ch] [ebp-4h]
  int nNumPoissonSamples; // [esp+16Ch] [ebp+Ch]

  v7 = this;
  v51 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: false);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "depth_of_field_vs20", a3: 0);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "depth_of_field_ps20b", a3: 0);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    CBaseShader::BindTexture(
      this: v7,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: v7,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: SMALLFB.m_Index,
      nFrameVar: -1);
    v8 = params[NEARBLURDEPTH.m_Index];
    v9 = params[NEARFOCUSDEPTH.m_Index];
    memset(vConst, 0, sizeof(vConst));
    x = v8->m_VecVal.x;
    v11 = params[FARFOCUSDEPTH.m_Index];
    vConst[0] = x;
    v12 = v9->m_VecVal.x;
    v13 = params[FARBLURDEPTH.m_Index];
    vConst[1] = v12;
    v14 = v11->m_VecVal.x;
    vConst[2] = v14;
    v15 = v13->m_VecVal.x;
    v16 = params[NEARBLURRADIUS.m_Index];
    vConst[3] = v15;
    m_fValue = mat_dof_max_blur_radius.m_pParent->m_Value.m_fValue;
    vConst[4] = m_fValue;
    if ( m_fValue <= v16->m_VecVal.x )
      v18 = m_fValue;
    else
      v18 = v16->m_VecVal.x;
    v19 = params[FARBLURRADIUS.m_Index];
    v20 = 1.0 / m_fValue;
    vConst[5] = (float)(1.0 / m_fValue) * v18;
    if ( m_fValue > v19->m_VecVal.x )
      m_fValue = v19->m_VecVal.x;
    v21 = params[NEARPLANE.m_Index];
    v22 = params[FARPLANE.m_Index];
    vConst[6] = v20 * m_fValue;
    v23 = v21->m_VecVal.x;
    v24 = pShaderAPI->__vftable;
    vConst[8] = v23;
    v25 = v22->m_VecVal.x;
    SetPixelShaderConstant = v24->SetPixelShaderConstant;
    vConst[9] = v25;
    v27 = x - v12;
    vConst[12] = (float)((float)((float)(v25 - v23) * 8192.0) / v25) / v27;
    v28 = v15 - v14;
    vConst[10] = (float)((float)(v25 - v23) * 8192.0) / v25;
    vConst[13] = (float)(v23 - v12) / v27;
    vConst[14] = vConst[10] / v28;
    vConst[15] = (float)(v23 - v14) / v28;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: vConst, a4: 4, a5: false);
    switch ( params[QUALITY.m_Index]->m_intVal )
    {
      case 0:
        goto $LN13;
      case 1:
      case 2:
        nNumPoissonSamples = 16;
        v29 = s_flPoissonConstsQuality1;
        break;
      case 3:
        nNumPoissonSamples = 32;
        v29 = s_flPoissonConstsQuality2;
        break;
      default:
        _Warning(a1: "Invalid mat_dof_quality value. Resetting to 0.\n");
        ConVar::SetValue(this: (ConVar *)&mat_dof_quality.IConVar, value: 0);
$LN13:
        v29 = s_flPoissonConstsQuality0;
        nNumPoissonSamples = 8;
        break;
    }
    v30 = ((int (__thiscall *)(IMaterialVar *, int))params[6]->GetTextureValue)(a1: params[6], a2);
    v31 = (float)(*(int (__thiscall **)(int))(*(_DWORD *)v30 + 12))(a1: v30);
    v32 = *(int (__thiscall **)(int))(*(_DWORD *)v30 + 16);
    flInvTexWidth = 1.0 / v31;
    v33 = v32(a1: v30);
    v34 = 0;
    v35 = 1.0 / (float)v33;
    v36 = flInvTexWidth;
    v48 = (char *)((char *)&vPoissonConst[2] - (char *)v29);
    v50 = (char *)((char *)&vPoissonConst[3] - (char *)v29);
    v47 = (char *)((char *)&vPoissonConst[4] - (char *)v29);
    v37 = (float *)(v29 + 2);
    v49 = (char *)((char *)&vPoissonConst[5] - (char *)v29);
    do
    {
      v38 = v48;
      vPoissonConst[2 * v34] = *(v37 - 2) * v36;
      vPoissonConst[2 * v34 + 1] = *(v37 - 1) * v35;
      *(float *)((char *)v37 + (char *)vPoissonConst - (char *)v29) = *v37 * v36;
      *(float *)((char *)v37 + (char *)&vPoissonConst[1] - (char *)v29) = v37[1] * v35;
      *(float *)((char *)v37 + (_DWORD)v38) = v37[2] * v36;
      *(float *)((char *)v37 + (_DWORD)v50) = v37[3] * v35;
      *(float *)((char *)v37 + (_DWORD)v47) = v37[4] * v36;
      *(float *)((char *)v37 + (_DWORD)v49) = v37[5] * v35;
      v34 += 4;
      v37 += 8;
    }
    while ( v34 < nNumPoissonSamples - 3 );
    v39 = nNumPoissonSamples;
    if ( v34 < nNumPoissonSamples )
    {
      v40 = (float *)&v29[2 * v34];
      v41 = nNumPoissonSamples - v34;
      do
      {
        *(float *)((char *)v40 + (char *)vPoissonConst - (char *)v29) = *v40 * v36;
        *(float *)((char *)v40 + (char *)&vPoissonConst[1] - (char *)v29) = v40[1] * v35;
        v40 += 2;
        --v41;
      }
      while ( v41 != 0 );
      v39 = nNumPoissonSamples;
    }
    for ( i = 1; i < v39; i += 2 )
    {
      v43 = vPoissonConst[2 * i];
      vPoissonConst[2 * i] = vPoissonConst[2 * i + 1];
      vPoissonConst[2 * i + 1] = v43;
    }
    ((void (__thiscall *)(IShaderDynamicAPI *, int, float *, int))pShaderAPI->SetPixelShaderConstant)(
      a1: pShaderAPI,
      a2: 4,
      a3: vPoissonConst,
      a4: v39 / 2);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      m_intVal = params[QUALITY.m_Index]->m_intVal;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "QUALITY", m_intVal, "params[QUALITY]->GetIntValue()");
      pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: m_intVal);
    }
    v7 = v51;
  }
  CBaseShader::Draw(this: v7, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC90
// Name: public: virtual int DepthOfField_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DepthOfField_dx9::CShader::GetParamCount(DepthOfField_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_24.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000BCA0
// Name: public: virtual struct ShaderParamInfo_t const __near & DepthOfField::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DepthOfField::CShaderParam *__thiscall DepthOfField::CShader::GetParamInfo(DepthOfField::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_23.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DepthOfField::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000BCD0
// Name: public: virtual struct ShaderParamInfo_t const __near & DepthOfField_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *__thiscall DepthOfField_dx9::CShader::GetParamInfo(
        DepthOfField_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_24.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DepthOfField_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000BD00
// Name: public: DepthOfField_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *__thiscall DepthOfField_dx9::CShaderParam::CShaderParam(
        DepthOfField_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  DepthOfField_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  DepthOfField_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_24.m_Size + 13;
  m_Size = s_ShaderParams_24.m_Size;
  v8 = s_ShaderParams_24.m_Size;
  if ( s_ShaderParams_24.m_Size + 1 > s_ShaderParams_24.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_24,
      num: s_ShaderParams_24.m_Size - s_ShaderParams_24.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_24.m_Size;
  }
  m_pMemory = s_ShaderParams_24.m_Memory.m_pMemory;
  s_ShaderParams_24.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_24.m_pElements = s_ShaderParams_24.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_24.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_24.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_24.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005FAC0
// Name: DepthOfField::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DepthOfField::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DepthOfField::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005FAD0
// Name: DepthOfField::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DepthOfField::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_23);
  s_ShaderInstance_23.__vftable = (DepthOfField::CShader_vtbl *)&DepthOfField::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005FAF0
// Name: DepthOfField_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DepthOfField_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DepthOfField_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005FB00
// Name: DepthOfField_dx9::_dynamic_initializer_for__SMALLFB__
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *DepthOfField_dx9::_dynamic_initializer_for__SMALLFB__()
{
  return DepthOfField_dx9::CShaderParam::CShaderParam(
           this: &SMALLFB,
           pName: "$SMALLFB",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_SmallFB1",
           pHelp: "Downsampled backbuffer",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FB20
// Name: DepthOfField_dx9::_dynamic_initializer_for__NEARPLANE__
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *DepthOfField_dx9::_dynamic_initializer_for__NEARPLANE__()
{
  return DepthOfField_dx9::CShaderParam::CShaderParam(
           this: &NEARPLANE,
           pName: "$NEARPLANE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Near plane depth",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FB40
// Name: DepthOfField_dx9::_dynamic_initializer_for__FARPLANE__
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *DepthOfField_dx9::_dynamic_initializer_for__FARPLANE__()
{
  return DepthOfField_dx9::CShaderParam::CShaderParam(
           this: &FARPLANE,
           pName: "$FARPLANE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Far plane depth",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FB60
// Name: DepthOfField_dx9::_dynamic_initializer_for__NEARBLURDEPTH__
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *DepthOfField_dx9::_dynamic_initializer_for__NEARBLURDEPTH__()
{
  return DepthOfField_dx9::CShaderParam::CShaderParam(
           this: &NEARBLURDEPTH,
           pName: "$NEARBLURDEPTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Near blur plane depth",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FB80
// Name: DepthOfField_dx9::_dynamic_initializer_for__NEARFOCUSDEPTH__
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *DepthOfField_dx9::_dynamic_initializer_for__NEARFOCUSDEPTH__()
{
  return DepthOfField_dx9::CShaderParam::CShaderParam(
           this: &NEARFOCUSDEPTH,
           pName: "$NEARFOCUSDEPTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Near focus plane depth",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FBA0
// Name: DepthOfField_dx9::_dynamic_initializer_for__FARFOCUSDEPTH__
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *DepthOfField_dx9::_dynamic_initializer_for__FARFOCUSDEPTH__()
{
  return DepthOfField_dx9::CShaderParam::CShaderParam(
           this: &FARFOCUSDEPTH,
           pName: "$FARFOCUSDEPTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Far focus plane depth",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FBC0
// Name: DepthOfField_dx9::_dynamic_initializer_for__FARBLURDEPTH__
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *DepthOfField_dx9::_dynamic_initializer_for__FARBLURDEPTH__()
{
  return DepthOfField_dx9::CShaderParam::CShaderParam(
           this: &FARBLURDEPTH,
           pName: "$FARBLURDEPTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Far blur plane depth",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FBE0
// Name: DepthOfField_dx9::_dynamic_initializer_for__NEARBLURRADIUS__
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *DepthOfField_dx9::_dynamic_initializer_for__NEARBLURRADIUS__()
{
  return DepthOfField_dx9::CShaderParam::CShaderParam(
           this: &NEARBLURRADIUS,
           pName: "$NEARBLURRADIUS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Max near blur radius",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FC00
// Name: DepthOfField_dx9::_dynamic_initializer_for__FARBLURRADIUS__
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *DepthOfField_dx9::_dynamic_initializer_for__FARBLURRADIUS__()
{
  return DepthOfField_dx9::CShaderParam::CShaderParam(
           this: &FARBLURRADIUS,
           pName: "$FARBLURRADIUS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Max far blur radius",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FC20
// Name: DepthOfField_dx9::_dynamic_initializer_for__QUALITY__
// Source: json
//------------------------------------------------------------------------------
DepthOfField_dx9::CShaderParam *DepthOfField_dx9::_dynamic_initializer_for__QUALITY__()
{
  return DepthOfField_dx9::CShaderParam::CShaderParam(
           this: &QUALITY,
           pName: "$QUALITY",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Quality level. Selects different algorithms.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FC40
// Name: DepthOfField_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DepthOfField_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_24);
  s_ShaderInstance_24.__vftable = (DepthOfField_dx9::CShader_vtbl *)&DepthOfField_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B010
// Name: DepthOfField::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DepthOfField::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_23);
}

//------------------------------------------------------------------------------
// Address: 0x1006B020
// Name: DepthOfField_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DepthOfField_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_24);
}

//------------------------------------------------------------------------------
// Address: 0x1005FC60
// Name: _dynamic_initializer_for__s_ConstructMe_depthwrite_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_depthwrite_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &depthwrite_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005FC80
// Name: _dynamic_initializer_for__s_ConstructMe_depthwrite_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_depthwrite_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &depthwrite_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005FCA0
// Name: _dynamic_initializer_for__s_ConstructMe_depthwrite_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_depthwrite_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &depthwrite_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005FCC0
// Name: _dynamic_initializer_for__s_ConstructMe_depthwrite_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_depthwrite_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &depthwrite_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005FCE0
// Name: _dynamic_initializer_for__s_ConstructMe_depthwrite_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_depthwrite_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &depthwrite_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005FD00
// Name: _dynamic_initializer_for__mat_displacementmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_displacementmap__()
{
  ConVar::ConVar(this: &mat_displacementmap, pName: "mat_displacementmap", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_displacementmap__);
}

//------------------------------------------------------------------------------
// Address: 0x1006B030
// Name: _dynamic_atexit_destructor_for__mat_displacementmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_displacementmap__()
{
  ConVar::~ConVar(this: &mat_displacementmap);
}
