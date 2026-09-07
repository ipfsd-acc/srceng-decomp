// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/filmdust.cpp
// Functions: 15
// ============================================================

#include "materialsystem\stdshaders\filmdust.h"

//------------------------------------------------------------------------------
// Address: 0x10012880
// Name: public: virtual char const __near * FilmDust::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall FilmDust::CShader::GetName(FilmDust::CShader *this)
{
  return s_Name_36;
}

//------------------------------------------------------------------------------
// Address: 0x10012890
// Name: public: virtual int FilmDust::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall FilmDust::CShader::GetFlags(FilmDust::CShader *this)
{
  return s_nFlags_13;
}

//------------------------------------------------------------------------------
// Address: 0x100128A0
// Name: public: virtual void FilmDust::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FilmDust::CShader::OnInitShaderInstance(
        FilmDust::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: DUST_TEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100128B0
// Name: public: virtual void FilmDust::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FilmDust::CShader::OnDrawElements(
        FilmDust::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
    pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_ZERO, a3: SHADER_BLEND_SRC_COLOR);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "filmdust_ps20", a3: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: DUST_TEXTURE.m_Index,
      nFrameVar: -1);
    CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 0, constantVar: CHANNEL_SELECT.m_Index);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10012970
// Name: public: virtual int FilmDust::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall FilmDust::CShader::GetParamCount(FilmDust::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_36.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10012980
// Name: public: virtual struct ShaderParamInfo_t const __near & FilmDust::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
FilmDust::CShaderParam *__thiscall FilmDust::CShader::GetParamInfo(FilmDust::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_36.m_Memory.m_pMemory[param - ParamCount];
  else
    return (FilmDust::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100129B0
// Name: public: FilmDust::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
FilmDust::CShaderParam *__thiscall FilmDust::CShaderParam::CShaderParam(
        FilmDust::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  FilmDust::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  FilmDust::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_36.m_Size + 13;
  m_Size = s_ShaderParams_36.m_Size;
  v8 = s_ShaderParams_36.m_Size;
  if ( s_ShaderParams_36.m_Size + 1 > s_ShaderParams_36.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_36,
      num: s_ShaderParams_36.m_Size - s_ShaderParams_36.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_36.m_Size;
  }
  m_pMemory = s_ShaderParams_36.m_Memory.m_pMemory;
  s_ShaderParams_36.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_36.m_pElements = s_ShaderParams_36.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_36.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_36.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_36.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10014F10
// Name: public: virtual void FilmDust::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FilmDust::CShader::OnInitShaderParams(
        FilmDust::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x8000);
}

//------------------------------------------------------------------------------
// Address: 0x10061400
// Name: FilmDust::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int FilmDust::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: FilmDust::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061410
// Name: FilmDust::_dynamic_initializer_for__DUST_TEXTURE__
// Source: json
//------------------------------------------------------------------------------
FilmDust::CShaderParam *FilmDust::_dynamic_initializer_for__DUST_TEXTURE__()
{
  return FilmDust::CShaderParam::CShaderParam(
           this: &DUST_TEXTURE,
           pName: "$DUST_TEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "0",
           pHelp: "Film dust texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061430
// Name: FilmDust::_dynamic_initializer_for__CHANNEL_SELECT__
// Source: json
//------------------------------------------------------------------------------
FilmDust::CShaderParam *FilmDust::_dynamic_initializer_for__CHANNEL_SELECT__()
{
  return FilmDust::CShaderParam::CShaderParam(
           this: &CHANNEL_SELECT,
           pName: "$CHANNEL_SELECT",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: "Select which color channel to use",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061450
// Name: FilmDust::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *FilmDust::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_36);
  s_ShaderInstance_36.__vftable = (FilmDust::CShader_vtbl *)&FilmDust::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B1E0
// Name: FilmDust::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl FilmDust::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_36);
}

//------------------------------------------------------------------------------
// Address: 0x10061470
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___4()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_4);
}

//------------------------------------------------------------------------------
// Address: 0x10061490
// Name: _dynamic_initializer_for__s_ConstructMe_filmgrain_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_filmgrain_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &filmgrain_ps20_combos);
}
