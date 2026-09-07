// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/floatcombine.cpp
// Functions: 22
// ============================================================

#include "materialsystem\stdshaders\floatcombine.h"

//------------------------------------------------------------------------------
// Address: 0x10013960
// Name: public: virtual char const __near * floatcombine::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall floatcombine::CShader::GetName(floatcombine::CShader *this)
{
  return s_Name_38;
}

//------------------------------------------------------------------------------
// Address: 0x10013970
// Name: public: virtual int floatcombine::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall floatcombine::CShader::GetFlags(floatcombine::CShader *this)
{
  return s_nFlags_15;
}

//------------------------------------------------------------------------------
// Address: 0x10013980
// Name: public: virtual void floatcombine::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall floatcombine::CShader::OnInitShaderInstance(
        floatcombine::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
  if ( params[BLOOMTEXTURE.m_Index]->IsDefined(this: params[BLOOMTEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: BLOOMTEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100139D0
// Name: public: virtual void floatcombine::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall floatcombine::CShader::OnDrawElements(
        floatcombine::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  floatcombine::CShader *v6; // ebx
  int v7; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  IMaterialVar *v10; // eax
  IMaterialVar *v11; // edx
  IMaterialVar *v12; // ecx
  IMaterialVar *v13; // eax
  IMaterialVar *v14; // edx
  IMaterialVar *v15; // ecx
  float x; // xmm0_4
  IMaterialVar *v17; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v19; // ebx
  int v20; // esi
  int v21; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v23; // [esp+0h] [ebp-40h]
  float v0[4]; // [esp+Ch] [ebp-34h] BYREF
  float c1[4]; // [esp+1Ch] [ebp-24h] BYREF
  float c0[4]; // [esp+2Ch] [ebp-14h] BYREF
  floatcombine::CShader *v27; // [esp+3Ch] [ebp-4h]

  v6 = this;
  v27 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v23 = 0;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "floatcombine_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "floatcombine_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    v10 = params[WOODCUT.m_Index];
    v11 = params[BLOOMAMOUNT_1.m_Index];
    c0[0] = params[SHARPNESS.m_Index]->m_VecVal.x;
    v12 = params[ALPHASHARPENFACTOR.m_Index];
    c0[1] = v10->m_VecVal.x;
    v13 = params[BLOOMEXPONENT.m_Index];
    c0[2] = v11->m_VecVal.x;
    v14 = params[VIGNETTE_MIN_BRIGHT.m_Index];
    c0[3] = v12->m_VecVal.x;
    v15 = params[VIGNETTE_POWER.m_Index];
    c1[0] = v13->m_VecVal.x;
    x = v14->m_VecVal.x;
    v17 = params[EDGE_SOFTNESS.m_Index];
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    c1[1] = x;
    c1[2] = v15->m_VecVal.x;
    c1[3] = v17->m_VecVal.x;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: c0, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 1, a3: c1, a4: 1, a5: false);
    CBaseShader::BindTexture(
      this: v6,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: v6,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: BLOOMTEXTURE.m_Index,
      nFrameVar: -1);
    v19 = ((int (__thiscall *)(IMaterialVar *, int))params[6]->GetTextureValue)(a1: params[6], a2: v23);
    v20 = params[BLOOMTEXTURE.m_Index]->GetTextureValue(this: params[BLOOMTEXTURE.m_Index]);
    v0[0] = 1.0 / (double)(*(int (__thiscall **)(int))(*(_DWORD *)v19 + 12))(a1: v19);
    v0[1] = 1.0 / (double)(*(int (__thiscall **)(int))(*(_DWORD *)v19 + 16))(a1: v19);
    v0[2] = 1.0 / (double)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 12))(a1: v20);
    v21 = (*(int (__thiscall **)(int))(*(_DWORD *)v20 + 16))(a1: v20);
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    v0[3] = 1.0 / (double)v21;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: v0, a4: 1, a5: false);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    v6 = v27;
  }
  CBaseShader::Draw(this: v6, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10013C50
// Name: public: virtual int floatcombine::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall floatcombine::CShader::GetParamCount(floatcombine::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_38.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10013C60
// Name: public: virtual struct ShaderParamInfo_t const __near & floatcombine::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
floatcombine::CShaderParam *__thiscall floatcombine::CShader::GetParamInfo(floatcombine::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_38.m_Memory.m_pMemory[param - ParamCount];
  else
    return (floatcombine::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10013C90
// Name: public: floatcombine::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
floatcombine::CShaderParam *__thiscall floatcombine::CShaderParam::CShaderParam(
        floatcombine::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  floatcombine::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  floatcombine::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_38.m_Size + 13;
  m_Size = s_ShaderParams_38.m_Size;
  v8 = s_ShaderParams_38.m_Size;
  if ( s_ShaderParams_38.m_Size + 1 > s_ShaderParams_38.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_38,
      num: s_ShaderParams_38.m_Size - s_ShaderParams_38.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_38.m_Size;
  }
  m_pMemory = s_ShaderParams_38.m_Memory.m_pMemory;
  s_ShaderParams_38.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_38.m_pElements = s_ShaderParams_38.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_38.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_38.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_38.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100615E0
// Name: floatcombine::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int floatcombine::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: floatcombine::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100615F0
// Name: floatcombine::_dynamic_initializer_for__BLOOMTEXTURE__
// Source: json
//------------------------------------------------------------------------------
floatcombine::CShaderParam *floatcombine::_dynamic_initializer_for__BLOOMTEXTURE__()
{
  return floatcombine::CShaderParam::CShaderParam(
           this: &BLOOMTEXTURE,
           pName: "$BLOOMTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061610
// Name: floatcombine::_dynamic_initializer_for__SHARPNESS__
// Source: json
//------------------------------------------------------------------------------
floatcombine::CShaderParam *floatcombine::_dynamic_initializer_for__SHARPNESS__()
{
  return floatcombine::CShaderParam::CShaderParam(
           this: &SHARPNESS,
           pName: "$SHARPNESS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061630
// Name: floatcombine::_dynamic_initializer_for__WOODCUT__
// Source: json
//------------------------------------------------------------------------------
floatcombine::CShaderParam *floatcombine::_dynamic_initializer_for__WOODCUT__()
{
  return floatcombine::CShaderParam::CShaderParam(
           this: &WOODCUT,
           pName: "$WOODCUT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061650
// Name: floatcombine::_dynamic_initializer_for__VIGNETTE_MIN_BRIGHT__
// Source: json
//------------------------------------------------------------------------------
floatcombine::CShaderParam *floatcombine::_dynamic_initializer_for__VIGNETTE_MIN_BRIGHT__()
{
  return floatcombine::CShaderParam::CShaderParam(
           this: &VIGNETTE_MIN_BRIGHT,
           pName: "$VIGNETTE_MIN_BRIGHT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061670
// Name: floatcombine::_dynamic_initializer_for__VIGNETTE_POWER__
// Source: json
//------------------------------------------------------------------------------
floatcombine::CShaderParam *floatcombine::_dynamic_initializer_for__VIGNETTE_POWER__()
{
  return floatcombine::CShaderParam::CShaderParam(
           this: &VIGNETTE_POWER,
           pName: "$VIGNETTE_POWER",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "4",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061690
// Name: floatcombine::_dynamic_initializer_for__EDGE_SOFTNESS__
// Source: json
//------------------------------------------------------------------------------
floatcombine::CShaderParam *floatcombine::_dynamic_initializer_for__EDGE_SOFTNESS__()
{
  return floatcombine::CShaderParam::CShaderParam(
           this: &EDGE_SOFTNESS,
           pName: "$EDGE_SOFTNESS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100616B0
// Name: floatcombine::_dynamic_initializer_for__BLOOMAMOUNT__
// Source: json
//------------------------------------------------------------------------------
floatcombine::CShaderParam *floatcombine::_dynamic_initializer_for__BLOOMAMOUNT__()
{
  return floatcombine::CShaderParam::CShaderParam(
           this: &BLOOMAMOUNT_1,
           pName: "$BLOOMAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100616D0
// Name: floatcombine::_dynamic_initializer_for__BLOOMEXPONENT__
// Source: json
//------------------------------------------------------------------------------
floatcombine::CShaderParam *floatcombine::_dynamic_initializer_for__BLOOMEXPONENT__()
{
  return floatcombine::CShaderParam::CShaderParam(
           this: &BLOOMEXPONENT,
           pName: "$BLOOMEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100616F0
// Name: floatcombine::_dynamic_initializer_for__ALPHASHARPENFACTOR__
// Source: json
//------------------------------------------------------------------------------
floatcombine::CShaderParam *floatcombine::_dynamic_initializer_for__ALPHASHARPENFACTOR__()
{
  return floatcombine::CShaderParam::CShaderParam(
           this: &ALPHASHARPENFACTOR,
           pName: "$ALPHASHARPENFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061710
// Name: floatcombine::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *floatcombine::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_38);
  s_ShaderInstance_38.__vftable = (floatcombine::CShader_vtbl *)&floatcombine::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B200
// Name: floatcombine::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl floatcombine::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_38);
}

//------------------------------------------------------------------------------
// Address: 0x10061730
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___6()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_6);
}

//------------------------------------------------------------------------------
// Address: 0x10061750
// Name: _dynamic_initializer_for__s_ConstructMe_floatcombine_autoexpose_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_floatcombine_autoexpose_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &floatcombine_autoexpose_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061770
// Name: _dynamic_initializer_for__s_ConstructMe_floatcombine_autoexpose_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_floatcombine_autoexpose_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &floatcombine_autoexpose_ps20b_combos);
}
