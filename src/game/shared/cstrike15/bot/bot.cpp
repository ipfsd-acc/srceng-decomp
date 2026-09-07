// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/bot/bot.cpp
// Functions: 6
// ============================================================

#include "game\shared\cstrike15\bot\bot.h"

//------------------------------------------------------------------------------
// Address: 0x102CBA00
// Name: public: void ActiveGrenade::OnEntityGone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ActiveGrenade::OnEntityGone(ActiveGrenade *this)
{
  if ( this->m_isSmoke )
    this->m_dieTimestamp = gpGlobals->curtime + 4.0;
  this->m_entity = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CBA30
// Name: public: bool ActiveGrenade::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall ActiveGrenade::IsValid(ActiveGrenade *this)
{
  if ( this->m_isSmoke )
  {
    if ( this->m_entity == nullptr && gpGlobals->curtime > this->m_dieTimestamp )
      return 0;
  }
  else if ( this->m_entity == nullptr )
  {
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102CBA60
// Name: public: ActiveGrenade::ActiveGrenade(class CBaseGrenade __near *)
// Source: json
//------------------------------------------------------------------------------
ActiveGrenade *__thiscall ActiveGrenade::ActiveGrenade(ActiveGrenade *this, CBaseGrenade *grenadeEntity)
{
  const char *pszValue; // eax
  bool v4; // al
  const char *v5; // eax
  bool v6; // al
  const char *v7; // eax
  bool v8; // al
  const char *v9; // eax
  bool v10; // al
  bool v11; // zf
  ActiveGrenade *result; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  this->m_entity = grenadeEntity;
  if ( (grenadeEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: grenadeEntity, a2: (int)&savedregs);
  this->m_detonationPosition = grenadeEntity->m_vecAbsOrigin;
  this->m_dieTimestamp = 0.0;
  this->m_radius = 115.0;
  pszValue = grenadeEntity->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v4 = pszValue == "smokegrenade_projectile" || _V_stricmp(s1: pszValue, s2: "smokegrenade_projectile") == 0;
  this->m_isSmoke = v4;
  if ( v4 )
    this->m_radius = 155.0;
  v5 = grenadeEntity->m_iClassname.pszValue;
  if ( v5 == nullptr )
    v5 = locale;
  v6 = v5 == "flashbang_projectile" || _V_stricmp(s1: v5, s2: "flashbang_projectile") == 0;
  this->m_isFlashbang = v6;
  if ( v6 )
    this->m_radius = 115.0;
  v7 = grenadeEntity->m_iClassname.pszValue;
  if ( v7 == nullptr )
    v7 = locale;
  v8 = v7 == "molotov_projectile" || _V_stricmp(s1: v7, s2: "molotov_projectile") == 0;
  this->m_isMolotov = v8;
  if ( v8 )
    this->m_radius = 115.0;
  v9 = grenadeEntity->m_iClassname.pszValue;
  if ( v9 == nullptr )
    v9 = locale;
  v10 = v9 == "decoy_projectile" || _V_stricmp(s1: v9, s2: "decoy_projectile") == 0;
  this->m_isDecoy = v10;
  v11 = !v10;
  result = this;
  if ( !v11 )
    this->m_radius = 115.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CBBC0
// Name: public: void ActiveGrenade::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ActiveGrenade::Update(ActiveGrenade *this@<ecx>, int a2@<ebp>)
{
  CBaseGrenade *m_entity; // esi

  m_entity = this->m_entity;
  if ( this->m_entity != nullptr )
  {
    if ( (m_entity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_entity, a2);
    this->m_detonationPosition.x = m_entity->m_vecAbsOrigin.x;
    this->m_detonationPosition.y = m_entity->m_vecAbsOrigin.y;
    this->m_detonationPosition.z = m_entity->m_vecAbsOrigin.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CBC00
// Name: public: class Vector const __near & ActiveGrenade::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall ActiveGrenade::GetPosition@<eax>(ActiveGrenade *this@<ecx>, int a2@<ebp>)
{
  CBaseGrenade *m_entity; // esi

  m_entity = this->m_entity;
  if ( this->m_entity == nullptr )
    return &this->m_detonationPosition;
  if ( (m_entity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_entity, a2);
  return &m_entity->m_vecAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x102CBC30
// Name: __CreateCServerGameTagsIServerGameTags_interface_32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_32()
{
  return &_g_CServerGameTags_singleton_32;
}
