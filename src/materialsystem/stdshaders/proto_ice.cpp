// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/proto_ice.cpp
// Functions: 25
// ============================================================

#include "materialsystem\stdshaders\proto_ice.h"

//------------------------------------------------------------------------------
// Address: 0x10028660
// Name: public: virtual char const __near * ProtoIce::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ProtoIce::CShader::GetFallbackShader(ProtoIce::CShader *this, IMaterialVar **params)
{
  return "ProtoIce_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x10028670
// Name: public: virtual char const __near * ProtoIce::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ProtoIce::CShader::GetName(ProtoIce::CShader *this)
{
  return s_Name_84;
}

//------------------------------------------------------------------------------
// Address: 0x10028680
// Name: public: virtual int ProtoIce::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ProtoIce::CShader::GetFlags(ProtoIce::CShader *this)
{
  return s_nFlags_101;
}

//------------------------------------------------------------------------------
// Address: 0x10028690
// Name: public: virtual int ProtoIce::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ProtoIce::CShader::GetParamCount(ProtoIce::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_84.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100286A0
// Name: public: virtual void ProtoIce_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ProtoIce_dx9::CShader::OnInitShaderParams(
        ProtoIce_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ProtoIceVars_t info; // [esp+0h] [ebp-14h] BYREF

  info.m_nBumpmap = BUMPMAP_4.m_Index;
  info.m_nBumpFrame = BUMPFRAME_8.m_Index;
  info.m_nSsBump = SSBUMP_0.m_Index;
  info.m_nBaseTexture = 6;
  info.m_nBaseTextureFrame = 7;
  InitParamsProtoIce(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10028700
// Name: public: virtual char const __near * ProtoIce_dx9::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ProtoIce_dx9::CShader::GetFallbackShader(ProtoIce_dx9::CShader *this, IMaterialVar **params)
{
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 90
    || g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
  {
    return "Wireframe";
  }
  if ( g_pConfig != nullptr && g_pConfig->bEditMode )
    return "VertexLitGeneric";
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10028750
// Name: public: virtual char const __near * ProtoIce_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ProtoIce_dx9::CShader::GetName(ProtoIce_dx9::CShader *this)
{
  return s_Name_85;
}

//------------------------------------------------------------------------------
// Address: 0x10028760
// Name: public: virtual int ProtoIce_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ProtoIce_dx9::CShader::GetFlags(ProtoIce_dx9::CShader *this)
{
  return s_nFlags_102;
}

//------------------------------------------------------------------------------
// Address: 0x10028770
// Name: public: virtual void ProtoIce_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ProtoIce_dx9::CShader::OnInitShaderInstance(
        ProtoIce_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  ProtoIceVars_t info; // [esp+0h] [ebp-14h] BYREF

  info.m_nBumpmap = BUMPMAP_4.m_Index;
  info.m_nBumpFrame = BUMPFRAME_8.m_Index;
  info.m_nSsBump = SSBUMP_0.m_Index;
  info.m_nBaseTexture = 6;
  info.m_nBaseTextureFrame = 7;
  InitPrototype(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x100287D0
// Name: public: virtual void ProtoIce_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ProtoIce_dx9::CShader::OnDrawElements(
        ProtoIce_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  ProtoIceVars_t info; // [esp+0h] [ebp-14h] BYREF

  info.m_nBumpmap = BUMPMAP_4.m_Index;
  info.m_nBumpFrame = BUMPFRAME_8.m_Index;
  info.m_nSsBump = SSBUMP_0.m_Index;
  info.m_nBaseTexture = 6;
  info.m_nBaseTextureFrame = 7;
  DrawProtoIce(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10028840
// Name: public: virtual int ProtoIce_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ProtoIce_dx9::CShader::GetParamCount(ProtoIce_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_85.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10028850
// Name: public: virtual struct ShaderParamInfo_t const __near & ProtoIce::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ProtoIce::CShaderParam *__thiscall ProtoIce::CShader::GetParamInfo(ProtoIce::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_84.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ProtoIce::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10028880
// Name: public: virtual struct ShaderParamInfo_t const __near & ProtoIce_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ProtoIce_dx9::CShaderParam *__thiscall ProtoIce_dx9::CShader::GetParamInfo(ProtoIce_dx9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_85.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ProtoIce_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100288B0
// Name: public: ProtoIce_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ProtoIce_dx9::CShaderParam *__thiscall ProtoIce_dx9::CShaderParam::CShaderParam(
        ProtoIce_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  ProtoIce_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  ProtoIce_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_85.m_Size + 13;
  m_Size = s_ShaderParams_85.m_Size;
  v8 = s_ShaderParams_85.m_Size;
  if ( s_ShaderParams_85.m_Size + 1 > s_ShaderParams_85.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_85,
      num: s_ShaderParams_85.m_Size - s_ShaderParams_85.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_85.m_Size;
  }
  m_pMemory = s_ShaderParams_85.m_Memory.m_pMemory;
  s_ShaderParams_85.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_85.m_pElements = s_ShaderParams_85.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_85.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_85.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_85.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10064B50
// Name: ProtoIce::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ProtoIce::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ProtoIce::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064B60
// Name: ProtoIce::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ProtoIce::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_84);
  s_ShaderInstance_84.__vftable = (ProtoIce::CShader_vtbl *)&ProtoIce::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064B80
// Name: ProtoIce_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ProtoIce_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ProtoIce_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064B90
// Name: ProtoIce_dx9::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
ProtoIce_dx9::CShaderParam *ProtoIce_dx9::_dynamic_initializer_for__BUMPMAP__()
{
  return ProtoIce_dx9::CShaderParam::CShaderParam(
           this: &BUMPMAP_4,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064BB0
// Name: ProtoIce_dx9::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
ProtoIce_dx9::CShaderParam *ProtoIce_dx9::_dynamic_initializer_for__BUMPFRAME__()
{
  return ProtoIce_dx9::CShaderParam::CShaderParam(
           this: &BUMPFRAME_8,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064BD0
// Name: ProtoIce_dx9::_dynamic_initializer_for__SSBUMP__
// Source: json
//------------------------------------------------------------------------------
ProtoIce_dx9::CShaderParam *ProtoIce_dx9::_dynamic_initializer_for__SSBUMP__()
{
  return ProtoIce_dx9::CShaderParam::CShaderParam(
           this: &SSBUMP_0,
           pName: "$SSBUMP",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "whether or not to use alternate bumpmap format with height",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064BF0
// Name: ProtoIce_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ProtoIce_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_85);
  s_ShaderInstance_85.__vftable = (ProtoIce_dx9::CShader_vtbl *)&ProtoIce_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B5B0
// Name: ProtoIce::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProtoIce::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_84);
}

//------------------------------------------------------------------------------
// Address: 0x1006B5C0
// Name: ProtoIce_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProtoIce_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_85);
}

//------------------------------------------------------------------------------
// Address: 0x10064C10
// Name: _dynamic_initializer_for__s_ConstructMe_proto_ice_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_proto_ice_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &proto_ice_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064C30
// Name: _dynamic_initializer_for__s_ConstructMe_proto_ice_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_proto_ice_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &proto_ice_ps20b_combos);
}
