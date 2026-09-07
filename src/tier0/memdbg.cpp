// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/memdbg.cpp
// Functions: 5
// ============================================================

#include "tier0\memdbg.h"

//------------------------------------------------------------------------------
// Address: 0x10006720
// Name: public: CallStackStatStructDescFuncs::CallStackStatStructDescFuncs(void)
// Source: json
//------------------------------------------------------------------------------
CallStackStatStructDescFuncs *__thiscall CallStackStatStructDescFuncs::CallStackStatStructDescFuncs(
        CallStackStatStructDescFuncs *this)
{
  this->__vftable = (CallStackStatStructDescFuncs_vtbl *)&CallStackStatStructDescFuncs::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006730
// Name: public: CallStackStatStructDescFuncs::CallStackStatStructDescFuncs(class CallStackStatStructDescFuncs const __near &)
// Source: json
//------------------------------------------------------------------------------
CallStackStatStructDescFuncs *__thiscall CallStackStatStructDescFuncs::CallStackStatStructDescFuncs(
        CallStackStatStructDescFuncs *this,
        const CallStackStatStructDescFuncs *__that)
{
  this->__vftable = (CallStackStatStructDescFuncs_vtbl *)&CallStackStatStructDescFuncs::`vftable';
  this->m_szFieldName = __that->m_szFieldName;
  this->m_iFieldOffset = __that->m_iFieldOffset;
  this->m_pNext = __that->m_pNext;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006780
// Name: public: BasicStatStructFieldDesc::BasicStatStructFieldDesc(enum BasicStatStructFieldTypes_t,enum BasicStatStructFieldCombineMethods_t)
// Source: json
//------------------------------------------------------------------------------
BasicStatStructFieldDesc *__thiscall BasicStatStructFieldDesc::BasicStatStructFieldDesc(
        BasicStatStructFieldDesc *this,
        BasicStatStructFieldTypes_t type,
        BasicStatStructFieldCombineMethods_t combineMethod)
{
  this->__vftable = (BasicStatStructFieldDesc_vtbl *)&BasicStatStructFieldDesc::`vftable';
  this->m_Type = type;
  this->m_Combine = combineMethod;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100067A0
// Name: public: BasicStatStructFieldDesc::BasicStatStructFieldDesc(class BasicStatStructFieldDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
BasicStatStructFieldDesc *__thiscall BasicStatStructFieldDesc::BasicStatStructFieldDesc(
        BasicStatStructFieldDesc *this,
        const BasicStatStructFieldDesc *__that)
{
  this->__vftable = (BasicStatStructFieldDesc_vtbl *)&CallStackStatStructDescFuncs::`vftable';
  this->m_szFieldName = __that->m_szFieldName;
  this->m_iFieldOffset = __that->m_iFieldOffset;
  this->m_pNext = __that->m_pNext;
  this->__vftable = (BasicStatStructFieldDesc_vtbl *)&BasicStatStructFieldDesc::`vftable';
  this->m_Type = __that->m_Type;
  this->m_Combine = __that->m_Combine;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100067E0
// Name: public: class BasicStatStructFieldDesc __near & BasicStatStructFieldDesc::operator=(class BasicStatStructFieldDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
BasicStatStructFieldDesc *__thiscall BasicStatStructFieldDesc::operator=(
        BasicStatStructFieldDesc *this,
        const BasicStatStructFieldDesc *__that)
{
  this->m_szFieldName = __that->m_szFieldName;
  this->m_iFieldOffset = __that->m_iFieldOffset;
  this->m_pNext = __that->m_pNext;
  this->m_Type = __that->m_Type;
  this->m_Combine = __that->m_Combine;
  return this;
}
