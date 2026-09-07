// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/object_motion_blur_dx9.cpp
// Functions: 15
// ============================================================

#include "materialsystem\stdshaders\object_motion_blur_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10020150
// Name: public: virtual char const __near * ObjectMotionBlur::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ObjectMotionBlur::CShader::GetName(ObjectMotionBlur::CShader *this)
{
  return s_Name_68;
}

//------------------------------------------------------------------------------
// Address: 0x10020160
// Name: public: virtual int ObjectMotionBlur::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ObjectMotionBlur::CShader::GetFlags(ObjectMotionBlur::CShader *this)
{
  return s_nFlags_26;
}

//------------------------------------------------------------------------------
// Address: 0x10020170
// Name: public: virtual void ObjectMotionBlur::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ObjectMotionBlur::CShader::OnInitShaderInstance(
        ObjectMotionBlur::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[FB_TEXTURE.m_Index]->IsDefined(this: params[FB_TEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: FB_TEXTURE.m_Index, nAdditionalCreationFlags: 0);
  if ( params[VELOCITY_TEXTURE.m_Index]->IsDefined(this: params[VELOCITY_TEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: VELOCITY_TEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100201D0
// Name: public: virtual void ObjectMotionBlur::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ObjectMotionBlur::CShader::OnDrawElements(
        ObjectMotionBlur::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "object_motion_blur_vs20", a3: 0);
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "object_motion_blur_ps20b", a3: 0);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: FB_TEXTURE.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: VELOCITY_TEXTURE.m_Index,
      nFrameVar: -1);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100202C0
// Name: public: virtual int ObjectMotionBlur::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ObjectMotionBlur::CShader::GetParamCount(ObjectMotionBlur::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_68.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100202D0
// Name: public: virtual struct ShaderParamInfo_t const __near & ObjectMotionBlur::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ObjectMotionBlur::CShaderParam *__thiscall ObjectMotionBlur::CShader::GetParamInfo(
        ObjectMotionBlur::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_68.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ObjectMotionBlur::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10020300
// Name: public: ObjectMotionBlur::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ObjectMotionBlur::CShaderParam *__thiscall ObjectMotionBlur::CShaderParam::CShaderParam(
        ObjectMotionBlur::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  ObjectMotionBlur::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  ObjectMotionBlur::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_68.m_Size + 13;
  m_Size = s_ShaderParams_68.m_Size;
  v8 = s_ShaderParams_68.m_Size;
  if ( s_ShaderParams_68.m_Size + 1 > s_ShaderParams_68.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_68,
      num: s_ShaderParams_68.m_Size - s_ShaderParams_68.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_68.m_Size;
  }
  m_pMemory = s_ShaderParams_68.m_Memory.m_pMemory;
  s_ShaderParams_68.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_68.m_pElements = s_ShaderParams_68.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_68.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_68.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_68.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063A60
// Name: ObjectMotionBlur::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ObjectMotionBlur::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ObjectMotionBlur::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063A70
// Name: ObjectMotionBlur::_dynamic_initializer_for__FB_TEXTURE__
// Source: json
//------------------------------------------------------------------------------
ObjectMotionBlur::CShaderParam *ObjectMotionBlur::_dynamic_initializer_for__FB_TEXTURE__()
{
  return ObjectMotionBlur::CShaderParam::CShaderParam(
           this: &FB_TEXTURE,
           pName: "$FB_TEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_FullFrameFB",
           pHelp: "Full-screen framebuffer to sample from.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063A90
// Name: ObjectMotionBlur::_dynamic_initializer_for__VELOCITY_TEXTURE__
// Source: json
//------------------------------------------------------------------------------
ObjectMotionBlur::CShaderParam *ObjectMotionBlur::_dynamic_initializer_for__VELOCITY_TEXTURE__()
{
  return ObjectMotionBlur::CShaderParam::CShaderParam(
           this: &VELOCITY_TEXTURE,
           pName: "$VELOCITY_TEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_SmallHDR0",
           pHelp: "Full-screen velocity buffer to sample from.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063AB0
// Name: ObjectMotionBlur::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ObjectMotionBlur::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_68);
  s_ShaderInstance_68.__vftable = (ObjectMotionBlur::CShader_vtbl *)&ObjectMotionBlur::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B450
// Name: ObjectMotionBlur::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ObjectMotionBlur::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_68);
}

//------------------------------------------------------------------------------
// Address: 0x10063AD0
// Name: _dynamic_initializer_for__s_ConstructMe_writez_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_writez_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &writez_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063AF0
// Name: _dynamic_initializer_for__s_ConstructMe_white_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_white_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &white_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063B10
// Name: _dynamic_initializer_for__s_ConstructMe_white_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_white_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &white_ps20b_combos);
}
