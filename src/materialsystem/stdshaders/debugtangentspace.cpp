// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/debugtangentspace.cpp
// Functions: 16
// ============================================================

#include "materialsystem\stdshaders\debugtangentspace.h"

//------------------------------------------------------------------------------
// Address: 0x10001DD0
// Name: public: virtual char const __near * DebugTangentSpace::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DebugTangentSpace::CShader::GetName(DebugTangentSpace::CShader *this)
{
  return s_Name_3;
}

//------------------------------------------------------------------------------
// Address: 0x10001DE0
// Name: public: virtual int DebugTangentSpace::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugTangentSpace::CShader::GetFlags(DebugTangentSpace::CShader *this)
{
  return s_nFlags_4;
}

//------------------------------------------------------------------------------
// Address: 0x10001DF0
// Name: public: virtual void DebugTangentSpace::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge DebugTangentSpace::CShader::OnDrawElements(
        DebugTangentSpace::CShader *this@<ecx>,
        int a2@<ebx>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  BOOL v7; // edi
  int v8; // eax
  bool v9; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  BOOL v11; // edi
  BOOL v12; // ebx
  int v13; // eax
  const char *v14; // [esp-4h] [ebp-10h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 0, a4: nullptr, a5: 4);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "debugtangentspace_vs20", a3: 8 * (v7 + 2 * (v8 < 92)));
    v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    SetPixelShader = pShaderShadow->SetPixelShader;
    if ( v9 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "unlitgeneric_notexture_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "unlitgeneric_notexture_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    v11 = ((int (__thiscall *)(IShaderDynamicAPI *, int))pShaderAPI->GetSceneFogMode)(a1: pShaderAPI, a2) == 2;
    v12 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v13 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v13 > 0, v14);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * (v11 + 2 * v12));
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10001F50
// Name: public: virtual int DebugTangentSpace::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugTangentSpace::CShader::GetParamCount(DebugTangentSpace::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_3.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001F60
// Name: public: virtual struct ShaderParamInfo_t const __near & DebugTangentSpace::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DebugTangentSpace::CShaderParam *__thiscall DebugTangentSpace::CShader::GetParamInfo(
        DebugTangentSpace::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_3.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DebugTangentSpace::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10016AE0
// Name: DebugTangentSpace::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DebugTangentSpace::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DebugTangentSpace::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10016AF0
// Name: DebugTangentSpace::_dynamic_initializer_for__BASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
void DebugTangentSpace::_dynamic_initializer_for__BASETEXTURE__()
{
  s_pShaderParamOverrides[6] = &BASETEXTURE;
}

//------------------------------------------------------------------------------
// Address: 0x10016B00
// Name: DebugTangentSpace::_dynamic_initializer_for__FRAME__
// Source: json
//------------------------------------------------------------------------------
void DebugTangentSpace::_dynamic_initializer_for__FRAME__()
{
  s_pShaderParamOverrides[7] = &FRAME;
}

//------------------------------------------------------------------------------
// Address: 0x10016B10
// Name: DebugTangentSpace::_dynamic_initializer_for__BASETEXTURETRANSFORM__
// Source: json
//------------------------------------------------------------------------------
void DebugTangentSpace::_dynamic_initializer_for__BASETEXTURETRANSFORM__()
{
  s_pShaderParamOverrides[8] = &BASETEXTURETRANSFORM;
}

//------------------------------------------------------------------------------
// Address: 0x10016B20
// Name: DebugTangentSpace::_dynamic_initializer_for__COLOR__
// Source: json
//------------------------------------------------------------------------------
void DebugTangentSpace::_dynamic_initializer_for__COLOR__()
{
  s_pShaderParamOverrides[4] = &COLOR;
}

//------------------------------------------------------------------------------
// Address: 0x10016B30
// Name: DebugTangentSpace::_dynamic_initializer_for__ALPHA__
// Source: json
//------------------------------------------------------------------------------
void DebugTangentSpace::_dynamic_initializer_for__ALPHA__()
{
  s_pShaderParamOverrides[5] = &ALPHA_0;
}

//------------------------------------------------------------------------------
// Address: 0x10016B40
// Name: DebugTangentSpace::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DebugTangentSpace::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_3);
  s_ShaderInstance_3.__vftable = (DebugTangentSpace::CShader_vtbl *)&DebugTangentSpace::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016D80
// Name: DebugTangentSpace::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugTangentSpace::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>::~CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_3);
}

//------------------------------------------------------------------------------
// Address: 0x10016B60
// Name: _dynamic_initializer_for__s_ConstructMe_fillrate_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_fillrate_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &fillrate_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10016B80
// Name: _dynamic_initializer_for__s_ConstructMe_fillrate_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_fillrate_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &fillrate_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10016BA0
// Name: _dynamic_initializer_for__s_ConstructMe_fillrate_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_fillrate_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &fillrate_ps20b_combos);
}
