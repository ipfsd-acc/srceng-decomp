// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/envshake.cpp
// Functions: 45
// ============================================================

#include "game\server\envshake.h"

//------------------------------------------------------------------------------
// Address: 0x1011FE10
// Name: private: virtual struct datamap_t __near * CEnvShake::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvShake::GetDataDescMap(CEnvShake *this)
{
  return &CEnvShake::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011FE20
// Name: public: virtual void CEnvShake::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvShake::OnRestore(CEnvShake *this)
{
  CBaseEntity::OnRestore(this);
  if ( this->m_pShakeController != nullptr )
    this->m_pShakeController->SetEventHandler(this: this->m_pShakeController, a2: &this->m_shakeCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1011FE50
// Name: void CC_Shake(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Shake()
{
  CBasePlayer *CommandClient; // eax
  const Vector *v1; // eax

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr )
  {
    v1 = CommandClient->WorldSpaceCenter(this: CommandClient);
    UTIL_ScreenShake(
      center: v1,
      amplitude: 25.0,
      frequency: 150.0,
      duration: 1.0,
      radius: 750.0,
      eCommand: SHAKE_START,
      bAirShake: false,
      ignore: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FEB0
// Name: public: virtual int CEnvShake::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEnvShake::DrawDebugTextOverlays(CEnvShake *this)
{
  int result; // eax
  int v3; // esi
  int v4; // esi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    magnitude: %f", this->m_Amplitude);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    frequency: %f", this->m_Frequency);
    CBaseEntity::EntityText(this, text_offset: v4++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    duration: %f", this->m_Duration);
    CBaseEntity::EntityText(this, text_offset: v4++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    radius: %f", this->m_Radius);
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v4 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10120040
// Name: private: virtual struct datamap_t __near * CEnvTilt::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvTilt::GetDataDescMap(CEnvTilt *this)
{
  return &CEnvTilt::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10120050
// Name: public: virtual int CEnvTilt::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEnvTilt::DrawDebugTextOverlays(CEnvTilt *this)
{
  int result; // eax
  int v3; // esi
  int v4; // esi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    duration: %f", this->m_Duration);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    radius: %f", this->m_Radius);
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v4 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10120180
// Name: public: virtual void CEnvShake::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvShake::Think(CEnvShake *this)
{
  float curtime; // xmm0_4
  Vector *p_m_maxForce; // ebx
  Vector *v4; // edi
  float v5; // xmm0_4
  __m128 curtime_low; // xmm1
  float v7; // xmm2_4
  float v8; // xmm0_4
  double v9; // xmm0_8
  int fraction; // [esp+14h] [ebp-4h]
  float fractiona; // [esp+14h] [ebp-4h]

  curtime = gpGlobals->curtime;
  if ( curtime > this->m_nextShake )
  {
    p_m_maxForce = &this->m_maxForce;
    this->m_nextShake = (float)(1.0 / this->m_Frequency) + curtime;
    v4 = &this->m_maxForce;
    for ( fraction = 2; fraction != 0; --fraction )
    {
      v4->x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: -1082130432,
                a3: 1065353216);
      v4 = (Vector *)((char *)v4 + 4);
    }
    this->m_maxForce.z = 4.0;
    VectorNormalize(vec: &this->m_maxForce);
    v5 = this->m_currentAmp * 400.0;
    p_m_maxForce->x = v5 * p_m_maxForce->x;
    this->m_maxForce.y = this->m_maxForce.y * v5;
    this->m_maxForce.z = this->m_maxForce.z * v5;
  }
  curtime_low = (__m128)LODWORD(gpGlobals->curtime);
  v7 = 0.0;
  v8 = (float)(this->m_stopTime - curtime_low.m128_f32[0]) / this->m_Duration;
  fractiona = v8;
  if ( v8 >= 0.0 )
  {
    if ( v8 != 0.0 )
      v7 = this->m_Frequency / v8;
    curtime_low.m128_f32[0] = curtime_low.m128_f32[0] * v7;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(curtime_low));
    *(float *)&v9 = v9;
    *(float *)&v9 = *(float *)&v9 * (float)(fractiona * fractiona);
    this->m_shakeCallback.m_force.x = *(float *)&v9 * this->m_maxForce.x;
    this->m_shakeCallback.m_force.y = this->m_maxForce.y * *(float *)&v9;
    this->m_shakeCallback.m_force.z = this->m_maxForce.z * *(float *)&v9;
    this->m_currentAmp = this->m_currentAmp
                       - (float)((float)(gpGlobals->frametime / (float)(this->m_Frequency * this->m_Duration))
                               * this->m_currentAmp);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
  else
  {
    this->m_pShakeController->ClearObjects(this: this->m_pShakeController);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120360
// Name: public: virtual void CEnvTilt::Precache(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEnvTilt::Precache(CEnvTilt *this)
{
  CRopeKeyframe::PrecacheShakeRopes();
}

//------------------------------------------------------------------------------
// Address: 0x10120380
// Name: public: virtual enum IMotionEvent::simresult_e CPhysicsShake::Simulate(class IPhysicsMotionController __near *,class IPhysicsObject __near *,float,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsShake::Simulate(
        CPhysicsShake *this,
        IPhysicsMotionController *pController,
        IPhysicsObject *pObject,
        float deltaTime,
        Vector *linear,
        Vector *angular)
{
  double v8; // st7
  void (__thiscall *CalculateForceOffset)(IPhysicsObject *, const Vector *, const Vector *, Vector *, Vector *); // eax
  Vector contact; // [esp+8h] [ebp-18h] BYREF
  float v11[3]; // [esp+14h] [ebp-Ch] BYREF

  if ( !pObject->GetContactPoint(this: pObject, a2: &contact, a3: nullptr) )
    return 0;
  v8 = ((double (__thiscall *)(IPhysicsObject *))pObject->GetMass)(a1: pObject) * 0.40000001 + 1.0;
  CalculateForceOffset = pObject->CalculateForceOffset;
  v11[0] = this->m_force.x * v8;
  v11[1] = this->m_force.y * v8;
  v11[2] = v8 * this->m_force.z;
  CalculateForceOffset(this: pObject, a2: (const Vector *)v11, a3: &contact, a4: linear, a5: angular);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10120410
// Name: public: virtual void CEnvShake::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvShake::Spawn(CEnvShake *this)
{
  int m_Value; // eax
  const char *DebugName; // eax

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 1) != 0 )
    this->m_Radius = 0.0;
  if ( (m_Value & 0x20) != 0 && (m_Value & 8) == 0 && (m_Value & 0x10) == 0 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevWarning(
      a1: "env_shake %s with \"Don't shake view\" spawnflag set without \"Shake physics\" or \"Shake ropes\" spawnflags set.",
      DebugName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120480
// Name: public: void CEnvShake::ApplyShake(enum ShakeCommand_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvShake::ApplyShake(CEnvShake *this, ShakeCommand_t command)
{
  int m_Value; // eax
  bool v5; // zf
  float radius; // xmm0_4
  int m_iEFlags; // eax
  unsigned int v8; // edx
  IPhysicsMotionController *m_pShakeController; // ecx
  float m_Radius; // xmm0_4
  float v11; // xmm1_4
  int v12; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  ShakeCommand_t v16; // ebx
  CBaseEntity *v17; // eax
  IPhysicsObject *m_pPhysicsObject; // edi
  CBaseEntity *pList[1024]; // [esp+24h] [ebp-103Ch] BYREF
  CFlaggedEntitiesEnum pEnum; // [esp+1024h] [ebp-3Ch] BYREF
  Vector maxs; // [esp+1038h] [ebp-28h] BYREF
  Vector mins; // [esp+1044h] [ebp-1Ch] BYREF
  float frequency; // [esp+1050h] [ebp-10h]
  float duration; // [esp+1054h] [ebp-Ch]
  bool bAirShake[4]; // [esp+1058h] [ebp-8h]
  float amplitude; // [esp+105Ch] [ebp-4h]
  int savedregs; // [esp+1060h] [ebp+0h] BYREF
  float eCommand; // [esp+1068h] [ebp+8h]
  ShakeCommand_t eCommanda; // [esp+1068h] [ebp+8h]
  ShakeCommand_t eCommandb; // [esp+1068h] [ebp+8h]

  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x20) == 0 || (m_Value & 0x40) == 0 )
  {
    v5 = (this->m_spawnflags.m_Value & 1) == 0;
    bAirShake[0] = (m_Value & 4) != 0;
    if ( v5 )
      radius = this->m_Radius;
    else
      radius = 0.0;
    m_iEFlags = this->m_iEFlags;
    duration = this->m_Duration;
    frequency = this->m_Frequency;
    amplitude = this->m_Amplitude;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_ScreenShake(
      center: &this->m_vecAbsOrigin,
      amplitude,
      frequency,
      duration,
      radius,
      eCommand: command,
      bAirShake: bAirShake[0],
      ignore: nullptr);
  }
  if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
  {
    v8 = (unsigned int)this->m_iEFlags >> 11;
    eCommand = this->m_Frequency;
    amplitude = this->m_Radius;
    if ( (v8 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    CRopeKeyframe::ShakeRopes(vCenter: &this->m_vecAbsOrigin, flRadius: amplitude, flMagnitude: eCommand);
  }
  if ( (this->m_spawnflags.m_Value & 8) != 0 )
  {
    if ( this->m_pShakeController == nullptr )
      this->m_pShakeController = physenv->CreateMotionController(this: physenv, a2: &this->m_shakeCallback);
    switch ( command )
    {
      case SHAKE_START:
      case SHAKE_START_RUMBLEONLY:
      case SHAKE_START_NORUMBLE:
        m_pShakeController = this->m_pShakeController;
        this->m_stopTime = this->m_Duration + gpGlobals->curtime;
        this->m_nextShake = 0.0;
        m_pShakeController->ClearObjects(this: m_pShakeController);
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
        m_Radius = this->m_Radius;
        this->m_currentAmp = this->m_Amplitude;
        *(float *)&eCommanda = m_Radius;
        if ( m_Radius == 0.0 )
        {
          m_Radius = 512.0;
          *(float *)&eCommanda = 512.0;
        }
        v11 = m_Radius;
        *(float *)&pEnum.m_count = m_Radius;
        if ( m_Radius <= 100.0 )
        {
          v11 = 100.0;
          pEnum.m_count = 1120403456;
        }
        if ( (this->m_iEFlags & 0x800) != 0 )
        {
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
          m_Radius = *(float *)&eCommanda;
          v11 = *(float *)&pEnum.m_count;
        }
        v12 = this->m_iEFlags;
        mins.x = this->m_vecAbsOrigin.x - m_Radius;
        mins.y = this->m_vecAbsOrigin.y - m_Radius;
        mins.z = this->m_vecAbsOrigin.z - v11;
        if ( (v12 & 0x800) != 0 )
        {
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
          m_Radius = *(float *)&eCommanda;
          v11 = *(float *)&pEnum.m_count;
        }
        v13 = v11 + this->m_vecAbsOrigin.z;
        v14 = this->m_vecAbsOrigin.x + m_Radius;
        v15 = m_Radius + this->m_vecAbsOrigin.y;
        maxs.x = v14;
        maxs.y = v15;
        maxs.z = v13;
        CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(this: &pEnum, pList, listMax: 1024, flagMask: 0);
        v16 = SHAKE_START;
        eCommandb = UTIL_EntitiesInBox(&mins, &maxs, &pEnum);
        if ( eCommandb > SHAKE_START )
        {
          do
          {
            v17 = pList[v16];
            if ( v17->m_MoveType.m_Value == 6 )
            {
              m_pPhysicsObject = v17->m_pPhysicsObject;
              if ( m_pPhysicsObject != nullptr && m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject) )
              {
                this->m_pShakeController->AttachObject(this: this->m_pShakeController, a2: m_pPhysicsObject, a3: false);
                m_pPhysicsObject->Wake(this: m_pPhysicsObject);
              }
            }
            ++v16;
          }
          while ( v16 < eCommandb );
        }
        break;
      case SHAKE_STOP:
        this->m_pShakeController->ClearObjects(this: this->m_pShakeController);
        break;
      case SHAKE_AMPLITUDE:
        this->m_currentAmp = this->m_Amplitude;
        goto $LN1_7;
      case SHAKE_FREQUENCY:
$LN1_7:
        this->m_pShakeController->WakeObjects(this: this->m_pShakeController);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120800
// Name: public: void CEnvShake::InputStartShake(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvShake::InputStartShake(CEnvShake *this, inputdata_t *inputdata)
{
  int m_Value; // eax

  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x40) != 0 )
  {
    CEnvShake::ApplyShake(this, command: SHAKE_START_NORUMBLE);
  }
  else if ( (m_Value & 0x20) != 0 )
  {
    CEnvShake::ApplyShake(this, command: SHAKE_START_RUMBLEONLY);
  }
  else
  {
    CEnvShake::ApplyShake(this, command: SHAKE_START);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120840
// Name: public: void CEnvShake::InputStopShake(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvShake::InputStopShake(CEnvShake *this, inputdata_t *inputdata)
{
  CEnvShake::ApplyShake(this, command: SHAKE_STOP);
}

//------------------------------------------------------------------------------
// Address: 0x10120850
// Name: public: void CEnvShake::InputAmplitude(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvShake::InputAmplitude(CEnvShake *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_Amplitude) = inputdata->value.iVal;
  else
    this->m_Amplitude = 0.0;
  CEnvShake::ApplyShake(this, command: SHAKE_AMPLITUDE);
}

//------------------------------------------------------------------------------
// Address: 0x10120890
// Name: public: void CEnvShake::InputFrequency(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvShake::InputFrequency(CEnvShake *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_Frequency) = inputdata->value.iVal;
  else
    this->m_Frequency = 0.0;
  CEnvShake::ApplyShake(this, command: SHAKE_FREQUENCY);
}

//------------------------------------------------------------------------------
// Address: 0x101208D0
// Name: public: virtual void CEnvTilt::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTilt::Spawn(CEnvTilt *this)
{
  int m_Value; // eax
  const char *DebugName; // eax

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 1) != 0 )
    this->m_Radius = 0.0;
  if ( (m_Value & 0x20) != 0 && (m_Value & 8) == 0 && (m_Value & 0x10) == 0 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevWarning(
      a1: "env_shake %s with \"Don't shake view\" spawnflag set without \"Shake physics\" or \"Shake ropes\" spawnflags set.",
      DebugName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120940
// Name: public: void CEnvTilt::ApplyTilt(enum ShakeCommand_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTilt::ApplyTilt(CEnvTilt *this, ShakeCommand_t command)
{
  int m_Value; // edi
  bool v4; // zf
  float m_Radius; // xmm0_4
  unsigned int v6; // edx
  int m_iEFlags; // ecx
  float z; // eax
  QAngle tiltAngle; // [esp+1Ch] [ebp-18h] BYREF
  float duration; // [esp+28h] [ebp-Ch]
  float tiltTime; // [esp+2Ch] [ebp-8h]
  float radius; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x20) == 0 || (m_Value & 0x40) == 0 )
  {
    v4 = (this->m_spawnflags.m_Value & 1) == 0;
    tiltTime = this->m_TiltTime;
    if ( v4 )
      m_Radius = this->m_Radius;
    else
      m_Radius = 0.0;
    v6 = (unsigned int)this->m_iEFlags >> 11;
    radius = m_Radius;
    duration = this->m_Duration;
    if ( (v6 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    m_iEFlags = this->m_iEFlags;
    z = this->m_angAbsRotation.z;
    tiltAngle.x = this->m_angAbsRotation.x;
    tiltAngle.z = z;
    tiltAngle.y = 0.0;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_ScreenTilt(
      center: &this->m_vecAbsOrigin,
      &tiltAngle,
      duration,
      radius,
      tiltTime,
      eCommand: command,
      bEaseInOut: (m_Value & 0x80) != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120A40
// Name: public: void CEnvTilt::InputStartTilt(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTilt::InputStartTilt(CEnvTilt *this, inputdata_t *inputdata)
{
  int m_Value; // eax

  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x40) != 0 )
  {
    CEnvTilt::ApplyTilt(this, command: SHAKE_START_NORUMBLE);
  }
  else if ( (m_Value & 0x20) != 0 )
  {
    CEnvTilt::ApplyTilt(this, command: SHAKE_START_RUMBLEONLY);
  }
  else
  {
    CEnvTilt::ApplyTilt(this, command: SHAKE_START);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120A80
// Name: public: void CEnvTilt::InputStopTilt(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTilt::InputStopTilt(CEnvTilt *this, inputdata_t *inputdata)
{
  CEnvTilt::ApplyTilt(this, command: SHAKE_STOP);
}

//------------------------------------------------------------------------------
// Address: 0x10402E70
// Name: CPhysicsShake_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysicsShake_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysicsShake>();
  CPhysicsShake_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402EA0
// Name: CEnvShake_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvShake_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvShake>();
  CEnvShake_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402EB0
// Name: _dynamic_initializer_for__shake__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__shake__()
{
  ConCommand::ConCommand(
    this: &shake,
    pName: "shake",
    callback: CC_Shake,
    pHelpString: "Shake the screen.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__shake__);
}

//------------------------------------------------------------------------------
// Address: 0x10402F00
// Name: CEnvTilt_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvTilt_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvTilt>();
  CEnvTilt_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B130
// Name: _dynamic_atexit_destructor_for__shake__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__shake__()
{
  ConCommand::~ConCommand(this: &shake);
}

//------------------------------------------------------------------------------
// Address: 0x10402E80
// Name: _dynamic_initializer_for__env_shake__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_shake__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvShake> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_shake,
           a3: "env_shake");
}

//------------------------------------------------------------------------------
// Address: 0x10402EE0
// Name: _dynamic_initializer_for__env_tilt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_tilt__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvTilt> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_tilt,
           a3: "env_tilt");
}

//------------------------------------------------------------------------------
// Address: 0x10402F10
// Name: _dynamic_initializer_for__fx_new_sparks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fx_new_sparks__()
{
  ConVar::ConVar(
    this: &fx_new_sparks,
    pName: "fx_new_sparks",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Use new style sparks.\n");
  return atexit(func: dynamic_atexit_destructor_for__fx_new_sparks__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B140
// Name: _DataMapInit_CPhysicsShake__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysicsShake__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_181);
}

//------------------------------------------------------------------------------
// Address: 0x1041B150
// Name: _DataMapInit_CEnvShake__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvShake__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_182);
}

//------------------------------------------------------------------------------
// Address: 0x1041B160
// Name: _DataMapInit_CEnvTilt__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvTilt__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_183);
}

//------------------------------------------------------------------------------
// Address: 0x1041B170
// Name: _dynamic_atexit_destructor_for__fx_new_sparks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fx_new_sparks__()
{
  ConVar::~ConVar(this: &fx_new_sparks);
}

//------------------------------------------------------------------------------
// Address: 0x1041B180
// Name: _DataMapInit_CEnvSpark__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvSpark__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_184);
}

//------------------------------------------------------------------------------
// Address: 0x1041B190
// Name: _dynamic_atexit_destructor_for__g_EventStrings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EventStrings__()
{
  CStringRegistry::~CStringRegistry(this: &g_EventStrings);
}

//------------------------------------------------------------------------------
// Address: 0x1041B1A0
// Name: _dynamic_atexit_destructor_for__g_EventList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EventList__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_EventList);
}

//------------------------------------------------------------------------------
// Address: 0x1041B1B0
// Name: _DataMapInit_CEnvExplosion__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvExplosion__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_185);
}

//------------------------------------------------------------------------------
// Address: 0x1041B1C0
// Name: _DataMapInit_CBaseFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_186);
}

//------------------------------------------------------------------------------
// Address: 0x1041B1D0
// Name: _DataMapInit_CFilterMultiple__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFilterMultiple__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_187);
}

//------------------------------------------------------------------------------
// Address: 0x1041B1E0
// Name: _DataMapInit_CFilterName__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFilterName__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_188);
}

//------------------------------------------------------------------------------
// Address: 0x1041B1F0
// Name: _DataMapInit_CFilterModel__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFilterModel__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_189);
}

//------------------------------------------------------------------------------
// Address: 0x1041B200
// Name: _DataMapInit_CFilterContext__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFilterContext__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_190);
}

//------------------------------------------------------------------------------
// Address: 0x1041B210
// Name: _DataMapInit_CFilterClass__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFilterClass__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_191);
}

//------------------------------------------------------------------------------
// Address: 0x1041B220
// Name: _DataMapInit_FilterTeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_FilterTeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_192);
}

//------------------------------------------------------------------------------
// Address: 0x1041B230
// Name: _DataMapInit_CFilterMassGreater__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFilterMassGreater__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_193);
}

//------------------------------------------------------------------------------
// Address: 0x1041B240
// Name: _DataMapInit_FilterDamageType__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_FilterDamageType__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_194);
}

//------------------------------------------------------------------------------
// Address: 0x1041B250
// Name: _DataMapInit_CFilterEnemy__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFilterEnemy__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_195);
}
