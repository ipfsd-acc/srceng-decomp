// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/morphweight_dx9.cpp
// Functions: 21
// ============================================================

#include "materialsystem\stdshaders\morphweight_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1001EE10
// Name: public: virtual char const __near * MorphWeight::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MorphWeight::CShader::GetFallbackShader(MorphWeight::CShader *this, IMaterialVar **params)
{
  return "MorphWeight_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x1001EE20
// Name: public: virtual char const __near * MorphWeight::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MorphWeight::CShader::GetName(MorphWeight::CShader *this)
{
  return s_Name_62;
}

//------------------------------------------------------------------------------
// Address: 0x1001EE30
// Name: public: virtual int MorphWeight::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MorphWeight::CShader::GetFlags(MorphWeight::CShader *this)
{
  return s_nFlags_84;
}

//------------------------------------------------------------------------------
// Address: 0x1001EE40
// Name: public: virtual int MorphWeight::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MorphWeight::CShader::GetParamCount(MorphWeight::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_62.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001EE50
// Name: public: virtual char const __near * MorphWeight_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MorphWeight_DX9::CShader::GetName(MorphWeight_DX9::CShader *this)
{
  return s_Name_63;
}

//------------------------------------------------------------------------------
// Address: 0x1001EE60
// Name: public: virtual int MorphWeight_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MorphWeight_DX9::CShader::GetFlags(MorphWeight_DX9::CShader *this)
{
  return s_nFlags_24;
}

//------------------------------------------------------------------------------
// Address: 0x1001EE70
// Name: public: virtual void MorphWeight_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MorphWeight_DX9::CShader::OnDrawElements(
        MorphWeight_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  void (__thiscall *VertexShaderVertexFormat)(IShaderShadow *, unsigned int, int, int *, int); // edx
  int pTexCoord[2]; // [esp+8h] [ebp-8h] BYREF

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->FogMode(this: pShaderShadow, a2: SHADER_FOGMODE_DISABLED, a3: false);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "morphweight_vs30", a3: 0);
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "morphweight_ps30", a3: 0);
    VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
    pTexCoord[0] = 2;
    pTexCoord[1] = 4;
    VertexShaderVertexFormat(this: pShaderShadow, a2: 512u, a3: 2, a4: pTexCoord, a5: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1001EF30
// Name: public: virtual int MorphWeight_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MorphWeight_DX9::CShader::GetParamCount(MorphWeight_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_63.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001EF40
// Name: public: virtual struct ShaderParamInfo_t const __near & MorphWeight::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
MorphWeight::CShaderParam *__thiscall MorphWeight::CShader::GetParamInfo(MorphWeight::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_62.m_Memory.m_pMemory[param - ParamCount];
  else
    return (MorphWeight::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001EF70
// Name: public: virtual struct ShaderParamInfo_t const __near & MorphWeight_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
MorphWeight_DX9::CShaderParam *__thiscall MorphWeight_DX9::CShader::GetParamInfo(
        MorphWeight_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_63.m_Memory.m_pMemory[param - ParamCount];
  else
    return (MorphWeight_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10063590
// Name: MorphWeight::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int MorphWeight::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: MorphWeight::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100635A0
// Name: MorphWeight::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *MorphWeight::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_63);
  s_ShaderInstance_63.__vftable = (MorphWeight::CShader_vtbl *)&MorphWeight::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100635C0
// Name: MorphWeight_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int MorphWeight_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: MorphWeight_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100635D0
// Name: MorphWeight_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *MorphWeight_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_62);
  s_ShaderInstance_62.__vftable = (MorphWeight_DX9::CShader_vtbl *)&MorphWeight_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B3E0
// Name: MorphWeight::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphWeight::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_62);
}

//------------------------------------------------------------------------------
// Address: 0x1006B3F0
// Name: MorphWeight_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphWeight_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_63);
}

//------------------------------------------------------------------------------
// Address: 0x100635F0
// Name: _dynamic_initializer_for__s_ConstructMe_motion_blur_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_motion_blur_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &motion_blur_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063610
// Name: _dynamic_initializer_for__s_ConstructMe_motion_blur_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_motion_blur_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &motion_blur_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063630
// Name: _dynamic_initializer_for__s_ConstructMe_motion_blur_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_motion_blur_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &motion_blur_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063650
// Name: _dynamic_initializer_for__mat_motion_blur_percent_of_screen_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_percent_of_screen_max__()
{
  ConVar::ConVar(
    this: &mat_motion_blur_percent_of_screen_max,
    pName: "mat_motion_blur_percent_of_screen_max",
    pDefaultValue: "4.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_percent_of_screen_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1006B400
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_percent_of_screen_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_percent_of_screen_max__()
{
  ConVar::~ConVar(this: &mat_motion_blur_percent_of_screen_max);
}
