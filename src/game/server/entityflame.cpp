// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/entityflame.cpp
// Functions: 32
// ============================================================

#include "game\server\entityflame.h"

//------------------------------------------------------------------------------
// Address: 0x1010C1D0
// Name: public: virtual struct datamap_t __near * CEntityFlame::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEntityFlame::GetDataDescMap(CEntityFlame *this)
{
  return &CEntityFlame::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010C1E0
// Name: public: virtual class ServerClass __near * CEntityFlame::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEntityFlame::GetServerClass(CEntityFlame *this)
{
  return &g_CEntityFlame_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1010C1F0
// Name: public: virtual void entityflamePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall entityflamePrecache::CResourcePrecacher::Cache(
        entityflamePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "entityflame",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1010C220
// Name: public: virtual struct datamap_t __near * CEnvEntityIgniter::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvEntityIgniter::GetDataDescMap(CEnvEntityIgniter *this)
{
  return &CEnvEntityIgniter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010C230
// Name: public: virtual void CEntityFlame::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFlame::Precache(CEntityFlame *this)
{
  PrecacheParticleSystem(pParticleSystemName: "burning_character");
  PrecacheParticleSystem(pParticleSystemName: "burning_gib_01");
  CBaseEntity::PrecacheScriptSound(soundname: "General.StopBurning");
  CBaseEntity::PrecacheScriptSound(soundname: "General.BurningFlesh");
  CBaseEntity::PrecacheScriptSound(soundname: "General.BurningObject");
}

//------------------------------------------------------------------------------
// Address: 0x1010C270
// Name: public: float CEntityFlame::GetRemainingLife(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEntityFlame::GetRemainingLife(CEntityFlame *this)
{
  return this->m_flLifetime.m_Value - gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x1010C280
// Name: public: virtual void CEnvEntityIgniter::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityIgniter::Precache(CEnvEntityIgniter *this)
{
  UTIL_PrecacheOther(szClassname: "entityflame", modelName: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1010C3A0
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CEntityFlame::NetworkVar_m_hEntAttached>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CEntityFlame::NetworkVar_m_hEntAttached>::Set(
        CNetworkHandleBase<CBaseEntity,CSprite::NetworkVar_m_hAttachedToEntity> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CSprite::NetworkVar_m_hAttachedToEntity> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 213;
    if ( *((_BYTE *)this - 768) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x354u);
    }
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x1010C430
// Name: public: virtual void CEntityFlame::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFlame::UpdateOnRemove(CEntityFlame *this)
{
  int m_Size; // edx
  int i; // eax
  CAI_Link *v4; // ecx

  if ( this->m_bPlayingSound )
  {
    CBaseEntity::EmitSound(this, soundname: "General.StopBurning", soundtime: 0.0, duration: nullptr);
    this->m_bPlayingSound = false;
  }
  if ( this->m_iDangerSound != -1 )
  {
    CSoundEnt::FreeSound(iSound: this->m_iDangerSound);
    this->m_iDangerSound = -1;
  }
  m_Size = this->m_DangerLinks.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_DangerLinks.m_Memory.m_pMemory[i];
    --v4->m_nDangerCount;
  }
  this->m_DangerLinks.m_Size = 0;
  if ( this->m_hObstacle != nullptr )
  {
    CAI_LocalNavigator::RemoveGlobalObstacle(hObstacle: this->m_hObstacle);
    this->m_hObstacle = nullptr;
  }
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010C4D0
// Name: public: void CEntityFlame::UseCheapEffect(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFlame::UseCheapEffect(CEntityFlame *this, bool bCheap)
{
  CNetworkVarBase<bool,CEntityFlame::NetworkVar_m_bCheapEffect> *p_m_bCheapEffect; // esi
  edict_t *m_pPev; // ecx

  p_m_bCheapEffect = &this->m_bCheapEffect;
  if ( this->m_bCheapEffect.m_Value != bCheap )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bCheapEffect->m_Value = bCheap;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
      p_m_bCheapEffect->m_Value = bCheap;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C520
// Name: public: void CEntityFlame::AttachToEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFlame::AttachToEntity(CEntityFlame *this, CBaseEntity *pTarget)
{
  void (__thiscall *SetParent)(struct CEntityFlame *, CBaseEntity *, int); // edx

  CNetworkHandleBase<CBaseEntity,CEntityFlame::NetworkVar_m_hEntAttached>::Set(
    this: (CNetworkHandleBase<CBaseEntity,CSprite::NetworkVar_m_hAttachedToEntity> *)&this->m_hEntAttached,
    val: pTarget);
  if ( pTarget->IsNPC(this: pTarget) )
    CBaseEntity::EmitSound(this, soundname: "General.BurningFlesh", soundtime: 0.0, duration: nullptr);
  else
    CBaseEntity::EmitSound(this, soundname: "General.BurningObject", soundtime: 0.0, duration: nullptr);
  SetParent = this->SetParent;
  this->m_bPlayingSound = true;
  SetParent(this, a2: pTarget, a3: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1010C580
// Name: public: void CEntityFlame::SetLifetime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFlame::SetLifetime(CEntityFlame *this, float lifetime)
{
  float v2; // xmm0_4
  CNetworkVarBase<float,CEntityFlame::NetworkVar_m_flLifetime> *p_m_flLifetime; // esi
  edict_t *m_pPev; // ecx
  float lifetimea; // [esp+8h] [ebp+8h]

  p_m_flLifetime = &this->m_flLifetime;
  lifetimea = gpGlobals->curtime + lifetime;
  v2 = lifetimea;
  if ( this->m_flLifetime.m_Value != lifetimea )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flLifetime->m_Value = lifetimea;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
        v2 = lifetimea;
      }
      p_m_flLifetime->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C5F0
// Name: public: CEntityFlame::CEntityFlame(void)
// Source: json
//------------------------------------------------------------------------------
CEntityFlame *__thiscall CEntityFlame::CEntityFlame(CEntityFlame *this)
{
  edict_t *m_pPev; // ecx
  float *p_curtime; // edx
  edict_t *v4; // ecx
  CEntityFlame *result; // eax
  edict_t *v6; // ecx
  float *v7; // [esp+Ch] [ebp-4h]

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CEntityFlame_vtbl *)&CEntityFlame::`vftable';
  this->m_hEntAttached.m_Value.m_Index = -1;
  this->m_hAttacker.m_Index = -1;
  this->m_DangerLinks.m_Memory.m_pMemory = nullptr;
  this->m_DangerLinks.m_Memory.m_nAllocationCount = 0;
  this->m_DangerLinks.m_Memory.m_nGrowSize = 0;
  this->m_DangerLinks.m_Size = 0;
  this->m_DangerLinks.m_pElements = nullptr;
  if ( this->m_flSize.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
    }
    this->m_flSize.m_Value = 0.0;
  }
  p_curtime = &gpGlobals->curtime;
  v7 = &gpGlobals->curtime;
  if ( this->m_flLifetime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x36Cu);
        p_curtime = v7;
      }
    }
    this->m_flLifetime.m_Value = *p_curtime;
  }
  this->m_bPlayingSound = false;
  this->m_iDangerSound = -1;
  result = this;
  if ( this->m_bCheapEffect.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x358u);
    }
    this->m_bCheapEffect.m_Value = false;
    result = this;
  }
  this->m_hObstacle = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010C710
// Name: public: static class CEntityFlame __near * CEntityFlame::Create(class CBaseEntity __near *,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
CEntityFlame *__cdecl CEntityFlame::Create(CBaseEntity *pTarget, float flLifetime, float flSize)
{
  CEntityFlame *result; // eax
  CEntityFlame *v4; // edi
  float v5; // xmm0_4
  CBaseEdict *v6; // ecx
  float v7; // xmm0_4
  CBaseEdict *v8; // ecx
  float xSize; // [esp+4h] [ebp-8h]
  const Vector *v10; // [esp+8h] [ebp-4h]
  float y; // [esp+8h] [ebp-4h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  result = (CEntityFlame *)CreateEntityByName(className: "entityflame", iForceEdictIndex: -1, bNotify: true);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = flSize;
    if ( flSize <= 0.0 )
    {
      v10 = pTarget->m_Collision.OBBMaxs(this: &pTarget->m_Collision);
      xSize = v10->x - pTarget->m_Collision.OBBMins(this: &pTarget->m_Collision)->x;
      y = pTarget->m_Collision.OBBMaxs(this: &pTarget->m_Collision)->y;
      v5 = (float)((float)(y - pTarget->m_Collision.OBBMins(this: &pTarget->m_Collision)->y) + xSize) * 0.5;
      flSize = v5;
      if ( v5 < 16.0 )
      {
        v5 = 16.0;
        flSize = 16.0;
      }
    }
    if ( flLifetime <= 0.0 )
      flLifetime = 2.0;
    if ( v4->m_flSize.m_Value != v5 )
    {
      if ( v4->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v4->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = &v4->m_Network.m_pPev->CBaseEdict;
        if ( v6 != nullptr )
        {
          CBaseEdict::StateChanged(this: v6, offset: 0x35Cu);
          v5 = flSize;
        }
      }
      v4->m_flSize.m_Value = v5;
    }
    v4->Spawn(this: v4);
    if ( (pTarget->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pTarget, a2: (int)&savedregs);
    UTIL_SetOrigin(entity: v4, vecOrigin: &pTarget->m_vecAbsOrigin, bFireTriggers: false);
    CEntityFlame::AttachToEntity(this: v4, pTarget);
    v7 = gpGlobals->curtime + flLifetime;
    if ( v4->m_flLifetime.m_Value != v7 )
    {
      if ( v4->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v4->m_Network + 76) |= 1u;
      }
      else
      {
        v8 = &v4->m_Network.m_pPev->CBaseEdict;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: v8, offset: 0x36Cu);
      }
      v4->m_flLifetime.m_Value = v7;
    }
    v4->Activate(this: v4);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010C8E0
// Name: protected: void CEntityFlame::FlameThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFlame::FlameThink(CEntityFlame *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  IHandleEntity *m_pEntity; // edx
  edict_t *m_pPev; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *v11; // ecx
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // eax
  IHandleEntity *v15; // ecx
  CBaseEntity *v16; // eax
  CBaseEntity *v17; // eax
  const CTakeDamageInfo *v18; // eax
  CBaseEntity *v19; // eax
  CBaseEntity *v20; // eax
  const Vector *AbsOrigin; // eax
  const Vector *v22; // eax
  const CTakeDamageInfo *v23; // eax
  const Vector *v24; // eax
  unsigned int v25; // eax
  CBaseEntity *v26; // eax
  int v27; // eax
  const Vector *flDuration; // [esp+10h] [ebp-90h]
  const Vector *flDurationa; // [esp+10h] [ebp-90h]
  float flRadius; // [esp+14h] [ebp-8Ch]
  float flRadiusa; // [esp+14h] [ebp-8Ch]
  float thinkTime; // [esp+18h] [ebp-88h]
  CBaseEntity *heat; // [esp+1Ch] [ebp-84h]
  const CTakeDamageInfo *heata; // [esp+1Ch] [ebp-84h]
  CTakeDamageInfo v35; // [esp+2Ch] [ebp-74h] BYREF
  Vector maxs; // [esp+88h] [ebp-18h] BYREF
  Vector mins; // [esp+94h] [ebp-Ch] BYREF

  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.2, szContext: nullptr);
  m_Index = this->m_hEntAttached.m_Value.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v5 = HIWORD(m_Index),
        v4->m_SerialNumber == v5)
    && v4->m_pEntity != nullptr )
  {
    if ( g_pEntityList->m_EntPtrArray[v3].m_SerialNumber == v5 )
      m_pEntity = g_pEntityList->m_EntPtrArray[v3].m_pEntity;
    else
      m_pEntity = nullptr;
    if ( ((int)m_pEntity[50].__vftable & 0x40000000) != 0 )
    {
      if ( this->m_clrRender.m_Value.a != 0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_clrRender.m_Value.a = 0;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
          this->m_clrRender.m_Value.a = 0;
        }
      }
    }
    else
    {
      v8 = v3;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v5;
      v10 = &g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        v11 = v10->m_pEntity;
      else
        v11 = nullptr;
      v12 = (int)v11->__vftable[24].GetRefEHandle(this: v11);
      v13 = v12;
      if ( v12 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v12 + 272))(a1: v12) != 0 )
      {
        v14 = this->m_hEntAttached.m_Value.m_Index;
        if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
          v15 = nullptr;
        else
          v15 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
        if ( HIBYTE(v15[84].__vftable) != 0 )
        {
          v16 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hEntAttached);
          mins = *v16->WorldSpaceCenter(this: v16);
          maxs = mins;
          v17 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hEntAttached);
          maxs.z = v17->WorldSpaceCenter(this: v17)->z;
          maxs.x = mins.x + 32.0;
          maxs.y = mins.y + 32.0;
          mins.z = mins.z - 32.0;
          mins.x = mins.x - 32.0;
          mins.y = mins.y - 32.0;
          UTIL_Bubbles(&mins, &maxs, count: 12);
        }
        if ( gpGlobals->curtime > this->m_flLifetime.m_Value
          || CHandle<CBaseEntity>::operator==(this: (CHandle<CBaseEntity> *)&this->m_hEntAttached, val: nullptr) )
        {
          CBaseEntity::EmitSound(this, soundname: "General.StopBurning", soundtime: 0.0, duration: nullptr);
          this->m_bPlayingSound = false;
          CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
          CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
          v25 = this->m_hEntAttached.m_Value.m_Index;
          if ( v25 != -1
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_SerialNumber == HIWORD(v25)
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_pEntity != nullptr )
          {
            v26 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hEntAttached);
            v27 = (int)v26->MyCombatCharacterPointer(this: v26);
            if ( v27 != 0 )
              (*(void (__thiscall **)(int))(*(_DWORD *)v27 + 888))(a1: v27);
          }
        }
        else
        {
          if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hEntAttached) != nullptr )
          {
            heat = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hEntAttached);
            flRadius = this->m_flSize.m_Value * 0.5;
            flDuration = CBaseEntity::GetAbsOrigin(this);
            v18 = CTakeDamageInfo::CTakeDamageInfo(
                    this: &v35,
                    pInflictor: this,
                    pAttacker: this,
                    flDamage: 4.0,
                    bitsDamageType: 8,
                    iKillType: 0,
                    iObjectsPenetrated: 0);
            RadiusDamage(info: v18, vecSrc: flDuration, flRadius, iClassIgnore: 0, pEntityIgnore: heat);
            heata = CTakeDamageInfo::CTakeDamageInfo(
                      this: &v35,
                      pInflictor: this,
                      pAttacker: this,
                      flDamage: 1.0,
                      bitsDamageType: 268435464,
                      iKillType: 0,
                      iObjectsPenetrated: 0);
            v19 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hEntAttached);
            CBaseEntity::TakeDamage(this: v19, a2: (int)this, inputInfo: heata);
            v20 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hEntAttached);
            if ( !v20->IsNPC(this: v20)
              && hl2_episodic.m_pParent != nullptr
              && hl2_episodic.m_pParent->m_Value.m_nValue != 0 )
            {
              AbsOrigin = CBaseEntity::GetAbsOrigin(this);
              CSoundEnt::InsertSound(
                iType: 4096,
                vecOrigin: AbsOrigin,
                iVolume: 24,
                flDuration: 0.1,
                pOwner: this,
                soundChannelIndex: 2,
                pSoundTarget: nullptr);
              v22 = CBaseEntity::GetAbsOrigin(this);
              maxs.x = v22->x;
              maxs.y = v22->y;
              maxs.z = v22->z + 48.0;
              CSoundEnt::InsertSound(
                iType: 4096,
                vecOrigin: &maxs,
                iVolume: 24,
                flDuration: 0.1,
                pOwner: this,
                soundChannelIndex: 1,
                pSoundTarget: nullptr);
            }
          }
          else
          {
            flRadiusa = this->m_flSize.m_Value * 0.5;
            flDurationa = CBaseEntity::GetAbsOrigin(this);
            v23 = CTakeDamageInfo::CTakeDamageInfo(
                    this: &v35,
                    pInflictor: this,
                    pAttacker: this,
                    flDamage: 0.80000001,
                    bitsDamageType: 8,
                    iKillType: 0,
                    iObjectsPenetrated: 0);
            RadiusDamage(info: v23, vecSrc: flDurationa, flRadius: flRadiusa, iClassIgnore: 0, pEntityIgnore: nullptr);
          }
          thinkTime = this->m_flSize.m_Value * 0.5;
          v24 = CBaseEntity::GetAbsOrigin(this);
          FireSystem_AddHeatInRadius(origin: v24, radius: thinkTime, heat: 2.0);
        }
      }
      else
      {
        UTIL_Remove(oldObj: this);
        (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 888))(a1: v13);
      }
    }
  }
  else
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010CDB0
// Name: protected: void CEnvEntityIgniter::InputIgnite(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityIgniter::InputIgnite(CEnvEntityIgniter *this, inputdata_t *inputdata)
{
  CBaseEntity *v3; // esi
  const char *pszValue; // eax
  CBaseEntity *EntityGeneric; // eax
  int v6; // eax

  if ( this->m_target.pszValue != nullptr )
  {
    v3 = nullptr;
    while ( 1 )
    {
      pszValue = this->m_target.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityGeneric = CGlobalEntityList::FindEntityGeneric(
                        this: &gEntList,
                        pStartEntity: v3,
                        szName: pszValue,
                        pSearchingEntity: this,
                        pActivator: inputdata->pActivator,
                        pCaller: nullptr);
      v3 = EntityGeneric;
      if ( EntityGeneric == nullptr )
        break;
      v6 = (int)EntityGeneric->MyCombatCharacterPointer(this: EntityGeneric);
      if ( v6 != 0 )
        (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v6 + 876))(
          a1: v6,
          a2: LODWORD(this->m_flLifetime),
          a3: 1,
          a4: 0,
          a5: 0);
      else
        CEntityFlame::Create(pTarget: v3, flLifetime: this->m_flLifetime, flSize: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010CF80
// Name: public: virtual void CEntityFlame::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFlame::Spawn(CEntityFlame *this)
{
  CGlobalVars *v2; // ebx
  edict_t *m_pPev; // ecx

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  v2 = gpGlobals;
  if ( this->m_flLifetime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
    }
    this->m_flLifetime.m_Value = v2->curtime;
  }
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CEntityFlame::FlameThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DB750
// Name: public: virtual void CEntityFlame::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEntityFlame::Activate(CBaseParticleEntity *this)
{
  CBaseEntity::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10402130
// Name: CEntityFlame_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEntityFlame_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEntityFlame>(__formal: nullptr);
  CEntityFlame_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402160
// Name: DT_EntityFlame::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityFlame::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EntityFlame::g_SendTable);
  return atexit(func: DT_EntityFlame::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10402180
// Name: DT_EntityFlame::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityFlame::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EntityFlame::ignored>();
  DT_EntityFlame::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402190
// Name: _dynamic_initializer_for__entityflame__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__entityflame__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEntityFlame> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &entityflame,
           a3: "entityflame");
}

//------------------------------------------------------------------------------
// Address: 0x104021B0
// Name: entityflamePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int entityflamePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  entityflamePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&entityflamePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104021D0
// Name: CEnvEntityIgniter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvEntityIgniter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvEntityIgniter>(__formal: nullptr);
  CEnvEntityIgniter_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041AB10
// Name: DT_EntityFlame::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EntityFlame::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EntityFlame::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1010CE60
// Name: struct datamap_t __near * DataMapInit<class CEntityFlame>(class CEntityFlame __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEntityFlame>()
{
  if ( (_S2_75 & 1) == 0 )
  {
    _S2_75 |= 1u;
    nameHolder_152.m_pszBase = "CEntityFlame";
    nameHolder_152.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_152.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_152.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_152.m_Names.m_Size = 0;
    nameHolder_152.m_Names.m_pElements = nullptr;
    nameHolder_152.m_nLenBase = 12;
    atexit(func: DataMapInit_CEntityFlame__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEntityFlame::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_75 & 2) == 0 )
  {
    _S2_75 |= 2u;
    dataDesc_144[6].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_152,
                                  pszIdentifier: "FlameThink");
    dataDesc_144[6].fieldOffset = 0;
    *(_DWORD *)&dataDesc_144[6].fieldSize = 2097153;
    dataDesc_144[6].externalName = nullptr;
    dataDesc_144[6].pSaveRestoreOps = nullptr;
    dataDesc_144[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEntityFlame::FlameThink;
    *(_QWORD *)&dataDesc_144[6].td = 0;
    *(_QWORD *)&dataDesc_144[6].override_field = 0;
    *(_QWORD *)&dataDesc_144[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_144[6].flatOffset[1] = 0;
  }
  CEntityFlame::m_DataMap.dataNumFields = 6;
  CEntityFlame::m_DataMap.dataDesc = &dataDesc_144[1];
  return &CEntityFlame::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010D020
// Name: struct datamap_t __near * DataMapInit<class CEnvEntityIgniter>(class CEnvEntityIgniter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvEntityIgniter>()
{
  if ( (_S4_24 & 1) == 0 )
  {
    _S4_24 |= 1u;
    nameHolder_153.m_pszBase = "CEnvEntityIgniter";
    nameHolder_153.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_153.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_153.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_153.m_Names.m_Size = 0;
    nameHolder_153.m_Names.m_pElements = nullptr;
    nameHolder_153.m_nLenBase = 17;
    atexit(func: DataMapInit_CEnvEntityIgniter__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvEntityIgniter::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvEntityIgniter::m_DataMap.dataNumFields = 2;
  CEnvEntityIgniter::m_DataMap.dataDesc = &dataDesc_145[1];
  return &CEnvEntityIgniter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10402140
// Name: _dynamic_initializer_for__g_CEntityFlame_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEntityFlame_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEntityFlame_ClassReg,
           pNetworkName: "CEntityFlame",
           pTable: &DT_EntityFlame::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104021E0
// Name: _dynamic_initializer_for__env_entity_igniter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_entity_igniter__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvEntityIgniter> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_entity_igniter,
           a3: "env_entity_igniter");
}

//------------------------------------------------------------------------------
// Address: 0x1041AB20
// Name: _ServerClassInit_DT_EntityFlame::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EntityFlame::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_43;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041AB40
// Name: _DataMapInit_CEntityFlame__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEntityFlame__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_152);
}

//------------------------------------------------------------------------------
// Address: 0x1041AB50
// Name: _DataMapInit_CEnvEntityIgniter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvEntityIgniter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_153);
}
