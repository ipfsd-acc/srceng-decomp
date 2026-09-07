// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/pointhurt.cpp
// Functions: 8
// ============================================================

#include "game\server\pointhurt.h"

//------------------------------------------------------------------------------
// Address: 0x101DAB40
// Name: public: virtual struct datamap_t __near * CPointHurt::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointHurt::GetDataDescMap(CPointHurt *this)
{
  return &CPointHurt::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DAB50
// Name: public: void CPointHurt::HurtThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointHurt::HurtThink(CPointHurt *this)
{
  unsigned int m_Index; // eax
  CBasePlayer *EntityByName; // edi
  CBaseEntity *m_pEntity; // ecx
  unsigned int v5; // eax
  CBaseEntity *v6; // ecx
  const char *pszValue; // eax
  const CTakeDamageInfo *v8; // eax
  float flRadius; // [esp+14h] [ebp-7Ch]
  CTakeDamageInfo info; // [esp+28h] [ebp-68h] BYREF
  Vector vecForceDir; // [esp+84h] [ebp-Ch] BYREF
  int savedregs; // [esp+90h] [ebp+0h] BYREF

  if ( this->m_strTarget.pszValue != nullptr )
  {
    m_Index = this->m_pActivator.m_Index;
    EntityByName = nullptr;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    CTakeDamageInfo::CTakeDamageInfo(
      this: &info,
      pInflictor: this,
      pAttacker: m_pEntity,
      flDamage: (float)this->m_nDamage,
      bitsDamageType: this->m_bitsDamageType,
      iKillType: 0,
      iObjectsPenetrated: 0);
    while ( 1 )
    {
      v5 = this->m_pActivator.m_Index;
      if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        v6 = nullptr;
      else
        v6 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      pszValue = this->m_strTarget.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: EntityByName,
                       szName: pszValue,
                       pSearchingEntity: nullptr,
                       pActivator: v6,
                       pCaller: nullptr,
                       pFilter: nullptr);
      if ( EntityByName == nullptr )
        break;
      if ( (EntityByName->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (EntityByName->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
      vecForceDir.x = EntityByName->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
      vecForceDir.y = EntityByName->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
      vecForceDir.z = EntityByName->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
      GuessDamageForce(&info, &vecForceDir, vecForceOrigin: &EntityByName->m_vecAbsOrigin, flScale: 1.0);
      CBaseEntity::TakeDamage(this: EntityByName, a2: (int)this, inputInfo: &info);
    }
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    flRadius = this->m_flRadius;
    v8 = CTakeDamageInfo::CTakeDamageInfo(
           this: &info,
           pInflictor: this,
           pAttacker: this,
           flDamage: (float)this->m_nDamage,
           bitsDamageType: this->m_bitsDamageType,
           iKillType: 0,
           iObjectsPenetrated: 0);
    RadiusDamage(info: v8, vecSrc: &this->m_vecAbsOrigin, flRadius, iClassIgnore: 0, pEntityIgnore: nullptr);
  }
  CBaseEntity::SetNextThink(this, thinkTime: this->m_flDelay + gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101DAD50
// Name: public: void CPointHurt::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointHurt::InputTurnOn(CPointHurt *this, inputdata_t *data)
{
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CPointHurt::HurtThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  if ( data->pActivator != nullptr )
    this->m_pActivator.m_Index = data->pActivator->GetRefEHandle(this: data->pActivator)->m_Index;
  else
    this->m_pActivator.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x101DADC0
// Name: public: void CPointHurt::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointHurt::InputTurnOff(CPointHurt *this, inputdata_t *data)
{
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  if ( data->pActivator != nullptr )
    this->m_pActivator.m_Index = data->pActivator->GetRefEHandle(this: data->pActivator)->m_Index;
  else
    this->m_pActivator.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x101DAE10
// Name: public: void CPointHurt::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointHurt::InputToggle(CPointHurt *this, inputdata_t *data)
{
  if ( data->pActivator != nullptr )
    this->m_pActivator.m_Index = data->pActivator->GetRefEHandle(this: data->pActivator)->m_Index;
  else
    this->m_pActivator.m_Index = -1;
  if ( (void (__thiscall *)(CPointHurt *))this->m_pfnThink == CPointHurt::HurtThink )
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  else
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CPointHurt::HurtThink,
      thinkTime: 0.0,
      szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101DAE70
// Name: public: void CPointHurt::InputHurt(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointHurt::InputHurt(CPointHurt *this, inputdata_t *data)
{
  if ( data->pActivator != nullptr )
    this->m_pActivator.m_Index = data->pActivator->GetRefEHandle(this: data->pActivator)->m_Index;
  else
    this->m_pActivator.m_Index = -1;
  CPointHurt::HurtThink(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DAEB0
// Name: public: virtual void CPointHurt::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointHurt::Spawn(CPointHurt *this)
{
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->m_pfnUse = nullptr;
  this->m_pActivator.m_Index = -1;
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CPointHurt::HurtThink,
      thinkTime: 0.0,
      szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  if ( this->m_flRadius <= 0.0 )
    this->m_flRadius = 128.0;
  if ( this->m_nDamage <= 0 )
    this->m_nDamage = 2;
  if ( this->m_flDelay <= 0.0 )
    this->m_flDelay = 0.1;
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x10408930
// Name: CPointHurt_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointHurt_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointHurt>();
  CPointHurt_DataDescInit::g_DataMapHolder = result;
  return result;
}
