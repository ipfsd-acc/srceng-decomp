// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_bounded_cvars.cpp
// Functions: 6
// ============================================================

#include "engine\cl_bounded_cvars.h"

//------------------------------------------------------------------------------
// Address: 0x10149F20
// Name: public: virtual int ConVar_ServerBounded::GetInt(void)const
// Source: json
//------------------------------------------------------------------------------
int __usercall ConVar_ServerBounded::GetInt@<eax>(ConVar_ServerBounded *this@<ecx>, double a2@<st0>)
{
  this->GetFloat(this);
  return _ftol2_sse(a1: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10149F30
// Name: public: virtual bool ConVar_ServerBounded::GetBool(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall ConVar_ServerBounded::GetBool(ConVar_ServerBounded *this)
{
  return this->GetInt(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10149F40
// Name: void CL_RateCvarChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RateCvarChanged(IConVar *pConVar)
{
  char rate[128]; // [esp+0h] [ebp-88h] BYREF
  ConVarRef var; // [esp+80h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  V_snprintf(pDest: rate, maxLen: 128, pFormat: "%u", var.m_pConVarState->m_Value.m_nValue);
  Sys_SetRegKeyValue(pszSubKey: "Software\\Valve\\Steam", pszElement: "Rate", pszValue: rate);
}

//------------------------------------------------------------------------------
// Address: 0x10149F90
// Name: public: virtual float CBoundedCvar_Rate::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBoundedCvar_Rate::GetFloat(CBoundedCvar_Rate *this)
{
  if ( GetBaseLocalClient()->m_nSignonState < 6 )
    return this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  else
    return (double)ClampClientRate(nRate: (int)this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue);
}

//------------------------------------------------------------------------------
// Address: 0x1014A020
// Name: public: virtual float CBoundedCvar_CmdRate::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBoundedCvar_CmdRate::GetFloat(CBoundedCvar_CmdRate *this)
{
  long double v1; // st7
  float v2; // xmm0_4
  double (*GetFloat)(void); // eax
  float m_fValue; // xmm0_4
  float v5; // xmm1_4
  float diffa; // [esp+0h] [ebp-8h]
  float diff; // [esp+0h] [ebp-8h]
  float flCmdRate; // [esp+4h] [ebp-4h]

  flCmdRate = this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  if ( sv_mincmdrate.m_pParent == nullptr
    || sv_mincmdrate.m_pParent->m_Value.m_nValue == 0
    || GetBaseLocalClient()->m_nSignonState < 6 )
  {
    return flCmdRate;
  }
  v1 = flCmdRate - ((double (__thiscall *)(ConVar_ServerBounded *))cl_updaterate->GetFloat)(a1: cl_updaterate);
  if ( fabs(v1) > sv_client_cmdrate_difference.m_pParent->m_Value.m_fValue )
  {
    diffa = v1;
    v2 = diffa;
    diff = sv_client_cmdrate_difference.m_pParent->m_Value.m_fValue;
    GetFloat = (double (*)(void))cl_updaterate->GetFloat;
    if ( v2 <= 0.0 )
      flCmdRate = GetFloat() - diff;
    else
      flCmdRate = GetFloat() + diff;
  }
  m_fValue = sv_mincmdrate.m_pParent->m_Value.m_fValue;
  v5 = sv_maxcmdrate.m_pParent->m_Value.m_fValue;
  if ( m_fValue > flCmdRate )
    return m_fValue;
  if ( flCmdRate > v5 )
    return v5;
  else
    return flCmdRate;
}

//------------------------------------------------------------------------------
// Address: 0x1014A100
// Name: public: virtual float CBoundedCvar_UpdateRate::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBoundedCvar_UpdateRate::GetFloat(CBoundedCvar_UpdateRate *this)
{
  float m_fValue; // xmm2_4
  float v2; // xmm1_4
  float v3; // xmm0_4

  m_fValue = sv_maxupdaterate.m_pParent->m_Value.m_fValue;
  v2 = sv_minupdaterate.m_pParent->m_Value.m_fValue;
  v3 = this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  if ( v2 > v3 )
    return v2;
  if ( v3 <= m_fValue )
    return v3;
  return m_fValue;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1014A080
// Name: public: virtual int ConVar_ServerBounded::GetInt(void)const
// Source: json
//------------------------------------------------------------------------------
int __usercall ConVar_ServerBounded::GetInt@<eax>(ConVar_ServerBounded *this@<ecx>, double a2@<st0>)
{
  this->GetFloat(this);
  return _ftol2_sse(a1: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1014A090
// Name: public: virtual bool ConVar_ServerBounded::GetBool(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall ConVar_ServerBounded::GetBool(ConVar_ServerBounded *this)
{
  return this->GetInt(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014A0A0
// Name: void CL_RateCvarChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RateCvarChanged(IConVar *pConVar)
{
  char rate[128]; // [esp+0h] [ebp-88h] BYREF
  ConVarRef var; // [esp+80h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  V_snprintf(pDest: rate, maxLen: 128, pFormat: "%u", var.m_pConVarState->m_Value.m_nValue);
  Sys_SetRegKeyValue(pszSubKey: "Software\\Valve\\Steam", pszElement: "Rate", pszValue: rate);
}

//------------------------------------------------------------------------------
// Address: 0x1014A0F0
// Name: public: virtual float CBoundedCvar_Rate::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBoundedCvar_Rate::GetFloat(CBoundedCvar_Rate *this)
{
  if ( GetBaseLocalClient()->m_nSignonState < 6 )
    return this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  else
    return (double)ClampClientRate(nRate: (int)this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue);
}

//------------------------------------------------------------------------------
// Address: 0x1014A180
// Name: public: virtual float CBoundedCvar_CmdRate::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBoundedCvar_CmdRate::GetFloat(CBoundedCvar_CmdRate *this)
{
  long double v1; // st7
  float v2; // xmm0_4
  double (*GetFloat)(void); // eax
  float m_fValue; // xmm0_4
  float v5; // xmm1_4
  float diffa; // [esp+0h] [ebp-8h]
  float diff; // [esp+0h] [ebp-8h]
  float flCmdRate; // [esp+4h] [ebp-4h]

  flCmdRate = this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  if ( sv_mincmdrate.m_pParent == nullptr
    || sv_mincmdrate.m_pParent->m_Value.m_nValue == 0
    || GetBaseLocalClient()->m_nSignonState < 6 )
  {
    return flCmdRate;
  }
  v1 = flCmdRate - ((double (__thiscall *)(ConVar_ServerBounded *))cl_updaterate->GetFloat)(a1: cl_updaterate);
  if ( fabs(v1) > sv_client_cmdrate_difference.m_pParent->m_Value.m_fValue )
  {
    diffa = v1;
    v2 = diffa;
    diff = sv_client_cmdrate_difference.m_pParent->m_Value.m_fValue;
    GetFloat = (double (*)(void))cl_updaterate->GetFloat;
    if ( v2 <= 0.0 )
      flCmdRate = GetFloat() - diff;
    else
      flCmdRate = GetFloat() + diff;
  }
  m_fValue = sv_mincmdrate.m_pParent->m_Value.m_fValue;
  v5 = sv_maxcmdrate.m_pParent->m_Value.m_fValue;
  if ( m_fValue > flCmdRate )
    return m_fValue;
  if ( flCmdRate > v5 )
    return v5;
  else
    return flCmdRate;
}

//------------------------------------------------------------------------------
// Address: 0x1014A260
// Name: public: virtual float CBoundedCvar_UpdateRate::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBoundedCvar_UpdateRate::GetFloat(CBoundedCvar_UpdateRate *this)
{
  float m_fValue; // xmm2_4
  float v2; // xmm1_4
  float v3; // xmm0_4

  m_fValue = sv_maxupdaterate.m_pParent->m_Value.m_fValue;
  v2 = sv_minupdaterate.m_pParent->m_Value.m_fValue;
  v3 = this->m_pParent->ConVar_ServerBounded::ConVar::m_Value.m_fValue;
  if ( v2 > v3 )
    return v2;
  if ( v3 <= m_fValue )
    return v3;
  return m_fValue;
}

} // namespace engine_xlsp
