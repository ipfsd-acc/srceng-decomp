// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/motion_blur_dx9.cpp
// Functions: 19
// ============================================================

#include "materialsystem\stdshaders\motion_blur_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1001EFA0
// Name: public: virtual char const __near * MotionBlur::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MotionBlur::CShader::GetFallbackShader(MotionBlur::CShader *this, IMaterialVar **params)
{
  return "MotionBlur_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x1001EFB0
// Name: public: virtual char const __near * MotionBlur::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MotionBlur::CShader::GetName(MotionBlur::CShader *this)
{
  return s_Name_64;
}

//------------------------------------------------------------------------------
// Address: 0x1001EFC0
// Name: public: virtual int MotionBlur::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MotionBlur::CShader::GetFlags(MotionBlur::CShader *this)
{
  return s_nFlags_85;
}

//------------------------------------------------------------------------------
// Address: 0x1001EFD0
// Name: public: virtual int MotionBlur::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MotionBlur::CShader::GetParamCount(MotionBlur::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_65.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001EFE0
// Name: public: virtual char const __near * MotionBlur_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MotionBlur_dx9::CShader::GetName(MotionBlur_dx9::CShader *this)
{
  return s_Name_65;
}

//------------------------------------------------------------------------------
// Address: 0x1001EFF0
// Name: public: virtual int MotionBlur_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MotionBlur_dx9::CShader::GetFlags(MotionBlur_dx9::CShader *this)
{
  return s_nFlags_25;
}

//------------------------------------------------------------------------------
// Address: 0x1001F030
// Name: public: virtual int MotionBlur_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MotionBlur_dx9::CShader::GetParamCount(MotionBlur_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_64.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001F040
// Name: public: virtual void MotionBlur_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge MotionBlur_dx9::CShader::OnDrawElements(
        MotionBlur_dx9::CShader *this@<ecx>,
        int a2@<ebx>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v8; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  int v10; // eax
  int v11; // eax
  float v12; // xmm1_4
  int v13; // ebx
  IMaterialVar *v14; // eax
  float v15; // xmm1_4
  int v16; // eax
  float v17; // xmm2_4
  float v18; // xmm0_4
  int v19; // ecx
  int v20; // edi
  int v21; // [esp+0h] [ebp-1Ch]
  float vConst[4]; // [esp+8h] [ebp-14h] BYREF
  CBaseShader *v23; // [esp+18h] [ebp-4h]

  v23 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: false);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: false);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "motion_blur_vs20", a3: 0);
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v21 = 0;
    if ( v8 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "motion_blur_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "motion_blur_ps20b");
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
  }
  if ( pShaderAPI != nullptr )
  {
    ((void (__thiscall *)(IShaderDynamicAPI *, _DWORD, int))pShaderAPI->SetVertexShaderIndex)(
      a1: pShaderAPI,
      a2: 0,
      a3: a2);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    v10 = ((int (__thiscall *)(IMaterialVar *, int))params[6]->GetTextureValue)(a1: params[6], a2: v21);
    v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 16))(a1: v10);
    memset(vConst, 0, sizeof(vConst));
    v12 = mat_motion_blur_percent_of_screen_max.m_pParent->m_Value.m_fValue * 0.0099999998;
    v13 = v11;
    v14 = params[MOTIONBLURVIEWPORTINTERNAL.m_Index];
    vConst[0] = v12;
    if ( v14->m_VecVal.x > 0.0 || v14->m_VecVal.y > 0.0 || v14->m_VecVal.z < 1.0 || v14->m_VecVal.w < 1.0 )
      vConst[0] = v12 * 0.25;
    ((void (__thiscall *)(IShaderDynamicAPI *, _DWORD, float *, int))pShaderAPI->SetPixelShaderConstant)(
      a1: pShaderAPI,
      a2: 0,
      a3: vConst,
      a4: 1);
    pShaderAPI->SetPixelShaderConstant(
      this: pShaderAPI,
      a2: 1,
      a3: (const float *)&params[MOTIONBLURINTERNAL.m_Index]->m_VecVal,
      a4: 1,
      a5: false);
    pShaderAPI->SetPixelShaderConstant(
      this: pShaderAPI,
      a2: 2,
      a3: (const float *)&params[MOTIONBLURVIEWPORTINTERNAL.m_Index]->m_VecVal,
      a4: 1,
      a5: false);
    v15 = (float)((float)(fabs(params[MOTIONBLURINTERNAL.m_Index]->m_VecVal.y)
                        + fabs(params[MOTIONBLURINTERNAL.m_Index]->m_VecVal.x))
                + fabs(params[MOTIONBLURINTERNAL.m_Index]->m_VecVal.z))
        + fabs(params[MOTIONBLURINTERNAL.m_Index]->m_VecVal.w);
    if ( v13 < 1080 )
      v16 = 4 * (v13 >= 720) + 6;
    else
      v16 = 14;
    v17 = 4.0;
    if ( (float)(mat_motion_blur_percent_of_screen_max.m_pParent->m_Value.m_fValue * 0.0099999998) < 4.0 )
      v17 = mat_motion_blur_percent_of_screen_max.m_pParent->m_Value.m_fValue * 0.0099999998;
    v18 = (float)(v15 * 2.0) / v17;
    if ( v18 >= 0.0 )
    {
      if ( v18 > 1.0 )
        v18 = 1.0;
    }
    else
    {
      v18 = 0.0;
    }
    v19 = (int)(float)((float)v16 * v18);
    if ( v19 < 1 )
      v19 = 1;
    if ( v15 == 0.0 )
    {
      v19 = 0;
    }
    else
    {
      v20 = 14;
      if ( v19 > 14 )
      {
LABEL_27:
        g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "D_NUM_BLUR_SAMPLES", v20, "nNumBlurSamples");
        pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v20);
        goto LABEL_30;
      }
    }
    v20 = v19;
    goto LABEL_27;
  }
LABEL_30:
  CBaseShader::Draw(this: v23, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1001F310
// Name: public: virtual struct ShaderParamInfo_t const __near & MotionBlur::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
MotionBlur::CShaderParam *__thiscall MotionBlur::CShader::GetParamInfo(MotionBlur::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_65.m_Memory.m_pMemory[param - ParamCount];
  else
    return (MotionBlur::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001F340
// Name: public: virtual struct ShaderParamInfo_t const __near & MotionBlur_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
MotionBlur_dx9::CShaderParam *__thiscall MotionBlur_dx9::CShader::GetParamInfo(
        MotionBlur_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_64.m_Memory.m_pMemory[param - ParamCount];
  else
    return (MotionBlur_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001F370
// Name: public: MotionBlur_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
MotionBlur_dx9::CShaderParam *__thiscall MotionBlur_dx9::CShaderParam::CShaderParam(
        MotionBlur_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  MotionBlur_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  MotionBlur_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_64.m_Size + 13;
  m_Size = s_ShaderParams_64.m_Size;
  v8 = s_ShaderParams_64.m_Size;
  if ( s_ShaderParams_64.m_Size + 1 > s_ShaderParams_64.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_64,
      num: s_ShaderParams_64.m_Size - s_ShaderParams_64.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_64.m_Size;
  }
  m_pMemory = s_ShaderParams_64.m_Memory.m_pMemory;
  s_ShaderParams_64.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_64.m_pElements = s_ShaderParams_64.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_64.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_64.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_64.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063680
// Name: MotionBlur::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int MotionBlur::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: MotionBlur::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063690
// Name: MotionBlur::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *MotionBlur::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_65);
  s_ShaderInstance_65.__vftable = (MotionBlur::CShader_vtbl *)&MotionBlur::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100636B0
// Name: MotionBlur_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int MotionBlur_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: MotionBlur_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100636C0
// Name: MotionBlur_dx9::_dynamic_initializer_for__MOTIONBLURINTERNAL__
// Source: json
//------------------------------------------------------------------------------
MotionBlur_dx9::CShaderParam *MotionBlur_dx9::_dynamic_initializer_for__MOTIONBLURINTERNAL__()
{
  return MotionBlur_dx9::CShaderParam::CShaderParam(
           this: &MOTIONBLURINTERNAL,
           pName: "$MOTIONBLURINTERNAL",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 0 0]",
           pHelp: "Internal motion blur value set by proxy",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100636E0
// Name: MotionBlur_dx9::_dynamic_initializer_for__MOTIONBLURVIEWPORTINTERNAL__
// Source: json
//------------------------------------------------------------------------------
MotionBlur_dx9::CShaderParam *MotionBlur_dx9::_dynamic_initializer_for__MOTIONBLURVIEWPORTINTERNAL__()
{
  return MotionBlur_dx9::CShaderParam::CShaderParam(
           this: &MOTIONBLURVIEWPORTINTERNAL,
           pName: "$MOTIONBLURVIEWPORTINTERNAL",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 0 0]",
           pHelp: "Internal motion blur value set by proxy",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063700
// Name: MotionBlur_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *MotionBlur_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_64);
  s_ShaderInstance_64.__vftable = (MotionBlur_dx9::CShader_vtbl *)&MotionBlur_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B410
// Name: MotionBlur::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MotionBlur::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_65);
}

//------------------------------------------------------------------------------
// Address: 0x1006B420
// Name: MotionBlur_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MotionBlur_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_64);
}
