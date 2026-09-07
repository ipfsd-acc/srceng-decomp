// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/floattoscreen.cpp
// Functions: 17
// ============================================================

#include "materialsystem\stdshaders\floattoscreen.h"

//------------------------------------------------------------------------------
// Address: 0x100140C0
// Name: public: virtual char const __near * floattoscreen::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall floattoscreen::CShader::GetName(floattoscreen::CShader *this)
{
  return s_Name_40;
}

//------------------------------------------------------------------------------
// Address: 0x100140D0
// Name: public: virtual int floattoscreen::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall floattoscreen::CShader::GetFlags(floattoscreen::CShader *this)
{
  return s_nFlags_16;
}

//------------------------------------------------------------------------------
// Address: 0x100140E0
// Name: public: virtual void floattoscreen::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall floattoscreen::CShader::OnInitShaderInstance(
        floattoscreen::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[FBTEXTURE_1.m_Index]->IsDefined(this: params[FBTEXTURE_1.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: FBTEXTURE_1.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10014120
// Name: public: virtual void floattoscreen::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall floattoscreen::CShader::OnDrawElements(
        floattoscreen::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  char *v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // edi
  void *v9; // esp
  IMaterialVar *v10; // ecx
  IShaderShadow_vtbl *v11; // edi
  int v12; // eax
  int v13; // [esp-4h] [ebp-14h]
  unsigned __int8 v14[12]; // [esp+0h] [ebp-10h] BYREF
  CBaseShader *v15; // [esp+Ch] [ebp-4h]

  v15 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      v10 = params[PIXSHADER.m_Index];
    }
    else
    {
      v6 = (char *)params[PIXSHADER.m_Index]->GetStringValue(this: params[PIXSHADER.m_Index]);
      v7 = _V_strlen(str: v6);
      v8 = v7;
      if ( v7 > 5 && _V_stricmp(s1: &v6[v7 - 5], s2: "_ps20") == 0 )
      {
        v9 = alloca(v8 + 2);
        memcpy(dst: v14, src: (unsigned __int8 *)v6, count: v8);
        *(_WORD *)&v14[v8] = 98;
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: (const char *)v14, a3: 0);
        goto LABEL_9;
      }
      v10 = params[PIXSHADER.m_Index];
    }
    v11 = pShaderShadow->__vftable;
    v12 = ((int (__thiscall *)(IMaterialVar *, _DWORD))v10->GetStringValue)(a1: v10, a2: 0);
    v11->SetPixelShader(this: pShaderShadow, a2: (const char *)v12, a3: v13);
  }
LABEL_9:
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v15,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: FBTEXTURE_1.m_Index,
      nFrameVar: -1);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this: v15, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10014270
// Name: public: virtual int floattoscreen::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall floattoscreen::CShader::GetParamCount(floattoscreen::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_40.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10014280
// Name: public: virtual struct ShaderParamInfo_t const __near & floattoscreen::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
floattoscreen::CShaderParam *__thiscall floattoscreen::CShader::GetParamInfo(floattoscreen::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_40.m_Memory.m_pMemory[param - ParamCount];
  else
    return (floattoscreen::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100142B0
// Name: public: floattoscreen::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
floattoscreen::CShaderParam *__thiscall floattoscreen::CShaderParam::CShaderParam(
        floattoscreen::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  floattoscreen::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  floattoscreen::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_40.m_Size + 13;
  m_Size = s_ShaderParams_40.m_Size;
  v8 = s_ShaderParams_40.m_Size;
  if ( s_ShaderParams_40.m_Size + 1 > s_ShaderParams_40.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_40,
      num: s_ShaderParams_40.m_Size - s_ShaderParams_40.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_40.m_Size;
  }
  m_pMemory = s_ShaderParams_40.m_Memory.m_pMemory;
  s_ShaderParams_40.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_40.m_pElements = s_ShaderParams_40.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_40.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_40.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_40.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100619A0
// Name: floattoscreen::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int floattoscreen::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: floattoscreen::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100619B0
// Name: floattoscreen::_dynamic_initializer_for__FBTEXTURE__
// Source: json
//------------------------------------------------------------------------------
floattoscreen::CShaderParam *floattoscreen::_dynamic_initializer_for__FBTEXTURE__()
{
  return floattoscreen::CShaderParam::CShaderParam(
           this: &FBTEXTURE_1,
           pName: "$FBTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100619D0
// Name: floattoscreen::_dynamic_initializer_for__PIXSHADER__
// Source: json
//------------------------------------------------------------------------------
floattoscreen::CShaderParam *floattoscreen::_dynamic_initializer_for__PIXSHADER__()
{
  return floattoscreen::CShaderParam::CShaderParam(
           this: &PIXSHADER,
           pName: "$PIXSHADER",
           type: SHADER_PARAM_TYPE_STRING,
           pDefaultParam: "floattoscreen_ps20",
           pHelp: "Name of the pixel shader to use",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100619F0
// Name: floattoscreen::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *floattoscreen::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_40);
  s_ShaderInstance_40.__vftable = (floattoscreen::CShader_vtbl *)&floattoscreen::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B220
// Name: floattoscreen::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl floattoscreen::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_40);
}

//------------------------------------------------------------------------------
// Address: 0x10061A10
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___8()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_8);
}

//------------------------------------------------------------------------------
// Address: 0x10061A30
// Name: _dynamic_initializer_for__s_ConstructMe_floattoscreen_vanilla_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_floattoscreen_vanilla_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &floattoscreen_vanilla_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061A50
// Name: _dynamic_initializer_for__s_ConstructMe_floattoscreen_vanilla_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_floattoscreen_vanilla_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &floattoscreen_vanilla_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061A70
// Name: _dynamic_initializer_for__s_ConstructMe_floattoscreen_ps20___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_floattoscreen_ps20___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &floattoscreen_ps20_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x10061A90
// Name: _dynamic_initializer_for__s_ConstructMe_floattoscreen_ps20b___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_floattoscreen_ps20b___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &floattoscreen_ps20b_combos_0);
}
