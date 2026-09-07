// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/debugluxel.cpp
// Functions: 19
// ============================================================

#include "materialsystem\stdshaders\debugluxel.h"

//------------------------------------------------------------------------------
// Address: 0x10001670
// Name: public: virtual void DebugLuxels::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DebugLuxels::CShader::OnInitShaderParams(
        DebugLuxels::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 2);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 4);
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 90 )
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
}

//------------------------------------------------------------------------------
// Address: 0x100016D0
// Name: public: virtual char const __near * DebugLuxels::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DebugLuxels::CShader::GetName(DebugLuxels::CShader *this)
{
  return s_Name_1;
}

//------------------------------------------------------------------------------
// Address: 0x100016E0
// Name: public: virtual int DebugLuxels::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugLuxels::CShader::GetFlags(DebugLuxels::CShader *this)
{
  return s_nFlags_1;
}

//------------------------------------------------------------------------------
// Address: 0x100016F0
// Name: public: virtual void DebugLuxels::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DebugLuxels::CShader::OnInitShaderInstance(
        DebugLuxels::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10001700
// Name: public: virtual void DebugLuxels::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DebugLuxels::CShader::OnDrawElements(
        DebugLuxels::CShader *this,
        IMaterialVar **params,
        int pShaderShadow,
        int pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v6; // esi
  int v8; // eax
  void (__stdcall *v9)(const char *); // edx
  IShaderDynamicAPI *v10; // esi
  IMaterialVar *v11; // edx
  int v12; // [esp+0h] [ebp-28h]
  Vector4D transformation[2]; // [esp+8h] [ebp-20h] BYREF

  v6 = pShaderShadow;
  if ( pShaderShadow != 0 )
  {
    (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)pShaderShadow + 84))(a1: pShaderShadow, a2: 0, a3: 1);
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 68))(a1: v6, a2: "debugluxel_vs20", a3: 0);
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v9 = *(void (__stdcall **)(const char *))(*(_DWORD *)v6 + 72);
    v12 = 0;
    if ( v8 < 92 )
      v9(a1: "debugluxel_ps20");
    else
      v9(a1: "debugluxel_ps20b");
    CBaseShader::SetDefaultBlendingShadowState(this, textureVar: 6, isBaseTexture: true);
    CBaseShader::DisableFog(this);
    (*(void (__thiscall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)v6 + 64))(a1: v6, a2: 1, a3: 2, a4: 0, a5: 0);
  }
  v10 = (IShaderDynamicAPI *)pShaderAPI;
  if ( pShaderAPI != 0 )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: 7);
    v11 = params[NOSCALE.m_Index];
    pShaderShadow = 1;
    pShaderAPI = 1;
    if ( v11->m_intVal == 0 )
      v10->GetLightmapDimensions(this: v10, a2: &pShaderShadow, a3: &pShaderAPI);
    v10->SetVertexShaderIndex(this: v10, a2: 0);
    ((void (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
      a1: g_pHardwareConfig,
      a2: v12);
    v10->SetPixelShaderIndex(this: v10, a2: 0);
    transformation[0].x = (float)pShaderShadow;
    transformation[0].y = 0.0;
    transformation[0].z = 0.0;
    transformation[0].w = 0.0;
    transformation[1].x = 0.0;
    transformation[1].y = (float)pShaderAPI;
    transformation[1].z = 0.0;
    transformation[1].w = 0.0;
    CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: 48,
      a3: (const float *)transformation,
      a4: 2,
      a5: false);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10001850
// Name: public: virtual int DebugLuxels::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugLuxels::CShader::GetParamCount(DebugLuxels::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_1.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001860
// Name: public: virtual struct ShaderParamInfo_t const __near & DebugLuxels::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DebugLuxels::CShaderParam *__thiscall DebugLuxels::CShader::GetParamInfo(DebugLuxels::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_1.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DebugLuxels::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: public: DebugLuxels::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DebugLuxels::CShaderParam *__thiscall DebugLuxels::CShaderParam::CShaderParam(
        DebugLuxels::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  DebugLuxels::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  DebugLuxels::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_1.m_Size + 13;
  m_Size = s_ShaderParams_1.m_Size;
  v8 = s_ShaderParams_1.m_Size;
  if ( s_ShaderParams_1.m_Size + 1 > s_ShaderParams_1.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<DebugDrawEnvmapMask::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_1,
      num: s_ShaderParams_1.m_Size - s_ShaderParams_1.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_1.m_Size;
  }
  m_pMemory = s_ShaderParams_1.m_Memory.m_pMemory;
  s_ShaderParams_1.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_1.m_pElements = s_ShaderParams_1.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_1.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_1.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_1.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100168D0
// Name: DebugLuxels::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DebugLuxels::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DebugLuxels::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100168E0
// Name: DebugLuxels::_dynamic_initializer_for__NOSCALE__
// Source: json
//------------------------------------------------------------------------------
DebugLuxels::CShaderParam *DebugLuxels::_dynamic_initializer_for__NOSCALE__()
{
  return DebugLuxels::CShaderParam::CShaderParam(
           this: &NOSCALE,
           pName: "$NOSCALE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "fixme",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016900
// Name: DebugLuxels::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DebugLuxels::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_1);
  s_ShaderInstance_1.__vftable = (DebugLuxels::CShader_vtbl *)&DebugLuxels::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016D50
// Name: DebugLuxels::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugLuxels::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>::~CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_1);
}

//------------------------------------------------------------------------------
// Address: 0x10016920
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10016940
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10016960
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10016980
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100169A0
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100169C0
// Name: _dynamic_initializer_for__mat_displacementmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_displacementmap__()
{
  ConVar::ConVar(this: &mat_displacementmap, pName: "mat_displacementmap", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_displacementmap__);
}

//------------------------------------------------------------------------------
// Address: 0x10016D60
// Name: _dynamic_atexit_destructor_for__mat_displacementmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_displacementmap__()
{
  ConVar::~ConVar(this: &mat_displacementmap);
}
