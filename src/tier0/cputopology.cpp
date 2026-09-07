// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/cputopology.cpp
// Functions: 4
// ============================================================

#include "tier0\cputopology.h"

//------------------------------------------------------------------------------
// Address: 0x10002EA0
// Name: public: unsigned long CpuTopology::NumberOfSystemCores(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CpuTopology::NumberOfSystemCores(CpuTopology *this)
{
  return this->m_pImpl->NumberOfSystemCores(this: this->m_pImpl);
}

//------------------------------------------------------------------------------
// Address: 0x10003120
// Name: public: CpuTopology::~CpuTopology(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CpuTopology::~CpuTopology(CpuTopology *this)
{
  ICpuTopology *m_pImpl; // ecx

  m_pImpl = this->m_pImpl;
  if ( m_pImpl != nullptr )
    ((void (__thiscall *)(ICpuTopology *, int))m_pImpl->dtr_ICpuTopology)(a1: m_pImpl, a2: 1);
  this->m_pImpl = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003800
// Name: public: void CpuTopology::ForceCpuid(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CpuTopology::ForceCpuid(CpuTopology *this, int bForce)
{
  ICpuTopology *m_pImpl; // ecx
  GlpiImpl *v4; // eax
  ICpuTopology *v5; // eax
  CpuidImpl *v6; // eax
  ICpuTopology *v7; // eax
  ICpuTopology *v8; // eax

  m_pImpl = this->m_pImpl;
  if ( m_pImpl != nullptr )
    ((void (__thiscall *)(ICpuTopology *, int))m_pImpl->dtr_ICpuTopology)(a1: m_pImpl, a2: 1);
  this->m_pImpl = nullptr;
  if ( bForce != 0 )
    goto LABEL_9;
  if ( (``anonymous namespace'::GlpiImpl::GetGlpiFn_'::`2'::`local static guard' & 1) == 0 )
  {
    ``anonymous namespace'::GlpiImpl::GetGlpiFn_'::`2'::`local static guard' |= 1u;
    ``anonymous namespace'::GlpiImpl::GetGlpiFn_'::`2'::pGlpi = (int)`anonymous namespace'::GlpiImpl::VerifyGlpiFn_();
  }
  if ( ``anonymous namespace'::GlpiImpl::GetGlpiFn_'::`2'::pGlpi == 0 )
  {
LABEL_9:
    if ( `anonymous namespace'::CpuidImpl::IsSupported() != 0 )
    {
      v6 = (CpuidImpl *)operator new(size: 0x30u);
      if ( v6 != nullptr )
      {
        `anonymous namespace'::CpuidImpl::CpuidImpl(this: v6);
        this->m_pImpl = v7;
        return;
      }
    }
    else
    {
      v8 = (ICpuTopology *)operator new(size: 4u);
      if ( v8 != nullptr )
      {
        v8->__vftable = (ICpuTopology_vtbl *)&`anonymous namespace'::DefaultImpl::`vftable';
        this->m_pImpl = v8;
        return;
      }
    }
  }
  else
  {
    v4 = (GlpiImpl *)operator new(size: 0xCu);
    if ( v4 != nullptr )
    {
      `anonymous namespace'::GlpiImpl::GlpiImpl(this: v4);
      this->m_pImpl = v5;
      return;
    }
  }
  this->m_pImpl = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100038B0
// Name: public: CpuTopology::CpuTopology(int)
// Source: json
//------------------------------------------------------------------------------
CpuTopology *__thiscall CpuTopology::CpuTopology(CpuTopology *this, int bForceCpuid)
{
  this->m_pImpl = nullptr;
  CpuTopology::ForceCpuid(this, bForce: bForceCpuid);
  return this;
}
