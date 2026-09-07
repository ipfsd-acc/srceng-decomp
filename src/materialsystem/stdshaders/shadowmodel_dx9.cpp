// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/shadowmodel_dx9.cpp
// Functions: 26
// ============================================================

#include "materialsystem\stdshaders\shadowmodel_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1002E470
// Name: public: virtual char const __near * ShadowModel::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ShadowModel::CShader::GetFallbackShader(ShadowModel::CShader *this, IMaterialVar **params)
{
  return "ShadowModel_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x1002E480
// Name: public: virtual char const __near * ShadowModel::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ShadowModel::CShader::GetName(ShadowModel::CShader *this)
{
  return s_Name_104;
}

//------------------------------------------------------------------------------
// Address: 0x1002E490
// Name: public: virtual int ShadowModel::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ShadowModel::CShader::GetFlags(ShadowModel::CShader *this)
{
  return s_nFlags_110;
}

//------------------------------------------------------------------------------
// Address: 0x1002E4A0
// Name: public: virtual int ShadowModel::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ShadowModel::CShader::GetParamCount(ShadowModel::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_104.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002E4B0
// Name: public: virtual void ShadowModel_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ShadowModel_DX9::CShader::OnInitShaderParams(
        ShadowModel_DX9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  IMaterialVar *v3; // ecx
  Vector2D scale; // [esp+14h] [ebp-8h] BYREF

  if ( !params[BASETEXTURESCALE.m_Index]->IsDefined(this: params[BASETEXTURESCALE.m_Index]) )
  {
    v3 = params[BASETEXTURESCALE.m_Index];
    scale.x = 1.0;
    scale.y = 1.0;
    v3->SetVecValue_4(this: v3, a2: &scale.x, a3: 2);
  }
  if ( !params[FALLOFFDISTANCE.m_Index]->IsDefined(this: params[FALLOFFDISTANCE.m_Index]) )
    ((void (__stdcall *)(int))params[FALLOFFDISTANCE.m_Index]->SetFloatValue)(a1: 1120403456);
  if ( !params[FALLOFFAMOUNT.m_Index]->IsDefined(this: params[FALLOFFAMOUNT.m_Index]) )
    ((void (__stdcall *)(int))params[FALLOFFAMOUNT.m_Index]->SetFloatValue)(a1: 1063675494);
}

//------------------------------------------------------------------------------
// Address: 0x1002E560
// Name: public: virtual char const __near * ShadowModel_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ShadowModel_DX9::CShader::GetName(ShadowModel_DX9::CShader *this)
{
  return s_Name_105;
}

//------------------------------------------------------------------------------
// Address: 0x1002E570
// Name: public: virtual int ShadowModel_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ShadowModel_DX9::CShader::GetFlags(ShadowModel_DX9::CShader *this)
{
  return s_nFlags_40;
}

//------------------------------------------------------------------------------
// Address: 0x1002E580
// Name: public: virtual void ShadowModel_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ShadowModel_DX9::CShader::OnDrawElements(
        ShadowModel_DX9::CShader *this@<ecx>,
        int a2@<ebx>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IMaterialVar *v8; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v10; // ebx
  int v11; // eax
  int v12; // eax
  const char *v13; // [esp-4h] [ebp-24h]
  const char *v14; // [esp-4h] [ebp-24h]
  Vector4D shadow; // [esp+8h] [ebp-18h] BYREF
  shadowmodel_vs20_Dynamic_Index _vshIndex; // [esp+18h] [ebp-8h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_DST_COLOR, dst: SHADER_BLEND_ZERO);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 3u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "shadowmodel_vs20", a3: 0);
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "shadowmodel_ps20", a3: 0);
    CBaseShader::FogToWhite(this);
    CBaseShader::PI_BeginCommandBuffer(this);
    CBaseShader::PI_SetModulationVertexShaderDynamicState(this);
    CBaseShader::PI_EndCommandBuffer(this);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: 7);
    CBaseVSShader::SetVertexShaderMatrix3x4(this, vertexReg: 48, matrixVar: 8);
    CBaseVSShader::SetVertexShaderConstant(this, vertexReg: 51, constantVar: BASETEXTUREOFFSET.m_Index);
    CBaseVSShader::SetVertexShaderConstant(this, vertexReg: 52, constantVar: BASETEXTURESCALE.m_Index);
    v8 = params[FALLOFFDISTANCE.m_Index];
    shadow.x = params[FALLOFFOFFSET.m_Index]->m_VecVal.x;
    shadow.y = v8->m_VecVal.x + shadow.x;
    if ( shadow.y != 0.0 )
      shadow.y = 1.0 / shadow.y;
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    shadow.z = params[FALLOFFAMOUNT.m_Index]->m_VecVal.x;
    ((void (__thiscall *)(IShaderDynamicAPI *, int, Vector4D *, int, _DWORD, int))SetVertexShaderConstant)(
      a1: pShaderAPI,
      a2: 53,
      a3: &shadow,
      a4: 1,
      a5: 0,
      a6: a2);
    v10 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    if ( g_shaderConfigDumpEnable )
    {
      v11 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetSceneFogMode)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetSceneFogMode() == MATERIAL_FOG_LINEAR_BELOW_FOG_Z");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "DOWATERFOG", v11 == 2, v13);
    }
    _vshIndex.m_nSKINNING = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v12 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v12 > 0, v14);
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v10 + 2 * _vshIndex.m_nSKINNING);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002E760
// Name: public: virtual int ShadowModel_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ShadowModel_DX9::CShader::GetParamCount(ShadowModel_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_105.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002E770
// Name: public: virtual struct ShaderParamInfo_t const __near & ShadowModel::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ShadowModel::CShaderParam *__thiscall ShadowModel::CShader::GetParamInfo(ShadowModel::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_104.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ShadowModel::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002E7A0
// Name: public: virtual struct ShaderParamInfo_t const __near & ShadowModel_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ShadowModel_DX9::CShaderParam *__thiscall ShadowModel_DX9::CShader::GetParamInfo(
        ShadowModel_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_105.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ShadowModel_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002E7D0
// Name: public: ShadowModel_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ShadowModel_DX9::CShaderParam *__thiscall ShadowModel_DX9::CShaderParam::CShaderParam(
        ShadowModel_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  ShadowModel_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  ShadowModel_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_105.m_Size + 13;
  m_Size = s_ShaderParams_105.m_Size;
  v8 = s_ShaderParams_105.m_Size;
  if ( s_ShaderParams_105.m_Size + 1 > s_ShaderParams_105.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_105,
      num: s_ShaderParams_105.m_Size - s_ShaderParams_105.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_105.m_Size;
  }
  m_pMemory = s_ShaderParams_105.m_Memory.m_pMemory;
  s_ShaderParams_105.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_105.m_pElements = s_ShaderParams_105.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_105.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_105.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_105.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066250
// Name: ShadowModel::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ShadowModel::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ShadowModel::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10066260
// Name: ShadowModel::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ShadowModel::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_104);
  s_ShaderInstance_104.__vftable = (ShadowModel::CShader_vtbl *)&ShadowModel::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066280
// Name: ShadowModel_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ShadowModel_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ShadowModel_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10066290
// Name: ShadowModel_DX9::_dynamic_initializer_for__BASETEXTUREOFFSET__
// Source: json
//------------------------------------------------------------------------------
ShadowModel_DX9::CShaderParam *ShadowModel_DX9::_dynamic_initializer_for__BASETEXTUREOFFSET__()
{
  return ShadowModel_DX9::CShaderParam::CShaderParam(
           this: &BASETEXTUREOFFSET,
           pName: "$BASETEXTUREOFFSET",
           type: SHADER_PARAM_TYPE_VEC2,
           pDefaultParam: "[0 0]",
           pHelp: "$baseTexture texcoord offset",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100662B0
// Name: ShadowModel_DX9::_dynamic_initializer_for__BASETEXTURESCALE__
// Source: json
//------------------------------------------------------------------------------
ShadowModel_DX9::CShaderParam *ShadowModel_DX9::_dynamic_initializer_for__BASETEXTURESCALE__()
{
  return ShadowModel_DX9::CShaderParam::CShaderParam(
           this: &BASETEXTURESCALE,
           pName: "$BASETEXTURESCALE",
           type: SHADER_PARAM_TYPE_VEC2,
           pDefaultParam: "[1 1]",
           pHelp: "$baseTexture texcoord scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100662D0
// Name: ShadowModel_DX9::_dynamic_initializer_for__FALLOFFOFFSET__
// Source: json
//------------------------------------------------------------------------------
ShadowModel_DX9::CShaderParam *ShadowModel_DX9::_dynamic_initializer_for__FALLOFFOFFSET__()
{
  return ShadowModel_DX9::CShaderParam::CShaderParam(
           this: &FALLOFFOFFSET,
           pName: "$FALLOFFOFFSET",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Distance at which shadow starts to fade",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100662F0
// Name: ShadowModel_DX9::_dynamic_initializer_for__FALLOFFDISTANCE__
// Source: json
//------------------------------------------------------------------------------
ShadowModel_DX9::CShaderParam *ShadowModel_DX9::_dynamic_initializer_for__FALLOFFDISTANCE__()
{
  return ShadowModel_DX9::CShaderParam::CShaderParam(
           this: &FALLOFFDISTANCE,
           pName: "$FALLOFFDISTANCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "100",
           pHelp: "Max shadow distance",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066310
// Name: ShadowModel_DX9::_dynamic_initializer_for__FALLOFFAMOUNT__
// Source: json
//------------------------------------------------------------------------------
ShadowModel_DX9::CShaderParam *ShadowModel_DX9::_dynamic_initializer_for__FALLOFFAMOUNT__()
{
  return ShadowModel_DX9::CShaderParam::CShaderParam(
           this: &FALLOFFAMOUNT,
           pName: "$FALLOFFAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.9",
           pHelp: "Amount to brighten the shadow at max dist",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066330
// Name: ShadowModel_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ShadowModel_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_105);
  s_ShaderInstance_105.__vftable = (ShadowModel_DX9::CShader_vtbl *)&ShadowModel_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B700
// Name: ShadowModel::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShadowModel::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_104);
}

//------------------------------------------------------------------------------
// Address: 0x1006B710
// Name: ShadowModel_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShadowModel_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_105);
}

//------------------------------------------------------------------------------
// Address: 0x10066350
// Name: _dynamic_initializer_for__s_ConstructMe_ShatteredGlass_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_ShatteredGlass_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &ShatteredGlass_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066370
// Name: _dynamic_initializer_for__s_ConstructMe_ShatteredGlass_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_ShatteredGlass_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &ShatteredGlass_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066390
// Name: _dynamic_initializer_for__s_ConstructMe_ShatteredGlass_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_ShatteredGlass_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &ShatteredGlass_vs20_combos);
}
