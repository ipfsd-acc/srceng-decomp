// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/floatcombine_autoexpose.cpp
// Functions: 25
// ============================================================

#include "materialsystem\stdshaders\floatcombine_autoexpose.h"

//------------------------------------------------------------------------------
// Address: 0x10013D30
// Name: public: virtual char const __near * floatcombine_autoexpose::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall floatcombine_autoexpose::CShader::GetName(floatcombine_autoexpose::CShader *this)
{
  return s_Name_39;
}

//------------------------------------------------------------------------------
// Address: 0x10013D40
// Name: public: virtual int floatcombine_autoexpose::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall floatcombine_autoexpose::CShader::GetFlags(floatcombine_autoexpose::CShader *this)
{
  return s_nFlags_69;
}

//------------------------------------------------------------------------------
// Address: 0x10013D50
// Name: public: virtual void floatcombine_autoexpose::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall floatcombine_autoexpose::CShader::OnInitShaderInstance(
        floatcombine_autoexpose::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
  if ( params[BLOOMTEXTURE_0.m_Index]->IsDefined(this: params[BLOOMTEXTURE_0.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: BLOOMTEXTURE_0.m_Index, nAdditionalCreationFlags: 0);
  if ( params[EXPOSURE_TEXTURE.m_Index]->IsDefined(this: params[EXPOSURE_TEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: EXPOSURE_TEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10013DC0
// Name: public: virtual void floatcombine_autoexpose::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall floatcombine_autoexpose::CShader::OnDrawElements(
        floatcombine_autoexpose::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v7; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  IMaterialVar *v9; // edx
  float x; // xmm0_4
  IMaterialVar *v11; // edx
  float v12; // xmm0_4
  IMaterialVar *v13; // edx
  float v14; // xmm0_4
  IMaterialVar *v15; // edx
  float v16; // xmm0_4
  IMaterialVar *v17; // edx
  float v18; // xmm0_4
  IMaterialVar *v19; // edx
  float v20; // xmm0_4
  IMaterialVar *v21; // edx
  float v22; // xmm0_4
  IMaterialVar *v23; // edx
  float v24; // xmm0_4
  IMaterialVar *v25; // edx
  IShaderDynamicAPI_vtbl *v26; // eax
  float v27; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v29; // [esp+0h] [ebp-38h]
  float c2[4]; // [esp+8h] [ebp-30h] BYREF
  float c1[4]; // [esp+18h] [ebp-20h] BYREF
  float c0[4]; // [esp+28h] [ebp-10h] BYREF

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v29 = 0;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "floatcombine_autoexpose_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "floatcombine_autoexpose_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    v9 = params[WOODCUT_0.m_Index];
    c0[0] = params[SHARPNESS_0.m_Index]->m_VecVal.x;
    x = v9->m_VecVal.x;
    v11 = params[BLOOMAMOUNT_2.m_Index];
    c0[1] = x;
    v12 = v11->m_VecVal.x;
    v13 = params[ALPHASHARPENFACTOR_0.m_Index];
    c0[2] = v12;
    v14 = v13->m_VecVal.x;
    v15 = params[BLOOMEXPONENT_0.m_Index];
    c0[3] = v14;
    v16 = v15->m_VecVal.x;
    v17 = params[VIGNETTE_MIN_BRIGHT_0.m_Index];
    c1[0] = v16;
    v18 = v17->m_VecVal.x;
    v19 = params[VIGNETTE_POWER_0.m_Index];
    c1[1] = v18;
    v20 = v19->m_VecVal.x;
    v21 = params[EDGE_SOFTNESS_0.m_Index];
    c1[2] = v20;
    v22 = v21->m_VecVal.x;
    v23 = params[AUTOEXPOSE_MIN.m_Index];
    c1[3] = v22;
    v24 = v23->m_VecVal.x;
    v25 = params[AUTOEXPOSE_MAX.m_Index];
    v26 = pShaderAPI->__vftable;
    c2[0] = v24;
    v27 = v25->m_VecVal.x;
    SetPixelShaderConstant = v26->SetPixelShaderConstant;
    c2[1] = v27;
    c2[2] = 0.0;
    c2[3] = 0.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: c0, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 1, a3: c1, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 2, a3: c2, a4: 1, a5: false);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: BLOOMTEXTURE_0.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: EXPOSURE_TEXTURE.m_Index,
      nFrameVar: -1);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    ((void (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
      a1: g_pHardwareConfig,
      a2: v29);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10013FE0
// Name: public: virtual int floatcombine_autoexpose::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall floatcombine_autoexpose::CShader::GetParamCount(floatcombine_autoexpose::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_39.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10013FF0
// Name: public: virtual struct ShaderParamInfo_t const __near & floatcombine_autoexpose::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *__thiscall floatcombine_autoexpose::CShader::GetParamInfo(
        floatcombine_autoexpose::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_39.m_Memory.m_pMemory[param - ParamCount];
  else
    return (floatcombine_autoexpose::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10014020
// Name: public: floatcombine_autoexpose::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *__thiscall floatcombine_autoexpose::CShaderParam::CShaderParam(
        floatcombine_autoexpose::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  floatcombine_autoexpose::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  floatcombine_autoexpose::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_39.m_Size + 13;
  m_Size = s_ShaderParams_39.m_Size;
  v8 = s_ShaderParams_39.m_Size;
  if ( s_ShaderParams_39.m_Size + 1 > s_ShaderParams_39.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_39,
      num: s_ShaderParams_39.m_Size - s_ShaderParams_39.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_39.m_Size;
  }
  m_pMemory = s_ShaderParams_39.m_Memory.m_pMemory;
  s_ShaderParams_39.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_39.m_pElements = s_ShaderParams_39.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_39.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_39.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_39.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10061790
// Name: floatcombine_autoexpose::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int floatcombine_autoexpose::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: floatcombine_autoexpose::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100617A0
// Name: floatcombine_autoexpose::_dynamic_initializer_for__BLOOMTEXTURE__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__BLOOMTEXTURE__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &BLOOMTEXTURE_0,
           pName: "$BLOOMTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100617C0
// Name: floatcombine_autoexpose::_dynamic_initializer_for__SHARPNESS__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__SHARPNESS__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &SHARPNESS_0,
           pName: "$SHARPNESS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100617E0
// Name: floatcombine_autoexpose::_dynamic_initializer_for__WOODCUT__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__WOODCUT__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &WOODCUT_0,
           pName: "$WOODCUT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061800
// Name: floatcombine_autoexpose::_dynamic_initializer_for__VIGNETTE_MIN_BRIGHT__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__VIGNETTE_MIN_BRIGHT__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &VIGNETTE_MIN_BRIGHT_0,
           pName: "$VIGNETTE_MIN_BRIGHT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061820
// Name: floatcombine_autoexpose::_dynamic_initializer_for__VIGNETTE_POWER__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__VIGNETTE_POWER__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &VIGNETTE_POWER_0,
           pName: "$VIGNETTE_POWER",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "4",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061840
// Name: floatcombine_autoexpose::_dynamic_initializer_for__EDGE_SOFTNESS__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__EDGE_SOFTNESS__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &EDGE_SOFTNESS_0,
           pName: "$EDGE_SOFTNESS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061860
// Name: floatcombine_autoexpose::_dynamic_initializer_for__BLOOMAMOUNT__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__BLOOMAMOUNT__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &BLOOMAMOUNT_2,
           pName: "$BLOOMAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061880
// Name: floatcombine_autoexpose::_dynamic_initializer_for__BLOOMEXPONENT__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__BLOOMEXPONENT__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &BLOOMEXPONENT_0,
           pName: "$BLOOMEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100618A0
// Name: floatcombine_autoexpose::_dynamic_initializer_for__ALPHASHARPENFACTOR__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__ALPHASHARPENFACTOR__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &ALPHASHARPENFACTOR_0,
           pName: "$ALPHASHARPENFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100618C0
// Name: floatcombine_autoexpose::_dynamic_initializer_for__EXPOSURE_TEXTURE__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__EXPOSURE_TEXTURE__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &EXPOSURE_TEXTURE,
           pName: "$EXPOSURE_TEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100618E0
// Name: floatcombine_autoexpose::_dynamic_initializer_for__AUTOEXPOSE_MIN__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__AUTOEXPOSE_MIN__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &AUTOEXPOSE_MIN,
           pName: "$AUTOEXPOSE_MIN",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: ".5",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061900
// Name: floatcombine_autoexpose::_dynamic_initializer_for__AUTOEXPOSE_MAX__
// Source: json
//------------------------------------------------------------------------------
floatcombine_autoexpose::CShaderParam *floatcombine_autoexpose::_dynamic_initializer_for__AUTOEXPOSE_MAX__()
{
  return floatcombine_autoexpose::CShaderParam::CShaderParam(
           this: &AUTOEXPOSE_MAX,
           pName: "$AUTOEXPOSE_MAX",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061920
// Name: floatcombine_autoexpose::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *floatcombine_autoexpose::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_39);
  s_ShaderInstance_39.__vftable = (floatcombine_autoexpose::CShader_vtbl *)&floatcombine_autoexpose::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B210
// Name: floatcombine_autoexpose::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl floatcombine_autoexpose::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_39);
}

//------------------------------------------------------------------------------
// Address: 0x10061940
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___7()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_7);
}

//------------------------------------------------------------------------------
// Address: 0x10061960
// Name: _dynamic_initializer_for__s_ConstructMe_floattoscreen_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_floattoscreen_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &floattoscreen_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061980
// Name: _dynamic_initializer_for__s_ConstructMe_floattoscreen_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_floattoscreen_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &floattoscreen_ps20b_combos);
}
