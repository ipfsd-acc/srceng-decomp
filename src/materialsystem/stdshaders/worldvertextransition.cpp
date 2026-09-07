// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/worldvertextransition.cpp
// Functions: 54
// ============================================================

#include "materialsystem\stdshaders\worldvertextransition.h"

//------------------------------------------------------------------------------
// Address: 0x10046AC0
// Name: public: void CUtlMemory<class ParticleSphere_DX9::CShaderParam __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
        CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Realloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: m_pMemory,
                                                                             a3: v7);
    else
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Alloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046C20
// Name: public: virtual char const __near * WorldVertexTransition::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WorldVertexTransition::CShader::GetFallbackShader(
        WorldVertexTransition::CShader *this,
        IMaterialVar **params)
{
  return "WorldVertexTransition_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x10046C30
// Name: public: virtual char const __near * WorldVertexTransition::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WorldVertexTransition::CShader::GetName(WorldVertexTransition::CShader *this)
{
  return s_Name_136;
}

//------------------------------------------------------------------------------
// Address: 0x10046C40
// Name: public: virtual int WorldVertexTransition::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WorldVertexTransition::CShader::GetFlags(WorldVertexTransition::CShader *this)
{
  return s_nFlags_138;
}

//------------------------------------------------------------------------------
// Address: 0x10046C50
// Name: public: virtual int WorldVertexTransition::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WorldVertexTransition::CShader::GetParamCount(WorldVertexTransition::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_135.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10046C60
// Name: public: void WorldVertexTransition_DX9::CShader::SetupVars(struct LightmappedGeneric_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WorldVertexTransition_DX9::CShader::SetupVars(
        WorldVertexTransition_DX9::CShader *this,
        LightmappedGeneric_DX9_Vars_t *info)
{
  info->m_nBaseTexture = 6;
  info->m_nBaseTextureFrame = 7;
  info->m_nBaseTextureTransform = 8;
  info->m_nSelfIllumTint = SELFILLUMTINT_4.m_Index;
  info->m_nDetail = DETAIL_5.m_Index;
  info->m_nDetailFrame = DETAILFRAME_4.m_Index;
  info->m_nDetailScale = DETAILSCALE_5.m_Index;
  info->m_nDetailTextureCombineMode = DETAILBLENDMODE_2.m_Index;
  info->m_nDetailTextureBlendFactor = DETAILBLENDFACTOR_2.m_Index;
  info->m_nDetailTint = DETAILTINT_1.m_Index;
  info->m_nEnvmap = ENVMAP_10.m_Index;
  info->m_nEnvmapFrame = ENVMAPFRAME_6.m_Index;
  info->m_nEnvmapMask = ENVMAPMASK_5.m_Index;
  info->m_nEnvmapMaskFrame = ENVMAPMASKFRAME_5.m_Index;
  info->m_nEnvmapMaskTransform = ENVMAPMASKTRANSFORM_4.m_Index;
  info->m_nEnvmapTint = ENVMAPTINT_6.m_Index;
  info->m_nBumpmap = BUMPMAP_11.m_Index;
  info->m_nBumpFrame = BUMPFRAME_15.m_Index;
  info->m_nBumpTransform = BUMPTRANSFORM_9.m_Index;
  info->m_nEnvmapContrast = ENVMAPCONTRAST_5.m_Index;
  info->m_nEnvmapSaturation = ENVMAPSATURATION_5.m_Index;
  info->m_nFresnelReflection = FRESNELREFLECTION_3.m_Index;
  info->m_nNoDiffuseBumpLighting = NODIFFUSEBUMPLIGHTING_1.m_Index;
  info->m_nBumpmap2 = BUMPMAP2_0.m_Index;
  info->m_nBumpFrame2 = BUMPFRAME2_1.m_Index;
  info->m_nBaseTexture2 = BASETEXTURE2_2.m_Index;
  info->m_nBaseTexture2Frame = FRAME2_2.m_Index;
  info->m_nBumpTransform2 = BUMPTRANSFORM2_1.m_Index;
  info->m_nBumpMask = BUMPMASK_0.m_Index;
  info->m_nFlashlightTexture = 9;
  info->m_nFlashlightTextureFrame = 10;
  info->m_nBlendModulateTexture = BLENDMODULATETEXTURE_0.m_Index;
  info->m_nSelfShadowedBumpFlag = SSBUMP_1.m_Index;
  info->m_nSeamlessMappingScale = SEAMLESS_SCALE_2.m_Index;
  info->m_nAlphaTestReference = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10046DB0
// Name: public: virtual void WorldVertexTransition_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge WorldVertexTransition_DX9::CShader::OnInitShaderParams(
        WorldVertexTransition_DX9::CShader *this@<ecx>,
        int a2@<ebx>,
        IMaterialVar **params,
        const char *pMaterialName)
{
  WorldVertexTransition_DX9::CShader::SetupVars(this, info: &s_info_0);
  InitParamsLightmappedGeneric_DX9(a1: a2, pShader: this, params, pMaterialName, info: &s_info_0);
}

//------------------------------------------------------------------------------
// Address: 0x10046DE0
// Name: public: virtual char const __near * WorldVertexTransition_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WorldVertexTransition_DX9::CShader::GetName(WorldVertexTransition_DX9::CShader *this)
{
  return s_Name_137;
}

//------------------------------------------------------------------------------
// Address: 0x10046DF0
// Name: public: virtual int WorldVertexTransition_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WorldVertexTransition_DX9::CShader::GetFlags(WorldVertexTransition_DX9::CShader *this)
{
  return s_nFlags_139;
}

//------------------------------------------------------------------------------
// Address: 0x10046E00
// Name: public: virtual void WorldVertexTransition_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WorldVertexTransition_DX9::CShader::OnInitShaderInstance(
        WorldVertexTransition_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  WorldVertexTransition_DX9::CShader::SetupVars(this, info: &s_info_0);
  InitLightmappedGeneric_DX9(pShader: this, params, info: &s_info_0);
}

//------------------------------------------------------------------------------
// Address: 0x10046E30
// Name: public: virtual void WorldVertexTransition_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WorldVertexTransition_DX9::CShader::OnDrawElements(
        WorldVertexTransition_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        ITexture *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  DrawLightmappedGeneric_DX9(pShader: this, params, pShaderAPI, pShaderShadow, info: &s_info_0, pContextDataPtr);
}

//------------------------------------------------------------------------------
// Address: 0x10046E60
// Name: public: virtual int WorldVertexTransition_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WorldVertexTransition_DX9::CShader::GetParamCount(WorldVertexTransition_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_136.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10046E70
// Name: public: virtual struct ShaderParamInfo_t const __near & WorldVertexTransition::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
WorldVertexTransition::CShaderParam *__thiscall WorldVertexTransition::CShader::GetParamInfo(
        WorldVertexTransition::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_135.m_Memory.m_pMemory[param - ParamCount];
  else
    return (WorldVertexTransition::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10046EA0
// Name: public: virtual struct ShaderParamInfo_t const __near & WorldVertexTransition_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *__thiscall WorldVertexTransition_DX9::CShader::GetParamInfo(
        WorldVertexTransition_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_136.m_Memory.m_pMemory[param - ParamCount];
  else
    return (WorldVertexTransition_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10046ED0
// Name: public: WorldVertexTransition_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *__thiscall WorldVertexTransition_DX9::CShaderParam::CShaderParam(
        WorldVertexTransition_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  WorldVertexTransition_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  WorldVertexTransition_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_136.m_Size + 13;
  m_Size = s_ShaderParams_136.m_Size;
  v8 = s_ShaderParams_136.m_Size;
  if ( s_ShaderParams_136.m_Size + 1 > s_ShaderParams_136.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_136,
      num: s_ShaderParams_136.m_Size - s_ShaderParams_136.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_136.m_Size;
  }
  m_pMemory = s_ShaderParams_136.m_Memory.m_pMemory;
  s_ShaderParams_136.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_136.m_pElements = s_ShaderParams_136.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_136.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_136.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_136.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10049520
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: m_pMemory,
                                                                                                a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A7F0
// Name: WorldVertexTransition::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int WorldVertexTransition::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: WorldVertexTransition::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006A800
// Name: WorldVertexTransition::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *WorldVertexTransition::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_136);
  s_ShaderInstance_136.__vftable = (WorldVertexTransition::CShader_vtbl *)&WorldVertexTransition::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006A820
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int WorldVertexTransition_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: WorldVertexTransition_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006A830
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__SELFILLUMTINT__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__SELFILLUMTINT__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &SELFILLUMTINT_4,
           pName: "$SELFILLUMTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Self-illumination tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A850
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__DETAIL__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__DETAIL__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &DETAIL_5,
           pName: "$DETAIL",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/detail",
           pHelp: "detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A870
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__DETAILFRAME__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__DETAILFRAME__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &DETAILFRAME_4,
           pName: "$DETAILFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $detail",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A890
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__DETAILSCALE__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__DETAILSCALE__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &DETAILSCALE_5,
           pName: "$DETAILSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "4",
           pHelp: "scale of the detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A8B0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__DETAILBLENDMODE__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__DETAILBLENDMODE__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &DETAILBLENDMODE_2,
           pName: "$DETAILBLENDMODE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "mode for combining detail texture with base. 0=normal, 1= additive, 2=alpha blend detail over base, 3=crossfade",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A8D0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__DETAILBLENDFACTOR__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__DETAILBLENDFACTOR__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &DETAILBLENDFACTOR_2,
           pName: "$DETAILBLENDFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "blend amount for detail texture.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A8F0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__DETAILTINT__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__DETAILTINT__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &DETAILTINT_1,
           pName: "$DETAILTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "detail texture tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A910
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAP__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &ENVMAP_10,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_env",
           pHelp: "envmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A930
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPFRAME__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPFRAME__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPFRAME_6,
           pName: "$ENVMAPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A950
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPMASK__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPMASK__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPMASK_5,
           pName: "$ENVMAPMASK",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_envmask",
           pHelp: "envmap mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A970
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPMASKFRAME__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPMASKFRAME__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPMASKFRAME_5,
           pName: "$ENVMAPMASKFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A990
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPMASKTRANSFORM_4,
           pName: "$ENVMAPMASKTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$envmapmask texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A9B0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPTINT__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPTINT__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPTINT_6,
           pName: "$ENVMAPTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "envmap tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A9D0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPMAP__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &BUMPMAP_11,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A9F0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPFRAME__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &BUMPFRAME_15,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AA10
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM_9,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AA30
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPCONTRAST__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPCONTRAST__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPCONTRAST_5,
           pName: "$ENVMAPCONTRAST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "contrast 0 == normal 1 == color*color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AA50
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPSATURATION__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__ENVMAPSATURATION__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPSATURATION_5,
           pName: "$ENVMAPSATURATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "saturation 0 == greyscale 1 == normal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AA70
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__FRESNELREFLECTION__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__FRESNELREFLECTION__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &FRESNELREFLECTION_3,
           pName: "$FRESNELREFLECTION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "1.0 == mirror, 0.0 == water",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AA90
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__NODIFFUSEBUMPLIGHTING__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__NODIFFUSEBUMPLIGHTING__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &NODIFFUSEBUMPLIGHTING_1,
           pName: "$NODIFFUSEBUMPLIGHTING",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "0 == Use diffuse bump lighting, 1 = No diffuse bump lighting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AAB0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPMAP2__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPMAP2__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &BUMPMAP2_0,
           pName: "$BUMPMAP2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader3_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AAD0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPFRAME2__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPFRAME2__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &BUMPFRAME2_1,
           pName: "$BUMPFRAME2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AAF0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPTRANSFORM2__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPTRANSFORM2__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM2_1,
           pName: "$BUMPTRANSFORM2",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AB10
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPMASK__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__BUMPMASK__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &BUMPMASK_0,
           pName: "$BUMPMASK",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AB30
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__BASETEXTURE2__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__BASETEXTURE2__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &BASETEXTURE2_2,
           pName: "$BASETEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/detail",
           pHelp: "detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AB50
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__FRAME2__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__FRAME2__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &FRAME2_2,
           pName: "$FRAME2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $basetexture2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AB70
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__BLENDMODULATETEXTURE__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__BLENDMODULATETEXTURE__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &BLENDMODULATETEXTURE_0,
           pName: "$BLENDMODULATETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "texture to use r/g channels for blend range for",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AB90
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__SSBUMP__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__SSBUMP__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &SSBUMP_1,
           pName: "$SSBUMP",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "whether or not to use alternate bumpmap format with height",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006ABB0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__SEAMLESS_SCALE__
// Source: json
//------------------------------------------------------------------------------
WorldVertexTransition_DX9::CShaderParam *WorldVertexTransition_DX9::_dynamic_initializer_for__SEAMLESS_SCALE__()
{
  return WorldVertexTransition_DX9::CShaderParam::CShaderParam(
           this: &SEAMLESS_SCALE_2,
           pName: "$SEAMLESS_SCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Scale factor for 'seamless' texture mapping. 0 means to use ordinary mapping",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006ABD0
// Name: WorldVertexTransition_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *WorldVertexTransition_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_137);
  s_ShaderInstance_137.__vftable = (WorldVertexTransition_DX9::CShader_vtbl *)&WorldVertexTransition_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B980
// Name: WorldVertexTransition::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl WorldVertexTransition::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_135);
}

//------------------------------------------------------------------------------
// Address: 0x1006B990
// Name: WorldVertexTransition_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl WorldVertexTransition_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_136);
}

//------------------------------------------------------------------------------
// Address: 0x1006ABF0
// Name: _dynamic_initializer_for__s_ConstructMe_writez_vs20___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_writez_vs20___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &writez_vs20_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AC10
// Name: _dynamic_initializer_for__s_ConstructMe_white_ps20___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_white_ps20___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &white_ps20_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x1006AC30
// Name: _dynamic_initializer_for__s_ConstructMe_white_ps20b___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_white_ps20b___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &white_ps20b_combos_0);
}
