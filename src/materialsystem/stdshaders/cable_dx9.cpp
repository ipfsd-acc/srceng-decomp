// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/cable_dx9.cpp
// Functions: 21
// ============================================================

#include "materialsystem\stdshaders\cable_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10008300
// Name: public: virtual char const __near * Cable::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Cable::CShader::GetFallbackShader(Cable::CShader *this, IMaterialVar **params)
{
  return "Cable_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x10008310
// Name: public: virtual char const __near * Cable::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Cable::CShader::GetName(Cable::CShader *this)
{
  return s_Name_12;
}

//------------------------------------------------------------------------------
// Address: 0x10008320
// Name: public: virtual int Cable::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Cable::CShader::GetFlags(Cable::CShader *this)
{
  return s_nFlags_53;
}

//------------------------------------------------------------------------------
// Address: 0x10008330
// Name: public: virtual int Cable::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Cable::CShader::GetParamCount(Cable::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_13.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10008340
// Name: public: virtual char const __near * Cable_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Cable_DX9::CShader::GetName(Cable_DX9::CShader *this)
{
  return s_Name_13;
}

//------------------------------------------------------------------------------
// Address: 0x10008350
// Name: public: virtual int Cable_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Cable_DX9::CShader::GetFlags(Cable_DX9::CShader *this)
{
  return s_nFlags_54;
}

//------------------------------------------------------------------------------
// Address: 0x10008360
// Name: public: virtual void Cable_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Cable_DX9::CShader::OnInitShaderInstance(
        Cable_DX9::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadBumpMap(this, nTextureVar: BUMPMAP.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x10008390
// Name: public: virtual void Cable_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Cable_DX9::CShader::OnDrawElements(
        Cable_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v6; // eax
  IMaterialVar **v7; // ebx
  unsigned int v8; // ecx
  void (__thiscall *VertexShaderVertexFormat)(IShaderShadow *, unsigned int, int, int *, int); // edx
  BOOL v10; // edi
  int v11; // eax
  bool v12; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  bool v14; // bl
  CBaseShader *v15; // edi
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v17; // eax
  bool v18; // al
  BOOL v19; // edi
  BOOL v20; // eax
  MaterialFogMode_t v21; // eax
  int v22; // [esp+0h] [ebp-28h]
  float vEyePos_SpecExponent[4]; // [esp+Ch] [ebp-1Ch] BYREF
  cable_ps20b_Dynamic_Index _pshIndex; // [esp+1Ch] [ebp-Ch] BYREF
  CBaseShader *v25; // [esp+24h] [ebp-4h]

  v25 = this;
  v6 = CBaseVSShader::EvaluateBlendRequirements(this, textureVar: 6, isBaseTexture: true, detailTextureVar: -1);
  v7 = params;
  if ( v6 == 3 || v6 == 1 || (v8 = (unsigned int)(*params)->m_intVal >> 8, LOBYTE(params) = 1, (v8 & 1) != 0) )
    LOBYTE(params) = 0;
  if ( pShaderShadow != nullptr )
  {
    if ( ((*v7)->m_intVal & 0x200000) != 0 )
    {
      pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
      pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
      pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    }
    pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: (*v7)->m_intVal & 0x100);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
    _pshIndex.m_nPIXELFOGTYPE = 2;
    _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA = 2;
    VertexShaderVertexFormat(this: pShaderShadow, a2: 53u, a3: 2, a4: &_pshIndex.m_nPIXELFOGTYPE, a5: 0);
    v10 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "cable_vs20", a3: 2 * (v10 + 2 * (v11 < 92)));
    v12 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    SetPixelShader = pShaderShadow->SetPixelShader;
    v22 = 0;
    if ( v12 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "cable_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "cable_ps20b");
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    CBaseShader::FogToFogColor(this: v25);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: (bool)params);
  }
  if ( pShaderAPI == nullptr )
    goto LABEL_33;
  v14 = g_pConfig->nFullbright == 2 && ((*v7)->m_intVal & 2) == 0;
  v15 = v25;
  CBaseShader::BindTexture(
    this: v25,
    sampler1: SHADER_SAMPLER0,
    nBindFlags: TEXTURE_BINDFLAGS_NONE,
    nTextureVar: BUMPMAP.m_Index,
    nFrameVar: -1);
  if ( v14 )
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER1,
      a3: TEXTURE_BINDFLAGS_SRGBREAD,
      a4: TEXTURE_GREY);
  else
    CBaseShader::BindTexture(
      this: v15,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: 6,
      nFrameVar: -1);
  pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
  pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos_SpecExponent);
  SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
  vEyePos_SpecExponent[3] = 0.0;
  SetPixelShaderConstant(this: pShaderAPI, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
  v17 = ((int (__thiscall *)(IShaderDynamicAPI *, int))pShaderAPI->GetSceneFogMode)(a1: pShaderAPI, a2: v22);
  pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v17 == 2);
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
  {
    v21 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v21 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
LABEL_33:
    CBaseShader::Draw(this: v25, bMakeActualDrawCall: true);
    return;
  }
  _pshIndex.m_nPIXELFOGTYPE = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  v18 = (_BYTE)params != 0 && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
  v19 = v18;
  if ( g_shaderConfigDumpEnable )
  {
    v20 = (_BYTE)params != 0 && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    printf(
      format: "\n   PS dyn  var %s = %d (%s)",
      "WRITE_DEPTH_TO_DESTALPHA",
      v20,
      "bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
  }
  pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: _pshIndex.m_nPIXELFOGTYPE + 2 * v19);
  CBaseShader::Draw(this: v25, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10008680
// Name: public: virtual int Cable_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Cable_DX9::CShader::GetParamCount(Cable_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_12.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10008690
// Name: public: virtual struct ShaderParamInfo_t const __near & Cable::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Cable::CShaderParam *__thiscall Cable::CShader::GetParamInfo(Cable::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_13.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Cable::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100086C0
// Name: public: virtual struct ShaderParamInfo_t const __near & Cable_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Cable_DX9::CShaderParam *__thiscall Cable_DX9::CShader::GetParamInfo(Cable_DX9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_12.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Cable_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100086F0
// Name: public: Cable_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Cable_DX9::CShaderParam *__thiscall Cable_DX9::CShaderParam::CShaderParam(
        Cable_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Cable_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Cable_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_12.m_Size + 13;
  m_Size = s_ShaderParams_12.m_Size;
  v8 = s_ShaderParams_12.m_Size;
  if ( s_ShaderParams_12.m_Size + 1 > s_ShaderParams_12.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_12,
      num: s_ShaderParams_12.m_Size - s_ShaderParams_12.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_12.m_Size;
  }
  m_pMemory = s_ShaderParams_12.m_Memory.m_pMemory;
  s_ShaderParams_12.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_12.m_pElements = s_ShaderParams_12.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_12.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_12.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_12.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005EF70
// Name: Cable::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Cable::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Cable::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005EF80
// Name: Cable::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Cable::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_13);
  s_ShaderInstance_13.__vftable = (Cable::CShader_vtbl *)&Cable::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005EFA0
// Name: Cable_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Cable_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Cable_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005EFB0
// Name: Cable_DX9::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
Cable_DX9::CShaderParam *Cable_DX9::_dynamic_initializer_for__BUMPMAP__()
{
  return Cable_DX9::CShaderParam::CShaderParam(
           this: &BUMPMAP,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "cable/cablenormalmap",
           pHelp: "bumpmap texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EFD0
// Name: Cable_DX9::_dynamic_initializer_for__MINLIGHT__
// Source: json
//------------------------------------------------------------------------------
Cable_DX9::CShaderParam *Cable_DX9::_dynamic_initializer_for__MINLIGHT__()
{
  return Cable_DX9::CShaderParam::CShaderParam(
           this: &MINLIGHT,
           pName: "$MINLIGHT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.1",
           pHelp: "Minimum amount of light (0-1 value)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F000
// Name: Cable_DX9::_dynamic_initializer_for__MAXLIGHT__
// Source: json
//------------------------------------------------------------------------------
Cable_DX9::CShaderParam *Cable_DX9::_dynamic_initializer_for__MAXLIGHT__()
{
  return Cable_DX9::CShaderParam::CShaderParam(
           this: &MAXLIGHT,
           pName: "$MAXLIGHT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.3",
           pHelp: "Maximum amount of light",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F020
// Name: Cable_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Cable_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_12);
  s_ShaderInstance_12.__vftable = (Cable_DX9::CShader_vtbl *)&Cable_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AF30
// Name: Cable::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cable::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_13);
}

//------------------------------------------------------------------------------
// Address: 0x1006AF40
// Name: Cable_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cable_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_12);
}
