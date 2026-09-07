// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/colorcorrection.cpp
// Functions: 20
// ============================================================

#include "materialsystem\stdshaders\colorcorrection.h"

//------------------------------------------------------------------------------
// Address: 0x10009EE0
// Name: public: virtual void ColorCorrection::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ColorCorrection::CShader::OnInitShaderParams(
        ColorCorrection::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( !params[WEIGHT_DEFAULT.m_Index]->IsDefined(this: params[WEIGHT_DEFAULT.m_Index]) )
    ((void (__stdcall *)(int))params[WEIGHT_DEFAULT.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[WEIGHT0.m_Index]->IsDefined(this: params[WEIGHT0.m_Index]) )
    ((void (__stdcall *)(int))params[WEIGHT0.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[WEIGHT1.m_Index]->IsDefined(this: params[WEIGHT1.m_Index]) )
    ((void (__stdcall *)(int))params[WEIGHT1.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[WEIGHT2.m_Index]->IsDefined(this: params[WEIGHT2.m_Index]) )
    ((void (__stdcall *)(int))params[WEIGHT2.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[WEIGHT3.m_Index]->IsDefined(this: params[WEIGHT3.m_Index]) )
    ((void (__stdcall *)(int))params[WEIGHT3.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[NUM_LOOKUPS.m_Index]->IsDefined(this: params[NUM_LOOKUPS.m_Index]) )
    params[NUM_LOOKUPS.m_Index]->SetIntValue(this: params[NUM_LOOKUPS.m_Index], a2: 0);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x8000);
}

//------------------------------------------------------------------------------
// Address: 0x1000A020
// Name: public: virtual char const __near * ColorCorrection::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ColorCorrection::CShader::GetName(ColorCorrection::CShader *this)
{
  return s_Name_16;
}

//------------------------------------------------------------------------------
// Address: 0x1000A030
// Name: public: virtual int ColorCorrection::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ColorCorrection::CShader::GetFlags(ColorCorrection::CShader *this)
{
  return s_nFlags_5;
}

//------------------------------------------------------------------------------
// Address: 0x1000A040
// Name: public: virtual void ColorCorrection::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ColorCorrection::CShader::OnDrawElements(
        ColorCorrection::CShader *this@<ecx>,
        int a2@<edi>,
        IMaterialVar **params,
        float pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  float v7; // esi
  ColorCorrection::CShader *v8; // ebx
  int v9; // eax
  void (__stdcall *v10)(const char *); // edx
  IShaderDynamicAPI *v11; // esi
  int v12; // ebx
  IMaterialVar *v13; // eax
  IMaterialVar *v14; // edx
  IMaterialVar *v15; // ecx
  float x; // xmm0_4
  IMaterialVar *v17; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int m_intVal; // edi
  int v20; // [esp+0h] [ebp-1Ch]
  float weights[4]; // [esp+8h] [ebp-14h] BYREF
  ColorCorrection::CShader *v22; // [esp+18h] [ebp-4h]

  v7 = pShaderShadow;
  v8 = this;
  v22 = this;
  if ( pShaderShadow != 0.0 )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD, int))(*(_DWORD *)LODWORD(pShaderShadow) + 84))(
      a1: LODWORD(pShaderShadow),
      a2: 0,
      a3: 1);
    (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v7) + 84))(a1: COERCE_FLOAT(LODWORD(v7)), a2: 1, a3: 1);
    (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v7) + 84))(a1: COERCE_FLOAT(LODWORD(v7)), a2: 2, a3: 1);
    (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v7) + 84))(a1: COERCE_FLOAT(LODWORD(v7)), a2: 3, a3: 1);
    (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v7) + 84))(a1: COERCE_FLOAT(LODWORD(v7)), a2: 4, a3: 1);
    (*(void (__thiscall **)(float, int, int, _DWORD, _DWORD))(*(_DWORD *)LODWORD(v7) + 64))(
      a1: COERCE_FLOAT(LODWORD(v7)),
      a2: 1,
      a3: 1,
      a4: 0,
      a5: 0);
    (*(void (__thiscall **)(float, _DWORD))(*(_DWORD *)LODWORD(v7) + 76))(a1: COERCE_FLOAT(LODWORD(v7)), a2: 0);
    (*(void (__thiscall **)(float, const char *, _DWORD))(*(_DWORD *)LODWORD(v7) + 68))(
      a1: COERCE_FLOAT(LODWORD(v7)),
      a2: "screenspaceeffect_vs20",
      a3: 0);
    v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v10 = *(void (__stdcall **)(const char *))(*(_DWORD *)LODWORD(v7) + 72);
    v20 = 0;
    if ( v9 < 92 )
      v10(a1: "colorcorrection_ps20");
    else
      v10(a1: "colorcorrection_ps20b");
  }
  v11 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    if ( params[USE_FB_TEXTURE.m_Index]->m_intVal != 0 )
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER0,
        a3: TEXTURE_BINDFLAGS_NONE,
        a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
    else
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: INPUT_TEXTURE.m_Index,
        nFrameVar: -1);
    if ( params[NUM_LOOKUPS.m_Index]->m_intVal > 0 )
    {
      v12 = 1;
      do
      {
        v11->BindStandardTexture(
          this: v11,
          a2: (Sampler_t)v12,
          a3: TEXTURE_BINDFLAGS_NONE,
          a4: (StandardTextureId_t)(v12 + 14));
        ++v12;
      }
      while ( v12 - 1 < params[NUM_LOOKUPS.m_Index]->m_intVal );
      v8 = v22;
    }
    v13 = params[WEIGHT0.m_Index];
    v14 = params[WEIGHT1.m_Index];
    pShaderShadow = params[WEIGHT_DEFAULT.m_Index]->m_VecVal.x;
    v15 = params[WEIGHT2.m_Index];
    weights[0] = v13->m_VecVal.x;
    x = v14->m_VecVal.x;
    v17 = params[WEIGHT3.m_Index];
    SetPixelShaderConstant = v11->SetPixelShaderConstant;
    weights[1] = x;
    weights[2] = v15->m_VecVal.x;
    weights[3] = v17->m_VecVal.x;
    ((void (__thiscall *)(IShaderDynamicAPI *, _DWORD, float *, int, _DWORD, int))SetPixelShaderConstant)(
      a1: v11,
      a2: 0,
      a3: &pShaderShadow,
      a4: 1,
      a5: 0,
      a6: a2);
    v11->SetPixelShaderConstant(this: v11, a2: 1, a3: weights, a4: 1, a5: false);
    v11->SetPixelShaderConstant(this: v11, a2: 2, a3: &weights[1], a4: 1, a5: false);
    v11->SetPixelShaderConstant(this: v11, a2: 3, a3: &weights[2], a4: 1, a5: false);
    v11->SetPixelShaderConstant(this: v11, a2: 4, a3: &weights[3], a4: 1, a5: false);
    if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
           a1: g_pHardwareConfig,
           a2: v20) < 92 )
    {
      m_intVal = params[NUM_LOOKUPS.m_Index]->m_intVal;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LOOKUPS", m_intVal, "params[ NUM_LOOKUPS ]->GetIntValue()");
    }
    else
    {
      m_intVal = params[NUM_LOOKUPS.m_Index]->m_intVal;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LOOKUPS", m_intVal, "params[ NUM_LOOKUPS ]->GetIntValue()");
    }
    v11->SetPixelShaderIndex(this: v11, a2: m_intVal);
    v11->SetVertexShaderIndex(this: v11, a2: 0);
  }
  CBaseShader::Draw(this: v8, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000A2D0
// Name: public: virtual int ColorCorrection::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ColorCorrection::CShader::GetParamCount(ColorCorrection::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_16.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000A2E0
// Name: public: virtual struct ShaderParamInfo_t const __near & ColorCorrection::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ColorCorrection::CShaderParam *__thiscall ColorCorrection::CShader::GetParamInfo(
        ColorCorrection::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_16.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ColorCorrection::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000A310
// Name: public: ColorCorrection::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ColorCorrection::CShaderParam *__thiscall ColorCorrection::CShaderParam::CShaderParam(
        ColorCorrection::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  ColorCorrection::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  ColorCorrection::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_16.m_Size + 13;
  m_Size = s_ShaderParams_16.m_Size;
  v8 = s_ShaderParams_16.m_Size;
  if ( s_ShaderParams_16.m_Size + 1 > s_ShaderParams_16.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_16,
      num: s_ShaderParams_16.m_Size - s_ShaderParams_16.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_16.m_Size;
  }
  m_pMemory = s_ShaderParams_16.m_Memory.m_pMemory;
  s_ShaderParams_16.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_16.m_pElements = s_ShaderParams_16.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_16.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_16.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_16.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005F570
// Name: ColorCorrection::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ColorCorrection::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ColorCorrection::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005F580
// Name: ColorCorrection::_dynamic_initializer_for__WEIGHT_DEFAULT__
// Source: json
//------------------------------------------------------------------------------
ColorCorrection::CShaderParam *ColorCorrection::_dynamic_initializer_for__WEIGHT_DEFAULT__()
{
  return ColorCorrection::CShaderParam::CShaderParam(
           this: &WEIGHT_DEFAULT,
           pName: "$WEIGHT_DEFAULT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Volume Texture Default Weight",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F5A0
// Name: ColorCorrection::_dynamic_initializer_for__WEIGHT0__
// Source: json
//------------------------------------------------------------------------------
ColorCorrection::CShaderParam *ColorCorrection::_dynamic_initializer_for__WEIGHT0__()
{
  return ColorCorrection::CShaderParam::CShaderParam(
           this: &WEIGHT0,
           pName: "$WEIGHT0",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Volume Texture Weight 0",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F5C0
// Name: ColorCorrection::_dynamic_initializer_for__WEIGHT1__
// Source: json
//------------------------------------------------------------------------------
ColorCorrection::CShaderParam *ColorCorrection::_dynamic_initializer_for__WEIGHT1__()
{
  return ColorCorrection::CShaderParam::CShaderParam(
           this: &WEIGHT1,
           pName: "$WEIGHT1",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Volume Texture Weight 1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F5E0
// Name: ColorCorrection::_dynamic_initializer_for__WEIGHT2__
// Source: json
//------------------------------------------------------------------------------
ColorCorrection::CShaderParam *ColorCorrection::_dynamic_initializer_for__WEIGHT2__()
{
  return ColorCorrection::CShaderParam::CShaderParam(
           this: &WEIGHT2,
           pName: "$WEIGHT2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Volume Texture Weight 2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F600
// Name: ColorCorrection::_dynamic_initializer_for__WEIGHT3__
// Source: json
//------------------------------------------------------------------------------
ColorCorrection::CShaderParam *ColorCorrection::_dynamic_initializer_for__WEIGHT3__()
{
  return ColorCorrection::CShaderParam::CShaderParam(
           this: &WEIGHT3,
           pName: "$WEIGHT3",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Volume Texture Weight 3",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F620
// Name: ColorCorrection::_dynamic_initializer_for__NUM_LOOKUPS__
// Source: json
//------------------------------------------------------------------------------
ColorCorrection::CShaderParam *ColorCorrection::_dynamic_initializer_for__NUM_LOOKUPS__()
{
  return ColorCorrection::CShaderParam::CShaderParam(
           this: &NUM_LOOKUPS,
           pName: "$NUM_LOOKUPS",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Number of lookup maps",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F640
// Name: ColorCorrection::_dynamic_initializer_for__USE_FB_TEXTURE__
// Source: json
//------------------------------------------------------------------------------
ColorCorrection::CShaderParam *ColorCorrection::_dynamic_initializer_for__USE_FB_TEXTURE__()
{
  return ColorCorrection::CShaderParam::CShaderParam(
           this: &USE_FB_TEXTURE,
           pName: "$USE_FB_TEXTURE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Use frame buffer texture as input",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F660
// Name: ColorCorrection::_dynamic_initializer_for__INPUT_TEXTURE__
// Source: json
//------------------------------------------------------------------------------
ColorCorrection::CShaderParam *ColorCorrection::_dynamic_initializer_for__INPUT_TEXTURE__()
{
  return ColorCorrection::CShaderParam::CShaderParam(
           this: &INPUT_TEXTURE,
           pName: "$INPUT_TEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "0",
           pHelp: "Input texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F680
// Name: ColorCorrection::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ColorCorrection::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_16);
  s_ShaderInstance_16.__vftable = (ColorCorrection::CShader_vtbl *)&ColorCorrection::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AF80
// Name: ColorCorrection::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ColorCorrection::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_16);
}

//------------------------------------------------------------------------------
// Address: 0x1005F6A0
// Name: _dynamic_initializer_for__s_ConstructMe_debugmorphaccumulator_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugmorphaccumulator_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugmorphaccumulator_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F6C0
// Name: _dynamic_initializer_for__s_ConstructMe_debugmorphaccumulator_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugmorphaccumulator_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugmorphaccumulator_vs30_combos);
}
