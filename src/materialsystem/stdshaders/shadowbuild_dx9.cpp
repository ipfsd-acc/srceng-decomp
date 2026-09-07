// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/shadowbuild_dx9.cpp
// Functions: 22
// ============================================================

#include "materialsystem\stdshaders\shadowbuild_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1002DDD0
// Name: public: virtual char const __near * ShadowBuild::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ShadowBuild::CShader::GetFallbackShader(ShadowBuild::CShader *this, IMaterialVar **params)
{
  return "ShadowBuild_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x1002DDE0
// Name: public: virtual char const __near * ShadowBuild::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ShadowBuild::CShader::GetName(ShadowBuild::CShader *this)
{
  return s_Name_102;
}

//------------------------------------------------------------------------------
// Address: 0x1002DDF0
// Name: public: virtual int ShadowBuild::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ShadowBuild::CShader::GetFlags(ShadowBuild::CShader *this)
{
  return s_nFlags_109;
}

//------------------------------------------------------------------------------
// Address: 0x1002DE00
// Name: public: virtual int ShadowBuild::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ShadowBuild::CShader::GetParamCount(ShadowBuild::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_102.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002DE10
// Name: public: virtual void ShadowBuild_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ShadowBuild_DX9::CShader::OnInitShaderParams(
        ShadowBuild_DX9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 2);
}

//------------------------------------------------------------------------------
// Address: 0x1002DE40
// Name: public: virtual char const __near * ShadowBuild_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ShadowBuild_DX9::CShader::GetName(ShadowBuild_DX9::CShader *this)
{
  return s_Name_103;
}

//------------------------------------------------------------------------------
// Address: 0x1002DE50
// Name: public: virtual int ShadowBuild_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ShadowBuild_DX9::CShader::GetFlags(ShadowBuild_DX9::CShader *this)
{
  return s_nFlags_39;
}

//------------------------------------------------------------------------------
// Address: 0x1002DE60
// Name: public: virtual void ShadowBuild_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ShadowBuild_DX9::CShader::OnInitShaderInstance(
        ShadowBuild_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x1002DE90
// Name: public: virtual int ShadowBuild_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ShadowBuild_DX9::CShader::GetParamCount(ShadowBuild_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_103.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002DEA0
// Name: public: virtual void ShadowBuild_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ShadowBuild_DX9::CShader::OnDrawElements(
        ShadowBuild_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  ShadowBuild_DX9::CShader *v6; // ebx
  BOOL v7; // edi
  BOOL v8; // ebx
  bool v9; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  BOOL v11; // edi
  IMaterial *v12; // eax
  int v13; // edi
  int (__thiscall ***v14)(_DWORD); // ecx
  ITexture *v15; // eax
  int v16; // eax
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  int v20; // xmm0_4
  int v21; // xmm1_4
  int v22; // xmm2_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v24; // zf
  IShaderDynamicAPI_vtbl *v25; // eax
  BOOL v26; // edi
  BOOL v27; // ebx
  int v28; // eax
  double v29; // st7
  void (__thiscall *v30)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v31; // edi
  BOOL v32; // ebx
  int v33; // eax
  const char *v34; // [esp-4h] [ebp-34h]
  const char *v35; // [esp-4h] [ebp-34h]
  int v36; // [esp+0h] [ebp-30h]
  float vSubDDimensions[4]; // [esp+Ch] [ebp-24h] BYREF
  float v38; // [esp+1Ch] [ebp-14h] BYREF
  int v39; // [esp+20h] [ebp-10h]
  int v40; // [esp+24h] [ebp-Ch]
  int v41; // [esp+28h] [ebp-8h]
  CBaseShader *v42; // [esp+2Ch] [ebp-4h]
  TessellationMode_t nTessellationMode; // [esp+38h] [ebp+8h]

  v6 = this;
  v42 = this;
  if ( pShaderShadow != nullptr )
  {
    CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->DepthFunc(this: pShaderShadow, a2: SHADER_DEPTHFUNC_ALWAYS);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1025u, a3: 1, a4: nullptr, a5: 0);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x800000);
      v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", 0, "0");
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "unlitgeneric_vs30", a3: 16 * v11);
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "shadowbuildtexture_ps30", a3: 0);
    }
    else
    {
      v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", 0, "0");
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "unlitgeneric_vs20", a3: 16 * (v7 + 2 * v8));
      v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      SetPixelShader = pShaderShadow->SetPixelShader;
      v36 = 0;
      if ( v9 )
        ((void (__thiscall *)(IShaderShadow *, const char *))SetPixelShader)(
          a1: pShaderShadow,
          a2: "shadowbuildtexture_ps20");
      else
        ((void (__thiscall *)(IShaderShadow *, const char *))SetPixelShader)(
          a1: pShaderShadow,
          a2: "shadowbuildtexture_ps20b");
      v6 = (ShadowBuild_DX9::CShader *)v42;
    }
    CBaseShader::PI_BeginCommandBuffer(this: v6);
    CBaseShader::PI_SetModulationVertexShaderDynamicState(this: v6);
    CBaseShader::PI_EndCommandBuffer(this: v6);
  }
  if ( pShaderAPI != nullptr )
  {
    if ( ((unsigned __int8 (__thiscall *)(IMaterialVar *, int))params[TRANSLUCENT_MATERIAL.m_Index]->IsDefined)(
           a1: params[TRANSLUCENT_MATERIAL.m_Index],
           a2: v36) != 0
      && (v12 = params[TRANSLUCENT_MATERIAL.m_Index]->GetMaterialValue(this: params[TRANSLUCENT_MATERIAL.m_Index])) != nullptr
      && (v13 = (int)v12->GetShaderParams(this: v12),
          ((_BYTE)(v14 = *(int (__thiscall ****)(_DWORD))(v13 + 24))[7] & 0xF) == 3)
      && (v15 = (ITexture *)(**v14)(a1: v14)) != nullptr )
    {
      CBaseShader::BindTexture(
        this: v6,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        pTexture: v15,
        nFrame: *(_DWORD *)(*(_DWORD *)(v13 + 28) + 8));
      v16 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v13 + 32) + 84))(a1: *(_DWORD *)(v13 + 32));
      v17 = *(float *)(v16 + 4);
      v18 = *(float *)(v16 + 8);
      v19 = *(float *)(v16 + 12);
      vSubDDimensions[0] = *(float *)v16;
      vSubDDimensions[1] = v17;
      vSubDDimensions[2] = v18;
      vSubDDimensions[3] = v19;
      v20 = *(_DWORD *)(v16 + 20);
      v21 = *(_DWORD *)(v16 + 24);
      v22 = *(_DWORD *)(v16 + 28);
      SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
      v38 = *(float *)(v16 + 16);
      v39 = v20;
      v40 = v21;
      v41 = v22;
      SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: vSubDDimensions, a4: 2, a5: false);
    }
    else
    {
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER0,
        a3: TEXTURE_BINDFLAGS_SRGBREAD,
        a4: TEXTURE_LIGHTMAP_FULLBRIGHT);
    }
    v24 = !g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig);
    v25 = pShaderAPI->__vftable;
    if ( v24 )
    {
      v26 = v25->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v27 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v28 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v28 > 0, v34);
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", 0, "0");
        }
      }
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * (v27 + 2 * v26));
      g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    }
    else
    {
      nTessellationMode = v25->GetTessellationMode(this: pShaderAPI);
      if ( nTessellationMode != TESSELLATION_MODE_DISABLED )
      {
        pShaderAPI->BindStandardVertexTexture(
          this: pShaderAPI,
          a2: SHADER_VERTEXTEXTURE_SAMPLER1,
          a3: TEXTURE_SUBDIVISION_PATCHES);
        v29 = ((double (__thiscall *)(IShaderDynamicAPI *))pShaderAPI->GetSubDHeight)(a1: pShaderAPI);
        v30 = pShaderAPI->SetVertexShaderConstant;
        v39 = 0;
        v40 = 0;
        v41 = 0;
        v38 = 1.0 / v29;
        v30(this: pShaderAPI, a2: 56, a3: &v38, a4: 1, a5: false);
      }
      v31 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v32 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v33 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v33 > 0, v35);
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", nTessellationMode, "nTessellationMode");
        }
      }
      pShaderAPI->SetVertexShaderIndex(
        this: pShaderAPI,
        a2: vertexCompression + 2 * (v32 + 2 * (nTessellationMode + v31)));
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    v6 = (ShadowBuild_DX9::CShader *)v42;
  }
  CBaseShader::Draw(this: v6, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002E370
// Name: public: virtual struct ShaderParamInfo_t const __near & ShadowBuild::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ShadowBuild::CShaderParam *__thiscall ShadowBuild::CShader::GetParamInfo(ShadowBuild::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_102.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ShadowBuild::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002E3A0
// Name: public: virtual struct ShaderParamInfo_t const __near & ShadowBuild_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ShadowBuild_DX9::CShaderParam *__thiscall ShadowBuild_DX9::CShader::GetParamInfo(
        ShadowBuild_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_103.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ShadowBuild_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002E3D0
// Name: public: ShadowBuild_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ShadowBuild_DX9::CShaderParam *__thiscall ShadowBuild_DX9::CShaderParam::CShaderParam(
        ShadowBuild_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  ShadowBuild_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  ShadowBuild_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_103.m_Size + 13;
  m_Size = s_ShaderParams_103.m_Size;
  v8 = s_ShaderParams_103.m_Size;
  if ( s_ShaderParams_103.m_Size + 1 > s_ShaderParams_103.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_103,
      num: s_ShaderParams_103.m_Size - s_ShaderParams_103.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_103.m_Size;
  }
  m_pMemory = s_ShaderParams_103.m_Memory.m_pMemory;
  s_ShaderParams_103.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_103.m_pElements = s_ShaderParams_103.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_103.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_103.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_103.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066190
// Name: ShadowBuild::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ShadowBuild::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ShadowBuild::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100661A0
// Name: ShadowBuild::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ShadowBuild::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_102);
  s_ShaderInstance_102.__vftable = (ShadowBuild::CShader_vtbl *)&ShadowBuild::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100661C0
// Name: ShadowBuild_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ShadowBuild_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ShadowBuild_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100661D0
// Name: ShadowBuild_DX9::_dynamic_initializer_for__TRANSLUCENT_MATERIAL__
// Source: json
//------------------------------------------------------------------------------
ShadowBuild_DX9::CShaderParam *ShadowBuild_DX9::_dynamic_initializer_for__TRANSLUCENT_MATERIAL__()
{
  return ShadowBuild_DX9::CShaderParam::CShaderParam(
           this: &TRANSLUCENT_MATERIAL,
           pName: "$TRANSLUCENT_MATERIAL",
           type: SHADER_PARAM_TYPE_MATERIAL,
           pDefaultParam: pDefaultParam,
           pHelp: "Points to a material to grab translucency from",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100661F0
// Name: ShadowBuild_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ShadowBuild_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_103);
  s_ShaderInstance_103.__vftable = (ShadowBuild_DX9::CShader_vtbl *)&ShadowBuild_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B6E0
// Name: ShadowBuild::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShadowBuild::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_102);
}

//------------------------------------------------------------------------------
// Address: 0x1006B6F0
// Name: ShadowBuild_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShadowBuild_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_103);
}

//------------------------------------------------------------------------------
// Address: 0x10066210
// Name: _dynamic_initializer_for__s_ConstructMe_shadowmodel_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_shadowmodel_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &shadowmodel_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066230
// Name: _dynamic_initializer_for__s_ConstructMe_shadowmodel_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_shadowmodel_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &shadowmodel_vs20_combos);
}
