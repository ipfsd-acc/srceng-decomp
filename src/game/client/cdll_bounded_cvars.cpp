// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cdll_bounded_cvars.cpp
// Functions: 6
// ============================================================

#include "game\client\cdll_bounded_cvars.h"

//------------------------------------------------------------------------------
// Address: 0x100984D0
// Name: public: virtual int ConVar_ServerBounded::GetInt(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ConVar_ServerBounded::GetInt(ConVar_ServerBounded *this)
{
  double v1; // st7

  v1 = ((double (__thiscall *)(ConVar_ServerBounded *))this->GetFloat)(a1: this);
  return _ftol2_sse(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100984E0
// Name: public: virtual bool ConVar_ServerBounded::GetBool(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall ConVar_ServerBounded::GetBool(ConVar_ServerBounded *this)
{
  return this->GetInt(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100984F0
// Name: float GetClientInterpAmount(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetClientInterpAmount()
{
  ConCommandBase *v0; // eax
  float v2; // [esp+0h] [ebp-8h]
  float v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+4h] [ebp-4h]

  if ( (_S5_88 & 1) == 0 )
  {
    _S5_88 |= 1u;
    v0 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: "cl_updaterate");
    pUpdateRate = (const ConVar_ServerBounded *)__RTDynamicCast(
                                                  inptr: v0,
                                                  VfDelta: 0,
                                                  SrcType: &ConCommandBase `RTTI Type Descriptor',
                                                  TargetType: &ConVar_ServerBounded `RTTI Type Descriptor',
                                                  isReference: 0);
  }
  if ( pUpdateRate == nullptr )
    return 0.1;
  v2 = cl_interp->GetFloat(this: cl_interp);
  v4 = cl_interp_ratio->GetFloat(this: cl_interp_ratio);
  if ( v2 > v4 / ((double (__thiscall *)(const ConVar_ServerBounded *))pUpdateRate->GetFloat)(a1: pUpdateRate) )
    return cl_interp->GetFloat(this: cl_interp);
  v3 = cl_interp_ratio->GetFloat(this: cl_interp_ratio);
  return v3 / ((double (__thiscall *)(const ConVar_ServerBounded *))pUpdateRate->GetFloat)(a1: pUpdateRate);
}

//------------------------------------------------------------------------------
// Address: 0x100985E0
// Name: public: virtual float CBoundedCvar_Predict::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBoundedCvar_Predict::GetFloat(CBoundedCvar_Predict *this)
{
  ConCommandBase *v3; // eax
  const ConVar *v4; // eax

  if ( g_bForceCLPredictOff )
    return 0.0;
  if ( (`CBoundedCvar_Predict::GetFloat'::`4'::`local static guard' & 1) != 0 )
  {
    v4 = `CBoundedCvar_Predict::GetFloat'::`4'::pClientPredict;
  }
  else
  {
    `CBoundedCvar_Predict::GetFloat'::`4'::`local static guard' |= 1u;
    v3 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: "sv_client_predict");
    v4 = (const ConVar *)__RTDynamicCast(
                           inptr: v3,
                           VfDelta: 0,
                           SrcType: &ConCommandBase `RTTI Type Descriptor',
                           TargetType: &ConVar `RTTI Type Descriptor',
                           isReference: 0);
    `CBoundedCvar_Predict::GetFloat'::`4'::pClientPredict = v4;
  }
  if ( v4 == nullptr || v4->m_pParent != nullptr && v4->m_pParent->m_Value.m_nValue == -1 )
    return this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  else
    return v4->m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x10098660
// Name: public: virtual float CBoundedCvar_InterpRatio::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBoundedCvar_InterpRatio::GetFloat(CBoundedCvar_InterpRatio *this)
{
  ConCommandBase *v2; // eax
  ConCommandBase *v3; // eax
  const ConVar *v4; // ecx
  float m_fValue; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm2_4

  if ( (`CBoundedCvar_InterpRatio::GetFloat'::`2'::`local static guard' & 1) == 0 )
  {
    `CBoundedCvar_InterpRatio::GetFloat'::`2'::`local static guard' |= 1u;
    v2 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: "sv_client_min_interp_ratio");
    `CBoundedCvar_InterpRatio::GetFloat'::`2'::pMin = (const ConVar *)__RTDynamicCast(
                                                                        inptr: v2,
                                                                        VfDelta: 0,
                                                                        SrcType: &ConCommandBase `RTTI Type Descriptor',
                                                                        TargetType: &ConVar `RTTI Type Descriptor',
                                                                        isReference: 0);
  }
  if ( (`CBoundedCvar_InterpRatio::GetFloat'::`2'::`local static guard' & 2) != 0 )
  {
    v4 = `CBoundedCvar_InterpRatio::GetFloat'::`2'::pMax;
  }
  else
  {
    `CBoundedCvar_InterpRatio::GetFloat'::`2'::`local static guard' |= 2u;
    v3 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: "sv_client_max_interp_ratio");
    v4 = (const ConVar *)__RTDynamicCast(
                           inptr: v3,
                           VfDelta: 0,
                           SrcType: &ConCommandBase `RTTI Type Descriptor',
                           TargetType: &ConVar `RTTI Type Descriptor',
                           isReference: 0);
    `CBoundedCvar_InterpRatio::GetFloat'::`2'::pMax = v4;
  }
  if ( `CBoundedCvar_InterpRatio::GetFloat'::`2'::pMin == nullptr )
    return this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  if ( v4 == nullptr )
    return this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  m_fValue = `CBoundedCvar_InterpRatio::GetFloat'::`2'::pMin->m_pParent->m_Value.m_fValue;
  if ( m_fValue == -1.0 )
    return this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  v6 = this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  v7 = v4->m_pParent->m_Value.m_fValue;
  if ( m_fValue > v6 )
    return m_fValue;
  if ( v6 <= v7 )
    return v6;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10098770
// Name: public: virtual float CBoundedCvar_Interp::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBoundedCvar_Interp::GetFloat(CBoundedCvar_Interp *this)
{
  ConCommandBase *v2; // eax
  const ConVar_ServerBounded *v3; // ecx
  ConCommandBase *v4; // eax
  const ConVar *v5; // eax
  double m_fValue; // st6
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]

  if ( (`CBoundedCvar_Interp::GetFloat'::`2'::`local static guard' & 1) != 0 )
  {
    v3 = `CBoundedCvar_Interp::GetFloat'::`2'::pUpdateRate;
  }
  else
  {
    `CBoundedCvar_Interp::GetFloat'::`2'::`local static guard' |= 1u;
    v2 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: "cl_updaterate");
    v3 = (const ConVar_ServerBounded *)__RTDynamicCast(
                                         inptr: v2,
                                         VfDelta: 0,
                                         SrcType: &ConCommandBase `RTTI Type Descriptor',
                                         TargetType: &ConVar_ServerBounded `RTTI Type Descriptor',
                                         isReference: 0);
    `CBoundedCvar_Interp::GetFloat'::`2'::pUpdateRate = v3;
  }
  if ( (`CBoundedCvar_Interp::GetFloat'::`2'::`local static guard' & 2) != 0 )
  {
    v5 = `CBoundedCvar_Interp::GetFloat'::`2'::pMin;
  }
  else
  {
    `CBoundedCvar_Interp::GetFloat'::`2'::`local static guard' |= 2u;
    v4 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: "sv_client_min_interp_ratio");
    v5 = (const ConVar *)__RTDynamicCast(
                           inptr: v4,
                           VfDelta: 0,
                           SrcType: &ConCommandBase `RTTI Type Descriptor',
                           TargetType: &ConVar `RTTI Type Descriptor',
                           isReference: 0);
    v3 = `CBoundedCvar_Interp::GetFloat'::`2'::pUpdateRate;
    `CBoundedCvar_Interp::GetFloat'::`2'::pMin = v5;
  }
  if ( v3 == nullptr || v5 == nullptr || v5->m_pParent->m_Value.m_fValue == -1.0 )
    return this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  m_fValue = this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  v9 = v5->m_pParent->m_Value.m_fValue;
  if ( m_fValue > v9 / ((double (__thiscall *)(const ConVar_ServerBounded *))v3->GetFloat)(a1: v3) )
    return this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  v8 = `CBoundedCvar_Interp::GetFloat'::`2'::pMin->m_pParent->m_Value.m_fValue;
  return v8
       / ((double (__thiscall *)(const ConVar_ServerBounded *))`CBoundedCvar_Interp::GetFloat'::`2'::pUpdateRate->GetFloat)(a1: `CBoundedCvar_Interp::GetFloat'::`2'::pUpdateRate);
}
