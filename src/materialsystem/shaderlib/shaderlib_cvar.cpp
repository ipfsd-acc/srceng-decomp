// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderlib/shaderlib_cvar.cpp
// Functions: 2
// ============================================================

#include "materialsystem\shaderlib\shaderlib_cvar.h"

//------------------------------------------------------------------------------
// Address: 0x10252910
// Name: void InitShaderLibCVars(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitShaderLibCVars()
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0x800000, pAccessor: &g_ConVarAccessor);
}

//------------------------------------------------------------------------------
// Address: 0x10252930
// Name: public: virtual bool CShaderLibConVarAccessor::RegisterConCommandBase(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderLibConVarAccessor::RegisterConCommandBase(
        CShaderLibConVarAccessor *this,
        ConCommandBase *pCommand)
{
  ICvar_vtbl *v2; // edi
  const char *v3; // eax
  int v4; // edi

  g_pCVar->RegisterConCommand(this: g_pCVar, a2: pCommand);
  v2 = g_pCVar->__vftable;
  v3 = pCommand->GetName(this: pCommand);
  v4 = (int)v2->GetCommandLineValue(this: g_pCVar, a2: v3);
  if ( v4 != 0 && !pCommand->IsCommand(this: pCommand) )
    pCommand[1].AddFlags(this: &pCommand[1], a2: v4);
  return 1;
}

// ============================================================
// Overlay from stdshader_dbg (Missing functions)
// ============================================================
namespace stdshader_dbg {

//------------------------------------------------------------------------------
// Address: 0x10003B30
// Name: void InitShaderLibCVars(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitShaderLibCVars()
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0x800000, pAccessor: &g_ConVarAccessor);
}

//------------------------------------------------------------------------------
// Address: 0x10003B50
// Name: public: virtual bool CShaderLibConVarAccessor::RegisterConCommandBase(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderLibConVarAccessor::RegisterConCommandBase(
        CShaderLibConVarAccessor *this,
        ConCommandBase *pCommand)
{
  ICvar_vtbl *v2; // edi
  const char *v3; // eax
  int v4; // edi

  g_pCVar->RegisterConCommand(this: g_pCVar, a2: pCommand);
  v2 = g_pCVar->__vftable;
  v3 = pCommand->GetName(this: pCommand);
  v4 = (int)v2->GetCommandLineValue(this: g_pCVar, a2: v3);
  if ( v4 != 0 && !pCommand->IsCommand(this: pCommand) )
    pCommand[1].AddFlags(this: &pCommand[1], a2: v4);
  return 1;
}

} // namespace stdshader_dbg

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x1004ADA0
// Name: void InitShaderLibCVars(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitShaderLibCVars()
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0x800000, pAccessor: &g_ConVarAccessor);
}

//------------------------------------------------------------------------------
// Address: 0x1004ADC0
// Name: public: virtual bool CShaderLibConVarAccessor::RegisterConCommandBase(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderLibConVarAccessor::RegisterConCommandBase(
        CShaderLibConVarAccessor *this,
        ConCommandBase *pCommand)
{
  ICvar_vtbl *v2; // edi
  const char *v3; // eax
  int v4; // edi

  g_pCVar->RegisterConCommand(this: g_pCVar, a2: pCommand);
  v2 = g_pCVar->__vftable;
  v3 = pCommand->GetName(this: pCommand);
  v4 = (int)v2->GetCommandLineValue(this: g_pCVar, a2: v3);
  if ( v4 != 0 && !pCommand->IsCommand(this: pCommand) )
    pCommand[1].AddFlags(this: &pCommand[1], a2: v4);
  return 1;
}

} // namespace stdshader_dx9
