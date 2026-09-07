// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/downsample.cpp
// Functions: 18
// ============================================================

#include "materialsystem\stdshaders\downsample.h"

//------------------------------------------------------------------------------
// Address: 0x1000C810
// Name: public: virtual char const __near * Downsample::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Downsample::CShader::GetName(Downsample::CShader *this)
{
  return s_Name_26;
}

//------------------------------------------------------------------------------
// Address: 0x1000C820
// Name: public: virtual int Downsample::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Downsample::CShader::GetFlags(Downsample::CShader *this)
{
  return s_nFlags_10;
}

//------------------------------------------------------------------------------
// Address: 0x1000C840
// Name: public: virtual void Downsample::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Downsample::CShader::OnDrawElements(
        Downsample::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v7; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v11)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v12)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v13)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IShaderDynamicAPI_vtbl *v14; // eax
  int v15; // [esp+0h] [ebp-28h]
  float v[4]; // [esp+8h] [ebp-20h] BYREF
  float v17; // [esp+18h] [ebp-10h]
  float v18; // [esp+1Ch] [ebp-Ch]
  int height; // [esp+20h] [ebp-8h] BYREF
  int width; // [esp+24h] [ebp-4h] BYREF
  float pShaderShadowa; // [esp+34h] [ebp+Ch]
  float dY; // [esp+38h] [ebp+10h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: false);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: false);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "Downsample_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v15 = 0;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "downsample_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "downsample_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    pShaderAPI->GetBackBufferDimensions(this: pShaderAPI, a2: &width, a3: &height);
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    pShaderShadowa = 1.0 / (float)width;
    dY = 1.0 / (float)height;
    LODWORD(v18) = LODWORD(pShaderShadowa) ^ _mask__NegFloat_;
    LODWORD(v[0]) = LODWORD(pShaderShadowa) ^ _mask__NegFloat_;
    LODWORD(v17) = LODWORD(dY) ^ _mask__NegFloat_;
    LODWORD(v[1]) = LODWORD(dY) ^ _mask__NegFloat_;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: v, a4: 1, a5: false);
    v11 = pShaderAPI->SetVertexShaderConstant;
    v[0] = v18;
    v[1] = dY;
    v11(this: pShaderAPI, a2: 49, a3: v, a4: 1, a5: false);
    v12 = pShaderAPI->SetVertexShaderConstant;
    v[0] = pShaderShadowa;
    v[1] = v17;
    v12(this: pShaderAPI, a2: 50, a3: v, a4: 1, a5: false);
    v13 = pShaderAPI->SetVertexShaderConstant;
    v[0] = pShaderShadowa;
    v[1] = dY;
    v13(this: pShaderAPI, a2: 51, a3: v, a4: 1, a5: false);
    v14 = pShaderAPI->__vftable;
    v[0] = 0.0;
    v14->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: v, a4: 1, a5: false);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    ((void (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
      a1: g_pHardwareConfig,
      a2: v15);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000CA30
// Name: public: virtual int Downsample::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Downsample::CShader::GetParamCount(Downsample::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_26.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000CA40
// Name: public: virtual struct ShaderParamInfo_t const __near & Downsample::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Downsample::CShaderParam *__thiscall Downsample::CShader::GetParamInfo(Downsample::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_26.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Downsample::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1005FFE0
// Name: Downsample::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Downsample::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Downsample::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005FFF0
// Name: Downsample::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Downsample::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_26);
  s_ShaderInstance_26.__vftable = (Downsample::CShader_vtbl *)&Downsample::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B050
// Name: Downsample::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Downsample::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_26);
}

//------------------------------------------------------------------------------
// Address: 0x10060010
// Name: _dynamic_initializer_for__s_ConstructMe_Downsample_nohdr_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Downsample_nohdr_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Downsample_nohdr_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060030
// Name: _dynamic_initializer_for__s_ConstructMe_Downsample_nohdr_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Downsample_nohdr_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Downsample_nohdr_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060050
// Name: _dynamic_initializer_for__r_bloomtintr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_bloomtintr__()
{
  ConVar::ConVar(this: &r_bloomtintr, pName: "r_bloomtintr", pDefaultValue: "0.3", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_bloomtintr__);
}

//------------------------------------------------------------------------------
// Address: 0x10060080
// Name: _dynamic_initializer_for__r_bloomtintg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_bloomtintg__()
{
  ConVar::ConVar(this: &r_bloomtintg, pName: "r_bloomtintg", pDefaultValue: "0.59", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_bloomtintg__);
}

//------------------------------------------------------------------------------
// Address: 0x100600B0
// Name: _dynamic_initializer_for__r_bloomtintb__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_bloomtintb__()
{
  ConVar::ConVar(this: &r_bloomtintb, pName: "r_bloomtintb", pDefaultValue: "0.11", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_bloomtintb__);
}

//------------------------------------------------------------------------------
// Address: 0x100600E0
// Name: _dynamic_initializer_for__r_bloomtintexponent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_bloomtintexponent__()
{
  ConVar::ConVar(this: &r_bloomtintexponent, pName: "r_bloomtintexponent", pDefaultValue: "2.2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_bloomtintexponent__);
}

//------------------------------------------------------------------------------
// Address: 0x1006B060
// Name: _dynamic_atexit_destructor_for__r_bloomtintr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_bloomtintr__()
{
  ConVar::~ConVar(this: &r_bloomtintr);
}

//------------------------------------------------------------------------------
// Address: 0x1006B070
// Name: _dynamic_atexit_destructor_for__r_bloomtintg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_bloomtintg__()
{
  ConVar::~ConVar(this: &r_bloomtintg);
}

//------------------------------------------------------------------------------
// Address: 0x1006B080
// Name: _dynamic_atexit_destructor_for__r_bloomtintb__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_bloomtintb__()
{
  ConVar::~ConVar(this: &r_bloomtintb);
}

//------------------------------------------------------------------------------
// Address: 0x1006B090
// Name: _dynamic_atexit_destructor_for__r_bloomtintexponent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_bloomtintexponent__()
{
  ConVar::~ConVar(this: &r_bloomtintexponent);
}
