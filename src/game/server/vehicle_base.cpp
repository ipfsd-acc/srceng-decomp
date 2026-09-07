// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/vehicle_base.cpp
// Functions: 92
// ============================================================

#include "game\server\vehicle_base.h"

//------------------------------------------------------------------------------
// Address: 0x102528C0
// Name: public: virtual struct datamap_t __near * CPropVehicle::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPropVehicle::GetDataDescMap(CPropVehicle *this)
{
  return &CPropVehicle::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102528D0
// Name: protected: virtual float CPropVehicle::GetUprightStrength(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPropVehicle::GetUprightStrength(CPropVehicle *this)
{
  return 8.0;
}

//------------------------------------------------------------------------------
// Address: 0x102528E0
// Name: protected: virtual float CPropVehicle::GetUprightTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPropVehicle::GetUprightTime(CPropVehicle *this)
{
  return 5.0;
}

//------------------------------------------------------------------------------
// Address: 0x102528F0
// Name: public: virtual void CPropVehicle::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPropVehicle::Precache(CPropVehicle *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseProp::Precache(this, a2);
  CFourWheelVehiclePhysics::Precache(this: &this->m_VehiclePhysics);
}

//------------------------------------------------------------------------------
// Address: 0x10252910
// Name: public: virtual void CPropVehicle::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::DrawDebugGeometryOverlays(CPropVehicle *this)
{
  if ( (this->m_debugOverlays & 4) != 0 )
    CFourWheelVehiclePhysics::DrawDebugGeometryOverlays(this: &this->m_VehiclePhysics);
  CBaseProp::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x10252930
// Name: public: virtual int CPropVehicle::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropVehicle::DrawDebugTextOverlays(CPropVehicle *this)
{
  int result; // eax

  result = CBaseAnimating::DrawDebugTextOverlays(this);
  if ( (this->m_debugOverlays & 1) != 0 )
    return CFourWheelVehiclePhysics::DrawDebugTextOverlays(this: &this->m_VehiclePhysics, nOffset: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10252950
// Name: public: void CPropVehicle::InputHandBrakeOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::InputHandBrakeOn(CPropVehicle *this, inputdata_t *inputdata)
{
  CFourWheelVehiclePhysics::SetHandbrake(this: &this->m_VehiclePhysics, bBrake: true);
}

//------------------------------------------------------------------------------
// Address: 0x10252960
// Name: public: void CPropVehicle::InputHandBrakeOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::InputHandBrakeOff(CPropVehicle *this, inputdata_t *inputdata)
{
  CFourWheelVehiclePhysics::ReleaseHandbrake(this: &this->m_VehiclePhysics);
}

//------------------------------------------------------------------------------
// Address: 0x10252970
// Name: public: virtual class Vector CPropVehicle::GetSmoothedVelocity(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPropVehicle::GetSmoothedVelocity(CPropVehicle *this, Vector *result)
{
  __int64 v2; // xmm0_8
  float z; // ecx

  v2 = *(_QWORD *)&this->m_vecSmoothedVelocity.x;
  z = this->m_vecSmoothedVelocity.z;
  *(_QWORD *)&result->x = v2;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10252990
// Name: public: virtual class ServerClass __near * CPropVehicleDriveable::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPropVehicleDriveable::GetServerClass(CPropVehicleDriveable *this)
{
  return &g_CPropVehicleDriveable_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102529A0
// Name: public: virtual struct datamap_t __near * CPropVehicleDriveable::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPropVehicleDriveable::GetDataDescMap(CPropVehicleDriveable *this)
{
  return &CPropVehicleDriveable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102529B0
// Name: public: virtual void CPropVehicleDriveable::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPropVehicleDriveable::Precache(
        CPropVehicleDriveable *this@<ecx>,
        bool (__cdecl *a2)(const char *)@<edi>)
{
  CFourWheelServerVehicle *m_pServerVehicle; // ecx
  const char *pszValue; // esi

  CBaseProp::Precache(this, a2);
  CFourWheelVehiclePhysics::Precache(this: &this->m_VehiclePhysics);
  if ( this->m_pServerVehicle == nullptr )
    this->CreateServerVehicle(this);
  m_pServerVehicle = this->m_pServerVehicle;
  if ( m_pServerVehicle != nullptr )
  {
    pszValue = this->m_vehicleScript.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CBaseServerVehicle::Initialize(this: m_pServerVehicle, pScriptName: pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252A00
// Name: public: virtual void CPropVehicleDriveable::VehicleAngleVectors(class QAngle const __near &,class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::VehicleAngleVectors(
        CPropVehicleDriveable *this,
        const QAngle *angles,
        Vector *pForward,
        Vector *pRight,
        Vector *pUp)
{
  AngleVectors(angles, forward: pRight, right: pForward, up: pUp);
  if ( pForward != nullptr )
  {
    pForward->x = pForward->x * -1.0;
    pForward->y = pForward->y * -1.0;
    pForward->z = pForward->z * -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252A60
// Name: public: void CPropVehicleDriveable::DriveVehicle(class CBasePlayer __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::DriveVehicle(CPropVehicleDriveable *this, CBasePlayer *pPlayer, CUserCmd *ucmd)
{
  if ( pPlayer->IsAlive(this: pPlayer) )
    ((void (__thiscall *)(CPropVehicleDriveable *, _DWORD, CUserCmd *, int, int))this->DriveVehicle)(
      a1: this,
      a2: LODWORD(gpGlobals->interval_per_tick),
      a3: ucmd,
      a4: pPlayer->m_afButtonPressed,
      a5: pPlayer->m_afButtonReleased);
}

//------------------------------------------------------------------------------
// Address: 0x10252AB0
// Name: public: void CPropVehicleDriveable::InputLock(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::InputLock(CPropVehicleDriveable *this, inputdata_t *inputdata)
{
  this->m_bLocked = true;
}

//------------------------------------------------------------------------------
// Address: 0x10252AC0
// Name: public: void CPropVehicleDriveable::InputUnlock(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::InputUnlock(CPropVehicleDriveable *this, inputdata_t *inputdata)
{
  this->m_bLocked = false;
}

//------------------------------------------------------------------------------
// Address: 0x10252AD0
// Name: public: virtual int CPropVehicleDriveable::VPhysicsGetObjectList(class IPhysicsObject __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropVehicleDriveable::VPhysicsGetObjectList(
        CPropVehicleDriveable *this,
        IPhysicsObject **pList,
        int listMax)
{
  return CFourWheelVehiclePhysics::VPhysicsGetObjectList(this: &this->m_VehiclePhysics, pList, listMax);
}

//------------------------------------------------------------------------------
// Address: 0x10252AE0
// Name: public: virtual bool CPropVehicleDriveable::NPC_AddPassenger(class CAI_BaseNPC __near *,struct string_t,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPropVehicleDriveable::NPC_AddPassenger(
        CPropVehicleDriveable *this,
        CAI_BaseNPC *pPassenger,
        string_t strRoleName,
        int nSeatID)
{
  bool result; // al
  int v6; // eax

  result = ((int (__thiscall *)(CPropVehicleDriveable *, CAI_BaseNPC *, int))this->dtr_IHandleEntity)(
             a1: this,
             a2: pPassenger,
             a3: 1);
  if ( result )
  {
    v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 378) + 364))(a1: (char *)this - 1512);
    return v6 == 0
        || (*(bool (__thiscall **)(int, CAI_BaseNPC *, const char *, int))(*(_DWORD *)v6 + 112))(
             a1: v6,
             a2: pPassenger,
             a3: strRoleName.pszValue,
             a4: nSeatID);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10252B40
// Name: public: virtual bool CPropVehicleDriveable::NPC_RemovePassenger(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPropVehicleDriveable::NPC_RemovePassenger(CPropVehicleDriveable *this, CAI_BaseNPC *pPassenger)
{
  bool result; // al
  int v4; // eax

  result = ((int (__thiscall *)(CPropVehicleDriveable *, CAI_BaseNPC *, int))this->SetRefEHandle)(
             a1: this,
             a2: pPassenger,
             a3: 1);
  if ( result )
  {
    v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 378) + 364))(a1: (char *)this - 1512);
    return v4 == 0 || (*(bool (__thiscall **)(int, CAI_BaseNPC *))(*(_DWORD *)v4 + 116))(a1: v4, a2: pPassenger);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10252B90
// Name: public: void CFourWheelServerVehicle::InitViewSmoothing(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelServerVehicle::InitViewSmoothing(
        CFourWheelServerVehicle *this,
        const Vector *vecOrigin,
        const QAngle *vecAngles)
{
  this->m_ViewSmoothing.bWasRunningAnim = false;
  this->m_ViewSmoothing.vecOriginSaved = *vecOrigin;
  this->m_ViewSmoothing.vecAnglesSaved = *vecAngles;
  this->m_ViewSmoothing.flFOV = r_JeepFOV.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x10252BF0
// Name: public: virtual void CFourWheelServerVehicle::SetVehicle(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelServerVehicle::SetVehicle(CFourWheelServerVehicle *this, CBaseEntity *pVehicle)
{
  CBaseServerVehicle::SetVehicle(this, pVehicle);
  if ( pVehicle != nullptr )
    this->m_ViewSmoothing.pVehicle = pVehicle->GetBaseAnimating(this: pVehicle);
}

//------------------------------------------------------------------------------
// Address: 0x10252C20
// Name: public: virtual bool CFourWheelServerVehicle::IsVehicleUpright(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFourWheelServerVehicle::IsVehicleUpright(CFourWheelServerVehicle *this)
{
  return (unsigned __int8)this->m_pVehicle->CBaseServerVehicle::__vftable[1].DrawDebugTextOverlays(this: this->m_pVehicle) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10252C40
// Name: public: virtual bool CFourWheelServerVehicle::IsVehicleBodyInWater(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFourWheelServerVehicle::IsVehicleBodyInWater(CFourWheelServerVehicle *this)
{
  return ((bool (__thiscall *)(CBaseEntity *))this->m_pVehicle->CBaseServerVehicle::__vftable[1].Save)(a1: this->m_pVehicle);
}

//------------------------------------------------------------------------------
// Address: 0x10252C90
// Name: vehicle_flushscript
// Source: json
//------------------------------------------------------------------------------
void __cdecl vehicle_flushscript()
{
  CBaseEntity *i; // esi
  int v1; // eax

  PhysFlushVehicleScripts();
  for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
        i != nullptr;
        i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
  {
    v1 = (int)i->GetServerVehicle(this: i);
    if ( v1 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 228))(a1: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252CE0
// Name: public: virtual void CPropVehicle::Teleport(class Vector const __near *,class QAngle const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::Teleport(
        CPropVehicle *this,
        const Vector *newPosition,
        const QAngle *newAngles,
        const Vector *newVelocity,
        bool bUseSlowHighAccuracyContacts)
{
  matrix3x4_t xform; // [esp+8h] [ebp-60h] BYREF
  matrix3x4_t startMatrixInv; // [esp+38h] [ebp-30h] BYREF
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  MatrixInvert(in: &this->m_rgflCoordinateFrame, out: &startMatrixInv);
  CBaseAnimating::Teleport(this, newPosition, newAngles, newVelocity, bUseSlowHighAccuracyContacts);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  ConcatTransforms(in1: &this->m_rgflCoordinateFrame, in2: &startMatrixInv, out: &xform);
  CFourWheelVehiclePhysics::Teleport(this: &this->m_VehiclePhysics, relativeTransform: &xform);
}

//------------------------------------------------------------------------------
// Address: 0x10252D70
// Name: public: void CPropVehicle::InputThrottle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::InputThrottle(CPropVehicle *this, inputdata_t *inputdata)
{
  const char *value; // xmm0_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    value = inputdata->value.iszVal.pszValue;
  else
    value = nullptr;
  CFourWheelVehiclePhysics::SetThrottle(this: (CFlexAnimationTrack *)&this->m_VehiclePhysics, value: *(float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x10252DA0
// Name: public: void CPropVehicle::InputSteering(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::InputSteering(CPropVehicle *this, inputdata_t *inputdata)
{
  const char *flSteering; // xmm0_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flSteering = inputdata->value.iszVal.pszValue;
  else
    flSteering = nullptr;
  CFourWheelVehiclePhysics::SetSteering(
    this: &this->m_VehiclePhysics,
    flSteering: *(float *)&flSteering,
    flSteeringRate: gpGlobals->frametime * 2.0);
}

//------------------------------------------------------------------------------
// Address: 0x10252DF0
// Name: public: void CPropVehicle::InputAction(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::InputAction(CPropVehicle *this, inputdata_t *inputdata)
{
  const char *flAction; // xmm0_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flAction = inputdata->value.iszVal.pszValue;
  else
    flAction = nullptr;
  CFourWheelVehiclePhysics::SetAction(this: &this->m_VehiclePhysics, flAction: *(float *)&flAction);
}

//------------------------------------------------------------------------------
// Address: 0x10252E20
// Name: public: virtual void CPropVehicle::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::VPhysicsUpdate(CPropVehicle *this, IPhysicsObject *pPhysics)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  Vector velocity; // [esp+4h] [ebp-Ch] BYREF

  if ( (this->m_iEFlags & 1) == 0 )
  {
    this->m_pPhysicsObject->GetVelocity(this: this->m_pPhysicsObject, a2: &velocity, a3: nullptr);
    v3 = (float)(this->m_vecSmoothedVelocity.y * 0.89999998) + (float)(velocity.y * 0.1);
    v4 = (float)(this->m_vecSmoothedVelocity.z * 0.89999998) + (float)(velocity.z * 0.1);
    this->m_vecSmoothedVelocity.x = (float)(this->m_vecSmoothedVelocity.x * 0.89999998) + (float)(velocity.x * 0.1);
    this->m_vecSmoothedVelocity.y = v3;
    this->m_vecSmoothedVelocity.z = v4;
    if ( CFourWheelVehiclePhysics::VPhysicsUpdate(this: &this->m_VehiclePhysics, pPhysics) != 0 )
      CBaseEntity::VPhysicsUpdate(this, pPhysics);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252EF0
// Name: public: virtual CPropVehicleDriveable::~CPropVehicleDriveable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::~CPropVehicleDriveable(CPropVehicleDriveable *this)
{
  CFourWheelServerVehicle *m_pServerVehicle; // ecx

  m_pServerVehicle = this->m_pServerVehicle;
  this->CPropVehicle::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPropVehicleDriveable_vtbl *)&CPropVehicleDriveable::`vftable'{for `CBaseProp'};
  this->CPropVehicle::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPropVehicleDriveable::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->IDrivableVehicle::__vftable = (IDrivableVehicle_vtbl *)&CPropVehicleDriveable::`vftable'{for `IDrivableVehicle'};
  this->INPCPassengerCarrier::__vftable = (INPCPassengerCarrier_vtbl *)&CPropVehicleDriveable::`vftable'{for `INPCPassengerCarrier'};
  if ( m_pServerVehicle != nullptr )
  {
    ((void (__thiscall *)(CFourWheelServerVehicle *, int))m_pServerVehicle->dtr_CFourWheelServerVehicle)(
      a1: m_pServerVehicle,
      a2: 1);
    this->m_pServerVehicle = nullptr;
  }
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_attack2axis);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_attackaxis);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_pressedAttack2);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_pressedAttack);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_playerOff);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_playerOn);
  this->CPropVehicle::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPropVehicleDriveable_vtbl *)&CPropVehicle::`vftable'{for `CBaseProp'};
  this->CPropVehicle::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPropVehicle::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  CFourWheelVehiclePhysics::~CFourWheelVehiclePhysics(this: &this->m_VehiclePhysics);
  CBaseAnimating::~CBaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x10252FB0
// Name: public: virtual struct string_t CPropVehicleDriveable::GetVehicleScriptName(void)
// Source: json
//------------------------------------------------------------------------------
string_t __thiscall CPropVehicleDriveable::GetVehicleScriptName(CPropVehicleDriveable *this, _DWORD *a2)
{
  *a2 = *((_DWORD *)this - 6);
  return (string_t)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10252FC0
// Name: public: virtual class IServerVehicle __near * CPropVehicleDriveable::GetServerVehicle(void)
// Source: json
//------------------------------------------------------------------------------
CFourWheelServerVehicle *__thiscall CPropVehicleDriveable::GetServerVehicle(CPropVehicleDriveable *this)
{
  return this->m_pServerVehicle;
}

//------------------------------------------------------------------------------
// Address: 0x10252FD0
// Name: protected: virtual bool CPropVehicleDriveable::ShouldThink(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPropVehicleDriveable::ShouldThink(CPropVehicleDriveable *this)
{
  return this->GetDriver(this: &this->IDrivableVehicle) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10252FF0
// Name: public: virtual void CPropVehicleDriveable::GetVectors(class Vector __near *,class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::GetVectors(
        CPropVehicleDriveable *this,
        Vector *pForward,
        Vector *pRight,
        Vector *pUp)
{
  matrix3x4_t *p_m_rgflCoordinateFrame; // esi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  p_m_rgflCoordinateFrame = &this->m_rgflCoordinateFrame;
  if ( pForward != nullptr )
    MatrixGetColumn(in: p_m_rgflCoordinateFrame, column: 1, out: pForward);
  if ( pRight != nullptr )
    MatrixGetColumn(in: p_m_rgflCoordinateFrame, column: 0, out: pRight);
  if ( pUp != nullptr )
    MatrixGetColumn(in: p_m_rgflCoordinateFrame, column: 2, out: pUp);
}

//------------------------------------------------------------------------------
// Address: 0x10253050
// Name: public: virtual void CPropVehicleDriveable::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::Use(
        CPropVehicleDriveable *this,
        CBaseCombatCharacter *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  int v6; // eax

  if ( pActivator != nullptr )
  {
    v6 = ((int (__thiscall *)(CBaseCombatCharacter *))pActivator->IsPlayer)(a1: pActivator);
    if ( (_BYTE)v6 != 0 )
    {
      pActivator[1].m_OnKilled.m_Value.fieldType &= ~0x20u;
      LOBYTE(v6) = value > 0.0;
      this->m_pServerVehicle->HandlePassengerEntry(this: this->m_pServerVehicle, a2: pActivator, a3: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102530A0
// Name: public: virtual bool CPropVehicleDriveable::IsOverturned(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPropVehicleDriveable::IsOverturned(CPropVehicleDriveable *this)
{
  Vector vUp; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  this->VehicleAngleVectors(this, a2: &this->m_angAbsRotation, a3: nullptr, a4: nullptr, a5: &vUp);
  return (float)((float)((float)(vUp.y + vUp.x) * 0.0) + vUp.z) < 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10253100
// Name: public: virtual void CPropVehicleDriveable::SetupMove(class CBasePlayer __near *,class CUserCmd __near *,class IMoveHelper __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::SetupMove(
        CPropVehicleDriveable *this,
        CBasePlayer *player,
        CUserCmd *ucmd,
        IMoveHelper *pHelper,
        CMoveData *move)
{
  if ( *((_BYTE *)this - 32) != 0
    && LOBYTE(this->m_hMoveParent.m_Value.m_Index) == 0
    && LOBYTE(this->m_hMovePeer.m_Index) == 0
    && BYTE1(this->m_hMovePeer.m_Index) == 0 )
  {
    CPropVehicleDriveable::DriveVehicle(this: (CPropVehicleDriveable *)((char *)this - 1508), pPlayer: player, ucmd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253140
// Name: public: virtual bool CPropVehicleDriveable::CanEnterVehicle(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPropVehicleDriveable::CanEnterVehicle(CPropVehicleDriveable *this, CBaseEntity *pEntity)
{
  if ( ((int (__thiscall *)(CPropVehicleDriveable *))this->dtr_IHandleEntity)(a1: this) != 0
    && (CBaseEntity *)((int (__thiscall *)(CPropVehicleDriveable *))this->dtr_IHandleEntity)(a1: this) != pEntity
    || (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 377) + 944))(a1: (char *)this - 1508) != 0 )
  {
    return false;
  }
  return BYTE1(this->m_hMoveParent.m_Value.m_Index) == 0
      && *(float *)&this->m_hMoveChild.m_Index >= (float)this->m_nNextThinkTick.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102531B0
// Name: public: virtual bool CPropVehicleDriveable::CanExitVehicle(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPropVehicleDriveable::CanExitVehicle(CPropVehicleDriveable *this, CBaseEntity *pEntity)
{
  return LOBYTE(this->m_hMovePeer.m_Index) == 0
      && BYTE1(this->m_hMovePeer.m_Index) == 0
      && BYTE1(this->m_hMoveParent.m_Value.m_Index) == 0
      && *(float *)&this->m_hMoveChild.m_Index >= (float)this->m_nNextThinkTick.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102531F0
// Name: public: void CPropVehicleDriveable::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::InputTurnOn(CPropVehicleDriveable *this, inputdata_t *inputdata)
{
  CFourWheelVehiclePhysics *p_m_VehiclePhysics; // esi

  p_m_VehiclePhysics = &this->m_VehiclePhysics;
  this->m_bEngineLocked = false;
  CFourWheelVehiclePhysics::TurnOn(this: &this->m_VehiclePhysics);
  CFourWheelVehiclePhysics::SetDisableEngine(this: p_m_VehiclePhysics, bDisable: false);
}

//------------------------------------------------------------------------------
// Address: 0x10253220
// Name: public: void CPropVehicleDriveable::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::InputTurnOff(CPropVehicleDriveable *this, inputdata_t *inputdata)
{
  CFourWheelVehiclePhysics *p_m_VehiclePhysics; // esi

  p_m_VehiclePhysics = &this->m_VehiclePhysics;
  this->m_bEngineLocked = true;
  CFourWheelVehiclePhysics::TurnOff(this: &this->m_VehiclePhysics);
  CFourWheelVehiclePhysics::SetDisableEngine(this: p_m_VehiclePhysics, bDisable: true);
}

//------------------------------------------------------------------------------
// Address: 0x10253250
// Name: public: virtual void CPropVehicleDriveable::Event_KilledOther(class CBaseEntity __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::Event_KilledOther(
        CPropVehicleDriveable *this,
        CBaseEntity *pVictim,
        const CTakeDamageInfo *info)
{
  int v3; // eax

  v3 = this->GetDriver(this: &this->IDrivableVehicle);
  if ( v3 != 0 )
    (*(void (__thiscall **)(int, CBaseEntity *, const CTakeDamageInfo *))(*(_DWORD *)v3 + 280))(
      a1: v3,
      a2: pVictim,
      a3: info);
}

//------------------------------------------------------------------------------
// Address: 0x10253280
// Name: public: CFourWheelServerVehicle::CFourWheelServerVehicle(void)
// Source: json
//------------------------------------------------------------------------------
CFourWheelServerVehicle *__thiscall CFourWheelServerVehicle::CFourWheelServerVehicle(CFourWheelServerVehicle *this)
{
  CBaseServerVehicle::CBaseServerVehicle(this);
  this->__vftable = (CFourWheelServerVehicle_vtbl *)&CFourWheelServerVehicle::`vftable';
  memset(dst: (int)&this->m_ViewSmoothing, value: nullptr, count: sizeof(this->m_ViewSmoothing));
  this->m_ViewSmoothing.flPitchCurveZero = 10.0;
  this->m_ViewSmoothing.bClampEyeAngles = true;
  this->m_ViewSmoothing.bDampenEyePosition = true;
  this->m_ViewSmoothing.flPitchCurveLinear = 45.0;
  this->m_ViewSmoothing.flRollCurveZero = 5.0;
  this->m_ViewSmoothing.flRollCurveLinear = 45.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102532F0
// Name: public: virtual enum Class_T CBaseServerVehicle::ClassifyPassenger(class CBaseCombatCharacter __near *,enum Class_T)
// Source: json
//------------------------------------------------------------------------------
Class_T __thiscall CBaseServerVehicle::ClassifyPassenger(
        CBaseServerVehicle *this,
        CBaseCombatCharacter *pPassenger,
        Class_T defaultClassification)
{
  return defaultClassification;
}

//------------------------------------------------------------------------------
// Address: 0x10253330
// Name: public: virtual void CFourWheelServerVehicle::GetVehicleViewPosition(int,class Vector __near *,class QAngle __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelServerVehicle::GetVehicleViewPosition(
        CFourWheelServerVehicle *this,
        int nRole,
        Vector *pAbsOrigin,
        QAngle *pAbsAngles,
        float *pFOV)
{
  CBasePlayer *v6; // esi
  bool v7; // al

  v6 = (CBasePlayer *)this->GetPassenger(this, a2: nRole);
  if ( v6 != nullptr && v6->IsPlayer(this: v6) )
  {
    v7 = v6->IsPlayer(this: v6);
    SharedVehicleViewSmoothing(
      pPlayer: v7 ? v6 : nullptr,
      pAbsOrigin,
      pAbsAngles,
      bEnterAnimOn: this->m_pVehicle[2].m_Network.m_PVSInfo.m_nHeadNode,
      bExitAnimOn: HIBYTE(this->m_pVehicle[2].m_Network.m_PVSInfo.m_nHeadNode),
      vecEyeExitEndpoint: (const Vector *)&this->m_pVehicle[1].m_ScriptScope.m_FuncHandles.m_pElements,
      pData: &this->m_ViewSmoothing,
      pFOV,
      bForceViewToAttachment: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102533B0
// Name: public: virtual struct vehicleparams_t const __near * CFourWheelServerVehicle::GetVehicleParams(void)
// Source: json
//------------------------------------------------------------------------------
const vehicleparams_t *__thiscall CFourWheelServerVehicle::GetVehicleParams(CFourWheelServerVehicle *this)
{
  return (*(const vehicleparams_t *(__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(this->m_pVehicle[1].m_vecBaseVelocity.m_Value.x)
                                                          + 12))(a1: LODWORD(this->m_pVehicle[1].m_vecBaseVelocity.m_Value.x));
}

//------------------------------------------------------------------------------
// Address: 0x102533D0
// Name: public: virtual class IPhysicsVehicleController __near * CFourWheelServerVehicle::GetVehicleController(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsVehicleController *__thiscall CFourWheelServerVehicle::GetVehicleController(CFourWheelServerVehicle *this)
{
  return (IPhysicsVehicleController *)LODWORD(this->m_pVehicle[1].m_vecBaseVelocity.m_Value.x);
}

//------------------------------------------------------------------------------
// Address: 0x102533E0
// Name: public: virtual bool CFourWheelServerVehicle::IsPassengerEntering(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFourWheelServerVehicle::IsPassengerEntering(CFourWheelServerVehicle *this)
{
  return this->m_pVehicle[2].m_Network.m_PVSInfo.m_nHeadNode;
}

//------------------------------------------------------------------------------
// Address: 0x102533F0
// Name: public: virtual bool CFourWheelServerVehicle::IsPassengerExiting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFourWheelServerVehicle::IsPassengerExiting(CFourWheelServerVehicle *this)
{
  return HIBYTE(this->m_pVehicle[2].m_Network.m_PVSInfo.m_nHeadNode);
}

//------------------------------------------------------------------------------
// Address: 0x10253420
// Name: public: virtual void CPropVehicle::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::Spawn(CPropVehicle *this)
{
  IServerVehicle *v2; // eax
  CFourWheelServerVehicle *v3; // ebx
  const char *pszValue; // eax

  v2 = this->GetServerVehicle(this);
  v3 = (CFourWheelServerVehicle *)__RTDynamicCast(
                                    inptr: v2,
                                    VfDelta: 0,
                                    SrcType: &IServerVehicle `RTTI Type Descriptor',
                                    TargetType: &CFourWheelServerVehicle `RTTI Type Descriptor',
                                    isReference: 0);
  this->m_VehiclePhysics.m_pOuter.m_Index = this->GetRefEHandle(this)->m_Index;
  this->m_VehiclePhysics.m_pOuterServerVehicle = v3;
  CBaseProp::Spawn(this);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 7);
  CFourWheelVehiclePhysics::Spawn(this: &this->m_VehiclePhysics);
  pszValue = this->m_vehicleScript.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( CFourWheelVehiclePhysics::Initialize(
         this: &this->m_VehiclePhysics,
         a2: (int)v3,
         pVehicleScript: pszValue,
         nVehicleType: this->m_nVehicleType) != 0 )
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    this->m_vecSmoothedVelocity.x = 0.0;
    this->m_vecSmoothedVelocity.y = 0.0;
    this->m_vecSmoothedVelocity.z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102534E0
// Name: public: virtual int CPropVehicle::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropVehicle::Restore(CPropVehicle *this, IRestore *restore)
{
  IServerVehicle *v3; // eax
  CFourWheelServerVehicle *v4; // edi

  v3 = this->GetServerVehicle(this);
  v4 = (CFourWheelServerVehicle *)__RTDynamicCast(
                                    inptr: v3,
                                    VfDelta: 0,
                                    SrcType: &IServerVehicle `RTTI Type Descriptor',
                                    TargetType: &CFourWheelServerVehicle `RTTI Type Descriptor',
                                    isReference: 0);
  this->m_VehiclePhysics.m_pOuter.m_Index = this->GetRefEHandle(this)->m_Index;
  this->m_VehiclePhysics.m_pOuterServerVehicle = v4;
  return CBaseAnimating::Restore(this, restore);
}

//------------------------------------------------------------------------------
// Address: 0x10253540
// Name: public: virtual void CPropVehicle::OnPhysGunPickup(class CBasePlayer __near *,enum PhysGunPickup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::OnPhysGunPickup(CPropVehicle *this, CBasePlayer *pPhysGunUser, PhysGunPickup_t reason)
{
  if ( pPhysGunUser != nullptr )
    *(_DWORD *)&this->m_nWaterTouch = pPhysGunUser->GetRefEHandle(this: pPhysGunUser)->m_Index;
  else
    *(_DWORD *)&this->m_nWaterTouch = -1;
  this->m_flNavIgnoreUntilTime = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10253590
// Name: public: virtual void CPropVehicle::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicle::Think(CPropVehicle *this)
{
  CFourWheelVehiclePhysics::Think(this: &this->m_VehiclePhysics);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102538B0
// Name: public: virtual void CPropVehicleDriveable::CreateServerVehicle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::CreateServerVehicle(CPropVehicleDriveable *this)
{
  CFourWheelServerVehicle *v2; // eax
  CFourWheelServerVehicle *v3; // eax

  v2 = (CFourWheelServerVehicle *)operator new(nSize: 0x218u);
  if ( v2 != nullptr )
    v3 = CFourWheelServerVehicle::CFourWheelServerVehicle(this: v2);
  else
    v3 = nullptr;
  this->m_pServerVehicle = v3;
  v3->SetVehicle(this: v3, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x102538F0
// Name: public: virtual int CPropVehicleDriveable::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropVehicleDriveable::Restore(CPropVehicleDriveable *this, IRestore *restore)
{
  CFourWheelServerVehicle *m_pServerVehicle; // ecx
  IServerVehicle *v4; // eax
  CFourWheelServerVehicle *v5; // edi

  m_pServerVehicle = this->m_pServerVehicle;
  if ( m_pServerVehicle != nullptr )
  {
    ((void (__thiscall *)(CFourWheelServerVehicle *, int))m_pServerVehicle->dtr_CFourWheelServerVehicle)(
      a1: m_pServerVehicle,
      a2: 1);
    this->m_pServerVehicle = nullptr;
  }
  this->CreateServerVehicle(this);
  v4 = this->GetServerVehicle(this);
  v5 = (CFourWheelServerVehicle *)__RTDynamicCast(
                                    inptr: v4,
                                    VfDelta: 0,
                                    SrcType: &IServerVehicle `RTTI Type Descriptor',
                                    TargetType: &CFourWheelServerVehicle `RTTI Type Descriptor',
                                    isReference: 0);
  this->m_VehiclePhysics.m_pOuter.m_Index = this->GetRefEHandle(this)->m_Index;
  this->m_VehiclePhysics.m_pOuterServerVehicle = v5;
  return CBaseAnimating::Restore(this, restore);
}

//------------------------------------------------------------------------------
// Address: 0x10253970
// Name: public: virtual void CPropVehicleDriveable::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::VPhysicsCollision(CPropVehicleDriveable *this, int index, CBaseEntity *pEvent)
{
  CBaseEntity *(__thiscall *GetDriver)(IDrivableVehicle *); // edx
  IDrivableVehicle *v4; // edi
  int v5; // eax
  bool v7; // cc
  CBaseEntity *v8; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *OwnerEntity; // eax
  double v11; // st7
  double v12; // st7
  CBaseEntity *(__thiscall *v13)(IDrivableVehicle *); // eax
  CBaseEntity *v14; // eax
  CBaseEntity *v15; // eax
  int energyScale; // [esp+Ch] [ebp-A0h]
  CTakeDamageInfo info; // [esp+28h] [ebp-84h] BYREF
  Vector damagePos; // [esp+84h] [ebp-28h] BYREF
  Vector damageForce; // [esp+90h] [ebp-1Ch] BYREF
  CBaseCombatCharacter *pDriver; // [esp+9Ch] [ebp-10h]
  int otherIndex; // [esp+A0h] [ebp-Ch]
  int damageType; // [esp+A4h] [ebp-8h] BYREF
  CBaseEntity *pInflictor; // [esp+A8h] [ebp-4h]
  int savedregs; // [esp+ACh] [ebp+0h] BYREF
  CBaseEntity *flDamage; // [esp+B4h] [ebp+8h]
  float flDamagea; // [esp+B4h] [ebp+8h]

  GetDriver = this->GetDriver;
  v4 = &this->IDrivableVehicle;
  pInflictor = this;
  if ( (int)GetDriver(this: &this->IDrivableVehicle) == 0 )
    return;
  v5 = v4->GetDriver(this: v4);
  pDriver = (CBaseCombatCharacter *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 300))(a1: v5);
  if ( pDriver == nullptr )
    return;
  v7 = *(float *)&pEvent->m_Network.m_pOuter >= 0.5;
  otherIndex = index == 0;
  flDamage = *((CBaseEntity **)&pEvent->m_flSimulationTime.m_Value + otherIndex);
  if ( !v7 && *((CBaseEntity **)&pEvent->m_flSimulationTime.m_Value + otherIndex) == pInflictor )
    return;
  CBaseEntity::VPhysicsCollision(this: pInflictor, (surfacedata_t *)index, pEvent);
  v8 = flDamage;
  m_Index = flDamage->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
LABEL_10:
      v8 = flDamage;
      goto LABEL_11;
    }
    v8 = flDamage;
    if ( (flDamage->m_fEffects.m_Value & 0x20) != 0 )
    {
      OwnerEntity = CBaseEntity::GetOwnerEntity(this: flDamage);
      if ( pDriver->IRelationType(this: pDriver, a2: OwnerEntity) == D_LI )
        return;
      goto LABEL_10;
    }
  }
LABEL_11:
  if ( v8->MyNPCPointer(this: v8) == nullptr
    && ((*(int (__thiscall **)(_DWORD))(**((_DWORD **)&pEvent->__vftable + otherIndex) + 76))(a1: *((_DWORD *)&pEvent->__vftable
                                                                                                  + otherIndex))
      & 8) == 0
    && __RTDynamicCast(
         inptr: flDamage,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CBreakable `RTTI Type Descriptor',
         isReference: 0) == nullptr )
  {
    damageType = 0;
    v11 = CalculatePhysicsImpactDamage(
            a1: COERCE_FLOAT(&savedregs),
            index,
            (gamevcollisionevent_t *)pEvent,
            table: &gDefaultPlayerVehicleImpactDamageTable,
            energyScale: 1.0,
            allowStaticDamage: true,
            &damageType,
            bDamageFromHeldObjects: false);
    flDamagea = v11;
    if ( v11 > 0.0 && gpGlobals->curtime > *(float *)&pInflictor[2].m_Network.m_PVSInfo.m_nAreaNum )
    {
      (*(void (__thiscall **)(_DWORD, Vector *))(**(_DWORD **)&pEvent->m_Network.m_PVSInfo.m_nHeadNode + 4))(
        a1: *(_DWORD *)&pEvent->m_Network.m_PVSInfo.m_nHeadNode,
        a2: &damagePos);
      v12 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**((_DWORD **)&pEvent->__vftable + index) + 116))(a1: *((_DWORD *)&pEvent->__vftable + index));
      damageForce.x = v12 * *(float *)&pEvent->m_Network.m_PVSInfo.m_pClustersInline[6 * index + 2];
      energyScale = damageType | 0x10;
      damageForce.y = *((float *)&pEvent->m_Network.m_pServerClass + 3 * index) * v12;
      v13 = v4->GetDriver;
      damageForce.z = v12 * *((float *)&pEvent->m_Network.m_hParent.m_Index + 3 * index);
      v14 = v13(this: v4);
      CTakeDamageInfo::CTakeDamageInfo(
        this: &info,
        pInflictor,
        pAttacker: v14,
        &damageForce,
        damagePosition: &damagePos,
        flDamage: flDamagea,
        bitsDamageType: energyScale,
        iKillType: 0,
        reportedPosition: nullptr,
        iObjectsPenetrated: 0);
      v15 = (CBaseEntity *)v4->GetDriver(this: v4);
      CBaseEntity::TakeDamage(this: v15, a2: (int)pEvent, inputInfo: &info);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253B80
// Name: public: virtual void CPropVehicleDriveable::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::TraceAttack(
        CPropVehicleDriveable *this,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  double v5; // st7
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *KeepUpright; // eax
  unsigned int v13; // eax
  IHandleEntity *v14; // ecx
  float flAngularLimit; // [esp+24h] [ebp-28h]
  float flUprightStrength; // [esp+48h] [ebp-4h]
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  if ( (info->m_bitsDamageType & 0x800000) != 0 )
  {
    v5 = ((double (__thiscall *)(CPropVehicleDriveable *))this->GetUprightStrength)(a1: this);
    if ( v5 != 0.0 )
    {
      m_Index = this->m_hKeepUpright.m_Index;
      if ( m_Index != -1
        && (v7 = (unsigned __int16)m_Index,
            v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
            v9 = HIWORD(m_Index),
            v8->m_SerialNumber == v9)
        && v8->m_pEntity != nullptr )
      {
        v10 = &g_pEntityList->m_EntPtrArray[v7];
        if ( v10->m_SerialNumber == v9 )
          m_pEntity = v10->m_pEntity;
        else
          m_pEntity = nullptr;
        flUprightStrength = v5;
        ((void (__thiscall *)(IHandleEntity *, const char *, CPropVehicleDriveable *, CPropVehicleDriveable *, _DWORD))m_pEntity->__vftable[13].dtr_IHandleEntity)(
          a1: m_pEntity,
          a2: "SetAngularLimit",
          a3: this,
          a4: this,
          a5: LODWORD(flUprightStrength));
      }
      else
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        flAngularLimit = this->GetUprightStrength(this);
        KeepUpright = CreateKeepUpright(
                        vecOrigin: &this->m_vecAbsOrigin,
                        vecAngles: &vec3_angle,
                        pOwner: this,
                        flAngularLimit,
                        bActive: false);
        if ( KeepUpright != nullptr )
          this->m_hKeepUpright.m_Index = KeepUpright->GetRefEHandle(this: KeepUpright)->m_Index;
        else
          this->m_hKeepUpright.m_Index = -1;
      }
      v13 = this->m_hKeepUpright.m_Index;
      if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
        v14 = nullptr;
      else
        v14 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
      ((void (__thiscall *)(IHandleEntity *, const char *, CPropVehicleDriveable *, CPropVehicleDriveable *, _DWORD))v14->__vftable[13].dtr_IHandleEntity)(
        a1: v14,
        a2: "TurnOn",
        a3: this,
        a4: this,
        a5: 0);
      this->m_flTurnOffKeepUpright = ((double (__thiscall *)(CPropVehicleDriveable *))this->GetUprightTime)(a1: this)
                                   + gpGlobals->curtime;
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
  CBaseEntity::TraceAttack(this, info, vecDir, ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10253D70
// Name: public: virtual void CFourWheelServerVehicle::NPC_SetDriver(class CNPC_VehicleDriver __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelServerVehicle::NPC_SetDriver(CFourWheelServerVehicle *this, CNPC_VehicleDriver *pDriver)
{
  CBaseEntity *m_pVehicle; // edi
  CBaseEntity *v4; // eax
  CFourWheelVehiclePhysics *p_z; // ecx
  CBaseEntity *v6; // ecx

  if ( pDriver != nullptr )
  {
    this->m_nNPCButtons = 0;
    m_pVehicle = this->m_pVehicle;
    m_pVehicle[2].m_Network.__vftable = (CServerNetworkProperty_vtbl *)pDriver->GetRefEHandle(this: pDriver)->m_Index;
    v4 = this->m_pVehicle;
    p_z = (CFourWheelVehiclePhysics *)&v4[1].m_Collision.m_vecSurroundingMaxs.z;
    if ( LOBYTE(v4[2].m_Network.m_pOuter) != 0 )
      CFourWheelVehiclePhysics::SetHandbrake(this: p_z, bBrake: true);
    else
      CFourWheelVehiclePhysics::TurnOn(this: p_z);
    v6 = this->m_pVehicle;
    this->m_flVehicleVolume = 1.0;
    v6->SetOwnerEntity(this: v6, a2: pDriver);
    CBaseEntity::SetNextThink(this: this->m_pVehicle, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
  else
  {
    this->m_pVehicle[2].m_Network.__vftable = (CServerNetworkProperty_vtbl *)-1;
    CFourWheelVehiclePhysics::TurnOff(this: (CFourWheelVehiclePhysics *)&this->m_pVehicle[1].m_Collision.m_vecSurroundingMaxs.z);
    this->m_pVehicle->SetOwnerEntity(this: this->m_pVehicle, a2: nullptr);
    this->m_flVehicleVolume = 0.5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253E40
// Name: public: virtual void CFourWheelServerVehicle::NPC_DriveVehicle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelServerVehicle::NPC_DriveVehicle(CFourWheelServerVehicle *this)
{
  int m_nNPCButtons; // eax
  int m_nPrevNPCButtons; // edx
  CBaseEntity *m_pVehicle; // ecx
  CBaseEntity *v5; // ecx
  float flSteering; // xmm0_4
  CUserCmd fakeCmd; // [esp+24h] [ebp-58h] BYREF

  m_nNPCButtons = this->m_nNPCButtons;
  m_nPrevNPCButtons = this->m_nPrevNPCButtons;
  memset(&fakeCmd.command_number, 0, 20);
  fakeCmd.impulse = 0;
  memset(&fakeCmd.weaponselect, 0, 17);
  fakeCmd.upmove = 0.0;
  memset((void *)&fakeCmd.headangles, 0, 24);
  fakeCmd.forwardmove = (float)((float)(m_nNPCButtons & 8) * 200.0) - (float)((float)(m_nNPCButtons & 0x10) * 200.0);
  fakeCmd.buttons = m_nNPCButtons;
  m_pVehicle = this->m_pVehicle;
  fakeCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  fakeCmd.sidemove = (float)((float)(m_nNPCButtons & 0x200) * -200.0) + (float)((float)(m_nNPCButtons & 0x400) * 200.0);
  ((void (__stdcall *)(_DWORD, CUserCmd *, int, int))m_pVehicle->__vftable[1].DrawDebugGeometryOverlays)(
    a1: LODWORD(gpGlobals->frametime),
    a2: &fakeCmd,
    a3: (m_nNPCButtons ^ m_nPrevNPCButtons) & m_nNPCButtons,
    a4: (m_nNPCButtons ^ m_nPrevNPCButtons) & ~m_nNPCButtons);
  v5 = this->m_pVehicle;
  flSteering = this->m_flTurnDegrees;
  this->m_nPrevNPCButtons = this->m_nNPCButtons;
  CFourWheelVehiclePhysics::SetSteering(
    this: (CFourWheelVehiclePhysics *)&v5[1].m_Collision.m_vecSurroundingMaxs.z,
    flSteering,
    flSteeringRate: 0.0);
  this->m_nNPCButtons &= 0xFFFFF7FE;
}

//------------------------------------------------------------------------------
// Address: 0x10254090
// Name: public: virtual class CBasePlayer __near * CPropVehicle::HasPhysicsAttacker(float)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CPropVehicle::HasPhysicsAttacker(CPropVehicle *this, float dt)
{
  unsigned int m_Index; // ecx

  if ( this->m_flLastPhysicsInfluenceTime < (float)(gpGlobals->curtime - dt) )
    return nullptr;
  m_Index = this->m_hPhysicsAttacker.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x102540F0
// Name: public: virtual class CBaseEntity __near * CPropVehicleDriveable::GetDriver(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CPropVehicleDriveable::GetDriver(CPropVehicleDriveable *this)
{
  unsigned int m_Index; // edx
  int v2; // eax
  CEntInfo *v3; // esi
  unsigned int v4; // edx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax
  const char *pszValue; // eax

  m_Index = this->m_pParent.m_Index;
  if ( m_Index != -1
    && (v2 = (unsigned __int16)m_Index,
        v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v4 = HIWORD(m_Index),
        v3->m_SerialNumber == v4)
    && v3->m_pEntity != nullptr )
  {
    v5 = v2;
    v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4;
    v7 = &g_pEntityList->m_EntPtrArray[v5];
    if ( v6 )
      return (CBaseEntity *)v7->m_pEntity;
  }
  else
  {
    pszValue = this->m_iszResponseContext.pszValue;
    if ( pszValue != (const char *)-1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)pszValue].m_SerialNumber == (unsigned int)pszValue >> 16 )
    {
      return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)pszValue].m_pEntity;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10254160
// Name: public: virtual void CPropVehicleDriveable::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::Think(CPropVehicleDriveable *this)
{
  unsigned int m_Index; // eax
  IServerVehicle *v3; // eax
  unsigned int v4; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v10; // esi

  CFourWheelVehiclePhysics::Think(this: &this->m_VehiclePhysics);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  if ( this->ShouldThink(this) )
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  m_Index = this->m_hNPCDriver.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v3 = this->GetServerVehicle(this);
    v3->NPC_DriveVehicle(this: v3);
  }
  if ( this->m_flTurnOffKeepUpright != 0.0 )
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    v4 = this->m_hKeepUpright.m_Index;
    if ( v4 != -1 )
    {
      v5 = (unsigned __int16)v4;
      v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v4];
      v7 = HIWORD(v4);
      if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr && gpGlobals->curtime > this->m_flTurnOffKeepUpright )
      {
        v8 = &g_pEntityList->m_EntPtrArray[v5];
        if ( v8->m_SerialNumber == v7 )
          m_pEntity = v8->m_pEntity;
        else
          m_pEntity = nullptr;
        ((void (__thiscall *)(IHandleEntity *, const char *, CPropVehicleDriveable *, CPropVehicleDriveable *, _DWORD))m_pEntity->__vftable[13].dtr_IHandleEntity)(
          a1: m_pEntity,
          a2: "TurnOff",
          a3: this,
          a4: this,
          a5: 0);
        this->m_flTurnOffKeepUpright = 0.0;
        v10 = this->m_hKeepUpright.m_Index;
        if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
          UTIL_Remove(oldObj: nullptr);
        else
          UTIL_Remove(oldObj: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10254360
// Name: public: virtual void CPropVehicleDriveable::SetVehicleEntryAnim(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::SetVehicleEntryAnim(CPropVehicleDriveable *this, bool bOn)
{
  CHandle<CBaseEntity> *p_m_hMovePeer; // esi
  char *v3; // eax
  CBaseEdict *v4; // ecx

  p_m_hMovePeer = &this->m_hMovePeer;
  if ( LOBYTE(this->m_hMovePeer.m_Index) != bOn )
  {
    v3 = (char *)this - 1508;
    if ( *((_BYTE *)this - 1424) != 0 )
    {
      v3[88] |= 1u;
      LOBYTE(p_m_hMovePeer->m_Index) = bOn;
    }
    else
    {
      v4 = *((CBaseEdict **)v3 + 6);
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: v4, offset: 0x6C4u);
      LOBYTE(p_m_hMovePeer->m_Index) = bOn;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102543B0
// Name: public: virtual void CPropVehicleDriveable::SetVehicleExitAnim(bool,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::SetVehicleExitAnim(
        CPropVehicleDriveable *this,
        bool bOn,
        Vector vecEyeExitEndpoint)
{
  char *v4; // eax
  CBaseEdict *v5; // ecx
  char *v6; // eax
  CBaseEdict *v7; // ecx

  if ( BYTE1(this->m_hMovePeer.m_Index) != bOn )
  {
    v4 = (char *)this - 1508;
    if ( *((_BYTE *)this - 1424) != 0 )
    {
      v4[88] |= 1u;
    }
    else
    {
      v5 = *((CBaseEdict **)v4 + 6);
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: 0x6C5u);
    }
    BYTE1(this->m_hMovePeer.m_Index) = bOn;
  }
  if ( bOn
    && (vecEyeExitEndpoint.x != *(float *)&this->m_nRenderFX.m_Value
     || vecEyeExitEndpoint.y != *(float *)&this->m_clrRender
     || vecEyeExitEndpoint.z != *(float *)&this->m_nSimulationTick) )
  {
    v6 = (char *)this - 1508;
    if ( *((_BYTE *)this - 1424) != 0 )
    {
      v6[88] |= 1u;
    }
    else
    {
      v7 = *((CBaseEdict **)v6 + 6);
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x698u);
    }
    *(Vector *)&this->m_nRenderFX.m_Value = vecEyeExitEndpoint;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10254490
// Name: public: CPropVehicleDriveable::CPropVehicleDriveable(void)
// Source: json
//------------------------------------------------------------------------------
CPropVehicleDriveable *__thiscall CPropVehicleDriveable::CPropVehicleDriveable(CPropVehicleDriveable *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx

  CBaseAnimating::CBaseAnimating(this);
  this->CPropVehicle::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CDefaultPlayerPickupVPhysics::`vftable';
  this->CPropVehicle::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPropVehicleDriveable_vtbl *)&CPropVehicle::`vftable'{for `CBaseProp'};
  this->CPropVehicle::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPropVehicle::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  CFourWheelVehiclePhysics::CFourWheelVehiclePhysics(this: &this->m_VehiclePhysics, pOuter: this);
  this->m_hPhysicsAttacker.m_Index = -1;
  this->m_nVehicleType = 1;
  this->IDrivableVehicle::__vftable = (IDrivableVehicle_vtbl *)&IDrivableVehicle::`vftable';
  this->INPCPassengerCarrier::__vftable = (INPCPassengerCarrier_vtbl *)&INPCPassengerCarrier::`vftable';
  this->CPropVehicle::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPropVehicleDriveable_vtbl *)&CPropVehicleDriveable::`vftable'{for `CBaseProp'};
  this->CPropVehicle::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPropVehicleDriveable::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->IDrivableVehicle::__vftable = (IDrivableVehicle_vtbl *)&CPropVehicleDriveable::`vftable'{for `IDrivableVehicle'};
  this->INPCPassengerCarrier::__vftable = (INPCPassengerCarrier_vtbl *)&CPropVehicleDriveable::`vftable'{for `INPCPassengerCarrier'};
  this->m_pServerVehicle = nullptr;
  this->m_playerOn.m_Value.iVal = 0;
  this->m_playerOn.m_Value.eVal.m_Index = -1;
  this->m_playerOn.m_Value.fieldType = FIELD_VOID;
  this->m_playerOff.m_Value.iVal = 0;
  this->m_playerOff.m_Value.eVal.m_Index = -1;
  this->m_playerOff.m_Value.fieldType = FIELD_VOID;
  this->m_pressedAttack.m_Value.iVal = 0;
  this->m_pressedAttack.m_Value.eVal.m_Index = -1;
  this->m_pressedAttack.m_Value.fieldType = FIELD_VOID;
  this->m_pressedAttack2.m_Value.iVal = 0;
  this->m_pressedAttack2.m_Value.eVal.m_Index = -1;
  this->m_pressedAttack2.m_Value.fieldType = FIELD_VOID;
  this->m_attackaxis.m_Value.iVal = 0;
  this->m_attackaxis.m_Value.eVal.m_Index = -1;
  this->m_attackaxis.m_Value.fieldType = FIELD_VOID;
  this->m_attack2axis.m_Value.iVal = 0;
  this->m_attack2axis.m_Value.eVal.m_Index = -1;
  this->m_attack2axis.m_Value.fieldType = FIELD_VOID;
  this->m_hPlayer.m_Value.m_Index = -1;
  this->m_hNPCDriver.m_Index = -1;
  this->m_hKeepUpright.m_Index = -1;
  this->m_flTurnOffKeepUpright = 0.0;
  this->m_flNoImpactDamageTime = 0.0;
  if ( this->m_vecEyeExitEndpoint.m_Value.x != 0.0
    || this->m_vecEyeExitEndpoint.m_Value.y != 0.0
    || this->m_vecEyeExitEndpoint.m_Value.z != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x698u);
    }
    this->m_vecEyeExitEndpoint.m_Value.x = 0.0;
    this->m_vecEyeExitEndpoint.m_Value.y = 0.0;
    this->m_vecEyeExitEndpoint.m_Value.z = 0.0;
  }
  if ( this->m_vecGunCrosshair.m_Value.x != 0.0
    || this->m_vecGunCrosshair.m_Value.y != 0.0
    || this->m_vecGunCrosshair.m_Value.z != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x6A4u);
    }
    this->m_vecGunCrosshair.m_Value.x = 0.0;
    this->m_vecGunCrosshair.m_Value.y = 0.0;
    this->m_vecGunCrosshair.m_Value.z = 0.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10254680
// Name: public: virtual void CPropVehicleDriveable::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::Spawn(CPropVehicleDriveable *this)
{
  CFourWheelServerVehicle *m_pServerVehicle; // ecx
  const char *pszValue; // eax
  const char *v4; // ecx
  const char *v5; // eax

  m_pServerVehicle = this->m_pServerVehicle;
  if ( m_pServerVehicle != nullptr )
  {
    ((void (__thiscall *)(CFourWheelServerVehicle *, int))m_pServerVehicle->dtr_CFourWheelServerVehicle)(
      a1: m_pServerVehicle,
      a2: 1);
    this->m_pServerVehicle = nullptr;
  }
  this->CreateServerVehicle(this);
  pszValue = this->m_vehicleScript.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( CBaseServerVehicle::Initialize(this: this->m_pServerVehicle, pScriptName: pszValue) )
  {
    CPropVehicle::Spawn(this);
    this->m_flMinimumSpeedToEnterExit = 0.0;
    if ( this->m_takedamage.m_Value != 1 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      this->m_takedamage.m_Value = 1;
    }
    this->m_bEngineLocked = false;
  }
  else
  {
    v4 = this->m_vehicleScript.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    v5 = this->m_iName.m_Value.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    _Warning(a1: "Vehicle (%s) unable to properly initialize due to script error in (%s)!\n", v5, v4);
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10254780
// Name: public: virtual void CPropVehicleDriveable::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPropVehicleDriveable::OnRestore(CPropVehicleDriveable *this@<ecx>, int a2@<ebp>)
{
  edict_t *m_pPev; // ecx
  IServerVehicle *(__thiscall *GetServerVehicle)(CBaseEntity *); // eax
  int v5; // eax

  CBaseAnimating::OnRestore(this);
  if ( !this->m_bExitAnimOn.m_Value )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    if ( this->m_vecAbsOrigin.x != this->m_vecEyeExitEndpoint.m_Value.x
      || this->m_vecAbsOrigin.y != this->m_vecEyeExitEndpoint.m_Value.y
      || this->m_vecAbsOrigin.z != this->m_vecEyeExitEndpoint.m_Value.z )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x698u);
      }
      this->m_vecEyeExitEndpoint.m_Value.x = this->m_vecAbsOrigin.x;
      this->m_vecEyeExitEndpoint.m_Value.y = this->m_vecAbsOrigin.y;
      this->m_vecEyeExitEndpoint.m_Value.z = this->m_vecAbsOrigin.z;
    }
  }
  GetServerVehicle = this->GetServerVehicle;
  this->m_flNoImpactDamageTime = gpGlobals->curtime + 5.0;
  v5 = (int)GetServerVehicle(this);
  if ( v5 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 144))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10254870
// Name: public: virtual void CPropVehicleDriveable::EnterVehicle(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::EnterVehicle(CPropVehicleDriveable *this, CBasePlayer *pPassenger)
{
  const char *pszValue; // eax
  char *v4; // ebx
  CFourWheelVehiclePhysics *v5; // ecx
  void (__thiscall *m_pfnThink)(CBaseEntity *); // eax
  float v7; // ecx
  unsigned int v8; // edx
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // edx
  const QAngle *v10; // eax
  Vector vecOrigin; // [esp+18h] [ebp-18h] BYREF
  Vector vecViewOffset; // [esp+24h] [ebp-Ch]
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  if ( pPassenger != nullptr && pPassenger->IsPlayer(this: pPassenger) )
  {
    pszValue = this->m_iszResponseContext.pszValue;
    if ( pszValue != (const char *)-1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)pszValue].m_SerialNumber == (unsigned int)pszValue >> 16
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)pszValue].m_pEntity != nullptr )
    {
      ((void (__thiscall *)(CPropVehicleDriveable *, _DWORD))this->GetDataDescMap)(a1: this, a2: 0);
    }
    CNetworkHandleBase<CBasePlayer,CPropVehicleDriveable::NetworkVar_m_hPlayer>::Set(
      this: (CNetworkHandleBase<CBasePlayer,CPropVehicleDriveable::NetworkVar_m_hPlayer> *)&this->m_iszResponseContext,
      val: pPassenger);
    v4 = (char *)this - 1508;
    COutputEvent::FireOutput(
      this: (COutputEvent *)&this->m_Network,
      pActivator: pPassenger,
      pCaller: (CPropVehicleDriveable *)((char *)this - 1508),
      fDelay: 0.0);
    if ( LOBYTE(this->m_hMovePeer.m_Index) == 0 )
    {
      v5 = (CFourWheelVehiclePhysics *)(v4 + 1168);
      if ( v4[1724] != 0 )
        CFourWheelVehiclePhysics::SetHandbrake(this: v5, bBrake: true);
      else
        CFourWheelVehiclePhysics::TurnOn(this: v5);
    }
    CBaseEntity::SetNextThink(
      this: (CPropVehicleDriveable *)((char *)this - 1508),
      thinkTime: gpGlobals->curtime,
      szContext: nullptr);
    m_pfnThink = this->m_pfnThink;
    v7 = *((float *)m_pfnThink + 33);
    v8 = (unsigned int)pPassenger->m_iEFlags >> 11;
    *(_QWORD *)&vecViewOffset.x = *(_QWORD *)((char *)m_pfnThink + 124);
    vecViewOffset.z = v7;
    if ( (v8 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pPassenger, a2: (int)&savedregs);
    EyeAngles = pPassenger->EyeAngles;
    vecOrigin.x = pPassenger->m_vecAbsOrigin.x + vecViewOffset.x;
    vecOrigin.y = pPassenger->m_vecAbsOrigin.y + vecViewOffset.y;
    vecOrigin.z = pPassenger->m_vecAbsOrigin.z + vecViewOffset.z;
    v10 = EyeAngles(this: pPassenger);
    CFourWheelServerVehicle::InitViewSmoothing(
      this: (CFourWheelServerVehicle *)this->m_pfnThink,
      &vecOrigin,
      vecAngles: v10);
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this - 76) + 44))(a1: *((_DWORD *)this - 76));
  }
}

//------------------------------------------------------------------------------
// Address: 0x102549D0
// Name: public: virtual void CPropVehicleDriveable::ExitVehicle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::ExitVehicle(CPropVehicleDriveable *this, int nRole)
{
  const char *pszValue; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // edi
  const char *v6; // eax
  char *v7; // eax
  CBaseEdict *v8; // ecx
  char *v9; // eax
  CBaseEdict *v10; // ecx
  char *v11; // eax
  CBaseEdict *v12; // ecx
  void (__thiscall *m_pfnThink)(CBaseEntity *); // ebx
  int data; // [esp+10h] [ebp-4h] BYREF

  pszValue = this->m_iszResponseContext.pszValue;
  if ( pszValue != (const char *)-1 )
  {
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)pszValue];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)pszValue].m_SerialNumber == (unsigned int)pszValue >> 16 )
    {
      m_pEntity = v4->m_pEntity;
      if ( v4->m_pEntity != nullptr )
      {
        v6 = this->m_iszResponseContext.pszValue;
        if ( v6 != (const char *)-1
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == (unsigned int)v6 >> 16
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity != nullptr )
        {
          v7 = (char *)this - 1508;
          if ( *((_BYTE *)this - 1424) != 0 )
          {
            v7[88] |= 1u;
          }
          else
          {
            v8 = *((CBaseEdict **)v7 + 6);
            if ( v8 != nullptr )
              CBaseEdict::StateChanged(this: v8, offset: 0x680u);
          }
          this->m_iszResponseContext.pszValue = (const char *)-1;
        }
        m_pEntity[739].__vftable = (IHandleEntity_vtbl *)((int)m_pEntity[739].__vftable & ~0x20u);
        COutputEvent::FireOutput(
          this: (COutputEvent *)&this->m_Network.m_PVSInfo.m_nAreaNum,
          pActivator: (CBaseEntity *)m_pEntity,
          pCaller: (CPropVehicleDriveable *)((char *)this - 1508),
          fDelay: 0.0);
        data = 0;
        variant_t::Set(
          this: (variant_t *)&this->m_nLastThinkTick,
          ftype: FIELD_FLOAT,
          ($3B1CACFA647AB85A7D70EA6016B49717 *)&data);
        CBaseEntityOutput::FireOutput(
          this: (CBaseEntityOutput *)&this->m_nLastThinkTick,
          Value: *(variant_t *)&this->m_nLastThinkTick,
          pActivator: (CBaseEntity *)m_pEntity,
          pCaller: (CPropVehicleDriveable *)((char *)this - 1508),
          fDelay: 0.0);
        data = 0;
        variant_t::Set(
          this: (variant_t *)&this->m_aThinkFunctions.m_pElements,
          ftype: FIELD_FLOAT,
          ($3B1CACFA647AB85A7D70EA6016B49717 *)&data);
        CBaseEntityOutput::FireOutput(
          this: (CBaseEntityOutput *)&this->m_aThinkFunctions.m_pElements,
          Value: *(variant_t *)&this->m_aThinkFunctions.m_pElements,
          pActivator: (CBaseEntity *)m_pEntity,
          pCaller: (CPropVehicleDriveable *)((char *)this - 1508),
          fDelay: 0.0);
        if ( this->m_nNextThinkTick.m_Value != 0 )
        {
          v9 = (char *)this - 1508;
          if ( *((_BYTE *)this - 1424) != 0 )
          {
            v9[88] |= 1u;
          }
          else
          {
            v10 = *((CBaseEdict **)v9 + 6);
            if ( v10 != nullptr )
              CBaseEdict::StateChanged(this: v10, offset: 0x684u);
          }
          this->m_nNextThinkTick.m_Value = 0;
        }
        if ( *(float *)&this->m_ModelName.pszValue != 0.0 )
        {
          v11 = (char *)this - 1508;
          if ( *((_BYTE *)this - 1424) != 0 )
          {
            v11[88] |= 1u;
          }
          else
          {
            v12 = *((CBaseEdict **)v11 + 6);
            if ( v12 != nullptr )
              CBaseEdict::StateChanged(this: v12, offset: 0x68Cu);
          }
          this->m_ModelName.pszValue = nullptr;
        }
        CFourWheelVehiclePhysics::TurnOff(this: (CFourWheelVehiclePhysics *)((char *)this - 340));
        (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this - 76) + 48))(a1: *((_DWORD *)this - 76));
        m_pfnThink = this->m_pfnThink;
        *((_BYTE *)m_pfnThink + 478) = 0;
        *(Vector *)((char *)m_pfnThink + 500) = vec3_origin;
        *(QAngle *)((char *)m_pfnThink + 488) = vec3_angle;
        *((float *)m_pfnThink + 110) = r_JeepFOV.m_pParent->m_Value.m_fValue;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10254CA0
// Name: public: virtual void CPropVehicleDriveable::DriveVehicle(float,class CUserCmd __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropVehicleDriveable::DriveVehicle(
        CPropVehicleDriveable *this,
        float flFrameTime,
        float ucmd,
        __int16 iButtonsDown,
        int iButtonsReleased)
{
  int m_nSpeed; // ebx
  edict_t *m_pPev; // ecx
  int m_nRPM; // eax
  int v9; // ebx
  edict_t *v10; // ecx
  int m_nBoostTimeLeft; // ebx
  edict_t *v12; // ecx
  int v13; // ebx
  edict_t *v14; // ecx
  CUserCmd *v15; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *v17; // ecx
  edict_t *v18; // ecx
  edict_t *v19; // ecx
  __int16 v20; // bx
  float v21; // xmm1_4
  int iButtons; // [esp+10h] [ebp-4h]

  iButtons = *(_DWORD *)(LODWORD(ucmd) + 36);
  CFourWheelVehiclePhysics::UpdateDriverControls(
    this: &this->m_VehiclePhysics,
    cmd: (CUserCmd *)LODWORD(ucmd),
    flFrameTime);
  m_nSpeed = this->m_VehiclePhysics.m_nSpeed;
  if ( this->m_nSpeed.m_Value != m_nSpeed )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x684u);
    }
    this->m_nSpeed.m_Value = m_nSpeed;
  }
  m_nRPM = this->m_VehiclePhysics.m_nRPM;
  if ( m_nRPM >= 0 )
  {
    v9 = 4095;
    if ( m_nRPM <= 4095 )
      v9 = this->m_VehiclePhysics.m_nRPM;
  }
  else
  {
    v9 = 0;
  }
  if ( this->m_nRPM.m_Value != v9 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x688u);
    }
    this->m_nRPM.m_Value = v9;
  }
  m_nBoostTimeLeft = this->m_VehiclePhysics.m_nBoostTimeLeft;
  if ( this->m_nBoostTimeLeft.m_Value != m_nBoostTimeLeft )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x690u);
    }
    this->m_nBoostTimeLeft.m_Value = m_nBoostTimeLeft;
  }
  v13 = this->m_VehiclePhysics.m_nHasBoost != 0;
  if ( this->m_nHasBoost.m_Value != v13 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x694u);
    }
    this->m_nHasBoost.m_Value = v13;
  }
  m_Value = this->m_flThrottle.m_Value;
  ucmd = this->m_VehiclePhysics.m_controls.throttle;
  v15 = (CUserCmd *)LODWORD(ucmd);
  if ( m_Value != ucmd )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v17 = this->m_Network.m_pPev;
      if ( v17 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x68Cu);
        v15 = (CUserCmd *)LODWORD(ucmd);
      }
    }
    LODWORD(this->m_flThrottle.m_Value) = v15;
  }
  if ( this->m_nScannerDisabledWeapons.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v18 = this->m_Network.m_pPev;
      if ( v18 != nullptr )
        CBaseEdict::StateChanged(this: &v18->CBaseEdict, offset: 0x6B2u);
    }
    this->m_nScannerDisabledWeapons.m_Value = false;
  }
  if ( this->m_nScannerDisabledVehicle.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v19 = this->m_Network.m_pPev;
      if ( v19 != nullptr )
        CBaseEdict::StateChanged(this: &v19->CBaseEdict, offset: 0x6B3u);
    }
    this->m_nScannerDisabledVehicle.m_Value = false;
  }
  v20 = iButtonsDown;
  flFrameTime = 0.0;
  ucmd = 0.0;
  if ( (iButtonsDown & 1) != 0 )
    COutputEvent::FireOutput(this: &this->m_pressedAttack, pActivator: this, pCaller: this, fDelay: 0.0);
  if ( (v20 & 0x800) != 0 )
    COutputEvent::FireOutput(this: &this->m_pressedAttack2, pActivator: this, pCaller: this, fDelay: 0.0);
  if ( (iButtons & 1) != 0 )
    v21 = 1.0;
  else
    v21 = flFrameTime;
  if ( (iButtons & 0x800) != 0 )
    ucmd = 1.0;
  flFrameTime = v21;
  variant_t::Set(
    this: &this->m_attackaxis.m_Value,
    ftype: FIELD_FLOAT,
    data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&flFrameTime);
  CBaseEntityOutput::FireOutput(
    this: &this->m_attackaxis,
    Value: this->m_attackaxis.m_Value,
    pActivator: this,
    pCaller: this,
    fDelay: 0.0);
  variant_t::Set(
    this: &this->m_attack2axis.m_Value,
    ftype: FIELD_FLOAT,
    data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&ucmd);
  CBaseEntityOutput::FireOutput(
    this: &this->m_attack2axis,
    Value: this->m_attack2axis.m_Value,
    pActivator: this,
    pCaller: this,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x103CA6F0
// Name: public: class CPropVehicleDriveable __near * CFourWheelServerVehicle::GetFourWheelVehicle(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFourWheelServerVehicle::GetFourWheelVehicle(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x1040C4E0
// Name: CFourWheelServerVehicle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFourWheelServerVehicle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFourWheelServerVehicle>();
  CFourWheelServerVehicle_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C4F0
// Name: CPropVehicle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPropVehicle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPropVehicle>();
  CPropVehicle_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C570
// Name: DT_PropVehicleDriveable::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PropVehicleDriveable::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PropVehicleDriveable::g_SendTable);
  return atexit(func: DT_PropVehicleDriveable::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C590
// Name: DT_PropVehicleDriveable::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PropVehicleDriveable::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PropVehicleDriveable::ignored>();
  DT_PropVehicleDriveable::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C5A0
// Name: CPropVehicleDriveable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPropVehicleDriveable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPropVehicleDriveable>();
  CPropVehicleDriveable_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041EE50
// Name: DT_PropVehicleDriveable::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PropVehicleDriveable::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PropVehicleDriveable::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE60
// Name: _dynamic_atexit_destructor_for__r_JeepFOV__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_JeepFOV__()
{
  ConVar::~ConVar(this: &r_JeepFOV);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE70
// Name: _ServerClassInit_DT_PropVehicleDriveable::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PropVehicleDriveable::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_65;
  for ( i = 15; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE90
// Name: _DataMapInit_CFourWheelServerVehicle__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFourWheelServerVehicle__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_453);
}

//------------------------------------------------------------------------------
// Address: 0x1041EEA0
// Name: _DataMapInit_CPropVehicle__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPropVehicle__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_454);
}

//------------------------------------------------------------------------------
// Address: 0x1041EEB0
// Name: _DataMapInit_CPropVehicleDriveable__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPropVehicleDriveable__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_455);
}

//------------------------------------------------------------------------------
// Address: 0x1041EEC0
// Name: _dynamic_atexit_destructor_for__g_debug_vehiclesound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_vehiclesound__()
{
  ConVar::~ConVar(this: &g_debug_vehiclesound);
}

//------------------------------------------------------------------------------
// Address: 0x1041EED0
// Name: _dynamic_atexit_destructor_for__g_debug_vehicleexit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_vehicleexit__()
{
  ConVar::~ConVar(this: &g_debug_vehicleexit);
}

//------------------------------------------------------------------------------
// Address: 0x1041EEE0
// Name: _dynamic_atexit_destructor_for__sv_vehicle_autoaim_scale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_vehicle_autoaim_scale__()
{
  ConVar::~ConVar(this: &sv_vehicle_autoaim_scale);
}

//------------------------------------------------------------------------------
// Address: 0x1041EEF0
// Name: _dynamic_atexit_destructor_for__g_debug_npc_vehicle_roles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_npc_vehicle_roles__()
{
  ConVar::~ConVar(this: &g_debug_npc_vehicle_roles);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF00
// Name: _DataMapInit_vehicle_gear_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehicle_gear_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_456);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF10
// Name: _DataMapInit_vehicle_crashsound_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehicle_crashsound_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_457);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF20
// Name: _DataMapInit_vehiclesounds_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehiclesounds_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_458);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF30
// Name: _DataMapInit_CPassengerInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPassengerInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_459);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF40
// Name: _DataMapInit_CBaseServerVehicle__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseServerVehicle__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_460);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF50
// Name: _DataMapInit_ViewSmoothingData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ViewSmoothingData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_461);
}
