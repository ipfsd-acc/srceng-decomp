// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/particlelitgeneric_dx9.cpp
// Functions: 16
// ============================================================

#include "materialsystem\stdshaders\particlelitgeneric_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10022230
// Name: public: virtual char const __near * ParticleLitGeneric_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ParticleLitGeneric_DX9::CShader::GetName(ParticleLitGeneric_DX9::CShader *this)
{
  return s_Name_74;
}

//------------------------------------------------------------------------------
// Address: 0x10022240
// Name: public: virtual int ParticleLitGeneric_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ParticleLitGeneric_DX9::CShader::GetFlags(ParticleLitGeneric_DX9::CShader *this)
{
  return s_nFlags_92;
}

//------------------------------------------------------------------------------
// Address: 0x10022250
// Name: public: virtual int ParticleLitGeneric_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ParticleLitGeneric_DX9::CShader::GetParamCount(ParticleLitGeneric_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_74.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10022260
// Name: public: virtual struct ShaderParamInfo_t const __near & ParticleLitGeneric_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ParticleLitGeneric_DX9::CShaderParam *__thiscall ParticleLitGeneric_DX9::CShader::GetParamInfo(
        ParticleLitGeneric_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_74.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ParticleLitGeneric_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10022290
// Name: public: ParticleLitGeneric_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ParticleLitGeneric_DX9::CShaderParam *__thiscall ParticleLitGeneric_DX9::CShaderParam::CShaderParam(
        ParticleLitGeneric_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  ParticleLitGeneric_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  ParticleLitGeneric_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_74.m_Size + 13;
  m_Size = s_ShaderParams_74.m_Size;
  v8 = s_ShaderParams_74.m_Size;
  if ( s_ShaderParams_74.m_Size + 1 > s_ShaderParams_74.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_74,
      num: s_ShaderParams_74.m_Size - s_ShaderParams_74.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_74.m_Size;
  }
  m_pMemory = s_ShaderParams_74.m_Memory.m_pMemory;
  s_ShaderParams_74.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_74.m_pElements = s_ShaderParams_74.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_74.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_74.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_74.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10064110
// Name: ParticleLitGeneric_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ParticleLitGeneric_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ParticleLitGeneric_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064120
// Name: ParticleLitGeneric_DX9::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
ParticleLitGeneric_DX9::CShaderParam *ParticleLitGeneric_DX9::_dynamic_initializer_for__BUMPMAP__()
{
  return ParticleLitGeneric_DX9::CShaderParam::CShaderParam(
           this: &BUMPMAP_2,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064140
// Name: ParticleLitGeneric_DX9::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
ParticleLitGeneric_DX9::CShaderParam *ParticleLitGeneric_DX9::_dynamic_initializer_for__BUMPFRAME__()
{
  return ParticleLitGeneric_DX9::CShaderParam::CShaderParam(
           this: &BUMPFRAME_7,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064160
// Name: ParticleLitGeneric_DX9::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
ParticleLitGeneric_DX9::CShaderParam *ParticleLitGeneric_DX9::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return ParticleLitGeneric_DX9::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM_3,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064180
// Name: ParticleLitGeneric_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ParticleLitGeneric_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_74);
  s_ShaderInstance_74.__vftable = (ParticleLitGeneric_DX9::CShader_vtbl *)&ParticleLitGeneric_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B4D0
// Name: ParticleLitGeneric_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParticleLitGeneric_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_74);
}

//------------------------------------------------------------------------------
// Address: 0x100641A0
// Name: _dynamic_initializer_for__s_ConstructMe_particlesphere_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_particlesphere_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &particlesphere_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100641C0
// Name: _dynamic_initializer_for__s_ConstructMe_particlesphere_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_particlesphere_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &particlesphere_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100641E0
// Name: _dynamic_initializer_for__s_ConstructMe_particlesphere_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_particlesphere_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &particlesphere_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064200
// Name: _dynamic_initializer_for__mat_depthfeather_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_depthfeather_enable__()
{
  ConVar::ConVar(this: &mat_depthfeather_enable, pName: "mat_depthfeather_enable", pDefaultValue: "1", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mat_depthfeather_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1006B4E0
// Name: _dynamic_atexit_destructor_for__mat_depthfeather_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_depthfeather_enable__()
{
  ConVar::~ConVar(this: &mat_depthfeather_enable);
}
