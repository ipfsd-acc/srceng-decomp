// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/intermission.cpp
// Functions: 2
// ============================================================

#include "game\server\intermission.h"

//------------------------------------------------------------------------------
// Address: 0x10162A90
// Name: public: virtual void CInfoIntermission::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoIntermission::Spawn(CInfoIntermission *this)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 2.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10162AE0
// Name: public: virtual void CInfoIntermission::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoIntermission::Think(CInfoIntermission *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  QAngle angles; // [esp+4h] [ebp-18h] BYREF
  Vector dir; // [esp+10h] [ebp-Ch] BYREF

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
    dir.x = EntityByName->m_vecOrigin.m_Value.x - this->m_vecOrigin.m_Value.x;
    dir.y = EntityByName->m_vecOrigin.m_Value.y - this->m_vecOrigin.m_Value.y;
    dir.z = EntityByName->m_vecOrigin.m_Value.z - this->m_vecOrigin.m_Value.z;
    VectorNormalize(vec: &dir);
    VectorAngles(forward: &dir, &angles);
    CBaseEntity::SetLocalAngles(this, &angles);
  }
}
