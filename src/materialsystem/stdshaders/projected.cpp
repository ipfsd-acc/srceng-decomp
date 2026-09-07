// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/projected.cpp
// Functions: 25
// ============================================================

#include "materialsystem\stdshaders\projected.h"

//------------------------------------------------------------------------------
// Address: 0x10028020
// Name: public: virtual char const __near * Projected::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Projected::CShader::GetFallbackShader(Projected::CShader *this, IMaterialVar **params)
{
  return "Projected_DX90";
}

//------------------------------------------------------------------------------
// Address: 0x10028030
// Name: public: virtual char const __near * Projected::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Projected::CShader::GetName(Projected::CShader *this)
{
  return s_Name_82;
}

//------------------------------------------------------------------------------
// Address: 0x10028040
// Name: public: virtual int Projected::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Projected::CShader::GetFlags(Projected::CShader *this)
{
  return s_nFlags_99;
}

//------------------------------------------------------------------------------
// Address: 0x10028050
// Name: public: virtual int Projected::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Projected::CShader::GetParamCount(Projected::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_83.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10028060
// Name: public: virtual void Projected_DX90::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Projected_DX90::CShader::OnInitShaderParams(
        Projected_DX90::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  InitParamsProjected_DX9();
}

//------------------------------------------------------------------------------
// Address: 0x100280A0
// Name: public: virtual char const __near * Projected_DX90::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Projected_DX90::CShader::GetName(Projected_DX90::CShader *this)
{
  return s_Name_83;
}

//------------------------------------------------------------------------------
// Address: 0x100280B0
// Name: public: virtual int Projected_DX90::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Projected_DX90::CShader::GetFlags(Projected_DX90::CShader *this)
{
  return s_nFlags_100;
}

//------------------------------------------------------------------------------
// Address: 0x100280C0
// Name: public: virtual void Projected_DX90::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Projected_DX90::CShader::OnInitShaderInstance(
        Projected_DX90::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  Projected_DX9_Vars_t info; // [esp+0h] [ebp-8h] BYREF

  info.m_nBaseTextureTransform = 8;
  info.m_nBaseTexture = 6;
  InitProjected_DX9(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10028100
// Name: public: virtual void Projected_DX90::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Projected_DX90::CShader::OnDrawElements(
        Projected_DX90::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  Projected_DX9_Vars_t info; // [esp+0h] [ebp-8h] BYREF

  info.m_nBaseTextureTransform = 8;
  info.m_nBaseTexture = 6;
  DrawProjected_DX9(pShader: this, params, pShaderAPI, pShaderShadow, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10028140
// Name: public: virtual int Projected_DX90::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Projected_DX90::CShader::GetParamCount(Projected_DX90::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_82.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10028150
// Name: public: virtual struct ShaderParamInfo_t const __near & Projected::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Projected::CShaderParam *__thiscall Projected::CShader::GetParamInfo(Projected::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_83.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Projected::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10028180
// Name: public: virtual struct ShaderParamInfo_t const __near & Projected_DX90::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Projected_DX90::CShaderParam *__thiscall Projected_DX90::CShader::GetParamInfo(
        Projected_DX90::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_82.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Projected_DX90::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100281B0
// Name: public: Projected_DX90::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Projected_DX90::CShaderParam *__thiscall Projected_DX90::CShaderParam::CShaderParam(
        Projected_DX90::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Projected_DX90::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Projected_DX90::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_82.m_Size + 13;
  m_Size = s_ShaderParams_82.m_Size;
  v8 = s_ShaderParams_82.m_Size;
  if ( s_ShaderParams_82.m_Size + 1 > s_ShaderParams_82.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_82,
      num: s_ShaderParams_82.m_Size - s_ShaderParams_82.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_82.m_Size;
  }
  m_pMemory = s_ShaderParams_82.m_Memory.m_pMemory;
  s_ShaderParams_82.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_82.m_pElements = s_ShaderParams_82.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_82.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_82.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_82.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10064A30
// Name: Projected::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Projected::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Projected::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064A40
// Name: Projected::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Projected::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_83);
  s_ShaderInstance_83.__vftable = (Projected::CShader_vtbl *)&Projected::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064A60
// Name: Projected_DX90::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Projected_DX90::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Projected_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064A70
// Name: Projected_DX90::_dynamic_initializer_for__SPECTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Projected_DX90::CShaderParam *Projected_DX90::_dynamic_initializer_for__SPECTEXTURE__()
{
  return Projected_DX90::CShaderParam::CShaderParam(
           this: &SPECTEXTURE_0,
           pName: "$SPECTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064A90
// Name: Projected_DX90::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Projected_DX90::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_82);
  s_ShaderInstance_82.__vftable = (Projected_DX90::CShader_vtbl *)&Projected_DX90::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B590
// Name: Projected::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Projected::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_83);
}

//------------------------------------------------------------------------------
// Address: 0x1006B5A0
// Name: Projected_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Projected_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_82);
}

//------------------------------------------------------------------------------
// Address: 0x10064AB0
// Name: _dynamic_initializer_for__s_ConstructMe_projected_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_projected_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &projected_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064AD0
// Name: _dynamic_initializer_for__s_ConstructMe_projected_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_projected_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &projected_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064AF0
// Name: _dynamic_initializer_for__s_ConstructMe_projected_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_projected_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &projected_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064B10
// Name: _dynamic_initializer_for__s_ConstructMe_projected_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_projected_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &projected_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064B30
// Name: _dynamic_initializer_for__s_ConstructMe_projected_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_projected_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &projected_ps30_combos);
}
