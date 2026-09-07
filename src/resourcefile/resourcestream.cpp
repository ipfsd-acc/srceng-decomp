// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: resourcefile/resourcestream.cpp
// Functions: 3
// ============================================================

#include "resourcefile\resourcestream.h"

//------------------------------------------------------------------------------
// Address: 0x10097030
// Name: protected: void CResourceStream::EnsureAvailable(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceStream::EnsureAvailable(CResourceStream *this, unsigned int addCapacity)
{
  unsigned int m_nUsed; // ecx
  unsigned int v4; // eax
  unsigned int m_nCommitted; // ecx
  unsigned int v6; // edi

  m_nUsed = this->m_nUsed;
  v4 = m_nUsed + addCapacity;
  if ( m_nUsed + addCapacity <= this->m_nReserved )
  {
    m_nCommitted = this->m_nCommitted;
    if ( v4 > m_nCommitted )
    {
      v6 = (v4 + 0xFFFF) & 0xFFFF0000;
      VirtualAlloc(
        lpAddress: &this->m_pData[m_nCommitted],
        dwSize: v6 - m_nCommitted,
        flAllocationType: 0x1000u,
        flProtect: 4u);
      this->m_nCommitted = v6;
    }
  }
  else
  {
    _Error(a1: "trying to add %u bytes, used %u bytes, reserved %u bytes\n", addCapacity, m_nUsed, this->m_nReserved);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100970A0
// Name: public: void __near * CResourceStream::AllocateBytes(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CResourceStream::AllocateBytes(CResourceStream *this, unsigned int numBytes)
{
  unsigned int m_nUsed; // ecx
  unsigned __int8 *result; // eax

  CResourceStream::EnsureAvailable(this, addCapacity: numBytes);
  m_nUsed = this->m_nUsed;
  result = &this->m_pData[m_nUsed];
  this->m_nUsed = numBytes + m_nUsed;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100970D0
// Name: public: void CResourceStream::Align(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceStream::Align(CResourceStream *this, unsigned int nAlignment, int nOffset)
{
  unsigned int m_nMaxAlignment; // ecx
  unsigned int v5; // esi

  m_nMaxAlignment = this->m_nMaxAlignment;
  if ( m_nMaxAlignment <= nAlignment )
    m_nMaxAlignment = nAlignment;
  this->m_nMaxAlignment = m_nMaxAlignment;
  if ( ((nAlignment - 1) & nAlignment) != 0 )
  {
    _Error(a1: "Wrong alignment %d\n", nAlignment);
  }
  else
  {
    v5 = (nAlignment - 1) & (nOffset - this->m_nUsed);
    CResourceStream::EnsureAvailable(this, addCapacity: v5);
    this->m_nUsed += v5;
  }
}
