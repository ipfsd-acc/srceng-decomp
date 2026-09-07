// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/morphaccumulate_dx9.cpp
// Functions: 24
// ============================================================

#include "materialsystem\stdshaders\morphaccumulate_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1001E9D0
// Name: public: virtual char const __near * MorphAccumulate::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MorphAccumulate::CShader::GetFallbackShader(
        MorphAccumulate::CShader *this,
        IMaterialVar **params)
{
  return "MorphAccumulate_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x1001E9E0
// Name: public: virtual char const __near * MorphAccumulate::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MorphAccumulate::CShader::GetName(MorphAccumulate::CShader *this)
{
  return s_Name_60;
}

//------------------------------------------------------------------------------
// Address: 0x1001E9F0
// Name: public: virtual int MorphAccumulate::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MorphAccumulate::CShader::GetFlags(MorphAccumulate::CShader *this)
{
  return s_nFlags_83;
}

//------------------------------------------------------------------------------
// Address: 0x1001EA00
// Name: public: virtual int MorphAccumulate::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MorphAccumulate::CShader::GetParamCount(MorphAccumulate::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_60.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001EA10
// Name: public: virtual char const __near * MorphAccumulate_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MorphAccumulate_DX9::CShader::GetName(MorphAccumulate_DX9::CShader *this)
{
  return s_Name_61;
}

//------------------------------------------------------------------------------
// Address: 0x1001EA20
// Name: public: virtual int MorphAccumulate_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MorphAccumulate_DX9::CShader::GetFlags(MorphAccumulate_DX9::CShader *this)
{
  return s_nFlags_23;
}

//------------------------------------------------------------------------------
// Address: 0x1001EA30
// Name: public: virtual void MorphAccumulate_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MorphAccumulate_DX9::CShader::OnInitShaderInstance(
        MorphAccumulate_DX9::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: DELTA.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: SIDESPEED.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001EA60
// Name: public: virtual void MorphAccumulate_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MorphAccumulate_DX9::CShader::OnDrawElements(
        MorphAccumulate_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v8; // bl
  void (__thiscall *VertexShaderVertexFormat)(IShaderShadow *, unsigned int, int, int *, int); // edx
  int v11; // ebx
  int v12; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v14)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float pMorphWeightDim[4]; // [esp+Ch] [ebp-2Ch] BYREF
  float pMorphWeightSubrect[4]; // [esp+1Ch] [ebp-1Ch] BYREF
  int nHeight; // [esp+2Ch] [ebp-Ch] BYREF
  int v18; // [esp+30h] [ebp-8h] BYREF
  int nWidth; // [esp+34h] [ebp-4h] BYREF
  BOOL nYOffset; // [esp+44h] [ebp+Ch]
  int nYOffseta; // [esp+44h] [ebp+Ch]
  int nSubrectWidth; // [esp+48h] [ebp+10h]

  v8 = g_pHardwareConfig->NumVertexShaderConstants(this: g_pHardwareConfig) >= 1536;
  if ( pShaderShadow != nullptr )
  {
    CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
    pShaderShadow->EnableBlendingSeparateAlpha(this: pShaderShadow, a2: true);
    pShaderShadow->BlendFuncSeparateAlpha(this: pShaderShadow, a2: SHADER_BLEND_ONE, a3: SHADER_BLEND_ONE);
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->FogMode(this: pShaderShadow, a2: SHADER_FOGMODE_DISABLED, a3: false);
    nYOffset = v8;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "CONSTANTBASEDMORPH", v8, "bUseConstantBasedAccum");
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "morphaccumulate_vs30", a3: nYOffset);
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "CONSTANTBASEDMORPH", v8, "bUseConstantBasedAccum");
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "morphaccumulate_ps30", a3: nYOffset);
    VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
    nHeight = 4;
    v18 = 1;
    VertexShaderVertexFormat(this: pShaderShadow, a2: 512u, a3: 2, a4: &nHeight, a5: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: DELTA.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: SIDESPEED.m_Index,
      nFrameVar: -1);
    if ( !v8 )
    {
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER2,
        a3: TEXTURE_BINDFLAGS_NONE,
        a4: TEXTURE_MORPH_WEIGHTS);
      v11 = pShaderAPI->GetIntRenderingParameter(this: pShaderAPI, a2: 6);
      nYOffseta = pShaderAPI->GetIntRenderingParameter(this: pShaderAPI, a2: 7);
      nSubrectWidth = pShaderAPI->GetIntRenderingParameter(this: pShaderAPI, a2: 8);
      v12 = pShaderAPI->GetIntRenderingParameter(this: pShaderAPI, a2: 9);
      SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
      pMorphWeightSubrect[0] = (float)v11;
      pMorphWeightSubrect[1] = (float)nYOffseta;
      pMorphWeightSubrect[2] = (float)nSubrectWidth;
      pMorphWeightSubrect[3] = (float)v12;
      SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: pMorphWeightSubrect, a4: 1, a5: false);
      pShaderAPI->GetStandardTextureDimensions(this: pShaderAPI, a2: &nWidth, a3: &v18, a4: TEXTURE_MORPH_WEIGHTS);
      v14 = pShaderAPI->SetVertexShaderConstant;
      pMorphWeightDim[0] = (float)nWidth;
      pMorphWeightDim[1] = (float)v18;
      pMorphWeightDim[2] = 0.0;
      pMorphWeightDim[3] = 0.0;
      v14(this: pShaderAPI, a2: 49, a3: pMorphWeightDim, a4: 1, a5: false);
    }
    CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 0, constantVar: DELTASCALE.m_Index);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1001ED00
// Name: public: virtual int MorphAccumulate_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MorphAccumulate_DX9::CShader::GetParamCount(MorphAccumulate_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_61.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001ED10
// Name: public: virtual struct ShaderParamInfo_t const __near & MorphAccumulate::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
MorphAccumulate::CShaderParam *__thiscall MorphAccumulate::CShader::GetParamInfo(
        MorphAccumulate::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_60.m_Memory.m_pMemory[param - ParamCount];
  else
    return (MorphAccumulate::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001ED40
// Name: public: virtual struct ShaderParamInfo_t const __near & MorphAccumulate_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
MorphAccumulate_DX9::CShaderParam *__thiscall MorphAccumulate_DX9::CShader::GetParamInfo(
        MorphAccumulate_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_61.m_Memory.m_pMemory[param - ParamCount];
  else
    return (MorphAccumulate_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001ED70
// Name: public: MorphAccumulate_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
MorphAccumulate_DX9::CShaderParam *__thiscall MorphAccumulate_DX9::CShaderParam::CShaderParam(
        MorphAccumulate_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  MorphAccumulate_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  MorphAccumulate_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_61.m_Size + 13;
  m_Size = s_ShaderParams_61.m_Size;
  v8 = s_ShaderParams_61.m_Size;
  if ( s_ShaderParams_61.m_Size + 1 > s_ShaderParams_61.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_61,
      num: s_ShaderParams_61.m_Size - s_ShaderParams_61.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_61.m_Size;
  }
  m_pMemory = s_ShaderParams_61.m_Memory.m_pMemory;
  s_ShaderParams_61.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_61.m_pElements = s_ShaderParams_61.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_61.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_61.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_61.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063470
// Name: MorphAccumulate::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int MorphAccumulate::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: MorphAccumulate::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063480
// Name: MorphAccumulate::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *MorphAccumulate::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_60);
  s_ShaderInstance_60.__vftable = (MorphAccumulate::CShader_vtbl *)&MorphAccumulate::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100634A0
// Name: MorphAccumulate_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int MorphAccumulate_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: MorphAccumulate_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100634B0
// Name: MorphAccumulate_DX9::_dynamic_initializer_for__DELTA__
// Source: json
//------------------------------------------------------------------------------
MorphAccumulate_DX9::CShaderParam *MorphAccumulate_DX9::_dynamic_initializer_for__DELTA__()
{
  return MorphAccumulate_DX9::CShaderParam::CShaderParam(
           this: &DELTA,
           pName: "$DELTA",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "position/normal deltas",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100634D0
// Name: MorphAccumulate_DX9::_dynamic_initializer_for__SIDESPEED__
// Source: json
//------------------------------------------------------------------------------
MorphAccumulate_DX9::CShaderParam *MorphAccumulate_DX9::_dynamic_initializer_for__SIDESPEED__()
{
  return MorphAccumulate_DX9::CShaderParam::CShaderParam(
           this: &SIDESPEED,
           pName: "$SIDESPEED",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "side/speed map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100634F0
// Name: MorphAccumulate_DX9::_dynamic_initializer_for__DIMENSIONS__
// Source: json
//------------------------------------------------------------------------------
MorphAccumulate_DX9::CShaderParam *MorphAccumulate_DX9::_dynamic_initializer_for__DIMENSIONS__()
{
  return MorphAccumulate_DX9::CShaderParam::CShaderParam(
           this: &DIMENSIONS,
           pName: "$DIMENSIONS",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: pDefaultParam,
           pHelp: "delta dimensions",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063510
// Name: MorphAccumulate_DX9::_dynamic_initializer_for__DELTASCALE__
// Source: json
//------------------------------------------------------------------------------
MorphAccumulate_DX9::CShaderParam *MorphAccumulate_DX9::_dynamic_initializer_for__DELTASCALE__()
{
  return MorphAccumulate_DX9::CShaderParam::CShaderParam(
           this: &DELTASCALE,
           pName: "$DELTASCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: "delta scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063530
// Name: MorphAccumulate_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *MorphAccumulate_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_61);
  s_ShaderInstance_61.__vftable = (MorphAccumulate_DX9::CShader_vtbl *)&MorphAccumulate_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B3C0
// Name: MorphAccumulate::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphAccumulate::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_60);
}

//------------------------------------------------------------------------------
// Address: 0x1006B3D0
// Name: MorphAccumulate_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphAccumulate_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_61);
}

//------------------------------------------------------------------------------
// Address: 0x10063550
// Name: _dynamic_initializer_for__s_ConstructMe_morphweight_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_morphweight_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &morphweight_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063570
// Name: _dynamic_initializer_for__s_ConstructMe_morphweight_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_morphweight_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &morphweight_ps30_combos);
}
