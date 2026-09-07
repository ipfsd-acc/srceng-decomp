// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/debugnormalmap.cpp
// Functions: 16
// ============================================================

#include "materialsystem\stdshaders\debugnormalmap.h"

//------------------------------------------------------------------------------
// Address: 0x10001930
// Name: public: virtual char const __near * DebugNormalMap::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DebugNormalMap::CShader::GetName(DebugNormalMap::CShader *this)
{
  return s_Name_2;
}

//------------------------------------------------------------------------------
// Address: 0x10001940
// Name: public: virtual int DebugNormalMap::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugNormalMap::CShader::GetFlags(DebugNormalMap::CShader *this)
{
  return s_nFlags_2;
}

//------------------------------------------------------------------------------
// Address: 0x10001950
// Name: public: virtual void DebugNormalMap::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DebugNormalMap::CShader::OnInitShaderInstance(
        DebugDepth::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001960
// Name: public: virtual int DebugNormalMap::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugNormalMap::CShader::GetParamCount(DebugNormalMap::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_2.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001970
// Name: public: virtual void DebugNormalMap::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DebugNormalMap::CShader::OnDrawElements(
        DebugNormalMap::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v6; // zf
  int (*GetDXSupportLevel)(void); // edx
  BOOL v8; // edi
  BOOL v9; // ebx
  bool v10; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  BOOL v12; // edi
  BOOL v13; // edi
  BOOL v14; // ebx
  int v15; // eax
  double v16; // st7
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v18; // edi
  BOOL v19; // ebx
  int v20; // eax
  const char *v21; // [esp-4h] [ebp-24h]
  const char *v22; // [esp-4h] [ebp-24h]
  int v23; // [esp+0h] [ebp-20h]
  float vSubDDimensions[4]; // [esp+Ch] [ebp-14h] BYREF
  CBaseShader *v25; // [esp+1Ch] [ebp-4h]
  TessellationMode_t nTessellationMode; // [esp+2Ch] [ebp+Ch]

  v25 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1025u, a3: 1, a4: nullptr, a5: 0);
    v6 = !g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig);
    GetDXSupportLevel = (int (*)(void))g_pHardwareConfig->GetDXSupportLevel;
    if ( v6 )
    {
      v8 = GetDXSupportLevel() >= 92;
      v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", 0, "0");
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "unlitgeneric_vs20", a3: 16 * (v8 + 2 * v9));
      v10 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      SetPixelShader = pShaderShadow->SetPixelShader;
      v23 = 0;
      if ( v10 )
        ((void (__thiscall *)(IShaderShadow *, const char *))SetPixelShader)(a1: pShaderShadow, a2: "unlitgeneric_ps20");
      else
        ((void (__thiscall *)(IShaderShadow *, const char *))SetPixelShader)(
          a1: pShaderShadow,
          a2: "unlitgeneric_ps20b");
    }
    else
    {
      v12 = GetDXSupportLevel() >= 92;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", 0, "0");
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "unlitgeneric_vs30", a3: 16 * v12);
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "unlitgeneric_ps30", a3: 0);
    }
  }
  if ( pShaderAPI != nullptr )
  {
    if ( (*((_BYTE *)params[BUMPMAP.m_Index] + 28) & 0xF) == 3 )
      CBaseShader::BindTexture(
        this: v25,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: BUMPMAP.m_Index,
        nFrameVar: BUMPFRAME.m_Index);
    else
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER0,
        a3: TEXTURE_BINDFLAGS_NONE,
        a4: TEXTURE_NORMALMAP_FLAT);
    CBaseVSShader::SetVertexShaderTextureTransform(
      this: (CBaseVSShader *)v25,
      vertexReg: 48,
      transformVar: BUMPTRANSFORM.m_Index);
    if ( ((unsigned __int8 (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->HasFastVertexTextures)(
           a1: g_pHardwareConfig,
           a2: v23) != 0 )
    {
      nTessellationMode = pShaderAPI->GetTessellationMode(this: pShaderAPI);
      if ( nTessellationMode != TESSELLATION_MODE_DISABLED )
      {
        pShaderAPI->BindStandardVertexTexture(
          this: pShaderAPI,
          a2: SHADER_VERTEXTEXTURE_SAMPLER1,
          a3: TEXTURE_SUBDIVISION_PATCHES);
        v16 = ((double (__thiscall *)(IShaderDynamicAPI *))pShaderAPI->GetSubDHeight)(a1: pShaderAPI);
        SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
        memset(&vSubDDimensions[1], 0, 12);
        vSubDDimensions[0] = 1.0 / v16;
        SetVertexShaderConstant(this: pShaderAPI, a2: 56, a3: vSubDDimensions, a4: 1, a5: false);
      }
      v18 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v19 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v20 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v20 > 0, v22);
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
        a2: vertexCompression + 2 * (v19 + 2 * (nTessellationMode + v18)));
    }
    else
    {
      v13 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v14 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v15 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v15 > 0, v21);
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
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * (v14 + 2 * v13));
      g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this: v25, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10001D00
// Name: public: virtual struct ShaderParamInfo_t const __near & DebugNormalMap::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DebugNormalMap::CShaderParam *__thiscall DebugNormalMap::CShader::GetParamInfo(
        DebugNormalMap::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_2.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DebugNormalMap::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10001D30
// Name: public: DebugNormalMap::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DebugNormalMap::CShaderParam *__thiscall DebugNormalMap::CShaderParam::CShaderParam(
        DebugNormalMap::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  DebugNormalMap::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  DebugNormalMap::CShaderParam **v11; // eax

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
    CUtlMemory<DebugDrawEnvmapMask::CShaderParam *,int>::Grow(
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
// Address: 0x100169F0
// Name: DebugNormalMap::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DebugNormalMap::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DebugNormalMap::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10016A00
// Name: DebugNormalMap::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
DebugNormalMap::CShaderParam *DebugNormalMap::_dynamic_initializer_for__BUMPMAP__()
{
  return DebugNormalMap::CShaderParam::CShaderParam(
           this: &BUMPMAP,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/WorldDiffuseBumpMap_bump",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016A20
// Name: DebugNormalMap::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
DebugNormalMap::CShaderParam *DebugNormalMap::_dynamic_initializer_for__BUMPFRAME__()
{
  return DebugNormalMap::CShaderParam::CShaderParam(
           this: &BUMPFRAME,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016A40
// Name: DebugNormalMap::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
DebugNormalMap::CShaderParam *DebugNormalMap::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return DebugNormalMap::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016A60
// Name: DebugNormalMap::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DebugNormalMap::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_2);
  s_ShaderInstance_2.__vftable = (DebugNormalMap::CShader_vtbl *)&DebugNormalMap::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016D70
// Name: DebugNormalMap::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugNormalMap::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>::~CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_2);
}

//------------------------------------------------------------------------------
// Address: 0x10016A80
// Name: _dynamic_initializer_for__s_ConstructMe_debugtangentspace_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugtangentspace_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugtangentspace_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10016AA0
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_notexture_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_notexture_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_notexture_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10016AC0
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_notexture_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_notexture_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_notexture_ps20b_combos);
}
