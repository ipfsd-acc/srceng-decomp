// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/writestencil_dx9.cpp
// Functions: 18
// ============================================================

#include "materialsystem\stdshaders\writestencil_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10046F70
// Name: public: virtual char const __near * WriteStencil::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WriteStencil::CShader::GetFallbackShader(WriteStencil::CShader *this, IMaterialVar **params)
{
  return "WriteStencil_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x10046F80
// Name: public: virtual char const __near * WriteStencil::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WriteStencil::CShader::GetName(WriteStencil::CShader *this)
{
  return s_Name_138;
}

//------------------------------------------------------------------------------
// Address: 0x10046F90
// Name: public: virtual int WriteStencil::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WriteStencil::CShader::GetFlags(WriteStencil::CShader *this)
{
  return s_nFlags_140;
}

//------------------------------------------------------------------------------
// Address: 0x10046FA0
// Name: public: virtual int WriteStencil::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WriteStencil::CShader::GetParamCount(WriteStencil::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_138.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10046FB0
// Name: public: virtual char const __near * WriteStencil_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WriteStencil_DX9::CShader::GetName(WriteStencil_DX9::CShader *this)
{
  return s_Name_139;
}

//------------------------------------------------------------------------------
// Address: 0x10046FC0
// Name: public: virtual int WriteStencil_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WriteStencil_DX9::CShader::GetFlags(WriteStencil_DX9::CShader *this)
{
  return s_nFlags_44;
}

//------------------------------------------------------------------------------
// Address: 0x10046FD0
// Name: public: virtual int WriteStencil_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WriteStencil_DX9::CShader::GetParamCount(WriteStencil_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_137.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10046FE0
// Name: public: virtual struct ShaderParamInfo_t const __near & WriteStencil::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
WriteStencil::CShaderParam *__thiscall WriteStencil::CShader::GetParamInfo(WriteStencil::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_138.m_Memory.m_pMemory[param - ParamCount];
  else
    return (WriteStencil::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10047010
// Name: public: virtual struct ShaderParamInfo_t const __near & WriteStencil_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
WriteStencil_DX9::CShaderParam *__thiscall WriteStencil_DX9::CShader::GetParamInfo(
        WriteStencil_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_137.m_Memory.m_pMemory[param - ParamCount];
  else
    return (WriteStencil_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1006AC50
// Name: WriteStencil::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int WriteStencil::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: WriteStencil::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006AC60
// Name: WriteStencil::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *WriteStencil::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_139);
  s_ShaderInstance_139.__vftable = (WriteStencil::CShader_vtbl *)&WriteStencil::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AC80
// Name: WriteStencil_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int WriteStencil_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: WriteStencil_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006AC90
// Name: WriteStencil_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *WriteStencil_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_138);
  s_ShaderInstance_138.__vftable = (WriteStencil_DX9::CShader_vtbl *)&WriteStencil_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B9A0
// Name: WriteStencil::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteStencil::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_138);
}

//------------------------------------------------------------------------------
// Address: 0x1006B9B0
// Name: WriteStencil_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteStencil_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_137);
}

//------------------------------------------------------------------------------
// Address: 0x1006ACB0
// Name: _dynamic_initializer_for__s_ConstructMe_writez_vs20___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_writez_vs20___1()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &writez_vs20_combos_1);
}

//------------------------------------------------------------------------------
// Address: 0x1006ACD0
// Name: _dynamic_initializer_for__s_ConstructMe_white_ps20___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_white_ps20___1()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &white_ps20_combos_1);
}

//------------------------------------------------------------------------------
// Address: 0x1006ACF0
// Name: _dynamic_initializer_for__s_ConstructMe_white_ps20b___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_white_ps20b___1()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &white_ps20b_combos_1);
}
