// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/steam_lobbyapi.cpp
// Functions: 7
// ============================================================

#include "matchmaking\steam_lobbyapi.h"

//------------------------------------------------------------------------------
// Address: 0x1001C080
// Name: private: virtual void CCallResult<class CLeaderboardRequestQueue,struct LeaderboardFindResult_t>::Run(void __near *,bool,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallResult<CLeaderboardRequestQueue,LeaderboardFindResult_t>::Run(
        CCallResult<CLeaderboardRequestQueue,LeaderboardScoresDownloaded_t> *this,
        LeaderboardScoresDownloaded_t *pvParam,
        BOOL bIOFailure,
        unsigned __int64 hSteamAPICall)
{
  if ( hSteamAPICall == this->m_hAPICall )
  {
    this->m_hAPICall = 0;
    this->m_Func(this: this->m_pObj, a2: pvParam, a3: bIOFailure);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C0D0
// Name: public: CSteamLeaderboardWriter::~CSteamLeaderboardWriter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamLeaderboardWriter::~CSteamLeaderboardWriter(CSteamLeaderboardWriter *this)
{
  void *Ptr; // eax
  KeyValues *m_pViewDescription; // ecx
  KeyValues *m_pViewData; // ecx
  int m_hAPICall; // eax
  int m_hAPICall_high; // ecx
  bool v7; // zf
  int v8; // eax
  int v9; // ecx

  Ptr = KeyValues::GetPtr(this: this->m_pViewData, keyName: ":payloadptr", defaultValue: nullptr);
  free(pMem: Ptr);
  m_pViewDescription = this->m_pViewDescription;
  if ( m_pViewDescription != nullptr )
    KeyValues::deleteThis(this: m_pViewDescription);
  m_pViewData = this->m_pViewData;
  if ( m_pViewData != nullptr )
    KeyValues::deleteThis(this: m_pViewData);
  m_hAPICall = this->m_CallbackOnLeaderboardScoreUploaded.m_hAPICall;
  m_hAPICall_high = HIDWORD(this->m_CallbackOnLeaderboardScoreUploaded.m_hAPICall);
  v7 = this->m_CallbackOnLeaderboardScoreUploaded.m_hAPICall == 0;
  this->m_CallbackOnLeaderboardScoreUploaded.__vftable = (CCallResult<CSteamLeaderboardWriter,LeaderboardScoreUploaded_t>_vtbl *)&CCallResult<CSteamLeaderboardWriter,LeaderboardScoreUploaded_t>::`vftable';
  if ( !v7 )
  {
    _SteamAPI_UnregisterCallResult(a1: &this->m_CallbackOnLeaderboardScoreUploaded, a2: m_hAPICall, a3: m_hAPICall_high);
    LODWORD(this->m_CallbackOnLeaderboardScoreUploaded.m_hAPICall) = 0;
    HIDWORD(this->m_CallbackOnLeaderboardScoreUploaded.m_hAPICall) = 0;
  }
  v8 = this->m_CallbackOnLeaderboardFindResult.m_hAPICall;
  v9 = HIDWORD(this->m_CallbackOnLeaderboardFindResult.m_hAPICall);
  v7 = this->m_CallbackOnLeaderboardFindResult.m_hAPICall == 0;
  this->m_CallbackOnLeaderboardFindResult.__vftable = (CCallResult<CSteamLeaderboardWriter,LeaderboardFindResult_t>_vtbl *)&CCallResult<CSteamLeaderboardWriter,LeaderboardFindResult_t>::`vftable';
  if ( !v7 )
  {
    _SteamAPI_UnregisterCallResult(a1: this, a2: v8, a3: v9);
    LODWORD(this->m_CallbackOnLeaderboardFindResult.m_hAPICall) = 0;
    HIDWORD(this->m_CallbackOnLeaderboardFindResult.m_hAPICall) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C160
// Name: protected: void CSteamLeaderboardWriter::Steam_OnLeaderboardScoreUploaded(struct LeaderboardScoreUploaded_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamLeaderboardWriter::Steam_OnLeaderboardScoreUploaded(
        CSteamLeaderboardWriter *this,
        LeaderboardScoreUploaded_t *p,
        bool bError)
{
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  int m_nGlobalRankNew; // [esp-8h] [ebp-Ch]
  int m_nGlobalRankPrevious; // [esp-4h] [ebp-8h]

  if ( bError )
  {
    Name = KeyValues::GetName(this: this->m_pViewData);
    _Warning(a1: "Failed to upload leaderboard score for '%s'\n", Name);
  }
  else if ( p->m_bSuccess != 0 )
  {
    if ( p->m_bScoreChanged != 0 )
    {
      m_nGlobalRankPrevious = p->m_nGlobalRankPrevious;
      m_nGlobalRankNew = p->m_nGlobalRankNew;
      v7 = KeyValues::GetName(this: this->m_pViewData);
      DevMsg(
        a1: "Leaderboard score uploaded for '%s', new rank %d, old rank %d\n",
        v7,
        m_nGlobalRankNew,
        m_nGlobalRankPrevious);
    }
    else
    {
      v6 = KeyValues::GetName(this: this->m_pViewData);
      DevMsg(a1: "Leaderboard score uploaded, but not changed for '%s'\n", v6);
    }
  }
  else
  {
    v5 = KeyValues::GetName(this: this->m_pViewData);
    _Warning(a1: "Failed to update leaderboard score for '%s'\n", v5);
  }
  CSteamLeaderboardWriter::~CSteamLeaderboardWriter(this);
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x1001C200
// Name: protected: void CSteamLeaderboardWriter::Steam_OnLeaderboardFindResult(struct LeaderboardFindResult_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamLeaderboardWriter::Steam_OnLeaderboardFindResult(
        CSteamLeaderboardWriter *this,
        LeaderboardFindResult_t *p,
        bool bError)
{
  const char *Name; // eax
  const char *v5; // eax
  const char *String; // eax
  const char *v7; // eax
  ISteamUserStats *m_pSteamUserStats; // ebx
  ISteamUserStats_vtbl *v9; // edi
  int Int; // eax
  unsigned __int64 v11; // kr00_8
  int Uint64; // [esp+8h] [ebp-8h]
  void *pvPayloadPtr; // [esp+Ch] [ebp-4h]
  int nPayloadSize; // [esp+1Ch] [ebp+Ch]

  if ( bError )
  {
    Name = KeyValues::GetName(this: this->m_pViewData);
    _Warning(a1: "Failed to contact leaderboard server for '%s'\n", Name);
LABEL_3:
    CSteamLeaderboardWriter::~CSteamLeaderboardWriter(this);
    free(pMem: this);
    return;
  }
  if ( p->m_bLeaderboardFound == 0 )
  {
    v5 = KeyValues::GetName(this: this->m_pViewData);
    DevWarning(a1: "Leaderboard '%s' was not found on server\n", v5);
    goto LABEL_3;
  }
  String = KeyValues::GetString(this: this->m_pViewDescription, keyName: ":score", defaultValue: defaultValue);
  Uint64 = KeyValues::GetUint64(this: this->m_pViewData, keyName: String, defaultValue: 0);
  pvPayloadPtr = KeyValues::GetPtr(this: this->m_pViewData, keyName: ":payloadptr", defaultValue: nullptr);
  nPayloadSize = KeyValues::GetInt(this: this->m_pViewData, keyName: ":payloadsize", defaultValue: 0);
  v7 = KeyValues::GetName(this: this->m_pViewData);
  DevMsg(a1: "Uploading score for leaderboard '%s'...\n", v7);
  m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
  v9 = m_pSteamUserStats->__vftable;
  Int = KeyValues::GetInt(this: this->m_pViewDescription, keyName: ":upload", defaultValue: 0);
  v11 = ((__int64 (__thiscall *)(ISteamUserStats *, _DWORD, _DWORD, int, int, void *, unsigned int))v9->UploadLeaderboardScore)(
          a1: m_pSteamUserStats,
          a2: p->m_hSteamLeaderboard,
          a3: HIDWORD(p->m_hSteamLeaderboard),
          a4: Int,
          a5: Uint64,
          a6: pvPayloadPtr,
          a7: (unsigned int)(nPayloadSize + 3) >> 2);
  if ( this->m_CallbackOnLeaderboardScoreUploaded.m_hAPICall != 0 )
    _SteamAPI_UnregisterCallResult(
      a1: &this->m_CallbackOnLeaderboardScoreUploaded,
      a2: this->m_CallbackOnLeaderboardScoreUploaded.m_hAPICall,
      a3: HIDWORD(this->m_CallbackOnLeaderboardScoreUploaded.m_hAPICall));
  this->m_CallbackOnLeaderboardScoreUploaded.m_hAPICall = v11;
  this->m_CallbackOnLeaderboardScoreUploaded.m_pObj = this;
  this->m_CallbackOnLeaderboardScoreUploaded.m_Func = CSteamLeaderboardWriter::Steam_OnLeaderboardScoreUploaded;
  if ( v11 != 0 )
    _SteamAPI_RegisterCallResult(a1: &this->m_CallbackOnLeaderboardScoreUploaded, a2: v11, a3: HIDWORD(v11));
}

//------------------------------------------------------------------------------
// Address: 0x1001C350
// Name: public: CSteamLeaderboardWriter::CSteamLeaderboardWriter(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamLeaderboardWriter *__thiscall CSteamLeaderboardWriter::CSteamLeaderboardWriter(
        CSteamLeaderboardWriter *this,
        KeyValues *pViewDescription,
        KeyValues *pViewData)
{
  KeyValues *Copy; // eax
  KeyValues *m_pViewDescription; // ecx
  int Int; // eax
  ISteamUserStats *m_pSteamUserStats; // ebx
  ISteamUserStats_vtbl *v8; // edi
  const char *Name; // eax
  __int64 v10; // rax
  const char *v11; // eax
  unsigned __int64 v12; // kr00_8
  int v14; // [esp-8h] [ebp-14h]
  int v15; // [esp-4h] [ebp-10h]

  this->m_CallbackOnLeaderboardFindResult.m_nCallbackFlags = 0;
  this->m_CallbackOnLeaderboardFindResult.__vftable = (CCallResult<CSteamLeaderboardWriter,LeaderboardFindResult_t>_vtbl *)&CCallResult<CSteamLeaderboardWriter,LeaderboardFindResult_t>::`vftable';
  this->m_CallbackOnLeaderboardFindResult.m_iCallback = 1104;
  this->m_CallbackOnLeaderboardFindResult.m_hAPICall = 0;
  this->m_CallbackOnLeaderboardFindResult.m_pObj = nullptr;
  this->m_CallbackOnLeaderboardFindResult.m_Func = nullptr;
  this->m_CallbackOnLeaderboardScoreUploaded.m_nCallbackFlags = 0;
  this->m_CallbackOnLeaderboardScoreUploaded.__vftable = (CCallResult<CSteamLeaderboardWriter,LeaderboardScoreUploaded_t>_vtbl *)&CCallResult<CSteamLeaderboardWriter,LeaderboardScoreUploaded_t>::`vftable';
  this->m_CallbackOnLeaderboardScoreUploaded.m_hAPICall = 0;
  this->m_CallbackOnLeaderboardScoreUploaded.m_pObj = nullptr;
  this->m_CallbackOnLeaderboardScoreUploaded.m_Func = nullptr;
  this->m_CallbackOnLeaderboardScoreUploaded.m_iCallback = 1106;
  this->m_pViewDescription = KeyValues::MakeCopy(this: pViewDescription);
  Copy = KeyValues::MakeCopy(this: pViewData);
  m_pViewDescription = this->m_pViewDescription;
  this->m_pViewData = Copy;
  Int = KeyValues::GetInt(this: m_pViewDescription, keyName: ":nocreate", defaultValue: 0);
  m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
  v8 = m_pSteamUserStats->__vftable;
  if ( Int != 0 )
  {
    Name = KeyValues::GetName(this: this->m_pViewData);
    LODWORD(v10) = v8->FindLeaderboard(this: m_pSteamUserStats, a2: Name);
  }
  else
  {
    v15 = KeyValues::GetInt(this: this->m_pViewDescription, keyName: ":format", defaultValue: 0);
    v14 = KeyValues::GetInt(this: this->m_pViewDescription, keyName: ":sort", defaultValue: 0);
    v11 = KeyValues::GetName(this: this->m_pViewData);
    v10 = v8->FindOrCreateLeaderboard(
            this: m_pSteamUserStats,
            a2: v11,
            a3: (ELeaderboardSortMethod)v14,
            a4: (ELeaderboardDisplayType)v15);
  }
  v12 = v10;
  if ( this->m_CallbackOnLeaderboardFindResult.m_hAPICall != 0 )
    _SteamAPI_UnregisterCallResult(
      a1: this,
      a2: this->m_CallbackOnLeaderboardFindResult.m_hAPICall,
      a3: HIDWORD(this->m_CallbackOnLeaderboardFindResult.m_hAPICall));
  this->m_CallbackOnLeaderboardFindResult.m_hAPICall = v12;
  this->m_CallbackOnLeaderboardFindResult.m_pObj = this;
  this->m_CallbackOnLeaderboardFindResult.m_Func = CSteamLeaderboardWriter::Steam_OnLeaderboardFindResult;
  if ( v12 != 0 )
    _SteamAPI_RegisterCallResult(a1: this, a2: v12, a3: HIDWORD(v12));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001C450
// Name: void Steam_WriteLeaderboardData(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Steam_WriteLeaderboardData(KeyValues *pViewDescription, KeyValues *pViewData)
{
  CSteamLeaderboardWriter *v2; // eax

  v2 = (CSteamLeaderboardWriter *)operator new(nSize: 0x48u);
  if ( v2 != nullptr )
    CSteamLeaderboardWriter::CSteamLeaderboardWriter(this: v2, pViewDescription, pViewData);
}

//------------------------------------------------------------------------------
// Address: 0x100305A0
// Name: private: virtual void CCallResult<class CSteamLeaderboardWriter,struct LeaderboardFindResult_t>::Run(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallResult<CSteamLeaderboardWriter,LeaderboardFindResult_t>::Run(
        CCallResult<CLeaderboardRequestQueue,LeaderboardScoresDownloaded_t> *this,
        LeaderboardScoresDownloaded_t *pvParam)
{
  void (__thiscall *m_Func)(CLeaderboardRequestQueue *, LeaderboardScoresDownloaded_t *, bool); // edx

  m_Func = this->m_Func;
  this->m_hAPICall = 0;
  m_Func(this: this->m_pObj, a2: pvParam, a3: false);
}
