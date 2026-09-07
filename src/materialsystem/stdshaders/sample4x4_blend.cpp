// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/sample4x4_blend.cpp
// Functions: 13
// ============================================================

#include "materialsystem\stdshaders\sample4x4_blend.h"

//------------------------------------------------------------------------------
// Address: 0x1002AEA0
// Name: public: virtual char const __near * Sample4x4_Blend::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Sample4x4_Blend::CShader::GetName(Sample4x4_Blend::CShader *this)
{
  return s_Name_91;
}

//------------------------------------------------------------------------------
// Address: 0x1002AEB0
// Name: public: virtual int Sample4x4_Blend::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sample4x4_Blend::CShader::GetFlags(Sample4x4_Blend::CShader *this)
{
  return s_nFlags_107;
}

//------------------------------------------------------------------------------
// Address: 0x1002AEC0
// Name: public: virtual void Sample4x4_Blend::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sample4x4_Blend::CShader::OnInitShaderInstance(
        Sample4x4_Blend::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: BASETEXTURE_2.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002AED0
// Name: public: virtual void Sample4x4_Blend::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sample4x4_Blend::CShader::OnDrawElements(
        Sample4x4_Blend::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  Sample4x4_Blend::CShader *v6; // ebx
  bool v7; // cc
  int (*GetStringValue)(void); // eax
  char *v9; // ebx
  unsigned int v10; // eax
  unsigned int v11; // edi
  void *v12; // esp
  IShaderShadow_vtbl *v13; // edi
  int v14; // eax
  int v15; // edi
  int v16; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v18)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v19)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IShaderDynamicAPI_vtbl *v20; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v22; // [esp-4h] [ebp-24h]
  unsigned __int8 v23[12]; // [esp+0h] [ebp-20h] BYREF
  float v[4]; // [esp+Ch] [ebp-14h] BYREF
  float v25; // [esp+1Ch] [ebp-4h]
  float paramsa; // [esp+28h] [ebp+8h]
  float dY; // [esp+2Ch] [ebp+Ch]

  v6 = this;
  v25 = *(float *)&this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "Downsample_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    GetStringValue = (int (*)(void))params[PIXSHADER_1.m_Index]->GetStringValue;
    if ( !v7 )
    {
      v9 = (char *)GetStringValue();
      v10 = _V_strlen(str: v9);
      v11 = v10;
      if ( v10 > 5 && _V_stricmp(s1: &v9[v10 - 5], s2: "_ps20") == 0 )
      {
        v12 = alloca(v11 + 2);
        memcpy(dst: v23, src: (unsigned __int8 *)v9, count: v11);
        *(_WORD *)&v23[v11] = 98;
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: (const char *)v23, a3: 0);
LABEL_8:
        pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
        pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
        v6 = (Sample4x4_Blend::CShader *)LODWORD(v25);
        goto LABEL_9;
      }
      GetStringValue = (int (*)(void))params[PIXSHADER_1.m_Index]->GetStringValue;
    }
    v13 = pShaderShadow->__vftable;
    v14 = ((int (__cdecl *)(_DWORD))GetStringValue)(a1: 0);
    v13->SetPixelShader(this: pShaderShadow, a2: (const char *)v14, a3: v22);
    goto LABEL_8;
  }
LABEL_9:
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v6,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: BASETEXTURE_2.m_Index,
      nFrameVar: -1);
    v15 = params[BASETEXTURE_2.m_Index]->GetTextureValue(this: params[BASETEXTURE_2.m_Index]);
    paramsa = 1.0 / (float)(*(int (__thiscall **)(int))(*(_DWORD *)v15 + 12))(a1: v15);
    v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 16))(a1: v15);
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    LODWORD(v[0]) = LODWORD(paramsa) ^ _mask__NegFloat_;
    dY = 1.0 / (float)v16;
    LODWORD(v25) = LODWORD(dY) ^ _mask__NegFloat_;
    LODWORD(v[1]) = LODWORD(dY) ^ _mask__NegFloat_;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: v, a4: 1, a5: false);
    v18 = pShaderAPI->SetVertexShaderConstant;
    LODWORD(v[0]) = LODWORD(paramsa) ^ _mask__NegFloat_;
    v[1] = dY;
    v18(this: pShaderAPI, a2: 49, a3: v, a4: 1, a5: false);
    v19 = pShaderAPI->SetVertexShaderConstant;
    v[0] = paramsa;
    v[1] = v25;
    v19(this: pShaderAPI, a2: 50, a3: v, a4: 1, a5: false);
    v20 = pShaderAPI->__vftable;
    v[0] = paramsa;
    v[1] = dY;
    v20->SetVertexShaderConstant(this: pShaderAPI, a2: 51, a3: v, a4: 1, a5: false);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    v[0] = 5.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: v, a4: 1, a5: false);
  }
  CBaseShader::Draw(this: v6, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002B160
// Name: public: virtual int Sample4x4_Blend::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sample4x4_Blend::CShader::GetParamCount(Sample4x4_Blend::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_91.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002B170
// Name: public: virtual struct ShaderParamInfo_t const __near & Sample4x4_Blend::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Sample4x4_Blend::CShaderParam *__thiscall Sample4x4_Blend::CShader::GetParamInfo(
        Sample4x4_Blend::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_91.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Sample4x4_Blend::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002B1A0
// Name: public: Sample4x4_Blend::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Sample4x4_Blend::CShaderParam *__thiscall Sample4x4_Blend::CShaderParam::CShaderParam(
        Sample4x4_Blend::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Sample4x4_Blend::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Sample4x4_Blend::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_91.m_Size + 13;
  m_Size = s_ShaderParams_91.m_Size;
  v8 = s_ShaderParams_91.m_Size;
  if ( s_ShaderParams_91.m_Size + 1 > s_ShaderParams_91.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_91,
      num: s_ShaderParams_91.m_Size - s_ShaderParams_91.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_91.m_Size;
  }
  m_pMemory = s_ShaderParams_91.m_Memory.m_pMemory;
  s_ShaderParams_91.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_91.m_pElements = s_ShaderParams_91.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_91.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_91.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_91.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10065230
// Name: Sample4x4_Blend::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Sample4x4_Blend::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Sample4x4_Blend::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10065240
// Name: Sample4x4_Blend::_dynamic_initializer_for__BASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
Sample4x4_Blend::CShaderParam *Sample4x4_Blend::_dynamic_initializer_for__BASETEXTURE__()
{
  return Sample4x4_Blend::CShaderParam::CShaderParam(
           this: &BASETEXTURE_2,
           pName: "$BASETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065260
// Name: Sample4x4_Blend::_dynamic_initializer_for__PIXSHADER__
// Source: json
//------------------------------------------------------------------------------
Sample4x4_Blend::CShaderParam *Sample4x4_Blend::_dynamic_initializer_for__PIXSHADER__()
{
  return Sample4x4_Blend::CShaderParam::CShaderParam(
           this: &PIXSHADER_1,
           pName: "$PIXSHADER",
           type: SHADER_PARAM_TYPE_STRING,
           pDefaultParam: "sample4x4_ps20",
           pHelp: "Name of the pixel shader to use",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065280
// Name: Sample4x4_Blend::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Sample4x4_Blend::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_91);
  s_ShaderInstance_91.__vftable = (Sample4x4_Blend::CShader_vtbl *)&Sample4x4_Blend::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B620
// Name: Sample4x4_Blend::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sample4x4_Blend::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_91);
}

//------------------------------------------------------------------------------
// Address: 0x100652A0
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___11
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___11()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_11);
}
