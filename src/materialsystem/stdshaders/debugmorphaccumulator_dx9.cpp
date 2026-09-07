// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/debugmorphaccumulator_dx9.cpp
// Functions: 12
// ============================================================

#include "materialsystem\stdshaders\debugmorphaccumulator_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1000A3B0
// Name: public: virtual char const __near * DebugMorphAccumulator::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DebugMorphAccumulator::CShader::GetName(DebugMorphAccumulator::CShader *this)
{
  return s_Name_17;
}

//------------------------------------------------------------------------------
// Address: 0x1000A3C0
// Name: public: virtual int DebugMorphAccumulator::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugMorphAccumulator::CShader::GetFlags(DebugMorphAccumulator::CShader *this)
{
  return s_nFlags_6;
}

//------------------------------------------------------------------------------
// Address: 0x1000A3D0
// Name: public: virtual void DebugMorphAccumulator::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DebugMorphAccumulator::CShader::OnDrawElements(
        DebugMorphAccumulator::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->FogMode(this: pShaderShadow, a2: SHADER_FOGMODE_DISABLED, a3: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: false);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "debugmorphaccumulator_vs30", a3: 0);
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "debugmorphaccumulator_ps30", a3: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000A490
// Name: public: virtual int DebugMorphAccumulator::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugMorphAccumulator::CShader::GetParamCount(DebugMorphAccumulator::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_17.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000A4A0
// Name: public: virtual struct ShaderParamInfo_t const __near & DebugMorphAccumulator::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DebugMorphAccumulator::CShaderParam *__thiscall DebugMorphAccumulator::CShader::GetParamInfo(
        DebugMorphAccumulator::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_17.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DebugMorphAccumulator::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000C830
// Name: public: virtual void DebugMorphAccumulator::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DebugMorphAccumulator::CShader::OnInitShaderInstance(
        DebugMorphAccumulator::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F6E0
// Name: DebugMorphAccumulator::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DebugMorphAccumulator::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DebugMorphAccumulator::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005F6F0
// Name: DebugMorphAccumulator::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DebugMorphAccumulator::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_17);
  s_ShaderInstance_17.__vftable = (DebugMorphAccumulator::CShader_vtbl *)&DebugMorphAccumulator::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AF90
// Name: DebugMorphAccumulator::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugMorphAccumulator::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_17);
}

//------------------------------------------------------------------------------
// Address: 0x1005F710
// Name: _dynamic_initializer_for__s_ConstructMe_debugmrttexture_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugmrttexture_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugmrttexture_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F730
// Name: _dynamic_initializer_for__s_ConstructMe_debugmrttexture_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugmrttexture_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugmrttexture_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F750
// Name: _dynamic_initializer_for__s_ConstructMe_debugmrttexture_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugmrttexture_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugmrttexture_vs20_combos);
}
