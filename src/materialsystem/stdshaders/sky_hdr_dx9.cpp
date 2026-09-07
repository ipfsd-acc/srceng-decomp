// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/sky_hdr_dx9.cpp
// Functions: 26
// ============================================================

#include "materialsystem\stdshaders\sky_hdr_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1000EE60
// Name: public: virtual void Sky::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sky::CShader::OnDrawElements(
        Aftershock::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderShadow,
        IShaderShadow *pShaderAPI,
        IShaderDynamicAPI *vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1002F650
// Name: public: virtual char const __near * Sky::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Sky::CShader::GetFallbackShader(Sky::CShader *this, IMaterialVar **params)
{
  return "Sky_HDR_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x1002F660
// Name: public: virtual char const __near * Sky::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Sky::CShader::GetName(Sky::CShader *this)
{
  return s_Name_108;
}

//------------------------------------------------------------------------------
// Address: 0x1002F670
// Name: public: virtual int Sky::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sky::CShader::GetFlags(Sky::CShader *this)
{
  return s_nFlags_112;
}

//------------------------------------------------------------------------------
// Address: 0x1002F680
// Name: public: virtual int Sky::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sky::CShader::GetParamCount(Sky::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_108.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002F690
// Name: public: virtual void Sky_HDR_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sky_HDR_DX9::CShader::OnInitShaderParams(
        Sky_HDR_DX9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x4000);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x8000);
}

//------------------------------------------------------------------------------
// Address: 0x1002F6D0
// Name: public: virtual char const __near * Sky_HDR_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Sky_HDR_DX9::CShader::GetName(Sky_HDR_DX9::CShader *this)
{
  return s_Name_109;
}

//------------------------------------------------------------------------------
// Address: 0x1002F6E0
// Name: public: virtual int Sky_HDR_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sky_HDR_DX9::CShader::GetFlags(Sky_HDR_DX9::CShader *this)
{
  return s_nFlags_113;
}

//------------------------------------------------------------------------------
// Address: 0x1002F6F0
// Name: public: virtual int Sky_HDR_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sky_HDR_DX9::CShader::GetParamCount(Sky_HDR_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_109.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002F700
// Name: public: virtual void Sky_HDR_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sky_HDR_DX9::CShader::OnInitShaderInstance(
        Sky_HDR_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int m_Index; // esi
  bool v8; // al
  int v9; // eax

  if ( params[HDRCOMPRESSEDTEXTURE.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE.m_Index])
    && mat_use_compressed_hdr_textures.m_pParent != nullptr
    && mat_use_compressed_hdr_textures.m_pParent->m_Value.m_nValue != 0
    || params[HDRCOMPRESSEDTEXTURE0.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE0.m_Index])
    || (v4 = params[HDRBASETEXTURE.m_Index]->GetTextureValue(this: params[HDRBASETEXTURE.m_Index]),
        (v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 76))(a1: v4)) == 24)
    || v5 == 25 )
  {
    v6 = 0;
  }
  else
  {
    v6 = 0x80000;
  }
  if ( params[HDRCOMPRESSEDTEXTURE.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE.m_Index])
    && mat_use_compressed_hdr_textures.m_pParent != nullptr
    && mat_use_compressed_hdr_textures.m_pParent->m_Value.m_nValue != 0 )
  {
    m_Index = HDRCOMPRESSEDTEXTURE.m_Index;
  }
  else
  {
    v8 = params[HDRCOMPRESSEDTEXTURE0.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE0.m_Index]);
    m_Index = HDRCOMPRESSEDTEXTURE0.m_Index;
    if ( !v8 )
      m_Index = HDRBASETEXTURE.m_Index;
  }
  if ( params[HDRCOMPRESSEDTEXTURE.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE.m_Index])
    && mat_use_compressed_hdr_textures.m_pParent != nullptr
    && mat_use_compressed_hdr_textures.m_pParent->m_Value.m_nValue != 0 )
  {
    v9 = HDRCOMPRESSEDTEXTURE.m_Index;
LABEL_26:
    CBaseShader::LoadTexture(this, nTextureVar: v9, nAdditionalCreationFlags: v9 != m_Index ? 0 : v6);
    return;
  }
  if ( !params[HDRCOMPRESSEDTEXTURE0.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE0.m_Index]) )
  {
    if ( !params[HDRBASETEXTURE.m_Index]->IsDefined(this: params[HDRBASETEXTURE.m_Index]) )
      return;
    v9 = HDRBASETEXTURE.m_Index;
    goto LABEL_26;
  }
  CBaseShader::LoadTexture(
    this,
    nTextureVar: HDRCOMPRESSEDTEXTURE0.m_Index,
    nAdditionalCreationFlags: HDRCOMPRESSEDTEXTURE0.m_Index != m_Index ? 0 : v6);
  if ( params[HDRCOMPRESSEDTEXTURE1.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE1.m_Index]) )
    CBaseShader::LoadTexture(
      this,
      nTextureVar: HDRCOMPRESSEDTEXTURE1.m_Index,
      nAdditionalCreationFlags: HDRCOMPRESSEDTEXTURE1.m_Index != m_Index ? 0 : v6);
  if ( params[HDRCOMPRESSEDTEXTURE2.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE2.m_Index]) )
  {
    v9 = HDRCOMPRESSEDTEXTURE2.m_Index;
    goto LABEL_26;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F8A0
// Name: public: virtual void Sky_HDR_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sky_HDR_DX9::CShader::OnDrawElements(
        Sky_HDR_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v7; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // eax
  void (__thiscall *v9)(IShaderShadow *, const char *, int); // eax
  int v10; // eax
  int v11; // eax
  void (__thiscall *v12)(IShaderShadow *, const char *, int); // eax
  IMaterialVar *v13; // ecx
  IMaterialVar *v14; // eax
  int v15; // edi
  float v16; // xmm2_4
  float v17; // xmm0_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v19; // xmm1_4
  float v20; // xmm4_4
  int v21; // eax
  IShaderDynamicAPI_vtbl *v22; // edx
  IShaderDynamicAPI *v23; // ecx
  void (__thiscall *v24)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v25; // eax
  int v26; // eax
  int v27; // eax
  BOOL v28; // edi
  unsigned __int8 v29; // al
  const char *v30; // [esp-4h] [ebp-30h]
  BOOL v31; // [esp-4h] [ebp-30h]
  int v32; // [esp+0h] [ebp-2Ch]
  float c1[4]; // [esp+Ch] [ebp-20h] BYREF
  float c0[4]; // [esp+1Ch] [ebp-10h] BYREF
  float w; // [esp+38h] [ebp+Ch]

  if ( pShaderShadow != nullptr )
  {
    CBaseShader::SetInitialShadowState(this);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "sky_vs20", a3: 0);
    if ( params[HDRCOMPRESSEDTEXTURE.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE.m_Index])
      && mat_use_compressed_hdr_textures.m_pParent != nullptr
      && mat_use_compressed_hdr_textures.m_pParent->m_Value.m_nValue != 0 )
    {
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: false);
      v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      SetPixelShader = pShaderShadow->SetPixelShader;
      v32 = 0;
      if ( v7 )
        ((void (__stdcall *)(const char *))SetPixelShader)(a1: "sky_hdr_compressed_rgbs_ps20");
      else
        ((void (__stdcall *)(const char *))SetPixelShader)(a1: "sky_hdr_compressed_rgbs_ps20b");
    }
    else if ( params[HDRCOMPRESSEDTEXTURE0.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE0.m_Index]) )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: false);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: false);
      v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      v9 = pShaderShadow->SetPixelShader;
      v32 = 0;
      if ( v7 )
        ((void (__stdcall *)(const char *))v9)(a1: "sky_hdr_compressed_ps20");
      else
        ((void (__stdcall *)(const char *))v9)(a1: "sky_hdr_compressed_ps20b");
    }
    else
    {
      v10 = params[HDRBASETEXTURE.m_Index]->GetTextureValue(this: params[HDRBASETEXTURE.m_Index]);
      v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 76))(a1: v10);
      if ( v11 == 24 || v11 == 25 )
        pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: false);
      else
        pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
      v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      v12 = pShaderShadow->SetPixelShader;
      v32 = 0;
      if ( v7 )
        ((void (__stdcall *)(const char *))v12)(a1: "sky_ps20");
      else
        ((void (__stdcall *)(const char *))v12)(a1: "sky_ps20b");
    }
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    CBaseVSShader::SetVertexShaderTextureTransform(this, vertexReg: 49, transformVar: 8);
    v13 = params[COLOR_3.m_Index];
    c0[0] = 1.0;
    c0[1] = 1.0;
    c0[2] = 1.0;
    c0[3] = 1.0;
    if ( ((unsigned __int8 (__thiscall *)(IMaterialVar *, int))v13->IsDefined)(a1: v13, a2: v32) != 0 )
    {
      v14 = params[COLOR_3.m_Index];
      *(_QWORD *)c0 = *(_QWORD *)&v14->m_VecVal.x;
      c0[2] = v14->m_VecVal.z;
    }
    if ( params[HDRCOMPRESSEDTEXTURE.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE.m_Index])
      && mat_use_compressed_hdr_textures.m_pParent != nullptr
      && mat_use_compressed_hdr_textures.m_pParent->m_Value.m_nValue != 0 )
    {
      v15 = params[HDRCOMPRESSEDTEXTURE.m_Index]->GetTextureValue(this: params[HDRCOMPRESSEDTEXTURE.m_Index]);
      w = (float)(*(int (__thiscall **)(int))(*(_DWORD *)v15 + 12))(a1: v15);
      v16 = (float)(*(int (__thiscall **)(int))(*(_DWORD *)v15 + 16))(a1: v15);
      if ( w <= v16 )
        v17 = v16;
      else
        v17 = w;
      SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
      v19 = 0.01 / v17;
      v20 = 0.5 / w - v19;
      c1[0] = v20;
      c1[1] = 0.5 / v16 - v19;
      c1[2] = w;
      c1[3] = v16;
      SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: c1, a4: 1, a5: false);
      CBaseShader::BindTexture(
        this,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: HDRCOMPRESSEDTEXTURE.m_Index,
        nFrameVar: 7);
      c0[0] = c0[0] * 8.0;
      c0[1] = c0[1] * 8.0;
      c0[2] = c0[2] * 8.0;
      v21 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      v22 = pShaderAPI->__vftable;
      v23 = pShaderAPI;
      if ( v21 < 92 )
        goto LABEL_30;
    }
    else
    {
      v24 = pShaderAPI->SetVertexShaderConstant;
      memset(c1, 0, sizeof(c1));
      v24(this: pShaderAPI, a2: 48, a3: c1, a4: 1, a5: false);
      if ( params[HDRCOMPRESSEDTEXTURE0.m_Index]->IsDefined(this: params[HDRCOMPRESSEDTEXTURE0.m_Index]) )
      {
        CBaseShader::BindTexture(
          this,
          sampler1: SHADER_SAMPLER0,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: HDRCOMPRESSEDTEXTURE0.m_Index,
          nFrameVar: 7);
        CBaseShader::BindTexture(
          this,
          sampler1: SHADER_SAMPLER1,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: HDRCOMPRESSEDTEXTURE1.m_Index,
          nFrameVar: 7);
        CBaseShader::BindTexture(
          this,
          sampler1: SHADER_SAMPLER2,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: HDRCOMPRESSEDTEXTURE2.m_Index,
          nFrameVar: 7);
        v25 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
        v22 = pShaderAPI->__vftable;
        v23 = pShaderAPI;
        if ( v25 < 92 )
        {
LABEL_30:
          ((void (__stdcall *)(_DWORD))v22->SetPixelShaderIndex)(a1: 0);
LABEL_45:
          pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: c0, a4: 1, a5: false);
          goto LABEL_46;
        }
      }
      else
      {
        CBaseShader::BindTexture(
          this,
          sampler1: SHADER_SAMPLER0,
          nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
          nTextureVar: HDRBASETEXTURE.m_Index,
          nFrameVar: 7);
        v26 = params[HDRBASETEXTURE.m_Index]->GetTextureValue(this: params[HDRBASETEXTURE.m_Index]);
        v27 = (*(int (__thiscall **)(int))(*(_DWORD *)v26 + 76))(a1: v26);
        if ( v27 == 25 || v27 == 24 && g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_INTEGER )
        {
          c0[0] = c0[0] * 16.0;
          c0[1] = c0[1] * 16.0;
          c0[2] = c0[2] * 16.0;
        }
        if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
        {
          v31 = false;
LABEL_44:
          ((void (__stdcall *)(BOOL))pShaderAPI->SetPixelShaderIndex)(a1: v31);
          goto LABEL_45;
        }
        v22 = pShaderAPI->__vftable;
        v23 = pShaderAPI;
      }
    }
    v28 = ((unsigned __int8 (__fastcall *)(IShaderDynamicAPI *))v22->ShouldWriteDepthToDestAlpha)(a1: v23) != 0;
    if ( g_shaderConfigDumpEnable )
    {
      v29 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->ShouldWriteDepthToDestAlpha)(
              a1: pShaderAPI,
              a2: "pShaderAPI->ShouldWriteDepthToDestAlpha()");
      printf(format: "\n   PS dyn  var %s = %d (%s)", "WRITE_DEPTH_TO_DESTALPHA", v29, v30);
    }
    v31 = v28;
    goto LABEL_44;
  }
LABEL_46:
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002FDA0
// Name: public: virtual struct ShaderParamInfo_t const __near & Sky::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Sky::CShaderParam *__thiscall Sky::CShader::GetParamInfo(Sky::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_108.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Sky::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002FDD0
// Name: public: virtual struct ShaderParamInfo_t const __near & Sky_HDR_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Sky_HDR_DX9::CShaderParam *__thiscall Sky_HDR_DX9::CShader::GetParamInfo(Sky_HDR_DX9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_109.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Sky_HDR_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002FE00
// Name: public: Sky_HDR_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Sky_HDR_DX9::CShaderParam *__thiscall Sky_HDR_DX9::CShaderParam::CShaderParam(
        Sky_HDR_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Sky_HDR_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Sky_HDR_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_109.m_Size + 13;
  m_Size = s_ShaderParams_109.m_Size;
  v8 = s_ShaderParams_109.m_Size;
  if ( s_ShaderParams_109.m_Size + 1 > s_ShaderParams_109.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_109,
      num: s_ShaderParams_109.m_Size - s_ShaderParams_109.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_109.m_Size;
  }
  m_pMemory = s_ShaderParams_109.m_Memory.m_pMemory;
  s_ShaderParams_109.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_109.m_pElements = s_ShaderParams_109.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_109.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_109.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_109.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066760
// Name: Sky::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Sky::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Sky::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10066770
// Name: Sky::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Sky::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_109);
  s_ShaderInstance_109.__vftable = (Sky::CShader_vtbl *)&Sky::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066790
// Name: Sky_HDR_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Sky_HDR_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Sky_HDR_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100667A0
// Name: Sky_HDR_DX9::_dynamic_initializer_for__HDRBASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
Sky_HDR_DX9::CShaderParam *Sky_HDR_DX9::_dynamic_initializer_for__HDRBASETEXTURE__()
{
  return Sky_HDR_DX9::CShaderParam::CShaderParam(
           this: &HDRBASETEXTURE,
           pName: "$HDRBASETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "base texture when running with HDR enabled",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100667C0
// Name: Sky_HDR_DX9::_dynamic_initializer_for__HDRCOMPRESSEDTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Sky_HDR_DX9::CShaderParam *Sky_HDR_DX9::_dynamic_initializer_for__HDRCOMPRESSEDTEXTURE__()
{
  return Sky_HDR_DX9::CShaderParam::CShaderParam(
           this: &HDRCOMPRESSEDTEXTURE,
           pName: "$HDRCOMPRESSEDTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "base texture (compressed) for hdr compression method A",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100667E0
// Name: Sky_HDR_DX9::_dynamic_initializer_for__HDRCOMPRESSEDTEXTURE0__
// Source: json
//------------------------------------------------------------------------------
Sky_HDR_DX9::CShaderParam *Sky_HDR_DX9::_dynamic_initializer_for__HDRCOMPRESSEDTEXTURE0__()
{
  return Sky_HDR_DX9::CShaderParam::CShaderParam(
           this: &HDRCOMPRESSEDTEXTURE0,
           pName: "$HDRCOMPRESSEDTEXTURE0",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "compressed base texture0 for hdr compression method B",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066800
// Name: Sky_HDR_DX9::_dynamic_initializer_for__HDRCOMPRESSEDTEXTURE1__
// Source: json
//------------------------------------------------------------------------------
Sky_HDR_DX9::CShaderParam *Sky_HDR_DX9::_dynamic_initializer_for__HDRCOMPRESSEDTEXTURE1__()
{
  return Sky_HDR_DX9::CShaderParam::CShaderParam(
           this: &HDRCOMPRESSEDTEXTURE1,
           pName: "$HDRCOMPRESSEDTEXTURE1",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "compressed base texture1 for hdr compression method B",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066820
// Name: Sky_HDR_DX9::_dynamic_initializer_for__HDRCOMPRESSEDTEXTURE2__
// Source: json
//------------------------------------------------------------------------------
Sky_HDR_DX9::CShaderParam *Sky_HDR_DX9::_dynamic_initializer_for__HDRCOMPRESSEDTEXTURE2__()
{
  return Sky_HDR_DX9::CShaderParam::CShaderParam(
           this: &HDRCOMPRESSEDTEXTURE2,
           pName: "$HDRCOMPRESSEDTEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "compressed base texture2 for hdr compression method B",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066840
// Name: Sky_HDR_DX9::_dynamic_initializer_for__COLOR__
// Source: json
//------------------------------------------------------------------------------
void Sky_HDR_DX9::_dynamic_initializer_for__COLOR__()
{
  s_pShaderParamOverrides_4[4] = &COLOR_3;
}

//------------------------------------------------------------------------------
// Address: 0x10066850
// Name: Sky_HDR_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Sky_HDR_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_108);
  s_ShaderInstance_108.__vftable = (Sky_HDR_DX9::CShader_vtbl *)&Sky_HDR_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B760
// Name: Sky::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sky::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_108);
}

//------------------------------------------------------------------------------
// Address: 0x1006B770
// Name: Sky_HDR_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sky_HDR_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_109);
}
