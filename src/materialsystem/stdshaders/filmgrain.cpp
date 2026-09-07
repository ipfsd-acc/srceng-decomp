// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/filmgrain.cpp
// Functions: 18
// ============================================================

#include "materialsystem\stdshaders\filmgrain.h"

//------------------------------------------------------------------------------
// Address: 0x10012A50
// Name: public: virtual char const __near * FilmGrain::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall FilmGrain::CShader::GetName(FilmGrain::CShader *this)
{
  return s_Name_37;
}

//------------------------------------------------------------------------------
// Address: 0x10012A60
// Name: public: virtual int FilmGrain::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall FilmGrain::CShader::GetFlags(FilmGrain::CShader *this)
{
  return s_nFlags_14;
}

//------------------------------------------------------------------------------
// Address: 0x10012A70
// Name: public: virtual void FilmGrain::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FilmGrain::CShader::OnInitShaderInstance(
        FilmGrain::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: GRAIN_TEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10012A80
// Name: public: virtual void FilmGrain::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FilmGrain::CShader::OnDrawElements(
        FilmGrain::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
    pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_ONE, a3: SHADER_BLEND_SRC_ALPHA);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "filmgrain_ps20", a3: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: GRAIN_TEXTURE.m_Index,
      nFrameVar: -1);
    CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 0, constantVar: NOISESCALE_0.m_Index);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10012B30
// Name: public: virtual int FilmGrain::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall FilmGrain::CShader::GetParamCount(FilmGrain::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_37.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10012B40
// Name: public: virtual struct ShaderParamInfo_t const __near & FilmGrain::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
FilmGrain::CShaderParam *__thiscall FilmGrain::CShader::GetParamInfo(FilmGrain::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_37.m_Memory.m_pMemory[param - ParamCount];
  else
    return (FilmGrain::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10012B70
// Name: public: FilmGrain::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
FilmGrain::CShaderParam *__thiscall FilmGrain::CShaderParam::CShaderParam(
        FilmGrain::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  FilmGrain::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  FilmGrain::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_37.m_Size + 13;
  m_Size = s_ShaderParams_37.m_Size;
  v8 = s_ShaderParams_37.m_Size;
  if ( s_ShaderParams_37.m_Size + 1 > s_ShaderParams_37.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_37,
      num: s_ShaderParams_37.m_Size - s_ShaderParams_37.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_37.m_Size;
  }
  m_pMemory = s_ShaderParams_37.m_Memory.m_pMemory;
  s_ShaderParams_37.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_37.m_pElements = s_ShaderParams_37.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_37.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_37.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_37.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100614B0
// Name: FilmGrain::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int FilmGrain::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: FilmGrain::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100614C0
// Name: FilmGrain::_dynamic_initializer_for__GRAIN_TEXTURE__
// Source: json
//------------------------------------------------------------------------------
FilmGrain::CShaderParam *FilmGrain::_dynamic_initializer_for__GRAIN_TEXTURE__()
{
  return FilmGrain::CShaderParam::CShaderParam(
           this: &GRAIN_TEXTURE,
           pName: "$GRAIN_TEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "0",
           pHelp: "Film grain texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100614E0
// Name: FilmGrain::_dynamic_initializer_for__NOISESCALE__
// Source: json
//------------------------------------------------------------------------------
FilmGrain::CShaderParam *FilmGrain::_dynamic_initializer_for__NOISESCALE__()
{
  return FilmGrain::CShaderParam::CShaderParam(
           this: &NOISESCALE_0,
           pName: "$NOISESCALE",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: "Strength of film grain",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061500
// Name: FilmGrain::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *FilmGrain::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_37);
  s_ShaderInstance_37.__vftable = (FilmGrain::CShader_vtbl *)&FilmGrain::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B1F0
// Name: FilmGrain::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl FilmGrain::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_37);
}

//------------------------------------------------------------------------------
// Address: 0x10061520
// Name: _dynamic_initializer_for__s_ConstructMe_flesh_interior_blended_pass_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_flesh_interior_blended_pass_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &flesh_interior_blended_pass_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061540
// Name: _dynamic_initializer_for__s_ConstructMe_flesh_interior_blended_pass_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_flesh_interior_blended_pass_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &flesh_interior_blended_pass_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061560
// Name: _dynamic_initializer_for__s_ConstructMe_flesh_interior_blended_pass_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_flesh_interior_blended_pass_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &flesh_interior_blended_pass_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061580
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___5
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___5()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_5);
}

//------------------------------------------------------------------------------
// Address: 0x100615A0
// Name: _dynamic_initializer_for__s_ConstructMe_floatcombine_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_floatcombine_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &floatcombine_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100615C0
// Name: _dynamic_initializer_for__s_ConstructMe_floatcombine_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_floatcombine_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &floatcombine_ps20b_combos);
}
