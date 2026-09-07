// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/gameui_util.cpp
// Functions: 9
// ============================================================

#include "game\client\cstrike15\gameui\gameui_util.h"

//------------------------------------------------------------------------------
// Address: 0x101D6700
// Name: int GetGameUIActiveSplitScreenPlayerSlot(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetGameUIActiveSplitScreenPlayerSlot()
{
  return g_nGameUIActiveSplitscreenPlayerSlot;
}

//------------------------------------------------------------------------------
// Address: 0x101D6710
// Name: void SetGameUIActiveSplitScreenPlayerSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetGameUIActiveSplitScreenPlayerSlot(int nSlot)
{
  if ( g_nGameUIActiveSplitscreenPlayerSlot != nSlot )
    g_nGameUIActiveSplitscreenPlayerSlot = nSlot;
}

//------------------------------------------------------------------------------
// Address: 0x101D6730
// Name: public: virtual char const __near * CEmptyGameUIConVar::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEmptyGameUIConVar::GetName(CEmptyConVar *this)
{
  return prType;
}

//------------------------------------------------------------------------------
// Address: 0x101D6740
// Name: public: bool CGameUIConVarRef::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameUIConVarRef::IsValid(CGameUIConVarRef *this)
{
  return this->m_Info[0].m_pConVar != &s_EmptyConVar.IConVar;
}

//------------------------------------------------------------------------------
// Address: 0x101D6750
// Name: public: CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(int)
// Source: json
//------------------------------------------------------------------------------
CGameUiSetActiveSplitScreenPlayerGuard *__thiscall CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
        CGameUiSetActiveSplitScreenPlayerGuard *this,
        int slot)
{
  this->m_nSaveSlot = engine->GetActiveSplitScreenPlayerSlot(this: engine);
  engine->SetActiveSplitScreenPlayerSlot(this: engine, a2: slot);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D6790
// Name: public: CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(
        CGameUiSetActiveSplitScreenPlayerGuard *this)
{
  engine->SetActiveSplitScreenPlayerSlot(this: engine, a2: this->m_nSaveSlot);
}

//------------------------------------------------------------------------------
// Address: 0x101D67B0
// Name: public: void CGameUIConVarRef::Init(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIConVarRef::Init(CGameUIConVarRef *this, char *pName, bool bIgnoreMissing)
{
  int i; // esi
  ConVar *v5; // eax
  IConVar *v6; // eax
  IConVar *m_pConVar; // eax
  ConVar *v8; // eax
  char pchName[256]; // [esp+Ch] [ebp-100h] BYREF

  for ( i = 0; i < 2; ++i )
  {
    if ( i != 0 )
      V_snprintf(pDest: pchName, maxLen: 0x100u, pFormat: "%s%d", pName, i + 1);
    else
      V_strncpy(pDest: pchName, pSrc: pName, maxLen: 256);
    if ( g_pCVar != nullptr )
    {
      v5 = g_pCVar->FindVar_2(this: g_pCVar, a2: pchName);
      if ( v5 != nullptr )
        v6 = &v5->IConVar;
      else
        v6 = nullptr;
    }
    else
    {
      v6 = &s_EmptyConVar.IConVar;
    }
    this->m_Info[i].m_pConVar = v6;
    if ( v6 != nullptr
      || (this->m_Info[i].m_pConVar = &s_EmptyConVar.IConVar, i <= 0)
      || (m_pConVar = this->m_Info[0].m_pConVar,
          this->m_Info[i].m_pConVar = this->m_Info[0].m_pConVar,
          m_pConVar != nullptr) )
    {
      v8 = (ConVar *)&this->m_Info[i].m_pConVar[-6];
    }
    else
    {
      v8 = nullptr;
    }
    this->m_Info[i].m_pConVarState = v8;
  }
  if ( this->m_Info[0].m_pConVar == &s_EmptyConVar.IConVar && (g_pCVar != nullptr || bFirst_0) )
  {
    if ( !bIgnoreMissing )
      _Warning(a1: "CGameUIConVarRef %s doesn't point to an existing ConVar\n", pName);
    bFirst_0 = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D68A0
// Name: public: CGameUIConVarRef::CGameUIConVarRef(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameUIConVarRef *__thiscall CGameUIConVarRef::CGameUIConVarRef(CGameUIConVarRef *this, char *pName)
{
  CGameUIConVarRef::Init(this, pName, bIgnoreMissing: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D68C0
// Name: public: CGameUIConVarRef::CGameUIConVarRef(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CGameUIConVarRef *__thiscall CGameUIConVarRef::CGameUIConVarRef(
        CGameUIConVarRef *this,
        char *pName,
        bool bIgnoreMissing)
{
  CGameUIConVarRef::Init(this, pName, bIgnoreMissing);
  return this;
}
