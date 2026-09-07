// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/gamerules_register.cpp
// Functions: 3
// ============================================================

#include "game\shared\gamerules_register.h"

//------------------------------------------------------------------------------
// Address: 0x100E8870
// Name: public: CGameRulesRegister::CGameRulesRegister(char const __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
CGameRulesRegister *__thiscall CGameRulesRegister::CGameRulesRegister(
        CGameRulesRegister *this,
        const char *pClassName,
        void (__cdecl *fn)())
{
  this->m_pClassName = pClassName;
  this->m_pFn = fn;
  this->m_pNext = (CGameRulesRegister *)_S5_99.m_RecvType;
  _S5_99.m_RecvType = (SendPropType)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E88A0
// Name: void OnGameRulesCreationStringChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnGameRulesCreationStringChanged(
        void *object,
        INetworkStringTable *stringTable,
        int stringNumber,
        const char *newString,
        const char *newData)
{
  SendPropType m_RecvType; // esi

  if ( g_pGameRules != nullptr )
    ((void (__thiscall *)(C_GameRules *, int))g_pGameRules->dtr_IGameSystem)(a1: g_pGameRules, a2: 1);
  m_RecvType = _S5_99.m_RecvType;
  g_pGameRules = nullptr;
  if ( _S5_99.m_RecvType != DPT_Int )
  {
    while ( _V_stricmp(s1: newData, s2: *(const char **)m_RecvType) != 0 )
    {
      m_RecvType = *(_DWORD *)(m_RecvType + 8);
      if ( m_RecvType == DPT_Int )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    m_RecvType = DPT_Int;
    _Error(this: (ISceneTokenProcessor *)&stru_104773B8, a2: newData);
  }
  (*(void (**)(void))(m_RecvType + 4))();
  if ( g_pGameRules == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_10477370, a2: newData);
}

//------------------------------------------------------------------------------
// Address: 0x100E8920
// Name: void InstallStringTableCallback_GameRules(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallStringTableCallback_GameRules(const char *tableName)
{
  INetworkStringTable *v1; // eax

  if ( V_strcasecmp(s1: tableName, s2: "GameRulesCreation") == 0 )
  {
    v1 = networkstringtable->FindTable(this: networkstringtable, a2: tableName);
    _S5_99.m_Flags = (int)v1;
    if ( v1 != nullptr )
      v1->SetStringChangedCallback(this: v1, a2: nullptr, a3: OnGameRulesCreationStringChanged);
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1014D320
// Name: public: CGameRulesRegister::CGameRulesRegister(char const __near *,void (*)(void))
// Source: json
//------------------------------------------------------------------------------
CGameRulesRegister *__thiscall CGameRulesRegister::CGameRulesRegister(
        CGameRulesRegister *this,
        const char *pClassName,
        void (__cdecl *fn)())
{
  this->m_pClassName = pClassName;
  this->m_pFn = fn;
  this->m_pNext = (CGameRulesRegister *)_S2_127.m_pMatchingRecvProp;
  _S2_127.m_pMatchingRecvProp = (struct RecvProp *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014D350
// Name: void CreateNetworkStringTables_GameRules(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateNetworkStringTables_GameRules()
{
  _S2_127.m_Type = (SendPropType)networkstringtable->CreateStringTable(
                                   this: networkstringtable,
                                   a2: "GameRulesCreation",
                                   a3: 1,
                                   a4: 0,
                                   a5: 0,
                                   a6: 0);
  CreateBlackMarketString();
}

//------------------------------------------------------------------------------
// Address: 0x1014D380
// Name: void CreateGameRulesObject(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateGameRulesObject(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const char *pClassName)
{
  struct RecvProp *m_pMatchingRecvProp; // esi

  if ( g_pGameRules != nullptr )
    ((void (__thiscall *)(CGameRules *, int))g_pGameRules->dtr_IGameSystem)(a1: g_pGameRules, a2: 1);
  m_pMatchingRecvProp = _S2_127.m_pMatchingRecvProp;
  g_pGameRules = nullptr;
  if ( _S2_127.m_pMatchingRecvProp != nullptr )
  {
    while ( _V_stricmp(s1: pClassName, s2: *(const char **)m_pMatchingRecvProp) != 0 )
    {
      m_pMatchingRecvProp = *((struct RecvProp **)m_pMatchingRecvProp + 2);
      if ( m_pMatchingRecvProp == nullptr )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    m_pMatchingRecvProp = nullptr;
    _Error(this: (ISceneTokenProcessor *)&stru_1047CE24, a2: pClassName);
  }
  (*((void (__stdcall **)(int, int, int))m_pMatchingRecvProp + 1))(a1: a2, a2: a3, a3: a1);
  if ( g_pGameRules == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_1047CDF0, a2: pClassName);
  strlen(pClassName);
  (*(void (__thiscall **)(SendPropType, int))(*(_DWORD *)_S2_127.m_Type + 32))(a1: _S2_127.m_Type, a2: 1);
  if ( g_pGameRules != nullptr )
    g_pGameRules->CreateCustomNetworkStringTables(this: g_pGameRules);
}

} // namespace server
