// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/shadow.cpp
// Functions: 23
// ============================================================

#include "materialsystem\stdshaders\shadow.h"

//------------------------------------------------------------------------------
// Address: 0x1002D710
// Name: public: virtual void Shadow::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Shadow::CShader::OnInitShaderParams(
        Shadow::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( !params[MAXFALLOFFAMOUNT.m_Index]->IsDefined(this: params[MAXFALLOFFAMOUNT.m_Index]) )
    ((void (__stdcall *)(int))params[MAXFALLOFFAMOUNT.m_Index]->SetFloatValue)(a1: 1131413504);
  if ( !params[DEFERREDSHADOWS.m_Index]->IsDefined(this: params[DEFERREDSHADOWS.m_Index]) )
    params[DEFERREDSHADOWS.m_Index]->SetIntValue(this: params[DEFERREDSHADOWS.m_Index], a2: 0);
  if ( !params[ZFAILENABLE.m_Index]->IsDefined(this: params[ZFAILENABLE.m_Index]) )
    params[ZFAILENABLE.m_Index]->SetIntValue(this: params[ZFAILENABLE.m_Index], a2: 0);
  if ( !params[BLOBBYSHADOWS.m_Index]->IsDefined(this: params[BLOBBYSHADOWS.m_Index]) )
    params[BLOBBYSHADOWS.m_Index]->SetIntValue(this: params[BLOBBYSHADOWS.m_Index], a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002D7C0
// Name: public: virtual char const __near * Shadow::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Shadow::CShader::GetName(Shadow::CShader *this)
{
  return s_Name_101;
}

//------------------------------------------------------------------------------
// Address: 0x1002D7D0
// Name: public: virtual int Shadow::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Shadow::CShader::GetFlags(Shadow::CShader *this)
{
  return s_nFlags_38;
}

//------------------------------------------------------------------------------
// Address: 0x1002D7E0
// Name: public: virtual void Shadow::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Shadow::CShader::OnInitShaderInstance(
        Shadow::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x1002D7F0
// Name: public: virtual void Shadow::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Shadow::CShader::OnDrawElements(
        Shadow::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  Shadow::CShader *v7; // edi
  bool v8; // bl
  void (__thiscall *EnableTexture)(IShaderShadow *, Sampler_t, bool); // edx
  void (__thiscall *VertexShaderVertexFormat)(IShaderShadow *, unsigned int, int, int *, int); // eax
  BOOL v12; // edi
  bool v14; // bl
  int v15; // ebx
  int v16; // edi
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v18; // xmm1_4
  int v19; // xmm0_4
  void (__thiscall *v20)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  MaterialFogMode_t v21; // eax
  MaterialFogMode_t v22; // eax
  float x; // xmm0_4
  int v24; // edi
  int v25; // eax
  _DWORD v26[3]; // [esp+Ch] [ebp-40h] BYREF
  float eyePos[4]; // [esp+18h] [ebp-34h] BYREF
  float v28; // [esp+28h] [ebp-24h] BYREF
  shadow_vs20_Static_Index _vshIndex; // [esp+2Ch] [ebp-20h]
  CBaseShader *v30; // [esp+38h] [ebp-14h]
  float v31; // [esp+3Ch] [ebp-10h] BYREF
  float v32; // [esp+40h] [ebp-Ch]
  int texCoordDims[2]; // [esp+44h] [ebp-8h] BYREF
  bool bBlobbyShadows_3; // [esp+5Bh] [ebp+Fh]
  bool bBlobbyShadows_3a; // [esp+5Bh] [ebp+Fh]
  int nHeight; // [esp+5Ch] [ebp+10h]

  v7 = this;
  v30 = this;
  if ( pShaderShadow != nullptr )
  {
    v8 = params[DEFERREDSHADOWS.m_Index]->m_intVal != 0;
    EnableTexture = pShaderShadow->EnableTexture;
    bBlobbyShadows_3 = params[BLOBBYSHADOWS.m_Index]->m_intVal != 0;
    EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    if ( v8 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
      CBaseShader::EnableAlphaBlending(this: v7, src: SHADER_BLEND_ZERO, dst: SHADER_BLEND_SRC_COLOR);
      v26[1] = 4;
      v26[2] = 4;
      LODWORD(eyePos[0]) = 4;
      LODWORD(eyePos[1]) = 4;
      LODWORD(eyePos[2]) = 4;
      VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
      v26[0] = 3;
      LODWORD(eyePos[3]) = 3;
      VertexShaderVertexFormat(this: pShaderShadow, a2: 3u, a3: 7, a4: v26, a5: 0);
    }
    else
    {
      CBaseShader::EnableAlphaBlending(this: v7, src: SHADER_BLEND_ZERO, dst: SHADER_BLEND_SRC_COLOR);
      texCoordDims[0] = 3;
      texCoordDims[1] = 3;
      pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 5u, a3: 2, a4: texCoordDims, a5: 0);
    }
    v12 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    _vshIndex.m_nHARDWAREFOGBLEND = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    texCoordDims[1] = v8;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "DEFERRED_SHADOWS", v8, "bDeferredShadows");
    pShaderShadow->SetVertexShader(
      this: pShaderShadow,
      a2: "shadow_vs20",
      a3: 2 * (texCoordDims[1] + 2 * (v12 + 2 * _vshIndex.m_nHARDWAREFOGBLEND)));
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DEFERRED_SHADOWS", v8, "bDeferredShadows");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BLOBBY_SHADOWS", bBlobbyShadows_3, "bBlobbyShadows");
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "shadow_ps20",
        a3: 2 * (texCoordDims[1] + bBlobbyShadows_3));
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DEFERRED_SHADOWS", v8, "bDeferredShadows");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BLOBBY_SHADOWS", bBlobbyShadows_3, "bBlobbyShadows");
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "shadow_ps20b",
        a3: 2 * (texCoordDims[1] + bBlobbyShadows_3));
    }
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    if ( v8 )
    {
      pShaderShadow->DepthFunc(
        this: pShaderShadow,
        a2: (ShaderDepthFunc_t)((params[ZFAILENABLE.m_Index]->m_intVal != 0) + 3));
      pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
      pShaderShadow->EnableColorWrites(this: pShaderShadow, a2: true);
      pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    }
    CBaseShader::FogToWhite(this: v30);
    v7 = (Shadow::CShader *)v30;
  }
  if ( pShaderAPI != nullptr )
  {
    v14 = params[DEFERREDSHADOWS.m_Index]->m_intVal != 0;
    bBlobbyShadows_3a = v14;
    CBaseShader::BindTexture(
      this: v7,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: 6,
      nFrameVar: 7);
    if ( v14 )
      CBaseShader::BindTexture(
        this: v7,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: DEPTHTEXTURE.m_Index,
        nFrameVar: -1);
    CBaseVSShader::SetVertexShaderTextureTransform(this: v7, vertexReg: 48, transformVar: 8);
    CBaseVSShader::SetPixelShaderConstantGammaToLinear(this: v7, pixelReg: 1, constantVar: 4);
    v15 = 16;
    nHeight = 16;
    v16 = params[6]->GetTextureValue(this: params[6]);
    if ( v16 != 0 )
    {
      v15 = (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 12))(a1: v16);
      nHeight = (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 16))(a1: v16);
    }
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    v18 = 1.0 / (double)v15;
    v28 = v18;
    *(float *)&v19 = 1.0 / (double)nHeight;
    _vshIndex.m_nDEFERRED_SHADOWS = v19;
    _vshIndex.m_nDOPIXELFOG = 0;
    _vshIndex.m_nHARDWAREFOGBLEND = 0;
    SetVertexShaderConstant(this: pShaderAPI, a2: 50, a3: &v28, a4: 1, a5: false);
    v20 = pShaderAPI->SetVertexShaderConstant;
    *(float *)&_vshIndex.m_nDEFERRED_SHADOWS = *(float *)&_vshIndex.m_nDEFERRED_SHADOWS * -1.0;
    v20(this: pShaderAPI, a2: 51, a3: &v28, a4: 1, a5: false);
    v21 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v21 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v22 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v22 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: eyePos);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 2, a3: eyePos, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 3);
    v31 = 0.0;
    v32 = 0.0;
    texCoordDims[0] = 0;
    texCoordDims[1] = 0;
    if ( MAXFALLOFFAMOUNT.m_Index >= 0
      && params[MAXFALLOFFAMOUNT.m_Index]->IsDefined(this: params[MAXFALLOFFAMOUNT.m_Index]) )
    {
      x = params[MAXFALLOFFAMOUNT.m_Index]->m_VecVal.x;
    }
    else
    {
      x = 240.0;
    }
    v31 = x * 0.0039215689;
    if ( bBlobbyShadows_3a )
    {
      v24 = params[DEPTHTEXTURE.m_Index]->GetTextureValue(this: params[DEPTHTEXTURE.m_Index]);
      if ( v24 != 0 )
      {
        v15 = (*(int (__thiscall **)(int))(*(_DWORD *)v24 + 12))(a1: v24);
        v25 = (*(int (__thiscall **)(int))(*(_DWORD *)v24 + 16))(a1: v24);
      }
      else
      {
        v25 = nHeight;
      }
      v32 = 1.0 / (float)v15;
      *(float *)texCoordDims = 1.0 / (float)v25;
    }
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 4, a3: &v31, a4: 1, a5: false);
    v7 = (Shadow::CShader *)v30;
  }
  CBaseShader::Draw(this: v7, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002DCF0
// Name: public: virtual int Shadow::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Shadow::CShader::GetParamCount(Shadow::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_101.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002DD00
// Name: public: virtual struct ShaderParamInfo_t const __near & Shadow::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Shadow::CShaderParam *__thiscall Shadow::CShader::GetParamInfo(Shadow::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_101.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Shadow::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002DD30
// Name: public: Shadow::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Shadow::CShaderParam *__thiscall Shadow::CShaderParam::CShaderParam(
        Shadow::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Shadow::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Shadow::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_101.m_Size + 13;
  m_Size = s_ShaderParams_101.m_Size;
  v8 = s_ShaderParams_101.m_Size;
  if ( s_ShaderParams_101.m_Size + 1 > s_ShaderParams_101.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_101,
      num: s_ShaderParams_101.m_Size - s_ShaderParams_101.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_101.m_Size;
  }
  m_pMemory = s_ShaderParams_101.m_Memory.m_pMemory;
  s_ShaderParams_101.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_101.m_pElements = s_ShaderParams_101.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_101.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_101.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_101.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10065FF0
// Name: Shadow::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Shadow::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Shadow::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10066000
// Name: Shadow::_dynamic_initializer_for__MAXFALLOFFAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Shadow::CShaderParam *Shadow::_dynamic_initializer_for__MAXFALLOFFAMOUNT__()
{
  return Shadow::CShaderParam::CShaderParam(
           this: &MAXFALLOFFAMOUNT,
           pName: "$MAXFALLOFFAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "240",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066020
// Name: Shadow::_dynamic_initializer_for__DEFERREDSHADOWS__
// Source: json
//------------------------------------------------------------------------------
Shadow::CShaderParam *Shadow::_dynamic_initializer_for__DEFERREDSHADOWS__()
{
  return Shadow::CShaderParam::CShaderParam(
           this: &DEFERREDSHADOWS,
           pName: "$DEFERREDSHADOWS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066040
// Name: Shadow::_dynamic_initializer_for__ZFAILENABLE__
// Source: json
//------------------------------------------------------------------------------
Shadow::CShaderParam *Shadow::_dynamic_initializer_for__ZFAILENABLE__()
{
  return Shadow::CShaderParam::CShaderParam(
           this: &ZFAILENABLE,
           pName: "$ZFAILENABLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066060
// Name: Shadow::_dynamic_initializer_for__BLOBBYSHADOWS__
// Source: json
//------------------------------------------------------------------------------
Shadow::CShaderParam *Shadow::_dynamic_initializer_for__BLOBBYSHADOWS__()
{
  return Shadow::CShaderParam::CShaderParam(
           this: &BLOBBYSHADOWS,
           pName: "$BLOBBYSHADOWS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066080
// Name: Shadow::_dynamic_initializer_for__DEPTHTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Shadow::CShaderParam *Shadow::_dynamic_initializer_for__DEPTHTEXTURE__()
{
  return Shadow::CShaderParam::CShaderParam(
           this: &DEPTHTEXTURE,
           pName: "$DEPTHTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100660A0
// Name: Shadow::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Shadow::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_101);
  s_ShaderInstance_101.__vftable = (Shadow::CShader_vtbl *)&Shadow::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B6C0
// Name: Shadow::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shadow::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_101);
}

//------------------------------------------------------------------------------
// Address: 0x100660C0
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs20___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs20___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_vs20_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x100660E0
// Name: _dynamic_initializer_for__s_ConstructMe_shadowbuildtexture_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_shadowbuildtexture_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &shadowbuildtexture_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066100
// Name: _dynamic_initializer_for__s_ConstructMe_shadowbuildtexture_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_shadowbuildtexture_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &shadowbuildtexture_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066120
// Name: _dynamic_initializer_for__s_ConstructMe_shadowbuildtexture_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_shadowbuildtexture_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &shadowbuildtexture_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066140
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs30___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs30___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_vs30_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x10066160
// Name: _dynamic_initializer_for__mat_displacementmap___3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_displacementmap___3()
{
  ConVar::ConVar(this: &mat_displacementmap_3, pName: "mat_displacementmap", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_displacementmap___3);
}

//------------------------------------------------------------------------------
// Address: 0x1006B6D0
// Name: _dynamic_atexit_destructor_for__mat_displacementmap___3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_displacementmap___3()
{
  ConVar::~ConVar(this: &mat_displacementmap_3);
}
