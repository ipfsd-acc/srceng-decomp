// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/game.cpp
// Functions: 3
// ============================================================

#include "game\server\game.h"

//------------------------------------------------------------------------------
// Address: 0x1013DAD0
// Name: void InitializeCvars(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitializeCvars()
{
  ConVar_Register(nCVarFlag: 4, pAccessor: &g_ConVarAccessor);
  g_pDeveloper = cvar->FindVar_2(this: cvar, a2: "developer");
}

//------------------------------------------------------------------------------
// Address: 0x1013DB00
// Name: void MapCycleFileChangedCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MapCycleFileChangedCallback(IConVar *var, const char *pOldString)
{
  char *m_pszString; // eax

  if ( (mapcyclefile.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = mapcyclefile.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)locale;
  }
  if ( _V_stricmp(s1: pOldString, s2: m_pszString) != 0 && g_pGameRules != nullptr )
    g_pGameRules->ResetMapCycleTimeStamp(this: g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x1013DB50
// Name: public: virtual bool CGameDLL_ConVarAccessor::RegisterConCommandBase(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameDLL_ConVarAccessor::RegisterConCommandBase(CGameDLL_ConVarAccessor *this, ConVar *pCommand)
{
  const char *Default; // ebx
  ICvar_vtbl *v4; // edi
  const char *v5; // eax
  int v6; // edi
  bool replicated_3; // [esp+17h] [ebp+Bh]

  Default = nullptr;
  replicated_3 = pCommand->IsFlagSet(this: pCommand, a2: 0x2000);
  if ( replicated_3 && !pCommand->IsCommand(this: pCommand) )
    Default = ConVar::GetDefault(this: pCommand);
  cvar->RegisterConCommand(this: cvar, a2: pCommand);
  v4 = cvar->__vftable;
  v5 = pCommand->GetName(this: pCommand);
  v6 = (int)v4->GetCommandLineValue(this: cvar, a2: v5);
  if ( v6 != 0 )
  {
    if ( !pCommand->IsCommand(this: pCommand) )
    {
      pCommand->SetValue_4(this: &pCommand->IConVar, a2: (const char *)v6);
      return 1;
    }
  }
  else if ( replicated_3 && Default != nullptr && !pCommand->IsCommand(this: pCommand) )
  {
    pCommand->SetValue_4(this: &pCommand->IConVar, a2: Default);
  }
  return 1;
}
