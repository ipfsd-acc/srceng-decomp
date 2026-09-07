// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/screenspace_general.cpp
// Functions: 77
// ============================================================

#include "materialsystem\stdshaders\screenspace_general.h"

//------------------------------------------------------------------------------
// Address: 0x1002B240
// Name: public: virtual char const __near * screenspace_general::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall screenspace_general::CShader::GetFallbackShader(
        screenspace_general::CShader *this,
        IMaterialVar **params)
{
  return "screenspace_general_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x1002B250
// Name: public: virtual char const __near * screenspace_general::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall screenspace_general::CShader::GetName(screenspace_general::CShader *this)
{
  return s_Name_92;
}

//------------------------------------------------------------------------------
// Address: 0x1002B260
// Name: public: virtual int screenspace_general::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall screenspace_general::CShader::GetFlags(screenspace_general::CShader *this)
{
  return s_nFlags_108;
}

//------------------------------------------------------------------------------
// Address: 0x1002B270
// Name: public: virtual int screenspace_general::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall screenspace_general::CShader::GetParamCount(screenspace_general::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_92.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002B280
// Name: GetAdjustedShaderName
// Source: json
//------------------------------------------------------------------------------
void __usercall GetAdjustedShaderName(char *pOutputBuffer@<esi>, const char *pShader20Name@<eax>)
{
  unsigned int v2; // eax
  unsigned int v3; // edi

  _V_strcpy(dest: pOutputBuffer, src: pShader20Name);
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
  {
    v2 = _V_strlen(str: pOutputBuffer);
    v3 = v2;
    if ( v2 > 4
      && (_V_stricmp(s1: &pOutputBuffer[v2 - 5], s2: "_ps20") == 0
       || _V_stricmp(s1: &pOutputBuffer[v3 - 5], s2: "_vs20") == 0) )
    {
      *(_DWORD *)&pOutputBuffer[v3 - 2] = 6434866;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B2F0
// Name: public: virtual void screenspace_general_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall screenspace_general_dx9::CShader::OnInitShaderParams(
        screenspace_general_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( !params[TCSIZE0.m_Index]->IsDefined(this: params[TCSIZE0.m_Index]) )
    params[TCSIZE0.m_Index]->SetIntValue(this: params[TCSIZE0.m_Index], a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x1002B330
// Name: public: virtual char const __near * screenspace_general_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall screenspace_general_dx9::CShader::GetName(screenspace_general_dx9::CShader *this)
{
  return s_Name_93;
}

//------------------------------------------------------------------------------
// Address: 0x1002B340
// Name: public: virtual int screenspace_general_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall screenspace_general_dx9::CShader::GetFlags(screenspace_general_dx9::CShader *this)
{
  return s_nFlags_30;
}

//------------------------------------------------------------------------------
// Address: 0x1002B350
// Name: public: virtual void screenspace_general_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall screenspace_general_dx9::CShader::OnInitShaderInstance(
        screenspace_general_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
  if ( params[TEXTURE1_1.m_Index]->IsDefined(this: params[TEXTURE1_1.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: TEXTURE1_1.m_Index, nAdditionalCreationFlags: 0);
  if ( params[TEXTURE2_2.m_Index]->IsDefined(this: params[TEXTURE2_2.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: TEXTURE2_2.m_Index, nAdditionalCreationFlags: 0);
  if ( params[TEXTURE3_1.m_Index]->IsDefined(this: params[TEXTURE3_1.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: TEXTURE3_1.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002B3F0
// Name: public: virtual void screenspace_general_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall screenspace_general_dx9::CShader::OnDrawElements(
        screenspace_general_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IMaterialVar *v8; // ecx
  bool (__thiscall *IsDefined)(IMaterialVar *); // eax
  IShaderShadow *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  unsigned int v15; // esi
  int v16; // edx
  int i; // eax
  int m_intVal; // ecx
  const char *v19; // eax
  IShaderShadow_vtbl *v20; // esi
  int v21; // eax
  const char *v22; // eax
  bool v23; // al
  bool v24; // al
  bool v25; // al
  bool v26; // al
  IMaterialVar *v27; // ecx
  IMaterialVar *v28; // eax
  IMaterialVar *v29; // edx
  IMaterialVar *v30; // ecx
  IMaterialVar *v31; // eax
  IMaterialVar *v32; // edx
  IMaterialVar *v33; // ecx
  IMaterialVar *v34; // eax
  IMaterialVar *v35; // edx
  IMaterialVar *v36; // ecx
  IMaterialVar *v37; // eax
  IMaterialVar *v38; // edx
  IMaterialVar *v39; // ecx
  IMaterialVar *v40; // eax
  IMaterialVar *v41; // edx
  IMaterialVar *v42; // ecx
  IMaterialVar *v43; // eax
  IMaterialVar *v44; // edx
  IMaterialVar *v45; // ecx
  float x; // xmm0_4
  IShaderDynamicAPI_vtbl *v47; // edx
  int v48; // [esp+9Ch] [ebp-184h]
  char szShaderNameBuf[256]; // [esp+ACh] [ebp-174h] BYREF
  float eyePos[4]; // [esp+1ACh] [ebp-74h] BYREF
  _BYTE v51[16]; // [esp+1BCh] [ebp-64h] BYREF
  float c0[20]; // [esp+1CCh] [ebp-54h] BYREF
  CBaseShader *v53; // [esp+21Ch] [ebp-4h]
  bool bCustomVertexShader_3; // [esp+22Bh] [ebp+Bh]

  v8 = params[VERTEXSHADER.m_Index];
  IsDefined = v8->IsDefined;
  v53 = this;
  v10 = pShaderShadow;
  bCustomVertexShader_3 = IsDefined(this: v8);
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: params[WRITEDEPTH.m_Index]->m_intVal != 0);
    if ( params[WRITEDEPTH.m_Index]->m_intVal != 0 )
    {
      pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: true);
      pShaderShadow->DepthFunc(this: pShaderShadow, a2: SHADER_DEPTHFUNC_ALWAYS);
    }
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: params[WRITEALPHA.m_Index]->m_intVal != 0);
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: params[DEPTHTEST.m_Index]->m_intVal != 0);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: params[CULL.m_Index]->m_intVal != 0);
    if ( params[6]->IsDefined(this: params[6]) )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
      v11 = ((int (__thiscall *)(IMaterialVar *))params[LINEARREAD_BASETEXTURE.m_Index]->IsDefined)(a1: params[LINEARREAD_BASETEXTURE.m_Index]);
      if ( (_BYTE)v11 != 0 && params[LINEARREAD_BASETEXTURE.m_Index]->m_intVal != 0 )
        LOBYTE(v11) = 0;
      else
        v11 = 1;
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: v11);
    }
    if ( params[TEXTURE1_1.m_Index]->IsDefined(this: params[TEXTURE1_1.m_Index]) )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      v12 = ((int (__thiscall *)(IMaterialVar *))params[LINEARREAD_TEXTURE1.m_Index]->IsDefined)(a1: params[LINEARREAD_TEXTURE1.m_Index]);
      if ( (_BYTE)v12 != 0 && params[LINEARREAD_TEXTURE1.m_Index]->m_intVal != 0 )
        LOBYTE(v12) = 0;
      else
        v12 = 1;
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: v12);
    }
    if ( params[TEXTURE2_2.m_Index]->IsDefined(this: params[TEXTURE2_2.m_Index]) )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
      v13 = ((int (__thiscall *)(IMaterialVar *))params[LINEARREAD_TEXTURE2.m_Index]->IsDefined)(a1: params[LINEARREAD_TEXTURE2.m_Index]);
      if ( (_BYTE)v13 != 0 && params[LINEARREAD_TEXTURE2.m_Index]->m_intVal != 0 )
        LOBYTE(v13) = 0;
      else
        v13 = 1;
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: v13);
    }
    if ( params[TEXTURE3_1.m_Index]->IsDefined(this: params[TEXTURE3_1.m_Index]) )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: false);
      v14 = ((int (__thiscall *)(IMaterialVar *))params[LINEARREAD_TEXTURE3.m_Index]->IsDefined)(a1: params[LINEARREAD_TEXTURE3.m_Index]);
      if ( (_BYTE)v14 != 0 && params[LINEARREAD_TEXTURE3.m_Index]->m_intVal != 0 )
        LOBYTE(v14) = 0;
      else
        v14 = 1;
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: v14);
    }
    v15 = 1;
    if ( params[VERTEXCOLOR.m_Index]->m_intVal != 0 )
      v15 = 5;
    v16 = 0;
    if ( (`screenspace_general_dx9::CShader::OnDrawElements'::`23'::`local static guard' & 1) == 0 )
    {
      `screenspace_general_dx9::CShader::OnDrawElements'::`23'::`local static guard' |= 1u;
      `screenspace_general_dx9::CShader::OnDrawElements'::`23'::s_tcSizeIds[0] = TCSIZE0.m_Index;
      dword_100ABC24 = TCSIZE1.m_Index;
      dword_100ABC28 = TCSIZE2.m_Index;
      dword_100ABC2C = TCSIZE3.m_Index;
      dword_100ABC30 = TCSIZE4.m_Index;
      dword_100ABC34 = TCSIZE5.m_Index;
      dword_100ABC38 = TCSIZE6.m_Index;
      dword_100ABC3C = TCSIZE7.m_Index;
    }
    for ( i = 0; i < 8; ++i )
    {
      m_intVal = params[`screenspace_general_dx9::CShader::OnDrawElements'::`23'::s_tcSizeIds[i]]->m_intVal;
      if ( m_intVal == 0 )
        break;
      LODWORD(eyePos[i]) = m_intVal;
      ++v16;
    }
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: v15, a3: v16, a4: (int *)eyePos, a5: 0);
    if ( ((*params)->m_intVal & 0x80) != 0 )
    {
      CBaseShader::EnableAlphaBlending(this: v53, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
    }
    else if ( params[MULTIPLYCOLOR.m_Index]->m_intVal != 0 )
    {
      CBaseShader::EnableAlphaBlending(this: v53, src: SHADER_BLEND_ZERO, dst: SHADER_BLEND_SRC_COLOR);
    }
    else if ( params[ALPHABLEND.m_Index]->m_intVal != 0 )
    {
      CBaseShader::EnableAlphaBlending(this: v53, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    }
    else
    {
      pShaderShadow->EnableBlending(this: pShaderShadow, a2: false);
    }
    LOBYTE(pShaderShadow) = params[LINEARWRITE.m_Index]->m_VecVal.x == 0.0;
    v10->EnableSRGBWrite(this: v10, a2: (bool)pShaderShadow);
    if ( bCustomVertexShader_3 )
    {
      v19 = params[VERTEXSHADER.m_Index]->GetStringValue(this: params[VERTEXSHADER.m_Index]);
      GetAdjustedShaderName(pOutputBuffer: szShaderNameBuf, pShader20Name: v19);
      v20 = v10->__vftable;
      v21 = ((int (__thiscall *)(IMaterialVar *, _DWORD))params[VERTEXSHADER.m_Index]->GetStringValue)(
              a1: params[VERTEXSHADER.m_Index],
              a2: 0);
      v20->SetVertexShader(this: v10, a2: (const char *)v21, a3: v48);
    }
    else
    {
      v10->SetVertexShader(
        this: v10,
        a2: "screenspaceeffect_vs20",
        a3: params[VERTEXCOLOR.m_Index]->m_intVal + 2 * params[VERTEXTRANSFORM.m_Index]->m_intVal);
    }
    if ( params[DISABLE_COLOR_WRITES.m_Index]->m_intVal != 0 )
      v10->EnableColorWrites(this: v10, a2: false);
    v10->EnableAlphaTest(this: v10, a2: true);
    ((void (__thiscall *)(IShaderShadow *, int, _DWORD))v10->AlphaFunc)(a1: v10, a2: 4, a3: 0);
    v22 = params[PIXSHADER_2.m_Index]->GetStringValue(this: params[PIXSHADER_2.m_Index]);
    GetAdjustedShaderName(pOutputBuffer: szShaderNameBuf, pShader20Name: v22);
    v10->SetPixelShader(this: v10, a2: szShaderNameBuf, a3: 0);
    if ( params[ALPHA_BLEND_COLOR_OVERLAY.m_Index]->m_intVal != 0 )
      CBaseShader::EnableAlphaBlending(this: v53, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    if ( params[ALPHA_BLEND.m_Index]->m_intVal != 0 )
      CBaseShader::EnableAlphaBlending(this: v53, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    if ( params[COPYALPHA.m_Index]->m_intVal != 0 )
    {
      v10->EnableBlending(this: v10, a2: false);
      ((void (__thiscall *)(IShaderShadow *, int, _DWORD))v10->AlphaFunc)(a1: v10, a2: 7, a3: 0);
    }
    this = (screenspace_general_dx9::CShader *)v53;
  }
  if ( pShaderAPI != nullptr )
  {
    if ( params[6]->IsDefined(this: params[6]) )
    {
      v23 = !params[LINEARREAD_BASETEXTURE.m_Index]->IsDefined(this: params[LINEARREAD_BASETEXTURE.m_Index])
         || params[LINEARREAD_BASETEXTURE.m_Index]->m_intVal == 0;
      CBaseShader::BindTexture(
        this,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: v23 ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
        nTextureVar: 6,
        nFrameVar: -1);
      if ( params[POINTSAMPLE_BASETEXTURE.m_Index]->m_intVal != 0 )
        pShaderAPI->SetTextureFilterMode(this: pShaderAPI, a2: SHADER_SAMPLER0, a3: TFILTER_MODE_POINTSAMPLED);
    }
    if ( params[TEXTURE1_1.m_Index]->IsDefined(this: params[TEXTURE1_1.m_Index]) )
    {
      v24 = !params[LINEARREAD_TEXTURE1.m_Index]->IsDefined(this: params[LINEARREAD_TEXTURE1.m_Index])
         || params[LINEARREAD_TEXTURE1.m_Index]->m_intVal == 0;
      CBaseShader::BindTexture(
        this,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: v24 ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
        nTextureVar: TEXTURE1_1.m_Index,
        nFrameVar: -1);
      if ( params[POINTSAMPLE_TEXTURE1.m_Index]->m_intVal != 0 )
        pShaderAPI->SetTextureFilterMode(this: pShaderAPI, a2: SHADER_SAMPLER1, a3: TFILTER_MODE_POINTSAMPLED);
    }
    if ( params[TEXTURE2_2.m_Index]->IsDefined(this: params[TEXTURE2_2.m_Index]) )
    {
      v25 = !params[LINEARREAD_TEXTURE2.m_Index]->IsDefined(this: params[LINEARREAD_TEXTURE2.m_Index])
         || params[LINEARREAD_TEXTURE2.m_Index]->m_intVal == 0;
      CBaseShader::BindTexture(
        this,
        sampler1: SHADER_SAMPLER2,
        nBindFlags: v25 ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
        nTextureVar: TEXTURE2_2.m_Index,
        nFrameVar: -1);
      if ( params[POINTSAMPLE_TEXTURE2.m_Index]->m_intVal != 0 )
        pShaderAPI->SetTextureFilterMode(this: pShaderAPI, a2: SHADER_SAMPLER2, a3: TFILTER_MODE_POINTSAMPLED);
    }
    if ( params[TEXTURE3_1.m_Index]->IsDefined(this: params[TEXTURE3_1.m_Index]) )
    {
      v26 = !params[LINEARREAD_TEXTURE3.m_Index]->IsDefined(this: params[LINEARREAD_TEXTURE3.m_Index])
         || params[LINEARREAD_TEXTURE3.m_Index]->m_intVal == 0;
      CBaseShader::BindTexture(
        this,
        sampler1: SHADER_SAMPLER3,
        nBindFlags: v26 ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
        nTextureVar: TEXTURE3_1.m_Index,
        nFrameVar: -1);
      if ( params[POINTSAMPLE_TEXTURE3.m_Index]->m_intVal != 0 )
        pShaderAPI->SetTextureFilterMode(this: pShaderAPI, a2: SHADER_SAMPLER3, a3: TFILTER_MODE_POINTSAMPLED);
    }
    v27 = params[C0_Y.m_Index];
    v28 = params[C0_Z.m_Index];
    c0[0] = params[C0_X.m_Index]->m_VecVal.x;
    v29 = params[C0_W.m_Index];
    c0[1] = v27->m_VecVal.x;
    v30 = params[C1_X.m_Index];
    c0[2] = v28->m_VecVal.x;
    v31 = params[C1_Y.m_Index];
    c0[3] = v29->m_VecVal.x;
    v32 = params[C1_Z.m_Index];
    c0[4] = v30->m_VecVal.x;
    v33 = params[C1_W.m_Index];
    c0[5] = v31->m_VecVal.x;
    v34 = params[C2_X.m_Index];
    c0[6] = v32->m_VecVal.x;
    v35 = params[C2_Y.m_Index];
    c0[7] = v33->m_VecVal.x;
    v36 = params[C2_Z.m_Index];
    c0[8] = v34->m_VecVal.x;
    v37 = params[C2_W.m_Index];
    c0[9] = v35->m_VecVal.x;
    v38 = params[C3_X.m_Index];
    c0[10] = v36->m_VecVal.x;
    v39 = params[C3_Y.m_Index];
    c0[11] = v37->m_VecVal.x;
    v40 = params[C3_Z.m_Index];
    c0[12] = v38->m_VecVal.x;
    v41 = params[C3_W.m_Index];
    c0[13] = v39->m_VecVal.x;
    v42 = params[C4_X.m_Index];
    c0[14] = v40->m_VecVal.x;
    v43 = params[C4_Y.m_Index];
    c0[15] = v41->m_VecVal.x;
    v44 = params[C4_Z.m_Index];
    c0[16] = v42->m_VecVal.x;
    v45 = params[C4_W.m_Index];
    c0[17] = v43->m_VecVal.x;
    x = v44->m_VecVal.x;
    v47 = pShaderAPI->__vftable;
    c0[18] = x;
    c0[19] = v45->m_VecVal.x;
    v47->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: c0, a4: 5, a5: false);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: (float *)v51);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 10, a3: (const float *)v51, a4: 1, a5: false);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    if ( !bCustomVertexShader_3 )
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002BC70
// Name: public: virtual int screenspace_general_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall screenspace_general_dx9::CShader::GetParamCount(screenspace_general_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_93.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002BC80
// Name: public: virtual struct ShaderParamInfo_t const __near & screenspace_general::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
screenspace_general::CShaderParam *__thiscall screenspace_general::CShader::GetParamInfo(
        screenspace_general::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_92.m_Memory.m_pMemory[param - ParamCount];
  else
    return (screenspace_general::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002BCB0
// Name: public: virtual struct ShaderParamInfo_t const __near & screenspace_general_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *__thiscall screenspace_general_dx9::CShader::GetParamInfo(
        screenspace_general_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_93.m_Memory.m_pMemory[param - ParamCount];
  else
    return (screenspace_general_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002BCE0
// Name: public: screenspace_general_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *__thiscall screenspace_general_dx9::CShaderParam::CShaderParam(
        screenspace_general_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  screenspace_general_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  screenspace_general_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_93.m_Size + 13;
  m_Size = s_ShaderParams_93.m_Size;
  v8 = s_ShaderParams_93.m_Size;
  if ( s_ShaderParams_93.m_Size + 1 > s_ShaderParams_93.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_93,
      num: s_ShaderParams_93.m_Size - s_ShaderParams_93.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_93.m_Size;
  }
  m_pMemory = s_ShaderParams_93.m_Memory.m_pMemory;
  s_ShaderParams_93.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_93.m_pElements = s_ShaderParams_93.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_93.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_93.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_93.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100652C0
// Name: screenspace_general::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int screenspace_general::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: screenspace_general::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100652D0
// Name: screenspace_general::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *screenspace_general::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_92);
  s_ShaderInstance_92.__vftable = (screenspace_general::CShader_vtbl *)&screenspace_general::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100652F0
// Name: screenspace_general_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int screenspace_general_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: screenspace_general_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10065300
// Name: screenspace_general_dx9::_dynamic_initializer_for__C0_X__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C0_X__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C0_X,
           pName: "$C0_X",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065320
// Name: screenspace_general_dx9::_dynamic_initializer_for__C0_Y__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C0_Y__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C0_Y,
           pName: "$C0_Y",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065340
// Name: screenspace_general_dx9::_dynamic_initializer_for__C0_Z__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C0_Z__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C0_Z,
           pName: "$C0_Z",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065360
// Name: screenspace_general_dx9::_dynamic_initializer_for__C0_W__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C0_W__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C0_W,
           pName: "$C0_W",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065380
// Name: screenspace_general_dx9::_dynamic_initializer_for__C1_X__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C1_X__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C1_X,
           pName: "$C1_X",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100653A0
// Name: screenspace_general_dx9::_dynamic_initializer_for__C1_Y__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C1_Y__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C1_Y,
           pName: "$C1_Y",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100653C0
// Name: screenspace_general_dx9::_dynamic_initializer_for__C1_Z__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C1_Z__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C1_Z,
           pName: "$C1_Z",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100653E0
// Name: screenspace_general_dx9::_dynamic_initializer_for__C1_W__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C1_W__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C1_W,
           pName: "$C1_W",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065400
// Name: screenspace_general_dx9::_dynamic_initializer_for__C2_X__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C2_X__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C2_X,
           pName: "$C2_X",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065420
// Name: screenspace_general_dx9::_dynamic_initializer_for__C2_Y__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C2_Y__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C2_Y,
           pName: "$C2_Y",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065440
// Name: screenspace_general_dx9::_dynamic_initializer_for__C2_Z__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C2_Z__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C2_Z,
           pName: "$C2_Z",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065460
// Name: screenspace_general_dx9::_dynamic_initializer_for__C2_W__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C2_W__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C2_W,
           pName: "$C2_W",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065480
// Name: screenspace_general_dx9::_dynamic_initializer_for__C3_X__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C3_X__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C3_X,
           pName: "$C3_X",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100654A0
// Name: screenspace_general_dx9::_dynamic_initializer_for__C3_Y__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C3_Y__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C3_Y,
           pName: "$C3_Y",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100654C0
// Name: screenspace_general_dx9::_dynamic_initializer_for__C3_Z__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C3_Z__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C3_Z,
           pName: "$C3_Z",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100654E0
// Name: screenspace_general_dx9::_dynamic_initializer_for__C3_W__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C3_W__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C3_W,
           pName: "$C3_W",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065500
// Name: screenspace_general_dx9::_dynamic_initializer_for__C4_X__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C4_X__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C4_X,
           pName: "$C4_X",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065520
// Name: screenspace_general_dx9::_dynamic_initializer_for__C4_Y__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C4_Y__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C4_Y,
           pName: "$C4_Y",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065540
// Name: screenspace_general_dx9::_dynamic_initializer_for__C4_Z__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C4_Z__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C4_Z,
           pName: "$C4_Z",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065560
// Name: screenspace_general_dx9::_dynamic_initializer_for__C4_W__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__C4_W__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &C4_W,
           pName: "$C4_W",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065580
// Name: screenspace_general_dx9::_dynamic_initializer_for__PIXSHADER__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__PIXSHADER__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &PIXSHADER_2,
           pName: "$PIXSHADER",
           type: SHADER_PARAM_TYPE_STRING,
           pDefaultParam: pDefaultParam,
           pHelp: "Name of the pixel shader to use",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100655A0
// Name: screenspace_general_dx9::_dynamic_initializer_for__VERTEXSHADER__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__VERTEXSHADER__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &VERTEXSHADER,
           pName: "$VERTEXSHADER",
           type: SHADER_PARAM_TYPE_STRING,
           pDefaultParam: pDefaultParam,
           pHelp: "Name of the vertex shader to use",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100655C0
// Name: screenspace_general_dx9::_dynamic_initializer_for__DISABLE_COLOR_WRITES__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__DISABLE_COLOR_WRITES__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &DISABLE_COLOR_WRITES,
           pName: "$DISABLE_COLOR_WRITES",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100655E0
// Name: screenspace_general_dx9::_dynamic_initializer_for__ALPHATESTED__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__ALPHATESTED__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &ALPHATESTED,
           pName: "$ALPHATESTED",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065600
// Name: screenspace_general_dx9::_dynamic_initializer_for__ALPHA_BLEND_COLOR_OVERLAY__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__ALPHA_BLEND_COLOR_OVERLAY__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &ALPHA_BLEND_COLOR_OVERLAY,
           pName: "$ALPHA_BLEND_COLOR_OVERLAY",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065620
// Name: screenspace_general_dx9::_dynamic_initializer_for__ALPHA_BLEND__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__ALPHA_BLEND__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &ALPHA_BLEND,
           pName: "$ALPHA_BLEND",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065640
// Name: screenspace_general_dx9::_dynamic_initializer_for__TEXTURE1__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TEXTURE1__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TEXTURE1_1,
           pName: "$TEXTURE1",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065660
// Name: screenspace_general_dx9::_dynamic_initializer_for__TEXTURE2__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TEXTURE2__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TEXTURE2_2,
           pName: "$TEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065680
// Name: screenspace_general_dx9::_dynamic_initializer_for__TEXTURE3__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TEXTURE3__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TEXTURE3_1,
           pName: "$TEXTURE3",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100656A0
// Name: screenspace_general_dx9::_dynamic_initializer_for__LINEARREAD_BASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__LINEARREAD_BASETEXTURE__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &LINEARREAD_BASETEXTURE,
           pName: "$LINEARREAD_BASETEXTURE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100656C0
// Name: screenspace_general_dx9::_dynamic_initializer_for__LINEARREAD_TEXTURE1__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__LINEARREAD_TEXTURE1__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &LINEARREAD_TEXTURE1,
           pName: "$LINEARREAD_TEXTURE1",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100656E0
// Name: screenspace_general_dx9::_dynamic_initializer_for__LINEARREAD_TEXTURE2__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__LINEARREAD_TEXTURE2__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &LINEARREAD_TEXTURE2,
           pName: "$LINEARREAD_TEXTURE2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065700
// Name: screenspace_general_dx9::_dynamic_initializer_for__LINEARREAD_TEXTURE3__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__LINEARREAD_TEXTURE3__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &LINEARREAD_TEXTURE3,
           pName: "$LINEARREAD_TEXTURE3",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065720
// Name: screenspace_general_dx9::_dynamic_initializer_for__LINEARWRITE__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__LINEARWRITE__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &LINEARWRITE,
           pName: "$LINEARWRITE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065740
// Name: screenspace_general_dx9::_dynamic_initializer_for__VERTEXCOLOR__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__VERTEXCOLOR__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &VERTEXCOLOR,
           pName: "$VERTEXCOLOR",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "vertices have color info",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065760
// Name: screenspace_general_dx9::_dynamic_initializer_for__VERTEXTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__VERTEXTRANSFORM__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &VERTEXTRANSFORM,
           pName: "$VERTEXTRANSFORM",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "verts are in world space",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065780
// Name: screenspace_general_dx9::_dynamic_initializer_for__ALPHABLEND__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__ALPHABLEND__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &ALPHABLEND,
           pName: "$ALPHABLEND",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "whether or not to enable alpha blend",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100657A0
// Name: screenspace_general_dx9::_dynamic_initializer_for__MULTIPLYCOLOR__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__MULTIPLYCOLOR__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &MULTIPLYCOLOR,
           pName: "$MULTIPLYCOLOR",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "whether or not to multiply src and dest color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100657C0
// Name: screenspace_general_dx9::_dynamic_initializer_for__WRITEALPHA__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__WRITEALPHA__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &WRITEALPHA,
           pName: "$WRITEALPHA",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "whether or not to enable alpha write",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100657E0
// Name: screenspace_general_dx9::_dynamic_initializer_for__WRITEDEPTH__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__WRITEDEPTH__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &WRITEDEPTH,
           pName: "$WRITEDEPTH",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "whether or not to enable depth write",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065800
// Name: screenspace_general_dx9::_dynamic_initializer_for__TCSIZE0__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TCSIZE0__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TCSIZE0,
           pName: "$TCSIZE0",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "2",
           pHelp: "Number of components in texture coord0",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065820
// Name: screenspace_general_dx9::_dynamic_initializer_for__TCSIZE1__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TCSIZE1__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TCSIZE1,
           pName: "$TCSIZE1",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Number of components in texture coord1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065840
// Name: screenspace_general_dx9::_dynamic_initializer_for__TCSIZE2__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TCSIZE2__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TCSIZE2,
           pName: "$TCSIZE2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Number of components in texture coord2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065860
// Name: screenspace_general_dx9::_dynamic_initializer_for__TCSIZE3__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TCSIZE3__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TCSIZE3,
           pName: "$TCSIZE3",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Number of components in texture coord3",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065880
// Name: screenspace_general_dx9::_dynamic_initializer_for__TCSIZE4__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TCSIZE4__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TCSIZE4,
           pName: "$TCSIZE4",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Number of components in texture coord4",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100658A0
// Name: screenspace_general_dx9::_dynamic_initializer_for__TCSIZE5__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TCSIZE5__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TCSIZE5,
           pName: "$TCSIZE5",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Number of components in texture coord5",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100658C0
// Name: screenspace_general_dx9::_dynamic_initializer_for__TCSIZE6__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TCSIZE6__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TCSIZE6,
           pName: "$TCSIZE6",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Number of components in texture coord6",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100658E0
// Name: screenspace_general_dx9::_dynamic_initializer_for__TCSIZE7__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__TCSIZE7__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &TCSIZE7,
           pName: "$TCSIZE7",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Number of components in texture coord7",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065900
// Name: screenspace_general_dx9::_dynamic_initializer_for__POINTSAMPLE_BASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__POINTSAMPLE_BASETEXTURE__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &POINTSAMPLE_BASETEXTURE,
           pName: "$POINTSAMPLE_BASETEXTURE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065920
// Name: screenspace_general_dx9::_dynamic_initializer_for__POINTSAMPLE_TEXTURE1__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__POINTSAMPLE_TEXTURE1__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &POINTSAMPLE_TEXTURE1,
           pName: "$POINTSAMPLE_TEXTURE1",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065940
// Name: screenspace_general_dx9::_dynamic_initializer_for__POINTSAMPLE_TEXTURE2__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__POINTSAMPLE_TEXTURE2__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &POINTSAMPLE_TEXTURE2,
           pName: "$POINTSAMPLE_TEXTURE2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065960
// Name: screenspace_general_dx9::_dynamic_initializer_for__POINTSAMPLE_TEXTURE3__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__POINTSAMPLE_TEXTURE3__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &POINTSAMPLE_TEXTURE3,
           pName: "$POINTSAMPLE_TEXTURE3",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065980
// Name: screenspace_general_dx9::_dynamic_initializer_for__CULL__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__CULL__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &CULL,
           pName: "$CULL",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Culling control - 0 = nocull, 1 = do cull",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100659A0
// Name: screenspace_general_dx9::_dynamic_initializer_for__DEPTHTEST__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__DEPTHTEST__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &DEPTHTEST,
           pName: "$DEPTHTEST",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Enable Depthtest",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100659C0
// Name: screenspace_general_dx9::_dynamic_initializer_for__COPYALPHA__
// Source: json
//------------------------------------------------------------------------------
screenspace_general_dx9::CShaderParam *screenspace_general_dx9::_dynamic_initializer_for__COPYALPHA__()
{
  return screenspace_general_dx9::CShaderParam::CShaderParam(
           this: &COPYALPHA,
           pName: "$COPYALPHA",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100659E0
// Name: screenspace_general_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *screenspace_general_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_93);
  s_ShaderInstance_93.__vftable = (screenspace_general_dx9::CShader_vtbl *)&screenspace_general_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B630
// Name: screenspace_general::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl screenspace_general::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_92);
}

//------------------------------------------------------------------------------
// Address: 0x1006B640
// Name: screenspace_general_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl screenspace_general_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_93);
}

//------------------------------------------------------------------------------
// Address: 0x10065A00
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_ambientocclusion_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_ambientocclusion_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_ambientocclusion_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10065A20
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_ambientocclusion_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_ambientocclusion_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_ambientocclusion_ps30_combos);
}
