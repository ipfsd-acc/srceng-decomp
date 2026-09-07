// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/shadershadowdx10.cpp
// Functions: 4
// ============================================================

#include "materialsystem\shaderapidx9\shadershadowdx10.h"

//------------------------------------------------------------------------------
// Address: 0x10015760
// Name: public: virtual void CShaderShadowDx10::EnableAlphaTest(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDx10::EnableAlphaTest(CShaderAPIDx8 *this, bool bEnable)
{
  BYTE1(this->m_nAdapter) = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1002F2F0
// Name: public: virtual void CShaderShadowDx10::SetDefaultState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDx10::SetDefaultState(CShaderShadowDx10 *this)
{
  this->m_IsTranslucent = false;
  this->m_IsAlphaTested = false;
  this->m_bIsDepthWriteEnabled = true;
  this->m_bUsesVertexAndPixelShaders = false;
}

//------------------------------------------------------------------------------
// Address: 0x1002F310
// Name: public: virtual void CShaderShadowDx10::EnableBlending(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDx10::EnableBlending(CShaderShadowDx10 *this, bool bEnable)
{
  this->m_IsTranslucent = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1002F320
// Name: public: virtual void CShaderShadowDx10::SetPixelShader(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDx10::SetPixelShader(CShaderShadowDx10 *this, const char *pShaderName, int pshIndex)
{
  this->m_bUsesVertexAndPixelShaders = pShaderName != nullptr;
}
