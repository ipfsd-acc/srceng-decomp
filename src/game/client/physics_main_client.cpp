// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/physics_main_client.cpp
// Functions: 10
// ============================================================

#include "game\client\physics_main_client.h"

//------------------------------------------------------------------------------
// Address: 0x1013F6D0
// Name: public: void C_BaseEntity::PhysicsStep(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsStep(C_BaseEntity *this)
{
  C_BaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_ALL_BUT_BASE);
  C_BaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_BASE_ONLY);
}

//------------------------------------------------------------------------------
// Address: 0x1013F6F0
// Name: private: void C_BaseEntity::PhysicsNoclip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsNoclip(C_BaseEntity *this)
{
  C_BaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_ALL_FUNCTIONS);
}

//------------------------------------------------------------------------------
// Address: 0x1013F700
// Name: public: virtual void C_BaseEntity::Touch(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Touch(C_BaseEntity *this, C_BaseEntity *pOther)
{
  void (__thiscall *m_pfnTouch)(char *, C_BaseEntity *); // edx

  m_pfnTouch = (void (__thiscall *)(char *, C_BaseEntity *))this->m_pfnTouch;
  if ( m_pfnTouch != nullptr )
    m_pfnTouch(a1: (char *)this + DWORD1(this->m_pfnTouch), a2: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x1013F730
// Name: public: void C_BaseEntity::SetCheckUntouch(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetCheckUntouch(C_BaseEntity *this, bool check)
{
  int m_iEFlags; // eax

  if ( check )
  {
    m_iEFlags = this->m_iEFlags;
    ++this->touchStamp;
    if ( (m_iEFlags & 0x1000000) == 0 )
      this->m_iEFlags = m_iEFlags | 0x1000000;
  }
  else
  {
    this->m_iEFlags &= ~0x1000000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F770
// Name: public: bool C_BaseEntity::GetCheckUntouch(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetCheckUntouch(C_BaseEntity *this)
{
  return HIBYTE(this->m_iEFlags) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013F780
// Name: public: void C_BaseEntity::PhysicsDispatchThink(void (C_BaseEntity::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BaseEntity::PhysicsDispatchThink(C_BaseEntity *this@<ecx>, int a2@<esi>, __int128 thinkFunc)
{
  double v4; // st7
  char *Classname; // eax
  const char *v6; // [esp-4h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-10h]
  double time; // [esp+Ch] [ebp-Ch]
  float time_4; // [esp+10h] [ebp-8h]
  float thinkLimit; // [esp+14h] [ebp-4h]

  v7 = a2;
  thinkLimit = think_limit.m_pParent->m_Value.m_fValue;
  time = 0.0;
  if ( thinkLimit != 0.0 )
    time = _Plat_FloatTime(a1: v7);
  if ( (_DWORD)thinkFunc != 0 )
    ((void (__thiscall *)(char *))thinkFunc)(a1: (char *)this + DWORD1(thinkFunc));
  if ( thinkLimit != 0.0 )
  {
    v4 = (_Plat_FloatTime(a1: v7) - time) * 1000.0;
    if ( v4 > thinkLimit )
    {
      v6 = type_info::raw_name(this: &C_BaseEntity * `RTTI Type Descriptor');
      Classname = C_BaseEntity::GetClassname(this);
      time_4 = v4;
      _Msg(a1: "CLIENT:  %s(%s) thinking for %.02f ms!!!\n", Classname, v6, time_4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F830
// Name: private: void C_BaseEntity::PhysicsCheckSweep(class Vector const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsCheckSweep(
        C_BaseEntity *this,
        const Vector *vecAbsStart,
        const Vector *vecAbsDelta,
        CGameTrace *pTrace)
{
  unsigned int v5; // eax
  bool v6; // zf
  float x; // xmm0_4
  const Vector *v8; // ebx
  const Vector *v9; // eax
  Vector vecAbsEnd; // [esp+Ch] [ebp-10h] BYREF
  unsigned int mask; // [esp+18h] [ebp-4h]
  IHandleEntity savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v5 = this->PhysicsSolidMaskForEntity(this);
  v6 = this->m_Collision.m_nSolidType.m_Value == 0;
  x = vecAbsStart->x;
  mask = v5;
  vecAbsEnd.x = x + vecAbsDelta->x;
  vecAbsEnd.y = vecAbsStart->y + vecAbsDelta->y;
  vecAbsEnd.z = vecAbsStart->z + vecAbsDelta->z;
  if ( v6
    || (this->m_Collision.m_usSolidFlags.m_Value & 4) != 0
    || (this->m_Collision.m_usSolidFlags.m_Value & 0x20) != 0 )
  {
    mask &= ~0x2000000u;
  }
  v8 = this->WorldAlignMaxs(this);
  v9 = this->WorldAlignMins(this);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart,
    &vecAbsEnd,
    hullMin: v9,
    hullMax: v8,
    mask,
    ignore: this,
    collisionGroup: this->m_CollisionGroup,
    ptr: pTrace);
}

//------------------------------------------------------------------------------
// Address: 0x1013F8F0
// Name: public: void C_BaseEntity::PhysicsPushEntity(class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsPushEntity(C_BaseEntity *this, const Vector *push, CGameTrace *pTrace)
{
  struct CBaseEntity *m_pEnt; // eax
  Vector prevOrigin; // [esp+8h] [ebp-Ch] BYREF

  prevOrigin = *this->GetAbsOrigin(this);
  C_BaseEntity::PhysicsCheckSweep(this, vecAbsStart: &prevOrigin, vecAbsDelta: push, pTrace);
  if ( pTrace->fraction != 0.0 )
    C_BaseEntity::SetAbsOrigin(this, absOrigin: &pTrace->endpos);
  this->m_vecNetworkOrigin = *C_BaseEntity::GetLocalOrigin(this);
  this->m_angNetworkAngles = *C_BaseEntity::GetLocalAngles(this);
  m_pEnt = pTrace->m_pEnt;
  if ( m_pEnt != nullptr )
    C_BaseEntity::PhysicsImpact(this, other: (C_BaseEntity *)m_pEnt, trace: pTrace);
}

//------------------------------------------------------------------------------
// Address: 0x1013F9B0
// Name: private: void C_BaseEntity::PhysicsCustom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsCustom(C_BaseEntity *this)
{
  C_BaseEntity *GroundEntity; // eax
  Vector *v3; // eax
  float z; // ecx
  C_BaseEntity_vtbl *v5; // edx
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // eax
  int v7; // eax
  float v8; // edx
  float v9; // ecx
  __int64 v10; // xmm0_8
  void (__thiscall *PerformCustomPhysics)(C_BaseEntity *, Vector *, Vector *, QAngle *, QAngle *); // eax
  const Vector *v12; // eax
  CGameTrace trace; // [esp+4h] [ebp-90h] BYREF
  Vector move; // [esp+58h] [ebp-3Ch] BYREF
  QAngle angNewAngles; // [esp+64h] [ebp-30h] BYREF
  Vector vecNewVelocity; // [esp+70h] [ebp-24h] BYREF
  QAngle angNewAngVelocity; // [esp+7Ch] [ebp-18h] BYREF
  Vector vecNewPosition; // [esp+88h] [ebp-Ch] BYREF

  C_BaseEntity::PhysicsCheckWater(this);
  if ( C_BaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_ALL_FUNCTIONS) )
  {
    if ( this->m_vecVelocity.z > 0.0
      || C_BaseEntity::GetGroundEntity(this) == nullptr
      || (GroundEntity = C_BaseEntity::GetGroundEntity(this), !C_BaseEntity::IsStandable(this: GroundEntity)) )
    {
      C_BaseEntity::SetGroundEntity(this, ground: nullptr);
    }
    v3 = this->GetAbsOrigin(this);
    z = this->m_vecVelocity.z;
    v5 = this->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    vecNewPosition = *v3;
    GetAbsAngles = v5->GetAbsAngles;
    vecNewVelocity.z = z;
    *(_QWORD *)&vecNewVelocity.x = *(_QWORD *)&this->m_vecVelocity.x;
    v7 = (int)GetAbsAngles(this);
    v8 = this->m_vecAngVelocity.z;
    *(_QWORD *)&angNewAngles.x = *(_QWORD *)v7;
    v9 = *(float *)(v7 + 8);
    v10 = *(_QWORD *)&this->m_vecAngVelocity.x;
    PerformCustomPhysics = this->PerformCustomPhysics;
    angNewAngles.z = v9;
    angNewAngVelocity.z = v8;
    *(_QWORD *)&angNewAngVelocity.x = v10;
    PerformCustomPhysics(this, a2: &vecNewPosition, a3: &vecNewVelocity, a4: &angNewAngles, a5: &angNewAngVelocity);
    this->m_vecVelocity = vecNewVelocity;
    C_BaseEntity::SetAbsAngles(this, absAngles: &angNewAngles);
    this->m_vecAngVelocity = angNewAngVelocity;
    v12 = this->GetAbsOrigin(this);
    move.x = vecNewPosition.x - v12->x;
    move.y = vecNewPosition.y - v12->y;
    move.z = vecNewPosition.z - v12->z;
    C_BaseEntity::PhysicsPushEntity(this, push: &move, pTrace: &trace);
    C_BaseEntity::PhysicsCheckVelocity(this);
    if ( trace.allsolid )
    {
      this->m_vecVelocity = vec3_origin;
      this->m_vecAngVelocity = vec3_angle;
    }
    else
    {
      C_BaseEntity::PhysicsCheckWaterTransition(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC140
// Name: private: virtual void C_BaseEntity::PerformCustomPhysics(class Vector __near *,class Vector __near *,class QAngle __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PerformCustomPhysics(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}
