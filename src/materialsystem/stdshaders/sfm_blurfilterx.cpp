// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/sfm_blurfilterx.cpp
// Functions: 13
// ============================================================

#include "materialsystem\stdshaders\sfm_blurfilterx.h"

//------------------------------------------------------------------------------
// Address: 0x1002C840
// Name: public: virtual char const __near * sfm_blurfilterx_shader::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall sfm_blurfilterx_shader::CShader::GetName(sfm_blurfilterx_shader::CShader *this)
{
  return s_Name_96;
}

//------------------------------------------------------------------------------
// Address: 0x1002C850
// Name: public: virtual int sfm_blurfilterx_shader::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_blurfilterx_shader::CShader::GetFlags(sfm_blurfilterx_shader::CShader *this)
{
  return s_nFlags_33;
}

//------------------------------------------------------------------------------
// Address: 0x1002C860
// Name: public: virtual void sfm_blurfilterx_shader::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sfm_blurfilterx_shader::CShader::OnInitShaderInstance(
        sfm_blurfilterx_shader::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
  if ( !params[BLOOMWIDTH.m_Index]->IsDefined(this: params[BLOOMWIDTH.m_Index]) )
    ((void (__stdcall *)(int))params[BLOOMWIDTH.m_Index]->SetFloatValue)(a1: 1082130432);
}

//------------------------------------------------------------------------------
// Address: 0x1002C8E0
// Name: public: virtual void sfm_blurfilterx_shader::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sfm_blurfilterx_shader::CShader::OnDrawElements(
        sfm_blurfilterx_shader::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  sfm_blurfilterx_shader::CShader *v6; // edi
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float x; // xmm0_4
  float v10; // xmm2_4
  int i; // edi
  double v12; // xmm0_8
  float v13; // xmm0_4
  float v14; // xmm1_4
  float *v15; // eax
  int j; // ecx
  int k; // ecx
  long double v18; // [esp+0h] [ebp-140h]
  long double v19; // [esp+0h] [ebp-140h]
  float vCoeff[72]; // [esp+8h] [ebp-138h] BYREF
  float vDir[4]; // [esp+128h] [ebp-18h] BYREF
  float v22; // [esp+138h] [ebp-8h]
  sfm_blurfilterx_shader::CShader *v23; // [esp+13Ch] [ebp-4h]
  float *pDst; // [esp+148h] [ebp+8h]
  float pShaderShadowa; // [esp+14Ch] [ebp+Ch]
  float fAccum; // [esp+150h] [ebp+10h]

  v6 = this;
  v23 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: false);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "sfm_screenspace_vs30", a3: 0);
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "sfm_blur_ps30", a3: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v6,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetScreenSizeForVPOS(this: pShaderAPI, a2: 32);
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    vDir[0] = 0.0;
    vDir[1] = 1.0;
    vDir[2] = 0.0;
    vDir[3] = 0.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: vDir, a4: 1, a5: false);
    x = params[BLOOMWIDTH.m_Index]->m_VecVal.x;
    v10 = sqrt(6.283180236816406);
    pShaderShadowa = 1.0 / (float)(v10 * x);
    v22 = (float)(x * 2.0) * x;
    __libm_sse2_exp(x: v18);
    vCoeff[0] = COERCE_FLOAT(COERCE_UNSIGNED_INT(0.0 / (float)((float)(x * 2.0) * x)) ^ _mask__NegFloat_)
              * pShaderShadowa;
    fAccum = vCoeff[0];
    pDst = &vCoeff[4];
    for ( i = 1; i < 18; ++i )
    {
      v12 = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)i * (float)i) / v22) ^ _mask__NegFloat_);
      __libm_sse2_exp(x: v19);
      *(float *)&v12 = v12;
      *(float *)&v12 = *(float *)&v12 * pShaderShadowa;
      *pDst = *(float *)&v12;
      v13 = (float)(*(float *)&v12 * 2.0) + fAccum;
      fAccum = v13;
      pDst += 4;
    }
    v14 = 1.0 / v13;
    vCoeff[0] = (float)(1.0 / v13) * vCoeff[0];
    v15 = &vCoeff[4];
    for ( j = 2; j != 0; --j )
    {
      *v15 = v14 * *v15;
      v15[4] = v14 * v15[4];
      v15[8] = v15[8] * v14;
      v15[12] = v15[12] * v14;
      v15[16] = v15[16] * v14;
      v15[20] = v15[20] * v14;
      v15[24] = v15[24] * v14;
      v15[28] = v15[28] * v14;
      v15 += 32;
    }
    for ( k = 1; k != 0; --k )
    {
      *v15 = v14 * *v15;
      v15 += 4;
    }
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 33, a3: vCoeff, a4: 18, a5: false);
    v6 = v23;
  }
  CBaseShader::Draw(this: v6, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002CBA0
// Name: public: virtual int sfm_blurfilterx_shader::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_blurfilterx_shader::CShader::GetParamCount(sfm_blurfilterx_shader::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_96.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002CBB0
// Name: public: virtual struct ShaderParamInfo_t const __near & sfm_blurfilterx_shader::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
sfm_blurfilterx_shader::CShaderParam *__thiscall sfm_blurfilterx_shader::CShader::GetParamInfo(
        sfm_blurfilterx_shader::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_96.m_Memory.m_pMemory[param - ParamCount];
  else
    return (sfm_blurfilterx_shader::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002CBE0
// Name: public: sfm_blurfilterx_shader::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
sfm_blurfilterx_shader::CShaderParam *__thiscall sfm_blurfilterx_shader::CShaderParam::CShaderParam(
        sfm_blurfilterx_shader::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  sfm_blurfilterx_shader::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  sfm_blurfilterx_shader::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_96.m_Size + 13;
  m_Size = s_ShaderParams_96.m_Size;
  v8 = s_ShaderParams_96.m_Size;
  if ( s_ShaderParams_96.m_Size + 1 > s_ShaderParams_96.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_96,
      num: s_ShaderParams_96.m_Size - s_ShaderParams_96.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_96.m_Size;
  }
  m_pMemory = s_ShaderParams_96.m_Memory.m_pMemory;
  s_ShaderParams_96.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_96.m_pElements = s_ShaderParams_96.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_96.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_96.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_96.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10065CC0
// Name: sfm_blurfilterx_shader::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int sfm_blurfilterx_shader::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: sfm_blurfilterx_shader::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10065CD0
// Name: sfm_blurfilterx_shader::_dynamic_initializer_for__BLOOMWIDTH__
// Source: json
//------------------------------------------------------------------------------
sfm_blurfilterx_shader::CShaderParam *sfm_blurfilterx_shader::_dynamic_initializer_for__BLOOMWIDTH__()
{
  return sfm_blurfilterx_shader::CShaderParam::CShaderParam(
           this: &BLOOMWIDTH,
           pName: "$BLOOMWIDTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065CF0
// Name: sfm_blurfilterx_shader::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *sfm_blurfilterx_shader::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_96);
  s_ShaderInstance_96.__vftable = (sfm_blurfilterx_shader::CShader_vtbl *)&sfm_blurfilterx_shader::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B670
// Name: sfm_blurfilterx_shader::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl sfm_blurfilterx_shader::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_96);
}

//------------------------------------------------------------------------------
// Address: 0x10065D10
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_screenspace_vs30___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_screenspace_vs30___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_screenspace_vs30_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x10065D30
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_blur_ps30___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_blur_ps30___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_blur_ps30_combos_0);
}
