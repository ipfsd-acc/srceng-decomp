// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/multiblend.cpp
// Functions: 43
// ============================================================

#include "materialsystem\stdshaders\multiblend.h"

//------------------------------------------------------------------------------
// Address: 0x1001F410
// Name: public: virtual char const __near * Multiblend::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Multiblend::CShader::GetFallbackShader(Multiblend::CShader *this, IMaterialVar **params)
{
  return "Multiblend_DX90";
}

//------------------------------------------------------------------------------
// Address: 0x1001F420
// Name: public: virtual char const __near * Multiblend::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Multiblend::CShader::GetName(Multiblend::CShader *this)
{
  return s_Name_66;
}

//------------------------------------------------------------------------------
// Address: 0x1001F430
// Name: public: virtual int Multiblend::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Multiblend::CShader::GetFlags(Multiblend::CShader *this)
{
  return s_nFlags_86;
}

//------------------------------------------------------------------------------
// Address: 0x1001F440
// Name: public: virtual int Multiblend::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Multiblend::CShader::GetParamCount(Multiblend::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_66.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001F450
// Name: public: void Multiblend_DX90::CShader::SetupVars(struct Multiblend_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Multiblend_DX90::CShader::SetupVars(Multiblend_DX90::CShader *this, Multiblend_DX9_Vars_t *info)
{
  info->m_nBaseTextureTransform = 8;
  info->m_nBaseTexture = 6;
  info->m_nSpecTexture = SPECTEXTURE.m_Index;
  info->m_nBaseTexture2 = BASETEXTURE2_0.m_Index;
  info->m_nSpecTexture2 = SPECTEXTURE2.m_Index;
  info->m_nBaseTexture3 = BASETEXTURE3.m_Index;
  info->m_nSpecTexture3 = SPECTEXTURE3.m_Index;
  info->m_nBaseTexture4 = BASETEXTURE4.m_Index;
  info->m_nSpecTexture4 = SPECTEXTURE4.m_Index;
  info->m_nRotation = ROTATION.m_Index;
  info->m_nRotation2 = ROTATION2.m_Index;
  info->m_nRotation3 = ROTATION3.m_Index;
  info->m_nRotation4 = ROTATION4.m_Index;
  info->m_nScale = SCALE.m_Index;
  info->m_nScale2 = SCALE2_1.m_Index;
  info->m_nScale3 = SCALE3.m_Index;
  info->m_nScale4 = SCALE4.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x1001F4F0
// Name: public: virtual void Multiblend_DX90::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Multiblend_DX90::CShader::OnInitShaderParams(
        Multiblend_DX90::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  Multiblend_DX9_Vars_t info; // [esp+4h] [ebp-44h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Multiblend_DX90::CShader::SetupVars(this, &info);
  InitParamsMultiblend_DX9(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x1001F540
// Name: public: virtual char const __near * Multiblend_DX90::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Multiblend_DX90::CShader::GetName(Multiblend_DX90::CShader *this)
{
  return s_Name_67;
}

//------------------------------------------------------------------------------
// Address: 0x1001F550
// Name: public: virtual int Multiblend_DX90::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Multiblend_DX90::CShader::GetFlags(Multiblend_DX90::CShader *this)
{
  return s_nFlags_87;
}

//------------------------------------------------------------------------------
// Address: 0x1001F560
// Name: public: virtual void Multiblend_DX90::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Multiblend_DX90::CShader::OnInitShaderInstance(
        Multiblend_DX90::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  Multiblend_DX9_Vars_t info; // [esp+4h] [ebp-44h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Multiblend_DX90::CShader::SetupVars(this, &info);
  InitMultiblend_DX9(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x1001F5A0
// Name: public: virtual void Multiblend_DX90::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Multiblend_DX90::CShader::OnDrawElements(
        Multiblend_DX90::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  Multiblend_DX9_Vars_t info; // [esp+4h] [ebp-44h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Multiblend_DX90::CShader::SetupVars(this, &info);
  DrawMultiblend_DX9(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x1001F5F0
// Name: public: virtual int Multiblend_DX90::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Multiblend_DX90::CShader::GetParamCount(Multiblend_DX90::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_67.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001F600
// Name: public: virtual struct ShaderParamInfo_t const __near & Multiblend::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Multiblend::CShaderParam *__thiscall Multiblend::CShader::GetParamInfo(Multiblend::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_66.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Multiblend::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001F630
// Name: public: virtual struct ShaderParamInfo_t const __near & Multiblend_DX90::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *__thiscall Multiblend_DX90::CShader::GetParamInfo(
        Multiblend_DX90::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_67.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Multiblend_DX90::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001F660
// Name: public: Multiblend_DX90::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *__thiscall Multiblend_DX90::CShaderParam::CShaderParam(
        Multiblend_DX90::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Multiblend_DX90::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Multiblend_DX90::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_67.m_Size + 13;
  m_Size = s_ShaderParams_67.m_Size;
  v8 = s_ShaderParams_67.m_Size;
  if ( s_ShaderParams_67.m_Size + 1 > s_ShaderParams_67.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_67,
      num: s_ShaderParams_67.m_Size - s_ShaderParams_67.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_67.m_Size;
  }
  m_pMemory = s_ShaderParams_67.m_Memory.m_pMemory;
  s_ShaderParams_67.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_67.m_pElements = s_ShaderParams_67.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_67.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_67.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_67.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063720
// Name: Multiblend::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Multiblend::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Multiblend::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063730
// Name: Multiblend::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Multiblend::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_66);
  s_ShaderInstance_66.__vftable = (Multiblend::CShader_vtbl *)&Multiblend::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063750
// Name: Multiblend_DX90::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Multiblend_DX90::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Multiblend_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063760
// Name: Multiblend_DX90::_dynamic_initializer_for__SPECTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__SPECTEXTURE__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &SPECTEXTURE,
           pName: "$SPECTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063780
// Name: Multiblend_DX90::_dynamic_initializer_for__BASETEXTURE2__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__BASETEXTURE2__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &BASETEXTURE2_0,
           pName: "$BASETEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100637A0
// Name: Multiblend_DX90::_dynamic_initializer_for__SPECTEXTURE2__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__SPECTEXTURE2__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &SPECTEXTURE2,
           pName: "$SPECTEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100637C0
// Name: Multiblend_DX90::_dynamic_initializer_for__BASETEXTURE3__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__BASETEXTURE3__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &BASETEXTURE3,
           pName: "$BASETEXTURE3",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100637E0
// Name: Multiblend_DX90::_dynamic_initializer_for__SPECTEXTURE3__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__SPECTEXTURE3__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &SPECTEXTURE3,
           pName: "$SPECTEXTURE3",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063800
// Name: Multiblend_DX90::_dynamic_initializer_for__BASETEXTURE4__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__BASETEXTURE4__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &BASETEXTURE4,
           pName: "$BASETEXTURE4",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063820
// Name: Multiblend_DX90::_dynamic_initializer_for__SPECTEXTURE4__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__SPECTEXTURE4__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &SPECTEXTURE4,
           pName: "$SPECTEXTURE4",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063840
// Name: Multiblend_DX90::_dynamic_initializer_for__ROTATION__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__ROTATION__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &ROTATION,
           pName: "$ROTATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063860
// Name: Multiblend_DX90::_dynamic_initializer_for__SCALE__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__SCALE__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &SCALE,
           pName: "$SCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063880
// Name: Multiblend_DX90::_dynamic_initializer_for__ROTATION2__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__ROTATION2__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &ROTATION2,
           pName: "$ROTATION2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100638A0
// Name: Multiblend_DX90::_dynamic_initializer_for__SCALE2__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__SCALE2__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &SCALE2_1,
           pName: "$SCALE2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100638C0
// Name: Multiblend_DX90::_dynamic_initializer_for__ROTATION3__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__ROTATION3__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &ROTATION3,
           pName: "$ROTATION3",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100638E0
// Name: Multiblend_DX90::_dynamic_initializer_for__SCALE3__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__SCALE3__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &SCALE3,
           pName: "$SCALE3",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063900
// Name: Multiblend_DX90::_dynamic_initializer_for__ROTATION4__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__ROTATION4__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &ROTATION4,
           pName: "$ROTATION4",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063920
// Name: Multiblend_DX90::_dynamic_initializer_for__SCALE4__
// Source: json
//------------------------------------------------------------------------------
Multiblend_DX90::CShaderParam *Multiblend_DX90::_dynamic_initializer_for__SCALE4__()
{
  return Multiblend_DX90::CShaderParam::CShaderParam(
           this: &SCALE4,
           pName: "$SCALE4",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063940
// Name: Multiblend_DX90::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Multiblend_DX90::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_67);
  s_ShaderInstance_67.__vftable = (Multiblend_DX90::CShader_vtbl *)&Multiblend_DX90::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B430
// Name: Multiblend::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Multiblend::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_66);
}

//------------------------------------------------------------------------------
// Address: 0x1006B440
// Name: Multiblend_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Multiblend_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_67);
}

//------------------------------------------------------------------------------
// Address: 0x10063960
// Name: _dynamic_initializer_for__s_ConstructMe_multiblend_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_multiblend_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &multiblend_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063980
// Name: _dynamic_initializer_for__s_ConstructMe_multiblend_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_multiblend_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &multiblend_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100639A0
// Name: _dynamic_initializer_for__s_ConstructMe_multiblend_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_multiblend_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &multiblend_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100639C0
// Name: _dynamic_initializer_for__s_ConstructMe_multiblend_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_multiblend_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &multiblend_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100639E0
// Name: _dynamic_initializer_for__s_ConstructMe_multiblend_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_multiblend_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &multiblend_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063A00
// Name: _dynamic_initializer_for__s_ConstructMe_object_motion_blur_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_object_motion_blur_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &object_motion_blur_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063A20
// Name: _dynamic_initializer_for__s_ConstructMe_object_motion_blur_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_object_motion_blur_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &object_motion_blur_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063A40
// Name: _dynamic_initializer_for__s_ConstructMe_object_motion_blur_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_object_motion_blur_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &object_motion_blur_ps20b_combos);
}
