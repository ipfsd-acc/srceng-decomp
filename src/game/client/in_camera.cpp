// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/in_camera.cpp
// Functions: 42
// ============================================================

#include "game\client\in_camera.h"

//------------------------------------------------------------------------------
// Address: 0x101114D0
// Name: void Cmd_CAM_ToThirdPerson(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_CAM_ToThirdPerson()
{
  C_BasePlayer *LocalPlayer; // eax

  input->CAM_ToThirdPerson(this: input);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    LocalPlayer->ThirdPersonSwitch(this: LocalPlayer, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10111500
// Name: void CAM_ToThirdPerson_MayaMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_ToThirdPerson_MayaMode()
{
  byte_106453D4 = byte_106453D4 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10111510
// Name: void Cmd_CAM_ToFirstPerson(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_CAM_ToFirstPerson()
{
  C_BasePlayer *LocalPlayer; // eax
  const char *Default; // eax

  input->CAM_ToFirstPerson(this: input);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    LocalPlayer->ThirdPersonSwitch(this: LocalPlayer, a2: false);
  ConVar::SetValue(this: (ConVar *)&c_thirdpersonshoulder_0.IConVar, value: 0);
  Default = ConVar::GetDefault(this: &cam_idealdist);
  ConVar::SetValue(this: (ConVar *)&cam_idealdist.IConVar, value: Default);
}

//------------------------------------------------------------------------------
// Address: 0x10111560
// Name: void Cmd_CAM_ToThirdPersonShoulder(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_CAM_ToThirdPersonShoulder()
{
  input->CAM_ToThirdPersonShoulder(this: input);
}

//------------------------------------------------------------------------------
// Address: 0x10111570
// Name: void Cmd_CAM_ToOrthographic(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_CAM_ToOrthographic()
{
  input->CAM_ToOrthographic(this: input);
}

//------------------------------------------------------------------------------
// Address: 0x10111580
// Name: void CAM_StartMouseMove(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_StartMouseMove()
{
  input->CAM_StartMouseMove(this: input);
}

//------------------------------------------------------------------------------
// Address: 0x10111590
// Name: void CAM_EndMouseMove(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_EndMouseMove()
{
  input->CAM_EndMouseMove(this: input);
}

//------------------------------------------------------------------------------
// Address: 0x101115A0
// Name: void CAM_StartDistance(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_StartDistance()
{
  input->CAM_StartDistance(this: input);
}

//------------------------------------------------------------------------------
// Address: 0x101115B0
// Name: void CAM_EndDistance(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_EndDistance()
{
  input->CAM_EndDistance(this: input);
}

//------------------------------------------------------------------------------
// Address: 0x101115C0
// Name: public: virtual void CInput::CAM_Command(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_Command(CInput *this, int command)
{
  CInput::GetPerUser(this, nSlot: -1)->m_nCamCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x101115E0
// Name: public: virtual void CInput::CAM_ToFirstPerson(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CInput::CAM_ToFirstPerson(CInput *this@<ecx>, int a2@<edi>)
{
  const CInput::PerUserInput_t *PerUser; // eax
  const CInput::PerUserInput_t *v3; // esi

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  v3 = PerUser;
  if ( PerUser->m_fCameraInThirdPerson )
  {
    PerUser->m_fCameraInThirdPerson = false;
    C_BaseEntity::UpdateVisibilityAllEntities(a1: a2);
  }
  v3->m_nCamCommand = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10111610
// Name: public: virtual bool CInput::CAM_IsOrthographic(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInput::CAM_IsOrthographic(CInput *this)
{
  return CInput::GetPerUser(this, nSlot: -1)->m_CameraIsOrthographic;
}

//------------------------------------------------------------------------------
// Address: 0x10111620
// Name: public: virtual void CInput::CAM_ToOrthographic(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CInput::CAM_ToOrthographic(CInput *this@<ecx>, int a2@<edi>)
{
  const CInput::PerUserInput_t *PerUser; // eax
  const CInput::PerUserInput_t *v3; // esi

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  v3 = PerUser;
  if ( PerUser->m_fCameraInThirdPerson )
  {
    PerUser->m_fCameraInThirdPerson = false;
    C_BaseEntity::UpdateVisibilityAllEntities(a1: a2);
  }
  v3->m_nCamCommand = 0;
  v3->m_CameraIsOrthographic = true;
}

//------------------------------------------------------------------------------
// Address: 0x10111650
// Name: public: virtual void CInput::CAM_StartMouseMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_StartMouseMove(CInput *this)
{
  const CInput::PerUserInput_t *PerUser; // esi
  int v3; // eax
  CHud *Hud; // eax
  double Sensitivity; // st7
  int v6; // edx
  int m_nCameraY; // ecx
  int cpy; // [esp+8h] [ebp-8h] BYREF
  int cpx; // [esp+Ch] [ebp-4h] BYREF

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  if ( PerUser->m_fCameraInThirdPerson )
  {
    if ( !PerUser->m_fCameraMovingWithMouse )
    {
      PerUser->m_fCameraMovingWithMouse = true;
      PerUser->m_fCameraInterceptingMouse = true;
      CInput::GetMousePos(this, ox: &cpx, oy: &cpy);
      v3 = cpy;
      PerUser->m_nCameraX = cpx;
      PerUser->m_nCameraY = v3;
      Hud = GetHud(nSlot: -1);
      Sensitivity = CHud::GetSensitivity(this: Hud);
      *(float *)&cpy = Sensitivity;
      if ( Sensitivity == 0.0 )
      {
        m_nCameraY = PerUser->m_nCameraY;
        PerUser->m_nCameraOldX = PerUser->m_nCameraX;
        PerUser->m_nCameraOldY = m_nCameraY;
      }
      else
      {
        v6 = (int)(float)((float)PerUser->m_nCameraY * *(float *)&cpy);
        PerUser->m_nCameraOldX = (int)(float)((float)PerUser->m_nCameraX * *(float *)&cpy);
        PerUser->m_nCameraOldY = v6;
      }
    }
  }
  else
  {
    PerUser->m_fCameraMovingWithMouse = false;
    PerUser->m_fCameraInterceptingMouse = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111730
// Name: public: virtual void CInput::CAM_EndMouseMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_EndMouseMove(CInput *this)
{
  const CInput::PerUserInput_t *PerUser; // eax

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  PerUser->m_fCameraMovingWithMouse = false;
  PerUser->m_fCameraInterceptingMouse = false;
}

//------------------------------------------------------------------------------
// Address: 0x10111740
// Name: public: virtual void CInput::CAM_StartDistance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_StartDistance(CInput *this)
{
  const CInput::PerUserInput_t *PerUser; // esi
  int v3; // eax
  CHud *Hud; // eax
  CHud *v5; // eax
  int cpy; // [esp+8h] [ebp-8h] BYREF
  int cpx; // [esp+Ch] [ebp-4h] BYREF

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  if ( PerUser->m_fCameraInThirdPerson )
  {
    if ( !PerUser->m_fCameraDistanceMove )
    {
      PerUser->m_fCameraDistanceMove = true;
      PerUser->m_fCameraMovingWithMouse = true;
      PerUser->m_fCameraInterceptingMouse = true;
      CInput::GetMousePos(this, ox: &cpx, oy: &cpy);
      v3 = cpy;
      PerUser->m_nCameraX = cpx;
      PerUser->m_nCameraY = v3;
      Hud = GetHud(nSlot: -1);
      PerUser->m_nCameraOldX = (int)(CHud::GetSensitivity(this: Hud) * (double)PerUser->m_nCameraX);
      v5 = GetHud(nSlot: -1);
      PerUser->m_nCameraOldY = (int)(CHud::GetSensitivity(this: v5) * (double)PerUser->m_nCameraY);
    }
  }
  else
  {
    PerUser->m_fCameraDistanceMove = false;
    PerUser->m_fCameraMovingWithMouse = false;
    PerUser->m_fCameraInterceptingMouse = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101117F0
// Name: public: virtual void CInput::CAM_EndDistance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_EndDistance(CInput *this)
{
  const CInput::PerUserInput_t *PerUser; // eax

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  PerUser->m_fCameraDistanceMove = false;
  PerUser->m_fCameraMovingWithMouse = false;
  PerUser->m_fCameraInterceptingMouse = false;
}

//------------------------------------------------------------------------------
// Address: 0x10111810
// Name: public: virtual int CInput::CAM_IsThirdPerson(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CInput::CAM_IsThirdPerson(CInput *this, int nSlot)
{
  if ( nSlot == -1 )
    return CInput::GetPerUser(this, nSlot: -1)->m_fCameraInThirdPerson;
  else
    return this->m_PerUser[nSlot].m_fCameraInThirdPerson;
}

//------------------------------------------------------------------------------
// Address: 0x10111840
// Name: public: virtual int CInput::CAM_InterceptingMouse(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CInput::CAM_InterceptingMouse(CInput *this)
{
  return CInput::GetPerUser(this, nSlot: -1)->m_fCameraInterceptingMouse;
}

//------------------------------------------------------------------------------
// Address: 0x10111850
// Name: protected: virtual void CInput::Init_Camera(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::Init_Camera(CInput *this)
{
  this->m_PerUser[0].m_CameraIsOrthographic = false;
}

//------------------------------------------------------------------------------
// Address: 0x10111860
// Name: cam_command
// Source: json
//------------------------------------------------------------------------------
void __cdecl cam_command(const CCommand *args)
{
  const char *v1; // eax
  IInput_vtbl *v2; // esi
  int v3; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = prType;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = input->__vftable;
    v3 = V_atoi(str: v1);
    v2->CAM_Command(this: input, a2: v3);
  }
  else
  {
    _Msg(a1: "cam_command <0, 1, or 2>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101118C0
// Name: void CAM_ToggleSnapto(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_ToggleSnapto()
{
  if ( cam_snapto.m_pParent != nullptr )
    ConVar::SetValue(this: (ConVar *)&cam_snapto.IConVar, value: cam_snapto.m_pParent->m_Value.m_nValue == 0);
  else
    ConVar::SetValue(this: (ConVar *)&cam_snapto.IConVar, value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10111900
// Name: float MoveToward(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl MoveToward(float cur, float goal, float lag)
{
  float v3; // xmm0_4

  v3 = cur;
  if ( cur != goal )
  {
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(cur - goal) & _mask__AbsFloat_) > 180.0 )
    {
      if ( goal <= cur )
        v3 = cur - 360.0;
      else
        v3 = cur + 360.0;
    }
    if ( goal <= v3 )
    {
      if ( v3 > (float)(goal + 1.0) )
      {
        v3 = v3 - (float)((float)(v3 - goal) / lag);
        goto LABEL_12;
      }
    }
    else if ( (float)(goal - 1.0) > v3 )
    {
      v3 = v3 + (float)((float)(goal - v3) / lag);
LABEL_12:
      cur = v3;
      goto LABEL_13;
    }
    v3 = goal;
    goto LABEL_12;
  }
LABEL_13:
  if ( v3 < 0.0 )
    return (float)(v3 + 360.0);
  if ( v3 >= 360.0 )
    return (float)(v3 - 360.0);
  return cur;
}

//------------------------------------------------------------------------------
// Address: 0x101119C0
// Name: public: virtual void CInput::CAM_SetCameraThirdData(struct CameraThirdData_t __near *,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_SetCameraThirdData(CInput *this, CameraThirdData_t *pCameraData, Vector *vecCameraOffset)
{
  const CInput::PerUserInput_t *PerUser; // eax

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  PerUser->m_pCameraThirdData = pCameraData;
  PerUser->m_vecCameraOffset = *vecCameraOffset;
}

//------------------------------------------------------------------------------
// Address: 0x101119F0
// Name: void CAM_PitchUpDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_PitchUpDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &cam_pitchup, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &cam_pitchup, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111A30
// Name: void CAM_PitchUpUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_PitchUpUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &cam_pitchup, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &cam_pitchup, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111A70
// Name: void CAM_PitchDownDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_PitchDownDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &cam_pitchdown, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &cam_pitchdown, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111AB0
// Name: void CAM_PitchDownUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_PitchDownUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &cam_pitchdown, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &cam_pitchdown, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111AF0
// Name: void CAM_YawLeftDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_YawLeftDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &cam_yawleft, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &cam_yawleft, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111B30
// Name: void CAM_YawLeftUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_YawLeftUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &cam_yawleft, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &cam_yawleft, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111B70
// Name: void CAM_YawRightDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_YawRightDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &cam_yawright, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &cam_yawright, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111BB0
// Name: void CAM_YawRightUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_YawRightUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &cam_yawright, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &cam_yawright, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111BF0
// Name: void CAM_InDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_InDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &cam_in, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &cam_in, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111C30
// Name: void CAM_InUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_InUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &cam_in, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &cam_in, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111C70
// Name: void CAM_OutDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_OutDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &cam_out, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &cam_out, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111CB0
// Name: void CAM_OutUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAM_OutUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &cam_out, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &cam_out, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10111CF0
// Name: public: virtual void CInput::CAM_ToThirdPerson(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CInput::CAM_ToThirdPerson(CInput *this@<ecx>, int a2@<edi>)
{
  const CInput::PerUserInput_t *PerUser; // esi
  QAngle viewangles; // [esp+4h] [ebp-Ch] BYREF

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  engine->GetViewAngles(this: engine, a2: &viewangles);
  if ( !PerUser->m_fCameraInThirdPerson )
  {
    PerUser->m_fCameraInThirdPerson = true;
    PerUser->m_vecCameraOffset.y = viewangles.y;
    PerUser->m_vecCameraOffset.x = viewangles.x;
    PerUser->m_vecCameraOffset.z = 30.0;
    C_BaseEntity::UpdateVisibilityAllEntities(a1: a2);
  }
  PerUser->m_nCamCommand = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10111D50
// Name: public: virtual void CInput::CAM_OrthographicSize(float __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_OrthographicSize(CInput *this, float *w, float *h)
{
  *w = c_orthowidth.m_pParent->m_Value.m_fValue;
  *h = c_orthoheight.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x10111D80
// Name: public: virtual void CInput::CAM_GetCameraOffset(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_GetCameraOffset(CInput *this, Vector *ofs)
{
  *ofs = CInput::GetPerUser(this, nSlot: -1)->m_vecCameraOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10111DB0
// Name: public: virtual void CInput::CAM_ToThirdPersonShoulder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_ToThirdPersonShoulder(CInput *this)
{
  const CInput::PerUserInput_t *PerUser; // eax
  const char *value; // eax

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  if ( c_thirdpersonshoulder_0.m_pParent != nullptr && c_thirdpersonshoulder_0.m_pParent->m_Value.m_nValue != 0 )
  {
    PerUser->m_nCamCommand = 2;
    ConVar::SetValue(this: (ConVar *)&c_thirdpersonshoulder_0.IConVar, value: 0);
    value = ConVar::GetDefault(this: &cam_idealdist);
    ConVar::SetValue(this: (ConVar *)&cam_idealdist.IConVar, value);
  }
  else
  {
    PerUser->m_nCamCommand = 1;
    ConVar::SetValue(this: (ConVar *)&c_thirdpersonshoulder_0.IConVar, value: 1);
    ConVar::SetValue(
      this: (ConVar *)&cam_idealdist.IConVar,
      value: c_thirdpersonshoulderdist.m_pParent->m_Value.m_fValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111E30
// Name: public: virtual void CInput::CAM_Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_Think(CInput *this)
{
  const CInput::PerUserInput_t *PerUser; // eax
  int v3; // esi
  int v4; // eax
  ConVar *v5; // eax
  bool v6; // al
  int v7; // ecx
  int v8; // ecx
  float m_fValue; // xmm1_4
  float v10; // xmm0_4
  bool v11; // cc
  float v12; // xmm0_4
  int v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm0_4
  bool v16; // cc
  float v17; // xmm0_4
  CHud *Hud; // eax
  double Sensitivity; // st7
  float v20; // xmm1_4
  int v21; // ecx
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  int v25; // ecx
  float v26; // xmm0_4
  float v27; // xmm1_4
  bool v28; // cc
  float v29; // xmm1_4
  CHud *v30; // eax
  CHud *v31; // eax
  float value; // xmm0_4
  int y_low; // xmm1_4
  float v34; // xmm1_4
  float z; // xmm5_4
  float v36; // xmm4_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  C_BasePlayer *v40; // edi
  const Vector *LocalOrigin; // eax
  float v42; // edx
  __int64 v43; // xmm0_8
  IHandleEntity v44; // eax
  const CBaseHandle *(__thiscall *GetRefEHandle)(IHandleEntity *); // edx
  float *v46; // eax
  float angle; // [esp+4Ch] [ebp-D0h]
  float angle_4; // [esp+50h] [ebp-CCh]
  CGameTrace trace; // [esp+64h] [ebp-B8h] BYREF
  CTraceFilterSimple traceFilter; // [esp+B8h] [ebp-64h] BYREF
  Vector camForward; // [esp+C8h] [ebp-54h] BYREF
  int x; // [esp+D4h] [ebp-48h] BYREF
  C_BasePlayer *localPlayer; // [esp+D8h] [ebp-44h]
  QAngle angles; // [esp+DCh] [ebp-40h] BYREF
  int y; // [esp+E8h] [ebp-34h] BYREF
  int flSensitivity; // [esp+ECh] [ebp-30h] BYREF
  QAngle viewangles; // [esp+F0h] [ebp-2Ch] BYREF
  Vector origin; // [esp+FCh] [ebp-20h] BYREF
  int cpy; // [esp+108h] [ebp-14h] BYREF
  float lag; // [esp+10Ch] [ebp-10h] BYREF
  Vector camOffset; // [esp+110h] [ebp-Ch]
  int savedregs; // [esp+11Ch] [ebp+0h] BYREF

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  v3 = (int)PerUser;
  if ( PerUser->m_pCameraThirdData != nullptr )
  {
    this->CAM_CameraThirdThink(this);
    return;
  }
  v4 = PerUser->m_nCamCommand - 1;
  if ( v4 != 0 )
  {
    if ( v4 == 1 )
      this->CAM_ToFirstPerson(this);
  }
  else
  {
    this->CAM_ToThirdPerson(this);
  }
  if ( *(_BYTE *)(v3 + 109) != 0 )
  {
    v5 = (ConVar *)sv_cheats;
    if ( sv_cheats != nullptr || (v5 = cvar->FindVar_2(this: cvar, a2: "sv_cheats"), sv_cheats = v5, v5 != nullptr) )
    {
      if ( (v5->m_pParent == nullptr || v5->m_pParent->m_Value.m_nValue == 0)
        && (c_thirdpersonshoulder_0.m_pParent == nullptr || c_thirdpersonshoulder_0.m_pParent->m_Value.m_nValue == 0) )
      {
        this->CAM_ToFirstPerson(this);
        return;
      }
    }
    localPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( byte_106453D4 != 0 )
    {
      v6 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
        || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT);
      *(_BYTE *)(v3 + 110) = v6;
      *(_BYTE *)(v3 + 108) = v6;
      if ( !v6 )
        return;
      *(_QWORD *)cam_pitchup.m_PerUser[0].down = 0;
      *(_QWORD *)cam_pitchdown.m_PerUser[0].down = 0;
      *(_QWORD *)cam_yawleft.m_PerUser[0].down = 0;
      *(_QWORD *)cam_yawright.m_PerUser[0].down = 0;
      *(_QWORD *)cam_in.m_PerUser[0].down = 0;
      cam_pitchup.m_PerUser[0].state = 0;
      cam_pitchdown.m_PerUser[0].state = 0;
      cam_yawleft.m_PerUser[0].state = 0;
      cam_yawright.m_PerUser[0].state = 0;
      cam_in.m_PerUser[0].state = 0;
      *(_QWORD *)cam_out.m_PerUser[0].down = 0;
      cam_out.m_PerUser[0].state = 0;
      if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT)
        || !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: MOUSE_MIDDLE) )
      {
        if ( g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
        {
          *(_BYTE *)(v3 + 124) = 0;
          goto LABEL_28;
        }
        if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: MOUSE_RIGHT) )
        {
          this->ResetMouse(this);
          return;
        }
      }
      *(_BYTE *)(v3 + 124) = 1;
    }
LABEL_28:
    camOffset.x = cam_idealpitch.m_pParent->m_Value.m_fValue;
    camOffset.y = cam_idealyaw.m_pParent->m_Value.m_fValue;
    camOffset.z = cam_idealdist.m_pParent->m_Value.m_fValue;
    if ( *(_BYTE *)(v3 + 110) == 0 )
      goto LABEL_54;
    CInput::GetMousePos(this, ox: (int *)&lag, oy: &cpy);
    v7 = cpy;
    *(float *)(v3 + 136) = lag;
    *(_DWORD *)(v3 + 140) = v7;
    if ( *(_BYTE *)(v3 + 124) != 0 )
      goto LABEL_54;
    this->GetWindowCenter(this, a2: &x, a3: &y);
    v8 = *(_DWORD *)(v3 + 136);
    if ( v8 <= x )
    {
      if ( v8 >= x )
        goto LABEL_40;
      m_fValue = c_minyaw.m_pParent->m_Value.m_fValue;
      v12 = camOffset.y;
      if ( camOffset.y > m_fValue )
      {
        v12 = camOffset.y - (double)((x - v8) / 2) * 0.5;
        camOffset.y = v12;
      }
      v11 = m_fValue <= v12;
    }
    else
    {
      m_fValue = c_maxyaw.m_pParent->m_Value.m_fValue;
      v10 = camOffset.y;
      if ( m_fValue > camOffset.y )
      {
        v10 = (double)((v8 - x) / 2) * 0.5 + camOffset.y;
        camOffset.y = v10;
      }
      v11 = v10 <= m_fValue;
    }
    if ( !v11 )
      camOffset.y = m_fValue;
LABEL_40:
    v13 = *(_DWORD *)(v3 + 140);
    if ( v13 <= y )
    {
      if ( v13 >= y )
      {
LABEL_50:
        Hud = GetHud(nSlot: -1);
        Sensitivity = CHud::GetSensitivity(this: Hud);
        *(float *)&flSensitivity = Sensitivity;
        if ( Sensitivity == 0.0 )
        {
          v21 = *(_DWORD *)(v3 + 140);
          *(_DWORD *)(v3 + 128) = *(_DWORD *)(v3 + 136);
          *(_DWORD *)(v3 + 132) = v21;
        }
        else
        {
          v20 = (float)*(int *)(v3 + 140) * *(float *)&flSensitivity;
          *(_DWORD *)(v3 + 128) = (int)(float)((float)*(int *)(v3 + 136) * *(float *)&flSensitivity);
          *(_DWORD *)(v3 + 132) = (int)v20;
        }
        this->ResetMouse(this);
LABEL_54:
        if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &cam_pitchup) == 0.0 )
        {
          if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &cam_pitchdown) == 0.0 )
            goto LABEL_59;
          v22 = camOffset.x - cam_idealdelta.m_pParent->m_Value.m_fValue;
        }
        else
        {
          v22 = cam_idealdelta.m_pParent->m_Value.m_fValue + camOffset.x;
        }
        camOffset.x = v22;
LABEL_59:
        if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &cam_yawleft) == 0.0 )
        {
          if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &cam_yawright) == 0.0 )
            goto LABEL_64;
          v23 = cam_idealdelta.m_pParent->m_Value.m_fValue + camOffset.y;
        }
        else
        {
          v23 = camOffset.y - cam_idealdelta.m_pParent->m_Value.m_fValue;
        }
        camOffset.y = v23;
LABEL_64:
        if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &cam_in) == 0.0 )
        {
          if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &cam_out) == 0.0 )
            goto LABEL_70;
          v24 = (float)(cam_idealdelta.m_pParent->m_Value.m_fValue * 2.0) + camOffset.z;
        }
        else
        {
          camOffset.z = camOffset.z - (float)(cam_idealdelta.m_pParent->m_Value.m_fValue * 2.0);
          if ( camOffset.z >= 30.0 )
            goto LABEL_70;
          v24 = 30.0;
          camOffset.x = 0.0;
          camOffset.y = 0.0;
        }
        camOffset.z = v24;
LABEL_70:
        if ( *(_BYTE *)(v3 + 124) == 0 )
        {
LABEL_82:
          engine->GetViewAngles(this: engine, a2: &viewangles);
          if ( (_S5_101 & 1) == 0 )
          {
            _S5_101 |= 1u;
            s_oldAngles = viewangles;
          }
          if ( byte_106453D4 == 0
            || viewangles.x == s_oldAngles.x && viewangles.y == s_oldAngles.y && viewangles.z == s_oldAngles.z )
          {
            value = camOffset.x;
            y_low = SLODWORD(camOffset.y);
          }
          else
          {
            value = (float)(s_oldAngles.x - viewangles.x) + camOffset.x;
            *(float *)&y_low = (float)(s_oldAngles.y - viewangles.y) + camOffset.y;
            s_oldAngles = viewangles;
          }
          if ( value <= 180.0 )
          {
            if ( value < -180.0 )
              value = value + 360.0;
          }
          else
          {
            value = value - 360.0;
          }
          if ( *(float *)&y_low < 180.0 )
          {
            if ( *(float *)&y_low <= -180.0 )
              *(float *)&y_low = *(float *)&y_low + 360.0;
          }
          else
          {
            *(float *)&y_low = *(float *)&y_low - 360.0;
          }
          if ( c_minpitch.m_pParent->m_Value.m_fValue <= value )
          {
            if ( value > c_maxpitch.m_pParent->m_Value.m_fValue )
              value = c_maxpitch.m_pParent->m_Value.m_fValue;
          }
          else
          {
            value = c_minpitch.m_pParent->m_Value.m_fValue;
          }
          if ( c_minyaw.m_pParent->m_Value.m_fValue <= *(float *)&y_low )
          {
            if ( *(float *)&y_low <= c_maxyaw.m_pParent->m_Value.m_fValue )
              cpy = y_low;
            else
              cpy = LODWORD(c_maxyaw.m_pParent->m_Value.m_fValue);
          }
          else
          {
            cpy = LODWORD(c_minyaw.m_pParent->m_Value.m_fValue);
          }
          if ( c_mindistance.m_pParent->m_Value.m_fValue <= camOffset.z )
          {
            if ( camOffset.z <= c_maxdistance.m_pParent->m_Value.m_fValue )
              lag = camOffset.z;
            else
              lag = c_maxdistance.m_pParent->m_Value.m_fValue;
          }
          else
          {
            lag = c_mindistance.m_pParent->m_Value.m_fValue;
          }
          ConVar::SetValue(this: (ConVar *)&cam_idealpitch.IConVar, value);
          ConVar::SetValue(this: (ConVar *)&cam_idealyaw.IConVar, value: *(float *)&cpy);
          ConVar::SetValue(this: (ConVar *)&cam_idealdist.IConVar, value: lag);
          v34 = *(float *)(v3 + 116);
          z = *(float *)(v3 + 120);
          v36 = 1.0;
          camOffset.x = *(float *)(v3 + 112);
          camOffset.y = v34;
          camOffset.z = z;
          if ( cam_snapto.m_pParent != nullptr && cam_snapto.m_pParent->m_Value.m_nValue != 0 )
          {
            camOffset.y = cam_idealyaw.m_pParent->m_Value.m_fValue + viewangles.y;
            camOffset.x = cam_idealpitch.m_pParent->m_Value.m_fValue + viewangles.x;
            v37 = cam_idealdist.m_pParent->m_Value.m_fValue;
          }
          else
          {
            if ( (float)(cam_ideallag.m_pParent->m_Value.m_fValue + 1.0) >= 1.0 )
              v36 = cam_ideallag.m_pParent->m_Value.m_fValue + 1.0;
            v38 = cam_idealyaw.m_pParent->m_Value.m_fValue;
            lag = v36;
            if ( (float)(v34 - viewangles.y) != v38 )
            {
              angle_4 = AngleNormalizePositive(angle: viewangles.y + v38);
              angle = AngleNormalizePositive(angle: camOffset.y);
              camOffset.y = MoveToward(cur: angle, goal: angle_4, lag: v36);
              z = camOffset.z;
              v36 = lag;
            }
            v39 = cam_idealpitch.m_pParent->m_Value.m_fValue;
            if ( (float)(camOffset.x - viewangles.x) != v39 )
              camOffset.x = MoveToward(cur: camOffset.x, goal: viewangles.x + v39, lag: v36);
            v37 = cam_idealdist.m_pParent->m_Value.m_fValue;
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(z - v37) & _mask__AbsFloat_) >= 2.0 )
              v37 = (float)((float)(v37 - z) / v36) + z;
          }
          camOffset.z = v37;
          if ( cam_collision.m_pParent != nullptr && cam_collision.m_pParent->m_Value.m_nValue != 0 )
          {
            v40 = localPlayer;
            if ( localPlayer != nullptr )
            {
              LocalOrigin = C_BaseEntity::GetLocalOrigin(this: localPlayer);
              v42 = LocalOrigin->z;
              v43 = *(_QWORD *)&LocalOrigin->x;
              v44.__vftable = (IHandleEntity_vtbl *)v40->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
              origin.z = v42;
              GetRefEHandle = v44.__vftable[53].GetRefEHandle;
              *(_QWORD *)&origin.x = v43;
              v46 = (float *)GetRefEHandle(this: v40);
              origin.x = *v46 + origin.x;
              origin.y = v46[1] + origin.y;
              origin.z = v46[2] + origin.z;
              angles.x = camOffset.x;
              angles.y = camOffset.y;
              angles.z = 0.0;
              AngleVectors(&angles, forward: &camForward, right: nullptr, up: nullptr);
              CTraceFilterSimple::CTraceFilterSimple(
                this: &traceFilter,
                passedict: v40,
                collisionGroup: 0,
                pExtraShouldHitFunc: nullptr);
              angles.y = origin.y - (float)(camForward.y * camOffset.z);
              angles.x = origin.x - (float)(camOffset.z * camForward.x);
              angles.z = origin.z - (float)(camForward.z * camOffset.z);
              UTIL_TraceHull(
                a1: (int)&savedregs,
                a2: v3,
                vecAbsStart: &origin,
                vecAbsEnd: (const Vector *)&angles,
                hullMin: &CAM_HULL_MIN,
                hullMax: &CAM_HULL_MAX,
                mask: 0x200400Bu,
                pFilter: &traceFilter,
                ptr: &trace);
              if ( trace.fraction < 1.0 )
                camOffset.z = camOffset.z * trace.fraction;
            }
          }
          if ( cam_showangles.m_pParent != nullptr && cam_showangles.m_pParent->m_Value.m_nValue != 0 )
          {
            engine->Con_NPrintf(
              this: engine,
              a2: 4,
              a3: "Pitch: %6.1f   Yaw: %6.1f %38s",
              viewangles.x,
              viewangles.y,
              "view angles");
            engine->Con_NPrintf(
              this: engine,
              a2: 6,
              a3: "Pitch: %6.1f   Yaw: %6.1f   Dist: %6.1f %19s",
              cam_idealpitch.m_pParent->m_Value.m_fValue,
              cam_idealyaw.m_pParent->m_Value.m_fValue,
              cam_idealdist.m_pParent->m_Value.m_fValue,
              "ideal angles");
            engine->Con_NPrintf(
              this: engine,
              a2: 8,
              a3: "Pitch: %6.1f   Yaw: %6.1f   Dist: %6.1f %16s",
              *(float *)(v3 + 112),
              *(float *)(v3 + 116),
              *(float *)(v3 + 120),
              "camera offset");
          }
          *(Vector *)(v3 + 112) = camOffset;
          return;
        }
        this->GetWindowCenter(this, a2: &y, a3: &flSensitivity);
        v25 = *(_DWORD *)(v3 + 140);
        if ( v25 <= flSensitivity )
        {
          if ( v25 >= flSensitivity )
          {
LABEL_81:
            v30 = GetHud(nSlot: -1);
            *(_DWORD *)(v3 + 128) = (int)(CHud::GetSensitivity(this: v30) * (double)*(int *)(v3 + 136));
            v31 = GetHud(nSlot: -1);
            *(_DWORD *)(v3 + 132) = (int)(CHud::GetSensitivity(this: v31) * (double)*(int *)(v3 + 140));
            this->ResetMouse(this);
            goto LABEL_82;
          }
          v26 = c_mindistance.m_pParent->m_Value.m_fValue;
          v29 = camOffset.z;
          if ( camOffset.z > v26 )
          {
            v29 = camOffset.z - (float)((float)((flSensitivity - v25) / 2) * cam_idealdelta.m_pParent->m_Value.m_fValue);
            camOffset.z = v29;
          }
          v28 = v26 <= v29;
        }
        else
        {
          v26 = c_maxdistance.m_pParent->m_Value.m_fValue;
          v27 = camOffset.z;
          if ( v26 > camOffset.z )
          {
            v27 = (float)((float)((*(_DWORD *)(v3 + 140) - flSensitivity) / 2)
                        * cam_idealdelta.m_pParent->m_Value.m_fValue)
                + camOffset.z;
            camOffset.z = v27;
          }
          v28 = v27 <= v26;
        }
        if ( !v28 )
          camOffset.z = v26;
        goto LABEL_81;
      }
      v14 = c_minpitch.m_pParent->m_Value.m_fValue;
      v17 = camOffset.x;
      if ( camOffset.x > v14 )
      {
        v17 = camOffset.x - (double)((y - v13) / 2) * 0.5;
        camOffset.x = v17;
      }
      v16 = v14 <= v17;
    }
    else
    {
      v14 = c_maxpitch.m_pParent->m_Value.m_fValue;
      v15 = camOffset.x;
      if ( v14 > camOffset.x )
      {
        v15 = (double)((v13 - y) / 2) * 0.5 + camOffset.x;
        camOffset.x = v15;
      }
      v16 = v15 <= v14;
    }
    if ( !v16 )
      camOffset.x = v14;
    goto LABEL_50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112A20
// Name: public: virtual void CInput::CAM_CameraThirdThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CAM_CameraThirdThink(CInput *this)
{
  const CInput::PerUserInput_t *PerUser; // esi
  CameraThirdData_t *m_pCameraThirdData; // eax
  float *p_m_flPitch; // ecx
  float lag; // xmm4_4
  float cur; // xmm1_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  C_BasePlayer *LocalPlayer; // eax
  const IHandleEntity *v12; // edi
  CameraThirdData_t *v13; // eax
  float v14; // xmm5_4
  float x; // xmm1_4
  float v16; // xmm0_4
  CGameTrace trace; // [esp+14h] [ebp-A4h] BYREF
  CTraceFilterSkipTwoEntities filter; // [esp+68h] [ebp-50h] BYREF
  QAngle angView; // [esp+7Ch] [ebp-3Ch] BYREF
  Vector vecForward; // [esp+88h] [ebp-30h] BYREF
  Vector vecOrigin; // [esp+94h] [ebp-24h] BYREF
  QAngle angles; // [esp+A0h] [ebp-18h] BYREF
  Vector vecCamOffset; // [esp+ACh] [ebp-Ch]
  int savedregs; // [esp+B8h] [ebp+0h] BYREF

  PerUser = CInput::GetPerUser(this, nSlot: -1);
  m_pCameraThirdData = PerUser->m_pCameraThirdData;
  if ( m_pCameraThirdData != nullptr && PerUser->m_fCameraInThirdPerson && m_pCameraThirdData->m_flLag != -1.0 )
  {
    engine->GetViewAngles(this: engine, a2: &angView);
    p_m_flPitch = &PerUser->m_pCameraThirdData->m_flPitch;
    lag = 1.0;
    cur = PerUser->m_vecCameraOffset.x;
    y = PerUser->m_vecCameraOffset.y;
    z = PerUser->m_vecCameraOffset.z;
    v8 = p_m_flPitch[3] + 1.0;
    vecCamOffset.x = cur;
    vecCamOffset.y = y;
    if ( v8 >= 1.0 )
      lag = v8;
    if ( (float)(cur - angView.x) != *p_m_flPitch )
      vecCamOffset.x = MoveToward(cur, goal: *p_m_flPitch + angView.x, lag);
    v9 = p_m_flPitch[1];
    if ( (float)(y - angView.y) != v9 )
      vecCamOffset.y = MoveToward(cur: y, goal: v9 + angView.y, lag);
    v10 = p_m_flPitch[2];
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(z - v10) & _mask__AbsFloat_) >= 2.0 )
      v10 = (float)((float)(v10 - z) / lag) + z;
    vecCamOffset.z = v10;
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    v12 = LocalPlayer;
    if ( LocalPlayer == nullptr )
      goto LABEL_15;
    LocalPlayer->GetThirdPersonViewPosition(this: LocalPlayer, result: &vecOrigin);
    angles.x = vecCamOffset.x;
    angles.y = vecCamOffset.y;
    angles.z = 0.0;
    AngleVectors(&angles, forward: &vecForward, right: nullptr, up: nullptr);
    CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
      this: &filter,
      passentity: v12,
      passentity2: nullptr,
      collisionGroup: 0);
    v13 = PerUser->m_pCameraThirdData;
    angles.y = vecOrigin.y - (float)(vecForward.y * vecCamOffset.z);
    angles.x = vecOrigin.x - (float)(vecForward.x * vecCamOffset.z);
    angles.z = vecOrigin.z - (float)(vecForward.z * vecCamOffset.z);
    UTIL_TraceHull(
      a1: (int)&savedregs,
      a2: (int)PerUser,
      vecAbsStart: &vecOrigin,
      vecAbsEnd: (const Vector *)&angles,
      hullMin: &v13->m_vecHullMin,
      hullMax: &v13->m_vecHullMax,
      mask: 0x200400Bu,
      pFilter: &filter,
      ptr: &trace);
    if ( trace.fraction < 1.0 )
      v14 = vecCamOffset.z * trace.fraction;
    else
LABEL_15:
      v14 = vecCamOffset.z;
    x = vecCamOffset.x;
    if ( vecCamOffset.x < 180.0 )
    {
      if ( vecCamOffset.x <= -180.0 )
        x = vecCamOffset.x + 360.0;
    }
    else
    {
      x = vecCamOffset.x - 360.0;
    }
    v16 = vecCamOffset.y;
    if ( vecCamOffset.y < 180.0 )
    {
      if ( vecCamOffset.y <= -180.0 )
        v16 = vecCamOffset.y + 360.0;
      PerUser->m_vecCameraOffset.x = x;
      PerUser->m_vecCameraOffset.y = v16;
      PerUser->m_vecCameraOffset.z = v14;
    }
    else
    {
      PerUser->m_vecCameraOffset.x = x;
      PerUser->m_vecCameraOffset.y = v16 - 360.0;
      PerUser->m_vecCameraOffset.z = v14;
    }
  }
}
