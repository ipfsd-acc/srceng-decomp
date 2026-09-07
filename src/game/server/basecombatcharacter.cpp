// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/basecombatcharacter.cpp
// Functions: 114
// ============================================================

#include "game\server\basecombatcharacter.h"

//------------------------------------------------------------------------------
// Address: 0x1002D890
// Name: public: virtual bool CBaseCombatCharacter::FVisible(class Vector const __near &,int,class CBaseEntity __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatCharacter::FVisible(
        CBaseCombatCharacter *this,
        const Vector *vecTarget,
        unsigned int traceMask,
        CBaseEntity **ppBlocker)
{
  return CBaseEntity::FVisible(this, vecTarget, traceMask, ppBlocker);
}

//------------------------------------------------------------------------------
// Address: 0x100A1E10
// Name: public: void CNavArea::DecrementPlayerCount(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::DecrementPlayerCount(CNavArea *this, int teamID, int entIndex)
{
  unsigned __int8 v3; // dl

  v3 = this->m_playerCount[teamID % 2];
  if ( v3 != 0 )
    this->m_playerCount[teamID % 2] = v3 - 1;
  else
    DevMsg(a1: "CNavArea::IncrementPlayerCount: Underflow\n");
}

//------------------------------------------------------------------------------
// Address: 0x100A1E50
// Name: public: virtual struct datamap_t __near * CBaseCombatCharacter::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseCombatCharacter::GetDataDescMap(CBaseCombatCharacter *this)
{
  return &CBaseCombatCharacter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100A1E60
// Name: public: virtual class ServerClass __near * CBaseCombatCharacter::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseCombatCharacter::GetServerClass(CBaseCombatCharacter *this)
{
  return &g_CBaseCombatCharacter_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100A1E70
// Name: public: static int CBaseCombatCharacter::GetInteractionID(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CBaseCombatCharacter::GetInteractionID()
{
  return ++CBaseCombatCharacter::m_lastInteraction;
}

//------------------------------------------------------------------------------
// Address: 0x100A1E80
// Name: public: bool CVisibilityCacheEntryLess::operator()(struct VisibilityCacheEntry_t const __near &,struct VisibilityCacheEntry_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVisibilityCacheEntryLess::operator()(
        CVisibilityCacheEntryLess *this,
        const VisibilityCacheEntry_t *lhs,
        const VisibilityCacheEntry_t *rhs)
{
  unsigned int v5; // eax
  int v7; // eax

  v5 = 8;
  while ( lhs->pEntity1 == rhs->pEntity1 )
  {
    v5 -= 4;
    rhs = (const VisibilityCacheEntry_t *)((char *)rhs + 4);
    lhs = (const VisibilityCacheEntry_t *)((char *)lhs + 4);
    if ( v5 < 4 )
      return false;
  }
  v7 = LOBYTE(lhs->pEntity1) - LOBYTE(rhs->pEntity1);
  if ( v7 == 0 )
  {
    v7 = BYTE1(lhs->pEntity1) - BYTE1(rhs->pEntity1);
    if ( v7 == 0 )
    {
      v7 = BYTE2(lhs->pEntity1) - BYTE2(rhs->pEntity1);
      if ( v7 == 0 )
        v7 = HIBYTE(lhs->pEntity1) - HIBYTE(rhs->pEntity1);
    }
  }
  return v7 >> 31 < 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A1EF0
// Name: public: virtual bool CBaseCombatCharacter::FInViewCone(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::FInViewCone(CBaseCombatCharacter *this, CBaseEntity *pEntity)
{
  CBaseCombatCharacter_vtbl *v3; // edi
  const Vector *v4; // eax

  v3 = this->__vftable;
  v4 = pEntity->WorldSpaceCenter(this: pEntity);
  return v3->FInViewCone(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100A1F20
// Name: public: virtual bool CBaseCombatCharacter::FInAimCone(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::FInAimCone(CBaseCombatCharacter *this, CBaseEntity *pEntity)
{
  CBaseCombatCharacter_vtbl *v4; // edi
  int v5; // eax
  int v6; // eax
  _BYTE v8[12]; // [esp+Ch] [ebp-18h] BYREF
  _BYTE v9[12]; // [esp+18h] [ebp-Ch] BYREF
  CBaseEntity *pEntitya; // [esp+2Ch] [ebp+8h]

  v4 = this->__vftable;
  pEntitya = (CBaseEntity *)pEntity->__vftable;
  v5 = ((int (__thiscall *)(CBaseCombatCharacter *, _BYTE *, int))this->EyePosition)(a1: this, a2: v9, a3: 1);
  v6 = ((int (__thiscall *)(CBaseEntity *, _BYTE *, int))LODWORD(pEntitya->m_flSpeed))(a1: pEntity, a2: v8, a3: v5);
  return v4->FInAimCone(this, a2: (const Vector *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x100A1F80
// Name: public: virtual bool CBaseCombatCharacter::Weapon_SlotOccupied(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::Weapon_SlotOccupied(CBaseCombatCharacter *this, CBaseCombatWeapon *pWeapon)
{
  CBaseCombatCharacter_vtbl *v4; // edi
  int v5; // eax

  if ( pWeapon == nullptr )
    return false;
  v4 = this->__vftable;
  v5 = pWeapon->GetSlot(this: pWeapon);
  return v4->Weapon_GetSlot(this, a2: v5) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A1FC0
// Name: public: virtual bool CBaseCombatCharacter::Weapon_CanUse(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatCharacter::Weapon_CanUse(CBaseCombatCharacter *this, CBaseCombatWeapon *pWeapon)
{
  int v4; // eax
  int v6; // ebx
  int *i; // esi
  Activity v8; // eax
  int actCount; // [esp+8h] [ebp-4h]
  acttable_t *pTable; // [esp+14h] [ebp+8h]

  pTable = pWeapon->ActivityList(this: pWeapon);
  v4 = pWeapon->ActivityListCount(this: pWeapon);
  actCount = v4;
  if ( v4 < 1 )
    return 0;
  v6 = 0;
  for ( i = &pTable->weaponAct; *((_BYTE *)i + 4) == 0; i += 3 )
  {
LABEL_8:
    if ( ++v6 >= v4 )
      return 1;
  }
  v8 = this->NPC_TranslateActivity(this, a2: (Activity)*i);
  if ( CBaseAnimating::SelectWeightedSequence(this, activity: v8) != -1 )
  {
    v4 = actCount;
    goto LABEL_8;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A2050
// Name: public: virtual class Vector CBaseCombatCharacter::BodyDirection3D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseCombatCharacter::BodyDirection3D(CBaseCombatCharacter *this, Vector *result)
{
  QAngle angles; // [esp+4h] [ebp-Ch] BYREF

  this->BodyAngles(this, result: &angles);
  AngleVectors(&angles, forward: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2080
// Name: public: static void CBaseCombatCharacter::SetDefaultRelationship(enum Class_T,enum Class_T,enum Disposition_t,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseCombatCharacter::SetDefaultRelationship(
        Class_T nClass,
        Class_T nClassTarget,
        Disposition_t nDisposition,
        int nPriority)
{
  Class_T v4; // eax

  if ( CBaseCombatCharacter::m_DefaultRelationship != nullptr )
  {
    v4 = nClassTarget;
    CBaseCombatCharacter::m_DefaultRelationship[nClass][v4].disposition = nDisposition;
    CBaseCombatCharacter::m_DefaultRelationship[nClass][v4].priority = nPriority;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A20C0
// Name: public: enum Disposition_t CBaseCombatCharacter::GetDefaultRelationshipDisposition(enum Class_T)
// Source: json
//------------------------------------------------------------------------------
Disposition_t __thiscall CBaseCombatCharacter::GetDefaultRelationshipDisposition(
        CBaseCombatCharacter *this,
        Class_T nClassTarget)
{
  return CBaseCombatCharacter::m_DefaultRelationship[this->Classify(this)][nClassTarget].disposition;
}

//------------------------------------------------------------------------------
// Address: 0x100A20F0
// Name: public: int CBaseCombatCharacter::GiveAmmo(int,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatCharacter::GiveAmmo(
        CBaseCombatCharacter *this,
        int iCount,
        const char *szName,
        BOOL bSuppressSound)
{
  CAmmoDef *AmmoDef; // eax
  int v6; // eax

  AmmoDef = GetAmmoDef();
  v6 = CAmmoDef::Index(this: AmmoDef, psz: szName);
  if ( v6 != -1 )
    return this->GiveAmmo(this, a2: iCount, a3: v6, a4: bSuppressSound);
  _Msg(a1: "ERROR: Attempting to give unknown ammo type (%s)\n", szName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A2140
// Name: public: virtual struct impactdamagetable_t const __near & CBaseCombatCharacter::GetPhysicsImpactDamageTable(void)
// Source: json
//------------------------------------------------------------------------------
const impactdamagetable_t *__thiscall CBaseCombatCharacter::GetPhysicsImpactDamageTable(CBaseCombatCharacter *this)
{
  return &gDefaultNPCImpactDamageTable;
}

//------------------------------------------------------------------------------
// Address: 0x100A2150
// Name: public: void CBaseCombatCharacter::InputKilledNPC(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::InputKilledNPC(CBaseCombatCharacter *this, inputdata_t *inputdata)
{
  CBaseCombatCharacter *v3; // eax

  if ( inputdata->pActivator != nullptr )
  {
    v3 = inputdata->pActivator->MyCombatCharacterPointer(this: inputdata->pActivator);
    this->OnKilledNPC(this, a2: v3);
  }
  else
  {
    this->OnKilledNPC(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2190
// Name: public: virtual void CBaseCombatCharacter::DoMuzzleFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::DoMuzzleFlash(CBaseCombatCharacter *this)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  if ( ActiveWeapon != nullptr )
    CBaseAnimating::DoMuzzleFlash(this: ActiveWeapon);
  else
    CBaseAnimating::DoMuzzleFlash(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A21B0
// Name: public: virtual bool CBaseCombatCharacter::IsHiddenByFog(float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::IsHiddenByFog(CBaseCombatCharacter *this, float range)
{
  return ((double (__stdcall *)(_DWORD))this->GetFogObscuredRatio)(a1: LODWORD(range)) >= 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100A21E0
// Name: public: virtual bool CBaseCombatCharacter::GetFogParams(struct fogparams_t __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::GetFogParams(CBaseCombatCharacter *this, fogparams_t *fog)
{
  return fog != nullptr && GetWorldFogParams(character: this, fog);
}

//------------------------------------------------------------------------------
// Address: 0x100A2200
// Name: public: virtual bool CBaseCombatCharacter::IsAreaTraversable(class CNavArea const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::IsAreaTraversable(CBaseCombatCharacter *this, CNavArea *area)
{
  CNavArea_vtbl *v2; // edi
  int TeamNumber; // eax

  if ( area == nullptr )
    return false;
  v2 = area->__vftable;
  TeamNumber = CBaseEntity::GetTeamNumber(this);
  return !v2->IsBlocked(this: area, a2: TeamNumber, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100A2240
// Name: public: virtual void CBaseCombatCharacter::OnNavAreaRemoved(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::OnNavAreaRemoved(CBaseCombatCharacter *this, CNavArea *removedArea)
{
  if ( this->m_lastNavArea == removedArea )
    this->ClearLastKnownArea(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A2260
// Name: public: virtual void CBaseCombatCharacter::ChangeTeam(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::ChangeTeam(CBaseCombatCharacter *this, int iTeamNum)
{
  this->ClearLastKnownArea(this);
  CBaseEntity::ChangeTeam(this, iTeamNum);
}

//------------------------------------------------------------------------------
// Address: 0x100A2280
// Name: public: virtual bool CBaseCombatCharacter::HasEverBeenInjured(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::HasEverBeenInjured(CBaseCombatCharacter *this, int team)
{
  if ( team == -1 )
    return this->m_hasBeenInjured != 0;
  else
    return ((1 << team) & this->m_hasBeenInjured) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A22B0
// Name: public: virtual bool CBaseCombatCharacter::FInViewCone(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::FInViewCone(CBaseCombatCharacter *this, const Vector *vecSpot)
{
  Vector *(__thiscall *EyeDirection2D)(CBaseCombatCharacter *, Vector *); // edx
  float *v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  bool v10; // cf
  Vector v12; // [esp+8h] [ebp-18h] BYREF
  Vector eyepos; // [esp+14h] [ebp-Ch] BYREF
  float vecSpota; // [esp+28h] [ebp+8h]

  this->EyePosition(this, result: &eyepos);
  EyeDirection2D = this->EyeDirection2D;
  eyepos.z = vecSpot->z;
  vecSpota = this->m_flFieldOfView;
  v5 = (float *)EyeDirection2D(this, result: &v12);
  v6 = vecSpot->x - eyepos.x;
  v7 = vecSpot->y - eyepos.y;
  v8 = vecSpot->z - eyepos.z;
  v9 = (float)((float)(v5[1] * v7) + (float)(v6 * *v5)) + (float)(v5[2] * v8);
  if ( vecSpota > 0.0 )
  {
    if ( v9 < 0.0 )
      return false;
    v10 = (float)(v9 * v9) < (float)((float)((float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8))
                                           * vecSpota)
                                   * vecSpota);
  }
  else
  {
    if ( v9 > 0.0 )
      return true;
    v10 = (float)((float)((float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8)) * vecSpota) * vecSpota) < (float)(v9 * v9);
  }
  return !v10;
}

//------------------------------------------------------------------------------
// Address: 0x100A23B0
// Name: public: virtual bool CBaseCombatCharacter::FInAimCone(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::FInAimCone(CBaseCombatCharacter *this, const Vector *vecSpot)
{
  Vector facingDir; // [esp+4h] [ebp-18h] BYREF
  Vector los; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  los.x = vecSpot->x - this->m_vecAbsOrigin.x;
  los.y = vecSpot->y - this->m_vecAbsOrigin.y;
  los.z = 0.0;
  VectorNormalize(vec: &los);
  this->BodyDirection2D(this, result: &facingDir);
  return (float)((float)((float)(los.x * facingDir.x) + (float)(facingDir.y * los.y)) + (float)(facingDir.z * los.z)) > 0.994;
}

//------------------------------------------------------------------------------
// Address: 0x100A2460
// Name: public: virtual enum Activity CBaseCombatCharacter::Weapon_TranslateActivity(enum Activity,bool __near *)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CBaseCombatCharacter::Weapon_TranslateActivity(
        CBaseCombatCharacter *this,
        Activity baseAct,
        bool *pRequired)
{
  unsigned int m_Index; // edx
  Activity result; // eax
  int v5; // ecx
  CEntInfo *v6; // esi
  unsigned int v7; // edx
  int v8; // ecx
  bool v9; // zf
  CEntInfo *v10; // ecx

  m_Index = this->m_hActiveWeapon.m_Value.m_Index;
  result = baseAct;
  if ( m_Index != -1
    && (v5 = (unsigned __int16)m_Index,
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v7 = HIWORD(m_Index),
        v6->m_SerialNumber == v7)
    && v6->m_pEntity != nullptr )
  {
    v8 = v5;
    v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
    v10 = &g_pEntityList->m_EntPtrArray[v8];
    if ( v9 )
      return ((Activity (__thiscall *)(IHandleEntity *, Activity, bool *))v10->m_pEntity->__vftable[116].dtr_IHandleEntity)(
               a1: v10->m_pEntity,
               a2: baseAct,
               a3: pRequired);
    else
      return (*(Activity (__stdcall **)(Activity, bool *))(MEMORY[0] + 1392))(a1: baseAct, a2: pRequired);
  }
  else if ( pRequired != nullptr )
  {
    *pRequired = false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A24E0
// Name: public: void CBaseCombatCharacter::Weapon_SetActivity(enum Activity,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::Weapon_SetActivity(
        CBaseCombatCharacter *this,
        Activity newActivity,
        float duration)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hActiveWeapon.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = &g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        m_pEntity = v9->m_pEntity;
      else
        m_pEntity = nullptr;
      ((void (__thiscall *)(IHandleEntity *, Activity, _DWORD))m_pEntity->__vftable[102].SetRefEHandle)(
        a1: m_pEntity,
        a2: newActivity,
        a3: LODWORD(duration));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2550
// Name: public: virtual void CBaseCombatCharacter::Weapon_FrameUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::Weapon_FrameUpdate(CBaseCombatCharacter *this)
{
  unsigned int m_Index; // edx
  int v2; // eax
  CEntInfo *v3; // esi
  unsigned int v4; // edx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax

  m_Index = this->m_hActiveWeapon.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v2 = (unsigned __int16)m_Index;
    v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v4 = HIWORD(m_Index);
    if ( v3->m_SerialNumber == v4 && v3->m_pEntity != nullptr )
    {
      v5 = v2;
      v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4;
      v7 = &g_pEntityList->m_EntPtrArray[v5];
      if ( v6 )
        ((void (__thiscall *)(IHandleEntity *, CBaseCombatCharacter *))v7->m_pEntity->__vftable[121].dtr_IHandleEntity)(
          a1: v7->m_pEntity,
          a2: this);
      else
        (*(void (__thiscall **)(_DWORD, CBaseCombatCharacter *))(MEMORY[0] + 1452))(a1: 0, a2: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A25B0
// Name: public: virtual bool CBaseCombatCharacter::BecomeRagdollBoogie(class CBaseEntity __near *,class Vector const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatCharacter::BecomeRagdollBoogie(
        CBaseCombatCharacter *this,
        CBaseEntity *pKiller,
        const Vector *forceVector,
        float duration,
        int flags)
{
  const Vector *v7; // eax
  const Vector *v9; // [esp+Ch] [ebp-C8h]
  CTakeDamageInfo info; // [esp+1Ch] [ebp-B8h] BYREF
  CTakeDamageInfo ragdollInfo; // [esp+78h] [ebp-5Ch] BYREF
  CBaseEntity *pRagdoll; // [esp+DCh] [ebp+8h]

  CTakeDamageInfo::CTakeDamageInfo(
    this: &info,
    pInflictor: pKiller,
    pAttacker: pKiller,
    flDamage: 1.0,
    bitsDamageType: 0,
    iKillType: 0,
    iObjectsPenetrated: 0);
  info.m_vecDamageForce = *forceVector;
  pRagdoll = CreateServerRagdoll(pAnimating: this, forceBone: 0, &info, collisionGroup: 3, bUseLRURetirement: true);
  v9 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
  v7 = this->m_Collision.OBBMins(this: &this->m_Collision);
  CBaseEntity::SetCollisionBounds(this: pRagdoll, mins: v7, maxs: v9);
  CRagdollBoogie::Create(
    pTarget: pRagdoll,
    flMagnitude: 200.0,
    flStartTime: gpGlobals->curtime,
    flLengthTime: duration,
    nSpawnFlags: flags);
  CTakeDamageInfo::CTakeDamageInfo(
    this: &ragdollInfo,
    pInflictor: pKiller,
    pAttacker: pKiller,
    flDamage: 10000.0,
    bitsDamageType: 0x400000,
    iKillType: 0,
    iObjectsPenetrated: 0);
  ragdollInfo.m_vecDamagePosition = *this->WorldSpaceCenter(this);
  ragdollInfo.m_vecDamageForce.x = 0.0;
  ragdollInfo.m_vecDamageForce.y = 0.0;
  ragdollInfo.m_vecDamageForce.z = 1.0;
  CBaseEntity::TakeDamage(this, a2: (int)this, inputInfo: &ragdollInfo);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A2710
// Name: public: virtual bool CBaseCombatCharacter::BecomeRagdoll(class CTakeDamageInfo const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::BecomeRagdoll(
        CBaseCombatCharacter *this,
        const CTakeDamageInfo *info,
        const Vector *forceVector)
{
  int m_iEFlags; // ecx
  float v5; // xmm0_4
  CBaseEntity *v6; // eax
  CTakeDamageInfo info2; // [esp+8h] [ebp-68h] BYREF
  Vector pos; // [esp+64h] [ebp-Ch]
  int savedregs; // [esp+70h] [ebp+0h] BYREF

  if ( (info->m_bitsDamageType & 0x10) == 0 || g_pGameRules->IsMultiplayer(this: g_pGameRules) )
  {
    CTakeDamageInfo::CTakeDamageInfo(this: &info2, __that: info);
    return this->BecomeRagdollOnClient(this, a2: forceVector);
  }
  else
  {
    CTakeDamageInfo::CTakeDamageInfo(this: &info2, __that: info);
    m_iEFlags = this->m_iEFlags;
    info2.m_vecDamageForce = *forceVector;
    pos = info2.m_vecDamagePosition;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v5 = this->m_vecAbsOrigin.z + this->m_Collision.OBBMins(this: &this->m_Collision)->z;
    if ( (float)(pos.z - v5) < 24.0 )
    {
      info2.m_vecDamagePosition.x = pos.x;
      info2.m_vecDamagePosition.y = pos.y;
      info2.m_vecDamagePosition.z = v5 + 24.0;
    }
    v6 = CreateServerRagdoll(
           pAnimating: this,
           forceBone: this->m_nForceBone.m_Value,
           info: &info2,
           collisionGroup: 3,
           bUseLRURetirement: true);
    this->FixupBurningServerRagdoll(this, a2: v6);
    CBaseEntity::RemoveDeferred(this);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2840
// Name: public: virtual void CBaseCombatCharacter::Weapon_HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::Weapon_HandleAnimEvent(CBaseCombatCharacter *this, animevent_t *pEvent)
{
  unsigned int m_Index; // edx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hActiveWeapon.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      ((void (__thiscall *)(IHandleEntity *, animevent_t *, CBaseCombatCharacter *))m_pEntity->__vftable[121].SetRefEHandle)(
        a1: m_pEntity,
        a2: pEvent,
        a3: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A28A0
// Name: public: virtual int CBaseCombatCharacter::TakeHealth(float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatCharacter::TakeHealth(CBaseCombatCharacter *this, float flHealth, int bitsDamageType)
{
  if ( this->m_takedamage.m_Value != 0 )
    return CBaseEntity::TakeHealth(this, flHealth, bitsDamageType);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A28D0
// Name: public: virtual class QAngle CBaseCombatCharacter::BodyAngles(void)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall CBaseCombatCharacter::BodyAngles(CBaseCombatCharacter *this, QAngle *result)
{
  float z; // ecx
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_angAbsRotation.z;
  *(_QWORD *)&result->x = *(_QWORD *)&this->m_angAbsRotation.x;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2910
// Name: public: virtual class Vector CBaseCombatCharacter::BodyDirection2D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__userpurge CBaseCombatCharacter::BodyDirection2D@<eax>(
        CBaseCombatCharacter *this@<ecx>,
        int a2@<esi>,
        Vector *result)
{
  float v3; // xmm1_4
  Vector *v4; // eax
  float v5; // [esp-10h] [ebp-1Ch]

  ((void (__thiscall *)(CBaseCombatCharacter *, Vector *, int))this->BodyDirection3D)(a1: this, a2: result, a3: a2);
  v3 = (float)(result->x * result->x) + (float)(result->y * result->y);
  result->z = 0.0;
  v5 = fsqrt(v3);
  v4 = result;
  if ( v5 == 0.0 )
  {
    result->y = 0.0;
    result->x = 0.0;
  }
  else
  {
    result->x = result->x * (float)(1.0 / v5);
    result->y = result->y * (float)(1.0 / v5);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100A29C0
// Name: public: virtual class Vector CBaseCombatCharacter::Weapon_ShootPosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseCombatCharacter::Weapon_ShootPosition(CBaseCombatCharacter *this, Vector *result)
{
  float z; // xmm0_4
  int m_iEFlags; // edx
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float x; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm6_4
  float y; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm7_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  Vector forward; // [esp+4h] [ebp-48h] BYREF
  Vector right; // [esp+10h] [ebp-3Ch] BYREF
  Vector up; // [esp+1Ch] [ebp-30h] BYREF
  float v22; // [esp+28h] [ebp-24h]
  float v23; // [esp+2Ch] [ebp-20h]
  float v24; // [esp+30h] [ebp-1Ch]
  float v25; // [esp+34h] [ebp-18h]
  float v26; // [esp+38h] [ebp-14h]
  float v27; // [esp+3Ch] [ebp-10h]
  float v28; // [esp+40h] [ebp-Ch]
  float v29; // [esp+44h] [ebp-8h]
  float v30; // [esp+48h] [ebp-4h]
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  AngleVectors(angles: &this->m_angAbsRotation, &forward, &right, &up);
  z = this->m_HackedGunPos.z;
  m_iEFlags = this->m_iEFlags;
  v5 = up.x * z;
  v6 = up.y * z;
  v7 = up.z * z;
  x = this->m_HackedGunPos.x;
  v23 = right.y * x;
  v9 = right.z * x;
  v10 = right.x * x;
  y = this->m_HackedGunPos.y;
  v24 = v9;
  v12 = forward.x * y;
  v13 = forward.y * y;
  v14 = forward.z * y;
  v28 = v5;
  v29 = v6;
  v30 = v7;
  v22 = v10;
  v25 = forward.x * y;
  v26 = forward.y * y;
  v27 = forward.z * y;
  if ( (m_iEFlags & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v6 = v29;
    v5 = v28;
    v7 = v30;
    v10 = v22;
    v12 = v25;
    v13 = v26;
    v14 = v27;
  }
  v16 = (float)((float)(this->m_vecAbsOrigin.x + v12) + v10) + v5;
  v17 = (float)((float)(this->m_vecAbsOrigin.y + v13) + v23) + v6;
  v18 = (float)((float)(this->m_vecAbsOrigin.z + v14) + v24) + v7;
  result->x = v16;
  result->y = v17;
  result->z = v18;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2B20
// Name: public: bool CBaseCombatCharacter::Weapon_IsOnGround(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::Weapon_IsOnGround(CBaseCombatCharacter *this, CBaseCombatWeapon *pWeapon)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( pWeapon->m_pConstraint != nullptr )
    return false;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  return COERCE_FLOAT(COERCE_UNSIGNED_INT(pWeapon->WorldSpaceCenter(this: pWeapon)->z - this->m_vecAbsOrigin.z) & _mask__AbsFloat_) < 12.0;
}

//------------------------------------------------------------------------------
// Address: 0x100A2B80
// Name: public: void CBaseCombatCharacter::ApplyStressDamage(class IPhysicsObject __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::ApplyStressDamage(
        CBaseCombatCharacter *this,
        IPhysicsObject *pPhysics,
        bool bRequireLargeObject)
{
  CWorld *v5; // eax
  float v6; // xmm0_4
  unsigned int v7; // eax
  CWorld *WorldEntity; // [esp-Ch] [ebp-90h]
  CTakeDamageInfo dmgInfo; // [esp+1Ch] [ebp-68h] BYREF
  vphysics_objectstress_t stressOut; // [esp+78h] [ebp-Ch] BYREF
  int savedregs; // [esp+84h] [ebp+0h] BYREF
  float pPhysicsa; // [esp+8Ch] [ebp+8h]

  pPhysicsa = pPhysics->GetMass(this: pPhysics);
  CalculateObjectStress(pObject: pPhysics, pInputOwnerEntity: this, pOutput: &stressOut);
  if ( stressOut.hasNonStaticStress
    && (float)((float)(this->m_impactEnergyScale * stressOut.receivedStress) / pPhysicsa) > phys_stressbodyweights.m_pParent->m_Value.m_fValue
    && (((int (__thiscall *)(IPhysicsObject *))pPhysics->GetGameFlags)(a1: pPhysics) & 0x40) == 0
    && (!bRequireLargeObject || stressOut.hasLargeObjectContact) )
  {
    WorldEntity = GetWorldEntity();
    v5 = GetWorldEntity();
    CTakeDamageInfo::CTakeDamageInfo(
      this: &dmgInfo,
      pInflictor: v5,
      pAttacker: WorldEntity,
      damageForce: &vec3_origin,
      damagePosition: &vec3_origin,
      flDamage: 200.0,
      bitsDamageType: 1,
      iKillType: 0,
      reportedPosition: nullptr,
      iObjectsPenetrated: 0);
    v6 = (float)(sv_gravity.m_pParent->m_Value.m_fValue * stressOut.receivedStress) * gpGlobals->frametime;
    v7 = (unsigned int)this->m_iEFlags >> 11;
    dmgInfo.m_vecDamageForce.x = 0.0;
    dmgInfo.m_vecDamageForce.y = 0.0;
    LODWORD(dmgInfo.m_vecDamageForce.z) = LODWORD(v6) ^ _mask__NegFloat_;
    if ( (v7 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    dmgInfo.m_vecDamagePosition = this->m_vecAbsOrigin;
    CBaseEntity::TakeDamage(this, a2: (int)this, inputInfo: &dmgInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2CB0
// Name: public: virtual class Vector CBaseCombatCharacter::GetAttackSpread(class CBaseCombatWeapon __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseCombatCharacter::GetAttackSpread(
        CBaseCombatCharacter *this,
        Vector *result,
        CBaseCombatWeapon *pWeapon,
        CBaseEntity *pTarget)
{
  if ( pWeapon != nullptr )
  {
    pWeapon->GetBulletSpread(this: pWeapon, result, a3: this->m_CurrentWeaponProficiency);
    return result;
  }
  else
  {
    result->x = 0.13053;
    result->y = 0.13053;
    result->z = 0.13053;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2D00
// Name: public: virtual float CBaseCombatCharacter::GetSpreadBias(class CBaseCombatWeapon __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatCharacter::GetSpreadBias(
        CBaseCombatCharacter *this,
        CBaseCombatWeapon *pWeapon,
        CBaseEntity *pTarget)
{
  if ( pWeapon != nullptr )
    return pWeapon->GetSpreadBias(this: pWeapon, a2: this->m_CurrentWeaponProficiency);
  else
    return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100A2D30
// Name: public: virtual class CBaseEntity __near * CBaseCombatCharacter::FindMissTarget(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseCombatCharacter::FindMissTarget(CBaseCombatCharacter *this)
{
  int v2; // edi
  CBasePlayer *LocalPlayer; // ebx
  float z; // ecx
  int v5; // esi
  CBaseEntity *v6; // ecx
  CBaseEntity *v7; // ecx
  CBaseEntity *v8; // ecx
  CBaseEntity *pEnts[256]; // [esp+Ch] [ebp-470h] BYREF
  CBaseEntity *pMissCandidates[16]; // [esp+40Ch] [ebp-70h]
  CFlaggedEntitiesEnum pEnum; // [esp+44Ch] [ebp-30h] BYREF
  Vector maxs; // [esp+460h] [ebp-1Ch] BYREF
  int numEnts; // [esp+46Ch] [ebp-10h]
  Vector vecSource; // [esp+470h] [ebp-Ch] BYREF
  int savedregs; // [esp+47Ch] [ebp+0h] BYREF

  v2 = 0;
  LocalPlayer = UTIL_GetLocalPlayer();
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&vecSource.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  maxs.x = vecSource.x + 100.0;
  maxs.y = vecSource.y + 100.0;
  maxs.z = z + 100.0;
  vecSource.x = vecSource.x - 100.0;
  vecSource.y = vecSource.y - 100.0;
  vecSource.z = z - 100.0;
  CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(this: &pEnum, pList: pEnts, listMax: 256, flagMask: 0);
  v5 = 0;
  numEnts = UTIL_EntitiesInBox(mins: &vecSource, &maxs, &pEnum);
  if ( numEnts <= 0 )
    return nullptr;
  do
  {
    if ( pEnts[v5] != nullptr && (LocalPlayer == nullptr || LocalPlayer->FInViewCone(this: LocalPlayer, a2: pEnts[v5])) )
    {
      if ( v2 >= 16 )
        break;
      v6 = pEnts[v5];
      if ( v6 != nullptr
        && (v6->m_iClassname.pszValue == "prop_dynamic"
         || CBaseEntity::ClassMatchesComplex(this: v6, pszClassOrWildcard: "prop_dynamic") != 0)
        || (v7 = pEnts[v5]) != nullptr
        && (v7->m_iClassname.pszValue == "prop_physics"
         || CBaseEntity::ClassMatchesComplex(this: v7, pszClassOrWildcard: "prop_physics") != 0)
        || (v8 = pEnts[v5]) != nullptr
        && (v8->m_iClassname.pszValue == "physics_prop"
         || CBaseEntity::ClassMatchesComplex(this: v8, pszClassOrWildcard: "physics_prop") != 0) )
      {
        pMissCandidates[v2++] = pEnts[v5];
      }
    }
    ++v5;
  }
  while ( v5 < numEnts );
  if ( v2 != 0 )
    return pMissCandidates[random->RandomInt(this: random, a2: 0, a3: v2 - 1)];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A2ED0
// Name: public: virtual bool CBaseCombatCharacter::IsHiddenByFog(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBaseCombatCharacter::IsHiddenByFog@<eax>(
        CBaseCombatCharacter *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        const Vector *target)
{
  float v7[6]; // [esp+1Ch] [ebp-18h] BYREF
  float retaddr; // [esp+34h] [ebp+0h]

  v7[3] = a2;
  v7[4] = retaddr;
  ((void (__thiscall *)(CBaseCombatCharacter *, float *, int))this->EyePosition)(a1: this, a2: v7, a3);
  return ((int (__thiscall *)(_DWORD, _DWORD))this->IsHiddenByFog)(
           a1: this,
           a2: fsqrt(
             (float)((float)((float)(v7[1] - target->y) * (float)(v7[1] - target->y))
                   + (float)((float)(v7[2] - target->z) * (float)(v7[2] - target->z)))
           + (float)((float)(v7[0] - target->x) * (float)(v7[0] - target->x))));
}

//------------------------------------------------------------------------------
// Address: 0x100A2F60
// Name: public: virtual bool CBaseCombatCharacter::IsHiddenByFog(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CBaseCombatCharacter::IsHiddenByFog@<al>(
        CBaseCombatCharacter *this@<ecx>,
        int a2@<ebp>,
        CBaseEntity *target)
{
  const Vector *v5; // eax
  bool (__thiscall *IsHiddenByFog)(CBaseCombatCharacter *, float); // edx
  __int128 v7; // xmm0
  __int128 v8; // [esp+18h] [ebp-1Ch] BYREF
  int v9; // [esp+28h] [ebp-Ch]
  void *v10; // [esp+2Ch] [ebp-8h]
  void *retaddr; // [esp+34h] [ebp+0h]

  v9 = a2;
  v10 = retaddr;
  if ( target == nullptr )
    return false;
  this->EyePosition(this, result: (Vector *)((char *)&v8 + 4));
  v5 = target->WorldSpaceCenter(this: target);
  IsHiddenByFog = this->IsHiddenByFog;
  v7 = 0;
  *(float *)&v7 = fsqrt(
                    (float)((float)((float)(*((float *)&v8 + 2) - v5->y) * (float)(*((float *)&v8 + 2) - v5->y))
                          + (float)((float)(*((float *)&v8 + 3) - v5->z) * (float)(*((float *)&v8 + 3) - v5->z)))
                  + (float)((float)(*((float *)&v8 + 1) - v5->x) * (float)(*((float *)&v8 + 1) - v5->x)));
  v8 = v7;
  return ((int (__thiscall *)(CBaseCombatCharacter *, _DWORD))IsHiddenByFog)(a1: this, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100A3010
// Name: public: virtual float CBaseCombatCharacter::GetFogObscuredRatio(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseCombatCharacter::GetFogObscuredRatio(
        CBaseCombatCharacter *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        const Vector *target)
{
  float v6[6]; // [esp+1Ch] [ebp-18h] BYREF
  float retaddr; // [esp+34h] [ebp+0h]

  v6[3] = a2;
  v6[4] = retaddr;
  ((void (__thiscall *)(CBaseCombatCharacter *, float *, int))this->EyePosition)(a1: this, a2: v6, a3);
  ((void (__thiscall *)(_DWORD, _DWORD))this->GetFogObscuredRatio)(
    a1: this,
    a2: fsqrt(
      (float)((float)((float)(v6[1] - target->y) * (float)(v6[1] - target->y))
            + (float)((float)(v6[2] - target->z) * (float)(v6[2] - target->z)))
    + (float)((float)(v6[0] - target->x) * (float)(v6[0] - target->x))));
}

//------------------------------------------------------------------------------
// Address: 0x100A30A0
// Name: public: virtual float CBaseCombatCharacter::GetFogObscuredRatio(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
double __userpurge CBaseCombatCharacter::GetFogObscuredRatio@<st0>(
        CBaseCombatCharacter *this@<ecx>,
        int a2@<ebp>,
        CBaseEntity *target)
{
  double result; // st7
  const Vector *v5; // eax
  float (__thiscall *GetFogObscuredRatio)(CBaseCombatCharacter *, float); // edx
  __int128 v7; // xmm0
  __int128 v8; // [esp+18h] [ebp-1Ch] BYREF
  int v9; // [esp+28h] [ebp-Ch]
  void *v10; // [esp+2Ch] [ebp-8h]
  void *retaddr; // [esp+34h] [ebp+0h]

  v9 = a2;
  v10 = retaddr;
  if ( target == nullptr )
    return 0.0;
  this->EyePosition(this, result: (Vector *)((char *)&v8 + 4));
  v5 = target->WorldSpaceCenter(this: target);
  GetFogObscuredRatio = this->GetFogObscuredRatio;
  v7 = 0;
  *(float *)&v7 = fsqrt(
                    (float)((float)((float)(*((float *)&v8 + 2) - v5->y) * (float)(*((float *)&v8 + 2) - v5->y))
                          + (float)((float)(*((float *)&v8 + 3) - v5->z) * (float)(*((float *)&v8 + 3) - v5->z)))
                  + (float)((float)(*((float *)&v8 + 1) - v5->x) * (float)(*((float *)&v8 + 1) - v5->x)));
  v8 = v7;
  ((void (__thiscall *)(CBaseCombatCharacter *, _DWORD))GetFogObscuredRatio)(a1: this, a2: v7);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3150
// Name: public: virtual void CBaseCombatCharacter::ClearLastKnownArea(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::ClearLastKnownArea(CBaseCombatCharacter *this)
{
  CNavArea *m_lastNavArea; // edx
  int v3; // eax
  unsigned __int8 v4; // cl

  this->OnNavAreaChanged(this, a2: nullptr, a3: this->m_lastNavArea);
  m_lastNavArea = this->m_lastNavArea;
  if ( m_lastNavArea != nullptr )
  {
    v3 = this->m_registeredNavTeam % 2;
    v4 = m_lastNavArea->m_playerCount[v3];
    if ( v4 != 0 )
      m_lastNavArea->m_playerCount[v3] = v4 - 1;
    else
      DevMsg(a1: "CNavArea::IncrementPlayerCount: Underflow\n");
    this->m_lastNavArea->OnExit(this: this->m_lastNavArea, a2: this, a3: nullptr);
    this->m_lastNavArea = nullptr;
    this->m_registeredNavTeam = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A32B0
// Name: public: void CBaseCombatCharacter::NetworkVar_m_iAmmo::Set(int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::NetworkVar_m_iAmmo::Set(
        CBaseCombatCharacter::NetworkVar_m_iAmmo *this,
        int i,
        int *val)
{
  int *v3; // esi

  v3 = &this->m_Value[i];
  if ( *v3 != *val )
  {
    (*(void (__thiscall **)(char *, int *))(*((_DWORD *)this - 453) + 1348))(a1: (char *)this - 1812, a2: v3);
    *v3 = *val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A33B0
// Name: public: virtual void CBaseCombatCharacter::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::UpdateOnRemove(CBaseCombatCharacter *this)
{
  CBaseEntityList *v1; // esi
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *p_m_hMyWeapons; // edi
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CBaseEntity **v10; // eax
  CBaseEntity *v11; // eax
  unsigned int v12; // eax
  IHandleEntity *m_pEntity; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v1 = g_pEntityList;
  p_m_hMyWeapons = &this->m_hMyWeapons;
  for ( i = 64; i != 0; --i )
  {
    m_Index = p_m_hMyWeapons->m_Value[0].m_Index;
    if ( p_m_hMyWeapons->m_Value[0].m_Index != -1 )
    {
      v5 = (unsigned __int16)m_Index;
      v6 = &v1->m_EntPtrArray[(unsigned __int16)m_Index];
      v7 = HIWORD(m_Index);
      if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
      {
        v8 = v5;
        v9 = v1->m_EntPtrArray[v8].m_SerialNumber == v7;
        v10 = (CBaseEntity **)&v1->m_EntPtrArray[v8];
        if ( v9 )
          v11 = *v10;
        else
          v11 = nullptr;
        UTIL_Remove(oldObj: v11);
        v1 = g_pEntityList;
      }
    }
    p_m_hMyWeapons = (CBaseCombatCharacter::NetworkVar_m_hMyWeapons *)((char *)p_m_hMyWeapons + 4);
  }
  _V_memset(dest: this->m_weaponIDToIndex, fill: 0, count: 42);
  v12 = this->m_hOwnerEntity.m_Value.m_Index;
  if ( v12 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == HIWORD(v12) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      m_pEntity->__vftable[19].SetRefEHandle(this: m_pEntity, a2: (const CBaseHandle *)this);
      this->SetOwnerEntity(this, a2: nullptr);
    }
  }
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A3490
// Name: public: virtual bool CBaseCombatCharacter::CorpseGib(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatCharacter::CorpseGib(CBaseCombatCharacter *this, const CTakeDamageInfo *info)
{
  CBaseEntity::EmitSound(this, soundname: "BaseCombatCharacter.CorpseGib", soundtime: 0.0, duration: nullptr);
  if ( this->HasHumanGibs(this) )
  {
    CGib::SpawnHeadGib(pVictim: this);
    CGib::SpawnRandomGibs(pVictim: this, cGibs: 4, eGibType: GIB_HUMAN);
    return 1;
  }
  else if ( this->HasAlienGibs(this) )
  {
    CGib::SpawnRandomGibs(pVictim: this, cGibs: 4, eGibType: GIB_ALIEN);
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3500
// Name: public: virtual enum Activity CBaseCombatCharacter::GetDeathActivity(void)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CBaseCombatCharacter::GetDeathActivity(CBaseCombatCharacter *this)
{
  Activity result; // eax
  char v3; // bl
  Activity v4; // edi
  int m_LastHitGroup; // eax
  float v6; // xmm0_4
  int v7; // eax
  const char *v8; // eax
  CGameTrace tr; // [esp+4h] [ebp-94h] BYREF
  Vector hullMin; // [esp+58h] [ebp-40h] BYREF
  Vector hullMax; // [esp+64h] [ebp-34h] BYREF
  Vector vecAbsEnd; // [esp+70h] [ebp-28h] BYREF
  float flDot; // [esp+7Ch] [ebp-1Ch] BYREF
  Vector forward; // [esp+80h] [ebp-18h] BYREF
  Vector vecSrc; // [esp+8Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  if ( !this->IsPlayer(this) )
  {
LABEL_11:
    vecSrc = *this->WorldSpaceCenter(this);
    v3 = 0;
    v4 = ACT_DIESIMPLE;
    AngleVectors(angles: &this->m_angRotation.m_Value, &forward);
    m_LastHitGroup = this->m_LastHitGroup;
    LODWORD(v6) = COERCE_UNSIGNED_INT(
                    (float)((float)(forward.y * g_vecAttackDir.y) + (float)(g_vecAttackDir.x * forward.x))
                  + (float)(g_vecAttackDir.z * forward.z))
                ^ _mask__NegFloat_;
    flDot = v6;
    if ( m_LastHitGroup != 0 )
    {
      v7 = m_LastHitGroup - 1;
      if ( v7 == 0 )
      {
        v4 = ACT_DIE_HEADSHOT;
        goto LABEL_20;
      }
      if ( v7 == 2 )
      {
        v4 = ACT_DIE_GUTSHOT;
        goto LABEL_20;
      }
    }
    v3 = 1;
    if ( v6 <= 0.3 )
    {
      if ( v6 <= -0.3 )
        v4 = ACT_DIEBACKWARD;
    }
    else
    {
      v4 = ACT_DIEFORWARD;
    }
LABEL_20:
    if ( CBaseAnimating::SelectWeightedSequence(this, activity: v4) == -1 )
    {
      if ( v3 != 0 )
      {
        v4 = ACT_DIESIMPLE;
      }
      else if ( flDot <= 0.3 )
      {
        if ( flDot <= -0.3 )
          v4 = ACT_DIEBACKWARD;
      }
      else
      {
        v4 = ACT_DIEFORWARD;
      }
    }
    if ( CBaseAnimating::SelectWeightedSequence(this, activity: v4) == -1 )
    {
      v4 = ACT_DIESIMPLE;
      if ( CBaseAnimating::SelectWeightedSequence(this, activity: ACT_DIESIMPLE) == -1 )
      {
        v8 = *(const char **)((int (__thiscall *)(CBaseCombatCharacter *, float *))this->GetModelName)(
                               a1: this,
                               a2: &flDot);
        if ( v8 == nullptr )
          v8 = locale;
        _Msg(a1: "ERROR! %s missing ACT_DIESIMPLE\n", v8);
        return ACT_DIESIMPLE;
      }
      return v4;
    }
    if ( v4 == ACT_DIEFORWARD )
    {
      vecAbsEnd.x = 16.0;
      vecAbsEnd.y = 16.0;
      vecAbsEnd.z = 18.0;
      hullMin.x = -16.0;
      hullMin.y = -16.0;
      hullMin.z = -18.0;
      hullMax.x = (float)(forward.x * 64.0) + vecSrc.x;
      hullMax.y = (float)(forward.y * 64.0) + vecSrc.y;
      hullMax.z = (float)(forward.z * 64.0) + vecSrc.z;
      UTIL_TraceHull(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: &vecSrc,
        vecAbsEnd: &hullMax,
        &hullMin,
        hullMax: &vecAbsEnd,
        mask: 0x200400Bu,
        ignore: this,
        collisionGroup: 0,
        ptr: &tr);
    }
    else
    {
      if ( v4 != ACT_DIEBACKWARD )
        return v4;
      hullMax.x = 16.0;
      hullMax.y = 16.0;
      hullMax.z = 18.0;
      hullMin.x = -16.0;
      hullMin.y = -16.0;
      hullMin.z = -18.0;
      vecAbsEnd.y = vecSrc.y - (float)(forward.y * 64.0);
      vecAbsEnd.x = vecSrc.x - (float)(forward.x * 64.0);
      vecAbsEnd.z = vecSrc.z - (float)(forward.z * 64.0);
      UTIL_TraceHull(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: &vecSrc,
        &vecAbsEnd,
        &hullMin,
        &hullMax,
        mask: 0x200400Bu,
        ignore: this,
        collisionGroup: 0,
        ptr: &tr);
    }
    if ( tr.fraction != 1.0 )
      return ACT_DIESIMPLE;
    return v4;
  }
  switch ( random->RandomInt(this: random, a2: 0, a3: 7) )
  {
    case 0:
      result = ACT_DIESIMPLE;
      break;
    case 1:
      result = ACT_DIEBACKWARD;
      break;
    case 2:
      result = ACT_DIEFORWARD;
      break;
    case 3:
      result = ACT_DIEVIOLENT;
      break;
    case 4:
      result = ACT_DIE_HEADSHOT;
      break;
    case 5:
      result = ACT_DIE_CHESTSHOT;
      break;
    case 6:
      result = ACT_DIE_GUTSHOT;
      break;
    case 7:
      result = ACT_DIE_BACKSHOT;
      break;
    default:
      goto LABEL_11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A38A0
// Name: public: virtual class CBaseEntity __near * CBaseCombatCharacter::CheckTraceHullAttack(float,class Vector const __near &,class Vector const __near &,float,int,float,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseCombatCharacter::CheckTraceHullAttack(
        CBaseCombatCharacter *this,
        float flDist,
        const Vector *mins,
        const Vector *maxs,
        float flDamage,
        int iDmgType,
        float forceScale,
        int bDamageAnyNPC)
{
  float z; // ecx
  Vector *v10; // eax
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  CBaseEntity *(__thiscall *CheckTraceHullAttack)(CBaseCombatCharacter *, const Vector *, const Vector *, const Vector *, const Vector *, float, int, float, bool); // edx
  Vector vEnd; // [esp+14h] [ebp-24h] BYREF
  Vector forward; // [esp+20h] [ebp-18h] BYREF
  Vector vStart; // [esp+2Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  AngleVectors(angles: &this->m_angAbsRotation, &forward);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&vStart.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  vStart.z = z;
  v10 = AllocTempVector();
  v10->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
  v10->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
  v11 = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
  v10->z = v11;
  v12 = v11 * 0.5;
  v13 = maxs->z;
  if ( v13 > v12 )
    v12 = v13 + 1.0;
  CheckTraceHullAttack = this->CheckTraceHullAttack;
  vEnd.z = (float)(forward.z * flDist) + (float)(vStart.z + v12);
  vStart.z = vStart.z + v12;
  vEnd.x = vStart.x + (float)(forward.x * flDist);
  vEnd.y = vStart.y + (float)(forward.y * flDist);
  return ((CBaseEntity *(__thiscall *)(CBaseCombatCharacter *, Vector *, Vector *, const Vector *, const Vector *, _DWORD, int, _DWORD, int))CheckTraceHullAttack)(
           a1: this,
           a2: &vStart,
           a3: &vEnd,
           a4: mins,
           a5: maxs,
           a6: LODWORD(flDamage),
           a7: iDmgType,
           a8: LODWORD(forceScale),
           a9: bDamageAnyNPC);
}

//------------------------------------------------------------------------------
// Address: 0x100A39F0
// Name: public: virtual bool CTraceFilterMelee::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterMelee::ShouldHitEntity(
        CTraceFilterMelee *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  CBaseEntity *v4; // esi
  CBaseEntity *Attacker; // eax
  float *v6; // ebx
  float *v7; // eax
  CBaseEntity *v8; // eax
  const Vector *v9; // eax
  CBaseEntity *v10; // eax
  int v11; // ebx
  int v12; // eax
  CBaseEntity *v13; // eax
  float flScale; // [esp+24h] [ebp-84h]
  CTakeDamageInfo info; // [esp+34h] [ebp-74h] BYREF
  Vector vecOrigin; // [esp+90h] [ebp-18h] BYREF
  Vector attackDir; // [esp+9Ch] [ebp-Ch] BYREF

  if ( !StandardFilterRules(pHandleEntity, fContentsMask: contentsMask) )
    return 0;
  if ( !PassServerEntityFilter(pTouch: pHandleEntity, pPass: this->m_pPassEnt) )
    return 0;
  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity) )
    return 0;
  v4 = (CBaseEntity *)pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity);
  if ( v4 == nullptr
    || !v4->ShouldCollide(this: v4, a2: this->m_collisionGroup, a3: contentsMask)
    || !g_pGameRules->ShouldCollide(this: g_pGameRules, a2: this->m_collisionGroup, a3: v4->m_CollisionGroup.m_Value)
    || v4->m_takedamage.m_Value == 0 )
  {
    return 0;
  }
  Attacker = CTakeDamageInfo::GetAttacker(this: this->m_dmgInfo);
  v6 = (float *)Attacker->WorldSpaceCenter(this: Attacker);
  v7 = (float *)v4->WorldSpaceCenter(this: v4);
  attackDir.x = *v7 - *v6;
  attackDir.y = v7[1] - v6[1];
  attackDir.z = v7[2] - v6[2];
  VectorNormalize(vec: &attackDir);
  CTakeDamageInfo::CTakeDamageInfo(this: &info, __that: this->m_dmgInfo);
  v8 = CTakeDamageInfo::GetAttacker(this: &info);
  flScale = this->m_flForceScale;
  v9 = v8->WorldSpaceCenter(this: v8);
  CalculateMeleeDamageForce(&info, vecMeleeDir: &attackDir, vecForceOrigin: v9, flScale);
  v10 = CTakeDamageInfo::GetAttacker(this: &info);
  v11 = (int)v10->MyCombatCharacterPointer(this: v10);
  v12 = (int)v4->MyCombatCharacterPointer(this: v4);
  if ( v11 == 0 || v12 == 0 )
  {
    this->m_pHit = v4;
    Pickup_ForcePlayerToDropThisObject(pTarget: v4);
    if ( info.m_flDamage != 0.0 )
      CBaseEntity::TakeDamage(this: v4, a2: (int)v4, inputInfo: &info);
    return 0;
  }
  if ( !this->m_bDamageAnyNPC
    && (*(int (__thiscall **)(int, CBaseEntity *))(*(_DWORD *)v11 + 1252))(a1: v11, a2: v4) != 1 )
  {
    return 0;
  }
  if ( info.m_flDamage != 0.0 )
    CBaseEntity::TakeDamage(this: v4, a2: (int)v4, inputInfo: &info);
  vecOrigin = info.m_vecDamagePosition;
  v13 = CTakeDamageInfo::GetAttacker(this: &info);
  CSoundEnt::InsertSound(
    iType: 1,
    &vecOrigin,
    iVolume: 200,
    flDuration: 0.2,
    pOwner: v13,
    soundChannelIndex: 0,
    pSoundTarget: nullptr);
  this->m_pHit = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A3C20
// Name: public: virtual class Vector CBaseCombatCharacter::CalcDeathForceVector(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseCombatCharacter::CalcDeathForceVector(
        CBaseCombatCharacter *this,
        Vector *result,
        const CTakeDamageInfo *info)
{
  bool v5; // al
  float z; // edx
  unsigned int m_Index; // eax
  CBaseCombatCharacter *m_pEntity; // esi
  unsigned int v9; // eax
  const Vector *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm0_4
  float x; // xmm2_4
  float y; // xmm1_4
  float v15; // xmm0_4
  double v16; // st7
  IPhysicsObject *m_pPhysicsObject; // edi
  float v18; // xmm1_4
  float v19; // xmm2_4
  double v21; // st7
  __int64 v22; // xmm0_8
  float v23; // ecx
  double v24; // xmm0_8
  float v25; // xmm0_4
  Vector forceVector; // [esp+28h] [ebp-Ch] BYREF
  float forceScale; // [esp+40h] [ebp+Ch]
  float forceScalea; // [esp+40h] [ebp+Ch]

  v5 = g_pGameRules->Damage_NoPhysicsForce(this: g_pGameRules, a2: info->m_bitsDamageType);
  z = info->m_vecDamageForce.z;
  *(_QWORD *)&forceVector.x = *(_QWORD *)&info->m_vecDamageForce.x;
  forceVector.z = z;
  if ( vec3_origin.x == forceVector.x && vec3_origin.y == forceVector.y && vec3_origin.z == forceVector.z && !v5 )
  {
    m_Index = info->m_hInflictor.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseCombatCharacter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr
      || ((v9 = info->m_hAttacker.m_Index) == -1
       || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9)
        ? (m_pEntity = nullptr)
        : (m_pEntity = (CBaseCombatCharacter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity),
          m_pEntity != nullptr) )
    {
      forceScale = (float)(info->m_flDamage * 75.0) * 4.0;
      if ( (info->m_bitsDamageType & 0x40) != 0 )
      {
        v10 = CBaseEntity::WorldAlignSize(this);
        v11 = this->m_vecOrigin.m_Value.y - m_pEntity->m_vecOrigin.m_Value.y;
        v12 = (float)(this->m_vecOrigin.m_Value.z + v10->z) - m_pEntity->m_vecOrigin.m_Value.z;
        forceVector.x = this->m_vecOrigin.m_Value.x - m_pEntity->m_vecOrigin.m_Value.x;
        forceVector.y = v11;
        forceVector.z = v12;
        VectorNormalize(vec: &forceVector);
        x = forceVector.x * 1.375;
        y = forceVector.y * 1.375;
        v15 = forceVector.z * 1.375;
      }
      else
      {
        if ( this == m_pEntity )
        {
          forceVector.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                            a1: random,
                            a2: -1082130432,
                            a3: 1065353216);
          v16 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: -1082130432,
                  a3: 1065353216);
          forceVector.y = v16;
          forceVector.z = 0.0;
          ((void (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: 1148846080,
            a3: 1157234688);
        }
        else
        {
          if ( m_pEntity->m_MoveType.m_Value != 6 )
          {
            v18 = this->m_vecOrigin.m_Value.y - m_pEntity->m_vecOrigin.m_Value.y;
            v19 = this->m_vecOrigin.m_Value.z - m_pEntity->m_vecOrigin.m_Value.z;
            forceVector.x = this->m_vecOrigin.m_Value.x - m_pEntity->m_vecOrigin.m_Value.x;
            forceVector.y = v18;
            forceVector.z = v19;
            VectorNormalize(vec: &forceVector);
            v15 = forceVector.z;
            y = forceVector.y;
            x = forceVector.x;
            goto LABEL_25;
          }
          m_pPhysicsObject = this->m_pPhysicsObject;
          if ( m_pPhysicsObject == nullptr )
            m_pPhysicsObject = m_pEntity->m_pPhysicsObject;
          m_pPhysicsObject->GetVelocity(this: m_pPhysicsObject, a2: &forceVector, a3: nullptr);
          v16 = ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: m_pPhysicsObject);
        }
        v15 = forceVector.z;
        forceScale = v16;
        y = forceVector.y;
        x = forceVector.x;
      }
LABEL_25:
      result->x = x * forceScale;
      result->y = y * forceScale;
      result->z = v15 * forceScale;
      return result;
    }
    *result = vec3_origin;
    return result;
  }
  else if ( (info->m_bitsDamageType & 0x40) != 0 )
  {
    v21 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: 1062836634,
            a3: 1066611507);
    v22 = *(_QWORD *)&info->m_vecDamageForce.x;
    v23 = info->m_vecDamageForce.z;
    forceVector.z = v23;
    forceVector.x = *(float *)&v22 * v21;
    forceVector.y = v21 * *((float *)&v22 + 1);
    if ( v23 <= 0.0 )
    {
      forceScalea = v21;
      v24 = forceScalea;
    }
    else
    {
      v24 = 1.15;
    }
    v25 = v23 * v24;
    forceVector.z = v25;
    *result = forceVector;
    return result;
  }
  else
  {
    *(_QWORD *)&result->x = *(_QWORD *)&info->m_vecDamageForce.x;
    result->z = z;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3FE0
// Name: public: class CBaseCombatWeapon __near * CBaseCombatCharacter::Weapon_Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__thiscall CBaseCombatCharacter::Weapon_Create(CBaseCombatCharacter *this, const char *pWeaponName)
{
  return (CBaseCombatWeapon *)CBaseEntity::Create(
                                szName: pWeaponName,
                                vecOrigin: &this->m_vecOrigin.m_Value,
                                vecAngles: &this->m_angRotation.m_Value,
                                pOwner: this);
}

//------------------------------------------------------------------------------
// Address: 0x100A4010
// Name: public: virtual int CBaseCombatCharacter::OnTakeDamage_Alive(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatCharacter::OnTakeDamage_Alive(CBaseCombatCharacter *this, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // ecx
  float *v12; // eax
  const Vector *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  __m128 m_flDamage_low; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // [esp+4h] [ebp-18h]
  float v24; // [esp+8h] [ebp-14h]
  float v25; // [esp+Ch] [ebp-10h]
  Vector vecDir; // [esp+10h] [ebp-Ch] BYREF

  if ( (this->m_fFlags.m_Value & 0x8000) != 0 )
    return 0;
  m_Index = info->m_hInflictor.m_Index;
  vecDir = vec3_origin;
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
      v12 = (float *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].dtr_IHandleEntity)(a1: m_pEntity);
      v23 = *v12;
      v24 = v12[1];
      v25 = v12[2] - 10.0;
      v13 = this->WorldSpaceCenter(this);
      v14 = v24 - v13->y;
      v15 = v25 - v13->z;
      vecDir.x = v23 - v13->x;
      vecDir.y = v14;
      vecDir.z = v15;
      VectorNormalize(vec: &vecDir);
    }
  }
  g_vecAttackDir = vecDir;
  if ( this->m_takedamage.m_Value != 1 )
  {
    m_flDamage_low = (__m128)LODWORD(info->m_flDamage);
    v17.m128_i32[0] = 1258291200;
    v18 = _mm_and_ps((__m128)0x80000000, m_flDamage_low);
    v17.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(m_flDamage_low, v18), v17).m128_f32[0]) & 0x4B000000
                    | v18.m128_i32[0];
    v19 = m_flDamage_low;
    v19.m128_f32[0] = (float)(m_flDamage_low.m128_f32[0] + v17.m128_f32[0]) - v17.m128_f32[0];
    v20 = v19;
    v20.m128_f32[0] = v19.m128_f32[0] - m_flDamage_low.m128_f32[0];
    m_flDamage_low.m128_f32[0] = m_flDamage_low.m128_f32[0]
                               - (float)(v19.m128_f32[0]
                                       - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v20, v18).m128_f32[0]) & 0x3F800000));
    v21 = this->m_flDamageAccumulator + m_flDamage_low.m128_f32[0];
    v22 = info->m_flDamage - m_flDamage_low.m128_f32[0];
    this->m_flDamageAccumulator = v21;
    if ( v21 >= 1.0 )
    {
      v22 = v22 + 1.0;
      this->m_flDamageAccumulator = v21 - 1.0;
    }
    if ( v22 <= 0.0 )
      return 0;
    this->SetHealth(this, a2: (int)(float)((float)this->m_iHealth.m_Value - v22));
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A4210
// Name: public: virtual void CBaseCombatCharacter::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::SetTransmit(CBaseCombatCharacter *this, CCheckTransmitInfo *pInfo, BOOL bAlways)
{
  edict_t *m_pPev; // eax
  bool v5; // bl
  bool v6; // al
  bool v7; // zf
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *p_m_hMyWeapons; // esi
  int i; // ebx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v12; // edx
  CHandle<CBaseEntity> *p_m_hActiveWeapon; // ecx
  int v14; // eax
  CEntInfo *v15; // esi
  unsigned int v16; // edx
  int v17; // eax
  CEntInfo *v18; // eax
  IHandleEntity *v19; // eax
  CBaseEntity *v20; // eax

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseAnimating::SetTransmit(this, pInfo, bAlways);
    v5 = pInfo->m_pClientEnt == this->m_Network.m_pPev;
    if ( this->IsPlayer(this) )
    {
      if ( v5 )
        goto LABEL_9;
      v6 = this->IsPlayer(this);
      v7 = !CBasePlayer::IsSplitScreenUserOnEdict(this: v6 ? (CBasePlayer *)this : nullptr, edict: pInfo->m_pClientEnt);
    }
    else
    {
      v7 = !v5;
    }
    if ( !v7 )
    {
LABEL_9:
      p_m_hMyWeapons = &this->m_hMyWeapons;
      for ( i = 64; i != 0; --i )
      {
        m_Index = p_m_hMyWeapons->m_Value[0].m_Index;
        if ( p_m_hMyWeapons->m_Value[0].m_Index != -1
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          if ( m_pEntity != nullptr )
            ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, BOOL))m_pEntity->__vftable[7].SetRefEHandle)(
              a1: m_pEntity,
              a2: pInfo,
              a3: bAlways);
        }
        p_m_hMyWeapons = (CBaseCombatCharacter::NetworkVar_m_hMyWeapons *)((char *)p_m_hMyWeapons + 4);
      }
      return;
    }
    v12 = this->m_hActiveWeapon.m_Value.m_Index;
    p_m_hActiveWeapon = (CHandle<CBaseEntity> *)&this->m_hActiveWeapon;
    if ( v12 != -1 )
    {
      v14 = (unsigned __int16)v12;
      v15 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v12];
      v16 = HIWORD(v12);
      if ( v15->m_SerialNumber == v16 && v15->m_pEntity != nullptr )
      {
        v17 = v14;
        v7 = g_pEntityList->m_EntPtrArray[v17].m_SerialNumber == v16;
        v18 = &g_pEntityList->m_EntPtrArray[v17];
        v19 = v7 ? v18->m_pEntity : nullptr;
        if ( ((int)v19[41].__vftable & 0x20) == 0 )
        {
          v20 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hActiveWeapon);
          v20->SetTransmit(this: v20, a2: pInfo, a3: bAlways);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4360
// Name: public: static void CBaseCombatCharacter::AllocateDefaultRelationships(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CBaseCombatCharacter::AllocateDefaultRelationships()
{
  int v0; // esi
  int v1; // edi
  Relationship_t *v2; // eax
  int v3; // edx
  Relationship_t *v4; // ecx

  if ( CBaseCombatCharacter::m_DefaultRelationship == nullptr )
  {
    v0 = g_pGameRules != nullptr ? g_pGameRules->NumEntityClasses(this: g_pGameRules) : 27;
    v1 = 0;
    for ( CBaseCombatCharacter::m_DefaultRelationship = (Relationship_t **)operator new(nSize: 4 * v0); v1 < v0; ++v1 )
    {
      v2 = (Relationship_t *)operator new(nSize: 20 * v0);
      if ( v2 != nullptr )
      {
        v3 = v0 - 1;
        v4 = v2;
        do
        {
          v4->entity.m_Index = -1;
          ++v4;
          --v3;
        }
        while ( v3 >= 0 );
      }
      else
      {
        v2 = nullptr;
      }
      CBaseCombatCharacter::m_DefaultRelationship[v1] = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4410
// Name: protected: struct Relationship_t __near * CBaseCombatCharacter::FindEntityRelationship(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
Relationship_t *__thiscall CBaseCombatCharacter::FindEntityRelationship(
        CBaseCombatCharacter *this,
        CBaseEntity *pTarget)
{
  CBaseEntity *v2; // ebx
  CBaseCombatCharacter *v3; // esi
  int v5; // edx
  Relationship_t *v6; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v9; // edi
  int v10; // ebx
  Relationship_t *v11; // esi
  int v12; // eax
  int v13; // edi
  int v14; // edx
  int v15; // eax
  Relationship_t *m_pMemory; // ebx
  int *p_faction; // ecx
  int m_nFaction; // eax
  Relationship_t **v19; // esi
  int m_Size; // [esp+Ch] [ebp-8h]

  v2 = pTarget;
  v3 = this;
  if ( pTarget == nullptr )
  {
    if ( (_S6_4 & 1) == 0 )
    {
      _S6_4 |= 1u;
      dummy.entity.m_Index = -1;
    }
    return &dummy;
  }
  v5 = 0;
  m_Size = this->m_Relationship.m_Size;
  if ( m_Size <= 0 )
  {
LABEL_13:
    if ( v2->Classify(this: v2) == CLASS_NONE || (v9 = 0, v3->m_Relationship.m_Size <= 0) )
    {
LABEL_19:
      v12 = (int)v2->MyCombatCharacterPointer(this: v2);
      if ( v12 != 0 )
      {
        v13 = *(_DWORD *)(v12 + 1784);
        if ( v13 != 0 )
        {
          v14 = v3->m_Relationship.m_Size;
          v15 = 0;
          if ( v14 > 0 )
          {
            m_pMemory = v3->m_Relationship.m_Memory.m_pMemory;
            p_faction = &m_pMemory->faction;
            while ( v13 != *p_faction )
            {
              ++v15;
              p_faction += 5;
              if ( v15 >= v14 )
              {
                v2 = pTarget;
                goto LABEL_26;
              }
            }
            return &m_pMemory[v15];
          }
LABEL_26:
          if ( CBaseCombatCharacter::m_FactionRelationship != nullptr )
          {
            m_nFaction = v3->m_nFaction;
            if ( m_nFaction != 0 )
              return &CBaseCombatCharacter::m_FactionRelationship[m_nFaction][v13];
          }
        }
      }
      CBaseCombatCharacter::AllocateDefaultRelationships();
      v19 = &CBaseCombatCharacter::m_DefaultRelationship[v3->Classify(this: v3)];
      return &(*v19)[v2->Classify(this: v2)];
    }
    v10 = 0;
    while ( 1 )
    {
      v11 = v3->m_Relationship.m_Memory.m_pMemory;
      if ( pTarget->Classify(this: pTarget) == v11[v10].classType )
        return &this->m_Relationship.m_Memory.m_pMemory[v9];
      ++v9;
      ++v10;
      v3 = this;
      if ( v9 >= this->m_Relationship.m_Size )
      {
        v2 = pTarget;
        goto LABEL_19;
      }
    }
  }
  else
  {
    v6 = this->m_Relationship.m_Memory.m_pMemory;
    while ( 1 )
    {
      m_Index = v6->entity.m_Index;
      if ( v6->entity.m_Index == -1
        || (v2 = pTarget, g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( v2 == m_pEntity )
        return &v3->m_Relationship.m_Memory.m_pMemory[v5];
      ++v5;
      ++v6;
      if ( v5 >= m_Size )
        goto LABEL_13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A45D0
// Name: public: virtual enum Disposition_t CBaseCombatCharacter::IRelationType(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
Disposition_t __thiscall CBaseCombatCharacter::IRelationType(CBaseCombatCharacter *this, CBaseEntity *pTarget)
{
  if ( pTarget != nullptr )
    return CBaseCombatCharacter::FindEntityRelationship(this, pTarget)->disposition;
  else
    return D_NU;
}

//------------------------------------------------------------------------------
// Address: 0x100A45F0
// Name: public: virtual int CBaseCombatCharacter::IRelationPriority(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatCharacter::IRelationPriority(CBaseCombatCharacter *this, CBaseEntity *pTarget)
{
  if ( pTarget != nullptr )
    return CBaseCombatCharacter::FindEntityRelationship(this, pTarget)->priority;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A4610
// Name: public: class CBaseEntity __near * CBaseCombatCharacter::Weapon_FindUsable(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CBaseEntity *__userpurge CBaseCombatCharacter::Weapon_FindUsable@<eax>(
        CBaseCombatCharacter *this@<ecx>,
        int a2@<ebp>,
        const Vector *range)
{
  unsigned int v4; // eax
  int m_iEFlags; // ecx
  CBaseCombatWeapon *v6; // esi
  CBaseCombatWeapon *ActiveWeapon; // eax
  const char *pszValue; // ecx
  float v9; // xmm0_4
  int m_Value; // eax
  float v11; // xmm1_4
  __int128 v12; // xmm0
  int z_low; // edx
  float z; // esi
  CBaseCombatWeapon *v16[3]; // [esp+28h] [ebp-1D4h] BYREF
  CBaseCombatWeapon *weaponList[64]; // [esp+34h] [ebp-1C8h] BYREF
  _BYTE tr_32[60]; // [esp+154h] [ebp-A8h] OVERLAPPED
  Vector v19; // [esp+19Ch] [ebp-60h] BYREF
  Vector mins; // [esp+1A8h] [ebp-54h] BYREF
  Vector maxs; // [esp+1B4h] [ebp-48h] BYREF
  float v22[3]; // [esp+1C0h] [ebp-3Ch] BYREF
  __int128 velocity; // [esp+1CCh] [ebp-30h] OVERLAPPED BYREF
  int listCount; // [esp+1DCh] [ebp-20h]
  Vector vAboveWeapon; // [esp+1E0h] [ebp-1Ch]
  float fBestDist; // [esp+1ECh] [ebp-10h]
  int i; // [esp+1F0h] [ebp-Ch] BYREF
  CBaseCombatWeapon *pBestWeapon; // [esp+1F4h] [ebp-8h]
  CBaseCombatWeapon *retaddr; // [esp+1FCh] [ebp+0h]

  i = a2;
  pBestWeapon = retaddr;
  v4 = (unsigned int)this->m_iEFlags >> 11;
  vAboveWeapon.z = 0.0;
  if ( (v4 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&i);
  m_iEFlags = this->m_iEFlags;
  v19.x = this->m_vecAbsOrigin.x - range->x;
  v19.y = this->m_vecAbsOrigin.y - range->y;
  v19.z = this->m_vecAbsOrigin.z - range->z;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&i);
  mins.x = this->m_vecAbsOrigin.x + range->x;
  mins.y = this->m_vecAbsOrigin.y + range->y;
  mins.z = this->m_vecAbsOrigin.z + range->z;
  DWORD1(velocity) = CBaseCombatWeapon::GetAvailableWeaponsInBox(pList: v16, listMax: 64, mins: &v19, maxs: &mins);
  *(_QWORD *)&vAboveWeapon.x = 1232348160;
  if ( SDWORD1(velocity) <= 0 )
    return (CBaseEntity *)LODWORD(vAboveWeapon.z);
  do
  {
    v6 = v16[LODWORD(vAboveWeapon.y)];
    v6->GetVelocity(this: v6, a2: (Vector *)v22, a3: nullptr);
    if ( !v6->CanBePickedUpByNPCs(this: v6) )
      goto LABEL_30;
    *(float *)&velocity = v22[1] * v22[1];
    if ( (float)((float)((float)(v22[1] * v22[1]) + (float)(v22[0] * v22[0])) + (float)(v22[2] * v22[2])) > 1.0 )
      goto LABEL_30;
    if ( !this->Weapon_CanUse(this, a2: v6) )
      goto LABEL_30;
    if ( CBaseCombatWeapon::IsLocked(this: v6, pAsker: this) )
      goto LABEL_30;
    if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
      pszValue = v6->m_iClassname.pszValue;
      if ( ActiveWeapon->m_iClassname.pszValue == pszValue
        || pszValue == "weapon_pistol"
        || CBaseEntity::ClassMatchesComplex(this: v6, pszClassOrWildcard: "weapon_pistol") != 0 )
      {
        goto LABEL_30;
      }
    }
    v9 = v6->m_vecOrigin.m_Value.x - this->m_vecOrigin.m_Value.x;
    m_Value = v6->m_spawnflags.m_Value;
    v11 = (float)((float)((float)(v6->m_vecOrigin.m_Value.y - this->m_vecOrigin.m_Value.y)
                        * (float)(v6->m_vecOrigin.m_Value.y - this->m_vecOrigin.m_Value.y))
                + (float)((float)(v6->m_vecOrigin.m_Value.z - this->m_vecOrigin.m_Value.z)
                        * (float)(v6->m_vecOrigin.m_Value.z - this->m_vecOrigin.m_Value.z)))
        + (float)(v9 * v9);
    v12 = 0;
    *(float *)&v12 = fsqrt(v11);
    *(_OWORD *)&tr_32[44] = v12;
    fBestDist = *(float *)&v12;
    if ( (m_Value & 2) != 0 )
    {
      *(float *)&v12 = *(float *)&v12 * 0.5;
      fBestDist = *(float *)&v12;
    }
    if ( LODWORD(vAboveWeapon.z) != 0 )
    {
      if ( v6->m_iClassname.pszValue != "weapon_ar2" )
      {
        if ( CBaseEntity::ClassMatchesComplex(this: v6, pszClassOrWildcard: "weapon_ar2") == 0 )
        {
LABEL_21:
          if ( (v6->CapabilitiesGet(this: v6) & 0x6000) == 0 || fBestDist > vAboveWeapon.x )
            goto LABEL_30;
          goto LABEL_23;
        }
        *(float *)&v12 = fBestDist;
      }
      fBestDist = *(float *)&v12 * 0.5;
      goto LABEL_21;
    }
LABEL_23:
    if ( !CBaseCombatCharacter::Weapon_IsOnGround(this, pWeapon: v6) )
      goto LABEL_28;
    if ( (v6->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v6, a2: (int)&i);
    z_low = SLODWORD(v6->m_vecAbsOrigin.z);
    *((_QWORD *)&velocity + 1) = *(_QWORD *)&v6->m_vecAbsOrigin.x;
    listCount = z_low;
    *(_QWORD *)&maxs.x = *((_QWORD *)&velocity + 1);
    maxs.z = *(float *)&z_low + 1.0;
    UTIL_TraceEntity(
      pEntity: this,
      vecAbsStart: (const Vector *)((char *)&velocity + 8),
      vecAbsEnd: &maxs,
      mask: 0x200400Bu,
      pIgnore: v6,
      nCollisionGroup: 0,
      ptr: (CGameTrace *)&weaponList[61]);
    if ( tr_32[11] == 0 && *(float *)tr_32 >= 1.0 )
    {
LABEL_28:
      if ( this->FVisible_2(this, a2: v6, a3: 16449, a4: nullptr) )
      {
        vAboveWeapon.x = fBestDist;
        LODWORD(vAboveWeapon.z) = v6;
      }
    }
LABEL_30:
    ++LODWORD(vAboveWeapon.y);
  }
  while ( SLODWORD(vAboveWeapon.y) < SDWORD1(velocity) );
  z = vAboveWeapon.z;
  if ( LODWORD(vAboveWeapon.z) != 0 )
    CBaseCombatWeapon::Lock(this: (CBaseCombatWeapon *)LODWORD(vAboveWeapon.z), lockTime: 2.0, pLocker: this);
  return (CBaseEntity *)LODWORD(z);
}

//------------------------------------------------------------------------------
// Address: 0x100A49B0
// Name: public: virtual int CBaseCombatCharacter::GiveAmmo(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatCharacter::GiveAmmo(
        CBaseCombatCharacter *this,
        int iCount,
        unsigned int iAmmoIndex,
        int bSuppressSound)
{
  int v4; // ebx
  CAmmoDef *AmmoDef; // eax
  int v8; // eax

  v4 = iCount;
  if ( iCount <= 0 )
    return 0;
  if ( !g_pGameRules->CanHaveAmmo_2(this: g_pGameRules, a2: this, a3: iAmmoIndex) || iAmmoIndex > 0x1F )
    return 0;
  AmmoDef = GetAmmoDef();
  v8 = CAmmoDef::MaxCarry(this: AmmoDef, nAmmoIndex: iAmmoIndex, owner: this) - this->m_iAmmo.m_Value[iAmmoIndex];
  if ( iCount >= v8 )
    v4 = v8;
  if ( v4 < 1 )
    return 0;
  if ( (_BYTE)bSuppressSound == 0 )
    CBaseEntity::EmitSound(this, soundname: "BaseCombatCharacter.AmmoPickup", soundtime: 0.0, duration: nullptr);
  bSuppressSound = v4 + this->m_iAmmo.m_Value[iAmmoIndex];
  CBaseCombatCharacter::NetworkVar_m_iAmmo::Set(this: &this->m_iAmmo, i: iAmmoIndex, val: &bSuppressSound);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100A4A50
// Name: public: virtual void CBaseCombatCharacter::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::VPhysicsUpdate(CBaseCombatCharacter *this, IPhysicsObject *pPhysics)
{
  CBaseCombatCharacter::ApplyStressDamage(this, pPhysics, bRequireLargeObject: false);
  CBaseEntity::VPhysicsUpdate(this, pPhysics);
}

//------------------------------------------------------------------------------
// Address: 0x100A4A70
// Name: void RadiusDamage(class CTakeDamageInfo const __near &,class Vector const __near &,float,int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RadiusDamage(
        const CTakeDamageInfo *info,
        const Vector *vecSrc,
        float flRadius,
        int iClassIgnore,
        CBaseEntity *pEntityIgnore)
{
  double v5; // xmm0_8
  unsigned int m_Index; // eax
  float v7; // xmm0_4
  CBaseEntity *m_pEntity; // ecx

  ((void (__stdcall *)(const CTakeDamageInfo *, const Vector *, _DWORD, int, CBaseEntity *))g_pGameRules->RadiusDamage)(
    a1: info,
    a2: vecSrc,
    a3: LODWORD(flRadius),
    a4: iClassIgnore,
    a5: pEntityIgnore);
  if ( (info->m_bitsDamageType & 0x40) != 0 )
  {
    v5 = flRadius * 1.5;
    if ( v5 < 128.0 )
      v5 = 128.0;
    m_Index = info->m_hInflictor.m_Index;
    v7 = v5;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    CSoundEnt::InsertSound(
      iType: 33554433,
      vecOrigin: vecSrc,
      iVolume: (int)v7,
      flDuration: 0.25,
      pOwner: m_pEntity,
      soundChannelIndex: 0,
      pSoundTarget: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4B30
// Name: public: class CBaseEntity __near * CBaseCombatCharacter::GetFogTrigger(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseCombatCharacter::GetFogTrigger(CBaseCombatCharacter *this)
{
  int v1; // eax
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // edi
  const Vector *v6; // eax
  unsigned int v7; // esi
  float v9; // [esp-20h] [ebp-2Ch]
  float *v10; // [esp-10h] [ebp-1Ch]
  IHandleEntity *v11; // [esp-Ch] [ebp-18h]
  int v12; // [esp-8h] [ebp-14h]
  float v13; // [esp-4h] [ebp-10h]

  v1 = 0;
  v13 = 999999.0;
  v11 = nullptr;
  v12 = 0;
  if ( this->m_hTriggerFogList.m_Size > 0 )
  {
    do
    {
      m_Index = this->m_hTriggerFogList.m_Memory.m_pMemory[v1].m_Index;
      if ( m_Index != -1 )
      {
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          m_pEntity = v4->m_pEntity;
          if ( v4->m_pEntity != nullptr )
          {
            v10 = (float *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].dtr_IHandleEntity)(a1: v4->m_pEntity);
            v6 = this->WorldSpaceCenter(this);
            v9 = fsqrt(
                   (float)((float)((float)(v6->y - v10[1]) * (float)(v6->y - v10[1]))
                         + (float)((float)(v6->z - v10[2]) * (float)(v6->z - v10[2])))
                 + (float)((float)(v6->x - *v10) * (float)(v6->x - *v10)));
            if ( v13 > v9 )
            {
              v13 = v9;
              v11 = m_pEntity;
            }
          }
        }
      }
      v1 = v12 + 1;
      v12 = v1;
    }
    while ( v1 < this->m_hTriggerFogList.m_Size );
    if ( v11 != nullptr )
      this->m_hLastFogTrigger.m_Index = v11->GetRefEHandle(this: v11)->m_Index;
  }
  v7 = this->m_hLastFogTrigger.m_Index;
  if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100A4C80
// Name: public: virtual float CBaseCombatCharacter::GetTimeSinceLastInjury(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatCharacter::GetTimeSinceLastInjury(CBaseCombatCharacter *this, int team)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  int i; // edi
  float m_Value; // xmm1_4
  float v5; // xmm0_4
  int v7; // eax
  CBaseCombatCharacter::DamageHistory *j; // edx
  int v9; // eax
  float v10; // [esp+4h] [ebp-8h]
  float time; // [esp+14h] [ebp+8h]

  if ( team == -1 )
  {
    time = 1.0e12;
    p_m_timestamp = &this->m_damageHistory[0].interval.m_timestamp;
    for ( i = 4; i != 0; --i )
    {
      if ( LODWORD(p_m_timestamp[-2].m_Value) != -1 )
      {
        m_Value = p_m_timestamp->m_Value;
        if ( p_m_timestamp->m_Value <= 0.0 )
        {
          v5 = 99999.898;
        }
        else
        {
          m_Value = p_m_timestamp->m_Value;
          v10 = IntervalTimer::Now(this: (CEffectsServer *)&p_m_timestamp[-1]) - m_Value;
          v5 = v10;
        }
        if ( time > v5 )
        {
          if ( m_Value <= 0.0 )
            time = 99999.898;
          else
            time = IntervalTimer::Now(this: (CEffectsServer *)&p_m_timestamp[-1]) - p_m_timestamp->m_Value;
        }
      }
      p_m_timestamp += 3;
    }
    return time;
  }
  else
  {
    v7 = 0;
    for ( j = this->m_damageHistory; j->team != team; ++j )
    {
      if ( ++v7 >= 4 )
        return 1.0e12;
    }
    v9 = v7;
    if ( this->m_damageHistory[v9].interval.m_timestamp.m_Value <= 0.0 )
      return 99999.898;
    else
      return IntervalTimer::Now(this: (CEffectsServer *)&this->m_damageHistory[v9].interval)
           - this->m_damageHistory[v9].interval.m_timestamp.m_Value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4D90
// Name: public: class CBaseCombatWeapon const __near * CNetworkHandleBase<class CBaseCombatWeapon,class CBaseCombatCharacter::NetworkVar_m_hActiveWeapon>::Set(class CBaseCombatWeapon const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseCombatWeapon *__thiscall CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon>::Set(
        CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> *this,
        const CBaseCombatWeapon *val)
{
  unsigned int m_Index; // eax
  const CBaseCombatWeapon *m_pEntity; // ecx
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 549;
    if ( *((_BYTE *)this - 2112) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x894u);
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
// Address: 0x100A4E20
// Name: public: void IntervalTimer::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IntervalTimer::Start(IntervalTimer *this)
{
  double v2; // st7
  double m_Value; // st6
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  float v5; // [esp+4h] [ebp-4h]

  v2 = IntervalTimer::Now((CEffectsServer *)this);
  m_Value = this->m_timestamp.m_Value;
  p_m_timestamp = &this->m_timestamp;
  if ( m_Value != v2 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *, CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-1].m_Value) + 4))(
      a1: p_m_timestamp - 1,
      a2: p_m_timestamp);
    v5 = v2;
    p_m_timestamp->m_Value = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4E60
// Name: public: void IntervalTimer::Invalidate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IntervalTimer::Invalidate(IntervalTimer *this)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi

  p_m_timestamp = &this->m_timestamp;
  if ( this->m_timestamp.m_Value != -1.0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_timestamp);
    p_m_timestamp->m_Value = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5B40
// Name: void __near * SendProxy_SendBaseCombatCharacterLocalDataTable(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_SendBaseCombatCharacterLocalDataTable(
        const SendProp *pProp,
        _DWORD *pStruct,
        const void *pVarData,
        CSendProxyRecipients *pRecipients)
{
  int v4; // eax
  int (__thiscall ***v6)(_DWORD, _DWORD); // eax
  int v7; // eax

  if ( pRecipients != nullptr )
    *pRecipients = 0;
  if ( pStruct == nullptr )
    return (void *)pVarData;
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*pStruct + 336))(a1: pStruct) != 0 )
  {
    v4 = pStruct[6];
    if ( v4 == 0 )
    {
LABEL_6:
      CSendProxyRecipients::SetOnly(this: pRecipients, iClient: -1);
      return (void *)pVarData;
    }
  }
  else
  {
    v6 = (int (__thiscall ***)(_DWORD, _DWORD))(*(int (__thiscall **)(_DWORD *))(*pStruct + 364))(a1: pStruct);
    if ( v6 == nullptr )
      return (void *)pVarData;
    v7 = (**v6)(a1: v6, a2: 0);
    if ( v7 == 0 )
      return (void *)pVarData;
    v4 = *(_DWORD *)(v7 + 24);
    if ( v4 == 0 )
      goto LABEL_6;
  }
  CSendProxyRecipients::SetOnly(
    this: pRecipients,
    iClient: ((signed int)(v4 - (unsigned int)gpGlobals->pEdicts) >> 4) - 1);
  return (void *)pVarData;
}

//------------------------------------------------------------------------------
// Address: 0x100A5CA0
// Name: public: virtual void CBaseCombatCharacter::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::Spawn(CBaseCombatCharacter *this)
{
  double v2; // st7
  float v3; // [esp+8h] [ebp-4h]

  vgui::ListViewPanel::Paint((vgui::ListViewPanel *)this);
  CBaseEntity::SetBlocksLOS(this, bBlocksLOS: false);
  v2 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_aliveTimer);
  if ( this->m_aliveTimer.m_timestamp.m_Value != v2 )
  {
    this->m_aliveTimer.NetworkStateChanged(this: &this->m_aliveTimer, a2: &this->m_aliveTimer.m_timestamp);
    v3 = v2;
    this->m_aliveTimer.m_timestamp.m_Value = v3;
  }
  this->m_hasBeenInjured = 0;
  this->m_damageHistory[0].team = -1;
  this->m_damageHistory[1].team = -1;
  this->m_damageHistory[2].team = -1;
  this->m_damageHistory[3].team = -1;
  this->ClearLastKnownArea(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A5D30
// Name: public: virtual void CBaseCombatCharacter::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::Precache(CBaseCombatCharacter *this)
{
  int v2; // ebx
  unsigned int j; // edi
  Relationship_t *v4; // edx
  unsigned int m_Index; // eax
  int m_Size; // eax
  Relationship_t *m_pMemory; // ecx
  int v8; // eax
  __int64 v9; // xmm0_8
  int v10; // eax
  int i; // [esp+8h] [ebp-4h]

  CBaseAnimating::Precache(this);
  CBaseEntity::PrecacheScriptSound(soundname: "BaseCombatCharacter.CorpseGib");
  CBaseEntity::PrecacheScriptSound(soundname: "BaseCombatCharacter.StopWeaponSounds");
  CBaseEntity::PrecacheScriptSound(soundname: "BaseCombatCharacter.AmmoPickup");
  v2 = this->m_Relationship.m_Size - 1;
  i = v2;
  if ( v2 >= 0 )
  {
    for ( j = v2; ; --j )
    {
      v4 = &this->m_Relationship.m_Memory.m_pMemory[j];
      m_Index = v4->entity.m_Index;
      if ( v4->entity.m_Index == -1 )
        goto LABEL_7;
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        break;
      }
      v2 = i;
LABEL_13:
      i = --v2;
      if ( v2 < 0 )
        return;
    }
    v2 = i;
LABEL_7:
    if ( v4->classType == CLASS_NONE )
    {
      _DevMsg(a1: 2, a2: "Removing relationship for lost entity\n");
      m_Size = this->m_Relationship.m_Size;
      if ( m_Size > 0 )
      {
        if ( v2 != m_Size - 1 )
        {
          m_pMemory = this->m_Relationship.m_Memory.m_pMemory;
          v8 = m_Size;
          v9 = *(_QWORD *)&m_pMemory[v8 - 1].entity.m_Index;
          v10 = (int)&m_pMemory[v8 - 1];
          *(_QWORD *)&m_pMemory[j].entity.m_Index = v9;
          *(_QWORD *)&m_pMemory[j].faction = *(_QWORD *)(v10 + 8);
          m_pMemory[j].priority = *(_DWORD *)(v10 + 16);
        }
        --this->m_Relationship.m_Size;
      }
    }
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5E30
// Name: public: virtual int CBaseCombatCharacter::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatCharacter::Restore(CBaseCombatCharacter *this, IRestore *restore)
{
  int result; // eax
  int v4; // ebx
  const char *pszValue; // ecx
  const char *v6; // eax
  int v7; // edi
  unsigned int v8; // edx
  IRestore_vtbl *v9; // eax
  int m_Size; // eax
  Relationship_t *m_pMemory; // ecx
  int v12; // eax
  __int64 v13; // xmm0_8
  int v14; // eax
  int status; // [esp+8h] [ebp-4h]
  IRestore *restorea; // [esp+14h] [ebp+8h]

  result = CBaseAnimating::Restore(this, restore);
  v4 = result;
  status = result;
  if ( result != 0 )
  {
    this->ChangeFaction(this, a2: this->m_nFaction);
    if ( gpGlobals->eLoadType == MapLoad_Transition )
    {
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v6 = this->m_iName.m_Value.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      _DevMsg(a1: 2, a2: "%s (%s) removing class relationships due to level transition\n", v6, pszValue);
      v7 = this->m_Relationship.m_Size - 1;
      if ( v7 >= 0 )
      {
        v8 = v7;
        do
        {
          restorea = (IRestore *)&this->m_Relationship.m_Memory.m_pMemory[v8];
          v9 = restorea->__vftable;
          if ( (restorea->__vftable == (IRestore_vtbl *)-1
             || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != (unsigned int)v9 >> 16
             || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity == nullptr)
            && restorea[1].__vftable != nullptr )
          {
            m_Size = this->m_Relationship.m_Size;
            if ( m_Size > 0 )
            {
              if ( v7 != m_Size - 1 )
              {
                m_pMemory = this->m_Relationship.m_Memory.m_pMemory;
                v12 = m_Size;
                v13 = *(_QWORD *)&m_pMemory[v12 - 1].entity.m_Index;
                v14 = (int)&m_pMemory[v12 - 1];
                *(_QWORD *)&m_pMemory[v8].entity.m_Index = v13;
                *(_QWORD *)&m_pMemory[v8].faction = *(_QWORD *)(v14 + 8);
                m_pMemory[v8].priority = *(_DWORD *)(v14 + 16);
              }
              --this->m_Relationship.m_Size;
            }
          }
          --v8;
          --v7;
        }
        while ( v7 >= 0 );
        return status;
      }
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A5F60
// Name: public: virtual class CBaseEntity __near * CBaseCombatCharacter::CheckTraceHullAttack(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,int,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
CBaseEntity *__userpurge CBaseCombatCharacter::CheckTraceHullAttack@<eax>(
        CBaseCombatCharacter *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *mins,
        const Vector *maxs,
        __int64 flDamage,
        int flForceScale,
        bool bDamageAnyNPC)
{
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  __int128 v15; // xmm4
  float z; // ecx
  const IHandleEntity *m_pPassEnt; // ecx
  const IHandleEntity *v18; // edi
  float x; // xmm0_4
  _BYTE v22[12]; // [esp+18h] [ebp-164h] BYREF
  CTakeDamageInfo dmgInfo; // [esp+24h] [ebp-158h] BYREF
  CGameTrace tr; // [esp+84h] [ebp-F8h] BYREF
  _BYTE ray_52[32]; // [esp+110h] [ebp-6Ch] OVERLAPPED
  _DWORD v26[3]; // [esp+13Ch] [ebp-40h] BYREF
  CTraceFilterMelee traceFilter; // [esp+148h] [ebp-34h] BYREF
  Vector vecMaxs; // [esp+164h] [ebp-18h] BYREF
  Vector vecTopCenter; // [esp+170h] [ebp-Ch] BYREF
  float retaddr; // [esp+17Ch] [ebp+0h]

  vecTopCenter.x = a2;
  vecTopCenter.y = retaddr;
  if ( ai_show_hull_attacks.m_pParent != nullptr && ai_show_hull_attacks.m_pParent->m_Value.m_nValue != 0 )
  {
    v12 = vEnd->y - vStart->y;
    v13 = vEnd->z - vStart->z;
    v14 = vEnd->x - vStart->x;
    v15 = 0;
    *(float *)&v15 = fsqrt((float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v14 * v14));
    *(_OWORD *)&ray_52[16] = v15;
    *(float *)&traceFilter.m_pHit = v14;
    traceFilter.m_flForceScale = v12;
    *(float *)&traceFilter.m_bDamageAnyNPC = v13;
    VectorNormalize(vec: (Vector *)&traceFilter.m_pHit);
    z = maxs->z;
    *(_QWORD *)&vecMaxs.x = *(_QWORD *)&maxs->x;
    vecMaxs.x = *(float *)&v15 + vecMaxs.x;
    vecMaxs.z = z;
    NDebugOverlay::BoxDirection(
      origin: vStart,
      mins,
      maxs: &vecMaxs,
      orientation: (const Vector *)&traceFilter.m_pHit,
      r: 100,
      g: 255,
      b: 255,
      a: 20,
      duration: 1.0);
    NDebugOverlay::BoxDirection(
      origin: vStart,
      mins,
      maxs,
      orientation: (const Vector *)&traceFilter.m_pHit,
      r: 255,
      g: 0,
      b: 0,
      a: 20,
      duration: 1.0);
  }
  CTakeDamageInfo::CTakeDamageInfo(
    this: (CTakeDamageInfo *)v22,
    pInflictor: this,
    pAttacker: this,
    flDamage: *(float *)&flDamage,
    bitsDamageType: SHIDWORD(flDamage),
    iKillType: 0,
    iObjectsPenetrated: 0);
  traceFilter.__vftable = (CTraceFilterMelee_vtbl *)v22;
  traceFilter.m_pPassEnt = nullptr;
  *(_DWORD *)ray_52 = 0;
  LOBYTE(traceFilter.m_dmgInfo) = bDamageAnyNPC;
  v26[0] = &CTraceFilterMelee::`vftable';
  v26[1] = this;
  v26[2] = 13;
  traceFilter.m_collisionGroup = flForceScale;
  Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start: vStart, end: vEnd, mins, maxs);
  ((void (__thiscall *)(IEngineTrace *, CBaseEntity **, int, _DWORD *, int *, int, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: &tr.m_pEnt,
    a3: 100679691,
    a4: v26,
    a5: &dmgInfo.m_iObjectsPenetrated,
    a6: a3,
    a7: a4);
  m_pPassEnt = traceFilter.m_pPassEnt;
  v18 = traceFilter.m_pPassEnt;
  if ( traceFilter.m_pPassEnt == nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecTopCenter);
    x = this->m_vecAbsOrigin.x;
    LODWORD(vecMaxs.y) = &traceFilter.m_pHit;
    CCollisionProperty::CollisionAABBToWorldAABB(
      this: &this->m_Collision,
      entityMins: &this->m_Collision.m_vecMins.m_Value,
      entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
      pWorldMins: (Vector *)LODWORD(x),
      pWorldMaxs: (Vector *)LODWORD(this->m_vecAbsOrigin.y));
    vecMaxs.z = *(float *)&traceFilter.m_bDamageAnyNPC + 1.0;
    Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start: &vecMaxs, end: vEnd, mins, maxs);
    enginetrace->TraceRay(
      this: enginetrace,
      a2: (const Ray_t *)&tr.m_pEnt,
      a3: 100679691u,
      a4: (ITraceFilter *)v26,
      a5: (CGameTrace *)&dmgInfo.m_iObjectsPenetrated);
    m_pPassEnt = traceFilter.m_pPassEnt;
    v18 = traceFilter.m_pPassEnt;
    if ( traceFilter.m_pPassEnt == nullptr )
      return (CBaseEntity *)v18;
  }
  if ( ((unsigned __int8 (__thiscall *)(const IHandleEntity *, CBaseCombatCharacter *))m_pPassEnt->__vftable[21].GetRefEHandle)(
         a1: m_pPassEnt,
         a2: this) == 0 )
    return nullptr;
  else
    return (CBaseEntity *)v18;
}

//------------------------------------------------------------------------------
// Address: 0x100A61F0
// Name: public: virtual int CBaseCombatCharacter::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBaseCombatCharacter::OnTakeDamage@<eax>(
        CBaseCombatCharacter *this@<ecx>,
        int a2@<edi>,
        const CTakeDamageInfo *info)
{
  __int64 scale; // xmm0_8
  float z; // eax
  unsigned int m_Index; // ecx
  int v9; // eax
  CEntInfo *v10; // edx
  unsigned int v11; // ecx
  int v12; // eax
  bool v13; // zf
  CBaseEntity **v14; // eax
  CBaseEntity *v15; // ecx
  int TeamNumber; // eax
  CBaseCombatCharacter::DamageHistory *m_damageHistory; // ecx
  int v18; // edx
  IntervalTimer *p_interval; // ebx
  IntervalTimer *v20; // ecx
  double v21; // st7
  double m_Value; // st6
  float *p_m_Value; // ebx
  CBaseCombatCharacter_vtbl *v24; // edx
  int v25; // ebx
  IPhysicsObject *m_pPhysicsObject; // ecx
  Vector origin; // [esp+34h] [ebp-Ch] BYREF
  float retVal; // [esp+48h] [ebp+8h]

  if ( this->m_takedamage.m_Value == 0 )
    return 0;
  if ( this->IsPlayer(this) )
    ((void (__thiscall *)(CBaseCombatCharacter *, int, _DWORD, int))this->__vftable[1].SetParent)(
      a1: this,
      a2: 15,
      a3: 0,
      a4: 4);
  ++this->m_iDamageCount;
  if ( (info->m_bitsDamageType & 0x100) != 0 )
  {
    scale = *(_QWORD *)&info->m_vecDamagePosition.x;
    origin.z = info->m_vecDamagePosition.z;
    *(_QWORD *)&origin.x = scale;
    ((void (__thiscall *)(IEffects *, Vector *, int, int, _DWORD, int))g_pEffects->Sparks)(
      a1: g_pEffects,
      a2: &origin,
      a3: 2,
      a4: 2,
      a5: 0,
      a6: a2);
    z = info->m_vecDamagePosition.z;
    *(_QWORD *)&origin.x = *(_QWORD *)&info->m_vecDamagePosition.x;
    origin.z = z;
    *(float *)&scale = (float)((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
    UTIL_Smoke(&origin, scale: *(const float *)&scale, framerate: COERCE_CONST_FLOAT(10));
  }
  m_Index = info->m_hAttacker.m_Index;
  if ( m_Index != -1 )
  {
    v9 = (unsigned __int16)m_Index;
    v10 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v11 = HIWORD(m_Index);
    if ( v10->m_SerialNumber == v11 && v10->m_pEntity != nullptr )
    {
      v12 = v9;
      v13 = g_pEntityList->m_EntPtrArray[v12].m_SerialNumber == v11;
      v14 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v12];
      if ( v13 )
        v15 = *v14;
      else
        v15 = nullptr;
      TeamNumber = CBaseEntity::GetTeamNumber(this: v15);
      m_damageHistory = this->m_damageHistory;
      this->m_hasBeenInjured |= 1 << TeamNumber;
      v18 = 0;
      while ( 1 )
      {
        if ( m_damageHistory->team == TeamNumber )
        {
          p_interval = &this->m_damageHistory[v18].interval;
          goto LABEL_20;
        }
        if ( m_damageHistory->team == -1 )
          break;
        ++v18;
        ++m_damageHistory;
        if ( v18 >= 4 )
          goto LABEL_22;
      }
      v20 = (IntervalTimer *)((char *)this + 12 * v18);
      LODWORD(v20[276].m_timestamp.m_Value) = TeamNumber;
      p_interval = v20 + 277;
LABEL_20:
      v21 = IntervalTimer::Now(this: (CEffectsServer *)p_interval);
      m_Value = p_interval->m_timestamp.m_Value;
      p_m_Value = &p_interval->m_timestamp.m_Value;
      if ( m_Value != v21 )
      {
        (*(void (__thiscall **)(float *, float *))(*((_DWORD *)p_m_Value - 1) + 4))(a1: p_m_Value - 1, a2: p_m_Value);
        retVal = v21;
        *p_m_Value = retVal;
      }
    }
  }
LABEL_22:
  v24 = this->__vftable;
  if ( this->m_lifeState.m_Value != 0 )
  {
    if ( this->m_lifeState.m_Value == 1 )
      return ((int (__stdcall *)(const CTakeDamageInfo *))v24->OnTakeDamage_Dying)(a1: info);
    v25 = ((int (__stdcall *)(const CTakeDamageInfo *))v24->OnTakeDamage_Dead)(a1: info);
    if ( this->m_iHealth.m_Value <= 0
      && g_pGameRules->Damage_ShouldGibCorpse(this: g_pGameRules, a2: info->m_bitsDamageType)
      && this->ShouldGib(this, a2: info) )
    {
      this->Event_Gibbed(this, a2: info);
      return 0;
    }
  }
  else
  {
    v25 = v24->OnTakeDamage_Alive(this, a2: info);
    if ( this->m_iHealth.m_Value <= 0 )
    {
      m_pPhysicsObject = this->m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr )
        m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: false);
      this->Event_Killed(this, a2: info);
      if ( !this->ShouldGib(this, a2: info) || !this->Event_Gibbed(this, a2: info) )
        this->Event_Dying(this);
    }
  }
  return v25;
}

//------------------------------------------------------------------------------
// Address: 0x100A6470
// Name: public: virtual int CBaseCombatCharacter::OnTakeDamage_Dead(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatCharacter::OnTakeDamage_Dead(CBaseCombatCharacter *this, const CTakeDamageInfo *info)
{
  int m_Value; // eax
  int m_flDamage; // edx
  int v5; // esi

  if ( this->m_takedamage.m_Value != 1 )
  {
    m_Value = this->m_iHealth.m_Value;
    m_flDamage = (int)info->m_flDamage;
    v5 = m_Value - m_flDamage;
    if ( m_Value != m_Value - m_flDamage )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      this->m_iHealth.m_Value = v5;
    }
  }
  if ( this->IsPlayer(this) )
    ((void (__thiscall *)(CBaseCombatCharacter *, int, _DWORD, int))this->__vftable[1].SetParent)(
      a1: this,
      a2: 17,
      a3: 0,
      a4: 4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A64F0
// Name: public: virtual bool CBaseCombatCharacter::RemoveEntityRelationship(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatCharacter::RemoveEntityRelationship(CBaseCombatCharacter *this, CBaseEntity *pEntity)
{
  int v3; // edx
  Relationship_t *i; // esi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  v3 = this->m_Relationship.m_Size - 1;
  if ( v3 < 0 )
    return 0;
  for ( i = &this->m_Relationship.m_Memory.m_pMemory[v3]; ; --i )
  {
    m_Index = i->entity.m_Index;
    if ( i->entity.m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    if ( m_pEntity == pEntity )
      break;
    if ( --v3 < 0 )
      return 0;
  }
  if ( this->m_Relationship.m_Size - v3 - 1 > 0 )
    _V_memmove(
      dest: &this->m_Relationship.m_Memory.m_pMemory[v3],
      src: &this->m_Relationship.m_Memory.m_pMemory[v3 + 1],
      count: 20 * (this->m_Relationship.m_Size - v3 - 1));
  --this->m_Relationship.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A7520
// Name: public: virtual void CBaseCombatCharacter::CorpseFade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::CorpseFade(CBaseCombatCharacter *this)
{
  edict_t *m_pPev; // ecx
  CGlobalVars *v3; // ebx
  edict_t *v4; // ecx

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
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  v3 = gpGlobals;
  if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x64u);
    }
    this->m_flAnimTime.m_Value = v3->curtime;
  }
  CBaseEntity::AddEffects(this, nEffects: 8);
  CBaseEntity::SUB_StartFadeOut(this, delay: 10.0, notSolid: true);
}

//------------------------------------------------------------------------------
// Address: 0x100A75F0
// Name: public: virtual bool CBaseCombatCharacter::Event_Gibbed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::Event_Gibbed(CBaseCombatCharacter *this, const CTakeDamageInfo *info)
{
  char v3; // bl
  bool v4; // zf
  ConVarRef violence_agibs; // [esp+Ch] [ebp-8h] BYREF

  v3 = 0;
  if ( this->HasHumanGibs(this) )
  {
    ConVarRef::ConVarRef(this: &violence_agibs, pName: "violence_hgibs");
    if ( !ConVarRef::IsValid(this: &violence_agibs) )
      goto LABEL_9;
    v4 = violence_agibs.m_pConVarState->m_Value.m_nValue == 0;
  }
  else
  {
    if ( !this->HasAlienGibs(this) )
      goto LABEL_9;
    ConVarRef::ConVarRef(this: &violence_agibs, pName: "violence_agibs");
    if ( !ConVarRef::IsValid(this: &violence_agibs) )
      goto LABEL_9;
    v4 = violence_agibs.m_pConVarState->m_Value.m_nValue == 0;
  }
  if ( v4 )
    v3 = 1;
LABEL_9:
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  if ( this->m_lifeState.m_Value != 2 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    this->m_lifeState.m_Value = 2;
  }
  if ( v3 != 0 )
  {
    this->CorpseFade(this);
    return false;
  }
  else
  {
    CBaseEntity::AddEffects(this, nEffects: 32);
    return this->CorpseGib(this, a2: info);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7700
// Name: public: virtual void CBaseCombatCharacter::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::Event_Killed(CBaseCombatCharacter *this, const CTakeDamageInfo *info)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_lifeState> *p_m_lifeState; // edi
  const CTakeDamageInfo *v4; // ebx
  CRagdollMagnet *BestMagnet; // eax
  Vector *v6; // eax
  bool (__thiscall *ShouldDropActiveWeaponWhenKilled)(CBaseCombatCharacter *); // eax
  unsigned int m_Index; // eax
  CBaseCombatWeapon *m_pEntity; // ecx
  IPhysicsObject *m_pPhysicsObject; // ecx
  double v11; // st7
  unsigned int v12; // eax
  CBaseCombatWeapon *v13; // ecx
  unsigned int v14; // ecx
  int v15; // eax
  CEntInfo *v16; // edx
  unsigned int v17; // ecx
  int v18; // eax
  bool v19; // zf
  CEntInfo *v20; // eax
  IHandleEntity *v21; // ecx
  unsigned int v22; // eax
  CBaseEntity *v23; // ecx
  BOOL v24; // edi
  char v25; // bl
  Vector weaponForce; // [esp+6Ch] [ebp-1Ch] BYREF
  Vector forceVector; // [esp+78h] [ebp-10h] BYREF
  CBaseCombatWeapon *pDroppedWeapon; // [esp+84h] [ebp-4h]
  int savedregs; // [esp+88h] [ebp+0h] BYREF

  p_m_lifeState = &this->m_lifeState;
  if ( this->m_lifeState.m_Value != 1 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    p_m_lifeState->m_Value = 1;
  }
  v4 = info;
  this->CalcDeathForceVector(this, result: &forceVector, a3: info);
  BestMagnet = CRagdollMagnet::FindBestMagnet(pNPC: this);
  if ( BestMagnet != nullptr )
  {
    v6 = CRagdollMagnet::GetForceVector(this: BestMagnet, result: &weaponForce, pNPC: this);
    forceVector.x = forceVector.x + v6->x;
    forceVector.y = v6->y + forceVector.y;
    forceVector.z = v6->z + forceVector.z;
  }
  ShouldDropActiveWeaponWhenKilled = this->ShouldDropActiveWeaponWhenKilled;
  pDroppedWeapon = nullptr;
  if ( ShouldDropActiveWeaponWhenKilled(this) )
  {
    m_Index = this->m_hActiveWeapon.m_Value.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    pDroppedWeapon = m_pEntity;
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      v11 = ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetInvMass)(a1: m_pPhysicsObject);
      v12 = this->m_hActiveWeapon.m_Value.m_Index;
      weaponForce.x = forceVector.x * v11;
      weaponForce.y = forceVector.y * v11;
      weaponForce.z = v11 * forceVector.z;
      if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
        this->Weapon_Drop(this, a2: nullptr, a3: nullptr, a4: &weaponForce);
      else
        this->Weapon_Drop(
          this,
          a2: (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity,
          a3: nullptr,
          a4: &weaponForce);
    }
    else
    {
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        v13 = nullptr;
      else
        v13 = (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      this->Weapon_Drop(this, a2: v13, a3: nullptr, a4: nullptr);
    }
  }
  if ( (this->m_spawnflags.m_Value & 8) != 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    CBaseEntity::Create(
      szName: "item_healthvial",
      vecOrigin: &this->m_vecAbsOrigin,
      vecAngles: &this->m_angAbsRotation,
      pOwner: nullptr);
  }
  CBaseEntity::EmitSound(this, soundname: "BaseCombatCharacter.StopWeaponSounds", soundtime: 0.0, duration: nullptr);
  v14 = info->m_hAttacker.m_Index;
  if ( v14 != -1 )
  {
    v15 = (unsigned __int16)v14;
    v16 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v14];
    v17 = HIWORD(v14);
    if ( v16->m_SerialNumber == v17 && v16->m_pEntity != nullptr )
    {
      v18 = v15;
      v19 = g_pEntityList->m_EntPtrArray[v18].m_SerialNumber == v17;
      v20 = &g_pEntityList->m_EntPtrArray[v18];
      if ( v19 )
        v21 = v20->m_pEntity;
      else
        v21 = nullptr;
      ((void (__thiscall *)(IHandleEntity *, CBaseCombatCharacter *, const CTakeDamageInfo *))v21->__vftable[23].SetRefEHandle)(
        a1: v21,
        a2: this,
        a3: info);
      v22 = info->m_hAttacker.m_Index;
      if ( v22 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_SerialNumber != HIWORD(v22) )
        v23 = nullptr;
      else
        v23 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_pEntity;
      CEventQueue::AddEvent(
        this: &g_EventQueue,
        target: v23,
        action: "KilledNPC",
        fireDelay: 0.30000001,
        pActivator: this,
        pCaller: this,
        outputID: 0);
    }
  }
  CBaseEntity::SendOnKilledGameEvent(this, a2: (int)info, info);
  if ( !this->ShouldGib(this, a2: info) )
  {
    if ( (info->m_bitsDamageType & 0x4000000) == 0 || !this->CanBecomeRagdoll(this) )
    {
LABEL_44:
      if ( (v4->m_bitsDamageType & 0x400000) == 0 )
        this->BecomeRagdoll(this, a2: v4, a3: &forceVector);
      goto LABEL_46;
    }
    v24 = (info->m_bitsDamageType & 0x100) != 0;
    v25 = ((int (__thiscall *)(CBaseCombatCharacter *, _DWORD, _DWORD, _DWORD, BOOL, _DWORD, _DWORD, _DWORD, _DWORD))this->Dissolve)(
            a1: this,
            a2: 0,
            a3: LODWORD(gpGlobals->curtime),
            a4: 0,
            a5: v24,
            a6: LODWORD(vec3_origin.x),
            a7: LODWORD(vec3_origin.y),
            a8: LODWORD(vec3_origin.z),
            a9: 0);
    if ( pDroppedWeapon != nullptr )
      ((void (__thiscall *)(CBaseCombatWeapon *, _DWORD, _DWORD, _DWORD, BOOL, _DWORD, _DWORD, _DWORD, _DWORD))pDroppedWeapon->Dissolve)(
        a1: pDroppedWeapon,
        a2: 0,
        a3: LODWORD(gpGlobals->curtime),
        a4: 0,
        a5: v24,
        a6: LODWORD(vec3_origin.x),
        a7: LODWORD(vec3_origin.y),
        a8: LODWORD(vec3_origin.z),
        a9: 0);
    if ( v25 == 0 )
    {
      v4 = info;
      goto LABEL_44;
    }
  }
LABEL_46:
  this->ClearLastKnownArea(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A7A90
// Name: public: virtual void CBaseCombatCharacter::SetLightingOriginRelative(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::SetLightingOriginRelative(
        CBaseCombatCharacter *this,
        CBaseEntity *pLightingOrigin)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  CNetworkHandleBase<CBaseEntity,CBaseAnimating::NetworkVar_m_hLightingOriginRelative>::Set(
    this: &this->m_hLightingOriginRelative,
    val: pLightingOrigin);
  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    ActiveWeapon->SetLightingOriginRelative(this: ActiveWeapon, a2: pLightingOrigin);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7AD0
// Name: public: virtual bool CBaseCombatCharacter::Weapon_EquipAmmoOnly(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::Weapon_EquipAmmoOnly(CBaseCombatCharacter *this, CBaseCombatWeapon *pWeapon)
{
  CBaseEntityList *v2; // ebx
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *p_m_hMyWeapons; // ecx
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  CBaseEntity *v12; // edi
  const char *Classname; // eax
  int m_Value; // ebx
  int m_iSecondaryAmmoCount; // edi
  int v17; // ebx
  int v18; // edi
  edict_t *m_pPev; // ecx
  int v20; // eax
  CNetworkVarBase<int,CBaseCombatWeapon::NetworkVar_m_iClip2> *p_m_iClip2; // edi
  int v22; // esi
  CNetworkVarBase<int,CBaseCombatWeapon::NetworkVar_m_iClip2> *v23; // eax
  CBaseEdict *v24; // ecx
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *j; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int takenPrimary; // [esp+20h] [ebp+8h]

  v2 = g_pEntityList;
  p_m_hMyWeapons = &this->m_hMyWeapons;
  i = 0;
  for ( j = p_m_hMyWeapons; ; j = (CBaseCombatCharacter::NetworkVar_m_hMyWeapons *)((char *)j + 4) )
  {
    m_Index = p_m_hMyWeapons->m_Value[0].m_Index;
    if ( m_Index != -1 )
    {
      v6 = (unsigned __int16)m_Index;
      v7 = &v2->m_EntPtrArray[(unsigned __int16)m_Index];
      v8 = HIWORD(m_Index);
      if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
      {
        v9 = v6;
        v10 = v2->m_EntPtrArray[v9].m_SerialNumber == v8;
        v11 = &v2->m_EntPtrArray[v9];
        v12 = v10 ? (CBaseEntity *)v11->m_pEntity : nullptr;
        Classname = CBaseEntity::GetClassname(this: pWeapon);
        if ( v12 == nullptr )
          goto LABEL_12;
        if ( v12->m_iClassname.pszValue == Classname
          || CBaseEntity::ClassMatchesComplex(this: v12, pszClassOrWildcard: Classname) != 0 )
        {
          break;
        }
        v2 = g_pEntityList;
      }
    }
LABEL_12:
    p_m_hMyWeapons = (CBaseCombatCharacter::NetworkVar_m_hMyWeapons *)&j->m_Value[1];
    if ( ++i >= 64 )
      return false;
  }
  if ( pWeapon->UsesClipsForAmmo1(this: pWeapon) )
    m_Value = pWeapon->m_iClip1.m_Value;
  else
    m_Value = pWeapon->m_iPrimaryAmmoCount;
  if ( pWeapon->UsesClipsForAmmo2(this: pWeapon) )
    m_iSecondaryAmmoCount = pWeapon->m_iClip2.m_Value;
  else
    m_iSecondaryAmmoCount = pWeapon->m_iSecondaryAmmoCount;
  takenPrimary = this->GiveAmmo(this, a2: m_Value, a3: pWeapon->m_iPrimaryAmmoType.m_Value, a4: false);
  v17 = this->GiveAmmo(this, a2: m_iSecondaryAmmoCount, a3: pWeapon->m_iSecondaryAmmoType.m_Value, a4: false);
  if ( pWeapon->UsesClipsForAmmo1(this: pWeapon) )
  {
    v18 = pWeapon->m_iClip1.m_Value - takenPrimary;
    if ( pWeapon->m_iClip1.m_Value != v18 )
    {
      if ( pWeapon->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&pWeapon->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = pWeapon->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
      }
      pWeapon->m_iClip1.m_Value = v18;
    }
  }
  else
  {
    pWeapon->m_iPrimaryAmmoCount -= takenPrimary;
  }
  if ( pWeapon->UsesClipsForAmmo2(this: pWeapon) )
  {
    v20 = pWeapon->m_iClip2.m_Value;
    p_m_iClip2 = &pWeapon->m_iClip2;
    v22 = v20 - v17;
    if ( v20 != v20 - v17 )
    {
      v23 = p_m_iClip2 - 301;
      if ( LOBYTE(p_m_iClip2[-280].m_Value) != 0 )
      {
        LOBYTE(v23[22].m_Value) |= 1u;
        p_m_iClip2->m_Value = v22;
      }
      else
      {
        v24 = (CBaseEdict *)v23[6].m_Value;
        if ( v24 != nullptr )
          CBaseEdict::StateChanged(this: v24, offset: 0x4B4u);
        p_m_iClip2->m_Value = v22;
      }
    }
  }
  else
  {
    pWeapon->m_iSecondaryAmmoCount -= v17;
  }
  return takenPrimary > 0 || v17 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A7CB0
// Name: public: virtual void CBaseCombatCharacter::VPhysicsShadowCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CBaseCombatCharacter::VPhysicsShadowCollision(
        CBaseCombatCharacter *this@<ecx>,
        CBaseCombatCharacter *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int index,
        gamevcollisionevent_t *pEvent)
{
  CBaseEntity *v6; // esi
  CScriptKeyValues *energyScale; // xmm0_4
  int (*GetPhysicsImpactDamageTable)(void); // edx
  const impactdamagetable_t *v9; // eax
  double v10; // st7
  IPhysicsObject *v11; // ecx
  float (__thiscall *GetMass)(IPhysicsObject *); // edx
  float v13; // xmm1_4
  float v14; // xmm2_4
  IServerVehicle *v15; // eax
  float v16; // eax
  __int128 v17; // xmm1
  bool v18; // cf
  void (__cdecl *v19)(int, _DWORD, _DWORD); // eax
  CBaseEntity *v20; // eax
  CBaseCombatCharacter *v21; // esi
  edict_t *m_pPev; // ecx
  _DWORD v24[3]; // [esp+3Ch] [ebp-ACh] BYREF
  __int128 dmgInfo_84; // [esp+9Ch] [ebp-4Ch] OVERLAPPED
  Vector v26; // [esp+B0h] [ebp-38h] BYREF
  Vector damagePos; // [esp+BCh] [ebp-2Ch] BYREF
  Vector damageForce; // [esp+C8h] [ebp-20h]
  int damage; // [esp+D4h] [ebp-14h] BYREF
  CBaseCombatCharacter *v30; // [esp+D8h] [ebp-10h]
  CBaseCombatCharacter *pPassenger; // [esp+DCh] [ebp-Ch]
  int damageType; // [esp+E0h] [ebp-8h]
  int retaddr; // [esp+E8h] [ebp+0h]

  pPassenger = a2;
  damageType = retaddr;
  v30 = this;
  v6 = pEvent->pEntities[index == 0];
  if ( v6 != nullptr
    && v6->m_lifeState.m_Value != 1
    && v6->m_MoveType.m_Value == 6
    && pEvent->pObjects[index == 0]->IsMoveable(this: pEvent->pObjects[index == 0])
    && v6 != CBaseEntity::GetGroundEntity(this: v30)
    && v30 != (CBaseCombatCharacter *)((int (__thiscall *)(CBaseEntity *, _DWORD))v6->HasPhysicsAttacker)(a1: v6, a2: 0) )
  {
    energyScale = (CScriptKeyValues *)LODWORD(v30->m_impactEnergyScale);
    GetPhysicsImpactDamageTable = (int (*)(void))v30->GetPhysicsImpactDamageTable;
    damage = 0;
    v9 = (const impactdamagetable_t *)GetPhysicsImpactDamageTable();
    v10 = CalculatePhysicsImpactDamage(
            index,
            pEvent,
            table: v9,
            energyScale: *(float *)&energyScale,
            allowStaticDamage: false,
            damageType: &damage,
            bDamageFromHeldObjects: false);
    damageForce.x = v10;
    if ( v10 > 0.0 )
    {
      v11 = pEvent->pObjects[index];
      GetMass = v11->GetMass;
      damageForce.y = phys_impactforcescale.m_pParent->m_Value.m_fValue;
      damageForce.z = ((double (__thiscall *)(IPhysicsObject *, int, int))GetMass)(a1: v11, a2: a3, a3: a4);
      v13 = (float)(pEvent->postVelocity[index].y * damageForce.z) * damageForce.y;
      v14 = (float)(pEvent->postVelocity[index].z * damageForce.z) * damageForce.y;
      damagePos.x = (float)(pEvent->postVelocity[index].x * damageForce.z) * damageForce.y;
      damagePos.y = v13;
      damagePos.z = v14;
      v15 = v6->GetServerVehicle(this: v6);
      if ( v15 != nullptr )
      {
        v16 = COERCE_FLOAT(v15->GetPassenger(this: v15, a2: 0));
        damageForce.z = v16;
        if ( v16 != 0.0 )
        {
          damage |= 0x10u;
          damageForce.y = damagePos.y * damagePos.y;
          v17 = 0;
          *(float *)&v17 = fsqrt(
                             (float)((float)(damagePos.y * damagePos.y) + (float)(damagePos.z * damagePos.z))
                           + (float)(damagePos.x * damagePos.x));
          dmgInfo_84 = v17;
          damagePos.z = (float)(phys_upimpactforcescale.m_pParent->m_Value.m_fValue * *(float *)&v17) + damagePos.z;
          if ( (*(unsigned __int8 (__thiscall **)(float))(*(_DWORD *)LODWORD(v16) + 336))(a1: COERCE_FLOAT(LODWORD(v16))) != 0 )
          {
            v18 = damageForce.x < (float)v30->GetMaxHealth(this: v30);
            v19 = *(void (__cdecl **)(int, _DWORD, _DWORD))(*(_DWORD *)LODWORD(damageForce.z) + 1504);
            v24[0] = 4;
            if ( v18 )
              v19(a1: 1, a2: 0, a3: v24[0]);
            else
              v19(a1: 2, a2: 0, a3: v24[0]);
          }
        }
      }
      pEvent->pInternalData->GetContactPoint(this: pEvent->pInternalData, a2: &v26);
      CTakeDamageInfo::CTakeDamageInfo(
        this: (CTakeDamageInfo *)v24,
        pInflictor: v6,
        pAttacker: v6,
        damageForce: &damagePos,
        damagePosition: &v26,
        flDamage: damageForce.x,
        bitsDamageType: damage,
        iKillType: 0,
        reportedPosition: nullptr,
        iObjectsPenetrated: 0);
      v20 = (CBaseEntity *)((int (__thiscall *)(CBaseEntity *, int))v6->HasPhysicsAttacker)(a1: v6, a2: 1065353216);
      if ( v20 != nullptr )
        CTakeDamageInfo::SetAttacker(this: (CTakeDamageInfo *)v24, pAttacker: v20);
      v21 = v30;
      if ( v30->m_nForceBone.m_Value != 0 )
      {
        if ( v30->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v30->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = v30->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
        }
        v21->m_nForceBone.m_Value = 0;
      }
      PhysCallbackDamage(pEntity: v21, info: (const CTakeDamageInfo *)v24, event: pEvent, hurtIndex: index);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7F80
// Name: public: void CBaseCombatCharacter::SetActiveWeapon(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::SetActiveWeapon(CBaseCombatCharacter *this, CBaseCombatWeapon *pNewWeapon)
{
  unsigned int m_Index; // eax
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> *p_m_hActiveWeapon; // ecx
  CBaseCombatWeapon *m_pEntity; // edi

  m_Index = this->m_hActiveWeapon.m_Value.m_Index;
  p_m_hActiveWeapon = &this->m_hActiveWeapon;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( pNewWeapon != m_pEntity )
  {
    CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon>::Set(
      this: p_m_hActiveWeapon,
      val: pNewWeapon);
    this->OnChangeActiveWeapon(this, a2: m_pEntity, a3: pNewWeapon);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7FE0
// Name: public: void CBaseCombatCharacter::OnFogTriggerEndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::OnFogTriggerEndTouch(CBaseCombatCharacter *this, unsigned int fogTrigger)
{
  int v3; // eax

  if ( fogTrigger != 0 )
    fogTrigger = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)fogTrigger + 8))(a1: fogTrigger);
  else
    fogTrigger = -1;
  v3 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: &this->m_hTriggerFogList,
         src: (CHandle<CBaseEntity> *)&fogTrigger);
  if ( v3 != -1 )
  {
    if ( this->m_hTriggerFogList.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &this->m_hTriggerFogList.m_Memory.m_pMemory[v3],
        src: &this->m_hTriggerFogList.m_Memory.m_pMemory[v3 + 1],
        count: 4 * (this->m_hTriggerFogList.m_Size - v3 - 1));
    --this->m_hTriggerFogList.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8050
// Name: public: virtual float CBaseCombatCharacter::GetFogObscuredRatio(float)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatCharacter::GetFogObscuredRatio(CBaseCombatCharacter *this, float range)
{
  bool (__thiscall *GetFogParams)(CBaseCombatCharacter *, fogparams_t *); // eax
  fogparams_t fog; // [esp+0h] [ebp-4Ch] BYREF
  float ratio; // [esp+54h] [ebp+8h]

  GetFogParams = this->GetFogParams;
  fog.__vftable = (fogparams_t_vtbl *)&fogparams_t::`vftable';
  GetFogParams(this, a2: &fog);
  if ( !fog.enable.m_Value || fog.start.m_Value >= range )
    return 0.0;
  if ( range >= fog.end.m_Value )
    return 1.0;
  ratio = (float)(range - fog.start.m_Value) / (float)(fog.end.m_Value - fog.start.m_Value);
  if ( fog.maxdensity.m_Value <= ratio )
    return fog.maxdensity.m_Value;
  return ratio;
}

//------------------------------------------------------------------------------
// Address: 0x100A83C0
// Name: public: CBaseCombatCharacter::CBaseCombatCharacter(void)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatCharacter *__thiscall CBaseCombatCharacter::CBaseCombatCharacter(CBaseCombatCharacter *this)
{
  IntervalTimer_vtbl *v2; // edx
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  void (__stdcall *v4)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *); // eax
  unsigned int m_Index; // eax
  edict_t *m_pPev; // ecx
  int v7; // edx
  edict_t *v8; // ecx
  int i; // [esp+Ch] [ebp-4h]
  int ia; // [esp+Ch] [ebp-4h]

  CBaseFlex::CBaseFlex(this);
  this->__vftable = (CBaseCombatCharacter_vtbl *)&CBaseCombatCharacter::`vftable';
  this->m_Relationship.m_Memory.m_pMemory = nullptr;
  this->m_Relationship.m_Memory.m_nAllocationCount = 0;
  this->m_Relationship.m_Memory.m_nGrowSize = 0;
  this->m_Relationship.m_Size = 0;
  this->m_Relationship.m_pElements = nullptr;
  this->m_hTriggerFogList.m_Memory.m_pMemory = nullptr;
  this->m_hTriggerFogList.m_Memory.m_nAllocationCount = 0;
  this->m_hTriggerFogList.m_Memory.m_nGrowSize = 0;
  this->m_hTriggerFogList.m_Size = 0;
  this->m_hTriggerFogList.m_pElements = nullptr;
  this->m_hLastFogTrigger.m_Index = -1;
  memset(&this->m_hMyWeapons, 0xFFu, sizeof(this->m_hMyWeapons));
  this->m_hActiveWeapon.m_Value.m_Index = -1;
  this->m_aliveTimer.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v2 = this->m_aliveTimer.__vftable;
  this->m_aliveTimer.m_timestamp.m_Value = -1.0;
  ((void (__stdcall *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v2->NetworkStateChanged)(a1: &this->m_aliveTimer.m_timestamp);
  i = 3;
  p_m_timestamp = &this->m_damageHistory[0].interval.m_timestamp;
  do
  {
    LODWORD(p_m_timestamp[-1].m_Value) = &IntervalTimer::`vftable';
    v4 = *(void (__stdcall **)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-1].m_Value)
                                                                                              + 4);
    p_m_timestamp->m_Value = -1.0;
    v4(a1: p_m_timestamp);
    p_m_timestamp += 3;
    --i;
  }
  while ( i >= 0 );
  this->m_NavAreaUpdateMonitor.m_vMark.x = 0.0;
  this->m_NavAreaUpdateMonitor.m_vMark.y = 0.0;
  this->m_NavAreaUpdateMonitor.m_vMark.z = 0.0;
  this->m_NavAreaUpdateMonitor.m_flMarkTolerance = -1.0;
  this->m_flDamageAccumulator = 0.0;
  m_Index = this->m_hActiveWeapon.m_Value.m_Index;
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
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x894u);
    }
    this->m_hActiveWeapon.m_Value.m_Index = -1;
  }
  this->m_nFaction = 0;
  CBaseCombatCharacter::RemoveAllAmmo(this);
  if ( this->m_aliveTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_aliveTimer.NetworkStateChanged(this: &this->m_aliveTimer, a2: &this->m_aliveTimer.m_timestamp);
    this->m_aliveTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_hasBeenInjured = 0;
  this->m_damageHistory[0].team = -1;
  this->m_damageHistory[1].team = -1;
  this->m_damageHistory[2].team = -1;
  this->m_damageHistory[3].team = -1;
  v7 = 0;
  this->m_lastNavArea = nullptr;
  this->m_registeredNavTeam = -1;
  ia = 0;
  do
  {
    if ( this->m_hMyWeapons.m_Value[v7].m_Index != -1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 4 * v7 + 1940);
          v7 = ia;
        }
      }
      this->m_hMyWeapons.m_Value[v7].m_Index = -1;
    }
    ia = ++v7;
  }
  while ( v7 < 64 );
  _V_memset(dest: this->m_weaponIDToIndex, fill: 0, count: 42);
  this->m_impactEnergyScale = 1.0;
  this->m_bForceServerRagdoll = ai_force_serverside_ragdoll.m_pParent != nullptr
                             && ai_force_serverside_ragdoll.m_pParent->m_Value.m_nValue != 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A8640
// Name: public: virtual class Vector CBaseCombatCharacter::HeadDirection2D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseCombatCharacter::HeadDirection2D(CBaseCombatCharacter *this, Vector *result)
{
  this->BodyDirection2D(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A86A0
// Name: public: bool CBaseCombatCharacter::Weapon_Detach(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatCharacter::Weapon_Detach(CBaseCombatCharacter *this, CBaseCombatWeapon *pWeapon)
{
  CBaseCombatCharacter *v2; // ebx
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *p_m_hMyWeapons; // edi
  int v4; // esi
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *i; // edx
  unsigned int m_Index; // eax
  CBaseCombatWeapon *m_pEntity; // ecx
  CHandle<CBaseCombatWeapon> *v9; // eax
  CBaseEdict *v10; // ecx
  int v11; // eax
  unsigned int v12; // eax
  CBaseCombatWeapon *v13; // edx
  CEntInfo *v14; // edx
  CBaseCombatWeapon *v15; // esi

  v2 = this;
  p_m_hMyWeapons = &this->m_hMyWeapons;
  v4 = 0;
  for ( i = &this->m_hMyWeapons; ; i = (CBaseCombatCharacter::NetworkVar_m_hMyWeapons *)((char *)i + 4) )
  {
    m_Index = i->m_Value[0].m_Index;
    if ( i->m_Value[0].m_Index == -1
      || (v2 = this, g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    if ( pWeapon == m_pEntity )
      break;
    if ( ++v4 >= 64 )
      return 0;
  }
  if ( p_m_hMyWeapons->m_Value[v4].m_Index != -1 )
  {
    v9 = &p_m_hMyWeapons[-8].m_Value[27];
    if ( LOBYTE(p_m_hMyWeapons[-8].m_Value[48].m_Index) != 0 )
    {
      LOBYTE(v9[22].m_Index) |= 1u;
    }
    else
    {
      v10 = (CBaseEdict *)v9[6].m_Index;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: v10, offset: 4 * v4 + 1940);
    }
    p_m_hMyWeapons->m_Value[v4].m_Index = -1;
  }
  v11 = 0;
  while ( v2->m_weaponIDToIndex[v11] != v4 + 1 )
  {
    if ( (unsigned int)++v11 >= 0x2A )
      goto LABEL_20;
  }
  v2->m_weaponIDToIndex[v11] = 0;
LABEL_20:
  CBaseCombatWeapon::SetOwner(this: pWeapon, owner: nullptr);
  v12 = v2->m_hActiveWeapon.m_Value.m_Index;
  if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
    v13 = nullptr;
  else
    v13 = (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
  if ( pWeapon == v13 && v12 != -1 )
  {
    v14 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v12];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == HIWORD(v12) )
    {
      v15 = (CBaseCombatWeapon *)v14->m_pEntity;
      if ( v14->m_pEntity != nullptr )
      {
        CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon>::Set(
          this: &v2->m_hActiveWeapon,
          val: nullptr);
        v2->OnChangeActiveWeapon(this: v2, a2: v15, a3: nullptr);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A87F0
// Name: public: virtual void CBaseCombatCharacter::Weapon_Drop(class CBaseCombatWeapon __near *,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CBaseCombatCharacter::Weapon_Drop(
        CBaseCombatCharacter *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseCombatWeapon *pWeapon,
        const Vector *pvecTarget,
        const Vector *pVelocity)
{
  edict_t *m_pPev; // ecx
  CBasePlayer *v9; // eax
  CBaseCombatWeapon_vtbl *v10; // edx
  CBasePlayer *v11; // eax
  edict_t *v12; // ecx
  edict_t *v13; // ecx
  Vector *v14; // eax
  const Vector *v15; // eax
  bool v16; // zf
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v18; // ecx
  int v19; // eax
  void (__thiscall *Teleport)(CBaseEntity *, const Vector *, const QAngle *, const Vector *, bool); // edx
  Vector *(__thiscall *Weapon_ShootPosition)(CBaseCombatCharacter *, Vector *); // edx
  float *v22; // eax
  Vector *v23; // ecx
  Vector *v24; // eax
  float y; // xmm1_4
  int z_low; // xmm2_4
  float v27; // xmm0_4
  __int128 v28; // xmm1
  float v29; // xmm0_4
  Vector *(__thiscall *BodyDirection3D)(CBaseCombatCharacter *, Vector *); // edx
  float *v31; // eax
  float v32; // xmm1_4
  int v33; // xmm2_4
  int v34; // [esp+18h] [ebp-120h]
  float *p_y; // [esp+20h] [ebp-118h]
  _BYTE v37[12]; // [esp+28h] [ebp-110h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-104h] BYREF
  matrix3x4_t rootLocal; // [esp+64h] [ebp-D4h] BYREF
  matrix3x4_t rootInvLocal; // [esp+94h] [ebp-A4h] BYREF
  _BYTE weaponMatrix[56]; // [esp+C4h] [ebp-74h] OVERLAPPED BYREF
  QAngle angles; // [esp+FCh] [ebp-3Ch] BYREF
  float v43; // [esp+108h] [ebp-30h]
  Vector origin; // [esp+10Ch] [ebp-2Ch] BYREF
  int iWeaponBoneIndex; // [esp+118h] [ebp-20h]
  Vector vecThrow; // [esp+11Ch] [ebp-1Ch] BYREF
  Vector vFacingDir; // [esp+128h] [ebp-10h] BYREF
  float retaddr; // [esp+138h] [ebp+0h]

  vFacingDir.y = a2;
  vFacingDir.z = retaddr;
  if ( pWeapon == nullptr )
    return;
  if ( (this->m_fFlags.m_Value & 0x4000) != 0 )
  {
    if ( !pWeapon->UsesClipsForAmmo1(this: pWeapon) )
      goto LABEL_24;
    LODWORD(vFacingDir.x) = pWeapon->GetDefaultClip1(this: pWeapon);
    if ( pWeapon->m_iClip1.m_Value != LODWORD(vFacingDir.x) )
    {
      if ( pWeapon->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&pWeapon->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = pWeapon->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
      }
      pWeapon->m_iClip1.m_Value = LODWORD(vFacingDir.x);
    }
    if ( pWeapon->m_iClassname.pszValue != "weapon_smg1"
      && CBaseEntity::ClassMatchesComplex(this: pWeapon, pszClassOrWildcard: "weapon_smg1") == 0 )
    {
      goto LABEL_24;
    }
    v9 = UTIL_PlayerByIndex(playerIndex: 1);
    v10 = pWeapon->__vftable;
    if ( v9 != nullptr )
    {
      LODWORD(vFacingDir.x) = &g_pGameRules->GetAmmoDamage;
      v34 = v10->GetPrimaryAmmoType(this: pWeapon);
      v11 = UTIL_PlayerByIndex(playerIndex: 1);
      vFacingDir.x = ((double (__thiscall *)(CGameRules *, CBasePlayer *, CBaseCombatCharacter *, int))*(_DWORD *)LODWORD(vFacingDir.x))(
                       a1: g_pGameRules,
                       a2: v11,
                       a3: this,
                       a4: v34);
      LODWORD(vFacingDir.x) = (int)(float)((float)((float)this->GetMaxHealth(this) / vFacingDir.x) * 2.0);
      if ( pWeapon->m_iClip1.m_Value != LODWORD(vFacingDir.x) )
      {
        if ( pWeapon->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&pWeapon->m_Network + 76) |= 1u;
LABEL_23:
          pWeapon->m_iClip1.m_Value = LODWORD(vFacingDir.x);
          goto LABEL_24;
        }
        v12 = pWeapon->m_Network.m_pPev;
        if ( v12 == nullptr )
          goto LABEL_23;
LABEL_22:
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x4B0u);
        goto LABEL_23;
      }
    }
    else
    {
      LODWORD(vFacingDir.x) = v10->GetMaxClip1(this: pWeapon);
      if ( pWeapon->m_iClip1.m_Value != LODWORD(vFacingDir.x) )
      {
        if ( pWeapon->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&pWeapon->m_Network + 76) |= 1u;
          goto LABEL_23;
        }
        v12 = pWeapon->m_Network.m_pPev;
        if ( v12 == nullptr )
          goto LABEL_23;
        goto LABEL_22;
      }
    }
LABEL_24:
    if ( pWeapon->UsesClipsForAmmo2(this: pWeapon) )
    {
      LODWORD(vFacingDir.x) = pWeapon->GetDefaultClip2(this: pWeapon);
      if ( pWeapon->m_iClip2.m_Value != LODWORD(vFacingDir.x) )
      {
        if ( pWeapon->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&pWeapon->m_Network + 76) |= 1u;
        }
        else
        {
          v13 = pWeapon->m_Network.m_pPev;
          if ( v13 != nullptr )
            CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x4B4u);
        }
        pWeapon->m_iClip2.m_Value = LODWORD(vFacingDir.x);
      }
    }
  }
  if ( ((unsigned __int8 (__thiscall *)(CBaseCombatCharacter *, int, int))this->IsPlayer)(a1: this, a2: a3, a3: a4) != 0 )
  {
    v14 = this->Weapon_ShootPosition(this, result: &weaponMatrix[44]);
    vecThrow.x = v14->x;
    vecThrow.y = v14->y;
    vecThrow.z = v14->z - 12.0;
    if ( (enginetrace->GetPointContents(this: enginetrace, a2: &vecThrow, a3: 1, a4: nullptr) & 1) != 0 )
      _Msg(a1: "Weapon spawning in solid!\n");
    CBaseEntity::SetAbsOrigin(this: pWeapon, absOrigin: &vecThrow);
    p_y = &angles.y;
    v15 = (const Vector *)((int (__thiscall *)(CBaseCombatCharacter *))this->BodyDirection2D)(a1: this);
    VectorAngles(forward: v15, angles: (QAngle *)&weaponMatrix[44]);
    CBaseEntity::SetAbsAngles(this: pWeapon, absAngles: (QAngle *)&angles.y);
    goto LABEL_47;
  }
  v16 = pWeapon->m_pStudioHdr == nullptr;
  origin.x = NAN;
  if ( v16 && CBaseEntity::GetModel(this: pWeapon) != nullptr )
    CBaseAnimating::LockStudioHdr(this: pWeapon);
  m_pStudioHdr = pWeapon->m_pStudioHdr;
  *(_DWORD *)&weaponMatrix[36] = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && (v18 = m_pStudioHdr->m_pStudioHdr, m_pStudioHdr->m_pStudioHdr->numbones > 0) )
  {
    origin.x = 0.0;
    vFacingDir.x = 0.0;
    while ( 1 )
    {
      v19 = CBaseAnimating::LookupBone(
              this,
              szName: (const char *)v18
            + v18->boneindex
            + LODWORD(vFacingDir.x)
            + *(int *)((char *)&v18->id + v18->boneindex + LODWORD(vFacingDir.x)));
      if ( v19 != -1 )
        break;
      v18 = **(const studiohdr_t ***)&weaponMatrix[36];
      LODWORD(vFacingDir.x) += 216;
      ++LODWORD(origin.x);
      if ( SLODWORD(origin.x) >= v18->numbones )
        goto LABEL_44;
    }
  }
  else
  {
LABEL_44:
    v19 = CBaseAnimating::LookupBone(this, szName: "ValveBiped.Weapon_bone");
    if ( v19 == -1 )
    {
      this->BodyDirection2D(this, result: &vecThrow);
      Weapon_ShootPosition = this->Weapon_ShootPosition;
      vecThrow.x = vecThrow.x * 10.0;
      vecThrow.y = vecThrow.y * 10.0;
      vecThrow.z = vecThrow.z * 10.0;
      v22 = (float *)Weapon_ShootPosition(this, result: (Vector *)&weaponMatrix[44]);
      angles.y = *v22 + vecThrow.x;
      angles.z = v22[1] + vecThrow.y;
      v43 = v22[2] + vecThrow.z;
      CBaseEntity::SetAbsOrigin(this: pWeapon, absOrigin: (const Vector *)&angles.y);
      goto LABEL_47;
    }
  }
  this->GetBoneTransform(this, a2: v19, a3: (matrix3x4_t *)v37);
  CBaseEntity::StopFollowingEntity(this: pWeapon);
  memset((void *)&vecThrow, 0, sizeof(vecThrow));
  CBaseEntity::SetAbsOrigin(this: pWeapon, absOrigin: &vecThrow);
  memset((void *)&vecThrow, 0, sizeof(vecThrow));
  CBaseEntity::SetAbsAngles(this: pWeapon, absAngles: (const QAngle *)&vecThrow);
  pWeapon->InvalidateBoneCache(this: pWeapon);
  pWeapon->GetBoneTransform(this: pWeapon, a2: LODWORD(origin.x), a3: (matrix3x4_t *)&transform.m_flMatVal[2][1]);
  MatrixInvert(in: (matrix3x4_t *)&transform.m_flMatVal[2][1], out: (matrix3x4_t *)&rootLocal.m_flMatVal[2][1]);
  ConcatTransforms(
    in1: (const matrix3x4_t *)v37,
    in2: (matrix3x4_t *)&rootLocal.m_flMatVal[2][1],
    out: (matrix3x4_t *)&rootInvLocal.m_flMatVal[2][1]);
  MatrixAngles(
    a1: (int)pWeapon,
    src: (const VMatrix *)&rootInvLocal.m_flMatVal[2][1],
    vAngles: (QAngle *)&weaponMatrix[44]);
  Teleport = pWeapon->Teleport;
  angles.y = *(float *)weaponMatrix;
  angles.z = *(float *)&weaponMatrix[16];
  v43 = *(float *)&weaponMatrix[32];
  Teleport(this: pWeapon, a2: (const Vector *)&angles.y, a3: (const QAngle *)&weaponMatrix[44], a4: nullptr, a5: true);
LABEL_47:
  v23 = pvecTarget;
  if ( pvecTarget != nullptr )
  {
    if ( (pWeapon->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: pWeapon, a2: (int)&vFacingDir.y);
      v23 = pvecTarget;
    }
    v24 = VecCheckToss(
            result: (Vector *)&weaponMatrix[44],
            pEntity: this,
            vecSpot1: pWeapon->m_vecAbsOrigin,
            vecSpot2: *v23,
            flHeightMaxRatio: 0.2,
            flGravityAdj: 1.0,
            bRandomize: false,
            vecMins: nullptr,
            vecMaxs: nullptr);
    origin.y = v24->x;
    origin.z = v24->y;
    iWeaponBoneIndex = SLODWORD(v24->z);
  }
  else if ( pVelocity != nullptr )
  {
    y = pVelocity->y;
    z_low = SLODWORD(pVelocity->z);
    origin.y = pVelocity->x;
    origin.z = y;
    iWeaponBoneIndex = z_low;
    v27 = (float)((float)(origin.y * origin.y) + (float)(y * y)) + (float)(*(float *)&z_low * *(float *)&z_low);
    v28 = 0;
    *(float *)&v28 = fsqrt(v27);
    *(_OWORD *)&weaponMatrix[40] = v28;
    if ( *(float *)&v28 > 400.0 )
    {
      VectorNormalize(vec: (Vector *)&origin.y);
      origin.y = origin.y * 400.0;
      origin.z = origin.z * 400.0;
      *(float *)&iWeaponBoneIndex = *(float *)&iWeaponBoneIndex * 400.0;
    }
  }
  else
  {
    if ( ((unsigned __int8 (__thiscall *)(CBaseCombatCharacter *, float *))this->IsPlayer)(a1: this, a2: p_y) != 0 )
      v29 = 400.0;
    else
      v29 = (float)random->RandomInt(this: random, a2: 64, a3: 128);
    BodyDirection3D = this->BodyDirection3D;
    vFacingDir.x = v29;
    v31 = (float *)BodyDirection3D(this, result: (Vector *)&weaponMatrix[44]);
    v32 = v31[1] * vFacingDir.x;
    *(float *)&v33 = v31[2] * vFacingDir.x;
    origin.y = *v31 * vFacingDir.x;
    origin.z = v32;
    iWeaponBoneIndex = v33;
  }
  pWeapon->Drop(this: pWeapon, a2: (Vector *)&origin.y);
  CBaseCombatCharacter::Weapon_Detach(this, pWeapon);
  if ( (this->m_spawnflags.m_Value & 0x2000) != 0 )
    UTIL_Remove(oldObj: pWeapon);
}

//------------------------------------------------------------------------------
// Address: 0x100A8E80
// Name: public: virtual void CBaseCombatCharacter::Weapon_Equip(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::Weapon_Equip(CBaseCombatCharacter *this, CBaseCombatWeapon *pWeapon)
{
  int v2; // ebx
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *p_m_hMyWeapons; // edx
  unsigned int m_Index; // eax
  edict_t *m_pPev; // ecx
  CBaseCombatCharacter *v7; // ebx
  CBaseCombatWeapon_vtbl *v8; // edi
  int TeamNumber; // eax
  CBaseCombatCharacter_vtbl *v10; // edi
  int v11; // eax
  int v12; // edi
  int v13; // ebx
  edict_t *v14; // ecx
  CBaseCombatCharacter_vtbl *v15; // edi
  int v16; // ebx
  int v17; // eax
  CBaseCombatCharacter_vtbl *v18; // edi
  int v19; // eax
  int v20; // edi
  int v21; // ebx
  edict_t *v22; // ecx
  CBaseCombatCharacter_vtbl *v23; // edi
  int v24; // ebx
  int v25; // eax
  unsigned int v26; // ecx
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> *p_m_hActiveWeapon; // edi
  int v28; // eax
  CEntInfo *v29; // edx
  unsigned int v30; // ecx
  int v31; // eax
  bool v32; // zf
  CEntInfo *v33; // eax
  IHandleEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> v35; // eax
  unsigned int v36; // eax
  CBaseCombatWeapon *v37; // edi
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> v38; // eax
  CBaseCombatWeapon *v39; // edx
  unsigned int v40; // ebx
  CBaseEdict *v41; // ecx
  unsigned int v42; // eax
  IHandleEntity *v43; // ecx
  unsigned int v44; // eax
  IHandleEntity *v45; // ecx
  const char *pszValue; // edi
  const char *WeaponProficiencyName; // eax
  unsigned int v48; // eax
  CBaseEntity *v49; // ecx
  WeaponProficiency_t proficiencya; // [esp+Ch] [ebp-4h]
  unsigned int pWeapona; // [esp+18h] [ebp+8h]
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> *pWeaponb; // [esp+18h] [ebp+8h]
  CBaseCombatWeapon *pWeaponc; // [esp+18h] [ebp+8h]
  const char *pWeapond; // [esp+18h] [ebp+8h]

  v2 = 0;
  p_m_hMyWeapons = &this->m_hMyWeapons;
  while ( 1 )
  {
    m_Index = p_m_hMyWeapons->m_Value[0].m_Index;
    if ( p_m_hMyWeapons->m_Value[0].m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      break;
    }
    ++v2;
    p_m_hMyWeapons = (CBaseCombatCharacter::NetworkVar_m_hMyWeapons *)((char *)p_m_hMyWeapons + 4);
    if ( v2 >= 64 )
      goto LABEL_17;
  }
  if ( pWeapon != nullptr )
    pWeapona = pWeapon->GetRefEHandle(this: pWeapon)->m_Index;
  else
    pWeapona = -1;
  if ( this->m_hMyWeapons.m_Value[v2].m_Index != pWeapona )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 4 * v2 + 1940);
    }
    this->m_hMyWeapons.m_Value[v2].m_Index = pWeapona;
  }
  this->m_weaponIDToIndex[pWeapon->GetWeaponID(this: pWeapon)] = v2 + 1;
LABEL_17:
  v7 = this;
  v8 = pWeapon->__vftable;
  TeamNumber = CBaseEntity::GetTeamNumber(this);
  v8->ChangeTeam(this: pWeapon, a2: TeamNumber);
  if ( pWeapon->GetMaxClip1(this: pWeapon) == -1 )
  {
    v10 = this->__vftable;
    v11 = ((int (__thiscall *)(CBaseCombatWeapon *, int, _DWORD))pWeapon->GetDefaultClip1)(
            a1: pWeapon,
            a2: pWeapon->m_iPrimaryAmmoType.m_Value,
            a3: 0);
    ((void (__thiscall *)(CBaseCombatCharacter *, int))v10->GiveAmmo)(a1: this, a2: v11);
  }
  else
  {
    v12 = pWeapon->GetDefaultClip1(this: pWeapon);
    if ( v12 > pWeapon->GetMaxClip1(this: pWeapon) )
    {
      v13 = pWeapon->GetMaxClip1(this: pWeapon);
      if ( pWeapon->m_iClip1.m_Value != v13 )
      {
        if ( pWeapon->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&pWeapon->m_Network + 76) |= 1u;
        }
        else
        {
          v14 = pWeapon->m_Network.m_pPev;
          if ( v14 != nullptr )
            CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x4B0u);
        }
        pWeapon->m_iClip1.m_Value = v13;
      }
      v15 = this->__vftable;
      v16 = ((int (__thiscall *)(CBaseCombatWeapon *, int, _DWORD))pWeapon->GetDefaultClip1)(
              a1: pWeapon,
              a2: pWeapon->m_iPrimaryAmmoType.m_Value,
              a3: 0);
      v17 = pWeapon->GetMaxClip1(this: pWeapon);
      ((void (__thiscall *)(CBaseCombatCharacter *, int))v15->GiveAmmo)(a1: this, a2: v16 - v17);
      v7 = this;
    }
  }
  if ( pWeapon->GetMaxClip2(this: pWeapon) == -1 )
  {
    v7 = this;
    v18 = this->__vftable;
    v19 = ((int (__thiscall *)(CBaseCombatWeapon *, int, _DWORD))pWeapon->GetDefaultClip2)(
            a1: pWeapon,
            a2: pWeapon->m_iSecondaryAmmoType.m_Value,
            a3: 0);
    ((void (__thiscall *)(CBaseCombatCharacter *, int))v18->GiveAmmo)(a1: this, a2: v19);
  }
  else
  {
    v20 = pWeapon->GetDefaultClip2(this: pWeapon);
    if ( v20 > pWeapon->GetMaxClip2(this: pWeapon) )
    {
      v21 = pWeapon->GetMaxClip2(this: pWeapon);
      if ( pWeapon->m_iClip2.m_Value != v21 )
      {
        if ( pWeapon->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&pWeapon->m_Network + 76) |= 1u;
        }
        else
        {
          v22 = pWeapon->m_Network.m_pPev;
          if ( v22 != nullptr )
            CBaseEdict::StateChanged(this: &v22->CBaseEdict, offset: 0x4B4u);
        }
        pWeapon->m_iClip2.m_Value = v21;
      }
      v23 = this->__vftable;
      v24 = ((int (__thiscall *)(CBaseCombatWeapon *, int, _DWORD))pWeapon->GetDefaultClip2)(
              a1: pWeapon,
              a2: pWeapon->m_iSecondaryAmmoType.m_Value,
              a3: 0);
      v25 = pWeapon->GetMaxClip2(this: pWeapon);
      ((void (__thiscall *)(CBaseCombatCharacter *, int))v23->GiveAmmo)(a1: this, a2: v24 - v25);
      v7 = this;
    }
  }
  pWeapon->Equip(this: pWeapon, a2: v7);
  if ( !v7->IsPlayer(this: v7) )
  {
    v26 = v7->m_hActiveWeapon.m_Value.m_Index;
    p_m_hActiveWeapon = &v7->m_hActiveWeapon;
    pWeaponb = &v7->m_hActiveWeapon;
    if ( v26 != -1 )
    {
      v28 = (unsigned __int16)v26;
      v29 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v26];
      v30 = HIWORD(v26);
      if ( v29->m_SerialNumber == v30 && v29->m_pEntity != nullptr )
      {
        v31 = v28;
        v32 = g_pEntityList->m_EntPtrArray[v31].m_SerialNumber == v30;
        v33 = &g_pEntityList->m_EntPtrArray[v31];
        if ( v32 )
          m_pEntity = v33->m_pEntity;
        else
          m_pEntity = nullptr;
        ((void (__thiscall *)(IHandleEntity *, _DWORD))m_pEntity->__vftable[87].GetRefEHandle)(a1: m_pEntity, a2: 0);
        p_m_hActiveWeapon = &v7->m_hActiveWeapon;
        v35.m_Value.m_Index = pWeaponb->m_Value.m_Index;
        if ( pWeaponb->m_Value.m_Index == -1
          || g_pEntityList->m_EntPtrArray[LOWORD(v35.m_Value.m_Index)].m_SerialNumber != HIWORD(v35.m_Value.m_Index) )
        {
          CBaseEntity::AddEffects(this: nullptr, nEffects: 32);
        }
        else
        {
          CBaseEntity::AddEffects(
            this: (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(v35.m_Value.m_Index)].m_pEntity,
            nEffects: 32);
        }
      }
      else
      {
        p_m_hActiveWeapon = &v7->m_hActiveWeapon;
      }
    }
    v36 = p_m_hActiveWeapon->m_Value.m_Index;
    if ( p_m_hActiveWeapon->m_Value.m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v36].m_SerialNumber != HIWORD(v36) )
    {
      v37 = nullptr;
    }
    else
    {
      v37 = (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v36].m_pEntity;
    }
    if ( pWeapon != v37 )
    {
      CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon>::Set(
        this: pWeaponb,
        val: pWeapon);
      v7->OnChangeActiveWeapon(this: v7, a2: v37, a3: pWeapon);
    }
    v38.m_Value.m_Index = pWeaponb->m_Value.m_Index;
    if ( pWeaponb->m_Value.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(v38.m_Value.m_Index)].m_SerialNumber != HIWORD(v38.m_Value.m_Index) )
    {
      pWeaponc = nullptr;
    }
    else
    {
      pWeaponc = (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[LOWORD(v38.m_Value.m_Index)].m_pEntity;
    }
    v39 = pWeaponc;
    v40 = pWeaponc->m_fEffects.m_Value & 0xFFFFFFDF;
    if ( pWeaponc->m_fEffects.m_Value != v40 )
    {
      if ( pWeaponc->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&pWeaponc->m_Network + 76) |= 1u;
      }
      else
      {
        v41 = &pWeaponc->m_Network.m_pPev->CBaseEdict;
        if ( v41 != nullptr )
        {
          CBaseEdict::StateChanged(this: v41, offset: 0xA4u);
          v39 = pWeaponc;
        }
      }
      pWeaponc->m_fEffects.m_Value = v40;
    }
    if ( v39->m_Network.m_pPev != nullptr )
      v39->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this: pWeaponc);
    v7 = this;
  }
  if ( !v7->IsPlayer(this: v7) && (v7->m_spawnflags.m_Value & 0x100) != 0 )
  {
    v42 = v7->m_hActiveWeapon.m_Value.m_Index;
    if ( v42 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_SerialNumber != HIWORD(v42) )
      v43 = nullptr;
    else
      v43 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_pEntity;
    v43[306].__vftable = (IHandleEntity_vtbl *)1315859240;
    v44 = v7->m_hActiveWeapon.m_Value.m_Index;
    if ( v44 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_SerialNumber != HIWORD(v44) )
      v45 = nullptr;
    else
      v45 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_pEntity;
    v45[307].__vftable = (IHandleEntity_vtbl *)1315859240;
  }
  proficiencya = v7->CalcWeaponProficiency(this: v7, a2: pWeapon);
  if ( weapon_showproficiency.m_pParent != nullptr && weapon_showproficiency.m_pParent->m_Value.m_nValue != 0 )
  {
    pszValue = locale;
    pWeapond = pWeapon->m_iClassname.pszValue;
    if ( pWeapond == nullptr )
      pWeapond = locale;
    if ( v7->m_iClassname.pszValue != nullptr )
      pszValue = v7->m_iClassname.pszValue;
    WeaponProficiencyName = GetWeaponProficiencyName(proficiency: proficiencya);
    _Msg(a1: "%s equipped with %s, proficiency is %s\n", pszValue, pWeapond, WeaponProficiencyName);
  }
  v7->m_CurrentWeaponProficiency = proficiencya;
  v48 = v7->m_hLightingOriginRelative.m_Value.m_Index;
  if ( v48 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v48].m_SerialNumber != HIWORD(v48) )
    v49 = nullptr;
  else
    v49 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v48].m_pEntity;
  pWeapon->SetLightingOriginRelative(this: pWeapon, a2: v49);
}

//------------------------------------------------------------------------------
// Address: 0x100A93C0
// Name: public: virtual void CBaseCombatCharacter::RemoveAllWeapons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::RemoveAllWeapons(CBaseCombatCharacter *this)
{
  unsigned int m_Index; // eax
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> *p_m_hActiveWeapon; // ecx
  CBaseCombatWeapon **v4; // edx
  CBaseCombatWeapon *v5; // esi
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *p_m_hMyWeapons; // edi
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *v7; // ebx
  unsigned int v8; // ecx
  int v9; // eax
  CEntInfo *v10; // edx
  unsigned int v11; // ecx
  int v12; // eax
  bool v13; // zf
  CEntInfo *v14; // eax
  IHandleEntity *v15; // ecx
  CHandle<CBaseCombatWeapon> *v16; // eax
  CBaseEdict *v17; // ecx
  int v18; // [esp+Ch] [ebp-Ch]
  CBaseCombatCharacter *v19; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  m_Index = this->m_hActiveWeapon.m_Value.m_Index;
  p_m_hActiveWeapon = &this->m_hActiveWeapon;
  v19 = this;
  if ( m_Index != -1 )
  {
    v4 = (CBaseCombatWeapon **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      v5 = *v4;
      if ( *v4 != nullptr )
      {
        CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon>::Set(
          this: p_m_hActiveWeapon,
          val: nullptr);
        this->OnChangeActiveWeapon(this, a2: v5, a3: nullptr);
      }
    }
  }
  p_m_hMyWeapons = &this->m_hMyWeapons;
  i = 0;
  v7 = p_m_hMyWeapons;
  v18 = -1940 - (_DWORD)v19;
  do
  {
    v8 = v7->m_Value[0].m_Index;
    if ( v7->m_Value[0].m_Index != -1 )
    {
      v9 = (unsigned __int16)v8;
      v10 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v8];
      v11 = HIWORD(v8);
      if ( v10->m_SerialNumber == v11 && v10->m_pEntity != nullptr )
      {
        v12 = v9;
        v13 = g_pEntityList->m_EntPtrArray[v12].m_SerialNumber == v11;
        v14 = &g_pEntityList->m_EntPtrArray[v12];
        v15 = v13 ? v14->m_pEntity : nullptr;
        ((void (__thiscall *)(IHandleEntity *))v15->__vftable[118].SetRefEHandle)(a1: v15);
        if ( *(unsigned int *)((char *)&p_m_hMyWeapons->m_Value[0].m_Index + (_DWORD)v7 + v18) != -1 )
        {
          v16 = &p_m_hMyWeapons[-8].m_Value[27];
          if ( LOBYTE(p_m_hMyWeapons[-8].m_Value[48].m_Index) != 0 )
          {
            LOBYTE(v16[22].m_Index) |= 1u;
          }
          else
          {
            v17 = (CBaseEdict *)v16[6].m_Index;
            if ( v17 != nullptr )
              CBaseEdict::StateChanged(this: v17, offset: 4 * i + 1940);
          }
          *(unsigned int *)((char *)&p_m_hMyWeapons->m_Value[0].m_Index + (_DWORD)v7 + v18) = -1;
        }
      }
    }
    v7 = (CBaseCombatCharacter::NetworkVar_m_hMyWeapons *)((char *)v7 + 4);
    ++i;
  }
  while ( i < 64 );
  _V_memset(dest: v19->m_weaponIDToIndex, fill: 0, count: 42);
}

//------------------------------------------------------------------------------
// Address: 0x100A94F0
// Name: public: virtual void CBaseCombatCharacter::AddClassRelationship(enum Class_T,enum Disposition_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::AddClassRelationship(
        CBaseCombatCharacter *this,
        Class_T class_type,
        Disposition_t disposition,
        int priority)
{
  int v4; // eax
  Relationship_t *v5; // esi
  Class_T *p_classType; // edx
  int m_nAllocationCount; // eax
  CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int> > *p_m_Relationship; // esi
  int m_Size; // edi
  Relationship_t *m_pMemory; // ecx
  int v11; // eax
  int v12; // eax
  Relationship_t *v13; // ecx
  int v14; // eax

  v4 = this->m_Relationship.m_Size - 1;
  if ( v4 < 0 )
  {
LABEL_5:
    m_nAllocationCount = this->m_Relationship.m_Memory.m_nAllocationCount;
    p_m_Relationship = &this->m_Relationship;
    m_Size = this->m_Relationship.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Relationship,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_Relationship->m_Size;
    m_pMemory = p_m_Relationship->m_Memory.m_pMemory;
    v11 = p_m_Relationship->m_Size - m_Size - 1;
    p_m_Relationship->m_pElements = p_m_Relationship->m_Memory.m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v11);
    v12 = m_Size;
    v13 = &p_m_Relationship->m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      v13->entity.m_Index = -1;
    p_m_Relationship->m_Memory.m_pMemory[v12].classType = class_type;
    p_m_Relationship->m_Memory.m_pMemory[v12].entity.m_Index = -1;
    p_m_Relationship->m_Memory.m_pMemory[v12].faction = 0;
    p_m_Relationship->m_Memory.m_pMemory[v12].disposition = disposition;
    p_m_Relationship->m_Memory.m_pMemory[v12].priority = priority != 0x80000000 ? priority : 0;
  }
  else
  {
    v5 = this->m_Relationship.m_Memory.m_pMemory;
    p_classType = &v5[v4].classType;
    while ( *p_classType != class_type )
    {
      p_classType -= 5;
      if ( --v4 < 0 )
        goto LABEL_5;
    }
    v14 = v4;
    v5[v14].disposition = disposition;
    if ( priority != 0x80000000 )
      this->m_Relationship.m_Memory.m_pMemory[v14].priority = priority;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A95F0
// Name: public: virtual void CBaseCombatCharacter::AddEntityRelationship(class CBaseEntity __near *,enum Disposition_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::AddEntityRelationship(
        CBaseCombatCharacter *this,
        CBaseEntity *pEntity,
        Disposition_t disposition,
        int priority)
{
  int v4; // esi
  Relationship_t *v5; // edi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int> > *p_m_Relationship; // esi
  Relationship_t *m_pMemory; // ecx
  int v12; // eax
  int v13; // edi
  Relationship_t *v14; // eax
  Relationship_t *v15; // ebx

  v4 = this->m_Relationship.m_Size - 1;
  if ( v4 < 0 )
  {
LABEL_9:
    m_Size = this->m_Relationship.m_Size;
    m_nAllocationCount = this->m_Relationship.m_Memory.m_nAllocationCount;
    p_m_Relationship = &this->m_Relationship;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Relationship,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_Relationship->m_Size;
    m_pMemory = p_m_Relationship->m_Memory.m_pMemory;
    v12 = p_m_Relationship->m_Size - m_Size - 1;
    p_m_Relationship->m_pElements = p_m_Relationship->m_Memory.m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v12);
    v13 = m_Size;
    v14 = &p_m_Relationship->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      v14->entity.m_Index = -1;
    p_m_Relationship->m_Memory.m_pMemory[v13].classType = CLASS_NONE;
    v15 = p_m_Relationship->m_Memory.m_pMemory;
    if ( pEntity != nullptr )
      v15[v13].entity.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    else
      v15[v13].entity.m_Index = -1;
    p_m_Relationship->m_Memory.m_pMemory[v13].faction = 0;
    p_m_Relationship->m_Memory.m_pMemory[v13].disposition = disposition;
    p_m_Relationship->m_Memory.m_pMemory[v13].priority = priority != 0x80000000 ? priority : 0;
  }
  else
  {
    v5 = &this->m_Relationship.m_Memory.m_pMemory[v4];
    while ( 1 )
    {
      m_Index = v5->entity.m_Index;
      if ( v5->entity.m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( m_pEntity == pEntity )
        break;
      --v5;
      if ( --v4 < 0 )
        goto LABEL_9;
    }
    this->m_Relationship.m_Memory.m_pMemory[v4].disposition = disposition;
    if ( priority != 0x80000000 )
      this->m_Relationship.m_Memory.m_pMemory[v4].priority = priority;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9740
// Name: public: virtual void CBaseCombatCharacter::AddFactionRelationship(int,enum Disposition_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::AddFactionRelationship(
        CBaseCombatCharacter *this,
        int nFaction,
        Disposition_t disposition,
        int priority)
{
  int v4; // eax
  Relationship_t *v5; // esi
  int *p_faction; // edx
  int m_nAllocationCount; // eax
  CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int> > *p_m_Relationship; // esi
  int m_Size; // edi
  Relationship_t *m_pMemory; // ecx
  int v11; // eax
  int v12; // eax
  Relationship_t *v13; // ecx
  int v14; // eax

  v4 = this->m_Relationship.m_Size - 1;
  if ( v4 < 0 )
  {
LABEL_5:
    m_nAllocationCount = this->m_Relationship.m_Memory.m_nAllocationCount;
    p_m_Relationship = &this->m_Relationship;
    m_Size = this->m_Relationship.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Relationship,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_Relationship->m_Size;
    m_pMemory = p_m_Relationship->m_Memory.m_pMemory;
    v11 = p_m_Relationship->m_Size - m_Size - 1;
    p_m_Relationship->m_pElements = p_m_Relationship->m_Memory.m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v11);
    v12 = m_Size;
    v13 = &p_m_Relationship->m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      v13->entity.m_Index = -1;
    p_m_Relationship->m_Memory.m_pMemory[v12].classType = CLASS_NONE;
    p_m_Relationship->m_Memory.m_pMemory[v12].entity.m_Index = -1;
    p_m_Relationship->m_Memory.m_pMemory[v12].faction = nFaction;
    p_m_Relationship->m_Memory.m_pMemory[v12].disposition = disposition;
    p_m_Relationship->m_Memory.m_pMemory[v12].priority = priority != 0x80000000 ? priority : 0;
  }
  else
  {
    v5 = this->m_Relationship.m_Memory.m_pMemory;
    p_faction = &v5[v4].faction;
    while ( *p_faction != nFaction )
    {
      p_faction -= 5;
      if ( --v4 < 0 )
        goto LABEL_5;
    }
    v14 = v4;
    v5[v14].disposition = disposition;
    if ( priority != 0x80000000 )
      this->m_Relationship.m_Memory.m_pMemory[v14].priority = priority;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9840
// Name: public: void CBaseCombatCharacter::OnFogTriggerStartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::OnFogTriggerStartTouch(CBaseCombatCharacter *this, CBaseEntity *fogTrigger)
{
  unsigned int m_Index; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CHandle<CBaseEntity> *m_pMemory; // eax
  int v7; // ecx
  CHandle<CBaseEntity> *v8; // esi

  if ( fogTrigger != nullptr )
    m_Index = fogTrigger->GetRefEHandle(this: fogTrigger)->m_Index;
  else
    m_Index = -1;
  m_Size = this->m_hTriggerFogList.m_Size;
  m_nAllocationCount = this->m_hTriggerFogList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hTriggerFogList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_hTriggerFogList.m_Size;
  m_pMemory = this->m_hTriggerFogList.m_Memory.m_pMemory;
  v7 = this->m_hTriggerFogList.m_Size - 1;
  this->m_hTriggerFogList.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[1], src: m_pMemory, count: 4 * v7);
  v8 = this->m_hTriggerFogList.m_Memory.m_pMemory;
  if ( v8 != nullptr )
    v8->m_Index = m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x100AA450
// Name: public: virtual bool CBaseCombatCharacter::FVisible(class CBaseEntity __near *,int,class CBaseEntity __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatCharacter::FVisible(
        CBaseCombatCharacter *this,
        CBaseCombatCharacter *pEntity,
        CBaseEntity *traceMask,
        CBaseEntity **ppBlocker)
{
  CBaseCombatCharacter *v5; // ebx
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // si
  UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short> *v8; // eax
  bool v9; // bl
  CBaseEntity **v10; // esi
  CBaseEntity *v11; // eax
  char result; // al
  CBaseEntity **p_traceMask; // ebx
  int v14; // esi
  VisibilityCacheEntry_t cacheEntry; // [esp+8h] [ebp-10h] BYREF

  if ( traceMask != (CBaseEntity *)16449
    || ai_use_visibility_cache.m_pParent == nullptr
    || ai_use_visibility_cache.m_pParent->m_Value.m_nValue == 0 )
  {
    v5 = pEntity;
    return CBaseEntity::FVisible(this, pEntity: v5, (unsigned int)traceMask, ppBlocker);
  }
  v5 = pEntity;
  if ( this == pEntity )
    return CBaseEntity::FVisible(this, pEntity: v5, (unsigned int)traceMask, ppBlocker);
  cacheEntry.pBlocker.m_Index = -1;
  if ( this >= pEntity )
  {
    cacheEntry.pEntity1 = pEntity;
    cacheEntry.pEntity2 = this;
  }
  else
  {
    cacheEntry.pEntity1 = this;
    cacheEntry.pEntity2 = pEntity;
  }
  v6 = CUtlRBTree<VisibilityCacheEntry_t,unsigned short,CVisibilityCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short>,unsigned short>>::Find(
         this: &g_VisibilityCache,
         search: &cacheEntry);
  v7 = v6;
  if ( v6 == 0xFFFF )
  {
    if ( g_VisibilityCache.m_NumElements == 0xFFFF )
      return CBaseEntity::FVisible(this, pEntity, traceMask: 0x4041u, ppBlocker);
    v7 = CUtlRBTree<VisibilityCacheEntry_t,unsigned short,CVisibilityCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short>,unsigned short>>::Insert(
           this: &g_VisibilityCache,
           a2: (const char *)this,
           insert: &cacheEntry);
    goto LABEL_19;
  }
  v8 = &g_VisibilityCache.m_Elements.m_pMemory[v6];
  if ( (float)(gpGlobals->curtime - v8->m_Data.time) >= 0.090000004 )
  {
LABEL_19:
    p_traceMask = ppBlocker;
    traceMask = nullptr;
    if ( ppBlocker == nullptr )
      p_traceMask = &traceMask;
    result = CBaseEntity::FVisible(this, pEntity, traceMask: 0x4041u, ppBlocker: p_traceMask);
    HIBYTE(ppBlocker) = result;
    v14 = v7;
    if ( result != 0 )
    {
      g_VisibilityCache.m_Elements.m_pMemory[v14].m_Data.pBlocker.m_Index = -1;
    }
    else
    {
      CHandle<CBaseEntity>::operator=(
        this: &g_VisibilityCache.m_Elements.m_pMemory[v14].m_Data.pBlocker,
        val: *p_traceMask);
      result = HIBYTE(ppBlocker);
    }
    g_VisibilityCache.m_Elements.m_pMemory[v14].m_Data.time = gpGlobals->curtime;
    return result;
  }
  v9 = v8->m_Data.pBlocker.m_Index != -1;
  if ( v8->m_Data.pBlocker.m_Index == -1 )
  {
    if ( ppBlocker != nullptr )
      *ppBlocker = nullptr;
  }
  else
  {
    v10 = ppBlocker;
    if ( ppBlocker != nullptr )
    {
      v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v8->m_Data.pBlocker);
      *v10 = v11;
      if ( v11 == nullptr )
      {
        *v10 = GetWorldEntity();
        return !v9;
      }
    }
  }
  return !v9;
}

//------------------------------------------------------------------------------
// Address: 0x100AA620
// Name: public: static void CBaseCombatCharacter::ResetVisibilityCache(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseCombatCharacter::ResetVisibilityCache(CBaseCombatCharacter *pBCC)
{
  int m_Size; // edi
  unsigned __int16 Inorder; // bx
  unsigned __int16 *m_pMemory; // ecx
  int m_nAllocationCount; // edx
  UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short> *v5; // eax
  int v6; // esi
  unsigned __int16 *v7; // esi
  unsigned __int16 v8; // ax
  int i; // ebx
  int v10; // esi
  int v11; // eax
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > removals; // [esp+4h] [ebp-14h] BYREF

  m_Size = 0;
  if ( pBCC != nullptr )
  {
    Inorder = CUtlRBTree<VisibilityCacheEntry_t,unsigned short,CVisibilityCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short>,unsigned short>>::FirstInorder(this: &g_VisibilityCache);
    m_pMemory = nullptr;
    m_nAllocationCount = 0;
    memset(&removals, 0, sizeof(removals));
    if ( Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        v5 = &g_VisibilityCache.m_Elements.m_pMemory[Inorder];
        if ( v5->m_Data.pEntity1 == pBCC || v5->m_Data.pEntity2 == pBCC )
        {
          v6 = m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
          {
            CUtlMemory<wchar_t,int>::Grow(
              this: (CUtlMemory<wchar_t,int> *)&removals,
              num: m_Size - m_nAllocationCount + 1);
            m_Size = removals.m_Size;
            m_pMemory = removals.m_Memory.m_pMemory;
          }
          removals.m_Size = ++m_Size;
          removals.m_pElements = m_pMemory;
          if ( m_Size - v6 - 1 > 0 )
          {
            _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 2 * (m_Size - v6 - 1));
            m_pMemory = removals.m_Memory.m_pMemory;
          }
          v7 = &m_pMemory[v6];
          if ( v7 != nullptr )
            *v7 = Inorder;
        }
        v8 = CUtlRBTree<VisibilityCacheEntry_t,unsigned short,CVisibilityCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short>,unsigned short>>::NextInorder(
               this: &g_VisibilityCache,
               i: Inorder);
        m_pMemory = removals.m_Memory.m_pMemory;
        Inorder = v8;
        if ( v8 == 0xFFFF )
          break;
        m_nAllocationCount = removals.m_Memory.m_nAllocationCount;
      }
    }
    for ( i = 0; i < m_Size; ++i )
    {
      v10 = m_pMemory[i];
      if ( (_WORD)v10 != 0xFFFF )
      {
        CUtlRBTree<VisibilityCacheEntry_t,unsigned short,CVisibilityCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short>,unsigned short>>::Unlink(
          this: &g_VisibilityCache,
          elem: m_pMemory[i]);
        v11 = v10;
        g_VisibilityCache.m_Elements.m_pMemory[v11].m_Left = v10;
        g_VisibilityCache.m_Elements.m_pMemory[v11].m_Right = g_VisibilityCache.m_FirstFree;
        m_pMemory = removals.m_Memory.m_pMemory;
        --g_VisibilityCache.m_NumElements;
        g_VisibilityCache.m_FirstFree = v10;
      }
    }
    if ( removals.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else
  {
    CUtlRBTree<VisibilityCacheEntry_t,unsigned short,CVisibilityCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short>,unsigned short>>::RemoveAll(this: &g_VisibilityCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA780
// Name: public: virtual CBaseCombatCharacter::~CBaseCombatCharacter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::~CBaseCombatCharacter(CBaseCombatCharacter *this)
{
  bool v2; // zf
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *v3; // esi
  int v4; // eax
  int m_Size; // edx
  CHandle<CBaseEntity> src; // [esp+4h] [ebp-4h] BYREF

  v2 = this->m_nFaction == 0;
  this->__vftable = (CBaseCombatCharacter_vtbl *)&CBaseCombatCharacter::`vftable';
  if ( !v2 && CBaseCombatCharacter::m_aFactions.m_Size != 0 )
  {
    src.m_Index = CBaseEntity::GetRefEHandle(this)->m_Index;
    v3 = &CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory[this->m_nFaction];
    v4 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(this: v3, &src);
    if ( v4 != -1 )
    {
      m_Size = v3->m_Size;
      if ( m_Size > 0 )
      {
        if ( v4 != m_Size - 1 )
          v3->m_Memory.m_pMemory[v4].m_Index = v3->m_Memory.m_pMemory[m_Size - 1].m_Index;
        --v3->m_Size;
      }
    }
  }
  CBaseCombatCharacter::ResetVisibilityCache(pBCC: this);
  CBaseCombatCharacter::ClearLastKnownArea(this);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hTriggerFogList);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Relationship);
  CBaseFlex::~CBaseFlex(this);
}

//------------------------------------------------------------------------------
// Address: 0x100AA820
// Name: public: virtual void CBaseCombatCharacter::FixupBurningServerRagdoll(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::FixupBurningServerRagdoll(CBaseCombatCharacter *this, CBaseEntity *pRagdoll)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CEntityFlame *v5; // esi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  if ( (this->m_fFlags.m_Value & 0x10000000) != 0 )
  {
    m_Index = this->m_hEffectEntity.m_Value.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v5 = (CEntityFlame *)__RTDynamicCast(
                           inptr: m_pEntity,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CEntityFlame `RTTI Type Descriptor',
                           isReference: 0);
    if ( v5 != nullptr )
    {
      CBaseEntity::SetEffectEntity(this, pEffectEnt: nullptr);
      CBaseEntity::AddFlag(this: pRagdoll, flags: 0x10000000);
      if ( (pRagdoll->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pRagdoll, a2: (int)&savedregs);
      CBaseEntity::SetAbsOrigin(this: v5, absOrigin: &pRagdoll->m_vecAbsOrigin);
      CEntityFlame::AttachToEntity(this: v5, pTarget: pRagdoll);
      v5->m_iEFlags |= 0x80u;
      CBaseEntity::DispatchUpdateTransmitState(this: v5);
      CBaseEntity::SetEffectEntity(this: pRagdoll, pEffectEnt: v5);
      CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
        this: &pRagdoll->m_clrRender,
        rVal: this->m_clrRender.m_Value.r,
        gVal: this->m_clrRender.m_Value.g,
        bVal: this->m_clrRender.m_Value.b);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA950
// Name: public: virtual void CCleanupDefaultRelationShips::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCleanupDefaultRelationShips::Shutdown(CCleanupDefaultRelationShips *this)
{
  int v1; // ebx
  int v2; // edi
  int i; // esi
  int j; // edi
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *v5; // esi
  bool v6; // sf
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *m_pMemory; // eax

  v1 = 0;
  if ( CBaseCombatCharacter::m_DefaultRelationship != nullptr )
  {
    if ( g_pGameRules != nullptr )
      v2 = g_pGameRules->NumEntityClasses(this: g_pGameRules);
    else
      v2 = 27;
    for ( i = 0; i < v2; ++i )
      free(pMem: CBaseCombatCharacter::m_DefaultRelationship[i]);
    free(pMem: CBaseCombatCharacter::m_DefaultRelationship);
    CBaseCombatCharacter::m_DefaultRelationship = nullptr;
  }
  if ( CBaseCombatCharacter::m_FactionRelationship != nullptr )
  {
    for ( j = 0; j < CBaseCombatCharacter::m_aFactions.m_Size; ++v1 )
    {
      free(pMem: CBaseCombatCharacter::m_FactionRelationship[j]);
      v5 = &CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory[v1];
      v6 = CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory[v1].m_Memory.m_nGrowSize < 0;
      CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory[v1].m_Size = 0;
      if ( !v6 )
      {
        if ( v5->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Memory.m_pMemory);
          v5->m_Memory.m_pMemory = nullptr;
        }
        v5->m_Memory.m_nAllocationCount = 0;
      }
      ++j;
      v5->m_pElements = v5->m_Memory.m_pMemory;
    }
    CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&CBaseCombatCharacter::m_aFactions);
    m_pMemory = CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory;
    if ( CBaseCombatCharacter::m_aFactions.m_Memory.m_nGrowSize >= 0 )
    {
      if ( CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory = nullptr;
      }
      CBaseCombatCharacter::m_aFactions.m_Memory.m_nAllocationCount = 0;
    }
    CBaseCombatCharacter::m_aFactions.m_pElements = m_pMemory;
    free(pMem: CBaseCombatCharacter::m_FactionRelationship);
    CBaseCombatCharacter::m_FactionRelationship = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AAA80
// Name: public: static void CBaseCombatCharacter::AllocateDefaultFactionRelationships(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CBaseCombatCharacter::AllocateDefaultFactionRelationships()
{
  int v0; // esi
  int v1; // edi
  Relationship_t *v2; // eax
  int v3; // edx
  Relationship_t *v4; // ecx

  if ( CBaseCombatCharacter::m_FactionRelationship == nullptr )
  {
    v0 = g_pGameRules != nullptr ? g_pGameRules->NumFactions(this: g_pGameRules) : 1;
    CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&CBaseCombatCharacter::m_aFactions);
    CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&CBaseCombatCharacter::m_aFactions,
      elem: CBaseCombatCharacter::m_aFactions.m_Size,
      num: v0);
    v1 = 0;
    for ( CBaseCombatCharacter::m_FactionRelationship = (Relationship_t **)operator new(nSize: 4 * v0); v1 < v0; ++v1 )
    {
      v2 = (Relationship_t *)operator new(nSize: 20 * v0);
      if ( v2 != nullptr )
      {
        v3 = v0 - 1;
        v4 = v2;
        do
        {
          v4->entity.m_Index = -1;
          ++v4;
          --v3;
        }
        while ( v3 >= 0 );
      }
      else
      {
        v2 = nullptr;
      }
      CBaseCombatCharacter::m_FactionRelationship[v1] = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AAB50
// Name: public: virtual void CBaseCombatCharacter::ChangeFaction(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::ChangeFaction(CBaseCombatCharacter *this, int nNewFaction)
{
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *v3; // esi
  int v4; // eax
  int m_Size; // edx
  int v6; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *v8; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v10; // eax
  unsigned int *v11; // edi
  int v12; // esi
  Relationship_t *v13; // edx
  unsigned int m_Index; // eax
  unsigned int v15; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v17; // eax
  IHandleEntity *v18; // ecx
  int v19; // eax
  int m_nFaction; // [esp+Ch] [ebp-8h]
  CHandle<CBaseEntity> src; // [esp+10h] [ebp-4h] BYREF
  unsigned int i; // [esp+1Ch] [ebp+8h]
  int ia; // [esp+1Ch] [ebp+8h]

  m_nFaction = this->m_nFaction;
  if ( m_nFaction != 0 && CBaseCombatCharacter::m_aFactions.m_Size != 0 )
  {
    src.m_Index = this->GetRefEHandle(this)->m_Index;
    v3 = &CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory[this->m_nFaction];
    v4 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(this: v3, &src);
    if ( v4 != -1 )
    {
      m_Size = v3->m_Size;
      if ( m_Size > 0 )
      {
        if ( v4 != m_Size - 1 )
          v3->m_Memory.m_pMemory[v4].m_Index = v3->m_Memory.m_pMemory[m_Size - 1].m_Index;
        --v3->m_Size;
      }
    }
  }
  this->m_nFaction = nNewFaction;
  if ( nNewFaction != 0 )
  {
    if ( CBaseCombatCharacter::m_aFactions.m_Size == 0 )
      CBaseCombatCharacter::AllocateDefaultFactionRelationships();
    i = this->GetRefEHandle(this)->m_Index;
    v6 = CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory[this->m_nFaction].m_Size;
    m_nAllocationCount = CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory[this->m_nFaction].m_Memory.m_nAllocationCount;
    v8 = (CUtlMemory<vgui::TreeNode *,int> *)&CBaseCombatCharacter::m_aFactions.m_Memory.m_pMemory[this->m_nFaction];
    if ( v6 + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: v8, num: v6 - m_nAllocationCount + 1);
    ++v8[1].m_pMemory;
    m_pMemory = v8->m_pMemory;
    v10 = (int)v8[1].m_pMemory - v6 - 1;
    v8[1].m_nAllocationCount = (int)v8->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v10);
    v11 = (unsigned int *)&v8->m_pMemory[v6];
    if ( v11 != nullptr )
      *v11 = i;
  }
  v12 = 0;
  if ( CBaseCombatCharacter::m_FactionRelationship != nullptr && this->m_nFaction != 0 )
  {
    for ( ia = 0; ia < this->m_Relationship.m_Size; ++ia )
    {
      v13 = &this->m_Relationship.m_Memory.m_pMemory[v12];
      m_Index = v13->entity.m_Index;
      if ( v13->entity.m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        v15 = v13->entity.m_Index;
        if ( v13->entity.m_Index == -1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
        {
          m_pEntity = nullptr;
        }
        else
        {
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
        }
        if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[24].SetRefEHandle)(a1: m_pEntity) != 0 )
        {
          v17 = this->m_Relationship.m_Memory.m_pMemory[v12].entity.m_Index;
          if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
            v18 = nullptr;
          else
            v18 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
          v19 = (int)v18->__vftable[24].GetRefEHandle(this: v18);
          if ( CBaseCombatCharacter::m_FactionRelationship[this->m_nFaction][*(_DWORD *)(v19 + 1784)].disposition != CBaseCombatCharacter::m_FactionRelationship[m_nFaction][*(_DWORD *)(v19 + 1784)].disposition )
          {
            CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int>>::FastRemove(
              this: &this->m_Relationship,
              elem: ia--);
            --v12;
          }
        }
      }
      ++v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EB450
// Name: public: virtual enum TraceType_t CTraceFilterEntitiesOnly::GetTraceType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTraceFilterEntitiesOnly::GetTraceType(CTraceFilterEntitiesOnly *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x103FF440
// Name: CBaseCombatCharacter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseCombatCharacter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseCombatCharacter>();
  CBaseCombatCharacter_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF450
// Name: Relationship_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *Relationship_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<Relationship_t>();
  Relationship_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF4B0
// Name: DT_BCCLocalPlayerExclusive::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BCCLocalPlayerExclusive::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BCCLocalPlayerExclusive::g_SendTable);
  return atexit(func: DT_BCCLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF4D0
// Name: DT_BCCLocalPlayerExclusive::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BCCLocalPlayerExclusive::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BCCLocalPlayerExclusive::ignored>();
  DT_BCCLocalPlayerExclusive::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF500
// Name: DT_BaseCombatCharacter::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCombatCharacter::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseCombatCharacter::g_SendTable);
  return atexit(func: DT_BaseCombatCharacter::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF520
// Name: DT_BaseCombatCharacter::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCombatCharacter::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseCombatCharacter::ignored>();
  DT_BaseCombatCharacter::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419810
// Name: DT_BCCLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BCCLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BCCLocalPlayerExclusive::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419820
// Name: DT_BaseCombatCharacter::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseCombatCharacter::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseCombatCharacter::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FF4E0
// Name: _dynamic_initializer_for__g_CBaseCombatCharacter_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseCombatCharacter_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseCombatCharacter_ClassReg,
           pNetworkName: "CBaseCombatCharacter",
           pTable: &DT_BaseCombatCharacter::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FF530
// Name: _dynamic_initializer_for__g_VisibilityCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VisibilityCache__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VisibilityCache__);
}

//------------------------------------------------------------------------------
// Address: 0x10419830
// Name: _ServerClassInit_DT_BaseCombatCharacter::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseCombatCharacter::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S5_6;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
