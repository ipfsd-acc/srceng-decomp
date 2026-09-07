// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/genericmonster.cpp
// Functions: 26
// ============================================================

#include "game\server\genericmonster.h"

//------------------------------------------------------------------------------
// Address: 0x1001B030
// Name: public: CPASAttenuationFilter::CPASAttenuationFilter(class CBaseEntity __near *,enum soundlevel_t)
// Source: json
//------------------------------------------------------------------------------
CPASAttenuationFilter *__thiscall CPASAttenuationFilter::CPASAttenuationFilter(
        CPASAttenuationFilter *this,
        CBaseEntity *entity,
        soundlevel_t soundlevel)
{
  const Vector *v4; // ebx
  float attenuation; // xmm0_4
  const Vector *v6; // eax
  _BYTE v8[12]; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  v4 = entity->GetSoundEmissionOrigin(this: entity, result: v8);
  CRecipientFilter::CRecipientFilter(this);
  this->__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this, origin: v4);
  this->__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  if ( soundlevel <= SNDLVL_50dB )
  {
    if ( soundlevel != SNDLVL_NONE )
      attenuation = 4.0;
    else
      attenuation = 0.0;
  }
  else
  {
    attenuation = 20.0 / (float)(soundlevel - 50);
  }
  v6 = entity->GetSoundEmissionOrigin(this: entity, result: v8);
  CPASAttenuationFilter::Filter(this, a2: (int)&savedregs, origin: v6, attenuation);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B4BD0
// Name: public: CPASAttenuationFilter::CPASAttenuationFilter(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
CPASAttenuationFilter *__thiscall CPASAttenuationFilter::CPASAttenuationFilter(
        CPASAttenuationFilter *this,
        CBaseEntity *entity,
        float attenuation)
{
  const Vector *v4; // ebx
  const Vector *v5; // eax
  float v7[3]; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  v4 = (const Vector *)((int (__thiscall *)(CBaseEntity *))entity->GetSoundEmissionOrigin)(a1: entity);
  CRecipientFilter::CRecipientFilter(this);
  this->__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this, origin: v4);
  this->__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  v5 = (const Vector *)((int (__thiscall *)(CBaseEntity *, float *, _DWORD))entity->GetSoundEmissionOrigin)(
                         a1: entity,
                         a2: v7,
                         a3: LODWORD(attenuation));
  CPASAttenuationFilter::Filter(this, a2: (int)&savedregs, origin: v5, attenuation: COERCE_FLOAT(v7));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E0EA0
// Name: public: CPASAttenuationFilter::CPASAttenuationFilter(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CPASAttenuationFilter *__thiscall CPASAttenuationFilter::CPASAttenuationFilter(
        CPASAttenuationFilter *this,
        const Vector *origin,
        float attenuation)
{
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CRecipientFilter::CRecipientFilter(this);
  this->__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this, origin);
  this->__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  CPASAttenuationFilter::Filter(this, a2: (int)&savedregs, origin, attenuation);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101551B0
// Name: private: virtual struct datamap_t __near * CNPC_Furniture::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CNPC_Furniture::GetDataDescMap(CNPC_Furniture *this)
{
  return &CNPC_Furniture::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101551D0
// Name: public: virtual void CNPC_Furniture::NPCThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNPC_Furniture::NPCThink(CNPC_Furniture *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CAI_BaseNPC::NPCThink(this, a2, a3);
  CBoneFollowerManager::UpdateBoneFollowers(this: &this->m_BoneFollowerManager, pParentEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x101551F0
// Name: public: virtual void CNPC_Furniture::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNPC_Furniture::DrawDebugGeometryOverlays(
        CNPC_Furniture *this@<ecx>,
        AI_EnemyInfo_t *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  int m_debugOverlays; // eax

  m_debugOverlays = this->m_debugOverlays;
  if ( (m_debugOverlays & 0x10000) != 0 )
    this->m_debugOverlays = m_debugOverlays & 0xFFFEFFFF;
  CAI_BaseNPC::DrawDebugGeometryOverlays(this, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x10155210
// Name: public: CPASAttenuationFilter::CPASAttenuationFilter(class CBaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPASAttenuationFilter *__thiscall CPASAttenuationFilter::CPASAttenuationFilter(
        CPASAttenuationFilter *this,
        CBaseEntity *entity,
        const char *lookupSound)
{
  const Vector *v4; // ebx
  soundlevel_t v5; // eax
  float attenuation; // xmm0_4
  const Vector *v7; // eax
  _BYTE v9[12]; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  v4 = entity->GetSoundEmissionOrigin(this: entity, result: v9);
  CRecipientFilter::CRecipientFilter(this);
  this->__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this, origin: v4);
  this->__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  v5 = CBaseEntity::LookupSoundLevel(soundname: lookupSound);
  if ( v5 <= SNDLVL_50dB )
  {
    if ( v5 != SNDLVL_NONE )
      attenuation = 4.0;
    else
      attenuation = 0.0;
  }
  else
  {
    attenuation = 20.0 / (float)(v5 - 50);
  }
  v7 = entity->GetSoundEmissionOrigin(this: entity, result: v9);
  CPASAttenuationFilter::Filter(this, a2: (int)&savedregs, origin: v7, attenuation);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101552B0
// Name: public: void CGenericNPC::TempGunEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGenericNPC::TempGunEffect(CGenericNPC *this)
{
  edict_t *m_pPev; // esi
  CPASAttenuationFilter filter2; // [esp+1Ch] [ebp-6Ch] BYREF
  QAngle vecAngle; // [esp+3Ch] [ebp-4Ch] BYREF
  Vector start; // [esp+48h] [ebp-40h] BYREF
  Vector end; // [esp+54h] [ebp-34h] BYREF
  Vector vecButt; // [esp+60h] [ebp-28h] BYREF
  Vector vecMuzzle; // [esp+6Ch] [ebp-1Ch] BYREF
  Vector vecDir; // [esp+78h] [ebp-10h] BYREF
  BOOL fSound; // [esp+84h] [ebp-4h]

  CBaseAnimating::GetAttachment(this, iAttachment: 2, absOrigin: &vecMuzzle, absAngles: &vecAngle);
  CBaseAnimating::GetAttachment(this, iAttachment: 3, absOrigin: &vecButt, absAngles: &vecAngle);
  vecDir.x = vecMuzzle.x - vecButt.x;
  vecDir.y = vecMuzzle.y - vecButt.y;
  vecDir.z = vecMuzzle.z - vecButt.z;
  VectorNormalize(vec: &vecDir);
  LOBYTE(fSound) = random->RandomInt(this: random, a2: 0, a3: 3) == 0;
  start.x = (float)(vecDir.x * 64.0) + vecMuzzle.x;
  start.y = (float)(vecDir.y * 64.0) + vecMuzzle.y;
  start.z = (float)(vecDir.z * 64.0) + vecMuzzle.z;
  end.x = (float)(vecDir.x * 4096.0) + vecMuzzle.x;
  end.y = (float)(vecDir.y * 4096.0) + vecMuzzle.y;
  end.z = (float)(vecDir.z * 4096.0) + vecMuzzle.z;
  UTIL_Tracer(
    vecStart: &start,
    vecEnd: &end,
    iEntIndex: 0,
    iAttachment: -1,
    flVelocity: 5500.0,
    bWhiz: fSound,
    pCustomTracerName: nullptr,
    iParticleID: 0);
  CPASAttenuationFilter::CPASAttenuationFilter(this: &filter2, entity: this, lookupSound: "GenericNPC.GunSound");
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  CBaseEntity::EmitSound(
    filter: &filter2,
    iEntIndex: (int)m_pPev,
    soundname: "GenericNPC.GunSound",
    pOrigin: nullptr,
    soundtime: 0.0,
    duration: nullptr);
  CRecipientFilter::~CRecipientFilter(this: &filter2);
}

//------------------------------------------------------------------------------
// Address: 0x10155430
// Name: public: virtual void CGenericNPC::HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGenericNPC::HandleAnimEvent(CGenericNPC *this, animevent_t *pEvent)
{
  int event_lowword; // edx
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( (pEvent->type & 0x400) != 0 )
    event_lowword = pEvent->_event_lowword;
  else
    event_lowword = *(_DWORD *)&pEvent->_event_highword;
  if ( event_lowword == 1 )
    CGenericNPC::TempGunEffect(this);
  else
    CAI_BaseNPC::HandleAnimEvent(this, a2: (CAI_BaseNPC *)&savedregs, pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10155460
// Name: public: virtual void CGenericNPC::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGenericNPC::Precache(CGenericNPC *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  CAI_BaseNPC::Precache(this);
  v3 = *(const char **)((int (__thiscall *)(CGenericNPC *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
  if ( v3 == nullptr )
    v3 = locale;
  CBaseEntity::PrecacheModel(a1: a2, name: v3, bPreload: true);
  CBaseEntity::PrecacheScriptSound(soundname: "GenericNPC.GunSound");
}

//------------------------------------------------------------------------------
// Address: 0x101554A0
// Name: public: virtual int CNPC_Furniture::SelectSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNPC_Furniture::SelectSchedule(CNPC_Furniture *this)
{
  int result; // eax

  switch ( this->m_NPCState )
  {
    case NPC_STATE_NONE:
    case NPC_STATE_IDLE:
    case NPC_STATE_ALERT:
    case NPC_STATE_COMBAT:
    case NPC_STATE_PRONE:
    case NPC_STATE_DEAD:
      result = 56;
      break;
    case NPC_STATE_SCRIPT:
      result = CAI_BehaviorHost<CAI_BaseNPC>::SelectSchedule(this);
      break;
    default:
      _DevWarning(a1: 2, a2: "Invalid State for SelectSchedule!\n");
      result = 82;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10155590
// Name: public: void CNPC_Furniture::UpdateBoneFollowerState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_Furniture::UpdateBoneFollowerState(CNPC_Furniture *this)
{
  CBoneFollowerManager *p_m_BoneFollowerManager; // edi
  physfollower_t *BoneFollower; // eax
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *v11; // eax
  int i; // esi
  physfollower_t *v13; // eax
  CHandle<CBaseEntity> *p_hFollower; // ecx
  unsigned int v15; // eax
  CBaseEntity *v16; // eax
  int m_Value; // [esp-8h] [ebp-14h]

  p_m_BoneFollowerManager = &this->m_BoneFollowerManager;
  if ( this->m_BoneFollowerManager.m_iNumBones != 0 )
  {
    BoneFollower = CBoneFollowerManager::GetBoneFollower(this: &this->m_BoneFollowerManager, iFollowerIndex: 0);
    if ( BoneFollower != nullptr )
    {
      m_Index = BoneFollower->hFollower.m_Index;
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
          v11 = v9 ? v10->m_pEntity : nullptr;
          if ( v11[81].__vftable != (IHandleEntity_vtbl *)this->m_CollisionGroup.m_Value )
          {
            for ( i = 0; i < p_m_BoneFollowerManager->m_iNumBones; ++i )
            {
              v13 = CBoneFollowerManager::GetBoneFollower(this: p_m_BoneFollowerManager, iFollowerIndex: i);
              if ( v13 != nullptr )
              {
                p_hFollower = (CHandle<CBaseEntity> *)&v13->hFollower;
                v15 = v13->hFollower.m_Index;
                if ( v15 != -1
                  && g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber == HIWORD(v15)
                  && g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity != nullptr )
                {
                  m_Value = this->m_CollisionGroup.m_Value;
                  v16 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_hFollower);
                  CBaseEntity::SetCollisionGroup(this: v16, collisionGroup: m_Value);
                }
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155670
// Name: public: virtual void CNPC_Furniture::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_Furniture::UpdateOnRemove(CNPC_Furniture *this)
{
  int i; // esi
  CAI_BehaviorBase *v3; // ecx

  CBoneFollowerManager::DestroyBoneFollowers(this: &this->m_BoneFollowerManager);
  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v3 = this->m_Behaviors.m_Memory.m_pMemory[i];
    v3->UpdateOnRemove(this: v3);
  }
  CAI_BaseNPC::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x101556C0
// Name: public: virtual void CNPC_Furniture::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_Furniture::OnRestore(CNPC_Furniture *this)
{
  int i; // edi
  CAI_BehaviorBase *v3; // ecx

  this->CreateVPhysics(this);
  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v3 = this->m_Behaviors.m_Memory.m_pMemory[i];
    v3->OnRestore(this: v3);
  }
  CAI_BaseNPC::OnRestore(this);
}

//------------------------------------------------------------------------------
// Address: 0x10155710
// Name: public: virtual void CGenericNPC::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGenericNPC::Spawn(CGenericNPC *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  Vector *p_m_vHullMin; // eax
  const char *v6; // eax
  int v7; // edi
  edict_t *m_pPev; // ecx
  Vector *p_m_vHullMax; // [esp-4h] [ebp-68h]
  CGameTrace tr; // [esp+Ch] [ebp-58h] BYREF
  _BYTE v11[4]; // [esp+60h] [ebp-4h] BYREF
  int savedregs; // [esp+64h] [ebp+0h] BYREF

  this->Precache(this);
  v2 = *(const char **)((int (__thiscall *)(CGenericNPC *, _BYTE *))this->GetModelName)(a1: this, a2: v11);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  v3 = *(const char **)((int (__thiscall *)(CGenericNPC *, _BYTE *))this->GetModelName)(a1: this, a2: v11);
  if ( v3 == nullptr )
    v3 = locale;
  if ( v3 == "models/player.mdl" || _V_stricmp(s1: v3, s2: "models/player.mdl") == 0 )
    goto LABEL_12;
  v4 = *(const char **)((int (__thiscall *)(CGenericNPC *, _BYTE *))this->GetModelName)(a1: this, a2: v11);
  if ( v4 == nullptr )
    v4 = locale;
  if ( v4 == "models/holo.mdl" || _V_stricmp(s1: v4, s2: "models/holo.mdl") == 0 )
  {
LABEL_12:
    p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
    p_m_vHullMin = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
  }
  else
  {
    p_m_vHullMax = NAI_Hull::Maxs(id: 0);
    p_m_vHullMin = NAI_Hull::Mins(id: 0);
  }
  UTIL_SetSize(pEnt: this, vecMin: p_m_vHullMin, vecMax: p_m_vHullMax);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_STEP, moveCollide: MOVECOLLIDE_DEFAULT);
  this->m_bloodColor = 0;
  if ( this->m_iHealth.m_Value != 8 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 8;
  }
  this->m_flFieldOfView = 0.5;
  this->m_NPCState = NPC_STATE_NONE;
  CAI_BaseNPC::CapabilitiesAdd(this, capability: 2049);
  this->NPCInit(this);
  if ( (this->m_spawnflags.m_Value & 0x10000) != 0 )
    goto LABEL_30;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  UTIL_TraceEntity(
    pEntity: this,
    vecAbsStart: &this->m_vecAbsOrigin,
    vecAbsEnd: &this->m_vecAbsOrigin,
    mask: 0x200400Bu,
    ptr: &tr);
  if ( tr.startsolid )
  {
    v6 = *(const char **)((int (__thiscall *)(CGenericNPC *, _BYTE *))this->GetModelName)(a1: this, a2: v11);
    if ( v6 == nullptr )
      v6 = locale;
    _Msg(a1: "Placed npc_generic in solid!!! (%s)\n", v6);
    v7 = this->m_spawnflags.m_Value | 0x10000;
    if ( this->m_spawnflags.m_Value != v7 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v7;
    }
  }
  if ( (this->m_spawnflags.m_Value & 0x10000) != 0 )
  {
LABEL_30:
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    if ( this->m_takedamage.m_Value != 0 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      this->m_takedamage.m_Value = 0;
    }
    this->VPhysicsDestroyObject(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155980
// Name: public: virtual void CNPC_Furniture::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_Furniture::Spawn(CNPC_Furniture *this)
{
  const char *v2; // eax
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  _BYTE v5[4]; // [esp+8h] [ebp-4h] BYREF

  this->Precache(this);
  v2 = *(const char **)((int (__thiscall *)(CNPC_Furniture *, _BYTE *))this->GetModelName)(a1: this, a2: v5);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_STEP, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseCombatCharacter::SetBloodColor(this, nBloodColor: -1);
  if ( this->m_iHealth.m_Value != 1000 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 1000;
  }
  if ( this->m_takedamage.m_Value != 3 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 3;
  }
  CBaseAnimating::SetSequence(this, nSequence: 0);
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
  CAI_BaseNPC::SetNavType(this, navType: NAV_FLY);
  CBaseEntity::AddFlag(this, flags: 2048);
  CAI_BaseNPC::CapabilitiesAdd(this, capability: 8392708);
  this->m_iEFlags |= 0x10000000u;
  CBaseAnimating::ResetSequenceInfo(this);
  if ( this->m_flCycle.m_Value != 0.0 )
  {
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
  }
  this->NPCInit(this);
  CBaseEntity::SetBlocksLOS(this, bBlocksLOS: true);
  this->m_pSenses->m_iSensingFlags |= 3u;
}

//------------------------------------------------------------------------------
// Address: 0x10155B30
// Name: public: void CNPC_Furniture::InputDisablePlayerCollision(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_Furniture::InputDisablePlayerCollision(CNPC_Furniture *this, inputdata_t *inputdata)
{
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 18);
  CNPC_Furniture::UpdateBoneFollowerState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10155B50
// Name: public: void CNPC_Furniture::InputEnablePlayerCollision(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_Furniture::InputEnablePlayerCollision(CNPC_Furniture *this, inputdata_t *inputdata)
{
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 9);
  CNPC_Furniture::UpdateBoneFollowerState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10155B70
// Name: public: virtual int CNPC_Furniture::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNPC_Furniture::OnTakeDamage(CNPC_Furniture *this, const CTakeDamageInfo *info)
{
  float m_flDamage; // xmm0_4
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // esi
  int v5; // edi

  m_flDamage = info->m_flDamage;
  p_m_iHealth = &this->m_iHealth;
  if ( m_flDamage >= (float)this->m_iHealth.m_Value )
  {
    v5 = (int)(float)(m_flDamage + 1000.0);
    if ( p_m_iHealth->m_Value != v5 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      p_m_iHealth->m_Value = v5;
    }
  }
  return CBaseCombatCharacter::OnTakeDamage(this, info);
}

//------------------------------------------------------------------------------
// Address: 0x10178630
// Name: public: virtual void CNPC_Furniture::UpdateEfficiency(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_Furniture::UpdateEfficiency(CNPC_Furniture *this, bool bInPVS)
{
  this->m_Efficiency = this->m_SleepState != AISS_AWAKE ? AIE_DORMANT : AIE_NORMAL;
  this->m_MoveEfficiency = AIME_NORMAL;
}

//------------------------------------------------------------------------------
// Address: 0x10404EA0
// Name: _dynamic_initializer_for__monster_generic__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__monster_generic__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGenericNPC> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &monster_generic,
           a3: "monster_generic");
}

//------------------------------------------------------------------------------
// Address: 0x10404EC0
// Name: _dynamic_initializer_for__monster_furniture__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__monster_furniture__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CNPC_Furniture> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &monster_furniture,
           a3: "monster_furniture");
}

//------------------------------------------------------------------------------
// Address: 0x10404F00
// Name: CNPC_Furniture_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CNPC_Furniture_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CNPC_Furniture>(__formal: nullptr);
  CNPC_Furniture_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10155BD0
// Name: struct datamap_t __near * DataMapInit<class CNPC_Furniture>(class CNPC_Furniture __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CNPC_Furniture>()
{
  if ( (_S2_131 & 1) == 0 )
  {
    _S2_131 |= 1u;
    nameHolder_229.m_pszBase = "CNPC_Furniture";
    nameHolder_229.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_229.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_229.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_229.m_Names.m_Size = 0;
    nameHolder_229.m_Names.m_pElements = nullptr;
    nameHolder_229.m_nLenBase = 14;
    atexit(func: DataMapInit_CNPC_Furniture__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CNPC_Furniture::m_DataMap.baseMap = &CAI_BaseActor::m_DataMap;
  CNPC_Furniture::m_DataMap.dataNumFields = 3;
  CNPC_Furniture::m_DataMap.dataDesc = &dataDesc_217[1];
  return &CNPC_Furniture::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10155C50
// Name: class CNPC_Furniture __near * _CreateEntityTemplate<class CNPC_Furniture>(class CNPC_Furniture __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNPC_Furniture *__cdecl _CreateEntityTemplate<CNPC_Furniture>(CNPC_Furniture *newEnt, const char *className)
{
  CAI_BaseActor *v2; // eax
  CAI_BaseActor *v3; // esi

  v2 = (CAI_BaseActor *)CBaseEntity::operator new(stAllocateBlock: 0x10B4u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CAI_BaseActor::CAI_BaseActor(this: v2);
    v3->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CAI_BaseActor_vtbl *)&CNPC_Furniture::`vftable'{for `CBaseCombatCharacter'};
    v3->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CNPC_Furniture::`vftable'{for `CAI_DefMovementSink'};
    v3->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::IAI_BehaviorBridge::__vftable = (IAI_BehaviorBridge_vtbl *)&CNPC_Furniture::`vftable'{for `IAI_BehaviorBridge'};
    v3->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CNPC_Furniture::`vftable';
    CBoneFollowerManager::CBoneFollowerManager(this: (CBoneFollowerManager *)&v3[1]);
    v3->PostConstructor(this: v3, a2: className);
    return (CNPC_Furniture *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10404EE0
// Name: _dynamic_initializer_for__npc_furniture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__npc_furniture__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CNPC_Furniture> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &npc_furniture,
           a3: "npc_furniture");
}
