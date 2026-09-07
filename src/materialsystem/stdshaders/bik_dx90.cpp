// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/bik_dx90.cpp
// Functions: 16
// ============================================================

#include "materialsystem\stdshaders\bik_dx90.h"

//------------------------------------------------------------------------------
// Address: 0x10004410
// Name: public: virtual char const __near * Bik::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Bik::CShader::GetName(Bik::CShader *this)
{
  return s_Name_3;
}

//------------------------------------------------------------------------------
// Address: 0x10004420
// Name: public: virtual int Bik::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Bik::CShader::GetFlags(Bik::CShader *this)
{
  return s_nFlags_48;
}

//------------------------------------------------------------------------------
// Address: 0x10004430
// Name: public: virtual void Bik::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Bik::CShader::OnInitShaderInstance(
        Bik::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[YTEXTURE.m_Index]->IsDefined(this: params[YTEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: YTEXTURE.m_Index, nAdditionalCreationFlags: 0);
  if ( params[CRTEXTURE.m_Index]->IsDefined(this: params[CRTEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: CRTEXTURE.m_Index, nAdditionalCreationFlags: 0);
  if ( params[CBTEXTURE.m_Index]->IsDefined(this: params[CBTEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: CBTEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100044B0
// Name: public: virtual void Bik::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge Bik::CShader::OnDrawElements(
        Bik::CShader *this@<ecx>,
        int a2@<ebx>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  BOOL v9; // ebx
  int v10; // eax
  MaterialFogMode_t v11; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  MaterialFogMode_t v13; // eax
  float vEyePos_SpecExponent[4]; // [esp+8h] [ebp-10h] BYREF
  bool bHasVertexAlpha_3; // [esp+27h] [ebp+Fh]

  if ( pShaderShadow != nullptr )
  {
    ((void (__thiscall *)(IShaderShadow *, _DWORD, int, int))pShaderShadow->EnableTexture)(
      a1: pShaderShadow,
      a2: 0,
      a3: 1,
      a4: a2);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    bHasVertexAlpha_3 = ((*params)->m_intVal & 0x20) != 0;
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 5u, a3: 1, a4: nullptr, a5: 0);
    v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v10 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "bik_vs20", a3: 2 * (v9 + 2 * (v10 < 92)));
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXALPHA", bHasVertexAlpha_3, "bHasVertexAlpha");
      ((void (__thiscall *)(IShaderShadow *, const char *))pShaderShadow->SetPixelShader)(
        a1: pShaderShadow,
        a2: "bik_ps20");
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXALPHA", bHasVertexAlpha_3, "bHasVertexAlpha");
      ((void (__thiscall *)(IShaderShadow *, const char *))pShaderShadow->SetPixelShader)(
        a1: pShaderShadow,
        a2: "bik_ps20b");
    }
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: false);
    if ( bHasVertexAlpha_3 )
      CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: YTEXTURE.m_Index,
      nFrameVar: 7);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: CRTEXTURE.m_Index,
      nFrameVar: 7);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: CBTEXTURE.m_Index,
      nFrameVar: 7);
    CBaseVSShader::LoadViewMatrixIntoVertexShaderConstant(this, vertexReg: 17);
    v11 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v11 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos_SpecExponent);
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    vEyePos_SpecExponent[3] = 0.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v13 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v13 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100046E0
// Name: public: virtual int Bik::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Bik::CShader::GetParamCount(Bik::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_3.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100046F0
// Name: public: virtual struct ShaderParamInfo_t const __near & Bik::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Bik::CShaderParam *__thiscall Bik::CShader::GetParamInfo(Bik::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_3.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Bik::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10004720
// Name: public: Bik::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Bik::CShaderParam *__thiscall Bik::CShaderParam::CShaderParam(
        Bik::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Bik::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Bik::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_3.m_Size + 13;
  m_Size = s_ShaderParams_3.m_Size;
  v8 = s_ShaderParams_3.m_Size;
  if ( s_ShaderParams_3.m_Size + 1 > s_ShaderParams_3.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_3,
      num: s_ShaderParams_3.m_Size - s_ShaderParams_3.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_3.m_Size;
  }
  m_pMemory = s_ShaderParams_3.m_Memory.m_pMemory;
  s_ShaderParams_3.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_3.m_pElements = s_ShaderParams_3.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_3.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_3.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_3.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005E360
// Name: Bik::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Bik::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Bik::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005E370
// Name: Bik::_dynamic_initializer_for__YTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Bik::CShaderParam *Bik::_dynamic_initializer_for__YTEXTURE__()
{
  return Bik::CShaderParam::CShaderParam(
           this: &YTEXTURE,
           pName: "$YTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Y Bink Texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E390
// Name: Bik::_dynamic_initializer_for__CRTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Bik::CShaderParam *Bik::_dynamic_initializer_for__CRTEXTURE__()
{
  return Bik::CShaderParam::CShaderParam(
           this: &CRTEXTURE,
           pName: "$CRTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Cr Bink Texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E3B0
// Name: Bik::_dynamic_initializer_for__CBTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Bik::CShaderParam *Bik::_dynamic_initializer_for__CBTEXTURE__()
{
  return Bik::CShaderParam::CShaderParam(
           this: &CBTEXTURE,
           pName: "$CBTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Cb Bink Texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E3D0
// Name: Bik::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Bik::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_3);
  s_ShaderInstance_3.__vftable = (Bik::CShader_vtbl *)&Bik::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AEA0
// Name: Bik::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bik::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_3);
}

//------------------------------------------------------------------------------
// Address: 0x1005E3F0
// Name: _dynamic_initializer_for__s_ConstructMe_black_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_black_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &black_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E410
// Name: _dynamic_initializer_for__s_ConstructMe_black_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_black_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &black_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005E430
// Name: _dynamic_initializer_for__s_ConstructMe_black_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_black_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &black_ps20b_combos);
}
