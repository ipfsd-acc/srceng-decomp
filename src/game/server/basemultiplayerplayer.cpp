// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/basemultiplayerplayer.cpp
// Functions: 25
// ============================================================

#include "game\server\basemultiplayerplayer.h"

//------------------------------------------------------------------------------
// Address: 0x1002D800
// Name: public: virtual class CBaseCombatCharacter __near * CBasePlayer::ActivePlayerCombatCharacter(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CBasePlayer::ActivePlayerCombatCharacter(vgui::Panel *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D7760
// Name: private: virtual struct ScriptClassDesc_t __near * CBaseMultiplayerPlayer::GetScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall CBaseMultiplayerPlayer::GetScriptDesc(CBaseMultiplayerPlayer *this)
{
  return GetScriptDesc(__formal: this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7780
// Name: protected: virtual class CAI_Expresser __near * CBaseMultiplayerPlayer::CreateExpresser(void)
// Source: json
//------------------------------------------------------------------------------
CMultiplayer_Expresser *__thiscall CBaseMultiplayerPlayer::CreateExpresser(CBaseMultiplayerPlayer *this)
{
  CMultiplayer_Expresser *v2; // eax
  CMultiplayer_Expresser *result; // eax

  v2 = (CMultiplayer_Expresser *)operator new(nSize: 0x54u);
  if ( v2 != nullptr )
    result = CMultiplayer_Expresser::CMultiplayer_Expresser(this: v2, pOuter: this);
  else
    result = nullptr;
  this->m_pExpresser = result;
  if ( result != nullptr )
  {
    result->m_pSink = &this->CAI_ExpresserSink;
    return this->m_pExpresser;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D77C0
// Name: public: virtual void CBaseMultiplayerPlayer::PostConstructor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseMultiplayerPlayer::PostConstructor(CBaseMultiplayerPlayer *this, const char *szClassname)
{
  CBaseEntity::PostConstructor(this, szClassname);
  this->CreateExpresser(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D77E0
// Name: public: virtual int CBaseMultiplayerPlayer::CalculateTeamBalanceScore(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseMultiplayerPlayer::CalculateTeamBalanceScore(CBaseMultiplayerPlayer *this)
{
  float m_flLastForcedChangeTeamTime; // xmm1_4
  int result; // eax

  m_flLastForcedChangeTeamTime = this->m_flLastForcedChangeTeamTime;
  result = -(int)(float)(gpGlobals->curtime - this->m_flConnectionTime);
  if ( m_flLastForcedChangeTeamTime > 0.0 && (float)(gpGlobals->curtime - m_flLastForcedChangeTeamTime) < 300.0 )
    result -= 10000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D7830
// Name: public: class IPlayerInfo __near * CBasePlayer::GetPlayerInfo(void)
// Source: json
//------------------------------------------------------------------------------
IPlayerInfo *__thiscall CBasePlayer::GetPlayerInfo(CBasePlayer *this)
{
  if ( this == (CBasePlayer *)-4164 )
    return nullptr;
  else
    return &this->m_PlayerInfo.IPlayerInfo;
}

//------------------------------------------------------------------------------
// Address: 0x100D78B0
// Name: public: virtual char const __near * CBasePlayer::GetPlayerName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBasePlayer::GetPlayerName(CBasePlayer *this)
{
  return this->m_szNetname;
}

//------------------------------------------------------------------------------
// Address: 0x100D78C0
// Name: public: virtual char const __near * CBasePlayer::GetCharacterDisplayName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBasePlayer::GetCharacterDisplayName(CBasePlayer *this)
{
  return this->GetPlayerName(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D78F0
// Name: public: virtual class CNavArea __near * CBasePlayer::GetLastKnownArea(void)const
// Source: json
//------------------------------------------------------------------------------
CNavArea *__thiscall CBasePlayer::GetLastKnownArea(CBaseCombatCharacter *this)
{
  return this->m_lastNavArea;
}

//------------------------------------------------------------------------------
// Address: 0x100D7900
// Name: public: virtual void CBasePlayer::ResetScores(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ResetScores(CBasePlayer *this)
{
  CBasePlayer::ResetFragCount(this);
  CBasePlayer::ResetDeathCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7940
// Name: public: virtual void CBaseMultiplayerPlayer::ModifyOrAppendCriteria(class ResponseRules::CriteriaSet __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseMultiplayerPlayer::ModifyOrAppendCriteria(
        CBaseMultiplayerPlayer *this,
        ResponseRules::CriteriaSet *criteriaSet)
{
  CAI_BaseNPC *v3; // eax

  CBaseAnimating::ModifyOrAppendCriteria(this, set: criteriaSet);
  if ( this->MyNPCPointer(this) != nullptr )
  {
    v3 = this->MyNPCPointer(this);
    CAI_ExpresserHost_NPC_DoModifyOrAppendCriteria(pSpeaker: v3, set: criteriaSet);
  }
  this->ModifyOrAppendPlayerCriteria(this, a2: criteriaSet);
}

//------------------------------------------------------------------------------
// Address: 0x100D7990
// Name: public: virtual bool CBaseMultiplayerPlayer::SpeakConceptIfAllowed(int,char const __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseMultiplayerPlayer::SpeakConceptIfAllowed(
        CBaseMultiplayerPlayer *this,
        int iConcept,
        const char *modifiers,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  int v8; // [esp-1Ch] [ebp-24h] BYREF
  int v9; // [esp-14h] [ebp-1Ch]
  const char *v10; // [esp-10h] [ebp-18h]
  char *v11; // [esp-Ch] [ebp-14h]
  unsigned int v12; // [esp-8h] [ebp-10h]
  IRecipientFilter *v13; // [esp-4h] [ebp-Ch]

  v13 = filter;
  v12 = bufsize;
  v11 = pszOutResponseChosen;
  v10 = modifiers;
  v9 = 1;
  this->m_iCurrentConcept = iConcept;
  ResponseRules::CRR_Concept::CRR_Concept(
    this: (ResponseRules::CRR_Concept *)&v8,
    fromString: g_pszMPConcepts[iConcept]);
  return ((bool (__thiscall *)(CBaseMultiplayerPlayer *, int, int, int, const char *, char *, unsigned int, IRecipientFilter *))this->SpeakIfAllowed)(
           a1: this,
           a2: v8,
           a3: -1,
           a4: v9,
           a5: v10,
           a6: v11,
           a7: v12,
           a8: v13);
}

//------------------------------------------------------------------------------
// Address: 0x100D79E0
// Name: public: virtual bool CBaseMultiplayerPlayer::CanHearAndReadChatFrom(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseMultiplayerPlayer::CanHearAndReadChatFrom(CBaseMultiplayerPlayer *this, CBasePlayer *pPlayer)
{
  int m_iIgnoreGlobalChat; // eax

  if ( pPlayer == nullptr )
    return this->m_iIgnoreGlobalChat != 1;
  m_iIgnoreGlobalChat = this->m_iIgnoreGlobalChat;
  return m_iIgnoreGlobalChat != 1
      && (m_iIgnoreGlobalChat != 2 || g_pGameRules->PlayerRelationship(this: g_pGameRules, a2: this, a3: pPlayer) == 1)
      && (pPlayer->m_lifeState.m_Value == 0 || this->m_lifeState.m_Value != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100D7A50
// Name: public: virtual bool CBaseMultiplayerPlayer::ClientCommand(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseMultiplayerPlayer::ClientCommand(CBaseMultiplayerPlayer *this, const CCommand *args)
{
  const char *v3; // eax
  int v4; // eax
  int v5; // eax

  v3 = locale;
  if ( args->m_nArgc > 0 )
    v3 = args->m_ppArgv[0];
  if ( v3 != "ignoremsg" && _V_stricmp(s1: v3, s2: "ignoremsg") != 0 )
    return CBasePlayer::ClientCommand(this, args);
  v4 = (this->m_iIgnoreGlobalChat + 1) % 3;
  this->m_iIgnoreGlobalChat = v4;
  if ( v4 != 0 )
  {
    v5 = v4 - 1;
    if ( v5 == 0 )
    {
      ClientPrint(
        player: this,
        msg_dest: 3,
        msg_name: "#Ignore_Broadcast_Messages",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      return true;
    }
    if ( v5 == 1 )
    {
      ClientPrint(
        player: this,
        msg_dest: 3,
        msg_name: "#Ignore_Broadcast_Team_Messages",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      return true;
    }
  }
  else
  {
    ClientPrint(
      player: this,
      msg_dest: 3,
      msg_name: "#Accept_All_Messages",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100D7B10
// Name: public: virtual void CBaseMultiplayerPlayer::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseMultiplayerPlayer::Spawn(CBaseMultiplayerPlayer *this)
{
  KeyValues::Clear(this: this->m_pAchievementKV);
  CBasePlayer::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7B30
// Name: public: void CBaseMultiplayerPlayer::AwardAchievement(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseMultiplayerPlayer::AwardAchievement(CBaseMultiplayerPlayer *this, int iAchievement, int iCount)
{
  IPlayerInfo *v4; // ecx
  int v5; // esi
  CSingleUserRecipientFilter filter; // [esp+4h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &filter, player: this);
  if ( this == (CBaseMultiplayerPlayer *)-4164 )
    v4 = nullptr;
  else
    v4 = &this->m_PlayerInfo.IPlayerInfo;
  v5 = v4->GetUserID(this: v4);
  UserMessageBegin(&filter, messagename: "AchievementEvent");
  MessageWriteShort(iValue: iAchievement);
  MessageWriteShort(iValue: iCount);
  MessageWriteShort(iValue: v5);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100D7C10
// Name: public: virtual class IServerVehicle __near * CBasePlayer::GetVehicle(void)
// Source: json
//------------------------------------------------------------------------------
IServerVehicle *__thiscall CBasePlayer::GetVehicle(CBasePlayer *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  m_Index = this->m_hVehicle.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return ((IServerVehicle *(__thiscall *)(IHandleEntity *))m_pEntity->__vftable[30].SetRefEHandle)(a1: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7C50
// Name: public: virtual class CBaseEntity __near * CBasePlayer::GetVehicleEntity(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__thiscall CBasePlayer::GetVehicleEntity(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_pHintNode.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CAI_Hint *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100D7C80
// Name: public: virtual bool CBasePlayer::IsInAVehicle(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::IsInAVehicle(CBasePlayer *this)
{
  unsigned int m_Index; // eax

  m_Index = this->m_hVehicle.m_Value.m_Index;
  return m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D7CC0
// Name: public: CBaseMultiplayerPlayer::CBaseMultiplayerPlayer(void)
// Source: json
//------------------------------------------------------------------------------
CBaseMultiplayerPlayer *__thiscall CBaseMultiplayerPlayer::CBaseMultiplayerPlayer(CBaseMultiplayerPlayer *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  CBasePlayer::CBasePlayer(this);
  this->CAI_ExpresserHost<CBasePlayer>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CAI_ExpresserSink::`vftable';
  this->CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBaseMultiplayerPlayer_vtbl *)&CBaseMultiplayerPlayer::`vftable'{for `CBasePlayer'};
  this->CAI_ExpresserHost<CBasePlayer>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CBaseMultiplayerPlayer::`vftable'{for `CAI_ExpresserSink'};
  this->m_iCurrentConcept = -1;
  *(_QWORD *)&this->m_flLastForcedChangeTeamTime = 3212836864LL;
  this->m_flConnectionTime = gpGlobals->curtime;
  this->m_pExpresser = nullptr;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "achievement_counts");
  else
    v3 = nullptr;
  this->m_pAchievementKV = v3;
  this->m_flAreaCaptureScoreAccumulator = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D7D60
// Name: public: virtual void CBaseMultiplayerPlayer::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseMultiplayerPlayer::Precache(CBaseMultiplayerPlayer *this)
{
  PrecacheParticleSystem(pParticleSystemName: "achieved");
  CBasePlayer::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7D80
// Name: public: virtual class CMultiplayer_Expresser __near * CBaseMultiplayerPlayer::GetMultiplayerExpresser(void)
// Source: json
//------------------------------------------------------------------------------
CMultiplayer_Expresser *__thiscall CBaseMultiplayerPlayer::GetMultiplayerExpresser(CBaseMultiplayerPlayer *this)
{
  return this->m_pExpresser;
}

//------------------------------------------------------------------------------
// Address: 0x100D7D90
// Name: public: unsigned __int64 CBaseMultiplayerPlayer::GetSteamIDAsUInt64(void)
// Source: json
//------------------------------------------------------------------------------
CSteamID::SteamID_t __thiscall CBaseMultiplayerPlayer::GetSteamIDAsUInt64(CBaseMultiplayerPlayer *this)
{
  const CSteamID *v1; // eax

  v1 = engine->GetClientSteamID(this: engine, a2: this->m_Network.m_pPev);
  if ( v1 != nullptr )
    return v1->m_steamid;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D7E10
// Name: public: virtual CBaseMultiplayerPlayer::~CBaseMultiplayerPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseMultiplayerPlayer::~CBaseMultiplayerPlayer(CBaseMultiplayerPlayer *this)
{
  KeyValues *m_pAchievementKV; // ecx
  CMultiplayer_Expresser *m_pExpresser; // edi

  m_pAchievementKV = this->m_pAchievementKV;
  this->CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBaseMultiplayerPlayer_vtbl *)&CBaseMultiplayerPlayer::`vftable'{for `CBasePlayer'};
  this->CAI_ExpresserHost<CBasePlayer>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CBaseMultiplayerPlayer::`vftable'{for `CAI_ExpresserSink'};
  KeyValues::deleteThis(this: m_pAchievementKV);
  m_pExpresser = this->m_pExpresser;
  if ( m_pExpresser != nullptr )
  {
    CAI_Expresser::~CAI_Expresser(this: this->m_pExpresser);
    free(pMem: m_pExpresser);
  }
  CBasePlayer::~CBasePlayer(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7E60
// Name: public: virtual bool CBaseMultiplayerPlayer::SpeakIfAllowed(class CAI_Concept,enum SpeechPriorityType,char const __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseMultiplayerPlayer::SpeakIfAllowed(
        CBaseMultiplayerPlayer *this,
        CAI_Concept concept,
        SpeechPriorityType priority,
        const char *modifiers,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  bool result; // al
  unsigned __int16 m_Id; // [esp-18h] [ebp-1Ch]

  result = this->IsAlive(this);
  if ( result )
  {
    m_Id = concept.m_iConcept.m_Id;
    return ((bool (__thiscall *)(CBaseMultiplayerPlayer *, unsigned __int16, unsigned int, const char *, char *, unsigned int, IRecipientFilter *))this->Speak)(
             a1: this,
             a2: m_Id,
             a3: concept.m_hSpeaker.m_Index,
             a4: modifiers,
             a5: pszOutResponseChosen,
             a6: bufsize,
             a7: filter);
  }
  return result;
}
