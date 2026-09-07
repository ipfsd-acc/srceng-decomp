// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/accumbuff5sample.cpp
// Functions: 16
// ============================================================

#include "materialsystem\stdshaders\accumbuff5sample.h"

//------------------------------------------------------------------------------
// Address: 0x100013E0
// Name: public: virtual char const __near * accumbuff5sample::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall accumbuff5sample::CShader::GetName(accumbuff5sample::CShader *this)
{
  return s_Name_0;
}

//------------------------------------------------------------------------------
// Address: 0x100013F0
// Name: public: virtual int accumbuff5sample::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall accumbuff5sample::CShader::GetFlags(accumbuff5sample::CShader *this)
{
  return s_nFlags_0;
}

//------------------------------------------------------------------------------
// Address: 0x10001400
// Name: public: virtual void accumbuff5sample::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall accumbuff5sample::CShader::OnInitShaderInstance(
        accumbuff5sample::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: TEXTURE0_0.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: TEXTURE1_0.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: TEXTURE2_0.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: TEXTURE3_0.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: TEXTURE4.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10001460
// Name: public: virtual void accumbuff5sample::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall accumbuff5sample::CShader::OnDrawElements(
        accumbuff5sample::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v7; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  int v9; // [esp+0h] [ebp-8h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: false);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v9 = 0;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "accumbuff5sample_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "accumbuff5sample_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: TEXTURE0_0.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: TEXTURE1_0.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: TEXTURE2_0.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER3,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: TEXTURE3_0.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER4,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: TEXTURE4.m_Index,
      nFrameVar: -1);
    CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 0, constantVar: WEIGHTS_0.m_Index);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    ((void (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
      a1: g_pHardwareConfig,
      a2: v9);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100015F0
// Name: public: virtual int accumbuff5sample::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall accumbuff5sample::CShader::GetParamCount(accumbuff5sample::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_0.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001600
// Name: public: virtual struct ShaderParamInfo_t const __near & accumbuff5sample::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
accumbuff5sample::CShaderParam *__thiscall accumbuff5sample::CShader::GetParamInfo(
        accumbuff5sample::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_0.m_Memory.m_pMemory[param - ParamCount];
  else
    return (accumbuff5sample::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10001630
// Name: public: accumbuff5sample::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
accumbuff5sample::CShaderParam *__thiscall accumbuff5sample::CShaderParam::CShaderParam(
        accumbuff5sample::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  accumbuff5sample::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  accumbuff5sample::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_0.m_Size + 13;
  m_Size = s_ShaderParams_0.m_Size;
  v8 = s_ShaderParams_0.m_Size;
  if ( s_ShaderParams_0.m_Size + 1 > s_ShaderParams_0.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_0,
      num: s_ShaderParams_0.m_Size - s_ShaderParams_0.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_0.m_Size;
  }
  m_pMemory = s_ShaderParams_0.m_Memory.m_pMemory;
  s_ShaderParams_0.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_0.m_pElements = s_ShaderParams_0.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_0.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_0.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_0.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005DED0
// Name: accumbuff5sample::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int accumbuff5sample::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: accumbuff5sample::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005DEE0
// Name: accumbuff5sample::_dynamic_initializer_for__TEXTURE0__
// Source: json
//------------------------------------------------------------------------------
accumbuff5sample::CShaderParam *accumbuff5sample::_dynamic_initializer_for__TEXTURE0__()
{
  return accumbuff5sample::CShaderParam::CShaderParam(
           this: &TEXTURE0_0,
           pName: "$TEXTURE0",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DF00
// Name: accumbuff5sample::_dynamic_initializer_for__TEXTURE1__
// Source: json
//------------------------------------------------------------------------------
accumbuff5sample::CShaderParam *accumbuff5sample::_dynamic_initializer_for__TEXTURE1__()
{
  return accumbuff5sample::CShaderParam::CShaderParam(
           this: &TEXTURE1_0,
           pName: "$TEXTURE1",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DF20
// Name: accumbuff5sample::_dynamic_initializer_for__TEXTURE2__
// Source: json
//------------------------------------------------------------------------------
accumbuff5sample::CShaderParam *accumbuff5sample::_dynamic_initializer_for__TEXTURE2__()
{
  return accumbuff5sample::CShaderParam::CShaderParam(
           this: &TEXTURE2_0,
           pName: "$TEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DF40
// Name: accumbuff5sample::_dynamic_initializer_for__TEXTURE3__
// Source: json
//------------------------------------------------------------------------------
accumbuff5sample::CShaderParam *accumbuff5sample::_dynamic_initializer_for__TEXTURE3__()
{
  return accumbuff5sample::CShaderParam::CShaderParam(
           this: &TEXTURE3_0,
           pName: "$TEXTURE3",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DF60
// Name: accumbuff5sample::_dynamic_initializer_for__TEXTURE4__
// Source: json
//------------------------------------------------------------------------------
accumbuff5sample::CShaderParam *accumbuff5sample::_dynamic_initializer_for__TEXTURE4__()
{
  return accumbuff5sample::CShaderParam::CShaderParam(
           this: &TEXTURE4,
           pName: "$TEXTURE4",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DF80
// Name: accumbuff5sample::_dynamic_initializer_for__WEIGHTS__
// Source: json
//------------------------------------------------------------------------------
accumbuff5sample::CShaderParam *accumbuff5sample::_dynamic_initializer_for__WEIGHTS__()
{
  return accumbuff5sample::CShaderParam::CShaderParam(
           this: &WEIGHTS_0,
           pName: "$WEIGHTS",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: "Weight for Samples",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DFA0
// Name: accumbuff5sample::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *accumbuff5sample::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_0);
  s_ShaderInstance_0.__vftable = (accumbuff5sample::CShader_vtbl *)&accumbuff5sample::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AE50
// Name: accumbuff5sample::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl accumbuff5sample::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_0);
}
