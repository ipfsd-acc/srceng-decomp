// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/dt_stack.cpp
// Functions: 2
// ============================================================

#include "engine\dt_stack.h"

//------------------------------------------------------------------------------
// Address: 0x10174740
// Name: public: CDatatableStack::CDatatableStack(class CSendTablePrecalc __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDatatableStack *__thiscall CDatatableStack::CDatatableStack(
        CDatatableStack *this,
        CSendTablePrecalc *pPrecalc,
        unsigned __int8 *pStructBase,
        int objectID)
{
  this->m_pPrecalc = pPrecalc;
  this->m_ObjectID = objectID;
  this->__vftable = (CDatatableStack_vtbl *)&CDatatableStack::`vftable';
  this->m_pStructBase = pStructBase;
  this->m_iCurProp = 0;
  this->m_pCurProp = nullptr;
  *(_WORD *)&this->m_bInitted = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10174780
// Name: public: void CDatatableStack::Init(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatatableStack::Init(CDatatableStack *this, bool bExplicitRoutes, bool bLocalNetworkBackDoor)
{
  CSendTablePrecalc *m_pPrecalc; // ecx

  m_pPrecalc = this->m_pPrecalc;
  this->m_bLocalNetworkBackDoor = bLocalNetworkBackDoor;
  if ( bExplicitRoutes )
    memset(dst: (unsigned __int8 *)this->m_pProxies, value: 0xFFu, count: 4 * m_pPrecalc->m_ProxyPaths.m_Size);
  else
    this->RecurseAndCallProxies(this, a2: &m_pPrecalc->m_Root, a3: this->m_pStructBase);
  this->m_bInitted = true;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10174AB0
// Name: public: CDatatableStack::CDatatableStack(class CSendTablePrecalc __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDatatableStack *__thiscall CDatatableStack::CDatatableStack(
        CDatatableStack *this,
        CSendTablePrecalc *pPrecalc,
        unsigned __int8 *pStructBase,
        int objectID)
{
  this->m_pPrecalc = pPrecalc;
  this->m_ObjectID = objectID;
  this->__vftable = (CDatatableStack_vtbl *)&CDatatableStack::`vftable';
  this->m_pStructBase = pStructBase;
  this->m_iCurProp = 0;
  this->m_pCurProp = nullptr;
  *(_WORD *)&this->m_bInitted = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10174AF0
// Name: public: void CDatatableStack::Init(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatatableStack::Init(CDatatableStack *this, bool bExplicitRoutes, bool bLocalNetworkBackDoor)
{
  CSendTablePrecalc *m_pPrecalc; // ecx

  m_pPrecalc = this->m_pPrecalc;
  this->m_bLocalNetworkBackDoor = bLocalNetworkBackDoor;
  if ( bExplicitRoutes )
    memset(dst: (unsigned __int8 *)this->m_pProxies, value: 0xFFu, count: 4 * m_pPrecalc->m_ProxyPaths.m_Size);
  else
    this->RecurseAndCallProxies(this, a2: &m_pPrecalc->m_Root, a3: this->m_pStructBase);
  this->m_bInitted = true;
}

} // namespace engine_xlsp
