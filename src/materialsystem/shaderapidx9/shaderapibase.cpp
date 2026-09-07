// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/shaderapibase.cpp
// Functions: 3
// ============================================================

#include "materialsystem\shaderapidx9\shaderapibase.h"

//------------------------------------------------------------------------------
// Address: 0x1000D830
// Name: public: virtual CShaderAPIBase::~CShaderAPIBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIBase::~CShaderAPIBase(CShaderAPIBase *this)
{
  this->__vftable = (CShaderAPIBase_vtbl *)&CShaderAPIBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1000D840
// Name: public: virtual void CShaderAPIBase::GetCurrentColorCorrection(struct ShaderColorCorrectionInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIBase::GetCurrentColorCorrection(CShaderAPIBase *this, ShaderColorCorrectionInfo_t *pInfo)
{
  g_pShaderUtil->GetCurrentColorCorrection(this: g_pShaderUtil, a2: pInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1000D890
// Name: public: CShaderAPIBase::CShaderAPIBase(void)
// Source: json
//------------------------------------------------------------------------------
CShaderAPIBase *__thiscall CShaderAPIBase::CShaderAPIBase(CShaderAPIBase *this)
{
  this->__vftable = (CShaderAPIBase_vtbl *)&CShaderAPIBase::`vftable';
  return this;
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x1000D450
// Name: public: virtual CShaderAPIBase::~CShaderAPIBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIBase::~CShaderAPIBase(CShaderAPIBase *this)
{
  this->__vftable = (CShaderAPIBase_vtbl *)&CShaderAPIBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1000D460
// Name: public: virtual void CShaderAPIBase::GetCurrentColorCorrection(struct ShaderColorCorrectionInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIBase::GetCurrentColorCorrection(CShaderAPIBase *this, ShaderColorCorrectionInfo_t *pInfo)
{
  g_pShaderUtil->GetCurrentColorCorrection(this: g_pShaderUtil, a2: pInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1000D490
// Name: public: CShaderAPIBase::CShaderAPIBase(void)
// Source: json
//------------------------------------------------------------------------------
CShaderAPIBase *__thiscall CShaderAPIBase::CShaderAPIBase(CShaderAPIBase *this)
{
  this->__vftable = (CShaderAPIBase_vtbl *)&CShaderAPIBase::`vftable';
  return this;
}

} // namespace shaderapidx10
