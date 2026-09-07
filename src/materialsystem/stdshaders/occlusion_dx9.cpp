// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/occlusion_dx9.cpp
// Functions: 17
// ============================================================

#include "materialsystem\stdshaders\occlusion_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x100203A0
// Name: public: virtual char const __near * Occlusion::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Occlusion::CShader::GetFallbackShader(Occlusion::CShader *this, IMaterialVar **params)
{
  return "Occlusion_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x100203B0
// Name: public: virtual char const __near * Occlusion::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Occlusion::CShader::GetName(Occlusion::CShader *this)
{
  return s_Name_69;
}

//------------------------------------------------------------------------------
// Address: 0x100203C0
// Name: public: virtual int Occlusion::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Occlusion::CShader::GetFlags(Occlusion::CShader *this)
{
  return s_nFlags_88;
}

//------------------------------------------------------------------------------
// Address: 0x100203D0
// Name: public: virtual int Occlusion::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Occlusion::CShader::GetParamCount(Occlusion::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_70.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100203E0
// Name: public: virtual char const __near * Occlusion_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Occlusion_DX9::CShader::GetName(Occlusion_DX9::CShader *this)
{
  return s_Name_70;
}

//------------------------------------------------------------------------------
// Address: 0x100203F0
// Name: public: virtual int Occlusion_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Occlusion_DX9::CShader::GetFlags(Occlusion_DX9::CShader *this)
{
  return s_nFlags_27;
}

//------------------------------------------------------------------------------
// Address: 0x10020400
// Name: public: virtual void Occlusion_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Occlusion_DX9::CShader::OnInitShaderInstance(
        Occlusion_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
}

//------------------------------------------------------------------------------
// Address: 0x10020420
// Name: public: virtual void Occlusion_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge Occlusion_DX9::CShader::OnDrawElements(
        Occlusion_DX9::CShader *this@<ecx>,
        int a2@<ebx>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  BOOL v7; // edi
  int v8; // eax
  BOOL v9; // ebx
  BOOL v10; // edi
  int v11; // eax
  const char *v12; // [esp-4h] [ebp-10h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableColorWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "writez_vs20", a3: 8 * (v7 + 2 * (v8 < 92)));
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1025u, a3: 1, a4: nullptr, a5: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    v9 = ((int (__thiscall *)(IShaderDynamicAPI *, int))pShaderAPI->GetSceneFogMode)(a1: pShaderAPI, a2) == 2;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    v10 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v11 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v11 > 0, v12);
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v10 + 2 * (vertexCompression + 2 * v9));
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10020560
// Name: public: virtual int Occlusion_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Occlusion_DX9::CShader::GetParamCount(Occlusion_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_69.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10020570
// Name: public: virtual struct ShaderParamInfo_t const __near & Occlusion::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Occlusion::CShaderParam *__thiscall Occlusion::CShader::GetParamInfo(Occlusion::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_70.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Occlusion::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100205A0
// Name: public: virtual struct ShaderParamInfo_t const __near & Occlusion_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Occlusion_DX9::CShaderParam *__thiscall Occlusion_DX9::CShader::GetParamInfo(Occlusion_DX9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_69.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Occlusion_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10063B30
// Name: Occlusion::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Occlusion::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Occlusion::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063B40
// Name: Occlusion::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Occlusion::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_70);
  s_ShaderInstance_70.__vftable = (Occlusion::CShader_vtbl *)&Occlusion::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063B60
// Name: Occlusion_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Occlusion_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Occlusion_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063B70
// Name: Occlusion_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Occlusion_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_69);
  s_ShaderInstance_69.__vftable = (Occlusion_DX9::CShader_vtbl *)&Occlusion_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B460
// Name: Occlusion::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Occlusion::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_70);
}

//------------------------------------------------------------------------------
// Address: 0x1006B470
// Name: Occlusion_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Occlusion_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_69);
}
