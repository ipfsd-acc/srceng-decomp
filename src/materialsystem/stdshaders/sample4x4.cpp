// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/sample4x4.cpp
// Functions: 12
// ============================================================

#include "materialsystem\stdshaders\sample4x4.h"

//------------------------------------------------------------------------------
// Address: 0x1002AB20
// Name: public: virtual char const __near * Sample4x4::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Sample4x4::CShader::GetName(Sample4x4::CShader *this)
{
  return s_Name_90;
}

//------------------------------------------------------------------------------
// Address: 0x1002AB30
// Name: public: virtual int Sample4x4::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sample4x4::CShader::GetFlags(Sample4x4::CShader *this)
{
  return s_nFlags_29;
}

//------------------------------------------------------------------------------
// Address: 0x1002AB40
// Name: public: virtual void Sample4x4::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sample4x4::CShader::OnInitShaderInstance(
        Sample4x4::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: BASETEXTURE_1.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002AB50
// Name: public: virtual void Sample4x4::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sample4x4::CShader::OnDrawElements(
        Sample4x4::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v6; // cc
  int (*GetStringValue)(void); // eax
  char *v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  void *v11; // esp
  IShaderShadow_vtbl *v12; // edi
  int v13; // eax
  int v14; // edi
  int v15; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v17)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v18)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IShaderDynamicAPI_vtbl *v19; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v21; // [esp-4h] [ebp-28h]
  unsigned __int8 v22[12]; // [esp+0h] [ebp-24h] BYREF
  float v[4]; // [esp+Ch] [ebp-18h] BYREF
  float v24; // [esp+1Ch] [ebp-8h]
  CBaseShader *v25; // [esp+20h] [ebp-4h]
  float paramsa; // [esp+2Ch] [ebp+8h]
  float dY; // [esp+30h] [ebp+Ch]

  v25 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "Downsample_vs20", a3: 0);
    v6 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    GetStringValue = (int (*)(void))params[PIXSHADER_0.m_Index]->GetStringValue;
    if ( !v6 )
    {
      v8 = (char *)GetStringValue();
      v9 = _V_strlen(str: v8);
      v10 = v9;
      if ( v9 > 5 && _V_stricmp(s1: &v8[v9 - 5], s2: "_ps20") == 0 )
      {
        v11 = alloca(v10 + 2);
        memcpy(dst: v22, src: (unsigned __int8 *)v8, count: v10);
        *(_WORD *)&v22[v10] = 98;
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: (const char *)v22, a3: 0);
        goto LABEL_8;
      }
      GetStringValue = (int (*)(void))params[PIXSHADER_0.m_Index]->GetStringValue;
    }
    v12 = pShaderShadow->__vftable;
    v13 = ((int (__cdecl *)(_DWORD))GetStringValue)(a1: 0);
    v12->SetPixelShader(this: pShaderShadow, a2: (const char *)v13, a3: v21);
  }
LABEL_8:
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v25,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: BASETEXTURE_1.m_Index,
      nFrameVar: -1);
    v14 = params[BASETEXTURE_1.m_Index]->GetTextureValue(this: params[BASETEXTURE_1.m_Index]);
    paramsa = 1.0 / (float)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 12))(a1: v14);
    v15 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 16))(a1: v14);
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    LODWORD(v[0]) = LODWORD(paramsa) ^ _mask__NegFloat_;
    dY = 1.0 / (float)v15;
    LODWORD(v24) = LODWORD(dY) ^ _mask__NegFloat_;
    LODWORD(v[1]) = LODWORD(dY) ^ _mask__NegFloat_;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: v, a4: 1, a5: false);
    v17 = pShaderAPI->SetVertexShaderConstant;
    LODWORD(v[0]) = LODWORD(paramsa) ^ _mask__NegFloat_;
    v[1] = dY;
    v17(this: pShaderAPI, a2: 49, a3: v, a4: 1, a5: false);
    v18 = pShaderAPI->SetVertexShaderConstant;
    v[0] = paramsa;
    v[1] = v24;
    v18(this: pShaderAPI, a2: 50, a3: v, a4: 1, a5: false);
    v19 = pShaderAPI->__vftable;
    v[0] = paramsa;
    v[1] = dY;
    v19->SetVertexShaderConstant(this: pShaderAPI, a2: 51, a3: v, a4: 1, a5: false);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    v[0] = 5.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: v, a4: 1, a5: false);
  }
  CBaseShader::Draw(this: v25, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002ADC0
// Name: public: virtual int Sample4x4::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sample4x4::CShader::GetParamCount(Sample4x4::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_90.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002ADD0
// Name: public: virtual struct ShaderParamInfo_t const __near & Sample4x4::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Sample4x4::CShaderParam *__thiscall Sample4x4::CShader::GetParamInfo(Sample4x4::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_90.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Sample4x4::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002AE00
// Name: public: Sample4x4::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Sample4x4::CShaderParam *__thiscall Sample4x4::CShaderParam::CShaderParam(
        Sample4x4::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Sample4x4::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Sample4x4::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_90.m_Size + 13;
  m_Size = s_ShaderParams_90.m_Size;
  v8 = s_ShaderParams_90.m_Size;
  if ( s_ShaderParams_90.m_Size + 1 > s_ShaderParams_90.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_90,
      num: s_ShaderParams_90.m_Size - s_ShaderParams_90.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_90.m_Size;
  }
  m_pMemory = s_ShaderParams_90.m_Memory.m_pMemory;
  s_ShaderParams_90.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_90.m_pElements = s_ShaderParams_90.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_90.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_90.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_90.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100651C0
// Name: Sample4x4::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Sample4x4::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Sample4x4::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100651D0
// Name: Sample4x4::_dynamic_initializer_for__BASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
Sample4x4::CShaderParam *Sample4x4::_dynamic_initializer_for__BASETEXTURE__()
{
  return Sample4x4::CShaderParam::CShaderParam(
           this: &BASETEXTURE_1,
           pName: "$BASETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100651F0
// Name: Sample4x4::_dynamic_initializer_for__PIXSHADER__
// Source: json
//------------------------------------------------------------------------------
Sample4x4::CShaderParam *Sample4x4::_dynamic_initializer_for__PIXSHADER__()
{
  return Sample4x4::CShaderParam::CShaderParam(
           this: &PIXSHADER_0,
           pName: "$PIXSHADER",
           type: SHADER_PARAM_TYPE_STRING,
           pDefaultParam: "sample4x4_ps20",
           pHelp: "Name of the pixel shader to use",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065210
// Name: Sample4x4::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Sample4x4::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_90);
  s_ShaderInstance_90.__vftable = (Sample4x4::CShader_vtbl *)&Sample4x4::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B610
// Name: Sample4x4::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sample4x4::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_90);
}
