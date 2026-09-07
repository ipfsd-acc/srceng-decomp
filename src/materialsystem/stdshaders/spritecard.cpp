// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/spritecard.cpp
// Functions: 79
// ============================================================

#include "materialsystem\stdshaders\spritecard.h"

//------------------------------------------------------------------------------
// Address: 0x100337C0
// Name: int GetDefaultDepthFeatheringValue(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetDefaultDepthFeatheringValue()
{
  int result; // eax
  int v1; // eax

  result = iRetVal;
  if ( iRetVal == -1 )
  {
    v1 = _CommandLine();
    result = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v1 + 12))(
               a1: v1,
               a2: "-softparticlesdefaultoff",
               a3: 0) == 0;
    iRetVal = result;
  }
  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    ConVarRef::ConVarRef(this: &mat_reduceparticles, pName: "mat_reduceparticles");
    result = iRetVal;
  }
  if ( mat_reduceparticles.m_pConVarState->m_Value.m_nValue != 0 )
  {
    iRetVal = 0;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033830
// Name: public: int spritecard_ps20b_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall spritecard_ps20b_Static_Index::GetIndex(spritecard_ps20b_Static_Index *this)
{
  return this->m_nDUALSEQUENCE
       + 2
       * (this->m_nSEQUENCE_BLEND_MODE
        + 3
        * (this->m_nADDBASETEXTURE2
         + 2
         * (this->m_nMAXLUMFRAMEBLEND1
          + 2
          * (this->m_nMAXLUMFRAMEBLEND2
           + 2
           * (this->m_nEXTRACTGREENALPHA
            + 2
            * (this->m_nCOLORRAMP
             + 2
             * (this->m_nANIMBLEND
              + 2
              * (this->m_nADDSELF
               + 2
               * (this->m_nMOD2X
                + 2
                * (this->m_nDEPTHBLEND
                 + this->m_nINVERSEDEPTHBLEND
                 + this->m_nSHADER_SRGB_READ
                 + this->m_nCOLOR_LERP_PS
                 + 2
                 * (this->m_nPACKED_INTERPOLATOR
                  + 2
                  * (this->m_nDISTANCEALPHA
                   + 2 * (this->m_nSOFTEDGES + 2 * (this->m_nOUTLINE + 2 * this->m_nMULOUTPUTBYALPHA))))))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x100338A0
// Name: public: virtual char const __near * Spritecard::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Spritecard::CShader::GetName(Spritecard::CShader *this)
{
  return s_Name_115;
}

//------------------------------------------------------------------------------
// Address: 0x100338B0
// Name: public: virtual int Spritecard::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Spritecard::CShader::GetFlags(Spritecard::CShader *this)
{
  return s_nFlags_42;
}

//------------------------------------------------------------------------------
// Address: 0x100338C0
// Name: public: virtual void Spritecard::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Spritecard::CShader::OnInitShaderInstance(
        Spritecard::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  bool v5; // bl

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  if ( params[6]->IsDefined(this: params[6]) )
  {
    v5 = false;
    if ( params[EXTRACTGREENALPHA.m_Index]->IsDefined(this: params[EXTRACTGREENALPHA.m_Index]) )
      v5 = params[EXTRACTGREENALPHA.m_Index]->m_intVal != 0;
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: v5 ? 0 : 0x80000);
  }
  if ( params[RAMPTEXTURE.m_Index]->IsDefined(this: params[RAMPTEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: RAMPTEXTURE.m_Index, nAdditionalCreationFlags: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x10033960
// Name: public: virtual void Spritecard::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Spritecard::CShader::OnInitShaderParams(
        Spritecard::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  IMaterialVar *v3; // ebx
  IMaterialVar_vtbl *v4; // edi
  int DefaultDepthFeatheringValue; // eax
  int m_Index; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  VMatrix mat; // [esp+ACh] [ebp-40h] BYREF

  if ( !params[MAXDISTANCE.m_Index]->IsDefined(this: params[MAXDISTANCE.m_Index]) )
    ((void (__stdcall *)(int))params[MAXDISTANCE.m_Index]->SetFloatValue)(a1: 1203982336);
  if ( !params[FARFADEINTERVAL.m_Index]->IsDefined(this: params[FARFADEINTERVAL.m_Index]) )
    ((void (__stdcall *)(int))params[FARFADEINTERVAL.m_Index]->SetFloatValue)(a1: 1137180672);
  if ( !params[MAXSIZE.m_Index]->IsDefined(this: params[MAXSIZE.m_Index]) )
    ((void (__stdcall *)(int))params[MAXSIZE.m_Index]->SetFloatValue)(a1: 1101004800);
  if ( !params[ENDFADESIZE.m_Index]->IsDefined(this: params[ENDFADESIZE.m_Index]) )
    ((void (__stdcall *)(int))params[ENDFADESIZE.m_Index]->SetFloatValue)(a1: 1101004800);
  if ( !params[STARTFADESIZE.m_Index]->IsDefined(this: params[STARTFADESIZE.m_Index]) )
    ((void (__stdcall *)(int))params[STARTFADESIZE.m_Index]->SetFloatValue)(a1: 1092616192);
  if ( !params[DEPTHBLENDSCALE_1.m_Index]->IsDefined(this: params[DEPTHBLENDSCALE_1.m_Index]) )
    ((void (__stdcall *)(int))params[DEPTHBLENDSCALE_1.m_Index]->SetFloatValue)(a1: 1112014848);
  if ( !params[OVERBRIGHTFACTOR.m_Index]->IsDefined(this: params[OVERBRIGHTFACTOR.m_Index]) )
    ((void (__stdcall *)(int))params[OVERBRIGHTFACTOR.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[ADDBASETEXTURE2.m_Index]->IsDefined(this: params[ADDBASETEXTURE2.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[ADDBASETEXTURE2.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[ADDSELF.m_Index]->IsDefined(this: params[ADDSELF.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[ADDSELF.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[ZOOMANIMATESEQ2.m_Index]->IsDefined(this: params[ZOOMANIMATESEQ2.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[ZOOMANIMATESEQ2.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[ALPHATRAILFADE.m_Index]->IsDefined(this: params[ALPHATRAILFADE.m_Index]) )
    ((void (__stdcall *)(int))params[ALPHATRAILFADE.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[RADIUSTRAILFADE.m_Index]->IsDefined(this: params[RADIUSTRAILFADE.m_Index]) )
    ((void (__stdcall *)(int))params[RADIUSTRAILFADE.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[VERTEXFOGAMOUNT.m_Index]->IsDefined(this: params[VERTEXFOGAMOUNT.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[VERTEXFOGAMOUNT.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[OUTLINEALPHA.m_Index]->IsDefined(this: params[OUTLINEALPHA.m_Index]) )
    ((void (__stdcall *)(int))params[OUTLINEALPHA.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[ORIENTATIONMATRIX.m_Index]->IsDefined(this: params[ORIENTATIONMATRIX.m_Index]) )
  {
    MatrixSetIdentity(dst: &mat);
    params[ORIENTATIONMATRIX.m_Index]->SetMatrixValue(this: params[ORIENTATIONMATRIX.m_Index], a2: &mat);
  }
  if ( !params[CROPFACTOR.m_Index]->IsDefined(this: params[CROPFACTOR.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, int, int))params[CROPFACTOR.m_Index]->SetVecValue_3)(
      a1: params[CROPFACTOR.m_Index],
      a2: 1065353216,
      a3: 1065353216);
  if ( !params[DEPTHBLEND_1.m_Index]->IsDefined(this: params[DEPTHBLEND_1.m_Index]) )
  {
    v3 = params[DEPTHBLEND_1.m_Index];
    v4 = v3->__vftable;
    DefaultDepthFeatheringValue = GetDefaultDepthFeatheringValue();
    v4->SetIntValue(this: v3, a2: DefaultDepthFeatheringValue);
  }
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    params[DEPTHBLEND_1.m_Index]->SetIntValue(this: params[DEPTHBLEND_1.m_Index], a2: 0);
  if ( DUALSEQUENCE.m_Index != -1 )
  {
    m_Index = DUALSEQUENCE.m_Index;
    if ( !params[DUALSEQUENCE.m_Index]->IsDefined(this: params[DUALSEQUENCE.m_Index]) )
      params[m_Index]->SetIntValue(this: params[m_Index], a2: 0);
  }
  if ( MAXLUMFRAMEBLEND1.m_Index != -1 )
  {
    v7 = MAXLUMFRAMEBLEND1.m_Index;
    if ( !params[MAXLUMFRAMEBLEND1.m_Index]->IsDefined(this: params[MAXLUMFRAMEBLEND1.m_Index]) )
      params[v7]->SetIntValue(this: params[v7], a2: 0);
  }
  if ( MAXLUMFRAMEBLEND2.m_Index != -1 )
  {
    v8 = MAXLUMFRAMEBLEND2.m_Index;
    if ( !params[MAXLUMFRAMEBLEND2.m_Index]->IsDefined(this: params[MAXLUMFRAMEBLEND2.m_Index]) )
      params[v8]->SetIntValue(this: params[v8], a2: 0);
  }
  if ( EXTRACTGREENALPHA.m_Index != -1 )
  {
    v9 = EXTRACTGREENALPHA.m_Index;
    if ( !params[EXTRACTGREENALPHA.m_Index]->IsDefined(this: params[EXTRACTGREENALPHA.m_Index]) )
      params[v9]->SetIntValue(this: params[v9], a2: 0);
  }
  if ( ADDOVERBLEND.m_Index != -1 )
  {
    v10 = ADDOVERBLEND.m_Index;
    if ( !params[ADDOVERBLEND.m_Index]->IsDefined(this: params[ADDOVERBLEND.m_Index]) )
      params[v10]->SetIntValue(this: params[v10], a2: 0);
  }
  if ( BLENDFRAMES.m_Index != -1 )
  {
    v11 = BLENDFRAMES.m_Index;
    if ( !params[BLENDFRAMES.m_Index]->IsDefined(this: params[BLENDFRAMES.m_Index]) )
      params[v11]->SetIntValue(this: params[v11], a2: 1);
  }
  if ( DISTANCEALPHA.m_Index != -1 )
  {
    v12 = DISTANCEALPHA.m_Index;
    if ( !params[DISTANCEALPHA.m_Index]->IsDefined(this: params[DISTANCEALPHA.m_Index]) )
      params[v12]->SetIntValue(this: params[v12], a2: 0);
  }
  if ( OUTLINE.m_Index != -1 )
  {
    v13 = OUTLINE.m_Index;
    if ( !params[OUTLINE.m_Index]->IsDefined(this: params[OUTLINE.m_Index]) )
      params[v13]->SetIntValue(this: params[v13], a2: 0);
  }
  if ( SOFTEDGES.m_Index != -1 )
  {
    v14 = SOFTEDGES.m_Index;
    if ( !params[SOFTEDGES.m_Index]->IsDefined(this: params[SOFTEDGES.m_Index]) )
      params[v14]->SetIntValue(this: params[v14], a2: 0);
  }
  if ( PERPARTICLEOUTLINE.m_Index != -1 )
  {
    v15 = PERPARTICLEOUTLINE.m_Index;
    if ( !params[PERPARTICLEOUTLINE.m_Index]->IsDefined(this: params[PERPARTICLEOUTLINE.m_Index]) )
      params[v15]->SetIntValue(this: params[v15], a2: 0);
  }
  if ( MULOUTPUTBYALPHA.m_Index != -1 )
  {
    v16 = MULOUTPUTBYALPHA.m_Index;
    if ( !params[MULOUTPUTBYALPHA.m_Index]->IsDefined(this: params[MULOUTPUTBYALPHA.m_Index]) )
      params[v16]->SetIntValue(this: params[v16], a2: 0);
  }
  if ( INTENSITY.m_Index != -1 )
  {
    v17 = INTENSITY.m_Index;
    if ( !params[INTENSITY.m_Index]->IsDefined(this: params[INTENSITY.m_Index]) )
      ((void (__stdcall *)(int))params[v17]->SetFloatValue)(a1: 1065353216);
  }
  if ( !params[USEINSTANCING.m_Index]->IsDefined(this: params[USEINSTANCING.m_Index]) )
    params[USEINSTANCING.m_Index]->SetIntValue(this: params[USEINSTANCING.m_Index], a2: 0);
  if ( SHADERSRGBREAD360_1.m_Index != -1 )
  {
    v18 = SHADERSRGBREAD360_1.m_Index;
    if ( !params[SHADERSRGBREAD360_1.m_Index]->IsDefined(this: params[SHADERSRGBREAD360_1.m_Index]) )
      params[v18]->SetIntValue(this: params[v18], a2: 0);
  }
  if ( OPAQUE.m_Index != -1 )
  {
    v19 = OPAQUE.m_Index;
    if ( !params[OPAQUE.m_Index]->IsDefined(this: params[OPAQUE.m_Index]) )
      params[v19]->SetIntValue(this: params[v19], a2: 0);
  }
  if ( VERTEXCOLORLERP.m_Index != -1 )
  {
    v20 = VERTEXCOLORLERP.m_Index;
    if ( !params[VERTEXCOLORLERP.m_Index]->IsDefined(this: params[VERTEXCOLORLERP.m_Index]) )
      params[v20]->SetIntValue(this: params[v20], a2: 0);
  }
  if ( !params[LERPCOLOR1.m_Index]->IsDefined(this: params[LERPCOLOR1.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, int, _DWORD, _DWORD))params[LERPCOLOR1.m_Index]->SetVecValue_2)(
      a1: params[LERPCOLOR1.m_Index],
      a2: 1065353216,
      a3: 0,
      a4: 0);
  if ( !params[LERPCOLOR2.m_Index]->IsDefined(this: params[LERPCOLOR2.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, _DWORD, int, _DWORD))params[LERPCOLOR2.m_Index]->SetVecValue_2)(
      a1: params[LERPCOLOR2.m_Index],
      a2: 0,
      a3: 1065353216,
      a4: 0);
  if ( params[OPAQUE.m_Index]->m_intVal != 0 )
  {
    ((void (__stdcall *)(_DWORD))params[ADDBASETEXTURE2.m_Index]->SetFloatValue)(a1: 0);
    params[DUALSEQUENCE.m_Index]->SetIntValue(this: params[DUALSEQUENCE.m_Index], a2: 0);
    params[SEQUENCE_BLEND_MODE.m_Index]->SetIntValue(this: params[SEQUENCE_BLEND_MODE.m_Index], a2: 0);
    params[MAXLUMFRAMEBLEND1.m_Index]->SetIntValue(this: params[MAXLUMFRAMEBLEND1.m_Index], a2: 0);
    params[MAXLUMFRAMEBLEND2.m_Index]->SetIntValue(this: params[MAXLUMFRAMEBLEND2.m_Index], a2: 0);
    params[EXTRACTGREENALPHA.m_Index]->SetIntValue(this: params[EXTRACTGREENALPHA.m_Index], a2: 0);
    params[RAMPTEXTURE.m_Index]->SetUndefined(this: params[RAMPTEXTURE.m_Index]);
    params[ZOOMANIMATESEQ2.m_Index]->SetIntValue(this: params[ZOOMANIMATESEQ2.m_Index], a2: 0);
    params[ADDOVERBLEND.m_Index]->SetIntValue(this: params[ADDOVERBLEND.m_Index], a2: 0);
    params[ADDSELF.m_Index]->SetIntValue(this: params[ADDSELF.m_Index], a2: 0);
    params[BLENDFRAMES.m_Index]->SetIntValue(this: params[BLENDFRAMES.m_Index], a2: 0);
    params[DEPTHBLEND_1.m_Index]->SetIntValue(this: params[DEPTHBLEND_1.m_Index], a2: 0);
    params[INVERSEDEPTHBLEND.m_Index]->SetIntValue(this: params[INVERSEDEPTHBLEND.m_Index], a2: 0);
  }
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x10000);
}

//------------------------------------------------------------------------------
// Address: 0x10034130
// Name: public: virtual int Spritecard::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Spritecard::CShader::GetParamCount(Spritecard::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_115.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10034160
// Name: public: virtual void Spritecard::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Spritecard::CShader::OnDrawElements(
        Spritecard::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IMaterialVar **v6; // edi
  bool v7; // al
  float x; // xmm1_4
  float v9; // xmm2_4
  int m_intVal; // edx
  IMaterialVar *v11; // ecx
  float v12; // xmm2_4
  float y; // xmm2_4
  bool v14; // dl
  bool v15; // bl
  bool v16; // zf
  bool v17; // cl
  IMaterialVar *v18; // ecx
  bool v19; // bl
  float v20; // xmm0_4
  IShaderShadow *v21; // esi
  int v22; // eax
  int *v23; // ecx
  bool v24; // bl
  bool v25; // al
  BOOL v26; // esi
  BOOL v27; // eax
  bool v28; // al
  BOOL v29; // eax
  bool v30; // al
  BOOL v31; // edi
  BOOL v32; // eax
  int (__thiscall *GetDXSupportLevel)(IMaterialSystemHardwareConfig *); // edx
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  int v41; // eax
  IShaderShadow *v42; // esi
  IShaderShadow_vtbl *v43; // ebx
  int v44; // eax
  int v45; // eax
  int m_Index; // ecx
  int v47; // eax
  int v48; // eax
  int v49; // eax
  IShaderShadow_vtbl *v50; // ebx
  IShaderDynamicAPI *v51; // esi
  CBaseVSShader *v52; // ebx
  int v53; // eax
  IMaterialVar *v54; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v56; // xmm0_4
  float v57; // xmm0_4
  float v58; // xmm1_4
  double v59; // xmm1_8
  IMaterialVar *v60; // ecx
  IMaterialVar *v61; // eax
  IMaterialVar *v62; // edx
  int v63; // xmm1_4
  IMaterialVar *v64; // ecx
  int x_low; // xmm3_4
  IMaterialVar *v66; // eax
  void (__thiscall *v67)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v68; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v70; // eax
  void (__thiscall *v71)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v72; // eax
  float z; // xmm0_4
  float *v74; // eax
  IMaterialVar *v75; // eax
  IMaterialVar *v76; // edx
  float v77; // xmm0_4
  IShaderDynamicAPI_vtbl *v78; // eax
  float v79; // xmm0_4
  void (__thiscall *SetBooleanVertexShaderConstant)(IShaderDynamicAPI *, int, const int *, int, bool); // edx
  IMaterialVar *v81; // eax
  IMaterialVar *v82; // edx
  IMaterialVar *v83; // ecx
  IMaterialVar *v84; // eax
  IMaterialVar *v85; // edx
  IMaterialVar *v86; // ecx
  IMaterialVar *v87; // eax
  IMaterialVar *v88; // edx
  float v89; // xmm0_4
  IShaderDynamicAPI_vtbl *v90; // eax
  float v91; // xmm0_4
  void (__thiscall *v92)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  ShaderBlendFactor_t v93; // [esp+E8h] [ebp-F4h]
  ShaderBlendFactor_t flSrgbGammaValue; // [esp+ECh] [ebp-F0h]
  ShaderBlendFactor_t flSrgbGammaValuea; // [esp+ECh] [ebp-F0h]
  int flSrgbGammaValueb; // [esp+ECh] [ebp-F0h]
  int flSrgbGammaValuec; // [esp+ECh] [ebp-F0h]
  float C0[4]; // [esp+FCh] [ebp-E0h] BYREF
  float vViewportMad[4]; // [esp+10Ch] [ebp-D0h] BYREF
  float vPsConst1[4]; // [esp+11Ch] [ebp-C0h] BYREF
  int nViewportY; // [esp+12Ch] [ebp-B0h] BYREF
  int nViewportHeight; // [esp+130h] [ebp-ACh] BYREF
  float flIntensity; // [esp+134h] [ebp-A8h]
  int nViewportX; // [esp+138h] [ebp-A4h] BYREF
  int nBoolShaderConstant; // [esp+13Ch] [ebp-A0h] BYREF
  _DWORD v106[4]; // [esp+140h] [ebp-9Ch] BYREF
  float pVec; // [esp+150h] [ebp-8Ch] BYREF
  float v108; // [esp+154h] [ebp-88h]
  float v109; // [esp+158h] [ebp-84h]
  int v110; // [esp+15Ch] [ebp-80h]
  float vCropFactors[4]; // [esp+160h] [ebp-7Ch] BYREF
  spritecard_ps20b_Static_Index v112; // [esp+170h] [ebp-6Ch] BYREF
  int nSplineType; // [esp+1BCh] [ebp-20h]
  bool bShadowDepth; // [esp+1C3h] [ebp-19h]
  int nRtHeight; // [esp+1C4h] [ebp-18h] BYREF
  bool bInverseDepthBlend; // [esp+1CBh] [ebp-11h]
  bool bCrop; // [esp+1CCh] [ebp-10h]
  bool bSoftEdges; // [esp+1CDh] [ebp-Fh]
  bool bZoomSeq2; // [esp+1CEh] [ebp-Eh]
  bool bDistanceAlpha; // [esp+1CFh] [ebp-Dh]
  bool bOutLine; // [esp+1D0h] [ebp-Ch]
  bool bMod2X; // [esp+1D1h] [ebp-Bh]
  bool bColorLerpPS; // [esp+1D2h] [ebp-Ah]
  bool bUseRampTexture; // [esp+1D3h] [ebp-9h]
  bool bSecondSequence; // [esp+1D4h] [ebp-8h]
  bool bPerParticleOutline; // [esp+1D5h] [ebp-7h]
  bool bPackedInterpolator; // [esp+1D6h] [ebp-6h]
  bool bAddSelf; // [esp+1D7h] [ebp-5h]
  bool bBlendFrames; // [esp+1D8h] [ebp-4h]
  bool bFog; // [esp+1D9h] [ebp-3h]
  bool bAdditive2ndTexture; // [esp+1DAh] [ebp-2h]
  bool bExtractGreenAlpha; // [esp+1DBh] [ebp-1h]

  v6 = params;
  nRtHeight = (int)this;
  v7 = params[RAMPTEXTURE.m_Index]->IsDefined(this: params[RAMPTEXTURE.m_Index]);
  x = v6[ZOOMANIMATESEQ2.m_Index]->m_VecVal.x;
  bUseRampTexture = v7;
  bZoomSeq2 = x > 1.0;
  v9 = v6[ADDBASETEXTURE2.m_Index]->m_VecVal.x;
  bInverseDepthBlend = v6[INVERSEDEPTHBLEND.m_Index]->m_intVal != 0;
  bAdditive2ndTexture = v9 != 0.0;
  m_intVal = v6[SPLINETYPE.m_Index]->m_intVal;
  v11 = v6[CROPFACTOR.m_Index];
  v12 = v11->m_VecVal.x;
  bExtractGreenAlpha = v6[EXTRACTGREENALPHA.m_Index]->m_intVal != 0;
  nSplineType = m_intVal;
  if ( v12 != 1.0 || (y = v11->m_VecVal.y, bCrop = false, y != 1.0) )
    bCrop = true;
  v14 = v6[DUALSEQUENCE.m_Index]->m_intVal != 0;
  v15 = v6[BLENDFRAMES.m_Index]->m_intVal != 0;
  v16 = v6[DISTANCEALPHA.m_Index]->m_intVal == 0;
  bSecondSequence = v14;
  v17 = !v16;
  bBlendFrames = v15;
  bDistanceAlpha = !v16;
  if ( v16 || (v16 = v6[OUTLINE.m_Index]->m_intVal == 0, bOutLine = true, v16) )
    bOutLine = false;
  if ( !v17 || (v16 = v6[OUTLINE.m_Index]->m_intVal == 0, bSoftEdges = true, v16) )
    bSoftEdges = false;
  if ( !v17 || v14 || (v16 = v6[PERPARTICLEOUTLINE.m_Index]->m_intVal == 0, bPerParticleOutline = true, v16) )
    bPerParticleOutline = false;
  flIntensity = v6[INTENSITY.m_Index]->m_VecVal.x;
  if ( nSplineType != 0 )
  {
    v15 = false;
    bBlendFrames = false;
  }
  bColorLerpPS = v6[VERTEXCOLORLERP.m_Index]->m_intVal != 0;
  if ( !bColorLerpPS
    || bExtractGreenAlpha
    || v14
    || v15
    || (v16 = v6[MAXLUMFRAMEBLEND1.m_Index]->m_intVal == 0, bPackedInterpolator = true, !v16) )
  {
    bPackedInterpolator = false;
  }
  bFog = v6[VERTEXFOGAMOUNT.m_Index]->m_VecVal.x != 0.0;
  if ( pShaderShadow != nullptr )
  {
    v18 = v6[SHADOWDEPTH_0.m_Index];
    v19 = v6[ADDOVERBLEND.m_Index]->m_intVal != 0;
    v20 = v6[ADDSELF.m_Index]->m_VecVal.x;
    bMod2X = v6[MOD2X_0.m_Index]->m_intVal != 0;
    bShadowDepth = v18->m_intVal != 0;
    bAddSelf = v20 != 0.0;
    v21 = pShaderShadow;
    if ( bFog )
      pShaderShadow->FogMode(this: pShaderShadow, a2: SHADER_FOGMODE_FOGCOLOR, a3: true);
    v21->EnableCulling(this: v21, a2: false);
    v21->EnableAlphaWrites(this: v21, a2: false);
    v21->EnableTexture(this: v21, a2: SHADER_SAMPLER0, a3: true);
    if ( bUseRampTexture )
    {
      v21->EnableTexture(this: v21, a2: SHADER_SAMPLER1, a3: true);
      v21->EnableSRGBRead(this: v21, a2: SHADER_SAMPLER1, a3: true);
    }
    if ( bAdditive2ndTexture || bAddSelf )
      v21->EnableAlphaTest(this: v21, a2: false);
    else
      v21->EnableAlphaTest(this: v21, a2: true);
    ((void (__thiscall *)(IShaderShadow *, int, _DWORD))v21->AlphaFunc)(a1: v21, a2: 4, a3: 0);
    if ( bMod2X )
    {
      flSrgbGammaValue = SHADER_BLEND_SRC_COLOR;
      v93 = SHADER_BLEND_DST_COLOR;
    }
    else
    {
      if ( !bAdditive2ndTexture && !v19 && !bAddSelf )
      {
        if ( ((*v6)->m_intVal & 0x80) != 0 )
          flSrgbGammaValuea = SHADER_BLEND_ONE;
        else
          flSrgbGammaValuea = SHADER_BLEND_ONE_MINUS_SRC_ALPHA;
        CBaseShader::EnableAlphaBlending(
          this: (CBaseShader *)nRtHeight,
          src: SHADER_BLEND_SRC_ALPHA,
          dst: flSrgbGammaValuea);
        goto LABEL_42;
      }
      flSrgbGammaValue = SHADER_BLEND_ONE_MINUS_SRC_ALPHA;
      v93 = SHADER_BLEND_ONE;
    }
    CBaseShader::EnableAlphaBlending(this: (CBaseShader *)nRtHeight, src: v93, dst: flSrgbGammaValue);
LABEL_42:
    v22 = 5;
    if ( nSplineType != 0 )
    {
      v22 = 6;
      if ( v6[ORIENTATION.m_Index]->m_intVal == 3 )
        v22 = 8;
      v23 = `Spritecard::CShader::OnDrawElements'::`40'::s_TexCoordSizeSpline;
    }
    else
    {
      if ( bPerParticleOutline || v6[ORIENTATION.m_Index]->m_intVal == 3 )
      {
        v22 = 6;
      }
      else if ( bSecondSequence )
      {
        v22 = 8;
      }
      v23 = `Spritecard::CShader::OnDrawElements'::`40'::s_TexCoordSize;
    }
    v21->VertexShaderVertexFormat(this: v21, a2: 5u, a3: v22, a4: v23, a5: 0);
    if ( nSplineType != 0 )
    {
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   VS stat var %s = %d (%s)", "ADDBASETEXTURE2", 0, "0");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   VS stat var %s = %d (%s)", "EXTRACTGREENALPHA", 0, "0");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   VS stat var %s = %d (%s)", "DUALSEQUENCE", 0, "0");
            if ( g_shaderConfigDumpEnable )
            {
              printf(format: "\n   VS stat var %s = %d (%s)", "DEPTHBLEND", 0, "0");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   VS stat var %s = %d (%s)", "PACKED_INTERPOLATOR", 0, "0");
            }
          }
        }
      }
      v24 = bBlendFrames;
      v25 = bBlendFrames || v6[MAXLUMFRAMEBLEND1.m_Index]->m_intVal != 0;
      v26 = v25;
      if ( g_shaderConfigDumpEnable )
      {
        v27 = bBlendFrames || v6[MAXLUMFRAMEBLEND1.m_Index]->m_intVal != 0;
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "ANIMBLEND_OR_MAXLUMFRAMEBLEND1",
          v27,
          "bBlendFrames || ( params[MAXLUMFRAMEBLEND1]->GetIntValue() != 0 )");
      }
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "splinecard_vs20", a3: 4 * v26);
    }
    else
    {
      v112.m_nSOFTEDGES = bFog;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SPRITECARDVERTEXFOG", bFog, "bFog");
      v112.m_nMOD2X = bSecondSequence;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "DUALSEQUENCE", bSecondSequence, "bSecondSequence");
      v112.m_nADDSELF = bZoomSeq2;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "ZOOM_ANIMATE_SEQ2", bZoomSeq2, "bZoomSeq2");
      v112.m_nDEPTHBLEND = bAdditive2ndTexture;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "ADDBASETEXTURE2", bAdditive2ndTexture, "bAdditive2ndTexture");
      v112.m_nINVERSEDEPTHBLEND = bExtractGreenAlpha;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   VS stat var %s = %d (%s)", "EXTRACTGREENALPHA", bExtractGreenAlpha, "bExtractGreenAlpha");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "DEPTHBLEND", 0, "bDepthBlend");
      }
      v28 = bBlendFrames || v6[MAXLUMFRAMEBLEND1.m_Index]->m_intVal != 0;
      v112.m_nCOLOR_LERP_PS = v28;
      if ( g_shaderConfigDumpEnable )
      {
        v29 = bBlendFrames || v6[MAXLUMFRAMEBLEND1.m_Index]->m_intVal != 0;
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "ANIMBLEND_OR_MAXLUMFRAMEBLEND1",
          v29,
          "bBlendFrames || ( params[MAXLUMFRAMEBLEND1]->GetIntValue() != 0 )");
      }
      v112.m_nPACKED_INTERPOLATOR = bCrop;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "CROP", bCrop, "bCrop");
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "PACKED_INTERPOLATOR",
          bPackedInterpolator,
          "bPackedInterpolator");
      v30 = bFog && g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) <= 90;
      v31 = v30;
      if ( g_shaderConfigDumpEnable )
      {
        v32 = bFog && g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) <= 90;
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "HARDWAREFOGBLEND",
          v32,
          "!IsX360() && bFog && ( g_pHardwareConfig->GetDXSupportLevel() <= 90 )");
      }
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "PERPARTICLEOUTLINE",
          bPerParticleOutline,
          "bPerParticleOutline");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "spritecard_vs20",
        a3: 4
      * (v112.m_nADDSELF
       + 2
       * (v112.m_nMOD2X
        + 2
        * (v112.m_nDEPTHBLEND
         + 2
         * (v112.m_nINVERSEDEPTHBLEND
          + 2
          * (v112.m_nCOLOR_LERP_PS
           + 2
           * (v112.m_nPACKED_INTERPOLATOR
            + 2 * (bPackedInterpolator + 2 * (v112.m_nSOFTEDGES + 2 * (v31 + 2 * bPerParticleOutline))))))))));
      v6 = params;
      v24 = bBlendFrames;
    }
    GetDXSupportLevel = g_pHardwareConfig->GetDXSupportLevel;
    HIBYTE(params) = v6[MULOUTPUTBYALPHA.m_Index]->m_intVal != 0;
    v34 = GetDXSupportLevel(this: g_pHardwareConfig);
    v35 = 0;
    if ( v34 < 92 )
    {
      LOBYTE(v35) = bAdditive2ndTexture;
      v112.m_nADDBASETEXTURE2 = v35;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "ADDBASETEXTURE2", bAdditive2ndTexture, "bAdditive2ndTexture");
      v112.m_nDUALSEQUENCE = bSecondSequence;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DUALSEQUENCE", bSecondSequence, "bSecondSequence");
      v112.m_nADDSELF = bAddSelf;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "ADDSELF", bAddSelf, "bAddSelf");
      v112.m_nANIMBLEND = bBlendFrames;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "ANIMBLEND", bBlendFrames, "bBlendFrames");
      if ( bSecondSequence )
        v44 = v6[SEQUENCE_BLEND_MODE.m_Index]->m_intVal;
      else
        v44 = 0;
      v112.m_nSEQUENCE_BLEND_MODE = v44;
      if ( g_shaderConfigDumpEnable )
      {
        if ( bSecondSequence )
          v45 = v6[SEQUENCE_BLEND_MODE.m_Index]->m_intVal;
        else
          v45 = 0;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "SEQUENCE_BLEND_MODE",
          v45,
          "bSecondSequence ? params[SEQUENCE_BLEND_MODE]->GetIntValue() : 0");
      }
      m_Index = MAXLUMFRAMEBLEND1.m_Index;
      v47 = v6[MAXLUMFRAMEBLEND1.m_Index]->m_intVal;
      v112.m_nMAXLUMFRAMEBLEND1 = v47;
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "MAXLUMFRAMEBLEND1",
          v47,
          "params[MAXLUMFRAMEBLEND1]->GetIntValue()");
        m_Index = MAXLUMFRAMEBLEND1.m_Index;
      }
      if ( bSecondSequence )
        v48 = v6[m_Index]->m_intVal;
      else
        v48 = 0;
      v112.m_nMAXLUMFRAMEBLEND2 = v48;
      if ( g_shaderConfigDumpEnable )
      {
        if ( bSecondSequence )
          v49 = v6[m_Index]->m_intVal;
        else
          v49 = 0;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "MAXLUMFRAMEBLEND2",
          v49,
          "bSecondSequence? params[MAXLUMFRAMEBLEND1]->GetIntValue() : 0");
      }
      v112.m_nCOLORRAMP = bUseRampTexture;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "COLORRAMP", bUseRampTexture, "bUseRampTexture");
      v112.m_nEXTRACTGREENALPHA = bExtractGreenAlpha;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "EXTRACTGREENALPHA", bExtractGreenAlpha, "bExtractGreenAlpha");
      v112.m_nINVERSEDEPTHBLEND = bInverseDepthBlend;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "INVERSEDEPTHBLEND", bInverseDepthBlend, "bInverseDepthBlend");
      v112.m_nSHADER_SRGB_READ = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
      v112.m_nMOD2X = bMod2X;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "MOD2X", bMod2X, "bMod2X");
      v112.m_nDEPTHBLEND = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DEPTHBLEND", 0, "bDepthBlend");
      v112.m_nPACKED_INTERPOLATOR = bPackedInterpolator;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "PACKED_INTERPOLATOR",
          bPackedInterpolator,
          "bPackedInterpolator");
      v112.m_nCOLOR_LERP_PS = bColorLerpPS;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "COLOR_LERP_PS", bColorLerpPS, "bColorLerpPS");
      v112.m_nDISTANCEALPHA = bDistanceAlpha;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DISTANCEALPHA", bDistanceAlpha, "bDistanceAlpha");
      v112.m_nOUTLINE = bOutLine;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "OUTLINE", bOutLine, "bOutLine");
      v112.m_nSOFTEDGES = bSoftEdges;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SOFTEDGES", bSoftEdges, "bSoftEdges");
      v112.m_nMULOUTPUTBYALPHA = HIBYTE(params) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "MULOUTPUTBYALPHA", HIBYTE(params), "bMulOutputByAlpha");
      v42 = pShaderShadow;
      v50 = pShaderShadow->__vftable;
      flSrgbGammaValuec = spritecard_ps20b_Static_Index::GetIndex(this: &v112);
      v50->SetPixelShader(this: v42, a2: "spritecard_ps20", a3: flSrgbGammaValuec);
    }
    else
    {
      LOBYTE(v35) = bAdditive2ndTexture;
      v112.m_nADDBASETEXTURE2 = v35;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "ADDBASETEXTURE2", bAdditive2ndTexture, "bAdditive2ndTexture");
      v112.m_nADDSELF = bAddSelf;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "ADDSELF", bAddSelf, "bAddSelf");
      v112.m_nANIMBLEND = v24;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "ANIMBLEND", v24, "bBlendFrames");
      v112.m_nDUALSEQUENCE = bSecondSequence;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DUALSEQUENCE", bSecondSequence, "bSecondSequence");
      if ( bSecondSequence )
        v36 = v6[SEQUENCE_BLEND_MODE.m_Index]->m_intVal;
      else
        v36 = 0;
      v112.m_nSEQUENCE_BLEND_MODE = v36;
      if ( g_shaderConfigDumpEnable )
      {
        if ( bSecondSequence )
          v37 = v6[SEQUENCE_BLEND_MODE.m_Index]->m_intVal;
        else
          v37 = 0;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "SEQUENCE_BLEND_MODE",
          v37,
          "bSecondSequence ? params[SEQUENCE_BLEND_MODE]->GetIntValue() : 0");
      }
      v38 = MAXLUMFRAMEBLEND1.m_Index;
      v39 = v6[MAXLUMFRAMEBLEND1.m_Index]->m_intVal;
      v112.m_nMAXLUMFRAMEBLEND1 = v39;
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "MAXLUMFRAMEBLEND1",
          v39,
          "params[MAXLUMFRAMEBLEND1]->GetIntValue()");
        v38 = MAXLUMFRAMEBLEND1.m_Index;
      }
      if ( bSecondSequence )
        v40 = v6[v38]->m_intVal;
      else
        v40 = 0;
      v112.m_nMAXLUMFRAMEBLEND2 = v40;
      if ( g_shaderConfigDumpEnable )
      {
        if ( bSecondSequence )
          v41 = v6[v38]->m_intVal;
        else
          v41 = 0;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "MAXLUMFRAMEBLEND2",
          v41,
          "bSecondSequence? params[MAXLUMFRAMEBLEND1]->GetIntValue() : 0");
      }
      v112.m_nCOLORRAMP = bUseRampTexture;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "COLORRAMP", bUseRampTexture, "bUseRampTexture");
      v112.m_nEXTRACTGREENALPHA = bExtractGreenAlpha;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "EXTRACTGREENALPHA", bExtractGreenAlpha, "bExtractGreenAlpha");
      v112.m_nDEPTHBLEND = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DEPTHBLEND", 0, "bDepthBlend");
      v112.m_nINVERSEDEPTHBLEND = bInverseDepthBlend;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "INVERSEDEPTHBLEND", bInverseDepthBlend, "bInverseDepthBlend");
      v112.m_nSHADER_SRGB_READ = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
      v112.m_nMOD2X = bMod2X;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "MOD2X", bMod2X, "bMod2X");
      v112.m_nPACKED_INTERPOLATOR = bPackedInterpolator;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "PACKED_INTERPOLATOR",
          bPackedInterpolator,
          "bPackedInterpolator");
      v112.m_nCOLOR_LERP_PS = bColorLerpPS;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "COLOR_LERP_PS", bColorLerpPS, "bColorLerpPS");
      v112.m_nDISTANCEALPHA = bDistanceAlpha;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DISTANCEALPHA", bDistanceAlpha, "bDistanceAlpha");
      v112.m_nOUTLINE = bOutLine;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "OUTLINE", bOutLine, "bOutLine");
      v112.m_nSOFTEDGES = bSoftEdges;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SOFTEDGES", bSoftEdges, "bSoftEdges");
      v112.m_nMULOUTPUTBYALPHA = HIBYTE(params) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "MULOUTPUTBYALPHA", HIBYTE(params), "bMulOutputByAlpha");
      v42 = pShaderShadow;
      v43 = pShaderShadow->__vftable;
      flSrgbGammaValueb = spritecard_ps20b_Static_Index::GetIndex(this: &v112);
      v43->SetPixelShader(this: v42, a2: "spritecard_ps20b", a3: flSrgbGammaValueb);
    }
    if ( bShadowDepth )
    {
      v42->EnableColorWrites(this: v42, a2: false);
      v42->EnableAlphaWrites(this: v42, a2: false);
      v42->EnablePolyOffset(this: v42, a2: SHADER_POLYOFFSET_SHADOW_BIAS);
    }
    v42->EnableSRGBWrite(this: v42, a2: true);
    if ( !bExtractGreenAlpha )
      v42->EnableSRGBRead(this: v42, a2: SHADER_SAMPLER0, a3: true);
  }
  v51 = pShaderAPI;
  v52 = (CBaseVSShader *)nRtHeight;
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: (CBaseShader *)nRtHeight,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: !bExtractGreenAlpha ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: 7);
    if ( bUseRampTexture )
      CBaseShader::BindTexture(
        this: v52,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: RAMPTEXTURE.m_Index,
        nFrameVar: 7);
    v53 = v6[ORIENTATION.m_Index]->m_intVal;
    if ( v53 >= 0 )
    {
      if ( v53 > 3 )
        v53 = 3;
    }
    else
    {
      v53 = 0;
    }
    pShaderShadow = (IShaderShadow *)v53;
    if ( v53 != 0 )
    {
      if ( v53 == 2 )
        CBaseVSShader::SetVertexShaderMatrix3x4(this: v52, vertexReg: 48, matrixVar: ORIENTATIONMATRIX.m_Index);
    }
    else
    {
      CBaseVSShader::LoadModelViewMatrixIntoVertexShaderConstant(this: v52, vertexReg: 48);
      CBaseVSShader::LoadProjectionMatrixIntoVertexShaderConstant(this: v52, vertexReg: 51);
    }
    if ( bZoomSeq2 || bFog )
    {
      v54 = v6[VERTEXFOGAMOUNT.m_Index];
      SetVertexShaderConstant = v51->SetVertexShaderConstant;
      v56 = 1.0 / v6[ZOOMANIMATESEQ2.m_Index]->m_VecVal.x;
      vCropFactors[1] = v56;
      vCropFactors[0] = (float)(v56 + 1.0) * 0.5;
      vCropFactors[2] = v54->m_VecVal.x;
      vCropFactors[3] = 0.0;
      SetVertexShaderConstant(this: v51, a2: 55, a3: vCropFactors, a4: 1, a5: false);
    }
    v57 = v6[MAXDISTANCE.m_Index]->m_VecVal.x;
    v58 = v57 - v6[FARFADEINTERVAL.m_Index]->m_VecVal.x;
    if ( v58 >= 1.0 )
      v59 = v58;
    else
      v59 = 1.0;
    v60 = v6[MAXSIZE.m_Index];
    v61 = v6[STARTFADESIZE.m_Index];
    v112.m_nINVERSEDEPTHBLEND = LODWORD(v6[MINSIZE.m_Index]->m_VecVal.x);
    v62 = v6[ENDFADESIZE.m_Index];
    *(float *)&v63 = v59;
    v112.m_nSHADER_SRGB_READ = LODWORD(v60->m_VecVal.x);
    v64 = v6[ALPHATRAILFADE.m_Index];
    v112.m_nCOLOR_LERP_PS = LODWORD(v61->m_VecVal.x);
    x_low = LODWORD(v62->m_VecVal.x);
    v66 = v6[RADIUSTRAILFADE.m_Index];
    v67 = v51->SetVertexShaderConstant;
    *(float *)&v68 = 1.0 / (float)(v57 - *(float *)&v63);
    v112.m_nPACKED_INTERPOLATOR = x_low;
    v112.m_nDISTANCEALPHA = v63;
    v112.m_nSOFTEDGES = v68;
    v112.m_nOUTLINE = LODWORD(v64->m_VecVal.x);
    v112.m_nMULOUTPUTBYALPHA = LODWORD(v66->m_VecVal.x);
    v67(this: v51, a2: 56, a3: (const float *)&v112.m_nINVERSEDEPTHBLEND, a4: 2, a5: false);
    ((void (__thiscall *)(IShaderDynamicAPI *, int, _DWORD))v51->SetDepthFeatheringPixelShaderConstant)(
      a1: v51,
      a2: 2,
      a3: LODWORD(v6[DEPTHBLENDSCALE_1.m_Index]->m_VecVal.x));
    v51->GetCurrentViewport(this: v51, a2: &nViewportX, a3: &nViewportY, a4: (int *)&pShaderAPI, a5: &nViewportHeight);
    v51->GetCurrentRenderTargetDimensions(this: v51, a2: (int *)&params, a3: &nRtHeight);
    vViewportMad[0] = (float)((float)(int)pShaderAPI / (float)(int)params) * 0.5;
    SetPixelShaderConstant = v51->SetPixelShaderConstant;
    vViewportMad[1] = (float)((float)nViewportHeight / (float)nRtHeight) * -0.5;
    vViewportMad[2] = (float)((float)nViewportX / (float)(int)params) + vViewportMad[0];
    vViewportMad[3] = (float)((float)nViewportY / (float)nRtHeight) - vViewportMad[1];
    SetPixelShaderConstant(this: v51, a2: 15, a3: vViewportMad, a4: 1, a5: false);
    if ( bCrop )
    {
      v70 = v6[CROPFACTOR.m_Index];
      v71 = v51->SetVertexShaderConstant;
      vCropFactors[0] = v70->m_VecVal.x;
      vCropFactors[1] = v70->m_VecVal.y;
      vCropFactors[2] = 0.5 - (float)(vCropFactors[0] * 0.5);
      vCropFactors[3] = 0.5 - (float)(vCropFactors[1] * 0.5);
      v71(this: v51, a2: 15, a3: vCropFactors, a4: 1, a5: false);
    }
    if ( bColorLerpPS )
    {
      v72 = v6[LERPCOLOR1.m_Index];
      pVec = v72->m_VecVal.x;
      v108 = v72->m_VecVal.y;
      z = v72->m_VecVal.z;
      v74 = (float *)v6[LERPCOLOR2.m_Index];
      v109 = z;
      vCropFactors[0] = v74[3];
      vCropFactors[1] = v74[4];
      vCropFactors[2] = v74[5];
      v110 = 1065353216;
      vCropFactors[3] = 1.0;
      CBaseVSShader::SetPixelShaderConstantGammaToLinear(this: v52, var: 5, &pVec, numConst: 2, bForce: false);
    }
    v75 = v6[OVERBRIGHTFACTOR.m_Index];
    v76 = v6[ADDSELF.m_Index];
    C0[0] = v6[ADDBASETEXTURE2.m_Index]->m_VecVal.x;
    v77 = v75->m_VecVal.x;
    v78 = v51->__vftable;
    C0[1] = v77;
    v79 = v76->m_VecVal.x;
    SetBooleanVertexShaderConstant = v78->SetBooleanVertexShaderConstant;
    C0[2] = v79;
    C0[3] = flIntensity;
    nBoolShaderConstant = 0;
    SetBooleanVertexShaderConstant(this: v51, a2: 4, a3: &nBoolShaderConstant, a4: 1, a5: false);
    v51->SetPixelShaderConstant(this: v51, a2: 0, a3: C0, a4: 1, a5: false);
    memset(vPsConst1, 0, sizeof(vPsConst1));
    if ( g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig) )
      vPsConst1[0] = 0.5;
    else
      vPsConst1[0] = SrgbGammaToLinear(flSrgbGammaValue: 0.5);
    v51->SetPixelShaderConstant(this: v51, a2: 1, a3: vPsConst1, a4: 1, a5: false);
    if ( bDistanceAlpha )
    {
      v81 = v6[OUTLINECOLOR.m_Index];
      v82 = v6[OUTLINEALPHA.m_Index];
      v106[0] = LODWORD(v81->m_VecVal.x);
      v106[1] = LODWORD(v81->m_VecVal.y);
      v83 = v6[OUTLINESTART0.m_Index];
      v106[2] = LODWORD(v81->m_VecVal.z);
      v84 = v6[OUTLINESTART1.m_Index];
      v106[3] = LODWORD(v82->m_VecVal.x);
      v85 = v6[OUTLINEEND0.m_Index];
      pVec = v83->m_VecVal.x;
      v86 = v6[OUTLINEEND1.m_Index];
      v108 = v84->m_VecVal.x;
      v87 = v6[EDGESOFTNESSSTART.m_Index];
      v109 = v85->m_VecVal.x;
      v88 = v6[EDGESOFTNESSEND.m_Index];
      v110 = LODWORD(v86->m_VecVal.x);
      v89 = v87->m_VecVal.x;
      v90 = v51->__vftable;
      vCropFactors[0] = v89;
      v91 = v88->m_VecVal.x;
      v92 = v90->SetPixelShaderConstant;
      vCropFactors[1] = v91;
      vCropFactors[2] = 0.0;
      vCropFactors[3] = 0.0;
      v92(this: v51, a2: 7, a3: (const float *)v106, a4: 3, a5: false);
    }
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "ORIENTATION", pShaderShadow, "nOrientation");
    v51->SetVertexShaderIndex(this: v51, a2: (int)pShaderShadow);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v51->SetPixelShaderIndex(this: v51, a2: 0);
  }
  CBaseShader::Draw(this: v52, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100356A0
// Name: public: virtual struct ShaderParamInfo_t const __near & Spritecard::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Spritecard::CShaderParam *__thiscall Spritecard::CShader::GetParamInfo(Spritecard::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_115.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Spritecard::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100356D0
// Name: public: Spritecard::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *__thiscall Spritecard::CShaderParam::CShaderParam(
        Spritecard::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Spritecard::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Spritecard::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_115.m_Size + 13;
  m_Size = s_ShaderParams_115.m_Size;
  v8 = s_ShaderParams_115.m_Size;
  if ( s_ShaderParams_115.m_Size + 1 > s_ShaderParams_115.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_115,
      num: s_ShaderParams_115.m_Size - s_ShaderParams_115.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_115.m_Size;
  }
  m_pMemory = s_ShaderParams_115.m_Memory.m_pMemory;
  s_ShaderParams_115.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_115.m_pElements = s_ShaderParams_115.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_115.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_115.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_115.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10067230
// Name: Spritecard::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Spritecard::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Spritecard::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10067240
// Name: Spritecard::_dynamic_initializer_for__DEPTHBLEND__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__DEPTHBLEND__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &DEPTHBLEND_1,
           pName: "$DEPTHBLEND",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "fade at intersection boundaries",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067260
// Name: Spritecard::_dynamic_initializer_for__SCENEDEPTH__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__SCENEDEPTH__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &SCENEDEPTH_0,
           pName: "$SCENEDEPTH",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067280
// Name: Spritecard::_dynamic_initializer_for__DEPTHBLENDSCALE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__DEPTHBLENDSCALE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &DEPTHBLENDSCALE_1,
           pName: "$DEPTHBLENDSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "50.0",
           pHelp: "Amplify or reduce DEPTHBLEND fading. Lower values make harder edges.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100672A0
// Name: Spritecard::_dynamic_initializer_for__INVERSEDEPTHBLEND__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__INVERSEDEPTHBLEND__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &INVERSEDEPTHBLEND,
           pName: "$INVERSEDEPTHBLEND",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "calculate 1-depthblendalpha so that sprites appear when they are near geometry",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100672C0
// Name: Spritecard::_dynamic_initializer_for__ORIENTATION__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__ORIENTATION__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &ORIENTATION,
           pName: "$ORIENTATION",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "0 = always face camera, 1 = rotate around z, 2= parallel to ground 3=use normal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100672E0
// Name: Spritecard::_dynamic_initializer_for__ADDBASETEXTURE2__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__ADDBASETEXTURE2__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &ADDBASETEXTURE2,
           pName: "$ADDBASETEXTURE2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "amount to blend second texture into frame by",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067300
// Name: Spritecard::_dynamic_initializer_for__OVERBRIGHTFACTOR__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__OVERBRIGHTFACTOR__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &OVERBRIGHTFACTOR,
           pName: "$OVERBRIGHTFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "overbright factor for texture. For HDR effects.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067320
// Name: Spritecard::_dynamic_initializer_for__DUALSEQUENCE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__DUALSEQUENCE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &DUALSEQUENCE,
           pName: "$DUALSEQUENCE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "blend two separate animated sequences.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067340
// Name: Spritecard::_dynamic_initializer_for__SEQUENCE_BLEND_MODE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__SEQUENCE_BLEND_MODE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &SEQUENCE_BLEND_MODE,
           pName: "$SEQUENCE_BLEND_MODE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "defines the blend mode between the images un dual sequence particles. 0 = avg, 1=alpha from first, rgb from 2"
           "nd, 2= first over second",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067360
// Name: Spritecard::_dynamic_initializer_for__MAXLUMFRAMEBLEND1__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__MAXLUMFRAMEBLEND1__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &MAXLUMFRAMEBLEND1,
           pName: "$MAXLUMFRAMEBLEND1",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "instead of blending between animation frames for the first sequence, select pixels based upon max luminance",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067380
// Name: Spritecard::_dynamic_initializer_for__MAXLUMFRAMEBLEND2__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__MAXLUMFRAMEBLEND2__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &MAXLUMFRAMEBLEND2,
           pName: "$MAXLUMFRAMEBLEND2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "instead of blending between animation frames for the 2nd sequence, select pixels based upon max luminance",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100673A0
// Name: Spritecard::_dynamic_initializer_for__RAMPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__RAMPTEXTURE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &RAMPTEXTURE,
           pName: "$RAMPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "if specified, then the red value of the image is used to index this ramp to produce the output color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100673C0
// Name: Spritecard::_dynamic_initializer_for__ZOOMANIMATESEQ2__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__ZOOMANIMATESEQ2__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &ZOOMANIMATESEQ2,
           pName: "$ZOOMANIMATESEQ2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "amount to gradually zoom between frames on the second sequence. 2.0 will double the size of a frame over its lifetime.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100673E0
// Name: Spritecard::_dynamic_initializer_for__EXTRACTGREENALPHA__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__EXTRACTGREENALPHA__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &EXTRACTGREENALPHA,
           pName: "$EXTRACTGREENALPHA",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "grayscale data sitting in green/alpha channels",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067400
// Name: Spritecard::_dynamic_initializer_for__ADDOVERBLEND__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__ADDOVERBLEND__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &ADDOVERBLEND,
           pName: "$ADDOVERBLEND",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "use ONE:INVSRCALPHA blending",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067420
// Name: Spritecard::_dynamic_initializer_for__ADDSELF__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__ADDSELF__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &ADDSELF,
           pName: "$ADDSELF",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "amount of base texture to additively blend in",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067440
// Name: Spritecard::_dynamic_initializer_for__BLENDFRAMES__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__BLENDFRAMES__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &BLENDFRAMES,
           pName: "$BLENDFRAMES",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "whether or not to smoothly blend between animated frames",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067460
// Name: Spritecard::_dynamic_initializer_for__MINSIZE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__MINSIZE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &MINSIZE,
           pName: "$MINSIZE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "minimum screen fractional size of particle",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067480
// Name: Spritecard::_dynamic_initializer_for__STARTFADESIZE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__STARTFADESIZE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &STARTFADESIZE,
           pName: "$STARTFADESIZE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "10.0",
           pHelp: "screen fractional size to start fading particle out",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100674A0
// Name: Spritecard::_dynamic_initializer_for__ENDFADESIZE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__ENDFADESIZE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &ENDFADESIZE,
           pName: "$ENDFADESIZE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "20.0",
           pHelp: "screen fractional size to finish fading particle out",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100674C0
// Name: Spritecard::_dynamic_initializer_for__MAXSIZE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__MAXSIZE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &MAXSIZE,
           pName: "$MAXSIZE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "20.0",
           pHelp: "maximum screen fractional size of particle",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100674E0
// Name: Spritecard::_dynamic_initializer_for__USEINSTANCING__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__USEINSTANCING__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &USEINSTANCING,
           pName: "$USEINSTANCING",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "whether to use GPU vertex instancing (submit 1 vert per particle quad)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067500
// Name: Spritecard::_dynamic_initializer_for__SPLINETYPE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__SPLINETYPE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &SPLINETYPE,
           pName: "$SPLINETYPE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "spline type 0 = none,  1=ctamull rom",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067520
// Name: Spritecard::_dynamic_initializer_for__MAXDISTANCE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__MAXDISTANCE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &MAXDISTANCE,
           pName: "$MAXDISTANCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "100000.0",
           pHelp: "maximum distance to draw particles at",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067540
// Name: Spritecard::_dynamic_initializer_for__FARFADEINTERVAL__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__FARFADEINTERVAL__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &FARFADEINTERVAL,
           pName: "$FARFADEINTERVAL",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "400.0",
           pHelp: "interval over which to fade out far away particles",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067560
// Name: Spritecard::_dynamic_initializer_for__SHADERSRGBREAD360__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__SHADERSRGBREAD360__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &SHADERSRGBREAD360_1,
           pName: "$SHADERSRGBREAD360",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Simulate srgb read in shader code",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067580
// Name: Spritecard::_dynamic_initializer_for__ORIENTATIONMATRIX__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__ORIENTATIONMATRIX__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &ORIENTATIONMATRIX,
           pName: "$ORIENTATIONMATRIX",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "Matrix used to orient in orientation mode #2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100675A0
// Name: Spritecard::_dynamic_initializer_for__MOD2X__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__MOD2X__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &MOD2X_0,
           pName: "$MOD2X",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "whether or not to multiply the result of the pixel shader * 2 against the framebuffer",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100675C0
// Name: Spritecard::_dynamic_initializer_for__ALPHATRAILFADE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__ALPHATRAILFADE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &ALPHATRAILFADE,
           pName: "$ALPHATRAILFADE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Amount to scale alpha by between start and end of trail/rope",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100675E0
// Name: Spritecard::_dynamic_initializer_for__RADIUSTRAILFADE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__RADIUSTRAILFADE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &RADIUSTRAILFADE,
           pName: "$RADIUSTRAILFADE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Amount to scale radis by between start and end of trail/rope",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067600
// Name: Spritecard::_dynamic_initializer_for__SHADOWDEPTH__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__SHADOWDEPTH__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &SHADOWDEPTH_0,
           pName: "$SHADOWDEPTH",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "writing to a shadow depth buffer",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067620
// Name: Spritecard::_dynamic_initializer_for__OPAQUE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__OPAQUE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &OPAQUE,
           pName: "$OPAQUE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Are we opaque? (defaults to 0)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067640
// Name: Spritecard::_dynamic_initializer_for__CROPFACTOR__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__CROPFACTOR__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &CROPFACTOR,
           pName: "$CROPFACTOR",
           type: SHADER_PARAM_TYPE_VEC2,
           pDefaultParam: "[1 1]",
           pHelp: "writing to a shadow depth buffer",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067660
// Name: Spritecard::_dynamic_initializer_for__VERTEXCOLORLERP__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__VERTEXCOLORLERP__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &VERTEXCOLORLERP,
           pName: "$VERTEXCOLORLERP",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable computing vertex color by interpolating two color based on vertex r color channel",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067680
// Name: Spritecard::_dynamic_initializer_for__LERPCOLOR1__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__LERPCOLOR1__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &LERPCOLOR1,
           pName: "$LERPCOLOR1",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[1 0 0]",
           pHelp: "Lerp color 1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100676A0
// Name: Spritecard::_dynamic_initializer_for__LERPCOLOR2__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__LERPCOLOR2__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &LERPCOLOR2,
           pName: "$LERPCOLOR2",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 1 0]",
           pHelp: "Lerp color 2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100676C0
// Name: Spritecard::_dynamic_initializer_for__VERTEXFOGAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__VERTEXFOGAMOUNT__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &VERTEXFOGAMOUNT,
           pName: "$VERTEXFOGAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Amount of vertex fog to apply",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100676E0
// Name: Spritecard::_dynamic_initializer_for__DISTANCEALPHA__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__DISTANCEALPHA__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &DISTANCEALPHA,
           pName: "$DISTANCEALPHA",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Use distance-coded alpha generated from hi-res texture by vtex.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067700
// Name: Spritecard::_dynamic_initializer_for__SOFTEDGES__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__SOFTEDGES__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &SOFTEDGES,
           pName: "$SOFTEDGES",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable soft edges to distance coded textures.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067720
// Name: Spritecard::_dynamic_initializer_for__EDGESOFTNESSSTART__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__EDGESOFTNESSSTART__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &EDGESOFTNESSSTART,
           pName: "$EDGESOFTNESSSTART",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.6",
           pHelp: "Start value for soft edges for distancealpha.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067740
// Name: Spritecard::_dynamic_initializer_for__EDGESOFTNESSEND__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__EDGESOFTNESSEND__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &EDGESOFTNESSEND,
           pName: "$EDGESOFTNESSEND",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.5",
           pHelp: "End value for soft edges for distancealpha.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067760
// Name: Spritecard::_dynamic_initializer_for__OUTLINE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__OUTLINE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &OUTLINE,
           pName: "$OUTLINE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable outline for distance coded textures.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067780
// Name: Spritecard::_dynamic_initializer_for__OUTLINECOLOR__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__OUTLINECOLOR__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &OUTLINECOLOR,
           pName: "$OUTLINECOLOR",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "color of outline for distance coded images.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100677A0
// Name: Spritecard::_dynamic_initializer_for__OUTLINEALPHA__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__OUTLINEALPHA__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &OUTLINEALPHA,
           pName: "$OUTLINEALPHA",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "alpha value for outline",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100677C0
// Name: Spritecard::_dynamic_initializer_for__OUTLINESTART0__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__OUTLINESTART0__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &OUTLINESTART0,
           pName: "$OUTLINESTART0",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "outer start value for outline",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100677E0
// Name: Spritecard::_dynamic_initializer_for__OUTLINESTART1__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__OUTLINESTART1__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &OUTLINESTART1,
           pName: "$OUTLINESTART1",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "inner start value for outline",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067800
// Name: Spritecard::_dynamic_initializer_for__OUTLINEEND0__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__OUTLINEEND0__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &OUTLINEEND0,
           pName: "$OUTLINEEND0",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "inner end value for outline",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067820
// Name: Spritecard::_dynamic_initializer_for__OUTLINEEND1__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__OUTLINEEND1__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &OUTLINEEND1,
           pName: "$OUTLINEEND1",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "outer end value for outline",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067840
// Name: Spritecard::_dynamic_initializer_for__PERPARTICLEOUTLINE__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__PERPARTICLEOUTLINE__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &PERPARTICLEOUTLINE,
           pName: "$PERPARTICLEOUTLINE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Allow per particle outline control",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067860
// Name: Spritecard::_dynamic_initializer_for__MULOUTPUTBYALPHA__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__MULOUTPUTBYALPHA__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &MULOUTPUTBYALPHA,
           pName: "$MULOUTPUTBYALPHA",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Multiply output RGB by output alpha to avoid precision problems",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067880
// Name: Spritecard::_dynamic_initializer_for__INTENSITY__
// Source: json
//------------------------------------------------------------------------------
Spritecard::CShaderParam *Spritecard::_dynamic_initializer_for__INTENSITY__()
{
  return Spritecard::CShaderParam::CShaderParam(
           this: &INTENSITY,
           pName: "$INTENSITY",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Multiply output RGB by intensity factor",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100678A0
// Name: Spritecard::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Spritecard::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_115);
  s_ShaderInstance_115.__vftable = (Spritecard::CShader_vtbl *)&Spritecard::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B7F0
// Name: Spritecard::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Spritecard::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_115);
}

//------------------------------------------------------------------------------
// Address: 0x100678C0
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100678E0
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_flashlight_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_flashlight_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_flashlight_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067900
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_bump_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_bump_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_bump_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067920
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067940
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067960
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_flashlight_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_flashlight_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_flashlight_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067980
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_flashlight_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_flashlight_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_flashlight_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100679A0
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_bump_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_bump_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_bump_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100679C0
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_bump_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_bump_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_bump_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100679E0
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067A00
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067A20
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_bump_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_bump_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_bump_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067A40
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_bump_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_bump_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_bump_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067A60
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_flashlight_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_flashlight_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_flashlight_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067A80
// Name: _dynamic_initializer_for__s_ConstructMe_teeth_flashlight_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_teeth_flashlight_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &teeth_flashlight_ps30_combos);
}
