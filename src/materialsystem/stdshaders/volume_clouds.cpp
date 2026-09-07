// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/volume_clouds.cpp
// Functions: 32
// ============================================================

#include "materialsystem\stdshaders\volume_clouds.h"

//------------------------------------------------------------------------------
// Address: 0x1003FF30
// Name: public: virtual char const __near * VolumeClouds::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall VolumeClouds::CShader::GetFallbackShader(VolumeClouds::CShader *this, IMaterialVar **params)
{
  return "VolumeClouds_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x1003FF40
// Name: public: virtual char const __near * VolumeClouds::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall VolumeClouds::CShader::GetName(VolumeClouds::CShader *this)
{
  return s_Name_123;
}

//------------------------------------------------------------------------------
// Address: 0x1003FF50
// Name: public: virtual int VolumeClouds::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall VolumeClouds::CShader::GetFlags(VolumeClouds::CShader *this)
{
  return s_nFlags_125;
}

//------------------------------------------------------------------------------
// Address: 0x1003FF60
// Name: public: virtual int VolumeClouds::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall VolumeClouds::CShader::GetParamCount(VolumeClouds::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_124.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003FF70
// Name: public: virtual void VolumeClouds_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VolumeClouds_dx9::CShader::OnInitShaderParams(
        VolumeClouds_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  VolumeCloudsVars_t info; // [esp+0h] [ebp-14h] BYREF

  info.m_nRefractAmount = REFRACTAMOUNT_7.m_Index;
  info.m_nTexture1 = BASETEXTURE_3.m_Index;
  info.m_nTexture2 = BASETEXTURE2_1.m_Index;
  info.m_nTexture3 = BASETEXTURE3_0.m_Index;
  info.m_nTime = TIME_5.m_Index;
  InitParamsVolumeClouds(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x1003FFD0
// Name: public: virtual char const __near * VolumeClouds_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall VolumeClouds_dx9::CShader::GetName(VolumeClouds_dx9::CShader *this)
{
  return s_Name_124;
}

//------------------------------------------------------------------------------
// Address: 0x1003FFE0
// Name: public: virtual int VolumeClouds_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall VolumeClouds_dx9::CShader::GetFlags(VolumeClouds_dx9::CShader *this)
{
  return s_nFlags_126;
}

//------------------------------------------------------------------------------
// Address: 0x1003FFF0
// Name: public: virtual void VolumeClouds_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VolumeClouds_dx9::CShader::OnInitShaderInstance(
        VolumeClouds_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  VolumeCloudsVars_t info; // [esp+0h] [ebp-14h] BYREF

  info.m_nRefractAmount = REFRACTAMOUNT_7.m_Index;
  info.m_nTexture1 = BASETEXTURE_3.m_Index;
  info.m_nTexture2 = BASETEXTURE2_1.m_Index;
  info.m_nTexture3 = BASETEXTURE3_0.m_Index;
  info.m_nTime = TIME_5.m_Index;
  InitVolumeClouds(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10040050
// Name: public: virtual void VolumeClouds_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VolumeClouds_dx9::CShader::OnDrawElements(
        VolumeClouds_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  VolumeCloudsVars_t info; // [esp+0h] [ebp-14h] BYREF

  info.m_nRefractAmount = REFRACTAMOUNT_7.m_Index;
  info.m_nTexture1 = BASETEXTURE_3.m_Index;
  info.m_nTexture2 = BASETEXTURE2_1.m_Index;
  info.m_nTexture3 = BASETEXTURE3_0.m_Index;
  info.m_nTime = TIME_5.m_Index;
  DrawVolumeClouds(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x100400C0
// Name: public: virtual int VolumeClouds_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall VolumeClouds_dx9::CShader::GetParamCount(VolumeClouds_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_123.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100400D0
// Name: public: virtual struct ShaderParamInfo_t const __near & VolumeClouds::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
VolumeClouds::CShaderParam *__thiscall VolumeClouds::CShader::GetParamInfo(VolumeClouds::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_124.m_Memory.m_pMemory[param - ParamCount];
  else
    return (VolumeClouds::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10040100
// Name: public: virtual struct ShaderParamInfo_t const __near & VolumeClouds_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
VolumeClouds_dx9::CShaderParam *__thiscall VolumeClouds_dx9::CShader::GetParamInfo(
        VolumeClouds_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_123.m_Memory.m_pMemory[param - ParamCount];
  else
    return (VolumeClouds_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10040130
// Name: public: VolumeClouds_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
VolumeClouds_dx9::CShaderParam *__thiscall VolumeClouds_dx9::CShaderParam::CShaderParam(
        VolumeClouds_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  VolumeClouds_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  VolumeClouds_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_123.m_Size + 13;
  m_Size = s_ShaderParams_123.m_Size;
  v8 = s_ShaderParams_123.m_Size;
  if ( s_ShaderParams_123.m_Size + 1 > s_ShaderParams_123.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_123,
      num: s_ShaderParams_123.m_Size - s_ShaderParams_123.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_123.m_Size;
  }
  m_pMemory = s_ShaderParams_123.m_Memory.m_pMemory;
  s_ShaderParams_123.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_123.m_pElements = s_ShaderParams_123.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_123.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_123.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_123.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10069560
// Name: VolumeClouds::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int VolumeClouds::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: VolumeClouds::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10069570
// Name: VolumeClouds::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *VolumeClouds::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_124);
  s_ShaderInstance_124.__vftable = (VolumeClouds::CShader_vtbl *)&VolumeClouds::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10069590
// Name: VolumeClouds_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int VolumeClouds_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: VolumeClouds_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100695A0
// Name: VolumeClouds_dx9::_dynamic_initializer_for__REFRACTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
VolumeClouds_dx9::CShaderParam *VolumeClouds_dx9::_dynamic_initializer_for__REFRACTAMOUNT__()
{
  return VolumeClouds_dx9::CShaderParam::CShaderParam(
           this: &REFRACTAMOUNT_7,
           pName: "$REFRACTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100695C0
// Name: VolumeClouds_dx9::_dynamic_initializer_for__BASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
VolumeClouds_dx9::CShaderParam *VolumeClouds_dx9::_dynamic_initializer_for__BASETEXTURE__()
{
  return VolumeClouds_dx9::CShaderParam::CShaderParam(
           this: &BASETEXTURE_3,
           pName: "$BASETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Texture 1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100695E0
// Name: VolumeClouds_dx9::_dynamic_initializer_for__BASETEXTURE2__
// Source: json
//------------------------------------------------------------------------------
VolumeClouds_dx9::CShaderParam *VolumeClouds_dx9::_dynamic_initializer_for__BASETEXTURE2__()
{
  return VolumeClouds_dx9::CShaderParam::CShaderParam(
           this: &BASETEXTURE2_1,
           pName: "$BASETEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Texture 2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069600
// Name: VolumeClouds_dx9::_dynamic_initializer_for__BASETEXTURE3__
// Source: json
//------------------------------------------------------------------------------
VolumeClouds_dx9::CShaderParam *VolumeClouds_dx9::_dynamic_initializer_for__BASETEXTURE3__()
{
  return VolumeClouds_dx9::CShaderParam::CShaderParam(
           this: &BASETEXTURE3_0,
           pName: "$BASETEXTURE3",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Texture 3",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069620
// Name: VolumeClouds_dx9::_dynamic_initializer_for__TIME__
// Source: json
//------------------------------------------------------------------------------
VolumeClouds_dx9::CShaderParam *VolumeClouds_dx9::_dynamic_initializer_for__TIME__()
{
  return VolumeClouds_dx9::CShaderParam::CShaderParam(
           this: &TIME_5,
           pName: "$TIME",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Needs CurrentTime Proxy",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069640
// Name: VolumeClouds_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *VolumeClouds_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_123);
  s_ShaderInstance_123.__vftable = (VolumeClouds_dx9::CShader_vtbl *)&VolumeClouds_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B8B0
// Name: VolumeClouds::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl VolumeClouds::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_124);
}

//------------------------------------------------------------------------------
// Address: 0x1006B8C0
// Name: VolumeClouds_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl VolumeClouds_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_123);
}

//------------------------------------------------------------------------------
// Address: 0x10069660
// Name: _dynamic_initializer_for__s_ConstructMe_volume_clouds_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_volume_clouds_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &volume_clouds_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069680
// Name: _dynamic_initializer_for__s_ConstructMe_volume_clouds_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_volume_clouds_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &volume_clouds_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100696A0
// Name: _dynamic_initializer_for__s_ConstructMe_volume_clouds_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_volume_clouds_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &volume_clouds_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100696C0
// Name: _dynamic_initializer_for__s_ConstructMe_vortwarp_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vortwarp_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vortwarp_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100696E0
// Name: _dynamic_initializer_for__s_ConstructMe_vortwarp_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vortwarp_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vortwarp_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069700
// Name: _dynamic_initializer_for__s_ConstructMe_vortwarp_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vortwarp_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vortwarp_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069720
// Name: _dynamic_initializer_for__s_ConstructMe_vortwarp_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vortwarp_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vortwarp_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069740
// Name: _dynamic_initializer_for__s_ConstructMe_vortwarp_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vortwarp_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vortwarp_ps30_combos);
}
