// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/aftershock.cpp
// Functions: 47
// ============================================================

#include "materialsystem\stdshaders\aftershock.h"

//------------------------------------------------------------------------------
// Address: 0x100016D0
// Name: public: virtual char const __near * Aftershock::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Aftershock::CShader::GetFallbackShader(Aftershock::CShader *this, IMaterialVar **params)
{
  return "Aftershock_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x100016E0
// Name: public: virtual char const __near * Aftershock::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Aftershock::CShader::GetName(Aftershock::CShader *this)
{
  return s_Name_1;
}

//------------------------------------------------------------------------------
// Address: 0x100016F0
// Name: public: virtual int Aftershock::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Aftershock::CShader::GetFlags(Aftershock::CShader *this)
{
  return s_nFlags_46;
}

//------------------------------------------------------------------------------
// Address: 0x10001700
// Name: public: virtual int Aftershock::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Aftershock::CShader::GetParamCount(Aftershock::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_1.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001710
// Name: public: void Aftershock_dx9::CShader::SetupVarsAftershock(struct AftershockVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Aftershock_dx9::CShader::SetupVarsAftershock(Aftershock_dx9::CShader *this, AftershockVars_t *info)
{
  info->m_nColorTint = COLORTINT.m_Index;
  info->m_nRefractAmount = REFRACTAMOUNT.m_Index;
  info->m_nBumpmap = NORMALMAP.m_Index;
  info->m_nBumpFrame = BUMPFRAME.m_Index;
  info->m_nBumpTransform = BUMPTRANSFORM.m_Index;
  info->m_nSilhouetteThickness = SILHOUETTETHICKNESS.m_Index;
  info->m_nSilhouetteColor = SILHOUETTECOLOR.m_Index;
  info->m_nGroundMin = GROUNDMIN.m_Index;
  info->m_nGroundMax = GROUNDMAX.m_Index;
  info->m_nBlurAmount = BLURAMOUNT.m_Index;
  info->m_nTime = TIME.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10001780
// Name: public: virtual void Aftershock_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Aftershock_dx9::CShader::OnInitShaderParams(
        Aftershock_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  AftershockVars_t info; // [esp+4h] [ebp-2Ch] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Aftershock_dx9::CShader::SetupVarsAftershock(this, &info);
  InitParamsAftershock(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x100017D0
// Name: public: virtual char const __near * Aftershock_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Aftershock_dx9::CShader::GetName(Aftershock_dx9::CShader *this)
{
  return s_Name_2;
}

//------------------------------------------------------------------------------
// Address: 0x100017E0
// Name: public: virtual int Aftershock_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Aftershock_dx9::CShader::GetFlags(Aftershock_dx9::CShader *this)
{
  return s_nFlags_47;
}

//------------------------------------------------------------------------------
// Address: 0x100017F0
// Name: public: virtual void Aftershock_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Aftershock_dx9::CShader::OnInitShaderInstance(
        Aftershock_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  AftershockVars_t info; // [esp+4h] [ebp-2Ch] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Aftershock_dx9::CShader::SetupVarsAftershock(this, &info);
  InitAftershock(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10001830
// Name: public: virtual void Aftershock_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Aftershock_dx9::CShader::OnDrawElements(
        Aftershock_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  AftershockVars_t info; // [esp+4h] [ebp-2Ch] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Aftershock_dx9::CShader::SetupVarsAftershock(this, &info);
  DrawAftershock(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10001880
// Name: public: virtual int Aftershock_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Aftershock_dx9::CShader::GetParamCount(Aftershock_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_2.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: public: virtual struct ShaderParamInfo_t const __near & Aftershock::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Aftershock::CShaderParam *__thiscall Aftershock::CShader::GetParamInfo(Aftershock::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_1.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Aftershock::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100018C0
// Name: public: virtual struct ShaderParamInfo_t const __near & Aftershock_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *__thiscall Aftershock_dx9::CShader::GetParamInfo(
        Aftershock_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_2.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Aftershock_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100018F0
// Name: public: Aftershock_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *__thiscall Aftershock_dx9::CShaderParam::CShaderParam(
        Aftershock_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Aftershock_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Aftershock_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_2.m_Size + 13;
  m_Size = s_ShaderParams_2.m_Size;
  v8 = s_ShaderParams_2.m_Size;
  if ( s_ShaderParams_2.m_Size + 1 > s_ShaderParams_2.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_2,
      num: s_ShaderParams_2.m_Size - s_ShaderParams_2.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_2.m_Size;
  }
  m_pMemory = s_ShaderParams_2.m_Memory.m_pMemory;
  s_ShaderParams_2.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_2.m_pElements = s_ShaderParams_2.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_2.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_2.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_2.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005DFC0
// Name: Aftershock::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Aftershock::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Aftershock::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005DFD0
// Name: Aftershock::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Aftershock::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_1);
  s_ShaderInstance_1.__vftable = (Aftershock::CShader_vtbl *)&Aftershock::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005DFF0
// Name: Aftershock_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Aftershock_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Aftershock_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005E000
// Name: Aftershock_dx9::_dynamic_initializer_for__COLORTINT__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__COLORTINT__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &COLORTINT,
           pName: "$COLORTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Color tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E020
// Name: Aftershock_dx9::_dynamic_initializer_for__REFRACTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__REFRACTAMOUNT__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &REFRACTAMOUNT,
           pName: "$REFRACTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E040
// Name: Aftershock_dx9::_dynamic_initializer_for__NORMALMAP__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__NORMALMAP__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &NORMALMAP,
           pName: "$NORMALMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E060
// Name: Aftershock_dx9::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__BUMPFRAME__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &BUMPFRAME,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E080
// Name: Aftershock_dx9::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E0A0
// Name: Aftershock_dx9::_dynamic_initializer_for__SILHOUETTETHICKNESS__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__SILHOUETTETHICKNESS__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &SILHOUETTETHICKNESS,
           pName: "$SILHOUETTETHICKNESS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E0C0
// Name: Aftershock_dx9::_dynamic_initializer_for__SILHOUETTECOLOR__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__SILHOUETTECOLOR__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &SILHOUETTECOLOR,
           pName: "$SILHOUETTECOLOR",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Silhouette color tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E0E0
// Name: Aftershock_dx9::_dynamic_initializer_for__GROUNDMIN__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__GROUNDMIN__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &GROUNDMIN,
           pName: "$GROUNDMIN",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E100
// Name: Aftershock_dx9::_dynamic_initializer_for__GROUNDMAX__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__GROUNDMAX__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &GROUNDMAX,
           pName: "$GROUNDMAX",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E120
// Name: Aftershock_dx9::_dynamic_initializer_for__BLURAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__BLURAMOUNT__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &BLURAMOUNT,
           pName: "$BLURAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E140
// Name: Aftershock_dx9::_dynamic_initializer_for__TIME__
// Source: json
//------------------------------------------------------------------------------
Aftershock_dx9::CShaderParam *Aftershock_dx9::_dynamic_initializer_for__TIME__()
{
  return Aftershock_dx9::CShaderParam::CShaderParam(
           this: &TIME,
           pName: "$TIME",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Needs CurrentTime Proxy",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E160
// Name: Aftershock_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Aftershock_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_2);
  s_ShaderInstance_2.__vftable = (Aftershock_dx9::CShader_vtbl *)&Aftershock_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AE60
// Name: Aftershock::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Aftershock::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_1);
}

//------------------------------------------------------------------------------
// Address: 0x1006AE70
// Name: Aftershock_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Aftershock_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_2);
}

//------------------------------------------------------------------------------
// Address: 0x1005E180
// Name: _dynamic_initializer_for__s_ConstructMe_aftershock_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_aftershock_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &aftershock_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E1A0
// Name: _dynamic_initializer_for__s_ConstructMe_aftershock_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_aftershock_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &aftershock_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E1C0
// Name: _dynamic_initializer_for__s_ConstructMe_aftershock_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_aftershock_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &aftershock_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E1E0
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_flashlight_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_flashlight_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedgeneric_flashlight_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E200
// Name: _dynamic_initializer_for__s_ConstructMe_flashlight_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_flashlight_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &flashlight_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E220
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_flashlight_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_flashlight_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedgeneric_flashlight_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E240
// Name: _dynamic_initializer_for__s_ConstructMe_flashlight_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_flashlight_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &flashlight_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E260
// Name: _dynamic_initializer_for__s_ConstructMe_flashlight_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_flashlight_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &flashlight_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E280
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlitgeneric_flashlight_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlitgeneric_flashlight_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlitgeneric_flashlight_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E2A0
// Name: _dynamic_initializer_for__r_flashlightbrightness__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightbrightness__()
{
  ConVar::ConVar(this: &r_flashlightbrightness, pName: "r_flashlightbrightness", pDefaultValue: "0.25", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightbrightness__);
}

//------------------------------------------------------------------------------
// Address: 0x1005E2D0
// Name: _dynamic_initializer_for__r_emulategl__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_emulategl__()
{
  ConVar::ConVar(this: &r_emulategl, pName: "r_emulategl", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_emulategl__);
}

//------------------------------------------------------------------------------
// Address: 0x1005E300
// Name: _dynamic_initializer_for__s_ConstructMe_bik_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_bik_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &bik_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E320
// Name: _dynamic_initializer_for__s_ConstructMe_bik_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_bik_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &bik_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E340
// Name: _dynamic_initializer_for__s_ConstructMe_bik_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_bik_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &bik_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006AE80
// Name: _dynamic_atexit_destructor_for__r_flashlightbrightness__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightbrightness__()
{
  ConVar::~ConVar(this: &r_flashlightbrightness);
}

//------------------------------------------------------------------------------
// Address: 0x1006AE90
// Name: _dynamic_atexit_destructor_for__r_emulategl__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_emulategl__()
{
  ConVar::~ConVar(this: &r_emulategl);
}
