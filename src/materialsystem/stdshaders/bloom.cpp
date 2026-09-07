// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/bloom.cpp
// Functions: 15
// ============================================================

#include "materialsystem\stdshaders\bloom.h"

//------------------------------------------------------------------------------
// Address: 0x10007290
// Name: public: virtual char const __near * Bloom::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Bloom::CShader::GetName(Bloom::CShader *this)
{
  return s_Name_7;
}

//------------------------------------------------------------------------------
// Address: 0x100072A0
// Name: public: virtual int Bloom::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Bloom::CShader::GetFlags(Bloom::CShader *this)
{
  return s_nFlags_1;
}

//------------------------------------------------------------------------------
// Address: 0x100072B0
// Name: public: virtual void Bloom::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Bloom::CShader::OnInitShaderInstance(
        Bloom::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[FBTEXTURE.m_Index]->IsDefined(this: params[FBTEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: FBTEXTURE.m_Index, nAdditionalCreationFlags: 0);
  if ( params[BLURTEXTURE.m_Index]->IsDefined(this: params[BLURTEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: BLURTEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10007310
// Name: public: virtual void Bloom::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Bloom::CShader::OnDrawElements(
        Bloom::CShader *this,
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
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v9 = 0;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "bloom_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "bloom_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: FBTEXTURE.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: BLURTEXTURE.m_Index,
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
// Address: 0x100073F0
// Name: public: virtual int Bloom::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Bloom::CShader::GetParamCount(Bloom::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_7.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10007400
// Name: public: virtual struct ShaderParamInfo_t const __near & Bloom::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Bloom::CShaderParam *__thiscall Bloom::CShader::GetParamInfo(Bloom::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_7.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Bloom::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10007430
// Name: public: Bloom::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Bloom::CShaderParam *__thiscall Bloom::CShaderParam::CShaderParam(
        Bloom::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Bloom::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Bloom::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_7.m_Size + 13;
  m_Size = s_ShaderParams_7.m_Size;
  v8 = s_ShaderParams_7.m_Size;
  if ( s_ShaderParams_7.m_Size + 1 > s_ShaderParams_7.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_7,
      num: s_ShaderParams_7.m_Size - s_ShaderParams_7.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_7.m_Size;
  }
  m_pMemory = s_ShaderParams_7.m_Memory.m_pMemory;
  s_ShaderParams_7.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_7.m_pElements = s_ShaderParams_7.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_7.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_7.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_7.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005EB80
// Name: Bloom::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Bloom::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Bloom::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005EB90
// Name: Bloom::_dynamic_initializer_for__FBTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Bloom::CShaderParam *Bloom::_dynamic_initializer_for__FBTEXTURE__()
{
  return Bloom::CShaderParam::CShaderParam(
           this: &FBTEXTURE,
           pName: "$FBTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_FullFrameFB",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EBB0
// Name: Bloom::_dynamic_initializer_for__BLURTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Bloom::CShaderParam *Bloom::_dynamic_initializer_for__BLURTEXTURE__()
{
  return Bloom::CShaderParam::CShaderParam(
           this: &BLURTEXTURE,
           pName: "$BLURTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_SmallHDR0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EBD0
// Name: Bloom::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Bloom::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_7);
  s_ShaderInstance_7.__vftable = (Bloom::CShader_vtbl *)&Bloom::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AEE0
// Name: Bloom::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bloom::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_7);
}

//------------------------------------------------------------------------------
// Address: 0x1005EBF0
// Name: _dynamic_initializer_for__s_ConstructMe_BlurFilter_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_BlurFilter_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &BlurFilter_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EC10
// Name: _dynamic_initializer_for__s_ConstructMe_BlurFilter_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_BlurFilter_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &BlurFilter_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EC30
// Name: _dynamic_initializer_for__s_ConstructMe_BlurFilter_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_BlurFilter_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &BlurFilter_ps20b_combos);
}
