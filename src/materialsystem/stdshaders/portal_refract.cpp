// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/portal_refract.cpp
// Functions: 38
// ============================================================

#include "materialsystem\stdshaders\portal_refract.h"

//------------------------------------------------------------------------------
// Address: 0x10026B00
// Name: public: virtual char const __near * PortalRefract::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall PortalRefract::CShader::GetFallbackShader(PortalRefract::CShader *this, IMaterialVar **params)
{
  return "PortalRefract_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x10026B10
// Name: public: virtual char const __near * PortalRefract::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall PortalRefract::CShader::GetName(PortalRefract::CShader *this)
{
  return s_Name_79;
}

//------------------------------------------------------------------------------
// Address: 0x10026B20
// Name: public: virtual int PortalRefract::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall PortalRefract::CShader::GetFlags(PortalRefract::CShader *this)
{
  return s_nFlags_96;
}

//------------------------------------------------------------------------------
// Address: 0x10026B30
// Name: public: virtual int PortalRefract::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall PortalRefract::CShader::GetParamCount(PortalRefract::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_80.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10026B40
// Name: public: void PortalRefract_dx9::CShader::SetupVarsPortalRefract(struct PortalRefractVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PortalRefract_dx9::CShader::SetupVarsPortalRefract(
        PortalRefract_dx9::CShader *this,
        PortalRefractVars_t *info)
{
  info->m_nStage = STAGE.m_Index;
  info->m_nPortalOpenAmount = PORTALOPENAMOUNT.m_Index;
  info->m_nPortalStatic = PORTALSTATIC.m_Index;
  info->m_nPortalMaskTexture = PORTALMASKTEXTURE.m_Index;
  info->m_nTextureTransform = TEXTURETRANSFORM.m_Index;
  info->m_nPortalColorTexture = PORTALCOLORTEXTURE.m_Index;
  info->m_nPortalColorGradientDark = PORTALCOLORGRADIENTDARK.m_Index;
  info->m_nPortalColorGradientLight = PORTALCOLORGRADIENTLIGHT.m_Index;
  info->m_nPortalColorScale = PORTALCOLORSCALE.m_Index;
  info->m_nTime = TIME_1.m_Index;
  info->m_nUseOnStaticProp = USEONSTATICPROP.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10026BB0
// Name: public: virtual bool PortalRefract_dx9::CShader::NeedsPowerOfTwoFrameBufferTexture(class IMaterialVar __near * __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PortalRefract_dx9::CShader::NeedsPowerOfTwoFrameBufferTexture(
        PortalRefract_dx9::CShader *this,
        IMaterialVar **params,
        bool bCheckSpecificToThisFrame)
{
  return !bCheckSpecificToThisFrame || params[STAGE.m_Index]->m_intVal == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10026BE0
// Name: public: virtual void PortalRefract_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PortalRefract_dx9::CShader::OnInitShaderParams(
        PortalRefract_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  PortalRefractVars_t info; // [esp+4h] [ebp-2Ch] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  PortalRefract_dx9::CShader::SetupVarsPortalRefract(this, &info);
  InitParamsPortalRefract(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10026C30
// Name: public: virtual char const __near * PortalRefract_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall PortalRefract_dx9::CShader::GetName(PortalRefract_dx9::CShader *this)
{
  return s_Name_80;
}

//------------------------------------------------------------------------------
// Address: 0x10026C40
// Name: public: virtual int PortalRefract_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall PortalRefract_dx9::CShader::GetFlags(PortalRefract_dx9::CShader *this)
{
  return s_nFlags_97;
}

//------------------------------------------------------------------------------
// Address: 0x10026C50
// Name: public: virtual void PortalRefract_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PortalRefract_dx9::CShader::OnInitShaderInstance(
        PortalRefract_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  PortalRefractVars_t info; // [esp+4h] [ebp-2Ch] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  PortalRefract_dx9::CShader::SetupVarsPortalRefract(this, &info);
  InitPortalRefract(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10026C90
// Name: public: virtual void PortalRefract_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PortalRefract_dx9::CShader::OnDrawElements(
        PortalRefract_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  char v7; // al
  float x; // xmm0_4
  PortalRefractVars_t info; // [esp+Ch] [ebp-2Ch] BYREF

  v7 = 1;
  if ( params[STAGE.m_Index]->m_intVal == 0 )
  {
    x = params[PORTALOPENAMOUNT.m_Index]->m_VecVal.x;
    if ( x <= 0.0 || x >= 1.0 )
      v7 = 0;
  }
  if ( pShaderShadow != nullptr || v7 == 1 )
  {
    memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
    PortalRefract_dx9::CShader::SetupVarsPortalRefract(this, &info);
    DrawPortalRefract(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
  }
  else
  {
    CBaseShader::Draw(this, bMakeActualDrawCall: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026D30
// Name: public: virtual int PortalRefract_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall PortalRefract_dx9::CShader::GetParamCount(PortalRefract_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_79.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10026D40
// Name: public: virtual struct ShaderParamInfo_t const __near & PortalRefract::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
PortalRefract::CShaderParam *__thiscall PortalRefract::CShader::GetParamInfo(PortalRefract::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_80.m_Memory.m_pMemory[param - ParamCount];
  else
    return (PortalRefract::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10026D70
// Name: public: virtual struct ShaderParamInfo_t const __near & PortalRefract_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *__thiscall PortalRefract_dx9::CShader::GetParamInfo(
        PortalRefract_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_79.m_Memory.m_pMemory[param - ParamCount];
  else
    return (PortalRefract_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10026DA0
// Name: public: PortalRefract_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *__thiscall PortalRefract_dx9::CShaderParam::CShaderParam(
        PortalRefract_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  PortalRefract_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  PortalRefract_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_79.m_Size + 13;
  m_Size = s_ShaderParams_79.m_Size;
  v8 = s_ShaderParams_79.m_Size;
  if ( s_ShaderParams_79.m_Size + 1 > s_ShaderParams_79.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_79,
      num: s_ShaderParams_79.m_Size - s_ShaderParams_79.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_79.m_Size;
  }
  m_pMemory = s_ShaderParams_79.m_Memory.m_pMemory;
  s_ShaderParams_79.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_79.m_pElements = s_ShaderParams_79.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_79.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_79.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_79.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10064680
// Name: PortalRefract::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int PortalRefract::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: PortalRefract::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064690
// Name: PortalRefract::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *PortalRefract::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_80);
  s_ShaderInstance_80.__vftable = (PortalRefract::CShader_vtbl *)&PortalRefract::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100646B0
// Name: PortalRefract_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int PortalRefract_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: PortalRefract_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100646C0
// Name: PortalRefract_dx9::_dynamic_initializer_for__STAGE__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__STAGE__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &STAGE,
           pName: "$STAGE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Stage of portal rendering (0, 1, 2)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100646E0
// Name: PortalRefract_dx9::_dynamic_initializer_for__PORTALOPENAMOUNT__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__PORTALOPENAMOUNT__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &PORTALOPENAMOUNT,
           pName: "$PORTALOPENAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Portal open amount 0.0-1.0",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064700
// Name: PortalRefract_dx9::_dynamic_initializer_for__PORTALSTATIC__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__PORTALSTATIC__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &PORTALSTATIC,
           pName: "$PORTALSTATIC",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Portal static amount 0.0-1.0",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064720
// Name: PortalRefract_dx9::_dynamic_initializer_for__PORTALMASKTEXTURE__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__PORTALMASKTEXTURE__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &PORTALMASKTEXTURE,
           pName: "$PORTALMASKTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Mask texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064740
// Name: PortalRefract_dx9::_dynamic_initializer_for__TEXTURETRANSFORM__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__TEXTURETRANSFORM__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &TEXTURETRANSFORM,
           pName: "$TEXTURETRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "Texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064760
// Name: PortalRefract_dx9::_dynamic_initializer_for__PORTALCOLORTEXTURE__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__PORTALCOLORTEXTURE__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &PORTALCOLORTEXTURE,
           pName: "$PORTALCOLORTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Color texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064780
// Name: PortalRefract_dx9::_dynamic_initializer_for__PORTALCOLORGRADIENTDARK__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__PORTALCOLORGRADIENTDARK__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &PORTALCOLORGRADIENTDARK,
           pName: "$PORTALCOLORGRADIENTDARK",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[0.0 0.0 0.0]",
           pHelp: "The dark end of a tint gradient if not using a color texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100647A0
// Name: PortalRefract_dx9::_dynamic_initializer_for__PORTALCOLORGRADIENTLIGHT__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__PORTALCOLORGRADIENTLIGHT__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &PORTALCOLORGRADIENTLIGHT,
           pName: "$PORTALCOLORGRADIENTLIGHT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1.0 1.0 1.0]",
           pHelp: "The light end of a tint gradient if not using a color texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100647C0
// Name: PortalRefract_dx9::_dynamic_initializer_for__PORTALCOLORSCALE__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__PORTALCOLORSCALE__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &PORTALCOLORSCALE,
           pName: "$PORTALCOLORSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Portal color scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100647E0
// Name: PortalRefract_dx9::_dynamic_initializer_for__TIME__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__TIME__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &TIME_1,
           pName: "$TIME",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Needs CurrentTime Proxy",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064800
// Name: PortalRefract_dx9::_dynamic_initializer_for__USEONSTATICPROP__
// Source: json
//------------------------------------------------------------------------------
PortalRefract_dx9::CShaderParam *PortalRefract_dx9::_dynamic_initializer_for__USEONSTATICPROP__()
{
  return PortalRefract_dx9::CShaderParam::CShaderParam(
           this: &USEONSTATICPROP,
           pName: "$USEONSTATICPROP",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Activate special mode to use this shader on a static prop",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064820
// Name: PortalRefract_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *PortalRefract_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_79);
  s_ShaderInstance_79.__vftable = (PortalRefract_dx9::CShader_vtbl *)&PortalRefract_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B560
// Name: PortalRefract::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl PortalRefract::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_80);
}

//------------------------------------------------------------------------------
// Address: 0x1006B570
// Name: PortalRefract_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl PortalRefract_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_79);
}

//------------------------------------------------------------------------------
// Address: 0x10064840
// Name: _dynamic_initializer_for__s_ConstructMe_portal_refract_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_portal_refract_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &portal_refract_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064860
// Name: _dynamic_initializer_for__s_ConstructMe_portal_refract_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_portal_refract_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &portal_refract_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064880
// Name: _dynamic_initializer_for__s_ConstructMe_portal_refract_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_portal_refract_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &portal_refract_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100648A0
// Name: _dynamic_initializer_for__s_ConstructMe_portalstaticoverlay_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_portalstaticoverlay_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &portalstaticoverlay_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100648C0
// Name: _dynamic_initializer_for__s_ConstructMe_portalstaticoverlay_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_portalstaticoverlay_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &portalstaticoverlay_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100648E0
// Name: _dynamic_initializer_for__s_ConstructMe_portalstaticoverlay_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_portalstaticoverlay_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &portalstaticoverlay_ps20b_combos);
}
