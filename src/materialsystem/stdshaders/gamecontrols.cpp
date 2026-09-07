// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/gamecontrols.cpp
// Functions: 12
// ============================================================

#include "materialsystem\stdshaders\gamecontrols.h"

//------------------------------------------------------------------------------
// Address: 0x10014560
// Name: public: virtual void GAMECONTROLS::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GAMECONTROLS::CShader::OnInitShaderParams(
        GAMECONTROLS::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x200000);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x2000);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x8000);
}

//------------------------------------------------------------------------------
// Address: 0x100145B0
// Name: public: virtual char const __near * GAMECONTROLS::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GAMECONTROLS::CShader::GetName(GAMECONTROLS::CShader *this)
{
  return s_Name_42;
}

//------------------------------------------------------------------------------
// Address: 0x100145C0
// Name: public: virtual int GAMECONTROLS::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GAMECONTROLS::CShader::GetFlags(GAMECONTROLS::CShader *this)
{
  return s_nFlags_18;
}

//------------------------------------------------------------------------------
// Address: 0x100145D0
// Name: public: virtual void GAMECONTROLS::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GAMECONTROLS::CShader::OnDrawElements(
        GAMECONTROLS::CShader *this,
        IMaterialVar **params,
        int pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v6; // esi
  void (__thiscall *v8)(int, int, int, int *, _DWORD); // edx
  IShaderDynamicAPI *v9; // esi

  v6 = pShaderShadow;
  if ( pShaderShadow != 0 )
  {
    (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)pShaderShadow + 84))(a1: pShaderShadow, a2: 0, a3: 1);
    v8 = *(void (__thiscall **)(int, int, int, int *, _DWORD))(*(_DWORD *)v6 + 64);
    pShaderShadow = 3;
    v8(a1: v6, a2: 5, a3: 1, a4: &pShaderShadow, a5: 0);
    CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 68))(a1: v6, a2: "gamecontrols_vs20", a3: 0);
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 72))(a1: v6, a2: "gamecontrols_ps20", a3: 0);
  }
  v9 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    v9->SetVertexShaderIndex(this: v9, a2: 0);
    v9->SetPixelShaderIndex(this: v9, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10014670
// Name: public: virtual int GAMECONTROLS::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GAMECONTROLS::CShader::GetParamCount(GAMECONTROLS::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_42.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10014680
// Name: public: virtual struct ShaderParamInfo_t const __near & GAMECONTROLS::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
GAMECONTROLS::CShaderParam *__thiscall GAMECONTROLS::CShader::GetParamInfo(GAMECONTROLS::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_42.m_Memory.m_pMemory[param - ParamCount];
  else
    return (GAMECONTROLS::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10061B40
// Name: GAMECONTROLS::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int GAMECONTROLS::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: GAMECONTROLS::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061B50
// Name: GAMECONTROLS::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *GAMECONTROLS::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_42);
  s_ShaderInstance_42.__vftable = (GAMECONTROLS::CShader_vtbl *)&GAMECONTROLS::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B240
// Name: GAMECONTROLS::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAMECONTROLS::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_42);
}

//------------------------------------------------------------------------------
// Address: 0x10061B70
// Name: _dynamic_initializer_for__s_ConstructMe_HDRCombineTo16Bit_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_HDRCombineTo16Bit_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &HDRCombineTo16Bit_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061B90
// Name: _dynamic_initializer_for__s_ConstructMe_HDRCombineTo16Bit_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_HDRCombineTo16Bit_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &HDRCombineTo16Bit_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061BB0
// Name: _dynamic_initializer_for__s_ConstructMe_HDRCombineTo16Bit_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_HDRCombineTo16Bit_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &HDRCombineTo16Bit_vs20_combos);
}
