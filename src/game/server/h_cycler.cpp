// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/h_cycler.cpp
// Functions: 62
// ============================================================

#include "game\server\h_cycler.h"

//------------------------------------------------------------------------------
// Address: 0x1010D130
// Name: public: virtual void CWreckage::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWreckage::Precache(CEntityFreezing *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( *(_DWORD *)((int (__thiscall *)(CEntityFreezing *, _BYTE *))this->GetModelName)(a1: this, a2: v4) != 0 )
  {
    v3 = *(const char **)((int (__thiscall *)(CEntityFreezing *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
    if ( v3 == nullptr )
      v3 = locale;
    CBaseEntity::PrecacheModel(a1: a2, name: v3, bPreload: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015AA20
// Name: public: virtual struct datamap_t __near * CCycler::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CCycler::GetDataDescMap(CCycler *this)
{
  return &CCycler::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1015AA30
// Name: public: virtual class ServerClass __near * CWeaponCycler::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponCycler::GetServerClass(CWeaponCycler *this)
{
  return &g_CWeaponCycler_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1015AA40
// Name: private: virtual struct datamap_t __near * CWeaponCycler::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWeaponCycler::GetDataDescMap(CWeaponCycler *this)
{
  return &CWeaponCycler::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1015AA50
// Name: public: virtual struct datamap_t __near * CWreckage::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWreckage::GetDataDescMap(CWreckage *this)
{
  return &CWreckage::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1015AA60
// Name: private: virtual struct datamap_t __near * CBlendingCycler::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBlendingCycler::GetDataDescMap(CBlendingCycler *this)
{
  return &CBlendingCycler::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1015AA70
// Name: public: virtual void CWreckage::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWreckage::Think(CWreckage *this)
{
  float m_flDieTime; // xmm0_4
  ITempEntsSystem_vtbl *v3; // esi
  int v4; // eax
  float thinkTime; // [esp+24h] [ebp-44h]
  float v6; // [esp+28h] [ebp-40h]
  CPVSFilter filter; // [esp+30h] [ebp-38h] BYREF
  Vector vecSrc; // [esp+50h] [ebp-18h] BYREF
  Vector vecNormalizedMaxs; // [esp+5Ch] [ebp-Ch] BYREF

  this->StudioFrameAdvance(this);
  thinkTime = gpGlobals->curtime + 0.2;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  m_flDieTime = this->m_flDieTime;
  if ( m_flDieTime == 0.0 )
    goto LABEL_5;
  if ( gpGlobals->curtime > m_flDieTime )
  {
    UTIL_Remove(oldObj: this);
    return;
  }
  if ( ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
         a1: random,
         a2: 0,
         a3: m_flDieTime - this->m_flStartTime) <= this->m_flDieTime - gpGlobals->curtime )
  {
LABEL_5:
    vecNormalizedMaxs.x = 1.0;
    vecNormalizedMaxs.y = 1.0;
    vecNormalizedMaxs.z = 1.0;
    CCollisionProperty::RandomPointInBounds(
      this: &this->m_Collision,
      vecNormalizedMins: &vec3_origin,
      &vecNormalizedMaxs,
      pPoint: &vecSrc);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
    CRecipientFilter::AddRecipientsByPVS(this: &filter, origin: &vecSrc);
    v3 = te->__vftable;
    v4 = random->RandomInt(this: random, a2: 0, a3: 3);
    v6 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int, int))random->RandomFloat)(
           a1: random,
           a2: 0,
           a3: 1084017869,
           a4: v4 + 8)
       + 5.0;
    ((void (__thiscall *)(ITempEntsSystem *, CPVSFilter *, _DWORD, Vector *, int, _DWORD))v3->Smoke)(
      a1: te,
      a2: &filter,
      a3: 0,
      a4: &vecSrc,
      a5: g_sModelIndexSmoke,
      a6: LODWORD(v6));
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015ABF0
// Name: public: virtual bool CBlendingCycler::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBlendingCycler::KeyValue(CBlendingCycler *this, const char *szKeyName, const char *szValue)
{
  if ( szKeyName != "lowboundary" && _V_stricmp(s1: szKeyName, s2: "lowboundary") != 0 )
  {
    if ( szKeyName != "highboundary" && _V_stricmp(s1: szKeyName, s2: "highboundary") != 0 )
    {
      if ( szKeyName != "blendspeed" && _V_stricmp(s1: szKeyName, s2: "blendspeed") != 0 )
      {
        if ( szKeyName != "blendsequence" && _V_stricmp(s1: szKeyName, s2: "blendsequence") != 0 )
        {
          return CAI_BaseNPC::KeyValue(this, szKeyName, szValue);
        }
        else
        {
          this->m_iszSequence.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&szValue).pszValue;
          return 1;
        }
      }
      else
      {
        this->m_iBlendspeed = atoi(nptr: szValue);
        return 1;
      }
    }
    else
    {
      this->m_iUpperBound = atoi(nptr: szValue);
      return 1;
    }
  }
  else
  {
    this->m_iLowerBound = atoi(nptr: szValue);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015ACF0
// Name: public: virtual int CCycler::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCycler::ObjectCaps(CCycler *this)
{
  return CBaseEntity::ObjectCaps(this) | 0x201;
}

//------------------------------------------------------------------------------
// Address: 0x1015AD90
// Name: public: virtual int CBlendingCycler::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBlendingCycler::ObjectCaps(CBlendingCycler *this)
{
  return CBaseEntity::ObjectCaps(this) | 0x80000201;
}

//------------------------------------------------------------------------------
// Address: 0x1015AE50
// Name: public: virtual void CWeaponCycler::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponCycler::Spawn(CWeaponCycler *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  const char *v4; // eax
  const char **v5; // eax
  CWeaponCycler_vtbl *v6; // edx
  int v7; // eax
  Vector vecMin; // [esp+8h] [ebp-1Ch] BYREF
  Vector vecMax; // [esp+14h] [ebp-10h] BYREF
  _BYTE v10[4]; // [esp+20h] [ebp-4h] BYREF

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v3 = *(const char **)((int (__thiscall *)(CWeaponCycler *, _BYTE *))this->GetModelName)(a1: this, a2: v10);
  if ( v3 == nullptr )
    v3 = locale;
  CBaseEntity::PrecacheModel(a1: a2, name: v3, bPreload: true);
  v4 = *(const char **)((int (__thiscall *)(CWeaponCycler *, _BYTE *))this->GetModelName)(a1: this, a2: v10);
  if ( v4 == nullptr )
    v4 = locale;
  this->SetModel(this, a2: v4);
  v5 = (const char **)((int (__thiscall *)(CWeaponCycler *, _BYTE *))this->GetModelName)(a1: this, a2: v10);
  v6 = this->__vftable;
  this->m_iszModel.pszValue = *v5;
  v7 = v6->GetModelIndex(this);
  vecMax.x = 16.0;
  vecMax.y = 16.0;
  vecMax.z = 16.0;
  vecMin.x = -16.0;
  vecMin.y = -16.0;
  this->m_iModel = v7;
  vecMin.z = 0.0;
  UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *)) __thiscall CWeaponCSBase::`vcall'{964,{flat}};
}

//------------------------------------------------------------------------------
// Address: 0x1015B070
// Name: public: virtual void CCycler::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCycler::Use(
        CCycler *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        CBaseEntity *useType,
        float value)
{
  BOOL v5; // eax
  CNetworkVarBase<float,CBaseAnimating::NetworkVar_m_flPlaybackRate> *p_m_flPlaybackRate; // esi
  float m_Value; // xmm0_4
  edict_t *m_pPev; // ecx
  edict_t *v9; // ecx

  v5 = this->m_animate == 0;
  p_m_flPlaybackRate = &this->m_flPlaybackRate;
  this->m_animate = v5;
  m_Value = this->m_flPlaybackRate.m_Value;
  if ( v5 )
  {
    if ( m_Value != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_flPlaybackRate->m_Value = 1.0;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
        p_m_flPlaybackRate->m_Value = 1.0;
      }
    }
  }
  else if ( m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flPlaybackRate->m_Value = 0.0;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x37Cu);
      p_m_flPlaybackRate->m_Value = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B130
// Name: public: virtual int CCycler::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCycler::OnTakeDamage(CCycler *this, const CTakeDamageInfo *info)
{
  int v3; // esi
  edict_t *v4; // ecx
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx

  if ( this->m_animate == 0 )
  {
    if ( this->m_flPlaybackRate.m_Value != 1.0 )
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
      this->m_flPlaybackRate.m_Value = 1.0;
    }
    this->StudioFrameAdvance(this);
    if ( this->m_flPlaybackRate.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x37Cu);
      }
      this->m_flPlaybackRate.m_Value = 0.0;
    }
    _Msg(a1: "sequence: %d, frame %.0f\n", this->m_nSequence.m_Value, this->m_flCycle.m_Value);
    return 0;
  }
  v3 = this->m_nSequence.m_Value + 1;
  if ( !CBaseAnimating::IsValidSequence(this, iSequence: v3) )
    v3 = 0;
  CBaseAnimating::ResetSequence(this, nSequence: v3);
  if ( this->m_flCycle.m_Value == 0.0 )
    return 0;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v4 = this->m_Network.m_pPev;
    if ( v4 != nullptr )
      CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x3ACu);
  }
  this->m_flCycle.m_Value = 0.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015B270
// Name: public: void CCycler::InputSetSequence(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCycler::InputSetSequence(CCycler *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // esi
  int v6; // eax
  float v7; // xmm0_4
  edict_t *m_pPev; // ecx

  if ( this->m_animate != 0 )
  {
    p_value = &inputdata->value;
    if ( inputdata->value.fieldType == FIELD_STRING )
    {
      iVal = (const char *)p_value->iVal;
      if ( iVal != nullptr )
        v5 = iVal;
      else
        v5 = locale;
    }
    else
    {
      v5 = variant_t::ToString(this: p_value);
    }
    v6 = atoi(nptr: v5);
    if ( v6 == 0 && *v5 != 48 )
      v6 = CBaseAnimating::LookupSequence(this, label: v5);
    CBaseAnimating::ResetSequence(this, nSequence: v6);
    v7 = 1.0 - this->m_flFrozen.m_Value;
    if ( v7 >= 0.0 )
    {
      if ( v7 > 1.0 )
        v7 = 1.0;
    }
    else
    {
      v7 = 0.0;
    }
    if ( (float)(this->m_flPlaybackRate.m_Value * v7) == 0.0 )
      CBaseAnimating::ResetSequence(this, nSequence: 0);
    if ( this->m_flCycle.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flCycle.m_Value = 0.0;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
        this->m_flCycle.m_Value = 0.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B370
// Name: public: virtual bool CWeaponCycler::Holster(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponCycler::Holster(CWeaponCycler *this, CBaseCombatWeapon *pSwitchingTo)
{
  CBaseCombatCharacter *Owner; // eax
  float *p_m_Value; // esi
  float v4; // xmm0_4
  CBaseEdict *v6; // ecx

  Owner = CBaseCombatWeapon::GetOwner(this);
  if ( Owner == nullptr )
    return 1;
  p_m_Value = &Owner->m_flNextAttack.m_Value;
  v4 = gpGlobals->curtime + 0.5;
  if ( Owner->m_flNextAttack.m_Value != v4 )
  {
    if ( Owner->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&Owner->m_Network + 76) |= 1u;
      *p_m_Value = v4;
      return 1;
    }
    v6 = &Owner->m_Network.m_pPev->CBaseEdict;
    if ( v6 != nullptr )
      CBaseEdict::StateChanged(this: v6, offset: 0x684u);
    *p_m_Value = v4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015B440
// Name: public: virtual void CCycler::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCycler::Spawn(CCycler *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx

  this->InitBoneControllers(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  else
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  if ( this->m_iHealth.m_Value != 80000 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 80000;
  }
  this->m_pMotor->m_IdealYaw = this->m_angRotation.m_Value.y;
  this->m_pMotor->UpdateYaw(this: this->m_pMotor, a2: 360);
  if ( this->m_flPlaybackRate.m_Value != 1.0 )
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
    this->m_flPlaybackRate.m_Value = 1.0;
  }
  this->m_flGroundSpeed = 0.0;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
  CBaseAnimating::ResetSequenceInfo(this);
  if ( this->m_nSequence.m_Value != 0 || this->m_flCycle.m_Value != 0.0 )
  {
    this->m_animate = 0;
    if ( this->m_flPlaybackRate.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flPlaybackRate.m_Value = 0.0;
      }
      else
      {
        v3 = this->m_Network.m_pPev;
        if ( v3 != nullptr )
          CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x37Cu);
        this->m_flPlaybackRate.m_Value = 0.0;
      }
    }
  }
  else
  {
    this->m_animate = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B610
// Name: public: virtual void CCycler::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCycler::Think(CCycler *this)
{
  CGlobalVars *v2; // ebx
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx

  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  if ( this->m_animate != 0 )
  {
    this->StudioFrameAdvance(this);
    this->DispatchAnimEvents(this, a2: this);
  }
  if ( this->m_bSequenceFinished && !this->m_bSequenceLoops )
  {
    v2 = gpGlobals;
    if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x64u);
      }
      this->m_flAnimTime.m_Value = v2->curtime;
    }
    if ( this->m_flPlaybackRate.m_Value != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v4 = this->m_Network.m_pPev;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x37Cu);
      }
      this->m_flPlaybackRate.m_Value = 1.0;
    }
    this->m_bSequenceFinished = false;
    this->m_flLastEventCheck = 0.0;
    if ( this->m_flCycle.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x3ACu);
      }
      this->m_flCycle.m_Value = 0.0;
    }
    if ( this->m_animate == 0 && this->m_flPlaybackRate.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flPlaybackRate.m_Value = 0.0;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x37Cu);
        this->m_flPlaybackRate.m_Value = 0.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B7A0
// Name: public: virtual bool CWeaponCycler::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponCycler::Deploy(CWeaponCycler *this)
{
  CBaseCombatCharacter *Owner; // eax
  float *p_m_Value; // esi
  float v4; // xmm0_4
  CBaseEdict *v5; // ecx
  edict_t *m_pPev; // ecx
  edict_t *v8; // ecx

  Owner = CBaseCombatWeapon::GetOwner(this);
  if ( Owner == nullptr )
    return 0;
  p_m_Value = &Owner->m_flNextAttack.m_Value;
  v4 = gpGlobals->curtime + 1.0;
  if ( Owner->m_flNextAttack.m_Value != v4 )
  {
    if ( Owner->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&Owner->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = &Owner->m_Network.m_pPev->CBaseEdict;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: 0x684u);
    }
    *p_m_Value = v4;
  }
  this->SendWeaponAnim(this, a2: 0);
  if ( this->m_iClip1.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
    }
    this->m_iClip1.m_Value = 0;
  }
  if ( this->m_iClip2.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iClip2.m_Value = 0;
      return 1;
    }
    v8 = this->m_Network.m_pPev;
    if ( v8 != nullptr )
      CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x4B4u);
    this->m_iClip2.m_Value = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015B8B0
// Name: public: virtual void CWeaponCycler::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCycler::PrimaryAttack(CWeaponCycler *this)
{
  float v2; // xmm0_4
  edict_t *m_pPev; // ecx

  this->SendWeaponAnim(this, a2: this->m_nSequence.m_Value);
  v2 = gpGlobals->curtime + 0.3;
  if ( this->m_flNextPrimaryAttack.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flNextPrimaryAttack.m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
      this->m_flNextPrimaryAttack.m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B940
// Name: public: virtual void CWeaponCycler::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCycler::SecondaryAttack(CWeaponCycler *this)
{
  float v2; // xmm0_4
  edict_t *m_pPev; // ecx

  this->SetModelIndex(this, a2: this->m_iModel);
  this->SetModelIndex(this, a2: 0);
  CBaseAnimating::SetSequence(this, nSequence: 0);
  this->SendWeaponAnim(this, a2: 0);
  v2 = gpGlobals->curtime + 0.3;
  if ( this->m_flNextSecondaryAttack.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flNextSecondaryAttack.m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x498u);
      this->m_flNextSecondaryAttack.m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B9F0
// Name: public: virtual void CWreckage::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWreckage::Spawn(CWreckage *this)
{
  bool (__cdecl *p_m_takedamage)(const char *); // edi
  edict_t *m_pPev; // ecx
  const char *v4; // eax
  const char *v5; // eax
  _BYTE v6[4]; // [esp+14h] [ebp-4h] BYREF

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  p_m_takedamage = (bool (__cdecl *)(const char *))&this->m_takedamage;
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    *(_BYTE *)p_m_takedamage = 0;
  }
  if ( this->m_flCycle.m_Value != 0.0 )
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
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  if ( *(_DWORD *)((int (__thiscall *)(CWreckage *, _BYTE *))this->GetModelName)(a1: this, a2: v6) != 0 )
  {
    v4 = *(const char **)((int (__thiscall *)(CWreckage *, _BYTE *))this->GetModelName)(a1: this, a2: v6);
    if ( v4 == nullptr )
      v4 = locale;
    CBaseEntity::PrecacheModel(a1: p_m_takedamage, name: v4, bPreload: true);
    v5 = *(const char **)((int (__thiscall *)(CWreckage *, _BYTE *))this->GetModelName)(a1: this, a2: v6);
    if ( v5 == nullptr )
      v5 = locale;
    this->SetModel(this, a2: v5);
    this->m_flStartTime = gpGlobals->curtime;
  }
  else
  {
    this->m_flStartTime = gpGlobals->curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BB20
// Name: public: virtual void CBlendingCycler::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlendingCycler::Think(CBlendingCycler *this)
{
  int m_iBlendspeed; // eax
  int m_iCurrent; // ecx
  CStudioHdr *m_pStudioHdr; // eax
  CGlobalVars *v5; // ebx
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  float flValue; // [esp+Ch] [ebp-4h]

  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  m_iBlendspeed = this->m_iBlendspeed;
  this->m_iCurrent += m_iBlendspeed;
  m_iCurrent = this->m_iCurrent;
  if ( m_iCurrent > this->m_iUpperBound || m_iCurrent < this->m_iLowerBound )
    this->m_iBlendspeed = -m_iBlendspeed;
  flValue = (float)this->m_iCurrent;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: m_pStudioHdr, iParameter: 0, flValue);
  _Msg(a1: "Current Blend: %d\n", this->m_iCurrent);
  if ( this->m_bSequenceFinished && !this->m_bSequenceLoops )
  {
    v5 = gpGlobals;
    if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x64u);
      }
      this->m_flAnimTime.m_Value = v5->curtime;
    }
    if ( this->m_flPlaybackRate.m_Value != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x37Cu);
      }
      this->m_flPlaybackRate.m_Value = 1.0;
    }
    this->m_bSequenceFinished = false;
    this->m_flLastEventCheck = 0.0;
    if ( this->m_flCycle.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x3ACu);
      }
      this->m_flCycle.m_Value = 0.0;
    }
    if ( this->m_animate == 0 && this->m_flPlaybackRate.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flPlaybackRate.m_Value = 0.0;
      }
      else
      {
        v9 = this->m_Network.m_pPev;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x37Cu);
        this->m_flPlaybackRate.m_Value = 0.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BD30
// Name: public: void CCycler::GenericCyclerSpawn(char __near *,class Vector,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCycler::GenericCyclerSpawn(CCycler *this, char *szModel, Vector vecMin, Vector vecMax)
{
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( szModel != nullptr && *szModel != 0 )
  {
    this->Precache(this);
    this->SetModel(this, a2: szModel);
    this->m_bloodColor = -1;
    CCycler::Spawn(this);
    UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    _Warning(
      a1: "cycler at %.0f %.0f %0.f missing modelname\n",
      this->m_vecAbsOrigin.x,
      this->m_vecAbsOrigin.y,
      this->m_vecAbsOrigin.z);
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BE10
// Name: public: virtual void CBlendingCycler::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlendingCycler::Spawn(CBlendingCycler *this)
{
  char *v2; // ecx
  const char *pszValue; // eax
  int v4; // eax
  Vector v5; // [esp-18h] [ebp-38h]
  Vector v6; // [esp-Ch] [ebp-2Ch]
  _BYTE v7[4]; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_iLowerBound != 0 || this->m_iUpperBound != 0 )
  {
    v2 = *(char **)((int (__thiscall *)(CBlendingCycler *, _BYTE *))this->GetModelName)(a1: this, a2: v7);
    if ( v2 == nullptr )
      v2 = (char *)locale;
    *(_QWORD *)&v6.x = 0x4180000041800000LL;
    v6.z = 16.0;
    *(_QWORD *)&v5.x = 0xC1800000C1800000uLL;
    v5.z = -16.0;
    CCycler::GenericCyclerSpawn(this, szModel: v2, vecMin: v5, vecMax: v6);
    if ( this->m_iBlendspeed == 0 )
      this->m_iBlendspeed = 5;
    if ( this->m_iszSequence.pszValue != nullptr )
    {
      pszValue = this->m_iszSequence.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v4 = CBaseAnimating::LookupSequence(this, label: pszValue);
      CBaseAnimating::SetSequence(this, nSequence: v4);
    }
    this->m_iCurrent = this->m_iLowerBound;
  }
  else
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BF80
// Name: public: virtual void CGenericCycler::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGenericCycler::Spawn(CGenericCycler *this@<ecx>, int a2@<esi>)
{
  char *v3; // ecx
  Vector v4; // [esp-18h] [ebp-34h]
  Vector v5; // [esp-Ch] [ebp-28h]
  _BYTE v7[4]; // [esp+18h] [ebp-4h] BYREF

  v3 = *(char **)((int (__thiscall *)(CGenericCycler *, _BYTE *, int))this->GetModelName)(a1: this, a2: v7, a3: a2);
  if ( v3 == nullptr )
    v3 = (char *)locale;
  *(_QWORD *)&v5.x = 0x4180000041800000LL;
  v5.z = 72.0;
  *(_QWORD *)&v4.x = 0xC1800000C1800000uLL;
  v4.z = 0.0;
  CCycler::GenericCyclerSpawn(this, szModel: v3, vecMin: v4, vecMax: v5);
}

//------------------------------------------------------------------------------
// Address: 0x104003D0
// Name: _dynamic_initializer_for__cycler_flex__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cycler_flex__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGenericFlexCycler> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cycler_flex,
           a3: "cycler_flex");
}

//------------------------------------------------------------------------------
// Address: 0x10404E80
// Name: _dynamic_initializer_for__cycler_actor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cycler_actor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFlextalkActor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cycler_actor,
           a3: "cycler_actor");
}

//------------------------------------------------------------------------------
// Address: 0x10405160
// Name: CCycler_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CCycler_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CCycler>(__formal: nullptr);
  CCycler_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405170
// Name: _dynamic_initializer_for__cycler__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cycler__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGenericCycler> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cycler,
           a3: "cycler");
}

//------------------------------------------------------------------------------
// Address: 0x104051D0
// Name: DT_WeaponCycler::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCycler::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponCycler::g_SendTable);
  return atexit(func: DT_WeaponCycler::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104051F0
// Name: DT_WeaponCycler::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCycler::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponCycler::ignored>();
  DT_WeaponCycler::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405200
// Name: _dynamic_initializer_for__cycler_weapon__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cycler_weapon__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CWeaponCycler> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cycler_weapon,
           a3: "cycler_weapon");
}

//------------------------------------------------------------------------------
// Address: 0x10405220
// Name: CWeaponCycler_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWeaponCycler_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWeaponCycler>(__formal: nullptr);
  CWeaponCycler_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405230
// Name: CWreckage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWreckage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWreckage>(__formal: nullptr);
  CWreckage_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405240
// Name: _dynamic_initializer_for__cycler_wreckage__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cycler_wreckage__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CWreckage> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cycler_wreckage,
           a3: "cycler_wreckage");
}

//------------------------------------------------------------------------------
// Address: 0x10405260
// Name: _dynamic_initializer_for__cycler_blender__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cycler_blender__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBlendingCycler> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cycler_blender,
           a3: "cycler_blender");
}

//------------------------------------------------------------------------------
// Address: 0x10405280
// Name: CBlendingCycler_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBlendingCycler_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBlendingCycler>(__formal: nullptr);
  CBlendingCycler_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041BF70
// Name: DT_WeaponCycler::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponCycler::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponCycler::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1015BF00
// Name: struct datamap_t __near * DataMapInit<class CCycler>(class CCycler __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CCycler>()
{
  if ( (_S2_135 & 1) == 0 )
  {
    _S2_135 |= 1u;
    nameHolder_234.m_pszBase = "CCycler";
    nameHolder_234.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_234.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_234.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_234.m_Names.m_Size = 0;
    nameHolder_234.m_Names.m_pElements = nullptr;
    nameHolder_234.m_nLenBase = 7;
    atexit(func: DataMapInit_CCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CCycler::m_DataMap.baseMap = &CAI_BaseNPC::m_DataMap;
  CCycler::m_DataMap.dataNumFields = 2;
  CCycler::m_DataMap.dataDesc = &dataDesc_221[1];
  return &CCycler::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1015C020
// Name: struct datamap_t __near * DataMapInit<class CWeaponCycler>(class CWeaponCycler __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWeaponCycler>()
{
  if ( (_S4_37 & 1) == 0 )
  {
    _S4_37 |= 1u;
    nameHolder_235.m_pszBase = "CWeaponCycler";
    nameHolder_235.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_235.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_235.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_235.m_Names.m_Size = 0;
    nameHolder_235.m_Names.m_pElements = nullptr;
    nameHolder_235.m_nLenBase = 13;
    atexit(func: DataMapInit_CWeaponCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWeaponCycler::m_DataMap.baseMap = &CBaseCombatWeapon::m_DataMap;
  CWeaponCycler::m_DataMap.dataNumFields = 2;
  CWeaponCycler::m_DataMap.dataDesc = &dataDesc_222[1];
  return &CWeaponCycler::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1015C0A0
// Name: struct datamap_t __near * DataMapInit<class CWreckage>(class CWreckage __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWreckage>()
{
  if ( (_S5_17 & 1) == 0 )
  {
    _S5_17 |= 1u;
    nameHolder_236.m_pszBase = "CWreckage";
    nameHolder_236.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_236.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_236.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_236.m_Names.m_Size = 0;
    nameHolder_236.m_Names.m_pElements = nullptr;
    nameHolder_236.m_nLenBase = 9;
    atexit(func: DataMapInit_CWreckage__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWreckage::m_DataMap.baseMap = &CAI_BaseNPC::m_DataMap;
  CWreckage::m_DataMap.dataNumFields = 2;
  CWreckage::m_DataMap.dataDesc = &dataDesc_223[1];
  return &CWreckage::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1015C120
// Name: struct datamap_t __near * DataMapInit<class CBlendingCycler>(class CBlendingCycler __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBlendingCycler>()
{
  if ( (_S6_12 & 1) == 0 )
  {
    _S6_12 |= 1u;
    nameHolder_237.m_pszBase = "CBlendingCycler";
    nameHolder_237.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_237.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_237.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_237.m_Names.m_Size = 0;
    nameHolder_237.m_Names.m_pElements = nullptr;
    nameHolder_237.m_nLenBase = 15;
    atexit(func: DataMapInit_CBlendingCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBlendingCycler::m_DataMap.baseMap = &CCycler::m_DataMap;
  CBlendingCycler::m_DataMap.dataNumFields = 5;
  CBlendingCycler::m_DataMap.dataDesc = &dataDesc_224[1];
  return &CBlendingCycler::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10405290
// Name: _dynamic_initializer_for__sv_clearhinthistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_clearhinthistory__()
{
  ConCommand::ConCommand(
    this: &sv_clearhinthistory,
    pName: "sv_clearhinthistory",
    callback: HintClear,
    pHelpString: "Clear memory of server side hints displayed to the player.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_clearhinthistory__);
}

//------------------------------------------------------------------------------
// Address: 0x104052C0
// Name: _dynamic_initializer_for__tv_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tv_delay__()
{
  ConVar::ConVar(
    this: &tv_delay,
    pName: "tv_delay",
    pDefaultValue: "30",
    flags: 0,
    pHelpString: "SourceTV broadcast delay in seconds",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 120.0);
  return atexit(func: dynamic_atexit_destructor_for__tv_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10405310
// Name: _dynamic_initializer_for__tv_allow_static_shots__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tv_allow_static_shots__()
{
  ConVar::ConVar(
    this: &tv_allow_static_shots,
    pName: "tv_allow_static_shots",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Auto director uses fixed level cameras for shots");
  return atexit(func: dynamic_atexit_destructor_for__tv_allow_static_shots__);
}

//------------------------------------------------------------------------------
// Address: 0x10405340
// Name: _dynamic_initializer_for__tv_allow_camera_man__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tv_allow_camera_man__()
{
  ConVar::ConVar(
    this: &tv_allow_camera_man,
    pName: "tv_allow_camera_man",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Auto director allows spectators to become camera man");
  return atexit(func: dynamic_atexit_destructor_for__tv_allow_camera_man__);
}

//------------------------------------------------------------------------------
// Address: 0x10405370
// Name: _dynamic_initializer_for__s_GameSystems__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GameSystems__()
{
  s_GameSystems.m_Memory.m_pMemory = (IGameSystem **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16);
  s_GameSystems.m_Size = 0;
  s_GameSystems.m_pElements = s_GameSystems.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_GameSystems__);
}

//------------------------------------------------------------------------------
// Address: 0x104053A0
// Name: _dynamic_initializer_for__s_GameSystemsPerFrame__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GameSystemsPerFrame__()
{
  s_GameSystemsPerFrame.m_Memory.m_pMemory = (IGameSystemPerFrame **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16);
  s_GameSystemsPerFrame.m_Size = 0;
  s_GameSystemsPerFrame.m_pElements = s_GameSystemsPerFrame.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_GameSystemsPerFrame__);
}

//------------------------------------------------------------------------------
// Address: 0x104053D0
// Name: _dynamic_initializer_for__g_InfoCameraLinkList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_InfoCameraLinkList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_InfoCameraLinkList__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BF80
// Name: _ServerClassInit_DT_WeaponCycler::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponCycler::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_74;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041BFA0
// Name: _DataMapInit_CCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_234);
}

//------------------------------------------------------------------------------
// Address: 0x1041BFB0
// Name: _DataMapInit_CWeaponCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWeaponCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_235);
}

//------------------------------------------------------------------------------
// Address: 0x1041BFC0
// Name: _DataMapInit_CWreckage__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWreckage__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_236);
}

//------------------------------------------------------------------------------
// Address: 0x1041BFD0
// Name: _DataMapInit_CBlendingCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBlendingCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_237);
}

//------------------------------------------------------------------------------
// Address: 0x1041BFE0
// Name: _dynamic_atexit_destructor_for__sv_clearhinthistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_clearhinthistory__()
{
  ConCommand::~ConCommand(this: &sv_clearhinthistory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BFF0
// Name: _dynamic_atexit_destructor_for__tv_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tv_delay__()
{
  ConVar::~ConVar(this: &tv_delay);
}

//------------------------------------------------------------------------------
// Address: 0x1041C000
// Name: _dynamic_atexit_destructor_for__tv_allow_static_shots__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tv_allow_static_shots__()
{
  ConVar::~ConVar(this: &tv_allow_static_shots);
}

//------------------------------------------------------------------------------
// Address: 0x1041C010
// Name: _dynamic_atexit_destructor_for__tv_allow_camera_man__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tv_allow_camera_man__()
{
  ConVar::~ConVar(this: &tv_allow_camera_man);
}

//------------------------------------------------------------------------------
// Address: 0x1041C020
// Name: _dynamic_atexit_destructor_for__s_GameSystems__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GameSystems__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_GameSystems);
}

//------------------------------------------------------------------------------
// Address: 0x1041C030
// Name: _dynamic_atexit_destructor_for__s_GameSystemsPerFrame__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GameSystemsPerFrame__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_GameSystemsPerFrame);
}

//------------------------------------------------------------------------------
// Address: 0x1041C040
// Name: _DataMapInit_CInfoCameraLink__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CInfoCameraLink__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_238);
}

//------------------------------------------------------------------------------
// Address: 0x1041C050
// Name: _dynamic_atexit_destructor_for__g_InfoCameraLinkList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_InfoCameraLinkList__()
{
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *v1; // [esp-4h] [ebp-8h]

  CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::RemoveAll(this: &g_InfoCameraLinkList);
  m_pBlocks = g_InfoCameraLinkList.m_Memory.m_pBlocks;
  if ( g_InfoCameraLinkList.m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v1 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1);
    }
    while ( m_pBlocks != nullptr );
    g_InfoCameraLinkList.m_Memory.m_pBlocks = nullptr;
    g_InfoCameraLinkList.m_Memory.m_nAllocationCount = 0;
  }
}
