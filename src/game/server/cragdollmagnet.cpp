// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cragdollmagnet.cpp
// Functions: 7
// ============================================================

#include "game\server\cragdollmagnet.h"

//------------------------------------------------------------------------------
// Address: 0x100F9D70
// Name: public: virtual struct datamap_t __near * CRagdollMagnet::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRagdollMagnet::GetDataDescMap(CRagdollMagnet *this)
{
  return &CRagdollMagnet::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F9D80
// Name: public: void CRagdollMagnet::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollMagnet::InputEnable(CRagdollMagnet *this, inputdata_t *inputdata)
{
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x100F9D90
// Name: public: void CRagdollMagnet::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollMagnet::InputDisable(CRagdollMagnet *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x100F9DA0
// Name: public: float CRagdollMagnet::DistToPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CRagdollMagnet::DistToPoint@<st0>(
        CRagdollMagnet *this@<ecx>,
        float a2@<ebp>,
        const Vector *vecPoint)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  double v6; // st7
  int m_iEFlags; // ecx
  long double v8; // st7
  float x; // xmm0_4
  _BYTE v11[12]; // [esp-Ch] [ebp-78h] BYREF
  CPlane bottom; // [esp+0h] [ebp-6Ch] BYREF
  CPlane top; // [esp+14h] [ebp-58h] BYREF
  CPlane axis; // [esp+28h] [ebp-44h] BYREF
  Vector vecUp; // [esp+40h] [ebp-2Ch] BYREF
  Vector vecRight; // [esp+4Ch] [ebp-20h] BYREF
  Vector vecAxis; // [esp+58h] [ebp-14h] BYREF
  float vDist; // [esp+64h] [ebp-8h]
  float retaddr; // [esp+6Ch] [ebp+0h]

  vecAxis.z = a2;
  vDist = retaddr;
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecAxis.z);
    v4 = this->m_axis.y - this->m_vecAbsOrigin.y;
    v5 = this->m_axis.z - this->m_vecAbsOrigin.z;
    vecRight.x = this->m_axis.x - this->m_vecAbsOrigin.x;
    vecRight.y = v4;
    vecRight.z = v5;
    VectorNormalize(vec: &vecRight);
    CPlane::CPlane(this: (CPlane *)&bottom.m_vecNormal.z);
    CPlane::CPlane(this: (CPlane *)v11);
    vecUp.x = -vecRight.x;
    vecUp.y = -vecRight.y;
    vecUp.z = -vecRight.z;
    CPlane::InitializePlane(this: (CPlane *)v11, vecNormal: &vecUp, vecPoint: &this->m_axis);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecAxis.z);
    CPlane::InitializePlane(
      this: (CPlane *)&bottom.m_vecNormal.z,
      vecNormal: &vecRight,
      vecPoint: &this->m_vecAbsOrigin);
    if ( CPlane::PointInFront(this: (CPlane *)&bottom.m_vecNormal.z, vecPoint)
      && CPlane::PointInFront(this: (CPlane *)v11, vecPoint) )
    {
      CPlane::CPlane(this: (CPlane *)&top.m_vecNormal.z);
      VectorVectors(forward: &vecRight, right: &vecUp, up: (Vector *)&axis.m_flDist);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecAxis.z);
      CPlane::InitializePlane(this: (CPlane *)&top.m_vecNormal.z, vecNormal: &vecUp, vecPoint: &this->m_vecAbsOrigin);
      v6 = CPlane::PointDist(this: (CPlane *)&top.m_vecNormal.z, vecPoint);
      m_iEFlags = this->m_iEFlags;
      vecAxis.y = fabs(v6);
      if ( (m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecAxis.z);
      CPlane::InitializePlane(
        this: (CPlane *)&top.m_vecNormal.z,
        vecNormal: (const Vector *)&axis.m_flDist,
        vecPoint: &this->m_vecAbsOrigin);
      v8 = fabs(CPlane::PointDist(this: (CPlane *)&top.m_vecNormal.z, vecPoint));
      vecAxis.x = v8;
      if ( vecAxis.y <= v8 )
        x = vecAxis.x;
      else
        x = vecAxis.y;
      vecAxis.y = x;
      return x;
    }
    else
    {
      return 3.4028235e38;
    }
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecAxis.z);
    return fsqrt(
             (float)((float)((float)(this->m_vecAbsOrigin.y - vecPoint->y)
                           * (float)(this->m_vecAbsOrigin.y - vecPoint->y))
                   + (float)((float)(this->m_vecAbsOrigin.z - vecPoint->z)
                           * (float)(this->m_vecAbsOrigin.z - vecPoint->z)))
           + (float)((float)(this->m_vecAbsOrigin.x - vecPoint->x) * (float)(this->m_vecAbsOrigin.x - vecPoint->x)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA020
// Name: public: static class CRagdollMagnet __near * CRagdollMagnet::FindBestMagnet(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CRagdollMagnet *__cdecl CRagdollMagnet::FindBestMagnet(CBaseEntity *pNPC)
{
  float v1; // xmm0_4
  CRagdollMagnet *v2; // esi
  CRagdollMagnet *v3; // ebx
  CBaseEntity *EntityByClassname; // eax
  const char *pszValue; // eax
  const Vector *v7; // eax
  double v8; // st7
  float flDist; // [esp+0h] [ebp-8h]
  float flClosestDist; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v1 = 3.4028235e38;
  v2 = nullptr;
  v3 = nullptr;
LABEL_2:
  flClosestDist = v1;
  while ( 1 )
  {
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: v2,
                          szName: "phys_ragdollmagnet");
    v2 = (CRagdollMagnet *)EntityByClassname;
    if ( EntityByClassname == nullptr )
      return v3;
    if ( LOBYTE(EntityByClassname[1].__vftable) == 0 )
    {
      pszValue = EntityByClassname->m_target.pszValue;
      if ( pszValue != nullptr )
      {
        if ( pNPC->m_iName.m_Value.pszValue == pszValue )
          return v2;
      }
      else
      {
        v7 = pNPC->WorldSpaceCenter(this: pNPC);
        v8 = CRagdollMagnet::DistToPoint(this: v2, a2: COERCE_FLOAT(&savedregs), vecPoint: v7);
        if ( flClosestDist > v8 )
        {
          v1 = v8;
          flDist = v8;
          if ( v2->m_radius >= flDist )
          {
            v3 = v2;
            goto LABEL_2;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA0C0
// Name: public: class Vector CRagdollMagnet::GetForceVector(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CRagdollMagnet::GetForceVector(CRagdollMagnet *this, Vector *result, CBaseEntity *pNPC)
{
  CBaseEntity *v4; // edi
  const Vector *v5; // eax
  float *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  const Vector *v10; // eax
  float m_force; // xmm0_4
  ConVar *m_pParent; // eax
  float v13; // xmm2_4
  float v14; // xmm1_4
  IPhysicsObject *m_pPhysicsObject; // ecx
  const char *pszValue; // edi
  double v17; // st7
  const char *v19; // [esp+8h] [ebp-3Ch]
  CPlane axis; // [esp+18h] [ebp-2Ch] BYREF
  Vector vecClosest; // [esp+2Ch] [ebp-18h] BYREF
  Vector vecForce; // [esp+38h] [ebp-Ch] BYREF
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  if ( (this->m_spawnflags.m_Value & 2) != 0 )
  {
    CPlane::CPlane(this: &axis);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v4 = pNPC;
    v5 = pNPC->WorldSpaceCenter(this: pNPC);
    CalcClosestPointOnLineSegment(
      P: v5,
      vLineA: &this->m_vecAbsOrigin,
      vLineB: &this->m_axis,
      vClosest: &vecClosest,
      outT: nullptr);
    v6 = (float *)v4->WorldSpaceCenter(this: v4);
    v7 = vecClosest.x - *v6;
    v8 = vecClosest.y - v6[1];
    v9 = vecClosest.z - v6[2];
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v4 = pNPC;
    v10 = pNPC->WorldSpaceCenter(this: pNPC);
    v7 = this->m_vecAbsOrigin.x - v10->x;
    v8 = this->m_vecAbsOrigin.y - v10->y;
    v9 = this->m_vecAbsOrigin.z - v10->z;
  }
  vecForce.x = v7;
  vecForce.y = v8;
  vecForce.z = v9;
  VectorNormalize(vec: &vecForce);
  m_force = this->m_force;
  m_pParent = ai_debug_ragdoll_magnets.m_pParent;
  v13 = vecForce.y * m_force;
  v14 = vecForce.x * m_force;
  result->z = vecForce.z * m_force;
  result->y = v13;
  result->x = v14;
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
  {
    m_pPhysicsObject = v4->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      pszValue = v4->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v17 = ((double (__thiscall *)(IPhysicsObject *, const char *))m_pPhysicsObject->GetMass)(
              a1: m_pPhysicsObject,
              a2: pszValue);
      _Msg(a1: "Ragdoll magnet adding %f inches/sec to %s\n", this->m_force / v17, v19);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104017D0
// Name: CRagdollMagnet_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRagdollMagnet_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRagdollMagnet>();
  CRagdollMagnet_DataDescInit::g_DataMapHolder = result;
  return result;
}
