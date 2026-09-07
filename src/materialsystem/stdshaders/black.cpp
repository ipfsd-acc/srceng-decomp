// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/black.cpp
// Functions: 9
// ============================================================

#include "materialsystem\stdshaders\black.h"

//------------------------------------------------------------------------------
// Address: 0x100047C0
// Name: public: virtual void Black::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Black::CShader::OnInitShaderParams(
        Black::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x80000000);
}

//------------------------------------------------------------------------------
// Address: 0x10004800
// Name: public: virtual char const __near * Black::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Black::CShader::GetName(Black::CShader *this)
{
  return s_Name_4;
}

//------------------------------------------------------------------------------
// Address: 0x10004810
// Name: public: virtual int Black::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Black::CShader::GetFlags(Black::CShader *this)
{
  return s_nFlags_49;
}

//------------------------------------------------------------------------------
// Address: 0x10004820
// Name: public: virtual void Black::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge Black::CShader::OnDrawElements(
        Black::CShader *this@<ecx>,
        int a2@<edi>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        float pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IShaderShadow *v7; // esi
  int v9; // eax
  bool v10; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  IShaderDynamicAPI *v12; // esi
  BOOL v13; // edi
  int v14; // eax
  double v15; // st7
  double v16; // st7
  double v17; // st7
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const char *flSrgbGammaValue; // [esp+30h] [ebp-1Ch]
  Vector4D fogColorPostTonemapLinearSpace; // [esp+3Ch] [ebp-10h] BYREF

  v7 = pShaderShadow;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1025u, a3: 1, a4: nullptr, a5: 0);
    v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v7->SetVertexShader(this: v7, a2: "black_vs20", a3: 2 * (v9 < 92));
    v10 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    SetPixelShader = v7->SetPixelShader;
    if ( v10 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "black_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "black_ps20b");
    v7->EnableSRGBWrite(this: v7, a2: true);
    CBaseShader::FogToFogColor(this);
  }
  v12 = (IShaderDynamicAPI *)LODWORD(pShaderAPI);
  if ( pShaderAPI != 0.0 )
  {
    v13 = ((int (__thiscall *)(IShaderDynamicAPI *, int))CBaseShader::s_pShaderAPI->GetCurrentNumBones)(
            a1: CBaseShader::s_pShaderAPI,
            a2) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v14 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))CBaseShader::s_pShaderAPI->GetCurrentNumBones)(
              a1: CBaseShader::s_pShaderAPI,
              a2: "s_pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v14 > 0, flSrgbGammaValue);
    }
    v12->SetVertexShaderIndex(this: v12, a2: v13);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v12->SetPixelShaderIndex(this: v12, a2: 0);
    v12->GetSceneFogColor(this: v12, a2: (unsigned __int8 *)&pShaderShadow);
    pShaderAPI = v12->GetToneMappingScaleLinear(this: v12)->x;
    v15 = SrgbGammaToLinear(flSrgbGammaValue: (float)(unsigned __int8)pShaderShadow * 0.0039215689);
    fogColorPostTonemapLinearSpace.x = v15 * pShaderAPI;
    v16 = SrgbGammaToLinear(flSrgbGammaValue: (float)BYTE1(pShaderShadow) * 0.0039215689);
    fogColorPostTonemapLinearSpace.y = v16 * pShaderAPI;
    v17 = SrgbGammaToLinear(flSrgbGammaValue: (float)BYTE2(pShaderShadow) * 0.0039215689);
    SetVertexShaderConstant = v12->SetVertexShaderConstant;
    fogColorPostTonemapLinearSpace.z = v17 * pShaderAPI;
    fogColorPostTonemapLinearSpace.w = 1.0;
    SetVertexShaderConstant(this: v12, a2: 48, a3: &fogColorPostTonemapLinearSpace.x, a4: 1, a5: false);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100049E0
// Name: public: virtual int Black::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Black::CShader::GetParamCount(Black::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_4.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100049F0
// Name: public: virtual struct ShaderParamInfo_t const __near & Black::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Black::CShaderParam *__thiscall Black::CShader::GetParamInfo(Black::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_4.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Black::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1005E450
// Name: Black::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Black::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Black::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005E460
// Name: Black::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Black::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_4);
  s_ShaderInstance_4.__vftable = (Black::CShader_vtbl *)&Black::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AEB0
// Name: Black::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Black::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_4);
}
