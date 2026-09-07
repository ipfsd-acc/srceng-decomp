// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/sfm_ao_blur.cpp
// Functions: 15
// ============================================================

#include "materialsystem\stdshaders\sfm_ao_blur.h"

//------------------------------------------------------------------------------
// Address: 0x1002C560
// Name: public: virtual char const __near * sfm_ao_blur_shader::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall sfm_ao_blur_shader::CShader::GetName(sfm_ao_blur_shader::CShader *this)
{
  return s_Name_95;
}

//------------------------------------------------------------------------------
// Address: 0x1002C570
// Name: public: virtual int sfm_ao_blur_shader::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_ao_blur_shader::CShader::GetFlags(sfm_ao_blur_shader::CShader *this)
{
  return s_nFlags_32;
}

//------------------------------------------------------------------------------
// Address: 0x1002C580
// Name: public: virtual void sfm_ao_blur_shader::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sfm_ao_blur_shader::CShader::OnInitShaderInstance(
        sfm_ao_blur_shader::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: FRONTNDTEXTURE_0.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: AOTEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002C5B0
// Name: public: virtual void sfm_ao_blur_shader::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sfm_ao_blur_shader::CShader::OnDrawElements(
        sfm_ao_blur_shader::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IShaderShadow *v6; // esi
  IShaderDynamicAPI *v8; // esi
  void (__thiscall *GetBackBufferDimensions)(IShaderDynamicAPI *, int *, int *); // edx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float vNoiseOffset[4]; // [esp+78h] [ebp-20h] BYREF
  float vScreenScale[4]; // [esp+88h] [ebp-10h] BYREF

  v6 = pShaderShadow;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    v6->EnableDepthTest(this: v6, a2: false);
    v6->EnableAlphaWrites(this: v6, a2: false);
    v6->EnableBlending(this: v6, a2: false);
    v6->EnableCulling(this: v6, a2: false);
    v6->EnableTexture(this: v6, a2: SHADER_SAMPLER0, a3: true);
    v6->EnableTexture(this: v6, a2: SHADER_SAMPLER1, a3: true);
    v6->EnableTexture(this: v6, a2: SHADER_SAMPLER2, a3: true);
    v6->VertexShaderVertexFormat(this: v6, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    v6->SetVertexShader(this: v6, a2: "sfm_ao_blur_vs30", a3: 0);
    v6->SetPixelShader(this: v6, a2: "sfm_ao_blur_ps30", a3: 0);
  }
  v8 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: FRONTNDTEXTURE_0.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: AOTEXTURE.m_Index,
      nFrameVar: -1);
    GetBackBufferDimensions = v8->GetBackBufferDimensions;
    vScreenScale[0] = 40.0;
    vScreenScale[1] = 22.5;
    vScreenScale[2] = 0.0;
    vScreenScale[3] = 0.0;
    GetBackBufferDimensions(this: v8, a2: (int *)&pShaderShadow, a3: (int *)&pShaderAPI);
    SetPixelShaderConstant = v8->SetPixelShaderConstant;
    vScreenScale[0] = (float)(int)pShaderShadow * 0.03125;
    vScreenScale[1] = (float)(int)pShaderAPI * 0.03125;
    SetPixelShaderConstant(this: v8, a2: 0, a3: vScreenScale, a4: 1, a5: false);
    CBaseVSShader::HashShadow2DJitter(
      this,
      fJitterSeed: params[JITTERSEED_0.m_Index]->m_VecVal.x,
      fU: vNoiseOffset,
      fV: &vNoiseOffset[1]);
    v8->SetPixelShaderConstant(this: v8, a2: 1, a3: vNoiseOffset, a4: 1, a5: false);
    v8->SetVertexShaderIndex(this: v8, a2: 0);
    v8->SetPixelShaderIndex(this: v8, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002C760
// Name: public: virtual int sfm_ao_blur_shader::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_ao_blur_shader::CShader::GetParamCount(sfm_ao_blur_shader::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_95.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002C770
// Name: public: virtual struct ShaderParamInfo_t const __near & sfm_ao_blur_shader::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
sfm_ao_blur_shader::CShaderParam *__thiscall sfm_ao_blur_shader::CShader::GetParamInfo(
        sfm_ao_blur_shader::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_95.m_Memory.m_pMemory[param - ParamCount];
  else
    return (sfm_ao_blur_shader::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002C7A0
// Name: public: sfm_ao_blur_shader::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
sfm_ao_blur_shader::CShaderParam *__thiscall sfm_ao_blur_shader::CShaderParam::CShaderParam(
        sfm_ao_blur_shader::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  sfm_ao_blur_shader::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  sfm_ao_blur_shader::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_95.m_Size + 13;
  m_Size = s_ShaderParams_95.m_Size;
  v8 = s_ShaderParams_95.m_Size;
  if ( s_ShaderParams_95.m_Size + 1 > s_ShaderParams_95.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_95,
      num: s_ShaderParams_95.m_Size - s_ShaderParams_95.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_95.m_Size;
  }
  m_pMemory = s_ShaderParams_95.m_Memory.m_pMemory;
  s_ShaderParams_95.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_95.m_pElements = s_ShaderParams_95.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_95.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_95.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_95.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10065BF0
// Name: sfm_ao_blur_shader::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int sfm_ao_blur_shader::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: sfm_ao_blur_shader::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10065C00
// Name: sfm_ao_blur_shader::_dynamic_initializer_for__FRONTNDTEXTURE__
// Source: json
//------------------------------------------------------------------------------
sfm_ao_blur_shader::CShaderParam *sfm_ao_blur_shader::_dynamic_initializer_for__FRONTNDTEXTURE__()
{
  return sfm_ao_blur_shader::CShaderParam::CShaderParam(
           this: &FRONTNDTEXTURE_0,
           pName: "$FRONTNDTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065C20
// Name: sfm_ao_blur_shader::_dynamic_initializer_for__AOTEXTURE__
// Source: json
//------------------------------------------------------------------------------
sfm_ao_blur_shader::CShaderParam *sfm_ao_blur_shader::_dynamic_initializer_for__AOTEXTURE__()
{
  return sfm_ao_blur_shader::CShaderParam::CShaderParam(
           this: &AOTEXTURE,
           pName: "$AOTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065C40
// Name: sfm_ao_blur_shader::_dynamic_initializer_for__JITTERSEED__
// Source: json
//------------------------------------------------------------------------------
sfm_ao_blur_shader::CShaderParam *sfm_ao_blur_shader::_dynamic_initializer_for__JITTERSEED__()
{
  return sfm_ao_blur_shader::CShaderParam::CShaderParam(
           this: &JITTERSEED_0,
           pName: "$JITTERSEED",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065C60
// Name: sfm_ao_blur_shader::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *sfm_ao_blur_shader::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_95);
  s_ShaderInstance_95.__vftable = (sfm_ao_blur_shader::CShader_vtbl *)&sfm_ao_blur_shader::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B660
// Name: sfm_ao_blur_shader::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl sfm_ao_blur_shader::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_95);
}

//------------------------------------------------------------------------------
// Address: 0x10065C80
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_screenspace_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_screenspace_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_screenspace_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10065CA0
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_blur_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_blur_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_blur_ps30_combos);
}
