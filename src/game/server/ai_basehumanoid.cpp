// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_basehumanoid.cpp
// Functions: 25
// ============================================================

#include "game\server\ai_basehumanoid.h"

//------------------------------------------------------------------------------
// Address: 0x10011980
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near * __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char **ppszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  const char **v3; // eax
  bool v4; // zf
  const char *v6; // [esp-Ch] [ebp-14h]
  char *v7; // [esp-8h] [ebp-10h]

  v2 = this;
  v3 = ppszFormat;
  v7 = (char *)(ppszFormat + 1);
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  v6 = *v3;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v2->m_szBuf, maxLen: 255, pFormat: v6, params: v7, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100179A0
// Name: public: bool Vector::operator!=(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Vector::operator!=(Vector *this, const Vector *src)
{
  return src->x != this->x || src->y != this->y || src->z != this->z;
}

//------------------------------------------------------------------------------
// Address: 0x100179E0
// Name: public: virtual bool CAI_BaseHumanoid::HandleInteraction(int,void __near *,class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseHumanoid::HandleInteraction(
        CAI_BaseHumanoid *this,
        int interactionType,
        vgui::Menu *data,
        vgui::Menu *sourceEnt)
{
  return CAI_BaseNPC::HandleInteraction(this, interactionType, data, sourceEnt);
}

//------------------------------------------------------------------------------
// Address: 0x100179F0
// Name: public: void CBaseEntity::SetNavIgnore(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetNavIgnore(CBaseEntity *this, float duration)
{
  float v2; // xmm0_4

  v2 = 3.4028235e38;
  if ( duration != 3.4028235e38 )
    v2 = gpGlobals->curtime + duration;
  if ( v2 > this->m_flNavIgnoreUntilTime )
    this->m_flNavIgnoreUntilTime = v2;
}

//------------------------------------------------------------------------------
// Address: 0x10017A30
// Name: public: bool CBaseEntity::IsNavIgnored(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseEntity::IsNavIgnored(CBaseEntity *this)
{
  return this->m_flNavIgnoreUntilTime >= gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10017A50
// Name: public: class CBaseEntity __near * CAI_Navigator::GetBlockingEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_Navigator::GetBlockingEntity(CAI_Navigator *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hLastBlockingEnt.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10017A80
// Name: IsSmall
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsSmall@<al>(CBaseEntity *pBlocker@<eax>)
{
  int v2; // ebx
  const Vector *v3; // edi
  const Vector *v4; // eax
  int v5; // eax
  float v6; // xmm0_4
  Vector vecSize; // [esp+Ch] [ebp-Ch]

  v2 = 0;
  v3 = pBlocker->m_Collision.OBBMins(this: &pBlocker->m_Collision);
  v4 = pBlocker->m_Collision.OBBMaxs(this: &pBlocker->m_Collision);
  vecSize.x = v4->x - v3->x;
  vecSize.y = v4->y - v3->y;
  vecSize.z = v4->z - v3->z;
  v5 = 0;
  while ( 1 )
  {
    v6 = *(&vecSize.x + v5);
    if ( v6 >= 42.0 )
      break;
    if ( v6 <= 30.0 )
      ++v2;
    if ( ++v5 >= 3 )
      return v2 >= 2;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10017BB0
// Name: public: virtual void CAI_BaseHumanoid::StartTaskRangeAttack1(struct Task_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseHumanoid::StartTaskRangeAttack1(CAI_BaseHumanoid *this, const Task_t *pTask)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // esi
  void (__thiscall *StartTask)(CAI_BehaviorBase *, const Task_t *); // edx

  if ( (this->CapabilitiesGet(this) & 0x1000000) != 0 )
  {
    if ( CAI_ShotRegulator::IsInRestInterval(this: &this->m_ShotRegulator) )
    {
      this->TaskFail(this, a2: (int)"Shot regulator in rest interval");
    }
    else if ( CAI_ShotRegulator::ShouldShoot(this: &this->m_ShotRegulator) )
    {
      this->OnRangeAttack1(this);
      CAI_BaseNPC::ResetIdealActivity(this, newIdealActivity: ACT_RANGE_ATTACK1);
    }
    else
    {
      CAI_BaseNPC::ResetIdealActivity(this, newIdealActivity: ACT_IDLE_ANGRY);
    }
  }
  else
  {
    m_pPrimaryBehavior = this->m_pPrimaryBehavior;
    if ( m_pPrimaryBehavior == nullptr
      || (StartTask = m_pPrimaryBehavior->StartTask,
          m_pPrimaryBehavior->m_fOverrode = true,
          StartTask(this: m_pPrimaryBehavior, a2: pTask),
          !m_pPrimaryBehavior->m_fOverrode) )
    {
      CAI_BaseNPC::StartTask(this, pTask);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017C60
// Name: public: virtual void CAI_BaseHumanoid::StartTask(struct Task_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseHumanoid::StartTask(CAI_BaseHumanoid *this, const Task_t *pTask)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // esi
  void (__thiscall *StartTask)(CAI_BehaviorBase *, const Task_t *); // edx

  if ( pTask->iTask == 75 )
  {
    this->StartTaskRangeAttack1(this, a2: pTask);
  }
  else
  {
    m_pPrimaryBehavior = this->m_pPrimaryBehavior;
    if ( m_pPrimaryBehavior == nullptr
      || (StartTask = m_pPrimaryBehavior->StartTask,
          m_pPrimaryBehavior->m_fOverrode = true,
          StartTask(this: m_pPrimaryBehavior, a2: pTask),
          !m_pPrimaryBehavior->m_fOverrode) )
    {
      CAI_BaseNPC::StartTask(this, pTask);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017CC0
// Name: public: virtual void CAI_BaseHumanoid::RunTaskRangeAttack1(struct Task_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseHumanoid::RunTaskRangeAttack1(CAI_BaseHumanoid *this, const Task_t *pTask)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // edi
  void (__thiscall *RunTask)(CAI_BehaviorBase *, const Task_t *); // edx
  CBaseEntity *v5; // eax
  Vector vecEnemyLKP; // [esp+14h] [ebp-Ch] BYREF

  if ( (this->CapabilitiesGet(this) & 0x1000000) != 0 )
  {
    CAI_BaseNPC::AutoMovement(this, pTarget: nullptr, pTraceResult: nullptr);
    vecEnemyLKP = *this->GetEnemyLKP(this);
    if ( vec3_origin.x != vecEnemyLKP.x || vec3_origin.y != vecEnemyLKP.y || vec3_origin.z != vecEnemyLKP.z )
    {
      if ( (pTask->iTask == 75 || pTask->iTask == 79)
        && (this->CapabilitiesGet(this) & 0x20000000) != 0
        && this->FInAimCone(this, a2: &vecEnemyLKP) )
      {
        CAI_Motor::SetIdealYawAndUpdate(this: this->m_pMotor, idealYaw: this->m_pMotor->m_IdealYaw, yawSpeed: -2.0);
      }
      else
      {
        CAI_Motor::SetIdealYawToTargetAndUpdate(this: this->m_pMotor, target: &vecEnemyLKP, yawSpeed: -2.0);
      }
    }
    if ( this->IsActivityFinished(this) )
    {
      if ( this->GetEnemy_2(this) != nullptr
        && (v5 = this->GetEnemy_2(this), v5->IsAlive(this: v5))
        && !CAI_ShotRegulator::IsInRestInterval(this: &this->m_ShotRegulator) )
      {
        if ( CAI_ShotRegulator::ShouldShoot(this: &this->m_ShotRegulator) )
        {
          this->OnRangeAttack1(this);
          CAI_BaseNPC::ResetIdealActivity(this, newIdealActivity: ACT_RANGE_ATTACK1);
        }
      }
      else
      {
        CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      }
    }
  }
  else
  {
    m_pPrimaryBehavior = this->m_pPrimaryBehavior;
    if ( m_pPrimaryBehavior == nullptr
      || (RunTask = m_pPrimaryBehavior->RunTask,
          m_pPrimaryBehavior->m_fOverrode = true,
          RunTask(this: m_pPrimaryBehavior, a2: pTask),
          !m_pPrimaryBehavior->m_fOverrode) )
    {
      CAI_BaseNPC::RunTask(this, pTask);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017E80
// Name: public: virtual void CAI_BaseHumanoid::RunTask(struct Task_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseHumanoid::RunTask(CAI_BaseHumanoid *this, const Task_t *pTask)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // esi
  void (__thiscall *RunTask)(CAI_BehaviorBase *, const Task_t *); // edx

  if ( pTask->iTask == 75 )
  {
    this->RunTaskRangeAttack1(this, a2: pTask);
  }
  else
  {
    m_pPrimaryBehavior = this->m_pPrimaryBehavior;
    if ( m_pPrimaryBehavior == nullptr
      || (RunTask = m_pPrimaryBehavior->RunTask,
          m_pPrimaryBehavior->m_fOverrode = true,
          RunTask(this: m_pPrimaryBehavior, a2: pTask),
          !m_pPrimaryBehavior->m_fOverrode) )
    {
      CAI_BaseNPC::RunTask(this, pTask);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017EE0
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10017F50
// Name: public: class CBaseEntity __near * CTakeDamageInfo::GetAttacker(void)const
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CTakeDamageInfo::GetAttacker(CTakeDamageInfo *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hAttacker.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10017F80
// Name: public: int CBaseEntity::GetHealth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::GetHealth(CBaseEntity *this)
{
  return this->m_iHealth.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10017F90
// Name: public: virtual void CAI_BaseHumanoid::CheckAmmo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseHumanoid::CheckAmmo(CAI_BaseHumanoid *this)
{
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseCombatWeapon *v3; // eax
  CBaseCombatWeapon *v4; // eax
  CBaseCombatWeapon *v5; // edi
  int m_Value; // ebx
  CBaseCombatWeapon *v7; // eax
  CBaseCombatWeapon *v8; // eax

  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr && !CAI_BaseNPC::IsWeaponStateChanging(this) )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( CBaseCombatWeapon::UsesPrimaryAmmo(this: ActiveWeapon) )
    {
      v3 = CBaseCombatCharacter::GetActiveWeapon(this);
      if ( v3->HasPrimaryAmmo(this: v3) )
      {
        v4 = CBaseCombatCharacter::GetActiveWeapon(this);
        if ( v4->UsesClipsForAmmo1(this: v4) )
        {
          v5 = CBaseCombatCharacter::GetActiveWeapon(this);
          m_Value = CBaseCombatCharacter::GetActiveWeapon(this)->m_iClip1.m_Value;
          if ( m_Value < v5->GetMaxClip1(this: v5) / 4 + 1 )
            CAI_BaseNPC::SetCondition(this, iCondition: 3);
        }
      }
      else
      {
        CAI_BaseNPC::SetCondition(this, iCondition: 4);
      }
    }
    v7 = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( !v7->HasSecondaryAmmo(this: v7) )
    {
      v8 = CBaseCombatCharacter::GetActiveWeapon(this);
      if ( v8->UsesClipsForAmmo2(this: v8) )
        CAI_BaseNPC::SetCondition(this, iCondition: 5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018070
// Name: public: virtual bool CAI_BaseHumanoid::OnMoveBlocked(enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseHumanoid::OnMoveBlocked(CAI_BaseHumanoid *this, AIMoveResult_t *pResult)
{
  float y; // esi
  unsigned int v4; // eax
  unsigned int v5; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *BlockingEntity; // eax
  int v8; // edx
  CAI_BaseNPC *v9; // edi
  CBaseEntity *v10; // esi
  double v11; // xmm0_8
  IPhysicsObject *m_pPhysicsObject; // ecx
  const char *DebugName; // eax
  CFmtStrN<256> *v14; // eax
  CFmtStrN<256> *v15; // eax
  CFmtStrN<256> v17; // [esp+Ch] [ebp-218h] BYREF
  CFmtStrN<256> v18; // [esp+118h] [ebp-10Ch] BYREF
  float massBonus; // [esp+22Ch] [ebp+8h]

  if ( *pResult != AIMR_BLOCKED_NPC )
  {
    y = this->m_vecVelocity.m_Value.y;
    v4 = *(_DWORD *)(LODWORD(y) + 128);
    if ( v4 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == HIWORD(v4)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity != nullptr )
    {
      v5 = *(_DWORD *)(LODWORD(y) + 128);
      if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[24].SetRefEHandle)(a1: m_pEntity) == 0 )
      {
        BlockingEntity = CAI_Navigator::GetBlockingEntity(this: (CAI_Navigator *)LODWORD(this->m_vecVelocity.m_Value.y));
        v8 = *((_DWORD *)this - 571);
        v9 = (CAI_BaseHumanoid *)((char *)this - 2284);
        v10 = BlockingEntity;
        v11 = (*(unsigned __int8 (__thiscall **)(CAI_BaseNPC *))(v8 + 1920))(a1: v9) != 0 ? 40.0 : 0.0;
        massBonus = v11;
        if ( v10->m_MoveType.m_Value == 6
          && v10 != CBaseEntity::GetGroundEntity(this: v9)
          && !CBaseEntity::IsNavIgnored(this: v10)
          && __RTDynamicCast(
               inptr: v10,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CBasePropDoor `RTTI Type Descriptor',
               isReference: 0) == nullptr )
        {
          m_pPhysicsObject = v10->m_pPhysicsObject;
          if ( m_pPhysicsObject != nullptr
            && m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject)
            && (massBonus + 35.0 + 0.1 >= ((double (__thiscall *)(IPhysicsObject *))v10->m_pPhysicsObject->GetMass)(a1: v10->m_pPhysicsObject)
             || massBonus + 50.0 + 0.1 >= ((double (__thiscall *)(IPhysicsObject *))v10->m_pPhysicsObject->GetMass)(a1: v10->m_pPhysicsObject)
             && IsSmall(pBlocker: v10)) )
          {
            if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
            {
              DebugName = CBaseEntity::GetDebugName(this: v10);
              v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v18, pszFormat: "Setting ignore on object %s", DebugName);
              v15 = CFmtStrN<256>::CFmtStrN<256>(this: &v17, pszFormat: "[Nav] %s", v14->m_szBuf);
              DevMsg(pAI: v9, pszFormat: v15->m_szBuf);
            }
            CBaseEntity::SetNavIgnore(this: v10, duration: 2.5);
          }
        }
      }
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10018260
// Name: public: virtual void CAI_BaseHumanoid::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CAI_BaseHumanoid::TraceAttack(
        CAI_BaseHumanoid *this@<ecx>,
        int a2@<ebp>,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *v13; // eax
  unsigned int v14; // eax
  CBaseEntity *m_pEntity; // esi
  CAI_Enemies *(__thiscall *GetEnemies)(CAI_BaseNPC *); // eax
  CAI_Enemies *v17; // eax
  AI_EnemyInfo_t *First; // esi
  CBaseEntity *Attacker; // eax
  CAI_Enemies *v20; // eax
  unsigned int v21; // eax
  CBaseEntity *v22; // esi
  float v23; // xmm0_4
  float v24; // xmm1_4
  __int128 v25; // xmm0
  const CTakeDamageInfo *v26; // ecx
  _BYTE v27[12]; // [esp-Ch] [ebp-8Ch] BYREF
  _BYTE newInfo_36[64]; // [esp+24h] [ebp-5Ch] OVERLAPPED
  AIEnemiesIter_t__ *v29; // [esp+6Ch] [ebp-14h] BYREF
  char v30; // [esp+73h] [ebp-Dh]
  int v31; // [esp+74h] [ebp-Ch] BYREF
  AIEnemiesIter_t__ *iter; // [esp+78h] [ebp-8h]
  AIEnemiesIter_t__ *retaddr; // [esp+80h] [ebp+0h]

  v31 = a2;
  iter = retaddr;
  if ( ptr->hitgroup != 1 )
    goto LABEL_31;
  m_Index = info->m_hAttacker.m_Index;
  if ( m_Index == -1 )
    goto LABEL_31;
  v7 = (unsigned __int16)m_Index;
  v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v9 = HIWORD(m_Index);
  if ( v8->m_SerialNumber != v9 || v8->m_pEntity == nullptr )
    goto LABEL_31;
  v10 = v7;
  v11 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9;
  v12 = &g_pEntityList->m_EntPtrArray[v10];
  v13 = v11 ? v12->m_pEntity : nullptr;
  if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v13->__vftable[28].dtr_IHandleEntity)(a1: v13) == 0 )
    goto LABEL_31;
  v14 = info->m_hAttacker.m_Index;
  if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
  if ( m_pEntity == this->GetEnemy_2(this) || this->m_bInAScript )
    goto LABEL_31;
  GetEnemies = this->GetEnemies;
  v30 = 1;
  v17 = GetEnemies(this);
  First = CAI_Enemies::GetFirst(this: v17, pIter: &v29);
  if ( First != nullptr )
  {
    while ( 1 )
    {
      Attacker = CTakeDamageInfo::GetAttacker(this: info);
      if ( CHandle<CBaseEntity>::operator==(this: &First->hEnemy, val: Attacker) )
        break;
      v20 = this->GetEnemies(this);
      First = CAI_Enemies::GetNext(this: v20, pIter: &v29);
      if ( First == nullptr )
        goto LABEL_20;
    }
    v30 = 0;
  }
LABEL_20:
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  v21 = info->m_hAttacker.m_Index;
  if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
    v22 = nullptr;
  else
    v22 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
  if ( (v22->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v22);
  v23 = v22->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
  v24 = (float)((float)((float)(v22->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y)
                      * (float)(v22->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y))
              + (float)((float)(v22->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)
                      * (float)(v22->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)))
      + (float)(v23 * v23);
  v25 = 0;
  *(float *)&v25 = fsqrt(v24);
  *(_OWORD *)&newInfo_36[48] = v25;
  if ( *(float *)&v25 <= 360.0 && v30 != 0 )
  {
    CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)v27, __that: info);
    *(float *)newInfo_36 = (float)this->m_iHealth.m_Value;
    v26 = (const CTakeDamageInfo *)v27;
  }
  else
  {
LABEL_31:
    v26 = info;
  }
  CAI_BaseNPC::TraceAttack(this, a2: (int)&v31, info: v26, vecDir, ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10018500
// Name: public: virtual void CAI_BaseHumanoid::BuildScheduleTestBits(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseHumanoid::BuildScheduleTestBits(CAI_BaseHumanoid *this)
{
  CAI_BehaviorHost<CAI_BaseNPC>::BuildScheduleTestBits(this);
  if ( (this->CapabilitiesGet(this) & 0x1000000) != 0
    && CAI_ShotRegulator::IsInRestInterval(this: &this->m_ShotRegulator) )
  {
    CAI_BaseNPC::ClearCustomInterruptCondition(this, nCondition: 21);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FBD10
// Name: _dynamic_initializer_for__Human_Hull__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Human_Hull__()
{
  *(_QWORD *)&Human_Hull.mins.x = 0xC1500000C1500000uLL;
  *(_QWORD *)&Human_Hull.maxs.x = 0x4150000041500000LL;
  Human_Hull.mins.z = 0.0;
  *(_QWORD *)&Human_Hull.smallMins.x = 0xC1000000C1000000uLL;
  Human_Hull.maxs.z = 72.0;
  Human_Hull.smallMins.z = 0.0;
  *(_QWORD *)&Human_Hull.smallMaxs.x = 0x4100000041000000LL;
  Human_Hull.smallMaxs.z = 72.0;
  return 1116733440;
}

//------------------------------------------------------------------------------
// Address: 0x103FBDE0
// Name: _dynamic_initializer_for__Small_Centered_Hull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Small_Centered_Hull__()
{
  *(_QWORD *)&Small_Centered_Hull.mins.x = 0xC1A00000C1A00000uLL;
  *(_QWORD *)&Small_Centered_Hull.maxs.x = 0x41A0000041A00000LL;
  Small_Centered_Hull.mins.z = -20.0;
  *(_QWORD *)&Small_Centered_Hull.smallMins.x = 0xC1400000C1400000uLL;
  Small_Centered_Hull.maxs.z = 20.0;
  Small_Centered_Hull.smallMins.z = -12.0;
  *(_QWORD *)&Small_Centered_Hull.smallMaxs.x = 0x4140000041400000LL;
  Small_Centered_Hull.smallMaxs.z = 12.0;
  return 1094713344;
}

//------------------------------------------------------------------------------
// Address: 0x103FBEA0
// Name: _dynamic_initializer_for__Wide_Human_Hull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Wide_Human_Hull__()
{
  *(_QWORD *)&Wide_Human_Hull.mins.x = 0xC1700000C1700000uLL;
  *(_QWORD *)&Wide_Human_Hull.maxs.x = 0x4170000041700000LL;
  Wide_Human_Hull.mins.z = 0.0;
  *(_QWORD *)&Wide_Human_Hull.smallMins.x = 0xC1200000C1200000uLL;
  Wide_Human_Hull.maxs.z = 72.0;
  Wide_Human_Hull.smallMins.z = 0.0;
  *(_QWORD *)&Wide_Human_Hull.smallMaxs.x = 0x4120000041200000LL;
  Wide_Human_Hull.smallMaxs.z = 72.0;
  return 1116733440;
}

//------------------------------------------------------------------------------
// Address: 0x103FBF70
// Name: _dynamic_initializer_for__Tiny_Hull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Tiny_Hull__()
{
  *(_QWORD *)&Tiny_Hull.mins.x = 0xC1400000C1400000uLL;
  *(_QWORD *)&Tiny_Hull.maxs.x = 0x4140000041400000LL;
  Tiny_Hull.mins.z = 0.0;
  *(_QWORD *)&Tiny_Hull.smallMins.x = 0xC1400000C1400000uLL;
  Tiny_Hull.maxs.z = 24.0;
  Tiny_Hull.smallMins.z = 0.0;
  *(_QWORD *)&Tiny_Hull.smallMaxs.x = 0x4140000041400000LL;
  Tiny_Hull.smallMaxs.z = 24.0;
  return 1103101952;
}

//------------------------------------------------------------------------------
// Address: 0x103FC030
// Name: _dynamic_initializer_for__Wide_Short_Hull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Wide_Short_Hull__()
{
  *(_QWORD *)&Wide_Short_Hull.mins.x = 0xC20C0000C20C0000uLL;
  *(_QWORD *)&Wide_Short_Hull.maxs.x = 0x420C0000420C0000LL;
  Wide_Short_Hull.mins.z = 0.0;
  *(_QWORD *)&Wide_Short_Hull.smallMins.x = 0xC1A00000C1A00000uLL;
  Wide_Short_Hull.maxs.z = 32.0;
  Wide_Short_Hull.smallMins.z = 0.0;
  *(_QWORD *)&Wide_Short_Hull.smallMaxs.x = 0x41A0000041A00000LL;
  Wide_Short_Hull.smallMaxs.z = 32.0;
  return 1107296256;
}

//------------------------------------------------------------------------------
// Address: 0x103FC100
// Name: _dynamic_initializer_for__Medium_Hull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Medium_Hull__()
{
  *(_QWORD *)&Medium_Hull.mins.x = 0xC1800000C1800000uLL;
  *(_QWORD *)&Medium_Hull.maxs.x = 0x4180000041800000LL;
  Medium_Hull.mins.z = 0.0;
  *(_QWORD *)&Medium_Hull.smallMins.x = 0xC1000000C1000000uLL;
  Medium_Hull.maxs.z = 64.0;
  Medium_Hull.smallMins.z = 0.0;
  *(_QWORD *)&Medium_Hull.smallMaxs.x = 0x4100000041000000LL;
  Medium_Hull.smallMaxs.z = 64.0;
  return 1115684864;
}

//------------------------------------------------------------------------------
// Address: 0x103FC1D0
// Name: _dynamic_initializer_for__Tiny_Centered_Hull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Tiny_Centered_Hull__()
{
  *(_QWORD *)&Tiny_Centered_Hull.mins.x = 0xC1000000C1000000uLL;
  *(_QWORD *)&Tiny_Centered_Hull.maxs.x = 0x4100000041000000LL;
  Tiny_Centered_Hull.mins.z = -4.0;
  *(_QWORD *)&Tiny_Centered_Hull.smallMins.x = 0xC1000000C1000000uLL;
  Tiny_Centered_Hull.maxs.z = 4.0;
  Tiny_Centered_Hull.smallMins.z = -4.0;
  *(_QWORD *)&Tiny_Centered_Hull.smallMaxs.x = 0x4100000041000000LL;
  Tiny_Centered_Hull.smallMaxs.z = 4.0;
  return 1082130432;
}
