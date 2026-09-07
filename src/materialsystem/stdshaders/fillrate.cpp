// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/fillrate.cpp
// Functions: 31
// ============================================================

#include "materialsystem\stdshaders\fillrate.h"

//------------------------------------------------------------------------------
// Address: 0x10001360
// Name: public: virtual char const __near * Fillrate::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Fillrate::CShader::GetFallbackShader(DebugDepth::CShader *this, IMaterialVar **params)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001560
// Name: public: CUtlVector<class Fillrate::CShaderParam __near *,class CUtlMemory<class Fillrate::CShaderParam __near *,int>>::~CUtlVector<class Fillrate::CShaderParam __near *,class CUtlMemory<class Fillrate::CShaderParam __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>::~CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this)
{
  bool v2; // sf
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001FB0
// Name: public: virtual char const __near * Fillrate::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Fillrate::CShader::GetName(Fillrate::CShader *this)
{
  return s_Name_4;
}

//------------------------------------------------------------------------------
// Address: 0x10001FC0
// Name: public: virtual int Fillrate::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Fillrate::CShader::GetFlags(Fillrate::CShader *this)
{
  return s_nFlags_3;
}

//------------------------------------------------------------------------------
// Address: 0x10001FD0
// Name: public: virtual void Fillrate::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Fillrate::CShader::OnDrawElements(
        Fillrate::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  BOOL v6; // edi
  int v7; // eax
  bool v8; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  int m_intVal; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v12; // ebx
  int v13; // eax
  BOOL v14; // ebx
  int v15; // eax
  void (__thiscall *v16)(IShaderShadow *, const char *, int); // edx
  void (__thiscall *v17)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v18; // esi
  BOOL v19; // ebx
  int v20; // eax
  const char *v21; // [esp-4h] [ebp-30h]
  const char *v22; // [esp-4h] [ebp-30h]
  int v23; // [esp+0h] [ebp-2Ch]
  float color[4]; // [esp+Ch] [ebp-20h] BYREF
  fillrate_vs20_Dynamic_Index _vshIndex; // [esp+1Ch] [ebp-10h]
  CBaseShader *v26; // [esp+28h] [ebp-4h]

  v26 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
    pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_ONE, a3: SHADER_BLEND_ONE);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1025u, a3: 1, a4: nullptr, a5: 0);
    v6 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "fillrate_vs20", a3: 8 * (v6 + 2 * (v7 < 92)));
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    SetPixelShader = pShaderShadow->SetPixelShader;
    v23 = 0;
    if ( v8 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "fillrate_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "fillrate_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    m_intVal = params[PASSCOUNT.m_Index]->m_intVal;
    if ( !g_pConfig->bMeasureFillRate )
      m_intVal *= 16;
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    color[0] = (float)m_intVal * 0.0078431377;
    memset(&color[1], 0, 12);
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: color, a4: 1, a5: false);
    v12 = ((int (__thiscall *)(IShaderDynamicAPI *, int))pShaderAPI->GetSceneFogMode)(a1: pShaderAPI, a2: v23) == 2;
    _vshIndex.m_nSKINNING = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v13 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v13 > 0, v21);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v12 + 2 * (vertexCompression + 2 * _vshIndex.m_nSKINNING));
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this: v26, bMakeActualDrawCall: true);
  if ( pShaderShadow != nullptr )
  {
    ((void (__thiscall *)(IShaderShadow *, _DWORD, int))pShaderShadow->EnableDepthTest)(
      a1: pShaderShadow,
      a2: 0,
      a3: v23);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
    pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_ONE, a3: SHADER_BLEND_ONE);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->PolyMode(this: pShaderShadow, a2: SHADER_POLYMODEFACE_FRONT_AND_BACK, a3: SHADER_POLYMODE_LINE);
    v14 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v15 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "fillrate_vs20", a3: 8 * (v14 + 2 * (v15 < 92)));
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    v16 = pShaderShadow->SetPixelShader;
    if ( v8 )
      ((void (__stdcall *)(const char *))v16)(a1: "fillrate_ps20");
    else
      ((void (__stdcall *)(const char *))v16)(a1: "fillrate_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    v17 = pShaderAPI->SetPixelShaderConstant;
    color[0] = 0.0;
    color[1] = 0.050000001;
    color[2] = 0.050000001;
    color[3] = 0.0;
    v17(this: pShaderAPI, a2: 0, a3: color, a4: 1, a5: false);
    v18 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v19 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v20 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v20 > 0, v22);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v18 + 2 * (vertexCompression + 2 * v19));
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this: v26, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10002360
// Name: public: virtual int Fillrate::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Fillrate::CShader::GetParamCount(Fillrate::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_4.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10002370
// Name: public: void CUtlMemory<class DebugDrawEnvmapMask::CShaderParam __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<DebugDrawEnvmapMask::CShaderParam *,int>::Grow(
        CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Realloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: m_pMemory,
                                                                             a3: v7);
    else
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Alloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002400
// Name: public: virtual struct ShaderParamInfo_t const __near & Fillrate::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Fillrate::CShaderParam *__thiscall Fillrate::CShader::GetParamInfo(Fillrate::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_4.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Fillrate::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10002430
// Name: public: Fillrate::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Fillrate::CShaderParam *__thiscall Fillrate::CShaderParam::CShaderParam(
        Fillrate::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Fillrate::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Fillrate::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_4.m_Size + 13;
  m_Size = s_ShaderParams_4.m_Size;
  v8 = s_ShaderParams_4.m_Size;
  if ( s_ShaderParams_4.m_Size + 1 > s_ShaderParams_4.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<DebugDrawEnvmapMask::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_4,
      num: s_ShaderParams_4.m_Size - s_ShaderParams_4.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_4.m_Size;
  }
  m_pMemory = s_ShaderParams_4.m_Memory.m_pMemory;
  s_ShaderParams_4.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_4.m_pElements = s_ShaderParams_4.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_4.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_4.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_4.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003600
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: m_pMemory,
                                                                                                a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016BC0
// Name: Fillrate::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Fillrate::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Fillrate::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10016BD0
// Name: Fillrate::_dynamic_initializer_for__PASSCOUNT__
// Source: json
//------------------------------------------------------------------------------
Fillrate::CShaderParam *Fillrate::_dynamic_initializer_for__PASSCOUNT__()
{
  return Fillrate::CShaderParam::CShaderParam(
           this: &PASSCOUNT,
           pName: "$PASSCOUNT",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "1",
           pHelp: "Number of passes for this material",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016BF0
// Name: Fillrate::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Fillrate::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_4);
  s_ShaderInstance_4.__vftable = (Fillrate::CShader_vtbl *)&Fillrate::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016D90
// Name: Fillrate::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Fillrate::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>::~CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_4);
}

//------------------------------------------------------------------------------
// Address: 0x100024D0
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _calloc_crt(unsigned int count, unsigned int size)
{
  unsigned __int8 *v2; // edi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * count);
  memset(dst: v2, value: 0, count: size * count);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10002500
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10002520
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: v3, value: 0, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10002560
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x10002580
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002590
// Name: __heap_term
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _heap_term()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100025A0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10016C10
// Name: _dynamic_initializer_for____g_CreateIShaderDLLInternal_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateIShaderDLLInternal_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateIShaderDLLInternal_reg,
           fn: (void *(__cdecl *)())GetShaderDLLInternal,
           pName: "ShaderDLL004");
}

//------------------------------------------------------------------------------
// Address: 0x10016C30
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x10016C50
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016CB0
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016CE0
// Name: _dynamic_atexit_destructor_for__r_flashlightbrightness__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightbrightness__()
{
  ConVar::~ConVar(this: &r_flashlightbrightness);
}

//------------------------------------------------------------------------------
// Address: 0x10016CF0
// Name: _dynamic_atexit_destructor_for__r_emulategl__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_emulategl__()
{
  ConVar::~ConVar(this: &r_emulategl);
}

//------------------------------------------------------------------------------
// Address: 0x10016D00
// Name: _dynamic_atexit_destructor_for__mat_debugdepthmode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_debugdepthmode__()
{
  ConVar::~ConVar(this: &mat_debugdepthmode);
}

//------------------------------------------------------------------------------
// Address: 0x10016D10
// Name: _dynamic_atexit_destructor_for__mat_debugdepthval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_debugdepthval__()
{
  ConVar::~ConVar(this: &mat_debugdepthval);
}

//------------------------------------------------------------------------------
// Address: 0x10016D20
// Name: _dynamic_atexit_destructor_for__mat_debugdepthvalmax__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_debugdepthvalmax__()
{
  ConVar::~ConVar(this: &mat_debugdepthvalmax);
}

//------------------------------------------------------------------------------
// Address: 0x10016DA0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>::~CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>(this: &s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}
