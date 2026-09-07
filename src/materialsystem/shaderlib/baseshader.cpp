// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderlib/baseshader.cpp
// Functions: 20
// ============================================================

#include "materialsystem\shaderlib\baseshader.h"

//------------------------------------------------------------------------------
// Address: 0x10002CA0
// Name: public: virtual int CBaseShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseShader::GetParamCount(CBaseShader *this)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10002CB0
// Name: public: virtual struct ShaderParamInfo_t const __near & CBaseShader::GetParamInfo(int)const
// Source: json
//------------------------------------------------------------------------------
const ShaderParamInfo_t *__thiscall CBaseShader::GetParamInfo(CBaseShader *this, int nParamIndex)
{
  return &s_StandardParams[nParamIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10002CD0
// Name: public: virtual void CBaseShader::InitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::InitShaderParams(CBaseShader *this, IMaterialVar **ppParams, const char *pMaterialName)
{
  CBaseShader::s_ppParams = ppParams;
  this->OnInitShaderParams(this, a2: ppParams, a3: pMaterialName);
  CBaseShader::s_ppParams = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002D00
// Name: public: virtual void CBaseShader::InitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::InitShaderInstance(
        CBaseShader *this,
        IMaterialVar **ppParams,
        IShaderInit *pShaderInit,
        const char *pMaterialName,
        const char *pTextureGroupName)
{
  CBaseShader::s_ppParams = ppParams;
  CBaseShader::s_pShaderInit = pShaderInit;
  CBaseShader::s_pTextureGroupName = pTextureGroupName;
  this->OnInitShaderInstance(this, a2: ppParams, a3: pShaderInit, a4: pMaterialName);
  CBaseShader::s_pTextureGroupName = nullptr;
  CBaseShader::s_ppParams = nullptr;
  CBaseShader::s_pShaderInit = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002D50
// Name: public: void CBaseShader::SetInitialShadowState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::SetInitialShadowState(CBaseShader *this)
{
  int m_intVal; // esi

  CBaseShader::s_pShaderShadow->SetDefaultState(this: CBaseShader::s_pShaderShadow);
  m_intVal = (*CBaseShader::s_ppParams)->m_intVal;
  if ( (m_intVal & 0x8000) != 0 )
  {
    CBaseShader::s_pShaderShadow->EnableDepthTest(this: CBaseShader::s_pShaderShadow, a2: false);
    CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: false);
  }
  if ( (m_intVal & 0x10000) != 0 )
  {
    CBaseShader::s_pShaderShadow->EnablePolyOffset(this: CBaseShader::s_pShaderShadow, a2: SHADER_POLYOFFSET_DECAL);
    CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: false);
  }
  if ( (m_intVal & 0x2000) != 0 )
    CBaseShader::s_pShaderShadow->EnableCulling(this: CBaseShader::s_pShaderShadow, a2: false);
  if ( (m_intVal & 0x400) != 0 )
    CBaseShader::s_pShaderShadow->DepthFunc(this: CBaseShader::s_pShaderShadow, a2: SHADER_DEPTHFUNC_NEARER);
  if ( (m_intVal & 0x10000000) != 0 )
    CBaseShader::s_pShaderShadow->PolyMode(
      this: CBaseShader::s_pShaderShadow,
      a2: SHADER_POLYMODEFACE_FRONT_AND_BACK,
      a3: SHADER_POLYMODE_LINE);
  if ( (m_intVal & 0x20000000) != 0 )
    CBaseShader::s_pShaderShadow->EnableAlphaToCoverage(this: CBaseShader::s_pShaderShadow, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10002E20
// Name: public: void CBaseShader::LoadTexture(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::LoadTexture(CBaseShader *this, int nTextureVar, int nAdditionalCreationFlags)
{
  IMaterialVar *v3; // esi

  if ( CBaseShader::s_ppParams != nullptr && nTextureVar != -1 )
  {
    v3 = CBaseShader::s_ppParams[nTextureVar];
    if ( v3 != nullptr && v3->IsDefined(this: v3) )
      CBaseShader::s_pShaderInit->LoadTexture(
        this: CBaseShader::s_pShaderInit,
        a2: v3,
        a3: CBaseShader::s_pTextureGroupName,
        a4: nAdditionalCreationFlags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E70
// Name: public: bool CBaseShader::TextureIsTranslucent(int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseShader::TextureIsTranslucent(CBaseShader *this, int textureVar, bool isBaseTexture)
{
  IMaterialVar *v4; // ecx
  int v5; // eax
  int m_intVal; // ecx
  int v7; // eax

  if ( textureVar < 0 )
    return false;
  v4 = CBaseShader::s_ppParams[textureVar];
  if ( (*((_BYTE *)v4 + 28) & 0xF) != 3 )
    return false;
  if ( !isBaseTexture )
  {
    v5 = v4->GetTextureValue(this: v4);
    return (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 24))(a1: v5);
  }
  if ( ((*CBaseShader::s_ppParams)->m_intVal & 0x1000000) != 0 )
    return false;
  m_intVal = (*CBaseShader::s_ppParams)->m_intVal;
  if ( (m_intVal & 0x40) != 0 && (CBaseShader::s_ppParams[2]->m_intVal & 0x400000) == 0 )
    return false;
  if ( (m_intVal & 0x100000) != 0 || (m_intVal & 0x200100) == 0 )
    return false;
  v7 = CBaseShader::s_ppParams[textureVar]->GetTextureValue(this: CBaseShader::s_ppParams[textureVar]);
  return (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 24))(a1: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10002F10
// Name: public: virtual bool CBaseShader::NeedsPowerOfTwoFrameBufferTexture(class IMaterialVar __near * __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseShader::NeedsPowerOfTwoFrameBufferTexture(
        CBaseShader *this,
        IMaterialVar **params,
        bool bCheckSpecificToThisFrame)
{
  return (params[2]->m_intVal & 0x4000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002F30
// Name: public: virtual bool CBaseShader::NeedsFullFrameBufferTexture(class IMaterialVar __near * __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseShader::NeedsFullFrameBufferTexture(
        CBaseShader *this,
        IMaterialVar **params,
        bool bCheckSpecificToThisFrame)
{
  return (params[2]->m_intVal & 0x8000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002F50
// Name: public: virtual bool CBaseShader::IsTranslucent(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseShader::IsTranslucent(CBaseShader *this, IMaterialVar **params)
{
  return ((*params)->m_intVal & 0x200000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002F70
// Name: public: void CBaseShader::SetNormalBlendingShadowState(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::SetNormalBlendingShadowState(CBaseShader *this, int textureVar, bool isBaseTexture)
{
  if ( (CBaseShader::s_nModulationFlags & 1) != 0
    || ((*CBaseShader::s_ppParams)->m_intVal & 0x20) != 0
    || CBaseShader::TextureIsTranslucent(this, textureVar, isBaseTexture)
    && ((*CBaseShader::s_ppParams)->m_intVal & 0x100) == 0 )
  {
    CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: true);
    CBaseShader::s_pShaderShadow->BlendFunc(
      this: CBaseShader::s_pShaderShadow,
      a2: SHADER_BLEND_SRC_ALPHA,
      a3: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: false);
  }
  else
  {
    CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003000
// Name: public: void CBaseShader::SetAdditiveBlendingShadowState(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::SetAdditiveBlendingShadowState(CBaseShader *this, int textureVar, bool isBaseTexture)
{
  int savedregs; // [esp+0h] [ebp+0h]
  int savedregsa; // [esp+0h] [ebp+0h]

  if ( (CBaseShader::s_nModulationFlags & 1) != 0
    || ((*CBaseShader::s_ppParams)->m_intVal & 0x20) != 0
    || CBaseShader::TextureIsTranslucent(this, textureVar, isBaseTexture)
    && ((*CBaseShader::s_ppParams)->m_intVal & 0x100) == 0 )
  {
    CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: true);
    savedregs = 1;
    ((void (__thiscall *)(IShaderShadow *, int))CBaseShader::s_pShaderShadow->BlendFunc)(
      a1: CBaseShader::s_pShaderShadow,
      a2: 4);
  }
  else
  {
    CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: true);
    savedregsa = 1;
    ((void (__thiscall *)(IShaderShadow *, int))CBaseShader::s_pShaderShadow->BlendFunc)(
      a1: CBaseShader::s_pShaderShadow,
      a2: 1);
  }
  CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10003090
// Name: public: void CBaseShader::SetDefaultBlendingShadowState(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::SetDefaultBlendingShadowState(CBaseShader *this, int textureVar, bool isBaseTexture)
{
  if ( SLOBYTE((*CBaseShader::s_ppParams)->m_intVal) >= 0 )
    CBaseShader::SetNormalBlendingShadowState(this, textureVar, isBaseTexture);
  else
    CBaseShader::SetAdditiveBlendingShadowState(this, textureVar, isBaseTexture);
}

//------------------------------------------------------------------------------
// Address: 0x100030B0
// Name: public: void CBaseShader::DisableFog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::DisableFog(CBaseShader *this)
{
  CBaseShader::s_pShaderShadow->FogMode(this: CBaseShader::s_pShaderShadow, a2: SHADER_FOGMODE_DISABLED, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10003110
// Name: public: CBaseShader::CBaseShader(void)
// Source: json
//------------------------------------------------------------------------------
CBaseShader *__thiscall CBaseShader::CBaseShader(CBaseShader *this)
{
  IShaderDLL *ShaderDLL; // eax

  this->__vftable = (CBaseShader_vtbl *)&CBaseShader::`vftable';
  ShaderDLL = GetShaderDLL();
  ShaderDLL->InsertShader(this: ShaderDLL, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003130
// Name: public: virtual void CBaseShader::DrawElements(class IMaterialVar __near * __near *,int,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *,class CBasePerInstanceContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::DrawElements(
        CBaseShader *this,
        IMaterialVar **ppParams,
        int nModulationFlags,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr,
        CBasePerInstanceContextData **pInstanceDataPtr)
{
  CBaseShader::s_ppParams = ppParams;
  CBaseShader::s_pShaderAPI = pShaderAPI;
  CBaseShader::s_pShaderShadow = pShaderShadow;
  CBaseShader::s_nModulationFlags = nModulationFlags;
  CBaseShader::s_pInstanceDataPtr = (CPerInstanceContextData **)pInstanceDataPtr;
  CBaseShader::s_nPassCount = 0;
  if ( pShaderShadow != nullptr )
    CBaseShader::SetInitialShadowState(this);
  this->OnDrawElements(
    this,
    a2: ppParams,
    a3: pShaderShadow,
    a4: pShaderAPI,
    a5: vertexCompression,
    a6: pContextDataPtr);
  CBaseShader::s_pInstanceDataPtr = nullptr;
  CBaseShader::s_nPassCount = 0;
  CBaseShader::s_nModulationFlags = 0;
  CBaseShader::s_ppParams = nullptr;
  CBaseShader::s_pShaderAPI = nullptr;
  CBaseShader::s_pShaderShadow = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100031C0
// Name: public: void CBaseShader::BindTexture(enum Sampler_t,enum TextureBindFlags_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::BindTexture(
        CBaseShader *this,
        Sampler_t sampler1,
        TextureBindFlags_t nBindFlags,
        int nTextureVar,
        int nFrameVar)
{
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // eax
  int m_intVal; // eax
  IShaderSystem *v8; // esi
  IShaderSystem_vtbl *v9; // edi
  int v10; // eax

  v5 = CBaseShader::s_ppParams[nTextureVar];
  if ( nFrameVar == -1 )
    v6 = nullptr;
  else
    v6 = CBaseShader::s_ppParams[nFrameVar];
  if ( v5 != nullptr )
  {
    if ( v6 != nullptr )
      m_intVal = v6->m_intVal;
    else
      m_intVal = 0;
    v8 = g_pSLShaderSystem;
    v9 = g_pSLShaderSystem->__vftable;
    v10 = ((int (__thiscall *)(IMaterialVar *, int))v5->GetTextureValue)(a1: v5, a2: m_intVal);
    ((void (__thiscall *)(IShaderSystem *, Sampler_t, TextureBindFlags_t, int))v9->BindTexture_2)(
      a1: v8,
      a2: sampler1,
      a3: nBindFlags,
      a4: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003220
// Name: public: virtual int CBaseShader::ComputeModulationFlags(class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseShader::ComputeModulationFlags(
        CBaseShader *this,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI)
{
  int v3; // edi
  IShaderDynamicAPI *v4; // ecx
  bool v5; // al
  bool v6; // al
  bool v7; // al
  IMaterialVar *v8; // ecx
  bool v9; // zf
  char v10; // al

  v3 = 0;
  v4 = pShaderAPI;
  CBaseShader::s_pShaderAPI = pShaderAPI;
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    v5 = (params[2]->m_intVal & 0x400) != 0;
  }
  else
  {
    v5 = pShaderAPI->InFlashlightMode(this: pShaderAPI);
    v4 = CBaseShader::s_pShaderAPI;
  }
  if ( v5 )
    v3 = 2;
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    v6 = (params[2]->m_intVal & 0x2000) != 0;
  }
  else
  {
    v6 = v4->InEditorMode(this: v4);
    v4 = CBaseShader::s_pShaderAPI;
  }
  if ( v6 )
    v3 |= 8u;
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    v7 = (params[2]->m_intVal & 0x800) != 0;
  }
  else
  {
    if ( !g_pConfig->m_bPaintInGame || !g_pConfig->m_bPaintInMap )
      goto LABEL_22;
    v7 = v4->IsRenderingPaint(this: v4);
  }
  if ( v7 )
    v3 |= 4u;
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    v8 = params[2];
    if ( (v8->m_intVal & 0x100000) != 0 )
      v3 |= 0x10u;
    v9 = (v8->m_intVal & 0x200000) == 0;
    goto LABEL_25;
  }
LABEL_22:
  v10 = pShaderAPI->GetIntRenderingParameter(this: pShaderAPI, a2: 0);
  if ( (v10 & 1) != 0 )
    v3 |= 0x10u;
  v9 = (v10 & 2) == 0;
LABEL_25:
  CBaseShader::s_pShaderAPI = nullptr;
  if ( !v9 )
    return v3 | 0x20;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10003320
// Name: public: void CBaseShader::PI_EndCommandBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_EndCommandBuffer(CBaseShader *this)
{
  signed int v1; // edi
  CPerInstanceContextData *v2; // esi
  CPerInstanceContextData *v3; // eax
  unsigned __int8 *m_pCommandBuffer; // eax

  if ( (CBaseShader::s_ppParams[2]->m_intVal & 0x40000) != 0 )
  {
    *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 3;
    s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  }
  if ( (CBaseShader::s_ppParams[2]->m_intVal & 2) != 0 )
  {
    *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 4;
    s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  }
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 0;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  v1 = s_InstanceCommandBuffer.m_Storage.m_pDataOut - (unsigned __int8 *)&s_InstanceCommandBuffer;
  s_bBuildingInstanceCommandBuffer = false;
  if ( s_InstanceCommandBuffer.m_Storage.m_pDataOut - (unsigned __int8 *)&s_InstanceCommandBuffer > 0 )
  {
    v2 = CBaseShader::s_pInstanceDataPtr[CBaseShader::s_nPassCount];
    if ( v2 == nullptr )
    {
      v3 = (CPerInstanceContextData *)operator new(nSize: 0xCu);
      if ( v3 != nullptr )
      {
        v3->m_pCommandBuffer = nullptr;
        v3->m_nSize = 0;
        v3->__vftable = (CPerInstanceContextData_vtbl *)&CPerInstanceContextData::`vftable';
        v2 = v3;
      }
      else
      {
        v2 = nullptr;
      }
      CBaseShader::s_pInstanceDataPtr[CBaseShader::s_nPassCount] = v2;
    }
    m_pCommandBuffer = v2->m_pCommandBuffer;
    if ( v2->m_nSize < v1 )
    {
      if ( m_pCommandBuffer != nullptr )
        free(pMem: v2->m_pCommandBuffer);
      m_pCommandBuffer = (unsigned __int8 *)operator new(nSize: v1);
      v2->m_pCommandBuffer = m_pCommandBuffer;
      v2->m_nSize = v1;
    }
    memcpy(dst: m_pCommandBuffer, src: s_InstanceCommandBuffer.m_Storage.m_Data, count: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003410
// Name: public: void CBaseShader::Draw(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::Draw(CBaseShader *this, BOOL bMakeActualDrawCall)
{
  int m_intVal; // eax
  unsigned __int8 *m_pCommandBuffer; // eax

  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    if ( g_pConfig->bNoTransparency && ((*CBaseShader::s_ppParams)->m_intVal & 2) == 0 )
    {
      ((void (__stdcall *)(int))CBaseShader::s_pShaderShadow->EnableDepthWrites)(a1: 1);
      CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: false);
    }
    g_pSLShaderSystem->TakeSnapshot(this: g_pSLShaderSystem);
    if ( CBaseShader::s_pInstanceDataPtr[CBaseShader::s_nPassCount] == nullptr )
    {
      m_intVal = CBaseShader::s_ppParams[2]->m_intVal;
      if ( (m_intVal & 0x40000) != 0 || (m_intVal & 2) != 0 )
      {
        s_bBuildingInstanceCommandBuffer = true;
        s_InstanceCommandBuffer.m_Storage.m_pDataOut = (unsigned __int8 *)&s_InstanceCommandBuffer;
        CBaseShader::PI_EndCommandBuffer(this);
      }
    }
    ++CBaseShader::s_nPassCount;
  }
  else
  {
    if ( CBaseShader::s_pInstanceDataPtr[CBaseShader::s_nPassCount] != nullptr )
      m_pCommandBuffer = CBaseShader::s_pInstanceDataPtr[CBaseShader::s_nPassCount]->m_pCommandBuffer;
    else
      m_pCommandBuffer = nullptr;
    g_pSLShaderSystem->DrawSnapshot(this: g_pSLShaderSystem, a2: m_pCommandBuffer, a3: bMakeActualDrawCall);
    ++CBaseShader::s_nPassCount;
  }
}

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x10049A80
// Name: public: virtual int CBaseShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseShader::GetParamCount(CBaseShader *this)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10049A90
// Name: public: virtual struct ShaderParamInfo_t const __near & CBaseShader::GetParamInfo(int)const
// Source: json
//------------------------------------------------------------------------------
const ShaderParamInfo_t *__thiscall CBaseShader::GetParamInfo(CBaseShader *this, int nParamIndex)
{
  return &s_StandardParams[nParamIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10049AB0
// Name: public: virtual void CBaseShader::InitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::InitShaderParams(CBaseShader *this, IMaterialVar **ppParams, const char *pMaterialName)
{
  CBaseShader::s_ppParams = ppParams;
  this->OnInitShaderParams(this, a2: ppParams, a3: pMaterialName);
  CBaseShader::s_ppParams = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10049AE0
// Name: public: virtual void CBaseShader::InitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::InitShaderInstance(
        CBaseShader *this,
        IMaterialVar **ppParams,
        IShaderInit *pShaderInit,
        const char *pMaterialName,
        const char *pTextureGroupName)
{
  CBaseShader::s_ppParams = ppParams;
  CBaseShader::s_pShaderInit = pShaderInit;
  CBaseShader::s_pTextureGroupName = pTextureGroupName;
  this->OnInitShaderInstance(this, a2: ppParams, a3: pShaderInit, a4: pMaterialName);
  CBaseShader::s_pTextureGroupName = nullptr;
  CBaseShader::s_ppParams = nullptr;
  CBaseShader::s_pShaderInit = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10049B30
// Name: public: void CBaseShader::SetInitialShadowState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::SetInitialShadowState(CBaseShader *this)
{
  int m_intVal; // esi

  CBaseShader::s_pShaderShadow->SetDefaultState(this: CBaseShader::s_pShaderShadow);
  m_intVal = (*CBaseShader::s_ppParams)->m_intVal;
  if ( (m_intVal & 0x8000) != 0 )
  {
    CBaseShader::s_pShaderShadow->EnableDepthTest(this: CBaseShader::s_pShaderShadow, a2: false);
    CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: false);
  }
  if ( (m_intVal & 0x10000) != 0 )
  {
    CBaseShader::s_pShaderShadow->EnablePolyOffset(this: CBaseShader::s_pShaderShadow, a2: SHADER_POLYOFFSET_DECAL);
    CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: false);
  }
  if ( (m_intVal & 0x2000) != 0 )
    CBaseShader::s_pShaderShadow->EnableCulling(this: CBaseShader::s_pShaderShadow, a2: false);
  if ( (m_intVal & 0x400) != 0 )
    CBaseShader::s_pShaderShadow->DepthFunc(this: CBaseShader::s_pShaderShadow, a2: SHADER_DEPTHFUNC_NEARER);
  if ( (m_intVal & 0x10000000) != 0 )
    CBaseShader::s_pShaderShadow->PolyMode(
      this: CBaseShader::s_pShaderShadow,
      a2: SHADER_POLYMODEFACE_FRONT_AND_BACK,
      a3: SHADER_POLYMODE_LINE);
  if ( (m_intVal & 0x20000000) != 0 )
    CBaseShader::s_pShaderShadow->EnableAlphaToCoverage(this: CBaseShader::s_pShaderShadow, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10049C00
// Name: public: bool CBaseShader::IsUsingGraphics(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseShader::IsUsingGraphics(CBaseShader *this)
{
  return g_pSLShaderSystem->IsUsingGraphics(this: g_pSLShaderSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10049C10
// Name: public: bool CBaseShader::CanUseEditorMaterials(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseShader::CanUseEditorMaterials(CBaseShader *this)
{
  return g_pSLShaderSystem->CanUseEditorMaterials(this: g_pSLShaderSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10049C20
// Name: public: void CBaseShader::LoadTexture(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::LoadTexture(CBaseShader *this, int nTextureVar, int nAdditionalCreationFlags)
{
  IMaterialVar *v3; // esi

  if ( CBaseShader::s_ppParams != nullptr && nTextureVar != -1 )
  {
    v3 = CBaseShader::s_ppParams[nTextureVar];
    if ( v3 != nullptr && v3->IsDefined(this: v3) )
      CBaseShader::s_pShaderInit->LoadTexture(
        this: CBaseShader::s_pShaderInit,
        a2: v3,
        a3: CBaseShader::s_pTextureGroupName,
        a4: nAdditionalCreationFlags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049C70
// Name: public: void CBaseShader::LoadBumpMap(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::LoadBumpMap(CBaseShader *this, int nTextureVar, int nAdditionalCreationFlags)
{
  IMaterialVar *v3; // esi

  if ( CBaseShader::s_ppParams != nullptr && nTextureVar != -1 )
  {
    v3 = CBaseShader::s_ppParams[nTextureVar];
    if ( v3 != nullptr && v3->IsDefined(this: v3) )
      CBaseShader::s_pShaderInit->LoadBumpMap(
        this: CBaseShader::s_pShaderInit,
        a2: v3,
        a3: CBaseShader::s_pTextureGroupName,
        a4: nAdditionalCreationFlags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049CC0
// Name: public: void CBaseShader::LoadCubeMap(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::LoadCubeMap(CBaseShader *this, int nTextureVar, int nAdditionalCreationFlags)
{
  IMaterialVar *v3; // esi

  if ( CBaseShader::s_ppParams != nullptr && nTextureVar != -1 )
  {
    v3 = CBaseShader::s_ppParams[nTextureVar];
    if ( v3 != nullptr && v3->IsDefined(this: v3) )
      CBaseShader::s_pShaderInit->LoadCubeMap(
        this: CBaseShader::s_pShaderInit,
        a2: CBaseShader::s_ppParams,
        a3: v3,
        a4: nAdditionalCreationFlags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049D10
// Name: public: int CBaseShader::GetShaderAPITextureBindHandle(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseShader::GetShaderAPITextureBindHandle(
        CBaseShader *this,
        int nTextureVar,
        int nFrameVar,
        int nTextureChannel)
{
  IMaterialVar *v4; // eax
  int m_intVal; // eax
  IShaderSystem *v6; // esi
  IShaderSystem_vtbl *v7; // edi
  int v8; // eax

  if ( nFrameVar == -1 || (v4 = CBaseShader::s_ppParams[nFrameVar]) == nullptr )
    m_intVal = 0;
  else
    m_intVal = v4->m_intVal;
  v6 = g_pSLShaderSystem;
  v7 = g_pSLShaderSystem->__vftable;
  v8 = ((int (__thiscall *)(IMaterialVar *, int, int))CBaseShader::s_ppParams[nTextureVar]->GetTextureValue)(
         a1: CBaseShader::s_ppParams[nTextureVar],
         a2: m_intVal,
         a3: nTextureChannel);
  return ((int (__thiscall *)(IShaderSystem *, int))v7->GetShaderAPITextureBindHandle)(a1: v6, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10049D60
// Name: public: void CBaseShader::BindVertexTexture(enum VertexTextureSampler_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::BindVertexTexture(
        CBaseShader *this,
        VertexTextureSampler_t vtSampler,
        int nTextureVar,
        int nFrame)
{
  IMaterialVar *v4; // ecx
  IShaderSystem *v5; // esi
  IShaderSystem_vtbl *v6; // edi
  int v7; // eax

  v4 = CBaseShader::s_ppParams[nTextureVar];
  if ( v4 != nullptr )
  {
    v5 = g_pSLShaderSystem;
    v6 = g_pSLShaderSystem->__vftable;
    v7 = ((int (__thiscall *)(IMaterialVar *, _DWORD))v4->GetTextureValue)(a1: v4, a2: 0);
    ((void (__thiscall *)(IShaderSystem *, VertexTextureSampler_t, int))v6->BindVertexTexture)(
      a1: v5,
      a2: vtSampler,
      a3: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049DA0
// Name: public: int CBaseShader::GetShaderAPITextureBindHandle(class ITexture __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseShader::GetShaderAPITextureBindHandle(
        CBaseShader *this,
        ITexture *pTexture,
        int nFrame,
        int nTextureChannel)
{
  return g_pSLShaderSystem->GetShaderAPITextureBindHandle(
           this: g_pSLShaderSystem,
           a2: pTexture,
           a3: nFrame,
           a4: nTextureChannel);
}

//------------------------------------------------------------------------------
// Address: 0x10049DB0
// Name: public: bool CBaseShader::TextureIsTranslucent(int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseShader::TextureIsTranslucent(CBaseShader *this, int textureVar, bool isBaseTexture)
{
  IMaterialVar *v4; // ecx
  int v5; // eax
  int m_intVal; // ecx
  int v7; // eax

  if ( textureVar < 0 )
    return false;
  v4 = CBaseShader::s_ppParams[textureVar];
  if ( (*((_BYTE *)v4 + 28) & 0xF) != 3 )
    return false;
  if ( !isBaseTexture )
  {
    v5 = v4->GetTextureValue(this: v4);
    return (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 24))(a1: v5);
  }
  if ( ((*CBaseShader::s_ppParams)->m_intVal & 0x1000000) != 0 )
    return false;
  m_intVal = (*CBaseShader::s_ppParams)->m_intVal;
  if ( (m_intVal & 0x40) != 0 && (CBaseShader::s_ppParams[2]->m_intVal & 0x400000) == 0 )
    return false;
  if ( (m_intVal & 0x100000) != 0 || (m_intVal & 0x200100) == 0 )
    return false;
  v7 = CBaseShader::s_ppParams[textureVar]->GetTextureValue(this: CBaseShader::s_ppParams[textureVar]);
  return (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 24))(a1: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10049E50
// Name: public: bool CBaseShader::IsAlphaModulating(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseShader::IsAlphaModulating(CBaseShader *this)
{
  return CBaseShader::s_nModulationFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10049E60
// Name: public: virtual bool CBaseShader::NeedsPowerOfTwoFrameBufferTexture(class IMaterialVar __near * __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseShader::NeedsPowerOfTwoFrameBufferTexture(
        CBaseShader *this,
        IMaterialVar **params,
        bool bCheckSpecificToThisFrame)
{
  return (params[2]->m_intVal & 0x4000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049E80
// Name: public: virtual bool CBaseShader::NeedsFullFrameBufferTexture(class IMaterialVar __near * __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseShader::NeedsFullFrameBufferTexture(
        CBaseShader *this,
        IMaterialVar **params,
        bool bCheckSpecificToThisFrame)
{
  return (params[2]->m_intVal & 0x8000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049EA0
// Name: public: virtual bool CBaseShader::IsTranslucent(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseShader::IsTranslucent(CBaseShader *this, IMaterialVar **params)
{
  return ((*params)->m_intVal & 0x200000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049EC0
// Name: public: void CBaseShader::ApplyColor2Factor(float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::ApplyColor2Factor(CBaseShader *this, float *pColorOut)
{
  IMaterialVar *v2; // eax
  float v3; // xmm0_4
  float v4; // xmm1_4
  IMaterialVar *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( g_pConfig->bShowDiffuse )
  {
    v2 = CBaseShader::s_ppParams[11];
    if ( (*((_BYTE *)v2 + 28) & 0xF) == 2 )
    {
      v3 = v2->m_VecVal.z * pColorOut[2];
      v4 = pColorOut[1] * v2->m_VecVal.y;
      *pColorOut = *pColorOut * v2->m_VecVal.x;
      pColorOut[1] = v4;
      pColorOut[2] = v3;
    }
    if ( g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig) )
    {
      v5 = CBaseShader::s_ppParams[12];
      if ( (*((_BYTE *)v5 + 28) & 0xF) == 2 )
      {
        v6 = v5->m_VecVal.z * pColorOut[2];
        v7 = pColorOut[1] * v5->m_VecVal.y;
        *pColorOut = *pColorOut * v5->m_VecVal.x;
        pColorOut[1] = v7;
        pColorOut[2] = v6;
      }
    }
  }
  else
  {
    *(_QWORD *)(pColorOut + 1) = 0;
    *pColorOut = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049F90
// Name: public: void CBaseShader::EnableAlphaBlending(enum ShaderBlendFactor_t,enum ShaderBlendFactor_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::EnableAlphaBlending(CBaseShader *this, ShaderBlendFactor_t src, ShaderBlendFactor_t dst)
{
  CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: true);
  CBaseShader::s_pShaderShadow->BlendFunc(this: CBaseShader::s_pShaderShadow, a2: src, a3: dst);
  CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10049FD0
// Name: public: void CBaseShader::DisableAlphaBlending(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::DisableAlphaBlending(CBaseShader *this)
{
  CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10049FE0
// Name: public: void CBaseShader::SetNormalBlendingShadowState(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::SetNormalBlendingShadowState(CBaseShader *this, int textureVar, bool isBaseTexture)
{
  if ( (CBaseShader::s_nModulationFlags & 1) != 0
    || ((*CBaseShader::s_ppParams)->m_intVal & 0x20) != 0
    || CBaseShader::TextureIsTranslucent(this, textureVar, isBaseTexture)
    && ((*CBaseShader::s_ppParams)->m_intVal & 0x100) == 0 )
  {
    CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: true);
    CBaseShader::s_pShaderShadow->BlendFunc(
      this: CBaseShader::s_pShaderShadow,
      a2: SHADER_BLEND_SRC_ALPHA,
      a3: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: false);
  }
  else
  {
    CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A060
// Name: public: void CBaseShader::SetAdditiveBlendingShadowState(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::SetAdditiveBlendingShadowState(CBaseShader *this, int textureVar, bool isBaseTexture)
{
  int savedregs; // [esp+0h] [ebp+0h]
  int savedregsa; // [esp+0h] [ebp+0h]

  if ( (CBaseShader::s_nModulationFlags & 1) != 0
    || ((*CBaseShader::s_ppParams)->m_intVal & 0x20) != 0
    || CBaseShader::TextureIsTranslucent(this, textureVar, isBaseTexture)
    && ((*CBaseShader::s_ppParams)->m_intVal & 0x100) == 0 )
  {
    CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: true);
    savedregs = 1;
    ((void (__thiscall *)(IShaderShadow *, int))CBaseShader::s_pShaderShadow->BlendFunc)(
      a1: CBaseShader::s_pShaderShadow,
      a2: 4);
  }
  else
  {
    CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: true);
    savedregsa = 1;
    ((void (__thiscall *)(IShaderShadow *, int))CBaseShader::s_pShaderShadow->BlendFunc)(
      a1: CBaseShader::s_pShaderShadow,
      a2: 1);
  }
  CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1004A0F0
// Name: public: void CBaseShader::SetDefaultBlendingShadowState(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::SetDefaultBlendingShadowState(CBaseShader *this, int textureVar, bool isBaseTexture)
{
  if ( SLOBYTE((*CBaseShader::s_ppParams)->m_intVal) >= 0 )
    CBaseShader::SetNormalBlendingShadowState(this, textureVar, isBaseTexture);
  else
    CBaseShader::SetAdditiveBlendingShadowState(this, textureVar, isBaseTexture);
}

//------------------------------------------------------------------------------
// Address: 0x1004A110
// Name: public: void CBaseShader::SetBlendingShadowState(enum BlendType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::SetBlendingShadowState(CBaseShader *this, BlendType_t nMode)
{
  switch ( nMode )
  {
    case BT_NONE:
      CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: false);
      break;
    case BT_BLEND:
      CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
      break;
    case BT_ADD:
      CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
      break;
    case BT_BLENDADD:
      CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A170
// Name: public: void CBaseShader::FogToOOOverbright(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::FogToOOOverbright(CBaseShader *this)
{
  int m_intVal; // eax

  m_intVal = (*CBaseShader::s_ppParams)->m_intVal;
  if ( (m_intVal & 0x4000) != 0 )
    CBaseShader::s_pShaderShadow->FogMode(this: CBaseShader::s_pShaderShadow, a2: SHADER_FOGMODE_DISABLED, a3: false);
  else
    CBaseShader::s_pShaderShadow->FogMode(
      this: CBaseShader::s_pShaderShadow,
      a2: SHADER_FOGMODE_OO_OVERBRIGHT,
      a3: m_intVal < 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004A1B0
// Name: public: void CBaseShader::FogToWhite(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::FogToWhite(CBaseShader *this)
{
  int m_intVal; // eax

  m_intVal = (*CBaseShader::s_ppParams)->m_intVal;
  if ( (m_intVal & 0x4000) != 0 )
    CBaseShader::s_pShaderShadow->FogMode(this: CBaseShader::s_pShaderShadow, a2: SHADER_FOGMODE_DISABLED, a3: false);
  else
    CBaseShader::s_pShaderShadow->FogMode(
      this: CBaseShader::s_pShaderShadow,
      a2: SHADER_FOGMODE_WHITE,
      a3: m_intVal < 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004A1F0
// Name: public: void CBaseShader::FogToBlack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::FogToBlack(CBaseShader *this)
{
  int m_intVal; // eax

  m_intVal = (*CBaseShader::s_ppParams)->m_intVal;
  if ( (m_intVal & 0x4000) != 0 )
    CBaseShader::s_pShaderShadow->FogMode(this: CBaseShader::s_pShaderShadow, a2: SHADER_FOGMODE_DISABLED, a3: false);
  else
    CBaseShader::s_pShaderShadow->FogMode(
      this: CBaseShader::s_pShaderShadow,
      a2: SHADER_FOGMODE_BLACK,
      a3: m_intVal < 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004A230
// Name: public: void CBaseShader::FogToGrey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::FogToGrey(CBaseShader *this)
{
  int m_intVal; // eax

  m_intVal = (*CBaseShader::s_ppParams)->m_intVal;
  if ( (m_intVal & 0x4000) != 0 )
    CBaseShader::s_pShaderShadow->FogMode(this: CBaseShader::s_pShaderShadow, a2: SHADER_FOGMODE_DISABLED, a3: false);
  else
    CBaseShader::s_pShaderShadow->FogMode(this: CBaseShader::s_pShaderShadow, a2: SHADER_FOGMODE_GREY, a3: m_intVal < 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004A270
// Name: public: void CBaseShader::FogToFogColor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::FogToFogColor(CBaseShader *this)
{
  int m_intVal; // eax

  m_intVal = (*CBaseShader::s_ppParams)->m_intVal;
  if ( (m_intVal & 0x4000) != 0 )
    CBaseShader::s_pShaderShadow->FogMode(this: CBaseShader::s_pShaderShadow, a2: SHADER_FOGMODE_DISABLED, a3: false);
  else
    CBaseShader::s_pShaderShadow->FogMode(
      this: CBaseShader::s_pShaderShadow,
      a2: SHADER_FOGMODE_FOGCOLOR,
      a3: m_intVal < 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004A2B0
// Name: public: void CBaseShader::DefaultFog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::DefaultFog(CBaseShader *this)
{
  int m_intVal; // eax

  m_intVal = (*CBaseShader::s_ppParams)->m_intVal;
  if ( (m_intVal & 0x80u) == 0 )
  {
    if ( (m_intVal & 0x4000) == 0 )
    {
      ((void (__stdcall *)(int, bool))CBaseShader::s_pShaderShadow->FogMode)(a1: 4, a2: m_intVal < 0);
      return;
    }
  }
  else if ( (m_intVal & 0x4000) == 0 )
  {
    ((void (__stdcall *)(int, bool))CBaseShader::s_pShaderShadow->FogMode)(a1: 2, a2: m_intVal < 0);
    return;
  }
  ((void (__stdcall *)(_DWORD, _DWORD))CBaseShader::s_pShaderShadow->FogMode)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004A310
// Name: public: bool CBaseShader::UsingFlashlight(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseShader::UsingFlashlight(CBaseShader *this, IMaterialVar **params)
{
  if ( CBaseShader::s_pShaderShadow != nullptr )
    return (params[2]->m_intVal & 0x400) != 0;
  else
    return CBaseShader::s_pShaderAPI->InFlashlightMode(this: CBaseShader::s_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x1004A340
// Name: public: bool CBaseShader::UsingEditor(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseShader::UsingEditor(CBaseShader *this, IMaterialVar **params)
{
  if ( CBaseShader::s_pShaderShadow != nullptr )
    return (params[2]->m_intVal & 0x2000) != 0;
  else
    return CBaseShader::s_pShaderAPI->InEditorMode(this: CBaseShader::s_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x1004A370
// Name: public: bool CBaseShader::IsRenderingPaint(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseShader::IsRenderingPaint(CBaseShader *this, IMaterialVar **params)
{
  if ( CBaseShader::s_pShaderShadow != nullptr )
    return (params[2]->m_intVal & 0x800) != 0;
  if ( g_pConfig->m_bPaintInGame && g_pConfig->m_bPaintInMap )
    return CBaseShader::s_pShaderAPI->IsRenderingPaint(this: CBaseShader::s_pShaderAPI);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1004A3C0
// Name: public: bool CBaseShader::IsHDREnabled(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseShader::IsHDREnabled(CBaseShader *this)
{
  HDRType_t v1; // eax

  v1 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
  return v1 == HDR_TYPE_INTEGER || v1 == HDR_TYPE_FLOAT;
}

//------------------------------------------------------------------------------
// Address: 0x1004A430
// Name: public: CBaseShader::CBaseShader(void)
// Source: json
//------------------------------------------------------------------------------
CBaseShader *__thiscall CBaseShader::CBaseShader(CBaseShader *this)
{
  IShaderDLL *ShaderDLL; // eax

  this->__vftable = (CBaseShader_vtbl *)&CBaseShader::`vftable';
  ShaderDLL = GetShaderDLL();
  ShaderDLL->InsertShader(this: ShaderDLL, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004A450
// Name: public: virtual void CBaseShader::DrawElements(class IMaterialVar __near * __near *,int,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *,class CBasePerInstanceContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::DrawElements(
        CBaseShader *this,
        IMaterialVar **ppParams,
        int nModulationFlags,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr,
        CBasePerInstanceContextData **pInstanceDataPtr)
{
  CBaseShader::s_ppParams = ppParams;
  CBaseShader::s_pShaderAPI = pShaderAPI;
  CBaseShader::s_pShaderShadow = pShaderShadow;
  CBaseShader::s_nModulationFlags = nModulationFlags;
  CBaseShader::s_pInstanceDataPtr = (CPerInstanceContextData **)pInstanceDataPtr;
  CBaseShader::s_nPassCount = 0;
  if ( pShaderShadow != nullptr )
    CBaseShader::SetInitialShadowState(this);
  this->OnDrawElements(
    this,
    a2: ppParams,
    a3: pShaderShadow,
    a4: pShaderAPI,
    a5: vertexCompression,
    a6: pContextDataPtr);
  CBaseShader::s_pInstanceDataPtr = nullptr;
  CBaseShader::s_nPassCount = 0;
  CBaseShader::s_nModulationFlags = 0;
  CBaseShader::s_ppParams = nullptr;
  CBaseShader::s_pShaderAPI = nullptr;
  CBaseShader::s_pShaderShadow = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1004A4E0
// Name: public: void CBaseShader::BindTexture(enum Sampler_t,enum TextureBindFlags_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::BindTexture(
        CBaseShader *this,
        Sampler_t sampler1,
        TextureBindFlags_t nBindFlags,
        int nTextureVar,
        int nFrameVar)
{
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // eax
  int m_intVal; // eax
  IShaderSystem *v8; // esi
  IShaderSystem_vtbl *v9; // edi
  int v10; // eax

  v5 = CBaseShader::s_ppParams[nTextureVar];
  if ( nFrameVar == -1 )
    v6 = nullptr;
  else
    v6 = CBaseShader::s_ppParams[nFrameVar];
  if ( v5 != nullptr )
  {
    if ( v6 != nullptr )
      m_intVal = v6->m_intVal;
    else
      m_intVal = 0;
    v8 = g_pSLShaderSystem;
    v9 = g_pSLShaderSystem->__vftable;
    v10 = ((int (__thiscall *)(IMaterialVar *, int))v5->GetTextureValue)(a1: v5, a2: m_intVal);
    ((void (__thiscall *)(IShaderSystem *, Sampler_t, TextureBindFlags_t, int))v9->BindTexture_2)(
      a1: v8,
      a2: sampler1,
      a3: nBindFlags,
      a4: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A540
// Name: public: void CBaseShader::BindTexture(enum Sampler_t,enum TextureBindFlags_t,class ITexture __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::BindTexture(
        CBaseShader *this,
        Sampler_t sampler1,
        TextureBindFlags_t nBindFlags,
        ITexture *pTexture,
        int nFrame)
{
  g_pSLShaderSystem->BindTexture_2(this: g_pSLShaderSystem, a2: sampler1, a3: nBindFlags, a4: pTexture, a5: nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x1004A560
// Name: public: virtual int CBaseShader::ComputeModulationFlags(class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseShader::ComputeModulationFlags(
        CBaseShader *this,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI)
{
  int v3; // edi
  IShaderDynamicAPI *v4; // ecx
  bool v5; // al
  bool v6; // al
  bool v7; // al
  IMaterialVar *v8; // ecx
  bool v9; // zf
  char v10; // al

  v3 = 0;
  v4 = pShaderAPI;
  CBaseShader::s_pShaderAPI = pShaderAPI;
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    v5 = (params[2]->m_intVal & 0x400) != 0;
  }
  else
  {
    v5 = pShaderAPI->InFlashlightMode(this: pShaderAPI);
    v4 = CBaseShader::s_pShaderAPI;
  }
  if ( v5 )
    v3 = 2;
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    v6 = (params[2]->m_intVal & 0x2000) != 0;
  }
  else
  {
    v6 = v4->InEditorMode(this: v4);
    v4 = CBaseShader::s_pShaderAPI;
  }
  if ( v6 )
    v3 |= 8u;
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    v7 = (params[2]->m_intVal & 0x800) != 0;
  }
  else
  {
    if ( !g_pConfig->m_bPaintInGame || !g_pConfig->m_bPaintInMap )
      goto LABEL_22;
    v7 = v4->IsRenderingPaint(this: v4);
  }
  if ( v7 )
    v3 |= 4u;
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    v8 = params[2];
    if ( (v8->m_intVal & 0x100000) != 0 )
      v3 |= 0x10u;
    v9 = (v8->m_intVal & 0x200000) == 0;
    goto LABEL_25;
  }
LABEL_22:
  v10 = pShaderAPI->GetIntRenderingParameter(this: pShaderAPI, a2: 0);
  if ( (v10 & 1) != 0 )
    v3 |= 0x10u;
  v9 = (v10 & 2) == 0;
LABEL_25:
  CBaseShader::s_pShaderAPI = nullptr;
  if ( !v9 )
    return v3 | 0x20;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1004A660
// Name: public: void CBaseShader::PI_BeginCommandBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_BeginCommandBuffer(CBaseShader *this)
{
  s_bBuildingInstanceCommandBuffer = true;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut = (unsigned __int8 *)&s_InstanceCommandBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x1004A680
// Name: public: void CBaseShader::PI_SetPixelShaderAmbientLightCube(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetPixelShaderAmbientLightCube(CBaseShader *this, int nFirstRegister)
{
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 7;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = nFirstRegister;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004A6B0
// Name: public: void CBaseShader::PI_SetPixelShaderLocalLighting(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetPixelShaderLocalLighting(CBaseShader *this, int nFirstRegister)
{
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 5;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = nFirstRegister;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004A6E0
// Name: public: void CBaseShader::PI_SetVertexShaderAmbientLightCube(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetVertexShaderAmbientLightCube(CBaseShader *this)
{
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 6;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004A700
// Name: public: void CBaseShader::PI_SetPixelShaderAmbientLightCubeLuminance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetPixelShaderAmbientLightCubeLuminance(CBaseShader *this, int nFirstRegister)
{
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 8;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = nFirstRegister;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004A730
// Name: public: void CBaseShader::PI_SetPixelShaderGlintDamping(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetPixelShaderGlintDamping(CBaseShader *this, int nFirstRegister)
{
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 9;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = nFirstRegister;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004A760
// Name: public: void CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearColorSpace_LinearScale(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearColorSpace_LinearScale(
        CBaseShader *this,
        int nRegister,
        float scale)
{
  float x; // xmm0_4
  unsigned __int8 *v4; // eax
  Vector color2; // [esp+0h] [ebp-Ch] BYREF

  color2.x = 1.0;
  color2.y = 1.0;
  color2.z = 1.0;
  CBaseShader::ApplyColor2Factor(this, pColorOut: &color2.x);
  x = color2.x;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 12;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = nRegister;
  v4 = s_InstanceCommandBuffer.m_Storage.m_pDataOut + 4;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut = v4;
  *(float *)v4 = x;
  *((_DWORD *)v4 + 1) = LODWORD(color2.y);
  *((_DWORD *)v4 + 2) = LODWORD(color2.z);
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 12;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 1065353216;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(float *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = scale;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004A810
// Name: public: void CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearScale(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearScale(
        CBaseShader *this,
        int nRegister,
        float scale)
{
  float x; // xmm0_4
  unsigned __int8 *v4; // eax
  Vector color2; // [esp+0h] [ebp-Ch] BYREF

  color2.x = 1.0;
  color2.y = 1.0;
  color2.z = 1.0;
  CBaseShader::ApplyColor2Factor(this, pColorOut: &color2.x);
  x = color2.x;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 14;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = nRegister;
  v4 = s_InstanceCommandBuffer.m_Storage.m_pDataOut + 4;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut = v4;
  *(float *)v4 = x;
  *((_DWORD *)v4 + 1) = LODWORD(color2.y);
  *((_DWORD *)v4 + 2) = LODWORD(color2.z);
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 12;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 1065353216;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(float *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = scale;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004A8C0
// Name: public: void CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearScale_ScaleInW(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearScale_ScaleInW(
        CBaseShader *this,
        int nRegister,
        float scale)
{
  float x; // xmm0_4
  unsigned __int8 *v4; // eax
  Vector color2; // [esp+0h] [ebp-Ch] BYREF

  color2.x = 1.0;
  color2.y = 1.0;
  color2.z = 1.0;
  CBaseShader::ApplyColor2Factor(this, pColorOut: &color2.x);
  x = color2.x;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 15;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = nRegister;
  v4 = s_InstanceCommandBuffer.m_Storage.m_pDataOut + 4;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut = v4;
  *(float *)v4 = x;
  *((_DWORD *)v4 + 1) = LODWORD(color2.y);
  *((_DWORD *)v4 + 2) = LODWORD(color2.z);
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 12;
  *(float *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = scale;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004A960
// Name: public: void CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearColorSpace(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearColorSpace(CBaseShader *this, int nRegister)
{
  float x; // xmm0_4
  unsigned __int8 *v3; // eax
  Vector color2; // [esp+0h] [ebp-Ch] BYREF

  color2.x = 1.0;
  color2.y = 1.0;
  color2.z = 1.0;
  CBaseShader::ApplyColor2Factor(this, pColorOut: &color2.x);
  x = color2.x;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 13;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = nRegister;
  v3 = s_InstanceCommandBuffer.m_Storage.m_pDataOut + 4;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut = v3;
  *(float *)v3 = x;
  *((_DWORD *)v3 + 1) = LODWORD(color2.y);
  *((_DWORD *)v3 + 2) = LODWORD(color2.z);
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 12;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 1065353216;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004AA00
// Name: public: void CBaseShader::PI_SetModulationPixelShaderDynamicState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetModulationPixelShaderDynamicState(CBaseShader *this, int nRegister)
{
  float x; // xmm0_4
  unsigned __int8 *v3; // eax
  Vector color2; // [esp+0h] [ebp-Ch] BYREF

  color2.x = 1.0;
  color2.y = 1.0;
  color2.z = 1.0;
  CBaseShader::ApplyColor2Factor(this, pColorOut: &color2.x);
  x = color2.x;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 11;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = nRegister;
  v3 = s_InstanceCommandBuffer.m_Storage.m_pDataOut + 4;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut = v3;
  *(float *)v3 = x;
  *((_DWORD *)v3 + 1) = LODWORD(color2.y);
  *((_DWORD *)v3 + 2) = LODWORD(color2.z);
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 12;
}

//------------------------------------------------------------------------------
// Address: 0x1004AA80
// Name: public: void CBaseShader::PI_SetModulationVertexShaderDynamicState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetModulationVertexShaderDynamicState(CBaseShader *this)
{
  float x; // xmm0_4
  unsigned __int8 *v2; // eax
  Vector color2; // [esp+0h] [ebp-Ch] BYREF

  color2.x = 1.0;
  color2.y = 1.0;
  color2.z = 1.0;
  CBaseShader::ApplyColor2Factor(this, pColorOut: &color2.x);
  x = color2.x;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 16;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 47;
  v2 = s_InstanceCommandBuffer.m_Storage.m_pDataOut + 4;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut = v2;
  *(float *)v2 = x;
  *((_DWORD *)v2 + 1) = LODWORD(color2.y);
  *((_DWORD *)v2 + 2) = LODWORD(color2.z);
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 12;
}

//------------------------------------------------------------------------------
// Address: 0x1004AB00
// Name: public: void CBaseShader::PI_SetModulationVertexShaderDynamicState_LinearScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetModulationVertexShaderDynamicState_LinearScale(CBaseShader *this, float flScale)
{
  float x; // xmm0_4
  unsigned __int8 *v3; // eax
  Vector color2; // [esp+0h] [ebp-Ch] BYREF

  color2.x = 1.0;
  color2.y = 1.0;
  color2.z = 1.0;
  CBaseShader::ApplyColor2Factor(this, pColorOut: &color2.x);
  x = color2.x;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 18;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 47;
  v3 = s_InstanceCommandBuffer.m_Storage.m_pDataOut + 4;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut = v3;
  *(float *)v3 = x;
  *((_DWORD *)v3 + 1) = LODWORD(color2.y);
  *((_DWORD *)v3 + 2) = LODWORD(color2.z);
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 12;
  *(float *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = flScale;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004ABA0
// Name: public: void CBaseShader::PI_SetModulationPixelShaderDynamicState_Identity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_SetModulationPixelShaderDynamicState_Identity(CBaseShader *this, int nRegister)
{
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 17;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = nRegister;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
}

//------------------------------------------------------------------------------
// Address: 0x1004ABD0
// Name: public: void CBaseShader::PI_EndCommandBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::PI_EndCommandBuffer(CBaseShader *this)
{
  signed int v1; // edi
  CPerInstanceContextData *v2; // esi
  CPerInstanceContextData *v3; // eax
  unsigned __int8 *m_pCommandBuffer; // eax

  if ( (CBaseShader::s_ppParams[2]->m_intVal & 0x40000) != 0 )
  {
    *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 3;
    s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  }
  if ( (CBaseShader::s_ppParams[2]->m_intVal & 2) != 0 )
  {
    *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 4;
    s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  }
  *(_DWORD *)s_InstanceCommandBuffer.m_Storage.m_pDataOut = 0;
  s_InstanceCommandBuffer.m_Storage.m_pDataOut += 4;
  v1 = s_InstanceCommandBuffer.m_Storage.m_pDataOut - (unsigned __int8 *)&s_InstanceCommandBuffer;
  s_bBuildingInstanceCommandBuffer = false;
  if ( s_InstanceCommandBuffer.m_Storage.m_pDataOut - (unsigned __int8 *)&s_InstanceCommandBuffer > 0 )
  {
    v2 = CBaseShader::s_pInstanceDataPtr[CBaseShader::s_nPassCount];
    if ( v2 == nullptr )
    {
      v3 = (CPerInstanceContextData *)operator new(nSize: 0xCu);
      if ( v3 != nullptr )
      {
        v3->m_pCommandBuffer = nullptr;
        v3->m_nSize = 0;
        v3->__vftable = (CPerInstanceContextData_vtbl *)&CPerInstanceContextData::`vftable';
        v2 = v3;
      }
      else
      {
        v2 = nullptr;
      }
      CBaseShader::s_pInstanceDataPtr[CBaseShader::s_nPassCount] = v2;
    }
    m_pCommandBuffer = v2->m_pCommandBuffer;
    if ( v2->m_nSize < v1 )
    {
      if ( m_pCommandBuffer != nullptr )
        free(pMem: v2->m_pCommandBuffer);
      m_pCommandBuffer = (unsigned __int8 *)operator new(nSize: v1);
      v2->m_pCommandBuffer = m_pCommandBuffer;
      v2->m_nSize = v1;
    }
    memcpy(dst: m_pCommandBuffer, src: s_InstanceCommandBuffer.m_Storage.m_Data, count: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004ACC0
// Name: public: void CBaseShader::Draw(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::Draw(CBaseShader *this, BOOL bMakeActualDrawCall)
{
  int m_intVal; // eax
  unsigned __int8 *m_pCommandBuffer; // eax

  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    if ( g_pConfig->bNoTransparency && ((*CBaseShader::s_ppParams)->m_intVal & 2) == 0 )
    {
      ((void (__stdcall *)(int))CBaseShader::s_pShaderShadow->EnableDepthWrites)(a1: 1);
      CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: false);
    }
    g_pSLShaderSystem->TakeSnapshot(this: g_pSLShaderSystem);
    if ( CBaseShader::s_pInstanceDataPtr[CBaseShader::s_nPassCount] == nullptr )
    {
      m_intVal = CBaseShader::s_ppParams[2]->m_intVal;
      if ( (m_intVal & 0x40000) != 0 || (m_intVal & 2) != 0 )
      {
        s_bBuildingInstanceCommandBuffer = true;
        s_InstanceCommandBuffer.m_Storage.m_pDataOut = (unsigned __int8 *)&s_InstanceCommandBuffer;
        CBaseShader::PI_EndCommandBuffer(this);
      }
    }
    ++CBaseShader::s_nPassCount;
  }
  else
  {
    if ( CBaseShader::s_pInstanceDataPtr[CBaseShader::s_nPassCount] != nullptr )
      m_pCommandBuffer = CBaseShader::s_pInstanceDataPtr[CBaseShader::s_nPassCount]->m_pCommandBuffer;
    else
      m_pCommandBuffer = nullptr;
    g_pSLShaderSystem->DrawSnapshot(this: g_pSLShaderSystem, a2: m_pCommandBuffer, a3: bMakeActualDrawCall);
    ++CBaseShader::s_nPassCount;
  }
}

} // namespace stdshader_dx9
