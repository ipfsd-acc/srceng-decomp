// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/trains.cpp
// Functions: 142
// ============================================================

#include "game\server\trains.h"

//------------------------------------------------------------------------------
// Address: 0x102344C0
// Name: public: virtual struct datamap_t __near * CBasePlatTrain::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBasePlatTrain::GetDataDescMap(CBasePlatTrain *this)
{
  return &CBasePlatTrain::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102344D0
// Name: public: void CFuncPlat::CallGoDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::CallGoDown(CFuncPlat *this)
{
  this->GoDown(this);
}

//------------------------------------------------------------------------------
// Address: 0x102344E0
// Name: public: void CFuncPlat::CallHitTop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::CallHitTop(CFuncPlat *this)
{
  this->HitTop(this);
}

//------------------------------------------------------------------------------
// Address: 0x102344F0
// Name: public: void CFuncPlat::CallHitBottom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::CallHitBottom(CFuncPlat *this)
{
  this->HitBottom(this);
}

//------------------------------------------------------------------------------
// Address: 0x10234500
// Name: public: virtual struct datamap_t __near * CFuncPlat::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncPlat::GetDataDescMap(CFuncPlat *this)
{
  return &CFuncPlat::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10234510
// Name: public: virtual void CPlatTrigger::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlatTrigger::Touch(CPlatTrigger *this, CBaseEntity *pOther)
{
  CFuncPlat *m_pPlatform; // ecx
  TOGGLE_STATE m_toggle_state; // eax

  if ( pOther->IsPlayer(this: pOther) && pOther->IsAlive(this: pOther) )
  {
    m_pPlatform = this->m_pPlatform;
    m_toggle_state = m_pPlatform->m_toggle_state;
    if ( m_toggle_state == TS_AT_BOTTOM )
    {
      m_pPlatform->GoUp(this: m_pPlatform);
    }
    else if ( m_toggle_state == TS_AT_TOP )
    {
      CBaseEntity::SetMoveDoneTime(this: m_pPlatform, flDelay: 1.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234580
// Name: public: void CFuncPlat::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::InputToggle(CFuncPlat *this, inputdata_t *data)
{
  TOGGLE_STATE m_toggle_state; // eax
  bool v4; // zf

  if ( !this->IsTogglePlat(this) )
  {
    v4 = this->m_toggle_state == TS_AT_TOP;
    this->m_pfnUse = nullptr;
    if ( !v4 )
      return;
    goto LABEL_6;
  }
  m_toggle_state = this->m_toggle_state;
  if ( m_toggle_state == TS_AT_TOP )
  {
LABEL_6:
    this->GoDown(this);
    return;
  }
  if ( m_toggle_state == TS_AT_BOTTOM )
    this->GoUp(this);
}

//------------------------------------------------------------------------------
// Address: 0x102345E0
// Name: public: void CFuncPlat::InputGoUp(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::InputGoUp(CFuncPlat *this, inputdata_t *data)
{
  if ( this->m_toggle_state == TS_AT_BOTTOM )
    this->GoUp(this);
}

//------------------------------------------------------------------------------
// Address: 0x10234600
// Name: public: void CFuncPlat::InputGoDown(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::InputGoDown(CFuncPlat *this, inputdata_t *data)
{
  if ( this->m_toggle_state == TS_AT_TOP )
    this->GoDown(this);
}

//------------------------------------------------------------------------------
// Address: 0x10234620
// Name: public: void CFuncPlat::PlatUse(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::PlatUse(
        CFuncPlat *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  TOGGLE_STATE m_toggle_state; // eax
  bool v7; // zf

  if ( !this->IsTogglePlat(this) )
  {
    v7 = this->m_toggle_state == TS_AT_TOP;
    this->m_pfnUse = nullptr;
    if ( !v7 )
      return;
    goto LABEL_7;
  }
  if ( CBaseEntity::ShouldToggle(this, useType, currentState: this->m_toggle_state == TS_AT_BOTTOM) == 0 )
    return;
  m_toggle_state = this->m_toggle_state;
  if ( m_toggle_state == TS_AT_TOP )
  {
LABEL_7:
    this->GoDown(this);
    return;
  }
  if ( m_toggle_state == TS_AT_BOTTOM )
    this->GoUp(this);
}

//------------------------------------------------------------------------------
// Address: 0x102346A0
// Name: public: virtual struct datamap_t __near * CFuncPlatRot::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncPlatRot::GetDataDescMap(CFuncPlatRot *this)
{
  return &CFuncPlatRot::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102346B0
// Name: public: virtual struct datamap_t __near * CFuncTrain::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncTrain::GetDataDescMap(CFuncTrain *this)
{
  return &CFuncTrain::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102346C0
// Name: public: virtual void CFuncTrain::Blocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFuncTrain::Blocked(CFuncTrain *this@<ecx>, int a2@<esi>, CBaseEntity *pOther)
{
  float curtime; // xmm0_4
  const CTakeDamageInfo *v4; // eax
  CTakeDamageInfo v5; // [esp+10h] [ebp-5Ch] BYREF

  curtime = gpGlobals->curtime;
  if ( this->m_flNextBlockTime <= curtime )
  {
    this->m_flNextBlockTime = curtime + 0.5;
    v4 = CTakeDamageInfo::CTakeDamageInfo(
           this: &v5,
           pInflictor: this,
           pAttacker: this,
           flDamage: this->m_flBlockDamage,
           bitsDamageType: 1,
           iKillType: 0,
           iObjectsPenetrated: 0);
    CBaseEntity::TakeDamage(this: pOther, a2, inputInfo: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234720
// Name: public: virtual struct datamap_t __near * CFuncTrackTrain::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncTrackTrain::GetDataDescMap(CFuncTrackTrain *this)
{
  return &CFuncTrackTrain::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10234730
// Name: public: virtual class ServerClass __near * CFuncTrackTrain::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncTrackTrain::GetServerClass(CFuncTrackTrain *this)
{
  return &g_CFuncTrackTrain_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10234740
// Name: public: void CFuncTrackTrain::SetDirForward(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::SetDirForward(CFuncTrackTrain *this, bool bForward)
{
  float m_dir; // xmm0_4
  CPathTrack *m_ppath; // ecx
  CPathTrack *v5; // ecx

  m_dir = this->m_dir;
  if ( bForward )
  {
    if ( m_dir != 1.0 )
    {
      m_ppath = this->m_ppath;
      if ( m_ppath != nullptr && CPathTrack::GetPrevious(this: m_ppath) != nullptr )
        this->m_ppath = CPathTrack::GetPrevious(this: this->m_ppath);
      this->m_dir = 1.0;
    }
  }
  else if ( m_dir != -1.0 )
  {
    v5 = this->m_ppath;
    if ( v5 != nullptr && CPathTrack::GetNext(this: v5) != nullptr )
      this->m_ppath = CPathTrack::GetNext(this: this->m_ppath);
    this->m_dir = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102347E0
// Name: public: virtual struct datamap_t __near * CFuncTrainControls::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncTrainControls::GetDataDescMap(CFuncTrainControls *this)
{
  return &CFuncTrainControls::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102347F0
// Name: public: virtual struct datamap_t __near * CFuncTrackChange::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncTrackChange::GetDataDescMap(CFuncTrackChange *this)
{
  return &CFuncTrackChange::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10234800
// Name: public: virtual struct datamap_t __near * CFuncTrackAuto::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncTrackAuto::GetDataDescMap(CFuncTrackAuto *this)
{
  return &CFuncTrackAuto::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10234820
// Name: public: virtual bool CBasePlatTrain::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlatTrain::KeyValue(CBasePlatTrain *this, char *szKeyName, const char *szValue)
{
  if ( szKeyName != "rotation" && _V_stricmp(s1: szKeyName, s2: "rotation") != 0 )
    return CBaseToggle::KeyValue(this, szKeyName, szValue);
  this->m_vecFinalAngle.x = atof(nptr: szValue);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10234870
// Name: public: virtual bool CBasePlatTrain::IsTogglePlat(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlatTrain::IsTogglePlat(CBasePlatTrain *this)
{
  return this->m_spawnflags.m_Value & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10234880
// Name: public: void CBasePlatTrain::PlayMovingSound(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlatTrain::PlayMovingSound(CBasePlatTrain *this@<ecx>, float a2@<ebx>, int a3@<edi>)
{
  CSoundControllerImp *Controller; // eax
  CSoundControllerImp *v5; // edi
  const Vector *v6; // ebx
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v8; // eax
  const char *pszValue; // ecx
  edict_t *m_pPev; // eax
  CSoundPatch *v11; // eax
  float m_volume; // xmm0_4
  CPASAttenuationFilter filter; // [esp+3Ch] [ebp-2Ch] BYREF
  _BYTE v16[12]; // [esp+5Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  if ( this->m_pMovementSound != nullptr )
  {
    Controller = CSoundEnvelopeController::GetController();
    Controller->SoundDestroy(this: Controller, a2: this->m_pMovementSound);
    this->m_pMovementSound = nullptr;
  }
  if ( this->m_NoiseMoving.pszValue != nullptr )
  {
    v5 = CSoundEnvelopeController::GetController();
    v6 = (const Vector *)((int (__thiscall *)(CBasePlatTrain *, _BYTE *, int))this->GetSoundEmissionOrigin)(
                           a1: this,
                           a2: v16,
                           a3);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v6);
    GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v8 = (const Vector *)((int (__thiscall *)(CBasePlatTrain *, _BYTE *, int))GetSoundEmissionOrigin)(
                           a1: this,
                           a2: v16,
                           a3: 1061997773);
    CPASAttenuationFilter::Filter(this: &filter, a2: (int)&savedregs, origin: v8, attenuation: a2);
    pszValue = this->m_NoiseMoving.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v11 = (CSoundPatch *)((int (__thiscall *)(CSoundControllerImp *, CPASAttenuationFilter *, edict_t *, int, const char *))v5->SoundCreate_4)(
                           a1: v5,
                           a2: &filter,
                           a3: m_pPev,
                           a4: 6,
                           a5: pszValue);
    m_volume = this->m_volume;
    this->m_pMovementSound = v11;
    ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, float, int, _DWORD))v5->Play)(
      a1: v5,
      a2: v11,
      a3: COERCE_FLOAT(LODWORD(m_volume)),
      a4: 1120403456,
      a5: 0);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102349C0
// Name: public: virtual void CFuncTrain::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrain::Precache(CFuncTrain *this)
{
  string_t *p_m_NoiseMoving; // edi
  string_t *p_m_NoiseArrived; // esi
  const char *pszValue; // edi
  const char *v5; // esi

  p_m_NoiseMoving = &this->m_NoiseMoving;
  UTIL_ValidateSoundName(name: &this->m_NoiseMoving, defaultStr: "Plat.DefaultMoving");
  p_m_NoiseArrived = &this->m_NoiseArrived;
  UTIL_ValidateSoundName(name: p_m_NoiseArrived, defaultStr: "Plat.DefaultArrive");
  pszValue = p_m_NoiseMoving->pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CBaseEntity::PrecacheScriptSound(soundname: pszValue);
  v5 = p_m_NoiseArrived->pszValue;
  if ( v5 == nullptr )
    v5 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10234A20
// Name: public: virtual void CFuncPlat::GoDown(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncPlat::GoDown(CFuncPlat *this@<ecx>, float a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  float flSpeed; // [esp+0h] [ebp-8h]

  CBasePlatTrain::PlayMovingSound(this, a2, a3: a4);
  flSpeed = this->m_flSpeed;
  this->m_toggle_state = TS_GOING_DOWN;
  this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncPlat::CallHitBottom;
  CBaseToggle::LinearMove(this, a2: a3, vecDest: &this->m_vecPosition2, flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x10234A60
// Name: public: virtual void CFuncPlat::GoUp(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncPlat::GoUp(CFuncPlat *this@<ecx>, float a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  float flSpeed; // [esp+0h] [ebp-8h]

  CBasePlatTrain::PlayMovingSound(this, a2, a3: a4);
  flSpeed = this->m_flSpeed;
  this->m_toggle_state = TS_GOING_UP;
  this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncPlat::CallHitTop;
  CBaseToggle::LinearMove(this, a2: a3, vecDest: &this->m_vecPosition1, flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x10234AA0
// Name: public: virtual void CFuncPlat::Blocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::Blocked(CFuncPlat *this, CBaseEntity *pOther)
{
  const char *pszValue; // eax
  const char *v4; // ecx
  const CTakeDamageInfo *v5; // eax
  const char *v6; // ecx
  edict_t *m_pPev; // eax
  TOGGLE_STATE m_toggle_state; // eax
  CTakeDamageInfo v9; // [esp+18h] [ebp-5Ch] BYREF

  pszValue = pOther->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v4 = this->m_iClassname.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  _DevMsg(a1: 2, a2: "%s Blocked by %s\n", v4, pszValue);
  v5 = CTakeDamageInfo::CTakeDamageInfo(
         this: &v9,
         pInflictor: this,
         pAttacker: this,
         flDamage: 1.0,
         bitsDamageType: 1,
         iKillType: 0,
         iObjectsPenetrated: 0);
  CBaseEntity::TakeDamage(this: pOther, a2: (int)this, inputInfo: v5);
  v6 = this->m_sNoise.pszValue;
  if ( v6 != nullptr )
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    CBaseEntity::StopSound(iEntIndex: (int)m_pPev, iChannel: 6, pSample: v6, bIsStoppingSpeakerSound: 0);
  }
  m_toggle_state = this->m_toggle_state;
  if ( m_toggle_state == TS_GOING_UP )
  {
    this->GoDown(this);
  }
  else if ( m_toggle_state == TS_GOING_DOWN )
  {
    this->GoUp(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234B60
// Name: public: virtual void CFuncTrackTrain::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::DrawDebugGeometryOverlays(CFuncTrackTrain *this)
{
  unsigned int v2; // eax
  Vector out; // [esp+8h] [ebp-24h] BYREF
  Vector mins; // [esp+14h] [ebp-18h] BYREF
  Vector maxs; // [esp+20h] [ebp-Ch] BYREF
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  CBaseEntity::DrawDebugGeometryOverlays(this);
  if ( (this->m_debugOverlays & 4) != 0 )
  {
    v2 = (unsigned int)this->m_iEFlags >> 11;
    maxs.x = 4.0;
    maxs.y = 4.0;
    maxs.z = 4.0;
    mins.x = -4.0;
    mins.y = -4.0;
    mins.z = -4.0;
    if ( (v2 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    NDebugOverlay::Box(origin: &this->m_vecAbsOrigin, &mins, &maxs, r: 255, g: 0, b: 255, a: 0, flDuration: 0.0);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    mins.x = this->m_length;
    mins.y = 0.0;
    mins.z = 0.0;
    VectorTransform(in1: &mins.x, in2: &this->m_rgflCoordinateFrame, out: &out.x);
    mins.x = 4.0;
    mins.y = 4.0;
    mins.z = 4.0;
    maxs.x = -4.0;
    maxs.y = -4.0;
    maxs.z = -4.0;
    NDebugOverlay::Box(origin: &out, mins: &maxs, maxs: &mins, r: 255, g: 0, b: 255, a: 0, flDuration: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234C90
// Name: public: virtual bool CFuncTrackTrain::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFuncTrackTrain::KeyValue(CFuncTrackTrain *this, char *szKeyName, const char *szValue)
{
  if ( szKeyName != "volume" && _V_stricmp(s1: szKeyName, s2: "volume") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  this->m_flVolume = (float)atoi(nptr: szValue) * 0.1;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10234D00
// Name: public: void CFuncTrackTrain::InputSetMaxSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::InputSetMaxSpeed(CFuncTrackTrain *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_maxSpeed) = inputdata->value.iVal;
  else
    this->m_maxSpeed = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10234D30
// Name: private: void CFuncTrackTrain::DoUpdateOrientation(class QAngle const __near &,class QAngle const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::DoUpdateOrientation(
        CFuncTrackTrain *this,
        const QAngle *curAngles,
        const QAngle *angles,
        float flInterval)
{
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float m_flBank; // xmm0_4
  float v13; // xmm1_4
  float target; // xmm1_4
  double v15; // st7
  QAngle vecAngVel; // [esp+18h] [ebp-10h] BYREF
  float vy; // [esp+24h] [ebp-4h]
  float vz; // [esp+30h] [ebp+8h]
  float vx; // [esp+34h] [ebp+Ch]
  float vxa; // [esp+34h] [ebp+Ch]
  float vxb; // [esp+34h] [ebp+Ch]

  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    vx = 0.0;
  else
    vx = AngleDistance(next: angles->x, cur: curAngles->x);
  vy = AngleDistance(next: angles->y, cur: curAngles->y);
  if ( (this->m_spawnflags.m_Value & 0x400) != 0 )
  {
    vz = AngleDistance(next: angles->z, cur: curAngles->z);
    v7 = vz;
  }
  else
  {
    v7 = 0.0;
  }
  v8 = vx;
  if ( fabs(vx) < 0.1 )
    v8 = 0.0;
  v9 = vy;
  if ( fabs(vy) < 0.1 )
    v9 = 0.0;
  if ( fabs(v7) < 0.1 )
    v7 = 0.0;
  v10 = flInterval;
  if ( flInterval == 0.0 )
    v10 = 0.1;
  vecAngVel.x = (float)(1.0 / v10) * v8;
  v11 = 1.0 / v10;
  vecAngVel.z = v11 * v7;
  m_flBank = this->m_flBank;
  v13 = v11 * v9;
  vecAngVel.y = v13;
  if ( m_flBank != 0.0 )
  {
    if ( v13 >= -5.0 )
    {
      if ( v13 <= 5.0 )
      {
        vxb = ApproachAngle(target: 0.0, value: curAngles->z, speed: m_flBank * 4.0);
        v15 = AngleDistance(next: vxb, cur: curAngles->z) * 4.0;
        goto LABEL_22;
      }
      m_flBank = this->m_flBank;
      target = m_flBank;
    }
    else
    {
      LODWORD(target) = LODWORD(m_flBank) ^ _mask__NegFloat_;
    }
    vxa = ApproachAngle(target, value: curAngles->z, speed: m_flBank * 2.0);
    v15 = AngleDistance(next: vxa, cur: curAngles->z);
LABEL_22:
    vecAngVel.z = v15;
  }
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vecAngVel);
}

//------------------------------------------------------------------------------
// Address: 0x10234F70
// Name: public: virtual void CFuncTrackTrain::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::Precache(CFuncTrackTrain *this)
{
  const char *pszValue; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // esi

  if ( this->m_flVolume == 0.0 )
    this->m_flVolume = 1.0;
  if ( this->m_iszSoundMove.pszValue != nullptr )
  {
    pszValue = this->m_iszSoundMove.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CBaseEntity::PrecacheScriptSound(soundname: pszValue);
  }
  if ( this->m_iszSoundMovePing.pszValue != nullptr )
  {
    v3 = this->m_iszSoundMovePing.pszValue;
    if ( v3 == nullptr )
      v3 = locale;
    CBaseEntity::PrecacheScriptSound(soundname: v3);
  }
  if ( this->m_iszSoundStart.pszValue != nullptr )
  {
    v4 = this->m_iszSoundStart.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    CBaseEntity::PrecacheScriptSound(soundname: v4);
  }
  if ( this->m_iszSoundStop.pszValue != nullptr )
  {
    v5 = this->m_iszSoundStop.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    CBaseEntity::PrecacheScriptSound(soundname: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10235020
// Name: public: virtual void CFuncTrackTrain::MoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::MoveDone(CFuncTrackTrain *this)
{
  void (*m_pfnMoveDone)(void); // eax

  this->m_lastBlockPos.x = 0.0;
  this->m_lastBlockPos.y = 0.0;
  this->m_lastBlockPos.z = 0.0;
  m_pfnMoveDone = (void (*)(void))this->m_pfnMoveDone;
  this->m_lastBlockTick = -1;
  if ( m_pfnMoveDone != nullptr )
    m_pfnMoveDone();
}

//------------------------------------------------------------------------------
// Address: 0x10235050
// Name: public: void CFuncTrackChange::Find(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackChange::Find(CFuncTrackChange *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  const char *v4; // eax
  CBasePlayer *v5; // eax
  const char *v6; // eax
  bool v7; // zf
  const char *v8; // eax
  CBasePlayer *v9; // eax
  const char *v10; // esi
  const Vector *v11; // eax
  CPathTrack *m_trackBottom; // ecx
  CPathTrack *v13; // eax
  CPathTrack *m_trackTop; // ecx
  CPathTrack *v15; // eax
  TOGGLE_STATE m_toggle_state; // ecx
  const char *v17; // esi
  const char *v18; // esi
  const char *v19; // esi
  Vector center; // [esp+10h] [ebp-Ch] BYREF

  pszValue = this->m_trackTopName.pszValue;
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
  if ( EntityByName != nullptr )
  {
    this->m_trackTop = (CPathTrack *)EntityByName;
    v4 = this->m_trackBottomName.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    v5 = CGlobalEntityList::FindEntityByName(
           this: &gEntList,
           pStartEntity: nullptr,
           szName: v4,
           pSearchingEntity: nullptr,
           pActivator: nullptr,
           pCaller: nullptr,
           pFilter: nullptr);
    if ( v5 != nullptr )
    {
      this->m_trackBottom = (CPathTrack *)v5;
      v6 = this->m_trainName.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      v7 = CGlobalEntityList::FindEntityByName(
             this: &gEntList,
             pStartEntity: nullptr,
             szName: v6,
             pSearchingEntity: nullptr,
             pActivator: nullptr,
             pCaller: nullptr,
             pFilter: nullptr) == nullptr;
      v8 = this->m_trainName.pszValue;
      if ( v7 )
      {
        if ( v8 == nullptr )
          v8 = locale;
        _Warning(a1: "Can't find train for track change! %s\n", v8);
        v17 = this->m_trainName.pszValue;
        if ( v17 == nullptr )
          v17 = locale;
        CGlobalEntityList::FindEntityByName(
          this: &gEntList,
          pStartEntity: nullptr,
          szName: v17,
          pSearchingEntity: nullptr,
          pActivator: nullptr,
          pCaller: nullptr,
          pFilter: nullptr);
      }
      else
      {
        if ( v8 == nullptr )
          v8 = locale;
        v9 = CGlobalEntityList::FindEntityByName(
               this: &gEntList,
               pStartEntity: nullptr,
               szName: v8,
               pSearchingEntity: nullptr,
               pActivator: nullptr,
               pCaller: nullptr,
               pFilter: nullptr);
        this->m_train = (CFuncTrackTrain *)v9;
        if ( v9 != nullptr )
        {
          v11 = this->WorldSpaceCenter(this);
          *(_QWORD *)&center.x = *(_QWORD *)&v11->x;
          m_trackBottom = this->m_trackBottom;
          center.z = v11->z;
          v13 = CPathTrack::Nearest(this: m_trackBottom, origin: &center);
          m_trackTop = this->m_trackTop;
          this->m_trackBottom = v13;
          v15 = CPathTrack::Nearest(this: m_trackTop, origin: &center);
          m_toggle_state = this->m_toggle_state;
          this->m_trackTop = v15;
          this->UpdateAutoTargets(this, a2: m_toggle_state);
          CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
        }
        else
        {
          v10 = this->m_trainName.pszValue;
          if ( v10 == nullptr )
            v10 = locale;
          _Warning(a1: "Can't find train for track change! %s\n", v10);
        }
      }
    }
    else
    {
      v18 = this->m_trackBottomName.pszValue;
      if ( v18 == nullptr )
        v18 = locale;
      _Warning(a1: "Can't find bottom track for track change! %s\n", v18);
    }
  }
  else
  {
    v19 = this->m_trackTopName.pszValue;
    if ( v19 == nullptr )
      v19 = locale;
    _Warning(a1: "Can't find top track for track change! %s\n", v19);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10235260
// Name: public: void CFuncPlat::Setup(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncPlat::Setup(CFuncPlat *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  const char *v4; // eax
  float m_flHeight; // xmm0_4
  Vector *v6; // eax
  float v7; // xmm0_4
  CFuncPlat *v9; // [esp+0h] [ebp-4h] BYREF

  v9 = this;
  if ( this->m_flTLength == 0.0 )
    this->m_flTLength = 80.0;
  if ( this->m_flTWidth == 0.0 )
    this->m_flTWidth = 10.0;
  CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  v4 = *(const char **)((int (__thiscall *)(CFuncPlat *, CFuncPlat **, int, int))this->GetModelName)(
                         a1: this,
                         a2: &v9,
                         a3: a2,
                         a4: a3);
  if ( v4 == nullptr )
    v4 = locale;
  this->SetModel(this, a2: v4);
  this->m_vecPosition1.x = this->m_vecOrigin.m_Value.x;
  this->m_vecPosition1.y = this->m_vecOrigin.m_Value.y;
  this->m_vecPosition1.z = this->m_vecOrigin.m_Value.z;
  this->m_vecPosition2.x = this->m_vecOrigin.m_Value.x;
  this->m_vecPosition2.y = this->m_vecOrigin.m_Value.y;
  this->m_vecPosition2.z = this->m_vecOrigin.m_Value.z;
  m_flHeight = this->m_flHeight;
  if ( m_flHeight == 0.0 )
  {
    v6 = AllocTempVector();
    v6->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
    v6->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
    v7 = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
    v6->z = v7;
    this->m_vecPosition2.z = (float)(this->m_vecOrigin.m_Value.z - v7) + 8.0;
  }
  else
  {
    this->m_vecPosition2.z = this->m_vecOrigin.m_Value.z - m_flHeight;
  }
  if ( this->m_flSpeed == 0.0 )
    this->m_flSpeed = 150.0;
  if ( this->m_volume == 0.0 )
    this->m_volume = 0.85000002;
}

//------------------------------------------------------------------------------
// Address: 0x10235410
// Name: public: virtual void CFuncPlat::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncPlat::Spawn(CFuncPlat *this@<ecx>, int a2@<edi>)
{
  CFuncPlat::Setup(this, a2, a3: (int)this);
  this->Precache(this);
  if ( this->m_iName.m_Value.pszValue != nullptr )
  {
    UTIL_SetOrigin(entity: this, vecOrigin: &this->m_vecPosition1, bFireTriggers: false);
    this->m_toggle_state = TS_AT_TOP;
    this->m_pfnUse = (void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float))CFuncPlat::PlatUse;
  }
  else
  {
    UTIL_SetOrigin(entity: this, vecOrigin: &this->m_vecPosition2, bFireTriggers: false);
    this->m_toggle_state = TS_AT_BOTTOM;
  }
  this->CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x10235480
// Name: public: void CPlatTrigger::SpawnInsideTrigger(class CFuncPlat __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlatTrigger::SpawnInsideTrigger(CPlatTrigger *this, CFuncPlat *pPlatform)
{
  CFuncPlat *m_pPlatform; // esi
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  float *p_m_Collision; // esi
  float *v6; // eax
  float *v7; // eax
  float v8; // xmm0_4
  CFuncPlat *v9; // eax
  Vector *v10; // eax
  float *v11; // ebx
  Vector *v12; // eax
  float *v13; // ebx
  Vector vecTMax; // [esp+Ch] [ebp-18h] BYREF
  Vector vecTMin; // [esp+18h] [ebp-Ch] BYREF

  this->m_pPlatform = pPlatform;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::SetLocalOrigin(this, origin: &pPlatform->m_vecOrigin.m_Value);
  m_pPlatform = this->m_pPlatform;
  OBBMins = m_pPlatform->m_Collision.OBBMins;
  p_m_Collision = (float *)&m_pPlatform->m_Collision;
  v6 = (float *)OBBMins(this: (struct CBaseEntity::NetworkVar_m_Collision *)p_m_Collision);
  vecTMin.x = *v6 + 25.0;
  vecTMin.y = v6[1] + 25.0;
  vecTMin.z = v6[2];
  v7 = (float *)(*(int (__thiscall **)(float *))(*(_DWORD *)p_m_Collision + 8))(a1: p_m_Collision);
  vecTMax.x = *v7 + 25.0;
  vecTMax.y = v7[1] + 25.0;
  v8 = v7[2];
  v9 = this->m_pPlatform;
  vecTMax.z = v8 + 8.0;
  vecTMin.z = (float)(v8 + 8.0) - (float)((float)(v9->m_vecPosition1.z - v9->m_vecPosition2.z) + 8.0);
  v10 = AllocTempVector();
  v10->x = p_m_Collision[5] - p_m_Collision[2];
  v10->y = p_m_Collision[6] - p_m_Collision[3];
  v10->z = p_m_Collision[7] - p_m_Collision[4];
  if ( v10->x <= 50.0 )
  {
    v11 = (float *)(*(int (__thiscall **)(float *))(*(_DWORD *)p_m_Collision + 8))(a1: p_m_Collision);
    vecTMin.x = (float)(*v11
                      + *(float *)(*(int (__thiscall **)(float *))(*(_DWORD *)p_m_Collision + 4))(a1: p_m_Collision))
              * 0.5;
    vecTMax.x = vecTMin.x + 1.0;
  }
  v12 = AllocTempVector();
  v12->x = p_m_Collision[5] - p_m_Collision[2];
  v12->y = p_m_Collision[6] - p_m_Collision[3];
  v12->z = p_m_Collision[7] - p_m_Collision[4];
  if ( v12->y <= 50.0 )
  {
    v13 = (float *)((*(int (__thiscall **)(float *))(*(_DWORD *)p_m_Collision + 8))(a1: p_m_Collision) + 4);
    vecTMin.y = (float)(*(float *)((*(int (__thiscall **)(float *))(*(_DWORD *)p_m_Collision + 4))(a1: p_m_Collision) + 4)
                      + *v13)
              * 0.5;
    vecTMax.y = vecTMin.y + 1.0;
  }
  UTIL_SetSize(pEnt: this, vecMin: &vecTMin, vecMax: &vecTMax);
}

//------------------------------------------------------------------------------
// Address: 0x10235680
// Name: public: void CFuncPlatRot::SetupRotation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlatRot::SetupRotation(CFuncPlatRot *this)
{
  QAngle *p_m_end; // eax
  float x; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  if ( this->m_vecFinalAngle.x == 0.0 )
  {
    this->m_start = vec3_angle;
    p_m_end = &this->m_end;
    this->m_end = vec3_angle;
  }
  else
  {
    CBaseToggle::AxisDir(this);
    this->m_start.x = this->m_angRotation.m_Value.x;
    p_m_end = &this->m_end;
    this->m_start.y = this->m_angRotation.m_Value.y;
    this->m_start.z = this->m_angRotation.m_Value.z;
    x = this->m_vecFinalAngle.x;
    v4 = (float)(this->m_vecMoveAng.y * x) + this->m_angRotation.m_Value.y;
    v5 = this->m_angRotation.m_Value.z + (float)(this->m_vecMoveAng.z * x);
    this->m_end.x = (float)(this->m_vecFinalAngle.x * this->m_vecMoveAng.x) + this->m_angRotation.m_Value.x;
    this->m_end.y = v4;
    this->m_end.z = v5;
  }
  if ( this->m_iName.m_Value.pszValue != nullptr )
    CBaseEntity::SetLocalAngles(this, angles: p_m_end);
}

//------------------------------------------------------------------------------
// Address: 0x102357A0
// Name: public: virtual void CFuncPlatRot::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncPlatRot::Spawn(CFuncPlatRot *this@<ecx>, int a2@<edi>)
{
  CFuncPlat::Spawn(this, a2);
  CFuncPlatRot::SetupRotation(this);
}

//------------------------------------------------------------------------------
// Address: 0x102357B0
// Name: public: void CFuncTrain::SetupTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrain::SetupTarget(CFuncTrain *this)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  const char *v5; // esi

  m_Index = this->m_hCurrentTarget.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    pszValue = this->m_target.pszValue;
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
    if ( EntityByName != nullptr )
    {
      this->m_target.pszValue = EntityByName->m_target.pszValue;
      this->m_hCurrentTarget.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
    }
    else
    {
      v5 = this->m_target.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      _Msg(a1: "Can't find target of train %s\n", v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10235850
// Name: public: virtual void CFuncTrain::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncTrain::Spawn(CFuncTrain *this@<ecx>, int a2@<edi>)
{
  const char *DebugName; // eax
  const char *v4; // eax
  float m_volume; // xmm0_4
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  this->Precache(this);
  if ( this->m_flSpeed == 0.0 )
    this->m_flSpeed = 100.0;
  if ( this->m_target.pszValue == nullptr )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(a1: "FuncTrain '%s' has no target.\n", DebugName);
  }
  if ( this->m_flBlockDamage == 0.0 )
    this->m_flBlockDamage = 2.0;
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  v4 = *(const char **)((int (__thiscall *)(CFuncTrain *, _BYTE *, int))this->GetModelName)(a1: this, a2: v6, a3: a2);
  if ( v4 == nullptr )
    v4 = locale;
  this->SetModel(this, a2: v4);
  if ( (this->m_spawnflags.m_Value & 8) != 0 )
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  m_volume = this->m_volume;
  this->m_activated = false;
  if ( m_volume == 0.0 )
    this->m_volume = 0.85000002;
}

//------------------------------------------------------------------------------
// Address: 0x10235960
// Name: public: virtual void CFuncTrain::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrain::OnRestore(CFuncTrain *this)
{
  CBaseEntity::OnRestore(this);
  if ( this->IsMoving(this) )
    this->m_target.pszValue = this->m_iszLastTarget.pszValue;
  CFuncTrain::SetupTarget(this);
}

//------------------------------------------------------------------------------
// Address: 0x10235A10
// Name: public: virtual int CFuncTrackTrain::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __usercall CFuncTrackTrain::DrawDebugTextOverlays@<eax>(CFuncTrackTrain *this@<ecx>, int a2@<ebp>)
{
  int result; // eax
  int v4; // edi
  __int128 v5; // xmm0
  int v6; // edi
  char v7[12]; // [esp+28h] [ebp-21Ch] BYREF
  __int128 tempstr_500; // [esp+228h] [ebp-1Ch] OVERLAPPED
  int v9; // [esp+238h] [ebp-Ch]
  void *v10; // [esp+23Ch] [ebp-8h]
  void *retaddr; // [esp+244h] [ebp+0h]

  v9 = a2;
  v10 = retaddr;
  result = CBaseEntity::DrawDebugTextOverlays(this);
  v4 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(
      pDest: v7,
      maxLen: 512,
      pFormat: "angles: %g %g %g",
      this->m_angRotation.m_Value.x,
      this->m_angRotation.m_Value.y,
      this->m_angRotation.m_Value.z);
    CBaseEntity::EntityText(this, text_offset: v4, text: v7, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v5 = 0;
    *(float *)&v5 = fsqrt(
                      (float)((float)(this->m_vecVelocity.m_Value.x * this->m_vecVelocity.m_Value.x)
                            + (float)(this->m_vecVelocity.m_Value.y * this->m_vecVelocity.m_Value.y))
                    + (float)(this->m_vecVelocity.m_Value.z * this->m_vecVelocity.m_Value.z));
    tempstr_500 = v5;
    v6 = v4 + 1;
    V_snprintf(pDest: v7, maxLen: 512, pFormat: "current speed (goal): %g (%g)", *(float *)&v5, this->m_flSpeed);
    CBaseEntity::EntityText(this, text_offset: v6++, text: v7, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: v7, maxLen: 512, pFormat: "max speed: %g", this->m_maxSpeed);
    CBaseEntity::EntityText(this, text_offset: v6, text: v7, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v6 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10235BD0
// Name: private: void CFuncTrackTrain::UpdateTrainVelocity(class CPathTrack __near *,class CPathTrack __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFuncTrackTrain::UpdateTrainVelocity(
        CFuncTrackTrain *this@<ecx>,
        float a2@<ebp>,
        CPathTrack *pPrev,
        CPathTrack *pNext,
        const Vector *nextPos,
        float flInterval)
{
  TrainVelocityType_t m_eVelocityType; // edi
  float m_flSpeed; // xmm0_4
  float m_flDesiredSpeed; // xmm1_4
  float m_flDecelSpeed; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float y; // xmm4_4
  float z; // xmm5_4
  float x; // xmm3_4
  __int128 v18; // xmm0
  float val; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  __int128 v23; // [esp+34h] [ebp-2Ch] BYREF
  Vector velDesired; // [esp+44h] [ebp-1Ch]
  float v25; // [esp+50h] [ebp-10h]
  float p; // [esp+54h] [ebp-Ch]
  float flNextSpeed; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  p = a2;
  flNextSpeed = retaddr;
  m_eVelocityType = this->m_eVelocityType;
  if ( m_eVelocityType != TrainVelocity_Instantaneous )
  {
    if ( (unsigned int)(m_eVelocityType - 1) > 1 )
      return;
    if ( this->m_bAccelToSpeed )
    {
      m_flSpeed = this->m_flSpeed;
      m_flDesiredSpeed = this->m_flDesiredSpeed;
      if ( m_flSpeed != m_flDesiredSpeed )
      {
        if ( fabs(m_flDesiredSpeed) <= fabs(m_flSpeed) )
          m_flDecelSpeed = this->m_flDecelSpeed;
        else
          m_flDecelSpeed = this->m_flAccelSpeed;
        this->m_flSpeed = UTIL_Approach(
                            target: this->m_flDesiredSpeed,
                            value: this->m_flSpeed,
                            speed: gpGlobals->frametime * m_flDecelSpeed);
      }
      goto LABEL_22;
    }
    if ( pPrev != nullptr && pNext != nullptr )
    {
      v11 = pPrev->m_flSpeed;
      v12 = this->m_flSpeed;
      v25 = v12;
      if ( v11 != 0.0 )
      {
        v12 = v11;
        v25 = v11;
      }
      v13 = pNext->m_flSpeed;
      v14 = v12;
      velDesired.z = v12;
      if ( v13 != 0.0 )
      {
        v14 = v13;
        velDesired.z = v13;
      }
      if ( v12 == v14 )
      {
        v20 = this->m_dir * v12;
LABEL_21:
        this->m_flSpeed = v20;
        goto LABEL_22;
      }
      y = pPrev->m_vecOrigin.m_Value.y;
      z = pPrev->m_vecOrigin.m_Value.z;
      x = pPrev->m_vecOrigin.m_Value.x;
      v18 = 0;
      *(float *)&v18 = fsqrt(
                         (float)((float)((float)(pNext->m_vecOrigin.m_Value.y - y)
                                       * (float)(pNext->m_vecOrigin.m_Value.y - y))
                               + (float)((float)(pNext->m_vecOrigin.m_Value.z - z)
                                       * (float)(pNext->m_vecOrigin.m_Value.z - z)))
                       + (float)((float)(pNext->m_vecOrigin.m_Value.x - x) * (float)(pNext->m_vecOrigin.m_Value.x - x)));
      v23 = v18;
      if ( *(float *)&v18 != 0.0 )
      {
        val = fsqrt(
                (float)((float)((float)(this->m_vecOrigin.m_Value.y - y) * (float)(this->m_vecOrigin.m_Value.y - y))
                      + (float)((float)(this->m_vecOrigin.m_Value.z - z) * (float)(this->m_vecOrigin.m_Value.z - z)))
              + (float)((float)(this->m_vecOrigin.m_Value.x - x) * (float)(this->m_vecOrigin.m_Value.x - x)))
            / *(float *)&v23;
        if ( m_eVelocityType == TrainVelocity_EaseInEaseOut )
        {
          velDesired.y = SimpleSplineRemapVal(val, A: 0.0, B: 1.0, C: 0.0, D: 1.0);
          val = velDesired.y;
        }
        v20 = (float)((float)((float)(1.0 - val) * v25) + (float)(val * velDesired.z)) * this->m_dir;
        goto LABEL_21;
      }
    }
LABEL_22:
    *((float *)&v23 + 1) = nextPos->x - this->m_vecOrigin.m_Value.x;
    *((float *)&v23 + 2) = nextPos->y - this->m_vecOrigin.m_Value.y;
    *((float *)&v23 + 3) = nextPos->z - this->m_vecOrigin.m_Value.z;
    VectorNormalize(vec: (Vector *)((char *)&v23 + 4));
    LODWORD(v21) = LODWORD(this->m_flSpeed) & _mask__AbsFloat_;
    *((float *)&v23 + 1) = *((float *)&v23 + 1) * v21;
    *((float *)&v23 + 2) = *((float *)&v23 + 2) * v21;
    *((float *)&v23 + 3) = *((float *)&v23 + 3) * v21;
    CBaseEntity::SetLocalVelocity(this, vecVelocity: (const Vector *)((char *)&v23 + 4));
    return;
  }
  *((float *)&v23 + 1) = nextPos->x - this->m_vecOrigin.m_Value.x;
  *((float *)&v23 + 2) = nextPos->y - this->m_vecOrigin.m_Value.y;
  *((float *)&v23 + 3) = nextPos->z - this->m_vecOrigin.m_Value.z;
  VectorNormalize(vec: (Vector *)((char *)&v23 + 4));
  LODWORD(v22) = LODWORD(this->m_flSpeed) & _mask__AbsFloat_;
  *((float *)&v23 + 1) = *((float *)&v23 + 1) * v22;
  *((float *)&v23 + 2) = *((float *)&v23 + 2) * v22;
  *((float *)&v23 + 3) = *((float *)&v23 + 3) * v22;
  if ( CBaseEntity::IsSimulatingOnAlternateTicks() && flInterval < 0.017 )
  {
    *((float *)&v23 + 1) = *((float *)&v23 + 1) * 2.0;
    *((float *)&v23 + 2) = *((float *)&v23 + 2) * 2.0;
    *((float *)&v23 + 3) = *((float *)&v23 + 3) * 2.0;
  }
  CBaseEntity::SetLocalVelocity(this, vecVelocity: (const Vector *)((char *)&v23 + 4));
}

//------------------------------------------------------------------------------
// Address: 0x10235FB0
// Name: private: void CFuncTrackTrain::UpdateOrientationAtPathTracks(class CPathTrack __near *,class CPathTrack __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::UpdateOrientationAtPathTracks(
        CFuncTrackTrain *this,
        CPathTrack *pPrev,
        CPathTrack *pNext,
        const Vector *nextPos,
        float flInterval)
{
  CPathTrack *m_ppath; // ecx
  float z; // eax
  float dist; // xmm0_4
  float m_dir; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // ecx
  QAngle result; // [esp+10h] [ebp-40h] BYREF
  QAngle curAngles; // [esp+1Ch] [ebp-34h] BYREF
  QAngle angles; // [esp+28h] [ebp-28h] BYREF
  Vector vecFaceDir; // [esp+34h] [ebp-1Ch] BYREF
  Vector nextFront; // [esp+40h] [ebp-10h] BYREF
  CPathTrack *pNextNode; // [esp+4Ch] [ebp-4h] BYREF

  m_ppath = this->m_ppath;
  if ( m_ppath != nullptr )
  {
    z = this->m_vecOrigin.m_Value.z;
    *(_QWORD *)&nextFront.x = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
    nextFront.z = z;
    nextFront.z = z - this->m_height;
    dist = this->m_length;
    pNextNode = nullptr;
    if ( dist <= 0.0 )
    {
      CPathTrack::LookAhead(
        this: m_ppath,
        origin: &nextFront,
        dist: (float)(this->m_dir == 1.0 ? 100 : -100),
        move: 0,
        pNextNext: &pNextNode);
    }
    else
    {
      if ( this->m_dir != 1.0 )
        LODWORD(dist) ^= _mask__NegFloat_;
      CPathTrack::LookAhead(this: m_ppath, origin: &nextFront, dist, move: 0, pNextNext: &pNextNode);
    }
    m_dir = this->m_dir;
    v10 = nextFront.x - this->m_vecOrigin.m_Value.x;
    v11 = nextFront.y - this->m_vecOrigin.m_Value.y;
    nextFront.z = this->m_height + nextFront.z;
    v12 = nextFront.z - this->m_vecOrigin.m_Value.z;
    vecFaceDir.x = v10;
    vecFaceDir.y = v11;
    vecFaceDir.z = v12;
    if ( m_dir != 1.0 )
    {
      vecFaceDir.x = v10 * -1.0;
      vecFaceDir.y = v11 * -1.0;
      vecFaceDir.z = v12 * -1.0;
    }
    VectorAngles(forward: &vecFaceDir, &angles);
    FixupAngles(v: &angles);
    if ( this->m_bManualSpeedChanges
      && pNextNode != nullptr
      && CPathTrack::GetOrientationType(this: pNextNode) == TrackOrientation_FacePathAngles )
    {
      angles = *CPathTrack::GetOrientation(this: pNextNode, &result, bForwardDir: this->m_dir == 1.0);
    }
    v13 = this->m_angRotation.m_Value.z;
    *(_QWORD *)&curAngles.x = *(_QWORD *)&this->m_angRotation.m_Value.x;
    curAngles.z = v13;
    FixupAngles(v: &curAngles);
    if ( pPrev == nullptr || vecFaceDir.x == 0.0 && vecFaceDir.y == 0.0 )
      angles = curAngles;
    CFuncTrackTrain::DoUpdateOrientation(this, &curAngles, &angles, flInterval);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10236200
// Name: private: void CFuncTrackTrain::UpdateOrientationBlend(enum TrainOrientationType_t,class CPathTrack __near *,class CPathTrack __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CFuncTrackTrain::UpdateOrientationBlend(
        CFuncTrackTrain *this@<ecx>,
        float a2@<ebp>,
        TrainOrientationType_t eOrientationType,
        CPathTrack *pPrev,
        CPathTrack *pNext,
        const Vector *nextPos,
        float flInterval)
{
  float m_dir; // xmm0_4
  float x; // xmm1_4
  float v9; // xmm6_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v12; // xmm3_4
  Quaternion v13; // xmm0
  __int128 v14; // xmm0
  _BYTE v15[17]; // [esp+18h] [ebp-7Ch] OVERLAPPED BYREF
  Quaternion qtPrev; // [esp+34h] [ebp-60h] BYREF
  Quaternion qtNext_4; // [esp+48h] [ebp-4Ch] OVERLAPPED BYREF
  QAngle v18; // [esp+5Ch] [ebp-38h] BYREF
  QAngle angNew; // [esp+68h] [ebp-2Ch] BYREF
  QAngle angPrev; // [esp+74h] [ebp-20h] BYREF
  QAngle angNext; // [esp+80h] [ebp-14h]
  void *v22; // [esp+8Ch] [ebp-8h]
  void *retaddr; // [esp+94h] [ebp+0h]

  angNext.z = a2;
  v22 = retaddr;
  m_dir = this->m_dir;
  LODWORD(angNext.x) = this;
  CPathTrack::GetOrientation(this: pPrev, result: &angNew, bForwardDir: m_dir == 1.0);
  FixupAngles(v: &angNew);
  if ( pNext != nullptr )
  {
    angPrev = *CPathTrack::GetOrientation(
                 this: pNext,
                 result: (QAngle *)&qtNext_4.y,
                 bForwardDir: *(float *)(LODWORD(angNext.x) + 924) == 1.0);
    FixupAngles(v: &angPrev);
    x = angNew.x;
  }
  else
  {
    x = angNew.x;
    angPrev = angNew;
  }
  if ( (*(_BYTE *)(LODWORD(angNext.x) + 760) & 1) != 0 )
    angPrev.x = x;
  v9 = 0.0;
  angNext.y = 0.0;
  if ( pPrev != nullptr && (angPrev.x != x || angPrev.y != angNew.y || angPrev.z != angNew.z) )
  {
    y = pPrev->m_vecOrigin.m_Value.y;
    z = pPrev->m_vecOrigin.m_Value.z;
    v12 = pPrev->m_vecOrigin.m_Value.x;
    v13 = 0;
    v13.x = fsqrt(
              (float)((float)((float)(pNext->m_vecOrigin.m_Value.y - y) * (float)(pNext->m_vecOrigin.m_Value.y - y))
                    + (float)((float)(pNext->m_vecOrigin.m_Value.z - z) * (float)(pNext->m_vecOrigin.m_Value.z - z)))
            + (float)((float)(pNext->m_vecOrigin.m_Value.x - v12) * (float)(pNext->m_vecOrigin.m_Value.x - v12)));
    qtNext_4 = v13;
    if ( v13.x != 0.0 )
    {
      v14 = 0;
      *(float *)&v14 = fsqrt(
                         (float)((float)((float)(*(float *)(LODWORD(angNext.x) + 704) - y)
                                       * (float)(*(float *)(LODWORD(angNext.x) + 704) - y))
                               + (float)((float)(*(float *)(LODWORD(angNext.x) + 708) - z)
                                       * (float)(*(float *)(LODWORD(angNext.x) + 708) - z)))
                       + (float)((float)(*(float *)(LODWORD(angNext.x) + 700) - v12)
                               * (float)(*(float *)(LODWORD(angNext.x) + 700) - v12)));
      *(_OWORD *)v15 = v14;
      v9 = *(float *)&v14 / qtNext_4.x;
      angNext.y = *(float *)&v14 / qtNext_4.x;
    }
    x = angNew.x;
  }
  if ( eOrientationType == TrainOrientation_EaseInEaseOut )
    angNext.y = (float)((float)(v9 * v9) * 3.0) - (float)((float)((float)(v9 * v9) * 2.0) * v9);
  if ( x == 90.0 )
  {
    angNew.x = 89.0;
  }
  else if ( x == -90.0 )
  {
    angNew.x = -89.0;
  }
  if ( angPrev.x == 90.0 || angPrev.x == -90.0 )
    angPrev.x = 89.0;
  AngleQuaternion(angles: &angNew, outQuat: (Quaternion *)&v15[16]);
  AngleQuaternion(angles: &angPrev, outQuat: (Quaternion *)&qtPrev.y);
  v18 = angPrev;
  if ( QuaternionAngleDiff(p: (const Quaternion *)&v15[16], q: (Quaternion *)&qtPrev.y) != 0.0 )
  {
    QuaternionSlerp(p: (const Quaternion *)&v15[16], q: (Quaternion *)&qtPrev.y, t: angNext.y, qt: (Quaternion *)v15);
    QuaternionAngles(q: (const Quaternion *)v15, angles: &v18);
  }
  if ( (*(_BYTE *)(LODWORD(angNext.x) + 760) & 1) != 0 )
    v18.x = angNew.x;
  CFuncTrackTrain::DoUpdateOrientation(
    this: (CFuncTrackTrain *)LODWORD(angNext.x),
    curAngles: (const QAngle *)(LODWORD(angNext.x) + 712),
    angles: &v18,
    flInterval);
}

//------------------------------------------------------------------------------
// Address: 0x10236530
// Name: private: void CFuncTrackTrain::TeleportToPathTrack(class CPathTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::TeleportToPathTrack(CFuncTrackTrain *this, CPathTrack *pTeleport)
{
  float z; // ecx
  float dist; // xmm0_4
  QAngle *Orientation; // eax
  bool v6; // zf
  __int64 angCur; // [esp+18h] [ebp-30h]
  Vector nextPos; // [esp+24h] [ebp-24h] BYREF
  Vector look; // [esp+30h] [ebp-18h] BYREF
  QAngle nextAngles; // [esp+3Ch] [ebp-Ch] BYREF

  z = pTeleport->m_vecOrigin.m_Value.z;
  angCur = *(_QWORD *)&this->m_angRotation.m_Value.x;
  *(_QWORD *)&nextPos.x = *(_QWORD *)&pTeleport->m_vecOrigin.m_Value.x;
  *(_QWORD *)&look.x = *(_QWORD *)&nextPos.x;
  dist = this->m_length;
  nextPos.z = z;
  look.z = z;
  CPathTrack::LookAhead(this: pTeleport, origin: &look, dist, move: 0, pNextNext: nullptr);
  if ( (this->m_spawnflags.m_Value & 0x10) != 0 || nextPos.x == look.x && nextPos.y == look.y && nextPos.z == look.z )
  {
    nextAngles = (QAngle)this->m_angRotation;
  }
  else
  {
    Orientation = CPathTrack::GetOrientation(
                    this: pTeleport,
                    result: (QAngle *)&nextPos,
                    bForwardDir: this->m_dir == 1.0);
    v6 = (this->m_spawnflags.m_Value & 1) == 0;
    nextAngles = *Orientation;
    if ( !v6 )
      LODWORD(nextAngles.x) = angCur;
  }
  this->Teleport(this, a2: (const Vector *)&pTeleport->m_vecOrigin, a3: &nextAngles, a4: nullptr, a5: true);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
}

//------------------------------------------------------------------------------
// Address: 0x10236680
// Name: private: void CFuncTrackTrain::FirePassInputs(class CPathTrack __near *,class CPathTrack __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::FirePassInputs(
        CFuncTrackTrain *this,
        CPathTrack *pStart,
        CPathTrack *pEnd,
        bool forward)
{
  CPathTrack *v5; // esi
  CPathTrack *v6; // eax

  v5 = pStart;
  if ( !forward )
  {
    v5 = pEnd;
    pEnd = pStart;
  }
  if ( v5 != nullptr )
  {
    do
    {
      if ( v5 == pEnd )
        break;
      ((void (__thiscall *)(CPathTrack *, const char *, CFuncTrackTrain *, CFuncTrackTrain *, _DWORD))v5->AcceptInput)(
        a1: v5,
        a2: "InPass",
        a3: this,
        a4: this,
        a5: 0);
      v6 = forward ? CPathTrack::GetNext(this: v5) : CPathTrack::GetPrevious(this: v5);
      v5 = v6;
    }
    while ( v6 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10236720
// Name: public: void CFuncTrackTrain::DeadEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::DeadEnd(CFuncTrackTrain *this)
{
  CPathTrack *m_ppath; // esi
  const char *DebugName; // eax
  CPathTrack *Previous; // eax
  CPathTrack *v5; // eax
  CPathTrack *Next; // eax
  CPathTrack *v7; // eax
  const char *v8; // eax
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax

  m_ppath = this->m_ppath;
  DebugName = CBaseEntity::GetDebugName(this);
  _DevMsg(a1: 2, a2: "TRAIN(%s): Dead end ", DebugName);
  if ( m_ppath != nullptr )
  {
    if ( this->m_oldSpeed >= 0.0 )
    {
      while ( 1 )
      {
        Next = CPathTrack::GetNext(this: m_ppath);
        v7 = CPathTrack::ValidPath(ppath: Next, testFlag: 1);
        if ( v7 == nullptr )
          break;
        m_ppath = v7;
      }
    }
    else
    {
      while ( 1 )
      {
        Previous = CPathTrack::GetPrevious(this: m_ppath);
        v5 = CPathTrack::ValidPath(ppath: Previous, testFlag: 1);
        if ( v5 == nullptr )
          break;
        m_ppath = v5;
      }
    }
  }
  CBaseEntity::SetLocalVelocity(this, vecVelocity: &vec3_origin);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  if ( m_ppath != nullptr )
  {
    this->m_ppath = m_ppath;
    v8 = CBaseEntity::GetDebugName(this: m_ppath);
    _DevMsg(a1: 2, a2: "at %s\n", v8);
    ((void (__thiscall *)(CPathTrack *, const char *, CFuncTrackTrain *, CFuncTrackTrain *, _DWORD))m_ppath->AcceptInput)(
      a1: m_ppath,
      a2: "InPass",
      a3: this,
      a4: this,
      a5: 0);
    if ( this->m_strPathTarget.pszValue != nullptr )
    {
      pszValue = this->m_strPathTarget.pszValue;
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
      if ( EntityByName != nullptr && m_ppath == (CPathTrack *)EntityByName )
      {
        COutputEvent::FireOutput(
          this: &this->m_OnArrivedAtDestinationNode,
          pActivator: m_ppath,
          pCaller: this,
          fDelay: 0.0);
        this->m_strPathTarget.pszValue = nullptr;
      }
    }
  }
  else
  {
    _DevMsg(a1: 2, a2: "\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10236890
// Name: public: virtual bool CFuncTrackTrain::OnControls(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFuncTrackTrain::OnControls(CFuncTrackTrain *this, CBaseEntity *pTest)
{
  bool v3; // zf
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  bool result; // al
  VMatrix tmp; // [esp+0h] [ebp-4Ch] BYREF
  Vector offset; // [esp+40h] [ebp-Ch]

  v3 = (this->m_spawnflags.m_Value & 2) == 0;
  offset.x = pTest->m_vecOrigin.m_Value.x - this->m_vecOrigin.m_Value.x;
  offset.y = pTest->m_vecOrigin.m_Value.y - this->m_vecOrigin.m_Value.y;
  offset.z = pTest->m_vecOrigin.m_Value.z - this->m_vecOrigin.m_Value.z;
  result = false;
  if ( v3 )
  {
    SetupMatrixAngles(result: &tmp, vAngles: &this->m_angRotation.m_Value);
    v4 = (float)((float)(offset.x * tmp.m[0][0]) + (float)(tmp.m[1][0] * offset.y)) + (float)(offset.z * tmp.m[2][0]);
    v5 = (float)((float)(tmp.m[0][1] * offset.x) + (float)(tmp.m[1][1] * offset.y)) + (float)(tmp.m[2][1] * offset.z);
    v6 = (float)((float)(tmp.m[0][2] * offset.x) + (float)(tmp.m[1][2] * offset.y)) + (float)(tmp.m[2][2] * offset.z);
    if ( v4 >= this->m_controlMins.x
      && v5 >= this->m_controlMins.y
      && v6 >= this->m_controlMins.z
      && this->m_controlMaxs.x >= v4
      && this->m_controlMaxs.y >= v5
      && this->m_controlMaxs.z >= v6 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102369D0
// Name: public: void CFuncTrainControls::Find(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrainControls::Find(CFuncTrainControls *this)
{
  CBasePlayer *v2; // esi
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  const Vector *v5; // eax
  int v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  float *v10; // eax
  int v11; // xmm1_4
  int v12; // xmm2_4
  const char *v13; // ebx
  __int64 v14; // [esp+14h] [ebp-Ch]
  float z; // [esp+1Ch] [ebp-4h]

  v2 = nullptr;
  while ( 1 )
  {
    pszValue = this->m_target.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: v2,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    v2 = EntityByName;
    if ( EntityByName == nullptr )
      break;
    if ( EntityByName->m_iClassname.pszValue == "func_tracktrain"
      || CBaseEntity::ClassMatchesComplex(this: EntityByName, pszClassOrWildcard: "func_tracktrain") != 0 )
    {
      z = this->m_vecOrigin.m_Value.z;
      v14 = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
      v5 = this->m_Collision.OBBMins(this: &this->m_Collision);
      *(float *)&v6 = v5->x + *(float *)&v14;
      v7 = v5->y + *((float *)&v14 + 1);
      v8 = v5->z + z;
      OBBMaxs = this->m_Collision.OBBMaxs;
      v2->m_nForceBone.m_Value = v6;
      v2->m_vecForce.m_Value.x = v7;
      v2->m_vecForce.m_Value.y = v8;
      v10 = (float *)OBBMaxs(this: &this->m_Collision);
      *(float *)&v11 = v10[1] + *((float *)&v14 + 1);
      *(float *)&v12 = v10[2] + z;
      v2->m_vecForce.m_Value.z = *v10 + *(float *)&v14;
      v2->m_nSkin.m_Value = v11;
      v2->m_nBody.m_Value = v12;
      CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
      return;
    }
  }
  v13 = this->m_target.pszValue;
  if ( v13 == nullptr )
    v13 = locale;
  _Msg(a1: "No train %s\n", v13);
}

//------------------------------------------------------------------------------
// Address: 0x10236B10
// Name: public: virtual void CFuncTrainControls::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrainControls::Spawn(CFuncTrainControls *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+14h] [ebp-4h] BYREF

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CFuncTrainControls *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CFuncTrainControls::Find,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10236B90
// Name: public: virtual void CFuncTrackChange::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncTrackChange::Spawn(CFuncTrackChange *this@<ecx>, int a2@<edi>)
{
  CFuncPlat::Setup(this, a2, a3: (int)this);
  if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
    this->m_vecPosition2.z = this->m_vecOrigin.m_Value.z;
  CFuncPlatRot::SetupRotation(this);
  if ( (this->m_spawnflags.m_Value & 8) != 0 )
  {
    UTIL_SetOrigin(entity: this, vecOrigin: &this->m_vecPosition2, bFireTriggers: false);
    this->m_toggle_state = TS_AT_BOTTOM;
    CBaseEntity::SetLocalAngles(this, angles: &this->m_start);
    this->m_targetState = 0;
  }
  else
  {
    UTIL_SetOrigin(entity: this, vecOrigin: &this->m_vecPosition1, bFireTriggers: false);
    this->m_toggle_state = TS_AT_TOP;
    CBaseEntity::SetLocalAngles(this, angles: &this->m_end);
    this->m_targetState = 1;
  }
  this->m_use = 1;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CFuncTrackChange::Find,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 2.0, szContext: nullptr);
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x10236C80
// Name: public: enum TRAIN_CODE CFuncTrackChange::EvaluateTrain(class CPathTrack __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFuncTrackChange::EvaluateTrain(CFuncTrackChange *this, CPathTrack *pcurrent)
{
  CFuncTrackTrain *m_train; // edx
  CPathTrack *m_ppath; // edi
  CPathTrack *m_pprevious; // esi
  CPathTrack *m_pnext; // eax
  float v7; // xmm0_4
  float m_length; // xmm0_4
  float v9; // [esp-10h] [ebp-1Ch]

  if ( pcurrent != nullptr )
  {
    m_train = this->m_train;
    if ( m_train != nullptr
      && ((m_ppath = m_train->m_ppath) == pcurrent
       || (m_pprevious = pcurrent->m_pprevious) != nullptr && m_ppath == m_pprevious
       || (m_pnext = pcurrent->m_pnext) != nullptr && m_ppath == m_pnext) )
    {
      if ( m_train->m_flSpeed != 0.0 )
        return 1;
      v7 = this->m_vecOrigin.m_Value.x - m_train->m_vecOrigin.m_Value.x;
      v9 = fsqrt(
             (float)((float)(this->m_vecOrigin.m_Value.y - m_train->m_vecOrigin.m_Value.y)
                   * (float)(this->m_vecOrigin.m_Value.y - m_train->m_vecOrigin.m_Value.y))
           + (float)(v7 * v7));
      m_length = m_train->m_length;
      if ( m_length > v9 )
        return 2;
      if ( v9 <= (float)(m_length + 150.0) )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10236D80
// Name: public: void CFuncTrackChange::UpdateTrain(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackChange::UpdateTrain(CFuncTrackChange *this, QAngle *dest)
{
  float m_flMoveDoneTime; // xmm0_4
  float v4; // xmm0_4
  unsigned int v5; // eax
  CFuncTrackTrain *m_train; // eax
  float v7; // xmm3_4
  unsigned int v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  CFuncTrackTrain *v11; // ecx
  Vector vecAbsVelocity; // [esp+Ch] [ebp-4Ch] BYREF
  Vector up; // [esp+18h] [ebp-40h] BYREF
  Vector right; // [esp+24h] [ebp-34h] BYREF
  Vector forward; // [esp+30h] [ebp-28h] BYREF
  QAngle delta; // [esp+3Ch] [ebp-1Ch] BYREF
  Vector offset; // [esp+48h] [ebp-10h]
  float time; // [esp+54h] [ebp-4h]
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  m_flMoveDoneTime = this->m_flMoveDoneTime;
  if ( m_flMoveDoneTime < 0.0 )
    v4 = -1.0;
  else
    v4 = m_flMoveDoneTime - this->m_flLocalTime;
  v5 = (unsigned int)this->m_iEFlags >> 12;
  time = v4;
  if ( (v5 & 1) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  CBaseEntity::SetAbsVelocity(this: this->m_train, vecAbsVelocity: &this->m_vecAbsVelocity);
  CBaseEntity::SetLocalAngularVelocity(this: this->m_train, vecAngVelocity: &this->m_vecAngVelocity);
  CBaseEntity::SetMoveDoneTime(this: this->m_train, flDelay: time);
  if ( time > 0.0 )
  {
    m_train = this->m_train;
    offset.x = m_train->m_vecOrigin.m_Value.x - this->m_vecOrigin.m_Value.x;
    offset.y = m_train->m_vecOrigin.m_Value.y - this->m_vecOrigin.m_Value.y;
    offset.z = m_train->m_vecOrigin.m_Value.z - this->m_vecOrigin.m_Value.z;
    delta.x = dest->x - this->m_angRotation.m_Value.x;
    delta.y = dest->y - this->m_angRotation.m_Value.y;
    delta.z = dest->z - this->m_angRotation.m_Value.z;
    AngleVectorsTranspose(angles: &delta, &forward, &right, &up);
    v7 = 1.0 / time;
    v8 = (unsigned int)this->m_iEFlags >> 12;
    v9 = (float)((float)((float)((float)(right.y * offset.y) + (float)(right.x * offset.x)) + (float)(right.z * offset.z))
               - offset.y)
       * v7;
    v10 = (float)((float)((float)((float)(up.y * offset.y) + (float)(up.x * offset.x)) + (float)(up.z * offset.z))
                - offset.z)
        * v7;
    offset.x = (float)((float)((float)((float)(forward.y * offset.y) + (float)(forward.x * offset.x))
                             + (float)(forward.z * offset.z))
                     - offset.x)
             * v7;
    offset.y = v9;
    offset.z = v10;
    if ( (v8 & 1) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    vecAbsVelocity.x = this->m_vecAbsVelocity.x + offset.x;
    vecAbsVelocity.y = this->m_vecAbsVelocity.y + offset.y;
    v11 = this->m_train;
    vecAbsVelocity.z = this->m_vecAbsVelocity.z + offset.z;
    CBaseEntity::SetAbsVelocity(this: v11, &vecAbsVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10236FB0
// Name: public: virtual void CFuncTrackChange::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackChange::Use(
        CFuncTrackChange *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        CBaseEntity *useType,
        float value)
{
  TOGGLE_STATE m_toggle_state; // esi
  int v6; // eax
  int v7; // eax
  CBaseEntity *v8; // ecx
  CBaseEntity_vtbl *v9; // eax

  m_toggle_state = this->m_toggle_state;
  if ( m_toggle_state != TS_AT_TOP )
  {
    if ( m_toggle_state != TS_AT_BOTTOM )
      return;
    v7 = CFuncTrackChange::EvaluateTrain(this, pcurrent: this->m_trackBottom);
    v8[1].m_iEFlags = v7;
  }
  else
  {
    v6 = CFuncTrackChange::EvaluateTrain(this, pcurrent: this->m_trackTop);
    v8[1].m_iEFlags = v6;
  }
  if ( v8[1].m_iEFlags == 1 )
  {
    CBaseEntity::EmitSound(this: v8, soundname: "FuncTrackChange.Blocking", soundtime: 0.0, duration: nullptr);
  }
  else
  {
    v9 = v8->__vftable;
    v8[1].m_iName.m_Value.pszValue = nullptr;
    if ( m_toggle_state != TS_AT_TOP )
      ((void (*)(void))v9[1].GetRefEHandle)();
    else
      ((void (*)(void))v9[1].GetCollideable)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237050
// Name: public: void CFuncTrackAuto::TriggerTrackChange(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackAuto::TriggerTrackChange(CFuncTrackAuto *this, inputdata_t *inputdata)
{
  TOGGLE_STATE m_toggle_state; // eax
  CPathTrack *m_trackBottom; // edi
  CBaseEntity *pActivator; // ecx
  TRAIN_CODE v6; // eax
  TOGGLE_STATE v7; // eax
  CFuncTrackAuto_vtbl *v8; // edx
  CPathTrack *Next; // eax

  if ( this->m_use != 0 )
  {
    m_toggle_state = this->m_toggle_state;
    if ( m_toggle_state != TS_AT_TOP )
    {
      if ( m_toggle_state == TS_AT_BOTTOM )
        m_trackBottom = this->m_trackBottom;
      else
        m_trackBottom = nullptr;
    }
    else
    {
      m_trackBottom = this->m_trackTop;
    }
    pActivator = inputdata->pActivator;
    if ( inputdata->pActivator != nullptr
      && (pActivator->m_iClassname.pszValue == "func_tracktrain"
       || CBaseEntity::ClassMatchesComplex(this: pActivator, pszClassOrWildcard: "func_tracktrain") != 0) )
    {
      v6 = CFuncTrackChange::EvaluateTrain(this, pcurrent: m_trackBottom);
      this->m_code = v6;
      if ( v6 == TRAIN_FOLLOWING )
      {
        v7 = this->m_toggle_state;
        if ( v7 != this->m_targetState )
        {
          v8 = this->__vftable;
          this->m_use = 0;
          if ( v7 != TS_AT_TOP )
            ((void (*)(void))v8->GoUp)();
          else
            ((void (*)(void))v8->GoDown)();
        }
      }
    }
    else
    {
      if ( m_trackBottom != nullptr )
      {
        Next = CPathTrack::GetNext(this: m_trackBottom);
        if ( Next != nullptr
          && this->m_train->m_ppath != Next
          && CBaseEntity::ShouldToggle(this, useType: USE_TOGGLE, currentState: this->m_targetState) != 0 )
        {
          this->m_targetState = this->m_targetState == 0;
        }
      }
      this->UpdateAutoTargets(this, a2: this->m_targetState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237160
// Name: public: virtual void CFuncTrackAuto::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackAuto::Use(
        CFuncTrackAuto *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  TOGGLE_STATE m_toggle_state; // eax
  CPathTrack *m_trackBottom; // edi
  TRAIN_CODE v8; // eax
  TOGGLE_STATE v9; // eax
  bool v10; // zf
  CFuncTrackAuto_vtbl *v11; // eax
  CPathTrack *Next; // eax

  if ( this->m_use != 0 )
  {
    m_toggle_state = this->m_toggle_state;
    if ( m_toggle_state != TS_AT_TOP )
    {
      if ( m_toggle_state == TS_AT_BOTTOM )
        m_trackBottom = this->m_trackBottom;
      else
        m_trackBottom = nullptr;
    }
    else
    {
      m_trackBottom = this->m_trackTop;
    }
    if ( pActivator != nullptr
      && (pActivator->m_iClassname.pszValue == "func_tracktrain"
       || CBaseEntity::ClassMatchesComplex(this: pActivator, pszClassOrWildcard: "func_tracktrain") != 0) )
    {
      v8 = CFuncTrackChange::EvaluateTrain(this, pcurrent: m_trackBottom);
      this->m_code = v8;
      if ( v8 == TRAIN_FOLLOWING )
      {
        v9 = this->m_toggle_state;
        if ( v9 != this->m_targetState )
        {
          v10 = v9 == TS_AT_TOP;
          v11 = this->__vftable;
          this->m_use = 0;
          if ( v10 )
            ((void (*)(void))v11->GoDown)();
          else
            ((void (*)(void))v11->GoUp)();
        }
      }
    }
    else
    {
      if ( m_trackBottom != nullptr )
      {
        Next = CPathTrack::GetNext(this: m_trackBottom);
        if ( Next != nullptr
          && this->m_train->m_ppath != Next
          && CBaseEntity::ShouldToggle(this, useType, currentState: this->m_targetState) != 0 )
        {
          this->m_targetState = this->m_targetState == 0;
        }
      }
      this->UpdateAutoTargets(this, a2: this->m_targetState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237310
// Name: PlatSpawnInsideTrigger
// Source: json
//------------------------------------------------------------------------------
void __usercall PlatSpawnInsideTrigger(edict_t *pevPlatform@<edi>)
{
  CBaseEntity *v1; // eax
  CPlatTrigger *v2; // esi
  IServerUnknown *m_pUnk; // ecx
  CFuncPlat *v4; // eax

  v1 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v2 = (CPlatTrigger *)v1;
  if ( v1 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v1, bServerOnly: false);
    v2->__vftable = (CPlatTrigger_vtbl *)&CPlatTrigger::`vftable';
  }
  else
  {
    v2 = nullptr;
  }
  v2->PostConstructor(this: v2, a2: "plat_trigger");
  if ( pevPlatform != nullptr && (m_pUnk = pevPlatform->m_pUnk) != nullptr )
  {
    v4 = (CFuncPlat *)m_pUnk->GetBaseEntity(this: m_pUnk);
    CPlatTrigger::SpawnInsideTrigger(this: v2, pPlatform: v4);
  }
  else
  {
    CPlatTrigger::SpawnInsideTrigger(this: v2, pPlatform: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237370
// Name: public: virtual void CFuncPlatRot::GoDown(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncPlatRot::GoDown(CFuncPlatRot *this@<ecx>, float a2@<ebx>, int a3@<edi>)
{
  float m_flMoveDoneTime; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float flSpeed; // [esp+0h] [ebp-20h]
  QAngle v11; // [esp+8h] [ebp-18h] BYREF
  QAngle vecAngVelocity; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  CBasePlatTrain::PlayMovingSound(this, a2, a3);
  flSpeed = this->m_flSpeed;
  this->m_toggle_state = TS_GOING_DOWN;
  this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncPlat::CallHitBottom;
  CBaseToggle::LinearMove(this, a2: (int)&savedregs, vecDest: &this->m_vecPosition2, flSpeed);
  m_flMoveDoneTime = this->m_flMoveDoneTime;
  if ( m_flMoveDoneTime < 0.0 )
    v5 = -1.0;
  else
    v5 = m_flMoveDoneTime - this->m_flLocalTime;
  v6 = this->m_start.x - this->m_angRotation.m_Value.x;
  v7 = this->m_start.y - this->m_angRotation.m_Value.y;
  v8 = this->m_start.z - this->m_angRotation.m_Value.z;
  v11.x = v6;
  v11.y = v7;
  v11.z = v8;
  if ( v5 < 0.1 )
  {
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &v11);
    CBaseEntity::SetMoveDoneTime(this, flDelay: 1.0);
  }
  else
  {
    v9 = 1.0 / v5;
    vecAngVelocity.x = v6 * v9;
    vecAngVelocity.y = v9 * v7;
    vecAngVelocity.z = v9 * v8;
    CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237480
// Name: public: virtual void CFuncPlatRot::GoUp(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncPlatRot::GoUp(CFuncPlatRot *this@<ecx>, float a2@<ebx>, int a3@<edi>)
{
  float m_flMoveDoneTime; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float flSpeed; // [esp+0h] [ebp-20h]
  QAngle v11; // [esp+8h] [ebp-18h] BYREF
  QAngle vecAngVelocity; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  CBasePlatTrain::PlayMovingSound(this, a2, a3);
  flSpeed = this->m_flSpeed;
  this->m_toggle_state = TS_GOING_UP;
  this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncPlat::CallHitTop;
  CBaseToggle::LinearMove(this, a2: (int)&savedregs, vecDest: &this->m_vecPosition1, flSpeed);
  m_flMoveDoneTime = this->m_flMoveDoneTime;
  if ( m_flMoveDoneTime < 0.0 )
    v5 = -1.0;
  else
    v5 = m_flMoveDoneTime - this->m_flLocalTime;
  v6 = this->m_end.x - this->m_angRotation.m_Value.x;
  v7 = this->m_end.y - this->m_angRotation.m_Value.y;
  v8 = this->m_end.z - this->m_angRotation.m_Value.z;
  v11.x = v6;
  v11.y = v7;
  v11.z = v8;
  if ( v5 < 0.1 )
  {
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &v11);
    CBaseEntity::SetMoveDoneTime(this, flDelay: 1.0);
  }
  else
  {
    v9 = 1.0 / v5;
    vecAngVelocity.x = v6 * v9;
    vecAngVelocity.y = v9 * v7;
    vecAngVelocity.z = v9 * v8;
    CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237590
// Name: public: CFuncTrackTrain::CFuncTrackTrain(void)
// Source: json
//------------------------------------------------------------------------------
CFuncTrackTrain *__thiscall CFuncTrackTrain::CFuncTrackTrain(CFuncTrackTrain *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CFuncTrackTrain_vtbl *)&CFuncTrackTrain::`vftable';
  this->m_OnStart.m_Value.iVal = 0;
  this->m_OnStart.m_Value.eVal.m_Index = -1;
  this->m_OnStart.m_Value.fieldType = FIELD_VOID;
  this->m_OnNext.m_Value.iVal = 0;
  this->m_OnNext.m_Value.eVal.m_Index = -1;
  this->m_OnNext.m_Value.fieldType = FIELD_VOID;
  this->m_OnArrivedAtDestinationNode.m_Value.iVal = 0;
  this->m_OnArrivedAtDestinationNode.m_Value.eVal.m_Index = -1;
  this->m_OnArrivedAtDestinationNode.m_Value.fieldType = FIELD_VOID;
  this->m_eVelocityType = TrainVelocity_Instantaneous;
  this->m_eOrientationType = TrainOrientation_AtPathTracks;
  this->m_lastBlockPos.x = 0.0;
  this->m_lastBlockPos.y = 0.0;
  this->m_lastBlockPos.z = 0.0;
  this->m_lastBlockTick = gpGlobals->tickcount;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10237670
// Name: private: void CFuncTrackTrain::UpdateTrainOrientation(class CPathTrack __near *,class CPathTrack __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::UpdateTrainOrientation(
        CFuncTrackTrain *this,
        CPathTrack *pPrev,
        CPathTrack *pNext,
        const Vector *nextPos,
        float flInterval)
{
  TrainOrientationType_t m_eOrientationType; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (this->m_spawnflags.m_Value & 0x10) == 0 )
  {
    m_eOrientationType = this->m_eOrientationType;
    if ( m_eOrientationType == TrainOrientation_AtPathTracks )
    {
      CFuncTrackTrain::UpdateOrientationAtPathTracks(this, pPrev, pNext, nextPos, flInterval);
    }
    else if ( (unsigned int)(m_eOrientationType - 2) <= 1 )
    {
      CFuncTrackTrain::UpdateOrientationBlend(
        this,
        a2: COERCE_FLOAT(&savedregs),
        eOrientationType: m_eOrientationType,
        pPrev,
        pNext,
        nextPos,
        flInterval);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102376E0
// Name: public: virtual void CFuncTrackChange::GoDown(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncTrackChange::GoDown(CFuncTrackChange *this@<ecx>, float a2@<ebx>, int a3@<edi>)
{
  QAngle *p_m_start; // edi
  float m_flMoveDoneTime; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float flSpeed; // [esp+4h] [ebp-24h]
  QAngle v12; // [esp+10h] [ebp-18h] BYREF
  QAngle vecAngVelocity; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  if ( this->m_code != TRAIN_BLOCKING )
  {
    this->UpdateAutoTargets(this, a2: 3);
    if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
    {
      p_m_start = &this->m_start;
      flSpeed = this->m_flSpeed;
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncPlat::CallHitBottom;
      this->m_toggle_state = TS_GOING_DOWN;
      CBaseToggle::AngularMove(this, a2: COERCE_FLOAT(&savedregs), vecDestAngle: &this->m_start, flSpeed);
    }
    else
    {
      CFuncPlatRot::GoDown(this, a2, a3);
      m_flMoveDoneTime = this->m_flMoveDoneTime;
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncPlat::CallHitBottom;
      if ( m_flMoveDoneTime < 0.0 )
        v6 = -1.0;
      else
        v6 = m_flMoveDoneTime - this->m_flLocalTime;
      v7 = this->m_start.x - this->m_angRotation.m_Value.x;
      v8 = this->m_start.y - this->m_angRotation.m_Value.y;
      v9 = this->m_start.z - this->m_angRotation.m_Value.z;
      p_m_start = &this->m_start;
      v12.x = v7;
      v12.y = v8;
      v12.z = v9;
      if ( v6 < 0.1 )
      {
        CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &v12);
        CBaseEntity::SetMoveDoneTime(this, flDelay: 1.0);
      }
      else
      {
        v10 = 1.0 / v6;
        vecAngVelocity.x = v7 * v10;
        vecAngVelocity.y = v10 * v8;
        vecAngVelocity.z = v10 * v9;
        CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
      }
    }
    if ( this->m_code == TRAIN_FOLLOWING )
    {
      CFuncTrackChange::UpdateTrain(this, dest: p_m_start);
      this->m_train->m_ppath = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237850
// Name: public: virtual void CFuncTrackChange::GoUp(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncTrackChange::GoUp(CFuncTrackChange *this@<ecx>, float a2@<ebx>, int a3@<edi>)
{
  QAngle *p_m_end; // edi
  float m_flMoveDoneTime; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float flSpeed; // [esp+4h] [ebp-24h]
  QAngle v12; // [esp+10h] [ebp-18h] BYREF
  QAngle vecAngVelocity; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  if ( this->m_code != TRAIN_BLOCKING )
  {
    this->UpdateAutoTargets(this, a2: 2);
    if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
    {
      p_m_end = &this->m_end;
      flSpeed = this->m_flSpeed;
      this->m_toggle_state = TS_GOING_UP;
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncPlat::CallHitTop;
      CBaseToggle::AngularMove(this, a2: COERCE_FLOAT(&savedregs), vecDestAngle: &this->m_end, flSpeed);
    }
    else
    {
      CFuncPlatRot::GoUp(this, a2, a3);
      m_flMoveDoneTime = this->m_flMoveDoneTime;
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncPlat::CallHitTop;
      if ( m_flMoveDoneTime < 0.0 )
        v6 = -1.0;
      else
        v6 = m_flMoveDoneTime - this->m_flLocalTime;
      v7 = this->m_end.x - this->m_angRotation.m_Value.x;
      v8 = this->m_end.y - this->m_angRotation.m_Value.y;
      v9 = this->m_end.z - this->m_angRotation.m_Value.z;
      p_m_end = &this->m_end;
      v12.x = v7;
      v12.y = v8;
      v12.z = v9;
      if ( v6 < 0.1 )
      {
        CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &v12);
        CBaseEntity::SetMoveDoneTime(this, flDelay: 1.0);
      }
      else
      {
        v10 = 1.0 / v6;
        vecAngVelocity.x = v7 * v10;
        vecAngVelocity.y = v10 * v8;
        vecAngVelocity.z = v10 * v9;
        CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
      }
    }
    if ( this->m_code == TRAIN_FOLLOWING )
    {
      CFuncTrackChange::UpdateTrain(this, dest: p_m_end);
      this->m_train->m_ppath = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237A50
// Name: public: virtual void CFuncPlat::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::Precache(CFuncPlat *this)
{
  string_t *p_m_NoiseMoving; // esi
  const char *pszValue; // esi
  const char *v4; // ebx

  p_m_NoiseMoving = &this->m_NoiseMoving;
  UTIL_ValidateSoundName(name: &this->m_NoiseMoving, defaultStr: "Plat.DefaultMoving");
  UTIL_ValidateSoundName(name: &this->m_NoiseArrived, defaultStr: "Plat.DefaultArrive");
  pszValue = p_m_NoiseMoving->pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CBaseEntity::PrecacheScriptSound(soundname: pszValue);
  v4 = this->m_NoiseArrived.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v4);
  if ( !this->IsTogglePlat(this) )
    PlatSpawnInsideTrigger(pevPlatform: this->m_Network.m_pPev);
}

//------------------------------------------------------------------------------
// Address: 0x10237AC0
// Name: FindPhysicsBlockerForHierarchy
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__usercall FindPhysicsBlockerForHierarchy@<eax>(int a1@<edi>, CBaseEntity *pParentEntity)
{
  CBaseEntity **m_pMemory; // eax
  int v3; // ecx
  IPhysicsObject *m_pPhysicsObject; // edi
  int v5; // esi
  int v6; // eax
  CBaseEntity *v7; // edi
  double v8; // st7
  unsigned int v9; // eax
  float v10; // xmm0_4
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > list; // [esp+8h] [ebp-3Ch] BYREF
  Vector normal; // [esp+1Ch] [ebp-28h] BYREF
  float v15; // [esp+28h] [ebp-1Ch]
  float v16; // [esp+2Ch] [ebp-18h]
  float v17; // [esp+30h] [ebp-14h]
  IPhysicsObject *pPhysics; // [esp+34h] [ebp-10h]
  int i; // [esp+38h] [ebp-Ch]
  float maxForce; // [esp+3Ch] [ebp-8h]
  CBaseEntity *pPhysicsBlocker; // [esp+40h] [ebp-4h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  memset(&list, 0, sizeof(list));
  GetAllInHierarchy(pParent: pParentEntity, &list);
  m_pMemory = list.m_Memory.m_pMemory;
  v3 = 0;
  pPhysicsBlocker = nullptr;
  maxForce = 0.0;
  for ( i = 0; v3 < list.m_Size; i = v3 )
  {
    m_pPhysicsObject = m_pMemory[v3]->m_pPhysicsObject;
    pPhysics = m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      v5 = ((int (__thiscall *)(IPhysicsObject *, int))m_pPhysicsObject->CreateFrictionSnapshot)(
             a1: m_pPhysicsObject,
             a2: a1);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5) != 0 )
      {
        do
        {
          v6 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 8))(a1: v5, a2: 1);
          v7 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 68))(a1: v6);
          if ( v7->m_MoveType.m_Value == 6 )
          {
            (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v5 + 20))(a1: v5, a2: &normal);
            v8 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v5 + 24))(a1: v5);
            v9 = (unsigned int)pParentEntity->m_iEFlags >> 12;
            v15 = normal.x * v8;
            v16 = normal.y * v8;
            v17 = v8 * normal.z;
            if ( (v9 & 1) != 0 )
              CBaseEntity::CalcAbsoluteVelocity(this: pParentEntity, a2: (int)&savedregs);
            v10 = (float)((float)(pParentEntity->m_vecAbsVelocity.y * v16)
                        + (float)(pParentEntity->m_vecAbsVelocity.x * v15))
                + (float)(pParentEntity->m_vecAbsVelocity.z * v17);
            if ( pPhysicsBlocker == nullptr || v10 > maxForce )
            {
              pPhysicsBlocker = v7;
              maxForce = v10;
            }
          }
          (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 48))(a1: v5);
        }
        while ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5) != 0 );
        m_pPhysicsObject = pPhysics;
      }
      a1 = v5;
      ((void (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->DestroyFrictionSnapshot)(a1: m_pPhysicsObject);
      m_pMemory = list.m_Memory.m_pMemory;
      v3 = i;
    }
    ++v3;
  }
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = m_pMemory;
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return pPhysicsBlocker;
}

//------------------------------------------------------------------------------
// Address: 0x10237C80
// Name: public: virtual void CFuncTrackTrain::Blocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CFuncTrackTrain::Blocked(CFuncTrackTrain *this@<ecx>, int a2@<ebp>, CBaseEntity *pOther)
{
  const char *pszValue; // eax
  const char *DebugName; // eax
  unsigned int v6; // xmm1_4
  unsigned int v7; // xmm2_4
  float m_flBlockDamage; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  __int128 v11; // xmm0
  unsigned int v12; // eax
  __int128 v13; // xmm0
  const char *v14; // eax
  const char *v15; // eax
  float flDamage; // xmm0_4
  const CTakeDamageInfo *v17; // eax
  const char *v18; // [esp+4h] [ebp-B8h]
  double v19; // [esp+8h] [ebp-B4h]
  const char *separationDuration; // [esp+Ch] [ebp-B0h]
  CTakeDamageInfo v21; // [esp+24h] [ebp-98h] BYREF
  __int128 v22; // [esp+80h] [ebp-3Ch] BYREF
  __int128 vecNewVelocity; // [esp+90h] [ebp-2Ch] OVERLAPPED BYREF
  float v24; // [esp+ACh] [ebp-10h]
  _DWORD v25[2]; // [esp+B0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+BCh] [ebp+0h]

  v25[0] = a2;
  v25[1] = retaddr;
  if ( (pOther->m_fFlags.m_Value & 1) != 0 && CBaseEntity::GetGroundEntity(this: pOther) == this )
  {
    pszValue = pOther->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    separationDuration = pszValue;
    DebugName = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 1, a2: "TRAIN(%s): Blocked by %s\n", DebugName, separationDuration);
    LODWORD(v24) = LODWORD(this->m_flSpeed) & _mask__AbsFloat_;
    if ( v24 > 50.0 )
      v24 = 50.0;
    pOther->GetVelocity(this: pOther, a2: (Vector *)((char *)&v22 + 4), a3: nullptr);
    if ( *((float *)&v22 + 3) == 0.0 )
    {
      *(_QWORD *)((char *)&vecNewVelocity + 4) = 0;
      *((float *)&vecNewVelocity + 3) = v24;
      CBaseEntity::ApplyAbsVelocityImpulse(this: pOther, vecImpulse: (const Vector *)((char *)&vecNewVelocity + 4));
    }
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)v25);
    if ( (pOther->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pOther, a2: (int)v25);
    *(float *)&v6 = pOther->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
    *(float *)&v7 = pOther->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
    *((float *)&vecNewVelocity + 1) = pOther->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
    *((_QWORD *)&vecNewVelocity + 1) = __PAIR64__(v7, v6);
    VectorNormalize(vec: (Vector *)((char *)&vecNewVelocity + 4));
    m_flBlockDamage = this->m_flBlockDamage;
    *((float *)&vecNewVelocity + 1) = *((float *)&vecNewVelocity + 1) * m_flBlockDamage;
    *((float *)&vecNewVelocity + 2) = *((float *)&vecNewVelocity + 2) * m_flBlockDamage;
    *((float *)&vecNewVelocity + 3) = *((float *)&vecNewVelocity + 3) * m_flBlockDamage;
    CBaseEntity::SetAbsVelocity(this: pOther, vecAbsVelocity: (const Vector *)((char *)&vecNewVelocity + 4));
    if ( (this->m_spawnflags.m_Value & 0x200) == 0 )
      goto LABEL_28;
    v24 = COERCE_FLOAT(FindPhysicsBlockerForHierarchy(a1: (int)pOther, pParentEntity: this));
    if ( v24 != 0.0 )
    {
      if ( gpGlobals->tickcount - this->m_lastBlockTick > 10 )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)v25);
        v9 = this->m_vecAbsOrigin.x - this->m_lastBlockPos.x;
        v10 = (float)((float)((float)(this->m_vecAbsOrigin.y - this->m_lastBlockPos.y)
                            * (float)(this->m_vecAbsOrigin.y - this->m_lastBlockPos.y))
                    + (float)((float)(this->m_vecAbsOrigin.z - this->m_lastBlockPos.z)
                            * (float)(this->m_vecAbsOrigin.z - this->m_lastBlockPos.z)))
            + (float)(v9 * v9);
        v11 = 0;
        v12 = (unsigned int)this->m_iEFlags >> 12;
        *(float *)&v11 = fsqrt(v10);
        v22 = v11;
        if ( (v12 & 1) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v25);
        v13 = 0;
        *(float *)&v13 = fsqrt(
                           (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                                 + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
                         + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z));
        vecNewVelocity = v13;
        if ( (float)((float)((float)(gpGlobals->interval_per_tick * *(float *)&v13) * 10.0) * 0.1) > *(float *)&v22 )
          EntityPhysics_CreateSolver(
            pMovingEntity: this,
            pPhysicsObject: (CBaseEntity *)LODWORD(v24),
            disableCollisions: true,
            separationDuration: (void (__thiscall *)(CBaseEntity *))0x40800000);
        if ( *(float *)&v22 > 1.0 )
          goto LABEL_24;
      }
      if ( this->m_lastBlockTick < 0 )
      {
LABEL_24:
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)v25);
        this->m_lastBlockPos.x = this->m_vecAbsOrigin.x;
        this->m_lastBlockPos.y = this->m_vecAbsOrigin.y;
        this->m_lastBlockPos.z = this->m_vecAbsOrigin.z;
        this->m_lastBlockTick = gpGlobals->tickcount;
      }
    }
    if ( !pOther->IsPlayer(this: pOther) )
    {
LABEL_28:
      v14 = pOther->m_iClassname.pszValue;
      if ( v14 == nullptr )
        v14 = locale;
      v19 = this->m_flBlockDamage;
      v18 = v14;
      v15 = CBaseEntity::GetDebugName(this);
      _DevWarning(a1: 2, a2: "TRAIN(%s): Blocked by %s (dmg:%.2f)\n", v15, v18, v19);
      flDamage = this->m_flBlockDamage;
      if ( flDamage > 0.0 )
      {
        v17 = CTakeDamageInfo::CTakeDamageInfo(
                this: &v21,
                pInflictor: this,
                pAttacker: this,
                flDamage,
                bitsDamageType: 1,
                iKillType: 0,
                iObjectsPenetrated: 0);
        CBaseEntity::TakeDamage(this: pOther, a2: (int)this, inputInfo: v17);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10238030
// Name: private: void CFuncTrackTrain::ArriveAtNode(class CPathTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::ArriveAtNode(CFuncTrackTrain *this, CPathTrack *pNode)
{
  CPathTrack *v2; // edi
  CPathTrack *Next; // eax
  int v5; // edi
  edict_t *m_pPev; // ecx
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  float m_flSpeed; // xmm0_4
  const char *v10; // eax
  const char *DebugName; // [esp-4h] [ebp-14h]
  double fDelay; // [esp+0h] [ebp-10h]

  v2 = pNode;
  Next = CPathTrack::GetNext(this: pNode);
  CFuncTrackTrain::FirePassInputs(this, pStart: pNode, pEnd: Next, forward: true);
  if ( (pNode->m_spawnflags.m_Value & 8) != 0 )
  {
    v5 = this->m_spawnflags.m_Value | 2;
    if ( this->m_spawnflags.m_Value != v5 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v5;
    }
    v2 = pNode;
  }
  if ( this->m_strPathTarget.pszValue == nullptr )
    goto LABEL_15;
  pszValue = this->m_strPathTarget.pszValue;
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
  if ( EntityByName != nullptr && v2 == (CPathTrack *)EntityByName )
  {
    COutputEvent::FireOutput(this: &this->m_OnArrivedAtDestinationNode, pActivator: v2, pCaller: this, fDelay: 0.0);
    this->m_oldSpeed = this->m_flSpeed;
    this->m_strPathTarget.pszValue = nullptr;
    this->m_flSpeed = 0.0;
  }
  else
  {
LABEL_15:
    if ( (this->m_spawnflags.m_Value & 2) != 0 )
    {
      m_flSpeed = v2->m_flSpeed;
      if ( m_flSpeed != 0.0 )
      {
        CFuncTrackTrain::SetSpeed(this, flSpeed: m_flSpeed, bAccel: false);
        fDelay = v2->m_flSpeed;
        DebugName = CBaseEntity::GetDebugName(this: v2);
        v10 = CBaseEntity::GetDebugName(this);
        _DevMsg(a1: 2, a2: "TrackTrain %s arrived at %s, speed to %4.2f\n", v10, DebugName, fDelay);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10238170
// Name: public: virtual void CFuncTrackChange::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackChange::Precache(CFuncTrackChange *this)
{
  CFuncPlat::Precache(this);
  CBaseEntity::PrecacheScriptSound(soundname: "FuncTrackChange.Blocking");
}

//------------------------------------------------------------------------------
// Address: 0x10238290
// Name: public: void CFuncTrackTrain::InputTeleportToPathNode(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::InputTeleportToPathNode(CFuncTrackTrain *this, inputdata_t *inputdata)
{
  variant_t *p_value; // esi
  const char *iVal; // eax
  const char *v5; // eax
  CBasePlayer *EntityByName; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: &inputdata->value);
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  this->m_strPathTarget.pszValue = iVal;
  if ( p_value->fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  v5 = (const char *)p_value->iVal;
  if ( p_value->iVal == 0 )
    v5 = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: v5,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
  {
    this->m_ppath = (CPathTrack *)EntityByName;
    CFuncTrackTrain::ArriveAtNode(this, pNode: (CPathTrack *)EntityByName);
    CFuncTrackTrain::TeleportToPathTrack(this, pTeleport: this->m_ppath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10238320
// Name: public: void CFuncTrackTrain::InputLockOrientation(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::InputLockOrientation(CFuncTrackTrain *this, inputdata_t *inputdata)
{
  int v3; // edi
  edict_t *m_pPev; // ecx

  v3 = this->m_spawnflags.m_Value | 0x10;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
    }
    this->m_spawnflags.m_Value = v3;
  }
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
}

//------------------------------------------------------------------------------
// Address: 0x10238370
// Name: public: void CFuncTrackTrain::InputUnlockOrientation(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::InputUnlockOrientation(CFuncTrackTrain *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_spawnflags = &this->m_spawnflags;
  v3 = this->m_spawnflags.m_Value & 0xFFFFFFEF;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_spawnflags->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102383C0
// Name: public: virtual void CFuncTrackChange::UpdateAutoTargets(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackChange::UpdateAutoTargets(CFuncTrackChange *this, int toggleState)
{
  CPathTrack *m_trackTop; // ecx

  m_trackTop = this->m_trackTop;
  if ( m_trackTop != nullptr && this->m_trackBottom != nullptr )
  {
    if ( toggleState != 0 )
    {
      CBaseEntity::AddSpawnFlags(this: m_trackTop, nFlags: 1);
      if ( toggleState == 1 )
      {
        CBaseEntity::RemoveSpawnFlags(this: this->m_trackBottom, nFlags: 1);
        return;
      }
    }
    else
    {
      CBaseEntity::RemoveSpawnFlags(this: m_trackTop, nFlags: 1);
    }
    CBaseEntity::AddSpawnFlags(this: this->m_trackBottom, nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10238B10
// Name: public: virtual void CFuncPlat::HitBottom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::HitBottom(CFuncPlat *this)
{
  signed int v2; // ebx
  CSoundControllerImp *Controller; // eax
  const Vector *v4; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v6; // eax
  const char *pszValue; // eax
  edict_t *m_pPev; // eax
  EmitSound_t ep; // [esp+18h] [ebp-74h] BYREF
  CPASAttenuationFilter filter; // [esp+60h] [ebp-2Ch] BYREF
  float attenuation[3]; // [esp+80h] [ebp-Ch] BYREF
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  v2 = 0;
  if ( this->m_pMovementSound != nullptr )
  {
    Controller = CSoundEnvelopeController::GetController();
    Controller->SoundDestroy(this: Controller, a2: this->m_pMovementSound);
    this->m_pMovementSound = nullptr;
  }
  if ( this->m_NoiseArrived.pszValue != nullptr )
  {
    v4 = (const Vector *)((int (__thiscall *)(CFuncPlat *))this->GetSoundEmissionOrigin)(a1: this);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v4);
    GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v6 = (const Vector *)((int (__thiscall *)(CFuncPlat *, float *, int))GetSoundEmissionOrigin)(
                           a1: this,
                           a2: attenuation,
                           a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v6,
      attenuation: COERCE_FLOAT(attenuation));
    ep.m_hSoundScriptHandle = -1;
    pszValue = this->m_NoiseArrived.pszValue;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nSoundEntryVersion = 1;
    ep.m_nChannel = 1;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    m_pPev = this->m_Network.m_pPev;
    ep.m_flVolume = this->m_volume;
    ep.m_SoundLevel = SNDLVL_NORM;
    if ( m_pPev != nullptr )
      v2 = m_pPev - gpGlobals->pEdicts;
    CBaseEntity::EmitSound(&filter, iEntIndex: v2, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
    this->m_toggle_state = TS_AT_BOTTOM;
  }
  else
  {
    this->m_toggle_state = TS_AT_BOTTOM;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10238C70
// Name: public: virtual void CFuncPlat::HitTop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlat::HitTop(CFuncPlat *this)
{
  CSoundControllerImp *Controller; // eax
  const Vector *v3; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v5; // eax
  const char *pszValue; // eax
  edict_t *m_pPev; // eax
  signed int v8; // eax
  bool (__thiscall *IsTogglePlat)(CBasePlatTrain *); // edx
  EmitSound_t ep; // [esp+18h] [ebp-74h] BYREF
  CPASAttenuationFilter filter; // [esp+60h] [ebp-2Ch] BYREF
  float attenuation[3]; // [esp+80h] [ebp-Ch] BYREF
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  if ( this->m_pMovementSound != nullptr )
  {
    Controller = CSoundEnvelopeController::GetController();
    Controller->SoundDestroy(this: Controller, a2: this->m_pMovementSound);
    this->m_pMovementSound = nullptr;
  }
  if ( this->m_NoiseArrived.pszValue != nullptr )
  {
    v3 = (const Vector *)((int (__thiscall *)(CFuncPlat *))this->GetSoundEmissionOrigin)(a1: this);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v3);
    GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v5 = (const Vector *)((int (__thiscall *)(CFuncPlat *, float *, int))GetSoundEmissionOrigin)(
                           a1: this,
                           a2: attenuation,
                           a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v5,
      attenuation: COERCE_FLOAT(attenuation));
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_nSoundEntryVersion = 1;
    ep.m_nChannel = 1;
    pszValue = this->m_NoiseArrived.pszValue;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_hSoundScriptHandle = -1;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    m_pPev = this->m_Network.m_pPev;
    ep.m_flVolume = this->m_volume;
    ep.m_SoundLevel = SNDLVL_NORM;
    if ( m_pPev != nullptr )
      v8 = m_pPev - gpGlobals->pEdicts;
    else
      v8 = 0;
    CBaseEntity::EmitSound(&filter, iEntIndex: v8, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  IsTogglePlat = this->IsTogglePlat;
  this->m_toggle_state = TS_AT_TOP;
  if ( !IsTogglePlat(this) )
  {
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncPlat::CallGoDown;
    CBaseEntity::SetMoveDoneTime(this, flDelay: 3.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10238E70
// Name: public: virtual void CFuncPlatRot::HitBottom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlatRot::HitBottom(CFuncPlatRot *this)
{
  CFuncPlat::HitBottom(this);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  CBaseEntity::SetLocalAngles(this, angles: &this->m_start);
}

//------------------------------------------------------------------------------
// Address: 0x10238EA0
// Name: public: virtual void CFuncPlatRot::HitTop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncPlatRot::HitTop(CFuncPlatRot *this)
{
  CFuncPlat::HitTop(this);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  CBaseEntity::SetLocalAngles(this, angles: &this->m_end);
}

//------------------------------------------------------------------------------
// Address: 0x10238ED0
// Name: public: void CFuncTrain::Wait(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrain::Wait(CFuncTrain *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v4; // eax
  IHandleEntity *v5; // ecx
  float flDelay; // xmm0_4
  CSoundControllerImp *v7; // eax
  const char *v8; // eax
  edict_t *v9; // eax
  signed int v10; // eax
  int v11; // edi
  edict_t *m_pPev; // ecx
  CSoundControllerImp *Controller; // eax
  const Vector *v14; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v16; // eax
  const char *pszValue; // eax
  edict_t *v18; // eax
  signed int v19; // eax
  EmitSound_t ep; // [esp+40h] [ebp-7Ch] BYREF
  CPASAttenuationFilter filter; // [esp+88h] [ebp-34h] BYREF
  variant_t emptyVariant; // [esp+A8h] [ebp-14h] BYREF
  int savedregs; // [esp+BCh] [ebp+0h] BYREF

  m_Index = this->m_hCurrentTarget.m_Index;
  emptyVariant.iVal = 0;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *, const char *, CFuncTrain *, CFuncTrain *, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD))m_pEntity->__vftable[13].dtr_IHandleEntity)(
    a1: m_pEntity,
    a2: "InPass",
    a3: this,
    a4: this,
    a5: 0,
    a6: LODWORD(emptyVariant.vecVal[1]),
    a7: LODWORD(emptyVariant.vecVal[2]),
    a8: -1,
    a9: 0,
    a10: 0);
  v4 = this->m_hCurrentTarget.m_Index;
  if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    v5 = nullptr;
  else
    v5 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  if ( ((int)v5[190].__vftable & 1) != 0 || (this->m_spawnflags.m_Value & 1) != 0 )
  {
    v11 = this->m_spawnflags.m_Value | 1;
    if ( this->m_spawnflags.m_Value != v11 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v11;
    }
    if ( this->m_pMovementSound != nullptr )
    {
      Controller = CSoundEnvelopeController::GetController();
      Controller->SoundDestroy(this: Controller, a2: this->m_pMovementSound);
      this->m_pMovementSound = nullptr;
    }
    if ( this->m_NoiseArrived.pszValue != nullptr )
    {
      v14 = (const Vector *)((int (__thiscall *)(CFuncTrain *))this->GetSoundEmissionOrigin)(a1: this);
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
      CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v14);
      GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
      filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
      v16 = (const Vector *)((int (__thiscall *)(CFuncTrain *, color32_s *, int))GetSoundEmissionOrigin)(
                              a1: this,
                              a2: &emptyVariant.rgbaVal + 2,
                              a3: 1061997773);
      CPASAttenuationFilter::Filter(
        this: &filter,
        a2: (int)&savedregs,
        origin: v16,
        attenuation: COERCE_FLOAT((variant_t *)(&emptyVariant.rgbaVal + 2)));
      ep.m_hSoundScriptHandle = -1;
      pszValue = this->m_NoiseArrived.pszValue;
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
      v18 = this->m_Network.m_pPev;
      ep.m_flVolume = this->m_volume;
      ep.m_SoundLevel = SNDLVL_NORM;
      if ( v18 != nullptr )
        v19 = v18 - gpGlobals->pEdicts;
      else
        v19 = 0;
      CBaseEntity::EmitSound(&filter, iEntIndex: v19, params: &ep);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
    CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
  }
  else
  {
    flDelay = this->m_flWait;
    if ( flDelay == 0.0 )
    {
      CFuncTrain::Next(this);
    }
    else
    {
      CBaseEntity::SetMoveDoneTime(this, flDelay);
      if ( this->m_pMovementSound != nullptr )
      {
        v7 = CSoundEnvelopeController::GetController();
        v7->SoundDestroy(this: v7, a2: this->m_pMovementSound);
        this->m_pMovementSound = nullptr;
      }
      if ( this->m_NoiseArrived.pszValue != nullptr )
      {
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
        EmitSound_t::EmitSound_t(this: &ep);
        v8 = this->m_NoiseArrived.pszValue;
        ep.m_nChannel = 2;
        ep.m_pSoundName = v8;
        if ( v8 == nullptr )
          ep.m_pSoundName = locale;
        v9 = this->m_Network.m_pPev;
        ep.m_flVolume = this->m_volume;
        ep.m_SoundLevel = SNDLVL_NORM;
        if ( v9 != nullptr )
          v10 = v9 - gpGlobals->pEdicts;
        else
          v10 = 0;
        CBaseEntity::EmitSound(&filter, iEntIndex: v10, params: &ep);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        CRecipientFilter::~CRecipientFilter(this: &filter);
      }
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncTrain::Next;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10239220
// Name: public: void CFuncTrain::Next(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrain::Next(CFuncTrain *this)
{
  CBaseEntity *NextTarget; // eax
  float *v3; // edi
  CSoundControllerImp *Controller; // eax
  const char *pszValue; // eax
  float m_volume; // xmm0_4
  edict_t *v7; // esi
  signed int v8; // esi
  unsigned int m_Index; // edx
  int v10; // ecx
  CEntInfo *v11; // eax
  unsigned int v12; // edx
  IHandleEntity *v13; // eax
  int v14; // ecx
  IHandleEntity *m_pEntity; // eax
  float v16; // xmm0_4
  const char *DebugName; // eax
  unsigned int v18; // eax
  IHandleEntity *v19; // ecx
  Vector *v20; // eax
  int m_Value; // eax
  unsigned int v22; // edx
  edict_t *m_pPev; // ecx
  Vector *v24; // eax
  EmitSound_t ep; // [esp+14h] [ebp-78h] BYREF
  CPASAttenuationFilter filter; // [esp+5Ch] [ebp-30h] BYREF
  Vector vecOrigin; // [esp+7Ch] [ebp-10h] BYREF
  unsigned int v28; // [esp+88h] [ebp-4h]
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  NextTarget = CBaseEntity::GetNextTarget(this);
  v3 = (float *)NextTarget;
  if ( NextTarget != nullptr )
  {
    this->m_iszLastTarget.pszValue = this->m_target.pszValue;
    this->m_target.pszValue = NextTarget->m_target.pszValue;
    this->m_flWait = NextTarget->GetDelay(this: NextTarget);
    m_Index = this->m_hCurrentTarget.m_Index;
    if ( m_Index != -1 )
    {
      v10 = (unsigned __int16)m_Index;
      v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v12 = HIWORD(m_Index);
      if ( v11->m_SerialNumber == v12 && v11->m_pEntity != nullptr )
      {
        v13 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v12
            ? g_pEntityList->m_EntPtrArray[v10].m_pEntity
            : nullptr;
        if ( *(float *)&v13[130].__vftable != 0.0 )
        {
          v14 = v10;
          if ( g_pEntityList->m_EntPtrArray[v14].m_SerialNumber == v12 )
            m_pEntity = g_pEntityList->m_EntPtrArray[v14].m_pEntity;
          else
            m_pEntity = nullptr;
          v16 = *(float *)&m_pEntity[130].__vftable;
          this->m_flSpeed = v16;
          DebugName = CBaseEntity::GetDebugName(this);
          _DevMsg(a1: 2, a2: "Train %s speed to %4.2f\n", DebugName, v16);
        }
      }
    }
    this->m_hCurrentTarget.m_Index = *(_DWORD *)(*(int (__thiscall **)(float *))(*(_DWORD *)v3 + 8))(a1: v3);
    this->m_hEnemy.m_Index = *(_DWORD *)(*(int (__thiscall **)(float *))(*(_DWORD *)v3 + 8))(a1: v3);
    v18 = this->m_hCurrentTarget.m_Index;
    if ( v18 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
      v19 = nullptr;
    else
      v19 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
    if ( ((int)v19[190].__vftable & 2) != 0 )
    {
      CBaseEntity::AddEffects(this, nEffects: 8);
      v20 = AllocTempVector();
      v20->x = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x) * 0.5)
             + this->m_Collision.m_vecMins.m_Value.x;
      v20->y = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y) * 0.5)
             + this->m_Collision.m_vecMins.m_Value.y;
      v20->z = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z) * 0.5)
             + this->m_Collision.m_vecMins.m_Value.z;
      vecOrigin.x = v3[175] - v20->x;
      vecOrigin.y = v3[176] - v20->y;
      vecOrigin.z = v3[177] - v20->z;
      UTIL_SetOrigin(entity: this, &vecOrigin, bFireTriggers: false);
      CFuncTrain::Wait(this);
    }
    else
    {
      CBasePlatTrain::PlayMovingSound(this, a2: 0.0, a3: (int)v3);
      m_Value = this->m_fEffects.m_Value;
      v22 = m_Value & 0xFFFFFFF7;
      v28 = m_Value & 0xFFFFFFF7;
      if ( m_Value != (m_Value & 0xFFFFFFF7) )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
          {
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
            v22 = v28;
          }
        }
        this->m_fEffects.m_Value = v22;
      }
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncTrain::Wait;
      v24 = AllocTempVector();
      v24->x = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x) * 0.5)
             + this->m_Collision.m_vecMins.m_Value.x;
      v24->y = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y) * 0.5)
             + this->m_Collision.m_vecMins.m_Value.y;
      v24->z = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z) * 0.5)
             + this->m_Collision.m_vecMins.m_Value.z;
      vecOrigin.x = v3[175] - v24->x;
      vecOrigin.y = v3[176] - v24->y;
      vecOrigin.z = v3[177] - v24->z;
      CBaseToggle::LinearMove(this, a2: (int)&savedregs, vecDest: &vecOrigin, flSpeed: this->m_flSpeed);
    }
  }
  else
  {
    if ( this->m_pMovementSound != nullptr )
    {
      Controller = CSoundEnvelopeController::GetController();
      Controller->SoundDestroy(this: Controller, a2: this->m_pMovementSound);
      this->m_pMovementSound = nullptr;
    }
    if ( this->m_NoiseArrived.pszValue != nullptr )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
      ep.m_hSoundScriptHandle = -1;
      pszValue = this->m_NoiseArrived.pszValue;
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
      m_volume = this->m_volume;
      v7 = this->m_Network.m_pPev;
      ep.m_flVolume = m_volume;
      ep.m_SoundLevel = SNDLVL_NORM;
      if ( v7 != nullptr )
        v8 = v7 - gpGlobals->pEdicts;
      else
        v8 = 0;
      CBaseEntity::EmitSound(&filter, iEntIndex: v8, params: &ep);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10239640
// Name: public: virtual void CFuncTrain::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrain::Activate(CFuncTrain *this)
{
  unsigned int m_Index; // eax
  Vector *v3; // eax
  unsigned int v4; // ecx
  float *m_pEntity; // ecx
  int v6; // esi
  edict_t *m_pPev; // ecx
  Vector vecOrigin; // [esp+Ch] [ebp-Ch] BYREF

  CBaseEntity::Activate(this);
  if ( !this->m_activated )
  {
    CFuncTrain::SetupTarget(this);
    this->m_activated = true;
    m_Index = this->m_hCurrentTarget.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      v3 = AllocTempVector();
      v3->x = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x) * 0.5)
            + this->m_Collision.m_vecMins.m_Value.x;
      v3->y = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y) * 0.5)
            + this->m_Collision.m_vecMins.m_Value.y;
      v3->z = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z) * 0.5)
            + this->m_Collision.m_vecMins.m_Value.z;
      v4 = this->m_hCurrentTarget.m_Index;
      if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
        m_pEntity = nullptr;
      else
        m_pEntity = (float *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      vecOrigin.x = m_pEntity[175] - v3->x;
      vecOrigin.y = m_pEntity[176] - v3->y;
      vecOrigin.z = m_pEntity[177] - v3->z;
      UTIL_SetOrigin(entity: this, &vecOrigin, bFireTriggers: false);
      if ( this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_BSP )
        CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
      if ( this->m_iName.m_Value.pszValue != nullptr )
      {
        v6 = this->m_spawnflags.m_Value | 1;
        if ( this->m_spawnflags.m_Value != v6 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
            this->m_spawnflags.m_Value = v6;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
            this->m_spawnflags.m_Value = v6;
          }
        }
      }
      else
      {
        CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
        this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncTrain::Next;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10239820
// Name: public: void CFuncTrain::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrain::Start(CFuncTrain *this)
{
  int m_Value; // eax
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    m_Value = this->m_spawnflags.m_Value;
    v3 = m_Value & 0xFFFFFFFE;
    if ( m_Value != (m_Value & 0xFFFFFFFE) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_spawnflags.m_Value = v3;
        CFuncTrain::Next(this);
        return;
      }
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      this->m_spawnflags.m_Value = v3;
    }
    CFuncTrain::Next(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10239880
// Name: public: void CFuncTrain::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrain::Stop(CFuncTrain *this)
{
  int m_Value; // eax
  int v3; // edi
  edict_t *m_pPev; // ecx
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *m_pEntity; // eax
  const char *pszValue; // eax
  edict_t *v14; // eax
  signed int v15; // eax
  EmitSound_t ep; // [esp+14h] [ebp-68h] BYREF
  CPASAttenuationFilter filter; // [esp+5Ch] [ebp-20h] BYREF

  if ( (this->m_spawnflags.m_Value & 1) == 0 )
  {
    m_Value = this->m_spawnflags.m_Value;
    v3 = m_Value | 1;
    if ( m_Value != (m_Value | 1) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v3;
    }
    m_Index = this->m_hEnemy.m_Index;
    if ( m_Index != -1 )
    {
      v6 = (unsigned __int16)m_Index;
      v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v8 = HIWORD(m_Index);
      if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
      {
        v9 = v6;
        v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
        v11 = &g_pEntityList->m_EntPtrArray[v9];
        if ( v10 )
          m_pEntity = v11->m_pEntity;
        else
          m_pEntity = nullptr;
        this->m_target.pszValue = (const char *)m_pEntity[51].__vftable;
      }
    }
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    if ( this->m_NoiseArrived.pszValue != nullptr )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
      pszValue = this->m_NoiseArrived.pszValue;
      ep.m_nFlags = 0;
      ep.m_nPitch = 100;
      memset(&ep.m_pOrigin, 0, 12);
      *(_WORD *)&ep.m_bEmitCloseCaption = 1;
      ep.m_bWarnOnDirectWaveReference = false;
      ep.m_nSpeakerEntity = -1;
      memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
      ep.m_hSoundScriptHandle = -1;
      ep.m_nSoundEntryVersion = 1;
      ep.m_nChannel = 2;
      ep.m_pSoundName = pszValue;
      if ( pszValue == nullptr )
        ep.m_pSoundName = locale;
      v14 = this->m_Network.m_pPev;
      ep.m_flVolume = this->m_volume;
      ep.m_SoundLevel = SNDLVL_NORM;
      if ( v14 != nullptr )
        v15 = v14 - gpGlobals->pEdicts;
      else
        v15 = 0;
      CBaseEntity::EmitSound(&filter, iEntIndex: v15, params: &ep);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
    this->m_pfnMoveDone = nullptr;
    CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10239A30
// Name: public: void CFuncTrackTrain::SoundStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::SoundStop(CFuncTrackTrain *this)
{
  const char *pszValue; // ecx
  edict_t *m_pPev; // eax
  signed int v4; // eax
  const char *v5; // eax
  edict_t *v6; // eax
  signed int v7; // eax
  EmitSound_t ep; // [esp+Ch] [ebp-68h] BYREF
  CPASAttenuationFilter filter; // [esp+54h] [ebp-20h] BYREF

  if ( this->m_bSoundPlaying )
  {
    if ( this->m_iszSoundMove.pszValue != nullptr )
    {
      pszValue = this->m_iszSoundMove.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        v4 = m_pPev - gpGlobals->pEdicts;
      else
        v4 = 0;
      CBaseEntity::StopSound(iEntIndex: v4, iChannel: 6, pSample: pszValue, bIsStoppingSpeakerSound: 0);
    }
    if ( this->m_iszSoundStop.pszValue != nullptr )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
      *(_WORD *)&ep.m_bEmitCloseCaption = 1;
      ep.m_nSoundEntryVersion = 1;
      v5 = this->m_iszSoundStop.pszValue;
      ep.m_nFlags = 0;
      ep.m_nPitch = 100;
      memset(&ep.m_pOrigin, 0, 12);
      ep.m_bWarnOnDirectWaveReference = false;
      ep.m_nSpeakerEntity = -1;
      memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
      ep.m_hSoundScriptHandle = -1;
      ep.m_nChannel = 3;
      ep.m_pSoundName = v5;
      if ( v5 == nullptr )
        ep.m_pSoundName = locale;
      v6 = this->m_Network.m_pPev;
      ep.m_flVolume = this->m_flVolume;
      ep.m_SoundLevel = SNDLVL_NORM;
      if ( v6 != nullptr )
        v7 = v6 - gpGlobals->pEdicts;
      else
        v7 = 0;
      CBaseEntity::EmitSound(&filter, iEntIndex: v7, params: &ep);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
  this->m_bSoundPlaying = false;
}

//------------------------------------------------------------------------------
// Address: 0x10239B60
// Name: public: void CFuncTrackTrain::SoundUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::SoundUpdate(CFuncTrackTrain *this)
{
  float curtime; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  Vector *(__thiscall *GetSoundEmissionOrigin)(struct CFuncTrackTrain *, Vector *); // edx
  float v7; // xmm0_4
  const Vector *v8; // edi
  Vector *(__thiscall *v9)(struct CFuncTrackTrain *, Vector *); // edx
  const Vector *v10; // eax
  const Vector *v11; // edi
  Vector *(__thiscall *v12)(struct CFuncTrackTrain *, Vector *); // edx
  const Vector *v13; // eax
  Vector *v14; // eax
  bool v15; // zf
  const char *pszValue; // eax
  edict_t *m_pPev; // eax
  const char *v18; // eax
  float m_flVolume; // xmm0_4
  edict_t *v20; // eax
  const char *v21; // eax
  float v22; // xmm0_4
  edict_t *v23; // eax
  CPASAttenuationFilter *p_filterReliable; // eax
  const char *v25; // eax
  signed int soundtime; // [esp+1Ch] [ebp-B8h]
  CPASAttenuationFilter filter; // [esp+2Ch] [ebp-A8h] BYREF
  CPASAttenuationFilter filterReliable; // [esp+4Ch] [ebp-88h] BYREF
  float attenuation[3]; // [esp+6Ch] [ebp-68h] BYREF
  Vector vecWorldSpaceCenter; // [esp+78h] [ebp-5Ch] BYREF
  EmitSound_t ep; // [esp+84h] [ebp-50h] BYREF
  float flpitch; // [esp+CCh] [ebp-8h]
  float flSpeedRatio; // [esp+D0h] [ebp-4h]
  int savedregs; // [esp+D4h] [ebp+0h] BYREF

  if ( this->m_iszSoundMove.pszValue != nullptr
    || this->m_iszSoundStart.pszValue != nullptr
    || this->m_iszSoundMovePing.pszValue != nullptr )
  {
    if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) && this->m_bSoundPlaying )
    {
      curtime = gpGlobals->curtime;
      if ( this->m_flNextMPSoundTime > curtime )
        return;
      this->m_flNextMPSoundTime = curtime + 1.0;
    }
    v3 = 0.0;
    LODWORD(v4) = LODWORD(this->m_flSpeed) & _mask__AbsFloat_;
    if ( (this->m_spawnflags.m_Value & 0x100) != 0 )
      v5 = v4 / this->m_maxSpeed;
    else
      v5 = v4 * 0.001;
    if ( v5 >= 0.0 )
    {
      if ( v5 <= 1.0 )
        v3 = v5;
      else
        v3 = 1.0;
    }
    GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
    v7 = (float)((float)((float)this->m_nMoveSoundMaxPitch - (float)this->m_nMoveSoundMinPitch) * v3)
       + (float)this->m_nMoveSoundMinPitch;
    flSpeedRatio = v3;
    flpitch = v7;
    v8 = (const Vector *)((int (__thiscall *)(CFuncTrackTrain *))GetSoundEmissionOrigin)(a1: this);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v8);
    v9 = this->GetSoundEmissionOrigin;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v10 = (const Vector *)((int (__thiscall *)(CFuncTrackTrain *, float *, int))v9)(
                            a1: this,
                            a2: attenuation,
                            a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v10,
      attenuation: COERCE_FLOAT(attenuation));
    v11 = (const Vector *)((int (__thiscall *)(CFuncTrackTrain *))this->GetSoundEmissionOrigin)(a1: this);
    CRecipientFilter::CRecipientFilter(this: &filterReliable);
    filterReliable.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filterReliable, origin: v11);
    v12 = this->GetSoundEmissionOrigin;
    filterReliable.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v13 = (const Vector *)((int (__thiscall *)(CFuncTrackTrain *, float *, int))v12)(
                            a1: this,
                            a2: attenuation,
                            a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filterReliable,
      a2: (int)&savedregs,
      origin: v13,
      attenuation: COERCE_FLOAT(attenuation));
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filterReliable);
    v14 = this->WorldSpaceCenter(this);
    v15 = !this->m_bSoundPlaying;
    vecWorldSpaceCenter = *v14;
    if ( v15 )
    {
      if ( this->m_iszSoundStart.pszValue != nullptr )
      {
        EmitSound_t::EmitSound_t(this: &ep);
        pszValue = this->m_iszSoundStart.pszValue;
        ep.m_nChannel = 3;
        ep.m_pSoundName = pszValue;
        if ( pszValue == nullptr )
          ep.m_pSoundName = locale;
        m_pPev = this->m_Network.m_pPev;
        ep.m_flVolume = this->m_flVolume;
        ep.m_SoundLevel = SNDLVL_NORM;
        ep.m_pOrigin = &vecWorldSpaceCenter;
        if ( m_pPev != nullptr )
          m_pPev -= (int)gpGlobals->pEdicts;
        CBaseEntity::EmitSound(&filter, iEntIndex: (int)m_pPev, params: &ep);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      }
      if ( this->m_iszSoundMove.pszValue != nullptr )
      {
        EmitSound_t::EmitSound_t(this: &ep);
        v18 = this->m_iszSoundMove.pszValue;
        ep.m_nChannel = 6;
        ep.m_pSoundName = v18;
        if ( v18 == nullptr )
          ep.m_pSoundName = locale;
        m_flVolume = this->m_flVolume;
        ep.m_nPitch = (int)flpitch;
        v20 = this->m_Network.m_pPev;
        ep.m_flVolume = m_flVolume;
        ep.m_SoundLevel = SNDLVL_NORM;
        ep.m_pOrigin = &vecWorldSpaceCenter;
        if ( v20 != nullptr )
          v20 -= (int)gpGlobals->pEdicts;
        CBaseEntity::EmitSound(filter: &filterReliable, iEntIndex: (int)v20, params: &ep);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      }
      this->m_flNextMoveSoundTime = gpGlobals->curtime
                                  + (float)((float)((float)(this->m_flMoveSoundMinTime - this->m_flMoveSoundMaxTime)
                                                  * flSpeedRatio)
                                          + this->m_flMoveSoundMaxTime);
      this->m_bSoundPlaying = true;
    }
    else
    {
      if ( this->m_iszSoundMove.pszValue != nullptr )
      {
        EmitSound_t::EmitSound_t(this: &ep);
        v21 = this->m_iszSoundMove.pszValue;
        ep.m_nChannel = 6;
        ep.m_pSoundName = v21;
        if ( v21 == nullptr )
          ep.m_pSoundName = locale;
        v22 = this->m_flVolume;
        ep.m_nPitch = (int)flpitch;
        ep.m_pOrigin = &vecWorldSpaceCenter;
        ep.m_flVolume = v22;
        ep.m_SoundLevel = SNDLVL_NORM;
        ep.m_nFlags = 2;
        v15 = !g_pGameRules->IsMultiplayer(this: g_pGameRules);
        v23 = this->m_Network.m_pPev;
        if ( v15 )
        {
          if ( v23 != nullptr )
            v23 -= (int)gpGlobals->pEdicts;
          soundtime = (signed int)v23;
          p_filterReliable = &filterReliable;
        }
        else
        {
          if ( v23 != nullptr )
            soundtime = v23 - gpGlobals->pEdicts;
          else
            soundtime = 0;
          p_filterReliable = &filter;
        }
        CBaseEntity::EmitSound(filter: p_filterReliable, iEntIndex: soundtime, params: &ep);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      }
      if ( this->m_iszSoundMovePing.pszValue != nullptr && gpGlobals->curtime > this->m_flNextMoveSoundTime )
      {
        v25 = this->m_iszSoundMovePing.pszValue;
        if ( v25 == nullptr )
          v25 = locale;
        CBaseEntity::EmitSound(this, soundname: v25, soundtime: 0.0, duration: nullptr);
        this->m_flNextMoveSoundTime = RemapVal(
                                        val: flSpeedRatio,
                                        A: 0.0,
                                        B: 1.0,
                                        C: this->m_flMoveSoundMaxTime,
                                        D: this->m_flMoveSoundMinTime)
                                    + gpGlobals->curtime;
      }
    }
    CRecipientFilter::~CRecipientFilter(this: &filterReliable);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023A000
// Name: public: void CFuncTrackTrain::Next(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncTrackTrain::Next(CFuncTrackTrain *this@<ecx>, float a2@<ebp>)
{
  const char *DebugName; // eax
  const char *v4; // eax
  float z; // eax
  CPathTrack *m_ppath; // ecx
  CPathTrack *v7; // edi
  int m_iEFlags; // ecx
  unsigned int v9; // eax
  float y; // ecx
  int v11; // eax
  float v12; // ecx
  int v13; // edx
  float x; // eax
  int v15; // eax
  int v16; // eax
  CPathTrack *Next; // eax
  float v18; // xmm2_4
  __int128 v19; // xmm0
  float v20; // xmm0_4
  float dist; // [esp+0h] [ebp-68h]
  Vector v22; // [esp+20h] [ebp-48h] BYREF
  _QWORD v23[2]; // [esp+2Ch] [ebp-3Ch] BYREF
  Vector v24; // [esp+48h] [ebp-20h] BYREF
  Vector nextPos; // [esp+54h] [ebp-14h] BYREF
  float flSpeed; // [esp+60h] [ebp-8h]
  float retaddr; // [esp+68h] [ebp+0h]

  nextPos.z = a2;
  flSpeed = retaddr;
  if ( this->m_flSpeed == 0.0 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "TRAIN(%s): Speed is 0\n", DebugName);
    CFuncTrackTrain::SoundStop(this);
    return;
  }
  if ( this->m_ppath == nullptr )
  {
    v4 = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "TRAIN(%s): Lost path\n", v4);
    CFuncTrackTrain::SoundStop(this);
    this->m_flSpeed = 0.0;
    return;
  }
  CFuncTrackTrain::SoundUpdate(this);
  z = this->m_vecOrigin.m_Value.z;
  *(_QWORD *)&v24.x = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
  nextPos.x = this->m_flSpeed;
  m_ppath = this->m_ppath;
  v24.z = z;
  dist = nextPos.x * 0.1;
  v24.z = z - this->m_height;
  nextPos.y = 0.0;
  v7 = CPathTrack::LookAhead(this: m_ppath, origin: &v24, dist, move: 1, pNextNext: (CPathTrack **)&nextPos.y);
  if ( this->m_bManualSpeedChanges && nextPos.x < 0.0 != this->m_flDesiredSpeed < 0.0 && v7 == nullptr )
    v7 = this->m_ppath;
  if ( (this->m_debugOverlays & 4) != 0 )
  {
    if ( v7 != nullptr )
    {
      if ( (v7->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&nextPos.z);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&nextPos.z);
      NDebugOverlay::Line(
        origin: &this->m_vecAbsOrigin,
        target: &v7->m_vecAbsOrigin,
        r: 255,
        g: 0,
        b: 0,
        noDepthTest: 1,
        duration: 0.1);
      if ( (v7->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&nextPos.z);
      m_iEFlags = v7->m_iEFlags;
      HIDWORD(v23[0]) = LODWORD(v7->m_vecAbsOrigin.x);
      *(float *)&v23[1] = v7->m_vecAbsOrigin.y;
      *((float *)&v23[1] + 1) = v7->m_vecAbsOrigin.z + 32.0;
      if ( (m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&nextPos.z);
      NDebugOverlay::Line(
        origin: &v7->m_vecAbsOrigin,
        target: (const Vector *)((char *)v23 + 4),
        r: 255,
        g: 0,
        b: 0,
        noDepthTest: 1,
        duration: 0.1);
      v9 = (unsigned int)v7->m_iEFlags >> 11;
      HIDWORD(v23[0]) = 1090519040;
      v23[1] = 0x4100000041000000LL;
      v22.x = -8.0;
      v22.y = -8.0;
      v22.z = -8.0;
      if ( (v9 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&nextPos.z);
      NDebugOverlay::Box(
        origin: &v7->m_vecAbsOrigin,
        mins: &v22,
        maxs: (const Vector *)((char *)v23 + 4),
        r: 255,
        g: 0,
        b: 0,
        a: 0,
        flDuration: 0.1);
    }
    y = nextPos.y;
    if ( LODWORD(nextPos.y) == 0 )
      goto LABEL_35;
    v11 = *(_DWORD *)(LODWORD(nextPos.y) + 196) >> 11;
    nextPos.x = nextPos.y;
    if ( (v11 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(nextPos.y), a2: (int)&nextPos.z);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&nextPos.z);
    NDebugOverlay::Line(
      origin: &this->m_vecAbsOrigin,
      target: (const Vector *)(LODWORD(nextPos.x) + 460),
      r: 0,
      g: 255,
      b: 0,
      noDepthTest: 1,
      duration: 0.1);
    v12 = nextPos.y;
    v13 = *(_DWORD *)(LODWORD(nextPos.y) + 196) >> 11;
    x = nextPos.y;
    nextPos.x = nextPos.y;
    if ( (v13 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(nextPos.y), a2: (int)&nextPos.z);
      v12 = nextPos.y;
      x = nextPos.x;
    }
    v22.x = *(float *)(LODWORD(x) + 460);
    v22.y = *(float *)(LODWORD(x) + 464);
    v22.z = *(float *)(LODWORD(x) + 468) + 32.0;
    v15 = *(_DWORD *)(LODWORD(v12) + 196) >> 11;
    nextPos.x = v12;
    if ( (v15 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(v12), a2: (int)&nextPos.z);
    NDebugOverlay::Line(
      origin: (const Vector *)(LODWORD(nextPos.x) + 460),
      target: &v22,
      r: 0,
      g: 255,
      b: 0,
      noDepthTest: 1,
      duration: 0.1);
    v22.x = 8.0;
    v22.y = 8.0;
    v22.z = 8.0;
    HIDWORD(v23[0]) = -1056964608;
    v23[1] = 0xC1000000C1000000uLL;
    v16 = *(_DWORD *)(LODWORD(nextPos.y) + 196) >> 11;
    nextPos.x = nextPos.y;
    if ( (v16 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(nextPos.y), a2: (int)&nextPos.z);
    NDebugOverlay::Box(
      origin: (const Vector *)(LODWORD(nextPos.x) + 460),
      mins: (const Vector *)((char *)v23 + 4),
      maxs: &v22,
      r: 0,
      g: 255,
      b: 0,
      a: 0,
      flDuration: 0.1);
  }
  y = nextPos.y;
LABEL_35:
  v24.z = this->m_height + v24.z;
  if ( v7 != nullptr )
  {
    CFuncTrackTrain::UpdateTrainVelocity(
      this,
      a2: COERCE_FLOAT((Vector *)&nextPos.z),
      pPrev: v7,
      pNext: (CPathTrack *)LODWORD(y),
      nextPos: &v24,
      flInterval: gpGlobals->frametime);
    CFuncTrackTrain::UpdateTrainOrientation(
      this,
      pPrev: v7,
      pNext: (CPathTrack *)LODWORD(nextPos.y),
      nextPos: &v24,
      flInterval: gpGlobals->frametime);
    if ( v7 != this->m_ppath )
    {
      this->m_ppath = v7;
      CFuncTrackTrain::ArriveAtNode(this, pNode: v7);
      Next = CPathTrack::GetNext(this: v7);
      if ( Next != nullptr && (Next->m_spawnflags.m_Value & 0x10) != 0 )
        CFuncTrackTrain::TeleportToPathTrack(this, pTeleport: Next);
    }
    COutputEvent::FireOutput(this: &this->m_OnNext, pActivator: v7, pCaller: this, fDelay: 0.0);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CFuncTrackTrain::Next,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    this->m_pfnMoveDone = nullptr;
  }
  else
  {
    CFuncTrackTrain::SoundStop(this);
    v22.x = v24.x - this->m_vecOrigin.m_Value.x;
    v22.y = v24.y - this->m_vecOrigin.m_Value.y;
    v22.z = v24.z - this->m_vecOrigin.m_Value.z;
    CBaseEntity::SetLocalVelocity(this, vecVelocity: &v22);
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
    v18 = (float)((float)(this->m_vecVelocity.m_Value.x * this->m_vecVelocity.m_Value.x)
                + (float)(this->m_vecVelocity.m_Value.y * this->m_vecVelocity.m_Value.y))
        + (float)(this->m_vecVelocity.m_Value.z * this->m_vecVelocity.m_Value.z);
    v19 = 0;
    this->m_oldSpeed = this->m_flSpeed;
    *(float *)&v19 = fsqrt(v18);
    *(_OWORD *)v23 = v19;
    this->m_flSpeed = 0.0;
    if ( *(float *)&v19 <= 0.0 )
    {
      CFuncTrackTrain::DeadEnd(this);
    }
    else
    {
      nextPos.x = this->m_oldSpeed;
      v20 = COERCE_FLOAT(LODWORD(nextPos.x) & _mask__AbsFloat_) / *(float *)&v19;
      v22.x = v20 * this->m_vecVelocity.m_Value.x;
      v22.y = this->m_vecVelocity.m_Value.y * v20;
      v22.z = this->m_vecVelocity.m_Value.z * v20;
      CBaseEntity::SetLocalVelocity(this, vecVelocity: &v22);
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncTrackTrain::DeadEnd;
      CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
      CBaseEntity::SetMoveDoneTime(this, flDelay: *(float *)v23 / COERCE_FLOAT(LODWORD(nextPos.x) & _mask__AbsFloat_));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023A680
// Name: public: void CFuncTrackTrain::Find(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::Find(CFuncTrackTrain *this)
{
  const char *pszValue; // eax
  CPathTrack *EntityByName; // eax
  CPathTrack *v4; // ecx
  CPathTrack *m_ppath; // ecx
  float dist; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  unsigned int v9; // ecx
  Vector forward; // [esp+1Ch] [ebp-30h] BYREF
  QAngle nextAngles; // [esp+28h] [ebp-24h] BYREF
  Vector nextPos; // [esp+34h] [ebp-18h] BYREF
  Vector look; // [esp+40h] [ebp-Ch] BYREF

  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = (CPathTrack *)CGlobalEntityList::FindEntityByName(
                                 this: &gEntList,
                                 pStartEntity: nullptr,
                                 szName: pszValue,
                                 pSearchingEntity: nullptr,
                                 pActivator: nullptr,
                                 pCaller: nullptr,
                                 pFilter: nullptr);
  this->m_ppath = EntityByName;
  if ( EntityByName != nullptr )
  {
    if ( EntityByName->m_iClassname.pszValue == "path_track"
      || CBaseEntity::ClassMatchesComplex(this: EntityByName, pszClassOrWildcard: "path_track") != 0
      || (v4 = this->m_ppath) != nullptr
      && (v4->m_iClassname.pszValue == "env_portal_path_track"
       || CBaseEntity::ClassMatchesComplex(this: v4, pszClassOrWildcard: "env_portal_path_track") != 0) )
    {
      m_ppath = this->m_ppath;
      nextPos = (Vector)m_ppath->m_vecOrigin;
      *(_QWORD *)&look.x = *(_QWORD *)&nextPos.x;
      dist = this->m_length;
      look.z = nextPos.z;
      CPathTrack::LookAhead(this: m_ppath, origin: &look, dist, move: 0, pNextNext: nullptr);
      v7 = this->m_height + nextPos.z;
      v8 = this->m_height + look.z;
      v9 = (unsigned int)this->m_spawnflags.m_Value >> 4;
      nextPos.z = v7;
      look.z = v8;
      if ( (v9 & 1) != 0 )
      {
        nextAngles = (QAngle)this->m_angRotation;
      }
      else
      {
        forward.x = look.x - nextPos.x;
        forward.y = look.y - nextPos.y;
        forward.z = v8 - v7;
        VectorAngles(&forward, angles: &nextAngles);
        if ( (this->m_spawnflags.m_Value & 1) != 0 )
          nextAngles.x = 0.0;
      }
      this->Teleport(this, a2: &nextPos, a3: &nextAngles, a4: nullptr, a5: true);
      CFuncTrackTrain::ArriveAtNode(this, pNode: this->m_ppath);
      if ( this->m_flSpeed != 0.0 )
      {
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
        CBaseEntity::ThinkSet(
          this,
          func: (void (__thiscall *)(CBaseEntity *))CFuncTrackTrain::Next,
          thinkTime: 0.0,
          szContext: nullptr);
        CFuncTrackTrain::SoundUpdate(this);
      }
    }
    else
    {
      _Warning(a1: "func_track_train must be on a path of path_track\n");
      this->m_ppath = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023A870
// Name: public: void CFuncTrackTrain::NearestPath(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CFuncTrackTrain::NearestPath(CFuncTrackTrain *this@<ecx>, int a2@<ebp>)
{
  unsigned int v3; // eax
  CBaseEntity *CurrentEntity; // esi
  float v5; // xmm0_4
  float v6; // xmm1_4
  __int128 v7; // xmm0
  CPathTrack *v8; // esi
  const char *v9; // eax
  CPathTrack *Next; // eax
  float x; // xmm1_4
  float y; // xmm3_4
  float z; // xmm5_4
  float v14; // xmm2_4
  __int128 v15; // xmm0
  float v16; // xmm3_4
  __int128 v17; // xmm1
  float m_flSpeed; // xmm0_4
  const char *DebugName; // [esp+4h] [ebp-850h]
  _DWORD v20[3]; // [esp+10h] [ebp-844h] BYREF
  __int128 sphere_2044; // [esp+818h] [ebp-3Ch] OVERLAPPED
  __int128 v22; // [esp+828h] [ebp-2Ch]
  unsigned __int64 flDelay; // [esp+840h] [ebp-14h]
  int v24; // [esp+848h] [ebp-Ch] BYREF
  float closest; // [esp+84Ch] [ebp-8h]
  float retaddr; // [esp+854h] [ebp+0h]

  v24 = a2;
  closest = retaddr;
  v3 = (unsigned int)this->m_iEFlags >> 11;
  flDelay = 1149239296;
  if ( (v3 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&v24);
  CEntitySphereQuery::CEntitySphereQuery(
    this: (CEntitySphereQuery *)v20,
    center: &this->m_vecAbsOrigin,
    radius: 1024.0,
    flagMask: 0);
  CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v20);
  if ( CurrentEntity == nullptr )
    goto LABEL_15;
  do
  {
    if ( (CurrentEntity->m_fFlags.m_Value & 0x4100) == 0
      && (CurrentEntity->m_iClassname.pszValue == "path_track"
       || CBaseEntity::ClassMatchesComplex(this: CurrentEntity, pszClassOrWildcard: "path_track") != 0) )
    {
      if ( (CurrentEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: CurrentEntity, a2: (int)&v24);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&v24);
      v5 = this->m_vecAbsOrigin.x - CurrentEntity->m_vecAbsOrigin.x;
      v6 = (float)((float)((float)(this->m_vecAbsOrigin.y - CurrentEntity->m_vecAbsOrigin.y)
                         * (float)(this->m_vecAbsOrigin.y - CurrentEntity->m_vecAbsOrigin.y))
                 + (float)((float)(this->m_vecAbsOrigin.z - CurrentEntity->m_vecAbsOrigin.z)
                         * (float)(this->m_vecAbsOrigin.z - CurrentEntity->m_vecAbsOrigin.z)))
         + (float)(v5 * v5);
      v7 = 0;
      *(float *)&v7 = fsqrt(v6);
      v22 = v7;
      if ( *(float *)&flDelay > *(float *)&v7 )
        flDelay = __PAIR64__((unsigned int)CurrentEntity, v22);
    }
    ++v20[0];
    CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v20);
  }
  while ( CurrentEntity != nullptr );
  v8 = (CPathTrack *)HIDWORD(flDelay);
  if ( HIDWORD(flDelay) != 0 )
  {
    DebugName = CBaseEntity::GetDebugName(this: (CBaseEntity *)HIDWORD(flDelay));
    v9 = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "TRAIN: %s, Nearest track is %s\n", v9, DebugName);
    Next = CPathTrack::GetNext(this: v8);
    if ( Next != nullptr )
    {
      x = this->m_vecOrigin.m_Value.x;
      y = this->m_vecOrigin.m_Value.y;
      z = this->m_vecOrigin.m_Value.z;
      v14 = (float)((float)((float)(y - v8->m_vecOrigin.m_Value.y) * (float)(y - v8->m_vecOrigin.m_Value.y))
                  + (float)((float)(z - v8->m_vecOrigin.m_Value.z) * (float)(z - v8->m_vecOrigin.m_Value.z)))
          + (float)((float)(x - v8->m_vecOrigin.m_Value.x) * (float)(x - v8->m_vecOrigin.m_Value.x));
      v15 = 0;
      v16 = (float)((float)((float)(y - Next->m_vecOrigin.m_Value.y) * (float)(y - Next->m_vecOrigin.m_Value.y))
                  + (float)((float)(z - Next->m_vecOrigin.m_Value.z) * (float)(z - Next->m_vecOrigin.m_Value.z)))
          + (float)((float)(x - Next->m_vecOrigin.m_Value.x) * (float)(x - Next->m_vecOrigin.m_Value.x));
      v17 = 0;
      *(float *)&v15 = fsqrt(v14);
      *(float *)&v17 = fsqrt(v16);
      v22 = v15;
      sphere_2044 = v17;
      if ( *(float *)&v15 > *(float *)&v17 )
      {
        HIDWORD(flDelay) = Next;
        v8 = Next;
      }
    }
    m_flSpeed = this->m_flSpeed;
    this->m_ppath = v8;
    if ( m_flSpeed != 0.0 )
    {
      CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncTrackTrain::Next;
    }
  }
  else
  {
LABEL_15:
    _Msg(a1: "Can't find a nearby track !!!\n");
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023AB20
// Name: public: virtual void CFuncTrackTrain::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncTrackTrain::OnRestore(CFuncTrackTrain *this@<ecx>, int a2@<ebp>)
{
  CBaseEntity::OnRestore(this);
  if ( this->m_ppath == nullptr )
  {
    CFuncTrackTrain::NearestPath(this, a2);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023AB50
// Name: public: virtual void CFuncTrackTrain::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncTrackTrain::Spawn(CFuncTrackTrain *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  float m_flSpeed; // xmm0_4
  bool v5; // zf
  const char *DebugName; // eax
  const char *v7; // eax
  const Vector *v8; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v9; // edx
  double z; // st7
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  float *v12; // eax
  CFuncTrackTrain *v14; // [esp+18h] [ebp-4h] BYREF

  v14 = this;
  if ( this->m_maxSpeed == 0.0 )
  {
    m_flSpeed = this->m_flSpeed;
    if ( m_flSpeed == 0.0 )
      m_flSpeed = 100.0;
    this->m_maxSpeed = m_flSpeed;
  }
  if ( this->m_nMoveSoundMinPitch == 0 )
    this->m_nMoveSoundMinPitch = 60;
  if ( this->m_nMoveSoundMaxPitch == 0 )
    this->m_nMoveSoundMaxPitch = 200;
  CBaseEntity::SetLocalVelocity(this, vecVelocity: &vec3_origin);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  v5 = this->m_target.pszValue == nullptr;
  this->m_dir = 1.0;
  if ( v5 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    _Msg(a1: "FuncTrackTrain '%s' has no target.\n", DebugName);
  }
  v7 = *(const char **)((int (__thiscall *)(CFuncTrackTrain *, CFuncTrackTrain **, int, int))this->GetModelName)(
                         a1: this,
                         a2: &v14,
                         a3: a2,
                         a4: a3);
  if ( v7 == nullptr )
    v7 = locale;
  this->SetModel(this, a2: v7);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(
    this: &this->m_Collision,
    val: (SolidType_t)((this->m_spawnflags.m_Value & 0x80) != 0 ? SOLID_BSP : SOLID_VPHYSICS));
  if ( (this->m_spawnflags.m_Value & 0x200) != 0 )
    CBaseEntity::AddFlag(this, flags: 0x80000000);
  if ( (this->m_spawnflags.m_Value & 8) != 0 )
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  v8 = this->m_Collision.OBBMins(this: &this->m_Collision);
  v9 = this->m_Collision.CBaseEntity::__vftable;
  this->m_controlMins.x = v8->x;
  this->m_controlMins.y = v8->y;
  z = v8->z;
  OBBMaxs = v9->OBBMaxs;
  this->m_controlMins.z = z;
  v12 = (float *)OBBMaxs(this: &this->m_Collision);
  this->m_controlMaxs.x = *v12;
  this->m_controlMaxs.y = v12[1];
  this->m_controlMaxs.z = v12[2];
  this->m_controlMaxs.z = this->m_controlMaxs.z + 72.0;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CFuncTrackTrain::Find,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  this->Precache(this);
  this->CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023AD40
// Name: public: virtual void CFuncTrackTrain::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::UpdateOnRemove(CFuncTrackTrain *this)
{
  CFuncTrackTrain::SoundStop(this);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023AF30
// Name: public: virtual void CFuncTrackChange::HitBottom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackChange::HitBottom(CFuncTrackChange *this)
{
  CFuncTrackTrain *m_train; // edi

  CFuncPlat::HitBottom(this);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  CBaseEntity::SetLocalAngles(this, angles: &this->m_start);
  if ( this->m_code == TRAIN_FOLLOWING )
  {
    m_train = this->m_train;
    m_train->m_ppath = CPathTrack::Nearest(this: this->m_trackBottom, origin: &m_train->m_vecOrigin.m_Value);
  }
  this->m_pfnMoveDone = nullptr;
  CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
  this->UpdateAutoTargets(this, a2: this->m_toggle_state);
  this->m_use = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023AFC0
// Name: public: virtual void CFuncTrackChange::HitTop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackChange::HitTop(CFuncTrackChange *this)
{
  CFuncTrackTrain *m_train; // edi

  CFuncPlat::HitTop(this);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  CBaseEntity::SetLocalAngles(this, angles: &this->m_end);
  if ( this->m_code == TRAIN_FOLLOWING )
  {
    m_train = this->m_train;
    m_train->m_ppath = CPathTrack::Nearest(this: this->m_trackTop, origin: &m_train->m_vecOrigin.m_Value);
  }
  this->m_pfnMoveDone = nullptr;
  CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
  this->UpdateAutoTargets(this, a2: this->m_toggle_state);
  this->m_use = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023B0C0
// Name: public: virtual void CFuncTrain::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrain::Use(
        CFuncTrain *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  unsigned int v7; // edi
  edict_t *m_pPev; // ecx
  int v9; // edi
  edict_t *v10; // ecx
  unsigned int m_Index; // ecx
  int v12; // eax
  CEntInfo *v13; // edx
  unsigned int v14; // ecx
  int v15; // eax
  bool v16; // zf
  CEntInfo *v17; // eax
  IHandleEntity *m_pEntity; // eax
  CFuncTrain *v19; // esi
  const char *pszValue; // eax
  edict_t *v21; // eax
  signed int v22; // eax
  EmitSound_t ep; // [esp+14h] [ebp-6Ch] BYREF
  CPASAttenuationFilter filter; // [esp+5Ch] [ebp-24h] BYREF
  CFuncTrain *v25; // [esp+7Ch] [ebp-4h]

  m_Value = this->m_spawnflags.m_Value;
  p_m_spawnflags = &this->m_spawnflags;
  v25 = this;
  if ( (m_Value & 1) != 0 )
  {
    v7 = m_Value & 0xFFFFFFFE;
    if ( m_Value != (m_Value & 0xFFFFFFFE) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_spawnflags->m_Value = v7;
        CFuncTrain::Next(this);
        return;
      }
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      this = v25;
      p_m_spawnflags->m_Value = v7;
    }
    CFuncTrain::Next(this);
  }
  else
  {
    v9 = m_Value | 1;
    if ( m_Value != (m_Value | 1) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x2F8u);
      }
      this = v25;
      p_m_spawnflags->m_Value = v9;
    }
    m_Index = this->m_hEnemy.m_Index;
    if ( m_Index != -1 )
    {
      v12 = (unsigned __int16)m_Index;
      v13 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v14 = HIWORD(m_Index);
      if ( v13->m_SerialNumber == v14 && v13->m_pEntity != nullptr )
      {
        v15 = v12;
        v16 = g_pEntityList->m_EntPtrArray[v15].m_SerialNumber == v14;
        v17 = &g_pEntityList->m_EntPtrArray[v15];
        if ( v16 )
          m_pEntity = v17->m_pEntity;
        else
          m_pEntity = nullptr;
        v25->m_target.pszValue = (const char *)m_pEntity[51].__vftable;
      }
    }
    CBaseEntity::SetNextThink(this: v25, thinkTime: -1.0, szContext: nullptr);
    v19 = v25;
    CBaseEntity::SetLocalVelocity(this: v25, vecVelocity: &vec3_origin);
    if ( v25->m_NoiseArrived.pszValue != nullptr )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: v25, attenuation: 0.80000001);
      pszValue = v19->m_NoiseArrived.pszValue;
      ep.m_nFlags = 0;
      ep.m_nPitch = 100;
      memset(&ep.m_pOrigin, 0, 12);
      *(_WORD *)&ep.m_bEmitCloseCaption = 1;
      ep.m_bWarnOnDirectWaveReference = false;
      ep.m_nSpeakerEntity = -1;
      memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
      ep.m_hSoundScriptHandle = -1;
      ep.m_nSoundEntryVersion = 1;
      ep.m_nChannel = 2;
      ep.m_pSoundName = pszValue;
      if ( pszValue == nullptr )
        ep.m_pSoundName = locale;
      v21 = v19->m_Network.m_pPev;
      ep.m_flVolume = v19->m_volume;
      ep.m_SoundLevel = SNDLVL_NORM;
      if ( v21 != nullptr )
        v22 = v21 - gpGlobals->pEdicts;
      else
        v22 = 0;
      CBaseEntity::EmitSound(&filter, iEntIndex: v22, params: &ep);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023B2B0
// Name: public: void CFuncTrain::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrain::InputToggle(CFuncTrain *this, inputdata_t *data)
{
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    CFuncTrain::Start(this);
  else
    CFuncTrain::Stop(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023B2D0
// Name: public: void CFuncTrain::InputStart(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFuncTrain::InputStart(CFuncTrain *this, inputdata_t *data)
{
  CFuncTrain::Start(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023B2E0
// Name: public: void CFuncTrain::InputStop(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFuncTrain::InputStop(CFuncTrain *this, inputdata_t *data)
{
  CFuncTrain::Stop(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023B2F0
// Name: public: void CFuncTrackTrain::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::Stop(CFuncTrackTrain *this)
{
  CBaseEntity::SetLocalVelocity(this, vecVelocity: &vec3_origin);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  this->m_oldSpeed = this->m_flSpeed;
  this->m_flSpeed = 0.0;
  CFuncTrackTrain::SoundStop(this);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1023B5E0
// Name: public: void CFuncTrackTrain::InputStop(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::InputStop(CFuncTrackTrain *this, inputdata_t *inputdata)
{
  CBaseEntity::SetLocalVelocity(this, vecVelocity: &vec3_origin);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  this->m_oldSpeed = this->m_flSpeed;
  this->m_flSpeed = 0.0;
  CFuncTrackTrain::SoundStop(this);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1023B630
// Name: public: void CFuncTrackTrain::InputResume(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFuncTrackTrain::InputResume(CFuncTrackTrain *this@<ecx>, float a2@<ebp>, inputdata_t *inputdata)
{
  this->m_flSpeed = this->m_oldSpeed;
  COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
  CFuncTrackTrain::Next(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1023B660
// Name: public: void CFuncTrackTrain::SetSpeed(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::SetSpeed(CFuncTrackTrain *this, float flSpeed, bool bAccel)
{
  CFuncTrackTrain *v3; // esi
  float m_flSpeed; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  const char *DebugName; // eax
  double v8; // [esp+0h] [ebp-Ch]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  v3 = this;
  m_flSpeed = this->m_flSpeed;
  this->m_bAccelToSpeed = bAccel;
  if ( bAccel )
  {
    v5 = fabs(flSpeed) * this->m_dir;
    this->m_flDesiredSpeed = v5;
    this->m_flSpeedChangeTime = gpGlobals->curtime;
    if ( m_flSpeed == 0.0 && fabs(v5) > 0.0 )
      this->m_flSpeed = 0.1;
    COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
    CFuncTrackTrain::Next(this: v3, a2: COERCE_FLOAT(&savedregs));
  }
  else
  {
    v6 = fabs(flSpeed) * this->m_dir;
    this->m_flSpeed = v6;
    if ( v6 != m_flSpeed )
    {
      if ( v6 == 0.0 )
      {
        CFuncTrackTrain::Stop(this);
      }
      else
      {
        if ( m_flSpeed == 0.0 )
        {
          COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
          this = v3;
        }
        CFuncTrackTrain::Next(this, a2: COERCE_FLOAT(&savedregs));
      }
    }
    v8 = v3->m_flSpeed;
    DebugName = CBaseEntity::GetDebugName(this: v3);
    _DevMsg(a1: 2, a2: "TRAIN(%s), speed to %.2f\n", DebugName, v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023B780
// Name: public: virtual void CFuncTrackAuto::UpdateAutoTargets(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackAuto::UpdateAutoTargets(CFuncTrackAuto *this, int toggleState)
{
  CPathTrack *m_trackTop; // ecx
  CPathTrack *m_trackBottom; // eax
  CPathTrack *Next; // eax
  CPathTrack *v6; // ecx
  CBaseEntity *v7; // edi
  CPathTrack *v8; // ebx
  CFuncTrackTrain *m_train; // ecx

  m_trackTop = this->m_trackTop;
  if ( m_trackTop != nullptr )
  {
    m_trackBottom = this->m_trackBottom;
    if ( m_trackBottom != nullptr )
    {
      if ( this->m_targetState != 0 )
      {
        Next = CPathTrack::GetNext(this: m_trackBottom);
        v6 = this->m_trackTop;
      }
      else
      {
        Next = CPathTrack::GetNext(this: m_trackTop);
        v6 = this->m_trackBottom;
      }
      v7 = Next;
      v8 = CPathTrack::GetNext(this: v6);
      if ( v7 != nullptr )
      {
        CBaseEntity::RemoveSpawnFlags(this: v7, nFlags: 1);
        if ( this->m_code == TRAIN_FOLLOWING )
        {
          m_train = this->m_train;
          if ( m_train != nullptr && m_train->m_flSpeed == 0.0 )
          {
            CFuncTrackTrain::SetSpeed(this: m_train, flSpeed: v7->m_flSpeed, bAccel: false);
            ((void (__stdcall *)(CFuncTrackAuto *, CFuncTrackAuto *, int, _DWORD))this->m_train->Use)(
              a1: this,
              a2: this,
              a3: 2,
              a4: 0);
          }
        }
      }
      if ( v8 != nullptr )
        CBaseEntity::AddSpawnFlags(this: v8, nFlags: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023B850
// Name: public: void CFuncTrackTrain::InputReverse(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFuncTrackTrain::InputReverse(CFuncTrackTrain *this@<ecx>, float a2@<ebp>, inputdata_t *inputdata)
{
  float m_flSpeed; // xmm1_4
  float v5; // xmm0_4
  const char *DebugName; // eax
  double v7; // [esp+0h] [ebp-Ch]

  CFuncTrackTrain::SetDirForward(this, bForward: this->m_dir != 1.0);
  m_flSpeed = this->m_flSpeed;
  this->m_bAccelToSpeed = false;
  v5 = fabs(m_flSpeed) * this->m_dir;
  this->m_flSpeed = v5;
  if ( v5 != m_flSpeed )
  {
    if ( v5 == 0.0 )
    {
      CFuncTrackTrain::Stop(this);
    }
    else
    {
      if ( m_flSpeed == 0.0 )
        COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
      CFuncTrackTrain::Next(this, a2);
    }
  }
  v7 = this->m_flSpeed;
  DebugName = CBaseEntity::GetDebugName(this);
  _DevMsg(a1: 2, a2: "TRAIN(%s), speed to %.2f\n", DebugName, v7);
}

//------------------------------------------------------------------------------
// Address: 0x1023B920
// Name: public: void CFuncTrackTrain::InputStartForward(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFuncTrackTrain::InputStartForward(
        CFuncTrackTrain *this@<ecx>,
        float a2@<ebp>,
        inputdata_t *inputdata)
{
  CPathTrack *m_ppath; // ecx
  float m_maxSpeed; // xmm0_4
  float m_flSpeed; // xmm1_4
  float v7; // xmm0_4
  const char *DebugName; // eax
  double v9; // [esp+0h] [ebp-Ch]

  if ( this->m_dir != 1.0 )
  {
    m_ppath = this->m_ppath;
    if ( m_ppath != nullptr && CPathTrack::GetPrevious(this: m_ppath) != nullptr )
      this->m_ppath = CPathTrack::GetPrevious(this: this->m_ppath);
    this->m_dir = 1.0;
  }
  m_maxSpeed = this->m_maxSpeed;
  m_flSpeed = this->m_flSpeed;
  this->m_bAccelToSpeed = false;
  v7 = fabs(m_maxSpeed) * this->m_dir;
  this->m_flSpeed = v7;
  if ( v7 != m_flSpeed )
  {
    if ( v7 == 0.0 )
    {
      CFuncTrackTrain::Stop(this);
    }
    else
    {
      if ( m_flSpeed == 0.0 )
        COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
      CFuncTrackTrain::Next(this, a2);
    }
  }
  v9 = this->m_flSpeed;
  DebugName = CBaseEntity::GetDebugName(this);
  _DevMsg(a1: 2, a2: "TRAIN(%s), speed to %.2f\n", DebugName, v9);
}

//------------------------------------------------------------------------------
// Address: 0x1023BA10
// Name: public: void CFuncTrackTrain::InputStartBackward(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFuncTrackTrain::InputStartBackward(
        CFuncTrackTrain *this@<ecx>,
        float a2@<ebp>,
        inputdata_t *inputdata)
{
  CPathTrack *m_ppath; // ecx
  float m_maxSpeed; // xmm0_4
  float m_flSpeed; // xmm1_4
  float v7; // xmm0_4
  const char *DebugName; // eax
  double v9; // [esp+0h] [ebp-Ch]

  if ( this->m_dir != -1.0 )
  {
    m_ppath = this->m_ppath;
    if ( m_ppath != nullptr && CPathTrack::GetNext(this: m_ppath) != nullptr )
      this->m_ppath = CPathTrack::GetNext(this: this->m_ppath);
    this->m_dir = -1.0;
  }
  m_maxSpeed = this->m_maxSpeed;
  m_flSpeed = this->m_flSpeed;
  this->m_bAccelToSpeed = false;
  v7 = fabs(m_maxSpeed) * this->m_dir;
  this->m_flSpeed = v7;
  if ( v7 != m_flSpeed )
  {
    if ( v7 == 0.0 )
    {
      CFuncTrackTrain::Stop(this);
    }
    else
    {
      if ( m_flSpeed == 0.0 )
        COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
      CFuncTrackTrain::Next(this, a2);
    }
  }
  v9 = this->m_flSpeed;
  DebugName = CBaseEntity::GetDebugName(this);
  _DevMsg(a1: 2, a2: "TRAIN(%s), speed to %.2f\n", DebugName, v9);
}

//------------------------------------------------------------------------------
// Address: 0x1023BB00
// Name: public: void CFuncTrackTrain::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFuncTrackTrain::InputToggle(CFuncTrackTrain *this@<ecx>, float a2@<ebp>, inputdata_t *inputdata)
{
  CFuncTrackTrain *v3; // esi
  float m_flSpeed; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  const char *DebugName; // eax
  double v8; // [esp+0h] [ebp-Ch]

  v3 = this;
  m_flSpeed = this->m_flSpeed;
  this->m_bAccelToSpeed = false;
  if ( m_flSpeed == 0.0 )
    LODWORD(v5) = LODWORD(this->m_maxSpeed) & _mask__AbsFloat_;
  else
    v5 = 0.0;
  v6 = v5 * this->m_dir;
  this->m_flSpeed = v6;
  if ( v6 != m_flSpeed )
  {
    if ( v6 == 0.0 )
    {
      CFuncTrackTrain::Stop(this);
    }
    else
    {
      if ( m_flSpeed == 0.0 )
      {
        COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
        this = v3;
      }
      CFuncTrackTrain::Next(this, a2);
    }
  }
  v8 = v3->m_flSpeed;
  DebugName = CBaseEntity::GetDebugName(this: v3);
  _DevMsg(a1: 2, a2: "TRAIN(%s), speed to %.2f\n", DebugName, v8);
}

//------------------------------------------------------------------------------
// Address: 0x1023BBC0
// Name: public: virtual void CFuncTrackTrain::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::Use(
        CFuncTrackTrain *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  int v6; // xmm1_4
  float v7; // xmm0_4
  bool v8; // al
  float m_flSpeed; // xmm1_4
  float v10; // xmm0_4
  const char *DebugName; // eax
  double v12; // [esp+0h] [ebp-Ch]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  float delta; // [esp+1Ch] [ebp+10h]

  if ( useType == USE_SET )
  {
    *(float *)&v6 = 1.0;
    v7 = (double)((int)(float)(this->m_flSpeed * 4.0) / (int)this->m_maxSpeed) * 0.25 + (float)(value * 0.25);
    delta = v7;
    if ( v7 > 1.0 || (*(float *)&v6 = -0.25, v7 < -0.25) )
    {
      v7 = *(float *)&v6;
      delta = *(float *)&v6;
    }
    if ( (this->m_spawnflags.m_Value & 4) != 0 && v7 < 0.0 )
    {
      delta = 0.0;
      v8 = true;
    }
    else
    {
      v8 = v7 >= 0.0;
    }
    CFuncTrackTrain::SetDirForward(this, bForward: v8);
    m_flSpeed = this->m_flSpeed;
    v10 = fabs(fabs(delta) * this->m_maxSpeed) * this->m_dir;
    this->m_bAccelToSpeed = false;
    this->m_flSpeed = v10;
    if ( v10 != m_flSpeed )
    {
      if ( v10 == 0.0 )
      {
        CFuncTrackTrain::Stop(this);
      }
      else
      {
        if ( m_flSpeed == 0.0 )
          COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
        CFuncTrackTrain::Next(this, a2: COERCE_FLOAT(&savedregs));
      }
    }
    v12 = this->m_flSpeed;
    DebugName = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "TRAIN(%s), speed to %.2f\n", DebugName, v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023BD20
// Name: public: void CFuncTrackTrain::InputSetSpeedReal(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::InputSetSpeedReal(CFuncTrackTrain *this, inputdata_t *inputdata)
{
  CFuncTrackTrain *v2; // esi
  float flVal; // xmm0_4
  float m_flSpeed; // xmm1_4
  float v5; // xmm0_4
  const char *DebugName; // eax
  double v7; // [esp+0h] [ebp-Ch]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  v2 = this;
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  if ( flVal >= 0.0 )
  {
    if ( flVal > this->m_maxSpeed )
      flVal = this->m_maxSpeed;
  }
  else
  {
    flVal = 0.0;
  }
  m_flSpeed = this->m_flSpeed;
  this->m_bAccelToSpeed = false;
  v5 = COERCE_FLOAT(LODWORD(flVal) & _mask__AbsFloat_) * this->m_dir;
  this->m_flSpeed = v5;
  if ( v5 != m_flSpeed )
  {
    if ( v5 == 0.0 )
    {
      CFuncTrackTrain::Stop(this);
    }
    else
    {
      if ( m_flSpeed == 0.0 )
      {
        COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
        this = v2;
      }
      CFuncTrackTrain::Next(this, a2: COERCE_FLOAT(&savedregs));
    }
  }
  v7 = v2->m_flSpeed;
  DebugName = CBaseEntity::GetDebugName(this: v2);
  _DevMsg(a1: 2, a2: "TRAIN(%s), speed to %.2f\n", DebugName, v7);
}

//------------------------------------------------------------------------------
// Address: 0x1023BDF0
// Name: public: void CFuncTrackTrain::InputSetSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::InputSetSpeed(CFuncTrackTrain *this, inputdata_t *inputdata)
{
  CFuncTrackTrain *v2; // esi
  float flVal; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float m_flSpeed; // xmm1_4
  float v7; // xmm0_4
  const char *DebugName; // eax
  double v9; // [esp+0h] [ebp-Ch]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  v2 = this;
  if ( inputdata->value.fieldType != FIELD_FLOAT )
  {
    flVal = 0.0;
LABEL_6:
    v4 = flVal;
    goto LABEL_7;
  }
  flVal = inputdata->value.flVal;
  if ( flVal < 0.0 )
  {
    v4 = 0.0;
    goto LABEL_7;
  }
  v4 = 1.0;
  if ( flVal <= 1.0 )
    goto LABEL_6;
LABEL_7:
  v5 = this->m_maxSpeed * v4;
  m_flSpeed = this->m_flSpeed;
  this->m_bAccelToSpeed = false;
  v7 = COERCE_FLOAT(LODWORD(v5) & _mask__AbsFloat_) * this->m_dir;
  this->m_flSpeed = v7;
  if ( v7 != m_flSpeed )
  {
    if ( v7 == 0.0 )
    {
      CFuncTrackTrain::Stop(this);
    }
    else
    {
      if ( m_flSpeed == 0.0 )
      {
        COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
        this = v2;
      }
      CFuncTrackTrain::Next(this, a2: COERCE_FLOAT(&savedregs));
    }
  }
  v9 = v2->m_flSpeed;
  DebugName = CBaseEntity::GetDebugName(this: v2);
  _DevMsg(a1: 2, a2: "TRAIN(%s), speed to %.2f\n", DebugName, v9);
}

//------------------------------------------------------------------------------
// Address: 0x1023BED0
// Name: public: void CFuncTrackTrain::InputSetSpeedDir(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::InputSetSpeedDir(CFuncTrackTrain *this, inputdata_t *inputdata)
{
  bool v3; // al
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float m_flSpeed; // xmm1_4
  float v8; // xmm0_4
  const char *DebugName; // eax
  double v10; // [esp+0h] [ebp-Ch]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  float newSpeed; // [esp+14h] [ebp+8h]

  if ( inputdata->value.fieldType == FIELD_FLOAT )
  {
    newSpeed = inputdata->value.flVal;
    v3 = newSpeed >= 0.0;
  }
  else
  {
    newSpeed = 0.0;
    v3 = true;
  }
  CFuncTrackTrain::SetDirForward(this, bForward: v3);
  v4 = fabs(newSpeed);
  if ( v4 >= 0.0 )
  {
    v5 = 1.0;
    if ( v4 <= 1.0 )
      v5 = v4;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = this->m_maxSpeed * v5;
  m_flSpeed = this->m_flSpeed;
  v8 = fabs(v6) * this->m_dir;
  this->m_bAccelToSpeed = false;
  this->m_flSpeed = v8;
  if ( v8 != m_flSpeed )
  {
    if ( v8 == 0.0 )
    {
      CFuncTrackTrain::Stop(this);
    }
    else
    {
      if ( m_flSpeed == 0.0 )
        COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
      CFuncTrackTrain::Next(this, a2: COERCE_FLOAT(&savedregs));
    }
  }
  v10 = this->m_flSpeed;
  DebugName = CBaseEntity::GetDebugName(this);
  _DevMsg(a1: 2, a2: "TRAIN(%s), speed to %.2f\n", DebugName, v10);
}

//------------------------------------------------------------------------------
// Address: 0x1023BFE0
// Name: public: void CFuncTrackTrain::InputSetSpeedDirAccel(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::InputSetSpeedDirAccel(CFuncTrackTrain *this, inputdata_t *inputdata)
{
  bool v3; // al
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float m_flSpeed; // xmm2_4
  float v8; // xmm0_4
  int savedregs; // [esp+8h] [ebp+0h] BYREF
  float newSpeed; // [esp+10h] [ebp+8h]

  if ( inputdata->value.fieldType == FIELD_FLOAT )
  {
    newSpeed = inputdata->value.flVal;
    v3 = newSpeed >= 0.0;
  }
  else
  {
    newSpeed = 0.0;
    v3 = true;
  }
  CFuncTrackTrain::SetDirForward(this, bForward: v3);
  v4 = fabs(newSpeed);
  if ( v4 >= 0.0 )
  {
    v5 = 1.0;
    if ( v4 <= 1.0 )
      v5 = v4;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = this->m_maxSpeed * v5;
  m_flSpeed = this->m_flSpeed;
  v8 = fabs(v6) * this->m_dir;
  this->m_bAccelToSpeed = true;
  this->m_flDesiredSpeed = v8;
  this->m_flSpeedChangeTime = gpGlobals->curtime;
  if ( m_flSpeed == 0.0 && fabs(v8) > 0.0 )
    this->m_flSpeed = 0.1;
  COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
  CFuncTrackTrain::Next(this, a2: COERCE_FLOAT(&savedregs));
}

//------------------------------------------------------------------------------
// Address: 0x1023C0D0
// Name: public: void CFuncTrackTrain::InputMoveToPathNode(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTrackTrain::InputMoveToPathNode(CFuncTrackTrain *this, float inputdata)
{
  variant_t *p_inputdata; // esi
  const char *iVal; // eax
  const char *v5; // eax
  CBasePlayer *EntityByName; // eax
  CPathTrack *m_ppath; // ecx
  CBasePlayer *v8; // edi
  int v9; // esi
  CPathTrack *Next; // eax
  CPathTrack *v11; // ecx
  CPathTrack *v12; // ecx
  int v13; // esi
  CPathTrack *Previous; // eax

  p_inputdata = (variant_t *)(LODWORD(inputdata) + 8);
  if ( *(_DWORD *)(LODWORD(inputdata) + 24) == 2 )
  {
    iVal = (const char *)p_inputdata->iVal;
    if ( p_inputdata->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: (variant_t *)(LODWORD(inputdata) + 8));
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  this->m_strPathTarget.pszValue = iVal;
  if ( p_inputdata->fieldType != FIELD_STRING )
  {
    inputdata = 0.0;
    p_inputdata = (variant_t *)&inputdata;
  }
  v5 = (const char *)p_inputdata->iVal;
  if ( p_inputdata->iVal == 0 )
    v5 = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: v5,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  m_ppath = this->m_ppath;
  v8 = EntityByName;
  v9 = 1000;
  if ( m_ppath != nullptr && EntityByName != nullptr )
  {
    inputdata = m_ppath->m_flSpeed;
    if ( inputdata == 0.0 )
      inputdata = this->m_maxSpeed;
    if ( EntityByName == (CBasePlayer *)m_ppath )
    {
      if ( this->m_dir != 1.0 )
      {
        if ( CPathTrack::GetPrevious(this: m_ppath) == nullptr )
          goto LABEL_19;
        CFuncTrackTrain::SetDirForward(this, bForward: true);
        goto LABEL_37;
      }
      if ( CPathTrack::GetNext(this: m_ppath) == nullptr )
      {
LABEL_19:
        CFuncTrackTrain::Stop(this);
        return;
      }
LABEL_36:
      CFuncTrackTrain::SetDirForward(this, bForward: false);
LABEL_37:
      CFuncTrackTrain::SetSpeed(this, flSpeed: inputdata, bAccel: false);
      return;
    }
    do
    {
      --v9;
      Next = CPathTrack::GetNext(this: m_ppath);
      if ( Next == nullptr )
        break;
      m_ppath = Next;
      if ( v8 == (CBasePlayer *)Next )
        goto LABEL_26;
    }
    while ( v9 != 0 );
    if ( Next == (CPathTrack *)v8 )
    {
LABEL_26:
      if ( this->m_dir != 1.0 )
      {
        v11 = this->m_ppath;
        if ( v11 != nullptr && CPathTrack::GetPrevious(this: v11) != nullptr )
          this->m_ppath = CPathTrack::GetPrevious(this: this->m_ppath);
        this->m_dir = 1.0;
      }
      goto LABEL_37;
    }
    v12 = this->m_ppath;
    v13 = 1000;
    do
    {
      --v13;
      Previous = CPathTrack::GetPrevious(this: v12);
      if ( Previous == nullptr )
        break;
      v12 = Previous;
      if ( v8 == (CBasePlayer *)Previous )
        goto LABEL_36;
    }
    while ( v13 != 0 );
    if ( Previous == (CPathTrack *)v8 )
      goto LABEL_36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040B800
// Name: CBasePlatTrain_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBasePlatTrain_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBasePlatTrain>(__formal: nullptr);
  CBasePlatTrain_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B810
// Name: CFuncPlat_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncPlat_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncPlat>(__formal: nullptr);
  CFuncPlat_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B860
// Name: CFuncPlatRot_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncPlatRot_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncPlatRot>(__formal: nullptr);
  CFuncPlatRot_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B890
// Name: CFuncTrain_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncTrain_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncTrain>(__formal: nullptr);
  CFuncTrain_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B8A0
// Name: CFuncTrackTrain_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncTrackTrain_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncTrackTrain>(__formal: nullptr);
  CFuncTrackTrain_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B8F0
// Name: DT_FuncTrackTrain::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncTrackTrain::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncTrackTrain::g_SendTable);
  return atexit(func: DT_FuncTrackTrain::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B910
// Name: DT_FuncTrackTrain::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncTrackTrain::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncTrackTrain::ignored>();
  DT_FuncTrackTrain::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B920
// Name: CFuncTrainControls_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncTrainControls_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncTrainControls>(__formal: nullptr);
  CFuncTrainControls_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B970
// Name: CFuncTrackChange_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncTrackChange_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncTrackChange>(__formal: nullptr);
  CFuncTrackChange_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B980
// Name: CFuncTrackAuto_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncTrackAuto_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncTrackAuto>(__formal: nullptr);
  CFuncTrackAuto_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E920
// Name: DT_FuncTrackTrain::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncTrackTrain::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncTrackTrain::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10238420
// Name: struct datamap_t __near * DataMapInit<class CBasePlatTrain>(class CBasePlatTrain __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBasePlatTrain>()
{
  CSoundPatchSaveRestoreOps *SoundSaveRestoreOps; // eax

  if ( (_S2_227 & 1) == 0 )
  {
    _S2_227 |= 1u;
    nameHolder_418.m_pszBase = "CBasePlatTrain";
    nameHolder_418.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_418.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_418.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_418.m_Names.m_Size = 0;
    nameHolder_418.m_Names.m_pElements = nullptr;
    nameHolder_418.m_nLenBase = 14;
    atexit(func: DataMapInit_CBasePlatTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBasePlatTrain::m_DataMap.baseMap = &CBaseToggle::m_DataMap;
  if ( (_S2_227 & 2) == 0 )
  {
    _S2_227 |= 2u;
    SoundSaveRestoreOps = GetSoundSaveRestoreOps();
    *(_QWORD *)dataDesc_397[4].flatOffset = 0;
    dataDesc_397[3].pSaveRestoreOps = SoundSaveRestoreOps;
    dataDesc_397[4].flags = 6;
    *(_QWORD *)dataDesc_397[5].flatOffset = 0;
    dataDesc_397[4].fieldSize = 1;
    dataDesc_397[5].flags = 2;
    dataDesc_397[6].flags = 2;
    *(_QWORD *)&dataDesc_397[3].td = 0;
    *(_QWORD *)&dataDesc_397[3].override_field = 0;
    *(_QWORD *)&dataDesc_397[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_397[3].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_397[6].flatOffset = 0;
    dataDesc_397[3].inputFunc = nullptr;
    dataDesc_397[4].fieldType = FIELD_FLOAT;
    dataDesc_397[4].fieldName = "m_volume";
    dataDesc_397[4].fieldOffset = 984;
    dataDesc_397[4].externalName = "volume";
    dataDesc_397[4].pSaveRestoreOps = nullptr;
    dataDesc_397[4].inputFunc = nullptr;
    dataDesc_397[4].td = nullptr;
    dataDesc_397[4].fieldSizeInBytes = 4;
    dataDesc_397[4].override_field = nullptr;
    dataDesc_397[4].override_count = 0;
    dataDesc_397[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_397[4].flatGroup = 0;
    dataDesc_397[5].fieldType = FIELD_FLOAT;
    dataDesc_397[5].fieldName = "m_flTWidth";
    dataDesc_397[5].fieldOffset = 988;
    dataDesc_397[5].fieldSize = 1;
    dataDesc_397[5].externalName = nullptr;
    dataDesc_397[5].pSaveRestoreOps = nullptr;
    dataDesc_397[5].inputFunc = nullptr;
    dataDesc_397[5].td = nullptr;
    dataDesc_397[5].fieldSizeInBytes = 4;
    dataDesc_397[5].override_field = nullptr;
    dataDesc_397[5].override_count = 0;
    dataDesc_397[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_397[5].flatGroup = 0;
    dataDesc_397[6].fieldType = FIELD_FLOAT;
    dataDesc_397[6].fieldName = "m_flTLength";
    dataDesc_397[6].fieldOffset = 992;
    dataDesc_397[6].fieldSize = 1;
    dataDesc_397[6].externalName = nullptr;
    dataDesc_397[6].pSaveRestoreOps = nullptr;
    dataDesc_397[6].inputFunc = nullptr;
    dataDesc_397[6].td = nullptr;
    dataDesc_397[6].fieldSizeInBytes = 4;
    dataDesc_397[6].override_field = nullptr;
    dataDesc_397[6].override_count = 0;
    dataDesc_397[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_397[6].flatGroup = 0;
    dataDesc_397[7].fieldType = FIELD_FLOAT;
    dataDesc_397[7].fieldName = "m_flLip";
    dataDesc_397[7].fieldOffset = 864;
    dataDesc_397[7].fieldSize = 1;
    dataDesc_397[7].flags = 6;
    dataDesc_397[7].externalName = "lip";
    dataDesc_397[7].pSaveRestoreOps = nullptr;
    dataDesc_397[7].inputFunc = nullptr;
    dataDesc_397[7].td = nullptr;
    dataDesc_397[7].fieldSizeInBytes = 4;
    dataDesc_397[7].override_field = nullptr;
    dataDesc_397[7].override_count = 0;
    dataDesc_397[7].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_397[7].flatOffset = 0;
    *(_DWORD *)&dataDesc_397[7].flatGroup = 0;
    dataDesc_397[8].fieldType = FIELD_FLOAT;
    dataDesc_397[8].fieldTolerance = 0.0;
    dataDesc_397[9].fieldTolerance = 0.0;
    dataDesc_397[8].fieldName = "m_flWait";
    dataDesc_397[8].fieldOffset = 860;
    dataDesc_397[8].fieldSize = 1;
    dataDesc_397[8].flags = 6;
    dataDesc_397[8].externalName = "wait";
    dataDesc_397[8].pSaveRestoreOps = nullptr;
    dataDesc_397[8].inputFunc = nullptr;
    dataDesc_397[8].td = nullptr;
    dataDesc_397[8].fieldSizeInBytes = 4;
    dataDesc_397[8].override_field = nullptr;
    dataDesc_397[8].override_count = 0;
    *(_QWORD *)dataDesc_397[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_397[8].flatGroup = 0;
    dataDesc_397[9].fieldType = FIELD_FLOAT;
    dataDesc_397[9].fieldName = "m_flHeight";
    dataDesc_397[9].fieldOffset = 928;
    *(_DWORD *)&dataDesc_397[9].fieldSize = 393217;
    dataDesc_397[9].externalName = "height";
    dataDesc_397[9].pSaveRestoreOps = nullptr;
    dataDesc_397[9].inputFunc = nullptr;
    dataDesc_397[9].td = nullptr;
    dataDesc_397[9].fieldSizeInBytes = 4;
    dataDesc_397[9].override_field = nullptr;
    dataDesc_397[9].override_count = 0;
    *(_QWORD *)dataDesc_397[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_397[9].flatGroup = 0;
  }
  CBasePlatTrain::m_DataMap.dataNumFields = 9;
  CBasePlatTrain::m_DataMap.dataDesc = &dataDesc_397[1];
  return &CBasePlatTrain::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10238790
// Name: struct datamap_t __near * DataMapInit<class CFuncPlat>(class CFuncPlat __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncPlat>()
{
  char *Name; // eax

  if ( (_S3_134 & 1) == 0 )
  {
    _S3_134 |= 1u;
    nameHolder_419.m_pszBase = "CFuncPlat";
    nameHolder_419.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_419.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_419.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_419.m_Names.m_Size = 0;
    nameHolder_419.m_Names.m_pElements = nullptr;
    nameHolder_419.m_nLenBase = 9;
    atexit(func: DataMapInit_CFuncPlat__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncPlat::m_DataMap.baseMap = &CBasePlatTrain::m_DataMap;
  if ( (_S3_134 & 2) == 0 )
  {
    _S3_134 |= 2u;
    dataDesc_398[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_419,
                                  pszIdentifier: "PlatUse");
    dataDesc_398[2].flags = 32;
    dataDesc_398[2].fieldOffset = 0;
    dataDesc_398[2].fieldSize = 1;
    dataDesc_398[2].externalName = nullptr;
    dataDesc_398[2].pSaveRestoreOps = nullptr;
    dataDesc_398[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncPlat::PlatUse;
    *(_QWORD *)&dataDesc_398[2].td = 0;
    *(_QWORD *)&dataDesc_398[2].override_field = 0;
    *(_QWORD *)&dataDesc_398[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_398[2].flatOffset[1] = 0;
    dataDesc_398[3].fieldType = FIELD_VOID;
    dataDesc_398[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_419,
                                  pszIdentifier: "CallGoDown");
    dataDesc_398[3].fieldOffset = 0;
    dataDesc_398[3].fieldSize = 1;
    dataDesc_398[3].flags = 32;
    dataDesc_398[3].externalName = nullptr;
    dataDesc_398[3].pSaveRestoreOps = nullptr;
    dataDesc_398[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncPlat::CallGoDown;
    *(_QWORD *)&dataDesc_398[3].td = 0;
    *(_QWORD *)&dataDesc_398[3].override_field = 0;
    *(_QWORD *)&dataDesc_398[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_398[3].flatOffset[1] = 0;
    dataDesc_398[4].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_419, pszIdentifier: "CallHitTop");
    dataDesc_398[4].fieldSize = 1;
    dataDesc_398[4].fieldName = Name;
    dataDesc_398[4].fieldOffset = 0;
    dataDesc_398[4].flags = 32;
    dataDesc_398[4].externalName = nullptr;
    dataDesc_398[4].pSaveRestoreOps = nullptr;
    dataDesc_398[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncPlat::CallHitTop;
    *(_QWORD *)&dataDesc_398[4].td = 0;
    *(_QWORD *)&dataDesc_398[4].override_field = 0;
    *(_QWORD *)&dataDesc_398[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_398[4].flatOffset[1] = 0;
    dataDesc_398[5].fieldType = FIELD_VOID;
    dataDesc_398[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_419,
                                  pszIdentifier: "CallHitBottom");
    dataDesc_398[5].fieldSize = 1;
    dataDesc_398[5].fieldOffset = 0;
    dataDesc_398[5].flags = 32;
    dataDesc_398[5].externalName = nullptr;
    dataDesc_398[5].pSaveRestoreOps = nullptr;
    dataDesc_398[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncPlat::CallHitBottom;
    *(_QWORD *)&dataDesc_398[5].td = 0;
    *(_QWORD *)&dataDesc_398[5].override_field = 0;
    *(_QWORD *)&dataDesc_398[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_398[5].flatOffset[1] = 0;
    dataDesc_398[6].fieldType = FIELD_VOID;
    dataDesc_398[6].fieldName = "InputToggle";
    dataDesc_398[6].fieldOffset = 0;
    dataDesc_398[6].fieldSize = 1;
    dataDesc_398[6].flags = 8;
    dataDesc_398[6].externalName = "Toggle";
    dataDesc_398[6].pSaveRestoreOps = nullptr;
    *(_QWORD *)&dataDesc_398[6].td = 0;
    *(_QWORD *)&dataDesc_398[6].override_field = 0;
    *(_QWORD *)&dataDesc_398[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_398[6].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_398[7].td = 0;
    *(_QWORD *)&dataDesc_398[7].override_field = 0;
    *(_QWORD *)&dataDesc_398[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_398[7].flatOffset[1] = 0;
    dataDesc_398[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncPlat::InputToggle;
    dataDesc_398[7].fieldType = FIELD_VOID;
    dataDesc_398[7].fieldName = "InputGoUp";
    dataDesc_398[7].fieldOffset = 0;
    dataDesc_398[7].fieldSize = 1;
    dataDesc_398[7].flags = 8;
    dataDesc_398[7].externalName = "GoUp";
    dataDesc_398[7].pSaveRestoreOps = nullptr;
    dataDesc_398[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncPlat::InputGoUp;
    dataDesc_398[8].fieldType = FIELD_VOID;
    dataDesc_398[8].fieldName = "InputGoDown";
    dataDesc_398[8].fieldOffset = 0;
    *(_DWORD *)&dataDesc_398[8].fieldSize = 524289;
    dataDesc_398[8].externalName = "GoDown";
    dataDesc_398[8].pSaveRestoreOps = nullptr;
    dataDesc_398[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncPlat::InputGoDown;
    *(_QWORD *)&dataDesc_398[8].td = 0;
    *(_QWORD *)&dataDesc_398[8].override_field = 0;
    *(_QWORD *)&dataDesc_398[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_398[8].flatOffset[1] = 0;
  }
  CFuncPlat::m_DataMap.dataNumFields = 8;
  CFuncPlat::m_DataMap.dataDesc = &dataDesc_398[1];
  return &CFuncPlat::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10238DF0
// Name: struct datamap_t __near * DataMapInit<class CFuncPlatRot>(class CFuncPlatRot __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncPlatRot>()
{
  if ( (_S4_62 & 1) == 0 )
  {
    _S4_62 |= 1u;
    nameHolder_420.m_pszBase = "CFuncPlatRot";
    nameHolder_420.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_420.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_420.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_420.m_Names.m_Size = 0;
    nameHolder_420.m_Names.m_pElements = nullptr;
    nameHolder_420.m_nLenBase = 12;
    atexit(func: DataMapInit_CFuncPlatRot__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncPlatRot::m_DataMap.baseMap = &CFuncPlat::m_DataMap;
  CFuncPlatRot::m_DataMap.dataNumFields = 2;
  CFuncPlatRot::m_DataMap.dataDesc = &dataDesc_399[1];
  return &CFuncPlatRot::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023AD50
// Name: struct datamap_t __near * DataMapInit<class CFuncTrainControls>(class CFuncTrainControls __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncTrainControls>()
{
  if ( (_S8_12 & 1) == 0 )
  {
    _S8_12 |= 1u;
    nameHolder_421.m_pszBase = "CFuncTrainControls";
    nameHolder_421.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_421.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_421.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_421.m_Names.m_Size = 0;
    nameHolder_421.m_Names.m_pElements = nullptr;
    nameHolder_421.m_nLenBase = 18;
    atexit(func: DataMapInit_CFuncTrainControls__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncTrainControls::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S8_12 & 2) == 0 )
  {
    _S8_12 |= 2u;
    dataDesc_488[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_421, pszIdentifier: "Find");
    dataDesc_488[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_488[1].fieldSize = 2097153;
    dataDesc_488[1].externalName = nullptr;
    dataDesc_488[1].pSaveRestoreOps = nullptr;
    dataDesc_488[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrainControls::Find;
    *(_QWORD *)&dataDesc_488[1].td = 0;
    *(_QWORD *)&dataDesc_488[1].override_field = 0;
    *(_QWORD *)&dataDesc_488[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_488[1].flatOffset[1] = 0;
  }
  CFuncTrainControls::m_DataMap.dataNumFields = 1;
  CFuncTrainControls::m_DataMap.dataDesc = &dataDesc_488[1];
  return &CFuncTrainControls::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023AE40
// Name: struct datamap_t __near * DataMapInit<class CFuncTrackChange>(class CFuncTrackChange __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncTrackChange>()
{
  if ( (_S9_8 & 1) == 0 )
  {
    _S9_8 |= 1u;
    nameHolder_422.m_pszBase = "CFuncTrackChange";
    nameHolder_422.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_422.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_422.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_422.m_Names.m_Size = 0;
    nameHolder_422.m_Names.m_pElements = nullptr;
    nameHolder_422.m_nLenBase = 16;
    atexit(func: DataMapInit_CFuncTrackChange__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncTrackChange::m_DataMap.baseMap = &CFuncPlatRot::m_DataMap;
  if ( (_S9_8 & 2) == 0 )
  {
    _S9_8 |= 2u;
    dataDesc_400[10].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_422,
                                   pszIdentifier: "Find");
    dataDesc_400[10].fieldOffset = 0;
    *(_DWORD *)&dataDesc_400[10].fieldSize = 2097153;
    dataDesc_400[10].externalName = nullptr;
    dataDesc_400[10].pSaveRestoreOps = nullptr;
    dataDesc_400[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrackChange::Find;
    *(_QWORD *)&dataDesc_400[10].td = 0;
    *(_QWORD *)&dataDesc_400[10].override_field = 0;
    *(_QWORD *)&dataDesc_400[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_400[10].flatOffset[1] = 0;
  }
  CFuncTrackChange::m_DataMap.dataNumFields = 10;
  CFuncTrackChange::m_DataMap.dataDesc = &dataDesc_400[1];
  return &CFuncTrackChange::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023B050
// Name: struct datamap_t __near * DataMapInit<class CFuncTrackAuto>(class CFuncTrackAuto __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncTrackAuto>()
{
  if ( (_S10_5 & 1) == 0 )
  {
    _S10_5 |= 1u;
    nameHolder_423.m_pszBase = "CFuncTrackAuto";
    nameHolder_423.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_423.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_423.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_423.m_Names.m_Size = 0;
    nameHolder_423.m_Names.m_pElements = nullptr;
    nameHolder_423.m_nLenBase = 14;
    atexit(func: DataMapInit_CFuncTrackAuto__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncTrackAuto::m_DataMap.baseMap = &CFuncTrackChange::m_DataMap;
  CFuncTrackAuto::m_DataMap.dataNumFields = 1;
  CFuncTrackAuto::m_DataMap.dataDesc = &dataDesc_401[1];
  return &CFuncTrackAuto::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023B340
// Name: struct datamap_t __near * DataMapInit<class CFuncTrain>(class CFuncTrain __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncTrain>()
{
  char *Name; // eax

  if ( (_S5_32 & 1) == 0 )
  {
    _S5_32 |= 1u;
    nameHolder_424.m_pszBase = "CFuncTrain";
    nameHolder_424.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_424.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_424.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_424.m_Names.m_Size = 0;
    nameHolder_424.m_Names.m_pElements = nullptr;
    nameHolder_424.m_nLenBase = 10;
    atexit(func: DataMapInit_CFuncTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncTrain::m_DataMap.baseMap = &CBasePlatTrain::m_DataMap;
  if ( (_S5_32 & 2) == 0 )
  {
    _S5_32 |= 2u;
    dataDesc_402[7].fieldName = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_424, pszIdentifier: "Wait");
    dataDesc_402[7].flags = 32;
    dataDesc_402[7].fieldOffset = 0;
    dataDesc_402[7].fieldSize = 1;
    dataDesc_402[7].externalName = nullptr;
    dataDesc_402[7].pSaveRestoreOps = nullptr;
    dataDesc_402[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrain::Wait;
    *(_QWORD *)&dataDesc_402[7].td = 0;
    *(_QWORD *)&dataDesc_402[7].override_field = 0;
    *(_QWORD *)&dataDesc_402[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_402[7].flatOffset[1] = 0;
    dataDesc_402[8].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_424, pszIdentifier: "Next");
    *(_QWORD *)&dataDesc_402[8].td = 0;
    *(_QWORD *)&dataDesc_402[8].override_field = 0;
    *(_QWORD *)&dataDesc_402[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_402[8].flatOffset[1] = 0;
    dataDesc_402[8].fieldName = Name;
    dataDesc_402[8].fieldSize = 1;
    *(_QWORD *)&dataDesc_402[9].td = 0;
    *(_QWORD *)&dataDesc_402[9].override_field = 0;
    *(_QWORD *)&dataDesc_402[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_402[9].flatOffset[1] = 0;
    dataDesc_402[8].flags = 32;
    dataDesc_402[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_402[10].td = 0;
    *(_QWORD *)&dataDesc_402[10].override_field = 0;
    *(_QWORD *)&dataDesc_402[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_402[10].flatOffset[1] = 0;
    dataDesc_402[8].fieldOffset = 0;
    dataDesc_402[8].externalName = nullptr;
    dataDesc_402[8].pSaveRestoreOps = nullptr;
    dataDesc_402[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrain::Next;
    dataDesc_402[9].fieldType = FIELD_VOID;
    dataDesc_402[9].fieldName = "InputToggle";
    dataDesc_402[9].fieldOffset = 0;
    dataDesc_402[9].flags = 8;
    dataDesc_402[9].externalName = "Toggle";
    dataDesc_402[9].pSaveRestoreOps = nullptr;
    dataDesc_402[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrain::InputToggle;
    dataDesc_402[10].fieldType = FIELD_VOID;
    dataDesc_402[10].fieldName = "InputStart";
    dataDesc_402[10].fieldOffset = 0;
    *(_DWORD *)&dataDesc_402[10].fieldSize = 524289;
    dataDesc_402[10].externalName = "Start";
    dataDesc_402[10].pSaveRestoreOps = nullptr;
    dataDesc_402[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrain::InputStart;
    dataDesc_402[11].fieldType = FIELD_VOID;
    dataDesc_402[11].fieldName = "InputStop";
    dataDesc_402[11].fieldOffset = 0;
    *(_DWORD *)&dataDesc_402[11].fieldSize = 524289;
    dataDesc_402[11].externalName = "Stop";
    dataDesc_402[11].pSaveRestoreOps = nullptr;
    dataDesc_402[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrain::InputStop;
    *(_QWORD *)&dataDesc_402[11].td = 0;
    *(_QWORD *)&dataDesc_402[11].override_field = 0;
    *(_QWORD *)&dataDesc_402[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_402[11].flatOffset[1] = 0;
  }
  CFuncTrain::m_DataMap.dataNumFields = 11;
  CFuncTrain::m_DataMap.dataDesc = &dataDesc_402[1];
  return &CFuncTrain::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C270
// Name: struct datamap_t __near * DataMapInit<class CFuncTrackTrain>(class CFuncTrackTrain __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncTrackTrain>()
{
  if ( (_S6_24 & 1) == 0 )
  {
    _S6_24 |= 1u;
    nameHolder_425.m_pszBase = "CFuncTrackTrain";
    nameHolder_425.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_425.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_425.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_425.m_Names.m_Size = 0;
    nameHolder_425.m_Names.m_pElements = nullptr;
    nameHolder_425.m_nLenBase = 15;
    atexit(func: DataMapInit_CFuncTrackTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncTrackTrain::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S6_24 & 2) == 0 )
  {
    _S6_24 |= 2u;
    dataDesc_403[44].fieldType = FIELD_CUSTOM;
    dataDesc_403[45].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_403[43].inputFunc = 0;
    *(_QWORD *)&dataDesc_403[43].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_403[43].override_count = 0;
    *(_QWORD *)dataDesc_403[43].flatOffset = 0;
    dataDesc_403[44].fieldSize = 1;
    *(_QWORD *)&dataDesc_403[44].inputFunc = 0;
    *(_QWORD *)&dataDesc_403[44].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_403[44].override_count = 0;
    *(_QWORD *)dataDesc_403[44].flatOffset = 0;
    dataDesc_403[45].fieldSize = 1;
    dataDesc_403[43].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_403[43].flatGroup = 0;
    dataDesc_403[44].fieldName = "m_OnNext";
    dataDesc_403[44].fieldOffset = 1004;
    dataDesc_403[44].flags = 22;
    dataDesc_403[44].externalName = "OnNextPoint";
    dataDesc_403[44].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_403[44].flatGroup = 0;
    dataDesc_403[45].fieldName = "m_OnArrivedAtDestinationNode";
    dataDesc_403[45].fieldOffset = 1028;
    dataDesc_403[45].flags = 22;
    dataDesc_403[45].externalName = "OnArrivedAtDestinationNode";
    dataDesc_403[45].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_403[45].inputFunc = 0;
    *(_QWORD *)&dataDesc_403[45].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_403[45].override_count = 0;
    *(_QWORD *)dataDesc_403[45].flatOffset = 0;
    *(_DWORD *)&dataDesc_403[45].flatGroup = 0;
    dataDesc_403[46].fieldType = FIELD_VOID;
    dataDesc_403[46].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_425,
                                   pszIdentifier: "Next");
    dataDesc_403[46].flags = 32;
    dataDesc_403[46].fieldOffset = 0;
    dataDesc_403[46].fieldSize = 1;
    dataDesc_403[46].externalName = nullptr;
    dataDesc_403[46].pSaveRestoreOps = nullptr;
    dataDesc_403[46].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrackTrain::Next;
    *(_QWORD *)&dataDesc_403[46].td = 0;
    *(_QWORD *)&dataDesc_403[46].override_field = 0;
    *(_QWORD *)&dataDesc_403[46].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_403[46].flatOffset[1] = 0;
    dataDesc_403[47].fieldType = FIELD_VOID;
    dataDesc_403[47].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_425,
                                   pszIdentifier: "Find");
    dataDesc_403[47].fieldOffset = 0;
    dataDesc_403[47].fieldSize = 1;
    dataDesc_403[47].flags = 32;
    dataDesc_403[47].externalName = nullptr;
    dataDesc_403[47].pSaveRestoreOps = nullptr;
    dataDesc_403[47].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrackTrain::Find;
    *(_QWORD *)&dataDesc_403[47].td = 0;
    *(_QWORD *)&dataDesc_403[47].override_field = 0;
    *(_QWORD *)&dataDesc_403[47].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_403[47].flatOffset[1] = 0;
    dataDesc_403[48].fieldType = FIELD_VOID;
    dataDesc_403[48].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_425,
                                   pszIdentifier: "NearestPath");
    dataDesc_403[48].fieldOffset = 0;
    dataDesc_403[48].fieldSize = 1;
    dataDesc_403[48].flags = 32;
    dataDesc_403[48].externalName = nullptr;
    dataDesc_403[48].pSaveRestoreOps = nullptr;
    dataDesc_403[48].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrackTrain::NearestPath;
    *(_QWORD *)&dataDesc_403[48].td = 0;
    *(_QWORD *)&dataDesc_403[48].override_field = 0;
    *(_QWORD *)&dataDesc_403[48].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_403[48].flatOffset[1] = 0;
    dataDesc_403[49].fieldType = FIELD_VOID;
    dataDesc_403[49].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_425,
                                   pszIdentifier: "DeadEnd");
    dataDesc_403[49].fieldOffset = 0;
    *(_DWORD *)&dataDesc_403[49].fieldSize = 2097153;
    dataDesc_403[49].externalName = nullptr;
    dataDesc_403[49].pSaveRestoreOps = nullptr;
    dataDesc_403[49].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncTrackTrain::DeadEnd;
    *(_QWORD *)&dataDesc_403[49].td = 0;
    *(_QWORD *)&dataDesc_403[49].override_field = 0;
    *(_QWORD *)&dataDesc_403[49].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_403[49].flatOffset[1] = 0;
  }
  CFuncTrackTrain::m_DataMap.dataNumFields = 49;
  CFuncTrackTrain::m_DataMap.dataDesc = &dataDesc_403[1];
  return &CFuncTrackTrain::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1041E930
// Name: _ServerClassInit_DT_FuncTrackTrain::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncTrackTrain::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S7_16;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E950
// Name: _DataMapInit_CBasePlatTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBasePlatTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_418);
}

//------------------------------------------------------------------------------
// Address: 0x1041E960
// Name: _DataMapInit_CFuncPlat__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncPlat__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_419);
}

//------------------------------------------------------------------------------
// Address: 0x1041E970
// Name: _DataMapInit_CFuncPlatRot__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncPlatRot__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_420);
}

//------------------------------------------------------------------------------
// Address: 0x1041E980
// Name: _DataMapInit_CFuncTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_424);
}

//------------------------------------------------------------------------------
// Address: 0x1041E990
// Name: _DataMapInit_CFuncTrackTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncTrackTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_425);
}

//------------------------------------------------------------------------------
// Address: 0x1041E9A0
// Name: _DataMapInit_CFuncTrainControls__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncTrainControls__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_421);
}

//------------------------------------------------------------------------------
// Address: 0x1041E9B0
// Name: _DataMapInit_CFuncTrackChange__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncTrackChange__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_422);
}

//------------------------------------------------------------------------------
// Address: 0x1041E9C0
// Name: _DataMapInit_CFuncTrackAuto__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncTrackAuto__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_423);
}

//------------------------------------------------------------------------------
// Address: 0x1041E9D0
// Name: _dynamic_atexit_destructor_for__g_debug_transitions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_transitions__()
{
  ConVar::~ConVar(this: &g_debug_transitions);
}

//------------------------------------------------------------------------------
// Address: 0x1041E9E0
// Name: _dynamic_atexit_destructor_for__showtriggers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showtriggers__()
{
  ConVar::~ConVar(this: &showtriggers);
}

//------------------------------------------------------------------------------
// Address: 0x1041E9F0
// Name: _dynamic_atexit_destructor_for__showtriggers_toggle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showtriggers_toggle__()
{
  ConCommand::~ConCommand(this: &showtriggers_toggle);
}
