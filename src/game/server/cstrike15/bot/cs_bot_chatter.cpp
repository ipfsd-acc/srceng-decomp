// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_chatter.cpp
// Functions: 177
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_chatter.h"

//------------------------------------------------------------------------------
// Address: 0x102A90C0
// Name: public: class CFuncElevator __near * CNavArea::GetElevator(void)const
// Source: json
//------------------------------------------------------------------------------
CFuncElevator *__thiscall CNavArea::GetElevator(CNavArea *this)
{
  if ( (this->m_attributeFlags & 0x40000000) != 0 )
    return this->m_elevator;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102A90E0
// Name: public: unsigned char CNavArea::GetPlayerCount(int)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CNavArea::GetPlayerCount(CNavArea *this, int teamID)
{
  if ( teamID != 0 )
    return this->m_playerCount[teamID % 2];
  else
    return this->m_playerCount[0] + this->m_playerCount[1];
}

//------------------------------------------------------------------------------
// Address: 0x102A9150
// Name: public: enum BotChatterInterface::VerbosityType BotChatterInterface::GetVerbosity(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall BotChatterInterface::GetVerbosity(BotChatterInterface *this)
{
  char *m_pszString; // eax
  char v2; // al

  if ( (cv_bot_chatter.m_nFlags & 0x1000) != 0 )
    return 0;
  m_pszString = cv_bot_chatter.m_pParent->m_Value.m_pszString;
  if ( m_pszString == nullptr )
    return 0;
  v2 = *m_pszString;
  if ( v2 == 109 || v2 == 77 )
    return 1;
  if ( v2 == 114 || v2 == 82 )
    return 2;
  if ( v2 != 111 && v2 != 79 )
    return 0;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x102A91A0
// Name: public: void BotMeme::Transmit(class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotMeme::Transmit(BotMeme *this, CCSBot *sender)
{
  int i; // ebx
  CCSBot *v3; // eax
  CBaseEntity *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = (CCSBot *)UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr
      && sender != v3
      && (v3->IsBot(this: v3) || v4->IsAlive(this: v4))
      && CBaseEntity::InSameTeam(this: v4, pEntity: sender)
      && v4->__vftable[2].MyCombatWeaponPointer(this: v4) != nullptr )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        this->Interpret(this, a2: sender, a3: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A9250
// Name: public: virtual void BotHelpMeme::Interpret(class CCSBot __near *,class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotHelpMeme::Interpret(BotHelpMeme *this, CCSBot *sender, CCSBot *receiver)
{
  CCSBot::RespondToHelpRequest(this: receiver, them: sender, place: this->m_place, maxRange: 3000.0);
}

//------------------------------------------------------------------------------
// Address: 0x102A9280
// Name: public: void BotPhraseManager::OnMapChange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotPhraseManager::OnMapChange(BotPhraseManager *this)
{
  this->m_placeCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102A9290
// Name: public: BotStatement::BotStatement(class BotChatterInterface __near *,enum BotStatementType,float)
// Source: json
//------------------------------------------------------------------------------
BotStatement *__thiscall BotStatement::BotStatement(
        BotStatement *this,
        BotChatterInterface *chatter,
        BotStatementType type,
        float expireDuration)
{
  double curtime; // st7

  this->m_chatter = chatter;
  this->m_next = nullptr;
  this->m_prev = nullptr;
  curtime = gpGlobals->curtime;
  this->m_type = type;
  this->m_timestamp = curtime;
  this->m_speakTimestamp = 0.0;
  this->m_subject = -1;
  this->m_place = 0;
  this->m_meme = nullptr;
  this->m_startTime = gpGlobals->curtime;
  this->m_expireTime = gpGlobals->curtime + expireDuration;
  this->m_isSpeaking = false;
  this->m_nextTime = 0.0;
  this->m_index = -1;
  this->m_count = 0;
  this->m_conditionCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102A9300
// Name: public: bool BotStatement::IsImportant(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall BotStatement::IsImportant(BotStatement *this)
{
  int m_count; // esi
  int v2; // edx
  $B1D420AA4BC179AFD3650035EBAFE544 *i; // eax

  m_count = this->m_count;
  v2 = 0;
  if ( m_count <= 0 )
    return 0;
  for ( i = &this->m_statement[0].___u1; LOBYTE(i[-1].phrase) != 0; i += 2 )
  {
    if ( i->phrase->m_isImportant )
      return 1;
LABEL_7:
    if ( ++v2 >= m_count )
      return 0;
  }
  if ( i->phrase != nullptr )
    goto LABEL_7;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A9340
// Name: public: void BotStatement::Convert(class BotStatement const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall BotStatement::Convert(BotStatement *this, const BotStatement *say)
{
  const BotPhrase *m_agreeWithPlanPhrase; // ecx
  const BotPhrase *phrase; // eax

  if ( this->m_type == REPORT_MY_PLAN && say->m_type == REPORT_MY_PLAN )
  {
    m_agreeWithPlanPhrase = TheBotPhrases->m_agreeWithPlanPhrase;
    phrase = this->m_statement[0].phrase;
    if ( phrase != m_agreeWithPlanPhrase && phrase == say->m_statement[0].phrase )
    {
      if ( this->m_place == say->m_place )
      {
        this->m_statement[0].phrase = m_agreeWithPlanPhrase;
        this->m_startTime = _RandomFloat(this: (IUniformRandomStream *)m_agreeWithPlanPhrase, a2: 0.5, a3: 1.0)
                          + gpGlobals->curtime;
      }
      else
      {
        this->m_startTime = _RandomFloat(this: (IUniformRandomStream *)m_agreeWithPlanPhrase, a2: 3.0, a3: 4.0)
                          + gpGlobals->curtime;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A93F0
// Name: public: void BotStatement::AppendPhrase(class BotPhrase const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotStatement::AppendPhrase(BotStatement *this, const BotPhrase *phrase)
{
  int m_count; // eax

  if ( phrase != nullptr )
  {
    m_count = this->m_count;
    if ( m_count < 4 )
    {
      this->m_statement[m_count].isPhrase = true;
      this->m_statement[this->m_count++].phrase = phrase;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A9420
// Name: public: unsigned int BotStatement::GetPlace(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall BotStatement::GetPlace(BotStatement *this)
{
  unsigned int result; // eax
  int m_count; // esi
  $B1D420AA4BC179AFD3650035EBAFE544 *i; // edx

  result = this->m_place;
  if ( result == 0 )
  {
    m_count = this->m_count;
    if ( m_count <= 0 )
    {
      return 0;
    }
    else
    {
      for ( i = &this->m_statement[0].___u1; LOBYTE(i[-1].phrase) == 0 || !i->phrase->m_isPlace; i += 2 )
      {
        if ( (int)++result >= m_count )
          return 0;
      }
      return this->m_statement[result].phrase->m_place;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A9460
// Name: public: void BotChatterInterface::RemoveStatement(class BotStatement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::RemoveStatement(BotChatterInterface *this, BotStatement *statement)
{
  BotStatement *m_next; // eax
  BotStatement *m_prev; // eax

  m_next = statement->m_next;
  if ( m_next != nullptr )
    m_next->m_prev = statement->m_prev;
  m_prev = statement->m_prev;
  if ( m_prev != nullptr )
    m_prev->m_next = statement->m_next;
  else
    this->m_statementList = statement->m_next;
  if ( statement->m_meme != nullptr )
    free(pMem: statement->m_meme);
  free(pMem: statement);
}

//------------------------------------------------------------------------------
// Address: 0x102A94B0
// Name: public: class BotStatement __near * BotChatterInterface::GetActiveStatement(void)
// Source: json
//------------------------------------------------------------------------------
BotStatement *__thiscall BotChatterInterface::GetActiveStatement(BotChatterInterface *this)
{
  int v1; // edi
  BotStatement *v2; // ebx
  CBasePlayer *v3; // eax
  CBaseEntity *v4; // esi
  _DWORD *v5; // eax
  BotStatement *result; // eax
  float m_timestamp; // xmm0_4
  int earlyTime; // [esp+4h] [ebp-4h]

  v1 = 1;
  v2 = nullptr;
  earlyTime = 1315859240;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v3 = UTIL_PlayerByIndex(playerIndex: v1);
      v4 = v3;
      if ( v3 != nullptr
        && (v3->IsBot(this: v3) || v4->IsAlive(this: v4))
        && CBaseEntity::InSameTeam(this: this->m_me, pEntity: v4) )
      {
        v5 = __RTDynamicCast(
               inptr: v4,
               VfDelta: 0,
               SrcType: &CBasePlayer `RTTI Type Descriptor',
               TargetType: &CCSBot `RTTI Type Descriptor',
               isReference: 0);
        if ( v5 != nullptr )
        {
          result = (BotStatement *)v5[4200];
          if ( result != nullptr )
          {
            m_timestamp = *(float *)&earlyTime;
            while ( !result->m_isSpeaking )
            {
              if ( m_timestamp > result->m_startTime )
              {
                m_timestamp = result->m_timestamp;
                earlyTime = LODWORD(m_timestamp);
                v2 = result;
              }
              result = result->m_next;
              if ( result == nullptr )
                goto LABEL_13;
            }
            return result;
          }
        }
      }
LABEL_13:
      ++v1;
    }
    while ( v1 <= gpGlobals->maxClients );
    if ( v2 != nullptr && v2->m_startTime > gpGlobals->curtime )
      return nullptr;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102A95A0
// Name: public: bool BotStatement::HasPlace(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall BotStatement::HasPlace(BotStatement *this)
{
  signed int m_place; // eax
  bool v2; // zf
  int m_count; // esi
  $B1D420AA4BC179AFD3650035EBAFE544 *v4; // edx

  m_place = this->m_place;
  v2 = m_place == 0;
  if ( m_place != 0 )
    return !v2;
  m_count = this->m_count;
  if ( m_count <= 0 )
  {
LABEL_7:
    v2 = true;
    return !v2;
  }
  v4 = &this->m_statement[0].___u1;
  while ( LOBYTE(v4[-1].phrase) == 0 || !v4->phrase->m_isPlace )
  {
    ++m_place;
    v4 += 2;
    if ( m_place >= m_count )
      goto LABEL_7;
  }
  return this->m_statement[m_place].phrase->m_place != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102A95F0
// Name: public: void CCSBot::SetTask(enum CCSBot::TaskType,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SetTask(CCSBot *this, CCSBot::TaskType task, CBaseEntity *entity)
{
  this->m_task = task;
  if ( entity != nullptr )
    this->m_taskEntity.m_Index = entity->GetRefEHandle(this: entity)->m_Index;
  else
    this->m_taskEntity.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x102A9630
// Name: public: bool BotStatement::IsRedundant(class BotStatement const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall BotStatement::IsRedundant(BotStatement *this, BotStatement *say)
{
  BotStatementType m_type; // eax
  int m_subject; // esi
  int v6; // eax
  const BotStatement *saya; // [esp+Ch] [ebp+8h]

  m_type = this->m_type;
  if ( m_type == REPORT_MY_PLAN
    || m_type == REPORT_REQUEST_HELP
    || m_type == REPORT_CRITICAL_EVENT
    || m_type == REPORT_ACKNOWLEDGE )
  {
    return 0;
  }
  if ( say->m_type == m_type )
  {
    if ( !BotStatement::HasPlace(this: say)
      && !BotStatement::HasPlace(this)
      && say->m_subject == -1
      && this->m_subject == -1 )
    {
      return 1;
    }
    if ( BotStatement::HasPlace(this: say) && BotStatement::HasPlace(this) )
    {
      saya = (const BotStatement *)BotStatement::GetPlace(this: say);
      if ( saya == (const BotStatement *)BotStatement::GetPlace(this) )
        return 1;
    }
    m_subject = say->m_subject;
    if ( m_subject != -1 )
    {
      v6 = this->m_subject;
      if ( v6 != -1 && m_subject == v6 )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102A96E0
// Name: public: BotChatterInterface::~BotChatterInterface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::~BotChatterInterface(BotChatterInterface *this)
{
  BotStatement *m_statementList; // esi
  BotStatement *m_next; // edi

  m_statementList = this->m_statementList;
  if ( this->m_statementList != nullptr )
  {
    do
    {
      m_next = m_statementList->m_next;
      if ( m_statementList->m_meme != nullptr )
        free(pMem: m_statementList->m_meme);
      free(pMem: m_statementList);
      m_statementList = m_next;
    }
    while ( m_next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A9710
// Name: public: float PathCost::operator()(class CNavArea __near *,class CNavArea __near *,class CNavLadder const __near *,class CFuncElevator const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall PathCost::operator()(
        PathCost *this,
        CNavArea *area,
        CNavArea *fromArea,
        const CNavLadder *ladder,
        const CFuncElevator *elevator,
        float length)
{
  CCSBot *m_bot; // eax
  int v8; // eax
  float m_length; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float z; // xmm0_4
  float v13; // xmm1_4
  float height; // xmm0_4
  double ApproximateFallDamage; // st7
  int m_attributeFlags; // eax
  float v17; // xmm2_4
  int TeamNumber; // eax
  double Danger; // st7
  int v20; // eax
  float v21; // [esp+30h] [ebp-20h]
  float v22; // [esp+30h] [ebp-20h]
  float v23; // [esp+30h] [ebp-20h]
  float v24; // [esp+34h] [ebp-1Ch]
  float v25; // [esp+38h] [ebp-18h]
  PathCost *size; // [esp+3Ch] [ebp-14h]
  float dangerFactor; // [esp+40h] [ebp-10h]

  m_bot = this->m_bot;
  size = this;
  v24 = (float)(1.0 - (float)(this->m_bot->m_profile->m_aggression * 0.94999999)) * 100.0;
  if ( fromArea != nullptr )
  {
    if ( ((fromArea->m_attributeFlags & 2) == 0 || (area->m_attributeFlags & 2) == 0)
      && ((area->m_attributeFlags & 0x800) == 0 || m_bot->m_hostageEscortCount == 0) )
    {
      if ( ladder != nullptr )
      {
        m_length = ladder->m_length;
      }
      else
      {
        v10 = area->m_center.x - fromArea->m_center.x;
        m_length = fsqrt(
                     (float)((float)((float)(area->m_center.y - fromArea->m_center.y)
                                   * (float)(area->m_center.y - fromArea->m_center.y))
                           + (float)((float)(area->m_center.z - fromArea->m_center.z)
                                   * (float)(area->m_center.z - fromArea->m_center.z)))
                   + (float)(v10 * v10));
      }
      v11 = fromArea->m_costSoFar + m_length;
      v25 = m_length;
      dangerFactor = v11;
      if ( cv_bot_zombie.m_pParent != nullptr && cv_bot_zombie.m_pParent->m_Value.m_nValue != 0 )
        return dangerFactor;
      if ( area->m_isUnderwater )
      {
LABEL_29:
        m_attributeFlags = area->m_attributeFlags;
        if ( (m_attributeFlags & 0x41) != 0 )
        {
          if ( this->m_route == FASTEST_ROUTE )
            v17 = 20.0;
          else
            v17 = 5.0;
          if ( (m_attributeFlags & 1) != 0 && this->m_bot->m_hostageEscortCount != 0 )
            v17 = v17 * 3.0;
          v11 = v11 + (float)(v17 * m_length);
          dangerFactor = v11;
        }
        if ( (m_attributeFlags & 2) != 0 )
        {
          v11 = v11 + m_length;
          dangerFactor = v11;
        }
        if ( gpGlobals->tickcount <= area->m_damagingTickCount )
        {
          v11 = v11 + (float)(m_length * 100.0);
          dangerFactor = v11;
        }
        if ( (m_attributeFlags & 0x80u) != 0 )
          dangerFactor = (float)(m_length * 20.0) + v11;
        if ( this->m_route == SAFEST_ROUTE )
        {
          TeamNumber = CBaseEntity::GetTeamNumber(this: this->m_bot);
          Danger = CNavArea::GetDanger(this: area, teamID: TeamNumber);
          this = size;
          dangerFactor = Danger * (v25 * v24) + dangerFactor;
        }
        if ( !CCSBot::IsAttacking(this: this->m_bot) )
        {
          v23 = (float)((float)(area->m_seCorner.y - area->m_nwCorner.y)
                      + (float)(area->m_seCorner.x - area->m_nwCorner.x))
              * 0.5;
          if ( v23 >= 1.0 )
          {
            v20 = CBaseEntity::GetTeamNumber(this: size->m_bot);
            return (float)((float)((float)((float)CNavArea::GetPlayerCount(this: area, teamID: v20) * 50000.0) / v23)
                         + dangerFactor);
          }
        }
        return dangerFactor;
      }
      if ( CNavArea::IsConnected(this: area, area: fromArea, dir: NUM_DIRECTIONS) != 0 )
        goto LABEL_27;
      v21 = -CNavArea::ComputeGroundHeightChange(this: fromArea, area);
      if ( ladder != nullptr && (z = ladder->m_bottom.z, fromArea->m_center.z > z) && (v13 = area->m_center.z, z > v13) )
        height = z - v13;
      else
        height = v21;
      ApproximateFallDamage = CCSBot::GetApproximateFallDamage(this: size->m_bot, height);
      v22 = ApproximateFallDamage;
      if ( ApproximateFallDamage <= 0.0 )
        goto LABEL_27;
      if ( (float)(v22 + 10.0) < (float)size->m_bot->m_iHealth.m_Value )
      {
        if ( size->m_route != FASTEST_ROUTE
          || v22 > (float)((float)(size->m_bot->m_profile->m_aggression * 15.0) + 10.0) )
        {
          v11 = (float)((float)(v22 * 100.0) * v22) + dangerFactor;
          dangerFactor = v11;
          this = size;
LABEL_28:
          m_length = v25;
          goto LABEL_29;
        }
LABEL_27:
        v11 = dangerFactor;
        this = size;
        goto LABEL_28;
      }
    }
    return -1.0;
  }
  if ( this->m_route == FASTEST_ROUTE )
    return 0.0;
  v8 = CBaseEntity::GetTeamNumber(this: m_bot);
  return CNavArea::GetDanger(this: area, teamID: v8) * v24;
}

//------------------------------------------------------------------------------
// Address: 0x102A9A60
// Name: class Vector const __near * GetRandomSpotAtPlace(unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const Vector *__cdecl GetRandomSpotAtPlace(unsigned int place)
{
  int v1; // ecx
  int v2; // eax
  int v3; // eax
  int v4; // ecx
  CNavArea *v5; // edx

  v1 = 0;
  v2 = 0;
  if ( TheNavAreas.m_Size <= 0 )
    return nullptr;
  do
  {
    if ( TheNavAreas.m_Memory.m_pMemory[v2]->m_place == place )
      ++v1;
    ++v2;
  }
  while ( v2 < TheNavAreas.m_Size );
  if ( v1 == 0 )
    return nullptr;
  v3 = _RandomInt(this: (IUniformRandomStream *)(v1 - 1), a2: 0, a3: v1 - 1);
  v4 = 0;
  if ( TheNavAreas.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = TheNavAreas.m_Memory.m_pMemory[v4];
    if ( v5->m_place == place && v3 == 0 )
      break;
    if ( ++v4 >= TheNavAreas.m_Size )
      return nullptr;
  }
  return &v5->m_center;
}

//------------------------------------------------------------------------------
// Address: 0x102A9AF0
// Name: public: char __near * BotPhrase::GetSpeakable(int,float __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall BotPhrase::GetSpeakable(BotPhrase *this, int bankIndex, float *duration)
{
  int v3; // edx
  CUtlVector<BotSpeakable *,CUtlMemory<BotSpeakable *,int> > *v4; // edi
  int *m_pMemory; // eax
  int v6; // esi
  BotSpeakable *v7; // esi
  unsigned int m_place; // eax
  unsigned int m_count; // edi
  unsigned int m_countCriteria; // eax
  int start; // [esp+8h] [ebp+8h]

  if ( bankIndex >= 0
    && bankIndex < this->m_numVoiceBanks
    && (v3 = bankIndex, this->m_count.m_Memory.m_pMemory[bankIndex] != 0) )
  {
    start = this->m_index.m_Memory.m_pMemory[v3];
    while ( 1 )
    {
      v4 = this->m_voiceBank.m_Memory.m_pMemory[v3];
      m_pMemory = this->m_index.m_Memory.m_pMemory;
      v6 = m_pMemory[v3];
      m_pMemory[v3] = v6 + 1;
      v7 = v4->m_Memory.m_pMemory[v6];
      if ( this->m_index.m_Memory.m_pMemory[v3] >= this->m_count.m_Memory.m_pMemory[v3] )
        this->m_index.m_Memory.m_pMemory[v3] = 0;
      m_place = v7->m_place;
      if ( m_place == 0xFFFF || m_place == this->m_placeCriteria )
      {
        m_count = v7->m_count;
        if ( m_count == 0xFFFF )
          break;
        m_countCriteria = this->m_countCriteria;
        if ( m_countCriteria >= 4 )
          m_countCriteria = 4;
        if ( m_count == m_countCriteria )
          break;
      }
      if ( this->m_index.m_Memory.m_pMemory[v3] == start )
      {
        if ( duration != nullptr )
          *duration = 0.0;
        return nullptr;
      }
    }
    if ( duration != nullptr )
      *duration = v7->m_duration;
    return v7->m_phrase;
  }
  else
  {
    if ( duration != nullptr )
      *duration = 0.0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A9BD0
// Name: public: void BotPhrase::Randomize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotPhrase::Randomize(BotPhrase *this)
{
  int v1; // edx
  CUtlVector<BotSpeakable *,CUtlMemory<BotSpeakable *,int> > *v2; // edi
  int m_Size; // eax
  int v4; // esi
  int v5; // eax
  BotSpeakable *v6; // edx
  BotPhrase *v7; // [esp+0h] [ebp-8h]
  int bank; // [esp+4h] [ebp-4h]

  v1 = 0;
  v7 = this;
  for ( bank = 0; v1 < this->m_voiceBank.m_Size; bank = v1 )
  {
    v2 = this->m_voiceBank.m_Memory.m_pMemory[v1];
    m_Size = v2->m_Size;
    if ( m_Size != 1 )
    {
      v4 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v5 = _RandomInt((IUniformRandomStream *)this, a2: 0, a3: m_Size - 1);
          v6 = v2->m_Memory.m_pMemory[v4];
          v2->m_Memory.m_pMemory[v4] = v2->m_Memory.m_pMemory[v5];
          this = (BotPhrase *)v2->m_Memory.m_pMemory;
          v2->m_Memory.m_pMemory[v5] = v6;
          m_Size = v2->m_Size;
          ++v4;
        }
        while ( v4 < m_Size );
        v1 = bank;
        this = v7;
      }
    }
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A9C40
// Name: public: void BotPhraseManager::OnRoundRestart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotPhraseManager::OnRoundRestart(BotPhraseManager *this)
{
  BotPhraseManager *v1; // ebx
  int v2; // eax
  BotPhrase *v3; // edx
  int v4; // ecx
  int *v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // edx
  int j; // esi
  BotPhrase *v12; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  IUniformRandomStream *v14; // [esp+14h] [ebp-4h]

  v1 = this;
  v2 = 0;
  this->m_placeCount = 0;
  for ( i = 0; v2 < v1->m_placeList.m_Size; i = v2 )
  {
    v3 = v1->m_placeList.m_Memory.m_pMemory[v2];
    v4 = 0;
    v12 = v3;
    v14 = nullptr;
    if ( v3->m_voiceBank.m_Size > 0 )
    {
      do
      {
        v5 = (int *)v3->m_voiceBank.m_Memory.m_pMemory[v4];
        v6 = v5[3];
        if ( v6 != 1 )
        {
          v7 = 0;
          if ( v6 > 0 )
          {
            do
            {
              v8 = _RandomInt(this: (IUniformRandomStream *)v4, a2: 0, a3: v6 - 1);
              v9 = *(_DWORD *)(*v5 + 4 * v7);
              *(_DWORD *)(*v5 + 4 * v7) = *(_DWORD *)(*v5 + 4 * v8);
              v4 = *v5;
              *(_DWORD *)(*v5 + 4 * v8) = v9;
              v6 = v5[3];
              ++v7;
            }
            while ( v7 < v6 );
            v3 = v12;
            v4 = (int)v14;
            v1 = this;
          }
        }
        v14 = (IUniformRandomStream *)++v4;
      }
      while ( v4 < v3->m_voiceBank.m_Size );
      v2 = i;
    }
    ++v2;
  }
  for ( j = 0; j < v1->m_list.m_Size; ++j )
    BotPhrase::Randomize(this: v1->m_list.m_Memory.m_pMemory[j]);
}

//------------------------------------------------------------------------------
// Address: 0x102A9CF0
// Name: public: class BotPhrase const __near * BotPhraseManager::GetPhrase(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const BotPhrase *__thiscall BotPhraseManager::GetPhrase(BotPhraseManager *this, const char *name)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_list.m_Size <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: this->m_list.m_Memory.m_pMemory[v3]->m_name, s2: name) != 0 )
  {
    if ( ++v3 >= this->m_list.m_Size )
      return nullptr;
  }
  return this->m_list.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x102A9D40
// Name: public: class BotPhrase const __near * BotPhraseManager::GetPlace(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const BotPhrase *__thiscall BotPhraseManager::GetPlace(BotPhraseManager *this, const char *name)
{
  int v4; // esi

  if ( name == nullptr )
    return nullptr;
  v4 = 0;
  if ( this->m_placeList.m_Size <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: this->m_placeList.m_Memory.m_pMemory[v4]->m_name, s2: name) != 0 )
  {
    if ( ++v4 >= this->m_placeList.m_Size )
      return nullptr;
  }
  return this->m_placeList.m_Memory.m_pMemory[v4];
}

//------------------------------------------------------------------------------
// Address: 0x102A9DA0
// Name: public: bool BotStatement::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall BotStatement::IsValid(BotStatement *this)
{
  BotStatement *v1; // esi
  int v2; // edi
  CBasePlayer *v3; // eax
  CBaseEntity *v4; // esi
  int TeamNumber; // ebx
  CBaseEntity *m_me; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  BotStatement::ConditionType *j; // [esp+18h] [ebp-8h]
  int v11; // [esp+1Ch] [ebp-4h]

  v1 = this;
  i = 0;
  if ( this->m_conditionCount <= 0 )
    return 1;
  for ( j = this->m_condition; *j == IS_IN_COMBAT; ++j )
  {
    if ( !CCSBot::IsAttacking(this: v1->m_chatter->m_me) )
      return 0;
LABEL_16:
    if ( ++i >= v1->m_conditionCount )
      return 1;
  }
  if ( *j != ENEMIES_REMAINING )
    goto LABEL_16;
  v2 = 1;
  m_me = v1->m_chatter->m_me;
  v11 = 0;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v3 = UTIL_PlayerByIndex(playerIndex: v2);
      v4 = v3;
      if ( v3 != nullptr && v3->IsPlayer(this: v3) && v4->IsAlive(this: v4) )
      {
        TeamNumber = CBaseEntity::GetTeamNumber(this: v4);
        if ( TeamNumber != CBaseEntity::GetTeamNumber(this: m_me) && v4->IsAlive(this: v4) )
          ++v11;
      }
      ++v2;
    }
    while ( v2 <= gpGlobals->maxClients );
    if ( v11 != 0 )
    {
      v1 = this;
      goto LABEL_16;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102A9EB0
// Name: public: void BotChatterInterface::ResetRadioSilenceDuration(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::ResetRadioSilenceDuration(BotChatterInterface *this)
{
  char *v1; // esi
  double v2; // st7
  double v3; // st6
  float *v4; // esi
  float v5; // [esp+4h] [ebp-4h]

  v1 = (char *)&BotChatterInterface::m_radioSilenceInterval + 8 * (CBaseEntity::GetTeamNumber(this: this->m_me) % 2);
  v2 = IntervalTimer::Now(this: (CEffectsServer *)v1);
  v3 = *((float *)v1 + 1);
  v4 = (float *)(v1 + 4);
  if ( v3 != v2 )
  {
    (*(void (__thiscall **)(float *, float *))(*((_DWORD *)v4 - 1) + 4))(a1: v4 - 1, a2: v4);
    v5 = v2;
    *v4 = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A9F10
// Name: void SayWhere(class BotStatement __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SayWhere(BotStatement *say, unsigned int place)
{
  int m_Size; // edx
  int v3; // eax
  BotPhrase **i; // ecx
  const BotPhrase *v5; // eax
  int m_count; // edx

  if ( place != 0 )
  {
    m_Size = TheBotPhrases->m_placeList.m_Size;
    v3 = 0;
    if ( m_Size > 0 )
    {
      for ( i = TheBotPhrases->m_placeList.m_Memory.m_pMemory; (*i)->m_place != place; ++i )
      {
        if ( ++v3 >= m_Size )
          return;
      }
      v5 = TheBotPhrases->m_placeList.m_Memory.m_pMemory[v3];
      if ( v5 != nullptr )
      {
        m_count = say->m_count;
        if ( m_count < 4 )
        {
          say->m_statement[m_count].isPhrase = true;
          say->m_statement[say->m_count++].phrase = v5;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AA510
// Name: private: int BotPhraseManager::FindPlaceIndex(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall BotPhraseManager::FindPlaceIndex(BotPhraseManager *this, unsigned int where)
{
  int m_placeCount; // edx
  int result; // eax
  BotPhraseManager::PlaceTimeInfo *m_placeStatementHistory; // ecx
  int v6; // eax
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi

  m_placeCount = this->m_placeCount;
  result = 0;
  if ( m_placeCount <= 0 )
  {
LABEL_5:
    if ( m_placeCount >= 64 )
    {
      return -1;
    }
    else
    {
      this->m_placeCount = m_placeCount + 1;
      this->m_placeStatementHistory[m_placeCount + 1].placeID = where;
      v6 = ++this->m_placeCount;
      p_m_timestamp = &this->m_placeStatementHistory[v6].timer.m_timestamp;
      if ( p_m_timestamp->m_Value != -1.0 )
      {
        this->m_placeStatementHistory[v6].timer.NetworkStateChanged(
          this: &this->m_placeStatementHistory[v6].timer,
          a2: &this->m_placeStatementHistory[v6].timer.m_timestamp);
        p_m_timestamp->m_Value = -1.0;
      }
      return this->m_placeCount - 1;
    }
  }
  else
  {
    m_placeStatementHistory = this->m_placeStatementHistory;
    while ( m_placeStatementHistory->placeID != where )
    {
      ++result;
      ++m_placeStatementHistory;
      if ( result >= m_placeCount )
        goto LABEL_5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102AA5B0
// Name: public: float BotPhraseManager::GetPlaceStatementInterval(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall BotPhraseManager::GetPlaceStatementInterval(BotPhraseManager *this, unsigned int place)
{
  int PlaceIndex; // eax
  int v5; // ecx
  float v6; // xmm0_4
  CEffectsServer *v7; // esi

  PlaceIndex = BotPhraseManager::FindPlaceIndex(this, where: place);
  if ( PlaceIndex < 0 || PlaceIndex >= this->m_placeCount )
    return 999999.88;
  v5 = 3 * PlaceIndex + 18;
  v6 = *((float *)&this->m_list.m_Memory.m_nAllocationCount + v5);
  v7 = (CEffectsServer *)(&this->m_list.m_Memory.m_pMemory + v5);
  if ( v6 <= 0.0 )
    return 99999.898;
  else
    return IntervalTimer::Now(this: v7) - *(float *)&v7->m_pNextSystem;
}

//------------------------------------------------------------------------------
// Address: 0x102AA610
// Name: public: void BotPhraseManager::ResetPlaceStatementInterval(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotPhraseManager::ResetPlaceStatementInterval(BotPhraseManager *this, unsigned int place)
{
  int PlaceIndex; // eax
  IntervalTimer *p_timer; // esi
  double v5; // st7
  double m_Value; // st6
  float *p_m_Value; // esi
  float placea; // [esp+Ch] [ebp+8h]

  PlaceIndex = BotPhraseManager::FindPlaceIndex(this, where: place);
  if ( PlaceIndex >= 0 && PlaceIndex < this->m_placeCount )
  {
    p_timer = &this->m_placeStatementHistory[PlaceIndex].timer;
    v5 = IntervalTimer::Now(this: (CEffectsServer *)p_timer);
    m_Value = p_timer->m_timestamp.m_Value;
    p_m_Value = &p_timer->m_timestamp.m_Value;
    if ( m_Value != v5 )
    {
      (*(void (__thiscall **)(float *, float *))(*((_DWORD *)p_m_Value - 1) + 4))(a1: p_m_Value - 1, a2: p_m_Value);
      placea = v5;
      *p_m_Value = placea;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AA670
// Name: public: virtual void BotHeardNoiseMeme::Interpret(class CCSBot __near *,class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotHeardNoiseMeme::Interpret(BotHeardNoiseMeme *this, CCSBot *sender, CCSBot *receiver)
{
  double v4; // st7
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  float receivera; // [esp+14h] [ebp+Ch]

  v4 = IntervalTimer::Now(this: (CEffectsServer *)&receiver->m_chatter.m_heardNoiseTimer) + 20.0;
  p_m_timestamp = &receiver->m_chatter.m_heardNoiseTimer.m_timestamp;
  if ( receiver->m_chatter.m_heardNoiseTimer.m_timestamp.m_Value != v4 )
  {
    receiver->m_chatter.m_heardNoiseTimer.NetworkStateChanged(
      this: &receiver->m_chatter.m_heardNoiseTimer,
      a2: &receiver->m_chatter.m_heardNoiseTimer.m_timestamp);
    receivera = v4;
    p_m_timestamp->m_Value = receivera;
  }
  if ( receiver->m_chatter.m_heardNoiseTimer.m_duration.m_Value != 20.0 )
  {
    receiver->m_chatter.m_heardNoiseTimer.NetworkStateChanged(
      this: &receiver->m_chatter.m_heardNoiseTimer,
      a2: &receiver->m_chatter.m_heardNoiseTimer.m_duration);
    receiver->m_chatter.m_heardNoiseTimer.m_duration.m_Value = 20.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AA6F0
// Name: public: virtual void BotWarnSniperMeme::Interpret(class CCSBot __near *,class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotWarnSniperMeme::Interpret(BotWarnSniperMeme *this, CCSBot *sender, CCSBot *receiver)
{
  double v4; // st7
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  float receivera; // [esp+14h] [ebp+Ch]

  v4 = IntervalTimer::Now(this: (CEffectsServer *)&receiver->m_chatter.m_warnSniperTimer) + 60.0;
  p_m_timestamp = &receiver->m_chatter.m_warnSniperTimer.m_timestamp;
  if ( receiver->m_chatter.m_warnSniperTimer.m_timestamp.m_Value != v4 )
  {
    receiver->m_chatter.m_warnSniperTimer.NetworkStateChanged(
      this: &receiver->m_chatter.m_warnSniperTimer,
      a2: &receiver->m_chatter.m_warnSniperTimer.m_timestamp);
    receivera = v4;
    p_m_timestamp->m_Value = receivera;
  }
  if ( receiver->m_chatter.m_warnSniperTimer.m_duration.m_Value != 60.0 )
  {
    receiver->m_chatter.m_warnSniperTimer.NetworkStateChanged(
      this: &receiver->m_chatter.m_warnSniperTimer,
      a2: &receiver->m_chatter.m_warnSniperTimer.m_duration);
    receiver->m_chatter.m_warnSniperTimer.m_duration.m_Value = 60.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AA770
// Name: public: bool BotStatement::Update(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall BotStatement::Update(BotStatement *this)
{
  CCSBot *m_me; // ebx
  IUniformRandomStream *v3; // ecx
  int m_index; // eax
  int m_nearbyEnemyCount; // edi
  int v7; // eax
  int v8; // eax
  BotMeme *m_meme; // esi
  bool v10; // zf
  const BotPhrase *phrase; // edi
  int NearbyEnemyCount; // ebx
  BotMeme *v13; // eax
  BotChatterInterface *p_m_chatter; // ebx
  RadioType m_radioEvent; // edi
  unsigned int EnemiesRemaining; // eax
  CCSBot *v17; // eax
  const char *Speakable; // ebx
  RadioType v19; // edi
  BotChatterInterface *v20; // [esp+14h] [ebp-Ch]
  float duration; // [esp+18h] [ebp-8h] BYREF
  CCSBot *me; // [esp+1Ch] [ebp-4h]

  m_me = this->m_chatter->m_me;
  me = m_me;
  if ( CBot<CCSPlayer>::GetFriendsRemaining(this: m_me) == 0 && this->m_type != REPORT_EMOTE )
    return 0;
  if ( !this->m_isSpeaking )
  {
    this->m_isSpeaking = true;
    v3 = (IUniformRandomStream *)gpGlobals;
    this->m_speakTimestamp = gpGlobals->curtime;
  }
  m_index = this->m_index;
  if ( m_index >= 0 && this->m_statement[m_index].phrase == (const BotPhrase *)4 )
  {
    m_nearbyEnemyCount = m_me->m_nearbyEnemyCount;
    v7 = CBot<CCSPlayer>::GetEnemiesRemaining(this: m_me) >= m_nearbyEnemyCount
       ? m_nearbyEnemyCount
       : CBot<CCSPlayer>::GetEnemiesRemaining(this: m_me);
    if ( v7 > 3 || (float)(gpGlobals->curtime - this->m_speakTimestamp) > 2.0 )
      this->m_nextTime = 0.0;
  }
  if ( gpGlobals->curtime <= this->m_nextTime )
    return 1;
  v8 = ++this->m_index;
  if ( v8 != this->m_count )
  {
    v10 = !this->m_statement[v8].isPhrase;
    duration = 0.0;
    if ( !v10 )
    {
      phrase = this->m_statement[v8].phrase;
LABEL_28:
      if ( phrase != nullptr )
      {
        p_m_chatter = &m_me->m_chatter;
        v20 = p_m_chatter;
        if ( BotChatterInterface::GetVerbosity(this: p_m_chatter) == 2 )
        {
          m_radioEvent = phrase->m_radioEvent;
          if ( m_radioEvent != RADIO_INVALID )
          {
            BotChatterInterface::ResetRadioSilenceDuration(this: p_m_chatter);
            CCSBot::SendRadioMessage(this: me, event: m_radioEvent);
            duration = 2.0;
            goto LABEL_47;
          }
        }
        else
        {
          v17 = me;
          phrase->m_placeCriteria = this->m_place;
          Speakable = BotPhrase::GetSpeakable(this: phrase, bankIndex: v17->m_profile->m_voiceBank, &duration);
          if ( phrase->m_isPlace )
          {
            if ( BotPhraseManager::GetPlaceStatementInterval(this: TheBotPhrases, place: phrase->m_place) < 20.0 )
              goto LABEL_47;
            BotPhraseManager::ResetPlaceStatementInterval(this: TheBotPhrases, place: phrase->m_place);
          }
          if ( Speakable != nullptr )
          {
            CCSBot::SpeakAudio(
              this: me,
              voiceFilename: Speakable,
              duration: duration + 1.0,
              pitch: me->m_profile->m_voicePitch);
            goto LABEL_47;
          }
          v19 = phrase->m_radioEvent;
          if ( v19 != RADIO_INVALID )
          {
            CCSBot::SendRadioMessage(this: me, event: v19);
            BotChatterInterface::ResetRadioSilenceDuration(this: v20);
            duration = 2.0;
            goto LABEL_47;
          }
        }
        this->m_nextTime = 0.0;
LABEL_47:
        this->m_nextTime = (float)(gpGlobals->curtime + duration) + 0.1;
        return 1;
      }
      goto LABEL_48;
    }
    switch ( (unsigned int)this->m_statement[v8].phrase )
    {
      case 0u:
        NearbyEnemyCount = CCSBot::GetNearbyEnemyCount(this: m_me);
        if ( NearbyEnemyCount - 1 <= CCSBot::GetNearbyFriendCount(this: me) )
        {
          if ( NearbyEnemyCount <= 1 )
          {
LABEL_48:
            this->m_nextTime = 0.0;
            return 1;
          }
          phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "EnemySpotted");
          phrase->m_countCriteria = NearbyEnemyCount;
        }
        else
        {
          phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "Help");
          v13 = (BotMeme *)operator new(nSize: 8u);
          if ( v13 != nullptr )
          {
            v13->__vftable = (BotMeme_vtbl *)&BotHelpMeme::`vftable';
            v13[1].__vftable = nullptr;
          }
          else
          {
            v13 = nullptr;
          }
          this->m_meme = v13;
        }
        m_me = me;
        goto LABEL_28;
      case 1u:
        EnemiesRemaining = CBot<CCSPlayer>::GetEnemiesRemaining(this: m_me);
        if ( EnemiesRemaining > 3 )
          goto LABEL_48;
        phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: speak[EnemiesRemaining]);
        goto LABEL_28;
      case 2u:
        this->m_nextTime = _RandomFloat(this: v3, a2: 0.1, a3: 0.5) + gpGlobals->curtime;
        return 1;
      case 3u:
        this->m_nextTime = _RandomFloat(this: v3, a2: 1.0, a3: 2.0) + gpGlobals->curtime;
        return 1;
      case 4u:
        this->m_nextTime = 100000000.0;
        return 1;
      default:
        goto LABEL_48;
    }
  }
  m_meme = this->m_meme;
  if ( m_meme != nullptr )
    BotMeme::Transmit(this: m_meme, sender: m_me);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102AAAD0
// Name: public: void BotChatterInterface::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::Reset(BotChatterInterface *this)
{
  BotStatement *m_statementList; // esi
  BotStatement *m_next; // ebx
  BotStatement *m_prev; // eax
  CCSBot *m_me; // ecx
  char *v6; // esi
  double v7; // st7
  double v8; // st6
  float *v9; // esi
  float v10; // [esp+8h] [ebp-4h]

  m_statementList = this->m_statementList;
  if ( this->m_statementList != nullptr )
  {
    do
    {
      m_next = m_statementList->m_next;
      if ( m_statementList->m_type != REPORT_ROUND_END )
      {
        if ( m_next != nullptr )
          m_next->m_prev = m_statementList->m_prev;
        m_prev = m_statementList->m_prev;
        if ( m_prev != nullptr )
          m_prev->m_next = m_statementList->m_next;
        else
          this->m_statementList = m_statementList->m_next;
        if ( m_statementList->m_meme != nullptr )
          free(pMem: m_statementList->m_meme);
        free(pMem: m_statementList);
      }
      m_statementList = m_next;
    }
    while ( m_next != nullptr );
  }
  m_me = this->m_me;
  this->m_seeAtLeastOneEnemy = false;
  this->m_timeWhenSawFirstEnemy = 0.0;
  *(_WORD *)&this->m_reportedEnemies = 0;
  v6 = (char *)&BotChatterInterface::m_radioSilenceInterval + 8 * (CBaseEntity::GetTeamNumber(this: m_me) % 2);
  v7 = IntervalTimer::Now(this: (CEffectsServer *)v6);
  v8 = *((float *)v6 + 1);
  v9 = (float *)(v6 + 4);
  if ( v8 != v7 )
  {
    (*(void (__thiscall **)(float *, float *))(*((_DWORD *)v9 - 1) + 4))(a1: v9 - 1, a2: v9);
    v10 = v7;
    *v9 = v10;
  }
  if ( this->m_needBackupInterval.m_timestamp.m_Value != -1.0 )
  {
    this->m_needBackupInterval.NetworkStateChanged(
      this: &this->m_needBackupInterval,
      a2: &this->m_needBackupInterval.m_timestamp);
    this->m_needBackupInterval.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_spottedBomberInterval.m_timestamp.m_Value != -1.0 )
  {
    this->m_spottedBomberInterval.NetworkStateChanged(
      this: &this->m_spottedBomberInterval,
      a2: &this->m_spottedBomberInterval.m_timestamp);
    this->m_spottedBomberInterval.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_spottedLooseBombTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_spottedLooseBombTimer.NetworkStateChanged(
      this: &this->m_spottedLooseBombTimer,
      a2: &this->m_spottedLooseBombTimer.m_timestamp);
    this->m_spottedLooseBombTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_heardNoiseTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_heardNoiseTimer.NetworkStateChanged(
      this: &this->m_heardNoiseTimer,
      a2: &this->m_heardNoiseTimer.m_timestamp);
    this->m_heardNoiseTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_scaredInterval.m_timestamp.m_Value != -1.0 )
  {
    this->m_scaredInterval.NetworkStateChanged(this: &this->m_scaredInterval, a2: &this->m_scaredInterval.m_timestamp);
    this->m_scaredInterval.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_planInterval.m_timestamp.m_Value != -1.0 )
  {
    this->m_planInterval.NetworkStateChanged(this: &this->m_planInterval, a2: &this->m_planInterval.m_timestamp);
    this->m_planInterval.m_timestamp.m_Value = -1.0;
  }
  if ( BotChatterInterface::m_encourageTimer.m_timestamp.m_Value != -1.0 )
  {
    BotChatterInterface::m_encourageTimer.NetworkStateChanged(
      this: &BotChatterInterface::m_encourageTimer,
      a2: &BotChatterInterface::m_encourageTimer.m_timestamp);
    BotChatterInterface::m_encourageTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_escortingHostageTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_escortingHostageTimer.NetworkStateChanged(
      this: &this->m_escortingHostageTimer,
      a2: &this->m_escortingHostageTimer.m_timestamp);
    this->m_escortingHostageTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_warnSniperTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_warnSniperTimer.NetworkStateChanged(
      this: &this->m_warnSniperTimer,
      a2: &this->m_warnSniperTimer.m_timestamp);
    this->m_warnSniperTimer.m_timestamp.m_Value = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AAD10
// Name: public: void BotChatterInterface::OnDeath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::OnDeath(BotChatterInterface *this)
{
  char *m_pszString; // eax
  char v3; // al
  BotPhrase *m_painPhrase; // ecx
  const BotProfile *m_profile; // eax
  const char *Speakable; // eax
  int m_voicePitch; // [esp+4h] [ebp-8h]

  if ( this->m_statementList != nullptr
    && this->m_statementList->m_isSpeaking
    && ((cv_bot_chatter.m_nFlags & 0x1000) == 0
     && (m_pszString = cv_bot_chatter.m_pParent->m_Value.m_pszString) != nullptr
     && ((v3 = *m_pszString) == 109 || v3 == 77)
     || BotChatterInterface::GetVerbosity(this: &this->m_me->m_chatter) == 0) )
  {
    m_painPhrase = TheBotPhrases->m_painPhrase;
    if ( m_painPhrase != nullptr )
    {
      m_profile = this->m_me->m_profile;
      m_voicePitch = m_profile->m_voicePitch;
      Speakable = BotPhrase::GetSpeakable(this: m_painPhrase, bankIndex: m_profile->m_voiceBank, duration: nullptr);
      CCSBot::SpeakAudio(this: this->m_me, voiceFilename: Speakable, duration: 0.0, pitch: m_voicePitch);
    }
  }
  BotChatterInterface::Reset(this);
}

//------------------------------------------------------------------------------
// Address: 0x102AB320
// Name: public: BotPhraseManager::BotPhraseManager(void)
// Source: json
//------------------------------------------------------------------------------
BotPhraseManager *__thiscall BotPhraseManager::BotPhraseManager(BotPhraseManager *this)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  void (__stdcall *v3)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *); // edx
  int v5; // [esp+Ch] [ebp-4h]

  this->m_list.m_Memory.m_pMemory = nullptr;
  this->m_list.m_Memory.m_nAllocationCount = 0;
  this->m_list.m_Memory.m_nGrowSize = 0;
  this->m_list.m_Size = 0;
  this->m_list.m_pElements = nullptr;
  this->m_placeList.m_Memory.m_pMemory = nullptr;
  this->m_placeList.m_Memory.m_nAllocationCount = 0;
  this->m_placeList.m_Memory.m_nGrowSize = 0;
  this->m_placeList.m_Size = 0;
  this->m_placeList.m_pElements = nullptr;
  this->m_output.m_Memory.m_pMemory = nullptr;
  this->m_output.m_Memory.m_nAllocationCount = 0;
  this->m_output.m_Memory.m_nGrowSize = 0;
  this->m_output.m_Size = 0;
  this->m_output.m_pElements = nullptr;
  v5 = 63;
  p_m_timestamp = &this->m_placeStatementHistory[0].timer.m_timestamp;
  do
  {
    LODWORD(p_m_timestamp[-1].m_Value) = &IntervalTimer::`vftable';
    v3 = *(void (__stdcall **)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-1].m_Value)
                                                                                              + 4);
    p_m_timestamp->m_Value = -1.0;
    v3(a1: p_m_timestamp);
    p_m_timestamp += 3;
    --v5;
  }
  while ( v5 >= 0 );
  this->m_placeCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102AB3A0
// Name: public: BotChatterInterface::BotChatterInterface(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
BotChatterInterface *__userpurge BotChatterInterface::BotChatterInterface@<eax>(
        BotChatterInterface *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CCSBot *me)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // eax
  IntervalTimer *p_m_needBackupInterval; // ecx
  IntervalTimer_vtbl *v7; // edx
  IntervalTimer_vtbl *v8; // edx
  IntervalTimer_vtbl *v9; // edx
  IntervalTimer_vtbl *v10; // edx
  CountdownTimer_vtbl *v11; // edx
  CountdownTimer_vtbl *v12; // edx
  CountdownTimer_vtbl *v13; // edx
  CountdownTimer_vtbl *v14; // edx
  CountdownTimer_vtbl *v15; // edx
  CountdownTimer_vtbl *v16; // edx
  CountdownTimer_vtbl *v17; // edx
  CountdownTimer_vtbl *v18; // edx
  int v19; // eax
  bool v20; // zf
  int v21; // eax
  int v22; // eax

  p_m_timestamp = &this->m_needBackupInterval.m_timestamp;
  p_m_needBackupInterval = &this->m_needBackupInterval;
  this->m_needBackupInterval.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v7 = p_m_needBackupInterval->__vftable;
  p_m_timestamp->m_Value = -1.0;
  ((void (__thiscall *)(IntervalTimer *, CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *, int, int))v7->NetworkStateChanged)(
    a1: p_m_needBackupInterval,
    a2: p_m_timestamp,
    a3: a2,
    a4: a3);
  this->m_spottedBomberInterval.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v8 = this->m_spottedBomberInterval.__vftable;
  this->m_spottedBomberInterval.m_timestamp.m_Value = -1.0;
  ((void (__cdecl *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v8->NetworkStateChanged)(a1: &this->m_spottedBomberInterval.m_timestamp);
  this->m_scaredInterval.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v9 = this->m_scaredInterval.__vftable;
  this->m_scaredInterval.m_timestamp.m_Value = -1.0;
  ((void (__cdecl *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v9->NetworkStateChanged)(a1: &this->m_scaredInterval.m_timestamp);
  this->m_planInterval.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v10 = this->m_planInterval.__vftable;
  this->m_planInterval.m_timestamp.m_Value = -1.0;
  ((void (__cdecl *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v10->NetworkStateChanged)(a1: &this->m_planInterval.m_timestamp);
  this->m_spottedLooseBombTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v11 = this->m_spottedLooseBombTimer.__vftable;
  this->m_spottedLooseBombTimer.m_duration.m_Value = 0.0;
  ((void (__cdecl *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v11->NetworkStateChanged)(a1: &this->m_spottedLooseBombTimer.m_duration);
  v12 = this->m_spottedLooseBombTimer.__vftable;
  this->m_spottedLooseBombTimer.m_timestamp.m_Value = -1.0;
  v12->NetworkStateChanged(this: &this->m_spottedLooseBombTimer, a2: &this->m_spottedLooseBombTimer.m_timestamp);
  this->m_heardNoiseTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v13 = this->m_heardNoiseTimer.__vftable;
  this->m_heardNoiseTimer.m_duration.m_Value = 0.0;
  ((void (__cdecl *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v13->NetworkStateChanged)(a1: &this->m_heardNoiseTimer.m_duration);
  v14 = this->m_heardNoiseTimer.__vftable;
  this->m_heardNoiseTimer.m_timestamp.m_Value = -1.0;
  v14->NetworkStateChanged(this: &this->m_heardNoiseTimer, a2: &this->m_heardNoiseTimer.m_timestamp);
  this->m_escortingHostageTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v15 = this->m_escortingHostageTimer.__vftable;
  this->m_escortingHostageTimer.m_duration.m_Value = 0.0;
  ((void (__cdecl *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v15->NetworkStateChanged)(a1: &this->m_escortingHostageTimer.m_duration);
  v16 = this->m_escortingHostageTimer.__vftable;
  this->m_escortingHostageTimer.m_timestamp.m_Value = -1.0;
  v16->NetworkStateChanged(this: &this->m_escortingHostageTimer, a2: &this->m_escortingHostageTimer.m_timestamp);
  this->m_warnSniperTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v17 = this->m_warnSniperTimer.__vftable;
  this->m_warnSniperTimer.m_duration.m_Value = 0.0;
  ((void (__cdecl *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v17->NetworkStateChanged)(a1: &this->m_warnSniperTimer.m_duration);
  v18 = this->m_warnSniperTimer.__vftable;
  this->m_warnSniperTimer.m_timestamp.m_Value = -1.0;
  v18->NetworkStateChanged(this: &this->m_warnSniperTimer, a2: &this->m_warnSniperTimer.m_timestamp);
  v19 = nextPitch;
  v20 = nextPitch == 0;
  this->m_me = me;
  this->m_statementList = nullptr;
  if ( v20 )
  {
    v22 = _RandomInt(this: (IUniformRandomStream *)me, a2: 105, a3: 110);
    goto LABEL_7;
  }
  v21 = v19 - 1;
  if ( v21 == 0 )
  {
    v22 = _RandomInt(this: (IUniformRandomStream *)me, a2: 95, a3: 105);
    goto LABEL_7;
  }
  if ( v21 == 1 )
  {
    v22 = _RandomInt(this: (IUniformRandomStream *)me, a2: 85, a3: 95);
LABEL_7:
    this->m_pitch = v22;
  }
  nextPitch = (nextPitch + 1) % 3;
  BotChatterInterface::Reset(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102AB550
// Name: public: void BotChatterInterface::AddStatement(class BotStatement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::AddStatement(BotChatterInterface *this, BotStatement *statement, bool mustAdd)
{
  char *m_pszString; // eax
  char v5; // al
  BotStatement *v6; // esi
  char *v7; // eax
  char v8; // al
  BotStatement *m_statementList; // ebx
  BotStatement *v10; // edi
  BotStatement *v11; // ecx
  BotStatement *i; // eax
  BotStatement *m_next; // eax

  if ( (cv_bot_chatter.m_nFlags & 0x1000) == 0 )
  {
    m_pszString = cv_bot_chatter.m_pParent->m_Value.m_pszString;
    if ( m_pszString != nullptr )
    {
      v5 = *m_pszString;
      if ( v5 != 109 && v5 != 77 && v5 != 114 && v5 != 82 && (v5 == 111 || v5 == 79) )
      {
        v6 = statement;
        goto LABEL_10;
      }
    }
  }
  v6 = statement;
  if ( (cv_bot_chatter.m_nFlags & 0x1000) == 0
    && (v7 = cv_bot_chatter.m_pParent->m_Value.m_pszString) != nullptr
    && ((v8 = *v7) == 109 || v8 == 77)
    && BotStatement::IsImportant(this: statement) == 0
    || !this->m_me->IsAlive(this: this->m_me) && !mustAdd )
  {
LABEL_10:
    if ( v6 == nullptr )
      return;
    goto LABEL_11;
  }
  if ( statement->m_count == 0 )
  {
LABEL_11:
    if ( v6->m_meme != nullptr )
      free(pMem: v6->m_meme);
    free(pMem: v6);
    return;
  }
  m_statementList = this->m_statementList;
  v10 = this->m_statementList;
  if ( v10 != nullptr )
  {
    while ( BotStatement::IsRedundant(this: statement, say: v10) == 0 )
    {
      v10 = v10->m_next;
      if ( v10 == nullptr )
        goto LABEL_25;
    }
    CBot<CCSPlayer>::PrintIfWatched(this: this->m_me, format: "I tried to say something I'm already saying.\n");
    if ( statement->m_meme != nullptr )
      free(pMem: statement->m_meme);
    free(pMem: statement);
  }
  else
  {
LABEL_25:
    if ( m_statementList != nullptr )
    {
      v11 = nullptr;
      for ( i = m_statementList; i != nullptr; i = i->m_next )
      {
        if ( i->m_startTime > statement->m_startTime )
          break;
        v11 = i;
      }
      if ( v11 != nullptr )
      {
        m_next = v11->m_next;
        if ( m_next != nullptr )
          m_next->m_prev = statement;
        statement->m_next = v11->m_next;
        v11->m_next = statement;
        statement->m_prev = v11;
      }
      else
      {
        statement->m_prev = nullptr;
        statement->m_next = this->m_statementList;
        this->m_statementList->m_prev = statement;
        this->m_statementList = statement;
      }
    }
    else
    {
      statement->m_next = nullptr;
      statement->m_prev = nullptr;
      this->m_statementList = statement;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB6D0
// Name: public: void BotChatterInterface::EnemySpotted(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::EnemySpotted(BotChatterInterface *this)
{
  unsigned int m_enemyPlace; // ebx
  BotStatement *v3; // eax
  double curtime; // st7
  int m_Size; // esi
  int v6; // ecx
  BotPhrase **m_pMemory; // edx
  BotPhrase *v8; // ecx
  int m_count; // esi
  int v10; // ecx
  int v11; // ecx
  int m_conditionCount; // ecx

  m_enemyPlace = this->m_me->m_enemyPlace;
  v3 = (BotStatement *)operator new(nSize: 0x70u);
  if ( v3 != nullptr )
  {
    v3->m_chatter = this;
    v3->m_next = nullptr;
    v3->m_prev = nullptr;
    curtime = gpGlobals->curtime;
    v3->m_speakTimestamp = 0.0;
    v3->m_timestamp = curtime;
    v3->m_type = REPORT_VISIBLE_ENEMIES;
    v3->m_subject = -1;
    v3->m_place = 0;
    v3->m_meme = nullptr;
    v3->m_startTime = gpGlobals->curtime;
    v3->m_expireTime = gpGlobals->curtime + 10.0;
    v3->m_isSpeaking = false;
    v3->m_nextTime = 0.0;
    v3->m_index = -1;
    v3->m_count = 0;
    v3->m_conditionCount = 0;
  }
  else
  {
    v3 = nullptr;
  }
  if ( m_enemyPlace != 0 )
  {
    m_Size = TheBotPhrases->m_placeList.m_Size;
    v6 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = TheBotPhrases->m_placeList.m_Memory.m_pMemory;
      while ( (*m_pMemory)->m_place != m_enemyPlace )
      {
        ++v6;
        ++m_pMemory;
        if ( v6 >= m_Size )
          goto LABEL_13;
      }
      v8 = TheBotPhrases->m_placeList.m_Memory.m_pMemory[v6];
      if ( v8 != nullptr )
      {
        m_count = v3->m_count;
        if ( m_count < 4 )
        {
          v3->m_statement[m_count].isPhrase = true;
          v3->m_statement[v3->m_count++].phrase = v8;
        }
      }
    }
  }
LABEL_13:
  v10 = v3->m_count;
  if ( v10 < 4 )
  {
    v3->m_statement[v10].isPhrase = false;
    v3->m_statement[v3->m_count++].phrase = (const BotPhrase *)4;
  }
  v11 = v3->m_count;
  if ( v11 < 4 )
  {
    v3->m_statement[v11].isPhrase = false;
    v3->m_statement[v3->m_count++].phrase = nullptr;
  }
  m_conditionCount = v3->m_conditionCount;
  if ( m_conditionCount < 4 )
  {
    v3->m_condition[m_conditionCount] = IS_IN_COMBAT;
    ++v3->m_conditionCount;
  }
  BotChatterInterface::AddStatement(this, statement: v3, mustAdd: false);
}

//------------------------------------------------------------------------------
// Address: 0x102AB800
// Name: public: void BotChatterInterface::SpottedSniper(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::SpottedSniper(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  BotStatement *v3; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  BotMeme *v6; // eax

  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_warnSniperTimer) > this->m_warnSniperTimer.m_timestamp.m_Value
    && CBot<CCSPlayer>::GetFriendsRemaining(this: this->m_me) != 0 )
  {
    v2 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v2 != nullptr )
      v3 = BotStatement::BotStatement(this: v2, chatter: this, type: REPORT_INFORMATION, expireDuration: 10.0);
    else
      v3 = nullptr;
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "SniperWarning");
    if ( Phrase != nullptr )
    {
      m_count = v3->m_count;
      if ( m_count < 4 )
      {
        v3->m_statement[m_count].isPhrase = true;
        v3->m_statement[v3->m_count++].phrase = Phrase;
      }
    }
    v6 = (BotMeme *)operator new(nSize: 4u);
    if ( v6 != nullptr )
    {
      v6->__vftable = (BotMeme_vtbl *)&BotWarnSniperMeme::`vftable';
      v3->m_meme = v6;
    }
    else
    {
      v3->m_meme = nullptr;
    }
    BotChatterInterface::AddStatement(this, statement: v3, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB8C0
// Name: public: void BotChatterInterface::ReportIn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::ReportIn(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  double curtime; // st7
  BotStatement *v4; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  int m_conditionCount; // eax
  BotMeme *v8; // eax

  v2 = (BotStatement *)operator new(nSize: 0x70u);
  if ( v2 != nullptr )
  {
    v2->m_chatter = this;
    v2->m_next = nullptr;
    v2->m_prev = nullptr;
    curtime = gpGlobals->curtime;
    v2->m_speakTimestamp = 0.0;
    v2->m_timestamp = curtime;
    v2->m_type = REPORT_REQUEST_INFORMATION;
    v2->m_subject = -1;
    v2->m_place = 0;
    v2->m_meme = nullptr;
    v4 = v2;
    v2->m_startTime = gpGlobals->curtime;
    v2->m_expireTime = gpGlobals->curtime + 10.0;
    v2->m_isSpeaking = false;
    v2->m_nextTime = 0.0;
    v2->m_index = -1;
    v2->m_count = 0;
    v2->m_conditionCount = 0;
  }
  else
  {
    v4 = nullptr;
  }
  Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "RequestReport");
  if ( Phrase != nullptr )
  {
    m_count = v4->m_count;
    if ( m_count < 4 )
    {
      v4->m_statement[m_count].isPhrase = true;
      v4->m_statement[v4->m_count++].phrase = Phrase;
    }
  }
  m_conditionCount = v4->m_conditionCount;
  if ( m_conditionCount < 4 )
  {
    v4->m_condition[m_conditionCount] = RADIO_SILENCE;
    ++v4->m_conditionCount;
  }
  v8 = (BotMeme *)operator new(nSize: 4u);
  if ( v8 != nullptr )
  {
    v8->__vftable = (BotMeme_vtbl *)&BotRequestReportMeme::`vftable';
    v4->m_meme = v8;
  }
  else
  {
    v4->m_meme = nullptr;
  }
  BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
}

//------------------------------------------------------------------------------
// Address: 0x102AB9C0
// Name: public: void BotChatterInterface::PinnedDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::PinnedDown(BotChatterInterface *this)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v3; // st7
  BotStatement *v4; // eax
  double curtime; // st7
  BotStatement *v6; // esi
  unsigned int Place; // edi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  BotMeme *v10; // eax
  int m_conditionCount; // eax
  float v13; // [esp+10h] [ebp-4h]

  p_m_timestamp = &this->m_needBackupInterval.m_timestamp;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_needBackupInterval)
     - this->m_needBackupInterval.m_timestamp.m_Value >= 10.0 )
  {
    v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_needBackupInterval);
    if ( p_m_timestamp->m_Value != v3 )
    {
      this->m_needBackupInterval.NetworkStateChanged(
        this: &this->m_needBackupInterval,
        a2: &this->m_needBackupInterval.m_timestamp);
      v13 = v3;
      p_m_timestamp->m_Value = v13;
    }
    v4 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v4 != nullptr )
    {
      v4->m_chatter = this;
      v4->m_next = nullptr;
      v4->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v4->m_speakTimestamp = 0.0;
      v4->m_timestamp = curtime;
      v4->m_type = REPORT_REQUEST_HELP;
      v4->m_subject = -1;
      v4->m_place = 0;
      v4->m_meme = nullptr;
      v6 = v4;
      v4->m_startTime = gpGlobals->curtime;
      v4->m_expireTime = gpGlobals->curtime + 10.0;
      v4->m_isSpeaking = false;
      v4->m_nextTime = 0.0;
      v4->m_index = -1;
      v4->m_count = 0;
      v4->m_conditionCount = 0;
    }
    else
    {
      v6 = nullptr;
    }
    Place = CCSBot::GetPlace(this: this->m_me);
    SayWhere(say: v6, place: Place);
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "PinnedDown");
    if ( Phrase != nullptr )
    {
      m_count = v6->m_count;
      if ( m_count < 4 )
      {
        v6->m_statement[m_count].isPhrase = true;
        v6->m_statement[v6->m_count++].phrase = Phrase;
      }
    }
    v10 = (BotMeme *)operator new(nSize: 8u);
    if ( v10 != nullptr )
    {
      v10->__vftable = (BotMeme_vtbl *)&BotHelpMeme::`vftable';
      v10[1].__vftable = (BotMeme_vtbl *)Place;
    }
    else
    {
      v10 = nullptr;
    }
    v6->m_meme = v10;
    m_conditionCount = v6->m_conditionCount;
    if ( m_conditionCount < 4 )
    {
      v6->m_condition[m_conditionCount] = IS_IN_COMBAT;
      ++v6->m_conditionCount;
    }
    BotChatterInterface::AddStatement(this, statement: v6, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ABB10
// Name: public: void BotChatterInterface::HeardNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::HeardNoise(BotChatterInterface *this, const Vector *pos)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  IUniformRandomStream *v4; // ecx
  double v5; // st7
  BotStatement *v6; // eax
  BotStatement *v7; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  BotMeme *v10; // eax
  float v11; // [esp+1Ch] [ebp-4h]

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    p_m_timestamp = &this->m_heardNoiseTimer.m_timestamp;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_heardNoiseTimer) > this->m_heardNoiseTimer.m_timestamp.m_Value )
    {
      v5 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_heardNoiseTimer) + 20.0;
      if ( p_m_timestamp->m_Value != v5 )
      {
        this->m_heardNoiseTimer.NetworkStateChanged(
          this: &this->m_heardNoiseTimer,
          a2: &this->m_heardNoiseTimer.m_timestamp);
        v11 = v5;
        p_m_timestamp->m_Value = v11;
      }
      if ( this->m_heardNoiseTimer.m_duration.m_Value != 20.0 )
      {
        this->m_heardNoiseTimer.NetworkStateChanged(
          this: &this->m_heardNoiseTimer,
          a2: &this->m_heardNoiseTimer.m_duration);
        this->m_heardNoiseTimer.m_duration.m_Value = 20.0;
      }
      if ( _RandomFloat(this: v4, a2: 0.0, a3: 100.0) < 33.0 )
      {
        v6 = (BotStatement *)operator new(nSize: 0x70u);
        if ( v6 != nullptr )
          v7 = BotStatement::BotStatement(this: v6, chatter: this, type: REPORT_INFORMATION, expireDuration: 5.0);
        else
          v7 = nullptr;
        Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "HeardNoise");
        if ( Phrase != nullptr )
        {
          m_count = v7->m_count;
          if ( m_count < 4 )
          {
            v7->m_statement[m_count].isPhrase = true;
            v7->m_statement[v7->m_count++].phrase = Phrase;
          }
        }
        v7->m_place = CNavMesh::GetPlace(this: TheNavMesh, pos);
        v10 = (BotMeme *)operator new(nSize: 4u);
        if ( v10 != nullptr )
          v10->__vftable = (BotMeme_vtbl *)&BotHeardNoiseMeme::`vftable';
        else
          v10 = nullptr;
        v7->m_meme = v10;
        BotChatterInterface::AddStatement(this, statement: v7, mustAdd: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ABC70
// Name: public: void BotChatterInterface::KilledMyEnemy(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::KilledMyEnemy(BotChatterInterface *this, int victimID)
{
  CCSBot *m_me; // esi
  int m_nearbyEnemyCount; // ebx
  int EnemiesRemaining; // eax
  BotStatement *v6; // eax
  double curtime; // st7
  BotStatement *v8; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx

  m_me = this->m_me;
  m_nearbyEnemyCount = m_me->m_nearbyEnemyCount;
  if ( CBot<CCSPlayer>::GetEnemiesRemaining(this: m_me) >= m_nearbyEnemyCount )
    EnemiesRemaining = m_nearbyEnemyCount;
  else
    EnemiesRemaining = CBot<CCSPlayer>::GetEnemiesRemaining(this: m_me);
  if ( EnemiesRemaining > 1 )
  {
    v6 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v6 != nullptr )
    {
      v6->m_chatter = this;
      v6->m_next = nullptr;
      v6->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v6->m_speakTimestamp = 0.0;
      v6->m_timestamp = curtime;
      v6->m_type = REPORT_ENEMY_ACTION;
      v6->m_subject = -1;
      v6->m_place = 0;
      v6->m_meme = nullptr;
      v8 = v6;
      v6->m_startTime = gpGlobals->curtime;
      v6->m_expireTime = gpGlobals->curtime + 3.0;
      v6->m_isSpeaking = false;
      v6->m_nextTime = 0.0;
      v6->m_index = -1;
      v6->m_count = 0;
      v6->m_conditionCount = 0;
    }
    else
    {
      v8 = nullptr;
    }
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "KilledMyEnemy");
    if ( Phrase != nullptr )
    {
      m_count = v8->m_count;
      if ( m_count < 4 )
      {
        v8->m_statement[m_count].isPhrase = true;
        v8->m_statement[v8->m_count++].phrase = Phrase;
      }
    }
    v8->m_subject = victimID;
    BotChatterInterface::AddStatement(this, statement: v8, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ABD60
// Name: public: void BotChatterInterface::EnemiesRemaining(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall BotChatterInterface::EnemiesRemaining(BotChatterInterface *this)
{
  CCSBot *m_me; // esi
  int m_nearbyEnemyCount; // ebx
  int EnemiesRemaining; // eax
  BotStatement *v5; // eax
  int v6; // ecx
  double curtime; // st7
  BotStatement *v8; // esi
  int m_count; // eax

  m_me = this->m_me;
  m_nearbyEnemyCount = m_me->m_nearbyEnemyCount;
  if ( CBot<CCSPlayer>::GetEnemiesRemaining(this: m_me) >= m_nearbyEnemyCount )
    EnemiesRemaining = m_nearbyEnemyCount;
  else
    EnemiesRemaining = CBot<CCSPlayer>::GetEnemiesRemaining(this: m_me);
  if ( EnemiesRemaining <= 1 )
  {
    v5 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v5 != nullptr )
    {
      v5->m_chatter = this;
      v5->m_next = nullptr;
      v5->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v5->m_speakTimestamp = 0.0;
      v5->m_timestamp = curtime;
      v5->m_type = REPORT_ENEMIES_REMAINING;
      v6 = -1;
      v5->m_subject = -1;
      v5->m_place = 0;
      v5->m_meme = nullptr;
      v8 = v5;
      v5->m_startTime = gpGlobals->curtime;
      v5->m_expireTime = gpGlobals->curtime + 5.0;
      v5->m_isSpeaking = false;
      v5->m_nextTime = 0.0;
      v5->m_index = -1;
      v5->m_count = 0;
      v5->m_conditionCount = 0;
    }
    else
    {
      v8 = nullptr;
    }
    m_count = v8->m_count;
    if ( m_count < 4 )
    {
      v8->m_statement[m_count].isPhrase = false;
      v6 = v8->m_count;
      v8->m_statement[v6].phrase = (const BotPhrase *)1;
      ++v8->m_count;
    }
    v8->m_startTime = _RandomFloat(this: (IUniformRandomStream *)v6, a2: 2.0, a3: 4.0) + gpGlobals->curtime;
    BotChatterInterface::AddStatement(this, statement: v8, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ABE70
// Name: public: void BotChatterInterface::Affirmative(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::Affirmative(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  double curtime; // st7
  BotStatement *v4; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx

  v2 = (BotStatement *)operator new(nSize: 0x70u);
  if ( v2 != nullptr )
  {
    v2->m_chatter = this;
    v2->m_next = nullptr;
    v2->m_prev = nullptr;
    curtime = gpGlobals->curtime;
    v2->m_speakTimestamp = 0.0;
    v2->m_timestamp = curtime;
    v2->m_type = REPORT_ACKNOWLEDGE;
    v2->m_subject = -1;
    v2->m_place = 0;
    v2->m_meme = nullptr;
    v4 = v2;
    v2->m_startTime = gpGlobals->curtime;
    v2->m_expireTime = gpGlobals->curtime + 3.0;
    v2->m_isSpeaking = false;
    v2->m_nextTime = 0.0;
    v2->m_index = -1;
    v2->m_count = 0;
    v2->m_conditionCount = 0;
  }
  else
  {
    v4 = nullptr;
  }
  Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "Affirmative");
  if ( Phrase != nullptr )
  {
    m_count = v4->m_count;
    if ( m_count < 4 )
    {
      v4->m_statement[m_count].isPhrase = true;
      v4->m_statement[v4->m_count++].phrase = Phrase;
    }
  }
  BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
}

//------------------------------------------------------------------------------
// Address: 0x102ABF30
// Name: public: void BotChatterInterface::Negative(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::Negative(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  double curtime; // st7
  BotStatement *v4; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx

  v2 = (BotStatement *)operator new(nSize: 0x70u);
  if ( v2 != nullptr )
  {
    v2->m_chatter = this;
    v2->m_next = nullptr;
    v2->m_prev = nullptr;
    curtime = gpGlobals->curtime;
    v2->m_speakTimestamp = 0.0;
    v2->m_timestamp = curtime;
    v2->m_type = REPORT_ACKNOWLEDGE;
    v2->m_subject = -1;
    v2->m_place = 0;
    v2->m_meme = nullptr;
    v4 = v2;
    v2->m_startTime = gpGlobals->curtime;
    v2->m_expireTime = gpGlobals->curtime + 3.0;
    v2->m_isSpeaking = false;
    v2->m_nextTime = 0.0;
    v2->m_index = -1;
    v2->m_count = 0;
    v2->m_conditionCount = 0;
  }
  else
  {
    v4 = nullptr;
  }
  Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "Negative");
  if ( Phrase != nullptr )
  {
    m_count = v4->m_count;
    if ( m_count < 4 )
    {
      v4->m_statement[m_count].isPhrase = true;
      v4->m_statement[v4->m_count++].phrase = Phrase;
    }
  }
  BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
}

//------------------------------------------------------------------------------
// Address: 0x102ABFF0
// Name: public: void BotChatterInterface::GoingToPlantTheBomb(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::GoingToPlantTheBomb(BotChatterInterface *this, unsigned int place)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v4; // st7
  BotStatement *v5; // eax
  BotStatement *v6; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  BotMeme *v9; // eax
  float v10; // [esp+14h] [ebp-4h]

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    p_m_timestamp = &this->m_planInterval.m_timestamp;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_planInterval) - this->m_planInterval.m_timestamp.m_Value >= 20.0 )
    {
      v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_planInterval);
      if ( p_m_timestamp->m_Value != v4 )
      {
        this->m_planInterval.NetworkStateChanged(this: &this->m_planInterval, a2: &this->m_planInterval.m_timestamp);
        v10 = v4;
        p_m_timestamp->m_Value = v10;
      }
      v5 = (BotStatement *)operator new(nSize: 0x70u);
      if ( v5 != nullptr )
        v6 = BotStatement::BotStatement(this: v5, chatter: this, type: REPORT_CRITICAL_EVENT, expireDuration: 10.0);
      else
        v6 = nullptr;
      Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "GoingToPlantBomb");
      if ( Phrase != nullptr )
      {
        m_count = v6->m_count;
        if ( m_count < 4 )
        {
          v6->m_statement[m_count].isPhrase = true;
          v6->m_statement[v6->m_count++].phrase = Phrase;
        }
      }
      v6->m_place = place;
      v9 = (BotMeme *)operator new(nSize: 4u);
      if ( v9 != nullptr )
        v9->__vftable = (BotMeme_vtbl *)&BotFollowMeme::`vftable';
      else
        v9 = nullptr;
      v6->m_meme = v9;
      BotChatterInterface::AddStatement(this, statement: v6, mustAdd: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AC0F0
// Name: public: void BotChatterInterface::PlantingTheBomb(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::PlantingTheBomb(BotChatterInterface *this, unsigned int place)
{
  BotStatement *v3; // eax
  double curtime; // st7
  BotStatement *v5; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  BotMeme *v8; // eax
  float z; // xmm0_4
  Vector myOrigin; // [esp+8h] [ebp-Ch] BYREF

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    v3 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v3 != nullptr )
    {
      v3->m_chatter = this;
      v3->m_next = nullptr;
      v3->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v3->m_speakTimestamp = 0.0;
      v3->m_timestamp = curtime;
      v3->m_type = REPORT_CRITICAL_EVENT;
      v3->m_subject = -1;
      v3->m_place = 0;
      v3->m_meme = nullptr;
      v5 = v3;
      v3->m_startTime = gpGlobals->curtime;
      v3->m_expireTime = gpGlobals->curtime + 10.0;
      v3->m_isSpeaking = false;
      v3->m_nextTime = 0.0;
      v3->m_index = -1;
      v3->m_count = 0;
      v3->m_conditionCount = 0;
    }
    else
    {
      v5 = nullptr;
    }
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "PlantingBomb");
    if ( Phrase != nullptr )
    {
      m_count = v5->m_count;
      if ( m_count < 4 )
      {
        v5->m_statement[m_count].isPhrase = true;
        v5->m_statement[v5->m_count++].phrase = Phrase;
      }
    }
    v5->m_place = place;
    GetCentroid(result: &myOrigin, player: this->m_me);
    v8 = (BotMeme *)operator new(nSize: 0x10u);
    if ( v8 != nullptr )
    {
      v8[1].__vftable = (BotMeme_vtbl *)LODWORD(myOrigin.x);
      v8[2].__vftable = (BotMeme_vtbl *)LODWORD(myOrigin.y);
      z = myOrigin.z;
      v8->__vftable = (BotMeme_vtbl *)&BotDefendHereMeme::`vftable';
      *(float *)&v8[3].__vftable = z;
    }
    else
    {
      v8 = nullptr;
    }
    v5->m_meme = v8;
    BotChatterInterface::AddStatement(this, statement: v5, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AC220
// Name: public: void BotChatterInterface::TheyPickedUpTheBomb(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::TheyPickedUpTheBomb(BotChatterInterface *this)
{
  CCSBot *m_me; // eax
  BotStatement *v3; // eax
  BotStatement *v4; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  char *v7; // eax
  Vector result; // [esp+Ch] [ebp-Ch] BYREF

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    m_me = this->m_me;
    if ( m_me->m_gameState.m_bombState == LOOSE )
    {
      GetCentroid(&result, player: m_me);
      CSGameState::UpdateBomber(this: &this->m_me->m_gameState, pos: &result);
      v3 = (BotStatement *)operator new(nSize: 0x70u);
      if ( v3 != nullptr )
        v4 = BotStatement::BotStatement(this: v3, chatter: this, type: REPORT_INFORMATION, expireDuration: 10.0);
      else
        v4 = nullptr;
      Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "TheyPickedUpTheBomb");
      if ( Phrase != nullptr )
      {
        m_count = v4->m_count;
        if ( m_count < 4 )
        {
          v4->m_statement[m_count].isPhrase = true;
          v4->m_statement[v4->m_count++].phrase = Phrase;
        }
      }
      v7 = (char *)operator new(nSize: 0x14u);
      if ( v7 != nullptr )
      {
        *(_DWORD *)v7 = &BotBombStatusMeme::`vftable';
        *((_DWORD *)v7 + 1) = 0;
        *(Vector *)(v7 + 8) = result;
        v4->m_meme = (BotMeme *)v7;
      }
      else
      {
        v4->m_meme = nullptr;
      }
      BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AC330
// Name: public: void BotChatterInterface::SpottedBomber(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::SpottedBomber(BotChatterInterface *this, CBasePlayer *bomber)
{
  CCSBot *m_me; // eax
  const Vector *BombPosition; // eax
  BotStatement *v5; // eax
  double curtime; // st7
  BotStatement *v7; // esi
  unsigned int Place; // eax
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  edict_t *m_pPev; // eax
  signed int v12; // eax
  char *v13; // eax
  Vector result; // [esp+8h] [ebp-Ch] BYREF

  GetCentroid(&result, player: bomber);
  m_me = this->m_me;
  if ( m_me->m_gameState.m_bombState != MOVING
    || (BombPosition = CSGameState::GetBombPosition(this: &m_me->m_gameState)) == nullptr
    || (float)((float)((float)((float)(result.y - BombPosition->y) * (float)(result.y - BombPosition->y))
                     + (float)((float)(result.x - BombPosition->x) * (float)(result.x - BombPosition->x)))
             + (float)((float)(result.z - BombPosition->z) * (float)(result.z - BombPosition->z))) >= 1000000.0 )
  {
    CSGameState::UpdateBomber(this: &this->m_me->m_gameState, pos: &result);
    v5 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v5 != nullptr )
    {
      v5->m_chatter = this;
      v5->m_next = nullptr;
      v5->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v5->m_speakTimestamp = 0.0;
      v5->m_timestamp = curtime;
      v5->m_type = REPORT_INFORMATION;
      v5->m_subject = -1;
      v5->m_place = 0;
      v5->m_meme = nullptr;
      v7 = v5;
      v5->m_startTime = gpGlobals->curtime;
      v5->m_expireTime = gpGlobals->curtime + 10.0;
      v5->m_isSpeaking = false;
      v5->m_nextTime = 0.0;
      v5->m_index = -1;
      v5->m_count = 0;
      v5->m_conditionCount = 0;
    }
    else
    {
      v7 = nullptr;
    }
    Place = CNavMesh::GetPlace(this: TheNavMesh, pos: &result);
    SayWhere(say: v7, place: Place);
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "SpottedBomber");
    if ( Phrase != nullptr )
    {
      m_count = v7->m_count;
      if ( m_count < 4 )
      {
        v7->m_statement[m_count].isPhrase = true;
        v7->m_statement[v7->m_count++].phrase = Phrase;
      }
    }
    m_pPev = bomber->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v12 = m_pPev - gpGlobals->pEdicts;
    else
      v12 = 0;
    v7->m_subject = v12;
    v13 = (char *)operator new(nSize: 0x14u);
    if ( v13 != nullptr )
    {
      *(_DWORD *)v13 = &BotBombStatusMeme::`vftable';
      *((_DWORD *)v13 + 1) = 0;
      *(Vector *)(v13 + 8) = result;
    }
    else
    {
      v13 = nullptr;
    }
    v7->m_meme = (BotMeme *)v13;
    BotChatterInterface::AddStatement(this, statement: v7, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AC4F0
// Name: public: void BotChatterInterface::SpottedLooseBomb(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::SpottedLooseBomb(BotChatterInterface *this, CBaseEntity *bomb)
{
  BotStatement *v3; // eax
  BotStatement *v4; // edi
  unsigned int Place; // eax
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  char *v8; // esi
  Vector *AbsOrigin; // eax
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 && this->m_me->m_gameState.m_bombState != LOOSE )
  {
    if ( (bomb->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: bomb, a2: (int)&savedregs);
    CSGameState::UpdateLooseBomb(this: &this->m_me->m_gameState, pos: &bomb->m_vecAbsOrigin);
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_spottedLooseBombTimer) > this->m_spottedLooseBombTimer.m_timestamp.m_Value )
    {
      CountdownTimer::Start(this: &this->m_spottedLooseBombTimer, duration: 10.0);
      v3 = (BotStatement *)operator new(nSize: 0x70u);
      if ( v3 != nullptr )
        v4 = BotStatement::BotStatement(this: v3, chatter: this, type: REPORT_INFORMATION, expireDuration: 10.0);
      else
        v4 = nullptr;
      if ( (bomb->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: bomb, a2: (int)&savedregs);
      Place = CNavMesh::GetPlace(this: TheNavMesh, pos: &bomb->m_vecAbsOrigin);
      SayWhere(say: v4, place: Place);
      Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "SpottedLooseBomb");
      if ( Phrase != nullptr )
      {
        m_count = v4->m_count;
        if ( m_count < 4 )
        {
          v4->m_statement[m_count].isPhrase = true;
          v4->m_statement[v4->m_count++].phrase = Phrase;
        }
      }
      if ( CCSBotManager::GetLooseBomb(this: (CCSBotManager *)TheBots) != nullptr )
      {
        v8 = (char *)operator new(nSize: 0x14u);
        if ( v8 != nullptr )
        {
          AbsOrigin = CBaseEntity::GetAbsOrigin(this: bomb);
          *(_DWORD *)v8 = &BotBombStatusMeme::`vftable';
          *((_DWORD *)v8 + 1) = 1;
          *(Vector *)(v8 + 8) = *AbsOrigin;
        }
        else
        {
          v8 = nullptr;
        }
        v4->m_meme = (BotMeme *)v8;
      }
      BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AC660
// Name: public: void BotChatterInterface::GuardingLooseBomb(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::GuardingLooseBomb(BotChatterInterface *this, CBaseEntity *bomb)
{
  IntervalTimer *p_m_planInterval; // edi
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v5; // st7
  BotStatement *v6; // eax
  BotStatement *v7; // edi
  unsigned int Place; // eax
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  char *v11; // esi
  Vector *AbsOrigin; // eax
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  float bomba; // [esp+20h] [ebp+8h]

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 && bomb != nullptr )
  {
    p_m_planInterval = &this->m_planInterval;
    p_m_timestamp = &this->m_planInterval.m_timestamp;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_planInterval) - this->m_planInterval.m_timestamp.m_Value >= 20.0 )
    {
      v5 = IntervalTimer::Now(this: (CEffectsServer *)p_m_planInterval);
      if ( p_m_timestamp->m_Value != v5 )
      {
        p_m_planInterval->NetworkStateChanged(this: p_m_planInterval, a2: &p_m_planInterval->m_timestamp);
        bomba = v5;
        p_m_timestamp->m_Value = bomba;
      }
      if ( (bomb->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: bomb, a2: (int)&savedregs);
      CSGameState::UpdateLooseBomb(this: &this->m_me->m_gameState, pos: &bomb->m_vecAbsOrigin);
      v6 = (BotStatement *)operator new(nSize: 0x70u);
      if ( v6 != nullptr )
        v7 = BotStatement::BotStatement(this: v6, chatter: this, type: REPORT_INFORMATION, expireDuration: 10.0);
      else
        v7 = nullptr;
      if ( (bomb->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: bomb, a2: (int)&savedregs);
      Place = CNavMesh::GetPlace(this: TheNavMesh, pos: &bomb->m_vecAbsOrigin);
      SayWhere(say: v7, place: Place);
      Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "GuardingLooseBomb");
      if ( Phrase != nullptr )
      {
        m_count = v7->m_count;
        if ( m_count < 4 )
        {
          v7->m_statement[m_count].isPhrase = true;
          v7->m_statement[v7->m_count++].phrase = Phrase;
        }
      }
      if ( CCSBotManager::GetLooseBomb(this: (CCSBotManager *)TheBots) != nullptr )
      {
        v11 = (char *)operator new(nSize: 0x14u);
        if ( v11 != nullptr )
        {
          AbsOrigin = CBaseEntity::GetAbsOrigin(this: bomb);
          *(_DWORD *)v11 = &BotBombStatusMeme::`vftable';
          *((_DWORD *)v11 + 1) = 1;
          *(Vector *)(v11 + 8) = *AbsOrigin;
        }
        else
        {
          v11 = nullptr;
        }
        v7->m_meme = (BotMeme *)v11;
      }
      BotChatterInterface::AddStatement(this, statement: v7, mustAdd: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AC7E0
// Name: public: void BotChatterInterface::RequestBombLocation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::RequestBombLocation(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  double curtime; // st7
  BotStatement *v4; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  BotMeme *v7; // eax

  if ( !this->m_requestedBombLocation )
  {
    this->m_requestedBombLocation = true;
    v2 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v2 != nullptr )
    {
      v2->m_chatter = this;
      v2->m_next = nullptr;
      v2->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v2->m_speakTimestamp = 0.0;
      v2->m_timestamp = curtime;
      v2->m_type = REPORT_REQUEST_INFORMATION;
      v2->m_subject = -1;
      v2->m_place = 0;
      v2->m_meme = nullptr;
      v4 = v2;
      v2->m_startTime = gpGlobals->curtime;
      v2->m_expireTime = gpGlobals->curtime + 10.0;
      v2->m_isSpeaking = false;
      v2->m_nextTime = 0.0;
      v2->m_index = -1;
      v2->m_count = 0;
      v2->m_conditionCount = 0;
    }
    else
    {
      v4 = nullptr;
    }
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "WhereIsTheBomb");
    if ( Phrase != nullptr )
    {
      m_count = v4->m_count;
      if ( m_count < 4 )
      {
        v4->m_statement[m_count].isPhrase = true;
        v4->m_statement[v4->m_count++].phrase = Phrase;
      }
    }
    v7 = (BotMeme *)operator new(nSize: 4u);
    if ( v7 != nullptr )
    {
      v7->__vftable = (BotMeme_vtbl *)&BotWhereBombMeme::`vftable';
      v4->m_meme = v7;
    }
    else
    {
      v4->m_meme = nullptr;
    }
    BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AC8D0
// Name: public: void BotChatterInterface::BombsiteClear(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::BombsiteClear(BotChatterInterface *this, int zoneIndex)
{
  const Vector *v3; // edi
  BotStatement *v4; // eax
  double curtime; // st7
  BotStatement *v6; // esi
  unsigned int Place; // eax
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  BotMeme *v10; // eax

  v3 = (const Vector *)(&TheBots[1].m_activeGrenadeList.m_Memory.m_nAllocationCount + 30 * zoneIndex);
  if ( (CBotManager *)((char *)TheBots + 120 * zoneIndex) != (CBotManager *)-6248 )
  {
    v4 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v4 != nullptr )
    {
      v4->m_chatter = this;
      v4->m_next = nullptr;
      v4->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v4->m_speakTimestamp = 0.0;
      v4->m_timestamp = curtime;
      v4->m_type = REPORT_INFORMATION;
      v4->m_subject = -1;
      v4->m_place = 0;
      v4->m_meme = nullptr;
      v6 = v4;
      v4->m_startTime = gpGlobals->curtime;
      v4->m_expireTime = gpGlobals->curtime + 10.0;
      v4->m_isSpeaking = false;
      v4->m_nextTime = 0.0;
      v4->m_index = -1;
      v4->m_count = 0;
      v4->m_conditionCount = 0;
    }
    else
    {
      v6 = nullptr;
    }
    Place = CNavMesh::GetPlace(this: TheNavMesh, pos: v3 + 6);
    SayWhere(say: v6, place: Place);
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "BombsiteClear");
    if ( Phrase != nullptr )
    {
      m_count = v6->m_count;
      if ( m_count < 4 )
      {
        v6->m_statement[m_count].isPhrase = true;
        v6->m_statement[v6->m_count++].phrase = Phrase;
      }
    }
    v10 = (BotMeme *)operator new(nSize: 0xCu);
    if ( v10 != nullptr )
    {
      v10->__vftable = (BotMeme_vtbl *)&BotBombsiteStatusMeme::`vftable';
      v10[1].__vftable = (BotMeme_vtbl *)zoneIndex;
      v10[2].__vftable = nullptr;
    }
    else
    {
      v10 = nullptr;
    }
    v6->m_meme = v10;
    BotChatterInterface::AddStatement(this, statement: v6, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ACA00
// Name: public: void BotChatterInterface::FoundPlantedBomb(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::FoundPlantedBomb(BotChatterInterface *this, int zoneIndex)
{
  const Vector *v3; // edi
  BotStatement *v4; // eax
  double curtime; // st7
  BotStatement *v6; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  BotMeme *v9; // eax

  v3 = (const Vector *)(&TheBots[1].m_activeGrenadeList.m_Memory.m_nAllocationCount + 30 * zoneIndex);
  if ( (CBotManager *)((char *)TheBots + 120 * zoneIndex) != (CBotManager *)-6248 )
  {
    v4 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v4 != nullptr )
    {
      v4->m_chatter = this;
      v4->m_next = nullptr;
      v4->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v4->m_speakTimestamp = 0.0;
      v4->m_timestamp = curtime;
      v4->m_type = REPORT_INFORMATION;
      v4->m_subject = -1;
      v4->m_place = 0;
      v4->m_meme = nullptr;
      v6 = v4;
      v4->m_startTime = gpGlobals->curtime;
      v4->m_expireTime = gpGlobals->curtime + 3.0;
      v4->m_isSpeaking = false;
      v4->m_nextTime = 0.0;
      v4->m_index = -1;
      v4->m_count = 0;
      v4->m_conditionCount = 0;
    }
    else
    {
      v6 = nullptr;
    }
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "PlantedBombPlace");
    if ( Phrase != nullptr )
    {
      m_count = v6->m_count;
      if ( m_count < 4 )
      {
        v6->m_statement[m_count].isPhrase = true;
        v6->m_statement[v6->m_count++].phrase = Phrase;
      }
    }
    v6->m_place = CNavMesh::GetPlace(this: TheNavMesh, pos: v3 + 6);
    v9 = (BotMeme *)operator new(nSize: 0xCu);
    if ( v9 != nullptr )
    {
      v9->__vftable = (BotMeme_vtbl *)&BotBombsiteStatusMeme::`vftable';
      v9[1].__vftable = (BotMeme_vtbl *)zoneIndex;
      v9[2].__vftable = (BotMeme_vtbl *)1;
    }
    else
    {
      v9 = nullptr;
    }
    v6->m_meme = v9;
    BotChatterInterface::AddStatement(this, statement: v6, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ACB20
// Name: public: void BotChatterInterface::Scared(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::Scared(BotChatterInterface *this)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v3; // st7
  BotStatement *v4; // eax
  double curtime; // st7
  BotStatement *v6; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  int m_conditionCount; // eax
  float v10; // [esp+Ch] [ebp-4h]

  p_m_timestamp = &this->m_scaredInterval.m_timestamp;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_scaredInterval) - this->m_scaredInterval.m_timestamp.m_Value >= 10.0 )
  {
    v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_scaredInterval);
    if ( p_m_timestamp->m_Value != v3 )
    {
      this->m_scaredInterval.NetworkStateChanged(this: &this->m_scaredInterval, a2: &this->m_scaredInterval.m_timestamp);
      v10 = v3;
      p_m_timestamp->m_Value = v10;
    }
    v4 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v4 != nullptr )
    {
      v4->m_chatter = this;
      v4->m_next = nullptr;
      v4->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v4->m_speakTimestamp = 0.0;
      v4->m_timestamp = curtime;
      v4->m_type = REPORT_EMOTE;
      v4->m_subject = -1;
      v4->m_place = 0;
      v4->m_meme = nullptr;
      v6 = v4;
      v4->m_startTime = gpGlobals->curtime;
      v4->m_expireTime = gpGlobals->curtime + 1.0;
      v4->m_isSpeaking = false;
      v4->m_nextTime = 0.0;
      v4->m_index = -1;
      v4->m_count = 0;
      v4->m_conditionCount = 0;
    }
    else
    {
      v6 = nullptr;
    }
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "ScaredEmote");
    if ( Phrase != nullptr )
    {
      m_count = v6->m_count;
      if ( m_count < 4 )
      {
        v6->m_statement[m_count].isPhrase = true;
        v6->m_statement[v6->m_count++].phrase = Phrase;
      }
    }
    m_conditionCount = v6->m_conditionCount;
    if ( m_conditionCount < 4 )
    {
      v6->m_condition[m_conditionCount] = IS_IN_COMBAT;
      ++v6->m_conditionCount;
    }
    BotChatterInterface::AddStatement(this, statement: v6, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ACC40
// Name: public: void BotChatterInterface::CelebrateWin(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall BotChatterInterface::CelebrateWin(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  int v3; // ecx
  double curtime; // st7
  BotStatement *v5; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // edx
  const char *v8; // [esp+4h] [ebp-10h]

  v2 = (BotStatement *)operator new(nSize: 0x70u);
  if ( v2 != nullptr )
  {
    v2->m_chatter = this;
    v2->m_next = nullptr;
    v2->m_prev = nullptr;
    curtime = gpGlobals->curtime;
    v2->m_speakTimestamp = 0.0;
    v2->m_timestamp = curtime;
    v2->m_type = REPORT_EMOTE;
    v3 = -1;
    v2->m_subject = -1;
    v2->m_place = 0;
    v2->m_meme = nullptr;
    v5 = v2;
    v2->m_startTime = gpGlobals->curtime;
    v2->m_expireTime = gpGlobals->curtime + 15.0;
    v2->m_isSpeaking = false;
    v2->m_nextTime = 0.0;
    v2->m_index = -1;
    v2->m_count = 0;
    v2->m_conditionCount = 0;
  }
  else
  {
    v5 = nullptr;
  }
  v5->m_startTime = _RandomFloat(this: (IUniformRandomStream *)v3, a2: 2.0, a3: 5.0) + gpGlobals->curtime;
  if ( CBot<CCSPlayer>::GetFriendsRemaining(this: this->m_me) != 0 )
  {
    if ( (float)(gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696]) >= 45.0 )
    {
      if ( _RandomFloat(this: (IUniformRandomStream *)TheBots, a2: 0.0, a3: 100.0) >= 10.0 )
        goto LABEL_17;
    }
    else if ( _RandomFloat(this: (IUniformRandomStream *)TheBots, a2: 0.0, a3: 100.0) >= 33.299999 )
    {
      goto LABEL_17;
    }
LABEL_13:
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: v8);
    goto LABEL_14;
  }
  if ( (float)(gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696]) >= 45.0 )
  {
    if ( _RandomFloat(this: (IUniformRandomStream *)gpGlobals, a2: 0.0, a3: 100.0) >= 33.299999 )
      goto LABEL_17;
    goto LABEL_13;
  }
  Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "WonRoundQuickly");
LABEL_14:
  if ( Phrase != nullptr )
  {
    m_count = v5->m_count;
    if ( m_count < 4 )
    {
      v5->m_statement[m_count].isPhrase = true;
      v5->m_statement[v5->m_count++].phrase = Phrase;
    }
  }
LABEL_17:
  BotChatterInterface::AddStatement(this, statement: v5, mustAdd: false);
}

//------------------------------------------------------------------------------
// Address: 0x102ACE10
// Name: public: void BotChatterInterface::AnnouncePlan(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall BotChatterInterface::AnnouncePlan(
        BotChatterInterface *this,
        const char *phraseName,
        unsigned int place)
{
  BotStatement *v4; // eax
  double curtime; // st7
  BotStatement *v6; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  float phraseNamea; // [esp+1Ch] [ebp+8h]

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    v4 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v4 != nullptr )
    {
      v4->m_chatter = this;
      v4->m_next = nullptr;
      v4->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v4->m_speakTimestamp = 0.0;
      v4->m_timestamp = curtime;
      v4->m_type = REPORT_MY_PLAN;
      v4->m_subject = -1;
      v4->m_place = 0;
      v4->m_meme = nullptr;
      v6 = v4;
      v4->m_startTime = gpGlobals->curtime;
      v4->m_expireTime = gpGlobals->curtime + 10.0;
      v4->m_isSpeaking = false;
      v4->m_nextTime = 0.0;
      v4->m_index = -1;
      v4->m_count = 0;
      v4->m_conditionCount = 0;
    }
    else
    {
      v6 = nullptr;
    }
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: phraseName);
    if ( Phrase != nullptr )
    {
      m_count = v6->m_count;
      if ( m_count < 4 )
      {
        v6->m_statement[m_count].isPhrase = true;
        m_count = v6->m_count;
        v6->m_statement[m_count].phrase = Phrase;
        ++v6->m_count;
      }
    }
    v6->m_place = place;
    phraseNamea = *(float *)&TheBots[1].m_debugMessage[0].m_string[696];
    v6->m_startTime = _RandomFloat(this: (IUniformRandomStream *)m_count, a2: 2.0, a3: 3.0) + phraseNamea;
    BotChatterInterface::AddStatement(this, statement: v6, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ACF30
// Name: public: void BotChatterInterface::GuardingBombsite(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::GuardingBombsite(BotChatterInterface *this, unsigned int place)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v4; // st7
  float v5; // [esp+4h] [ebp-4h]

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    p_m_timestamp = &this->m_planInterval.m_timestamp;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_planInterval) - this->m_planInterval.m_timestamp.m_Value >= 20.0 )
    {
      v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_planInterval);
      if ( p_m_timestamp->m_Value != v4 )
      {
        this->m_planInterval.NetworkStateChanged(this: &this->m_planInterval, a2: &this->m_planInterval.m_timestamp);
        v5 = v4;
        p_m_timestamp->m_Value = v5;
      }
      BotChatterInterface::AnnouncePlan(this, phraseName: "GoingToDefendBombsite", place);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ACFB0
// Name: public: void BotChatterInterface::HostagesBeingTaken(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::HostagesBeingTaken(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  double curtime; // st7
  BotStatement *v4; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  BotMeme *v7; // eax

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    v2 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v2 != nullptr )
    {
      v2->m_chatter = this;
      v2->m_next = nullptr;
      v2->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v2->m_speakTimestamp = 0.0;
      v2->m_timestamp = curtime;
      v2->m_type = REPORT_INFORMATION;
      v2->m_subject = -1;
      v2->m_place = 0;
      v2->m_meme = nullptr;
      v4 = v2;
      v2->m_startTime = gpGlobals->curtime;
      v2->m_expireTime = gpGlobals->curtime + 3.0;
      v2->m_isSpeaking = false;
      v2->m_nextTime = 0.0;
      v2->m_index = -1;
      v2->m_count = 0;
      v2->m_conditionCount = 0;
    }
    else
    {
      v4 = nullptr;
    }
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "HostagesBeingTaken");
    if ( Phrase != nullptr )
    {
      m_count = v4->m_count;
      if ( m_count < 4 )
      {
        v4->m_statement[m_count].isPhrase = true;
        v4->m_statement[v4->m_count++].phrase = Phrase;
      }
    }
    v7 = (BotMeme *)operator new(nSize: 4u);
    if ( v7 != nullptr )
    {
      v7->__vftable = (BotMeme_vtbl *)&BotHostageBeingTakenMeme::`vftable';
      v4->m_meme = v7;
    }
    else
    {
      v4->m_meme = nullptr;
    }
    BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AD0B0
// Name: public: void BotChatterInterface::HostagesTaken(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::HostagesTaken(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  double curtime; // st7
  BotStatement *v4; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    v2 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v2 != nullptr )
    {
      v2->m_chatter = this;
      v2->m_next = nullptr;
      v2->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v2->m_speakTimestamp = 0.0;
      v2->m_timestamp = curtime;
      v2->m_type = REPORT_INFORMATION;
      v2->m_subject = -1;
      v2->m_place = 0;
      v2->m_meme = nullptr;
      v4 = v2;
      v2->m_startTime = gpGlobals->curtime;
      v2->m_expireTime = gpGlobals->curtime + 3.0;
      v2->m_isSpeaking = false;
      v2->m_nextTime = 0.0;
      v2->m_index = -1;
      v2->m_count = 0;
      v2->m_conditionCount = 0;
    }
    else
    {
      v4 = nullptr;
    }
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "HostagesTaken");
    if ( Phrase != nullptr )
    {
      m_count = v4->m_count;
      if ( m_count < 4 )
      {
        v4->m_statement[m_count].isPhrase = true;
        v4->m_statement[v4->m_count++].phrase = Phrase;
      }
    }
    BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AD180
// Name: public: void BotChatterInterface::EscortingHostages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::EscortingHostages(BotChatterInterface *this)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v3; // st7
  BotStatement *v4; // eax
  BotStatement *v5; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  float v8; // [esp+18h] [ebp-4h]

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    p_m_timestamp = &this->m_escortingHostageTimer.m_timestamp;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_escortingHostageTimer) > this->m_escortingHostageTimer.m_timestamp.m_Value )
    {
      v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_escortingHostageTimer) + 10.0;
      if ( p_m_timestamp->m_Value != v3 )
      {
        this->m_escortingHostageTimer.NetworkStateChanged(
          this: &this->m_escortingHostageTimer,
          a2: &this->m_escortingHostageTimer.m_timestamp);
        v8 = v3;
        p_m_timestamp->m_Value = v8;
      }
      if ( this->m_escortingHostageTimer.m_duration.m_Value != 10.0 )
      {
        this->m_escortingHostageTimer.NetworkStateChanged(
          this: &this->m_escortingHostageTimer,
          a2: &this->m_escortingHostageTimer.m_duration);
        this->m_escortingHostageTimer.m_duration.m_Value = 10.0;
      }
      v4 = (BotStatement *)operator new(nSize: 0x70u);
      if ( v4 != nullptr )
        v5 = BotStatement::BotStatement(this: v4, chatter: this, type: REPORT_MY_PLAN, expireDuration: 5.0);
      else
        v5 = nullptr;
      Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "EscortingHostages");
      if ( Phrase != nullptr )
      {
        m_count = v5->m_count;
        if ( m_count < 4 )
        {
          v5->m_statement[m_count].isPhrase = true;
          v5->m_statement[v5->m_count++].phrase = Phrase;
        }
      }
      BotChatterInterface::AddStatement(this, statement: v5, mustAdd: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AD280
// Name: public: void BotChatterInterface::KilledFriend(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall BotChatterInterface::KilledFriend(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  double curtime; // st7
  BotStatement *v4; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx

  v2 = (BotStatement *)operator new(nSize: 0x70u);
  if ( v2 != nullptr )
  {
    v2->m_chatter = this;
    v2->m_next = nullptr;
    v2->m_prev = nullptr;
    curtime = gpGlobals->curtime;
    v2->m_speakTimestamp = 0.0;
    v2->m_timestamp = curtime;
    v2->m_type = REPORT_KILLED_FRIEND;
    v2->m_subject = -1;
    v2->m_place = 0;
    v2->m_meme = nullptr;
    v4 = v2;
    v2->m_startTime = gpGlobals->curtime;
    v2->m_expireTime = gpGlobals->curtime + 2.0;
    v2->m_isSpeaking = false;
    v2->m_nextTime = 0.0;
    v2->m_index = -1;
    v2->m_count = 0;
    v2->m_conditionCount = 0;
  }
  else
  {
    v4 = nullptr;
  }
  Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "KilledFriend");
  if ( Phrase != nullptr )
  {
    m_count = v4->m_count;
    if ( m_count < 4 )
    {
      v4->m_statement[m_count].isPhrase = true;
      m_count = v4->m_count;
      v4->m_statement[m_count].phrase = Phrase;
      ++v4->m_count;
    }
  }
  v4->m_startTime = _RandomFloat(this: (IUniformRandomStream *)m_count, a2: 0.5, a3: 1.0) + gpGlobals->curtime;
  BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
}

//------------------------------------------------------------------------------
// Address: 0x102AD370
// Name: public: void BotChatterInterface::FriendlyFire(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall BotChatterInterface::FriendlyFire(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  double curtime; // st7
  BotStatement *v4; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx

  if ( friendlyfire.m_pParent != nullptr && friendlyfire.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v2 != nullptr )
    {
      v2->m_chatter = this;
      v2->m_next = nullptr;
      v2->m_prev = nullptr;
      curtime = gpGlobals->curtime;
      v2->m_speakTimestamp = 0.0;
      v2->m_timestamp = curtime;
      v2->m_type = REPORT_FRIENDLY_FIRE;
      v2->m_subject = -1;
      v2->m_place = 0;
      v2->m_meme = nullptr;
      v4 = v2;
      v2->m_startTime = gpGlobals->curtime;
      v2->m_expireTime = gpGlobals->curtime + 1.0;
      v2->m_isSpeaking = false;
      v2->m_nextTime = 0.0;
      v2->m_index = -1;
      v2->m_count = 0;
      v2->m_conditionCount = 0;
    }
    else
    {
      v4 = nullptr;
    }
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "FriendlyFire");
    if ( Phrase != nullptr )
    {
      m_count = v4->m_count;
      if ( m_count < 4 )
      {
        v4->m_statement[m_count].isPhrase = true;
        m_count = v4->m_count;
        v4->m_statement[m_count].phrase = Phrase;
        ++v4->m_count;
      }
    }
    v4->m_startTime = _RandomFloat(this: (IUniformRandomStream *)m_count, a2: 0.30000001, a3: 0.5) + gpGlobals->curtime;
    BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AD480
// Name: public: void BotChatterInterface::Say(char const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::Say(
        BotChatterInterface *this,
        const char *phraseName,
        float lifetime,
        float delay)
{
  BotStatement *v5; // eax
  double curtime; // st7
  BotStatement *v7; // esi
  const BotPhrase *Phrase; // eax
  int m_count; // ecx

  v5 = (BotStatement *)operator new(nSize: 0x70u);
  if ( v5 != nullptr )
  {
    v5->m_chatter = this;
    v5->m_next = nullptr;
    v5->m_prev = nullptr;
    curtime = gpGlobals->curtime;
    v5->m_speakTimestamp = 0.0;
    v5->m_timestamp = curtime;
    v5->m_type = REPORT_MY_INTENTION;
    v5->m_subject = -1;
    v5->m_place = 0;
    v5->m_meme = nullptr;
    v7 = v5;
    v5->m_startTime = gpGlobals->curtime;
    v5->m_expireTime = gpGlobals->curtime + lifetime;
    v5->m_isSpeaking = false;
    v5->m_nextTime = 0.0;
    v5->m_index = -1;
    v5->m_count = 0;
    v5->m_conditionCount = 0;
  }
  else
  {
    v7 = nullptr;
  }
  Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: phraseName);
  if ( Phrase != nullptr )
  {
    m_count = v7->m_count;
    if ( m_count < 4 )
    {
      v7->m_statement[m_count].isPhrase = true;
      v7->m_statement[v7->m_count++].phrase = Phrase;
    }
  }
  if ( delay > 0.0 )
    v7->m_startTime = gpGlobals->curtime + delay;
  BotChatterInterface::AddStatement(this, statement: v7, mustAdd: false);
}

//------------------------------------------------------------------------------
// Address: 0x102AD560
// Name: public: virtual void BotBombsiteStatusMeme::Interpret(class CCSBot __near *,class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotBombsiteStatusMeme::Interpret(BotBombsiteStatusMeme *this, CCSBot *sender, CCSBot *receiver)
{
  if ( this->m_status != CLEAR )
    CSGameState::MarkBombsiteAsPlanted(this: &receiver->m_gameState, zoneIndex: this->m_zoneIndex);
  else
    CSGameState::ClearBombsite(this: &receiver->m_gameState, zoneIndex: this->m_zoneIndex);
  if ( receiver->m_task == FIND_TICKING_BOMB )
  {
    CCSBot::Idle(this: receiver);
    BotChatterInterface::Affirmative(this: &receiver->m_chatter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AD5B0
// Name: public: virtual void BotBombStatusMeme::Interpret(class CCSBot __near *,class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotBombStatusMeme::Interpret(BotBombStatusMeme *this, CCSBot *sender, CCSBot *receiver)
{
  CSGameState::BombState m_state; // eax
  Vector *p_m_pos; // ebx
  int m_nearbyEnemyCount; // edi
  int v6; // eax
  unsigned int Place; // eax

  m_state = this->m_state;
  if ( m_state != MOVING )
  {
    if ( m_state == LOOSE )
    {
      CSGameState::UpdateLooseBomb(this: &receiver->m_gameState, pos: &this->m_pos);
      if ( receiver->m_task == GUARD_BOMB_ZONE )
      {
        CCSBot::Idle(this: receiver);
        BotChatterInterface::Affirmative(this: &receiver->m_chatter);
      }
    }
  }
  else
  {
    p_m_pos = &this->m_pos;
    CSGameState::UpdateBomber(this: &receiver->m_gameState, pos: &this->m_pos);
    if ( !CCSBot::IsRogue(this: receiver) && CCSBot::IsHunting(this: receiver) )
    {
      m_nearbyEnemyCount = receiver->m_nearbyEnemyCount;
      v6 = CBot<CCSPlayer>::GetEnemiesRemaining(this: receiver) >= m_nearbyEnemyCount
         ? m_nearbyEnemyCount
         : CBot<CCSPlayer>::GetEnemiesRemaining(this: receiver);
      if ( v6 == 0 )
      {
        Place = CNavMesh::GetPlace(this: TheNavMesh, pos: p_m_pos);
        CCSBot::RespondToHelpRequest(this: receiver, them: sender, place: Place, maxRange: -1.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AD670
// Name: public: virtual void BotFollowMeme::Interpret(class CCSBot __near *,class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotFollowMeme::Interpret(BotFollowMeme *this, CCSBot *sender, CCSBot *receiver)
{
  CNavArea *v4; // eax
  double v5; // st7
  CNavArea *NearestNavArea; // [esp+8h] [ebp-28h]
  Vector senderOrigin; // [esp+1Ch] [ebp-14h] BYREF
  PathCost cost; // [esp+28h] [ebp-8h] BYREF
  float travelDistance; // [esp+3Ch] [ebp+Ch]

  if ( !CCSBot::IsRogue(this: receiver) && !CCSBot::IsBusy(this: receiver) )
  {
    GetCentroid(result: &senderOrigin, player: sender);
    cost.m_bot = receiver;
    cost.m_route = SAFEST_ROUTE;
    NearestNavArea = CNavMesh::GetNearestNavArea(
                       this: TheNavMesh,
                       pos: &senderOrigin,
                       anyZ: false,
                       maxDist: 10000.0,
                       checkLOS: false,
                       checkGround: true);
    v4 = receiver->GetLastKnownArea(this: receiver);
    v5 = NavAreaTravelDistance<PathCost>(startArea: v4, endArea: NearestNavArea, costFunc: &cost, maxPathLength: 0.0);
    if ( v5 >= 0.0 )
    {
      travelDistance = v5;
      if ( travelDistance <= 1000.0 )
      {
        CCSBot::Follow(this: receiver, player: sender);
        BotChatterInterface::Say(this: &receiver->m_chatter, phraseName: "CoveringFriend", lifetime: 3.0, delay: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AD750
// Name: public: virtual void BotDefendHereMeme::Interpret(class CCSBot __near *,class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotDefendHereMeme::Interpret(BotDefendHereMeme *this, CCSBot *sender, CCSBot *receiver)
{
  Vector *p_m_pos; // ebx
  unsigned int Place; // edi
  bool IsSniper; // al
  const Vector *RandomHidingSpot; // eax
  CNavArea *NearestNavArea; // eax

  if ( !CCSBot::IsRogue(this: receiver) && !CCSBot::IsBusy(this: receiver) )
  {
    p_m_pos = &this->m_pos;
    Place = CNavMesh::GetPlace(this: TheNavMesh, pos: p_m_pos);
    if ( Place != 0
      && (IsSniper = CCSBot::IsSniper(this: receiver),
          (RandomHidingSpot = FindRandomHidingSpot(me: receiver, place: Place, isSniper: IsSniper)) != nullptr) )
    {
      receiver->m_task = HOLD_POSITION;
      receiver->m_taskEntity.m_Index = -1;
      CCSBot::Hide(this: receiver, hidingSpot: RandomHidingSpot, duration: -1.0, holdPosition: false);
    }
    else
    {
      receiver->m_task = HOLD_POSITION;
      receiver->m_taskEntity.m_Index = -1;
      NearestNavArea = CNavMesh::GetNearestNavArea(
                         this: TheNavMesh,
                         pos: p_m_pos,
                         anyZ: false,
                         maxDist: 10000.0,
                         checkLOS: false,
                         checkGround: true);
      CCSBot::Hide(
        this: receiver,
        searchFromArea: NearestNavArea,
        duration: -1.0,
        hideRange: 750.0,
        holdPosition: false);
      BotChatterInterface::Say(this: &receiver->m_chatter, phraseName: "Affirmative", lifetime: 3.0, delay: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AD870
// Name: public: virtual void BotWhereBombMeme::Interpret(class CCSBot __near *,class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotWhereBombMeme::Interpret(BotWhereBombMeme *this, CCSBot *sender, CCSBot *receiver)
{
  int PlantedBombsite; // eax

  PlantedBombsite = CSGameState::GetPlantedBombsite(this: &receiver->m_gameState);
  if ( PlantedBombsite != -1 )
    BotChatterInterface::FoundPlantedBomb(this: &receiver->m_chatter, zoneIndex: PlantedBombsite);
}

//------------------------------------------------------------------------------
// Address: 0x102AD8A0
// Name: public: virtual void BotHostageBeingTakenMeme::Interpret(class CCSBot __near *,class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotHostageBeingTakenMeme::Interpret(BotHostageBeingTakenMeme *this, CCSBot *sender, CCSBot *receiver)
{
  receiver->m_gameState.m_haveSomeHostagesBeenTaken = true;
  if ( !CCSBot::IsBusy(this: receiver) )
  {
    CCSBot::Idle(this: receiver);
    BotChatterInterface::Say(this: &receiver->m_chatter, phraseName: "Affirmative", lifetime: 3.0, delay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AD8F0
// Name: private: BotPhrase::~BotPhrase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotPhrase::~BotPhrase(BotPhrase *this)
{
  int v2; // ebx
  int v3; // ecx
  CUtlVector<BotSpeakable *,CUtlMemory<BotSpeakable *,int> > *v4; // eax
  void **p_m_phrase; // edi
  CUtlVector<BotSpeakable *,CUtlMemory<BotSpeakable *,int> > *v6; // edi
  BotSpeakable **m_pMemory; // eax
  int *v8; // eax
  int *v9; // eax
  CUtlVector<BotSpeakable *,CUtlMemory<BotSpeakable *,int> > **v10; // eax
  int bank; // [esp+8h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  for ( bank = 0; v3 < this->m_voiceBank.m_Size; bank = v3 )
  {
    v4 = this->m_voiceBank.m_Memory.m_pMemory[v3];
    if ( v4->m_Size > 0 )
    {
      do
      {
        p_m_phrase = (void **)&v4->m_Memory.m_pMemory[v2]->m_phrase;
        if ( p_m_phrase != nullptr )
        {
          if ( *p_m_phrase != nullptr )
          {
            free(pMem: *p_m_phrase);
            *p_m_phrase = nullptr;
          }
          free(pMem: p_m_phrase);
          v3 = bank;
        }
        v4 = this->m_voiceBank.m_Memory.m_pMemory[v3];
        ++v2;
      }
      while ( v2 < v4->m_Size );
    }
    v6 = this->m_voiceBank.m_Memory.m_pMemory[v3];
    if ( v6 != nullptr )
    {
      v6->m_Size = 0;
      if ( v6->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v6->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_Memory.m_pMemory);
          v6->m_Memory.m_pMemory = nullptr;
        }
        v6->m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v6->m_Memory.m_pMemory;
      v6->m_pElements = v6->m_Memory.m_pMemory;
      if ( v6->m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v6->m_Memory.m_pMemory = nullptr;
        }
        v6->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v6);
      v3 = bank;
    }
    ++v3;
    v2 = 0;
  }
  if ( this->m_name != nullptr )
    free(pMem: this->m_name);
  this->m_index.m_Size = 0;
  if ( this->m_index.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_index.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_index.m_Memory.m_pMemory);
      this->m_index.m_Memory.m_pMemory = nullptr;
    }
    this->m_index.m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_index.m_Memory.m_pMemory;
  this->m_index.m_pElements = v8;
  if ( this->m_index.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      this->m_index.m_Memory.m_pMemory = nullptr;
    }
    this->m_index.m_Memory.m_nAllocationCount = 0;
  }
  this->m_count.m_Size = 0;
  if ( this->m_count.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_count.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_count.m_Memory.m_pMemory);
      this->m_count.m_Memory.m_pMemory = nullptr;
    }
    this->m_count.m_Memory.m_nAllocationCount = 0;
  }
  v9 = this->m_count.m_Memory.m_pMemory;
  this->m_count.m_pElements = v9;
  if ( this->m_count.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      this->m_count.m_Memory.m_pMemory = nullptr;
    }
    this->m_count.m_Memory.m_nAllocationCount = 0;
  }
  this->m_voiceBank.m_Size = 0;
  if ( this->m_voiceBank.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_voiceBank.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_voiceBank.m_Memory.m_pMemory);
      this->m_voiceBank.m_Memory.m_pMemory = nullptr;
    }
    this->m_voiceBank.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_voiceBank.m_Memory.m_pMemory;
  this->m_voiceBank.m_pElements = v10;
  if ( this->m_voiceBank.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
      this->m_voiceBank.m_Memory.m_pMemory = nullptr;
    }
    this->m_voiceBank.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ADAC0
// Name: public: bool BotChatterInterface::NeedBackup(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall BotChatterInterface::NeedBackup(BotChatterInterface *this)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v4; // st7
  BotStatement *v5; // eax
  BotStatement *v6; // esi
  unsigned int Place; // ebx
  const BotPhrase *Phrase; // eax
  int m_count; // ecx
  BotMeme *v10; // eax
  float v11; // [esp+14h] [ebp-4h]

  p_m_timestamp = &this->m_needBackupInterval.m_timestamp;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_needBackupInterval)
     - this->m_needBackupInterval.m_timestamp.m_Value < 10.0 )
    return 0;
  v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_needBackupInterval);
  if ( p_m_timestamp->m_Value != v4 )
  {
    this->m_needBackupInterval.NetworkStateChanged(
      this: &this->m_needBackupInterval,
      a2: &this->m_needBackupInterval.m_timestamp);
    v11 = v4;
    p_m_timestamp->m_Value = v11;
  }
  if ( CBot<CCSPlayer>::GetFriendsRemaining(this: this->m_me) != 0 )
  {
    v5 = (BotStatement *)operator new(nSize: 0x70u);
    if ( v5 != nullptr )
      v6 = BotStatement::BotStatement(this: v5, chatter: this, type: REPORT_REQUEST_HELP, expireDuration: 10.0);
    else
      v6 = nullptr;
    Place = CCSBot::GetPlace(this: this->m_me);
    SayWhere(say: v6, place: Place);
    Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "Help");
    if ( Phrase != nullptr )
    {
      m_count = v6->m_count;
      if ( m_count < 4 )
      {
        v6->m_statement[m_count].isPhrase = true;
        v6->m_statement[v6->m_count++].phrase = Phrase;
      }
    }
    v10 = (BotMeme *)operator new(nSize: 8u);
    if ( v10 != nullptr )
    {
      v10->__vftable = (BotMeme_vtbl *)&BotHelpMeme::`vftable';
      v10[1].__vftable = (BotMeme_vtbl *)Place;
    }
    else
    {
      v10 = nullptr;
    }
    v6->m_meme = v10;
    BotChatterInterface::AddStatement(this, statement: v6, mustAdd: false);
    return 1;
  }
  else
  {
    BotChatterInterface::Scared(this);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ADBD0
// Name: public: void BotChatterInterface::GuardingHostages(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::GuardingHostages(BotChatterInterface *this, unsigned int place, bool isPlan)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v5; // st7
  float v6; // [esp+18h] [ebp-4h]

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    p_m_timestamp = &this->m_planInterval.m_timestamp;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_planInterval) - this->m_planInterval.m_timestamp.m_Value >= 20.0 )
    {
      v5 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_planInterval);
      if ( p_m_timestamp->m_Value != v5 )
      {
        this->m_planInterval.NetworkStateChanged(this: &this->m_planInterval, a2: &this->m_planInterval.m_timestamp);
        v6 = v5;
        p_m_timestamp->m_Value = v6;
      }
      if ( isPlan )
        BotChatterInterface::AnnouncePlan(this, phraseName: "GoingToGuardHostages", place);
      else
        BotChatterInterface::Say(this, phraseName: "GuardingHostages", lifetime: 3.0, delay: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ADC80
// Name: public: void BotChatterInterface::GuardingHostageEscapeZone(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::GuardingHostageEscapeZone(BotChatterInterface *this, bool isPlan)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v4; // st7
  float v5; // [esp+18h] [ebp-4h]

  if ( TheBots[1].m_debugMessage[0].m_string[484] == 0 )
  {
    p_m_timestamp = &this->m_planInterval.m_timestamp;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_planInterval) - this->m_planInterval.m_timestamp.m_Value >= 20.0 )
    {
      v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_planInterval);
      if ( p_m_timestamp->m_Value != v4 )
      {
        this->m_planInterval.NetworkStateChanged(this: &this->m_planInterval, a2: &this->m_planInterval.m_timestamp);
        v5 = v4;
        p_m_timestamp->m_Value = v5;
      }
      if ( isPlan )
        BotChatterInterface::AnnouncePlan(this, phraseName: "GoingToGuardHostageEscapeZone", place: 0);
      else
        BotChatterInterface::Say(this, phraseName: "GuardingHostageEscapeZone", lifetime: 3.0, delay: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ADD30
// Name: public: void BotChatterInterface::Encourage(char const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::Encourage(
        BotChatterInterface *this,
        const char *phraseName,
        float repeatInterval,
        float lifetime)
{
  double v5; // st7
  float lifetimea; // [esp+1Ch] [ebp+10h]

  if ( IntervalTimer::Now(this: (CEffectsServer *)&BotChatterInterface::m_encourageTimer) > BotChatterInterface::m_encourageTimer.m_timestamp.m_Value )
  {
    BotChatterInterface::Say(this, phraseName, lifetime, delay: 0.0);
    v5 = IntervalTimer::Now(this: (CEffectsServer *)&BotChatterInterface::m_encourageTimer) + repeatInterval;
    if ( BotChatterInterface::m_encourageTimer.m_timestamp.m_Value != v5 )
    {
      BotChatterInterface::m_encourageTimer.NetworkStateChanged(
        this: &BotChatterInterface::m_encourageTimer,
        a2: &BotChatterInterface::m_encourageTimer.m_timestamp);
      lifetimea = v5;
      BotChatterInterface::m_encourageTimer.m_timestamp.m_Value = lifetimea;
    }
    if ( BotChatterInterface::m_encourageTimer.m_duration.m_Value != repeatInterval )
    {
      BotChatterInterface::m_encourageTimer.NetworkStateChanged(
        this: &BotChatterInterface::m_encourageTimer,
        a2: &BotChatterInterface::m_encourageTimer.m_duration);
      BotChatterInterface::m_encourageTimer.m_duration.m_Value = repeatInterval;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ADDF0
// Name: private: void BotPhrase::InitVoiceBank(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotPhrase::InitVoiceBank(BotPhrase *this, int bankIndex)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_count; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_index; // ebx
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v6; // ecx
  int v7; // eax
  vgui::TreeNode **v8; // esi
  vgui::TreeNode **v9; // esi
  int v10; // eax
  vgui::TreeNode **v11; // ecx
  int v12; // eax
  vgui::TreeNode **v13; // esi
  CUtlVector<BotSpeakable *,CUtlMemory<BotSpeakable *,int> > *v14; // eax
  int m_Size; // esi
  int v16; // eax
  CUtlVector<BotSpeakable *,CUtlMemory<BotSpeakable *,int> > **v17; // ecx
  int v18; // eax
  CUtlVector<BotSpeakable *,CUtlMemory<BotSpeakable *,int> > **v19; // esi
  CUtlVector<BotSpeakable *,CUtlMemory<BotSpeakable *,int> > *v20; // [esp+0h] [ebp-8h]

  if ( this->m_numVoiceBanks <= bankIndex )
  {
    p_m_count = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_count;
    p_m_index = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_index;
    do
    {
      m_pMemory = p_m_count[1].m_pMemory;
      m_nAllocationCount = p_m_count->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_count, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_count[1].m_pMemory;
      v6 = p_m_count->m_pMemory;
      v7 = (char *)p_m_count[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_count[1].m_nAllocationCount = (int)p_m_count->m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &v6[(_DWORD)m_pMemory + 1], src: &v6[(_DWORD)m_pMemory], count: 4 * v7);
      v8 = &p_m_count->m_pMemory[(_DWORD)m_pMemory];
      if ( v8 != nullptr )
        *v8 = nullptr;
      v9 = p_m_index[1].m_pMemory;
      v10 = p_m_index->m_nAllocationCount;
      if ( (int)v9 + 1 > v10 )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_index, num: (int)v9 - v10 + 1);
      ++p_m_index[1].m_pMemory;
      v11 = p_m_index->m_pMemory;
      v12 = (char *)p_m_index[1].m_pMemory - (char *)v9 - 1;
      p_m_index[1].m_nAllocationCount = (int)p_m_index->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[(_DWORD)v9 + 1], src: &v11[(_DWORD)v9], count: 4 * v12);
      v13 = &p_m_index->m_pMemory[(_DWORD)v9];
      if ( v13 != nullptr )
        *v13 = nullptr;
      v14 = (CUtlVector<BotSpeakable *,CUtlMemory<BotSpeakable *,int> > *)operator new(nSize: 0x14u);
      if ( v14 != nullptr )
      {
        v14->m_Memory.m_pMemory = nullptr;
        v14->m_Memory.m_nAllocationCount = 0;
        v14->m_Memory.m_nGrowSize = 0;
        v14->m_Size = 0;
        v14->m_pElements = nullptr;
        v20 = v14;
      }
      else
      {
        v20 = nullptr;
      }
      m_Size = this->m_voiceBank.m_Size;
      v16 = this->m_voiceBank.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > v16 )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_voiceBank,
          num: m_Size - v16 + 1);
      ++this->m_voiceBank.m_Size;
      v17 = this->m_voiceBank.m_Memory.m_pMemory;
      v18 = this->m_voiceBank.m_Size - m_Size - 1;
      this->m_voiceBank.m_pElements = v17;
      if ( v18 > 0 )
        _V_memmove(dest: &v17[m_Size + 1], src: &v17[m_Size], count: 4 * v18);
      v19 = &this->m_voiceBank.m_Memory.m_pMemory[m_Size];
      if ( v19 != nullptr )
        *v19 = v20;
      ++this->m_numVoiceBanks;
    }
    while ( this->m_numVoiceBanks <= bankIndex );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ADF50
// Name: public: void BotPhraseManager::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotPhraseManager::Reset(BotPhraseManager *this)
{
  int i; // edi
  BotPhrase *v3; // ebx
  int j; // edi
  BotPhrase **m_pMemory; // ecx
  BotPhrase *v6; // ebx

  for ( i = 0; i < this->m_list.m_Size; ++i )
  {
    v3 = this->m_list.m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      BotPhrase::~BotPhrase(this: this->m_list.m_Memory.m_pMemory[i]);
      free(pMem: (void *)v3);
    }
  }
  for ( j = 0; j < this->m_placeList.m_Size; ++j )
  {
    m_pMemory = this->m_placeList.m_Memory.m_pMemory;
    v6 = m_pMemory[j];
    if ( v6 != nullptr )
    {
      BotPhrase::~BotPhrase(this: m_pMemory[j]);
      free(pMem: (void *)v6);
    }
  }
  this->m_list.m_Size = 0;
  this->m_placeList.m_Size = 0;
  this->m_painPhrase = nullptr;
  this->m_agreeWithPlanPhrase = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102ADFC0
// Name: private: void BotChatterInterface::ReportEnemies(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::ReportEnemies(BotChatterInterface *this)
{
  CCSBot *m_me; // edi
  int m_nearbyEnemyCount; // ebx
  int EnemiesRemaining; // eax

  if ( this->m_me->IsAlive(this: this->m_me) )
  {
    m_me = this->m_me;
    m_nearbyEnemyCount = m_me->m_nearbyEnemyCount;
    if ( CBot<CCSPlayer>::GetEnemiesRemaining(this: m_me) >= m_nearbyEnemyCount )
      EnemiesRemaining = m_nearbyEnemyCount;
    else
      EnemiesRemaining = CBot<CCSPlayer>::GetEnemiesRemaining(this: m_me);
    if ( EnemiesRemaining != 0 )
    {
      if ( !this->m_seeAtLeastOneEnemy )
      {
        this->m_seeAtLeastOneEnemy = true;
        this->m_timeWhenSawFirstEnemy = gpGlobals->curtime;
      }
    }
    else
    {
      this->m_seeAtLeastOneEnemy = false;
      this->m_reportedEnemies = false;
    }
    if ( !this->m_reportedEnemies && this->m_seeAtLeastOneEnemy )
    {
      if ( !CCSBot::IsOutnumbered(this: this->m_me) || BotChatterInterface::NeedBackup(this) == 0 )
        BotChatterInterface::EnemySpotted(this: &this->m_me->m_chatter);
      this->m_reportedEnemies = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AE050
// Name: public: void BotChatterInterface::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::Update(BotChatterInterface *this)
{
  CCSBot *m_me; // esi
  int m_nearbyFriendCount; // edi
  int v4; // eax
  BotStatement *ActiveStatement; // esi
  BotStatement *v6; // eax
  BotStatement *v7; // edi
  BotStatement *m_statementList; // esi
  BotStatement *v9; // eax
  BotStatement *v10; // eax
  BotStatement *m_next; // eax
  BotStatement *m_prev; // eax
  float nextSaya; // [esp+Ch] [ebp-4h]
  BotStatement *nextSay; // [esp+Ch] [ebp-4h]

  BotChatterInterface::ReportEnemies(this);
  if ( CBot<CCSPlayer>::GetFriendsRemaining(this: this->m_me) != 0 )
  {
    m_me = this->m_me;
    m_nearbyFriendCount = m_me->m_nearbyFriendCount;
    if ( CBot<CCSPlayer>::GetFriendsRemaining(this: m_me) < m_nearbyFriendCount )
      m_nearbyFriendCount = CBot<CCSPlayer>::GetFriendsRemaining(this: m_me);
    if ( m_nearbyFriendCount != CBot<CCSPlayer>::GetFriendsRemaining(this: this->m_me)
      && CBot<CCSPlayer>::GetEnemiesRemaining(this: this->m_me) > 0 )
    {
      v4 = CBaseEntity::GetTeamNumber(this: this->m_me) % 2;
      if ( *((float *)&BotChatterInterface::m_radioSilenceInterval.m_pNextSystem + 2 * v4) <= 0.0
        || (nextSaya = IntervalTimer::Now(this: (CEffectsServer *)((char *)&BotChatterInterface::m_radioSilenceInterval
                                                                 + 8 * v4))
                     - *((float *)&BotChatterInterface::m_radioSilenceInterval.m_pNextSystem + 2 * v4)) > 30.0 )
      {
        BotChatterInterface::ReportIn(this);
      }
    }
  }
  ActiveStatement = BotChatterInterface::GetActiveStatement(this);
  if ( ActiveStatement != nullptr
    && ActiveStatement->m_chatter->m_me == this->m_me
    && BotStatement::Update(this: ActiveStatement) == 0 )
  {
    BotChatterInterface::RemoveStatement(this, statement: ActiveStatement);
  }
  v6 = BotChatterInterface::GetActiveStatement(this);
  v7 = v6;
  if ( v6 != nullptr && v6->m_chatter->m_me == this->m_me )
    v7 = nullptr;
  m_statementList = this->m_statementList;
  if ( this->m_statementList != nullptr )
  {
    while ( 1 )
    {
      nextSay = m_statementList->m_next;
      if ( BotStatement::IsValid(this: m_statementList) == 0 )
        break;
      if ( !m_statementList->m_isSpeaking )
      {
        if ( (!CRecipientFilter::IsReliable(this: (CRecipientFilter *)&m_statementList->m_chatter->m_me->m_gameState)
           || m_statementList->m_type == REPORT_EMOTE)
          && (!m_statementList->m_chatter->m_me->m_chatter.m_seeAtLeastOneEnemy
           || m_statementList->m_type != REPORT_ENEMY_LOST)
          && gpGlobals->curtime <= m_statementList->m_expireTime )
        {
          if ( v7 != nullptr )
          {
            BotStatement::Convert(this: m_statementList, say: v7);
            if ( BotStatement::IsRedundant(this: m_statementList, say: v7) != 0 )
            {
              CBot<CCSPlayer>::PrintIfWatched(
                this: this->m_me,
                format: "Teammate said what I was going to say - shutting up.\n");
              BotChatterInterface::RemoveStatement(this, statement: m_statementList);
            }
          }
          goto LABEL_39;
        }
        CBot<CCSPlayer>::PrintIfWatched(this: this->m_me, format: "Statement obsolete - removing.\n");
        m_next = m_statementList->m_next;
        if ( m_next != nullptr )
          m_next->m_prev = m_statementList->m_prev;
        m_prev = m_statementList->m_prev;
        if ( m_prev != nullptr )
        {
          m_prev->m_next = m_statementList->m_next;
          goto LABEL_23;
        }
LABEL_22:
        this->m_statementList = m_statementList->m_next;
LABEL_23:
        if ( m_statementList->m_meme != nullptr )
          free(pMem: m_statementList->m_meme);
        free(pMem: m_statementList);
      }
LABEL_39:
      m_statementList = nextSay;
      if ( nextSay == nullptr )
        return;
    }
    v9 = m_statementList->m_next;
    if ( v9 != nullptr )
      v9->m_prev = m_statementList->m_prev;
    v10 = m_statementList->m_prev;
    if ( v10 == nullptr )
      goto LABEL_22;
    v10->m_next = m_statementList->m_next;
    goto LABEL_23;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AE250
// Name: public: void BotChatterInterface::ReportingIn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotChatterInterface::ReportingIn(BotChatterInterface *this)
{
  BotStatement *v2; // eax
  double curtime; // st7
  BotStatement *v4; // esi
  CCSBot *m_me; // eax
  const BotPhrase *Phrase; // eax
  char *v7; // edi
  CBaseEntity *LooseBomb; // eax
  Vector *AbsOrigin; // eax
  BotChatterInterface *p_m_chatter; // edi
  bool v11; // al
  BotChatterInterface *v12; // edi
  bool v13; // al
  const BotPhrase *v14; // eax
  int m_count; // ecx
  BotMeme *v16; // eax
  const BotPhrase *v17; // eax
  CCSBot *v18; // ecx
  const BotPhrase *v19; // eax
  int v20; // ecx
  int v21; // ecx
  unsigned int place; // [esp+14h] [ebp-4h]

  v2 = (BotStatement *)operator new(nSize: 0x70u);
  if ( v2 != nullptr )
  {
    v2->m_chatter = this;
    v2->m_next = nullptr;
    v2->m_prev = nullptr;
    curtime = gpGlobals->curtime;
    v2->m_speakTimestamp = 0.0;
    v2->m_timestamp = curtime;
    v2->m_type = REPORT_INFORMATION;
    v2->m_subject = -1;
    v2->m_place = 0;
    v2->m_meme = nullptr;
    v4 = v2;
    v2->m_startTime = gpGlobals->curtime;
    v2->m_expireTime = gpGlobals->curtime + 10.0;
    v2->m_isSpeaking = false;
    v2->m_nextTime = 0.0;
    v2->m_index = -1;
    v2->m_count = 0;
    v2->m_conditionCount = 0;
  }
  else
  {
    v4 = nullptr;
  }
  place = CCSBot::GetPlace(this: this->m_me);
  SayWhere(say: v4, place);
  m_me = this->m_me;
  switch ( m_me->m_task )
  {
    case PLANT_BOMB:
      BotChatterInterface::GoingToPlantTheBomb(this: &m_me->m_chatter, place: 0);
      break;
    case DEFUSE_BOMB:
      BotChatterInterface::Say(this: &m_me->m_chatter, phraseName: "DefusingBomb", lifetime: 3.0, delay: 0.0);
      break;
    case GUARD_LOOSE_BOMB:
      if ( CCSBotManager::GetLooseBomb(this: (CCSBotManager *)TheBots) != nullptr )
      {
        Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "GuardingLooseBomb");
        BotStatement::AppendPhrase(this: v4, phrase: Phrase);
        v7 = (char *)operator new(nSize: 0x14u);
        if ( v7 != nullptr )
        {
          LooseBomb = CCSBotManager::GetLooseBomb(this: (CCSBotManager *)TheBots);
          AbsOrigin = CBaseEntity::GetAbsOrigin(this: LooseBomb);
          *(_DWORD *)v7 = &BotBombStatusMeme::`vftable';
          *((_DWORD *)v7 + 1) = 1;
          *(Vector *)(v7 + 8) = *AbsOrigin;
          v4->m_meme = (BotMeme *)v7;
        }
        else
        {
          v4->m_meme = nullptr;
        }
      }
      break;
    case RESCUE_HOSTAGES:
      BotChatterInterface::EscortingHostages(this: &m_me->m_chatter);
      break;
    case GUARD_HOSTAGES:
      p_m_chatter = &m_me->m_chatter;
      v11 = CCSBot::IsAtHidingSpot(this: this->m_me);
      BotChatterInterface::GuardingHostages(this: p_m_chatter, place: 0, isPlan: !v11);
      break;
    case GUARD_HOSTAGE_RESCUE_ZONE:
      v12 = &m_me->m_chatter;
      v13 = CCSBot::IsAtHidingSpot(this: this->m_me);
      BotChatterInterface::GuardingHostageEscapeZone(this: v12, isPlan: !v13);
      break;
    default:
      break;
  }
  if ( CCSBot::IsAttacking(this: this->m_me) )
  {
    if ( CCSBot::IsOutnumbered(this: this->m_me) )
    {
      v14 = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "Help");
      if ( v14 != nullptr )
      {
        m_count = v4->m_count;
        if ( m_count < 4 )
        {
          v4->m_statement[m_count].isPhrase = true;
          v4->m_statement[v4->m_count++].phrase = v14;
        }
      }
      v16 = (BotMeme *)operator new(nSize: 8u);
      if ( v16 != nullptr )
      {
        v16->__vftable = (BotMeme_vtbl *)&BotHelpMeme::`vftable';
        v16[1].__vftable = (BotMeme_vtbl *)place;
        v4->m_meme = v16;
      }
      else
      {
        v4->m_meme = nullptr;
      }
      goto LABEL_34;
    }
    v17 = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "InCombat");
LABEL_31:
    if ( v17 != nullptr )
    {
      v21 = v4->m_count;
      if ( v21 < 4 )
      {
        v4->m_statement[v21].isPhrase = true;
        v4->m_statement[v4->m_count++].phrase = v17;
      }
    }
    goto LABEL_34;
  }
  v4->m_startTime = gpGlobals->curtime + 2.0;
  v18 = this->m_me;
  if ( v18->m_enemyDeathTimestamp < 10.0
    && v18->m_enemyDeathTimestamp >= (float)((float)(gpGlobals->curtime - v18->m_lastSawEnemyTimestamp) + 0.5) )
  {
    v17 = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "EnemyDown");
    goto LABEL_31;
  }
  if ( (float)(gpGlobals->curtime - v18->m_lastSawEnemyTimestamp) >= 10.0 )
  {
    v17 = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "Clear");
    goto LABEL_31;
  }
  v19 = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "EnemySpotted");
  if ( v19 != nullptr )
  {
    v20 = v4->m_count;
    if ( v20 < 4 )
    {
      v4->m_statement[v20].isPhrase = true;
      v4->m_statement[v4->m_count++].phrase = v19;
      BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
      return;
    }
  }
LABEL_34:
  BotChatterInterface::AddStatement(this, statement: v4, mustAdd: false);
}

//------------------------------------------------------------------------------
// Address: 0x102AE5C0
// Name: public: virtual void BotRequestReportMeme::Interpret(class CCSBot __near *,class CCSBot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotRequestReportMeme::Interpret(BotRequestReportMeme *this, CCSBot *sender, CCSBot *receiver)
{
  BotChatterInterface::ReportingIn(this: &receiver->m_chatter);
}

//------------------------------------------------------------------------------
// Address: 0x102AE5E0
// Name: private: BotPhrase::BotPhrase(bool)
// Source: json
//------------------------------------------------------------------------------
BotPhrase *__thiscall BotPhrase::BotPhrase(BotPhrase *this, bool isPlace)
{
  this->m_voiceBank.m_Memory.m_pMemory = nullptr;
  this->m_voiceBank.m_Memory.m_nAllocationCount = 0;
  this->m_voiceBank.m_Memory.m_nGrowSize = 0;
  this->m_voiceBank.m_Size = 0;
  this->m_voiceBank.m_pElements = nullptr;
  this->m_count.m_Memory.m_pMemory = nullptr;
  this->m_count.m_Memory.m_nAllocationCount = 0;
  this->m_count.m_Memory.m_nGrowSize = 0;
  this->m_count.m_Size = 0;
  this->m_count.m_pElements = nullptr;
  this->m_index.m_Memory.m_pMemory = nullptr;
  this->m_index.m_Memory.m_nAllocationCount = 0;
  this->m_index.m_Memory.m_nGrowSize = 0;
  this->m_index.m_Size = 0;
  this->m_index.m_pElements = nullptr;
  this->m_isPlace = isPlace;
  this->m_placeCriteria = 0xFFFF;
  this->m_countCriteria = 0xFFFF;
  this->m_name = nullptr;
  this->m_place = 0;
  this->m_radioEvent = RADIO_INVALID;
  this->m_isImportant = false;
  this->m_numVoiceBanks = 0;
  BotPhrase::InitVoiceBank(this, bankIndex: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102AE650
// Name: public: bool BotPhraseManager::Initialize(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall BotPhraseManager::Initialize(BotPhraseManager *this, const char *filename, int bankIndex)
{
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // edx
  void *v4; // esi
  unsigned int v6; // edi
  char *v7; // ebx
  int (__thiscall *Read)(IBaseFileSystem *, void *, int, void *); // eax
  int v9; // edi
  const char *v10; // edi
  const char *Token; // esi
  BotPhraseManager *v12; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  BotChatterOutputType *m_pMemory; // ecx
  int v16; // eax
  BotChatterOutputType *v17; // edi
  const char *v18; // eax
  const char *v19; // eax
  BotPhrase *Place; // ebx
  BotPhrase *v21; // eax
  const char *v22; // eax
  const char *v23; // edi
  char *v24; // eax
  unsigned int v25; // eax
  char *v26; // edi
  const char *v27; // esi
  const char *v28; // esi
  const char *v29; // esi
  RadioType v30; // eax
  const char **v31; // eax
  const char **v32; // ebx
  char *v33; // eax
  unsigned int v34; // edx
  unsigned int v35; // eax
  double v36; // st7
  CUtlMemory<vgui::TreeNode *,int> *v37; // esi
  vgui::TreeNode **v38; // edi
  int v39; // eax
  vgui::TreeNode **v40; // ecx
  int v41; // eax
  const char ***v42; // edi
  BotPhrase *v43; // edx
  bool v44; // al
  BotPhraseManager *v45; // esi
  int v46; // edi
  int v47; // eax
  BotPhrase **v48; // ecx
  int v49; // eax
  BotPhrase **v50; // eax
  BotPhraseManager *v51; // edi
  int v52; // esi
  int v53; // eax
  BotPhrase **v54; // ecx
  int v55; // eax
  const char *v56; // eax
  BotPhraseManager *v57; // esi
  const char *v58; // eax
  char compositeFilename[128]; // [esp+8h] [ebp-124h] BYREF
  char baseDir[128]; // [esp+88h] [ebp-A4h] BYREF
  RadioType radioEvent; // [esp+108h] [ebp-24h]
  unsigned int countCriteria; // [esp+10Ch] [ebp-20h]
  BOOL isPlace; // [esp+110h] [ebp-1Ch]
  unsigned int placeCriteria; // [esp+114h] [ebp-18h]
  BotPhrase *phrase; // [esp+118h] [ebp-14h]
  char *phraseDataFile; // [esp+11Ch] [ebp-10h]
  BotPhraseManager *v67; // [esp+120h] [ebp-Ch]
  bool isImportant; // [esp+126h] [ebp-6h]
  bool isDefault; // [esp+127h] [ebp-5h]
  const char *phraseData; // [esp+128h] [ebp-4h]

  v67 = this;
  Open = filesystem->Open;
  isDefault = bankIndex == 0;
  v4 = Open(this: &filesystem->IBaseFileSystem, a2: filename, a3: "r", a4: nullptr);
  if ( v4 == nullptr )
  {
    CONSOLE_ECHO(pszMsg: "WARNING: Cannot access bot phrase database '%s'\n", filename);
    return 0;
  }
  v6 = filesystem->Size(this: &filesystem->IBaseFileSystem, a2: filename, a3: nullptr);
  v7 = (char *)operator new(nSize: v6);
  Read = filesystem->Read;
  phraseDataFile = v7;
  v9 = Read(this: &filesystem->IBaseFileSystem, a2: v7, a3: v6, a4: v4);
  filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v4);
  if ( v9 > 0 )
    v7[v9 - 1] = 0;
  memset(baseDir, 0, sizeof(baseDir));
  v10 = SharedParse(data: v7);
  phraseData = v10;
  if ( v10 == nullptr )
  {
LABEL_94:
    free(pMem: v7);
    v57 = v67;
    v57->m_painPhrase = BotPhraseManager::GetPhrase(this: v67, name: "Pain");
    v57->m_agreeWithPlanPhrase = BotPhraseManager::GetPhrase(this: v57, name: "AgreeWithPlan");
    return 1;
  }
  while ( 1 )
  {
    Token = SharedGetToken();
    if ( _V_stricmp(s1: Token, s2: "Output") == 0 )
    {
      phraseData = SharedParse(data: v10);
      if ( phraseData == nullptr )
        goto LABEL_95;
      if ( v67->m_output.m_Size <= bankIndex )
      {
        v12 = v67;
        do
        {
          m_Size = v12->m_output.m_Size;
          m_nAllocationCount = v12->m_output.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&v12->m_output,
              num: m_Size - m_nAllocationCount + 1);
          ++v12->m_output.m_Size;
          m_pMemory = v12->m_output.m_Memory.m_pMemory;
          v16 = v12->m_output.m_Size - m_Size - 1;
          v12->m_output.m_pElements = m_pMemory;
          if ( v16 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
          v17 = &v12->m_output.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = BOT_CHATTER_RADIO;
        }
        while ( v12->m_output.m_Size <= bankIndex );
      }
      v18 = SharedGetToken();
      if ( _V_stricmp(s1: v18, s2: "Voice") == 0 )
        v67->m_output.m_Memory.m_pMemory[bankIndex] = BOT_CHATTER_VOICE;
      goto LABEL_93;
    }
    if ( _V_stricmp(s1: Token, s2: "BaseDir") != 0 )
      break;
    phraseData = SharedParse(data: v10);
    if ( phraseData == nullptr )
    {
LABEL_95:
      CONSOLE_ECHO(pszMsg: "Error parsing '%s' - expected identifier\n", filename);
      free(pMem: v7);
      return 0;
    }
    v19 = SharedGetToken();
    V_strncpy(pDest: baseDir, pSrc: v19, maxLen: 128);
    V_strncat(pDest: baseDir, pSrc: "\\", destBufferSize: 0x80u, max_chars_to_copy: -1);
    baseDir[127] = 0;
LABEL_93:
    v56 = SharedParse(data: phraseData);
    v7 = phraseDataFile;
    phraseData = v56;
    if ( v56 == nullptr )
      goto LABEL_94;
    v10 = phraseData;
  }
  if ( _V_stricmp(s1: Token, s2: "Place") != 0 && _V_stricmp(s1: Token, s2: "Chatter") != 0 )
    goto LABEL_93;
  LOBYTE(isPlace) = _V_stricmp(s1: Token, s2: "Place") == 0;
  Place = nullptr;
  phrase = nullptr;
  if ( isDefault )
  {
    v21 = (BotPhrase *)operator new(nSize: 0x5Cu);
    if ( v21 != nullptr )
      Place = BotPhrase::BotPhrase(this: v21, isPlace);
    else
      Place = nullptr;
    phrase = Place;
  }
  phraseData = SharedParse(data: phraseData);
  if ( phraseData == nullptr )
  {
    CONSOLE_ECHO(pszMsg: "Error parsing '%s' - expected identifier\n", filename);
    free(pMem: phraseDataFile);
    return 0;
  }
  v22 = SharedGetToken();
  if ( isDefault )
  {
    v23 = v22;
    v24 = (char *)operator new(nSize: strlen(v22) + 1);
    strcpy(v24, v23);
    Place->m_name = v24;
    if ( isPlace )
      Place->m_place = CNavMesh::NameToPlace(this: TheNavMesh, name: v24);
    else
      Place->m_place = 0;
LABEL_40:
    BotPhrase::InitVoiceBank(this: Place, bankIndex);
    v25 = 0xFFFF;
    countCriteria = 0xFFFF;
    radioEvent = RADIO_INVALID;
    isImportant = false;
LABEL_41:
    placeCriteria = v25;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              phraseData = SharedParse(data: phraseData);
              if ( phraseData == nullptr )
              {
                CONSOLE_ECHO(pszMsg: "Error parsing %s - expected 'End'\n", filename);
                free(pMem: phraseDataFile);
                return 0;
              }
              v26 = SharedGetToken();
              if ( _V_stricmp(s1: v26, s2: "Place") != 0 )
                break;
              phraseData = SharedParse(data: phraseData);
              if ( phraseData == nullptr )
              {
                CONSOLE_ECHO(pszMsg: "Error parsing %s - expected Place name\n", filename);
                free(pMem: phraseDataFile);
                return 0;
              }
              v27 = SharedGetToken();
              if ( _V_stricmp(s1: "ANY", s2: v27) != 0 )
              {
                if ( _V_stricmp(s1: "UNDEFINED", s2: v27) != 0 )
                {
                  v25 = CNavMesh::NameToPlace(this: TheNavMesh, name: v27);
                  goto LABEL_41;
                }
                placeCriteria = 0;
              }
              else
              {
                placeCriteria = 0xFFFF;
              }
            }
            if ( _V_stricmp(s1: v26, s2: "Count") != 0 )
              break;
            phraseData = SharedParse(data: phraseData);
            if ( phraseData == nullptr )
            {
              CONSOLE_ECHO(pszMsg: "Error parsing %s - expected Count value\n", filename);
              free(pMem: phraseDataFile);
              return 0;
            }
            v28 = SharedGetToken();
            if ( _V_stricmp(s1: v28, s2: "Many") != 0 )
              countCriteria = atoi(nptr: v28);
            else
              countCriteria = 4;
          }
          if ( _V_stricmp(s1: v26, s2: "Radio") != 0 )
            break;
          phraseData = SharedParse(data: phraseData);
          if ( phraseData == nullptr )
          {
            CONSOLE_ECHO(pszMsg: "Error parsing %s - expected radio event\n", filename);
            free(pMem: phraseDataFile);
            return 0;
          }
          v29 = SharedGetToken();
          v30 = NameToRadioEvent(name: v29);
          if ( (unsigned int)(v30 - 2) > 0x16 )
          {
            CONSOLE_ECHO(pszMsg: "Error parsing %s - invalid radio event '%s'\n", filename, v29);
            free(pMem: phraseDataFile);
            return 0;
          }
          radioEvent = v30;
        }
        if ( _V_stricmp(s1: v26, s2: "Important") != 0 )
          break;
        isImportant = true;
      }
      if ( _V_stricmp(s1: v26, s2: "End") == 0 )
        break;
      v31 = (const char **)operator new(nSize: 0x10u);
      if ( v31 != nullptr )
      {
        *v31 = nullptr;
        v32 = v31;
      }
      else
      {
        v32 = nullptr;
      }
      if ( baseDir[0] != 0 )
      {
        V_snprintf(pDest: compositeFilename, maxLen: 128, pFormat: "%s%s", baseDir, v26);
        v26 = compositeFilename;
      }
      v33 = CloneString(str: v26);
      v34 = placeCriteria;
      *v32 = v33;
      v35 = countCriteria;
      v32[2] = (const char *)v34;
      v32[3] = (const char *)v35;
      v36 = ((double (__thiscall *)(IEngineSound *, const char *))enginesound->GetSoundDuration)(
              a1: enginesound,
              a2: *v32);
      *((float *)v32 + 1) = v36;
      if ( v36 <= 0.0 )
      {
        if ( !engine->IsDedicatedServer(this: engine) )
          DevMsg(a1: "Warning: Couldn't get duration of phrase '%s'\n", *v32);
        v32[1] = (const char *)1065353216;
      }
      v37 = (CUtlMemory<vgui::TreeNode *,int> *)phrase->m_voiceBank.m_Memory.m_pMemory[bankIndex];
      v38 = v37[1].m_pMemory;
      v39 = v37->m_nAllocationCount;
      if ( (int)v38 + 1 > v39 )
        CUtlMemory<CNavLadder *,int>::Grow(this: v37, num: (int)v38 - v39 + 1);
      ++v37[1].m_pMemory;
      v40 = v37->m_pMemory;
      v41 = (char *)v37[1].m_pMemory - (char *)v38 - 1;
      v37[1].m_nAllocationCount = (int)v37->m_pMemory;
      if ( v41 > 0 )
        _V_memmove(dest: &v40[(_DWORD)v38 + 1], src: &v40[(_DWORD)v38], count: 4 * v41);
      v42 = (const char ***)&v37->m_pMemory[(_DWORD)v38];
      if ( v42 != nullptr )
        *v42 = v32;
      v43 = phrase;
      ++phrase->m_count.m_Memory.m_pMemory[bankIndex];
      Place = v43;
    }
    if ( isDefault )
    {
      v44 = isImportant;
      Place->m_radioEvent = radioEvent;
      Place->m_isImportant = v44;
    }
    if ( isPlace )
    {
      v45 = v67;
      v46 = v67->m_placeList.m_Size;
      v47 = v67->m_placeList.m_Memory.m_nAllocationCount;
      if ( v46 + 1 > v47 )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&v67->m_placeList,
          num: v46 - v47 + 1);
      ++v45->m_placeList.m_Size;
      v48 = v45->m_placeList.m_Memory.m_pMemory;
      v49 = v45->m_placeList.m_Size - v46 - 1;
      v45->m_placeList.m_pElements = v48;
      if ( v49 > 0 )
        _V_memmove(dest: &v48[v46 + 1], src: &v48[v46], count: 4 * v49);
      v50 = &v45->m_placeList.m_Memory.m_pMemory[v46];
    }
    else
    {
      v51 = v67;
      v52 = v67->m_list.m_Size;
      v53 = v67->m_list.m_Memory.m_nAllocationCount;
      if ( v52 + 1 > v53 )
        CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)v67, num: v52 - v53 + 1);
      ++v51->m_list.m_Size;
      v54 = v51->m_list.m_Memory.m_pMemory;
      v55 = v51->m_list.m_Size - v52 - 1;
      v51->m_list.m_pElements = v51->m_list.m_Memory.m_pMemory;
      if ( v55 > 0 )
        _V_memmove(dest: &v54[v52 + 1], src: &v54[v52], count: 4 * v55);
      v50 = &v51->m_list.m_Memory.m_pMemory[v52];
    }
    if ( v50 != nullptr )
      *v50 = Place;
    goto LABEL_93;
  }
  if ( isPlace )
    Place = BotPhraseManager::GetPlace(this: v67, name: v22);
  else
    Place = BotPhraseManager::GetPhrase(this: v67, name: v22);
  phrase = Place;
  if ( Place != nullptr )
    goto LABEL_40;
  v58 = SharedGetToken();
  CONSOLE_ECHO(pszMsg: "Error parsing '%s' - phrase '%s' is invalid\n", filename, v58);
  free(pMem: phraseDataFile);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10410770
// Name: _dynamic_initializer_for__BotChatterInterface::m_encourageTimer__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__BotChatterInterface::m_encourageTimer__()
{
  void (__thiscall *NetworkStateChanged)(CountdownTimer *, void *); // edx

  CNavMesh::SaveCustomData(
    this: (vgui::TreeView *)&BotChatterInterface::m_encourageTimer,
    itemIndex: (int)&BotChatterInterface::m_encourageTimer.m_duration);
  NetworkStateChanged = BotChatterInterface::m_encourageTimer.NetworkStateChanged;
  BotChatterInterface::m_encourageTimer.m_timestamp.m_Value = -1.0;
  return ((int (__thiscall *)(CountdownTimer *, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))NetworkStateChanged)(
           a1: &BotChatterInterface::m_encourageTimer,
           a2: &BotChatterInterface::m_encourageTimer.m_timestamp);
}

//------------------------------------------------------------------------------
// Address: 0x104107B0
// Name: _dynamic_initializer_for__BotChatterInterface::m_radioSilenceInterval__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__BotChatterInterface::m_radioSilenceInterval__()
{
  int v0; // edi
  IPredictionSystem **p_m_pNextSystem; // esi
  IPredictionSystem *m_pNextSystem; // edx
  int result; // eax

  v0 = 1;
  p_m_pNextSystem = &BotChatterInterface::m_radioSilenceInterval.m_pNextSystem;
  do
  {
    *(p_m_pNextSystem - 1) = (IPredictionSystem *)&IntervalTimer::`vftable';
    m_pNextSystem = (*(p_m_pNextSystem - 1))->m_pNextSystem;
    *p_m_pNextSystem = (IPredictionSystem *)-1082130432;
    result = ((int (__stdcall *)(IPredictionSystem **))m_pNextSystem)(a1: p_m_pNextSystem);
    p_m_pNextSystem += 2;
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A9110
// Name: __CreateCServerGameTagsIServerGameTags_interface_14
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_14()
{
  return &_g_CServerGameTags_singleton_14;
}

//------------------------------------------------------------------------------
// Address: 0x102A9F70
// Name: bool NavAreaBuildPath<class PathCost>(class CNavArea __near *,class CNavArea __near *,class Vector const __near *,class PathCost __near &,class CNavArea __near * __near *,float,int,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl NavAreaBuildPath<PathCost>(
        CNavArea *startArea,
        CNavArea *goalArea,
        const Vector *goalPos,
        PathCost *costFunc,
        CNavArea **closestArea,
        float maxPathLength,
        int teamID,
        BOOL ignoreNavBlockers)
{
  int v8; // ecx
  CNavArea *v9; // edi
  const Vector *p_m_center; // eax
  float v12; // xmm0_4
  int TeamNumber; // eax
  double v14; // st7
  CNavArea *v15; // esi
  int v16; // edi
  const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v17; // ecx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v19; // eax
  unsigned int id; // esi
  float v21; // xmm0_4
  const CNavLadder *v22; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v23; // eax
  double v24; // st7
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  double v28; // xmm0_8
  float v29; // xmm0_4
  int v30; // eax
  __int64 v31; // [esp+70h] [ebp-48h]
  float z; // [esp+78h] [ebp-40h]
  float actualGoalPos; // [esp+7Ch] [ebp-3Ch]
  float actualGoalPosb; // [esp+7Ch] [ebp-3Ch]
  float actualGoalPosa; // [esp+7Ch] [ebp-3Ch]
  const CFuncElevator *actualGoalPos_4; // [esp+80h] [ebp-38h]
  float actualGoalPos_4a; // [esp+80h] [ebp-38h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *actualGoalPos_8; // [esp+84h] [ebp-34h]
  const CNavLadder *initCost; // [esp+88h] [ebp-30h]
  const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *floorList; // [esp+90h] [ebp-28h]
  int ladder; // [esp+94h] [ebp-24h]
  int length; // [esp+98h] [ebp-20h]
  int ladderList; // [esp+9Ch] [ebp-1Ch]
  NavAreaBuildPath::__l31::SearchType searchWhere; // [esp+A0h] [ebp-18h]
  CNavArea *dir; // [esp+A4h] [ebp-14h]
  bool ladderTopDir_2; // [esp+AAh] [ebp-Eh]
  char ladderTopDir_3; // [esp+ABh] [ebp-Dh]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "NavAreaBuildPath",
    a3: 0,
    a4: "NextBotSpiky",
    a5: false,
    a6: 4);
  if ( closestArea != nullptr )
    *closestArea = startArea;
  v8 = g_DebugPathfindCounter--;
  ladderTopDir_2 = v8 > 0;
  if ( startArea == nullptr )
    goto LABEL_8;
  v9 = goalArea;
  if ( goalArea != nullptr )
  {
    if ( !goalArea->IsBlocked(this: goalArea, a2: teamID, a3: ignoreNavBlockers) )
    {
      p_m_center = goalPos;
      goto LABEL_10;
    }
    v9 = nullptr;
    goalArea = nullptr;
  }
  p_m_center = goalPos;
  if ( goalPos == nullptr )
  {
LABEL_8:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
LABEL_10:
  startArea->m_parent = nullptr;
  startArea->m_parentHow = NUM_TRAVERSE_TYPES;
  if ( startArea == v9 )
  {
    v9->m_parent = nullptr;
    v9->m_parentHow = NUM_TRAVERSE_TYPES;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  if ( p_m_center == nullptr )
    p_m_center = &v9->m_center;
  v31 = *(_QWORD *)&p_m_center->x;
  z = p_m_center->z;
  CNavArea::ClearSearchLists();
  startArea->m_totalCost = fsqrt(
                             (float)((float)((float)(startArea->m_center.y - *((float *)&v31 + 1))
                                           * (float)(startArea->m_center.y - *((float *)&v31 + 1)))
                                   + (float)((float)(startArea->m_center.z - z) * (float)(startArea->m_center.z - z)))
                           + (float)((float)(startArea->m_center.x - *(float *)&v31)
                                   * (float)(startArea->m_center.x - *(float *)&v31)));
  actualGoalPos = costFunc->m_bot->m_profile->m_aggression;
  if ( costFunc->m_route == FASTEST_ROUTE )
  {
    v12 = 0.0;
  }
  else
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this: costFunc->m_bot);
    v14 = CNavArea::GetDanger(this: startArea, teamID: TeamNumber) * ((1.0 - actualGoalPos * 0.94999999) * 100.0);
    if ( v14 < 0.0 )
      goto LABEL_8;
    actualGoalPosb = v14;
    v12 = actualGoalPosb;
  }
  startArea->m_costSoFar = v12;
  startArea->m_pathLengthSoFar = 0.0;
  CNavArea::AddToOpenList(this: startArea);
  if ( closestArea != nullptr )
    *closestArea = startArea;
  v15 = CNavArea::m_openList;
  actualGoalPosa = startArea->m_totalCost;
  if ( CNavArea::m_openList == nullptr )
    goto LABEL_8;
  while ( 1 )
  {
    CNavArea::RemoveFromOpenList(this: v15);
    v15->m_prevOpen = nullptr;
    v15->m_nextOpen = nullptr;
    if ( ladderTopDir_2 )
      ((void (__thiscall *)(CNavArea *, _DWORD, int, _DWORD, int, int, int, int))v15->DrawFilled)(
        a1: v15,
        a2: 0,
        a3: 255,
        a4: 0,
        a5: 128,
        a6: 1106247680,
        a7: 1,
        a8: 1084227584);
    if ( !v15->IsBlocked(this: v15, a2: teamID, a3: ignoreNavBlockers) )
      break;
LABEL_76:
    v15 = CNavArea::m_openList;
    if ( CNavArea::m_openList == nullptr )
      goto LABEL_8;
  }
  if ( v15 != goalArea && (goalArea != nullptr || goalPos == nullptr || !CNavArea::Contains(this: v15, pos: goalPos)) )
  {
    v16 = 0;
    ladder = 0;
    length = 0;
    actualGoalPos_8 = v15->m_connect;
    ladderTopDir_3 = 1;
    floorList = nullptr;
    ladderList = 0;
LABEL_29:
    v17 = (const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)dir;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            initCost = nullptr;
            actualGoalPos_4 = nullptr;
            if ( ladder != 0 )
              break;
            m_pData = actualGoalPos_8->m_pData;
            if ( v16 < actualGoalPos_8->m_pData->m_Size )
            {
              id = m_pData->m_Elements[v16].id;
              v21 = m_pData->m_Elements[v16++].length;
LABEL_56:
              if ( (const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)id != v17 )
              {
                if ( (*(unsigned __int8 (__thiscall **)(unsigned int, int, BOOL))(*(_DWORD *)id + 68))(
                       a1: id,
                       a2: teamID,
                       a3: ignoreNavBlockers) != 0 )
                  goto LABEL_29;
                v24 = PathCost::operator()(
                        this: costFunc,
                        area: (CNavArea *)id,
                        fromArea: dir,
                        ladder: initCost,
                        elevator: actualGoalPos_4,
                        length: v21);
                if ( v24 < 0.0 )
                  goto LABEL_29;
                if ( maxPathLength > 0.0 )
                {
                  v25 = *(float *)(id + 44) - dir->m_center.x;
                  v26 = dir->m_pathLengthSoFar
                      + fsqrt(
                          (float)((float)((float)(*(float *)(id + 48) - dir->m_center.y)
                                        * (float)(*(float *)(id + 48) - dir->m_center.y))
                                + (float)((float)(*(float *)(id + 52) - dir->m_center.z)
                                        * (float)(*(float *)(id + 52) - dir->m_center.z)))
                        + (float)(v25 * v25));
                  if ( v26 > maxPathLength )
                    goto LABEL_29;
                  *(float *)(id + 128) = v26;
                }
                actualGoalPos_4a = v24;
                if ( (*(_DWORD *)(id + 80) == CNavArea::m_masterMarker
                   || *(_DWORD *)(id + 60) == CNavArea::m_masterMarker)
                  && actualGoalPos_4a >= *(float *)(id + 68) )
                {
                  goto LABEL_29;
                }
                v27 = (float)((float)((float)(*(float *)(id + 48) - *((float *)&v31 + 1))
                                    * (float)(*(float *)(id + 48) - *((float *)&v31 + 1)))
                            + (float)((float)(*(float *)(id + 44) - *(float *)&v31)
                                    * (float)(*(float *)(id + 44) - *(float *)&v31)))
                    + (float)((float)(*(float *)(id + 52) - z) * (float)(*(float *)(id + 52) - z));
                if ( v27 <= 0.0 )
                  v28 = 0.0;
                else
                  v28 = fsqrt(v27);
                v29 = v28;
                if ( closestArea != nullptr && actualGoalPosa > v29 )
                {
                  *closestArea = (CNavArea *)id;
                  actualGoalPosa = v29;
                }
                v30 = *(_DWORD *)(id + 80);
                *(float *)(id + 68) = actualGoalPos_4a;
                *(float *)(id + 64) = v29 + actualGoalPos_4a;
                if ( v30 == CNavArea::m_masterMarker )
                  CNavArea::UpdateOnOpenList(this: (CNavArea *)id);
                else
                  CNavArea::AddToOpenList(this: (CNavArea *)id);
                v17 = (const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)dir;
                *(_DWORD *)(id + 120) = dir;
                *(_DWORD *)(id + 124) = searchWhere;
              }
            }
            else
            {
              v19 = length + 1;
              v16 = 0;
              length = v19;
              if ( v19 == 4 )
              {
                ladder = 1;
                floorList = v17 + 26;
                ladderList = 0;
              }
              else
              {
                actualGoalPos_8 = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)&v17[v19 + 22];
              }
            }
          }
          if ( ladder != 1 )
          {
            actualGoalPos_4 = CNavArea::GetElevator(this: dir);
            if ( actualGoalPos_4 == nullptr || (v23 = dir->m_elevatorAreas.m_pData, v16 >= v23->m_Size) )
            {
              dir->m_marker = CNavArea::m_masterMarker;
              goto LABEL_76;
            }
            id = v23->m_Elements[v16++].id;
            v17 = (const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)dir;
LABEL_55:
            v21 = -1.0;
            goto LABEL_56;
          }
          if ( v16 < floorList->m_pData->m_Size )
            break;
          v16 = 0;
          if ( ladderTopDir_3 != 0 )
          {
            ladderTopDir_3 = 0;
            floorList = v17 + 27;
          }
          else
          {
            ladder = 2;
          }
        }
        v22 = (const CNavLadder *)*(&floorList->m_pData->m_Elements[0].id + v16);
        initCost = v22;
        if ( ladderTopDir_3 == 0 )
        {
          id = (unsigned int)v22->m_bottomArea;
          ++v16;
          goto LABEL_50;
        }
        if ( ladderList != 0 )
          break;
        id = (unsigned int)v22->m_topForwardArea;
        ladderList = 1;
LABEL_50:
        if ( id != 0 )
          goto LABEL_55;
      }
      if ( ladderList == 1 )
      {
        id = (unsigned int)v22->m_topLeftArea;
        ladderList = 2;
        goto LABEL_50;
      }
      if ( ladderList == 2 )
      {
        id = (unsigned int)v22->m_topRightArea;
        ladderList = 3;
        goto LABEL_50;
      }
      ++v16;
      ladderList = 0;
    }
  }
  if ( closestArea != nullptr )
    *closestArea = v15;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102AADA0
// Name: float NavAreaTravelDistance<class PathCost>(class CNavArea __near *,class CNavArea __near *,class PathCost __near &,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl NavAreaTravelDistance<PathCost>(
        CNavArea *startArea,
        CNavArea *endArea,
        PathCost *costFunc,
        float maxPathLength)
{
  CNavArea *v4; // edi
  int v6; // ecx
  float v7; // xmm0_4
  int TeamNumber; // eax
  double v9; // st7
  CNavArea *v10; // esi
  int v11; // edi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v13; // eax
  CNavArea *area; // esi
  float length; // xmm0_4
  const CNavLadder *ladder; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v17; // eax
  double v18; // st7
  float v19; // xmm0_4
  float v20; // xmm0_4
  unsigned int m_openMarker; // eax
  float v22; // xmm0_4
  double v23; // xmm0_8
  CNavArea *m_parent; // eax
  float v25; // xmm3_4
  float *v26; // ecx
  float v27; // xmm0_4
  float v28; // xmm1_4
  float m_aggression; // [esp+80h] [ebp-38h]
  float v31; // [esp+80h] [ebp-38h]
  const CFuncElevator *Elevator; // [esp+80h] [ebp-38h]
  float v33; // [esp+80h] [ebp-38h]
  float v34; // [esp+80h] [ebp-38h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // [esp+84h] [ebp-34h]
  const CNavLadder *v36; // [esp+88h] [ebp-30h]
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *m_ladder; // [esp+90h] [ebp-28h]
  int v38; // [esp+94h] [ebp-24h]
  int v39; // [esp+98h] [ebp-20h]
  int v40; // [esp+9Ch] [ebp-1Ch]
  int v41; // [esp+A0h] [ebp-18h]
  CNavArea *v42; // [esp+A4h] [ebp-14h]
  bool v43; // [esp+AAh] [ebp-Eh]
  char v44; // [esp+ABh] [ebp-Dh]
  Vector m_center; // 0:^74.12

  if ( startArea == nullptr )
    return -1.0;
  v4 = endArea;
  if ( endArea == nullptr )
    return -1.0;
  if ( startArea == endArea )
    return 0.0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "NavAreaBuildPath",
    a3: 0,
    a4: "NextBotSpiky",
    a5: false,
    a6: 4);
  v6 = g_DebugPathfindCounter--;
  v43 = v6 > 0;
  if ( endArea->IsBlocked(this: endArea, a2: -1, a3: false) )
    goto LABEL_62;
  startArea->m_parent = nullptr;
  startArea->m_parentHow = NUM_TRAVERSE_TYPES;
  m_center = endArea->m_center;
  CNavArea::ClearSearchLists();
  startArea->m_totalCost = fsqrt(
                             (float)((float)((float)(startArea->m_center.x - m_center.x)
                                           * (float)(startArea->m_center.x - m_center.x))
                                   + (float)((float)(startArea->m_center.y - m_center.y)
                                           * (float)(startArea->m_center.y - m_center.y)))
                           + (float)((float)(startArea->m_center.z - m_center.z)
                                   * (float)(startArea->m_center.z - m_center.z)));
  m_aggression = costFunc->m_bot->m_profile->m_aggression;
  if ( costFunc->m_route == FASTEST_ROUTE )
  {
    v7 = 0.0;
    goto LABEL_10;
  }
  TeamNumber = CBaseEntity::GetTeamNumber(this: costFunc->m_bot);
  v9 = CNavArea::GetDanger(this: startArea, teamID: TeamNumber) * ((1.0 - m_aggression * 0.94999999) * 100.0);
  if ( v9 < 0.0 )
  {
LABEL_62:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return -1.0;
  }
  v31 = v9;
  v7 = v31;
LABEL_10:
  startArea->m_costSoFar = v7;
  startArea->m_pathLengthSoFar = 0.0;
  CNavArea::AddToOpenList(this: startArea);
  v10 = CNavArea::m_openList;
  if ( CNavArea::m_openList == nullptr )
    goto LABEL_62;
  while ( 1 )
  {
    CNavArea::RemoveFromOpenList(this: v10);
    v10->m_prevOpen = nullptr;
    v10->m_nextOpen = nullptr;
    v42 = v10;
    if ( v43 )
      ((void (__thiscall *)(CNavArea *, _DWORD, int, _DWORD, int, int, int, int))v10->DrawFilled)(
        a1: v10,
        a2: 0,
        a3: 255,
        a4: 0,
        a5: 128,
        a6: 1106247680,
        a7: 1,
        a8: 1084227584);
    if ( !v10->IsBlocked(this: v10, a2: -1, a3: false) )
      break;
LABEL_61:
    v10 = CNavArea::m_openList;
    if ( CNavArea::m_openList == nullptr )
      goto LABEL_62;
  }
  if ( v10 != v4 )
  {
    m_connect = v10->m_connect;
    v11 = 0;
    v38 = 0;
    v39 = 0;
    v44 = 1;
    m_ladder = nullptr;
    v41 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v36 = nullptr;
        Elevator = nullptr;
        if ( v38 != 0 )
          break;
        m_pData = m_connect->m_pData;
        if ( v11 < m_connect->m_pData->m_Size )
        {
          area = m_pData->m_Elements[v11].area;
          length = m_pData->m_Elements[v11].length;
          v40 = v39;
          ++v11;
LABEL_44:
          if ( area != v42 && !area->IsBlocked(this: area, a2: -1, a3: false) )
          {
            v18 = PathCost::operator()(this: costFunc, area, fromArea: v42, ladder: v36, elevator: Elevator, length);
            if ( v18 >= 0.0 )
            {
              if ( maxPathLength > 0.0 )
              {
                v19 = area->m_center.x - v42->m_center.x;
                v20 = v42->m_pathLengthSoFar
                    + fsqrt(
                        (float)((float)((float)(area->m_center.y - v42->m_center.y)
                                      * (float)(area->m_center.y - v42->m_center.y))
                              + (float)((float)(area->m_center.z - v42->m_center.z)
                                      * (float)(area->m_center.z - v42->m_center.z)))
                      + (float)(v19 * v19));
                if ( v20 > maxPathLength )
                  goto LABEL_16;
                area->m_pathLengthSoFar = v20;
              }
              m_openMarker = area->m_openMarker;
              v33 = v18;
              if ( m_openMarker != CNavArea::m_masterMarker && area->m_marker != CNavArea::m_masterMarker
                || v33 < area->m_costSoFar )
              {
                v22 = (float)((float)((float)(area->m_center.y - m_center.y) * (float)(area->m_center.y - m_center.y))
                            + (float)((float)(area->m_center.x - m_center.x) * (float)(area->m_center.x - m_center.x)))
                    + (float)((float)(area->m_center.z - m_center.z) * (float)(area->m_center.z - m_center.z));
                if ( v22 <= 0.0 )
                  v23 = 0.0;
                else
                  v23 = fsqrt(v22);
                area->m_costSoFar = v33;
                area->m_totalCost = (float)v23 + v33;
                if ( m_openMarker == CNavArea::m_masterMarker )
                  CNavArea::UpdateOnOpenList(this: area);
                else
                  CNavArea::AddToOpenList(this: area);
                area->m_parent = v42;
                area->m_parentHow = v40;
              }
            }
          }
LABEL_16:
          v10 = v42;
        }
        else
        {
          v13 = v39 + 1;
          v11 = 0;
          v39 = v13;
          if ( v13 == 4 )
          {
            v38 = 1;
            m_ladder = v10->m_ladder;
            v41 = 0;
          }
          else
          {
            m_connect = &v10->m_connect[v13];
          }
        }
      }
      if ( v38 != 1 )
        break;
      if ( v11 < m_ladder->m_pData->m_Size )
      {
        ladder = m_ladder->m_pData->m_Elements[v11].ladder;
        v36 = ladder;
        if ( v44 == 0 )
        {
          area = ladder->m_bottomArea;
          v40 = 5;
          ++v11;
          goto LABEL_37;
        }
        switch ( v41 )
        {
          case 0:
            area = ladder->m_topForwardArea;
            v41 = 1;
            v40 = 4;
LABEL_37:
            if ( area == nullptr )
              goto LABEL_16;
LABEL_43:
            length = -1.0;
            goto LABEL_44;
          case 1:
            area = ladder->m_topLeftArea;
            v41 = 2;
            v40 = 4;
            goto LABEL_37;
          case 2:
            area = ladder->m_topRightArea;
            v41 = 3;
            v40 = 4;
            goto LABEL_37;
          default:
            break;
        }
        ++v11;
        v41 = 0;
      }
      else
      {
        v11 = 0;
        if ( v44 != 0 )
        {
          v44 = 0;
          m_ladder = &v10->m_ladder[1];
        }
        else
        {
          v38 = 2;
        }
      }
    }
    Elevator = CNavArea::GetElevator(this: v10);
    if ( Elevator == nullptr || (v17 = v10->m_elevatorAreas.m_pData, v11 >= v17->m_Size) )
    {
      v4 = endArea;
      v10->m_marker = CNavArea::m_masterMarker;
      goto LABEL_61;
    }
    area = v17->m_Elements[v11++].area;
    v40 = 7;
    if ( area->m_center.z <= v42->m_center.z )
      v40 = 8;
    goto LABEL_43;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  m_parent = v4->m_parent;
  v25 = 0.0;
  v34 = 0.0;
  v26 = (float *)v4;
  if ( m_parent != nullptr )
  {
    do
    {
      v27 = v26[11] - m_parent->m_center.x;
      v28 = (float)((float)((float)(v26[12] - m_parent->m_center.y) * (float)(v26[12] - m_parent->m_center.y))
                  + (float)((float)(v26[13] - m_parent->m_center.z) * (float)(v26[13] - m_parent->m_center.z)))
          + (float)(v27 * v27);
      v26 = (float *)m_parent;
      m_parent = m_parent->m_parent;
      v25 = v25 + fsqrt(v28);
    }
    while ( m_parent != nullptr );
    return v25;
  }
  return v34;
}

//------------------------------------------------------------------------------
// Address: 0x102AEE40
// Name: __CreateCServerGameTagsIServerGameTags_interface_15
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_15()
{
  return &_g_CServerGameTags_singleton_15;
}

//------------------------------------------------------------------------------
// Address: 0x104107F0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___15
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___15()
{
  return InterfaceReg::InterfaceReg(
           this: (InterfaceReg *)&BotChatterInterface::m_radioSilenceInterval.m_nStatusPushed,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_15,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10410810
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___16()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_16,
           fn: _CreateCServerGameTagsIServerGameTags_interface_16,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10410830
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___17
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___17()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_17,
           fn: _CreateCServerGameTagsIServerGameTags_interface_17,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10410850
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___18
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___18()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_18,
           fn: _CreateCServerGameTagsIServerGameTags_interface_18,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10410870
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___19
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___19()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_19,
           fn: _CreateCServerGameTagsIServerGameTags_interface_19,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10410890
// Name: _dynamic_initializer_for__cv_bot_traceview__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_traceview__()
{
  ConVar::ConVar(
    this: &cv_bot_traceview,
    pName: "bot_traceview",
    pDefaultValue: "0",
    flags: 24576,
    pHelpString: "For internal testing purposes.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_traceview__);
}

//------------------------------------------------------------------------------
// Address: 0x104108C0
// Name: _dynamic_initializer_for__cv_bot_stop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_stop__()
{
  ConVar::ConVar(
    this: &cv_bot_stop,
    pName: "bot_stop",
    pDefaultValue: "0",
    flags: 24576,
    pHelpString: "If nonzero, immediately stops all bot processing.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_stop__);
}

//------------------------------------------------------------------------------
// Address: 0x104108F0
// Name: _dynamic_initializer_for__cv_bot_show_nav__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_show_nav__()
{
  ConVar::ConVar(
    this: &cv_bot_show_nav,
    pName: "bot_show_nav",
    pDefaultValue: "0",
    flags: 24576,
    pHelpString: "For internal testing purposes.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_show_nav__);
}

//------------------------------------------------------------------------------
// Address: 0x10410920
// Name: _dynamic_initializer_for__cv_bot_walk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_walk__()
{
  ConVar::ConVar(
    this: &cv_bot_walk,
    pName: "bot_walk",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "If nonzero, bots can only walk, not run.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_walk__);
}

//------------------------------------------------------------------------------
// Address: 0x10410950
// Name: _dynamic_initializer_for__cv_bot_difficulty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_difficulty__()
{
  ConVar::ConVar(
    this: &cv_bot_difficulty,
    pName: "bot_difficulty",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Defines the skill of bots joining the game.  Values are: 0=easy, 1=normal, 2=hard, 3=expert.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_difficulty__);
}

//------------------------------------------------------------------------------
// Address: 0x10410980
// Name: _dynamic_initializer_for__cv_bot_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_debug__()
{
  ConVar::ConVar(
    this: &cv_bot_debug,
    pName: "bot_debug",
    pDefaultValue: "0",
    flags: 24576,
    pHelpString: "For internal testing purposes.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x104109B0
// Name: _dynamic_initializer_for__cv_bot_debug_target__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_debug_target__()
{
  ConVar::ConVar(
    this: &cv_bot_debug_target,
    pName: "bot_debug_target",
    pDefaultValue: "0",
    flags: 24576,
    pHelpString: "For internal testing purposes.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_debug_target__);
}

//------------------------------------------------------------------------------
// Address: 0x104109E0
// Name: _dynamic_initializer_for__cv_bot_quota__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_quota__()
{
  ConVar::ConVar(
    this: &cv_bot_quota,
    pName: "bot_quota",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Determines the total number of bots in the game.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_quota__);
}

//------------------------------------------------------------------------------
// Address: 0x10410A10
// Name: _dynamic_initializer_for__cv_bot_quota_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_quota_mode__()
{
  ConVar::ConVar(
    this: &cv_bot_quota_mode,
    pName: "bot_quota_mode",
    pDefaultValue: "normal",
    flags: 0x2000,
    pHelpString: "Determines the type of quota.\n"
    "Allowed values: 'normal', 'fill', and 'match'.\n"
    "If 'fill', the server will adjust bots to keep N players in the game, where N is bot_quota.\n"
    "If 'match', the server will maintain a 1:N ratio of humans to bots, where N is bot_quota.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_quota_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10410A40
// Name: _dynamic_initializer_for__cv_bot_prefix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_prefix__()
{
  ConVar::ConVar(
    this: &cv_bot_prefix,
    pName: "bot_prefix",
    pDefaultValue: locale,
    flags: 0x2000,
    pHelpString: "This string is prefixed to the name of all bots that join the game.\n"
    "<difficulty> will be replaced with the bot's difficulty.\n"
    "<weaponclass> will be replaced with the bot's desired weapon class.\n"
    "<skill> will be replaced with a 0-100 representation of the bot's skill.",
    callback: PrefixChanged);
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_prefix__);
}

//------------------------------------------------------------------------------
// Address: 0x10410A70
// Name: _dynamic_initializer_for__cv_bot_allow_rogues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_allow_rogues__()
{
  ConVar::ConVar(
    this: &cv_bot_allow_rogues,
    pName: "bot_allow_rogues",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "If nonzero, bots may occasionally go 'rogue'. Rogue bots do not obey radio commands, nor pursue scenario goals.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_allow_rogues__);
}

//------------------------------------------------------------------------------
// Address: 0x10410AA0
// Name: _dynamic_initializer_for__cv_bot_allow_pistols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_allow_pistols__()
{
  ConVar::ConVar(
    this: &cv_bot_allow_pistols,
    pName: "bot_allow_pistols",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "If nonzero, bots may use pistols.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_allow_pistols__);
}

//------------------------------------------------------------------------------
// Address: 0x10410AD0
// Name: _dynamic_initializer_for__cv_bot_allow_shotguns__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_allow_shotguns__()
{
  ConVar::ConVar(
    this: &cv_bot_allow_shotguns,
    pName: "bot_allow_shotguns",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "If nonzero, bots may use shotguns.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_allow_shotguns__);
}

//------------------------------------------------------------------------------
// Address: 0x10410B00
// Name: _dynamic_initializer_for__cv_bot_allow_sub_machine_guns__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_allow_sub_machine_guns__()
{
  ConVar::ConVar(
    this: &cv_bot_allow_sub_machine_guns,
    pName: "bot_allow_sub_machine_guns",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "If nonzero, bots may use sub-machine guns.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_allow_sub_machine_guns__);
}

//------------------------------------------------------------------------------
// Address: 0x10410B30
// Name: _dynamic_initializer_for__cv_bot_allow_rifles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_allow_rifles__()
{
  ConVar::ConVar(
    this: &cv_bot_allow_rifles,
    pName: "bot_allow_rifles",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "If nonzero, bots may use rifles.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_allow_rifles__);
}

//------------------------------------------------------------------------------
// Address: 0x10410B60
// Name: _dynamic_initializer_for__cv_bot_allow_machine_guns__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_allow_machine_guns__()
{
  ConVar::ConVar(
    this: &cv_bot_allow_machine_guns,
    pName: "bot_allow_machine_guns",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "If nonzero, bots may use the machine gun.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_allow_machine_guns__);
}

//------------------------------------------------------------------------------
// Address: 0x10410B90
// Name: _dynamic_initializer_for__cv_bot_allow_grenades__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_allow_grenades__()
{
  ConVar::ConVar(
    this: &cv_bot_allow_grenades,
    pName: "bot_allow_grenades",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "If nonzero, bots may use grenades.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_allow_grenades__);
}

//------------------------------------------------------------------------------
// Address: 0x10410BC0
// Name: _dynamic_initializer_for__cv_bot_allow_snipers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_allow_snipers__()
{
  ConVar::ConVar(
    this: &cv_bot_allow_snipers,
    pName: "bot_allow_snipers",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "If nonzero, bots may use sniper rifles.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_allow_snipers__);
}

//------------------------------------------------------------------------------
// Address: 0x10410BF0
// Name: _dynamic_initializer_for__cv_bot_join_team__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_join_team__()
{
  ConVar::ConVar(
    this: &cv_bot_join_team,
    pName: "bot_join_team",
    pDefaultValue: "any",
    flags: 0x2000,
    pHelpString: "Determines the team bots will join into. Allowed values: 'any', 'T', or 'CT'.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_join_team__);
}

//------------------------------------------------------------------------------
// Address: 0x10410C20
// Name: _dynamic_initializer_for__cv_bot_join_after_player__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_join_after_player__()
{
  ConVar::ConVar(
    this: &cv_bot_join_after_player,
    pName: "bot_join_after_player",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "If nonzero, bots wait until a player joins before entering the game.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_join_after_player__);
}

//------------------------------------------------------------------------------
// Address: 0x10410C50
// Name: _dynamic_initializer_for__cv_bot_auto_vacate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_auto_vacate__()
{
  ConVar::ConVar(
    this: &cv_bot_auto_vacate,
    pName: "bot_auto_vacate",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "If nonzero, bots will automatically leave to make room for human players.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_auto_vacate__);
}

//------------------------------------------------------------------------------
// Address: 0x10410C80
// Name: _dynamic_initializer_for__cv_bot_zombie__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_zombie__()
{
  ConVar::ConVar(
    this: &cv_bot_zombie,
    pName: "bot_zombie",
    pDefaultValue: "0",
    flags: 24576,
    pHelpString: "If nonzero, bots will stay in idle mode and not attack.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_zombie__);
}

//------------------------------------------------------------------------------
// Address: 0x10410CB0
// Name: _dynamic_initializer_for__cv_bot_defer_to_human__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_defer_to_human__()
{
  ConVar::ConVar(
    this: &cv_bot_defer_to_human,
    pName: "bot_defer_to_human",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "If nonzero and there is a human on the team, the bots will not do the scenario tasks.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_defer_to_human__);
}

//------------------------------------------------------------------------------
// Address: 0x10410CE0
// Name: _dynamic_initializer_for__cv_bot_chatter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_chatter__()
{
  ConVar::ConVar(
    this: &cv_bot_chatter,
    pName: "bot_chatter",
    pDefaultValue: "normal",
    flags: 0x2000,
    pHelpString: "Control how bots talk. Allowed values: 'off', 'radio', 'minimal', or 'normal'.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_chatter__);
}

//------------------------------------------------------------------------------
// Address: 0x10410D10
// Name: _dynamic_initializer_for__cv_bot_profile_db__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_profile_db__()
{
  ConVar::ConVar(
    this: &cv_bot_profile_db,
    pName: "bot_profile_db",
    pDefaultValue: "BotProfile.db",
    flags: 0x2000,
    pHelpString: "The filename from which bot profiles will be read.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_profile_db__);
}

//------------------------------------------------------------------------------
// Address: 0x10410D40
// Name: _dynamic_initializer_for__cv_bot_dont_shoot__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_dont_shoot__()
{
  ConVar::ConVar(
    this: &cv_bot_dont_shoot,
    pName: "bot_dont_shoot",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "If nonzero, bots will not fire weapons (for debugging).");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_dont_shoot__);
}

//------------------------------------------------------------------------------
// Address: 0x10410D70
// Name: _dynamic_initializer_for__cv_bot_eco_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_eco_limit__()
{
  ConVar::ConVar(
    this: &cv_bot_eco_limit,
    pName: "bot_eco_limit",
    pDefaultValue: "2000",
    flags: 0x2000,
    pHelpString: "If nonzero, bots will not buy if their money falls below this amount.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_eco_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x10410DA0
// Name: _dynamic_initializer_for__cv_bot_auto_follow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_auto_follow__()
{
  ConVar::ConVar(
    this: &cv_bot_auto_follow,
    pName: "bot_auto_follow",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "If nonzero, bots with high co-op may automatically follow a nearby human player.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_auto_follow__);
}

//------------------------------------------------------------------------------
// Address: 0x10410DD0
// Name: _dynamic_initializer_for__cv_bot_flipout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_flipout__()
{
  ConVar::ConVar(
    this: &cv_bot_flipout,
    pName: "bot_flipout",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "If nonzero, bots use no CPU for AI. Instead, they run around randomly.");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_flipout__);
}

//------------------------------------------------------------------------------
// Address: 0x10410E00
// Name: _dynamic_initializer_for__cv_bot_controllable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_bot_controllable__()
{
  ConVar::ConVar(
    this: &cv_bot_controllable,
    pName: "bot_controllable",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Determines whether bots can be controlled by players");
  return atexit(func: dynamic_atexit_destructor_for__cv_bot_controllable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410E30
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___20()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_20,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_20,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10410E50
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___21
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___21()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_21,
           fn: _CreateCServerGameTagsIServerGameTags_interface_21,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10410E70
// Name: _dynamic_initializer_for__bot_show_occupy_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_show_occupy_time__()
{
  ConVar::ConVar(
    this: &bot_show_occupy_time,
    pName: "bot_show_occupy_time",
    pDefaultValue: "0",
    flags: 16388,
    pHelpString: "Show when each nav area can first be reached by each team.");
  return atexit(func: dynamic_atexit_destructor_for__bot_show_occupy_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10410EA0
// Name: _dynamic_initializer_for__bot_show_battlefront__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_show_battlefront__()
{
  ConVar::ConVar(
    this: &bot_show_battlefront,
    pName: "bot_show_battlefront",
    pDefaultValue: "0",
    flags: 16388,
    pHelpString: "Show areas where rushing players will initially meet.");
  return atexit(func: dynamic_atexit_destructor_for__bot_show_battlefront__);
}

//------------------------------------------------------------------------------
// Address: 0x10410ED0
// Name: _dynamic_initializer_for__bot_join_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_join_delay__()
{
  ConVar::ConVar(
    this: &bot_join_delay,
    pName: "bot_join_delay",
    pDefaultValue: "0",
    flags: 4,
    pHelpString: "Prevents bots from joining the server for this many seconds after a map change.");
  return atexit(func: dynamic_atexit_destructor_for__bot_join_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10410F00
// Name: _dynamic_initializer_for__bot_add_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_add_command__()
{
  ConCommand::ConCommand(
    this: &bot_add_command,
    pName: "bot_add",
    callback: (void (__cdecl *)())bot_add,
    pHelpString: "bot_add <t|ct> <type> <difficulty> <name> - Adds a bot matching the given criteria.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_add_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10410F30
// Name: _dynamic_initializer_for__bot_add_t_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_add_t_command__()
{
  ConCommand::ConCommand(
    this: &bot_add_t_command,
    pName: "bot_add_t",
    callback: (void (__cdecl *)())bot_add_t,
    pHelpString: "bot_add_t <type> <difficulty> <name> - Adds a terrorist bot matching the given criteria.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_add_t_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10410F60
// Name: _dynamic_initializer_for__bot_add_ct_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_add_ct_command__()
{
  ConCommand::ConCommand(
    this: &bot_add_ct_command,
    pName: "bot_add_ct",
    callback: (void (__cdecl *)())bot_add_ct,
    pHelpString: "bot_add_ct <type> <difficulty> <name> - Adds a Counter-Terrorist bot matching the given criteria.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_add_ct_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10410F90
// Name: _dynamic_initializer_for__bot_kill_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_kill_command__()
{
  ConCommand::ConCommand(
    this: &bot_kill_command,
    pName: "bot_kill",
    callback: (void (__cdecl *)())bot_kill,
    pHelpString: "bot_kill <all> <t|ct> <type> <difficulty> <name> - Kills a specific bot, or all bots, matching the given criteria.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_kill_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10410FC0
// Name: _dynamic_initializer_for__bot_kick_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_kick_command__()
{
  ConCommand::ConCommand(
    this: &bot_kick_command,
    pName: "bot_kick",
    callback: (void (__cdecl *)())bot_kick,
    pHelpString: "bot_kick <all> <t|ct> <type> <difficulty> <name> - Kicks a specific bot, or all bots, matching the given criteria.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_kick_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10411000
// Name: _dynamic_initializer_for__bot_knives_only_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_knives_only_command__()
{
  ConCommand::ConCommand(
    this: &bot_knives_only_command,
    pName: "bot_knives_only",
    callback: (void (__cdecl *)())bot_knives_only,
    pHelpString: "Restricts the bots to only using knives",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_knives_only_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10411030
// Name: _dynamic_initializer_for__bot_pistols_only_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_pistols_only_command__()
{
  ConCommand::ConCommand(
    this: &bot_pistols_only_command,
    pName: "bot_pistols_only",
    callback: (void (__cdecl *)())bot_pistols_only,
    pHelpString: "Restricts the bots to only using pistols",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_pistols_only_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10411060
// Name: _dynamic_initializer_for__bot_snipers_only_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_snipers_only_command__()
{
  ConCommand::ConCommand(
    this: &bot_snipers_only_command,
    pName: "bot_snipers_only",
    callback: (void (__cdecl *)())bot_snipers_only,
    pHelpString: "Restricts the bots to only using sniper rifles",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_snipers_only_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10411090
// Name: _dynamic_initializer_for__bot_all_weapons_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_all_weapons_command__()
{
  ConCommand::ConCommand(
    this: &bot_all_weapons_command,
    pName: "bot_all_weapons",
    callback: (void (__cdecl *)())bot_all_weapons,
    pHelpString: "Allows the bots to use all weapons",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_all_weapons_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104110C0
// Name: _dynamic_initializer_for__bot_goto_mark_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_goto_mark_command__()
{
  ConCommand::ConCommand(
    this: &bot_goto_mark_command,
    pName: "bot_goto_mark",
    callback: (void (__cdecl *)())bot_goto_mark,
    pHelpString: "Sends a bot to the marked nav area (useful for testing navigation meshes)",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_goto_mark_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104110F0
// Name: _dynamic_initializer_for__bot_goto_selected_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_goto_selected_command__()
{
  ConCommand::ConCommand(
    this: &bot_goto_selected_command,
    pName: "bot_goto_selected",
    callback: (void (__cdecl *)())bot_goto_selected,
    pHelpString: "Sends a bot to the selected nav area (useful for testing navigation meshes)",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_goto_selected_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10411120
// Name: _dynamic_initializer_for__nav_check_connectivity_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_check_connectivity_command__()
{
  ConCommand::ConCommand(
    this: &nav_check_connectivity_command,
    pName: "nav_check_connectivity",
    callback: (void (__cdecl *)())nav_check_connectivity,
    pHelpString: "Checks to be sure every (or just the marked) nav area can get to every goal area for the map (hostages or bomb site).",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_check_connectivity_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10411150
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___22
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___22()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_22,
           fn: _CreateCServerGameTagsIServerGameTags_interface_22,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411170
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___23
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___23()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_23,
           fn: _CreateCServerGameTagsIServerGameTags_interface_23,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411190
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___24
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___24()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_24,
           fn: _CreateCServerGameTagsIServerGameTags_interface_24,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104111B0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___25
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___25()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_25,
           fn: _CreateCServerGameTagsIServerGameTags_interface_25,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104111D0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___26
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___26()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_26,
           fn: _CreateCServerGameTagsIServerGameTags_interface_26,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104111F0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___27
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___27()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_27,
           fn: _CreateCServerGameTagsIServerGameTags_interface_27,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411210
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___28
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___28()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_28,
           fn: _CreateCServerGameTagsIServerGameTags_interface_28,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411230
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___29
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___29()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_29,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_29,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411250
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___30()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_30,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_30,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411270
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___31
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___31()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_31,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_31,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411290
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___32()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_32,
           fn: _CreateCServerGameTagsIServerGameTags_interface_32,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104112B0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___33
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___33()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_33,
           fn: _CreateCServerGameTagsIServerGameTags_interface_33,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104112D0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___34
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___34()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_34,
           fn: _CreateCServerGameTagsIServerGameTags_interface_34,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104112F0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___35
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___35()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_35,
           fn: _CreateCServerGameTagsIServerGameTags_interface_35,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411310
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___36
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___36()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_36,
           fn: _CreateCServerGameTagsIServerGameTags_interface_36,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411330
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___37
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___37()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_37,
           fn: _CreateCServerGameTagsIServerGameTags_interface_37,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411350
// Name: _dynamic_initializer_for__bot_loadout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_loadout__()
{
  ConVar::ConVar(
    this: &bot_loadout,
    pName: "bot_loadout",
    pDefaultValue: locale,
    flags: 0x4000,
    pHelpString: "bots are given these items at round start");
  return atexit(func: dynamic_atexit_destructor_for__bot_loadout__);
}

//------------------------------------------------------------------------------
// Address: 0x10411380
// Name: _dynamic_initializer_for__bot_randombuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_randombuy__()
{
  ConVar::ConVar(
    this: &bot_randombuy,
    pName: "bot_randombuy",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "should bots ignore their prefered weapons and just buy weapons at random?");
  return atexit(func: dynamic_atexit_destructor_for__bot_randombuy__);
}

//------------------------------------------------------------------------------
// Address: 0x104113B0
// Name: _dynamic_initializer_for__bot_gungameselect_weapons_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_gungameselect_weapons_t__()
{
  ConVar::ConVar(
    this: &bot_gungameselect_weapons_t,
    pName: "bot_gungameselect_weapons_t",
    pDefaultValue: "deagle awp p90 ak47 sg556",
    flags: 0,
    pHelpString: "the list of weapons that T bots start with in gun game select");
  return atexit(func: dynamic_atexit_destructor_for__bot_gungameselect_weapons_t__);
}

//------------------------------------------------------------------------------
// Address: 0x104113E0
// Name: _dynamic_initializer_for__bot_gungameselect_weapons_ct__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_gungameselect_weapons_ct__()
{
  ConVar::ConVar(
    this: &bot_gungameselect_weapons_ct,
    pName: "bot_gungameselect_weapons_ct",
    pDefaultValue: "deagle awp p90 aug m4a1",
    flags: 0,
    pHelpString: "the list of weapons that CT bots start with in gun game select");
  return atexit(func: dynamic_atexit_destructor_for__bot_gungameselect_weapons_ct__);
}

//------------------------------------------------------------------------------
// Address: 0x10411410
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___38
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___38()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_38,
           fn: _CreateCServerGameTagsIServerGameTags_interface_38,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411430
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___39
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___39()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_39,
           fn: _CreateCServerGameTagsIServerGameTags_interface_39,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411450
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___40()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_40,
           fn: _CreateCServerGameTagsIServerGameTags_interface_40,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411470
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___41
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___41()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_41,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_41,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411490
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___42
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___42()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_42,
           fn: _CreateCServerGameTagsIServerGameTags_interface_42,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104114B0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___43
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___43()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_43,
           fn: _CreateCServerGameTagsIServerGameTags_interface_43,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104114D0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___44
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___44()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_44,
           fn: _CreateCServerGameTagsIServerGameTags_interface_44,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104114F0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___45
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___45()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_45,
           fn: _CreateCServerGameTagsIServerGameTags_interface_45,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411510
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___46
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___46()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_46,
           fn: _CreateCServerGameTagsIServerGameTags_interface_46,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411530
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___47
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___47()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_47,
           fn: _CreateCServerGameTagsIServerGameTags_interface_47,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411550
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___48
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___48()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_48,
           fn: _CreateCServerGameTagsIServerGameTags_interface_48,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411570
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___49
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___49()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_49,
           fn: _CreateCServerGameTagsIServerGameTags_interface_49,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411590
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___50()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_50,
           fn: _CreateCServerGameTagsIServerGameTags_interface_50,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104115B0
// Name: _dynamic_initializer_for__g_CInferno_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CInferno_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CInferno_ClassReg,
           pNetworkName: "CInferno",
           pTable: &DT_Inferno::g_SendTable);
}
