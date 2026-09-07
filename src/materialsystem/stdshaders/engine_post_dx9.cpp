// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/engine_post_dx9.cpp
// Functions: 66
// ============================================================

#include "materialsystem\stdshaders\engine_post_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1000D510
// Name: public: virtual char const __near * Engine_Post::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Engine_Post::CShader::GetFallbackShader(Engine_Post::CShader *this, IMaterialVar **params)
{
  return "Engine_Post_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x1000D520
// Name: public: virtual char const __near * Engine_Post::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Engine_Post::CShader::GetName(Engine_Post::CShader *this)
{
  return s_Name_28;
}

//------------------------------------------------------------------------------
// Address: 0x1000D530
// Name: public: virtual int Engine_Post::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Engine_Post::CShader::GetFlags(Engine_Post::CShader *this)
{
  return s_nFlags_62;
}

//------------------------------------------------------------------------------
// Address: 0x1000D540
// Name: public: virtual int Engine_Post::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Engine_Post::CShader::GetParamCount(Engine_Post::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_28.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000D550
// Name: public: virtual void Engine_Post_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Engine_Post_dx9::CShader::OnInitShaderParams(
        Engine_Post_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( !params[INTERNAL_VIGNETTETEXTURE.m_Index]->IsDefined(this: params[INTERNAL_VIGNETTETEXTURE.m_Index]) )
    params[INTERNAL_VIGNETTETEXTURE.m_Index]->SetStringValue(
      this: params[INTERNAL_VIGNETTETEXTURE.m_Index],
      a2: "dev/vignette");
  if ( !params[AAENABLE.m_Index]->IsDefined(this: params[AAENABLE.m_Index]) )
    params[AAENABLE.m_Index]->SetIntValue(this: params[AAENABLE.m_Index], a2: 0);
  if ( !params[AAINTERNAL1.m_Index]->IsDefined(this: params[AAINTERNAL1.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD, _DWORD))params[AAINTERNAL1.m_Index]->SetVecValue)(
      a1: params[AAINTERNAL1.m_Index],
      a2: 0,
      a3: 0,
      a4: 0,
      a5: 0);
  if ( !params[AAINTERNAL2.m_Index]->IsDefined(this: params[AAINTERNAL2.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD, _DWORD))params[AAINTERNAL2.m_Index]->SetVecValue)(
      a1: params[AAINTERNAL2.m_Index],
      a2: 0,
      a3: 0,
      a4: 0,
      a5: 0);
  if ( !params[AAINTERNAL3.m_Index]->IsDefined(this: params[AAINTERNAL3.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD, _DWORD))params[AAINTERNAL3.m_Index]->SetVecValue)(
      a1: params[AAINTERNAL3.m_Index],
      a2: 0,
      a3: 0,
      a4: 0,
      a5: 0);
  if ( !params[BLOOMENABLE.m_Index]->IsDefined(this: params[BLOOMENABLE.m_Index]) )
    params[BLOOMENABLE.m_Index]->SetIntValue(this: params[BLOOMENABLE.m_Index], a2: 1);
  if ( !params[BLOOMAMOUNT_0.m_Index]->IsDefined(this: params[BLOOMAMOUNT_0.m_Index]) )
    ((void (__stdcall *)(int))params[BLOOMAMOUNT_0.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[DEPTHBLURENABLE.m_Index]->IsDefined(this: params[DEPTHBLURENABLE.m_Index]) )
    params[DEPTHBLURENABLE.m_Index]->SetIntValue(this: params[DEPTHBLURENABLE.m_Index], a2: 0);
  if ( !params[ALLOWNOISE.m_Index]->IsDefined(this: params[ALLOWNOISE.m_Index]) )
    params[ALLOWNOISE.m_Index]->SetIntValue(this: params[ALLOWNOISE.m_Index], a2: 1);
  if ( !params[NOISESCALE.m_Index]->IsDefined(this: params[NOISESCALE.m_Index]) )
    ((void (__stdcall *)(int))params[NOISESCALE.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[NOISEENABLE.m_Index]->IsDefined(this: params[NOISEENABLE.m_Index]) )
    params[NOISEENABLE.m_Index]->SetIntValue(this: params[NOISEENABLE.m_Index], a2: 0);
  if ( !params[ALLOWVIGNETTE.m_Index]->IsDefined(this: params[ALLOWVIGNETTE.m_Index]) )
    params[ALLOWVIGNETTE.m_Index]->SetIntValue(this: params[ALLOWVIGNETTE.m_Index], a2: 1);
  if ( !params[VIGNETTEENABLE.m_Index]->IsDefined(this: params[VIGNETTEENABLE.m_Index]) )
    params[VIGNETTEENABLE.m_Index]->SetIntValue(this: params[VIGNETTEENABLE.m_Index], a2: 0);
  if ( !params[ALLOWLOCALCONTRAST.m_Index]->IsDefined(this: params[ALLOWLOCALCONTRAST.m_Index]) )
    params[ALLOWLOCALCONTRAST.m_Index]->SetIntValue(this: params[ALLOWLOCALCONTRAST.m_Index], a2: 1);
  if ( !params[LOCALCONTRASTSCALE.m_Index]->IsDefined(this: params[LOCALCONTRASTSCALE.m_Index]) )
    ((void (__stdcall *)(int))params[LOCALCONTRASTSCALE.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[LOCALCONTRASTMIDTONEMASK.m_Index]->IsDefined(this: params[LOCALCONTRASTMIDTONEMASK.m_Index]) )
    ((void (__stdcall *)(int))params[LOCALCONTRASTMIDTONEMASK.m_Index]->SetFloatValue)(a1: 1148846080);
  if ( !params[LOCALCONTRASTENABLE.m_Index]->IsDefined(this: params[LOCALCONTRASTENABLE.m_Index]) )
    params[LOCALCONTRASTENABLE.m_Index]->SetIntValue(this: params[LOCALCONTRASTENABLE.m_Index], a2: 0);
  if ( !params[LOCALCONTRASTVIGNETTESTART.m_Index]->IsDefined(this: params[LOCALCONTRASTVIGNETTESTART.m_Index]) )
    ((void (__stdcall *)(int))params[LOCALCONTRASTVIGNETTESTART.m_Index]->SetFloatValue)(a1: 1060320051);
  if ( !params[LOCALCONTRASTVIGNETTEEND.m_Index]->IsDefined(this: params[LOCALCONTRASTVIGNETTEEND.m_Index]) )
    ((void (__stdcall *)(int))params[LOCALCONTRASTVIGNETTEEND.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[LOCALCONTRASTEDGESCALE.m_Index]->IsDefined(this: params[LOCALCONTRASTEDGESCALE.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[LOCALCONTRASTEDGESCALE.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[BLURREDVIGNETTEENABLE.m_Index]->IsDefined(this: params[BLURREDVIGNETTEENABLE.m_Index]) )
    params[BLURREDVIGNETTEENABLE.m_Index]->SetIntValue(this: params[BLURREDVIGNETTEENABLE.m_Index], a2: 0);
  if ( !params[BLURREDVIGNETTESCALE.m_Index]->IsDefined(this: params[BLURREDVIGNETTESCALE.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[BLURREDVIGNETTESCALE.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[FADETOBLACKSCALE.m_Index]->IsDefined(this: params[FADETOBLACKSCALE.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[FADETOBLACKSCALE.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[DEPTHBLURFOCALDISTANCE.m_Index]->IsDefined(this: params[DEPTHBLURFOCALDISTANCE.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[DEPTHBLURFOCALDISTANCE.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[DEPTHBLURSTRENGTH.m_Index]->IsDefined(this: params[DEPTHBLURSTRENGTH.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[DEPTHBLURSTRENGTH.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[SCREENBLURSTRENGTH.m_Index]->IsDefined(this: params[SCREENBLURSTRENGTH.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[SCREENBLURSTRENGTH.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[TOOLMODE.m_Index]->IsDefined(this: params[TOOLMODE.m_Index]) )
    params[TOOLMODE.m_Index]->SetIntValue(this: params[TOOLMODE.m_Index], a2: 0);
  if ( !params[TOOLCOLORCORRECTION.m_Index]->IsDefined(this: params[TOOLCOLORCORRECTION.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[TOOLCOLORCORRECTION.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[VOMITENABLE.m_Index]->IsDefined(this: params[VOMITENABLE.m_Index]) )
    params[VOMITENABLE.m_Index]->SetIntValue(this: params[VOMITENABLE.m_Index], a2: 0);
  if ( !params[VOMITREFRACTSCALE.m_Index]->IsDefined(this: params[VOMITREFRACTSCALE.m_Index]) )
    ((void (__stdcall *)(int))params[VOMITREFRACTSCALE.m_Index]->SetFloatValue)(a1: 1041865114);
  if ( !params[VOMITCOLOR1.m_Index]->IsDefined(this: params[VOMITCOLOR1.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, int, int, _DWORD))params[VOMITCOLOR1.m_Index]->SetVecValue_2)(
      a1: params[VOMITCOLOR1.m_Index],
      a2: 1065353216,
      a3: 1065353216,
      a4: 0);
  if ( !params[VOMITCOLOR2.m_Index]->IsDefined(this: params[VOMITCOLOR2.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, _DWORD, int, _DWORD))params[VOMITCOLOR2.m_Index]->SetVecValue_2)(
      a1: params[VOMITCOLOR2.m_Index],
      a2: 0,
      a3: 1065353216,
      a4: 0);
  if ( !params[FADE.m_Index]->IsDefined(this: params[FADE.m_Index]) )
    params[FADE.m_Index]->SetIntValue(this: params[FADE.m_Index], a2: 0);
  if ( !params[FADECOLOR.m_Index]->IsDefined(this: params[FADECOLOR.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD, _DWORD))params[FADECOLOR.m_Index]->SetVecValue)(
      a1: params[FADECOLOR.m_Index],
      a2: 0,
      a3: 0,
      a4: 0,
      a5: 0);
  if ( !params[TV_GAMMA.m_Index]->IsDefined(this: params[TV_GAMMA.m_Index]) )
    params[TV_GAMMA.m_Index]->SetIntValue(this: params[TV_GAMMA.m_Index], a2: 0);
  if ( !params[DESATURATEENABLE.m_Index]->IsDefined(this: params[DESATURATEENABLE.m_Index]) )
    params[DESATURATEENABLE.m_Index]->SetIntValue(this: params[DESATURATEENABLE.m_Index], a2: 0);
  if ( !params[DESATURATION.m_Index]->IsDefined(this: params[DESATURATION.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[DESATURATION.m_Index]->SetFloatValue)(a1: 0);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x8000);
}

//------------------------------------------------------------------------------
// Address: 0x1000DC30
// Name: public: virtual char const __near * Engine_Post_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Engine_Post_dx9::CShader::GetName(Engine_Post_dx9::CShader *this)
{
  return s_Name_29;
}

//------------------------------------------------------------------------------
// Address: 0x1000DC40
// Name: public: virtual int Engine_Post_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Engine_Post_dx9::CShader::GetFlags(Engine_Post_dx9::CShader *this)
{
  return s_nFlags_12;
}

//------------------------------------------------------------------------------
// Address: 0x1000DC50
// Name: public: virtual void Engine_Post_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Engine_Post_dx9::CShader::OnInitShaderInstance(
        Engine_Post_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
  if ( params[FBTEXTURE_0.m_Index]->IsDefined(this: params[FBTEXTURE_0.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: FBTEXTURE_0.m_Index, nAdditionalCreationFlags: 0);
  if ( params[SCREENEFFECTTEXTURE.m_Index]->IsDefined(this: params[SCREENEFFECTTEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: SCREENEFFECTTEXTURE.m_Index, nAdditionalCreationFlags: 0);
  if ( params[NOISETEXTURE.m_Index]->IsDefined(this: params[NOISETEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: NOISETEXTURE.m_Index, nAdditionalCreationFlags: 0);
  if ( params[INTERNAL_VIGNETTETEXTURE.m_Index]->IsDefined(this: params[INTERNAL_VIGNETTETEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: INTERNAL_VIGNETTETEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000DD10
// Name: public: virtual int Engine_Post_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Engine_Post_dx9::CShader::GetParamCount(Engine_Post_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_29.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000DD20
// Name: public: virtual void Engine_Post_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Engine_Post_dx9::CShader::OnDrawElements(
        Engine_Post_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v8; // bl
  bool v9; // zf
  int x; // eax
  Sampler_t v11; // ebx
  IShaderDynamicAPI *v12; // esi
  int v13; // eax
  IShaderDynamicAPI_vtbl *v14; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v16; // edx
  IShaderDynamicAPI_vtbl *v17; // eax
  float v18; // xmm0_4
  void (__thiscall *v19)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v20; // eax
  int v21; // ecx
  IMaterialVar *v22; // eax
  IMaterialVar *v23; // edx
  IMaterialVar *v24; // ecx
  IMaterialVar *v25; // eax
  IMaterialVar *v26; // edx
  int m_nLookupCount; // eax
  int v28; // ebx
  int v29; // ebx
  int v30; // eax
  void (__thiscall *v31)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v32; // eax
  void (__thiscall *v33)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float y; // xmm0_4
  IMaterialVar *v35; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v37; // xmm1_4
  IMaterialVar *v38; // eax
  IMaterialVar *v39; // edx
  IMaterialVar *v40; // ecx
  bool v41; // bl
  int v42; // eax
  IMaterialVar *v43; // eax
  float m_fValue; // xmm2_4
  void (__thiscall *v45)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  char v46; // al
  IMaterialVar *v47; // ecx
  void (__thiscall *v48)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v49; // ecx
  void (__thiscall *v50)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v51; // eax
  IMaterialVar *v52; // edx
  float z; // xmm0_4
  IShaderDynamicAPI_vtbl *v54; // eax
  float v55; // xmm0_4
  void (__thiscall *v56)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v57; // eax
  void (__thiscall *v58)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v59)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v60)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  HDRType_t v61; // eax
  bool v62; // bl
  HDRType_t v63; // eax
  int m_intVal; // eax
  int v65; // eax
  BOOL v66; // ebx
  BOOL v67; // eax
  BOOL v68; // edi
  int v69; // eax
  BOOL v70; // edi
  BOOL v71; // [esp+14h] [ebp-E4h]
  BOOL v72; // [esp+18h] [ebp-E0h]
  BOOL v73; // [esp+28h] [ebp-D0h]
  BOOL v74; // [esp+2Ch] [ebp-CCh]
  BOOL v75; // [esp+30h] [ebp-C8h]
  BOOL v76; // [esp+34h] [ebp-C4h]
  float tweakables[4]; // [esp+40h] [ebp-B8h] BYREF
  Vector4D uvTrans; // [esp+50h] [ebp-A8h] BYREF
  float offsets[4]; // [esp+60h] [ebp-98h] BYREF
  float bloomConstant[4]; // [esp+70h] [ebp-88h] BYREF
  BOOL v81; // [esp+80h] [ebp-78h]
  int colCorrectEnabled; // [esp+84h] [ebp-74h]
  engine_post_ps20b_Static_Index _pshIndex; // [esp+88h] [ebp-70h] BYREF
  ShaderColorCorrectionInfo_t ccInfo; // [esp+98h] [ebp-60h] BYREF
  int nViewportHeight; // [esp+B4h] [ebp-44h] BYREF
  int nViewportY; // [esp+B8h] [ebp-40h] BYREF
  int nRtHeight; // [esp+BCh] [ebp-3Ch] BYREF
  int nViewportX; // [esp+C0h] [ebp-38h] BYREF
  float vPsConst[4]; // [esp+C4h] [ebp-34h] BYREF
  CBaseShader *v90; // [esp+D4h] [ebp-24h]
  int colCorrectNumLookups; // [esp+D8h] [ebp-20h]
  int nViewportWidth; // [esp+DCh] [ebp-1Ch] BYREF
  float vViewportMad[4]; // [esp+E0h] [ebp-18h] BYREF
  bool bLocalContrastEnable; // [esp+F2h] [ebp-6h]
  bool bVignetteEnable; // [esp+F3h] [ebp-5h]
  bool bBlurredVignetteEnable; // [esp+F4h] [ebp-4h]
  bool bDesaturateEnable; // [esp+F5h] [ebp-3h]
  bool bVomitEnable; // [esp+F6h] [ebp-2h]
  bool bToolMode; // [esp+F7h] [ebp-1h]
  int bDepthBlurEnable; // [esp+100h] [ebp+8h]
  float bDepthBlurEnablea; // [esp+100h] [ebp+8h]
  bool bDepthBlurEnable_3; // [esp+103h] [ebp+Bh]
  bool bDepthBlurEnable_3a; // [esp+103h] [ebp+Bh]
  int flTime; // [esp+104h] [ebp+Ch]
  float flTimea; // [esp+104h] [ebp+Ch]
  bool flTime_3; // [esp+107h] [ebp+Fh]

  v90 = this;
  v8 = params[TOOLMODE.m_Index]->m_intVal != 0;
  v9 = params[DEPTHBLURENABLE.m_Index]->m_intVal == 0;
  bToolMode = v8;
  bDepthBlurEnable_3 = !v9;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: false);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
    x = (int)params[NUM_LOOKUPS_0.m_Index]->m_VecVal.x;
    if ( x >= 3 )
      x = 3;
    if ( x > 0 )
    {
      v11 = SHADER_SAMPLER2;
      for ( flTime = x; flTime != 0; --flTime )
      {
        pShaderShadow->EnableTexture(this: pShaderShadow, a2: v11, a3: true);
        pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: v11++, a3: false);
      }
      v8 = bToolMode;
    }
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER8, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER8, a3: false);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "engine_post_vs20", a3: 0);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      _pshIndex.m_nTOOL_MODE = v8;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "TOOL_MODE", v8, "bToolMode");
      _pshIndex.m_nDEPTH_BLUR_ENABLE = bDepthBlurEnable_3;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "DEPTH_BLUR_ENABLE", bDepthBlurEnable_3, "bDepthBlurEnable");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "LINEAR_INPUT", 0, "bLinearInput");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS stat var %s = %d (%s)", "LINEAR_OUTPUT", 0, "bLinearOutput");
        }
      }
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "engine_post_ps20b",
        a3: 12288 * (_pshIndex.m_nTOOL_MODE + 2 * _pshIndex.m_nDEPTH_BLUR_ENABLE));
    }
    else
    {
      v81 = v8;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "TOOL_MODE", v8, "bToolMode");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DEPTH_BLUR_ENABLE", bDepthBlurEnable_3, "bDepthBlurEnable");
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "engine_post_ps20",
        a3: 48 * (v81 + 2 * bDepthBlurEnable_3));
      v8 = bToolMode;
    }
  }
  v12 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v90,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: v90,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: FBTEXTURE_0.m_Index,
      nFrameVar: -1);
    ccInfo.m_bIsEnabled = false;
    ccInfo.m_nLookupCount = 0;
    ccInfo.m_flDefaultWeight = 1.0;
    ccInfo.m_pLookupWeights[0] = 1.0;
    ccInfo.m_pLookupWeights[1] = 1.0;
    ccInfo.m_pLookupWeights[2] = 1.0;
    ccInfo.m_pLookupWeights[3] = 1.0;
    if ( v8 )
    {
      flTimea = params[TOOLTIME.m_Index]->m_VecVal.x;
      if ( params[DESATURATEENABLE.m_Index]->m_intVal != 0 )
      {
        v13 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
        bDesaturateEnable = true;
        if ( v13 >= 92 )
          goto LABEL_26;
      }
    }
    else
    {
      flTimea = v12->CurrentTime(this: v12);
    }
    bDesaturateEnable = false;
LABEL_26:
    v14 = v12->__vftable;
    if ( params[FADE.m_Index]->m_intVal != 0 )
    {
      v14->SetPixelShaderConstant(this: v12, a2: 15, a3: &params[FADECOLOR.m_Index]->m_VecVal.x, a4: 1, a5: false);
    }
    else
    {
      SetPixelShaderConstant = v14->SetPixelShaderConstant;
      memset(vViewportMad, 0, sizeof(vViewportMad));
      SetPixelShaderConstant(this: v12, a2: 15, a3: vViewportMad, a4: 1, a5: false);
    }
    if ( bDesaturateEnable )
    {
      v16 = params[DESATURATION.m_Index];
      v17 = v12->__vftable;
      memset(vViewportMad, 0, sizeof(vViewportMad));
      v18 = v16->m_VecVal.x;
      v19 = v17->SetPixelShaderConstant;
      vViewportMad[0] = v18;
      v19(this: v12, a2: 16, a3: vViewportMad, a4: 1, a5: false);
    }
    else if ( params[TOOLCOLORCORRECTION.m_Index]->m_intVal != 0 )
    {
      v20 = params[NUM_LOOKUPS_0.m_Index];
      ccInfo.m_bIsEnabled = true;
      v21 = (int)v20->m_VecVal.x;
      v22 = params[WEIGHT_DEFAULT_0.m_Index];
      ccInfo.m_nLookupCount = v21;
      v23 = params[WEIGHT0_0.m_Index];
      v24 = params[WEIGHT1_0.m_Index];
      ccInfo.m_flDefaultWeight = v22->m_VecVal.x;
      v25 = params[WEIGHT2_0.m_Index];
      ccInfo.m_pLookupWeights[0] = v23->m_VecVal.x;
      v26 = params[WEIGHT3_0.m_Index];
      ccInfo.m_pLookupWeights[1] = v24->m_VecVal.x;
      ccInfo.m_pLookupWeights[2] = v25->m_VecVal.x;
      ccInfo.m_pLookupWeights[3] = v26->m_VecVal.x;
    }
    else
    {
      v12->GetCurrentColorCorrection(this: v12, a2: &ccInfo);
    }
    m_nLookupCount = ccInfo.m_nLookupCount;
    if ( ccInfo.m_nLookupCount >= 3 )
      m_nLookupCount = 3;
    colCorrectNumLookups = m_nLookupCount;
    if ( m_nLookupCount > 0 )
    {
      v28 = 2;
      for ( bDepthBlurEnable = m_nLookupCount; bDepthBlurEnable != 0; --bDepthBlurEnable )
      {
        v12->BindStandardTexture(
          this: v12,
          a2: (Sampler_t)v28,
          a3: TEXTURE_BINDFLAGS_NONE,
          a4: (StandardTextureId_t)(v28 + 13));
        ++v28;
      }
    }
    v29 = params[FBTEXTURE_0.m_Index]->GetTextureValue(this: params[FBTEXTURE_0.m_Index]);
    bDepthBlurEnablea = 1.0 / (float)(*(int (__thiscall **)(int))(*(_DWORD *)v29 + 12))(a1: v29);
    v30 = (*(int (__thiscall **)(int))(*(_DWORD *)v29 + 16))(a1: v29);
    v31 = v12->SetPixelShaderConstant;
    offsets[0] = bDepthBlurEnablea;
    offsets[1] = 0.0;
    offsets[2] = 1.0 / (float)v30;
    LODWORD(offsets[3]) = LODWORD(bDepthBlurEnablea) ^ _mask__NegFloat_;
    v31(this: v12, a2: 0, a3: offsets, a4: 1, a5: false);
    v32 = params[AAINTERNAL1.m_Index];
    v33 = v12->SetPixelShaderConstant;
    tweakables[0] = v32->m_VecVal.x;
    y = v32->m_VecVal.y;
    v35 = params[AAINTERNAL3.m_Index];
    tweakables[1] = y;
    tweakables[2] = v35->m_VecVal.x;
    tweakables[3] = v35->m_VecVal.y;
    v33(this: v12, a2: 1, a3: tweakables, a4: 1, a5: false);
    SetVertexShaderConstant = v12->SetVertexShaderConstant;
    uvTrans = params[AAINTERNAL2.m_Index]->m_VecVal;
    SetVertexShaderConstant(this: v12, a2: 48, a3: &uvTrans.x, a4: 1, a5: false);
    v12->SetPixelShaderConstant(this: v12, a2: 3, a3: &ccInfo.m_flDefaultWeight, a4: 1, a5: false);
    v12->SetPixelShaderConstant(this: v12, a2: 4, a3: ccInfo.m_pLookupWeights, a4: 1, a5: false);
    v9 = params[BLOOMENABLE.m_Index]->m_intVal == 0;
    colCorrectEnabled = ccInfo.m_bIsEnabled;
    if ( v9 )
      v37 = 0.0;
    else
      v37 = 1.0;
    v38 = params[SCREENBLURSTRENGTH.m_Index];
    v39 = params[DEPTHBLURFOCALDISTANCE.m_Index];
    bloomConstant[0] = params[BLOOMAMOUNT_0.m_Index]->m_VecVal.x * v37;
    v40 = params[DEPTHBLURSTRENGTH.m_Index];
    bloomConstant[1] = v38->m_VecVal.x;
    bloomConstant[2] = v39->m_VecVal.x;
    bloomConstant[3] = v40->m_VecVal.x;
    if ( mat_screen_blur_override.m_pParent->m_Value.m_fValue >= 0.0 )
      bloomConstant[1] = mat_screen_blur_override.m_pParent->m_Value.m_fValue;
    if ( mat_depth_blur_focal_distance_override.m_pParent->m_Value.m_fValue >= 0.0 )
      bloomConstant[2] = mat_depth_blur_focal_distance_override.m_pParent->m_Value.m_fValue;
    if ( mat_depth_blur_strength_override.m_pParent->m_Value.m_fValue >= 0.0 )
      bloomConstant[3] = mat_depth_blur_strength_override.m_pParent->m_Value.m_fValue;
    v12->SetPixelShaderConstant(this: v12, a2: 5, a3: bloomConstant, a4: 1, a5: false);
    if ( params[VIGNETTEENABLE.m_Index]->m_intVal != 0 && params[ALLOWVIGNETTE.m_Index]->m_intVal != 0 )
    {
      bVignetteEnable = true;
      CBaseShader::BindTexture(
        this: v90,
        sampler1: SHADER_SAMPLER7,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: INTERNAL_VIGNETTETEXTURE.m_Index,
        nFrameVar: -1);
    }
    else
    {
      bVignetteEnable = false;
    }
    v41 = params[NOISEENABLE.m_Index]->m_intVal != 0 && params[ALLOWNOISE.m_Index]->m_intVal != 0;
    bDepthBlurEnable_3a = v41;
    v42 = params[FBTEXTURE_0.m_Index]->GetTextureValue(this: params[FBTEXTURE_0.m_Index]);
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v42 + 16))(a1: v42) >= 720 )
    {
      if ( v41 )
      {
        CBaseShader::BindTexture(
          this: v90,
          sampler1: SHADER_SAMPLER6,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: NOISETEXTURE.m_Index,
          nFrameVar: -1);
        v43 = params[NOISESCALE.m_Index];
        memset(vViewportMad, 0, sizeof(vViewportMad));
        m_fValue = v43->m_VecVal.x;
        vViewportMad[0] = m_fValue;
        if ( mat_grain_scale_override.m_pParent->m_Value.m_fValue != -1.0 )
        {
          m_fValue = mat_grain_scale_override.m_pParent->m_Value.m_fValue;
          vViewportMad[0] = m_fValue;
        }
        if ( m_fValue <= 0.0 )
          bDepthBlurEnable_3a = false;
        v12->SetPixelShaderConstant(this: v12, a2: 6, a3: vViewportMad, a4: 1, a5: false);
        v45 = v12->SetPixelShaderConstant;
        memset(&_pshIndex.m_nDEPTH_BLUR_ENABLE, 0, 12);
        *(float *)&_pshIndex.m_nTOOL_MODE = flTimea - (float)((float)(int)(float)(flTimea * 0.001) * 1000.0);
        v45(this: v12, a2: 7, a3: (const float *)&_pshIndex.m_nTOOL_MODE, a4: 1, a5: false);
      }
    }
    else
    {
      bDepthBlurEnable_3a = false;
    }
    if ( params[LOCALCONTRASTENABLE.m_Index]->m_intVal != 0 && params[ALLOWLOCALCONTRAST.m_Index]->m_intVal != 0 )
    {
      v9 = params[BLURREDVIGNETTEENABLE.m_Index]->m_intVal == 0;
      v46 = 1;
      bLocalContrastEnable = true;
      if ( !v9 )
      {
        bBlurredVignetteEnable = true;
        goto LABEL_71;
      }
    }
    else
    {
      v46 = 0;
      bLocalContrastEnable = false;
    }
    bBlurredVignetteEnable = false;
    if ( v46 == 0 )
    {
LABEL_82:
      v49 = params[FADETOBLACKSCALE.m_Index];
      v50 = v12->SetPixelShaderConstant;
      memset(vPsConst, 0, sizeof(vPsConst));
      vPsConst[0] = v49->m_VecVal.x;
      v50(this: v12, a2: 10, a3: vPsConst, a4: 1, a5: false);
      flTime_3 = vPsConst[0] > 0.0;
      bVomitEnable = params[VOMITENABLE.m_Index]->m_intVal != 0;
      if ( bVomitEnable )
      {
        CBaseShader::BindTexture(
          this: v90,
          sampler1: SHADER_SAMPLER8,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: SCREENEFFECTTEXTURE.m_Index,
          nFrameVar: -1);
        v51 = params[VOMITCOLOR1.m_Index];
        v52 = params[VOMITREFRACTSCALE.m_Index];
        vPsConst[0] = v51->m_VecVal.x;
        vPsConst[1] = v51->m_VecVal.y;
        z = v51->m_VecVal.z;
        v54 = v12->__vftable;
        vPsConst[2] = z;
        v55 = v52->m_VecVal.x;
        v56 = v54->SetPixelShaderConstant;
        vPsConst[3] = v55;
        v56(this: v12, a2: 11, a3: vPsConst, a4: 1, a5: false);
        v57 = params[VOMITCOLOR2.m_Index];
        v58 = v12->SetPixelShaderConstant;
        vPsConst[0] = v57->m_VecVal.x;
        vPsConst[1] = v57->m_VecVal.y;
        vPsConst[2] = v57->m_VecVal.z;
        vPsConst[3] = 0.0;
        v58(this: v12, a2: 12, a3: vPsConst, a4: 1, a5: false);
        v12->GetCurrentViewport(this: v12, a2: &nViewportX, a3: &nViewportY, a4: &nViewportWidth, a5: &nViewportHeight);
        v12->GetCurrentRenderTargetDimensions(this: v12, a2: (int *)&pShaderAPI, a3: &nRtHeight);
        vViewportMad[0] = (float)(int)pShaderAPI / (float)nViewportWidth;
        vViewportMad[1] = (float)nRtHeight / (float)nViewportHeight;
        v59 = v12->SetPixelShaderConstant;
        LODWORD(vViewportMad[2]) = COERCE_UNSIGNED_INT((float)nViewportX / (float)nViewportWidth) ^ _mask__NegFloat_;
        LODWORD(vViewportMad[3]) = COERCE_UNSIGNED_INT((float)nViewportY / (float)nViewportHeight) ^ _mask__NegFloat_;
        v59(this: v12, a2: 13, a3: vViewportMad, a4: 1, a5: false);
        v60 = v12->SetPixelShaderConstant;
        vViewportMad[0] = (float)nViewportWidth / (float)(int)pShaderAPI;
        vViewportMad[1] = (float)nViewportHeight / (float)nRtHeight;
        vViewportMad[2] = (float)nViewportX / (float)(int)pShaderAPI;
        vViewportMad[3] = (float)nViewportY / (float)nRtHeight;
        v60(this: v12, a2: 14, a3: vViewportMad, a4: 1, a5: false);
      }
      if ( colCorrectEnabled == 0 )
        colCorrectNumLookups = 0;
      v61 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      v62 = v61 == HDR_TYPE_FLOAT;
      if ( !bToolMode
        || v61 != HDR_TYPE_FLOAT
        || (v63 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig), HIBYTE(pShaderAPI) = 1, v63 != HDR_TYPE_FLOAT) )
      {
        HIBYTE(pShaderAPI) = 0;
      }
      m_intVal = params[FADE.m_Index]->m_intVal;
      if ( m_intVal >= 0 )
      {
        nViewportWidth = 2;
        if ( m_intVal <= 2 )
          nViewportWidth = m_intVal;
      }
      else
      {
        nViewportWidth = 0;
      }
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS dyn  var %s = %d (%s)", "AA_ENABLE", 0, "aaEnabled");
          if ( g_shaderConfigDumpEnable )
            printf(
              format: "\n   PS dyn  var %s = %d (%s)",
              "COL_CORRECT_NUM_LOOKUPS",
              colCorrectNumLookups,
              "colCorrectNumLookups");
        }
        v70 = bVomitEnable;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "VOMIT_ENABLE", bVomitEnable, "bVomitEnable");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS dyn  var %s = %d (%s)", "FADE_TO_BLACK", flTime_3, "bFadeToBlackEnable");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS dyn  var %s = %d (%s)", "FADE_TYPE", nViewportWidth, "nFadeType");
        }
        v12->SetPixelShaderIndex(
          this: v12,
          a2: colCorrectNumLookups + 4 * (flTime_3 + 2 * (v70 + nViewportWidth + 2 * v70)));
      }
      else
      {
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS dyn  var %s = %d (%s)", "AA_ENABLE", 0, "aaEnabled");
          if ( g_shaderConfigDumpEnable )
            printf(
              format: "\n   PS dyn  var %s = %d (%s)",
              "COL_CORRECT_NUM_LOOKUPS",
              colCorrectNumLookups,
              "colCorrectNumLookups");
        }
        v71 = v62;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "CONVERT_FROM_LINEAR", v62, "bConvertFromLinear");
        v72 = HIBYTE(pShaderAPI) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "CONVERT_TO_LINEAR", HIBYTE(pShaderAPI), "bConvertToLinear");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "NOISE_ENABLE", bDepthBlurEnable_3a, "bNoiseEnable");
        v73 = bVignetteEnable;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "VIGNETTE_ENABLE", bVignetteEnable, "bVignetteEnable");
        v74 = bLocalContrastEnable;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "LOCAL_CONTRAST_ENABLE",
            bLocalContrastEnable,
            "bLocalContrastEnable");
        v75 = bBlurredVignetteEnable;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "BLURRED_VIGNETTE_ENABLE",
            bBlurredVignetteEnable,
            "bBlurredVignetteEnable");
        v76 = bVomitEnable;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "VOMIT_ENABLE", bVomitEnable, "bVomitEnable");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS dyn  var %s = %d (%s)", "FADE_TO_BLACK", flTime_3, "bFadeToBlackEnable");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS dyn  var %s = %d (%s)", "FADE_TYPE", nViewportWidth, "nFadeType");
        }
        v65 = params[TV_GAMMA.m_Index]->m_intVal;
        v66 = v65 != 0 && bToolMode;
        if ( g_shaderConfigDumpEnable )
        {
          v67 = v65 != 0 && bToolMode;
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "TV_GAMMA",
            v67,
            "params[TV_GAMMA]->GetIntValue() && bToolMode ? 1 : 0");
        }
        v68 = bDesaturateEnable;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "DESATURATEENABLE", bDesaturateEnable, "bDesaturateEnable");
        v69 = bDepthBlurEnable_3a + 2 * (v73 + 2 * (v74 + 2 * (v75 + 2 * (v76 + 2 * (v66 + 2 * v68)))));
        v12->SetPixelShaderIndex(
          this: v12,
          a2: colCorrectNumLookups + 4 * (v71 + 2 * (v72 + 2 * (flTime_3 + 2 * (v69 + nViewportWidth + 2 * v69)))));
      }
      v12->SetVertexShaderIndex(this: v12, a2: 0);
      goto LABEL_138;
    }
LABEL_71:
    v47 = params[LOCALCONTRASTSCALE.m_Index];
    memset(vViewportMad, 0, sizeof(vViewportMad));
    vViewportMad[0] = v47->m_VecVal.x;
    if ( mat_local_contrast_scale_override.m_pParent->m_Value.m_fValue != 0.0 )
      vViewportMad[0] = mat_local_contrast_scale_override.m_pParent->m_Value.m_fValue;
    vViewportMad[1] = params[LOCALCONTRASTMIDTONEMASK.m_Index]->m_VecVal.x;
    if ( mat_local_contrast_midtone_mask_override.m_pParent->m_Value.m_fValue >= 0.0 )
      vViewportMad[1] = mat_local_contrast_midtone_mask_override.m_pParent->m_Value.m_fValue;
    v48 = v12->SetPixelShaderConstant;
    vViewportMad[2] = params[BLURREDVIGNETTESCALE.m_Index]->m_VecVal.x;
    v48(this: v12, a2: 8, a3: vViewportMad, a4: 1, a5: false);
    vViewportMad[0] = params[LOCALCONTRASTVIGNETTESTART.m_Index]->m_VecVal.x;
    if ( mat_local_contrast_vignette_start_override.m_pParent->m_Value.m_fValue >= 0.0 )
      vViewportMad[0] = mat_local_contrast_vignette_start_override.m_pParent->m_Value.m_fValue;
    vViewportMad[1] = params[LOCALCONTRASTVIGNETTEEND.m_Index]->m_VecVal.x;
    if ( mat_local_contrast_vignette_end_override.m_pParent->m_Value.m_fValue >= 0.0 )
      vViewportMad[1] = mat_local_contrast_vignette_end_override.m_pParent->m_Value.m_fValue;
    vViewportMad[2] = params[LOCALCONTRASTEDGESCALE.m_Index]->m_VecVal.x;
    if ( mat_local_contrast_edge_scale_override.m_pParent->m_Value.m_fValue >= -1.0 )
      vViewportMad[2] = mat_local_contrast_edge_scale_override.m_pParent->m_Value.m_fValue;
    v12->SetPixelShaderConstant(this: v12, a2: 9, a3: vViewportMad, a4: 1, a5: false);
    goto LABEL_82;
  }
LABEL_138:
  CBaseShader::Draw(this: v90, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000ED30
// Name: public: virtual struct ShaderParamInfo_t const __near & Engine_Post::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Engine_Post::CShaderParam *__thiscall Engine_Post::CShader::GetParamInfo(Engine_Post::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_28.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Engine_Post::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000ED60
// Name: public: virtual struct ShaderParamInfo_t const __near & Engine_Post_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *__thiscall Engine_Post_dx9::CShader::GetParamInfo(
        Engine_Post_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_29.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Engine_Post_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000ED90
// Name: public: Engine_Post_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *__thiscall Engine_Post_dx9::CShaderParam::CShaderParam(
        Engine_Post_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Engine_Post_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Engine_Post_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_29.m_Size + 13;
  m_Size = s_ShaderParams_29.m_Size;
  v8 = s_ShaderParams_29.m_Size;
  if ( s_ShaderParams_29.m_Size + 1 > s_ShaderParams_29.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_29,
      num: s_ShaderParams_29.m_Size - s_ShaderParams_29.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_29.m_Size;
  }
  m_pMemory = s_ShaderParams_29.m_Memory.m_pMemory;
  s_ShaderParams_29.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_29.m_pElements = s_ShaderParams_29.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_29.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_29.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_29.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10060470
// Name: Engine_Post::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Engine_Post::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Engine_Post::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10060480
// Name: Engine_Post::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Engine_Post::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_28);
  s_ShaderInstance_28.__vftable = (Engine_Post::CShader_vtbl *)&Engine_Post::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100604A0
// Name: Engine_Post_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Engine_Post_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Engine_Post_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100604B0
// Name: Engine_Post_dx9::_dynamic_initializer_for__FBTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__FBTEXTURE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &FBTEXTURE_0,
           pName: "$FBTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_FullFrameFB",
           pHelp: "Full framebuffer texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100604D0
// Name: Engine_Post_dx9::_dynamic_initializer_for__AAENABLE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__AAENABLE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &AAENABLE,
           pName: "$AAENABLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable software anti-aliasing",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100604F0
// Name: Engine_Post_dx9::_dynamic_initializer_for__AAINTERNAL1__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__AAINTERNAL1__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &AAINTERNAL1,
           pName: "$AAINTERNAL1",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 0 0]",
           pHelp: "Internal anti-aliasing values set via material proxy",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060510
// Name: Engine_Post_dx9::_dynamic_initializer_for__AAINTERNAL2__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__AAINTERNAL2__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &AAINTERNAL2,
           pName: "$AAINTERNAL2",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 0 0]",
           pHelp: "Internal anti-aliasing values set via material proxy",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060530
// Name: Engine_Post_dx9::_dynamic_initializer_for__AAINTERNAL3__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__AAINTERNAL3__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &AAINTERNAL3,
           pName: "$AAINTERNAL3",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 0 0]",
           pHelp: "Internal anti-aliasing values set via material proxy",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060550
// Name: Engine_Post_dx9::_dynamic_initializer_for__BLOOMENABLE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__BLOOMENABLE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &BLOOMENABLE,
           pName: "$BLOOMENABLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "Enable bloom",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060570
// Name: Engine_Post_dx9::_dynamic_initializer_for__BLOOMAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__BLOOMAMOUNT__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &BLOOMAMOUNT_0,
           pName: "$BLOOMAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Bloom scale factor",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060590
// Name: Engine_Post_dx9::_dynamic_initializer_for__SCREENEFFECTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__SCREENEFFECTTEXTURE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &SCREENEFFECTTEXTURE,
           pName: "$SCREENEFFECTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "used for paint or vomit screen effect",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100605B0
// Name: Engine_Post_dx9::_dynamic_initializer_for__DEPTHBLURENABLE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__DEPTHBLURENABLE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &DEPTHBLURENABLE,
           pName: "$DEPTHBLURENABLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Inexpensive depth-of-field substitute",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100605D0
// Name: Engine_Post_dx9::_dynamic_initializer_for__ALLOWVIGNETTE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__ALLOWVIGNETTE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &ALLOWVIGNETTE,
           pName: "$ALLOWVIGNETTE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Allow vignette",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100605F0
// Name: Engine_Post_dx9::_dynamic_initializer_for__VIGNETTEENABLE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__VIGNETTEENABLE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &VIGNETTEENABLE,
           pName: "$VIGNETTEENABLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable vignette",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060610
// Name: Engine_Post_dx9::_dynamic_initializer_for__INTERNAL_VIGNETTETEXTURE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__INTERNAL_VIGNETTETEXTURE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &INTERNAL_VIGNETTETEXTURE,
           pName: "$INTERNAL_VIGNETTETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "dev/vignette",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060630
// Name: Engine_Post_dx9::_dynamic_initializer_for__ALLOWNOISE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__ALLOWNOISE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &ALLOWNOISE,
           pName: "$ALLOWNOISE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Allow noise",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060650
// Name: Engine_Post_dx9::_dynamic_initializer_for__NOISEENABLE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__NOISEENABLE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &NOISEENABLE,
           pName: "$NOISEENABLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable noise",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060670
// Name: Engine_Post_dx9::_dynamic_initializer_for__NOISESCALE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__NOISESCALE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &NOISESCALE,
           pName: "$NOISESCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Noise scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060690
// Name: Engine_Post_dx9::_dynamic_initializer_for__NOISETEXTURE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__NOISETEXTURE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &NOISETEXTURE,
           pName: "$NOISETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Noise texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100606B0
// Name: Engine_Post_dx9::_dynamic_initializer_for__ALLOWLOCALCONTRAST__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__ALLOWLOCALCONTRAST__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &ALLOWLOCALCONTRAST,
           pName: "$ALLOWLOCALCONTRAST",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable local contrast enhancement",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100606D0
// Name: Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTENABLE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTENABLE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &LOCALCONTRASTENABLE,
           pName: "$LOCALCONTRASTENABLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable local contrast enhancement",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100606F0
// Name: Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTSCALE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTSCALE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &LOCALCONTRASTSCALE,
           pName: "$LOCALCONTRASTSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Local contrast scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060710
// Name: Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTMIDTONEMASK__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTMIDTONEMASK__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &LOCALCONTRASTMIDTONEMASK,
           pName: "$LOCALCONTRASTMIDTONEMASK",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Local contrast midtone mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060730
// Name: Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTVIGNETTESTART__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTVIGNETTESTART__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &LOCALCONTRASTVIGNETTESTART,
           pName: "$LOCALCONTRASTVIGNETTESTART",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable local contrast enhancement",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060750
// Name: Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTVIGNETTEEND__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTVIGNETTEEND__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &LOCALCONTRASTVIGNETTEEND,
           pName: "$LOCALCONTRASTVIGNETTEEND",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Local contrast scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060770
// Name: Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTEDGESCALE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__LOCALCONTRASTEDGESCALE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &LOCALCONTRASTEDGESCALE,
           pName: "$LOCALCONTRASTEDGESCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Local contrast midtone mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060790
// Name: Engine_Post_dx9::_dynamic_initializer_for__BLURREDVIGNETTEENABLE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__BLURREDVIGNETTEENABLE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &BLURREDVIGNETTEENABLE,
           pName: "$BLURREDVIGNETTEENABLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable blurred vignette",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100607B0
// Name: Engine_Post_dx9::_dynamic_initializer_for__BLURREDVIGNETTESCALE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__BLURREDVIGNETTESCALE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &BLURREDVIGNETTESCALE,
           pName: "$BLURREDVIGNETTESCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "blurred vignette strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100607D0
// Name: Engine_Post_dx9::_dynamic_initializer_for__FADETOBLACKSCALE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__FADETOBLACKSCALE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &FADETOBLACKSCALE,
           pName: "$FADETOBLACKSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "fade strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100607F0
// Name: Engine_Post_dx9::_dynamic_initializer_for__DEPTHBLURFOCALDISTANCE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__DEPTHBLURFOCALDISTANCE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &DEPTHBLURFOCALDISTANCE,
           pName: "$DEPTHBLURFOCALDISTANCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Distance in dest-alpha space [0,1] of focal plane.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060810
// Name: Engine_Post_dx9::_dynamic_initializer_for__DEPTHBLURSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__DEPTHBLURSTRENGTH__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &DEPTHBLURSTRENGTH,
           pName: "$DEPTHBLURSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Strength of depth-blur effect",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060830
// Name: Engine_Post_dx9::_dynamic_initializer_for__SCREENBLURSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__SCREENBLURSTRENGTH__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &SCREENBLURSTRENGTH,
           pName: "$SCREENBLURSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Full-screen blur factor",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060850
// Name: Engine_Post_dx9::_dynamic_initializer_for__VOMITCOLOR1__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__VOMITCOLOR1__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &VOMITCOLOR1,
           pName: "$VOMITCOLOR1",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0 0]",
           pHelp: "1st vomit blend color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060870
// Name: Engine_Post_dx9::_dynamic_initializer_for__VOMITCOLOR2__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__VOMITCOLOR2__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &VOMITCOLOR2,
           pName: "$VOMITCOLOR2",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0 0]",
           pHelp: "2st vomit blend color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060890
// Name: Engine_Post_dx9::_dynamic_initializer_for__VOMITREFRACTSCALE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__VOMITREFRACTSCALE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &VOMITREFRACTSCALE,
           pName: "$VOMITREFRACTSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.15",
           pHelp: "vomit refract strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100608B0
// Name: Engine_Post_dx9::_dynamic_initializer_for__VOMITENABLE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__VOMITENABLE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &VOMITENABLE,
           pName: "$VOMITENABLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable vomit refract",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100608D0
// Name: Engine_Post_dx9::_dynamic_initializer_for__FADECOLOR__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__FADECOLOR__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &FADECOLOR,
           pName: "$FADECOLOR",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 0 0]",
           pHelp: "viewfade color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100608F0
// Name: Engine_Post_dx9::_dynamic_initializer_for__FADE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__FADE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &FADE,
           pName: "$FADE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "fade type. 0 = off, 1 = lerp, 2 = modulate",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060910
// Name: Engine_Post_dx9::_dynamic_initializer_for__TV_GAMMA__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__TV_GAMMA__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &TV_GAMMA,
           pName: "$TV_GAMMA",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "0 default, 1 used for laying off 360 movies",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060930
// Name: Engine_Post_dx9::_dynamic_initializer_for__DESATURATEENABLE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__DESATURATEENABLE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &DESATURATEENABLE,
           pName: "$DESATURATEENABLE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Desaturate with math, turns off color correction",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060950
// Name: Engine_Post_dx9::_dynamic_initializer_for__DESATURATION__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__DESATURATION__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &DESATURATION,
           pName: "$DESATURATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Desaturation Amount",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060970
// Name: Engine_Post_dx9::_dynamic_initializer_for__TOOLMODE__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__TOOLMODE__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &TOOLMODE,
           pName: "$TOOLMODE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "tool mode",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060990
// Name: Engine_Post_dx9::_dynamic_initializer_for__TOOLCOLORCORRECTION__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__TOOLCOLORCORRECTION__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &TOOLCOLORCORRECTION,
           pName: "$TOOLCOLORCORRECTION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "tool color correction override",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100609B0
// Name: Engine_Post_dx9::_dynamic_initializer_for__WEIGHT_DEFAULT__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__WEIGHT_DEFAULT__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &WEIGHT_DEFAULT_0,
           pName: "$WEIGHT_DEFAULT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "weight default",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100609D0
// Name: Engine_Post_dx9::_dynamic_initializer_for__WEIGHT0__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__WEIGHT0__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &WEIGHT0_0,
           pName: "$WEIGHT0",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "weight0",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100609F0
// Name: Engine_Post_dx9::_dynamic_initializer_for__WEIGHT1__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__WEIGHT1__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &WEIGHT1_0,
           pName: "$WEIGHT1",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "weight1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060A10
// Name: Engine_Post_dx9::_dynamic_initializer_for__WEIGHT2__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__WEIGHT2__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &WEIGHT2_0,
           pName: "$WEIGHT2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "weight2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060A30
// Name: Engine_Post_dx9::_dynamic_initializer_for__WEIGHT3__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__WEIGHT3__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &WEIGHT3_0,
           pName: "$WEIGHT3",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "weight3",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060A50
// Name: Engine_Post_dx9::_dynamic_initializer_for__NUM_LOOKUPS__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__NUM_LOOKUPS__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &NUM_LOOKUPS_0,
           pName: "$NUM_LOOKUPS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "num_lookups",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060A70
// Name: Engine_Post_dx9::_dynamic_initializer_for__TOOLTIME__
// Source: json
//------------------------------------------------------------------------------
Engine_Post_dx9::CShaderParam *Engine_Post_dx9::_dynamic_initializer_for__TOOLTIME__()
{
  return Engine_Post_dx9::CShaderParam::CShaderParam(
           this: &TOOLTIME,
           pName: "$TOOLTIME",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "tooltime",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060A90
// Name: Engine_Post_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Engine_Post_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_29);
  s_ShaderInstance_29.__vftable = (Engine_Post_dx9::CShader_vtbl *)&Engine_Post_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B140
// Name: Engine_Post::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Engine_Post::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_28);
}

//------------------------------------------------------------------------------
// Address: 0x1006B150
// Name: Engine_Post_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Engine_Post_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_29);
}
