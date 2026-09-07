// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/worldimposter.cpp
// Functions: 17
// ============================================================

#include "materialsystem\stdshaders\worldimposter.h"

//------------------------------------------------------------------------------
// Address: 0x10044A10
// Name: public: virtual char const __near * worldimposter::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall worldimposter::CShader::GetName(worldimposter::CShader *this)
{
  return s_Name_134;
}

//------------------------------------------------------------------------------
// Address: 0x10044A20
// Name: public: virtual int worldimposter::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall worldimposter::CShader::GetFlags(worldimposter::CShader *this)
{
  return s_nFlags_136;
}

//------------------------------------------------------------------------------
// Address: 0x10044A30
// Name: public: virtual void worldimposter::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall worldimposter::CShader::OnInitShaderInstance(
        worldimposter::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: BASETEXTURE_4.m_Index, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadTexture(this, nTextureVar: ALBEDO_2.m_Index, nAdditionalCreationFlags: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x10044A60
// Name: public: virtual void worldimposter::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall worldimposter::CShader::OnDrawElements(
        worldimposter::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        ITexture *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  worldimposter::CShader *v6; // edi
  int v7; // eax
  ShadowFilterMode_t v8; // ebx
  ITexture *v9; // ebx
  CBaseVSShader *v10; // esi
  int (__thiscall *GetNumAnimationFrames)(ITexture *); // edx
  int (__thiscall *v12)(ITexture *); // edx
  bool v13; // al
  float m_flShadowAtten; // xmm0_4
  BOOL v15; // esi
  int v16; // eax
  BOOL v17; // edi
  CBaseShader *v18; // esi
  const char *v19; // [esp+A0h] [ebp-190h]
  VMatrix worldToTexture; // [esp+B0h] [ebp-180h] BYREF
  FlashlightState_t flashlightState; // [esp+F0h] [ebp-140h]
  int nTexHeight; // [esp+1ECh] [ebp-44h] BYREF
  int nWidth; // [esp+1F0h] [ebp-40h] BYREF
  int nHeight; // [esp+1F4h] [ebp-3Ch] BYREF
  int nTexWidth; // [esp+1F8h] [ebp-38h] BYREF
  float pos[4]; // [esp+1FCh] [ebp-34h] BYREF
  float tweaks[4]; // [esp+20Ch] [ebp-24h] BYREF
  float atten[4]; // [esp+21Ch] [ebp-14h] BYREF
  CBaseShader *v29; // [esp+22Ch] [ebp-4h]
  bool bHasFlashlight_3; // [esp+23Bh] [ebp+Bh]
  bool bFlashlightShadows_3; // [esp+23Fh] [ebp+Fh]

  v6 = this;
  v29 = this;
  bHasFlashlight_3 = CBaseShader::UsingFlashlight(this, params);
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "worldimposter_vs20", a3: 8 * (v7 < 92));
    v8 = SHADOWFILTERMODE_DEFAULT;
    if ( bHasFlashlight_3 )
      v8 = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: true, a3: false);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "worldimposter_ps20", a3: 0);
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHTDEPTHFILTERMODE", v8, "nShadowFilterMode");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "worldimposter_ps20b", a3: 4 * v8);
    }
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    if ( bHasFlashlight_3 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    }
    CBaseShader::FogToFogColor(this: v6);
  }
  v9 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    bFlashlightShadows_3 = false;
    if ( bHasFlashlight_3 )
    {
      flashlightState = *(FlashlightState_t *)((int (__thiscall *)(ITexture *, VMatrix *, ITexture **))pShaderAPI->SetActiveSubTarget)(
                                                a1: pShaderAPI,
                                                a2: &worldToTexture,
                                                a3: &pShaderAPI);
      v10 = (CBaseVSShader *)v29;
      bFlashlightShadows_3 = flashlightState.m_bEnableShadows;
      CBaseShader::BindTexture(
        this: v29,
        sampler1: SHADER_SAMPLER4,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        pTexture: flashlightState.m_pSpotlightTexture,
        nFrame: flashlightState.m_nSpotlightTextureFrame);
      if ( pShaderAPI != nullptr && g_pConfig->m_bShadowDepthTexture && bFlashlightShadows_3 )
      {
        CBaseShader::BindTexture(
          this: v10,
          sampler1: SHADER_SAMPLER2,
          nBindFlags: TEXTURE_BINDFLAGS_SHADOWDEPTH,
          pTexture: pShaderAPI,
          nFrame: 0);
        ((void (__thiscall *)(ITexture *, int, _DWORD, int))v9->IsCubeMap)(a1: v9, a2: 3, a3: 0, a4: 20);
      }
      GetNumAnimationFrames = v9->GetNumAnimationFrames;
      atten[0] = flashlightState.m_fConstantAtten;
      atten[1] = flashlightState.m_fLinearAtten;
      atten[2] = flashlightState.m_fQuadraticAtten;
      atten[3] = flashlightState.m_FarZAtten;
      ((void (__thiscall *)(ITexture *, _DWORD, float *, int, _DWORD))GetNumAnimationFrames)(
        a1: v9,
        a2: 0,
        a3: atten,
        a4: 1,
        a5: 0);
      v12 = v9->GetNumAnimationFrames;
      *(Vector *)pos = flashlightState.m_vecLightOrigin;
      pos[3] = flashlightState.m_FarZ;
      ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v12)(a1: v9, a2: 1, a3: pos, a4: 1, a5: 0);
      ((void (__thiscall *)(ITexture *, int, VMatrix *, int, _DWORD))v9->GetNumAnimationFrames)(
        a1: v9,
        a2: 2,
        a3: &worldToTexture,
        a4: 4,
        a5: 0);
      tweaks[0] = flashlightState.m_flShadowFilterSize * 0.0009765625;
      v13 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
      m_flShadowAtten = flashlightState.m_flShadowAtten;
      if ( v13 )
        m_flShadowAtten = flashlightState.m_flShadowAtten * 0.1;
      tweaks[1] = m_flShadowAtten;
      CBaseVSShader::HashShadow2DJitter(
        this: v10,
        fJitterSeed: flashlightState.m_flShadowJitterSeed,
        fU: &tweaks[2],
        fV: &tweaks[3]);
      ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v9->GetNumAnimationFrames)(
        a1: v9,
        a2: 6,
        a3: tweaks,
        a4: 1,
        a5: 0);
      v9->Download(this: v9, a2: (Rect_t *)&nWidth, a3: (int)&nHeight);
      ((void (__thiscall *)(ITexture *, int *, int *, int))v9->__vftable[1].GetActualHeight)(
        a1: v9,
        a2: &nTexWidth,
        a3: &nTexHeight,
        a4: 20);
    }
    v15 = CBaseShader::s_pShaderAPI->GetCurrentNumBones(this: CBaseShader::s_pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v16 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))CBaseShader::s_pShaderAPI->GetCurrentNumBones)(
              a1: CBaseShader::s_pShaderAPI,
              a2: "s_pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v16 > 0, v19);
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "COMPRESSED_VERTS",
          vertexCompression,
          "( int )vertexCompression");
    }
    v17 = bHasFlashlight_3;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "FLASHLIGHT", bHasFlashlight_3, "bHasFlashlight");
    ((void (__thiscall *)(ITexture *, __int32))v9->DecrementReferenceCount)(
      a1: v9,
      a2: v15 + 2 * (vertexCompression + 2 * v17));
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHT", bHasFlashlight_3, "bHasFlashlight");
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHTSHADOWS", bFlashlightShadows_3, "bFlashlightShadows");
    ((void (__thiscall *)(ITexture *, int))v9->SetTextureRegenerator)(a1: v9, a2: v17 + 2 * bFlashlightShadows_3);
    v18 = v29;
    CBaseShader::BindTexture(
      this: v29,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: BASETEXTURE_4.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: v18,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: ALBEDO_2.m_Index,
      nFrameVar: -1);
    v6 = (worldimposter::CShader *)v18;
  }
  CBaseShader::Draw(this: v6, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10044ED0
// Name: public: virtual int worldimposter::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall worldimposter::CShader::GetParamCount(worldimposter::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_133.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10044EE0
// Name: public: virtual struct ShaderParamInfo_t const __near & worldimposter::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
worldimposter::CShaderParam *__thiscall worldimposter::CShader::GetParamInfo(worldimposter::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_133.m_Memory.m_pMemory[param - ParamCount];
  else
    return (worldimposter::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10044F10
// Name: public: worldimposter::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
worldimposter::CShaderParam *__thiscall worldimposter::CShaderParam::CShaderParam(
        worldimposter::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  worldimposter::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  worldimposter::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_133.m_Size + 13;
  m_Size = s_ShaderParams_133.m_Size;
  v8 = s_ShaderParams_133.m_Size;
  if ( s_ShaderParams_133.m_Size + 1 > s_ShaderParams_133.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_133,
      num: s_ShaderParams_133.m_Size - s_ShaderParams_133.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_133.m_Size;
  }
  m_pMemory = s_ShaderParams_133.m_Memory.m_pMemory;
  s_ShaderParams_133.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_133.m_pElements = s_ShaderParams_133.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_133.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_133.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_133.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006A520
// Name: worldimposter::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int worldimposter::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: worldimposter::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006A530
// Name: worldimposter::_dynamic_initializer_for__BASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
worldimposter::CShaderParam *worldimposter::_dynamic_initializer_for__BASETEXTURE__()
{
  return worldimposter::CShaderParam::CShaderParam(
           this: &BASETEXTURE_4,
           pName: "$BASETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A550
// Name: worldimposter::_dynamic_initializer_for__ALBEDO__
// Source: json
//------------------------------------------------------------------------------
worldimposter::CShaderParam *worldimposter::_dynamic_initializer_for__ALBEDO__()
{
  return worldimposter::CShaderParam::CShaderParam(
           this: &ALBEDO_2,
           pName: "$ALBEDO",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A570
// Name: worldimposter::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *worldimposter::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_134);
  s_ShaderInstance_134.__vftable = (worldimposter::CShader_vtbl *)&worldimposter::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B960
// Name: worldimposter::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl worldimposter::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_133);
}

//------------------------------------------------------------------------------
// Address: 0x1006A590
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedgeneric_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006A5B0
// Name: _dynamic_initializer_for__s_ConstructMe_worldtwotextureblend_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_worldtwotextureblend_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &worldtwotextureblend_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006A5D0
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_vs20___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_vs20___1()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedgeneric_vs20_combos_1);
}

//------------------------------------------------------------------------------
// Address: 0x1006A5F0
// Name: _dynamic_initializer_for__s_ConstructMe_WorldTwoTextureBlend_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_WorldTwoTextureBlend_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &WorldTwoTextureBlend_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006A610
// Name: _dynamic_initializer_for__s_ConstructMe_WorldTwoTextureBlend_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_WorldTwoTextureBlend_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &WorldTwoTextureBlend_ps20b_combos);
}
