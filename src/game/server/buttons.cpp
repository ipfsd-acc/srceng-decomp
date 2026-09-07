// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/buttons.cpp
// Functions: 76
// ============================================================

#include "game\server\buttons.h"

//------------------------------------------------------------------------------
// Address: 0x100E39E0
// Name: protected: virtual struct datamap_t __near * CBaseButton::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseButton::GetDataDescMap(CBaseButton *this)
{
  return &CBaseButton::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E39F0
// Name: public: virtual class ServerClass __near * CBaseButton::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseButton::GetServerClass(CBaseButton *this)
{
  return &g_CBaseButton_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100E3A00
// Name: protected: virtual void CBaseButton::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::Lock(CBaseButton *this)
{
  this->m_bLocked = true;
}

//------------------------------------------------------------------------------
// Address: 0x100E3A10
// Name: protected: virtual void CBaseButton::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::Unlock(CBaseButton *this)
{
  this->m_bLocked = false;
}

//------------------------------------------------------------------------------
// Address: 0x100E3A30
// Name: protected: void CBaseButton::ButtonSpark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::ButtonSpark(CBaseButton *this)
{
  const Vector *v2; // eax
  float thinkTime; // [esp+8h] [ebp-Ch]

  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CBaseButton::ButtonSpark,
    thinkTime: 0.0,
    szContext: nullptr);
  thinkTime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                a1: random,
                a2: 0,
                a3: 1069547520)
            + gpGlobals->curtime
            + 0.1;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  v2 = this->WorldSpaceCenter(this);
  DoSpark(ent: this, location: v2, nMagnitude: 1, nTrailLength: 1, bPlaySound: true, vecDir: &vec3_origin);
}

//------------------------------------------------------------------------------
// Address: 0x100E3AB0
// Name: protected: bool CBaseButton::OnUseLocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseButton::OnUseLocked(CBaseButton *this, CBaseEntity *pActivator)
{
  PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 1, fbutton: 1);
  if ( gpGlobals->curtime <= this->m_flUseLockedTime )
    return 0;
  COutputEvent::FireOutput(this: &this->m_OnUseLocked, pActivator, pCaller: this, fDelay: 0.0);
  this->m_flUseLockedTime = gpGlobals->curtime + 0.5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E3B20
// Name: public: virtual int CBaseButton::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseButton::DrawDebugTextOverlays(CBaseButton *this)
{
  int result; // eax
  int v3; // esi
  TOGGLE_STATE m_toggle_state; // eax
  int v5; // esi
  const char *v6; // eax
  char tempstr[256]; // [esp+1Ch] [ebp-100h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    m_toggle_state = this->m_toggle_state;
    if ( (unsigned int)m_toggle_state >= 4 )
      m_toggle_state = 4;
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "State: %s", pszStates[m_toggle_state]);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v5 = v3 + 1;
    v6 = "Locked";
    if ( !this->m_bLocked )
      v6 = "Unlocked";
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "%s", v6);
    CBaseEntity::EntityText(this, text_offset: v5, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v5 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E3C10
// Name: public: virtual struct datamap_t __near * CMomentaryRotButton::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMomentaryRotButton::GetDataDescMap(CMomentaryRotButton *this)
{
  return &CMomentaryRotButton::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E3C20
// Name: public: virtual bool CBaseButton::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseButton::CreateVPhysics(CMomentaryRotButton *this)
{
  CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E3C30
// Name: public: void CMomentaryRotButton::InputDisableUpdateTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::InputDisableUpdateTarget(CMomentaryRotButton *this, inputdata_t *inputdata)
{
  this->m_bUpdateTarget = false;
}

//------------------------------------------------------------------------------
// Address: 0x100E3C40
// Name: public: void CMomentaryRotButton::InputEnableUpdateTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::InputEnableUpdateTarget(CMomentaryRotButton *this, inputdata_t *inputdata)
{
  this->m_bUpdateTarget = true;
}

//------------------------------------------------------------------------------
// Address: 0x100E3C50
// Name: public: virtual void CMomentaryRotButton::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::Lock(CMomentaryRotButton *this)
{
  this->m_bLocked = true;
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
  this->m_pfnMoveDone = nullptr;
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100E3CB0
// Name: public: void CMomentaryRotButton::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::InputEnable(CMomentaryRotButton *this, inputdata_t *inputdata)
{
  this->Enable(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E3CC0
// Name: public: void CMomentaryRotButton::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::InputDisable(CMomentaryRotButton *this, inputdata_t *inputdata)
{
  this->Disable(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E3CD0
// Name: public: virtual void CMomentaryRotButton::Enable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::Enable(CMomentaryRotButton *this)
{
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x100E3CE0
// Name: public: virtual void CMomentaryRotButton::Disable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::Disable(CMomentaryRotButton *this)
{
  this->m_bDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x100E3CF0
// Name: public: virtual void CBaseButton::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::Precache(CBaseButton *this)
{
  unsigned __int8 m_bLockedSound; // al
  const char *v3; // eax
  unsigned __int8 m_bUnlockedSound; // al
  const char *v5; // eax
  const char *v6; // esi
  char pDest[1024]; // [esp+4h] [ebp-404h] BYREF
  char pszValue[4]; // [esp+404h] [ebp-4h] BYREF

  m_bLockedSound = this->m_bLockedSound;
  if ( m_bLockedSound != 0 )
  {
    V_snprintf(pDest, maxLen: 1024, pFormat: "Buttons.snd%d", m_bLockedSound);
    AllocPooledString(pszValue);
    v3 = *(const char **)pszValue;
    this->m_ls.sLockedSound.pszValue = *(const char **)pszValue;
    if ( v3 == nullptr )
      v3 = locale;
    CBaseEntity::PrecacheScriptSound(soundname: v3);
  }
  m_bUnlockedSound = this->m_bUnlockedSound;
  if ( m_bUnlockedSound != 0 )
  {
    V_snprintf(pDest, maxLen: 1024, pFormat: "Buttons.snd%d", m_bUnlockedSound);
    AllocPooledString(pszValue);
    v5 = *(const char **)pszValue;
    this->m_ls.sUnlockedSound.pszValue = *(const char **)pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    CBaseEntity::PrecacheScriptSound(soundname: v5);
  }
  switch ( this->m_bLockedSentence )
  {
    case 1u:
      this->m_ls.sLockedSentence.pszValue = "NA";
      break;
    case 2u:
      this->m_ls.sLockedSentence.pszValue = "ND";
      break;
    case 3u:
      this->m_ls.sLockedSentence.pszValue = "NF";
      break;
    case 4u:
      this->m_ls.sLockedSentence.pszValue = "NFIRE";
      break;
    case 5u:
      this->m_ls.sLockedSentence.pszValue = "NCHEM";
      break;
    case 6u:
      this->m_ls.sLockedSentence.pszValue = "NRAD";
      break;
    case 7u:
      this->m_ls.sLockedSentence.pszValue = "NCON";
      break;
    case 8u:
      this->m_ls.sLockedSentence.pszValue = "NH";
      break;
    case 9u:
      this->m_ls.sLockedSentence.pszValue = "NG";
      break;
    default:
      this->m_ls.sLockedSentence.pszValue = nullptr;
      break;
  }
  switch ( this->m_bUnlockedSentence )
  {
    case 1u:
      this->m_ls.sUnlockedSentence.pszValue = "EA";
      break;
    case 2u:
      this->m_ls.sUnlockedSentence.pszValue = "ED";
      break;
    case 3u:
      this->m_ls.sUnlockedSentence.pszValue = "EF";
      break;
    case 4u:
      this->m_ls.sUnlockedSentence.pszValue = "EFIRE";
      break;
    case 5u:
      this->m_ls.sUnlockedSentence.pszValue = "ECHEM";
      break;
    case 6u:
      this->m_ls.sUnlockedSentence.pszValue = "ERAD";
      break;
    case 7u:
      this->m_ls.sUnlockedSentence.pszValue = "ECON";
      break;
    case 8u:
      this->m_ls.sUnlockedSentence.pszValue = "EH";
      break;
    default:
      this->m_ls.sUnlockedSentence.pszValue = nullptr;
      break;
  }
  if ( this->m_sNoise.pszValue != nullptr )
  {
    v6 = this->m_sNoise.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
    CBaseEntity::PrecacheScriptSound(soundname: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3F20
// Name: public: virtual bool CBaseButton::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseButton::KeyValue(CBaseButton *this, const char *szKeyName, const char *szValue)
{
  long double v4; // st7
  long double v6; // st7
  long double v7; // st7

  if ( szKeyName != "locked_sound" && _V_stricmp(s1: szKeyName, s2: "locked_sound") != 0 )
  {
    if ( szKeyName != "locked_sentence" && _V_stricmp(s1: szKeyName, s2: "locked_sentence") != 0 )
    {
      if ( szKeyName != "unlocked_sound" && _V_stricmp(s1: szKeyName, s2: "unlocked_sound") != 0 )
      {
        if ( szKeyName != "unlocked_sentence" && _V_stricmp(s1: szKeyName, s2: "unlocked_sentence") != 0 )
        {
          return CBaseToggle::KeyValue(this, szKeyName, szValue);
        }
        else
        {
          v7 = atof(nptr: szValue);
          this->m_bUnlockedSentence = (int)v7;
          return true;
        }
      }
      else
      {
        v6 = atof(nptr: szValue);
        this->m_bUnlockedSound = (int)v6;
        return true;
      }
    }
    else
    {
      this->m_bLockedSentence = (int)atof(nptr: szValue);
      return true;
    }
  }
  else
  {
    v4 = atof(nptr: szValue);
    this->m_bLockedSound = (int)v4;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4080
// Name: public: float CMomentaryRotButton::GetPos(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMomentaryRotButton::GetPos(CMomentaryRotButton *this, const QAngle *vecAngles)
{
  double v2; // st7
  float v3; // xmm0_4
  float flScale; // [esp+0h] [ebp-4h]
  float flPos; // [esp+Ch] [ebp+8h]

  flScale = 1.0;
  if ( this->m_vecMoveAng.x < 0.0 || this->m_vecMoveAng.y < 0.0 || this->m_vecMoveAng.z < 0.0 )
    flScale = -1.0;
  v2 = CBaseToggle::AxisDelta(flags: this->m_spawnflags.m_Value, angle1: vecAngles, angle2: &this->m_start)
     * flScale
     / this->m_flMoveDistance;
  if ( v2 < 0.0 )
    return 0.0;
  v3 = v2;
  flPos = v2;
  if ( flPos <= 1.0 )
    return v3;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100E4120
// Name: public: void CMomentaryRotButton::InputSetPositionImmediately(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::InputSetPositionImmediately(CMomentaryRotButton *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  QAngle angles; // [esp+0h] [ebp-Ch] BYREF

  if ( inputdata->value.fieldType != FIELD_FLOAT )
  {
    flVal = 0.0;
LABEL_4:
    v3 = flVal;
    goto LABEL_5;
  }
  flVal = inputdata->value.flVal;
  v3 = 0.0;
  if ( flVal >= 0.0 )
  {
    v3 = 1.0;
    if ( flVal <= 1.0 )
      goto LABEL_4;
  }
LABEL_5:
  v4 = this->m_flMoveDistance * v3;
  this->m_IdealYaw = v3;
  v5 = this->m_vecMoveAng.y * v4;
  v6 = this->m_vecMoveAng.z * v4;
  angles.x = this->m_start.x + (float)(this->m_vecMoveAng.x * v4);
  angles.y = this->m_start.y + v5;
  angles.z = this->m_start.z + v6;
  CBaseEntity::SetLocalAngles(this, &angles);
}

//------------------------------------------------------------------------------
// Address: 0x100E4280
// Name: protected: enum CBaseButton::BUTTON_CODE CBaseButton::ButtonResponseToTouch(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseButton::ButtonResponseToTouch(CBaseButton *this)
{
  TOGGLE_STATE m_toggle_state; // eax

  m_toggle_state = this->m_toggle_state;
  if ( m_toggle_state != TS_GOING_UP && m_toggle_state != TS_GOING_DOWN )
  {
    if ( m_toggle_state != TS_AT_TOP )
      return 1;
    if ( (this->m_fStayPushed || (this->m_spawnflags.m_Value & 0x20) != 0)
      && (this->m_spawnflags.m_Value & 0x20) != 0
      && !this->m_fStayPushed )
    {
      return 2;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E42E0
// Name: protected: virtual int CBaseButton::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseButton::ObjectCaps(CBaseButton *this)
{
  bool v1; // bl

  v1 = (this->m_spawnflags.m_Value & 0x400) != 0;
  return (v1 ? 0x21 : 0) | CBaseEntity::ObjectCaps(this) & 0xFFFFFF7F;
}

//------------------------------------------------------------------------------
// Address: 0x100E4310
// Name: protected: void CBaseButton::ButtonBackHome(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::ButtonBackHome(CBaseButton *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // eax
  unsigned int v4; // eax

  this->m_toggle_state = TS_AT_BOTTOM;
  m_Index = this->m_hActivator.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  COutputEvent::FireOutput(this: &this->m_OnOut, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
  v4 = (unsigned int)this->m_spawnflags.m_Value >> 12;
  this->m_pfnTouch = (this->m_spawnflags.m_Value & 0x100) != 0
                   ? (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBaseButton::ButtonTouch
                   : nullptr;
  if ( (v4 & 1) != 0 )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CBaseButton::ButtonSpark,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E43D0
// Name: public: virtual int CMomentaryRotButton::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMomentaryRotButton::ObjectCaps(CMomentaryRotButton *this)
{
  bool v2; // bl
  unsigned int result; // eax

  v2 = (this->m_spawnflags.m_Value & 0x400) != 0;
  result = (v2 ? 0x21 : 0) | CBaseEntity::ObjectCaps(this) & 0xFFFFFF7F;
  if ( (this->m_spawnflags.m_Value & 0x400) != 0 )
    result |= 0x22u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E4410
// Name: public: virtual int CMomentaryRotButton::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMomentaryRotButton::DrawDebugTextOverlays(CMomentaryRotButton *this)
{
  int result; // eax
  int v3; // edi
  int v4; // edi
  double Pos; // st7
  int v6; // edi
  const char *v7; // eax
  char tempstr[256]; // [esp+24h] [ebp-100h] BYREF

  result = CBaseButton::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(
      pDest: tempstr,
      maxLen: 255,
      pFormat: "QAngle: %.2f %.2f %.2f",
      this->m_angRotation.m_Value.x,
      this->m_angRotation.m_Value.y,
      this->m_angRotation.m_Value.z);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    V_snprintf(
      pDest: tempstr,
      maxLen: 255,
      pFormat: "AVelocity: %.2f %.2f %.2f",
      this->m_vecAngVelocity.x,
      this->m_vecAngVelocity.y,
      this->m_vecAngVelocity.z);
    CBaseEntity::EntityText(this, text_offset: v4++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Target Pos:   %3.3f", this->m_IdealYaw);
    CBaseEntity::EntityText(this, text_offset: v4++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    Pos = CMomentaryRotButton::GetPos(this, vecAngles: &this->m_angRotation.m_Value);
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Current Pos:   %3.3f", Pos);
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v6 = v4 + 1;
    v7 = "Forward";
    if ( this->m_direction != 1 )
      v7 = "Backward";
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Direction: %s", v7);
    CBaseEntity::EntityText(this, text_offset: v6, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v6 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E4640
// Name: protected: void CBaseButton::ButtonReturn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::ButtonReturn(CBaseButton *this)
{
  bool v2; // zf
  float flSpeed; // xmm0_4

  v2 = !this->m_fRotating;
  flSpeed = this->m_flSpeed;
  this->m_toggle_state = TS_GOING_DOWN;
  this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CBaseButton::ButtonBackHome;
  if ( v2 )
    CBaseToggle::LinearMove(this, vecDest: &this->m_vecPosition1, flSpeed);
  else
    CBaseToggle::AngularMove(this, vecDestAngle: &this->m_vecAngle1, flSpeed);
  this->m_nState = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E46A0
// Name: protected: void CMomentaryRotButton::UpdateThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::UpdateThink(CMomentaryRotButton *this)
{
  float value; // [esp+10h] [ebp-4h]

  value = CMomentaryRotButton::GetPos(this, vecAngles: &this->m_angRotation.m_Value);
  if ( this->m_bUpdateTarget && this->m_Position.m_Value.flVal != value )
    CEntityOutputTemplate<float,1>::Set(this: &this->m_Position, value, pActivator: nullptr, pCaller: this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100E4710
// Name: public: CBaseButton::CBaseButton(void)
// Source: json
//------------------------------------------------------------------------------
CBaseButton *__thiscall CBaseButton::CBaseButton(CBaseButton *this)
{
  CBaseToggle::CBaseToggle(this);
  this->__vftable = (CBaseButton_vtbl *)&CBaseButton::`vftable';
  this->m_ls.__vftable = (locksound_t_vtbl *)&locksound_t::`vftable';
  this->m_OnDamaged.m_Value.iVal = 0;
  this->m_OnDamaged.m_Value.eVal.m_Index = -1;
  this->m_OnDamaged.m_Value.fieldType = FIELD_VOID;
  this->m_OnPressed.m_Value.iVal = 0;
  this->m_OnPressed.m_Value.eVal.m_Index = -1;
  this->m_OnPressed.m_Value.fieldType = FIELD_VOID;
  this->m_OnUseLocked.m_Value.iVal = 0;
  this->m_OnUseLocked.m_Value.eVal.m_Index = -1;
  this->m_OnUseLocked.m_Value.fieldType = FIELD_VOID;
  this->m_OnIn.m_Value.iVal = 0;
  this->m_OnIn.m_Value.eVal.m_Index = -1;
  this->m_OnIn.m_Value.fieldType = FIELD_VOID;
  this->m_OnOut.m_Value.iVal = 0;
  this->m_OnOut.m_Value.eVal.m_Index = -1;
  this->m_OnOut.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E47D0
// Name: public: virtual float CBaseToggle::GetDelay(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseToggle::GetDelay(CBaseToggle *this)
{
  return this->m_flWait;
}

//------------------------------------------------------------------------------
// Address: 0x100E4840
// Name: public: CMomentaryRotButton::CMomentaryRotButton(void)
// Source: json
//------------------------------------------------------------------------------
CMomentaryRotButton *__thiscall CMomentaryRotButton::CMomentaryRotButton(CMomentaryRotButton *this)
{
  CBaseButton::CBaseButton(this);
  this->__vftable = (CMomentaryRotButton_vtbl *)&CMomentaryRotButton::`vftable';
  this->m_Position.m_Value.iVal = 0;
  this->m_Position.m_Value.eVal.m_Index = -1;
  this->m_Position.m_Value.fieldType = FIELD_VOID;
  this->m_OnUnpressed.m_Value.iVal = 0;
  this->m_OnUnpressed.m_Value.eVal.m_Index = -1;
  this->m_OnUnpressed.m_Value.fieldType = FIELD_VOID;
  this->m_OnFullyOpen.m_Value.iVal = 0;
  this->m_OnFullyOpen.m_Value.eVal.m_Index = -1;
  this->m_OnFullyOpen.m_Value.fieldType = FIELD_VOID;
  this->m_OnFullyClosed.m_Value.iVal = 0;
  this->m_OnFullyClosed.m_Value.eVal.m_Index = -1;
  this->m_OnFullyClosed.m_Value.fieldType = FIELD_VOID;
  this->m_OnReachedPosition.m_Value.iVal = 0;
  this->m_OnReachedPosition.m_Value.eVal.m_Index = -1;
  this->m_OnReachedPosition.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E48C0
// Name: public: virtual CMomentaryRotButton::~CMomentaryRotButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::~CMomentaryRotButton(CMomentaryRotButton *this)
{
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnReachedPosition);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnFullyClosed);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnFullyOpen);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUnpressed);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_Position);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnOut);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnIn);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUseLocked);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPressed);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnDamaged);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E4970
// Name: protected: void CBaseButton::TriggerAndWait(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::TriggerAndWait(CBaseButton *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  bool v4; // zf
  unsigned int v5; // eax
  CBaseEntity *v6; // ecx

  m_Index = this->m_hActivator.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( UTIL_IsMasterTriggered(sMaster: this->m_sMaster, pActivator: m_pEntity) && !this->m_bLocked )
  {
    v4 = !this->m_fStayPushed;
    this->m_toggle_state = TS_AT_TOP;
    if ( !v4 || (this->m_spawnflags.m_Value & 0x20) != 0 )
    {
      this->m_pfnTouch = (this->m_spawnflags.m_Value & 0x100) != 0
                       ? (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBaseButton::ButtonTouch
                       : nullptr;
    }
    else
    {
      CBaseEntity::SetNextThink(this, thinkTime: this->m_flWait + gpGlobals->curtime, szContext: nullptr);
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CBaseButton::ButtonReturn,
        thinkTime: 0.0,
        szContext: nullptr);
    }
    this->m_nState = 1;
    v5 = this->m_hActivator.m_Index;
    if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
      v6 = nullptr;
    else
      v6 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
    COutputEvent::FireOutput(this: &this->m_OnIn, pActivator: v6, pCaller: this, fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4A90
// Name: public: virtual void CMomentaryRotButton::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::Spawn(CMomentaryRotButton *this)
{
  float m_flSpeed; // xmm0_4
  float m_flStartPosition; // xmm0_4
  const char *DebugName; // eax
  float m_IdealYaw; // xmm0_4
  int m_direction; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float m_flMoveDistance; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float x; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int m_Value; // eax
  const char *v23; // eax
  const char *v24; // eax
  char pDest[1024]; // [esp+18h] [ebp-404h] BYREF
  char pszValue[4]; // [esp+418h] [ebp-4h] BYREF

  CBaseToggle::AxisDir(this);
  m_flSpeed = this->m_flSpeed;
  this->m_bUpdateTarget = true;
  if ( m_flSpeed == 0.0 )
    this->m_flSpeed = 100.0;
  m_flStartPosition = this->m_flStartPosition;
  if ( m_flStartPosition < 0.0 || m_flStartPosition > 1.0 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(a1: "WARNING: Momentary door (%s) start position not between 0 and 1.  Clamping.\n", DebugName);
    m_IdealYaw = this->m_IdealYaw;
    if ( m_IdealYaw >= 0.0 )
    {
      if ( m_IdealYaw > 1.0 )
        m_IdealYaw = 1.0;
    }
    else
    {
      m_IdealYaw = 0.0;
    }
    this->m_flStartPosition = m_IdealYaw;
  }
  m_direction = this->m_direction;
  if ( m_direction != 1 && m_direction != -1 )
    this->m_direction = 1;
  if ( this->m_flMoveDistance < 0.0 )
  {
    y = this->m_vecMoveAng.y;
    z = this->m_vecMoveAng.z;
    this->m_vecMoveAng.x = this->m_vecMoveAng.x * -1.0;
    this->m_vecMoveAng.y = y * -1.0;
    this->m_vecMoveAng.z = z * -1.0;
    LODWORD(this->m_flMoveDistance) ^= _mask__NegFloat_;
  }
  m_flMoveDistance = this->m_flMoveDistance;
  v10 = this->m_flStartPosition;
  v11 = this->m_vecMoveAng.x * m_flMoveDistance;
  v12 = (float)(m_flMoveDistance * this->m_vecMoveAng.z) * v10;
  v13 = this->m_angRotation.m_Value.z;
  v14 = v10 * v11;
  x = this->m_angRotation.m_Value.x;
  this->m_start.y = this->m_angRotation.m_Value.y
                  - (float)((float)(this->m_flMoveDistance * this->m_vecMoveAng.y) * v10);
  this->m_start.z = v13 - v12;
  this->m_start.x = x - v14;
  v16 = this->m_flMoveDistance;
  v17 = this->m_vecMoveAng.x * v16;
  v18 = 1.0 - this->m_flStartPosition;
  v19 = (float)((float)(v16 * this->m_vecMoveAng.z) * v18) + this->m_angRotation.m_Value.z;
  v20 = (float)((float)(this->m_flMoveDistance * this->m_vecMoveAng.y) * v18) + this->m_angRotation.m_Value.y;
  this->m_end.x = this->m_angRotation.m_Value.x + (float)(v18 * v17);
  this->m_end.y = v20;
  this->m_end.z = v19;
  v21 = this->m_flStartPosition;
  this->m_IdealYaw = v21;
  if ( v21 == 0.0 )
  {
    this->m_direction = -1;
  }
  else if ( v21 == 1.0 )
  {
    this->m_direction = 1;
  }
  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x800) != 0 )
    this->m_bLocked = true;
  if ( (m_Value & 0x400) != 0 )
  {
    if ( this->m_sounds != 0 )
    {
      V_snprintf(pDest, maxLen: 1024, pFormat: "Buttons.snd%d", this->m_sounds);
      AllocPooledString(pszValue);
      v23 = *(const char **)pszValue;
      this->m_sNoise.pszValue = *(const char **)pszValue;
      if ( v23 == nullptr )
        v23 = locale;
      CBaseEntity::PrecacheScriptSound(soundname: v23);
    }
    else
    {
      this->m_sNoise.pszValue = nullptr;
    }
    this->m_lastUsed = 0;
    if ( this->m_bUpdateTarget && this->m_Position.m_Value.flVal != 0.0 )
      CEntityOutputTemplate<float,1>::Set(this: &this->m_Position, value: 0.0, pActivator: this, pCaller: this);
  }
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    this->m_iEFlags |= 0x40000u;
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  }
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  v24 = *(const char **)((int (__thiscall *)(CMomentaryRotButton *, char *))this->GetModelName)(a1: this, a2: pszValue);
  if ( v24 == nullptr )
    v24 = locale;
  this->SetModel(this, a2: v24);
  this->CreateVPhysics(this);
  if ( this->m_bSolidBsp )
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x100E4E10
// Name: public: void CMomentaryRotButton::SetPositionMoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::SetPositionMoveDone(CMomentaryRotButton *this)
{
  CNetworkVectorXYZBase<QAngle,CBaseEntity::NetworkVar_m_angRotation> *p_m_angRotation; // edi
  float m_IdealYaw; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float value; // xmm0_4
  float v9; // xmm0_4
  int m_Value; // edx
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  long double v14; // st7
  CGlobalVars *v15; // eax
  float interval_per_tick; // xmm2_4
  float v17; // xmm1_4
  __m128i v18; // xmm3
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float flDelay; // xmm0_4
  QAngle vecNewAngles; // [esp+14h] [ebp-1Ch] BYREF
  QAngle angles; // [esp+20h] [ebp-10h] BYREF
  float flAngleDelta; // [esp+2Ch] [ebp-4h]

  p_m_angRotation = &this->m_angRotation;
  flAngleDelta = CMomentaryRotButton::GetPos(this, vecAngles: &this->m_angRotation.m_Value);
  m_IdealYaw = this->m_IdealYaw;
  if ( flAngleDelta >= m_IdealYaw && this->m_direction == 1 || m_IdealYaw >= flAngleDelta && this->m_direction == -1 )
  {
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
    v4 = this->m_flMoveDistance * this->m_IdealYaw;
    v5 = (float)(v4 * this->m_vecMoveAng.x) + this->m_start.x;
    v6 = this->m_vecMoveAng.z * v4;
    angles.y = this->m_start.y + (float)(this->m_vecMoveAng.y * v4);
    v7 = this->m_start.z + v6;
    angles.x = v5;
    angles.z = v7;
    CBaseEntity::SetLocalAngles(this, &angles);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
    value = this->m_IdealYaw;
    if ( this->m_bUpdateTarget && this->m_Position.m_Value.flVal != value )
      CEntityOutputTemplate<float,1>::Set(this: &this->m_Position, value, pActivator: this, pCaller: this);
    v9 = this->m_IdealYaw;
    if ( v9 == 1.0 )
    {
      COutputEvent::FireOutput(this: &this->m_OnFullyClosed, pActivator: this, pCaller: this, fDelay: 0.0);
    }
    else if ( v9 == 0.0 )
    {
      COutputEvent::FireOutput(this: &this->m_OnFullyOpen, pActivator: this, pCaller: this, fDelay: 0.0);
    }
    COutputEvent::FireOutput(this: &this->m_OnReachedPosition, pActivator: this, pCaller: this, fDelay: 0.0);
  }
  else
  {
    m_Value = this->m_spawnflags.m_Value;
    v11 = this->m_flMoveDistance * m_IdealYaw;
    vecNewAngles.x = (float)(v11 * this->m_vecMoveAng.x) + this->m_start.x;
    v12 = v11 * this->m_vecMoveAng.y;
    v13 = v11 * this->m_vecMoveAng.z;
    vecNewAngles.y = this->m_start.y + v12;
    vecNewAngles.z = this->m_start.z + v13;
    v14 = CBaseToggle::AxisDelta(flags: m_Value, angle1: &vecNewAngles, angle2: &p_m_angRotation->m_Value);
    v15 = gpGlobals;
    flAngleDelta = fabs(v14);
    interval_per_tick = gpGlobals->interval_per_tick;
    v17 = flAngleDelta / this->m_flSpeed;
    if ( interval_per_tick > v17 )
    {
      v18 = _mm_cvtsi32_si128(this->m_direction);
      v19 = flAngleDelta / interval_per_tick;
      flAngleDelta = gpGlobals->interval_per_tick;
      *(float *)v18.m128i_i32 = _mm_cvtepi32_ps(v18).m128_f32[0];
      v20 = (float)(v19 * this->m_vecMoveAng.x) * *(float *)v18.m128i_i32;
      v21 = (float)(v19 * this->m_vecMoveAng.y) * *(float *)v18.m128i_i32;
      v22 = (float)(v19 * this->m_vecMoveAng.z) * *(float *)v18.m128i_i32;
      angles.x = v20;
      angles.y = v21;
      angles.z = v22;
      CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &angles);
      v15 = gpGlobals;
      v17 = flAngleDelta;
    }
    flDelay = v15->interval_per_tick * 6.0;
    if ( v15->interval_per_tick <= v17 )
    {
      if ( v17 <= flDelay )
        flDelay = v17;
      CBaseEntity::SetMoveDoneTime(this, flDelay);
    }
    else
    {
      CBaseEntity::SetMoveDoneTime(this, flDelay: v15->interval_per_tick);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E50E0
// Name: public: void CMomentaryRotButton::ReturnMoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::ReturnMoveDone(CMomentaryRotButton *this)
{
  float v2; // xmm0_4
  QAngle vecAngVelocity; // [esp+10h] [ebp-Ch] BYREF

  if ( CMomentaryRotButton::GetPos(this, vecAngles: &this->m_angRotation.m_Value) > 0.0 )
  {
    LODWORD(v2) = LODWORD(this->m_returnSpeed) ^ _mask__NegFloat_;
    vecAngVelocity.x = this->m_vecMoveAng.x * v2;
    vecAngVelocity.y = this->m_vecMoveAng.y * v2;
    vecAngVelocity.z = this->m_vecMoveAng.z * v2;
    CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
    CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CMomentaryRotButton::UpdateThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.0099999998, szContext: nullptr);
  }
  else
  {
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
    CBaseEntity::SetLocalAngles(this, angles: &this->m_start);
    if ( this->m_bUpdateTarget && this->m_Position.m_Value.flVal != 0.0 )
      CEntityOutputTemplate<float,1>::Set(this: &this->m_Position, value: 0.0, pActivator: nullptr, pCaller: this);
    CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
    this->m_pfnMoveDone = nullptr;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5240
// Name: public: void CMomentaryRotButton::InputSetPosition(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::InputSetPosition(CMomentaryRotButton *this, inputdata_t *inputdata)
{
  float flVal; // xmm1_4
  float v4; // xmm0_4
  float m_IdealYaw; // xmm0_4
  float m_flSpeed; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  int m_Value; // ecx
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  long double v18; // st7
  CGlobalVars *v19; // eax
  float interval_per_tick; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float m_direction; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float flDelay; // xmm0_4
  QAngle vecNewAngles; // [esp+10h] [ebp-18h] BYREF
  QAngle vecAngVelocity; // [esp+1Ch] [ebp-Ch] BYREF
  float flAngleDelta; // [esp+30h] [ebp+8h]
  float flAngleDeltaa; // [esp+30h] [ebp+8h]
  float flAngleDeltab; // [esp+30h] [ebp+8h]

  if ( inputdata->value.fieldType != FIELD_FLOAT )
  {
    flVal = 0.0;
LABEL_4:
    v4 = flVal;
    goto LABEL_5;
  }
  flVal = inputdata->value.flVal;
  v4 = 0.0;
  if ( flVal >= 0.0 )
  {
    v4 = 1.0;
    if ( flVal <= 1.0 )
      goto LABEL_4;
  }
LABEL_5:
  this->m_IdealYaw = v4;
  flAngleDelta = CMomentaryRotButton::GetPos(this, vecAngles: &this->m_angRotation.m_Value);
  m_IdealYaw = this->m_IdealYaw;
  if ( m_IdealYaw <= flAngleDelta )
  {
    if ( flAngleDelta <= m_IdealYaw )
    {
      CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
      return;
    }
    LODWORD(v9) = LODWORD(this->m_flSpeed) ^ _mask__NegFloat_;
    vecAngVelocity.x = v9 * this->m_vecMoveAng.x;
    v10 = v9 * this->m_vecMoveAng.y;
    v11 = v9 * this->m_vecMoveAng.z;
    vecAngVelocity.y = v10;
    vecAngVelocity.z = v11;
    CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
    this->m_direction = -1;
  }
  else
  {
    m_flSpeed = this->m_flSpeed;
    vecAngVelocity.x = m_flSpeed * this->m_vecMoveAng.x;
    v7 = m_flSpeed * this->m_vecMoveAng.y;
    v8 = m_flSpeed * this->m_vecMoveAng.z;
    vecAngVelocity.y = v7;
    vecAngVelocity.z = v8;
    CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
    this->m_direction = 1;
  }
  this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CMomentaryRotButton::SetPositionMoveDone;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CMomentaryRotButton::UpdateThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  v12 = this->m_flMoveDistance * this->m_IdealYaw;
  m_Value = this->m_spawnflags.m_Value;
  v14 = this->m_start.x + (float)(v12 * this->m_vecMoveAng.x);
  v15 = v12 * this->m_vecMoveAng.y;
  v16 = v12 * this->m_vecMoveAng.z;
  vecNewAngles.y = this->m_start.y + v15;
  v17 = this->m_start.z + v16;
  vecNewAngles.x = v14;
  vecNewAngles.z = v17;
  v18 = CBaseToggle::AxisDelta(flags: m_Value, angle1: &vecNewAngles, angle2: &this->m_angRotation.m_Value);
  v19 = gpGlobals;
  flAngleDeltaa = fabs(v18);
  interval_per_tick = gpGlobals->interval_per_tick;
  v21 = flAngleDeltaa / this->m_flSpeed;
  if ( interval_per_tick > v21 )
  {
    v22 = flAngleDeltaa / interval_per_tick;
    flAngleDeltab = gpGlobals->interval_per_tick;
    m_direction = (float)this->m_direction;
    v24 = (float)(v22 * this->m_vecMoveAng.x) * m_direction;
    v25 = (float)(v22 * this->m_vecMoveAng.y) * m_direction;
    v26 = (float)(v22 * this->m_vecMoveAng.z) * m_direction;
    vecAngVelocity.x = v24;
    vecAngVelocity.y = v25;
    vecAngVelocity.z = v26;
    CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
    v19 = gpGlobals;
    v21 = flAngleDeltab;
  }
  flDelay = v19->interval_per_tick * 6.0;
  if ( v19->interval_per_tick <= v21 )
  {
    if ( v21 <= flDelay )
      flDelay = v21;
    CBaseEntity::SetMoveDoneTime(this, flDelay);
  }
  else
  {
    CBaseEntity::SetMoveDoneTime(this, flDelay: v19->interval_per_tick);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E54E0
// Name: public: virtual void CMomentaryRotButton::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::Unlock(CMomentaryRotButton *this)
{
  this->m_bLocked = false;
  this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CMomentaryRotButton::ReturnMoveDone;
  CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
}

//------------------------------------------------------------------------------
// Address: 0x100E5510
// Name: public: void CMomentaryRotButton::UseMoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::UseMoveDone(CMomentaryRotButton *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v4; // eax
  float flPos; // [esp+10h] [ebp-4h]

  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  flPos = CMomentaryRotButton::GetPos(this, vecAngles: &this->m_angRotation.m_Value);
  if ( this->m_bUpdateTarget && this->m_Position.m_Value.flVal != flPos )
    CEntityOutputTemplate<float,1>::Set(this: &this->m_Position, value: flPos, pActivator: this, pCaller: this);
  m_Index = this->m_hActivator.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  COutputEvent::FireOutput(this: &this->m_OnUnpressed, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
  v4 = (unsigned int)this->m_spawnflags.m_Value >> 5;
  this->m_lastUsed = 0;
  if ( (v4 & 1) != 0 || this->m_returnSpeed <= 0.0 )
  {
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    this->m_pfnMoveDone = nullptr;
  }
  else
  {
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CMomentaryRotButton::ReturnMoveDone;
    this->m_direction = -1;
    CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E56E0
// Name: protected: void CBaseButton::ButtonActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::ButtonActivate(CBaseButton *this)
{
  const Vector *v2; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v4; // eax
  const char *pszValue; // eax
  edict_t *m_pPev; // eax
  signed int v7; // eax
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  float flSpeed; // xmm0_4
  EmitSound_t ep; // [esp+14h] [ebp-74h] BYREF
  CPASAttenuationFilter filter; // [esp+5Ch] [ebp-2Ch] BYREF
  float attenuation[3]; // [esp+7Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+88h] [ebp+0h] BYREF

  if ( this->m_sNoise.pszValue != nullptr )
  {
    v2 = (const Vector *)((int (__thiscall *)(CBaseButton *))this->GetSoundEmissionOrigin)(a1: this);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v2);
    GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v4 = (const Vector *)((int (__thiscall *)(CBaseButton *, float *, int))GetSoundEmissionOrigin)(
                           a1: this,
                           a2: attenuation,
                           a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v4,
      attenuation: COERCE_FLOAT(attenuation));
    ep.m_hSoundScriptHandle = -1;
    pszValue = this->m_sNoise.pszValue;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nSoundEntryVersion = 1;
    ep.m_nChannel = 2;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    m_pPev = this->m_Network.m_pPev;
    ep.m_flVolume = 1.0;
    ep.m_SoundLevel = SNDLVL_NORM;
    if ( m_pPev != nullptr )
      v7 = m_pPev - gpGlobals->pEdicts;
    else
      v7 = 0;
    CBaseEntity::EmitSound(&filter, iEntIndex: v7, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  m_Index = this->m_hActivator.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( !UTIL_IsMasterTriggered(sMaster: this->m_sMaster, pActivator: m_pEntity) || this->m_bLocked )
  {
    PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 1, fbutton: 1);
  }
  else
  {
    PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 0, fbutton: 1);
    flSpeed = this->m_flSpeed;
    this->m_toggle_state = TS_GOING_UP;
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CBaseButton::TriggerAndWait;
    if ( this->m_fRotating )
      CBaseToggle::AngularMove(this, vecDestAngle: &this->m_vecAngle2, flSpeed);
    else
      CBaseToggle::LinearMove(this, vecDest: &this->m_vecPosition2, flSpeed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6000
// Name: public: void CMomentaryRotButton::PlaySound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::PlaySound(CMomentaryRotButton *this)
{
  const Vector *v2; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v4; // eax
  const char *pszValue; // eax
  edict_t *m_pPev; // esi
  signed int v7; // esi
  EmitSound_t ep; // [esp+14h] [ebp-74h] BYREF
  CPASAttenuationFilter filter; // [esp+5Ch] [ebp-2Ch] BYREF
  float attenuation[3]; // [esp+7Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+88h] [ebp+0h] BYREF

  if ( this->m_sNoise.pszValue != nullptr )
  {
    v2 = (const Vector *)((int (__thiscall *)(CMomentaryRotButton *))this->GetSoundEmissionOrigin)(a1: this);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v2);
    GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v4 = (const Vector *)((int (__thiscall *)(CMomentaryRotButton *, float *, int))GetSoundEmissionOrigin)(
                           a1: this,
                           a2: attenuation,
                           a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v4,
      attenuation: COERCE_FLOAT(attenuation));
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_nSoundEntryVersion = 1;
    pszValue = this->m_sNoise.pszValue;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_hSoundScriptHandle = -1;
    ep.m_nChannel = 2;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    m_pPev = this->m_Network.m_pPev;
    ep.m_flVolume = 1.0;
    ep.m_SoundLevel = SNDLVL_NORM;
    if ( m_pPev != nullptr )
      v7 = m_pPev - gpGlobals->pEdicts;
    else
      v7 = 0;
    CBaseEntity::EmitSound(&filter, iEntIndex: v7, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6130
// Name: public: void CMomentaryRotButton::UpdateSelf(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::UpdateSelf(CMomentaryRotButton *this, float value, bool bPlaySound)
{
  int m_direction; // eax
  bool v5; // sf
  float v6; // xmm0_4
  QAngle vecAngVelocity; // [esp+8h] [ebp-Ch] BYREF

  CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
  m_direction = this->m_direction;
  v5 = m_direction < 0;
  if ( m_direction > 0 )
  {
    if ( value >= 1.0 )
    {
      CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
      CBaseEntity::SetLocalAngles(this, angles: &this->m_end);
      COutputEvent::FireOutput(this: &this->m_OnFullyClosed, pActivator: this, pCaller: this, fDelay: 0.0);
      return;
    }
    v5 = m_direction < 0;
  }
  if ( v5 && value <= 0.0 )
  {
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
    CBaseEntity::SetLocalAngles(this, angles: &this->m_start);
    COutputEvent::FireOutput(this: &this->m_OnFullyOpen, pActivator: this, pCaller: this, fDelay: 0.0);
  }
  else
  {
    if ( bPlaySound )
      CMomentaryRotButton::PlaySound(this);
    v6 = (float)this->m_direction * this->m_flSpeed;
    vecAngVelocity.x = this->m_vecMoveAng.x * v6;
    vecAngVelocity.y = this->m_vecMoveAng.y * v6;
    vecAngVelocity.z = this->m_vecMoveAng.z * v6;
    CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CMomentaryRotButton::UseMoveDone;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6250
// Name: protected: void CBaseButton::Press(class CBaseEntity __near *,enum CBaseButton::BUTTON_CODE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::Press(CBaseButton *this, CBaseEntity *pActivator, CBaseButton::BUTTON_CODE eCode)
{
  TOGGLE_STATE m_toggle_state; // ecx
  TOGGLE_STATE v5; // ecx
  TOGGLE_STATE v6; // ecx
  TOGGLE_STATE v7; // eax
  const char *pszValue; // eax
  edict_t *v9; // eax
  TOGGLE_STATE v10; // eax
  EmitSound_t ep; // [esp+8h] [ebp-68h] BYREF
  CPASAttenuationFilter filter; // [esp+50h] [ebp-20h] BYREF

  switch ( eCode )
  {
    case BUTTON_PRESS:
      m_toggle_state = this->m_toggle_state;
      if ( m_toggle_state == TS_GOING_UP || m_toggle_state == TS_GOING_DOWN )
        return;
      break;
    case BUTTON_ACTIVATE:
      v5 = this->m_toggle_state;
      if ( v5 == TS_GOING_UP || v5 == TS_AT_TOP )
        return;
      break;
    case BUTTON_RETURN:
      v6 = this->m_toggle_state;
      if ( v6 == TS_GOING_DOWN || v6 == TS_AT_BOTTOM )
        return;
      break;
    default:
      break;
  }
  if ( this->m_bLocked )
  {
    PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 1, fbutton: 1);
    return;
  }
  this->m_pfnTouch = nullptr;
  switch ( eCode )
  {
    case BUTTON_PRESS:
      if ( this->m_toggle_state != TS_AT_TOP )
        goto LABEL_28;
      break;
    case BUTTON_RETURN:
      v7 = this->m_toggle_state;
      if ( v7 != TS_AT_TOP && v7 != TS_GOING_UP )
        return;
      break;
    case BUTTON_ACTIVATE:
      v10 = this->m_toggle_state;
      if ( v10 != TS_AT_BOTTOM && v10 != TS_GOING_DOWN )
        return;
LABEL_28:
      COutputEvent::FireOutput(this: &this->m_OnPressed, pActivator, pCaller: this, fDelay: 0.0);
      CBaseButton::ButtonActivate(this);
      return;
    default:
      return;
  }
  if ( this->m_sNoise.pszValue != nullptr )
  {
    CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
    EmitSound_t::EmitSound_t(this: &ep);
    pszValue = this->m_sNoise.pszValue;
    ep.m_nChannel = 2;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    ep.m_flVolume = 1.0;
    ep.m_SoundLevel = SNDLVL_NORM;
    v9 = CBaseEntity::entindex(this);
    CBaseEntity::EmitSound(&filter, iEntIndex: (int)v9, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  COutputEvent::FireOutput(this: &this->m_OnPressed, pActivator, pCaller: this, fDelay: 0.0);
  CBaseButton::ButtonReturn(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E6400
// Name: protected: void CBaseButton::InputPress(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::InputPress(CBaseButton *this, inputdata_t *inputdata)
{
  CBaseButton::Press(this, pActivator: inputdata->pActivator, eCode: BUTTON_PRESS);
}

//------------------------------------------------------------------------------
// Address: 0x100E6420
// Name: protected: void CBaseButton::InputPressIn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::InputPressIn(CBaseButton *this, inputdata_t *inputdata)
{
  CBaseButton::Press(this, pActivator: inputdata->pActivator, eCode: BUTTON_ACTIVATE);
}

//------------------------------------------------------------------------------
// Address: 0x100E6440
// Name: protected: void CBaseButton::InputPressOut(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::InputPressOut(CBaseButton *this, inputdata_t *inputdata)
{
  CBaseButton::Press(this, pActivator: inputdata->pActivator, eCode: BUTTON_RETURN);
}

//------------------------------------------------------------------------------
// Address: 0x100E6460
// Name: protected: virtual int CBaseButton::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseButton::OnTakeDamage(CBaseButton *this, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  int v5; // ebx
  unsigned int v6; // eax
  IHandleEntity *v7; // ecx
  unsigned int v8; // eax
  const char *pszValue; // eax
  edict_t *v10; // eax
  CBaseEntity *v11; // eax
  CBaseEntity *v13; // eax
  EmitSound_t ep; // [esp+10h] [ebp-68h] BYREF
  CPASAttenuationFilter filter; // [esp+58h] [ebp-20h] BYREF

  m_Index = this->m_hActivator.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  COutputEvent::FireOutput(this: &this->m_OnDamaged, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
  if ( (this->m_spawnflags.m_Value & 0x200) == 0 && this->m_iHealth.m_Value == 0 )
    return 0;
  v5 = CBaseButton::ButtonResponseToTouch(this);
  if ( v5 == 0 )
    return 0;
  v6 = info->m_hAttacker.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  this->m_hActivator.m_Index = v7 != nullptr ? v7->GetRefEHandle(this: v7)->m_Index : -1;
  v8 = this->m_hActivator.m_Index;
  if ( v8 == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity == nullptr
    || this->m_bLocked )
  {
    return 0;
  }
  this->m_pfnTouch = nullptr;
  if ( v5 != 2 )
  {
    v13 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
    COutputEvent::FireOutput(this: &this->m_OnPressed, pActivator: v13, pCaller: this, fDelay: 0.0);
    CBaseButton::ButtonActivate(this);
    return 0;
  }
  if ( this->m_sNoise.pszValue != nullptr )
  {
    CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
    EmitSound_t::EmitSound_t(this: &ep);
    pszValue = this->m_sNoise.pszValue;
    ep.m_nChannel = 2;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    ep.m_flVolume = 1.0;
    ep.m_SoundLevel = SNDLVL_NORM;
    v10 = CBaseEntity::entindex(this);
    CBaseEntity::EmitSound(&filter, iEntIndex: (int)v10, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
  COutputEvent::FireOutput(this: &this->m_OnPressed, pActivator: v11, pCaller: this, fDelay: 0.0);
  CBaseButton::ButtonReturn(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E6670
// Name: protected: void CBaseButton::ButtonUse(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::ButtonUse(
        CBaseButton *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  TOGGLE_STATE m_toggle_state; // eax
  const char *pszValue; // eax
  edict_t *v8; // eax
  CBaseEntity *v9; // eax
  CBaseEntity *v10; // eax
  EmitSound_t ep; // [esp+Ch] [ebp-68h] BYREF
  CPASAttenuationFilter filter; // [esp+54h] [ebp-20h] BYREF

  m_toggle_state = this->m_toggle_state;
  if ( m_toggle_state != TS_GOING_UP && m_toggle_state != TS_GOING_DOWN )
  {
    if ( this->m_bLocked )
    {
      CBaseButton::OnUseLocked(this, pActivator);
    }
    else
    {
      if ( pActivator != nullptr )
        this->m_hActivator.m_Index = pActivator->GetRefEHandle(this: pActivator)->m_Index;
      else
        this->m_hActivator.m_Index = -1;
      if ( this->m_toggle_state != TS_AT_TOP )
      {
        v10 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
        COutputEvent::FireOutput(this: &this->m_OnPressed, pActivator: v10, pCaller: this, fDelay: 0.0);
        CBaseButton::ButtonActivate(this);
      }
      else if ( (this->m_spawnflags.m_Value & 0x20) != 0 )
      {
        if ( this->m_sNoise.pszValue != nullptr )
        {
          CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
          EmitSound_t::EmitSound_t(this: &ep);
          pszValue = this->m_sNoise.pszValue;
          ep.m_nChannel = 2;
          ep.m_pSoundName = pszValue;
          if ( pszValue == nullptr )
            ep.m_pSoundName = locale;
          ep.m_flVolume = 1.0;
          ep.m_SoundLevel = SNDLVL_NORM;
          v8 = CBaseEntity::entindex(this);
          CBaseEntity::EmitSound(&filter, iEntIndex: (int)v8, params: &ep);
          CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
          CRecipientFilter::~CRecipientFilter(this: &filter);
        }
        v9 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
        COutputEvent::FireOutput(this: &this->m_OnPressed, pActivator: v9, pCaller: this, fDelay: 0.0);
        CBaseButton::ButtonReturn(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E67D0
// Name: protected: void CBaseButton::ButtonTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseButton::ButtonTouch(CBaseButton *this, CBaseEntity *pOther)
{
  int v3; // ebx
  const char *pszValue; // eax
  edict_t *v5; // eax
  CBaseEntity *v6; // eax
  CBaseEntity *v7; // eax
  EmitSound_t ep; // [esp+10h] [ebp-68h] BYREF
  CPASAttenuationFilter filter; // [esp+58h] [ebp-20h] BYREF

  if ( pOther->IsPlayer(this: pOther) )
  {
    this->m_hActivator.m_Index = pOther->GetRefEHandle(this: pOther)->m_Index;
    v3 = CBaseButton::ButtonResponseToTouch(this);
    if ( v3 != 0 )
    {
      if ( !UTIL_IsMasterTriggered(sMaster: this->m_sMaster, pActivator: pOther) || this->m_bLocked )
      {
        PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 1, fbutton: 1);
      }
      else
      {
        this->m_pfnTouch = nullptr;
        if ( v3 == 2 )
        {
          if ( this->m_sNoise.pszValue != nullptr )
          {
            CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
            EmitSound_t::EmitSound_t(this: &ep);
            pszValue = this->m_sNoise.pszValue;
            ep.m_nChannel = 2;
            ep.m_pSoundName = pszValue;
            if ( pszValue == nullptr )
              ep.m_pSoundName = locale;
            ep.m_flVolume = 1.0;
            ep.m_SoundLevel = SNDLVL_NORM;
            v5 = CBaseEntity::entindex(this);
            CBaseEntity::EmitSound(&filter, iEntIndex: (int)v5, params: &ep);
            CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
            CRecipientFilter::~CRecipientFilter(this: &filter);
          }
          v6 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
          COutputEvent::FireOutput(this: &this->m_OnPressed, pActivator: v6, pCaller: this, fDelay: 0.0);
          CBaseButton::ButtonReturn(this);
        }
        else
        {
          v7 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
          COutputEvent::FireOutput(this: &this->m_OnPressed, pActivator: v7, pCaller: this, fDelay: 0.0);
          CBaseButton::ButtonActivate(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6950
// Name: public: virtual void CRotButton::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRotButton::Spawn(CRotButton *this@<ecx>, int a2@<edi>)
{
  const char *v3; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4
  const char *v6; // eax
  float m_flMoveDistance; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  void (__thiscall *v10)(CBaseEntity *, CBaseEntity *); // edx
  CRotButton_vtbl *v11; // eax
  bool (__thiscall *CreateVPhysics)(CBaseEntity *); // edx
  char pDest[1024]; // [esp+4h] [ebp-404h] BYREF
  char pszValue[4]; // [esp+404h] [ebp-4h] BYREF

  if ( this->m_sounds != 0 )
  {
    V_snprintf(pDest, maxLen: 1024, pFormat: "Buttons.snd%d", this->m_sounds);
    AllocPooledString(pszValue);
    v3 = *(const char **)pszValue;
    this->m_sNoise.pszValue = *(const char **)pszValue;
    if ( v3 == nullptr )
      v3 = locale;
    CBaseEntity::PrecacheScriptSound(soundname: v3);
  }
  else
  {
    this->m_sNoise.pszValue = nullptr;
  }
  CBaseToggle::AxisDir(this);
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
  {
    v4 = this->m_vecMoveAng.y * -1.0;
    v5 = this->m_vecMoveAng.z * -1.0;
    this->m_vecMoveAng.x = this->m_vecMoveAng.x * -1.0;
    this->m_vecMoveAng.y = v4;
    this->m_vecMoveAng.z = v5;
  }
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    this->m_iEFlags |= 0x40000u;
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  }
  v6 = *(const char **)((int (__thiscall *)(CRotButton *, char *, int))this->GetModelName)(
                         a1: this,
                         a2: pszValue,
                         a3: a2);
  if ( v6 == nullptr )
    v6 = locale;
  this->SetModel(this, a2: v6);
  if ( this->m_flSpeed == 0.0 )
    this->m_flSpeed = 40.0;
  if ( this->m_flWait == 0.0 )
    this->m_flWait = 1.0;
  if ( this->m_iHealth.m_Value > 0 && this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  this->m_toggle_state = TS_AT_BOTTOM;
  this->m_vecAngle1.x = this->m_angRotation.m_Value.x;
  this->m_vecAngle1.y = this->m_angRotation.m_Value.y;
  this->m_vecAngle1.z = this->m_angRotation.m_Value.z;
  m_flMoveDistance = this->m_flMoveDistance;
  v8 = (float)(this->m_vecMoveAng.y * m_flMoveDistance) + this->m_angRotation.m_Value.y;
  v9 = this->m_angRotation.m_Value.z + (float)(this->m_vecMoveAng.z * m_flMoveDistance);
  this->m_vecAngle2.x = this->m_angRotation.m_Value.x + (float)(m_flMoveDistance * this->m_vecMoveAng.x);
  this->m_vecAngle2.y = v8;
  this->m_vecAngle2.z = v9;
  v10 = (this->m_spawnflags.m_Value & 0x100) != 0
      ? (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBaseButton::ButtonTouch
      : nullptr;
  this->m_fStayPushed = this->m_flWait == -1.0;
  v11 = this->__vftable;
  this->m_pfnTouch = v10;
  CreateVPhysics = v11->CreateVPhysics;
  this->m_fRotating = true;
  this->m_pfnUse = (void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float))CBaseButton::ButtonUse;
  CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E6BE0
// Name: public: virtual void CMomentaryRotButton::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMomentaryRotButton::Use(
        CMomentaryRotButton *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  float v6; // xmm0_4
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  CBaseEntity *v9; // ecx
  variant_t v10; // [esp-14h] [ebp-44h] BYREF
  float fireDelay; // [esp+0h] [ebp-30h]
  CMomentaryRotButton *v12; // [esp+4h] [ebp-2Ch]
  CMomentaryRotButton *thinkTime; // [esp+8h] [ebp-28h]
  CNetworkVectorXYZBase<QAngle,CBaseEntity::NetworkVar_m_angRotation> *fDelay; // [esp+Ch] [ebp-24h]
  variant_t __that; // [esp+18h] [ebp-18h] BYREF
  float flPos; // [esp+2Ch] [ebp-4h]
  bool flDist; // [esp+38h] [ebp+8h]

  if ( !this->m_bDisabled )
  {
    if ( this->m_bLocked )
    {
      if ( CBaseButton::OnUseLocked(this, pActivator) != 0 && (this->m_spawnflags.m_Value & 0x2000) != 0 )
      {
        v6 = 2.0 / this->m_flMoveDistance;
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: this,
          action: "_DisableUpdateTarget",
          fireDelay: 0.0,
          pActivator: this,
          pCaller: this,
          outputID: 0);
        fDelay = nullptr;
        thinkTime = this;
        v12 = this;
        __that.flVal = v6;
        fireDelay = 0.0099999998;
        __that.eVal.m_Index = -1;
        __that.fieldType = FIELD_FLOAT;
        variant_t::variant_t(this: &v10, &__that);
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: this,
          targetInput: "SetPosition",
          Value: v10,
          fireDelay,
          pActivator: v12,
          pCaller: thinkTime,
          outputID: (int)fDelay);
        fDelay = nullptr;
        thinkTime = this;
        v12 = this;
        __that.iVal = 0;
        fireDelay = 0.1;
        __that.fieldType = FIELD_FLOAT;
        variant_t::variant_t(this: &v10, &__that);
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: this,
          targetInput: "SetPosition",
          Value: v10,
          fireDelay,
          pActivator: v12,
          pCaller: thinkTime,
          outputID: (int)fDelay);
        fDelay = nullptr;
        thinkTime = this;
        v12 = this;
        __that.flVal = v6 * 0.5;
        fireDelay = 0.2;
        __that.fieldType = FIELD_FLOAT;
        variant_t::variant_t(this: &v10, &__that);
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: this,
          targetInput: "SetPosition",
          Value: v10,
          fireDelay,
          pActivator: v12,
          pCaller: thinkTime,
          outputID: (int)fDelay);
        fDelay = nullptr;
        thinkTime = this;
        v12 = this;
        __that.iVal = 0;
        fireDelay = 0.30000001;
        __that.fieldType = FIELD_FLOAT;
        variant_t::variant_t(this: &v10, &__that);
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: this,
          targetInput: "SetPosition",
          Value: v10,
          fireDelay,
          pActivator: v12,
          pCaller: thinkTime,
          outputID: (int)fDelay);
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: this,
          action: "_EnableUpdateTarget",
          fireDelay: 0.5,
          pActivator: this,
          pCaller: this,
          outputID: 0);
      }
    }
    else
    {
      flDist = false;
      if ( this->m_lastUsed == 0 )
      {
        this->m_direction = -this->m_direction;
        m_Index = this->m_hActivator.m_Index;
        flDist = true;
        if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        COutputEvent::FireOutput(this: &this->m_OnPressed, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
      }
      fDelay = &this->m_angRotation;
      this->m_lastUsed = 1;
      flPos = CMomentaryRotButton::GetPos(this, vecAngles: &fDelay->m_Value);
      CMomentaryRotButton::UpdateSelf(this, value: flPos, bPlaySound: flDist);
      if ( this->m_pfnThink == nullptr )
      {
        CBaseEntity::ThinkSet(
          this,
          func: (void (__thiscall *)(CBaseEntity *))CMomentaryRotButton::UpdateThink,
          thinkTime: 0.0,
          szContext: nullptr);
        fDelay = nullptr;
        thinkTime = (CMomentaryRotButton *)v9;
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7580
// Name: public: virtual void CBaseButton::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CBaseButton::Spawn(CBaseButton *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int m_sounds; // eax
  const char *v6; // eax
  float y; // xmm0_4
  string_t (__thiscall *GetModelName)(struct CBaseEntity *); // edx
  const char *v9; // eax
  Vector *v10; // eax
  float z; // ecx
  float x; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm3_4
  __int128 v19; // xmm0
  int m_Value; // eax
  CBaseButton_vtbl *v21; // edx
  char v23[1028]; // [esp+18h] [ebp-43Ch] BYREF
  QAngle v24; // [esp+41Ch] [ebp-38h] BYREF
  __int128 angMoveDir; // [esp+428h] [ebp-2Ch] OVERLAPPED
  _DWORD v26[4]; // [esp+444h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+454h] [ebp+0h]

  v26[1] = a2;
  v26[2] = retaddr;
  m_sounds = this->m_sounds;
  if ( m_sounds != 0 )
  {
    V_snprintf(pDest: v23, maxLen: 1024, pFormat: "Buttons.snd%d", m_sounds);
    AllocPooledString(pszValue: (const char *)v26);
    v6 = (const char *)v26[0];
    this->m_sNoise.pszValue = (const char *)v26[0];
    if ( v6 == nullptr )
      v6 = locale;
    CBaseEntity::PrecacheScriptSound(soundname: v6);
  }
  else
  {
    this->m_sNoise.pszValue = nullptr;
  }
  ((void (__thiscall *)(CBaseButton *, int, int))this->Precache)(a1: this, a2: a3, a3: a4);
  if ( (this->m_spawnflags.m_Value & 0x1000) != 0 )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CBaseButton::ButtonSpark,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
  }
  v24.x = this->m_vecMoveDir.x;
  y = this->m_vecMoveDir.y;
  v26[0] = &this->m_vecMoveDir;
  v24.y = y;
  v24.z = this->m_vecMoveDir.z;
  AngleVectors(angles: &v24, forward: &this->m_vecMoveDir);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  GetModelName = this->GetModelName;
  v26[0] = v26;
  v9 = *(const char **)((int (__thiscall *)(CBaseButton *))GetModelName)(a1: this);
  if ( v9 == nullptr )
    v9 = locale;
  this->SetModel(this, a2: v9);
  if ( this->m_flSpeed == 0.0 )
    this->m_flSpeed = 40.0;
  if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  if ( this->m_flWait == 0.0 )
    this->m_flWait = 1.0;
  if ( this->m_flLip == 0.0 )
    this->m_flLip = 4.0;
  this->m_toggle_state = TS_AT_BOTTOM;
  this->m_vecPosition1.x = this->m_vecOrigin.m_Value.x;
  this->m_vecPosition1.y = this->m_vecOrigin.m_Value.y;
  this->m_vecPosition1.z = this->m_vecOrigin.m_Value.z;
  v10 = AllocTempVector();
  v10->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
  v10->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
  v10->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
  z = v10->z;
  x = this->m_vecMoveDir.x;
  v13 = this->m_vecMoveDir.z;
  *(_QWORD *)((char *)&angMoveDir + 4) = *(_QWORD *)&v10->x;
  *((float *)&angMoveDir + 3) = z;
  v14 = this->m_vecMoveDir.y;
  v15 = (float)((float)(fabs((float)(*((float *)&angMoveDir + 2) - 2.0) * v14)
                      + fabs((float)(*((float *)&angMoveDir + 1) - 2.0) * x))
              + fabs((float)(z - 2.0) * v13))
      - this->m_flLip;
  v16 = (float)(v15 * v14) + this->m_vecPosition1.y;
  v17 = this->m_vecPosition1.x;
  this->m_vecPosition2.z = (float)(v15 * v13) + this->m_vecPosition1.z;
  this->m_vecPosition2.y = v16;
  this->m_vecPosition2.x = v17 + (float)(v15 * x);
  v18 = this->m_vecPosition1.x;
  v19 = 0;
  *(float *)&v19 = fsqrt(
                     (float)((float)((float)(v16 - this->m_vecPosition1.y) * (float)(v16 - this->m_vecPosition1.y))
                           + (float)((float)(this->m_vecPosition2.z - this->m_vecPosition1.z)
                                   * (float)(this->m_vecPosition2.z - this->m_vecPosition1.z)))
                   + (float)((float)(this->m_vecPosition2.x - v18) * (float)(this->m_vecPosition2.x - v18)));
  angMoveDir = v19;
  if ( *(float *)&v19 < 1.0 || (this->m_spawnflags.m_Value & 1) != 0 )
  {
    this->m_vecPosition2.x = v18;
    this->m_vecPosition2.y = this->m_vecPosition1.y;
    this->m_vecPosition2.z = this->m_vecPosition1.z;
  }
  this->m_fStayPushed = this->m_flWait == -1.0;
  m_Value = this->m_spawnflags.m_Value;
  this->m_fRotating = false;
  if ( (m_Value & 0x800) != 0 )
    this->m_bLocked = true;
  this->m_pfnUse = (m_Value & 0x400) != 0
                 ? (void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float))CBaseButton::ButtonUse
                 : nullptr;
  v21 = this->__vftable;
  this->m_pfnTouch = (m_Value & 0x100) != 0
                   ? (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBaseButton::ButtonTouch
                   : nullptr;
  v21->CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x10400AB0
// Name: CBaseButton_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseButton_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseButton>(__formal: nullptr);
  CBaseButton_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400B00
// Name: DT_BaseButton::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseButton::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseButton::g_SendTable);
  return atexit(func: DT_BaseButton::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10400B20
// Name: DT_BaseButton::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseButton::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseButton::ignored>();
  DT_BaseButton::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400B50
// Name: CMomentaryRotButton_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMomentaryRotButton_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMomentaryRotButton>(__formal: nullptr);
  CMomentaryRotButton_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A140
// Name: DT_BaseButton::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseButton::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseButton::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100E58D0
// Name: struct datamap_t __near * DataMapInit<class CMomentaryRotButton>(class CMomentaryRotButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMomentaryRotButton>()
{
  char *Name; // eax

  if ( (_S4_17 & 1) == 0 )
  {
    _S4_17 |= 1u;
    nameHolder_107.m_pszBase = "CMomentaryRotButton";
    nameHolder_107.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_107.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_107.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_107.m_Names.m_Size = 0;
    nameHolder_107.m_Names.m_pElements = nullptr;
    nameHolder_107.m_nLenBase = 19;
    atexit(func: DataMapInit_CMomentaryRotButton__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMomentaryRotButton::m_DataMap.baseMap = &CBaseButton::m_DataMap;
  if ( (_S4_17 & 2) == 0 )
  {
    _S4_17 |= 2u;
    dataDesc_104[11].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_107,
                                   pszIdentifier: "UseMoveDone");
    dataDesc_104[11].flags = 32;
    dataDesc_104[11].fieldOffset = 0;
    dataDesc_104[11].fieldSize = 1;
    dataDesc_104[11].externalName = nullptr;
    dataDesc_104[11].pSaveRestoreOps = nullptr;
    dataDesc_104[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMomentaryRotButton::UseMoveDone;
    *(_QWORD *)&dataDesc_104[11].td = 0;
    *(_QWORD *)&dataDesc_104[11].override_field = 0;
    *(_QWORD *)&dataDesc_104[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_104[11].flatOffset[1] = 0;
    dataDesc_104[12].fieldType = FIELD_VOID;
    dataDesc_104[12].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_107,
                                   pszIdentifier: "ReturnMoveDone");
    dataDesc_104[12].fieldOffset = 0;
    dataDesc_104[12].fieldSize = 1;
    dataDesc_104[12].flags = 32;
    dataDesc_104[12].externalName = nullptr;
    dataDesc_104[12].pSaveRestoreOps = nullptr;
    dataDesc_104[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMomentaryRotButton::ReturnMoveDone;
    *(_QWORD *)&dataDesc_104[12].td = 0;
    *(_QWORD *)&dataDesc_104[12].override_field = 0;
    *(_QWORD *)&dataDesc_104[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_104[12].flatOffset[1] = 0;
    dataDesc_104[13].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_107, pszIdentifier: "SetPositionMoveDone");
    dataDesc_104[13].fieldSize = 1;
    dataDesc_104[13].fieldName = Name;
    dataDesc_104[13].fieldOffset = 0;
    dataDesc_104[13].flags = 32;
    dataDesc_104[13].externalName = nullptr;
    dataDesc_104[13].pSaveRestoreOps = nullptr;
    dataDesc_104[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMomentaryRotButton::SetPositionMoveDone;
    *(_QWORD *)&dataDesc_104[13].td = 0;
    *(_QWORD *)&dataDesc_104[13].override_field = 0;
    *(_QWORD *)&dataDesc_104[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_104[13].flatOffset[1] = 0;
    dataDesc_104[14].fieldType = FIELD_VOID;
    dataDesc_104[14].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_107,
                                   pszIdentifier: "UpdateThink");
    dataDesc_104[14].fieldSize = 1;
    dataDesc_104[14].fieldOffset = 0;
    dataDesc_104[14].flags = 32;
    dataDesc_104[14].externalName = nullptr;
    dataDesc_104[14].pSaveRestoreOps = nullptr;
    dataDesc_104[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMomentaryRotButton::UpdateThink;
    *(_QWORD *)&dataDesc_104[14].td = 0;
    *(_QWORD *)&dataDesc_104[14].override_field = 0;
    *(_QWORD *)&dataDesc_104[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_104[14].flatOffset[1] = 0;
    dataDesc_104[15].fieldType = FIELD_FLOAT;
    dataDesc_104[15].fieldName = "InputSetPosition";
    dataDesc_104[15].fieldOffset = 0;
    dataDesc_104[15].fieldSize = 1;
    dataDesc_104[15].flags = 8;
    dataDesc_104[15].externalName = "SetPosition";
    dataDesc_104[15].pSaveRestoreOps = nullptr;
    *(_QWORD *)&dataDesc_104[15].td = 0;
    *(_QWORD *)&dataDesc_104[15].override_field = 0;
    *(_QWORD *)&dataDesc_104[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_104[15].flatOffset[1] = 0;
    dataDesc_104[16].fieldSize = 1;
    *(_QWORD *)&dataDesc_104[16].td = 0;
    *(_QWORD *)&dataDesc_104[16].override_field = 0;
    *(_QWORD *)&dataDesc_104[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_104[16].flatOffset[1] = 0;
    dataDesc_104[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_104[17].td = 0;
    *(_QWORD *)&dataDesc_104[17].override_field = 0;
    *(_QWORD *)&dataDesc_104[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_104[17].flatOffset[1] = 0;
    dataDesc_104[16].flags = 8;
    dataDesc_104[18].flags = 8;
    *(_QWORD *)&dataDesc_104[18].td = 0;
    *(_QWORD *)&dataDesc_104[18].override_field = 0;
    *(_QWORD *)&dataDesc_104[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_104[18].flatOffset[1] = 0;
    dataDesc_104[17].flags = 8;
    dataDesc_104[18].fieldSize = 1;
    dataDesc_104[19].fieldSize = 1;
    dataDesc_104[19].flags = 22;
    dataDesc_104[20].fieldSize = 1;
    *(_QWORD *)&dataDesc_104[19].inputFunc = 0;
    *(_QWORD *)&dataDesc_104[19].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_104[19].override_count = 0;
    *(_QWORD *)dataDesc_104[19].flatOffset = 0;
    dataDesc_104[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMomentaryRotButton::InputSetPosition;
    dataDesc_104[16].fieldType = FIELD_FLOAT;
    dataDesc_104[16].fieldName = "InputSetPositionImmediately";
    dataDesc_104[16].fieldOffset = 0;
    dataDesc_104[16].externalName = "SetPositionImmediately";
    dataDesc_104[16].pSaveRestoreOps = nullptr;
    dataDesc_104[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMomentaryRotButton::InputSetPositionImmediately;
    dataDesc_104[17].fieldType = FIELD_VOID;
    dataDesc_104[17].fieldName = "InputDisableUpdateTarget";
    dataDesc_104[17].fieldOffset = 0;
    dataDesc_104[17].externalName = "_DisableUpdateTarget";
    dataDesc_104[17].pSaveRestoreOps = nullptr;
    dataDesc_104[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMomentaryRotButton::InputDisableUpdateTarget;
    dataDesc_104[18].fieldType = FIELD_VOID;
    dataDesc_104[18].fieldName = "InputEnableUpdateTarget";
    dataDesc_104[18].fieldOffset = 0;
    dataDesc_104[18].externalName = "_EnableUpdateTarget";
    dataDesc_104[18].pSaveRestoreOps = nullptr;
    dataDesc_104[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMomentaryRotButton::InputEnableUpdateTarget;
    dataDesc_104[19].fieldType = FIELD_CUSTOM;
    dataDesc_104[19].fieldName = "m_Position";
    dataDesc_104[19].fieldOffset = 1180;
    dataDesc_104[19].externalName = "Position";
    dataDesc_104[19].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_104[19].flatGroup = 0;
    dataDesc_104[20].fieldType = FIELD_CUSTOM;
    dataDesc_104[20].fieldName = "m_OnUnpressed";
    dataDesc_104[20].fieldOffset = 1204;
    dataDesc_104[20].flags = 22;
    dataDesc_104[20].externalName = "OnUnpressed";
    dataDesc_104[20].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_104[20].inputFunc = 0;
    *(_QWORD *)&dataDesc_104[20].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_104[20].override_count = 0;
    *(_QWORD *)dataDesc_104[20].flatOffset = 0;
    *(_DWORD *)&dataDesc_104[20].flatGroup = 0;
    dataDesc_104[21].fieldSize = 1;
    dataDesc_104[21].flags = 22;
    dataDesc_104[21].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_104[21].inputFunc = 0;
    *(_QWORD *)&dataDesc_104[21].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_104[21].override_count = 0;
    *(_QWORD *)dataDesc_104[21].flatOffset = 0;
    dataDesc_104[22].fieldType = FIELD_CUSTOM;
    dataDesc_104[22].fieldSize = 1;
    dataDesc_104[23].fieldType = FIELD_CUSTOM;
    dataDesc_104[21].pSaveRestoreOps = eventFuncs;
    dataDesc_104[22].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_104[22].inputFunc = 0;
    *(_QWORD *)&dataDesc_104[22].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_104[22].override_count = 0;
    *(_QWORD *)dataDesc_104[22].flatOffset = 0;
    dataDesc_104[23].pSaveRestoreOps = eventFuncs;
    dataDesc_104[22].flags = 22;
    dataDesc_104[23].fieldSize = 1;
    dataDesc_104[23].flags = 22;
    *(_QWORD *)&dataDesc_104[23].inputFunc = 0;
    *(_QWORD *)&dataDesc_104[23].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_104[23].override_count = 0;
    *(_QWORD *)dataDesc_104[23].flatOffset = 0;
    dataDesc_104[24].fieldSize = 1;
    dataDesc_104[24].flags = 8;
    dataDesc_104[25].fieldSize = 1;
    *(_QWORD *)&dataDesc_104[24].td = 0;
    *(_QWORD *)&dataDesc_104[24].override_field = 0;
    *(_QWORD *)&dataDesc_104[24].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_104[24].flatOffset[1] = 0;
    dataDesc_104[21].fieldName = "m_OnFullyClosed";
    dataDesc_104[21].fieldOffset = 1252;
    dataDesc_104[21].externalName = "OnFullyClosed";
    *(_DWORD *)&dataDesc_104[21].flatGroup = 0;
    dataDesc_104[22].fieldName = "m_OnFullyOpen";
    dataDesc_104[22].fieldOffset = 1228;
    dataDesc_104[22].externalName = "OnFullyOpen";
    *(_DWORD *)&dataDesc_104[22].flatGroup = 0;
    dataDesc_104[23].fieldName = "m_OnReachedPosition";
    dataDesc_104[23].fieldOffset = 1276;
    dataDesc_104[23].externalName = "OnReachedPosition";
    *(_DWORD *)&dataDesc_104[23].flatGroup = 0;
    dataDesc_104[24].fieldType = FIELD_VOID;
    dataDesc_104[24].fieldName = "InputEnable";
    dataDesc_104[24].fieldOffset = 0;
    dataDesc_104[24].externalName = "Enable";
    dataDesc_104[24].pSaveRestoreOps = nullptr;
    dataDesc_104[24].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMomentaryRotButton::InputEnable;
    dataDesc_104[25].fieldType = FIELD_VOID;
    dataDesc_104[25].fieldName = "InputDisable";
    dataDesc_104[25].fieldOffset = 0;
    dataDesc_104[25].flags = 8;
    dataDesc_104[25].externalName = "Disable";
    dataDesc_104[25].pSaveRestoreOps = nullptr;
    dataDesc_104[25].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMomentaryRotButton::InputDisable;
    *(_QWORD *)&dataDesc_104[25].td = 0;
    *(_QWORD *)&dataDesc_104[25].override_field = 0;
    *(_QWORD *)&dataDesc_104[25].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_104[25].flatOffset[1] = 0;
    dataDesc_104[26].fieldType = FIELD_BOOLEAN;
    dataDesc_104[26].fieldName = "m_bDisabled";
    dataDesc_104[26].fieldOffset = 1176;
    dataDesc_104[26].fieldSize = 1;
    dataDesc_104[26].flags = 2;
    dataDesc_104[26].fieldTolerance = 0.0;
    dataDesc_104[26].externalName = nullptr;
    dataDesc_104[26].pSaveRestoreOps = nullptr;
    dataDesc_104[26].inputFunc = nullptr;
    dataDesc_104[26].td = nullptr;
    dataDesc_104[26].fieldSizeInBytes = 1;
    dataDesc_104[26].override_field = nullptr;
    dataDesc_104[26].override_count = 0;
    *(_QWORD *)dataDesc_104[26].flatOffset = 0;
    *(_DWORD *)&dataDesc_104[26].flatGroup = 0;
  }
  CMomentaryRotButton::m_DataMap.dataNumFields = 26;
  CMomentaryRotButton::m_DataMap.dataDesc = &dataDesc_104[1];
  return &CMomentaryRotButton::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E6E70
// Name: struct datamap_t __near * DataMapInit<class CBaseButton>(class CBaseButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseButton>()
{
  char *Name; // eax

  if ( (_S2_59 & 1) == 0 )
  {
    _S2_59 |= 1u;
    nameHolder_108.m_pszBase = "CBaseButton";
    nameHolder_108.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_108.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_108.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_108.m_Names.m_Size = 0;
    nameHolder_108.m_Names.m_pElements = nullptr;
    nameHolder_108.m_nLenBase = 11;
    atexit(func: DataMapInit_CBaseButton__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseButton::m_DataMap.baseMap = &CBaseToggle::m_DataMap;
  if ( (_S2_59 & 2) == 0 )
  {
    _S2_59 |= 2u;
    dataDesc_105[13].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_108,
                                   pszIdentifier: "ButtonTouch");
    dataDesc_105[13].flags = 32;
    dataDesc_105[13].fieldOffset = 0;
    dataDesc_105[13].fieldSize = 1;
    dataDesc_105[13].externalName = nullptr;
    dataDesc_105[13].pSaveRestoreOps = nullptr;
    dataDesc_105[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseButton::ButtonTouch;
    *(_QWORD *)&dataDesc_105[13].td = 0;
    *(_QWORD *)&dataDesc_105[13].override_field = 0;
    *(_QWORD *)&dataDesc_105[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[13].flatOffset[1] = 0;
    dataDesc_105[14].fieldType = FIELD_VOID;
    dataDesc_105[14].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_108,
                                   pszIdentifier: "ButtonSpark");
    dataDesc_105[14].fieldOffset = 0;
    dataDesc_105[14].fieldSize = 1;
    dataDesc_105[14].flags = 32;
    dataDesc_105[14].externalName = nullptr;
    dataDesc_105[14].pSaveRestoreOps = nullptr;
    dataDesc_105[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseButton::ButtonSpark;
    *(_QWORD *)&dataDesc_105[14].td = 0;
    *(_QWORD *)&dataDesc_105[14].override_field = 0;
    *(_QWORD *)&dataDesc_105[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[14].flatOffset[1] = 0;
    dataDesc_105[15].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_108, pszIdentifier: "TriggerAndWait");
    dataDesc_105[15].fieldSize = 1;
    dataDesc_105[15].fieldName = Name;
    dataDesc_105[15].fieldOffset = 0;
    dataDesc_105[15].flags = 32;
    dataDesc_105[15].externalName = nullptr;
    dataDesc_105[15].pSaveRestoreOps = nullptr;
    dataDesc_105[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseButton::TriggerAndWait;
    *(_QWORD *)&dataDesc_105[15].td = 0;
    *(_QWORD *)&dataDesc_105[15].override_field = 0;
    *(_QWORD *)&dataDesc_105[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[15].flatOffset[1] = 0;
    dataDesc_105[16].fieldType = FIELD_VOID;
    dataDesc_105[16].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_108,
                                   pszIdentifier: "ButtonReturn");
    dataDesc_105[16].flags = 32;
    dataDesc_105[16].fieldOffset = 0;
    dataDesc_105[16].fieldSize = 1;
    dataDesc_105[16].externalName = nullptr;
    dataDesc_105[16].pSaveRestoreOps = nullptr;
    dataDesc_105[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseButton::ButtonReturn;
    *(_QWORD *)&dataDesc_105[16].td = 0;
    *(_QWORD *)&dataDesc_105[16].override_field = 0;
    *(_QWORD *)&dataDesc_105[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[16].flatOffset[1] = 0;
    dataDesc_105[17].fieldType = FIELD_VOID;
    dataDesc_105[17].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_108,
                                   pszIdentifier: "ButtonBackHome");
    dataDesc_105[17].fieldOffset = 0;
    dataDesc_105[17].fieldSize = 1;
    dataDesc_105[17].flags = 32;
    dataDesc_105[17].externalName = nullptr;
    dataDesc_105[17].pSaveRestoreOps = nullptr;
    dataDesc_105[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseButton::ButtonBackHome;
    *(_QWORD *)&dataDesc_105[17].td = 0;
    *(_QWORD *)&dataDesc_105[17].override_field = 0;
    *(_QWORD *)&dataDesc_105[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[17].flatOffset[1] = 0;
    dataDesc_105[18].fieldType = FIELD_VOID;
    dataDesc_105[18].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_108,
                                   pszIdentifier: "ButtonUse");
    dataDesc_105[18].fieldSize = 1;
    dataDesc_105[18].flags = 32;
    *(_QWORD *)&dataDesc_105[18].td = 0;
    *(_QWORD *)&dataDesc_105[18].override_field = 0;
    *(_QWORD *)&dataDesc_105[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[18].flatOffset[1] = 0;
    dataDesc_105[19].fieldSize = 1;
    dataDesc_105[19].flags = 8;
    *(_QWORD *)&dataDesc_105[19].td = 0;
    *(_QWORD *)&dataDesc_105[19].override_field = 0;
    *(_QWORD *)&dataDesc_105[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[19].flatOffset[1] = 0;
    dataDesc_105[20].fieldSize = 1;
    dataDesc_105[20].flags = 8;
    dataDesc_105[21].fieldSize = 1;
    *(_QWORD *)&dataDesc_105[20].td = 0;
    *(_QWORD *)&dataDesc_105[20].override_field = 0;
    *(_QWORD *)&dataDesc_105[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[20].flatOffset[1] = 0;
    dataDesc_105[18].fieldOffset = 0;
    dataDesc_105[18].externalName = nullptr;
    dataDesc_105[18].pSaveRestoreOps = nullptr;
    dataDesc_105[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseButton::ButtonUse;
    dataDesc_105[19].fieldType = FIELD_VOID;
    dataDesc_105[19].fieldName = "InputLock";
    dataDesc_105[19].fieldOffset = 0;
    dataDesc_105[19].externalName = "Lock";
    dataDesc_105[19].pSaveRestoreOps = nullptr;
    dataDesc_105[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerCameraMultiplayer::InputDisable;
    dataDesc_105[20].fieldType = FIELD_VOID;
    dataDesc_105[20].fieldName = "InputUnlock";
    dataDesc_105[20].fieldOffset = 0;
    dataDesc_105[20].externalName = "Unlock";
    dataDesc_105[20].pSaveRestoreOps = nullptr;
    dataDesc_105[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseTrigger::InputDisable;
    dataDesc_105[21].fieldType = FIELD_VOID;
    dataDesc_105[21].fieldName = "InputPress";
    dataDesc_105[21].fieldOffset = 0;
    dataDesc_105[21].flags = 8;
    dataDesc_105[21].externalName = "Press";
    dataDesc_105[21].pSaveRestoreOps = nullptr;
    dataDesc_105[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseButton::InputPress;
    *(_QWORD *)&dataDesc_105[21].td = 0;
    *(_QWORD *)&dataDesc_105[21].override_field = 0;
    *(_QWORD *)&dataDesc_105[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[21].flatOffset[1] = 0;
    dataDesc_105[22].fieldType = FIELD_VOID;
    dataDesc_105[22].fieldName = "InputPressIn";
    dataDesc_105[22].fieldOffset = 0;
    dataDesc_105[22].fieldSize = 1;
    dataDesc_105[22].flags = 8;
    dataDesc_105[22].externalName = "PressIn";
    dataDesc_105[22].pSaveRestoreOps = nullptr;
    *(_QWORD *)&dataDesc_105[22].td = 0;
    *(_QWORD *)&dataDesc_105[22].override_field = 0;
    *(_QWORD *)&dataDesc_105[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[22].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_105[23].td = 0;
    *(_QWORD *)&dataDesc_105[23].override_field = 0;
    *(_QWORD *)&dataDesc_105[23].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_105[23].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_105[24].inputFunc = 0;
    *(_QWORD *)&dataDesc_105[24].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_105[24].override_count = 0;
    *(_QWORD *)dataDesc_105[24].flatOffset = 0;
    *(_QWORD *)&dataDesc_105[25].inputFunc = 0;
    *(_QWORD *)&dataDesc_105[25].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_105[25].override_count = 0;
    *(_QWORD *)dataDesc_105[25].flatOffset = 0;
    dataDesc_105[23].fieldSize = 1;
    dataDesc_105[23].flags = 8;
    *(_QWORD *)&dataDesc_105[26].inputFunc = 0;
    *(_QWORD *)&dataDesc_105[26].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_105[26].override_count = 0;
    *(_QWORD *)dataDesc_105[26].flatOffset = 0;
    dataDesc_105[22].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseButton::InputPressIn;
    dataDesc_105[23].fieldType = FIELD_VOID;
    dataDesc_105[23].fieldName = "InputPressOut";
    dataDesc_105[23].fieldOffset = 0;
    dataDesc_105[23].externalName = "PressOut";
    dataDesc_105[23].pSaveRestoreOps = nullptr;
    dataDesc_105[23].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseButton::InputPressOut;
    dataDesc_105[24].fieldType = FIELD_CUSTOM;
    dataDesc_105[24].fieldName = "m_OnDamaged";
    dataDesc_105[24].fieldOffset = 1052;
    dataDesc_105[24].fieldSize = 1;
    dataDesc_105[24].flags = 22;
    dataDesc_105[24].externalName = "OnDamaged";
    dataDesc_105[24].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_105[24].flatGroup = 0;
    dataDesc_105[25].fieldType = FIELD_CUSTOM;
    dataDesc_105[25].fieldName = "m_OnPressed";
    dataDesc_105[25].fieldOffset = 1076;
    dataDesc_105[25].fieldSize = 1;
    dataDesc_105[25].flags = 22;
    dataDesc_105[25].externalName = "OnPressed";
    dataDesc_105[25].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_105[25].flatGroup = 0;
    dataDesc_105[26].fieldType = FIELD_CUSTOM;
    dataDesc_105[26].fieldName = "m_OnUseLocked";
    dataDesc_105[26].fieldOffset = 1100;
    dataDesc_105[26].fieldSize = 1;
    dataDesc_105[26].flags = 22;
    dataDesc_105[26].externalName = "OnUseLocked";
    dataDesc_105[26].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_105[26].flatGroup = 0;
    dataDesc_105[27].fieldType = FIELD_CUSTOM;
    dataDesc_105[27].fieldName = "m_OnIn";
    dataDesc_105[27].fieldOffset = 1124;
    dataDesc_105[27].fieldSize = 1;
    dataDesc_105[27].flags = 22;
    dataDesc_105[27].externalName = "OnIn";
    dataDesc_105[27].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_105[27].inputFunc = 0;
    *(_QWORD *)&dataDesc_105[27].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_105[27].override_count = 0;
    *(_QWORD *)dataDesc_105[27].flatOffset = 0;
    *(_DWORD *)&dataDesc_105[27].flatGroup = 0;
    dataDesc_105[28].fieldType = FIELD_CUSTOM;
    dataDesc_105[28].fieldName = "m_OnOut";
    dataDesc_105[28].fieldOffset = 1148;
    *(_DWORD *)&dataDesc_105[28].fieldSize = 1441793;
    dataDesc_105[28].externalName = "OnOut";
    dataDesc_105[28].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_105[28].inputFunc = 0;
    *(_QWORD *)&dataDesc_105[28].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_105[28].override_count = 0;
    *(_QWORD *)dataDesc_105[28].flatOffset = 0;
    *(_DWORD *)&dataDesc_105[28].flatGroup = 0;
  }
  CBaseButton::m_DataMap.dataNumFields = 28;
  CBaseButton::m_DataMap.dataDesc = &dataDesc_105[1];
  return &CBaseButton::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10400B60
// Name: _dynamic_initializer_for__momentary_rot_button__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__momentary_rot_button__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CMomentaryRotButton> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &momentary_rot_button,
           a3: "momentary_rot_button");
}

//------------------------------------------------------------------------------
// Address: 0x1041A150
// Name: _ServerClassInit_DT_BaseButton::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseButton::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_31;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A170
// Name: _DataMapInit_CBaseButton__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseButton__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_108);
}

//------------------------------------------------------------------------------
// Address: 0x1041A180
// Name: _DataMapInit_CMomentaryRotButton__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMomentaryRotButton__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_107);
}

//------------------------------------------------------------------------------
// Address: 0x1041A190
// Name: _dynamic_atexit_destructor_for__g_EntityListPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EntityListPool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_EntityListPool);
}

//------------------------------------------------------------------------------
// Address: 0x1041A1A0
// Name: _dynamic_atexit_destructor_for__EventQueuePrioritizedEvent_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__EventQueuePrioritizedEvent_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &EventQueuePrioritizedEvent_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x1041A1B0
// Name: _dynamic_atexit_destructor_for__dumpeventqueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dumpeventqueue__()
{
  ConCommand::~ConCommand(this: &dumpeventqueue);
}

//------------------------------------------------------------------------------
// Address: 0x1041A1C0
// Name: _dynamic_atexit_destructor_for__g_EntListMemPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EntListMemPool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_EntListMemPool);
}

//------------------------------------------------------------------------------
// Address: 0x1041A1D0
// Name: _dynamic_atexit_destructor_for__g_EventQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EventQueue__()
{
  EventQueuePrioritizedEvent_t *m_pNext; // eax
  EventQueuePrioritizedEvent_t *v1; // esi

  m_pNext = g_EventQueue.m_Events.m_pNext;
  if ( g_EventQueue.m_Events.m_pNext != nullptr )
  {
    do
    {
      v1 = m_pNext->m_pNext;
      CUtlMemoryPool::Free(this: &EventQueuePrioritizedEvent_t::s_Allocator, memBlock: m_pNext);
      m_pNext = v1;
    }
    while ( v1 != nullptr );
  }
  g_EventQueue.m_Events.m_pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1041A200
// Name: _DataMapInit_CEventAction__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEventAction__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_109);
}

//------------------------------------------------------------------------------
// Address: 0x1041A210
// Name: _DataMapInit_CBaseEntityOutput__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseEntityOutput__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_110);
}

//------------------------------------------------------------------------------
// Address: 0x1041A220
// Name: _DataMapInit_CEventQueue__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEventQueue__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_111);
}

//------------------------------------------------------------------------------
// Address: 0x1041A230
// Name: _DataMapInit_EventQueuePrioritizedEvent_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_EventQueuePrioritizedEvent_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_112);
}

//------------------------------------------------------------------------------
// Address: 0x1041A240
// Name: _DataMapInit_CBaseProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_113);
}

//------------------------------------------------------------------------------
// Address: 0x1041A250
// Name: _dynamic_atexit_destructor_for__cast_ray_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cast_ray_command__()
{
  ConCommand::~ConCommand(this: &cast_ray_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A260
// Name: _dynamic_atexit_destructor_for__cast_hull_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cast_hull_command__()
{
  ConCommand::~ConCommand(this: &cast_hull_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A270
// Name: _dynamic_atexit_destructor_for__drawline__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__drawline__()
{
  ConCommand::~ConCommand(this: &drawline);
}

//------------------------------------------------------------------------------
// Address: 0x1041A280
// Name: _dynamic_atexit_destructor_for__drawcross__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__drawcross__()
{
  ConCommand::~ConCommand(this: &drawcross);
}
