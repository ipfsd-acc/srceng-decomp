// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/depthwrite.cpp
// Functions: 31
// ============================================================

#include "materialsystem\stdshaders\depthwrite.h"

//------------------------------------------------------------------------------
// Address: 0x1000BDA0
// Name: public: virtual void DepthWrite::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DepthWrite::CShader::OnInitShaderParams(
        DepthWrite::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
}

//------------------------------------------------------------------------------
// Address: 0x1000BDC0
// Name: public: virtual char const __near * DepthWrite::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DepthWrite::CShader::GetName(DepthWrite::CShader *this)
{
  return s_Name_25;
}

//------------------------------------------------------------------------------
// Address: 0x1000BDD0
// Name: public: virtual int DepthWrite::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DepthWrite::CShader::GetFlags(DepthWrite::CShader *this)
{
  return s_nFlags_9;
}

//------------------------------------------------------------------------------
// Address: 0x1000BDE0
// Name: public: virtual void DepthWrite::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DepthWrite::CShader::OnInitShaderInstance(
        DepthWrite::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[DISPLACEMENTMAP.m_Index]->IsDefined(this: params[DISPLACEMENTMAP.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: DISPLACEMENTMAP.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE20
// Name: public: virtual int DepthWrite::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DepthWrite::CShader::GetParamCount(DepthWrite::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_25.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE30
// Name: public: virtual void DepthWrite::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DepthWrite::CShader::OnDrawElements(
        DepthWrite::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v6; // eax
  int m_intVal; // eax
  int v8; // ebx
  IMaterialVar *v9; // ecx
  unsigned int v10; // eax
  bool v11; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  bool v13; // zf
  IShaderDynamicAPI_vtbl *v14; // eax
  BOOL v15; // ebx
  int v16; // eax
  bool v17; // bl
  float x; // xmm0_4
  int v19; // edi
  bool v20; // bl
  void (__thiscall *v21)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v22; // ecx
  int (__thiscall *GetCurrentNumBones)(IShaderDynamicAPI *); // eax
  bool v24; // al
  BOOL v25; // ebx
  BOOL v26; // eax
  bool v27; // al
  BOOL v28; // edi
  BOOL v29; // eax
  float v30; // xmm0_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  void (__thiscall *v36)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  void (__thiscall *v41)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  void (__thiscall *v45)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v46; // xmm0_4
  float v47; // xmm0_4
  void (__thiscall *v48)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const char *v49; // [esp-4h] [ebp-38h]
  int v50; // [esp+0h] [ebp-34h]
  float flParams[4]; // [esp+Ch] [ebp-28h] BYREF
  Vector windDir; // [esp+1Ch] [ebp-18h] BYREF
  int v53; // [esp+28h] [ebp-Ch]
  CBaseShader *v54; // [esp+2Ch] [ebp-8h]
  bool bHasDisplacementWrinkles; // [esp+31h] [ebp-3h]
  bool bHasDisplacement; // [esp+32h] [ebp-2h]
  bool bAlphaClip; // [esp+33h] [ebp-1h]
  TessellationMode_t nTessellationMode; // [esp+40h] [ebp+Ch]

  v6 = (int)*params;
  v54 = this;
  bAlphaClip = BYTE1(*(_DWORD *)(v6 + 8)) & 1;
  if ( TREESWAY.m_Index == -1 )
  {
    m_intVal = 0;
LABEL_5:
    v8 = m_intVal;
    v53 = m_intVal;
    goto LABEL_6;
  }
  m_intVal = params[TREESWAY.m_Index]->m_intVal;
  if ( m_intVal < 0 )
  {
    v8 = 0;
    v53 = 0;
    goto LABEL_6;
  }
  if ( m_intVal <= 2 )
    goto LABEL_5;
  v8 = 2;
  v53 = 2;
LABEL_6:
  v9 = params[DISPLACEMENTWRINKLE.m_Index];
  bHasDisplacement = (*((_BYTE *)params[DISPLACEMENTMAP.m_Index] + 28) & 0xF) == 3;
  bHasDisplacementWrinkles = v9->m_intVal != 0;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1025u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnablePolyOffset(this: pShaderShadow, a2: SHADER_POLYOFFSET_SHADOW_BIAS);
    pShaderShadow->EnableColorWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
    v10 = (*params)->m_intVal;
    LOBYTE(v10) = (v10 & 0x100) != 0 && (v10 >>= 13, (v10 & 1) == 0);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: v10);
    if ( bHasDisplacement && g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
      pShaderShadow->EnableVertexTexture(this: pShaderShadow, a2: SHADER_VERTEXTEXTURE_SAMPLER2, a3: true);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x800000);
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   VS stat var %s = %d (%s)", "ONLY_PROJECT_POSITION", 0, "0");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "TREESWAY", v8, "nTreeSwayMode");
      }
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "depthwrite_vs30", a3: 8 * v8);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
      v50 = 0;
      ((void (__stdcall *)(const char *))pShaderShadow->SetPixelShader)(a1: "depthwrite_ps30");
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   VS stat var %s = %d (%s)", "ONLY_PROJECT_POSITION", 0, "!bAlphaClip && IsX360()");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "TREESWAY", v8, "nTreeSwayMode");
      }
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "depthwrite_vs20", a3: 4 * v8);
      if ( bAlphaClip )
      {
        pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
        pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
        v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
        SetPixelShader = pShaderShadow->SetPixelShader;
        v50 = 0;
        if ( v11 )
          ((void (__stdcall *)(const char *))SetPixelShader)(a1: "depthwrite_ps20");
        else
          ((void (__stdcall *)(const char *))SetPixelShader)(a1: "depthwrite_ps20b");
      }
    }
  }
  if ( pShaderAPI != nullptr )
  {
    v13 = ((unsigned __int8 (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->HasFastVertexTextures)(
            a1: g_pHardwareConfig,
            a2: v50) == 0;
    v14 = pShaderAPI->__vftable;
    if ( v13 )
    {
      v15 = v14->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v16 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v16 > 0, v49);
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "( int )vertexCompression");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", 0, "0");
        }
      }
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * v15);
      v17 = bAlphaClip;
      if ( bAlphaClip )
      {
        CBaseShader::BindTexture(
          this: v54,
          sampler1: SHADER_SAMPLER0,
          nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
          nTextureVar: 6,
          nFrameVar: 7);
        qmemcpy(flParams, "333?333?333?333?", sizeof(flParams));
        if ( ALPHATESTREFERENCE.m_Index != -1 )
        {
          x = params[ALPHATESTREFERENCE.m_Index]->m_VecVal.x;
          if ( x > 0.0 )
          {
            flParams[3] = params[ALPHATESTREFERENCE.m_Index]->m_VecVal.x;
            flParams[2] = x;
            flParams[1] = x;
            flParams[0] = x;
          }
        }
        pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: flParams, a4: 1, a5: false);
      }
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "ALPHACLIP", v17, "bAlphaClip");
LABEL_85:
        pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v17);
        if ( v53 != 0 )
        {
          flParams[0] = pShaderAPI->CurrentTime(this: pShaderAPI);
          pShaderAPI->GetVectorRenderingParameter(this: pShaderAPI, result: &windDir, a3: 3);
          SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
          flParams[1] = windDir.x;
          flParams[2] = windDir.y;
          flParams[3] = 0.0;
          SetVertexShaderConstant(this: pShaderAPI, a2: 50, a3: flParams, a4: 1, a5: false);
          if ( TREESWAYSCRUMBLEFALLOFFEXP.m_Index == -1 )
            v32 = 1.0;
          else
            v32 = params[TREESWAYSCRUMBLEFALLOFFEXP.m_Index]->m_VecVal.x;
          flParams[0] = v32;
          if ( TREESWAYFALLOFFEXP.m_Index == -1 )
            v33 = 1.0;
          else
            v33 = params[TREESWAYFALLOFFEXP.m_Index]->m_VecVal.x;
          flParams[1] = v33;
          if ( TREESWAYSCRUMBLESPEED.m_Index == -1 )
            v34 = 3.0;
          else
            v34 = params[TREESWAYSCRUMBLESPEED.m_Index]->m_VecVal.x;
          flParams[2] = v34;
          if ( TREESWAYSPEEDHIGHWINDMULTIPLIER.m_Index == -1 )
            v35 = 2.0;
          else
            v35 = params[TREESWAYSPEEDHIGHWINDMULTIPLIER.m_Index]->m_VecVal.x;
          v36 = pShaderAPI->SetVertexShaderConstant;
          flParams[3] = v35;
          v36(this: pShaderAPI, a2: 51, a3: flParams, a4: 1, a5: false);
          if ( TREESWAYHEIGHT.m_Index == -1 )
            v37 = 1000.0;
          else
            v37 = params[TREESWAYHEIGHT.m_Index]->m_VecVal.x;
          flParams[0] = v37;
          if ( TREESWAYSTARTHEIGHT.m_Index == -1 )
            v38 = 0.1;
          else
            v38 = params[TREESWAYSTARTHEIGHT.m_Index]->m_VecVal.x;
          flParams[1] = v38;
          if ( TREESWAYRADIUS.m_Index == -1 )
            v39 = 300.0;
          else
            v39 = params[TREESWAYRADIUS.m_Index]->m_VecVal.x;
          flParams[2] = v39;
          if ( TREESWAYSTARTRADIUS.m_Index == -1 )
            v40 = 0.2;
          else
            v40 = params[TREESWAYSTARTRADIUS.m_Index]->m_VecVal.x;
          v41 = pShaderAPI->SetVertexShaderConstant;
          flParams[3] = v40;
          v41(this: pShaderAPI, a2: 52, a3: flParams, a4: 1, a5: false);
          if ( TREESWAYSPEED.m_Index == -1 )
            v42 = 1.0;
          else
            v42 = params[TREESWAYSPEED.m_Index]->m_VecVal.x;
          flParams[0] = v42;
          v43 = 10.0;
          if ( TREESWAYSTRENGTH.m_Index == -1 )
            flParams[1] = 10.0;
          else
            flParams[1] = params[TREESWAYSTRENGTH.m_Index]->m_VecVal.x;
          if ( TREESWAYSCRUMBLEFREQUENCY.m_Index == -1 )
            v44 = 12.0;
          else
            v44 = params[TREESWAYSCRUMBLEFREQUENCY.m_Index]->m_VecVal.x;
          flParams[2] = v44;
          if ( TREESWAYSCRUMBLESTRENGTH.m_Index != -1 )
            v43 = params[TREESWAYSCRUMBLESTRENGTH.m_Index]->m_VecVal.x;
          v45 = pShaderAPI->SetVertexShaderConstant;
          flParams[3] = v43;
          v45(this: pShaderAPI, a2: 53, a3: flParams, a4: 1, a5: false);
          if ( TREESWAYSPEEDLERPSTART.m_Index == -1 )
            v46 = 3.0;
          else
            v46 = params[TREESWAYSPEEDLERPSTART.m_Index]->m_VecVal.x;
          flParams[0] = v46;
          if ( TREESWAYSPEEDLERPEND.m_Index == -1 )
            v47 = 6.0;
          else
            v47 = params[TREESWAYSPEEDLERPEND.m_Index]->m_VecVal.x;
          v48 = pShaderAPI->SetVertexShaderConstant;
          flParams[1] = v47;
          flParams[2] = 0.0;
          flParams[3] = 0.0;
          v48(this: pShaderAPI, a2: 57, a3: flParams, a4: 1, a5: false);
        }
        goto LABEL_128;
      }
    }
    else
    {
      v19 = v14->GetTessellationMode(this: pShaderAPI);
      nTessellationMode = v19;
      if ( v19 != 0 )
      {
        pShaderAPI->BindStandardVertexTexture(
          this: pShaderAPI,
          a2: SHADER_VERTEXTEXTURE_SAMPLER1,
          a3: TEXTURE_SUBDIVISION_PATCHES);
        v20 = bHasDisplacement;
        flParams[0] = 1.0 / ((double (__thiscall *)(IShaderDynamicAPI *))pShaderAPI->GetSubDHeight)(a1: pShaderAPI);
        if ( bHasDisplacement
          && mat_displacementmap.m_pParent != nullptr
          && mat_displacementmap.m_pParent->m_Value.m_nValue != 0 )
        {
          flParams[1] = 1.0;
        }
        else
        {
          flParams[1] = 0.0;
        }
        if ( bHasDisplacementWrinkles
          && mat_displacementmap.m_pParent != nullptr
          && mat_displacementmap.m_pParent->m_Value.m_nValue != 0 )
        {
          flParams[2] = 1.0;
        }
        else
        {
          flParams[2] = 0.0;
        }
        v21 = pShaderAPI->SetVertexShaderConstant;
        flParams[3] = 0.0;
        v21(this: pShaderAPI, a2: 56, a3: flParams, a4: 1, a5: false);
        if ( v20 )
          CBaseShader::BindVertexTexture(
            this: v54,
            vtSampler: SHADER_VERTEXTEXTURE_SAMPLER2,
            nTextureVar: DISPLACEMENTMAP.m_Index,
            nFrame: 0);
        else
          pShaderAPI->BindStandardVertexTexture(this: pShaderAPI, a2: SHADER_VERTEXTEXTURE_SAMPLER2, a3: TEXTURE_BLACK);
      }
      CBaseVSShader::SetHWMorphVertexShaderState(
        this: (CBaseVSShader *)v54,
        nDimConst: 54,
        nSubrectConst: 55,
        morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
      v22 = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
      GetCurrentNumBones = pShaderAPI->GetCurrentNumBones;
      LODWORD(flParams[2]) = v22;
      v24 = GetCurrentNumBones(this: pShaderAPI) > 0 && v19 == 0;
      v25 = v24;
      if ( g_shaderConfigDumpEnable )
      {
        v26 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0 && v19 == 0;
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "SKINNING",
          v26,
          "( pShaderAPI->GetCurrentNumBones() > 0 ) && ( nTessellationMode == TESSELLATION_MODE_DISABLED )");
      }
      v27 = vertexCompression != VERTEX_COMPRESSION_NONE && v19 == 0;
      v28 = v27;
      if ( g_shaderConfigDumpEnable )
      {
        v29 = vertexCompression != VERTEX_COMPRESSION_NONE && nTessellationMode == TESSELLATION_MODE_DISABLED;
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "COMPRESSED_VERTS",
          v29,
          "(int)vertexCompression && ( nTessellationMode == TESSELLATION_MODE_DISABLED )");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", nTessellationMode, "nTessellationMode");
      }
      pShaderAPI->SetVertexShaderIndex(
        this: pShaderAPI,
        a2: v28 + 2 * (v25 + 2 * (LODWORD(flParams[2]) + 2 * nTessellationMode)));
      v17 = bAlphaClip;
      if ( bAlphaClip )
      {
        CBaseShader::BindTexture(
          this: v54,
          sampler1: SHADER_SAMPLER0,
          nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
          nTextureVar: 6,
          nFrameVar: 7);
        qmemcpy(flParams, "333?333?333?333?", sizeof(flParams));
        if ( ALPHATESTREFERENCE.m_Index != -1 )
        {
          v30 = params[ALPHATESTREFERENCE.m_Index]->m_VecVal.x;
          if ( v30 > 0.0 )
          {
            flParams[3] = params[ALPHATESTREFERENCE.m_Index]->m_VecVal.x;
            flParams[2] = v30;
            flParams[1] = v30;
            flParams[0] = v30;
          }
        }
        pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: flParams, a4: 1, a5: false);
      }
    }
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "ALPHACLIP", v17, "bAlphaClip");
    goto LABEL_85;
  }
LABEL_128:
  CBaseShader::Draw(this: v54, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000C740
// Name: public: virtual struct ShaderParamInfo_t const __near & DepthWrite::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *__thiscall DepthWrite::CShader::GetParamInfo(DepthWrite::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_25.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DepthWrite::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000C770
// Name: public: DepthWrite::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *__thiscall DepthWrite::CShaderParam::CShaderParam(
        DepthWrite::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  DepthWrite::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  DepthWrite::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_25.m_Size + 13;
  m_Size = s_ShaderParams_25.m_Size;
  v8 = s_ShaderParams_25.m_Size;
  if ( s_ShaderParams_25.m_Size + 1 > s_ShaderParams_25.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_25,
      num: s_ShaderParams_25.m_Size - s_ShaderParams_25.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_25.m_Size;
  }
  m_pMemory = s_ShaderParams_25.m_Memory.m_pMemory;
  s_ShaderParams_25.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_25.m_pElements = s_ShaderParams_25.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_25.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_25.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_25.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005FD30
// Name: DepthWrite::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DepthWrite::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DepthWrite::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005FD40
// Name: DepthWrite::_dynamic_initializer_for__ALPHATESTREFERENCE__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__ALPHATESTREFERENCE__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &ALPHATESTREFERENCE,
           pName: "$ALPHATESTREFERENCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: "Alpha reference value",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FD60
// Name: DepthWrite::_dynamic_initializer_for__DISPLACEMENTMAP__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__DISPLACEMENTMAP__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &DISPLACEMENTMAP,
           pName: "$DISPLACEMENTMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Displacement map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FD80
// Name: DepthWrite::_dynamic_initializer_for__DISPLACEMENTWRINKLE__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__DISPLACEMENTWRINKLE__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &DISPLACEMENTWRINKLE,
           pName: "$DISPLACEMENTWRINKLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Displacement map contains wrinkle displacements",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FDA0
// Name: DepthWrite::_dynamic_initializer_for__TREESWAY__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAY__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAY,
           pName: "$TREESWAY",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FDC0
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYHEIGHT__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYHEIGHT__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYHEIGHT,
           pName: "$TREESWAYHEIGHT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1000",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FDE0
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSTARTHEIGHT__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSTARTHEIGHT__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSTARTHEIGHT,
           pName: "$TREESWAYSTARTHEIGHT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FE00
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYRADIUS__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYRADIUS__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYRADIUS,
           pName: "$TREESWAYRADIUS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "300",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FE20
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSTARTRADIUS__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSTARTRADIUS__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSTARTRADIUS,
           pName: "$TREESWAYSTARTRADIUS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FE40
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSPEED__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSPEED__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSPEED,
           pName: "$TREESWAYSPEED",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FE60
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSPEEDHIGHWINDMULTIPLIER__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSPEEDHIGHWINDMULTIPLIER__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSPEEDHIGHWINDMULTIPLIER,
           pName: "$TREESWAYSPEEDHIGHWINDMULTIPLIER",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FE80
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSTRENGTH__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSTRENGTH,
           pName: "$TREESWAYSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "10",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FEA0
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSCRUMBLESPEED__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSCRUMBLESPEED__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSCRUMBLESPEED,
           pName: "$TREESWAYSCRUMBLESPEED",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FEC0
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSCRUMBLESTRENGTH__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSCRUMBLESTRENGTH__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSCRUMBLESTRENGTH,
           pName: "$TREESWAYSCRUMBLESTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FEE0
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSCRUMBLEFREQUENCY__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSCRUMBLEFREQUENCY__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSCRUMBLEFREQUENCY,
           pName: "$TREESWAYSCRUMBLEFREQUENCY",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FF00
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYFALLOFFEXP__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYFALLOFFEXP__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYFALLOFFEXP,
           pName: "$TREESWAYFALLOFFEXP",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.5",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FF20
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSCRUMBLEFALLOFFEXP__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSCRUMBLEFALLOFFEXP__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSCRUMBLEFALLOFFEXP,
           pName: "$TREESWAYSCRUMBLEFALLOFFEXP",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FF40
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSPEEDLERPSTART__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSPEEDLERPSTART__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSPEEDLERPSTART,
           pName: "$TREESWAYSPEEDLERPSTART",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "3",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FF60
// Name: DepthWrite::_dynamic_initializer_for__TREESWAYSPEEDLERPEND__
// Source: json
//------------------------------------------------------------------------------
DepthWrite::CShaderParam *DepthWrite::_dynamic_initializer_for__TREESWAYSPEEDLERPEND__()
{
  return DepthWrite::CShaderParam::CShaderParam(
           this: &TREESWAYSPEEDLERPEND,
           pName: "$TREESWAYSPEEDLERPEND",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "6",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FF80
// Name: DepthWrite::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DepthWrite::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_25);
  s_ShaderInstance_25.__vftable = (DepthWrite::CShader_vtbl *)&DepthWrite::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B040
// Name: DepthWrite::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DepthWrite::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_25);
}

//------------------------------------------------------------------------------
// Address: 0x1005FFA0
// Name: _dynamic_initializer_for__s_ConstructMe_Downsample_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Downsample_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Downsample_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005FFC0
// Name: _dynamic_initializer_for__s_ConstructMe_Downsample_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Downsample_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Downsample_ps20b_combos);
}
