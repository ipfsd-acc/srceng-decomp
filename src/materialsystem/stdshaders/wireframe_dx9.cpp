// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/wireframe_dx9.cpp
// Functions: 24
// ============================================================

#include "materialsystem\stdshaders\wireframe_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10044740
// Name: public: virtual char const __near * Wireframe::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Wireframe::CShader::GetFallbackShader(Wireframe::CShader *this, IMaterialVar **params)
{
  return "Wireframe_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x10044750
// Name: public: virtual char const __near * Wireframe::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Wireframe::CShader::GetName(Wireframe::CShader *this)
{
  return s_Name_132;
}

//------------------------------------------------------------------------------
// Address: 0x10044760
// Name: public: virtual int Wireframe::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Wireframe::CShader::GetFlags(Wireframe::CShader *this)
{
  return s_nFlags_134;
}

//------------------------------------------------------------------------------
// Address: 0x10044770
// Name: public: virtual int Wireframe::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Wireframe::CShader::GetParamCount(Wireframe::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_131.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10044780
// Name: public: virtual void Wireframe_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Wireframe_DX9::CShader::OnInitShaderParams(
        Wireframe_DX9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  VertexLitGeneric_DX9_Vars_t vars; // [esp+8h] [ebp-1BCh] BYREF

  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  vars.m_nDisplacementMap = DISPLACEMENTMAP_2.m_Index;
  vars.m_nDisplacementWrinkleMap = DISPLACEMENTWRINKLE_1.m_Index;
  InitParamsVertexLitGeneric_DX9(pShader: this, params, pMaterialName, bVertexLitGeneric: false, info: &vars);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 2);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x4000);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x10000000);
}

//------------------------------------------------------------------------------
// Address: 0x10044810
// Name: public: virtual char const __near * Wireframe_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Wireframe_DX9::CShader::GetName(Wireframe_DX9::CShader *this)
{
  return s_Name_133;
}

//------------------------------------------------------------------------------
// Address: 0x10044820
// Name: public: virtual int Wireframe_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Wireframe_DX9::CShader::GetFlags(Wireframe_DX9::CShader *this)
{
  return s_nFlags_135;
}

//------------------------------------------------------------------------------
// Address: 0x10044830
// Name: public: virtual void Wireframe_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Wireframe_DX9::CShader::OnInitShaderInstance(
        Wireframe_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  VertexLitGeneric_DX9_Vars_t vars; // [esp+4h] [ebp-1BCh] BYREF

  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  vars.m_nDisplacementMap = DISPLACEMENTMAP_2.m_Index;
  vars.m_nDisplacementWrinkleMap = DISPLACEMENTWRINKLE_1.m_Index;
  InitVertexLitGeneric_DX9(pShader: this, params, bVertexLitGeneric: false, info: &vars);
}

//------------------------------------------------------------------------------
// Address: 0x10044890
// Name: public: virtual void Wireframe_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Wireframe_DX9::CShader::OnDrawElements(
        Wireframe_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  VertexLitGeneric_DX9_Vars_t vars; // [esp+4h] [ebp-1BCh] BYREF

  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  vars.m_nDisplacementMap = DISPLACEMENTMAP_2.m_Index;
  vars.m_nDisplacementWrinkleMap = DISPLACEMENTWRINKLE_1.m_Index;
  DrawVertexLitGeneric_DX9(
    pShader: this,
    params,
    pShaderAPI,
    pShaderShadow,
    bVertexLitGeneric: 0,
    info: &vars,
    vertexCompression,
    pContextDataPtr);
}

//------------------------------------------------------------------------------
// Address: 0x10044900
// Name: public: virtual int Wireframe_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Wireframe_DX9::CShader::GetParamCount(Wireframe_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_132.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10044910
// Name: public: virtual struct ShaderParamInfo_t const __near & Wireframe::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Wireframe::CShaderParam *__thiscall Wireframe::CShader::GetParamInfo(Wireframe::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_131.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Wireframe::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10044940
// Name: public: virtual struct ShaderParamInfo_t const __near & Wireframe_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Wireframe_DX9::CShaderParam *__thiscall Wireframe_DX9::CShader::GetParamInfo(Wireframe_DX9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_132.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Wireframe_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10044970
// Name: public: Wireframe_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Wireframe_DX9::CShaderParam *__thiscall Wireframe_DX9::CShaderParam::CShaderParam(
        Wireframe_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Wireframe_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Wireframe_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_132.m_Size + 13;
  m_Size = s_ShaderParams_132.m_Size;
  v8 = s_ShaderParams_132.m_Size;
  if ( s_ShaderParams_132.m_Size + 1 > s_ShaderParams_132.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_132,
      num: s_ShaderParams_132.m_Size - s_ShaderParams_132.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_132.m_Size;
  }
  m_pMemory = s_ShaderParams_132.m_Memory.m_pMemory;
  s_ShaderParams_132.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_132.m_pElements = s_ShaderParams_132.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_132.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_132.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_132.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006A420
// Name: Wireframe::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Wireframe::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Wireframe::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006A430
// Name: Wireframe::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Wireframe::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_132);
  s_ShaderInstance_132.__vftable = (Wireframe::CShader_vtbl *)&Wireframe::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006A450
// Name: Wireframe_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Wireframe_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Wireframe_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006A460
// Name: Wireframe_DX9::_dynamic_initializer_for__DISPLACEMENTMAP__
// Source: json
//------------------------------------------------------------------------------
Wireframe_DX9::CShaderParam *Wireframe_DX9::_dynamic_initializer_for__DISPLACEMENTMAP__()
{
  return Wireframe_DX9::CShaderParam::CShaderParam(
           this: &DISPLACEMENTMAP_2,
           pName: "$DISPLACEMENTMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Displacement map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A480
// Name: Wireframe_DX9::_dynamic_initializer_for__DISPLACEMENTWRINKLE__
// Source: json
//------------------------------------------------------------------------------
Wireframe_DX9::CShaderParam *Wireframe_DX9::_dynamic_initializer_for__DISPLACEMENTWRINKLE__()
{
  return Wireframe_DX9::CShaderParam::CShaderParam(
           this: &DISPLACEMENTWRINKLE_1,
           pName: "$DISPLACEMENTWRINKLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Displacement map contains wrinkle displacements",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A4A0
// Name: Wireframe_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Wireframe_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_133);
  s_ShaderInstance_133.__vftable = (Wireframe_DX9::CShader_vtbl *)&Wireframe_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B940
// Name: Wireframe::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Wireframe::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_131);
}

//------------------------------------------------------------------------------
// Address: 0x1006B950
// Name: Wireframe_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Wireframe_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_132);
}

//------------------------------------------------------------------------------
// Address: 0x1006A4C0
// Name: _dynamic_initializer_for__s_ConstructMe_worldimposter_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_worldimposter_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &worldimposter_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006A4E0
// Name: _dynamic_initializer_for__s_ConstructMe_worldimposter_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_worldimposter_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &worldimposter_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006A500
// Name: _dynamic_initializer_for__s_ConstructMe_worldimposter_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_worldimposter_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &worldimposter_ps20b_combos);
}
