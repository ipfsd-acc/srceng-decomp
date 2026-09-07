// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/debugdepth.cpp
// Functions: 12
// ============================================================

#include "materialsystem\stdshaders\debugdepth.h"

//------------------------------------------------------------------------------
// Address: 0x100010D0
// Name: public: virtual char const __near * DebugDepth::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DebugDepth::CShader::GetName(DebugDepth::CShader *this)
{
  return s_Name;
}

//------------------------------------------------------------------------------
// Address: 0x100010E0
// Name: public: virtual int DebugDepth::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugDepth::CShader::GetFlags(DebugDepth::CShader *this)
{
  return s_nFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100010F0
// Name: public: virtual void DebugDepth::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge DebugDepth::CShader::OnDrawElements(
        DebugDepth::CShader *this@<ecx>,
        int a2@<ebx>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v7; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  BOOL v9; // esi
  int v10; // eax
  int m_nValue; // eax
  IShaderDynamicAPI *v12; // ecx
  int v13; // edx
  bool v14; // zf
  float m_fValue; // xmm0_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const char *v17; // [esp-4h] [ebp-40h]
  int v18; // [esp+0h] [ebp-3Ch]
  Vector4D vecZFactor; // [esp+8h] [ebp-34h] BYREF
  Vector4D vecZFilter; // [esp+18h] [ebp-24h] BYREF
  Vector4D vecModulationColor; // [esp+28h] [ebp-14h] BYREF
  CBaseShader *v22; // [esp+38h] [ebp-4h]

  v22 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1025u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "debugdrawdepth_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v18 = 0;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "debugdrawdepth_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "debugdrawdepth_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    v9 = ((int (__thiscall *)(IShaderDynamicAPI *, int))CBaseShader::s_pShaderAPI->GetCurrentNumBones)(
           a1: CBaseShader::s_pShaderAPI,
           a2) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v10 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *, int))CBaseShader::s_pShaderAPI->GetCurrentNumBones)(
              a1: CBaseShader::s_pShaderAPI,
              a2: "s_pShaderAPI->GetCurrentNumBones() > 0",
              a3: v18);
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v10 > 0, v17);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * v9);
    memset(&vecZFilter, 0, 12);
    vecZFilter.w = 1.0;
    if ( mat_debugdepthmode.m_pParent == nullptr || (m_nValue = mat_debugdepthmode.m_pParent->m_Value.m_nValue) > 1 )
      m_nValue = 0;
    v12 = CBaseShader::s_pShaderAPI;
    *((_DWORD *)&vecZFilter.x + m_nValue) = 1065353216;
    v12->SetPixelShaderConstant(this: v12, a2: 1, a3: &vecZFilter.x, a4: 1, a5: false);
    v13 = (int)*params;
    vecModulationColor.y = 0.0;
    vecModulationColor.z = 0.0;
    vecModulationColor.x = 0.0;
    vecModulationColor.w = 1.0;
    v14 = (*(_BYTE *)(v13 + 10) & 1) == 0;
    vecModulationColor.y = 1.0;
    vecModulationColor.z = 1.0;
    if ( v14 )
      vecModulationColor.x = 1.0;
    else
      vecModulationColor.x = 0.0;
    CBaseShader::s_pShaderAPI->SetPixelShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: 2,
      a3: (const float *)&vecModulationColor,
      a4: 1,
      a5: false);
    m_fValue = mat_debugdepthval.m_pParent->m_Value.m_fValue;
    if ( m_fValue == 0.0 )
      m_fValue = 1.0;
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    vecZFactor.x = mat_debugdepthvalmax.m_pParent->m_Value.m_fValue - m_fValue;
    vecZFactor.y = m_fValue;
    vecZFactor.z = 1.0;
    vecZFactor.w = 1.0;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: &vecZFactor.x, a4: 1, a5: false);
  }
  CBaseShader::Draw(this: v22, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100012F0
// Name: public: virtual int DebugDepth::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugDepth::CShader::GetParamCount(DebugDepth::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001300
// Name: public: virtual struct ShaderParamInfo_t const __near & DebugDepth::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DebugDepth::CShaderParam *__thiscall DebugDepth::CShader::GetParamInfo(DebugDepth::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DebugDepth::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10001F90
// Name: public: virtual void DebugDepth::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DebugDepth::CShader::OnInitShaderParams(
        DebugDepth::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
}

//------------------------------------------------------------------------------
// Address: 0x10016790
// Name: DebugDepth::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DebugDepth::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DebugDepth::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100167A0
// Name: DebugDepth::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DebugDepth::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance);
  s_ShaderInstance.__vftable = (DebugDepth::CShader_vtbl *)&DebugDepth::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016D30
// Name: DebugDepth::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugDepth::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>::~CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams);
}

//------------------------------------------------------------------------------
// Address: 0x100167C0
// Name: _dynamic_initializer_for__s_ConstructMe_debugdrawenvmapmask_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugdrawenvmapmask_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugdrawenvmapmask_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100167E0
// Name: _dynamic_initializer_for__s_ConstructMe_debugdrawenvmapmask_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugdrawenvmapmask_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugdrawenvmapmask_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10016800
// Name: _dynamic_initializer_for__s_ConstructMe_debugdrawenvmapmask_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugdrawenvmapmask_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugdrawenvmapmask_ps20b_combos);
}
