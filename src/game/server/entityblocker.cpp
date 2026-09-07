// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/entityblocker.cpp
// Functions: 3
// ============================================================

#include "game\server\entityblocker.h"

//------------------------------------------------------------------------------
// Address: 0x1010AD30
// Name: public: static class CEntityBlocker __near * CEntityBlocker::Create(class Vector const __near &,class Vector const __near &,class Vector const __near &,class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CEntityBlocker *__cdecl CEntityBlocker::Create(
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        CBaseEntity *pOwner,
        bool bBlockPhysics)
{
  CEntityBlocker *result; // eax
  CEntityBlocker *v6; // esi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  result = (CEntityBlocker *)CBaseEntity::Create(
                               szName: "entity_blocker",
                               vecOrigin: origin,
                               vecAngles: &vec3_angle,
                               pOwner);
  v6 = result;
  if ( result != nullptr )
  {
    CBaseEntity::SetSize(this: result, mins, maxs);
    if ( bBlockPhysics )
      CBaseEntity::VPhysicsInitStatic(this: v6, a2: (int)&savedregs);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010AD80
// Name: public: virtual void CEntityBlocker::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityBlocker::Spawn(CEntityBlocker *this)
{
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // esi

  p_m_Collision = &this->m_Collision;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: p_m_Collision, flags: p_m_Collision->m_usSolidFlags.m_Value | 1);
}

//------------------------------------------------------------------------------
// Address: 0x1010ADB0
// Name: void CC_Test_Entity_Blocker(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Test_Entity_Blocker()
{
  CBasePlayer *CommandClient; // esi
  unsigned int v1; // eax
  float x; // xmm0_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v5; // xmm1_4
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  float v7; // xmm2_4
  float v8; // xmm0_4
  const CViewVectors *v9; // eax
  Vector *v10; // esi
  Vector *p_m_vHullMin; // edi
  CBaseEntity *v12; // eax
  CBaseEntity *v13; // ebx
  const CViewVectors *v14; // eax
  Vector *v15; // [esp-8h] [ebp-9Ch]
  const Vector *p_m_vHullMax; // [esp+4h] [ebp-90h]
  CGameTrace tr; // [esp+1Ch] [ebp-78h] BYREF
  Vector vecAbsStart; // [esp+70h] [ebp-24h] BYREF
  Vector vecForward; // [esp+7Ch] [ebp-18h] BYREF
  Vector vecAbsEnd; // [esp+88h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+94h] [ebp+0h] BYREF

  CommandClient = UTIL_GetCommandClient();
  CommandClient->GetVectors(this: CommandClient, a2: &vecForward, a3: nullptr, a4: nullptr);
  v1 = (unsigned int)CommandClient->m_iEFlags >> 11;
  x = vecForward.x * 256.0;
  y = vecForward.y * 256.0;
  z = vecForward.z * 256.0;
  vecAbsEnd.x = vecForward.x * 256.0;
  vecAbsEnd.y = vecForward.y * 256.0;
  vecAbsEnd.z = vecForward.z * 256.0;
  if ( (v1 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this: CommandClient, a2: (int)&savedregs);
    x = vecAbsEnd.x;
    y = vecAbsEnd.y;
    z = vecAbsEnd.z;
  }
  v5 = CommandClient->m_vecAbsOrigin.x + x;
  GetViewVectors = g_pGameRules->GetViewVectors;
  v7 = CommandClient->m_vecAbsOrigin.y + y;
  v8 = CommandClient->m_vecAbsOrigin.z + z;
  vecAbsEnd.x = v5;
  vecAbsEnd.y = v7;
  vecAbsEnd.z = v8 - 256.0;
  vecAbsStart.x = v5;
  vecAbsStart.y = v7;
  vecAbsStart.z = v8 + 256.0;
  p_m_vHullMax = &GetViewVectors(this: g_pGameRules)->m_vHullMax;
  v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)CommandClient,
    &vecAbsStart,
    &vecAbsEnd,
    hullMin: &v9->m_vHullMin,
    hullMax: p_m_vHullMax,
    mask: 0x200400Bu,
    ignore: CommandClient,
    collisionGroup: 0,
    ptr: &tr);
  if ( !tr.allsolid && !tr.startsolid )
  {
    v10 = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
    p_m_vHullMin = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
    v12 = CBaseEntity::Create(szName: "entity_blocker", vecOrigin: &tr.endpos, vecAngles: &vec3_angle, pOwner: nullptr);
    v13 = v12;
    if ( v12 != nullptr )
    {
      CBaseEntity::SetSize(this: v12, mins: p_m_vHullMin, maxs: v10);
      CBaseEntity::VPhysicsInitStatic(this: v13, a2: (int)&savedregs);
    }
    v15 = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
    v14 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    NDebugOverlay::Box(
      origin: &tr.endpos,
      mins: &v14->m_vHullMin,
      maxs: v15,
      r: 0,
      g: 255,
      b: 0,
      a: 64,
      flDuration: 1000.0);
  }
}
