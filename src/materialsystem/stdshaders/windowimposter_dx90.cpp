// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/windowimposter_dx90.cpp
// Functions: 19
// ============================================================

#include "materialsystem\stdshaders\windowimposter_dx90.h"

//------------------------------------------------------------------------------
// Address: 0x10044410
// Name: public: virtual char const __near * WindowImposter::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WindowImposter::CShader::GetFallbackShader(WindowImposter::CShader *this, IMaterialVar **params)
{
  return "WindowImposter_DX90";
}

//------------------------------------------------------------------------------
// Address: 0x10044420
// Name: public: virtual char const __near * WindowImposter::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WindowImposter::CShader::GetName(WindowImposter::CShader *this)
{
  return s_Name_130;
}

//------------------------------------------------------------------------------
// Address: 0x10044430
// Name: public: virtual int WindowImposter::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WindowImposter::CShader::GetFlags(WindowImposter::CShader *this)
{
  return s_nFlags_132;
}

//------------------------------------------------------------------------------
// Address: 0x10044440
// Name: public: virtual int WindowImposter::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WindowImposter::CShader::GetParamCount(WindowImposter::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_129.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10044450
// Name: public: virtual char const __near * WindowImposter_DX90::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WindowImposter_DX90::CShader::GetName(WindowImposter_DX90::CShader *this)
{
  return s_Name_131;
}

//------------------------------------------------------------------------------
// Address: 0x10044460
// Name: public: virtual int WindowImposter_DX90::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WindowImposter_DX90::CShader::GetFlags(WindowImposter_DX90::CShader *this)
{
  return s_nFlags_133;
}

//------------------------------------------------------------------------------
// Address: 0x10044470
// Name: public: virtual void WindowImposter_DX90::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WindowImposter_DX90::CShader::OnInitShaderInstance(
        WindowImposter_DX90::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadCubeMap(this, nTextureVar: ENVMAP_9.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10044480
// Name: public: virtual void WindowImposter_DX90::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge WindowImposter_DX90::CShader::OnDrawElements(
        WindowImposter_DX90::CShader *this@<ecx>,
        int a2@<edi>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  BOOL v8; // edi
  int v9; // eax
  bool v10; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  int v12; // eax
  MaterialFogMode_t v13; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v15; // [esp+0h] [ebp-18h]
  float vEyePos_SpecExponent[4]; // [esp+8h] [ebp-10h] BYREF

  if ( pShaderShadow != nullptr )
  {
    if ( g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) != HDR_TYPE_NONE )
      pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    ((void (__thiscall *)(IShaderShadow *, _DWORD, int, int))pShaderShadow->EnableTexture)(
      a1: pShaderShadow,
      a2: 0,
      a3: 1,
      a4: a2);
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "windowimposter_vs20", a3: 2 * (v8 + 2 * (v9 < 92)));
    v10 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    SetPixelShader = pShaderShadow->SetPixelShader;
    v15 = 0;
    if ( v10 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "windowimposter_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "windowimposter_ps20b");
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
    pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    CBaseShader::FogToFogColor(this);
    CBaseShader::PI_BeginCommandBuffer(this);
    CBaseShader::PI_SetModulationVertexShaderDynamicState(this);
    CBaseShader::PI_EndCommandBuffer(this);
  }
  if ( pShaderAPI != nullptr )
  {
    v12 = ((int (__thiscall *)(IShaderDynamicAPI *, int))pShaderAPI->GetSceneFogMode)(a1: pShaderAPI, a2: v15);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v12 == 2);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v13 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v13 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos_SpecExponent);
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    vEyePos_SpecExponent[3] = 0.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: ENVMAP_9.m_Index,
      nFrameVar: -1);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10044630
// Name: public: virtual int WindowImposter_DX90::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WindowImposter_DX90::CShader::GetParamCount(WindowImposter_DX90::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_130.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10044640
// Name: public: virtual struct ShaderParamInfo_t const __near & WindowImposter::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
WindowImposter::CShaderParam *__thiscall WindowImposter::CShader::GetParamInfo(
        WindowImposter::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_129.m_Memory.m_pMemory[param - ParamCount];
  else
    return (WindowImposter::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10044670
// Name: public: virtual struct ShaderParamInfo_t const __near & WindowImposter_DX90::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
WindowImposter_DX90::CShaderParam *__thiscall WindowImposter_DX90::CShader::GetParamInfo(
        WindowImposter_DX90::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_130.m_Memory.m_pMemory[param - ParamCount];
  else
    return (WindowImposter_DX90::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100446A0
// Name: public: WindowImposter_DX90::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
WindowImposter_DX90::CShaderParam *__thiscall WindowImposter_DX90::CShaderParam::CShaderParam(
        WindowImposter_DX90::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  WindowImposter_DX90::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  WindowImposter_DX90::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_130.m_Size + 13;
  m_Size = s_ShaderParams_130.m_Size;
  v8 = s_ShaderParams_130.m_Size;
  if ( s_ShaderParams_130.m_Size + 1 > s_ShaderParams_130.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_130,
      num: s_ShaderParams_130.m_Size - s_ShaderParams_130.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_130.m_Size;
  }
  m_pMemory = s_ShaderParams_130.m_Memory.m_pMemory;
  s_ShaderParams_130.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_130.m_pElements = s_ShaderParams_130.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_130.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_130.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_130.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006A3A0
// Name: WindowImposter::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int WindowImposter::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: WindowImposter::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006A3B0
// Name: WindowImposter::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *WindowImposter::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_130);
  s_ShaderInstance_130.__vftable = (WindowImposter::CShader_vtbl *)&WindowImposter::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006A3D0
// Name: WindowImposter_DX90::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int WindowImposter_DX90::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: WindowImposter_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006A3E0
// Name: WindowImposter_DX90::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
WindowImposter_DX90::CShaderParam *WindowImposter_DX90::_dynamic_initializer_for__ENVMAP__()
{
  return WindowImposter_DX90::CShaderParam::CShaderParam(
           this: &ENVMAP_9,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_env",
           pHelp: "envmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A400
// Name: WindowImposter_DX90::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *WindowImposter_DX90::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_131);
  s_ShaderInstance_131.__vftable = (WindowImposter_DX90::CShader_vtbl *)&WindowImposter_DX90::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B920
// Name: WindowImposter::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl WindowImposter::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_129);
}

//------------------------------------------------------------------------------
// Address: 0x1006B930
// Name: WindowImposter_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl WindowImposter_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_130);
}
