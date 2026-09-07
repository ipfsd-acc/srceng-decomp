// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/in_joystick.cpp
// Functions: 19
// ============================================================

#include "game\client\in_joystick.h"

//------------------------------------------------------------------------------
// Address: 0x10112CD0
// Name: void joy_movement_stick_Callback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl joy_movement_stick_Callback()
{
  engine->ClientCmd(this: engine, a2: "joyadvancedupdate silent\n");
}

//------------------------------------------------------------------------------
// Address: 0x10112CF0
// Name: protected: void CInput::DescribeJoystickAxis(int,char const __near *,struct CInput::joy_axis_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::DescribeJoystickAxis(
        CInput *this,
        int nJoystick,
        const char *axis,
        CInput::joy_axis_t *mapping)
{
  unsigned int AxisMap; // eax
  const char *v5; // ecx
  const char *v6; // eax

  AxisMap = mapping->AxisMap;
  if ( AxisMap != 0 )
  {
    v5 = "relative";
    if ( mapping->ControlMap == 0 )
      v5 = "absolute";
    switch ( AxisMap )
    {
      case 1u:
        v6 = "forward";
        break;
      case 2u:
        v6 = "pitch";
        break;
      case 3u:
        v6 = "strafe";
        break;
      case 4u:
        v6 = "yaw";
        break;
      default:
        v6 = "n/a";
        break;
    }
    _Msg(a1: "joy%d %s:  %s (%s)\n", nJoystick + 1, axis, v6, v5);
  }
  else
  {
    _Msg(a1: "joy%d %s:  unmapped\n", nJoystick + 1, axis);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112D90
// Name: public: virtual void CInput::Joystick_SetSampleTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::Joystick_SetSampleTime(CInput *this, float frametime)
{
  this->m_PerUser[0].m_flRemainingJoystickSampleTime = frametime;
}

//------------------------------------------------------------------------------
// Address: 0x10112DB0
// Name: public: virtual float CInput::Joystick_GetPitch(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInput::Joystick_GetPitch(CInput *this)
{
  if ( this->ControllerModeActive(this) )
    return CInput::GetPerUser(this, nSlot: 0)->m_flPreviousJoystickPitch;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10112DE0
// Name: public: virtual float CInput::Joystick_GetYaw(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInput::Joystick_GetYaw(CInput *this)
{
  if ( this->ControllerModeActive(this) )
    return CInput::GetPerUser(this, nSlot: 0)->m_flPreviousJoystickYaw;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10112E10
// Name: public: virtual void CInput::Joystick_Querry(float __near &,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::Joystick_Querry(CInput *this, float *forward, float *side, float *pitch, float *yaw)
{
  this->JoyStickSampleAxes(
    this,
    a2: forward,
    a3: side,
    a4: pitch,
    a5: yaw,
    a6: (bool *)&pitch + 3,
    a7: (bool *)&yaw + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10112E40
// Name: public: virtual void CInput::Joystick_ForceRecentering(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::Joystick_ForceRecentering(CInput *this, unsigned int nStick, bool bSet)
{
  if ( nStick <= 1 )
    CInput::GetPerUser(this, nSlot: 0)->m_bForceJoystickRecentering[nStick] = bSet;
}

//------------------------------------------------------------------------------
// Address: 0x10112E70
// Name: ResponseCurve
// Source: json
//------------------------------------------------------------------------------
float __usercall ResponseCurve@<xmm0>(int curve@<eax>, float x, int axis, float sensitivity)
{
  float result; // xmm0_4
  float v5; // xmm0_4
  int v6; // xmm5_4
  int v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float val; // xmm0_4
  float B; // xmm1_4
  double v12; // st7
  float v13; // xmm1_4
  float v14; // xmm0_4
  float m_fValue; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float sign; // [esp+14h] [ebp-4h]
  float signa; // [esp+14h] [ebp-4h]
  float xa; // [esp+20h] [ebp+8h]

  switch ( curve )
  {
    case 1:
      result = (float)(x * x) * sensitivity;
      if ( x < 0.0 )
        goto LABEL_3;
      break;
    case 2:
      result = (float)((float)(x * x) * x) * sensitivity;
      break;
    case 3:
      v5 = 1.0;
      if ( COERCE_FLOAT(LODWORD(x) & _mask__AbsFloat_) >= 0.94999999 )
        v5 = 1.5;
      result = (float)((float)(v5 * x) * x) * sensitivity;
      if ( x < 0.0 )
LABEL_3:
        LODWORD(result) ^= _mask__NegFloat_;
      break;
    case 4:
      if ( sensitivity >= 0.0 )
        *(float *)&v6 = 1.0;
      else
        *(float *)&v6 = -1.0;
      sign = *(float *)&v6;
      if ( x < 0.0 )
        LODWORD(sign) = v6 ^ _mask__NegFloat_;
      __libm_sse2_pow();
      *(float *)&v7 = 0.0;
      v8 = fabs(x);
      if ( v8 < 0.0 || (*(float *)&v7 = 1.0, v8 > 1.0) )
        v8 = *(float *)&v7;
      result = v8 * sign;
      break;
    case 5:
      v9 = x;
      if ( COERCE_FLOAT(LODWORD(x) & _mask__AbsFloat_) > 0.60000002 )
        goto LABEL_55;
      result = (float)(x * 0.5) * sensitivity;
      break;
    case 6:
      if ( axis != 1 )
        goto $LN21_3;
      signa = 1.0;
      if ( x < 0.0 )
        signa = -1.0;
      LODWORD(val) = LODWORD(x) & _mask__AbsFloat_;
      B = joy_vehicle_turn_lowend.m_pParent->m_Value.m_fValue;
      if ( B < COERCE_FLOAT(LODWORD(x) & _mask__AbsFloat_) )
        v12 = RemapVal(val, A: B, B: 1.0, C: joy_vehicle_turn_lowmap.m_pParent->m_Value.m_fValue, D: 1.0);
      else
        v12 = RemapVal(val, A: 0.0, B, C: 0.0, D: joy_vehicle_turn_lowmap.m_pParent->m_Value.m_fValue);
      xa = v12;
      result = (float)(xa * sensitivity) * signa;
      break;
    case 7:
$LN21_3:
      if ( joy_sensitive_step0.m_pParent->m_Value.m_fValue > COERCE_FLOAT(LODWORD(x) & _mask__AbsFloat_) )
        goto LABEL_28;
      if ( joy_sensitive_step2.m_pParent->m_Value.m_fValue > COERCE_FLOAT(LODWORD(x) & _mask__AbsFloat_) )
      {
        if ( x >= 0.0 )
          goto LABEL_32;
        v13 = -1.0;
        goto LABEL_33;
      }
      if ( x >= 0.0 )
        goto LABEL_36;
      result = -1.0;
      break;
    case 8:
      LODWORD(v14) = LODWORD(x) & _mask__AbsFloat_;
      if ( joy_sensitive_step0.m_pParent->m_Value.m_fValue > COERCE_FLOAT(LODWORD(x) & _mask__AbsFloat_) )
        goto LABEL_28;
      m_fValue = joy_sensitive_step2.m_pParent->m_Value.m_fValue;
      if ( m_fValue <= v14 )
      {
        v17 = (float)(85.0 / cl_forwardspeed.m_pParent->m_Value.m_fValue)
            + (float)((float)((float)(v14 - joy_sensitive_step2.m_pParent->m_Value.m_fValue)
                            / (float)(1.0 - joy_sensitive_step2.m_pParent->m_Value.m_fValue))
                    * (float)(1.0 - (float)(85.0 / cl_forwardspeed.m_pParent->m_Value.m_fValue)));
        if ( x >= 0.0 )
          result = 1.0 * v17;
        else
          result = -1.0 * v17;
      }
      else
      {
        v16 = (float)(85.0 / cl_forwardspeed.m_pParent->m_Value.m_fValue)
            * (float)((float)(v14 - joy_sensitive_step0.m_pParent->m_Value.m_fValue)
                    / (float)(m_fValue - joy_sensitive_step0.m_pParent->m_Value.m_fValue));
        if ( x >= 0.0 )
          goto LABEL_41;
        result = -1.0 * v16;
      }
      break;
    case 9:
      LODWORD(v18) = LODWORD(x) & _mask__AbsFloat_;
      if ( joy_sensitive_step0.m_pParent->m_Value.m_fValue > COERCE_FLOAT(LODWORD(x) & _mask__AbsFloat_) )
      {
LABEL_28:
        result = 0.0;
      }
      else
      {
        v19 = joy_sensitive_step1.m_pParent->m_Value.m_fValue;
        if ( v19 <= v18 )
        {
          if ( joy_sensitive_step2.m_pParent->m_Value.m_fValue <= v18 )
          {
            if ( x >= 0.0 )
LABEL_36:
              result = 1.0;
            else
              result = -1.0;
          }
          else
          {
            if ( x >= 0.0 )
LABEL_32:
              v13 = 1.0;
            else
              v13 = -1.0;
LABEL_33:
            result = (float)(85.0 / cl_forwardspeed.m_pParent->m_Value.m_fValue) * v13;
          }
        }
        else
        {
          v16 = (float)(85.0 / cl_forwardspeed.m_pParent->m_Value.m_fValue)
              * (float)((float)(v18 - joy_sensitive_step0.m_pParent->m_Value.m_fValue)
                      / (float)(v19 - joy_sensitive_step0.m_pParent->m_Value.m_fValue));
          if ( x >= 0.0 )
LABEL_41:
            result = 1.0 * v16;
          else
            result = -1.0 * v16;
        }
      }
      break;
    default:
      v9 = x;
LABEL_55:
      result = v9 * sensitivity;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101132E0
// Name: protected: virtual bool CInput::ControllerModeActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInput::ControllerModeActive(CInput *this)
{
  return in_joystick.m_pParent != nullptr && in_joystick.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10113300
// Name: protected: virtual bool CInput::JoyStickActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInput::JoyStickActive(CInput *this)
{
  return in_joystick.m_pParent != nullptr
      && in_joystick.m_pParent->m_Value.m_nValue != 0
      && inputsystem->GetJoystickCount(this: inputsystem) != 0
      && g_pInputStackSystem->IsTopmostEnabledContext(this: g_pInputStackSystem, a2: this->m_hInputContext);
}

//------------------------------------------------------------------------------
// Address: 0x10113350
// Name: protected: virtual void CInput::JoyStickThirdPersonPlatformer(class CUserCmd __near *,float __near &,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CInput::JoyStickThirdPersonPlatformer(
        CInput *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CUserCmd *cmd,
        float *forward,
        float *side,
        float *pitch,
        float *yaw)
{
  const CInput::PerUserInput_t *PerUser; // esi
  double v11; // xmm0_8
  float *v12; // ecx
  float *v13; // edx
  float v15; // [esp+30h] [ebp-18h] BYREF
  float value; // [esp+34h] [ebp-14h]
  QAngle viewangles; // [esp+3Ch] [ebp-Ch]
  float retaddr; // [esp+48h] [ebp+0h]

  viewangles.x = a2;
  viewangles.y = retaddr;
  ((void (__thiscall *)(IVEngineClient *, float *, int, int))engine->GetViewAngles)(a1: engine, a2: &v15, a3, a4);
  PerUser = CInput::GetPerUser(this, nSlot: 0);
  if ( *forward != 0.0 || *side != 0.0 )
  {
    v11 = COERCE_FLOAT(*(_DWORD *)side ^ _mask__NegFloat_);
    __libm_sse2_atan2();
    *(float *)&v11 = v11;
    value = (float)(*(float *)&v11 * 57.29578) + PerUser->m_vecCameraOffset.y;
    engine->SetViewAngles(this: engine, a2: (QAngle *)&v15);
    cmd->forwardmove = (float)(cl_forwardspeed.m_pParent->m_Value.m_fValue
                             * fsqrt((float)(*side * *side) + (float)(*forward * *forward)))
                     + cmd->forwardmove;
  }
  v12 = pitch;
  if ( *pitch != 0.0 || (v13 = yaw, *yaw != 0.0) )
  {
    if ( (_S7_10 & 1) == 0 )
    {
      _S7_10 |= 1u;
      SplitScreenConVarRef::SplitScreenConVarRef(this: &s_joy_yawsensitivity, pName: "joy_yawsensitivity");
    }
    if ( (_S7_10 & 2) == 0 )
    {
      _S7_10 |= 2u;
      SplitScreenConVarRef::SplitScreenConVarRef(this: &s_joy_pitchsensitivity, pName: "joy_pitchsensitivity");
    }
    v12 = pitch;
    v13 = yaw;
    PerUser->m_vecCameraOffset.x = (float)(s_joy_pitchsensitivity.m_Info[0].m_pConVarState->m_Value.m_fValue * *pitch)
                                 + PerUser->m_vecCameraOffset.x;
    PerUser->m_vecCameraOffset.y = (float)(s_joy_yawsensitivity.m_Info[0].m_pConVarState->m_Value.m_fValue * *yaw)
                                 + PerUser->m_vecCameraOffset.y;
  }
  if ( *forward != 0.0 || *side != 0.0 || *v12 != 0.0 || *v13 != 0.0 )
  {
    ConVar::SetValue(this: (ConVar *)&cam_idealpitch.IConVar, value: PerUser->m_vecCameraOffset.x - v15);
    ConVar::SetValue(this: (ConVar *)&cam_idealyaw.IConVar, value: PerUser->m_vecCameraOffset.y - value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113560
// Name: protected: virtual void CInput::JoyStickMove(float,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CInput::JoyStickMove(CInput *this@<ecx>, int a2@<esi>, float frametime, CUserCmd *cmd)
{
  const CInput::PerUserInput_t *PerUser; // eax
  const CInput::PerUserInput_t *v6; // esi
  float m_flRemainingJoystickSampleTime; // xmm0_4
  float v8; // xmm1_4
  bool v9; // cl
  bool v10; // dl
  unsigned __int64 v11; // [esp+4Ch] [ebp-30h]
  float joySideMove; // [esp+60h] [ebp-1Ch]
  float joyForwardMove; // [esp+64h] [ebp-18h] BYREF
  float pitch; // [esp+68h] [ebp-14h] BYREF
  float yaw; // [esp+6Ch] [ebp-10h] BYREF
  int forward; // [esp+70h] [ebp-Ch] BYREF
  int side; // [esp+74h] [ebp-8h] BYREF
  bool bAbsolutePitch; // [esp+7Ah] [ebp-2h] BYREF
  bool bAbsoluteYaw; // [esp+7Bh] [ebp-1h] BYREF

  if ( !this->m_fJoystickAdvancedInit )
    this->Joystick_Advanced(this, a2: false);
  if ( in_joystick.m_pParent != nullptr
    && in_joystick.m_pParent->m_Value.m_nValue != 0
    && inputsystem->GetJoystickCount(this: inputsystem) != 0
    && !g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
    && !enginevgui->IsGameUIVisible(this: enginevgui)
    && !g_pScaleformUI->SlotDeniesInputToGame(this: g_pScaleformUI, a2: 2) )
  {
    PerUser = CInput::GetPerUser(this, nSlot: 0);
    v6 = PerUser;
    m_flRemainingJoystickSampleTime = PerUser->m_flRemainingJoystickSampleTime;
    if ( m_flRemainingJoystickSampleTime > 0.0 )
    {
      v8 = frametime;
      if ( frametime > m_flRemainingJoystickSampleTime )
      {
        v8 = PerUser->m_flRemainingJoystickSampleTime;
        frametime = v8;
      }
      PerUser->m_flRemainingJoystickSampleTime = m_flRemainingJoystickSampleTime - v8;
      ((void (__thiscall *)(CInput *, int *, int *, float *, float *, bool *, bool *, int))this->JoyStickSampleAxes)(
        a1: this,
        a2: &forward,
        a3: &side,
        a4: &pitch,
        a5: &yaw,
        a6: &bAbsoluteYaw,
        a7: &bAbsolutePitch,
        a8: a2);
      if ( this->CAM_IsThirdPerson(this, a2: -1) != 0
        && thirdperson_platformer.m_pParent != nullptr
        && thirdperson_platformer.m_pParent->m_Value.m_nValue != 0 )
      {
        ((void (__thiscall *)(CInput *, CUserCmd *, int *, int *, float *))this->JoyStickThirdPersonPlatformer)(
          a1: this,
          a2: cmd,
          a3: &forward,
          a4: &side,
          a5: &pitch);
        return;
      }
      ((void (__thiscall *)(CInput *, int, int, float *))this->JoyStickForwardSideControl)(
        a1: this,
        a2: forward,
        a3: side,
        a4: &joyForwardMove);
      v9 = bAbsoluteYaw;
      v10 = bAbsolutePitch;
      v6->m_flPreviousJoystickForwardMove = joyForwardMove;
      v6->m_flPreviousJoystickSideMove = joySideMove;
      v6->m_flPreviousJoystickYaw = yaw;
      v6->m_flPreviousJoystickPitch = pitch;
      v6->m_bPreviousJoystickUseAbsoluteYaw = v9;
      v6->m_bPreviousJoystickUseAbsolutePitch = v10;
    }
    if ( this->JoyStickActive(this) )
    {
      v11 = __PAIR64__(v6->m_bPreviousJoystickUseAbsolutePitch, v6->m_bPreviousJoystickUseAbsoluteYaw);
      ((void (__thiscall *)(CInput *, CUserCmd *, float *, float *, _DWORD, _DWORD, _DWORD))this->JoyStickTurn)(
        a1: this,
        a2: cmd,
        a3: &v6->m_flPreviousJoystickYaw,
        a4: &v6->m_flPreviousJoystickPitch,
        a5: LODWORD(frametime),
        a6: v11,
        a7: HIDWORD(v11));
      ((void (__thiscall *)(CInput *, CUserCmd *, _DWORD, _DWORD))this->JoyStickApplyMovement)(
        a1: this,
        a2: cmd,
        a3: LODWORD(v6->m_flPreviousJoystickForwardMove),
        a4: LODWORD(v6->m_flPreviousJoystickSideMove));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113780
// Name: protected: virtual void CInput::JoyStickApplyMovement(class CUserCmd __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::JoyStickApplyMovement(CInput *this, CUserCmd *cmd, float joyForwardMove, float joySideMove)
{
  __m128 m_fValue_low; // xmm0
  double v5; // xmm0_8
  CUserCmd *v6; // eax
  double v7; // xmm0_8
  float v8; // xmm4_4
  float v9; // xmm0_4
  float m_fValue; // xmm0_4
  CCommand tmp; // [esp+0h] [ebp-510h] BYREF
  int v12; // [esp+508h] [ebp-8h]
  float ideal_sin; // [esp+50Ch] [ebp-4h]

  if ( this->CAM_IsThirdPerson(this, a2: -1) != 0
    && thirdperson_screenspace.m_pParent != nullptr
    && thirdperson_screenspace.m_pParent->m_Value.m_nValue != 0 )
  {
    m_fValue_low = (__m128)LODWORD(cam_idealyaw.m_pParent->m_Value.m_fValue);
    m_fValue_low.m128_f32[0] = m_fValue_low.m128_f32[0] * 0.017453292;
    v12 = m_fValue_low.m128_i32[0];
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(m_fValue_low));
    *(float *)&v5 = v5;
    ideal_sin = *(float *)&v5;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)v12));
    v6 = cmd;
    *(float *)&v7 = v7;
    v8 = (float)((float)(*(float *)&v7 * joyForwardMove) + (float)(ideal_sin * joySideMove)) + cmd->forwardmove;
    v9 = (float)((float)(*(float *)&v7 * joySideMove) - (float)(ideal_sin * joyForwardMove)) + cmd->sidemove;
    cmd->forwardmove = v8;
  }
  else
  {
    v6 = cmd;
    cmd->forwardmove = cmd->forwardmove + joyForwardMove;
    v9 = cmd->sidemove + joySideMove;
  }
  v6->sidemove = v9;
  CCommand::CCommand(this: &tmp);
  m_fValue = joy_autosprint.m_pParent->m_Value.m_fValue;
  if ( fabs(joyForwardMove) >= m_fValue || fabs(joySideMove) >= m_fValue )
    KeyDown(b: &in_joyspeed, c: nullptr);
  else
    KeyUp(b: &in_joyspeed, c: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101138B0
// Name: protected: float CInput::ResponseCurveLookDefault(int,float,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInput::ResponseCurveLookDefault(
        CInput *this,
        int nSlot,
        float x,
        int axis,
        float otherAxis,
        float dist,
        float frametime)
{
  float v8; // xmm0_4
  BOOL v10; // ecx
  envelope_t *v12; // eax
  bool v13; // dl
  char v14; // bl
  ConVar *m_pParent; // ecx
  ConVar *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  C_CSPlayer *LocalPlayer; // eax
  float m_fValue; // xmm0_4
  float m_lastAutoAimValue; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float xa; // [esp+2Ch] [ebp+Ch]
  float xb; // [esp+2Ch] [ebp+Ch]

  v8 = x;
  v10 = nSlot <= 0;
  v12 = &controlEnvelope[v10 ? 0 : nSlot];
  v13 = dist >= joy_pegged.m_pParent->m_Value.m_fValue;
  v14 = 0;
  if ( x < 0.0 )
  {
    v8 = x * -1.0;
    v14 = 1;
  }
  if ( axis == 1 && joy_virtual_peg.m_pParent != nullptr && joy_virtual_peg.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( v8 >= 0.94999999 )
    {
      v12->peggedAxis[1] = true;
      v12->axisPeggedDir[1] = v14;
    }
    if ( v12->peggedAxis[1] )
    {
      if ( v13 && v14 == v12->axisPeggedDir[1] )
        v8 = 1.0;
      else
        v12->peggedAxis[1] = false;
    }
  }
  m_pParent = joy_lowend.m_pParent;
  if ( v8 <= joy_lowend.m_pParent->m_Value.m_fValue )
  {
    v12->envelopeScale[axis] = 0.0;
    v20 = (float)(v8 / m_pParent->m_Value.m_fValue) * joy_lowmap.m_pParent->m_Value.m_fValue;
  }
  else
  {
    v16 = joy_lowmap.m_pParent;
    v17 = v12->envelopeScale[axis];
    v18 = (float)((float)((float)(v8 - joy_lowend.m_pParent->m_Value.m_fValue)
                        / (float)(1.0 - joy_lowend.m_pParent->m_Value.m_fValue))
                * (float)(1.0 - joy_lowmap.m_pParent->m_Value.m_fValue))
        + joy_lowmap.m_pParent->m_Value.m_fValue;
    if ( v17 < 1.0 )
    {
      v19 = (float)(joy_accelscale.m_pParent->m_Value.m_fValue * frametime) + v17;
      v12->envelopeScale[axis] = v19;
      if ( v19 > 1.0 )
        v12->envelopeScale[axis] = 1.0;
    }
    v20 = (float)((float)(v18 - v16->m_Value.m_fValue) * v12->envelopeScale[axis]) + v16->m_Value.m_fValue;
  }
  xa = v20;
  if ( joy_autoaimdampen.m_pParent->m_Value.m_fValue > 0.0
    && joy_autoaimdampenrange.m_pParent->m_Value.m_fValue > COERCE_FLOAT(LODWORD(x) & _mask__AbsFloat_)
    && (LocalPlayer = CClientTools::GetLocalPlayer()) != nullptr
    && C_CSPlayer::IsCursorOnAutoAimTarget(this: LocalPlayer) )
  {
    m_fValue = joy_autoaimdampen.m_pParent->m_Value.m_fValue;
    this->m_lastAutoAimValue = m_fValue;
  }
  else
  {
    m_lastAutoAimValue = this->m_lastAutoAimValue;
    if ( m_lastAutoAimValue < 1.0 )
    {
      v24 = (float)(joy_autoaim_dampen_smoothout_speed.m_pParent->m_Value.m_fValue * frametime) + m_lastAutoAimValue;
      this->m_lastAutoAimValue = v24;
      if ( v24 >= 1.0 )
        this->m_lastAutoAimValue = 1.0;
    }
    m_fValue = this->m_lastAutoAimValue;
  }
  v25 = m_fValue * xa;
  xb = v25;
  if ( axis == 1
    && v25 > 0.0
    && joy_display_input.m_pParent != nullptr
    && joy_display_input.m_pParent->m_Value.m_nValue != 0 )
  {
    _Msg(a1: "In:%f Out:%f Frametime:%f\n", x, v25, frametime);
  }
  if ( v14 != 0 )
    return (float)(v25 * -1.0);
  return xb;
}

//------------------------------------------------------------------------------
// Address: 0x10113AF0
// Name: protected: float CInput::ResponseCurveLookAccelerated(int,float,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInput::ResponseCurveLookAccelerated(
        CInput *this,
        int nSlot,
        float x,
        int axis,
        float otherAxis,
        float dist,
        float frametime)
{
  float m_fValue; // xmm1_4
  envelope_t *v9; // esi
  bool v10; // al
  float v11; // xmm0_4
  float v12; // xmm0_4
  ConVar *v13; // ecx
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm6_4
  C_CSPlayer *LocalPlayer; // eax
  float v20; // xmm0_4
  ConVar *m_pParent; // ecx
  float v22; // xmm3_4
  float v23; // xmm2_4
  float m_lastAutoAimValue; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float input; // [esp+0h] [ebp-4h]
  float negative; // [esp+Ch] [ebp+8h]
  char negative_3; // [esp+Fh] [ebp+Bh]
  float xa; // [esp+10h] [ebp+Ch]

  m_fValue = x;
  v9 = &controlEnvelope[nSlot <= 0 ? 0 : nSlot];
  input = x;
  v10 = fsqrt((float)(m_fValue * m_fValue) + (float)(otherAxis * otherAxis)) >= joy_pegged.m_pParent->m_Value.m_fValue;
  if ( joy_useNewAcecelMethod.m_pParent != nullptr && joy_useNewAcecelMethod.m_pParent->m_Value.m_nValue != 0 )
  {
    negative = fabs(x);
    v11 = fabs(otherAxis);
    if ( v11 <= 0.25 )
      v11 = 0.25;
    __libm_sse2_pow();
    __libm_sse2_pow();
    __libm_sse2_pow();
    v10 = (float)(v11 + negative) >= 0.94;
    m_fValue = x;
  }
  v12 = (float)(joy_gamma.m_pParent->m_Value.m_fValue * 2.0) - 1.0;
  negative_3 = 0;
  if ( m_fValue < 0.0 )
  {
    m_fValue = m_fValue * -1.0;
    negative_3 = 1;
    x = m_fValue;
  }
  if ( !v10 || m_fValue <= joy_accel_filter.m_pParent->m_Value.m_fValue )
  {
    m_pParent = joy_lowend.m_pParent;
    v9->envelopeScale[axis] = 0.0;
    v22 = m_fValue / m_pParent->m_Value.m_fValue;
    v23 = (float)(v22 * v12) + 1.0;
    if ( v23 == 0.0 )
      goto LABEL_21;
    m_fValue = (float)((float)((float)(v12 + 1.0) * v22) / v23) * joy_lowmap.m_pParent->m_Value.m_fValue;
    goto LABEL_20;
  }
  v13 = joy_lowmap.m_pParent;
  if ( (joy_no_accel_jump.m_pParent == nullptr || joy_no_accel_jump.m_pParent->m_Value.m_nValue == 0)
    && joy_lowmap.m_pParent->m_Value.m_fValue > m_fValue )
  {
    m_fValue = joy_lowmap.m_pParent->m_Value.m_fValue;
  }
  v14 = joy_accelmax.m_pParent->m_Value.m_fValue;
  v15 = (float)(joy_accelscale.m_pParent->m_Value.m_fValue * frametime) + v9->envelopeScale[axis];
  v9->envelopeScale[axis] = v15;
  if ( v15 > v14 )
    v9->envelopeScale[axis] = v14;
  m_fValue = (float)((float)(m_fValue - v13->m_Value.m_fValue) * v9->envelopeScale[axis]) + v13->m_Value.m_fValue;
  v16 = m_fValue / joy_lowend.m_pParent->m_Value.m_fValue;
  v17 = (float)(v16 * v12) + 1.0;
  x = m_fValue;
  v18 = 0.0;
  if ( v17 != 0.0 )
    v18 = (float)((float)((float)(v12 + 1.0) * v16) / v17) * v13->m_Value.m_fValue;
  if ( m_fValue <= v18 )
  {
    m_fValue = v18;
LABEL_20:
    x = m_fValue;
  }
LABEL_21:
  if ( joy_autoaimdampen.m_pParent->m_Value.m_fValue > 0.0
    && joy_autoaimdampenrange.m_pParent->m_Value.m_fValue > fabs(input) )
  {
    LocalPlayer = CClientTools::GetLocalPlayer();
    if ( LocalPlayer != nullptr && C_CSPlayer::IsCursorOnAutoAimTarget(this: LocalPlayer) )
    {
      v20 = joy_autoaimdampen.m_pParent->m_Value.m_fValue;
      m_fValue = x;
      this->m_lastAutoAimValue = v20;
      goto LABEL_33;
    }
    m_fValue = x;
  }
  m_lastAutoAimValue = this->m_lastAutoAimValue;
  if ( m_lastAutoAimValue < 1.0 )
  {
    v25 = (float)(joy_autoaim_dampen_smoothout_speed.m_pParent->m_Value.m_fValue * frametime) + m_lastAutoAimValue;
    this->m_lastAutoAimValue = v25;
    if ( v25 >= 1.0 )
      this->m_lastAutoAimValue = 1.0;
  }
  v20 = this->m_lastAutoAimValue;
LABEL_33:
  v26 = v20 * m_fValue;
  xa = v26;
  if ( negative_3 != 0 )
    return (float)(v26 * -1.0);
  return xa;
}

//------------------------------------------------------------------------------
// Address: 0x10113E10
// Name: public: virtual void CInput::Joystick_Advanced(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::Joystick_Advanced(CInput *this, bool bSilent)
{
  int i; // edi
  CInput::joy_axis_t *PerUser; // esi
  char *m_pszString; // eax
  char *v6; // eax
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  bool v9; // zf
  ConVar *v10; // eax
  int v11; // eax
  int v12; // eax
  ConVar *v13; // eax
  int v14; // eax
  ConVar *v15; // eax
  int v16; // eax
  int v17; // eax
  ConVarRef var; // [esp+Ch] [ebp-Ch] BYREF
  bool bJoyMovementStick; // [esp+17h] [ebp-1h]

  this->m_fJoystickAdvancedInit = true;
  for ( i = 0; i < 1; ++i )
  {
    PerUser = (CInput::joy_axis_t *)CInput::GetPerUser(this, nSlot: -1);
    PerUser[3].AxisMap = 0;
    PerUser[3].ControlMap = 0;
    PerUser[4].AxisMap = 0;
    PerUser[4].ControlMap = 0;
    PerUser[5].AxisMap = 0;
    PerUser[5].ControlMap = 0;
    PerUser[6].AxisMap = 0;
    PerUser[6].ControlMap = 0;
    PerUser[7].AxisMap = 0;
    PerUser[7].ControlMap = 0;
    PerUser[8].AxisMap = 0;
    PerUser[8].ControlMap = 0;
    if ( joy_advanced.m_pParent != nullptr && joy_advanced.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( !bSilent && i == 0 )
      {
        if ( (joy_name.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = joy_name.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)prType;
        }
        if ( _V_stricmp(s1: m_pszString, s2: "joystick") != 0 )
        {
          if ( (joy_name.m_nFlags & 0x1000) != 0 )
          {
            v6 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v6 = joy_name.m_pParent->m_Value.m_pszString;
            if ( v6 == nullptr )
              v6 = (char *)prType;
          }
          _Msg(a1: "Using joystick '%s' configuration\n", v6);
        }
      }
      if ( (_S5_102 & 1) == 0 )
      {
        _S5_102 |= 1u;
        SplitScreenConVarRef::SplitScreenConVarRef(this: &s_joy_movement_stick, pName: "joy_movement_stick");
      }
      bJoyMovementStick = s_joy_movement_stick.m_Info[i].m_pConVarState->m_Value.m_nValue != 0;
      m_pParent = joy_advaxisu.m_pParent;
      if ( !bJoyMovementStick )
        m_pParent = joy_advaxisx.m_pParent;
      if ( m_pParent != nullptr )
        m_nValue = m_pParent->m_Value.m_nValue;
      else
        LOBYTE(m_nValue) = 0;
      v9 = !bJoyMovementStick;
      PerUser[3].AxisMap = m_nValue & 0xF;
      PerUser[3].ControlMap = m_nValue & 0x10;
      v10 = joy_advaxisr.m_pParent;
      if ( v9 )
        v10 = joy_advaxisy.m_pParent;
      if ( v10 != nullptr )
        v11 = v10->m_Value.m_nValue;
      else
        LOBYTE(v11) = 0;
      PerUser[4].AxisMap = v11 & 0xF;
      PerUser[4].ControlMap = v11 & 0x10;
      if ( joy_advaxisz.m_pParent != nullptr )
        v12 = joy_advaxisz.m_pParent->m_Value.m_nValue;
      else
        LOBYTE(v12) = 0;
      v9 = !bJoyMovementStick;
      PerUser[5].AxisMap = v12 & 0xF;
      PerUser[5].ControlMap = v12 & 0x10;
      v13 = joy_advaxisy.m_pParent;
      if ( v9 )
        v13 = joy_advaxisr.m_pParent;
      if ( v13 != nullptr )
        v14 = v13->m_Value.m_nValue;
      else
        LOBYTE(v14) = 0;
      v9 = !bJoyMovementStick;
      PerUser[6].AxisMap = v14 & 0xF;
      PerUser[6].ControlMap = v14 & 0x10;
      v15 = joy_advaxisx.m_pParent;
      if ( v9 )
        v15 = joy_advaxisu.m_pParent;
      if ( v15 != nullptr )
        v16 = v15->m_Value.m_nValue;
      else
        LOBYTE(v16) = 0;
      PerUser[7].AxisMap = v16 & 0xF;
      PerUser[7].ControlMap = v16 & 0x10;
      if ( joy_advaxisv.m_pParent != nullptr )
        v17 = joy_advaxisv.m_pParent->m_Value.m_nValue;
      else
        LOBYTE(v17) = 0;
      PerUser[8].AxisMap = v17 & 0xF;
      PerUser[8].ControlMap = v17 & 0x10;
      if ( !bSilent )
      {
        _Msg(a1: "Advanced joystick settings initialized for joystick %d\n------------\n", i + 1);
        CInput::DescribeJoystickAxis(this, nJoystick: i, axis: "x axis", mapping: PerUser + 3);
        CInput::DescribeJoystickAxis(this, nJoystick: i, axis: "y axis", mapping: PerUser + 4);
        CInput::DescribeJoystickAxis(this, nJoystick: i, axis: "z axis", mapping: PerUser + 5);
        CInput::DescribeJoystickAxis(this, nJoystick: i, axis: "r axis", mapping: PerUser + 6);
        CInput::DescribeJoystickAxis(this, nJoystick: i, axis: "u axis", mapping: PerUser + 7);
        CInput::DescribeJoystickAxis(this, nJoystick: i, axis: "v axis", mapping: PerUser + 8);
      }
    }
    else
    {
      PerUser[3].AxisMap = 4;
      PerUser[4].AxisMap = 1;
    }
  }
  ConVarRef::ConVarRef(this: &var, pName: "joy_xcontroller_found");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var)
    && var.m_pConVarState->m_Value.m_nValue != 0
    && in_joystick.m_pParent != nullptr
    && in_joystick.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( joy_xcontroller_cfg_loaded.m_pParent == nullptr || joy_xcontroller_cfg_loaded.m_pParent->m_Value.m_nValue == 0 )
    {
      engine->ClientCmd_Unrestricted(this: engine, a2: "exec controller.cfg");
      ConVar::SetValue(this: (ConVar *)&joy_xcontroller_cfg_loaded.IConVar, value: 1);
    }
  }
  else if ( joy_xcontroller_cfg_loaded.m_pParent != nullptr
         && joy_xcontroller_cfg_loaded.m_pParent->m_Value.m_nValue != 0 )
  {
    engine->ClientCmd_Unrestricted(this: engine, a2: "exec undo360controller.cfg");
    ConVar::SetValue(this: (ConVar *)&joy_xcontroller_cfg_loaded.IConVar, value: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114120
// Name: protected: virtual void CInput::JoyStickSampleAxes(float __near &,float __near &,float __near &,float __near &,bool __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::JoyStickSampleAxes(
        CInput *this,
        float *forward,
        float *side,
        float *pitch,
        float *yaw,
        bool *bAbsoluteYaw,
        bool *bAbsolutePitch)
{
  CInput::PerUserInput_t *PerUser; // eax
  int v8; // esi
  unsigned int *p_AxisMap; // edi
  float v10; // xmm0_4
  unsigned int v11; // eax
  int v12; // ecx
  ConVar_ServerBounded_vtbl *v13; // edx
  float (__thiscall *GetFloat)(ConVar_ServerBounded *); // eax
  kbutton_t::Split_t *v15; // eax
  int controlType; // esi
  int v17; // edi
  float value; // eax
  int v19; // ecx
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  bool v31; // zf
  CInput::JoyStickSampleAxes::__l2::axis_t gameAxes[5]; // [esp+8h] [ebp-30h] BYREF
  CInput::PerUserInput_t *user; // [esp+30h] [ebp-8h]
  float fAxisValue; // [esp+34h] [ebp-4h]

  PerUser = (CInput::PerUserInput_t *)CInput::GetPerUser(this, nSlot: 0);
  memset(gameAxes, 0, sizeof(gameAxes));
  user = PerUser;
  v8 = 0;
  p_AxisMap = &PerUser->m_rgAxes[0].AxisMap;
  do
  {
    if ( *p_AxisMap != 0 )
    {
      v10 = (float)inputsystem->GetAnalogValue(this: inputsystem, a2: (AnalogCode_t)(v8 + 4));
      fAxisValue = v10;
      if ( joy_wwhack2.m_pParent != nullptr && joy_wwhack2.m_pParent->m_Value.m_nValue != 0 )
      {
        __libm_sse2_pow();
        v10 = COERCE_FLOAT(LODWORD(v10) & _mask__AbsFloat_) * 0.00125 * 300.0;
        if ( v10 > 14000.0 )
          v10 = 14000.0;
        if ( fAxisValue <= 0.0 )
          v10 = -v10;
      }
      v11 = *p_AxisMap;
      v12 = p_AxisMap[1];
      gameAxes[v11].value = v10;
      gameAxes[v11].controlType = v12;
      PerUser = user;
    }
    ++v8;
    p_AxisMap += 3;
  }
  while ( v8 < 6 );
  if ( PerUser->m_bForceJoystickRecentering[0] )
  {
    if ( fabs(gameAxes[1].value) < 0.1 && fabs(gameAxes[3].value) < 0.1 )
      PerUser->m_bForceJoystickRecentering[0] = false;
    gameAxes[1].value = 0.0;
    gameAxes[3].value = 0.0;
  }
  if ( PerUser->m_bForceJoystickRecentering[1] )
  {
    if ( fabs(gameAxes[2].value) < 0.1 && fabs(gameAxes[4].value) < 0.1 )
      PerUser->m_bForceJoystickRecentering[1] = false;
    gameAxes[2].value = 0.0;
    gameAxes[4].value = 0.0;
  }
  if ( (joy_advanced.m_pParent == nullptr || joy_advanced.m_pParent->m_Value.m_nValue == 0)
    && (kbutton_t::GetPerUser(this: &in_jlook, nSlot: 0)->state & 1) != 0 )
  {
    gameAxes[2].value = gameAxes[1].value;
    v13 = m_pitch->ConVar::ConCommandBase::__vftable;
    gameAxes[2].controlType = gameAxes[1].controlType;
    GetFloat = v13->GetFloat;
    gameAxes[1].value = 0.0;
    if ( ((double (__thiscall *)(ConVar_ServerBounded *))GetFloat)(a1: m_pitch) < 0.0 )
      gameAxes[2].value = gameAxes[2].value * -1.0;
  }
  v15 = kbutton_t::GetPerUser(this: &in_strafe, nSlot: 0);
  controlType = gameAxes[4].controlType;
  if ( (v15->state & 1) != 0
    || lookstrafe.m_pParent->m_Value.m_fValue != 0.0
    && (kbutton_t::GetPerUser(this: &in_jlook, nSlot: 0)->state & 1) != 0 )
  {
    gameAxes[3].value = gameAxes[4].value;
    v17 = controlType;
    gameAxes[4].value = 0.0;
  }
  else
  {
    v17 = gameAxes[3].controlType;
  }
  if ( (_S6_30 & 1) == 0 )
  {
    _S6_30 |= 1u;
    SplitScreenConVarRef::SplitScreenConVarRef(this: &s_joy_legacy, pName: "joy_legacy");
  }
  if ( ConVarRef::IsValid(this: &s_joy_legacy) && s_joy_legacy.m_Info[0].m_pConVarState->m_Value.m_nValue != 0 )
  {
    value = gameAxes[4].value;
    v19 = controlType;
    gameAxes[4].value = gameAxes[3].value;
    controlType = v17;
    gameAxes[3].value = value;
    gameAxes[3].controlType = v19;
  }
  v20 = gameAxes[3].value;
  v21 = joy_forwardthreshold.m_pParent->m_Value.m_fValue * 32768.0;
  v22 = 0.0;
  if ( (float)-v21 <= gameAxes[1].value )
  {
    if ( gameAxes[1].value > v21 )
      v22 = (float)(gameAxes[1].value - v21) / (float)(32768.0 - v21);
  }
  else
  {
    v22 = (float)(v21 + gameAxes[1].value) / (float)(32768.0 - v21);
  }
  *forward = v22;
  v23 = joy_sidethreshold.m_pParent->m_Value.m_fValue * 32768.0;
  v24 = 0.0;
  if ( (float)-v23 <= v20 )
  {
    if ( v20 > v23 )
      v24 = (float)(v20 - v23) / (float)(32768.0 - v23);
  }
  else
  {
    v24 = (float)(v23 + v20) / (float)(32768.0 - v23);
  }
  v25 = gameAxes[2].value;
  *side = v24;
  v26 = joy_pitchthreshold.m_pParent->m_Value.m_fValue * 32768.0;
  v27 = 0.0;
  if ( (float)-v26 <= v25 )
  {
    if ( v25 > v26 )
      v27 = (float)(v25 - v26) / (float)(32768.0 - v26);
  }
  else
  {
    v27 = (float)(v26 + v25) / (float)(32768.0 - v26);
  }
  v28 = gameAxes[4].value;
  *pitch = v27;
  v29 = joy_yawthreshold.m_pParent->m_Value.m_fValue * 32768.0;
  v30 = 0.0;
  if ( (float)-v29 <= v28 )
  {
    if ( v28 > v29 )
      v30 = (float)(v28 - v29) / (float)(32768.0 - v29);
  }
  else
  {
    v30 = (float)(v29 + v28) / (float)(32768.0 - v29);
  }
  v31 = gameAxes[2].controlType == 0;
  *yaw = v30;
  *bAbsoluteYaw = controlType == 0;
  *bAbsolutePitch = v31;
  if ( (_S6_30 & 2) == 0 )
  {
    _S6_30 |= 2u;
    SplitScreenConVarRef::SplitScreenConVarRef(this: &s_joy_inverty, pName: "joy_inverty");
  }
  if ( !ConVarRef::IsValid(this: &s_joy_inverty) || s_joy_inverty.m_Info[0].m_pConVarState->m_Value.m_nValue == 0 )
    *pitch = *pitch * -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10114550
// Name: protected: virtual void CInput::JoyStickTurn(class CUserCmd __near *,float __near &,float __near &,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CInput::JoyStickTurn(
        CInput *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CUserCmd *cmd,
        float *yaw,
        float *pitch,
        float frametime,
        bool bAbsoluteYaw,
        bool bAbsolutePitch)
{
  void (__thiscall *GetViewAngles)(IVEngineClient *, QAngle *); // eax
  const CInput::PerUserInput_t *PerUser; // edi
  int m_nValue; // eax
  float v14; // xmm0_4
  CHud *Hud; // eax
  double FOVSensitivityAdjust; // st7
  float m_flSpinFrameTime; // xmm1_4
  float v18; // xmm3_4
  float m_flSpinRate; // xmm0_4
  float v20; // xmm0_4
  int v21; // eax
  float v22; // xmm1_4
  float v23; // xmm0_4
  double v24; // st7
  C_BasePlayer *LocalPlayer; // esi
  float m_flLastYawAngle; // xmm1_4
  float m_fValue; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  int v30; // eax
  float v31; // xmm1_4
  float v32; // xmm0_4
  double v33; // st7
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v37; // [esp+28h] [ebp-4Ch]
  float v38; // [esp+44h] [ebp-30h] BYREF
  float v39; // [esp+48h] [ebp-2Ch]
  QAngle viewangles; // [esp+50h] [ebp-24h]
  float fAxisValue; // [esp+5Ch] [ebp-18h]
  float aspeed; // [esp+60h] [ebp-14h]
  float v43; // [esp+64h] [ebp-10h]
  float angle; // [esp+68h] [ebp-Ch]
  float lookFrametime; // [esp+6Ch] [ebp-8h]
  float retaddr; // [esp+74h] [ebp+0h]

  angle = a2;
  lookFrametime = retaddr;
  GetViewAngles = engine->GetViewAngles;
  LODWORD(viewangles.z) = this;
  ((void (__thiscall *)(IVEngineClient *, float *, int, int))GetViewAngles)(a1: engine, a2: &v38, a3, a4);
  PerUser = CInput::GetPerUser(this, nSlot: 0);
  if ( (_S8_7 & 1) == 0 )
  {
    _S8_7 |= 1u;
    SplitScreenConVarRef::SplitScreenConVarRef(this: &s_joy_yawsensitivity_0, pName: "joy_yawsensitivity");
  }
  if ( (_S8_7 & 2) == 0 )
  {
    _S8_7 |= 2u;
    SplitScreenConVarRef::SplitScreenConVarRef(this: &s_joy_pitchsensitivity_0, pName: "joy_pitchsensitivity");
  }
  v37 = fsqrt((float)(*pitch * *pitch) + (float)(*yaw * *yaw));
  if ( joy_variable_frametime.m_pParent != nullptr )
    m_nValue = joy_variable_frametime.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  HIBYTE(v43) = m_nValue != 0;
  if ( m_nValue != 0 )
    v14 = frametime;
  else
    v14 = *(float *)(gpGlobals.m_Index + 16);
  aspeed = v14;
  Hud = GetHud(nSlot: -1);
  FOVSensitivityAdjust = CHud::GetFOVSensitivityAdjust(this: Hud);
  m_flSpinFrameTime = PerUser->m_flSpinFrameTime;
  viewangles.y = FOVSensitivityAdjust * aspeed;
  fAxisValue = 0.0;
  if ( m_flSpinFrameTime == 0.0 )
  {
    if ( HIBYTE(v43) == 0 && frametime == *(float *)(gpGlobals.m_Index + 16) )
      goto LABEL_28;
    if ( bAbsoluteYaw )
    {
      if ( joy_response_look.m_pParent != nullptr )
        v21 = joy_response_look.m_pParent->m_Value.m_nValue;
      else
        v21 = 0;
      v22 = *pitch;
      v23 = *yaw;
      v43 = aspeed;
      aspeed = v37;
      fAxisValue = v22;
      LODWORD(viewangles.z) = 1;
      viewangles.y = v23;
      viewangles.x = 0.0;
      if ( v21 == 1 )
        v24 = CInput::ResponseCurveLookAccelerated(
                this: (CInput *)1,
                nSlot: SLODWORD(viewangles.x),
                x: viewangles.y,
                axis: SLODWORD(viewangles.z),
                otherAxis: fAxisValue,
                dist: aspeed,
                frametime: v43);
      else
        v24 = CInput::ResponseCurveLookDefault(
                this: (CInput *)1,
                nSlot: SLODWORD(viewangles.x),
                x: viewangles.y,
                axis: SLODWORD(viewangles.z),
                otherAxis: fAxisValue,
                dist: aspeed,
                frametime: v43);
      viewangles.x = v24;
      v20 = (float)((float)(s_joy_yawsensitivity_0.m_Info[0].m_pConVarState->m_Value.m_fValue * viewangles.x)
                  * viewangles.y)
          * cl_yawspeed.m_pParent->m_Value.m_fValue;
    }
    else
    {
      v20 = (float)((float)(s_joy_yawsensitivity_0.m_Info[0].m_pConVarState->m_Value.m_fValue * *yaw) * viewangles.y)
          * 180.0;
    }
  }
  else
  {
    v18 = aspeed;
    if ( (float)(m_flSpinFrameTime - aspeed) > 0.0 )
    {
      PerUser->m_flSpinFrameTime = m_flSpinFrameTime - aspeed;
      v20 = PerUser->m_flSpinRate * v18;
    }
    else
    {
      m_flSpinRate = PerUser->m_flSpinRate;
      PerUser->m_flSpinFrameTime = 0.0;
      v20 = m_flSpinRate * m_flSpinFrameTime;
    }
  }
  fAxisValue = v20;
  if ( v20 != 0.0 )
    PerUser->m_flLastYawAngle = v20;
LABEL_28:
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0);
  if ( (kbutton_t::GetPerUser(this: &in_lookspin, nSlot: 0)->state & 2) != 0
    && PerUser->m_flSpinFrameTime == 0.0
    && LocalPlayer != nullptr
    && LocalPlayer->GetObserverMode(this: LocalPlayer) == 0 )
  {
    m_flLastYawAngle = PerUser->m_flLastYawAngle;
    m_fValue = joy_lookspin_default.m_pParent->m_Value.m_fValue;
    PerUser->m_flSpinFrameTime = m_fValue;
    if ( m_flLastYawAngle < 0.0 )
      v28 = -180.0;
    else
      v28 = 180.0;
    PerUser->m_flSpinRate = v28 / m_fValue;
  }
  v43 = 0.0;
  v39 = v39 + fAxisValue;
  cmd->mousedx = (int)fAxisValue;
  if ( (kbutton_t::GetPerUser(this: &in_jlook, nSlot: SLODWORD(v43))->state & 1) != 0 )
  {
    v29 = 0.0;
    if ( HIBYTE(v43) != 0 || frametime != *(float *)(gpGlobals.m_Index + 16) )
    {
      if ( bAbsolutePitch )
      {
        if ( joy_response_look_pitch.m_pParent != nullptr )
          v30 = joy_response_look_pitch.m_pParent->m_Value.m_nValue;
        else
          v30 = 0;
        v31 = *yaw;
        v32 = *pitch;
        v43 = aspeed;
        aspeed = v37;
        fAxisValue = v31;
        viewangles.z = 0.0;
        viewangles.y = v32;
        viewangles.x = 0.0;
        if ( v30 == 1 )
          v33 = CInput::ResponseCurveLookAccelerated(
                  this: nullptr,
                  nSlot: SLODWORD(viewangles.x),
                  x: viewangles.y,
                  axis: SLODWORD(viewangles.z),
                  otherAxis: fAxisValue,
                  dist: aspeed,
                  frametime: v43);
        else
          v33 = CInput::ResponseCurveLookDefault(
                  this: nullptr,
                  nSlot: SLODWORD(viewangles.x),
                  x: viewangles.y,
                  axis: SLODWORD(viewangles.z),
                  otherAxis: fAxisValue,
                  dist: aspeed,
                  frametime: v43);
        viewangles.x = v33;
        v29 = (float)((float)(s_joy_pitchsensitivity_0.m_Info[0].m_pConVarState->m_Value.m_fValue * viewangles.x)
                    * viewangles.y)
            * cl_pitchspeed.m_pParent->m_Value.m_fValue;
      }
      else
      {
        v29 = (float)((float)(s_joy_pitchsensitivity_0.m_Info[0].m_pConVarState->m_Value.m_fValue * *pitch)
                    * viewangles.y)
            * 180.0;
      }
    }
    v34 = v38;
    cmd->mousedy = (int)v29;
    v38 = v34 + v29;
    view->StopPitchDrift(this: view);
    if ( *pitch == 0.0 && lookspring.m_pParent->m_Value.m_fValue == 0.0 )
      view->StopPitchDrift(this: view);
  }
  LODWORD(v35) = LODWORD(cl_pitchup.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_;
  if ( v35 <= v38 )
  {
    if ( v38 <= cl_pitchdown.m_pParent->m_Value.m_fValue )
      v35 = v38;
    else
      v35 = cl_pitchdown.m_pParent->m_Value.m_fValue;
  }
  v38 = v35;
  engine->SetViewAngles(this: engine, a2: (QAngle *)&v38);
}

//------------------------------------------------------------------------------
// Address: 0x10114980
// Name: protected: virtual void CInput::JoyStickForwardSideControl(float,float,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::JoyStickForwardSideControl(
        CInput *this,
        float forward,
        float side,
        float *joyForwardMove,
        float *joySideMove)
{
  int m_nValue; // eax
  float v6; // xmm0_4
  float x; // xmm1_4
  char v8; // bl
  float v9; // xmm0_4
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v11; // esi
  unsigned int m_Index; // ecx
  IClientVehicle *Vehicle; // eax
  int v14; // esi
  ConVar *m_pParent; // eax
  float scale; // [esp+18h] [ebp-4h]

  *joySideMove = 0.0;
  *joyForwardMove = 0.0;
  if ( joy_response_move.m_pParent != nullptr )
  {
    m_nValue = joy_response_move.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 6 && joy_circle_correct.m_pParent != nullptr && joy_circle_correct.m_pParent->m_Value.m_nValue != 0 )
    {
      v6 = fsqrt((float)(forward * forward) + (float)(side * side));
      x = 1.0;
      v8 = 1;
      if ( v6 <= 1.0 )
      {
        x = v6;
        scale = v6;
        if ( v6 <= 0.0099999998 )
        {
LABEL_12:
          IN_ForceSpeedUp();
          return;
        }
      }
      else
      {
        scale = 1.0;
      }
      if ( x > joy_sensitive_step2.m_pParent->m_Value.m_fValue )
        v8 = 0;
      v9 = ResponseCurve(curve: m_nValue, x, axis: 0, sensitivity: joy_forwardsensitivity.m_pParent->m_Value.m_fValue);
      *joyForwardMove = (float)((float)((float)(1.0 / scale) * forward) * v9)
                      * cl_forwardspeed.m_pParent->m_Value.m_fValue;
      *joySideMove = (float)((float)((float)((float)(1.0 / scale) * side) * v9)
                           * cl_sidespeed.m_pParent->m_Value.m_fValue)
                   + *joySideMove;
      if ( v8 != 0 )
      {
        IN_ForceSpeedDown();
        return;
      }
      goto LABEL_12;
    }
  }
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v11 = LocalPlayer;
  if ( LocalPlayer == nullptr
    || (m_Index = LocalPlayer->m_hVehicle.m_Index) == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    m_pParent = joy_response_move.m_pParent;
LABEL_21:
    if ( m_pParent != nullptr )
      v14 = m_pParent->m_Value.m_nValue;
    else
      v14 = 0;
    goto LABEL_24;
  }
  if ( C_BasePlayer::GetVehicle(this: LocalPlayer) == nullptr )
  {
    m_pParent = joy_response_move_vehicle.m_pParent;
    goto LABEL_21;
  }
  Vehicle = C_BasePlayer::GetVehicle(this: v11);
  v14 = Vehicle->GetJoystickResponseCurve(this: Vehicle);
LABEL_24:
  *joyForwardMove = (float)(ResponseCurve(
                              curve: v14,
                              x: forward,
                              axis: 0,
                              sensitivity: joy_forwardsensitivity.m_pParent->m_Value.m_fValue)
                          * cl_forwardspeed.m_pParent->m_Value.m_fValue)
                  + *joyForwardMove;
  *joySideMove = (float)(ResponseCurve(
                           curve: v14,
                           x: side,
                           axis: 1,
                           sensitivity: joy_sidesensitivity.m_pParent->m_Value.m_fValue)
                       * cl_sidespeed.m_pParent->m_Value.m_fValue)
               + *joySideMove;
}
