// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/dt_recv_decoder.cpp
// Functions: 3
// ============================================================

#include "engine\dt_recv_decoder.h"

//------------------------------------------------------------------------------
// Address: 0x10170380
// Name: public: CRecvDecoder::CRecvDecoder(void)
// Source: json
//------------------------------------------------------------------------------
CRecvDecoder *__thiscall CRecvDecoder::CRecvDecoder(CRecvDecoder *this)
{
  CSendTablePrecalc::CSendTablePrecalc(this: &this->m_Precalc);
  this->m_Props.m_Memory.m_pMemory = nullptr;
  this->m_Props.m_Memory.m_nAllocationCount = 0;
  this->m_Props.m_Memory.m_nGrowSize = 0;
  this->m_Props.m_Size = 0;
  this->m_Props.m_pElements = nullptr;
  this->m_DatatableProps.m_Memory.m_pMemory = nullptr;
  this->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
  this->m_DatatableProps.m_Memory.m_nGrowSize = 0;
  this->m_DatatableProps.m_Size = 0;
  this->m_DatatableProps.m_pElements = nullptr;
  this->m_pTable = nullptr;
  this->m_pClientSendTable = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101703E0
// Name: public: CClientSendTable::CClientSendTable(void)
// Source: json
//------------------------------------------------------------------------------
CClientSendTable *__thiscall CClientSendTable::CClientSendTable(CClientSendTable *this)
{
  SendTable::SendTable(this: &this->m_SendTable);
  this->m_Props.m_Memory.m_pMemory = nullptr;
  this->m_Props.m_Memory.m_nAllocationCount = 0;
  this->m_Props.m_Memory.m_nGrowSize = 0;
  this->m_Props.m_Size = 0;
  this->m_Props.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10170400
// Name: public: CClientSendTable::~CClientSendTable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientSendTable::~CClientSendTable(CClientSendTable *this)
{
  int v2; // ebx
  int v3; // edi
  SendProp *m_pProps; // ecx
  int i; // edi
  bool v6; // sf
  CClientSendProp *m_pMemory; // eax

  free(pMem: this->m_SendTable.m_pNetTableName);
  v2 = 0;
  if ( this->m_SendTable.m_nProps > 0 )
  {
    v3 = 0;
    do
    {
      free(pMem: this->m_SendTable.m_pProps[v3].m_pVarName);
      free(pMem: this->m_SendTable.m_pProps[v3].m_pExcludeDTName);
      free(pMem: this->m_SendTable.m_pProps[v3].m_pParentArrayPropName);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_SendTable.m_nProps );
  }
  m_pProps = this->m_SendTable.m_pProps;
  if ( this->m_SendTable.m_pProps != nullptr )
  {
    if ( m_pProps[-1].m_pExtraData != nullptr )
      ((void (__thiscall *)(SendProp *, int))m_pProps->dtr_SendProp)(a1: m_pProps, a2: 3);
    else
      free(pMem: &m_pProps[-1].m_pExtraData);
  }
  for ( i = this->m_Props.m_Size - 1; i >= 0; --i )
    free(pMem: this->m_Props.m_Memory.m_pMemory[i].m_pTableName);
  v6 = this->m_Props.m_Memory.m_nGrowSize < 0;
  this->m_Props.m_Size = 0;
  if ( !v6 )
  {
    if ( this->m_Props.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Props.m_Memory.m_pMemory);
      this->m_Props.m_Memory.m_pMemory = nullptr;
    }
    this->m_Props.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_Props.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Props.m_Memory.m_pMemory;
  this->m_Props.m_pElements = m_pMemory;
  if ( !v6 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Props.m_Memory.m_pMemory = nullptr;
    }
    this->m_Props.m_Memory.m_nAllocationCount = 0;
  }
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10170540
// Name: public: CRecvDecoder::CRecvDecoder(void)
// Source: json
//------------------------------------------------------------------------------
CRecvDecoder *__thiscall CRecvDecoder::CRecvDecoder(CRecvDecoder *this)
{
  CSendTablePrecalc::CSendTablePrecalc(this: &this->m_Precalc);
  this->m_Props.m_Memory.m_pMemory = nullptr;
  this->m_Props.m_Memory.m_nAllocationCount = 0;
  this->m_Props.m_Memory.m_nGrowSize = 0;
  this->m_Props.m_Size = 0;
  this->m_Props.m_pElements = nullptr;
  this->m_DatatableProps.m_Memory.m_pMemory = nullptr;
  this->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
  this->m_DatatableProps.m_Memory.m_nGrowSize = 0;
  this->m_DatatableProps.m_Size = 0;
  this->m_DatatableProps.m_pElements = nullptr;
  this->m_pTable = nullptr;
  this->m_pClientSendTable = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101705A0
// Name: public: CClientSendTable::CClientSendTable(void)
// Source: json
//------------------------------------------------------------------------------
CClientSendTable *__thiscall CClientSendTable::CClientSendTable(CClientSendTable *this)
{
  SendTable::SendTable(this: &this->m_SendTable);
  this->m_Props.m_Memory.m_pMemory = nullptr;
  this->m_Props.m_Memory.m_nAllocationCount = 0;
  this->m_Props.m_Memory.m_nGrowSize = 0;
  this->m_Props.m_Size = 0;
  this->m_Props.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101705C0
// Name: public: CClientSendTable::~CClientSendTable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientSendTable::~CClientSendTable(CClientSendTable *this)
{
  int v2; // ebx
  int v3; // edi
  SendProp *m_pProps; // ecx
  int i; // edi
  bool v6; // sf
  CClientSendProp *m_pMemory; // eax

  free(pMem: this->m_SendTable.m_pNetTableName);
  v2 = 0;
  if ( this->m_SendTable.m_nProps > 0 )
  {
    v3 = 0;
    do
    {
      free(pMem: this->m_SendTable.m_pProps[v3].m_pVarName);
      free(pMem: this->m_SendTable.m_pProps[v3].m_pExcludeDTName);
      free(pMem: this->m_SendTable.m_pProps[v3].m_pParentArrayPropName);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_SendTable.m_nProps );
  }
  m_pProps = this->m_SendTable.m_pProps;
  if ( this->m_SendTable.m_pProps != nullptr )
  {
    if ( m_pProps[-1].m_pExtraData != nullptr )
      ((void (__thiscall *)(SendProp *, int))m_pProps->dtr_SendProp)(a1: m_pProps, a2: 3);
    else
      free(pMem: &m_pProps[-1].m_pExtraData);
  }
  for ( i = this->m_Props.m_Size - 1; i >= 0; --i )
    free(pMem: this->m_Props.m_Memory.m_pMemory[i].m_pTableName);
  v6 = this->m_Props.m_Memory.m_nGrowSize < 0;
  this->m_Props.m_Size = 0;
  if ( !v6 )
  {
    if ( this->m_Props.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Props.m_Memory.m_pMemory);
      this->m_Props.m_Memory.m_pMemory = nullptr;
    }
    this->m_Props.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_Props.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Props.m_Memory.m_pMemory;
  this->m_Props.m_pElements = m_pMemory;
  if ( !v6 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Props.m_Memory.m_pMemory = nullptr;
    }
    this->m_Props.m_Memory.m_nAllocationCount = 0;
  }
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

} // namespace engine_xlsp
