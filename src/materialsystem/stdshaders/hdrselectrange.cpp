// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/hdrselectrange.cpp
// Functions: 14
// ============================================================

#include "materialsystem\stdshaders\hdrselectrange.h"

//------------------------------------------------------------------------------
// Address: 0x100148B0
// Name: public: virtual char const __near * HDRSelectRange::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall HDRSelectRange::CShader::GetName(HDRSelectRange::CShader *this)
{
  return s_Name_44;
}

//------------------------------------------------------------------------------
// Address: 0x100148C0
// Name: public: virtual int HDRSelectRange::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall HDRSelectRange::CShader::GetFlags(HDRSelectRange::CShader *this)
{
  return s_nFlags_20;
}

//------------------------------------------------------------------------------
// Address: 0x100148D0
// Name: public: virtual void HDRSelectRange::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall HDRSelectRange::CShader::OnInitShaderInstance(
        HDRSelectRange::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: SOURCEMRTRENDERTARGET_0.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100148E0
// Name: public: virtual void HDRSelectRange::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall HDRSelectRange::CShader::OnDrawElements(
        HDRSelectRange::CShader *this,
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
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "HDRSelectRange_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v9 = 0;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "hdrselectrange_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "hdrselectrange_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: SOURCEMRTRENDERTARGET_0.m_Index,
      nFrameVar: -1);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    ((void (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
      a1: g_pHardwareConfig,
      a2: v9);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100149D0
// Name: public: virtual int HDRSelectRange::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall HDRSelectRange::CShader::GetParamCount(HDRSelectRange::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_44.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100149E0
// Name: public: virtual struct ShaderParamInfo_t const __near & HDRSelectRange::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
HDRSelectRange::CShaderParam *__thiscall HDRSelectRange::CShader::GetParamInfo(
        HDRSelectRange::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_44.m_Memory.m_pMemory[param - ParamCount];
  else
    return (HDRSelectRange::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10014A10
// Name: public: HDRSelectRange::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
HDRSelectRange::CShaderParam *__thiscall HDRSelectRange::CShaderParam::CShaderParam(
        HDRSelectRange::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  HDRSelectRange::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  HDRSelectRange::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_44.m_Size + 13;
  m_Size = s_ShaderParams_44.m_Size;
  v8 = s_ShaderParams_44.m_Size;
  if ( s_ShaderParams_44.m_Size + 1 > s_ShaderParams_44.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_44,
      num: s_ShaderParams_44.m_Size - s_ShaderParams_44.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_44.m_Size;
  }
  m_pMemory = s_ShaderParams_44.m_Memory.m_pMemory;
  s_ShaderParams_44.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_44.m_pElements = s_ShaderParams_44.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_44.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_44.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_44.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10061C60
// Name: HDRSelectRange::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int HDRSelectRange::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: HDRSelectRange::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061C70
// Name: HDRSelectRange::_dynamic_initializer_for__SOURCEMRTRENDERTARGET__
// Source: json
//------------------------------------------------------------------------------
HDRSelectRange::CShaderParam *HDRSelectRange::_dynamic_initializer_for__SOURCEMRTRENDERTARGET__()
{
  return HDRSelectRange::CShaderParam::CShaderParam(
           this: &SOURCEMRTRENDERTARGET_0,
           pName: "$SOURCEMRTRENDERTARGET",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061C90
// Name: HDRSelectRange::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *HDRSelectRange::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_44);
  s_ShaderInstance_44.__vftable = (HDRSelectRange::CShader_vtbl *)&HDRSelectRange::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B260
// Name: HDRSelectRange::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl HDRSelectRange::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_44);
}

//------------------------------------------------------------------------------
// Address: 0x10061CB0
// Name: _dynamic_initializer_for__s_ConstructMe_filmgrain_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_filmgrain_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &filmgrain_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061CD0
// Name: _dynamic_initializer_for__s_ConstructMe_hsl_filmgrain_pass1_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_hsl_filmgrain_pass1_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &hsl_filmgrain_pass1_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061CF0
// Name: _dynamic_initializer_for__s_ConstructMe_hsl_filmgrain_pass1_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_hsl_filmgrain_pass1_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &hsl_filmgrain_pass1_ps20b_combos);
}
