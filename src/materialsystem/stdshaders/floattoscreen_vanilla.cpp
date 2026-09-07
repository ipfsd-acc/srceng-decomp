// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/floattoscreen_vanilla.cpp
// Functions: 13
// ============================================================

#include "materialsystem\stdshaders\floattoscreen_vanilla.h"

//------------------------------------------------------------------------------
// Address: 0x10014350
// Name: public: virtual char const __near * floattoscreen_vanilla::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall floattoscreen_vanilla::CShader::GetName(floattoscreen_vanilla::CShader *this)
{
  return s_Name_41;
}

//------------------------------------------------------------------------------
// Address: 0x10014360
// Name: public: virtual int floattoscreen_vanilla::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall floattoscreen_vanilla::CShader::GetFlags(floattoscreen_vanilla::CShader *this)
{
  return s_nFlags_17;
}

//------------------------------------------------------------------------------
// Address: 0x10014370
// Name: public: virtual void floattoscreen_vanilla::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall floattoscreen_vanilla::CShader::OnInitShaderInstance(
        floattoscreen_vanilla::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[FBTEXTURE_2.m_Index]->IsDefined(this: params[FBTEXTURE_2.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: FBTEXTURE_2.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100143B0
// Name: public: virtual void floattoscreen_vanilla::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall floattoscreen_vanilla::CShader::OnDrawElements(
        floattoscreen_vanilla::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v7; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  int v9; // [esp+0h] [ebp-8h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v9 = 0;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "floattoscreen_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "floattoscreen_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: FBTEXTURE_2.m_Index,
      nFrameVar: -1);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    ((void (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
      a1: g_pHardwareConfig,
      a2: v9);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10014480
// Name: public: virtual int floattoscreen_vanilla::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall floattoscreen_vanilla::CShader::GetParamCount(floattoscreen_vanilla::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_41.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10014490
// Name: public: virtual struct ShaderParamInfo_t const __near & floattoscreen_vanilla::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
floattoscreen_vanilla::CShaderParam *__thiscall floattoscreen_vanilla::CShader::GetParamInfo(
        floattoscreen_vanilla::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_41.m_Memory.m_pMemory[param - ParamCount];
  else
    return (floattoscreen_vanilla::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100144C0
// Name: public: floattoscreen_vanilla::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
floattoscreen_vanilla::CShaderParam *__thiscall floattoscreen_vanilla::CShaderParam::CShaderParam(
        floattoscreen_vanilla::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  floattoscreen_vanilla::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  floattoscreen_vanilla::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_41.m_Size + 13;
  m_Size = s_ShaderParams_41.m_Size;
  v8 = s_ShaderParams_41.m_Size;
  if ( s_ShaderParams_41.m_Size + 1 > s_ShaderParams_41.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_41,
      num: s_ShaderParams_41.m_Size - s_ShaderParams_41.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_41.m_Size;
  }
  m_pMemory = s_ShaderParams_41.m_Memory.m_pMemory;
  s_ShaderParams_41.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_41.m_pElements = s_ShaderParams_41.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_41.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_41.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_41.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10061AB0
// Name: floattoscreen_vanilla::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int floattoscreen_vanilla::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: floattoscreen_vanilla::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061AC0
// Name: floattoscreen_vanilla::_dynamic_initializer_for__FBTEXTURE__
// Source: json
//------------------------------------------------------------------------------
floattoscreen_vanilla::CShaderParam *floattoscreen_vanilla::_dynamic_initializer_for__FBTEXTURE__()
{
  return floattoscreen_vanilla::CShaderParam::CShaderParam(
           this: &FBTEXTURE_2,
           pName: "$FBTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061AE0
// Name: floattoscreen_vanilla::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *floattoscreen_vanilla::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_41);
  s_ShaderInstance_41.__vftable = (floattoscreen_vanilla::CShader_vtbl *)&floattoscreen_vanilla::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B230
// Name: floattoscreen_vanilla::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl floattoscreen_vanilla::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_41);
}

//------------------------------------------------------------------------------
// Address: 0x10061B00
// Name: _dynamic_initializer_for__s_ConstructMe_gamecontrols_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_gamecontrols_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &gamecontrols_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061B20
// Name: _dynamic_initializer_for__s_ConstructMe_gamecontrols_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_gamecontrols_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &gamecontrols_ps20_combos);
}
