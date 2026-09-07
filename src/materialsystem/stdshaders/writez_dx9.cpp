// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/writez_dx9.cpp
// Functions: 22
// ============================================================

#include "materialsystem\stdshaders\writez_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1001C8E0
// Name: public: CUtlVector<class PortalRefract::CShaderParam __near *,class CUtlMemory<class PortalRefract::CShaderParam __near *,int>>::~CUtlVector<class PortalRefract::CShaderParam __near *,class CUtlMemory<class PortalRefract::CShaderParam __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this)
{
  bool v2; // sf
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047040
// Name: public: virtual char const __near * WriteZ::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WriteZ::CShader::GetFallbackShader(WriteZ::CShader *this, IMaterialVar **params)
{
  return "WriteZ_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x10047050
// Name: public: virtual char const __near * WriteZ::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WriteZ::CShader::GetName(WriteZ::CShader *this)
{
  return s_Name_140;
}

//------------------------------------------------------------------------------
// Address: 0x10047060
// Name: public: virtual int WriteZ::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WriteZ::CShader::GetFlags(WriteZ::CShader *this)
{
  return s_nFlags_141;
}

//------------------------------------------------------------------------------
// Address: 0x10047070
// Name: public: virtual int WriteZ::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WriteZ::CShader::GetParamCount(WriteZ::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_139.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10047090
// Name: public: virtual char const __near * WriteZ_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WriteZ_DX9::CShader::GetName(WriteZ_DX9::CShader *this)
{
  return s_Name_141;
}

//------------------------------------------------------------------------------
// Address: 0x100470A0
// Name: public: virtual int WriteZ_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WriteZ_DX9::CShader::GetFlags(WriteZ_DX9::CShader *this)
{
  return s_nFlags_45;
}

//------------------------------------------------------------------------------
// Address: 0x100470B0
// Name: public: virtual void WriteZ_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge WriteZ_DX9::CShader::OnDrawElements(
        WriteZ_DX9::CShader *this@<ecx>,
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
// Address: 0x100471E0
// Name: public: virtual int WriteZ_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WriteZ_DX9::CShader::GetParamCount(WriteZ_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_140.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100471F0
// Name: public: virtual struct ShaderParamInfo_t const __near & WriteZ::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
WriteZ::CShaderParam *__thiscall WriteZ::CShader::GetParamInfo(WriteZ::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_139.m_Memory.m_pMemory[param - ParamCount];
  else
    return (WriteZ::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10047220
// Name: public: virtual struct ShaderParamInfo_t const __near & WriteZ_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
WriteZ_DX9::CShaderParam *__thiscall WriteZ_DX9::CShader::GetParamInfo(WriteZ_DX9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_140.m_Memory.m_pMemory[param - ParamCount];
  else
    return (WriteZ_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1006AD10
// Name: WriteZ::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int WriteZ::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: WriteZ::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006AD20
// Name: WriteZ::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *WriteZ::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_140);
  s_ShaderInstance_140.__vftable = (WriteZ::CShader_vtbl *)&WriteZ::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AD40
// Name: WriteZ_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int WriteZ_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: WriteZ_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006AD50
// Name: WriteZ_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *WriteZ_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_141);
  s_ShaderInstance_141.__vftable = (WriteZ_DX9::CShader_vtbl *)&WriteZ_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B9C0
// Name: WriteZ::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteZ::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_139);
}

//------------------------------------------------------------------------------
// Address: 0x1006B9D0
// Name: WriteZ_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteZ_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_140);
}

//------------------------------------------------------------------------------
// Address: 0x1006AD70
// Name: _dynamic_initializer_for____g_CreateIShaderDLLInternal_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateIShaderDLLInternal_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateIShaderDLLInternal_reg,
           fn: (void *(__cdecl *)())GetShaderDLLInternal,
           pName: "ShaderDLL004");
}

//------------------------------------------------------------------------------
// Address: 0x1006AD90
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x1006ADB0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AE10
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B9E0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: &s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}
