// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/debugtextureview.cpp
// Functions: 23
// ============================================================

#include "materialsystem\stdshaders\debugtextureview.h"

//------------------------------------------------------------------------------
// Address: 0x1000A6F0
// Name: public: virtual char const __near * DebugTextureView::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DebugTextureView::CShader::GetFallbackShader(
        DebugTextureView::CShader *this,
        IMaterialVar **params)
{
  return "DebugTextureView_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x1000A700
// Name: public: virtual char const __near * DebugTextureView::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DebugTextureView::CShader::GetName(DebugTextureView::CShader *this)
{
  return s_Name_19;
}

//------------------------------------------------------------------------------
// Address: 0x1000A710
// Name: public: virtual int DebugTextureView::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugTextureView::CShader::GetFlags(DebugTextureView::CShader *this)
{
  return s_nFlags_57;
}

//------------------------------------------------------------------------------
// Address: 0x1000A720
// Name: public: virtual int DebugTextureView::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugTextureView::CShader::GetParamCount(DebugTextureView::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_19.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000A730
// Name: public: virtual char const __near * DebugTextureView_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DebugTextureView_dx9::CShader::GetName(DebugTextureView_dx9::CShader *this)
{
  return s_Name_20;
}

//------------------------------------------------------------------------------
// Address: 0x1000A740
// Name: public: virtual int DebugTextureView_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugTextureView_dx9::CShader::GetFlags(DebugTextureView_dx9::CShader *this)
{
  return s_nFlags_58;
}

//------------------------------------------------------------------------------
// Address: 0x1000A750
// Name: public: virtual void DebugTextureView_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DebugTextureView_dx9::CShader::OnDrawElements(
        DebugTextureView_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v6; // eax
  int v7; // edx
  IMaterialVar *v8; // ecx
  int v9; // edi
  int v10; // edi
  int v11; // esi
  BOOL v12; // ebx
  int v13; // [esp-8h] [ebp-28h]
  const char *v14; // [esp-4h] [ebp-24h]
  float cPsConst0[4]; // [esp+Ch] [ebp-14h] BYREF
  CBaseShader *v16; // [esp+1Ch] [ebp-4h]

  v16 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1025u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "debugtextureview_vs20", a3: 0);
    v6 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v7 = 0;
    v8 = params[SHOWALPHA.m_Index];
    if ( v6 < 92 )
    {
      LOBYTE(v7) = v8->m_intVal != 0;
      v10 = v7;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SHOWALPHA", v7, "params[SHOWALPHA]->GetIntValue() != 0");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "debugtextureview_ps20", a3: 2 * v10);
    }
    else
    {
      LOBYTE(v7) = v8->m_intVal != 0;
      v9 = v7;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SHOWALPHA", v7, "params[SHOWALPHA]->GetIntValue() != 0");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "debugtextureview_ps20b", a3: 2 * v9);
    }
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v16,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: 7);
    v11 = params[6]->GetTextureValue(this: params[6]);
    memset(cPsConst0, 0, sizeof(cPsConst0));
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 76))(a1: v11) == 24
      || (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 76))(a1: v11) == 25
      || (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 76))(a1: v11) == 28
      || (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 76))(a1: v11) == 29 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 84))(a1: v11) != 0 )
        cPsConst0[0] = 1.0;
      else
        cPsConst0[1] = 1.0;
    }
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: cPsConst0, a4: 1, a5: false);
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      v12 = (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 84))(a1: v11) != 0;
      if ( g_shaderConfigDumpEnable )
      {
LABEL_23:
        v13 = (*(unsigned __int8 (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 84))(
                a1: v11,
                a2: "pTexture->IsCubeMap()");
        printf(format: "\n   PS dyn  var %s = %d (%s)", "ISCUBEMAP", v13, v14);
      }
    }
    else
    {
      v12 = (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 84))(a1: v11) != 0;
      if ( g_shaderConfigDumpEnable )
        goto LABEL_23;
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v12);
  }
  CBaseShader::Draw(this: v16, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000A9B0
// Name: public: virtual int DebugTextureView_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugTextureView_dx9::CShader::GetParamCount(DebugTextureView_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_20.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000A9C0
// Name: public: virtual struct ShaderParamInfo_t const __near & DebugTextureView::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DebugTextureView::CShaderParam *__thiscall DebugTextureView::CShader::GetParamInfo(
        DebugTextureView::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_19.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DebugTextureView::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000A9F0
// Name: public: virtual struct ShaderParamInfo_t const __near & DebugTextureView_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DebugTextureView_dx9::CShaderParam *__thiscall DebugTextureView_dx9::CShader::GetParamInfo(
        DebugTextureView_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_20.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DebugTextureView_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000AA20
// Name: public: DebugTextureView_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DebugTextureView_dx9::CShaderParam *__thiscall DebugTextureView_dx9::CShaderParam::CShaderParam(
        DebugTextureView_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  DebugTextureView_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  DebugTextureView_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_20.m_Size + 13;
  m_Size = s_ShaderParams_20.m_Size;
  v8 = s_ShaderParams_20.m_Size;
  if ( s_ShaderParams_20.m_Size + 1 > s_ShaderParams_20.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_20,
      num: s_ShaderParams_20.m_Size - s_ShaderParams_20.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_20.m_Size;
  }
  m_pMemory = s_ShaderParams_20.m_Memory.m_pMemory;
  s_ShaderParams_20.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_20.m_pElements = s_ShaderParams_20.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_20.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_20.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_20.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005F820
// Name: DebugTextureView::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DebugTextureView::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DebugTextureView::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005F830
// Name: DebugTextureView::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DebugTextureView::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_19);
  s_ShaderInstance_19.__vftable = (DebugTextureView::CShader_vtbl *)&DebugTextureView::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005F850
// Name: DebugTextureView_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DebugTextureView_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DebugTextureView_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005F860
// Name: DebugTextureView_dx9::_dynamic_initializer_for__SHOWALPHA__
// Source: json
//------------------------------------------------------------------------------
DebugTextureView_dx9::CShaderParam *DebugTextureView_dx9::_dynamic_initializer_for__SHOWALPHA__()
{
  return DebugTextureView_dx9::CShaderParam::CShaderParam(
           this: &SHOWALPHA,
           pName: "$SHOWALPHA",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F880
// Name: DebugTextureView_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DebugTextureView_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_20);
  s_ShaderInstance_20.__vftable = (DebugTextureView_dx9::CShader_vtbl *)&DebugTextureView_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AFB0
// Name: DebugTextureView::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugTextureView::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_19);
}

//------------------------------------------------------------------------------
// Address: 0x1006AFC0
// Name: DebugTextureView_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugTextureView_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_20);
}

//------------------------------------------------------------------------------
// Address: 0x1005F8A0
// Name: _dynamic_initializer_for__s_ConstructMe_decalmodulate_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_decalmodulate_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &decalmodulate_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F8C0
// Name: _dynamic_initializer_for__s_ConstructMe_decalmodulate_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_decalmodulate_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &decalmodulate_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F8E0
// Name: _dynamic_initializer_for__s_ConstructMe_decalmodulate_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_decalmodulate_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &decalmodulate_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F900
// Name: _dynamic_initializer_for__s_ConstructMe_decalmodulate_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_decalmodulate_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &decalmodulate_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F920
// Name: _dynamic_initializer_for__s_ConstructMe_decalmodulate_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_decalmodulate_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &decalmodulate_ps30_combos);
}
