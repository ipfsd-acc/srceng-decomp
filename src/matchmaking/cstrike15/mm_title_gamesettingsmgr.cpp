// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/cstrike15/mm_title_gamesettingsmgr.cpp
// Functions: 43
// ============================================================

#include "matchmaking\cstrike15\mm_title_gamesettingsmgr.h"

//------------------------------------------------------------------------------
// Address: 0x100018F0
// Name: public: class INetSupport __near * CMatchExtensions::GetINetSupport(void)
// Source: json
//------------------------------------------------------------------------------
INetSupport *__thiscall CMatchExtensions::GetINetSupport(CMatchExtensions *this)
{
  return this->m_exts.m_pINetSupport;
}

//------------------------------------------------------------------------------
// Address: 0x10001900
// Name: public: INetSupport::ServerInfo_t::ServerInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
INetSupport::ServerInfo_t *__thiscall INetSupport::ServerInfo_t::ServerInfo_t(INetSupport::ServerInfo_t *this)
{
  netadr_s::SetIP(this: &this->m_netAdr, unIP: 0);
  netadr_s::SetPort(this: &this->m_netAdr, newport: 0);
  netadr_s::SetType(this: &this->m_netAdr, newtype: NA_IP);
  netadr_s::SetIP(this: &this->m_netAdrOnline, unIP: 0);
  netadr_s::SetPort(this: &this->m_netAdrOnline, newport: 0);
  netadr_s::SetType(this: &this->m_netAdrOnline, newtype: NA_IP);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001940
// Name: public: virtual void CMatchTitleGameSettingsMgr::ExtendLobbyDetailsTemplate(class KeyValues __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitleGameSettingsMgr::ExtendLobbyDetailsTemplate(
        CMatchTitleGameSettingsMgr *this,
        KeyValues *pDetails,
        const char *szReason,
        KeyValues *pFullSettings)
{
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    pkvExt = KeyValues::FromString(
               szName: "settings",
               szStringVal: " game {  bspname #empty#  mode #empty#  type #empty#  } ",
               ppEndOfParse: nullptr);
  }
  KeyValues::MergeFrom(this: pDetails, kvMerge: pkvExt, eOp: MERGE_KV_UPDATE);
}

//------------------------------------------------------------------------------
// Address: 0x10001980
// Name: public: virtual void CMatchTitleGameSettingsMgr::ExtendGameSettingsForLobbyTransition(class KeyValues __near *,class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitleGameSettingsMgr::ExtendGameSettingsForLobbyTransition(
        CMatchTitleGameSettingsMgr *this,
        KeyValues *pSettings,
        KeyValues *pSettingsUpdate,
        bool bEndGame)
{
  KeyValues::SetString(this: pSettingsUpdate, keyName: "game/state", value: "lobby");
}

//------------------------------------------------------------------------------
// Address: 0x100019A0
// Name: public: virtual class KeyValues __near * CMatchTitleGameSettingsMgr::RollupGameDetails(class KeyValues __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchTitleGameSettingsMgr::RollupGameDetails(
        CMatchTitleGameSettingsMgr *this,
        KeyValues *pDetails,
        KeyValues *pRollup,
        KeyValues *pQuery)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100019B0
// Name: public: virtual void CMatchTitleGameSettingsMgr::InitializeGameSettings(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitleGameSettingsMgr::InitializeGameSettings(
        CMatchTitleGameSettingsMgr *this,
        int pSettings,
        const char *szReason)
{
  KeyValues *v3; // esi
  KeyValues *Key; // eax
  const char *String; // edi
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  unsigned int dwRichPresenceContext; // [esp+8h] [ebp-8h] BYREF
  int extraSpectators; // [esp+Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)pSettings;
  Key = KeyValues::FindKey(this: (KeyValues *)pSettings, keyName: "game", bCreate: true);
  if ( Key != nullptr )
    KeyValues::SetString(this: Key, keyName: "state", value: "lobby");
  if ( KeyValues::GetString(this: v3, keyName: "game/bspname", defaultValue: nullptr) == nullptr )
  {
    String = KeyValues::GetString(this: v3, keyName: "game/type", defaultValue: defaultValue);
    v6 = KeyValues::GetString(this: v3, keyName: "game/mode", defaultValue: defaultValue);
    if ( String != nullptr && v6 != nullptr )
    {
      v7 = g_pGameTypes->GetRandomMap(this: g_pGameTypes, a2: String, a3: v6);
      if ( v7 != nullptr )
        KeyValues::SetString(this: v3, keyName: "game/bspname", value: v7);
    }
  }
  v8 = KeyValues::GetString(this: v3, keyName: "game/bspname", defaultValue: nullptr);
  pSettings = 2;
  extraSpectators = 0;
  dwRichPresenceContext = 0xFFFF;
  if ( v8 != nullptr )
    g_pGameTypes->GetMapInfo(
      this: g_pGameTypes,
      a2: v8,
      a3: &pSettings,
      a4: &extraSpectators,
      a5: &dwRichPresenceContext);
  KeyValues::SetInt(this: v3, keyName: "members/numSlots", value: pSettings);
  KeyValues::SetInt(this: v3, keyName: "members/numExtraSpectatorSlots", value: extraSpectators);
  KeyValues::SetInt(this: v3, keyName: "game/mapRichPresence", value: dwRichPresenceContext);
}

//------------------------------------------------------------------------------
// Address: 0x10001AC0
// Name: public: virtual void CMatchTitleGameSettingsMgr::ExtendGameSettingsUpdateKeys(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitleGameSettingsMgr::ExtendGameSettingsUpdateKeys(
        CMatchTitleGameSettingsMgr *this,
        KeyValues *pSettings,
        KeyValues *pUpdateDeleteKeys)
{
  KeyValues *v3; // esi
  const char *String; // eax
  int numSlots; // [esp+4h] [ebp-8h] BYREF
  unsigned int dwRichPresenceContext; // [esp+8h] [ebp-4h] BYREF

  v3 = pSettings;
  String = KeyValues::GetString(this: pSettings, keyName: "game/bspname", defaultValue: nullptr);
  numSlots = 2;
  pSettings = nullptr;
  dwRichPresenceContext = 0xFFFF;
  if ( String != nullptr )
    g_pGameTypes->GetMapInfo(
      this: g_pGameTypes,
      a2: String,
      a3: &numSlots,
      a4: (int *)&pSettings,
      a5: &dwRichPresenceContext);
  KeyValues::SetInt(this: v3, keyName: "members/numExtraSpectatorSlots", value: (int)pSettings);
}

//------------------------------------------------------------------------------
// Address: 0x10001B30
// Name: public: virtual class KeyValues __near * CMatchTitleGameSettingsMgr::PrepareForSessionCreate(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchTitleGameSettingsMgr::PrepareForSessionCreate(
        CMatchTitleGameSettingsMgr *this,
        KeyValues *pSettings)
{
  return (KeyValues *)CBaseAppSystem<IMatchFramework>::GetDependencies((ConVar *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10001B50
// Name: public: virtual void CMatchTitleGameSettingsMgr::ExecuteCommand(class KeyValues __near *,class KeyValues __near *,class KeyValues __near *,class KeyValues __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitleGameSettingsMgr::ExecuteCommand(
        CMatchTitleGameSettingsMgr *this,
        KeyValues *pCommand,
        KeyValues *pSessionSystemData,
        KeyValues *pSettings,
        KeyValues **ppPlayersUpdated)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001B60
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 32;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001BF0
// Name: public: virtual void CMatchTitleGameSettingsMgr::ExtendServerDetails(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitleGameSettingsMgr::ExtendServerDetails(
        CMatchTitleGameSettingsMgr *this,
        KeyValues *pDetails,
        KeyValues *pRequest)
{
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+4h] [ebp-13Ch] BYREF
  INetSupport::ServerInfo_t v5; // [esp+110h] [ebp-30h] BYREF

  netadr_s::SetIP(this: &v5.m_netAdr, unIP: 0);
  netadr_s::SetPort(this: &v5.m_netAdr, newport: 0);
  netadr_s::SetType(this: &v5.m_netAdr, newtype: NA_IP);
  netadr_s::SetIP(this: &v5.m_netAdrOnline, unIP: 0);
  netadr_s::SetPort(this: &v5.m_netAdrOnline, newport: 0);
  netadr_s::SetType(this: &v5.m_netAdrOnline, newtype: NA_IP);
  g_pMatchExtensions->m_exts.m_pINetSupport->GetServerInfo(this: g_pMatchExtensions->m_exts.m_pINetSupport, a2: &v5);
  KeyValues::SetString(this: pDetails, keyName: "game/state", value: "game");
  v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "%s", v5.m_szMapName);
  KeyValues::SetString(this: pDetails, keyName: "game/bspname", value: v3->m_szBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10001C90
// Name: public: virtual class KeyValues __near * CMatchTitleGameSettingsMgr::DefineDedicatedSearchKeys(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchTitleGameSettingsMgr::DefineDedicatedSearchKeys(
        CMatchTitleGameSettingsMgr *this,
        KeyValues *pSettings)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  char *m_pszString; // edi
  int v5; // eax
  CFmtStrN<256> *v6; // eax
  CFmtStrN<256> v8; // [esp+0h] [ebp-10Ch] BYREF

  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    ConVarRef::ConVarRef(this: &sv_search_key, pName: "sv_search_key");
  }
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SearchKeys");
  else
    v3 = nullptr;
  m_pszString = sv_search_key.m_pConVarState->m_Value.m_pszString;
  v5 = g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport);
  v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "%s,sv_search_key_%s%d", "empty", m_pszString, v5);
  KeyValues::SetString(this: v3, keyName: "gametype", value: v6->m_szBuf);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001F20
// Name: public: virtual class KeyValues __near * CMatchTitleGameSettingsMgr::PrepareTeamLinkForGame(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchTitleGameSettingsMgr::PrepareTeamLinkForGame(
        CMatchTitleGameSettingsMgr *this,
        KeyValues *pSettingsLocal,
        KeyValues *pDisconnectInfo)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
// Name: protected: void CMatchTitleGameSettingsMgr::LoadMatchSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitleGameSettingsMgr::LoadMatchSettings(CMatchTitleGameSettingsMgr *this)
{
  CMatchTitleGameSettingsMgr *v1; // ebx
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // eax
  KeyValues *m_pMatchSystemData; // ecx
  int Int; // eax
  KeyValues *Key; // esi
  int v8; // ebx
  CFmtStrN<256> *v9; // eax
  const char *i; // eax
  CFmtStrN<256> *v11; // eax
  int v12; // eax
  KeyValues *v13; // eax
  CMatchTitleGameSettingsMgr::SkillFormulas **m_pMemory; // edx
  CMatchTitleGameSettingsMgr::SkillFormulas *v15; // esi
  CUtlString *v16; // eax
  CMatchTitleGameSettingsMgr *v17; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_FormulaSkill; // ebx
  CFmtStrN<256> *v19; // eax
  CUtlMemory<CMatchSearcher::SearchResult_t,int> *v20; // eax
  CUtlMemory<CMatchSearcher::SearchResult_t,int> *v21; // esi
  CFmtStrN<256> *v22; // eax
  const char *j; // eax
  CMatchSearcher::SearchResult_t *v24; // edi
  int m_nAllocationCount; // eax
  CMatchSearcher::SearchResult_t *v26; // ecx
  int v27; // eax
  CUtlString *v28; // edi
  CFmtStrN<256> *v29; // eax
  KeyValues *v30; // edi
  CUtlSymbolTable::StringPool_t **v31; // edi
  int v32; // eax
  CUtlSymbolTable::StringPool_t **v33; // ecx
  int v34; // eax
  CUtlMemory<CMatchSearcher::SearchResult_t,int> **v35; // edi
  CFmtStrN<256> *v36; // eax
  KeyValues *v37; // esi
  int v38; // ebx
  CFmtStrN<256> *v39; // eax
  const char *k; // eax
  _DWORD *v41; // esi
  int m_Size; // edi
  int v43; // eax
  int v44; // ecx
  int v45; // eax
  CUtlString *v46; // edi
  CFmtStrN<256> *v47; // eax
  CMatchTitleGameSettingsMgr *v48; // esi
  int m; // ebx
  CMatchTitleGameSettingsMgr::SearchPass *v50; // esi
  int *v51; // eax
  bool *v52; // eax
  CFmtStrN<256> *v53; // eax
  KeyValues *v54; // ebx
  CMatchTitleGameSettingsMgr::SearchPass *v55; // eax
  CMatchTitleGameSettingsMgr::SearchPass *v56; // esi
  CFmtStrN<256> *v57; // eax
  int v58; // eax
  int v59; // ebx
  bool v60; // zf
  int v61; // eax
  bool *v62; // ecx
  int v63; // eax
  bool *v64; // eax
  CFmtStrN<256> *v65; // eax
  int v66; // eax
  int v67; // ebx
  int v68; // eax
  int *v69; // ecx
  int v70; // eax
  int *v71; // ebx
  int v72; // esi
  int v73; // eax
  _DWORD *v74; // edx
  int v75; // ecx
  int v76; // eax
  CMatchTitleGameSettingsMgr::SearchPass **v77; // eax
  CFmtStrN<256> *v78; // eax
  CFmtStrN<256> v79; // [esp+8h] [ebp-244h] BYREF
  CFmtStrN<256> v80; // [esp+114h] [ebp-138h] BYREF
  int v81; // [esp+220h] [ebp-2Ch]
  int nSearchPassIndex; // [esp+224h] [ebp-28h]
  CUtlString src; // [esp+228h] [ebp-24h] BYREF
  CMatchTitleGameSettingsMgr::SearchPass *pSearchPass; // [esp+238h] [ebp-14h]
  bool v85; // [esp+23Fh] [ebp-Dh]
  KeyValues *pSearchPassInfo; // [esp+240h] [ebp-Ch]
  int nSkillIndex; // [esp+244h] [ebp-8h]
  CMatchTitleGameSettingsMgr *v88; // [esp+248h] [ebp-4h]

  v1 = this;
  v88 = this;
  if ( this->m_pMatchSystemData == nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: defaultValue);
    else
      v3 = nullptr;
    v1->m_pMatchSystemData = v3;
  }
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v1->m_pMatchSystemData,
          filesystem: v4,
          resourceName: "resource\\MatchSystem.360.res",
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr) )
  {
    KeyValues::deleteThis(this: v1->m_pMatchSystemData);
    v1->m_pMatchSystemData = nullptr;
  }
  m_pMatchSystemData = v1->m_pMatchSystemData;
  if ( m_pMatchSystemData != nullptr )
  {
    Int = KeyValues::GetInt(this: m_pMatchSystemData, keyName: "version", defaultValue: -1);
    if ( v1->m_nMatchSystemDataVersion < Int )
    {
      v1->m_nMatchSystemDataVersion = Int;
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::Purge(this: &v1->m_FormulaExperience);
      Key = KeyValues::FindKey(this: v1->m_pMatchSystemData, keyName: "ExperienceFormula", bCreate: false);
      if ( Key != nullptr )
      {
        v8 = 0;
        v9 = CFmtStrN<256>::CFmtStrN<256>(this: &v80, pszFormat: "%d", 0);
        for ( i = KeyValues::GetString(this: Key, keyName: v9->m_szBuf, defaultValue: nullptr);
              i != nullptr;
              i = KeyValues::GetString(this: Key, keyName: v11->m_szBuf, defaultValue: nullptr) )
        {
          if ( *i == 0 )
            break;
          CUtlString::CUtlString(this: &src, pString: i);
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
            this: &v88->m_FormulaExperience,
            elem: v88->m_FormulaExperience.m_Size,
            &src);
          src.m_Storage.m_nActualLength = 0;
          if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
              src.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            src.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = CFmtStrN<256>::CFmtStrN<256>(this: &v80, pszFormat: "%d", ++v8);
        }
        v12 = KeyValues::GetInt(this: Key, keyName: "minvalue", defaultValue: 0);
        v1 = v88;
        v88->m_nFormulaExperienceRangeMin = v12;
        v1->m_nFormulaExperienceRangeMax = KeyValues::GetInt(this: Key, keyName: "maxvalue", defaultValue: 0x7FFFFFFF);
      }
      v13 = nullptr;
      for ( pSearchPassInfo = nullptr; (int)v13 < v1->m_FormulaSkill.m_Size; pSearchPassInfo = v13 )
      {
        m_pMemory = v1->m_FormulaSkill.m_Memory.m_pMemory;
        v15 = m_pMemory[(_DWORD)v13];
        if ( v15 != nullptr )
        {
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &m_pMemory[(_DWORD)v13]->formulas);
          if ( v15->formulas.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v15->formulas.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15->formulas.m_Memory.m_pMemory);
              v15->formulas.m_Memory.m_pMemory = nullptr;
            }
            v15->formulas.m_Memory.m_nAllocationCount = 0;
          }
          v16 = v15->formulas.m_Memory.m_pMemory;
          v15->formulas.m_pElements = v15->formulas.m_Memory.m_pMemory;
          if ( v15->formulas.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v16 != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
              v15->formulas.m_Memory.m_pMemory = nullptr;
            }
            v15->formulas.m_Memory.m_nAllocationCount = 0;
          }
          free(pMem: v15);
          v13 = pSearchPassInfo;
        }
        v13 = (KeyValues *)((char *)v13 + 1);
      }
      v17 = v88;
      p_m_FormulaSkill = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v88->m_FormulaSkill;
      v88->m_FormulaSkill.m_Size = 0;
      if ( p_m_FormulaSkill->m_nGrowSize >= 0 )
      {
        if ( p_m_FormulaSkill->m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_FormulaSkill->m_pMemory);
          p_m_FormulaSkill->m_pMemory = nullptr;
        }
        p_m_FormulaSkill->m_nAllocationCount = 0;
      }
      p_m_FormulaSkill[1].m_nAllocationCount = (int)p_m_FormulaSkill->m_pMemory;
      pSearchPass = nullptr;
      v19 = CFmtStrN<256>::CFmtStrN<256>(this: &v79, pszFormat: "Skill%dFormula", 0);
      for ( nSkillIndex = (int)KeyValues::FindKey(this: v17->m_pMatchSystemData, keyName: v19->m_szBuf, bCreate: false);
            nSkillIndex != 0;
            nSkillIndex = (int)KeyValues::FindKey(this: v88->m_pMatchSystemData, keyName: v36->m_szBuf, bCreate: false) )
      {
        v20 = (CUtlMemory<CMatchSearcher::SearchResult_t,int> *)operator new(nSize: 0x1Cu);
        if ( v20 != nullptr )
        {
          v20->m_pMemory = nullptr;
          v20->m_nAllocationCount = 0;
          v20->m_nGrowSize = 0;
          v20[1].m_pMemory = nullptr;
          v20[1].m_nAllocationCount = 0;
          v21 = v20;
        }
        else
        {
          v21 = nullptr;
        }
        pSearchPassInfo = nullptr;
        v22 = CFmtStrN<256>::CFmtStrN<256>(this: &v80, pszFormat: "%d", 0);
        for ( j = KeyValues::GetString(this: (KeyValues *)nSkillIndex, keyName: v22->m_szBuf, defaultValue: nullptr);
              j != nullptr;
              j = KeyValues::GetString(this: (KeyValues *)nSkillIndex, keyName: v29->m_szBuf, defaultValue: nullptr) )
        {
          if ( *j == 0 )
            break;
          CUtlString::CUtlString(this: &src, pString: j);
          v24 = v21[1].m_pMemory;
          m_nAllocationCount = v21->m_nAllocationCount;
          if ( (int)&v24->m_uiLobbyId + 1 > m_nAllocationCount )
            CUtlMemory<CMatchSearcher::SearchResult_t,int>::Grow(
              this: v21,
              num: (int)&v24->m_uiLobbyId - m_nAllocationCount + 1);
          ++v21[1].m_pMemory;
          v26 = v21->m_pMemory;
          v27 = (char *)v21[1].m_pMemory - (char *)v24 - 1;
          v21[1].m_nAllocationCount = (int)v21->m_pMemory;
          if ( v27 > 0 )
            _V_memmove(dest: (void *)&v26[(int)v24 + 1], src: &v26[(_DWORD)v24], count: 16 * v27);
          v28 = (CUtlString *)&v21->m_pMemory[(_DWORD)v24];
          if ( v28 != nullptr )
            CUtlString::CUtlString(this: v28, string: &src);
          src.m_Storage.m_nActualLength = 0;
          if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
              src.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            src.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          pSearchPassInfo = (KeyValues *)((char *)pSearchPassInfo + 1);
          v29 = CFmtStrN<256>::CFmtStrN<256>(this: &v80, pszFormat: "%d", pSearchPassInfo);
        }
        v30 = (KeyValues *)nSkillIndex;
        v21[1].m_nGrowSize = KeyValues::GetInt(this: (KeyValues *)nSkillIndex, keyName: "minvalue", defaultValue: 0);
        v21[2].m_pMemory = (CMatchSearcher::SearchResult_t *)KeyValues::GetInt(
                                                               this: v30,
                                                               keyName: "maxvalue",
                                                               defaultValue: 0x7FFFFFFF);
        v31 = p_m_FormulaSkill[1].m_pMemory;
        v32 = p_m_FormulaSkill->m_nAllocationCount;
        if ( (int)v31 + 1 > v32 )
          CUtlMemory<GCSDK::CLock *,int>::Grow(this: p_m_FormulaSkill, num: (int)v31 - v32 + 1);
        ++p_m_FormulaSkill[1].m_pMemory;
        v33 = p_m_FormulaSkill->m_pMemory;
        v34 = (char *)p_m_FormulaSkill[1].m_pMemory - (char *)v31 - 1;
        p_m_FormulaSkill[1].m_nAllocationCount = (int)p_m_FormulaSkill->m_pMemory;
        if ( v34 > 0 )
          _V_memmove(dest: &v33[(_DWORD)v31 + 1], src: &v33[(_DWORD)v31], count: 4 * v34);
        v35 = (CUtlMemory<CMatchSearcher::SearchResult_t,int> **)&p_m_FormulaSkill->m_pMemory[(_DWORD)v31];
        if ( v35 != nullptr )
          *v35 = v21;
        pSearchPass = (CMatchTitleGameSettingsMgr::SearchPass *)((char *)pSearchPass + 1);
        v36 = CFmtStrN<256>::CFmtStrN<256>(this: &v79, pszFormat: "Skill%dFormula", pSearchPass);
      }
      v37 = KeyValues::FindKey(this: v88->m_pMatchSystemData, keyName: "AvgFormula", bCreate: false);
      nSearchPassIndex = (int)v37;
      if ( v37 != nullptr )
      {
        v38 = 0;
        v39 = CFmtStrN<256>::CFmtStrN<256>(this: &v79, pszFormat: "%d", 0);
        for ( k = KeyValues::GetString(this: v37, keyName: v39->m_szBuf, defaultValue: nullptr);
              k != nullptr;
              k = KeyValues::GetString(
                    this: (KeyValues *)nSearchPassIndex,
                    keyName: v47->m_szBuf,
                    defaultValue: nullptr) )
        {
          if ( *k == 0 )
            break;
          CUtlString::CUtlString(this: &src, pString: k);
          v41 = &v88->__vftable;
          m_Size = v88->m_FormulaAverage.m_Size;
          v43 = v88->m_FormulaAverage.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > v43 )
            CUtlMemory<CMatchSearcher::SearchResult_t,int>::Grow(
              this: (CUtlMemory<CMatchSearcher::SearchResult_t,int> *)&v88->m_FormulaAverage,
              num: m_Size - v43 + 1);
          ++v41[6];
          v44 = v41[3];
          v45 = v41[6] - m_Size - 1;
          v41[7] = v44;
          if ( v45 > 0 )
            _V_memmove(dest: (void *)(16 * m_Size + v44 + 16), src: (const void *)(16 * m_Size + v44), count: 16 * v45);
          v46 = (CUtlString *)(v41[3] + 16 * m_Size);
          if ( v46 != nullptr )
            CUtlString::CUtlString(this: v46, string: &src);
          src.m_Storage.m_nActualLength = 0;
          if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
              src.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            src.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v47 = CFmtStrN<256>::CFmtStrN<256>(this: &v79, pszFormat: "%d", ++v38);
        }
      }
      v48 = v88;
      for ( m = 0; m < v88->m_SearchPass.m_Size; v48 = v88 )
      {
        v50 = v48->m_SearchPass.m_Memory.m_pMemory[m];
        if ( v50 != nullptr )
        {
          v50->skillRange.m_Size = 0;
          if ( v50->skillRange.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v50->skillRange.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50->skillRange.m_Memory.m_pMemory);
              v50->skillRange.m_Memory.m_pMemory = nullptr;
            }
            v50->skillRange.m_Memory.m_nAllocationCount = 0;
          }
          v51 = v50->skillRange.m_Memory.m_pMemory;
          v50->skillRange.m_pElements = v51;
          if ( v50->skillRange.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v51 != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v51);
              v50->skillRange.m_Memory.m_pMemory = nullptr;
            }
            v50->skillRange.m_Memory.m_nAllocationCount = 0;
          }
          v50->checkSkill.m_Size = 0;
          if ( v50->checkSkill.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v50->checkSkill.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50->checkSkill.m_Memory.m_pMemory);
              v50->checkSkill.m_Memory.m_pMemory = nullptr;
            }
            v50->checkSkill.m_Memory.m_nAllocationCount = 0;
          }
          v52 = v50->checkSkill.m_Memory.m_pMemory;
          v50->checkSkill.m_pElements = v52;
          if ( v50->checkSkill.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v52 != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v52);
              v50->checkSkill.m_Memory.m_pMemory = nullptr;
            }
            v50->checkSkill.m_Memory.m_nAllocationCount = 0;
          }
          free(pMem: v50);
        }
        ++m;
      }
      v48->m_SearchPass.m_Size = 0;
      if ( v48->m_SearchPass.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v48->m_SearchPass.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v48->m_SearchPass.m_Memory.m_pMemory);
          v48->m_SearchPass.m_Memory.m_pMemory = nullptr;
        }
        v48->m_SearchPass.m_Memory.m_nAllocationCount = 0;
      }
      v48->m_SearchPass.m_pElements = v48->m_SearchPass.m_Memory.m_pMemory;
      nSearchPassIndex = 0;
      v53 = CFmtStrN<256>::CFmtStrN<256>(this: &v79, pszFormat: "SearchPass%d", 0);
      v54 = KeyValues::FindKey(this: v48->m_pMatchSystemData, keyName: v53->m_szBuf, bCreate: false);
      for ( pSearchPassInfo = v54; v54 != nullptr; pSearchPassInfo = v54 )
      {
        v55 = (CMatchTitleGameSettingsMgr::SearchPass *)operator new(nSize: 0x30u);
        if ( v55 != nullptr )
        {
          v55->checkSkill.m_Memory.m_pMemory = nullptr;
          v55->checkSkill.m_Memory.m_nAllocationCount = 0;
          v55->checkSkill.m_Memory.m_nGrowSize = 0;
          v55->checkSkill.m_Size = 0;
          v55->checkSkill.m_pElements = nullptr;
          v55->skillRange.m_Memory.m_pMemory = nullptr;
          v55->skillRange.m_Memory.m_nAllocationCount = 0;
          v55->skillRange.m_Memory.m_nGrowSize = 0;
          v55->skillRange.m_Size = 0;
          v55->skillRange.m_pElements = nullptr;
          v56 = v55;
          pSearchPass = v55;
        }
        else
        {
          v56 = nullptr;
          pSearchPass = nullptr;
        }
        v56->checkExperience = KeyValues::GetInt(this: v54, keyName: "ExpCheck", defaultValue: 0) != 0;
        v56->experienceRange = KeyValues::GetInt(this: v54, keyName: "ExperienceRange", defaultValue: 0);
        for ( nSkillIndex = 0; nSkillIndex < 5; ++nSkillIndex )
        {
          v57 = CFmtStrN<256>::CFmtStrN<256>(this: &v80, pszFormat: "Skill%dCheck", nSkillIndex);
          v58 = KeyValues::GetInt(this: pSearchPassInfo, keyName: v57->m_szBuf, defaultValue: 0);
          v59 = v56->checkSkill.m_Size;
          v60 = v58 == 0;
          v61 = v56->checkSkill.m_Memory.m_nAllocationCount;
          v85 = !v60;
          if ( v59 + 1 > v61 )
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&v56->checkSkill, num: v59 - v61 + 1);
          ++v56->checkSkill.m_Size;
          v62 = v56->checkSkill.m_Memory.m_pMemory;
          v63 = v56->checkSkill.m_Size - v59 - 1;
          v56->checkSkill.m_pElements = v62;
          if ( v63 > 0 )
            _V_memmove(dest: &v62[v59 + 1], src: &v62[v59], count: v63);
          v64 = &v56->checkSkill.m_Memory.m_pMemory[v59];
          if ( v64 != nullptr )
            *v64 = v85;
          v65 = CFmtStrN<256>::CFmtStrN<256>(this: &v80, pszFormat: "Skill%dRange", nSkillIndex);
          v66 = KeyValues::GetInt(this: pSearchPassInfo, keyName: v65->m_szBuf, defaultValue: 0);
          v67 = v56->skillRange.m_Size;
          v81 = v66;
          v68 = v56->skillRange.m_Memory.m_nAllocationCount;
          if ( v67 + 1 > v68 )
            CUtlMemory<GCSDK::CLock *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v56->skillRange,
              num: v67 - v68 + 1);
          ++v56->skillRange.m_Size;
          v69 = v56->skillRange.m_Memory.m_pMemory;
          v70 = v56->skillRange.m_Size - v67 - 1;
          v56->skillRange.m_pElements = v69;
          if ( v70 > 0 )
            _V_memmove(dest: &v69[v67 + 1], src: &v69[v67], count: 4 * v70);
          v71 = &v56->skillRange.m_Memory.m_pMemory[v67];
          if ( v71 != nullptr )
            *v71 = v81;
        }
        v72 = v88->m_SearchPass.m_Size;
        v73 = v88->m_SearchPass.m_Memory.m_nAllocationCount;
        if ( v72 + 1 > v73 )
          CUtlMemory<GCSDK::CLock *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v88->m_SearchPass,
            num: v72 - v73 + 1);
        v74 = &v88->__vftable;
        ++v88->m_SearchPass.m_Size;
        v75 = v74[20];
        v76 = v74[23] - v72 - 1;
        v74[24] = v75;
        if ( v76 > 0 )
          _V_memmove(dest: (void *)(v75 + 4 * v72 + 4), src: (const void *)(v75 + 4 * v72), count: 4 * v76);
        v77 = &v88->m_SearchPass.m_Memory.m_pMemory[v72];
        if ( v77 != nullptr )
          *v77 = pSearchPass;
        v78 = CFmtStrN<256>::CFmtStrN<256>(this: &v79, pszFormat: "SearchPass%d", ++nSearchPassIndex);
        v54 = KeyValues::FindKey(this: v88->m_pMatchSystemData, keyName: v78->m_szBuf, bCreate: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002780
// Name: public: virtual char const __near * CMatchTitleGameSettingsMgr::GetFormulaAverage(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMatchTitleGameSettingsMgr::GetFormulaAverage(CMatchTitleGameSettingsMgr *this, int index)
{
  int m_Size; // eax
  int v5; // eax

  CMatchTitleGameSettingsMgr::LoadMatchSettings(this);
  m_Size = this->m_FormulaAverage.m_Size;
  if ( m_Size == 0 )
    return "newValue";
  v5 = m_Size - 1;
  if ( index < 0 )
    return CUtlString::operator char const *(this: this->m_FormulaAverage.m_Memory.m_pMemory);
  if ( index <= v5 )
    v5 = index;
  return CUtlString::operator char const *(this: &this->m_FormulaAverage.m_Memory.m_pMemory[v5]);
}

//------------------------------------------------------------------------------
// Address: 0x100027D0
// Name: public: virtual class KeyValues __near * CMatchTitleGameSettingsMgr::DefineSessionSearchKeys(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchTitleGameSettingsMgr::DefineSessionSearchKeys(
        CMatchTitleGameSettingsMgr *this,
        KeyValues *pSettings)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  int Int; // eax
  const char *String; // eax
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  int v9; // [esp+Ch] [ebp-4h]

  DevMsg(a1: "DefineSessionSearchKeys settings:\n");
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v9 = 1;
  KeyValues::Dump(this: pSettings, &pDump, nIndentLevel: 1);
  CMatchTitleGameSettingsMgr::LoadMatchSettings(this);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "SessionSearch");
  else
    v4 = nullptr;
  Int = KeyValues::GetInt(this: pSettings, keyName: "members/numPlayers", defaultValue: 1);
  KeyValues::SetInt(this: v4, keyName: "numPlayers", value: Int);
  String = KeyValues::GetString(this: pSettings, keyName: "game/bspname", defaultValue: nullptr);
  if ( String != nullptr )
    KeyValues::SetString(this: v4, keyName: "Filter=/game:bspname", value: String);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10053C70
// Name: _dynamic_initializer_for__game_type__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_type__()
{
  ConVar::ConVar(
    this: &game_type,
    pName: "game_type",
    pDefaultValue: "0",
    flags: 8204,
    pHelpString: "The current game type. See GameModes.txt.");
  return atexit(func: dynamic_atexit_destructor_for__game_type__);
}

//------------------------------------------------------------------------------
// Address: 0x10053CA0
// Name: _dynamic_initializer_for__game_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_mode__()
{
  ConVar::ConVar(
    this: &game_mode,
    pName: "game_mode",
    pDefaultValue: "0",
    flags: 8204,
    pHelpString: "The current game mode (based on game type). See GameModes.txt.");
  return atexit(func: dynamic_atexit_destructor_for__game_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10053D00
// Name: _dynamic_initializer_for__game_mode_convars__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_mode_convars__()
{
  ConCommand::ConCommand(
    this: &game_mode_convars,
    pName: "game_mode_convars",
    callback: DisplayGameModeConvars,
    pHelpString: "Display the values of the convars for the current game_mode.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__game_mode_convars__);
}

//------------------------------------------------------------------------------
// Address: 0x10054DE0
// Name: _dynamic_atexit_destructor_for__game_type__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__game_type__()
{
  ConVar::~ConVar(this: &game_type);
}

//------------------------------------------------------------------------------
// Address: 0x10054DF0
// Name: _dynamic_atexit_destructor_for__game_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__game_mode__()
{
  ConVar::~ConVar(this: &game_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10054E10
// Name: _dynamic_atexit_destructor_for__game_mode_convars__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__game_mode_convars__()
{
  ConCommand::~ConCommand(this: &game_mode_convars);
}

//------------------------------------------------------------------------------
// Address: 0x10053CD0
// Name: _dynamic_initializer_for__freestyle_bot_difficulty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__freestyle_bot_difficulty__()
{
  ConVar::ConVar(
    this: &freestyle_bot_difficulty,
    pName: "freestyle_bot_difficulty",
    pDefaultValue: "0",
    flags: 8204,
    pHelpString: "Bot difficulty for freestyle.");
  return atexit(func: dynamic_atexit_destructor_for__freestyle_bot_difficulty__);
}

//------------------------------------------------------------------------------
// Address: 0x10053D30
// Name: _dynamic_initializer_for__s_GameTypes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GameTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_GameTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x10053D40
// Name: _dynamic_initializer_for____g_CreateGameTypesIGameTypes_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateGameTypesIGameTypes_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateGameTypesIGameTypes_reg,
           fn: _CreateGameTypesIGameTypes_interface,
           pName: "VENGINE_GAMETYPES_VERSION001");
}

//------------------------------------------------------------------------------
// Address: 0x10053D60
// Name: _dynamic_initializer_for__g_MatchExtensions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatchExtensions__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_MatchExtensions.m_mapRegisteredInterfaces.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  *(_QWORD *)&g_MatchExtensions.m_exts.m_pILocalize = 0;
  *(_QWORD *)&g_MatchExtensions.m_exts.m_pIEngineVoice = 0;
  *(_QWORD *)&g_MatchExtensions.m_exts.m_pIVEngineServer = 0;
  g_MatchExtensions.m_exts.m_pIGameEventManager2 = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_MatchExtensions__);
}

//------------------------------------------------------------------------------
// Address: 0x10053DB0
// Name: _dynamic_initializer_for__g_GCClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GCClient__()
{
  GCSDK::CGCClient::CGCClient(this: &g_GCClient, pSteamGameCoordinator: nullptr, bGameserver: false);
  return atexit(func: dynamic_atexit_destructor_for__g_GCClient__);
}

//------------------------------------------------------------------------------
// Address: 0x10053DD0
// Name: _dynamic_initializer_for__mm_player_search_update_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_player_search_update_interval__()
{
  ConVar::ConVar(
    this: &mm_player_search_update_interval,
    pName: "mm_player_search_update_interval",
    pDefaultValue: "10",
    flags: 2,
    pHelpString: "Interval between players searches.");
  return atexit(func: dynamic_atexit_destructor_for__mm_player_search_update_interval__);
}

//------------------------------------------------------------------------------
// Address: 0x10053E00
// Name: _dynamic_initializer_for__mm_player_search_lan_ping_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_player_search_lan_ping_interval__()
{
  ConVar::ConVar(
    this: &mm_player_search_lan_ping_interval,
    pName: "mm_player_search_lan_ping_interval",
    pDefaultValue: "0.5",
    flags: 2,
    pHelpString: "Interval between LAN discovery pings.");
  return atexit(func: dynamic_atexit_destructor_for__mm_player_search_lan_ping_interval__);
}

//------------------------------------------------------------------------------
// Address: 0x10053E30
// Name: _dynamic_initializer_for__mm_player_search_lan_ping_duration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_player_search_lan_ping_duration__()
{
  ConVar::ConVar(
    this: &mm_player_search_lan_ping_duration,
    pName: "mm_player_search_lan_ping_duration",
    pDefaultValue: "3.5",
    flags: 2,
    pHelpString: "Duration of LAN discovery ping phase.");
  return atexit(func: dynamic_atexit_destructor_for__mm_player_search_lan_ping_duration__);
}

//------------------------------------------------------------------------------
// Address: 0x10053E60
// Name: _dynamic_initializer_for__g_PlayerManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PlayerManager__()
{
  PlayerManager::PlayerManager(this: &g_PlayerManager);
  return atexit(func: dynamic_atexit_destructor_for__g_PlayerManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10053E80
// Name: _dynamic_initializer_for__LOG_CONSOLE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_CONSOLE__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "Console",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_10);
  LOG_CONSOLE = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10053EA0
// Name: _dynamic_initializer_for__g_MatchFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatchFramework__()
{
  CMatchFramework::CMatchFramework(this: &g_MatchFramework);
  return atexit(func: dynamic_atexit_destructor_for__g_MatchFramework__);
}

//------------------------------------------------------------------------------
// Address: 0x10053EC0
// Name: _dynamic_initializer_for____g_CreateCMatchFrameworkIMatchFramework_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCMatchFrameworkIMatchFramework_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCMatchFrameworkIMatchFramework_reg,
           fn: _CreateCMatchFrameworkIMatchFramework_interface,
           pName: "MATCHFRAMEWORK_001");
}

//------------------------------------------------------------------------------
// Address: 0x10054E00
// Name: _dynamic_atexit_destructor_for__freestyle_bot_difficulty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__freestyle_bot_difficulty__()
{
  ConVar::~ConVar(this: &freestyle_bot_difficulty);
}

//------------------------------------------------------------------------------
// Address: 0x10054E20
// Name: _dynamic_atexit_destructor_for__s_GameTypes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GameTypes__()
{
  s_GameTypes.__vftable = (GameTypes_vtbl *)&GameTypes::`vftable';
  CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &s_GameTypes.m_GameTypes);
  CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &s_GameTypes.m_Maps);
  CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &s_GameTypes.m_FreestyleBotDifficulties);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_GameTypes.m_FreestyleBotDifficulties);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_GameTypes.m_Maps);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_GameTypes.m_GameTypes);
  s_GameTypes.__vftable = (GameTypes_vtbl *)&IGameTypes::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10054E80
// Name: _dynamic_atexit_destructor_for__g_MatchExtensions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchExtensions__()
{
  g_MatchExtensions.__vftable = (CMatchExtensions_vtbl *)&CMatchExtensions::`vftable';
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_MatchExtensions.m_mapRegisteredInterfaces.m_SymbolTable);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchExtensions.m_mapRegisteredInterfaces);
}

//------------------------------------------------------------------------------
// Address: 0x10054EA0
// Name: _dynamic_atexit_destructor_for__g_GCClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GCClient__()
{
  GCSDK::CGCClient::~CGCClient(this: &g_GCClient);
}

//------------------------------------------------------------------------------
// Address: 0x10054EB0
// Name: _dynamic_atexit_destructor_for__mm_player_search_update_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_player_search_update_interval__()
{
  ConVar::~ConVar(this: &mm_player_search_update_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10054EC0
// Name: _dynamic_atexit_destructor_for__mm_player_search_lan_ping_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_player_search_lan_ping_interval__()
{
  ConVar::~ConVar(this: &mm_player_search_lan_ping_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10054ED0
// Name: _dynamic_atexit_destructor_for__mm_player_search_lan_ping_duration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_player_search_lan_ping_duration__()
{
  ConVar::~ConVar(this: &mm_player_search_lan_ping_duration);
}

//------------------------------------------------------------------------------
// Address: 0x10054EE0
// Name: _dynamic_atexit_destructor_for__g_PlayerManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PlayerManager__()
{
  PlayerManager::~PlayerManager(this: &g_PlayerManager);
}

//------------------------------------------------------------------------------
// Address: 0x10054EF0
// Name: _dynamic_atexit_destructor_for__g_MatchFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchFramework__()
{
  CMatchFramework::~CMatchFramework(this: &g_MatchFramework);
}
