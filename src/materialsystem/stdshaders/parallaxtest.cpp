// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/parallaxtest.cpp
// Functions: 12
// ============================================================

#include "materialsystem\stdshaders\parallaxtest.h"

//------------------------------------------------------------------------------
// Address: 0x10022010
// Name: public: virtual char const __near * ParallaxTest::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ParallaxTest::CShader::GetName(ParallaxTest::CShader *this)
{
  return s_Name_73;
}

//------------------------------------------------------------------------------
// Address: 0x10022020
// Name: public: virtual int ParallaxTest::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ParallaxTest::CShader::GetFlags(ParallaxTest::CShader *this)
{
  return s_nFlags_91;
}

//------------------------------------------------------------------------------
// Address: 0x10022030
// Name: public: virtual void ParallaxTest::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParallaxTest::CShader::OnInitShaderInstance(
        ParallaxTest::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: BUMPMAP_1.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10022050
// Name: public: virtual void ParallaxTest::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParallaxTest::CShader::OnDrawElements(
        ParallaxTest::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  float m_fValue; // xmm1_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  Vector4D c0; // [esp+8h] [ebp-10h] BYREF

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 51u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "parallaxtest_vs30", a3: 0);
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "parallaxtest_ps30", a3: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: 7);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: BUMPMAP_1.m_Index,
      nFrameVar: BUMPFRAME_6.m_Index);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    m_fValue = mat_parallaxmapsamplesmin.m_pParent->m_Value.m_fValue;
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    c0.y = mat_parallaxmapsamplesmax.m_pParent->m_Value.m_fValue;
    c0.x = m_fValue;
    c0.z = 0.0;
    c0.w = 0.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: &c0.x, a4: 1, a5: false);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10022150
// Name: public: virtual int ParallaxTest::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ParallaxTest::CShader::GetParamCount(ParallaxTest::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_73.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10022160
// Name: public: virtual struct ShaderParamInfo_t const __near & ParallaxTest::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ParallaxTest::CShaderParam *__thiscall ParallaxTest::CShader::GetParamInfo(ParallaxTest::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_73.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ParallaxTest::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10022190
// Name: public: ParallaxTest::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ParallaxTest::CShaderParam *__thiscall ParallaxTest::CShaderParam::CShaderParam(
        ParallaxTest::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  ParallaxTest::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  ParallaxTest::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_73.m_Size + 13;
  m_Size = s_ShaderParams_73.m_Size;
  v8 = s_ShaderParams_73.m_Size;
  if ( s_ShaderParams_73.m_Size + 1 > s_ShaderParams_73.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_73,
      num: s_ShaderParams_73.m_Size - s_ShaderParams_73.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_73.m_Size;
  }
  m_pMemory = s_ShaderParams_73.m_Memory.m_pMemory;
  s_ShaderParams_73.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_73.m_pElements = s_ShaderParams_73.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_73.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_73.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_73.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100640A0
// Name: ParallaxTest::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ParallaxTest::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ParallaxTest::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100640B0
// Name: ParallaxTest::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
ParallaxTest::CShaderParam *ParallaxTest::_dynamic_initializer_for__BUMPMAP__()
{
  return ParallaxTest::CShaderParam::CShaderParam(
           this: &BUMPMAP_1,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100640D0
// Name: ParallaxTest::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
ParallaxTest::CShaderParam *ParallaxTest::_dynamic_initializer_for__BUMPFRAME__()
{
  return ParallaxTest::CShaderParam::CShaderParam(
           this: &BUMPFRAME_6,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100640F0
// Name: ParallaxTest::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ParallaxTest::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_73);
  s_ShaderInstance_73.__vftable = (ParallaxTest::CShader_vtbl *)&ParallaxTest::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B4C0
// Name: ParallaxTest::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParallaxTest::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_73);
}
