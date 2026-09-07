// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/movement.cpp
// Functions: 43
// ============================================================

#include "game\server\movement.h"

//------------------------------------------------------------------------------
// Address: 0x10174200
// Name: void FixupAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixupAngles(QAngle *v)
{
  float i; // xmm1_4
  float j; // xmm1_4
  float k; // xmm1_4

  for ( i = v->x; i < 0.0; i = i + 360.0 )
    ;
  for ( ; i > 360.0; i = i - 360.0 )
    ;
  v->x = i;
  for ( j = v->y; j < 0.0; j = j + 360.0 )
    ;
  for ( ; j > 360.0; j = j - 360.0 )
    ;
  v->y = j;
  for ( k = v->z; k < 0.0; k = k + 360.0 )
    ;
  for ( ; k > 360.0; k = k - 360.0 )
    ;
  v->z = k;
}

//------------------------------------------------------------------------------
// Address: 0x10174290
// Name: protected: virtual struct datamap_t __near * CPathKeyFrame::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPathKeyFrame::GetDataDescMap(CPathKeyFrame *this)
{
  return &CPathKeyFrame::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101742A0
// Name: public: virtual struct datamap_t __near * CBaseMoveBehavior::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseMoveBehavior::GetDataDescMap(CBaseMoveBehavior *this)
{
  return &CBaseMoveBehavior::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101742B0
// Name: public: virtual bool CBaseMoveBehavior::IsMoving(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseMoveBehavior::IsMoving(CBaseMoveBehavior *this)
{
  return this->m_iDirection != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101742C0
// Name: public: void CPathKeyFrame::CalculateFrameDuration(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathKeyFrame::CalculateFrameDuration(CPathKeyFrame *this)
{
  CPathKeyFrame *m_pNextKey; // edx
  float m_flSpeed; // xmm4_4
  float v3; // xmm0_4
  float v4; // xmm6_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float i; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm1_4

  m_pNextKey = this->m_pNextKey;
  if ( m_pNextKey != nullptr )
  {
    m_flSpeed = this->m_flSpeed;
    if ( m_flSpeed > 0.0 )
    {
      v3 = this->m_Origin.x - m_pNextKey->m_Origin.x;
      v4 = 1.0 / m_flSpeed;
      v5 = (float)(1.0 / m_flSpeed)
         * fsqrt(
             (float)((float)((float)(this->m_Origin.y - m_pNextKey->m_Origin.y)
                           * (float)(this->m_Origin.y - m_pNextKey->m_Origin.y))
                   + (float)((float)(this->m_Origin.z - m_pNextKey->m_Origin.z)
                           * (float)(this->m_Origin.z - m_pNextKey->m_Origin.z)))
           + (float)(v3 * v3));
      this->m_flNextTime = v5;
      if ( v5 == 0.0 )
      {
        v6 = this->m_Angles.x - m_pNextKey->m_Angles.x;
        v7 = this->m_Angles.y - m_pNextKey->m_Angles.y;
        for ( i = this->m_Angles.z - m_pNextKey->m_Angles.z; v6 < 0.0; v6 = v6 + 360.0 )
          ;
        for ( ; v6 > 360.0; v6 = v6 - 360.0 )
          ;
        for ( ; v7 < 0.0; v7 = v7 + 360.0 )
          ;
        for ( ; v7 > 360.0; v7 = v7 - 360.0 )
          ;
        for ( ; i < 0.0; i = i + 360.0 )
          ;
        for ( ; i > 360.0; i = i - 360.0 )
          ;
        v9 = fabs(v6);
        v10 = 0.0;
        if ( v9 > 0.0 )
          v10 = v9;
        v11 = fabs(v7);
        if ( v11 > v10 )
          v10 = v11;
        v12 = fabs(i);
        if ( v12 > v10 )
          v10 = v12;
        this->m_flNextTime = v4 * v10;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174450
// Name: public: virtual bool CBaseMoveBehavior::StartMoving(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseMoveBehavior::StartMoving(CBaseMoveBehavior *this, int direction)
{
  int m_iDirection; // eax
  CPathKeyFrame *m_pTargetKeyFrame; // eax
  CPathKeyFrame *m_pNextKey; // ecx
  CPathKeyFrame *m_pCurrentKeyFrame; // eax
  CPathKeyFrame *v8; // ecx
  CPathKeyFrame *m_pPrevKey; // eax
  CPathKeyFrame *v10; // ecx
  CPathKeyFrame *v11; // eax
  CPathKeyFrame *v12; // ecx
  float m_flLocalTime; // xmm4_4
  float m_flTimeIntoFrame; // xmm0_4
  CPathKeyFrame *v15; // eax
  float v16; // xmm3_4
  float m_flNextTime; // xmm1_4
  float v18; // xmm1_4
  CPathKeyFrame *v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float flDelay; // xmm0_4
  float v23; // [esp+14h] [ebp-1Ch]

  if ( direction == 0 )
  {
    this->StopMoving(this);
    return 0;
  }
  m_iDirection = this->m_iDirection;
  if ( m_iDirection == direction )
  {
    if ( this->m_flLocalTime >= this->m_flAnimEndTime )
    {
      m_pTargetKeyFrame = this->m_pTargetKeyFrame;
      this->m_pCurrentKeyFrame = m_pTargetKeyFrame;
      this->m_flTimeIntoFrame = 0.0;
      if ( direction == 1 )
      {
        m_pNextKey = m_pTargetKeyFrame->m_pNextKey;
      }
      else if ( direction == -1 )
      {
        m_pNextKey = m_pTargetKeyFrame->m_pPrevKey;
      }
      else
      {
        m_pNextKey = m_pTargetKeyFrame;
      }
      if ( m_pNextKey == nullptr )
      {
        this->m_flAnimEndTime = 0.0;
        this->m_flAnimStartTime = 0.0;
LABEL_13:
        this->StopMoving(this);
        return 0;
      }
      if ( direction == 1 )
      {
        this->m_pTargetKeyFrame = m_pTargetKeyFrame->m_pNextKey;
      }
      else
      {
        if ( direction == -1 )
          m_pTargetKeyFrame = m_pTargetKeyFrame->m_pPrevKey;
        this->m_pTargetKeyFrame = m_pTargetKeyFrame;
      }
    }
  }
  else
  {
    if ( m_iDirection != 0 )
      this->StopMoving(this);
    this->m_iDirection = direction;
    if ( direction == 1 )
    {
      this->m_pTargetKeyFrame = this->m_pCurrentKeyFrame->m_pNextKey;
    }
    else if ( direction == -1 )
    {
      if ( this->m_flTimeIntoFrame <= 0.0 )
      {
        this->m_pTargetKeyFrame = this->m_pCurrentKeyFrame->m_pPrevKey;
      }
      else
      {
        m_pCurrentKeyFrame = this->m_pCurrentKeyFrame;
        this->m_pTargetKeyFrame = m_pCurrentKeyFrame;
        this->m_pCurrentKeyFrame = m_pCurrentKeyFrame->m_pNextKey;
      }
    }
    v8 = this->m_pTargetKeyFrame;
    if ( v8 == nullptr )
      goto LABEL_13;
    if ( direction == 1 )
    {
      m_pPrevKey = v8->m_pNextKey;
    }
    else if ( direction == -1 )
    {
      m_pPrevKey = v8->m_pPrevKey;
    }
    else
    {
      m_pPrevKey = this->m_pTargetKeyFrame;
    }
    this->m_pPostKeyFrame = m_pPrevKey;
    if ( m_pPrevKey == nullptr )
      this->m_pPostKeyFrame = v8;
    v10 = this->m_pCurrentKeyFrame;
    if ( direction == 1 )
    {
      v11 = v10->m_pPrevKey;
    }
    else if ( direction == -1 )
    {
      v11 = v10->m_pNextKey;
    }
    else
    {
      v11 = this->m_pCurrentKeyFrame;
    }
    this->m_pPreKeyFrame = v11;
    if ( v11 == nullptr )
      this->m_pPreKeyFrame = v10;
  }
  v12 = this->m_pTargetKeyFrame;
  if ( v12 == nullptr )
    return 0;
  if ( this->m_iDirection == 1 )
  {
    m_flLocalTime = this->m_flLocalTime;
    m_flTimeIntoFrame = this->m_flTimeIntoFrame;
    v15 = this->m_pCurrentKeyFrame;
    v16 = m_flLocalTime - m_flTimeIntoFrame;
    this->m_flAnimStartTime = m_flLocalTime - m_flTimeIntoFrame;
    m_flNextTime = v15->m_flNextTime;
  }
  else
  {
    v18 = this->m_flTimeIntoFrame;
    if ( v18 != 0.0 )
      this->m_flTimeIntoFrame = v12->m_flNextTime - v18;
    m_flLocalTime = this->m_flLocalTime;
    m_flTimeIntoFrame = this->m_flTimeIntoFrame;
    v16 = m_flLocalTime - m_flTimeIntoFrame;
    this->m_flAnimStartTime = m_flLocalTime - m_flTimeIntoFrame;
    m_flNextTime = v12->m_flNextTime;
  }
  v19 = this->m_pCurrentKeyFrame;
  this->m_flAnimEndTime = (float)(m_flNextTime + m_flLocalTime) - m_flTimeIntoFrame;
  v20 = v19->m_Origin.x - v12->m_Origin.x;
  v21 = v19->m_Origin.y - v12->m_Origin.y;
  v23 = fsqrt(
          (float)((float)(v21 * v21)
                + (float)((float)(v19->m_Origin.z - v12->m_Origin.z) * (float)(v19->m_Origin.z - v12->m_Origin.z)))
        + (float)(v20 * v20));
  flDelay = this->m_flAnimEndTime - m_flLocalTime;
  this->m_flAverageSpeedAcrossFrame = (float)(this->m_flAnimEndTime - v16) / v23;
  CBaseEntity::SetMoveDoneTime(this, flDelay);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10174750
// Name: public: virtual void CBaseMoveBehavior::StopMoving(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseMoveBehavior::StopMoving(CBaseMoveBehavior *this)
{
  int m_iDirection; // eax
  float m_flLocalTime; // xmm0_4
  float v4; // xmm0_4
  CPathKeyFrame *m_pTargetKeyFrame; // eax
  float v6; // xmm1_4
  float m_flAnimEndTime; // xmm0_4

  m_iDirection = this->m_iDirection;
  this->m_flTimeIntoFrame = 0.0;
  if ( m_iDirection == 1 )
  {
    m_flLocalTime = this->m_flLocalTime;
    if ( this->m_flAnimEndTime > m_flLocalTime )
    {
      v4 = m_flLocalTime - this->m_flAnimStartTime;
LABEL_9:
      this->m_flTimeIntoFrame = v4;
      goto LABEL_10;
    }
    m_pTargetKeyFrame = this->m_pTargetKeyFrame;
    if ( m_pTargetKeyFrame != nullptr )
      this->m_pCurrentKeyFrame = m_pTargetKeyFrame;
  }
  else if ( m_iDirection == -1 )
  {
    v6 = this->m_flLocalTime;
    m_flAnimEndTime = this->m_flAnimEndTime;
    this->m_pCurrentKeyFrame = this->m_pTargetKeyFrame;
    if ( m_flAnimEndTime > v6 )
    {
      v4 = m_flAnimEndTime - v6;
      goto LABEL_9;
    }
  }
LABEL_10:
  CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
  this->m_iDirection = 0;
  this->m_flAnimStartTime = 0.0;
  this->m_flAnimEndTime = 0.0;
  this->m_pTargetKeyFrame = nullptr;
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
}

//------------------------------------------------------------------------------
// Address: 0x10174820
// Name: public: virtual void CBaseMoveBehavior::MoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseMoveBehavior::MoveDone(CBaseMoveBehavior *this)
{
  const char *pszValue; // eax
  int m_iDirection; // edi
  void (__thiscall *m_pfnMoveDone)(CBaseEntity *); // eax

  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( _V_stricmp(s1: pszValue, s2: "move_keyframed") == 0 )
  {
    m_iDirection = this->m_iDirection;
    if ( !this->StartMoving(this, a2: m_iDirection) )
      this->StartMoving(this, a2: -m_iDirection);
  }
  m_pfnMoveDone = this->m_pfnMoveDone;
  if ( m_pfnMoveDone != nullptr )
    m_pfnMoveDone(this);
}

//------------------------------------------------------------------------------
// Address: 0x10174880
// Name: public: virtual void CPathKeyFrame::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathKeyFrame::Spawn(CPathKeyFrame *this)
{
  QAngle *p_m_Angles; // eax
  Quaternion *p_m_qAngle; // ecx
  float z; // edx

  p_m_Angles = &this->m_Angles;
  this->m_Origin.x = this->m_vecOrigin.m_Value.x;
  p_m_qAngle = &this->m_qAngle;
  p_m_qAngle[-2].w = p_m_qAngle[-11].y;
  p_m_qAngle[-1].x = p_m_qAngle[-11].z;
  *p_m_Angles = *(QAngle *)&p_m_qAngle[-11].w;
  z = p_m_Angles->z;
  *(_QWORD *)&p_m_Angles->x = *(_QWORD *)&p_m_Angles->x;
  p_m_Angles->z = z;
  AngleQuaternion(angles: p_m_Angles, outQuat: p_m_qAngle);
}

//------------------------------------------------------------------------------
// Address: 0x10174910
// Name: public: virtual void CPathKeyFrame::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathKeyFrame::Activate(CPathKeyFrame *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  CPathKeyFrame *v4; // eax

  CBaseEntity::Activate(this);
  pszValue = this->m_iNextKey.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v4 = (CPathKeyFrame *)__RTDynamicCast(
                          inptr: EntityByName,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CPathKeyFrame `RTTI Type Descriptor',
                          isReference: 0);
  this->m_pNextKey = v4;
  if ( v4 != nullptr )
    v4->m_pPrevKey = this;
  CPathKeyFrame::CalculateFrameDuration(this);
}

//------------------------------------------------------------------------------
// Address: 0x10174970
// Name: public: virtual void CBaseMoveBehavior::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseMoveBehavior::Spawn(CBaseMoveBehavior *this)
{
  this->m_pCurrentKeyFrame = this;
  this->m_flTimeIntoFrame = 0.0;
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  this->m_Origin = this->m_vecOrigin.m_Value;
  this->m_Angles = this->m_angRotation.m_Value;
  CPathKeyFrame::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x101749E0
// Name: public: virtual void CBaseMoveBehavior::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseMoveBehavior::Activate(CBaseMoveBehavior *this)
{
  const char *pszValue; // eax

  CPathKeyFrame::Activate(this);
  CBaseEntity::SetMoveDoneTime(this, flDelay: 0.5);
  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( _V_stricmp(s1: pszValue, s2: "move_keyframed") == 0 )
    this->StartMoving(this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10405F20
// Name: CPathKeyFrame_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPathKeyFrame_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPathKeyFrame>();
  CPathKeyFrame_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405F50
// Name: CBaseMoveBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseMoveBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseMoveBehavior>();
  CBaseMoveBehavior_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405F60
// Name: _dynamic_initializer_for__sv_gravity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_gravity__()
{
  ConVar::ConVar(
    this: &sv_gravity,
    pName: "sv_gravity",
    pDefaultValue: "800",
    flags: 8448,
    pHelpString: "World gravity.");
  return atexit(func: dynamic_atexit_destructor_for__sv_gravity__);
}

//------------------------------------------------------------------------------
// Address: 0x10405F90
// Name: _dynamic_initializer_for__sv_stopspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_stopspeed__()
{
  ConVar::ConVar(
    this: &sv_stopspeed,
    pName: "sv_stopspeed",
    pDefaultValue: "100",
    flags: 8450,
    pHelpString: "Minimum stopping speed when on ground.");
  return atexit(func: dynamic_atexit_destructor_for__sv_stopspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10405FC0
// Name: _dynamic_initializer_for__sv_noclipaccelerate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_noclipaccelerate__()
{
  ConVar::ConVar(this: &sv_noclipaccelerate, pName: "sv_noclipaccelerate", pDefaultValue: "5", flags: 8576);
  return atexit(func: dynamic_atexit_destructor_for__sv_noclipaccelerate__);
}

//------------------------------------------------------------------------------
// Address: 0x10405FF0
// Name: _dynamic_initializer_for__sv_noclipspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_noclipspeed__()
{
  ConVar::ConVar(this: &sv_noclipspeed, pName: "sv_noclipspeed", pDefaultValue: "5", flags: 8576);
  return atexit(func: dynamic_atexit_destructor_for__sv_noclipspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10406020
// Name: _dynamic_initializer_for__sv_specaccelerate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_specaccelerate__()
{
  ConVar::ConVar(this: &sv_specaccelerate, pName: "sv_specaccelerate", pDefaultValue: "5", flags: 8576);
  return atexit(func: dynamic_atexit_destructor_for__sv_specaccelerate__);
}

//------------------------------------------------------------------------------
// Address: 0x10406050
// Name: _dynamic_initializer_for__sv_specspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_specspeed__()
{
  ConVar::ConVar(this: &sv_specspeed, pName: "sv_specspeed", pDefaultValue: "3", flags: 8576);
  return atexit(func: dynamic_atexit_destructor_for__sv_specspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10406080
// Name: _dynamic_initializer_for__sv_specnoclip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_specnoclip__()
{
  ConVar::ConVar(this: &sv_specnoclip, pName: "sv_specnoclip", pDefaultValue: "1", flags: 8576);
  return atexit(func: dynamic_atexit_destructor_for__sv_specnoclip__);
}

//------------------------------------------------------------------------------
// Address: 0x104060B0
// Name: _dynamic_initializer_for__sv_maxspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxspeed__()
{
  ConVar::ConVar(this: &sv_maxspeed, pName: "sv_maxspeed", pDefaultValue: "320", flags: 8450);
  return atexit(func: dynamic_atexit_destructor_for__sv_maxspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x104060E0
// Name: _dynamic_initializer_for__sv_accelerate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_accelerate__()
{
  ConVar::ConVar(this: &sv_accelerate, pName: "sv_accelerate", pDefaultValue: "10", flags: 8450);
  return atexit(func: dynamic_atexit_destructor_for__sv_accelerate__);
}

//------------------------------------------------------------------------------
// Address: 0x10406110
// Name: _dynamic_initializer_for__sv_airaccelerate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_airaccelerate__()
{
  ConVar::ConVar(this: &sv_airaccelerate, pName: "sv_airaccelerate", pDefaultValue: "10", flags: 8450);
  return atexit(func: dynamic_atexit_destructor_for__sv_airaccelerate__);
}

//------------------------------------------------------------------------------
// Address: 0x10406140
// Name: _dynamic_initializer_for__sv_wateraccelerate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_wateraccelerate__()
{
  ConVar::ConVar(this: &sv_wateraccelerate, pName: "sv_wateraccelerate", pDefaultValue: "10", flags: 8450);
  return atexit(func: dynamic_atexit_destructor_for__sv_wateraccelerate__);
}

//------------------------------------------------------------------------------
// Address: 0x10406170
// Name: _dynamic_initializer_for__sv_waterfriction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_waterfriction__()
{
  ConVar::ConVar(this: &sv_waterfriction, pName: "sv_waterfriction", pDefaultValue: "1", flags: 8450);
  return atexit(func: dynamic_atexit_destructor_for__sv_waterfriction__);
}

//------------------------------------------------------------------------------
// Address: 0x104061A0
// Name: _dynamic_initializer_for__sv_footsteps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_footsteps__()
{
  ConVar::ConVar(
    this: &sv_footsteps,
    pName: "sv_footsteps",
    pDefaultValue: "1",
    flags: 8450,
    pHelpString: "Play footstep sound for players");
  return atexit(func: dynamic_atexit_destructor_for__sv_footsteps__);
}

//------------------------------------------------------------------------------
// Address: 0x104061D0
// Name: _dynamic_initializer_for__sv_rollspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rollspeed__()
{
  ConVar::ConVar(this: &sv_rollspeed, pName: "sv_rollspeed", pDefaultValue: "200", flags: 8450);
  return atexit(func: dynamic_atexit_destructor_for__sv_rollspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10406200
// Name: _dynamic_initializer_for__sv_rollangle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rollangle__()
{
  ConVar::ConVar(
    this: &sv_rollangle,
    pName: "sv_rollangle",
    pDefaultValue: "0",
    flags: 8450,
    pHelpString: "Max view roll angle");
  return atexit(func: dynamic_atexit_destructor_for__sv_rollangle__);
}

//------------------------------------------------------------------------------
// Address: 0x10406230
// Name: _dynamic_initializer_for__sv_friction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_friction__()
{
  ConVar::ConVar(
    this: &sv_friction,
    pName: "sv_friction",
    pDefaultValue: "4",
    flags: 8450,
    pHelpString: "World friction.");
  return atexit(func: dynamic_atexit_destructor_for__sv_friction__);
}

//------------------------------------------------------------------------------
// Address: 0x10406260
// Name: _dynamic_initializer_for__sv_bounce__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_bounce__()
{
  ConVar::ConVar(
    this: &sv_bounce,
    pName: "sv_bounce",
    pDefaultValue: "0",
    flags: 8450,
    pHelpString: "Bounce multiplier for when physically simulated objects collide with other objects.");
  return atexit(func: dynamic_atexit_destructor_for__sv_bounce__);
}

//------------------------------------------------------------------------------
// Address: 0x10406290
// Name: _dynamic_initializer_for__sv_maxvelocity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxvelocity__()
{
  ConVar::ConVar(
    this: &sv_maxvelocity,
    pName: "sv_maxvelocity",
    pDefaultValue: "3500",
    flags: 8194,
    pHelpString: "Maximum speed any ballistically moving object is allowed to attain per axis.");
  return atexit(func: dynamic_atexit_destructor_for__sv_maxvelocity__);
}

//------------------------------------------------------------------------------
// Address: 0x104062C0
// Name: _dynamic_initializer_for__sv_stepsize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_stepsize__()
{
  ConVar::ConVar(this: &sv_stepsize, pName: "sv_stepsize", pDefaultValue: "18", flags: 8450);
  return atexit(func: dynamic_atexit_destructor_for__sv_stepsize__);
}

//------------------------------------------------------------------------------
// Address: 0x104062F0
// Name: _dynamic_initializer_for__sv_skyname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_skyname__()
{
  ConVar::ConVar(
    this: &sv_skyname,
    pName: "sv_skyname",
    pDefaultValue: "sky_urb01",
    flags: 8320,
    pHelpString: "Current name of the skybox texture");
  return atexit(func: dynamic_atexit_destructor_for__sv_skyname__);
}

//------------------------------------------------------------------------------
// Address: 0x10406320
// Name: _dynamic_initializer_for__sv_backspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_backspeed__()
{
  ConVar::ConVar(
    this: &sv_backspeed,
    pName: "sv_backspeed",
    pDefaultValue: "0.6",
    flags: 8194,
    pHelpString: "How much to slow down backwards motion");
  return atexit(func: dynamic_atexit_destructor_for__sv_backspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10406350
// Name: _dynamic_initializer_for__sv_waterdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_waterdist__()
{
  ConVar::ConVar(
    this: &sv_waterdist,
    pName: "sv_waterdist",
    pDefaultValue: "12",
    flags: 8194,
    pHelpString: "Vertical view fixup when eyes are near water plane.");
  return atexit(func: dynamic_atexit_destructor_for__sv_waterdist__);
}

//------------------------------------------------------------------------------
// Address: 0x10406380
// Name: _dynamic_initializer_for__r_VehicleViewDampen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_VehicleViewDampen__()
{
  ConVar::ConVar(this: &r_VehicleViewDampen, pName: "r_VehicleViewDampen", pDefaultValue: "1", flags: 24832);
  return atexit(func: dynamic_atexit_destructor_for__r_VehicleViewDampen__);
}

//------------------------------------------------------------------------------
// Address: 0x104063B0
// Name: _dynamic_initializer_for__r_JeepViewDampenFreq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_JeepViewDampenFreq__()
{
  ConVar::ConVar(this: &r_JeepViewDampenFreq, pName: "r_JeepViewDampenFreq", pDefaultValue: "7.0", flags: 24832);
  return atexit(func: dynamic_atexit_destructor_for__r_JeepViewDampenFreq__);
}

//------------------------------------------------------------------------------
// Address: 0x104063E0
// Name: _dynamic_initializer_for__r_JeepViewDampenDamp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_JeepViewDampenDamp__()
{
  ConVar::ConVar(this: &r_JeepViewDampenDamp, pName: "r_JeepViewDampenDamp", pDefaultValue: "1.0", flags: 24832);
  return atexit(func: dynamic_atexit_destructor_for__r_JeepViewDampenDamp__);
}

//------------------------------------------------------------------------------
// Address: 0x10406410
// Name: _dynamic_initializer_for__r_JeepViewZHeight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_JeepViewZHeight__()
{
  ConVar::ConVar(this: &r_JeepViewZHeight, pName: "r_JeepViewZHeight", pDefaultValue: "10.0", flags: 24832);
  return atexit(func: dynamic_atexit_destructor_for__r_JeepViewZHeight__);
}

//------------------------------------------------------------------------------
// Address: 0x10406440
// Name: _dynamic_initializer_for__r_AirboatViewDampenFreq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_AirboatViewDampenFreq__()
{
  ConVar::ConVar(this: &r_AirboatViewDampenFreq, pName: "r_AirboatViewDampenFreq", pDefaultValue: "7.0", flags: 24832);
  return atexit(func: dynamic_atexit_destructor_for__r_AirboatViewDampenFreq__);
}

//------------------------------------------------------------------------------
// Address: 0x10406470
// Name: _dynamic_initializer_for__r_AirboatViewDampenDamp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_AirboatViewDampenDamp__()
{
  ConVar::ConVar(this: &r_AirboatViewDampenDamp, pName: "r_AirboatViewDampenDamp", pDefaultValue: "1.0", flags: 24832);
  return atexit(func: dynamic_atexit_destructor_for__r_AirboatViewDampenDamp__);
}

//------------------------------------------------------------------------------
// Address: 0x104064A0
// Name: _dynamic_initializer_for__r_AirboatViewZHeight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_AirboatViewZHeight__()
{
  ConVar::ConVar(this: &r_AirboatViewZHeight, pName: "r_AirboatViewZHeight", pDefaultValue: "0.0", flags: 24832);
  return atexit(func: dynamic_atexit_destructor_for__r_AirboatViewZHeight__);
}
