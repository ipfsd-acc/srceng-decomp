// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/prototype.cpp
// Functions: 24
// ============================================================

#include "materialsystem\stdshaders\prototype.h"

//------------------------------------------------------------------------------
// Address: 0x10028F00
// Name: public: virtual char const __near * Prototype::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Prototype::CShader::GetFallbackShader(Prototype::CShader *this, IMaterialVar **params)
{
  return "Prototype_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x10028F10
// Name: public: virtual char const __near * Prototype::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Prototype::CShader::GetName(Prototype::CShader *this)
{
  return s_Name_86;
}

//------------------------------------------------------------------------------
// Address: 0x10028F20
// Name: public: virtual int Prototype::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Prototype::CShader::GetFlags(Prototype::CShader *this)
{
  return s_nFlags_103;
}

//------------------------------------------------------------------------------
// Address: 0x10028F30
// Name: public: virtual int Prototype::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Prototype::CShader::GetParamCount(Prototype::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_87.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10028F40
// Name: public: virtual void Prototype_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Prototype_dx9::CShader::OnInitShaderParams(
        Prototype_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  PrototypeVars_t info; // [esp+0h] [ebp-10h] BYREF

  info.m_nBumpmap = BUMPMAP_5.m_Index;
  info.m_nBumpFrame = BUMPFRAME_9.m_Index;
  info.m_nBaseTexture = 6;
  info.m_nBaseTextureFrame = 7;
  InitParamsPrototype(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10028F90
// Name: public: virtual char const __near * Prototype_dx9::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Prototype_dx9::CShader::GetFallbackShader(Prototype_dx9::CShader *this, IMaterialVar **params)
{
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 90
    || g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
  {
    return "Wireframe";
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028FD0
// Name: public: virtual char const __near * Prototype_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Prototype_dx9::CShader::GetName(Prototype_dx9::CShader *this)
{
  return s_Name_87;
}

//------------------------------------------------------------------------------
// Address: 0x10028FE0
// Name: public: virtual int Prototype_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Prototype_dx9::CShader::GetFlags(Prototype_dx9::CShader *this)
{
  return s_nFlags_104;
}

//------------------------------------------------------------------------------
// Address: 0x10028FF0
// Name: public: virtual void Prototype_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Prototype_dx9::CShader::OnInitShaderInstance(
        Prototype_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  PrototypeVars_t info; // [esp+0h] [ebp-10h] BYREF

  info.m_nBumpmap = BUMPMAP_5.m_Index;
  info.m_nBumpFrame = BUMPFRAME_9.m_Index;
  info.m_nBaseTexture = 6;
  info.m_nBaseTextureFrame = 7;
  InitPrototype(pShader: this, params, (ProtoIceVars_t *)&info);
}

//------------------------------------------------------------------------------
// Address: 0x10029040
// Name: public: virtual void Prototype_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Prototype_dx9::CShader::OnDrawElements(
        Prototype_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  PrototypeVars_t info; // [esp+0h] [ebp-10h] BYREF

  info.m_nBumpmap = BUMPMAP_5.m_Index;
  info.m_nBumpFrame = BUMPFRAME_9.m_Index;
  info.m_nBaseTexture = 6;
  info.m_nBaseTextureFrame = 7;
  DrawPrototype(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x100290A0
// Name: public: virtual int Prototype_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Prototype_dx9::CShader::GetParamCount(Prototype_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_86.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100290B0
// Name: public: virtual struct ShaderParamInfo_t const __near & Prototype::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Prototype::CShaderParam *__thiscall Prototype::CShader::GetParamInfo(Prototype::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_87.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Prototype::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100290E0
// Name: public: virtual struct ShaderParamInfo_t const __near & Prototype_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Prototype_dx9::CShaderParam *__thiscall Prototype_dx9::CShader::GetParamInfo(Prototype_dx9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_86.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Prototype_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10029110
// Name: public: Prototype_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Prototype_dx9::CShaderParam *__thiscall Prototype_dx9::CShaderParam::CShaderParam(
        Prototype_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Prototype_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Prototype_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_86.m_Size + 13;
  m_Size = s_ShaderParams_86.m_Size;
  v8 = s_ShaderParams_86.m_Size;
  if ( s_ShaderParams_86.m_Size + 1 > s_ShaderParams_86.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_86,
      num: s_ShaderParams_86.m_Size - s_ShaderParams_86.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_86.m_Size;
  }
  m_pMemory = s_ShaderParams_86.m_Memory.m_pMemory;
  s_ShaderParams_86.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_86.m_pElements = s_ShaderParams_86.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_86.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_86.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_86.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10064C50
// Name: Prototype::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Prototype::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Prototype::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064C60
// Name: Prototype::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Prototype::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_87);
  s_ShaderInstance_87.__vftable = (Prototype::CShader_vtbl *)&Prototype::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064C80
// Name: Prototype_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Prototype_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Prototype_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064C90
// Name: Prototype_dx9::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
Prototype_dx9::CShaderParam *Prototype_dx9::_dynamic_initializer_for__BUMPMAP__()
{
  return Prototype_dx9::CShaderParam::CShaderParam(
           this: &BUMPMAP_5,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064CB0
// Name: Prototype_dx9::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
Prototype_dx9::CShaderParam *Prototype_dx9::_dynamic_initializer_for__BUMPFRAME__()
{
  return Prototype_dx9::CShaderParam::CShaderParam(
           this: &BUMPFRAME_9,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064CD0
// Name: Prototype_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Prototype_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_86);
  s_ShaderInstance_86.__vftable = (Prototype_dx9::CShader_vtbl *)&Prototype_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B5D0
// Name: Prototype::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Prototype::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_87);
}

//------------------------------------------------------------------------------
// Address: 0x1006B5E0
// Name: Prototype_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Prototype_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_86);
}

//------------------------------------------------------------------------------
// Address: 0x10064CF0
// Name: _dynamic_initializer_for__s_ConstructMe_prototype_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_prototype_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &prototype_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064D10
// Name: _dynamic_initializer_for__s_ConstructMe_prototype_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_prototype_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &prototype_ps20b_combos);
}
