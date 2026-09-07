// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/player.cpp
// Functions: 340
// ============================================================

#include "game\server\player.h"

//------------------------------------------------------------------------------
// Address: 0x100D78D0
// Name: public: virtual void CBasePlayer::ChangeTeam(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ChangeTeam(CBasePlayer *this, int iTeamNum)
{
  this->ChangeTeam(this, a2: iTeamNum, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x100D96D0
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBasePlayer::NetworkVar_m_hObserverTarget>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hObserverTarget>::Set(
        CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hObserverTarget> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hObserverTarget> *v5; // eax
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
    v5 = this - 792;
    if ( *((_BYTE *)this - 3084) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xC60u);
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
// Address: 0x101104C0
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CEntityParticleTrail::NetworkVar_m_hConstraintEntity>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CEntityParticleTrail::NetworkVar_m_hConstraintEntity>::Set(
        CNetworkHandleBase<CBaseEntity,CEntityParticleTrail::NetworkVar_m_hConstraintEntity> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CEntityParticleTrail::NetworkVar_m_hConstraintEntity> *v5; // eax
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
    v5 = this - 219;
    if ( *((_BYTE *)this - 792) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x36Cu);
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
// Address: 0x10122A20
// Name: public: virtual int CSprayCan::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSprayCan::ObjectCaps(CShower *this)
{
  return 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x101717D0
// Name: public: virtual int CBasePlayer::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::UpdateTransmitState(CMaterialModifyControl *this)
{
  return CBaseEntity::SetTransmitState(this, nFlag: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B38A0
// Name: void CC_GiveCurrentAmmo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_GiveCurrentAmmo()
{
  CBasePlayer *v0; // eax
  CBaseCombatCharacter *v1; // esi
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseCombatWeapon *v3; // edi
  int v4; // eax
  int v5; // ebx
  CAmmoDef *AmmoDef; // eax
  CAmmoDef *v7; // eax
  Ammo_t *AmmoOfIndex; // eax
  int v9; // eax
  int v10; // edi
  CAmmoDef *v11; // eax
  int v12; // ebx
  CAmmoDef *v13; // eax
  Ammo_t *v14; // eax
  int v15; // [esp-10h] [ebp-18h]
  int v16; // [esp-10h] [ebp-18h]
  int giveAmount; // [esp+4h] [ebp-4h]

  v0 = UTIL_PlayerByIndex(playerIndex: 1);
  v1 = v0;
  if ( v0 != nullptr )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v0);
    v3 = ActiveWeapon;
    if ( ActiveWeapon != nullptr )
    {
      if ( CBaseCombatWeapon::UsesPrimaryAmmo(this: ActiveWeapon) )
      {
        v4 = v3->GetPrimaryAmmoType(this: v3);
        v5 = v4;
        if ( v4 != -1 )
        {
          v15 = v4;
          AmmoDef = GetAmmoDef();
          giveAmount = CAmmoDef::MaxCarry(this: AmmoDef, nAmmoIndex: v15, owner: v1);
          v7 = GetAmmoDef();
          AmmoOfIndex = CAmmoDef::GetAmmoOfIndex(this: v7, nAmmoIndex: v5);
          CBaseCombatCharacter::GiveAmmo(
            this: v1,
            iCount: giveAmount,
            szName: AmmoOfIndex->pName,
            bSuppressSound: false);
        }
      }
      if ( CBaseCombatWeapon::UsesSecondaryAmmo(this: v3) && v3->HasSecondaryAmmo(this: v3) )
      {
        v9 = v3->GetSecondaryAmmoType(this: v3);
        v10 = v9;
        if ( v9 != -1 )
        {
          v16 = v9;
          v11 = GetAmmoDef();
          v12 = CAmmoDef::MaxCarry(this: v11, nAmmoIndex: v16, owner: v1);
          v13 = GetAmmoDef();
          v14 = CAmmoDef::GetAmmoOfIndex(this: v13, nAmmoIndex: v10);
          CBaseCombatCharacter::GiveAmmo(this: v1, iCount: v12, szName: v14->pName, bSuppressSound: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3980
// Name: public: virtual struct datamap_t __near * CBasePlayer::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBasePlayer::GetDataDescMap(CBasePlayer *this)
{
  return &CBasePlayer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B3990
// Name: public: virtual struct ScriptClassDesc_t __near * CBasePlayer::GetScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall CBasePlayer::GetScriptDesc(CBasePlayer *this)
{
  return GetScriptDesc<CBasePlayer>();
}

//------------------------------------------------------------------------------
// Address: 0x101B39B0
// Name: public: void CBasePlayer::SnapEyeAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SnapEyeAngles(CBasePlayer *this, const QAngle *viewAngles)
{
  this->pl.v_angle = *viewAngles;
  this->pl.fixangle = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B39E0
// Name: int TrainSpeed(int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TrainSpeed(int iSpeed, int iMax)
{
  float v2; // xmm0_4
  int result; // eax

  v2 = (float)iSpeed / (float)iMax;
  if ( iSpeed < 0 )
    return 5;
  if ( iSpeed == 0 )
    return 1;
  if ( v2 < 0.33 )
    return 2;
  result = 3;
  if ( v2 >= 0.66 )
    return 4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B3A50
// Name: public: virtual void CBasePlayer::DamageEffect(float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::DamageEffect(CBasePlayer *this, float flDamage, color32_s fDamageType)
{
  Vector *v4; // edi
  int v5; // eax
  int v6; // eax
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  QAngle angleOffset; // [esp+2Ch] [ebp-10h] BYREF
  float v9; // [esp+38h] [ebp-4h]
  float flDamagea; // [esp+44h] [ebp+8h]

  if ( (fDamageType.r & 1) != 0 )
  {
    fDamageType = (color32_s)-2147483520;
    UTIL_ScreenFade(pEntity: this, color: &fDamageType, fadeTime: 1.0, fadeHold: 0.1, flags: 1);
  }
  else if ( (*(_WORD *)&fDamageType.r & 0x4000) != 0 )
  {
    fDamageType = (color32_s)-2139095040;
    UTIL_ScreenFade(pEntity: this, color: &fDamageType, fadeTime: 1.0, fadeHold: 0.1, flags: 1);
  }
  else if ( (fDamageType.r & 4) != 0 )
  {
    v4 = this->EyePosition(this, result: &angleOffset);
    v5 = this->BloodColor(this);
    SpawnBlood(vecSpot: *v4, vecDir: &g_vecAttackDir, bloodColor: v5, flDamage);
  }
  else if ( (*(_DWORD *)&fDamageType & 0x1000000) != 0 )
  {
    fDamageType = (color32_s)1694433280;
    UTIL_ScreenFade(pEntity: this, color: &fDamageType, fadeTime: 0.2, fadeHold: 0.40000001, flags: 4);
    flDamagea = (float)random->RandomInt(this: random, a2: 0, a3: 0);
    v6 = random->RandomInt(this: random, a2: 0, a3: 0);
    RandomInt = random->RandomInt;
    v9 = (float)v6;
    angleOffset.x = flDamagea;
    angleOffset.y = (float)v6;
    angleOffset.z = (float)RandomInt(this: random, a2: 0, a3: 0);
    CBasePlayer::ViewPunch(this, &angleOffset);
    CBaseEntity::EmitSound(this, soundname: "Player.PlasmaDamage", soundtime: 0.0, duration: nullptr);
  }
  else if ( (*(_WORD *)&fDamageType.r & 0x200) != 0 )
  {
    CBaseEntity::EmitSound(this, soundname: "Player.SonicDamage", soundtime: 0.0, duration: nullptr);
  }
  else if ( (fDamageType.r & 2) != 0 )
  {
    CBaseEntity::EmitSound(this, soundname: "Flesh.BulletImpact", soundtime: 0.0, duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3C50
// Name: public: virtual struct impactdamagetable_t const __near & CBasePlayer::GetPhysicsImpactDamageTable(void)
// Source: json
//------------------------------------------------------------------------------
const impactdamagetable_t *__thiscall CBasePlayer::GetPhysicsImpactDamageTable(CBasePlayer *this)
{
  return &gDefaultPlayerImpactDamageTable;
}

//------------------------------------------------------------------------------
// Address: 0x101B3C60
// Name: public: float CBasePlayer::GetWaterJumpTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayer::GetWaterJumpTime(CBasePlayer *this)
{
  return this->m_flWaterJumpTime;
}

//------------------------------------------------------------------------------
// Address: 0x101B3C70
// Name: public: virtual void CBasePlayer::AttemptToExitFreezeCam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::AttemptToExitFreezeCam(CBasePlayer *this)
{
  this->StartObserverMode(this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101B3C80
// Name: public: virtual bool CBasePlayer::StartReplayMode(float,float,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePlayer::StartReplayMode(CBasePlayer *this, float fDelay, float fDuration, int iEntity)
{
  float v4; // xmm0_4

  if ( sv_maxreplay == nullptr || sv_maxreplay->m_pParent->m_Value.m_fValue <= 0.0 )
    return 0;
  this->m_fDelay = fDelay;
  v4 = gpGlobals->curtime + fDuration;
  this->m_iReplayEntity = iEntity;
  this->m_fReplayEnd = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B3CE0
// Name: public: virtual void CBasePlayer::StopReplayMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::StopReplayMode(CBasePlayer *this)
{
  this->m_fDelay = 0.0;
  *(_QWORD *)&this->m_fReplayEnd = 3212836864LL;
}

//------------------------------------------------------------------------------
// Address: 0x101B3D10
// Name: public: virtual int CBasePlayer::GetDelayTicks(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::GetDelayTicks(CBasePlayer *this)
{
  float m_fDelay; // xmm0_4

  m_fDelay = this->m_fDelay;
  if ( this->m_fReplayEnd > gpGlobals->curtime )
    return (int)(float)((float)(m_fDelay / gpGlobals->interval_per_tick) + 0.5);
  if ( m_fDelay > 0.0 )
    this->StopReplayMode(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B3D60
// Name: public: virtual int CBasePlayer::GetReplayEntity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::GetReplayEntity(CBasePlayer *this)
{
  return this->m_iReplayEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101B3D70
// Name: public: virtual void CBasePlayer::ObserverUse(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ObserverUse(CBasePlayer *this, bool bIsPressed)
{
  CHLTVDirector *v3; // eax
  CHLTVDirector *v4; // eax
  int m_iCameraManIndex; // esi
  edict_t *v6; // eax
  CHLTVDirector *v7; // eax
  int v8; // [esp-8h] [ebp-Ch]

  v3 = HLTVDirector();
  if ( v3->IsActive(this: &v3->IHLTVDirector) && CBaseEntity::GetTeamNumber(this) == 1 && bIsPressed )
  {
    v4 = HLTVDirector();
    if ( v4->IsActive(this: &v4->IHLTVDirector) )
    {
      m_iCameraManIndex = HLTVDirector()->m_iCameraManIndex;
      v6 = CBaseEntity::entindex(this);
      if ( m_iCameraManIndex == 0 )
      {
        v8 = (int)v6;
LABEL_7:
        v7 = HLTVDirector();
        CHLTVDirector::SetCameraMan(this: v7, iPlayerIndex: v8);
        return;
      }
      v8 = 0;
      if ( (edict_t *)m_iCameraManIndex == v6 )
        goto LABEL_7;
      ClientPrint(
        player: this,
        msg_dest: 3,
        msg_name: "Camera in use by other player.",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3E00
// Name: public: virtual void CBasePlayer::JumptoPosition(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::JumptoPosition(CBasePlayer *this, const Vector *origin, const QAngle *angles)
{
  CBaseEntity::SetAbsOrigin(this, absOrigin: origin);
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  CBaseEntity::SetLocalAngles(this, angles);
  this->pl.v_angle = *angles;
  this->pl.fixangle = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B3E60
// Name: public: virtual bool CBasePlayer::PassesObserverFilter(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePlayer::PassesObserverFilter(CBasePlayer *this, const CBaseEntity *entity)
{
  if ( entity == nullptr )
    return 0;
  this->IsNetClient(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B3E80
// Name: public: virtual class CBaseEntity __near * CBasePlayer::FindNextObserverTarget(bool)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CBasePlayer::FindNextObserverTarget(CBasePlayer *this, int bReverse)
{
  int maxClients; // ebx
  int v3; // esi
  CBasePlayer *v4; // edi
  int iDir; // [esp+18h] [ebp+8h]

  maxClients = ((int (__stdcall *)(int))this->GetNextObserverSearchStartPoint)(a1: bReverse);
  if ( maxClients <= gpGlobals->maxClients )
  {
    if ( maxClients < 1 )
      maxClients = gpGlobals->maxClients;
  }
  else
  {
    maxClients = 1;
  }
  v3 = maxClients;
  iDir = 2 * ((_BYTE)bReverse == 0) - 1;
  while ( 1 )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: v3);
    if ( this->IsValidObserverTarget(this, a2: v4) )
      break;
    v3 += iDir;
    if ( v3 <= gpGlobals->maxClients )
    {
      if ( v3 < 1 )
        v3 = gpGlobals->maxClients;
    }
    else
    {
      v3 = 1;
    }
    if ( v3 == maxClients )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101B3F20
// Name: public: virtual bool CBasePlayer::IsUseableEntity(class CBaseEntity __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::IsUseableEntity(CBasePlayer *this, CBaseEntity *pEntity, unsigned int requiredCaps)
{
  int v3; // eax
  bool result; // al

  result = false;
  if ( pEntity != nullptr )
  {
    v3 = pEntity->ObjectCaps(this: pEntity);
    if ( (v3 & 0xF) != 0 && (requiredCaps & v3) == requiredCaps )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B3F50
// Name: public: virtual void CBasePlayer::Duck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Duck(CBasePlayer *this)
{
  if ( (this->m_nButtons & 4) != 0 && this->m_Activity != ACT_LEAP )
    this->SetAnimation(this, a2: PLAYER_WALK);
}

//------------------------------------------------------------------------------
// Address: 0x101B3F70
// Name: public: void CBasePlayer::ResetFragCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ResetFragCount(CBasePlayer *this)
{
  this->m_iFrags = 0;
  this->pl.frags = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B3F80
// Name: public: virtual void CBasePlayer::IncrementFragCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::IncrementFragCount(CBasePlayer *this, int nCount)
{
  this->m_iFrags += nCount;
  this->pl.frags = this->m_iFrags;
}

//------------------------------------------------------------------------------
// Address: 0x101B3FA0
// Name: public: void CBasePlayer::ResetDeathCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ResetDeathCount(CBasePlayer *this)
{
  this->m_iDeaths = 0;
  this->pl.deaths = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B3FB0
// Name: public: virtual void CBasePlayer::IncrementDeathCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::IncrementDeathCount(CBasePlayer *this, int nCount)
{
  this->m_iDeaths += nCount;
  this->pl.deaths = this->m_iDeaths;
}

//------------------------------------------------------------------------------
// Address: 0x101B3FD0
// Name: public: void CBasePlayer::AddPoints(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::AddPoints(CBasePlayer *this, int score, bool bAllowNegativeScore)
{
  int v3; // edx
  int m_iFrags; // eax

  v3 = score;
  if ( score < 0 && !bAllowNegativeScore )
  {
    m_iFrags = this->m_iFrags;
    if ( m_iFrags < 0 )
      return;
    if ( -score > m_iFrags )
      v3 = -m_iFrags;
  }
  this->m_iFrags += v3;
  this->pl.frags = this->m_iFrags;
}

//------------------------------------------------------------------------------
// Address: 0x101B4010
// Name: public: void CBasePlayer::AddPointsToTeam(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::AddPointsToTeam(CBasePlayer *this, int score, bool bAllowNegativeScore)
{
  CTeam *Team; // eax

  if ( CBaseEntity::GetTeam(this) != nullptr )
  {
    Team = CBaseEntity::GetTeam(this);
    Team->AddScore(this: Team, a2: score);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4040
// Name: public: void CBasePlayer::ForceSimulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ForceSimulation(CBasePlayer *this)
{
  this->m_nSimulationTick = -1;
}

//------------------------------------------------------------------------------
// Address: 0x101B4050
// Name: public: void CBasePlayer::CheckTimeBasedDamage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::CheckTimeBasedDamage(CBasePlayer *this)
{
  int i; // ebx
  int v3; // edi
  unsigned __int8 v4; // al
  int m_idrowndmg; // eax
  int m_idrownrestored; // ecx
  int v7; // edi
  int m_nPoisonDmg; // eax
  int m_nPoisonRestored; // ecx
  int v10; // edi
  unsigned __int8 v11; // cl

  if ( g_pGameRules->Damage_IsTimeBased(this: g_pGameRules, a2: this->m_bitsDamageType)
    && COERCE_FLOAT(COERCE_UNSIGNED_INT(gpGlobals->curtime - this->m_tbdPrev) & _mask__AbsFloat_) >= 2.0 )
  {
    this->m_tbdPrev = gpGlobals->curtime;
    for ( i = 0; i < 8; ++i )
    {
      v3 = 0x8000 << i;
      if ( g_pGameRules->Damage_IsTimeBased(this: g_pGameRules, a2: 0x8000 << i) && (v3 & this->m_bitsDamageType) != 0 )
      {
        switch ( i )
        {
          case 0:
          case 1:
          case 3:
          case 5:
          case 6:
          case 7:
            v4 = 2;
            break;
          case 2:
            m_nPoisonDmg = this->m_nPoisonDmg;
            m_nPoisonRestored = this->m_nPoisonRestored;
            if ( m_nPoisonDmg > m_nPoisonRestored )
            {
              v10 = m_nPoisonDmg - m_nPoisonRestored;
              if ( m_nPoisonDmg - m_nPoisonRestored >= 10 )
                v10 = 10;
              ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->TakeHealth)(a1: this, a2: (float)v10, a3: 0);
              this->m_nPoisonRestored += v10;
              v3 = 0x8000 << i;
            }
            v4 = 9;
            break;
          case 4:
            m_idrowndmg = this->m_idrowndmg;
            m_idrownrestored = this->m_idrownrestored;
            if ( m_idrowndmg > m_idrownrestored )
            {
              v7 = m_idrowndmg - m_idrownrestored;
              if ( m_idrowndmg - m_idrownrestored >= 10 )
                v7 = 10;
              ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->TakeHealth)(a1: this, a2: (float)v7, a3: 0);
              this->m_idrownrestored += v7;
              v3 = 0x8000 << i;
            }
            v4 = 4;
            break;
          default:
            v4 = 0;
            break;
        }
        v11 = this->m_rgbTimeBasedDamage[i];
        if ( v11 != 0 )
        {
          this->m_rgbTimeBasedDamage[i] = v11 - 1;
          if ( v11 == 1 )
          {
            this->m_rgbTimeBasedDamage[i] = 0;
            this->m_bitsDamageType &= ~v3;
          }
        }
        else
        {
          this->m_rgbTimeBasedDamage[i] = v4;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B41F0
// Name: public: void CBasePlayer::ForceOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ForceOrigin(CBasePlayer *this, const Vector *vecOrigin)
{
  this->m_bForceOrigin = true;
  this->m_vForcedOrigin = *vecOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x101B4220
// Name: public: virtual class Vector CBasePlayer::GetSmoothedVelocity(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBasePlayer::GetSmoothedVelocity(CBasePlayer *this, Vector *result)
{
  IServerVehicle *v3; // eax
  int v4; // eax

  if ( this->IsInAVehicle(this) )
  {
    v3 = this->GetVehicle(this);
    v4 = (int)v3->GetVehicleEnt(this: v3);
    (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v4 + 540))(a1: v4, a2: result);
  }
  else
  {
    *result = this->m_vecSmoothedVelocity;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B4280
// Name: public: virtual void CBasePlayer::InitialSpawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::InitialSpawn(CBasePlayer *this)
{
  this->m_iConnected = PlayerConnected;
  gamestats->Event_PlayerConnected(this: gamestats, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101B42A0
// Name: public: virtual void CBasePlayer::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Activate(CBasePlayer *this)
{
  CBaseAnimating::Activate(this);
  AimTarget_ForceRepopulateList();
  this->RumbleEffect(this, a2: 0, a3: 0, a4: 0);
  this->m_iVehicleAnalogBias = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B42D0
// Name: public: virtual void CBasePlayer::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Precache(CBasePlayer *this)
{
  CBaseCombatCharacter::Precache(this);
  CBaseEntity::PrecacheScriptSound(soundname: "Player.FallGib");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.Death");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.PlasmaDamage");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.SonicDamage");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.DrownStart");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.DrownContinue");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.Wade");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.AmbientUnderWater");
  enginesound->PrecacheSentenceGroup(this: enginesound, a2: "HEV");
  PrecacheParticleSystem(pParticleSystemName: "slime_splash_01");
  PrecacheParticleSystem(pParticleSystemName: "slime_splash_02");
  PrecacheParticleSystem(pParticleSystemName: "slime_splash_03");
  this->m_flgeigerRange = 1000.0;
  this->m_igeigerRangePrev = 1000;
  this->m_iClientBattery = -1;
  this->m_iUpdateTime = 5;
  if ( gInitHUD )
    this->m_fInitHUD = true;
}

//------------------------------------------------------------------------------
// Address: 0x101B43A0
// Name: public: virtual void CBasePlayer::ForceRespawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ForceRespawn(CBasePlayer *this)
{
  void (__thiscall *Spawn)(CBaseEntity *); // edx

  this->RemoveAllItems(this, a2: true);
  CBaseEntity::SetGroundEntity(this, ground: nullptr);
  Spawn = this->Spawn;
  this->m_nButtons = 0;
  Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B43D0
// Name: public: virtual int CBasePlayer::Save(class ISave __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBasePlayer::Save(CBasePlayer *this, ISave *save)
{
  return CBaseEntity::Save(this, save) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B43F0
// Name: public: void CBasePlayer::NotifyNearbyRadiationSource(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::NotifyNearbyRadiationSource(CBasePlayer *this, float flRange)
{
  if ( this->m_flgeigerRange >= flRange )
    this->m_flgeigerRange = flRange;
}

//------------------------------------------------------------------------------
// Address: 0x101B4420
// Name: public: void CBasePlayer::AllowImmediateDecalPainting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::AllowImmediateDecalPainting(CBasePlayer *this)
{
  this->m_flNextDecalTime = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x101B4430
// Name: public: bool CBasePlayer::CanEnterVehicle(class IServerVehicle __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::CanEnterVehicle(CBasePlayer *this, IServerVehicle *pVehicle, int nRole)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  return pVehicle->GetPassenger(this: pVehicle, a2: nRole) == 0
      && (pVehicle->IsPassengerUsingStandardWeapons(this: pVehicle, a2: nRole)
       || (ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this)) == nullptr
       || ActiveWeapon->CanHolster(this: ActiveWeapon))
      && this->IsAlive(this)
      && (this->m_iEFlags & 0x100000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B44B0
// Name: public: virtual void spraycanPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall spraycanPrecache::CResourcePrecacher::Cache(
        spraycanPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "spraycan",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101B44E0
// Name: public: void CSprayCan::Spawn(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprayCan::Spawn(CSprayCan *this, CBasePlayer *pOwner)
{
  const Vector *v3; // eax
  const QAngle *v4; // eax
  Vector origin; // [esp+14h] [ebp-Ch] BYREF

  v3 = pOwner->WorldSpaceCenter(this: pOwner);
  origin.x = v3->x;
  origin.y = v3->y;
  origin.z = v3->z + 32.0;
  CBaseEntity::SetLocalOrigin(this, &origin);
  v4 = pOwner->EyeAngles(this: pOwner);
  CBaseEntity::SetLocalAngles(this, angles: v4);
  this->SetOwnerEntity(this, a2: pOwner);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  CBaseEntity::EmitSound(this, soundname: "SprayCan.Paint", soundtime: 0.0, duration: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101B4580
// Name: public: virtual void CSprayCan::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprayCan::Precache(CSprayCan *this)
{
  CBaseEntity::PrecacheScriptSound(soundname: "SprayCan.Paint");
}

//------------------------------------------------------------------------------
// Address: 0x101B4590
// Name: public: virtual class CBaseEntity __near * CBasePlayer::FindPickerEntityClass(char __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::FindPickerEntityClass(CBasePlayer *this, char *classname)
{
  CBaseEntity *result; // eax
  Vector forward; // [esp+14h] [ebp-18h] BYREF
  Vector origin; // [esp+20h] [ebp-Ch] BYREF

  result = this->FindEntityClassForward(this, a2: classname);
  if ( result == nullptr )
  {
    CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: nullptr);
    origin = *this->WorldSpaceCenter(this);
    return CGlobalEntityList::FindEntityClassNearestFacing(
             this: &gEntList,
             &origin,
             facing: &forward,
             threshold: 0.94999999,
             classname);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B4610
// Name: public: virtual class CBaseEntity __near * CBasePlayer::FindPickerEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::FindPickerEntity(CBasePlayer *this)
{
  IMDLCache *v1; // ebx
  CBaseEntity *EntityNearestFacing; // edi
  _BYTE v5[12]; // [esp+18h] [ebp-24h] BYREF
  Vector forward; // [esp+24h] [ebp-18h] BYREF
  Vector origin; // [esp+30h] [ebp-Ch] BYREF

  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  EntityNearestFacing = this->FindEntityForward(this, a2: 1);
  if ( EntityNearestFacing == nullptr )
  {
    CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: nullptr);
    origin = *this->EyePosition(this, result: v5);
    EntityNearestFacing = CGlobalEntityList::FindEntityNearestFacing(
                            this: &gEntList,
                            &origin,
                            facing: &forward,
                            threshold: 0.94999999);
  }
  v1->EndLock(this: v1);
  return EntityNearestFacing;
}

//------------------------------------------------------------------------------
// Address: 0x101B46B0
// Name: public: virtual class CAI_Node __near * CBasePlayer::FindPickerAINode(int)
// Source: json
//------------------------------------------------------------------------------
CAI_Node *__thiscall CBasePlayer::FindPickerAINode(CBasePlayer *this, int nNodeType)
{
  const Vector *v3; // eax
  _BYTE v5[12]; // [esp+Ch] [ebp-18h] BYREF
  Vector forward; // [esp+18h] [ebp-Ch] BYREF

  CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: nullptr);
  v3 = this->EyePosition(this, result: v5);
  return CAI_NetworkEditTools::FindAINodeNearestFacing(origin: v3, facing: &forward, threshold: 0.89999998, nNodeType);
}

//------------------------------------------------------------------------------
// Address: 0x101B4700
// Name: public: virtual class CAI_Link __near * CBasePlayer::FindPickerAILink(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Link *__thiscall CBasePlayer::FindPickerAILink(CBasePlayer *this)
{
  const Vector *v2; // eax
  _BYTE v4[12]; // [esp+8h] [ebp-18h] BYREF
  Vector forward; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: nullptr);
  v2 = this->EyePosition(this, result: v4);
  return CAI_NetworkEditTools::FindAILinkNearestFacing(
           a1: COERCE_FLOAT(&savedregs),
           vOrigin: v2,
           vFacing: &forward,
           threshold: 0.89999998);
}

//------------------------------------------------------------------------------
// Address: 0x101B4750
// Name: public: virtual void CBasePlayer::ForceClientDllUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ForceClientDllUpdate(CBasePlayer *this)
{
  void (*UpdateClientData)(void); // edx

  UpdateClientData = (void (*)(void))this->UpdateClientData;
  this->m_iTrain |= 0xC0u;
  this->m_iClientBattery = -1;
  this->m_fWeapon = false;
  this->m_fInitHUD = true;
  UpdateClientData();
  UTIL_RestartAmbientSounds();
}

//------------------------------------------------------------------------------
// Address: 0x101B4790
// Name: CreateJeep
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateJeep(CBasePlayer *pPlayer@<edi>)
{
  const QAngle *v1; // eax
  CBaseEntity *EntityByName; // esi
  unsigned int v3; // ecx
  float v4; // xmm0_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  unsigned int v8; // edx
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  Vector vecForward; // [esp+4h] [ebp-30h] BYREF
  Vector vecOrigin; // [esp+10h] [ebp-24h] BYREF
  QAngle vecAngles; // [esp+1Ch] [ebp-18h] BYREF
  float v15; // [esp+28h] [ebp-Ch]
  float v16; // [esp+2Ch] [ebp-8h]
  float v17; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  v1 = pPlayer->EyeAngles(this: pPlayer);
  AngleVectors(angles: v1, forward: &vecForward);
  EntityByName = CreateEntityByName(className: "prop_vehicle_jeep", iForceEdictIndex: -1, bNotify: true);
  if ( EntityByName != nullptr )
  {
    v3 = (unsigned int)pPlayer->m_iEFlags >> 11;
    v4 = vecForward.x * 256.0;
    v5 = vecForward.y * 256.0;
    v6 = vecForward.z * 256.0;
    v15 = vecForward.x * 256.0;
    v16 = vecForward.y * 256.0;
    v17 = vecForward.z * 256.0;
    if ( (v3 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&savedregs);
      v5 = v16;
      v6 = v17;
      v4 = v15;
    }
    v7 = pPlayer->m_vecAbsOrigin.x + v4;
    v8 = (unsigned int)pPlayer->m_iEFlags >> 11;
    v9 = (float)(pPlayer->m_vecAbsOrigin.z + v6) + 64.0;
    v10 = pPlayer->m_vecAbsOrigin.y + v5;
    vecOrigin.x = v7;
    vecOrigin.y = v10;
    vecOrigin.z = v9;
    if ( (v8 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&savedregs);
    v11 = pPlayer->m_angAbsRotation.y - 90.0;
    vecAngles.x = 0.0;
    vecAngles.y = v11;
    vecAngles.z = 0.0;
    CBaseEntity::SetAbsOrigin(this: EntityByName, absOrigin: &vecOrigin);
    CBaseEntity::SetAbsAngles(this: EntityByName, absAngles: &vecAngles);
    EntityByName->KeyValue_4(this: EntityByName, a2: "model", a3: "models/buggy.mdl");
    EntityByName->KeyValue_4(this: EntityByName, a2: "solid", a3: "6");
    EntityByName->KeyValue_4(this: EntityByName, a2: "targetname", a3: "jeep");
    EntityByName->KeyValue_4(this: EntityByName, a2: "vehiclescript", a3: "scripts/vehicles/jeep_test.txt");
    DispatchSpawn(pEntity: EntityByName, bRunVScripts: true);
    EntityByName->Activate(this: EntityByName);
    EntityByName->Teleport(this: EntityByName, a2: &vecOrigin, a3: &vecAngles, a4: nullptr, a5: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4940
// Name: void CC_CH_CreateJeep(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CH_CreateJeep()
{
  CBasePlayer *CommandClient; // eax

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr )
    CreateJeep(pPlayer: CommandClient);
}

//------------------------------------------------------------------------------
// Address: 0x101B4960
// Name: CreateAirboat
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateAirboat(CBasePlayer *pPlayer@<edi>)
{
  const QAngle *v1; // eax
  CBaseEntity *EntityByName; // esi
  unsigned int v3; // ecx
  float v4; // xmm0_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  unsigned int v8; // edx
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  QAngle vecAngles; // [esp+4h] [ebp-30h] BYREF
  Vector vecOrigin; // [esp+10h] [ebp-24h] BYREF
  Vector vecForward; // [esp+1Ch] [ebp-18h] BYREF
  float v15; // [esp+28h] [ebp-Ch]
  float v16; // [esp+2Ch] [ebp-8h]
  float v17; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  v1 = pPlayer->EyeAngles(this: pPlayer);
  AngleVectors(angles: v1, forward: &vecForward);
  EntityByName = CreateEntityByName(className: "prop_vehicle_airboat", iForceEdictIndex: -1, bNotify: true);
  if ( EntityByName != nullptr )
  {
    v3 = (unsigned int)pPlayer->m_iEFlags >> 11;
    v4 = vecForward.x * 256.0;
    v5 = vecForward.y * 256.0;
    v6 = vecForward.z * 256.0;
    v15 = vecForward.x * 256.0;
    v16 = vecForward.y * 256.0;
    v17 = vecForward.z * 256.0;
    if ( (v3 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&savedregs);
      v5 = v16;
      v6 = v17;
      v4 = v15;
    }
    v7 = pPlayer->m_vecAbsOrigin.x + v4;
    v8 = (unsigned int)pPlayer->m_iEFlags >> 11;
    v9 = (float)(pPlayer->m_vecAbsOrigin.z + v6) + 64.0;
    v10 = pPlayer->m_vecAbsOrigin.y + v5;
    vecOrigin.x = v7;
    vecOrigin.y = v10;
    vecOrigin.z = v9;
    if ( (v8 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&savedregs);
    v11 = pPlayer->m_angAbsRotation.y - 90.0;
    vecAngles.x = 0.0;
    vecAngles.y = v11;
    vecAngles.z = 0.0;
    CBaseEntity::SetAbsOrigin(this: EntityByName, absOrigin: &vecOrigin);
    CBaseEntity::SetAbsAngles(this: EntityByName, absAngles: &vecAngles);
    EntityByName->KeyValue_4(this: EntityByName, a2: "model", a3: "models/airboat.mdl");
    EntityByName->KeyValue_4(this: EntityByName, a2: "solid", a3: "6");
    EntityByName->KeyValue_4(this: EntityByName, a2: "targetname", a3: "airboat");
    EntityByName->KeyValue_4(this: EntityByName, a2: "vehiclescript", a3: "scripts/vehicles/airboat.txt");
    DispatchSpawn(pEntity: EntityByName, bRunVScripts: true);
    EntityByName->Activate(this: EntityByName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4AF0
// Name: void CC_CH_CreateAirboat(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CH_CreateAirboat()
{
  CBasePlayer *CommandClient; // eax

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr )
    CreateAirboat(pPlayer: CommandClient);
}

//------------------------------------------------------------------------------
// Address: 0x101B4B10
// Name: public: virtual class QAngle CBasePlayer::BodyAngles(void)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall CBasePlayer::BodyAngles(CBasePlayer *this, QAngle *result)
{
  const QAngle *v2; // eax
  __int64 v3; // xmm0_8
  float z; // eax

  v2 = this->EyeAngles(this);
  v3 = *(_QWORD *)&v2->x;
  z = v2->z;
  *(_QWORD *)&result->x = v3;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B4B40
// Name: public: virtual class Vector CBasePlayer::BodyTarget(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBasePlayer::BodyTarget(CBasePlayer *this, Vector *result, const Vector *posSrc, int bNoisy)
{
  IServerVehicle *v5; // eax
  int v6; // eax
  const Vector *v8; // eax
  float v9; // [esp+Ch] [ebp-Ch]
  float v10; // [esp+10h] [ebp-8h]
  float v11; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  float bNoisya; // [esp+28h] [ebp+10h]

  if ( this->IsInAVehicle(this) )
  {
    v5 = this->GetVehicle(this);
    v6 = (int)v5->GetVehicleEnt(this: v5);
    (*(void (__thiscall **)(int, Vector *, const Vector *, int))(*(_DWORD *)v6 + 520))(
      a1: v6,
      a2: result,
      a3: posSrc,
      a4: bNoisy);
    return result;
  }
  else if ( (_BYTE)bNoisy != 0 )
  {
    bNoisya = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1060320051,
                a3: 1065353216);
    v8 = this->GetViewOffset(this);
    v9 = v8->x * bNoisya;
    v10 = v8->y * bNoisya;
    v11 = bNoisya * v8->z;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    result->x = v9 + this->m_vecAbsOrigin.x;
    result->y = this->m_vecAbsOrigin.y + v10;
    result->z = this->m_vecAbsOrigin.z + v11;
    return result;
  }
  else
  {
    this->EyePosition(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4C60
// Name: public: void CBasePlayer::EnableControl(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::EnableControl(CBasePlayer *this, bool fControl)
{
  if ( fControl )
    CBaseEntity::RemoveFlag(this, flagsToRemove: 64);
  else
    CBaseEntity::AddFlag(this, flags: 64);
}

//------------------------------------------------------------------------------
// Address: 0x101B4C80
// Name: public: virtual bool CBasePlayer::ShouldAutoaim(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::ShouldAutoaim(CBasePlayer *this)
{
  return !this->IsBot(this) && gpGlobals->maxClients <= 1 && !g_pGameRules->IsSkillLevel(this: g_pGameRules, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x101B4CC0
// Name: public: virtual bool CTraceFilterSkipTwoEntitiesAndTeammates::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterSkipTwoEntitiesAndTeammates::ShouldHitEntity(
        CTraceFilterSkipTwoEntitiesAndTeammates *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  CBaseEntity *v4; // ebx
  bool result; // al
  IHandleEntity *m_pPassEnt; // esi
  CBaseEntity *v7; // eax
  int TeamNumber; // esi

  result = !staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity)
        && (v4 = (CBaseEntity *)pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity)) != nullptr
        && (m_pPassEnt = (IHandleEntity *)this->m_pPassEnt,
            !staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: m_pPassEnt))
        && (v7 = (CBaseEntity *)m_pPassEnt->__vftable[1].GetRefEHandle(this: m_pPassEnt)) != nullptr
        && (TeamNumber = CBaseEntity::GetTeamNumber(this: v7)) != CBaseEntity::GetTeamNumber(this: v4)
        && CTraceFilterSkipTwoEntities::ShouldHitEntity(this, pHandleEntity, contentsMask);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B4D50
// Name: public: virtual void CBasePlayer::Weapon_Equip(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Weapon_Equip(CBasePlayer *this, CBaseCombatWeapon *pWeapon)
{
  CBaseCombatCharacter::Weapon_Equip(this, pWeapon);
  if ( g_pGameRules->FShouldSwitchWeapon(this: g_pGameRules, a2: this, a3: pWeapon) )
    this->Weapon_Switch(this, a2: pWeapon, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B4D90
// Name: public: void CBasePlayer::LockPlayerInPlace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::LockPlayerInPlace(CBasePlayer *this)
{
  void (__thiscall *UpdateClientData)(CBasePlayer *); // edx

  if ( this->m_iPlayerLocked == 0 )
  {
    CBaseEntity::AddFlag(this, flags: 32832);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    UpdateClientData = this->UpdateClientData;
    this->m_iPlayerLocked = 1;
    UpdateClientData(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4DD0
// Name: public: void CBasePlayer::UnlockPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UnlockPlayer(CBasePlayer *this)
{
  if ( this->m_iPlayerLocked != 0 )
  {
    CBaseEntity::RemoveFlag(this, flagsToRemove: 32832);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_WALK, moveCollide: MOVECOLLIDE_DEFAULT);
    this->m_iPlayerLocked = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4E00
// Name: public: virtual class CBaseEntity __near * CBasePlayer::GetPotentialUseEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::GetPotentialUseEntity(CBasePlayer *this)
{
  return this->GetUseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B4E10
// Name: public: virtual struct datamap_t __near * CStripWeapons::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CStripWeapons::GetDataDescMap(CStripWeapons *this)
{
  return &CStripWeapons::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B4E20
// Name: public: virtual struct datamap_t __near * CRevertSaved::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRevertSaved::GetDataDescMap(CRevertSaved *this)
{
  return &CRevertSaved::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B4E30
// Name: public: void CRevertSaved::LoadThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRevertSaved::LoadThink(CRevertSaved *this)
{
  if ( !gpGlobals->deathmatch )
    engine->ServerCommand(this: engine, a2: "reload\n");
}

//------------------------------------------------------------------------------
// Address: 0x101B4E60
// Name: private: virtual struct datamap_t __near * CMovementSpeedMod::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMovementSpeedMod::GetDataDescMap(CMovementSpeedMod *this)
{
  return &CMovementSpeedMod::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B4E70
// Name: void SendProxy_CropFlagsToPlayerFlagBitsLength(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_CropFlagsToPlayerFlagBitsLength(
        const SendProp *pProp,
        const void *pStruct,
        _DWORD *pVarData,
        DVariant *pOut)
{
  pOut->m_Int = *pVarData & 0x7FF;
}

//------------------------------------------------------------------------------
// Address: 0x101B4E90
// Name: void __near * SendProxy_SendLocalDataTable(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_SendLocalDataTable(
        const SendProp *pProp,
        const void *pStruct,
        const void *pVarData,
        CSendProxyRecipients *pRecipients,
        int objectID)
{
  CSendProxyRecipients::SetOnly(this: pRecipients, iClient: objectID - 1);
  return (void *)pVarData;
}

//------------------------------------------------------------------------------
// Address: 0x101B4EB0
// Name: void __near * SendProxy_SendNonLocalDataTable(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_SendNonLocalDataTable(
        const SendProp *pProp,
        const void *pStruct,
        const void *pVarData,
        CSendProxyRecipients *pRecipients,
        int objectID)
{
  CSendProxyRecipients::ExcludeOnly(this: pRecipients, iClient: objectID - 1);
  return (void *)pVarData;
}

//------------------------------------------------------------------------------
// Address: 0x101B4ED0
// Name: public: virtual class ServerClass __near * CBasePlayer::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBasePlayer::GetServerClass(CBasePlayer *this)
{
  return &g_CBasePlayer_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101B4EF0
// Name: public: virtual void CBasePlayer::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::VPhysicsUpdate(CBasePlayer *this, IPhysicsObject *pPhysics)
{
  float savedImpact; // [esp+4h] [ebp-4h]

  savedImpact = this->m_impactEnergyScale;
  this->m_impactEnergyScale = savedImpact * 0.125;
  CBaseCombatCharacter::ApplyStressDamage(this, pPhysics, bRequireLargeObject: true);
  this->m_impactEnergyScale = savedImpact;
}

//------------------------------------------------------------------------------
// Address: 0x101B4F40
// Name: public: virtual void CBasePlayer::VPhysicsDestroyObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::VPhysicsDestroyObject(CBasePlayer *this)
{
  IPhysicsObject *m_pShadowStand; // ecx
  IPhysicsObject *m_pShadowCrouch; // ecx

  CBaseEntity::VPhysicsSetObject(this, pPhysics: nullptr);
  PhysRemoveShadow(pEntity: this);
  if ( this->m_pPhysicsController != nullptr )
  {
    physenv->DestroyPlayerController(this: physenv, a2: this->m_pPhysicsController);
    this->m_pPhysicsController = nullptr;
  }
  m_pShadowStand = this->m_pShadowStand;
  if ( m_pShadowStand != nullptr )
  {
    m_pShadowStand->EnableCollisions(this: m_pShadowStand, a2: false);
    PhysDestroyObject(pObject: this->m_pShadowStand, pEntity: nullptr);
    this->m_pShadowStand = nullptr;
  }
  m_pShadowCrouch = this->m_pShadowCrouch;
  if ( m_pShadowCrouch != nullptr )
  {
    m_pShadowCrouch->EnableCollisions(this: m_pShadowCrouch, a2: false);
    PhysDestroyObject(pObject: this->m_pShadowCrouch, pEntity: nullptr);
    this->m_pShadowCrouch = nullptr;
  }
  CBaseEntity::VPhysicsDestroyObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B4FE0
// Name: public: void CBasePlayer::SetPlayerName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetPlayerName(CBasePlayer *this, const char *name)
{
  if ( name != nullptr )
    V_strncpy(pDest: this->m_szNetname, pSrc: name, maxLen: 32);
}

//------------------------------------------------------------------------------
// Address: 0x101B5000
// Name: public: virtual char const __near * CPlayerInfo::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPlayerInfo::GetName(CPlayerInfo *this)
{
  return (*((const char *(__thiscall **)(IPlayerInfo_vtbl *))this->GetName + 40))(a1: this->IPlayerInfo::__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x101B5010
// Name: public: virtual int CPlayerInfo::GetTeamIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlayerInfo::GetTeamIndex(CPlayerInfo *this)
{
  return CBaseEntity::GetTeamNumber(this: (CBaseEntity *)this->IPlayerInfo::__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x101B5020
// Name: public: virtual void CPlayerInfo::ChangeTeam(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerInfo::ChangeTeam(CPlayerInfo *this, int iTeamNum)
{
  (*((void (__thiscall **)(IPlayerInfo_vtbl *, int))this->GetName + 93))(a1: this->IPlayerInfo::__vftable, a2: iTeamNum);
}

//------------------------------------------------------------------------------
// Address: 0x101B5040
// Name: public: virtual bool CPlayerInfo::IsPlayer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerInfo::IsPlayer(CPlayerInfo *this)
{
  return (*((bool (__thiscall **)(IPlayerInfo_vtbl *))this->GetName + 84))(a1: this->IPlayerInfo::__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x101B5050
// Name: public: virtual bool CPlayerInfo::IsFakeClient(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerInfo::IsFakeClient(CPlayerInfo *this)
{
  return (*((bool (__thiscall **)(IPlayerInfo_vtbl *))this->GetName + 358))(a1: this->IPlayerInfo::__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x101B5060
// Name: public: virtual bool CPlayerInfo::IsInAVehicle(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerInfo::IsInAVehicle(CPlayerInfo *this)
{
  return (*((bool (__thiscall **)(IPlayerInfo_vtbl *))this->GetName + 315))(a1: this->IPlayerInfo::__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x101B5070
// Name: public: virtual class Vector const CPlayerInfo::GetAbsOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CPlayerInfo::GetAbsOrigin(CPlayerInfo *this, const Vector *result)
{
  IPlayerInfo_vtbl *v2; // esi
  float v4; // ecx
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v2 = this->IPlayerInfo::__vftable;
  if ( ((int)v2[2].GetUserID & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)this->IPlayerInfo::__vftable, a2: (int)&savedregs);
  v4 = *(float *)&v2[4].GetHealth;
  *(_QWORD *)&result->x = *(_QWORD *)&v2[4].GetWeaponName;
  result->z = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B50B0
// Name: public: virtual class QAngle const CPlayerInfo::GetAbsAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CPlayerInfo::GetAbsAngles(CPlayerInfo *this, const QAngle *result)
{
  IPlayerInfo_vtbl *v2; // esi
  float v4; // ecx
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v2 = this->IPlayerInfo::__vftable;
  if ( ((int)v2[2].GetUserID & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)this->IPlayerInfo::__vftable, a2: (int)&savedregs);
  v4 = *(float *)&v2[5].GetName;
  *(_QWORD *)&result->x = *(_QWORD *)&v2[4].GetMaxHealth;
  result->z = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B50F0
// Name: public: virtual class Vector const CPlayerInfo::GetPlayerMins(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CPlayerInfo::GetPlayerMins(CPlayerInfo *this, const Vector *result)
{
  (*((void (__thiscall **)(IPlayerInfo_vtbl *, const Vector *))this->GetName + 360))(
    a1: this->IPlayerInfo::__vftable,
    a2: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B5110
// Name: public: virtual class Vector const CPlayerInfo::GetPlayerMaxs(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CPlayerInfo::GetPlayerMaxs(CPlayerInfo *this, const Vector *result)
{
  (*((void (__thiscall **)(IPlayerInfo_vtbl *, const Vector *))this->GetName + 361))(
    a1: this->IPlayerInfo::__vftable,
    a2: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B5130
// Name: public: virtual char const __near * CPlayerInfo::GetWeaponName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPlayerInfo::GetWeaponName(CPlayerInfo *this)
{
  const char *result; // eax

  result = (const char *)CBaseCombatCharacter::GetActiveWeapon(this: (CBaseCombatCharacter *)this->IPlayerInfo::__vftable);
  if ( result != nullptr )
    return (*(const char *(__thiscall **)(const char *))(*(_DWORD *)result + 1320))(a1: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B5150
// Name: public: virtual char const __near * CPlayerInfo::GetModelName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPlayerInfo::GetModelName(CPlayerInfo *this)
{
  const char *result; // eax
  CPlayerInfo *v2; // [esp+0h] [ebp-4h] BYREF

  v2 = this;
  result = *(const char **)(*((int (__thiscall **)(IPlayerInfo_vtbl *, CPlayerInfo **))this->GetName + 7))(
                             a1: this->IPlayerInfo::__vftable,
                             a2: &v2);
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B5180
// Name: public: virtual int const CPlayerInfo::GetMaxHealth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlayerInfo::GetMaxHealth(CPlayerInfo *this)
{
  return (*((int (__thiscall **)(IPlayerInfo_vtbl *))this->GetName + 119))(a1: this->IPlayerInfo::__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x101B5190
// Name: public: virtual void CPlayerInfo::SetAbsOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerInfo::SetAbsOrigin(CPlayerInfo *this, Vector *vec)
{
  if ( this->m_pParent->IsBot(this: this->m_pParent) )
    CBaseEntity::SetAbsOrigin(this: this->m_pParent, absOrigin: vec);
}

//------------------------------------------------------------------------------
// Address: 0x101B51C0
// Name: public: virtual void CPlayerInfo::SetAbsAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerInfo::SetAbsAngles(CPlayerInfo *this, QAngle *ang)
{
  if ( this->m_pParent->IsBot(this: this->m_pParent) )
    CBaseEntity::SetAbsAngles(this: this->m_pParent, absAngles: ang);
}

//------------------------------------------------------------------------------
// Address: 0x101B51F0
// Name: public: virtual void CPlayerInfo::RemoveAllItems(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerInfo::RemoveAllItems(CPlayerInfo *this, BOOL removeSuit)
{
  if ( this->m_pParent->IsBot(this: this->m_pParent) )
    this->m_pParent->RemoveAllItems(this: this->m_pParent, a2: removeSuit);
}

//------------------------------------------------------------------------------
// Address: 0x101B5220
// Name: public: virtual void CPlayerInfo::SetActiveWeapon(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerInfo::SetActiveWeapon(CPlayerInfo *this, const char *WeaponName)
{
  CBaseCombatWeapon *v3; // edi

  if ( this->m_pParent->IsBot(this: this->m_pParent) )
  {
    v3 = CBaseCombatCharacter::Weapon_Create(this: this->m_pParent, pWeaponName: WeaponName);
    if ( v3 != nullptr )
    {
      this->m_pParent->Weapon_Equip(this: this->m_pParent, a2: v3);
      this->m_pParent->Weapon_Switch(this: this->m_pParent, a2: v3, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5270
// Name: public: virtual void CPlayerInfo::SetLocalOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerInfo::SetLocalOrigin(CPlayerInfo *this, const Vector *origin)
{
  if ( this->m_pParent->IsBot(this: this->m_pParent) )
    CBaseEntity::SetLocalOrigin(this: this->m_pParent, origin);
}

//------------------------------------------------------------------------------
// Address: 0x101B52A0
// Name: public: virtual void CPlayerInfo::SetLocalAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerInfo::SetLocalAngles(CPlayerInfo *this, const QAngle *angles)
{
  if ( this->m_pParent->IsBot(this: this->m_pParent) )
    CBaseEntity::SetLocalAngles(this: this->m_pParent, angles);
}

//------------------------------------------------------------------------------
// Address: 0x101B52D0
// Name: public: virtual void CPlayerInfo::PostClientMessagesSent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerInfo::PostClientMessagesSent(CPlayerInfo *this)
{
  if ( this->m_pParent->IsBot(this: this->m_pParent) )
    CBaseEntity::PostClientMessagesSent(this: this->m_pParent);
}

//------------------------------------------------------------------------------
// Address: 0x101B52F0
// Name: public: virtual bool CPlayerInfo::IsEFlagSet(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerInfo::IsEFlagSet(CPlayerInfo *this, int nEFlagMask)
{
  return this->m_pParent->IsBot(this: this->m_pParent) && (nEFlagMask & this->m_pParent->m_iEFlags) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B5330
// Name: public: virtual void CBasePlayer::Event_KilledOther(class CBaseEntity __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Event_KilledOther(CBasePlayer *this, CBasePlayer *pVictim, const CTakeDamageInfo *info)
{
  if ( pVictim != this )
    gamestats->Event_PlayerKilledOther(this: gamestats, a2: this, a3: pVictim, a4: info);
}

//------------------------------------------------------------------------------
// Address: 0x101B5360
// Name: public: bool CBasePlayer::IsSplitScreenPlayer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::IsSplitScreenPlayer(CBasePlayer *this)
{
  return this->m_bSplitScreenPlayer;
}

//------------------------------------------------------------------------------
// Address: 0x101B5370
// Name: public: void CBasePlayer::SetCrossPlayPlatform(enum CrossPlayPlatform_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetCrossPlayPlatform(CBasePlayer *this, CrossPlayPlatform_t clientPlatform)
{
  this->m_ClientPlatform = clientPlatform;
}

//------------------------------------------------------------------------------
// Address: 0x101B5380
// Name: public: virtual unsigned int CBasePlayer::PlayerSolidMask(bool)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::PlayerSolidMask(CBasePlayer *this, bool brushOnly)
{
  return brushOnly ? 81931 : 33636363;
}

//------------------------------------------------------------------------------
// Address: 0x101B53A0
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
// Address: 0x101B5490
// Name: float SimpleSplineRemapValClamped(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SimpleSplineRemapValClamped(float val, float A, float B, float C, float D)
{
  float v6; // xmm0_4
  int v7; // xmm1_4
  float Aa; // [esp+Ch] [ebp+Ch]

  if ( A == B )
  {
    if ( val < B )
      return C;
    else
      return D;
  }
  else
  {
    v6 = (float)(val - A) / (float)(B - A);
    v7 = 0;
    if ( v6 < 0.0 || (v7 = 1065353216, v6 > 1.0) )
      Aa = *(float *)&v7;
    else
      Aa = (float)(val - A) / (float)(B - A);
    return C + (D - C) * (3.0 * (Aa * Aa) - Aa * (Aa * Aa + Aa * Aa));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5530
// Name: class IScriptInstanceHelper __near * GetScriptInstanceHelper_CBasePlayer(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
IScriptInstanceHelper *__cdecl GetScriptInstanceHelper_CBasePlayer()
{
  return GetScriptInstanceHelper_CBaseAnimating();
}

//------------------------------------------------------------------------------
// Address: 0x101B5540
// Name: public: float CTakeDamageInfo::GetBaseDamage(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTakeDamageInfo::GetBaseDamage(CTakeDamageInfo *this)
{
  if ( this->m_flBaseDamage == 3.4028235e38 )
    return this->m_flDamage;
  else
    return this->m_flBaseDamage;
}

//------------------------------------------------------------------------------
// Address: 0x101B5570
// Name: public: virtual int CBasePlayer::TakeHealth(float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::TakeHealth(CBasePlayer *this, float flHealth, int bitsDamageType)
{
  if ( this->m_takedamage.m_Value != 0 )
    this->m_bitsDamageType &= ~(bitsDamageType & ~g_pGameRules->Damage_GetTimeBased(this: g_pGameRules));
  return CBaseCombatCharacter::TakeHealth(this, flHealth, bitsDamageType);
}

//------------------------------------------------------------------------------
// Address: 0x101B55C0
// Name: public: virtual void CBasePlayer::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::DrawDebugGeometryOverlays(CBasePlayer *this)
{
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v3; // eax
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  float v9; // xmm1_4
  Vector origin; // [esp+10h] [ebp-3Ch] BYREF
  Vector target; // [esp+1Ch] [ebp-30h] BYREF
  Vector vBodyDir; // [esp+28h] [ebp-24h] BYREF
  float v13; // [esp+34h] [ebp-18h]
  float v14; // [esp+38h] [ebp-14h]
  float v15; // [esp+3Ch] [ebp-10h]
  float v16; // [esp+40h] [ebp-Ch]
  float v17; // [esp+44h] [ebp-8h]
  float v18; // [esp+48h] [ebp-4h]

  if ( (this->m_debugOverlays & 0x2000000) != 0 && this->m_iHealth.m_Value == 1 )
  {
    this->BodyDirection2D(this, result: &vBodyDir);
    EyePosition = this->EyePosition;
    target.x = vBodyDir.x * 10.0;
    target.y = vBodyDir.y * 10.0;
    target.z = vBodyDir.z * 10.0;
    v3 = (float *)EyePosition(this, result: &origin);
    v4 = v3[1] + target.y;
    v5 = v3[2] + target.z;
    v6 = (float)(vBodyDir.x * 0.0) - (float)(vBodyDir.y * 0.0);
    v7 = (float)(vBodyDir.y * 8.0) - (float)(vBodyDir.z * 0.0);
    v8 = *v3 + target.x;
    v9 = (float)(vBodyDir.z * 0.0) - (float)(vBodyDir.x * 8.0);
    v15 = v8 + v7;
    origin.x = v8 + v7;
    v18 = v4 - v9;
    v17 = v8 - v7;
    v16 = v5 - v6;
    target.x = v8 - v7;
    v13 = v6 + v5;
    target.y = v4 - v9;
    target.z = (float)(v5 - v6) - 8.0;
    v14 = v9 + v4;
    origin.y = v9 + v4;
    origin.z = (float)(v6 + v5) + 8.0;
    NDebugOverlay::Line(&origin, &target, r: 255, g: 0, b: 0, noDepthTest: false, duration: 0.0);
    origin.x = v17;
    origin.y = v18;
    origin.z = v16 + 8.0;
    target.x = v15;
    target.y = v14;
    target.z = v13 - 8.0;
    NDebugOverlay::Line(origin: &target, target: &origin, r: 255, g: 0, b: 0, noDepthTest: false, duration: 0.0);
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B57C0
// Name: public: virtual void CBasePlayer::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::TraceAttack(
        CBasePlayer *this,
        const CTakeDamageInfo *inputInfo,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  IHandleEntity *m_pEntity; // ecx
  int v6; // eax
  int v7; // esi
  IHandleEntity *v8; // eax
  CBaseEntity *v9; // eax
  float flDamage; // xmm0_4
  int v11; // eax
  CTakeDamageInfo info; // [esp+28h] [ebp-5Ch] BYREF

  if ( this->m_takedamage.m_Value != 0 )
  {
    if ( (CTakeDamageInfo::CTakeDamageInfo(this: &info, __that: inputInfo), info.m_hAttacker.m_Index == -1)
      || g_pEntityList->m_EntPtrArray[LOWORD(info.m_hAttacker.m_Index)].m_SerialNumber != HIWORD(info.m_hAttacker.m_Index)
      || g_pEntityList->m_EntPtrArray[LOWORD(info.m_hAttacker.m_Index)].m_pEntity == nullptr
      || (g_pEntityList->m_EntPtrArray[LOWORD(info.m_hAttacker.m_Index)].m_SerialNumber != HIWORD(info.m_hAttacker.m_Index)
        ? (m_pEntity = nullptr)
        : (m_pEntity = g_pEntityList->m_EntPtrArray[LOWORD(info.m_hAttacker.m_Index)].m_pEntity),
          (v6 = (int)m_pEntity->__vftable[24].GetRefEHandle(this: m_pEntity), v7 = v6, v6 == 0)
       || ((*(int (__thiscall **)(int))(*(_DWORD *)v6 + 1916))(a1: v6) & 0x10000000) == 0
       || (*(int (__thiscall **)(int, CBasePlayer *))(*(_DWORD *)v7 + 1252))(a1: v7, a2: this) == 1)
      && (info.m_hAttacker.m_Index == -1
       || g_pEntityList->m_EntPtrArray[LOWORD(info.m_hAttacker.m_Index)].m_SerialNumber != HIWORD(info.m_hAttacker.m_Index)
        ? (v8 = nullptr)
        : (v8 = g_pEntityList->m_EntPtrArray[LOWORD(info.m_hAttacker.m_Index)].m_pEntity),
          ((unsigned __int8 (__thiscall *)(IHandleEntity *))v8->__vftable[28].dtr_IHandleEntity)(a1: v8) == 0
       || (info.m_hAttacker.m_Index == -1
        || g_pEntityList->m_EntPtrArray[LOWORD(info.m_hAttacker.m_Index)].m_SerialNumber != HIWORD(info.m_hAttacker.m_Index)
         ? (v9 = nullptr)
         : (v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(info.m_hAttacker.m_Index)].m_pEntity),
           g_pGameRules->FPlayerCanTakeDamage(this: g_pGameRules, a2: this, a3: v9))) )
    {
      this->m_LastHitGroup = ptr->hitgroup;
      switch ( ptr->hitgroup )
      {
        case 1:
          flDamage = sk_player_head.m_pParent->m_Value.m_fValue * info.m_flDamage;
          info.m_flDamage = flDamage;
          break;
        case 2:
          flDamage = sk_player_chest.m_pParent->m_Value.m_fValue * info.m_flDamage;
          info.m_flDamage = flDamage;
          break;
        case 3:
          flDamage = sk_player_stomach.m_pParent->m_Value.m_fValue * info.m_flDamage;
          info.m_flDamage = flDamage;
          break;
        case 4:
        case 5:
          flDamage = sk_player_arm.m_pParent->m_Value.m_fValue * info.m_flDamage;
          info.m_flDamage = flDamage;
          break;
        case 6:
        case 7:
          flDamage = sk_player_leg.m_pParent->m_Value.m_fValue * info.m_flDamage;
          info.m_flDamage = flDamage;
          break;
        default:
          flDamage = info.m_flDamage;
          break;
      }
      v11 = this->BloodColor(this);
      SpawnBlood(vecSpot: ptr->endpos, vecDir, bloodColor: v11, flDamage);
      CBaseEntity::TraceBleed(this, flDamage: info.m_flDamage, vecDir, ptr, bitsDamageType: info.m_bitsDamageType);
      AddMultiDamage(&info, pEntity: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B59F0
// Name: public: bool CBasePlayer::ShouldTakeDamageInCommentaryMode(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::ShouldTakeDamageInCommentaryMode(CBasePlayer *this, const CTakeDamageInfo *inputInfo)
{
  bool result; // al
  unsigned int m_Index; // eax
  CBasePlayer *m_pEntity; // edx
  unsigned int v6; // eax
  CBasePlayer *v7; // edx
  int m_bitsDamageType; // eax
  unsigned int v9; // eax
  CBaseEntity *Attacker; // eax

  if ( !IsListeningToCommentary() )
    return true;
  m_Index = inputInfo->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  result = true;
  if ( m_pEntity != this
    || ((v6 = inputInfo->m_hAttacker.m_Index) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6)
      ? (v7 = nullptr)
      : (v7 = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity),
        v7 != this) )
  {
    m_bitsDamageType = inputInfo->m_bitsDamageType;
    if ( (m_bitsDamageType & 0x1000029) == 0 && m_bitsDamageType != 0 )
      return false;
    if ( (m_bitsDamageType & 1) != 0 )
    {
      v9 = inputInfo->m_hAttacker.m_Index;
      if ( v9 == -1 )
        return false;
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
        return false;
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity == nullptr )
        return false;
      Attacker = CTakeDamageInfo::GetAttacker(this: inputInfo);
      if ( !CBaseEntity::IsBSPModel(this: Attacker) )
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B5AC0
// Name: public: virtual void CBasePlayer::OnDamagedByExplosion(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CBasePlayer::OnDamagedByExplosion(CBasePlayer *this@<ecx>, int a2@<ebp>, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  CBaseEntity **v5; // ecx
  CBaseEntity *v6; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  __int128 v9; // xmm0
  char v10; // al
  int v11; // eax
  int v12; // esi
  _DWORD v13[3]; // [esp-Ch] [ebp-4Ch] BYREF
  __int128 user_20; // [esp+14h] [ebp-2Ch] OVERLAPPED
  float m_flDamage; // [esp+30h] [ebp-10h]
  _DWORD v16[2]; // [esp+34h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+40h] [ebp+0h]

  v16[0] = a2;
  v16[1] = retaddr;
  m_Index = info->m_hInflictor.m_Index;
  m_flDamage = info->m_flDamage;
  if ( m_Index == -1 )
    goto LABEL_10;
  v5 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    goto LABEL_10;
  v6 = *v5;
  if ( *v5 == nullptr )
    goto LABEL_10;
  if ( (v6->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: *v5, a2: (int)v16);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)v16);
  v7 = this->m_vecAbsOrigin.x - v6->m_vecAbsOrigin.x;
  v8 = (float)((float)((float)(this->m_vecAbsOrigin.y - v6->m_vecAbsOrigin.y)
                     * (float)(this->m_vecAbsOrigin.y - v6->m_vecAbsOrigin.y))
             + (float)((float)(this->m_vecAbsOrigin.z - v6->m_vecAbsOrigin.z)
                     * (float)(this->m_vecAbsOrigin.z - v6->m_vecAbsOrigin.z)))
     + (float)(v7 * v7);
  v9 = 0;
  *(float *)&v9 = fsqrt(v8);
  user_20 = v9;
  if ( *(float *)&v9 < 240.0 )
    v10 = 1;
  else
LABEL_10:
    v10 = 0;
  if ( m_flDamage >= 30.0 )
  {
    v11 = random->RandomInt(this: random, a2: 35, a3: 37);
  }
  else
  {
    if ( v10 == 0 )
      return;
    v11 = random->RandomInt(this: random, a2: 32, a3: 34);
  }
  v12 = v11;
  CRecipientFilter::CRecipientFilter(this: (CRecipientFilter *)v13);
  v13[0] = &CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: (CRecipientFilter *)v13, player: this);
  enginesound->SetPlayerDSP(this: enginesound, a2: (IRecipientFilter *)v13, a3: v12, a4: false);
  CRecipientFilter::~CRecipientFilter(this: (CRecipientFilter *)v13);
}

//------------------------------------------------------------------------------
// Address: 0x101B5C20
// Name: public: virtual void CBasePlayer::PackDeadPlayerItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::PackDeadPlayerItems(CBasePlayer *this)
{
  int v2; // esi
  int (__thiscall *DeadPlayerAmmo)(CGameRules *, CBasePlayer *); // edx
  int v4; // eax
  CBaseCombatWeapon **v5; // ebx
  CBaseCombatWeapon *Weapon; // esi
  int v7; // esi
  char *v8; // ebx
  char v9; // [esp+8h] [ebp-90h] BYREF
  CBaseCombatWeapon *rgpPackWeapons[20]; // [esp+3Ch] [ebp-5Ch] BYREF
  int iWeaponRules; // [esp+8Ch] [ebp-Ch]
  int iAmmoRules; // [esp+90h] [ebp-8h]
  int i; // [esp+94h] [ebp-4h]

  v2 = g_pGameRules->DeadPlayerWeapons(this: g_pGameRules, a2: this);
  DeadPlayerAmmo = g_pGameRules->DeadPlayerAmmo;
  iWeaponRules = v2;
  v4 = DeadPlayerAmmo(this: g_pGameRules, a2: this);
  iAmmoRules = v4;
  if ( v2 == 9 && v4 == 12 )
  {
    this->RemoveAllItems(this, a2: true);
  }
  else
  {
    i = 0;
    v5 = rgpPackWeapons;
    do
    {
      Weapon = CBaseCombatCharacter::GetWeapon(this, i);
      if ( Weapon != nullptr
        && (iWeaponRules == 7
         || iWeaponRules == 8
         && CBaseCombatCharacter::GetActiveWeapon(this) != nullptr
         && Weapon == CBaseCombatCharacter::GetActiveWeapon(this)) )
      {
        ++v5;
      }
      ++i;
    }
    while ( i < 64 );
    if ( iAmmoRules != 12 )
    {
      v7 = 0;
      v8 = &v9;
      do
      {
        if ( CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v7) > 0 && iAmmoRules == 10 )
          v8 += 4;
        ++v7;
      }
      while ( v7 < 32 );
    }
    this->RemoveAllItems(this, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5D00
// Name: public: bool CBasePlayer::IsDead(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBasePlayer::IsDead(CBasePlayer *this)
{
  return this->m_lifeState.m_Value == 2;
}

//------------------------------------------------------------------------------
// Address: 0x101B5D10
// Name: public: virtual void CBasePlayer::ShowViewPortPanel(char const __near *,bool,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ShowViewPortPanel(CBasePlayer *this, const char *name, bool bShow, KeyValues *data)
{
  unsigned int v5; // edi
  KeyValues *FirstSubKey; // esi
  KeyValues *i; // eax
  const char *v8; // eax
  const char *String; // eax
  CSingleUserRecipientFilter filter; // [esp+Ch] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &filter, player: this);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  v5 = 0;
  FirstSubKey = nullptr;
  if ( data != nullptr )
  {
    for ( i = KeyValues::GetFirstSubKey(this: data); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      ++v5;
    FirstSubKey = KeyValues::GetFirstSubKey(this: data);
  }
  UserMessageBegin(&filter, messagename: "VGUIMenu");
  MessageWriteString(sz: name);
  MessageWriteByte(iValue: bShow);
  MessageWriteByte(iValue: v5);
  for ( ; FirstSubKey != nullptr; FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey) )
  {
    v8 = KeyValues::GetName(this: FirstSubKey);
    MessageWriteString(sz: v8);
    String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: locale);
    MessageWriteString(sz: String);
  }
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x101B5DF0
// Name: public: virtual int CBasePlayer::GetObserverMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::GetObserverMode(CBasePlayer *this)
{
  return this->m_iObserverMode.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101B5E00
// Name: public: virtual void CBasePlayer::ForceObserverMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ForceObserverMode(CBasePlayer *this, int mode)
{
  int m_iObserverLastMode; // edi

  m_iObserverLastMode = 6;
  if ( this->m_iObserverMode.m_Value != mode )
  {
    if ( this->m_bForcedObserverMode )
      m_iObserverLastMode = this->m_iObserverLastMode;
    this->SetObserverMode(this, a2: mode);
    if ( this->m_bForcedObserverMode )
      this->m_iObserverLastMode = m_iObserverLastMode;
    this->m_bForcedObserverMode = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5E50
// Name: public: virtual class CBaseEntity __near * CBasePlayer::GetObserverTarget(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::GetObserverTarget(CBasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hObserverTarget.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101B5E80
// Name: public: virtual int CBasePlayer::GetNextObserverSearchStartPoint(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::GetNextObserverSearchStartPoint(CBasePlayer *this, bool bReverse)
{
  unsigned int m_Index; // edx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  edict_t *m_pPev; // eax
  int result; // eax

  m_Index = this->m_hObserverTarget.m_Value.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v5 = HIWORD(m_Index),
        v4->m_SerialNumber == v5)
    && v4->m_pEntity != nullptr )
  {
    v6 = v3;
    v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
    v8 = &g_pEntityList->m_EntPtrArray[v6];
    if ( v7 )
      m_pPev = (edict_t *)v8->m_pEntity[6].__vftable;
    else
      m_pPev = (edict_t *)MEMORY[0x18];
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
  }
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  result = (int)m_pPev + 2 * !bReverse - 1;
  if ( result > gpGlobals->maxClients )
    return 1;
  if ( result < 1 )
    return gpGlobals->maxClients;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B5F10
// Name: public: virtual void CBasePlayer::UpdateGeigerCounter(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayer::UpdateGeigerCounter(CBasePlayer *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  float curtime; // xmm0_4
  int v5; // xmm1_4
  float v6; // xmm0_4
  int v7; // ebx
  char v8; // al
  CSingleUserRecipientFilter user; // [esp+0h] [ebp-20h] BYREF

  curtime = gpGlobals->curtime;
  if ( this->m_flgeigerDelay <= curtime )
  {
    v5 = 0;
    this->m_flgeigerDelay = curtime + 0.25;
    v6 = this->m_flgeigerRange * 0.25;
    if ( v6 < 0.0 || (v5 = 1132396544, v6 > 255.0) )
      v6 = *(float *)&v5;
    v7 = (int)v6;
    if ( ((unsigned __int8 (__thiscall *)(CBasePlayer *, int, int))this->IsInAVehicle)(a1: this, a2: a3, a3: a2) != 0 )
    {
      v8 = 4 * v7;
      if ( 4 * (unsigned int)(unsigned __int8)v7 > 0xFF )
        v8 = -1;
      LOBYTE(v7) = v8;
    }
    if ( (unsigned __int8)v7 != this->m_igeigerRangePrev )
    {
      this->m_igeigerRangePrev = (unsigned __int8)v7;
      CRecipientFilter::CRecipientFilter(this: &user);
      user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
      CRecipientFilter::AddRecipient(this: &user, player: this);
      CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
      UserMessageBegin(filter: &user, messagename: "Geiger");
      MessageWriteByte(iValue: (unsigned __int8)v7);
      MessageEnd();
      CRecipientFilter::~CRecipientFilter(this: &user);
    }
    if ( random->RandomInt(this: random, a2: 0, a3: 3) == 0 )
      this->m_flgeigerRange = 1000.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6020
// Name: void FixPlayerCrouchStuck(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall FixPlayerCrouchStuck(int a1@<ebp>, float *a2@<edi>, int a3@<esi>, CBasePlayer *pPlayer)
{
  float z; // ecx
  float *v5; // edi
  const CViewVectors *v6; // eax
  float v7; // xmm7_4
  float x; // xmm4_4
  float y; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm6_4
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  float v17; // eax
  float *v18; // edi
  const CViewVectors *v19; // eax
  float v20; // xmm7_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm6_4
  void (__thiscall *v29)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  float v30; // eax
  Vector v33; // [esp+2Ch] [ebp-F4h] BYREF
  _BYTE trace[88]; // [esp+38h] [ebp-E8h] OVERLAPPED BYREF
  float v35; // [esp+90h] [ebp-90h]
  Vector org; // [esp+94h] [ebp-8Ch] BYREF
  float v37[12]; // [esp+A4h] [ebp-7Ch] BYREF
  float v38; // [esp+D4h] [ebp-4Ch]
  float v39; // [esp+D8h] [ebp-48h]
  float v40; // [esp+DCh] [ebp-44h]
  int v41; // [esp+E4h] [ebp-3Ch]
  bool v42; // [esp+E8h] [ebp-38h]
  bool v43; // [esp+E9h] [ebp-37h]
  Vector v44; // [esp+FCh] [ebp-24h] BYREF
  Vector origin; // [esp+108h] [ebp-18h]
  _DWORD v46[2]; // [esp+114h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+120h] [ebp+0h]

  v46[0] = a1;
  v46[1] = retaddr;
  if ( (pPlayer->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)v46);
  z = pPlayer->m_vecAbsOrigin.z;
  *(_QWORD *)&trace[80] = *(_QWORD *)&pPlayer->m_vecAbsOrigin.x;
  v35 = z;
  origin.z = 0.0;
  while ( 1 )
  {
    if ( (pPlayer->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)v46);
    if ( (pPlayer->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)v46);
    v5 = (float *)((int (__thiscall *)(CGameRules *, float *, int, _DWORD, _DWORD))g_pGameRules->GetViewVectors)(
                    a1: g_pGameRules,
                    a2,
                    a3,
                    a4: LODWORD(v33.x),
                    a5: LODWORD(v33.y));
    v6 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    memset(&v37[4], 0, 12);
    v41 = 0;
    v43 = (float)((float)((float)(0.0 * 0.0) + (float)(0.0 * 0.0)) + (float)(0.0 * 0.0)) != 0.0;
    v7 = v5[12];
    x = v6->m_vDuckHullMin.x;
    y = v6->m_vDuckHullMin.y;
    v10 = v5[14];
    v11 = v6->m_vDuckHullMin.z;
    origin.y = v5[13];
    v38 = (float)(v7 - x) * 0.5;
    v39 = (float)(origin.y - y) * 0.5;
    origin.x = v10;
    v40 = (float)(v10 - v11) * 0.5;
    v42 = (float)((float)((float)(v39 * v39) + (float)(v38 * v38)) + (float)(v40 * v40)) < 0.000001;
    v12 = y + origin.y;
    v13 = (float)(x + v7) * 0.5;
    v37[0] = v13 + pPlayer->m_vecAbsOrigin.x;
    v14 = (float)(v12 * 0.5) + pPlayer->m_vecAbsOrigin.y;
    v33.y = 0.0;
    v15 = (float)(v11 + v10) * 0.5;
    v37[1] = v14;
    v37[2] = v15 + pPlayer->m_vecAbsOrigin.z;
    v37[8] = v13 * -1.0;
    v37[9] = (float)(v12 * 0.5) * -1.0;
    v37[10] = v15 * -1.0;
    CTraceFilterSimple::CTraceFilterSimple(
      this: (CTraceFilterSimple *)&org,
      passedict: pPlayer,
      collisionGroup: 8,
      pExtraShouldHitFunc: nullptr);
    TraceRay = enginetrace->TraceRay;
    LODWORD(v33.y) = &v33;
    LODWORD(v33.x) = &org;
    a3 = 33636363;
    a2 = v37;
    ((void (__thiscall *)(IEngineTrace *))TraceRay)(a1: enginetrace);
    if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      DebugDrawLine(
        vecAbsStart: &v33,
        vecAbsEnd: (const Vector *)trace,
        r: 255,
        g: 255,
        b: 0,
        test: true,
        duration: -1.0);
    if ( trace[43] == 0 )
      break;
    if ( (pPlayer->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)v46);
    v17 = pPlayer->m_vecAbsOrigin.z;
    *(_QWORD *)&v44.x = *(_QWORD *)&pPlayer->m_vecAbsOrigin.x;
    v44.z = v17 + 1.0;
    CBaseEntity::SetLocalOrigin(this: pPlayer, origin: &v44);
    ++LODWORD(origin.z);
    if ( SLODWORD(origin.z) >= 18 )
    {
      CBaseEntity::SetAbsOrigin(this: pPlayer, absOrigin: (const Vector *)&trace[80]);
      origin.z = 0.0;
      do
      {
        if ( (pPlayer->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)v46);
        if ( (pPlayer->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)v46);
        v18 = (float *)((int (__thiscall *)(CGameRules *, float *, int, _DWORD, _DWORD))g_pGameRules->GetViewVectors)(
                         a1: g_pGameRules,
                         a2: v37,
                         a3: 33636363,
                         a4: LODWORD(v33.x),
                         a5: LODWORD(v33.y));
        v19 = g_pGameRules->GetViewVectors(this: g_pGameRules);
        memset(&v37[4], 0, 12);
        v41 = 0;
        v43 = (float)((float)((float)(0.0 * 0.0) + (float)(0.0 * 0.0)) + (float)(0.0 * 0.0)) != 0.0;
        v20 = v18[12];
        v21 = v19->m_vDuckHullMin.x;
        v22 = v19->m_vDuckHullMin.y;
        v23 = v18[14];
        v24 = v19->m_vDuckHullMin.z;
        origin.x = v18[13];
        v38 = (float)(v20 - v21) * 0.5;
        v39 = (float)(origin.x - v22) * 0.5;
        origin.y = v23;
        v40 = (float)(v23 - v24) * 0.5;
        v42 = (float)((float)((float)(v39 * v39) + (float)(v38 * v38)) + (float)(v40 * v40)) < 0.000001;
        v25 = v22 + origin.x;
        v26 = (float)(v21 + v20) * 0.5;
        v37[0] = v26 + pPlayer->m_vecAbsOrigin.x;
        v27 = (float)(v25 * 0.5) + pPlayer->m_vecAbsOrigin.y;
        v33.y = 0.0;
        v28 = (float)(v24 + v23) * 0.5;
        v37[1] = v27;
        v37[2] = v28 + pPlayer->m_vecAbsOrigin.z;
        v37[8] = v26 * -1.0;
        v37[9] = (float)(v25 * 0.5) * -1.0;
        v37[10] = v28 * -1.0;
        CTraceFilterSimple::CTraceFilterSimple(
          this: (CTraceFilterSimple *)&org,
          passedict: pPlayer,
          collisionGroup: 8,
          pExtraShouldHitFunc: nullptr);
        v29 = enginetrace->TraceRay;
        LODWORD(v33.y) = &v33;
        LODWORD(v33.x) = &org;
        ((void (__thiscall *)(IEngineTrace *))v29)(a1: enginetrace);
        if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
          DebugDrawLine(
            vecAbsStart: &v33,
            vecAbsEnd: (const Vector *)trace,
            r: 255,
            g: 255,
            b: 0,
            test: true,
            duration: -1.0);
        if ( trace[43] == 0 )
          break;
        if ( (pPlayer->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)v46);
        v30 = pPlayer->m_vecAbsOrigin.z;
        *(_QWORD *)&v44.x = *(_QWORD *)&pPlayer->m_vecAbsOrigin.x;
        v44.z = v30 - 1.0;
        CBaseEntity::SetLocalOrigin(this: pPlayer, origin: &v44);
        ++LODWORD(origin.z);
      }
      while ( SLODWORD(origin.z) < 18 );
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6560
// Name: class CBaseEntity __near * FindPlayerStart(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl FindPlayerStart(const char *pszClassName)
{
  CBaseEntity *result; // eax
  CBaseEntity *v2; // edi

  result = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: pszClassName);
  v2 = result;
  if ( result == nullptr )
    return v2;
  while ( (result->m_spawnflags.m_Value & 1) == 0 )
  {
    result = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: result, szName: pszClassName);
    if ( result == nullptr )
      return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B65A0
// Name: public: virtual class CBaseEntity __near * CBasePlayer::EntSelectSpawnPoint(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::EntSelectSpawnPoint(CBasePlayer *this)
{
  CGameRules_vtbl *v2; // edx
  CBaseEntity *EntityByClassname; // esi
  const char *pszValue; // esi
  int i; // edi
  CBaseEntity *v7; // edi
  CBaseEntity *v8; // eax
  CBaseEntity *j; // edi
  edict_t *v10; // eax
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v12; // ebx
  edict_t *v13; // eax
  IServerUnknown *v14; // ecx
  CBaseEntity *v15; // eax
  const CTakeDamageInfo *v16; // eax
  edict_t *pEdicts; // esi
  edict_t *v18; // eax
  IServerUnknown *v19; // ecx
  CEntitySphereQuery sphere; // [esp+2Ch] [ebp-868h] BYREF
  CTakeDamageInfo v21; // [esp+834h] [ebp-60h] BYREF
  edict_t *player; // [esp+890h] [ebp-4h]
  int savedregs; // [esp+894h] [ebp+0h] BYREF

  v2 = g_pGameRules->__vftable;
  player = this->m_Network.m_pPev;
  if ( v2->IsCoOp(this: g_pGameRules) )
  {
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: g_pLastSpawn,
                          szName: "info_player_coop");
    if ( EntityByClassname != nullptr )
      goto LABEL_7;
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: g_pLastSpawn,
                          szName: "info_player_start");
    if ( EntityByClassname != nullptr )
      goto LABEL_7;
  }
  else if ( g_pGameRules->IsDeathmatch(this: g_pGameRules) )
  {
    EntityByClassname = g_pLastSpawn;
    for ( i = random->RandomInt(this: random, a2: 1, a3: 5);
          i > 0;
          EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                                this: &gEntList,
                                pStartEntity: EntityByClassname,
                                szName: "info_player_deathmatch") )
    {
      --i;
    }
    if ( EntityByClassname == nullptr )
      EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                            this: &gEntList,
                            pStartEntity: nullptr,
                            szName: "info_player_deathmatch");
    v7 = EntityByClassname;
    while ( EntityByClassname == nullptr
         || !g_pGameRules->IsSpawnPointValid(this: g_pGameRules, a2: EntityByClassname, a3: this)
         || vec3_origin.x == EntityByClassname->m_vecOrigin.m_Value.x
         && vec3_origin.y == EntityByClassname->m_vecOrigin.m_Value.y
         && vec3_origin.z == EntityByClassname->m_vecOrigin.m_Value.z )
    {
      v8 = CGlobalEntityList::FindEntityByClassname(
             this: &gEntList,
             pStartEntity: EntityByClassname,
             szName: "info_player_deathmatch");
      EntityByClassname = v8;
      if ( v8 == v7 )
      {
        if ( v8 == nullptr )
          goto LABEL_4;
        if ( (v8->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v8, a2: (int)&savedregs);
        CEntitySphereQuery::CEntitySphereQuery(
          this: &sphere,
          center: &EntityByClassname->m_vecAbsOrigin,
          radius: 128.0,
          flagMask: 0);
        for ( j = CEntitySphereQuery::GetCurrentEntity(this: &sphere);
              j != nullptr;
              j = CEntitySphereQuery::GetCurrentEntity(this: &sphere) )
        {
          if ( j->IsPlayer(this: j) && j->m_Network.m_pPev != player )
          {
            v10 = INDEXENT(iEdictNum: 0);
            if ( v10 != nullptr && (m_pUnk = v10->m_pUnk) != nullptr )
              v12 = m_pUnk->GetBaseEntity(this: m_pUnk);
            else
              v12 = nullptr;
            v13 = INDEXENT(iEdictNum: 0);
            if ( v13 != nullptr && (v14 = v13->m_pUnk) != nullptr )
              v15 = v14->GetBaseEntity(this: v14);
            else
              v15 = nullptr;
            v16 = CTakeDamageInfo::CTakeDamageInfo(
                    this: &v21,
                    pInflictor: v15,
                    pAttacker: v12,
                    flDamage: 300.0,
                    bitsDamageType: 0,
                    iKillType: 0,
                    iObjectsPenetrated: 0);
            CBaseEntity::TakeDamage(this: j, a2: (int)EntityByClassname, inputInfo: v16);
          }
          ++sphere.m_listIndex;
        }
        break;
      }
    }
ReturnSpot:
    if ( EntityByClassname != nullptr )
      goto LABEL_7;
    goto LABEL_39;
  }
LABEL_4:
  pszValue = gpGlobals->startspot.pszValue;
  if ( pszValue == nullptr || strlen(gpGlobals->startspot.pszValue) == 0 )
  {
    EntityByClassname = FindPlayerStart(pszClassName: "info_player_start");
    goto ReturnSpot;
  }
  EntityByClassname = CGlobalEntityList::FindEntityByName(
                        this: &gEntList,
                        pStartEntity: nullptr,
                        szName: pszValue,
                        pSearchingEntity: nullptr,
                        pActivator: nullptr,
                        pCaller: nullptr,
                        pFilter: nullptr);
  if ( EntityByClassname != nullptr )
  {
LABEL_7:
    g_pLastSpawn = EntityByClassname;
    return EntityByClassname;
  }
LABEL_39:
  _Warning(a1: "PutClientInServer: no info_player_start on level\n");
  pEdicts = gpGlobals->pEdicts;
  if ( pEdicts != nullptr )
    v18 = (pEdicts->m_fStateFlags & 2) == 0 ? pEdicts : nullptr;
  else
    v18 = nullptr;
  if ( (v18 != nullptr || pEdicts != nullptr && (v18 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0))
    && (v19 = v18->m_pUnk) != nullptr )
  {
    return v19->GetBaseEntity(this: v19);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B68B0
// Name: public: virtual void CBasePlayer::CommitSuicide(class Vector const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::CommitSuicide(CBasePlayer *this, const Vector *vecForce, bool bExplode, bool bForce)
{
  IMDLCache *v4; // edi
  float curtime; // xmm0_4
  int m_Value; // ebx
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CBaseEntity *); // eax
  unsigned int m_Index; // ecx
  float z; // xmm0_4
  CBasePlayer_vtbl *v11; // eax
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // edx
  CTakeDamageInfo info; // [esp+8h] [ebp-5Ch] BYREF

  v4 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( this->IsAlive(this) && ((curtime = gpGlobals->curtime, this->m_fNextSuicideTime <= curtime) || bForce) )
  {
    m_Value = this->m_iHealth.m_Value;
    this->m_fNextSuicideTime = curtime + 5.0;
    CTakeDamageInfo::CTakeDamageInfo(this: &info);
    GetRefEHandle = this->GetRefEHandle;
    info.m_flDamage = (float)(m_Value + 10);
    m_Index = GetRefEHandle(this)->m_Index;
    info.m_vecDamageForce.x = vecForce->x;
    info.m_vecDamageForce.y = vecForce->y;
    z = vecForce->z;
    v11 = this->__vftable;
    info.m_hAttacker.m_Index = m_Index;
    info.m_bitsDamageType = bExplode ? 0x2040 : 0;
    WorldSpaceCenter = v11->WorldSpaceCenter;
    info.m_vecDamageForce.z = z;
    info.m_vecDamagePosition = *WorldSpaceCenter(this);
    CBaseEntity::TakeDamage(this, a2: (int)this, inputInfo: &info);
    v4->EndLock(this: v4);
  }
  else
  {
    v4->EndLock(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B69D0
// Name: public: bool CBasePlayer::HasWeapons(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePlayer::HasWeapons(CBasePlayer *this)
{
  int v2; // esi

  v2 = 0;
  while ( CBaseCombatCharacter::GetWeapon(this, i: v2) == nullptr )
  {
    if ( ++v2 >= 64 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B6A00
// Name: public: virtual void CSprayCan::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprayCan::Think(CSprayCan *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  const IHandleEntity *m_pEntity; // ebx
  IHandleEntity_vtbl *v5; // eax
  unsigned int v6; // edx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  int m_iEFlags; // eax
  float v11; // xmm3_4
  float v12; // xmm0_4
  CGameTrace tr; // [esp+4h] [ebp-70h] BYREF
  Vector forward; // [esp+58h] [ebp-1Ch] BYREF
  Vector vecAbsEnd; // [esp+64h] [ebp-10h] BYREF
  int playernum; // [esp+70h] [ebp-4h]
  IHandleEntity savedregs; // [esp+74h] [ebp+0h] BYREF

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = v3->m_pEntity;
      if ( v3->m_pEntity != nullptr
        && ((unsigned __int8 (__thiscall *)(const IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: m_pEntity) != 0 )
      {
        v5 = m_pEntity[6].__vftable;
        if ( v5 != nullptr )
          playernum = ((char *)v5 - (char *)gpGlobals->pEdicts) >> 4;
        else
          playernum = 0;
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        AngleVectors(angles: &this->m_angAbsRotation, &forward);
        v6 = (unsigned int)this->m_iEFlags >> 11;
        x = forward.x * 128.0;
        y = forward.y * 128.0;
        z = forward.z * 128.0;
        vecAbsEnd.x = forward.x * 128.0;
        vecAbsEnd.y = forward.y * 128.0;
        vecAbsEnd.z = forward.z * 128.0;
        if ( (v6 & 1) != 0 )
        {
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
          y = vecAbsEnd.y;
          x = vecAbsEnd.x;
          z = vecAbsEnd.z;
        }
        m_iEFlags = this->m_iEFlags;
        v11 = this->m_vecAbsOrigin.x + x;
        vecAbsEnd.y = this->m_vecAbsOrigin.y + y;
        v12 = this->m_vecAbsOrigin.z + z;
        vecAbsEnd.x = v11;
        vecAbsEnd.z = v12;
        if ( (m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)&this->m_vecAbsOrigin,
          vecAbsStart: &this->m_vecAbsOrigin,
          &vecAbsEnd,
          mask: 0x400Bu,
          ignore: m_pEntity,
          collisionGroup: 0,
          ptr: &tr);
        UTIL_PlayerDecalTrace(pTrace: &tr, playernum);
      }
    }
  }
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x101B6B70
// Name: public: void CBloodSplat::Spawn(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBloodSplat::Spawn(CBloodSplat *this, CBaseEntity *pOwner)
{
  const Vector *v3; // eax
  Vector origin; // [esp+14h] [ebp-Ch] BYREF

  v3 = pOwner->WorldSpaceCenter(this: pOwner);
  origin.x = v3->x;
  origin.y = v3->y;
  origin.z = v3->z + 32.0;
  CBaseEntity::SetLocalOrigin(this, &origin);
  CBaseEntity::SetLocalAngles(this, angles: &pOwner->m_angRotation.m_Value);
  this->SetOwnerEntity(this, a2: pOwner);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101B6C00
// Name: public: virtual void CBloodSplat::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBloodSplat::Think(CBloodSplat *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  IHandleEntity *m_pEntity; // esi
  const IHandleEntity *v5; // ebx
  unsigned int v6; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  int m_iEFlags; // ecx
  float v11; // xmm3_4
  float v12; // xmm0_4
  CGameTrace tr; // [esp+4h] [ebp-6Ch] BYREF
  Vector forward; // [esp+58h] [ebp-18h] BYREF
  Vector vecAbsEnd; // [esp+64h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+70h] [ebp+0h] BYREF

  if ( g_Language.m_pParent == nullptr || g_Language.m_pParent->m_Value.m_nValue != 1 )
  {
    m_Index = this->m_hOwnerEntity.m_Value.m_Index;
    if ( m_Index != -1
      && (v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && (m_pEntity = v3->m_pEntity, v3->m_pEntity != nullptr)
      && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: m_pEntity) != 0 )
    {
      v5 = m_pEntity;
    }
    else
    {
      v5 = nullptr;
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    AngleVectors(angles: &this->m_angAbsRotation, &forward);
    v6 = (unsigned int)this->m_iEFlags >> 11;
    x = forward.x * 128.0;
    y = forward.y * 128.0;
    z = forward.z * 128.0;
    vecAbsEnd.x = forward.x * 128.0;
    vecAbsEnd.y = forward.y * 128.0;
    vecAbsEnd.z = forward.z * 128.0;
    if ( (v6 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      y = vecAbsEnd.y;
      x = vecAbsEnd.x;
      z = vecAbsEnd.z;
    }
    m_iEFlags = this->m_iEFlags;
    v11 = this->m_vecAbsOrigin.x + x;
    vecAbsEnd.y = this->m_vecAbsOrigin.y + y;
    v12 = this->m_vecAbsOrigin.z + z;
    vecAbsEnd.x = v11;
    vecAbsEnd.z = v12;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)&this->m_vecAbsOrigin,
      vecAbsStart: &this->m_vecAbsOrigin,
      &vecAbsEnd,
      mask: 0x400Bu,
      ignore: v5,
      collisionGroup: 0,
      ptr: &tr);
    UTIL_BloodDecalTrace(pTrace: &tr, bloodColor: 0);
  }
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x101B6D60
// Name: public: virtual class CBaseEntity __near * CBasePlayer::FindEntityClassForward(char __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::FindEntityClassForward(CBasePlayer *this, char *classname)
{
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v4; // eax
  Vector *(__thiscall *v5)(CBaseEntity *, Vector *); // edx
  const Vector *v6; // eax
  CBaseEntity *m_pEnt; // esi
  CGameTrace tr; // [esp+4h] [ebp-90h] BYREF
  Vector vecAbsEnd; // [esp+58h] [ebp-3Ch] BYREF
  Vector v11; // [esp+64h] [ebp-30h] BYREF
  Vector forward; // [esp+70h] [ebp-24h] BYREF
  unsigned int mask[3]; // [esp+7Ch] [ebp-18h] BYREF
  float v14; // [esp+88h] [ebp-Ch]
  float v15; // [esp+8Ch] [ebp-8h]
  float v16; // [esp+90h] [ebp-4h]
  IHandleEntity savedregs; // [esp+94h] [ebp+0h] BYREF

  CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: nullptr);
  EyePosition = this->EyePosition;
  v14 = forward.x * 16384.0;
  v15 = forward.y * 16384.0;
  v16 = forward.z * 16384.0;
  v4 = (float *)EyePosition(this, result: &v11);
  v5 = this->EyePosition;
  *(float *)mask = *v4 + v14;
  *(float *)&mask[1] = v4[1] + v15;
  *(float *)&mask[2] = v4[2] + v16;
  v6 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v5)(a1: this);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: v6,
    &vecAbsEnd,
    (unsigned int)mask,
    ignore: (const IHandleEntity *)0x200400B,
    collisionGroup: (int)this,
    ptr: nullptr);
  if ( tr.fraction != 1.0
    && CGameTrace::DidHitNonWorldEntity(this: &tr)
    && (m_pEnt = tr.m_pEnt, tr.m_pEnt != nullptr)
    && (tr.m_pEnt->m_iClassname.pszValue == classname
     || CBaseEntity::ClassMatchesComplex(this: tr.m_pEnt, pszClassOrWildcard: classname) != 0) )
  {
    return m_pEnt;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6E70
// Name: public: virtual class CBaseEntity __near * CBasePlayer::FindEntityForward(bool)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::FindEntityForward(CBasePlayer *this, bool fHull)
{
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v4; // eax
  Vector *(__thiscall *v5)(CBaseEntity *, Vector *); // edx
  const Vector *v6; // eax
  const IHandleEntity *v8; // [esp-Ch] [ebp-A4h]
  CGameTrace tr; // [esp+8h] [ebp-90h] BYREF
  Vector vecAbsEnd; // [esp+5Ch] [ebp-3Ch] BYREF
  Vector v11; // [esp+68h] [ebp-30h] BYREF
  Vector forward; // [esp+74h] [ebp-24h] BYREF
  unsigned int mask[3]; // [esp+80h] [ebp-18h] BYREF
  float v14; // [esp+8Ch] [ebp-Ch]
  float v15; // [esp+90h] [ebp-8h]
  float v16; // [esp+94h] [ebp-4h]
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: nullptr);
  EyePosition = this->EyePosition;
  v14 = forward.x * 16384.0;
  v15 = forward.y * 16384.0;
  v16 = forward.z * 16384.0;
  v4 = (float *)EyePosition(this, result: &v11);
  v5 = this->EyePosition;
  *(float *)mask = *v4 + v14;
  *(float *)&mask[1] = v4[1] + v15;
  v8 = (const IHandleEntity *)(fHull ? 33570827 : 1174421507);
  *(float *)&mask[2] = v4[2] + v16;
  v6 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v5)(a1: this);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)v8,
    vecAbsStart: v6,
    &vecAbsEnd,
    (unsigned int)mask,
    ignore: v8,
    collisionGroup: (int)this,
    ptr: nullptr);
  if ( tr.fraction == 1.0 || !CGameTrace::DidHitNonWorldEntity(this: &tr) )
    return nullptr;
  else
    return tr.m_pEnt;
}

//------------------------------------------------------------------------------
// Address: 0x101B6F70
// Name: public: virtual bool CBasePlayer::BumpWeapon(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::BumpWeapon(CBasePlayer *this, CBaseCombatWeapon *pWeapon)
{
  CBaseCombatCharacter *Owner; // eax
  bool result; // al
  CBasePlayer_vtbl *v6; // ebx
  int v7; // eax
  const char *pWeapona; // [esp+10h] [ebp+8h]

  Owner = CBaseCombatWeapon::GetOwner(this: pWeapon);
  if ( this->m_bPreventWeaponPickup )
    return false;
  if ( Owner != nullptr
    || !this->Weapon_CanUse(this, a2: pWeapon)
    || !g_pGameRules->CanHavePlayerItem(this: g_pGameRules, a2: this, a3: pWeapon) )
  {
    if ( gEvilImpulse101 != 0 )
      UTIL_Remove(oldObj: pWeapon);
    return false;
  }
  if ( hl2_episodic.m_pParent == nullptr || hl2_episodic.m_pParent->m_Value.m_nValue == 0 )
  {
    if ( pWeapon->FVisible_2(this: pWeapon, a2: this, a3: 33570827, a4: nullptr)
      || (this->m_fFlags.m_Value & 0x10000) != 0 )
    {
      goto LABEL_12;
    }
    return false;
  }
  result = UTIL_ItemCanBeTouchedByPlayer(pItem: pWeapon, pPlayer: this);
  if ( !result && gEvilImpulse101 == 0 )
    return result;
LABEL_12:
  pWeapona = pWeapon->m_iClassname.pszValue;
  if ( pWeapona == nullptr )
    pWeapona = locale;
  v6 = this->__vftable;
  v7 = pWeapon->GetSubType(this: pWeapon);
  if ( v6->Weapon_OwnsThisType(this, a2: pWeapona, a3: v7) != nullptr )
  {
    if ( this->Weapon_EquipAmmoOnly(this, a2: pWeapon) && !pWeapon->HasPrimaryAmmo(this: pWeapon) )
    {
      UTIL_Remove(oldObj: pWeapon);
      return true;
    }
    return false;
  }
  pWeapon->CheckRespawn(this: pWeapon);
  CBaseEntity::AddSolidFlags(this: pWeapon, flags: 4);
  CBaseEntity::AddEffects(this: pWeapon, nEffects: 32);
  this->Weapon_Equip(this, a2: pWeapon);
  if ( this->IsInAVehicle(this) )
    pWeapon->Holster(this: pWeapon, a2: nullptr);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101B70F0
// Name: public: bool CBasePlayer::ScriptIsPlayerNoclipping(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBasePlayer::ScriptIsPlayerNoclipping(CBasePlayer *this)
{
  return this->m_MoveType.m_Value == 8;
}

//------------------------------------------------------------------------------
// Address: 0x101B7100
// Name: public: virtual void CBasePlayer::UpdateBattery(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdateBattery(CBasePlayer *this)
{
  int m_Value; // eax
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  m_Value = this->m_ArmorValue.m_Value;
  if ( m_Value != this->m_iClientBattery )
  {
    this->m_iClientBattery = m_Value;
    if ( CUserMessages::LookupUserMessage(this: usermessages, name: "Battery") != -1 )
    {
      CRecipientFilter::CRecipientFilter(this: &user);
      user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
      CRecipientFilter::AddRecipient(this: &user, player: this);
      CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
      UserMessageBegin(filter: &user, messagename: "Battery");
      MessageWriteShort(iValue: this->m_ArmorValue.m_Value);
      MessageEnd();
      CRecipientFilter::~CRecipientFilter(this: &user);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7190
// Name: public: virtual void CBasePlayer::RumbleEffect(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::RumbleEffect(
        CBasePlayer *this,
        unsigned __int8 index,
        unsigned __int8 rumbleData,
        unsigned __int8 rumbleFlags)
{
  CSingleUserRecipientFilter filter; // [esp+4h] [ebp-20h] BYREF

  if ( this->IsAlive(this) )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &filter, player: this);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
    UserMessageBegin(&filter, messagename: "Rumble");
    MessageWriteByte(iValue: index);
    MessageWriteByte(iValue: rumbleData);
    MessageWriteByte(iValue: rumbleFlags);
    MessageEnd();
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7210
// Name: public: virtual void CBasePlayer::CheckTrainUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::CheckTrainUpdate(CBasePlayer *this)
{
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  if ( (this->m_iTrain & 0xC0) != 0 )
  {
    CRecipientFilter::CRecipientFilter(this: &user);
    user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &user, player: this);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
    UserMessageBegin(filter: &user, messagename: "Train");
    MessageWriteByte(iValue: this->m_iTrain & 0xF);
    MessageEnd();
    this->m_iTrain &= 0xFFFFFF3F;
    CRecipientFilter::~CRecipientFilter(this: &user);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7280
// Name: private: float CBasePlayer::GetAutoaimScore(class Vector const __near &,class Vector const __near &,class Vector const __near &,class CBaseEntity __near *,float,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayer::GetAutoaimScore(
        CBasePlayer *this,
        const Vector *eyePosition,
        const Vector *viewDir,
        const Vector *vecTarget,
        CBaseEntity *pTarget,
        float fScale,
        CBaseCombatWeapon *pActiveWeapon)
{
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  Vector vecNearestPoint; // [esp+0h] [ebp-18h] BYREF
  Vector vEndPos; // [esp+Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  float score; // [esp+2Ch] [ebp+14h]
  float scorea; // [esp+2Ch] [ebp+14h]

  score = pTarget->GetAutoAimRadius(this: pTarget);
  if ( fScale == 1.0 )
  {
    if ( pActiveWeapon != nullptr )
      score = ((double (__thiscall *)(CBaseCombatWeapon *))pActiveWeapon->WeaponAutoAimScale)(a1: pActiveWeapon) * score;
    v7 = score;
  }
  else
  {
    v7 = score * fScale;
  }
  scorea = v7 * v7;
  v8 = viewDir->z * 8192.0;
  v9 = eyePosition->x + (float)(viewDir->x * 8192.0);
  vEndPos.y = eyePosition->y + (float)(viewDir->y * 8192.0);
  v10 = eyePosition->z + v8;
  vEndPos.x = v9;
  vEndPos.z = v10;
  PointOnLineNearestPoint(
    a1: COERCE_FLOAT(&savedregs),
    result: &vecNearestPoint,
    vStartPos: eyePosition,
    &vEndPos,
    vPoint: vecTarget);
  v11 = (float)((float)((float)(vecTarget->x - vecNearestPoint.x) * (float)(vecTarget->x - vecNearestPoint.x))
              + (float)((float)(vecTarget->y - vecNearestPoint.y) * (float)(vecTarget->y - vecNearestPoint.y)))
      + (float)((float)(vecTarget->z - vecNearestPoint.z) * (float)(vecTarget->z - vecNearestPoint.z));
  if ( scorea < v11 )
    return 0.0;
  else
    return (float)(1.0 - (float)(v11 / scorea));
}

//------------------------------------------------------------------------------
// Address: 0x101B73B0
// Name: public: virtual class CBaseEntity __near * CBasePlayer::GetUseEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::GetUseEntity(CBasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hUseEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101B73E0
// Name: public: void CStripWeapons::InputStripWeapons(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStripWeapons::InputStripWeapons(CStripWeapons *this, inputdata_t *data)
{
  CBasePlayer *pActivator; // eax

  if ( data->pActivator != nullptr && data->pActivator->IsPlayer(this: data->pActivator) )
  {
    pActivator = (CBasePlayer *)data->pActivator;
  }
  else
  {
    if ( g_pGameRules->IsDeathmatch(this: g_pGameRules) )
      return;
    pActivator = UTIL_GetLocalPlayer();
  }
  if ( pActivator != nullptr )
    pActivator->RemoveAllItems(this: pActivator, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x101B7430
// Name: public: void CStripWeapons::InputStripWeaponsAndSuit(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStripWeapons::InputStripWeaponsAndSuit(CStripWeapons *this, inputdata_t *data)
{
  CBasePlayer *pActivator; // eax

  if ( data->pActivator != nullptr && data->pActivator->IsPlayer(this: data->pActivator) )
  {
    pActivator = (CBasePlayer *)data->pActivator;
  }
  else
  {
    if ( g_pGameRules->IsDeathmatch(this: g_pGameRules) )
      return;
    pActivator = UTIL_GetLocalPlayer();
  }
  if ( pActivator != nullptr )
    pActivator->RemoveAllItems(this: pActivator, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x101B7480
// Name: private: int CMovementSpeedMod::GetDisabledButtonMask(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMovementSpeedMod::GetDisabledButtonMask(CMovementSpeedMod *this)
{
  int m_Value; // ecx
  int result; // eax

  m_Value = this->m_spawnflags.m_Value;
  result = 0;
  if ( (m_Value & 4) != 0 )
    result = 2;
  if ( (m_Value & 8) != 0 )
    result |= 4u;
  if ( (m_Value & 0x10) != 0 )
    result |= 0x20u;
  if ( (m_Value & 0x20) != 0 )
    result |= 0x20000u;
  if ( (m_Value & 0x40) != 0 )
    result |= 0x801u;
  if ( (m_Value & 0x80) != 0 )
    return result | 0x80000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B7F40
// Name: public: void CBasePlayer::SetupVPhysicsShadow(class Vector const __near &,class Vector const __near &,class CPhysCollide __near *,char const __near *,class CPhysCollide __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetupVPhysicsShadow(
        CBasePlayer *this,
        const Vector *vecAbsOrigin,
        const Vector *vecAbsVelocity,
        struct CPhysCollide *pStandModel,
        const char *pStandHullName,
        struct CPhysCollide *pCrouchModel,
        const char *pCrouchHullName)
{
  IPhysicsObject *v8; // eax
  IPhysicsObject *v9; // eax
  IPhysicsPlayerController *v10; // eax
  solid_t solid; // [esp+20h] [ebp-640h] BYREF

  V_strncpy(pDest: solid.surfaceprop, pSrc: "player", maxLen: 512);
  solid.params.massCenterOverride = g_PhysDefaultObjectParams.massCenterOverride;
  solid.params.damping = g_PhysDefaultObjectParams.damping;
  *(_QWORD *)&solid.params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)&solid.params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  memset(&solid.params.volume, 0, 12);
  solid.params.mass = 85.0;
  solid.params.inertia = 1.0e24;
  v8 = PhysModelCreateCustom(
         pEntity: this,
         pModel: pStandModel,
         origin: &this->m_vecOrigin.m_Value,
         angles: &this->m_angRotation.m_Value,
         pName: pStandHullName,
         isStatic: false,
         pSolid: &solid);
  this->m_pShadowStand = v8;
  v8->SetCallbackFlags(this: v8, a2: 17u);
  v9 = PhysModelCreateCustom(
         pEntity: this,
         pModel: pCrouchModel,
         origin: &this->m_vecOrigin.m_Value,
         angles: &this->m_angRotation.m_Value,
         pName: pCrouchHullName,
         isStatic: false,
         pSolid: &solid);
  this->m_pShadowCrouch = v9;
  v9->SetCallbackFlags(this: v9, a2: 17u);
  CBaseEntity::VPhysicsSetObject(this, pPhysics: this->m_pShadowStand);
  PhysAddShadow(pEntity: this);
  v10 = physenv->CreatePlayerController(this: physenv, a2: this->m_pShadowStand);
  this->m_pPhysicsController = v10;
  ((void (__thiscall *)(IPhysicsPlayerController *, int))v10->SetPushMassLimit)(a1: v10, a2: 1135542272);
  ((void (__stdcall *)(int))this->m_pPhysicsController->SetPushSpeedLimit)(a1: 1112014848);
  CBasePlayer::UpdatePhysicsShadowToPosition(this, vecAbsOrigin);
  if ( (this->m_fFlags.m_Value & 2) != 0 )
    CBasePlayer::SetVCollisionState(this, vecAbsOrigin, vecAbsVelocity, collisionState: 1);
  else
    CBasePlayer::SetVCollisionState(this, vecAbsOrigin, vecAbsVelocity, collisionState: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B80E0
// Name: public: virtual void CBasePlayer::InitVCollision(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::InitVCollision(
        CBasePlayer *this,
        const Vector *vecAbsOrigin,
        const Vector *vecAbsVelocity)
{
  const CViewVectors *v4; // eax
  struct CPhysCollide *Bbox; // edi
  const CViewVectors *v6; // eax
  struct CPhysCollide *v7; // eax
  Vector *p_m_vHullMax; // [esp-8h] [ebp-Ch]
  Vector *p_m_vDuckHullMax; // [esp-8h] [ebp-Ch]

  this->VPhysicsDestroyObject(this);
  if ( sv_turbophysics.m_pParent == nullptr || sv_turbophysics.m_pParent->m_Value.m_nValue == 0 )
  {
    p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
    v4 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    Bbox = PhysCreateBbox(minsIn: &v4->m_vHullMin, maxsIn: p_m_vHullMax);
    p_m_vDuckHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vDuckHullMax;
    v6 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v7 = PhysCreateBbox(minsIn: &v6->m_vDuckHullMin, maxsIn: p_m_vDuckHullMax);
    CBasePlayer::SetupVPhysicsShadow(
      this,
      vecAbsOrigin,
      vecAbsVelocity,
      pStandModel: Bbox,
      pStandHullName: "player_stand",
      pCrouchModel: v7,
      pCrouchHullName: "player_crouch");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8180
// Name: public: int CBasePlayer::GetFOVForNetworking(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::GetFOVForNetworking(CBasePlayer *this)
{
  IServerVehicle *v2; // eax
  CBasePlayer *v3; // ecx
  float m_flVehicleViewFOV; // xmm0_4
  int DefaultFOV; // eax
  int m_Value; // ecx
  float v7; // xmm0_4
  int v8; // esi

  v2 = this->GetVehicle(this);
  v3 = this;
  if ( v2 == nullptr )
    goto LABEL_4;
  CBasePlayer::CacheVehicleView(this);
  m_flVehicleViewFOV = this->m_flVehicleViewFOV;
  if ( m_flVehicleViewFOV == 0.0 )
  {
    v3 = this;
LABEL_4:
    DefaultFOV = CBasePlayer::GetDefaultFOV(this: v3);
    goto LABEL_5;
  }
  DefaultFOV = (int)m_flVehicleViewFOV;
LABEL_5:
  m_Value = this->m_iFOV.m_Value;
  if ( m_Value == 0 )
    m_Value = DefaultFOV;
  v7 = this->m_Local.m_flFOVRate.m_Value;
  if ( v7 != 0.0 && v7 > (float)(gpGlobals->curtime - this->m_flFOVTime.m_Value) )
  {
    v8 = this->m_iFOVStart.m_Value;
    if ( m_Value >= v8 )
      return v8;
  }
  return m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101B8210
// Name: public: float CBasePlayer::GetFOVDistanceAdjustFactorForNetworking(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayer::GetFOVDistanceAdjustFactorForNetworking(CBasePlayer *this)
{
  float FOVForNetworking; // xmm1_4
  float defaultFOV; // [esp+8h] [ebp-4h]

  defaultFOV = (float)CBasePlayer::GetDefaultFOV(this);
  FOVForNetworking = (float)CBasePlayer::GetFOVForNetworking(this);
  if ( FOVForNetworking == defaultFOV || defaultFOV < 0.001 )
    return 1.0;
  else
    return FOVForNetworking / defaultFOV;
}

//------------------------------------------------------------------------------
// Address: 0x101B8270
// Name: public: virtual void CBasePlayer::ModifyOrAppendPlayerCriteria(class ResponseRules::CriteriaSet __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBasePlayer::ModifyOrAppendPlayerCriteria(
        CBasePlayer *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        ResponseRules::CriteriaSet *set)
{
  const char *v6; // eax
  float v7; // xmm0_4
  const char *v8; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  const char *pszValue; // eax
  const char *ActivityName; // eax
  const char *v12; // eax
  float m_Value; // [esp+38h] [ebp-10h]
  _DWORD v15[2]; // [esp+3Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+48h] [ebp+0h]

  v15[0] = a2;
  v15[1] = retaddr;
  v6 = UTIL_VarArgs(format: "%i", this->m_iHealth.m_Value);
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "playerhealth", value: v6, weight: 1.0);
  if ( ((int (__thiscall *)(CBasePlayer *, int, int))this->GetMaxHealth)(a1: this, a2: a3, a3: a4) <= 0 )
  {
    v7 = 0.0;
  }
  else
  {
    m_Value = (float)this->m_iHealth.m_Value;
    v7 = m_Value / (float)this->GetMaxHealth(this);
  }
  v8 = UTIL_VarArgs(format: "%.3f", v7);
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "playerhealthfrac", value: v8, weight: 1.0);
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  if ( ActiveWeapon != nullptr )
  {
    pszValue = ActiveWeapon->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "playerweapon", value: pszValue, weight: 1.0);
  }
  else
  {
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "playerweapon", value: "none", weight: 1.0);
  }
  ActivityName = CAI_BaseNPC::GetActivityName(actID: this->m_Activity);
  ResponseRules::CriteriaSet::AppendCriteria(
    this: set,
    pCriteriaName: "playeractivity",
    value: ActivityName,
    weight: 1.0);
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v15);
  v12 = UTIL_VarArgs(
          format: "%.3f",
          fsqrt(
            (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                  + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
          + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z)));
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "playerspeed", value: v12, weight: 1.0);
  CBaseEntity::AppendContextToCriteria(this, set, prefix: "player");
}

//------------------------------------------------------------------------------
// Address: 0x101B8450
// Name: public: class QAngle const __near & CBasePlayer::GetPunchAngle(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *__thiscall CBasePlayer::GetPunchAngle(
        CBasePlayer *this)
{
  return &this->m_Local.m_vecPunchAngle;
}

//------------------------------------------------------------------------------
// Address: 0x101B8460
// Name: public: class CBaseEntity __near * CBasePlayer::DoubleCheckUseNPC(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__userpurge CBasePlayer::DoubleCheckUseNPC@<eax>(
        CBasePlayer *this@<ecx>,
        int a2@<esi>,
        CBaseEntity *pNPC,
        const Vector *vecSrc,
        const Vector *vecDir)
{
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  CBaseEntity *result; // eax
  CGameTrace tr; // [esp+0h] [ebp-60h] BYREF
  Vector vecAbsEnd; // [esp+54h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+60h] [ebp+0h] BYREF

  v5 = vecDir->z * 1024.0;
  v6 = vecSrc->x + (float)(vecDir->x * 1024.0);
  vecAbsEnd.y = vecSrc->y + (float)(vecDir->y * 1024.0);
  v7 = vecSrc->z + v5;
  vecAbsEnd.x = v6;
  vecAbsEnd.z = v7;
  UTIL_TraceLine(
    a1: &savedregs,
    a2,
    vecAbsStart: vecSrc,
    &vecAbsEnd,
    mask: 0x46004003u,
    ignore: this,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.m_pEnt == nullptr )
    return pNPC;
  if ( tr.m_pEnt->MyNPCPointer(this: tr.m_pEnt) == nullptr )
    return pNPC;
  result = tr.m_pEnt;
  if ( tr.m_pEnt == pNPC )
    return pNPC;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B8500
// Name: public: virtual bool CBasePlayer::IsBot(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBasePlayer::IsBot(CBasePlayer *this)
{
  return (this->m_fFlags.m_Value & 0x200) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B8510
// Name: public: void CBasePlayer::InputSetFogController(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::InputSetFogController(CBasePlayer *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // ecx
  CFogController *v4; // eax
  variant_t *p_value; // ecx
  const char *iVal; // eax
  CBaseEntity *EntityByName; // eax

  if ( inputdata->value.fieldType == FIELD_EHANDLE )
  {
    m_Index = inputdata->value.eVal.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      v4 = (CFogController *)__RTDynamicCast(
                               inptr: nullptr,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CFogController `RTTI Type Descriptor',
                               isReference: 0);
    else
      v4 = (CFogController *)__RTDynamicCast(
                               inptr: g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CFogController `RTTI Type Descriptor',
                               isReference: 0);
  }
  else
  {
    p_value = &inputdata->value;
    if ( inputdata->value.fieldType == FIELD_STRING )
    {
      iVal = (const char *)p_value->iVal;
      if ( p_value->iVal == 0 )
        iVal = locale;
    }
    else
    {
      iVal = variant_t::ToString(this: p_value);
    }
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: iVal,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    v4 = (CFogController *)__RTDynamicCast(
                             inptr: EntityByName,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CFogController `RTTI Type Descriptor',
                             isReference: 0);
  }
  if ( v4 != nullptr )
    this->SetFogController(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101B85D0
// Name: public: char const __near * CBasePlayer::GetNetworkIDString(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBasePlayer::GetNetworkIDString(CBasePlayer *this)
{
  const char *v2; // eax
  char *m_szNetworkIDString; // esi

  v2 = engine->GetPlayerNetworkIDString(this: engine, a2: this->m_Network.m_pPev);
  if ( v2 == nullptr )
    v2 = "UNKNOWN";
  m_szNetworkIDString = this->m_szNetworkIDString;
  V_strncpy(pDest: m_szNetworkIDString, pSrc: v2, maxLen: 64);
  return m_szNetworkIDString;
}

//------------------------------------------------------------------------------
// Address: 0x101B8610
// Name: public: virtual void CBasePlayer::HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::HandleAnimEvent(CBasePlayer *this, animevent_t *pEvent)
{
  int type; // edx
  int event_lowword; // edi

  type = pEvent->type;
  if ( (type & 0x400) != 0 )
    event_lowword = pEvent->_event_lowword;
  else
    event_lowword = *(_DWORD *)&pEvent->_event_highword;
  if ( (pEvent->type & 0x400) != 0 && (type & 1) != 0 && event_lowword == 36 )
  {
    this->CreateRagdollEntity(this);
    this->BecomeRagdollOnClient(this, a2: &vec3_origin);
    CBaseEntity::ThinkSet(this, func:  __thiscall CBasePlayer::`vcall'{1392,{flat}}, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
  else
  {
    CBaseAnimating::HandleAnimEvent(this, pEvent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B86B0
// Name: public: virtual int CPlayerInfo::GetUserID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlayerInfo::GetUserID(CPlayerInfo *this)
{
  return engine->GetPlayerUserId(this: engine, a2: (const edict_t *)this->GetDeathCount);
}

//------------------------------------------------------------------------------
// Address: 0x101B86D0
// Name: public: virtual char const __near * CPlayerInfo::GetNetworkIDString(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CPlayerInfo::GetNetworkIDString(CPlayerInfo *this)
{
  IPlayerInfo_vtbl *v1; // esi
  const char *v2; // eax
  char *v3; // esi

  v1 = this->IPlayerInfo::__vftable;
  v2 = engine->GetPlayerNetworkIDString(this: engine, a2: v1->GetDeathCount);
  if ( v2 == nullptr )
    v2 = "UNKNOWN";
  v3 = (char *)&v1[42].GetAbsAngles + 2;
  V_strncpy(pDest: v3, pSrc: v2, maxLen: 64);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101B8710
// Name: public: virtual int CPlayerInfo::GetFragCount(void)
// Source: json
//------------------------------------------------------------------------------
int (__thiscall *__thiscall CPlayerInfo::GetFragCount(CPlayerInfo *this))(IPlayerInfo *this)
{
  return this->IPlayerInfo::__vftable[38].GetArmorValue;
}

//------------------------------------------------------------------------------
// Address: 0x101B8720
// Name: public: virtual int CPlayerInfo::GetDeathCount(void)
// Source: json
//------------------------------------------------------------------------------
bool (__thiscall *__thiscall CPlayerInfo::GetDeathCount(CPlayerInfo *this))(IPlayerInfo *this)
{
  return this->IPlayerInfo::__vftable[38].IsHLTV;
}

//------------------------------------------------------------------------------
// Address: 0x101B8730
// Name: public: virtual bool CPlayerInfo::IsConnected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerInfo::IsConnected(CPlayerInfo *this)
{
  return this->IPlayerInfo::__vftable[38].GetNetworkIDString != (const char *(__thiscall *)(IPlayerInfo *))2;
}

//------------------------------------------------------------------------------
// Address: 0x101B8740
// Name: public: virtual bool CPlayerInfo::IsHLTV(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerInfo::IsHLTV(CPlayerInfo *this)
{
  return (bool)this->IPlayerInfo::__vftable[30].GetAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x101B8750
// Name: public: virtual bool CPlayerInfo::IsDead(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerInfo::IsDead(CPlayerInfo *this)
{
  return BYTE1(this->IPlayerInfo::__vftable[5].GetPlayerMaxs) == 2;
}

//------------------------------------------------------------------------------
// Address: 0x101B8760
// Name: public: virtual int const CPlayerInfo::GetHealth(void)
// Source: json
//------------------------------------------------------------------------------
bool (__thiscall *__thiscall CPlayerInfo::GetHealth(CPlayerInfo *this))(IPlayerInfo *this)
{
  return this->IPlayerInfo::__vftable[5].IsDead;
}

//------------------------------------------------------------------------------
// Address: 0x101B8770
// Name: public: virtual class Vector const CPlayerInfo::GetLocalOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CPlayerInfo::GetLocalOrigin(CPlayerInfo *this, const Vector *result)
{
  bool v3; // zf
  const Vector *v4; // eax
  CBasePlayer *m_pParent; // ecx
  __int64 v6; // xmm0_8
  float z; // ecx

  v3 = !this->m_pParent->IsBot(this: this->m_pParent);
  v4 = result;
  if ( v3 )
  {
    result->x = 0.0;
    result->y = 0.0;
    result->z = 0.0;
  }
  else
  {
    m_pParent = this->m_pParent;
    v6 = *(_QWORD *)&m_pParent->m_vecOrigin.m_Value.x;
    z = m_pParent->m_vecOrigin.m_Value.z;
    *(_QWORD *)&result->x = v6;
    result->z = z;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101B87C0
// Name: public: virtual class QAngle const CPlayerInfo::GetLocalAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CPlayerInfo::GetLocalAngles(CPlayerInfo *this, const QAngle *result)
{
  bool v3; // zf
  const QAngle *v4; // eax
  CBasePlayer *m_pParent; // ecx
  __int64 v6; // xmm0_8
  float z; // ecx

  v3 = !this->m_pParent->IsBot(this: this->m_pParent);
  v4 = result;
  if ( !v3 )
  {
    m_pParent = this->m_pParent;
    v6 = *(_QWORD *)&m_pParent->m_angRotation.m_Value.x;
    z = m_pParent->m_angRotation.m_Value.z;
    *(_QWORD *)&result->x = v6;
    result->z = z;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101B8800
// Name: public: virtual void CBasePlayer::NetworkVar_m_Local::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::NetworkVar_m_Local::NetworkStateChanged(CBasePlayer::NetworkVar_m_Local *this, void *pVar)
{
  char *v2; // eax
  CBaseEdict *v3; // ecx

  v2 = (char *)this - 2288;
  if ( *((_BYTE *)this - 2204) != 0 )
  {
    v2[88] |= 1u;
  }
  else
  {
    v3 = *((CBaseEdict **)v2 + 6);
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: v3, offset: (_WORD)pVar - (_WORD)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8830
// Name: public: void CBasePlayer::NetworkVar_m_hViewModel::Set(int,class CHandle<class CBaseViewModel> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::NetworkVar_m_hViewModel::Set(
        CBasePlayer::NetworkVar_m_hViewModel *this,
        int i,
        const CHandle<CBaseViewModel> *val)
{
  CBasePlayer::NetworkVar_m_hViewModel *v4; // eax
  CBaseEdict *m_Index; // ecx

  if ( this->m_Value[i].m_Index != val->m_Index )
  {
    v4 = this - 461;
    if ( *((_BYTE *)this - 3604) != 0 )
    {
      LOBYTE(v4[11].m_Value[0].m_Index) |= 1u;
      this->m_Value[i] = (CHandle<CBaseViewModel>)val->m_Index;
    }
    else
    {
      m_Index = (CBaseEdict *)v4[3].m_Value[0].m_Index;
      if ( m_Index != nullptr )
        CBaseEdict::StateChanged(this: m_Index, offset: (_WORD)this + 4 * i - (_WORD)v4);
      this->m_Value[i] = (CHandle<CBaseViewModel>)val->m_Index;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B89D0
// Name: public: class CFogController const __near * CNetworkHandleBase<class CFogController,class fogplayerparams_t::NetworkVar_m_hCtrl>::Set(class CFogController const __near *)
// Source: json
//------------------------------------------------------------------------------
const CFogController *__thiscall CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl>::Set(
        CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl> *this,
        const CFogController *val)
{
  unsigned int m_Index; // eax
  const CFogController *m_pEntity; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CFogController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    (**((void (__thiscall ***)(CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl> *, CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl> *))this
      - 1))(
      a1: this - 1,
      a2: this);
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
// Address: 0x101B8A40
// Name: public: class CBaseViewModel __near * CBasePlayer::GetViewModel(int)
// Source: json
//------------------------------------------------------------------------------
CBaseViewModel *__thiscall CBasePlayer::GetViewModel(CBasePlayer *this, int index)
{
  unsigned int m_Index; // eax

  m_Index = this->m_hViewModel.m_Value[index].m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseViewModel *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101B8A80
// Name: public: virtual void CBasePlayer::CreateViewModel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::CreateViewModel(CBasePlayer *this, unsigned int index)
{
  int v2; // ebx
  unsigned int m_Index; // eax
  CBaseViewModel *EntityByName; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v2 = index;
  m_Index = this->m_hViewModel.m_Value[index].m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    EntityByName = (CBaseViewModel *)CreateEntityByName(className: "viewmodel", iForceEdictIndex: -1, bNotify: true);
    if ( EntityByName != nullptr )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      CBaseEntity::SetAbsOrigin(this: EntityByName, absOrigin: &this->m_vecAbsOrigin);
      CBaseViewModel::SetOwner(this: EntityByName, pEntity: this);
      CBaseViewModel::SetIndex(this: EntityByName, nIndex: v2);
      DispatchSpawn(pEntity: EntityByName, bRunVScripts: true);
      CBaseEntity::FollowEntity(this: EntityByName, pBaseEntity: this, bBoneMerge: true);
      index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
      CBasePlayer::NetworkVar_m_hViewModel::Set(
        this: &this->m_hViewModel,
        i: v2,
        val: (const CHandle<CBaseViewModel> *)&index);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8B40
// Name: public: void CBasePlayer::DestroyViewModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::DestroyViewModels(CBasePlayer *this)
{
  CBasePlayer *v1; // esi
  int v2; // ebx
  CHandle<CBaseViewModel> *v3; // edi
  unsigned int m_Index; // eax
  CBaseEntity **v5; // ecx
  CBasePlayer::NetworkVar_m_hViewModel *p_m_hViewModel; // eax
  CBasePlayer::NetworkVar_m_hViewModel *v7; // esi
  CBasePlayer::NetworkVar_m_hViewModel *v8; // edx
  CBaseEdict *v9; // ecx
  int v10; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v1 = this;
  v2 = 1;
  i = 1;
  v3 = &this->m_hViewModel.m_Value[1];
  v10 = -3688 - (_DWORD)this;
  while ( 1 )
  {
    m_Index = v3->m_Index;
    if ( v3->m_Index != -1 )
    {
      v5 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) && *v5 != nullptr )
      {
        UTIL_Remove(oldObj: *v5);
        p_m_hViewModel = &v1->m_hViewModel;
        v7 = (CBasePlayer::NetworkVar_m_hViewModel *)((char *)&v1->m_hViewModel + (_DWORD)v3 + v10);
        if ( v7->m_Value[0].m_Index != -1 )
        {
          v8 = p_m_hViewModel - 461;
          if ( LOBYTE(p_m_hViewModel[-451].m_Value[1].m_Index) != 0 )
          {
            LOBYTE(v8[11].m_Value[0].m_Index) |= 1u;
          }
          else
          {
            v9 = (CBaseEdict *)v8[3].m_Value[0].m_Index;
            if ( v9 != nullptr )
            {
              CBaseEdict::StateChanged(this: v9, offset: 4 * v2 + 3688);
              v2 = i;
            }
          }
          v7->m_Value[0].m_Index = -1;
        }
      }
    }
    --v2;
    --v3;
    i = v2;
    if ( v2 < 0 )
      break;
    v1 = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8C30
// Name: public: virtual void CBasePlayer::NetworkVar_pl::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::NetworkVar_pl::NetworkStateChanged(CBasePlayer::NetworkVar_pl *this, void *pVar)
{
  char *v2; // eax
  CBaseEdict *v3; // ecx

  v2 = (char *)this - 2900;
  if ( *((_BYTE *)this - 2816) != 0 )
  {
    v2[88] |= 1u;
  }
  else
  {
    v3 = *((CBaseEdict **)v2 + 6);
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: v3, offset: (_WORD)pVar - (_WORD)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8C60
// Name: public: virtual void CBasePlayer::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdateOnRemove(CBasePlayer *this)
{
  CTeam *Team; // eax
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CBasePlayer **v9; // eax
  CBasePlayer *v10; // eax
  _DWORD v11[2]; // [esp+4h] [ebp-8h] BYREF

  if ( !g_pGameRules->IsMultiplayer(this: g_pGameRules) && g_pScriptVM != nullptr )
  {
    v11[1] = 0;
    v11[0] = 0;
    g_pScriptVM->SetValue(this: g_pScriptVM, a2: nullptr, a3: "player", a4: (const ScriptVariant_t *)v11);
  }
  this->VPhysicsDestroyObject(this);
  if ( CBaseEntity::GetTeam(this) != nullptr )
  {
    Team = CBaseEntity::GetTeam(this);
    Team->RemovePlayer(this: Team, a2: this);
  }
  m_Index = this->m_hSplitOwner.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = (CBasePlayer **)&g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        v10 = *v9;
      else
        v10 = nullptr;
      CBasePlayer::RemoveSplitScreenPlayer(this: v10, pOther: this);
    }
  }
  CBaseCombatCharacter::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B8D30
// Name: public: virtual void CBasePlayer::SetupVisibility(class CBaseEntity __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetupVisibility(
        CBasePlayer *this,
        CBaseEntity *pViewEntity,
        unsigned __int8 *pvs,
        int pvssize)
{
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *SplitScreenAndPictureInPicturePlayers; // edi
  int i; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  _BYTE v9[12]; // [esp+8h] [ebp-18h] BYREF
  Vector org; // [esp+14h] [ebp-Ch] BYREF

  if ( pViewEntity == nullptr || VisForce.m_pParent != nullptr && VisForce.m_pParent->m_Value.m_nValue != 0 )
  {
    org = *this->EyePosition(this, result: v9);
    engine->AddOriginToPVS(this: engine, a2: &org);
  }
  SplitScreenAndPictureInPicturePlayers = CBasePlayer::GetSplitScreenAndPictureInPicturePlayers(this);
  for ( i = 0; i < SplitScreenAndPictureInPicturePlayers->m_Size; ++i )
  {
    m_Index = SplitScreenAndPictureInPicturePlayers->m_Memory.m_pMemory[i].m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
      {
        org = *(Vector *)((int (__thiscall *)(IHandleEntity *, _BYTE *))m_pEntity->__vftable[42].dtr_IHandleEntity)(
                           a1: m_pEntity,
                           a2: v9);
        engine->AddOriginToPVS(this: engine, a2: &org);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8E20
// Name: public: virtual bool CBasePlayer::WantsLagCompensationOnEntity(class CBaseEntity const __near *,class CUserCmd const __near *,class CBitVec<2048> const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CBasePlayer::WantsLagCompensationOnEntity@<al>(
        CBasePlayer *this@<ecx>,
        float a2@<ebp>,
        CBaseEntity *entity,
        const CUserCmd *pCmd,
        const CBitVec<2048> *pEntityTransmitBits)
{
  edict_t *m_pPev; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  Vector v10; // [esp-Ch] [ebp-2Ch] BYREF
  Vector vForward; // [esp+0h] [ebp-20h] BYREF
  Vector vDiff; // [esp+Ch] [ebp-14h] BYREF
  void *v13; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  vDiff.z = a2;
  v13 = retaddr;
  if ( friendlyfire.m_pParent == nullptr || friendlyfire.m_pParent->m_Value.m_nValue == 0 )
  {
    LODWORD(vDiff.y) = CBaseEntity::GetTeamNumber(this: entity);
    if ( LODWORD(vDiff.y) == CBaseEntity::GetTeamNumber(this) )
      return false;
  }
  if ( pEntityTransmitBits != nullptr )
  {
    m_pPev = entity->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pEntityTransmitBits->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
      return false;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vDiff.z);
  if ( (entity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&vDiff.z);
  v8 = entity->IsPlayer(this: entity)
     ? (entity->IsPlayer(this: entity) ? &entity[4].m_rgflCoordinateFrame : (matrix3x4_t *)3796)->m_flMatVal[0][0]
     : 300.0;
  v9 = entity->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
  if ( (float)((float)(v8 * 1.5) * sv_maxunlag.m_pParent->m_Value.m_fValue) > fsqrt(
                                                                                (float)((float)((float)(entity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y)
                                                                                              * (float)(entity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y))
                                                                                      + (float)(v9 * v9))
                                                                              + (float)((float)(entity->m_vecAbsOrigin.z
                                                                                              - this->m_vecAbsOrigin.z)
                                                                                      * (float)(entity->m_vecAbsOrigin.z
                                                                                              - this->m_vecAbsOrigin.z))) )
    return true;
  AngleVectors(angles: &pCmd->viewangles, forward: &v10);
  vForward.x = entity->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
  vForward.y = entity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
  vForward.z = entity->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
  VectorNormalize(vec: &vForward);
  return (float)((float)((float)(v10.y * vForward.y) + (float)(vForward.x * v10.x)) + (float)(v10.z * vForward.z)) >= 0.70710701;
}

//------------------------------------------------------------------------------
// Address: 0x101B9020
// Name: public: virtual void CBasePlayer::DeathSound(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::DeathSound(CBasePlayer *this, const CTakeDamageInfo *info)
{
  if ( (this->m_bitsDamageType & 0x20) != 0 )
    CBaseEntity::EmitSound(this, soundname: "Player.FallGib", soundtime: 0.0, duration: nullptr);
  else
    CBaseEntity::EmitSound(this, soundname: "Player.Death", soundtime: 0.0, duration: nullptr);
  if ( this->m_Local.m_bWearingSuit.m_Value )
    UTIL_EmitGroupnameSuit(entity: this->m_Network.m_pPev, groupname: "HEV_DEAD");
}

//------------------------------------------------------------------------------
// Address: 0x101B9070
// Name: public: virtual void CBasePlayer::SetFogController(class CFogController __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetFogController(CBasePlayer *this, CFogController *pFogController)
{
  CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl>::Set(
    this: &this->m_PlayerFog.m_hCtrl,
    val: pFogController);
}

//------------------------------------------------------------------------------
// Address: 0x101B9080
// Name: public: virtual int CBasePlayer::OnTakeDamage_Alive(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBasePlayer::OnTakeDamage_Alive@<eax>(
        CBasePlayer *this@<ecx>,
        int a2@<ebx>,
        const CTakeDamageInfo *info)
{
  int result; // eax
  unsigned int m_Index; // eax
  CBaseEntityList *v6; // esi
  CEntInfo *v7; // ecx
  IHandleEntity *v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  CEntInfo *v11; // edx
  unsigned int v12; // ecx
  int v13; // eax
  bool v14; // zf
  CEntInfo *v15; // eax
  IHandleEntity *m_pEntity; // ecx
  float *v17; // eax
  CBasePlayer_vtbl *v18; // edx
  float v19; // xmm0_4
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  float *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  unsigned int v24; // eax
  const Vector *v25; // eax
  float v26; // xmm0_4
  float v27; // xmm0_4
  IGameEvent *v28; // esi
  int v29; // eax
  CBasePlayer *v30; // eax
  Vector force; // [esp+54h] [ebp-18h] BYREF
  Vector vecDir; // [esp+60h] [ebp-Ch] BYREF
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF
  float infoa; // [esp+74h] [ebp+8h]

  this->m_bitsDamageType |= info->m_bitsDamageType;
  result = CBaseCombatCharacter::OnTakeDamage_Alive(this, info);
  if ( result != 0 )
  {
    m_Index = info->m_hAttacker.m_Index;
    if ( m_Index != -1
      && (v6 = g_pEntityList,
          v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && (v8 = v7->m_pEntity, v7->m_pEntity != nullptr) )
    {
      v9 = info->m_hInflictor.m_Index;
      vecDir = vec3_origin;
      if ( v9 != -1 )
      {
        v10 = (unsigned __int16)v9;
        v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v9];
        v12 = HIWORD(v9);
        if ( v11->m_SerialNumber == v12 && v11->m_pEntity != nullptr )
        {
          v13 = v10;
          v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v12;
          v15 = &g_pEntityList->m_EntPtrArray[v13];
          if ( v14 )
            m_pEntity = v15->m_pEntity;
          else
            m_pEntity = nullptr;
          v17 = (float *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].dtr_IHandleEntity)(a1: m_pEntity);
          v18 = this->__vftable;
          force.x = *v17;
          force.y = v17[1];
          v19 = v17[2] - 10.0;
          WorldSpaceCenter = v18->WorldSpaceCenter;
          force.z = v19;
          v21 = (float *)WorldSpaceCenter(this);
          v22 = force.y - v21[1];
          v23 = v19 - v21[2];
          vecDir.x = force.x - *v21;
          vecDir.y = v22;
          vecDir.z = v23;
          VectorNormalize(vec: &vecDir);
          v6 = g_pEntityList;
        }
      }
      v24 = info->m_hInflictor.m_Index;
      if ( v24 != -1
        && v6->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber == HIWORD(v24)
        && v6->m_EntPtrArray[(unsigned __int16)v24].m_pEntity != nullptr
        && this->m_MoveType.m_Value == 2
        && ((int)v8[65].__vftable & 8) == 0 )
      {
        infoa = CTakeDamageInfo::GetBaseDamage(this: info);
        v25 = CBaseEntity::WorldAlignSize(this);
        v26 = 73728.0 / (float)((float)(v25->y * v25->x) * v25->z) * infoa * 5.0;
        if ( v26 > 1000.0 )
          v26 = 1000.0;
        LODWORD(v27) = LODWORD(v26) ^ _mask__NegFloat_;
        force.x = v27 * vecDir.x;
        force.y = vecDir.y * v27;
        force.z = vecDir.z * v27;
        if ( (float)(vecDir.z * v27) > 250.0 )
          force.z = 250.0;
        CBaseEntity::ApplyAbsVelocityImpulse(this, vecImpulse: &force);
      }
      v28 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_hurt", a3: 0, a4: &g_PlayerHurtEvent);
      if ( v28 != nullptr )
      {
        v29 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                a1: engine,
                a2: this->m_Network.m_pPev,
                a3: a2);
        v28->SetInt(this: v28, a2: "userid", a3: v29);
        v28->SetInt(this: v28, a2: "health", a3: this->m_iHealth.m_Value < 0 ? 0 : this->m_iHealth.m_Value);
        v28->SetInt(this: v28, a2: "priority", a3: 5);
        if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v8->__vftable[28].dtr_IHandleEntity)(a1: v8) != 0 )
        {
          v30 = ToBasePlayer(pEntity: (CBaseEntity *)v8);
          engine->GetPlayerUserId(this: engine, a2: v30->m_Network.m_pPev);
        }
        ((void (__thiscall *)(IGameEvent *, const char *))v28->SetInt)(a1: v28, a2: "attacker");
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v28, a3: false);
      }
      if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v8->__vftable[24].SetRefEHandle)(a1: v8) != 0 )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        CSoundEnt::InsertSound(
          iType: 1,
          vecOrigin: &this->m_vecAbsOrigin,
          iVolume: 512,
          flDuration: 0.5,
          pOwner: this,
          soundChannelIndex: 0,
          pSoundTarget: nullptr);
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B93D0
// Name: public: virtual void CBasePlayer::Event_Dying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Event_Dying(CBasePlayer *this)
{
  CTakeDamageInfo info; // [esp+18h] [ebp-68h] BYREF
  QAngle angles; // [esp+74h] [ebp-Ch] BYREF

  CTakeDamageInfo::CTakeDamageInfo(this: &info);
  this->DeathSound(this, a2: &info);
  if ( this->IsInAVehicle(this) )
    this->LeaveVehicle(this, a2: &vec3_origin, a3: &vec3_angle);
  angles.y = this->m_angRotation.m_Value.y;
  angles.x = 0.0;
  angles.z = 0.0;
  CBaseEntity::SetLocalAngles(this, &angles);
  CBaseEntity::ThinkSet(this, func:  __thiscall CBasePlayer::`vcall'{1392,{flat}}, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101B9490
// Name: public: void CBasePlayer::WaterMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::WaterMove(CBasePlayer *this)
{
  unsigned int m_Index; // ecx
  int m_bitsDamageType; // eax
  float curtime; // xmm0_4
  CBasePlayer_vtbl *v5; // edi
  edict_t *v6; // eax
  edict_t *v7; // eax
  CBaseEntity *v8; // eax
  CTakeDamageInfo *v9; // eax
  bool (__thiscall *CanRecoverCurrentDrowningDamage)(CBasePlayer *); // eax
  int m_idrowndmg; // ecx
  CBaseEntity *ContainingEntity; // [esp-4h] [ebp-78h]
  float flDamage; // [esp+0h] [ebp-74h]
  CTakeDamageInfo v14; // [esp+18h] [ebp-5Ch] BYREF

  if ( this->m_MoveType.m_Value == 8 )
  {
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      this->m_AirFinished = gpGlobals->curtime + 12.0;
      return;
    }
  }
  if ( this->m_iHealth.m_Value >= 0 && this->IsAlive(this) )
  {
    if ( this->m_nWaterLevel.m_Value != 3 || this->CanBreatheUnderwater(this) )
    {
      if ( gpGlobals->curtime > this->m_AirFinished )
        CBaseEntity::EmitSound(this, soundname: "Player.DrownStart", soundtime: 0.0, duration: nullptr);
      m_idrowndmg = this->m_idrowndmg;
      this->m_AirFinished = gpGlobals->curtime + 12.0;
      this->m_nDrownDmgRate = 2;
      if ( m_idrowndmg > this->m_idrownrestored )
      {
        this->m_bitsDamageType = this->m_bitsDamageType & 0xFFF7BFFF | 0x80000;
        this->m_rgbTimeBasedDamage[4] = 0;
      }
    }
    else
    {
      this->m_bitsDamageType &= ~0x80000u;
      m_bitsDamageType = this->m_bitsDamageType;
      this->m_rgbTimeBasedDamage[4] = 0;
      curtime = gpGlobals->curtime;
      if ( curtime <= this->m_AirFinished || (this->m_fFlags.m_Value & 0x8000) != 0 )
      {
        this->m_bitsDamageType = m_bitsDamageType & 0xFFFFBFFF;
        CBasePlayer::UpdateUnderwaterState(this);
        return;
      }
      if ( curtime > this->m_PainFinished )
      {
        if ( ++this->m_nDrownDmgRate > 5 )
          this->m_nDrownDmgRate = 5;
        v5 = this->__vftable;
        flDamage = (float)this->m_nDrownDmgRate;
        v6 = INDEXENT(iEdictNum: 0);
        ContainingEntity = GetContainingEntity(pent: v6);
        v7 = INDEXENT(iEdictNum: 0);
        v8 = GetContainingEntity(pent: v7);
        v9 = CTakeDamageInfo::CTakeDamageInfo(
               this: &v14,
               pInflictor: v8,
               pAttacker: ContainingEntity,
               flDamage,
               bitsDamageType: 0x4000,
               iKillType: 0,
               iObjectsPenetrated: 0);
        v5->OnTakeDamage(this, a2: v9);
        CanRecoverCurrentDrowningDamage = this->CanRecoverCurrentDrowningDamage;
        this->m_PainFinished = gpGlobals->curtime + 1.0;
        if ( CanRecoverCurrentDrowningDamage(this) )
        {
          this->m_idrowndmg += this->m_nDrownDmgRate;
          CBasePlayer::UpdateUnderwaterState(this);
          return;
        }
      }
    }
  }
  CBasePlayer::UpdateUnderwaterState(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B96D0
// Name: public: bool CBasePlayer::IsOnLadder(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBasePlayer::IsOnLadder(CBasePlayer *this)
{
  return this->m_MoveType.m_Value == 9;
}

//------------------------------------------------------------------------------
// Address: 0x101B96E0
// Name: public: virtual void CBasePlayer::CheckObserverSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::CheckObserverSettings(CBasePlayer *this)
{
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax
  CBaseEntity *v4; // edi
  bool (__thiscall *SetObserverMode)(CBasePlayer *, int); // edx
  int m_Value; // eax
  unsigned int v7; // eax
  CEntInfo *v8; // ecx
  CHandle<CBaseEntity> *v9; // edi
  int v10; // ebx
  const Vector *v11; // ebx
  float *v12; // eax
  CBasePlayer_vtbl *v13; // ebx
  int v14; // eax
  unsigned int v15; // eax
  IHandleEntity *v16; // ecx
  unsigned int v17; // eax
  IHandleEntity *v18; // edx
  const CFogController *v19; // eax
  int m_iObserverLastMode; // [esp-4h] [ebp-10h]
  int v21; // [esp+8h] [ebp-4h]

  if ( this->m_bForcedObserverMode )
  {
    m_Index = this->m_hObserverTarget.m_Value.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v4 = m_pEntity;
    if ( !this->IsValidObserverTarget(this, a2: m_pEntity) )
      v4 = this->FindNextObserverTarget(this, a2: 0);
    if ( v4 != nullptr )
    {
      SetObserverMode = this->SetObserverMode;
      m_iObserverLastMode = this->m_iObserverLastMode;
      this->m_bForcedObserverMode = false;
      SetObserverMode(this, a2: m_iObserverLastMode);
      this->SetObserverTarget(this, a2: v4);
    }
  }
  else
  {
    if ( this->m_iObserverLastMode < 3 )
      this->m_iObserverLastMode = 6;
    m_Value = this->m_iObserverMode.m_Value;
    if ( m_Value == 4 || m_Value == 5 )
    {
      this->ValidateCurrentObserverTarget(this);
      v7 = this->m_hObserverTarget.m_Value.m_Index;
      if ( v7 != -1 )
      {
        v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v7];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7) )
        {
          v9 = (CHandle<CBaseEntity> *)v8->m_pEntity;
          if ( v8->m_pEntity != nullptr
            && (*(unsigned __int8 (__thiscall **)(IHandleEntity *))(v9->m_Index + 336))(a1: v8->m_pEntity) != 0 )
          {
            if ( this->m_iObserverMode.m_Value == 4 )
            {
              v21 = this->m_fFlags.m_Value;
              v10 = v9[50].m_Index & 3;
              if ( (v21 & 3) != v10 )
              {
                CBaseEntity::ClearFlags(this);
                CBaseEntity::AddFlag(this, flags: v10 | v21 & 0xFFFFFFFC);
              }
              v11 = this->GetViewOffset(this);
              v12 = (float *)(*(int (__thiscall **)(CHandle<CBaseEntity> *))(v9->m_Index + 532))(a1: v9);
              if ( v11->x != *v12 || v11->y != v12[1] || v11->z != v12[2] )
              {
                v13 = this->__vftable;
                v14 = (*(int (__thiscall **)(CHandle<CBaseEntity> *))(v9->m_Index + 532))(a1: v9);
                v13->SetViewOffset(this, a2: (const Vector *)v14);
              }
            }
            v15 = v9[699].m_Index;
            if ( v15 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
              v16 = nullptr;
            else
              v16 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
            v17 = this->m_PlayerFog.m_hCtrl.m_Value.m_Index;
            if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
              v18 = nullptr;
            else
              v18 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
            if ( v16 != v18 )
            {
              v19 = (const CFogController *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: v9 + 699);
              CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl>::Set(
                this: &this->m_PlayerFog.m_hCtrl,
                val: v19);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9910
// Name: public: virtual bool CBasePlayer::IsValidObserverTarget(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::IsValidObserverTarget(CBasePlayer *this, CBaseEntity *target)
{
  CBasePlayer *v4; // esi
  char m_Value; // al
  int m_nValue; // eax
  int v7; // eax
  int TeamNumber; // edi

  if ( target == nullptr || !target->IsPlayer(this: target) )
    return false;
  v4 = target->IsPlayer(this: target) ? (CBasePlayer *)target : nullptr;
  if ( v4 == this )
    return false;
  if ( (v4->m_fEffects.m_Value & 0x20) != 0 )
    return false;
  m_Value = v4->m_lifeState.m_Value;
  if ( m_Value == 3 )
    return false;
  if ( (m_Value == 2 || m_Value == 1) && gpGlobals->curtime > (float)(v4->m_flDeathTime.m_Value + 3.0) )
    return false;
  if ( CBaseEntity::GetTeamNumber(this) != 1 )
  {
    if ( mp_forcecamera.m_pParent != nullptr )
      m_nValue = mp_forcecamera.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v7 = m_nValue - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
        return false;
    }
    else
    {
      TeamNumber = CBaseEntity::GetTeamNumber(this: target);
      if ( CBaseEntity::GetTeamNumber(this) != TeamNumber )
        return false;
    }
  }
  return this->PassesObserverFilter(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101B99F0
// Name: private: int CBasePlayer::DetermineSimulationTicks(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::DetermineSimulationTicks(CBasePlayer *this)
{
  int m_Size; // edi
  int result; // eax
  int v3; // esi
  int v4; // ebx
  CCommandContext *v5; // edx
  CBasePlayer *v6; // [esp+8h] [ebp-4h]

  m_Size = this->m_CommandContext.m_Size;
  result = 0;
  v3 = 0;
  v6 = this;
  if ( m_Size > 0 )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = v3 < 0 || v3 >= m_Size ? nullptr : &this->m_CommandContext.m_Memory.m_pMemory[v4];
      ++v3;
      result += v5->numcmds + v5->dropped_packets;
      ++v4;
      if ( v3 >= m_Size )
        break;
      this = v6;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B9A40
// Name: public: virtual void CBasePlayer::PlayerRunCommand(class CUserCmd __near *,class IMoveHelper __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::PlayerRunCommand(CBasePlayer *this, CUserCmd *ucmd, IMoveHelper *moveHelper)
{
  CPlayerMove *v4; // eax

  this->m_bTouchedPhysObject = false;
  if ( this->pl.fixangle == 0 )
    this->pl.v_angle = ucmd->viewangles;
  if ( (this->m_fFlags.m_Value & 0x40) == 0
    && (developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0
     || gpGlobals->eLoadType != MapLoad_NewGame
     || gpGlobals->curtime >= 3.0) )
  {
    if ( this->m_bDuckEnabled )
    {
      if ( this->m_bDuckToggled )
      {
        if ( xc_crouch_debounce.m_pParent != nullptr && xc_crouch_debounce.m_pParent->m_Value.m_nValue != 0 )
        {
          this->m_bDuckToggled = false;
          CCollisionProperty::TestCollision(this: (ConVar *)&xc_crouch_debounce.IConVar, value: 0);
        }
        else
        {
          ucmd->buttons |= 4u;
        }
      }
    }
    else
    {
      ucmd->buttons &= ~4u;
      this->m_bDuckToggled = false;
    }
  }
  else
  {
    ucmd->forwardmove = 0.0;
    ucmd->sidemove = 0.0;
    ucmd->upmove = 0.0;
    ucmd->buttons = 0;
    ucmd->impulse = 0;
    ucmd->viewangles = this->pl.v_angle;
  }
  v4 = PlayerMove();
  v4->RunCommand(this: v4, a2: this, a3: ucmd, a4: moveHelper);
}

//------------------------------------------------------------------------------
// Address: 0x101B9B40
// Name: public: void CBasePlayer::CheckSuitUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::CheckSuitUpdate(CBasePlayer *this)
{
  int m_iSuitPlayNext; // esi
  float m_flSuitUpdate; // xmm0_4
  int v4; // ecx
  int v5; // eax
  const char *v6; // eax
  char sentence[512]; // [esp+8h] [ebp-200h] BYREF

  m_iSuitPlayNext = this->m_iSuitPlayNext;
  if ( this->m_Local.m_bWearingSuit.m_Value )
  {
    this->UpdateGeigerCounter(this);
    if ( !g_pGameRules->IsMultiplayer(this: g_pGameRules) )
    {
      m_flSuitUpdate = this->m_flSuitUpdate;
      if ( gpGlobals->curtime >= m_flSuitUpdate && m_flSuitUpdate > 0.0 )
      {
        v4 = 0;
        while ( 1 )
        {
          v5 = this->m_rgSuitPlayList[m_iSuitPlayNext];
          if ( v5 != 0 )
            break;
          if ( ++m_iSuitPlayNext == 4 )
            m_iSuitPlayNext = 0;
          if ( ++v4 >= 4 )
          {
            this->m_flSuitUpdate = 0.0;
            return;
          }
        }
        this->m_rgSuitPlayList[m_iSuitPlayNext] = 0;
        if ( v5 <= 0 )
        {
          UTIL_EmitGroupIDSuit(entity: this->m_Network.m_pPev, isentenceg: -v5);
        }
        else
        {
          v6 = engine->SentenceNameFromIndex(this: engine, a2: v5);
          V_snprintf(pDest: sentence, maxLen: 512, pFormat: "!%s", v6);
          UTIL_EmitSoundSuit(entity: this->m_Network.m_pPev, sample: sentence);
        }
        this->m_flSuitUpdate = gpGlobals->curtime + 3.5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9C50
// Name: public: void CBasePlayer::SetSuitUpdate(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetSuitUpdate(CBasePlayer *this, char *name, int fgroup, int iNoRepeatTime)
{
  int v5; // ebx
  int v6; // edi
  int v7; // eax
  int *m_rgiSuitNoRepeat; // edx
  float m_flSuitUpdate; // xmm0_4
  float curtime; // xmm1_4
  bool v11; // zf
  double v12; // xmm0_8

  v5 = -1;
  if ( this->m_Local.m_bWearingSuit.m_Value && !g_pGameRules->IsMultiplayer(this: g_pGameRules) )
  {
    if ( name == nullptr )
    {
      this->m_rgSuitPlayList[0] = 0;
      this->m_rgSuitPlayList[1] = 0;
      this->m_rgSuitPlayList[2] = 0;
      this->m_rgSuitPlayList[3] = 0;
      return;
    }
    if ( fgroup != 0 )
    {
      v6 = -SENTENCEG_GetIndex(szrootname: name);
    }
    else
    {
      v6 = SENTENCEG_Lookup(sample: name);
      if ( v6 < 0 )
        return;
    }
    v7 = 0;
    m_rgiSuitNoRepeat = this->m_rgiSuitNoRepeat;
    while ( v6 != *m_rgiSuitNoRepeat )
    {
      if ( *m_rgiSuitNoRepeat == 0 )
        v5 = v7;
      ++v7;
      ++m_rgiSuitNoRepeat;
      if ( v7 >= 32 )
        goto LABEL_17;
    }
    if ( gpGlobals->curtime <= this->m_rgflSuitNoRepeatTime[v7] )
      return;
    this->m_rgiSuitNoRepeat[v7] = 0;
    this->m_rgflSuitNoRepeatTime[v7] = 0.0;
    v5 = v7;
LABEL_17:
    if ( iNoRepeatTime != 0 )
    {
      if ( v5 < 0 )
        v5 = random->RandomInt(this: random, a2: 0, a3: 31);
      this->m_rgiSuitNoRepeat[v5] = v6;
      this->m_rgflSuitNoRepeatTime[v5] = (float)iNoRepeatTime + gpGlobals->curtime;
    }
    this->m_rgSuitPlayList[this->m_iSuitPlayNext++] = v6;
    if ( this->m_iSuitPlayNext == 4 )
      this->m_iSuitPlayNext = 0;
    m_flSuitUpdate = this->m_flSuitUpdate;
    curtime = gpGlobals->curtime;
    if ( curtime >= m_flSuitUpdate )
    {
      v11 = m_flSuitUpdate == 0.0;
      v12 = curtime;
      if ( v11 )
        this->m_flSuitUpdate = v12 + 0.1;
      else
        this->m_flSuitUpdate = v12 + 3.5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9DE0
// Name: public: virtual void CBasePlayer::UpdatePlayerSound(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayer::UpdatePlayerSound(CBasePlayer *this@<ecx>, int a2@<ebp>)
{
  int v3; // eax
  CSound *v4; // edi
  int m_Value; // eax
  int v6; // eax
  int m_iVolume; // edi
  CSound *v8; // [esp-4h] [ebp-10h]
  _DWORD v9[2]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v9[0] = a2;
  v9[1] = retaddr;
  v3 = CSoundEnt::ClientSoundIndex(pClient: this->m_Network.m_pPev);
  v4 = CSoundEnt::SoundPointerForIndex(iIndex: v3);
  v8 = v4;
  if ( v4 != nullptr )
  {
    m_Value = this->m_fFlags.m_Value;
    if ( (m_Value & 0x10000) != 0 )
    {
      v4->m_iVolume = 0;
    }
    else
    {
      if ( (m_Value & 1) != 0 )
      {
        if ( (this->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v9);
        v6 = (int)fsqrt(
                    (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                          + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
                  + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z));
        if ( v6 > 512 )
          v6 = 512;
      }
      else
      {
        v6 = 0;
      }
      if ( (this->m_nButtons & 2) != 0 )
        v6 += 100;
      this->m_iTargetVolume = v6;
      m_iVolume = v4->m_iVolume;
      if ( m_iVolume >= v6 )
      {
        if ( m_iVolume > v6 )
        {
          m_iVolume = (int)(float)((float)m_iVolume - (float)(gpGlobals->frametime * 250.0));
          if ( m_iVolume < v6 )
            m_iVolume = 0;
        }
      }
      else
      {
        m_iVolume = v6;
      }
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)v9);
      v8->m_vecOrigin.x = this->m_vecAbsOrigin.x;
      v8->m_vecOrigin.y = this->m_vecAbsOrigin.y;
      v8->m_vecOrigin.z = this->m_vecAbsOrigin.z;
      v8->m_iVolume = m_iVolume;
      v8->m_iType = 4;
    }
  }
  else
  {
    _Msg(a1: "Client lost reserved sound!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9F50
// Name: public: virtual void CBasePlayer::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Touch(CBasePlayer *this, CBaseEntity *pOther)
{
  IPhysicsObject *m_pPhysicsObject; // edi

  if ( pOther != CBaseEntity::GetGroundEntity(this)
    && pOther->m_MoveType.m_Value == 6
    && pOther->m_Collision.GetSolid(this: &pOther->m_Collision) == SOLID_VPHYSICS
    && (pOther->m_Collision.GetSolidFlags(this: &pOther->m_Collision) & 8) == 0 )
  {
    m_pPhysicsObject = pOther->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr && m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject) )
      this->m_bTouchedPhysObject = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9FC0
// Name: public: virtual class Vector CBasePlayer::GetAutoaimVector(float)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBasePlayer::GetAutoaimVector(CBasePlayer *this, Vector *result, float flScale)
{
  void (__thiscall *GetAutoaimVector)(CBasePlayer *, autoaim_params_t *); // edx
  autoaim_params_t params; // [esp+0h] [ebp-2Ch] BYREF

  GetAutoaimVector = this->GetAutoaimVector;
  params.m_fMaxDist = 0.0;
  params.m_fMaxDeflection = -1.0;
  params.m_hAutoAimEntity.m_Index = -1;
  params.m_bOnTargetQueryOnly = false;
  params.m_fScale = flScale;
  params.m_fMaxDist = autoaim_max_dist.m_pParent->m_Value.m_fValue;
  params.m_fMaxDeflection = -1.0;
  GetAutoaimVector(this, a2: &params);
  *result = params.m_vecAutoAimDir;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BA030
// Name: public: virtual class Vector CBasePlayer::GetAutoaimVector(float,float)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBasePlayer::GetAutoaimVector(CBasePlayer *this, Vector *result, float flScale, float flMaxDist)
{
  void (__thiscall *GetAutoaimVector)(CBasePlayer *, autoaim_params_t *); // eax
  autoaim_params_t params; // [esp+0h] [ebp-2Ch] BYREF

  GetAutoaimVector = this->GetAutoaimVector;
  params.m_fScale = flScale;
  params.m_fMaxDist = flMaxDist;
  params.m_hAutoAimEntity.m_Index = -1;
  params.m_bOnTargetQueryOnly = false;
  params.m_fMaxDeflection = -1.0;
  GetAutoaimVector(this, a2: &params);
  *result = params.m_vecAutoAimDir;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BA090
// Name: public: virtual class Vector CBasePlayer::GetAutoaimVector(float,float,float,enum AimResults __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBasePlayer::GetAutoaimVector(
        CBasePlayer *this,
        Vector *result,
        float flScale,
        float flMaxDist,
        float flMaxDeflection,
        AimResults *pAimResults)
{
  void (__thiscall *GetAutoaimVector)(CBasePlayer *, autoaim_params_t *); // eax
  bool v7; // zf
  autoaim_params_t params; // [esp+0h] [ebp-2Ch] BYREF

  GetAutoaimVector = this->GetAutoaimVector;
  params.m_fScale = flScale;
  params.m_fMaxDist = flMaxDist;
  params.m_hAutoAimEntity.m_Index = -1;
  params.m_bOnTargetQueryOnly = false;
  params.m_fMaxDeflection = flMaxDeflection;
  GetAutoaimVector(this, a2: &params);
  v7 = !params.m_bOnTargetNatural;
  *pAimResults = AIMRESULTS_NONE;
  if ( v7 )
  {
    if ( params.m_bAutoAimAssisting )
      *pAimResults = AIMRESULTS_ASSISTED;
  }
  else
  {
    *pAimResults = AIMRESULTS_ONTARGET;
  }
  *result = params.m_vecAutoAimDir;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BA110
// Name: public: virtual void CBasePlayer::Weapon_Drop(class CBaseCombatWeapon __near *,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Weapon_Drop(
        CBasePlayer *this,
        CBaseCombatWeapon *pWeapon,
        const Vector *pvecTarget,
        const Vector *pVelocity)
{
  CBaseCombatWeapon *ActiveWeapon; // eax
  bool v6; // bl
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  v6 = pWeapon == ActiveWeapon;
  if ( pWeapon != nullptr && pWeapon == ActiveWeapon )
    pWeapon->SendWeaponAnim(this: pWeapon, a2: 183);
  CBaseCombatCharacter::Weapon_Drop(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)pWeapon,
    a4: (int)this,
    pWeapon,
    pvecTarget,
    pVelocity);
  if ( v6 && !CBaseCombatCharacter::SwitchToNextBestWeapon(this, pCurrent: nullptr) )
  {
    m_Index = this->m_hViewModel.m_Value[0].m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
        m_pEntity->__vftable[78].SetRefEHandle(this: m_pEntity, a2: (const CBaseHandle *)32);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA1B0
// Name: public: virtual void CBasePlayer::ChangeTeam(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBasePlayer::ChangeTeam(
        CBasePlayer *this@<ecx>,
        int a2@<esi>,
        int iTeamNum,
        bool bAutoTeam,
        bool bSilent)
{
  int v5; // ebx
  IGameEvent *v7; // esi
  int v8; // eax
  IGameEvent_vtbl *v9; // ebx
  int TeamNumber; // eax
  IGameEvent_vtbl *v11; // ebx
  IGameEvent_vtbl *v12; // ebx
  bool v13; // al
  CTeam *Team; // eax
  CTeam *GlobalTeam; // eax

  v5 = iTeamNum;
  if ( GetGlobalTeam(iIndex: iTeamNum) != nullptr )
  {
    if ( iTeamNum != CBaseEntity::GetTeamNumber(this) )
    {
      v7 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_team", a3: 0, a4: 0);
      if ( v7 != nullptr )
      {
        v8 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
               a1: engine,
               a2: this->m_Network.m_pPev,
               a3: a2);
        v7->SetInt(this: v7, a2: "userid", a3: v8);
        v7->SetInt(this: v7, a2: "team", a3: iTeamNum);
        v9 = v7->__vftable;
        TeamNumber = CBaseEntity::GetTeamNumber(this);
        v9->SetInt(this: v7, a2: "oldteam", a3: TeamNumber);
        v7->SetInt(this: v7, a2: "disconnect", a3: this->m_iConnected == PlayerDisconnecting);
        v7->SetInt(this: v7, a2: "autoteam", a3: bAutoTeam);
        v7->SetInt(this: v7, a2: "silent", a3: bSilent);
        if ( CBaseEntity::GetTeamNumber(this) != 0 )
        {
          ((void (__thiscall *)(IGameEvent *, const char *))v7->SetString)(a1: v7, a2: "name");
        }
        else
        {
          v11 = v7->__vftable;
          this->GetPlayerName(this);
          ((void (__thiscall *)(IGameEvent *, const char *))v11->SetString)(a1: v7, a2: "name");
        }
        v12 = v7->__vftable;
        v13 = this->IsNetClient(this);
        v12->SetBool(this: v7, a2: "isbot", a3: !v13);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v7, a3: false);
        v5 = iTeamNum;
      }
      if ( CBaseEntity::GetTeam(this) != nullptr )
      {
        Team = CBaseEntity::GetTeam(this);
        Team->RemovePlayer(this: Team, a2: this);
      }
      if ( v5 != 0 )
      {
        GlobalTeam = GetGlobalTeam(iIndex: v5);
        GlobalTeam->AddPlayer(this: GlobalTeam, a2: this);
      }
      CBaseCombatCharacter::ChangeTeam(this, iTeamNum: v5);
    }
  }
  else
  {
    _Warning(a1: "CBasePlayer::ChangeTeam( %d ) - invalid team index.\n", iTeamNum);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA350
// Name: public: void CBasePlayer::HideViewModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::HideViewModels(CBasePlayer *this)
{
  CBasePlayer::NetworkVar_m_hViewModel *p_m_hViewModel; // esi
  int i; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  p_m_hViewModel = &this->m_hViewModel;
  for ( i = 2; i != 0; --i )
  {
    m_Index = p_m_hViewModel->m_Value[0].m_Index;
    if ( p_m_hViewModel->m_Value[0].m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
        ((void (__thiscall *)(IHandleEntity *, _DWORD, _DWORD))m_pEntity->__vftable[76].GetRefEHandle)(
          a1: m_pEntity,
          a2: 0,
          a3: 0);
    }
    p_m_hViewModel = (CBasePlayer::NetworkVar_m_hViewModel *)((char *)p_m_hViewModel + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA430
// Name: public: virtual int CPlayerInfo::GetArmorValue(void)
// Source: json
//------------------------------------------------------------------------------
int (__thiscall *__thiscall CPlayerInfo::GetArmorValue(CPlayerInfo *this))(IPlayerInfo *this)
{
  return this->IPlayerInfo::__vftable[38].GetTeamIndex;
}

//------------------------------------------------------------------------------
// Address: 0x101BA440
// Name: public: virtual bool CPlayerInfo::IsObserver(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPlayerInfo::IsObserver(CPlayerInfo *this)
{
  return ((int)this->IPlayerInfo::__vftable[31].GetLastUserCommand & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101BA450
// Name: public: virtual void CPlayerInfo::SetLastUserCommand(class CBotCmd const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerInfo::SetLastUserCommand(CPlayerInfo *this, const CBotCmd *ucmd)
{
  int command_number; // edx
  bool hasbeenpredicted; // cl
  float forwardmove; // xmm0_4
  float sidemove; // xmm0_4
  __int16 mousedx; // cx
  float upmove; // xmm0_4
  int random_seed; // ecx
  float x; // xmm0_4
  int tick_count; // edx
  int weaponselect; // ecx
  float y; // xmm0_4
  int weaponsubtype; // edx
  float z; // xmm0_4
  CUserCmd *p_m_LastCmd; // ecx
  CUserCmd cmd; // [esp+4h] [ebp-58h] BYREF

  if ( this->m_pParent->IsBot(this: this->m_pParent) )
  {
    command_number = ucmd->command_number;
    cmd.buttons = ucmd->buttons;
    hasbeenpredicted = ucmd->hasbeenpredicted;
    memset((void *)&cmd.headangles, 0, 24);
    forwardmove = ucmd->forwardmove;
    cmd.command_number = command_number;
    LOBYTE(command_number) = ucmd->impulse;
    cmd.forwardmove = forwardmove;
    sidemove = ucmd->sidemove;
    cmd.hasbeenpredicted = hasbeenpredicted;
    mousedx = ucmd->mousedx;
    cmd.sidemove = sidemove;
    upmove = ucmd->upmove;
    cmd.impulse = command_number;
    LOWORD(command_number) = ucmd->mousedy;
    cmd.mousedx = mousedx;
    random_seed = ucmd->random_seed;
    cmd.upmove = upmove;
    x = ucmd->viewangles.x;
    cmd.mousedy = command_number;
    tick_count = ucmd->tick_count;
    cmd.random_seed = random_seed;
    weaponselect = ucmd->weaponselect;
    cmd.viewangles.x = x;
    y = ucmd->viewangles.y;
    cmd.tick_count = tick_count;
    weaponsubtype = ucmd->weaponsubtype;
    cmd.viewangles.y = y;
    z = ucmd->viewangles.z;
    cmd.weaponselect = weaponselect;
    p_m_LastCmd = &this->m_pParent->m_LastCmd;
    cmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
    cmd.viewangles.z = z;
    cmd.weaponsubtype = weaponsubtype;
    CUserCmd::operator=(this: p_m_LastCmd, src: &cmd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA530
// Name: public: virtual class CBotCmd CPlayerInfo::GetLastUserCommand(void)
// Source: json
//------------------------------------------------------------------------------
CBotCmd *__thiscall CPlayerInfo::GetLastUserCommand(CPlayerInfo *this, CBotCmd *result)
{
  CBotCmd *v2; // eax
  bool (__thiscall **p_IsDead)(IPlayerInfo *); // ecx

  v2 = result;
  result->__vftable = (CBotCmd_vtbl *)&CBotCmd::`vftable';
  result->command_number = 0;
  result->tick_count = 0;
  result->viewangles.x = 0.0;
  result->viewangles.y = 0.0;
  result->viewangles.z = 0.0;
  result->mousedx = 0;
  result->mousedy = 0;
  result->forwardmove = 0.0;
  result->sidemove = 0.0;
  result->upmove = 0.0;
  result->buttons = 0;
  result->impulse = 0;
  result->weaponselect = 0;
  result->weaponsubtype = 0;
  result->random_seed = 0;
  result->hasbeenpredicted = false;
  p_IsDead = &this->IPlayerInfo::__vftable[38].IsDead;
  if ( p_IsDead != nullptr )
  {
    result->buttons = (int)p_IsDead[9];
    result->command_number = (int)p_IsDead[1];
    result->forwardmove = *((float *)p_IsDead + 6);
    result->hasbeenpredicted = *((_BYTE *)p_IsDead + 60);
    result->impulse = *((_BYTE *)p_IsDead + 40);
    result->mousedx = *((_WORD *)p_IsDead + 28);
    result->mousedy = *((_WORD *)p_IsDead + 29);
    result->random_seed = (int)p_IsDead[13];
    result->sidemove = *((float *)p_IsDead + 7);
    result->tick_count = (int)p_IsDead[2];
    result->upmove = *((float *)p_IsDead + 8);
    result->viewangles = *((QAngle *)p_IsDead + 1);
    result->weaponselect = (int)p_IsDead[11];
    result->weaponsubtype = (int)p_IsDead[12];
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101BA600
// Name: public: virtual void CBasePlayer::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetModel(CBasePlayer *this, const char *szModelName)
{
  IMDLCache *v3; // edi
  CStudioHdr *m_pStudioHdr; // eax

  CBaseFlex::SetModel(this, szModelName);
  v3 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  this->m_nBodyPitchPoseParam = CBaseAnimating::LookupPoseParameter(
                                  this,
                                  pStudioHdr: m_pStudioHdr,
                                  szName: "body_pitch");
  v3->EndLock(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101BA670
// Name: public: void CBasePlayer::SetBodyPitch(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetBodyPitch(CBasePlayer *this, float flPitch)
{
  int m_nBodyPitchPoseParam; // edi
  CStudioHdr *m_pStudioHdr; // eax

  m_nBodyPitchPoseParam = this->m_nBodyPitchPoseParam;
  if ( m_nBodyPitchPoseParam >= 0 )
  {
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    CBaseAnimating::SetPoseParameter(
      this,
      pStudioHdr: m_pStudioHdr,
      iParameter: m_nBodyPitchPoseParam,
      flValue: flPitch);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA6D0
// Name: public: void CBasePlayer::SetSplitScreenPlayer(bool,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetSplitScreenPlayer(CBasePlayer *this, bool bSplitScreenPlayer, CBasePlayer *pOwner)
{
  this->m_bSplitScreenPlayer = bSplitScreenPlayer;
  if ( pOwner != nullptr )
  {
    this->m_hSplitOwner.m_Index = pOwner->GetRefEHandle(this: pOwner)->m_Index;
    CBasePlayer::AddSplitScreenPlayer(this: pOwner, pOther: this);
  }
  else
  {
    this->m_hSplitOwner.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA720
// Name: public: class CBasePlayer __near * CBasePlayer::GetSplitScreenPlayerOwner(void)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CBasePlayer::GetSplitScreenPlayerOwner(CBasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hSplitOwner.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101BA750
// Name: public: bool CBasePlayer::IsSplitScreenUserOnEdict(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePlayer::IsSplitScreenUserOnEdict(CBasePlayer *this, edict_t *edict)
{
  IServerUnknown *m_pUnk; // ecx
  int v5; // eax
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // ecx

  if ( !this->m_bSplitScreenPlayer )
    return 0;
  if ( edict != nullptr )
  {
    m_pUnk = edict->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v5 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      if ( v5 != 0 )
      {
        m_Index = this->m_hSplitOwner.m_Index;
        if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( (IHandleEntity *)v5 == m_pEntity )
          return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101BA7D0
// Name: public: virtual bool CBasePlayer::EnsureSplitScreenTeam(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePlayer::EnsureSplitScreenTeam(CBasePlayer *this)
{
  unsigned int m_Index; // ecx
  CBasePlayer *SplitScreenPlayerOwner; // eax
  CBasePlayer *v4; // eax
  int TeamNumber; // edi
  CBasePlayer *v6; // eax
  int v7; // eax
  const char *TeamName; // eax
  CBasePlayer_vtbl *v9; // edi
  CBasePlayer *v10; // eax
  int v11; // eax

  if ( !g_pGameRules->ForceSplitScreenPlayersOnToSameTeam(this: g_pGameRules) )
    return 0;
  if ( !this->m_bSplitScreenPlayer )
    return 0;
  m_Index = this->m_hSplitOwner.m_Index;
  if ( m_Index == -1 )
    return 0;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return 0;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    return 0;
  SplitScreenPlayerOwner = CBasePlayer::GetSplitScreenPlayerOwner(this);
  if ( CBaseEntity::GetTeamNumber(this: SplitScreenPlayerOwner) < 2 )
    return 0;
  v4 = CBasePlayer::GetSplitScreenPlayerOwner(this);
  TeamNumber = CBaseEntity::GetTeamNumber(this: v4);
  if ( CBaseEntity::GetTeamNumber(this) == TeamNumber )
    return 0;
  v6 = CBasePlayer::GetSplitScreenPlayerOwner(this);
  v7 = CBaseEntity::GetTeamNumber(this: v6);
  TeamName = GetTeamName(iTeam: v7);
  _Msg(a1: "Forcing split screen player onto team %s\n", TeamName);
  v9 = this->__vftable;
  v10 = CBasePlayer::GetSplitScreenPlayerOwner(this);
  v11 = CBaseEntity::GetTeamNumber(this: v10);
  v9->ForceChangeTeam(this, a2: v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101BA8A0
// Name: public: class CPostProcessController const __near * CNetworkHandleBase<class CPostProcessController,class CBasePlayer::NetworkVar_m_hPostProcessCtrl>::Set(class CPostProcessController const __near *)
// Source: json
//------------------------------------------------------------------------------
const CPostProcessController *__thiscall CNetworkHandleBase<CPostProcessController,CBasePlayer::NetworkVar_m_hPostProcessCtrl>::Set(
        CNetworkHandleBase<CPostProcessController,CBasePlayer::NetworkVar_m_hPostProcessCtrl> *this,
        const CPostProcessController *val)
{
  unsigned int m_Index; // eax
  const CPostProcessController *m_pEntity; // ecx
  CNetworkHandleBase<CPostProcessController,CBasePlayer::NetworkVar_m_hPostProcessCtrl> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CPostProcessController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 718;
    if ( *((_BYTE *)this - 2788) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xB38u);
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
// Address: 0x101BA930
// Name: public: class CColorCorrection const __near * CNetworkHandleBase<class CColorCorrection,class CBasePlayer::NetworkVar_m_hColorCorrectionCtrl>::Set(class CColorCorrection const __near *)
// Source: json
//------------------------------------------------------------------------------
const CColorCorrection *__thiscall CNetworkHandleBase<CColorCorrection,CBasePlayer::NetworkVar_m_hColorCorrectionCtrl>::Set(
        CNetworkHandleBase<CColorCorrection,CBasePlayer::NetworkVar_m_hColorCorrectionCtrl> *this,
        const CColorCorrection *val)
{
  unsigned int m_Index; // eax
  const CColorCorrection *m_pEntity; // ecx
  CNetworkHandleBase<CColorCorrection,CBasePlayer::NetworkVar_m_hColorCorrectionCtrl> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CColorCorrection *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 719;
    if ( *((_BYTE *)this - 2792) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xB3Cu);
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
// Address: 0x101BA9C0
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBasePlayer::NetworkVar_m_hVehicle>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hVehicle>::Set(
        CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hVehicle> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hVehicle> *v5; // eax
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
    v5 = this - 768;
    if ( *((_BYTE *)this - 2988) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xC00u);
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
// Address: 0x101BAA50
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBasePlayer::NetworkVar_m_hTonemapController>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hTonemapController>::Set(
        CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hTonemapController> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hTonemapController> *v5; // eax
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
    v5 = this - 808;
    if ( *((_BYTE *)this - 3148) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xCA0u);
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
// Address: 0x101BAAE0
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBasePlayer::NetworkVar_m_hViewEntity>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hViewEntity>::Set(
        CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hViewEntity> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hViewEntity> *v5; // eax
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
    v5 = this - 983;
    if ( *((_BYTE *)this - 3848) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xF5Cu);
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
// Address: 0x101BAB70
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBasePlayer::NetworkVar_m_hConstraintEntity>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hConstraintEntity>::Set(
        CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hConstraintEntity> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hConstraintEntity> *v5; // eax
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
    v5 = this - 985;
    if ( *((_BYTE *)this - 3856) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xF64u);
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
// Address: 0x101BAD50
// Name: public: fogplayerparams_t::fogplayerparams_t(void)
// Source: json
//------------------------------------------------------------------------------
fogplayerparams_t *__thiscall fogplayerparams_t::fogplayerparams_t(fogplayerparams_t *this)
{
  CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl> *p_m_hCtrl; // edi
  unsigned int m_Index; // eax

  p_m_hCtrl = &this->m_hCtrl;
  this->__vftable = (fogplayerparams_t_vtbl *)&fogplayerparams_t::`vftable';
  this->m_hCtrl.m_Value.m_Index = -1;
  m_Index = this->m_hCtrl.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    this->NetworkStateChanged(this, a2: &this->m_hCtrl);
    p_m_hCtrl->m_Value.m_Index = -1;
  }
  this->m_flTransitionTime = -1.0;
  this->m_OldColor.a = 0;
  *(_WORD *)&this->m_OldColor.r = 0;
  this->m_NewColor.a = 0;
  *(_WORD *)&this->m_NewColor.r = 0;
  this->m_flOldStart = 0.0;
  this->m_flOldEnd = 0.0;
  this->m_flOldMaxDensity = 1.0;
  this->m_flOldHDRColorScale = 1.0;
  this->m_flOldFarZ = 0.0;
  this->m_flNewStart = 0.0;
  this->m_flNewEnd = 0.0;
  this->m_flNewMaxDensity = 1.0;
  this->m_flNewHDRColorScale = 1.0;
  this->m_flNewFarZ = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BAEE0
// Name: public: class CBaseCombatWeapon __near * CBasePlayer::Weapon_GetLast(void)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__thiscall CBasePlayer::Weapon_GetLast(CBasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hLastWeapon.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101BB090
// Name: public: virtual void CBasePlayer::NetworkVar_m_Local::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::NetworkVar_m_Local::NetworkStateChanged(CBasePlayer::NetworkVar_m_Local *this)
{
  CBaseEdict *v1; // ecx

  if ( *((_BYTE *)this - 2204) != 0 )
  {
    *((_BYTE *)this - 2200) |= 1u;
  }
  else
  {
    v1 = *((CBaseEdict **)this - 566);
    if ( v1 != nullptr )
    {
      v1->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v1)->m_iChangeInfoSerialNumber = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB0C0
// Name: public: virtual void CBasePlayer::NetworkVar_pl::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::NetworkVar_pl::NetworkStateChanged(CBasePlayer::NetworkVar_pl *this)
{
  CBaseEdict *v1; // ecx

  if ( *((_BYTE *)this - 2816) != 0 )
  {
    *((_BYTE *)this - 2812) |= 1u;
  }
  else
  {
    v1 = *((CBaseEdict **)this - 719);
    if ( v1 != nullptr )
    {
      v1->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v1)->m_iChangeInfoSerialNumber = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB450
// Name: public: char __near * CBasePlayer::NetworkVar_m_szLastPlaceName::GetForModify(void)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer::NetworkVar_m_szLastPlaceName *__thiscall CBasePlayer::NetworkVar_m_szLastPlaceName::GetForModify(
        CBasePlayer::NetworkVar_m_szLastPlaceName *this)
{
  CBaseEdict *v3; // ecx

  if ( *((_BYTE *)this - 3996) != 0 )
  {
    *((_BYTE *)this - 3992) |= 1u;
    return this;
  }
  else
  {
    v3 = *((CBaseEdict **)this - 1014);
    if ( v3 != nullptr )
    {
      v3->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v3)->m_iChangeInfoSerialNumber = 0;
    }
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB490
// Name: public: virtual void CBasePlayer::NetworkVar_m_PlayerFog::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::NetworkVar_m_PlayerFog::NetworkStateChanged(
        CBasePlayer::NetworkVar_m_PlayerFog *this,
        void *pVar)
{
  char *v2; // eax
  CBaseEdict *v3; // ecx

  v2 = (char *)this - 2792;
  if ( *((_BYTE *)this - 2708) != 0 )
  {
    v2[88] |= 1u;
  }
  else
  {
    v3 = *((CBaseEdict **)v2 + 6);
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: v3, offset: (_WORD)pVar - (_WORD)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB4C0
// Name: public: virtual void CBasePlayer::NetworkVar_m_PlayerFog::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::NetworkVar_m_PlayerFog::NetworkStateChanged(CBasePlayer::NetworkVar_m_PlayerFog *this)
{
  CBaseEdict *v1; // ecx

  if ( *((_BYTE *)this - 2708) != 0 )
  {
    *((_BYTE *)this - 2704) |= 1u;
  }
  else
  {
    v1 = *((CBaseEdict **)this - 692);
    if ( v1 != nullptr )
    {
      v1->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v1)->m_iChangeInfoSerialNumber = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB4F0
// Name: public: virtual int CBasePlayer::ShouldTransmit(class CCheckTransmitInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::ShouldTransmit(CBasePlayer *this, const CCheckTransmitInfo *pInfo)
{
  int m_iCameraManIndex; // ecx
  edict_t *m_pPev; // eax

  if ( pInfo->m_pClientEnt == this->m_Network.m_pPev
    || CBasePlayer::IsSplitScreenUserOnEdict(this, edict: pInfo->m_pClientEnt) != 0 )
  {
    return 8;
  }
  m_iCameraManIndex = HLTVDirector()->m_iCameraManIndex;
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( (edict_t *)m_iCameraManIndex == m_pPev
    && LOBYTE(CBaseEntity::Instance(pent: pInfo->m_pClientEnt)[3].m_vecAngVelocity.z) != 0 )
  {
    this->m_Network.AreaNum(this: &this->m_Network);
    return 8;
  }
  if ( this->IsAlive(this) && (this->m_fEffects.m_Value & 0x20) != 0
    || (this->m_afPhysicsFlags.m_Value & 8) != 0
    && (float)(gpGlobals->curtime - this->m_flDeathTime.m_Value) > 0.5
    && this->m_lifeState.m_Value == 2
    && (float)(gpGlobals->curtime - this->m_flDeathAnimTime) > 0.5 )
  {
    return 16;
  }
  else
  {
    return CBaseEntity::ShouldTransmit(this, pInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB5E0
// Name: public: virtual bool CBasePlayer::SetObserverMode(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::SetObserverMode(CBasePlayer *this, unsigned int mode)
{
  int v2; // ebx
  int m_nValue; // eax
  int v5; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int m_Value; // eax
  edict_t *m_pPev; // ecx
  bool result; // al
  CBasePlayer_vtbl *v11; // edi
  CBaseEntity *v12; // eax
  CBasePlayer_vtbl *v13; // edi
  CBaseEntity *v14; // eax

  v2 = mode;
  if ( mode == 6 )
  {
    v2 = 3;
  }
  else
  {
    if ( mode > 6 )
      return false;
    if ( (int)mode > 3 && CBaseEntity::GetTeamNumber(this) > 1 )
    {
      if ( mp_forcecamera.m_pParent != nullptr )
        m_nValue = mp_forcecamera.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v5 = m_nValue - 1;
      if ( v5 != 0 )
      {
        if ( v5 == 1 )
          v2 = 3;
      }
      else
      {
        v2 = 4;
      }
    }
  }
  m_Index = this->m_hObserverTarget.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( __RTDynamicCast(
         inptr: m_pEntity,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CPlantedC4 `RTTI Type Descriptor',
         isReference: 0) != nullptr )
    v2 = 5;
  m_Value = this->m_iObserverMode.m_Value;
  if ( m_Value > 1 )
    this->m_iObserverLastMode = m_Value;
  if ( m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC48u);
    }
    this->m_iObserverMode.m_Value = v2;
  }
  switch ( v2 )
  {
    case 0:
    case 1:
    case 3:
      CBasePlayer::SetFOV(this, pRequester: this, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
      this->SetViewOffset(this, a2: &vec3_origin);
      this->SetObserverTarget(this, a2: nullptr);
      CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
      this->CheckObserverSettings(this);
      result = true;
      break;
    case 2:
    case 6:
      CBasePlayer::SetFOV(this, pRequester: this, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
      v13 = this->__vftable;
      v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hObserverTarget);
      v13->SetObserverTarget(this, a2: v14);
      this->SetViewOffset(this, a2: &vec3_origin);
      CBaseEntity::SetMoveType(this, val: MOVETYPE_OBSERVER, moveCollide: MOVECOLLIDE_DEFAULT);
      this->CheckObserverSettings(this);
      result = true;
      break;
    case 4:
    case 5:
      v11 = this->__vftable;
      v12 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hObserverTarget);
      v11->SetObserverTarget(this, a2: v12);
      CBaseEntity::SetMoveType(this, val: MOVETYPE_OBSERVER, moveCollide: MOVECOLLIDE_DEFAULT);
      this->CheckObserverSettings(this);
      result = true;
      break;
    default:
      this->SetObserverTarget(this, a2: nullptr);
      this->CheckObserverSettings(this);
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BB810
// Name: public: virtual void CBasePlayer::ValidateCurrentObserverTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ValidateCurrentObserverTarget(CBasePlayer *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  CBaseEntity *v4; // eax

  m_Index = this->m_hObserverTarget.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( !this->IsValidObserverTarget(this, a2: m_pEntity) )
  {
    v4 = this->FindNextObserverTarget(this, a2: 0);
    if ( v4 != nullptr )
    {
      this->SetObserverTarget(this, a2: v4);
    }
    else if ( mp_forcecamera.m_pParent != nullptr && mp_forcecamera.m_pParent->m_Value.m_nValue != 0 )
    {
      this->ForceObserverMode(this, a2: 3);
      CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hObserverTarget>::Set(
        this: &this->m_hObserverTarget,
        val: nullptr);
    }
    else
    {
      this->ForceObserverMode(this, a2: 6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB8C0
// Name: public: virtual bool CBasePlayer::SetObserverTarget(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CBasePlayer::SetObserverTarget@<al>(
        CBasePlayer *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseEntity *target)
{
  bool (__thiscall *IsValidObserverTarget)(CBasePlayer *, CBaseEntity *); // edx
  char result; // al
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  CBaseEntity_vtbl *v9; // edx
  const QAngle *v10; // eax
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  int v12; // eax
  const Vector *v13; // eax
  IMDLCache *v14; // edi
  CBaseEntity_vtbl *v15; // edx
  int v16; // eax
  _DWORD v18[3]; // [esp+14h] [ebp-E4h] BYREF
  CGameTrace tr; // [esp+20h] [ebp-D8h] BYREF
  int v20; // [esp+74h] [ebp-84h]
  Ray_t ray; // [esp+78h] [ebp-80h] BYREF
  float v22; // [esp+C8h] [ebp-30h]
  Vector end; // [esp+CCh] [ebp-2Ch] BYREF
  Vector dir; // [esp+D8h] [ebp-20h] BYREF
  Vector start; // [esp+E4h] [ebp-14h]
  void *v26; // [esp+F0h] [ebp-8h]
  void *retaddr; // [esp+F8h] [ebp+0h]

  start.z = a2;
  v26 = retaddr;
  IsValidObserverTarget = this->IsValidObserverTarget;
  LODWORD(start.y) = this;
  result = ((int (__stdcall *)(CBaseEntity *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, CBaseEntity *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))IsValidObserverTarget)(
             a1: target,
             a2: a3,
             a3: a4,
             a4: v18[0],
             a5: v18[1],
             a6: v18[2],
             a7: LODWORD(tr.startpos.x),
             a8: LODWORD(tr.startpos.y),
             a9: LODWORD(tr.startpos.z),
             a10: LODWORD(tr.endpos.x),
             a11: LODWORD(tr.endpos.y),
             a12: LODWORD(tr.endpos.z),
             a13: LODWORD(tr.plane.normal.x),
             a14: LODWORD(tr.plane.normal.y),
             a15: LODWORD(tr.plane.normal.z),
             a16: LODWORD(tr.plane.dist),
             a17: *(_DWORD *)&tr.plane.type,
             a18: LODWORD(tr.fraction),
             a19: tr.contents,
             a20: *(_DWORD *)&tr.dispFlags,
             a21: LODWORD(tr.fractionleftsolid),
             a22: tr.surface.name,
             a23: *(_DWORD *)&tr.surface.surfaceProps,
             a24: tr.hitgroup,
             a25: *(_DWORD *)&tr.physicsbone,
             a26: tr.m_pEnt,
             a27: tr.hitbox,
             a28: v20,
             a29: LODWORD(ray.m_Start.x),
             a30: LODWORD(ray.m_Start.y),
             a31: LODWORD(ray.m_Start.z),
             a32: LODWORD(ray.m_Start.w),
             a33: LODWORD(ray.m_Delta.x),
             a34: LODWORD(ray.m_Delta.y),
             a35: LODWORD(ray.m_Delta.z),
             a36: LODWORD(ray.m_Delta.w),
             a37: LODWORD(ray.m_StartOffset.x),
             a38: LODWORD(ray.m_StartOffset.y),
             a39: LODWORD(ray.m_StartOffset.z),
             a40: LODWORD(ray.m_StartOffset.w),
             a41: LODWORD(ray.m_Extents.x),
             a42: LODWORD(ray.m_Extents.y),
             a43: LODWORD(ray.m_Extents.z),
             a44: LODWORD(ray.m_Extents.w),
             a45: ray.m_pWorldAxisTransform,
             a46: *(_DWORD *)&ray.m_IsRay,
             a47: *(_DWORD *)(&ray.m_IsSwept + 3),
             a48: *(_DWORD *)(&ray.m_IsSwept + 7),
             a49: LODWORD(v22),
             a50: LODWORD(end.x),
             a51: LODWORD(end.y),
             a52: LODWORD(end.z),
             a53: LODWORD(dir.x),
             a54: LODWORD(dir.y),
             a55: LODWORD(dir.z),
             a56: LODWORD(start.x));
  if ( result != 0 )
  {
    CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hObserverTarget>::Set(
      this: &this->m_hObserverTarget,
      val: target);
    CBasePlayer::SetFOV(this, pRequester: this, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
    if ( this->m_iObserverMode.m_Value == 6 )
    {
      EyePosition = target->EyePosition;
      LODWORD(start.x) = &dir;
      ((void (__thiscall *)(CBaseEntity *))EyePosition)(a1: target);
      v9 = target->__vftable;
      LODWORD(dir.z) = &end;
      v10 = v9->EyeAngles(this: target);
      AngleVectors(angles: v10, forward: (Vector *)LODWORD(dir.z));
      VectorNormalize(vec: &end);
      *(float *)(&ray.m_IsSwept + 3) = dir.x - (float)(end.x * 64.0);
      ray.m_Extents.y = 0.0;
      GetViewVectors = g_pGameRules->GetViewVectors;
      *(float *)(&ray.m_IsSwept + 7) = dir.y - (float)(end.y * 64.0);
      v22 = dir.z - (float)(end.z * 64.0);
      v12 = (int)GetViewVectors(this: g_pGameRules);
      v13 = (const Vector *)((int (__thiscall *)(CGameRules *, int))g_pGameRules->GetViewVectors)(
                              a1: g_pGameRules,
                              a2: v12 + 48);
      Ray_t::Init(
        this: (Ray_t *)&tr.m_pEnt,
        start: &dir,
        end: (const Vector *)(&ray.m_IsSwept + 3),
        mins: v13 + 3,
        maxs: (const Vector *)LODWORD(start.x));
      v14 = mdlcache;
      mdlcache->BeginLock(this: mdlcache);
      UTIL_TraceRay(
        ray: (const Ray_t *)&tr.m_pEnt,
        mask: 0x201400Bu,
        ignore: target,
        collisionGroup: 8,
        ptr: (CGameTrace *)v18);
      v15 = target->__vftable;
      start.x = *(float *)LODWORD(start.y);
      v16 = (int)v15->EyeAngles(this: target);
      (*(void (__thiscall **)(_DWORD, CGameTrace *, int))(LODWORD(start.x) + 1644))(
        a1: LODWORD(start.y),
        a2: &tr,
        a3: v16);
      v14->EndLock(this: v14);
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BBA60
// Name: public: void CBasePlayer::DumpPerfToRecipient(class CBasePlayer __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CBasePlayer::DumpPerfToRecipient(
        CBasePlayer *this@<ecx>,
        int a2@<ebp>,
        CBasePlayer *pRecipient,
        int nMaxRecords)
{
  CBasePlayer *v4; // esi
  int m_Tail; // eax
  float v6; // xmm0_4
  int v7; // edi
  float x; // xmm2_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v11; // xmm1_4
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *m_pMemory; // esi
  int v13; // eax
  float m_flFinalSimulationTime; // xmm6_4
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *v15; // esi
  float v16; // xmm1_4
  __int128 v17; // xmm0
  int m_Previous; // eax
  int v19; // esi
  int v20; // edi
  char v21[12]; // [esp+40h] [ebp-1ACh] BYREF
  _BYTE line_116[272]; // [esp+C0h] [ebp-12Ch] OVERLAPPED BYREF
  int v23; // [esp+1D0h] [ebp-1Ch]
  int v24; // [esp+1D4h] [ebp-18h]
  CBasePlayer *v25; // [esp+1D8h] [ebp-14h]
  int len; // [esp+1DCh] [ebp-10h]
  int v27; // [esp+1E0h] [ebp-Ch]
  void *v28; // [esp+1E4h] [ebp-8h]
  void *retaddr; // [esp+1ECh] [ebp+0h]

  v27 = a2;
  v28 = retaddr;
  v4 = this;
  v25 = this;
  if ( pRecipient != nullptr )
  {
    memset(line_116, 0, 256);
    m_Tail = this->m_vecPlayerSimInfo.m_Tail;
    v6 = 0.0;
    v7 = 0;
    len = 0;
    x = 0.0;
    y = 0.0;
    z = 0.0;
    v11 = 0.0;
    if ( m_Tail != 0xFFFF )
    {
      while ( 1 )
      {
        m_pMemory = v4->m_vecPlayerSimInfo.m_Memory.m_pMemory;
        v13 = (unsigned __int16)m_Tail;
        m_flFinalSimulationTime = m_pMemory[v13].m_Element.m_flFinalSimulationTime;
        v15 = &m_pMemory[v13];
        v16 = v11 - m_flFinalSimulationTime;
        v24 = v13 * 40;
        if ( len > 0 && v16 > 0.0 )
        {
          v17 = 0;
          *(float *)&v17 = fsqrt(
                             (float)((float)((float)(v15->m_Element.m_vecAbsOrigin.y - y)
                                           * (float)(v15->m_Element.m_vecAbsOrigin.y - y))
                                   + (float)((float)(v15->m_Element.m_vecAbsOrigin.z - z)
                                           * (float)(v15->m_Element.m_vecAbsOrigin.z - z)))
                           + (float)((float)(v15->m_Element.m_vecAbsOrigin.x - x)
                                   * (float)(v15->m_Element.m_vecAbsOrigin.x - x)));
          *(_OWORD *)&line_116[256] = v17;
          v6 = *(float *)&v17 / v16;
        }
        v23 = V_snprintf(
                pDest: v21,
                maxLen: 128,
                pFormat: "%.3f %d %d %.3f %.3f %.3f [vel %.2f]\n",
                v15->m_Element.m_flTime,
                v15->m_Element.m_nNumCmds,
                v15->m_Element.m_nTicksCorrected,
                m_flFinalSimulationTime,
                v15->m_Element.m_flGameSimulationTime,
                v15->m_Element.m_flServerFrameTime,
                v6);
        if ( v7 + v23 > 200 )
        {
          ClientPrint(
            player: pRecipient,
            msg_dest: 2,
            msg_name: line_116,
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
          line_116[0] = 0;
          v7 = 0;
        }
        V_strncpy(pDest: &line_116[v7], pSrc: v21, maxLen: 256 - v7);
        v7 += v23;
        ++len;
        if ( nMaxRecords != -1 && len >= nMaxRecords )
          break;
        m_Tail = *(unsigned __int16 *)((char *)&v25->m_vecPlayerSimInfo.m_Memory.m_pMemory->m_Previous + v24);
        x = v15->m_Element.m_vecAbsOrigin.x;
        y = v15->m_Element.m_vecAbsOrigin.y;
        z = v15->m_Element.m_vecAbsOrigin.z;
        v11 = v15->m_Element.m_flFinalSimulationTime;
        if ( m_Tail == 0xFFFF )
          break;
        v6 = 0.0;
        v4 = v25;
      }
      if ( v7 > 0 )
        ClientPrint(
          player: pRecipient,
          msg_dest: 2,
          msg_name: line_116,
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
    }
    m_Previous = v25->m_vecPlayerCmdInfo.m_Tail;
    v19 = 0;
    len = 0;
    if ( m_Previous != 0xFFFF )
    {
      do
      {
        v20 = (unsigned __int16)m_Previous;
        v24 = V_snprintf(
                pDest: v21,
                maxLen: 128,
                pFormat: "%.3f %d %d\n",
                v25->m_vecPlayerCmdInfo.m_Memory.m_pMemory[(unsigned __int16)m_Previous].m_Element.m_flTime,
                v25->m_vecPlayerCmdInfo.m_Memory.m_pMemory[(unsigned __int16)m_Previous].m_Element.m_nNumCmds,
                v25->m_vecPlayerCmdInfo.m_Memory.m_pMemory[(unsigned __int16)m_Previous].m_Element.m_nDroppedPackets);
        if ( v19 + v24 > 200 )
        {
          ClientPrint(
            player: pRecipient,
            msg_dest: 2,
            msg_name: line_116,
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
          line_116[0] = 0;
          v19 = 0;
        }
        V_strncpy(pDest: &line_116[v19], pSrc: v21, maxLen: 256 - v19);
        v19 += v24;
        ++len;
        if ( nMaxRecords != -1 && len >= nMaxRecords )
          break;
        m_Previous = v25->m_vecPlayerCmdInfo.m_Memory.m_pMemory[v20].m_Previous;
      }
      while ( m_Previous != 0xFFFF );
      if ( v19 > 0 )
        ClientPrint(
          player: pRecipient,
          msg_dest: 2,
          msg_name: line_116,
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBD70
// Name: public: virtual void CBasePlayer::CommitSuicide(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::CommitSuicide(CBasePlayer *this, bool bExplode, bool bForce)
{
  IMDLCache *v3; // edi
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  float curtime; // xmm0_4
  CBasePlayer_vtbl *v7; // ebx
  CTakeDamageInfo *v8; // eax
  IMDLCache *m_pCache; // ecx
  CTakeDamageInfo v10; // [esp+20h] [ebp-60h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+7Ch] [ebp-4h]

  v3 = mdlcache;
  BeginLock = mdlcache->BeginLock;
  cacheCriticalSection.m_pCache = mdlcache;
  BeginLock(this: mdlcache);
  if ( this->IsAlive(this) && ((curtime = gpGlobals->curtime, this->m_fNextSuicideTime <= curtime) || bForce) )
  {
    this->m_fNextSuicideTime = curtime + 5.0;
    if ( this->m_iHealth.m_Value != 0 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      this->m_iHealth.m_Value = 0;
    }
    v7 = this->__vftable;
    v8 = CTakeDamageInfo::CTakeDamageInfo(
           this: &v10,
           pInflictor: this,
           pAttacker: this,
           flDamage: 0.0,
           bitsDamageType: (bExplode ? 8256 : 4096) | 0x800,
           iKillType: this->m_iSuicideCustomKillFlags,
           iObjectsPenetrated: 0);
    v7->Event_Killed(this, a2: v8);
    this->Event_Dying(this);
    m_pCache = cacheCriticalSection.m_pCache;
    this->m_iSuicideCustomKillFlags = 0;
    m_pCache->EndLock(this: m_pCache);
  }
  else
  {
    v3->EndLock(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBE80
// Name: public: virtual void CBasePlayer::ImpulseCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ImpulseCommands(CBasePlayer *this)
{
  int m_nImpulse; // eax
  int v3; // eax
  CBasePlayer_vtbl *v4; // edx
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseCombatWeapon_vtbl *v6; // edx
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v8; // eax
  Vector *(__thiscall *v9)(CBaseEntity *, Vector *); // edx
  const Vector *v10; // eax
  CSprayCan *Entity; // eax
  IGameEvent *v12; // eax
  IGameEvent *v13; // edi
  IGameEvent_vtbl *v14; // ebx
  int UserID; // eax
  float tr_44; // [esp+34h] [ebp-64h]
  Vector vecAbsEnd; // [esp+5Ch] [ebp-3Ch] BYREF
  Vector v18; // [esp+68h] [ebp-30h] BYREF
  Vector forward; // [esp+74h] [ebp-24h] BYREF
  unsigned int mask[3]; // [esp+80h] [ebp-18h] BYREF
  float v21; // [esp+8Ch] [ebp-Ch]
  float v22; // [esp+90h] [ebp-8h]
  float v23; // [esp+94h] [ebp-4h]
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  m_nImpulse = this->m_nImpulse;
  switch ( m_nImpulse )
  {
    case 100:
      v3 = this->FlashlightIsOn(this);
      v4 = this->__vftable;
      if ( v3 != 0 )
        v4->FlashlightTurnOff(this, a2: true);
      else
        v4->FlashlightTurnOn(this, a2: true);
      this->m_nImpulse = 0;
      break;
    case 200:
      if ( sv_cheats->m_pParent == nullptr || sv_cheats->m_pParent->m_Value.m_nValue == 0 )
        goto LABEL_19;
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
      v6 = ActiveWeapon->__vftable;
      if ( (ActiveWeapon->m_fEffects.m_Value & 0x20) != 0 )
        v6->Deploy(this: ActiveWeapon);
      else
        v6->Holster(this: ActiveWeapon, a2: nullptr);
      this->m_nImpulse = 0;
      break;
    case 201:
      if ( this->m_flNextDecalTime > gpGlobals->curtime )
        goto LABEL_19;
      CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: nullptr);
      EyePosition = this->EyePosition;
      v21 = forward.x * 128.0;
      v22 = forward.y * 128.0;
      v23 = forward.z * 128.0;
      v8 = (float *)EyePosition(this, result: &v18);
      v9 = this->EyePosition;
      *(float *)mask = *v8 + v21;
      *(float *)&mask[1] = v8[1] + v22;
      *(float *)&mask[2] = v8[2] + v23;
      v10 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v9)(a1: this);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: v10,
        &vecAbsEnd,
        (unsigned int)mask,
        ignore: (const IHandleEntity *)0x400B,
        collisionGroup: (int)this,
        ptr: nullptr);
      if ( tr_44 == 1.0 )
        goto LABEL_19;
      this->m_flNextDecalTime = decalfrequency.m_pParent->m_Value.m_fValue + gpGlobals->curtime;
      Entity = _CreateEntityTemplate<CSprayCan>(newEnt: nullptr, className: "spraycan");
      CSprayCan::Spawn(this: Entity, pOwner: this);
      v12 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_decal", a3: 0, a4: 0);
      v13 = v12;
      if ( v12 == nullptr )
        goto LABEL_19;
      v14 = v12->__vftable;
      UserID = CBasePlayer::GetUserID(this);
      v14->SetInt(this: v13, a2: "userid", a3: UserID);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v13, a3: false);
      this->m_nImpulse = 0;
      break;
    case 202:
      if ( this->m_flNextDecalTime > gpGlobals->curtime )
        goto LABEL_19;
      EntityMessageBegin(entity: this, reliable: 0);
      MessageWriteByte(iValue: 1u);
      MessageEnd();
      this->m_flNextDecalTime = decalfrequency.m_pParent->m_Value.m_fValue + gpGlobals->curtime;
      this->m_nImpulse = 0;
      break;
    default:
      this->CheatImpulseCommands(this, a2: m_nImpulse);
LABEL_19:
      this->m_nImpulse = 0;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC1B0
// Name: public: virtual void CBasePlayer::CheatImpulseCommands(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBasePlayer::CheatImpulseCommands(CBasePlayer *this@<ecx>, int a2@<esi>, int iImpulse)
{
  const QAngle *v4; // eax
  CBaseEntity *v5; // eax
  int v6; // eax
  CBaseEntity *v7; // eax
  CBaseEntity *v8; // esi
  const char *pszValue; // eax
  const char *v10; // eax
  const char *v11; // esi
  CBaseEntity *v12; // eax
  int v13; // eax
  CAI_BaseNPC *v14; // esi
  const char *v15; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v17; // eax
  Vector *(__thiscall *v18)(CBaseEntity *, Vector *); // edx
  const Vector *v19; // eax
  CBloodSplat *Entity; // eax
  CBaseEntity *v21; // eax
  float tr_44; // [esp+C4h] [ebp-C4h]
  CGameTrace ptr; // [esp+ECh] [ebp-9Ch] BYREF
  Vector vecAbsEnd; // [esp+140h] [ebp-48h] BYREF
  _BYTE v25[12]; // [esp+14Ch] [ebp-3Ch] BYREF
  Vector vecOrigin; // [esp+158h] [ebp-30h] BYREF
  Vector forward; // [esp+164h] [ebp-24h] BYREF
  Vector end; // [esp+170h] [ebp-18h] BYREF
  Vector start; // [esp+17Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+188h] [ebp+0h] BYREF

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    switch ( iImpulse )
    {
      case 76:
        if ( giPrecacheGrunt != 0 )
        {
          v4 = this->EyeAngles(this);
          UTIL_YawToVector(result: &start, yaw: v4->y);
          vecOrigin.x = (float)(start.x * 128.0) + this->m_vecOrigin.m_Value.x;
          vecOrigin.y = this->m_vecOrigin.m_Value.y + (float)(start.y * 128.0);
          vecOrigin.z = this->m_vecOrigin.m_Value.z + (float)(start.z * 128.0);
          CBaseEntity::Create(
            szName: "NPC_human_grunt",
            &vecOrigin,
            vecAngles: &this->m_angRotation.m_Value,
            pOwner: nullptr);
        }
        else
        {
          giPrecacheGrunt = 1;
          _Msg(a1: "You must now restart to use Grunt-o-matic.\n");
        }
        break;
      case 81:
        this->GiveNamedItem(this, a2: "weapon_cubemap", a3: 0, a4: true);
        break;
      case 82:
        CreateJeep(pPlayer: this);
        break;
      case 83:
        CreateAirboat(pPlayer: this);
        break;
      case 101:
        gEvilImpulse101 = 1;
        this->EquipSuit(this, a2: true);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 255, szName: "Pistol", bSuppressSound: false);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 255, szName: "AR2", bSuppressSound: false);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 5, szName: "AR2AltFire", bSuppressSound: false);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 255, szName: "SMG1", bSuppressSound: false);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 255, szName: "Buckshot", bSuppressSound: false);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 3, szName: "smg1_grenade", bSuppressSound: false);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 3, szName: "rpg_round", bSuppressSound: false);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 5, szName: "grenade", bSuppressSound: false);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 32, szName: "357", bSuppressSound: false);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 16, szName: "XBowBolt", bSuppressSound: false);
        this->GiveNamedItem(this, a2: "weapon_smg1", a3: 0, a4: true);
        this->GiveNamedItem(this, a2: "weapon_frag", a3: 0, a4: true);
        this->GiveNamedItem(this, a2: "weapon_crowbar", a3: 0, a4: true);
        this->GiveNamedItem(this, a2: "weapon_pistol", a3: 0, a4: true);
        this->GiveNamedItem(this, a2: "weapon_ar2", a3: 0, a4: true);
        this->GiveNamedItem(this, a2: "weapon_shotgun", a3: 0, a4: true);
        this->GiveNamedItem(this, a2: "weapon_physcannon", a3: 0, a4: true);
        this->GiveNamedItem(this, a2: "weapon_bugbait", a3: 0, a4: true);
        this->GiveNamedItem(this, a2: "weapon_rpg", a3: 0, a4: true);
        this->GiveNamedItem(this, a2: "weapon_357", a3: 0, a4: true);
        this->GiveNamedItem(this, a2: "weapon_crossbow", a3: 0, a4: true);
        if ( this->m_iHealth.m_Value < 100 )
          ((void (__thiscall *)(CBasePlayer *, int, _DWORD))this->TakeHealth)(a1: this, a2: 1103626240, a3: 0);
        gEvilImpulse101 = 0;
        break;
      case 102:
        CGib::SpawnRandomGibs(pVictim: this, cGibs: 1, eGibType: GIB_HUMAN);
        break;
      case 103:
        v5 = this->FindEntityForward(this, a2: 1);
        if ( v5 != nullptr )
        {
          v6 = (int)v5->MyNPCPointer(this: v5);
          if ( v6 != 0 )
            (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 2436))(a1: v6);
        }
        break;
      case 106:
        v7 = this->FindEntityForward(this, a2: 1);
        v8 = v7;
        if ( v7 != nullptr )
        {
          pszValue = v7->m_iClassname.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          _Msg(a1: "Classname: %s", pszValue);
          if ( v8->m_iName.m_Value.pszValue != nullptr )
            _Msg(a1: " - Name: %s\n", v8->m_iName.m_Value.pszValue);
          else
            _Msg(a1: " - Name: No Targetname\n");
          if ( v8->m_iParent.pszValue != nullptr )
            _Msg(a1: "Parent: %s\n", v8->m_iParent.pszValue);
          v10 = *(const char **)((int (__thiscall *)(CBaseEntity *, int *))v8->GetModelName)(a1: v8, a2: &iImpulse);
          if ( v10 == nullptr )
            v10 = locale;
          _Msg(a1: "Model: %s\n", v10);
          v11 = v8->m_iGlobalname.pszValue;
          if ( v11 != nullptr )
            _Msg(a1: "Globalname: %s\n", v11);
        }
        break;
      case 107:
        this->EyePosition(this, result: &start);
        CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: nullptr);
        end.y = start.y + (float)(forward.y * 1024.0);
        end.x = start.x + (float)(forward.x * 1024.0);
        end.z = start.z + (float)(forward.z * 1024.0);
        UTIL_TraceLine(
          a1: &savedregs,
          a2,
          vecAbsStart: &start,
          vecAbsEnd: &end,
          mask: 0x400Bu,
          ignore: this,
          collisionGroup: 0,
          &ptr);
        if ( ptr.surface.name != nullptr )
          _Msg(a1: "Texture: %s\n", ptr.surface.name);
        break;
      case 108:
        v12 = this->FindEntityForward(this, a2: 1);
        if ( v12 != nullptr )
        {
          v13 = (int)v12->MyNPCPointer(this: v12);
          v14 = (CAI_BaseNPC *)v13;
          if ( v13 != 0 )
          {
            v15 = *(const char **)(v13 + 92);
            if ( v15 == nullptr )
              v15 = locale;
            _Msg(a1: "Debugging %s (0x%x)\n", v15, v14);
            CAI_BaseNPC::m_pDebugNPC = v14;
          }
        }
        break;
      case 195:
        CBaseEntity::Create(
          szName: "node_viewer_fly",
          vecOrigin: &this->m_vecOrigin.m_Value,
          vecAngles: &this->m_angRotation.m_Value,
          pOwner: nullptr);
        break;
      case 196:
        CBaseEntity::Create(
          szName: "node_viewer_large",
          vecOrigin: &this->m_vecOrigin.m_Value,
          vecAngles: &this->m_angRotation.m_Value,
          pOwner: nullptr);
        break;
      case 197:
        CBaseEntity::Create(
          szName: "node_viewer_human",
          vecOrigin: &this->m_vecOrigin.m_Value,
          vecAngles: &this->m_angRotation.m_Value,
          pOwner: nullptr);
        break;
      case 202:
        CBasePlayer::EyeVectors(this, pForward: &end, pRight: nullptr, pUp: nullptr);
        EyePosition = this->EyePosition;
        start.x = end.x * 128.0;
        start.y = end.y * 128.0;
        start.z = end.z * 128.0;
        v17 = (float *)((int (__thiscall *)(CBasePlayer *, _BYTE *, int))EyePosition)(a1: this, a2: v25, a3: a2);
        v18 = this->EyePosition;
        forward.x = start.x + *v17;
        forward.y = v17[1] + start.y;
        forward.z = v17[2] + start.z;
        v19 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v18)(a1: this);
        UTIL_TraceLine(
          a1: &savedregs,
          a2,
          vecAbsStart: v19,
          &vecAbsEnd,
          mask: (unsigned int)&forward,
          ignore: (const IHandleEntity *)0x400B,
          collisionGroup: (int)this,
          ptr: nullptr);
        if ( tr_44 != 1.0 )
        {
          Entity = _CreateEntityTemplate<CBloodSplat>(newEnt: nullptr, className: "bloodsplat");
          CBloodSplat::Spawn(this: Entity, pOwner: this);
        }
        break;
      case 203:
        v21 = this->FindEntityForward(this, a2: 1);
        if ( v21 != nullptr )
          UTIL_Remove(oldObj: v21);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC900
// Name: public: virtual bool CBasePlayer::ClientCommand(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePlayer::ClientCommand(CBasePlayer *this, const CCommand *args)
{
  const char *v4; // ebx
  const char *v5; // edi
  int v6; // ebx
  IServerVehicle *v7; // edi
  ConVar *m_pParent; // eax
  const char *v10; // edi
  int v11; // eax
  int v12; // edi
  int v13; // eax
  CBasePlayer_vtbl *v14; // edx
  CBasePlayer *v15; // ecx
  CBaseEntity *v16; // eax
  int v17; // eax
  int v18; // eax
  CBasePlayer *v19; // eax
  CBaseEntity *v20; // edi
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // edi
  void (__thiscall *JumptoPosition)(CBasePlayer *, const Vector *, const QAngle *); // edx
  const char *v26; // eax
  int v27; // eax
  int v28; // ebx
  const char *v29; // eax
  CBasePlayer *v30; // eax
  Vector origin; // [esp+Ch] [ebp-18h] BYREF
  float v32; // [esp+18h] [ebp-Ch] BYREF
  ConVarRef mp_allowspectators; // [esp+1Ch] [ebp-8h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF
  int nRecip; // [esp+2Ch] [ebp+8h]

  v4 = locale;
  if ( args->m_nArgc > 0 )
    v4 = args->m_ppArgv[0];
  if ( _V_stricmp(s1: v4, s2: "vehicleRole") == 0 )
  {
    if ( args->m_nArgc == 2 )
    {
      if ( this->IsInAVehicle(this) )
      {
        if ( args->m_nArgc > 1 )
          v5 = args->m_ppArgv[1];
        else
          v5 = locale;
        v6 = atoi(nptr: v5);
        v7 = this->GetVehicle(this);
        if ( v7 != nullptr && v7->GetPassenger(this: v7, a2: v6) == 0 )
        {
          this->LeaveVehicle(this, a2: &vec3_origin, a3: &vec3_angle);
          this->GetInVehicle(this, a2: v7, a3: v6);
        }
      }
      return 1;
    }
    return 0;
  }
  if ( _V_stricmp(s1: v4, s2: "spectate") == 0 )
  {
    if ( CBaseEntity::GetTeamNumber(this) != 1 )
    {
      ConVarRef::ConVarRef(this: &mp_allowspectators, pName: "mp_allowspectators");
      if ( !ConVarRef::IsValid(this: &mp_allowspectators)
        || mp_allowspectators.m_pConVarState->m_Value.m_nValue != 0
        || this->pl.hltv )
      {
        if ( this->m_lifeState.m_Value != 2 )
          this->CommitSuicide(this, a2: false, a3: false);
        this->RemoveAllItems(this, a2: true);
        this->ChangeTeam(this, a2: 1);
        this->StartObserverMode(this, a2: 6);
        return 1;
      }
      else
      {
        ClientPrint(
          player: this,
          msg_dest: 4,
          msg_name: "#Cannot_Be_Spectator",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        return 1;
      }
    }
    return 1;
  }
  if ( _V_stricmp(s1: v4, s2: "spec_mode") != 0 )
  {
    if ( _V_stricmp(s1: v4, s2: "spec_next") != 0 )
    {
      if ( _V_stricmp(s1: v4, s2: "spec_prev") != 0 )
      {
        if ( _V_stricmp(s1: v4, s2: "spec_player") != 0 )
        {
          if ( _V_stricmp(s1: v4, s2: "spec_goto") != 0 )
          {
            if ( _V_stricmp(s1: v4, s2: "playerperf") != 0 )
              return 0;
            nRecip = (int)CBaseEntity::entindex(this);
            if ( args->m_nArgc >= 2 )
            {
              v26 = locale;
              if ( args->m_nArgc > 1 )
                v26 = args->m_ppArgv[1];
              v27 = V_atoi(str: v26);
              if ( v27 >= 1 )
              {
                nRecip = gpGlobals->maxClients;
                if ( v27 <= nRecip )
                  nRecip = v27;
              }
              else
              {
                nRecip = 1;
              }
            }
            v28 = -1;
            if ( args->m_nArgc >= 3 )
            {
              v29 = locale;
              if ( args->m_nArgc > 2 )
                v29 = args->m_ppArgv[2];
              if ( V_atoi(str: v29) <= 1 )
              {
                v28 = 1;
              }
              else if ( args->m_nArgc > 2 )
              {
                v28 = V_atoi(str: args->m_ppArgv[2]);
              }
              else
              {
                v28 = V_atoi(str: locale);
              }
            }
            v30 = UTIL_PlayerByIndex(playerIndex: nRecip);
            if ( v30 != nullptr )
              CBasePlayer::DumpPerfToRecipient(this: v30, a2: (int)&savedregs, pRecipient: this, nMaxRecords: v28);
            return 1;
          }
          else
          {
            if ( (this->GetObserverMode(this) == 3 || this->GetObserverMode(this) == 6) && args->m_nArgc == 6 )
            {
              origin.x = atof(nptr: args->m_ppArgv[1]);
              v21 = locale;
              if ( args->m_nArgc > 2 )
                v21 = args->m_ppArgv[2];
              origin.y = atof(nptr: v21);
              v22 = locale;
              if ( args->m_nArgc > 3 )
                v22 = args->m_ppArgv[3];
              origin.z = atof(nptr: v22);
              v23 = locale;
              if ( args->m_nArgc > 4 )
                v23 = args->m_ppArgv[4];
              v32 = atof(nptr: v23);
              if ( args->m_nArgc > 5 )
                v24 = args->m_ppArgv[5];
              else
                v24 = locale;
              *(float *)&mp_allowspectators.m_pConVar = atof(nptr: v24);
              JumptoPosition = this->JumptoPosition;
              mp_allowspectators.m_pConVarState = nullptr;
              JumptoPosition(this, a2: &origin, a3: (const QAngle *)&v32);
            }
            return 1;
          }
        }
        else
        {
          if ( this->GetObserverMode(this) > 3 && args->m_nArgc == 2 )
          {
            v18 = atoi(nptr: args->m_ppArgv[1]);
            if ( v18 != 0 )
              v19 = UTIL_PlayerByIndex(playerIndex: v18);
            else
              v19 = args->m_nArgc > 1 ? UTIL_PlayerByName(name: args->m_ppArgv[1]) : UTIL_PlayerByName(name: locale);
            v20 = v19;
            if ( this->IsValidObserverTarget(this, a2: v19) )
              this->SetObserverTarget(this, a2: v20);
          }
          return 1;
        }
      }
      v17 = this->GetObserverMode(this);
      v14 = this->__vftable;
      v15 = this;
      if ( v17 > 3 )
      {
        v16 = (CBaseEntity *)((int (__stdcall *)(int))v14->FindNextObserverTarget)(a1: 1);
LABEL_51:
        if ( v16 != nullptr )
        {
          this->SetObserverTarget(this, a2: v16);
          return 1;
        }
        return 1;
      }
    }
    else
    {
      v13 = this->GetObserverMode(this);
      v14 = this->__vftable;
      v15 = this;
      if ( v13 > 3 )
      {
        v16 = (CBaseEntity *)((int (__stdcall *)(_DWORD))v14->FindNextObserverTarget)(a1: 0);
        goto LABEL_51;
      }
    }
    if ( v14->GetObserverMode(this: v15) != 2 )
      return 1;
LABEL_54:
    this->AttemptToExitFreezeCam(this);
    return 1;
  }
  if ( this->GetObserverMode(this) == 2 )
    goto LABEL_54;
  m_pParent = mp_fadetoblack.m_pParent;
  if ( mp_fadetoblack.m_pParent != nullptr )
  {
    if ( mp_fadetoblack.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( CBaseEntity::GetTeamNumber(this) > 1 )
        return 1;
      m_pParent = mp_fadetoblack.m_pParent;
    }
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 && CBaseEntity::GetTeamNumber(this) > 1 )
      return 1;
  }
  if ( args->m_nArgc < 2 )
  {
    v12 = this->GetObserverMode(this) + 1;
    if ( v12 <= 6 )
    {
      if ( v12 < 4 )
        v12 = 6;
    }
    else
    {
      v12 = 4;
    }
  }
  else
  {
    if ( args->m_nArgc > 1 )
      v10 = args->m_ppArgv[1];
    else
      v10 = locale;
    v11 = atoi(nptr: v10);
    v12 = v11;
    if ( v11 < 4 || v11 > 6 )
      v12 = 4;
  }
  if ( this->GetObserverMode(this) <= 1 )
  {
    this->m_iObserverLastMode = v12;
    engine->ClientCommand(this: engine, a2: this->m_Network.m_pPev, a3: "cl_spec_mode %d", v12);
  }
  else
  {
    if ( !this->SetObserverMode(this, a2: v12) )
    {
      ClientPrint(
        player: this,
        msg_dest: 2,
        msg_name: "#Spectator_Mode_Unkown",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      return 1;
    }
    engine->ClientCommand(this: engine, a2: this->m_Network.m_pPev, a3: "cl_spec_mode %d", v12);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101BCEB0
// Name: public: void CBasePlayer::SetPunchAngle(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetPunchAngle(CBasePlayer *this, const QAngle *punchAngle)
{
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *p_m_vecPunchAngle; // esi
  edict_t *m_pPev; // eax
  int i; // edi
  CBasePlayer *v7; // esi
  const QAngle *punchAnglea; // [esp+10h] [ebp+8h]

  p_m_vecPunchAngle = &this->m_Local.m_vecPunchAngle;
  if ( punchAngle->x != this->m_Local.m_vecPunchAngle.m_Value.x
    || punchAngle->y != this->m_Local.m_vecPunchAngle.m_Value.y
    || punchAngle->z != this->m_Local.m_vecPunchAngle.m_Value.z )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: p_m_vecPunchAngle);
    p_m_vecPunchAngle->m_Value = *punchAngle;
  }
  if ( this->IsAlive(this) )
  {
    m_pPev = this->m_Network.m_pPev;
    punchAnglea = m_pPev != nullptr ? (const QAngle *)(m_pPev - gpGlobals->pEdicts) : nullptr;
    for ( i = 1; i <= gpGlobals->maxClients; ++i )
    {
      v7 = UTIL_PlayerByIndex(playerIndex: i);
      if ( v7 != nullptr
        && (const QAngle *)i != punchAnglea
        && v7->GetObserverTarget(this: v7) == this
        && v7->GetObserverMode(this: v7) == 4 )
      {
        CBasePlayer::SetPunchAngle(this: v7, punchAngle);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BCFA0
// Name: public: void CBasePlayer::InitFogController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::InitFogController(CBasePlayer *this)
{
  unsigned int m_Index; // eax

  m_Index = FogSystem()->m_hMasterController.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl>::Set(
      this: &this->m_PlayerFog.m_hCtrl,
      val: nullptr);
  else
    CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl>::Set(
      this: &this->m_PlayerFog.m_hCtrl,
      val: (const CFogController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x101BCFF0
// Name: mp_disable_autokick
// Source: json
//------------------------------------------------------------------------------
void __cdecl mp_disable_autokick(const CCommand *args)
{
  DisableAutokick disable; // [esp+0h] [ebp-4h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( args->m_nArgc == 2 )
    {
      disable.m_userID = atoi(nptr: args->m_ppArgv[1]);
      ForEachPlayer<DisableAutokick>(func: &disable);
    }
    else
    {
      _Msg(a1: "Usage: mp_disable_autokick <userid>\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BD040
// Name: public: void CBasePlayer::UpdateFXVolume(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdateFXVolume(CBasePlayer *this)
{
  CBasePlayer *v1; // ebx
  unsigned int m_Index; // eax
  CBaseEntity **v3; // ecx
  CBaseEntity *v4; // esi
  float z; // xmm0_4
  int v6; // eax
  CFogVolume *FogVolumeForPosition; // eax
  unsigned int v8; // ecx
  CBaseEntityList *v9; // esi
  const CFogController *m_pEntity; // edi
  unsigned int v11; // ecx
  CPostProcessController *v12; // ebx
  unsigned int v13; // eax
  unsigned int v14; // eax
  IHandleEntity *v15; // ecx
  unsigned int v16; // eax
  CPostProcessController *v17; // ecx
  unsigned int v18; // eax
  CColorCorrection *v19; // ecx
  unsigned int v20; // eax
  const CFogController *v21; // edx
  unsigned int v22; // eax
  IHandleEntity *v23; // eax
  unsigned int v24; // eax
  CPostProcessController *v25; // eax
  unsigned int v26; // eax
  Vector v27; // [esp+Ch] [ebp-28h] BYREF
  Vector eyePos; // [esp+18h] [ebp-1Ch] BYREF
  CBasePlayer *v29; // [esp+24h] [ebp-10h]
  CColorCorrection *pColorCorrectionEnt; // [esp+28h] [ebp-Ch]
  CPostProcessController *pPostProcessController; // [esp+2Ch] [ebp-8h]
  CColorCorrection *v32; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  v1 = this;
  m_Index = this->m_hViewEntity.m_Value.m_Index;
  v29 = this;
  if ( m_Index != -1
    && (v3 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (v4 = *v3, *v3 != nullptr) )
  {
    if ( (v4->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: *v3, a2: (int)&savedregs);
    eyePos.x = v4->m_vecAbsOrigin.x;
    eyePos.y = v4->m_vecAbsOrigin.y;
    z = v4->m_vecAbsOrigin.z;
  }
  else
  {
    v6 = (int)v1->EyePosition(this: v1, result: &v27);
    eyePos.x = *(float *)v6;
    eyePos.y = *(float *)(v6 + 4);
    z = *(float *)(v6 + 8);
  }
  eyePos.z = z;
  FogVolumeForPosition = CFogVolume::FindFogVolumeForPosition(position: &eyePos);
  if ( FogVolumeForPosition != nullptr )
  {
    v8 = FogVolumeForPosition->m_hFogController.m_Index;
    v9 = g_pEntityList;
    if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
      m_pEntity = nullptr;
    else
      m_pEntity = (const CFogController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
    v11 = FogVolumeForPosition->m_hPostProcessController.m_Index;
    if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
      v12 = nullptr;
    else
      v12 = (CPostProcessController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
    v13 = FogVolumeForPosition->m_hColorCorrectionController.m_Index;
    pPostProcessController = v12;
    if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
      v32 = nullptr;
    else
      v32 = (CColorCorrection *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    pColorCorrectionEnt = v32;
    if ( m_pEntity == nullptr )
    {
      v14 = FogSystem()->m_hMasterController.m_Index;
      v9 = g_pEntityList;
      if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
        v15 = nullptr;
      else
        v15 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
      m_pEntity = (const CFogController *)v15;
    }
    if ( v12 == nullptr )
    {
      v16 = PostProcessSystem()->m_hMasterController.m_Index;
      v9 = g_pEntityList;
      if ( v16 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16) )
        v17 = nullptr;
      else
        v17 = (CPostProcessController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity;
      pPostProcessController = v17;
    }
    if ( v32 == nullptr )
    {
      v18 = ColorCorrectionSystem()->m_hMasterController.m_Index;
      v9 = g_pEntityList;
      if ( v18 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
        v19 = nullptr;
      else
        v19 = (CColorCorrection *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
      pColorCorrectionEnt = v19;
    }
    v1 = v29;
  }
  else
  {
    if ( TheFogVolumes.m_Size <= 0 )
      return;
    v22 = FogSystem()->m_hMasterController.m_Index;
    if ( v22 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_SerialNumber != HIWORD(v22) )
      v23 = nullptr;
    else
      v23 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_pEntity;
    m_pEntity = (const CFogController *)v23;
    v24 = PostProcessSystem()->m_hMasterController.m_Index;
    if ( v24 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber != HIWORD(v24) )
      v25 = nullptr;
    else
      v25 = (CPostProcessController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_pEntity;
    pPostProcessController = v25;
    v26 = ColorCorrectionSystem()->m_hMasterController.m_Index;
    v9 = g_pEntityList;
    if ( v26 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_SerialNumber != HIWORD(v26) )
      pColorCorrectionEnt = nullptr;
    else
      pColorCorrectionEnt = (CColorCorrection *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_pEntity;
  }
  if ( m_pEntity != nullptr )
  {
    v20 = v1->m_PlayerFog.m_hCtrl.m_Value.m_Index;
    if ( v20 == -1 || v9->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20) )
      v21 = nullptr;
    else
      v21 = (const CFogController *)v9->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
    if ( v21 != m_pEntity )
      CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl>::Set(
        this: &v1->m_PlayerFog.m_hCtrl,
        val: m_pEntity);
  }
  if ( pPostProcessController != nullptr )
    CNetworkHandleBase<CPostProcessController,CBasePlayer::NetworkVar_m_hPostProcessCtrl>::Set(
      this: &v1->m_hPostProcessCtrl,
      val: pPostProcessController);
  if ( pColorCorrectionEnt != nullptr )
    CNetworkHandleBase<CColorCorrection,CBasePlayer::NetworkVar_m_hColorCorrectionCtrl>::Set(
      this: &v1->m_hColorCorrectionCtrl,
      val: pColorCorrectionEnt);
}

//------------------------------------------------------------------------------
// Address: 0x101BD940
// Name: public: virtual int CBasePlayer::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBasePlayer::OnTakeDamage@<eax>(
        CBasePlayer *this@<ecx>,
        int a2@<edi>,
        const CTakeDamageInfo *inputInfo)
{
  int m_bitsDamageType; // ebx
  __m128i v5; // xmm0
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // edi
  int v7; // eax
  float v9; // xmm0_4
  CGameRules_vtbl *v10; // edi
  CBaseEntity *Attacker; // eax
  float m_flDamage; // xmm1_4
  const Vector *AbsOrigin; // edi
  CBaseEntity *Inflictor; // eax
  const char *v15; // eax
  CNetworkVarBase<int,CBasePlayer::NetworkVar_m_ArmorValue> *p_m_ArmorValue; // edi
  int m_Value; // eax
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  CBaseEntity *v21; // eax
  int i; // edi
  int v23; // eax
  bool v24; // cc
  int v25; // edi
  bool v26; // zf
  bool v27; // sf
  bool v28; // of
  BOOL v29; // ecx
  double curtime; // st7
  IUniformRandomStream *v31; // ecx
  CBasePlayer_vtbl *v32; // edi
  CBaseEntity *v33; // eax
  double v34; // st7
  int v35; // eax
  char *v36; // [esp+4h] [ebp-1FCh]
  int v37; // [esp+8h] [ebp-1F8h]
  double x; // [esp+Ch] [ebp-1F4h]
  int v39; // [esp+10h] [ebp-1F0h]
  int v40; // [esp+14h] [ebp-1ECh]
  double y; // [esp+14h] [ebp-1ECh]
  double z; // [esp+1Ch] [ebp-1E4h]
  double v43; // [esp+24h] [ebp-1DCh]
  const char *DebugName; // [esp+2Ch] [ebp-1D4h]
  char outputString[256]; // [esp+4Ch] [ebp-1B4h] BYREF
  char dmgtype[64]; // [esp+14Ch] [ebp-B4h] BYREF
  CTakeDamageInfo info; // [esp+18Ch] [ebp-74h] BYREF
  int fTookDamage; // [esp+1E8h] [ebp-18h]
  int fcritical; // [esp+1ECh] [ebp-14h]
  int ffound; // [esp+1F0h] [ebp-10h]
  float flHealthPrev; // [esp+1F4h] [ebp-Ch]
  int ftrivial; // [esp+1F8h] [ebp-8h]
  float flNew; // [esp+1FCh] [ebp-4h]
  int fmajor; // [esp+208h] [ebp+8h]
  int fmajora; // [esp+208h] [ebp+8h]
  int fmajorb; // [esp+208h] [ebp+8h]

  m_bitsDamageType = inputInfo->m_bitsDamageType;
  v5 = _mm_cvtsi32_si128(this->m_iHealth.m_Value);
  p_m_iHealth = &this->m_iHealth;
  ffound = 1;
  LODWORD(flHealthPrev) = _mm_cvtepi32_ps(v5).m128_u32[0];
  CTakeDamageInfo::CTakeDamageInfo(this: &info, __that: inputInfo);
  v7 = ((int (__thiscall *)(CBasePlayer *, int))this->GetVehicle)(a1: this, a2);
  if ( v7 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CTakeDamageInfo *))(*(_DWORD *)v7 + 48))(a1: v7, a2: &info) == 0
    || IsInCommentaryMode() && !CBasePlayer::ShouldTakeDamageInCommentaryMode(this, inputInfo: &info)
    || (this->m_fFlags.m_Value & 0x8000) != 0 )
  {
    return 0;
  }
  if ( (this->m_debugOverlays & 0x2000000) != 0 && (float)((float)p_m_iHealth->m_Value - info.m_flDamage) <= 0.0 )
  {
    if ( p_m_iHealth->m_Value != 1 )
    {
      (*(void (__thiscall **)(CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *))(p_m_iHealth[-132].m_Value + 732))(a1: p_m_iHealth - 132);
      p_m_iHealth->m_Value = 1;
    }
    return 0;
  }
  if ( info.m_flDamage == 0.0 )
    return 0;
  if ( old_armor.m_pParent != nullptr && old_armor.m_pParent->m_Value.m_nValue != 0 )
    v9 = 0.5;
  else
    v9 = 1.0;
  *(float *)&fmajor = v9;
  if ( (info.m_bitsDamageType & 0x40) != 0 && g_pGameRules->IsMultiplayer(this: g_pGameRules) )
    *(float *)&fmajor = v9 * 2.0;
  if ( !this->IsAlive(this) )
    return 0;
  v10 = g_pGameRules->__vftable;
  Attacker = CTakeDamageInfo::GetAttacker(this: &info);
  if ( !v10->FPlayerCanTakeDamage(this: g_pGameRules, a2: this, a3: Attacker) )
    return 0;
  if ( player_debug_print_damage.m_pParent == nullptr || player_debug_print_damage.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_25;
  m_flDamage = info.m_flDamage;
  if ( info.m_flDamage > 0.0 )
  {
    CTakeDamageInfo::DebugGetDamageTypeString(damageType: info.m_bitsDamageType, outbuf: dmgtype, outbuflength: 512);
    ftrivial = SLODWORD(info.m_flDamage);
    AbsOrigin = CBaseEntity::GetAbsOrigin(this);
    Inflictor = CTakeDamageInfo::GetInflictor(this: &info);
    DebugName = CBaseEntity::GetDebugName(this: Inflictor);
    v43 = *(float *)&ftrivial;
    z = CBaseEntity::GetAbsOrigin(this)->z;
    y = CBaseEntity::GetAbsOrigin(this)->y;
    x = AbsOrigin->x;
    v15 = CBaseEntity::GetDebugName(this);
    V_snprintf(
      pDest: outputString,
      maxLen: 256,
      pFormat: "%f: Player %s at [%0.2f %0.2f %0.2f] took %f damage from %s, type %s\n",
      gpGlobals->curtime,
      v15,
      x,
      y,
      z,
      v43,
      DebugName,
      dmgtype);
    _Msg(a1: outputString);
LABEL_25:
    m_flDamage = info.m_flDamage;
  }
  p_m_ArmorValue = &this->m_ArmorValue;
  this->m_lastDamageAmount = (int)m_flDamage;
  m_Value = this->m_ArmorValue.m_Value;
  if ( m_Value != 0 && (info.m_bitsDamageType & 0x64020) == 0 )
  {
    v18 = m_flDamage * 0.2;
    flNew = m_flDamage * 0.2;
    v19 = (float)(m_flDamage - (float)(m_flDamage * 0.2)) * *(float *)&fmajor;
    if ( (old_armor.m_pParent == nullptr || old_armor.m_pParent->m_Value.m_nValue == 0) && v19 < 1.0 )
      v19 = 1.0;
    v20 = (float)m_Value;
    if ( v19 <= (float)m_Value )
    {
      this->m_DmgSave = v19;
      fmajora = m_Value - (int)v19;
      if ( m_Value == fmajora )
      {
LABEL_37:
        info.m_flDamage = v18;
        goto LABEL_38;
      }
      this->NetworkStateChanged_m_ArmorValue(this, a2: &this->m_ArmorValue);
      p_m_ArmorValue->m_Value = fmajora;
    }
    else
    {
      flNew = m_flDamage - (float)((float)(1.0 / *(float *)&fmajor) * v20);
      this->m_DmgSave = v20;
      this->NetworkStateChanged_m_ArmorValue(this, a2: &this->m_ArmorValue);
      p_m_ArmorValue->m_Value = 0;
    }
    v18 = flNew;
    goto LABEL_37;
  }
LABEL_38:
  fTookDamage = CBaseCombatCharacter::OnTakeDamage(this, a2: (int)p_m_ArmorValue, &info);
  if ( fTookDamage == 0 )
    return 0;
  if ( CTakeDamageInfo::GetInflictor(this: &info) != nullptr
    && CTakeDamageInfo::GetInflictor(this: &info)->m_Network.m_pPev != nullptr )
  {
    v21 = CTakeDamageInfo::GetInflictor(this: &info);
    this->m_DmgOrigin = *CBaseEntity::GetAbsOrigin(this: v21);
  }
  this->m_DmgTake = (float)(int)info.m_flDamage + this->m_DmgTake;
  for ( i = 0; i < 8; ++i )
  {
    if ( ((0x8000 << i) & info.m_bitsDamageType) != 0
      && g_pGameRules->Damage_IsTimeBased(this: g_pGameRules, a2: 0x8000 << i) )
    {
      this->m_rgbTimeBasedDamage[i] = 0;
    }
  }
  ((void (__thiscall *)(CBasePlayer *, _DWORD, int))this->DamageEffect)(
    a1: this,
    a2: LODWORD(info.m_flDamage),
    a3: m_bitsDamageType);
  v23 = this->m_iHealth.m_Value;
  if ( v23 > 75 || (v24 = this->m_lastDamageAmount < 5, *(float *)&ftrivial = 0.0, v24) )
    ftrivial = 1;
  v25 = ffound;
  v28 = __OFSUB__(this->m_lastDamageAmount, 25);
  v26 = this->m_lastDamageAmount == 25;
  v27 = this->m_lastDamageAmount - 25 < 0;
  this->m_bitsHUDDamage = -1;
  v29 = !(v27 ^ v28 | v26);
  this->m_bitsDamageType |= m_bitsDamageType;
  fmajorb = v29;
  fcritical = v23 < 30;
  while ( (*(float *)&ftrivial == 0.0 || g_pGameRules->Damage_IsTimeBased(this: g_pGameRules, a2: m_bitsDamageType))
       && v25 != 0
       && m_bitsDamageType != 0 )
  {
    v25 = 0;
    if ( (m_bitsDamageType & 0x80u) != 0 )
    {
      if ( fmajorb != 0 )
        CBasePlayer::SetSuitUpdate(this, name: "!HEV_DMG4", fgroup: 0, iNoRepeatTime: 30);
      m_bitsDamageType &= ~0x80u;
      v25 = 1;
    }
    if ( (m_bitsDamageType & 0x21) != 0 )
    {
      if ( fmajorb != 0 )
        CBasePlayer::SetSuitUpdate(this, name: "!HEV_DMG5", fgroup: 0, iNoRepeatTime: 30);
      else
        CBasePlayer::SetSuitUpdate(this, name: "!HEV_DMG4", fgroup: 0, iNoRepeatTime: 30);
      m_bitsDamageType &= 0xFFFFFFDE;
      v25 = 1;
    }
    if ( (m_bitsDamageType & 2) != 0 )
    {
      if ( this->m_lastDamageAmount > 5 )
        CBasePlayer::SetSuitUpdate(this, name: "!HEV_DMG6", fgroup: 0, iNoRepeatTime: 30);
      m_bitsDamageType &= ~2u;
      v25 = 1;
    }
    if ( (m_bitsDamageType & 4) != 0 )
    {
      if ( fmajorb != 0 )
        CBasePlayer::SetSuitUpdate(this, name: "!HEV_DMG1", fgroup: 0, iNoRepeatTime: 30);
      else
        CBasePlayer::SetSuitUpdate(this, name: "!HEV_DMG0", fgroup: 0, iNoRepeatTime: 30);
      m_bitsDamageType &= ~4u;
      v25 = 1;
    }
    if ( (m_bitsDamageType & 0x200) != 0 )
    {
      if ( fmajorb != 0 )
        CBasePlayer::SetSuitUpdate(this, name: "!HEV_DMG2", fgroup: 0, iNoRepeatTime: 60);
      m_bitsDamageType &= ~0x200u;
      v25 = 1;
    }
    if ( (m_bitsDamageType & 0x28000) != 0 )
    {
      if ( (m_bitsDamageType & 0x20000) != 0 )
      {
        this->m_nPoisonDmg = (int)(float)((float)this->m_nPoisonDmg + info.m_flDamage);
        curtime = gpGlobals->curtime;
        this->m_rgbTimeBasedDamage[2] = 0;
        this->m_tbdPrev = curtime;
      }
      CBasePlayer::SetSuitUpdate(this, name: "!HEV_DMG3", fgroup: 0, iNoRepeatTime: 60);
      m_bitsDamageType &= 0xFFFD7FFF;
      v25 = 1;
    }
    if ( (m_bitsDamageType & 0x100000) != 0 )
    {
      CBasePlayer::SetSuitUpdate(this, name: "!HEV_DET1", fgroup: 0, iNoRepeatTime: 60);
      m_bitsDamageType &= ~0x100000u;
      v25 = 1;
    }
    if ( (m_bitsDamageType & 0x10000) != 0 )
    {
      CBasePlayer::SetSuitUpdate(this, name: "!HEV_DET0", fgroup: 0, iNoRepeatTime: 60);
      m_bitsDamageType &= ~0x10000u;
      v25 = 1;
    }
    if ( (m_bitsDamageType & 0x40000) != 0 )
    {
      CBasePlayer::SetSuitUpdate(this, name: "!HEV_DET2", fgroup: 0, iNoRepeatTime: 60);
      m_bitsDamageType &= ~0x40000u;
      v25 = 1;
    }
    if ( (m_bitsDamageType & 0x100) != 0 )
    {
      m_bitsDamageType &= ~0x100u;
      v25 = 1;
    }
  }
  flNew = _RandomFloat(this: (IUniformRandomStream *)v29, a2: -2.0, a3: -3.5);
  if ( hl2_episodic.m_pParent != nullptr
    && hl2_episodic.m_pParent->m_Value.m_nValue != 0
    && CTakeDamageInfo::GetAttacker(this: &info) != nullptr )
  {
    v32 = this->__vftable;
    v33 = CTakeDamageInfo::GetAttacker(this: &info);
    if ( !v32->FInViewCone(this, a2: v33) )
    {
      if ( info.m_flDamage <= 10.0 )
        flNew = _RandomFloat(this: v31, a2: -5.0, a3: -7.0);
      else
        flNew = -10.0;
    }
  }
  if ( this->m_Local.m_vecPunchAngle.m_Value.x != flNew )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_vecPunchAngle);
    this->m_Local.m_vecPunchAngle.m_Value.x = flNew;
  }
  v34 = _RandomFloat(this: v31, a2: 1.0, a3: -1.0);
  *(float *)&ffound = v34;
  if ( this->m_Local.m_vecPunchAngle.m_Value.y != v34 )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_vecPunchAngle);
    this->m_Local.m_vecPunchAngle.m_Value.y = *(float *)&ffound;
  }
  if ( *(float *)&ftrivial == 0.0 )
  {
    if ( fmajorb != 0 && flHealthPrev >= 75.0 )
    {
      CBasePlayer::SetSuitUpdate(this, name: "!HEV_MED1", fgroup: 0, iNoRepeatTime: 1800);
      CBasePlayer::SetSuitUpdate(this, name: "!HEV_HEAL7", fgroup: 0, iNoRepeatTime: 1800);
    }
    if ( fcritical != 0 && flHealthPrev < 75.0 )
    {
      v35 = this->m_iHealth.m_Value;
      if ( v35 >= 6 )
      {
        if ( v35 < 20 )
          CBasePlayer::SetSuitUpdate(this, name: "!HEV_HLTH2", fgroup: 0, iNoRepeatTime: 600);
      }
      else
      {
        CBasePlayer::SetSuitUpdate(this, name: "!HEV_HLTH3", fgroup: 0, iNoRepeatTime: 600);
      }
      if ( random->RandomInt(this: random, a2: 0, a3: 3) == 0 && flHealthPrev < 50.0 )
        CBasePlayer::SetSuitUpdate(this, name: "!HEV_DMG7", fgroup: 0, iNoRepeatTime: 300);
    }
  }
  if ( g_pGameRules->Damage_IsTimeBased(this: g_pGameRules, a2: info.m_bitsDamageType) && flHealthPrev < 75.0 )
  {
    if ( flHealthPrev >= 50.0 )
    {
      v40 = 600;
      v39 = 0;
      CBasePlayer::SetSuitUpdate(this, name: v36, fgroup: v37, iNoRepeatTime: (int)"!HEV_HLTH1");
    }
    else if ( random->RandomInt(this: random, a2: 0, a3: 3) == 0 )
    {
      CBasePlayer::SetSuitUpdate(this, name: "!HEV_DMG7", fgroup: 0, iNoRepeatTime: 300);
    }
  }
  if ( (m_bitsDamageType & 0x40) != 0 )
    ((void (__thiscall *)(CBasePlayer *, CTakeDamageInfo *, int, int))this->OnDamagedByExplosion)(
      a1: this,
      a2: &info,
      a3: v39,
      a4: v40);
  if ( this->m_iHealth.m_Value < 100 )
    this->m_fTimeLastHurt = gpGlobals->curtime;
  return fTookDamage;
}

//------------------------------------------------------------------------------
// Address: 0x101BE200
// Name: public: virtual void CBasePlayer::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Event_Killed(CBasePlayer *this, const CTakeDamageInfo *info)
{
  CHintSystem *v3; // eax
  int v4; // eax
  CSound *v5; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // edi
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBasePlayer_vtbl *v8; // edi
  const CViewVectors *v9; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  CGlobalVars *v11; // ebx
  edict_t *m_pPev; // ecx

  if ( this->Hints(this) != nullptr )
  {
    v3 = this->Hints(this);
    CHintSystem::ResetHintTimers(this: v3);
  }
  g_pGameRules->PlayerKilled(this: g_pGameRules, a2: this, a3: info);
  gamestats->Event_PlayerKilled(this: gamestats, a2: this, a3: info);
  this->RumbleEffect(this, a2: 0, a3: 0, a4: 0);
  this->ForceDropOfCarriedPhysObjects(this, a2: nullptr);
  v4 = CSoundEnt::ClientSoundIndex(pClient: this->m_Network.m_pPev);
  v5 = CSoundEnt::SoundPointerForIndex(iIndex: v4);
  if ( v5 != nullptr )
    CSound::Reset(this: v5);
  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value < -99 && p_m_iHealth->m_Value != 0 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    p_m_iHealth->m_Value = 0;
  }
  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    ActiveWeapon->Holster(this: ActiveWeapon, a2: nullptr);
  }
  this->SetAnimation(this, a2: PLAYER_DIE);
  v8 = this->__vftable;
  v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v8->SetViewOffset(this, a2: &v9->m_vDeadViewHeight);
  if ( this->m_lifeState.m_Value != 1 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    this->m_lifeState.m_Value = 1;
  }
  if ( !this->pl.deadflag.m_Value )
  {
    this->pl.NetworkStateChanged(this: &this->pl, a2: &this->pl.deadflag);
    this->pl.deadflag.m_Value = true;
  }
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->RecheckContactPoints(this: m_pPhysicsObject, a2: false);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::SetGroundEntity(this, ground: nullptr);
  if ( this->m_Local.m_bWearingSuit.m_Value && !g_pGameRules->IsMultiplayer(this: g_pGameRules) )
  {
    this->m_rgSuitPlayList[0] = 0;
    this->m_rgSuitPlayList[1] = 0;
    this->m_rgSuitPlayList[2] = 0;
    this->m_rgSuitPlayList[3] = 0;
  }
  CBasePlayer::SetFOV(this, pRequester: this, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
  if ( this->FlashlightIsOn(this) != 0 )
    this->FlashlightTurnOff(this, a2: false);
  v11 = gpGlobals;
  if ( this->m_flDeathTime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC3Cu);
    }
    this->m_flDeathTime.m_Value = v11->curtime;
  }
  this->ClearLastKnownArea(this);
  CBaseCombatCharacter::Event_Killed(this, info);
}

//------------------------------------------------------------------------------
// Address: 0x101BE440
// Name: public: virtual void CBasePlayer::SetAnimation(enum PLAYER_ANIM)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CBasePlayer::SetAnimation(CBasePlayer *this@<ecx>, int a2@<ebp>, PLAYER_ANIM playerAnim)
{
  int m_Value; // eax
  __int128 v5; // xmm0
  Activity m_Activity; // eax
  int v7; // eax
  int v8; // edi
  edict_t *m_pPev; // ecx
  edict_t *v10; // ecx
  char v11[12]; // [esp+14h] [ebp-5Ch] BYREF
  __int128 szAnim_52; // [esp+54h] [ebp-1Ch] OVERLAPPED
  _DWORD v13[3]; // [esp+64h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  v13[0] = a2;
  v13[1] = retaddr;
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v13);
  m_Value = this->m_fFlags.m_Value;
  v5 = 0;
  *(float *)&v5 = fsqrt(
                    (float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                  + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y));
  szAnim_52 = v5;
  if ( (m_Value & 0xC0) != 0 )
  {
    LODWORD(v5) = 0;
LABEL_27:
    if ( (m_Value & 1) != 0 || (m_Activity = this->m_Activity) != ACT_HOP && m_Activity != ACT_LEAP )
    {
      if ( this->m_nWaterLevel.m_Value > 1u )
      {
        if ( *(float *)&v5 == 0.0 )
          m_Activity = ACT_HOVER;
        else
          m_Activity = ACT_SWIM;
LABEL_7:
        if ( this->m_Activity != m_Activity )
        {
          this->m_Activity = m_Activity;
          v7 = CBaseAnimating::SelectWeightedSequence(this, activity: m_Activity);
          if ( this->m_nSequence.m_Value != v7 )
          {
            CBaseAnimating::ResetSequence(this, nSequence: v7);
            CBaseAnimating::SetCycle(this, flCycle: 0.0);
          }
        }
        return;
      }
      goto LABEL_47;
    }
    goto LABEL_16;
  }
  if ( playerAnim == PLAYER_JUMP )
  {
    m_Activity = ACT_HOP;
    goto LABEL_7;
  }
  if ( playerAnim == PLAYER_SUPERJUMP )
  {
    m_Activity = ACT_LEAP;
    goto LABEL_7;
  }
  if ( playerAnim != PLAYER_DIE )
  {
    if ( playerAnim == PLAYER_ATTACK1 )
    {
      m_Activity = this->m_Activity;
      if ( m_Activity != ACT_HOVER
        && m_Activity != ACT_SWIM
        && m_Activity != ACT_HOP
        && m_Activity != ACT_LEAP
        && m_Activity != ACT_DIESIMPLE )
      {
LABEL_17:
        if ( (this->m_fFlags.m_Value & 2) != 0 )
          V_strncpy(pDest: v11, pSrc: "crouch_shoot_", maxLen: 64);
        else
          V_strncpy(pDest: v11, pSrc: "ref_shoot_", maxLen: 64);
        V_strncat(pDest: v11, pSrc: this->m_szAnimExtension, destBufferSize: 0x40u, max_chars_to_copy: -1);
        v8 = CBaseAnimating::LookupSequence(this, label: v11);
        if ( v8 == -1 )
          v8 = 0;
        if ( (this->m_nSequence.m_Value != v8 || !this->m_bSequenceLoops) && this->m_flCycle.m_Value != 0.0 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
          }
          this->m_flCycle.m_Value = 0.0;
        }
        this->m_Activity = ACT_RANGE_ATTACK1;
        CBaseAnimating::ResetSequence(this, nSequence: v8);
        goto LABEL_56;
      }
      goto LABEL_16;
    }
    if ( (unsigned int)playerAnim > PLAYER_WALK )
      goto LABEL_47;
    goto LABEL_27;
  }
  if ( this->m_lifeState.m_Value == 0 )
  {
    m_Activity = this->GetDeathActivity(this);
LABEL_16:
    if ( m_Activity == ACT_RANGE_ATTACK1 )
      goto LABEL_17;
    if ( m_Activity != ACT_WALK )
      goto LABEL_7;
  }
LABEL_47:
  if ( this->m_Activity != ACT_RANGE_ATTACK1 || this->IsActivityFinished(this) )
  {
    if ( (this->m_fFlags.m_Value & 2) != 0 )
      V_strncpy(pDest: v11, pSrc: "crouch_aim_", maxLen: 64);
    else
      V_strncpy(pDest: v11, pSrc: "ref_aim_", maxLen: 64);
    V_strncat(pDest: v11, pSrc: this->m_szAnimExtension, destBufferSize: 0x40u, max_chars_to_copy: -1);
    v8 = CBaseAnimating::LookupSequence(this, label: v11);
    if ( v8 == -1 )
      v8 = 0;
    this->m_Activity = ACT_WALK;
  }
  else
  {
    v8 = this->m_nSequence.m_Value;
  }
LABEL_56:
  if ( this->m_nSequence.m_Value != v8 )
  {
    CBaseAnimating::ResetSequence(this, nSequence: v8);
    if ( this->m_flCycle.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x3ACu);
      }
      this->m_flCycle.m_Value = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BE760
// Name: public: virtual void CBasePlayer::PlayerDeathThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayer::PlayerDeathThink(CBasePlayer *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  __int128 v5; // xmm0
  float z; // eax
  int v7; // edi
  float v8; // xmm0_4
  edict_t *m_pPev; // ecx
  edict_t *v10; // ecx
  float v11; // eax
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_lifeState> *p_m_lifeState; // edi
  int v13; // [esp+10h] [ebp-3Ch]
  int v14; // [esp+14h] [ebp-38h]
  __int128 v15; // [esp+20h] [ebp-2Ch] BYREF
  Vector vecNewVelocity; // [esp+30h] [ebp-1Ch]
  float v17; // [esp+3Ch] [ebp-10h]
  _DWORD v18[2]; // [esp+40h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+4Ch] [ebp+0h]

  v18[0] = a2;
  v18[1] = retaddr;
  v14 = a4;
  v13 = a3;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  if ( (this->m_fFlags.m_Value & 1) != 0 )
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v18);
    v5 = 0;
    *(float *)&v5 = fsqrt(
                      (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                            + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
                    + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z));
    v15 = v5;
    v17 = *(float *)&v5 - 20.0;
    if ( (float)(*(float *)&v5 - 20.0) > 0.0 )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v18);
      z = this->m_vecAbsVelocity.z;
      *(_QWORD *)((char *)&v15 + 4) = *(_QWORD *)&this->m_vecAbsVelocity.x;
      *((float *)&v15 + 3) = z;
      VectorNormalize(vec: (Vector *)((char *)&v15 + 4));
      *((float *)&v15 + 1) = *((float *)&v15 + 1) * v17;
      *((float *)&v15 + 2) = *((float *)&v15 + 2) * v17;
      *((float *)&v15 + 3) = *((float *)&v15 + 3) * v17;
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: (const Vector *)((char *)&v15 + 4));
    }
    else
    {
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    }
  }
  v7 = 0;
  while ( CBaseCombatCharacter::GetWeapon(this, i: v7) == nullptr )
  {
    if ( ++v7 >= 64 )
      goto LABEL_14;
  }
  ((void (__thiscall *)(CBasePlayer *, int, int))this->PackDeadPlayerItems)(a1: this, a2: v13, a3: v14);
LABEL_14:
  if ( ((int (__thiscall *)(CBasePlayer *, int, int))this->GetModelIndex)(a1: this, a2: v13, a3: v14) == 0
    || this->m_bSequenceFinished
    || this->m_lifeState.m_Value != 1
    || (this->StudioFrameAdvance(this), v8 = this->m_iRespawnFrames + 1.0, this->m_iRespawnFrames = v8, v8 >= 60.0) )
  {
    if ( this->m_lifeState.m_Value == 1 )
    {
      if ( this->m_lifeState.m_Value != 2 )
      {
        this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
        this->m_lifeState.m_Value = 2;
      }
      this->m_flDeathAnimTime = gpGlobals->curtime;
    }
    if ( this->m_flPlaybackRate.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
      }
      this->m_flPlaybackRate.m_Value = 0.0;
    }
    CBaseEntity::AddEffects(this, nEffects: 8);
    if ( this->m_flPlaybackRate.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x37Cu);
      }
      this->m_flPlaybackRate.m_Value = 0.0;
    }
    LODWORD(v11) = this->m_nButtons & 0xFFFEFFFF;
    v17 = v11;
    if ( (LOBYTE(v11) & 4) != 0 && this->m_bDuckToggled )
    {
      LODWORD(v11) &= ~4u;
      v17 = v11;
    }
    p_m_lifeState = &this->m_lifeState;
    if ( this->m_lifeState.m_Value == 2 )
    {
      if ( v11 == 0.0 && g_pGameRules->FPlayerCanRespawn(this: g_pGameRules, a2: this) && p_m_lifeState->m_Value != 3 )
      {
        this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
        p_m_lifeState->m_Value = 3;
      }
    }
    else
    {
      if ( g_pGameRules->IsMultiplayer(this: g_pGameRules)
        && gpGlobals->curtime > (float)(this->m_flDeathTime.m_Value + 3.0)
        && (this->m_afPhysicsFlags.m_Value & 8) == 0 )
      {
        this->StartObserverMode(this, a2: this->m_iObserverLastMode);
      }
      if ( v17 != 0.0
        || g_pGameRules->IsMultiplayer(this: g_pGameRules)
        && forcerespawn.m_pParent != nullptr
        && forcerespawn.m_pParent->m_Value.m_nValue > 0
        && gpGlobals->curtime > (float)(this->m_flDeathTime.m_Value + 5.0) )
      {
        LOBYTE(vecNewVelocity.z) = (this->m_afPhysicsFlags.m_Value & 8) == 0;
        LODWORD(vecNewVelocity.y) = this;
        this->m_nButtons = 0;
        this->m_iRespawnFrames = 0.0;
        respawn(pEdict: (CBaseEntity *)LODWORD(vecNewVelocity.y), fCopyCorpse: SLOBYTE(vecNewVelocity.z));
        CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BEB40
// Name: public: virtual void CBasePlayer::StopObserverMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::StopObserverMode(CBasePlayer *this)
{
  unsigned int v2; // esi
  edict_t *m_pPev; // ecx
  int m_Value; // eax
  edict_t *v5; // ecx
  unsigned int m_Index; // eax
  edict_t *v7; // ecx

  this->m_bForcedObserverMode = false;
  v2 = this->m_afPhysicsFlags.m_Value & 0xFFFFFFF7;
  if ( this->m_afPhysicsFlags.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xBFCu);
    }
    this->m_afPhysicsFlags.m_Value = v2;
  }
  m_Value = this->m_iObserverMode.m_Value;
  if ( m_Value != 0 )
  {
    if ( m_Value > 1 )
      this->m_iObserverLastMode = m_Value;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0xC48u);
    }
    this->m_iObserverMode.m_Value = 0;
    m_Index = this->m_hObserverTarget.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0xC60u);
      }
      this->m_hObserverTarget.m_Value.m_Index = -1;
    }
    this->ShowViewPortPanel(this, a2: "specmenu", a3: false, a4: nullptr);
    this->ShowViewPortPanel(this, a2: "specgui", a3: false, a4: nullptr);
    this->ShowViewPortPanel(this, a2: "overview", a3: false, a4: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BEC70
// Name: public: virtual bool CBasePlayer::StartObserverMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePlayer::StartObserverMode(CBasePlayer *this, int mode)
{
  const Vector *v3; // eax
  unsigned int v4; // edi
  edict_t *m_pPev; // ecx
  CBaseCombatWeapon *ActiveWeapon; // eax
  unsigned __int8 v8; // al
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *p_m_iHideHUD; // edi
  int v10; // ebx
  int v11; // ebx
  CNetworkVarBase<bool,CPlayerState::NetworkVar_deadflag> *p_deadflag; // esi
  Vector absOrigin; // [esp+Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  CBasePlayer_vtbl *modea; // [esp+20h] [ebp+8h]

  if ( (this->m_afPhysicsFlags.m_Value & 8) == 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v3 = this->GetViewOffset(this);
    absOrigin.x = v3->x + this->m_vecAbsOrigin.x;
    absOrigin.y = v3->y + this->m_vecAbsOrigin.y;
    absOrigin.z = v3->z + this->m_vecAbsOrigin.z;
    CBaseEntity::SetAbsOrigin(this, &absOrigin);
    this->SetViewOffset(this, a2: &vec3_origin);
  }
  v4 = this->m_afPhysicsFlags.m_Value | 8;
  if ( this->m_afPhysicsFlags.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xBFCu);
    }
    this->m_afPhysicsFlags.m_Value = v4;
  }
  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    ActiveWeapon->Holster(this: ActiveWeapon, a2: nullptr);
  }
  if ( this->m_Local.m_bWearingSuit.m_Value && !g_pGameRules->IsMultiplayer(this: g_pGameRules) )
  {
    this->m_rgSuitPlayList[0] = 0;
    this->m_rgSuitPlayList[1] = 0;
    this->m_rgSuitPlayList[2] = 0;
    this->m_rgSuitPlayList[3] = 0;
  }
  CBaseEntity::SetGroundEntity(this, ground: nullptr);
  CBaseEntity::RemoveFlag(this, flagsToRemove: 2);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  this->SetObserverMode(this, a2: mode);
  if ( gpGlobals->eLoadType != MapLoad_Background )
  {
    modea = this->__vftable;
    v8 = ((int (__thiscall *)(CBasePlayer *, int, _DWORD))this->ModeWantsSpectatorGUI)(a1: this, a2: mode, a3: 0);
    ((void (__thiscall *)(CBasePlayer *, const char *, _DWORD))modea->ShowViewPortPanel)(
      a1: this,
      a2: "specgui",
      a3: v8);
  }
  p_m_iHideHUD = &this->m_Local.m_iHideHUD;
  v10 = this->m_Local.m_iHideHUD.m_Value | 8;
  if ( this->m_Local.m_iHideHUD.m_Value != v10 )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_iHideHUD);
    p_m_iHideHUD->m_Value = v10;
  }
  v11 = p_m_iHideHUD->m_Value | 1;
  if ( p_m_iHideHUD->m_Value != v11 )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_iHideHUD);
    p_m_iHideHUD->m_Value = v11;
  }
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  CBaseEntity::AddEffects(this, nEffects: 32);
  if ( this->m_iHealth.m_Value != 1 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 1;
  }
  if ( this->m_lifeState.m_Value != 2 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    this->m_lifeState.m_Value = 2;
  }
  p_deadflag = &this->pl.deadflag;
  *(float *)&p_deadflag[232].m_Value = gpGlobals->curtime;
  if ( !p_deadflag->m_Value )
  {
    (**(void (__thiscall ***)(int, CNetworkVarBase<bool,CPlayerState::NetworkVar_deadflag> *))&p_deadflag[-4].m_Value)(
      a1: (int)&p_deadflag[-4],
      a2: p_deadflag);
    p_deadflag->m_Value = true;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101BEEF0
// Name: public: void CBasePlayer::RunNullCommand(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayer::RunNullCommand(CBasePlayer *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  CBasePlayer_vtbl *v5; // edx
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // eax
  int v7; // edx
  edict_t *m_pPev; // ecx
  IMoveHelper *v9; // eax
  CBasePlayer_vtbl *v10; // edi
  IMoveHelper *v11; // eax
  IMoveHelper *v12; // eax
  CUserCmd cmd; // [esp+0h] [ebp-64h] BYREF
  float flOldCurtime; // [esp+58h] [ebp-Ch]
  float flOldFrametime; // [esp+5Ch] [ebp-8h]
  int v17; // [esp+60h] [ebp-4h]

  v5 = this->__vftable;
  cmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  memset(&cmd.command_number, 0, 37);
  memset(&cmd.weaponselect, 0, 17);
  memset((void *)&cmd.headangles, 0, 24);
  flOldFrametime = gpGlobals->frametime;
  EyeAngles = v5->EyeAngles;
  flOldCurtime = gpGlobals->curtime;
  this->pl.fixangle = 0;
  cmd.viewangles = *(QAngle *)((int (__stdcall *)(int, int, int))EyeAngles)(a1: a3, a2: a4, a3: a2);
  v7 = (int)(float)((float)(gpGlobals->curtime / gpGlobals->interval_per_tick) + 0.5);
  v17 = v7;
  if ( this->m_nTickBase.m_Value != v7 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xF2Cu);
        v7 = v17;
      }
    }
    this->m_nTickBase.m_Value = v7;
  }
  v9 = MoveHelperServer();
  v9->SetHost(this: v9, a2: this);
  v10 = this->__vftable;
  v11 = MoveHelperServer();
  v10->PlayerRunCommand(this, a2: &cmd, a3: v11);
  CUserCmd::operator=(this: &this->m_LastCmd, src: &cmd);
  gpGlobals->frametime = flOldFrametime;
  gpGlobals->curtime = flOldCurtime;
  v12 = MoveHelperServer();
  v12->SetHost(this: v12, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101BF070
// Name: private: void CBasePlayer::HandleFuncTrain(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::HandleFuncTrain(CBasePlayer *this)
{
  CBaseEntity *GroundEntity; // edi
  CBaseCombatWeapon *ActiveWeapon; // eax
  int m_nButtons; // eax
  int m_iEFlags; // eax
  unsigned int v6; // ebx
  edict_t *m_pPev; // ecx
  int m_afButtonPressed; // eax
  int v9; // xmm0_4
  unsigned int v10; // edi
  edict_t *v11; // ecx
  CGameTrace trainTrace; // [esp+10h] [ebp-60h] BYREF
  Vector vecAbsEnd; // [esp+64h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+70h] [ebp+0h] BYREF

  if ( (this->m_afPhysicsFlags.m_Value & 1) != 0 )
    CBaseEntity::AddFlag(this, flags: 16);
  else
    CBaseEntity::RemoveFlag(this, flagsToRemove: 16);
  if ( (this->m_afPhysicsFlags.m_Value & 1) == 0 )
  {
    if ( SLOBYTE(this->m_iTrain) < 0 )
      this->m_iTrain = 192;
    return;
  }
  GroundEntity = CBaseEntity::GetGroundEntity(this);
  if ( GroundEntity == nullptr )
  {
LABEL_10:
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( (ActiveWeapon->ObjectCaps(this: ActiveWeapon) & 8) != 0 )
    {
      m_nButtons = this->m_nButtons;
      this->m_iTrain = 192;
      if ( (m_nButtons & 8) != 0 )
        this->m_iTrain = 196;
      else
        this->m_iTrain = (m_nButtons & 0x10 | 0x304u) >> 2;
      return;
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    m_iEFlags = this->m_iEFlags;
    vecAbsEnd.x = this->m_vecAbsOrigin.x;
    vecAbsEnd.y = this->m_vecAbsOrigin.y;
    vecAbsEnd.z = this->m_vecAbsOrigin.z - 38.0;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &this->m_vecAbsOrigin,
      &vecAbsEnd,
      mask: 0x1400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &trainTrace);
    if ( trainTrace.fraction != 1.0 && trainTrace.m_pEnt != nullptr )
      GroundEntity = trainTrace.m_pEnt;
    if ( GroundEntity == nullptr
      || (GroundEntity->ObjectCaps(this: GroundEntity) & 8) == 0
      || !GroundEntity->OnControls(this: GroundEntity, a2: this) )
    {
      v6 = this->m_afPhysicsFlags.m_Value & 0xFFFFFFFE;
      if ( this->m_afPhysicsFlags.m_Value != v6 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_afPhysicsFlags.m_Value = v6;
          this->m_iTrain = 192;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xBFCu);
          this->m_afPhysicsFlags.m_Value = v6;
          this->m_iTrain = 192;
        }
        return;
      }
LABEL_44:
      this->m_iTrain = 192;
      return;
    }
    goto LABEL_33;
  }
  if ( (GroundEntity->ObjectCaps(this: GroundEntity) & 8) == 0 )
  {
    GroundEntity = nullptr;
    goto LABEL_10;
  }
  if ( (this->m_fFlags.m_Value & 1) == 0
    || (GroundEntity->m_spawnflags.m_Value & 2) != 0
    || (this->m_nButtons & 0x600) != 0 )
  {
    v10 = this->m_afPhysicsFlags.m_Value & 0xFFFFFFFE;
    if ( this->m_afPhysicsFlags.m_Value != v10 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v11 = this->m_Network.m_pPev;
        if ( v11 != nullptr )
          CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0xBFCu);
      }
      this->m_afPhysicsFlags.m_Value = v10;
    }
    goto LABEL_44;
  }
LABEL_33:
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  m_afButtonPressed = this->m_afButtonPressed;
  if ( (m_afButtonPressed & 8) != 0 )
  {
    v9 = 1065353216;
  }
  else
  {
    if ( (m_afButtonPressed & 0x10) == 0 )
      return;
    v9 = -1082130432;
  }
  ((void (__thiscall *)(CBaseEntity *, CBasePlayer *, CBasePlayer *, int, int))GroundEntity->Use)(
    a1: GroundEntity,
    a2: this,
    a3: this,
    a4: 2,
    a5: v9);
  this->m_iTrain = TrainSpeed(
                     iSpeed: (int)GroundEntity->m_flSpeed,
                     iMax: (int)*(float *)&GroundEntity[1].m_Network.m_TimerEvent.m_pEventMgr)
                 | 0xC0;
}

//------------------------------------------------------------------------------
// Address: 0x101BF330
// Name: public: virtual void CBasePlayer::PreThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::PreThink(CBasePlayer *this)
{
  CHintSystem *v2; // eax
  int m_Value; // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *p_m_iHideHUD; // ebx
  unsigned int v5; // edi
  CBasePlayer *v6; // ecx
  float v7; // xmm0_4
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  this->EnsureSplitScreenTeam(this);
  if ( !g_fGameOver && this->m_iPlayerLocked == 0 )
  {
    if ( this->Hints(this) != nullptr )
    {
      v2 = this->Hints(this);
      CHintSystem::Update(this: v2);
    }
    CBasePlayer::ItemPreFrame(this);
    CBasePlayer::WaterMove(this);
    if ( g_pGameRules != nullptr && g_pGameRules->FAllowFlashlight(this: g_pGameRules) )
    {
      m_Value = this->m_Local.m_iHideHUD.m_Value;
      p_m_iHideHUD = &this->m_Local.m_iHideHUD;
      v5 = m_Value & 0xFFFFFFFD;
    }
    else
    {
      m_Value = this->m_Local.m_iHideHUD.m_Value;
      p_m_iHideHUD = &this->m_Local.m_iHideHUD;
      v5 = m_Value | 2;
    }
    if ( m_Value != v5 )
    {
      (*(void (__thiscall **)(CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *, CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *))p_m_iHideHUD[-15].m_Value)(
        a1: p_m_iHideHUD - 15,
        a2: p_m_iHideHUD);
      p_m_iHideHUD->m_Value = v5;
    }
    this->UpdateClientData(this);
    CBasePlayer::CheckTimeBasedDamage(this);
    CBasePlayer::CheckSuitUpdate(this);
    if ( this->GetObserverMode(this) > 2 )
      this->CheckObserverSettings(this);
    v6 = this;
    if ( this->m_lifeState.m_Value < 1 )
    {
      CBasePlayer::HandleFuncTrain(this);
      if ( (this->m_nButtons & 2) != 0 )
        this->Jump(this);
      if ( (this->m_nButtons & 4) != 0 || (this->m_fFlags.m_Value & 2) != 0 || (this->m_afPhysicsFlags.m_Value & 2) != 0 )
        this->Duck(this);
      if ( (this->m_fFlags.m_Value & 1) == 0 )
      {
        if ( (this->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
        LODWORD(v7) = LODWORD(this->m_vecAbsVelocity.z) ^ _mask__NegFloat_;
        if ( this->m_Local.m_flFallVelocity.m_Value != v7 )
        {
          this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_flFallVelocity);
          this->m_Local.m_flFallVelocity.m_Value = v7;
        }
      }
      if ( CBaseEntity::GetGroundEntity(this) != nullptr )
        this->m_flTimeLastTouchedGround = gpGlobals->curtime;
      v6 = this;
      this->m_flTimeLastTouchedGround = gpGlobals->curtime;
    }
    this->UpdateLastKnownArea(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF500
// Name: public: void CBasePlayer::OnTonemapTriggerEndTouch(class CTonemapTrigger __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::OnTonemapTriggerEndTouch(CBasePlayer *this, unsigned int pTonemapTrigger)
{
  int v3; // eax

  if ( pTonemapTrigger != 0 )
    pTonemapTrigger = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)pTonemapTrigger + 8))(a1: pTonemapTrigger);
  else
    pTonemapTrigger = -1;
  v3 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_hTriggerTonemapList,
         src: (CHandle<CBaseEntity> *)&pTonemapTrigger);
  if ( v3 != -1 )
  {
    if ( this->m_hTriggerTonemapList.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &this->m_hTriggerTonemapList.m_Memory.m_pMemory[v3],
        src: &this->m_hTriggerTonemapList.m_Memory.m_pMemory[v3 + 1],
        count: 4 * (this->m_hTriggerTonemapList.m_Size - v3 - 1));
    --this->m_hTriggerTonemapList.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF570
// Name: protected: virtual void CBasePlayer::UpdateTonemapController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdateTonemapController(CBasePlayer *this)
{
  unsigned int m_Index; // eax

  m_Index = TheTonemapSystem()->m_hMasterController.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hTonemapController>::Set(
      this: &this->m_hTonemapController,
      val: nullptr);
  else
    CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hTonemapController>::Set(
      this: &this->m_hTonemapController,
      val: (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x101BF5C0
// Name: public: virtual int CBasePlayer::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBasePlayer::Restore@<eax>(CBasePlayer *this@<ecx>, int a2@<edi>, IRestore *restore)
{
  int result; // eax
  CSaveRestoreData *pSaveData; // eax
  int v6; // edi
  float *v7; // edi
  edict_t *m_pPev; // ecx
  const CViewVectors *v9; // eax
  const CViewVectors *v10; // eax
  int v11; // [esp-4h] [ebp-20h]
  const Vector *v12; // [esp-4h] [ebp-20h]
  const Vector *v13; // [esp-4h] [ebp-20h]
  Vector origin; // [esp+4h] [ebp-18h] BYREF
  QAngle newViewAngles; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  result = CBaseCombatCharacter::Restore(this, restore);
  if ( result != 0 )
  {
    pSaveData = gpGlobals->pSaveData;
    v11 = a2;
    if ( pSaveData->levelInfo.fUseLandmark == 0 )
    {
      _Msg(a1: "No Landmark:%s\n", pSaveData->levelInfo.szLandmarkName);
      v6 = ((int (__thiscall *)(CBasePlayer *, int))this->EntSelectSpawnPoint)(a1: this, a2);
      origin.x = *(float *)(v6 + 700);
      origin.y = *(float *)(v6 + 704);
      origin.z = *(float *)(v6 + 708) + 1.0;
      CBaseEntity::SetLocalOrigin(this, &origin);
      CBaseEntity::SetLocalAngles(this, angles: (const QAngle *)(v6 + 712));
    }
    *(_QWORD *)&newViewAngles.x = *(_QWORD *)&this->pl.v_angle.x;
    newViewAngles.z = 0.0;
    CBaseEntity::SetLocalAngles(this, angles: &newViewAngles);
    this->pl.v_angle = newViewAngles;
    this->pl.fixangle = 1;
    CBaseCombatCharacter::SetBloodColor(this, nBloodColor: 0);
    v7 = (float *)(this->m_afPhysicsFlags.m_Value & 0xFFFFFFEF);
    if ( (float *)this->m_afPhysicsFlags.m_Value != v7 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xBFCu);
      }
      this->m_afPhysicsFlags.m_Value = (unsigned int)v7;
    }
    if ( (this->m_fFlags.m_Value & 2) != 0 )
    {
      FixPlayerCrouchStuck(a1: (int)&savedregs, a2: v7, a3: (int)this, pPlayer: this);
      v12 = (const Vector *)(((int (__thiscall *)(CGameRules *, int))g_pGameRules->GetViewVectors)(
                               a1: g_pGameRules,
                               a2: v11)
                           + 48);
      v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      UTIL_SetSize(pEnt: this, vecMin: &v9->m_vDuckHullMin, vecMax: v12);
      if ( !this->m_Local.m_bDucked.m_Value )
      {
        this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bDucked);
        this->m_Local.m_bDucked.m_Value = true;
      }
    }
    else
    {
      if ( this->m_Local.m_bDucked.m_Value )
      {
        this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bDucked);
        this->m_Local.m_bDucked.m_Value = false;
      }
      v13 = (const Vector *)(((int (__thiscall *)(CGameRules *, int))g_pGameRules->GetViewVectors)(
                               a1: g_pGameRules,
                               a2: v11)
                           + 24);
      v10 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      UTIL_SetSize(pEnt: this, vecMin: &v10->m_vHullMin, vecMax: v13);
    }
    ((void (__thiscall *)(CBasePlayer *, Vector *))this->InitVCollision)(a1: this, a2: &this->m_vecAbsOrigin);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BF7C0
// Name: public: void CBasePlayer::SetArmorValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetArmorValue(CBasePlayer *this, int value)
{
  CNetworkVarBase<int,CBasePlayer::NetworkVar_m_ArmorValue> *p_m_ArmorValue; // esi

  p_m_ArmorValue = &this->m_ArmorValue;
  if ( this->m_ArmorValue.m_Value != value )
  {
    this->NetworkStateChanged_m_ArmorValue(this, a2: &this->m_ArmorValue);
    p_m_ArmorValue->m_Value = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF800
// Name: public: virtual bool CBasePlayer::GetInVehicle(class IServerVehicle __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::GetInVehicle(CBasePlayer *this, IServerVehicle *pVehicle, int nRole)
{
  int v3; // ebx
  bool result; // al
  CBaseCombatWeapon *ActiveWeapon; // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *p_m_iHideHUD; // ebx
  CBaseEntity *v9; // ebx
  CBasePlayer_vtbl *v10; // edi
  const CViewVectors *v11; // eax
  void (__thiscall *OnVehicleStart)(CBasePlayer *); // edx
  QAngle qSeatAngles; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector vSeatOrigin; // [esp+38h] [ebp-10h] BYREF
  CBaseEntity *pEnt; // [esp+44h] [ebp-4h]
  IServerVehicle *pVehiclea; // [esp+50h] [ebp+8h]
  IServerVehicle *pVehicleb; // [esp+50h] [ebp+8h]

  v3 = nRole;
  result = CBasePlayer::CanEnterVehicle(this, pVehicle, nRole);
  if ( result )
  {
    pEnt = pVehicle->GetVehicleEnt(this: pVehicle);
    if ( !pVehicle->IsPassengerUsingStandardWeapons(this: pVehicle, a2: nRole) )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
      if ( ActiveWeapon != nullptr )
        ActiveWeapon->Holster(this: ActiveWeapon, a2: nullptr);
      p_m_iHideHUD = &this->m_Local.m_iHideHUD;
      pVehiclea = (IServerVehicle *)(this->m_Local.m_iHideHUD.m_Value | 1);
      if ( (IServerVehicle *)this->m_Local.m_iHideHUD.m_Value != pVehiclea )
      {
        this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_iHideHUD);
        p_m_iHideHUD->m_Value = (int)pVehiclea;
      }
      pVehicleb = (IServerVehicle *)(p_m_iHideHUD->m_Value | 0x400);
      if ( (IServerVehicle *)p_m_iHideHUD->m_Value != pVehicleb )
      {
        this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_iHideHUD);
        p_m_iHideHUD->m_Value = (int)pVehicleb;
      }
      v3 = nRole;
    }
    if ( !pVehicle->IsPassengerVisible(this: pVehicle, a2: v3) )
      CBaseEntity::AddEffects(this, nEffects: 32);
    pVehicle->SetPassenger(this: pVehicle, a2: v3, a3: this);
    CBasePlayer::ViewPunchReset(this, tolerance: 0.0);
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NOCLIP, moveCollide: MOVECOLLIDE_DEFAULT);
    gamestats->Event_DecrementPlayerEnteredNoClip(this: gamestats, a2: this);
    pVehicle->GetPassengerSeatPoint(this: pVehicle, a2: v3, a3: &vSeatOrigin, a4: &qSeatAngles);
    CBaseEntity::SetAbsOrigin(this, absOrigin: &vSeatOrigin);
    CBaseEntity::SetAbsAngles(this, absAngles: &qSeatAngles);
    v9 = pEnt;
    this->SetParent(this, a2: pEnt, a3: -1);
    CBaseEntity::SetCollisionGroup(this, collisionGroup: 10);
    CBaseEntity::RemoveFlag(this, flagsToRemove: 2);
    v10 = this->__vftable;
    v11 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v10->SetViewOffset(this, a2: &v11->m_vView);
    if ( this->m_Local.m_bDucked.m_Value )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bDucked);
      this->m_Local.m_bDucked.m_Value = false;
    }
    if ( this->m_Local.m_bDucking.m_Value )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bDucking);
      this->m_Local.m_bDucking.m_Value = false;
    }
    if ( this->m_Local.m_nDuckTimeMsecs.m_Value != 0 )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_nDuckTimeMsecs);
      this->m_Local.m_nDuckTimeMsecs.m_Value = 0;
    }
    if ( this->m_Local.m_nDuckJumpTimeMsecs.m_Value != 0 )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_nDuckJumpTimeMsecs);
      this->m_Local.m_nDuckJumpTimeMsecs.m_Value = 0;
    }
    if ( this->m_Local.m_nJumpTimeMsecs.m_Value != 0 )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_nJumpTimeMsecs);
      this->m_Local.m_nJumpTimeMsecs.m_Value = 0;
    }
    if ( this->m_bDuckToggled )
      this->m_bDuckToggled = false;
    CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hVehicle>::Set(this: &this->m_hVehicle, val: v9);
    g_pNotify->ReportNamedEvent(this: g_pNotify, a2: this, a3: "PlayerEnteredVehicle");
    OnVehicleStart = this->OnVehicleStart;
    this->m_iVehicleAnalogBias = 0;
    OnVehicleStart(this);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BFA50
// Name: public: virtual class CBaseEntity __near * CBasePlayer::GiveNamedItem(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::GiveNamedItem(
        CBasePlayer *this,
        const char *pszName,
        int iSubType,
        bool removeIfNotCarried)
{
  CBaseEntity *EntityByName; // eax
  unsigned int m_Index; // edi
  int v8; // esi
  CEntInfo *v9; // eax
  unsigned int v10; // edi
  CBaseEntity *m_pEntity; // ecx
  IHandleEntity *v12; // eax
  _DWORD *v13; // ebx
  IHandleEntity_vtbl *v14; // eax
  int v15; // edx
  _DWORD *v16; // eax
  CBaseEdict *v17; // ecx
  IHandleEntity *v18; // eax
  void *v19; // eax
  CBaseEntity *v20; // eax
  CBaseEntityList *v21; // ecx
  IHandleEntity *v22; // eax
  CBaseEntity *v23; // eax
  CHandle<CBaseEntity> pent; // [esp+Ch] [ebp-4h] BYREF
  const char *pszNamea; // [esp+18h] [ebp+8h]

  if ( ((int (__stdcall *)(const char *, int))this->Weapon_OwnsThisType)(a1: pszName, a2: iSubType) != 0 )
    return nullptr;
  EntityByName = CreateEntityByName(className: pszName, iForceEdictIndex: -1, bNotify: true);
  if ( EntityByName == nullptr
    || (m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index, pent.m_Index = m_Index, m_Index == -1)
    || (v8 = (unsigned __int16)m_Index,
        v9 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v10 = HIWORD(m_Index),
        v9->m_SerialNumber != v10)
    || v9->m_pEntity == nullptr )
  {
    _Msg(a1: "NULL Ent in GiveNamedItem!\n");
    return nullptr;
  }
  if ( g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v10 )
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[v8].m_pEntity;
  else
    m_pEntity = nullptr;
  CBaseEntity::SetLocalOrigin(this: m_pEntity, origin: &this->m_vecOrigin.m_Value);
  if ( g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v10 )
    v12 = g_pEntityList->m_EntPtrArray[v8].m_pEntity;
  else
    v12 = nullptr;
  v13 = &v12[190].__vftable;
  v14 = v12[190].__vftable;
  v15 = (unsigned int)v14 | 0x40000000;
  pszNamea = (const char *)((unsigned int)v14 | 0x40000000);
  if ( v14 != (IHandleEntity_vtbl *)((unsigned int)v14 | 0x40000000) )
  {
    v16 = v13 - 190;
    if ( *((_BYTE *)v13 - 676) != 0 )
    {
      *((_BYTE *)v16 + 88) |= 1u;
    }
    else
    {
      v17 = (CBaseEdict *)v16[6];
      if ( v17 != nullptr )
      {
        CBaseEdict::StateChanged(this: v17, offset: 0x2F8u);
        v15 = (int)pszNamea;
      }
    }
    *v13 = v15;
  }
  if ( g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v10 )
    v18 = g_pEntityList->m_EntPtrArray[v8].m_pEntity;
  else
    v18 = nullptr;
  v19 = __RTDynamicCast(
          inptr: v18,
          VfDelta: 0,
          SrcType: &CBaseEntity `RTTI Type Descriptor',
          TargetType: &CBaseCombatWeapon `RTTI Type Descriptor',
          isReference: 0);
  if ( v19 != nullptr )
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)v19 + 928))(a1: v19, a2: iSubType);
  if ( g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v10 )
    v20 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[v8].m_pEntity;
  else
    v20 = nullptr;
  DispatchSpawn(pEntity: v20, bRunVScripts: true);
  v21 = g_pEntityList;
  if ( g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v10 && g_pEntityList->m_EntPtrArray[v8].m_pEntity != nullptr )
  {
    if ( g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v10 )
      v22 = g_pEntityList->m_EntPtrArray[v8].m_pEntity;
    else
      v22 = nullptr;
    if ( ((int)v22[49].__vftable & 1) == 0 )
    {
      v23 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &pent);
      v23->Touch(this: v23, a2: this);
      v21 = g_pEntityList;
    }
  }
  if ( v21->m_EntPtrArray[v8].m_SerialNumber != v10 )
    return nullptr;
  return (CBaseEntity *)v21->m_EntPtrArray[v8].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101BFC30
// Name: public: void CBasePlayer::ShowCrosshair(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ShowCrosshair(CBasePlayer *this, bool bShow)
{
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *p_m_iHideHUD; // edi
  int m_Value; // esi
  unsigned int v4; // esi

  p_m_iHideHUD = &this->m_Local.m_iHideHUD;
  m_Value = this->m_Local.m_iHideHUD.m_Value;
  if ( bShow )
    v4 = m_Value & 0xFFFFFEFF;
  else
    v4 = m_Value | 0x100;
  if ( this->m_Local.m_iHideHUD.m_Value != v4 )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: p_m_iHideHUD);
    p_m_iHideHUD->m_Value = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BFC70
// Name: public: virtual void CBasePlayer::UpdateClientData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdateClientData(CBasePlayer *this)
{
  int v2; // edi
  CAI_ScriptedSequence *WorldEntity; // eax
  CWorld *v4; // ebx
  CBaseCombatWeapon *Weapon; // eax
  bool v6; // bl
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *p_m_iHideHUD; // ebx
  int v8; // edi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *v9; // edi
  unsigned int v10; // ebx
  variant_t v11; // [esp-10h] [ebp-64h]
  variant_t v12; // [esp-10h] [ebp-64h]
  CSingleUserRecipientFilter user; // [esp+20h] [ebp-34h] BYREF
  variant_t value; // [esp+40h] [ebp-14h]

  CRecipientFilter::CRecipientFilter(this: &user);
  user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &user, player: this);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
  if ( this->m_fInitHUD )
  {
    this->m_fInitHUD = false;
    gInitHUD = false;
    UserMessageBegin(filter: &user, messagename: "ResetHUD");
    v2 = 0;
    MessageWriteByte(iValue: 0);
    MessageEnd();
    if ( !this->m_fGameHUDInitialized )
    {
      g_pGameRules->InitHUD(this: g_pGameRules, a2: this);
      this->InitHUD(this);
      this->m_fGameHUDInitialized = true;
      if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) )
      {
        value.iVal = 0;
        v11.vecVal[2] = value.vecVal[2];
        *(_QWORD *)&v11.bVal = __PAIR64__(LODWORD(value.vecVal[1]), 0);
        *(_QWORD *)&v11.eVal.m_Index = 0xFFFFFFFFLL;
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: "game_player_manager",
          targetInput: "OnPlayerJoin",
          Value: v11,
          fireDelay: 0.0,
          pActivator: this,
          pCaller: this,
          outputID: 0);
      }
    }
    value.iVal = 0;
    v12.vecVal[2] = value.vecVal[2];
    *(_QWORD *)&v12.bVal = __PAIR64__(LODWORD(value.vecVal[1]), 0);
    *(_QWORD *)&v12.eVal.m_Index = 0xFFFFFFFFLL;
    CEventQueue::AddEvent(
      this: &g_EventQueue,
      target: "game_player_manager",
      targetInput: "OnPlayerSpawn",
      Value: v12,
      fireDelay: 0.0,
      pActivator: this,
      pCaller: this,
      outputID: 0);
  }
  else
  {
    v2 = 0;
  }
  WorldEntity = (CAI_ScriptedSequence *)GetWorldEntity();
  v4 = (CWorld *)WorldEntity;
  if ( WorldEntity != nullptr && CWorld::GetDisplayTitle(this: WorldEntity) )
  {
    UserMessageBegin(filter: &user, messagename: "GameTitle");
    MessageEnd();
    CWorld::SetDisplayTitle(this: v4, display: false);
  }
  this->UpdateBattery(this);
  this->CheckTrainUpdate(this);
  do
  {
    if ( CBaseCombatCharacter::GetWeapon(this, i: v2) != nullptr )
    {
      Weapon = CBaseCombatCharacter::GetWeapon(this, i: v2);
      Weapon->UpdateClientData(this: Weapon, a2: this);
    }
    ++v2;
  }
  while ( v2 < 64 );
  v6 = (this->m_bitsDamageType & 0x20000) != 0
    && this->m_nPoisonDmg > this->m_nPoisonRestored
    && this->m_iHealth.m_Value < 100;
  if ( this->m_Local.m_bPoisoned.m_Value != v6 )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bPoisoned);
    this->m_Local.m_bPoisoned.m_Value = v6;
  }
  if ( this->m_iBonusChallenge.m_Value != 0 )
    goto LABEL_27;
  if ( this->m_iBonusProgress.m_Value == 0 )
  {
    p_m_iHideHUD = &this->m_Local.m_iHideHUD;
    if ( (this->m_Local.m_iHideHUD.m_Value & 0x800) == 0 )
    {
      v8 = p_m_iHideHUD->m_Value | 0x800;
      if ( p_m_iHideHUD->m_Value != v8 )
      {
        this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_iHideHUD);
        p_m_iHideHUD->m_Value = v8;
      }
    }
  }
  if ( this->m_iBonusChallenge.m_Value != 0 )
  {
LABEL_27:
    v9 = &this->m_Local.m_iHideHUD;
    if ( (this->m_Local.m_iHideHUD.m_Value & 0x800) != 0 )
    {
      v10 = v9->m_Value & 0xFFFFF7FF;
      if ( v9->m_Value != v10 )
      {
        this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_iHideHUD);
        v9->m_Value = v10;
      }
    }
  }
  g_pGameRules->UpdateClientData(this: g_pGameRules, a2: this);
  CRecipientFilter::~CRecipientFilter(this: &user);
}

//------------------------------------------------------------------------------
// Address: 0x101BFEF0
// Name: private: class QAngle CBasePlayer::AutoaimDeflection(class Vector __near &,struct autoaim_params_t __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
QAngle *__userpurge CBasePlayer::AutoaimDeflection@<eax>(
        CBasePlayer *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        QAngle *result,
        Vector *vecSrc,
        autoaim_params_t *params)
{
  bool m_Value; // zf
  CNetworkVarBase<bool,CBasePlayer::NetworkVar_m_fOnTarget> *p_m_fOnTarget; // esi
  edict_t *m_pPev; // ecx
  float *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float x; // xmm3_4
  float v15; // xmm3_4
  float y; // xmm0_4
  float v17; // xmm0_4
  bool (__thiscall *IsInAVehicle)(CBaseCombatCharacter *); // eax
  CBaseEntity *v19; // esi
  float v20; // xmm0_4
  unsigned int v21; // xmm1_4
  float v22; // xmm3_4
  CBaseEntity *m_pEnt; // esi
  Class_T v24; // eax
  CNetworkVarBase<bool,CBasePlayer::NetworkVar_m_fOnTarget> *v25; // esi
  CNetworkVarBase<bool,CBasePlayer::NetworkVar_m_fOnTarget> *v26; // eax
  CBaseEdict *v27; // ecx
  autoaim_params_t *v28; // esi
  const CBaseEntity *v29; // eax
  void *v30; // esp
  CBasePlayer *v31; // esi
  float *v32; // eax
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  __int128 v38; // xmm1
  CBaseCombatWeapon *v39; // eax
  double v40; // st6
  CBaseCombatWeapon *ActiveWeapon; // eax
  Vector *(__thiscall *GetAutoAimCenter)(CBaseEntity *, Vector *); // edx
  float v43; // ecx
  const Vector *v44; // eax
  double AutoaimScore; // st7
  CBasePlayer *v46; // esi
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // eax
  float *v48; // eax
  float v49; // xmm0_4
  float *v50; // eax
  float v51; // xmm2_4
  float v52; // xmm3_4
  CNetworkVarBase<bool,CBasePlayer::NetworkVar_m_fOnTarget> *v53; // edi
  CNetworkVarBase<bool,CBasePlayer::NetworkVar_m_fOnTarget> *v54; // eax
  CBaseEdict *v55; // ecx
  unsigned int *v56; // eax
  float v57; // xmm0_4
  Vector *(__thiscall *BodyTarget)(CBaseEntity *, Vector *, const Vector *, bool); // edx
  CBaseCombatWeapon *v59; // eax
  Vector v63; // [esp+28h] [ebp-11Ch] BYREF
  Vector v64; // [esp+34h] [ebp-110h] BYREF
  CGameTrace v65; // [esp+40h] [ebp-104h] BYREF
  __int128 v66; // [esp+98h] [ebp-ACh]
  _BYTE v67[12]; // [esp+B0h] [ebp-94h] BYREF
  float v68; // [esp+BCh] [ebp-88h]
  CTraceFilterSkipTwoEntities v69; // [esp+C8h] [ebp-7Ch] BYREF
  Vector v70; // [esp+DCh] [ebp-68h] BYREF
  float v71; // [esp+E8h] [ebp-5Ch]
  float v72; // [esp+ECh] [ebp-58h]
  float *p_z; // [esp+F0h] [ebp-54h]
  Vector v74; // [esp+F4h] [ebp-50h] BYREF
  float v75; // [esp+100h] [ebp-44h]
  CNetworkVarBase<bool,CBasePlayer::NetworkVar_m_fOnTarget> *v76; // [esp+104h] [ebp-40h]
  CBasePlayer *v77; // [esp+108h] [ebp-3Ch]
  int v78; // [esp+10Ch] [ebp-38h]
  Vector v79; // [esp+110h] [ebp-34h] BYREF
  const CBaseEntity *v80; // [esp+11Ch] [ebp-28h]
  Vector v81; // [esp+120h] [ebp-24h] BYREF
  QAngle fScale; // [esp+12Ch] [ebp-18h] BYREF
  QAngle bestang; // [esp+138h] [ebp-Ch] BYREF
  float retaddr; // [esp+144h] [ebp+0h]

  bestang.x = a2;
  bestang.y = retaddr;
  m_Value = !this->m_fOnTarget.m_Value;
  p_m_fOnTarget = &this->m_fOnTarget;
  v76 = &this->m_fOnTarget;
  if ( !m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xBA0u);
    }
    p_m_fOnTarget->m_Value = false;
  }
  v11 = (float *)((int (__thiscall *)(CBasePlayer *, int, int))this->EyeAngles)(a1: this, a2: a3, a3: a4);
  v12 = this->m_Local.m_vecPunchAngle.m_Value.y + v11[1];
  v13 = this->m_Local.m_vecPunchAngle.m_Value.z + v11[2];
  x = this->m_vecAutoAim.x;
  v68 = *v11;
  v15 = x + (float)(v68 + this->m_Local.m_vecPunchAngle.m_Value.x);
  y = this->m_vecAutoAim.y;
  LODWORD(fScale.y) = &v64;
  LODWORD(fScale.x) = &v63;
  v81.y = y + v12;
  v17 = this->m_vecAutoAim.z + v13;
  v81.x = v15;
  AngleVectors(angles: (const QAngle *)&v81, forward: (Vector *)LODWORD(v17), right: &v63, up: &v64);
  IsInAVehicle = this->IsInAVehicle;
  v79 = v74;
  v75 = 0.0;
  fScale = vec3_angle;
  v19 = nullptr;
  v77 = nullptr;
  if ( IsInAVehicle(this) )
    v19 = this->GetVehicleEntity(this);
  CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
    this: &v69,
    passentity: this,
    passentity2: v19,
    collisionGroup: 0);
  LODWORD(fScale.y) = &v65;
  LODWORD(fScale.x) = &v69;
  v20 = (float)(v79.y * 16384.0) + vecSrc->y;
  *(float *)&v21 = (float)(v79.z * 16384.0) + vecSrc->z;
  v81.z = 8208.0029;
  v22 = vecSrc->x + (float)(v79.x * 16384.0);
  v69.__vftable = (CTraceFilterSkipTwoEntities_vtbl *)&CTraceFilterSkipTwoEntitiesAndTeammates::`vftable';
  UTIL_TraceLine(
    a1: (int)&bestang,
    a2: (int)v19,
    vecAbsStart: (const Vector *)LODWORD(v22),
    vecAbsEnd: (const Vector *)LODWORD(v20),
    mask: v21,
    pFilter: &v69,
    ptr: &v65);
  m_pEnt = v65.m_pEnt;
  v80 = v65.m_pEnt;
  if ( v65.m_pEnt == nullptr || v65.m_pEnt->m_takedamage.m_Value == 0 || !v65.m_pEnt->IsAlive(this: v65.m_pEnt) )
    goto LABEL_28;
  if ( this->m_nWaterLevel.m_Value != 3 )
  {
    if ( m_pEnt->m_nWaterLevel.m_Value != 3 )
      goto LABEL_16;
LABEL_28:
    v28 = params;
    goto LABEL_29;
  }
  if ( m_pEnt->m_nWaterLevel.m_Value == 0 )
    goto LABEL_28;
LABEL_16:
  if ( !m_pEnt->ShouldAttractAutoAim(this: m_pEnt, a2: this) )
    goto LABEL_28;
  if ( m_pEnt->IsNPC(this: m_pEnt) && g_pGameRules->GetAutoAimMode(this: g_pGameRules) > 0 )
  {
    v24 = m_pEnt->Classify(this: m_pEnt);
    if ( CBaseCombatCharacter::GetDefaultRelationshipDisposition(this, nClassTarget: v24) != D_HT )
      goto LABEL_28;
  }
  if ( (m_pEnt->m_fFlags.m_Value & 0x20000) != 0 )
  {
    v25 = v76;
    if ( !v76->m_Value )
    {
      v26 = v76 - 2976;
      if ( v76[-2892].m_Value )
      {
        v26[88].m_Value |= 1u;
      }
      else
      {
        v27 = *(CBaseEdict **)&v26[24].m_Value;
        if ( v27 != nullptr )
          CBaseEdict::StateChanged(this: v27, offset: 0xBA0u);
      }
      v25->m_Value = true;
    }
  }
  v28 = params;
  CHandle<CBaseEntity>::Set(this: &params->m_hAutoAimEntity, pVal: v80);
  params->m_vecAutoAimDir = v79;
  params->m_vecAutoAimPoint = v65.endpos;
  *(_WORD *)&params->m_bAutoAimAssisting = 256;
LABEL_29:
  v29 = (const CBaseEntity *)AimTarget_ListCount();
  v80 = v29;
  if ( v29 == nullptr )
    goto LABEL_70;
  v30 = alloca(4 * (_DWORD)v29);
  p_z = &fScale.z;
  AimTarget_ListCopy(pList: (CBaseEntity **)&fScale.z, listMax: (int)v80);
  v78 = 0;
  if ( (int)v80 <= 0 )
    goto LABEL_70;
  do
  {
    v31 = (CBasePlayer *)LODWORD(p_z[v78]);
    if ( v31->ShouldAttractAutoAim(this: v31, a2: this)
      && v31 != this
      && (!v31->IsNPC(this: v31) || v31->IsAlive(this: v31))
      && v31->m_Network.m_pPev != nullptr
      && g_pGameRules->ShouldAutoAim(this: g_pGameRules, a2: this, a3: v31->m_Network.m_pPev) )
    {
      if ( this->m_nWaterLevel.m_Value == 3 )
      {
        if ( v31->m_nWaterLevel.m_Value == 0 )
          goto LABEL_57;
      }
      else if ( v31->m_nWaterLevel.m_Value == 3 )
      {
        goto LABEL_57;
      }
      if ( v31->MyNPCPointer(this: v31) == nullptr
        || this->IRelationType(this, a2: v31) == D_HT
        || v31->IsPlayer(this: v31)
        || g_pGameRules->IsDeathmatch(this: g_pGameRules) )
      {
        v32 = (float *)v31->WorldSpaceCenter(this: v31);
        v33 = *v32;
        v34 = v32[2];
        v70.y = v32[1];
        v35 = v70.y - vecSrc->y;
        v70.x = v33;
        v36 = v33 - vecSrc->x;
        v81.y = v35;
        v81.x = v36;
        v70.z = v34;
        v37 = (float)(v36 * v36) + (float)(v35 * v35);
        v38 = 0;
        v81.z = v34 - vecSrc->z;
        *(float *)&v38 = fsqrt(v37);
        v66 = v38;
        VectorNormalize(vec: &v81);
        if ( *(float *)&v66 <= params->m_fMaxDist )
        {
          v71 = (float)((float)(v81.x * v74.x) + (float)(v81.y * v74.y)) + (float)(v81.z * v74.z);
          if ( v71 >= 0.0 )
          {
            if ( (v31->m_fFlags.m_Value & 0x800) != 0
              || CBaseCombatCharacter::GetActiveWeapon(this) == nullptr
              || (v39 = CBaseCombatCharacter::GetActiveWeapon(this),
                  (v40 = ((double (__thiscall *)(CBaseCombatWeapon *))v39->GetMaxAutoAimDeflection)(a1: v39)) <= v71)
              || v68 >= 30.0 && v68 <= 90.0 && g_pGameRules->GetAutoAimMode(this: g_pGameRules) == 2 )
            {
              ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
              GetAutoAimCenter = v31->GetAutoAimCenter;
              LODWORD(fScale.y) = ActiveWeapon;
              fScale.x = v43;
              fScale.x = params->m_fScale;
              LODWORD(v81.z) = v31;
              v44 = GetAutoAimCenter(this: v31, result: (Vector *)v67);
              AutoaimScore = CBasePlayer::GetAutoaimScore(
                               this,
                               eyePosition: vecSrc,
                               viewDir: &v74,
                               vecTarget: v44,
                               pTarget: (CBaseEntity *)LODWORD(v81.z),
                               fScale: fScale.x,
                               pActiveWeapon: (CBaseCombatWeapon *)LODWORD(fScale.y));
              v72 = AutoaimScore;
              if ( v75 < AutoaimScore )
              {
                UTIL_TraceLine(
                  a1: (int)&bestang,
                  a2: (int)v31,
                  vecAbsStart: vecSrc,
                  vecAbsEnd: &v70,
                  mask: 0x46004003u,
                  pFilter: &v69,
                  ptr: &v65);
                if ( v65.fraction == 1.0 || v65.m_pEnt == v31 )
                {
                  v75 = v72;
                  v79 = v81;
                  v77 = v31;
                }
              }
            }
          }
        }
      }
    }
LABEL_57:
    ++v78;
  }
  while ( v78 < (int)v80 );
  v46 = v77;
  if ( v77 != nullptr )
  {
    VectorAngles(forward: &v79, angles: &fScale);
    m_Value = ((unsigned __int8 (__thiscall *)(CBasePlayer *, _DWORD))this->IsInAVehicle)(
                a1: this,
                a2: LODWORD(fScale.z)) == 0;
    EyeAngles = this->EyeAngles;
    if ( m_Value )
    {
      v50 = (float *)((int (__thiscall *)(CBasePlayer *, _DWORD, _DWORD))EyeAngles)(
                       a1: this,
                       a2: LODWORD(bestang.x),
                       a3: LODWORD(bestang.y));
      v51 = v50[2] - this->m_Local.m_vecPunchAngle.m_Value.z;
      v52 = fScale.x - (float)(*v50 - this->m_Local.m_vecPunchAngle.m_Value.x);
      fScale.y = fScale.y - (float)(v50[1] - this->m_Local.m_vecPunchAngle.m_Value.y);
      fScale.x = v52;
      v49 = fScale.z - v51;
    }
    else
    {
      v48 = (float *)((int (__thiscall *)(CBasePlayer *, _DWORD, _DWORD))EyeAngles)(
                       a1: this,
                       a2: LODWORD(bestang.x),
                       a3: LODWORD(bestang.y));
      fScale.x = fScale.x - *v48;
      fScale.y = fScale.y - v48[1];
      v49 = fScale.z - v48[2];
    }
    v53 = v76;
    m_Value = v76->m_Value;
    fScale.z = v49;
    if ( !m_Value )
    {
      v54 = v76 - 2976;
      if ( v76[-2892].m_Value )
      {
        v54[88].m_Value |= 1u;
      }
      else
      {
        v55 = *(CBaseEdict **)&v54[24].m_Value;
        if ( v55 != nullptr )
          CBaseEdict::StateChanged(this: v55, offset: 0xBA0u);
      }
      v53->m_Value = true;
    }
    v56 = (unsigned int *)((int (__thiscall *)(CBasePlayer *, _DWORD, _DWORD))v46->GetRefEHandle)(
                            a1: v46,
                            a2: LODWORD(bestang.x),
                            a3: LODWORD(bestang.y));
    v57 = v79.x;
    params->m_hAutoAimEntity.m_Index = *v56;
    params->m_vecAutoAimDir.x = v57;
    params->m_vecAutoAimDir.y = v79.y;
    bestang.y = 0.0;
    params->m_vecAutoAimDir.z = v79.z;
    BodyTarget = v46->BodyTarget;
    LODWORD(bestang.x) = vecSrc;
    LODWORD(fScale.z) = v67;
    params->m_vecAutoAimPoint = *(Vector *)((int (__thiscall *)(CBasePlayer *))BodyTarget)(a1: v46);
    params->m_bAutoAimAssisting = true;
    goto LABEL_72;
  }
  v28 = params;
LABEL_70:
  if ( v28->m_fMaxDeflection < 0.0 )
  {
    v59 = CBaseCombatCharacter::GetActiveWeapon(this);
    v59->GetMaxAutoAimDeflection(this: v59);
  }
LABEL_72:
  *result = fScale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C06A0
// Name: public: void CBasePlayer::ResetAutoaim(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ResetAutoaim(CBasePlayer *this)
{
  edict_t *m_pPev; // edx
  edict_t *v3; // ecx

  m_pPev = this->m_Network.m_pPev;
  this->m_vecAutoAim.x = 0.0;
  this->m_vecAutoAim.y = 0.0;
  this->m_vecAutoAim.z = 0.0;
  ((void (__thiscall *)(IVEngineServer *, edict_t *, _DWORD, _DWORD))engine->CrosshairAngle)(
    a1: engine,
    a2: m_pPev,
    a3: 0,
    a4: 0);
  if ( this->m_fOnTarget.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_fOnTarget.m_Value = false;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0xBA0u);
      this->m_fOnTarget.m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0720
// Name: public: virtual void CRevertSaved::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRevertSaved::Use(
        CRevertSaved *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        CBaseEntity *useType,
        float value)
{
  CBasePlayer *LocalPlayer; // eax
  CBaseEntity *v7; // edi
  CNetworkVarBase<bool,CPlayerState::NetworkVar_deadflag> *p_deadflag; // esi

  UTIL_ScreenFadeAll(
    color: &this->m_clrRender.m_Value,
    fadeTime: this->m_Duration,
    fadeHold: this->m_HoldTime,
    flags: 2);
  CBaseEntity::SetNextThink(this, thinkTime: this->m_loadTime + gpGlobals->curtime, szContext: nullptr);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CRevertSaved::LoadThink,
    thinkTime: 0.0,
    szContext: nullptr);
  LocalPlayer = UTIL_GetLocalPlayer();
  v7 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    p_deadflag = &LocalPlayer->pl.deadflag;
    if ( !LocalPlayer->pl.deadflag.m_Value )
    {
      LocalPlayer->pl.NetworkStateChanged(this: &LocalPlayer->pl, a2: &LocalPlayer->pl.deadflag);
      p_deadflag->m_Value = true;
    }
    CBaseEntity::AddFlag(this: v7, flags: 65600);
    g_ServerGameDLL.m_fAutoSaveDangerousTime = 0.0;
    g_ServerGameDLL.m_fAutoSaveDangerousMinHealthToCommit = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C07E0
// Name: public: void CRevertSaved::InputReload(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRevertSaved::InputReload(CRevertSaved *this, inputdata_t *inputdata)
{
  CBasePlayer *LocalPlayer; // eax
  CBaseEntity *v4; // edi
  CNetworkVarBase<bool,CPlayerState::NetworkVar_deadflag> *p_deadflag; // esi

  UTIL_ScreenFadeAll(
    color: &this->m_clrRender.m_Value,
    fadeTime: this->m_Duration,
    fadeHold: this->m_HoldTime,
    flags: 2);
  CBaseEntity::SetNextThink(this, thinkTime: this->m_loadTime + gpGlobals->curtime, szContext: nullptr);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CRevertSaved::LoadThink,
    thinkTime: 0.0,
    szContext: nullptr);
  LocalPlayer = UTIL_GetLocalPlayer();
  v4 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    p_deadflag = &LocalPlayer->pl.deadflag;
    if ( !LocalPlayer->pl.deadflag.m_Value )
    {
      LocalPlayer->pl.NetworkStateChanged(this: &LocalPlayer->pl, a2: &LocalPlayer->pl.deadflag);
      p_deadflag->m_Value = true;
    }
    CBaseEntity::AddFlag(this: v4, flags: 65600);
    g_ServerGameDLL.m_fAutoSaveDangerousTime = 0.0;
    g_ServerGameDLL.m_fAutoSaveDangerousMinHealthToCommit = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C08A0
// Name: public: void CMovementSpeedMod::InputSpeedMod(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovementSpeedMod::InputSpeedMod(CMovementSpeedMod *this, inputdata_t *data)
{
  CBasePlayer *pActivator; // esi
  CBasePlayer_vtbl *v4; // ebx
  CBaseCombatWeapon *v5; // eax
  CBaseCombatWeapon *v6; // eax
  int m_Value; // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *p_m_iHideHUD; // ebx
  unsigned int v9; // edi
  CBaseCombatWeapon *Last; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  float flVal; // xmm0_4
  CBaseEdict *v13; // ecx

  if ( data->pActivator != nullptr && data->pActivator->IsPlayer(this: data->pActivator) )
  {
    pActivator = (CBasePlayer *)data->pActivator;
  }
  else
  {
    if ( g_pGameRules->IsDeathmatch(this: g_pGameRules) )
      return;
    pActivator = UTIL_GetLocalPlayer();
  }
  if ( pActivator != nullptr )
  {
    if ( data->value.fieldType == FIELD_FLOAT && data->value.flVal == 1.0 )
    {
      if ( (this->m_spawnflags.m_Value & 1) != 0 && CBaseCombatCharacter::GetActiveWeapon(this: pActivator) == nullptr )
      {
        Last = CBasePlayer::Weapon_GetLast(this: pActivator);
        CBaseCombatCharacter::SetActiveWeapon(this: pActivator, pNewWeapon: Last);
        if ( CBaseCombatCharacter::GetActiveWeapon(this: pActivator) != nullptr )
        {
          ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: pActivator);
          ActiveWeapon->Deploy(this: ActiveWeapon);
        }
      }
      pActivator->SetFlashlightEnabled(this: pActivator, a2: true);
      pActivator->m_afButtonDisabled &= ~CMovementSpeedMod::GetDisabledButtonMask(this);
      if ( (this->m_spawnflags.m_Value & 2) == 0 )
        goto LABEL_25;
      m_Value = pActivator->m_Local.m_iHideHUD.m_Value;
      p_m_iHideHUD = &pActivator->m_Local.m_iHideHUD;
      v9 = m_Value & 0xFFFFFFFB;
    }
    else
    {
      if ( (this->m_spawnflags.m_Value & 1) != 0 )
      {
        if ( CBaseCombatCharacter::GetActiveWeapon(this: pActivator) != nullptr )
        {
          v4 = pActivator->__vftable;
          v5 = CBaseCombatCharacter::GetActiveWeapon(this: pActivator);
          v4->Weapon_SetLast(this: pActivator, a2: v5);
          v6 = CBaseCombatCharacter::GetActiveWeapon(this: pActivator);
          v6->Holster(this: v6, a2: nullptr);
          CBaseCombatCharacter::SetActiveWeapon(this: pActivator, pNewWeapon: nullptr);
        }
        CBasePlayer::HideViewModels(this: pActivator);
      }
      if ( pActivator->FlashlightIsOn(this: pActivator) != 0 )
        pActivator->FlashlightTurnOff(this: pActivator, a2: false);
      pActivator->SetFlashlightEnabled(this: pActivator, a2: false);
      pActivator->m_afButtonDisabled |= CMovementSpeedMod::GetDisabledButtonMask(this);
      if ( (this->m_spawnflags.m_Value & 2) == 0 )
        goto LABEL_25;
      m_Value = pActivator->m_Local.m_iHideHUD.m_Value;
      p_m_iHideHUD = &pActivator->m_Local.m_iHideHUD;
      v9 = m_Value | 4;
    }
    if ( m_Value != v9 )
    {
      (*(void (__thiscall **)(int *, CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *))p_m_iHideHUD[-15].m_Value)(
        a1: &p_m_iHideHUD[-15].m_Value,
        a2: p_m_iHideHUD);
      p_m_iHideHUD->m_Value = v9;
    }
LABEL_25:
    if ( data->value.fieldType == FIELD_FLOAT )
      flVal = data->value.flVal;
    else
      flVal = 0.0;
    if ( pActivator->m_flLaggedMovementValue.m_Value != flVal )
    {
      if ( pActivator->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&pActivator->m_Network + 76) |= 1u;
        pActivator->m_flLaggedMovementValue.m_Value = flVal;
      }
      else
      {
        v13 = &pActivator->m_Network.m_pPev->CBaseEdict;
        if ( v13 != nullptr )
          CBaseEdict::StateChanged(this: v13, offset: 0xFA4u);
        pActivator->m_flLaggedMovementValue.m_Value = flVal;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0AB0
// Name: public: int CBasePlayer::GetFOV(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::GetFOV(CBasePlayer *this)
{
  IServerVehicle *v2; // eax
  CBasePlayer *v3; // ecx
  float m_flVehicleViewFOV; // xmm0_4
  int DefaultFOV; // eax
  int m_Value; // edi
  float v7; // xmm1_4
  float val; // xmm0_4
  edict_t *m_pPev; // ecx

  v2 = this->GetVehicle(this);
  v3 = this;
  if ( v2 == nullptr )
    goto LABEL_4;
  CBasePlayer::CacheVehicleView(this);
  m_flVehicleViewFOV = this->m_flVehicleViewFOV;
  if ( m_flVehicleViewFOV == 0.0 )
  {
    v3 = this;
LABEL_4:
    DefaultFOV = CBasePlayer::GetDefaultFOV(this: v3);
    goto LABEL_5;
  }
  DefaultFOV = (int)m_flVehicleViewFOV;
LABEL_5:
  m_Value = DefaultFOV;
  if ( this->m_iFOV.m_Value != 0 )
    m_Value = this->m_iFOV.m_Value;
  v7 = this->m_Local.m_flFOVRate.m_Value;
  if ( v7 == 0.0 )
    return m_Value;
  val = (float)(gpGlobals->curtime - this->m_flFOVTime.m_Value) / v7;
  if ( val < 1.0 )
    return (int)SimpleSplineRemapValClamped(val, A: 0.0, B: 1.0, C: (float)this->m_iFOVStart.m_Value, D: (float)m_Value);
  if ( this->m_iFOVStart.m_Value == m_Value )
    return m_Value;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
    this->m_iFOVStart.m_Value = m_Value;
    return m_Value;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC54u);
    this->m_iFOVStart.m_Value = m_Value;
    return m_Value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0BC0
// Name: public: void CBasePlayer::SetDefaultFOV(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetDefaultFOV(CBasePlayer *this, int FOV)
{
  int v2; // eax
  int v4; // edi
  edict_t *m_pPev; // ecx

  v2 = FOV;
  if ( FOV == 0 )
    v2 = g_pGameRules->DefaultFOV(this: g_pGameRules);
  v4 = v2;
  if ( this->m_iDefaultFOV.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iDefaultFOV.m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC50u);
      this->m_iDefaultFOV.m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0C20
// Name: public: void CBasePlayer::ActivateMovementConstraint(class CBaseEntity __near *,class Vector const __near &,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ActivateMovementConstraint(
        CBasePlayer *this,
        CBaseEntity *pEntity,
        const Vector *vecCenter,
        float flRadius,
        float flConstraintWidth,
        float flSpeedFactor,
        bool constraintPastRadius)
{
  edict_t *m_pPev; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  edict_t *v11; // ecx
  CNetworkVarBase<bool,CBasePlayer::NetworkVar_m_bConstraintPastRadius> *p_m_bConstraintPastRadius; // esi
  edict_t *v13; // ecx

  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hConstraintEntity>::Set(
    this: &this->m_hConstraintEntity,
    val: pEntity);
  if ( vecCenter->x != this->m_vecConstraintCenter.m_Value.x
    || vecCenter->y != this->m_vecConstraintCenter.m_Value.y
    || vecCenter->z != this->m_vecConstraintCenter.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xF68u);
    }
    this->m_vecConstraintCenter.m_Value = *vecCenter;
  }
  if ( this->m_flConstraintRadius.m_Value != flRadius )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0xF74u);
    }
    this->m_flConstraintRadius.m_Value = flRadius;
  }
  if ( this->m_flConstraintWidth.m_Value != flConstraintWidth )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0xF78u);
    }
    this->m_flConstraintWidth.m_Value = flConstraintWidth;
  }
  if ( this->m_flConstraintSpeedFactor.m_Value != flSpeedFactor )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0xF7Cu);
    }
    this->m_flConstraintSpeedFactor.m_Value = flSpeedFactor;
  }
  p_m_bConstraintPastRadius = &this->m_bConstraintPastRadius;
  if ( this->m_bConstraintPastRadius.m_Value != constraintPastRadius )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bConstraintPastRadius->m_Value = constraintPastRadius;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0xF80u);
      p_m_bConstraintPastRadius->m_Value = constraintPastRadius;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0DC0
// Name: public: void CBasePlayer::DeactivateMovementConstraint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::DeactivateMovementConstraint(CBasePlayer *this)
{
  unsigned int m_Index; // eax
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx

  m_Index = this->m_hConstraintEntity.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xF64u);
    }
    this->m_hConstraintEntity.m_Value.m_Index = -1;
  }
  if ( this->m_flConstraintRadius.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0xF74u);
    }
    this->m_flConstraintRadius.m_Value = 0.0;
  }
  if ( vec3_origin.x != this->m_vecConstraintCenter.m_Value.x
    || vec3_origin.y != this->m_vecConstraintCenter.m_Value.y
    || vec3_origin.z != this->m_vecConstraintCenter.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0xF68u);
    }
    this->m_vecConstraintCenter.m_Value = vec3_origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0F00
// Name: public: virtual void CBasePlayer::EquipSuit(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::EquipSuit(CBasePlayer *this, bool bPlayEffects)
{
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bWearingSuit> *p_m_bWearingSuit; // esi

  p_m_bWearingSuit = &this->m_Local.m_bWearingSuit;
  if ( !this->m_Local.m_bWearingSuit.m_Value )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: p_m_bWearingSuit);
    p_m_bWearingSuit->m_Value = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0F30
// Name: public: virtual void CBasePlayer::RemoveSuit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::RemoveSuit(CBasePlayer *this)
{
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bWearingSuit> *p_m_bWearingSuit; // esi

  p_m_bWearingSuit = &this->m_Local.m_bWearingSuit;
  if ( this->m_Local.m_bWearingSuit.m_Value )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: p_m_bWearingSuit);
    p_m_bWearingSuit->m_Value = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0F60
// Name: public: void CBasePlayer::InputSetHealth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::InputSetHealth(CBasePlayer *this, inputdata_t *inputdata)
{
  const char *pszValue; // esi
  int m_Value; // ecx
  int v5; // ebx
  CNetworkVarBase<int,CBasePlayer::NetworkVar_m_ArmorValue> *p_m_ArmorValue; // esi
  const CTakeDamageInfo *v7; // eax
  CTakeDamageInfo v8; // [esp+20h] [ebp-5Ch] BYREF
  int armor; // [esp+84h] [ebp+8h]

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  m_Value = this->m_iHealth.m_Value;
  v5 = abs32(this->m_iHealth.m_Value - (_DWORD)pszValue);
  if ( (int)pszValue <= m_Value )
  {
    if ( (int)pszValue < m_Value )
    {
      p_m_ArmorValue = &this->m_ArmorValue;
      armor = this->m_ArmorValue.m_Value;
      if ( armor != 0 )
      {
        this->NetworkStateChanged_m_ArmorValue(this, a2: &this->m_ArmorValue);
        p_m_ArmorValue->m_Value = 0;
      }
      v7 = CTakeDamageInfo::CTakeDamageInfo(
             this: &v8,
             pInflictor: this,
             pAttacker: this,
             flDamage: (float)v5,
             bitsDamageType: 0,
             iKillType: 0,
             iObjectsPenetrated: 0);
      CBaseEntity::TakeDamage(this, a2: (int)p_m_ArmorValue, inputInfo: v7);
      if ( p_m_ArmorValue->m_Value != armor )
      {
        this->NetworkStateChanged_m_ArmorValue(this, a2: &this->m_ArmorValue);
        p_m_ArmorValue->m_Value = armor;
      }
    }
  }
  else
  {
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->TakeHealth)(a1: this, a2: (float)v5, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C1030
// Name: public: void CBasePlayer::InputSetHUDVisibility(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::InputSetHUDVisibility(CBasePlayer *this, inputdata_t *inputdata)
{
  int m_Value; // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *p_m_iHideHUD; // edi
  unsigned int v4; // esi

  if ( inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal )
  {
    m_Value = this->m_Local.m_iHideHUD.m_Value;
    p_m_iHideHUD = &this->m_Local.m_iHideHUD;
    v4 = m_Value & 0xFFFFFFFB;
  }
  else
  {
    m_Value = this->m_Local.m_iHideHUD.m_Value;
    p_m_iHideHUD = &this->m_Local.m_iHideHUD;
    v4 = m_Value | 4;
  }
  if ( m_Value != v4 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *, CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *))p_m_iHideHUD[-15].m_Value)(
      a1: p_m_iHideHUD - 15,
      a2: p_m_iHideHUD);
    p_m_iHideHUD->m_Value = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C1080
// Name: public: void CBasePlayer::InitPostProcessController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::InitPostProcessController(CBasePlayer *this)
{
  unsigned int m_Index; // eax

  m_Index = PostProcessSystem()->m_hMasterController.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    CNetworkHandleBase<CPostProcessController,CBasePlayer::NetworkVar_m_hPostProcessCtrl>::Set(
      this: &this->m_hPostProcessCtrl,
      val: nullptr);
  else
    CNetworkHandleBase<CPostProcessController,CBasePlayer::NetworkVar_m_hPostProcessCtrl>::Set(
      this: &this->m_hPostProcessCtrl,
      val: (const CPostProcessController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x101C10D0
// Name: public: void CBasePlayer::InitColorCorrectionController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::InitColorCorrectionController(CBasePlayer *this)
{
  unsigned int m_Index; // eax

  m_Index = ColorCorrectionSystem()->m_hMasterController.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    CNetworkHandleBase<CColorCorrection,CBasePlayer::NetworkVar_m_hColorCorrectionCtrl>::Set(
      this: &this->m_hColorCorrectionCtrl,
      val: nullptr);
  else
    CNetworkHandleBase<CColorCorrection,CBasePlayer::NetworkVar_m_hColorCorrectionCtrl>::Set(
      this: &this->m_hColorCorrectionCtrl,
      val: (const CColorCorrection *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x101C1120
// Name: public: void CBasePlayer::SetViewEntity(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetViewEntity(CBasePlayer *this, CBaseEntity *pEntity, bool bShouldDrawPlayer)
{
  edict_t *m_pPev; // ecx
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *m_pEntity; // eax

  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hViewEntity>::Set(this: &this->m_hViewEntity, val: pEntity);
  if ( this->m_bShouldDrawPlayerWhileUsingViewEntity.m_Value != bShouldDrawPlayer )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xF60u);
    }
    this->m_bShouldDrawPlayerWhileUsingViewEntity.m_Value = bShouldDrawPlayer;
  }
  m_Index = this->m_hViewEntity.m_Value.m_Index;
  if ( m_Index != -1
    && (v6 = (unsigned __int16)m_Index,
        v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v8 = HIWORD(m_Index),
        v7->m_SerialNumber == v8)
    && v7->m_pEntity != nullptr )
  {
    v9 = v6;
    v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
    v11 = &g_pEntityList->m_EntPtrArray[v9];
    if ( v10 )
      m_pEntity = v11->m_pEntity;
    else
      m_pEntity = nullptr;
    engine->SetView(this: engine, a2: this->m_Network.m_pPev, a3: (const edict_t *)m_pEntity[6].__vftable);
  }
  else
  {
    engine->SetView(this: engine, a2: this->m_Network.m_pPev, a3: this->m_Network.m_pPev);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C11F0
// Name: public: virtual void CPlayerInfo::RunPlayerMove(class CBotCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerInfo::RunPlayerMove(CPlayerInfo *this, CBotCmd *ucmd)
{
  int buttons; // ecx
  int command_number; // edx
  float sidemove; // xmm0_4
  float upmove; // xmm0_4
  float x; // xmm0_4
  int random_seed; // ecx
  int tick_count; // edx
  float z; // xmm0_4
  int weaponselect; // ecx
  int weaponsubtype; // edx
  CBasePlayer *m_pParent; // esi
  int v14; // ebx
  CBaseEdict *v15; // ecx
  IMoveHelper *v16; // eax
  CBasePlayer_vtbl *v17; // esi
  IMoveHelper *v18; // eax
  IMoveHelper *v19; // eax
  CUserCmd cmd; // [esp+4h] [ebp-5Ch] BYREF
  float flOldCurtime; // [esp+5Ch] [ebp-4h]
  float flOldFrametime; // [esp+68h] [ebp+8h]

  if ( this->m_pParent->IsBot(this: this->m_pParent) )
  {
    buttons = ucmd->buttons;
    command_number = ucmd->command_number;
    memset((void *)&cmd.headangles, 0, 24);
    cmd.forwardmove = ucmd->forwardmove;
    sidemove = ucmd->sidemove;
    cmd.buttons = buttons;
    LOBYTE(buttons) = ucmd->hasbeenpredicted;
    cmd.command_number = command_number;
    LOBYTE(command_number) = ucmd->impulse;
    cmd.sidemove = sidemove;
    upmove = ucmd->upmove;
    cmd.hasbeenpredicted = buttons;
    LOWORD(buttons) = ucmd->mousedx;
    cmd.impulse = command_number;
    LOWORD(command_number) = ucmd->mousedy;
    cmd.upmove = upmove;
    x = ucmd->viewangles.x;
    cmd.mousedx = buttons;
    random_seed = ucmd->random_seed;
    cmd.mousedy = command_number;
    tick_count = ucmd->tick_count;
    cmd.viewangles.x = x;
    cmd.viewangles.y = ucmd->viewangles.y;
    z = ucmd->viewangles.z;
    cmd.random_seed = random_seed;
    weaponselect = ucmd->weaponselect;
    cmd.tick_count = tick_count;
    weaponsubtype = ucmd->weaponsubtype;
    cmd.viewangles.z = z;
    cmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
    cmd.weaponselect = weaponselect;
    cmd.weaponsubtype = weaponsubtype;
    flOldFrametime = gpGlobals->frametime;
    flOldCurtime = gpGlobals->curtime;
    m_pParent = this->m_pParent;
    v14 = (int)(float)((float)(flOldCurtime / gpGlobals->interval_per_tick) + 0.5);
    if ( m_pParent->m_nTickBase.m_Value != v14 )
    {
      if ( m_pParent->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&m_pParent->m_Network + 76) |= 1u;
      }
      else
      {
        v15 = &m_pParent->m_Network.m_pPev->CBaseEdict;
        if ( v15 != nullptr )
          CBaseEdict::StateChanged(this: v15, offset: 0xF2Cu);
      }
      m_pParent->m_nTickBase.m_Value = v14;
    }
    v16 = MoveHelperServer();
    v16->SetHost(this: v16, a2: this->m_pParent);
    v17 = this->m_pParent->__vftable;
    v18 = MoveHelperServer();
    v17->PlayerRunCommand(this: this->m_pParent, a2: &cmd, a3: v18);
    CUserCmd::operator=(this: &this->m_pParent->m_LastCmd, src: &cmd);
    this->m_pParent->pl.fixangle = 0;
    gpGlobals->frametime = flOldFrametime;
    gpGlobals->curtime = flOldCurtime;
    v19 = MoveHelperServer();
    v19->SetHost(this: v19, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C49F0
// Name: public: virtual void CBasePlayer::RemoveAllItems(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::RemoveAllItems(CBasePlayer *this, bool removeSuit)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
  {
    CBasePlayer::ResetAutoaim(this);
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    ActiveWeapon->Holster(this: ActiveWeapon, a2: nullptr);
  }
  this->Weapon_SetLast(this, a2: nullptr);
  this->RemoveAllWeapons(this);
  CBaseCombatCharacter::RemoveAllAmmo(this);
  if ( removeSuit )
    this->RemoveSuit(this);
  this->UpdateClientData(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C4A60
// Name: private: void CBasePlayer::ReplaceContextCommands(class CCommandContext __near *,class CUserCmd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ReplaceContextCommands(
        CBasePlayer *this,
        CCommandContext *ctx,
        CUserCmd *pCommands,
        int nCommands)
{
  int v5; // edi
  int v6; // ebx
  int v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUserCmd *m_pMemory; // ecx
  int v11; // eax
  CUserCmd *v12; // edi
  const CUserCmd *ctxa; // [esp+14h] [ebp+8h]

  v5 = ctx->cmds.m_Size - 1;
  if ( v5 >= 0 )
  {
    v6 = v5;
    do
    {
      ((void (__thiscall *)(CUserCmd *, _DWORD))ctx->cmds.m_Memory.m_pMemory[v6].dtr_CUserCmd)(
        a1: &ctx->cmds.m_Memory.m_pMemory[v6],
        a2: 0);
      --v6;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v7 = nCommands - 1;
  ctx->cmds.m_Size = 0;
  ctx->numcmds = nCommands;
  ctx->totalcmds = nCommands;
  ctx->dropped_packets = 0;
  if ( nCommands - 1 >= 0 )
  {
    ctxa = &pCommands[v7];
    do
    {
      m_Size = ctx->cmds.m_Size;
      m_nAllocationCount = ctx->cmds.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CUserCmd,int>::Grow(this: &ctx->cmds.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++ctx->cmds.m_Size;
      m_pMemory = ctx->cmds.m_Memory.m_pMemory;
      v11 = ctx->cmds.m_Size - m_Size - 1;
      ctx->cmds.m_pElements = ctx->cmds.m_Memory.m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: (void *)&m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 88 * v11);
      v12 = &ctx->cmds.m_Memory.m_pMemory[m_Size];
      if ( v12 != nullptr )
      {
        v12->__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
        CUserCmd::operator=(this: v12, src: ctxa);
      }
      --ctxa;
      --v7;
    }
    while ( v7 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C4B20
// Name: public: void CBasePlayer::OnTonemapTriggerStartTouch(class CTonemapTrigger __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::OnTonemapTriggerStartTouch(CBasePlayer *this, unsigned int pTonemapTrigger)
{
  unsigned int v2; // edi
  int v3; // ebx
  int v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<CTonemapTrigger> *m_pMemory; // ecx
  int v9; // eax
  CHandle<CTonemapTrigger> *v10; // eax

  v2 = pTonemapTrigger;
  v3 = -1;
  if ( pTonemapTrigger != 0 )
    pTonemapTrigger = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)pTonemapTrigger + 8))(a1: pTonemapTrigger);
  else
    pTonemapTrigger = -1;
  v5 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_hTriggerTonemapList,
         src: (CHandle<CBaseEntity> *)&pTonemapTrigger);
  if ( v5 != -1 )
  {
    if ( this->m_hTriggerTonemapList.m_Size - v5 - 1 > 0 )
      _V_memmove(
        dest: &this->m_hTriggerTonemapList.m_Memory.m_pMemory[v5],
        src: &this->m_hTriggerTonemapList.m_Memory.m_pMemory[v5 + 1],
        count: 4 * (this->m_hTriggerTonemapList.m_Size - v5 - 1));
    --this->m_hTriggerTonemapList.m_Size;
  }
  if ( v2 != 0 )
    v3 = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 8))(a1: v2);
  m_Size = this->m_hTriggerTonemapList.m_Size;
  m_nAllocationCount = this->m_hTriggerTonemapList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hTriggerTonemapList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_hTriggerTonemapList.m_Size;
  m_pMemory = this->m_hTriggerTonemapList.m_Memory.m_pMemory;
  v9 = this->m_hTriggerTonemapList.m_Size - m_Size - 1;
  this->m_hTriggerTonemapList.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_hTriggerTonemapList.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    v10->m_Index = v3;
}

//------------------------------------------------------------------------------
// Address: 0x101C4C10
// Name: public: virtual void CBasePlayer::PostThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::PostThink(CBasePlayer *this)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // eax
  unsigned int v12; // eax
  IHandleEntity *v13; // ecx
  CNetworkVarBase<float,CPlayerLocalData::NetworkVar_m_flFallVelocity> *p_m_flFallVelocity; // edi
  const Vector *AbsOrigin; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  edict_t *m_pPev; // ecx
  QAngle *v19; // ebx
  int v20; // edi
  int Index; // eax
  float m_fTimeLastHurt; // xmm0_4
  int m_Value; // [esp+0h] [ebp-30h]
  QAngle result; // [esp+20h] [ebp-10h] BYREF
  color32_s hurtScreenOverlay; // [esp+2Ch] [ebp-4h] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  v2 = (float)(this->m_vecSmoothedVelocity.y * 0.89999998) + (float)(this->m_vecAbsVelocity.y * 0.1);
  v3 = (float)(this->m_vecAbsVelocity.z * 0.1) + (float)(this->m_vecSmoothedVelocity.z * 0.89999998);
  this->m_vecSmoothedVelocity.x = (float)(this->m_vecSmoothedVelocity.x * 0.89999998)
                                + (float)(this->m_vecAbsVelocity.x * 0.1);
  this->m_vecSmoothedVelocity.y = v2;
  this->m_vecSmoothedVelocity.z = v3;
  this->UpdateTonemapController(this);
  CBasePlayer::UpdateFXVolume(this);
  if ( g_fGameOver || this->m_iPlayerLocked != 0 )
  {
    this->ItemPostFrame(this);
  }
  else
  {
    if ( this->IsAlive(this) )
    {
      this->UpdateCollisionBounds(this);
      m_Index = this->m_hUseEntity.m_Value.m_Index;
      if ( m_Index != -1 )
      {
        v5 = (unsigned __int16)m_Index;
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v7 = HIWORD(m_Index);
        if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
        {
          v8 = v5;
          v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
          v10 = &g_pEntityList->m_EntPtrArray[v8];
          if ( v9 )
            m_pEntity = v10->m_pEntity;
          else
            m_pEntity = nullptr;
          if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *, CBasePlayer *))m_pEntity->__vftable[27].SetRefEHandle)(
                 a1: m_pEntity,
                 a2: this) != 0
            && (CBaseCombatCharacter::GetActiveWeapon(this) == nullptr
             || (CBaseCombatCharacter::GetActiveWeapon(this)->m_fEffects.m_Value & 0x20) != 0
             || CBaseCombatCharacter::GetActiveWeapon(this)->m_Activity == ACT_VM_HOLSTER) )
          {
            v12 = this->m_hUseEntity.m_Value.m_Index;
            if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
              v13 = nullptr;
            else
              v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
            ((void (__stdcall *)(CBasePlayer *, CBasePlayer *, int, int))v13->__vftable[33].dtr_IHandleEntity)(
              a1: this,
              a2: this,
              a3: 2,
              a4: 0x40000000);
          }
          else
          {
            CBasePlayer::ClearUseEntity(this);
          }
        }
      }
      this->ItemPostFrame(this);
      if ( (this->m_fFlags.m_Value & 1) != 0 )
      {
        p_m_flFallVelocity = &this->m_Local.m_flFallVelocity;
        if ( this->m_Local.m_flFallVelocity.m_Value > 64.0
          && !g_pGameRules->IsMultiplayer(this: g_pGameRules)
          && gpGlobals->frametime > 0.0 )
        {
          m_Value = (int)p_m_flFallVelocity->m_Value;
          AbsOrigin = CBaseEntity::GetAbsOrigin(this);
          CSoundEnt::InsertSound(
            iType: 4,
            vecOrigin: AbsOrigin,
            iVolume: m_Value,
            flDuration: 0.2,
            pOwner: this,
            soundChannelIndex: 0,
            pSoundTarget: nullptr);
        }
        if ( p_m_flFallVelocity->m_Value != 0.0 )
        {
          this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_flFallVelocity);
          p_m_flFallVelocity->m_Value = 0.0;
        }
      }
      if ( this->IsInAVehicle(this) )
      {
        this->SetAnimation(this, a2: PLAYER_IN_VEHICLE);
      }
      else
      {
        if ( (this->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
        if ( this->m_vecAbsVelocity.x == 0.0 && CBaseEntity::GetAbsVelocity(this)->y == 0.0 )
        {
          this->SetAnimation(this, a2: PLAYER_IDLE);
        }
        else if ( (CBaseEntity::GetAbsVelocity(this)->x != 0.0 || CBaseEntity::GetAbsVelocity(this)->y != 0.0)
               && (this->m_fFlags.m_Value & 1) != 0
               || this->m_nWaterLevel.m_Value > 1u )
        {
          this->SetAnimation(this, a2: PLAYER_WALK);
        }
      }
    }
    else
    {
      this->m_nImpulse = 0;
    }
    if ( this->m_nSequence.m_Value == -1 )
      CBaseAnimating::SetSequence(this, nSequence: 0);
    this->StudioFrameAdvance(this);
    this->DispatchAnimEvents(this, a2: this);
    v17 = this->m_flSimulationTime.m_Value;
    hurtScreenOverlay = LODWORD(gpGlobals->curtime);
    v16 = *(float *)&hurtScreenOverlay;
    if ( v17 != *(float *)&hurtScreenOverlay )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x68u);
          v16 = *(float *)&hurtScreenOverlay;
        }
      }
      this->m_flSimulationTime.m_Value = v16;
    }
    this->Weapon_FrameUpdate(this);
    this->UpdatePlayerSound(this);
    if ( this->m_bForceOrigin )
    {
      CBaseEntity::SetLocalOrigin(this, origin: &this->m_vForcedOrigin);
      CBaseEntity::SetLocalAngles(this, angles: &this->m_Local.m_vecPunchAngle.m_Value);
      v19 = RandomAngle(&result, minVal: -25.0, maxVal: 25.0);
      if ( v19->x != this->m_Local.m_vecPunchAngle.m_Value.x
        || v19->y != this->m_Local.m_vecPunchAngle.m_Value.y
        || v19->z != this->m_Local.m_vecPunchAngle.m_Value.z )
      {
        this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_vecPunchAngle);
        this->m_Local.m_vecPunchAngle.m_Value.x = v19->x;
        this->m_Local.m_vecPunchAngle.m_Value.y = v19->y;
        this->m_Local.m_vecPunchAngle.m_Value.z = v19->z;
      }
      if ( this->m_Local.m_vecPunchAngleVel.m_Value.x != 0.0
        || this->m_Local.m_vecPunchAngleVel.m_Value.y != 0.0
        || this->m_Local.m_vecPunchAngleVel.m_Value.z != 0.0 )
      {
        this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_vecPunchAngleVel);
        this->m_Local.m_vecPunchAngleVel.m_Value.x = 0.0;
        this->m_Local.m_vecPunchAngleVel.m_Value.y = 0.0;
        this->m_Local.m_vecPunchAngleVel.m_Value.z = 0.0;
      }
    }
    CBasePlayer::PostThinkVPhysics(this);
  }
  CBasePlayer::SimulatePlayerSimulatedEntities(this);
  if ( this->IsAlive(this) )
  {
    v20 = this->m_iHealth.m_Value;
    if ( v20 < this->GetMaxHealth(this) )
    {
      Index = GlobalEntity_GetIndex(pGlobalname: "player_regenerates_health");
      if ( GlobalEntity_GetState(globalIndex: Index) != GLOBAL_OFF )
      {
        m_fTimeLastHurt = this->m_fTimeLastHurt;
        *(float *)&hurtScreenOverlay = 2.0000153;
        if ( gpGlobals->curtime <= (float)(m_fTimeLastHurt + sv_regeneration_wait_time.m_pParent->m_Value.m_fValue) )
          UTIL_ScreenFade(pEntity: this, color: &hurtScreenOverlay, fadeTime: 1.0, fadeHold: 0.1, flags: 17);
        else
          ((void (__thiscall *)(CBasePlayer *, int, _DWORD))this->TakeHealth)(a1: this, a2: 1065353216, a3: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C51B0
// Name: public: virtual void CBasePlayer::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Spawn(CBasePlayer *this)
{
  CHintSystem *v2; // eax
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  int v5; // ebx
  unsigned int m_Index; // eax
  const CFogController *m_pEntity; // eax
  unsigned int v8; // eax
  const CPostProcessController *v9; // ecx
  edict_t *v10; // ecx
  CBasePlayer_vtbl *v11; // edi
  const CViewVectors *v12; // eax
  void (__thiscall *SetPlayerUnderwater)(CBasePlayer *, bool); // edx
  int m_nValue; // ebx
  edict_t *v15; // ecx
  edict_t *v16; // ecx
  void (__thiscall *UpdateClientData)(CBasePlayer *); // edx
  bool v18; // zf
  CBasePlayer_vtbl *v19; // eax
  edict_t *v20; // ecx
  IGameEvent *v21; // edi
  int v22; // eax
  int v23; // [esp+38h] [ebp-3Ch]
  CSingleUserRecipientFilter user; // [esp+48h] [ebp-2Ch] BYREF
  _DWORD v25[2]; // [esp+68h] [ebp-Ch] BYREF
  color32_s nothing; // [esp+70h] [ebp-4h] BYREF
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  if ( this->Hints(this) != nullptr )
  {
    v2 = this->Hints(this);
    CHintSystem::ResetHints(this: v2);
  }
  CBaseEntity::SetClassname(this, className: "player");
  this->SharedSpawn(this);
  if ( !this->m_bSimulatedEveryTick.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1F5u);
    }
    this->m_bSimulatedEveryTick.m_Value = true;
  }
  if ( !this->m_bAnimatedEveryTick.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x1F6u);
    }
    this->m_bAnimatedEveryTick.m_Value = true;
  }
  v5 = this->SpawnArmorValue(this);
  if ( this->m_ArmorValue.m_Value != v5 )
  {
    this->NetworkStateChanged_m_ArmorValue(this, a2: &this->m_ArmorValue);
    this->m_ArmorValue.m_Value = v5;
  }
  CBaseEntity::SetBlocksLOS(this, bBlocksLOS: false);
  if ( this->m_iMaxHealth.m_Value != this->m_iHealth.m_Value )
  {
    this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
    this->m_iMaxHealth.m_Value = this->m_iHealth.m_Value;
  }
  if ( (this->m_fFlags.m_Value & 0x200) != 0 )
  {
    CBaseEntity::ClearFlags(this);
    CBaseEntity::AddFlag(this, flags: 768);
  }
  else
  {
    CBaseEntity::ClearFlags(this);
    CBaseEntity::AddFlag(this, flags: 256);
  }
  CBaseEntity::AddFlag(this, flags: 0x20000);
  v23 = this->m_fEffects.m_Value & 0x10 | 8;
  this->m_AirFinished = gpGlobals->curtime + 12.0;
  this->m_nDrownDmgRate = 2;
  CBaseEntity::SetEffects(this, nEffects: v23);
  if ( this->m_bClientSideRagdoll.m_Value )
  {
    this->NetworkStateChanged_m_bClientSideRagdoll(this, a2: &this->m_bClientSideRagdoll);
    this->m_bClientSideRagdoll.m_Value = false;
  }
  m_Index = FogSystem()->m_hMasterController.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (const CFogController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CNetworkHandleBase<CFogController,fogplayerparams_t::NetworkVar_m_hCtrl>::Set(
    this: &this->m_PlayerFog.m_hCtrl,
    val: m_pEntity);
  v8 = PostProcessSystem()->m_hMasterController.m_Index;
  if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
    v9 = nullptr;
  else
    v9 = (const CPostProcessController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
  CNetworkHandleBase<CPostProcessController,CBasePlayer::NetworkVar_m_hPostProcessCtrl>::Set(
    this: &this->m_hPostProcessCtrl,
    val: v9);
  this->m_DmgTake = 0.0;
  this->m_DmgSave = 0.0;
  this->m_bitsHUDDamage = -1;
  this->m_bitsDamageType = 0;
  if ( this->m_afPhysicsFlags.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0xBFCu);
    }
    this->m_afPhysicsFlags.m_Value = 0;
  }
  this->m_idrownrestored = this->m_idrowndmg;
  CBasePlayer::SetFOV(this, pRequester: this, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
  this->m_flNextDecalTime = 0.0;
  this->m_flgeigerDelay = gpGlobals->curtime + 2.0;
  this->m_flFieldOfView = 0.76599997;
  this->m_vecAdditionalPVSOrigin = vec3_origin;
  this->m_vecCameraPVSOrigin = vec3_origin;
  if ( !this->m_fGameHUDInitialized )
    g_pGameRules->SetDefaultPlayerTeam(this: g_pGameRules, a2: this);
  g_pGameRules->GetPlayerSpawnSpot(this: g_pGameRules, a2: this);
  *(_WORD *)&this->m_bDropEnabled = 257;
  if ( this->m_Local.m_bDucked.m_Value )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bDucked);
    this->m_Local.m_bDucked.m_Value = false;
  }
  if ( this->m_Local.m_bDucking.m_Value )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bDucking);
    this->m_Local.m_bDucking.m_Value = false;
  }
  v11 = this->__vftable;
  v12 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v11->SetViewOffset(this, a2: &v12->m_vView);
  if ( CBaseEntity::IsPrecacheAllowed() )
    this->Precache(this);
  SetPlayerUnderwater = this->SetPlayerUnderwater;
  this->m_bitsDamageType = 0;
  this->m_bitsHUDDamage = -1;
  SetPlayerUnderwater(this, a2: false);
  this->m_iTrain = 192;
  this->m_HackedGunPos.x = 0.0;
  this->m_HackedGunPos.y = 32.0;
  this->m_HackedGunPos.z = 0.0;
  if ( sv_bonus_challenge.m_pParent != nullptr )
    m_nValue = sv_bonus_challenge.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( this->m_iBonusChallenge.m_Value != m_nValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v15 = this->m_Network.m_pPev;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0xC10u);
    }
    this->m_iBonusChallenge.m_Value = m_nValue;
  }
  CCollisionProperty::TestCollision(this: (ConVar *)&sv_bonus_challenge.IConVar, value: 0);
  if ( this->m_iPlayerSound == -1 )
    _Msg(a1: "Couldn't alloc player sound slot!\n");
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->m_iClientBattery = -1;
  this->m_fInitHUD = true;
  this->m_fWeapon = false;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v16 = this->m_Network.m_pPev;
    if ( v16 != nullptr )
    {
      v16->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v16->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  V_strncpy(pDest: this->m_szLastPlaceName.m_Value, pSrc: locale, maxLen: 18);
  CRecipientFilter::CRecipientFilter(this: &user);
  user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &user, player: this);
  enginesound->SetPlayerDSP(this: enginesound, a2: &user, a3: 0, a4: false);
  this->CreateViewModel(this, a2: 0);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 5);
  if ( this->m_iPlayerLocked != 0 )
  {
    this->m_iPlayerLocked = 0;
    CBaseEntity::AddFlag(this, flags: 32832);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    UpdateClientData = this->UpdateClientData;
    this->m_iPlayerLocked = 1;
    UpdateClientData(this);
  }
  v18 = CBaseEntity::GetTeamNumber(this) == 1;
  v19 = this->__vftable;
  if ( v18 )
    v19->StartObserverMode(this, a2: this->m_iObserverLastMode);
  else
    v19->StopObserverMode(this);
  this->StopReplayMode(this);
  nothing = (color32_s)-16777216;
  UTIL_ScreenFade(pEntity: this, color: &nothing, fadeTime: 0.0, fadeHold: 0.0, flags: 17);
  g_pGameRules->PlayerSpawn(this: g_pGameRules, a2: this);
  if ( this->m_flLaggedMovementValue.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v20 = this->m_Network.m_pPev;
      if ( v20 != nullptr )
        CBaseEdict::StateChanged(this: &v20->CBaseEdict, offset: 0xFA4u);
    }
    this->m_flLaggedMovementValue.m_Value = 1.0;
  }
  this->m_vecSmoothedVelocity = vec3_origin;
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  this->InitVCollision(this, a2: &this->m_vecAbsOrigin, a3: &this->m_vecAbsVelocity);
  v21 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_spawn", a3: 0, a4: 0);
  if ( v21 != nullptr )
  {
    v22 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
    v21->SetInt(this: v21, a2: "userid", a3: v22);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v21, a3: false);
  }
  this->RumbleEffect(this, a2: 0, a3: 0, a4: 0);
  this->m_nVehicleViewSavedFrame = 0;
  this->m_movementCollisionNormal.x = 0.0;
  this->m_movementCollisionNormal.y = 0.0;
  this->m_movementCollisionNormal.z = 1.0;
  this->UpdateLastKnownArea(this);
  CBaseCombatCharacter::Spawn(this);
  this->UpdateLastKnownArea(this);
  if ( !g_pGameRules->IsMultiplayer(this: g_pGameRules) && g_pScriptVM != nullptr )
  {
    v25[0] = CBaseEntity::GetScriptInstance(this);
    v25[1] = 33;
    g_pScriptVM->SetValue(this: g_pScriptVM, a2: nullptr, a3: "player", a4: (const ScriptVariant_t *)v25);
  }
  CRecipientFilter::~CRecipientFilter(this: &user);
}

//------------------------------------------------------------------------------
// Address: 0x101C5930
// Name: public: virtual void CBasePlayer::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::OnRestore(CBasePlayer *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // eax
  int m_Value; // eax
  int v5; // ebx
  edict_t *m_pPev; // ecx
  bool v7; // zf
  CStudioHdr *m_pStudioHdr; // eax
  _DWORD v9[2]; // [esp+4h] [ebp-8h] BYREF

  CBaseAnimatingOverlay::OnRestore(this);
  m_Index = this->m_hViewEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CBasePlayer::SetViewEntity(
    this,
    pEntity: m_pEntity,
    bShouldDrawPlayer: this->m_bShouldDrawPlayerWhileUsingViewEntity.m_Value);
  m_Value = this->m_iDefaultFOV.m_Value;
  if ( m_Value == 0 )
    m_Value = g_pGameRules->DefaultFOV(this: g_pGameRules);
  v5 = m_Value;
  if ( this->m_iDefaultFOV.m_Value != m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC50u);
    }
    this->m_iDefaultFOV.m_Value = v5;
  }
  v7 = this->m_pStudioHdr == nullptr;
  this->m_nVehicleViewSavedFrame = 0;
  if ( v7 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  this->m_nBodyPitchPoseParam = CBaseAnimating::LookupPoseParameter(
                                  this,
                                  pStudioHdr: m_pStudioHdr,
                                  szName: "body_pitch");
  if ( gpGlobals->eLoadType == MapLoad_Transition )
  {
    v9[0] = CBaseEntity::GetScriptInstance(this);
    v9[1] = 33;
    g_pScriptVM->SetValue(this: g_pScriptVM, a2: nullptr, a3: "player", a4: (const ScriptVariant_t *)v9);
    *(_WORD *)&this->m_bDropEnabled = 257;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C5A60
// Name: public: virtual void CBasePlayer::LeaveVehicle(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBasePlayer::LeaveVehicle(
        CBasePlayer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const Vector *vecExitPoint,
        const QAngle *vecExitAngles)
{
  unsigned int m_Index; // eax
  IServerVehicle *v7; // edi
  int (__thiscall *GetPassengerRole)(struct IServerVehicle *, CBaseCombatCharacter *); // edx
  int v9; // ebx
  void (__thiscall *SetParent)(CBaseEntity *, CBaseEntity *, int); // edx
  float z; // ecx
  unsigned int v12; // edx
  float v13; // eax
  float x; // xmm0_4
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_iHideHUD> *p_m_iHideHUD; // ebx
  int m_Value; // eax
  unsigned int v17; // edi
  unsigned int v18; // edi
  unsigned int v19; // edx
  edict_t *m_pPev; // ecx
  IPhysicsObject *m_pPhysicsObject; // ecx
  unsigned int v22; // eax
  edict_t *v23; // ecx
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseCombatWeapon *v25; // eax
  unsigned int v26; // edi
  Vector vNewPos; // [esp+4h] [ebp-20h] BYREF
  QAngle qAngles; // [esp+10h] [ebp-14h] BYREF
  int nRole; // [esp+1Ch] [ebp-8h]
  IServerVehicle *pVehicle; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF
  const Vector *vecExitPointa; // [esp+2Ch] [ebp+8h]

  m_Index = this->m_hVehicle.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v7 = (IServerVehicle *)((int (__thiscall *)(CBasePlayer *, int, int))this->GetVehicle)(a1: this, a2: a3, a3: a2);
    GetPassengerRole = v7->GetPassengerRole;
    pVehicle = v7;
    v9 = GetPassengerRole(this: v7, a2: this);
    SetParent = this->SetParent;
    nRole = v9;
    SetParent(this, a2: nullptr, a3: -1);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    z = this->m_vecAbsOrigin.z;
    v12 = (unsigned int)this->m_iEFlags >> 11;
    *(_QWORD *)&vNewPos.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    vNewPos.z = z;
    if ( (v12 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v13 = this->m_angAbsRotation.z;
    *(_QWORD *)&qAngles.x = *(_QWORD *)&this->m_angAbsRotation.x;
    x = vecExitPoint->x;
    qAngles.z = v13;
    if ( vec3_origin.x == x && vec3_origin.y == vecExitPoint->y && vec3_origin.z == vecExitPoint->z )
    {
      v7->GetPassengerExitPoint(this: v7, a2: v9, a3: &vNewPos, a4: &qAngles);
    }
    else
    {
      vNewPos.x = x;
      vNewPos.y = vecExitPoint->y;
      vNewPos.z = vecExitPoint->z;
      qAngles = *vecExitAngles;
    }
    this->OnVehicleEnd(this, a2: &vNewPos);
    CBaseEntity::SetAbsOrigin(this, absOrigin: &vNewPos);
    CBaseEntity::SetAbsAngles(this, absAngles: &qAngles);
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    this->pl.v_angle.x = qAngles.x;
    this->pl.v_angle.y = qAngles.y;
    this->pl.v_angle.z = 0.0;
    p_m_iHideHUD = &this->m_Local.m_iHideHUD;
    this->pl.fixangle = 1;
    m_Value = this->m_Local.m_iHideHUD.m_Value;
    v17 = m_Value & 0xFFFFFFFE;
    qAngles.z = 0.0;
    if ( m_Value != (m_Value & 0xFFFFFFFE) )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_iHideHUD);
      p_m_iHideHUD->m_Value = v17;
    }
    v18 = p_m_iHideHUD->m_Value & 0xFFFFFBFF;
    if ( p_m_iHideHUD->m_Value != v18 )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_iHideHUD);
      p_m_iHideHUD->m_Value = v18;
    }
    v19 = this->m_fEffects.m_Value & 0xFFFFFFDF;
    vecExitPointa = (const Vector *)v19;
    if ( this->m_fEffects.m_Value != v19 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
          v19 = (unsigned int)vecExitPointa;
        }
      }
      this->m_fEffects.m_Value = v19;
    }
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_WALK, moveCollide: MOVECOLLIDE_DEFAULT);
    CBaseEntity::SetCollisionGroup(this, collisionGroup: 5);
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
      m_pPhysicsObject->SetPosition(this: m_pPhysicsObject, a2: &vNewPos, a3: &vec3_angle, a4: true);
    v22 = this->m_hVehicle.m_Value.m_Index;
    if ( v22 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_SerialNumber == HIWORD(v22)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_pEntity != nullptr )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v23 = this->m_Network.m_pPev;
        if ( v23 != nullptr )
          CBaseEdict::StateChanged(this: &v23->CBaseEdict, offset: 0xC00u);
      }
      this->m_hVehicle.m_Value.m_Index = -1;
    }
    pVehicle->SetPassenger(this: pVehicle, a2: nRole, a3: nullptr);
    if ( this->IsAlive(this) && CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
      if ( !ActiveWeapon->IsWeaponVisible(this: ActiveWeapon) )
      {
        v25 = CBaseCombatCharacter::GetActiveWeapon(this);
        v25->Deploy(this: v25);
        v26 = p_m_iHideHUD->m_Value & 0xFFFFFEFF;
        if ( p_m_iHideHUD->m_Value != v26 )
        {
          this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_iHideHUD);
          p_m_iHideHUD->m_Value = v26;
        }
      }
    }
    ((void (__thiscall *)(CBasePlayer *, _DWORD))this->RumbleEffect)(a1: this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C5DC0
// Name: public: virtual bool CBasePlayer::RemovePlayerItem(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePlayer::RemovePlayerItem(CBasePlayer *this, CBaseCombatWeapon *pItem)
{
  unsigned int m_Index; // ecx
  CBaseCombatWeapon *m_pEntity; // eax

  if ( CBaseCombatCharacter::GetActiveWeapon(this) == pItem )
  {
    CBasePlayer::ResetAutoaim(this);
    pItem->Holster(this: pItem, a2: nullptr);
    CBaseEntity::SetNextThink(this: pItem, thinkTime: -1.0, szContext: nullptr);
    CBaseEntity::ThinkSet(this: pItem, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
  m_Index = this->m_hLastWeapon.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == pItem )
    this->Weapon_SetLast(this, a2: nullptr);
  return CBaseCombatCharacter::Weapon_Detach(this, pWeapon: pItem);
}

//------------------------------------------------------------------------------
// Address: 0x101C5E60
// Name: public: virtual void CBasePlayer::GetAutoaimVector(struct autoaim_params_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::GetAutoaimVector(CBasePlayer *this, autoaim_params_t *params)
{
  bool (__thiscall *ShouldAutoaim)(CBasePlayer *); // edx
  edict_t *m_pPev; // ecx
  float x; // xmm1_4
  float y; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  bool (__thiscall *IsInAVehicle)(CBaseCombatCharacter *); // edx
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // edx
  float *v11; // eax
  const QAngle *(__thiscall *v12)(CBaseEntity *); // eax
  float v13; // xmm3_4
  float v14; // xmm0_4
  float *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  const QAngle *v18; // eax
  Vector vecShootPosition; // [esp+8h] [ebp-30h] BYREF
  Vector v20; // [esp+14h] [ebp-24h] BYREF
  Vector forward; // [esp+20h] [ebp-18h] BYREF
  QAngle angles; // [esp+2Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  *(_WORD *)&params->m_bAutoAimAssisting = 0;
  params->m_hAutoAimEntity.m_Index = -1;
  ShouldAutoaim = this->ShouldAutoaim;
  params->m_vecAutoAimPoint = vec3_invalid;
  if ( !ShouldAutoaim(this) || params->m_fScale == 0.0 )
  {
    v18 = this->EyeAngles(this);
    angles.x = this->m_Local.m_vecPunchAngle.m_Value.x + v18->x;
    angles.y = this->m_Local.m_vecPunchAngle.m_Value.y + v18->y;
    angles.z = this->m_Local.m_vecPunchAngle.m_Value.z + v18->z;
    AngleVectors(&angles, forward: &v20);
    params->m_vecAutoAimDir = v20;
  }
  else
  {
    this->Weapon_ShootPosition(this, result: &vecShootPosition);
    CBasePlayer::AutoaimDeflection(
      this,
      a2: COERCE_FLOAT(&savedregs),
      a3: (int)params,
      a4: (int)this,
      result: &angles,
      vecSrc: &vecShootPosition,
      params);
    if ( !g_pGameRules->AllowAutoTargetCrosshair(this: g_pGameRules) && this->m_fOnTarget.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xBA0u);
      }
      this->m_fOnTarget.m_Value = false;
    }
    x = angles.x;
    if ( angles.x > 180.0 )
    {
      x = angles.x - 360.0;
      angles.x = angles.x - 360.0;
    }
    if ( x < -180.0 )
    {
      x = x + 360.0;
      angles.x = x;
    }
    y = angles.y;
    if ( angles.y > 180.0 )
    {
      y = angles.y - 360.0;
      angles.y = angles.y - 360.0;
    }
    if ( y < -180.0 )
    {
      y = y + 360.0;
      angles.y = y;
    }
    v7 = 25.0;
    if ( x > 25.0 || (v7 = -25.0, x < -25.0) )
      angles.x = v7;
    v8 = 12.0;
    if ( y > 12.0 || (v8 = -12.0, y < -12.0) )
      angles.y = v8;
    IsInAVehicle = this->IsInAVehicle;
    this->m_vecAutoAim.x = 0.0;
    this->m_vecAutoAim.y = 0.0;
    this->m_vecAutoAim.z = 0.0;
    if ( IsInAVehicle(this) && g_pGameRules->GetAutoAimMode(this: g_pGameRules) == 2 )
    {
      EyeAngles = this->EyeAngles;
      this->m_vecAutoAim = angles;
      v11 = (float *)EyeAngles(this);
      angles.x = *v11 + this->m_vecAutoAim.x;
      angles.y = v11[1] + this->m_vecAutoAim.y;
      angles.z = v11[2] + this->m_vecAutoAim.z;
      AngleVectors(&angles, &forward);
    }
    else
    {
      v12 = this->EyeAngles;
      v13 = angles.y * 0.89999998;
      v14 = angles.z * 0.89999998;
      this->m_vecAutoAim.x = angles.x * 0.89999998;
      this->m_vecAutoAim.y = v13;
      this->m_vecAutoAim.z = v14;
      v15 = (float *)v12(this);
      v16 = (float)(this->m_Local.m_vecPunchAngle.m_Value.y + v15[1]) + this->m_vecAutoAim.y;
      v17 = (float)(this->m_Local.m_vecPunchAngle.m_Value.z + v15[2]) + this->m_vecAutoAim.z;
      angles.x = this->m_vecAutoAim.x + (float)(this->m_Local.m_vecPunchAngle.m_Value.x + *v15);
      angles.y = v16;
      angles.z = v17;
      AngleVectors(&angles, &forward);
    }
    params->m_vecAutoAimDir = forward;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C66B0
// Name: private: class CCommandContext __near * CBasePlayer::RemoveAllCommandContextsExceptNewest(void)
// Source: json
//------------------------------------------------------------------------------
CCommandContext *__thiscall CBasePlayer::RemoveAllCommandContextsExceptNewest(CBasePlayer *this)
{
  int v2; // eax

  if ( this->m_CommandContext.m_Size - 1 > 0 )
    CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::RemoveMultiple(
      this: &this->m_CommandContext,
      elem: 0,
      num: this->m_CommandContext.m_Size - 1);
  if ( this->m_CommandContext.m_Size == 0 )
  {
    v2 = CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::InsertBefore(
           this: &this->m_CommandContext,
           elem: this->m_CommandContext.m_Size);
    _V_memset(dest: &this->m_CommandContext.m_Memory.m_pMemory[v2], fill: 0, count: 36);
  }
  return this->m_CommandContext.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x101C6710
// Name: private: void CBasePlayer::AdjustPlayerTimeBase(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::AdjustPlayerTimeBase(CBasePlayer *this, int simulation_ticks)
{
  ConVar *m_pParent; // eax
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *v4; // edi
  int v5; // eax
  CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short> > *p_m_vecPlayerSimInfo; // ecx
  int m_Head; // edi
  CGlobalVars *v8; // ecx
  float v9; // xmm0_4
  int v10; // xmm1_4
  int v11; // esi
  CNetworkVarBase<int,CBasePlayer::NetworkVar_m_nTickBase> *p_m_nTickBase; // ebx
  int v13; // edx
  int v14; // eax
  int v15; // esi
  CNetworkVarBase<int,CBasePlayer::NetworkVar_m_nTickBase> *v16; // eax
  CBaseEdict *m_Value; // ecx
  CPlayerSimInfo *pi; // [esp+8h] [ebp-4h]

  if ( simulation_ticks >= 0 )
  {
    m_pParent = sv_playerperfhistorycount.m_pParent;
    v4 = nullptr;
    pi = nullptr;
    if ( sv_playerperfhistorycount.m_pParent != nullptr && sv_playerperfhistorycount.m_pParent->m_Value.m_nValue > 0 )
    {
      while ( 1 )
      {
        v5 = m_pParent != nullptr ? m_pParent->m_Value.m_nValue : 0;
        p_m_vecPlayerSimInfo = &this->m_vecPlayerSimInfo;
        if ( this->m_vecPlayerSimInfo.m_ElementCount <= v5 )
          break;
        m_Head = this->m_vecPlayerSimInfo.m_Head;
        CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::Unlink(
          this: p_m_vecPlayerSimInfo,
          elem: this->m_vecPlayerSimInfo.m_Head);
        this->m_vecPlayerSimInfo.m_Memory.m_pMemory[m_Head].m_Next = this->m_vecPlayerSimInfo.m_FirstFree;
        this->m_vecPlayerSimInfo.m_FirstFree = m_Head;
        m_pParent = sv_playerperfhistorycount.m_pParent;
      }
      v4 = &this->m_vecPlayerSimInfo.m_Memory.m_pMemory[(unsigned __int16)CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::AddToTail(this: p_m_vecPlayerSimInfo)];
      pi = &v4->m_Element;
    }
    v8 = gpGlobals;
    if ( !this->m_bPredictionEnabled || gpGlobals->maxClients == 1 )
    {
      v15 = gpGlobals->tickcount + gpGlobals->simTicksThisFrame - simulation_ticks;
      p_m_nTickBase = &this->m_nTickBase;
    }
    else
    {
      v9 = sv_clockcorrection_msecs.m_pParent->m_Value.m_fValue * 0.001;
      v10 = 0;
      if ( v9 < 0.0 || (v10 = 1065353216, v9 > 1.0) )
        v9 = *(float *)&v10;
      v11 = simulation_ticks + this->m_nTickBase.m_Value;
      p_m_nTickBase = &this->m_nTickBase;
      v13 = (int)(float)((float)(v9 / gpGlobals->interval_per_tick) + 0.5);
      v14 = v13 + gpGlobals->tickcount;
      if ( v11 <= v14 + v13 )
      {
        if ( v11 >= v14 - (int)(float)((float)(v9 / gpGlobals->interval_per_tick) + 0.5) )
        {
          v4 = (UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *)pi;
LABEL_28:
          if ( v4 != nullptr )
            v4->m_Element.m_flFinalSimulationTime = (float)(p_m_nTickBase->m_Value
                                                          + simulation_ticks
                                                          + v8->simTicksThisFrame)
                                                  * v8->interval_per_tick;
          return;
        }
        v13 = (int)(float)((float)(v9 / gpGlobals->interval_per_tick) + 0.5);
      }
      v4 = (UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *)pi;
      v15 = v14 + gpGlobals->simTicksThisFrame - simulation_ticks;
      if ( pi != nullptr )
      {
        pi->m_nTicksCorrected = v13;
        v8 = gpGlobals;
      }
    }
    if ( p_m_nTickBase->m_Value != v15 )
    {
      v16 = p_m_nTickBase - 971;
      if ( LOBYTE(p_m_nTickBase[-950].m_Value) != 0 )
      {
        LOBYTE(v16[22].m_Value) |= 1u;
        p_m_nTickBase->m_Value = v15;
        v8 = gpGlobals;
      }
      else
      {
        m_Value = (CBaseEdict *)v16[6].m_Value;
        if ( m_Value != nullptr )
          CBaseEdict::StateChanged(this: m_Value, offset: 0xF2Cu);
        p_m_nTickBase->m_Value = v15;
        v8 = gpGlobals;
      }
    }
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C68B0
// Name: public: virtual void CBasePlayer::PhysicsSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayer::PhysicsSimulate(CBasePlayer *this@<ecx>, int a2@<ebx>)
{
  CCommandContext *v2; // esi
  CBasePlayer *v3; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int tickcount; // eax
  int v7; // eax
  int m_Size; // ecx
  CCommandContext *v9; // edx
  CUserCmd *m_pMemory; // ebx
  int v11; // eax
  int dropped_packets; // ecx
  int v13; // eax
  CCommandContext *v14; // edi
  CUserCmd *v15; // edi
  bool v16; // zf
  CCommandContext *v17; // edi
  CUserCmd *v18; // edi
  int v19; // eax
  int v20; // eax
  const CUserCmd *v21; // ebx
  CCommandContext *v22; // edi
  CUserCmd *v23; // ecx
  CUserCmd *v24; // edi
  bool IsSimulatingOnAlternateTicks; // al
  int v26; // eax
  int simTicksThisFrame; // ecx
  int v28; // ecx
  CCommandContext *v29; // eax
  IMoveHelper *v30; // eax
  IPredictionSystem *j; // eax
  CUserCmd *v32; // edi
  IMoveHelper *v33; // eax
  CBasePlayer *v34; // ebx
  IPredictionSystem *k; // eax
  IMoveHelper *v36; // eax
  int v37; // edi
  CBasePlayer *v38; // ecx
  double z; // st7
  CCommandContext *v40; // ecx
  double curtime; // st7
  int v42; // esi
  CUserCmd *v43; // edi
  CUserCmd *p_m_LastCmd; // [esp+20h] [ebp-48h]
  const CUserCmd *v45; // [esp+20h] [ebp-48h]
  CUtlVector<CUserCmd,CUtlMemory<CUserCmd,int> > vecAvailCommands; // [esp+30h] [ebp-38h] BYREF
  float saveframetime; // [esp+44h] [ebp-24h]
  float savetime; // [esp+48h] [ebp-20h]
  int command_context_count; // [esp+4Ch] [ebp-1Ch]
  int context_number; // [esp+50h] [ebp-18h]
  int i; // [esp+54h] [ebp-14h]
  float vphysicsArrivalTime; // [esp+58h] [ebp-10h]
  int droppedcmds; // [esp+5Ch] [ebp-Ch]
  CCommandContext *ctx; // [esp+60h] [ebp-8h]
  CBasePlayer *v56; // [esp+64h] [ebp-4h]
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  v2 = nullptr;
  v3 = this;
  v56 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBasePlayer::PhysicsSimulate",
    a3: 0,
    a4: "Player",
    a5: false,
    a6: 4);
  m_Index = v3->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
      ((void (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[35].SetRefEHandle)(a1: m_pEntity);
  }
  tickcount = gpGlobals->tickcount;
  if ( v3->m_nSimulationTick == tickcount )
    goto LABEL_10;
  v3->m_nSimulationTick = tickcount;
  v7 = CBasePlayer::DetermineSimulationTicks(this: v3);
  if ( v7 > 0 )
    CBasePlayer::AdjustPlayerTimeBase(this: v3, simulation_ticks: v7);
  if ( v3->pl.hltv )
  {
    CBasePlayer::RunNullCommand(this: v3, a2, a3: (int)v3, a4: 0);
    CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::RemoveAll(this: &v3->m_CommandContext);
LABEL_10:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  m_Size = v3->m_CommandContext.m_Size;
  savetime = gpGlobals->curtime;
  v9 = nullptr;
  m_pMemory = nullptr;
  v11 = 0;
  saveframetime = gpGlobals->frametime;
  command_context_count = m_Size;
  memset(&vecAvailCommands, 0, sizeof(vecAvailCommands));
  context_number = 0;
  if ( m_Size > 0 )
  {
    vphysicsArrivalTime = 0.0;
    while ( 1 )
    {
      if ( v11 < 0 || v11 >= v3->m_CommandContext.m_Size )
      {
        ctx = nullptr;
      }
      else
      {
        v9 = (CCommandContext *)((char *)v3->m_CommandContext.m_Memory.m_pMemory + LODWORD(vphysicsArrivalTime));
        ctx = v9;
      }
      if ( v9->cmds.m_Size != 0 )
      {
        dropped_packets = v9->dropped_packets;
        v13 = v9->totalcmds - v9->numcmds;
        if ( dropped_packets < 24 )
        {
          droppedcmds = v9->dropped_packets;
          if ( dropped_packets > v13 )
          {
            i = dropped_packets - v13;
            droppedcmds = v13;
            do
            {
              ++v3->m_LastCmd.tick_count;
              v14 = v2;
              if ( (int)&v2->cmds.m_Memory.m_pMemory + 1 > vecAvailCommands.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<CUserCmd,int>::Grow(
                  this: &vecAvailCommands.m_Memory,
                  num: (int)&v2->cmds.m_Memory.m_pMemory - vecAvailCommands.m_Memory.m_nAllocationCount + 1);
                v2 = (CCommandContext *)vecAvailCommands.m_Size;
                m_pMemory = vecAvailCommands.m_Memory.m_pMemory;
              }
              v2 = (CCommandContext *)((char *)v2 + 1);
              vecAvailCommands.m_Size = (int)v2;
              vecAvailCommands.m_pElements = m_pMemory;
              if ( (char *)v2 - (char *)v14 - 1 > 0 )
                _V_memmove(
                  dest: (void *)&m_pMemory[(int)v14 + 1],
                  src: &m_pMemory[(_DWORD)v14],
                  count: 88 * ((char *)v2 - (char *)v14 - 1));
              v15 = &m_pMemory[(_DWORD)v14];
              if ( v15 != nullptr )
              {
                p_m_LastCmd = &v56->m_LastCmd;
                v15->__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
                CUserCmd::operator=(this: v15, src: p_m_LastCmd);
              }
              v16 = i-- == 1;
              v3 = v56;
            }
            while ( !v16 );
            v9 = ctx;
            dropped_packets = droppedcmds;
          }
          if ( dropped_packets > 0 )
          {
            do
            {
              i = (int)&v9->cmds.m_Memory.m_pMemory[dropped_packets - 1 + v9->numcmds];
              v17 = v2;
              if ( (int)&v2->cmds.m_Memory.m_pMemory + 1 > vecAvailCommands.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<CUserCmd,int>::Grow(
                  this: &vecAvailCommands.m_Memory,
                  num: (int)&v2->cmds.m_Memory.m_pMemory - vecAvailCommands.m_Memory.m_nAllocationCount + 1);
                v2 = (CCommandContext *)vecAvailCommands.m_Size;
                m_pMemory = vecAvailCommands.m_Memory.m_pMemory;
              }
              v2 = (CCommandContext *)((char *)v2 + 1);
              vecAvailCommands.m_Size = (int)v2;
              vecAvailCommands.m_pElements = m_pMemory;
              if ( (char *)v2 - (char *)v17 - 1 > 0 )
                _V_memmove(
                  dest: (void *)&m_pMemory[(int)v17 + 1],
                  src: &m_pMemory[(_DWORD)v17],
                  count: 88 * ((char *)v2 - (char *)v17 - 1));
              v18 = &m_pMemory[(_DWORD)v17];
              if ( v18 != nullptr )
              {
                v45 = (const CUserCmd *)i;
                v18->__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
                CUserCmd::operator=(this: v18, src: v45);
              }
              v9 = ctx;
              dropped_packets = droppedcmds - 1;
              droppedcmds = dropped_packets;
            }
            while ( dropped_packets > 0 );
            v3 = v56;
          }
        }
        v19 = v9->numcmds - 1;
        i = v19;
        if ( v19 >= 0 )
        {
          v20 = 88 * v19;
          for ( droppedcmds = v20; ; v20 = droppedcmds )
          {
            v21 = (CUserCmd *)((char *)v9->cmds.m_Memory.m_pMemory + v20);
            v22 = v2;
            if ( (int)&v2->cmds.m_Memory.m_pMemory + 1 > vecAvailCommands.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CUserCmd,int>::Grow(
                this: &vecAvailCommands.m_Memory,
                num: (int)&v2->cmds.m_Memory.m_pMemory - vecAvailCommands.m_Memory.m_nAllocationCount + 1);
              v2 = (CCommandContext *)vecAvailCommands.m_Size;
            }
            v23 = vecAvailCommands.m_Memory.m_pMemory;
            v2 = (CCommandContext *)((char *)v2 + 1);
            vecAvailCommands.m_Size = (int)v2;
            vecAvailCommands.m_pElements = vecAvailCommands.m_Memory.m_pMemory;
            if ( (char *)v2 - (char *)v22 - 1 > 0 )
            {
              _V_memmove(
                dest: (void *)&vecAvailCommands.m_Memory.m_pMemory[(int)v22 + 1],
                src: &vecAvailCommands.m_Memory.m_pMemory[(_DWORD)v22],
                count: 88 * ((char *)v2 - (char *)v22 - 1));
              v23 = vecAvailCommands.m_Memory.m_pMemory;
            }
            v24 = &v23[(_DWORD)v22];
            if ( v24 != nullptr )
            {
              v24->__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
              CUserCmd::operator=(this: v24, src: v21);
            }
            droppedcmds -= 88;
            v9 = ctx;
            if ( --i < 0 )
              break;
          }
          m_pMemory = vecAvailCommands.m_Memory.m_pMemory;
          v3 = v56;
        }
        CUserCmd::operator=(this: &v3->m_LastCmd, src: v9->cmds.m_Memory.m_pMemory);
        v11 = context_number;
      }
      LODWORD(vphysicsArrivalTime) += 36;
      context_number = ++v11;
      if ( v11 >= command_context_count )
        break;
      v9 = nullptr;
    }
  }
  IsSimulatingOnAlternateTicks = CBaseEntity::IsSimulatingOnAlternateTicks();
  ctx = v2;
  v26 = IsSimulatingOnAlternateTicks + 1;
  simTicksThisFrame = gpGlobals->simTicksThisFrame;
  if ( simTicksThisFrame < v26
    || (int)v2 <= v26
    || ((int)v2 >= simTicksThisFrame - 1
      ? (LODWORD(vphysicsArrivalTime) = simTicksThisFrame - 1, v28 = simTicksThisFrame - 1)
      : (v28 = (int)v2, vphysicsArrivalTime = *(float *)&v2),
        ctx = (CCommandContext *)((char *)v2 - v28),
        v28 <= 0) )
  {
    CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::RemoveAll(this: &v3->m_CommandContext);
  }
  else
  {
    v29 = CBasePlayer::RemoveAllCommandContextsExceptNewest(this: v3);
    CBasePlayer::ReplaceContextCommands(
      this: v3,
      ctx: v29,
      pCommands: &m_pMemory[(_DWORD)ctx],
      nCommands: SLODWORD(vphysicsArrivalTime));
  }
  vphysicsArrivalTime = gpGlobals->interval_per_tick;
  if ( (int)ctx > 0 )
  {
    v30 = MoveHelperServer();
    ((void (__thiscall *)(IMoveHelper *, CBasePlayer *, int))v30->SetHost)(a1: v30, a2: v3, a3: a2);
    if ( v3->m_bPredictWeapons )
    {
      for ( j = IPredictionSystem::g_pPredictionSystems; j != nullptr; j = j->m_pNextSystem )
        j->m_pSuppressHost = v3;
    }
    if ( (int)ctx > 0 )
    {
      v32 = m_pMemory;
      for ( context_number = (int)ctx; context_number != 0; --context_number )
      {
        command_context_count = (int)v56->__vftable;
        v33 = MoveHelperServer();
        v34 = v56;
        (*(void (__thiscall **)(CBasePlayer *, CUserCmd *, IMoveHelper *))(command_context_count + 1800))(
          a1: v56,
          a2: v32,
          a3: v33);
        if ( v34->m_pPhysicsController != nullptr )
        {
          CBasePlayer::UpdateVPhysicsPosition(
            this: v34,
            position: &v34->m_vNewVPhysicsPosition,
            velocity: &v34->m_vNewVPhysicsVelocity,
            secondsToArrival: vphysicsArrivalTime);
          vphysicsArrivalTime = gpGlobals->interval_per_tick + vphysicsArrivalTime;
        }
        ++v32;
      }
      m_pMemory = vecAvailCommands.m_Memory.m_pMemory;
      v3 = v56;
    }
    for ( k = IPredictionSystem::g_pPredictionSystems; k != nullptr; k = k->m_pNextSystem )
      k->m_pSuppressHost = nullptr;
    v36 = MoveHelperServer();
    v36->SetHost(this: v36, a2: nullptr);
    if ( v3->m_vecPlayerSimInfo.m_ElementCount != 0 )
    {
      v37 = (int)&v3->m_vecPlayerSimInfo.m_Memory.m_pMemory[v3->m_vecPlayerSimInfo.m_Tail];
      v38 = v56;
      *(float *)v37 = gpGlobals->realtime;
      if ( (v38->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: v38, a2: (int)&savedregs);
        v38 = v56;
      }
      *(float *)(v37 + 24) = v38->m_vecAbsOrigin.x;
      *(float *)(v37 + 28) = v38->m_vecAbsOrigin.y;
      z = v38->m_vecAbsOrigin.z;
      v40 = ctx;
      *(float *)(v37 + 32) = z;
      curtime = gpGlobals->curtime;
      *(_DWORD *)(v37 + 4) = v40;
      *(float *)(v37 + 16) = curtime;
    }
  }
  v42 = (int)(&v2[-1].paused + 3);
  gpGlobals->curtime = savetime;
  gpGlobals->frametime = saveframetime;
  if ( v42 >= 0 )
  {
    v43 = &m_pMemory[v42];
    do
    {
      ((void (__thiscall *)(CUserCmd *, _DWORD))v43->dtr_CUserCmd)(a1: v43, a2: 0);
      --v43;
      --v42;
    }
    while ( v42 >= 0 );
  }
  if ( vecAvailCommands.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101C6DE0
// Name: public: virtual void CBasePlayer::ProcessUsercmds(class CUserCmd __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ProcessUsercmds(
        CBasePlayer *this,
        CUserCmd *cmds,
        int numcmds,
        int totalcmds,
        int dropped_packets,
        bool paused)
{
  CBasePlayer *v6; // edi
  int v7; // ebx
  CCommandContext *v8; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUserCmd *m_pMemory; // ecx
  int v13; // eax
  CUserCmd *v14; // edi
  bool v15; // cl
  bool v16; // bl
  int v17; // edx
  int v18; // eax
  CUserCmd *v19; // ecx
  int p_viewangles; // ecx
  void (__thiscall *PhysicsSimulate)(CBaseEntity *); // eax
  ConVar *m_pParent; // eax
  int v23; // eax
  int m_Head; // edi
  CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short> > *p_m_vecPlayerCmdInfo; // esi
  unsigned __int16 v26; // ax
  int v27; // edi
  UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short> *v28; // eax
  int v29; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short> *v31; // esi
  __int64 pi; // [esp+Ch] [ebp-14h]
  int i; // [esp+18h] [ebp-8h]

  v6 = this;
  v7 = totalcmds;
  v8 = &this->m_CommandContext.m_Memory.m_pMemory[CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::InsertBefore(
                                                    this: &this->m_CommandContext,
                                                    elem: this->m_CommandContext.m_Size)];
  i = totalcmds - 1;
  if ( totalcmds - 1 >= 0 )
  {
    do
    {
      m_Size = v8->cmds.m_Size;
      m_nAllocationCount = v8->cmds.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CUserCmd,int>::Grow(this: &v8->cmds.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++v8->cmds.m_Size;
      m_pMemory = v8->cmds.m_Memory.m_pMemory;
      v13 = v8->cmds.m_Size - m_Size - 1;
      v8->cmds.m_pElements = v8->cmds.m_Memory.m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: (void *)&m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 88 * v13);
      v14 = &v8->cmds.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
      {
        v14->__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
        CUserCmd::operator=(this: v14, src: cmds);
      }
      ++cmds;
      --i;
    }
    while ( i >= 0 );
    v6 = this;
    v7 = totalcmds;
  }
  v8->dropped_packets = dropped_packets;
  v15 = paused;
  v8->numcmds = numcmds;
  v8->totalcmds = v7;
  v8->paused = paused;
  if ( paused )
  {
    v16 = true;
    if ( v6->m_MoveType.m_Value == 8
      && sv_cheats->m_pParent != nullptr
      && sv_cheats->m_pParent->m_Value.m_nValue != 0
      && sv_noclipduringpause.m_pParent != nullptr )
    {
      v16 = sv_noclipduringpause.m_pParent->m_Value.m_nValue == 0;
    }
    v17 = 0;
    if ( numcmds > 0 )
    {
      v18 = 0;
      do
      {
        v8->cmds.m_Memory.m_pMemory[v18].buttons = 0;
        if ( v16 )
        {
          v8->cmds.m_Memory.m_pMemory[v18].forwardmove = 0.0;
          v8->cmds.m_Memory.m_pMemory[v18].sidemove = 0.0;
          v8->cmds.m_Memory.m_pMemory[v18].upmove = 0.0;
          v19 = v8->cmds.m_Memory.m_pMemory;
          v19[v18].viewangles.x = v6->pl.v_angle.x;
          p_viewangles = (int)&v19[v18].viewangles;
          *(float *)(p_viewangles + 4) = v6->pl.v_angle.y;
          *(float *)(p_viewangles + 8) = v6->pl.v_angle.z;
        }
        ++v17;
        ++v18;
      }
      while ( v17 < v8->numcmds );
      v15 = paused;
    }
    v8->dropped_packets = 0;
  }
  v6->m_bGamePaused = v15;
  if ( v15 )
  {
    PhysicsSimulate = v6->PhysicsSimulate;
    v6->m_nSimulationTick = -1;
    PhysicsSimulate(this: v6);
  }
  m_pParent = sv_playerperfhistorycount.m_pParent;
  if ( sv_playerperfhistorycount.m_pParent != nullptr && sv_playerperfhistorycount.m_pParent->m_Value.m_nValue > 0 )
  {
    *(float *)&pi = gpGlobals->realtime;
    HIDWORD(pi) = numcmds;
    while ( 1 )
    {
      v23 = m_pParent != nullptr ? m_pParent->m_Value.m_nValue : 0;
      if ( v6->m_vecPlayerCmdInfo.m_ElementCount < v23 )
        break;
      m_Head = v6->m_vecPlayerCmdInfo.m_Head;
      CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::Unlink(
        this: &this->m_vecPlayerCmdInfo,
        elem: m_Head);
      this->m_vecPlayerCmdInfo.m_Memory.m_pMemory[m_Head].m_Next = this->m_vecPlayerCmdInfo.m_FirstFree;
      this->m_vecPlayerCmdInfo.m_FirstFree = m_Head;
      m_pParent = sv_playerperfhistorycount.m_pParent;
      v6 = this;
    }
    p_m_vecPlayerCmdInfo = &v6->m_vecPlayerCmdInfo;
    v26 = CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::AllocInternal(
            this: &v6->m_vecPlayerCmdInfo,
            multilist: false);
    v27 = v26;
    if ( v26 != 0xFFFF )
    {
      CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::Unlink(
        this: p_m_vecPlayerCmdInfo,
        elem: v26);
      v28 = p_m_vecPlayerCmdInfo->m_Memory.m_pMemory;
      v29 = v27;
      v28[v29].m_Next = -1;
      m_Tail = p_m_vecPlayerCmdInfo->m_Tail;
      v28[v29].m_Previous = m_Tail;
      p_m_vecPlayerCmdInfo->m_Tail = v27;
      if ( (_WORD)m_Tail == 0xFFFF )
        p_m_vecPlayerCmdInfo->m_Head = v27;
      else
        p_m_vecPlayerCmdInfo->m_Memory.m_pMemory[m_Tail].m_Next = v27;
      ++p_m_vecPlayerCmdInfo->m_ElementCount;
      v31 = &p_m_vecPlayerCmdInfo->m_Memory.m_pMemory[v29];
      if ( v31 != nullptr )
      {
        *(_QWORD *)&v31->m_Element.m_flTime = pi;
        v31->m_Element.m_nDroppedPackets = dropped_packets;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7070
// Name: public: bool CUserMessageThrottleMgr::ShouldThrottle(class CBasePlayer __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUserMessageThrottleMgr::ShouldThrottle(
        CUserMessageThrottleMgr *this,
        CBasePlayer *pPlayer,
        const char *pchMessageName)
{
  int v4; // eax
  edict_t *m_pPev; // ecx
  CBitVec<64> *p_elem; // esi
  int v7; // eax
  unsigned int *v8; // ecx
  CUtlMap<char const *,CBitVec<64>,int>::Node_t search; // [esp+4h] [ebp-Ch] BYREF

  if ( pchMessageName != nullptr )
  {
    search.key = pchMessageName;
    search.elem = 0;
    v4 = CUtlRBTree<CUtlMap<char const *,CBitVec<64>,int>::Node_t,int,CUtlMap<char const *,CBitVec<64>,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBitVec<64>,int>::Node_t,int>,int>>::Find(
           this: &this->m_SentMessage.m_Elements.m_Tree,
           &search);
    if ( v4 != -1 )
    {
      m_pPev = pPlayer->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      p_elem = &this->m_SentMessage.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
      v7 = 1 << (((_BYTE)m_pPev - 1) & 0x1F);
      v8 = &p_elem->m_Ints[((int)&m_pPev[-1].m_pUnk + 3) >> 5];
      if ( (v7 & *v8) != 0 )
        return 1;
      *v8 |= v7;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C70F0
// Name: public: bool CBasePlayer::ShouldThrottleUserMessage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePlayer::ShouldThrottleUserMessage(CBasePlayer *this, const char *pchMessageName)
{
  return CUserMessageThrottleMgr::ShouldThrottle(this: &g_ThrottleMgr, pPlayer: this, pchMessageName);
}

//------------------------------------------------------------------------------
// Address: 0x101C7170
// Name: void InitCBasePlayerScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCBasePlayerScriptDesc()
{
  ScriptFunctionBinding_t *v0; // eax

  if ( !bInitialized_3 )
  {
    bInitialized_3 = true;
    g_CBasePlayer_ScriptDesc.m_pszDescription = "The player entity.";
    g_CBasePlayer_ScriptDesc.m_pszScriptName = "CBasePlayer";
    g_CBasePlayer_ScriptDesc.m_pszClassname = "CBasePlayer";
    g_CBasePlayer_ScriptDesc.m_pBaseDesc = GetScriptDesc();
    g_CBasePlayer_ScriptDesc.pHelper = GetScriptInstanceHelper_CBaseAnimating();
    v0 = &g_CBasePlayer_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBasePlayer_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBasePlayer_ScriptDesc.m_FunctionBindings.m_Size)];
    v0->m_desc.m_pszDescription = "Returns true if the player is in noclip mode.";
    v0->m_desc.m_pszScriptName = "IsNoclipping";
    v0->m_desc.m_pszFunction = "ScriptIsPlayerNoclipping";
    v0->m_desc.m_ReturnType = 6;
    v0->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CBasePlayer *,bool (__thiscall CBasePlayer::*)(void),bool>::Call;
    v0->m_pFunction = CBasePlayer::ScriptIsPlayerNoclipping;
    v0->m_flags = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7210
// Name: public: CBasePlayer::CBasePlayer(void)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CBasePlayer::CBasePlayer(CBasePlayer *this)
{
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short> *v3; // edx
  unsigned int m_Index; // eax
  edict_t *m_pPev; // ecx
  edict_t *v6; // ecx
  unsigned int v7; // eax
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  unsigned int v10; // eax
  edict_t *v11; // ecx
  unsigned int v12; // eax
  edict_t *v13; // ecx
  edict_t *v14; // ecx
  int v16; // [esp+Ch] [ebp-4h]

  CBaseCombatCharacter::CBaseCombatCharacter(this);
  this->__vftable = (CBasePlayer_vtbl *)&CBasePlayer::`vftable';
  CPlayerLocalData::CPlayerLocalData(this: &this->m_Local);
  this->m_Local.__vftable = (CBasePlayer::NetworkVar_m_Local_vtbl *)&CBasePlayer::NetworkVar_m_Local::`vftable';
  fogplayerparams_t::fogplayerparams_t(this: &this->m_PlayerFog);
  this->m_PlayerFog.__vftable = (CBasePlayer::NetworkVar_m_PlayerFog_vtbl *)&CBasePlayer::NetworkVar_m_PlayerFog::`vftable';
  this->m_hTriggerTonemapList.m_Memory.m_pMemory = nullptr;
  this->m_hTriggerTonemapList.m_Memory.m_nAllocationCount = 0;
  this->m_hTriggerTonemapList.m_Memory.m_nGrowSize = 0;
  this->m_hTriggerTonemapList.m_Size = 0;
  this->m_hTriggerTonemapList.m_pElements = nullptr;
  this->m_hPostProcessCtrl.m_Value.m_Index = -1;
  this->m_hColorCorrectionCtrl.m_Value.m_Index = -1;
  this->m_hTriggerSoundscapeList.m_Memory.m_pMemory = nullptr;
  this->m_hTriggerSoundscapeList.m_Memory.m_nAllocationCount = 0;
  this->m_hTriggerSoundscapeList.m_Memory.m_nGrowSize = 0;
  this->m_hTriggerSoundscapeList.m_Size = 0;
  this->m_hTriggerSoundscapeList.m_pElements = nullptr;
  this->pl.__vftable = (CBasePlayer::NetworkVar_pl_vtbl *)&CBasePlayer::NetworkVar_pl::`vftable';
  this->m_hUseEntity.m_Value.m_Index = -1;
  this->m_hVehicle.m_Value.m_Index = -1;
  this->m_hObserverTarget.m_Value.m_Index = -1;
  this->m_hZoomOwner.m_Value.m_Index = -1;
  this->m_hTonemapController.m_Value.m_Index = -1;
  this->m_CommandContext.m_Memory.m_pMemory = nullptr;
  this->m_CommandContext.m_Memory.m_nAllocationCount = 0;
  this->m_CommandContext.m_Memory.m_nGrowSize = 0;
  this->m_CommandContext.m_Size = 0;
  this->m_CommandContext.m_pElements = nullptr;
  this->m_AutoaimTimer.m_next = -1.0;
  this->m_hViewModel.m_Value[0].m_Index = -1;
  this->m_hViewModel.m_Value[1].m_Index = -1;
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
  this->m_hLastWeapon.m_Value.m_Index = -1;
  this->m_SimulatedByThisPlayer.m_Memory.m_pMemory = nullptr;
  this->m_SimulatedByThisPlayer.m_Memory.m_nAllocationCount = 0;
  this->m_SimulatedByThisPlayer.m_Memory.m_nGrowSize = 0;
  this->m_SimulatedByThisPlayer.m_Size = 0;
  this->m_SimulatedByThisPlayer.m_pElements = nullptr;
  this->m_hViewEntity.m_Value.m_Index = -1;
  this->m_hConstraintEntity.m_Value.m_Index = -1;
  this->m_PlayerInfo.__vftable = (IPlayerInfo_vtbl *)&IPlayerInfo::`vftable';
  this->m_PlayerInfo.__vftable = (CPlayerInfo_vtbl *)&CPlayerInfo::`vftable'{for `IBotController'};
  this->m_PlayerInfo.__vftable = (IPlayerInfo_vtbl *)&CPlayerInfo::`vftable'{for `IPlayerInfo'};
  this->m_PlayerInfo.m_pParent = nullptr;
  this->m_hPlayerProxy.m_Index = -1;
  this->m_StepSoundCache[0].m_SoundParameters.channel = 0;
  this->m_StepSoundCache[0].m_SoundParameters.volume = 1.0;
  this->m_StepSoundCache[0].m_SoundParameters.soundlevel = SNDLVL_NORM;
  this->m_StepSoundCache[0].m_SoundParameters.soundname[0] = 0;
  this->m_StepSoundCache[0].m_SoundParameters.play_to_owner_only = false;
  this->m_StepSoundCache[0].m_SoundParameters.count = 0;
  this->m_StepSoundCache[0].m_SoundParameters.delay_msec = 0;
  this->m_StepSoundCache[0].m_SoundParameters.m_pOperatorsKV = nullptr;
  this->m_StepSoundCache[0].m_SoundParameters.m_nRandomSeed = -1;
  this->m_StepSoundCache[1].m_SoundParameters.channel = 0;
  this->m_StepSoundCache[1].m_SoundParameters.volume = 1.0;
  this->m_StepSoundCache[1].m_SoundParameters.soundlevel = SNDLVL_NORM;
  this->m_StepSoundCache[1].m_SoundParameters.soundname[0] = 0;
  this->m_StepSoundCache[1].m_SoundParameters.play_to_owner_only = false;
  this->m_StepSoundCache[1].m_SoundParameters.count = 0;
  this->m_StepSoundCache[1].m_SoundParameters.delay_msec = 0;
  this->m_StepSoundCache[1].m_SoundParameters.m_pOperatorsKV = nullptr;
  this->m_StepSoundCache[1].m_SoundParameters.m_nRandomSeed = -1;
  this->m_StepSoundCache[0].m_SoundParameters.pitch = 100;
  this->m_StepSoundCache[0].m_SoundParameters.pitchlow = 100;
  this->m_StepSoundCache[0].m_SoundParameters.pitchhigh = 100;
  this->m_StepSoundCache[1].m_SoundParameters.pitch = 100;
  this->m_StepSoundCache[1].m_SoundParameters.pitchlow = 100;
  this->m_StepSoundCache[1].m_SoundParameters.pitchhigh = 100;
  this->m_StepSoundCache[0].m_SoundParameters.m_hSoundScriptHandle = -1;
  this->m_StepSoundCache[0].m_usSoundNameIndex = 0;
  this->m_StepSoundCache[1].m_usSoundNameIndex = 0;
  this->m_StepSoundCache[1].m_SoundParameters.m_hSoundScriptHandle = -1;
  this->m_StepSoundCache[0].m_SoundParameters.m_nSoundEntryVersion = 1;
  this->m_StepSoundCache[1].m_SoundParameters.m_nSoundEntryVersion = 1;
  this->m_vecPlayerSimInfo.m_Memory.m_pMemory = nullptr;
  this->m_vecPlayerSimInfo.m_Memory.m_nAllocationCount = 0;
  this->m_vecPlayerSimInfo.m_Memory.m_nGrowSize = 0;
  this->m_vecPlayerSimInfo.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_vecPlayerSimInfo.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_vecPlayerSimInfo.m_Memory.m_pMemory;
  this->m_vecPlayerSimInfo.m_NumAlloced = 0;
  this->m_vecPlayerSimInfo.m_pElements = m_pMemory;
  *(_DWORD *)&this->m_vecPlayerSimInfo.m_Head = -1;
  this->m_vecPlayerCmdInfo.m_Memory.m_pMemory = nullptr;
  this->m_vecPlayerCmdInfo.m_Memory.m_nAllocationCount = 0;
  this->m_vecPlayerCmdInfo.m_Memory.m_nGrowSize = 0;
  this->m_vecPlayerCmdInfo.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_vecPlayerCmdInfo.m_FirstFree = 0xFFFF;
  v3 = this->m_vecPlayerCmdInfo.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_vecPlayerCmdInfo.m_Head = -1;
  this->m_vecPlayerCmdInfo.m_pElements = v3;
  this->m_vecPlayerCmdInfo.m_NumAlloced = 0;
  this->m_stuckCharacter.m_Index = -1;
  this->m_hSplitOwner.m_Index = -1;
  this->m_hSplitScreenPlayers.m_Memory.m_pMemory = nullptr;
  this->m_hSplitScreenPlayers.m_Memory.m_nAllocationCount = 0;
  this->m_hSplitScreenPlayers.m_Memory.m_nGrowSize = 0;
  this->m_hSplitScreenPlayers.m_Size = 0;
  this->m_hSplitScreenPlayers.m_pElements = nullptr;
  this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory = nullptr;
  this->m_hSplitScreenAndPipPlayers.m_Memory.m_nAllocationCount = 0;
  this->m_hSplitScreenAndPipPlayers.m_Memory.m_nGrowSize = 0;
  this->m_hSplitScreenAndPipPlayers.m_Size = 0;
  this->m_hSplitScreenAndPipPlayers.m_pElements = nullptr;
  this->m_hPipPlayers.m_Memory.m_pMemory = nullptr;
  this->m_hPipPlayers.m_Memory.m_nAllocationCount = 0;
  this->m_hPipPlayers.m_Memory.m_nGrowSize = 0;
  this->m_hPipPlayers.m_Size = 0;
  this->m_hPipPlayers.m_pElements = nullptr;
  this->m_iEFlags |= 0x400u;
  this->m_vecAutoAim.x = 0.0;
  this->m_vecAutoAim.y = 0.0;
  this->m_vecAutoAim.z = 0.0;
  if ( CBasePlayer::s_PlayerEdict != nullptr )
  {
    CServerNetworkProperty::AttachEdict(this: &this->m_Network, pRequiredEdict: CBasePlayer::s_PlayerEdict);
    CBasePlayer::s_PlayerEdict = nullptr;
  }
  this->m_flFlashTime = -1.0;
  this->pl.fixangle = 1;
  this->pl.hltv = false;
  this->pl.frags = 0;
  this->pl.deaths = 0;
  this->m_szNetname[0] = 0;
  if ( this->m_iHealth.m_Value != 0 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 0;
  }
  CBasePlayer::Weapon_SetLast(this, pWeapon: nullptr);
  this->m_bitsDamageType = 0;
  this->m_bForceOrigin = false;
  m_Index = this->m_hVehicle.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC00u);
    }
    this->m_hVehicle.m_Value.m_Index = -1;
  }
  this->m_pCurrentCommand = nullptr;
  v16 = g_pGameRules->DefaultFOV(this: g_pGameRules);
  if ( this->m_iDefaultFOV.m_Value != v16 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0xC50u);
    }
    this->m_iDefaultFOV.m_Value = v16;
  }
  v7 = this->m_hZoomOwner.m_Value.m_Index;
  if ( v7 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0xC68u);
    }
    this->m_hZoomOwner.m_Value.m_Index = -1;
  }
  this->m_fLerpTime = 0.1;
  this->m_nUpdateRate = 20;
  *(_WORD *)&this->m_bLagCompensation = 256;
  if ( this->m_flLaggedMovementValue.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0xFA4u);
    }
    this->m_flLaggedMovementValue.m_Value = 1.0;
  }
  this->m_impactEnergyScale = 1.0;
  this->m_StuckLast = 0;
  this->m_fLastPlayerTalkTime = 0.0;
  this->m_PlayerInfo.m_pParent = this;
  CBasePlayer::ResetObserverMode(this);
  this->m_surfaceProps = 0;
  this->m_pSurfaceData = nullptr;
  this->m_surfaceFriction = 1.0;
  *(_WORD *)&this->m_chTextureType = 0;
  this->m_iSuicideCustomKillFlags = 0;
  this->m_fDelay = 0.0;
  this->m_fReplayEnd = -1.0;
  this->m_iReplayEntity = 0;
  this->m_autoKickDisabled = false;
  this->m_nNumCrouches = 0;
  this->m_bDuckToggled = false;
  this->m_bPhysicsWasFrozen = false;
  *(_WORD *)&this->m_bDropEnabled = 257;
  this->m_movementCollisionNormal.x = 0.0;
  this->m_movementCollisionNormal.y = 0.0;
  this->m_movementCollisionNormal.z = 1.0;
  this->m_afButtonDisabled = 0;
  this->m_afButtonForced = 0;
  this->m_nBodyPitchPoseParam = -1;
  this->m_flForwardMove = 0.0;
  this->m_flSideMove = 0.0;
  this->m_bSplitScreenPlayer = false;
  this->m_hSplitOwner.m_Index = -1;
  this->m_ClientPlatform = CROSSPLAYPLATFORM_PC;
  v10 = this->m_hPostProcessCtrl.m_Value.m_Index;
  if ( v10 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber == HIWORD(v10)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0xB38u);
    }
    this->m_hPostProcessCtrl.m_Value.m_Index = -1;
  }
  v12 = this->m_hColorCorrectionCtrl.m_Value.m_Index;
  if ( v12 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == HIWORD(v12)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0xB3Cu);
    }
    this->m_hColorCorrectionCtrl.m_Value.m_Index = -1;
  }
  if ( vec3_origin.x != this->m_vecConstraintCenter.m_Value.x
    || vec3_origin.y != this->m_vecConstraintCenter.m_Value.y
    || vec3_origin.z != this->m_vecConstraintCenter.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0xF68u);
    }
    this->m_vecConstraintCenter.m_Value = vec3_origin;
  }
  this->m_flTimeLastTouchedGround = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C7A20
// Name: public: virtual CBasePlayer::~CBasePlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::~CBasePlayer(CBasePlayer *this)
{
  this->__vftable = (CBasePlayer_vtbl *)&CBasePlayer::`vftable';
  CBasePlayer::VPhysicsDestroyObject(this);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hPipPlayers);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hSplitScreenAndPipPlayers);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hSplitScreenPlayers);
  CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_vecPlayerCmdInfo);
  if ( this->m_vecPlayerCmdInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecPlayerCmdInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecPlayerCmdInfo.m_Memory.m_pMemory);
      this->m_vecPlayerCmdInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecPlayerCmdInfo.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_vecPlayerSimInfo);
  if ( this->m_vecPlayerSimInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecPlayerSimInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecPlayerSimInfo.m_Memory.m_pMemory);
      this->m_vecPlayerSimInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecPlayerSimInfo.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PlayerInfo.__vftable = (CPlayerInfo_vtbl *)&CPlayerInfo::`vftable'{for `IBotController'};
  this->m_PlayerInfo.__vftable = (IPlayerInfo_vtbl *)&CPlayerInfo::`vftable'{for `IPlayerInfo'};
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SimulatedByThisPlayer);
  this->m_LastCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::~CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>(this: &this->m_CommandContext);
  this->pl.__vftable = (CBasePlayer::NetworkVar_pl_vtbl *)&CPlayerState::`vftable';
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hTriggerSoundscapeList);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hTriggerTonemapList);
  CBaseCombatCharacter::~CBaseCombatCharacter(this);
}

//------------------------------------------------------------------------------
// Address: 0x1027D720
// Name: public: static class CBasePlayer __near * CBasePlayer::CreatePlayer(char const __near *,struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl CBasePlayer::CreatePlayer(const char *className, edict_t *ed)
{
  CBasePlayer::s_PlayerEdict = ed;
  return (CBasePlayer *)CreateEntityByName(className, iForceEdictIndex: -1, bNotify: true);
}

//------------------------------------------------------------------------------
// Address: 0x102DB560
// Name: public: virtual unsigned int CBasePlayer::PhysicsSolidMaskForEntity(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBasePlayer::PhysicsSolidMaskForEntity(CPushable *this)
{
  return 33636363;
}

//------------------------------------------------------------------------------
// Address: 0x10407E10
// Name: CPlayerState_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPlayerState_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPlayerState>();
  CPlayerState_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407E20
// Name: CBasePlayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBasePlayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBasePlayer>();
  CBasePlayer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407F60
// Name: spraycanPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int spraycanPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  spraycanPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&spraycanPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408000
// Name: CStripWeapons_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CStripWeapons_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CStripWeapons>(__formal: nullptr);
  CStripWeapons_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408030
// Name: CRevertSaved_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRevertSaved_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRevertSaved>(__formal: nullptr);
  CRevertSaved_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408060
// Name: CMovementSpeedMod_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMovementSpeedMod_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMovementSpeedMod>(__formal: nullptr);
  CMovementSpeedMod_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408090
// Name: DT_PlayerState::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PlayerState::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PlayerState::g_SendTable);
  return atexit(func: DT_PlayerState::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104080B0
// Name: DT_PlayerState::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PlayerState::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PlayerState::ignored>();
  DT_PlayerState::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104080C0
// Name: DT_LocalPlayerExclusive::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalPlayerExclusive::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_LocalPlayerExclusive::g_SendTable);
  return atexit(func: DT_LocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104080E0
// Name: DT_LocalPlayerExclusive::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalPlayerExclusive::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_LocalPlayerExclusive::ignored>();
  DT_LocalPlayerExclusive::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408110
// Name: DT_BasePlayer::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BasePlayer::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BasePlayer::g_SendTable);
  return atexit(func: DT_BasePlayer::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10408130
// Name: DT_BasePlayer::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BasePlayer::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BasePlayer::ignored>();
  DT_BasePlayer::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D130
// Name: DT_PlayerState::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PlayerState::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PlayerState::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D140
// Name: DT_LocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_LocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_LocalPlayerExclusive::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D170
// Name: DT_BasePlayer::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BasePlayer::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BasePlayer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10122A30
// Name: class CEnvExplosion __near * _CreateEntityTemplate<class CEnvExplosion>(class CEnvExplosion __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvExplosion *__cdecl _CreateEntityTemplate<CEnvExplosion>(CEnvExplosion *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x37Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvExplosion::`vftable';
    v3[1].m_Network.m_pPev = (edict_t *)-1;
    *(_DWORD *)&v3[1].m_Network.m_PVSInfo.m_nAreaNum = -1;
    LOWORD(v3[1].m_Network.m_pOuter) = -1;
    v3->PostConstructor(this: v3, a2: className);
    return (CEnvExplosion *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BAC00
// Name: class CSprayCan __near * _CreateEntityTemplate<class CSprayCan>(class CSprayCan __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSprayCan *__cdecl _CreateEntityTemplate<CSprayCan>(CSprayCan *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CSprayCan::`vftable';
    v3->PostConstructor(this: v3, a2: className);
    return (CSprayCan *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BAC50
// Name: class CBloodSplat __near * _CreateEntityTemplate<class CBloodSplat>(class CBloodSplat __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBloodSplat *__cdecl _CreateEntityTemplate<CBloodSplat>(CBloodSplat *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CBloodSplat::`vftable';
    v3->PostConstructor(this: v3, a2: className);
    return (CBloodSplat *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BACA0
// Name: bool ForEachPlayer<class DisableAutokick>(class DisableAutokick __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachPlayer<DisableAutokick>(DisableAutokick *func)
{
  int v1; // edi
  CBasePlayer *v2; // eax
  CBasePlayer *v3; // esi
  edict_t *m_pPev; // eax
  const char *v6; // eax

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 1;
  while ( 1 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    v3 = v2;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v3->IsPlayer(this: v3)
        && v3->m_iConnected != PlayerDisconnected
        && engine->GetPlayerUserId(this: engine, a2: v3->m_Network.m_pPev) == func->m_userID )
      {
        break;
      }
    }
    if ( ++v1 > gpGlobals->maxClients )
      return 1;
  }
  v6 = v3->GetPlayerName(this: v3);
  _Msg(a1: "autokick is disabled for %s\n", v6);
  v3->m_autoKickDisabled = true;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C61D0
// Name: struct datamap_t __near * DataMapInit<class CStripWeapons>(class CStripWeapons __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CStripWeapons>()
{
  if ( (_S4_47 & 1) == 0 )
  {
    _S4_47 |= 1u;
    nameHolder_325.m_pszBase = "CStripWeapons";
    nameHolder_325.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_325.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_325.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_325.m_Names.m_Size = 0;
    nameHolder_325.m_Names.m_pElements = nullptr;
    nameHolder_325.m_nLenBase = 13;
    atexit(func: DataMapInit_CStripWeapons__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CStripWeapons::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CStripWeapons::m_DataMap.dataNumFields = 2;
  CStripWeapons::m_DataMap.dataDesc = &dataDesc_312[1];
  return &CStripWeapons::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101C6250
// Name: struct datamap_t __near * DataMapInit<class CRevertSaved>(class CRevertSaved __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRevertSaved>()
{
  if ( (_S5_25 & 1) == 0 )
  {
    _S5_25 |= 1u;
    nameHolder_326.m_pszBase = "CRevertSaved";
    nameHolder_326.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_326.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_326.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_326.m_Names.m_Size = 0;
    nameHolder_326.m_Names.m_pElements = nullptr;
    nameHolder_326.m_nLenBase = 12;
    atexit(func: DataMapInit_CRevertSaved__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRevertSaved::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S5_25 & 2) == 0 )
  {
    _S5_25 |= 2u;
    dataDesc_313[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_326,
                                  pszIdentifier: "LoadThink");
    dataDesc_313[5].fieldOffset = 0;
    *(_DWORD *)&dataDesc_313[5].fieldSize = 2097153;
    dataDesc_313[5].externalName = nullptr;
    dataDesc_313[5].pSaveRestoreOps = nullptr;
    dataDesc_313[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CRevertSaved::LoadThink;
    *(_QWORD *)&dataDesc_313[5].td = 0;
    *(_QWORD *)&dataDesc_313[5].override_field = 0;
    *(_QWORD *)&dataDesc_313[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_313[5].flatOffset[1] = 0;
  }
  CRevertSaved::m_DataMap.dataNumFields = 5;
  CRevertSaved::m_DataMap.dataDesc = &dataDesc_313[1];
  return &CRevertSaved::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101C6340
// Name: struct datamap_t __near * DataMapInit<class CMovementSpeedMod>(class CMovementSpeedMod __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMovementSpeedMod>()
{
  if ( (_S6_19 & 1) == 0 )
  {
    _S6_19 |= 1u;
    nameHolder_327.m_pszBase = "CMovementSpeedMod";
    nameHolder_327.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_327.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_327.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_327.m_Names.m_Size = 0;
    nameHolder_327.m_Names.m_pElements = nullptr;
    nameHolder_327.m_nLenBase = 17;
    atexit(func: DataMapInit_CMovementSpeedMod__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMovementSpeedMod::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CMovementSpeedMod::m_DataMap.dataNumFields = 1;
  CMovementSpeedMod::m_DataMap.dataDesc = &dataDesc_314[1];
  return &CMovementSpeedMod::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10407E30
// Name: _dynamic_initializer_for__g_CBasePlayer_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CBasePlayer_ScriptDesc__()
{
  InitCBasePlayerScriptDesc();
  g_CBasePlayer_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CBasePlayer_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CBasePlayer_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x10407E60
// Name: _dynamic_initializer_for__VisForce__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__VisForce__()
{
  ConVar::ConVar(this: &VisForce, pName: "vis_force", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__VisForce__);
}

//------------------------------------------------------------------------------
// Address: 0x10407E90
// Name: _dynamic_initializer_for__sv_clockcorrection_msecs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_clockcorrection_msecs__()
{
  ConVar::ConVar(
    this: &sv_clockcorrection_msecs,
    pName: "sv_clockcorrection_msecs",
    pDefaultValue: "60",
    flags: 0,
    pHelpString: "The server tries to keep each player's m_nTickBase withing this many msecs of the server absolute tickcount");
  return atexit(func: dynamic_atexit_destructor_for__sv_clockcorrection_msecs__);
}

//------------------------------------------------------------------------------
// Address: 0x10407EC0
// Name: _dynamic_initializer_for__sv_playerperfhistorycount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_playerperfhistorycount__()
{
  ConVar::ConVar(
    this: &sv_playerperfhistorycount,
    pName: "sv_playerperfhistorycount",
    pDefaultValue: "20",
    flags: 0,
    pHelpString: "Number of samples to maintain in player perf history",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 128.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_playerperfhistorycount__);
}

//------------------------------------------------------------------------------
// Address: 0x10407F10
// Name: _dynamic_initializer_for__xc_crouch_debounce__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xc_crouch_debounce__()
{
  ConVar::ConVar(this: &xc_crouch_debounce, pName: "xc_crouch_debounce", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__xc_crouch_debounce__);
}

//------------------------------------------------------------------------------
// Address: 0x10407F40
// Name: _dynamic_initializer_for__spraycan__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__spraycan__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSprayCan> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &spraycan,
           a3: "spraycan");
}

//------------------------------------------------------------------------------
// Address: 0x10407F80
// Name: _dynamic_initializer_for__ch_createjeep__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ch_createjeep__()
{
  ConCommand::ConCommand(
    this: &ch_createjeep,
    pName: "ch_createjeep",
    callback: CC_CH_CreateJeep,
    pHelpString: "Spawn jeep in front of the player.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ch_createjeep__);
}

//------------------------------------------------------------------------------
// Address: 0x10407FB0
// Name: _dynamic_initializer_for__ch_createairboat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ch_createairboat__()
{
  ConCommand::ConCommand(
    this: &ch_createairboat,
    pName: "ch_createairboat",
    callback: CC_CH_CreateAirboat,
    pHelpString: "Spawn airboat in front of the player.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ch_createairboat__);
}

//------------------------------------------------------------------------------
// Address: 0x104080F0
// Name: _dynamic_initializer_for__g_CBasePlayer_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBasePlayer_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBasePlayer_ClassReg,
           pNetworkName: "CBasePlayer",
           pTable: &DT_BasePlayer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10408140
// Name: _dynamic_initializer_for__mp_disable_autokick_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_disable_autokick_command__()
{
  ConCommand::ConCommand(
    this: &mp_disable_autokick_command,
    pName: "mp_disable_autokick",
    callback: (void (__cdecl *)())mp_disable_autokick,
    pHelpString: "Prevents a userid from being auto-kicked",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mp_disable_autokick_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10408170
// Name: _dynamic_initializer_for__g_ThrottleMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ThrottleMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ThrottleMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10408180
// Name: _dynamic_initializer_for__sv_unlag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_unlag__()
{
  ConVar::ConVar(
    this: &sv_unlag,
    pName: "sv_unlag",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Enables player lag compensation");
  return atexit(func: dynamic_atexit_destructor_for__sv_unlag__);
}

//------------------------------------------------------------------------------
// Address: 0x104081B0
// Name: _dynamic_initializer_for__sv_maxunlag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxunlag__()
{
  ConVar::ConVar(
    this: &sv_maxunlag,
    pName: "sv_maxunlag",
    pDefaultValue: "1.0",
    flags: 2,
    pHelpString: "Maximum lag compensation in seconds",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_maxunlag__);
}

//------------------------------------------------------------------------------
// Address: 0x10408200
// Name: _dynamic_initializer_for__sv_lagflushbonecache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_lagflushbonecache__()
{
  ConVar::ConVar(
    this: &sv_lagflushbonecache,
    pName: "sv_lagflushbonecache",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Flushes entity bone cache on lag compensation");
  return atexit(func: dynamic_atexit_destructor_for__sv_lagflushbonecache__);
}

//------------------------------------------------------------------------------
// Address: 0x10408230
// Name: _dynamic_initializer_for__sv_showlagcompensation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_showlagcompensation__()
{
  ConVar::ConVar(
    this: &sv_showlagcompensation,
    pName: "sv_showlagcompensation",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Show lag compensated hitboxes whenever a player is lag compensated.");
  return atexit(func: dynamic_atexit_destructor_for__sv_showlagcompensation__);
}

//------------------------------------------------------------------------------
// Address: 0x10408260
// Name: _dynamic_initializer_for__sv_lagcompensationforcerestore__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_lagcompensationforcerestore__()
{
  ConVar::ConVar(
    this: &sv_lagcompensationforcerestore,
    pName: "sv_lagcompensationforcerestore",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Don't test validity of a lag comp restore, just do it.");
  return atexit(func: dynamic_atexit_destructor_for__sv_lagcompensationforcerestore__);
}

//------------------------------------------------------------------------------
// Address: 0x10408290
// Name: _dynamic_initializer_for__sv_unlag_fixstuck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_unlag_fixstuck__()
{
  ConVar::ConVar(
    this: &sv_unlag_fixstuck,
    pName: "sv_unlag_fixstuck",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Disallow backtracking a player for lag compensation if it will cause them to become stuck");
  return atexit(func: dynamic_atexit_destructor_for__sv_unlag_fixstuck__);
}

//------------------------------------------------------------------------------
// Address: 0x104082C0
// Name: _dynamic_initializer_for__sv_lagpushticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_lagpushticks__()
{
  ConVar::ConVar(
    this: &sv_lagpushticks,
    pName: "sv_lagpushticks",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Push computed lag compensation amount by this many ticks.");
  return atexit(func: dynamic_atexit_destructor_for__sv_lagpushticks__);
}

//------------------------------------------------------------------------------
// Address: 0x104082F0
// Name: _dynamic_initializer_for__g_LagCompensationManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_LagCompensationManager__()
{
  CLagCompensationManager::CLagCompensationManager(this: &g_LagCompensationManager, name: "CLagCompensationManager");
  return atexit(func: dynamic_atexit_destructor_for__g_LagCompensationManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10408310
// Name: _dynamic_initializer_for__sv_unlag_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_unlag_debug__()
{
  ConVar::ConVar(this: &sv_unlag_debug, pName: "sv_unlag_debug", pDefaultValue: "0", flags: 6);
  return atexit(func: dynamic_atexit_destructor_for__sv_unlag_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10408340
// Name: _dynamic_initializer_for__g_CPlayerResource_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPlayerResource_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPlayerResource_ClassReg,
           pNetworkName: "CPlayerResource",
           pTable: &DT_PlayerResource::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D150
// Name: _ServerClassInit_DT_LocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_LocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S8_9;
  for ( i = 25; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D180
// Name: _ServerClassInit_DT_BasePlayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BasePlayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S9_6;
  for ( i = 32; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D1A0
// Name: _dynamic_atexit_destructor_for__mp_disable_autokick_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_disable_autokick_command__()
{
  ConCommand::~ConCommand(this: &mp_disable_autokick_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041D1B0
// Name: _ServerClassInit_DT_PlayerState::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PlayerState::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S7_11;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D1D0
// Name: _DataMapInit_CPlayerState__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPlayerState__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_323);
}

//------------------------------------------------------------------------------
// Address: 0x1041D1E0
// Name: _DataMapInit_CBasePlayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBasePlayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_324);
}

//------------------------------------------------------------------------------
// Address: 0x1041D1F0
// Name: _DataMapInit_CStripWeapons__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CStripWeapons__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_325);
}

//------------------------------------------------------------------------------
// Address: 0x1041D200
// Name: _DataMapInit_CRevertSaved__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRevertSaved__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_326);
}

//------------------------------------------------------------------------------
// Address: 0x1041D210
// Name: _DataMapInit_CMovementSpeedMod__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMovementSpeedMod__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_327);
}

//------------------------------------------------------------------------------
// Address: 0x1041D220
// Name: _dynamic_atexit_destructor_for__g_ThrottleMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ThrottleMgr__()
{
  CUtlDict<CBitVec<64>,int>::RemoveAll(this: &g_ThrottleMgr.m_SentMessage);
  CUtlRBTree<CUtlMap<char const *,CBitVec<64>,int>::Node_t,int,CUtlMap<char const *,CBitVec<64>,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBitVec<64>,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CBitVec<64>,int>::Node_t,int,CUtlMap<char const *,CBitVec<64>,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBitVec<64>,int>::Node_t,int>,int>>(this: &g_ThrottleMgr.m_SentMessage.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1041D240
// Name: _dynamic_atexit_destructor_for__g_CBasePlayer_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CBasePlayer_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CBasePlayer_ScriptDesc.m_FunctionBindings);
}

//------------------------------------------------------------------------------
// Address: 0x1041D250
// Name: _dynamic_atexit_destructor_for__sv_unlag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_unlag__()
{
  ConVar::~ConVar(this: &sv_unlag);
}

//------------------------------------------------------------------------------
// Address: 0x1041D260
// Name: _dynamic_atexit_destructor_for__sv_maxunlag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxunlag__()
{
  ConVar::~ConVar(this: &sv_maxunlag);
}

//------------------------------------------------------------------------------
// Address: 0x1041D270
// Name: _dynamic_atexit_destructor_for__sv_lagflushbonecache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_lagflushbonecache__()
{
  ConVar::~ConVar(this: &sv_lagflushbonecache);
}

//------------------------------------------------------------------------------
// Address: 0x1041D280
// Name: _dynamic_atexit_destructor_for__sv_showlagcompensation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_showlagcompensation__()
{
  ConVar::~ConVar(this: &sv_showlagcompensation);
}

//------------------------------------------------------------------------------
// Address: 0x1041D290
// Name: _dynamic_atexit_destructor_for__sv_lagcompensationforcerestore__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_lagcompensationforcerestore__()
{
  ConVar::~ConVar(this: &sv_lagcompensationforcerestore);
}

//------------------------------------------------------------------------------
// Address: 0x1041D2A0
// Name: _dynamic_atexit_destructor_for__sv_unlag_fixstuck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_unlag_fixstuck__()
{
  ConVar::~ConVar(this: &sv_unlag_fixstuck);
}

//------------------------------------------------------------------------------
// Address: 0x1041D2B0
// Name: _dynamic_atexit_destructor_for__sv_lagpushticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_lagpushticks__()
{
  ConVar::~ConVar(this: &sv_lagpushticks);
}

//------------------------------------------------------------------------------
// Address: 0x1041D2C0
// Name: _dynamic_atexit_destructor_for__sv_unlag_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_unlag_debug__()
{
  ConVar::~ConVar(this: &sv_unlag_debug);
}

//------------------------------------------------------------------------------
// Address: 0x1041D2D0
// Name: _dynamic_atexit_destructor_for__g_LagCompensationManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_LagCompensationManager__()
{
  CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl *)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short>>::~CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl *)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short>>(this: &g_LagCompensationManager.m_AdditionalEntities);
  CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_LagCompensationManager.m_CompensatedEntities.m_Tree);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_LagCompensationManager);
}
