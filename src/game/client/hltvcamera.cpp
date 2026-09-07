// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hltvcamera.cpp
// Functions: 23
// ============================================================

#include "game\client\hltvcamera.h"

//------------------------------------------------------------------------------
// Address: 0x100EC6E0
// Name: class C_HLTVCamera __near * HLTVCamera(void)
// Source: json
//------------------------------------------------------------------------------
C_HLTVCamera *__cdecl HLTVCamera()
{
  return &s_HLTVCamera;
}

//------------------------------------------------------------------------------
// Address: 0x100EC6F0
// Name: public: int C_HLTVCamera::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_HLTVCamera::GetMode(C_HLTVCamera *this)
{
  C_BasePlayer *v2; // eax

  if ( this->m_iCameraMan > 0 && (v2 = UTIL_PlayerByIndex(entindex: this->m_iCameraMan)) != nullptr )
    return v2->GetObserverMode(this: v2);
  else
    return this->m_nCameraMode;
}

//------------------------------------------------------------------------------
// Address: 0x100EC720
// Name: public: void C_HLTVCamera::PostEntityPacketReceived(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::PostEntityPacketReceived(C_HLTVCamera *this)
{
  this->m_bEntityPacketReceived = true;
}

//------------------------------------------------------------------------------
// Address: 0x100EC730
// Name: public: void C_HLTVCamera::SetMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::SetMode(C_HLTVCamera *this, int iMode)
{
  int m_nCameraMode; // ebx
  IGameEvent *v4; // esi

  m_nCameraMode = this->m_nCameraMode;
  if ( m_nCameraMode != iMode )
  {
    this->m_nCameraMode = iMode;
    v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hltv_changed_mode", a3: 0, a4: 0);
    if ( v4 != nullptr )
    {
      v4->SetInt(this: v4, a2: "oldmode", a3: m_nCameraMode);
      v4->SetInt(this: v4, a2: "newmode", a3: this->m_nCameraMode);
      v4->SetInt(this: v4, a2: "obs_target", a3: this->m_iTraget1);
      gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC7B0
// Name: public: void C_HLTVCamera::SetAutoDirector(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::SetAutoDirector(C_HLTVCamera *this, bool bActive)
{
  ConVar::SetValue(this: (ConVar *)&spec_autodirector.IConVar, value: bActive);
}

//------------------------------------------------------------------------------
// Address: 0x100EC7D0
// Name: public: class CUserCmd __near & CUserCmd::operator=(class CUserCmd const __near &)
// Source: json
//------------------------------------------------------------------------------
CUserCmd *__thiscall CUserCmd::operator=(CUserCmd *this, const CUserCmd *src)
{
  CUserCmd *result; // eax

  result = this;
  if ( this != src )
  {
    this->command_number = src->command_number;
    this->tick_count = src->tick_count;
    this->viewangles = src->viewangles;
    this->forwardmove = src->forwardmove;
    this->sidemove = src->sidemove;
    this->upmove = src->upmove;
    this->buttons = src->buttons;
    this->impulse = src->impulse;
    this->weaponselect = src->weaponselect;
    this->weaponsubtype = src->weaponsubtype;
    this->random_seed = src->random_seed;
    this->mousedx = src->mousedx;
    this->mousedy = src->mousedy;
    this->hasbeenpredicted = src->hasbeenpredicted;
    this->headangles = src->headangles;
    this->headoffset = src->headoffset;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EC870
// Name: public: void C_HLTVCamera::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::Reset(C_HLTVCamera *this)
{
  this->m_flFOV = 90.0;
  this->m_flLastDistance = 96.0;
  this->m_flDistance = 96.0;
  this->m_flInertia = 3.0;
  this->m_nCameraMode = 3;
  *(_QWORD *)&this->m_flTheta = 0;
  this->m_flOffset = 0.0;
  this->m_iCameraMan = 0;
  this->m_iTraget2 = 0;
  this->m_iTraget1 = 0;
  this->m_bEntityPacketReceived = false;
  this->m_vCamOrigin.x = 0.0;
  this->m_vCamOrigin.y = 0.0;
  this->m_vCamOrigin.z = 0.0;
  this->m_aCamAngle.x = 0.0;
  this->m_aCamAngle.y = 0.0;
  this->m_aCamAngle.z = 0.0;
  this->m_LastCmd.command_number = 0;
  this->m_LastCmd.tick_count = 0;
  this->m_LastCmd.viewangles.x = 0.0;
  this->m_LastCmd.viewangles.y = 0.0;
  this->m_LastCmd.viewangles.z = 0.0;
  this->m_LastCmd.forwardmove = 0.0;
  this->m_LastCmd.sidemove = 0.0;
  this->m_LastCmd.upmove = 0.0;
  this->m_LastCmd.buttons = 0;
  this->m_LastCmd.impulse = 0;
  this->m_LastCmd.weaponselect = 0;
  this->m_LastCmd.weaponsubtype = 0;
  this->m_LastCmd.random_seed = 0;
  this->m_LastCmd.hasbeenpredicted = false;
  this->m_LastCmd.mousedx = 0;
  this->m_LastCmd.mousedy = 0;
  this->m_LastCmd.headangles.x = 0.0;
  this->m_LastCmd.headangles.y = 0.0;
  this->m_LastCmd.headangles.z = 0.0;
  this->m_LastCmd.headoffset.x = 0.0;
  this->m_LastCmd.headoffset.y = 0.0;
  this->m_LastCmd.headoffset.z = 0.0;
  this->m_vecVelocity.x = 0.0;
  this->m_vecVelocity.y = 0.0;
  this->m_vecVelocity.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100EC9A0
// Name: public: class C_BaseEntity __near * C_HLTVCamera::GetPrimaryTarget(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_HLTVCamera::GetPrimaryTarget(C_HLTVCamera *this)
{
  C_BasePlayer *v2; // eax
  int m_iTraget1; // esi

  if ( this->m_iCameraMan > 0 )
  {
    v2 = UTIL_PlayerByIndex(entindex: this->m_iCameraMan);
    if ( v2 != nullptr )
      return v2->GetObserverTarget(this: v2);
  }
  m_iTraget1 = this->m_iTraget1;
  if ( m_iTraget1 > 0 )
    return CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: m_iTraget1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100EC9E0
// Name: public: class C_BaseEntity __near * C_HLTVCamera::GetCameraMan(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_HLTVCamera::GetCameraMan(C_HLTVCamera *this)
{
  return CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: this->m_iCameraMan);
}

//------------------------------------------------------------------------------
// Address: 0x100EC9F0
// Name: public: void C_HLTVCamera::CreateMove(class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::CreateMove(C_HLTVCamera *this, CUserCmd *cmd)
{
  if ( cmd != nullptr )
    CUserCmd::operator=(this: &this->m_LastCmd, src: cmd);
}

//------------------------------------------------------------------------------
// Address: 0x100ECA10
// Name: protected: void C_HLTVCamera::SetCameraAngle(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::SetCameraAngle(C_HLTVCamera *this, QAngle *targetAngle)
{
  this->m_aCamAngle = *targetAngle;
  NormalizeAngles(angles: &this->m_aCamAngle);
  this->m_flLastAngleUpdateTime = *(float *)gpGlobals.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x100ECA50
// Name: protected: void C_HLTVCamera::SmoothCameraAngle(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::SmoothCameraAngle(C_HLTVCamera *this, QAngle *targetAngle)
{
  float m_flLastAngleUpdateTime; // xmm1_4
  float frac; // xmm0_4

  m_flLastAngleUpdateTime = this->m_flLastAngleUpdateTime;
  if ( m_flLastAngleUpdateTime <= 0.0 )
  {
    this->m_aCamAngle = *targetAngle;
    this->m_flLastAngleUpdateTime = *(float *)gpGlobals.m_Index;
  }
  else
  {
    frac = (float)(*(float *)gpGlobals.m_Index - m_flLastAngleUpdateTime) * this->m_flInertia;
    if ( frac >= 0.01 )
    {
      if ( frac > 1.0 )
        frac = 1.0;
    }
    else
    {
      frac = 0.0099999998;
    }
    InterpolateAngles(start: &this->m_aCamAngle, end: targetAngle, output: &this->m_aCamAngle, frac);
    this->m_flLastAngleUpdateTime = *(float *)gpGlobals.m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECAF0
// Name: public: C_HLTVCamera::C_HLTVCamera(void)
// Source: json
//------------------------------------------------------------------------------
C_HLTVCamera *__thiscall C_HLTVCamera::C_HLTVCamera(C_HLTVCamera *this)
{
  C_HLTVCamera *v1; // ecx

  this->m_nDebugID = 42;
  this->__vftable = (C_HLTVCamera_vtbl *)&C_HLTVCamera::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_LastCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  this->m_LastCmd.command_number = 0;
  this->m_LastCmd.tick_count = 0;
  this->m_LastCmd.viewangles.x = 0.0;
  this->m_LastCmd.viewangles.y = 0.0;
  this->m_LastCmd.viewangles.z = 0.0;
  this->m_LastCmd.forwardmove = 0.0;
  this->m_LastCmd.sidemove = 0.0;
  this->m_LastCmd.upmove = 0.0;
  this->m_LastCmd.buttons = 0;
  this->m_LastCmd.impulse = 0;
  this->m_LastCmd.weaponselect = 0;
  this->m_LastCmd.weaponsubtype = 0;
  this->m_LastCmd.random_seed = 0;
  this->m_LastCmd.hasbeenpredicted = false;
  *(_DWORD *)&this->m_LastCmd.mousedx = 0;
  this->m_LastCmd.headangles.x = 0.0;
  this->m_LastCmd.headangles.y = 0.0;
  this->m_LastCmd.headangles.z = 0.0;
  this->m_LastCmd.headoffset.x = 0.0;
  this->m_LastCmd.headoffset.y = 0.0;
  this->m_LastCmd.headoffset.z = 0.0;
  C_HLTVCamera::Reset(this);
  v1->m_nNumSpectators = 0;
  v1->m_szTitleText[0] = 0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100ECC20
// Name: public: void C_HLTVCamera::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::Init(C_HLTVCamera *this)
{
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "game_newmap", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "hltv_cameraman", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "hltv_fixed", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "hltv_chase", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "hltv_message", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "hltv_title", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "hltv_status", a4: false);
  C_HLTVCamera::Reset(this);
  this->m_nNumSpectators = 0;
  this->m_szTitleText[0] = 0;
  tv_transmitall = cvar->FindVar_2(this: cvar, a2: "tv_transmitall");
}

//------------------------------------------------------------------------------
// Address: 0x100ECD00
// Name: protected: void C_HLTVCamera::CalcChaseCamView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_HLTVCamera::CalcChaseCamView(
        C_HLTVCamera *this@<ecx>,
        float a2@<ebp>,
        Vector *eyeOrigin,
        QAngle *eyeAngles,
        float *fov)
{
  int m_nValue; // eax
  C_BasePlayer *v7; // eax
  float x; // edi
  int v9; // eax
  int v10; // edx
  float v11; // xmm0_4
  unsigned __int8 (__thiscall *v12)(_DWORD); // eax
  bool v13; // zf
  int (*GetViewVectors)(void); // eax
  float *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float *v19; // eax
  float v20; // xmm0_4
  float *v21; // eax
  int m_iTraget2; // eax
  float z; // xmm3_4
  float v24; // xmm4_4
  C_BaseEntity *v25; // edi
  C_BaseEntity *BaseEntity; // eax
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // ecx
  int v31; // eax
  C_BaseEntity_vtbl *v32; // edx
  float v33; // xmm0_4
  bool (__thiscall *IsAlive)(C_BaseEntity *); // eax
  int (*v35)(void); // eax
  float *v36; // eax
  float *v37; // eax
  float *v38; // eax
  int v39; // eax
  float *v40; // eax
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  float v46; // xmm3_4
  float v47; // xmm6_4
  float v48; // xmm4_4
  float y; // xmm7_4
  __int128 v50; // xmm0
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm0_4
  float v54; // xmm5_4
  float v55; // xmm6_4
  int v56; // xmm1_4
  float v57; // xmm0_4
  int v58; // [esp-Ch] [ebp-C4h] BYREF
  _BYTE trace[92]; // [esp+0h] [ebp-B8h] OVERLAPPED
  Vector v60; // [esp+68h] [ebp-50h] BYREF
  Vector forward; // [esp+74h] [ebp-44h] BYREF
  C_BaseEntity *target1; // [esp+80h] [ebp-38h]
  Vector cameraOrigin; // [esp+84h] [ebp-34h] BYREF
  QAngle cameraAngles; // [esp+90h] [ebp-28h] BYREF
  QAngle angle; // [esp+9Ch] [ebp-1Ch] BYREF
  float v66; // [esp+A8h] [ebp-10h] OVERLAPPED
  Vector targetOrigin1; // [esp+ACh] [ebp-Ch] BYREF
  float retaddr; // [esp+B8h] [ebp+0h]

  targetOrigin1.x = a2;
  targetOrigin1.y = retaddr;
  if ( spec_autodirector.m_pParent != nullptr )
    m_nValue = spec_autodirector.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  HIBYTE(angle.x) = m_nValue == 0;
  if ( this->m_iTraget1 != 0 )
  {
    if ( this->m_iCameraMan > 0 && (v7 = UTIL_PlayerByIndex(entindex: this->m_iCameraMan)) != nullptr )
    {
      x = COERCE_FLOAT((int)v7->GetObserverTarget(this: v7));
      forward.x = x;
    }
    else
    {
      if ( this->m_iTraget1 <= 0 )
        return;
      LODWORD(forward.x) = CClientEntityList::GetBaseEntity(
                             this: (CClientEntityList *)cl_entitylist.m_Index,
                             entnum: this->m_iTraget1);
      x = forward.x;
    }
    if ( x != 0.0
      && ((*(unsigned __int8 (__thiscall **)(float))(*(_DWORD *)LODWORD(x) + 576))(a1: COERCE_FLOAT(LODWORD(x))) == 0
       || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(LODWORD(x) + 8) + 36))(a1: LODWORD(x) + 8) == 0) )
    {
      v9 = (*(int (__thiscall **)(int))(*(_DWORD *)(LODWORD(x) + 4) + 4))(a1: LODWORD(x) + 4);
      v10 = *(_DWORD *)LODWORD(x);
      angle.y = *(float *)v9;
      angle.z = *(float *)(v9 + 4);
      v11 = *(float *)(v9 + 8);
      v12 = *(unsigned __int8 (__thiscall **)(_DWORD))(v10 + 576);
      v66 = v11;
      v13 = v12(a1: LODWORD(x)) == 0;
      GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
      if ( v13 )
      {
        v15 = (float *)GetViewVectors();
        v16 = angle.y + v15[24];
        v17 = v15[25];
        v18 = v15[26];
      }
      else
      {
        if ( (*(_BYTE *)(LODWORD(x) + 248) & 2) != 0 )
        {
          v19 = (float *)GetViewVectors();
          v20 = v19[15];
          v17 = v19[16];
          v18 = v19[17];
        }
        else
        {
          v21 = (float *)GetViewVectors();
          v20 = *v21;
          v17 = v21[1];
          v18 = v21[2];
        }
        v16 = v20 + angle.y;
      }
      m_iTraget2 = this->m_iTraget2;
      z = v17 + angle.z;
      v24 = v18 + v66;
      v25 = nullptr;
      angle.y = v16;
      angle.z = z;
      v66 = v24;
      if ( m_iTraget2 > 0 && m_iTraget2 != this->m_iTraget1 && HIBYTE(angle.x) == 0 )
      {
        BaseEntity = CClientEntityList::GetBaseEntity(
                       this: (CClientEntityList *)cl_entitylist.m_Index,
                       entnum: m_iTraget2);
        v25 = BaseEntity;
        if ( BaseEntity != nullptr )
        {
          if ( !BaseEntity->IsDormant(this: &BaseEntity->IClientNetworkable) || !v25->IsAlive(this: v25) )
          {
            v31 = (int)v25->GetRenderOrigin(this: &v25->IClientRenderable);
            v32 = v25->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
            cameraAngles.x = *(float *)v31;
            cameraAngles.y = *(float *)(v31 + 4);
            v33 = *(float *)(v31 + 8);
            IsAlive = v32->IsAlive;
            cameraAngles.z = v33;
            v13 = !IsAlive(this: v25);
            v35 = (int (*)(void))g_pGameRules->GetViewVectors;
            if ( v13 )
            {
              v36 = (float *)v35();
              v27 = cameraAngles.x + v36[24];
              v28 = v36[25] + cameraAngles.y;
              v29 = v36[26] + cameraAngles.z;
              v24 = v66;
              z = angle.z;
              cameraAngles.x = v27;
              cameraAngles.y = v28;
              cameraAngles.z = v29;
            }
            else
            {
              if ( (v25->m_fFlags & 2) != 0 )
              {
                v37 = (float *)v35();
                v27 = v37[15] + cameraAngles.x;
                v28 = v37[16] + cameraAngles.y;
                v29 = v37[17] + cameraAngles.z;
              }
              else
              {
                v38 = (float *)v35();
                v27 = *v38 + cameraAngles.x;
                v28 = v38[1] + cameraAngles.y;
                v29 = v38[2] + cameraAngles.z;
              }
              v24 = v66;
              z = angle.z;
              cameraAngles.x = v27;
              cameraAngles.y = v28;
              cameraAngles.z = v29;
            }
LABEL_28:
            v30 = this->m_aCamAngle.z;
            forward.y = this->m_flPhi;
            forward.z = this->m_flTheta;
            *(_QWORD *)&cameraOrigin.x = *(_QWORD *)&this->m_aCamAngle.x;
            cameraOrigin.z = v30;
            if ( HIBYTE(angle.x) != 0 )
            {
              engine->GetViewAngles(this: engine, a2: (QAngle *)&cameraOrigin);
LABEL_47:
              AngleVectors(angles: (const QAngle *)&cameraOrigin, forward: &v60);
              VectorNormalize(vec: &v60);
              LODWORD(v42) = LODWORD(this->m_flDistance) ^ _mask__NegFloat_;
              forward.y = (float)(v42 * v60.x) + angle.y;
              v43 = (float)(v60.y * v42) + angle.z;
              v44 = (float)(v60.z * v42) + v66;
              v45 = this->m_flOffset + v66;
              forward.z = v43;
              target1 = (C_BaseEntity *)LODWORD(v44);
              v66 = v45;
              C_BaseEntity::PushEnableAbsRecomputations(bEnable: false);
              UTIL_TraceHull(
                a1: (const IHandleEntity *)&targetOrigin1,
                a2: (int)this,
                vecAbsStart: (const Vector *)&angle.y,
                vecAbsEnd: (Vector *)&forward.y,
                hullMin: &WALL_MIN_0,
                hullMax: &WALL_MAX_0,
                mask: 0x200400Bu,
                ignore: (const IHandleEntity *)LODWORD(forward.x),
                collisionGroup: 0,
                ptr: (CGameTrace *)&v58);
              C_BaseEntity::PopEnableAbsRecomputations();
              v46 = *(float *)trace;
              v47 = angle.z;
              v48 = v66;
              y = angle.y;
              v50 = 0;
              *(float *)&v50 = fsqrt(
                                 (float)((float)((float)(*(float *)&trace[4] - v47) * (float)(*(float *)&trace[4] - v47))
                                       + (float)((float)(*(float *)&trace[8] - v48) * (float)(*(float *)&trace[8] - v48)))
                               + (float)((float)(*(float *)trace - y) * (float)(*(float *)trace - y)));
              *(_OWORD *)&trace[76] = v50;
              v51 = (float)(*(float *)(gpGlobals.m_Index + 16) * 32.0) + this->m_flLastDistance;
              v52 = *(float *)&trace[76];
              this->m_flLastDistance = v51;
              if ( v52 <= v51 )
              {
                v54 = *(float *)&trace[4];
                v55 = *(float *)&trace[8];
                this->m_flLastDistance = *(float *)&trace[76];
              }
              else
              {
                v53 = -v51;
                v54 = (float)(v60.y * v53) + v47;
                v46 = (float)(v53 * v60.x) + y;
                v55 = (float)(v60.z * v53) + v48;
              }
              target1 = (C_BaseEntity *)LODWORD(v55);
              forward.z = v54;
              forward.y = v46;
              if ( v25 != nullptr )
              {
                v60.x = (float)((float)(cameraAngles.x + y) * 0.5) - v46;
                v60.y = (float)((float)(cameraAngles.y + angle.z) * 0.5) - v54;
                v60.z = (float)((float)(cameraAngles.z + v48) * 0.5) - v55;
                VectorAngles(forward: &v60, angles: &cameraAngles);
                cameraOrigin.y = cameraAngles.y;
                NormalizeAngles(angles: (QAngle *)&cameraOrigin);
                v56 = -1032847360;
                v57 = cameraOrigin.x;
                if ( cameraOrigin.x < -60.0 || (v56 = 1114636288, cameraOrigin.x > 60.0) )
                  v57 = *(float *)&v56;
                cameraOrigin.x = v57;
                C_HLTVCamera::SmoothCameraAngle(this, targetAngle: (QAngle *)&cameraOrigin);
              }
              else
              {
                C_HLTVCamera::SetCameraAngle(this, targetAngle: (QAngle *)&cameraOrigin);
              }
              this->m_vCamOrigin.x = forward.y;
              this->m_vCamOrigin.y = forward.z;
              LODWORD(this->m_vCamOrigin.z) = target1;
              *eyeAngles = this->m_aCamAngle;
              *eyeOrigin = this->m_vCamOrigin;
              return;
            }
            if ( v25 != nullptr )
            {
              v60.x = v27 - angle.y;
              v60.y = v28 - z;
              v60.z = v29 - v24;
              VectorAngles(forward: &v60, angles: (QAngle *)&cameraOrigin);
            }
            else
            {
              v39 = this->m_iTraget2;
              if ( v39 != 0 && v39 != this->m_iTraget1 )
              {
                forward.y = 0.0;
                forward.z = 0.0;
LABEL_43:
                if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(forward.x) + 576))(a1: LODWORD(forward.x)) != 0 )
                  v41 = forward.y;
                else
                  v41 = 15.0;
                cameraOrigin.x = v41 + cameraOrigin.x;
                cameraOrigin.y = forward.z + cameraOrigin.y;
                goto LABEL_47;
              }
              v40 = (float *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(forward.x) + 628))(a1: LODWORD(forward.x));
              cameraOrigin.x = *v40;
              cameraOrigin.y = v40[1];
              cameraOrigin.x = 0.0;
            }
            cameraOrigin.z = 0.0;
            goto LABEL_43;
          }
          v25 = nullptr;
        }
        z = angle.z;
        v24 = v66;
      }
      v27 = cameraAngles.x;
      v28 = cameraAngles.y;
      v29 = cameraAngles.z;
      goto LABEL_28;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED350
// Name: protected: void C_HLTVCamera::CalcInEyeCamView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::CalcInEyeCamView(C_HLTVCamera *this, Vector *eyeOrigin, QAngle *eyeAngles, float *fov)
{
  C_BasePlayer *v5; // eax
  C_BasePlayer *v6; // edi
  float *v7; // eax
  float *v8; // eax
  int (*GetViewVectors)(void); // eax
  float *v10; // eax
  float v11; // xmm0_4
  float *v12; // eax
  C_BaseViewModel *ViewModel; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v5 = UTIL_PlayerByIndex(entindex: this->m_iTraget1);
  v6 = v5;
  if ( v5 != nullptr )
  {
    if ( v5->IsAlive(this: v5) )
    {
      v7 = (float *)v6->EyeAngles(this: v6);
      this->m_aCamAngle.x = *v7;
      this->m_aCamAngle.y = v7[1];
      this->m_aCamAngle.z = v7[2];
      v8 = (float *)v6->GetAbsOrigin(this: v6);
      this->m_vCamOrigin.x = *v8;
      this->m_vCamOrigin.y = v8[1];
      this->m_vCamOrigin.z = v8[2];
      this->m_flFOV = v6->GetFOV(this: v6);
      GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
      if ( (v6->m_fFlags & 2) != 0 )
      {
        v10 = (float *)GetViewVectors();
        this->m_vCamOrigin.x = v10[15] + this->m_vCamOrigin.x;
        this->m_vCamOrigin.y = v10[16] + this->m_vCamOrigin.y;
        v11 = v10[17];
      }
      else
      {
        v12 = (float *)GetViewVectors();
        this->m_vCamOrigin.x = *v12 + this->m_vCamOrigin.x;
        this->m_vCamOrigin.y = v12[1] + this->m_vCamOrigin.y;
        v11 = v12[2];
      }
      this->m_vCamOrigin.z = v11 + this->m_vCamOrigin.z;
      *eyeOrigin = this->m_vCamOrigin;
      *eyeAngles = this->m_aCamAngle;
      *fov = this->m_flFOV;
      v6->CalcViewModelView(this: v6, a2: eyeOrigin, a3: eyeAngles);
      ViewModel = C_BasePlayer::GetViewModel(this: v6, index: 0);
      if ( ViewModel != nullptr )
        C_BaseEntity::UpdateVisibility(this: ViewModel);
    }
    else
    {
      C_HLTVCamera::CalcChaseCamView(this, a2: COERCE_FLOAT(&savedregs), eyeOrigin, eyeAngles, fov);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED4A0
// Name: protected: void C_HLTVCamera::CalcFixedView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::CalcFixedView(C_HLTVCamera *this, Vector *eyeOrigin, QAngle *eyeAngles, float *fov)
{
  int m_iTraget1; // eax
  C_BaseEntity *BaseEntity; // eax
  C_BaseEntity *v7; // ebx
  const CViewVectors *v8; // edi
  float *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  QAngle angle; // [esp+4h] [ebp-18h] BYREF
  Vector forward; // [esp+10h] [ebp-Ch] BYREF

  *eyeOrigin = this->m_vCamOrigin;
  *eyeAngles = this->m_aCamAngle;
  *fov = this->m_flFOV;
  m_iTraget1 = this->m_iTraget1;
  if ( m_iTraget1 != 0 )
  {
    BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: m_iTraget1);
    v7 = BaseEntity;
    if ( BaseEntity != nullptr && BaseEntity->IsAlive(this: BaseEntity) )
    {
      v8 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v9 = (float *)v7->GetAbsOrigin(this: v7);
      v10 = (float)(v8->m_vView.y + v9[1]) - this->m_vCamOrigin.y;
      v11 = (float)(v8->m_vView.z + v9[2]) - this->m_vCamOrigin.z;
      forward.x = (float)(v8->m_vView.x + *v9) - this->m_vCamOrigin.x;
      forward.y = v10;
      forward.z = v11;
      VectorAngles(&forward, angles: &angle);
      C_HLTVCamera::SmoothCameraAngle(this, targetAngle: &angle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED580
// Name: public: void C_HLTVCamera::FixupMovmentParents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::FixupMovmentParents(C_HLTVCamera *this)
{
  int v1; // eax
  int v2; // esi
  C_BaseEntity *v3; // eax
  int v4; // eax

  v1 = *(_DWORD *)(cl_entitylist.m_Index + 131076);
  if ( v1 != 0 )
  {
    v2 = ((signed int)(v1 - cl_entitylist.m_Index - 4) >> 4)
       | (*(_DWORD *)(cl_entitylist.m_Index + 16 * ((signed int)(v1 - cl_entitylist.m_Index - 4) >> 4) + 8) << 16);
    while ( v2 != -1 )
    {
      v3 = C_BaseEntity::Instance(hEnt: (CBaseHandle)v2);
      if ( v3 != nullptr )
        C_BaseEntity::HierarchyUpdateMoveParent(this: v3);
      v4 = *(_DWORD *)(cl_entitylist.m_Index + 16 * ((unsigned __int16)v2 + 1));
      if ( v4 != 0 )
        v2 = ((signed int)(v4 - cl_entitylist.m_Index - 4) >> 4)
           | (*(_DWORD *)(cl_entitylist.m_Index + 16 * ((signed int)(v4 - cl_entitylist.m_Index - 4) >> 4) + 8) << 16);
      else
        v2 = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED610
// Name: public: void C_HLTVCamera::SetPrimaryTarget(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::SetPrimaryTarget(C_HLTVCamera *this, int nEntity)
{
  int m_iTraget1; // ebx
  C_BasePlayer *v4; // eax
  int m_nCameraMode; // eax
  C_BasePlayer *v6; // eax
  int v7; // eax
  C_BaseEntity *BaseEntity; // eax
  IGameEvent *v9; // edi
  Vector vOrigin; // [esp+8h] [ebp-18h] BYREF
  QAngle eyeAngle; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  m_iTraget1 = this->m_iTraget1;
  if ( m_iTraget1 != nEntity )
  {
    this->m_iTraget1 = nEntity;
    if ( this->m_iCameraMan > 0 && (v4 = UTIL_PlayerByIndex(entindex: this->m_iCameraMan)) != nullptr )
      m_nCameraMode = v4->GetObserverMode(this: v4);
    else
      m_nCameraMode = this->m_nCameraMode;
    if ( m_nCameraMode == 6 )
    {
      C_HLTVCamera::CalcChaseCamView(
        this,
        a2: COERCE_FLOAT(&savedregs),
        eyeOrigin: &vOrigin,
        eyeAngles: &eyeAngle,
        fov: (float *)&nEntity);
    }
    else
    {
      if ( this->m_iCameraMan > 0 && (v6 = UTIL_PlayerByIndex(entindex: this->m_iCameraMan)) != nullptr )
        v7 = v6->GetObserverMode(this: v6);
      else
        v7 = this->m_nCameraMode;
      if ( v7 == 5 )
      {
        BaseEntity = CClientEntityList::GetBaseEntity(
                       this: (CClientEntityList *)cl_entitylist.m_Index,
                       entnum: this->m_iTraget1);
        if ( BaseEntity != nullptr )
        {
          eyeAngle = *BaseEntity->EyeAngles(this: BaseEntity);
          prediction->SetViewAngles(this: prediction, a2: &eyeAngle);
        }
      }
    }
    this->m_flLastDistance = this->m_flDistance;
    this->m_flLastAngleUpdateTime = -1.0;
    v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hltv_changed_target", a3: 0, a4: 0);
    if ( v9 != nullptr )
    {
      v9->SetInt(this: v9, a2: "mode", a3: this->m_nCameraMode);
      v9->SetInt(this: v9, a2: "old_target", a3: m_iTraget1);
      v9->SetInt(this: v9, a2: "obs_target", a3: this->m_iTraget1);
      gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED750
// Name: public: bool C_HLTVCamera::IsPVSLocked(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_HLTVCamera::IsPVSLocked(C_HLTVCamera *this)
{
  ConVar *m_pParent; // eax

  if ( tv_transmitall == nullptr )
    return !engine->IsPlayingDemo(this: engine);
  m_pParent = tv_transmitall->m_pParent;
  return m_pParent == nullptr || m_pParent->m_Value.m_nValue == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ED790
// Name: protected: void C_HLTVCamera::CalcRoamingView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_HLTVCamera::CalcRoamingView(
        C_HLTVCamera *this@<ecx>,
        float a2@<ebp>,
        Vector *eyeOrigin,
        QAngle *eyeAngles,
        float *fov)
{
  ConVar *m_pParent; // eax
  bool v7; // zf
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  double v11; // st7
  float z; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float y; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  __int128 v21; // xmm1
  float v22; // xmm5_4
  double v23; // xmm0_8
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  Vector v27; // [esp-Ch] [ebp-5Ch] BYREF
  Vector up; // [esp+0h] [ebp-50h] BYREF
  Vector forward; // [esp+Ch] [ebp-44h] BYREF
  Vector right; // [esp+18h] [ebp-38h] BYREF
  __int128 wishdir; // [esp+24h] [ebp-2Ch] OVERLAPPED
  Vector wishvel; // [esp+34h] [ebp-1Ch]
  float fmove; // [esp+40h] [ebp-10h]
  float smove; // [esp+44h] [ebp-Ch]
  float maxspeed; // [esp+48h] [ebp-8h]
  float retaddr; // [esp+50h] [ebp+0h]

  smove = a2;
  maxspeed = retaddr;
  if ( tv_transmitall != nullptr )
  {
    m_pParent = tv_transmitall->m_pParent;
    v7 = m_pParent == nullptr || m_pParent->m_Value.m_nValue == 0;
  }
  else
  {
    v7 = !engine->IsPlayingDemo(this: engine);
  }
  if ( !v7 )
  {
    v8 = sv_maxspeed.m_pParent->m_Value.m_fValue * sv_specspeed.m_pParent->m_Value.m_fValue;
    fmove = sv_specspeed.m_pParent->m_Value.m_fValue;
    wishvel.z = v8;
    AngleVectors(angles: &this->m_LastCmd.viewangles, forward: &up, right: &forward, up: &v27);
    v9 = fmove;
    if ( (this->m_LastCmd.buttons & 0x20000) != 0 )
    {
      v9 = fmove * 0.5;
      fmove = fmove * 0.5;
    }
    wishvel.x = this->m_LastCmd.forwardmove * v9;
    wishvel.y = this->m_LastCmd.sidemove * v9;
    VectorNormalize(vec: &up);
    VectorNormalize(vec: &forward);
    v10 = (float)(this->m_LastCmd.upmove * fmove) + (float)((float)(forward.z * wishvel.y) + (float)(up.z * wishvel.x));
    *((float *)&wishdir + 1) = (float)(forward.x * wishvel.y) + (float)(up.x * wishvel.x);
    *((float *)&wishdir + 2) = (float)(forward.y * wishvel.y) + (float)(up.y * wishvel.x);
    *((float *)&wishdir + 3) = v10;
    right = *(Vector *)((char *)&wishdir + 4);
    v11 = VectorNormalize(vec: &right);
    fmove = v11;
    z = wishvel.z;
    v13 = *((float *)&wishdir + 1);
    v14 = *((float *)&wishdir + 2);
    if ( v11 <= wishvel.z )
    {
      v16 = fmove;
      v15 = *((float *)&wishdir + 3);
    }
    else
    {
      v13 = *((float *)&wishdir + 1) * (float)(wishvel.z / fmove);
      v14 = *((float *)&wishdir + 2) * (float)(wishvel.z / fmove);
      v15 = *((float *)&wishdir + 3) * (float)(wishvel.z / fmove);
      v16 = wishvel.z;
    }
    wishvel.x = sv_specaccelerate.m_pParent->m_Value.m_fValue;
    if ( wishvel.x <= 0.0 )
    {
      this->m_vecVelocity.x = v13;
      this->m_vecVelocity.y = v14;
      this->m_vecVelocity.z = v15;
    }
    else
    {
      y = right.y;
      v18 = right.z;
      v19 = v16
          - (float)((float)((float)(this->m_vecVelocity.y * right.y) + (float)(right.x * this->m_vecVelocity.x))
                  + (float)(this->m_vecVelocity.z * right.z));
      if ( v19 > 0.0 )
      {
        v20 = (float)(*(float *)(gpGlobals.m_Index + 16) * wishvel.x) * v16;
        if ( v20 > v19 )
          v20 = v16
              - (float)((float)((float)(this->m_vecVelocity.y * right.y) + (float)(right.x * this->m_vecVelocity.x))
                      + (float)(this->m_vecVelocity.z * right.z));
        this->m_vecVelocity.x = (float)(v20 * right.x) + this->m_vecVelocity.x;
        this->m_vecVelocity.y = (float)(y * v20) + this->m_vecVelocity.y;
        this->m_vecVelocity.z = (float)(v18 * v20) + this->m_vecVelocity.z;
      }
      v21 = 0;
      *(float *)&v21 = fsqrt(
                         (float)((float)(this->m_vecVelocity.z * this->m_vecVelocity.z)
                               + (float)(this->m_vecVelocity.x * this->m_vecVelocity.x))
                       + (float)(this->m_vecVelocity.y * this->m_vecVelocity.y));
      wishdir = v21;
      if ( *(float *)&v21 >= 1.0 )
      {
        v22 = z * 0.25;
        if ( v22 <= *(float *)&wishdir )
          v23 = *(float *)&wishdir;
        else
          v23 = v22;
        v24 = *(float *)&wishdir
            - (float)((float)((float)v23 * sv_friction.m_pParent->m_Value.m_fValue) * *(float *)(gpGlobals.m_Index + 16));
        if ( v24 < 0.0 )
          v24 = 0.0;
        v25 = v24 / *(float *)&wishdir;
        this->m_vecVelocity.x = v25 * this->m_vecVelocity.x;
        this->m_vecVelocity.y = this->m_vecVelocity.y * v25;
        this->m_vecVelocity.z = this->m_vecVelocity.z * v25;
      }
      else
      {
        this->m_vecVelocity.x = 0.0;
        this->m_vecVelocity.y = 0.0;
        this->m_vecVelocity.z = 0.0;
      }
    }
    v26 = *(float *)(gpGlobals.m_Index + 16);
    this->m_vCamOrigin.x = (float)(v26 * this->m_vecVelocity.x) + this->m_vCamOrigin.x;
    this->m_vCamOrigin.y = (float)(this->m_vecVelocity.y * v26) + this->m_vCamOrigin.y;
    this->m_vCamOrigin.z = (float)(this->m_vecVelocity.z * v26) + this->m_vCamOrigin.z;
    engine->GetViewAngles(this: engine, a2: &this->m_aCamAngle);
    if ( sv_specaccelerate.m_pParent->m_Value.m_fValue < 0.0 )
    {
      this->m_vecVelocity.x = 0.0;
      this->m_vecVelocity.y = 0.0;
      this->m_vecVelocity.z = 0.0;
    }
  }
  *eyeOrigin = this->m_vCamOrigin;
  *eyeAngles = this->m_aCamAngle;
  *fov = this->m_flFOV;
}

//------------------------------------------------------------------------------
// Address: 0x100EDBD0
// Name: public: void C_HLTVCamera::CalcView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HLTVCamera::CalcView(C_HLTVCamera *this, Vector *origin, QAngle *angles, float *fov)
{
  C_BasePlayer *v5; // eax
  C_BasePlayer *v6; // esi
  QAngle *v7; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( this->m_bEntityPacketReceived )
  {
    C_HLTVCamera::FixupMovmentParents(this);
    this->m_bEntityPacketReceived = false;
  }
  if ( this->m_iCameraMan > 0 && (v5 = UTIL_PlayerByIndex(entindex: this->m_iCameraMan), v6 = v5, v5 != nullptr) )
  {
    v7 = angles;
    v5->CalcView(this: v5, a2: origin, a3: angles, a4: (float *)&angles, a5: (float *)&fov, a6: fov);
    v6->CalcViewModelView(this: v6, a2: origin, a3: v7);
  }
  else
  {
    switch ( this->m_nCameraMode )
    {
      case 3:
        C_HLTVCamera::CalcFixedView(this, eyeOrigin: origin, eyeAngles: angles, fov);
        break;
      case 4:
        C_HLTVCamera::CalcInEyeCamView(this, eyeOrigin: origin, eyeAngles: angles, fov);
        break;
      case 5:
        C_HLTVCamera::CalcChaseCamView(this, a2: COERCE_FLOAT(&savedregs), eyeOrigin: origin, eyeAngles: angles, fov);
        break;
      case 6:
        C_HLTVCamera::CalcRoamingView(this, a2: COERCE_FLOAT(&savedregs), eyeOrigin: origin, eyeAngles: angles, fov);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EDCC0
// Name: public: virtual void C_HLTVCamera::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_HLTVCamera::FireGameEvent(C_HLTVCamera *this@<ecx>, int a2@<ebx>, int a3@<esi>, IGameEvent *event)
{
  const char *v5; // ebx
  IViewPort *ViewPortInterface; // eax
  IViewPort *v7; // eax
  const char *v8; // eax
  const char *v9; // esi
  const wchar_t *v10; // eax
  CCenterPrint *CenterPrint; // eax
  wchar_t *i; // edx
  char *v13; // eax
  int v14; // ebx
  int v15; // eax
  int (__thiscall *GetInt)(IGameEvent *, const char *, int); // edx
  int v17; // eax
  bool v18; // zf
  int v19; // eax
  char v20; // al
  int m_nCameraMode; // ecx
  bool v22; // dl
  int v23; // eax
  float m_flDistance; // xmm0_4
  double v25; // st7
  int v26; // eax
  wchar_t outputBuf[1024]; // [esp+48h] [ebp-80Ch] BYREF
  QAngle angle; // [esp+848h] [ebp-Ch] BYREF

  if ( g_bEngineIsHLTV )
  {
    v5 = event->GetName(this: event);
    if ( _V_strcmp(s1: "game_newmap", s2: v5) != 0 )
    {
      if ( _V_strcmp(s1: "hltv_message", s2: v5) != 0 )
      {
        if ( _V_strcmp(s1: "hltv_title", s2: v5) != 0 )
        {
          if ( _V_strcmp(s1: "hltv_status", s2: v5) != 0 )
          {
            if ( spec_autodirector.m_pParent != nullptr && spec_autodirector.m_pParent->m_Value.m_nValue != 0
              || C_HLTVCamera::IsPVSLocked(this) )
            {
              if ( _V_strcmp(s1: "hltv_cameraman", s2: v5) != 0 )
              {
                if ( _V_strcmp(s1: "hltv_fixed", s2: v5) != 0 )
                {
                  if ( _V_strcmp(s1: "hltv_chase", s2: v5) == 0 )
                  {
                    v20 = ((int (__thiscall *)(IGameEvent *, const char *, _DWORD, int, int))event->GetBool)(
                            a1: event,
                            a2: "ineye",
                            a3: 0,
                            a4: a3,
                            a5: a2);
                    m_nCameraMode = this->m_nCameraMode;
                    v22 = m_nCameraMode == 4 || m_nCameraMode == 5;
                    if ( spec_autodirector.m_pParent != nullptr && spec_autodirector.m_pParent->m_Value.m_nValue != 0
                      || !v22 )
                    {
                      C_HLTVCamera::SetMode(this, iMode: (v20 == 0) + 4);
                    }
                    this->m_iCameraMan = 0;
                    v23 = event->GetInt(this: event, a2: "target2", a3: 0);
                    m_flDistance = this->m_flDistance;
                    this->m_iTraget2 = v23;
                    this->m_flDistance = ((double (__thiscall *)(IGameEvent *, const char *, _DWORD))event->GetFloat)(
                                           a1: event,
                                           a2: "distance",
                                           a3: LODWORD(m_flDistance));
                    this->m_flOffset = ((double (__thiscall *)(IGameEvent *, const char *, _DWORD))event->GetFloat)(
                                         a1: event,
                                         a2: "offset",
                                         a3: LODWORD(this->m_flOffset));
                    this->m_flTheta = ((double (__thiscall *)(IGameEvent *, const char *, _DWORD))event->GetFloat)(
                                        a1: event,
                                        a2: "theta",
                                        a3: LODWORD(this->m_flTheta));
                    this->m_flPhi = ((double (__thiscall *)(IGameEvent *, const char *, _DWORD))event->GetFloat)(
                                      a1: event,
                                      a2: "phi",
                                      a3: LODWORD(this->m_flPhi));
                    this->m_flFOV = ((double (__thiscall *)(IGameEvent *, const char *, int))event->GetFloat)(
                                      a1: event,
                                      a2: "fov",
                                      a3: 1119092736);
                    v25 = ((double (__thiscall *)(IGameEvent *, const char *, int))event->GetFloat)(
                            a1: event,
                            a2: "inertia",
                            a3: 1106247680)
                        * 0.1;
                    this->m_flInertia = v25;
                    if ( v25 <= 0.0 )
                      this->m_flInertia = 3.0;
                    v26 = event->GetInt(this: event, a2: "target1", a3: 0);
                    C_HLTVCamera::SetPrimaryTarget(this, nEntity: v26);
                  }
                }
                else
                {
                  this->m_iCameraMan = 0;
                  this->m_vCamOrigin.x = (float)((int (__thiscall *)(IGameEvent *, const char *, _DWORD, int, int))event->GetInt)(
                                                  a1: event,
                                                  a2: "posx",
                                                  a3: 0,
                                                  a4: a3,
                                                  a5: a2);
                  this->m_vCamOrigin.y = (float)event->GetInt(this: event, a2: "posy", a3: 0);
                  this->m_vCamOrigin.z = (float)event->GetInt(this: event, a2: "posz", a3: 0);
                  v15 = event->GetInt(this: event, a2: "theta", a3: 0);
                  GetInt = event->GetInt;
                  angle.x = (float)v15;
                  v17 = GetInt(this: event, a2: "phi", a3: 0);
                  v18 = this->m_nCameraMode == 3;
                  angle.y = (float)v17;
                  angle.z = 0.0;
                  if ( !v18 )
                  {
                    C_HLTVCamera::SetMode(this, iMode: 3);
                    C_HLTVCamera::SetCameraAngle(this, targetAngle: &angle);
                    this->m_flFOV = ((double (__thiscall *)(IGameEvent *, const char *, int))event->GetFloat)(
                                      a1: event,
                                      a2: "fov",
                                      a3: 1119092736);
                  }
                  v19 = event->GetInt(this: event, a2: "target", a3: 0);
                  C_HLTVCamera::SetPrimaryTarget(this, nEntity: v19);
                  if ( this->m_iTraget1 == 0 )
                    C_HLTVCamera::SetCameraAngle(this, targetAngle: &angle);
                }
              }
              else
              {
                C_HLTVCamera::Reset(this);
                this->m_nCameraMode = 6;
                this->m_iCameraMan = event->GetInt(this: event, a2: "index", a3: 0);
              }
            }
          }
          else
          {
            v14 = event->GetInt(this: event, a2: "proxies", a3: 0);
            this->m_nNumSpectators = event->GetInt(this: event, a2: "clients", a3: 0) - v14;
          }
        }
        else
        {
          v13 = (char *)event->GetString(this: event, a2: "text", a3: prType);
          V_strncpy(pDest: this->m_szTitleText, pSrc: v13, maxLen: 64);
        }
      }
      else
      {
        v8 = (const char *)((int (__thiscall *)(IGameEvent *, const char *, const char *, int))event->GetString)(
                             a1: event,
                             a2: "text",
                             a3: prType,
                             a4: a3);
        v9 = hudtextmessage->LookupString(this: hudtextmessage, a2: v8, a3: 0);
        v10 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v9);
        if ( v10 != nullptr )
        {
          wcsncpy(dest: outputBuf, source: v10, count: 0x400u);
          outputBuf[1023] = 0;
        }
        else
        {
          g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v9, a3: outputBuf, a4: 2048);
        }
        CenterPrint = GetCenterPrint();
        for ( i = outputBuf; *i != 0; ++i )
        {
          if ( *i == 13 )
            *i = 10;
        }
        CenterPrint->Print(this: CenterPrint, a2: outputBuf);
      }
    }
    else
    {
      C_HLTVCamera::Reset(this);
      if ( GetViewPortInterface() != nullptr )
      {
        if ( ((unsigned __int8 (__thiscall *)(IVEngineClient *, int, int))engine->IsPlayingDemo)(
               a1: engine,
               a2: a3,
               a3: a2) != 0 )
        {
          ViewPortInterface = GetViewPortInterface();
          ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "specmenu", a3: true);
          C_HLTVCamera::SetMode(this, iMode: 6);
        }
        else
        {
          v7 = GetViewPortInterface();
          v7->ShowPanel_2(this: v7, a2: "specgui", a3: true);
        }
      }
    }
  }
}
