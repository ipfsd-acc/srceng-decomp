// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/bmodels.cpp
// Functions: 81
// ============================================================

#include "game\server\bmodels.h"

//------------------------------------------------------------------------------
// Address: 0x100E0D60
// Name: public: virtual struct datamap_t __near * CFuncWall::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncWall::GetDataDescMap(CFuncWall *this)
{
  return &CFuncWall::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E0D70
// Name: public: virtual void CFuncWall::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncWall::Use(
        CFuncWall *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( CBaseEntity::ShouldToggle(this, useType, currentState: this->m_nState) != 0 )
    this->m_nState = 1 - this->m_nState;
}

//------------------------------------------------------------------------------
// Address: 0x100E0DB0
// Name: public: virtual struct datamap_t __near * CFuncWallToggle::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncWallToggle::GetDataDescMap(CFuncWallToggle *this)
{
  return &CFuncWallToggle::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E0DC0
// Name: public: virtual struct datamap_t __near * CFuncVehicleClip::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncVehicleClip::GetDataDescMap(CFuncVehicleClip *this)
{
  return &CFuncVehicleClip::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E0DD0
// Name: public: virtual struct datamap_t __near * CFuncConveyor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncConveyor::GetDataDescMap(CFuncConveyor *this)
{
  return &CFuncConveyor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E0DE0
// Name: public: virtual class ServerClass __near * CFuncConveyor::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncConveyor::GetServerClass(CFuncConveyor *this)
{
  return &g_CFuncConveyor_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100E0DF0
// Name: public: void CFuncConveyor::InputToggleDirection(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncConveyor::InputToggleDirection(CFuncConveyor *this, inputdata_t *inputdata)
{
  ((void (__stdcall *)(CBaseEntity *, CBaseEntity *, int, _DWORD))this->Use)(
    a1: inputdata->pActivator,
    a2: inputdata->pCaller,
    a3: 3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100E0E20
// Name: public: virtual struct datamap_t __near * CFuncRotating::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncRotating::GetDataDescMap(CFuncRotating *this)
{
  return &CFuncRotating::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E0E30
// Name: void SendProxy_FuncRotatingSimulationTime(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_FuncRotatingSimulationTime(
        const SendProp *pProp,
        float *pStruct,
        const void *pVarData,
        DVariant *pOut)
{
  SendProxy_SimulationTime(pProp, pStruct, pVarData, pOut);
}

//------------------------------------------------------------------------------
// Address: 0x100E0E40
// Name: public: virtual class ServerClass __near * CFuncRotating::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncRotating::GetServerClass(CFuncRotating *this)
{
  return &g_CFuncRotating_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100E0E50
// Name: public: virtual void CFuncRotating::Blocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFuncRotating::Blocked(CFuncRotating *this@<ecx>, int a2@<esi>, CBaseEntity *pOther)
{
  const CTakeDamageInfo *v3; // eax
  CTakeDamageInfo v4; // [esp+10h] [ebp-5Ch] BYREF

  v3 = CTakeDamageInfo::CTakeDamageInfo(
         this: &v4,
         pInflictor: this,
         pAttacker: this,
         flDamage: this->m_flBlockDamage,
         bitsDamageType: 1,
         iKillType: 0,
         iObjectsPenetrated: 0);
  CBaseEntity::TakeDamage(this: pOther, a2, inputInfo: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100E0E90
// Name: private: virtual struct datamap_t __near * CFuncVPhysicsClip::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncVPhysicsClip::GetDataDescMap(CFuncVPhysicsClip *this)
{
  return &CFuncVPhysicsClip::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E0EE0
// Name: public: virtual void CFuncWall::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncWall::Spawn(CFuncWall *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CFuncWall *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::AddFlag(this, flags: 0x2000000);
  this->CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E0F40
// Name: public: virtual bool CFuncWall::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CFuncWall::CreateVPhysics@<al>(CFuncWall *this@<ecx>, int a2@<ebp>)
{
  IPhysicsObject *inited; // edi
  IVModelInfo_vtbl *v4; // ebx
  int v5; // eax

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  inited = CBaseEntity::VPhysicsInitStatic(this, a2);
  if ( inited != nullptr )
  {
    v4 = modelinfo->__vftable;
    v5 = this->GetModelIndex(this);
    if ( (v4->GetModelContents(this: modelinfo, a2: v5) & 0x203400B) == 0 )
      inited->EnableCollisions(this: inited, a2: false);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E0FA0
// Name: public: virtual void CFuncVehicleClip::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncVehicleClip::Spawn(CFuncVehicleClip *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CFuncVehicleClip *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::AddFlag(this, flags: 0x2000000);
  this->CreateVPhysics(this);
  CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 12);
}

//------------------------------------------------------------------------------
// Address: 0x100E1010
// Name: public: virtual bool CFuncVehicleClip::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CFuncVehicleClip::CreateVPhysics@<al>(CFuncVehicleClip *this@<ecx>, int a2@<ebp>)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CBaseEntity::VPhysicsInitStatic(this, a2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E1030
// Name: public: virtual void CFuncConveyor::GetGroundVelocityToApply(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncConveyor::GetGroundVelocityToApply(CFuncConveyor *this, Vector *vecGroundVel)
{
  float m_flSpeed; // xmm0_4
  float v3; // xmm2_4
  float v4; // xmm3_4

  m_flSpeed = this->m_flSpeed;
  v3 = this->m_vecMoveDir.y * m_flSpeed;
  v4 = this->m_vecMoveDir.z * m_flSpeed;
  vecGroundVel->x = this->m_vecMoveDir.x * m_flSpeed;
  vecGroundVel->y = v3;
  vecGroundVel->z = v4;
}

//------------------------------------------------------------------------------
// Address: 0x100E1080
// Name: public: virtual void CFuncIllusionary::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncIllusionary::Spawn(CFuncIllusionary *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  v2 = *(const char **)((int (__thiscall *)(CFuncIllusionary *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100E10D0
// Name: public: virtual bool CFuncRotating::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFuncRotating::KeyValue(CFuncRotating *this, char *szKeyName, const char *szValue)
{
  long double v4; // st7
  int v6; // xmm1_4
  float m_flVolume; // xmm0_4

  if ( szKeyName != "fanfriction" && _V_stricmp(s1: szKeyName, s2: "fanfriction") != 0 )
  {
    if ( szKeyName != "Volume" && _V_stricmp(s1: szKeyName, s2: "Volume") != 0 )
    {
      return CBaseEntity::KeyValue(this, szKeyName, szValue);
    }
    else
    {
      v6 = 0;
      this->m_flVolume = atof(nptr: szValue) * 0.1;
      m_flVolume = this->m_flVolume;
      if ( m_flVolume < 0.0 || (v6 = 1065353216, m_flVolume > 1.0) )
        m_flVolume = *(float *)&v6;
      this->m_flVolume = m_flVolume;
      return true;
    }
  }
  else
  {
    v4 = atof(nptr: szValue);
    this->m_flFanFriction = v4 * 0.01;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1190
// Name: public: virtual int CFuncRotating::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFuncRotating::DrawDebugTextOverlays(CFuncRotating *this)
{
  int result; // eax
  int v3; // edi
  float x; // xmm0_4
  float y; // xmm1_4
  float v6; // xmm1_4
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    x = this->m_vecMoveAng.x;
    if ( x == 0.0 )
    {
      y = this->m_vecMoveAng.y;
      if ( y == 0.0 )
        y = this->m_vecMoveAng.z;
    }
    else
    {
      y = this->m_vecMoveAng.x;
    }
    v6 = y * this->m_flTargetSpeed;
    if ( x == 0.0 )
    {
      x = this->m_vecMoveAng.y;
      if ( x == 0.0 )
        x = this->m_vecMoveAng.z;
    }
    V_snprintf(
      pDest: tempstr,
      maxLen: 512,
      pFormat: "Speed cur (target): %3.2f (%3.2f)",
      (float)(x * this->m_flSpeed),
      v6);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E1280
// Name: public: void CFuncVPhysicsClip::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncVPhysicsClip::InputEnable(CFuncVPhysicsClip *this, inputdata_t *inputdata)
{
  this->m_pPhysicsObject->EnableCollisions(this: this->m_pPhysicsObject, a2: true);
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x100E12A0
// Name: public: void CFuncVPhysicsClip::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncVPhysicsClip::InputDisable(CFuncVPhysicsClip *this, inputdata_t *inputdata)
{
  this->m_pPhysicsObject->EnableCollisions(this: this->m_pPhysicsObject, a2: false);
  this->m_bDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x100E1300
// Name: public: void CFuncVehicleClip::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncVehicleClip::InputEnable(CFuncVehicleClip *this, inputdata_t *data)
{
  IPhysicsObject *m_pPhysicsObject; // ecx

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: true);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
}

//------------------------------------------------------------------------------
// Address: 0x100E1330
// Name: public: void CFuncVehicleClip::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncVehicleClip::InputDisable(CFuncVehicleClip *this, inputdata_t *data)
{
  IPhysicsObject *m_pPhysicsObject; // ecx

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: false);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
}

//------------------------------------------------------------------------------
// Address: 0x100E1420
// Name: void SendProxy_FuncRotatingOrigin(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_FuncRotatingOrigin(
        const SendProp *pProp,
        $5FB8512C96CD1B8867E59BA5A9F6C5D6 *pStruct,
        const void *pData,
        DVariant *pOut)
{
  if ( (LODWORD(pStruct[63].m_Vector[1]) & 0x400) != 0 )
    pOut->___u0 = pStruct[78];
  else
    SendProxy_Origin(pProp, pStruct, pData, pOut);
}

//------------------------------------------------------------------------------
// Address: 0x100E1620
// Name: public: void CFuncRotating::HurtTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFuncRotating::HurtTouch(CFuncRotating *this@<ecx>, float a2@<ebp>, CBaseEntity *pOther)
{
  __int128 flDamage; // xmm0
  const CTakeDamageInfo *v5; // eax
  const Vector *v6; // eax
  float m_flBlockDamage; // xmm0_4
  CTakeDamageInfo v8; // [esp+24h] [ebp-78h] BYREF
  __int128 v9; // [esp+80h] [ebp-1Ch] BYREF
  Vector vecNewVelocity; // [esp+90h] [ebp-Ch] BYREF
  float retaddr; // [esp+9Ch] [ebp+0h]

  vecNewVelocity.x = a2;
  vecNewVelocity.y = retaddr;
  if ( pOther->m_takedamage.m_Value != 0 )
  {
    flDamage = 0;
    *(float *)&flDamage = fsqrt(
                            (float)((float)(this->m_vecAngVelocity.x * this->m_vecAngVelocity.x)
                                  + (float)(this->m_vecAngVelocity.y * this->m_vecAngVelocity.y))
                          + (float)(this->m_vecAngVelocity.z * this->m_vecAngVelocity.z));
    v9 = flDamage;
    *(float *)&flDamage = *(float *)&flDamage * 0.1;
    LODWORD(this->m_flBlockDamage) = flDamage;
    v5 = CTakeDamageInfo::CTakeDamageInfo(
           this: &v8,
           pInflictor: this,
           pAttacker: this,
           flDamage: *(float *)&flDamage,
           bitsDamageType: 1,
           iKillType: 0,
           iObjectsPenetrated: 0);
    CBaseEntity::TakeDamage(this: pOther, a2: (int)this, inputInfo: v5);
    if ( (pOther->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pOther, a2: (int)&vecNewVelocity);
    v6 = this->WorldSpaceCenter(this);
    *((float *)&v9 + 1) = pOther->m_vecAbsOrigin.x - v6->x;
    *((float *)&v9 + 2) = pOther->m_vecAbsOrigin.y - v6->y;
    *((float *)&v9 + 3) = pOther->m_vecAbsOrigin.z - v6->z;
    VectorNormalize(vec: (Vector *)((char *)&v9 + 4));
    m_flBlockDamage = this->m_flBlockDamage;
    *((float *)&v9 + 1) = *((float *)&v9 + 1) * m_flBlockDamage;
    *((float *)&v9 + 2) = m_flBlockDamage * *((float *)&v9 + 2);
    *((float *)&v9 + 3) = *((float *)&v9 + 3) * m_flBlockDamage;
    CBaseEntity::SetAbsVelocity(this: pOther, vecAbsVelocity: (const Vector *)((char *)&v9 + 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1770
// Name: public: void CFuncRotating::RotateMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::RotateMove(CFuncRotating *this)
{
  int v2; // ecx
  float v3; // xmm0_4
  float z; // eax
  float interval_per_tick; // xmm1_4
  QAngle avelpertick; // [esp+8h] [ebp-18h]
  QAngle avel; // [esp+14h] [ebp-Ch]

  CBaseEntity::SetMoveDoneTime(this, flDelay: 10.0);
  if ( this->m_bStopAtStartPos )
  {
    CBaseEntity::SetMoveDoneTime(this, flDelay: gpGlobals->interval_per_tick);
    v2 = 2;
    if ( this->m_vecMoveAng.x == 0.0 )
    {
      if ( this->m_vecMoveAng.y != 0.0 )
        v2 = 1;
    }
    else
    {
      v2 = 0;
    }
    v3 = (float)(unsigned __int16)(int)(float)((float)(*(&this->m_angRotation.m_Value.x + v2)
                                                     - *(&this->m_angStart.x + v2))
                                             * 182.04445)
       * 0.0054931641;
    if ( v3 > 180.0 )
      v3 = v3 - 360.0;
    z = this->m_vecAngVelocity.z;
    *(_QWORD *)&avel.x = *(_QWORD *)&this->m_vecAngVelocity.x;
    interval_per_tick = gpGlobals->interval_per_tick;
    avelpertick.x = avel.x * interval_per_tick;
    avelpertick.y = avel.y * interval_per_tick;
    avel.z = z;
    avelpertick.z = z * interval_per_tick;
    if ( COERCE_FLOAT(*(_DWORD *)(&avelpertick.x + v2) & _mask__AbsFloat_) > COERCE_FLOAT(LODWORD(v3) & _mask__AbsFloat_) )
    {
      CFuncRotating::SetTargetSpeed(this, flSpeed: 0.0);
      CBaseEntity::SetLocalAngles(this, angles: &this->m_angStart);
      this->m_bStopAtStartPos = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E18C0
// Name: public: virtual void CFuncVPhysicsClip::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncVPhysicsClip::Spawn(CFuncVPhysicsClip *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+8h] [ebp-4h] BYREF

  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  v2 = *(const char **)((int (__thiscall *)(CFuncVPhysicsClip *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::AddEffects(this, nEffects: 32);
  this->CreateVPhysics(this);
  this->m_pPhysicsObject->EnableCollisions(this: this->m_pPhysicsObject, a2: !this->m_bDisabled);
}

//------------------------------------------------------------------------------
// Address: 0x100E1950
// Name: public: bool CFuncVPhysicsClip::EntityPassesFilter(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFuncVPhysicsClip::EntityPassesFilter(CFuncVPhysicsClip *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // eax
  CBaseFilter *m_pEntity; // edx
  IPhysicsObject *m_pPhysicsObject; // ecx

  m_Index = this->m_hFilter.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (CBaseFilter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
      return CBaseFilter::PassesFilter(this: m_pEntity, pCaller: this, pEntity: pOther);
  }
  m_pPhysicsObject = pOther->m_pPhysicsObject;
  return m_pPhysicsObject != nullptr
      && pOther->m_MoveType.m_Value == 6
      && m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject);
}

//------------------------------------------------------------------------------
// Address: 0x100E19C0
// Name: public: virtual bool CFuncVPhysicsClip::ForceVPhysicsCollide(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFuncVPhysicsClip::ForceVPhysicsCollide(CFuncVPhysicsClip *this, CBaseEntity *pEntity)
{
  return CFuncVPhysicsClip::EntityPassesFilter(this, pOther: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x100E1A90
// Name: public: void CEntityOutputTemplate<float,1>::Set(float,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityOutputTemplate<float,1>::Set(
        CEntityOutputTemplate<float,1> *this,
        float value,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  variant_t::Set(this: &this->m_Value, ftype: FIELD_FLOAT, data: &value);
  CBaseEntityOutput::FireOutput(this, Value: this->m_Value, pActivator, pCaller, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100E1AF0
// Name: public: virtual void CFuncWallToggle::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncWallToggle::Spawn(CFuncWallToggle *this)
{
  const char *v2; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CFuncWallToggle *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::AddFlag(this, flags: 0x2000000);
  this->CreateVPhysics(this);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
      m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: false);
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    CBaseEntity::AddEffects(this, nEffects: 32);
  }
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x100E1BA0
// Name: protected: void CFuncRotating::InputGetSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::InputGetSpeed(CFuncRotating *this, float inputdata)
{
  float m_flSpeed; // xmm0_4
  CBaseEntity *v3; // edi
  CBaseEntity *v4; // ebx
  CEntityOutputTemplate<float,1> *p_m_OnGetSpeed; // esi

  m_flSpeed = this->m_flSpeed;
  if ( m_flSpeed < 0.0 )
    m_flSpeed = m_flSpeed * -1.0;
  v3 = *(CBaseEntity **)(LODWORD(inputdata) + 4);
  v4 = *(CBaseEntity **)LODWORD(inputdata);
  p_m_OnGetSpeed = &this->m_OnGetSpeed;
  inputdata = m_flSpeed;
  variant_t::Set(this: &this->m_OnGetSpeed.m_Value, ftype: FIELD_FLOAT, data: &inputdata);
  CBaseEntityOutput::FireOutput(
    this: p_m_OnGetSpeed,
    Value: p_m_OnGetSpeed->m_Value,
    pActivator: v4,
    pCaller: v3,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100E1C30
// Name: public: virtual void CFuncVPhysicsClip::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncVPhysicsClip::Activate(CFuncVPhysicsClip *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  void *v4; // eax

  pszValue = this->m_iFilterName.pszValue;
  if ( pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    v4 = __RTDynamicCast(
           inptr: EntityByName,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBaseFilter `RTTI Type Descriptor',
           isReference: 0);
    if ( v4 != nullptr )
    {
      this->m_hFilter.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
      CBaseEntity::Activate(this);
      return;
    }
    this->m_hFilter.m_Index = -1;
  }
  CBaseEntity::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E1CD0
// Name: public: virtual void CFuncConveyor::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncConveyor::Use(
        CFuncConveyor *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  float v5; // xmm0_4
  CNetworkVarBase<float,CFuncConveyor::NetworkVar_m_flConveyorSpeed> *p_m_flConveyorSpeed; // esi
  edict_t *m_pPev; // ecx

  LODWORD(v5) = LODWORD(this->m_flSpeed) ^ _mask__NegFloat_;
  p_m_flConveyorSpeed = &this->m_flConveyorSpeed;
  this->m_flSpeed = v5;
  if ( this->m_flConveyorSpeed.m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flConveyorSpeed->m_Value = v5;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x364u);
      p_m_flConveyorSpeed->m_Value = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1D50
// Name: public: void CFuncConveyor::InputSetSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncConveyor::InputSetSpeed(CFuncConveyor *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CFuncConveyor::NetworkVar_m_flConveyorSpeed> *p_m_flConveyorSpeed; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flConveyorSpeed = &this->m_flConveyorSpeed;
  this->m_flSpeed = flVal;
  if ( this->m_flConveyorSpeed.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flConveyorSpeed->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x364u);
      p_m_flConveyorSpeed->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1F30
// Name: public: void CFuncWallToggle::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncWallToggle::TurnOn(CFuncWallToggle *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: true);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
  v3 = this->m_fEffects.m_Value & 0xFFFFFFDF;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v3;
  }
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E1FB0
// Name: public: void CFuncWallToggle::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncWallToggle::InputToggle(CFuncWallToggle *this, inputdata_t *inputdata)
{
  BOOL v3; // edi
  IPhysicsObject *m_pPhysicsObject; // ecx

  v3 = (this->m_Collision.m_usSolidFlags.m_Value & 4) == 0;
  if ( CBaseEntity::ShouldToggle(this, useType: USE_TOGGLE, currentState: v3) != 0 )
  {
    if ( v3 )
    {
      m_pPhysicsObject = this->m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr )
        m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: false);
      CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
      CBaseEntity::AddEffects(this, nEffects: 32);
    }
    else
    {
      CFuncWallToggle::TurnOn(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2020
// Name: public: virtual void CFuncWallToggle::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncWallToggle::Use(
        CFuncWallToggle *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  BOOL v6; // edi
  IPhysicsObject *m_pPhysicsObject; // ecx

  v6 = (this->m_Collision.m_usSolidFlags.m_Value & 4) == 0;
  if ( CBaseEntity::ShouldToggle(this, useType, currentState: v6) != 0 )
  {
    if ( v6 )
    {
      m_pPhysicsObject = this->m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr )
        m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: false);
      CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
      CBaseEntity::AddEffects(this, nEffects: 32);
    }
    else
    {
      CFuncWallToggle::TurnOn(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2090
// Name: public: virtual void CFuncConveyor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncConveyor::Spawn(CFuncConveyor *this)
{
  const char *v2; // eax
  float v3; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  QAngle angMoveDir; // [esp+4h] [ebp-10h] BYREF
  float m_flSpeed; // [esp+10h] [ebp-4h] BYREF

  angMoveDir = (QAngle)this->m_vecMoveDir;
  AngleVectors(angles: &angMoveDir, forward: &this->m_vecMoveDir);
  CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CFuncConveyor *, float *))this->GetModelName)(a1: this, a2: &m_flSpeed);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::AddFlag(this, flags: 0x2000000);
  this->CreateVPhysics(this);
  if ( (this->m_spawnflags.m_Value & 1) == 0 )
    CBaseEntity::AddFlag(this, flags: 0x2000);
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  if ( this->m_flSpeed == 0.0 )
    this->m_flSpeed = 100.0;
  m_Value = this->m_flConveyorSpeed.m_Value;
  m_flSpeed = this->m_flSpeed;
  v3 = m_flSpeed;
  if ( m_Value != m_flSpeed )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flConveyorSpeed.m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x364u);
        v3 = m_flSpeed;
      }
      this->m_flConveyorSpeed.m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2400
// Name: public: void CFuncRotating::RampPitchVol(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::RampPitchVol(CFuncRotating *this)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  const char *pszValue; // eax
  float v6; // xmm0_4
  signed int v7; // ecx
  float m_flAttenuation; // xmm1_4
  edict_t *m_pPev; // esi
  EmitSound_t ep; // [esp+Ch] [ebp-74h] BYREF
  CPASAttenuationFilter filter; // [esp+54h] [ebp-2Ch] BYREF
  float attenuation; // [esp+74h] [ebp-Ch]
  int pitch; // [esp+78h] [ebp-8h]
  float fvol; // [esp+7Ch] [ebp-4h]
  int savedregs; // [esp+80h] [ebp+0h] BYREF

  v2 = COERCE_FLOAT(LODWORD(this->m_flSpeed) & _mask__AbsFloat_) / this->m_flMaxSpeed;
  v3 = this->m_flVolume * v2;
  if ( v3 >= 0.0 )
  {
    if ( v3 <= 1.0 )
      fvol = this->m_flVolume * v2;
    else
      fvol = 1.0;
  }
  else
  {
    fvol = 0.0;
  }
  v4 = (float)(v2 * 70.0) + 30.0;
  if ( v4 >= 0.0 )
  {
    if ( v4 > 255.0 )
      v4 = 255.0;
  }
  else
  {
    v4 = 0.0;
  }
  pitch = (int)v4;
  if ( (int)v4 == 100 )
    pitch = 99;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  attenuation = this->m_flAttenuation;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &this->m_vecAbsOrigin);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  CPASAttenuationFilter::Filter(this: &filter, a2: (int)&savedregs, origin: &this->m_vecAbsOrigin, attenuation);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  pszValue = this->m_NoiseRunning.pszValue;
  v6 = 0.0;
  v7 = 0;
  memset(&ep.m_pOrigin, 0, 12);
  *(_WORD *)&ep.m_bEmitCloseCaption = 1;
  ep.m_bWarnOnDirectWaveReference = false;
  ep.m_nSpeakerEntity = -1;
  memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
  ep.m_hSoundScriptHandle = -1;
  ep.m_nSoundEntryVersion = 1;
  ep.m_nChannel = 6;
  ep.m_pSoundName = pszValue;
  if ( pszValue == nullptr )
    ep.m_pSoundName = locale;
  ep.m_flVolume = fvol;
  m_flAttenuation = this->m_flAttenuation;
  if ( m_flAttenuation != 0.0 )
    v6 = (float)(20.0 / m_flAttenuation) + 50.0;
  m_pPev = this->m_Network.m_pPev;
  ep.m_SoundLevel = (int)v6;
  ep.m_nFlags = 3;
  ep.m_nPitch = pitch;
  if ( m_pPev != nullptr )
    v7 = m_pPev - gpGlobals->pEdicts;
  CBaseEntity::EmitSound(&filter, iEntIndex: v7, params: &ep);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100E25D0
// Name: public: void CFuncRotating::UpdateSpeed(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::UpdateSpeed(CFuncRotating *this, float flNewSpeed)
{
  float m_flSpeed; // xmm4_4
  float m_flMaxSpeed; // xmm0_4
  float x; // xmm0_4
  int v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  const char *pszValue; // eax
  float m_flAttenuation; // xmm1_4
  edict_t *m_pPev; // eax
  signed int v14; // eax
  const char *v15; // ecx
  edict_t *v16; // eax
  float v17; // xmm0_4
  EmitSound_t ep; // [esp+10h] [ebp-78h] BYREF
  CPASAttenuationFilter filter; // [esp+58h] [ebp-30h] BYREF
  QAngle vecAngVelocity; // [esp+78h] [ebp-10h] BYREF
  float flOldSpeed; // [esp+84h] [ebp-4h]
  int savedregs; // [esp+88h] [ebp+0h] BYREF
  float flNewSpeeda; // [esp+90h] [ebp+8h]

  m_flSpeed = this->m_flSpeed;
  m_flMaxSpeed = -this->m_flMaxSpeed;
  flOldSpeed = m_flSpeed;
  if ( m_flMaxSpeed <= flNewSpeed )
  {
    m_flMaxSpeed = this->m_flMaxSpeed;
    if ( flNewSpeed <= m_flMaxSpeed )
      m_flMaxSpeed = flNewSpeed;
  }
  this->m_flSpeed = m_flMaxSpeed;
  if ( this->m_bStopAtStartPos )
  {
    x = this->m_vecMoveAng.x;
    v6 = 2;
    if ( x == 0.0 )
    {
      if ( this->m_vecMoveAng.y != 0.0 )
        v6 = 1;
    }
    else
    {
      v6 = 0;
    }
    v7 = (float)(unsigned __int16)(int)(float)((float)(*(&this->m_angRotation.m_Value.x + v6)
                                                     - *(&this->m_angStart.x + v6))
                                             * 182.04445)
       * 0.0054931641;
    if ( v7 > 180.0 )
      v7 = v7 - 360.0;
    if ( flNewSpeed < 100.0 )
    {
      if ( flNewSpeed > 25.0 || fabs(v7) >= 1.0 )
      {
        v8 = fabs(v7);
        if ( v8 <= 90.0 )
        {
          if ( v8 < 20.0 )
            v8 = 20.0;
          if ( m_flSpeed <= 0.0 )
            v8 = -v8;
          this->m_flSpeed = v8;
        }
        else
        {
          this->m_flSpeed = m_flSpeed;
        }
      }
      else
      {
        this->m_flTargetSpeed = 0.0;
        this->m_bStopAtStartPos = false;
        this->m_flSpeed = 0.0;
        CBaseEntity::SetLocalAngles(this, angles: &this->m_angStart);
        m_flSpeed = flOldSpeed;
      }
    }
  }
  v9 = this->m_flSpeed;
  if ( m_flSpeed == 0.0 )
  {
    if ( v9 != 0.0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      flNewSpeeda = this->m_flAttenuation;
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
      CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &this->m_vecAbsOrigin);
      filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
      CPASAttenuationFilter::Filter(
        this: &filter,
        a2: (int)&savedregs,
        origin: &this->m_vecAbsOrigin,
        attenuation: flNewSpeeda);
      CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
      v10 = 0.0;
      ep.m_hSoundScriptHandle = -1;
      pszValue = this->m_NoiseRunning.pszValue;
      ep.m_nFlags = 0;
      memset(&ep.m_pOrigin, 0, 12);
      *(_WORD *)&ep.m_bEmitCloseCaption = 1;
      ep.m_bWarnOnDirectWaveReference = false;
      ep.m_nSpeakerEntity = -1;
      memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
      ep.m_nSoundEntryVersion = 1;
      ep.m_nChannel = 6;
      ep.m_pSoundName = pszValue;
      if ( pszValue == nullptr )
        ep.m_pSoundName = locale;
      ep.m_flVolume = 0.0099999998;
      m_flAttenuation = this->m_flAttenuation;
      if ( m_flAttenuation != 0.0 )
        v10 = (float)(20.0 / m_flAttenuation) + 50.0;
      m_pPev = this->m_Network.m_pPev;
      ep.m_SoundLevel = (int)v10;
      ep.m_nPitch = 30;
      if ( m_pPev != nullptr )
        v14 = m_pPev - gpGlobals->pEdicts;
      else
        v14 = 0;
      CBaseEntity::EmitSound(&filter, iEntIndex: v14, params: &ep);
      CFuncRotating::RampPitchVol(this);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      CRecipientFilter::~CRecipientFilter(this: &filter);
      goto LABEL_41;
    }
LABEL_40:
    CFuncRotating::RampPitchVol(this);
    goto LABEL_41;
  }
  if ( v9 != 0.0 )
    goto LABEL_40;
  v15 = this->m_NoiseRunning.pszValue;
  if ( v15 == nullptr )
    v15 = locale;
  v16 = this->m_Network.m_pPev;
  if ( v16 != nullptr )
    CBaseEntity::StopSound(iEntIndex: v16 - gpGlobals->pEdicts, iChannel: 6, pSample: v15, bIsStoppingSpeakerSound: 0);
  else
    CBaseEntity::StopSound(iEntIndex: 0, iChannel: 6, pSample: v15, bIsStoppingSpeakerSound: 0);
LABEL_41:
  v17 = this->m_flSpeed;
  vecAngVelocity.x = this->m_vecMoveAng.x * v17;
  vecAngVelocity.y = this->m_vecMoveAng.y * v17;
  vecAngVelocity.z = this->m_vecMoveAng.z * v17;
  CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x100E2940
// Name: public: void CFuncRotating::SpinUpMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::SpinUpMove(CFuncRotating *this)
{
  float flNewSpeed; // xmm0_4
  bool v3; // bl

  flNewSpeed = fabs(this->m_flSpeed) + this->m_flMaxSpeed * 0.2 * this->m_flFanFriction;
  v3 = false;
  if ( fabs(flNewSpeed) < fabs(this->m_flTargetSpeed) )
  {
    if ( this->m_flTargetSpeed < 0.0 )
      flNewSpeed = flNewSpeed * -1.0;
  }
  else
  {
    flNewSpeed = this->m_flTargetSpeed;
    v3 = !this->m_bStopAtStartPos;
  }
  CFuncRotating::UpdateSpeed(this, flNewSpeed);
  if ( v3 )
  {
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncRotating::RotateMove;
    CFuncRotating::RotateMove(this);
  }
  if ( this->m_bStopAtStartPos )
    CBaseEntity::SetMoveDoneTime(this, flDelay: gpGlobals->interval_per_tick);
  else
    CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
}

//------------------------------------------------------------------------------
// Address: 0x100E2A20
// Name: public: void CFuncRotating::SpinDownMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::SpinDownMove(CFuncRotating *this)
{
  bool v2; // bl
  float flNewSpeed; // xmm0_4

  v2 = false;
  flNewSpeed = fabs(this->m_flSpeed) - this->m_flMaxSpeed * 0.1 * this->m_flFanFriction;
  if ( flNewSpeed < 0.0 )
    flNewSpeed = 0.0;
  if ( fabs(this->m_flTargetSpeed) < fabs(flNewSpeed) )
  {
    if ( this->m_flSpeed < 0.0 )
      flNewSpeed = flNewSpeed * -1.0;
  }
  else
  {
    flNewSpeed = this->m_flTargetSpeed;
    v2 = !this->m_bStopAtStartPos;
  }
  CFuncRotating::UpdateSpeed(this, flNewSpeed);
  if ( v2 )
  {
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncRotating::RotateMove;
    CFuncRotating::RotateMove(this);
  }
  else if ( this->m_bStopAtStartPos )
  {
    CBaseEntity::SetMoveDoneTime(this, flDelay: gpGlobals->interval_per_tick);
  }
  else
  {
    CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2B10
// Name: public: void CFuncRotating::ReverseMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::ReverseMove(CFuncRotating *this)
{
  bool v2; // bl
  float flNewSpeed; // xmm0_4

  v2 = false;
  flNewSpeed = fabs(this->m_flSpeed) - this->m_flMaxSpeed * 0.1 * this->m_flFanFriction;
  if ( flNewSpeed < 0.0 )
    flNewSpeed = 0.0;
  if ( (float)0.0 < fabs(flNewSpeed) )
  {
    if ( this->m_flSpeed < 0.0 )
      flNewSpeed = flNewSpeed * -1.0;
  }
  else
  {
    flNewSpeed = 0.0;
    v2 = !this->m_bStopAtStartPos;
  }
  CFuncRotating::UpdateSpeed(this, flNewSpeed);
  if ( v2 )
  {
    CFuncRotating::SetTargetSpeed(this, flSpeed: this->m_flTargetSpeed);
  }
  else if ( this->m_bStopAtStartPos )
  {
    CBaseEntity::SetMoveDoneTime(this, flDelay: gpGlobals->interval_per_tick);
  }
  else
  {
    CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2C00
// Name: public: void CFuncRotating::SetTargetSpeed(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::SetTargetSpeed(CFuncRotating *this, float flSpeed)
{
  float flNewSpeed; // xmm0_4
  unsigned int v4; // eax
  float m_flSpeed; // xmm1_4
  float v6; // xmm1_4
  float v7; // xmm0_4

  flNewSpeed = fabs(flSpeed);
  if ( this->m_bReversed )
    flNewSpeed = flNewSpeed * -1.0;
  v4 = (unsigned int)this->m_spawnflags.m_Value >> 4;
  this->m_flTargetSpeed = flNewSpeed;
  if ( (v4 & 1) == 0 )
  {
    CFuncRotating::UpdateSpeed(this, flNewSpeed);
LABEL_5:
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncRotating::RotateMove;
    goto LABEL_6;
  }
  m_flSpeed = this->m_flSpeed;
  if ( (m_flSpeed <= 0.0 || flNewSpeed >= 0.0) && (m_flSpeed >= 0.0 || flNewSpeed <= 0.0) )
  {
    v6 = fabs(m_flSpeed);
    v7 = fabs(flNewSpeed);
    if ( v7 <= v6 )
    {
      if ( v6 <= v7 )
        goto LABEL_5;
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncRotating::SpinDownMove;
    }
    else
    {
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncRotating::SpinUpMove;
    }
  }
  else
  {
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncRotating::ReverseMove;
  }
LABEL_6:
  if ( this->m_bStopAtStartPos )
    CBaseEntity::SetMoveDoneTime(this, flDelay: gpGlobals->interval_per_tick);
  else
    CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
}

//------------------------------------------------------------------------------
// Address: 0x100E2CE0
// Name: public: void CFuncRotating::RotatingUse(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::RotatingUse(
        CFuncRotating *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        CBaseEntity *useType,
        float value)
{
  float flSpeed; // xmm0_4

  flSpeed = 0.0;
  if ( this->m_flSpeed == 0.0 )
    flSpeed = this->m_flMaxSpeed;
  CFuncRotating::SetTargetSpeed(this, flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x100E2D10
// Name: protected: void CFuncRotating::InputReverse(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::InputReverse(CFuncRotating *this, inputdata_t *inputdata)
{
  float flSpeed; // xmm0_4
  bool v3; // al

  flSpeed = this->m_flSpeed;
  v3 = !this->m_bReversed;
  this->m_bStopAtStartPos = false;
  this->m_bReversed = v3;
  CFuncRotating::SetTargetSpeed(this, flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x100E2D40
// Name: protected: void CFuncRotating::InputSetSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::InputSetSpeed(CFuncRotating *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  int v3; // xmm1_4
  bool v4; // al
  float v5; // xmm0_4

  this->m_bStopAtStartPos = false;
  if ( inputdata->value.fieldType != FIELD_FLOAT )
  {
    v3 = 0;
    flVal = 0.0;
    goto LABEL_5;
  }
  flVal = inputdata->value.flVal;
  v3 = 0;
  if ( flVal >= 0.0 )
  {
LABEL_5:
    v4 = false;
    goto LABEL_6;
  }
  v4 = true;
LABEL_6:
  this->m_bReversed = v4;
  LODWORD(v5) = LODWORD(flVal) & _mask__AbsFloat_;
  if ( v5 < 0.0 || (v3 = 1065353216, v5 > 1.0) )
    v5 = *(float *)&v3;
  CFuncRotating::SetTargetSpeed(this, flSpeed: this->m_flMaxSpeed * v5);
}

//------------------------------------------------------------------------------
// Address: 0x100E2DB0
// Name: protected: void CFuncRotating::InputStart(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::InputStart(CFuncRotating *this, inputdata_t *inputdata)
{
  float flSpeed; // xmm0_4

  flSpeed = this->m_flMaxSpeed;
  this->m_bStopAtStartPos = false;
  CFuncRotating::SetTargetSpeed(this, flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x100E2DD0
// Name: protected: void CFuncRotating::InputStartForward(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::InputStartForward(CFuncRotating *this, inputdata_t *inputdata)
{
  float flSpeed; // xmm0_4

  flSpeed = this->m_flMaxSpeed;
  this->m_bReversed = false;
  CFuncRotating::SetTargetSpeed(this, flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x100E2DF0
// Name: protected: void CFuncRotating::InputStartBackward(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::InputStartBackward(CFuncRotating *this, inputdata_t *inputdata)
{
  float flSpeed; // xmm0_4

  flSpeed = this->m_flMaxSpeed;
  this->m_bStopAtStartPos = false;
  this->m_bReversed = true;
  CFuncRotating::SetTargetSpeed(this, flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x100E2E20
// Name: protected: void CFuncRotating::InputStop(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::InputStop(CFuncRotating *this, inputdata_t *inputdata)
{
  this->m_bStopAtStartPos = false;
  CFuncRotating::SetTargetSpeed(this, flSpeed: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100E2E40
// Name: protected: void CFuncRotating::InputStopAtStartPos(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::InputStopAtStartPos(CFuncRotating *this, inputdata_t *inputdata)
{
  this->m_bStopAtStartPos = true;
  CFuncRotating::SetTargetSpeed(this, flSpeed: 0.0);
  if ( this->m_bStopAtStartPos )
    CBaseEntity::SetMoveDoneTime(this, flDelay: gpGlobals->interval_per_tick);
  else
    CBaseEntity::SetMoveDoneTime(this, flDelay: 0.1);
}

//------------------------------------------------------------------------------
// Address: 0x100E2EA0
// Name: protected: void CFuncRotating::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::InputToggle(CFuncRotating *this, inputdata_t *inputdata)
{
  float flSpeed; // xmm0_4

  flSpeed = 0.0;
  if ( this->m_flSpeed <= 0.0 )
    flSpeed = this->m_flMaxSpeed;
  CFuncRotating::SetTargetSpeed(this, flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x100E3690
// Name: public: virtual void CFuncRotating::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncRotating::Spawn(CFuncRotating *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  int m_Value; // ecx
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  const char *v8; // eax
  float m_flMaxSpeed; // xmm0_4
  float v10; // xmm0_4
  void (__thiscall *Precache)(struct CFuncRotating *); // edx
  CFuncRotating *v13; // [esp+18h] [ebp-4h] BYREF

  v13 = this;
  if ( this->m_flVolume == 0.0 )
    this->m_flVolume = 1.0;
  m_Value = this->m_spawnflags.m_Value;
  if ( (this->m_spawnflags.m_Value & 0x80) != 0 )
  {
    v5 = 2.0;
  }
  else if ( (m_Value & 0x100) != 0 )
  {
    v5 = 1.25;
  }
  else
  {
    v5 = 0.80000001;
  }
  this->m_flAttenuation = v5;
  if ( this->m_flFanFriction == 0.0 )
    this->m_flFanFriction = 1.0;
  if ( (m_Value & 4) != 0 )
  {
    this->m_vecMoveAng.y = 0.0;
    this->m_vecMoveAng.z = 1.0;
  }
  else
  {
    this->m_vecMoveAng.z = 0.0;
    if ( (m_Value & 8) != 0 )
    {
      this->m_vecMoveAng.x = 1.0;
      this->m_vecMoveAng.y = 0.0;
      goto LABEL_16;
    }
    this->m_vecMoveAng.y = 1.0;
  }
  this->m_vecMoveAng.x = 0.0;
LABEL_16:
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
  {
    v6 = this->m_vecMoveAng.y * -1.0;
    v7 = this->m_vecMoveAng.z * -1.0;
    this->m_vecMoveAng.x = this->m_vecMoveAng.x * -1.0;
    this->m_vecMoveAng.y = v6;
    this->m_vecMoveAng.z = v7;
  }
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  if ( (this->m_spawnflags.m_Value & 0x40) != 0 )
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  else
    CCollisionProperty::SetSolidFlags(
      this: &this->m_Collision,
      flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  v8 = *(const char **)((int (__thiscall *)(CFuncRotating *, CFuncRotating **, int, int))this->GetModelName)(
                         a1: this,
                         a2: &v13,
                         a3: a2,
                         a4: a3);
  if ( v8 == nullptr )
    v8 = locale;
  this->SetModel(this, a2: v8);
  m_flMaxSpeed = this->m_flMaxSpeed;
  this->m_pfnUse = (void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float))CFuncRotating::RotatingUse;
  LODWORD(v10) = LODWORD(m_flMaxSpeed) & _mask__AbsFloat_;
  this->m_flMaxSpeed = v10;
  if ( v10 == 0.0 )
    this->m_flMaxSpeed = 100.0;
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_CallUseToggle, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.2, szContext: nullptr);
  }
  if ( (this->m_spawnflags.m_Value & 0x20) != 0 )
    this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CFuncRotating::HurtTouch;
  Precache = this->Precache;
  this->m_flSpeed = 0.0;
  Precache(this);
  this->CreateVPhysics(this);
  this->m_angStart.x = this->m_angRotation.m_Value.x;
  this->m_angStart.y = this->m_angRotation.m_Value.y;
  this->m_angStart.z = this->m_angRotation.m_Value.z;
  if ( this->m_bSolidBsp )
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
}

//------------------------------------------------------------------------------
// Address: 0x100E3920
// Name: public: virtual void CFuncRotating::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncRotating::Precache(CFuncRotating *this)
{
  const char *v2; // eax
  const char *v3; // eax
  char pszValue[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = this->m_NoiseRunning.pszValue;
  if ( v2 == nullptr )
    v2 = locale;
  if ( this->m_NoiseRunning.pszValue == nullptr || strlen(v2) == 0 )
    this->m_NoiseRunning.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
  v3 = this->m_NoiseRunning.pszValue;
  if ( v3 == nullptr )
    v3 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v3);
  if ( vec3_angle.x != this->m_vecAngVelocity.x
    || vec3_angle.y != this->m_vecAngVelocity.y
    || vec3_angle.z != this->m_vecAngVelocity.z )
  {
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CFuncRotating::SpinUpMove;
    CBaseEntity::SetMoveDoneTime(this, flDelay: 1.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104008F0
// Name: CFuncWall_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncWall_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncWall>();
  CFuncWall_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400900
// Name: CFuncWallToggle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncWallToggle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncWallToggle>();
  CFuncWallToggle_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400930
// Name: CFuncVehicleClip_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncVehicleClip_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncVehicleClip>();
  CFuncVehicleClip_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400980
// Name: CFuncConveyor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncConveyor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncConveyor>();
  CFuncConveyor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104009B0
// Name: DT_FuncConveyor::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncConveyor::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncConveyor::g_SendTable);
  return atexit(func: DT_FuncConveyor::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104009D0
// Name: DT_FuncConveyor::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncConveyor::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncConveyor::ignored>();
  DT_FuncConveyor::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400A20
// Name: CFuncRotating_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncRotating_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncRotating>(__formal: nullptr);
  CFuncRotating_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400A50
// Name: DT_FuncRotating::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncRotating::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncRotating::g_SendTable);
  return atexit(func: DT_FuncRotating::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10400A70
// Name: DT_FuncRotating::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncRotating::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncRotating::ignored>();
  DT_FuncRotating::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400A80
// Name: CFuncVPhysicsClip_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncVPhysicsClip_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncVPhysicsClip>(__formal: nullptr);
  CFuncVPhysicsClip_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A080
// Name: DT_FuncConveyor::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncConveyor::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncConveyor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A090
// Name: DT_FuncRotating::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncRotating::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncRotating::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100E2ED0
// Name: struct datamap_t __near * DataMapInit<class CFuncVPhysicsClip>(class CFuncVPhysicsClip __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncVPhysicsClip>()
{
  if ( (_S9_0 & 1) == 0 )
  {
    _S9_0 |= 1u;
    nameHolder_105.m_pszBase = "CFuncVPhysicsClip";
    nameHolder_105.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_105.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_105.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_105.m_Names.m_Size = 0;
    nameHolder_105.m_Names.m_pElements = nullptr;
    nameHolder_105.m_nLenBase = 17;
    atexit(func: DataMapInit_CFuncVPhysicsClip__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncVPhysicsClip::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFuncVPhysicsClip::m_DataMap.dataNumFields = 5;
  CFuncVPhysicsClip::m_DataMap.dataDesc = &dataDesc_102[1];
  return &CFuncVPhysicsClip::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E2F70
// Name: struct datamap_t __near * DataMapInit<class CFuncRotating>(class CFuncRotating __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncRotating>()
{
  char *Name; // eax

  if ( (_S7_3 & 1) == 0 )
  {
    _S7_3 |= 1u;
    nameHolder_106.m_pszBase = "CFuncRotating";
    nameHolder_106.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_106.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_106.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_106.m_Names.m_Size = 0;
    nameHolder_106.m_Names.m_pElements = nullptr;
    nameHolder_106.m_nLenBase = 13;
    atexit(func: DataMapInit_CFuncRotating__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncRotating::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S7_3 & 2) == 0 )
  {
    _S7_3 |= 2u;
    dataDesc_103[13].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_106,
                                   pszIdentifier: "SpinUpMove");
    dataDesc_103[13].flags = 32;
    dataDesc_103[13].fieldOffset = 0;
    dataDesc_103[13].fieldSize = 1;
    dataDesc_103[13].externalName = nullptr;
    dataDesc_103[13].pSaveRestoreOps = nullptr;
    dataDesc_103[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::SpinUpMove;
    *(_QWORD *)&dataDesc_103[13].td = 0;
    *(_QWORD *)&dataDesc_103[13].override_field = 0;
    *(_QWORD *)&dataDesc_103[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[13].flatOffset[1] = 0;
    dataDesc_103[14].fieldType = FIELD_VOID;
    dataDesc_103[14].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_106,
                                   pszIdentifier: "SpinDownMove");
    dataDesc_103[14].fieldOffset = 0;
    dataDesc_103[14].fieldSize = 1;
    dataDesc_103[14].flags = 32;
    dataDesc_103[14].externalName = nullptr;
    dataDesc_103[14].pSaveRestoreOps = nullptr;
    dataDesc_103[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::SpinDownMove;
    *(_QWORD *)&dataDesc_103[14].td = 0;
    *(_QWORD *)&dataDesc_103[14].override_field = 0;
    *(_QWORD *)&dataDesc_103[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[14].flatOffset[1] = 0;
    dataDesc_103[15].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_106, pszIdentifier: "HurtTouch");
    dataDesc_103[15].fieldSize = 1;
    dataDesc_103[15].fieldName = Name;
    dataDesc_103[15].fieldOffset = 0;
    dataDesc_103[15].flags = 32;
    dataDesc_103[15].externalName = nullptr;
    dataDesc_103[15].pSaveRestoreOps = nullptr;
    dataDesc_103[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::HurtTouch;
    *(_QWORD *)&dataDesc_103[15].td = 0;
    *(_QWORD *)&dataDesc_103[15].override_field = 0;
    *(_QWORD *)&dataDesc_103[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[15].flatOffset[1] = 0;
    dataDesc_103[16].fieldType = FIELD_VOID;
    dataDesc_103[16].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_106,
                                   pszIdentifier: "RotatingUse");
    dataDesc_103[16].flags = 32;
    dataDesc_103[16].fieldOffset = 0;
    dataDesc_103[16].fieldSize = 1;
    dataDesc_103[16].externalName = nullptr;
    dataDesc_103[16].pSaveRestoreOps = nullptr;
    dataDesc_103[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::RotatingUse;
    *(_QWORD *)&dataDesc_103[16].td = 0;
    *(_QWORD *)&dataDesc_103[16].override_field = 0;
    *(_QWORD *)&dataDesc_103[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[16].flatOffset[1] = 0;
    dataDesc_103[17].fieldType = FIELD_VOID;
    dataDesc_103[17].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_106,
                                   pszIdentifier: "RotateMove");
    dataDesc_103[17].fieldOffset = 0;
    dataDesc_103[17].fieldSize = 1;
    dataDesc_103[17].flags = 32;
    dataDesc_103[17].externalName = nullptr;
    dataDesc_103[17].pSaveRestoreOps = nullptr;
    dataDesc_103[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::RotateMove;
    *(_QWORD *)&dataDesc_103[17].td = 0;
    *(_QWORD *)&dataDesc_103[17].override_field = 0;
    *(_QWORD *)&dataDesc_103[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[17].flatOffset[1] = 0;
    dataDesc_103[18].fieldType = FIELD_VOID;
    dataDesc_103[18].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_106,
                                   pszIdentifier: "ReverseMove");
    dataDesc_103[18].fieldSize = 1;
    dataDesc_103[18].flags = 32;
    *(_QWORD *)&dataDesc_103[18].td = 0;
    *(_QWORD *)&dataDesc_103[18].override_field = 0;
    *(_QWORD *)&dataDesc_103[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[18].flatOffset[1] = 0;
    dataDesc_103[19].fieldSize = 1;
    dataDesc_103[19].flags = 8;
    *(_QWORD *)&dataDesc_103[19].td = 0;
    *(_QWORD *)&dataDesc_103[19].override_field = 0;
    *(_QWORD *)&dataDesc_103[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[19].flatOffset[1] = 0;
    dataDesc_103[20].fieldSize = 1;
    dataDesc_103[20].flags = 8;
    dataDesc_103[21].fieldSize = 1;
    *(_QWORD *)&dataDesc_103[20].td = 0;
    *(_QWORD *)&dataDesc_103[20].override_field = 0;
    *(_QWORD *)&dataDesc_103[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[20].flatOffset[1] = 0;
    dataDesc_103[18].fieldOffset = 0;
    dataDesc_103[18].externalName = nullptr;
    dataDesc_103[18].pSaveRestoreOps = nullptr;
    dataDesc_103[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::ReverseMove;
    dataDesc_103[19].fieldType = FIELD_FLOAT;
    dataDesc_103[19].fieldName = "InputSetSpeed";
    dataDesc_103[19].fieldOffset = 0;
    dataDesc_103[19].externalName = "SetSpeed";
    dataDesc_103[19].pSaveRestoreOps = nullptr;
    dataDesc_103[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::InputSetSpeed;
    dataDesc_103[20].fieldType = FIELD_VOID;
    dataDesc_103[20].fieldName = "InputGetSpeed";
    dataDesc_103[20].fieldOffset = 0;
    dataDesc_103[20].externalName = "GetSpeed";
    dataDesc_103[20].pSaveRestoreOps = nullptr;
    dataDesc_103[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::InputGetSpeed;
    dataDesc_103[21].fieldType = FIELD_VOID;
    dataDesc_103[21].fieldName = "InputStart";
    dataDesc_103[21].fieldOffset = 0;
    dataDesc_103[21].flags = 8;
    dataDesc_103[21].externalName = "Start";
    dataDesc_103[21].pSaveRestoreOps = nullptr;
    dataDesc_103[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::InputStart;
    *(_QWORD *)&dataDesc_103[21].td = 0;
    *(_QWORD *)&dataDesc_103[21].override_field = 0;
    *(_QWORD *)&dataDesc_103[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[21].flatOffset[1] = 0;
    dataDesc_103[22].fieldType = FIELD_VOID;
    dataDesc_103[22].fieldName = "InputStop";
    dataDesc_103[22].fieldOffset = 0;
    dataDesc_103[22].fieldSize = 1;
    dataDesc_103[22].flags = 8;
    dataDesc_103[22].externalName = "Stop";
    dataDesc_103[22].pSaveRestoreOps = nullptr;
    *(_QWORD *)&dataDesc_103[22].td = 0;
    *(_QWORD *)&dataDesc_103[22].override_field = 0;
    *(_QWORD *)&dataDesc_103[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[22].flatOffset[1] = 0;
    dataDesc_103[23].fieldSize = 1;
    *(_QWORD *)&dataDesc_103[23].td = 0;
    *(_QWORD *)&dataDesc_103[23].override_field = 0;
    *(_QWORD *)&dataDesc_103[23].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[23].flatOffset[1] = 0;
    dataDesc_103[23].flags = 8;
    dataDesc_103[24].fieldSize = 1;
    *(_QWORD *)&dataDesc_103[24].td = 0;
    *(_QWORD *)&dataDesc_103[24].override_field = 0;
    *(_QWORD *)&dataDesc_103[24].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[24].flatOffset[1] = 0;
    dataDesc_103[24].flags = 8;
    dataDesc_103[25].fieldSize = 1;
    *(_QWORD *)&dataDesc_103[25].td = 0;
    *(_QWORD *)&dataDesc_103[25].override_field = 0;
    *(_QWORD *)&dataDesc_103[25].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[25].flatOffset[1] = 0;
    dataDesc_103[25].flags = 8;
    dataDesc_103[26].fieldSize = 1;
    *(_QWORD *)&dataDesc_103[26].td = 0;
    *(_QWORD *)&dataDesc_103[26].override_field = 0;
    *(_QWORD *)&dataDesc_103[26].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[26].flatOffset[1] = 0;
    dataDesc_103[22].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::InputStop;
    dataDesc_103[23].fieldType = FIELD_VOID;
    dataDesc_103[23].fieldName = "InputToggle";
    dataDesc_103[23].fieldOffset = 0;
    dataDesc_103[23].externalName = "Toggle";
    dataDesc_103[23].pSaveRestoreOps = nullptr;
    dataDesc_103[23].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::InputToggle;
    dataDesc_103[24].fieldType = FIELD_VOID;
    dataDesc_103[24].fieldName = "InputReverse";
    dataDesc_103[24].fieldOffset = 0;
    dataDesc_103[24].externalName = "Reverse";
    dataDesc_103[24].pSaveRestoreOps = nullptr;
    dataDesc_103[24].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::InputReverse;
    dataDesc_103[25].fieldType = FIELD_VOID;
    dataDesc_103[25].fieldName = "InputStartForward";
    dataDesc_103[25].fieldOffset = 0;
    dataDesc_103[25].externalName = "StartForward";
    dataDesc_103[25].pSaveRestoreOps = nullptr;
    dataDesc_103[25].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::InputStartForward;
    dataDesc_103[26].fieldType = FIELD_VOID;
    dataDesc_103[26].fieldName = "InputStartBackward";
    dataDesc_103[26].fieldOffset = 0;
    dataDesc_103[26].flags = 8;
    dataDesc_103[26].externalName = "StartBackward";
    dataDesc_103[26].pSaveRestoreOps = nullptr;
    dataDesc_103[26].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::InputStartBackward;
    dataDesc_103[27].fieldType = FIELD_VOID;
    dataDesc_103[27].fieldName = "InputStopAtStartPos";
    dataDesc_103[27].fieldOffset = 0;
    dataDesc_103[27].fieldSize = 1;
    dataDesc_103[27].flags = 8;
    dataDesc_103[27].externalName = "StopAtStartPos";
    dataDesc_103[27].pSaveRestoreOps = nullptr;
    dataDesc_103[27].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncRotating::InputStopAtStartPos;
    *(_QWORD *)&dataDesc_103[27].td = 0;
    *(_QWORD *)&dataDesc_103[27].override_field = 0;
    *(_QWORD *)&dataDesc_103[27].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_103[27].flatOffset[1] = 0;
    dataDesc_103[28].fieldType = FIELD_CUSTOM;
    dataDesc_103[28].fieldName = "m_OnGetSpeed";
    dataDesc_103[28].fieldOffset = 912;
    *(_DWORD *)&dataDesc_103[28].fieldSize = 1441793;
    dataDesc_103[28].externalName = "OnGetSpeed";
    dataDesc_103[28].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_103[28].inputFunc = 0;
    *(_QWORD *)&dataDesc_103[28].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_103[28].override_count = 0;
    *(_QWORD *)dataDesc_103[28].flatOffset = 0;
    *(_DWORD *)&dataDesc_103[28].flatGroup = 0;
  }
  CFuncRotating::m_DataMap.dataNumFields = 28;
  CFuncRotating::m_DataMap.dataDesc = &dataDesc_103[1];
  return &CFuncRotating::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10400990
// Name: _dynamic_initializer_for__g_CFuncConveyor_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncConveyor_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncConveyor_ClassReg,
           pNetworkName: "CFuncConveyor",
           pTable: &DT_FuncConveyor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10400A30
// Name: _dynamic_initializer_for__g_CFuncRotating_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncRotating_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncRotating_ClassReg,
           pNetworkName: "CFuncRotating",
           pTable: &DT_FuncRotating::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A0A0
// Name: _ServerClassInit_DT_FuncRotating::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncRotating::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S8_1;
  for ( i = 9; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A0C0
// Name: _ServerClassInit_DT_FuncConveyor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncConveyor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S6_8;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A0E0
// Name: _DataMapInit_CFuncWall__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncWall__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_101);
}

//------------------------------------------------------------------------------
// Address: 0x1041A0F0
// Name: _DataMapInit_CFuncWallToggle__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncWallToggle__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_102);
}

//------------------------------------------------------------------------------
// Address: 0x1041A100
// Name: _DataMapInit_CFuncVehicleClip__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncVehicleClip__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_103);
}

//------------------------------------------------------------------------------
// Address: 0x1041A110
// Name: _DataMapInit_CFuncConveyor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncConveyor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_104);
}

//------------------------------------------------------------------------------
// Address: 0x1041A120
// Name: _DataMapInit_CFuncRotating__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncRotating__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_106);
}

//------------------------------------------------------------------------------
// Address: 0x1041A130
// Name: _DataMapInit_CFuncVPhysicsClip__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncVPhysicsClip__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_105);
}
