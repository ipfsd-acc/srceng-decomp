// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/eyeglint_dx9.cpp
// Functions: 26
// ============================================================

#include "materialsystem\stdshaders\eyeglint_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10011100
// Name: public: virtual char const __near * EyeGlint::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall EyeGlint::CShader::GetFallbackShader(EyeGlint::CShader *this, IMaterialVar **params)
{
  return "EyeGlint_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x10011110
// Name: public: virtual char const __near * EyeGlint::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall EyeGlint::CShader::GetName(EyeGlint::CShader *this)
{
  return s_Name_32;
}

//------------------------------------------------------------------------------
// Address: 0x10011120
// Name: public: virtual int EyeGlint::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall EyeGlint::CShader::GetFlags(EyeGlint::CShader *this)
{
  return s_nFlags_65;
}

//------------------------------------------------------------------------------
// Address: 0x10011130
// Name: public: virtual int EyeGlint::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall EyeGlint::CShader::GetParamCount(EyeGlint::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_32.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011140
// Name: public: virtual char const __near * EyeGlint_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall EyeGlint_dx9::CShader::GetName(EyeGlint_dx9::CShader *this)
{
  return s_Name_33;
}

//------------------------------------------------------------------------------
// Address: 0x10011150
// Name: public: virtual int EyeGlint_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall EyeGlint_dx9::CShader::GetFlags(EyeGlint_dx9::CShader *this)
{
  return s_nFlags_66;
}

//------------------------------------------------------------------------------
// Address: 0x10011160
// Name: public: virtual void EyeGlint_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EyeGlint_dx9::CShader::OnDrawElements(
        EyeGlint_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  void (__thiscall *VertexShaderVertexFormat)(IShaderShadow *, unsigned int, int, int *, int); // edx
  int v8; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  int v10; // [esp+0h] [ebp-14h]
  int pTexCoords[3]; // [esp+8h] [ebp-Ch] BYREF

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
    pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_ONE, a3: SHADER_BLEND_ONE);
    pTexCoords[0] = 2;
    pTexCoords[1] = 2;
    VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
    pTexCoords[2] = 3;
    VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 3, a4: pTexCoords, a5: 0);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: false);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "eyeglint_vs20", a3: 0);
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v10 = 0;
    if ( v8 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "eyeglint_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "eyeglint_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    ((void (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
      a1: g_pHardwareConfig,
      a2: v10);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10011250
// Name: public: virtual int EyeGlint_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall EyeGlint_dx9::CShader::GetParamCount(EyeGlint_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_33.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011260
// Name: public: virtual struct ShaderParamInfo_t const __near & EyeGlint::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
EyeGlint::CShaderParam *__thiscall EyeGlint::CShader::GetParamInfo(EyeGlint::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_32.m_Memory.m_pMemory[param - ParamCount];
  else
    return (EyeGlint::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10011290
// Name: public: virtual struct ShaderParamInfo_t const __near & EyeGlint_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
EyeGlint_dx9::CShaderParam *__thiscall EyeGlint_dx9::CShader::GetParamInfo(EyeGlint_dx9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_33.m_Memory.m_pMemory[param - ParamCount];
  else
    return (EyeGlint_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10061040
// Name: EyeGlint::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int EyeGlint::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: EyeGlint::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061050
// Name: EyeGlint::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *EyeGlint::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_32);
  s_ShaderInstance_32.__vftable = (EyeGlint::CShader_vtbl *)&EyeGlint::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061070
// Name: EyeGlint_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int EyeGlint_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: EyeGlint_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061080
// Name: EyeGlint_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *EyeGlint_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_33);
  s_ShaderInstance_33.__vftable = (EyeGlint_dx9::CShader_vtbl *)&EyeGlint_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B1A0
// Name: EyeGlint::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl EyeGlint::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_32);
}

//------------------------------------------------------------------------------
// Address: 0x1006B1B0
// Name: EyeGlint_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl EyeGlint_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_33);
}

//------------------------------------------------------------------------------
// Address: 0x100610A0
// Name: _dynamic_initializer_for__s_ConstructMe_eyes_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyes_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyes_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100610C0
// Name: _dynamic_initializer_for__s_ConstructMe_eyes_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyes_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyes_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100610E0
// Name: _dynamic_initializer_for__s_ConstructMe_eyes_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyes_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyes_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061100
// Name: _dynamic_initializer_for__s_ConstructMe_eyes_flashlight_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyes_flashlight_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyes_flashlight_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061120
// Name: _dynamic_initializer_for__s_ConstructMe_eyes_flashlight_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyes_flashlight_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyes_flashlight_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061140
// Name: _dynamic_initializer_for__s_ConstructMe_eyes_flashlight_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyes_flashlight_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyes_flashlight_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061160
// Name: _dynamic_initializer_for__s_ConstructMe_eyes_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyes_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyes_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061180
// Name: _dynamic_initializer_for__s_ConstructMe_eyes_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyes_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyes_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100611A0
// Name: _dynamic_initializer_for__s_ConstructMe_eyes_flashlight_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyes_flashlight_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyes_flashlight_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100611C0
// Name: _dynamic_initializer_for__s_ConstructMe_eyes_flashlight_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyes_flashlight_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyes_flashlight_ps30_combos);
}
