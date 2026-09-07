// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/maprules.cpp
// Functions: 40
// ============================================================

#include "game\server\maprules.h"

//------------------------------------------------------------------------------
// Address: 0x10170520
// Name: public: virtual struct datamap_t __near * CRulePointEntity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRulePointEntity::GetDataDescMap(CRulePointEntity *this)
{
  return &CRulePointEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10170530
// Name: public: virtual struct datamap_t __near * CGameScore::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGameScore::GetDataDescMap(CGameScore *this)
{
  return &CGameScore::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10170540
// Name: public: virtual struct datamap_t __near * CGameEnd::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGameEnd::GetDataDescMap(CGameEnd *this)
{
  return &CGameEnd::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10170550
// Name: public: void CGameEnd::InputGameEnd(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEnd::InputGameEnd(CGameEnd *this, inputdata_t *inputdata)
{
  g_pGameRules->EndMultiplayerGame(this: g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x10170570
// Name: public: virtual struct datamap_t __near * CGameText::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGameText::GetDataDescMap(CGameText *this)
{
  return &CGameText::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10170580
// Name: public: virtual struct datamap_t __near * CGamePlayerZone::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGamePlayerZone::GetDataDescMap(CGamePlayerZone *this)
{
  return &CGamePlayerZone::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10170590
// Name: private: virtual struct datamap_t __near * CGamePlayerEquip::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGamePlayerEquip::GetDataDescMap(CGamePlayerEquip *this)
{
  return &CGamePlayerEquip::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101705A0
// Name: public: virtual void CRulePointEntity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRulePointEntity::Spawn(CRulePointEntity *this)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::AddEffects(this, nEffects: 32);
  this->m_ModelName.pszValue = nullptr;
  CBaseEntity::DispatchUpdateTransmitState(this);
  this->m_Score = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101705F0
// Name: public: virtual void CRuleBrushEntity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRuleBrushEntity::Spawn(CRuleBrushEntity *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = *(const char **)((int (__thiscall *)(CRuleBrushEntity *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x10170640
// Name: public: virtual void CGameScore::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameScore::Spawn(CGameScore *this)
{
  int m_Score; // edi

  m_Score = this->m_Score;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::AddEffects(this, nEffects: 32);
  this->m_ModelName.pszValue = nullptr;
  CBaseEntity::DispatchUpdateTransmitState(this);
  this->m_Score = m_Score;
}

//------------------------------------------------------------------------------
// Address: 0x10170690
// Name: public: virtual bool CGameScore::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameScore::KeyValue(CGameScore *this, char *szKeyName, const char *szValue)
{
  if ( szKeyName != "points" && _V_stricmp(s1: szKeyName, s2: "points") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  this->m_Score = atoi(nptr: szValue);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101706E0
// Name: public: void CGameScore::InputApplyScore(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameScore::InputApplyScore(CGameScore *this, inputdata_t *inputdata)
{
  CBaseEntity *pActivator; // edi
  int m_Score; // [esp-8h] [ebp-10h]
  bool v5; // [esp-4h] [ebp-Ch]

  pActivator = inputdata->pActivator;
  if ( inputdata->pActivator != nullptr
    && (this->m_iszMaster.pszValue == nullptr
     || UTIL_IsMasterTriggered(sMaster: this->m_iszMaster, pActivator: inputdata->pActivator))
    && pActivator->IsPlayer(this: pActivator) )
  {
    v5 = this->m_spawnflags.m_Value & 1;
    m_Score = this->m_Score;
    if ( (this->m_spawnflags.m_Value & 2) != 0 )
      CBaseEntity::AddPointsToTeam(this: pActivator, score: m_Score, bAllowNegativeScore: v5);
    else
      CBaseEntity::AddPoints(this: pActivator, score: m_Score, bAllowNegativeScore: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10170760
// Name: public: virtual void CGameScore::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameScore::Use(
        CGameScore *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  int m_Score; // [esp-8h] [ebp-10h]
  bool v7; // [esp-4h] [ebp-Ch]

  if ( (this->m_iszMaster.pszValue == nullptr || UTIL_IsMasterTriggered(sMaster: this->m_iszMaster, pActivator))
    && pActivator->IsPlayer(this: pActivator) )
  {
    v7 = this->m_spawnflags.m_Value & 1;
    m_Score = this->m_Score;
    if ( (this->m_spawnflags.m_Value & 2) != 0 )
      CBaseEntity::AddPointsToTeam(this: pActivator, score: m_Score, bAllowNegativeScore: v7);
    else
      CBaseEntity::AddPoints(this: pActivator, score: m_Score, bAllowNegativeScore: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101707D0
// Name: public: virtual void CGameEnd::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEnd::Use(
        CGameEnd *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( this->m_iszMaster.pszValue == nullptr || UTIL_IsMasterTriggered(sMaster: this->m_iszMaster, pActivator) )
    g_pGameRules->EndMultiplayerGame(this: g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x10170810
// Name: public: virtual bool CGameText::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameText::KeyValue(CGameText *this, char *szKeyName, const char *szValue)
{
  unsigned __int8 v4; // al
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // dl
  unsigned __int8 v8; // al
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // dl
  int color[4]; // [esp+8h] [ebp-10h] BYREF

  if ( szKeyName != "color" && _V_stricmp(s1: szKeyName, s2: "color") != 0 )
  {
    if ( szKeyName != "color2" && _V_stricmp(s1: szKeyName, s2: "color2") != 0 )
    {
      return CBaseEntity::KeyValue(this, szKeyName, szValue);
    }
    else
    {
      V_StringToIntArray(pVector: color, count: 4, pString: szValue);
      v8 = color[1];
      v9 = color[2];
      this->m_textParms.r2 = color[0];
      v10 = color[3];
      this->m_textParms.g2 = v8;
      this->m_textParms.b2 = v9;
      this->m_textParms.a2 = v10;
      return true;
    }
  }
  else
  {
    V_StringToIntArray(pVector: color, count: 4, pString: szValue);
    v4 = color[1];
    v5 = color[2];
    this->m_textParms.r1 = color[0];
    v6 = color[3];
    this->m_textParms.g1 = v4;
    this->m_textParms.b1 = v5;
    this->m_textParms.a1 = v6;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101708F0
// Name: public: void CGameText::Display(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::Display(CGameText *this, CBaseEntity *pActivator)
{
  const char *pszValue; // eax
  CBasePlayer *LocalPlayer; // eax
  const char *v5; // ecx
  const char *v6; // eax
  CBasePlayer *v7; // eax
  const char *v8; // [esp-4h] [ebp-Ch]

  if ( this->m_iszMaster.pszValue == nullptr || UTIL_IsMasterTriggered(sMaster: this->m_iszMaster, pActivator) )
  {
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      pszValue = this->m_iszMessage.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      UTIL_HudMessageAll(textparms: &this->m_textParms, pMessage: pszValue);
    }
    else if ( gpGlobals->maxClients == 1 )
    {
      LocalPlayer = UTIL_GetLocalPlayer();
      v5 = this->m_iszMessage.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      UTIL_HudMessage(pToPlayer: LocalPlayer, textparms: &this->m_textParms, pMessage: v5);
    }
    else if ( pActivator != nullptr && pActivator->IsNetClient(this: pActivator) )
    {
      v6 = this->m_iszMessage.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      v8 = v6;
      v7 = ToBasePlayer(pEntity: pActivator);
      UTIL_HudMessage(pToPlayer: v7, textparms: &this->m_textParms, pMessage: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101709D0
// Name: public: void CGameText::InputSetText(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::InputSetText(CGameText *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  this->m_iszMessage.pszValue = *(const char **)AllocPooledString(pszValue: (char *)&inputdata, pszValuea: iVal).pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x10170A10
// Name: public: void CGameText::InputSetPosX(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::InputSetPosX(CGameText *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_textParms.x) = inputdata->value.iVal;
  else
    this->m_textParms.x = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10170A40
// Name: public: void CGameText::InputSetPosY(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::InputSetPosY(CGameText *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_textParms.y) = inputdata->value.iVal;
  else
    this->m_textParms.y = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10170A70
// Name: public: void CGameText::InputSetTextColor(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::InputSetTextColor(CGameText *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  pszValue = inputdata->value.iszVal.pszValue;
  *(_DWORD *)&this->m_textParms.r1 = pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x10170AB0
// Name: public: void CGameText::InputSetTextColor2(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::InputSetTextColor2(CGameText *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  pszValue = inputdata->value.iszVal.pszValue;
  *(_DWORD *)&this->m_textParms.r2 = pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x10170AF0
// Name: public: virtual bool CGamePlayerEquip::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGamePlayerEquip::KeyValue(CGamePlayerEquip *this, char *szKeyName, const char *szValue)
{
  const char *v3; // ebx
  int v5; // esi
  string_t *i; // eax
  int v8; // eax
  char tmp[128]; // [esp+Ch] [ebp-80h] BYREF

  v3 = szValue;
  if ( CBaseEntity::KeyValue(this, szKeyName, szValue) )
    return 0;
  v5 = 0;
  for ( i = this->m_weaponNames; i->pszValue != nullptr; ++i )
  {
    if ( ++v5 >= 32 )
      return 0;
  }
  UTIL_StripToken(pKey: szKeyName, pDest: tmp);
  this->m_weaponNames[v5].pszValue = *(const char **)AllocPooledString(pszValue: (char *)&szKeyName, pszValuea: tmp).pszValue;
  v8 = atoi(nptr: v3);
  this->m_weaponCount[v5] = v8 < 0 ? 0 : v8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10170B80
// Name: private: void CGamePlayerEquip::EquipPlayer(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePlayerEquip::EquipPlayer(CGamePlayerEquip *this, CBaseEntity *pEntity)
{
  string_t *m_weaponNames; // edi
  CSWeaponID v5; // ebx
  int j; // ebx
  const char *v7; // eax
  const char *pszValue; // eax
  CCSWeaponInfo *WeaponInfo; // eax
  int i; // [esp+10h] [ebp+8h]

  if ( pEntity->IsPlayer(this: pEntity) )
  {
    if ( (this->m_spawnflags.m_Value & 2) != 0 )
      pEntity->__vftable[1].NetworkStateChanged_m_hGroundEntity(this: pEntity, a2: (void *)1);
    i = 0;
    m_weaponNames = this->m_weaponNames;
    do
    {
      if ( m_weaponNames->pszValue == nullptr )
        break;
      v5 = WeaponIdFromString(szWeaponName: m_weaponNames->pszValue);
      if ( v5 < WEAPON_KNIFE )
      {
        pszValue = m_weaponNames->pszValue;
        if ( m_weaponNames->pszValue == nullptr )
          pszValue = locale;
        ((void (__thiscall *)(CBaseEntity *, const char *, _DWORD, int))pEntity->__vftable[2].DrawDebugTextOverlays)(
          a1: pEntity,
          a2: pszValue,
          a3: 0,
          a4: 1);
        WeaponInfo = GetWeaponInfo(weaponID: v5);
        ((void (__thiscall *)(CBaseEntity *, const char *, int, _DWORD))pEntity->__vftable[1].MyCombatCharacterPointer)(
          a1: pEntity,
          a2: m_weaponNames[32].pszValue,
          a3: WeaponInfo->iAmmoType,
          a4: 0);
      }
      else
      {
        for ( j = 0; j < (int)m_weaponNames[32].pszValue; ++j )
        {
          v7 = m_weaponNames->pszValue;
          if ( m_weaponNames->pszValue == nullptr )
            v7 = locale;
          ((void (__thiscall *)(CBaseEntity *, const char *, _DWORD, int))pEntity->__vftable[2].DrawDebugTextOverlays)(
            a1: pEntity,
            a2: v7,
            a3: 0,
            a4: 1);
        }
      }
      ++m_weaponNames;
      ++i;
    }
    while ( i < 32 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10170C80
// Name: public: virtual void CGamePlayerEquip::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePlayerEquip::Use(
        CGamePlayerEquip *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  CGamePlayerEquip::EquipPlayer(this, pEntity: pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x10170C90
// Name: private: char const __near * CGamePlayerTeam::TargetTeamName(char const __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGamePlayerTeam::TargetTeamName(
        CGamePlayerTeam *this,
        const char *pszTargetName,
        CBaseEntity *pActivator)
{
  CBasePlayer *EntityByName; // esi

  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszTargetName,
                   pSearchingEntity: nullptr,
                   pActivator,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName == nullptr )
    return nullptr;
  while ( EntityByName->m_iClassname.pszValue != "game_team_master"
       && CBaseEntity::ClassMatchesComplex(this: EntityByName, pszClassOrWildcard: "game_team_master") == 0 )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: EntityByName,
                     szName: pszTargetName,
                     pSearchingEntity: nullptr,
                     pActivator,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName == nullptr )
      return nullptr;
  }
  return CBaseEntity::TeamID(this: EntityByName);
}

//------------------------------------------------------------------------------
// Address: 0x10170D00
// Name: public: virtual void CGamePlayerTeam::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePlayerTeam::Use(
        CGamePlayerTeam *this,
        CBasePlayer *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  const char *pszValue; // eax
  const char *v7; // eax

  if ( this->m_iszMaster.pszValue == nullptr || UTIL_IsMasterTriggered(sMaster: this->m_iszMaster, pActivator) )
  {
    if ( pActivator->IsPlayer(this: pActivator) )
    {
      pszValue = this->m_target.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v7 = CGamePlayerTeam::TargetTeamName(this, pszTargetName: pszValue, pActivator);
      if ( v7 != nullptr )
        g_pGameRules->ChangePlayerTeam(
          this: g_pGameRules,
          a2: pActivator,
          a3: v7,
          a4: (this->m_spawnflags.m_Value & 2) != 0,
          a5: (this->m_spawnflags.m_Value & 4) != 0);
    }
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
      UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10170DA0
// Name: public: void CGameText::InputDisplay(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::InputDisplay(CGameText *this, inputdata_t *inputdata)
{
  CGameText::Display(this, pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x10170DC0
// Name: public: void CGamePlayerEquip::TriggerForAllPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePlayerEquip::TriggerForAllPlayers(CGamePlayerEquip *this)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBaseEntity *v4; // esi

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr
      && (this->m_iszMaster.pszValue == nullptr || UTIL_IsMasterTriggered(sMaster: this->m_iszMaster, pActivator: v3)) )
    {
      CGamePlayerEquip::EquipPlayer(this, pEntity: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10170E20
// Name: public: virtual void CGamePlayerEquip::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePlayerEquip::Touch(CGamePlayerEquip *this, CBaseEntity *pOther)
{
  if ( (this->m_iszMaster.pszValue == nullptr || UTIL_IsMasterTriggered(sMaster: this->m_iszMaster, pActivator: pOther))
    && (this->m_spawnflags.m_Value & 1) == 0 )
  {
    CGamePlayerEquip::EquipPlayer(this, pEntity: pOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10170E60
// Name: public: virtual void CGameText::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::Use(
        CGameText *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  CGameText::Display(this, pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x10170E70
// Name: public: void CGamePlayerZone::InputCountPlayersInZone(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePlayerZone::InputCountPlayersInZone(CGamePlayerZone *this, inputdata_t *inputdata)
{
  CBaseEntity *pActivator; // eax
  int v4; // eax
  CBasePlayer *v5; // eax
  CBaseEntity *v6; // esi
  const Vector *v7; // eax
  COutputEvent *p_m_OnPlayerInZone; // ecx
  CBaseEntity *v9; // ebx
  CBaseEntity *v10; // ebx
  const Vector *v11; // [esp-Ch] [ebp-80h]
  CGameTrace trace; // [esp+10h] [ebp-64h] BYREF
  int i; // [esp+64h] [ebp-10h] BYREF
  int playersOutCount; // [esp+68h] [ebp-Ch]
  int playersInCount; // [esp+6Ch] [ebp-8h]
  Hull_t hullType; // [esp+70h] [ebp-4h]
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  pActivator = inputdata->pActivator;
  playersInCount = 0;
  playersOutCount = 0;
  if ( this->m_iszMaster.pszValue == nullptr || UTIL_IsMasterTriggered(sMaster: this->m_iszMaster, pActivator) )
  {
    v4 = 1;
    for ( i = 1; v4 <= gpGlobals->maxClients; i = v4 )
    {
      v5 = UTIL_PlayerByIndex(playerIndex: v4);
      v6 = v5;
      if ( v5 != nullptr )
      {
        hullType = (v5->m_fFlags.m_Value & 2) != 0;
        if ( (v5->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
        if ( (v6->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v6, a2: (int)&savedregs);
        v11 = NAI_Hull::Maxs(id: hullType);
        v7 = NAI_Hull::Mins(id: hullType);
        UTIL_TraceModel(
          a1: (int)&savedregs,
          vecStart: &v6->m_vecAbsOrigin,
          vecEnd: &v6->m_vecAbsOrigin,
          hullMin: v7,
          hullMax: v11,
          pentModel: this,
          collisionGroup: 0,
          ptr: &trace);
        if ( trace.startsolid )
        {
          ++playersInCount;
          p_m_OnPlayerInZone = &this->m_OnPlayerInZone;
        }
        else
        {
          ++playersOutCount;
          p_m_OnPlayerInZone = &this->m_OnPlayerOutZone;
        }
        COutputEvent::FireOutput(this: p_m_OnPlayerInZone, pActivator: v6, pCaller: this, fDelay: 0.0);
      }
      v4 = i + 1;
    }
    v9 = inputdata->pActivator;
    i = playersInCount;
    variant_t::Set(
      this: &this->m_PlayersInCount.m_Value,
      ftype: FIELD_INTEGER,
      data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&i);
    CBaseEntityOutput::FireOutput(
      this: &this->m_PlayersInCount,
      Value: this->m_PlayersInCount.m_Value,
      pActivator: v9,
      pCaller: this,
      fDelay: 0.0);
    v10 = inputdata->pActivator;
    inputdata = (inputdata_t *)playersOutCount;
    variant_t::Set(
      this: &this->m_PlayersOutCount.m_Value,
      ftype: FIELD_INTEGER,
      data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&inputdata);
    CBaseEntityOutput::FireOutput(
      this: &this->m_PlayersOutCount,
      Value: this->m_PlayersOutCount.m_Value,
      pActivator: v10,
      pCaller: this,
      fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101710A0
// Name: public: void CGamePlayerEquip::InputTriggerForAllPlayers(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CGamePlayerEquip::InputTriggerForAllPlayers(CGamePlayerEquip *this, inputdata_t *inputdata)
{
  CGamePlayerEquip::TriggerForAllPlayers(this);
}

//------------------------------------------------------------------------------
// Address: 0x101710B0
// Name: public: CGamePlayerZone::CGamePlayerZone(void)
// Source: json
//------------------------------------------------------------------------------
CGamePlayerZone *__thiscall CGamePlayerZone::CGamePlayerZone(CGamePlayerZone *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CGamePlayerZone_vtbl *)&CGamePlayerZone::`vftable';
  this->m_OnPlayerInZone.m_Value.iVal = 0;
  this->m_OnPlayerInZone.m_Value.eVal.m_Index = -1;
  this->m_OnPlayerInZone.m_Value.fieldType = FIELD_VOID;
  this->m_OnPlayerOutZone.m_Value.iVal = 0;
  this->m_OnPlayerOutZone.m_Value.eVal.m_Index = -1;
  this->m_OnPlayerOutZone.m_Value.fieldType = FIELD_VOID;
  this->m_PlayersInCount.m_Value.iVal = 0;
  this->m_PlayersInCount.m_Value.eVal.m_Index = -1;
  this->m_PlayersInCount.m_Value.fieldType = FIELD_VOID;
  this->m_PlayersOutCount.m_Value.iVal = 0;
  this->m_PlayersOutCount.m_Value.eVal.m_Index = -1;
  this->m_PlayersOutCount.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10405BB0
// Name: CRuleEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRuleEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRuleEntity>();
  CRuleEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405BC0
// Name: CRulePointEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRulePointEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRulePointEntity>();
  CRulePointEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405BF0
// Name: CGameScore_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGameScore_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGameScore>();
  CGameScore_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405C00
// Name: CGameEnd_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGameEnd_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGameEnd>();
  CGameEnd_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405C50
// Name: CGameText_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGameText_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGameText>();
  CGameText_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405C80
// Name: CGamePlayerZone_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGamePlayerZone_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGamePlayerZone>();
  CGamePlayerZone_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405CB0
// Name: CGamePlayerEquip_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGamePlayerEquip_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGamePlayerEquip>();
  CGamePlayerEquip_DataDescInit::g_DataMapHolder = result;
  return result;
}
