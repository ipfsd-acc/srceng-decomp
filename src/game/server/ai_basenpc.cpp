// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_basenpc.cpp
// Functions: 460
// ============================================================

#include "game\server\ai_basenpc.h"

//------------------------------------------------------------------------------
// Address: 0x100013F0
// Name: public: bool CBaseEntity::ClassMatches(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::ClassMatches(CBaseEntity *this, const char *pszClassOrWildcard)
{
  return this->m_iClassname.pszValue == pszClassOrWildcard || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard);
}

//------------------------------------------------------------------------------
// Address: 0x100185A0
// Name: public: void CAI_BaseNPC::InputStartScripting(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputStartScripting(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  this->m_bInAScript = true;
}

//------------------------------------------------------------------------------
// Address: 0x100185B0
// Name: public: void CAI_BaseNPC::InputStopScripting(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputStopScripting(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  this->m_bInAScript = false;
}

//------------------------------------------------------------------------------
// Address: 0x100185C0
// Name: public: bool CAI_BaseNPC::IsInLockedScene(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsInLockedScene(CAI_BaseNPC *this)
{
  return this->m_flSceneTime > gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x100185E0
// Name: float RemapVal(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapVal(float val, float A, float B, float C, float D)
{
  if ( A != B )
    return C + (D - C) * (val - A) / (B - A);
  if ( (float)(val - B) < 0.0 )
    return C;
  return D;
}

//------------------------------------------------------------------------------
// Address: 0x10018650
// Name: public: virtual bool IAI_BehaviorBridge::BehaviorBridge_IsValidCover(class Vector const __near &,class CAI_Hint const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IAI_BehaviorBridge::BehaviorBridge_IsValidCover(
        vgui::Panel *this,
        vgui::Menu *menu,
        vgui::Menu *msglist)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10018660
// Name: public: virtual bool CAI_BaseNPC::RespondedTo(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::RespondedTo(vgui::TreeView *this, int itemIndex, vgui::Menu *menu, vgui::Menu *msglist)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10018670
// Name: public: virtual bool IAI_BehaviorBridge::BehaviorBridge_IsJumpLegal(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float,float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IAI_BehaviorBridge::BehaviorBridge_IsJumpLegal(
        IAI_BehaviorBridge *this,
        const Vector *startPos,
        const Vector *apex,
        const Vector *endPos,
        float maxUp,
        float maxDown,
        float maxDist)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10018680
// Name: public: CEffectData::CEffectData(void)
// Source: json
//------------------------------------------------------------------------------
CEffectData *__thiscall CEffectData::CEffectData(CEffectData *this)
{
  this->m_vOrigin.x = 0.0;
  this->m_vOrigin.y = 0.0;
  this->m_vOrigin.z = 0.0;
  this->m_vStart.x = 0.0;
  this->m_vStart.y = 0.0;
  this->m_vStart.z = 0.0;
  this->m_vNormal.x = 0.0;
  this->m_vNormal.y = 0.0;
  this->m_vNormal.z = 0.0;
  this->m_vAngles.x = 0.0;
  this->m_vAngles.y = 0.0;
  this->m_vAngles.z = 0.0;
  this->m_fFlags = 0;
  this->m_nEntIndex = 0;
  this->m_flScale = 1.0;
  this->m_nAttachmentIndex = 0;
  this->m_nSurfaceProp = 0;
  this->m_flMagnitude = 0.0;
  this->m_flRadius = 0.0;
  this->m_nMaterial = 0;
  this->m_nDamageType = 0;
  this->m_nHitBox = 0;
  this->m_nColor = 0;
  this->m_nOtherEntIndex = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10018700
// Name: public: void Ray_t::Init(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Ray_t::Init(Ray_t *this, const Vector *start, const Vector *end)
{
  this->m_Delta.x = end->x - start->x;
  this->m_Delta.y = end->y - start->y;
  this->m_Delta.z = end->z - start->z;
  this->m_IsSwept = (float)((float)((float)(this->m_Delta.x * this->m_Delta.x)
                                  + (float)(this->m_Delta.y * this->m_Delta.y))
                          + (float)(this->m_Delta.z * this->m_Delta.z)) != 0.0;
  this->m_Extents.z = 0.0;
  this->m_Extents.y = 0.0;
  this->m_Extents.x = 0.0;
  this->m_pWorldAxisTransform = nullptr;
  this->m_IsRay = true;
  this->m_StartOffset.z = 0.0;
  this->m_StartOffset.y = 0.0;
  this->m_StartOffset.x = 0.0;
  this->m_Start.Vector = *start;
}

//------------------------------------------------------------------------------
// Address: 0x100187B0
// Name: public: void Ray_t::Init(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Ray_t::Init(
        Ray_t *this,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs)
{
  this->m_Delta.x = end->x - start->x;
  this->m_Delta.y = end->y - start->y;
  this->m_Delta.z = end->z - start->z;
  this->m_pWorldAxisTransform = nullptr;
  this->m_IsSwept = (float)((float)((float)(this->m_Delta.x * this->m_Delta.x)
                                  + (float)(this->m_Delta.y * this->m_Delta.y))
                          + (float)(this->m_Delta.z * this->m_Delta.z)) != 0.0;
  this->m_Extents.x = maxs->x - mins->x;
  this->m_Extents.y = maxs->y - mins->y;
  this->m_Extents.z = maxs->z - mins->z;
  this->m_Extents.x = this->m_Extents.x * 0.5;
  this->m_Extents.y = this->m_Extents.y * 0.5;
  this->m_Extents.z = this->m_Extents.z * 0.5;
  this->m_IsRay = (float)((float)((float)(this->m_Extents.x * this->m_Extents.x)
                                + (float)(this->m_Extents.y * this->m_Extents.y))
                        + (float)(this->m_Extents.z * this->m_Extents.z)) < 0.000001;
  this->m_StartOffset.x = mins->x + maxs->x;
  this->m_StartOffset.y = maxs->y + mins->y;
  this->m_StartOffset.z = mins->z + maxs->z;
  this->m_StartOffset.x = this->m_StartOffset.x * 0.5;
  this->m_StartOffset.y = this->m_StartOffset.y * 0.5;
  this->m_StartOffset.z = this->m_StartOffset.z * 0.5;
  this->m_Start.x = start->x + this->m_StartOffset.x;
  this->m_Start.y = this->m_StartOffset.y + start->y;
  this->m_Start.z = this->m_StartOffset.z + start->z;
  this->m_StartOffset.x = this->m_StartOffset.x * -1.0;
  this->m_StartOffset.y = this->m_StartOffset.y * -1.0;
  this->m_StartOffset.z = this->m_StartOffset.z * -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10018980
// Name: public: bool CJob::IsFinished(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CJob::IsFinished(CJob *this)
{
  int m_status; // eax

  m_status = this->m_status;
  return m_status != 1 && m_status != 2 && m_status != 4;
}

//------------------------------------------------------------------------------
// Address: 0x100189A0
// Name: class CPostFrameNavigationHook __near * PostFrameNavigationSystem(void)
// Source: json
//------------------------------------------------------------------------------
CPostFrameNavigationHook *__cdecl PostFrameNavigationSystem()
{
  return &g_PostFrameNavigationHook;
}

//------------------------------------------------------------------------------
// Address: 0x100189B0
// Name: ProcessNavigationQueries
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessNavigationQueries(CFunctor **pData, unsigned int nCount)
{
  unsigned int i; // esi

  for ( i = 0; i < nCount; ++i )
    pData[i]->operator()(this: pData[i]);
}

//------------------------------------------------------------------------------
// Address: 0x100189E0
// Name: public: void CAI_BaseNPC::SetPrimaryBehavior(class CAI_BehaviorBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetPrimaryBehavior(CAI_BaseNPC *this, CAI_BehaviorBase *pNewBehavior)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // ebx

  m_pPrimaryBehavior = this->m_pPrimaryBehavior;
  this->m_pPrimaryBehavior = pNewBehavior;
  if ( m_pPrimaryBehavior != pNewBehavior )
  {
    if ( pNewBehavior != nullptr )
    {
      pNewBehavior->BeginScheduleSelection(this: pNewBehavior);
      g_bBehaviorHost_PreventBaseClassGatherConditions = true;
      this->m_pPrimaryBehavior->GatherConditions(this: this->m_pPrimaryBehavior);
      g_bBehaviorHost_PreventBaseClassGatherConditions = false;
    }
    if ( m_pPrimaryBehavior != nullptr )
    {
      m_pPrimaryBehavior->EndScheduleSelection(this: m_pPrimaryBehavior);
      CAI_BaseNPC::VacateStrategySlot(this);
    }
    this->OnChangeRunningBehavior(this, a2: m_pPrimaryBehavior, a3: pNewBehavior);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018A60
// Name: public: class CAI_BehaviorBase __near * CAI_BaseNPC::DeferSchedulingToBehavior(class CAI_BehaviorBase __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_BehaviorBase *__thiscall CAI_BaseNPC::DeferSchedulingToBehavior(CAI_BaseNPC *this, CAI_BehaviorBase *pNewBehavior)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // esi

  m_pPrimaryBehavior = this->m_pPrimaryBehavior;
  CAI_BaseNPC::SetPrimaryBehavior(this, pNewBehavior);
  return m_pPrimaryBehavior;
}

//------------------------------------------------------------------------------
// Address: 0x10018A80
// Name: public: virtual bool CAI_BaseNPC::Event_Gibbed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::Event_Gibbed(CAI_BaseNPC *this, const CTakeDamageInfo *info)
{
  bool v3; // bl

  v3 = this->CorpseGib(this, a2: info);
  if ( v3 )
  {
    UTIL_Remove(oldObj: this);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    return v3;
  }
  else
  {
    this->CorpseFade(this);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018AE0
// Name: public: virtual void CAI_BaseNPC::Ignite(float,bool,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::Ignite(
        CAI_BaseNPC *this,
        float flFlameLifetime,
        bool bNPCOnly,
        float flSize,
        bool bCalledByLevelDesigner)
{
  CBaseAnimating::Ignite(this, flFlameLifetime, bNPCOnly, flSize, bCalledByLevelDesigner);
}

//------------------------------------------------------------------------------
// Address: 0x10018B10
// Name: public: virtual unsigned int CAI_BaseNPC::PhysicsSolidMaskForEntity(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAI_BaseNPC::PhysicsSolidMaskForEntity(CAI_BaseNPC *this)
{
  return 33701899;
}

//------------------------------------------------------------------------------
// Address: 0x10018B20
// Name: public: virtual void CAI_BaseNPC::DecalTrace(class CGameTrace __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::DecalTrace(CAI_BaseNPC *this, CGameTrace *pTrace, const char *decalName)
{
  if ( this->m_fNoDamageDecal )
    this->m_fNoDamageDecal = false;
  else
    CBaseEntity::DecalTrace(this, pTrace, decalName);
}

//------------------------------------------------------------------------------
// Address: 0x10018B40
// Name: public: virtual void CAI_BaseNPC::ImpactTrace(class CGameTrace __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ImpactTrace(
        CAI_BaseNPC *this,
        CGameTrace *pTrace,
        int iDamageType,
        char *pCustomImpactName)
{
  if ( this->m_fNoDamageDecal )
    this->m_fNoDamageDecal = false;
  else
    CBaseEntity::ImpactTrace(this, pTrace, iDamageType, pCustomImpactName);
}

//------------------------------------------------------------------------------
// Address: 0x10018B60
// Name: public: virtual float CAI_BaseNPC::GetHitgroupDamageMultiplier(int,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::GetHitgroupDamageMultiplier(
        CAI_BaseNPC *this,
        int iHitGroup,
        const CTakeDamageInfo *info)
{
  double result; // st7

  switch ( iHitGroup )
  {
    case 1:
      result = sk_npc_head.m_pParent->m_Value.m_fValue;
      break;
    case 2:
      result = sk_npc_chest.m_pParent->m_Value.m_fValue;
      break;
    case 3:
      result = sk_npc_stomach.m_pParent->m_Value.m_fValue;
      break;
    case 4:
    case 5:
      result = sk_npc_arm.m_pParent->m_Value.m_fValue;
      break;
    case 6:
    case 7:
      result = sk_npc_leg.m_pParent->m_Value.m_fValue;
      break;
    default:
      result = 1.0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018BE0
// Name: public: virtual void CAI_BaseNPC::MakeTracer(class Vector const __near &,class CGameTrace const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::MakeTracer(
        CAI_BaseNPC *this,
        const Vector *vecTracerSrc,
        const CGameTrace *tr,
        int iTracerType)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    ActiveWeapon->MakeTracer(this: ActiveWeapon, a2: vecTracerSrc, a3: tr, a4: iTracerType);
  }
  else
  {
    CBaseEntity::MakeTracer(this, vecTracerSrc, tr, iTracerType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018C20
// Name: public: virtual void CAI_BaseNPC::FireBullets(struct FireBulletsInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::FireBullets(CAI_BaseNPC *this, const FireBulletsInfo_t *info)
{
  CBaseEntity::FireBullets(this, info);
}

//------------------------------------------------------------------------------
// Address: 0x10018C30
// Name: public: virtual void CAI_BaseNPC::DoImpactEffect(class CGameTrace __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::DoImpactEffect(CAI_BaseNPC *this, CGameTrace *tr, int nDamageType)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    ActiveWeapon->DoImpactEffect(this: ActiveWeapon, a2: tr, a3: nDamageType);
  }
  else
  {
    CBaseEntity::DoImpactEffect(this, tr, nDamageType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018C70
// Name: public: void CAI_BaseNPC::SetDistLook(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetDistLook(CAI_BaseNPC *this, float flDistLook)
{
  this->m_pSenses->m_LookDist = flDistLook;
}

//------------------------------------------------------------------------------
// Address: 0x10018C90
// Name: public: virtual bool CAI_BaseNPC::QuerySeeEntity(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::QuerySeeEntity(CAI_BaseNPC *this, CBaseEntity *pEntity, bool bOnlyHateOrFearIfNPC)
{
  Disposition_t v4; // eax

  if ( !bOnlyHateOrFearIfNPC || !pEntity->IsNPC(this: pEntity) )
    return true;
  v4 = this->IRelationType(this, a2: pEntity);
  return v4 == D_HT || v4 == D_FR;
}

//------------------------------------------------------------------------------
// Address: 0x10018CF0
// Name: public: virtual enum Activity CAI_BaseNPC::GetHintActivity(short,enum Activity)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_BaseNPC::GetHintActivity(CAI_BaseNPC *this, __int16 sHintType, Activity HintsActivity)
{
  Activity result; // eax

  result = HintsActivity;
  if ( HintsActivity == ACT_INVALID )
    return ACT_IDLE;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018D10
// Name: public: virtual int CAI_BaseNPC::GetSoundInterests(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::GetSoundInterests(CAI_BaseNPC *this)
{
  return 8215;
}

//------------------------------------------------------------------------------
// Address: 0x10018D20
// Name: public: virtual int CAI_BaseNPC::GetSoundPriority(class CSound __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::GetSoundPriority(CAI_BaseNPC *this, CSound *pSound)
{
  if ( (pSound->m_iType & 8) != 0 )
    return 3;
  if ( (pSound->m_iType & 1) != 0 )
    return ((pSound->m_iType & 0x2000000) != 0) + 1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018D60
// Name: public: virtual class CSound __near * CAI_BaseNPC::GetBestSound(int)
// Source: json
//------------------------------------------------------------------------------
CSound *__thiscall CAI_BaseNPC::GetBestSound(CAI_BaseNPC *this, int validTypes)
{
  CSound *result; // eax
  CSound *ClosestSound; // esi

  result = this->m_pLockedBestSound;
  if ( result->m_iType == 0 )
  {
    ClosestSound = CAI_Senses::GetClosestSound(this: this->m_pSenses, fScent: false, validTypes, bUsePriority: true);
    if ( ClosestSound == nullptr )
      DevMsg(a1: "Warning: NULL Return from GetBestSound\n");
    return ClosestSound;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018DA0
// Name: public: virtual class CSound __near * CAI_BaseNPC::GetBestScent(void)
// Source: json
//------------------------------------------------------------------------------
CSound *__thiscall CAI_BaseNPC::GetBestScent(CAI_BaseNPC *this)
{
  CSound *result; // eax

  result = CAI_Senses::GetClosestSound(this: this->m_pSenses, fScent: true, validTypes: 0xFFFFF, bUsePriority: true);
  if ( result == nullptr )
  {
    DevMsg(a1: "Warning: NULL Return from GetBestScent\n");
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018DD0
// Name: public: class CSound __near & CSound::operator=(class CSound const __near &)
// Source: json
//------------------------------------------------------------------------------
CSound *__thiscall CSound::operator=(CSound *this, const CSound *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10018E30
// Name: public: virtual bool CAI_BaseNPC::ValidEyeTarget(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::ValidEyeTarget(CAI_BaseNPC *this, const Vector *lookTargetPos)
{
  Vector *v3; // eax
  _BYTE v5[12]; // [esp+4h] [ebp-24h] BYREF
  Vector vHeadDir; // [esp+10h] [ebp-18h] BYREF
  Vector lookTargetDir; // [esp+1Ch] [ebp-Ch] BYREF

  this->HeadDirection3D(this, result: &vHeadDir);
  v3 = this->EyePosition(this, result: v5);
  lookTargetDir.x = lookTargetPos->x - v3->x;
  lookTargetDir.y = lookTargetPos->y - v3->y;
  lookTargetDir.z = lookTargetPos->z - v3->z;
  VectorNormalize(vec: &lookTargetDir);
  return (float)((float)((float)(lookTargetDir.x * vHeadDir.x) + (float)(vHeadDir.y * lookTargetDir.y))
               + (float)(vHeadDir.z * lookTargetDir.z)) > 0.7;
}

//------------------------------------------------------------------------------
// Address: 0x10018EE0
// Name: public: virtual class Vector CAI_BaseNPC::HeadDirection2D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::HeadDirection2D(CAI_BaseNPC *this, Vector *result)
{
  QAngle bodyAngles; // [esp+Ch] [ebp-Ch] BYREF

  this->BodyAngles(this, result: &bodyAngles);
  UTIL_YawToVector(result, yaw: this->m_flHeadYaw + bodyAngles.y);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018F30
// Name: public: virtual class Vector CAI_BaseNPC::HeadDirection3D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::HeadDirection3D(CAI_BaseNPC *this, Vector *result)
{
  QAngle bodyAngles; // [esp+4h] [ebp-18h] BYREF
  QAngle angles; // [esp+10h] [ebp-Ch] BYREF

  this->BodyAngles(this, result: &bodyAngles);
  angles.x = this->m_flHeadPitch;
  angles.y = this->m_flHeadYaw + bodyAngles.y;
  angles.z = 0.0;
  AngleVectors(&angles, forward: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018F90
// Name: public: virtual void CAI_BaseNPC::AimGun(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::AimGun(CAI_BaseNPC *this)
{
  bool v2; // zf
  CAI_BaseNPC_vtbl *v3; // eax
  int v4; // eax
  float v5; // xmm0_4
  Vector *(__thiscall *GetShootEnemyDir)(CAI_BaseNPC *, Vector *, const Vector *, bool); // eax
  Vector v7; // [esp+4h] [ebp-24h] BYREF
  Vector vecShootDir; // [esp+10h] [ebp-18h] BYREF
  Vector vecShootOrigin; // [esp+1Ch] [ebp-Ch] BYREF

  v2 = this->GetEnemy_2(this) == nullptr;
  v3 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 )
  {
    v3->RelaxAim(this);
  }
  else
  {
    v4 = (int)v3->Weapon_ShootPosition(this, result: &v7);
    vecShootOrigin.x = *(float *)v4;
    vecShootOrigin.y = *(float *)(v4 + 4);
    v5 = *(float *)(v4 + 8);
    GetShootEnemyDir = this->GetShootEnemyDir;
    vecShootOrigin.z = v5;
    GetShootEnemyDir(this, result: &vecShootDir, a3: &vecShootOrigin, a4: false);
    this->SetAim(this, a2: &vecShootDir);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019010
// Name: public: virtual void CAI_BaseNPC::MaintainTurnActivity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::MaintainTurnActivity(CAI_BaseNPC *this)
{
  if ( !this->IsInAVehicle(this) )
    this->m_pMotor->MaintainTurnActivity(this: this->m_pMotor);
}

//------------------------------------------------------------------------------
// Address: 0x10019040
// Name: int ThinkRebalanceCompare(struct AIRebalanceInfo_t const __near *,struct AIRebalanceInfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ThinkRebalanceCompare(const AIRebalanceInfo_t *pLeft, const AIRebalanceInfo_t *pRight)
{
  int result; // eax
  float dotPlayer; // xmm1_4
  float v4; // xmm3_4
  float distPlayer; // xmm2_4

  result = pLeft->iNextThinkTick - pRight->iNextThinkTick;
  if ( result == 0 )
  {
    if ( !pLeft->bInPVS )
      return pRight->bInPVS;
    if ( !pRight->bInPVS )
      return -1;
    dotPlayer = pLeft->dotPlayer;
    if ( dotPlayer < 0.0 )
    {
      if ( pRight->dotPlayer < 0.0 )
        return 0;
      if ( dotPlayer < 0.0 )
        return 1;
    }
    v4 = pRight->dotPlayer;
    if ( v4 < 0.0 )
      return -1;
    distPlayer = pLeft->distPlayer;
    if ( distPlayer < 600.0 && pRight->distPlayer >= 600.0 )
      return -1;
    if ( pRight->distPlayer < 600.0 && distPlayer >= 600.0 )
      return 1;
    if ( dotPlayer > v4 )
      return -1;
    return v4 > dotPlayer;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100190D0
// Name: bool NPC_CheckBrushExclude(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NPC_CheckBrushExclude(CBaseEntity *pEntity, CBaseEntity *pBrush)
{
  CAI_BaseNPC *v2; // eax

  v2 = pEntity->MyNPCPointer(this: pEntity);
  return v2 != nullptr && CAI_MoveProbe::ShouldBrushBeIgnored(this: v2->m_pMoveProbe, pEntity: pBrush);
}

//------------------------------------------------------------------------------
// Address: 0x10019100
// Name: public: int CServerNetworkProperty::entindex(void)const
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CServerNetworkProperty::entindex(CServerNetworkProperty *this)
{
  edict_t *result; // eax

  result = this->m_pPev;
  if ( result != nullptr )
    return (edict_t *)(result - gpGlobals->pEdicts);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019120
// Name: public: virtual int CAI_BaseNPC::RangeAttack1Conditions(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::RangeAttack1Conditions(CAI_BaseNPC *this, float flDot, float flDist)
{
  int result; // eax

  if ( flDist < 64.0 )
    return 38;
  if ( flDist > 784.0 )
    return 39;
  result = 40;
  if ( flDot >= 0.5 )
    return 21;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019170
// Name: public: virtual int CAI_BaseNPC::RangeAttack2Conditions(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::RangeAttack2Conditions(CAI_BaseNPC *this, float flDot, float flDist)
{
  int result; // eax

  if ( flDist < 64.0 )
    return 38;
  if ( flDist > 512.0 )
    return 39;
  result = 40;
  if ( flDot >= 0.5 )
    return 22;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100191C0
// Name: public: virtual int CAI_BaseNPC::MeleeAttack2Conditions(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::MeleeAttack2Conditions(CAI_BaseNPC *this, float flDot, float flDist)
{
  if ( flDist > 64.0 )
    return 39;
  if ( flDot >= 0.7 )
    return 24;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019200
// Name: public: virtual int CAI_BaseNPC::CapabilitiesGet(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::CapabilitiesGet(CAI_BaseNPC *this)
{
  int m_afCapability; // esi
  CBaseCombatWeapon *ActiveWeapon; // eax

  m_afCapability = this->m_afCapability;
  if ( CBaseCombatCharacter::GetActiveWeapon(this) == nullptr )
    return m_afCapability;
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  return m_afCapability | ActiveWeapon->CapabilitiesGet(this: ActiveWeapon);
}

//------------------------------------------------------------------------------
// Address: 0x10019230
// Name: public: int CAI_BaseNPC::CapabilitiesAdd(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::CapabilitiesAdd(CAI_BaseNPC *this, int capability)
{
  this->m_afCapability |= capability;
  return this->m_afCapability;
}

//------------------------------------------------------------------------------
// Address: 0x10019250
// Name: public: int CAI_BaseNPC::CapabilitiesRemove(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::CapabilitiesRemove(CAI_BaseNPC *this, int capability)
{
  this->m_afCapability &= ~capability;
  return this->m_afCapability;
}

//------------------------------------------------------------------------------
// Address: 0x10019270
// Name: public: void CAI_BaseNPC::CapabilitiesClear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::CapabilitiesClear(CAI_BaseNPC *this)
{
  this->m_afCapability = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019280
// Name: public: bool CAI_BaseNPC::WokeThisTick(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::WokeThisTick(CAI_BaseNPC *this)
{
  return this->m_nWakeTick == gpGlobals->tickcount;
}

//------------------------------------------------------------------------------
// Address: 0x100192A0
// Name: protected: virtual bool CAI_BaseNPC::CanFlinch(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::CanFlinch(CAI_BaseNPC *this)
{
  return !CAI_BaseNPC::IsCurSchedule(this, schedId: 23, fIdeal: true) && this->m_flNextFlinchTime < gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x100192D0
// Name: public: virtual void CAI_BaseNPC::PrescheduleThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::PrescheduleThink(CAI_BaseNPC *this)
{
  DesiredWeaponState_t m_iDesiredWeaponState; // eax
  DesiredWeaponState_t v3; // eax

  if ( (this->CapabilitiesGet(this) & 0x200000) != 0 )
  {
    m_iDesiredWeaponState = this->m_iDesiredWeaponState;
    if ( m_iDesiredWeaponState == DESIREDWEAPONSTATE_HOLSTERED
      || m_iDesiredWeaponState == DESIREDWEAPONSTATE_UNHOLSTERED
      || m_iDesiredWeaponState == DESIREDWEAPONSTATE_HOLSTERED_DESTROYED )
    {
      if ( !this->IsAlive(this) || this->m_bInAScript )
      {
        this->m_iDesiredWeaponState = DESIREDWEAPONSTATE_IGNORE;
      }
      else if ( !CAI_BaseNPC::IsCurSchedule(this, schedId: 42, fIdeal: false)
             && !CAI_BaseNPC::IsCurSchedule(this, schedId: 43, fIdeal: false)
             && !CAI_BaseNPC::IsCurSchedule(this, schedId: 44, fIdeal: false)
             && !CAI_BaseNPC::IsCurSchedule(this, schedId: 45, fIdeal: false) )
      {
        v3 = this->m_iDesiredWeaponState;
        if ( v3 == DESIREDWEAPONSTATE_HOLSTERED || v3 == DESIREDWEAPONSTATE_HOLSTERED_DESTROYED )
        {
          this->HolsterWeapon(this);
        }
        else if ( v3 == DESIREDWEAPONSTATE_UNHOLSTERED )
        {
          this->UnholsterWeapon(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100193A0
// Name: public: virtual bool CAI_BaseNPC::ShouldLookForBetterWeapon(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::ShouldLookForBetterWeapon(CAI_BaseNPC *this)
{
  return this->m_flNextWeaponSearchTime <= gpGlobals->curtime
      && (this->CapabilitiesGet(this) & 0x200000) != 0
      && (CBaseCombatCharacter::GetActiveWeapon(this) == nullptr || this->m_NPCState != NPC_STATE_COMBAT)
      && !CAI_BaseNPC::IsCurSchedule(this, schedId: 64, fIdeal: true)
      && (this->IsPlayerAlly(this, a2: nullptr) || CBaseCombatCharacter::GetActiveWeapon(this) == nullptr)
      && !this->m_bInAScript;
}

//------------------------------------------------------------------------------
// Address: 0x10019420
// Name: public: virtual float CAI_BaseNPC::GetReactionDelay(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::GetReactionDelay(CAI_BaseNPC *this, CBaseEntity *pEnemy)
{
  NPC_STATE m_NPCState; // eax

  m_NPCState = this->m_NPCState;
  if ( m_NPCState == NPC_STATE_ALERT || m_NPCState == NPC_STATE_COMBAT )
    return ai_reaction_delay_alert.m_pParent->m_Value.m_fValue;
  else
    return ai_reaction_delay_idle.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x10019470
// Name: public: virtual bool CAI_BaseNPC::UpdateEnemyMemory(class CBaseEntity __near *,class Vector const __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::UpdateEnemyMemory(
        CAI_BaseNPC *this,
        CBaseEntity *pEnemy,
        const Vector *position,
        CAI_BaseNPC *pInformer)
{
  CAI_Enemies *v5; // eax
  double v6; // xmm0_8
  CAI_Enemies *v7; // eax
  bool result; // al
  CAI_Squad *m_pSquad; // ecx
  CAI_Network *m_pAINetwork; // [esp-8h] [ebp-2Ch]
  float reactionDelay; // [esp+4h] [ebp-20h]
  bool firstHand; // [esp+20h] [ebp-4h]
  bool result_3; // [esp+37h] [ebp+13h]

  if ( pInformer == nullptr || (firstHand = false, pInformer == this) )
    firstHand = true;
  if ( this->GetEnemies(this) == nullptr )
    return true;
  v5 = this->GetEnemies(this);
  if ( CAI_Enemies::HasEludedMe(this: v5, pEnemy) )
    this->FoundEnemySound(this);
  if ( pInformer == nullptr || pInformer == this )
    v6 = ((double (__thiscall *)(CAI_BaseNPC *, CBaseEntity *))this->GetReactionDelay)(a1: this, a2: pEnemy);
  else
    v6 = 0.0;
  reactionDelay = v6;
  m_pAINetwork = this->m_pNavigator->m_pAINetwork;
  v7 = this->GetEnemies(this);
  result = CAI_Enemies::UpdateMemory(
             this: v7,
             pAINet: m_pAINetwork,
             pEnemy,
             vPosition: position,
             reactionDelay,
             firstHand);
  result_3 = result;
  if ( firstHand )
  {
    if ( pEnemy != nullptr )
    {
      m_pSquad = this->m_pSquad;
      if ( m_pSquad != nullptr )
      {
        CAI_Squad::UpdateEnemyMemory(this: m_pSquad, pUpdater: this, pEnemy, position);
        return result_3;
      }
    }
  }
  else if ( pEnemy != nullptr && result && this->m_NPCState == NPC_STATE_IDLE )
  {
    this->m_flNextDecisionTime = 0.0;
    this->m_Efficiency = AIE_NORMAL;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019580
// Name: public: bool CBaseEntity::ClassMatches(struct string_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::ClassMatches(CBaseEntity *this, string_t nameStr)
{
  const char *pszValue; // eax

  pszValue = nameStr.pszValue;
  if ( this->m_iClassname.pszValue == nameStr.pszValue )
    return true;
  if ( nameStr.pszValue == nullptr )
    pszValue = locale;
  return CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x100195B0
// Name: public: virtual bool CAI_BaseNPC::IsActivityMovementPhased(enum Activity)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsActivityMovementPhased(CAI_BaseNPC *this, Activity activity)
{
  return activity >= ACT_WALK && activity <= ACT_RUN_PROTECTED;
}

//------------------------------------------------------------------------------
// Address: 0x100195D0
// Name: public: virtual void CAI_BaseNPC::OnChangeActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnChangeActivity(CAI_BaseNPC *this, Activity eNewActivity)
{
  if ( eNewActivity == ACT_RUN || eNewActivity == ACT_RUN_AIM || eNewActivity == ACT_WALK )
    this->Stand(this);
}

//------------------------------------------------------------------------------
// Address: 0x10019600
// Name: public: virtual class Vector CBaseEntity::GetSmoothedVelocity(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseEntity::GetSmoothedVelocity(CBaseEntity *this, Vector *result)
{
  this->GetVelocity(this, a2: result, a3: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019620
// Name: public: enum SolidType_t CBaseEntity::GetSolid(void)const
// Source: json
//------------------------------------------------------------------------------
SolidType_t __thiscall CBaseEntity::GetSolid(CBaseEntity *this)
{
  return this->m_Collision.GetSolid(this: &this->m_Collision);
}

//------------------------------------------------------------------------------
// Address: 0x10019660
// Name: protected: virtual void CAI_BaseNPC::OnUpdateShotRegulator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnUpdateShotRegulator(CAI_BaseNPC *this)
{
  CBaseCombatWeapon *ActiveWeapon; // esi
  int v3; // eax
  CAI_BehaviorBase *m_pPrimaryBehavior; // ecx
  float flMinBurstInterval; // [esp+0h] [ebp-14h]
  float flMinBurstIntervala; // [esp+0h] [ebp-14h]
  float flMaxBurstInterval; // [esp+4h] [ebp-10h]
  int flMaxBurstIntervala; // [esp+4h] [ebp-10h]
  float flMaxBurstIntervalb; // [esp+4h] [ebp-10h]

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  if ( ActiveWeapon != nullptr )
  {
    flMaxBurstInterval = ActiveWeapon->GetFireRate(this: ActiveWeapon);
    flMinBurstInterval = ActiveWeapon->GetFireRate(this: ActiveWeapon);
    CAI_ShotRegulator::SetBurstInterval(this: &this->m_ShotRegulator, flMinBurstInterval, flMaxBurstInterval);
    flMaxBurstIntervala = ActiveWeapon->GetMaxBurst(this: ActiveWeapon);
    v3 = ActiveWeapon->GetMinBurst(this: ActiveWeapon);
    CAI_ShotRegulator::SetBurstShotCountRange(
      this: &this->m_ShotRegulator,
      minShotsPerBurst: v3,
      maxShotsPerBurst: flMaxBurstIntervala);
    flMaxBurstIntervalb = ActiveWeapon->GetMaxRestTime(this: ActiveWeapon);
    flMinBurstIntervala = ActiveWeapon->GetMinRestTime(this: ActiveWeapon);
    CAI_ShotRegulator::SetRestInterval(
      this: &this->m_ShotRegulator,
      flMinRestInterval: flMinBurstIntervala,
      flMaxRestInterval: flMaxBurstIntervalb);
    m_pPrimaryBehavior = this->m_pPrimaryBehavior;
    if ( m_pPrimaryBehavior != nullptr )
      m_pPrimaryBehavior->OnUpdateShotRegulator(this: m_pPrimaryBehavior);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019710
// Name: public: virtual bool CAI_BaseNPC::CanHolsterWeapon(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::CanHolsterWeapon(CAI_BaseNPC *this)
{
  return CBaseAnimating::SelectWeightedSequence(this, activity: ACT_DISARM) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019720
// Name: public: void CAI_BaseNPC::InputHolsterWeapon(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputHolsterWeapon(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  this->m_iDesiredWeaponState = DESIREDWEAPONSTATE_HOLSTERED;
}

//------------------------------------------------------------------------------
// Address: 0x10019730
// Name: public: void CAI_BaseNPC::InputHolsterAndDestroyWeapon(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputHolsterAndDestroyWeapon(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  this->m_iDesiredWeaponState = DESIREDWEAPONSTATE_HOLSTERED_DESTROYED;
}

//------------------------------------------------------------------------------
// Address: 0x10019740
// Name: public: void CAI_BaseNPC::InputUnholsterWeapon(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputUnholsterWeapon(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  this->m_iDesiredWeaponState = DESIREDWEAPONSTATE_UNHOLSTERED;
}

//------------------------------------------------------------------------------
// Address: 0x10019750
// Name: public: bool CAI_BaseNPC::IsWeaponStateChanging(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsWeaponStateChanging(CAI_BaseNPC *this)
{
  DesiredWeaponState_t m_iDesiredWeaponState; // eax

  m_iDesiredWeaponState = this->m_iDesiredWeaponState;
  return m_iDesiredWeaponState == DESIREDWEAPONSTATE_CHANGING
      || m_iDesiredWeaponState == DESIREDWEAPONSTATE_CHANGING_DESTROY;
}

//------------------------------------------------------------------------------
// Address: 0x10019770
// Name: public: void CAI_BaseNPC::AddRelationship(char const __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::AddRelationship(CAI_BaseNPC *this, const char *pszRelationship, CBaseEntity *pActivator)
{
  const char *v4; // edi
  const char *v5; // eax
  const char *v6; // esi
  const char *v7; // eax
  CBaseEntity *EntityByName; // esi
  IEntityFactoryDictionary *v9; // eax
  CBaseEntity *v10; // eax
  CBaseEntity *v11; // esi
  CAI_BaseNPC_vtbl *v12; // edi
  int v13; // eax
  char parseString[1000]; // [esp+8h] [ebp-3F0h] BYREF
  int priority; // [esp+3F0h] [ebp-8h]
  Disposition_t disposition; // [esp+3F4h] [ebp-4h]

  V_strncpy(pDest: parseString, pSrc: pszRelationship, maxLen: 1000);
  v4 = strtok(string: parseString, control: " ");
  if ( v4 != nullptr )
  {
    while ( 1 )
    {
      v5 = strtok(string: nullptr, control: " ");
      v6 = v5;
      if ( v5 == nullptr )
        break;
      if ( _V_stricmp(s1: v5, s2: "D_HT") != 0 )
      {
        if ( _V_stricmp(s1: v6, s2: "D_FR") != 0 )
        {
          if ( _V_stricmp(s1: v6, s2: "D_LI") != 0 )
          {
            if ( _V_stricmp(s1: v6, s2: "D_NU") != 0 )
            {
              _Warning(a1: "***ERROR***\nBad relationship type (%s) to unknown entity (%s)!\n", v6, v4);
              return;
            }
            disposition = D_NU;
          }
          else
          {
            disposition = D_LI;
          }
        }
        else
        {
          disposition = D_FR;
        }
      }
      else
      {
        disposition = D_HT;
      }
      v7 = strtok(string: nullptr, control: " ");
      if ( v7 != nullptr )
        priority = atoi(nptr: v7);
      else
        priority = 0x80000000;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: v4,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      if ( EntityByName != nullptr )
      {
        do
        {
          this->AddEntityRelationship(this, a2: EntityByName, a3: disposition, a4: priority);
          EntityByName = CGlobalEntityList::FindEntityByName(
                           this: &gEntList,
                           pStartEntity: EntityByName,
                           szName: v4,
                           pSearchingEntity: nullptr,
                           pActivator: nullptr,
                           pCaller: nullptr,
                           pFilter: nullptr);
        }
        while ( EntityByName != nullptr );
      }
      else if ( _V_stricmp(s1: "player", s2: v4) != 0 && _V_stricmp(s1: "!player", s2: v4) != 0 )
      {
        if ( EntityFactoryDictionary() != nullptr
          && (v9 = EntityFactoryDictionary(), v9->FindFactory(this: v9, a2: v4) != nullptr)
          && (v10 = CreateEntityByName(className: v4, iForceEdictIndex: -1, bNotify: true), v11 = v10, v10 != nullptr) )
        {
          v12 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          v13 = ((int (__thiscall *)(CBaseEntity *, Disposition_t, int))v10->Classify)(
                  a1: v10,
                  a2: disposition,
                  a3: priority);
          ((void (__thiscall *)(CAI_BaseNPC *, int))v12->AddClassRelationship)(a1: this, a2: v13);
          UTIL_RemoveImmediate(oldObj: v11);
        }
        else
        {
          DevWarning(a1: "Couldn't set relationship to unknown entity or class (%s)!\n", v4);
        }
      }
      else
      {
        this->AddClassRelationship(this, a2: CLASS_PLAYER, a3: disposition, a4: priority);
      }
      v4 = strtok(string: nullptr, control: " ");
      if ( v4 == nullptr )
        return;
    }
    _Warning(
      a1: "Can't parse relationship info (%s) - Expecting 'name [D_HT, D_FR, D_LI, D_NU] [1-99]'\n",
      pszRelationship);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100199B0
// Name: public: virtual void CAI_BaseNPC::AddEntityRelationship(class CBaseEntity __near *,enum Disposition_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::AddEntityRelationship(
        CAI_BaseNPC *this,
        CBaseEntity *pEntity,
        Disposition_t nDisposition,
        int nPriority)
{
  CBaseCombatCharacter::AddEntityRelationship(this, pEntity, disposition: nDisposition, priority: nPriority);
}

//------------------------------------------------------------------------------
// Address: 0x100199C0
// Name: public: virtual void CAI_BaseNPC::AddClassRelationship(enum Class_T,enum Disposition_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::AddClassRelationship(
        CAI_BaseNPC *this,
        Class_T nClass,
        Disposition_t nDisposition,
        int nPriority)
{
  CBaseCombatCharacter::AddClassRelationship(this, class_type: nClass, disposition: nDisposition, priority: nPriority);
}

//------------------------------------------------------------------------------
// Address: 0x100199D0
// Name: public: virtual bool CAI_BaseNPC::InitSquad(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::InitSquad(CAI_BaseNPC *this)
{
  const char *pszValue; // edi
  const char *v3; // eax
  CAI_Squad *Squad; // esi

  if ( this->m_pSquad != nullptr || (this->CapabilitiesGet(this) & 0x4000000) == 0 )
    return this->m_pSquad != nullptr;
  pszValue = this->m_SquadName.pszValue;
  if ( pszValue != nullptr )
  {
    Squad = CAI_SquadManager::FindSquad(this: &g_AI_SquadManager, squadName: (string_t)pszValue);
    if ( Squad == nullptr )
      Squad = CAI_SquadManager::CreateSquad(this: &g_AI_SquadManager, squadName: (string_t)pszValue);
    CAI_Squad::AddToSquad(this: Squad, pNPC: this);
    this->m_pSquad = Squad;
    return this->m_pSquad != nullptr;
  }
  v3 = this->m_iClassname.pszValue;
  if ( v3 == nullptr )
    v3 = locale;
  _DevMsg(a1: 2, a2: "Found %s that isn't in a squad\n", v3);
  return this->m_pSquad != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10019A60
// Name: public: virtual class CAI_Enemies __near * CAI_BaseNPC::GetEnemies(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Enemies *__thiscall CAI_BaseNPC::GetEnemies(CAI_BaseNPC *this)
{
  return this->m_pEnemies;
}

//------------------------------------------------------------------------------
// Address: 0x10019A70
// Name: public: int CAI_BaseNPC::TaskIsRunning(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::TaskIsRunning(CAI_BaseNPC *this)
{
  TaskStatus_e fTaskStatus; // eax

  fTaskStatus = this->m_ScheduleState.fTaskStatus;
  return fTaskStatus != TASKSTATUS_COMPLETE && fTaskStatus != TASKSTATUS_RUN_MOVE;
}

//------------------------------------------------------------------------------
// Address: 0x10019A90
// Name: public: virtual bool CAI_BaseNPC::CanBeAnEnemyOf(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::CanBeAnEnemyOf(CAI_BaseNPC *this, CBaseEntity *pEnemy)
{
  return this->m_SleepState <= AISS_WAITING_FOR_THREAT;
}

//------------------------------------------------------------------------------
// Address: 0x10019AA0
// Name: public: virtual enum Activity CAI_BaseNPC::GetCoverActivity(class CAI_Hint __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::GetCoverActivity(CAI_BaseNPC *this, CAI_Hint *pHint)
{
  if ( pHint != nullptr )
  {
    if ( pHint->m_NodeData.nHintType == 100 )
      return 4;
    if ( pHint->m_NodeData.nHintType == 101 )
      return 5;
  }
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10019AE0
// Name: public: virtual class Vector CAI_BaseNPC::EyeOffset(enum Activity)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::EyeOffset(CAI_BaseNPC *this, Vector *result, Activity nActivity)
{
  double ModelHierarchyScale; // st7

  if ( (this->CapabilitiesGet(this) & 0x8000000) != 0 && this->IsCrouchedActivity(this, a2: nActivity)
    || this->IsCrouching(this) )
  {
    this->GetCrouchEyeOffset(this, result);
    return result;
  }
  else
  {
    ModelHierarchyScale = CBaseAnimating::GetModelHierarchyScale(this);
    result->x = this->m_vDefaultEyeOffset.x * ModelHierarchyScale;
    result->y = this->m_vDefaultEyeOffset.y * ModelHierarchyScale;
    result->z = ModelHierarchyScale * this->m_vDefaultEyeOffset.z;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019B80
// Name: public: virtual class Vector CAI_BaseNPC::EyePosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::EyePosition(CAI_BaseNPC *this, Vector *result)
{
  Vector *v3; // eax
  _BYTE v5[12]; // [esp+4h] [ebp-Ch] BYREF

  if ( this->IsCrouching(this) )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    v3 = this->GetCrouchEyeOffset(this, result: v5);
    result->x = v3->x + this->m_vecAbsOrigin.x;
    result->y = v3->y + this->m_vecAbsOrigin.y;
    result->z = v3->z + this->m_vecAbsOrigin.z;
    return result;
  }
  else
  {
    CBaseEntity::EyePosition(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019C20
// Name: public: void CAI_BaseNPC::SetHintGroup(struct string_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetHintGroup(CAI_BaseNPC *this, string_t newGroup, bool bHintGroupNavLimiting)
{
  const char *pszValue; // eax

  pszValue = this->m_strHintGroup.pszValue;
  this->m_strHintGroup = newGroup;
  this->m_bHintGroupNavLimiting = bHintGroupNavLimiting;
  if ( pszValue != newGroup.pszValue )
    ((void (__thiscall *)(CAI_BaseNPC *, const char *, const char *))this->OnChangeHintGroup)(
      a1: this,
      a2: pszValue,
      a3: newGroup.pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x10019C60
// Name: public: virtual class Vector CAI_BaseNPC::GetActualShootPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::GetActualShootPosition(CAI_BaseNPC *this, Vector *result, const Vector *shootOrigin)
{
  const Vector *v4; // eax
  __int64 v5; // xmm0_8
  CAI_BaseNPC_vtbl *v6; // edx
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // eax
  int v8; // ebx
  CBaseEntity *v9; // eax
  float *v10; // edi
  float *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  CBaseEntity *(__thiscall *v14)(CBaseEntity *); // edx
  int v15; // eax
  float *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  Vector vecEnemyLKP; // [esp+Ch] [ebp-18h] BYREF
  Vector vecTargetPosition; // [esp+18h] [ebp-Ch] BYREF
  float shootOrigina; // [esp+30h] [ebp+Ch]

  v4 = this->GetEnemyLKP(this);
  v5 = *(_QWORD *)&v4->x;
  v6 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  vecEnemyLKP.z = v4->z;
  GetEnemy_2 = v6->GetEnemy_2;
  *(_QWORD *)&vecEnemyLKP.x = v5;
  v8 = (int)GetEnemy_2(this);
  v9 = this->GetEnemy_2(this);
  v10 = (float *)v9;
  if ( (v9->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v9);
  v11 = (float *)(*(int (__thiscall **)(int, Vector *, const Vector *, int))(*(_DWORD *)v8 + 520))(
                   a1: v8,
                   a2: &vecTargetPosition,
                   a3: shootOrigin,
                   a4: 1);
  v12 = *v11 - v10[115];
  v13 = v11[2] - v10[117];
  v14 = this->GetEnemy_2;
  vecTargetPosition.y = (float)(v11[1] - v10[116]) + vecEnemyLKP.y;
  vecTargetPosition.x = vecEnemyLKP.x + v12;
  vecTargetPosition.z = vecEnemyLKP.z + v13;
  v15 = (int)v14(this);
  shootOrigina = ai_lead_time.m_pParent->m_Value.m_fValue;
  v16 = (float *)(*(int (__thiscall **)(int, Vector *))(*(_DWORD *)v15 + 540))(a1: v15, a2: &vecEnemyLKP);
  v17 = v16[1];
  v18 = v16[2];
  v19 = shootOrigina * *v16;
  v21 = (float)(v17 * shootOrigina) + vecTargetPosition.y;
  v22 = (float)(v18 * shootOrigina) + vecTargetPosition.z;
  result->x = v19 + vecTargetPosition.x;
  result->y = v21;
  result->z = v22;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019D90
// Name: public: virtual float CAI_BaseNPC::GetSpreadBias(class CBaseCombatWeapon __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::GetSpreadBias(CAI_BaseNPC *this, CBaseCombatWeapon *pWeapon, CBaseEntity *pTarget)
{
  AI_EnemyInfo_t *v5; // ecx
  float m_fValue; // xmm4_4
  double result; // st7
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float bias; // [esp+14h] [ebp+Ch]

  bias = CBaseCombatCharacter::GetSpreadBias(this, pWeapon, pTarget);
  v5 = CAI_Enemies::Find(this: this->m_pEnemies, pEntity: pTarget, bTryDangerMemory: false);
  if ( ai_shot_bias.m_pParent->m_Value.m_fValue == 1.0 )
  {
    m_fValue = bias;
  }
  else
  {
    m_fValue = ai_shot_bias.m_pParent->m_Value.m_fValue;
    bias = m_fValue;
  }
  result = bias;
  if ( v5 != nullptr )
  {
    v8 = ai_spread_pattern_focus_time.m_pParent->m_Value.m_fValue;
    if ( v8 > 0.0 )
    {
      v9 = gpGlobals->curtime - v5->timeValidEnemy;
      if ( v9 < 0.0 )
        v9 = 0.0;
      v10 = gpGlobals->curtime - v5->timeLastReacquired;
      if ( v8 <= v9 )
      {
        if ( v8 > v10 )
          return (float)((float)(v10 / v8) * m_fValue);
      }
      else
      {
        return (float)((float)(v9 / v8) * m_fValue);
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019E50
// Name: public: virtual class Vector CAI_BaseNPC::GetAttackSpread(class CBaseCombatWeapon __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::GetAttackSpread(
        CAI_BaseNPC *this,
        Vector *result,
        CBaseCombatWeapon *pWeapon,
        CBaseEntity *pTarget)
{
  AI_EnemyInfo_t *v5; // eax
  float m_fValue; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  Vector *v9; // eax
  float v10; // xmm0_4

  CBaseCombatCharacter::GetAttackSpread(this, result, pWeapon, pTarget);
  v5 = CAI_Enemies::Find(this: this->m_pEnemies, pEntity: pTarget, bTryDangerMemory: false);
  if ( v5 == nullptr )
    return result;
  m_fValue = ai_spread_cone_focus_time.m_pParent->m_Value.m_fValue;
  if ( m_fValue <= 0.0 )
    return result;
  v7 = gpGlobals->curtime - v5->timeValidEnemy;
  if ( v7 < 0.0 )
    v7 = 0.0;
  if ( m_fValue <= v7 )
    return result;
  v8 = ai_spread_defocused_cone_multiplier.m_pParent->m_Value.m_fValue;
  v9 = result;
  if ( v8 > 1.0 )
  {
    v10 = (float)((float)(1.0 - (float)(v7 / m_fValue)) * (float)(v8 - 1.0)) + 1.0;
    result->x = result->x * v10;
    result->y = result->y * v10;
    result->z = result->z * v10;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10019F20
// Name: public: virtual class Vector CAI_BaseNPC::BodyTarget(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::BodyTarget(CAI_BaseNPC *this, Vector *result, const Vector *posSrc, bool bNoisy)
{
  const Vector *v5; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float *v12; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  Vector high; // [esp+14h] [ebp-28h] BYREF
  Vector delta; // [esp+20h] [ebp-1Ch]
  Vector low; // [esp+2Ch] [ebp-10h]
  float rand1; // [esp+38h] [ebp-4h]
  float rand2; // [esp+4Ch] [ebp+10h]

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  v5 = this->WorldSpaceCenter(this);
  x = v5->x;
  y = v5->y;
  z = v5->z;
  WorldSpaceCenter = this->WorldSpaceCenter;
  v10 = (float)(y - this->m_vecAbsOrigin.y) * 0.25;
  v11 = (float)(z - this->m_vecAbsOrigin.z) * 0.25;
  delta.x = (float)(x - this->m_vecAbsOrigin.x) * 0.25;
  delta.y = v10;
  delta.z = v11;
  v12 = (float *)WorldSpaceCenter(this);
  EyePosition = this->EyePosition;
  low.x = *v12 - delta.x;
  low.y = v12[1] - v10;
  low.z = v12[2] - v11;
  EyePosition(this, result: &high);
  v14 = low.y;
  v15 = low.z;
  v16 = high.y - low.y;
  v17 = high.z - low.z;
  delta.x = high.x - low.x;
  delta.y = high.y - low.y;
  delta.z = high.z - low.z;
  if ( bNoisy )
  {
    rand1 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
              a1: random,
              a2: 0,
              a3: 1056964608);
    rand2 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
              a1: random,
              a2: 0,
              a3: 1056964608);
    v19 = (float)((float)(delta.y * rand1) + low.y) + (float)(delta.y * rand2);
    v20 = (float)((float)(delta.z * rand1) + low.z) + (float)(delta.z * rand2);
    result->x = (float)((float)(delta.x * rand1) + low.x) + (float)(delta.x * rand2);
    result->y = v19;
    result->z = v20;
    return result;
  }
  else
  {
    result->x = (float)((float)(high.x - low.x) * 0.5) + low.x;
    result->y = (float)(v16 * 0.5) + v14;
    result->z = (float)(v17 * 0.5) + v15;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A120
// Name: public: virtual bool CAI_BaseNPC::ShouldMoveAndShoot(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::ShouldMoveAndShoot(CAI_BaseNPC *this)
{
  return (this->CapabilitiesGet(this) & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A140
// Name: public: bool CAI_BaseNPC::FacingIdeal(float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::FacingIdeal(CAI_BaseNPC *this, float flTolerance)
{
  if ( flTolerance <= 0.0060000001 )
    flTolerance = 0.0060000001;
  return flTolerance >= fabs(CAI_Motor::DeltaIdealYaw(this: this->m_pMotor));
}

//------------------------------------------------------------------------------
// Address: 0x1001A180
// Name: public: virtual void CAI_BaseNPC::AddFacingTarget(class CBaseEntity __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::AddFacingTarget(
        CAI_BaseNPC *this,
        CBaseEntity *pTarget,
        float flImportance,
        float flDuration,
        float flRamp)
{
  ((void (__thiscall *)(CAI_Motor *, CBaseEntity *, _DWORD, _DWORD, _DWORD))this->m_pMotor->AddFacingTarget_3)(
    a1: this->m_pMotor,
    a2: pTarget,
    a3: LODWORD(flImportance),
    a4: LODWORD(flDuration),
    a5: LODWORD(flRamp));
}

//------------------------------------------------------------------------------
// Address: 0x1001A1C0
// Name: public: virtual void CAI_BaseNPC::AddFacingTarget(class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::AddFacingTarget(
        CAI_BaseNPC *this,
        const Vector *vecPosition,
        float flImportance,
        float flDuration,
        float flRamp)
{
  ((void (__thiscall *)(CAI_Motor *, const Vector *, _DWORD, _DWORD, _DWORD))this->m_pMotor->AddFacingTarget_2)(
    a1: this->m_pMotor,
    a2: vecPosition,
    a3: LODWORD(flImportance),
    a4: LODWORD(flDuration),
    a5: LODWORD(flRamp));
}

//------------------------------------------------------------------------------
// Address: 0x1001A200
// Name: public: virtual void CAI_BaseNPC::AddFacingTarget(class CBaseEntity __near *,class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::AddFacingTarget(
        CAI_BaseNPC *this,
        CBaseEntity *pTarget,
        const Vector *vecPosition,
        float flImportance,
        float flDuration,
        float flRamp)
{
  ((void (__thiscall *)(CAI_Motor *, CBaseEntity *, const Vector *, _DWORD, _DWORD, _DWORD))this->m_pMotor->AddFacingTarget)(
    a1: this->m_pMotor,
    a2: pTarget,
    a3: vecPosition,
    a4: LODWORD(flImportance),
    a5: LODWORD(flDuration),
    a6: LODWORD(flRamp));
}

//------------------------------------------------------------------------------
// Address: 0x1001A240
// Name: public: virtual float CAI_BaseNPC::GetFacingDirection(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CAI_BaseNPC::GetFacingDirection(CAI_BaseNPC *this, Vector *vecDir)
{
  return this->m_pMotor->GetFacingDirection(this: this->m_pMotor, a2: vecDir);
}

//------------------------------------------------------------------------------
// Address: 0x1001A260
// Name: public: virtual int CAI_BaseNPC::PlayScriptedSentence(char const __near *,float,float,enum soundlevel_t,bool,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::PlayScriptedSentence(
        CAI_BaseNPC *this,
        const char *pszSentence,
        float delay,
        float volume,
        soundlevel_t soundlevel,
        bool bConcurrent,
        CBaseEntity *pListener)
{
  return ((int (__thiscall *)(CAI_BaseNPC *, const char *, _DWORD, _DWORD, soundlevel_t, CBaseEntity *))this->PlaySentence)(
           a1: this,
           a2: pszSentence,
           a3: LODWORD(delay),
           a4: LODWORD(volume),
           a5: soundlevel,
           a6: pListener);
}

//------------------------------------------------------------------------------
// Address: 0x1001A2A0
// Name: public: virtual class Vector const __near & CAI_BaseNPC::GetEnemyLKP(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_BaseNPC::GetEnemyLKP(CAI_BaseNPC *this)
{
  CAI_Enemies *v2; // eax
  CBaseEntity *v4; // [esp-4h] [ebp-8h]

  v4 = this->GetEnemy(this);
  v2 = this->GetEnemies(this);
  return CAI_Enemies::LastKnownPosition(this: v2, pEnemy: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1001A2D0
// Name: public: float CAI_BaseNPC::GetEnemyLastTimeSeen(void)const
// Source: json
//------------------------------------------------------------------------------
float __thiscall CAI_BaseNPC::GetEnemyLastTimeSeen(CAI_BaseNPC *this)
{
  CAI_Enemies *v2; // eax
  CBaseEntity *v5; // [esp-8h] [ebp-Ch]

  v5 = this->GetEnemy(this);
  v2 = this->GetEnemies(this);
  return CAI_Enemies::LastTimeSeen(this: v2, pEnemy: v5, bCheckDangerMemory: true);
}

//------------------------------------------------------------------------------
// Address: 0x1001A300
// Name: public: void CAI_BaseNPC::MarkEnemyAsEluded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::MarkEnemyAsEluded(CAI_BaseNPC *this)
{
  CAI_Enemies *v2; // eax
  CBaseEntity *v3; // [esp-4h] [ebp-8h]

  v3 = this->GetEnemy_2(this);
  v2 = this->GetEnemies(this);
  CAI_Enemies::MarkAsEluded(this: v2, pEnemy: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1001A330
// Name: public: virtual void CAI_BaseNPC::PickupWeapon(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::PickupWeapon(CAI_BaseNPC *this, CBaseCombatWeapon *pWeapon)
{
  pWeapon->OnPickedUp(this: pWeapon, a2: this);
  this->Weapon_Equip(this, a2: pWeapon);
  this->m_iszPendingWeapon.pszValue = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001A370
// Name: public: virtual void CAI_BaseNPC::MakeAIFootstepSound(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::MakeAIFootstepSound(CAI_BaseNPC *this, float volume, CBaseEntity *duration)
{
  const Vector *v3; // eax
  int iVolume[3]; // [esp+10h] [ebp-Ch] BYREF

  v3 = (const Vector *)((int (__fastcall *)(CAI_BaseNPC *))this->EyePosition)(a1: this);
  CSoundEnt::InsertSound(
    iType: 1,
    vecOrigin: v3,
    (int)iVolume,
    flDuration: COERCE_FLOAT((int)volume),
    pOwner: duration,
    soundChannelIndex: (int)this,
    pSoundTarget: (CBaseEntity *)7);
}

//------------------------------------------------------------------------------
// Address: 0x1001A3B0
// Name: public: virtual void CAI_BaseNPC::JustMadeSound(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::JustMadeSound(CAI_BaseNPC *this, int soundPriority, float flSoundLength)
{
  double v4; // st7
  bool v5; // zf
  double v6; // st6
  float time; // [esp+10h] [ebp-Ch]

  v4 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: 1069547520,
         a3: 0x40000000);
  v5 = this->m_pSquad == nullptr;
  v6 = gpGlobals->curtime + flSoundLength;
  this->m_nSoundPriority = soundPriority;
  this->m_flSoundWaitTime = v4 + v6;
  if ( !v5 )
  {
    time = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
             a1: random,
             a2: 1069547520,
             a3: 0x40000000)
         + gpGlobals->curtime
         + flSoundLength;
    CAI_Squad::JustMadeSound(this: this->m_pSquad, soundPriority, time);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A460
// Name: public: enum Activity CAI_BaseNPC::GetStoppedActivity(void)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_BaseNPC::GetStoppedActivity(CAI_BaseNPC *this)
{
  Activity result; // eax

  if ( !CAI_Navigator::IsGoalActive(this: this->m_pNavigator) )
    return ACT_IDLE;
  result = CAI_Navigator::GetArrivalActivity(this: this->m_pNavigator);
  if ( result <= ACT_RESET )
    return ACT_IDLE;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A490
// Name: public: virtual struct datamap_t __near * CAI_BaseNPC::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_BaseNPC::GetDataDescMap(CAI_BaseNPC *this)
{
  return &CAI_BaseNPC::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1001A4A0
// Name: public: virtual class ServerClass __near * CAI_BaseNPC::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CAI_BaseNPC::GetServerClass(CAI_BaseNPC *this)
{
  return &g_CAI_BaseNPC_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1001A4B0
// Name: public: virtual void CAI_BaseNPC::PostConstructor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::PostConstructor(CAI_BaseNPC *this, const char *szClassname)
{
  CBaseEntity::PostConstructor(this, szClassname);
  this->CreateComponents(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001A4D0
// Name: public: virtual void CAI_BaseNPC::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::Precache(CAI_BaseNPC *this)
{
  const char *v2; // esi
  const char *DebugName; // eax
  char pszValue[4]; // [esp+8h] [ebp-4h] BYREF

  CAI_BaseNPC::gm_iszPlayerSquad.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
  v2 = this->m_spawnEquipment.pszValue;
  if ( v2 != nullptr && strcmp(this->m_spawnEquipment.pszValue, "0") != 0 )
    UTIL_PrecacheOther(szClassname: v2, modelName: nullptr);
  if ( this->LoadedSchedules(this) )
  {
    CBaseEntity::PrecacheScriptSound(soundname: "AI_BaseNPC.SwishSound");
    CBaseEntity::PrecacheScriptSound(soundname: "AI_BaseNPC.BodyDrop_Heavy");
    CBaseEntity::PrecacheScriptSound(soundname: "AI_BaseNPC.BodyDrop_Light");
    CBaseEntity::PrecacheScriptSound(soundname: "AI_BaseNPC.SentenceStop");
    CBaseCombatCharacter::Precache(this);
  }
  else
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "ERROR: Rejecting spawn of %s as error in NPC's schedules.\n", DebugName);
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A5A0
// Name: public: virtual bool CAI_BaseNPC::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::KeyValue(CAI_BaseNPC *this, const char *szKeyName, const char *szValue)
{
  CAI_BehaviorBase **v4; // ebx
  int v5; // edi
  bool bResult; // [esp+Fh] [ebp-1h]

  bResult = CBaseEntity::KeyValue(this, szKeyName, szValue);
  if ( bResult )
    return bResult;
  v4 = this->AccessBehaviors(this);
  v5 = 0;
  if ( this->NumBehaviors(this) <= 0 )
    return bResult;
  while ( !v4[v5]->KeyValue(this: v4[v5], a2: szKeyName, a3: szValue) )
  {
    if ( ++v5 >= this->NumBehaviors(this) )
      return bResult;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001A630
// Name: public: virtual void CAI_BaseNPC::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::UpdateOnRemove(CAI_BaseNPC *this)
{
  if ( !this->m_bDidDeathCleanup )
  {
    if ( this->m_NPCState == NPC_STATE_DEAD )
      DevMsg(a1: "May not have cleaned up on NPC death\n");
    this->CleanupOnDeath(this, a2: nullptr, a3: false);
  }
  CBaseCombatCharacter::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001A670
// Name: public: virtual bool CAI_BaseNPC::CreateComponents(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::CreateComponents(CAI_BaseNPC *this)
{
  CAI_Senses *v2; // eax
  CAI_Motor *v4; // eax
  CAI_LocalNavigator *v5; // eax
  CAI_MoveProbe *v6; // eax
  CAI_Navigator *v7; // eax
  CAI_Pathfinder *v8; // eax
  CAI_TacticalServices *v9; // eax
  CAI_LocalNavigator *m_pLocalNavigator; // eax
  IAI_MovementSink *v11; // eax
  CAI_Navigator *m_pNavigator; // eax
  IAI_MovementSink *v13; // eax

  v2 = this->CreateSenses(this);
  this->m_pSenses = v2;
  if ( v2 == nullptr )
    return false;
  v4 = this->CreateMotor(this);
  this->m_pMotor = v4;
  if ( v4 == nullptr )
    return false;
  v5 = this->CreateLocalNavigator(this);
  this->m_pLocalNavigator = v5;
  if ( v5 == nullptr )
    return false;
  v6 = this->CreateMoveProbe(this);
  this->m_pMoveProbe = v6;
  if ( v6 == nullptr )
    return false;
  v7 = this->CreateNavigator(this);
  this->m_pNavigator = v7;
  if ( v7 == nullptr )
    return false;
  v8 = this->CreatePathfinder(this);
  this->m_pPathfinder = v8;
  if ( v8 == nullptr )
    return false;
  v9 = this->CreateTacticalServices(this);
  this->m_pTacticalServices = v9;
  if ( v9 == nullptr )
    return false;
  this->m_MoveAndShootOverlay.SetOuter(this: &this->m_MoveAndShootOverlay, a2: this);
  m_pLocalNavigator = this->m_pLocalNavigator;
  if ( m_pLocalNavigator != nullptr )
    v11 = &m_pLocalNavigator->CAI_ProxyMovementSink;
  else
    v11 = nullptr;
  CAI_Motor::Init(this: this->m_pMotor, pMovementServices: v11);
  m_pNavigator = this->m_pNavigator;
  if ( m_pNavigator != nullptr )
    v13 = &m_pNavigator->CAI_DefMovementSink;
  else
    v13 = nullptr;
  CAI_LocalNavigator::Init(this: this->m_pLocalNavigator, pMovementServices: v13);
  this->m_pNavigator->Init(this: this->m_pNavigator, a2: g_pBigAINet);
  CAI_Pathfinder::Init(this: this->m_pPathfinder, pNetwork: g_pBigAINet);
  CAI_TacticalServices::Init(this: this->m_pTacticalServices, pNetwork: g_pBigAINet);
  return this->CreateBehaviors(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001A7B0
// Name: public: void CAI_BaseNPC::InputSetRelationship(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputSetRelationship(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
      CAI_BaseNPC::AddRelationship(this, pszRelationship: locale, pActivator: inputdata->pActivator);
      return;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  CAI_BaseNPC::AddRelationship(this, pszRelationship: iVal, pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x1001A800
// Name: public: void CAI_BaseNPC::InputBeginRappel(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputBeginRappel(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  this->BeginRappel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001A810
// Name: public: void CAI_BaseNPC::InputSetSquad(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputSetSquad(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  const char *DebugName; // eax
  variant_t *p_value; // eax
  const char *iVal; // esi
  CAI_Squad *m_pSquad; // ecx
  CAI_Squad *Squad; // edi

  if ( (this->CapabilitiesGet(this) & 0x4000000) != 0 )
  {
    p_value = &inputdata->value;
    if ( inputdata->value.fieldType != FIELD_STRING )
    {
      inputdata = nullptr;
      p_value = (variant_t *)&inputdata;
    }
    iVal = (const char *)p_value->iVal;
    this->m_SquadName.pszValue = (const char *)p_value->iVal;
    if ( iVal != nullptr )
    {
      Squad = CAI_SquadManager::FindSquad(this: &g_AI_SquadManager, squadName: (string_t)iVal);
      if ( Squad == nullptr )
        Squad = CAI_SquadManager::CreateSquad(this: &g_AI_SquadManager, squadName: (string_t)iVal);
      CAI_Squad::AddToSquad(this: Squad, pNPC: this);
      this->m_pSquad = Squad;
    }
    else
    {
      m_pSquad = this->m_pSquad;
      if ( m_pSquad != nullptr )
      {
        CAI_Squad::RemoveFromSquad(this: m_pSquad, pNPC: this, bDeath: true);
        this->m_pSquad = nullptr;
      }
    }
  }
  else
  {
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(a1: "SetSquad Input received for NPC %s, but that NPC can't use squads.\n", DebugName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A8C0
// Name: public: void CAI_BaseNPC::InputIgnoreDangerSounds(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputIgnoreDangerSounds(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  float flVal; // xmm1_4

  flVal = 10.0;
  if ( inputdata->value.fieldType == FIELD_FLOAT && inputdata->value.flVal > 0.0 )
    flVal = inputdata->value.flVal;
  this->m_flIgnoreDangerSoundsUntil = gpGlobals->curtime + flVal;
}

//------------------------------------------------------------------------------
// Address: 0x1001A900
// Name: public: void CAI_BaseNPC::InputUpdateEnemyMemory(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputUpdateEnemyMemory(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  CBaseEntity *EntityByName; // esi

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
  if ( EntityByName != nullptr )
  {
    if ( (EntityByName->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: EntityByName);
    this->UpdateEnemyMemory(this, a2: EntityByName, a3: &EntityByName->m_vecAbsOrigin, a4: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A970
// Name: public: virtual bool CAI_BaseNPC::HandleInteraction(int,void __near *,class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::HandleInteraction(
        CAI_BaseNPC *this,
        int interactionType,
        vgui::Menu *data,
        vgui::Menu *sourceEnt)
{
  return CAI_BaseNPC::RespondedTo((vgui::TreeView *)this, itemIndex: interactionType, menu: data, msglist: sourceEnt);
}

//------------------------------------------------------------------------------
// Address: 0x1001A980
// Name: public: virtual bool CAI_BaseNPC::IsNavigationUrgent(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsNavigationUrgent(CAI_BaseNPC *this)
{
  return CAI_BaseNPC::IsCurSchedule(this, schedId: 58, fIdeal: false)
      || CAI_BaseNPC::IsCurSchedule(this, schedId: 59, fIdeal: false)
      || CAI_BaseNPC::IsCurSchedule(this, schedId: 60, fIdeal: false)
      || CAI_BaseNPC::IsCurSchedule(this, schedId: 63, fIdeal: false) && this->m_flSceneTime > gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x1001A9E0
// Name: public: virtual bool CAI_BaseNPC::ShouldFailNav(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::ShouldFailNav(CAI_BaseNPC *this, bool bMovementFailed)
{
  return !this->IsNavigationUrgent(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001AA00
// Name: public: enum Navigation_t CAI_BaseNPC::GetNavType(void)const
// Source: json
//------------------------------------------------------------------------------
Navigation_t __thiscall CAI_BaseNPC::GetNavType(CAI_BaseNPC *this)
{
  return this->m_pNavigator->m_navType;
}

//------------------------------------------------------------------------------
// Address: 0x1001AA10
// Name: public: void CAI_BaseNPC::SetNavType(enum Navigation_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetNavType(CAI_BaseNPC *this, Navigation_t navType)
{
  CAI_Navigator::SetNavType(this: this->m_pNavigator, navType);
}

//------------------------------------------------------------------------------
// Address: 0x1001AA30
// Name: public: virtual bool CAI_BaseNPC::OnCalcBaseMove(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::OnCalcBaseMove(
        CAI_BaseNPC *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  CBaseEntity *pObstruction; // eax
  void *v6; // eax
  bool result; // al

  pObstruction = pMoveGoal->directTrace.pObstruction;
  result = false;
  if ( pObstruction != nullptr )
  {
    v6 = __RTDynamicCast(
           inptr: pObstruction,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBasePropDoor `RTTI Type Descriptor',
           isReference: 0);
    if ( v6 != nullptr
      && (*(unsigned __int8 (__stdcall **)(AILocalMoveGoal_t *, void *, _DWORD, AIMoveResult_t *))(*((_DWORD *)this - 571)
                                                                                                 + 2036))(
           a1: pMoveGoal,
           a2: v6,
           a3: LODWORD(distClear),
           a4: pResult) != 0 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001AAA0
// Name: public: virtual bool CAI_BaseNPC::OnObstructionPreSteer(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::OnObstructionPreSteer(
        CAI_BaseNPC *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  CBaseEntity *pObstruction; // eax
  void *v6; // eax
  bool result; // al

  pObstruction = pMoveGoal->directTrace.pObstruction;
  result = false;
  if ( pObstruction != nullptr )
  {
    v6 = __RTDynamicCast(
           inptr: pObstruction,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBaseDoor `RTTI Type Descriptor',
           isReference: 0);
    if ( v6 != nullptr
      && (*(unsigned __int8 (__stdcall **)(AILocalMoveGoal_t *, void *, _DWORD, AIMoveResult_t *))(*((_DWORD *)this - 571)
                                                                                                 + 2032))(
           a1: pMoveGoal,
           a2: v6,
           a3: LODWORD(distClear),
           a4: pResult) != 0 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001AB10
// Name: public: virtual bool CAI_BaseNPC::OnObstructingDoor(struct AILocalMoveGoal_t __near *,class CBaseDoor __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::OnObstructingDoor(
        CAI_BaseNPC *this,
        AILocalMoveGoal_t *pMoveGoal,
        CBaseDoor *pDoor,
        float distClear,
        AIMoveResult_t *pResult)
{
  TOGGLE_STATE m_toggle_state; // eax

  if ( distClear > pMoveGoal->maxDist )
    return 0;
  m_toggle_state = pDoor->m_toggle_state;
  if ( m_toggle_state != TS_AT_BOTTOM && m_toggle_state != TS_GOING_DOWN )
    return 0;
  if ( distClear >= 0.1 )
  {
    pMoveGoal->maxDist = distClear;
    *pResult = AIMR_OK;
  }
  else
  {
    *pResult = AIMR_BLOCKED_ENTITY;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001AB70
// Name: public: virtual bool CAI_BaseNPC::CanBeUsedAsAFriend(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::CanBeUsedAsAFriend(CAI_BaseNPC *this)
{
  return !CAI_BaseNPC::IsCurSchedule(this, schedId: 72, fIdeal: true)
      && !CAI_BaseNPC::IsCurSchedule(this, schedId: 73, fIdeal: true);
}

//------------------------------------------------------------------------------
// Address: 0x1001ABA0
// Name: public: virtual class Vector CAI_BaseNPC::GetSmoothedVelocity(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::GetSmoothedVelocity(CAI_BaseNPC *this, Vector *result)
{
  Navigation_t m_navType; // eax

  m_navType = this->m_pNavigator->m_navType;
  if ( m_navType == NAV_GROUND || m_navType == NAV_FLY )
  {
    *result = this->m_pMotor->m_vecVelocity;
    return result;
  }
  else
  {
    this->GetVelocity(this, a2: result, a3: nullptr);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001ABF0
// Name: public: bool CSimpleSimTimer::Expired(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSimpleSimTimer::Expired(CSimpleSimTimer *this)
{
  return (float)(gpGlobals->curtime - this->m_next) > -0.001;
}

//------------------------------------------------------------------------------
// Address: 0x1001AC20
// Name: public: float CAI_BaseNPC::SetWait(float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::SetWait(CAI_BaseNPC *this, float minWait, float maxWait)
{
  int v4; // edx
  double v5; // xmm0_8

  v4 = (int)(float)(minWait * 10.0);
  if ( maxWait == 0.0 )
  {
    v5 = (double)v4;
  }
  else
  {
    if ( v4 == 0 )
      v4 = 1;
    v5 = (double)random->RandomInt(this: random, a2: v4, a3: (int)(float)(maxWait * 10.0));
  }
  this->m_flWaitFinished = v5 * 0.1 + gpGlobals->curtime;
  return this->m_flWaitFinished;
}

//------------------------------------------------------------------------------
// Address: 0x1001AD00
// Name: public: bool CAI_BaseNPC::IsWaitFinished(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsWaitFinished(CAI_BaseNPC *this)
{
  return gpGlobals->curtime >= this->m_flWaitFinished;
}

//------------------------------------------------------------------------------
// Address: 0x1001AD20
// Name: public: bool CStopwatchBase::Expired(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CStopwatchBase::Expired(CStopwatchBase *this)
{
  return this->m_fIsRunning && (float)(gpGlobals->curtime - this->m_next) > -0.001;
}

//------------------------------------------------------------------------------
// Address: 0x1001AD50
// Name: public: void CRandStopwatch::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRandStopwatch::Start(CRandStopwatch *this)
{
  float m_maxInterval; // xmm0_4
  float m_minInterval; // xmm1_4

  m_maxInterval = this->m_maxInterval;
  m_minInterval = this->m_minInterval;
  this->m_fIsRunning = true;
  if ( m_maxInterval == 0.0 )
    this->m_next = gpGlobals->curtime + m_minInterval;
  else
    this->m_next = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                     a1: random,
                     a2: LODWORD(m_minInterval),
                     a3: LODWORD(m_maxInterval))
                 + gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x1001ADE0
// Name: protected: virtual bool CAI_BaseNPC::IsAllowedToDodge(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsAllowedToDodge(CAI_BaseNPC *this)
{
  NPC_STATE m_NPCState; // eax

  m_NPCState = this->m_NPCState;
  return (m_NPCState == NPC_STATE_IDLE || m_NPCState == NPC_STATE_ALERT || m_NPCState == NPC_STATE_COMBAT)
      && gpGlobals->curtime >= this->m_flNextDodgeTime;
}

//------------------------------------------------------------------------------
// Address: 0x1001AE20
// Name: public: virtual class Vector CAI_BaseNPC::Weapon_ShootPosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::Weapon_ShootPosition(CAI_BaseNPC *this, Vector *result)
{
  int m_iEFlags; // ecx
  Vector *v4; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  _BYTE v8[12]; // [esp+4h] [ebp-24h] BYREF
  Vector right; // [esp+10h] [ebp-18h] BYREF
  float v10; // [esp+1Ch] [ebp-Ch]
  float v11; // [esp+20h] [ebp-8h]
  float v12; // [esp+24h] [ebp-4h]

  this->GetVectors(this, a2: nullptr, a3: &right, a4: nullptr);
  if ( this->IsCrouching(this)
    || (this->CapabilitiesGet(this) & 0x8000000) != 0 && this->IsCrouchedActivity(this, a2: this->m_Activity) )
  {
    m_iEFlags = this->m_iEFlags;
    v10 = right.x * 8.0;
    v11 = right.y * 8.0;
    v12 = right.z * 8.0;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    v4 = this->GetCrouchGunOffset(this, result: v8);
    v6 = (float)(this->m_vecAbsOrigin.y + v4->y) + v11;
    v7 = (float)(this->m_vecAbsOrigin.z + v4->z) + v12;
    result->x = (float)(this->m_vecAbsOrigin.x + v4->x) + v10;
    result->y = v6;
    result->z = v7;
    return result;
  }
  else
  {
    CBaseCombatCharacter::Weapon_ShootPosition(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AF40
// Name: protected: virtual bool CAI_BaseNPC::Crouch(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::Crouch(CAI_BaseNPC *this)
{
  this->m_bIsCrouching = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001AF50
// Name: public: virtual bool CAI_BaseNPC::IsCrouching(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsCrouching(CAI_BaseNPC *this)
{
  return (this->CapabilitiesGet(this) & 0x8000000) != 0 && this->m_bIsCrouching;
}

//------------------------------------------------------------------------------
// Address: 0x1001AF80
// Name: protected: virtual bool CAI_BaseNPC::Stand(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::Stand(CAI_BaseNPC *this)
{
  char result; // al

  result = 0;
  if ( !this->m_bForceCrouch )
  {
    this->m_bIsCrouching = false;
    this->m_bCrouchDesired = false;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001AFA0
// Name: protected: virtual void CAI_BaseNPC::DesireCrouch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::DesireCrouch(CAI_BaseNPC *this)
{
  this->m_bCrouchDesired = true;
}

//------------------------------------------------------------------------------
// Address: 0x1001AFB0
// Name: class CBasePlayer __near * ToBasePlayer(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl ToBasePlayer(CBaseEntity *pEntity)
{
  if ( pEntity != nullptr && pEntity->IsPlayer(this: pEntity) )
    return (CBasePlayer *)pEntity;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001AFE0
// Name: class CBaseCombatWeapon __near * ToBaseCombatWeapon(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__cdecl ToBaseCombatWeapon(CBaseEntity *pEntity)
{
  if ( pEntity != nullptr )
    return pEntity->MyCombatWeaponPointer(this: pEntity);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001B000
// Name: public: CPASFilter::CPASFilter(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CPASFilter *__thiscall CPASFilter::CPASFilter(CPASFilter *this, const Vector *origin)
{
  CRecipientFilter::CRecipientFilter(this);
  this->__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this, origin);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001B0D0
// Name: float clamp<float,int,int>(float const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,int,int>(float *val, const int *minVal, const int *maxVal)
{
  float v3; // xmm1_4
  float vala; // [esp+8h] [ebp+8h]

  v3 = (float)*minVal;
  vala = *val;
  if ( v3 > vala )
    return v3;
  if ( vala <= (float)*maxVal )
    return vala;
  return (float)*maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x1001B140
// Name: public: class CBaseEntity __near * CAI_BaseNPC::GetTarget(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_BaseNPC::GetTarget(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1001B170
// Name: public: class CBaseEntity __near * CAI_BaseNPC::GetGoalEnt(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_BaseNPC::GetGoalEnt(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hGoalEnt.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1001B1A0
// Name: public: bool CAI_BaseNPC::HaveSequenceForActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::HaveSequenceForActivity(CAI_BaseNPC *this, Activity activity)
{
  CStudioHdr *m_pStudioHdr; // esi

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return false;
  if ( m_pStudioHdr->m_pActivityToSequence == nullptr )
    m_pStudioHdr->m_pActivityToSequence = CStudioHdr::CActivityToSequenceMapping::FindMapping(pHdr: m_pStudioHdr);
  return CStudioHdr::CActivityToSequenceMapping::NumSequencesForActivity(
           this: m_pStudioHdr->m_pActivityToSequence,
           forActivity: activity) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B200
// Name: protected: virtual void CAI_Component::TaskFail(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Component::TaskFail(CAI_Component *this, int code)
{
  this->m_pOuter->TaskFail(this: this->m_pOuter, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x1001B220
// Name: public: class Vector const __near & CShotManipulator::ApplySpread(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CShotManipulator::ApplySpread(CShotManipulator *this, const Vector *vecSpread, float bias)
{
  float v3; // xmm2_4
  float v5; // xmm2_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v16; // xmm2_4
  float shotBias; // [esp+24h] [ebp-10h]
  float ya; // [esp+28h] [ebp-Ch]
  float yb; // [esp+28h] [ebp-Ch]
  float y; // [esp+28h] [ebp-Ch]
  float x; // [esp+2Ch] [ebp-8h]
  float flatness; // [esp+30h] [ebp-4h]
  float biasa; // [esp+40h] [ebp+Ch]

  v3 = bias;
  if ( bias <= 1.0 )
  {
    if ( bias < 0.0 )
      v3 = 0.0;
  }
  else
  {
    v3 = 1.0;
  }
  shotBias = (float)((float)(ai_shot_bias_max.m_pParent->m_Value.m_fValue - ai_shot_bias_min.m_pParent->m_Value.m_fValue)
                   * v3)
           + ai_shot_bias_min.m_pParent->m_Value.m_fValue;
  flatness = COERCE_FLOAT(LODWORD(shotBias) & _mask__AbsFloat_) * 0.5;
  biasa = 1.0 - flatness;
  do
  {
    ya = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: -1082130432,
           a3: 1065353216)
       * biasa;
    x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
          a1: random,
          a2: -1082130432,
          a3: 1065353216)
      * flatness
      + ya;
    yb = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: -1082130432,
           a3: 1065353216)
       * biasa;
    y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
          a1: random,
          a2: -1082130432,
          a3: 1065353216)
      * flatness
      + yb;
    if ( shotBias >= 0.0 )
    {
      v6 = x;
      v8 = y;
    }
    else
    {
      if ( x < 0.0 )
        v5 = -1.0;
      else
        v5 = 1.0;
      v6 = v5 - x;
      if ( y < 0.0 )
        v7 = -1.0;
      else
        v7 = 1.0;
      v8 = v7 - y;
    }
  }
  while ( (float)((float)(v8 * v8) + (float)(v6 * v6)) > 1.0 );
  v9 = vecSpread->y * v8;
  v10 = this->m_vecUp.y * v9;
  v11 = this->m_vecUp.z * v9;
  v12 = this->m_vecUp.x * v9;
  v13 = vecSpread->x * v6;
  v14 = this->m_vecShotDirection.y + (float)(this->m_vecRight.y * v13);
  v16 = (float)(this->m_vecShotDirection.z + (float)(this->m_vecRight.z * v13)) + v11;
  this->m_vecResult.x = (float)(this->m_vecShotDirection.x + (float)(this->m_vecRight.x * v13)) + v12;
  this->m_vecResult.y = v14 + v10;
  this->m_vecResult.z = v16;
  return &this->m_vecResult;
}

//------------------------------------------------------------------------------
// Address: 0x1001B470
// Name: class Vector __near & AllocTempVector(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl AllocTempVector()
{
  int v0; // eax
  volatile int m_value; // edx
  unsigned __int16 v2; // cx
  volatile int v3; // edx

  v0 = `AllocTempVector'::`2'::`local static guard';
  if ( (`AllocTempVector'::`2'::`local static guard' & 1) == 0 )
  {
    v0 = `AllocTempVector'::`2'::`local static guard' | 1;
    `AllocTempVector'::`2'::`local static guard' |= 1u;
  }
  if ( (v0 & 2) == 0 )
  {
    `AllocTempVector'::`2'::`local static guard' = v0 | 2;
    `AllocTempVector'::`2'::s_nIndex.m_value = 0;
  }
  m_value = `AllocTempVector'::`2'::s_nIndex.m_value;
  v2 = (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F;
  if ( _InterlockedCompareExchange(
         &`AllocTempVector'::`2'::s_nIndex.m_value,
         (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F,
         `AllocTempVector'::`2'::s_nIndex.m_value) != m_value )
  {
    do
    {
      _mm_pause();
      v3 = `AllocTempVector'::`2'::s_nIndex.m_value;
      v2 = (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F;
    }
    while ( _InterlockedCompareExchange(
              &`AllocTempVector'::`2'::s_nIndex.m_value,
              (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F,
              `AllocTempVector'::`2'::s_nIndex.m_value) != v3 );
  }
  return &`AllocTempVector'::`2'::s_vecTemp[v2];
}

//------------------------------------------------------------------------------
// Address: 0x1001B500
// Name: public: bool CBasePropDoor::IsNPCOpening(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePropDoor::IsNPCOpening(CBasePropDoor *this, CAI_BaseNPC *pNPC)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hActivator.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return pNPC == nullptr;
  else
    return pNPC == g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1001B550
// Name: public: bool CJob::WaitForFinishAndRelease(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CJob::WaitForFinishAndRelease(CJob *this, unsigned int dwTimeout)
{
  int m_status; // eax
  bool v5; // bl
  CJob *v6; // [esp+4h] [ebp-4h] BYREF

  if ( this == nullptr )
    return 1;
  m_status = this->m_status;
  if ( m_status == 1 || m_status == 2 || m_status == 4 )
  {
    v6 = this;
    v5 = _g_pThreadPool->YieldWait(this: _g_pThreadPool, a2: &v6, a3: 1, a4: true, a5: dwTimeout) != 258;
    this->Release(this);
    return v5;
  }
  else
  {
    this->Release(this);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B5D0
// Name: bool AIStrongOpt(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AIStrongOpt()
{
  return ai_strong_optimizations.m_pParent != nullptr && ai_strong_optimizations.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B5F0
// Name: public: virtual bool CAI_BaseNPC::OnBehaviorChangeStatus(class CAI_BehaviorBase __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::OnBehaviorChangeStatus(
        CAI_BaseNPC *this,
        CAI_BehaviorBase *pBehavior,
        bool fCanFinishSchedule)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // edi

  if ( pBehavior != this->m_pPrimaryBehavior || pBehavior->CanSelectSchedule(this: pBehavior) || fCanFinishSchedule )
    return 0;
  m_pPrimaryBehavior = this->m_pPrimaryBehavior;
  this->m_pPrimaryBehavior = nullptr;
  if ( m_pPrimaryBehavior != nullptr )
  {
    m_pPrimaryBehavior->EndScheduleSelection(this: m_pPrimaryBehavior);
    CAI_BaseNPC::VacateStrategySlot(this);
    this->OnChangeRunningBehavior(this, a2: m_pPrimaryBehavior, a3: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001B670
// Name: public: virtual enum Activity CAI_BaseNPC::GetFlinchActivity(bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::GetFlinchActivity(CAI_BaseNPC *this, bool bHeavyDamage, bool bGesture)
{
  bool v4; // bl
  Activity v5; // esi

  switch ( this->m_LastHitGroup )
  {
    case 1:
      v4 = bGesture;
      v5 = bGesture ? ACT_GESTURE_FLINCH_HEAD : ACT_FLINCH_HEAD;
      break;
    case 2:
      v4 = bGesture;
      v5 = bGesture ? ACT_GESTURE_FLINCH_CHEST : ACT_FLINCH_CHEST;
      break;
    case 3:
      v4 = bGesture;
      v5 = bGesture ? ACT_GESTURE_FLINCH_STOMACH : ACT_FLINCH_STOMACH;
      break;
    case 4:
      v4 = bGesture;
      v5 = bGesture ? ACT_GESTURE_FLINCH_LEFTARM : ACT_FLINCH_LEFTARM;
      break;
    case 5:
      v4 = bGesture;
      v5 = bGesture ? ACT_GESTURE_FLINCH_RIGHTARM : ACT_FLINCH_RIGHTARM;
      break;
    case 6:
      v4 = bGesture;
      v5 = bGesture ? ACT_GESTURE_FLINCH_LEFTLEG : ACT_FLINCH_LEFTLEG;
      break;
    case 7:
      v4 = bGesture;
      v5 = bGesture ? ACT_GESTURE_FLINCH_RIGHTLEG : ACT_FLINCH_RIGHTLEG;
      break;
    default:
      v4 = bGesture;
      if ( bHeavyDamage )
        v5 = bGesture ? ACT_GESTURE_BIG_FLINCH : ACT_BIG_FLINCH;
      else
        v5 = bGesture ? ACT_GESTURE_SMALL_FLINCH : ACT_SMALL_FLINCH;
      break;
  }
  if ( CBaseAnimating::SelectWeightedSequence(this, activity: v5) == -1
    && (!bHeavyDamage
     || (v5 = v4 ? ACT_GESTURE_BIG_FLINCH : ACT_BIG_FLINCH,
         CBaseAnimating::SelectWeightedSequence(this, activity: v5) == -1)) )
  {
    return v4 ? 152 : 63;
  }
  else
  {
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B7A0
// Name: public: virtual void CAI_BaseNPC::OnFriendDamaged(class CBaseCombatCharacter __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnFriendDamaged(
        CAI_BaseNPC *this,
        CBaseCombatCharacter *pSquadmate,
        CBaseEntity *pAttacker)
{
  float v4; // xmm0_4

  if ( this->m_SleepState != AISS_WAITING_FOR_INPUT )
  {
    if ( (pAttacker->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pAttacker);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    v4 = (float)((float)((float)(this->m_vecAbsOrigin.x - pAttacker->m_vecAbsOrigin.x)
                       * (float)(this->m_vecAbsOrigin.x - pAttacker->m_vecAbsOrigin.x))
               + (float)((float)(this->m_vecAbsOrigin.y - pAttacker->m_vecAbsOrigin.y)
                       * (float)(this->m_vecAbsOrigin.y - pAttacker->m_vecAbsOrigin.y)))
       + (float)((float)(this->m_vecAbsOrigin.z - pAttacker->m_vecAbsOrigin.z)
               * (float)(this->m_vecAbsOrigin.z - pAttacker->m_vecAbsOrigin.z));
    if ( this->m_SleepState != AISS_AWAKE && v4 < 57600.0 )
      this->Wake(this, a2: true);
    if ( v4 < 360000.0 )
    {
      this->m_bForceConditionsGather = true;
      this->m_Efficiency = AIE_NORMAL;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B880
// Name: public: virtual bool CAI_BaseNPC::IsLightDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsLightDamage(CAI_BaseNPC *this, const CTakeDamageInfo *info)
{
  return info->m_flDamage > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B8B0
// Name: public: virtual bool CAI_BaseNPC::IsHeavyDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsHeavyDamage(CAI_BaseNPC *this, const CTakeDamageInfo *info)
{
  return info->m_flDamage > 20.0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B8E0
// Name: public: bool CAI_BaseNPC::PointInSpread(class CBaseCombatCharacter __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::PointInSpread(
        CAI_BaseNPC *this,
        CBaseCombatCharacter *pCheckEntity,
        const Vector *sourcePos,
        const Vector2D *targetPos,
        const Vector *testPoint,
        float flSpread,
        float maxDistOffCenter)
{
  float v8; // xmm0_4
  Vector toTarget; // [esp+Ch] [ebp-18h] BYREF
  Vector toTest; // [esp+18h] [ebp-Ch] BYREF
  float flBBoxDist; // [esp+34h] [ebp+10h]
  float flBBoxDista; // [esp+34h] [ebp+10h]

  if ( (double)maxDistOffCenter <= CalcDistanceToLine2D(
                                     P: (const Vector2D *)testPoint,
                                     vLineA: (const Vector2D *)sourcePos,
                                     vLineB: targetPos,
                                     outT: nullptr) )
    return false;
  toTarget.x = targetPos->x - sourcePos->x;
  toTarget.y = targetPos->y - sourcePos->y;
  toTarget.z = targetPos[1].x - sourcePos->z;
  flBBoxDist = VectorNormalize(vec: &toTarget);
  toTest.x = testPoint->x - sourcePos->x;
  toTest.y = testPoint->y - sourcePos->y;
  toTest.z = testPoint->z - sourcePos->z;
  if ( (double)flBBoxDist <= VectorNormalize(vec: &toTest) )
    return false;
  v8 = (float)(toTest.x * toTarget.x) + (float)(toTest.y * toTarget.y);
  toTarget.z = 0.0;
  toTest.z = 0.0;
  if ( v8 > flSpread )
    return true;
  return v8 > 0.0
      && pCheckEntity != nullptr
      && (double)(flBBoxDista = NAI_Hull::Width(id: pCheckEntity->m_eHull) * 1.414) > CalcDistanceToLine(
                                                                                        P: testPoint,
                                                                                        vLineA: sourcePos,
                                                                                        vLineB: (const Vector *)targetPos,
                                                                                        outT: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1001BA00
// Name: public: virtual bool CAI_BaseNPC::PlayerInSpread(class Vector const __near &,class Vector const __near &,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::PlayerInSpread(
        CAI_BaseNPC *this,
        const Vector *sourcePos,
        const Vector *targetPos,
        float flSpread,
        float maxDistOffCenter,
        bool ignoreHatedPlayers)
{
  int v6; // esi
  int *v8; // ebx
  const Vector *v9; // esi
  float v10; // xmm0_4
  Vector v12; // [esp+Ch] [ebp-20h] BYREF
  Vector vec; // [esp+18h] [ebp-14h] BYREF
  CAI_BaseNPC *v14; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]
  float sourcePosa; // [esp+34h] [ebp+8h]
  float sourcePosb; // [esp+34h] [ebp+8h]

  v6 = 1;
  v14 = this;
  i = 1;
  if ( gpGlobals->maxClients < 1 )
    return 0;
  while ( 1 )
  {
    v8 = (int *)UTIL_PlayerByIndex(playerIndex: v6);
    if ( v8 != nullptr && (!ignoreHatedPlayers || v14->IRelationType(this: v14, a2: (CBaseEntity *)v8) != D_HT) )
    {
      v9 = (const Vector *)(*(int (__thiscall **)(int *))(*v8 + 588))(a1: v8);
      if ( (double)maxDistOffCenter > CalcDistanceToLine2D(
                                        P: (const Vector2D *)v9,
                                        vLineA: (const Vector2D *)sourcePos,
                                        vLineB: (const Vector2D *)targetPos,
                                        outT: nullptr) )
      {
        vec.x = targetPos->x - sourcePos->x;
        vec.y = targetPos->y - sourcePos->y;
        vec.z = targetPos->z - sourcePos->z;
        sourcePosa = VectorNormalize(&vec);
        v12.x = v9->x - sourcePos->x;
        v12.y = v9->y - sourcePos->y;
        v12.z = v9->z - sourcePos->z;
        if ( (double)sourcePosa > VectorNormalize(vec: &v12) )
        {
          v10 = (float)(v12.x * vec.x) + (float)(vec.y * v12.y);
          vec.z = 0.0;
          v12.z = 0.0;
          if ( v10 > flSpread )
            break;
          if ( v10 > 0.0 )
          {
            sourcePosb = NAI_Hull::Width(id: v8[418]) * 1.414;
            if ( (double)sourcePosb > CalcDistanceToLine(P: v9, vLineA: sourcePos, vLineB: targetPos, outT: nullptr) )
              break;
          }
        }
      }
      v6 = i;
    }
    i = ++v6;
    if ( v6 > gpGlobals->maxClients )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001BB90
// Name: public: void CBaseEntity::TraceAttackToTriggers(class CTakeDamageInfo const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseEntity::TraceAttackToTriggers(
        CBaseEntity *this@<ecx>,
        int a2@<ebp>,
        const CTakeDamageInfo *info,
        const Vector *start,
        const Vector *end,
        const Vector *dir)
{
  int x_low; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  __int64 v11; // xmm0_8
  float v12; // eax
  _DWORD v13[3]; // [esp-Ch] [ebp-D4h] BYREF
  CTriggerTraceEnum triggerTraceEnum; // [esp+0h] [ebp-C8h] BYREF
  float v15; // [esp+74h] [ebp-54h]
  Ray_t ray; // [esp+78h] [ebp-50h] BYREF
  _UNKNOWN *retaddr; // [esp+C8h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a2;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  x_low = LODWORD(start->x);
  y = start->y;
  z = start->z;
  v9 = end->z;
  v10 = end->x - start->x;
  ray.m_Start.z = end->y - y;
  ray.m_Start.y = v10;
  ray.m_Start.w = v9 - z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z) + (float)(v10 * v10))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  ray.m_Extents.y = 0.0;
  memset(&ray.m_StartOffset.y, 0, 12);
  memset(&ray.m_Delta.y, 0, 12);
  v11 = *(_QWORD *)&dir->x;
  v12 = dir->z;
  LODWORD(triggerTraceEnum.m_VecDir.y) = &triggerTraceEnum.m_info.m_iObjectsPenetrated;
  LOBYTE(ray.m_Extents.z) = 1;
  triggerTraceEnum.m_info.m_iObjectsPenetrated = x_low;
  *(float *)&triggerTraceEnum.m_info.m_uiBulletID = y;
  v15 = z;
  v13[0] = &CTriggerTraceEnum::`vftable';
  *(_QWORD *)&v13[1] = v11;
  *(float *)&triggerTraceEnum.__vftable = v12;
  triggerTraceEnum.m_VecDir.x = 8208.0029;
  CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&triggerTraceEnum.m_VecDir.z, __that: info);
  enginetrace->EnumerateEntities_2(
    this: enginetrace,
    a2: (const Ray_t *)&triggerTraceEnum.m_info.m_iObjectsPenetrated,
    a3: true,
    a4: (IEntityEnumerator *)v13);
}

//------------------------------------------------------------------------------
// Address: 0x1001BCB0
// Name: private: void CBaseEntity::UpdateShotStatistics(class CGameTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::UpdateShotStatistics(CBaseEntity *this, const CGameTrace *tr)
{
  CAI_BaseNPC *v2; // esi
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // edx

  if ( ai_shot_stats.m_pParent != nullptr && ai_shot_stats.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = this->MyNPCPointer(this);
    if ( v2 != nullptr )
    {
      GetEnemy_2 = v2->GetEnemy_2;
      ++v2->m_TotalShots;
      if ( tr->m_pEnt == GetEnemy_2(this: v2) )
        ++v2->m_TotalHits;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BD00
// Name: public: ServerClass::ServerClass(char __near *,class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall ServerClass::ServerClass(ServerClass *this, char *pNetworkName, SendTable *pTable)
{
  ServerClass *v4; // edi
  ServerClass *m_pNext; // esi

  this->m_pNetworkName = pNetworkName;
  this->m_pTable = pTable;
  this->m_InstanceBaselineIndex = 0xFFFF;
  v4 = g_pServerClassHead;
  if ( g_pServerClassHead != nullptr )
  {
    m_pNext = g_pServerClassHead->m_pNext;
    if ( _V_stricmp(s1: g_pServerClassHead->m_pNetworkName, s2: pNetworkName) <= 0 )
    {
      while ( m_pNext != nullptr && _V_stricmp(s1: m_pNext->m_pNetworkName, s2: pNetworkName) <= 0 )
      {
        v4 = m_pNext;
        m_pNext = m_pNext->m_pNext;
      }
      this->m_pNext = m_pNext;
      v4->m_pNext = this;
      return this;
    }
    else
    {
      this->m_pNext = g_pServerClassHead;
      g_pServerClassHead = this;
      return this;
    }
  }
  else
  {
    g_pServerClassHead = this;
    this->m_pNext = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BDA0
// Name: void UTIL_TraceLine(class Vector const __near &,class Vector const __near &,unsigned int,class IHandleEntity const __near *,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_TraceLine(
        const IHandleEntity *a1@<ebp>,
        int a2@<esi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        const IHandleEntity *ignore,
        int collisionGroup,
        CGameTrace *ptr)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  _DWORD v13[3]; // [esp+24h] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+30h] [ebp-60h] BYREF
  CTraceFilterSimple traceFilter; // [esp+80h] [ebp-10h]
  int retaddr; // [esp+90h] [ebp+0h]

  traceFilter.m_pPassEnt = a1;
  traceFilter.m_collisionGroup = retaddr;
  x = vecAbsStart->x;
  y = vecAbsStart->y;
  z = vecAbsStart->z;
  v11 = vecAbsEnd->z;
  v12 = vecAbsEnd->x - vecAbsStart->x;
  ray.m_Start.z = vecAbsEnd->y - y;
  ray.m_Start.y = v12;
  ray.m_Start.w = v11 - z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z) + (float)(v12 * v12))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_Delta.y, 0, 12);
  *(float *)v13 = x;
  *(float *)&v13[1] = y;
  *(float *)&v13[2] = z;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&ray.m_IsRay,
    passedict: ignore,
    collisionGroup,
    pExtraShouldHitFunc: nullptr);
  ((void (__thiscall *)(IEngineTrace *, _DWORD *, unsigned int, bool *, CGameTrace *, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: v13,
    a3: mask,
    a4: &ray.m_IsRay,
    a5: ptr,
    a6: a2);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &ptr->startpos, vecAbsEnd: &ptr->endpos, r: 255, g: 0, b: 0, test: true, duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1001BED0
// Name: void UTIL_TraceLine(class Vector const __near &,class Vector const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_TraceLine(
        int a1@<ebp>,
        int a2@<esi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        ITraceFilter *pFilter,
        CGameTrace *ptr)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  _DWORD v12[3]; // [esp+24h] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+30h] [ebp-50h] BYREF
  _UNKNOWN *retaddr; // [esp+80h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a1;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  x = vecAbsStart->x;
  y = vecAbsStart->y;
  z = vecAbsStart->z;
  v10 = vecAbsEnd->z;
  v11 = vecAbsEnd->x - vecAbsStart->x;
  ray.m_Start.z = vecAbsEnd->y - y;
  ray.m_Start.y = v11;
  ray.m_Start.w = v10 - z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z) + (float)(v11 * v11))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_Delta.y, 0, 12);
  *(float *)v12 = x;
  *(float *)&v12[1] = y;
  *(float *)&v12[2] = z;
  ((void (__thiscall *)(IEngineTrace *, _DWORD *, unsigned int, ITraceFilter *, CGameTrace *, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: v12,
    a3: mask,
    a4: pFilter,
    a5: ptr,
    a6: a2);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &ptr->startpos, vecAbsEnd: &ptr->endpos, r: 255, g: 0, b: 0, test: true, duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1001BFF0
// Name: void UTIL_TraceHull(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned int,class IHandleEntity const __near *,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_TraceHull(
        const IHandleEntity *a1@<ebp>,
        int a2@<esi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        const Vector *hullMin,
        const Vector *hullMax,
        unsigned int mask,
        const IHandleEntity *ignore,
        int collisionGroup,
        CGameTrace *ptr)
{
  _BYTE v10[12]; // [esp+24h] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+30h] [ebp-60h] BYREF
  CTraceFilterSimple traceFilter; // [esp+80h] [ebp-10h]
  int retaddr; // [esp+90h] [ebp+0h]

  traceFilter.m_pPassEnt = a1;
  traceFilter.m_collisionGroup = retaddr;
  ray.m_Extents.y = 0.0;
  Ray_t::Init(this: (Ray_t *)v10, start: vecAbsStart, end: vecAbsEnd, mins: hullMin, maxs: hullMax);
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&ray.m_IsRay,
    passedict: ignore,
    collisionGroup,
    pExtraShouldHitFunc: nullptr);
  ((void (__thiscall *)(IEngineTrace *, _BYTE *, unsigned int, bool *, CGameTrace *, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: v10,
    a3: mask,
    a4: &ray.m_IsRay,
    a5: ptr,
    a6: a2);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: &ptr->startpos,
      vecAbsEnd: &ptr->endpos,
      r: 255,
      g: 255,
      b: 0,
      test: true,
      duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1001C0A0
// Name: void UTIL_TraceHull(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_TraceHull(
        int a1@<ebp>,
        int a2@<esi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        const Vector *hullMin,
        const Vector *hullMax,
        unsigned int mask,
        ITraceFilter *pFilter,
        CGameTrace *ptr)
{
  _BYTE v9[12]; // [esp+24h] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+30h] [ebp-50h]
  _UNKNOWN *retaddr; // [esp+80h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a1;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  ray.m_Extents.y = 0.0;
  Ray_t::Init(this: (Ray_t *)v9, start: vecAbsStart, end: vecAbsEnd, mins: hullMin, maxs: hullMax);
  ((void (__thiscall *)(IEngineTrace *, _BYTE *, unsigned int, ITraceFilter *, CGameTrace *, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: v9,
    a3: mask,
    a4: pFilter,
    a5: ptr,
    a6: a2);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: &ptr->startpos,
      vecAbsEnd: &ptr->endpos,
      r: 255,
      g: 255,
      b: 0,
      test: true,
      duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1001C140
// Name: private: void CAI_BaseNPC::LockBestSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::LockBestSound(CAI_BaseNPC *this)
{
  CSound *m_pLockedBestSound; // eax
  const CSound *v3; // eax

  m_pLockedBestSound = this->m_pLockedBestSound;
  if ( m_pLockedBestSound->m_iType != 0 )
  {
    m_pLockedBestSound->m_iType = 0;
    this->OnListened(this);
  }
  v3 = this->GetBestSound(this, a2: 1048351);
  if ( v3 != nullptr )
    CSound::operator=(this: this->m_pLockedBestSound, __that: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1001C190
// Name: public: bool CAI_BaseNPC::SoundIsVisible(class CSound __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::SoundIsVisible(CAI_BaseNPC *this, CSound *pSound)
{
  CAI_BaseNPC_vtbl *v3; // edi
  const Vector *SoundReactOrigin; // eax
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax
  bool result; // al
  CBaseEntity *pBlocker; // [esp+Ch] [ebp-4h] BYREF

  v3 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  pBlocker = nullptr;
  SoundReactOrigin = CSound::GetSoundReactOrigin(this: pSound);
  result = true;
  if ( !v3->FVisible(this, a2: SoundReactOrigin, a3: 16449, a4: &pBlocker) )
  {
    if ( pBlocker == nullptr )
      return false;
    m_Index = pSound->m_hOwner.m_Index;
    if ( pSound->m_hOwner.m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    if ( pBlocker != m_pEntity )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C210
// Name: public: virtual bool CAI_BaseNPC::FInAimCone(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::FInAimCone(CAI_BaseNPC *this, const Vector *vecSpot)
{
  double v3; // xmm0_8
  Vector facingDir; // [esp+4h] [ebp-18h] BYREF
  Vector los; // [esp+10h] [ebp-Ch] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  los.x = vecSpot->x - this->m_vecAbsOrigin.x;
  los.y = vecSpot->y - this->m_vecAbsOrigin.y;
  los.z = 0.0;
  VectorNormalize(vec: &los);
  this->BodyDirection2D(this, result: &facingDir);
  v3 = (float)((float)((float)(los.x * facingDir.x) + (float)(facingDir.y * los.y)) + (float)(facingDir.z * los.z));
  if ( (this->CapabilitiesGet(this) & 0x20000000) != 0 )
    return v3 > 0.8660254037839999;
  else
    return v3 > 0.994;
}

//------------------------------------------------------------------------------
// Address: 0x1001C300
// Name: private: void CAI_BaseNPC::PostMovement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::PostMovement(CAI_BaseNPC *this)
{
  CStudioHdr *m_pStudioHdr; // ecx
  float flInterval; // [esp+8h] [ebp-4h]

  this->InvalidateBoneCache(this);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && CStudioHdr::SequencesAvailable(this: m_pStudioHdr) )
  {
    flInterval = CBaseAnimating::GetAnimTimeInterval(this);
    if ( (this->CapabilitiesGet(this) & 0x20000000) != 0 )
    {
      this->AimGun(this);
    }
    else
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      this->m_flInteractionYaw = this->m_angAbsRotation.y;
    }
    if ( (this->CapabilitiesGet(this) & 0x800000) != 0 )
      ((void (__thiscall *)(CAI_BaseNPC *, _DWORD))this->MaintainLookTargets)(a1: this, a2: LODWORD(flInterval));
  }
  this->MaintainTurnActivity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001C3D0
// Name: public: class CBaseEntity __near * CTakeDamageInfo::GetInflictor(void)const
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CTakeDamageInfo::GetInflictor(CTakeDamageInfo *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1001C400
// Name: public: void CTakeDamageInfo::SetInflictor(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTakeDamageInfo::SetInflictor(CTakeDamageInfo *this, CBaseEntity *pInflictor)
{
  if ( pInflictor != nullptr )
    this->m_hInflictor.m_Index = pInflictor->GetRefEHandle(this: pInflictor)->m_Index;
  else
    this->m_hInflictor.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001C430
// Name: public: void CTakeDamageInfo::SetAttacker(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTakeDamageInfo::SetAttacker(CTakeDamageInfo *this, CBaseEntity *pAttacker)
{
  if ( pAttacker != nullptr )
    this->m_hAttacker.m_Index = pAttacker->GetRefEHandle(this: pAttacker)->m_Index;
  else
    this->m_hAttacker.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001C460
// Name: private: void CAI_BaseNPC::RunAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RunAnimation(CAI_BaseNPC *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  NPC_STATE m_NPCState; // eax
  int v4; // eax
  int v5; // edi
  const char *SequenceName; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CAI_BaseNPC_RunAnimation",
    a3: 0,
    a4: "Server Animation",
    a5: false,
    a6: 4);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    CBaseAnimating::GetAnimTimeInterval(this);
    this->StudioFrameAdvance(this);
    if ( (CAI_BaseNPC::m_nDebugBits & 2) != 0 )
      CAI_Navigator::IsGoalActive(this: this->m_pNavigator);
    m_NPCState = this->m_NPCState;
    if ( m_NPCState != NPC_STATE_SCRIPT
      && m_NPCState != NPC_STATE_DEAD
      && this->m_Activity == ACT_IDLE
      && this->IsActivityFinished(this) )
    {
      v4 = this->m_bSequenceLoops
         ? CBaseAnimating::SelectWeightedSequence(this, activity: this->m_translatedActivity)
         : CBaseAnimating::SelectHeaviestSequence(this, activity: this->m_translatedActivity);
      v5 = v4;
      if ( v4 != -1 )
      {
        if ( ai_sequence_debug.m_pParent != nullptr
          && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
          && (this->m_debugOverlays & 0x1000) != 0 )
        {
          SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: v4);
          DevMsg(a1: "RunAnimation calling ResetSequence %s\n", SequenceName);
        }
        CBaseAnimating::ResetSequence(this, nSequence: v5);
        if ( hl2_episodic.m_pParent != nullptr && hl2_episodic.m_pParent->m_Value.m_nValue != 0 )
          this->m_nIdealSequence = v5;
      }
    }
    this->DispatchAnimEvents(this, a2: this);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C5B0
// Name: public: variant_t::variant_t(class variant_t const __near &)
// Source: json
//------------------------------------------------------------------------------
variant_t *__thiscall variant_t::variant_t(variant_t *this, const variant_t *__that)
{
  this->iszVal = __that->iszVal;
  this->iVal = __that->iVal;
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001C5F0
// Name: private: bool CAI_BaseNPC::PreNPCThink(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::PreNPCThink(CAI_BaseNPC *this)
{
  bool v2; // al
  int framecount; // eax
  double v5; // st7
  float v6; // xmm0_4
  int v7; // ecx
  float m_flLastRealThinkTime; // xmm0_4
  float timescale; // [esp+Ch] [ebp-4h]

  v2 = !this->m_bInChoreo
    && ai_use_think_optimizations.m_pParent != nullptr
    && ai_use_think_optimizations.m_pParent->m_Value.m_nValue != 0
    && ai_use_frame_think_limits.m_pParent != nullptr
    && ai_use_frame_think_limits.m_pParent->m_Value.m_nValue != 0;
  g_StartTimeCurThink = 0.0;
  if ( !v2 )
    return 1;
  framecount = gpGlobals->framecount;
  if ( this->m_iFrameBlocked == framecount )
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    return 0;
  }
  if ( framecount != iPrevFrame )
  {
    v5 = ((double (__thiscall *)(IVEngineServer *))engine->GetTimescale)(a1: engine);
    if ( v5 >= 1.0 )
    {
      timescale = v5;
      v6 = timescale;
    }
    else
    {
      v6 = 1.0;
    }
    v7 = gpGlobals->framecount;
    frameTimeLimit = v6 * 0.0099999998;
    iPrevFrame = v7;
    g_NpcTimeThisFrame = 0.0;
  }
  else if ( g_NpcTimeThisFrame > 0.0099999998 && (float)(gpGlobals->curtime - this->m_flLastRealThinkTime) <= 0.25 )
  {
    this->m_iFrameBlocked = framecount;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    return 0;
  }
  g_StartTimeCurThink = _Plat_FloatTime();
  m_flLastRealThinkTime = this->m_flLastRealThinkTime;
  this->m_iFrameBlocked = -1;
  this->m_nLastThinkTick = (int)(float)((float)(m_flLastRealThinkTime / gpGlobals->interval_per_tick) + 0.5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001C760
// Name: public: void CAI_BaseNPC::NotifyPushMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::NotifyPushMove(CAI_BaseNPC *this)
{
  this->m_CheckOnGroundTimer.m_next = gpGlobals->curtime + 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x1001C780
// Name: public: float CAI_BaseNPC::EnemyDistance(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CAI_BaseNPC::EnemyDistance@<st0>(
        CAI_BaseNPC *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseEntity *pEnemy)
{
  const Vector *v5; // eax
  Vector *v6; // eax
  float v7; // xmm0_4
  Vector *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v14; // [esp-Ch] [ebp-28h]
  float v15; // [esp-8h] [ebp-24h]
  float v16; // [esp-4h] [ebp-20h]
  float *v17; // [esp+Ch] [ebp-10h]
  float v18; // [esp+Ch] [ebp-10h]

  v17 = (float *)((int (__thiscall *)(CAI_BaseNPC *, int, int))this->WorldSpaceCenter)(a1: this, a2, a3);
  v5 = pEnemy->WorldSpaceCenter(this: pEnemy);
  v14 = v5->x - *v17;
  v15 = v5->y - v17[1];
  v16 = v5->z - v17[2];
  v6 = AllocTempVector();
  v6->x = pEnemy->m_Collision.m_vecMaxs.m_Value.x - pEnemy->m_Collision.m_vecMins.m_Value.x;
  v6->y = pEnemy->m_Collision.m_vecMaxs.m_Value.y - pEnemy->m_Collision.m_vecMins.m_Value.y;
  v7 = pEnemy->m_Collision.m_vecMaxs.m_Value.z - pEnemy->m_Collision.m_vecMins.m_Value.z;
  v6->z = v7;
  v18 = v7;
  v8 = AllocTempVector();
  v8->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
  v8->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
  v9 = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
  v8->z = v9;
  v10 = (float)(v9 + v18) * 0.5;
  if ( v16 <= v10 )
  {
    if ( COERCE_FLOAT(LODWORD(v10) ^ _mask__NegFloat_) <= v16 )
      v11 = 0.0;
    else
      v11 = v16 + v10;
  }
  else
  {
    v11 = v16 - v10;
  }
  return fsqrt((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v11 * v11));
}

//------------------------------------------------------------------------------
// Address: 0x1001C8F0
// Name: public: void CAI_BaseNPC::SetEnemyOccluder(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetEnemyOccluder(CAI_BaseNPC *this, CBaseEntity *pBlocker)
{
  if ( pBlocker != nullptr )
    this->m_hEnemyOccluder.m_Index = pBlocker->GetRefEHandle(this: pBlocker)->m_Index;
  else
    this->m_hEnemyOccluder.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001C920
// Name: protected: virtual float CAI_BaseNPC::GetGoalRepathTolerance(class CBaseEntity __near *,enum GoalType_t,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CAI_BaseNPC::GetGoalRepathTolerance@<st0>(
        CAI_BaseNPC *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        CBaseEntity *pGoalEnt,
        GoalType_t type,
        const Vector *curGoal,
        const Vector *curTargetPos)
{
  CAI_Navigator *m_pNavigator; // ecx
  __int128 v9; // xmm0
  double ArrivalDistance; // st7
  Vector *(__thiscall *GetSmoothedVelocity)(CBaseEntity *, Vector *); // edx
  float *v12; // eax
  __int128 v13; // xmm0
  float v14; // xmm0_4
  __int128 v18; // [esp-20h] [ebp-2Ch] BYREF
  float v19; // [esp-8h] [ebp-14h]
  float v20; // [esp-4h] [ebp-10h]
  int v21; // [esp+0h] [ebp-Ch]
  float distToGoal; // [esp+4h] [ebp-8h]
  float retaddr; // [esp+Ch] [ebp+0h]

  v21 = a2;
  distToGoal = retaddr;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  m_pNavigator = this->m_pNavigator;
  v9 = 0;
  *(float *)&v9 = fsqrt(
                    (float)((float)((float)(this->m_vecAbsOrigin.y - curTargetPos->y)
                                  * (float)(this->m_vecAbsOrigin.y - curTargetPos->y))
                          + (float)((float)(this->m_vecAbsOrigin.z - curTargetPos->z)
                                  * (float)(this->m_vecAbsOrigin.z - curTargetPos->z)))
                  + (float)((float)(this->m_vecAbsOrigin.x - curTargetPos->x)
                          * (float)(this->m_vecAbsOrigin.x - curTargetPos->x)));
  v18 = v9;
  ArrivalDistance = CAI_Navigator::GetArrivalDistance(this: m_pNavigator);
  GetSmoothedVelocity = this->GetSmoothedVelocity;
  v19 = *(float *)&v9 - ArrivalDistance;
  v12 = (float *)((int (__thiscall *)(CAI_BaseNPC *, char *, int))GetSmoothedVelocity)(
                   a1: this,
                   a2: (char *)&v18 + 4,
                   a3);
  v13 = 0;
  *(float *)&v13 = fsqrt((float)((float)(*v12 * *v12) + (float)(v12[1] * v12[1])) + (float)(v12[2] * v12[2]));
  v18 = v13;
  v20 = 120.0;
  if ( *(float *)&v13 > 0.0 )
  {
    v14 = (float)(v19 / *(float *)&v18) * 120.0;
    if ( v14 >= 0.0 )
    {
      if ( v14 <= 120.0 )
        v20 = (float)(v19 / *(float *)&v18) * 120.0;
      else
        v20 = 120.0;
    }
    else
    {
      v20 = 0.0;
    }
  }
  if ( !pGoalEnt->IsPlayer(this: pGoalEnt) )
    return (float)(v20 * 1.2);
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x1001CA70
// Name: public: class CBaseEntity __near * CBaseEntity::GetMoveParent(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::GetMoveParent(CBaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1001CAA0
// Name: public: class CBaseEntity __near * CAI_BaseNPC::GetNavTargetEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_BaseNPC::GetNavTargetEntity(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx

  if ( CAI_Navigator::GetGoalType(this: this->m_pNavigator) == GOALTYPE_ENEMY )
  {
    m_Index = this->m_hEnemy.m_Index;
  }
  else
  {
    if ( CAI_Navigator::GetGoalType(this: this->m_pNavigator) != GOALTYPE_TARGETENT )
      return nullptr;
    m_Index = this->m_hTargetEnt.m_Index;
  }
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001CB00
// Name: public: void CBaseEntity::AddSolidFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::AddSolidFlags(CBaseEntity *this, int flags)
{
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: flags | this->m_Collision.m_usSolidFlags.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x1001CB20
// Name: public: bool CBaseEntity::IsSolid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseEntity::IsSolid(CBaseEntity *this)
{
  return this->m_Collision.m_nSolidType.m_Value != 0 && (this->m_Collision.m_usSolidFlags.m_Value & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CB40
// Name: public: class Vector const __near & CBaseEntity::WorldAlignSize(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::WorldAlignSize(CBaseEntity *this)
{
  const Vector *result; // eax

  result = AllocTempVector();
  result->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
  result->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
  result->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001CB90
// Name: public: virtual void CAI_BaseNPC::OnChangeActiveWeapon(class CBaseCombatWeapon __near *,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnChangeActiveWeapon(
        CAI_BaseNPC *this,
        CBaseCombatWeapon *pOldWeapon,
        CBaseCombatWeapon *pNewWeapon)
{
  if ( pNewWeapon != nullptr )
  {
    this->OnUpdateShotRegulator(this);
    CAI_ShotRegulator::Reset(this: &this->m_ShotRegulator, bStartShooting: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CBC0
// Name: public: virtual void CAI_BaseNPC::RemoveMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RemoveMemory(CAI_BaseNPC *this)
{
  CAI_Enemies *m_pEnemies; // esi

  m_pEnemies = this->m_pEnemies;
  if ( m_pEnemies != nullptr )
  {
    CAI_Enemies::~CAI_Enemies(this: this->m_pEnemies);
    free(pMem: m_pEnemies);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CBE0
// Name: public: virtual void CAI_BaseNPC::ChangeFaction(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ChangeFaction(CAI_BaseNPC *this, AIEnemiesIter_t__ *nNewFaction)
{
  CAI_Enemies *v3; // eax
  AI_EnemyInfo_t *First; // eax
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // esi
  CAI_Enemies *v7; // eax
  AI_EnemyInfo_t *Next; // ebx
  CAI_Enemies *v9; // eax

  CBaseCombatCharacter::ChangeFaction(this, (int)nNewFaction);
  v3 = this->GetEnemies(this);
  First = CAI_Enemies::GetFirst(this: v3, pIter: &nNewFaction);
  if ( First != nullptr )
  {
    do
    {
      m_Index = First->hEnemy.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v7 = this->GetEnemies(this);
      Next = CAI_Enemies::GetNext(this: v7, pIter: &nNewFaction);
      if ( m_pEntity != nullptr && this->IRelationType(this, a2: m_pEntity) == D_LI )
      {
        v9 = this->GetEnemies(this);
        CAI_Enemies::ClearMemory(this: v9, pEnemy: m_pEntity);
      }
      First = Next;
    }
    while ( Next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CC90
// Name: public: virtual bool CAI_BaseNPC::IsValidEnemy(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::IsValidEnemy(CAI_BaseNPC *this, CBaseEntity *pEnemy)
{
  CAI_BaseNPC *v3; // eax
  char result; // al
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  CBaseFilter *v12; // eax

  v3 = pEnemy->MyNPCPointer(this: pEnemy);
  if ( v3 == nullptr || (result = v3->CanBeAnEnemyOf(this: v3, a2: this)) != 0 )
  {
    m_Index = this->m_hEnemyFilter.m_Index;
    if ( m_Index == -1 )
      return 1;
    v6 = (unsigned __int16)m_Index;
    v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v8 = HIWORD(m_Index);
    if ( v7->m_SerialNumber != v8 || v7->m_pEntity == nullptr )
      return 1;
    v9 = v6;
    v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
    v11 = &g_pEntityList->m_EntPtrArray[v9];
    v12 = v10 ? (CBaseFilter *)v11->m_pEntity : nullptr;
    result = CBaseFilter::PassesFilter(this: v12, pCaller: this, pEntity: pEnemy);
    if ( result != 0 )
      return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001CD20
// Name: public: virtual float CAI_BaseNPC::CalcIdealYaw(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CAI_BaseNPC::CalcIdealYaw(CAI_BaseNPC *this, const Vector *vecTarget)
{
  float v3; // xmm1_4
  float z; // xmm0_4
  float v5; // xmm1_4
  Vector vecProjection; // [esp+4h] [ebp-Ch] BYREF

  if ( CAI_Navigator::GetMovementActivity(this: this->m_pNavigator) == ACT_STRAFE_LEFT )
  {
    v3 = vecTarget->x - this->m_vecOrigin.m_Value.y;
    vecProjection.x = COERCE_FLOAT(LODWORD(vecTarget->y) ^ _mask__NegFloat_) - this->m_vecOrigin.m_Value.x;
    z = vecProjection.z;
    vecProjection.y = v3;
  }
  else if ( CAI_Navigator::GetMovementActivity(this: this->m_pNavigator) == ACT_STRAFE_RIGHT )
  {
    v5 = vecTarget->x - this->m_vecOrigin.m_Value.y;
    vecProjection.x = vecTarget->y - this->m_vecOrigin.m_Value.x;
    z = vecProjection.z;
    vecProjection.y = v5;
  }
  else
  {
    vecProjection.x = vecTarget->x - this->m_vecOrigin.m_Value.x;
    vecProjection.y = vecTarget->y - this->m_vecOrigin.m_Value.y;
    z = vecTarget->z;
  }
  vecProjection.z = z - this->m_vecOrigin.m_Value.z;
  return UTIL_VecToYaw(vec: &vecProjection);
}

//------------------------------------------------------------------------------
// Address: 0x1001CE00
// Name: public: void CAI_BaseNPC::SetDefaultEyeOffset(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BaseNPC::SetDefaultEyeOffset(CAI_BaseNPC *this@<ecx>, int a2@<ebx>)
{
  CStudioHdr *m_pStudioHdr; // eax
  Vector *p_m_vDefaultEyeOffset; // esi
  const char *v5; // eax
  const char *pszValue; // ecx
  const Vector *v7; // eax
  float *v8; // ecx
  float *v9; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    p_m_vDefaultEyeOffset = &this->m_vDefaultEyeOffset;
    this->m_vDefaultEyeOffset = vec3_origin;
LABEL_17:
    this->SetViewOffset(this, a2: p_m_vDefaultEyeOffset);
    return;
  }
  p_m_vDefaultEyeOffset = &this->m_vDefaultEyeOffset;
  GetEyePosition(pstudiohdr: m_pStudioHdr, vecEyePosition: &this->m_vDefaultEyeOffset);
  if ( vec3_origin.x != this->m_vDefaultEyeOffset.x
    || vec3_origin.y != this->m_vDefaultEyeOffset.y
    || vec3_origin.z != this->m_vDefaultEyeOffset.z )
  {
    goto LABEL_17;
  }
  if ( this->Classify(this) != CLASS_NONE )
  {
    v5 = *(const char **)((int (__thiscall *)(CAI_BaseNPC *, float **))this->GetModelName)(a1: this, a2: &v9);
    if ( v5 == nullptr )
      v5 = locale;
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    DevMsg(a1: "WARNING: %s(%s) has no eye offset in .qc!\n", pszValue, v5);
  }
  v9 = (float *)((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int))this->m_Collision.OBBMaxs)(
                  a1: &this->m_Collision,
                  a2);
  v7 = this->m_Collision.OBBMins(this: &this->m_Collision);
  v8 = v9;
  p_m_vDefaultEyeOffset->x = *v9 + v7->x;
  this->m_vDefaultEyeOffset.y = v7->y + v8[1];
  this->m_vDefaultEyeOffset.z = v7->z + v8[2];
  p_m_vDefaultEyeOffset->x = p_m_vDefaultEyeOffset->x * 0.75;
  this->m_vDefaultEyeOffset.y = this->m_vDefaultEyeOffset.y * 0.75;
  this->m_vDefaultEyeOffset.z = this->m_vDefaultEyeOffset.z * 0.75;
  this->SetViewOffset(this, a2: &this->m_vDefaultEyeOffset);
}

//------------------------------------------------------------------------------
// Address: 0x1001CFB0
// Name: public: virtual void CAI_BaseNPC::ReportAIState(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BaseNPC::ReportAIState(CAI_BaseNPC *this@<ecx>, int a2@<edi>)
{
  const char *pszValue; // eax
  NPC_STATE m_NPCState; // eax
  Activity m_Activity; // eax
  const char *ActivityName; // edi
  const char *v7; // eax
  CAI_Schedule *m_pSchedule; // eax
  const char *m_pName; // eax
  const Task_t *Task; // eax
  CBaseEntity *v11; // eax
  float *v12; // edi
  const char *v13; // eax
  float m_flMoveWaitFinished; // xmm0_4
  float curtime; // xmm1_4
  Activity ArrivalActivity; // eax
  const char *v17; // eax
  float v19[3]; // [esp+14h] [ebp-Ch] BYREF

  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  DevMsg(a1: "%s: ", pszValue);
  m_NPCState = this->m_NPCState;
  if ( (unsigned int)m_NPCState < NPC_STATE_DEAD )
    DevMsg(a1: "State: %s, ", pStateNames[m_NPCState]);
  m_Activity = this->m_Activity;
  if ( m_Activity != ACT_INVALID && this->m_IdealActivity != ACT_INVALID )
  {
    ActivityName = CAI_BaseNPC::GetActivityName(actID: m_Activity);
    v7 = CAI_BaseNPC::GetActivityName(actID: this->m_IdealActivity);
    DevMsg(a1: "Activity: %s  -  Ideal Activity: %s\n", ActivityName, v7);
  }
  m_pSchedule = this->m_pSchedule;
  if ( m_pSchedule != nullptr )
  {
    m_pName = m_pSchedule->m_pName;
    if ( m_pName == nullptr )
      m_pName = "Unknown";
    DevMsg(a1: "Schedule %s, ", m_pName);
    Task = CAI_BaseNPC::GetTask(this);
    if ( Task != nullptr )
      DevMsg(a1: "Task %d (#%d), ", Task->iTask, this->m_ScheduleState.iCurTask);
  }
  else
  {
    DevMsg(a1: "No Schedule, ");
  }
  if ( this->GetEnemy_2(this) != nullptr )
  {
    v11 = (CBaseEntity *)((int (__thiscall *)(CAI_BaseNPC *, int))this->GetEnemy_2)(a1: this, a2);
    v12 = (float *)v11;
    if ( (v11->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v11);
    v19[0] = v12[115];
    v19[1] = v12[116];
    v19[2] = v12[117] + 64.0;
    ((void (__thiscall *)(IEffects *, float *, int, int))g_pEffects->Sparks)(a1: g_pEffects, a2: v19, a3: 1, a4: 1);
    v13 = this->GetEnemy_2(this)->m_iClassname.pszValue;
    if ( v13 == nullptr )
      v13 = locale;
    DevMsg(a1: "\nEnemy is %s", v13);
  }
  else
  {
    DevMsg(a1: "No enemy ");
  }
  if ( this->IsMoving(this) )
  {
    DevMsg(a1: " Moving ");
    m_flMoveWaitFinished = this->m_flMoveWaitFinished;
    curtime = gpGlobals->curtime;
    if ( m_flMoveWaitFinished <= curtime )
    {
      if ( !CAI_Navigator::IsGoalActive(this: this->m_pNavigator)
        || (ArrivalActivity = CAI_Navigator::GetArrivalActivity(this: this->m_pNavigator)) <= ACT_RESET )
      {
        ArrivalActivity = ACT_IDLE;
      }
      if ( this->m_IdealActivity == ArrivalActivity )
        DevMsg(a1: ": In stopped anim. ");
    }
    else
    {
      DevMsg(a1: ": Stopped for %.2f. ", (float)(m_flMoveWaitFinished - curtime));
    }
  }
  DevMsg(a1: "Leader.");
  DevMsg(a1: "\n");
  DevMsg(a1: "Yaw speed:%3.1f,Health: %3d\n", this->m_pMotor->m_YawSpeed, this->m_iHealth.m_Value);
  if ( CBaseEntity::GetGroundEntity(this) != nullptr )
  {
    v17 = CBaseEntity::GetGroundEntity(this)->m_iClassname.pszValue;
    if ( v17 == nullptr )
      v17 = locale;
    DevMsg(a1: "Groundent:%s\n\n", v17);
  }
  else
  {
    DevMsg(a1: "Groundent: NULL\n\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D220
// Name: public: virtual class Vector CAI_BaseNPC::GetShootEnemyDir(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::GetShootEnemyDir(
        CAI_BaseNPC *this,
        Vector *result,
        const Vector *shootOrigin,
        BOOL bNoisy)
{
  CBaseEntity *v5; // esi
  const Vector *v6; // eax
  __int64 v7; // xmm0_8
  float z; // eax
  unsigned int v9; // ecx
  float *v10; // eax
  float v11; // xmm0_4
  float v12; // xmm2_4
  Vector v14; // [esp+8h] [ebp-24h] BYREF
  Vector forward; // [esp+14h] [ebp-18h] BYREF
  Vector retval; // [esp+20h] [ebp-Ch] BYREF

  v5 = this->GetEnemy_2(this);
  if ( v5 != nullptr )
  {
    v6 = this->GetEnemyLKP(this);
    v7 = *(_QWORD *)&v6->x;
    z = v6->z;
    v9 = (unsigned int)v5->m_iEFlags >> 11;
    *(_QWORD *)&forward.x = v7;
    forward.z = z;
    if ( (v9 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v5);
    v10 = (float *)v5->BodyTarget(this: v5, result: &v14, a3: shootOrigin, a4: bNoisy);
    v11 = (float)((float)(v10[1] - v5->m_vecAbsOrigin.y) + forward.y) - shootOrigin->y;
    v12 = (float)(forward.z + (float)(v10[2] - v5->m_vecAbsOrigin.z)) - shootOrigin->z;
    retval.x = (float)(forward.x + (float)(*v10 - v5->m_vecAbsOrigin.x)) - shootOrigin->x;
    retval.y = v11;
    retval.z = v12;
    VectorNormalize(vec: &retval);
    *result = retval;
    return result;
  }
  else
  {
    AngleVectors(angles: &this->m_angRotation.m_Value, &forward);
    *result = forward;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D340
// Name: public: virtual int CAI_BaseNPC::PlaySentence(char const __near *,float,float,enum soundlevel_t,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::PlaySentence(
        CAI_BaseNPC *this,
        const char *pszSentence,
        float delay,
        float volume,
        soundlevel_t soundlevel,
        CBaseEntity *pListener)
{
  int v7; // edi
  edict_t *m_pPev; // esi
  CPASAttenuationFilter filter; // [esp+2Ch] [ebp-20h] BYREF

  if ( pszSentence == nullptr || !this->IsAlive(this) )
    return -1;
  if ( *pszSentence != 33 )
    return SENTENCEG_PlayRndSz(
             entity: this->m_Network.m_pPev,
             szgroupname: pszSentence,
             volume,
             soundlevel,
             flags: 0,
             pitch: 100);
  v7 = SENTENCEG_Lookup(sample: pszSentence);
  CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, soundlevel);
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  CBaseEntity::EmitSentenceByIndex(
    &filter,
    iEntIndex: (int)m_pPev,
    iChannel: 2,
    iSentenceIndex: v7,
    flVolume: volume,
    iSoundlevel: soundlevel,
    iFlags: 0,
    iPitch: 100,
    pOrigin: nullptr,
    pDirection: nullptr,
    bUpdatePositions: true,
    soundtime: 0.0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1001D410
// Name: public: virtual class CBaseEntity __near * CAI_BaseNPC::FindNamedEntity(char const __near *,class IEntityFindFilter __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CAI_BaseNPC::FindNamedEntity(CAI_BaseNPC *this, const char *name, IEntityFindFilter *pFilter)
{
  CBaseEntity *EntityByName; // eax
  int i; // esi
  IUniformRandomStream *v7; // ecx
  CBaseEntity *entityList[32]; // [esp+8h] [ebp-80h]

  if ( _V_stricmp(s1: name, s2: "!player") == 0 )
  {
    if ( gpGlobals->maxClients <= 1 )
      return UTIL_GetLocalPlayer();
    return nullptr;
  }
  if ( _V_stricmp(s1: name, s2: "!enemy") == 0 )
  {
    if ( this->GetEnemy_2(this) != nullptr )
      return (CBasePlayer *)this->GetEnemy_2(this);
    return nullptr;
  }
  if ( _V_stricmp(s1: name, s2: "!self") == 0 || _V_stricmp(s1: name, s2: "!target1") == 0 )
    return (CBasePlayer *)this;
  if ( _V_stricmp(s1: name, s2: "!nearestfriend") != 0 && _V_stricmp(s1: name, s2: "!friend") != 0 )
  {
    if ( _V_stricmp(s1: name, s2: "self") == 0 )
    {
      if ( ++selfwarningcount < 5 )
        DevMsg(a1: "ERROR: \"self\" is no longer used, use \"!self\" in vcd instead!\n");
      return (CBasePlayer *)this;
    }
    if ( _V_stricmp(s1: name, s2: "Player") == 0 )
    {
      if ( ++playerwarningcount < 5 )
        DevMsg(a1: "ERROR: \"player\" is no longer used, use \"!player\" in vcd instead!\n");
      if ( gpGlobals->maxClients <= 1 )
        return UTIL_GetLocalPlayer();
      return nullptr;
    }
    EntityByName = nullptr;
    for ( i = 0; i < 32; ++i )
    {
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: EntityByName,
                       szName: name,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter);
      if ( EntityByName == nullptr )
        break;
      entityList[i] = EntityByName;
    }
    if ( i <= 0 )
      return nullptr;
    return (CBasePlayer *)entityList[_RandomInt(this: v7, a2: 0, a3: i - 1)];
  }
  else
  {
    if ( gpGlobals->maxClients <= 1 )
      return UTIL_GetLocalPlayer();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D5C0
// Name: public: void CAI_BaseNPC::CorpseFallThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::CorpseFallThink(CAI_BaseNPC *this)
{
  if ( (this->m_fFlags.m_Value & 1) != 0 )
  {
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    CBaseAnimating::SetSequenceBox(this);
  }
  else
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D610
// Name: public: bool CAI_BaseNPC::BBoxFlat(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __usercall CAI_BaseNPC::BBoxFlat@<al>(CAI_BaseNPC *this@<ecx>, float a2@<ebp>)
{
  Vector *v3; // eax
  Vector *v4; // eax
  float v5; // xmm0_4
  unsigned int v6; // eax
  float v7; // xmm2_4
  unsigned int v8; // ecx
  unsigned int v9; // edx
  float v10; // xmm1_4
  __int128 v11; // xmm0
  unsigned int v12; // ecx
  float v13; // xmm1_4
  unsigned int v14; // edx
  __int128 v15; // xmm0
  float v17; // xmm1_4
  unsigned int v18; // edx
  __int128 v19; // xmm0
  float v20; // xmm1_4
  unsigned int v21; // edx
  __int128 v22; // xmm1
  unsigned int v23; // [esp-24h] [ebp-CCh]
  unsigned int v24; // [esp-24h] [ebp-CCh]
  unsigned int v25; // [esp-24h] [ebp-CCh]
  unsigned int v26; // [esp-24h] [ebp-CCh]
  _BYTE v27[12]; // [esp-Ch] [ebp-B4h] BYREF
  _BYTE tr[92]; // [esp+0h] [ebp-A8h] OVERLAPPED
  float v29[7]; // [esp+5Ch] [ebp-4Ch]
  float v30; // [esp+78h] [ebp-30h]
  float v31; // [esp+7Ch] [ebp-2Ch]
  _DWORD v32[2]; // [esp+80h] [ebp-28h] BYREF
  float flXSize; // [esp+88h] [ebp-20h]
  float v34; // [esp+8Ch] [ebp-1Ch]
  float v35; // [esp+90h] [ebp-18h] BYREF
  float v36; // [esp+94h] [ebp-14h]
  float flYSize; // [esp+98h] [ebp-10h]
  Vector vecPoint; // [esp+9Ch] [ebp-Ch] BYREF
  float retaddr; // [esp+A8h] [ebp+0h]

  vecPoint.x = a2;
  vecPoint.y = retaddr;
  v3 = AllocTempVector();
  v3->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
  v3->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
  v3->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
  v31 = v3->x * 0.5;
  v4 = AllocTempVector();
  v4->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
  v4->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
  v4->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
  v5 = v4->y * 0.5;
  v6 = (unsigned int)this->m_iEFlags >> 11;
  v34 = v5;
  if ( (v6 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this);
    v5 = v34;
  }
  v7 = this->m_vecAbsOrigin.x + v31;
  v8 = (unsigned int)this->m_iEFlags >> 11;
  v35 = v7;
  if ( (v8 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this);
    v7 = v35;
    v5 = v34;
  }
  v9 = (unsigned int)this->m_iEFlags >> 11;
  v10 = this->m_vecAbsOrigin.y + v5;
  v36 = v10;
  if ( (v9 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this);
    v10 = v36;
    v7 = v35;
  }
  v23 = this->m_nAITraceMask & 0xFDFFFFFF;
  flYSize = this->m_vecAbsOrigin.z;
  *(float *)v32 = v7;
  *(float *)&v32[1] = v10;
  v30 = flYSize - 100.0;
  flXSize = flYSize - 100.0;
  UTIL_TraceLine(
    a1: (const IHandleEntity *)&vecPoint,
    a2: (int)this,
    vecAbsStart: (const Vector *)&v35,
    vecAbsEnd: (const Vector *)v32,
    mask: v23,
    ignore: this,
    collisionGroup: 0,
    ptr: (CGameTrace *)v27);
  v11 = 0;
  v12 = (unsigned int)this->m_iEFlags >> 11;
  *(float *)&v11 = fsqrt(
                     (float)((float)((float)(v36 - *(float *)&tr[4]) * (float)(v36 - *(float *)&tr[4]))
                           + (float)((float)(flYSize - *(float *)&tr[8]) * (float)(flYSize - *(float *)&tr[8])))
                   + (float)((float)(v35 - *(float *)tr) * (float)(v35 - *(float *)tr)));
  *(_OWORD *)&tr[76] = v11;
  if ( (v12 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  v13 = this->m_vecAbsOrigin.x - v31;
  v14 = (unsigned int)this->m_iEFlags >> 11;
  v35 = v13;
  if ( (v14 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this);
    v13 = v35;
  }
  v24 = this->m_nAITraceMask & 0xFDFFFFFF;
  v36 = this->m_vecAbsOrigin.y - v34;
  *(float *)&v32[1] = v36;
  *(float *)v32 = v13;
  flXSize = v30;
  UTIL_TraceLine(
    a1: (const IHandleEntity *)&vecPoint,
    a2: (int)this,
    vecAbsStart: (const Vector *)&v35,
    vecAbsEnd: (const Vector *)v32,
    mask: v24,
    ignore: this,
    collisionGroup: 0,
    ptr: (CGameTrace *)v27);
  v15 = 0;
  *(float *)&v15 = fsqrt(
                     (float)((float)((float)(v36 - *(float *)&tr[4]) * (float)(v36 - *(float *)&tr[4]))
                           + (float)((float)(flYSize - *(float *)&tr[8]) * (float)(flYSize - *(float *)&tr[8])))
                   + (float)((float)(v35 - *(float *)tr) * (float)(v35 - *(float *)tr)));
  *(_OWORD *)v29 = v15;
  if ( *(float *)&v15 > *(float *)&tr[76] )
    return false;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  v17 = this->m_vecAbsOrigin.x - v31;
  v18 = (unsigned int)this->m_iEFlags >> 11;
  v35 = v17;
  if ( (v18 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this);
    v17 = v35;
  }
  v25 = this->m_nAITraceMask & 0xFDFFFFFF;
  v36 = this->m_vecAbsOrigin.y + v34;
  *(float *)&v32[1] = v36;
  *(float *)v32 = v17;
  flXSize = v30;
  UTIL_TraceLine(
    a1: (const IHandleEntity *)&vecPoint,
    a2: (int)this,
    vecAbsStart: (const Vector *)&v35,
    vecAbsEnd: (const Vector *)v32,
    mask: v25,
    ignore: this,
    collisionGroup: 0,
    ptr: (CGameTrace *)v27);
  v19 = 0;
  *(float *)&v19 = fsqrt(
                     (float)((float)((float)(v36 - *(float *)&tr[4]) * (float)(v36 - *(float *)&tr[4]))
                           + (float)((float)(flYSize - *(float *)&tr[8]) * (float)(flYSize - *(float *)&tr[8])))
                   + (float)((float)(v35 - *(float *)tr) * (float)(v35 - *(float *)tr)));
  *(_OWORD *)&tr[76] = v19;
  if ( *(float *)&v19 > v29[0] )
    return false;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  v20 = this->m_vecAbsOrigin.x + v31;
  v21 = (unsigned int)this->m_iEFlags >> 11;
  v35 = v20;
  if ( (v21 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this);
    v20 = v35;
  }
  v26 = this->m_nAITraceMask & 0xFDFFFFFF;
  v36 = this->m_vecAbsOrigin.y - v34;
  *(float *)&v32[1] = v36;
  *(float *)v32 = v20;
  flXSize = v30;
  UTIL_TraceLine(
    a1: (const IHandleEntity *)&vecPoint,
    a2: (int)this,
    vecAbsStart: (const Vector *)&v35,
    vecAbsEnd: (const Vector *)v32,
    mask: v26,
    ignore: this,
    collisionGroup: 0,
    ptr: (CGameTrace *)v27);
  v22 = 0;
  *(float *)&v22 = fsqrt(
                     (float)((float)((float)(v36 - *(float *)&tr[4]) * (float)(v36 - *(float *)&tr[4]))
                           + (float)((float)(flYSize - *(float *)&tr[8]) * (float)(flYSize - *(float *)&tr[8])))
                   + (float)((float)(v35 - *(float *)tr) * (float)(v35 - *(float *)tr)));
  *(_OWORD *)v29 = v22;
  return *(float *)&v22 <= *(float *)&tr[76];
}

//------------------------------------------------------------------------------
// Address: 0x1001DAC0
// Name: public: void CAI_BaseNPC::SetTarget(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetTarget(CAI_BaseNPC *this, CBaseEntity *pTarget)
{
  if ( pTarget != nullptr )
    this->m_hTargetEnt.m_Index = pTarget->GetRefEHandle(this: pTarget)->m_Index;
  else
    this->m_hTargetEnt.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001DAF0
// Name: public: virtual bool CAI_BaseNPC::ShouldFadeOnDeath(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::ShouldFadeOnDeath(CAI_BaseNPC *this)
{
  return g_RagdollLVManager.m_bLowViolence || (this->m_spawnflags.m_Value & 0x200) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001DB10
// Name: public: virtual bool CAI_BaseNPC::ShouldPlayIdleSound(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::ShouldPlayIdleSound(CAI_BaseNPC *this)
{
  NPC_STATE m_NPCState; // eax

  m_NPCState = this->m_NPCState;
  return (m_NPCState == NPC_STATE_IDLE || m_NPCState == NPC_STATE_ALERT)
      && random->RandomInt(this: random, a2: 0, a3: 99) == 0
      && (this->m_spawnflags.m_Value & 2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001DB50
// Name: public: virtual bool CAI_BaseNPC::FOkToMakeSound(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::FOkToMakeSound(CAI_BaseNPC *this, int soundPriority)
{
  CAI_Squad *m_pSquad; // ecx

  m_pSquad = this->m_pSquad;
  if ( m_pSquad != nullptr )
  {
    if ( !CAI_Squad::FOkToMakeSound(this: m_pSquad, soundPriority) )
      return false;
  }
  else if ( this->m_flSoundWaitTime >= gpGlobals->curtime && soundPriority <= this->m_nSoundPriority )
  {
    return false;
  }
  return (this->m_spawnflags.m_Value & 2) == 0 || this->m_NPCState == NPC_STATE_COMBAT;
}

//------------------------------------------------------------------------------
// Address: 0x1001DBB0
// Name: public: virtual int CAI_BaseNPC::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::UpdateTransmitState(CAI_BaseNPC *this)
{
  if ( this->m_flTimePingEffect.m_Value <= gpGlobals->curtime )
    return CBaseEntity::UpdateTransmitState(this);
  else
    return CBaseEntity::SetTransmitState(this, nFlag: 8);
}

//------------------------------------------------------------------------------
// Address: 0x1001DBD0
// Name: public: virtual class CAI_Motor __near * CAI_BaseNPC::CreateMotor(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Motor *__thiscall CAI_BaseNPC::CreateMotor(CAI_BaseNPC *this)
{
  unsigned __int8 *v2; // esi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 96);
  memset(dst: v2, value: 0, count: 0x60u);
  if ( v2 != nullptr )
    return CAI_Motor::CAI_Motor(this: (CAI_Motor *)v2, pOuter: this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001DC10
// Name: public: virtual class CAI_MoveProbe __near * CAI_BaseNPC::CreateMoveProbe(void)
// Source: json
//------------------------------------------------------------------------------
CAI_MoveProbe *__thiscall CAI_BaseNPC::CreateMoveProbe(CAI_BaseNPC *this)
{
  CAI_MoveProbe *v2; // eax

  v2 = (CAI_MoveProbe *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 20);
  v2->CAI_Component = 0;
  *(_QWORD *)&v2->m_bIgnoreTransientEntities = 0;
  v2->m_hLastBlockingEnt.m_Index = 0;
  if ( v2 != nullptr )
    return CAI_MoveProbe::CAI_MoveProbe(this: v2, pOuter: this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001DC50
// Name: public: virtual class CAI_LocalNavigator __near * CAI_BaseNPC::CreateLocalNavigator(void)
// Source: json
//------------------------------------------------------------------------------
CAI_LocalNavigator *__thiscall CAI_BaseNPC::CreateLocalNavigator(CAI_BaseNPC *this)
{
  unsigned __int8 *v2; // esi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 212);
  memset(dst: v2, value: 0, count: 0xD4u);
  if ( v2 != nullptr )
    return CAI_LocalNavigator::CAI_LocalNavigator(this: (CAI_LocalNavigator *)v2, pOuter: this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001DC90
// Name: public: virtual class CAI_TacticalServices __near * CAI_BaseNPC::CreateTacticalServices(void)
// Source: json
//------------------------------------------------------------------------------
CAI_TacticalServices *__thiscall CAI_BaseNPC::CreateTacticalServices(CAI_BaseNPC *this)
{
  CAI_TacticalServices *result; // eax

  result = (CAI_TacticalServices *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 20);
  result->CAI_Component = 0;
  *(_QWORD *)&result->m_pNetwork = 0;
  *(_DWORD *)&result->m_bAllowFindLateralLos = 0;
  if ( result == nullptr )
    return nullptr;
  result->m_pOuter = this;
  result->__vftable = (CAI_TacticalServices_vtbl *)&CAI_TacticalServices::`vftable';
  result->m_pNetwork = nullptr;
  result->m_bAllowFindLateralLos = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DCD0
// Name: public: virtual class CAI_Navigator __near * CAI_BaseNPC::CreateNavigator(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Navigator *__thiscall CAI_BaseNPC::CreateNavigator(CAI_BaseNPC *this)
{
  unsigned __int8 *v2; // esi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 156);
  memset(dst: v2, value: 0, count: 0x9Cu);
  if ( v2 != nullptr )
    return CAI_Navigator::CAI_Navigator(this: (CAI_Navigator *)v2, pOuter: this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001DD10
// Name: public: virtual class CAI_Pathfinder __near * CAI_BaseNPC::CreatePathfinder(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Pathfinder *__thiscall CAI_BaseNPC::CreatePathfinder(CAI_BaseNPC *this)
{
  CAI_Pathfinder *result; // eax

  result = (CAI_Pathfinder *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24);
  result->CAI_Component = 0;
  *(_QWORD *)&result->m_TriDebugOverlay.m_debugTriOverlayLine = 0;
  *(_QWORD *)&result->m_bIgnoreStaleLinks = 0;
  if ( result == nullptr )
    return nullptr;
  result->m_pOuter = this;
  result->__vftable = (CAI_Pathfinder_vtbl *)&CAI_Pathfinder::`vftable';
  result->m_TriDebugOverlay.m_debugTriOverlayLine = nullptr;
  result->m_flLastStaleLinkCheckTime = 0.0;
  result->m_pNetwork = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DD60
// Name: public: void CAI_BaseNPC::InputSetHealth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputSetHealth(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  const char *pszValue; // edi
  int m_Value; // ecx
  int v5; // eax
  const CTakeDamageInfo *v6; // eax
  CTakeDamageInfo v7; // [esp+18h] [ebp-5Ch] BYREF

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
      v6 = CTakeDamageInfo::CTakeDamageInfo(
             this: &v7,
             pInflictor: this,
             pAttacker: this,
             flDamage: (float)v5,
             bitsDamageType: 0,
             iKillType: 0,
             iObjectsPenetrated: 0);
      CBaseEntity::TakeDamage(this, inputInfo: v6);
    }
  }
  else
  {
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->TakeHealth)(a1: this, a2: (float)v5, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DDE0
// Name: public: void CAI_BaseNPC::InputWake(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputWake(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  const char *v9; // eax
  const char *v10; // esi
  int v11; // eax
  bool v12; // zf
  CBaseEntity **v13; // eax

  this->Wake(this, a2: true);
  pszValue = this->m_target.pszValue;
  if ( pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
      this->m_hGoalEnt.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
    else
      this->m_hGoalEnt.m_Index = -1;
    m_Index = this->m_hGoalEnt.m_Index;
    if ( m_Index != -1
      && (v6 = (unsigned __int16)m_Index,
          v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v8 = HIWORD(m_Index),
          v7->m_SerialNumber == v8)
      && v7->m_pEntity != nullptr )
    {
      v11 = v6;
      v12 = g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v8;
      v13 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v11];
      if ( v12 )
        this->StartTargetHandling(this, a2: *v13);
      else
        this->StartTargetHandling(this, a2: nullptr);
    }
    else
    {
      v9 = this->m_target.pszValue;
      if ( v9 == nullptr )
        v9 = locale;
      v10 = this->m_iClassname.pszValue;
      if ( v10 == nullptr )
        v10 = locale;
      _Warning(a1: "ReadyNPC()--%s couldn't find target %s\n", v10, v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DED0
// Name: public: void CAI_BaseNPC::InputCreateAddon(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputCreateAddon(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  float z; // eax
  __int64 v4; // xmm0_8
  variant_t *p_value; // ecx
  bool v6; // zf
  const char *iVal; // eax
  CBaseEntity *EntityByName; // eax
  CBaseEntity *v9; // esi
  Vector vecSpawnOrigin; // [esp+8h] [ebp-Ch] BYREF

  z = this->m_vecOrigin.m_Value.z;
  v4 = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
  p_value = &inputdata->value;
  v6 = inputdata->value.fieldType == FIELD_STRING;
  *(_QWORD *)&vecSpawnOrigin.x = v4;
  vecSpawnOrigin.z = z;
  if ( v6 )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  EntityByName = CreateEntityByName(className: iVal, iForceEdictIndex: -1, bNotify: true);
  v9 = EntityByName;
  if ( EntityByName != nullptr )
  {
    CBaseEntity::SetAbsOrigin(this: EntityByName, absOrigin: &vecSpawnOrigin);
    DispatchSpawn(pEntity: v9, bRunVScripts: true);
    ((void (__thiscall *)(CBaseEntity *, CAI_BaseNPC *, int))v9->__vftable[1].GetKeyValue)(a1: v9, a2: this, a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DF50
// Name: public: void CAI_BaseNPC::OpenPropDoorBegin(class CBasePropDoor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OpenPropDoorBegin(CAI_BaseNPC *this, CBasePropDoor *pDoor)
{
  CBasePropDoor::NPCOpenDoor(this: pDoor, pNPC: this);
  this->m_flMoveWaitFinished = ((double (__thiscall *)(CBasePropDoor *))pDoor->GetOpenInterval)(a1: pDoor)
                             + gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x1001DF90
// Name: public: virtual bool CAI_BaseNPC::IsTemplate(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsTemplate(CAI_BaseNPC *this)
{
  return (this->m_spawnflags.m_Value & 0x800) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001DFA0
// Name: AIMsgGuts
// Source: json
//------------------------------------------------------------------------------
void __cdecl AIMsgGuts(CAI_BaseNPC *pAI, const char *flags)
{
  unsigned int v2; // eax
  char v3; // cl
  const char *v4; // edi
  const char *pszValue; // esi
  edict_t *m_pPev; // eax
  signed int v7; // eax
  const char *v8; // ecx

  v2 = strlen(flags);
  if ( v2 != 0 && flags[v2 - 1] == 10 )
  {
    flags[v2 - 1] = v3;
    v4 = "%s (%s: %d/%s) [%d]\n";
  }
  else
  {
    v4 = "%s (%s: %d/%s) [%d]";
  }
  pszValue = "<unnamed>";
  if ( pAI->m_iName.m_Value.pszValue != nullptr )
    pszValue = pAI->m_iName.m_Value.pszValue;
  m_pPev = pAI->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v7 = m_pPev - gpGlobals->pEdicts;
  else
    v7 = 0;
  v8 = pAI->m_iClassname.pszValue;
  if ( v8 == nullptr )
    v8 = locale;
  DevMsg(a1: v4, flags, v8, v7, pszValue, gpGlobals->tickcount);
}

//------------------------------------------------------------------------------
// Address: 0x1001E020
// Name: public: virtual bool CAI_BaseNPC::IsPlayerAlly(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsPlayerAlly(CAI_BaseNPC *this, CBasePlayer *pPlayer)
{
  CBasePlayer *LocalPlayer; // eax

  LocalPlayer = pPlayer;
  if ( pPlayer == nullptr )
  {
    if ( gpGlobals->maxClients != 1 )
      return false;
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer == nullptr )
      return true;
  }
  return this->IRelationType(this, a2: LocalPlayer) == D_LI;
}

//------------------------------------------------------------------------------
// Address: 0x1001E070
// Name: public: virtual void CAI_BaseNPC::SetCommandGoal(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetCommandGoal(CAI_BaseNPC *this, const Vector *vecGoal)
{
  this->m_vecCommandGoal = *vecGoal;
  this->m_CommandMoveMonitor.m_flMarkTolerance = -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E0B0
// Name: public: virtual void CAI_BaseNPC::ClearCommandGoal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ClearCommandGoal(CAI_BaseNPC *this)
{
  this->m_vecCommandGoal = vec3_invalid;
  this->m_CommandMoveMonitor.m_flMarkTolerance = -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E100
// Name: public: bool CAI_BaseNPC::IsInPlayerSquad(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsInPlayerSquad(CAI_BaseNPC *this)
{
  CAI_Squad *m_pSquad; // eax
  const char *pszValue; // eax

  m_pSquad = this->m_pSquad;
  if ( m_pSquad == nullptr )
    return false;
  pszValue = m_pSquad->m_Name.pszValue;
  if ( pszValue == nullptr || *pszValue == 0 )
    pszValue = nullptr;
  return pszValue == CAI_BaseNPC::gm_iszPlayerSquad.pszValue && !CAI_Squad::IsSilentMember(pNPC: this);
}

//------------------------------------------------------------------------------
// Address: 0x1001E140
// Name: public: virtual bool CAI_BaseNPC::FindNearestValidGoalPos(class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::FindNearestValidGoalPos(CAI_BaseNPC *this, const Vector *vTestPoint, Vector *pResult)
{
  CAI_Navigator *m_pNavigator; // ecx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  int v8; // eax
  CAI_MoveProbe *m_pMoveProbe; // ebx
  const Vector *NodePosition; // eax
  double v11; // st7
  float v12; // xmm0_4
  CBasePlayer *LocalPlayer; // ebx
  AI_Waypoint_t *v14; // eax
  AI_Waypoint_t *v15; // ebx
  CAI_Path tempPath; // [esp+18h] [ebp-BCh] BYREF
  AIMoveTrace_t moveTrace; // [esp+84h] [ebp-50h] BYREF
  Vector v19; // [esp+BCh] [ebp-18h] BYREF
  Vector vCandidate; // [esp+C8h] [ebp-Ch] BYREF

  memset(dst: (unsigned __int8 *)&moveTrace, value: 0, count: sizeof(moveTrace));
  vCandidate.z = vec3_invalid.z;
  m_pNavigator = this->m_pNavigator;
  *(_QWORD *)&vCandidate.x = *(_QWORD *)&vec3_invalid.x;
  if ( CAI_Navigator::CanFitAtPosition(
         this: m_pNavigator,
         vStartPos: vTestPoint,
         collisionMask: 0x400Bu,
         bIgnoreTransients: false,
         bAllowPlayerAvoid: true)
    && CAI_MoveProbe::CheckStandPosition(this: this->m_pMoveProbe, vecStart: vTestPoint, collisionMask: 0x400Bu) )
  {
    x = vTestPoint->x;
    y = vTestPoint->y;
    z = vTestPoint->z;
    vCandidate.x = vTestPoint->x;
    vCandidate.y = y;
    vCandidate.z = z;
  }
  else
  {
    z = vCandidate.z;
    y = vCandidate.y;
    x = vCandidate.x;
  }
  if ( vec3_invalid.x != x )
    goto LABEL_16;
  if ( vec3_invalid.y == y && vec3_invalid.z == z )
  {
    v8 = CAI_Network::NearestNodeToPoint(
           this: this->m_pNavigator->m_pAINetwork,
           vPosition: vTestPoint,
           bCheckVisibility: false);
    if ( v8 == -1
      || (m_pMoveProbe = this->m_pMoveProbe,
          NodePosition = CAI_Network::GetNodePosition(this: g_pBigAINet, result: &v19, hull: this->m_eHull, nodeID: v8),
          CAI_MoveProbe::MoveLimit(
            this: m_pMoveProbe,
            navType: NAV_GROUND,
            vecStart: NodePosition,
            vecEnd: vTestPoint,
            collisionMask: 0x400Bu,
            pTarget: nullptr,
            pctToCheckStandPositions: 0.0,
            flags: 0,
            pTrace: &moveTrace),
          v11 = NAI_Hull::Width(id: this->m_eHull),
          v12 = moveTrace.vEndPosition.x - vTestPoint->x,
          *(double *)&v19.y = v11 * 3.0,
          *(double *)&v19.y * *(double *)&v19.y <= (float)((float)((float)(moveTrace.vEndPosition.y - vTestPoint->y)
                                                                 * (float)(moveTrace.vEndPosition.y - vTestPoint->y))
                                                         + (float)(v12 * v12)))
      || !CAI_MoveProbe::CheckStandPosition(
            this: this->m_pMoveProbe,
            vecStart: &moveTrace.vEndPosition,
            collisionMask: 0x400Bu) )
    {
      z = vCandidate.z;
      y = vCandidate.y;
      x = vCandidate.x;
    }
    else
    {
      x = moveTrace.vEndPosition.x;
      y = moveTrace.vEndPosition.y;
      z = moveTrace.vEndPosition.z;
      vCandidate = moveTrace.vEndPosition;
    }
  }
  if ( vec3_invalid.x != x || vec3_invalid.y != y || vec3_invalid.z != z )
  {
LABEL_16:
    if ( gpGlobals->maxClients <= 1 )
      LocalPlayer = UTIL_GetLocalPlayer();
    else
      LocalPlayer = nullptr;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    v14 = CAI_Pathfinder::BuildRoute(
            this: this->m_pPathfinder,
            vStart: &this->m_vecAbsOrigin,
            vEnd: &vCandidate,
            pTarget: LocalPlayer,
            goalTolerance: 60.0,
            curNavType: NAV_NONE,
            nBuildFlags: 512);
    v15 = v14;
    if ( v14 != nullptr )
    {
      CAI_Pathfinder::UnlockRouteNodes(this: this->m_pPathfinder, pPath: v14);
      CAI_Path::CAI_Path(this: &tempPath);
      CAI_Path::SetWaypoints(this: &tempPath, route: v15, fSetGoalFromLast: false);
      CAI_Path::~CAI_Path(this: &tempPath);
      z = vCandidate.z;
      y = vCandidate.y;
      x = vCandidate.x;
    }
    else
    {
      x = vec3_invalid.x;
      y = vec3_invalid.y;
      z = vec3_invalid.z;
      vCandidate = vec3_invalid;
    }
  }
  if ( vec3_invalid.x == x )
  {
    if ( vec3_invalid.y == y && vec3_invalid.z == z )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      CAI_MoveProbe::MoveLimit(
        this: this->m_pMoveProbe,
        navType: NAV_GROUND,
        vecStart: &this->m_vecAbsOrigin,
        vecEnd: vTestPoint,
        collisionMask: 0x400Bu,
        pTarget: nullptr,
        pctToCheckStandPositions: 0.0,
        flags: 0,
        pTrace: &moveTrace);
      x = moveTrace.vEndPosition.x;
      y = moveTrace.vEndPosition.y;
      z = moveTrace.vEndPosition.z;
    }
    if ( vec3_invalid.x == x && vec3_invalid.y == y && vec3_invalid.z == z )
      return 0;
  }
  if ( pResult != nullptr )
  {
    pResult->x = x;
    pResult->y = y;
    pResult->z = z;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001E4E0
// Name: void AI_TraceLOS(class Vector const __near &,class Vector const __near &,class CBaseEntity __near *,class CGameTrace __near *,class ITraceFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall AI_TraceLOS(
        int a1@<esi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        CBaseEntity *pLooker,
        CGameTrace *ptr,
        CTraceFilterLOS *pFilter)
{
  CTraceFilterLOS *p_traceFilter; // eax
  CTraceFilterLOS traceFilter; // [esp+0h] [ebp-14h] BYREF
  IHandleEntity savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( ai_LOS_mode.m_pParent != nullptr && ai_LOS_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    UTIL_TraceLine(
      a1: &savedregs,
      a2: a1,
      vecAbsStart,
      vecAbsEnd,
      mask: 0x4041u,
      ignore: pLooker,
      collisionGroup: 0,
      ptr);
  }
  else
  {
    CTraceFilterLOS::CTraceFilterLOS(
      this: &traceFilter,
      pHandleEntity: pLooker,
      collisionGroup: 0,
      pHandleEntity2: nullptr);
    p_traceFilter = pFilter;
    if ( pFilter == nullptr )
      p_traceFilter = &traceFilter;
    UTIL_TraceLine(a1: (int)&savedregs, a2: a1, vecAbsStart, vecAbsEnd, mask: 0x2004041u, pFilter: p_traceFilter, ptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E550
// Name: public: virtual void CAI_BaseNPC::ModifyOrAppendCriteria(class ResponseRules::CriteriaSet __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ModifyOrAppendCriteria(CAI_BaseNPC *this, ResponseRules::CriteriaSet *set)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // ecx
  const char *v4; // eax
  float m_flLastSawPlayerTime; // xmm0_4
  CBaseEntity *v6; // eax
  double v7; // st7
  const char *v8; // eax
  const char *v9; // [esp+4h] [ebp-10h]

  CBaseAnimating::ModifyOrAppendCriteria(this, set);
  m_pPrimaryBehavior = this->m_pPrimaryBehavior;
  if ( m_pPrimaryBehavior != nullptr )
  {
    v4 = (const char *)((int (*)(void))m_pPrimaryBehavior->GetName)();
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "active_behavior", value: v4, weight: 1.0);
  }
  m_flLastSawPlayerTime = this->m_flLastSawPlayerTime;
  if ( m_flLastSawPlayerTime == 0.0 )
  {
    ResponseRules::CriteriaSet::AppendCriteria(
      this: set,
      pCriteriaName: "timesinceseenplayer",
      value: "-1",
      weight: 1.0);
  }
  else
  {
    v9 = UTIL_VarArgs(format: "%f", (float)(gpGlobals->curtime - m_flLastSawPlayerTime));
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "timesinceseenplayer", value: v9, weight: 1.0);
  }
  if ( this->GetEnemy_2(this) != nullptr )
  {
    v6 = this->GetEnemy_2(this);
    v7 = CAI_BaseNPC::EnemyDistance(this, a2: (int)set, a3: (int)this, pEnemy: v6);
    v8 = UTIL_VarArgs(format: "%f", v7);
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "distancetoenemy", value: v8, weight: 1.0);
  }
  else
  {
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "distancetoenemy", value: "-1", weight: 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E670
// Name: public: virtual bool CAI_BaseNPC::ShouldProbeCollideAgainstEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::ShouldProbeCollideAgainstEntity(CAI_BaseNPC *this, CBaseEntity *pEntity)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  bool result; // al

  result = true;
  if ( pEntity->m_MoveType.m_Value == 6
    && ai_test_moveprobe_ignoresmall.m_pParent != nullptr
    && ai_test_moveprobe_ignoresmall.m_pParent->m_Value.m_nValue != 0
    && this->IsNavigationUrgent(this) )
  {
    m_pPhysicsObject = pEntity->m_pPhysicsObject;
    if ( m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject)
      && ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: m_pPhysicsObject) < 40.0 )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E740
// Name: public: char const __near * CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  bool v3; // zf
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  this->InitQuietTruncation(this);
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v2->m_szBuf, maxLen: 255, pFormat: pszFormat, params, pbTruncated: (bool *)&this + 3);
  v3 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v3 && !v2->m_bQuietTruncation && `CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2->m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x1001EAA0
// Name: protected: bool CAI_BaseNPC::IsRunningDynamicInteraction(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsRunningDynamicInteraction(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx
  BOOL result; // eax

  result = false;
  if ( this->m_iInteractionState != 0 )
  {
    m_Index = this->m_hCine.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001EAE0
// Name: public: class CAI_BaseNPC __near * __near * CAI_Manager::AccessAIs(void)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC **__thiscall CAI_Manager::AccessAIs(CAI_Manager *this)
{
  if ( this->m_AIs.m_Size != 0 )
    return this->m_AIs.m_Memory.m_pMemory;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001EAF0
// Name: public: virtual void CAI_BaseNPC::CleanupOnDeath(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::CleanupOnDeath(CAI_BaseNPC *this, CBaseEntity *pCulprit, bool bFireDeathOutput)
{
  bool v4; // zf
  unsigned int m_Index; // ecx
  CBaseEntityList *v6; // edx
  int v7; // eax
  CEntInfo *v8; // edi
  unsigned int v9; // ecx
  int v10; // eax
  CAI_ScriptedSequence **v11; // eax
  CAI_ScriptedSequence *v12; // eax
  unsigned int v13; // ecx
  int v14; // eax
  CEntInfo *v15; // edi
  unsigned int v16; // ecx
  int v17; // eax
  CAI_Hint **v18; // eax
  CAI_Hint *v19; // eax
  CAI_Enemies *v20; // eax
  CAI_BaseNPC_vtbl *v21; // edi
  const Vector *AbsOrigin; // eax

  if ( this->m_bDidDeathCleanup )
  {
    DevMsg(a1: "Unexpected double-death-cleanup\n");
    return;
  }
  v4 = this->m_NPCState == NPC_STATE_SCRIPT;
  this->m_bDidDeathCleanup = true;
  if ( v4 )
  {
    m_Index = this->m_hCine.m_Index;
    if ( m_Index != -1 )
    {
      v6 = g_pEntityList;
      v7 = (unsigned __int16)m_Index;
      v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v9 = HIWORD(m_Index);
      if ( v8->m_SerialNumber != v9 || v8->m_pEntity == nullptr )
        goto LABEL_11;
      v10 = v7;
      v4 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9;
      v11 = (CAI_ScriptedSequence **)&g_pEntityList->m_EntPtrArray[v10];
      if ( v4 )
        v12 = *v11;
      else
        v12 = nullptr;
      CAI_ScriptedSequence::CancelScript(this: v12);
    }
  }
  v6 = g_pEntityList;
LABEL_11:
  v13 = this->m_pHintNode.m_Index;
  if ( v13 != -1 )
  {
    v14 = (unsigned __int16)v13;
    v15 = &v6->m_EntPtrArray[(unsigned __int16)v13];
    v16 = HIWORD(v13);
    if ( v15->m_SerialNumber == v16 && v15->m_pEntity != nullptr )
    {
      v17 = v14;
      v4 = v6->m_EntPtrArray[v17].m_SerialNumber == v16;
      v18 = (CAI_Hint **)&v6->m_EntPtrArray[v17];
      if ( v4 )
        v19 = *v18;
      else
        v19 = nullptr;
      CAI_Hint::Unlock(this: v19, flSeconds: 0.0);
      CAI_BaseNPC::SetHintNode(this, pHintNode: nullptr);
    }
  }
  if ( bFireDeathOutput )
    COutputEvent::FireOutput(this: &this->m_OnDeath, pActivator: pCulprit, pCaller: this, fDelay: 0.0);
  CAI_BaseNPC::VacateStrategySlot(this);
  if ( this->m_pSquad != nullptr )
  {
    if ( this->m_NPCState == NPC_STATE_IDLE && pCulprit != nullptr )
    {
      v20 = this->GetEnemies(this);
      if ( CAI_Enemies::GetDangerMemory(this: v20) == nullptr )
      {
        v21 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        AbsOrigin = CBaseEntity::GetAbsOrigin(this);
        v21->UpdateEnemyMemory(this, a2: pCulprit, a3: AbsOrigin, a4: nullptr);
      }
    }
    CAI_Squad::RemoveFromSquad(this: this->m_pSquad, pNPC: this, bDeath: true);
    this->m_pSquad = nullptr;
  }
  RemoveActorFromScriptedScenes(
    pActor: this,
    instancedscenesonly: false,
    nonidlescenesonly: false,
    pszThisSceneOnly: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1001EC60
// Name: public: virtual bool CAI_BaseNPC::PassesDamageFilter(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::PassesDamageFilter(CAI_BaseNPC *this, const CTakeDamageInfo *info)
{
  bool result; // al
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  CAI_BaseNPC *v11; // eax
  CBaseEntity *Attacker; // eax
  int v13; // eax
  int v14; // esi
  CBaseEntity *v15; // eax
  CBaseEntity *v16; // eax
  CBaseEntity *v17; // eax

  if ( ai_block_damage.m_pParent != nullptr && ai_block_damage.m_pParent->m_Value.m_nValue != 0 )
    return false;
  if ( (this->CapabilitiesGet(this) & 0x2000000) == 0 )
    goto LABEL_14;
  m_Index = info->m_hAttacker.m_Index;
  if ( m_Index == -1 )
    goto LABEL_14;
  v5 = (unsigned __int16)m_Index;
  v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v7 = HIWORD(m_Index);
  if ( v6->m_SerialNumber != v7 || v6->m_pEntity == nullptr )
    goto LABEL_14;
  v8 = v5;
  v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
  v10 = &g_pEntityList->m_EntPtrArray[v8];
  v11 = v9 ? (CAI_BaseNPC *)v10->m_pEntity : nullptr;
  if ( v11 == this )
    goto LABEL_14;
  Attacker = CTakeDamageInfo::GetAttacker(this: info);
  v13 = (int)Attacker->MyCombatCharacterPointer(this: Attacker);
  v14 = v13;
  if ( v13 != 0 )
  {
    if ( (*(int (__thiscall **)(int, CAI_BaseNPC *))(*(_DWORD *)v13 + 1252))(a1: v13, a2: this) != 3 )
    {
LABEL_14:
      result = CBaseEntity::PassesDamageFilter(this, info);
      if ( result )
        return true;
      this->m_fNoDamageDecal = true;
      return result;
    }
  }
  else
  {
    v15 = CTakeDamageInfo::GetAttacker(this: info);
    if ( v15->GetServerVehicle(this: v15) == nullptr )
      goto LABEL_14;
  }
  this->m_fNoDamageDecal = true;
  if ( v14 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v14 + 336))(a1: v14) != 0 )
  {
    v16 = CTakeDamageInfo::GetAttacker(this: info);
    COutputEvent::FireOutput(this: &this->m_OnDamagedByPlayer, pActivator: v16, pCaller: this, fDelay: 0.0);
    v17 = CTakeDamageInfo::GetAttacker(this: info);
    COutputEvent::FireOutput(this: &this->m_OnDamagedByPlayerSquad, pActivator: v17, pCaller: this, fDelay: 0.0);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1001EDA0
// Name: public: virtual void CAI_BaseNPC::NotifyFriendsOfDamage(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::NotifyFriendsOfDamage(CAI_BaseNPC *this, CAI_BaseNPC *pAttackerEntity)
{
  int m_Size; // eax
  int i; // ebx
  CAI_BaseNPC **v5; // eax
  CAI_BaseNPC *v6; // esi
  float v7; // xmm1_4
  CAI_BaseNPC *pAttacker; // [esp+Ch] [ebp+8h]

  pAttacker = pAttackerEntity->MyNPCPointer(this: pAttackerEntity);
  if ( pAttacker != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    m_Size = g_AI_Manager.m_AIs.m_Size;
    for ( i = 0; i < g_AI_Manager.m_AIs.m_Size; ++i )
    {
      v5 = m_Size != 0 ? g_AI_Manager.m_AIs.m_Memory.m_pMemory : nullptr;
      v6 = v5[i];
      if ( v6 != nullptr && v6 != this )
      {
        if ( (v6->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v5[i]);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v6->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z) & _mask__AbsFloat_) < 120.0 )
        {
          v7 = v6->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
          if ( (float)((float)((float)(v6->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x)
                             * (float)(v6->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x))
                     + (float)(v7 * v7)) < 360000.0
            && (v6->m_pSquad == this->m_pSquad || this->IRelationType(this, a2: v6) == D_LI) )
          {
            v6->OnFriendDamaged(this: v6, a2: this, a3: pAttacker);
          }
        }
      }
      m_Size = g_AI_Manager.m_AIs.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EEC0
// Name: public: virtual bool CTriggerTraceEnum::EnumEntity(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTriggerTraceEnum::EnumEntity(CTriggerTraceEnum *this, IHandleEntity *pHandleEntity)
{
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // ecx
  int v6; // edi
  CGameTrace tr; // [esp+Ch] [ebp-54h] BYREF

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index != -1
    && (v4 = &gEntList.m_EntPtrArray[(unsigned __int16)m_Index])->m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = v4->m_pEntity) != nullptr )
  {
    v6 = (int)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  }
  else
  {
    v6 = 0;
  }
  if ( *(_BYTE *)(v6 + 262) == 0 || (*(_BYTE *)(v6 + 260) & 4) != 0 )
  {
    enginetrace->ClipRayToEntity(
      this: enginetrace,
      a2: this->m_pRay,
      a3: this->m_ContentsMask,
      a4: pHandleEntity,
      a5: &tr);
    if ( tr.fraction < 1.0 )
    {
      CBaseEntity::DispatchTraceAttack(this: (CBaseEntity *)v6, info: &this->m_info, vecDir: &this->m_VecDir, ptr: &tr);
      ApplyMultiDamage();
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001EF70
// Name: protected: void CBaseEntity::HandleShotImpactingGlass(struct FireBulletsInfo_t const __near &,class CGameTrace const __near &,class Vector const __near &,class ITraceFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::HandleShotImpactingGlass(
        CBaseEntity *this,
        const FireBulletsInfo_t *info,
        const CGameTrace *tr,
        const Vector *vecDir,
        ITraceFilter *pTraceFilter)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float x; // xmm3_4
  float y; // xmm4_4
  float v9; // xmm0_4
  float z; // xmm1_4
  float v11; // xmm0_4
  CBaseEntity_vtbl *v12; // ebx
  CAmmoDef *AmmoDef; // eax
  int v14; // eax
  int m_iTracerFreq; // ecx
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm0_4
  CBaseEntity *m_pAttacker; // eax
  float m_flDamage; // xmm0_4
  void (__thiscall *FireBullets)(CBaseEntity *, const FireBulletsInfo_t *); // eax
  int m_iAmmoType; // [esp-4h] [ebp-128h]
  CGameTrace penetrationTrace; // [esp+Ch] [ebp-118h] BYREF
  FireBulletsInfo_t behindGlassInfo; // [esp+60h] [ebp-C4h] BYREF
  CEffectData data; // [esp+B0h] [ebp-74h] BYREF
  Vector testPos; // [esp+114h] [ebp-10h] BYREF
  CBaseEntity *v27; // [esp+120h] [ebp-4h]
  int savedregs; // [esp+124h] [ebp+0h] BYREF

  v27 = this;
  v5 = vecDir->y * 16.0;
  v6 = vecDir->z * 16.0;
  x = tr->endpos.x;
  testPos.x = x + (float)(vecDir->x * 16.0);
  y = tr->endpos.y;
  v9 = y + v5;
  z = tr->endpos.z;
  testPos.y = v9;
  testPos.z = z + v6;
  memset((void *)&data.m_vStart, 0, sizeof(data.m_vStart));
  memset((void *)&data.m_vAngles, 0, 20);
  memset(&data.m_flMagnitude, 0, 14);
  data.m_vNormal.x = tr->plane.normal.x;
  data.m_vNormal.y = tr->plane.normal.y;
  v11 = tr->plane.normal.z;
  data.m_flScale = 1.0;
  memset(&data.m_nMaterial, 0, 17);
  data.m_vNormal.z = v11;
  data.m_vOrigin.x = x;
  data.m_vOrigin.y = y;
  data.m_vOrigin.z = z;
  DispatchEffect(pName: "GlassImpact", &data);
  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)&tr->endpos,
    vecAbsStart: &testPos,
    vecAbsEnd: &tr->endpos,
    mask: 0x46004003u,
    pFilter: pTraceFilter,
    ptr: &penetrationTrace);
  if ( !penetrationTrace.startsolid && tr->fraction != 0.0 && penetrationTrace.fraction != 1.0 )
  {
    v12 = v27->__vftable;
    m_iAmmoType = info->m_iAmmoType;
    AmmoDef = GetAmmoDef();
    v14 = CAmmoDef::DamageType(this: AmmoDef, nAmmoIndex: m_iAmmoType);
    v12->DoImpactEffect(this: v27, a2: &penetrationTrace, a3: v14);
    data.m_vNormal = penetrationTrace.plane.normal;
    data.m_vOrigin = penetrationTrace.endpos;
    DispatchEffect(pName: "GlassImpact", &data);
    m_iTracerFreq = info->m_iTracerFreq;
    behindGlassInfo.m_vecSrc = penetrationTrace.endpos;
    behindGlassInfo.m_vecDirShooting.x = vecDir->x;
    behindGlassInfo.m_vecDirShooting.y = vecDir->y;
    v16 = vecDir->z;
    behindGlassInfo.m_flPlayerDamage = 0.0;
    behindGlassInfo.m_bPrimaryAttack = true;
    behindGlassInfo.m_iShots = 1;
    v17 = info->m_iAmmoType;
    behindGlassInfo.m_vecDirShooting.z = v16;
    behindGlassInfo.m_flDamageForceScale = 1.0;
    v18 = (float)(1.0 - tr->fraction) * info->m_flDistance;
    behindGlassInfo.m_vecSpread.x = vec3_origin.x;
    behindGlassInfo.m_iAmmoType = v17;
    m_pAttacker = info->m_pAttacker;
    behindGlassInfo.m_vecSpread.y = vec3_origin.y;
    behindGlassInfo.m_flDistance = v18;
    m_flDamage = info->m_flDamage;
    behindGlassInfo.m_iTracerFreq = m_iTracerFreq;
    behindGlassInfo.m_pAdditionalIgnoreEnt = nullptr;
    behindGlassInfo.m_vecSpread.z = vec3_origin.z;
    behindGlassInfo.m_flDamage = m_flDamage;
    behindGlassInfo.m_pAttacker = m_pAttacker;
    if ( m_pAttacker == nullptr )
      behindGlassInfo.m_pAttacker = v27;
    FireBullets = v27->FireBullets;
    behindGlassInfo.m_nFlags = info->m_nFlags;
    ((void (__stdcall *)(FireBulletsInfo_t *))FireBullets)(a1: &behindGlassInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F270
// Name: public: bool CAI_BaseNPC::HasCondition(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::HasCondition(CAI_BaseNPC *this, int iCondition)
{
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax
  int v5; // eax

  if ( iCondition >= 1000000000 )
  {
    v4 = iCondition;
  }
  else
  {
    v3 = this->GetClassScheduleIdSpace(this);
    v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: iCondition);
  }
  return v4 != -1 && (v5 = v4 - 1000000000) != -1 && ((1 << (v5 & 0x1F)) & this->m_Conditions.m_Ints[v5 >> 5]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001F2E0
// Name: public: bool CAI_BaseNPC::HasCondition(int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::HasCondition(CAI_BaseNPC *this, int iCondition, bool bUseIgnoreConditions)
{
  CAI_ClassScheduleIdSpace *v5; // eax
  int v6; // eax
  int v7; // eax

  if ( bUseIgnoreConditions )
    return CAI_BaseNPC::HasCondition(this, iCondition);
  if ( iCondition >= 1000000000 )
  {
    v6 = iCondition;
  }
  else
  {
    v5 = this->GetClassScheduleIdSpace(this);
    v6 = CAI_LocalIdSpace::LocalToGlobal(this: &v5->m_ConditionIds, localID: iCondition);
  }
  return v6 != -1
      && (v7 = v6 - 1000000000) != -1
      && ((1 << (v7 & 0x1F)) & this->m_ConditionsPreIgnore.m_Ints[v7 >> 5]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001F360
// Name: public: void CAI_BaseNPC::ClearCondition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ClearCondition(CAI_BaseNPC *this, int iCondition)
{
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax
  int v5; // ebx

  if ( iCondition >= 1000000000 )
  {
    v4 = iCondition;
  }
  else
  {
    v3 = this->GetClassScheduleIdSpace(this);
    v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: iCondition);
  }
  if ( v4 != -1 )
  {
    v5 = v4 - 1000000000;
    if ( v4 != 999999999 )
    {
      if ( CAI_BaseNPC::HasCondition(this, iCondition) )
        this->OnConditionCleared(this, a2: iCondition);
      this->m_Conditions.m_Ints[v5 >> 5] &= ~(1 << (v5 & 0x1F));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F3E0
// Name: public: void CAI_BaseNPC::ClearConditions(int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ClearConditions(CAI_BaseNPC *this, int *pConditions, int nConditions)
{
  int i; // ebx
  int v5; // esi
  CAI_ClassScheduleIdSpace *v6; // eax
  int v7; // eax

  for ( i = 0; i < nConditions; ++i )
  {
    v5 = pConditions[i];
    if ( v5 >= 1000000000 )
    {
      v7 = pConditions[i];
    }
    else
    {
      v6 = this->GetClassScheduleIdSpace(this);
      v7 = CAI_LocalIdSpace::LocalToGlobal(this: &v6->m_ConditionIds, localID: v5);
    }
    if ( v7 != -1 && v7 != 999999999 )
      this->m_Conditions.m_Ints[(v7 - 1000000000) >> 5] &= ~(1 << (v7 & 0x1F));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F460
// Name: public: void CAI_BaseNPC::SetIgnoreConditions(int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetIgnoreConditions(CAI_BaseNPC *this, int *pConditions, int nConditions)
{
  int i; // ebx
  int v5; // esi
  CAI_ClassScheduleIdSpace *v6; // eax
  int v7; // eax

  for ( i = 0; i < nConditions; ++i )
  {
    v5 = pConditions[i];
    if ( v5 >= 1000000000 )
    {
      v7 = pConditions[i];
    }
    else
    {
      v6 = this->GetClassScheduleIdSpace(this);
      v7 = CAI_LocalIdSpace::LocalToGlobal(this: &v6->m_ConditionIds, localID: v5);
    }
    if ( v7 != -1 && v7 != 999999999 )
      this->m_InverseIgnoreConditions.m_Ints[(v7 - 1000000000) >> 5] &= ~(1 << (v7 & 0x1F));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F4E0
// Name: public: void CAI_BaseNPC::ClearIgnoreConditions(int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ClearIgnoreConditions(CAI_BaseNPC *this, int *pConditions, int nConditions)
{
  int i; // ebx
  int v5; // esi
  CAI_ClassScheduleIdSpace *v6; // eax
  int v7; // eax

  for ( i = 0; i < nConditions; ++i )
  {
    v5 = pConditions[i];
    if ( v5 >= 1000000000 )
    {
      v7 = pConditions[i];
    }
    else
    {
      v6 = this->GetClassScheduleIdSpace(this);
      v7 = CAI_LocalIdSpace::LocalToGlobal(this: &v6->m_ConditionIds, localID: v5);
    }
    if ( v7 != -1 && v7 != 999999999 )
      this->m_InverseIgnoreConditions.m_Ints[(v7 - 1000000000) >> 5] |= 1 << (v7 & 0x1F);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F560
// Name: public: bool CAI_BaseNPC::HasInterruptCondition(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::HasInterruptCondition(CAI_BaseNPC *this, int iCondition)
{
  CAI_ClassScheduleIdSpace *v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax

  if ( this->m_pSchedule == nullptr )
    return false;
  if ( iCondition >= 1000000000 )
  {
    v5 = iCondition;
  }
  else
  {
    v4 = this->GetClassScheduleIdSpace(this);
    v5 = CAI_LocalIdSpace::LocalToGlobal(this: &v4->m_ConditionIds, localID: iCondition);
  }
  if ( v5 == -1 )
    return false;
  v6 = v5 - 1000000000;
  if ( v5 == 999999999 )
    return false;
  v7 = 1 << (v5 & 0x1F);
  return (v7 & this->m_Conditions.m_Ints[v6 >> 5]) != 0
      && (v7 & this->m_pSchedule->m_InterruptMask.m_Ints[v6 >> 5]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001F5F0
// Name: public: virtual void CAI_BaseNPC::SetScriptedScheduleIgnoreConditions(enum Interruptability_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetScriptedScheduleIgnoreConditions(CAI_BaseNPC *this, Interruptability_t interrupt)
{
  CAI_BaseNPC::ClearIgnoreConditions(this, pConditions: g_GeneralConditions, nConditions: 14);
  CAI_BaseNPC::ClearIgnoreConditions(this, pConditions: g_DamageConditions, nConditions: 3);
  if ( interrupt > GENERAL_INTERRUPTABILITY )
    CAI_BaseNPC::SetIgnoreConditions(this, pConditions: g_GeneralConditions, nConditions: 14);
  if ( interrupt > DAMAGEORDEATH_INTERRUPTABILITY )
    CAI_BaseNPC::SetIgnoreConditions(this, pConditions: g_DamageConditions, nConditions: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1001F640
// Name: public: bool CAI_BaseNPC::IsCustomInterruptConditionSet(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsCustomInterruptConditionSet(CAI_BaseNPC *this, int nCondition)
{
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax

  if ( nCondition >= 1000000000 )
  {
    v4 = nCondition;
  }
  else
  {
    v3 = this->GetClassScheduleIdSpace(this);
    v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: nCondition);
  }
  return v4 != -1
      && v4 != 999999999
      && (this->m_CustomInterruptConditions.m_Ints[(v4 - 1000000000) >> 5] & (1 << (v4 & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001F6B0
// Name: public: void CAI_BaseNPC::SetCustomInterruptCondition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetCustomInterruptCondition(CAI_BaseNPC *this, int nCondition)
{
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax
  char v5; // cl
  unsigned int *v6; // eax

  if ( nCondition >= 1000000000 )
  {
    v4 = nCondition;
  }
  else
  {
    v3 = this->GetClassScheduleIdSpace(this);
    v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: nCondition);
  }
  if ( v4 != -1 )
  {
    v5 = v4;
    if ( v4 != 999999999 )
    {
      v6 = &this->m_CustomInterruptConditions.m_Ints[(v4 - 1000000000) >> 5];
      *v6 |= 1 << (v5 & 0x1F);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F710
// Name: public: void CAI_BaseNPC::ClearCustomInterruptCondition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ClearCustomInterruptCondition(CAI_BaseNPC *this, int nCondition)
{
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax
  char v5; // cl
  unsigned int *v6; // eax

  if ( nCondition >= 1000000000 )
  {
    v4 = nCondition;
  }
  else
  {
    v3 = this->GetClassScheduleIdSpace(this);
    v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: nCondition);
  }
  if ( v4 != -1 )
  {
    v5 = v4;
    if ( v4 != 999999999 )
    {
      v6 = &this->m_CustomInterruptConditions.m_Ints[(v4 - 1000000000) >> 5];
      *v6 &= ~(1 << (v5 & 0x1F));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F770
// Name: public: virtual bool CAI_BaseNPC::QueryHearSound(class CSound __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::QueryHearSound(CAI_BaseNPC *this, CSound *pSound)
{
  int m_iType; // eax
  bool result; // al
  CAI_BaseNPC_vtbl *v5; // ebx
  const Vector *SoundReactOrigin; // eax
  CBaseEntity *v7; // eax
  const char *pszValue; // [esp-4h] [ebp-Ch]

  m_iType = pSound->m_iType;
  result = (m_iType & 0x800000) == 0
        && ((m_iType & 0x10000000) == 0 || this->IsPlayerAlly(this, a2: nullptr))
        && ((pSound->m_iType & 4) == 0
         || this->m_NPCState != NPC_STATE_IDLE
         || (v5 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable,
             SoundReactOrigin = CSound::GetSoundReactOrigin(this: pSound),
             v5->FVisible(this, a2: SoundReactOrigin, a3: 16449, a4: nullptr)))
        && ((pSound->m_iType & 1) == 0
         || pSound->m_ownerChannelIndex != 7
         || CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &pSound->m_hOwner) == nullptr
         || (pszValue = this->m_iClassname.pszValue,
             v7 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &pSound->m_hOwner),
             !CBaseEntity::ClassMatches(this: v7, nameStr: (string_t)pszValue)))
        && !this->ShouldIgnoreSound(this, a2: pSound);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001F820
// Name: public: virtual void CAI_BaseNPC::SetHeadDirection(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_BaseNPC::SetHeadDirection(
        CAI_BaseNPC *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vTargetPos,
        float flInterval)
{
  float v7; // xmm1_4
  float v8; // xmm3_4
  float y; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float m_flHeadYaw; // xmm1_4
  float v14; // xmm0_4
  __int128 v15; // xmm1
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float m_flHeadPitch; // xmm2_4
  float v22[3]; // [esp+1Ch] [ebp-38h] BYREF
  __int128 vEyePosition; // [esp+28h] [ebp-2Ch] OVERLAPPED BYREF
  long double v24; // [esp+44h] [ebp-10h]
  void *v25; // [esp+4Ch] [ebp-8h]
  void *retaddr; // [esp+54h] [ebp+0h]

  HIDWORD(v24) = a2;
  v25 = retaddr;
  if ( (((int (__thiscall *)(CAI_BaseNPC *, int, int))this->CapabilitiesGet)(a1: this, a2: a3, a3: a4) & 0x1000) != 0 )
  {
    v7 = vTargetPos->y - this->m_vecOrigin.m_Value.y;
    v8 = vTargetPos->z - this->m_vecOrigin.m_Value.z;
    *((float *)&vEyePosition + 1) = vTargetPos->x - this->m_vecOrigin.m_Value.x;
    *((_QWORD *)&vEyePosition + 1) = __PAIR64__(LODWORD(v8), LODWORD(v7));
    if ( *((float *)&vEyePosition + 1) == 0.0 && v7 == 0.0 && v8 == 0.0 )
    {
      y = this->m_angRotation.m_Value.y;
    }
    else
    {
      *(float *)&v24 = UTIL_VecToYaw(vec: (const Vector *)((char *)&vEyePosition + 4));
      y = *(float *)&v24;
    }
    v10 = y - this->m_angRotation.m_Value.y;
    if ( v10 > 180.0 )
      v10 = v10 - 360.0;
    if ( v10 < -180.0 )
      v10 = v10 + 360.0;
    v11 = flInterval;
    if ( flInterval > 0.0 )
    {
      v12 = v10 * 0.19999999;
      m_flHeadYaw = this->m_flHeadYaw;
      do
      {
        v11 = v11 - 0.1;
        m_flHeadYaw = (float)(m_flHeadYaw * 0.80000001) + v12;
      }
      while ( v11 > 0.0 );
      this->m_flHeadYaw = m_flHeadYaw;
    }
    if ( this->m_flHeadYaw > 360.0 )
      this->m_flHeadYaw = 0.0;
    this->m_flHeadYaw = CBaseAnimating::SetBoneController(this, iController: 0, flValue: this->m_flHeadYaw);
    this->EyePosition(this, result: (Vector *)v22);
    v14 = vTargetPos->z - v22[2];
    v15 = 0;
    *(float *)&v15 = fsqrt(
                       (float)((float)((float)(vTargetPos->y - v22[1]) * (float)(vTargetPos->y - v22[1]))
                             + (float)(v14 * v14))
                     + (float)((float)(vTargetPos->x - v22[0]) * (float)(vTargetPos->x - v22[0])));
    vEyePosition = v15;
    v16 = v14 / *(float *)&v15;
    __libm_sse2_atan(x: v24);
    v17 = flInterval;
    LODWORD(v18) = COERCE_UNSIGNED_INT(v16 * 57.29578) ^ _mask__NegFloat_;
    if ( flInterval > 0.0 )
    {
      v19 = v18 * 0.19999999;
      m_flHeadPitch = this->m_flHeadPitch;
      do
      {
        v17 = v17 - 0.1;
        m_flHeadPitch = (float)(m_flHeadPitch * 0.80000001) + v19;
      }
      while ( v17 > 0.0 );
      this->m_flHeadPitch = m_flHeadPitch;
    }
    if ( this->m_flHeadPitch > 360.0 )
      this->m_flHeadPitch = 0.0;
    CBaseAnimating::SetBoneController(this, iController: 1, flValue: this->m_flHeadPitch);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FA80
// Name: public: virtual class CBaseEntity __near * CAI_BaseNPC::EyeLookTarget(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__usercall CAI_BaseNPC::EyeLookTarget@<eax>(CAI_BaseNPC *this@<ecx>, int a2@<ebp>)
{
  unsigned int v3; // ecx
  CAI_BaseNPC *CurrentEntity; // esi
  float *v5; // eax
  __int128 v6; // xmm0
  int v7; // eax
  int v8; // esi
  unsigned int m_Index; // edi
  _DWORD v11[3]; // [esp+18h] [ebp-84Ch] BYREF
  CEntitySphereQuery sphere; // [esp+24h] [ebp-840h] BYREF
  int v13; // [esp+82Ch] [ebp-38h] BYREF
  __int128 v14; // [esp+838h] [ebp-2Ch]
  bool (__thiscall **p_ValidEyeTarget)(CAI_BaseNPC *, const Vector *); // [esp+84Ch] [ebp-18h]
  unsigned __int64 v16; // [esp+850h] [ebp-14h]
  int v17; // [esp+858h] [ebp-Ch]
  float fBestDist; // [esp+85Ch] [ebp-8h]
  float retaddr; // [esp+864h] [ebp+0h]

  v17 = a2;
  fBestDist = retaddr;
  if ( gpGlobals->curtime > this->m_flNextEyeLookTime )
  {
    v3 = (unsigned int)this->m_iEFlags >> 11;
    v16 = 1182793728;
    if ( (v3 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    CEntitySphereQuery::CEntitySphereQuery(
      this: (CEntitySphereQuery *)v11,
      center: &this->m_vecAbsOrigin,
      radius: 1024.0,
      flagMask: 0);
    CurrentEntity = (CAI_BaseNPC *)CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v11);
    if ( CurrentEntity != nullptr )
    {
      do
      {
        if ( CurrentEntity != this
          && (CurrentEntity->MyNPCPointer(this: CurrentEntity) != nullptr
           || (CurrentEntity->m_fFlags.m_Value & 0x100) != 0) )
        {
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this);
          v5 = (float *)CurrentEntity->EyePosition(this: CurrentEntity, result: (Vector *)&v13);
          v6 = 0;
          *(float *)&v6 = fsqrt(
                            (float)((float)((float)(this->m_vecAbsOrigin.y - v5[1])
                                          * (float)(this->m_vecAbsOrigin.y - v5[1]))
                                  + (float)((float)(this->m_vecAbsOrigin.z - v5[2])
                                          * (float)(this->m_vecAbsOrigin.z - v5[2])))
                          + (float)((float)(this->m_vecAbsOrigin.x - *v5) * (float)(this->m_vecAbsOrigin.x - *v5)));
          v14 = v6;
          if ( *(float *)&v16 > *(float *)&v6 )
          {
            p_ValidEyeTarget = &this->ValidEyeTarget;
            v7 = (int)CurrentEntity->EyePosition(this: CurrentEntity, result: (Vector *)&sphere.m_pList[509]);
            if ( (*p_ValidEyeTarget)(this, a2: (const Vector *)v7) )
              v16 = __PAIR64__((unsigned int)CurrentEntity, v14);
          }
        }
        ++v11[0];
        CurrentEntity = (CAI_BaseNPC *)CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v11);
      }
      while ( CurrentEntity != nullptr );
      v8 = HIDWORD(v16);
      if ( HIDWORD(v16) != 0 )
      {
        this->m_flNextEyeLookTime = (float)random->RandomInt(this: random, a2: 1, a3: 5) + gpGlobals->curtime;
        this->m_hEyeLookTarget.m_Index = *(_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
      }
    }
  }
  m_Index = this->m_hEyeLookTarget.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1001FC90
// Name: protected: virtual void CAI_BaseNPC::PopulatePoseParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::PopulatePoseParameters(CAI_BaseNPC *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  int v3; // eax
  bool v4; // zf
  CStudioHdr *v5; // eax
  int v6; // eax
  CStudioHdr *v7; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v3 = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: m_pStudioHdr, szName: "aim_pitch");
  v4 = this->m_pStudioHdr == nullptr;
  this->m_poseAim_Pitch = v3;
  if ( v4 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v5 = this->m_pStudioHdr;
  if ( v5 == nullptr || v5->m_pStudioHdr == nullptr )
    v5 = nullptr;
  v6 = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: v5, szName: "aim_yaw");
  v4 = this->m_pStudioHdr == nullptr;
  this->m_poseAim_Yaw = v6;
  if ( v4 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v7 = this->m_pStudioHdr;
  if ( v7 == nullptr || v7->m_pStudioHdr == nullptr )
    v7 = nullptr;
  this->m_poseMove_Yaw = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: v7, szName: "move_yaw");
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1001FD60
// Name: public: virtual void CAI_BaseNPC::SetAim(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetAim(CAI_BaseNPC *this, const Vector *aimDir)
{
  double v3; // st7
  unsigned int v4; // ecx
  double v5; // st7
  double v6; // st7
  double v7; // st7
  unsigned int v8; // edx
  double v9; // st7
  int m_poseAim_Pitch; // edi
  CStudioHdr *m_pStudioHdr; // eax
  int m_poseAim_Yaw; // edi
  CStudioHdr *v13; // eax
  QAngle angDir; // [esp+10h] [ebp-14h] BYREF
  float newPitch; // [esp+1Ch] [ebp-8h]
  float curYaw; // [esp+20h] [ebp-4h]
  float flRelativeYaw; // [esp+2Ch] [ebp+8h]
  float flRelativeYawb; // [esp+2Ch] [ebp+8h]
  float flRelativeYawc; // [esp+2Ch] [ebp+8h]
  float flRelativeYawd; // [esp+2Ch] [ebp+8h]
  float flRelativeYawa; // [esp+2Ch] [ebp+8h]

  VectorAngles(forward: aimDir, angles: &angDir);
  flRelativeYaw = CBaseAnimating::GetPoseParameter(this, iParameter: this->m_poseAim_Pitch);
  curYaw = CBaseAnimating::GetPoseParameter(this, iParameter: this->m_poseAim_Yaw);
  if ( this->GetEnemy_2(this) != nullptr )
  {
    newPitch = ApproachAngle(target: angDir.x, value: flRelativeYaw, speed: 20.0);
    v3 = AngleDiff(destAngle: newPitch, srcAngle: flRelativeYaw);
    v4 = (unsigned int)this->m_iEFlags >> 11;
    newPitch = v3 * 0.8 + flRelativeYaw;
    if ( (v4 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    flRelativeYawb = AngleDiff(destAngle: angDir.y, srcAngle: this->m_angAbsRotation.y);
    v5 = AngleDiff(destAngle: flRelativeYawb, srcAngle: curYaw);
    v6 = v5 + curYaw;
  }
  else
  {
    newPitch = ApproachAngle(target: angDir.x, value: flRelativeYaw, speed: 20.0);
    v7 = AngleDiff(destAngle: newPitch, srcAngle: flRelativeYaw);
    v8 = (unsigned int)this->m_iEFlags >> 11;
    newPitch = v7 * 0.6 + flRelativeYaw;
    if ( (v8 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    flRelativeYawc = AngleDiff(destAngle: angDir.y, srcAngle: this->m_angAbsRotation.y);
    v9 = AngleDiff(destAngle: flRelativeYawc, srcAngle: curYaw);
    v6 = v9 * 0.6 + curYaw;
  }
  flRelativeYawd = v6;
  newPitch = AngleNormalize(angle: newPitch);
  flRelativeYawa = AngleNormalize(angle: flRelativeYawd);
  m_poseAim_Pitch = this->m_poseAim_Pitch;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: m_pStudioHdr, iParameter: m_poseAim_Pitch, flValue: newPitch);
  m_poseAim_Yaw = this->m_poseAim_Yaw;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v13 = this->m_pStudioHdr;
  if ( v13 == nullptr || v13->m_pStudioHdr == nullptr )
    v13 = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: v13, iParameter: m_poseAim_Yaw, flValue: flRelativeYawa);
  if ( COERCE_FLOAT(LODWORD(flRelativeYawa) & _mask__AbsFloat_) >= 20.0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    this->m_flInteractionYaw = this->m_angAbsRotation.y;
  }
  else
  {
    this->m_flInteractionYaw = angDir.y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020010
// Name: public: virtual void CAI_BaseNPC::RelaxAim(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RelaxAim(CAI_BaseNPC *this)
{
  int m_poseAim_Pitch; // edi
  CStudioHdr *m_pStudioHdr; // eax
  int m_poseAim_Yaw; // edi
  CStudioHdr *v5; // eax
  float newYawa; // [esp+14h] [ebp-8h]
  float newYawb; // [esp+14h] [ebp-8h]
  float newYaw; // [esp+14h] [ebp-8h]
  float newPitcha; // [esp+18h] [ebp-4h]
  float newPitchb; // [esp+18h] [ebp-4h]
  float newPitch; // [esp+18h] [ebp-4h]

  newPitcha = CBaseAnimating::GetPoseParameter(this, iParameter: this->m_poseAim_Pitch);
  newYawa = CBaseAnimating::GetPoseParameter(this, iParameter: this->m_poseAim_Yaw);
  newPitchb = ApproachAngle(target: 0.0, value: newPitcha, speed: 3.0);
  newPitch = AngleNormalize(angle: newPitchb);
  newYawb = ApproachAngle(target: 0.0, value: newYawa, speed: 2.0);
  newYaw = AngleNormalize(angle: newYawb);
  m_poseAim_Pitch = this->m_poseAim_Pitch;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: m_pStudioHdr, iParameter: m_poseAim_Pitch, flValue: newPitch);
  m_poseAim_Yaw = this->m_poseAim_Yaw;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v5 = this->m_pStudioHdr;
  if ( v5 == nullptr || v5->m_pStudioHdr == nullptr )
    v5 = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: v5, iParameter: m_poseAim_Yaw, flValue: newYaw);
}

//------------------------------------------------------------------------------
// Address: 0x10020160
// Name: public: virtual void CAI_BaseNPC::MaintainLookTargets(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAI_BaseNPC::MaintainLookTargets(CAI_BaseNPC *this@<ecx>, int a2@<ebx>, unsigned int flInterval)
{
  CBaseEntity *v4; // eax
  CAI_BaseNPC_vtbl *v5; // edi
  int v6; // eax
  CBaseEntity *v7; // eax
  CAI_BaseNPC_vtbl *v8; // edi
  int v9; // eax
  CBaseEntity *v10; // eax
  CAI_BaseNPC_vtbl *v11; // edi
  int v12; // eax
  CAI_BaseNPC_vtbl *v13; // edi
  const Vector *v14; // eax
  CAI_BaseNPC_vtbl *v15; // edi
  const Vector *CurWaypointPos; // eax
  CAI_BaseNPC_vtbl *v17; // edi
  const Vector *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  CAI_ClassScheduleIdSpace *v22; // eax
  int v23; // eax
  int v24; // eax
  CSound *v25; // eax
  CSound *v26; // edi
  CAI_BaseNPC_vtbl *v27; // ebx
  const Vector *v28; // eax
  CAI_BaseNPC_vtbl *v29; // ebx
  const Vector *SoundOrigin; // eax
  CAI_BaseNPC_vtbl *v31; // ebx
  const Vector *v32; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v34; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  __m128 v37; // xmm5
  float v38; // xmm3_4
  float m_flEyeIntegRate; // xmm4_4
  float v40; // xmm0_4
  float v41; // xmm4_4
  float v42; // xmm6_4
  float v43; // xmm0_4
  float x; // xmm1_4
  float v45; // xmm2_4
  __m128d v46; // xmm0
  Vector v47; // [esp+1Ch] [ebp-24h] BYREF
  Vector vBodyDir; // [esp+28h] [ebp-18h] BYREF
  float v49; // [esp+34h] [ebp-Ch]
  float v50; // [esp+38h] [ebp-8h]
  float v51; // [esp+3Ch] [ebp-4h]

  if ( this->GetEnemy_2(this) != nullptr
    && (v4 = this->GetEnemy_2(this),
        v5 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable,
        v6 = (int)v4->EyePosition(this: v4, result: &vBodyDir),
        v5->ValidEyeTarget(this, a2: (const Vector *)v6)) )
  {
    v7 = this->GetEnemy_2(this);
    v8 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v9 = ((int (__thiscall *)(CBaseEntity *, Vector *, unsigned int))v7->EyePosition)(
           a1: v7,
           a2: &vBodyDir,
           a3: flInterval);
    ((void (__thiscall *)(CAI_BaseNPC *, int))v8->SetHeadDirection)(a1: this, a2: v9);
    v10 = this->GetEnemy_2(this);
    v11 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v12 = (int)v10->EyePosition(this: v10, result: &vBodyDir);
    v11->SetViewtarget(this, a2: (const Vector *)v12);
  }
  else if ( CAI_Navigator::IsGoalActive(this: this->m_pNavigator)
         && (v13 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable,
             v14 = CAI_Navigator::GetCurWaypointPos(this: this->m_pNavigator),
             v13->ValidEyeTarget(this, a2: v14)) )
  {
    v15 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    CurWaypointPos = CAI_Navigator::GetCurWaypointPos(this: this->m_pNavigator);
    ((void (__thiscall *)(CAI_BaseNPC *, const Vector *, unsigned int))v15->SetHeadDirection)(
      a1: this,
      a2: CurWaypointPos,
      a3: flInterval);
    v17 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v18 = CAI_Navigator::GetCurWaypointPos(this: this->m_pNavigator);
    v17->SetViewtarget(this, a2: v18);
  }
  else
  {
    v19 = ((int (__thiscall *)(CAI_BaseNPC *, int))this->GetClassScheduleIdSpace)(a1: this, a2);
    v20 = CAI_LocalIdSpace::LocalToGlobal(this: (CAI_LocalIdSpace *)(v19 + 52), localID: 53);
    if ( v20 == -1 || (v21 = v20 - 1000000000) == -1 || ((1 << (v21 & 0x1F)) & this->m_Conditions.m_Ints[v21 >> 5]) == 0 )
    {
      v22 = this->GetClassScheduleIdSpace(this);
      v23 = CAI_LocalIdSpace::LocalToGlobal(this: &v22->m_ConditionIds, localID: 50);
      if ( v23 == -1 )
        goto LABEL_18;
      v24 = v23 - 1000000000;
      if ( v24 == -1 || ((1 << (v24 & 0x1F)) & this->m_Conditions.m_Ints[v24 >> 5]) == 0 )
        goto LABEL_18;
    }
    v25 = this->GetBestSound(this, a2: 1048351);
    v26 = v25;
    if ( v25 != nullptr
      && (v25->m_iType & 9) != 0
      && (v27 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable,
          v28 = CSound::GetSoundOrigin(this: v25),
          v27->ValidEyeTarget(this, a2: v28)) )
    {
      v29 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      SoundOrigin = CSound::GetSoundOrigin(this: v26);
      ((void (__thiscall *)(CAI_BaseNPC *, const Vector *))v29->SetHeadDirection)(a1: this, a2: SoundOrigin);
      v31 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v32 = CSound::GetSoundOrigin(this: v26);
      v31->SetViewtarget(this, a2: v32);
    }
    else
    {
LABEL_18:
      if ( this->m_flNextEyeLookTime > gpGlobals->curtime && !this->ValidEyeTarget(this, a2: &this->m_vEyeLookTarget) )
        this->m_flNextEyeLookTime = 0.0;
      if ( gpGlobals->curtime > this->m_flNextEyeLookTime )
      {
        this->BodyDirection2D(this, result: &vBodyDir);
        EyePosition = this->EyePosition;
        v49 = vBodyDir.x * 500.0;
        v50 = vBodyDir.y * 500.0;
        v51 = vBodyDir.z * 500.0;
        v34 = (float *)EyePosition(this, result: &v47);
        v35 = v34[1] + v50;
        v36 = v34[2] + v51;
        this->m_vEyeLookTarget.x = *v34 + v49;
        this->m_vEyeLookTarget.y = v35;
        this->m_vEyeLookTarget.z = v36;
        this->m_flNextEyeLookTime = gpGlobals->curtime + 0.5;
      }
      ((void (__thiscall *)(CAI_BaseNPC *, Vector *, unsigned int))this->SetHeadDirection)(
        a1: this,
        a2: &this->m_vEyeLookTarget,
        a3: flInterval);
      v37 = (__m128)flInterval;
      if ( *(float *)&flInterval > 0.0 )
      {
        do
        {
          v38 = this->m_flEyeIntegRate * this->m_vEyeLookTarget.x;
          m_flEyeIntegRate = this->m_flEyeIntegRate;
          v40 = m_flEyeIntegRate * this->m_vEyeLookTarget.z;
          v41 = m_flEyeIntegRate * this->m_vEyeLookTarget.y;
          v42 = v40;
          v43 = 1.0 - this->m_flEyeIntegRate;
          x = this->m_vCurEyeTarget.x;
          v45 = v43 * this->m_vCurEyeTarget.y;
          this->m_vCurEyeTarget.z = (float)(v43 * this->m_vCurEyeTarget.z) + v42;
          this->m_vCurEyeTarget.x = (float)(x * v43) + v38;
          this->m_vCurEyeTarget.y = v45 + v41;
          v46 = _mm_cvtps_pd(v37);
          v46.m128d_f64[0] = v46.m128d_f64[0] - 0.1;
          v37 = _mm_cvtpd_ps(v46);
        }
        while ( v37.m128_f32[0] > 0.0 );
      }
      this->SetViewtarget(this, a2: &this->m_vCurEyeTarget);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020550
// Name: private: void CAI_BaseNPC::PerformMovement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::PerformMovement(CAI_BaseNPC *this)
{
  float m_flTimeLastMovement; // xmm0_4
  double v3; // xmm1_8
  float v4; // xmm1_4

  if ( this->IsAlive(this) )
  {
    g_AIMoveTimer.m_Duration.m_Int64 = __rdtsc();
    m_flTimeLastMovement = this->m_flTimeLastMovement;
    if ( m_flTimeLastMovement == 3.4028235e38 )
      v3 = 0.1;
    else
      v3 = (float)(gpGlobals->curtime - m_flTimeLastMovement);
    v4 = v3;
    ((void (__stdcall *)(_DWORD))this->m_pNavigator->Move)(a1: (float)(int)(float)((float)(v4
                                                                                         / gpGlobals->interval_per_tick)
                                                                                 + 0.5) * gpGlobals->interval_per_tick);
    this->m_flTimeLastMovement = gpGlobals->curtime;
    g_AIMoveTimer.m_Duration.m_Int64 = __rdtsc() - g_AIMoveTimer.m_Duration.m_Int64;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020630
// Name: private: void CAI_BaseNPC::PostRun(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::PostRun(CAI_BaseNPC *this)
{
  Activity m_IdealActivity; // eax

  g_AIPostRunTimer.m_Duration.m_Int64 = __rdtsc();
  if ( !this->IsMoving(this) )
  {
    m_IdealActivity = this->m_IdealActivity;
    if ( m_IdealActivity == ACT_WALK
      || m_IdealActivity == ACT_RUN
      || m_IdealActivity == ACT_WALK_AIM
      || m_IdealActivity == ACT_RUN_AIM )
    {
      this->PostRunStopMoving(this);
    }
  }
  CAI_BaseNPC::RunAnimation(this);
  this->Weapon_FrameUpdate(this);
  g_AIPostRunTimer.m_Duration.m_Int64 = __rdtsc() - g_AIPostRunTimer.m_Duration.m_Int64;
}

//------------------------------------------------------------------------------
// Address: 0x100206D0
// Name: public: virtual bool CAI_BaseNPC::ShouldAlwaysThink(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::ShouldAlwaysThink(CAI_BaseNPC *this)
{
  return (this->m_spawnflags.m_Value & 0x400) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100206E0
// Name: public: virtual bool CAI_BaseNPC::ShouldPlayerAvoid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::ShouldPlayerAvoid(CAI_BaseNPC *this)
{
  return this->m_NPCState == NPC_STATE_SCRIPT
      || this->m_bInAScript
      || this->m_flSceneTime > gpGlobals->curtime
      || (this->m_spawnflags.m_Value & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10020720
// Name: public: virtual void CAI_BaseNPC::UpdateEfficiency(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::UpdateEfficiency(CAI_BaseNPC *this, bool bInPVS)
{
  bool v3; // al
  CBasePlayer *LocalPlayer; // esi
  unsigned int v5; // eax
  bool v6; // al
  bool v7; // bl
  edict_t *ClientInVisibilityPVS; // eax
  AI_Efficiency_t m_nValue; // eax
  float v10; // xmm0_4
  bool v11; // bl
  NPC_STATE m_NPCState; // eax
  AI_Efficiency_t v13; // ebx
  int active; // eax
  CSound *v15; // esi
  const Vector *SoundOrigin; // eax
  int v18; // esi
  float v19; // xmm1_4
  NPC_STATE v20; // eax
  int v21; // ecx
  int v22; // eax
  AI_Efficiency_t v23; // ebx
  AI_Efficiency_t v24; // esi
  Vector vEarPosition; // [esp+8h] [ebp-30h] BYREF
  Vector vToNPC; // [esp+14h] [ebp-24h] BYREF
  float flHearDistanceSq; // [esp+20h] [ebp-18h]
  float hearingSensitivity; // [esp+24h] [ebp-14h]
  AI_Efficiency_t minEfficiency; // [esp+28h] [ebp-10h]
  CBasePlayer *pPlayer; // [esp+2Ch] [ebp-Ch]
  float playerDist; // [esp+30h] [ebp-8h]
  bool bInVisibilityPVS; // [esp+36h] [ebp-2h]
  bool bPlayerFacing; // [esp+37h] [ebp-1h]
  int state; // [esp+40h] [ebp+8h]

  if ( this->m_SleepState != AISS_AWAKE )
  {
    this->m_Efficiency = AIE_DORMANT;
    return;
  }
  v3 = this->m_NPCState == NPC_STATE_SCRIPT || CAI_BaseNPC::IsCurSchedule(this, schedId: 63, fIdeal: false);
  this->m_bInChoreo = v3;
  if ( ai_use_think_optimizations.m_pParent == nullptr
    || ai_use_think_optimizations.m_pParent->m_Value.m_nValue == 0
    || ai_use_efficiency.m_pParent == nullptr
    || ai_use_efficiency.m_pParent->m_Value.m_nValue == 0 )
  {
    this->m_Efficiency = AIE_NORMAL;
    this->m_MoveEfficiency = AIME_NORMAL;
    return;
  }
  if ( gpGlobals->maxClients <= 1 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
    pPlayer = LocalPlayer;
  }
  else
  {
    LocalPlayer = nullptr;
    pPlayer = nullptr;
  }
  v5 = _S2_2;
  if ( (_S2_2 & 1) == 0 )
  {
    v5 = _S2_2 | 1;
    _S2_2 |= 1u;
  }
  if ( (v5 & 2) == 0 )
    _S2_2 = v5 | 2;
  if ( gpGlobals->framecount != iPrevFrame_0 )
  {
    iPrevFrame_0 = gpGlobals->framecount;
    if ( LocalPlayer != nullptr )
      CBasePlayer::EyePositionAndVectors(
        this: LocalPlayer,
        pPosition: &vPlayerEyePosition,
        pForward: &vPlayerForward,
        pRight: nullptr,
        pUp: nullptr);
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  vToNPC.x = this->m_vecAbsOrigin.x - vPlayerEyePosition.x;
  vToNPC.y = this->m_vecAbsOrigin.y - vPlayerEyePosition.y;
  vToNPC.z = this->m_vecAbsOrigin.z - vPlayerEyePosition.z;
  playerDist = VectorNormalize(vec: &vToNPC);
  v6 = UTIL_ClientPVSIsExpanded();
  v7 = v6;
  if ( LocalPlayer == nullptr )
  {
    playerDist = 0.0;
    goto LABEL_29;
  }
  if ( v6
    || bInPVS
    && (float)((float)((float)(vToNPC.y * vPlayerForward.y) + (float)(vToNPC.x * vPlayerForward.x))
             + (float)(vToNPC.z * vPlayerForward.z)) > 0.0 )
  {
LABEL_29:
    bPlayerFacing = true;
    if ( v6 )
    {
      ClientInVisibilityPVS = UTIL_FindClientInVisibilityPVS(pEdict: this->m_Network.m_pPev);
      bInVisibilityPVS = true;
      if ( ClientInVisibilityPVS != nullptr )
        goto LABEL_32;
    }
    goto LABEL_31;
  }
  bPlayerFacing = false;
LABEL_31:
  bInVisibilityPVS = false;
LABEL_32:
  this->m_MoveEfficiency = (!bInPVS || !bPlayerFacing && playerDist >= 300.0) && !v7;
  if ( ai_efficiency_override.m_pParent != nullptr )
  {
    m_nValue = ai_efficiency_override.m_pParent->m_Value.m_nValue;
    if ( m_nValue > AIE_NORMAL && m_nValue <= AIE_DORMANT )
      goto LABEL_96;
  }
  v10 = gpGlobals->curtime - this->m_flLastAttackTime;
  if ( v10 < 0.15 )
  {
    this->m_Efficiency = AIE_NORMAL;
    return;
  }
  v11 = ai_frametime_limit.m_pParent->m_Value.m_fValue > gpGlobals->frametime;
  if ( this->m_bForceConditionsGather
    || v10 < 0.2
    || (float)(gpGlobals->curtime - this->m_flLastDamageTime) < 0.2
    || (m_NPCState = this->m_NPCState) < NPC_STATE_IDLE
    || m_NPCState > NPC_STATE_SCRIPT
    || (bInPVS || bInVisibilityPVS)
    && (CAI_BaseNPC::GetTask(this) != nullptr && !CAI_BaseNPC::TaskIsRunning(this)
     || this->m_ScheduleState.iTaskInterrupt > 0
     || this->m_bInChoreo) )
  {
    m_nValue = !v11;
LABEL_96:
    this->m_Efficiency = m_nValue;
    return;
  }
  if ( ai_use_think_optimizations.m_pParent != nullptr
    && ai_use_think_optimizations.m_pParent->m_Value.m_nValue != 0
    && ai_default_efficient.m_pParent != nullptr
    && ai_default_efficient.m_pParent->m_Value.m_nValue != 0 )
  {
    v13 = !v11 + 1;
    minEfficiency = v13;
  }
  else
  {
    v13 = !v11;
    minEfficiency = v13;
  }
  if ( (this->GetSoundInterests(this) & 8) != 0 )
  {
    active = CSoundEnt::ActiveList();
    if ( active != -1 )
    {
      while ( 1 )
      {
        v15 = CSoundEnt::SoundPointerForIndex(iIndex: active);
        hearingSensitivity = this->HearingSensitivity(this);
        this->EarPosition(this, result: &vEarPosition);
        if ( v15 != nullptr && (v15->m_iType & 8) != 0 )
        {
          flHearDistanceSq = (float)v15->m_iVolume * hearingSensitivity;
          SoundOrigin = CSound::GetSoundOrigin(this: v15);
          if ( (float)(flHearDistanceSq * flHearDistanceSq) >= (float)((float)((float)((float)(SoundOrigin->y
                                                                                             - vEarPosition.y)
                                                                                     * (float)(SoundOrigin->y
                                                                                             - vEarPosition.y))
                                                                             + (float)((float)(SoundOrigin->x
                                                                                             - vEarPosition.x)
                                                                                     * (float)(SoundOrigin->x
                                                                                             - vEarPosition.x)))
                                                                     + (float)((float)(SoundOrigin->z - vEarPosition.z)
                                                                             * (float)(SoundOrigin->z - vEarPosition.z))) )
            goto LABEL_70;
        }
        active = v15->m_iNext;
        if ( active == -1 )
        {
          LocalPlayer = pPlayer;
          break;
        }
      }
    }
  }
  if ( LocalPlayer == nullptr )
  {
LABEL_70:
    this->m_Efficiency = v13;
    return;
  }
  if ( bInPVS )
  {
    if ( playerDist < 180.0 )
      goto LABEL_70;
    if ( playerDist < 600.0 )
    {
      v18 = 0;
      goto LABEL_79;
    }
    v19 = 2400.0;
  }
  else
  {
    if ( playerDist < 300.0 )
    {
      v18 = 0;
      goto LABEL_79;
    }
    v19 = 1200.0;
  }
  v18 = 1;
  if ( v19 <= playerDist )
    v18 = 2;
LABEL_79:
  v20 = this->m_NPCState;
  state = v20;
  if ( v20 == NPC_STATE_SCRIPT )
  {
    v20 = NPC_STATE_ALERT;
    state = 2;
  }
  v21 = *((_DWORD *)&FLOAT_500_0 + v20);
  if ( !bInPVS || bPlayerFacing )
    v22 = 0;
  else
    v22 = 3;
  v23 = mappings[v18 + v21 + v22 + (bInPVS ? 0 : 6)];
  v24 = AIE_SUPER_EFFICIENT;
  if ( bInVisibilityPVS )
  {
    if ( state >= 2 )
    {
      v24 = AIE_EFFICIENT;
      goto LABEL_90;
    }
  }
  else if ( !CAI_BaseNPC::HasCondition(this, iCondition: 32) )
  {
    goto LABEL_90;
  }
  v24 = AIE_VERY_EFFICIENT;
LABEL_90:
  if ( v23 >= minEfficiency )
  {
    if ( v23 <= v24 )
      v24 = v23;
    this->m_Efficiency = v24;
  }
  else
  {
    this->m_Efficiency = minEfficiency;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020C40
// Name: public: virtual int CAI_BaseNPC::MeleeAttack1Conditions(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::MeleeAttack1Conditions(CAI_BaseNPC *this, float flDot, float flDist)
{
  if ( flDist > 64.0 )
    return 39;
  if ( flDot >= 0.7 && this->GetEnemy_2(this) != nullptr )
    return (this->GetEnemy_2(this)->m_fFlags.m_Value & 1) != 0 ? 0x17 : 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10020CB0
// Name: public: virtual void CAI_BaseNPC::ClearAttackConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ClearAttackConditions(CAI_BaseNPC *this)
{
  CAI_ClassScheduleIdSpace *v2; // eax
  int v3; // eax
  int v4; // edi
  CAI_ClassScheduleIdSpace *v5; // eax
  int v6; // eax
  int v7; // eax
  CAI_ClassScheduleIdSpace *v8; // eax
  int v9; // eax
  int v10; // edi
  CAI_ClassScheduleIdSpace *v11; // eax
  int v12; // eax
  int v13; // eax
  CAI_ClassScheduleIdSpace *v14; // eax
  int v15; // eax
  int v16; // edi
  CAI_ClassScheduleIdSpace *v17; // eax
  int v18; // eax
  int v19; // eax
  CAI_ClassScheduleIdSpace *v20; // eax
  int v21; // eax
  int v22; // edi
  CAI_ClassScheduleIdSpace *v23; // eax
  int v24; // eax
  int v25; // eax
  CAI_ClassScheduleIdSpace *v26; // eax
  int v27; // eax
  int v28; // edi
  CAI_ClassScheduleIdSpace *v29; // eax
  int v30; // eax
  int v31; // eax
  CAI_ClassScheduleIdSpace *v32; // eax
  int v33; // eax
  int v34; // edi
  CAI_ClassScheduleIdSpace *v35; // eax
  int v36; // eax
  int v37; // eax
  CAI_ClassScheduleIdSpace *v38; // eax
  int v39; // eax
  int v40; // edi
  CAI_ClassScheduleIdSpace *v41; // eax
  int v42; // eax
  int v43; // eax
  CAI_ClassScheduleIdSpace *v44; // eax
  int v45; // eax
  int v46; // edi
  CAI_ClassScheduleIdSpace *v47; // eax
  int v48; // eax
  int v49; // eax
  CAI_ClassScheduleIdSpace *v50; // eax
  int v51; // eax
  int v52; // edi
  CAI_ClassScheduleIdSpace *v53; // eax
  int v54; // eax
  int v55; // eax

  v2 = this->GetClassScheduleIdSpace(this);
  v3 = CAI_LocalIdSpace::LocalToGlobal(this: &v2->m_ConditionIds, localID: 21);
  if ( v3 != -1 )
  {
    v4 = v3 - 1000000000;
    if ( v3 != 999999999 )
    {
      v5 = this->GetClassScheduleIdSpace(this);
      v6 = CAI_LocalIdSpace::LocalToGlobal(this: &v5->m_ConditionIds, localID: 21);
      if ( v6 != -1 )
      {
        v7 = v6 - 1000000000;
        if ( v7 != -1 && ((1 << (v7 & 0x1F)) & this->m_Conditions.m_Ints[v7 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 21);
      }
      this->m_Conditions.m_Ints[v4 >> 5] &= ~(1 << (v4 & 0x1F));
    }
  }
  v8 = this->GetClassScheduleIdSpace(this);
  v9 = CAI_LocalIdSpace::LocalToGlobal(this: &v8->m_ConditionIds, localID: 22);
  if ( v9 != -1 )
  {
    v10 = v9 - 1000000000;
    if ( v9 != 999999999 )
    {
      v11 = this->GetClassScheduleIdSpace(this);
      v12 = CAI_LocalIdSpace::LocalToGlobal(this: &v11->m_ConditionIds, localID: 22);
      if ( v12 != -1 )
      {
        v13 = v12 - 1000000000;
        if ( v13 != -1 && ((1 << (v13 & 0x1F)) & this->m_Conditions.m_Ints[v13 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 22);
      }
      this->m_Conditions.m_Ints[v10 >> 5] &= ~(1 << (v10 & 0x1F));
    }
  }
  v14 = this->GetClassScheduleIdSpace(this);
  v15 = CAI_LocalIdSpace::LocalToGlobal(this: &v14->m_ConditionIds, localID: 23);
  if ( v15 != -1 )
  {
    v16 = v15 - 1000000000;
    if ( v15 != 999999999 )
    {
      v17 = this->GetClassScheduleIdSpace(this);
      v18 = CAI_LocalIdSpace::LocalToGlobal(this: &v17->m_ConditionIds, localID: 23);
      if ( v18 != -1 )
      {
        v19 = v18 - 1000000000;
        if ( v19 != -1 && ((1 << (v19 & 0x1F)) & this->m_Conditions.m_Ints[v19 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 23);
      }
      this->m_Conditions.m_Ints[v16 >> 5] &= ~(1 << (v16 & 0x1F));
    }
  }
  v20 = this->GetClassScheduleIdSpace(this);
  v21 = CAI_LocalIdSpace::LocalToGlobal(this: &v20->m_ConditionIds, localID: 24);
  if ( v21 != -1 )
  {
    v22 = v21 - 1000000000;
    if ( v21 != 999999999 )
    {
      v23 = this->GetClassScheduleIdSpace(this);
      v24 = CAI_LocalIdSpace::LocalToGlobal(this: &v23->m_ConditionIds, localID: 24);
      if ( v24 != -1 )
      {
        v25 = v24 - 1000000000;
        if ( v25 != -1 && ((1 << (v25 & 0x1F)) & this->m_Conditions.m_Ints[v25 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 24);
      }
      this->m_Conditions.m_Ints[v22 >> 5] &= ~(1 << (v22 & 0x1F));
    }
  }
  v26 = this->GetClassScheduleIdSpace(this);
  v27 = CAI_LocalIdSpace::LocalToGlobal(this: &v26->m_ConditionIds, localID: 41);
  if ( v27 != -1 )
  {
    v28 = v27 - 1000000000;
    if ( v27 != 999999999 )
    {
      v29 = this->GetClassScheduleIdSpace(this);
      v30 = CAI_LocalIdSpace::LocalToGlobal(this: &v29->m_ConditionIds, localID: 41);
      if ( v30 != -1 )
      {
        v31 = v30 - 1000000000;
        if ( v31 != -1 && ((1 << (v31 & 0x1F)) & this->m_Conditions.m_Ints[v31 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 41);
      }
      this->m_Conditions.m_Ints[v28 >> 5] &= ~(1 << (v28 & 0x1F));
    }
  }
  v32 = this->GetClassScheduleIdSpace(this);
  v33 = CAI_LocalIdSpace::LocalToGlobal(this: &v32->m_ConditionIds, localID: 42);
  if ( v33 != -1 )
  {
    v34 = v33 - 1000000000;
    if ( v33 != 999999999 )
    {
      v35 = this->GetClassScheduleIdSpace(this);
      v36 = CAI_LocalIdSpace::LocalToGlobal(this: &v35->m_ConditionIds, localID: 42);
      if ( v36 != -1 )
      {
        v37 = v36 - 1000000000;
        if ( v37 != -1 && ((1 << (v37 & 0x1F)) & this->m_Conditions.m_Ints[v37 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 42);
      }
      this->m_Conditions.m_Ints[v34 >> 5] &= ~(1 << (v34 & 0x1F));
    }
  }
  v38 = this->GetClassScheduleIdSpace(this);
  v39 = CAI_LocalIdSpace::LocalToGlobal(this: &v38->m_ConditionIds, localID: 43);
  if ( v39 != -1 )
  {
    v40 = v39 - 1000000000;
    if ( v39 != 999999999 )
    {
      v41 = this->GetClassScheduleIdSpace(this);
      v42 = CAI_LocalIdSpace::LocalToGlobal(this: &v41->m_ConditionIds, localID: 43);
      if ( v42 != -1 )
      {
        v43 = v42 - 1000000000;
        if ( v43 != -1 && ((1 << (v43 & 0x1F)) & this->m_Conditions.m_Ints[v43 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 43);
      }
      this->m_Conditions.m_Ints[v40 >> 5] &= ~(1 << (v40 & 0x1F));
    }
  }
  v44 = this->GetClassScheduleIdSpace(this);
  v45 = CAI_LocalIdSpace::LocalToGlobal(this: &v44->m_ConditionIds, localID: 44);
  if ( v45 != -1 )
  {
    v46 = v45 - 1000000000;
    if ( v45 != 999999999 )
    {
      v47 = this->GetClassScheduleIdSpace(this);
      v48 = CAI_LocalIdSpace::LocalToGlobal(this: &v47->m_ConditionIds, localID: 44);
      if ( v48 != -1 )
      {
        v49 = v48 - 1000000000;
        if ( v49 != -1 && ((1 << (v49 & 0x1F)) & this->m_Conditions.m_Ints[v49 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 44);
      }
      this->m_Conditions.m_Ints[v46 >> 5] &= ~(1 << (v46 & 0x1F));
    }
  }
  v50 = this->GetClassScheduleIdSpace(this);
  v51 = CAI_LocalIdSpace::LocalToGlobal(this: &v50->m_ConditionIds, localID: 45);
  if ( v51 != -1 )
  {
    v52 = v51 - 1000000000;
    if ( v51 != 999999999 )
    {
      v53 = this->GetClassScheduleIdSpace(this);
      v54 = CAI_LocalIdSpace::LocalToGlobal(this: &v53->m_ConditionIds, localID: 45);
      if ( v54 != -1 )
      {
        v55 = v54 - 1000000000;
        if ( v55 != -1 && ((1 << (v55 & 0x1F)) & this->m_Conditions.m_Ints[v55 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 45);
      }
      this->m_Conditions.m_Ints[v52 >> 5] &= ~(1 << (v52 & 0x1F));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100211E0
// Name: public: void CAI_BaseNPC::Sleep(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::Sleep(CAI_BaseNPC *this)
{
  const char *pszValue; // eax

  CBaseEntity::AddEffects(this, nEffects: 32);
  if ( this->m_NPCState == NPC_STATE_SCRIPT )
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "%s put to sleep while in Scripted state!\n", pszValue);
  }
  CAI_BaseNPC::VacateStrategySlot(this);
  CAI_BaseNPC::SetSchedule(this, localScheduleID: 88);
  COutputEvent::FireOutput(this: &this->m_OnSleep, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10021240
// Name: protected: virtual void CAI_BaseNPC::ClearSenseConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ClearSenseConditions(CAI_BaseNPC *this)
{
  CAI_BaseNPC::ClearConditions(this, pConditions: conditionsToClear, nConditions: 15);
}

//------------------------------------------------------------------------------
// Address: 0x10021250
// Name: protected: virtual void CAI_BaseNPC::CheckFlinches(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::CheckFlinches(CAI_BaseNPC *this)
{
  CAI_ClassScheduleIdSpace *v2; // eax
  int v3; // eax
  int v4; // edi
  CAI_ClassScheduleIdSpace *v5; // eax
  int v6; // eax
  int v7; // eax
  CAI_ClassScheduleIdSpace *v8; // eax
  int v9; // eax
  int v10; // edi
  CAI_ClassScheduleIdSpace *v11; // eax
  int v12; // eax
  int v13; // eax
  CAI_ClassScheduleIdSpace *v14; // eax
  int v15; // eax
  int v16; // eax
  CAI_ClassScheduleIdSpace *v17; // eax
  int v18; // eax
  int v19; // eax
  int m_afMemory; // eax

  if ( CAI_BaseNPC::IsCurSchedule(this, schedId: 23, fIdeal: true) )
  {
    v2 = this->GetClassScheduleIdSpace(this);
    v3 = CAI_LocalIdSpace::LocalToGlobal(this: &v2->m_ConditionIds, localID: 17);
    if ( v3 != -1 )
    {
      v4 = v3 - 1000000000;
      if ( v3 != 999999999 )
      {
        v5 = this->GetClassScheduleIdSpace(this);
        v6 = CAI_LocalIdSpace::LocalToGlobal(this: &v5->m_ConditionIds, localID: 17);
        if ( v6 != -1 )
        {
          v7 = v6 - 1000000000;
          if ( v7 != -1 && ((1 << (v7 & 0x1F)) & this->m_Conditions.m_Ints[v7 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 17);
        }
        this->m_Conditions.m_Ints[v4 >> 5] &= ~(1 << (v4 & 0x1F));
      }
    }
    v8 = this->GetClassScheduleIdSpace(this);
    v9 = CAI_LocalIdSpace::LocalToGlobal(this: &v8->m_ConditionIds, localID: 18);
    if ( v9 != -1 )
    {
      v10 = v9 - 1000000000;
      if ( v9 != 999999999 )
      {
        v11 = this->GetClassScheduleIdSpace(this);
        v12 = CAI_LocalIdSpace::LocalToGlobal(this: &v11->m_ConditionIds, localID: 18);
        if ( v12 != -1 )
        {
          v13 = v12 - 1000000000;
          if ( v13 != -1 && ((1 << (v13 & 0x1F)) & this->m_Conditions.m_Ints[v13 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 18);
        }
        this->m_Conditions.m_Ints[v10 >> 5] &= ~(1 << (v10 & 0x1F));
      }
    }
  }
  v14 = this->GetClassScheduleIdSpace(this);
  v15 = CAI_LocalIdSpace::LocalToGlobal(this: &v14->m_ConditionIds, localID: 18);
  if ( v15 == -1 || (v16 = v15 - 1000000000) == -1 || ((1 << (v16 & 0x1F)) & this->m_Conditions.m_Ints[v16 >> 5]) == 0 )
  {
    v17 = this->GetClassScheduleIdSpace(this);
    v18 = CAI_LocalIdSpace::LocalToGlobal(this: &v17->m_ConditionIds, localID: 17);
    if ( v18 != -1 )
    {
      v19 = v18 - 1000000000;
      if ( v19 != -1 && ((1 << (v19 & 0x1F)) & this->m_Conditions.m_Ints[v19 >> 5]) != 0 )
LABEL_26:
        this->PlayFlinchGesture(this);
    }
  }
  else
  {
    if ( (this->m_afMemory & 0x40) != 0 )
    {
      CAI_BaseNPC::ClearCondition(this, iCondition: 18);
      goto LABEL_27;
    }
    if ( !CAI_BaseNPC::HasInterruptCondition(this, iCondition: 18) )
      goto LABEL_26;
  }
LABEL_27:
  m_afMemory = this->m_afMemory;
  if ( (m_afMemory & 0x40) != 0 && gpGlobals->curtime > this->m_flNextFlinchTime )
    this->m_afMemory = m_afMemory & 0xFFFFFFBF;
}

//------------------------------------------------------------------------------
// Address: 0x10021470
// Name: public: void CAI_BaseNPC::ClearTransientConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ClearTransientConditions(CAI_BaseNPC *this)
{
  CAI_ClassScheduleIdSpace *v2; // eax
  int v3; // eax
  int v4; // edi
  CAI_ClassScheduleIdSpace *v5; // eax
  int v6; // eax
  int v7; // eax
  CAI_ClassScheduleIdSpace *v8; // eax
  int v9; // eax
  int v10; // edi
  CAI_ClassScheduleIdSpace *v11; // eax
  int v12; // eax
  int v13; // eax
  CAI_ClassScheduleIdSpace *v14; // eax
  int v15; // eax
  int v16; // edi
  CAI_ClassScheduleIdSpace *v17; // eax
  int v18; // eax
  int v19; // eax
  CAI_ClassScheduleIdSpace *v20; // eax
  int v21; // eax
  int v22; // edi
  CAI_ClassScheduleIdSpace *v23; // eax
  int v24; // eax
  int v25; // eax

  v2 = this->GetClassScheduleIdSpace(this);
  v3 = CAI_LocalIdSpace::LocalToGlobal(this: &v2->m_ConditionIds, localID: 17);
  if ( v3 != -1 )
  {
    v4 = v3 - 1000000000;
    if ( v3 != 999999999 )
    {
      v5 = this->GetClassScheduleIdSpace(this);
      v6 = CAI_LocalIdSpace::LocalToGlobal(this: &v5->m_ConditionIds, localID: 17);
      if ( v6 != -1 )
      {
        v7 = v6 - 1000000000;
        if ( v7 != -1 && ((1 << (v7 & 0x1F)) & this->m_Conditions.m_Ints[v7 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 17);
      }
      this->m_Conditions.m_Ints[v4 >> 5] &= ~(1 << (v4 & 0x1F));
    }
  }
  v8 = this->GetClassScheduleIdSpace(this);
  v9 = CAI_LocalIdSpace::LocalToGlobal(this: &v8->m_ConditionIds, localID: 18);
  if ( v9 != -1 )
  {
    v10 = v9 - 1000000000;
    if ( v9 != 999999999 )
    {
      v11 = this->GetClassScheduleIdSpace(this);
      v12 = CAI_LocalIdSpace::LocalToGlobal(this: &v11->m_ConditionIds, localID: 18);
      if ( v12 != -1 )
      {
        v13 = v12 - 1000000000;
        if ( v13 != -1 && ((1 << (v13 & 0x1F)) & this->m_Conditions.m_Ints[v13 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 18);
      }
      this->m_Conditions.m_Ints[v10 >> 5] &= ~(1 << (v10 & 0x1F));
    }
  }
  v14 = this->GetClassScheduleIdSpace(this);
  v15 = CAI_LocalIdSpace::LocalToGlobal(this: &v14->m_ConditionIds, localID: 19);
  if ( v15 != -1 )
  {
    v16 = v15 - 1000000000;
    if ( v15 != 999999999 )
    {
      v17 = this->GetClassScheduleIdSpace(this);
      v18 = CAI_LocalIdSpace::LocalToGlobal(this: &v17->m_ConditionIds, localID: 19);
      if ( v18 != -1 )
      {
        v19 = v18 - 1000000000;
        if ( v19 != -1 && ((1 << (v19 & 0x1F)) & this->m_Conditions.m_Ints[v19 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 19);
      }
      this->m_Conditions.m_Ints[v16 >> 5] &= ~(1 << (v16 & 0x1F));
    }
  }
  v20 = this->GetClassScheduleIdSpace(this);
  v21 = CAI_LocalIdSpace::LocalToGlobal(this: &v20->m_ConditionIds, localID: 66);
  if ( v21 != -1 )
  {
    v22 = v21 - 1000000000;
    if ( v21 != 999999999 )
    {
      v23 = this->GetClassScheduleIdSpace(this);
      v24 = CAI_LocalIdSpace::LocalToGlobal(this: &v23->m_ConditionIds, localID: 66);
      if ( v24 != -1 )
      {
        v25 = v24 - 1000000000;
        if ( v25 != -1 && ((1 << (v25 & 0x1F)) & this->m_Conditions.m_Ints[v25 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 66);
      }
      this->m_Conditions.m_Ints[v22 >> 5] &= ~(1 << (v22 & 0x1F));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100216C0
// Name: protected: enum NPC_STATE CAI_BaseNPC::SelectIdleIdealState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::SelectIdleIdealState(CAI_BaseNPC *this)
{
  CAI_ClassScheduleIdSpace *v2; // eax
  int v3; // eax
  int v4; // eax
  CAI_ClassScheduleIdSpace *v5; // eax
  int v6; // eax
  int v7; // eax
  CAI_ClassScheduleIdSpace *v8; // eax
  int v9; // eax
  int v10; // eax
  CAI_ClassScheduleIdSpace *v11; // eax
  int v12; // eax
  int v13; // eax
  CGlobalVars *v14; // edi
  CAI_Enemies *v15; // eax
  CSound *v16; // eax
  CSound *v17; // edi
  CAI_Motor *m_pMotor; // ebx
  const Vector *SoundReactOrigin; // eax
  bool v21; // zf
  CAI_BaseNPC_vtbl *v22; // eax
  Vector *KnownPosition; // eax
  CAI_Enemies *v24; // eax
  CAI_BaseNPC_vtbl *v25; // eax
  CAI_Enemies *v26; // eax
  float *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // [esp+18h] [ebp-18h]
  float v31; // [esp+1Ch] [ebp-14h]
  float v32; // [esp+20h] [ebp-10h]
  Vector vecEnemyLKP; // [esp+24h] [ebp-Ch] BYREF

  v2 = this->GetClassScheduleIdSpace(this);
  v3 = CAI_LocalIdSpace::LocalToGlobal(this: &v2->m_ConditionIds, localID: 26);
  if ( v3 == -1 || (v4 = v3 - 1000000000) == -1 || ((1 << (v4 & 0x1F)) & this->m_Conditions.m_Ints[v4 >> 5]) == 0 )
  {
    v5 = this->GetClassScheduleIdSpace(this);
    v6 = CAI_LocalIdSpace::LocalToGlobal(this: &v5->m_ConditionIds, localID: 10);
    if ( v6 == -1 || (v7 = v6 - 1000000000) == -1 || ((1 << (v7 & 0x1F)) & this->m_Conditions.m_Ints[v7 >> 5]) == 0 )
    {
      v8 = this->GetClassScheduleIdSpace(this);
      v9 = CAI_LocalIdSpace::LocalToGlobal(this: &v8->m_ConditionIds, localID: 17);
      if ( v9 == -1 || (v10 = v9 - 1000000000) == -1 || ((1 << (v10 & 0x1F)) & this->m_Conditions.m_Ints[v10 >> 5]) == 0 )
      {
        v11 = this->GetClassScheduleIdSpace(this);
        v12 = CAI_LocalIdSpace::LocalToGlobal(this: &v11->m_ConditionIds, localID: 18);
        if ( v12 == -1
          || (v13 = v12 - 1000000000) == -1
          || ((1 << (v13 & 0x1F)) & this->m_Conditions.m_Ints[v13 >> 5]) == 0 )
        {
          if ( this->GetEnemy_2(this) != nullptr
            || (v14 = gpGlobals,
                v15 = this->GetEnemies(this),
                v14->curtime
              - CAI_Enemies::LastTimeSeen(this: v15, pEnemy: (CBaseEntity *)0x354, bCheckDangerMemory: true) >= 3.0) )
          {
            if ( !CAI_BaseNPC::HasCondition(this, iCondition: 50)
              && !CAI_BaseNPC::HasCondition(this, iCondition: 53)
              && !CAI_BaseNPC::HasCondition(this, iCondition: 54)
              && !CAI_BaseNPC::HasCondition(this, iCondition: 55)
              && !CAI_BaseNPC::HasCondition(this, iCondition: 51)
              && !CAI_BaseNPC::HasCondition(this, iCondition: 56) )
            {
              return CAI_BaseNPC::HasInterruptCondition(this, iCondition: 37) ? 2 : -1;
            }
            v16 = this->GetBestSound(this, a2: 1048351);
            v17 = v16;
            if ( v16 == nullptr )
              return CAI_BaseNPC::HasInterruptCondition(this, iCondition: 37) ? 2 : -1;
            m_pMotor = this->m_pMotor;
            SoundReactOrigin = CSound::GetSoundReactOrigin(this: v16);
            CAI_Motor::SetIdealYawToTarget(this: m_pMotor, target: SoundReactOrigin, noise: 0.0, offset: 0.0);
            if ( (v17->m_iType & 0x19) == 0 )
              return CAI_BaseNPC::HasInterruptCondition(this, iCondition: 37) ? 2 : -1;
            return 2;
          }
        }
      }
      v21 = this->GetEnemy_2(this) == nullptr;
      v22 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      if ( v21 )
      {
        v24 = v22->GetEnemies(this);
        v21 = CAI_Enemies::Find(this: v24, pEntity: (CBaseEntity *)0x354, bTryDangerMemory: false) == nullptr;
        v25 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        if ( v21 )
        {
          v30 = g_vecAttackDir.x * 128.0;
          v31 = g_vecAttackDir.y * 128.0;
          v32 = g_vecAttackDir.z * 128.0;
          v27 = (float *)v25->WorldSpaceCenter(this);
          v28 = v27[1] + v31;
          v29 = v27[2] + v32;
          vecEnemyLKP.x = *v27 + v30;
          vecEnemyLKP.y = v28;
          vecEnemyLKP.z = v29;
          goto LABEL_30;
        }
        v26 = v25->GetEnemies(this);
        KnownPosition = CAI_Enemies::LastKnownPosition(this: v26, pEnemy: (CBaseEntity *)0x354);
      }
      else
      {
        KnownPosition = v22->GetEnemyLKP(this);
      }
      vecEnemyLKP = *KnownPosition;
LABEL_30:
      CAI_Motor::SetIdealYawToTarget(this: this->m_pMotor, target: &vecEnemyLKP, noise: 0.0, offset: 0.0);
      return 2;
    }
  }
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x100219F0
// Name: protected: enum NPC_STATE CAI_BaseNPC::SelectAlertIdealState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::SelectAlertIdealState(CAI_BaseNPC *this)
{
  CAI_ClassScheduleIdSpace *v2; // eax
  int v3; // eax
  int v4; // eax
  CAI_ClassScheduleIdSpace *v5; // eax
  int v6; // eax
  int v7; // eax
  CAI_ClassScheduleIdSpace *v8; // eax
  int v9; // eax
  int v10; // eax
  CGlobalVars *v11; // edi
  CAI_Enemies *v12; // eax
  CSound *v14; // eax
  CAI_Motor *m_pMotor; // esi
  const Vector *SoundReactOrigin; // eax
  CBaseEntity *v17; // eax
  CAI_BaseNPC_vtbl *v18; // edx
  Vector *KnownPosition; // eax
  CAI_Enemies *v20; // eax
  AI_EnemyInfo_t *v21; // eax
  CAI_BaseNPC_vtbl *v22; // edx
  CAI_Enemies *v23; // eax
  float *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // [esp+10h] [ebp-18h]
  float v28; // [esp+14h] [ebp-14h]
  float v29; // [esp+18h] [ebp-10h]
  Vector vecEnemyLKP; // [esp+1Ch] [ebp-Ch] BYREF

  v2 = this->GetClassScheduleIdSpace(this);
  v3 = CAI_LocalIdSpace::LocalToGlobal(this: &v2->m_ConditionIds, localID: 26);
  if ( v3 != -1 )
  {
    v4 = v3 - 1000000000;
    if ( v4 != -1 && ((1 << (v4 & 0x1F)) & this->m_Conditions.m_Ints[v4 >> 5]) != 0 )
      return 3;
  }
  v5 = this->GetClassScheduleIdSpace(this);
  v6 = CAI_LocalIdSpace::LocalToGlobal(this: &v5->m_ConditionIds, localID: 10);
  if ( v6 != -1 )
  {
    v7 = v6 - 1000000000;
    if ( v7 != -1 && ((1 << (v7 & 0x1F)) & this->m_Conditions.m_Ints[v7 >> 5]) != 0 )
      return 3;
  }
  if ( this->GetEnemy_2(this) != nullptr )
    return 3;
  v8 = this->GetClassScheduleIdSpace(this);
  v9 = CAI_LocalIdSpace::LocalToGlobal(this: &v8->m_ConditionIds, localID: 17);
  if ( v9 != -1 && (v10 = v9 - 1000000000) != -1 && ((1 << (v10 & 0x1F)) & this->m_Conditions.m_Ints[v10 >> 5]) != 0
    || CAI_BaseNPC::HasCondition(this, iCondition: 18)
    || this->GetEnemy_2(this) == nullptr
    && (v11 = gpGlobals,
        v12 = this->GetEnemies(this),
        v11->curtime - CAI_Enemies::LastTimeSeen(this: v12, pEnemy: (CBaseEntity *)0x354, bCheckDangerMemory: true) < 3.0) )
  {
    v17 = this->GetEnemy_2(this);
    v18 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    if ( v17 != nullptr )
    {
      KnownPosition = v18->GetEnemyLKP(this);
    }
    else
    {
      v20 = v18->GetEnemies(this);
      v21 = CAI_Enemies::Find(this: v20, pEntity: (CBaseEntity *)0x354, bTryDangerMemory: false);
      v22 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      if ( v21 == nullptr )
      {
        v27 = g_vecAttackDir.x * 128.0;
        v28 = g_vecAttackDir.y * 128.0;
        v29 = g_vecAttackDir.z * 128.0;
        v24 = (float *)v22->WorldSpaceCenter(this);
        v25 = v24[1] + v28;
        v26 = v24[2] + v29;
        vecEnemyLKP.x = *v24 + v27;
        vecEnemyLKP.y = v25;
        vecEnemyLKP.z = v26;
        goto LABEL_26;
      }
      v23 = v22->GetEnemies(this);
      KnownPosition = CAI_Enemies::LastKnownPosition(this: v23, pEnemy: (CBaseEntity *)0x354);
    }
    vecEnemyLKP = *KnownPosition;
LABEL_26:
    CAI_Motor::SetIdealYawToTarget(this: this->m_pMotor, target: &vecEnemyLKP, noise: 0.0, offset: 0.0);
    return 2;
  }
  if ( !CAI_BaseNPC::HasCondition(this, iCondition: 50) && !CAI_BaseNPC::HasCondition(this, iCondition: 53) )
    return 2 * this->ShouldGoToIdleState(this) - 1;
  v14 = this->GetBestSound(this, a2: 1048351);
  if ( v14 != nullptr )
  {
    m_pMotor = this->m_pMotor;
    SoundReactOrigin = CSound::GetSoundReactOrigin(this: v14);
    CAI_Motor::SetIdealYawToTarget(this: m_pMotor, target: SoundReactOrigin, noise: 0.0, offset: 0.0);
  }
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10021CC0
// Name: public: virtual void CAI_BaseNPC::GiveWeapon(struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::GiveWeapon(CAI_BaseNPC *this, string_t iszWeaponName)
{
  const char *pszValue; // eax
  CBaseCombatWeapon *v4; // edi
  const char *v5; // esi
  const char *v6; // eax
  CAI_BaseNPC_vtbl *v7; // ebx
  CBaseCombatWeapon *ActiveWeapon; // eax

  pszValue = iszWeaponName.pszValue;
  if ( iszWeaponName.pszValue == nullptr )
    pszValue = locale;
  v4 = CBaseCombatCharacter::Weapon_Create(this, pWeaponName: pszValue);
  if ( v4 != nullptr )
  {
    if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
    {
      v7 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
      v7->Weapon_Drop(this, a2: ActiveWeapon, a3: nullptr, a4: nullptr);
    }
    v4->MakeWeaponNameFromEntity(this: v4, a2: this);
    this->Weapon_Equip(this, a2: v4);
    this->OnGivenWeapon(this, a2: v4);
  }
  else
  {
    v5 = this->m_iName.m_Value.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    v6 = iszWeaponName.pszValue;
    if ( iszWeaponName.pszValue == nullptr )
      v6 = locale;
    _Warning(a1: "Couldn't create weapon %s to give NPC %s.\n", v6, v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021D70
// Name: public: bool CAI_BaseNPC::Weapon_IsBetterAvailable(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::Weapon_IsBetterAvailable(CAI_BaseNPC *this)
{
  float curtime; // xmm0_4
  float v4; // xmm0_4
  Vector range; // [esp+4h] [ebp-Ch] BYREF

  if ( this->m_iszPendingWeapon.pszValue != nullptr )
    return 1;
  if ( this->ShouldLookForBetterWeapon(this) )
  {
    if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
    {
      curtime = gpGlobals->curtime;
    }
    else
    {
      if ( CAI_BaseNPC::IsInPlayerSquad(this) )
      {
        v4 = gpGlobals->curtime + 1.0;
        goto LABEL_10;
      }
      curtime = gpGlobals->curtime;
    }
    v4 = curtime + 2.0;
LABEL_10:
    this->m_flNextWeaponSearchTime = v4;
    range.x = 540.0;
    range.y = 540.0;
    range.z = 100.0;
    if ( CBaseCombatCharacter::Weapon_FindUsable(this, &range) != nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10021E30
// Name: public: virtual bool CAI_BaseNPC::FCanCheckAttacks(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::FCanCheckAttacks(CAI_BaseNPC *this)
{
  Navigation_t m_navType; // eax
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax
  int v5; // eax
  CAI_ClassScheduleIdSpace *v6; // eax
  int v7; // eax
  int v8; // eax
  bool result; // al

  m_navType = this->m_pNavigator->m_navType;
  result = false;
  if ( m_navType != NAV_CLIMB && m_navType != NAV_JUMP )
  {
    v3 = this->GetClassScheduleIdSpace(this);
    v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: 10);
    if ( v4 != -1 )
    {
      v5 = v4 - 1000000000;
      if ( v5 != -1 && ((1 << (v5 & 0x1F)) & this->m_Conditions.m_Ints[v5 >> 5]) != 0 )
      {
        v6 = this->GetClassScheduleIdSpace(this);
        v7 = CAI_LocalIdSpace::LocalToGlobal(this: &v6->m_ConditionIds, localID: 27);
        if ( v7 == -1 )
          return true;
        v8 = v7 - 1000000000;
        if ( v8 == -1 || ((1 << (v8 & 0x1F)) & this->m_Conditions.m_Ints[v8 >> 5]) == 0 )
          return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021EE0
// Name: private: void CAI_BaseNPC::UpdateEnemyPos(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BaseNPC::UpdateEnemyPos(CAI_BaseNPC *this@<ecx>, float a2@<ebp>)
{
  CAI_Navigator *m_pNavigator; // ecx
  Navigation_t m_navType; // eax
  CHandle<CBaseEntity> *p_m_hEnemy; // edi
  CBaseEntity *GoalTarget; // eax
  CAI_Navigator *v7; // esi
  CBaseEntity *v8; // eax
  const Vector *v9; // eax
  CAI_BaseNPC_vtbl *v10; // edi
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // edx
  int v12; // eax
  CAI_BaseNPC_vtbl *v13; // edi
  const Vector *GoalPos; // eax
  int v15; // eax
  const Vector *v16; // eax
  __int64 v17; // [esp-Ch] [ebp-1Ch] BYREF
  float z; // [esp-4h] [ebp-14h]
  Vector vEnemyLKP; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  vEnemyLKP.y = a2;
  vEnemyLKP.z = retaddr;
  m_pNavigator = this->m_pNavigator;
  m_navType = m_pNavigator->m_navType;
  if ( m_navType != NAV_CLIMB
    && m_navType != NAV_JUMP
    && (float)(gpGlobals->curtime - CAI_BaseNPC::m_AnyUpdateEnemyPosTimer.m_next) > -0.001
    && (float)(gpGlobals->curtime - this->m_UpdateEnemyPosTimer.m_next) > -0.001
    && CAI_Navigator::GetGoalType(this: m_pNavigator) == GOALTYPE_ENEMY )
  {
    p_m_hEnemy = &this->m_hEnemy;
    GoalTarget = CAI_Navigator::GetGoalTarget(this: this->m_pNavigator);
    if ( CHandle<CBaseEntity>::operator!=(this: &this->m_hEnemy, val: GoalTarget) )
    {
      v7 = this->m_pNavigator;
      v8 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hEnemy);
      v7->SetGoalTarget(this: v7, a2: v8, a3: &vec3_origin);
    }
    else
    {
      v9 = this->GetEnemyLKP(this);
      v10 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      GetEnemy_2 = this->GetEnemy_2;
      v17 = *(_QWORD *)&v9->x;
      z = v9->z;
      v12 = ((int (__thiscall *)(CAI_BaseNPC *, __int64 *))GetEnemy_2)(a1: this, a2: &v17);
      ((void (__thiscall *)(CAI_BaseNPC *, int))v10->TranslateNavGoal)(a1: this, a2: v12);
      v13 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      GoalPos = CAI_Navigator::GetGoalPos(this: this->m_pNavigator);
      v15 = ((int (__thiscall *)(CAI_BaseNPC *, int, const Vector *, __int64 *))this->GetEnemy_2)(
              a1: this,
              a2: 2,
              a3: GoalPos,
              a4: &v17);
      vEnemyLKP.x = ((double (__thiscall *)(CAI_BaseNPC *, int))v13->GetGoalRepathTolerance)(a1: this, a2: v15);
      v16 = CAI_Navigator::GetGoalPos(this: this->m_pNavigator);
      if ( fsqrt(
             (float)((float)((float)(v16->y - *((float *)&v17 + 1)) * (float)(v16->y - *((float *)&v17 + 1)))
                   + (float)((float)(v16->z - z) * (float)(v16->z - z)))
           + (float)((float)(v16->x - *(float *)&v17) * (float)(v16->x - *(float *)&v17))) > (double)vEnemyLKP.x )
      {
        CAI_BaseNPC::m_AnyUpdateEnemyPosTimer.m_next = gpGlobals->curtime + 0.1;
        if ( !CAI_Navigator::RefindPathToGoal(
                this: this->m_pNavigator,
                fSignalTaskStatus: false,
                bDontIgnoreBadLinks: false) )
          this->TaskFail(this, a2: 11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100220B0
// Name: private: void CAI_BaseNPC::UpdateTargetPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::UpdateTargetPos(CAI_BaseNPC *this)
{
  CAI_Navigator *m_pNavigator; // ecx
  Navigation_t m_navType; // eax
  CBaseEntity *GoalTarget; // eax
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // ecx
  CAI_Navigator *v7; // esi
  CBaseEntity *Target; // eax
  const Vector *AbsOrigin; // edi
  const Vector *GoalPos; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  CAI_Navigator *v14; // edi
  CBaseEntity *v15; // eax
  CBaseEntity *v16; // eax
  const Vector *v17; // [esp-38h] [ebp-44h]
  const Vector *v18; // [esp-34h] [ebp-40h]
  CAI_Navigator *v19; // [esp-4h] [ebp-10h]
  CAI_BaseNPC_vtbl *v20; // [esp-4h] [ebp-10h]

  m_pNavigator = this->m_pNavigator;
  m_navType = m_pNavigator->m_navType;
  if ( m_navType != NAV_CLIMB
    && m_navType != NAV_JUMP
    && CAI_Navigator::GetGoalType(this: m_pNavigator) == GOALTYPE_TARGETENT )
  {
    GoalTarget = CAI_Navigator::GetGoalTarget(this: this->m_pNavigator);
    m_Index = this->m_hTargetEnt.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == GoalTarget )
    {
      if ( (CAI_Navigator::GetGoalFlags(this: this->m_pNavigator) & 2) != 0 )
      {
        if ( CAI_BaseNPC::GetTarget(this) == nullptr )
          goto LABEL_20;
        v19 = this->m_pNavigator;
        Target = CAI_BaseNPC::GetTarget(this);
        AbsOrigin = CBaseEntity::GetAbsOrigin(this: Target);
        GoalPos = CAI_Navigator::GetGoalPos(this: v19);
        v11 = GoalPos->x - AbsOrigin->x;
        v12 = GoalPos->y - AbsOrigin->y;
        v13 = GoalPos->z - AbsOrigin->z;
        v14 = this->m_pNavigator;
        v20 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v15 = CAI_BaseNPC::GetTarget(this);
        v18 = CBaseEntity::GetAbsOrigin(this: v15);
        v17 = CAI_Navigator::GetGoalPos(this: v14);
        v16 = CAI_BaseNPC::GetTarget(this);
        if ( fsqrt((float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v11 * v11)) > ((double (__thiscall *)(CAI_BaseNPC *, CBaseEntity *, int, const Vector *, const Vector *))v20->GetGoalRepathTolerance)(
                                                                                              a1: this,
                                                                                              a2: v16,
                                                                                              a3: 1,
                                                                                              a4: v17,
                                                                                              a5: v18) )
        {
LABEL_20:
          if ( !CAI_Navigator::RefindPathToGoal(
                  this: this->m_pNavigator,
                  fSignalTaskStatus: false,
                  bDontIgnoreBadLinks: false) )
            this->TaskFail(this, a2: 11);
        }
      }
    }
    else
    {
      v7 = this->m_pNavigator;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        v7->SetGoalTarget(this: v7, a2: nullptr, a3: &vec3_origin);
      else
        v7->SetGoalTarget(
          this: v7,
          a2: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity,
          a3: &vec3_origin);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022280
// Name: public: virtual enum Activity CAI_BaseNPC::NPC_TranslateActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_BaseNPC::NPC_TranslateActivity(CAI_BaseNPC *this, Activity eNewActivity)
{
  Activity v2; // edi
  unsigned int v4; // ecx
  unsigned int m_Index; // eax
  CAI_Hint *m_pEntity; // ecx

  v2 = eNewActivity;
  switch ( eNewActivity )
  {
    case ACT_RANGE_ATTACK1:
      if ( this->IsCrouching(this) )
        v2 = ACT_RANGE_ATTACK1_LOW;
      break;
    case ACT_RELOAD:
      if ( this->IsCrouching(this) )
        v2 = ACT_RELOAD_LOW;
      break;
    case ACT_IDLE:
      if ( this->IsCrouching(this) )
        v2 = ACT_CROUCHIDLE;
      break;
    default:
      if ( eNewActivity == ACT_IDLE_ANGRY_SMG1 && this->IsCrouching(this) )
        v2 = ACT_RANGE_AIM_LOW;
      break;
  }
  if ( (this->CapabilitiesGet(this) & 0x8000000) == 0 )
    return v2;
  if ( v2 != ACT_RELOAD )
  {
    if ( v2 == ACT_COVER || v2 == ACT_IDLE && (this->m_afMemory & 2) != 0 )
    {
      m_Index = this->m_pHintNode.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CAI_Hint *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v2 = this->GetCoverActivity(this, a2: m_pEntity);
      if ( CBaseAnimating::SelectWeightedSequence(this, activity: v2) == -1 )
        return ACT_IDLE;
    }
    return v2;
  }
  v4 = this->m_pHintNode.m_Index;
  if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    return this->GetReloadActivity(this, a2: nullptr);
  else
    return this->GetReloadActivity(this, a2: (CAI_Hint *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x100223D0
// Name: public: virtual bool CAI_BaseNPC::IsActivityFinished(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsActivityFinished(CAI_BaseNPC *this)
{
  return this->m_bSequenceFinished && this->m_nSequence.m_Value == this->m_nIdealSequence;
}

//------------------------------------------------------------------------------
// Address: 0x100223F0
// Name: public: void CAI_BaseNPC::SetupVPhysicsHull(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetupVPhysicsHull(CAI_BaseNPC *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  IPhysicsObject *v3; // edi
  CStudioHdr *m_pStudioHdr; // eax
  double v5; // st7
  int v6; // ebx
  Vector *v7; // edi
  Vector *v8; // eax
  float y; // xmm1_4
  float mass; // [esp+18h] [ebp-4h]

  if ( this->m_MoveType.m_Value != 6 )
  {
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: false);
      this->VPhysicsDestroyObject(this);
    }
    CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: true, allowPhysicsRotation: false, pSolid: nullptr);
    v3 = this->m_pPhysicsObject;
    if ( v3 != nullptr )
    {
      if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
        CBaseAnimating::LockStudioHdr(this);
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
        m_pStudioHdr = nullptr;
      v5 = Studio_GetMass(pstudiohdr: m_pStudioHdr);
      if ( v5 > 0.0 )
      {
        mass = v5;
        ((void (__thiscall *)(IPhysicsObject *, _DWORD))v3->SetMass)(a1: v3, a2: LODWORD(mass));
      }
      v6 = (int)v3->GetShadowController(this: v3);
      v7 = AllocTempVector();
      v7->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
      v7->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
      v7->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
      v8 = AllocTempVector();
      v8->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
      v8->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
      y = v8->y;
      v8->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 16))(a1: v6, a2: (float)((float)(y + v7->x) * 0.5) * 0.5);
      this->m_bCheckContacts = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022570
// Name: public: void CAI_BaseNPC::CheckPhysicsContacts(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BaseNPC::CheckPhysicsContacts(CAI_BaseNPC *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  bool v4; // cf
  bool v6; // zf
  IPhysicsObject *m_pPhysicsObject; // edi
  int v8; // esi
  CBaseEntity *GroundEntity; // eax
  unsigned int v10; // ecx
  const Vector *v11; // eax
  void (__thiscall *GetVelocity)(IPhysicsObject *, Vector *, Vector *); // edx
  unsigned __int8 (__thiscall *v13)(int); // edx
  CBaseEntity *v14; // ebx
  int v15; // edi
  CBaseEntity *v16; // eax
  int (__thiscall *v17)(int); // edx
  Vector point; // [esp+28h] [ebp-40h] BYREF
  Vector npcVel; // [esp+34h] [ebp-34h] BYREF
  Vector vel; // [esp+40h] [ebp-28h] BYREF
  float heightCheck; // [esp+4Ch] [ebp-1Ch]
  float otherMass; // [esp+50h] [ebp-18h]
  CBaseEntity *pGroundEntity; // [esp+54h] [ebp-14h]
  CAI_BaseNPC *pNPC; // [esp+58h] [ebp-10h]
  IPhysicsObject *v27; // [esp+5Ch] [ebp-Ch]
  float solverTime; // [esp+60h] [ebp-8h]
  bool createSolver; // [esp+67h] [ebp-1h]

  v4 = gpGlobals->frametime > 0.0;
  pNPC = this;
  if ( v4 && ai_auto_contact_solver.m_pParent != nullptr && ai_auto_contact_solver.m_pParent->m_Value.m_nValue != 0 )
  {
    v6 = this->m_MoveType.m_Value == 3;
    this->m_bCheckContacts = false;
    if ( v6 )
    {
      m_pPhysicsObject = this->m_pPhysicsObject;
      v27 = m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr )
      {
        v8 = ((int (__thiscall *)(IPhysicsObject *, int, int, int))m_pPhysicsObject->CreateFrictionSnapshot)(
               a1: m_pPhysicsObject,
               a2: a4,
               a3,
               a4: a2);
        GroundEntity = CBaseEntity::GetGroundEntity(this);
        v10 = (unsigned int)this->m_iEFlags >> 11;
        pGroundEntity = GroundEntity;
        if ( (v10 & 1) != 0 )
          CBaseEntity::CalcAbsolutePosition(this);
        v11 = NAI_Hull::Maxs(id: this->m_eHull);
        GetVelocity = m_pPhysicsObject->GetVelocity;
        heightCheck = this->m_vecAbsOrigin.z + v11->z;
        GetVelocity(this: m_pPhysicsObject, a2: &npcVel, a3: nullptr);
        v13 = *(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 4);
        v14 = nullptr;
        createSolver = false;
        solverTime = 0.0;
        if ( v13(a1: v8) != 0 )
        {
          while ( 1 )
          {
            v15 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 8))(a1: v8, a2: 1);
            v16 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v15 + 68))(a1: v15);
            v14 = v16;
            if ( v16 != nullptr && pGroundEntity != v16 )
            {
              otherMass = PhysGetEntityMass(pEntity: v16);
              if ( v14->m_MoveType.m_Value == 6
                && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v15 + 40))(a1: v15) != 0
                && otherMass < 500.0
                && v14->GetServerVehicle(this: v14) == nullptr )
              {
                pNPC->m_bCheckContacts = true;
                (*(void (__thiscall **)(int, Vector *, _DWORD))(*(_DWORD *)v15 + 208))(a1: v15, a2: &vel, a3: 0);
                (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v8 + 16))(a1: v8, a2: &point);
                vel.x = vel.x - npcVel.x;
                vel.y = vel.y - npcVel.y;
                vel.z = vel.z - npcVel.z;
                if ( (float)((float)((float)(vel.x * vel.x) + (float)(vel.y * vel.y)) + (float)(vel.z * vel.z)) < 25.0 )
                {
                  solverTime = 4.0;
                  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(point.z - heightCheck) & _mask__AbsFloat_) < 2.0 )
                    break;
                }
              }
            }
            (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 48))(a1: v8);
            if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8) == 0 )
              goto LABEL_22;
          }
          v17 = *(int (__thiscall **)(int))(*(_DWORD *)v15 + 76);
          solverTime = 0.5;
          if ( (v17(a1: v15) & 4) != 0 )
            solverTime = 0.25;
          createSolver = true;
LABEL_22:
          m_pPhysicsObject = v27;
        }
        ((void (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->DestroyFrictionSnapshot)(a1: m_pPhysicsObject);
        if ( createSolver )
        {
          NPCPhysics_CreateSolver(pNPC, pPhysicsObject: v14, disableCollisions: true, separationDuration: solverTime);
          m_pPhysicsObject->RecheckContactPoints(this: m_pPhysicsObject, a2: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022800
// Name: public: virtual void CAI_BaseNPC::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::StartTouch(CAI_BaseNPC *this, CBaseEntity *pOther)
{
  CBaseEntity::StartTouch(this, pOther);
  if ( pOther->m_MoveType.m_Value == 6 )
    this->m_bCheckContacts = true;
}

//------------------------------------------------------------------------------
// Address: 0x10022830
// Name: public: void CAI_BaseNPC::SetHullSizeNormal(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetHullSizeNormal(CAI_BaseNPC *this, bool force)
{
  const Vector *v3; // eax
  const Vector *v4; // eax
  bool v5; // zf
  Hull_t m_eHull; // [esp-8h] [ebp-24h]
  Vector vecMins; // [esp+4h] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+10h] [ebp-Ch] BYREF
  float flScale; // [esp+24h] [ebp+8h]

  if ( this->m_fIsUsingSmallHull || force )
  {
    if ( CBaseAnimating::GetModelHierarchyScale(this) <= 1.0 )
      flScale = CBaseAnimating::GetModelHierarchyScale(this);
    else
      flScale = 1.0;
    v3 = NAI_Hull::Mins(id: this->m_eHull);
    vecMins.x = v3->x * flScale;
    vecMins.y = v3->y * flScale;
    m_eHull = this->m_eHull;
    vecMins.z = v3->z * flScale;
    v4 = NAI_Hull::Maxs(id: m_eHull);
    vecMaxs.x = flScale * v4->x;
    vecMaxs.y = v4->y * flScale;
    vecMaxs.z = v4->z * flScale;
    UTIL_SetSize(pEnt: this, vecMin: &vecMins, vecMax: &vecMaxs);
    v5 = this->m_pPhysicsObject == nullptr;
    this->m_fIsUsingSmallHull = false;
    if ( !v5 )
      CAI_BaseNPC::SetupVPhysicsHull(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022920
// Name: public: bool CAI_BaseNPC::SetHullSizeSmall(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::SetHullSizeSmall(CAI_BaseNPC *this, bool force)
{
  Hull_t m_eHull; // edi
  const Vector *v4; // eax
  bool v5; // zf
  const Vector *v7; // [esp-8h] [ebp-Ch]

  if ( !this->m_fIsUsingSmallHull || force )
  {
    m_eHull = this->m_eHull;
    v7 = NAI_Hull::SmallMaxs(id: m_eHull);
    v4 = NAI_Hull::SmallMins(id: m_eHull);
    UTIL_SetSize(pEnt: this, vecMin: v4, vecMax: v7);
    v5 = this->m_pPhysicsObject == nullptr;
    this->m_fIsUsingSmallHull = true;
    if ( !v5 )
      CAI_BaseNPC::SetupVPhysicsHull(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10022980
// Name: public: virtual bool CAI_BaseNPC::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::CreateVPhysics(CAI_BaseNPC *this)
{
  if ( this->IsAlive(this) && this->m_pPhysicsObject == nullptr )
    CAI_BaseNPC::SetupVPhysicsHull(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100229B0
// Name: public: void CAI_BaseNPC::NPCInitThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::NPCInitThink(CAI_BaseNPC *this)
{
  const char *pszValue; // eax

  pszValue = this->m_RelationshipString.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CAI_BaseNPC::AddRelationship(this, pszRelationship: pszValue, pActivator: nullptr);
  this->StartNPC(this);
  this->PostNPCInit(this);
  if ( this->m_SleepState == AISS_AUTO_PVS )
  {
    this->m_SleepFlags |= 1u;
    this->m_SleepState = AISS_AWAKE;
  }
  if ( this->m_SleepState == AISS_AUTO_PVS_AFTER_PVS )
  {
    this->m_SleepFlags |= 2u;
    this->m_SleepState = AISS_AWAKE;
  }
  if ( this->m_SleepState > AISS_AWAKE )
    CAI_BaseNPC::Sleep(this);
  this->m_flLastRealThinkTime = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10022A50
// Name: public: void CAI_BaseNPC::TaskComplete(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::TaskComplete(CAI_BaseNPC *this, bool fIgnoreSetFailedCondition)
{
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax
  int v5; // eax

  CAI_BaseNPC::EndTaskOverlay(this);
  if ( fIgnoreSetFailedCondition
    || (v3 = this->GetClassScheduleIdSpace(this),
        (v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: 35)) == -1)
    || (v5 = v4 - 1000000000) == -1
    || ((1 << (v5 & 0x1F)) & this->m_Conditions.m_Ints[v5 >> 5]) == 0 )
  {
    this->m_ScheduleState.fTaskStatus = TASKSTATUS_COMPLETE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022AC0
// Name: public: virtual enum Activity CAI_BaseNPC::GetReloadActivity(class CAI_Hint __near *)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_BaseNPC::GetReloadActivity(CAI_BaseNPC *this, CAI_Hint *pHint)
{
  Vector *v3; // edi
  const Vector *AbsOrigin; // eax
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // edx
  int v6; // eax
  const Vector *v7; // eax
  Activity result; // eax
  CGameTrace tr; // [esp+Ch] [ebp-78h] BYREF
  char v10; // [esp+60h] [ebp-24h] BYREF
  _BYTE v11[12]; // [esp+6Ch] [ebp-18h] BYREF
  Vector vEyePos; // [esp+78h] [ebp-Ch] BYREF

  if ( pHint == nullptr )
    return ACT_RELOAD;
  if ( this->GetEnemy_2(this) == nullptr )
    return ACT_RELOAD;
  if ( (unsigned int)(pHint->m_NodeData.nHintType - 100) > 1 )
    return ACT_RELOAD;
  if ( CBaseAnimating::SelectWeightedSequence(this, activity: ACT_RELOAD_LOW) == -1 )
    return ACT_RELOAD;
  v3 = this->EyeOffset(this, result: v11, a3: 70);
  AbsOrigin = CBaseEntity::GetAbsOrigin(this);
  vEyePos.x = v3->x + AbsOrigin->x;
  vEyePos.y = v3->y + AbsOrigin->y;
  GetEnemy_2 = this->GetEnemy_2;
  vEyePos.z = v3->z + AbsOrigin->z;
  v6 = (int)GetEnemy_2(this);
  v7 = (const Vector *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 504))(a1: v6);
  AI_TraceLOS(
    a1: (int)this,
    vecAbsStart: &vEyePos,
    vecAbsEnd: v7,
    pLooker: (CBaseEntity *)&v10,
    ptr: (CGameTrace *)this,
    pFilter: (CTraceFilterLOS *)&tr);
  result = ACT_RELOAD_LOW;
  if ( tr.fraction == 1.0 )
    return ACT_RELOAD;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022BB0
// Name: public: virtual void CAI_BaseNPC::ReportOverThinkLimit(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ReportOverThinkLimit(CAI_BaseNPC *this, float time)
{
  char *m_pName; // eax
  const char *DebugName; // eax
  float v5; // xmm0_4
  const char *v6; // edx
  CFmtStrN<256> *v7; // eax
  const char *v8; // [esp+8h] [ebp-180h]
  CFmtStrN<256> v9; // [esp+44h] [ebp-144h] BYREF
  long double v10; // [esp+150h] [ebp-38h]
  long double v11; // [esp+158h] [ebp-30h]
  Vector tmp; // [esp+160h] [ebp-28h] BYREF
  Vector in; // [esp+16Ch] [ebp-1Ch] BYREF
  long double v14; // [esp+178h] [ebp-10h]
  long double v15; // [esp+180h] [ebp-8h]

  v14 = (double)g_AIMoveTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
  v10 = (double)g_AIPostRunTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
  v11 = (double)g_AIMaintainScheduleTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
  *(double *)&tmp.y = (double)g_AIPrescheduleThinkTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
  *(_QWORD *)&v15 = g_AIRunTimer.m_Duration.m_Int64 & 0x7FFFFFFF00000000LL;
  *(double *)&in.y = (double)g_AIConditionsTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
  m_pName = this->m_pSchedule->m_pName;
  v15 = _g_ClockSpeedMillisecondsMultiplier * (double)g_AIRunTimer.m_Duration.m_Int64;
  v8 = m_pName;
  DebugName = CBaseEntity::GetDebugName(this);
  DevMsg(
    a1: "%s thinking for %.02fms!!! (%s); r%.2f (c%.2f, pst%.2f, ms%.2f), p-r%.2f, m%.2f\n",
    DebugName,
    time,
    v8,
    (double)v15,
    *(double *)&in.y,
    *(double *)&tmp.y,
    (double)v11,
    (double)v10,
    (double)v14);
  if ( ai_think_limit_label.m_pParent != nullptr && ai_think_limit_label.m_pParent->m_Value.m_nValue != 0 )
  {
    in.x = 0.5;
    in.y = 0.5;
    in.z = 1.0;
    CCollisionProperty::NormalizedToWorldSpace(this: &this->m_Collision, &in, pResult: &tmp);
    tmp.z = tmp.z + 16.0;
    v5 = -1.0;
    *(_QWORD *)&v14 = g_AIConditionsTimer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    HIDWORD(v15) = -1082130432;
    v6 = "unknown";
    *(double *)&in.y = (double)g_AIConditionsTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
    if ( *(double *)&in.y > -1.0 )
    {
      v5 = *(double *)&in.y;
      *((float *)&v15 + 1) = v5;
      v6 = "Conditions";
    }
    *(_QWORD *)&v14 = g_AIPrescheduleThinkTimer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    *(double *)&in.y = (double)g_AIPrescheduleThinkTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
    if ( *(double *)&in.y > *((float *)&v15 + 1) )
    {
      v5 = *(double *)&in.y;
      *((float *)&v15 + 1) = v5;
      v6 = "Pre-think";
    }
    *(_QWORD *)&v14 = g_AIMaintainScheduleTimer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    *(double *)&in.y = (double)g_AIMaintainScheduleTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
    if ( *(double *)&in.y > *((float *)&v15 + 1) )
    {
      v5 = *(double *)&in.y;
      *((float *)&v15 + 1) = v5;
      v6 = "Schedule";
    }
    *(_QWORD *)&v14 = g_AIPostRunTimer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    *(double *)&in.y = (double)g_AIPostRunTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
    if ( *(double *)&in.y > *((float *)&v15 + 1) )
    {
      v5 = *(double *)&in.y;
      *((float *)&v15 + 1) = v5;
      v6 = "Post-run";
    }
    *(_QWORD *)&v14 = g_AIMoveTimer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    *(double *)&in.y = _g_ClockSpeedMillisecondsMultiplier * (double)g_AIMoveTimer.m_Duration.m_Int64;
    if ( *(double *)&in.y > *((float *)&v15 + 1) )
    {
      v5 = *(double *)&in.y;
      v6 = "Move";
    }
    v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "Slow %.1f, %s %.1f ", time, v6, v5);
    NDebugOverlay::Text(origin: &tmp, text: v7->m_szBuf, bViewCheck: false, duration: 1.0);
  }
  if ( ai_report_task_timings_on_limit.m_pParent != nullptr
    && ai_report_task_timings_on_limit.m_pParent->m_Value.m_nValue != 0 )
  {
    CAI_BaseNPC::DumpTaskTimings(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022FE0
// Name: public: virtual enum CanPlaySequence_t CAI_BaseNPC::CanPlaySequence(bool,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::CanPlaySequence(CAI_BaseNPC *this, bool fDisregardNPCState, int interruptLevel)
{
  unsigned int m_Index; // ecx
  int v5; // ebx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CAI_ScriptedSequence **v11; // eax
  CAI_ScriptedSequence *v12; // eax
  NPC_STATE m_NPCState; // eax

  m_Index = this->m_hCine.m_Index;
  v5 = 1;
  if ( m_Index != -1 )
  {
    v6 = (unsigned __int16)m_Index;
    v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v8 = HIWORD(m_Index);
    if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
    {
      v9 = v6;
      v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
      v11 = (CAI_ScriptedSequence **)&g_pEntityList->m_EntPtrArray[v9];
      if ( v10 )
        v12 = *v11;
      else
        v12 = nullptr;
      if ( !CAI_ScriptedSequence::CanEnqueueAfter(this: v12) )
        return 0;
      v5 = 2;
    }
  }
  if ( !this->IsAlive(this) )
    return 0;
  if ( this->IsInAVehicle(this) )
    return 0;
  if ( !fDisregardNPCState )
  {
    m_NPCState = this->m_NPCState;
    if ( (unsigned int)m_NPCState >= NPC_STATE_ALERT
      && this->m_IdealNPCState != NPC_STATE_IDLE
      && (m_NPCState != NPC_STATE_ALERT || interruptLevel < 1) )
    {
      return 0;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100230A0
// Name: public: virtual class Vector CAI_BaseNPC::GetActualShootTrajectory(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__userpurge CAI_BaseNPC::GetActualShootTrajectory@<eax>(
        CAI_BaseNPC *this@<ecx>,
        int a2@<ebx>,
        Vector *result,
        const Vector *shootOrigin)
{
  bool v5; // zf
  CAI_BaseNPC_vtbl *v6; // eax
  int v8; // eax
  CBaseEntity *v9; // eax
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // edx
  int v11; // eax
  CBaseEntity *v12; // edi
  CBaseEntity *v13; // esi
  float *v14; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  CAI_BaseNPC_vtbl *v19; // ebx
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseCombatWeapon *v21; // eax
  const Vector *v22; // eax
  CBaseEntity *(__thiscall *v23)(CBaseEntity *); // edx
  int v24; // eax
  int v25; // eax
  int v26; // ebx
  float v27; // xmm3_4
  float v28; // xmm0_4
  int v29; // eax
  float *v30; // eax
  float v31; // xmm1_4
  float v32; // xmm2_4
  CBaseEntity *v33; // [esp+14h] [ebp-108h]
  float v34; // [esp+14h] [ebp-108h]
  int v35; // [esp+14h] [ebp-108h]
  CGameTrace tr; // [esp+28h] [ebp-F4h] BYREF
  Vector v37; // [esp+7Ch] [ebp-A0h] BYREF
  Vector v38; // [esp+88h] [ebp-94h] BYREF
  CShotManipulator manipulator; // [esp+94h] [ebp-88h] BYREF
  Vector vecProjectedPosition; // [esp+C4h] [ebp-58h] BYREF
  float v41; // [esp+D0h] [ebp-4Ch]
  float v42; // [esp+D4h] [ebp-48h]
  float v43; // [esp+D8h] [ebp-44h]
  float v44; // [esp+DCh] [ebp-40h]
  float v45; // [esp+E0h] [ebp-3Ch]
  float v46; // [esp+E4h] [ebp-38h]
  Vector vecShotDir; // [esp+E8h] [ebp-34h] BYREF
  Vector vecEnemyForward; // [esp+F4h] [ebp-28h] BYREF
  Vector vecEnd; // [esp+100h] [ebp-1Ch] BYREF
  float flVelocityScale; // [esp+10Ch] [ebp-10h]
  Vector shotDir; // [esp+110h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+11Ch] [ebp+0h] BYREF

  v5 = this->GetEnemy_2(this) == nullptr;
  v6 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v5 )
  {
    v6->GetShootEnemyDir(this, result, a3: shootOrigin, a4: true);
    return result;
  }
  v8 = ((int (__thiscall *)(CAI_BaseNPC *, int))v6->GetEnemy_2)(a1: this, a2);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 336))(a1: v8) != 0
    && this->m_nWaterLevel.m_Value != 3
    && this->GetEnemy_2(this)->m_nWaterLevel.m_Value == 3
    && random->RandomInt(this: random, a2: 0, a3: 4) < 3 )
  {
    v9 = this->GetEnemy_2(this);
    v9->GetVectors(this: v9, a2: &vecEnemyForward, a3: nullptr, a4: nullptr);
    GetEnemy_2 = this->GetEnemy_2;
    vecEnemyForward.z = 0.0;
    v11 = (int)GetEnemy_2(this);
    (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v11 + 540))(a1: v11, a2: &vecEnd);
    VectorNormalize(vec: &vecEnd);
    flVelocityScale = (float)((float)(vecEnemyForward.y * vecEnd.y) + (float)(vecEnd.x * vecEnemyForward.x))
                    + (float)(vecEnd.z * vecEnemyForward.z);
    if ( flVelocityScale < 0.0 )
      flVelocityScale = 0.0;
    v12 = this->GetEnemy_2(this);
    v13 = this->GetEnemy_2(this);
    v14 = (float *)v12->GetSmoothedVelocity(this: v12, result: &v37);
    v41 = flVelocityScale * *v14;
    v42 = v14[1] * flVelocityScale;
    EyePosition = v13->EyePosition;
    v43 = v14[2] * flVelocityScale;
    v44 = vecEnemyForward.x * 48.0;
    v45 = vecEnemyForward.y * 48.0;
    v46 = vecEnemyForward.z * 48.0;
    v16 = (float *)EyePosition(this: v13, result: &v38);
    v17 = (float)((float)(v16[1] + v45) + v42) - shootOrigin->y;
    v18 = (float)((float)(v16[2] + v46) + v43) - shootOrigin->z;
    vecShotDir.x = (float)((float)(*v16 + v44) + v41) - shootOrigin->x;
    vecShotDir.y = v17;
    vecShotDir.z = v18;
    VectorNormalize(vec: &vecShotDir);
    *result = vecShotDir;
    return result;
  }
  else
  {
    ((void (__thiscall *)(CAI_BaseNPC *))this->GetActualShootPosition)(a1: this);
    shotDir.x = vecProjectedPosition.x - shootOrigin->x;
    shotDir.y = vecProjectedPosition.y - shootOrigin->y;
    shotDir.z = vecProjectedPosition.z - shootOrigin->z;
    VectorNormalize(vec: &shotDir);
    this->CollectShotStats(this, a2: shootOrigin, a3: &shotDir);
    manipulator.m_vecShotDirection = shotDir;
    VectorVectors(forward: &manipulator.m_vecShotDirection, right: &manipulator.m_vecRight, up: &manipulator.m_vecUp);
    v19 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v33 = this->GetEnemy_2(this);
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    v34 = v19->GetSpreadBias(this, a2: ActiveWeapon, a3: v33);
    v35 = ((int (__thiscall *)(CAI_BaseNPC *, _DWORD))v19->GetEnemy_2)(a1: this, a2: LODWORD(v34));
    v21 = CBaseCombatCharacter::GetActiveWeapon(this);
    v22 = v19->GetAttackSpread(this, result: &v38, a3: v21, a4: (CBaseEntity *)v35);
    CShotManipulator::ApplySpread(this: &manipulator, vecSpread: v22, bias: COERCE_FLOAT(&vecProjectedPosition));
    v23 = this->GetEnemy_2;
    shotDir = manipulator.m_vecResult;
    v24 = (int)v23(this);
    v25 = (*(int (__thiscall **)(int))(*(_DWORD *)v24 + 300))(a1: v24);
    v26 = v25;
    if ( v25 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CAI_BaseNPC *))(*(_DWORD *)v25 + 980))(a1: v25, a2: this) != 0 )
    {
      v27 = shootOrigin->x + (float)(shotDir.x * 8192.0);
      vecEnd.y = shootOrigin->y + (float)(shotDir.y * 8192.0);
      v28 = shootOrigin->z + (float)(shotDir.z * 8192.0);
      vecEnd.x = v27;
      vecEnd.z = v28;
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: shootOrigin,
        vecAbsEnd: &vecEnd,
        mask: 0x46004003u,
        ignore: this,
        collisionGroup: 0,
        ptr: &tr);
      if ( tr.fraction != 1.0 && tr.m_pEnt != nullptr && tr.m_pEnt->m_takedamage.m_Value != 0 )
      {
        *result = manipulator.m_vecResult;
        return result;
      }
      v29 = (*(int (__thiscall **)(int))(*(_DWORD *)v26 + 984))(a1: v26);
      if ( v29 != 0 )
      {
        v30 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v29 + 588))(a1: v29);
        v31 = v30[1] - shootOrigin->y;
        v32 = v30[2] - shootOrigin->z;
        shotDir.x = *v30 - shootOrigin->x;
        shotDir.y = v31;
        shotDir.z = v32;
        VectorNormalize(vec: &shotDir);
      }
    }
    *result = shotDir;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023540
// Name: public: virtual void CAI_BaseNPC::OnScheduleChange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnScheduleChange(CAI_BaseNPC *this)
{
  CSound *m_pLockedBestSound; // eax
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // eax
  double v11; // st7
  unsigned int v12; // eax
  CAI_Hint *v13; // ecx
  float hintDelay; // [esp+10h] [ebp-4h]

  CAI_BaseNPC::EndTaskOverlay(this);
  this->m_pNavigator->OnScheduleChange(this: this->m_pNavigator);
  this->m_flMoveWaitFinished = 0.0;
  CAI_BaseNPC::VacateStrategySlot(this);
  CAI_Navigator::ClearGoal(this: this->m_pNavigator);
  m_pLockedBestSound = this->m_pLockedBestSound;
  if ( m_pLockedBestSound->m_iType != 0 )
  {
    m_pLockedBestSound->m_iType = 0;
    this->OnListened(this);
  }
  if ( (this->m_afMemory & 0x400) != 0 )
  {
    m_Index = this->m_pHintNode.m_Index;
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
        v11 = ((double (__thiscall *)(CAI_BaseNPC *, _DWORD))this->GetHintDelay)(
                a1: this,
                a2: SLOWORD(m_pEntity[217].__vftable));
        v12 = this->m_pHintNode.m_Index;
        if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
          v13 = nullptr;
        else
          v13 = (CAI_Hint *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
        hintDelay = v11;
        CAI_Hint::Unlock(this: v13, flSeconds: hintDelay);
        CAI_BaseNPC::SetHintNode(this, pHintNode: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023830
// Name: public: void CAI_BaseNPC::SaveConditions(class ISave __near &,class CBitVec<256> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SaveConditions(CAI_BaseNPC *this, ISave *save, const CBitVec<256> *conditions)
{
  int v4; // esi
  int v5; // edi
  int v6; // eax
  const char *v7; // eax

  v4 = 0;
  v5 = 1;
  while ( (v5 & conditions->m_Ints[v4 >> 5]) == 0 )
  {
LABEL_8:
    ++v4;
    v5 = __ROL4__(v5, 1);
    if ( v4 >= 256 )
      goto LABEL_9;
  }
  if ( v4 == -1 )
    v6 = -1;
  else
    v6 = v4 + 1000000000;
  v7 = this->ConditionName(this, a2: v6);
  if ( v7 != nullptr )
  {
    save->WriteString_4(this: save, a2: v7);
    goto LABEL_8;
  }
LABEL_9:
  save->WriteString_4(this: save, a2: locale);
}

//------------------------------------------------------------------------------
// Address: 0x100238A0
// Name: public: void CAI_BaseNPC::RestoreConditions(class IRestore __near &,class CBitVec<256> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RestoreConditions(CAI_BaseNPC *this, IRestore *restore, CBitVec<256> *pConditions)
{
  int v3; // eax
  char szCondition[256]; // [esp+8h] [ebp-100h] BYREF

  if ( pConditions != nullptr )
  {
    *(_QWORD *)pConditions->m_Ints = 0;
    *(_QWORD *)&pConditions->m_Ints[2] = 0;
    *(_QWORD *)&pConditions->m_Ints[4] = 0;
    *(_QWORD *)&pConditions->m_Ints[6] = 0;
  }
  restore->ReadString_2(this: restore, a2: szCondition, a3: 256, a4: 0);
  while ( szCondition[0] != 0 )
  {
    v3 = CAI_GlobalNamespace::SymbolToId(
           this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ConditionNamespace,
           pszSymbol: szCondition);
    if ( v3 != -1 )
      pConditions->m_Ints[(v3 - 1000000000) >> 5] |= 1 << (v3 & 0x1F);
    restore->ReadString_2(this: restore, a2: szCondition, a3: 256, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023950
// Name: public: void CAI_BaseNPC::InputSetEnemyFilter(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputSetEnemyFilter(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax
  const char *iVal; // eax
  CBaseEntity *EntityByName; // eax
  void *v6; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  iVal = (const char *)p_value->iVal;
  if ( iVal == nullptr )
    iVal = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: iVal,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v6 = __RTDynamicCast(
         inptr: EntityByName,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CBaseFilter `RTTI Type Descriptor',
         isReference: 0);
  if ( v6 != nullptr )
    this->m_hEnemyFilter.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v6 + 8))(a1: v6);
  else
    this->m_hEnemyFilter.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100239D0
// Name: public: void CAI_BaseNPC::CleanupScriptsOnTeleport(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::CleanupScriptsOnTeleport(CAI_BaseNPC *this, bool bEnrouteAsWell)
{
  unsigned int m_Index; // eax
  CBaseEntityList *v3; // ebx
  int v4; // esi
  unsigned int v5; // edi
  CAI_BaseNPC::SCRIPTSTATE m_scriptState; // eax

  if ( this->m_NPCState == NPC_STATE_SCRIPT )
  {
    m_Index = this->m_hCine.m_Index;
    if ( m_Index != -1 )
    {
      v3 = g_pEntityList;
      v4 = (unsigned __int16)m_Index;
      v5 = HIWORD(m_Index);
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
        && (bEnrouteAsWell
         || (m_scriptState = this->m_scriptState) != SCRIPT_WALK_TO_MARK
         && m_scriptState != SCRIPT_RUN_TO_MARK
         && m_scriptState != SCRIPT_CUSTOM_MOVE_TO_MARK
         && *((_BYTE *)&CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine)[1].m_Network
            + 78) == 0) )
      {
        if ( v3->m_EntPtrArray[v4].m_SerialNumber == v5 )
          CAI_ScriptedSequence::ScriptEntityCancel(
            pentCine: (CBaseEntity *)v3->m_EntPtrArray[v4].m_pEntity,
            bPretendSuccess: true);
        else
          CAI_ScriptedSequence::ScriptEntityCancel(pentCine: nullptr, bPretendSuccess: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023A90
// Name: public: bool CAI_BaseNPC::ExitScriptedSequence(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::ExitScriptedSequence(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CAI_ScriptedSequence **v8; // eax

  if ( this->m_lifeState.m_Value == 1 )
  {
    if ( this->m_IdealNPCState != NPC_STATE_DEAD )
      this->m_IdealNPCState = NPC_STATE_DEAD;
    return 0;
  }
  else
  {
    m_Index = this->m_hCine.m_Index;
    if ( m_Index != -1 )
    {
      v3 = (unsigned __int16)m_Index;
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v5 = HIWORD(m_Index);
      if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
      {
        v6 = v3;
        v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
        v8 = (CAI_ScriptedSequence **)&g_pEntityList->m_EntPtrArray[v6];
        if ( v7 )
        {
          CAI_ScriptedSequence::CancelScript(this: *v8);
          return 1;
        }
        CAI_ScriptedSequence::CancelScript(this: nullptr);
      }
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023B10
// Name: public: virtual void CAI_BaseNPC::Teleport(class Vector const __near *,class QAngle const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::Teleport(
        CAI_BaseNPC *this,
        const Vector *newPosition,
        const QAngle *newAngles,
        const Vector *newVelocity,
        bool bUseSlowHighAccuracyContacts)
{
  CAI_BaseNPC::CleanupScriptsOnTeleport(this, bEnrouteAsWell: false);
  CBaseFlex::Teleport(this, newPosition, newAngles, newVelocity, bUseSlowHighAccuracyContacts);
  this->CheckPVSCondition(this);
}

//------------------------------------------------------------------------------
// Address: 0x10023B50
// Name: public: virtual bool CAI_BaseNPC::OnUpcomingPropDoor(struct AILocalMoveGoal_t __near *,class CBasePropDoor __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::OnUpcomingPropDoor(
        CAI_BaseNPC *this,
        AILocalMoveGoal_t *pMoveGoal,
        CBasePropDoor *pDoor,
        float distClear,
        AIMoveResult_t *pResult)
{
  unsigned int m_Index; // eax
  CBasePropDoor *m_pEntity; // ecx
  CBasePropDoor::DoorState_t m_eDoorState; // eax
  CHandle<CBaseEntity> *v10; // eax
  AI_Waypoint_t *v11; // ebx
  opendata_t opendata; // [esp+18h] [ebp-20h] BYREF
  CHandle<CBaseEntity> *p_m_hOpeningDoor; // [esp+34h] [ebp-4h]

  this->CapabilitiesGet(this);
  if ( (pMoveGoal->flags & 1) != 0 && distClear > pMoveGoal->maxDist
    || distClear > NAI_Hull::Width(id: this->m_eHull) * 0.25 + pMoveGoal->maxDist )
  {
    return 0;
  }
  m_Index = this->m_hOpeningDoor.m_Index;
  p_m_hOpeningDoor = (CHandle<CBaseEntity> *)&this->m_hOpeningDoor;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBasePropDoor *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( pDoor == m_pEntity )
  {
    if ( CBasePropDoor::IsNPCOpening(this: pDoor, pNPC: this) )
    {
      pMoveGoal->maxDist = distClear;
      *pResult = AIMR_OK;
      return 1;
    }
    this->m_hOpeningDoor.m_Index = -1;
  }
  if ( (this->CapabilitiesGet(this) & 0xC00) == 0 )
    return 0;
  if ( pDoor->IsDoorLocked(this: pDoor) )
    return 0;
  m_eDoorState = pDoor->m_eDoorState;
  if ( m_eDoorState != DOOR_STATE_CLOSED && m_eDoorState != DOOR_STATE_CLOSING )
    return 0;
  pDoor->GetNPCOpenData(this: pDoor, a2: this, a3: &opendata);
  v10 = (CHandle<CBaseEntity> *)((int (__stdcall *)(CNetworkVectorXY_SeparateZBase<Vector,CBaseEntity::NetworkVar_m_vecOrigin> *, opendata_t *, _DWORD, int, int, int, _DWORD))this->m_pPathfinder->BuildLocalRoute)(
                                  a1: &this->m_vecOrigin,
                                  a2: &opendata,
                                  a3: 0,
                                  a4: 48,
                                  a5: -1,
                                  a6: 129,
                                  a7: 0);
  v11 = (AI_Waypoint_t *)v10;
  if ( v10 == nullptr )
    return 0;
  CHandle<CBaseEntity>::operator=(this: v10 + 7, val: pDoor);
  CAI_Path::PrependWaypoints(this: this->m_pNavigator->m_pPath, pWaypoints: v11);
  CHandle<CBaseEntity>::operator=(this: p_m_hOpeningDoor, val: pDoor);
  pMoveGoal->maxDist = distClear;
  *pResult = AIMR_CHANGE_TYPE;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10023CF0
// Name: public: void CAI_BaseNPC::OnDoorFullyOpen(class CBasePropDoor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnDoorFullyOpen(CAI_BaseNPC *this, CBasePropDoor *pDoor)
{
  this->m_hOpeningDoor.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10023D00
// Name: void DevMsg(class CAI_BaseNPC __near *,unsigned int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DevMsg(CAI_BaseNPC *pAI, char flags, const char *pszFormat, ...)
{
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+4h] [ebp-10Ch] BYREF

  if ( (flags & 1) != 0 || (pAI->m_debugOverlays & 0x1000) != 0 )
  {
    v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, ppszFormat: &pszFormat);
    AIMsgGuts(pAI, flags: v3->m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023D50
// Name: void DevMsg(class CAI_BaseNPC __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DevMsg(CAI_BaseNPC *pAI, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // eax
  CFmtStrN<256> v3; // [esp+4h] [ebp-10Ch] BYREF

  if ( (pAI->m_debugOverlays & 0x1000) != 0 )
  {
    v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v3, ppszFormat: &pszFormat);
    AIMsgGuts(pAI, flags: v2->m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023D90
// Name: public: virtual bool CAI_BaseNPC::IsCoverPosition(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsCoverPosition(CAI_BaseNPC *this, const Vector *vecThreat, const Vector *vecPosition)
{
  CBaseEntity *v4; // eax
  float *v5; // eax
  float v6; // xmm1_4
  CBaseEntity *v7; // eax
  int v8; // eax
  int v9; // edi
  CGameTrace tr; // [esp+8h] [ebp-78h] BYREF
  CTraceFilterLOS filter; // [esp+5Ch] [ebp-24h] BYREF
  Vector v13; // [esp+70h] [ebp-10h] BYREF
  CBaseEntity *pEnemy; // [esp+7Ch] [ebp-4h]

  CTraceFilterLOS::CTraceFilterLOS(this: &filter, pHandleEntity: nullptr, collisionGroup: 0, pHandleEntity2: this);
  pEnemy = this->GetEnemy_2(this);
  if ( pEnemy != nullptr )
  {
    v4 = this->GetEnemy_2(this);
    v5 = (float *)v4->EyePosition(this: v4, result: &v13);
    v6 = vecThreat->y - v5[1];
    if ( (float)((float)((float)((float)(vecThreat->x - *v5) * (float)(vecThreat->x - *v5)) + (float)(v6 * v6))
               + (float)((float)(vecThreat->z - v5[2]) * (float)(vecThreat->z - v5[2]))) < 0.1 )
    {
      v7 = this->GetEnemy_2(this);
      v8 = (int)v7->MyCombatCharacterPointer(this: v7);
      v9 = v8;
      if ( v8 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 1260))(a1: v8) != 0 )
        filter.m_pPassEnt = (const IHandleEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 1268))(a1: v9);
      if ( filter.m_pPassEnt == nullptr )
        filter.m_pPassEnt = pEnemy;
    }
  }
  AI_TraceLOS(a1: (int)this, vecAbsStart: vecThreat, vecAbsEnd: vecPosition, pLooker: this, ptr: &tr, pFilter: &filter);
  if ( tr.fraction == 1.0 )
    return false;
  return hl2_episodic.m_pParent == nullptr
      || hl2_episodic.m_pParent->m_Value.m_nValue == 0
      || tr.m_pEnt->m_iClassname.pszValue != this->m_iClassname.pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x10023ED0
// Name: public: virtual float CAI_BaseNPC::LineOfSightDist(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CAI_BaseNPC::LineOfSightDist@<st0>(
        CAI_BaseNPC *this@<ecx>,
        float a2@<ebp>,
        const Vector *vecDir,
        float zEye)
{
  Vector *v5; // eax
  float z; // xmm0_4
  float y; // xmm4_4
  float v9[3]; // [esp-Ch] [ebp-9Ch] BYREF
  CGameTrace tr; // [esp+0h] [ebp-90h] BYREF
  Vector v11; // [esp+68h] [ebp-28h] BYREF
  Vector testPos; // [esp+74h] [ebp-1Ch] BYREF
  float v13; // [esp+80h] [ebp-10h]
  Vector testDir; // [esp+84h] [ebp-Ch] BYREF
  float retaddr; // [esp+90h] [ebp+0h]

  testDir.x = a2;
  testDir.y = retaddr;
  if ( vec3_invalid.x == vecDir->x && vec3_invalid.y == vecDir->y && vec3_invalid.z == vecDir->z )
  {
    v5 = this->EyeDirection3D(this, result: &v11);
    testPos.y = v5->x;
    testPos.z = v5->y;
    z = v5->z;
  }
  else
  {
    testPos.y = vecDir->x;
    testPos.z = vecDir->y;
    z = vecDir->z;
  }
  v13 = z;
  if ( zEye == 3.4028235e38 )
    zEye = this->EyePosition(this, result: &v11)->z;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  y = this->m_vecAbsOrigin.y;
  v11.x = this->m_vecAbsOrigin.x;
  v11.y = y;
  v11.z = zEye;
  testPos.y = (float)(testPos.y * 16384.0) + v11.x;
  testPos.z = (float)(testPos.z * 16384.0) + y;
  v13 = (float)(16384.0 * v13) + zEye;
  if ( ai_LOS_mode.m_pParent != nullptr && ai_LOS_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    UTIL_TraceLine(
      a1: (const IHandleEntity *)&testDir,
      a2: (int)this,
      vecAbsStart: &v11,
      vecAbsEnd: (Vector *)&testPos.y,
      mask: 0x4041u,
      ignore: this,
      collisionGroup: 0,
      ptr: (CGameTrace *)v9);
  }
  else
  {
    CTraceFilterLOS::CTraceFilterLOS(
      this: (CTraceFilterLOS *)&tr.hitbox,
      pHandleEntity: this,
      collisionGroup: 0,
      pHandleEntity2: nullptr);
    UTIL_TraceLine(
      a1: (int)&testDir,
      a2: (int)this,
      vecAbsStart: &v11,
      vecAbsEnd: (Vector *)&testPos.y,
      mask: 0x2004041u,
      pFilter: (ITraceFilter *)&tr.hitbox,
      ptr: (CGameTrace *)v9);
  }
  return fsqrt(
           (float)((float)((float)(v9[1] - tr.startpos.y) * (float)(v9[1] - tr.startpos.y))
                 + (float)((float)(v9[2] - tr.startpos.z) * (float)(v9[2] - tr.startpos.z)))
         + (float)((float)(v9[0] - tr.startpos.x) * (float)(v9[0] - tr.startpos.x)));
}

//------------------------------------------------------------------------------
// Address: 0x100240E0
// Name: protected: virtual bool CAI_BaseNPC::CanRunAScriptedNPCInteraction(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::CanRunAScriptedNPCInteraction(CAI_BaseNPC *this, bool bForced)
{
  NPC_STATE m_NPCState; // eax
  CHandle<CAI_BaseNPC> *p_m_hForcedInteractionPartner; // ecx

  m_NPCState = this->m_NPCState;
  if ( m_NPCState != NPC_STATE_IDLE && m_NPCState != NPC_STATE_ALERT && m_NPCState != NPC_STATE_COMBAT
    || !this->IsAlive(this)
    || (this->m_fFlags.m_Value & 0x10000000) != 0
    || this->IsCrouching(this)
    || CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine) != nullptr )
  {
    return 0;
  }
  p_m_hForcedInteractionPartner = &this->m_hForcedInteractionPartner;
  if ( bForced )
  {
    if ( CHandle<CAI_BaseNPC>::operator!(this: p_m_hForcedInteractionPartner) )
      return 0;
  }
  else if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)p_m_hForcedInteractionPartner) != nullptr
         || CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hInteractionPartner) != nullptr
         || this->m_bInAScript
         || !CAI_BaseNPC::HasCondition(this, iCondition: 1)
         || CAI_BaseNPC::HasCondition(this, iCondition: 50)
         || CAI_BaseNPC::HasCondition(this, iCondition: 58)
         || CAI_BaseNPC::IsCurSchedule(this, schedId: 42, fIdeal: true)
         || CAI_BaseNPC::IsCurSchedule(this, schedId: 43, fIdeal: true) )
  {
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100241C0
// Name: protected: bool CAI_BaseNPC::HasInteractionCantDie(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::HasInteractionCantDie(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx
  BOOL result; // eax

  result = false;
  if ( this->m_bCannotDieDuringInteraction && this->m_iInteractionState != 0 )
  {
    m_Index = this->m_hCine.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10024210
// Name: protected: void CAI_BaseNPC::StartForcedInteraction(class CAI_BaseNPC __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::StartForcedInteraction(CAI_BaseNPC *this, CAI_BaseNPC *pNPC, int iInteraction)
{
  if ( pNPC != nullptr )
    this->m_hForcedInteractionPartner.m_Index = pNPC->GetRefEHandle(this: pNPC)->m_Index;
  else
    this->m_hForcedInteractionPartner.m_Index = -1;
  CAI_BaseNPC::ClearSchedule(this, szReason: "Starting a forced interaction");
  this->m_flForcedInteractionTimeout = gpGlobals->curtime + 8.0;
  this->m_iInteractionPlaying = iInteraction;
  this->m_iInteractionState = 3;
}

//------------------------------------------------------------------------------
// Address: 0x10024280
// Name: protected: void CAI_BaseNPC::CalculateForcedInteractionPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::CalculateForcedInteractionPosition(CAI_BaseNPC *this)
{
  int m_iInteractionPlaying; // eax
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ebx
  int m_iEFlags; // eax
  unsigned int v6; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  CBaseEntity *v10; // esi
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  VMatrix matMeToWorld; // [esp+4h] [ebp-B4h] BYREF
  VMatrix matLocalToWorld; // [esp+44h] [ebp-74h] BYREF
  QAngle angToTarget; // [esp+84h] [ebp-34h] BYREF
  Vector vecToTarget; // [esp+90h] [ebp-28h] BYREF
  Vector vecOrigin; // [esp+9Ch] [ebp-1Ch]
  ScriptedNPCInteraction_t *pInteraction; // [esp+A8h] [ebp-10h]
  float v20; // [esp+ACh] [ebp-Ch]
  float v21; // [esp+B0h] [ebp-8h]
  float v22; // [esp+B4h] [ebp-4h]

  m_iInteractionPlaying = this->m_iInteractionPlaying;
  if ( m_iInteractionPlaying != -1 )
  {
    pInteraction = &this->m_ScriptedInteractions.m_Memory.m_pMemory[m_iInteractionPlaying];
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    m_Index = this->m_hForcedInteractionPartner.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity);
    vecToTarget.x = m_pEntity->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
    vecToTarget.y = m_pEntity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
    vecToTarget.z = m_pEntity->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
    VectorNormalize(vec: &vecToTarget);
    VectorAngles(forward: &vecToTarget, angles: &angToTarget);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    VMatrix::SetupMatrixOrgAngles(this: &matMeToWorld, origin: &this->m_vecAbsOrigin, vAngles: &angToTarget);
    MatrixMultiply(src1: &matMeToWorld, src2: &pInteraction->matDesiredLocalToWorld, dst: &matLocalToWorld);
    m_iEFlags = this->m_iEFlags;
    v20 = matLocalToWorld.m[0][3];
    v21 = matLocalToWorld.m[1][3];
    v22 = matLocalToWorld.m[2][3];
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    v6 = this->m_hForcedInteractionPartner.m_Index;
    x = this->m_vecAbsOrigin.x - v20;
    y = this->m_vecAbsOrigin.y - v21;
    z = this->m_vecAbsOrigin.z - v22;
    vecOrigin.x = x;
    vecOrigin.y = y;
    vecOrigin.z = z;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      v10 = nullptr;
    else
      v10 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    if ( (v10->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v10);
      z = vecOrigin.z;
      y = vecOrigin.y;
      x = vecOrigin.x;
    }
    v11 = v10->m_vecAbsOrigin.x + x;
    v12 = v10->m_vecAbsOrigin.y + y;
    v13 = v10->m_vecAbsOrigin.z;
    this->m_vecForcedWorldPosition.x = v11;
    this->m_vecForcedWorldPosition.y = v12;
    this->m_vecForcedWorldPosition.z = v13 + z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024540
// Name: public: virtual void CFunctor2<void (*)(class CFunctor __near * __near *,unsigned int),class CFunctor __near * __near *,int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor2<void (__cdecl *)(CFunctor * *,unsigned int),CFunctor * *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor2<void (__cdecl*)(CFunctor * *,unsigned int),CFunctor * *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1, a2: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x100248B0
// Name: protected: virtual void CAI_Component::TaskComplete(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Component::TaskComplete(CAI_Component *this, bool fIgnoreSetFailedCondition)
{
  CAI_BaseNPC::TaskComplete(this: this->m_pOuter, fIgnoreSetFailedCondition);
}

//------------------------------------------------------------------------------
// Address: 0x100248C0
// Name: public: virtual int CAI_BaseNPC::OnTakeDamage_Dying(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
WeaponProficiency_t __thiscall CAI_BaseNPC::OnTakeDamage_Dying(CAI_BaseNPC *this, CBaseCombatWeapon *info)
{
  int m_Value; // eax
  int v4; // ecx
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // edi
  int v6; // esi

  if ( ((int)info->m_Network.m_pServerClass & 0x1000000) != 0 && this->m_takedamage.m_Value != 1 )
  {
    m_Value = this->m_iHealth.m_Value;
    v4 = (int)info->m_Network.m_PVSInfo.m_vCenter[2];
    p_m_iHealth = &this->m_iHealth;
    v6 = m_Value - v4;
    if ( m_Value != m_Value - v4 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      p_m_iHealth->m_Value = v6;
    }
    if ( p_m_iHealth->m_Value < -500 )
      UTIL_Remove(oldObj: this);
  }
  return CTeamplayRules::GetCaptureValueForPlayer(this, pWeapon: info);
}

//------------------------------------------------------------------------------
// Address: 0x10024930
// Name: public: virtual int CAI_BaseNPC::OnTakeDamage_Dead(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CAI_BaseNPC::OnTakeDamage_Dead@<eax>(
        CAI_BaseNPC *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const CTakeDamageInfo *info)
{
  const CTakeDamageInfo *v5; // esi
  unsigned int m_Index; // ecx
  int v8; // eax
  CEntInfo *v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  bool v12; // zf
  CEntInfo *v13; // eax
  IHandleEntity *m_pEntity; // ecx
  float *v15; // eax
  const Vector *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  int v19; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // edi
  int v21; // esi
  int v23; // [esp-Ch] [ebp-24h]
  int v24; // [esp-8h] [ebp-20h]
  int v25; // [esp-4h] [ebp-1Ch]
  float v26; // [esp+0h] [ebp-18h]
  float v27; // [esp+4h] [ebp-14h]
  float v28; // [esp+8h] [ebp-10h]
  Vector vecDir; // [esp+Ch] [ebp-Ch] BYREF

  v25 = a2;
  v24 = a4;
  v5 = info;
  vecDir.x = vec3_origin.x;
  m_Index = info->m_hInflictor.m_Index;
  vecDir.y = vec3_origin.y;
  v23 = a3;
  vecDir.z = vec3_origin.z;
  if ( m_Index != -1 )
  {
    v8 = (unsigned __int16)m_Index;
    v9 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v10 = HIWORD(m_Index);
    if ( v9->m_SerialNumber == v10 && v9->m_pEntity != nullptr )
    {
      v11 = v8;
      v12 = g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v10;
      v13 = &g_pEntityList->m_EntPtrArray[v11];
      if ( v12 )
        m_pEntity = v13->m_pEntity;
      else
        m_pEntity = nullptr;
      v15 = (float *)((int (__thiscall *)(IHandleEntity *, int, int, int))m_pEntity->__vftable[49].dtr_IHandleEntity)(
                       a1: m_pEntity,
                       a2: a3,
                       a3: v24,
                       a4: v25);
      v26 = *v15;
      v27 = v15[1];
      v28 = v15[2] - 10.0;
      v16 = this->WorldSpaceCenter(this);
      v17 = v27 - v16->y;
      v18 = v28 - v16->z;
      vecDir.x = v26 - v16->x;
      vecDir.y = v17;
      vecDir.z = v18;
      VectorNormalize(vec: &vecDir);
      g_vecAttackDir = vecDir;
    }
  }
  if ( ((unsigned __int8 (__thiscall *)(CGameRules *, int, int, int, int))g_pGameRules->Damage_ShouldGibCorpse)(
         a1: g_pGameRules,
         a2: info->m_bitsDamageType,
         a3: v23,
         a4: v24,
         a5: v25) != 0
    && this->m_takedamage.m_Value != 1 )
  {
    v19 = this->m_iHealth.m_Value - (int)(info->m_flDamage * 0.1);
    if ( this->m_iHealth.m_Value != v19 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      this->m_iHealth.m_Value = v19;
    }
    v5 = info;
  }
  if ( (v5->m_bitsDamageType & 0x1000000) != 0 && this->m_takedamage.m_Value != 1 )
  {
    p_m_iHealth = &this->m_iHealth;
    v21 = this->m_iHealth.m_Value - (int)v5->m_flDamage;
    if ( this->m_iHealth.m_Value != v21 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      p_m_iHealth->m_Value = v21;
    }
    if ( p_m_iHealth->m_Value < -500 )
      UTIL_Remove(oldObj: this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024B10
// Name: public: virtual void CAI_BaseNPC::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CAI_BaseNPC::TraceAttack(
        CAI_BaseNPC *this@<ecx>,
        int a2@<ebp>,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  CGameTrace *v6; // edx
  edict_t *m_pPev; // ecx
  int m_nValue; // eax
  bool v9; // zf
  int hitgroup; // eax
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  int v16; // eax
  CGameTrace *v17; // edi
  __int128 v18; // xmm4
  unsigned int m_Index; // ecx
  int v20; // eax
  CEntInfo *v21; // edx
  unsigned int v22; // ecx
  int v23; // eax
  CEntInfo *v24; // eax
  IHandleEntity *m_pEntity; // eax
  unsigned int v26; // eax
  IHandleEntity *v27; // ecx
  float flDamage; // [esp+Ch] [ebp-A0h]
  float v29; // [esp+20h] [ebp-8Ch] BYREF
  float v30; // [esp+24h] [ebp-88h]
  float v31; // [esp+28h] [ebp-84h]
  _BYTE subInfo_24[76]; // [esp+44h] [ebp-68h] OVERLAPPED
  int physicsbone; // [esp+98h] [ebp-14h]
  bool v34; // [esp+9Fh] [ebp-Dh]
  int v35; // [esp+A0h] [ebp-Ch]
  void *v36; // [esp+A4h] [ebp-8h]
  void *retaddr; // [esp+ACh] [ebp+0h]

  v35 = a2;
  v36 = retaddr;
  v9 = this->m_takedamage.m_Value == 0;
  this->m_fNoDamageDecal = false;
  if ( !v9 )
  {
    CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&v29, __that: info);
    v6 = ptr;
    this->m_LastHitGroup = ptr->hitgroup;
    physicsbone = ptr->physicsbone;
    if ( this->m_nForceBone.m_Value != physicsbone )
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
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
          v6 = ptr;
        }
      }
      this->m_nForceBone.m_Value = physicsbone;
    }
    if ( showhitlocation.m_pParent != nullptr )
      m_nValue = showhitlocation.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v9 = m_nValue == 0;
    hitgroup = v6->hitgroup;
    v34 = !v9;
    switch ( hitgroup )
    {
      case 0:
        if ( !v9 )
          DevMsg(a1: "Hit Location: Generic\n");
        break;
      case 1:
        v11 = ((double (__thiscall *)(CAI_BaseNPC *, int, const CTakeDamageInfo *))this->GetHitgroupDamageMultiplier)(
                a1: this,
                a2: 1,
                a3: info);
        *(float *)&subInfo_24[12] = v11 * *(float *)&subInfo_24[12];
        if ( v34 )
          DevMsg(a1: "Hit Location: Head\n");
        break;
      case 2:
        v12 = ((double (__thiscall *)(CAI_BaseNPC *, int, const CTakeDamageInfo *))this->GetHitgroupDamageMultiplier)(
                a1: this,
                a2: 2,
                a3: info);
        *(float *)&subInfo_24[12] = v12 * *(float *)&subInfo_24[12];
        if ( v34 )
          DevMsg(a1: "Hit Location: Chest\n");
        break;
      case 3:
        v13 = ((double (__thiscall *)(CAI_BaseNPC *, int, const CTakeDamageInfo *))this->GetHitgroupDamageMultiplier)(
                a1: this,
                a2: 3,
                a3: info);
        *(float *)&subInfo_24[12] = v13 * *(float *)&subInfo_24[12];
        if ( v34 )
          DevMsg(a1: "Hit Location: Stomach\n");
        break;
      case 4:
      case 5:
        v14 = ((double (__thiscall *)(CAI_BaseNPC *, int, const CTakeDamageInfo *))this->GetHitgroupDamageMultiplier)(
                a1: this,
                a2: hitgroup,
                a3: info);
        *(float *)&subInfo_24[12] = v14 * *(float *)&subInfo_24[12];
        if ( v34 )
          DevMsg(a1: "Hit Location: Left/Right Arm\n");
        break;
      case 6:
      case 7:
        v15 = ((double (__thiscall *)(CAI_BaseNPC *, int, const CTakeDamageInfo *))this->GetHitgroupDamageMultiplier)(
                a1: this,
                a2: hitgroup,
                a3: info);
        *(float *)&subInfo_24[12] = v15 * *(float *)&subInfo_24[12];
        if ( v34 )
          DevMsg(a1: "Hit Location: Left/Right Leg\n");
        break;
      case 10:
        *(_DWORD *)&subInfo_24[12] = 1008981770;
        v6->hitgroup = 0;
        if ( !v9 )
          DevMsg(a1: "Hit Location: Gear\n");
        break;
      default:
        if ( !v9 )
          DevMsg(a1: "Hit Location: UNKNOWN\n");
        break;
    }
    if ( *(float *)&subInfo_24[12] >= 1.0 && (*(_WORD *)&subInfo_24[24] & 0x100) == 0 )
    {
      if ( !this->IsPlayer(this) || this->IsPlayer(this) && g_pGameRules->IsMultiplayer(this: g_pGameRules) )
      {
        flDamage = *(float *)&subInfo_24[12];
        v16 = this->BloodColor(this);
        v17 = ptr;
        SpawnBlood(vecSpot: ptr->endpos, vecDir, bloodColor: v16, flDamage);
      }
      else
      {
        v17 = ptr;
      }
      CBaseEntity::TraceBleed(
        this,
        flDamage: *(float *)&subInfo_24[12],
        vecDir,
        ptr: v17,
        bitsDamageType: *(int *)&subInfo_24[24]);
      if ( v17->hitgroup == 1 && (float)((float)this->m_iHealth.m_Value - *(float *)&subInfo_24[12]) > 0.0 )
        this->m_fNoDamageDecal = true;
    }
    if ( (info->m_bitsDamageType & 0x2000000) != 0 && *(float *)&subInfo_24[12] >= (float)this->m_iHealth.m_Value )
    {
      v18 = 0;
      *(float *)&v18 = fsqrt((float)((float)(v30 * v30) + (float)(v29 * v29)) + (float)(v31 * v31));
      *(_OWORD *)&subInfo_24[60] = v18;
      if ( *(float *)&v18 != 0.0 && *(float *)&subInfo_24[60] < 26000.0 )
      {
        v29 = v29 * (float)(26000.0 / *(float *)&subInfo_24[60]);
        v30 = v30 * (float)(26000.0 / *(float *)&subInfo_24[60]);
        v31 = v31 * (float)(26000.0 / *(float *)&subInfo_24[60]);
      }
    }
    m_Index = info->m_hInflictor.m_Index;
    if ( m_Index != -1
      && (v20 = (unsigned __int16)m_Index,
          v21 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v22 = HIWORD(m_Index),
          v21->m_SerialNumber == v22)
      && v21->m_pEntity != nullptr )
    {
      v23 = v20;
      v9 = g_pEntityList->m_EntPtrArray[v23].m_SerialNumber == v22;
      v24 = &g_pEntityList->m_EntPtrArray[v23];
      if ( v9 )
      {
        m_pEntity = v24->m_pEntity;
        if ( m_pEntity != nullptr )
        {
          *(_DWORD *)subInfo_24 = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
LABEL_54:
          AddMultiDamage(info: (const CTakeDamageInfo *)&v29, pEntity: this);
          return;
        }
      }
    }
    else
    {
      v26 = info->m_hAttacker.m_Index;
      if ( v26 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_SerialNumber == HIWORD(v26) )
      {
        v27 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_pEntity;
        if ( v27 != nullptr )
        {
          *(_DWORD *)subInfo_24 = v27->GetRefEHandle(this: v27)->m_Index;
          goto LABEL_54;
        }
      }
    }
    *(_DWORD *)subInfo_24 = -1;
    goto LABEL_54;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024F20
// Name: public: void CAI_BaseNPC::SetCondition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetCondition(CAI_BaseNPC *this, int iCondition)
{
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax
  int v5; // ebx

  if ( iCondition >= 1000000000 )
  {
    v4 = iCondition;
  }
  else
  {
    v3 = this->GetClassScheduleIdSpace(this);
    v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: iCondition);
  }
  if ( v4 != -1 )
  {
    v5 = v4 - 1000000000;
    if ( v4 != 999999999 )
    {
      if ( !CAI_BaseNPC::HasCondition(this, iCondition) )
        this->OnConditionSet(this, a2: iCondition);
      this->m_Conditions.m_Ints[v5 >> 5] |= 1 << (v5 & 0x1F);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024FA0
// Name: public: virtual void CAI_BaseNPC::OnLooked(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAI_BaseNPC::OnLooked(CAI_BaseNPC *this@<ecx>, CBaseEntity *a2@<ebx>, int iDistance)
{
  CAI_ClassScheduleIdSpace *v4; // eax
  int v5; // eax
  int v6; // eax
  CBaseEntity *i; // ebx
  CAI_ClassScheduleIdSpace *v8; // eax
  int v9; // eax
  int v10; // edi
  CAI_ClassScheduleIdSpace *v11; // eax
  int v12; // eax
  int v13; // eax
  CAI_ClassScheduleIdSpace *v14; // eax
  int v15; // eax
  int v16; // edi
  CAI_ClassScheduleIdSpace *v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  CAI_ClassScheduleIdSpace *v21; // eax
  int v22; // eax
  int v23; // edi
  CAI_ClassScheduleIdSpace *v24; // eax
  int v25; // eax
  int v26; // eax
  CAI_ClassScheduleIdSpace *v27; // eax
  int v28; // eax
  int v29; // edi
  CAI_ClassScheduleIdSpace *v30; // eax
  int v31; // eax
  int v32; // eax
  const char *pszValue; // eax
  const char *Classname; // eax
  CAI_ClassScheduleIdSpace *v35; // eax
  int v36; // eax
  int v37; // eax
  CAI_ClassScheduleIdSpace *v38; // eax
  int v39; // eax
  int v40; // edi
  CAI_ClassScheduleIdSpace *v41; // eax
  int v42; // eax
  int v43; // eax
  const char *v44; // [esp-8h] [ebp-1Ch]
  AISightIter_t__ *iter; // [esp+8h] [ebp-Ch] BYREF
  Disposition_t relation; // [esp+Ch] [ebp-8h]
  bool bHadSeePlayer; // [esp+13h] [ebp-1h]

  v4 = this->GetClassScheduleIdSpace(this);
  v5 = CAI_LocalIdSpace::LocalToGlobal(this: &v4->m_ConditionIds, localID: 32);
  bHadSeePlayer = v5 != -1
               && (v6 = v5 - 1000000000) != -1
               && ((1 << (v6 & 0x1F)) & this->m_Conditions.m_Ints[v6 >> 5]) != 0;
  CAI_BaseNPC::ClearConditions(this, pConditions: conditionsToClear_0, nConditions: 8);
  for ( i = CAI_Senses::GetFirstSeenEntity(this: this->m_pSenses, pIter: &iter, iSeenType: SEEN_ALL);
        i != nullptr;
        i = CAI_Senses::GetNextSeenEntity(this: this->m_pSenses, pIter: &iter) )
  {
    if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *, CBaseEntity *))i->IsPlayer)(a1: i, a2) != 0 )
    {
      v8 = this->GetClassScheduleIdSpace(this);
      v9 = CAI_LocalIdSpace::LocalToGlobal(this: &v8->m_ConditionIds, localID: 32);
      if ( v9 != -1 )
      {
        v10 = v9 - 1000000000;
        if ( v9 != 999999999 )
        {
          v11 = this->GetClassScheduleIdSpace(this);
          v12 = CAI_LocalIdSpace::LocalToGlobal(this: &v11->m_ConditionIds, localID: 32);
          if ( v12 == -1
            || (v13 = v12 - 1000000000) == -1
            || ((1 << (v13 & 0x1F)) & this->m_Conditions.m_Ints[v13 >> 5]) == 0 )
          {
            this->OnConditionSet(this, a2: 32);
          }
          this->m_Conditions.m_Ints[v10 >> 5] |= 1 << (v10 & 0x1F);
        }
      }
      this->m_flLastSawPlayerTime = gpGlobals->curtime;
    }
    a2 = i;
    relation = ((int (__thiscall *)(CAI_BaseNPC *))this->IRelationType)(a1: this);
    if ( relation != D_NU )
    {
      if ( i == this->GetEnemy_2(this) )
      {
        v14 = this->GetClassScheduleIdSpace(this);
        v15 = CAI_LocalIdSpace::LocalToGlobal(this: &v14->m_ConditionIds, localID: 10);
        if ( v15 != -1 )
        {
          v16 = v15 - 1000000000;
          if ( v15 != 999999999 )
          {
            v17 = this->GetClassScheduleIdSpace(this);
            v18 = CAI_LocalIdSpace::LocalToGlobal(this: &v17->m_ConditionIds, localID: 10);
            if ( v18 == -1
              || (v19 = v18 - 1000000000) == -1
              || ((1 << (v19 & 0x1F)) & this->m_Conditions.m_Ints[v19 >> 5]) == 0 )
            {
              this->OnConditionSet(this, a2: 10);
            }
            this->m_Conditions.m_Ints[v16 >> 5] |= 1 << (v16 & 0x1F);
          }
        }
      }
      switch ( relation )
      {
        case D_HT:
          v20 = ((int (__thiscall *)(CAI_BaseNPC *, CBaseEntity *, CBaseEntity *))this->IRelationPriority)(
                  a1: this,
                  a2: i,
                  a3: i);
          if ( v20 >= 0 )
          {
            if ( v20 <= 10 )
              CAI_BaseNPC::SetCondition(this, iCondition: 7);
            else
              CAI_BaseNPC::SetCondition(this, iCondition: 34);
          }
          else
          {
            v21 = this->GetClassScheduleIdSpace(this);
            v22 = CAI_LocalIdSpace::LocalToGlobal(this: &v21->m_ConditionIds, localID: 9);
            if ( v22 != -1 )
            {
              v23 = v22 - 1000000000;
              if ( v22 != 999999999 )
              {
                v24 = this->GetClassScheduleIdSpace(this);
                v25 = CAI_LocalIdSpace::LocalToGlobal(this: &v24->m_ConditionIds, localID: 9);
                if ( v25 == -1
                  || (v26 = v25 - 1000000000) == -1
                  || ((1 << (v26 & 0x1F)) & this->m_Conditions.m_Ints[v26 >> 5]) == 0 )
                {
                  this->OnConditionSet(this, a2: 9);
                }
                this->m_Conditions.m_Ints[v23 >> 5] |= 1 << (v23 & 0x1F);
              }
            }
          }
          if ( (i->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: i);
          a2 = nullptr;
          ((void (__thiscall *)(CAI_BaseNPC *, CBaseEntity *, Vector *))this->UpdateEnemyMemory)(
            a1: this,
            a2: i,
            a3: &i->m_vecAbsOrigin);
          break;
        case D_FR:
          if ( (i->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: i);
          this->UpdateEnemyMemory(this, a2: i, a3: &i->m_vecAbsOrigin, a4: nullptr);
          v27 = this->GetClassScheduleIdSpace(this);
          v28 = CAI_LocalIdSpace::LocalToGlobal(this: &v27->m_ConditionIds, localID: 8);
          if ( v28 != -1 )
          {
            v29 = v28 - 1000000000;
            if ( v28 != 999999999 )
            {
              v30 = this->GetClassScheduleIdSpace(this);
              v31 = CAI_LocalIdSpace::LocalToGlobal(this: &v30->m_ConditionIds, localID: 8);
              if ( v31 == -1
                || (v32 = v31 - 1000000000) == -1
                || ((1 << (v32 & 0x1F)) & this->m_Conditions.m_Ints[v32 >> 5]) == 0 )
              {
                this->OnConditionSet(this, a2: 8);
              }
              this->m_Conditions.m_Ints[v29 >> 5] |= 1 << (v29 & 0x1F);
            }
          }
          break;
        case D_LI:
        case D_NU:
          continue;
        default:
          pszValue = i->m_iClassname.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          v44 = pszValue;
          Classname = CBaseEntity::GetClassname(this);
          _DevWarning(a1: 2, a2: "%s can't assess %s\n", Classname, v44);
          break;
      }
    }
  }
  if ( bHadSeePlayer )
  {
    v35 = this->GetClassScheduleIdSpace(this);
    v36 = CAI_LocalIdSpace::LocalToGlobal(this: &v35->m_ConditionIds, localID: 32);
    if ( v36 == -1 || (v37 = v36 - 1000000000) == -1 || ((1 << (v37 & 0x1F)) & this->m_Conditions.m_Ints[v37 >> 5]) == 0 )
    {
      v38 = this->GetClassScheduleIdSpace(this);
      v39 = CAI_LocalIdSpace::LocalToGlobal(this: &v38->m_ConditionIds, localID: 33);
      if ( v39 != -1 )
      {
        v40 = v39 - 1000000000;
        if ( v39 != 999999999 )
        {
          v41 = this->GetClassScheduleIdSpace(this);
          v42 = CAI_LocalIdSpace::LocalToGlobal(this: &v41->m_ConditionIds, localID: 33);
          if ( v42 == -1
            || (v43 = v42 - 1000000000) == -1
            || ((1 << (v43 & 0x1F)) & this->m_Conditions.m_Ints[v43 >> 5]) == 0 )
          {
            this->OnConditionSet(this, a2: 33);
          }
          this->m_Conditions.m_Ints[v40 >> 5] |= 1 << (v40 & 0x1F);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025490
// Name: public: virtual void CAI_BaseNPC::OnListened(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnListened(CAI_BaseNPC *this)
{
  CSound *FirstHeardSound; // edi
  unsigned int v3; // eax
  int v4; // edi
  const char *Classname; // eax
  CAI_ClassScheduleIdSpace *v6; // eax
  int v7; // eax
  int v8; // ebx
  CAI_ClassScheduleIdSpace *v9; // eax
  int v10; // eax
  int v11; // eax
  CAI_ClassScheduleIdSpace *v12; // eax
  int v13; // eax
  int v14; // eax
  CAI_ClassScheduleIdSpace *v15; // eax
  int v16; // eax
  int v17; // edi
  CAI_ClassScheduleIdSpace *v18; // eax
  int v19; // eax
  int v20; // eax
  CAI_ClassScheduleIdSpace *v21; // eax
  int v22; // eax
  int v23; // eax
  CAI_ClassScheduleIdSpace *v24; // eax
  int v25; // eax
  int v26; // eax
  CAI_ClassScheduleIdSpace *v27; // eax
  int v28; // eax
  int v29; // eax
  CAI_ClassScheduleIdSpace *v30; // eax
  int v31; // eax
  int v32; // eax
  CAI_ClassScheduleIdSpace *v33; // eax
  int v34; // eax
  int v35; // eax
  int m_iType; // [esp+4h] [ebp-14h]
  AISoundIter_t__ *iter; // [esp+14h] [ebp-4h] BYREF

  CAI_BaseNPC::ClearConditions(this, pConditions: conditionsToClear_1, nConditions: 11);
  FirstHeardSound = CAI_Senses::GetFirstHeardSound(this: this->m_pSenses, pIter: &iter);
  if ( FirstHeardSound != nullptr )
  {
    while ( 1 )
    {
      if ( !CSound::FIsSound(this: FirstHeardSound) )
      {
        v4 = 37;
        goto LABEL_24;
      }
      v3 = FirstHeardSound->m_iType & 0xFFFFF;
      if ( v3 <= 0x100 )
      {
        if ( v3 == 256 )
        {
          v4 = 51;
        }
        else
        {
          switch ( v3 )
          {
            case 1u:
              v4 = FirstHeardSound->m_ownerChannelIndex != 8 ? 53 : 59;
              goto LABEL_24;
            case 2u:
              v4 = 54;
              goto LABEL_24;
            case 4u:
              goto $LN14_0;
            case 8u:
              if ( gpGlobals->curtime <= this->m_flIgnoreDangerSoundsUntil )
                goto LABEL_31;
              v4 = 50;
              break;
            case 0x10u:
              v4 = 56;
              goto LABEL_24;
            default:
              goto LABEL_21;
          }
        }
        goto LABEL_24;
      }
      if ( (FirstHeardSound->m_iType & 0xFFFFFu) > 0x800 )
        break;
      if ( v3 != 2048 )
      {
        if ( v3 == 512 )
        {
          v4 = 52;
          goto LABEL_24;
        }
        if ( v3 == 1024 )
        {
          v4 = 57;
          goto LABEL_24;
        }
LABEL_21:
        m_iType = FirstHeardSound->m_iType;
        Classname = CBaseEntity::GetClassname(this);
        DevMsg(a1: "**ERROR: NPC %s hearing sound of unknown type %d!\n", Classname, m_iType);
      }
LABEL_31:
      FirstHeardSound = CAI_Senses::GetNextHeardSound(this: this->m_pSenses, pIter: &iter);
      if ( FirstHeardSound == nullptr )
        goto LABEL_32;
    }
    if ( v3 == 4096 )
    {
      v4 = 58;
      goto LABEL_24;
    }
    if ( v3 == 0x2000 )
    {
$LN14_0:
      v4 = 55;
LABEL_24:
      v6 = this->GetClassScheduleIdSpace(this);
      v7 = CAI_LocalIdSpace::LocalToGlobal(this: &v6->m_ConditionIds, localID: v4);
      if ( v7 != -1 )
      {
        v8 = v7 - 1000000000;
        if ( v7 != 999999999 )
        {
          v9 = this->GetClassScheduleIdSpace(this);
          v10 = CAI_LocalIdSpace::LocalToGlobal(this: &v9->m_ConditionIds, localID: v4);
          if ( v10 == -1
            || (v11 = v10 - 1000000000) == -1
            || ((1 << (v11 & 0x1F)) & this->m_Conditions.m_Ints[v11 >> 5]) == 0 )
          {
            this->OnConditionSet(this, a2: v4);
          }
          this->m_Conditions.m_Ints[v8 >> 5] |= 1 << (v8 & 0x1F);
        }
      }
      goto LABEL_31;
    }
    goto LABEL_21;
  }
LABEL_32:
  v12 = this->GetClassScheduleIdSpace(this);
  v13 = CAI_LocalIdSpace::LocalToGlobal(this: &v12->m_ConditionIds, localID: 50);
  if ( v13 == -1 || (v14 = v13 - 1000000000) == -1 || ((1 << (v14 & 0x1F)) & this->m_Conditions.m_Ints[v14 >> 5]) == 0 )
  {
    v15 = this->GetClassScheduleIdSpace(this);
    v16 = CAI_LocalIdSpace::LocalToGlobal(this: &v15->m_ConditionIds, localID: 60);
    if ( v16 != -1 )
    {
      v17 = v16 - 1000000000;
      if ( v16 != 999999999 )
      {
        v18 = this->GetClassScheduleIdSpace(this);
        v19 = CAI_LocalIdSpace::LocalToGlobal(this: &v18->m_ConditionIds, localID: 60);
        if ( v19 == -1
          || (v20 = v19 - 1000000000) == -1
          || ((1 << (v20 & 0x1F)) & this->m_Conditions.m_Ints[v20 >> 5]) == 0 )
        {
          this->OnConditionSet(this, a2: 60);
        }
        this->m_Conditions.m_Ints[v17 >> 5] |= 1 << (v17 & 0x1F);
      }
    }
  }
  v21 = this->GetClassScheduleIdSpace(this);
  v22 = CAI_LocalIdSpace::LocalToGlobal(this: &v21->m_ConditionIds, localID: 54);
  if ( v22 != -1 )
  {
    v23 = v22 - 1000000000;
    if ( v23 != -1 && ((1 << (v23 & 0x1F)) & this->m_Conditions.m_Ints[v23 >> 5]) != 0 )
      COutputEvent::FireOutput(this: &this->m_OnHearWorld, pActivator: this, pCaller: this, fDelay: 0.0);
  }
  v24 = this->GetClassScheduleIdSpace(this);
  v25 = CAI_LocalIdSpace::LocalToGlobal(this: &v24->m_ConditionIds, localID: 55);
  if ( v25 != -1 )
  {
    v26 = v25 - 1000000000;
    if ( v26 != -1 && ((1 << (v26 & 0x1F)) & this->m_Conditions.m_Ints[v26 >> 5]) != 0 )
      COutputEvent::FireOutput(this: &this->m_OnHearPlayer, pActivator: this, pCaller: this, fDelay: 0.0);
  }
  v27 = this->GetClassScheduleIdSpace(this);
  v28 = CAI_LocalIdSpace::LocalToGlobal(this: &v27->m_ConditionIds, localID: 53);
  if ( v28 != -1 && (v29 = v28 - 1000000000) != -1 && ((1 << (v29 & 0x1F)) & this->m_Conditions.m_Ints[v29 >> 5]) != 0
    || (v30 = this->GetClassScheduleIdSpace(this),
        (v31 = CAI_LocalIdSpace::LocalToGlobal(this: &v30->m_ConditionIds, localID: 56)) != -1)
    && (v32 = v31 - 1000000000) != -1
    && ((1 << (v32 & 0x1F)) & this->m_Conditions.m_Ints[v32 >> 5]) != 0
    || (v33 = this->GetClassScheduleIdSpace(this),
        (v34 = CAI_LocalIdSpace::LocalToGlobal(this: &v33->m_ConditionIds, localID: 50)) != -1)
    && (v35 = v34 - 1000000000) != -1
    && ((1 << (v35 & 0x1F)) & this->m_Conditions.m_Ints[v35 >> 5]) != 0 )
  {
    COutputEvent::FireOutput(this: &this->m_OnHearCombat, pActivator: this, pCaller: this, fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025900
// Name: private: void CAI_BaseNPC::TryRestoreHull(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::TryRestoreHull(CAI_BaseNPC *this)
{
  float z; // ecx
  Hull_t m_eHull; // eax
  const Vector *v4; // ebx
  const Vector *v5; // eax
  unsigned int v6; // edx
  const Vector *v7; // eax
  const Vector *v8; // eax
  bool v9; // zf
  Hull_t v10; // [esp-8h] [ebp-7Ch]
  CGameTrace tr; // [esp+4h] [ebp-70h] BYREF
  Vector vecMin; // [esp+58h] [ebp-1Ch] BYREF
  Vector vUpBit; // [esp+64h] [ebp-10h] BYREF
  const Vector *hullMin; // [esp+70h] [ebp-4h]
  IHandleEntity savedregs; // [esp+74h] [ebp+0h] BYREF

  if ( this->m_fIsUsingSmallHull && this->m_pSchedule != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    z = this->m_vecAbsOrigin.z;
    m_eHull = this->m_eHull;
    *(_QWORD *)&vUpBit.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    vUpBit.z = z + 1.0;
    v4 = NAI_Hull::Maxs(id: m_eHull);
    v5 = NAI_Hull::Mins(id: this->m_eHull);
    v6 = (unsigned int)this->m_iEFlags >> 11;
    hullMin = v5;
    if ( (v6 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    UTIL_TraceHull(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &this->m_vecAbsOrigin,
      vecAbsEnd: &vUpBit,
      hullMin,
      hullMax: v4,
      mask: 0x200400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    if ( !tr.startsolid && tr.fraction == 1.0 && this->m_fIsUsingSmallHull )
    {
      if ( CBaseAnimating::GetModelHierarchyScale(this) <= 1.0 )
        *(float *)&hullMin = CBaseAnimating::GetModelHierarchyScale(this);
      else
        *(float *)&hullMin = 1.0;
      v7 = NAI_Hull::Mins(id: this->m_eHull);
      vecMin.x = v7->x * *(float *)&hullMin;
      vecMin.y = v7->y * *(float *)&hullMin;
      v10 = this->m_eHull;
      vecMin.z = v7->z * *(float *)&hullMin;
      v8 = NAI_Hull::Maxs(id: v10);
      vUpBit.x = v8->x * *(float *)&hullMin;
      vUpBit.y = v8->y * *(float *)&hullMin;
      vUpBit.z = v8->z * *(float *)&hullMin;
      UTIL_SetSize(pEnt: this, &vecMin, vecMax: &vUpBit);
      v9 = this->m_pPhysicsObject == nullptr;
      this->m_fIsUsingSmallHull = false;
      if ( !v9 )
        CAI_BaseNPC::SetupVPhysicsHull(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025AC0
// Name: private: bool CAI_BaseNPC::PreThink(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::PreThink(CAI_BaseNPC *this)
{
  edict_t *v2; // ecx
  edict_t *m_pPev; // ecx
  hudtextparms_s tTextParam; // [esp+4h] [ebp-28h] BYREF

  if ( (CAI_BaseNPC::m_nDebugBits & 1) != 0 || !CAI_NetworkManager::gm_fNetworksLoaded )
  {
    if ( gpGlobals->curtime >= g_AINextDisabledMessageTime && !IsInCommentaryMode() )
    {
      g_AINextDisabledMessageTime = gpGlobals->curtime + 0.5;
      strcpy((char *)&tTextParam, "333?ff&?");
      BYTE1(tTextParam.effect) = 0;
      HIWORD(tTextParam.effect) = 0;
      *(_DWORD *)&tTextParam.r1 = -1;
      *(_DWORD *)&tTextParam.r2 = -1;
      tTextParam.fadeinTime = 0.0;
      tTextParam.fadeoutTime = 0.0;
      tTextParam.holdTime = 0.60000002;
      tTextParam.fxTime = 0.0;
      tTextParam.channel = 1;
      UTIL_HudMessageAll(textparms: &tTextParam, pMessage: "A.I. Disabled...\n");
    }
    this->SetActivity(this, a2: ACT_IDLE);
    return 0;
  }
  if ( (CAI_BaseNPC::m_nDebugBits & 2) == 0 )
    return 1;
  if ( this->m_nDebugCurIndex < CAI_BaseNPC::m_nDebugPauseIndex )
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
    return 1;
  }
  if ( CAI_Navigator::IsGoalActive(this: this->m_pNavigator) || this->m_flPlaybackRate.m_Value == 0.0 )
    return 0;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v2 = this->m_Network.m_pPev;
    if ( v2 != nullptr )
      CBaseEdict::StateChanged(this: &v2->CBaseEdict, offset: 0x37Cu);
  }
  this->m_flPlaybackRate.m_Value = 0.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10025C70
// Name: public: virtual void CAI_BaseNPC::UpdateSleepState(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::UpdateSleepState(CAI_BaseNPC *this, bool bInPVS)
{
  CBasePlayer *LocalPlayer; // eax
  CBaseEntity *v4; // edi
  AI_SleepState_t m_SleepState; // eax
  int i; // edi
  CBasePlayer *v7; // eax
  int active; // eax
  CSound *v9; // eax
  CSound *v10; // edi

  if ( this->m_SleepState <= AISS_AWAKE )
  {
    if ( !this->m_bInAScript && this->m_NPCState != NPC_STATE_SCRIPT )
    {
      if ( (this->m_SleepFlags & 1) != 0 && !CAI_BaseNPC::HasCondition(this, iCondition: 1) )
      {
        this->m_SleepState = AISS_WAITING_FOR_PVS;
        CAI_BaseNPC::Sleep(this);
      }
      if ( (this->m_SleepFlags & 2) != 0 && CAI_BaseNPC::HasCondition(this, iCondition: 1) )
        this->m_SleepFlags = this->m_SleepFlags & 0xFFFFFFFC | 1;
    }
  }
  else
  {
    if ( gpGlobals->maxClients > 1 || (LocalPlayer = UTIL_GetLocalPlayer(), v4 = LocalPlayer, LocalPlayer == nullptr) )
    {
      if ( gpGlobals->maxClients <= 1 )
      {
        _Warning(a1: "CAI_BaseNPC::UpdateSleepState called with NULL pLocalPlayer\n");
        return;
      }
      goto LABEL_15;
    }
    if ( this->m_flWakeRadius > 0.1 && (LocalPlayer->m_fFlags.m_Value & 0x10000) == 0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      if ( (v4->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v4);
      if ( (float)(this->m_flWakeRadius * this->m_flWakeRadius) >= (float)((float)((float)((float)(v4->m_vecAbsOrigin.y
                                                                                                 - this->m_vecAbsOrigin.y)
                                                                                         * (float)(v4->m_vecAbsOrigin.y
                                                                                                 - this->m_vecAbsOrigin.y))
                                                                                 + (float)((float)(v4->m_vecAbsOrigin.x
                                                                                                 - this->m_vecAbsOrigin.x)
                                                                                         * (float)(v4->m_vecAbsOrigin.x
                                                                                                 - this->m_vecAbsOrigin.x)))
                                                                         + (float)((float)(v4->m_vecAbsOrigin.z
                                                                                         - this->m_vecAbsOrigin.z)
                                                                                 * (float)(v4->m_vecAbsOrigin.z
                                                                                         - this->m_vecAbsOrigin.z))) )
      {
LABEL_15:
        this->Wake(this, a2: true);
        return;
      }
    }
    m_SleepState = this->m_SleepState;
    if ( m_SleepState == AISS_WAITING_FOR_PVS )
    {
      if ( bInPVS )
        goto LABEL_15;
    }
    else if ( m_SleepState == AISS_WAITING_FOR_THREAT )
    {
      if ( CAI_BaseNPC::HasCondition(this, iCondition: 17) || CAI_BaseNPC::HasCondition(this, iCondition: 18) )
        goto LABEL_15;
      if ( bInPVS )
      {
        for ( i = 1; i <= gpGlobals->maxClients; ++i )
        {
          v7 = UTIL_PlayerByIndex(playerIndex: i);
          if ( v7 != nullptr
            && (v7->m_fFlags.m_Value & 0x10000) == 0
            && v7->FVisible_2(this: v7, a2: this, a3: 16449, a4: nullptr) )
          {
            this->Wake(this, a2: true);
          }
        }
      }
      if ( (this->GetSoundInterests(this) & 8) != 0 && (this->m_spawnflags.m_Value & 1) == 0 )
      {
        active = CSoundEnt::ActiveList();
        if ( active != -1 )
        {
          while ( 1 )
          {
            v9 = CSoundEnt::SoundPointerForIndex(iIndex: active);
            v10 = v9;
            if ( (v9->m_iType & 8) != 0
              && CAI_Senses::CanHearSound(this: this->m_pSenses, pSound: v9)
              && CAI_BaseNPC::SoundIsVisible(this, pSound: v10) )
            {
              break;
            }
            active = v10->m_iNext;
            if ( active == -1 )
              return;
          }
          this->Wake(this, a2: true);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025F10
// Name: protected: virtual bool CAI_BaseNPC::CheckPVSCondition(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::CheckPVSCondition(CAI_BaseNPC *this)
{
  char v2; // bl
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax
  int v5; // edi
  CAI_ClassScheduleIdSpace *v6; // eax
  int v7; // eax
  int v8; // eax
  CAI_ClassScheduleIdSpace *v10; // eax
  int v11; // eax
  int v12; // edi
  CAI_ClassScheduleIdSpace *v13; // eax
  int v14; // eax
  int v15; // eax

  if ( UTIL_FindClientInPVS(pEdict: this->m_Network.m_pPev) == nullptr
    && (!UTIL_ClientPVSIsExpanded() || UTIL_FindClientInVisibilityPVS(pEdict: this->m_Network.m_pPev) == nullptr) )
  {
    v2 = 0;
    v3 = this->GetClassScheduleIdSpace(this);
    v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: 1);
    if ( v4 != -1 )
    {
      v5 = v4 - 1000000000;
      if ( v4 != 999999999 )
      {
        v6 = this->GetClassScheduleIdSpace(this);
        v7 = CAI_LocalIdSpace::LocalToGlobal(this: &v6->m_ConditionIds, localID: 1);
        if ( v7 != -1 )
        {
          v8 = v7 - 1000000000;
          if ( v8 != -1 && ((1 << (v8 & 0x1F)) & this->m_Conditions.m_Ints[v8 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 1);
        }
        this->m_Conditions.m_Ints[v5 >> 5] &= ~(1 << (v5 & 0x1F));
      }
    }
    return v2;
  }
  v2 = 1;
  v10 = this->GetClassScheduleIdSpace(this);
  v11 = CAI_LocalIdSpace::LocalToGlobal(this: &v10->m_ConditionIds, localID: 1);
  if ( v11 == -1 )
    return v2;
  v12 = v11 - 1000000000;
  if ( v11 == 999999999 )
    return v2;
  v13 = this->GetClassScheduleIdSpace(this);
  v14 = CAI_LocalIdSpace::LocalToGlobal(this: &v13->m_ConditionIds, localID: 1);
  if ( v14 == -1 || (v15 = v14 - 1000000000) == -1 || ((1 << (v15 & 0x1F)) & this->m_Conditions.m_Ints[v15 >> 5]) == 0 )
    this->OnConditionSet(this, a2: 1);
  this->m_Conditions.m_Ints[v12 >> 5] |= 1 << (v12 & 0x1F);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026080
// Name: public: virtual void CAI_BaseNPC::RemoveIgnoredConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RemoveIgnoredConditions(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx
  int v2; // eax
  CEntInfo *v3; // edx
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CAI_ScriptedSequence **v7; // eax

  this->m_ConditionsPreIgnore = this->m_Conditions;
  this->m_Conditions.m_Ints[0] &= this->m_InverseIgnoreConditions.m_Ints[0];
  this->m_Conditions.m_Ints[1] &= this->m_InverseIgnoreConditions.m_Ints[1];
  this->m_Conditions.m_Ints[2] &= this->m_InverseIgnoreConditions.m_Ints[2];
  this->m_Conditions.m_Ints[3] &= this->m_InverseIgnoreConditions.m_Ints[3];
  this->m_Conditions.m_Ints[4] &= this->m_InverseIgnoreConditions.m_Ints[4];
  this->m_Conditions.m_Ints[5] &= this->m_InverseIgnoreConditions.m_Ints[5];
  this->m_Conditions.m_Ints[6] &= this->m_InverseIgnoreConditions.m_Ints[6];
  this->m_Conditions.m_Ints[7] &= this->m_InverseIgnoreConditions.m_Ints[7];
  if ( this->m_NPCState == NPC_STATE_SCRIPT )
  {
    m_Index = this->m_hCine.m_Index;
    if ( m_Index != -1 )
    {
      v2 = (unsigned __int16)m_Index;
      v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v4 = HIWORD(m_Index);
      if ( v3->m_SerialNumber == v4 && v3->m_pEntity != nullptr )
      {
        v5 = v2;
        v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4;
        v7 = (CAI_ScriptedSequence **)&g_pEntityList->m_EntPtrArray[v5];
        if ( v6 )
          CAI_ScriptedSequence::RemoveIgnoredConditions(this: *v7);
        else
          CAI_ScriptedSequence::RemoveIgnoredConditions(this: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100261D0
// Name: public: void CAI_BaseNPC::GatherAttackConditions(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::GatherAttackConditions(CAI_BaseNPC *this, CBaseEntity *pTarget, float flDist)
{
  int (__thiscall *CapabilitiesGet)(CAI_BaseNPC *); // edx
  Vector *v6; // eax
  bool (__thiscall *CurrentWeaponLOSCondition)(CAI_BaseNPC *, const Vector *, bool); // edx
  CAI_BaseNPC_vtbl *v8; // eax
  Vector *v9; // eax
  bool (__thiscall *v10)(CAI_BaseNPC *, const Vector *, bool); // edx
  bool v11; // bl
  int v12; // eax
  int v13; // eax
  int v14; // edi
  CAI_ClassScheduleIdSpace *v15; // eax
  int v16; // eax
  int v17; // eax
  CAI_ClassScheduleIdSpace *v18; // eax
  int v19; // eax
  int v20; // edi
  CAI_ClassScheduleIdSpace *v21; // eax
  int v22; // eax
  int v23; // eax
  DesiredWeaponState_t m_iDesiredWeaponState; // eax
  int v25; // edi
  CBaseCombatWeapon *ActiveWeapon; // eax
  int v27; // eax
  int v28; // edi
  CBaseCombatWeapon *v29; // eax
  CAI_BaseNPC *v30; // ecx
  int (__thiscall *SelectFailSchedule)(CAI_BaseNPC *, float, float); // eax
  int v32; // eax
  int v33; // eax
  CAI_BaseNPC *v34; // ecx
  int (__thiscall *TranslateSchedule)(CAI_BaseNPC *, float, float); // eax
  int v36; // eax
  CAI_BaseNPC *v37; // ecx
  int (__thiscall *StartTask)(CAI_BaseNPC *, float, float); // eax
  int v39; // eax
  CAI_ClassScheduleIdSpace *v40; // eax
  int v41; // eax
  int v42; // eax
  CAI_ClassScheduleIdSpace *v43; // eax
  int v44; // eax
  int v45; // eax
  CAI_ClassScheduleIdSpace *v46; // eax
  int v47; // eax
  int v48; // eax
  CAI_ClassScheduleIdSpace *v49; // eax
  int v50; // eax
  int v51; // edi
  CAI_ClassScheduleIdSpace *v52; // eax
  int v53; // eax
  int v54; // eax
  CAI_ClassScheduleIdSpace *v55; // eax
  int v56; // eax
  int v57; // edi
  CAI_ClassScheduleIdSpace *v58; // eax
  int v59; // eax
  int v60; // eax
  CAI_ClassScheduleIdSpace *v61; // eax
  int v62; // eax
  int v63; // edi
  CAI_ClassScheduleIdSpace *v64; // eax
  int v65; // eax
  int v66; // eax
  _BYTE v67[12]; // [esp+40h] [ebp-38h] BYREF
  Vector vBodyDir; // [esp+4Ch] [ebp-2Ch] BYREF
  Vector vecLOS; // [esp+58h] [ebp-20h] BYREF
  Vector targetPos; // [esp+64h] [ebp-14h] BYREF
  int capability; // [esp+70h] [ebp-8h]
  float flDot; // [esp+74h] [ebp-4h]
  bool bWeaponIsReady_3; // [esp+83h] [ebp+Bh]
  char bWeaponIsReady_3a; // [esp+83h] [ebp+Bh]

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  if ( (pTarget->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pTarget);
  vecLOS.x = pTarget->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
  vecLOS.y = pTarget->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
  vecLOS.z = 0.0;
  VectorNormalize(vec: &vecLOS);
  this->BodyDirection2D(this, result: &vBodyDir);
  CapabilitiesGet = this->CapabilitiesGet;
  flDot = (float)((float)(vBodyDir.y * vecLOS.y) + (float)(vecLOS.x * vBodyDir.x)) + (float)(vBodyDir.z * vecLOS.z);
  capability = CapabilitiesGet(this);
  this->ClearAttackConditions(this);
  v6 = pTarget->EyePosition(this: pTarget, result: v67);
  targetPos.x = v6->x;
  targetPos.y = v6->y;
  CurrentWeaponLOSCondition = this->CurrentWeaponLOSCondition;
  targetPos.z = v6->z;
  bWeaponIsReady_3 = CurrentWeaponLOSCondition(this, a2: &targetPos, a3: true);
  v8 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( bWeaponIsReady_3 )
  {
    v12 = (int)v8->GetClassScheduleIdSpace(this);
    v13 = CAI_LocalIdSpace::LocalToGlobal(this: (CAI_LocalIdSpace *)(v12 + 52), localID: 41);
    if ( v13 != -1 )
    {
      v14 = v13 - 1000000000;
      if ( v13 != 999999999 )
      {
        v15 = this->GetClassScheduleIdSpace(this);
        v16 = CAI_LocalIdSpace::LocalToGlobal(this: &v15->m_ConditionIds, localID: 41);
        if ( v16 == -1
          || (v17 = v16 - 1000000000) == -1
          || ((1 << (v17 & 0x1F)) & this->m_Conditions.m_Ints[v17 >> 5]) == 0 )
        {
          this->OnConditionSet(this, a2: 41);
        }
        this->m_Conditions.m_Ints[v14 >> 5] |= 1 << (v14 & 0x1F);
      }
    }
    v11 = bWeaponIsReady_3;
  }
  else
  {
    v8->ClearAttackConditions(this);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    v9 = pTarget->BodyTarget(this: pTarget, result: v67, a3: &this->m_vecAbsOrigin, a4: 1);
    targetPos.x = v9->x;
    targetPos.y = v9->y;
    v10 = this->CurrentWeaponLOSCondition;
    targetPos.z = v9->z;
    v11 = v10(this, a2: &targetPos, a3: true);
  }
  if ( this->IsAttackFrozen(this) )
  {
    v18 = this->GetClassScheduleIdSpace(this);
    v19 = CAI_LocalIdSpace::LocalToGlobal(this: &v18->m_ConditionIds, localID: 38);
    if ( v19 != -1 )
    {
      v20 = v19 - 1000000000;
      if ( v19 != 999999999 )
      {
        v21 = this->GetClassScheduleIdSpace(this);
        v22 = CAI_LocalIdSpace::LocalToGlobal(this: &v21->m_ConditionIds, localID: 38);
        if ( v22 == -1
          || (v23 = v22 - 1000000000) == -1
          || ((1 << (v23 & 0x1F)) & this->m_Conditions.m_Ints[v23 >> 5]) == 0 )
        {
          this->OnConditionSet(this, a2: 38);
        }
        this->m_Conditions.m_Ints[v20 >> 5] |= 1 << (v20 & 0x1F);
      }
    }
    return;
  }
  if ( CBaseCombatCharacter::GetActiveWeapon(this) == nullptr
    || (m_iDesiredWeaponState = this->m_iDesiredWeaponState) == DESIREDWEAPONSTATE_CHANGING
    || (bWeaponIsReady_3a = 1, m_iDesiredWeaponState == DESIREDWEAPONSTATE_CHANGING_DESTROY) )
  {
    bWeaponIsReady_3a = 0;
  }
  v25 = capability;
  if ( (capability & 0x2000) != 0 && bWeaponIsReady_3a != 0 )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    v27 = ((int (__thiscall *)(CBaseCombatWeapon *, float, _DWORD))ActiveWeapon->WeaponRangeAttack1Condition)(
            a1: ActiveWeapon,
            a2: COERCE_FLOAT(LODWORD(flDot)),
            a3: LODWORD(flDist));
    v28 = v27;
    if ( v27 == 40 )
    {
      if ( this->FInAimCone(this, a2: &targetPos) )
        DevMsg(a1: "Warning: COND_NOT_FACING_ATTACK set but FInAimCone is true\n");
    }
    else if ( v27 == 21 && !v11 )
    {
      goto LABEL_37;
    }
    CAI_BaseNPC::SetCondition(this, iCondition: v28);
LABEL_37:
    v25 = capability;
    goto LABEL_38;
  }
  if ( (capability & 0x20000) != 0 )
  {
    v32 = ((int (__thiscall *)(CAI_BaseNPC *, _DWORD, _DWORD))this->RangeAttack1Conditions)(
            a1: this,
            a2: LODWORD(flDot),
            a3: LODWORD(flDist));
    if ( v32 != 21 || v11 )
      CAI_BaseNPC::SetCondition(this, iCondition: v32);
  }
LABEL_38:
  if ( (v25 & 0x4000) != 0
    && bWeaponIsReady_3a != 0
    && (v29 = CBaseCombatCharacter::GetActiveWeapon(this), (v29->CapabilitiesGet(this: v29) & 0x4000) != 0) )
  {
    v30 = (CAI_BaseNPC *)CBaseCombatCharacter::GetActiveWeapon(this);
    SelectFailSchedule = (int (__thiscall *)(CAI_BaseNPC *, float, float))v30->SelectFailSchedule;
  }
  else
  {
    if ( (v25 & 0x40000) == 0 )
      goto LABEL_51;
    SelectFailSchedule = this->RangeAttack2Conditions;
    v30 = this;
  }
  v33 = ((int (__thiscall *)(CAI_BaseNPC *, _DWORD, _DWORD))SelectFailSchedule)(
          a1: v30,
          a2: LODWORD(flDot),
          a3: LODWORD(flDist));
  if ( v33 != 22 || v11 )
    CAI_BaseNPC::SetCondition(this, iCondition: v33);
LABEL_51:
  if ( (v25 & 0x8000) != 0 && bWeaponIsReady_3a != 0 )
  {
    v34 = (CAI_BaseNPC *)CBaseCombatCharacter::GetActiveWeapon(this);
    TranslateSchedule = (int (__thiscall *)(CAI_BaseNPC *, float, float))v34->TranslateSchedule;
LABEL_56:
    v36 = ((int (__thiscall *)(CAI_BaseNPC *, _DWORD, _DWORD))TranslateSchedule)(
            a1: v34,
            a2: LODWORD(flDot),
            a3: LODWORD(flDist));
    CAI_BaseNPC::SetCondition(this, iCondition: v36);
    goto LABEL_57;
  }
  if ( (v25 & 0x80000) != 0 )
  {
    TranslateSchedule = this->MeleeAttack1Conditions;
    v34 = this;
    goto LABEL_56;
  }
LABEL_57:
  if ( (v25 & 0x10000) != 0 && bWeaponIsReady_3a != 0 )
  {
    v37 = (CAI_BaseNPC *)CBaseCombatCharacter::GetActiveWeapon(this);
    StartTask = (int (__thiscall *)(CAI_BaseNPC *, float, float))v37->StartTask;
  }
  else
  {
    if ( (v25 & 0x100000) == 0 )
      goto LABEL_63;
    StartTask = this->MeleeAttack2Conditions;
    v37 = this;
  }
  v39 = ((int (__thiscall *)(CAI_BaseNPC *, _DWORD, _DWORD))StartTask)(a1: v37, a2: LODWORD(flDot), a3: LODWORD(flDist));
  CAI_BaseNPC::SetCondition(this, iCondition: v39);
LABEL_63:
  v40 = this->GetClassScheduleIdSpace(this);
  v41 = CAI_LocalIdSpace::LocalToGlobal(this: &v40->m_ConditionIds, localID: 22);
  if ( v41 != -1 && (v42 = v41 - 1000000000) != -1 && ((1 << (v42 & 0x1F)) & this->m_Conditions.m_Ints[v42 >> 5]) != 0
    || (v43 = this->GetClassScheduleIdSpace(this),
        (v44 = CAI_LocalIdSpace::LocalToGlobal(this: &v43->m_ConditionIds, localID: 21)) != -1)
    && (v45 = v44 - 1000000000) != -1
    && ((1 << (v45 & 0x1F)) & this->m_Conditions.m_Ints[v45 >> 5]) != 0
    || (v46 = this->GetClassScheduleIdSpace(this),
        (v47 = CAI_LocalIdSpace::LocalToGlobal(this: &v46->m_ConditionIds, localID: 24)) != -1)
    && (v48 = v47 - 1000000000) != -1
    && ((1 << (v48 & 0x1F)) & this->m_Conditions.m_Ints[v48 >> 5]) != 0
    || CAI_BaseNPC::HasCondition(this, iCondition: 23) )
  {
    v49 = this->GetClassScheduleIdSpace(this);
    v50 = CAI_LocalIdSpace::LocalToGlobal(this: &v49->m_ConditionIds, localID: 38);
    if ( v50 != -1 )
    {
      v51 = v50 - 1000000000;
      if ( v50 != 999999999 )
      {
        v52 = this->GetClassScheduleIdSpace(this);
        v53 = CAI_LocalIdSpace::LocalToGlobal(this: &v52->m_ConditionIds, localID: 38);
        if ( v53 != -1 )
        {
          v54 = v53 - 1000000000;
          if ( v54 != -1 && ((1 << (v54 & 0x1F)) & this->m_Conditions.m_Ints[v54 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 38);
        }
        this->m_Conditions.m_Ints[v51 >> 5] &= ~(1 << (v51 & 0x1F));
      }
    }
    v55 = this->GetClassScheduleIdSpace(this);
    v56 = CAI_LocalIdSpace::LocalToGlobal(this: &v55->m_ConditionIds, localID: 39);
    if ( v56 != -1 )
    {
      v57 = v56 - 1000000000;
      if ( v56 != 999999999 )
      {
        v58 = this->GetClassScheduleIdSpace(this);
        v59 = CAI_LocalIdSpace::LocalToGlobal(this: &v58->m_ConditionIds, localID: 39);
        if ( v59 != -1 )
        {
          v60 = v59 - 1000000000;
          if ( v60 != -1 && ((1 << (v60 & 0x1F)) & this->m_Conditions.m_Ints[v60 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 39);
        }
        this->m_Conditions.m_Ints[v57 >> 5] &= ~(1 << (v57 & 0x1F));
      }
    }
    v61 = this->GetClassScheduleIdSpace(this);
    v62 = CAI_LocalIdSpace::LocalToGlobal(this: &v61->m_ConditionIds, localID: 42);
    if ( v62 != -1 )
    {
      v63 = v62 - 1000000000;
      if ( v62 != 999999999 )
      {
        v64 = this->GetClassScheduleIdSpace(this);
        v65 = CAI_LocalIdSpace::LocalToGlobal(this: &v64->m_ConditionIds, localID: 42);
        if ( v65 != -1 )
        {
          v66 = v65 - 1000000000;
          if ( v66 != -1 && ((1 << (v66 & 0x1F)) & this->m_Conditions.m_Ints[v66 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 42);
        }
        this->m_Conditions.m_Ints[v63 >> 5] &= ~(1 << (v63 & 0x1F));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026930
// Name: private: void CAI_BaseNPC::CheckOnGround(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::CheckOnGround(CAI_BaseNPC *this)
{
  unsigned int m_Index; // eax
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax
  int v5; // eax
  unsigned int v6; // eax
  unsigned __int8 m_Value; // al
  const Vector *AbsOrigin; // eax
  Vector *v9; // eax
  unsigned int m_nAITraceMask; // ecx
  CAI_MoveProbe *m_pMoveProbe; // ecx
  IPhysicsObject *m_pPhysicsObject; // ecx
  CBaseEntity *m_pEnt; // ecx
  IPhysicsObject *v14; // ecx
  CBaseEntity *GroundEntity; // eax
  unsigned int v16; // eax
  CAI_ClassScheduleIdSpace *v17; // eax
  int v18; // eax
  int v19; // edi
  CAI_ClassScheduleIdSpace *v20; // eax
  int v21; // eax
  int v22; // eax
  unsigned int v23; // [esp-4h] [ebp-98h]
  CGameTrace trace; // [esp+10h] [ebp-84h] BYREF
  Vector vecStart; // [esp+64h] [ebp-30h] BYREF
  Vector mins; // [esp+70h] [ebp-24h] BYREF
  Vector vecDown; // [esp+7Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+88h] [ebp-Ch] BYREF

  if ( !CAI_BaseNPC::IsCurSchedule(this, schedId: 56, fIdeal: true) )
  {
    m_Index = this->m_hCine.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
      || this->m_scriptState != SCRIPT_WAIT )
    {
      v3 = this->GetClassScheduleIdSpace(this);
      v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: 61);
      if ( v4 == -1 || (v5 = v4 - 1000000000) == -1 || ((1 << (v5 & 0x1F)) & this->m_Conditions.m_Ints[v5 >> 5]) == 0 )
      {
        v6 = this->m_hMoveParent.m_Value.m_Index;
        if ( (v6 == -1
           || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6)
           || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity == nullptr)
          && (this->m_NPCState != NPC_STATE_SCRIPT || (this->m_fFlags.m_Value & 0x800) == 0)
          && this->m_pNavigator->m_navType == NAV_GROUND )
        {
          m_Value = this->m_MoveType.m_Value;
          if ( m_Value != 6 && m_Value != 0 && CSimpleSimTimer::Expired(this: &this->m_CheckOnGroundTimer) )
          {
            this->m_CheckOnGroundTimer.m_next = gpGlobals->curtime + 0.5;
            maxs = *CBaseEntity::ScriptGetBoundingMaxs(this);
            mins = *CBaseEntity::ScriptGetBoundingMins(this);
            if ( Vector::operator!=(this: &mins, src: &maxs) )
            {
              maxs.z = maxs.z - 0.2;
              AbsOrigin = CBaseEntity::GetAbsOrigin(this);
              vecStart.x = AbsOrigin->x;
              vecStart.y = AbsOrigin->y;
              vecStart.z = AbsOrigin->z + 0.1;
              v9 = CBaseEntity::GetAbsOrigin(this);
              m_nAITraceMask = this->m_nAITraceMask;
              vecDown = *v9;
              v23 = m_nAITraceMask;
              m_pMoveProbe = this->m_pMoveProbe;
              vecDown.z = vecDown.z - 4.0;
              CAI_MoveProbe::TraceHull(
                this: m_pMoveProbe,
                &vecStart,
                vecEnd: &vecDown,
                hullMin: &mins,
                hullMax: &maxs,
                mask: v23,
                pResult: &trace);
              if ( trace.fraction == 1.0 )
              {
                CAI_BaseNPC::SetCondition(this, iCondition: 61);
                CBaseEntity::SetGroundEntity(this, ground: nullptr);
              }
              else
              {
                if ( trace.startsolid && trace.m_pEnt->m_MoveType.m_Value == 6 )
                {
                  m_pPhysicsObject = trace.m_pEnt->m_pPhysicsObject;
                  if ( m_pPhysicsObject != nullptr
                    && ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: m_pPhysicsObject) < 500.0 )
                  {
                    m_pEnt = trace.m_pEnt;
                    this->m_CheckOnGroundTimer.m_next = gpGlobals->curtime + 0.1;
                    NPCPhysics_CreateSolver(
                      pNPC: this,
                      pPhysicsObject: m_pEnt,
                      disableCollisions: true,
                      separationDuration: 0.25);
                    v14 = this->m_pPhysicsObject;
                    if ( v14 != nullptr )
                      v14->RecheckContactPoints(this: v14, a2: false);
                  }
                }
                if ( trace.m_pEnt != nullptr )
                {
                  GroundEntity = CBaseEntity::GetGroundEntity(this);
                  if ( trace.m_pEnt != GroundEntity )
                    CBaseEntity::SetGroundEntity(this, ground: trace.m_pEnt);
                }
              }
            }
          }
        }
        return;
      }
      v16 = this->m_hMoveParent.m_Value.m_Index;
      if ( (v16 == -1
         || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16)
         || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity == nullptr)
        && (this->m_fFlags.m_Value & 1) == 0
        && this->m_pNavigator->m_navType == NAV_GROUND )
      {
        return;
      }
    }
  }
  v17 = this->GetClassScheduleIdSpace(this);
  v18 = CAI_LocalIdSpace::LocalToGlobal(this: &v17->m_ConditionIds, localID: 61);
  if ( v18 != -1 )
  {
    v19 = v18 - 1000000000;
    if ( v18 != 999999999 )
    {
      v20 = this->GetClassScheduleIdSpace(this);
      v21 = CAI_LocalIdSpace::LocalToGlobal(this: &v20->m_ConditionIds, localID: 61);
      if ( v21 != -1 )
      {
        v22 = v21 - 1000000000;
        if ( v22 != -1 && ((1 << (v22 & 0x1F)) & this->m_Conditions.m_Ints[v22 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 61);
      }
      this->m_Conditions.m_Ints[v19 >> 5] &= ~(1 << (v19 & 0x1F));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026D00
// Name: public: virtual void CAI_BaseNPC::RunAI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RunAI(CAI_BaseNPC *this)
{
  CAI_Squad *m_pSquad; // ebx
  Vector *v3; // eax
  float y; // xmm2_4
  float v5; // xmm0_4
  void (__thiscall *GetVectors)(CBaseEntity *, Vector *, Vector *, Vector *); // edx
  const Vector *v7; // eax
  CAI_BaseNPC *i; // edi
  const Vector *v9; // eax
  Vector *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm0_4
  CBasePlayer *LocalPlayer; // eax
  int v14; // [esp+14h] [ebp-54h]
  int v15; // [esp+18h] [ebp-50h]
  Vector v16; // [esp+34h] [ebp-34h] BYREF
  Vector target; // [esp+40h] [ebp-28h] BYREF
  Vector right; // [esp+4Ch] [ebp-1Ch] BYREF
  Vector vecPoint; // [esp+58h] [ebp-10h] BYREF
  AISquadIter_t__ *iter; // [esp+64h] [ebp-4h] BYREF

  iter = (AISquadIter_t__ *)&g_AIRunTimer;
  g_AIRunTimer.m_Duration.m_Int64 = __rdtsc();
  if ( ai_debug_squads.m_pParent != nullptr
    && ai_debug_squads.m_pParent->m_Value.m_nValue != 0
    && this->m_pSquad != nullptr
    && !CAI_Squad::IsSilentMember(pNPC: this)
    && (CAI_Squad::IsLeader(this: this->m_pSquad, pNPC: this)
     || CAI_Squad::NumMembers(this: this->m_pSquad, bIgnoreSilentMembers: true) == 1) )
  {
    m_pSquad = this->m_pSquad;
    v3 = this->EyePosition(this, result: &target);
    y = v3->y;
    v5 = v3->z + 12.0;
    GetVectors = this->GetVectors;
    vecPoint.x = v3->x;
    vecPoint.y = y;
    vecPoint.z = v5;
    GetVectors(this, a2: nullptr, a3: &right, a4: nullptr);
    target.x = vecPoint.x;
    target.y = vecPoint.y;
    target.z = vecPoint.z + 64.0;
    NDebugOverlay::Line(origin: &vecPoint, &target, r: 0, g: 255, b: 0, noDepthTest: false, duration: 0.1);
    target.z = (float)(vecPoint.z + 32.0) + (float)(right.z * 32.0);
    target.x = vecPoint.x + (float)(right.x * 32.0);
    target.y = vecPoint.y + (float)(right.y * 32.0);
    NDebugOverlay::Line(origin: &vecPoint, &target, r: 0, g: 255, b: 0, noDepthTest: false, duration: 0.1);
    target.z = (float)(vecPoint.z + 32.0) - (float)(right.z * 32.0);
    target.x = vecPoint.x - (float)(right.x * 32.0);
    target.y = vecPoint.y - (float)(right.y * 32.0);
    NDebugOverlay::Line(origin: &vecPoint, &target, r: 0, g: 255, b: 0, noDepthTest: false, duration: 0.1);
    v7 = CAI_Squad::ComputeSquadCentroid(
           this: this->m_pSquad,
           result: &target,
           bIncludeSilentMembers: false,
           pExcludeMember: nullptr);
    NDebugOverlay::Cross3D(position: v7, size: 16.0, r: 255, g: 255, b: 255, noDepthTest: false, flDuration: 0.1);
    for ( i = CAI_Squad::GetFirstMember(this: m_pSquad, pIter: &iter, bIgnoreSilentMembers: false);
          i != nullptr;
          i = CAI_Squad::GetNextMember(this: m_pSquad, pIter: &iter, bIgnoreSilentMembers: false) )
    {
      if ( i != this )
      {
        v15 = CAI_Squad::IsSilentMember(pNPC: i) ? 127 : 255;
        v14 = ((int (__thiscall *)(CAI_BaseNPC *, Vector *, _DWORD))i->EyePosition)(a1: i, a2: &target, a3: 0);
        v9 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))this->EyePosition)(a1: this);
        NDebugOverlay::Line(origin: v9, target: &v16, r: v14, g: v15, b: 0, noDepthTest: false, duration: 0.1);
      }
    }
  }
  if ( ai_debug_loners.m_pParent != nullptr
    && ai_debug_loners.m_pParent->m_Value.m_nValue != 0
    && this->m_pSquad == nullptr
    && gpGlobals->maxClients == 1 )
  {
    v10 = this->EyePosition(this, result: &v16);
    v11 = v10->y;
    v12 = v10->z + 12.0;
    vecPoint.x = v10->x;
    vecPoint.y = v11;
    vecPoint.z = v12;
    LocalPlayer = UTIL_GetLocalPlayer();
    LocalPlayer->GetVectors(this: LocalPlayer, a2: nullptr, a3: &right, a4: nullptr);
    target.x = vecPoint.x;
    target.y = vecPoint.y;
    target.z = vecPoint.z + 64.0;
    NDebugOverlay::Line(origin: &vecPoint, &target, r: 255, g: 0, b: 0, noDepthTest: false, duration: 0.1);
    target.z = (float)(vecPoint.z + 32.0) + (float)(right.z * 32.0);
    target.x = vecPoint.x + (float)(right.x * 32.0);
    target.y = vecPoint.y + (float)(right.y * 32.0);
    NDebugOverlay::Line(origin: &vecPoint, &target, r: 255, g: 0, b: 0, noDepthTest: false, duration: 0.1);
    target.z = (float)(vecPoint.z + 32.0) - (float)(right.z * 32.0);
    target.x = vecPoint.x - (float)(right.x * 32.0);
    target.y = vecPoint.y - (float)(right.y * 32.0);
    NDebugOverlay::Line(origin: &vecPoint, &target, r: 255, g: 0, b: 0, noDepthTest: false, duration: 0.1);
  }
  *(_WORD *)&this->m_bConditionsGathered = 0;
  if ( g_pDeveloper->m_pParent != nullptr
    && g_pDeveloper->m_pParent->m_Value.m_nValue != 0
    && this->m_pNavigator->m_bNotOnNetwork )
  {
    CBaseEntity::AddTimedOverlay(this, msg: "NPC w/no reachable nodes!", endTime: 5);
  }
  this->GatherConditions(this);
  this->RemoveIgnoredConditions(this);
  if ( !this->m_bConditionsGathered )
    this->m_bConditionsGathered = true;
  CAI_BaseNPC::TryRestoreHull(this);
  iter = (AISquadIter_t__ *)&g_AIPrescheduleThinkTimer;
  g_AIPrescheduleThinkTimer.m_Duration.m_Int64 = __rdtsc();
  this->PrescheduleThink(this);
  iter = (AISquadIter_t__ *)&vecPoint.y;
  *(_QWORD *)&vecPoint.y = __rdtsc();
  g_AIPrescheduleThinkTimer.m_Duration.m_Int64 = *(_QWORD *)&vecPoint.y - g_AIPrescheduleThinkTimer.m_Duration.m_Int64;
  CAI_BaseNPC::MaintainSchedule(this);
  this->PostscheduleThink(this);
  CAI_BaseNPC::ClearTransientConditions(this);
  g_AIRunTimer.m_Duration.m_Int64 = __rdtsc() - g_AIRunTimer.m_Duration.m_Int64;
}

//------------------------------------------------------------------------------
// Address: 0x100272B0
// Name: protected: enum NPC_STATE CAI_BaseNPC::SelectScriptIdealState(void)
// Source: json
//------------------------------------------------------------------------------
NPC_STATE __thiscall CAI_BaseNPC::SelectScriptIdealState(CAI_BaseNPC *this)
{
  CAI_ClassScheduleIdSpace *v2; // eax
  int v3; // eax
  int v4; // eax
  CAI_ClassScheduleIdSpace *v5; // eax
  int v6; // eax
  int v7; // eax
  CAI_ClassScheduleIdSpace *v8; // eax
  int v9; // eax
  int v10; // eax
  NPC_STATE (__thiscall *SelectIdealState)(CAI_BaseNPC *); // edx
  NPC_STATE result; // eax

  v2 = this->GetClassScheduleIdSpace(this);
  v3 = CAI_LocalIdSpace::LocalToGlobal(this: &v2->m_ConditionIds, localID: 35);
  if ( v3 != -1 && (v4 = v3 - 1000000000) != -1 && ((1 << (v4 & 0x1F)) & this->m_Conditions.m_Ints[v4 >> 5]) != 0
    || (v5 = this->GetClassScheduleIdSpace(this),
        (v6 = CAI_LocalIdSpace::LocalToGlobal(this: &v5->m_ConditionIds, localID: 17)) != -1)
    && (v7 = v6 - 1000000000) != -1
    && ((1 << (v7 & 0x1F)) & this->m_Conditions.m_Ints[v7 >> 5]) != 0
    || (v8 = this->GetClassScheduleIdSpace(this),
        (v9 = CAI_LocalIdSpace::LocalToGlobal(this: &v8->m_ConditionIds, localID: 18)) != -1)
    && (v10 = v9 - 1000000000) != -1
    && ((1 << (v10 & 0x1F)) & this->m_Conditions.m_Ints[v10 >> 5]) != 0 )
  {
    CAI_BaseNPC::ExitScriptedSequence(this);
  }
  if ( this->m_IdealNPCState != NPC_STATE_IDLE )
    return NPC_STATE_INVALID;
  SelectIdealState = this->SelectIdealState;
  this->m_NPCState = NPC_STATE_IDLE;
  result = SelectIdealState(this);
  this->m_NPCState = NPC_STATE_SCRIPT;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100273C0
// Name: public: virtual enum NPC_STATE CAI_BaseNPC::SelectIdealState(void)
// Source: json
//------------------------------------------------------------------------------
NPC_STATE __thiscall CAI_BaseNPC::SelectIdealState(CAI_BaseNPC *this)
{
  CAI_ClassScheduleIdSpace *v2; // eax
  int v3; // eax
  int v4; // eax
  CBaseEntity *v5; // eax
  NPC_STATE result; // eax

  if ( this->m_pSquad != nullptr && (unsigned int)(this->m_NPCState - 1) <= 1 )
  {
    v2 = this->GetClassScheduleIdSpace(this);
    v3 = CAI_LocalIdSpace::LocalToGlobal(this: &v2->m_ConditionIds, localID: 26);
    if ( v3 != -1 )
    {
      v4 = v3 - 1000000000;
      if ( v4 != -1 && ((1 << (v4 & 0x1F)) & this->m_Conditions.m_Ints[v4 >> 5]) != 0 )
      {
        v5 = this->GetEnemy_2(this);
        CAI_Squad::SquadNewEnemy(this: this->m_pSquad, pEnemy: v5);
      }
    }
  }
  switch ( this->m_NPCState )
  {
    case NPC_STATE_IDLE:
      result = CAI_BaseNPC::SelectIdleIdealState(this);
      if ( result == NPC_STATE_INVALID )
        goto LABEL_9;
      break;
    case NPC_STATE_ALERT:
      result = CAI_BaseNPC::SelectAlertIdealState(this);
      if ( result == NPC_STATE_INVALID )
        goto LABEL_9;
      break;
    case NPC_STATE_COMBAT:
      if ( this->GetEnemy_2(this) != nullptr )
        goto LABEL_9;
      _DevWarning(a1: 2, a2: "***Combat state with no enemy!\n");
      result = NPC_STATE_ALERT;
      break;
    case NPC_STATE_SCRIPT:
      result = CAI_BaseNPC::SelectScriptIdealState(this);
      if ( result == NPC_STATE_INVALID )
        goto LABEL_9;
      break;
    case NPC_STATE_DEAD:
      result = NPC_STATE_DEAD;
      break;
    default:
LABEL_9:
      result = this->m_IdealNPCState;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100274C0
// Name: public: virtual bool CAI_BaseNPC::WeaponLOSCondition(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::WeaponLOSCondition(
        CAI_BaseNPC *this,
        const Vector *ownerPos,
        const Vector *targetPos,
        BOOL bSetConditions)
{
  CBaseCombatWeapon *ActiveWeapon; // eax
  bool v7; // bl
  CBaseCombatWeapon *v8; // eax
  double x; // xmm0_8
  float v10; // xmm0_4
  long double v12; // [esp+18h] [ebp-1Ch]
  Vector vSpread; // [esp+24h] [ebp-10h] BYREF
  float v14; // [esp+30h] [ebp-4h]
  float spread; // [esp+40h] [ebp+Ch]

  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    v7 = ActiveWeapon->WeaponLOSCondition(this: ActiveWeapon, a2: ownerPos, a3: targetPos, a4: bSetConditions);
  }
  else if ( (this->CapabilitiesGet(this) & 0x20000) != 0 )
  {
    v7 = this->InnateWeaponLOSCondition(this, a2: ownerPos, a3: targetPos, a4: bSetConditions);
  }
  else
  {
    if ( bSetConditions )
      CAI_BaseNPC::SetCondition(this, iCondition: 6);
    v7 = false;
  }
  if ( (this->CapabilitiesGet(this) & 0x50000000) == 0 )
    return v7;
  spread = 0.92000002;
  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
  {
    v14 = *(float *)&this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v8 = CBaseCombatCharacter::GetActiveWeapon(this);
    (*(void (__thiscall **)(CAI_BaseNPC *, Vector *, CBaseCombatWeapon *, _DWORD))(LODWORD(v14) + 1284))(
      a1: this,
      a2: &vSpread,
      a3: v8,
      a4: 0);
    if ( vSpread.x <= 0.13053 )
    {
      v10 = 0.99145001;
    }
    else
    {
      x = vSpread.x;
      __libm_sse2_asin(x: v12);
      *(float *)&x = x;
      v14 = (float)(*(float *)&x * 40.743664) + 12582976.0;
      v10 = SinCosTable[LOBYTE(v14)];
    }
    spread = v10;
  }
  if ( (this->CapabilitiesGet(this) & 0x10000000) == 0
    || ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *, const Vector *, const Vector *, _DWORD, int, int))this->PlayerInSpread)(
         a1: this,
         a2: ownerPos,
         a3: targetPos,
         a4: LODWORD(spread),
         a5: 1119879168,
         a6: 1) == 0 )
  {
    if ( v7
      && (this->CapabilitiesGet(this) & 0x40000000) != 0
      && this->m_pSquad != nullptr
      && this->GetEnemy_2(this) != nullptr
      && CAI_BaseNPC::IsSquadmateInSpread(
           this,
           sourcePos: ownerPos,
           targetPos,
           flSpread: spread,
           maxDistOffCenter: 96.0) )
    {
      CAI_BaseNPC::SetCondition(this, iCondition: 42);
      return false;
    }
    return v7;
  }
  if ( bSetConditions )
    CAI_BaseNPC::SetCondition(this, iCondition: 43);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100276B0
// Name: public: virtual bool CAI_BaseNPC::InnateWeaponLOSCondition(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::InnateWeaponLOSCondition(
        CAI_BaseNPC *this,
        const Vector *ownerPos,
        const Vector *targetPos,
        bool bSetConditions)
{
  const Vector *v5; // eax
  CBaseEntity *m_pEnt; // ebx
  CBaseEntity *v8; // eax
  int v9; // eax
  int v10; // edi
  CBaseEntity *v11; // edi
  CGameTrace tr; // [esp+4h] [ebp-60h] BYREF
  Vector barrelPos; // [esp+58h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+64h] [ebp+0h] BYREF

  v5 = this->GetViewOffset(this);
  barrelPos.x = v5->x + ownerPos->x;
  barrelPos.y = v5->y + ownerPos->y;
  barrelPos.z = v5->z + ownerPos->z;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &barrelPos,
    vecAbsEnd: targetPos,
    mask: 0x46004003u,
    ignore: this,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction == 1.0 )
    return 1;
  m_pEnt = tr.m_pEnt;
  if ( this->GetEnemy_2(this) != nullptr )
  {
    v8 = this->GetEnemy_2(this);
    v9 = (int)v8->MyCombatCharacterPointer(this: v8);
    v10 = v9;
    if ( v9 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 1260))(a1: v9) != 0 )
    {
      v11 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 1268))(a1: v10);
      if ( m_pEnt == v11 || CBaseEntity::GetOwnerEntity(this: m_pEnt) == v11 )
        return 1;
    }
  }
  if ( m_pEnt == this->GetEnemy_2(this) )
    return 1;
  if ( m_pEnt != nullptr && m_pEnt->MyCombatCharacterPointer(this: m_pEnt) != nullptr )
  {
    if ( this->IRelationType(this, a2: m_pEnt) == D_HT )
      return 1;
    if ( bSetConditions )
    {
      CAI_BaseNPC::SetCondition(this, iCondition: 42);
      return 0;
    }
  }
  else if ( bSetConditions )
  {
    CAI_BaseNPC::SetCondition(this, iCondition: 45);
    CAI_BaseNPC::SetEnemyOccluder(this, pBlocker: tr.m_pEnt);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10027810
// Name: public: virtual void CAI_BaseNPC::GatherEnemyConditions(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_BaseNPC::GatherEnemyConditions(
        CAI_BaseNPC *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseEntity *pEnemy)
{
  int v6; // eax
  int v7; // eax
  int v8; // edi
  CAI_ClassScheduleIdSpace *v9; // eax
  int v10; // eax
  CAI_ClassScheduleIdSpace *v11; // eax
  int v12; // eax
  int v13; // edi
  CAI_ClassScheduleIdSpace *v14; // eax
  int v15; // eax
  CAI_ClassScheduleIdSpace *v16; // eax
  int v17; // eax
  CBaseEntity *v18; // edi
  CAI_BaseNPC_vtbl *v19; // edx
  CBaseEntity *v20; // eax
  CAI_ClassScheduleIdSpace *v21; // eax
  int v22; // eax
  CAI_ClassScheduleIdSpace *v23; // eax
  int v24; // eax
  CAI_ClassScheduleIdSpace *v25; // eax
  int v26; // eax
  int v27; // edi
  CAI_ClassScheduleIdSpace *v28; // eax
  int v29; // eax
  bool (__thiscall *FVisible_2)(CBaseEntity *, CBaseEntity *, int, CBaseEntity **); // edx
  CBaseEntity *v31; // eax
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // eax
  CBaseEntity *v33; // eax
  CBaseEntity *(__thiscall *v34)(CBaseEntity *); // eax
  CBaseEntity *v35; // eax
  CBaseEntity *v36; // eax
  float v37; // edi
  CBaseEntity *v38; // eax
  bool v39; // al
  CAI_ClassScheduleIdSpace *v40; // eax
  int v41; // eax
  int v42; // edi
  CAI_ClassScheduleIdSpace *v43; // eax
  int v44; // eax
  int v45; // eax
  CAI_ClassScheduleIdSpace *v46; // eax
  int v47; // eax
  int v48; // edi
  CAI_ClassScheduleIdSpace *v49; // eax
  int v50; // eax
  int v51; // eax
  CAI_ClassScheduleIdSpace *v52; // eax
  int v53; // eax
  int v54; // edi
  CAI_ClassScheduleIdSpace *v55; // eax
  int v56; // eax
  int v57; // eax
  CAI_ClassScheduleIdSpace *v58; // eax
  int v59; // eax
  int v60; // eax
  float *v61; // ecx
  float *v62; // eax
  double v63; // st7
  unsigned int v64; // eax
  bool (__thiscall *UpdateEnemyMemory)(CAI_BaseNPC *, CBaseEntity *, const Vector *, CBaseEntity *); // edx
  float v66; // xmm0_4
  CAI_BaseNPC_vtbl *v67; // edx
  int v68; // eax
  CAI_ClassScheduleIdSpace *v69; // eax
  int v70; // eax
  int v71; // eax
  CAI_BaseNPC_vtbl *v72; // eax
  const Vector *AbsOrigin; // eax
  CAI_ClassScheduleIdSpace *v74; // eax
  int v75; // eax
  int v76; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  float x; // xmm0_4
  CAI_ClassScheduleIdSpace *v79; // eax
  int v80; // eax
  int v81; // edi
  CAI_ClassScheduleIdSpace *v82; // eax
  int v83; // eax
  int v84; // eax
  bool v85; // zf
  CAI_BaseNPC_vtbl *v86; // eax
  CBaseEntity *v87; // eax
  CAI_BaseNPC_vtbl *v88; // edi
  CBaseEntity *v89; // eax
  CBaseEntity *(__thiscall *GetEnemy)(CBaseEntity *); // eax
  float v91; // eax
  CAI_BaseNPC_vtbl *v92; // edx
  CAI_Enemies *v93; // eax
  Vector *v94; // eax
  int m_iEFlags; // edx
  __int128 v96; // xmm0
  CAI_ClassScheduleIdSpace *v97; // eax
  int v98; // eax
  int v99; // eax
  CAI_ClassScheduleIdSpace *v100; // eax
  int v101; // eax
  int v102; // eax
  CAI_ClassScheduleIdSpace *v103; // eax
  int v104; // eax
  int v105; // eax
  __int128 v107; // [esp+30h] [ebp-4Ch] BYREF
  float v108[3]; // [esp+4Ch] [ebp-30h] BYREF
  Vector vTrailPos; // [esp+58h] [ebp-24h] BYREF
  Vector flEnemyLKP; // [esp+64h] [ebp-18h] BYREF
  float tooFar; // [esp+70h] [ebp-Ch] BYREF
  CBaseEntity *pBlocker; // [esp+74h] [ebp-8h]
  CBaseEntity *retaddr; // [esp+7Ch] [ebp+0h]

  tooFar = a2;
  pBlocker = retaddr;
  v6 = ((int (__thiscall *)(CAI_BaseNPC *, int, int))this->GetClassScheduleIdSpace)(a1: this, a2: a3, a3: a4);
  v7 = CAI_LocalIdSpace::LocalToGlobal(this: (CAI_LocalIdSpace *)(v6 + 52), localID: 28);
  if ( v7 != -1 )
  {
    v8 = v7 - 1000000000;
    if ( v7 != 999999999 )
    {
      v9 = this->GetClassScheduleIdSpace(this);
      v10 = CAI_LocalIdSpace::LocalToGlobal(this: &v9->m_ConditionIds, localID: 28);
      if ( v10 != -1
        && v10 != 999999999
        && ((1 << (v10 & 0x1F)) & this->m_Conditions.m_Ints[(v10 - 1000000000) >> 5]) != 0 )
      {
        this->OnConditionCleared(this, a2: 28);
      }
      this->m_Conditions.m_Ints[v8 >> 5] &= ~(1 << (v8 & 0x1F));
    }
  }
  v11 = this->GetClassScheduleIdSpace(this);
  v12 = CAI_LocalIdSpace::LocalToGlobal(this: &v11->m_ConditionIds, localID: 29);
  if ( v12 != -1 )
  {
    v13 = v12 - 1000000000;
    if ( v12 != 999999999 )
    {
      v14 = this->GetClassScheduleIdSpace(this);
      v15 = CAI_LocalIdSpace::LocalToGlobal(this: &v14->m_ConditionIds, localID: 29);
      if ( v15 != -1
        && v15 != 999999999
        && ((1 << (v15 & 0x1F)) & this->m_Conditions.m_Ints[(v15 - 1000000000) >> 5]) != 0 )
      {
        this->OnConditionCleared(this, a2: 29);
      }
      this->m_Conditions.m_Ints[v13 >> 5] &= ~(1 << (v13 & 0x1F));
    }
  }
  v16 = this->GetClassScheduleIdSpace(this);
  v17 = CAI_LocalIdSpace::LocalToGlobal(this: &v16->m_ConditionIds, localID: 26);
  v18 = pEnemy;
  if ( v17 != -1 && v17 != 999999999 && ((1 << (v17 & 0x1F)) & this->m_Conditions.m_Ints[(v17 - 1000000000) >> 5]) != 0
    || (v19 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable,
        LODWORD(flEnemyLKP.y) = this->m_pSenses,
        v20 = v19->GetEnemy_2(this),
        CAI_Senses::GetTimeLastUpdate(this: (CAI_Senses *)LODWORD(flEnemyLKP.y), pEntity: v20) == gpGlobals->curtime) )
  {
    v21 = this->GetClassScheduleIdSpace(this);
    v22 = CAI_LocalIdSpace::LocalToGlobal(this: &v21->m_ConditionIds, localID: 15);
    if ( v22 != -1 )
    {
      LODWORD(flEnemyLKP.x) = v22 - 1000000000;
      if ( v22 != 999999999 )
      {
        v23 = this->GetClassScheduleIdSpace(this);
        v24 = CAI_LocalIdSpace::LocalToGlobal(this: &v23->m_ConditionIds, localID: 15);
        if ( v24 != -1
          && v24 != 999999999
          && ((1 << (v24 & 0x1F)) & this->m_Conditions.m_Ints[(v24 - 1000000000) >> 5]) != 0 )
        {
          this->OnConditionCleared(this, a2: 15);
        }
        this->m_Conditions.m_Ints[SLODWORD(flEnemyLKP.x) >> 5] &= ~(1 << (LOBYTE(flEnemyLKP.x) & 0x1F));
      }
    }
    v25 = this->GetClassScheduleIdSpace(this);
    v26 = CAI_LocalIdSpace::LocalToGlobal(this: &v25->m_ConditionIds, localID: 13);
    if ( v26 != -1 )
    {
      v27 = v26 - 1000000000;
      if ( v26 != 999999999 )
      {
        v28 = this->GetClassScheduleIdSpace(this);
        v29 = CAI_LocalIdSpace::LocalToGlobal(this: &v28->m_ConditionIds, localID: 13);
        if ( v29 != -1
          && v29 != 999999999
          && ((1 << (v29 & 0x1F)) & this->m_Conditions.m_Ints[(v29 - 1000000000) >> 5]) != 0 )
        {
          this->OnConditionCleared(this, a2: 13);
        }
        this->m_Conditions.m_Ints[v27 >> 5] &= ~(1 << (v27 & 0x1F));
      }
      v18 = pEnemy;
    }
    this->m_hEnemyOccluder.m_Index = -1;
    HIBYTE(flEnemyLKP.z) = CAI_Senses::DidSeeEntity(this: this->m_pSenses, pSightEnt: nullptr);
    if ( HIBYTE(flEnemyLKP.z) != 0
      || (flEnemyLKP.x = this->m_pSenses->m_LookDist,
          CAI_BaseNPC::EnemyDistance(this, a2: (int)v18, a3: (int)this, pEnemy: v18) < flEnemyLKP.x)
      && (FVisible_2 = this->FVisible_2,
          LODWORD(flEnemyLKP.y) = &flEnemyLKP.y,
          ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *, CBaseEntity *, int))FVisible_2)(a1: this, a2: v18, a3: 16449) != 0) )
    {
      CAI_BaseNPC::SetCondition(this, iCondition: 15);
      LODWORD(flEnemyLKP.y) = 10;
      if ( HIBYTE(flEnemyLKP.z) != 0 )
        CAI_BaseNPC::SetCondition(this, iCondition: SLODWORD(flEnemyLKP.y));
      else
        CAI_BaseNPC::ClearCondition(this, iCondition: SLODWORD(flEnemyLKP.y));
      if ( (this->m_afMemory & 0x20000) == 0 )
      {
        v36 = this->GetEnemy_2(this);
        if ( v36 != nullptr )
          v37 = *(float *)&v36->GetRefEHandle(this: v36)->m_Index;
        else
          v37 = NAN;
        v38 = this->GetEnemy_2(this);
        v39 = v38->IsPlayer(this: v38);
        LODWORD(flEnemyLKP.y) = this;
        LODWORD(flEnemyLKP.x) = this;
        vTrailPos.z = v37;
        if ( v39 )
        {
          CEntityOutputTemplate<CHandle<CBaseEntity>,13>::Set(
            this: &this->m_OnFoundPlayer,
            value: LODWORD(vTrailPos.z),
            pActivator: (CBaseEntity *)LODWORD(flEnemyLKP.x),
            pCaller: (CBaseEntity *)LODWORD(flEnemyLKP.y));
          LODWORD(flEnemyLKP.y) = this;
          LODWORD(flEnemyLKP.x) = this;
          vTrailPos.z = v37;
        }
        CEntityOutputTemplate<CHandle<CBaseEntity>,13>::Set(
          this: &this->m_OnFoundEnemy,
          value: LODWORD(vTrailPos.z),
          pActivator: (CBaseEntity *)LODWORD(flEnemyLKP.x),
          pCaller: (CBaseEntity *)LODWORD(flEnemyLKP.y));
        v18 = pEnemy;
      }
      this->m_afMemory |= 0x20000u;
    }
    else
    {
      if ( LODWORD(flEnemyLKP.y) != 0 )
        this->m_hEnemyOccluder.m_Index = *(_DWORD *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(flEnemyLKP.y) + 8))(a1: LODWORD(flEnemyLKP.y));
      else
        this->m_hEnemyOccluder.m_Index = -1;
      CAI_BaseNPC::SetCondition(this, iCondition: 13);
      CAI_BaseNPC::ClearCondition(this, iCondition: 10);
      if ( (this->m_afMemory & 0x20000) != 0 )
      {
        v31 = this->GetEnemy_2(this);
        if ( v31->IsPlayer(this: v31) )
        {
          GetEnemy_2 = this->GetEnemy_2;
          flEnemyLKP.y = 0.0;
          v33 = GetEnemy_2(this);
          COutputEvent::FireOutput(this: &this->m_OnLostPlayerLOS, pActivator: v33, pCaller: this, fDelay: flEnemyLKP.y);
        }
        v34 = this->GetEnemy_2;
        flEnemyLKP.y = 0.0;
        v35 = v34(this);
        COutputEvent::FireOutput(this: &this->m_OnLostEnemyLOS, pActivator: v35, pCaller: this, fDelay: flEnemyLKP.y);
      }
      this->m_afMemory &= ~0x20000u;
    }
  }
  if ( v18->IsAlive(this: v18) )
  {
    flEnemyLKP.y = CAI_BaseNPC::EnemyDistance(this, a2: (int)v18, a3: (int)this, pEnemy: v18);
    v58 = this->GetClassScheduleIdSpace(this);
    v59 = CAI_LocalIdSpace::LocalToGlobal(this: &v58->m_ConditionIds, localID: 10);
    if ( v59 == -1 || (v60 = v59 - 1000000000) == -1 || ((1 << (v60 & 0x1F)) & this->m_Conditions.m_Ints[v60 >> 5]) == 0 )
    {
      v69 = this->GetClassScheduleIdSpace(this);
      v70 = CAI_LocalIdSpace::LocalToGlobal(this: &v69->m_ConditionIds, localID: 13);
      if ( (v70 == -1
         || (v71 = v70 - 1000000000) == -1
         || ((1 << (v71 & 0x1F)) & this->m_Conditions.m_Ints[v71 >> 5]) == 0)
        && !CAI_BaseNPC::HasCondition(this, iCondition: 10)
        && flEnemyLKP.y <= 256.0 )
      {
        v72 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        LODWORD(flEnemyLKP.y) = v18;
        LODWORD(flEnemyLKP.x) = v72;
        AbsOrigin = CBaseEntity::GetAbsOrigin(this: v18);
        (*(void (__thiscall **)(CAI_BaseNPC *, CBaseEntity *, const Vector *, _DWORD))(LODWORD(flEnemyLKP.x) + 2124))(
          a1: this,
          a2: v18,
          a3: AbsOrigin,
          a4: LODWORD(flEnemyLKP.y));
      }
    }
    else
    {
      v61 = (float *)((int (__thiscall *)(CBaseEntity *, float *, _DWORD))v18->GetSmoothedVelocity)(
                       a1: v18,
                       a2: v108,
                       a3: LODWORD(flEnemyLKP.z));
      if ( vec3_origin.x == *v61 && vec3_origin.y == v61[1] && vec3_origin.z == v61[2] )
      {
        if ( (v18->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v18);
        v67 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        flEnemyLKP.z = 0.0;
        ((void (__thiscall *)(CAI_BaseNPC *, CBaseEntity *, Vector *))v67->UpdateEnemyMemory)(
          a1: this,
          a2: v18,
          a3: &v18->m_vecAbsOrigin);
      }
      else
      {
        flEnemyLKP.x = ((double (__thiscall *)(IUniformRandomStream *, int, _DWORD))random->RandomFloat)(
                         a1: random,
                         a2: -1119040307,
                         a3: 0);
        v62 = (float *)v18->GetSmoothedVelocity(this: v18, result: (Vector *)((char *)&v107 + 4));
        vTrailPos.x = flEnemyLKP.x * *v62;
        vTrailPos.y = v62[1] * flEnemyLKP.x;
        v63 = flEnemyLKP.x * v62[2];
        v64 = (unsigned int)v18->m_iEFlags >> 11;
        vTrailPos.z = v63;
        if ( (v64 & 1) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v18);
        UpdateEnemyMemory = this->UpdateEnemyMemory;
        v108[0] = v18->m_vecAbsOrigin.x - vTrailPos.x;
        v66 = v18->m_vecAbsOrigin.y - vTrailPos.y;
        flEnemyLKP.z = 0.0;
        v108[1] = v66;
        v108[2] = v18->m_vecAbsOrigin.z - vTrailPos.z;
        ((void (__thiscall *)(CAI_BaseNPC *, CBaseEntity *, float *))UpdateEnemyMemory)(a1: this, a2: v18, a3: v108);
      }
      if ( v18->MyCombatCharacterPointer(this: v18) != nullptr
        && (v68 = (int)v18->MyCombatCharacterPointer(this: v18),
            (*(unsigned __int8 (__thiscall **)(int, CAI_BaseNPC *))(*(_DWORD *)v68 + 968))(a1: v68, a2: this) != 0) )
      {
        CAI_BaseNPC::SetCondition(this, iCondition: 28);
        CAI_BaseNPC::ClearCondition(this, iCondition: 29);
      }
      else
      {
        CAI_BaseNPC::ClearCondition(this, iCondition: 28);
        CAI_BaseNPC::SetCondition(this, iCondition: 29);
      }
    }
    flEnemyLKP.x = this->m_flDistTooFar;
    if ( CBaseCombatCharacter::GetActiveWeapon(this) == nullptr
      || (v74 = this->GetClassScheduleIdSpace(this),
          (v75 = CAI_LocalIdSpace::LocalToGlobal(this: &v74->m_ConditionIds, localID: 10)) == -1)
      || (v76 = v75 - 1000000000) == -1
      || ((1 << (v76 & 0x1F)) & this->m_Conditions.m_Ints[v76 >> 5]) == 0 )
    {
      x = flEnemyLKP.x;
    }
    else
    {
      flEnemyLKP.x = this->m_flDistTooFar;
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
      x = flEnemyLKP.x;
      if ( flEnemyLKP.x <= ActiveWeapon->m_fMaxRange1 )
        x = CBaseCombatCharacter::GetActiveWeapon(this)->m_fMaxRange1;
    }
    if ( flEnemyLKP.y < x )
    {
      CAI_BaseNPC::ClearCondition(this, iCondition: 27);
    }
    else
    {
      v79 = this->GetClassScheduleIdSpace(this);
      v80 = CAI_LocalIdSpace::LocalToGlobal(this: &v79->m_ConditionIds, localID: 27);
      if ( v80 != -1 )
      {
        v81 = v80 - 1000000000;
        if ( v80 != 999999999 )
        {
          v82 = this->GetClassScheduleIdSpace(this);
          v83 = CAI_LocalIdSpace::LocalToGlobal(this: &v82->m_ConditionIds, localID: 27);
          if ( v83 == -1
            || (v84 = v83 - 1000000000) == -1
            || ((1 << (v84 & 0x1F)) & this->m_Conditions.m_Ints[v84 >> 5]) == 0 )
          {
            this->OnConditionSet(this, a2: 27);
          }
          this->m_Conditions.m_Ints[v81 >> 5] |= 1 << (v81 & 0x1F);
        }
      }
    }
    v85 = !this->FCanCheckAttacks(this);
    v86 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    if ( v85 )
    {
      v86->ClearAttackConditions(this);
    }
    else
    {
      v87 = v86->GetEnemy_2(this);
      CAI_BaseNPC::GatherAttackConditions(this, pTarget: v87, flDist: flEnemyLKP.y);
    }
    CAI_BaseNPC::UpdateEnemyPos(this, a2: COERCE_FLOAT(&tooFar));
    CAI_BaseNPC::UpdateTargetPos(this);
    if ( !this->m_pNavigator->m_bNotOnNetwork )
    {
      v88 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v89 = this->GetEnemy_2(this);
      if ( v88->IsUnreachable(this, a2: v89) )
        CAI_BaseNPC::SetCondition(this, iCondition: 31);
    }
    GetEnemy = this->GetEnemy;
    LODWORD(flEnemyLKP.y) = 1;
    v91 = COERCE_FLOAT((int)GetEnemy(this));
    v92 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    flEnemyLKP.x = v91;
    v93 = v92->GetEnemies(this);
    if ( gpGlobals->curtime
       - CAI_Enemies::LastTimeSeen(
           this: v93,
           pEnemy: (CBaseEntity *)LODWORD(flEnemyLKP.x),
           bCheckDangerMemory: SLOBYTE(flEnemyLKP.y)) > 8.0 )
    {
      v94 = this->GetEnemyLKP(this);
      m_iEFlags = this->m_iEFlags;
      vTrailPos = *v94;
      if ( (m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      v96 = 0;
      *(float *)&v96 = fsqrt(
                         (float)((float)(vTrailPos.y - this->m_vecAbsOrigin.y)
                               * (float)(vTrailPos.y - this->m_vecAbsOrigin.y))
                       + (float)((float)(vTrailPos.x - this->m_vecAbsOrigin.x)
                               * (float)(vTrailPos.x - this->m_vecAbsOrigin.x)));
      v107 = v96;
      if ( *(float *)&v96 < 48.0 )
      {
        v97 = this->GetClassScheduleIdSpace(this);
        v98 = CAI_LocalIdSpace::LocalToGlobal(this: &v97->m_ConditionIds, localID: 10);
        if ( v98 == -1
          || (v99 = v98 - 1000000000) == -1
          || ((1 << (v99 & 0x1F)) & this->m_Conditions.m_Ints[v99 >> 5]) == 0 )
        {
          CAI_BaseNPC::MarkEnemyAsEluded(this);
        }
      }
      v100 = this->GetClassScheduleIdSpace(this);
      v101 = CAI_LocalIdSpace::LocalToGlobal(this: &v100->m_ConditionIds, localID: 10);
      if ( v101 == -1
        || (v102 = v101 - 1000000000) == -1
        || ((1 << (v102 & 0x1F)) & this->m_Conditions.m_Ints[v102 >> 5]) == 0 )
      {
        v103 = this->GetClassScheduleIdSpace(this);
        v104 = CAI_LocalIdSpace::LocalToGlobal(this: &v103->m_ConditionIds, localID: 31);
        if ( v104 != -1 )
        {
          v105 = v104 - 1000000000;
          if ( v105 != -1
            && ((1 << (v105 & 0x1F)) & this->m_Conditions.m_Ints[v105 >> 5]) != 0
            && !this->FVisible(this, a2: &vTrailPos, a3: 16449, a4: nullptr) )
          {
            CAI_BaseNPC::MarkEnemyAsEluded(this);
          }
        }
      }
    }
  }
  else
  {
    v40 = this->GetClassScheduleIdSpace(this);
    v41 = CAI_LocalIdSpace::LocalToGlobal(this: &v40->m_ConditionIds, localID: 30);
    if ( v41 != -1 )
    {
      v42 = v41 - 1000000000;
      if ( v41 != 999999999 )
      {
        v43 = this->GetClassScheduleIdSpace(this);
        v44 = CAI_LocalIdSpace::LocalToGlobal(this: &v43->m_ConditionIds, localID: 30);
        if ( v44 == -1
          || (v45 = v44 - 1000000000) == -1
          || ((1 << (v45 & 0x1F)) & this->m_Conditions.m_Ints[v45 >> 5]) == 0 )
        {
          this->OnConditionSet(this, a2: 30);
        }
        this->m_Conditions.m_Ints[v42 >> 5] |= 1 << (v42 & 0x1F);
      }
    }
    v46 = this->GetClassScheduleIdSpace(this);
    v47 = CAI_LocalIdSpace::LocalToGlobal(this: &v46->m_ConditionIds, localID: 10);
    if ( v47 != -1 )
    {
      v48 = v47 - 1000000000;
      if ( v47 != 999999999 )
      {
        v49 = this->GetClassScheduleIdSpace(this);
        v50 = CAI_LocalIdSpace::LocalToGlobal(this: &v49->m_ConditionIds, localID: 10);
        if ( v50 != -1 )
        {
          v51 = v50 - 1000000000;
          if ( v51 != -1 && ((1 << (v51 & 0x1F)) & this->m_Conditions.m_Ints[v51 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 10);
        }
        this->m_Conditions.m_Ints[v48 >> 5] &= ~(1 << (v48 & 0x1F));
      }
    }
    v52 = this->GetClassScheduleIdSpace(this);
    v53 = CAI_LocalIdSpace::LocalToGlobal(this: &v52->m_ConditionIds, localID: 13);
    if ( v53 != -1 )
    {
      v54 = v53 - 1000000000;
      if ( v53 != 999999999 )
      {
        v55 = this->GetClassScheduleIdSpace(this);
        v56 = CAI_LocalIdSpace::LocalToGlobal(this: &v55->m_ConditionIds, localID: 13);
        if ( v56 != -1 )
        {
          v57 = v56 - 1000000000;
          if ( v57 != -1 && ((1 << (v57 & 0x1F)) & this->m_Conditions.m_Ints[v57 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 13);
        }
        this->m_Conditions.m_Ints[v54 >> 5] &= ~(1 << (v54 & 0x1F));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028440
// Name: public: void CAI_BaseNPC::CheckTarget(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::CheckTarget(CAI_BaseNPC *this, CBaseEntity *pTarget)
{
  CAI_ClassScheduleIdSpace *v3; // eax
  int v4; // eax
  int v5; // edi
  CAI_ClassScheduleIdSpace *v6; // eax
  int v7; // eax
  int v8; // eax
  CAI_ClassScheduleIdSpace *v9; // eax
  int v10; // eax
  int v11; // edi
  CAI_ClassScheduleIdSpace *v12; // eax
  int v13; // eax
  int v14; // eax
  CAI_ClassScheduleIdSpace *v15; // eax
  int v16; // eax
  int v17; // edi
  CAI_ClassScheduleIdSpace *v18; // eax
  int v19; // eax
  int v20; // eax
  CAI_ClassScheduleIdSpace *v21; // eax
  int v22; // eax
  CAI_ClassScheduleIdSpace *v23; // eax
  int v24; // eax
  int v25; // eax
  float m_LookDist; // [esp+8h] [ebp-4h]

  v3 = this->GetClassScheduleIdSpace(this);
  v4 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: 16);
  if ( v4 != -1 )
  {
    v5 = v4 - 1000000000;
    if ( v4 != 999999999 )
    {
      v6 = this->GetClassScheduleIdSpace(this);
      v7 = CAI_LocalIdSpace::LocalToGlobal(this: &v6->m_ConditionIds, localID: 16);
      if ( v7 != -1 )
      {
        v8 = v7 - 1000000000;
        if ( v8 != -1 && ((1 << (v8 & 0x1F)) & this->m_Conditions.m_Ints[v8 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 16);
      }
      this->m_Conditions.m_Ints[v5 >> 5] &= ~(1 << (v5 & 0x1F));
    }
  }
  v9 = this->GetClassScheduleIdSpace(this);
  v10 = CAI_LocalIdSpace::LocalToGlobal(this: &v9->m_ConditionIds, localID: 14);
  if ( v10 != -1 )
  {
    v11 = v10 - 1000000000;
    if ( v10 != 999999999 )
    {
      v12 = this->GetClassScheduleIdSpace(this);
      v13 = CAI_LocalIdSpace::LocalToGlobal(this: &v12->m_ConditionIds, localID: 14);
      if ( v13 != -1 )
      {
        v14 = v13 - 1000000000;
        if ( v14 != -1 && ((1 << (v14 & 0x1F)) & this->m_Conditions.m_Ints[v14 >> 5]) != 0 )
          this->OnConditionCleared(this, a2: 14);
      }
      this->m_Conditions.m_Ints[v11 >> 5] &= ~(1 << (v11 & 0x1F));
    }
  }
  m_LookDist = this->m_pSenses->m_LookDist;
  if ( CAI_BaseNPC::EnemyDistance(this, a2: (int)pTarget, a3: (int)this, pEnemy: pTarget) < m_LookDist
    && this->FVisible_2(this, a2: pTarget, a3: 16449, a4: nullptr) )
  {
    v15 = this->GetClassScheduleIdSpace(this);
    v16 = CAI_LocalIdSpace::LocalToGlobal(this: &v15->m_ConditionIds, localID: 16);
    if ( v16 != -1 )
    {
      v17 = v16 - 1000000000;
      if ( v16 != 999999999 )
      {
        v18 = this->GetClassScheduleIdSpace(this);
        v19 = CAI_LocalIdSpace::LocalToGlobal(this: &v18->m_ConditionIds, localID: 16);
        if ( v19 == -1
          || (v20 = v19 - 1000000000) == -1
          || ((1 << (v20 & 0x1F)) & this->m_Conditions.m_Ints[v20 >> 5]) == 0 )
        {
          this->OnConditionSet(this, a2: 16);
        }
LABEL_29:
        this->m_Conditions.m_Ints[v17 >> 5] |= 1 << (v17 & 0x1F);
      }
    }
  }
  else
  {
    v21 = this->GetClassScheduleIdSpace(this);
    v22 = CAI_LocalIdSpace::LocalToGlobal(this: &v21->m_ConditionIds, localID: 14);
    if ( v22 != -1 )
    {
      v17 = v22 - 1000000000;
      if ( v22 != 999999999 )
      {
        v23 = this->GetClassScheduleIdSpace(this);
        v24 = CAI_LocalIdSpace::LocalToGlobal(this: &v23->m_ConditionIds, localID: 14);
        if ( v24 == -1
          || (v25 = v24 - 1000000000) == -1
          || ((1 << (v25 & 0x1F)) & this->m_Conditions.m_Ints[v25 >> 5]) == 0 )
        {
          this->OnConditionSet(this, a2: 14);
        }
        goto LABEL_29;
      }
    }
  }
  CAI_BaseNPC::UpdateTargetPos(this);
}

//------------------------------------------------------------------------------
// Address: 0x100286C0
// Name: public: virtual int CAI_BaseNPC::HolsterWeapon(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::HolsterWeapon(CAI_BaseNPC *this)
{
  int result; // eax
  int v3; // eax
  int v4; // edi
  float flTime; // [esp+0h] [ebp-Ch]

  if ( CBaseCombatCharacter::GetActiveWeapon(this) == nullptr
    || (CBaseCombatCharacter::GetActiveWeapon(this)->m_fEffects.m_Value & 0x20) != 0 )
  {
    return -1;
  }
  result = CBaseAnimatingOverlay::FindGestureLayer(this, activity: ACT_DISARM);
  if ( result == -1 )
  {
    v3 = CBaseAnimatingOverlay::AddGesture(this, activity: ACT_DISARM, autokill: true);
    v4 = v3;
    if ( v3 != -1 )
    {
      flTime = CBaseAnimatingOverlay::GetLayerDuration(this, iLayer: v3) + gpGlobals->curtime + 0.5;
      CAI_ShotRegulator::FireNoEarlierThan(this: &this->m_ShotRegulator, flTime);
      this->m_iDesiredWeaponState = (this->m_iDesiredWeaponState == DESIREDWEAPONSTATE_HOLSTERED_DESTROYED) + 4;
      CAI_BaseNPC::ClearCondition(this, iCondition: 3);
      CAI_BaseNPC::ClearCondition(this, iCondition: 4);
      CAI_BaseNPC::ClearCondition(this, iCondition: 5);
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028770
// Name: public: virtual void CAI_BaseNPC::TaskFail(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::TaskFail(CAI_BaseNPC *this, int code)
{
  const char *v3; // eax
  CAI_Schedule *m_pSchedule; // ecx
  bool v5; // zf
  CAI_ClassScheduleIdSpace *(__thiscall *GetClassScheduleIdSpace)(CAI_BaseNPC *); // eax
  int v7; // eax
  int v8; // eax
  int v9; // edi
  CAI_ClassScheduleIdSpace *v10; // eax
  int v11; // eax
  int v12; // eax

  CAI_BaseNPC::EndTaskOverlay(this);
  if ( g_pDeveloper->m_pParent != nullptr && g_pDeveloper->m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = TaskFailureToString(code);
    m_pSchedule = this->m_pSchedule;
    v5 = (this->m_debugOverlays & 0x8000000) == 0;
    this->m_failText = v3;
    this->m_interuptSchedule = nullptr;
    this->m_failedSchedule = m_pSchedule;
    if ( !v5 )
      DevMsg(pAI: this, flags: 1, pszFormat: "      TaskFail -> %s\n", v3);
  }
  GetClassScheduleIdSpace = this->GetClassScheduleIdSpace;
  this->m_ScheduleState.taskFailureCode = code;
  v7 = (int)GetClassScheduleIdSpace(this);
  v8 = CAI_LocalIdSpace::LocalToGlobal(this: (CAI_LocalIdSpace *)(v7 + 52), localID: 35);
  if ( v8 != -1 )
  {
    v9 = v8 - 1000000000;
    if ( v8 != 999999999 )
    {
      v10 = this->GetClassScheduleIdSpace(this);
      v11 = CAI_LocalIdSpace::LocalToGlobal(this: &v10->m_ConditionIds, localID: 35);
      if ( v11 == -1
        || (v12 = v11 - 1000000000) == -1
        || ((1 << (v12 & 0x1F)) & this->m_Conditions.m_Ints[v12 >> 5]) == 0 )
      {
        this->OnConditionSet(this, a2: 35);
      }
      this->m_Conditions.m_Ints[v9 >> 5] |= 1 << (v9 & 0x1F);
    }
  }
  this->m_afMemory &= ~0x2000u;
}

//------------------------------------------------------------------------------
// Address: 0x10028880
// Name: public: virtual bool CAI_BaseNPC::IsUnreachable(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::IsUnreachable(CAI_BaseNPC *this, CBaseEntity *pEntity)
{
  int v3; // edi
  unsigned int j; // ebx
  UnreachableEnt_t *v5; // edx
  unsigned int m_Index; // eax
  int m_Size; // eax
  UnreachableEnt_t *m_pMemory; // ecx
  int v9; // eax
  __int64 v10; // xmm0_8
  int v11; // eax
  unsigned int v12; // eax
  CBaseEntity *m_pEntity; // ecx
  CBaseEntity *v14; // eax
  int v16; // edi
  UnreachableEnt_t *v17; // ebx
  int v18; // eax
  UnreachableEnt_t *v19; // ecx
  __int64 v20; // xmm0_8
  int v21; // eax
  int i; // [esp+Ch] [ebp-4h]

  v3 = this->m_UnreachableEnts.m_Size - 1;
  i = v3;
  if ( v3 < 0 )
    return 0;
  for ( j = v3; ; --j )
  {
    v5 = &this->m_UnreachableEnts.m_Memory.m_pMemory[j];
    m_Index = v5->hUnreachableEnt.m_Index;
    if ( v5->hUnreachableEnt.m_Index != -1 )
    {
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        break;
      }
      v3 = i;
    }
    m_Size = this->m_UnreachableEnts.m_Size;
    if ( m_Size > 0 )
    {
      if ( v3 != m_Size - 1 )
      {
        m_pMemory = this->m_UnreachableEnts.m_Memory.m_pMemory;
        v9 = m_Size;
        v10 = *(_QWORD *)&m_pMemory[v9 - 1].hUnreachableEnt.m_Index;
        v11 = (int)&m_pMemory[v9 - 1];
        *(_QWORD *)&m_pMemory[j].hUnreachableEnt.m_Index = v10;
        *(_QWORD *)&m_pMemory[j].vLocationWhenUnreachable.x = *(_QWORD *)(v11 + 8);
        m_pMemory[j].vLocationWhenUnreachable.z = *(float *)(v11 + 16);
      }
      --this->m_UnreachableEnts.m_Size;
    }
LABEL_16:
    i = --v3;
    if ( v3 < 0 )
      return 0;
  }
  v12 = v5->hUnreachableEnt.m_Index;
  if ( v5->hUnreachableEnt.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
  }
  v14 = pEntity;
  v3 = i;
  if ( pEntity != m_pEntity )
    goto LABEL_16;
  v16 = i;
  v17 = &this->m_UnreachableEnts.m_Memory.m_pMemory[i];
  if ( gpGlobals->curtime <= v17->fExpireTime )
  {
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: pEntity);
      v14 = pEntity;
    }
    if ( (float)((float)((float)((float)(v14->m_vecAbsOrigin.y - v17->vLocationWhenUnreachable.y)
                               * (float)(v14->m_vecAbsOrigin.y - v17->vLocationWhenUnreachable.y))
                       + (float)((float)(v14->m_vecAbsOrigin.x - v17->vLocationWhenUnreachable.x)
                               * (float)(v14->m_vecAbsOrigin.x - v17->vLocationWhenUnreachable.x)))
               + (float)((float)(v14->m_vecAbsOrigin.z - v17->vLocationWhenUnreachable.z)
                       * (float)(v14->m_vecAbsOrigin.z - v17->vLocationWhenUnreachable.z))) <= 14400.0 )
      return 1;
  }
  v18 = this->m_UnreachableEnts.m_Size;
  if ( v18 > 0 )
  {
    if ( i != v18 - 1 )
    {
      v19 = this->m_UnreachableEnts.m_Memory.m_pMemory;
      v20 = *(_QWORD *)&v19[v18 - 1].hUnreachableEnt.m_Index;
      v21 = (int)&v19[v18 - 1];
      *(_QWORD *)&v19[i].hUnreachableEnt.m_Index = v20;
      *(_QWORD *)&v19[v16].vLocationWhenUnreachable.x = *(_QWORD *)(v21 + 8);
      v19[v16].vLocationWhenUnreachable.z = *(float *)(v21 + 16);
    }
    --this->m_UnreachableEnts.m_Size;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10028A40
// Name: public: virtual class CBaseEntity __near * CAI_BaseNPC::BestEnemy(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__usercall CAI_BaseNPC::BestEnemy@<eax>(CAI_BaseNPC *this@<ecx>, CBaseEntity *a2@<ebx>)
{
  CAI_Enemies *v3; // eax
  AI_EnemyInfo_t *i; // ebx
  unsigned int m_Index; // eax
  CEntInfo *v6; // ecx
  CBaseEntity *m_pEntity; // edi
  Disposition_t v8; // eax
  float m_flAcceptableTimeSeenEnemy; // xmm0_4
  bool v10; // al
  ConVar *m_pParent; // eax
  const char *v12; // eax
  const char *v13; // eax
  const Vector *AbsOrigin; // ebx
  const Vector *v15; // eax
  int v16; // eax
  int v17; // ebx
  ConVar *v18; // eax
  const char *v19; // eax
  CBaseEntity *v20; // ebx
  const char *v21; // eax
  const Vector *v22; // ebx
  const Vector *v23; // eax
  const Vector *v24; // ebx
  const Vector *v25; // eax
  CAI_BaseNPC_vtbl *v26; // edx
  float v27; // xmm1_4
  float (__thiscall *EnemyDistTolerance)(CAI_BaseNPC *); // eax
  double v29; // st7
  double v30; // st7
  ThreeState_t v31; // eax
  CBaseEntity *v32; // ebx
  double v33; // st7
  bool v34; // al
  double v35; // st7
  bool v36; // cl
  bool v37; // al
  ConVar *v38; // eax
  const char *v39; // eax
  const char *v40; // eax
  CAI_BaseNPC_vtbl *v41; // eax
  CAI_Enemies *v42; // eax
  CBaseEntity *v43; // edi
  const char *v44; // eax
  const char *v46; // [esp-8h] [ebp-38h]
  const char *v47; // [esp-8h] [ebp-38h]
  const char *v48; // [esp-8h] [ebp-38h]
  const char *v49; // [esp-8h] [ebp-38h]
  const char *v50; // [esp-8h] [ebp-38h]
  const char *v51; // [esp-8h] [ebp-38h]
  const char *v52; // [esp-8h] [ebp-38h]
  const char *v53; // [esp-8h] [ebp-38h]
  const char *v54; // [esp-8h] [ebp-38h]
  int v55; // [esp-8h] [ebp-38h]
  const char *v56; // [esp-8h] [ebp-38h]
  const char *v57; // [esp-8h] [ebp-38h]
  const char *v58; // [esp-8h] [ebp-38h]
  const char *v59; // [esp-8h] [ebp-38h]
  const char *DebugName; // [esp-8h] [ebp-38h]
  int v62; // [esp-4h] [ebp-34h]
  AIEnemiesIter_t__ *iter; // [esp+8h] [ebp-28h] BYREF
  int iDistSq; // [esp+Ch] [ebp-24h]
  int iBestDistSq; // [esp+10h] [ebp-20h]
  int iBestPriority; // [esp+14h] [ebp-1Ch]
  ThreeState_t fCurSeen; // [esp+18h] [ebp-18h]
  ThreeState_t fCurVisible; // [esp+1Ch] [ebp-14h]
  ThreeState_t fBestVisible; // [esp+20h] [ebp-10h]
  ThreeState_t fBestSeen; // [esp+24h] [ebp-Ch]
  CBaseEntity *pBestEnemy; // [esp+28h] [ebp-8h]
  bool bUnreachable; // [esp+2Dh] [ebp-3h]
  bool bCloser; // [esp+2Eh] [ebp-2h]
  bool bBestUnreachable; // [esp+2Fh] [ebp-1h]

  fBestSeen = TRS_NONE;
  fBestVisible = TRS_NONE;
  pBestEnemy = nullptr;
  iBestDistSq = 0x10000000;
  iBestPriority = -1000;
  bBestUnreachable = true;
  if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(pAI: this, pszFormat: "BestEnemy() {\n");
  v3 = this->GetEnemies(this);
  for ( i = CAI_Enemies::GetFirst(this: v3, pIter: &iter); i != nullptr; i = CAI_Enemies::GetNext(
                                                                               this: v42,
                                                                               pIter: &iter) )
  {
    m_Index = i->hEnemy.m_Index;
    if ( i->hEnemy.m_Index != -1 )
    {
      v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = (CBaseEntity *)v6->m_pEntity;
        if ( v6->m_pEntity != nullptr )
        {
          if ( !m_pEntity->IsAlive(this: (CBaseEntity *)v6->m_pEntity) )
          {
            if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
            {
              DebugName = CBaseEntity::GetDebugName(this: m_pEntity);
              DevMsg(pAI: this, pszFormat: "    %s rejected: dead\n", DebugName);
            }
            goto LABEL_137;
          }
          if ( (m_pEntity->m_fFlags.m_Value & 0x10000) != 0 )
          {
            if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
            {
              v46 = CBaseEntity::GetDebugName(this: m_pEntity);
              DevMsg(pAI: this, pszFormat: "    %s rejected: no target\n", v46);
            }
          }
          else if ( this->m_bIgnoreUnseenEnemies && (float)(gpGlobals->curtime - 0.40000001) > i->timeLastSeen )
          {
            if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
            {
              v47 = CBaseEntity::GetDebugName(this: m_pEntity);
              DevMsg(pAI: this, pszFormat: "    %s rejected: not seen and set to ignore unseen enemies\n", v47);
            }
          }
          else
          {
            v8 = this->IRelationType(this, a2: m_pEntity);
            if ( v8 == D_HT || v8 == D_FR )
            {
              m_flAcceptableTimeSeenEnemy = this->m_flAcceptableTimeSeenEnemy;
              if ( m_flAcceptableTimeSeenEnemy <= 0.0 || m_flAcceptableTimeSeenEnemy <= i->timeLastSeen )
              {
                if ( i->timeValidEnemy <= gpGlobals->curtime )
                {
                  if ( i->bEludedMe )
                  {
                    if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                    {
                      v51 = CBaseEntity::GetDebugName(this: m_pEntity);
                      DevMsg(pAI: this, pszFormat: "    %s rejected: eluded\n", v51);
                    }
                  }
                  else if ( v8 == D_FR && !i->bUnforgettable && i->timeFirstSeen == -3.402823466385289e38 )
                  {
                    if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                    {
                      v52 = CBaseEntity::GetDebugName(this: m_pEntity);
                      DevMsg(pAI: this, pszFormat: "    %s rejected: feared, but never seen\n", v52);
                    }
                  }
                  else if ( this->IsValidEnemy(this, a2: m_pEntity) )
                  {
                    v10 = this->IsUnreachable(this, a2: m_pEntity);
                    bUnreachable = v10;
                    if ( bBestUnreachable )
                    {
                      if ( !v10 )
                      {
                        m_pParent = ai_debug_enemies.m_pParent;
                        if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                        {
                          v12 = CBaseEntity::GetDebugName(this: m_pEntity);
                          DevMsg(pAI: this, pszFormat: "    %s accepted (1)\n", v12);
                          m_pParent = ai_debug_enemies.m_pParent;
                        }
                        if ( pBestEnemy != nullptr && m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
                        {
                          v13 = CBaseEntity::GetDebugName(this: pBestEnemy);
                          DevMsg(pAI: this, pszFormat: "    (%s displaced)\n", v13);
                        }
                        iBestPriority = this->IRelationPriority(this, a2: m_pEntity);
                        AbsOrigin = CBaseEntity::GetAbsOrigin(this);
                        v15 = CBaseEntity::GetAbsOrigin(this: m_pEntity);
                        iBestDistSq = (int)(float)((float)((float)((float)(v15->y - AbsOrigin->y)
                                                                 * (float)(v15->y - AbsOrigin->y))
                                                         + (float)((float)(v15->x - AbsOrigin->x)
                                                                 * (float)(v15->x - AbsOrigin->x)))
                                                 + (float)((float)(v15->z - AbsOrigin->z)
                                                         * (float)(v15->z - AbsOrigin->z)));
                        pBestEnemy = m_pEntity;
                        bBestUnreachable = false;
                        fBestSeen = TRS_NONE;
                        fBestVisible = TRS_NONE;
                        goto LABEL_137;
                      }
                    }
                    else if ( v10 )
                    {
                      if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                      {
                        v54 = CBaseEntity::GetDebugName(this: m_pEntity);
                        DevMsg(pAI: this, pszFormat: "    %s rejected: unreachable\n", v54);
                      }
                      goto LABEL_137;
                    }
                    v16 = ((int (__thiscall *)(CAI_BaseNPC *, CBaseEntity *, CBaseEntity *))this->IRelationPriority)(
                            a1: this,
                            a2: m_pEntity,
                            a3: a2);
                    v17 = iBestPriority;
                    if ( v16 <= iBestPriority )
                    {
                      a2 = m_pEntity;
                      if ( ((int (__thiscall *)(CAI_BaseNPC *))this->IRelationPriority)(a1: this) != v17 )
                      {
                        if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                        {
                          v59 = CBaseEntity::GetDebugName(this: m_pEntity);
                          DevMsg(pAI: this, pszFormat: "    %s rejected: lower priority\n", v59);
                        }
                        goto LABEL_137;
                      }
                      v24 = CBaseEntity::GetAbsOrigin(this);
                      v25 = CBaseEntity::GetAbsOrigin(this: m_pEntity);
                      v26 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
                      v27 = (float)((float)((float)(v25->y - v24->y) * (float)(v25->y - v24->y))
                                  + (float)((float)(v25->x - v24->x) * (float)(v25->x - v24->x)))
                          + (float)((float)(v25->z - v24->z) * (float)(v25->z - v24->z));
                      fCurSeen = iBestDistSq - (int)v27;
                      iDistSq = (int)v27;
                      EnemyDistTolerance = v26->EnemyDistTolerance;
                      *(float *)&fCurSeen = (float)fCurSeen;
                      v29 = ((double (__thiscall *)(CAI_BaseNPC *))EnemyDistTolerance)(a1: this);
                      bCloser = *(float *)&fCurSeen > v29;
                      fCurSeen = TRS_NONE;
                      fCurVisible = TRS_NONE;
                      if ( bCloser )
                      {
                        if ( fBestSeen == TRS_FALSE && *(float *)&fBestVisible == 0.0
                          || (fCurSeen = CAI_Senses::DidSeeEntity(this: this->m_pSenses, pSightEnt: m_pEntity)) == TRS_TRUE
                          || fBestVisible == TRS_NONE
                          && ((fCurVisible = SLODWORD(this->m_pSenses->m_LookDist),
                               v30 = CAI_BaseNPC::EnemyDistance(
                                       this,
                                       a2: (int)m_pEntity,
                                       a3: (int)this,
                                       pEnemy: m_pEntity),
                               *(float *)&fCurVisible <= v30)
                           || !this->FVisible_2(this, a2: m_pEntity, a3: 16449, a4: nullptr)
                            ? (v31 = TRS_FALSE)
                            : (v31 = TRS_TRUE),
                              fCurVisible = v31,
                              v31 == TRS_TRUE) )
                        {
                          v32 = pBestEnemy;
LABEL_123:
                          v38 = ai_debug_enemies.m_pParent;
                          if ( ai_debug_enemies.m_pParent != nullptr
                            && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                          {
                            v39 = CBaseEntity::GetDebugName(this: m_pEntity);
                            DevMsg(pAI: this, pszFormat: "    %s accepted\n", v39);
                            v38 = ai_debug_enemies.m_pParent;
                          }
                          if ( v32 != nullptr && v38 != nullptr && v38->m_Value.m_nValue != 0 )
                          {
                            v40 = CBaseEntity::GetDebugName(this: v32);
                            DevMsg(pAI: this, pszFormat: "    (%s displaced due to distance/visibility)\n", v40);
                          }
                          fBestSeen = fCurSeen;
                          v41 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
                          fBestVisible = fCurVisible;
                          iBestDistSq = iDistSq;
                          iBestPriority = v41->IRelationPriority(this, a2: m_pEntity);
                          pBestEnemy = m_pEntity;
                          bBestUnreachable = bUnreachable;
                          goto LABEL_137;
                        }
                        v32 = pBestEnemy;
                      }
                      else
                      {
                        if ( fBestSeen == TRS_TRUE || fBestVisible == TRS_TRUE )
                          goto LABEL_73;
                        v32 = pBestEnemy;
                        if ( fBestSeen == TRS_NONE )
                          fBestSeen = CAI_Senses::DidSeeEntity(this: this->m_pSenses, pSightEnt: pBestEnemy);
                        if ( fBestSeen == TRS_TRUE )
                          goto LABEL_73;
                      }
                      if ( fBestSeen == TRS_NONE )
                        fBestSeen = CAI_Senses::DidSeeEntity(this: this->m_pSenses, pSightEnt: v32);
                      if ( fBestVisible == TRS_NONE )
                      {
                        fBestVisible = SLODWORD(this->m_pSenses->m_LookDist);
                        v33 = CAI_BaseNPC::EnemyDistance(this, a2: (int)m_pEntity, a3: (int)this, pEnemy: v32);
                        if ( *(float *)&fBestVisible <= v33
                          || (v34 = this->FVisible_2(this, a2: v32, a3: 16449, a4: nullptr),
                              fBestVisible = TRS_TRUE,
                              !v34) )
                        {
                          *(float *)&fBestVisible = 0.0;
                        }
                      }
                      if ( fCurSeen == TRS_NONE )
                        fCurSeen = CAI_Senses::DidSeeEntity(this: this->m_pSenses, pSightEnt: m_pEntity);
                      if ( fCurVisible == TRS_NONE )
                      {
                        fCurVisible = SLODWORD(this->m_pSenses->m_LookDist);
                        v35 = CAI_BaseNPC::EnemyDistance(this, a2: (int)m_pEntity, a3: (int)this, pEnemy: m_pEntity);
                        if ( *(float *)&fCurVisible > v35
                          && this->FVisible_2(this, a2: m_pEntity, a3: 16449, a4: nullptr) )
                        {
                          fCurVisible = TRS_TRUE;
                        }
                        else
                        {
                          *(float *)&fCurVisible = 0.0;
                        }
                      }
                      v36 = fBestSeen == TRS_TRUE || fBestVisible == TRS_TRUE;
                      v37 = fCurSeen == TRS_TRUE || fCurVisible == TRS_TRUE;
                      if ( bCloser )
                      {
                        if ( !v37 && v36 )
                        {
                          if ( ai_debug_enemies.m_pParent != nullptr
                            && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                          {
                            v58 = CBaseEntity::GetDebugName(this: m_pEntity);
                            DevMsg(pAI: this, pszFormat: "    %s rejected: current is father but seen\n", v58);
                          }
                          goto LABEL_137;
                        }
                        goto LABEL_123;
                      }
                      if ( v36 )
                      {
LABEL_73:
                        if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                        {
                          v56 = CBaseEntity::GetDebugName(this: m_pEntity);
                          DevMsg(pAI: this, pszFormat: "    %s rejected: current is closer and seen\n", v56);
                        }
                        goto LABEL_137;
                      }
                      if ( v37 )
                        goto LABEL_123;
                      if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                      {
                        v57 = CBaseEntity::GetDebugName(this: m_pEntity);
                        DevMsg(pAI: this, pszFormat: "    %s rejected: current is closer and neither is seen\n", v57);
                      }
                    }
                    else
                    {
                      v18 = ai_debug_enemies.m_pParent;
                      if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                      {
                        v19 = CBaseEntity::GetDebugName(this: m_pEntity);
                        DevMsg(pAI: this, pszFormat: "    %s accepted\n", v19);
                        v18 = ai_debug_enemies.m_pParent;
                      }
                      v20 = pBestEnemy;
                      if ( pBestEnemy != nullptr && v18 != nullptr && v18->m_Value.m_nValue != 0 )
                      {
                        v62 = iBestPriority;
                        v55 = this->IRelationPriority(this, a2: m_pEntity);
                        v21 = CBaseEntity::GetDebugName(this: v20);
                        DevMsg(pAI: this, pszFormat: "    (%s displaced due to priority, %d > %d )\n", v21, v55, v62);
                      }
                      a2 = m_pEntity;
                      iBestPriority = ((int (__thiscall *)(CAI_BaseNPC *))this->IRelationPriority)(a1: this);
                      v22 = CBaseEntity::GetAbsOrigin(this);
                      v23 = CBaseEntity::GetAbsOrigin(this: m_pEntity);
                      iBestDistSq = (int)(float)((float)((float)((float)(v23->y - v22->y) * (float)(v23->y - v22->y))
                                                       + (float)((float)(v23->x - v22->x) * (float)(v23->x - v22->x)))
                                               + (float)((float)(v23->z - v22->z) * (float)(v23->z - v22->z)));
                      pBestEnemy = m_pEntity;
                      bBestUnreachable = bUnreachable;
                      fBestSeen = TRS_NONE;
                      fBestVisible = TRS_NONE;
                    }
                  }
                  else if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                  {
                    v53 = CBaseEntity::GetDebugName(this: m_pEntity);
                    DevMsg(pAI: this, pszFormat: "    %s rejected: not valid\n", v53);
                  }
                }
                else if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
                {
                  v50 = CBaseEntity::GetDebugName(this: m_pEntity);
                  DevMsg(pAI: this, pszFormat: "    %s rejected: not yet valid\n", v50);
                }
              }
              else if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
              {
                v49 = CBaseEntity::GetDebugName(this: m_pEntity);
                DevMsg(pAI: this, pszFormat: "    %s rejected: old\n", v49);
              }
            }
            else if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
            {
              v48 = CBaseEntity::GetDebugName(this: m_pEntity);
              DevMsg(pAI: this, pszFormat: "    %s rejected: no hate/fear\n", v48);
            }
          }
        }
      }
    }
LABEL_137:
    v42 = this->GetEnemies(this);
  }
  if ( ai_debug_enemies.m_pParent == nullptr || ai_debug_enemies.m_pParent->m_Value.m_nValue == 0 )
    return pBestEnemy;
  v43 = pBestEnemy;
  v44 = CBaseEntity::GetDebugName(this: pBestEnemy);
  DevMsg(pAI: this, pszFormat: "} == %s\n", v44);
  return v43;
}

//------------------------------------------------------------------------------
// Address: 0x100292E0
// Name: public: virtual void CAI_BaseNPC::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CAI_BaseNPC::DrawDebugGeometryOverlays(
        CAI_BaseNPC *this@<ecx>,
        AI_EnemyInfo_t *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  CAI_BaseNPC_vtbl *v5; // edi
  CBaseCombatWeapon *ActiveWeapon; // eax
  int m_debugOverlays; // eax
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CBaseEntity *); // eax
  CAI_BaseNPC *LocalPlayer; // eax
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  float *v11; // eax
  CAI_BaseNPC_vtbl *v12; // edx
  float v13; // xmm0_4
  const Vector *(__thiscall *v14)(CBaseEntity *); // eax
  const Vector *v15; // eax
  int v16; // eax
  Hull_t m_eHull; // ecx
  CAI_Navigator *m_pNavigator; // edx
  const Vector *Position; // eax
  double m_flFieldOfView; // xmm0_8
  Vector *(__thiscall *EyeDirection2D)(CBaseCombatCharacter *, Vector *); // edx
  double v22; // xmm0_8
  double x; // xmm0_8
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float v25; // xmm3_4
  float *v26; // eax
  const Vector *v27; // eax
  Vector *(__thiscall *v28)(CBaseEntity *, Vector *); // edx
  float *v29; // eax
  Vector *(__thiscall *v30)(CBaseEntity *, Vector *); // edx
  const Vector *v31; // eax
  Vector *(__thiscall *v32)(CBaseEntity *, Vector *); // edx
  float *v33; // eax
  Vector *(__thiscall *v34)(CBaseEntity *, Vector *); // edx
  const Vector *v35; // eax
  Vector *(__thiscall *v36)(CBaseEntity *, Vector *); // edx
  const Vector *v37; // eax
  int m_Size; // edi
  float v39; // ecx
  int v40; // edx
  CAI_BaseNPC *v41; // eax
  Disposition_t v42; // eax
  int v43; // edi
  CBasePlayer *v44; // edi
  Disposition_t v45; // eax
  CAI_Enemies *v46; // eax
  AI_EnemyInfo_t *First; // eax
  unsigned int m_Index; // ecx
  int v49; // eax
  CEntInfo *v50; // edx
  unsigned int v51; // ecx
  int v52; // eax
  bool v53; // zf
  CEntInfo *v54; // eax
  IHandleEntity *v55; // ecx
  CBaseEntity *v56; // edi
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // eax
  float v58; // ecx
  float v59; // xmm0_4
  float v60; // xmm1_4
  __int128 v61; // xmm0
  Vector *(__thiscall *v62)(CBaseEntity *, Vector *); // edx
  float *v63; // eax
  float v64; // xmm3_4
  int v65; // edi
  float v66; // xmm1_4
  float v67; // xmm4_4
  float v68; // xmm5_4
  int m_hScope; // edi
  const Vector *v70; // eax
  CAI_Enemies *v71; // eax
  int v72; // eax
  const Vector *v73; // eax
  unsigned int v74; // ecx
  int v75; // eax
  CEntInfo *v76; // edx
  unsigned int v77; // ecx
  int v78; // eax
  CEntInfo *v79; // eax
  IHandleEntity *m_pEntity; // ecx
  const Vector *v81; // eax
  const Vector *v82; // [esp+3Ch] [ebp-244h]
  int v83; // [esp+40h] [ebp-240h]
  int v84; // [esp+40h] [ebp-240h]
  int v85; // [esp+40h] [ebp-240h]
  int v86; // [esp+44h] [ebp-23Ch]
  int v87; // [esp+48h] [ebp-238h]
  const char *yaw; // [esp+50h] [ebp-230h]
  long double v89; // [esp+54h] [ebp-22Ch]
  int v90; // [esp+54h] [ebp-22Ch]
  int v91; // [esp+58h] [ebp-228h]
  long double v92; // [esp+5Ch] [ebp-224h]
  long double v93; // [esp+5Ch] [ebp-224h]
  char v94[12]; // [esp+64h] [ebp-21Ch] BYREF
  char debugText[255]; // [esp+70h] [ebp-210h] BYREF
  _BYTE info_24[76]; // [esp+188h] [ebp-F8h] OVERLAPPED
  _BYTE v97[12]; // [esp+1DCh] [ebp-A4h] BYREF
  Vector v98; // [esp+1E8h] [ebp-98h] BYREF
  Vector v99; // [esp+1F4h] [ebp-8Ch] BYREF
  Vector v100; // [esp+200h] [ebp-80h] BYREF
  Vector v101; // [esp+20Ch] [ebp-74h] BYREF
  Vector v102; // [esp+218h] [ebp-68h] BYREF
  Vector drawPos; // [esp+224h] [ebp-5Ch] BYREF
  Vector v104; // [esp+230h] [ebp-50h] BYREF
  Vector vEnemyFacing; // [esp+23Ch] [ebp-44h] BYREF
  Vector sideVec; // [esp+248h] [ebp-38h] BYREF
  Vector vLeftDir; // [esp+254h] [ebp-2Ch] BYREF
  AIEnemiesIter_t__ *iter; // [esp+260h] [ebp-20h]
  __int128 eyePos; // [esp+264h] [ebp-1Ch] OVERLAPPED BYREF
  AI_EnemyInfo_t *eMemory; // [esp+274h] [ebp-Ch]
  float b; // [esp+278h] [ebp-8h]
  float retaddr; // [esp+280h] [ebp+0h]

  eMemory = a2;
  b = retaddr;
  HIDWORD(v89) = a4;
  LODWORD(v89) = a3;
  if ( (this->m_debugOverlays & 0x10000) != 0 )
  {
    CAI_BaseNPC::VacateStrategySlot(this);
    v5 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    v5->Weapon_Drop(this, a2: ActiveWeapon, a3: nullptr, a4: nullptr);
    if ( this->m_iHealth.m_Value != 0 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      this->m_iHealth.m_Value = 0;
    }
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  }
  m_debugOverlays = this->m_debugOverlays;
  if ( (m_debugOverlays & 0x800000) != 0 )
  {
    CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&debugText[244]);
    GetRefEHandle = this->GetRefEHandle;
    *(float *)&info_24[12] = (float)this->m_iHealth.m_Value;
    *(_DWORD *)&info_24[4] = GetRefEHandle(this)->m_Index;
    if ( gpGlobals->maxClients == 1 )
      LocalPlayer = (CAI_BaseNPC *)UTIL_GetLocalPlayer();
    else
      LocalPlayer = this;
    if ( LocalPlayer != nullptr )
      *(_DWORD *)info_24 = LocalPlayer->GetRefEHandle(this: LocalPlayer)->m_Index;
    else
      *(_DWORD *)info_24 = -1;
    this->m_debugOverlays &= ~0x800000u;
    *(_DWORD *)&info_24[24] = 0;
    CBaseEntity::TakeDamage(this, inputInfo: (const CTakeDamageInfo *)&debugText[244]);
  }
  else
  {
    if ( (m_debugOverlays & 0x4000) != 0 )
    {
      CAI_Navigator::DrawDebugRouteOverlay(this: this->m_pNavigator);
      if ( this->IsMoving(this) )
      {
        UTIL_YawToVector(result: &sideVec, yaw: this->m_pMotor->m_IdealYaw);
        vLeftDir.x = NAI_Hull::Width(id: this->m_eHull);
        WorldSpaceCenter = this->WorldSpaceCenter;
        vLeftDir.y = (float)(sideVec.x * vLeftDir.x) * 0.5;
        vLeftDir.z = (float)(sideVec.y * vLeftDir.x) * 0.5;
        *(float *)&iter = (float)(sideVec.z * vLeftDir.x) * 0.5;
        v11 = (float *)WorldSpaceCenter(this);
        v12 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v104.x = vLeftDir.y + *v11;
        v104.y = v11[1] + vLeftDir.z;
        v13 = v11[2] + *(float *)&iter;
        v14 = v12->WorldSpaceCenter;
        v104.z = v13;
        v15 = v14(this);
        NDebugOverlay::Line(origin: v15, target: &v104, r: 255, g: 255, b: 255, noDepthTest: true, duration: 0.0);
      }
    }
    if ( (CAI_BaseNPC::m_nDebugBits & 1) == 0
      && (CAI_BaseNPC::IsCurSchedule(this, schedId: 72, fIdeal: true)
       || CAI_BaseNPC::IsCurSchedule(this, schedId: 73, fIdeal: true)) )
    {
      sideVec.x = 5.0;
      sideVec.y = 5.0;
      sideVec.z = 5.0;
      vLeftDir.y = -5.0;
      vLeftDir.z = -5.0;
      *(float *)&iter = -5.0;
      NDebugOverlay::Box(
        origin: &this->m_vecLastPosition,
        mins: (Vector *)&vLeftDir.y,
        maxs: &sideVec,
        r: 255,
        g: 0,
        b: 255,
        a: 0,
        flDuration: 0.0);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      NDebugOverlay::HorzArrow(
        startPos: &this->m_vecAbsOrigin,
        endPos: &this->m_vecLastPosition,
        width: 16.0,
        r: 255,
        g: 0,
        b: 255,
        a: 64,
        noDepthTest: true,
        flDuration: 0.0);
    }
    if ( (this->m_debugOverlays & 0x1000) != 0
      && (ai_no_select_box.m_pParent == nullptr || ai_no_select_box.m_pParent->m_Value.m_nValue == 0) )
    {
      NDebugOverlay::EntityBounds(pEntity: this, r: 255, g: 0, b: 0, a: 20, flDuration: 0.0);
    }
    if ( (this->m_debugOverlays & 0x2000) != 0 )
    {
      v16 = CAI_Pathfinder::NearestNodeToNPC(this: this->m_pPathfinder);
      if ( v16 != -1 )
      {
        m_pNavigator = this->m_pNavigator;
        m_eHull = this->m_eHull;
        sideVec.x = 10.0;
        sideVec.y = 10.0;
        sideVec.z = 10.0;
        vLeftDir.y = -10.0;
        vLeftDir.z = -10.0;
        *(float *)&iter = -10.0;
        Position = CAI_Node::GetPosition(
                     this: m_pNavigator->m_pAINetwork->m_pAInode[v16],
                     result: &drawPos,
                     hull: m_eHull);
        NDebugOverlay::Box(
          origin: Position,
          mins: (Vector *)&vLeftDir.y,
          maxs: &sideVec,
          r: 255,
          g: 255,
          b: 255,
          a: 0,
          flDuration: 0.0);
      }
    }
    if ( (this->m_debugOverlays & 0x400000) != 0 )
    {
      m_flFieldOfView = this->m_flFieldOfView;
      __libm_sse2_acos(x: v89);
      EyeDirection2D = this->EyeDirection2D;
      *(float *)&m_flFieldOfView = m_flFieldOfView;
      LODWORD(eyePos) = LODWORD(m_flFieldOfView);
      ((void (__thiscall *)(CAI_BaseNPC *, Vector *, int, int))EyeDirection2D)(
        a1: this,
        a2: &vEnemyFacing,
        a3: v90,
        a4: v91);
      HIDWORD(eyePos) = (char *)&eyePos + 4;
      *((float *)&eyePos + 1) = cos(*(float *)&eyePos);
      *((float *)&eyePos + 2) = sin(*(float *)&eyePos);
      sideVec.x = (float)(vEnemyFacing.x * *((float *)&eyePos + 1)) - (float)(vEnemyFacing.y * *((float *)&eyePos + 2));
      sideVec.y = (float)(vEnemyFacing.x * *((float *)&eyePos + 2)) + (float)(vEnemyFacing.y * *((float *)&eyePos + 1));
      LODWORD(vLeftDir.x) = eyePos ^ _mask__NegFloat_;
      v22 = COERCE_FLOAT(eyePos ^ _mask__NegFloat_);
      __libm_sse2_sin(x: v92);
      *(float *)&v22 = v22;
      DWORD2(eyePos) = LODWORD(v22);
      x = vLeftDir.x;
      __libm_sse2_cos(x: v93);
      EyePosition = this->EyePosition;
      v25 = x;
      v104.y = (float)(vEnemyFacing.x * *((float *)&eyePos + 2)) + (float)(vEnemyFacing.y * v25);
      vLeftDir.y = sideVec.x * 200.0;
      vLeftDir.z = sideVec.y * 200.0;
      *((float *)&eyePos + 1) = v25;
      v104.x = (float)(vEnemyFacing.x * v25) - (float)(vEnemyFacing.y * *((float *)&eyePos + 2));
      vLeftDir.x = vEnemyFacing.z * 200.0;
      *(float *)&iter = vEnemyFacing.z * 200.0;
      v26 = (float *)EyePosition(this, result: &drawPos);
      sideVec.x = *v26 + vLeftDir.y;
      sideVec.y = v26[1] + vLeftDir.z;
      sideVec.z = v26[2] + *(float *)&iter;
      v27 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))this->EyePosition)(a1: this);
      NDebugOverlay::VertArrow(
        startPos: v27,
        endPos: &v102,
        width: COERCE_FLOAT(&sideVec),
        r: 1115684864,
        g: 255,
        b: 0,
        a: 0,
        noDepthTest: 50,
        flDuration: 0.0);
      v28 = this->EyePosition;
      vLeftDir.y = v104.x * 200.0;
      vLeftDir.z = v104.y * 200.0;
      iter = (AIEnemiesIter_t__ *)LODWORD(vLeftDir.x);
      v29 = (float *)((int (__thiscall *)(CAI_BaseNPC *, Vector *, _DWORD))v28)(a1: this, a2: &drawPos, a3: 0);
      v30 = this->EyePosition;
      sideVec.x = *v29 + vLeftDir.y;
      sideVec.y = v29[1] + vLeftDir.z;
      sideVec.z = v29[2] + *(float *)&iter;
      v31 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))v30)(a1: this);
      NDebugOverlay::VertArrow(
        startPos: v31,
        endPos: &v102,
        width: COERCE_FLOAT(&sideVec),
        r: 1115684864,
        g: 255,
        b: 0,
        a: 0,
        noDepthTest: 50,
        flDuration: 0.0);
      v32 = this->EyePosition;
      vLeftDir.y = vEnemyFacing.x * 100.0;
      vLeftDir.z = vEnemyFacing.y * 100.0;
      *(float *)&iter = vEnemyFacing.z * 100.0;
      v33 = (float *)((int (__thiscall *)(CAI_BaseNPC *, Vector *, _DWORD))v32)(a1: this, a2: &drawPos, a3: 0);
      v34 = this->EyePosition;
      sideVec.x = vLeftDir.y + *v33;
      sideVec.y = v33[1] + vLeftDir.z;
      sideVec.z = v33[2] + *(float *)&iter;
      v35 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))v34)(a1: this);
      NDebugOverlay::VertArrow(
        startPos: v35,
        endPos: &v102,
        width: COERCE_FLOAT(&sideVec),
        r: 1090519040,
        g: 0,
        b: 255,
        a: 0,
        noDepthTest: 50,
        flDuration: 0.0);
      v36 = this->EyePosition;
      sideVec.x = 2.0;
      sideVec.y = 2.0;
      sideVec.z = 2.0;
      vLeftDir.y = -2.0;
      vLeftDir.z = -2.0;
      *(float *)&iter = -2.0;
      v89 = 0.0;
      v37 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))v36)(a1: this);
      NDebugOverlay::Box(
        origin: v37,
        mins: &drawPos,
        maxs: (Vector *)&vLeftDir.y,
        r: (int)&sideVec,
        g: 0,
        b: 255,
        a: 0,
        flDuration: COERCE_FLOAT(128));
    }
    if ( (this->m_debugOverlays & 0x20000000) != 0 )
    {
      m_Size = g_AI_Manager.m_AIs.m_Size;
      LODWORD(v39) = g_AI_Manager.m_AIs.m_Size != 0 ? g_AI_Manager.m_AIs.m_Memory.m_pMemory : nullptr;
      v40 = 0;
      eyePos = 0u;
      for ( vLeftDir.x = v39; v40 < m_Size; HIDWORD(eyePos) = v40 )
      {
        v41 = *(CAI_BaseNPC **)(LODWORD(v39) + 4 * v40);
        if ( v41 != nullptr && v41 != this )
        {
          v42 = this->IRelationType(this, a2: v41);
          UTIL_GetDebugColorForRelationship(
            nRelationship: v42,
            r: (int *)&eyePos,
            g: (int *)&eyePos + 2,
            b: (int *)&eyePos + 1);
          v43 = *(_DWORD *)(LODWORD(vLeftDir.x) + 4 * HIDWORD(eyePos));
          if ( (*(_DWORD *)(v43 + 196) & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: *(CBaseEntity **)(LODWORD(vLeftDir.x) + 4 * HIDWORD(eyePos)));
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this);
          NDebugOverlay::HorzArrow(
            startPos: &this->m_vecAbsOrigin,
            endPos: (const Vector *)(v43 + 460),
            width: 16.0,
            r: eyePos,
            g: SDWORD2(eyePos),
            b: SDWORD1(eyePos),
            a: 64,
            noDepthTest: true,
            flDuration: 0.0);
          m_Size = g_AI_Manager.m_AIs.m_Size;
          v39 = vLeftDir.x;
          v40 = HIDWORD(eyePos);
        }
        ++v40;
      }
      HIDWORD(eyePos) = 1;
      if ( gpGlobals->maxClients >= 1 )
      {
        do
        {
          v44 = UTIL_PlayerByIndex(playerIndex: SHIDWORD(eyePos));
          if ( v44 != nullptr )
          {
            v45 = this->IRelationType(this, a2: v44);
            UTIL_GetDebugColorForRelationship(
              nRelationship: v45,
              r: (int *)&eyePos,
              g: (int *)&eyePos + 2,
              b: (int *)&eyePos + 1);
            if ( (v44->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v44);
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this);
            NDebugOverlay::HorzArrow(
              startPos: &this->m_vecAbsOrigin,
              endPos: &v44->m_vecAbsOrigin,
              width: 16.0,
              r: eyePos,
              g: SDWORD2(eyePos),
              b: SDWORD1(eyePos),
              a: 64,
              noDepthTest: true,
              flDuration: 0.0);
          }
          ++HIDWORD(eyePos);
        }
        while ( SHIDWORD(eyePos) <= gpGlobals->maxClients );
      }
    }
    if ( (this->m_debugOverlays & 0x20000) != 0 )
    {
      v46 = this->GetEnemies(this);
      First = CAI_Enemies::GetFirst(this: v46, pIter: (AIEnemiesIter_t__ **)&vLeftDir);
      for ( DWORD1(eyePos) = First; First != nullptr; DWORD1(eyePos) = First )
      {
        m_Index = First->hEnemy.m_Index;
        if ( First->hEnemy.m_Index != -1 )
        {
          v49 = (unsigned __int16)m_Index;
          v50 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
          v51 = HIWORD(m_Index);
          if ( v50->m_SerialNumber == v51 && v50->m_pEntity != nullptr )
          {
            v52 = v49;
            v53 = g_pEntityList->m_EntPtrArray[v52].m_SerialNumber == v51;
            v54 = &g_pEntityList->m_EntPtrArray[v52];
            v55 = v53 ? v54->m_pEntity : nullptr;
            v56 = (CBaseEntity *)((int (__thiscall *)(IHandleEntity *))v55->__vftable[25].dtr_IHandleEntity)(a1: v55);
            if ( v56 != nullptr )
            {
              GetEnemy_2 = this->GetEnemy_2;
              v94[0] = 0;
              if ( v56 == (CBaseEntity *)((int (__thiscall *)(CAI_BaseNPC *, _DWORD, _DWORD))GetEnemy_2)(
                                           a1: this,
                                           a2: LODWORD(v89),
                                           a3: HIDWORD(v89)) )
              {
                V_strncat(pDest: v94, pSrc: "Current Enemy", destBufferSize: 0xFFu, max_chars_to_copy: -1);
              }
              else
              {
                if ( v56 == CAI_BaseNPC::GetTarget(this) )
                  yaw = "Current Target";
                else
                  yaw = "Other Memory";
                V_strncat(pDest: v94, pSrc: yaw, destBufferSize: 0xFFu, max_chars_to_copy: -1);
              }
              HIDWORD(v89) = v56;
              if ( ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *))this->IsUnreachable)(a1: this) != 0 )
                V_strncat(pDest: v94, pSrc: " (Unreachable)", destBufferSize: 0xFFu, max_chars_to_copy: -1);
              if ( *(_BYTE *)(DWORD1(eyePos) + 57) != 0 )
                V_strncat(pDest: v94, pSrc: " (Eluded)", destBufferSize: 0xFFu, max_chars_to_copy: -1);
              LODWORD(v89) = v56;
              if ( ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *))this->IsUnreachable)(a1: this) != 0 )
              {
                LODWORD(eyePos) = 0;
                *((_QWORD *)&eyePos + 1) = 0x437F000000000000LL;
              }
              else if ( *(_BYTE *)(DWORD1(eyePos) + 57) != 0 )
              {
                LODWORD(eyePos) = 0;
                *((_QWORD *)&eyePos + 1) = 1132396544;
              }
              else if ( v56 == this->GetEnemy_2(this) )
              {
                LODWORD(eyePos) = 1132396544;
                *((_QWORD *)&eyePos + 1) = 0;
              }
              else if ( v56 == CAI_BaseNPC::GetTarget(this) )
              {
                LODWORD(eyePos) = 1132396544;
                *((_QWORD *)&eyePos + 1) = 1132396544;
              }
              else
              {
                LODWORD(eyePos) = 1132396544;
                *((_QWORD *)&eyePos + 1) = 0x42C8000042C80000LL;
              }
              v58 = *(float *)(DWORD1(eyePos) + 12);
              *(_QWORD *)&v102.x = *(_QWORD *)(DWORD1(eyePos) + 4);
              v102.z = v58;
              NDebugOverlay::Text(origin: &v102, text: v94, bViewCheck: false, duration: 0.0);
              if ( !v56->IsPlayer(this: v56) )
                goto LABEL_82;
              if ( (v56->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: v56);
              v59 = *(float *)(DWORD1(eyePos) + 4) - v56->m_vecAbsOrigin.x;
              v60 = (float)((float)((float)(*(float *)(DWORD1(eyePos) + 8) - v56->m_vecAbsOrigin.y)
                                  * (float)(*(float *)(DWORD1(eyePos) + 8) - v56->m_vecAbsOrigin.y))
                          + (float)((float)(*(float *)(DWORD1(eyePos) + 12) - v56->m_vecAbsOrigin.z)
                                  * (float)(*(float *)(DWORD1(eyePos) + 12) - v56->m_vecAbsOrigin.z)))
                  + (float)(v59 * v59);
              v61 = 0;
              *(float *)&v61 = fsqrt(v60);
              *(_OWORD *)&info_24[60] = v61;
              if ( *(float *)&v61 < 10.0 )
              {
                ((void (__thiscall *)(CBaseEntity *, Vector *))v56->__vftable[1].GetResponseSystem)(a1: v56, a2: &v104);
                v62 = v56->EyePosition;
                sideVec.x = v104.x * 10.0;
                sideVec.y = v104.y * 10.0;
                sideVec.z = v104.z * 10.0;
                v63 = (float *)v62(this: v56, result: (Vector *)v97);
                v64 = sideVec.x + *v63;
                v65 = (int)*((float *)&eyePos + 2);
                v66 = (float)(v104.y * 2.0) - (float)(v104.z * 0.0);
                vEnemyFacing.y = (float)(v104.z * 0.0) - (float)(v104.x * 2.0);
                vEnemyFacing.z = (float)(v104.x * 0.0) - (float)(v104.y * 0.0);
                vLeftDir.y = v64;
                v67 = v63[1] + sideVec.y;
                v101.x = v64 - v66;
                drawPos.y = v67 - vEnemyFacing.y;
                v101.y = v67 - vEnemyFacing.y;
                vLeftDir.z = v67;
                v68 = v63[2] + sideVec.z;
                v100.z = (float)(vEnemyFacing.z + v68) + 2.0;
                vEnemyFacing.x = v66;
                *(float *)&iter = v68;
                v101.z = (float)(v68 - vEnemyFacing.z) - 2.0;
                v100.x = v64 + v66;
                v100.y = vEnemyFacing.y + v67;
                NDebugOverlay::Line(
                  origin: &v100,
                  target: &v101,
                  r: (int)*(float *)&eyePos,
                  g: (int)*((float *)&eyePos + 3),
                  b: (int)*((float *)&eyePos + 2),
                  noDepthTest: false,
                  duration: 0.0);
                v98.z = (float)(*(float *)&iter - vEnemyFacing.z) + 2.0;
                v98.x = vLeftDir.y - vEnemyFacing.x;
                v98.y = vLeftDir.z - vEnemyFacing.y;
                v99.x = vLeftDir.y + vEnemyFacing.x;
                v99.y = vEnemyFacing.y + vLeftDir.z;
                v99.z = (float)(vEnemyFacing.z + *(float *)&iter) - 2.0;
                NDebugOverlay::Line(
                  origin: &v99,
                  target: &v98,
                  r: (int)*(float *)&eyePos,
                  g: (int)*((float *)&eyePos + 3),
                  b: v65,
                  noDepthTest: false,
                  duration: 0.0);
                NDebugOverlay::Text(origin: (Vector *)&vLeftDir.y, text: v94, bViewCheck: false, duration: 0.0);
              }
              else
              {
LABEL_82:
                m_hScope = (int)v56[1].m_ScriptScope.m_hScope;
                v87 = (int)*((float *)&eyePos + 2);
                v86 = (int)*((float *)&eyePos + 3);
                v83 = (int)*(float *)&eyePos;
                v82 = NAI_Hull::Maxs(id: m_hScope);
                v70 = NAI_Hull::Mins(id: m_hScope);
                NDebugOverlay::Cross3D(
                  position: &v102,
                  mins: v70,
                  maxs: v82,
                  r: v83,
                  g: v86,
                  b: v87,
                  noDepthTest: false,
                  fDuration: 0.0);
              }
            }
          }
        }
        v71 = this->GetEnemies(this);
        First = CAI_Enemies::GetNext(this: v71, pIter: (AIEnemiesIter_t__ **)&vLeftDir);
      }
    }
    if ( (this->m_debugOverlays & 0x200000) != 0 )
    {
      if ( this->GetEnemy_2(this) != nullptr )
      {
        v72 = ((int (__thiscall *)(CAI_BaseNPC *, _DWORD, _DWORD))this->GetEnemy_2)(
                a1: this,
                a2: LODWORD(v89),
                a3: HIDWORD(v89));
        v84 = (*(int (__thiscall **)(int))(*(_DWORD *)v72 + 504))(a1: v72);
        v73 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))this->EyePosition)(a1: this);
        NDebugOverlay::Line(
          origin: v73,
          target: &drawPos,
          r: v84,
          g: (int)v97,
          b: 255,
          noDepthTest: false,
          duration: 0.0);
      }
      v74 = this->m_hTargetEnt.m_Index;
      if ( v74 != -1 )
      {
        v75 = (unsigned __int16)v74;
        v76 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v74];
        v77 = HIWORD(v74);
        if ( v76->m_SerialNumber == v77 && v76->m_pEntity != nullptr )
        {
          v78 = v75;
          v53 = g_pEntityList->m_EntPtrArray[v78].m_SerialNumber == v77;
          v79 = &g_pEntityList->m_EntPtrArray[v78];
          if ( v53 )
            m_pEntity = v79->m_pEntity;
          else
            m_pEntity = nullptr;
          v85 = ((int (__stdcall *)(_BYTE *, _DWORD))m_pEntity->__vftable[42].dtr_IHandleEntity)(a1: v97, a2: 0);
          v81 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))this->EyePosition)(a1: this);
          NDebugOverlay::Line(origin: v81, target: &drawPos, r: v85, g: 0, b: 255, noDepthTest: true, duration: 0.0);
        }
      }
    }
    CAI_Pathfinder::DrawDebugGeometryOverlays(this: this->m_pPathfinder, npcDebugOverlays: this->m_debugOverlays);
    CBaseEntity::DrawDebugGeometryOverlays(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A240
// Name: public: void CAI_BaseNPC::SetEnemy(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetEnemy(CAI_BaseNPC *this, CBaseEntity *pEnemy, bool bSetCondNewEnemy)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v6; // eax
  CBaseEntity *v7; // ecx
  CAI_ClassScheduleIdSpace *v8; // eax
  int v9; // eax
  int v10; // edi
  CAI_ClassScheduleIdSpace *v11; // eax
  int v12; // eax
  int v13; // eax

  m_Index = this->m_hEnemy.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != pEnemy )
  {
    this->ClearAttackConditions(this);
    CAI_BaseNPC::VacateStrategySlot(this);
    this->m_GiveUpOnDeadEnemyTimer.m_fIsRunning = false;
    if ( pEnemy != nullptr && bSetCondNewEnemy )
      CAI_BaseNPC::SetCondition(this, iCondition: 26);
    v6 = this->m_hEnemy.m_Index;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      v7 = nullptr;
    else
      v7 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    this->OnEnemyChanged(this, a2: v7, a3: pEnemy);
  }
  if ( pEnemy != nullptr )
    this->m_hEnemy.m_Index = pEnemy->GetRefEHandle(this: pEnemy)->m_Index;
  else
    this->m_hEnemy.m_Index = -1;
  this->m_flTimeEnemyAcquired = gpGlobals->curtime;
  *(_QWORD *)&this->m_LastShootAccuracy = 3212836864LL;
  this->m_TotalHits = 0;
  if ( pEnemy == nullptr )
  {
    v8 = this->GetClassScheduleIdSpace(this);
    v9 = CAI_LocalIdSpace::LocalToGlobal(this: &v8->m_ConditionIds, localID: 26);
    if ( v9 != -1 )
    {
      v10 = v9 - 1000000000;
      if ( v9 != 999999999 )
      {
        v11 = this->GetClassScheduleIdSpace(this);
        v12 = CAI_LocalIdSpace::LocalToGlobal(this: &v11->m_ConditionIds, localID: 26);
        if ( v12 != -1 )
        {
          v13 = v12 - 1000000000;
          if ( v13 != -1 && ((1 << (v13 & 0x1F)) & this->m_Conditions.m_Ints[v13 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 26);
        }
        this->m_Conditions.m_Ints[v10 >> 5] &= ~(1 << (v10 & 0x1F));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A3E0
// Name: public: virtual bool CAI_BaseNPC::ShouldChooseNewEnemy(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::ShouldChooseNewEnemy(CAI_BaseNPC *this)
{
  CBaseEntity *v2; // edi
  int m_serial; // ecx
  CBaseEntity *(__thiscall *GetEnemy)(CBaseEntity *); // eax
  CAI_Enemies *v5; // eax
  CRandStopwatch *p_m_GiveUpOnDeadEnemyTimer; // ecx
  CAI_Enemies *v8; // eax
  AI_EnemyInfo_t *v9; // edi
  CBaseEntity *v10; // [esp-4h] [ebp-10h]

  v2 = this->GetEnemy_2(this);
  if ( v2 == nullptr )
    goto LABEL_35;
  if ( this->GetEnemies(this)->m_serial != this->m_EnemiesSerialNumber )
    return 1;
  m_serial = this->GetEnemies(this)->m_serial;
  GetEnemy = this->GetEnemy;
  this->m_EnemiesSerialNumber = m_serial;
  v10 = GetEnemy(this);
  v5 = this->GetEnemies(this);
  if ( CAI_Enemies::HasEludedMe(this: v5, pEnemy: v10)
    || this->IRelationType(this, a2: v2) != D_HT && this->IRelationType(this, a2: v2) != D_FR
    || !this->IsValidEnemy(this, a2: v2) )
  {
    if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
    {
      DevMsg(pAI: this, pszFormat: "ShouldChooseNewEnemy() --> true (1)\n");
      return 1;
    }
    return 1;
  }
  if ( CAI_BaseNPC::HasCondition(this, iCondition: 7)
    || CAI_BaseNPC::HasCondition(this, iCondition: 9)
    || CAI_BaseNPC::HasCondition(this, iCondition: 34)
    || CAI_BaseNPC::HasCondition(this, iCondition: 8) )
  {
    if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
    {
      DevMsg(pAI: this, pszFormat: "ShouldChooseNewEnemy() --> true (2)\n");
      return 1;
    }
    return 1;
  }
  if ( !v2->IsAlive(this: v2) )
  {
    p_m_GiveUpOnDeadEnemyTimer = &this->m_GiveUpOnDeadEnemyTimer;
    if ( this->m_GiveUpOnDeadEnemyTimer.m_fIsRunning )
    {
      if ( CStopwatchBase::Expired(this: p_m_GiveUpOnDeadEnemyTimer) )
      {
        if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
        {
          DevMsg(pAI: this, pszFormat: "ShouldChooseNewEnemy() --> true (3)\n");
          return 1;
        }
        return 1;
      }
    }
    else
    {
      CRandStopwatch::Start(this: p_m_GiveUpOnDeadEnemyTimer);
    }
  }
  v8 = this->GetEnemies(this);
  v9 = CAI_Enemies::Find(this: v8, pEntity: v2, bTryDangerMemory: false);
  if ( CSimpleSimTimer::Expired(this: &this->m_FailChooseEnemyTimer) )
  {
    this->m_FailChooseEnemyTimer.m_next = gpGlobals->curtime + 1.5;
    if ( CAI_BaseNPC::HasCondition(this, iCondition: 35) )
      return 1;
    if ( v9 == nullptr )
    {
LABEL_35:
      if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
        DevMsg(pAI: this, pszFormat: "ShouldChooseNewEnemy() --> true (4)\n");
      this->m_EnemiesSerialNumber = this->GetEnemies(this)->m_serial;
      return 1;
    }
    if ( v9->timeAtFirstHand == -3.402823466385289e38 || (float)(gpGlobals->curtime - v9->timeLastSeen) > 10.0 )
      return 1;
  }
  if ( v9 == nullptr || gpGlobals->curtime <= v9->timeValidEnemy )
    goto LABEL_35;
  if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(pAI: this, pszFormat: "ShouldChooseNewEnemy() --> false\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A670
// Name: public: bool CAI_BaseNPC::ChooseEnemy(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::ChooseEnemy(CAI_BaseNPC *this)
{
  CBaseEntity *v2; // edi
  int m_afMemory; // eax
  bool IsCustomInterruptConditionSet; // bl
  CAI_Enemies *v5; // eax
  ConVar *m_pParent; // eax
  CAI_Schedule *m_pSchedule; // eax
  bool (__thiscall *ShouldChooseNewEnemy)(CAI_BaseNPC *); // edx
  CBaseEntity *v10; // ebx
  const char *DebugName; // eax
  CAI_ClassScheduleIdSpace *v12; // eax
  int v13; // eax
  int v14; // eax
  const char *fDelay; // [esp+0h] [ebp-1Ch]
  bool fEnemyWasPlayer; // [esp+17h] [ebp-5h]
  bool fHadEnemy; // [esp+18h] [ebp-4h]
  bool fEnemyEluded; // [esp+19h] [ebp-3h]
  bool fEnemyWentNull; // [esp+1Ah] [ebp-2h]
  bool fHaveCondLostEnemy; // [esp+1Bh] [ebp-1h]

  if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(pAI: this, pszFormat: "ChooseEnemy() {\n");
  v2 = this->GetEnemy_2(this);
  m_afMemory = this->m_afMemory;
  fHadEnemy = (m_afMemory & 0x18000) != 0;
  fEnemyWasPlayer = BYTE2(m_afMemory) & 1;
  if ( (m_afMemory & 0x18000) == 0 || v2 != nullptr )
  {
    fEnemyWentNull = false;
    if ( v2 == nullptr || (v5 = this->GetEnemies(this), !CAI_Enemies::HasEludedMe(this: v5, pEnemy: v2)) )
    {
      fEnemyEluded = false;
      goto LABEL_8;
    }
  }
  else
  {
    fEnemyWentNull = true;
  }
  fEnemyEluded = true;
LABEL_8:
  if ( this->m_ScheduleState.bScheduleWasInterrupted || this->m_pSchedule == nullptr || CAI_BaseNPC::FScheduleDone(this) )
  {
    IsCustomInterruptConditionSet = true;
    fHaveCondLostEnemy = true;
  }
  else
  {
    IsCustomInterruptConditionSet = (this->m_pSchedule->m_InterruptMask.m_Ints[0] & 0x4000000) != 0;
    fHaveCondLostEnemy = (this->m_pSchedule->m_InterruptMask.m_Ints[0] & 0x800) != 0;
    if ( (this->m_pSchedule->m_InterruptMask.m_Ints[0] & 0x4000000) == 0 )
      IsCustomInterruptConditionSet = CAI_BaseNPC::IsCustomInterruptConditionSet(this, nCondition: 26);
    if ( !fHaveCondLostEnemy )
      fHaveCondLostEnemy = CAI_BaseNPC::IsCustomInterruptConditionSet(this, nCondition: 11);
  }
  if ( fEnemyWentNull )
  {
    if ( !IsCustomInterruptConditionSet && !fHaveCondLostEnemy )
    {
      m_pSchedule = this->m_pSchedule;
      if ( m_pSchedule != nullptr )
        _DevMsg(a1: 2, a2: "WARNING: AI enemy went NULL but schedule (%s) is not interested\n", m_pSchedule->m_pName);
    }
  }
  else if ( !IsCustomInterruptConditionSet && (!fHaveCondLostEnemy || !fEnemyEluded) )
  {
    this->m_bSkippedChooseEnemy = true;
    m_pParent = ai_debug_enemies.m_pParent;
    if ( ai_debug_enemies.m_pParent != nullptr )
    {
      if ( ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
      {
        DevMsg(pAI: this, pszFormat: "Skipped enemy selection due to schedule restriction\n");
        m_pParent = ai_debug_enemies.m_pParent;
      }
      if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
        DevMsg(pAI: this, pszFormat: "}\n");
    }
    return v2 != nullptr;
  }
  ShouldChooseNewEnemy = this->ShouldChooseNewEnemy;
  this->m_bSkippedChooseEnemy = false;
  if ( ShouldChooseNewEnemy(this) )
  {
    v10 = this->BestEnemy(this);
    if ( v10 != v2 )
      goto LABEL_39;
  }
  else
  {
    v10 = v2;
  }
  if ( !fEnemyWentNull )
    return v10 != nullptr;
LABEL_39:
  if ( ai_debug_enemies.m_pParent != nullptr && ai_debug_enemies.m_pParent->m_Value.m_nValue != 0 )
  {
    fDelay = CBaseEntity::GetDebugName(this: v10);
    DebugName = CBaseEntity::GetDebugName(this: v2);
    DevMsg(pAI: this, pszFormat: "Enemy changed from %s to %s\n", DebugName, fDelay);
  }
  this->m_afMemory &= 0xFFFE7FFF;
  if ( v2 != nullptr && !v2->IsAlive(this: v2) )
    CAI_BaseNPC::SetCondition(this, iCondition: 30);
  CAI_BaseNPC::SetEnemy(this, pEnemy: v10, bSetCondNewEnemy: true);
  if ( fHadEnemy )
  {
    CAI_BaseNPC::VacateStrategySlot(this);
    this->m_afMemory &= ~0x20000u;
  }
  if ( v10 != nullptr )
  {
    this->m_afMemory |= v10->IsPlayer(this: v10) ? 0x10000 : 0x8000;
    return v10 != nullptr;
  }
  v12 = this->GetClassScheduleIdSpace(this);
  v13 = CAI_LocalIdSpace::LocalToGlobal(this: &v12->m_ConditionIds, localID: 30);
  if ( v13 == -1 || (v14 = v13 - 1000000000) == -1 || ((1 << (v14 & 0x1F)) & this->m_Conditions.m_Ints[v14 >> 5]) == 0 )
    CAI_BaseNPC::SetCondition(this, iCondition: 12);
  if ( fEnemyEluded )
  {
    CAI_BaseNPC::SetCondition(this, iCondition: 11);
    this->LostEnemySound(this);
  }
  if ( fEnemyWasPlayer )
    COutputEvent::FireOutput(this: &this->m_OnLostPlayer, pActivator: v2, pCaller: this, fDelay: 0.0);
  COutputEvent::FireOutput(this: &this->m_OnLostEnemy, pActivator: v2, pCaller: this, fDelay: 0.0);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1002A970
// Name: public: virtual void CAI_BaseNPC::Freeze(float,class CBaseEntity __near *,struct Ray_t __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_BaseNPC::Freeze(
        CAI_BaseNPC *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        int flFreezeAmount,
        CBaseEntity *pFreezer,
        Ray_t *pFreezeRay)
{
  int v7; // eax
  int v8; // eax
  int v9; // edi
  CAI_ClassScheduleIdSpace *v10; // eax
  int v11; // eax
  int v12; // eax
  bool (__thiscall *ShouldBecomeStatue)(CAI_BaseNPC *); // edx
  CAI_BaseNPC_vtbl *v14; // ebx
  CTakeDamageInfo *v15; // eax
  CTakeDamageInfo v17; // [esp+1Ch] [ebp-5Ch] BYREF

  CBaseCombatWeapon::AddViewmodelBob(
    (vgui::TreeView *)this,
    itemIndex: flFreezeAmount,
    x: (int)pFreezer,
    y: (int)pFreezeRay);
  if ( *(float *)&flFreezeAmount >= 0.0 )
  {
    ShouldBecomeStatue = this->ShouldBecomeStatue;
    this->m_flFrozenThawRate = 0.1;
    if ( ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, _DWORD, _DWORD, int, int, int, int, _DWORD, int))ShouldBecomeStatue)(
           a1: this,
           a2,
           a3,
           a4: LODWORD(v17.m_vecDamageForce.x),
           a5: LODWORD(v17.m_vecDamageForce.y),
           a6: LODWORD(v17.m_vecDamageForce.z),
           a7: LODWORD(v17.m_vecDamagePosition.x),
           a8: LODWORD(v17.m_vecDamagePosition.y),
           a9: LODWORD(v17.m_vecDamagePosition.z),
           a10: LODWORD(v17.m_vecReportedPosition.x),
           a11: LODWORD(v17.m_vecReportedPosition.y),
           a12: LODWORD(v17.m_vecReportedPosition.z),
           a13: v17.m_hInflictor.m_Index,
           a14: v17.m_hAttacker.m_Index,
           a15: v17.m_hWeapon.m_Index,
           a16: LODWORD(v17.m_flDamage),
           a17: LODWORD(v17.m_flMaxDamage),
           a18: LODWORD(v17.m_flBaseDamage),
           a19: v17.m_bitsDamageType,
           a20: v17.m_iDamageCustom,
           a21: v17.m_iDamageStats,
           a22: v17.m_iAmmoType,
           a23: LODWORD(v17.m_flRadius),
           a24: v17.m_iDamagedOtherPlayers) != 0
      && this->IsAlive(this) )
    {
      CreateServerStatue(pAnimating: this, collisionGroup: 0);
      v14 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v15 = CTakeDamageInfo::CTakeDamageInfo(
              this: &v17,
              pInflictor: pFreezer,
              pAttacker: pFreezer,
              flDamage: 1000.0,
              bitsDamageType: 4196352,
              iKillType: 0,
              iObjectsPenetrated: 0);
      v14->Event_Killed(this, a2: v15);
      CBaseEntity::RemoveDeferred(this);
    }
  }
  else
  {
    v7 = ((int (__thiscall *)(CAI_BaseNPC *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, _DWORD, _DWORD, int, int, int, int, _DWORD, int))this->GetClassScheduleIdSpace)(
           a1: this,
           a2,
           a3,
           a4: LODWORD(v17.m_vecDamageForce.x),
           a5: LODWORD(v17.m_vecDamageForce.y),
           a6: LODWORD(v17.m_vecDamageForce.z),
           a7: LODWORD(v17.m_vecDamagePosition.x),
           a8: LODWORD(v17.m_vecDamagePosition.y),
           a9: LODWORD(v17.m_vecDamagePosition.z),
           a10: LODWORD(v17.m_vecReportedPosition.x),
           a11: LODWORD(v17.m_vecReportedPosition.y),
           a12: LODWORD(v17.m_vecReportedPosition.z),
           a13: v17.m_hInflictor.m_Index,
           a14: v17.m_hAttacker.m_Index,
           a15: v17.m_hWeapon.m_Index,
           a16: LODWORD(v17.m_flDamage),
           a17: LODWORD(v17.m_flMaxDamage),
           a18: LODWORD(v17.m_flBaseDamage),
           a19: v17.m_bitsDamageType,
           a20: v17.m_iDamageCustom,
           a21: v17.m_iDamageStats,
           a22: v17.m_iAmmoType,
           a23: LODWORD(v17.m_flRadius),
           a24: v17.m_iDamagedOtherPlayers);
    v8 = CAI_LocalIdSpace::LocalToGlobal(this: (CAI_LocalIdSpace *)(v7 + 52), localID: 67);
    if ( v8 != -1 )
    {
      v9 = v8 - 1000000000;
      if ( v8 != 999999999 )
      {
        v10 = this->GetClassScheduleIdSpace(this);
        v11 = CAI_LocalIdSpace::LocalToGlobal(this: &v10->m_ConditionIds, localID: 67);
        if ( v11 == -1
          || (v12 = v11 - 1000000000) == -1
          || ((1 << (v12 & 0x1F)) & this->m_Conditions.m_Ints[v12 >> 5]) == 0 )
        {
          this->OnConditionSet(this, a2: 67);
        }
        this->m_Conditions.m_Ints[v9 >> 5] |= 1 << (v9 & 0x1F);
      }
    }
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    v17.m_iDamagedOtherPlayers = (int)&vec3_angle;
    this->m_flGravity = 0.0;
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: (const QAngle *)v17.m_iDamagedOtherPlayers);
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AAE0
// Name: public: virtual void CAI_BaseNPC::Unfreeze(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::Unfreeze(CAI_BaseNPC *this)
{
  CAI_ClassScheduleIdSpace *v2; // eax
  int v3; // eax
  int v4; // edi
  CAI_ClassScheduleIdSpace *v5; // eax
  int v6; // eax
  int v7; // eax

  CBaseAnimating::Unfreeze(this);
  v2 = this->GetClassScheduleIdSpace(this);
  v3 = CAI_LocalIdSpace::LocalToGlobal(this: &v2->m_ConditionIds, localID: 68);
  if ( v3 != -1 )
  {
    v4 = v3 - 1000000000;
    if ( v3 != 999999999 )
    {
      v5 = this->GetClassScheduleIdSpace(this);
      v6 = CAI_LocalIdSpace::LocalToGlobal(this: &v5->m_ConditionIds, localID: 68);
      if ( v6 == -1 || (v7 = v6 - 1000000000) == -1 || ((1 << (v7 & 0x1F)) & this->m_Conditions.m_Ints[v7 >> 5]) == 0 )
        this->OnConditionSet(this, a2: 68);
      this->m_Conditions.m_Ints[v4 >> 5] |= 1 << (v4 & 0x1F);
    }
  }
  this->m_Activity = ACT_RESET;
  CBaseEntity::SetMoveType(this, val: MOVETYPE_STEP, moveCollide: MOVECOLLIDE_DEFAULT);
  this->m_flGravity = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1002ABB0
// Name: public: void CAI_BaseNPC::InputForgetEntity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputForgetEntity(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // esi
  CBaseEntity *EntityByName; // esi
  CAI_Enemies *v7; // eax

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
  if ( g_pDeveloper->m_pParent != nullptr && g_pDeveloper->m_pParent->m_Value.m_nValue != 0 && v5[strlen(v5) - 1] == 42 )
    DevMsg(a1: "InputForgetEntity does not support wildcards\n");
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: v5,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
  {
    if ( this->GetEnemy_2(this) == EntityByName )
    {
      CAI_BaseNPC::SetEnemy(this, pEnemy: nullptr, bSetCondNewEnemy: true);
      if ( this->m_IdealNPCState != NPC_STATE_ALERT )
        this->m_IdealNPCState = NPC_STATE_ALERT;
    }
    v7 = this->GetEnemies(this);
    CAI_Enemies::ClearMemory(this: v7, pEnemy: EntityByName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AC80
// Name: public: virtual void CAI_BaseNPC::InputInsideTransition(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputInsideTransition(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  CAI_BaseNPC::CleanupScriptsOnTeleport(this, bEnrouteAsWell: true);
  if ( CAI_BaseNPC::IsCurSchedule(this, schedId: 63, fIdeal: false) )
    RemoveActorFromScriptedScenes(
      pActor: this,
      instancedscenesonly: false,
      nonidlescenesonly: false,
      pszThisSceneOnly: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002ACB0
// Name: public: void CBaseAnimating::SetCycle(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetCycle(CBaseAnimating *this, float flCycle)
{
  CNetworkVarBase<float,CBaseAnimating::NetworkVar_m_flCycle> *p_m_flCycle; // esi
  edict_t *m_pPev; // ecx

  p_m_flCycle = &this->m_flCycle;
  if ( this->m_flCycle.m_Value != flCycle )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flCycle->m_Value = flCycle;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
      p_m_flCycle->m_Value = flCycle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AD10
// Name: private: void CAI_BaseNPC::Break(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::Break(CAI_BaseNPC *this, CBaseEntity *pBreaker)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // edi
  IPhysicsObject *m_pPhysicsObject; // edi
  int m_iEFlags; // edx
  int v6; // eax
  float m_impactEnergyScale; // xmm0_4
  int m_Value; // eax
  int (__thiscall *GetModelIndex)(struct CBaseEntity *); // edx
  int v10; // eax
  breakablepropparams_t params; // [esp+8h] [ebp-4Ch] BYREF
  QAngle angles; // [esp+24h] [ebp-30h] BYREF
  Vector origin; // [esp+30h] [ebp-24h] BYREF
  Vector angVelocity; // [esp+3Ch] [ebp-18h] BYREF
  Vector velocity; // [esp+48h] [ebp-Ch] BYREF

  p_m_takedamage = &this->m_takedamage;
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    p_m_takedamage->m_Value = 0;
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  if ( m_pPhysicsObject != nullptr )
  {
    m_pPhysicsObject->GetVelocity(this: m_pPhysicsObject, a2: &velocity, a3: &angVelocity);
    m_pPhysicsObject->GetPosition(this: m_pPhysicsObject, a2: &origin, a3: &angles);
    m_pPhysicsObject->RecheckCollisionFilter(this: m_pPhysicsObject);
  }
  else
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this);
    m_iEFlags = this->m_iEFlags;
    velocity = this->m_vecAbsVelocity;
    angVelocity.x = this->m_vecAngVelocity.z;
    angVelocity.y = this->m_vecAngVelocity.x;
    angVelocity.z = this->m_vecAngVelocity.y;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    v6 = this->m_iEFlags;
    origin = this->m_vecAbsOrigin;
    if ( (v6 & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    angles = this->m_angAbsRotation;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  m_impactEnergyScale = this->m_impactEnergyScale;
  params.origin = &this->m_vecAbsOrigin;
  params.angles = &this->m_angAbsRotation;
  params.velocity = &velocity;
  m_Value = this->m_CollisionGroup.m_Value;
  params.angularVelocity = &angVelocity;
  params.impactEnergyScale = m_impactEnergyScale;
  params.defCollisionGroup = m_Value;
  if ( m_Value == 0 )
    params.defCollisionGroup = 4;
  GetModelIndex = this->GetModelIndex;
  params.defBurstScale = 100.0;
  v10 = GetModelIndex(this);
  PropBreakableCreateAll(
    modelindex: v10,
    pPhysics: m_pPhysicsObject,
    &params,
    pEntity: this,
    iPrecomputedBreakableCount: -1,
    bIgnoreGibLimit: false,
    defaultLocation: true);
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x1002AF20
// Name: private: void CAI_BaseNPC::InputBreak(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputBreak(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  CAI_BaseNPC::Break(this, pBreaker: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x1002AF40
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AF70
// Name: public: void CBaseCombatCharacter::SetNextAttack(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::SetNextAttack(CBaseCombatCharacter *this, float flWait)
{
  CNetworkVarBase<float,CBaseCombatCharacter::NetworkVar_m_flNextAttack> *p_m_flNextAttack; // esi
  edict_t *m_pPev; // ecx

  p_m_flNextAttack = &this->m_flNextAttack;
  if ( this->m_flNextAttack.m_Value != flWait )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flNextAttack->m_Value = flWait;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x684u);
      p_m_flNextAttack->m_Value = flWait;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AFD0
// Name: protected: void CAI_BaseNPC::InputForceInteractionWithNPC(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputForceInteractionWithNPC(CAI_BaseNPC *this, CAI_BaseNPC *inputdata)
{
  variant_t *p_m_pfnThink; // edi
  const char *iVal; // eax
  char *v5; // eax
  const char *v6; // ebx
  CBaseEntity *v7; // eax
  const char *v8; // edi
  const char *DebugName; // eax
  CBaseAnimating *v10; // eax
  char *v11; // eax
  bool v12; // cc
  int v13; // edi
  int v14; // eax
  const char *v15; // ecx
  ScriptedNPCInteraction_t *v16; // eax
  CAI_BaseNPC *v17; // ebx
  int v18; // eax
  const char *SequenceName; // eax
  const char *v20; // eax
  const char *v21; // edi
  const char *v22; // eax
  const char *pszValue; // ebx
  const char *v24; // eax
  const char *v25; // edi
  const char *v26; // eax
  const char *v27; // edi
  const char *v28; // eax
  char *v29; // [esp-8h] [ebp-11Ch]
  const char *v30; // [esp-4h] [ebp-118h]
  const char *v31; // [esp-4h] [ebp-118h]
  char parseString[256]; // [esp+Ch] [ebp-108h] BYREF
  int i; // [esp+10Ch] [ebp-8h]
  char *pszParam; // [esp+110h] [ebp-4h]
  CAI_BaseNPC *pNPC; // [esp+11Ch] [ebp+8h]

  p_m_pfnThink = (variant_t *)&inputdata->m_pfnThink;
  if ( inputdata->m_Network.m_pPev == (edict_t *)2 )
  {
    iVal = (const char *)p_m_pfnThink->iVal;
    if ( p_m_pfnThink->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_m_pfnThink);
  }
  V_strncpy(pDest: parseString, pSrc: iVal, maxLen: 255);
  v5 = strtok(string: parseString, control: " ");
  v6 = v5;
  if ( v5 == nullptr || *v5 == 0 )
  {
    if ( inputdata->m_Network.m_pPev == (edict_t *)2 )
    {
      v27 = (const char *)p_m_pfnThink->iVal;
      if ( v27 != nullptr )
        v24 = v27;
      else
        v24 = locale;
    }
    else
    {
      v24 = variant_t::ToString(this: p_m_pfnThink);
    }
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    goto LABEL_49;
  }
  v7 = this->FindNamedEntity(this, a2: v5, a3: 0);
  if ( v7 == nullptr )
  {
    v8 = this->m_iClassname.pszValue;
    if ( v8 == nullptr )
      v8 = locale;
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(
      a1: "%s(%s) received ForceInteractionWithNPC input, but couldn't find entity named: %s\n",
      v8,
      DebugName,
      v6);
    return;
  }
  v10 = v7->MyNPCPointer(this: v7);
  pNPC = (CAI_BaseNPC *)v10;
  if ( v10 == nullptr || CBaseAnimating::GetModelPtr(this: v10) == nullptr )
  {
    v25 = this->m_iClassname.pszValue;
    if ( v25 == nullptr )
      v25 = locale;
    v26 = CBaseEntity::GetDebugName(this);
    _Warning(
      a1: "%s(%s) received ForceInteractionWithNPC input, but entity named %s cannot run dynamic interactions.\n",
      v25,
      v26,
      v6);
    return;
  }
  v11 = strtok(string: nullptr, control: " ");
  pszParam = v11;
  if ( v11 == nullptr || *v11 == 0 )
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v24 = variant_t::String(this: p_m_pfnThink);
LABEL_49:
    v31 = v24;
    v28 = CBaseEntity::GetDebugName(this);
    _Warning(
      a1: "%s(%s) received ForceInteractionWithNPC input with bad parameters: %s\n"
      "Format should be: ForceInteractionWithNPC <target NPC> <interaction name>\n",
      pszValue,
      v28,
      v31);
    return;
  }
  v12 = this->m_ScriptedInteractions.m_Size <= 0;
  i = 0;
  if ( v12 )
  {
LABEL_29:
    v17 = pNPC;
    goto LABEL_30;
  }
  v13 = 0;
  while ( 1 )
  {
    v14 = strlen(v11);
    v15 = this->m_ScriptedInteractions.m_Memory.m_pMemory[v13].iszInteractionName.pszValue;
    if ( v15 == nullptr )
      v15 = locale;
    if ( V_strncmp(s1: pszParam, s2: v15, count: v14) == 0 )
    {
      v16 = &this->m_ScriptedInteractions.m_Memory.m_pMemory[v13];
      if ( v16->sPhases[1].iActivity == -1 )
        break;
      v17 = pNPC;
      if ( CAI_BaseNPC::HaveSequenceForActivity(this: pNPC, activity: (Activity)v16->sPhases[1].iActivity) )
        goto LABEL_34;
      v18 = CBaseAnimating::SelectWeightedSequence(
              this,
              activity: (Activity)this->m_ScriptedInteractions.m_Memory.m_pMemory[v13].sPhases[1].iActivity);
      SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: v18);
      if ( CBaseAnimating::LookupSequence(this: pNPC, label: SequenceName) != -1 )
        goto LABEL_34;
    }
LABEL_28:
    ++v13;
    if ( ++i >= this->m_ScriptedInteractions.m_Size )
      goto LABEL_29;
    v11 = pszParam;
  }
  v20 = v16->sPhases[1].iszSequence.pszValue;
  if ( v20 == nullptr )
    v20 = locale;
  if ( CBaseAnimating::LookupSequence(this: pNPC, label: v20) == -1 )
    goto LABEL_28;
  v17 = pNPC;
LABEL_34:
  if ( i != -1 )
  {
    CAI_BaseNPC::StartForcedInteraction(this, pNPC: v17, iInteraction: i);
    CAI_BaseNPC::StartForcedInteraction(this: v17, pNPC: this, iInteraction: -1);
    return;
  }
LABEL_30:
  v21 = this->m_iClassname.pszValue;
  if ( v21 == nullptr )
    v21 = locale;
  v30 = CBaseEntity::GetDebugName(this: v17);
  v29 = pszParam;
  v22 = CBaseEntity::GetDebugName(this);
  _Warning(
    a1: "%s(%s) received ForceInteractionWithNPC input, but couldn't find an interaction named %s that entity named %s could run.\n",
    v21,
    v22,
    v29,
    v30);
}

//------------------------------------------------------------------------------
// Address: 0x1002B300
// Name: public: void CAI_BaseNPC::SetDeathPose(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetDeathPose(CAI_BaseNPC *this, int *iDeathPose)
{
  CNetworkVarBase<int,CAI_BaseNPC::NetworkVar_m_iDeathPose> *p_m_iDeathPose; // esi
  edict_t *m_pPev; // ecx

  p_m_iDeathPose = &this->m_iDeathPose;
  if ( this->m_iDeathPose.m_Value != *iDeathPose )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iDeathPose->m_Value = *iDeathPose;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA1Cu);
      p_m_iDeathPose->m_Value = *iDeathPose;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B350
// Name: public: void CAI_BaseNPC::SetDeathPoseFrame(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetDeathPoseFrame(CAI_BaseNPC *this, int *iDeathPoseFrame)
{
  CNetworkVarBase<int,CAI_BaseNPC::NetworkVar_m_iDeathFrame> *p_m_iDeathFrame; // esi
  edict_t *m_pPev; // ecx

  p_m_iDeathFrame = &this->m_iDeathFrame;
  if ( this->m_iDeathFrame.m_Value != *iDeathPoseFrame )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iDeathFrame->m_Value = *iDeathPoseFrame;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA20u);
      p_m_iDeathFrame->m_Value = *iDeathPoseFrame;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B3A0
// Name: public: void CAI_BaseNPC::InputActivateSpeedModifier(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputActivateSpeedModifier(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CAI_BaseNPC::NetworkVar_m_bSpeedModActive> *p_m_bSpeedModActive; // esi
  edict_t *m_pPev; // ecx

  p_m_bSpeedModActive = &this->m_bSpeedModActive;
  if ( !this->m_bSpeedModActive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bSpeedModActive->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE68u);
      p_m_bSpeedModActive->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B3F0
// Name: public: void CAI_BaseNPC::InputDisableSpeedModifier(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputDisableSpeedModifier(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CAI_BaseNPC::NetworkVar_m_bSpeedModActive> *p_m_bSpeedModActive; // esi
  edict_t *m_pPev; // ecx

  p_m_bSpeedModActive = &this->m_bSpeedModActive;
  if ( this->m_bSpeedModActive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bSpeedModActive->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE68u);
      p_m_bSpeedModActive->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B440
// Name: public: virtual bool CPostFrameNavigationHook::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPostFrameNavigationHook::Init(CPostFrameNavigationHook *this)
{
  this->m_Functors.m_Size = 0;
  if ( this->m_Functors.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Functors.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Functors.m_Memory.m_pMemory);
      this->m_Functors.m_Memory.m_pMemory = nullptr;
    }
    this->m_Functors.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Functors.m_pElements = this->m_Functors.m_Memory.m_pMemory;
  this->m_bGameFrameRunning = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B480
// Name: public: virtual void CPostFrameNavigationHook::FrameUpdatePreEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostFrameNavigationHook::FrameUpdatePreEntityThink(CPostFrameNavigationHook *this)
{
  if ( g_pQueuedNavigationQueryJob != nullptr )
  {
    CJob::WaitForFinishAndRelease(this: g_pQueuedNavigationQueryJob, dwTimeout: 0xFFFFFFFF);
    g_pQueuedNavigationQueryJob = nullptr;
    this->m_Functors.m_Size = 0;
    if ( this->m_Functors.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_Functors.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Functors.m_Memory.m_pMemory);
        this->m_Functors.m_Memory.m_pMemory = nullptr;
      }
      this->m_Functors.m_Memory.m_nAllocationCount = 0;
    }
    this->m_Functors.m_pElements = this->m_Functors.m_Memory.m_pMemory;
  }
  if ( ai_post_frame_navigation.m_pParent != nullptr && ai_post_frame_navigation.m_pParent->m_Value.m_nValue != 0 )
    this->m_bGameFrameRunning = true;
}

//------------------------------------------------------------------------------
// Address: 0x1002B4E0
// Name: public: void CPostFrameNavigationHook::EnqueueEntityNavigationQuery(class CAI_BaseNPC __near *,class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostFrameNavigationHook::EnqueueEntityNavigationQuery(
        CPostFrameNavigationHook *this,
        CAI_BaseNPC *pNPC,
        CFunctor *pFunctor)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Functors; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v7; // eax
  vgui::TreeNode **v8; // eax

  if ( ai_post_frame_navigation.m_pParent != nullptr && ai_post_frame_navigation.m_pParent->m_Value.m_nValue != 0 )
  {
    m_nAllocationCount = this->m_Functors.m_Memory.m_nAllocationCount;
    p_m_Functors = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Functors;
    m_Size = this->m_Functors.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Functors, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Functors[1].m_pMemory;
    m_pMemory = p_m_Functors->m_pMemory;
    v7 = (int)p_m_Functors[1].m_pMemory - m_Size - 1;
    p_m_Functors[1].m_nAllocationCount = (int)p_m_Functors->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &p_m_Functors->m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = (vgui::TreeNode *)pFunctor;
    pNPC->m_bDeferredNavigation = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B560
// Name: public: void CAI_BaseNPC::SelectDeathPose(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SelectDeathPose(CAI_BaseNPC *this, int info)
{
  CStudioHdr *m_pStudioHdr; // eax
  const CTakeDamageInfo *v4; // edi
  int m_LastHitGroup; // [esp-10h] [ebp-1Ch]
  int iDeathFrame; // [esp+4h] [ebp-8h] BYREF
  Activity aActivity; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v4 = (const CTakeDamageInfo *)info;
    if ( (*(_DWORD *)(info + 60) & 0x800) == 0 && this->ShouldPickADeathPose(this) )
    {
      m_LastHitGroup = this->m_LastHitGroup;
      aActivity = ACT_INVALID;
      iDeathFrame = 0;
      SelectDeathPoseActivityAndFrame(
        entity: this,
        info: v4,
        hitgroup: m_LastHitGroup,
        activity: &aActivity,
        frame: &iDeathFrame);
      if ( aActivity == ACT_INVALID )
      {
        info = -1;
        CAI_BaseNPC::SetDeathPose(this, iDeathPose: &info);
        info = 0;
        CAI_BaseNPC::SetDeathPoseFrame(this, iDeathPoseFrame: &info);
      }
      else
      {
        info = CBaseAnimating::SelectWeightedSequence(this, activity: aActivity);
        CAI_BaseNPC::SetDeathPose(this, iDeathPose: &info);
        CAI_BaseNPC::SetDeathPoseFrame(this, iDeathPoseFrame: &iDeathFrame);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B640
// Name: public: virtual int CAI_BaseNPC::OnTakeDamage_Alive(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CAI_BaseNPC::OnTakeDamage_Alive@<eax>(
        CAI_BaseNPC *this@<ecx>,
        int a2@<ebx>,
        const CTakeDamageInfo *info)
{
  int m_Value; // eax
  int result; // eax
  CAI_Squad *m_pSquad; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edx
  unsigned int v9; // edx
  int v10; // eax
  CEntInfo *v11; // edi
  unsigned int v12; // edx
  int v13; // eax
  bool v14; // zf
  CEntInfo *v15; // eax
  IHandleEntity *v16; // eax
  CAI_ScriptedSequence *v17; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // edi
  unsigned int v19; // eax
  IHandleEntity *v20; // edx
  unsigned int v21; // eax
  IHandleEntity *v22; // ecx
  unsigned int v23; // eax
  CBaseEntity *v24; // ecx
  unsigned int v25; // ecx
  CBaseEntityList *v26; // edi
  int v27; // eax
  CEntInfo *v28; // edx
  unsigned int v29; // ecx
  int v30; // eax
  CEntInfo *v31; // eax
  IHandleEntity *v32; // eax
  CBaseEntity *Attacker; // eax
  CTakeDamageInfo *v34; // ecx
  unsigned int v35; // eax
  IHandleEntity *v36; // ecx
  CAI_BaseNPC *v37; // edi
  CBasePlayer *LocalPlayer; // ebx
  CBaseEntity *v39; // eax
  const CTakeDamageInfo *v40; // ecx
  int m_bitsDamageType; // eax
  unsigned int v42; // eax
  CBaseEntity *v43; // ecx
  unsigned int v44; // ecx
  int v45; // eax
  CEntInfo *v46; // edx
  unsigned int v47; // ecx
  int v48; // eax
  CEntInfo *v49; // eax
  IHandleEntity *v50; // eax
  CAI_BaseNPC_vtbl *v51; // edi
  CBaseEntity *v52; // eax
  CAI_BaseNPC_vtbl *v53; // edi
  CBaseEntity *v54; // eax
  CBaseEntity *Inflictor; // eax
  const Vector *AbsOrigin; // eax
  float v57; // xmm1_4
  float v58; // xmm2_4
  CAI_Enemies *v59; // eax
  CAI_BaseNPC_vtbl *v60; // edi
  CBaseEntity *v61; // eax
  int v62; // eax
  CBaseEntity *v63; // eax
  CAI_Enemies *v64; // eax
  bool HasMemory; // al
  CAI_BaseNPC_vtbl *v66; // edi
  CBaseEntity *v67; // eax
  CBaseEntity *v68; // eax
  CAI_Enemies *v69; // eax
  CAI_BaseNPC_vtbl *v70; // edi
  CBaseEntity *v71; // eax
  CBaseEntity *v73; // [esp+44h] [ebp-28h]
  int v74; // [esp+44h] [ebp-28h]
  CBaseEntity *v75; // [esp+44h] [ebp-28h]
  CBaseEntity *v76; // [esp+48h] [ebp-24h]
  float v77; // [esp+50h] [ebp-1Ch]
  float v78; // [esp+54h] [ebp-18h]
  float v79; // [esp+58h] [ebp-14h]
  Vector vAttackPos; // [esp+5Ch] [ebp-10h] BYREF
  bool bIsBelowHalfHealthBefore; // [esp+6Bh] [ebp-1h]

  m_Value = this->m_iMaxHealth.m_Value;
  this->m_afMemory &= ~2u;
  bIsBelowHalfHealthBefore = this->m_iHealth.m_Value <= m_Value / 2;
  result = CBaseCombatCharacter::OnTakeDamage_Alive(this, info);
  if ( result == 0 )
    return result;
  if ( this->m_SleepState == AISS_WAITING_FOR_THREAT )
    this->Wake(this, a2: true);
  m_pSquad = this->m_pSquad;
  if ( m_pSquad == nullptr
    || ((m_Index = info->m_hAttacker.m_Index) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      ? (m_pEntity = nullptr)
      : (m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity),
        !CAI_Squad::SquadIsMember(this: m_pSquad, pMember: m_pEntity)) )
  {
    this->PainSound(this, a2: info);
  }
  if ( this->m_iInteractionState == 1 )
  {
    v9 = this->m_hCine.m_Index;
    if ( v9 != -1 )
    {
      v10 = (unsigned __int16)v9;
      v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v9];
      v12 = HIWORD(v9);
      if ( v11->m_SerialNumber == v12
        && v11->m_pEntity != nullptr
        && (this->m_ScriptedInteractions.m_Memory.m_pMemory[this->m_iInteractionPlaying].iLoopBreakTriggerMethod & 2) != 0 )
      {
        v13 = v10;
        v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v12;
        v15 = &g_pEntityList->m_EntPtrArray[v13];
        v16 = v14 ? v15->m_pEntity : nullptr;
        if ( BYTE1(v16[232].__vftable) != 0 && LOBYTE(v16[221].__vftable) == 0 )
        {
          v17 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine);
          CAI_ScriptedSequence::StopActionLoop(this: v17, bStopSynchronizedScenes: true);
        }
      }
    }
  }
  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value <= 0 && CAI_BaseNPC::HasInteractionCantDie(this) )
  {
    v19 = info->m_hAttacker.m_Index;
    if ( v19 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
      v20 = nullptr;
    else
      v20 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
    v21 = this->m_hInteractionPartner.m_Index;
    if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
      v22 = nullptr;
    else
      v22 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
    if ( v20 != v22 && p_m_iHealth->m_Value != 1 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      p_m_iHealth->m_Value = 1;
    }
  }
  if ( this->m_flLastDamageTime != gpGlobals->curtime )
  {
    v23 = info->m_hAttacker.m_Index;
    if ( v23 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != HIWORD(v23) )
      v24 = nullptr;
    else
      v24 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
    COutputEvent::FireOutput(this: &this->m_OnDamaged, pActivator: v24, pCaller: this, fDelay: 0.0);
    v25 = info->m_hAttacker.m_Index;
    if ( v25 != -1 )
    {
      v26 = g_pEntityList;
      v27 = (unsigned __int16)v25;
      v28 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v25];
      v29 = HIWORD(v25);
      if ( v28->m_SerialNumber != v29 || v28->m_pEntity == nullptr )
        goto LABEL_49;
      v30 = v27;
      v14 = g_pEntityList->m_EntPtrArray[v30].m_SerialNumber == v29;
      v31 = &g_pEntityList->m_EntPtrArray[v30];
      if ( v14 )
        v32 = v31->m_pEntity;
      else
        v32 = nullptr;
      if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v32->__vftable[28].dtr_IHandleEntity)(a1: v32) != 0 )
      {
        Attacker = CTakeDamageInfo::GetAttacker(this: info);
        COutputEvent::FireOutput(this: &this->m_OnDamagedByPlayer, pActivator: Attacker, pCaller: this, fDelay: 0.0);
        v34 = info;
LABEL_62:
        v39 = CTakeDamageInfo::GetAttacker(this: v34);
        COutputEvent::FireOutput(this: &this->m_OnDamagedByPlayerSquad, pActivator: v39, pCaller: this, fDelay: 0.0);
        goto LABEL_63;
      }
    }
    v26 = g_pEntityList;
LABEL_49:
    v35 = info->m_hAttacker.m_Index;
    if ( v35 == -1 || v26->m_EntPtrArray[(unsigned __int16)v35].m_SerialNumber != HIWORD(v35) )
      v36 = nullptr;
    else
      v36 = v26->m_EntPtrArray[(unsigned __int16)v35].m_pEntity;
    v37 = (CAI_BaseNPC *)__RTDynamicCast(
                           inptr: v36,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CAI_BaseNPC `RTTI Type Descriptor',
                           isReference: 0);
    if ( gpGlobals->maxClients <= 1 )
      LocalPlayer = UTIL_GetLocalPlayer();
    else
      LocalPlayer = nullptr;
    if ( v37 == nullptr
      || !v37->IsAlive(this: v37)
      || LocalPlayer == nullptr
      || v37->m_pSquad == nullptr
      || !CAI_BaseNPC::IsInPlayerSquad(this: v37) )
    {
      goto LABEL_63;
    }
    v34 = info;
    goto LABEL_62;
  }
LABEL_63:
  v40 = info;
  m_bitsDamageType = info->m_bitsDamageType;
  if ( (m_bitsDamageType & 1) != 0 && (m_bitsDamageType & 0x800000) == 0 && info->m_flDamage >= 5.0 )
  {
    CAI_BaseNPC::SetCondition(this, iCondition: 19);
    v40 = info;
  }
  if ( !bIsBelowHalfHealthBefore && this->m_iHealth.m_Value <= this->m_iMaxHealth.m_Value / 2 )
  {
    v42 = v40->m_hAttacker.m_Index;
    if ( v42 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_SerialNumber != HIWORD(v42) )
      v43 = nullptr;
    else
      v43 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_pEntity;
    COutputEvent::FireOutput(this: &this->m_OnHalfHealth, pActivator: v43, pCaller: this, fDelay: 0.0);
  }
  if ( (this->m_fFlags.m_Value & 0x4000) != 0 )
  {
    v44 = info->m_hAttacker.m_Index;
    if ( v44 != -1 )
    {
      v45 = (unsigned __int16)v44;
      v46 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v44];
      v47 = HIWORD(v44);
      if ( v46->m_SerialNumber == v47 && v46->m_pEntity != nullptr )
      {
        v48 = v45;
        v14 = g_pEntityList->m_EntPtrArray[v48].m_SerialNumber == v47;
        v49 = &g_pEntityList->m_EntPtrArray[v48];
        if ( v14 )
          v50 = v49->m_pEntity;
        else
          v50 = nullptr;
        if ( ((int)v50[50].__vftable & 0x4100) != 0 )
        {
          v51 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          v52 = CTakeDamageInfo::GetAttacker(this: info);
          if ( ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *, CBaseEntity *, int))v51->FInViewCone)(
                 a1: this,
                 a2: v52,
                 a3: a2) == 0
            || (v53 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable,
                v54 = CTakeDamageInfo::GetAttacker(this: info),
                !v53->FVisible_2(this, a2: v54, a3: 16449, a4: nullptr)) )
          {
            if ( CTakeDamageInfo::GetInflictor(this: info) != nullptr )
            {
              Inflictor = CTakeDamageInfo::GetInflictor(this: info);
              vAttackPos = *CBaseEntity::GetAbsOrigin(this: Inflictor);
            }
            else
            {
              v77 = g_vecAttackDir.x * 64.0;
              v78 = g_vecAttackDir.y * 64.0;
              v79 = g_vecAttackDir.z * 64.0;
              AbsOrigin = CBaseEntity::GetAbsOrigin(this);
              v57 = AbsOrigin->y + v78;
              v58 = AbsOrigin->z + v79;
              vAttackPos.x = AbsOrigin->x + v77;
              vAttackPos.y = v57;
              vAttackPos.z = v58;
            }
            if ( this->GetEnemy_2(this) == nullptr
              || (v73 = CTakeDamageInfo::GetAttacker(this: info),
                  v59 = this->GetEnemies(this),
                  CAI_Enemies::HasMemory(this: v59, pEnemy: v73))
              || CAI_BaseNPC::HasCondition(this, iCondition: 10) )
            {
              v63 = CTakeDamageInfo::GetAttacker(this: info);
              v64 = (CAI_Enemies *)((int (__thiscall *)(CAI_BaseNPC *, CBaseEntity *))this->GetEnemies)(
                                     a1: this,
                                     a2: v63);
              HasMemory = CAI_Enemies::HasMemory(this: v64, pEnemy: v76);
              v76 = nullptr;
              if ( HasMemory )
              {
                v66 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
                v67 = CTakeDamageInfo::GetAttacker(this: info);
                ((void (__thiscall *)(CAI_BaseNPC *, CBaseEntity *, Vector *))v66->UpdateEnemyMemory)(
                  a1: this,
                  a2: v67,
                  a3: &vAttackPos);
              }
              else
              {
                ((void (__thiscall *)(CAI_BaseNPC *, _DWORD, Vector *))this->UpdateEnemyMemory)(
                  a1: this,
                  a2: 0,
                  a3: &vAttackPos);
              }
            }
            else
            {
              v60 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
              v61 = this->GetEnemy_2(this);
              v62 = ((int (__thiscall *)(CAI_BaseNPC *, Vector *, CBaseEntity *))this->GetEnemy_2)(
                      a1: this,
                      a2: &vAttackPos,
                      a3: v61);
              ((void (__thiscall *)(CAI_BaseNPC *, int, int))v60->UpdateEnemyMemory)(a1: this, a2: v62, a3: v74);
            }
          }
          if ( this->IsLightDamage(this, a2: info) )
            CAI_BaseNPC::SetCondition(this, iCondition: 17);
          if ( this->IsHeavyDamage(this, a2: info) )
            CAI_BaseNPC::SetCondition(this, iCondition: 18);
          this->m_bForceConditionsGather = true;
          this->m_Efficiency = AIE_NORMAL;
          if ( (float)(gpGlobals->curtime - this->m_flLastDamageTime) >= 1.0 )
            this->m_flSumDamage = info->m_flDamage;
          else
            this->m_flSumDamage = info->m_flDamage + this->m_flSumDamage;
          this->m_flLastDamageTime = gpGlobals->curtime;
          if ( CTakeDamageInfo::GetAttacker(this: info) != nullptr )
          {
            v68 = CTakeDamageInfo::GetAttacker(this: info);
            if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *, CBaseEntity *))v68->IsPlayer)(a1: v68, a2: v76) != 0 )
              this->m_flLastPlayerDamageTime = gpGlobals->curtime;
          }
          v75 = CTakeDamageInfo::GetAttacker(this: info);
          v69 = this->GetEnemies(this);
          CAI_Enemies::OnTookDamageFrom(this: v69, pEnemy: v75);
          if ( this->m_flSumDamage > (double)this->m_iMaxHealth.m_Value * 0.3 )
            CAI_BaseNPC::SetCondition(this, iCondition: 20);
          v70 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          v71 = CTakeDamageInfo::GetAttacker(this: info);
          v70->NotifyFriendsOfDamage(this, a2: v71);
        }
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this);
        CSoundEnt::InsertSound(
          iType: 1,
          vecOrigin: &this->m_vecAbsOrigin,
          iVolume: 1024,
          flDuration: 0.5,
          pOwner: this,
          soundChannelIndex: 5,
          pSoundTarget: nullptr);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002BD80
// Name: public: virtual void CAI_BaseNPC::SetPlayerAvoidState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetPlayerAvoidState(CAI_BaseNPC *this)
{
  bool v2; // bl
  const Vector *v3; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v4; // edx
  float z; // xmm0_4
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  CBasePlayer *LocalPlayer; // eax
  CBaseEntity *v8; // edi
  float *v9; // eax
  unsigned int v10; // ecx
  CBaseEntity::NetworkVar_m_Collision_vtbl *v11; // edx
  float v12; // xmm0_4
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  float *v14; // ebx
  int m_iEFlags; // edx
  int v16; // eax
  bool v17; // bl
  edict_t *m_pPev; // ecx
  int v19; // eax
  int m_Value; // [esp-4h] [ebp-70h]
  Vector boxMin1; // [esp+10h] [ebp-5Ch] BYREF
  Vector boxMax1; // [esp+1Ch] [ebp-50h] BYREF
  Vector boxMin2; // [esp+28h] [ebp-44h] BYREF
  Vector boxMax2; // [esp+34h] [ebp-38h] BYREF
  Vector vNothing; // [esp+40h] [ebp-2Ch] BYREF
  Vector vMins; // [esp+4Ch] [ebp-20h] BYREF
  Vector vMaxs; // [esp+58h] [ebp-14h] BYREF
  float *v28; // [esp+64h] [ebp-8h]
  bool bShouldPlayerAvoid; // [esp+6Bh] [ebp-1h]

  m_Value = this->m_nSequence.m_Value;
  bShouldPlayerAvoid = false;
  CBaseAnimating::GetSequenceLinearMotion(this, iSequence: m_Value, pVec: &vNothing);
  v2 = this->IsMoving(this) || vec3_origin.x != vNothing.x || vec3_origin.y != vNothing.y || vec3_origin.z != vNothing.z;
  if ( this->m_bPerformAvoidance.m_Value || this->ShouldPlayerAvoid(this) && v2 )
  {
    v3 = this->m_Collision.OBBMins(this: &this->m_Collision);
    v4 = this->m_Collision.CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::__vftable;
    vMins.x = v3->x;
    vMins.y = v3->y;
    z = v3->z;
    OBBMaxs = v4->OBBMaxs;
    vMins.z = z;
    vMaxs = *OBBMaxs(this: &this->m_Collision);
    if ( gpGlobals->maxClients <= 1 && (LocalPlayer = UTIL_GetLocalPlayer(), v8 = LocalPlayer, LocalPlayer != nullptr) )
    {
      v9 = (float *)LocalPlayer->m_Collision.OBBMaxs(this: &LocalPlayer->m_Collision);
      v10 = (unsigned int)v8->m_iEFlags >> 11;
      v28 = v9;
      if ( (v10 & 1) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: v8);
        v9 = v28;
      }
      v11 = v8->m_Collision.__vftable;
      boxMax2.x = *v9 + v8->m_vecAbsOrigin.x;
      boxMax2.y = v9[1] + v8->m_vecAbsOrigin.y;
      v12 = v9[2] + v8->m_vecAbsOrigin.z;
      OBBMins = v11->OBBMins;
      boxMax2.z = v12;
      v14 = (float *)OBBMins(this: &v8->m_Collision);
      if ( (v8->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v8);
      m_iEFlags = this->m_iEFlags;
      boxMin2.x = v8->m_vecAbsOrigin.x + *v14;
      boxMin2.y = v14[1] + v8->m_vecAbsOrigin.y;
      boxMin2.z = v14[2] + v8->m_vecAbsOrigin.z;
      if ( (m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      v16 = this->m_iEFlags;
      boxMax1.x = vMaxs.x + this->m_vecAbsOrigin.x;
      boxMax1.y = this->m_vecAbsOrigin.y + vMaxs.y;
      boxMax1.z = this->m_vecAbsOrigin.z + vMaxs.z;
      if ( (v16 & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      boxMin1.x = vMins.x + this->m_vecAbsOrigin.x;
      boxMin1.y = this->m_vecAbsOrigin.y + vMins.y;
      boxMin1.z = this->m_vecAbsOrigin.z + vMins.z;
      v17 = IsBoxIntersectingBox(&boxMin1, &boxMax1, &boxMin2, &boxMax2);
    }
    else
    {
      v17 = bShouldPlayerAvoid;
    }
    if ( ai_debug_avoidancebounds.m_pParent != nullptr && ai_debug_avoidancebounds.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      NDebugOverlay::Box(
        origin: &this->m_vecAbsOrigin,
        mins: &vMins,
        maxs: &vMaxs,
        r: (unsigned __int8)(!v17 - 1),
        g: 0,
        b: 255,
        a: 64,
        flDuration: 0.1);
    }
  }
  else
  {
    v17 = bShouldPlayerAvoid;
  }
  this->m_bPlayerAvoidState = this->ShouldPlayerAvoid(this);
  if ( this->m_bPerformAvoidance.m_Value != v17 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE64u);
    }
    this->m_bPerformAvoidance.m_Value = v17;
  }
  v19 = this->m_CollisionGroup.m_Value;
  if ( v19 == 9 || v19 == 18 )
  {
    if ( this->m_bPerformAvoidance.m_Value )
      CBaseEntity::SetCollisionGroup(this, collisionGroup: 18);
    else
      CBaseEntity::SetCollisionGroup(this, collisionGroup: 9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C0F0
// Name: public: virtual void CAI_BaseNPC::PlayerPenetratingVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::PlayerPenetratingVPhysics(CAI_BaseNPC *this)
{
  CNetworkVarBase<bool,CAI_BaseNPC::NetworkVar_m_bPerformAvoidance> *p_m_bPerformAvoidance; // esi
  edict_t *m_pPev; // ecx

  p_m_bPerformAvoidance = &this->m_bPerformAvoidance;
  if ( !this->m_bPerformAvoidance.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bPerformAvoidance->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE64u);
      p_m_bPerformAvoidance->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C130
// Name: public: void CAI_BaseNPC::SetState(enum NPC_STATE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetState(CAI_BaseNPC *this, NPC_STATE State)
{
  NPC_STATE m_NPCState; // ebx
  bool v4; // al

  m_NPCState = this->m_NPCState;
  if ( State != m_NPCState )
    this->m_flLastStateChangeTime = gpGlobals->curtime;
  if ( State == NPC_STATE_IDLE && this->GetEnemy_2(this) != nullptr )
  {
    CAI_BaseNPC::SetEnemy(this, pEnemy: nullptr, bSetCondNewEnemy: true);
    _DevMsg(a1: 2, a2: "Stripped\n");
  }
  v4 = this->m_NPCState != State;
  this->m_NPCState = State;
  if ( State != this->m_IdealNPCState )
    this->m_IdealNPCState = State;
  if ( v4 )
    this->OnStateChange(this, a2: m_NPCState, a3: State);
}

//------------------------------------------------------------------------------
// Address: 0x1002C1C0
// Name: public: void CAI_BaseNPC::SetActivityAndSequence(enum Activity,int,enum Activity,enum Activity)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetActivityAndSequence(
        CAI_BaseNPC *this,
        Activity NewActivity,
        int iSequence,
        Activity translatedActivity,
        Activity weaponActivity)
{
  int m_Value; // edi
  Activity m_Activity; // ebx
  const char *v8; // eax
  edict_t *m_pPev; // ecx
  CStudioHdr *m_pStudioHdr; // eax
  CAI_BaseNPC_vtbl *v11; // edi
  Vector *v12; // eax
  const char *v13; // [esp-8h] [ebp-30h]
  const char *v14; // [esp-4h] [ebp-2Ch]
  const char *SequenceName; // [esp+0h] [ebp-28h]
  const char *ActivityName; // [esp+4h] [ebp-24h]
  const char *duration; // [esp+8h] [ebp-20h]
  float durationa; // [esp+8h] [ebp-20h]
  _BYTE v19[12]; // [esp+18h] [ebp-10h] BYREF
  const char *pszValue; // [esp+24h] [ebp-4h]

  this->m_translatedActivity = translatedActivity;
  if ( ai_sequence_debug.m_pParent != nullptr
    && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
    && (this->m_debugOverlays & 0x1000) != 0 )
  {
    m_Value = this->m_nSequence.m_Value;
    m_Activity = this->m_Activity;
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    duration = CAI_BaseNPC::GetActivityName(actID: weaponActivity);
    ActivityName = CAI_BaseNPC::GetActivityName(actID: translatedActivity);
    SequenceName = CBaseAnimating::GetSequenceName(this, iSequence);
    v14 = CAI_BaseNPC::GetActivityName(actID: NewActivity);
    v13 = CBaseAnimating::GetSequenceName(this, iSequence: m_Value);
    v8 = CAI_BaseNPC::GetActivityName(actID: m_Activity);
    DevMsg(
      a1: "SetActivityAndSequence : %s: %s:%s -> %s:%s / %s:%s\n",
      pszValue,
      v8,
      v13,
      v14,
      SequenceName,
      ActivityName,
      duration);
  }
  if ( iSequence <= -1 )
  {
    CBaseAnimating::ResetSequence(this, nSequence: 0);
  }
  else
  {
    if ( (this->m_nSequence.m_Value != iSequence || !this->m_bSequenceLoops)
      && (!this->IsActivityMovementPhased(this, a2: this->m_Activity)
       || !this->IsActivityMovementPhased(this, a2: NewActivity))
      && this->m_flCycle.m_Value != 0.0 )
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
    CBaseAnimating::ResetSequence(this, nSequence: iSequence);
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    durationa = CBaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence);
    CBaseCombatCharacter::Weapon_SetActivity(this, newActivity: weaponActivity, duration: durationa);
  }
  v11 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  v12 = this->EyeOffset(this, result: v19, a3: this->m_translatedActivity);
  v11->SetViewOffset(this, a2: v12);
  if ( this->m_Activity != NewActivity )
    this->OnChangeActivity(this, a2: NewActivity);
  this->m_Activity = NewActivity;
  this->m_pMotor->RecalculateYawSpeed(this: this->m_pMotor);
}

//------------------------------------------------------------------------------
// Address: 0x1002C3B0
// Name: public: void CBaseEntity::SetName(struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetName(CBaseEntity *this, string_t newName)
{
  edict_t *m_pPev; // ecx

  if ( this->m_iName.m_Value.pszValue != newName.pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xCCu);
    }
    this->m_iName.m_Value = newName;
  }
  CGlobalEntityList::UpdateName(this: &gEntList, pEnt: this);
}

//------------------------------------------------------------------------------
// Address: 0x1002C400
// Name: public: void CBaseEntity::AddSpawnFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::AddSpawnFlags(CBaseEntity *this, int nFlags)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_spawnflags = &this->m_spawnflags;
  v3 = nFlags | this->m_spawnflags.m_Value;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_spawnflags->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C450
// Name: public: void CBaseEntity::RemoveSpawnFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::RemoveSpawnFlags(CBaseEntity *this, int nFlags)
{
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // edi
  int v4; // esi
  edict_t *m_pPev; // ecx

  m_Value = this->m_spawnflags.m_Value;
  p_m_spawnflags = &this->m_spawnflags;
  v4 = m_Value & ~nFlags;
  if ( m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_spawnflags->m_Value = v4;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C4A0
// Name: public: void CAI_BaseNPC::SetSequenceById(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetSequenceById(CAI_BaseNPC *this, int iSequence)
{
  edict_t *m_pPev; // ecx
  const char *pszValue; // eax

  if ( iSequence <= -1 )
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevWarning(a1: 2, a2: "%s invalid sequence requested\n", pszValue);
    CBaseAnimating::SetSequence(this, nSequence: 0);
  }
  else
  {
    if ( (this->m_nSequence.m_Value != iSequence || !this->m_bSequenceLoops) && this->m_flCycle.m_Value != 0.0 )
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
    CBaseAnimating::ResetSequence(this, nSequence: iSequence);
    this->m_pMotor->RecalculateYawSpeed(this: this->m_pMotor);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C550
// Name: public: virtual int CAI_BaseNPC::UnholsterWeapon(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::UnholsterWeapon(CAI_BaseNPC *this)
{
  int result; // eax
  int v3; // edi
  CBaseCombatWeapon *Weapon; // eax
  int v5; // eax
  int v6; // ebx
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseCombatWeapon *v8; // eax
  int v9; // ebx
  CBaseCombatWeapon *v10; // eax
  CBaseCombatWeapon *v11; // edi
  CBaseEdict *v12; // ecx
  CAI_ClassScheduleIdSpace *v13; // eax
  int v14; // eax
  int v15; // edi
  CAI_ClassScheduleIdSpace *v16; // eax
  int v17; // eax
  int v18; // eax
  CAI_ClassScheduleIdSpace *v19; // eax
  int v20; // eax
  int v21; // edi
  CAI_ClassScheduleIdSpace *v22; // eax
  int v23; // eax
  int v24; // eax
  CAI_ClassScheduleIdSpace *v25; // eax
  int v26; // eax
  int v27; // edi
  CAI_ClassScheduleIdSpace *v28; // eax
  int v29; // eax
  int v30; // eax
  float flTime; // [esp+0h] [ebp-14h]
  int iLayer; // [esp+10h] [ebp-4h]

  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr
    && (CBaseCombatCharacter::GetActiveWeapon(this)->m_fEffects.m_Value & 0x20) == 0 )
  {
    return -1;
  }
  result = CBaseAnimatingOverlay::FindGestureLayer(this, activity: ACT_ARM);
  if ( result == -1 )
  {
    v3 = 0;
    while ( CBaseCombatCharacter::GetWeapon(this, i: v3) == nullptr )
    {
      if ( ++v3 >= 64 )
        return -1;
    }
    Weapon = CBaseCombatCharacter::GetWeapon(this, i: v3);
    CBaseCombatCharacter::SetActiveWeapon(this, pNewWeapon: Weapon);
    v5 = CBaseAnimatingOverlay::AddGesture(this, activity: ACT_ARM, autokill: true);
    v6 = v5;
    iLayer = v5;
    if ( v5 != -1 )
    {
      flTime = CBaseAnimatingOverlay::GetLayerDuration(this, iLayer: v5) + gpGlobals->curtime + 0.5;
      CAI_ShotRegulator::FireNoEarlierThan(this: &this->m_ShotRegulator, flTime);
      this->m_iDesiredWeaponState = DESIREDWEAPONSTATE_CHANGING;
    }
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( ActiveWeapon->UsesClipsForAmmo1(this: ActiveWeapon) )
    {
      v8 = CBaseCombatCharacter::GetActiveWeapon(this);
      v9 = v8->GetMaxClip1(this: v8);
      v10 = CBaseCombatCharacter::GetActiveWeapon(this);
      v11 = v10;
      if ( v10->m_iClip1.m_Value != v9 )
      {
        if ( v10->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v10->m_Network + 76) |= 1u;
        }
        else
        {
          v12 = &v10->m_Network.m_pPev->CBaseEdict;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: v12, offset: 0x4B0u);
        }
        v11->m_iClip1.m_Value = v9;
      }
      v6 = iLayer;
    }
    v13 = this->GetClassScheduleIdSpace(this);
    v14 = CAI_LocalIdSpace::LocalToGlobal(this: &v13->m_ConditionIds, localID: 3);
    if ( v14 != -1 )
    {
      v15 = v14 - 1000000000;
      if ( v14 != 999999999 )
      {
        v16 = this->GetClassScheduleIdSpace(this);
        v17 = CAI_LocalIdSpace::LocalToGlobal(this: &v16->m_ConditionIds, localID: 3);
        if ( v17 != -1 )
        {
          v18 = v17 - 1000000000;
          if ( v18 != -1 && ((1 << (v18 & 0x1F)) & this->m_Conditions.m_Ints[v18 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 3);
        }
        this->m_Conditions.m_Ints[v15 >> 5] &= ~(1 << (v15 & 0x1F));
      }
    }
    v19 = this->GetClassScheduleIdSpace(this);
    v20 = CAI_LocalIdSpace::LocalToGlobal(this: &v19->m_ConditionIds, localID: 4);
    if ( v20 != -1 )
    {
      v21 = v20 - 1000000000;
      if ( v20 != 999999999 )
      {
        v22 = this->GetClassScheduleIdSpace(this);
        v23 = CAI_LocalIdSpace::LocalToGlobal(this: &v22->m_ConditionIds, localID: 4);
        if ( v23 != -1 )
        {
          v24 = v23 - 1000000000;
          if ( v24 != -1 && ((1 << (v24 & 0x1F)) & this->m_Conditions.m_Ints[v24 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 4);
        }
        this->m_Conditions.m_Ints[v21 >> 5] &= ~(1 << (v21 & 0x1F));
      }
    }
    v25 = this->GetClassScheduleIdSpace(this);
    v26 = CAI_LocalIdSpace::LocalToGlobal(this: &v25->m_ConditionIds, localID: 5);
    if ( v26 != -1 )
    {
      v27 = v26 - 1000000000;
      if ( v26 != 999999999 )
      {
        v28 = this->GetClassScheduleIdSpace(this);
        v29 = CAI_LocalIdSpace::LocalToGlobal(this: &v28->m_ConditionIds, localID: 5);
        if ( v29 != -1 )
        {
          v30 = v29 - 1000000000;
          if ( v30 != -1 && ((1 << (v30 & 0x1F)) & this->m_Conditions.m_Ints[v30 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 5);
        }
        this->m_Conditions.m_Ints[v27 >> 5] &= ~(1 << (v27 & 0x1F));
      }
    }
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002C830
// Name: public: void CBaseEntity::SetSimulationTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetSimulationTime(CBaseEntity *this, float st)
{
  CNetworkVarBase<float,CBaseEntity::NetworkVar_m_flSimulationTime> *p_m_flSimulationTime; // esi
  edict_t *m_pPev; // ecx

  p_m_flSimulationTime = &this->m_flSimulationTime;
  if ( this->m_flSimulationTime.m_Value != st )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flSimulationTime->m_Value = st;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x68u);
      p_m_flSimulationTime->m_Value = st;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C880
// Name: public: virtual void CAI_BaseNPC::OnRangeAttack1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnRangeAttack1(CAI_BaseNPC *this)
{
  double ShotTime; // st7
  edict_t *m_pPev; // ecx
  float v4; // [esp+8h] [ebp-4h]

  this->m_flLastAttackTime = gpGlobals->curtime;
  CAI_ShotRegulator::OnFiredWeapon(this: &this->m_ShotRegulator);
  if ( CAI_ShotRegulator::IsInRestInterval(this: &this->m_ShotRegulator) )
    this->OnUpdateShotRegulator(this);
  ShotTime = CAI_ShotRegulator::NextShotTime(this: &this->m_ShotRegulator);
  v4 = ShotTime;
  if ( this->m_flNextAttack.m_Value != ShotTime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flNextAttack.m_Value = v4;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x684u);
      this->m_flNextAttack.m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C930
// Name: public: virtual void CAI_BaseNPC::StartTargetHandling(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::StartTargetHandling(CAI_BaseNPC *this, CBaseEntity *pTargetEnt)
{
  unsigned __int8 m_Value; // al
  bool v4; // bl
  __int64 v5; // xmm0_8
  float z; // ecx
  NPC_STATE m_NPCState; // edi
  bool v8; // al
  AI_NavGoal_t goal; // [esp+Ch] [ebp-30h] BYREF

  m_Value = this->m_MoveType.m_Value;
  v4 = m_Value == 4 || m_Value == 5;
  if ( (pTargetEnt->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pTargetEnt);
  v5 = *(_QWORD *)&pTargetEnt->m_vecAbsOrigin.x;
  z = pTargetEnt->m_vecAbsOrigin.z;
  m_NPCState = this->m_NPCState;
  goal.destNode = (AI_PathNode_t__ *)-1;
  goal.arrivalActivity = ACT_INVALID;
  goal.arrivalSequence = -1;
  *(_QWORD *)&goal.dest.x = v5;
  goal.type = GOALTYPE_PATHCORNER;
  goal.dest.z = z;
  goal.activity = v4 ? ACT_FLY : ACT_WALK;
  goal.tolerance = -1.0;
  goal.maxInitialSimplificationDist = -1.0;
  goal.flags = 1;
  goal.pTarget = AIN_DEF_TARGET_3;
  if ( m_NPCState != NPC_STATE_IDLE )
    this->m_flLastStateChangeTime = gpGlobals->curtime;
  if ( this->GetEnemy_2(this) != nullptr )
  {
    CAI_BaseNPC::SetEnemy(this, pEnemy: nullptr, bSetCondNewEnemy: true);
    _DevMsg(a1: 2, a2: "Stripped\n");
  }
  v8 = this->m_NPCState != NPC_STATE_IDLE;
  this->m_NPCState = NPC_STATE_IDLE;
  if ( this->m_IdealNPCState != NPC_STATE_IDLE )
    this->m_IdealNPCState = NPC_STATE_IDLE;
  if ( v8 )
    this->OnStateChange(this, a2: m_NPCState, a3: NPC_STATE_IDLE);
  CAI_BaseNPC::SetSchedule(this, localScheduleID: 2);
  if ( !this->m_pNavigator->SetGoal(this: this->m_pNavigator, a2: &goal, a3: 0) )
    _DevWarning(a1: 2, a2: "Can't Create Route!\n");
}

//------------------------------------------------------------------------------
// Address: 0x1002CA70
// Name: public: virtual int CAI_BaseNPC::Save(class ISave __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::Save(CAI_BaseNPC *this, ISave *save)
{
  CAI_BaseNPC_vtbl *v3; // edx
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // eax
  unsigned int m_Index; // eax
  CAI_Schedule *m_pSchedule; // eax
  int v7; // eax
  CAI_Schedule *v8; // eax
  int v9; // eax
  CAI_Schedule *v10; // eax
  CStudioHdr *m_pStudioHdr; // eax
  const char *SequenceName; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // ecx
  unsigned int v21; // eax
  AIExtendedSaveHeader_t saveHeader; // [esp+Ch] [ebp-22Ch] BYREF
  CBitVec<256> ignoreConditions; // [esp+218h] [ebp-20h] BYREF

  v3 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  saveHeader.version = 5;
  GetEnemy_2 = v3->GetEnemy_2;
  saveHeader.flags = 0;
  saveHeader.scheduleCrc = 0;
  saveHeader.szSchedule[0] = 0;
  saveHeader.szIdealSchedule[0] = 0;
  saveHeader.szFailSchedule[0] = 0;
  saveHeader.szSequence[0] = 0;
  if ( (int)GetEnemy_2(this) != 0 )
    saveHeader.flags |= 1u;
  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    saveHeader.flags |= 2u;
  }
  if ( CAI_Navigator::IsGoalActive(this: this->m_pNavigator) )
    saveHeader.flags |= 4u;
  m_pSchedule = this->m_pSchedule;
  if ( m_pSchedule != nullptr )
  {
    V_strncpy(pDest: saveHeader.szSchedule, pSrc: m_pSchedule->m_pName, maxLen: 128);
    CRC32_Init(pulCRC: &saveHeader.scheduleCrc);
    CRC32_ProcessBuffer(
      pulCRC: &saveHeader.scheduleCrc,
      pBuffer: this->m_pSchedule->m_pTaskList,
      nBuffer: 8 * this->m_pSchedule->m_iNumTasks);
    CRC32_Final(pulCRC: &saveHeader.scheduleCrc);
  }
  else
  {
    saveHeader.szSchedule[0] = 0;
    saveHeader.scheduleCrc = 0;
  }
  v7 = this->GetGlobalScheduleId(this, a2: this->m_IdealSchedule);
  if ( v7 != -1 && v7 != 1000000000 && v7 != 1000000057 )
  {
    v8 = this->GetSchedule(this, a2: this->m_IdealSchedule);
    if ( v8 != nullptr )
      V_strncpy(pDest: saveHeader.szIdealSchedule, pSrc: v8->m_pName, maxLen: 128);
  }
  v9 = this->GetGlobalScheduleId(this, a2: this->m_failSchedule);
  if ( v9 != -1 && v9 != 1000000000 && v9 != 1000000057 )
  {
    v10 = this->GetSchedule(this, a2: this->m_failSchedule);
    if ( v10 != nullptr )
      V_strncpy(pDest: saveHeader.szFailSchedule, pSrc: v10->m_pName, maxLen: 128);
  }
  if ( this->m_nSequence.m_Value != -1 )
  {
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: this->m_nSequence.m_Value);
      if ( SequenceName != nullptr && *SequenceName != 0 )
        V_strncpy(pDest: saveHeader.szSequence, pSrc: SequenceName, maxLen: 128);
    }
  }
  save->WriteAll(this: save, a2: &saveHeader, a3: &AIExtendedSaveHeader_t::m_DataMap);
  save->StartBlock(this: save);
  CAI_BaseNPC::SaveConditions(this, save, conditions: &this->m_Conditions);
  CAI_BaseNPC::SaveConditions(this, save, conditions: &this->m_CustomInterruptConditions);
  CAI_BaseNPC::SaveConditions(this, save, conditions: &this->m_ConditionsPreIgnore);
  v14 = ~this->m_InverseIgnoreConditions.m_Ints[6];
  v15 = ~this->m_InverseIgnoreConditions.m_Ints[7];
  v16 = ~this->m_InverseIgnoreConditions.m_Ints[5];
  ignoreConditions.m_Ints[7] = 0;
  ignoreConditions.m_Ints[6] = v14;
  v17 = this->m_InverseIgnoreConditions.m_Ints[3];
  *(_QWORD *)&ignoreConditions.m_Ints[4] = 0;
  ignoreConditions.m_Ints[7] = v15;
  v18 = this->m_InverseIgnoreConditions.m_Ints[4];
  ignoreConditions.m_Ints[5] = v16;
  v19 = this->m_InverseIgnoreConditions.m_Ints[2];
  ignoreConditions.m_Ints[2] = 0;
  ignoreConditions.m_Ints[3] = ~v17;
  v20 = this->m_InverseIgnoreConditions.m_Ints[0];
  ignoreConditions.m_Ints[4] = ~v18;
  v21 = this->m_InverseIgnoreConditions.m_Ints[1];
  ignoreConditions.m_Ints[2] = ~v19;
  ignoreConditions.m_Ints[0] = ~v20;
  ignoreConditions.m_Ints[1] = ~v21;
  CAI_BaseNPC::SaveConditions(this, save, conditions: &ignoreConditions);
  save->EndBlock(this: save);
  save->StartBlock(this: save);
  CAI_Navigator::Save(this: this->m_pNavigator, save);
  save->EndBlock(this: save);
  return CBaseEntity::Save(this, save);
}

//------------------------------------------------------------------------------
// Address: 0x1002CD80
// Name: protected: void CAI_BaseNPC::DiscardScheduleState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::DiscardScheduleState(CAI_BaseNPC *this)
{
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // edx
  unsigned int m_Index; // ecx
  CBaseEntity *(__thiscall *v4)(CBaseEntity *); // eax
  bool v5; // al
  const char *DebugName; // eax

  CAI_Navigator::ClearGoal(this: this->m_pNavigator);
  CAI_BaseNPC::ClearSchedule(this, szReason: "Restoring NPC");
  GetEnemy_2 = this->GetEnemy_2;
  this->m_Activity = ACT_RESET;
  if ( (int)GetEnemy_2(this) == 0 && this != (CAI_BaseNPC *)-2388 )
  {
    *(_QWORD *)this->m_Conditions.m_Ints = 0;
    *(_QWORD *)&this->m_Conditions.m_Ints[2] = 0;
    *(_QWORD *)&this->m_Conditions.m_Ints[4] = 0;
    *(_QWORD *)&this->m_Conditions.m_Ints[6] = 0;
  }
  if ( this->m_NPCState == NPC_STATE_SCRIPT )
  {
    m_Index = this->m_hCine.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      v4 = this->GetEnemy_2;
      this->m_flLastStateChangeTime = gpGlobals->curtime;
      if ( (int)v4(this) != 0 )
      {
        CAI_BaseNPC::SetEnemy(this, pEnemy: nullptr, bSetCondNewEnemy: true);
        _DevMsg(a1: 2, a2: "Stripped\n");
      }
      v5 = this->m_NPCState != NPC_STATE_IDLE;
      this->m_NPCState = NPC_STATE_IDLE;
      if ( this->m_IdealNPCState != NPC_STATE_IDLE )
        this->m_IdealNPCState = NPC_STATE_IDLE;
      if ( v5 )
        this->OnStateChange(this, a2: NPC_STATE_SCRIPT, a3: NPC_STATE_IDLE);
      if ( this->m_IdealNPCState != NPC_STATE_IDLE )
        this->m_IdealNPCState = NPC_STATE_IDLE;
      DebugName = CBaseEntity::GetDebugName(this);
      _DevMsg(a1: 1, a2: "Scripted Sequence stripped on level transition for %s\n", DebugName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CEB0
// Name: public: virtual void CAI_BaseNPC::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnRestore(CAI_BaseNPC *this)
{
  char pszValue[4]; // [esp+4h] [ebp-4h] BYREF

  CAI_BaseNPC::gm_iszPlayerSquad.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
  if ( this->m_bDoPostRestoreRefindPath && CAI_NetworkManager::gm_fNetworksLoaded )
  {
    CAI_DynamicLink::InitDynamicLinks();
    if ( !CAI_Navigator::RefindPathToGoal(
            this: this->m_pNavigator,
            fSignalTaskStatus: false,
            bDontIgnoreBadLinks: false) )
    {
      CAI_BaseNPC::DiscardScheduleState(this);
      CBaseAnimatingOverlay::OnRestore(this);
      this->m_bCheckContacts = true;
      return;
    }
  }
  else
  {
    CAI_Navigator::ClearGoal(this: this->m_pNavigator);
  }
  CBaseAnimatingOverlay::OnRestore(this);
  this->m_bCheckContacts = true;
}

//------------------------------------------------------------------------------
// Address: 0x1002CF40
// Name: public: virtual int CAI_BaseNPC::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::Restore(CAI_BaseNPC *this, IRestore *restore)
{
  IRestore *v2; // edi
  int (__thiscall *ReadAll)(IRestore *, void *, datamap_t *); // edx
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // eax
  int v12; // edi
  CAI_Schedule *ScheduleByName; // eax
  int m_iScheduleID; // eax
  CAI_Schedule *v16; // eax
  int v17; // eax
  char v18; // bl
  int v19; // eax
  unsigned int m_Index; // eax
  bool v21; // bl
  CAI_Schedule *v22; // eax
  AIExtendedSaveHeader_t saveHeader; // [esp+Ch] [ebp-22Ch] BYREF
  CBitVec<256> ignoreConditions; // [esp+218h] [ebp-20h] BYREF

  v2 = restore;
  ReadAll = restore->ReadAll;
  saveHeader.version = 5;
  saveHeader.flags = 0;
  saveHeader.scheduleCrc = 0;
  saveHeader.szSchedule[0] = 0;
  saveHeader.szIdealSchedule[0] = 0;
  saveHeader.szFailSchedule[0] = 0;
  saveHeader.szSequence[0] = 0;
  ReadAll(this: restore, a2: &saveHeader, a3: &AIExtendedSaveHeader_t::m_DataMap);
  if ( saveHeader.version >= 2 )
  {
    v2->StartBlock(this: v2);
    CAI_BaseNPC::RestoreConditions(this, restore: v2, pConditions: &this->m_Conditions);
    CAI_BaseNPC::RestoreConditions(this, restore: v2, pConditions: &this->m_CustomInterruptConditions);
    CAI_BaseNPC::RestoreConditions(this, restore: v2, pConditions: &this->m_ConditionsPreIgnore);
    memset(&ignoreConditions, 0, sizeof(ignoreConditions));
    CAI_BaseNPC::RestoreConditions(this, restore: v2, pConditions: &ignoreConditions);
    v5 = ignoreConditions.m_Ints[5];
    v6 = ~ignoreConditions.m_Ints[6];
    this->m_InverseIgnoreConditions.m_Ints[7] = ~ignoreConditions.m_Ints[7];
    v7 = ignoreConditions.m_Ints[4];
    this->m_InverseIgnoreConditions.m_Ints[6] = v6;
    v8 = ~ignoreConditions.m_Ints[3];
    this->m_InverseIgnoreConditions.m_Ints[4] = ~v7;
    v9 = ignoreConditions.m_Ints[1];
    this->m_InverseIgnoreConditions.m_Ints[3] = v8;
    v10 = ignoreConditions.m_Ints[0];
    this->m_InverseIgnoreConditions.m_Ints[5] = ~v5;
    v11 = ~ignoreConditions.m_Ints[2];
    this->m_InverseIgnoreConditions.m_Ints[1] = ~v9;
    this->m_InverseIgnoreConditions.m_Ints[0] = ~v10;
    this->m_InverseIgnoreConditions.m_Ints[2] = v11;
    v2->EndBlock(this: v2);
  }
  if ( saveHeader.version >= 5 )
  {
    v2->StartBlock(this: v2);
    CAI_Navigator::Restore(this: this->m_pNavigator, restore: v2);
    v2->EndBlock(this: v2);
  }
  v12 = CBaseCombatCharacter::Restore(this, restore: v2);
  if ( v12 == 0 )
    return 0;
  if ( saveHeader.version >= 3 )
  {
    if ( saveHeader.szIdealSchedule[0] != 0 )
    {
      ScheduleByName = CAI_SchedulesManager::GetScheduleByName(
                         this: &g_AI_SchedulesManager,
                         name: saveHeader.szIdealSchedule);
      if ( ScheduleByName != nullptr )
        m_iScheduleID = ScheduleByName->m_iScheduleID;
      else
        m_iScheduleID = 0;
      this->m_IdealSchedule = m_iScheduleID;
    }
    if ( saveHeader.szFailSchedule[0] != 0 )
    {
      v16 = CAI_SchedulesManager::GetScheduleByName(this: &g_AI_SchedulesManager, name: saveHeader.szFailSchedule);
      if ( v16 != nullptr )
        v17 = v16->m_iScheduleID;
      else
        v17 = 0;
      this->m_failSchedule = v17;
    }
  }
  v18 = 0;
  if ( saveHeader.version >= 4 && saveHeader.szSequence[0] != 0 && CBaseAnimating::GetModelPtr(this) != nullptr )
  {
    v19 = CBaseAnimating::LookupSequence(this, label: saveHeader.szSequence);
    CBaseAnimating::SetSequence(this, nSequence: v19);
    if ( this->m_nSequence.m_Value == -1 )
    {
      DevMsg(pAI: this, flags: 1, pszFormat: "Discarding missing sequence %s on load.\n", saveHeader.szSequence);
      CBaseAnimating::SetSequence(this, nSequence: 0);
      v18 = 1;
    }
  }
  v21 = this->m_NPCState == NPC_STATE_SCRIPT
     && ((m_Index = this->m_hCine.m_Index) == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr)
     || v18 != 0
     || saveHeader.szSchedule[0] == 0
     || saveHeader.version < 3
     || (saveHeader.flags & 1) != 0 && this->GetEnemy_2(this) == nullptr
     || (saveHeader.flags & 2) != 0 && CAI_BaseNPC::GetTarget(this) == nullptr;
  if ( this->m_ScheduleState.taskFailureCode >= 29 )
    this->m_ScheduleState.taskFailureCode = 1;
  if ( !v21 )
  {
    v22 = CAI_SchedulesManager::GetScheduleByName(this: &g_AI_SchedulesManager, name: saveHeader.szSchedule);
    this->m_pSchedule = v22;
    if ( v22 != nullptr )
    {
      CRC32_Init(pulCRC: (unsigned int *)&restore);
      CRC32_ProcessBuffer(
        pulCRC: (unsigned int *)&restore,
        pBuffer: this->m_pSchedule->m_pTaskList,
        nBuffer: 8 * this->m_pSchedule->m_iNumTasks);
      CRC32_Final(pulCRC: (unsigned int *)&restore);
      if ( restore != (IRestore *)saveHeader.scheduleCrc )
        this->m_pSchedule = nullptr;
    }
  }
  if ( this->m_pSchedule == nullptr || v21 )
  {
    this->m_bDoPostRestoreRefindPath = false;
    CAI_BaseNPC::DiscardScheduleState(this);
    return v12;
  }
  else
  {
    this->m_bDoPostRestoreRefindPath = (saveHeader.flags & 4) != 0;
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D2A0
// Name: public: virtual CAI_BaseNPC::~CAI_BaseNPC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::~CAI_BaseNPC(CAI_BaseNPC *this)
{
  int m_Size; // ecx
  int v3; // eax
  CAI_Enemies *m_pEnemies; // edi
  CAI_Pathfinder *m_pPathfinder; // ecx
  CAI_Navigator *m_pNavigator; // ecx
  CAI_Motor *m_pMotor; // ecx
  CAI_LocalNavigator *m_pLocalNavigator; // ecx
  CAI_MoveProbe *m_pMoveProbe; // ecx
  CAI_Senses *m_pSenses; // ecx
  CAI_TacticalServices *m_pTacticalServices; // ecx

  this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CAI_BaseNPC_vtbl *)&CAI_BaseNPC::`vftable'{for `CBaseCombatCharacter'};
  this->CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CAI_BaseNPC::`vftable'{for `CAI_DefMovementSink'};
  this->IAI_BehaviorBridge::__vftable = (IAI_BehaviorBridge_vtbl *)&CAI_BaseNPC::`vftable'{for `IAI_BehaviorBridge'};
  m_Size = g_AI_Manager.m_AIs.m_Size;
  v3 = 0;
  if ( g_AI_Manager.m_AIs.m_Size > 0 )
  {
    while ( g_AI_Manager.m_AIs.m_Memory.m_pMemory[v3] != this )
    {
      if ( ++v3 >= g_AI_Manager.m_AIs.m_Size )
        goto LABEL_10;
    }
    if ( v3 != -1 && g_AI_Manager.m_AIs.m_Size > 0 )
    {
      if ( v3 != g_AI_Manager.m_AIs.m_Size - 1 )
      {
        g_AI_Manager.m_AIs.m_Memory.m_pMemory[v3] = g_AI_Manager.m_AIs.m_Memory.m_pMemory[g_AI_Manager.m_AIs.m_Size - 1];
        m_Size = g_AI_Manager.m_AIs.m_Size;
      }
      g_AI_Manager.m_AIs.m_Size = m_Size - 1;
    }
  }
LABEL_10:
  free(pMem: this->m_pLockedBestSound);
  m_pEnemies = this->m_pEnemies;
  if ( m_pEnemies != nullptr )
  {
    CAI_Enemies::~CAI_Enemies(this: this->m_pEnemies);
    free(pMem: m_pEnemies);
  }
  m_pPathfinder = this->m_pPathfinder;
  if ( m_pPathfinder != nullptr )
    ((void (__thiscall *)(CAI_Pathfinder *, int))m_pPathfinder->dtr_CAI_Component)(a1: m_pPathfinder, a2: 1);
  m_pNavigator = this->m_pNavigator;
  if ( m_pNavigator != nullptr )
    ((void (__thiscall *)(CAI_Navigator *, int))m_pNavigator->dtr_CAI_Component)(a1: m_pNavigator, a2: 1);
  m_pMotor = this->m_pMotor;
  if ( m_pMotor != nullptr )
    ((void (__thiscall *)(CAI_Motor *, int))m_pMotor->dtr_CAI_Component)(a1: m_pMotor, a2: 1);
  m_pLocalNavigator = this->m_pLocalNavigator;
  if ( m_pLocalNavigator != nullptr )
    ((void (__thiscall *)(CAI_LocalNavigator *, int))m_pLocalNavigator->dtr_CAI_Component)(a1: m_pLocalNavigator, a2: 1);
  m_pMoveProbe = this->m_pMoveProbe;
  if ( m_pMoveProbe != nullptr )
    ((void (__thiscall *)(CAI_MoveProbe *, int))m_pMoveProbe->dtr_CAI_Component)(a1: m_pMoveProbe, a2: 1);
  m_pSenses = this->m_pSenses;
  if ( m_pSenses != nullptr )
    ((void (__thiscall *)(CAI_Senses *, int))m_pSenses->dtr_CAI_Component)(a1: m_pSenses, a2: 1);
  m_pTacticalServices = this->m_pTacticalServices;
  if ( m_pTacticalServices != nullptr )
    ((void (__thiscall *)(CAI_TacticalServices *, int))m_pTacticalServices->dtr_CAI_Component)(
      a1: m_pTacticalServices,
      a2: 1);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnForcedInteractionFinished);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnForcedInteractionAborted);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnForcedInteractionStarted);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnWake);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnSleep);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnRappelTouchdown);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnDenyCommanderUse);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnDamagedByPlayerSquad);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnDamagedByPlayer);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnHearCombat);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnHearPlayer);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnHearWorld);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnLostPlayer);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnLostPlayerLOS);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnFoundPlayer);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnLostEnemy);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnLostEnemyLOS);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnFoundEnemy);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnHalfHealth);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnDeath);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnDamaged);
  this->m_MoveAndShootOverlay.__vftable = (CAI_MoveAndShootOverlay_vtbl *)&CAI_Component::`vftable';
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_UnreachableEnts);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ScriptedInteractions);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Behaviors);
  CBaseCombatCharacter::~CBaseCombatCharacter(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002D530
// Name: public: virtual int CAI_BaseNPC::GetLocalScheduleId(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::GetLocalScheduleId(CAI_BaseNPC *this, int globalScheduleID)
{
  CAI_ClassScheduleIdSpace *v3; // eax

  if ( globalScheduleID < 1000000000 )
    return globalScheduleID;
  v3 = this->GetClassScheduleIdSpace(this);
  return CAI_LocalIdSpace::GlobalToLocal(this: &v3->m_ScheduleIds, globalID: globalScheduleID);
}

//------------------------------------------------------------------------------
// Address: 0x1002D570
// Name: public: virtual int CAI_BaseNPC::GetGlobalScheduleId(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::GetGlobalScheduleId(CAI_BaseNPC *this, int localScheduleID)
{
  CAI_ClassScheduleIdSpace *v3; // eax

  if ( localScheduleID >= 1000000000 || localScheduleID == -1 )
    return localScheduleID;
  v3 = this->GetClassScheduleIdSpace(this);
  return CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ScheduleIds, localID: localScheduleID);
}

//------------------------------------------------------------------------------
// Address: 0x1002D5B0
// Name: public: virtual int CAI_BaseNPC::GetLocalTaskId(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::GetLocalTaskId(CAI_BaseNPC *this, int globalTaskId)
{
  CAI_ClassScheduleIdSpace *v2; // eax

  v2 = this->GetClassScheduleIdSpace(this);
  return CAI_LocalIdSpace::GlobalToLocal(this: &v2->m_TaskIds, globalID: globalTaskId);
}

//------------------------------------------------------------------------------
// Address: 0x1002D5D0
// Name: public: virtual char const __near * CAI_BaseNPC::GetSchedulingErrorName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAI_BaseNPC::GetSchedulingErrorName(CAI_BaseNPC *this)
{
  return "CAI_BaseNPC";
}

//------------------------------------------------------------------------------
// Address: 0x1002D5E0
// Name: public: virtual bool CAI_BaseNPC::TargetOrder(class CBaseEntity __near *,class CAI_BaseNPC __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::TargetOrder(
        CAI_BaseNPC *this,
        CBaseEntity *pTarget,
        CAI_BaseNPC **Allies,
        CAI_BaseNPC **numAllies)
{
  this->OnTargetOrder(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002D5F0
// Name: public: virtual bool CAI_BaseNPC::CanPlaySentence(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::CanPlaySentence(CAI_BaseNPC *this, bool fDisregardState)
{
  return this->IsAlive(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002D600
// Name: public: virtual void CAI_BaseNPC::BarnacleDeathSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::BarnacleDeathSound(CAI_BaseNPC *this)
{
  CTakeDamageInfo info; // [esp+4h] [ebp-5Ch] BYREF

  CTakeDamageInfo::CTakeDamageInfo(this: &info);
  this->PainSound(this, a2: &info);
}

//------------------------------------------------------------------------------
// Address: 0x1002D630
// Name: public: virtual float CAI_BaseNPC::StepHeight(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::StepHeight(CAI_BaseNPC *this)
{
  return 18.0;
}

//------------------------------------------------------------------------------
// Address: 0x1002D640
// Name: public: virtual float CAI_BaseNPC::GetMaxJumpSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::GetMaxJumpSpeed(CAI_BaseNPC *this)
{
  return 350.0;
}

//------------------------------------------------------------------------------
// Address: 0x1002D650
// Name: public: virtual float CAI_BaseNPC::GetJumpGravity(void)const
// Source: json
//------------------------------------------------------------------------------
float __thiscall CAI_BaseNPC::GetJumpGravity(CAI_BaseNPC *this)
{
  return this->GetDefaultJumpGravity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002D660
// Name: public: virtual class Vector CAI_BaseNPC::GetNodeViewOffset(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::GetNodeViewOffset(CAI_BaseNPC *this, Vector *result)
{
  const Vector *v2; // eax
  __int64 v3; // xmm0_8
  float z; // eax

  v2 = this->GetViewOffset(this);
  v3 = *(_QWORD *)&v2->x;
  z = v2->z;
  *(_QWORD *)&result->x = v3;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D690
// Name: public: virtual char const __near * CAI_BaseNPC::SquadSlotName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAI_BaseNPC::SquadSlotName(CAI_BaseNPC *this, int slotID)
{
  return CAI_GlobalNamespace::IdToSymbol(this: &CAI_BaseNPC::gm_SquadSlotNamespace, symbolID: slotID);
}

//------------------------------------------------------------------------------
// Address: 0x1002D6A0
// Name: public: virtual bool CAI_BaseNPC::TestShootPosition(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::TestShootPosition(CAI_BaseNPC *this, const Vector *vecShootPos, const Vector *targetPos)
{
  return this->WeaponLOSCondition(this, a2: vecShootPos, a3: targetPos, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x1002D6C0
// Name: public: virtual float CAI_BaseNPC::CoverRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::CoverRadius(CAI_BaseNPC *this)
{
  return 1024.0;
}

//------------------------------------------------------------------------------
// Address: 0x1002D6E0
// Name: public: virtual float CAI_BaseNPC::InnateRange1MaxRange(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::InnateRange1MaxRange(CAI_BaseNPC *this)
{
  return 3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x1002D6F0
// Name: public: virtual class Vector CAI_BaseNPC::GetAutoAimCenter(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::GetAutoAimCenter(CAI_BaseNPC *this, Vector *result)
{
  this->BodyTarget(this, result, a3: &vec3_origin, a4: false);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D710
// Name: public: virtual int CAI_BaseNPC::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::ObjectCaps(CAI_BaseNPC *this)
{
  return CBaseEntity::ObjectCaps(this) | 0x200;
}

//------------------------------------------------------------------------------
// Address: 0x1002D720
// Name: public: virtual class CAI_ClassScheduleIdSpace __near * CAI_BaseNPC::GetClassScheduleIdSpace(void)
// Source: json
//------------------------------------------------------------------------------
CAI_ClassScheduleIdSpace *__thiscall CAI_BaseNPC::GetClassScheduleIdSpace(CAI_BaseNPC *this)
{
  return &CAI_BaseNPC::gm_ClassScheduleIdSpace;
}

//------------------------------------------------------------------------------
// Address: 0x1002D730
// Name: public: virtual bool CAI_BaseNPC::IsMovementFrozen(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsMovementFrozen(CAI_BaseNPC *this)
{
  return this->m_flMovementFrozen > this->m_flFrozenMoveBlock;
}

//------------------------------------------------------------------------------
// Address: 0x1002D750
// Name: public: virtual bool CAI_BaseNPC::IsAttackFrozen(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::IsAttackFrozen(CAI_BaseNPC *this)
{
  return this->m_flAttackFrozen > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1002D770
// Name: public: virtual void CBaseEntity::MoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::MoveDone(CBaseEntity *this)
{
  void (*m_pfnMoveDone)(void); // eax

  m_pfnMoveDone = (void (*)(void))this->m_pfnMoveDone;
  if ( m_pfnMoveDone != nullptr )
    m_pfnMoveDone();
}

//------------------------------------------------------------------------------
// Address: 0x1002D780
// Name: public: virtual void CBaseEntity::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::Think(CBaseEntity *this)
{
  void (*m_pfnThink)(void); // eax

  m_pfnThink = (void (*)(void))this->m_pfnThink;
  if ( m_pfnThink != nullptr )
    m_pfnThink();
}

//------------------------------------------------------------------------------
// Address: 0x1002D790
// Name: public: virtual void CBaseEntity::GetGroundVelocityToApply(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::GetGroundVelocityToApply(CBaseEntity *this, Vector *vecGroundVel)
{
  *vecGroundVel = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x1002D7C0
// Name: class CBaseEntity __near * GetContainingEntity(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl GetContainingEntity(edict_t *pent)
{
  IServerUnknown *m_pUnk; // ecx

  if ( pent != nullptr && (m_pUnk = pent->m_pUnk) != nullptr )
    return m_pUnk->GetBaseEntity(this: m_pUnk);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D7E0
// Name: public: virtual class ICollideable __near * CBaseEntity::GetCollideable(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity::NetworkVar_m_Collision *__thiscall CBaseEntity::GetCollideable(CBaseEntity *this)
{
  return &this->m_Collision;
}

//------------------------------------------------------------------------------
// Address: 0x1002D7F0
// Name: public: virtual class IServerNetworkable __near * CBaseEntity::GetNetworkable(void)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CBaseEntity::GetNetworkable(CBaseEntity *this)
{
  return &this->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1002D810
// Name: public: virtual struct string_t CBaseEntity::GetModelName(void)const
// Source: json
//------------------------------------------------------------------------------
string_t __thiscall CBaseEntity::GetModelName(CBaseEntity *this, const char **a2)
{
  *a2 = this->m_ModelName.pszValue;
  return (string_t)a2;
}

//------------------------------------------------------------------------------
// Address: 0x1002D830
// Name: public: virtual struct string_t CBaseEntity::GetAIAddOn(void)const
// Source: json
//------------------------------------------------------------------------------
string_t __thiscall CBaseEntity::GetAIAddOn(CBaseEntity *this, const char **a2)
{
  *a2 = this->m_AIAddOn.pszValue;
  return (string_t)a2;
}

//------------------------------------------------------------------------------
// Address: 0x1002D850
// Name: public: virtual class CBaseHandle const __near & CBaseEntity::GetRefEHandle(void)const
// Source: json
//------------------------------------------------------------------------------
const CBaseHandle *__thiscall CBaseEntity::GetRefEHandle(CBaseEntity *this)
{
  return &this->m_RefEHandle;
}

//------------------------------------------------------------------------------
// Address: 0x1002D860
// Name: public: virtual void CBaseAnimating::ClampRagdollForce(class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::ClampRagdollForce(CBaseAnimating *this, const Vector *vecForceIn, Vector *vecForceOut)
{
  *vecForceOut = *vecForceIn;
}

//------------------------------------------------------------------------------
// Address: 0x1002D880
// Name: public: virtual void CBaseAnimating::Extinguish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::Extinguish(CBaseAnimating *this)
{
  CBaseEntity::RemoveFlag(this, flagsToRemove: 0x10000000);
}

//------------------------------------------------------------------------------
// Address: 0x1002D8B0
// Name: public: virtual int CAI_BaseNPC::NumBehaviors(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::NumBehaviors(CAI_BaseNPC *this)
{
  return this->m_Behaviors.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1002D8C0
// Name: public: virtual class CBaseEntity __near * CAI_BaseNPC::GetEnemy(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_BaseNPC::GetEnemy(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hEnemy.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1002D8F0
// Name: public: virtual bool CAI_BaseNPC::CurrentWeaponLOSCondition(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::CurrentWeaponLOSCondition(CAI_BaseNPC *this, const Vector *targetPos, BOOL bSetConditions)
{
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  return this->WeaponLOSCondition(this, a2: &this->m_vecAbsOrigin, a3: targetPos, a4: bSetConditions);
}

//------------------------------------------------------------------------------
// Address: 0x1002D930
// Name: protected: virtual class Vector CAI_BaseNPC::GetCrouchEyeOffset(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::GetCrouchEyeOffset(CAI_BaseNPC *this, Vector *result)
{
  result->x = 0.0;
  result->y = 0.0;
  result->z = 40.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D960
// Name: protected: virtual class Vector CAI_BaseNPC::GetCrouchGunOffset(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::GetCrouchGunOffset(CAI_BaseNPC *this, Vector *result)
{
  result->x = 0.0;
  result->y = 0.0;
  result->z = 36.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D990
// Name: public: float IntervalTimer::GetElapsedTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall IntervalTimer::GetElapsedTime(IntervalTimer *this)
{
  if ( this->m_timestamp.m_Value <= 0.0 )
    return 99999.898;
  else
    return IntervalTimer::Now((CEffectsServer *)this) - this->m_timestamp.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1002DA20
// Name: public: virtual float CBaseEntity::GetFriction(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseEntity::GetFriction(CBaseEntity *this)
{
  return this->m_flFriction.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1002DA30
// Name: public: virtual int CBaseEntity::GetModelIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::GetModelIndex(CBaseEntity *this)
{
  return this->m_nModelIndex.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1002DA40
// Name: public: virtual bool CBaseEntity::IsAlive(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseEntity::IsAlive(CBaseEntity *this)
{
  return this->m_lifeState.m_Value == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002DA50
// Name: public: virtual bool CBaseAnimating::IsFrozen(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseAnimating::IsFrozen(CBaseAnimating *this)
{
  return this->m_flFrozen.m_Value >= 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1002DA70
// Name: public: virtual float CBaseCombatCharacter::GetAliveDuration(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatCharacter::GetAliveDuration(CBaseCombatCharacter *this)
{
  if ( this->m_aliveTimer.m_timestamp.m_Value <= 0.0 )
    return 99999.898;
  else
    return IntervalTimer::Now(this: (CEffectsServer *)&this->m_aliveTimer) - this->m_aliveTimer.m_timestamp.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1002DAB0
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBaseAnimating::NetworkVar_m_hLightingOrigin>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBaseAnimating::NetworkVar_m_hLightingOrigin>::Set(
        CNetworkHandleBase<CBaseEntity,CBaseAnimating::NetworkVar_m_hLightingOrigin> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBaseAnimating::NetworkVar_m_hLightingOrigin> *v5; // eax
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
    v5 = this - 269;
    if ( *((_BYTE *)this - 992) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x434u);
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
// Address: 0x1002DB40
// Name: public: virtual class CAI_BehaviorBase __near * __near * CAI_BaseNPC::AccessBehaviors(void)
// Source: json
//------------------------------------------------------------------------------
CAI_BehaviorBase **__thiscall CAI_BaseNPC::AccessBehaviors(CAI_BaseNPC *this)
{
  if ( this->m_Behaviors.m_Size != 0 )
    return this->m_Behaviors.m_Memory.m_pMemory;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DB60
// Name: public: virtual float CAI_BaseNPC::GetDefaultNavGoalTolerance(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::GetDefaultNavGoalTolerance(CAI_BaseNPC *this)
{
  double v1; // st7

  v1 = NAI_Hull::Width(id: this->m_eHull);
  return v1 + v1;
}

//------------------------------------------------------------------------------
// Address: 0x1002DB80
// Name: public: virtual bool CAI_BaseNPC::ShouldCheckPhysicsContacts(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::ShouldCheckPhysicsContacts(CAI_BaseNPC *this)
{
  return this->m_MoveType.m_Value == 3 && this->m_pPhysicsObject != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DBA0
// Name: public: virtual bool CBaseEntity::ShouldAttractAutoAim(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseEntity::ShouldAttractAutoAim(CBaseEntity *this, CBaseEntity *pAimingEnt)
{
  return (this->m_fFlags.m_Value & 0x20000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002DBB0
// Name: public: virtual void CBaseEntity::SetHealth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetHealth(CBaseEntity *this, int amt)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // esi

  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value != amt )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    p_m_iHealth->m_Value = amt;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DC00
// Name: public: virtual void CAI_BaseNPC::MoveOrder(class Vector const __near &,class CAI_BaseNPC __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::MoveOrder(CAI_BaseNPC *this, const Vector *vecDest, CAI_BaseNPC **Allies, int numAllies)
{
  CAI_ClassScheduleIdSpace *v5; // eax
  int v6; // eax
  int v7; // edi
  CAI_ClassScheduleIdSpace *v8; // eax
  int v9; // eax
  int v10; // eax

  this->SetCommandGoal(this, a2: vecDest);
  v5 = this->GetClassScheduleIdSpace(this);
  v6 = CAI_LocalIdSpace::LocalToGlobal(this: &v5->m_ConditionIds, localID: 63);
  if ( v6 != -1 )
  {
    v7 = v6 - 1000000000;
    if ( v6 != 999999999 )
    {
      v8 = this->GetClassScheduleIdSpace(this);
      v9 = CAI_LocalIdSpace::LocalToGlobal(this: &v8->m_ConditionIds, localID: 63);
      if ( v9 == -1 || (v10 = v9 - 1000000000) == -1 || ((1 << (v10 & 0x1F)) & this->m_Conditions.m_Ints[v10 >> 5]) == 0 )
        this->OnConditionSet(this, a2: 63);
      this->m_Conditions.m_Ints[v7 >> 5] |= 1 << (v7 & 0x1F);
    }
  }
  this->OnMoveOrder(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002DCC0
// Name: public: virtual void CBaseEntity::SetModelIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetModelIndex(CBaseEntity *this, __int16 index)
{
  edict_t *m_pPev; // ecx

  if ( this->m_nModelIndex.m_Value != index )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB6u);
    }
    this->m_nModelIndex.m_Value = index;
  }
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002DD10
// Name: public: bool CAI_BaseNPC::CineCleanup(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall CAI_BaseNPC::CineCleanup@<al>(CAI_BaseNPC *this@<ecx>, int a2@<ebp>)
{
  CBaseEntityList *v2; // edx
  unsigned int m_Index; // eax
  IHandleEntity_vtbl *m_Value; // ecx
  bool v6; // zf
  unsigned int v7; // ecx
  int v8; // eax
  CEntInfo *v9; // edi
  unsigned int v10; // ecx
  int v11; // eax
  CBaseEntity **v12; // eax
  CBaseEntity *v13; // eax
  unsigned int v14; // eax
  CEntInfo *v15; // edx
  unsigned int v16; // ecx
  int v17; // eax
  CEntInfo *v18; // edi
  unsigned int v19; // ecx
  int v20; // eax
  CEntInfo *v21; // edx
  IHandleEntity *m_pEntity; // edx
  unsigned int v23; // eax
  IHandleEntity *v24; // ecx
  unsigned int v25; // eax
  NPC_STATE m_NPCState; // eax
  const Vector *v27; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v28; // edx
  float v29; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v30; // edx
  float x; // xmm2_4
  float v32; // xmm1_4
  CBaseEntity::NetworkVar_m_Collision_vtbl *v33; // edx
  float v34; // xmm0_4
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  const Vector *v36; // eax
  edict_t *m_pPev; // ecx
  float v39; // xmm2_4
  float y; // xmm3_4
  float z; // eax
  __int128 v42; // xmm0
  unsigned int m_nAITraceMask; // edi
  CBasePlayer *LocalPlayer; // eax
  int v45; // eax
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  __int128 v50; // xmm0
  CAI_ClassScheduleIdSpace *v51; // eax
  int v52; // eax
  int v53; // edi
  CAI_ClassScheduleIdSpace *v54; // eax
  int v55; // eax
  int v56; // eax
  unsigned int v57; // edi
  edict_t *v58; // ecx
  QAngle v59; // [esp+2Ch] [ebp-68h] BYREF
  __int128 new_angle; // [esp+38h] [ebp-5Ch] OVERLAPPED BYREF
  Vector v61; // [esp+54h] [ebp-40h] BYREF
  Vector new_origin; // [esp+60h] [ebp-34h] BYREF
  Vector oldOrigin; // [esp+6Ch] [ebp-28h] BYREF
  Vector origin; // [esp+78h] [ebp-1Ch] BYREF
  char v65; // [esp+87h] [ebp-Dh]
  int v66; // [esp+88h] [ebp-Ch]
  void *v67; // [esp+8Ch] [ebp-8h]
  void *retaddr; // [esp+94h] [ebp+0h]

  v66 = a2;
  v67 = retaddr;
  v2 = g_pEntityList;
  m_Index = this->m_hCine.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    origin.z = 0.0;
  else
    LODWORD(origin.z) = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_Index == -1 )
    goto LABEL_12;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    v2 = g_pEntityList;
    goto LABEL_12;
  }
  v2 = g_pEntityList;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
LABEL_12:
    m_Value = (IHandleEntity_vtbl *)this->m_fFlags.m_Value;
    goto LABEL_13;
  }
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    m_Value = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity[230].__vftable;
  else
    m_Value = (IHandleEntity_vtbl *)MEMORY[0x398];
LABEL_13:
  v6 = this->m_iInteractionState == 0;
  LODWORD(origin.y) = m_Value;
  v65 = 0;
  if ( !v6
    && m_Index != -1
    && v2->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && v2->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v7 = this->m_hInteractionPartner.m_Index;
    v65 = 1;
    if ( v7 != -1 )
    {
      v8 = (unsigned __int16)v7;
      v9 = &v2->m_EntPtrArray[(unsigned __int16)v7];
      v10 = HIWORD(v7);
      if ( v9->m_SerialNumber == v10 && v9->m_pEntity != nullptr )
      {
        v11 = v8;
        v6 = v2->m_EntPtrArray[v11].m_SerialNumber == v10;
        v12 = (CBaseEntity **)&v2->m_EntPtrArray[v11];
        if ( v6 )
          v13 = *v12;
        else
          v13 = nullptr;
        PhysEnableEntityCollisions(pEntity0: this, pEntity1: v13);
        v2 = g_pEntityList;
      }
    }
    v14 = this->m_hForcedInteractionPartner.m_Index;
    if ( v14 != -1 )
    {
      v15 = &v2->m_EntPtrArray[(unsigned __int16)v14];
      if ( v15->m_SerialNumber == HIWORD(v14) && v15->m_pEntity != nullptr )
        COutputEvent::FireOutput(
          this: &this->m_OnForcedInteractionFinished,
          pActivator: this,
          pCaller: this,
          fDelay: 0.0);
    }
    this->m_hInteractionPartner.m_Index = -1;
    this->m_hForcedInteractionPartner.m_Index = -1;
    this->m_iInteractionPlaying = -1;
    this->m_iInteractionState = 0;
    this->m_flForcedInteractionTimeout = 0.0;
    v2 = g_pEntityList;
  }
  v16 = this->m_hCine.m_Index;
  if ( v16 != -1
    && (v17 = (unsigned __int16)v16,
        v18 = &v2->m_EntPtrArray[(unsigned __int16)v16],
        v19 = HIWORD(v16),
        v18->m_SerialNumber == v19)
    && v18->m_pEntity != nullptr )
  {
    v20 = v17;
    v6 = v2->m_EntPtrArray[v20].m_SerialNumber == v19;
    v21 = &v2->m_EntPtrArray[v20];
    if ( v6 )
      m_pEntity = v21->m_pEntity;
    else
      m_pEntity = nullptr;
    m_pEntity[233].__vftable = (IHandleEntity_vtbl *)-1;
    v23 = this->m_hCine.m_Index;
    if ( v23 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != HIWORD(v23) )
      v24 = nullptr;
    else
      v24 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
    CBaseEntity::SetEffects(this, nEffects: (int)v24[229].__vftable);
    v25 = this->m_hCine.m_Index;
    if ( v25 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_SerialNumber != HIWORD(v25) )
      CBaseEntity::SetCollisionGroup(this, collisionGroup: MEMORY[0x39C]);
    else
      CBaseEntity::SetCollisionGroup(
        this,
        collisionGroup: (int)g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_pEntity[231].__vftable);
  }
  else
  {
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
  }
  this->m_hCine.m_Index = -1;
  this->m_hTargetEnt.m_Index = -1;
  this->m_hGoalEnt.m_Index = -1;
  if ( this->m_lifeState.m_Value == 1 )
  {
    if ( this->m_iHealth.m_Value > 0 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      this->m_iHealth.m_Value = 0;
    }
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    m_NPCState = this->m_NPCState;
    if ( m_NPCState != NPC_STATE_DEAD )
      this->m_flLastStateChangeTime = gpGlobals->curtime;
    this->m_NPCState = NPC_STATE_DEAD;
    if ( this->m_IdealNPCState != NPC_STATE_DEAD )
      this->m_IdealNPCState = NPC_STATE_DEAD;
    if ( m_NPCState != NPC_STATE_DEAD )
      this->OnStateChange(this, a2: m_NPCState, a3: NPC_STATE_DEAD);
    if ( this->m_lifeState.m_Value != 2 )
    {
      this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
      this->m_lifeState.m_Value = 2;
    }
    v27 = this->m_Collision.OBBMins(this: &this->m_Collision);
    v28 = this->m_Collision.CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::__vftable;
    LODWORD(origin.x) = v27;
    v29 = COERCE_FLOAT((int)v28->OBBMaxs(this: &this->m_Collision));
    v30 = this->m_Collision.CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::__vftable;
    origin.y = v29;
    x = v30->OBBMaxs(this: &this->m_Collision)->x;
    v32 = *(float *)(LODWORD(origin.y) + 4);
    v33 = this->m_Collision.CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::__vftable;
    v34 = *(float *)(LODWORD(origin.x) + 8) + 2.0;
    LODWORD(origin.z) = &v61;
    OBBMins = v33->OBBMins;
    v61.x = x;
    v61.y = v32;
    v61.z = v34;
    v36 = OBBMins(this: &this->m_Collision);
    UTIL_SetSize(pEnt: this, vecMin: v36, vecMax: (const Vector *)LODWORD(origin.z));
    if ( LODWORD(origin.z) != 0 && (*(_DWORD *)(LODWORD(origin.z) + 760) & 8) != 0 )
    {
      memset((void *)&origin, 0, sizeof(origin));
      this->m_pfnUse = nullptr;
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))LODWORD(origin.x),
        thinkTime: origin.y,
        szContext: (const char *)LODWORD(origin.z));
      this->m_pfnTouch = nullptr;
    }
    else
    {
      CBaseEntity::SUB_StartFadeOut(this, delay: 10.0, notSolid: true);
    }
    if ( !this->CanBecomeRagdoll(this) )
    {
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
    }
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    return 0;
  }
  else
  {
    if ( LODWORD(origin.z) != 0 && *(_DWORD *)(LODWORD(origin.z) + 860) != 0 && *(_BYTE *)(LODWORD(origin.z) + 929) != 0 )
    {
      if ( (*(_DWORD *)(LODWORD(origin.z) + 760) & 0x80) == 0 )
      {
        CBaseAnimating::GetBonePosition(this, iBone: 0, origin: &v61, angles: &v59);
        v39 = v61.x;
        y = v61.y;
        z = this->m_vecOrigin.m_Value.z;
        *(_QWORD *)&new_origin.x = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
        v42 = 0;
        new_origin.z = z;
        *(float *)&v42 = fsqrt(
                           (float)((float)(new_origin.y - y) * (float)(new_origin.y - y))
                         + (float)((float)(new_origin.x - v39) * (float)(new_origin.x - v39)));
        new_angle = v42;
        if ( *(float *)&v42 < 8.0 )
        {
          v39 = new_origin.x;
          y = new_origin.y;
          v61 = new_origin;
        }
        oldOrigin.z = this->m_vecOrigin.m_Value.z;
        oldOrigin.x = v39;
        oldOrigin.y = y;
        oldOrigin.z = oldOrigin.z + 1.0;
        if ( (LOWORD(origin.y) & 0x800) != 0 )
        {
          oldOrigin.z = v61.z;
          CBaseEntity::SetLocalOrigin(this, origin: &oldOrigin);
        }
        else
        {
          CBaseEntity::SetLocalOrigin(this, origin: &oldOrigin);
          m_nAITraceMask = this->m_nAITraceMask;
          LocalPlayer = UTIL_GetLocalPlayer();
          v45 = UTIL_DropToFloor(pEntity: this, mask: m_nAITraceMask, pIgnore: LocalPlayer);
          if ( v45 < 0
            || sv_test_scripted_sequences.m_pParent != nullptr
            && sv_test_scripted_sequences.m_pParent->m_Value.m_nValue != 0 )
          {
            CBaseEntity::SetLocalOrigin(this, origin: &new_origin);
          }
          else if ( v45 == 0 )
          {
            *(_QWORD *)((char *)&new_angle + 4) = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
            HIDWORD(new_angle) = LODWORD(v61.z);
            CBaseEntity::SetLocalOrigin(this, origin: (const Vector *)((char *)&new_angle + 4));
            CBaseEntity::SetGroundEntity(this, ground: nullptr);
          }
        }
        v46 = this->m_vecOrigin.m_Value.y;
        v47 = this->m_vecOrigin.m_Value.z;
        v48 = new_origin.x - this->m_vecOrigin.m_Value.x;
        oldOrigin.x = this->m_vecOrigin.m_Value.x;
        oldOrigin.y = v46;
        v49 = (float)((float)((float)(new_origin.y - v46) * (float)(new_origin.y - v46))
                    + (float)((float)(new_origin.z - v47) * (float)(new_origin.z - v47)))
            + (float)(v48 * v48);
        v50 = 0;
        oldOrigin.z = v47;
        *(float *)&v50 = fsqrt(v49);
        new_angle = v50;
        if ( *(float *)&v50 > 8.0 )
        {
          this->Teleport(this, a2: &oldOrigin, a3: nullptr, a4: nullptr, a5: true);
          CBaseEntity::SetLocalOrigin(this, origin: &oldOrigin);
          CBaseEntity::AddEffects(this, nEffects: 8);
        }
        if ( this->m_iHealth.m_Value <= 0 )
        {
          if ( this->m_IdealNPCState != NPC_STATE_DEAD )
            this->m_IdealNPCState = NPC_STATE_DEAD;
          CAI_BaseNPC::SetCondition(this, iCondition: 17);
          if ( this->m_lifeState.m_Value != 1 )
          {
            this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
            this->m_lifeState.m_Value = 1;
          }
        }
      }
      this->m_Activity = ACT_RESET;
    }
    if ( this->m_iHealth.m_Value <= 0 )
    {
      if ( this->m_IdealNPCState != NPC_STATE_DEAD )
        this->m_IdealNPCState = NPC_STATE_DEAD;
      v51 = this->GetClassScheduleIdSpace(this);
      v52 = CAI_LocalIdSpace::LocalToGlobal(this: &v51->m_ConditionIds, localID: 17);
      if ( v52 != -1 )
      {
        v53 = v52 - 1000000000;
        if ( v52 != 999999999 )
        {
          v54 = this->GetClassScheduleIdSpace(this);
          v55 = CAI_LocalIdSpace::LocalToGlobal(this: &v54->m_ConditionIds, localID: 17);
          if ( v55 == -1
            || (v56 = v55 - 1000000000) == -1
            || ((1 << (v56 & 0x1F)) & this->m_Conditions.m_Ints[v56 >> 5]) == 0 )
          {
            this->OnConditionSet(this, a2: 17);
          }
          this->m_Conditions.m_Ints[v53 >> 5] |= 1 << (v53 & 0x1F);
        }
      }
    }
    else if ( this->m_IdealNPCState != NPC_STATE_IDLE )
    {
      this->m_IdealNPCState = NPC_STATE_IDLE;
    }
    v57 = this->m_spawnflags.m_Value & 0xFFFFFF7F;
    if ( this->m_spawnflags.m_Value != v57 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v58 = this->m_Network.m_pPev;
        if ( v58 != nullptr )
          CBaseEdict::StateChanged(this: &v58->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v57;
    }
    if ( v65 != 0 )
      UTIL_Remove(oldObj: (CBaseEntity *)LODWORD(origin.z));
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E570
// Name: public: void CAI_BaseNPC::InputSetSpeedModifierRadius(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputSetSpeedModifierRadius(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  const char *pszValue; // edi
  CNetworkVarBase<int,CAI_BaseNPC::NetworkVar_m_iSpeedModRadius> *p_m_iSpeedModRadius; // esi
  edict_t *m_pPev; // ecx
  int m_Value; // eax
  int v6; // edi
  CNetworkVarBase<int,CAI_BaseNPC::NetworkVar_m_iSpeedModRadius> *v7; // eax
  CBaseEdict *v8; // ecx

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_iSpeedModRadius = &this->m_iSpeedModRadius;
  if ( (const char *)this->m_iSpeedModRadius.m_Value != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE6Cu);
    }
    p_m_iSpeedModRadius->m_Value = (int)pszValue;
  }
  m_Value = p_m_iSpeedModRadius->m_Value;
  v6 = m_Value * m_Value;
  if ( m_Value != m_Value * m_Value )
  {
    v7 = p_m_iSpeedModRadius - 923;
    if ( LOBYTE(p_m_iSpeedModRadius[-902].m_Value) != 0 )
    {
      LOBYTE(v7[22].m_Value) |= 1u;
      p_m_iSpeedModRadius->m_Value = v6;
    }
    else
    {
      v8 = (CBaseEdict *)v7[6].m_Value;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: v8, offset: 0xE6Cu);
      p_m_iSpeedModRadius->m_Value = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E600
// Name: public: void CAI_BaseNPC::InputSetSpeedModifierSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputSetSpeedModifierSpeed(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  const char *pszValue; // edi
  CNetworkVarBase<int,CAI_BaseNPC::NetworkVar_m_iSpeedModSpeed> *p_m_iSpeedModSpeed; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_iSpeedModSpeed = &this->m_iSpeedModSpeed;
  if ( (const char *)this->m_iSpeedModSpeed.m_Value != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iSpeedModSpeed->m_Value = (int)pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE70u);
      p_m_iSpeedModSpeed->m_Value = (int)pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E6B0
// Name: public: void CAI_BaseNPC::InputGagEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputGagEnable(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_spawnflags = &this->m_spawnflags;
  v3 = this->m_spawnflags.m_Value | 2;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_spawnflags->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E700
// Name: public: void CAI_BaseNPC::InputGagDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::InputGagDisable(CAI_BaseNPC *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_spawnflags = &this->m_spawnflags;
  v3 = this->m_spawnflags.m_Value & 0xFFFFFFFD;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_spawnflags->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E750
// Name: public: CAI_Senses::CAI_Senses(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Senses *__thiscall CAI_Senses::CAI_Senses(CAI_Senses *this)
{
  this->m_LookDist = 2048.0;
  this->m_pOuter = nullptr;
  this->__vftable = (CAI_Senses_vtbl *)&CAI_Senses::`vftable';
  this->m_LastLookDist = -1.0;
  this->m_TimeLastLook = -1.0;
  this->m_iAudibleList = 0;
  this->m_SeenHighPriority.m_Memory.m_pMemory = nullptr;
  this->m_SeenHighPriority.m_Memory.m_nAllocationCount = 0;
  this->m_SeenHighPriority.m_Memory.m_nGrowSize = 0;
  this->m_SeenHighPriority.m_Size = 0;
  this->m_SeenHighPriority.m_pElements = nullptr;
  this->m_SeenNPCs.m_Memory.m_pMemory = nullptr;
  this->m_SeenNPCs.m_Memory.m_nAllocationCount = 0;
  this->m_SeenNPCs.m_Memory.m_nGrowSize = 0;
  this->m_SeenNPCs.m_Size = 0;
  this->m_SeenNPCs.m_pElements = nullptr;
  this->m_SeenMisc.m_Memory.m_pMemory = nullptr;
  this->m_SeenMisc.m_Memory.m_nAllocationCount = 0;
  this->m_SeenMisc.m_Memory.m_nGrowSize = 0;
  this->m_SeenMisc.m_Size = 0;
  this->m_SeenMisc.m_pElements = nullptr;
  this->m_SeenArrays[2] = &this->m_SeenMisc;
  this->m_SeenArrays[1] = &this->m_SeenNPCs;
  this->m_TimeLastLookHighPriority = -1.0;
  this->m_TimeLastLookNPCs = -1.0;
  this->m_TimeLastLookMisc = -1.0;
  this->m_SeenArrays[0] = &this->m_SeenHighPriority;
  this->m_iSensingFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002E7E0
// Name: public: virtual bool CAI_Senses::IsWithinSenseDistance(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_Senses::IsWithinSenseDistance(
        CAI_Senses *this,
        const Vector *source,
        const Vector *dest,
        float dist)
{
  return (float)(dist * dist) > (float)((float)((float)((float)(source->y - dest->y) * (float)(source->y - dest->y))
                                              + (float)((float)(source->x - dest->x) * (float)(source->x - dest->x)))
                                      + (float)((float)(source->z - dest->z) * (float)(source->z - dest->z)));
}

//------------------------------------------------------------------------------
// Address: 0x1002E840
// Name: public: virtual char const __near * CPostFrameNavigationHook::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPostFrameNavigationHook::Name(CPostFrameNavigationHook *this)
{
  return "CPostFrameNavigationHook";
}

//------------------------------------------------------------------------------
// Address: 0x1002E880
// Name: public: virtual void CPostFrameNavigationHook::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostFrameNavigationHook::FrameUpdatePostEntityThink(CPostFrameNavigationHook *this)
{
  int m_Size; // esi
  CFunctor **m_pMemory; // edi
  CFunctor *v3; // eax
  CJob *v4; // [esp+0h] [ebp-4h] BYREF

  v4 = (CJob *)this;
  if ( ai_post_frame_navigation.m_pParent != nullptr && ai_post_frame_navigation.m_pParent->m_Value.m_nValue != 0 )
  {
    m_Size = this->m_Functors.m_Size;
    this->m_bGameFrameRunning = false;
    m_pMemory = this->m_Functors.m_Memory.m_pMemory;
    v3 = (CFunctor *)operator new(nSize: 0x1Cu);
    if ( v3 != nullptr )
    {
      v3[1].m_nUserID = 1;
      v3->__vftable = (CFunctor_vtbl *)&CFunctor2<void (__cdecl *)(CFunctor * *,unsigned int),CFunctor * *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      v3[1].__vftable = (CFunctor_vtbl *)&CFunctor2<void (__cdecl *)(CFunctor * *,unsigned int),CFunctor * *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v3[2].__vftable = (CFunctor_vtbl *)ProcessNavigationQueries;
      v3[2].m_nUserID = (unsigned int)m_pMemory;
      v3[3].__vftable = (CFunctor_vtbl *)m_Size;
    }
    else
    {
      v3 = nullptr;
    }
    _g_pThreadPool->AddFunctorInternal(this: _g_pThreadPool, a2: v3, a3: &v4, a4: nullptr, a5: 8u);
    g_pQueuedNavigationQueryJob = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E900
// Name: public: virtual void CAI_BaseNPC::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAI_BaseNPC::Event_Killed(
        CAI_BaseNPC *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const CTakeDamageInfo *info)
{
  const CTakeDamageInfo *v5; // ebx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // eax
  vgui::ToggleButton *v8; // ecx
  bool IsCurTaskContinuousMove; // bl
  edict_t *m_pPev; // ecx
  CAI_ClassScheduleIdSpace *v11; // eax
  int v12; // eax
  int v13; // edi
  CAI_ClassScheduleIdSpace *v14; // eax
  int v15; // eax
  int v16; // eax
  NPC_STATE m_NPCState; // eax

  if ( !CAI_BaseNPC::IsCurSchedule(this, schedId: 74, fIdeal: true) )
  {
    ((void (__thiscall *)(CAI_BaseNPC *, _DWORD, int, int))this->Wake)(a1: this, a2: 0, a3, a4: a2);
    v5 = info;
    CAI_BaseNPC::SelectDeathPose(this, (int)info);
    if ( this->m_lifeState.m_Value != 1 )
    {
      this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
      this->m_lifeState.m_Value = 1;
    }
    m_Index = info->m_hAttacker.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    this->CleanupOnDeath(this, a2: m_pEntity, a3: true);
    this->StopLoopingSounds(this);
    this->DeathSound(this, a2: info);
    if ( (this->m_fFlags.m_Value & 0x4000) != 0 && !this->ShouldGib(this, a2: info) )
      this->m_pfnTouch = nullptr;
    CBaseCombatCharacter::Event_Killed(this, info);
    if ( this->m_bFadeCorpse.m_Value )
    {
      IsCurTaskContinuousMove = IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: v8);
      if ( this->m_bImportanRagdoll.m_Value != IsCurTaskContinuousMove )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE67u);
        }
        this->m_bImportanRagdoll.m_Value = IsCurTaskContinuousMove;
      }
      v5 = info;
    }
    v11 = this->GetClassScheduleIdSpace(this);
    v12 = CAI_LocalIdSpace::LocalToGlobal(this: &v11->m_ConditionIds, localID: 17);
    if ( v12 != -1 )
    {
      v13 = v12 - 1000000000;
      if ( v12 != 999999999 )
      {
        v14 = this->GetClassScheduleIdSpace(this);
        v15 = CAI_LocalIdSpace::LocalToGlobal(this: &v14->m_ConditionIds, localID: 17);
        if ( v15 == -1
          || (v16 = v15 - 1000000000) == -1
          || ((1 << (v16 & 0x1F)) & this->m_Conditions.m_Ints[v16 >> 5]) == 0 )
        {
          this->OnConditionSet(this, a2: 17);
        }
        this->m_Conditions.m_Ints[v13 >> 5] |= 1 << (v13 & 0x1F);
      }
    }
    if ( this->m_IdealNPCState != NPC_STATE_DEAD )
      this->m_IdealNPCState = NPC_STATE_DEAD;
    if ( this->CanBecomeRagdoll(this) || this->IsRagdoll(this) )
    {
      m_NPCState = this->m_NPCState;
      if ( m_NPCState != NPC_STATE_DEAD )
        this->m_flLastStateChangeTime = gpGlobals->curtime;
      this->m_NPCState = NPC_STATE_DEAD;
      if ( this->m_IdealNPCState != NPC_STATE_DEAD )
        this->m_IdealNPCState = NPC_STATE_DEAD;
      if ( m_NPCState != NPC_STATE_DEAD )
        this->OnStateChange(this, a2: m_NPCState, a3: NPC_STATE_DEAD);
    }
    if ( (v5->m_bitsDamageType & 0x400000) != 0 && (this->m_iEFlags & 0x100000) == 0 )
      CBaseEntity::RemoveDeferred(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EB60
// Name: private: void CAI_BaseNPC::RebalanceThinks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RebalanceThinks(CAI_BaseNPC *this)
{
  int m_nValue; // eax
  CGlobalVars *v3; // ecx
  bool v4; // bl
  double v5; // st7
  CGlobalVars *v6; // esi
  CBasePlayer *v7; // ecx
  CBasePlayer *LocalPlayer; // eax
  int tickcount; // eax
  int v10; // ecx
  int v11; // edi
  int m_Size; // eax
  int v13; // ecx
  CAI_BaseNPC *v14; // edi
  int v15; // eax
  int v16; // eax
  int v17; // esi
  AIRebalanceInfo_t *v18; // ebx
  float *v19; // eax
  edict_t *m_pPev; // edi
  AIRebalanceInfo_t *v21; // ebx
  AIRebalanceInfo_t *v22; // edi
  int NextThinkTick; // eax
  double v24; // st7
  AIRebalanceInfo_t *m_pMemory; // ecx
  int iNextThinkTick; // edi
  int v27; // eax
  int v28; // ebx
  int v29; // esi
  int v30; // eax
  int v31; // eax
  int v32; // esi
  int v33; // eax
  int v34; // eax
  Vector v35; // [esp+20h] [ebp-48h] BYREF
  Vector vPlayerForward; // [esp+2Ch] [ebp-3Ch] BYREF
  Vector vToCandidate; // [esp+38h] [ebp-30h] BYREF
  Vector vPlayerEyePosition; // [esp+44h] [ebp-24h] BYREF
  int iMaxThinkersPerTick; // [esp+50h] [ebp-18h]
  int iMaxTickRebalance; // [esp+54h] [ebp-14h]
  int iMinTickRebalance; // [esp+58h] [ebp-10h]
  CBasePlayer *pPlayer; // [esp+5Ch] [ebp-Ch]
  int i; // [esp+60h] [ebp-8h]
  bool bDebugThinkTicks; // [esp+67h] [ebp-1h]

  if ( ai_debug_think_ticks.m_pParent != nullptr )
    m_nValue = ai_debug_think_ticks.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v3 = gpGlobals;
  v4 = m_nValue != 0;
  bDebugThinkTicks = m_nValue != 0;
  if ( m_nValue != 0 )
  {
    if ( gpGlobals->tickcount != iPrevTick )
    {
      DevMsg(
        a1: "NPC per tick is %d [%d] (tick %d, frame %d)\n",
        nRebalanceableThinksInTick,
        nThinksInTick,
        iPrevTick,
        gpGlobals->framecount);
      v3 = gpGlobals;
      iPrevTick = gpGlobals->tickcount;
      nThinksInTick = 0;
      nRebalanceableThinksInTick = 0;
    }
    ++nThinksInTick;
    if ( (void (__thiscall *)(CAI_BaseNPC *))this->m_pfnThink == CAI_BaseNPC::CallNPCThink
      && !this->m_bInChoreo
      && this->m_NPCState != NPC_STATE_DEAD
      && this->m_SleepState == AISS_AWAKE
      && this->m_bUsingStandardThinkTime )
    {
      ++nRebalanceableThinksInTick;
    }
  }
  if ( ai_use_think_optimizations.m_pParent != nullptr
    && ai_use_think_optimizations.m_pParent->m_Value.m_nValue != 0
    && ai_rebalance_thinks.m_pParent != nullptr
    && ai_rebalance_thinks.m_pParent->m_Value.m_nValue != 0
    && v3->tickcount >= CAI_BaseNPC::gm_iNextThinkRebalanceTick )
  {
    if ( (_S3_1 & 1) == 0 )
    {
      _S3_1 |= 1u;
      rebalanceCandidates.m_Memory.m_pMemory = nullptr;
      rebalanceCandidates.m_Memory.m_nAllocationCount = 64;
      rebalanceCandidates.m_Memory.m_nGrowSize = 16;
      rebalanceCandidates.m_Memory.m_pMemory = (AIRebalanceInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1280);
      rebalanceCandidates.m_Size = 0;
      rebalanceCandidates.m_pElements = rebalanceCandidates.m_Memory.m_pMemory;
      atexit(func: CAI_BaseNPC::RebalanceThinks_::_13_::_dynamic_atexit_destructor_for__rebalanceCandidates__);
    }
    v5 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: 1077936128,
           a3: 1084227584);
    v6 = gpGlobals;
    CAI_BaseNPC::gm_iNextThinkRebalanceTick = gpGlobals->tickcount + (int)(v5 / gpGlobals->interval_per_tick + 0.5);
    if ( gpGlobals->maxClients <= 1 )
    {
      LocalPlayer = UTIL_GetLocalPlayer();
      v6 = gpGlobals;
      pPlayer = LocalPlayer;
      v7 = LocalPlayer;
    }
    else
    {
      v7 = nullptr;
      pPlayer = nullptr;
    }
    memset((void *)&vPlayerForward, 0, sizeof(vPlayerForward));
    memset((void *)&vPlayerEyePosition, 0, sizeof(vPlayerEyePosition));
    if ( v7 != nullptr )
    {
      CBasePlayer::EyePositionAndVectors(
        this: v7,
        pPosition: &vPlayerEyePosition,
        pForward: &vPlayerForward,
        pRight: nullptr,
        pUp: nullptr);
      v6 = gpGlobals;
    }
    tickcount = v6->tickcount;
    v10 = tickcount - 1;
    v11 = (int)(float)((float)(0.1 / v6->interval_per_tick) + 0.5);
    iMaxTickRebalance = v11 + tickcount;
    m_Size = g_AI_Manager.m_AIs.m_Size;
    iMinTickRebalance = v10;
    v13 = 0;
    iMaxThinkersPerTick = v11;
    i = 0;
    if ( g_AI_Manager.m_AIs.m_Size > 0 )
    {
      while ( 1 )
      {
        v14 = (m_Size != 0 ? g_AI_Manager.m_AIs.m_Memory.m_pMemory : nullptr)[v13];
        if ( (void (__thiscall *)(CAI_BaseNPC *))v14->m_pfnThink != CAI_BaseNPC::CallNPCThink
          || v14->m_bInChoreo
          || v14->m_NPCState == NPC_STATE_DEAD
          || v14->m_SleepState != AISS_AWAKE
          || !v14->m_bUsingStandardThinkTime
          || (v15 = CBaseEntity::GetNextThinkTick(this: v14, szContext: nullptr)) < iMinTickRebalance
          || (v16 = CBaseEntity::GetNextThinkTick(this: v14, szContext: nullptr)) >= iMaxTickRebalance )
        {
          if ( v4 )
          {
            NextThinkTick = CBaseEntity::GetNextThinkTick(this: v14, szContext: nullptr);
            DevMsg(a1: "   Ignoring %d\n", NextThinkTick);
          }
        }
        else
        {
          v17 = CUtlVector<AIRebalanceInfo_t,CUtlMemory<AIRebalanceInfo_t,int>>::AddToTail(this: &rebalanceCandidates);
          rebalanceCandidates.m_Memory.m_pMemory[v17].pNPC = v14;
          v18 = &rebalanceCandidates.m_Memory.m_pMemory[v17];
          v18->iNextThinkTick = CBaseEntity::GetNextThinkTick(this: v14, szContext: nullptr);
          if ( (v14->m_spawnflags.m_Value & 0x10) != 0 )
          {
            rebalanceCandidates.m_Memory.m_pMemory[v17].bInPVS = false;
          }
          else if ( pPlayer != nullptr )
          {
            v19 = (float *)v14->EyePosition(this: v14, result: &v35);
            m_pPev = v14->m_Network.m_pPev;
            vToCandidate.x = *v19 - vPlayerEyePosition.x;
            vToCandidate.y = v19[1] - vPlayerEyePosition.y;
            vToCandidate.z = v19[2] - vPlayerEyePosition.z;
            v21 = &rebalanceCandidates.m_Memory.m_pMemory[v17];
            v21->bInPVS = UTIL_FindClientInPVS(pEdict: m_pPev) != nullptr;
            v22 = &rebalanceCandidates.m_Memory.m_pMemory[v17];
            v22->distPlayer = VectorNormalize(vec: &vToCandidate);
            rebalanceCandidates.m_Memory.m_pMemory[v17].dotPlayer = (float)((float)(vToCandidate.y * vPlayerForward.y)
                                                                          + (float)(vToCandidate.x * vPlayerForward.x))
                                                                  + (float)(vToCandidate.z * vPlayerForward.z);
          }
          else
          {
            rebalanceCandidates.m_Memory.m_pMemory[v17].bInPVS = true;
            rebalanceCandidates.m_Memory.m_pMemory[v17].dotPlayer = 1.0;
            rebalanceCandidates.m_Memory.m_pMemory[v17].distPlayer = 0.0;
          }
        }
        m_Size = g_AI_Manager.m_AIs.m_Size;
        v13 = i + 1;
        i = v13;
        if ( v13 >= g_AI_Manager.m_AIs.m_Size )
          break;
        v4 = bDebugThinkTicks;
      }
      v11 = iMaxThinkersPerTick;
    }
    if ( rebalanceCandidates.m_Size != 0 )
    {
      CUtlVector<AIRebalanceInfo_t,CUtlMemory<AIRebalanceInfo_t,int>>::Sort(
        this: &rebalanceCandidates,
        pfnCompare: ThinkRebalanceCompare);
      v24 = ceil(X: (float)((float)(rebalanceCandidates.m_Size + 1) / (float)v11));
      m_pMemory = rebalanceCandidates.m_Memory.m_pMemory;
      iNextThinkTick = rebalanceCandidates.m_Memory.m_pMemory->iNextThinkTick;
      v27 = gpGlobals->tickcount;
      iMaxThinkersPerTick = (int)v24;
      if ( v27 < iNextThinkTick )
        iNextThinkTick = v27;
      v28 = (int)v24 - 1;
      if ( bDebugThinkTicks )
      {
        DevMsg(a1: "Rebalance %d!\n", rebalanceCandidates.m_Size + 1);
        DevMsg(a1: "   Distributing %d\n", iNextThinkTick);
        m_pMemory = rebalanceCandidates.m_Memory.m_pMemory;
      }
      i = 0;
      if ( rebalanceCandidates.m_Size > 0 )
      {
        v29 = 0;
        while ( 1 )
        {
          if ( v28 == 0 || m_pMemory[v29].iNextThinkTick > iNextThinkTick )
          {
            if ( m_pMemory[v29].iNextThinkTick > iNextThinkTick )
              iNextThinkTick = m_pMemory[v29].iNextThinkTick;
            else
              ++iNextThinkTick;
            if ( bDebugThinkTicks )
            {
              DevMsg(a1: "   Distributing %d\n", iNextThinkTick);
              m_pMemory = rebalanceCandidates.m_Memory.m_pMemory;
            }
            v28 = iMaxThinkersPerTick;
          }
          if ( CBaseEntity::GetNextThinkTick(this: m_pMemory[v29].pNPC, szContext: nullptr) == iNextThinkTick )
          {
            if ( bDebugThinkTicks )
            {
              v31 = CBaseEntity::GetNextThinkTick(
                      this: rebalanceCandidates.m_Memory.m_pMemory[v29].pNPC,
                      szContext: nullptr);
              DevMsg(a1: "      Leaving %d\n", v31);
            }
          }
          else
          {
            if ( bDebugThinkTicks )
            {
              v30 = CBaseEntity::GetNextThinkTick(
                      this: rebalanceCandidates.m_Memory.m_pMemory[v29].pNPC,
                      szContext: nullptr);
              DevMsg(a1: "      Bumping %d to %d\n", v30, iNextThinkTick);
            }
            CBaseEntity::SetNextThink(
              this: rebalanceCandidates.m_Memory.m_pMemory[v29].pNPC,
              thinkTime: (float)iNextThinkTick * gpGlobals->interval_per_tick,
              szContext: nullptr);
          }
          --v28;
          ++v29;
          if ( ++i >= rebalanceCandidates.m_Size )
            break;
          m_pMemory = rebalanceCandidates.m_Memory.m_pMemory;
        }
      }
    }
    v32 = 0;
    rebalanceCandidates.m_Size = 0;
    if ( bDebugThinkTicks )
    {
      DevMsg(a1: "New distribution is:\n");
      v33 = g_AI_Manager.m_AIs.m_Size;
      if ( g_AI_Manager.m_AIs.m_Size > 0 )
      {
        do
        {
          v34 = CBaseEntity::GetNextThinkTick(
                  this: (v33 != 0 ? g_AI_Manager.m_AIs.m_Memory.m_pMemory : nullptr)[v32],
                  szContext: nullptr);
          DevMsg(a1: "   %d\n", v34);
          v33 = g_AI_Manager.m_AIs.m_Size;
          ++v32;
        }
        while ( v32 < g_AI_Manager.m_AIs.m_Size );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F140
// Name: public: void CAI_BaseNPC::CallNPCThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::CallNPCThink(CAI_BaseNPC *this)
{
  IMDLCache *v2; // edi
  bool v3; // zf

  CAI_BaseNPC::RebalanceThinks(this);
  this->m_bUsingStandardThinkTime = false;
  if ( CAI_BaseNPC::PreNPCThink(this) != 0 )
  {
    v2 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    this->NPCThink(this);
    v3 = g_StartTimeCurThink == 0.0;
    this->m_flLastRealThinkTime = gpGlobals->curtime;
    if ( !v3 )
      g_NpcTimeThisFrame = _Plat_FloatTime() - g_StartTimeCurThink + g_NpcTimeThisFrame;
    v2->EndLock(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F1C0
// Name: public: virtual void CAI_BaseNPC::NPCThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BaseNPC::NPCThink(CAI_BaseNPC *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool v4; // cc
  float A; // xmm0_4
  void (__thiscall *RunAI)(CAI_BaseNPC *); // eax
  bool v7; // bl
  edict_t *m_pPev; // ecx
  long double v9; // st7
  int v10; // eax
  int v11; // edi
  Vector *v12; // eax
  float y; // xmm2_4
  float v14; // xmm0_4
  void (__thiscall *GetVectors)(CBaseEntity *, Vector *, Vector *, Vector *); // edx
  int NextThinkTick; // eax
  void (__thiscall *UpdateEfficiency)(CAI_BaseNPC *, bool); // edx
  double v18; // xmm0_8
  Vector target; // [esp+38h] [ebp-34h] BYREF
  Vector right; // [esp+44h] [ebp-28h] BYREF
  Vector vecPoint; // [esp+50h] [ebp-1Ch] BYREF
  float thinkTime; // [esp+5Ch] [ebp-10h]
  BOOL bInPVS; // [esp+60h] [ebp-Ch]
  float thinkLimit; // [esp+64h] [ebp-8h]
  bool bRanDecision; // [esp+6Bh] [ebp-1h]

  if ( this->m_bCheckContacts )
    CAI_BaseNPC::CheckPhysicsContacts(this, a2, a3, a4: (int)this);
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  LOBYTE(bInPVS) = this->CheckPVSCondition(this);
  this->UpdateSleepState(this, a2: bInPVS);
  v4 = this->m_Efficiency < AIE_DORMANT;
  bRanDecision = false;
  if ( v4 && this->m_SleepState == AISS_AWAKE )
  {
    if ( (_S4_0 & 1) == 0 )
    {
      _S4_0 |= 1u;
      timer.m_Duration.m_Int64 = 0;
    }
    thinkLimit = ai_show_think_tolerance.m_pParent->m_Value.m_fValue;
    A = thinkLimit;
    if ( thinkLimit > 0.0 )
    {
      thinkTime = COERCE_FLOAT(&timer);
      timer.m_Duration.m_Int64 = __rdtsc();
    }
    if ( g_pAINetworkManager != nullptr && g_pAINetworkManager->m_fInitalized )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "NPCs",
        a3: 0,
        a4: "NPCs",
        a5: false,
        a6: 4);
      this->SetPlayerAvoidState(this);
      if ( CAI_BaseNPC::PreThink(this) != 0 )
      {
        if ( gpGlobals->curtime < this->m_flNextDecisionTime )
        {
          if ( this->m_ScheduleState.bTaskRanAutomovement )
            CAI_BaseNPC::AutoMovement(this, pTarget: nullptr, pTraceResult: nullptr);
          if ( this->m_ScheduleState.bTaskUpdatedYaw )
            this->m_pMotor->UpdateYaw(this: this->m_pMotor, a2: -1);
        }
        else
        {
          RunAI = this->RunAI;
          bRanDecision = true;
          *(_WORD *)&this->m_ScheduleState.bTaskRanAutomovement = 0;
          RunAI(this);
        }
        CAI_BaseNPC::PostRun(this);
        CAI_BaseNPC::PerformMovement(this);
        v7 = this->IsMoving(this);
        if ( this->m_bIsMoving.m_Value != v7 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE65u);
          }
          this->m_bIsMoving.m_Value = v7;
        }
        CAI_BaseNPC::PostMovement(this);
        CBaseEntity::SetSimulationTime(this, st: gpGlobals->curtime);
      }
      else
      {
        this->m_flTimeLastMovement = 3.4028235e38;
      }
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      A = thinkLimit;
    }
    if ( A > 0.0 )
    {
      LODWORD(vecPoint.z) = HIDWORD(g_AIRunTimer.m_Duration.m_Int64) & 0x80000000;
      vecPoint.y = 0.0;
      timer.m_Duration.m_Int64 = __rdtsc() - timer.m_Duration.m_Int64;
      v9 = (double)g_AIRunTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
      thinkTime = v9;
      if ( v9 > thinkLimit )
      {
        v10 = (int)RemapVal(val: thinkTime, A, B: A * 3.0, C: 96.0, D: 255.0);
        v11 = v10;
        if ( v10 <= 255 )
        {
          if ( v10 < 96 )
            v11 = 96;
        }
        else
        {
          v11 = 255;
        }
        v12 = this->EyePosition(this, result: &target);
        y = v12->y;
        v14 = v12->z + 12.0;
        GetVectors = this->GetVectors;
        vecPoint.x = v12->x;
        vecPoint.y = y;
        vecPoint.z = v14;
        GetVectors(this, a2: nullptr, a3: &right, a4: nullptr);
        target.x = vecPoint.x;
        target.y = vecPoint.y;
        target.z = vecPoint.z + 64.0;
        NDebugOverlay::Line(origin: &vecPoint, &target, r: v11, g: 0, b: 0, noDepthTest: false, duration: 1.0);
        target.z = (float)(vecPoint.z + 16.0) + (float)(right.z * 16.0);
        target.x = vecPoint.x + (float)(right.x * 16.0);
        target.y = vecPoint.y + (float)(right.y * 16.0);
        NDebugOverlay::Line(origin: &vecPoint, &target, r: v11, g: 0, b: 0, noDepthTest: false, duration: 1.0);
        target.z = (float)(vecPoint.z + 16.0) - (float)(right.z * 16.0);
        target.x = vecPoint.x - (float)(right.x * 16.0);
        target.y = vecPoint.y - (float)(right.y * 16.0);
        NDebugOverlay::Line(origin: &vecPoint, &target, r: v11, g: 0, b: 0, noDepthTest: false, duration: 1.0);
      }
    }
  }
  NextThinkTick = CBaseEntity::GetNextThinkTick(this, szContext: nullptr);
  UpdateEfficiency = this->UpdateEfficiency;
  this->m_bUsingStandardThinkTime = NextThinkTick == -1;
  UpdateEfficiency(this, a2: bInPVS);
  if ( this->m_bUsingStandardThinkTime )
  {
    if ( ai_debug_efficiency.m_pParent != nullptr && ai_debug_efficiency.m_pParent->m_Value.m_nValue != 0 )
      DevMsg(
        pAI: this,
        pszFormat: "Eff: %s, Move: %s\n",
        ppszEfficiencies[this->m_Efficiency],
        ppszMoveEfficiencies[this->m_MoveEfficiency]);
    if ( bRanDecision )
      this->m_flNextDecisionTime = g_DecisionIntervals[this->m_Efficiency] + gpGlobals->curtime;
    if ( this->m_MoveEfficiency != AIME_NORMAL && this->m_Efficiency != AIE_NORMAL )
      v18 = gpGlobals->curtime + 0.2;
    else
      v18 = gpGlobals->curtime + 0.1;
    CBaseEntity::SetNextThink(this, thinkTime: v18, szContext: nullptr);
  }
  else
  {
    this->m_flNextDecisionTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F720
// Name: public: virtual void CAI_BaseNPC::Wake(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::Wake(CAI_BaseNPC *this, char bFireOutput)
{
  int m_Value; // eax
  unsigned int v4; // esi
  edict_t *m_pPev; // ecx
  CAI_Squad *m_pSquad; // ecx
  CAI_BaseNPC *i; // esi
  void (__thiscall *Wake)(CAI_BaseNPC *, bool); // eax

  if ( this->m_SleepState != AISS_AWAKE )
  {
    this->m_nWakeTick = gpGlobals->tickcount;
    this->m_SleepState = AISS_AWAKE;
    m_Value = this->m_fEffects.m_Value;
    v4 = m_Value & 0xFFFFFFDF;
    if ( m_Value != (m_Value & 0xFFFFFFDF) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      }
      this->m_fEffects.m_Value = v4;
    }
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
    if ( bFireOutput != 0 )
      COutputEvent::FireOutput(this: &this->m_OnWake, pActivator: this, pCaller: this, fDelay: 0.0);
    if ( this->m_bWakeSquad )
    {
      m_pSquad = this->m_pSquad;
      if ( m_pSquad != nullptr )
      {
        for ( i = CAI_Squad::GetFirstMember(
                    this: m_pSquad,
                    pIter: (AISquadIter_t__ **)&bFireOutput,
                    bIgnoreSilentMembers: true);
              i != nullptr;
              i = CAI_Squad::GetNextMember(
                    this: this->m_pSquad,
                    pIter: (AISquadIter_t__ **)&bFireOutput,
                    bIgnoreSilentMembers: true) )
        {
          if ( i->IsAlive(this: i) && i != this )
          {
            Wake = i->Wake;
            i->m_bWakeSquad = false;
            Wake(this: i, a2: true);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F830
// Name: public: virtual void CAI_BaseNPC::GatherConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::GatherConditions(CAI_BaseNPC *this)
{
  float m_Value; // xmm0_4
  edict_t *m_pPev; // ecx
  NPC_STATE m_NPCState; // eax
  bool v5; // zf
  bool m_bForceConditionsGather; // bl
  CAI_Enemies *v7; // eax
  NPC_STATE v8; // eax
  CAI_BaseNPC_vtbl *v9; // edi
  CBaseEntity *v10; // eax
  unsigned int m_Index; // ecx
  CBaseEntity *Target; // eax
  CAI_ClassScheduleIdSpace *v13; // eax
  int v14; // eax
  int v15; // edi
  CAI_ClassScheduleIdSpace *v16; // eax
  int v17; // eax
  int v18; // eax

  this->m_bConditionsGathered = true;
  g_AIConditionsTimer.m_Duration.m_Int64 = __rdtsc();
  m_Value = this->m_flTimePingEffect.m_Value;
  if ( gpGlobals->curtime > m_Value && m_Value > 0.0 )
  {
    CBaseEntity::DispatchUpdateTransmitState(this);
    if ( this->m_flTimePingEffect.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE74u);
      }
      this->m_flTimePingEffect.m_Value = 0.0;
    }
  }
  m_NPCState = this->m_NPCState;
  if ( m_NPCState == NPC_STATE_NONE || m_NPCState == NPC_STATE_DEAD )
  {
    v13 = this->GetClassScheduleIdSpace(this);
    v14 = CAI_LocalIdSpace::LocalToGlobal(this: &v13->m_ConditionIds, localID: 1);
    if ( v14 != -1 )
    {
      v15 = v14 - 1000000000;
      if ( v14 != 999999999 )
      {
        v16 = this->GetClassScheduleIdSpace(this);
        v17 = CAI_LocalIdSpace::LocalToGlobal(this: &v16->m_ConditionIds, localID: 1);
        if ( v17 != -1 )
        {
          v18 = v17 - 1000000000;
          if ( v18 != -1 && ((1 << (v18 & 0x1F)) & this->m_Conditions.m_Ints[v18 >> 5]) != 0 )
            this->OnConditionCleared(this, a2: 1);
        }
        this->m_Conditions.m_Ints[v15 >> 5] &= ~(1 << (v15 & 0x1F));
      }
    }
  }
  else
  {
    if ( fabs(CAI_Motor::DeltaIdealYaw(this: this->m_pMotor)) <= 0.0060000001 )
      this->m_afMemory &= ~0x2000u;
    v5 = this->m_pfnThink == (void (__thiscall *)(CBaseEntity *))CAI_BaseNPC::CallNPCThink;
    m_bForceConditionsGather = this->m_bForceConditionsGather;
    this->m_bForceConditionsGather = false;
    if ( !v5 )
    {
      if ( UTIL_FindClientInPVS(pEdict: this->m_Network.m_pPev) != nullptr )
        CAI_BaseNPC::SetCondition(this, iCondition: 1);
      else
        CAI_BaseNPC::ClearCondition(this, iCondition: 1);
    }
    if ( (this->m_spawnflags.m_Value & 0x10) == 0
      && (m_bForceConditionsGather
       || CAI_BaseNPC::HasCondition(this, iCondition: 1)
       || this->ShouldAlwaysThink(this)
       || this->m_NPCState == NPC_STATE_COMBAT) )
    {
      CAI_BaseNPC::CheckOnGround(this);
      if ( this->ShouldPlayIdleSound(this) )
        this->IdleSound(this);
      this->m_pSenses->PerformSensing(this: this->m_pSenses);
      v7 = this->GetEnemies(this);
      CAI_Enemies::RefreshMemories(this: v7);
      CAI_BaseNPC::ChooseEnemy(this);
      if ( CAI_BaseNPC::Weapon_IsBetterAvailable(this) != 0 )
        CAI_BaseNPC::SetCondition(this, iCondition: 46);
      if ( this->m_pSchedule != nullptr )
      {
        v8 = this->m_NPCState;
        if ( (v8 == NPC_STATE_IDLE || v8 == NPC_STATE_ALERT)
          && this->GetEnemy_2(this) != nullptr
          && !CAI_BaseNPC::HasCondition(this, iCondition: 26)
          && (this->m_pSchedule->m_InterruptMask.m_Ints[0] & 0x4000000) != 0 )
        {
          _DevMsg(a1: 2, a2: "Had to force COND_NEW_ENEMY\n");
          CAI_BaseNPC::SetCondition(this, iCondition: 26);
        }
      }
    }
    else
    {
      this->ClearSenseConditions(this);
    }
    if ( this->GetEnemy_2(this) != nullptr )
    {
      if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
      {
        _DevMsg(a1: 2, a2: "Lost enemy because we're flagged efficient\n");
        CAI_BaseNPC::SetEnemy(this, pEnemy: nullptr, bSetCondNewEnemy: true);
      }
      else
      {
        v9 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v10 = this->GetEnemy_2(this);
        v9->GatherEnemyConditions(this, a2: v10);
        this->m_flLastEnemyTime = gpGlobals->curtime;
      }
    }
    m_Index = this->m_hTargetEnt.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      Target = CAI_BaseNPC::GetTarget(this);
      CAI_BaseNPC::CheckTarget(this, pTarget: Target);
    }
    this->CheckAmmo(this);
    this->CheckFlinches(this);
    CAI_BaseNPC::CheckSquad(this);
  }
  g_AIConditionsTimer.m_Duration.m_Int64 = __rdtsc() - g_AIConditionsTimer.m_Duration.m_Int64;
}

//------------------------------------------------------------------------------
// Address: 0x1002FBD0
// Name: public: enum Activity CAI_BaseNPC::TranslateActivity(enum Activity,enum Activity __near *)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_BaseNPC::TranslateActivity(
        CAI_BaseNPC *this,
        Activity idealActivity,
        Activity *pIdealWeaponActivity)
{
  Activity v3; // esi
  Activity (__thiscall *Weapon_TranslateActivity)(CBaseCombatCharacter *, Activity, bool *); // edx
  Activity v6; // eax
  Activity v7; // eax
  Activity v8; // eax
  int v9; // ebx
  int v11; // eax
  const char *pszValue; // eax
  const char *v13; // esi
  const char *ActivityName; // eax
  int m_Size; // eax
  int v16; // esi
  Activity *m_pMemory; // ecx
  int v18; // eax
  int *v19; // esi
  Activity v20; // esi
  const char *v21; // [esp-4h] [ebp-1Ch]
  Activity idealWeaponActivity; // [esp+Ch] [ebp-Ch]
  int count; // [esp+10h] [ebp-8h]
  bool bIdealWeaponRequired; // [esp+16h] [ebp-2h] BYREF
  bool bWeaponRequired; // [esp+17h] [ebp-1h] BYREF
  Activity baseTranslation; // [esp+24h] [ebp+Ch]

  v3 = idealActivity;
  Weapon_TranslateActivity = this->Weapon_TranslateActivity;
  count = 0;
  bIdealWeaponRequired = false;
  bWeaponRequired = false;
  v6 = Weapon_TranslateActivity(this, a2: idealActivity, a3: &bIdealWeaponRequired);
  idealWeaponActivity = v6;
  if ( pIdealWeaponActivity != nullptr )
    *pIdealWeaponActivity = v6;
  baseTranslation = idealActivity;
  do
  {
    ++count;
    v7 = this->NPC_TranslateActivity(this, a2: v3);
    if ( v7 != v3 )
      baseTranslation = v7;
    v8 = this->Weapon_TranslateActivity(this, a2: v7, a3: &bWeaponRequired);
    v9 = v8;
    if ( v8 == v3 )
      break;
    v3 = v8;
  }
  while ( count < 5 );
  if ( v3 == ACT_SCRIPT_CUSTOM_MOVE )
    return ACT_SCRIPT_CUSTOM_MOVE;
  if ( CAI_BaseNPC::HaveSequenceForActivity(this, activity: v8) )
    return v9;
  if ( bWeaponRequired )
  {
    if ( (_S5 & 1) == 0 )
    {
      _S5 |= 1u;
      sUniqueActivities.m_Memory.m_pMemory = nullptr;
      sUniqueActivities.m_Memory.m_nAllocationCount = 0;
      sUniqueActivities.m_Memory.m_nGrowSize = 0;
      sUniqueActivities.m_Size = 0;
      sUniqueActivities.m_pElements = nullptr;
      atexit(func: CAI_BaseNPC::TranslateActivity_::_17_::_dynamic_atexit_destructor_for__sUniqueActivities__);
    }
    v11 = 0;
    if ( sUniqueActivities.m_Size > 0 )
    {
      while ( sUniqueActivities.m_Memory.m_pMemory[v11] != v9 )
      {
        if ( ++v11 >= sUniqueActivities.m_Size )
          goto LABEL_30;
      }
      if ( v11 == 0 )
      {
        pszValue = CBaseCombatCharacter::GetActiveWeapon(this)->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        v13 = this->m_iClassname.pszValue;
        if ( v13 == nullptr )
          v13 = locale;
        v21 = pszValue;
        ActivityName = CAI_BaseNPC::GetActivityName(actID: v9);
        DevWarning(a1: "%s missing activity \"%s\" needed by weapon\"%s\"\n", v13, ActivityName, v21);
        m_Size = sUniqueActivities.m_Size;
        v16 = sUniqueActivities.m_Size;
        if ( sUniqueActivities.m_Size + 1 > sUniqueActivities.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&sUniqueActivities,
            num: sUniqueActivities.m_Size - sUniqueActivities.m_Memory.m_nAllocationCount + 1);
          m_Size = sUniqueActivities.m_Size;
        }
        m_pMemory = sUniqueActivities.m_Memory.m_pMemory;
        sUniqueActivities.m_Size = m_Size + 1;
        v18 = m_Size - v16;
        sUniqueActivities.m_pElements = sUniqueActivities.m_Memory.m_pMemory;
        if ( v18 > 0 )
        {
          _V_memmove(
            dest: &sUniqueActivities.m_Memory.m_pMemory[v16 + 1],
            src: &sUniqueActivities.m_Memory.m_pMemory[v16],
            count: 4 * v18);
          m_pMemory = sUniqueActivities.m_Memory.m_pMemory;
        }
        v19 = (int *)&m_pMemory[v16];
        if ( v19 != nullptr )
          *v19 = v9;
      }
    }
  }
LABEL_30:
  v20 = baseTranslation;
  if ( baseTranslation == v9 || !CAI_BaseNPC::HaveSequenceForActivity(this, activity: baseTranslation) )
  {
    if ( idealWeaponActivity != baseTranslation
      && CAI_BaseNPC::HaveSequenceForActivity(this, activity: idealWeaponActivity) )
    {
      return idealActivity;
    }
    v20 = idealActivity;
    if ( idealActivity == idealWeaponActivity || !CAI_BaseNPC::HaveSequenceForActivity(this, activity: idealActivity) )
    {
      if ( idealActivity == ACT_RUN )
        return ACT_WALK;
      if ( idealActivity == ACT_WALK )
        return ACT_RUN;
    }
  }
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x1002FE00
// Name: private: void CAI_BaseNPC::ResolveActivityToSequence(enum Activity,int __near &,enum Activity __near &,enum Activity __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ResolveActivityToSequence(
        CAI_BaseNPC *this,
        Activity NewActivity,
        int *iSequence,
        Activity *translatedActivity,
        Activity *weaponActivity)
{
  Activity v7; // eax
  int ScriptCustomMoveSequence; // eax
  int v9; // eax
  const char *pszValue; // edi
  const char *DebugName; // eax
  Activity v12; // ecx
  float curtime; // xmm0_4
  Activity *v14; // [esp-8h] [ebp-10h]
  const char *v15; // [esp-8h] [ebp-10h]
  const char *iSequencea; // [esp+14h] [ebp+Ch]

  if ( NewActivity == ACT_SPECIFIC_SEQUENCE )
  {
    *weaponActivity = ACT_SPECIFIC_SEQUENCE;
    *translatedActivity = ACT_SPECIFIC_SEQUENCE;
    *iSequence = this->m_nIdealSequence;
    return;
  }
  v14 = weaponActivity;
  *iSequence = -1;
  v7 = CAI_BaseNPC::TranslateActivity(this, idealActivity: NewActivity, pIdealWeaponActivity: v14);
  *translatedActivity = v7;
  if ( NewActivity == ACT_SCRIPT_CUSTOM_MOVE )
  {
    ScriptCustomMoveSequence = CAI_BaseNPC::GetScriptCustomMoveSequence(this);
LABEL_16:
    *iSequence = ScriptCustomMoveSequence;
    goto LABEL_17;
  }
  v9 = CBaseAnimating::SelectWeightedSequence(this, activity: v7);
  *iSequence = v9;
  if ( v9 != -1 )
    return;
  if ( pLastWarn != this && lastWarnActivity != *translatedActivity || (float)(gpGlobals->curtime - timeLastWarn) > 5.0 )
  {
    iSequencea = *(const char **)((int (__thiscall *)(CAI_BaseNPC *, Activity **))this->GetModelName)(
                                   a1: this,
                                   a2: &weaponActivity);
    if ( iSequencea == nullptr )
      iSequencea = locale;
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v15 = ActivityList_NameForIndex(activityIndex: *translatedActivity);
    DebugName = CBaseEntity::GetDebugName(this);
    DevWarning(a1: "%s:%s:%s has no sequence for act:%s\n", pszValue, DebugName, iSequencea, v15);
    v12 = *translatedActivity;
    curtime = gpGlobals->curtime;
    pLastWarn = this;
    lastWarnActivity = v12;
    timeLastWarn = curtime;
  }
  if ( *translatedActivity == ACT_RUN )
  {
    *translatedActivity = ACT_WALK;
    ScriptCustomMoveSequence = CBaseAnimating::SelectWeightedSequence(this, activity: ACT_WALK);
    goto LABEL_16;
  }
LABEL_17:
  if ( *iSequence == -1 )
    *iSequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002FF40
// Name: public: virtual void CAI_BaseNPC::SetActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetActivity(CAI_BaseNPC *this, Activity NewActivity)
{
  Activity m_Activity; // eax
  const char *pszValue; // edi
  const char *v5; // eax
  CStudioHdr *m_pStudioHdr; // eax
  const char *ActivityName; // [esp-8h] [ebp-14h]
  int actID; // [esp+8h] [ebp-4h]

  m_Activity = this->m_Activity;
  actID = m_Activity;
  if ( m_Activity != NewActivity
    && (NewActivity == ACT_RESET || m_Activity != ACT_TRANSITION || this->m_IdealActivity == ACT_DO_NOT_DISTURB) )
  {
    if ( ai_sequence_debug.m_pParent != nullptr
      && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
      && (this->m_debugOverlays & 0x1000) != 0 )
    {
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      ActivityName = CAI_BaseNPC::GetActivityName(actID: NewActivity);
      v5 = CAI_BaseNPC::GetActivityName(actID);
      DevMsg(a1: "SetActivity : %s: %s -> %s\n", pszValue, v5, ActivityName);
    }
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      this->m_IdealActivity = NewActivity;
      CAI_BaseNPC::ResolveActivityToSequence(
        this,
        NewActivity,
        iSequence: &this->m_nIdealSequence,
        translatedActivity: &this->m_IdealTranslatedActivity,
        weaponActivity: &this->m_IdealWeaponActivity);
      CAI_BaseNPC::SetActivityAndSequence(
        this,
        NewActivity: this->m_IdealActivity,
        iSequence: this->m_nIdealSequence,
        translatedActivity: this->m_IdealTranslatedActivity,
        weaponActivity: this->m_IdealWeaponActivity);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030040
// Name: public: void CAI_BaseNPC::SetIdealActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetIdealActivity(CAI_BaseNPC *this, Activity NewActivity)
{
  Activity v3; // ecx
  Activity m_Activity; // ebx
  const char *pszValue; // edi
  const char *v6; // eax
  const char *ActivityName; // [esp-Ch] [ebp-10h]

  v3 = NewActivity;
  if ( NewActivity != ACT_TRANSITION )
  {
    if ( ai_sequence_debug.m_pParent != nullptr
      && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
      && (this->m_debugOverlays & 0x1000) != 0 )
    {
      m_Activity = this->m_Activity;
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      ActivityName = CAI_BaseNPC::GetActivityName(actID: NewActivity);
      v6 = CAI_BaseNPC::GetActivityName(actID: m_Activity);
      DevMsg(a1: "SetIdealActivity : %s: %s -> %s\n", pszValue, v6, ActivityName);
      v3 = NewActivity;
    }
    if ( v3 != ACT_RESET )
    {
      this->m_IdealActivity = v3;
      if ( v3 != ACT_DO_NOT_DISTURB && CBaseAnimating::GetModelPtr(this) != nullptr )
        CAI_BaseNPC::ResolveActivityToSequence(
          this,
          NewActivity: this->m_IdealActivity,
          iSequence: &this->m_nIdealSequence,
          translatedActivity: &this->m_IdealTranslatedActivity,
          weaponActivity: &this->m_IdealWeaponActivity);
    }
    else
    {
      this->SetActivity(this, a2: ACT_RESET);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030110
// Name: private: void CAI_BaseNPC::AdvanceToIdealActivity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::AdvanceToIdealActivity(CAI_BaseNPC *this)
{
  int TransitionSequence; // edi
  int m_nIdealSequence; // eax
  Activity SequenceActivity; // eax
  const char *SequenceName; // eax
  int nDiscard; // [esp+8h] [ebp-Ch] BYREF
  Activity eTranslatedActivity; // [esp+Ch] [ebp-8h] BYREF
  Activity eWeaponActivity; // [esp+10h] [ebp-4h] BYREF

  TransitionSequence = CBaseAnimating::FindTransitionSequence(
                         this,
                         iCurrentSequence: this->m_nSequence.m_Value,
                         iGoalSequence: this->m_nIdealSequence,
                         piDir: nullptr);
  if ( TransitionSequence == -1 )
  {
    this->SetActivity(this, a2: this->m_IdealActivity);
  }
  else
  {
    m_nIdealSequence = this->m_nIdealSequence;
    if ( TransitionSequence == m_nIdealSequence )
    {
      CAI_BaseNPC::SetActivityAndSequence(
        this,
        NewActivity: this->m_IdealActivity,
        iSequence: m_nIdealSequence,
        translatedActivity: this->m_IdealTranslatedActivity,
        weaponActivity: this->m_IdealWeaponActivity);
    }
    else
    {
      eWeaponActivity = ACT_TRANSITION;
      eTranslatedActivity = ACT_TRANSITION;
      SequenceActivity = CBaseAnimating::GetSequenceActivity(this, iSequence: TransitionSequence);
      if ( SequenceActivity != ACT_INVALID )
        CAI_BaseNPC::ResolveActivityToSequence(
          this,
          NewActivity: SequenceActivity,
          iSequence: &nDiscard,
          translatedActivity: &eTranslatedActivity,
          weaponActivity: &eWeaponActivity);
      if ( ai_sequence_debug.m_pParent != nullptr
        && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
        && (this->m_debugOverlays & 0x1000) != 0 )
      {
        SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: TransitionSequence);
        DevMsg(a1: "AdvanceToIdealActivity calling SetActivityAndSequence because of change %s\n", SequenceName);
      }
      CAI_BaseNPC::SetActivityAndSequence(
        this,
        NewActivity: ACT_TRANSITION,
        iSequence: TransitionSequence,
        translatedActivity: eTranslatedActivity,
        weaponActivity: eWeaponActivity);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030200
// Name: public: void CAI_BaseNPC::MaintainActivity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::MaintainActivity(CAI_BaseNPC *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  int m_Value; // ebx
  const char *pszValue; // edi
  const char *v5; // eax
  const char *v6; // [esp-14h] [ebp-1Ch]
  const char *ActivityName; // [esp-10h] [ebp-18h]
  const char *SequenceName; // [esp-Ch] [ebp-14h]
  Activity actID; // [esp+4h] [ebp-4h]

  if ( this->m_lifeState.m_Value != 2
    && (this->m_NPCState != NPC_STATE_SCRIPT || this->m_Activity == ACT_TRANSITION)
    && this->m_IdealActivity != ACT_DO_NOT_DISTURB )
  {
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      actID = this->m_Activity;
      if ( actID != this->m_IdealActivity || this->m_nSequence.m_Value != this->m_nIdealSequence )
      {
        if ( ai_sequence_debug.m_pParent != nullptr
          && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
          && (this->m_debugOverlays & 0x1000) != 0 )
        {
          m_Value = this->m_nSequence.m_Value;
          pszValue = this->m_iClassname.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: this->m_nIdealSequence);
          ActivityName = CAI_BaseNPC::GetActivityName(actID: this->m_IdealActivity);
          v6 = CBaseAnimating::GetSequenceName(this, iSequence: m_Value);
          v5 = CAI_BaseNPC::GetActivityName(actID);
          DevMsg(a1: "MaintainActivity %s : %s:%s -> %s:%s\n", pszValue, v5, v6, ActivityName, SequenceName);
        }
        if ( this->m_Activity == ACT_TRANSITION )
        {
          if ( this->m_bSequenceFinished )
            CAI_BaseNPC::AdvanceToIdealActivity(this);
        }
        else
        {
          CAI_BaseNPC::ResolveActivityToSequence(
            this,
            NewActivity: this->m_IdealActivity,
            iSequence: &this->m_nIdealSequence,
            translatedActivity: &this->m_IdealTranslatedActivity,
            weaponActivity: &this->m_IdealWeaponActivity);
          CAI_BaseNPC::AdvanceToIdealActivity(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030360
// Name: public: virtual void CAI_BaseNPC::NPCInit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BaseNPC::NPCInit(CAI_BaseNPC *this@<ecx>, int a2@<ebx>)
{
  Activity m_Activity; // ebx
  const char *pszValue; // edi
  const char *v5; // eax
  CStudioHdr *m_pStudioHdr; // eax
  CAI_Senses *m_pSenses; // ecx
  CAI_Senses *v8; // eax
  const char *v9; // edi
  const char *v10; // eax
  const char *v11; // eax
  CBaseCombatWeapon *v12; // eax
  CBaseCombatWeapon *v13; // edi
  unsigned int v14; // edx
  const char *SpawnPreIdleSequenceForScript; // eax
  int v16; // eax
  bool v17; // bl
  edict_t *m_pPev; // ecx
  edict_t *v19; // ecx
  edict_t *v20; // ecx
  int v21; // edi
  CAI_BehaviorBase *v22; // ecx
  const char *ActivityName; // [esp+20h] [ebp-10h]

  if ( g_pGameRules->FAllowNPCs(this: g_pGameRules) )
  {
    if ( this->IsWaitingToRappel(this) )
      CBaseEntity::AddFlag(this, flags: 2048);
    CBaseEntity::AddFlag(this, flags: 147456);
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    this->m_flOriginalYaw = this->m_angAbsRotation.y;
    if ( this->m_bClientSideRagdoll.m_Value )
    {
      this->NetworkStateChanged_m_bClientSideRagdoll(this, a2: &this->m_bClientSideRagdoll);
      this->m_bClientSideRagdoll.m_Value = false;
    }
    CBaseEntity::SetBlocksLOS(this, bBlocksLOS: false);
    this->m_flGravity = 1.0;
    if ( this->m_takedamage.m_Value != 2 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      this->m_takedamage.m_Value = 2;
    }
    this->m_pMotor->m_IdealYaw = this->m_angRotation.m_Value.y;
    if ( this->m_iMaxHealth.m_Value != this->m_iHealth.m_Value )
    {
      this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
      this->m_iMaxHealth.m_Value = this->m_iHealth.m_Value;
    }
    if ( this->m_lifeState.m_Value != 0 )
    {
      this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
      this->m_lifeState.m_Value = 0;
    }
    if ( this->m_IdealNPCState != NPC_STATE_IDLE )
      this->m_IdealNPCState = NPC_STATE_IDLE;
    if ( ai_sequence_debug.m_pParent != nullptr
      && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
      && (this->m_debugOverlays & 0x1000) != 0 )
    {
      m_Activity = this->m_Activity;
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      ActivityName = CAI_BaseNPC::GetActivityName(actID: 1);
      v5 = CAI_BaseNPC::GetActivityName(actID: m_Activity);
      DevMsg(a1: "SetIdealActivity : %s: %s -> %s\n", pszValue, v5, ActivityName);
    }
    this->m_IdealActivity = ACT_IDLE;
    if ( CBaseAnimating::GetModelPtr(this) != nullptr )
      CAI_BaseNPC::ResolveActivityToSequence(
        this,
        NewActivity: this->m_IdealActivity,
        iSequence: &this->m_nIdealSequence,
        translatedActivity: &this->m_IdealTranslatedActivity,
        weaponActivity: &this->m_IdealWeaponActivity);
    this->SetActivity(this, a2: ACT_IDLE);
    this->ClearCommandGoal(this);
    CAI_BaseNPC::ClearSchedule(this, szReason: "Initializing NPC");
    CAI_Navigator::ClearGoal(this: this->m_pNavigator);
    this->InitBoneControllers(this);
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      CBaseAnimating::ResetActivityIndexes(this);
      CBaseAnimating::ResetEventIndexes(this);
    }
    CAI_BaseNPC::SetHintNode(this, pHintNode: nullptr);
    this->m_afMemory = 0;
    CAI_BaseNPC::SetEnemy(this, pEnemy: nullptr, bSetCondNewEnemy: true);
    m_pSenses = this->m_pSenses;
    this->m_flDistTooFar = 1024.0;
    m_pSenses->m_LookDist = 2048.0;
    if ( (this->m_spawnflags.m_Value & 0x100) != 0 )
    {
      v8 = this->m_pSenses;
      this->m_flDistTooFar = 1000000000.0;
      v8->m_LookDist = 6000.0;
    }
    if ( this != (CAI_BaseNPC *)-2388 )
    {
      *(_QWORD *)this->m_Conditions.m_Ints = 0;
      *(_QWORD *)&this->m_Conditions.m_Ints[2] = 0;
      *(_QWORD *)&this->m_Conditions.m_Ints[4] = 0;
      *(_QWORD *)&this->m_Conditions.m_Ints[6] = 0;
    }
    CAI_BaseNPC::SetDefaultEyeOffset(this, a2: 0);
    if ( (this->CapabilitiesGet(this) & 0x200000) != 0 && this->m_spawnEquipment.pszValue != nullptr )
    {
      v9 = this->m_spawnEquipment.pszValue;
      v10 = v9;
      if ( v9 == nullptr )
        v10 = locale;
      if ( strcmp(v10, "0") != 0 )
      {
        v11 = this->m_spawnEquipment.pszValue;
        if ( v9 == nullptr )
          v11 = locale;
        v12 = CBaseCombatCharacter::Weapon_Create(this, pWeaponName: v11);
        v13 = v12;
        if ( v12 != nullptr )
        {
          ((void (__thiscall *)(CBaseCombatWeapon *, CAI_BaseNPC *, int))v12->MakeWeaponNameFromEntity)(
            a1: v12,
            a2: this,
            a3: a2);
          if ( (this->m_fEffects.m_Value & 0x10) != 0 )
            CBaseEntity::AddEffects(this: v13, nEffects: 16);
          this->Weapon_Equip(this, a2: v13);
        }
      }
    }
    this->m_pfnUse = (void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float))CParticleSystemQuery::TraceAgainstRayTraceEnv;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_BaseNPC::NPCInitThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.0099999998, szContext: nullptr);
    v14 = (unsigned int)this->m_spawnflags.m_Value >> 7;
    this->m_bForceConditionsGather = true;
    this->m_Efficiency = AIE_NORMAL;
    if ( (v14 & 1) != 0 )
    {
      SpawnPreIdleSequenceForScript = CAI_ScriptedSequence::GetSpawnPreIdleSequenceForScript(pEntity: this);
      if ( SpawnPreIdleSequenceForScript != nullptr )
      {
        v16 = CBaseAnimating::LookupSequence(this, label: SpawnPreIdleSequenceForScript);
        CBaseAnimating::SetSequence(this, nSequence: v16);
      }
    }
    this->CreateVPhysics(this);
    if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
      this->m_Efficiency = AIE_EFFICIENT;
    v17 = this->ShouldFadeOnDeath(this);
    if ( this->m_bFadeCorpse.m_Value != v17 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE66u);
      }
      this->m_bFadeCorpse.m_Value = v17;
    }
    this->m_GiveUpOnDeadEnemyTimer.m_minInterval = 0.75;
    this->m_GiveUpOnDeadEnemyTimer.m_maxInterval = 2.0;
    this->m_flTimeLastMovement = 3.4028235e38;
    this->m_flIgnoreDangerSoundsUntil = 0.0;
    if ( this->m_iDeathPose.m_Value != -1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v19 = this->m_Network.m_pPev;
        if ( v19 != nullptr )
          CBaseEdict::StateChanged(this: &v19->CBaseEdict, offset: 0xA1Cu);
      }
      this->m_iDeathPose.m_Value = -1;
    }
    if ( this->m_iDeathFrame.m_Value != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v20 = this->m_Network.m_pPev;
        if ( v20 != nullptr )
          CBaseEdict::StateChanged(this: &v20->CBaseEdict, offset: 0xA20u);
      }
      this->m_iDeathFrame.m_Value = 0;
    }
    v21 = 0;
    for ( this->m_EnemiesSerialNumber = -1; v21 < this->m_Behaviors.m_Size; ++v21 )
    {
      v22 = this->m_Behaviors.m_Memory.m_pMemory[v21];
      v22->Spawn(this: v22);
    }
  }
  else
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100308C0
// Name: public: virtual void CAI_BaseNPC::StartNPC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::StartNPC(CAI_BaseNPC *this)
{
  unsigned __int8 m_Value; // al
  float z; // ecx
  unsigned int m_nAITraceMask; // eax
  float v5; // xmm0_4
  CAI_MoveProbe *m_pMoveProbe; // ecx
  const char *pszValue; // ebx
  const Vector *AbsOrigin; // edi
  const Vector *v9; // eax
  const char *v10; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int m_Index; // ecx
  int v13; // eax
  CEntInfo *v14; // edx
  unsigned int v15; // ecx
  const char *v16; // ecx
  const char *v17; // eax
  int v18; // eax
  bool v19; // zf
  CBaseEntity **v20; // eax
  CBaseEntity *v21; // eax
  int v22; // ecx
  unsigned int v23; // eax
  NPC_STATE m_NPCState; // edi
  bool v25; // al
  int v26; // edx
  double flEndZ; // [esp+10h] [ebp-2Ch]
  Vector vecStart; // [esp+24h] [ebp-18h] BYREF
  Vector origin; // [esp+30h] [ebp-Ch] BYREF

  m_Value = this->m_MoveType.m_Value;
  if ( m_Value == 4
    || m_Value == 5
    || (this->CapabilitiesGet(this) & 4) != 0
    || (this->m_spawnflags.m_Value & 4) != 0
    || this->IsWaitingToRappel(this)
    || CBaseEntity::GetMoveParent(this) != nullptr )
  {
    CBaseEntity::SetGroundEntity(this, ground: nullptr);
  }
  else
  {
    z = this->m_vecOrigin.m_Value.z;
    m_nAITraceMask = this->m_nAITraceMask;
    *(_QWORD *)&origin.x = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
    *(_QWORD *)&vecStart.x = *(_QWORD *)&origin.x;
    origin.z = z;
    v5 = z + 0.1;
    m_pMoveProbe = this->m_pMoveProbe;
    vecStart.z = v5;
    if ( !CAI_MoveProbe::FloorPoint(
            this: m_pMoveProbe,
            &vecStart,
            collisionMask: m_nAITraceMask,
            flStartZ: 0.0,
            flEndZ: -2048.0,
            pVecResult: &origin) )
    {
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      AbsOrigin = CBaseEntity::GetAbsOrigin(this);
      flEndZ = CBaseEntity::GetAbsOrigin(this)->z;
      v9 = CBaseEntity::GetAbsOrigin(this);
      _Warning(
        a1: "NPC %s stuck in wall--level design error at (%.2f %.2f %.2f)\n",
        pszValue,
        AbsOrigin->x,
        v9->y,
        flEndZ);
      if ( g_pDeveloper->m_pParent != nullptr && g_pDeveloper->m_pParent->m_Value.m_nValue > 1 )
        this->m_debugOverlays |= 4u;
    }
    CBaseEntity::SetLocalOrigin(this, &origin);
  }
  v10 = this->m_target.pszValue;
  if ( v10 != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: v10,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
      this->m_hGoalEnt.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
    else
      this->m_hGoalEnt.m_Index = -1;
    m_Index = this->m_hGoalEnt.m_Index;
    if ( m_Index != -1
      && (v13 = (unsigned __int16)m_Index,
          v14 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v15 = HIWORD(m_Index),
          v14->m_SerialNumber == v15)
      && v14->m_pEntity != nullptr )
    {
      v18 = v13;
      v19 = g_pEntityList->m_EntPtrArray[v18].m_SerialNumber == v15;
      v20 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v18];
      if ( v19 )
        v21 = *v20;
      else
        v21 = nullptr;
      this->StartTargetHandling(this, a2: v21);
    }
    else
    {
      v16 = this->m_target.pszValue;
      if ( v16 == nullptr )
        v16 = locale;
      v17 = this->m_iClassname.pszValue;
      if ( v17 == nullptr )
        v17 = locale;
      _Warning(a1: "ReadyNPC()--%s couldn't find target %s\n", v17, v16);
    }
  }
  this->InitSquad(this);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CAI_BaseNPC::CallNPCThink,
    thinkTime: 0.0,
    szContext: nullptr);
  if ( CAI_BaseNPC::gm_flTimeLastSpawn == gpGlobals->curtime )
  {
    v22 = CAI_BaseNPC::gm_nSpawnedThisFrame;
  }
  else
  {
    v22 = 0;
    CAI_BaseNPC::gm_nSpawnedThisFrame = 0;
    CAI_BaseNPC::gm_flTimeLastSpawn = gpGlobals->curtime;
  }
  CBaseEntity::SetNextThink(this, thinkTime: nextThinkTimes[v22 % 20] + gpGlobals->curtime, szContext: nullptr);
  ++CAI_BaseNPC::gm_nSpawnedThisFrame;
  v23 = (unsigned int)this->m_spawnflags.m_Value >> 7;
  this->m_ScriptArrivalActivity = ACT_INVALID;
  this->m_strScriptArrivalSequence.pszValue = nullptr;
  if ( (v23 & 1) != 0 )
  {
    m_NPCState = this->m_NPCState;
    if ( m_NPCState != NPC_STATE_IDLE )
      this->m_flLastStateChangeTime = gpGlobals->curtime;
    if ( this->GetEnemy_2(this) != nullptr )
    {
      CAI_BaseNPC::SetEnemy(this, pEnemy: nullptr, bSetCondNewEnemy: true);
      _DevMsg(a1: 2, a2: "Stripped\n");
    }
    v25 = this->m_NPCState != NPC_STATE_IDLE;
    this->m_NPCState = NPC_STATE_IDLE;
    if ( this->m_IdealNPCState != NPC_STATE_IDLE )
      this->m_IdealNPCState = NPC_STATE_IDLE;
    if ( v25 )
      this->OnStateChange(this, a2: m_NPCState, a3: NPC_STATE_IDLE);
    v26 = this->m_nSequence.m_Value;
    this->m_Activity = this->m_IdealActivity;
    this->m_nIdealSequence = v26;
    CAI_BaseNPC::SetSchedule(this, localScheduleID: 56);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030C40
// Name: public: void CAI_BaseNPC::TaskMovementComplete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::TaskMovementComplete(CAI_BaseNPC *this)
{
  TaskStatus_e fTaskStatus; // eax
  Activity ArrivalActivity; // eax

  fTaskStatus = this->m_ScheduleState.fTaskStatus;
  if ( fTaskStatus >= TASKSTATUS_NEW )
  {
    if ( fTaskStatus <= TASKSTATUS_RUN_MOVE_AND_TASK )
    {
      this->m_ScheduleState.fTaskStatus = TASKSTATUS_RUN_TASK;
    }
    else if ( fTaskStatus == TASKSTATUS_RUN_MOVE )
    {
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
    }
  }
  if ( this->m_scriptState != SCRIPT_CUSTOM_MOVE_TO_MARK )
  {
    if ( !CAI_Navigator::IsGoalActive(this: this->m_pNavigator)
      || (ArrivalActivity = CAI_Navigator::GetArrivalActivity(this: this->m_pNavigator)) <= ACT_RESET )
    {
      ArrivalActivity = ACT_IDLE;
    }
    CAI_BaseNPC::SetIdealActivity(this, NewActivity: ArrivalActivity);
  }
  if ( CAI_Navigator::IsGoalActive(this: this->m_pNavigator) )
    CAI_Navigator::AdvancePath(this: this->m_pNavigator);
  CAI_Navigator::ClearGoal(this: this->m_pNavigator);
  this->OnMovementComplete(this);
}

//------------------------------------------------------------------------------
// Address: 0x10030CD0
// Name: public: void CAI_BaseNPC::RememberUnreachable(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RememberUnreachable(CAI_BaseNPC *this, CBaseEntity *pEntity, float duration)
{
  CBaseEntity *v4; // ebx
  float v5; // xmm0_4
  int v6; // edx
  UnreachableEnt_t *v7; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_UnreachableEnts; // esi
  int m_Size; // edi
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v14; // eax
  int v15; // edi
  vgui::CTreeViewListControl::CColumnInfo *v16; // eax
  CBaseEntity *v17; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v18; // ebx
  int v19; // esi
  Vector *p_vLocationWhenUnreachable; // esi
  float *p_m_Left; // edi

  v4 = pEntity;
  if ( pEntity == this->GetEnemy_2(this) )
    this->m_EnemiesSerialNumber = -1;
  v5 = duration;
  if ( duration <= 0.0 )
    v5 = 3.0;
  v6 = this->m_UnreachableEnts.m_Size - 1;
  if ( v6 < 0 )
  {
LABEL_13:
    m_nAllocationCount = this->m_UnreachableEnts.m_Memory.m_nAllocationCount;
    p_m_UnreachableEnts = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_UnreachableEnts;
    m_Size = this->m_UnreachableEnts.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
        this: p_m_UnreachableEnts,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_UnreachableEnts[1].m_pMemory;
    m_pMemory = p_m_UnreachableEnts->m_pMemory;
    v14 = (int)p_m_UnreachableEnts[1].m_pMemory - m_Size - 1;
    p_m_UnreachableEnts[1].m_nAllocationCount = (int)p_m_UnreachableEnts->m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v14);
    v15 = m_Size;
    v16 = &p_m_UnreachableEnts->m_pMemory[v15];
    if ( v16 != nullptr )
      *(_DWORD *)&v16->m_Title.m_Id = -1;
    v17 = pEntity;
    v18 = p_m_UnreachableEnts->m_pMemory;
    if ( pEntity != nullptr )
    {
      *(_DWORD *)&v18[v15].m_Title.m_Id = pEntity->GetRefEHandle(this: pEntity)->m_Index;
      v17 = pEntity;
    }
    else
    {
      *(_DWORD *)&v18[v15].m_Title.m_Id = -1;
    }
    *(float *)&p_m_UnreachableEnts->m_pMemory[v15].m_Width = gpGlobals->curtime + v5;
    if ( (v17->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v17);
      v17 = pEntity;
    }
    p_m_Left = (float *)&p_m_UnreachableEnts->m_pMemory[v15].m_Left;
    *p_m_Left = v17->m_vecAbsOrigin.x;
    p_m_Left[1] = v17->m_vecAbsOrigin.y;
    p_m_Left[2] = v17->m_vecAbsOrigin.z;
  }
  else
  {
    v7 = &this->m_UnreachableEnts.m_Memory.m_pMemory[v6];
    while ( 1 )
    {
      m_Index = v7->hUnreachableEnt.m_Index;
      if ( v7->hUnreachableEnt.m_Index == -1
        || (v4 = pEntity, g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( v4 == m_pEntity )
        break;
      --v7;
      if ( --v6 < 0 )
        goto LABEL_13;
    }
    v19 = v6;
    this->m_UnreachableEnts.m_Memory.m_pMemory[v6].fExpireTime = gpGlobals->curtime + v5;
    if ( (v4->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v4);
    p_vLocationWhenUnreachable = &this->m_UnreachableEnts.m_Memory.m_pMemory[v19].vLocationWhenUnreachable;
    p_vLocationWhenUnreachable->x = v4->m_vecAbsOrigin.x;
    p_vLocationWhenUnreachable->y = v4->m_vecAbsOrigin.y;
    p_vLocationWhenUnreachable->z = v4->m_vecAbsOrigin.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030EA0
// Name: public: virtual void CAI_BaseNPC::HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_BaseNPC::HandleAnimEvent(CAI_BaseNPC *this@<ecx>, CAI_BaseNPC *a2@<ebp>, animevent_t *pEvent)
{
  int v3; // edx
  CAI_BaseNPC *v4; // esi
  int event_lowword; // eax
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_lifeState> *p_m_lifeState; // edi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // esi
  float v8; // ecx
  edict_t *m_pPev; // edx
  CAI_ScriptedSequence *v10; // eax
  unsigned int v11; // ecx
  CAI_ScriptedSequence *v12; // eax
  float y; // xmm0_4
  const char *v14; // eax
  const Vector *AbsOrigin; // eax
  CBaseEntity *EntityGenericNearest; // eax
  CBaseEntity *v17; // edi
  float *v18; // eax
  __int128 v19; // xmm0
  CBaseCombatWeapon *v20; // eax
  bool v21; // zf
  CAI_BaseNPC_vtbl *v22; // eax
  unsigned int v23; // edi
  CAI_BaseNPC_vtbl *v24; // eax
  void (__thiscall *PickupWeapon)(CAI_BaseNPC *, CBaseCombatWeapon *); // edx
  void (__thiscall *PickupItem)(CAI_BaseNPC *, CBaseEntity *); // edx
  CBaseCombatWeapon *v27; // esi
  const char *v28; // edi
  int v29; // eax
  CBaseCombatWeapon *v30; // eax
  const char *v31; // edi
  CBaseCombatWeapon *v32; // eax
  const char *v33; // edi
  Activity v34; // eax
  const char *options; // edi
  CBaseEntity *EntityGeneric; // eax
  int v37; // eax
  CAI_BaseNPC_vtbl *v38; // edi
  int v39; // ecx
  CBaseCombatWeapon *v40; // eax
  CAI_BaseNPC_vtbl *v41; // edi
  CBaseCombatWeapon *v42; // eax
  CBasePropDoor *v43; // eax
  CBaseCombatWeapon *v44; // eax
  CBaseCombatWeapon *v45; // eax
  CBaseCombatWeapon *v46; // eax
  CBaseCombatWeapon *v47; // edi
  CBaseEdict *v48; // ecx
  CBaseEntity *m_Index; // eax
  CBaseCombatWeapon *ActiveWeapon; // edi
  CBaseCombatWeapon *v51; // eax
  CBaseCombatWeapon *v52; // eax
  Activity v53; // eax
  Activity v54; // eax
  Activity v55; // eax
  Activity v56; // eax
  CBaseCombatWeapon *v57; // eax
  const char *v58; // ecx
  int ActivityID; // eax
  const char *v60; // edi
  const char *v61; // eax
  const char *v62; // edi
  const char *v63; // eax
  int v64; // edi
  const char *v65; // eax
  const char *DebugName; // eax
  CBaseCombatWeapon *v67; // eax
  CBaseCombatWeapon *v68; // eax
  CBaseEdict *v69; // ecx
  CBaseCombatWeapon *v70; // eax
  variant_t v71; // [esp+0h] [ebp-144h] BYREF
  int flValue; // [esp+14h] [ebp-130h]
  char v73[12]; // [esp+28h] [ebp-11Ch] BYREF
  char szEventOptions[128]; // [esp+34h] [ebp-110h] BYREF
  _BYTE info_36[68]; // [esp+D8h] [ebp-6Ch] OVERLAPPED BYREF
  const Vector *v76; // [esp+124h] [ebp-20h]
  const Vector *v77; // [esp+128h] [ebp-1Ch]
  CAI_BaseNPC *v78; // [esp+12Ch] [ebp-18h]
  CAI_BaseNPC *v79; // [esp+130h] [ebp-14h]
  CHandle<CBaseEntity> v80; // [esp+134h] [ebp-10h] BYREF
  CAI_BaseNPC *pAttacker; // [esp+138h] [ebp-Ch]
  CAI_BaseNPC *pTarget; // [esp+13Ch] [ebp-8h]
  CAI_BaseNPC *retaddr; // [esp+144h] [ebp+0h]

  pAttacker = a2;
  pTarget = retaddr;
  v3 = pEvent->type & 0x400;
  v4 = this;
  if ( v3 != 0 )
    event_lowword = pEvent->_event_lowword;
  else
    event_lowword = *(_DWORD *)&pEvent->_event_highword;
  if ( event_lowword <= 2001 )
  {
    if ( event_lowword == 2001 )
    {
      if ( (this->m_fFlags.m_Value & 1) != 0 )
        CBaseEntity::EmitSound(this, soundname: "AI_BaseNPC.BodyDrop_Light", soundtime: 0.0, duration: nullptr);
      return;
    }
    if ( event_lowword > 1000 )
    {
      LODWORD(v8) = event_lowword - 1001;
      switch ( event_lowword )
      {
        case 1001:
          if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v4->m_hCine) == nullptr )
            return;
          flValue = 0;
          goto LABEL_29;
        case 1002:
          if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v4->m_hCine) == nullptr )
            return;
          flValue = 1;
LABEL_29:
          v12 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v4->m_hCine);
          CAI_ScriptedSequence::AllowInterrupt(this: v12, fAllow: flValue);
          break;
        case 1003:
          if ( CHandle<CBaseEntity>::operator!=(this: (CHandle<CBaseEntity> *)&v4->m_hCine, val: nullptr) )
          {
            flValue = atoi(nptr: pEvent->options);
            v10 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v4->m_hCine);
            CAI_ScriptedSequence::FireScriptEvent(this: v10, nEvent: flValue);
          }
          return;
        case 1004:
        case 1008:
          CBaseEntity::EmitSound(this: v4, soundname: pEvent->options, soundtime: 0.0, duration: nullptr);
          return;
        case 1005:
          goto $LN104;
        case 1009:
          if ( random->RandomInt(this: random, a2: 0, a3: 2) != 0 )
          {
$LN104:
            m_pPev = v4->m_Network.m_pPev;
            v71.vecVal[2] = v8;
            SENTENCEG_PlayRndSz(
              entity: m_pPev,
              szgroupname: pEvent->options,
              volume: 1.0,
              soundlevel: SNDLVL_80dB,
              flags: 0,
              pitch: 100);
          }
          break;
        case 1010:
          if ( v4->m_NPCState == NPC_STATE_SCRIPT )
          {
            if ( v4->m_lifeState.m_Value != 0 )
            {
              v4->NetworkStateChanged_m_lifeState(this: v4, a2: &v4->m_lifeState);
              v4->m_lifeState.m_Value = 0;
            }
            if ( v4->m_iHealth.m_Value != v4->m_iMaxHealth.m_Value )
            {
              v4->NetworkStateChanged_m_iHealth(this: v4, a2: &v4->m_iHealth);
              v4->m_iHealth.m_Value = v4->m_iMaxHealth.m_Value;
            }
          }
          break;
        case 1020:
        case 1021:
        case 1022:
          DevMsg(a1: "Bodygroup!\n");
          break;
        case 1100:
          v11 = (unsigned int)v4->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          flValue = 0;
          v80.m_Index = v11;
          *(_DWORD *)&info_36[48] = 0;
          *(_DWORD *)&info_36[60] = -1;
          *(_DWORD *)&info_36[64] = 0;
          variant_t::variant_t(this: &v71, __that: (const variant_t *)&info_36[48]);
          (*(void (__thiscall **)(CAI_BaseNPC *, const char *, CAI_BaseNPC *, CAI_BaseNPC *))(v80.m_Index + 156))(
            a1: v4,
            a2: pEvent->options,
            a3: v4,
            a4: v4);
          break;
        default:
          goto LABEL_87;
      }
      return;
    }
    if ( event_lowword == 1000 )
    {
      if ( this->m_NPCState == NPC_STATE_SCRIPT )
      {
        p_m_lifeState = &this->m_lifeState;
        if ( this->m_lifeState.m_Value != 1 )
        {
          this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
          p_m_lifeState->m_Value = 1;
        }
        p_m_iHealth = &v4->m_iHealth;
        if ( p_m_iHealth->m_Value != 0 )
        {
          (*(void (__thiscall **)(int *, CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *))(p_m_iHealth[-132].m_Value
                                                                                                  + 732))(
            a1: &p_m_iHealth[-132].m_Value,
            a2: p_m_iHealth);
          p_m_iHealth->m_Value = 0;
        }
      }
      return;
    }
    if ( event_lowword == 28 )
      return;
LABEL_87:
    if ( v3 != 0 && (pEvent->type & 1) != 0 )
    {
      switch ( event_lowword )
      {
        case 12:
          ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v4);
          v51 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
          v51->Holster(this: v51, a2: nullptr);
          CBaseCombatCharacter::SetActiveWeapon(this: v4, pNewWeapon: nullptr);
          CAI_Navigator::SetArrivalSequence(this: v4->m_pNavigator, sequence: -1);
          if ( v4->m_iDesiredWeaponState == DESIREDWEAPONSTATE_CHANGING_DESTROY )
            UTIL_Remove(oldObj: ActiveWeapon);
          if ( v4->m_iDesiredWeaponState != DESIREDWEAPONSTATE_IGNORE )
          {
            v4->m_iDesiredWeaponState = DESIREDWEAPONSTATE_IGNORE;
            v4->m_Activity = ACT_RESET;
          }
          return;
        case 13:
          if ( CBaseCombatCharacter::GetActiveWeapon(this: v4) != nullptr )
          {
            v52 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
            v52->Deploy(this: v52);
            CAI_Navigator::SetArrivalSequence(this: v4->m_pNavigator, sequence: -1);
            if ( v4->m_iDesiredWeaponState != DESIREDWEAPONSTATE_IGNORE )
            {
              v4->m_iDesiredWeaponState = DESIREDWEAPONSTATE_IGNORE;
              v4->m_Activity = ACT_RESET;
            }
          }
          return;
        case 4:
$LN92:
          if ( (v4->m_fFlags.m_Value & 1) != 0 )
            CBaseEntity::EmitSound(this: v4, soundname: "AI_BaseNPC.BodyDrop_Heavy", soundtime: 0.0, duration: nullptr);
          return;
        case 1:
        case 2:
          return;
        case 25:
          v4->BecomeRagdollOnClient(this: v4, a2: &vec3_origin);
          return;
        case 26:
          v53 = CBaseAnimating::LookupActivity(this: v4, label: pEvent->options);
          if ( v53 != ACT_INVALID )
          {
            v54 = CAI_BaseNPC::TranslateActivity(this: v4, idealActivity: v53, pIdealWeaponActivity: nullptr);
            if ( v54 != ACT_INVALID )
              CBaseAnimatingOverlay::AddGesture(this: v4, activity: v54, autokill: true);
          }
          return;
        case 27:
          v55 = CBaseAnimating::LookupActivity(this: v4, label: pEvent->options);
          if ( v55 != ACT_INVALID )
          {
            v56 = CAI_BaseNPC::TranslateActivity(this: v4, idealActivity: v55, pIdealWeaponActivity: nullptr);
            if ( v56 != ACT_INVALID )
              CBaseAnimatingOverlay::RestartGesture(this: v4, activity: v56, addifmissing: true, autokill: true);
          }
          return;
        case 8:
$LN64:
          options = pEvent->options;
          if ( options != nullptr
            && (EntityGeneric = CGlobalEntityList::FindEntityGeneric(
                                  this: &gEntList,
                                  pStartEntity: nullptr,
                                  szName: options,
                                  pSearchingEntity: v4,
                                  pActivator: nullptr,
                                  pCaller: nullptr)) != nullptr )
          {
            v37 = (int)EntityGeneric->WorldSpaceCenter(this: EntityGeneric);
            v38 = v4->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
            *(_QWORD *)&info_36[56] = *(_QWORD *)v37;
            v39 = *(_DWORD *)(v37 + 8);
            v77 = nullptr;
            *(_DWORD *)&info_36[64] = v39;
            v76 = (const Vector *)&info_36[56];
            v40 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
            v38->Weapon_Drop(this: v4, a2: v40, a3: v76, a4: v77);
          }
          else
          {
            v41 = v4->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
            v42 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
            v41->Weapon_Drop(this: v4, a2: v42, a3: nullptr, a4: nullptr);
          }
          return;
        case 11:
          v57 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
          if ( v57 != nullptr && pEvent->options != nullptr )
          {
            v34 = CBaseAnimating::LookupActivity(this: v57, label: pEvent->options);
            if ( v34 != ACT_INVALID )
              goto LABEL_69;
            v58 = pEvent->options;
            v80.m_Index = (unsigned int)v4->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
            ActivityID = CAI_BaseNPC::GetActivityID(actName: v58);
            v34 = (*(int (__thiscall **)(CAI_BaseNPC *, int, _DWORD))(v80.m_Index + 1084))(
                    a1: v4,
                    a2: ActivityID,
                    a3: 0);
LABEL_68:
            if ( v34 != ACT_INVALID )
LABEL_69:
              CBaseCombatCharacter::Weapon_SetActivity(this: v4, newActivity: v34, duration: 0.0);
          }
          return;
        case 30:
          v4->m_bCannotDieDuringInteraction = atoi(nptr: pEvent->options) != 0;
          return;
        case 29:
          v80.m_Index = (unsigned int)&v4->m_hInteractionPartner;
          if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v4->m_hInteractionPartner) != nullptr )
          {
            v60 = pEvent->options;
            v79 = nullptr;
            v78 = nullptr;
            if ( v60 != nullptr
              && (V_strncpy(pDest: v73, pSrc: v60, maxLen: 128),
                  v61 = strtok(string: v73, control: " "),
                  v62 = v61,
                  v61 != nullptr)
              && (V_strncmp(s1: v61, s2: "ME", count: 2) != 0
                ? (V_strncmp(s1: v62, s2: "THEM", count: 4) != 0
                 ? (v4 = v78)
                 : (v79 = (CAI_BaseNPC *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)v80.m_Index)))
                : (v79 = v4,
                   v4 = (CAI_BaseNPC *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)v80.m_Index)),
                  (v63 = strtok(string: nullptr, control: " "), v4 != nullptr)
               && v79 != nullptr
               && v63 != nullptr
               && (v64 = atoi(nptr: v63)) != 0) )
            {
              CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&szEventOptions[116]);
              *(float *)info_36 = (float)v64;
              CTakeDamageInfo::SetAttacker(this: (CTakeDamageInfo *)&szEventOptions[116], pAttacker: v4);
              CTakeDamageInfo::SetInflictor(this: (CTakeDamageInfo *)&szEventOptions[116], pInflictor: v4);
              *(_DWORD *)&info_36[12] = 2048;
              CBaseEntity::TakeDamage(this: v79, inputInfo: (const CTakeDamageInfo *)&szEventOptions[116]);
            }
            else
            {
              v65 = EventList_NameForIndex(eventIndex: 29);
              _DevWarning(
                a1: 1,
                a2: "Bad %s format. Should be: { AE_NPC_HURT_INTERACTION_PARTNER <frame number> \"<ME/THEM> <Amount of damage done>\" }\n",
                v65);
            }
          }
          else
          {
            DebugName = CBaseEntity::GetDebugName(this: v4);
            DevWarning(
              a1: "%s received AE_NPC_HURT_INTERACTION_PARTNER anim event, but it's not interacting with anything.\n",
              DebugName);
          }
          return;
        default:
          break;
      }
    }
    if ( pEvent->pSource != v4 || v3 != 0 && (pEvent->type & 8) != 0 || event_lowword >= 3000 && event_lowword <= 3999 )
      v4->Weapon_HandleAnimEvent(this: v4, a2: pEvent);
    else
      CBaseAnimating::HandleAnimEvent(this: v4, pEvent);
    return;
  }
  if ( event_lowword > 3015 )
  {
    if ( event_lowword != 3017 )
    {
      if ( event_lowword != 3018 )
        goto LABEL_87;
      if ( CBaseCombatCharacter::GetActiveWeapon(this) == nullptr )
        return;
      v67 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
      v80.m_Index = v67->GetMaxClip1(this: v67);
      v68 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
      v47 = v68;
      if ( v68->m_iClip1.m_Value != v80.m_Index )
      {
        if ( v68->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v68->m_Network + 76) |= 1u;
          m_Index = (CBaseEntity *)v80.m_Index;
        }
        else
        {
          v69 = &v68->m_Network.m_pPev->CBaseEdict;
          if ( v69 != nullptr )
            CBaseEdict::StateChanged(this: v69, offset: 0x4B0u);
          m_Index = (CBaseEntity *)v80.m_Index;
        }
        goto LABEL_83;
      }
LABEL_84:
      CAI_BaseNPC::ClearCondition(this: v4, iCondition: 3);
      CAI_BaseNPC::ClearCondition(this: v4, iCondition: 4);
      CAI_BaseNPC::ClearCondition(this: v4, iCondition: 5);
      return;
    }
    if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
    {
      v70 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
      ((void (__thiscall *)(CBaseCombatWeapon *, int, _DWORD))v70->WeaponSound)(a1: v70, a2: 7, a3: 0);
    }
  }
  else
  {
    if ( event_lowword != 3015 )
    {
      switch ( event_lowword )
      {
        case 2002:
          goto $LN92;
        case 2010:
          CBaseEntity::EmitSound(this, soundname: "AI_BaseNPC.SwishSound", soundtime: 0.0, duration: nullptr);
          return;
        case 2020:
          CAI_BaseNPC::SetIdealActivity(this, NewActivity: ACT_IDLE);
          y = v4->m_angRotation.m_Value.y;
          v4->m_afMemory &= ~0x2000u;
          CBaseAnimating::SetBoneController(this: v4, iController: 0, flValue: y);
          CBaseEntity::AddEffects(this: v4, nEffects: 8);
          return;
        case 2040:
          v14 = pEvent->options;
          if ( v14 != nullptr && strlen(v14) != 0 )
          {
            AbsOrigin = CBaseEntity::GetAbsOrigin(this: v4);
            EntityGenericNearest = CGlobalEntityList::FindEntityGenericNearest(
                                     this: &gEntList,
                                     szName: pEvent->options,
                                     vecSrc: AbsOrigin,
                                     flRadius: 256.0,
                                     pSearchingEntity: v4,
                                     pActivator: nullptr,
                                     pCaller: nullptr);
          }
          else
          {
            EntityGenericNearest = CAI_BaseNPC::GetTarget(this: v4);
          }
          v17 = EntityGenericNearest;
          if ( EntityGenericNearest != nullptr )
          {
            v80.m_Index = (unsigned int)CBaseEntity::GetAbsOrigin(this: v4);
            v18 = (float *)v17->WorldSpaceCenter(this: v17);
            v19 = 0;
            *(float *)&v19 = fsqrt(
                               (float)((float)(v18[1] - *(float *)(v80.m_Index + 4))
                                     * (float)(v18[1] - *(float *)(v80.m_Index + 4)))
                             + (float)((float)(*v18 - *(float *)v80.m_Index) * (float)(*v18 - *(float *)v80.m_Index)));
            *(_OWORD *)&info_36[48] = v19;
            if ( *(float *)&v19 <= 48.0 )
            {
              v20 = ToBaseCombatWeapon(pEntity: v17);
              v80.m_Index = (unsigned int)v20;
              if ( v20 != nullptr )
              {
                v21 = CBaseCombatWeapon::GetOwner(this: v20) == nullptr;
                v22 = v4->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
                if ( v21 )
                {
                  v23 = v80.m_Index;
                  v21 = !v22->Weapon_CanUse(this: v4, a2: (CBaseCombatWeapon *)v80.m_Index);
                  v24 = v4->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
                  if ( v21 )
                  {
                    v24->TaskFail(this: v4, a2: (int)"Can't use this weapon type");
                  }
                  else
                  {
                    PickupWeapon = v24->PickupWeapon;
                    v80.m_Index = v23;
                    ((void (__thiscall *)(CAI_BaseNPC *))PickupWeapon)(a1: v4);
                    CAI_BaseNPC::TaskComplete(this: v4, fIgnoreSetFailedCondition: false);
                  }
                }
                else
                {
                  v22->TaskFail(this: v4, a2: (int)"Weapon in use by someone else");
                }
              }
              else
              {
                PickupItem = v4->PickupItem;
                v80.m_Index = (unsigned int)v17;
                ((void (__thiscall *)(CAI_BaseNPC *))PickupItem)(a1: v4);
                CAI_BaseNPC::TaskComplete(this: v4, fIgnoreSetFailedCondition: false);
              }
            }
            else
            {
              v4->TaskFail(this: v4, a2: (int)"Item has moved!\n");
            }
          }
          else
          {
            v4->TaskFail(this: v4, a2: (int)"Item no longer available!\n");
          }
          return;
        case 2041:
          goto $LN64;
        case 2042:
          v30 = CBaseCombatCharacter::GetActiveWeapon(this);
          v27 = v30;
          if ( v30 == nullptr )
            return;
          v31 = pEvent->options;
          if ( v31 == nullptr )
            return;
          v29 = CBaseAnimating::LookupSequence(this: v30, label: v31);
          goto LABEL_60;
        case 2043:
          v27 = CBaseCombatCharacter::GetActiveWeapon(this);
          if ( v27 == nullptr )
            return;
          v28 = pEvent->options;
          if ( v28 == nullptr )
            return;
          v29 = atoi(nptr: v28);
LABEL_60:
          if ( v29 != -1 )
            CBaseAnimating::ResetSequence(this: v27, nSequence: v29);
          return;
        case 2044:
          v32 = CBaseCombatCharacter::GetActiveWeapon(this);
          if ( v32 == nullptr )
            return;
          v33 = pEvent->options;
          if ( v33 == nullptr )
            return;
          v34 = CBaseAnimating::LookupActivity(this: v32, label: v33);
          goto LABEL_68;
        case 2050:
        case 2051:
          return;
        case 2060:
          v80.m_Index = this->m_pNavigator->m_pPath->m_Waypoints.m_pFirstWaypoint->m_hData.m_Index;
          v43 = (CBasePropDoor *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v80);
          if ( v43 != nullptr )
            CAI_BaseNPC::OpenPropDoorBegin(this: v4, pDoor: v43);
          return;
        default:
          goto LABEL_87;
      }
    }
    if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
    {
      v44 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
      ((void (__thiscall *)(CBaseCombatWeapon *, int, _DWORD))v44->WeaponSound)(a1: v44, a2: 7, a3: 0);
      v45 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
      v79 = (CAI_BaseNPC *)v45->GetMaxClip1(this: v45);
      v46 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
      v47 = v46;
      if ( (CAI_BaseNPC *)v46->m_iClip1.m_Value != v79 )
      {
        if ( v46->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v46->m_Network + 76) |= 1u;
        }
        else
        {
          v48 = &v46->m_Network.m_pPev->CBaseEdict;
          if ( v48 != nullptr )
            CBaseEdict::StateChanged(this: v48, offset: 0x4B0u);
        }
        m_Index = v79;
LABEL_83:
        v47->m_iClip1.m_Value = (int)m_Index;
        goto LABEL_84;
      }
      goto LABEL_84;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031B60
// Name: public: virtual int CAI_BaseNPC::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::DrawDebugTextOverlays(CAI_BaseNPC *this)
{
  int v2; // edi
  int v3; // edi
  CAI_Squad *m_pSquad; // eax
  const char *pszValue; // eax
  int v6; // edi
  const char *v7; // eax
  int v8; // edi
  const char *v9; // eax
  NPC_STATE m_NPCState; // eax
  int v11; // edi
  unsigned __int32 v12; // eax
  CAI_BehaviorBase *m_pPrimaryBehavior; // ecx
  const char *v14; // eax
  char *m_pName; // eax
  CAI_Schedule *m_pSchedule; // eax
  int i; // ebx
  const char *v18; // ecx
  const char *v19; // eax
  const Task_t *Task; // eax
  const char *v21; // eax
  Activity m_Activity; // eax
  Activity v23; // ebx
  Activity v24; // eax
  const char *ActivityName; // ebx
  const char *v26; // eax
  const char *v27; // eax
  Activity v28; // eax
  char v29; // cl
  int v30; // ebx
  int v31; // eax
  const char *v32; // eax
  CAI_Schedule *m_interuptSchedule; // eax
  const char *v34; // eax
  CAI_Schedule *m_failedSchedule; // eax
  const char *v36; // eax
  CAI_ClassScheduleIdSpace *v37; // eax
  int v38; // eax
  int v39; // eax
  float m_LastShootAccuracy; // xmm0_4
  char *v41; // eax
  int m_TotalShots; // eax
  char *v43; // eax
  CAI_BaseNPC_vtbl *v44; // ebx
  CBaseCombatWeapon *ActiveWeapon; // eax
  CAI_BaseNPC_vtbl *v46; // ebx
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // eax
  CBaseCombatWeapon *v48; // eax
  long double v49; // st7
  double v50; // xmm0_8
  char *v51; // eax
  unsigned int m_Index; // eax
  unsigned int v53; // eax
  IHandleEntity *m_pEntity; // ecx
  const char *v55; // ecx
  IHandleEntity *v56; // ecx
  IPhysicsObject *m_pPhysicsObject; // eax
  CAI_Squad *v58; // ecx
  const char *v59; // eax
  double x; // [esp+24h] [ebp-43Ch]
  Activity duration_4; // [esp+34h] [ebp-42Ch]
  const char *v63; // [esp+3Ch] [ebp-424h]
  int iCurTask; // [esp+3Ch] [ebp-424h]
  CBaseEntity *v65; // [esp+3Ch] [ebp-424h]
  int v66; // [esp+3Ch] [ebp-424h]
  int m_iMySquadSlot; // [esp+40h] [ebp-420h]
  CFmtStrN<256> msg; // [esp+4Ch] [ebp-414h] BYREF
  int v69; // [esp+248h] [ebp-218h]
  char tempstr[512]; // [esp+24Ch] [ebp-214h] BYREF
  vphysics_objectstress_t stressOut; // [esp+44Ch] [ebp-14h] BYREF
  const char *v72; // [esp+458h] [ebp-8h]
  Activity iIdealActivity; // [esp+45Ch] [ebp-4h]

  v2 = CBaseAnimating::DrawDebugTextOverlays(this);
  if ( (this->m_debugOverlays & 0x80000) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Health: %i", this->m_iHealth.m_Value);
    CBaseEntity::EntityText(this, text_offset: v2, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v3 = v2 + 1;
    V_strncpy(pDest: tempstr, pSrc: "Squad: ", maxLen: 512);
    m_pSquad = this->m_pSquad;
    if ( m_pSquad != nullptr )
    {
      pszValue = m_pSquad->m_Name.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      V_strncat(pDest: tempstr, pSrc: pszValue, destBufferSize: 0x200u, max_chars_to_copy: -1);
      if ( CAI_Squad::GetLeader(this: this->m_pSquad) == this )
        V_strncat(pDest: tempstr, pSrc: " (LEADER)", destBufferSize: 0x200u, max_chars_to_copy: -1);
      V_strncat(pDest: tempstr, pSrc: "\n", destBufferSize: 0x200u, max_chars_to_copy: -1);
    }
    else
    {
      V_strncat(pDest: tempstr, pSrc: " - \n", destBufferSize: 0x200u, max_chars_to_copy: -1);
    }
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v6 = v3 + 1;
    V_strncpy(pDest: tempstr, pSrc: "Enemy: ", maxLen: 512);
    if ( this->GetEnemy_2(this) != nullptr )
    {
      if ( this->GetEnemy_2(this)->m_iName.m_Value.pszValue != nullptr )
      {
        v7 = this->GetEnemy_2(this)->m_iName.m_Value.pszValue;
        if ( v7 == nullptr )
          v7 = locale;
      }
      else
      {
        v7 = this->GetEnemy_2(this)->m_iClassname.pszValue;
        if ( v7 == nullptr )
          v7 = locale;
      }
      V_strncat(pDest: tempstr, pSrc: v7, destBufferSize: 0x200u, max_chars_to_copy: -1);
      V_strncat(pDest: tempstr, pSrc: "\n", destBufferSize: 0x200u, max_chars_to_copy: -1);
    }
    else
    {
      V_strncat(pDest: tempstr, pSrc: " - \n", destBufferSize: 0x200u, max_chars_to_copy: -1);
    }
    CBaseEntity::EntityText(this, text_offset: v6, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    m_iMySquadSlot = this->m_iMySquadSlot;
    v8 = v6 + 1;
    v9 = this->SquadSlotName(this, a2: m_iMySquadSlot);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Slot:  %s (%d)\n", v9, m_iMySquadSlot);
    CBaseEntity::EntityText(this, text_offset: v8, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v2 = v8 + 1;
  }
  if ( (this->m_debugOverlays & 1) == 0 )
    return v2;
  V_snprintf(
    pDest: tempstr,
    maxLen: 512,
    pFormat: "Health: %i  (DACC:%1.2f)",
    this->m_iHealth.m_Value,
    this->m_flDamageAccumulator);
  CBaseEntity::EntityText(this, text_offset: v2, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
  m_NPCState = this->m_NPCState;
  v11 = v2 + 1;
  if ( (unsigned int)m_NPCState < NPC_STATE_DEAD )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Stat: %s, ", pStateNames_0[m_NPCState]);
    CBaseEntity::EntityText(this, text_offset: v11++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
  }
  if ( this->m_bInAScript )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "STARTSCRIPTING");
    CBaseEntity::EntityText(this, text_offset: v11++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
  }
  if ( this->m_strHintGroup.pszValue != nullptr )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Hint Group: %s", this->m_strHintGroup.pszValue);
    CBaseEntity::EntityText(this, text_offset: v11++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
  }
  v12 = this->m_pNavigator->m_navType + 1;
  if ( v12 < 6 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Move: %s, ", pMoveNames[v12]);
    CBaseEntity::EntityText(this, text_offset: v11++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
  }
  if ( this->m_pSchedule != nullptr )
  {
    m_pPrimaryBehavior = this->m_pPrimaryBehavior;
    if ( m_pPrimaryBehavior != nullptr )
    {
      v14 = m_pPrimaryBehavior->GetName(this: m_pPrimaryBehavior);
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Behv: %s, ", v14);
      CBaseEntity::EntityText(this, text_offset: v11++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
    }
    m_pName = this->m_pSchedule->m_pName;
    if ( m_pName == nullptr )
      m_pName = "Unknown";
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Schd: %s, ", m_pName);
    CBaseEntity::EntityText(this, text_offset: v11++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
    if ( (this->m_debugOverlays & 0x100000) != 0 )
    {
      m_pSchedule = this->m_pSchedule;
      for ( i = 0; i < m_pSchedule->m_iNumTasks; ++v11 )
      {
        v18 = "<-";
        if ( i == this->m_ScheduleState.iCurTask )
        {
          v72 = "->";
        }
        else
        {
          v18 = locale;
          v72 = "   ";
        }
        *(float *)&iIdealActivity = COERCE_FLOAT("Task:");
        if ( i != 0 )
          *(float *)&iIdealActivity = COERCE_FLOAT("       ");
        v63 = v18;
        v19 = this->TaskName(this, a2: m_pSchedule->m_pTaskList[i].iTask);
        V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "%s%s%s%s", (const char *)iIdealActivity, v72, v19, v63);
        CBaseEntity::EntityText(this, text_offset: v11, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
        m_pSchedule = this->m_pSchedule;
        ++i;
      }
    }
    else
    {
      Task = CAI_BaseNPC::GetTask(this);
      if ( Task != nullptr )
      {
        iCurTask = this->m_ScheduleState.iCurTask;
        v21 = this->TaskName(this, a2: Task->iTask);
        V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Task: %s (#%d), ", v21, iCurTask);
      }
      else
      {
        V_strncpy(pDest: tempstr, pSrc: "Task: None", maxLen: 512);
      }
      CBaseEntity::EntityText(this, text_offset: v11++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
    }
  }
  m_Activity = this->m_Activity;
  if ( m_Activity != ACT_INVALID && this->m_IdealActivity != ACT_INVALID )
  {
    if ( m_Activity != ACT_RESET )
    {
      v23 = CAI_BaseNPC::TranslateActivity(this, idealActivity: m_Activity, pIdealWeaponActivity: nullptr);
      v24 = this->Weapon_TranslateActivity(this, a2: this->m_IdealActivity, a3: nullptr);
      *(float *)&iIdealActivity = COERCE_FLOAT(this->NPC_TranslateActivity(this, a2: v24));
      ActivityName = CAI_BaseNPC::GetActivityName(actID: v23);
      v26 = CAI_BaseNPC::GetActivityName(actID: iIdealActivity);
      duration_4 = this->m_Activity;
      iIdealActivity = (Activity)v26;
      v27 = CAI_BaseNPC::GetActivityName(actID: duration_4);
      V_snprintf(
        pDest: tempstr,
        maxLen: 512,
        pFormat: "Actv: %s (%s) [%s]\n",
        ActivityName,
        (const char *)iIdealActivity,
        v27);
      goto LABEL_53;
    }
  }
  else if ( m_Activity != ACT_RESET )
  {
    V_strncpy(pDest: tempstr, pSrc: "Actv: INVALID", maxLen: 512);
LABEL_53:
    CBaseEntity::EntityText(this, text_offset: v11, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
    v2 = v11 + 1;
    if ( (this->m_debugOverlays & 0x40000) != 0 )
    {
      v28 = ACT_IDLE;
      v29 = 0;
      v30 = 0;
      iIdealActivity = ACT_IDLE;
      do
      {
        if ( (v28 & this->m_Conditions.m_Ints[v30 >> 5]) != 0 )
        {
          if ( v30 == -1 )
            v31 = -1;
          else
            v31 = v30 + 1000000000;
          v32 = this->ConditionName(this, a2: v31);
          V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Cond: %s\n", v32);
          CBaseEntity::EntityText(this, text_offset: v2, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
          v28 = iIdealActivity;
          ++v2;
          v29 = 1;
        }
        ++v30;
        v28 = __ROL4__(v28, 1);
        iIdealActivity = v28;
      }
      while ( v30 < 256 );
      if ( v29 == 0 )
      {
        V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "(no conditions)");
        CBaseEntity::EntityText(this, text_offset: v2++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
      }
    }
    if ( (this->m_fFlags.m_Value & 0x800) != 0 )
      CBaseEntity::EntityText(
        this,
        text_offset: v2++,
        text: "HAS FL_FLY",
        duration: 0.0,
        r: 255,
        g: 255,
        b: 255,
        a: 255);
    m_interuptSchedule = this->m_interuptSchedule;
    if ( m_interuptSchedule != nullptr )
    {
      v34 = m_interuptSchedule->m_pName;
      if ( v34 == nullptr )
        v34 = "Unknown";
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Intr: %s (%s)\n", v34, this->m_interruptText);
      CBaseEntity::EntityText(this, text_offset: v2++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
    }
    m_failedSchedule = this->m_failedSchedule;
    if ( m_failedSchedule != nullptr )
    {
      v36 = m_failedSchedule->m_pName;
      if ( v36 == nullptr )
        v36 = "Unknown";
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Fail: %s (%s)\n", v36, this->m_failText);
      CBaseEntity::EntityText(this, text_offset: v2++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
    }
    v37 = this->GetClassScheduleIdSpace(this);
    v38 = CAI_LocalIdSpace::LocalToGlobal(this: &v37->m_ConditionIds, localID: 27);
    if ( v38 != -1 )
    {
      v39 = v38 - 1000000000;
      if ( v39 != -1 && ((1 << (v39 & 0x1F)) & this->m_Conditions.m_Ints[v39 >> 5]) != 0 )
        CBaseEntity::EntityText(
          this,
          text_offset: v2++,
          text: "Enemy too far to attack",
          duration: 0.0,
          r: 0,
          g: 255,
          b: 255,
          a: 255);
    }
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this);
    if ( vec3_origin.x != this->m_vecAbsVelocity.x
      || vec3_origin.y != this->m_vecAbsVelocity.y
      || vec3_origin.z != this->m_vecAbsVelocity.z
      || vec3_angle.x != this->m_vecAngVelocity.x
      || vec3_angle.y != this->m_vecAngVelocity.y
      || vec3_angle.z != this->m_vecAngVelocity.z )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this);
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this);
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this);
      V_snprintf(
        pDest: (char *)&msg,
        maxLen: 512,
        pFormat: "Vel %.1f %.1f %.1f   Ang: %.1f %.1f %.1f\n",
        this->m_vecAbsVelocity.x,
        this->m_vecAbsVelocity.y,
        this->m_vecAbsVelocity.z,
        this->m_vecAngVelocity.x,
        this->m_vecAngVelocity.y,
        this->m_vecAngVelocity.z);
      CBaseEntity::EntityText(
        this,
        text_offset: v2++,
        text: (const char *)&msg,
        duration: 0.0,
        r: 0,
        g: 255,
        b: 255,
        a: 255);
    }
    m_LastShootAccuracy = this->m_LastShootAccuracy;
    if ( m_LastShootAccuracy != -1.0
      && ai_shot_stats.m_pParent != nullptr
      && ai_shot_stats.m_pParent->m_Value.m_nValue != 0 )
    {
      *(_DWORD *)&msg.m_szBuf[239] = &CFmtStrN<256>::`vftable';
      *(_WORD *)&msg.m_szBuf[243] = 1;
      v69 = 0;
      v41 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
              this: (CFmtStrN<256> *)&msg.m_szBuf[239],
              pszFormat: "Cur Accuracy: %.1f",
              m_LastShootAccuracy);
      CBaseEntity::EntityText(this, text_offset: v2, text: v41, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      m_TotalShots = this->m_TotalShots;
      ++v2;
      if ( m_TotalShots != 0 )
      {
        v43 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
                this: (CFmtStrN<256> *)&msg.m_szBuf[239],
                pszFormat: "Act Accuracy: %.1f",
                (float)((float)this->m_TotalHits / (float)m_TotalShots) * 100.0);
        CBaseEntity::EntityText(this, text_offset: v2++, text: v43, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
      }
      if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr && this->GetEnemy_2(this) != nullptr )
      {
        v44 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v65 = this->GetEnemy_2(this);
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
        v44->GetAttackSpread(this, result: (Vector *)&stressOut, a3: ActiveWeapon, a4: v65);
        v46 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        GetEnemy_2 = this->GetEnemy_2;
        iIdealActivity = SLODWORD(stressOut.exertedStress);
        v66 = (int)GetEnemy_2(this);
        v48 = CBaseCombatCharacter::GetActiveWeapon(this);
        v49 = ((double (__thiscall *)(CAI_BaseNPC *, CBaseCombatWeapon *, int))v46->GetSpreadBias)(
                a1: this,
                a2: v48,
                a3: v66);
        v50 = *(float *)&iIdealActivity;
        __libm_sse2_asin(x: v49);
        *(float *)&v50 = v50;
        v51 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
                this: (CFmtStrN<256> *)&msg.m_szBuf[239],
                pszFormat: "Cone %.1f, Bias %.2f",
                (float)((float)(*(float *)&v50 * 57.29578) * 2.0),
                x);
        CBaseEntity::EntityText(this, text_offset: v2++, text: v51, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
      }
    }
    m_Index = this->m_hGoalEnt.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
      && CAI_Navigator::GetGoalType(this: this->m_pNavigator) == GOALTYPE_PATHCORNER )
    {
      V_strncpy(pDest: tempstr, pSrc: "Pathcorner/goal ent: ", maxLen: 512);
      v53 = this->m_hGoalEnt.m_Index;
      if ( v53 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v53].m_SerialNumber != HIWORD(v53) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v53].m_pEntity;
      if ( m_pEntity[51].__vftable != nullptr )
      {
        if ( v53 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v53].m_SerialNumber != HIWORD(v53) )
          v55 = (const char *)MEMORY[0xCC];
        else
          v55 = (const char *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v53].m_pEntity[51].__vftable;
      }
      else
      {
        if ( v53 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v53].m_SerialNumber != HIWORD(v53) )
          v56 = nullptr;
        else
          v56 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v53].m_pEntity;
        v55 = (const char *)v56[23].__vftable;
      }
      if ( v55 == nullptr )
        v55 = locale;
      V_strncat(pDest: tempstr, pSrc: v55, destBufferSize: 0x200u, max_chars_to_copy: -1);
      CBaseEntity::EntityText(this, text_offset: v2++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
    }
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      CalculateObjectStress(pObject: m_pPhysicsObject, pInputOwnerEntity: this, pOutput: &stressOut);
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Stress: %.2f", stressOut.receivedStress);
      CBaseEntity::EntityText(this, text_offset: v2++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
    }
    v58 = this->m_pSquad;
    if ( v58 != nullptr )
    {
      if ( CAI_Squad::IsLeader(this: v58, pNPC: this) )
      {
        V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "**Squad Leader**");
        CBaseEntity::EntityText(this, text_offset: v2++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
      }
      v59 = this->GetSquadSlotDebugName(this, a2: this->m_iMySquadSlot);
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "SquadSlot:%s", v59);
      CBaseEntity::EntityText(this, text_offset: v2++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 255, a: 255);
    }
    if ( this->m_pPrimaryBehavior != nullptr )
      return this->m_pPrimaryBehavior->DrawDebugTextOverlays(this: this->m_pPrimaryBehavior, a2: v2);
    return v2;
  }
  V_strncpy(pDest: tempstr, pSrc: "Actv: RESET", maxLen: 512);
  goto LABEL_53;
}

//------------------------------------------------------------------------------
// Address: 0x10037400
// Name: public: CAI_BaseNPC::CAI_BaseNPC(void)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC *__thiscall CAI_BaseNPC::CAI_BaseNPC(CAI_BaseNPC *this)
{
  UnreachableEnt_t *v2; // eax
  CAI_Enemies *v3; // eax
  CAI_Enemies *v4; // eax
  CSound *v5; // eax
  int m_Size; // ecx
  int v7; // ecx
  int v8; // eax
  CAI_BaseNPC **v9; // eax
  int v11; // [esp+Ch] [ebp-4h]

  CBaseCombatCharacter::CBaseCombatCharacter(this);
  this->CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CAI_DefMovementSink::`vftable';
  this->IAI_BehaviorBridge::__vftable = (IAI_BehaviorBridge_vtbl *)&IAI_BehaviorBridge::`vftable';
  this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CAI_BaseNPC_vtbl *)&CAI_BaseNPC::`vftable'{for `CBaseCombatCharacter'};
  this->CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CAI_BaseNPC::`vftable'{for `CAI_DefMovementSink'};
  this->IAI_BehaviorBridge::__vftable = (IAI_BehaviorBridge_vtbl *)&CAI_BaseNPC::`vftable'{for `IAI_BehaviorBridge'};
  this->m_pPrimaryBehavior = nullptr;
  this->m_Behaviors.m_Memory.m_pMemory = nullptr;
  this->m_Behaviors.m_Memory.m_nAllocationCount = 0;
  this->m_Behaviors.m_Memory.m_nGrowSize = 0;
  this->m_Behaviors.m_Size = 0;
  this->m_Behaviors.m_pElements = nullptr;
  if ( this != (CAI_BaseNPC *)-2388 )
  {
    *(_QWORD *)this->m_Conditions.m_Ints = 0;
    *(_QWORD *)&this->m_Conditions.m_Ints[2] = 0;
    *(_QWORD *)&this->m_Conditions.m_Ints[4] = 0;
    *(_QWORD *)&this->m_Conditions.m_Ints[6] = 0;
  }
  if ( this != (CAI_BaseNPC *)-2420 )
  {
    *(_QWORD *)this->m_CustomInterruptConditions.m_Ints = 0;
    *(_QWORD *)&this->m_CustomInterruptConditions.m_Ints[2] = 0;
    *(_QWORD *)&this->m_CustomInterruptConditions.m_Ints[4] = 0;
    *(_QWORD *)&this->m_CustomInterruptConditions.m_Ints[6] = 0;
  }
  if ( this != (CAI_BaseNPC *)-2452 )
  {
    *(_QWORD *)this->m_ConditionsPreIgnore.m_Ints = 0;
    *(_QWORD *)&this->m_ConditionsPreIgnore.m_Ints[2] = 0;
    *(_QWORD *)&this->m_ConditionsPreIgnore.m_Ints[4] = 0;
    *(_QWORD *)&this->m_ConditionsPreIgnore.m_Ints[6] = 0;
  }
  if ( this != (CAI_BaseNPC *)-2484 )
  {
    *(_QWORD *)this->m_InverseIgnoreConditions.m_Ints = 0;
    *(_QWORD *)&this->m_InverseIgnoreConditions.m_Ints[2] = 0;
    *(_QWORD *)&this->m_InverseIgnoreConditions.m_Ints[4] = 0;
    *(_QWORD *)&this->m_InverseIgnoreConditions.m_Ints[6] = 0;
  }
  this->m_hEnemy.m_Index = -1;
  this->m_hTargetEnt.m_Index = -1;
  this->m_GiveUpOnDeadEnemyTimer.m_next = -1.0;
  this->m_GiveUpOnDeadEnemyTimer.m_fIsRunning = false;
  this->m_GiveUpOnDeadEnemyTimer.m_minInterval = 0.0;
  this->m_GiveUpOnDeadEnemyTimer.m_maxInterval = 0.0;
  this->m_FailChooseEnemyTimer.m_next = -1.0;
  this->m_UpdateEnemyPosTimer.m_next = -1.0;
  this->m_CommandMoveMonitor.m_vMark.x = 0.0;
  this->m_CommandMoveMonitor.m_vMark.y = 0.0;
  this->m_CommandMoveMonitor.m_vMark.z = 0.0;
  this->m_CommandMoveMonitor.m_flMarkTolerance = -1.0;
  this->m_hForcedInteractionPartner.m_Index = -1;
  this->m_hInteractionPartner.m_Index = -1;
  this->m_hLastInteractionTestTarget.m_Index = -1;
  this->m_ScriptedInteractions.m_Memory.m_pMemory = nullptr;
  this->m_ScriptedInteractions.m_Memory.m_nAllocationCount = 0;
  this->m_ScriptedInteractions.m_Memory.m_nGrowSize = 0;
  this->m_ScriptedInteractions.m_Size = 0;
  this->m_ScriptedInteractions.m_pElements = nullptr;
  this->m_hOpeningDoor.m_Index = -1;
  this->m_UnreachableEnts.m_Memory.m_pMemory = nullptr;
  this->m_UnreachableEnts.m_Memory.m_nAllocationCount = 4;
  this->m_UnreachableEnts.m_Memory.m_nGrowSize = 0;
  v2 = (UnreachableEnt_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 80);
  this->m_UnreachableEnts.m_Memory.m_pMemory = v2;
  this->m_UnreachableEnts.m_Size = 0;
  this->m_UnreachableEnts.m_pElements = v2;
  this->m_hGoalEnt.m_Index = -1;
  this->m_CheckOnGroundTimer.m_next = -1.0;
  this->m_hEyeLookTarget.m_Index = -1;
  this->m_hCine.m_Index = -1;
  this->m_hEnemyOccluder.m_Index = -1;
  CAI_ShotRegulator::CAI_ShotRegulator(this: &this->m_ShotRegulator);
  CAI_MoveAndShootOverlay::CAI_MoveAndShootOverlay(this: &this->m_MoveAndShootOverlay);
  this->m_pHintNode.m_Index = -1;
  this->m_hStoredPathTarget.m_Index = -1;
  this->m_hEnemyFilter.m_Index = -1;
  this->m_OnDamaged.m_Value.iVal = 0;
  this->m_OnDamaged.m_Value.eVal.m_Index = -1;
  this->m_OnDamaged.m_Value.fieldType = FIELD_VOID;
  this->m_OnDeath.m_Value.iVal = 0;
  this->m_OnDeath.m_Value.eVal.m_Index = -1;
  this->m_OnDeath.m_Value.fieldType = FIELD_VOID;
  this->m_OnHalfHealth.m_Value.iVal = 0;
  this->m_OnHalfHealth.m_Value.eVal.m_Index = -1;
  this->m_OnHalfHealth.m_Value.fieldType = FIELD_VOID;
  this->m_OnFoundEnemy.m_Value.iVal = 0;
  this->m_OnFoundEnemy.m_Value.eVal.m_Index = -1;
  this->m_OnFoundEnemy.m_Value.fieldType = FIELD_VOID;
  this->m_OnLostEnemyLOS.m_Value.iVal = 0;
  this->m_OnLostEnemyLOS.m_Value.eVal.m_Index = -1;
  this->m_OnLostEnemyLOS.m_Value.fieldType = FIELD_VOID;
  this->m_OnLostEnemy.m_Value.iVal = 0;
  this->m_OnLostEnemy.m_Value.eVal.m_Index = -1;
  this->m_OnLostEnemy.m_Value.fieldType = FIELD_VOID;
  this->m_OnFoundPlayer.m_Value.iVal = 0;
  this->m_OnFoundPlayer.m_Value.eVal.m_Index = -1;
  this->m_OnFoundPlayer.m_Value.fieldType = FIELD_VOID;
  this->m_OnLostPlayerLOS.m_Value.iVal = 0;
  this->m_OnLostPlayerLOS.m_Value.eVal.m_Index = -1;
  this->m_OnLostPlayerLOS.m_Value.fieldType = FIELD_VOID;
  this->m_OnLostPlayer.m_Value.iVal = 0;
  this->m_OnLostPlayer.m_Value.eVal.m_Index = -1;
  this->m_OnLostPlayer.m_Value.fieldType = FIELD_VOID;
  this->m_OnHearWorld.m_Value.iVal = 0;
  this->m_OnHearWorld.m_Value.eVal.m_Index = -1;
  this->m_OnHearWorld.m_Value.fieldType = FIELD_VOID;
  this->m_OnHearPlayer.m_Value.iVal = 0;
  this->m_OnHearPlayer.m_Value.eVal.m_Index = -1;
  this->m_OnHearPlayer.m_Value.fieldType = FIELD_VOID;
  this->m_OnHearCombat.m_Value.iVal = 0;
  this->m_OnHearCombat.m_Value.eVal.m_Index = -1;
  this->m_OnHearCombat.m_Value.fieldType = FIELD_VOID;
  this->m_OnDamagedByPlayer.m_Value.iVal = 0;
  this->m_OnDamagedByPlayer.m_Value.eVal.m_Index = -1;
  this->m_OnDamagedByPlayer.m_Value.fieldType = FIELD_VOID;
  this->m_OnDamagedByPlayerSquad.m_Value.iVal = 0;
  this->m_OnDamagedByPlayerSquad.m_Value.eVal.m_Index = -1;
  this->m_OnDamagedByPlayerSquad.m_Value.fieldType = FIELD_VOID;
  this->m_OnDenyCommanderUse.m_Value.iVal = 0;
  this->m_OnDenyCommanderUse.m_Value.eVal.m_Index = -1;
  this->m_OnDenyCommanderUse.m_Value.fieldType = FIELD_VOID;
  this->m_OnRappelTouchdown.m_Value.iVal = 0;
  this->m_OnRappelTouchdown.m_Value.eVal.m_Index = -1;
  this->m_OnRappelTouchdown.m_Value.fieldType = FIELD_VOID;
  this->m_OnSleep.m_Value.iVal = 0;
  this->m_OnSleep.m_Value.eVal.m_Index = -1;
  this->m_OnSleep.m_Value.fieldType = FIELD_VOID;
  this->m_OnWake.m_Value.iVal = 0;
  this->m_OnWake.m_Value.eVal.m_Index = -1;
  this->m_OnWake.m_Value.fieldType = FIELD_VOID;
  this->m_OnForcedInteractionStarted.m_Value.iVal = 0;
  this->m_OnForcedInteractionStarted.m_Value.eVal.m_Index = -1;
  this->m_OnForcedInteractionStarted.m_Value.fieldType = FIELD_VOID;
  this->m_OnForcedInteractionAborted.m_Value.iVal = 0;
  this->m_OnForcedInteractionAborted.m_Value.eVal.m_Index = -1;
  this->m_OnForcedInteractionAborted.m_Value.fieldType = FIELD_VOID;
  this->m_OnForcedInteractionFinished.m_Value.iVal = 0;
  this->m_OnForcedInteractionFinished.m_Value.eVal.m_Index = -1;
  this->m_OnForcedInteractionFinished.m_Value.fieldType = FIELD_VOID;
  this->m_bDeferredNavigation = false;
  this->m_pMotor = nullptr;
  this->m_pMoveProbe = nullptr;
  this->m_pNavigator = nullptr;
  this->m_pSenses = nullptr;
  this->m_pPathfinder = nullptr;
  this->m_pLocalNavigator = nullptr;
  this->m_pSchedule = nullptr;
  this->m_IdealSchedule = 0;
  this->m_bDidDeathCleanup = false;
  this->m_afCapability = 0;
  this->m_eHull = HULL_HUMAN;
  this->m_nAITraceMask = 33701899;
  this->m_iMySquadSlot = -1;
  this->m_flSumDamage = 0.0;
  this->m_flLastDamageTime = 0.0;
  this->m_flLastAttackTime = 0.0;
  this->m_flSoundWaitTime = 0.0;
  this->m_flNextEyeLookTime = 0.0;
  this->m_flHeadYaw = 0.0;
  this->m_flHeadPitch = 0.0;
  this->m_spawnEquipment.pszValue = nullptr;
  v3 = (CAI_Enemies *)operator new(nSize: 0x3Cu);
  if ( v3 != nullptr )
    v4 = CAI_Enemies::CAI_Enemies(this: v3);
  else
    v4 = nullptr;
  this->m_flEyeIntegRate = 0.94999999;
  this->m_flFaceEnemyTolerance = 0.0060000001;
  this->m_pEnemies = v4;
  this->m_bIgnoreUnseenEnemies = false;
  this->m_hTargetEnt.m_Index = -1;
  this->m_pSquad = nullptr;
  this->m_flMoveWaitFinished = 0.0;
  this->m_fIsUsingSmallHull = true;
  this->m_bHintGroupNavLimiting = false;
  this->m_fNoDamageDecal = false;
  this->m_bInAScript = false;
  v5 = (CSound *)operator new(nSize: 0x34u);
  if ( v5 != nullptr )
  {
    v5->m_hOwner.m_Index = -1;
    v5->m_hTarget.m_Index = -1;
  }
  else
  {
    v5 = nullptr;
  }
  this->m_pLockedBestSound = v5;
  v5->m_iType = 0;
  this->m_interruptText = nullptr;
  this->m_failText = nullptr;
  this->m_failedSchedule = nullptr;
  this->m_interuptSchedule = nullptr;
  m_Size = g_AI_Manager.m_AIs.m_Size;
  CAI_BaseNPC::m_nDebugPauseIndex = 0;
  v11 = g_AI_Manager.m_AIs.m_Size;
  if ( g_AI_Manager.m_AIs.m_Size + 1 > g_AI_Manager.m_AIs.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_AI_Manager,
      num: g_AI_Manager.m_AIs.m_Size - g_AI_Manager.m_AIs.m_Memory.m_nAllocationCount + 1);
    m_Size = g_AI_Manager.m_AIs.m_Size;
  }
  v7 = m_Size + 1;
  g_AI_Manager.m_AIs.m_pElements = g_AI_Manager.m_AIs.m_Memory.m_pMemory;
  v8 = v7 - v11 - 1;
  g_AI_Manager.m_AIs.m_Size = v7;
  if ( v8 > 0 )
  {
    _V_memmove(
      dest: &g_AI_Manager.m_AIs.m_Memory.m_pMemory[v11 + 1],
      src: &g_AI_Manager.m_AIs.m_Memory.m_pMemory[v11],
      count: 4 * v8);
    v7 = g_AI_Manager.m_AIs.m_Size;
  }
  v9 = &g_AI_Manager.m_AIs.m_Memory.m_pMemory[v11];
  if ( v9 != nullptr )
  {
    *v9 = this;
    v7 = g_AI_Manager.m_AIs.m_Size;
  }
  if ( v7 == 1 )
  {
    LODWORD(CAI_BaseNPC::m_AnyUpdateEnemyPosTimer.m_next) = (CSimpleSimTimer)-1082130432;
    CAI_BaseNPC::gm_flTimeLastSpawn = -1.0;
    CAI_BaseNPC::gm_nSpawnedThisFrame = 0;
    CAI_BaseNPC::gm_iNextThinkRebalanceTick = 0;
  }
  this->m_iFrameBlocked = -1;
  this->m_bInChoreo = true;
  this->m_pScheduleEvent = nullptr;
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 9);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100379B0
// Name: public: virtual class CAI_Senses __near * CAI_BaseNPC::CreateSenses(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Senses *__thiscall CAI_BaseNPC::CreateSenses(CAI_BaseNPC *this)
{
  unsigned __int8 *v2; // esi
  CAI_Senses *v3; // esi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 112);
  memset(dst: v2, value: 0, count: 0x70u);
  if ( v2 != nullptr )
  {
    v3 = CAI_Senses::CAI_Senses(this: (CAI_Senses *)v2);
    v3->SetOuter(this: v3, a2: this);
    return v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, CAI_BaseNPC *))(MEMORY[0] + 4))(a1: 0, a2: this);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037A00
// Name: protected: void CAI_BaseNPC::AddScriptedNPCInteraction(struct ScriptedNPCInteraction_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::AddScriptedNPCInteraction(CAI_BaseNPC *this, ScriptedNPCInteraction_t *pInteraction)
{
  CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int> > *p_m_ScriptedInteractions; // ebx
  const char *pszValue; // eax
  const char *v5; // edi
  const char *DebugName; // eax
  const char *v7; // [esp-4h] [ebp-14h]
  int nNewIndex; // [esp+Ch] [ebp-4h]

  p_m_ScriptedInteractions = &this->m_ScriptedInteractions;
  nNewIndex = CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>::InsertBefore(
                this: &this->m_ScriptedInteractions,
                elem: this->m_ScriptedInteractions.m_Size);
  if ( ai_debug_dyninteractions.m_pParent != nullptr && ai_debug_dyninteractions.m_pParent->m_Value.m_nValue != 0 )
  {
    pszValue = pInteraction->iszInteractionName.pszValue;
    if ( pInteraction->iszInteractionName.pszValue == nullptr )
      pszValue = locale;
    v5 = this->m_iClassname.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    v7 = pszValue;
    DebugName = CBaseEntity::GetDebugName(this);
    _Msg(a1: "%s(%s): Added dynamic interaction: %s\n", v5, DebugName, v7);
  }
  qmemcpy(
    &p_m_ScriptedInteractions->m_Memory.m_pMemory[nNewIndex],
    pInteraction,
    sizeof(p_m_ScriptedInteractions->m_Memory.m_pMemory[nNewIndex]));
  VMatrix::SetupMatrixOrgAngles(
    this: &p_m_ScriptedInteractions->m_Memory.m_pMemory[nNewIndex].matDesiredLocalToWorld,
    origin: &pInteraction->vecRelativeOrigin,
    vAngles: &pInteraction->angRelativeAngles);
}

//------------------------------------------------------------------------------
// Address: 0x10037AA0
// Name: protected: virtual bool CAI_BaseNPC::IsCrouchedActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::IsCrouchedActivity(CAI_BaseNPC *this, Activity activity)
{
  Activity v2; // eax

  v2 = CAI_BaseNPC::TranslateActivity(this, idealActivity: activity, pIdealWeaponActivity: nullptr);
  if ( v2 > ACT_COVER_SMG1_LOW )
    return v2 == ACT_RELOAD_SMG1_LOW;
  if ( v2 >= ACT_COVER_PISTOL_LOW || v2 == ACT_COVER_LOW )
    return 1;
  return v2 == ACT_RELOAD_LOW;
}

//------------------------------------------------------------------------------
// Address: 0x10037CC0
// Name: protected: virtual void CAI_BaseNPC::PostRunStopMoving(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::PostRunStopMoving(CAI_BaseNPC *this)
{
  const char *DebugName; // eax
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> *v4; // eax
  Activity ArrivalActivity; // eax
  CFmtStrN<256> v6; // [esp+4h] [ebp-218h] BYREF
  CFmtStrN<256> v7; // [esp+110h] [ebp-10Ch] BYREF

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    v3 = CFmtStrN<256>::CFmtStrN<256>(
           this: &v7,
           pszFormat: "NPC %s failed to stop properly, slamming activity\n",
           DebugName);
    v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v6, pszFormat: "[Nav] %s", v3->m_szBuf);
    DevMsg(pAI: this, pszFormat: v4->m_szBuf);
  }
  if ( !CAI_Navigator::SetGoalFromStoppingPath(this: this->m_pNavigator) )
  {
    if ( !CAI_Navigator::IsGoalActive(this: this->m_pNavigator)
      || (ArrivalActivity = CAI_Navigator::GetArrivalActivity(this: this->m_pNavigator)) <= ACT_RESET )
    {
      ArrivalActivity = ACT_IDLE;
    }
    CAI_BaseNPC::SetIdealActivity(this, NewActivity: ArrivalActivity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037D60
// Name: protected: void CAI_BaseNPC::ParseScriptedNPCInteractions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ParseScriptedNPCInteractions(CAI_BaseNPC *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  model_t *Model; // eax
  IVModelInfo_vtbl *v5; // esi
  model_t *v6; // eax
  const char *v7; // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  const char *String; // eax
  const char *v11; // eax
  const char *i; // edi
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  const char *v21; // eax
  const char *v22; // edi
  char szTrigger[256]; // [esp+1Ch] [ebp-204h] BYREF
  CUtlBuffer buf; // [esp+11Ch] [ebp-104h] BYREF
  char v25[4]; // [esp+14Ch] [ebp-D4h] BYREF
  char v26[4]; // [esp+150h] [ebp-D0h] BYREF
  char v27[4]; // [esp+154h] [ebp-CCh] BYREF
  char v28[4]; // [esp+158h] [ebp-C8h] BYREF
  char v29[4]; // [esp+15Ch] [ebp-C4h] BYREF
  ScriptedNPCInteraction_t sInteraction; // [esp+160h] [ebp-C0h] BYREF
  char pszValue[4]; // [esp+214h] [ebp-Ch] BYREF
  CBaseEntity *v32; // [esp+218h] [ebp-8h]
  KeyValues *modelKeyValues; // [esp+21Ch] [ebp-4h]

  v32 = this;
  if ( this->m_ScriptedInteractions.m_Size == 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: locale);
      modelKeyValues = v3;
    }
    else
    {
      modelKeyValues = nullptr;
      v3 = nullptr;
    }
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 1024, initSize: 0, nFlags: 1);
    *(IVModelInfo *)pszValue = (IVModelInfo)modelinfo->__vftable;
    Model = CBaseEntity::GetModel(this);
    if ( (*(unsigned __int8 (__thiscall **)(IVModelInfo *, model_t *, CUtlBuffer *))(*(_DWORD *)pszValue + 80))(
           a1: modelinfo,
           a2: Model,
           a3: &buf) != 0 )
    {
      v5 = modelinfo->__vftable;
      v6 = CBaseEntity::GetModel(this: v32);
      v7 = v5->GetModelName(this: modelinfo, a2: v6);
      if ( KeyValues::LoadFromBuffer(
             this: v3,
             resourceName: v7,
             &buf,
             pFileSystem: nullptr,
             pPathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        Key = KeyValues::FindKey(this: v3, keyName: "dynamic_interactions", bCreate: false);
        if ( Key != nullptr )
        {
          FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
          if ( FirstSubKey != nullptr )
          {
            do
            {
              sInteraction.vecRelativeOrigin = vec3_origin;
              sInteraction.flDelay = 5.0;
              sInteraction.flDistSqr = 36.0;
              memset(&sInteraction, 0, 16);
              sInteraction.bValidOnCurrentEnemy = false;
              sInteraction.flNextAttemptTime = 0.0;
              memset(&sInteraction.iszMyWeapon, 0, 12);
              sInteraction.sPhases[0].iActivity = -1;
              sInteraction.sPhases[1].iszSequence.pszValue = nullptr;
              sInteraction.sPhases[1].iActivity = -1;
              sInteraction.sPhases[2].iszSequence.pszValue = nullptr;
              sInteraction.sPhases[2].iActivity = -1;
              KeyValues::GetName(this: FirstSubKey);
              sInteraction.iszInteractionName.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
              String = KeyValues::GetString(this: FirstSubKey, keyName: "trigger", defaultValue: nullptr);
              if ( String != nullptr && V_strncmp(s1: String, s2: "auto_in_combat", count: 14) == 0 )
                sInteraction.iTriggerMethod = 1;
              v11 = KeyValues::GetString(this: FirstSubKey, keyName: "loop_break_trigger", defaultValue: nullptr);
              if ( v11 != nullptr )
              {
                V_strncpy(pDest: szTrigger, pSrc: v11, maxLen: 256);
                for ( i = strtok(string: szTrigger, control: " "); i != nullptr; i = strtok(
                                                                                       string: nullptr,
                                                                                       control: " ") )
                {
                  if ( V_strncmp(s1: i, s2: "on_damage", count: 9) == 0 )
                    sInteraction.iLoopBreakTriggerMethod |= 2u;
                  if ( V_strncmp(s1: i, s2: "on_flashlight_illum", count: 19) == 0 )
                    sInteraction.iLoopBreakTriggerMethod |= 4u;
                }
              }
              v13 = KeyValues::GetString(this: FirstSubKey, keyName: "origin_relative", defaultValue: "0 0 0");
              UTIL_StringToVector(pVector: &sInteraction.vecRelativeOrigin.x, pString: v13);
              v14 = KeyValues::GetString(this: FirstSubKey, keyName: "angles_relative", defaultValue: nullptr);
              if ( v14 != nullptr )
              {
                sInteraction.iFlags |= 2u;
                UTIL_StringToVector(pVector: &sInteraction.angRelativeAngles.x, pString: v14);
              }
              v15 = KeyValues::GetString(this: FirstSubKey, keyName: "velocity_relative", defaultValue: nullptr);
              if ( v15 != nullptr )
              {
                sInteraction.iFlags |= 4u;
                UTIL_StringToVector(pVector: &sInteraction.vecRelativeVelocity.x, pString: v15);
              }
              if ( KeyValues::GetString(this: FirstSubKey, keyName: "entry_sequence", defaultValue: nullptr) != nullptr )
                sInteraction.sPhases[0].iszSequence.pszValue = *(const char **)AllocPooledString(pszValue: v27).pszValue;
              v16 = KeyValues::GetString(this: FirstSubKey, keyName: "entry_activity", defaultValue: nullptr);
              if ( v16 != nullptr )
                sInteraction.sPhases[0].iActivity = CAI_BaseNPC::GetActivityID(actName: v16);
              if ( KeyValues::GetString(this: FirstSubKey, keyName: "sequence", defaultValue: nullptr) != nullptr )
                sInteraction.sPhases[1].iszSequence.pszValue = *(const char **)AllocPooledString(pszValue: v26).pszValue;
              v17 = KeyValues::GetString(this: FirstSubKey, keyName: "activity", defaultValue: nullptr);
              if ( v17 != nullptr )
                sInteraction.sPhases[1].iActivity = CAI_BaseNPC::GetActivityID(actName: v17);
              if ( KeyValues::GetString(this: FirstSubKey, keyName: "exit_sequence", defaultValue: nullptr) != nullptr )
                sInteraction.sPhases[2].iszSequence.pszValue = *(const char **)AllocPooledString(pszValue: v29).pszValue;
              v18 = KeyValues::GetString(this: FirstSubKey, keyName: "exit_activity", defaultValue: nullptr);
              if ( v18 != nullptr )
                sInteraction.sPhases[2].iActivity = CAI_BaseNPC::GetActivityID(actName: v18);
              sInteraction.flDelay = KeyValues::GetFloat(this: FirstSubKey, keyName: "delay", defaultValue: 10.0);
              sInteraction.flDistSqr = KeyValues::GetFloat(
                                         this: FirstSubKey,
                                         keyName: "origin_max_delta",
                                         defaultValue: 36.0);
              if ( KeyValues::GetFloat(this: FirstSubKey, keyName: "loop_in_action", defaultValue: 0.0) != 0.0 )
                sInteraction.iFlags |= 8u;
              v19 = KeyValues::GetString(this: FirstSubKey, keyName: "dont_teleport_at_end", defaultValue: nullptr);
              v20 = v19;
              if ( v19 != nullptr )
              {
                if ( _V_stricmp(s1: v19, s2: "me") != 0 && _V_stricmp(s1: v20, s2: "both") != 0 )
                {
                  if ( _V_stricmp(s1: v20, s2: "them") == 0 || _V_stricmp(s1: v20, s2: "both") == 0 )
                    sInteraction.iFlags |= 0x80u;
                }
                else
                {
                  sInteraction.iFlags |= 0x40u;
                }
              }
              v21 = KeyValues::GetString(this: FirstSubKey, keyName: "needs_weapon", defaultValue: nullptr);
              v22 = v21;
              if ( v21 != nullptr )
              {
                if ( V_strncmp(s1: v21, s2: "ME", count: 2) != 0 )
                {
                  if ( V_strncmp(s1: v22, s2: "THEM", count: 4) != 0 )
                  {
                    if ( V_strncmp(s1: v22, s2: "BOTH", count: 4) == 0 )
                      sInteraction.iFlags |= 0x30u;
                  }
                  else
                  {
                    sInteraction.iFlags |= 0x20u;
                  }
                }
                else
                {
                  sInteraction.iFlags |= 0x10u;
                }
              }
              if ( KeyValues::GetString(this: FirstSubKey, keyName: "weapon_mine", defaultValue: nullptr) != nullptr )
              {
                sInteraction.iFlags |= 0x10u;
                sInteraction.iszMyWeapon.pszValue = *(const char **)AllocPooledString(pszValue: v25).pszValue;
              }
              if ( KeyValues::GetString(this: FirstSubKey, keyName: "weapon_theirs", defaultValue: nullptr) != nullptr )
              {
                sInteraction.iFlags |= 0x20u;
                sInteraction.iszTheirWeapon.pszValue = *(const char **)AllocPooledString(pszValue: v28).pszValue;
              }
              CAI_BaseNPC::AddScriptedNPCInteraction(this: (CAI_BaseNPC *)v32, pInteraction: &sInteraction);
              FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
            }
            while ( FirstSubKey != nullptr );
            v3 = modelKeyValues;
          }
        }
      }
    }
    if ( v3 != nullptr )
      KeyValues::deleteThis(this: v3);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100382D0
// Name: public: virtual void CAI_BaseNPC::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::Activate(CAI_BaseNPC *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  void *v5; // eax

  CBaseAnimating::Activate(this);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    CAI_BaseNPC::ParseScriptedNPCInteractions(this);
  pszValue = this->m_iszEnemyFilterName.pszValue;
  if ( pszValue != nullptr )
  {
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
      v5 = __RTDynamicCast(
             inptr: EntityByName,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CBaseFilter `RTTI Type Descriptor',
             isReference: 0);
      if ( v5 != nullptr )
        this->m_hEnemyFilter.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v5 + 8))(a1: v5);
      else
        this->m_hEnemyFilter.m_Index = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E8A0
// Name: public: virtual void CAI_BaseNPC::OnSetSchedule(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnSetSchedule(vgui::Panel *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100A8660
// Name: public: virtual class Vector CAI_BaseNPC::EyeDirection2D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::EyeDirection2D(CAI_BaseNPC *this, Vector *result)
{
  this->HeadDirection2D(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8680
// Name: public: virtual class Vector CAI_BaseNPC::EyeDirection3D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseNPC::EyeDirection3D(CAI_BaseNPC *this, Vector *result)
{
  this->HeadDirection3D(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D7BF0
// Name: public: int CBaseEntity::entindex(void)const
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CBaseEntity::entindex(CBaseEntity *this)
{
  edict_t *result; // eax

  result = this->m_Network.m_pPev;
  if ( result != nullptr )
    return (edict_t *)(result - gpGlobals->pEdicts);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DDA90
// Name: public: virtual bool CAI_BaseNPC::CreateBehaviors(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::CreateBehaviors(vgui::Panel *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014FAC0
// Name: public: virtual bool IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(vgui::ToggleButton *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10175EF0
// Name: public: virtual class CAI_BaseNPC __near * CAI_BaseNPC::CreateCustomTarget(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC *__thiscall CAI_BaseNPC::CreateCustomTarget(CAI_BaseNPC *this, const Vector *vecOrigin, float duration)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101B4EE0
// Name: public: virtual void CAI_BaseNPC::OnChangeRunningBehavior(class CAI_BehaviorBase __near *,class CAI_BehaviorBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::OnChangeRunningBehavior(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x103FB1B0
// Name: CAI_BaseNPC_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_BaseNPC_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_BaseNPC>(__formal: nullptr);
  CAI_BaseNPC_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB1C0
// Name: AIScheduleState_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AIScheduleState_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AIScheduleState_t>(__formal: nullptr);
  AIScheduleState_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB1F0
// Name: DT_AI_BaseNPC::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_AI_BaseNPC::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_AI_BaseNPC::g_SendTable);
  return atexit(func: DT_AI_BaseNPC::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB210
// Name: DT_AI_BaseNPC::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_AI_BaseNPC::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_AI_BaseNPC::ignored>(__formal: nullptr);
  DT_AI_BaseNPC::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB220
// Name: UnreachableEnt_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *UnreachableEnt_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<UnreachableEnt_t>(__formal: nullptr);
  UnreachableEnt_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB230
// Name: ScriptedNPCInteraction_Phases_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *ScriptedNPCInteraction_Phases_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ScriptedNPCInteraction_Phases_t>(__formal: nullptr);
  ScriptedNPCInteraction_Phases_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB240
// Name: ScriptedNPCInteraction_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *ScriptedNPCInteraction_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ScriptedNPCInteraction_t>(__formal: nullptr);
  ScriptedNPCInteraction_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB250
// Name: AIExtendedSaveHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AIExtendedSaveHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AIExtendedSaveHeader_t>(__formal: nullptr);
  AIExtendedSaveHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10418B70
// Name: DT_AI_BaseNPC::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_AI_BaseNPC::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_AI_BaseNPC::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10032B30
// Name: struct datamap_t __near * DataMapInit<class CAI_BaseNPC>(class CAI_BaseNPC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_BaseNPC>()
{
  if ( (_S6 & 1) == 0 )
  {
    _S6 |= 1u;
    nameHolder_5.m_pszBase = "CAI_BaseNPC";
    nameHolder_5.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_5.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_5.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_5.m_Names.m_Size = 0;
    nameHolder_5.m_Names.m_pElements = nullptr;
    nameHolder_5.m_nLenBase = 11;
    atexit(func: DataMapInit_CAI_BaseNPC__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_BaseNPC::m_DataMap.baseMap = &CBaseCombatCharacter::m_DataMap;
  if ( (_S6 & 2) == 0 )
  {
    _S6 |= 2u;
    dataDesc_5[22].pSaveRestoreOps = ActivityDataOps();
    dataDesc_5[22].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_5[22].td = 0;
    *(_QWORD *)&dataDesc_5[22].override_field = 0;
    *(_QWORD *)&dataDesc_5[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[22].flatOffset[1] = 0;
    dataDesc_5[23].fieldType = FIELD_CUSTOM;
    dataDesc_5[23].fieldName = "m_translatedActivity";
    dataDesc_5[23].fieldOffset = 2568;
    *(_DWORD *)&dataDesc_5[23].fieldSize = 131073;
    dataDesc_5[23].externalName = nullptr;
    dataDesc_5[23].pSaveRestoreOps = ActivityDataOps();
    dataDesc_5[23].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_5[23].td = 0;
    *(_QWORD *)&dataDesc_5[23].override_field = 0;
    *(_QWORD *)&dataDesc_5[23].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[23].flatOffset[1] = 0;
    dataDesc_5[24].fieldType = FIELD_CUSTOM;
    dataDesc_5[24].fieldName = "m_IdealActivity";
    dataDesc_5[24].fieldOffset = 2572;
    *(_DWORD *)&dataDesc_5[24].fieldSize = 131073;
    dataDesc_5[24].externalName = nullptr;
    dataDesc_5[24].pSaveRestoreOps = ActivityDataOps();
    dataDesc_5[24].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_5[24].td = 0;
    *(_QWORD *)&dataDesc_5[24].override_field = 0;
    *(_QWORD *)&dataDesc_5[24].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[24].flatOffset[1] = 0;
    dataDesc_5[25].fieldType = FIELD_CUSTOM;
    dataDesc_5[25].fieldName = "m_IdealTranslatedActivity";
    dataDesc_5[25].fieldOffset = 2580;
    *(_DWORD *)&dataDesc_5[25].fieldSize = 131073;
    dataDesc_5[25].externalName = nullptr;
    dataDesc_5[25].pSaveRestoreOps = ActivityDataOps();
    dataDesc_5[25].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_5[25].td = 0;
    *(_QWORD *)&dataDesc_5[25].override_field = 0;
    *(_QWORD *)&dataDesc_5[25].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[25].flatOffset[1] = 0;
    dataDesc_5[26].fieldType = FIELD_CUSTOM;
    dataDesc_5[26].fieldName = "m_IdealWeaponActivity";
    dataDesc_5[26].fieldOffset = 2584;
    *(_DWORD *)&dataDesc_5[26].fieldSize = 131073;
    dataDesc_5[26].externalName = nullptr;
    dataDesc_5[26].pSaveRestoreOps = ActivityDataOps();
    *(_QWORD *)&dataDesc_5[26].td = 0;
    *(_QWORD *)&dataDesc_5[26].override_field = 0;
    *(_QWORD *)&dataDesc_5[26].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[26].flatOffset[1] = 0;
    dataDesc_5[26].inputFunc = nullptr;
    dataDesc_5[27].fieldType = FIELD_INTEGER;
    dataDesc_5[27].fieldName = "m_nIdealSequence";
    dataDesc_5[27].fieldOffset = 2576;
    *(_DWORD *)&dataDesc_5[27].fieldSize = 131073;
    dataDesc_5[27].externalName = nullptr;
    dataDesc_5[27].pSaveRestoreOps = nullptr;
    dataDesc_5[27].inputFunc = nullptr;
    dataDesc_5[27].td = nullptr;
    dataDesc_5[27].fieldSizeInBytes = 4;
    dataDesc_5[27].override_field = nullptr;
    dataDesc_5[27].override_count = 0;
    dataDesc_5[27].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[27].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[27].flatGroup = 0;
    dataDesc_5[28].fieldType = FIELD_EMBEDDED;
    dataDesc_5[28].fieldSize = 1;
    dataDesc_5[28].flags = 66;
    dataDesc_5[29].fieldSize = 1;
    dataDesc_5[29].flags = 66;
    dataDesc_5[30].fieldSize = 1;
    dataDesc_5[30].flags = 2;
    dataDesc_5[31].fieldSize = 1;
    *(_QWORD *)dataDesc_5[28].flatOffset = 0;
    dataDesc_5[31].flags = 2;
    *(_QWORD *)dataDesc_5[29].flatOffset = 0;
    dataDesc_5[32].fieldSize = 1;
    *(_QWORD *)dataDesc_5[30].flatOffset = 0;
    dataDesc_5[28].fieldName = "m_pSenses";
    dataDesc_5[28].fieldOffset = 2596;
    dataDesc_5[28].externalName = nullptr;
    dataDesc_5[28].pSaveRestoreOps = nullptr;
    dataDesc_5[28].inputFunc = nullptr;
    dataDesc_5[28].td = &CAI_Senses::m_DataMap;
    dataDesc_5[28].fieldSizeInBytes = 112;
    dataDesc_5[28].override_field = nullptr;
    dataDesc_5[28].override_count = 0;
    dataDesc_5[28].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[28].flatGroup = 0;
    dataDesc_5[29].fieldType = FIELD_EMBEDDED;
    dataDesc_5[29].fieldName = "m_pLockedBestSound";
    dataDesc_5[29].fieldOffset = 2600;
    dataDesc_5[29].externalName = nullptr;
    dataDesc_5[29].pSaveRestoreOps = nullptr;
    dataDesc_5[29].inputFunc = nullptr;
    dataDesc_5[29].td = &CSound::m_DataMap;
    dataDesc_5[29].fieldSizeInBytes = 52;
    dataDesc_5[29].override_field = nullptr;
    dataDesc_5[29].override_count = 0;
    dataDesc_5[29].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[29].flatGroup = 0;
    dataDesc_5[30].fieldType = FIELD_EHANDLE;
    dataDesc_5[30].fieldName = "m_hEnemy";
    dataDesc_5[30].fieldOffset = 2604;
    dataDesc_5[30].externalName = nullptr;
    dataDesc_5[30].pSaveRestoreOps = nullptr;
    dataDesc_5[30].inputFunc = nullptr;
    dataDesc_5[30].td = nullptr;
    dataDesc_5[30].fieldSizeInBytes = 4;
    dataDesc_5[30].override_field = nullptr;
    dataDesc_5[30].override_count = 0;
    dataDesc_5[30].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[30].flatGroup = 0;
    dataDesc_5[31].fieldType = FIELD_TIME;
    dataDesc_5[31].fieldName = "m_flTimeEnemyAcquired";
    dataDesc_5[31].fieldOffset = 2608;
    dataDesc_5[31].externalName = nullptr;
    dataDesc_5[31].pSaveRestoreOps = nullptr;
    dataDesc_5[31].inputFunc = nullptr;
    dataDesc_5[31].td = nullptr;
    dataDesc_5[31].fieldSizeInBytes = 4;
    dataDesc_5[31].override_field = nullptr;
    dataDesc_5[31].override_count = 0;
    dataDesc_5[31].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[31].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[31].flatGroup = 0;
    dataDesc_5[32].fieldType = FIELD_EHANDLE;
    dataDesc_5[32].fieldName = "m_hTargetEnt";
    dataDesc_5[32].fieldOffset = 2612;
    dataDesc_5[32].flags = 2;
    dataDesc_5[32].externalName = nullptr;
    dataDesc_5[32].pSaveRestoreOps = nullptr;
    dataDesc_5[33].fieldSize = 1;
    dataDesc_5[33].flags = 2;
    dataDesc_5[34].fieldSize = 1;
    dataDesc_5[34].flags = 2;
    *(_QWORD *)dataDesc_5[32].flatOffset = 0;
    dataDesc_5[35].fieldSize = 1;
    *(_QWORD *)dataDesc_5[33].flatOffset = 0;
    dataDesc_5[35].flags = 2;
    *(_QWORD *)dataDesc_5[34].flatOffset = 0;
    dataDesc_5[36].fieldSize = 1;
    *(_QWORD *)dataDesc_5[35].flatOffset = 0;
    dataDesc_5[32].inputFunc = nullptr;
    dataDesc_5[32].td = nullptr;
    dataDesc_5[32].fieldSizeInBytes = 4;
    dataDesc_5[32].override_field = nullptr;
    dataDesc_5[32].override_count = 0;
    dataDesc_5[32].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[32].flatGroup = 0;
    dataDesc_5[33].fieldType = FIELD_EMBEDDED;
    dataDesc_5[33].fieldName = "m_GiveUpOnDeadEnemyTimer";
    dataDesc_5[33].fieldOffset = 2616;
    dataDesc_5[33].externalName = nullptr;
    dataDesc_5[33].pSaveRestoreOps = nullptr;
    dataDesc_5[33].inputFunc = nullptr;
    dataDesc_5[33].td = &CRandStopwatch::m_DataMap;
    dataDesc_5[33].fieldSizeInBytes = 16;
    dataDesc_5[33].override_field = nullptr;
    dataDesc_5[33].override_count = 0;
    dataDesc_5[33].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[33].flatGroup = 0;
    dataDesc_5[34].fieldType = FIELD_EMBEDDED;
    dataDesc_5[34].fieldName = "m_FailChooseEnemyTimer";
    dataDesc_5[34].fieldOffset = 2632;
    dataDesc_5[34].externalName = nullptr;
    dataDesc_5[34].pSaveRestoreOps = nullptr;
    dataDesc_5[34].inputFunc = nullptr;
    dataDesc_5[34].td = &CSimpleSimTimer::m_DataMap;
    dataDesc_5[34].fieldSizeInBytes = 4;
    dataDesc_5[34].override_field = nullptr;
    dataDesc_5[34].override_count = 0;
    dataDesc_5[34].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[34].flatGroup = 0;
    dataDesc_5[35].fieldType = FIELD_INTEGER;
    dataDesc_5[35].fieldName = "m_EnemiesSerialNumber";
    dataDesc_5[35].fieldOffset = 2636;
    dataDesc_5[35].externalName = nullptr;
    dataDesc_5[35].pSaveRestoreOps = nullptr;
    dataDesc_5[35].inputFunc = nullptr;
    dataDesc_5[35].td = nullptr;
    dataDesc_5[35].fieldSizeInBytes = 4;
    dataDesc_5[35].override_field = nullptr;
    dataDesc_5[35].override_count = 0;
    dataDesc_5[35].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[35].flatGroup = 0;
    dataDesc_5[36].fieldType = FIELD_TIME;
    dataDesc_5[36].fieldName = "m_flAcceptableTimeSeenEnemy";
    dataDesc_5[36].fieldOffset = 2640;
    dataDesc_5[36].flags = 2;
    dataDesc_5[36].externalName = nullptr;
    dataDesc_5[36].pSaveRestoreOps = nullptr;
    dataDesc_5[36].inputFunc = nullptr;
    dataDesc_5[36].td = nullptr;
    dataDesc_5[36].fieldSizeInBytes = 4;
    dataDesc_5[36].override_field = nullptr;
    dataDesc_5[36].override_count = 0;
    dataDesc_5[36].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[36].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[36].flatGroup = 0;
    dataDesc_5[37].fieldSize = 1;
    dataDesc_5[37].flags = 2;
    dataDesc_5[38].fieldSize = 1;
    dataDesc_5[38].flags = 2;
    dataDesc_5[39].fieldSize = 1;
    dataDesc_5[39].flags = 2;
    dataDesc_5[39].fieldSizeInBytes = 16;
    dataDesc_5[40].fieldType = FIELD_TIME;
    dataDesc_5[40].fieldSize = 1;
    *(_QWORD *)dataDesc_5[37].flatOffset = 0;
    dataDesc_5[40].flags = 2;
    *(_QWORD *)dataDesc_5[38].flatOffset = 0;
    dataDesc_5[41].fieldSize = 1;
    *(_QWORD *)dataDesc_5[39].flatOffset = 0;
    dataDesc_5[37].fieldType = FIELD_EMBEDDED;
    dataDesc_5[37].fieldName = "m_UpdateEnemyPosTimer";
    dataDesc_5[37].fieldOffset = 2644;
    dataDesc_5[37].externalName = nullptr;
    dataDesc_5[37].pSaveRestoreOps = nullptr;
    dataDesc_5[37].inputFunc = nullptr;
    dataDesc_5[37].td = &CSimpleSimTimer::m_DataMap;
    dataDesc_5[37].fieldSizeInBytes = 4;
    dataDesc_5[37].override_field = nullptr;
    dataDesc_5[37].override_count = 0;
    dataDesc_5[37].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[37].flatGroup = 0;
    dataDesc_5[38].fieldType = FIELD_VECTOR;
    dataDesc_5[38].fieldName = "m_vecCommandGoal";
    dataDesc_5[38].fieldOffset = 2648;
    dataDesc_5[38].externalName = nullptr;
    dataDesc_5[38].pSaveRestoreOps = nullptr;
    dataDesc_5[38].inputFunc = nullptr;
    dataDesc_5[38].td = nullptr;
    dataDesc_5[38].fieldSizeInBytes = 12;
    dataDesc_5[38].override_field = nullptr;
    dataDesc_5[38].override_count = 0;
    dataDesc_5[38].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[38].flatGroup = 0;
    dataDesc_5[39].fieldType = FIELD_EMBEDDED;
    dataDesc_5[39].fieldName = "m_CommandMoveMonitor";
    dataDesc_5[39].fieldOffset = 2660;
    dataDesc_5[39].externalName = nullptr;
    dataDesc_5[39].pSaveRestoreOps = nullptr;
    dataDesc_5[39].inputFunc = nullptr;
    dataDesc_5[39].td = &CAI_MoveMonitor::m_DataMap;
    dataDesc_5[39].override_field = nullptr;
    dataDesc_5[39].override_count = 0;
    dataDesc_5[39].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[39].flatGroup = 0;
    dataDesc_5[40].fieldName = "m_flSoundWaitTime";
    dataDesc_5[40].fieldOffset = 3672;
    dataDesc_5[40].externalName = nullptr;
    dataDesc_5[40].pSaveRestoreOps = nullptr;
    dataDesc_5[40].inputFunc = nullptr;
    dataDesc_5[40].td = nullptr;
    dataDesc_5[40].fieldSizeInBytes = 4;
    dataDesc_5[40].override_field = nullptr;
    dataDesc_5[40].override_count = 0;
    dataDesc_5[40].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[40].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[40].flatGroup = 0;
    dataDesc_5[41].fieldType = FIELD_INTEGER;
    dataDesc_5[41].fieldName = "m_nSoundPriority";
    dataDesc_5[41].fieldOffset = 3676;
    dataDesc_5[41].flags = 2;
    dataDesc_5[41].externalName = nullptr;
    dataDesc_5[42].fieldSize = 1;
    dataDesc_5[42].flags = 2;
    dataDesc_5[43].fieldSize = 1;
    dataDesc_5[43].flags = 2;
    *(_QWORD *)dataDesc_5[41].flatOffset = 0;
    dataDesc_5[44].fieldSize = 1;
    *(_QWORD *)dataDesc_5[42].flatOffset = 0;
    dataDesc_5[44].flags = 2;
    *(_QWORD *)dataDesc_5[43].flatOffset = 0;
    dataDesc_5[45].fieldSize = 1;
    *(_QWORD *)dataDesc_5[44].flatOffset = 0;
    dataDesc_5[41].pSaveRestoreOps = nullptr;
    dataDesc_5[41].inputFunc = nullptr;
    dataDesc_5[41].td = nullptr;
    dataDesc_5[41].fieldSizeInBytes = 4;
    dataDesc_5[41].override_field = nullptr;
    dataDesc_5[41].override_count = 0;
    dataDesc_5[41].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[41].flatGroup = 0;
    dataDesc_5[42].fieldType = FIELD_TIME;
    dataDesc_5[42].fieldName = "m_flIgnoreDangerSoundsUntil";
    dataDesc_5[42].fieldOffset = 3680;
    dataDesc_5[42].externalName = nullptr;
    dataDesc_5[42].pSaveRestoreOps = nullptr;
    dataDesc_5[42].inputFunc = nullptr;
    dataDesc_5[42].td = nullptr;
    dataDesc_5[42].fieldSizeInBytes = 4;
    dataDesc_5[42].override_field = nullptr;
    dataDesc_5[42].override_count = 0;
    dataDesc_5[42].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[42].flatGroup = 0;
    dataDesc_5[43].fieldType = FIELD_INTEGER;
    dataDesc_5[43].fieldName = "m_afCapability";
    dataDesc_5[43].fieldOffset = 2740;
    dataDesc_5[43].externalName = nullptr;
    dataDesc_5[43].pSaveRestoreOps = nullptr;
    dataDesc_5[43].inputFunc = nullptr;
    dataDesc_5[43].td = nullptr;
    dataDesc_5[43].fieldSizeInBytes = 4;
    dataDesc_5[43].override_field = nullptr;
    dataDesc_5[43].override_count = 0;
    dataDesc_5[43].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[43].flatGroup = 0;
    dataDesc_5[44].fieldType = FIELD_TIME;
    dataDesc_5[44].fieldName = "m_flMoveWaitFinished";
    dataDesc_5[44].fieldOffset = 2744;
    dataDesc_5[44].externalName = nullptr;
    dataDesc_5[44].pSaveRestoreOps = nullptr;
    dataDesc_5[44].inputFunc = nullptr;
    dataDesc_5[44].td = nullptr;
    dataDesc_5[44].fieldSizeInBytes = 4;
    dataDesc_5[44].override_field = nullptr;
    dataDesc_5[44].override_count = 0;
    dataDesc_5[44].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[44].flatGroup = 0;
    dataDesc_5[45].fieldType = FIELD_EHANDLE;
    dataDesc_5[45].fieldName = "m_hOpeningDoor";
    dataDesc_5[45].fieldOffset = 2748;
    dataDesc_5[45].flags = 2;
    dataDesc_5[45].externalName = nullptr;
    dataDesc_5[45].pSaveRestoreOps = nullptr;
    dataDesc_5[45].inputFunc = nullptr;
    dataDesc_5[45].td = nullptr;
    dataDesc_5[45].fieldSizeInBytes = 4;
    dataDesc_5[45].override_field = nullptr;
    dataDesc_5[45].override_count = 0;
    dataDesc_5[45].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[45].flatOffset = 0;
    dataDesc_5[46].fieldSize = 1;
    dataDesc_5[46].flags = 66;
    dataDesc_5[47].fieldSize = 1;
    dataDesc_5[47].flags = 66;
    dataDesc_5[48].fieldSize = 1;
    dataDesc_5[48].flags = 66;
    dataDesc_5[49].fieldSize = 1;
    *(_QWORD *)dataDesc_5[46].flatOffset = 0;
    dataDesc_5[49].flags = 66;
    *(_QWORD *)dataDesc_5[47].flatOffset = 0;
    dataDesc_5[50].fieldSize = 1;
    *(_QWORD *)dataDesc_5[48].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[45].flatGroup = 0;
    dataDesc_5[46].fieldType = FIELD_EMBEDDED;
    dataDesc_5[46].fieldName = "m_pNavigator";
    dataDesc_5[46].fieldOffset = 2772;
    dataDesc_5[46].externalName = nullptr;
    dataDesc_5[46].pSaveRestoreOps = nullptr;
    dataDesc_5[46].inputFunc = nullptr;
    dataDesc_5[46].td = &CAI_Navigator::m_DataMap;
    dataDesc_5[46].fieldSizeInBytes = 156;
    dataDesc_5[46].override_field = nullptr;
    dataDesc_5[46].override_count = 0;
    dataDesc_5[46].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[46].flatGroup = 0;
    dataDesc_5[47].fieldType = FIELD_EMBEDDED;
    dataDesc_5[47].fieldName = "m_pLocalNavigator";
    dataDesc_5[47].fieldOffset = 2776;
    dataDesc_5[47].externalName = nullptr;
    dataDesc_5[47].pSaveRestoreOps = nullptr;
    dataDesc_5[47].inputFunc = nullptr;
    dataDesc_5[47].td = &CAI_LocalNavigator::m_DataMap;
    dataDesc_5[47].fieldSizeInBytes = 212;
    dataDesc_5[47].override_field = nullptr;
    dataDesc_5[47].override_count = 0;
    dataDesc_5[47].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[47].flatGroup = 0;
    dataDesc_5[48].fieldType = FIELD_EMBEDDED;
    dataDesc_5[48].fieldName = "m_pPathfinder";
    dataDesc_5[48].fieldOffset = 2780;
    dataDesc_5[48].externalName = nullptr;
    dataDesc_5[48].pSaveRestoreOps = nullptr;
    dataDesc_5[48].inputFunc = nullptr;
    dataDesc_5[48].td = &CAI_Pathfinder::m_DataMap;
    dataDesc_5[48].fieldSizeInBytes = 24;
    dataDesc_5[48].override_field = nullptr;
    dataDesc_5[48].override_count = 0;
    dataDesc_5[48].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[48].flatGroup = 0;
    dataDesc_5[49].fieldType = FIELD_EMBEDDED;
    dataDesc_5[49].fieldName = "m_pMoveProbe";
    dataDesc_5[49].fieldOffset = 2784;
    dataDesc_5[49].externalName = nullptr;
    dataDesc_5[49].pSaveRestoreOps = nullptr;
    dataDesc_5[49].inputFunc = nullptr;
    dataDesc_5[49].td = &CAI_MoveProbe::m_DataMap;
    dataDesc_5[49].fieldSizeInBytes = 20;
    dataDesc_5[49].override_field = nullptr;
    dataDesc_5[49].override_count = 0;
    dataDesc_5[49].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[49].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[49].flatGroup = 0;
    dataDesc_5[50].fieldType = FIELD_EMBEDDED;
    dataDesc_5[50].fieldName = "m_pMotor";
    dataDesc_5[50].fieldOffset = 2788;
    dataDesc_5[50].flags = 66;
    dataDesc_5[50].externalName = nullptr;
    dataDesc_5[51].fieldSize = 1;
    dataDesc_5[50].pSaveRestoreOps = nullptr;
    dataDesc_5[50].inputFunc = nullptr;
    dataDesc_5[50].td = &CAI_Motor::m_DataMap;
    dataDesc_5[50].fieldSizeInBytes = 96;
    dataDesc_5[50].override_field = nullptr;
    dataDesc_5[50].override_count = 0;
    dataDesc_5[50].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[50].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[50].flatGroup = 0;
    dataDesc_5[51].fieldType = FIELD_CUSTOM;
    dataDesc_5[51].fieldName = "m_UnreachableEnts";
    dataDesc_5[51].fieldOffset = 2752;
    dataDesc_5[51].flags = 2;
    dataDesc_5[51].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int>>,10>::`vftable';
    }
    dataDesc_5[52].fieldSize = 1;
    dataDesc_5[52].flags = 2;
    dataDesc_5[53].fieldSize = 1;
    dataDesc_5[53].flags = 2;
    *(_QWORD *)&dataDesc_5[51].td = 0;
    *(_QWORD *)&dataDesc_5[51].override_field = 0;
    *(_QWORD *)&dataDesc_5[51].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[51].flatOffset[1] = 0;
    dataDesc_5[54].fieldSize = 1;
    *(_QWORD *)dataDesc_5[52].flatOffset = 0;
    dataDesc_5[54].flags = 2;
    *(_QWORD *)dataDesc_5[53].flatOffset = 0;
    dataDesc_5[55].fieldSize = 1;
    *(_QWORD *)dataDesc_5[54].flatOffset = 0;
    dataDesc_5[51].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int>>>'::`2'::ops;
    dataDesc_5[51].inputFunc = nullptr;
    dataDesc_5[52].fieldType = FIELD_EHANDLE;
    dataDesc_5[52].fieldName = "m_hInteractionPartner";
    dataDesc_5[52].fieldOffset = 2696;
    dataDesc_5[52].externalName = nullptr;
    dataDesc_5[52].pSaveRestoreOps = nullptr;
    dataDesc_5[52].inputFunc = nullptr;
    dataDesc_5[52].td = nullptr;
    dataDesc_5[52].fieldSizeInBytes = 4;
    dataDesc_5[52].override_field = nullptr;
    dataDesc_5[52].override_count = 0;
    dataDesc_5[52].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[52].flatGroup = 0;
    dataDesc_5[53].fieldType = FIELD_EHANDLE;
    dataDesc_5[53].fieldName = "m_hLastInteractionTestTarget";
    dataDesc_5[53].fieldOffset = 2700;
    dataDesc_5[53].externalName = nullptr;
    dataDesc_5[53].pSaveRestoreOps = nullptr;
    dataDesc_5[53].inputFunc = nullptr;
    dataDesc_5[53].td = nullptr;
    dataDesc_5[53].fieldSizeInBytes = 4;
    dataDesc_5[53].override_field = nullptr;
    dataDesc_5[53].override_count = 0;
    dataDesc_5[53].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[53].flatGroup = 0;
    dataDesc_5[54].fieldType = FIELD_EHANDLE;
    dataDesc_5[54].fieldName = "m_hForcedInteractionPartner";
    dataDesc_5[54].fieldOffset = 2676;
    dataDesc_5[54].externalName = nullptr;
    dataDesc_5[54].pSaveRestoreOps = nullptr;
    dataDesc_5[54].inputFunc = nullptr;
    dataDesc_5[54].td = nullptr;
    dataDesc_5[54].fieldSizeInBytes = 4;
    dataDesc_5[54].override_field = nullptr;
    dataDesc_5[54].override_count = 0;
    dataDesc_5[54].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[54].flatGroup = 0;
    dataDesc_5[55].fieldType = FIELD_TIME;
    dataDesc_5[55].fieldName = "m_flForcedInteractionTimeout";
    dataDesc_5[55].fieldOffset = 2692;
    dataDesc_5[55].flags = 2;
    dataDesc_5[55].externalName = nullptr;
    dataDesc_5[55].pSaveRestoreOps = nullptr;
    dataDesc_5[55].inputFunc = nullptr;
    dataDesc_5[55].td = nullptr;
    dataDesc_5[55].fieldSizeInBytes = 4;
    dataDesc_5[55].override_field = nullptr;
    dataDesc_5[55].override_count = 0;
    dataDesc_5[55].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[55].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[55].flatGroup = 0;
    dataDesc_5[56].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_5[56].fieldName = "m_vecForcedWorldPosition";
    dataDesc_5[56].fieldSize = 1;
    dataDesc_5[56].flags = 2;
    dataDesc_5[57].fieldSize = 1;
    dataDesc_5[57].flags = 2;
    dataDesc_5[58].fieldSize = 1;
    dataDesc_5[58].flags = 2;
    dataDesc_5[59].fieldSize = 1;
    *(_QWORD *)dataDesc_5[56].flatOffset = 0;
    dataDesc_5[59].flags = 2;
    *(_QWORD *)dataDesc_5[57].flatOffset = 0;
    dataDesc_5[60].fieldSize = 1;
    *(_QWORD *)dataDesc_5[58].flatOffset = 0;
    dataDesc_5[56].fieldOffset = 2680;
    dataDesc_5[56].externalName = nullptr;
    dataDesc_5[56].pSaveRestoreOps = nullptr;
    dataDesc_5[56].inputFunc = nullptr;
    dataDesc_5[56].td = nullptr;
    dataDesc_5[56].fieldSizeInBytes = 12;
    dataDesc_5[56].override_field = nullptr;
    dataDesc_5[56].override_count = 0;
    dataDesc_5[56].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[56].flatGroup = 0;
    dataDesc_5[57].fieldType = FIELD_BOOLEAN;
    dataDesc_5[57].fieldName = "m_bCannotDieDuringInteraction";
    dataDesc_5[57].fieldOffset = 2704;
    dataDesc_5[57].externalName = nullptr;
    dataDesc_5[57].pSaveRestoreOps = nullptr;
    dataDesc_5[57].inputFunc = nullptr;
    dataDesc_5[57].td = nullptr;
    dataDesc_5[57].fieldSizeInBytes = 1;
    dataDesc_5[57].override_field = nullptr;
    dataDesc_5[57].override_count = 0;
    dataDesc_5[57].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[57].flatGroup = 0;
    dataDesc_5[58].fieldType = FIELD_INTEGER;
    dataDesc_5[58].fieldName = "m_iInteractionState";
    dataDesc_5[58].fieldOffset = 2708;
    dataDesc_5[58].externalName = nullptr;
    dataDesc_5[58].pSaveRestoreOps = nullptr;
    dataDesc_5[58].inputFunc = nullptr;
    dataDesc_5[58].td = nullptr;
    dataDesc_5[58].fieldSizeInBytes = 4;
    dataDesc_5[58].override_field = nullptr;
    dataDesc_5[58].override_count = 0;
    dataDesc_5[58].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[58].flatGroup = 0;
    dataDesc_5[59].fieldType = FIELD_INTEGER;
    dataDesc_5[59].fieldName = "m_iInteractionPlaying";
    dataDesc_5[59].fieldOffset = 2712;
    dataDesc_5[59].externalName = nullptr;
    dataDesc_5[59].pSaveRestoreOps = nullptr;
    dataDesc_5[59].inputFunc = nullptr;
    dataDesc_5[59].td = nullptr;
    dataDesc_5[59].fieldSizeInBytes = 4;
    dataDesc_5[59].override_field = nullptr;
    dataDesc_5[59].override_count = 0;
    dataDesc_5[59].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[59].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[59].flatGroup = 0;
    dataDesc_5[60].fieldType = FIELD_CUSTOM;
    dataDesc_5[60].fieldName = "m_ScriptedInteractions";
    dataDesc_5[60].fieldOffset = 2716;
    dataDesc_5[60].flags = 2;
    dataDesc_5[60].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>,10>::`vftable';
    }
    dataDesc_5[61].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[60].td = 0;
    *(_QWORD *)&dataDesc_5[60].override_field = 0;
    *(_QWORD *)&dataDesc_5[60].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[60].flatOffset[1] = 0;
    dataDesc_5[61].flags = 2;
    dataDesc_5[62].flags = 2;
    dataDesc_5[63].flags = 2;
    *(_QWORD *)dataDesc_5[61].flatOffset = 0;
    dataDesc_5[62].fieldType = FIELD_EMBEDDED;
    *(_QWORD *)dataDesc_5[62].flatOffset = 0;
    dataDesc_5[64].fieldSize = 1;
    dataDesc_5[62].fieldSize = 1;
    dataDesc_5[63].fieldSize = 1;
    *(_QWORD *)dataDesc_5[63].flatOffset = 0;
    dataDesc_5[64].flags = 2;
    dataDesc_5[60].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>>'::`2'::ops;
    dataDesc_5[60].inputFunc = nullptr;
    dataDesc_5[61].fieldType = FIELD_FLOAT;
    dataDesc_5[61].fieldName = "m_flInteractionYaw";
    dataDesc_5[61].fieldOffset = 2736;
    dataDesc_5[61].externalName = nullptr;
    dataDesc_5[61].pSaveRestoreOps = nullptr;
    dataDesc_5[61].inputFunc = nullptr;
    dataDesc_5[61].td = nullptr;
    dataDesc_5[61].fieldSizeInBytes = 4;
    dataDesc_5[61].override_field = nullptr;
    dataDesc_5[61].override_count = 0;
    dataDesc_5[61].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[61].flatGroup = 0;
    dataDesc_5[62].fieldName = "m_CheckOnGroundTimer";
    dataDesc_5[62].fieldOffset = 2800;
    dataDesc_5[62].externalName = nullptr;
    dataDesc_5[62].pSaveRestoreOps = nullptr;
    dataDesc_5[62].inputFunc = nullptr;
    dataDesc_5[62].td = &CSimpleSimTimer::m_DataMap;
    dataDesc_5[62].fieldSizeInBytes = 4;
    dataDesc_5[62].override_field = nullptr;
    dataDesc_5[62].override_count = 0;
    dataDesc_5[62].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[62].flatGroup = 0;
    dataDesc_5[63].fieldType = FIELD_VECTOR;
    dataDesc_5[63].fieldName = "m_vDefaultEyeOffset";
    dataDesc_5[63].fieldOffset = 2804;
    dataDesc_5[63].externalName = nullptr;
    dataDesc_5[63].pSaveRestoreOps = nullptr;
    dataDesc_5[63].inputFunc = nullptr;
    dataDesc_5[63].td = nullptr;
    dataDesc_5[63].fieldSizeInBytes = 12;
    dataDesc_5[63].override_field = nullptr;
    dataDesc_5[63].override_count = 0;
    dataDesc_5[63].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[63].flatGroup = 0;
    dataDesc_5[64].fieldType = FIELD_TIME;
    dataDesc_5[64].fieldName = "m_flNextEyeLookTime";
    dataDesc_5[64].fieldOffset = 2816;
    dataDesc_5[64].externalName = nullptr;
    dataDesc_5[64].pSaveRestoreOps = nullptr;
    dataDesc_5[64].inputFunc = nullptr;
    dataDesc_5[64].td = nullptr;
    dataDesc_5[64].fieldSizeInBytes = 4;
    dataDesc_5[64].override_field = nullptr;
    dataDesc_5[64].override_count = 0;
    dataDesc_5[64].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[64].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[64].flatGroup = 0;
    dataDesc_5[65].fieldType = FIELD_FLOAT;
    dataDesc_5[65].fieldName = "m_flEyeIntegRate";
    dataDesc_5[65].fieldOffset = 2820;
    dataDesc_5[65].fieldSize = 1;
    dataDesc_5[65].flags = 2;
    dataDesc_5[66].fieldSize = 1;
    dataDesc_5[66].flags = 2;
    dataDesc_5[67].fieldSize = 1;
    dataDesc_5[67].flags = 2;
    dataDesc_5[68].fieldSize = 1;
    *(_QWORD *)dataDesc_5[65].flatOffset = 0;
    dataDesc_5[68].flags = 2;
    *(_QWORD *)dataDesc_5[66].flatOffset = 0;
    dataDesc_5[66].fieldSizeInBytes = 12;
    dataDesc_5[67].fieldSizeInBytes = 12;
    dataDesc_5[69].fieldSize = 1;
    *(_QWORD *)dataDesc_5[67].flatOffset = 0;
    dataDesc_5[65].externalName = nullptr;
    dataDesc_5[65].pSaveRestoreOps = nullptr;
    dataDesc_5[65].inputFunc = nullptr;
    dataDesc_5[65].td = nullptr;
    dataDesc_5[65].fieldSizeInBytes = 4;
    dataDesc_5[65].override_field = nullptr;
    dataDesc_5[65].override_count = 0;
    dataDesc_5[65].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[65].flatGroup = 0;
    dataDesc_5[66].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_5[66].fieldName = "m_vEyeLookTarget";
    dataDesc_5[66].fieldOffset = 2824;
    dataDesc_5[66].externalName = nullptr;
    dataDesc_5[66].pSaveRestoreOps = nullptr;
    dataDesc_5[66].inputFunc = nullptr;
    dataDesc_5[66].td = nullptr;
    dataDesc_5[66].override_field = nullptr;
    dataDesc_5[66].override_count = 0;
    dataDesc_5[66].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[66].flatGroup = 0;
    dataDesc_5[67].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_5[67].fieldName = "m_vCurEyeTarget";
    dataDesc_5[67].fieldOffset = 2836;
    dataDesc_5[67].externalName = nullptr;
    dataDesc_5[67].pSaveRestoreOps = nullptr;
    dataDesc_5[67].inputFunc = nullptr;
    dataDesc_5[67].td = nullptr;
    dataDesc_5[67].override_field = nullptr;
    dataDesc_5[67].override_count = 0;
    dataDesc_5[67].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[67].flatGroup = 0;
    dataDesc_5[68].fieldType = FIELD_EHANDLE;
    dataDesc_5[68].fieldName = "m_hEyeLookTarget";
    dataDesc_5[68].fieldOffset = 2848;
    dataDesc_5[68].externalName = nullptr;
    dataDesc_5[68].pSaveRestoreOps = nullptr;
    dataDesc_5[68].inputFunc = nullptr;
    dataDesc_5[68].td = nullptr;
    dataDesc_5[68].fieldSizeInBytes = 4;
    dataDesc_5[68].override_field = nullptr;
    dataDesc_5[68].override_count = 0;
    dataDesc_5[68].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[68].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[68].flatGroup = 0;
    dataDesc_5[69].fieldType = FIELD_FLOAT;
    dataDesc_5[69].fieldName = "m_flHeadYaw";
    dataDesc_5[69].fieldOffset = 2852;
    dataDesc_5[69].flags = 2;
    dataDesc_5[69].externalName = nullptr;
    dataDesc_5[69].pSaveRestoreOps = nullptr;
    dataDesc_5[69].inputFunc = nullptr;
    dataDesc_5[69].td = nullptr;
    dataDesc_5[69].fieldSizeInBytes = 4;
    dataDesc_5[70].fieldSize = 1;
    dataDesc_5[70].flags = 2;
    dataDesc_5[71].fieldSize = 1;
    dataDesc_5[71].flags = 2;
    *(_QWORD *)dataDesc_5[69].flatOffset = 0;
    dataDesc_5[72].fieldSize = 1;
    *(_QWORD *)dataDesc_5[70].flatOffset = 0;
    dataDesc_5[72].flags = 2;
    *(_QWORD *)dataDesc_5[71].flatOffset = 0;
    dataDesc_5[73].fieldSize = 1;
    *(_QWORD *)dataDesc_5[72].flatOffset = 0;
    dataDesc_5[69].override_field = nullptr;
    dataDesc_5[69].override_count = 0;
    dataDesc_5[69].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[69].flatGroup = 0;
    dataDesc_5[70].fieldType = FIELD_FLOAT;
    dataDesc_5[70].fieldName = "m_flHeadPitch";
    dataDesc_5[70].fieldOffset = 2856;
    dataDesc_5[70].externalName = nullptr;
    dataDesc_5[70].pSaveRestoreOps = nullptr;
    dataDesc_5[70].inputFunc = nullptr;
    dataDesc_5[70].td = nullptr;
    dataDesc_5[70].fieldSizeInBytes = 4;
    dataDesc_5[70].override_field = nullptr;
    dataDesc_5[70].override_count = 0;
    dataDesc_5[70].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[70].flatGroup = 0;
    dataDesc_5[71].fieldType = FIELD_FLOAT;
    dataDesc_5[71].fieldName = "m_flOriginalYaw";
    dataDesc_5[71].fieldOffset = 2860;
    dataDesc_5[71].externalName = nullptr;
    dataDesc_5[71].pSaveRestoreOps = nullptr;
    dataDesc_5[71].inputFunc = nullptr;
    dataDesc_5[71].td = nullptr;
    dataDesc_5[71].fieldSizeInBytes = 4;
    dataDesc_5[71].override_field = nullptr;
    dataDesc_5[71].override_count = 0;
    dataDesc_5[71].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[71].flatGroup = 0;
    dataDesc_5[72].fieldType = FIELD_BOOLEAN;
    dataDesc_5[72].fieldName = "m_bInAScript";
    dataDesc_5[72].fieldOffset = 2868;
    dataDesc_5[72].externalName = nullptr;
    dataDesc_5[72].pSaveRestoreOps = nullptr;
    dataDesc_5[72].inputFunc = nullptr;
    dataDesc_5[72].td = nullptr;
    dataDesc_5[72].fieldSizeInBytes = 1;
    dataDesc_5[72].override_field = nullptr;
    dataDesc_5[72].override_count = 0;
    dataDesc_5[72].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[72].flatGroup = 0;
    dataDesc_5[73].fieldType = FIELD_INTEGER;
    dataDesc_5[73].fieldName = "m_scriptState";
    dataDesc_5[73].fieldOffset = 2872;
    dataDesc_5[73].flags = 2;
    dataDesc_5[73].externalName = nullptr;
    dataDesc_5[73].pSaveRestoreOps = nullptr;
    dataDesc_5[73].inputFunc = nullptr;
    dataDesc_5[73].td = nullptr;
    dataDesc_5[73].fieldSizeInBytes = 4;
    dataDesc_5[73].override_field = nullptr;
    dataDesc_5[73].override_count = 0;
    dataDesc_5[73].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[73].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[73].flatGroup = 0;
    dataDesc_5[74].fieldType = FIELD_EHANDLE;
    dataDesc_5[74].fieldName = "m_hCine";
    dataDesc_5[74].fieldOffset = 2876;
    dataDesc_5[74].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[74].fieldSize = 131073;
    dataDesc_5[74].externalName = nullptr;
    dataDesc_5[74].pSaveRestoreOps = nullptr;
    dataDesc_5[74].inputFunc = nullptr;
    dataDesc_5[74].td = nullptr;
    dataDesc_5[74].fieldSizeInBytes = 4;
    dataDesc_5[74].override_field = nullptr;
    dataDesc_5[74].override_count = 0;
    *(_QWORD *)dataDesc_5[74].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[74].flatGroup = 0;
    dataDesc_5[75].fieldType = FIELD_CUSTOM;
    dataDesc_5[75].fieldName = "m_ScriptArrivalActivity";
    dataDesc_5[75].fieldOffset = 2880;
    *(_DWORD *)&dataDesc_5[75].fieldSize = 131073;
    dataDesc_5[75].externalName = nullptr;
    dataDesc_5[75].pSaveRestoreOps = ActivityDataOps();
    dataDesc_5[76].fieldSize = 1;
    dataDesc_5[76].flags = 2;
    dataDesc_5[77].fieldSize = 1;
    dataDesc_5[77].flags = 2;
    dataDesc_5[78].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[75].td = 0;
    *(_QWORD *)&dataDesc_5[75].override_field = 0;
    *(_QWORD *)&dataDesc_5[75].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[75].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_5[76].flatOffset = 0;
    dataDesc_5[75].inputFunc = nullptr;
    dataDesc_5[76].fieldType = FIELD_STRING;
    dataDesc_5[76].fieldName = "m_strScriptArrivalSequence";
    dataDesc_5[76].fieldOffset = 2884;
    dataDesc_5[76].externalName = nullptr;
    dataDesc_5[76].pSaveRestoreOps = nullptr;
    dataDesc_5[76].inputFunc = nullptr;
    dataDesc_5[76].td = nullptr;
    dataDesc_5[76].fieldSizeInBytes = 4;
    dataDesc_5[76].override_field = nullptr;
    dataDesc_5[76].override_count = 0;
    dataDesc_5[76].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[76].flatGroup = 0;
    dataDesc_5[77].fieldType = FIELD_TIME;
    dataDesc_5[77].fieldName = "m_flSceneTime";
    dataDesc_5[77].fieldOffset = 2888;
    dataDesc_5[77].externalName = nullptr;
    dataDesc_5[77].pSaveRestoreOps = nullptr;
    dataDesc_5[77].inputFunc = nullptr;
    dataDesc_5[77].td = nullptr;
    dataDesc_5[77].fieldSizeInBytes = 4;
    dataDesc_5[77].override_field = nullptr;
    dataDesc_5[77].override_count = 0;
    dataDesc_5[77].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[77].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[77].flatGroup = 0;
    dataDesc_5[78].fieldType = FIELD_STRING;
    dataDesc_5[78].fieldName = "m_iszSceneCustomMoveSeq";
    dataDesc_5[78].fieldOffset = 2892;
    dataDesc_5[78].flags = 2;
    dataDesc_5[78].externalName = nullptr;
    dataDesc_5[78].pSaveRestoreOps = nullptr;
    dataDesc_5[78].inputFunc = nullptr;
    dataDesc_5[78].td = nullptr;
    dataDesc_5[78].fieldSizeInBytes = 4;
    dataDesc_5[78].override_field = nullptr;
    dataDesc_5[78].override_count = 0;
    dataDesc_5[78].fieldTolerance = 0.0;
    dataDesc_5[79].fieldSize = 1;
    dataDesc_5[79].flags = 2;
    dataDesc_5[80].fieldSize = 1;
    dataDesc_5[80].flags = 2;
    dataDesc_5[81].fieldSize = 1;
    dataDesc_5[81].flags = 2;
    *(_QWORD *)dataDesc_5[78].flatOffset = 0;
    dataDesc_5[82].fieldSize = 1;
    *(_QWORD *)dataDesc_5[79].flatOffset = 0;
    *(_QWORD *)dataDesc_5[80].flatOffset = 0;
    dataDesc_5[82].flags = 2;
    *(_QWORD *)dataDesc_5[81].flatOffset = 0;
    dataDesc_5[83].fieldSize = 1;
    *(_DWORD *)&dataDesc_5[78].flatGroup = 0;
    dataDesc_5[79].fieldType = FIELD_INTEGER;
    dataDesc_5[79].fieldName = "m_afMemory";
    dataDesc_5[79].fieldOffset = 2900;
    dataDesc_5[79].externalName = nullptr;
    dataDesc_5[79].pSaveRestoreOps = nullptr;
    dataDesc_5[79].inputFunc = nullptr;
    dataDesc_5[79].td = nullptr;
    dataDesc_5[79].fieldSizeInBytes = 4;
    dataDesc_5[79].override_field = nullptr;
    dataDesc_5[79].override_count = 0;
    dataDesc_5[79].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[79].flatGroup = 0;
    dataDesc_5[80].fieldType = FIELD_EHANDLE;
    dataDesc_5[80].fieldName = "m_hEnemyOccluder";
    dataDesc_5[80].fieldOffset = 2904;
    dataDesc_5[80].externalName = nullptr;
    dataDesc_5[80].pSaveRestoreOps = nullptr;
    dataDesc_5[80].inputFunc = nullptr;
    dataDesc_5[80].td = nullptr;
    dataDesc_5[80].fieldSizeInBytes = 4;
    dataDesc_5[80].override_field = nullptr;
    dataDesc_5[80].override_count = 0;
    dataDesc_5[80].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[80].flatGroup = 0;
    dataDesc_5[81].fieldType = FIELD_FLOAT;
    dataDesc_5[81].fieldName = "m_flSumDamage";
    dataDesc_5[81].fieldOffset = 2908;
    dataDesc_5[81].externalName = nullptr;
    dataDesc_5[81].pSaveRestoreOps = nullptr;
    dataDesc_5[81].inputFunc = nullptr;
    dataDesc_5[81].td = nullptr;
    dataDesc_5[81].fieldSizeInBytes = 4;
    dataDesc_5[81].override_field = nullptr;
    dataDesc_5[81].override_count = 0;
    dataDesc_5[81].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[81].flatGroup = 0;
    dataDesc_5[82].fieldType = FIELD_TIME;
    dataDesc_5[82].fieldName = "m_flLastDamageTime";
    dataDesc_5[82].fieldOffset = 2912;
    dataDesc_5[82].externalName = nullptr;
    dataDesc_5[82].pSaveRestoreOps = nullptr;
    dataDesc_5[82].inputFunc = nullptr;
    dataDesc_5[82].td = nullptr;
    dataDesc_5[82].fieldSizeInBytes = 4;
    dataDesc_5[82].override_field = nullptr;
    dataDesc_5[82].override_count = 0;
    dataDesc_5[82].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[82].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[82].flatGroup = 0;
    dataDesc_5[83].fieldType = FIELD_TIME;
    dataDesc_5[83].fieldName = "m_flLastPlayerDamageTime";
    dataDesc_5[83].fieldOffset = 2916;
    dataDesc_5[83].flags = 2;
    dataDesc_5[84].fieldSize = 1;
    dataDesc_5[84].flags = 2;
    dataDesc_5[85].fieldSize = 1;
    dataDesc_5[85].flags = 2;
    dataDesc_5[86].fieldSize = 1;
    *(_QWORD *)dataDesc_5[83].flatOffset = 0;
    dataDesc_5[86].flags = 2;
    *(_QWORD *)dataDesc_5[84].flatOffset = 0;
    dataDesc_5[87].fieldSize = 1;
    *(_QWORD *)dataDesc_5[85].flatOffset = 0;
    dataDesc_5[83].externalName = nullptr;
    dataDesc_5[83].pSaveRestoreOps = nullptr;
    dataDesc_5[83].inputFunc = nullptr;
    dataDesc_5[83].td = nullptr;
    dataDesc_5[83].fieldSizeInBytes = 4;
    dataDesc_5[83].override_field = nullptr;
    dataDesc_5[83].override_count = 0;
    dataDesc_5[83].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[83].flatGroup = 0;
    dataDesc_5[84].fieldType = FIELD_TIME;
    dataDesc_5[84].fieldName = "m_flLastSawPlayerTime";
    dataDesc_5[84].fieldOffset = 2920;
    dataDesc_5[84].externalName = nullptr;
    dataDesc_5[84].pSaveRestoreOps = nullptr;
    dataDesc_5[84].inputFunc = nullptr;
    dataDesc_5[84].td = nullptr;
    dataDesc_5[84].fieldSizeInBytes = 4;
    dataDesc_5[84].override_field = nullptr;
    dataDesc_5[84].override_count = 0;
    dataDesc_5[84].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[84].flatGroup = 0;
    dataDesc_5[85].fieldType = FIELD_TIME;
    dataDesc_5[85].fieldName = "m_flLastAttackTime";
    dataDesc_5[85].fieldOffset = 2924;
    dataDesc_5[85].externalName = nullptr;
    dataDesc_5[85].pSaveRestoreOps = nullptr;
    dataDesc_5[85].inputFunc = nullptr;
    dataDesc_5[85].td = nullptr;
    dataDesc_5[85].fieldSizeInBytes = 4;
    dataDesc_5[85].override_field = nullptr;
    dataDesc_5[85].override_count = 0;
    dataDesc_5[85].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[85].flatGroup = 0;
    dataDesc_5[86].fieldType = FIELD_TIME;
    dataDesc_5[86].fieldName = "m_flLastEnemyTime";
    dataDesc_5[86].fieldOffset = 2928;
    dataDesc_5[86].externalName = nullptr;
    dataDesc_5[86].pSaveRestoreOps = nullptr;
    dataDesc_5[86].inputFunc = nullptr;
    dataDesc_5[86].td = nullptr;
    dataDesc_5[86].fieldSizeInBytes = 4;
    dataDesc_5[86].override_field = nullptr;
    dataDesc_5[86].override_count = 0;
    dataDesc_5[86].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[86].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[86].flatGroup = 0;
    dataDesc_5[87].fieldType = FIELD_TIME;
    dataDesc_5[87].fieldName = "m_flNextWeaponSearchTime";
    dataDesc_5[87].fieldOffset = 2932;
    dataDesc_5[87].flags = 2;
    dataDesc_5[87].externalName = nullptr;
    dataDesc_5[87].pSaveRestoreOps = nullptr;
    dataDesc_5[87].inputFunc = nullptr;
    dataDesc_5[87].td = nullptr;
    dataDesc_5[87].fieldSizeInBytes = 4;
    dataDesc_5[87].override_field = nullptr;
    dataDesc_5[87].override_count = 0;
    dataDesc_5[87].fieldTolerance = 0.0;
    dataDesc_5[88].fieldSize = 1;
    dataDesc_5[88].flags = 2;
    dataDesc_5[89].fieldSize = 1;
    dataDesc_5[89].flags = 6;
    dataDesc_5[90].fieldSize = 1;
    dataDesc_5[90].flags = 2;
    *(_QWORD *)dataDesc_5[87].flatOffset = 0;
    dataDesc_5[91].fieldSize = 1;
    *(_QWORD *)dataDesc_5[88].flatOffset = 0;
    *(_QWORD *)dataDesc_5[89].flatOffset = 0;
    dataDesc_5[91].flags = 2;
    *(_QWORD *)dataDesc_5[90].flatOffset = 0;
    dataDesc_5[92].fieldSize = 1;
    *(_DWORD *)&dataDesc_5[87].flatGroup = 0;
    dataDesc_5[88].fieldType = FIELD_STRING;
    dataDesc_5[88].fieldName = "m_iszPendingWeapon";
    dataDesc_5[88].fieldOffset = 2936;
    dataDesc_5[88].externalName = nullptr;
    dataDesc_5[88].pSaveRestoreOps = nullptr;
    dataDesc_5[88].inputFunc = nullptr;
    dataDesc_5[88].td = nullptr;
    dataDesc_5[88].fieldSizeInBytes = 4;
    dataDesc_5[88].override_field = nullptr;
    dataDesc_5[88].override_count = 0;
    dataDesc_5[88].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[88].flatGroup = 0;
    dataDesc_5[89].fieldType = FIELD_BOOLEAN;
    dataDesc_5[89].fieldName = "m_bIgnoreUnseenEnemies";
    dataDesc_5[89].fieldOffset = 2940;
    dataDesc_5[89].externalName = "ignoreunseenenemies";
    dataDesc_5[89].pSaveRestoreOps = nullptr;
    dataDesc_5[89].inputFunc = nullptr;
    dataDesc_5[89].td = nullptr;
    dataDesc_5[89].fieldSizeInBytes = 1;
    dataDesc_5[89].override_field = nullptr;
    dataDesc_5[89].override_count = 0;
    dataDesc_5[89].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[89].flatGroup = 0;
    dataDesc_5[90].fieldType = FIELD_EMBEDDED;
    dataDesc_5[90].fieldName = "m_ShotRegulator";
    dataDesc_5[90].fieldOffset = 2944;
    dataDesc_5[90].externalName = nullptr;
    dataDesc_5[90].pSaveRestoreOps = nullptr;
    dataDesc_5[90].inputFunc = nullptr;
    dataDesc_5[90].td = &CAI_ShotRegulator::m_DataMap;
    dataDesc_5[90].fieldSizeInBytes = 32;
    dataDesc_5[90].override_field = nullptr;
    dataDesc_5[90].override_count = 0;
    dataDesc_5[90].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[90].flatGroup = 0;
    dataDesc_5[91].fieldType = FIELD_INTEGER;
    dataDesc_5[91].fieldName = "m_iDesiredWeaponState";
    dataDesc_5[91].fieldOffset = 2976;
    dataDesc_5[91].externalName = nullptr;
    dataDesc_5[91].pSaveRestoreOps = nullptr;
    dataDesc_5[91].inputFunc = nullptr;
    dataDesc_5[91].td = nullptr;
    dataDesc_5[91].fieldSizeInBytes = 4;
    dataDesc_5[91].override_field = nullptr;
    dataDesc_5[91].override_count = 0;
    dataDesc_5[91].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[91].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[91].flatGroup = 0;
    dataDesc_5[92].fieldType = FIELD_STRING;
    dataDesc_5[92].fieldName = "m_SquadName";
    dataDesc_5[92].fieldOffset = 2984;
    dataDesc_5[92].flags = 6;
    dataDesc_5[93].fieldSize = 1;
    dataDesc_5[93].flags = 2;
    dataDesc_5[94].fieldSize = 1;
    dataDesc_5[94].flags = 6;
    dataDesc_5[95].fieldType = FIELD_BOOLEAN;
    dataDesc_5[95].fieldSize = 1;
    *(_QWORD *)dataDesc_5[92].flatOffset = 0;
    dataDesc_5[95].flags = 6;
    *(_QWORD *)dataDesc_5[93].flatOffset = 0;
    dataDesc_5[96].fieldSize = 1;
    *(_QWORD *)dataDesc_5[94].flatOffset = 0;
    dataDesc_5[92].externalName = "squadname";
    dataDesc_5[92].pSaveRestoreOps = nullptr;
    dataDesc_5[92].inputFunc = nullptr;
    dataDesc_5[92].td = nullptr;
    dataDesc_5[92].fieldSizeInBytes = 4;
    dataDesc_5[92].override_field = nullptr;
    dataDesc_5[92].override_count = 0;
    dataDesc_5[92].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[92].flatGroup = 0;
    dataDesc_5[93].fieldType = FIELD_INTEGER;
    dataDesc_5[93].fieldName = "m_iMySquadSlot";
    dataDesc_5[93].fieldOffset = 2988;
    dataDesc_5[93].externalName = nullptr;
    dataDesc_5[93].pSaveRestoreOps = nullptr;
    dataDesc_5[93].inputFunc = nullptr;
    dataDesc_5[93].td = nullptr;
    dataDesc_5[93].fieldSizeInBytes = 4;
    dataDesc_5[93].override_field = nullptr;
    dataDesc_5[93].override_count = 0;
    dataDesc_5[93].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[93].flatGroup = 0;
    dataDesc_5[94].fieldType = FIELD_STRING;
    dataDesc_5[94].fieldName = "m_strHintGroup";
    dataDesc_5[94].fieldOffset = 2992;
    dataDesc_5[94].externalName = "hintgroup";
    dataDesc_5[94].pSaveRestoreOps = nullptr;
    dataDesc_5[94].inputFunc = nullptr;
    dataDesc_5[94].td = nullptr;
    dataDesc_5[94].fieldSizeInBytes = 4;
    dataDesc_5[94].override_field = nullptr;
    dataDesc_5[94].override_count = 0;
    dataDesc_5[94].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[94].flatGroup = 0;
    dataDesc_5[95].fieldName = "m_bHintGroupNavLimiting";
    dataDesc_5[95].fieldOffset = 2996;
    dataDesc_5[95].externalName = "hintlimiting";
    dataDesc_5[95].pSaveRestoreOps = nullptr;
    dataDesc_5[95].inputFunc = nullptr;
    dataDesc_5[95].td = nullptr;
    dataDesc_5[95].fieldSizeInBytes = 1;
    dataDesc_5[95].override_field = nullptr;
    dataDesc_5[95].override_count = 0;
    dataDesc_5[95].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[95].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[95].flatGroup = 0;
    dataDesc_5[96].fieldType = FIELD_EMBEDDED;
    dataDesc_5[96].fieldName = "m_pTacticalServices";
    dataDesc_5[96].fieldOffset = 3000;
    dataDesc_5[96].flags = 66;
    dataDesc_5[96].externalName = nullptr;
    dataDesc_5[96].pSaveRestoreOps = nullptr;
    dataDesc_5[96].inputFunc = nullptr;
    dataDesc_5[96].td = &CAI_TacticalServices::m_DataMap;
    dataDesc_5[96].fieldSizeInBytes = 20;
    dataDesc_5[96].override_field = nullptr;
    dataDesc_5[96].override_count = 0;
    dataDesc_5[96].fieldTolerance = 0.0;
    dataDesc_5[97].fieldSize = 1;
    dataDesc_5[97].flags = 2;
    dataDesc_5[98].fieldSize = 1;
    dataDesc_5[98].flags = 2;
    dataDesc_5[99].fieldSize = 1;
    dataDesc_5[99].flags = 2;
    *(_QWORD *)dataDesc_5[96].flatOffset = 0;
    dataDesc_5[100].fieldSize = 1;
    *(_QWORD *)dataDesc_5[97].flatOffset = 0;
    *(_QWORD *)dataDesc_5[98].flatOffset = 0;
    dataDesc_5[100].flags = 2;
    *(_QWORD *)dataDesc_5[99].flatOffset = 0;
    dataDesc_5[101].fieldSize = 1;
    *(_DWORD *)&dataDesc_5[96].flatGroup = 0;
    dataDesc_5[97].fieldType = FIELD_TIME;
    dataDesc_5[97].fieldName = "m_flWaitFinished";
    dataDesc_5[97].fieldOffset = 3004;
    dataDesc_5[97].externalName = nullptr;
    dataDesc_5[97].pSaveRestoreOps = nullptr;
    dataDesc_5[97].inputFunc = nullptr;
    dataDesc_5[97].td = nullptr;
    dataDesc_5[97].fieldSizeInBytes = 4;
    dataDesc_5[97].override_field = nullptr;
    dataDesc_5[97].override_count = 0;
    dataDesc_5[97].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[97].flatGroup = 0;
    dataDesc_5[98].fieldType = FIELD_TIME;
    dataDesc_5[98].fieldName = "m_flNextFlinchTime";
    dataDesc_5[98].fieldOffset = 3008;
    dataDesc_5[98].externalName = nullptr;
    dataDesc_5[98].pSaveRestoreOps = nullptr;
    dataDesc_5[98].inputFunc = nullptr;
    dataDesc_5[98].td = nullptr;
    dataDesc_5[98].fieldSizeInBytes = 4;
    dataDesc_5[98].override_field = nullptr;
    dataDesc_5[98].override_count = 0;
    dataDesc_5[98].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[98].flatGroup = 0;
    dataDesc_5[99].fieldType = FIELD_TIME;
    dataDesc_5[99].fieldName = "m_flNextDodgeTime";
    dataDesc_5[99].fieldOffset = 3012;
    dataDesc_5[99].externalName = nullptr;
    dataDesc_5[99].pSaveRestoreOps = nullptr;
    dataDesc_5[99].inputFunc = nullptr;
    dataDesc_5[99].td = nullptr;
    dataDesc_5[99].fieldSizeInBytes = 4;
    dataDesc_5[99].override_field = nullptr;
    dataDesc_5[99].override_count = 0;
    dataDesc_5[99].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[99].flatGroup = 0;
    dataDesc_5[100].fieldType = FIELD_EMBEDDED;
    dataDesc_5[100].fieldName = "m_MoveAndShootOverlay";
    dataDesc_5[100].fieldOffset = 3016;
    dataDesc_5[100].externalName = nullptr;
    dataDesc_5[100].pSaveRestoreOps = nullptr;
    dataDesc_5[100].inputFunc = nullptr;
    dataDesc_5[100].td = &CAI_MoveAndShootOverlay::m_DataMap;
    dataDesc_5[100].fieldSizeInBytes = 20;
    dataDesc_5[100].override_field = nullptr;
    dataDesc_5[100].override_count = 0;
    dataDesc_5[100].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[100].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[100].flatGroup = 0;
    dataDesc_5[101].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_5[101].fieldName = "m_vecLastPosition";
    dataDesc_5[101].fieldOffset = 3036;
    dataDesc_5[101].flags = 2;
    dataDesc_5[102].fieldSize = 1;
    dataDesc_5[102].flags = 2;
    dataDesc_5[103].fieldSize = 1;
    dataDesc_5[103].flags = 2;
    dataDesc_5[104].fieldSize = 1;
    *(_QWORD *)dataDesc_5[101].flatOffset = 0;
    dataDesc_5[104].flags = 2;
    *(_QWORD *)dataDesc_5[102].flatOffset = 0;
    dataDesc_5[105].fieldSize = 1;
    *(_QWORD *)dataDesc_5[103].flatOffset = 0;
    dataDesc_5[101].externalName = nullptr;
    dataDesc_5[101].pSaveRestoreOps = nullptr;
    dataDesc_5[101].inputFunc = nullptr;
    dataDesc_5[101].td = nullptr;
    dataDesc_5[101].fieldSizeInBytes = 12;
    dataDesc_5[101].override_field = nullptr;
    dataDesc_5[101].override_count = 0;
    dataDesc_5[101].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[101].flatGroup = 0;
    dataDesc_5[102].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_5[102].fieldName = "m_vSavePosition";
    dataDesc_5[102].fieldOffset = 3048;
    dataDesc_5[102].externalName = nullptr;
    dataDesc_5[102].pSaveRestoreOps = nullptr;
    dataDesc_5[102].inputFunc = nullptr;
    dataDesc_5[102].td = nullptr;
    dataDesc_5[102].fieldSizeInBytes = 12;
    dataDesc_5[102].override_field = nullptr;
    dataDesc_5[102].override_count = 0;
    dataDesc_5[102].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[102].flatGroup = 0;
    dataDesc_5[103].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_5[103].fieldName = "m_vInterruptSavePosition";
    dataDesc_5[103].fieldOffset = 3060;
    dataDesc_5[103].externalName = nullptr;
    dataDesc_5[103].pSaveRestoreOps = nullptr;
    dataDesc_5[103].inputFunc = nullptr;
    dataDesc_5[103].td = nullptr;
    dataDesc_5[103].fieldSizeInBytes = 12;
    dataDesc_5[103].override_field = nullptr;
    dataDesc_5[103].override_count = 0;
    dataDesc_5[103].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[103].flatGroup = 0;
    dataDesc_5[104].fieldType = FIELD_EHANDLE;
    dataDesc_5[104].fieldName = "m_pHintNode";
    dataDesc_5[104].fieldOffset = 3072;
    dataDesc_5[104].externalName = nullptr;
    dataDesc_5[104].pSaveRestoreOps = nullptr;
    dataDesc_5[104].inputFunc = nullptr;
    dataDesc_5[104].td = nullptr;
    dataDesc_5[104].fieldSizeInBytes = 4;
    dataDesc_5[104].override_field = nullptr;
    dataDesc_5[104].override_count = 0;
    dataDesc_5[104].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[104].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[104].flatGroup = 0;
    dataDesc_5[105].fieldType = FIELD_INTEGER;
    dataDesc_5[105].fieldName = "m_cAmmoLoaded";
    dataDesc_5[105].fieldOffset = 3076;
    dataDesc_5[105].flags = 2;
    dataDesc_5[105].externalName = nullptr;
    dataDesc_5[105].pSaveRestoreOps = nullptr;
    dataDesc_5[105].inputFunc = nullptr;
    dataDesc_5[105].td = nullptr;
    dataDesc_5[105].fieldSizeInBytes = 4;
    dataDesc_5[105].override_field = nullptr;
    dataDesc_5[105].override_count = 0;
    dataDesc_5[105].fieldTolerance = 0.0;
    dataDesc_5[106].fieldSize = 1;
    dataDesc_5[106].flags = 2;
    dataDesc_5[107].fieldSize = 1;
    dataDesc_5[107].flags = 2;
    dataDesc_5[108].fieldSize = 1;
    dataDesc_5[108].flags = 2;
    *(_QWORD *)dataDesc_5[105].flatOffset = 0;
    dataDesc_5[109].fieldSize = 1;
    *(_QWORD *)dataDesc_5[106].flatOffset = 0;
    *(_QWORD *)dataDesc_5[107].flatOffset = 0;
    dataDesc_5[109].flags = 6;
    dataDesc_5[110].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)dataDesc_5[108].flatOffset = 0;
    dataDesc_5[110].fieldSize = 1;
    *(_DWORD *)&dataDesc_5[105].flatGroup = 0;
    dataDesc_5[106].fieldType = FIELD_FLOAT;
    dataDesc_5[106].fieldName = "m_flDistTooFar";
    dataDesc_5[106].fieldOffset = 3080;
    dataDesc_5[106].externalName = nullptr;
    dataDesc_5[106].pSaveRestoreOps = nullptr;
    dataDesc_5[106].inputFunc = nullptr;
    dataDesc_5[106].td = nullptr;
    dataDesc_5[106].fieldSizeInBytes = 4;
    dataDesc_5[106].override_field = nullptr;
    dataDesc_5[106].override_count = 0;
    dataDesc_5[106].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[106].flatGroup = 0;
    dataDesc_5[107].fieldType = FIELD_EHANDLE;
    dataDesc_5[107].fieldName = "m_hGoalEnt";
    dataDesc_5[107].fieldOffset = 2792;
    dataDesc_5[107].externalName = nullptr;
    dataDesc_5[107].pSaveRestoreOps = nullptr;
    dataDesc_5[107].inputFunc = nullptr;
    dataDesc_5[107].td = nullptr;
    dataDesc_5[107].fieldSizeInBytes = 4;
    dataDesc_5[107].override_field = nullptr;
    dataDesc_5[107].override_count = 0;
    dataDesc_5[107].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[107].flatGroup = 0;
    dataDesc_5[108].fieldType = FIELD_TIME;
    dataDesc_5[108].fieldName = "m_flTimeLastMovement";
    dataDesc_5[108].fieldOffset = 2796;
    dataDesc_5[108].externalName = nullptr;
    dataDesc_5[108].pSaveRestoreOps = nullptr;
    dataDesc_5[108].inputFunc = nullptr;
    dataDesc_5[108].td = nullptr;
    dataDesc_5[108].fieldSizeInBytes = 4;
    dataDesc_5[108].override_field = nullptr;
    dataDesc_5[108].override_count = 0;
    dataDesc_5[108].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[108].flatGroup = 0;
    dataDesc_5[109].fieldType = FIELD_STRING;
    dataDesc_5[109].fieldName = "m_spawnEquipment";
    dataDesc_5[109].fieldOffset = 3084;
    dataDesc_5[109].externalName = "additionalequipment";
    dataDesc_5[109].pSaveRestoreOps = nullptr;
    dataDesc_5[109].inputFunc = nullptr;
    dataDesc_5[109].td = nullptr;
    dataDesc_5[109].fieldSizeInBytes = 4;
    dataDesc_5[109].override_field = nullptr;
    dataDesc_5[109].override_count = 0;
    dataDesc_5[109].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[109].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[109].flatGroup = 0;
    dataDesc_5[110].fieldName = "m_fNoDamageDecal";
    dataDesc_5[110].fieldOffset = 3088;
    dataDesc_5[110].flags = 2;
    dataDesc_5[111].fieldSize = 1;
    dataDesc_5[111].flags = 2;
    dataDesc_5[112].fieldSize = 1;
    dataDesc_5[112].flags = 2;
    dataDesc_5[113].fieldSize = 1;
    *(_QWORD *)dataDesc_5[110].flatOffset = 0;
    dataDesc_5[113].flags = 2;
    *(_QWORD *)dataDesc_5[111].flatOffset = 0;
    dataDesc_5[114].fieldSize = 1;
    *(_QWORD *)dataDesc_5[112].flatOffset = 0;
    dataDesc_5[110].externalName = nullptr;
    dataDesc_5[110].pSaveRestoreOps = nullptr;
    dataDesc_5[110].inputFunc = nullptr;
    dataDesc_5[110].td = nullptr;
    dataDesc_5[110].fieldSizeInBytes = 1;
    dataDesc_5[110].override_field = nullptr;
    dataDesc_5[110].override_count = 0;
    dataDesc_5[110].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[110].flatGroup = 0;
    dataDesc_5[111].fieldType = FIELD_EHANDLE;
    dataDesc_5[111].fieldName = "m_hStoredPathTarget";
    dataDesc_5[111].fieldOffset = 3092;
    dataDesc_5[111].externalName = nullptr;
    dataDesc_5[111].pSaveRestoreOps = nullptr;
    dataDesc_5[111].inputFunc = nullptr;
    dataDesc_5[111].td = nullptr;
    dataDesc_5[111].fieldSizeInBytes = 4;
    dataDesc_5[111].override_field = nullptr;
    dataDesc_5[111].override_count = 0;
    dataDesc_5[111].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[111].flatGroup = 0;
    dataDesc_5[112].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_5[112].fieldName = "m_vecStoredPathGoal";
    dataDesc_5[112].fieldOffset = 3096;
    dataDesc_5[112].externalName = nullptr;
    dataDesc_5[112].pSaveRestoreOps = nullptr;
    dataDesc_5[112].inputFunc = nullptr;
    dataDesc_5[112].td = nullptr;
    dataDesc_5[112].fieldSizeInBytes = 12;
    dataDesc_5[112].override_field = nullptr;
    dataDesc_5[112].override_count = 0;
    dataDesc_5[112].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[112].flatGroup = 0;
    dataDesc_5[113].fieldType = FIELD_INTEGER;
    dataDesc_5[113].fieldName = "m_nStoredPathType";
    dataDesc_5[113].fieldOffset = 3108;
    dataDesc_5[113].externalName = nullptr;
    dataDesc_5[113].pSaveRestoreOps = nullptr;
    dataDesc_5[113].inputFunc = nullptr;
    dataDesc_5[113].td = nullptr;
    dataDesc_5[113].fieldSizeInBytes = 4;
    dataDesc_5[113].override_field = nullptr;
    dataDesc_5[113].override_count = 0;
    dataDesc_5[113].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[113].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[113].flatGroup = 0;
    dataDesc_5[114].fieldType = FIELD_INTEGER;
    dataDesc_5[114].fieldName = "m_fStoredPathFlags";
    dataDesc_5[114].fieldOffset = 3112;
    dataDesc_5[114].flags = 2;
    dataDesc_5[114].externalName = nullptr;
    dataDesc_5[114].pSaveRestoreOps = nullptr;
    dataDesc_5[114].inputFunc = nullptr;
    dataDesc_5[114].td = nullptr;
    dataDesc_5[114].fieldSizeInBytes = 4;
    dataDesc_5[114].override_field = nullptr;
    dataDesc_5[114].override_count = 0;
    dataDesc_5[114].fieldTolerance = 0.0;
    dataDesc_5[115].fieldSize = 1;
    dataDesc_5[115].flags = 2;
    dataDesc_5[116].fieldSize = 1;
    dataDesc_5[116].flags = 2;
    dataDesc_5[117].fieldSize = 1;
    dataDesc_5[117].flags = 2;
    *(_QWORD *)dataDesc_5[114].flatOffset = 0;
    dataDesc_5[118].fieldSize = 1;
    *(_QWORD *)dataDesc_5[115].flatOffset = 0;
    *(_QWORD *)dataDesc_5[116].flatOffset = 0;
    dataDesc_5[118].flags = 2;
    *(_QWORD *)dataDesc_5[117].flatOffset = 0;
    dataDesc_5[119].fieldSize = 1;
    *(_DWORD *)&dataDesc_5[114].flatGroup = 0;
    dataDesc_5[115].fieldType = FIELD_BOOLEAN;
    dataDesc_5[115].fieldName = "m_bDidDeathCleanup";
    dataDesc_5[115].fieldOffset = 3124;
    dataDesc_5[115].externalName = nullptr;
    dataDesc_5[115].pSaveRestoreOps = nullptr;
    dataDesc_5[115].inputFunc = nullptr;
    dataDesc_5[115].td = nullptr;
    dataDesc_5[115].fieldSizeInBytes = 1;
    dataDesc_5[115].override_field = nullptr;
    dataDesc_5[115].override_count = 0;
    dataDesc_5[115].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[115].flatGroup = 0;
    dataDesc_5[116].fieldType = FIELD_BOOLEAN;
    dataDesc_5[116].fieldName = "m_bCrouchDesired";
    dataDesc_5[116].fieldOffset = 3634;
    dataDesc_5[116].externalName = nullptr;
    dataDesc_5[116].pSaveRestoreOps = nullptr;
    dataDesc_5[116].inputFunc = nullptr;
    dataDesc_5[116].td = nullptr;
    dataDesc_5[116].fieldSizeInBytes = 1;
    dataDesc_5[116].override_field = nullptr;
    dataDesc_5[116].override_count = 0;
    dataDesc_5[116].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[116].flatGroup = 0;
    dataDesc_5[117].fieldType = FIELD_BOOLEAN;
    dataDesc_5[117].fieldName = "m_bForceCrouch";
    dataDesc_5[117].fieldOffset = 3635;
    dataDesc_5[117].externalName = nullptr;
    dataDesc_5[117].pSaveRestoreOps = nullptr;
    dataDesc_5[117].inputFunc = nullptr;
    dataDesc_5[117].td = nullptr;
    dataDesc_5[117].fieldSizeInBytes = 1;
    dataDesc_5[117].override_field = nullptr;
    dataDesc_5[117].override_count = 0;
    dataDesc_5[117].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[117].flatGroup = 0;
    dataDesc_5[118].fieldType = FIELD_BOOLEAN;
    dataDesc_5[118].fieldName = "m_bIsCrouching";
    dataDesc_5[118].fieldOffset = 3636;
    dataDesc_5[118].externalName = nullptr;
    dataDesc_5[118].pSaveRestoreOps = nullptr;
    dataDesc_5[118].inputFunc = nullptr;
    dataDesc_5[118].td = nullptr;
    dataDesc_5[118].fieldSizeInBytes = 1;
    dataDesc_5[118].override_field = nullptr;
    dataDesc_5[118].override_count = 0;
    dataDesc_5[118].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[118].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[118].flatGroup = 0;
    dataDesc_5[119].fieldType = FIELD_BOOLEAN;
    dataDesc_5[119].fieldName = "m_bPerformAvoidance";
    dataDesc_5[119].fieldOffset = 3684;
    dataDesc_5[119].flags = 2;
    dataDesc_5[120].fieldSize = 1;
    dataDesc_5[120].flags = 2;
    dataDesc_5[121].fieldSize = 1;
    dataDesc_5[121].flags = 2;
    dataDesc_5[122].fieldSize = 1;
    *(_QWORD *)dataDesc_5[119].flatOffset = 0;
    dataDesc_5[122].flags = 2;
    *(_QWORD *)dataDesc_5[120].flatOffset = 0;
    dataDesc_5[123].fieldSize = 1;
    *(_QWORD *)dataDesc_5[121].flatOffset = 0;
    dataDesc_5[119].externalName = nullptr;
    dataDesc_5[119].pSaveRestoreOps = nullptr;
    dataDesc_5[119].inputFunc = nullptr;
    dataDesc_5[119].td = nullptr;
    dataDesc_5[119].fieldSizeInBytes = 1;
    dataDesc_5[119].override_field = nullptr;
    dataDesc_5[119].override_count = 0;
    dataDesc_5[119].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[119].flatGroup = 0;
    dataDesc_5[120].fieldType = FIELD_BOOLEAN;
    dataDesc_5[120].fieldName = "m_bIsMoving";
    dataDesc_5[120].fieldOffset = 3685;
    dataDesc_5[120].externalName = nullptr;
    dataDesc_5[120].pSaveRestoreOps = nullptr;
    dataDesc_5[120].inputFunc = nullptr;
    dataDesc_5[120].td = nullptr;
    dataDesc_5[120].fieldSizeInBytes = 1;
    dataDesc_5[120].override_field = nullptr;
    dataDesc_5[120].override_count = 0;
    dataDesc_5[120].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[120].flatGroup = 0;
    dataDesc_5[121].fieldType = FIELD_BOOLEAN;
    dataDesc_5[121].fieldName = "m_bFadeCorpse";
    dataDesc_5[121].fieldOffset = 3686;
    dataDesc_5[121].externalName = nullptr;
    dataDesc_5[121].pSaveRestoreOps = nullptr;
    dataDesc_5[121].inputFunc = nullptr;
    dataDesc_5[121].td = nullptr;
    dataDesc_5[121].fieldSizeInBytes = 1;
    dataDesc_5[121].override_field = nullptr;
    dataDesc_5[121].override_count = 0;
    dataDesc_5[121].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[121].flatGroup = 0;
    dataDesc_5[122].fieldType = FIELD_INTEGER;
    dataDesc_5[122].fieldName = "m_iDeathPose";
    dataDesc_5[122].fieldOffset = 2588;
    dataDesc_5[122].externalName = nullptr;
    dataDesc_5[122].pSaveRestoreOps = nullptr;
    dataDesc_5[122].inputFunc = nullptr;
    dataDesc_5[122].td = nullptr;
    dataDesc_5[122].fieldSizeInBytes = 4;
    dataDesc_5[122].override_field = nullptr;
    dataDesc_5[122].override_count = 0;
    dataDesc_5[122].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[122].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[122].flatGroup = 0;
    dataDesc_5[123].fieldType = FIELD_INTEGER;
    dataDesc_5[123].fieldName = "m_iDeathFrame";
    dataDesc_5[123].fieldOffset = 2592;
    dataDesc_5[123].flags = 2;
    dataDesc_5[123].externalName = nullptr;
    dataDesc_5[123].pSaveRestoreOps = nullptr;
    dataDesc_5[123].inputFunc = nullptr;
    dataDesc_5[123].td = nullptr;
    dataDesc_5[123].fieldSizeInBytes = 4;
    dataDesc_5[123].override_field = nullptr;
    dataDesc_5[123].override_count = 0;
    dataDesc_5[123].fieldTolerance = 0.0;
    dataDesc_5[124].fieldSize = 1;
    dataDesc_5[124].flags = 2;
    dataDesc_5[125].fieldSize = 1;
    dataDesc_5[125].flags = 2;
    dataDesc_5[126].fieldSize = 1;
    dataDesc_5[126].flags = 2;
    *(_QWORD *)dataDesc_5[123].flatOffset = 0;
    dataDesc_5[127].fieldSize = 1;
    *(_QWORD *)dataDesc_5[124].flatOffset = 0;
    *(_QWORD *)dataDesc_5[125].flatOffset = 0;
    dataDesc_5[127].flags = 2;
    *(_QWORD *)dataDesc_5[126].flatOffset = 0;
    dataDesc_5[128].fieldSize = 1;
    *(_DWORD *)&dataDesc_5[123].flatGroup = 0;
    dataDesc_5[124].fieldType = FIELD_BOOLEAN;
    dataDesc_5[124].fieldName = "m_bCheckContacts";
    dataDesc_5[124].fieldOffset = 3633;
    dataDesc_5[124].externalName = nullptr;
    dataDesc_5[124].pSaveRestoreOps = nullptr;
    dataDesc_5[124].inputFunc = nullptr;
    dataDesc_5[124].td = nullptr;
    dataDesc_5[124].fieldSizeInBytes = 1;
    dataDesc_5[124].override_field = nullptr;
    dataDesc_5[124].override_count = 0;
    dataDesc_5[124].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[124].flatGroup = 0;
    dataDesc_5[125].fieldType = FIELD_BOOLEAN;
    dataDesc_5[125].fieldName = "m_bSpeedModActive";
    dataDesc_5[125].fieldOffset = 3688;
    dataDesc_5[125].externalName = nullptr;
    dataDesc_5[125].pSaveRestoreOps = nullptr;
    dataDesc_5[125].inputFunc = nullptr;
    dataDesc_5[125].td = nullptr;
    dataDesc_5[125].fieldSizeInBytes = 1;
    dataDesc_5[125].override_field = nullptr;
    dataDesc_5[125].override_count = 0;
    dataDesc_5[125].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[125].flatGroup = 0;
    dataDesc_5[126].fieldType = FIELD_INTEGER;
    dataDesc_5[126].fieldName = "m_iSpeedModRadius";
    dataDesc_5[126].fieldOffset = 3692;
    dataDesc_5[126].externalName = nullptr;
    dataDesc_5[126].pSaveRestoreOps = nullptr;
    dataDesc_5[126].inputFunc = nullptr;
    dataDesc_5[126].td = nullptr;
    dataDesc_5[126].fieldSizeInBytes = 4;
    dataDesc_5[126].override_field = nullptr;
    dataDesc_5[126].override_count = 0;
    dataDesc_5[126].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_5[126].flatGroup = 0;
    dataDesc_5[127].fieldType = FIELD_INTEGER;
    dataDesc_5[127].fieldName = "m_iSpeedModSpeed";
    dataDesc_5[127].fieldOffset = 3696;
    dataDesc_5[127].externalName = nullptr;
    dataDesc_5[127].pSaveRestoreOps = nullptr;
    dataDesc_5[127].inputFunc = nullptr;
    dataDesc_5[127].td = nullptr;
    dataDesc_5[127].fieldSizeInBytes = 4;
    dataDesc_5[127].override_field = nullptr;
    dataDesc_5[127].override_count = 0;
    dataDesc_5[127].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[127].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[127].flatGroup = 0;
    dataDesc_5[128].fieldType = FIELD_EHANDLE;
    dataDesc_5[128].fieldName = "m_hEnemyFilter";
    dataDesc_5[128].fieldOffset = 3116;
    dataDesc_5[128].flags = 2;
    dataDesc_5[129].fieldSize = 1;
    dataDesc_5[129].flags = 6;
    dataDesc_5[130].fieldType = FIELD_BOOLEAN;
    dataDesc_5[131].fieldType = FIELD_BOOLEAN;
    dataDesc_5[131].fieldSize = 1;
    dataDesc_5[131].flags = 2;
    dataDesc_5[128].fieldSizeInBytes = 4;
    dataDesc_5[129].fieldSizeInBytes = 4;
    dataDesc_5[132].fieldSize = 1;
    dataDesc_5[128].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_5[128].flatOffset = 0;
    dataDesc_5[129].fieldTolerance = 0.0;
    dataDesc_5[130].fieldTolerance = 0.0;
    dataDesc_5[131].fieldTolerance = 0.0;
    dataDesc_5[130].fieldSize = 1;
    dataDesc_5[132].flags = 22;
    *(_QWORD *)dataDesc_5[129].flatOffset = 0;
    *(_QWORD *)dataDesc_5[131].flatOffset = 0;
    dataDesc_5[128].externalName = nullptr;
    dataDesc_5[128].pSaveRestoreOps = nullptr;
    dataDesc_5[128].inputFunc = nullptr;
    dataDesc_5[128].td = nullptr;
    dataDesc_5[128].override_field = nullptr;
    dataDesc_5[128].override_count = 0;
    *(_DWORD *)&dataDesc_5[128].flatGroup = 0;
    dataDesc_5[129].fieldType = FIELD_STRING;
    dataDesc_5[129].fieldName = "m_iszEnemyFilterName";
    dataDesc_5[129].fieldOffset = 3120;
    dataDesc_5[129].externalName = "enemyfilter";
    dataDesc_5[129].pSaveRestoreOps = nullptr;
    dataDesc_5[129].inputFunc = nullptr;
    dataDesc_5[129].td = nullptr;
    dataDesc_5[129].override_field = nullptr;
    dataDesc_5[129].override_count = 0;
    *(_DWORD *)&dataDesc_5[129].flatGroup = 0;
    dataDesc_5[130].fieldName = "m_bImportanRagdoll";
    dataDesc_5[130].fieldOffset = 3687;
    dataDesc_5[130].flags = 2;
    dataDesc_5[130].externalName = nullptr;
    dataDesc_5[130].pSaveRestoreOps = nullptr;
    dataDesc_5[130].inputFunc = nullptr;
    dataDesc_5[130].td = nullptr;
    dataDesc_5[130].fieldSizeInBytes = 1;
    dataDesc_5[130].override_field = nullptr;
    dataDesc_5[130].override_count = 0;
    *(_QWORD *)dataDesc_5[130].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[130].flatGroup = 0;
    dataDesc_5[131].fieldName = "m_bPlayerAvoidState";
    dataDesc_5[131].fieldOffset = 3708;
    dataDesc_5[131].externalName = nullptr;
    dataDesc_5[131].pSaveRestoreOps = nullptr;
    dataDesc_5[131].inputFunc = nullptr;
    dataDesc_5[131].td = nullptr;
    dataDesc_5[131].fieldSizeInBytes = 1;
    dataDesc_5[131].override_field = nullptr;
    dataDesc_5[131].override_count = 0;
    *(_DWORD *)&dataDesc_5[131].flatGroup = 0;
    dataDesc_5[132].fieldType = FIELD_CUSTOM;
    dataDesc_5[132].fieldName = "m_OnDamaged";
    dataDesc_5[132].fieldOffset = 3128;
    dataDesc_5[132].externalName = "OnDamaged";
    dataDesc_5[132].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_5[132].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[132].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[132].override_count = 0;
    *(_QWORD *)dataDesc_5[132].flatOffset = 0;
    dataDesc_5[133].fieldSize = 1;
    dataDesc_5[133].flags = 22;
    dataDesc_5[134].fieldSize = 1;
    dataDesc_5[134].flags = 22;
    dataDesc_5[135].fieldSize = 1;
    dataDesc_5[135].flags = 22;
    dataDesc_5[136].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[133].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[133].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[133].override_count = 0;
    *(_QWORD *)dataDesc_5[133].flatOffset = 0;
    dataDesc_5[136].flags = 22;
    *(_QWORD *)&dataDesc_5[134].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[134].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[134].override_count = 0;
    *(_QWORD *)dataDesc_5[134].flatOffset = 0;
    dataDesc_5[137].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[135].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[135].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[135].override_count = 0;
    *(_QWORD *)dataDesc_5[135].flatOffset = 0;
    dataDesc_5[137].flags = 22;
    *(_QWORD *)&dataDesc_5[136].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[136].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[136].override_count = 0;
    *(_QWORD *)dataDesc_5[136].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[132].flatGroup = 0;
    dataDesc_5[133].fieldType = FIELD_CUSTOM;
    dataDesc_5[133].fieldName = "m_OnDeath";
    dataDesc_5[133].fieldOffset = 3152;
    dataDesc_5[133].externalName = "OnDeath";
    dataDesc_5[133].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[133].flatGroup = 0;
    dataDesc_5[134].fieldType = FIELD_CUSTOM;
    dataDesc_5[134].fieldName = "m_OnHalfHealth";
    dataDesc_5[134].fieldOffset = 3176;
    dataDesc_5[134].externalName = "OnHalfHealth";
    dataDesc_5[134].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[134].flatGroup = 0;
    dataDesc_5[135].fieldType = FIELD_CUSTOM;
    dataDesc_5[135].fieldName = "m_OnFoundEnemy";
    dataDesc_5[135].fieldOffset = 3200;
    dataDesc_5[135].externalName = "OnFoundEnemy";
    dataDesc_5[135].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[135].flatGroup = 0;
    dataDesc_5[136].fieldType = FIELD_CUSTOM;
    dataDesc_5[136].fieldName = "m_OnLostEnemyLOS";
    dataDesc_5[136].fieldOffset = 3224;
    dataDesc_5[136].externalName = "OnLostEnemyLOS";
    dataDesc_5[136].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[136].flatGroup = 0;
    dataDesc_5[137].fieldType = FIELD_CUSTOM;
    dataDesc_5[137].fieldName = "m_OnLostEnemy";
    dataDesc_5[137].fieldOffset = 3248;
    dataDesc_5[137].externalName = "OnLostEnemy";
    dataDesc_5[137].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_5[137].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[137].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[137].override_count = 0;
    *(_QWORD *)dataDesc_5[137].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[137].flatGroup = 0;
    dataDesc_5[138].fieldType = FIELD_CUSTOM;
    dataDesc_5[138].fieldName = "m_OnFoundPlayer";
    dataDesc_5[138].fieldOffset = 3272;
    dataDesc_5[138].fieldSize = 1;
    dataDesc_5[138].flags = 22;
    dataDesc_5[139].fieldSize = 1;
    dataDesc_5[139].flags = 22;
    dataDesc_5[140].fieldSize = 1;
    dataDesc_5[140].flags = 22;
    dataDesc_5[141].fieldSize = 1;
    dataDesc_5[141].flags = 22;
    *(_QWORD *)&dataDesc_5[138].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[138].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[138].override_count = 0;
    *(_QWORD *)dataDesc_5[138].flatOffset = 0;
    *(_QWORD *)&dataDesc_5[139].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[139].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[139].override_count = 0;
    *(_QWORD *)dataDesc_5[139].flatOffset = 0;
    dataDesc_5[142].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[140].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[140].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[140].override_count = 0;
    *(_QWORD *)dataDesc_5[140].flatOffset = 0;
    dataDesc_5[142].flags = 22;
    *(_QWORD *)&dataDesc_5[141].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[141].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[141].override_count = 0;
    *(_QWORD *)dataDesc_5[141].flatOffset = 0;
    dataDesc_5[143].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[142].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[142].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[142].override_count = 0;
    *(_QWORD *)dataDesc_5[142].flatOffset = 0;
    dataDesc_5[138].externalName = "OnFoundPlayer";
    dataDesc_5[138].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[138].flatGroup = 0;
    dataDesc_5[139].fieldType = FIELD_CUSTOM;
    dataDesc_5[139].fieldName = "m_OnLostPlayerLOS";
    dataDesc_5[139].fieldOffset = 3296;
    dataDesc_5[139].externalName = "OnLostPlayerLOS";
    dataDesc_5[139].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[139].flatGroup = 0;
    dataDesc_5[140].fieldType = FIELD_CUSTOM;
    dataDesc_5[140].fieldName = "m_OnLostPlayer";
    dataDesc_5[140].fieldOffset = 3320;
    dataDesc_5[140].externalName = "OnLostPlayer";
    dataDesc_5[140].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[140].flatGroup = 0;
    dataDesc_5[141].fieldType = FIELD_CUSTOM;
    dataDesc_5[141].fieldName = "m_OnHearWorld";
    dataDesc_5[141].fieldOffset = 3344;
    dataDesc_5[141].externalName = "OnHearWorld";
    dataDesc_5[141].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[141].flatGroup = 0;
    dataDesc_5[142].fieldType = FIELD_CUSTOM;
    dataDesc_5[142].fieldName = "m_OnHearPlayer";
    dataDesc_5[142].fieldOffset = 3368;
    dataDesc_5[142].externalName = "OnHearPlayer";
    dataDesc_5[142].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[142].flatGroup = 0;
    dataDesc_5[143].fieldType = FIELD_CUSTOM;
    dataDesc_5[143].fieldName = "m_OnHearCombat";
    dataDesc_5[143].fieldOffset = 3392;
    dataDesc_5[143].flags = 22;
    dataDesc_5[143].externalName = "OnHearCombat";
    dataDesc_5[143].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_5[143].inputFunc = 0;
    dataDesc_5[144].fieldSize = 1;
    dataDesc_5[144].flags = 22;
    dataDesc_5[145].fieldSize = 1;
    dataDesc_5[145].flags = 22;
    dataDesc_5[146].fieldSize = 1;
    dataDesc_5[146].flags = 22;
    *(_QWORD *)&dataDesc_5[143].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[143].override_count = 0;
    *(_QWORD *)dataDesc_5[143].flatOffset = 0;
    *(_QWORD *)&dataDesc_5[144].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[144].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[144].override_count = 0;
    *(_QWORD *)dataDesc_5[144].flatOffset = 0;
    dataDesc_5[147].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[145].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[145].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[145].override_count = 0;
    *(_QWORD *)dataDesc_5[145].flatOffset = 0;
    dataDesc_5[147].flags = 22;
    *(_QWORD *)&dataDesc_5[146].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[146].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[146].override_count = 0;
    *(_QWORD *)dataDesc_5[146].flatOffset = 0;
    dataDesc_5[148].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[147].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[147].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[147].override_count = 0;
    *(_QWORD *)dataDesc_5[147].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[143].flatGroup = 0;
    dataDesc_5[144].fieldType = FIELD_CUSTOM;
    dataDesc_5[144].fieldName = "m_OnDamagedByPlayer";
    dataDesc_5[144].fieldOffset = 3416;
    dataDesc_5[144].externalName = "OnDamagedByPlayer";
    dataDesc_5[144].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[144].flatGroup = 0;
    dataDesc_5[145].fieldType = FIELD_CUSTOM;
    dataDesc_5[145].fieldName = "m_OnDamagedByPlayerSquad";
    dataDesc_5[145].fieldOffset = 3440;
    dataDesc_5[145].externalName = "OnDamagedByPlayerSquad";
    dataDesc_5[145].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[145].flatGroup = 0;
    dataDesc_5[146].fieldType = FIELD_CUSTOM;
    dataDesc_5[146].fieldName = "m_OnDenyCommanderUse";
    dataDesc_5[146].fieldOffset = 3464;
    dataDesc_5[146].externalName = "OnDenyCommanderUse";
    dataDesc_5[146].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[146].flatGroup = 0;
    dataDesc_5[147].fieldType = FIELD_CUSTOM;
    dataDesc_5[147].fieldName = "m_OnRappelTouchdown";
    dataDesc_5[147].fieldOffset = 3488;
    dataDesc_5[147].externalName = "OnRappelTouchdown";
    dataDesc_5[147].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_5[147].flatGroup = 0;
    dataDesc_5[148].fieldType = FIELD_CUSTOM;
    dataDesc_5[148].fieldName = "m_OnWake";
    dataDesc_5[148].fieldOffset = 3536;
    dataDesc_5[148].flags = 22;
    dataDesc_5[148].externalName = "OnWake";
    dataDesc_5[148].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_5[148].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[148].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[148].override_count = 0;
    *(_QWORD *)dataDesc_5[148].flatOffset = 0;
    *(_DWORD *)&dataDesc_5[148].flatGroup = 0;
    dataDesc_5[149].fieldType = FIELD_CUSTOM;
    dataDesc_5[149].fieldName = "m_OnSleep";
    dataDesc_5[149].fieldSize = 1;
    dataDesc_5[149].flags = 22;
    dataDesc_5[150].fieldSize = 1;
    dataDesc_5[149].pSaveRestoreOps = eventFuncs;
    dataDesc_5[150].flags = 22;
    dataDesc_5[150].pSaveRestoreOps = eventFuncs;
    dataDesc_5[151].pSaveRestoreOps = eventFuncs;
    dataDesc_5[152].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_5[149].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[149].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[149].override_count = 0;
    *(_QWORD *)dataDesc_5[149].flatOffset = 0;
    dataDesc_5[151].fieldSize = 1;
    dataDesc_5[153].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[150].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[150].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[150].override_count = 0;
    *(_QWORD *)dataDesc_5[150].flatOffset = 0;
    dataDesc_5[151].flags = 22;
    dataDesc_5[153].flags = 8;
    *(_QWORD *)&dataDesc_5[151].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[151].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[151].override_count = 0;
    *(_QWORD *)dataDesc_5[151].flatOffset = 0;
    dataDesc_5[152].fieldSize = 1;
    dataDesc_5[154].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[152].inputFunc = 0;
    *(_QWORD *)&dataDesc_5[152].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_5[152].override_count = 0;
    *(_QWORD *)dataDesc_5[152].flatOffset = 0;
    dataDesc_5[149].fieldOffset = 3512;
    dataDesc_5[149].externalName = "OnSleep";
    *(_DWORD *)&dataDesc_5[149].flatGroup = 0;
    dataDesc_5[150].fieldType = FIELD_CUSTOM;
    dataDesc_5[150].fieldName = "m_OnForcedInteractionStarted";
    dataDesc_5[150].fieldOffset = 3560;
    dataDesc_5[150].externalName = "OnForcedInteractionStarted";
    *(_DWORD *)&dataDesc_5[150].flatGroup = 0;
    dataDesc_5[151].fieldType = FIELD_CUSTOM;
    dataDesc_5[151].fieldName = "m_OnForcedInteractionAborted";
    dataDesc_5[151].fieldOffset = 3584;
    dataDesc_5[151].externalName = "OnForcedInteractionAborted";
    *(_DWORD *)&dataDesc_5[151].flatGroup = 0;
    dataDesc_5[152].fieldType = FIELD_CUSTOM;
    dataDesc_5[152].fieldName = "m_OnForcedInteractionFinished";
    dataDesc_5[152].fieldOffset = 3608;
    dataDesc_5[152].flags = 22;
    dataDesc_5[152].externalName = "OnForcedInteractionFinished";
    *(_DWORD *)&dataDesc_5[152].flatGroup = 0;
    dataDesc_5[153].fieldType = FIELD_STRING;
    dataDesc_5[153].fieldName = "InputSetRelationship";
    dataDesc_5[153].fieldOffset = 0;
    dataDesc_5[153].externalName = "SetRelationship";
    dataDesc_5[153].pSaveRestoreOps = nullptr;
    dataDesc_5[153].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputSetRelationship;
    *(_QWORD *)&dataDesc_5[153].td = 0;
    *(_QWORD *)&dataDesc_5[153].override_field = 0;
    *(_QWORD *)&dataDesc_5[153].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[153].flatOffset[1] = 0;
    dataDesc_5[154].fieldType = FIELD_STRING;
    dataDesc_5[154].fieldName = "InputSetEnemyFilter";
    dataDesc_5[154].fieldOffset = 0;
    dataDesc_5[154].flags = 8;
    dataDesc_5[154].externalName = "SetEnemyFilter";
    dataDesc_5[155].fieldSize = 1;
    dataDesc_5[155].flags = 8;
    dataDesc_5[156].fieldSize = 1;
    dataDesc_5[156].flags = 8;
    dataDesc_5[157].fieldSize = 1;
    dataDesc_5[157].flags = 8;
    *(_QWORD *)&dataDesc_5[154].td = 0;
    *(_QWORD *)&dataDesc_5[154].override_field = 0;
    *(_QWORD *)&dataDesc_5[154].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[154].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_5[155].td = 0;
    *(_QWORD *)&dataDesc_5[155].override_field = 0;
    *(_QWORD *)&dataDesc_5[155].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[155].flatOffset[1] = 0;
    dataDesc_5[158].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[156].td = 0;
    *(_QWORD *)&dataDesc_5[156].override_field = 0;
    *(_QWORD *)&dataDesc_5[156].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[156].flatOffset[1] = 0;
    dataDesc_5[158].flags = 8;
    *(_QWORD *)&dataDesc_5[157].td = 0;
    *(_QWORD *)&dataDesc_5[157].override_field = 0;
    *(_QWORD *)&dataDesc_5[157].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[157].flatOffset[1] = 0;
    dataDesc_5[159].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[158].td = 0;
    *(_QWORD *)&dataDesc_5[158].override_field = 0;
    *(_QWORD *)&dataDesc_5[158].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[158].flatOffset[1] = 0;
    dataDesc_5[154].pSaveRestoreOps = nullptr;
    dataDesc_5[154].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputSetEnemyFilter;
    dataDesc_5[155].fieldType = FIELD_INTEGER;
    dataDesc_5[155].fieldName = "InputSetHealth";
    dataDesc_5[155].fieldOffset = 0;
    dataDesc_5[155].externalName = "SetHealth";
    dataDesc_5[155].pSaveRestoreOps = nullptr;
    dataDesc_5[155].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputSetHealth;
    dataDesc_5[156].fieldType = FIELD_VOID;
    dataDesc_5[156].fieldName = "InputBeginRappel";
    dataDesc_5[156].fieldOffset = 0;
    dataDesc_5[156].externalName = "BeginRappel";
    dataDesc_5[156].pSaveRestoreOps = nullptr;
    dataDesc_5[156].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputBeginRappel;
    dataDesc_5[157].fieldType = FIELD_STRING;
    dataDesc_5[157].fieldName = "InputSetSquad";
    dataDesc_5[157].fieldOffset = 0;
    dataDesc_5[157].externalName = "SetSquad";
    dataDesc_5[157].pSaveRestoreOps = nullptr;
    dataDesc_5[157].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputSetSquad;
    dataDesc_5[158].fieldType = FIELD_VOID;
    dataDesc_5[158].fieldName = "InputWake";
    dataDesc_5[158].fieldOffset = 0;
    dataDesc_5[158].externalName = "Wake";
    dataDesc_5[158].pSaveRestoreOps = nullptr;
    dataDesc_5[158].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputWake;
    dataDesc_5[159].fieldType = FIELD_STRING;
    dataDesc_5[159].fieldName = "InputForgetEntity";
    dataDesc_5[159].fieldOffset = 0;
    dataDesc_5[159].flags = 8;
    dataDesc_5[159].externalName = "ForgetEntity";
    dataDesc_5[159].pSaveRestoreOps = nullptr;
    dataDesc_5[159].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputForgetEntity;
    *(_QWORD *)&dataDesc_5[159].td = 0;
    *(_QWORD *)&dataDesc_5[159].override_field = 0;
    dataDesc_5[160].fieldSize = 1;
    dataDesc_5[160].flags = 8;
    dataDesc_5[161].fieldSize = 1;
    dataDesc_5[161].flags = 8;
    dataDesc_5[162].fieldSize = 1;
    dataDesc_5[162].flags = 8;
    *(_QWORD *)&dataDesc_5[159].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[159].flatOffset[1] = 0;
    dataDesc_5[163].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[160].td = 0;
    *(_QWORD *)&dataDesc_5[160].override_field = 0;
    *(_QWORD *)&dataDesc_5[160].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[160].flatOffset[1] = 0;
    dataDesc_5[163].flags = 8;
    *(_QWORD *)&dataDesc_5[161].td = 0;
    *(_QWORD *)&dataDesc_5[161].override_field = 0;
    *(_QWORD *)&dataDesc_5[161].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[161].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_5[162].td = 0;
    *(_QWORD *)&dataDesc_5[162].override_field = 0;
    *(_QWORD *)&dataDesc_5[162].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[162].flatOffset[1] = 0;
    dataDesc_5[164].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[163].td = 0;
    *(_QWORD *)&dataDesc_5[163].override_field = 0;
    *(_QWORD *)&dataDesc_5[163].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[163].flatOffset[1] = 0;
    dataDesc_5[164].flags = 8;
    dataDesc_5[160].fieldType = FIELD_FLOAT;
    dataDesc_5[160].fieldName = "InputIgnoreDangerSounds";
    dataDesc_5[160].fieldOffset = 0;
    dataDesc_5[160].externalName = "IgnoreDangerSounds";
    dataDesc_5[160].pSaveRestoreOps = nullptr;
    dataDesc_5[160].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputIgnoreDangerSounds;
    dataDesc_5[161].fieldType = FIELD_VOID;
    dataDesc_5[161].fieldName = "InputBreak";
    dataDesc_5[161].fieldOffset = 0;
    dataDesc_5[161].externalName = "Break";
    dataDesc_5[161].pSaveRestoreOps = nullptr;
    dataDesc_5[161].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputBreak;
    dataDesc_5[162].fieldType = FIELD_VOID;
    dataDesc_5[162].fieldName = "InputStartScripting";
    dataDesc_5[162].fieldOffset = 0;
    dataDesc_5[162].externalName = "StartScripting";
    dataDesc_5[162].pSaveRestoreOps = nullptr;
    dataDesc_5[162].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputStartScripting;
    dataDesc_5[163].fieldType = FIELD_VOID;
    dataDesc_5[163].fieldName = "InputStopScripting";
    dataDesc_5[163].fieldOffset = 0;
    dataDesc_5[163].externalName = "StopScripting";
    dataDesc_5[163].pSaveRestoreOps = nullptr;
    dataDesc_5[163].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputStopScripting;
    dataDesc_5[164].fieldType = FIELD_VOID;
    dataDesc_5[164].fieldName = "InputGagEnable";
    dataDesc_5[164].fieldOffset = 0;
    dataDesc_5[164].externalName = "GagEnable";
    dataDesc_5[164].pSaveRestoreOps = nullptr;
    dataDesc_5[164].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputGagEnable;
    *(_QWORD *)&dataDesc_5[164].td = 0;
    *(_QWORD *)&dataDesc_5[164].override_field = 0;
    *(_QWORD *)&dataDesc_5[164].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[164].flatOffset[1] = 0;
    dataDesc_5[165].fieldType = FIELD_VOID;
    dataDesc_5[165].fieldName = "InputGagDisable";
    dataDesc_5[165].fieldOffset = 0;
    dataDesc_5[165].fieldSize = 1;
    dataDesc_5[165].flags = 8;
    dataDesc_5[166].fieldSize = 1;
    dataDesc_5[166].flags = 8;
    dataDesc_5[167].fieldSize = 1;
    dataDesc_5[167].flags = 8;
    dataDesc_5[168].fieldSize = 1;
    dataDesc_5[168].flags = 8;
    *(_QWORD *)&dataDesc_5[165].td = 0;
    *(_QWORD *)&dataDesc_5[165].override_field = 0;
    *(_QWORD *)&dataDesc_5[165].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[165].flatOffset[1] = 0;
    dataDesc_5[169].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[166].td = 0;
    *(_QWORD *)&dataDesc_5[166].override_field = 0;
    *(_QWORD *)&dataDesc_5[166].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[166].flatOffset[1] = 0;
    dataDesc_5[169].flags = 8;
    *(_QWORD *)&dataDesc_5[167].td = 0;
    *(_QWORD *)&dataDesc_5[167].override_field = 0;
    *(_QWORD *)&dataDesc_5[167].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[167].flatOffset[1] = 0;
    dataDesc_5[170].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[168].td = 0;
    *(_QWORD *)&dataDesc_5[168].override_field = 0;
    *(_QWORD *)&dataDesc_5[168].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[168].flatOffset[1] = 0;
    dataDesc_5[165].externalName = "GagDisable";
    dataDesc_5[165].pSaveRestoreOps = nullptr;
    dataDesc_5[165].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputGagDisable;
    dataDesc_5[166].fieldType = FIELD_VOID;
    dataDesc_5[166].fieldName = "InputInsideTransition";
    dataDesc_5[166].fieldOffset = 0;
    dataDesc_5[166].externalName = "InsideTransition";
    dataDesc_5[166].pSaveRestoreOps = nullptr;
    dataDesc_5[166].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CAI_BaseNPC::`vcall'{2100,{flat}};
    dataDesc_5[167].fieldType = FIELD_VOID;
    dataDesc_5[167].fieldName = "InputOutsideTransition";
    dataDesc_5[167].fieldOffset = 0;
    dataDesc_5[167].externalName = "OutsideTransition";
    dataDesc_5[167].pSaveRestoreOps = nullptr;
    dataDesc_5[167].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CAI_BaseNPC::`vcall'{2096,{flat}};
    dataDesc_5[168].fieldType = FIELD_VOID;
    dataDesc_5[168].fieldName = "InputActivateSpeedModifier";
    dataDesc_5[168].fieldOffset = 0;
    dataDesc_5[168].externalName = "ActivateSpeedModifier";
    dataDesc_5[168].pSaveRestoreOps = nullptr;
    dataDesc_5[168].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputActivateSpeedModifier;
    dataDesc_5[169].fieldType = FIELD_VOID;
    dataDesc_5[169].fieldName = "InputDisableSpeedModifier";
    dataDesc_5[169].fieldOffset = 0;
    dataDesc_5[169].externalName = "DisableSpeedModifier";
    dataDesc_5[169].pSaveRestoreOps = nullptr;
    dataDesc_5[169].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputDisableSpeedModifier;
    *(_QWORD *)&dataDesc_5[169].td = 0;
    *(_QWORD *)&dataDesc_5[169].override_field = 0;
    *(_QWORD *)&dataDesc_5[169].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[169].flatOffset[1] = 0;
    dataDesc_5[170].fieldType = FIELD_INTEGER;
    dataDesc_5[170].fieldName = "InputSetSpeedModifierRadius";
    dataDesc_5[170].fieldOffset = 0;
    dataDesc_5[170].flags = 8;
    dataDesc_5[170].externalName = "SetSpeedModRadius";
    dataDesc_5[170].pSaveRestoreOps = nullptr;
    dataDesc_5[170].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputSetSpeedModifierRadius;
    dataDesc_5[171].fieldType = FIELD_INTEGER;
    dataDesc_5[171].fieldSize = 1;
    dataDesc_5[171].flags = 8;
    dataDesc_5[172].fieldSize = 1;
    dataDesc_5[172].flags = 8;
    dataDesc_5[173].fieldSize = 1;
    dataDesc_5[173].flags = 8;
    *(_QWORD *)&dataDesc_5[170].td = 0;
    *(_QWORD *)&dataDesc_5[170].override_field = 0;
    *(_QWORD *)&dataDesc_5[170].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[170].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_5[171].td = 0;
    *(_QWORD *)&dataDesc_5[171].override_field = 0;
    *(_QWORD *)&dataDesc_5[171].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[171].flatOffset[1] = 0;
    dataDesc_5[174].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[172].td = 0;
    *(_QWORD *)&dataDesc_5[172].override_field = 0;
    *(_QWORD *)&dataDesc_5[172].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[172].flatOffset[1] = 0;
    dataDesc_5[174].flags = 8;
    *(_QWORD *)&dataDesc_5[173].td = 0;
    *(_QWORD *)&dataDesc_5[173].override_field = 0;
    *(_QWORD *)&dataDesc_5[173].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[173].flatOffset[1] = 0;
    dataDesc_5[175].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[174].td = 0;
    *(_QWORD *)&dataDesc_5[174].override_field = 0;
    *(_QWORD *)&dataDesc_5[174].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[174].flatOffset[1] = 0;
    dataDesc_5[171].fieldName = "InputSetSpeedModifierSpeed";
    dataDesc_5[171].fieldOffset = 0;
    dataDesc_5[171].externalName = "SetSpeedModSpeed";
    dataDesc_5[171].pSaveRestoreOps = nullptr;
    dataDesc_5[171].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputSetSpeedModifierSpeed;
    dataDesc_5[172].fieldType = FIELD_VOID;
    dataDesc_5[172].fieldName = "InputHolsterWeapon";
    dataDesc_5[172].fieldOffset = 0;
    dataDesc_5[172].externalName = "HolsterWeapon";
    dataDesc_5[172].pSaveRestoreOps = nullptr;
    dataDesc_5[172].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputHolsterWeapon;
    dataDesc_5[173].fieldType = FIELD_VOID;
    dataDesc_5[173].fieldName = "InputHolsterAndDestroyWeapon";
    dataDesc_5[173].fieldOffset = 0;
    dataDesc_5[173].externalName = "HolsterAndDestroyWeapon";
    dataDesc_5[173].pSaveRestoreOps = nullptr;
    dataDesc_5[173].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputHolsterAndDestroyWeapon;
    dataDesc_5[174].fieldType = FIELD_VOID;
    dataDesc_5[174].fieldName = "InputUnholsterWeapon";
    dataDesc_5[174].fieldOffset = 0;
    dataDesc_5[174].externalName = "UnholsterWeapon";
    dataDesc_5[174].pSaveRestoreOps = nullptr;
    dataDesc_5[174].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputUnholsterWeapon;
    dataDesc_5[175].fieldType = FIELD_STRING;
    dataDesc_5[175].fieldName = "InputForceInteractionWithNPC";
    dataDesc_5[175].fieldOffset = 0;
    dataDesc_5[175].flags = 8;
    dataDesc_5[175].externalName = "ForceInteractionWithNPC";
    dataDesc_5[175].pSaveRestoreOps = nullptr;
    dataDesc_5[175].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputForceInteractionWithNPC;
    *(_QWORD *)&dataDesc_5[175].td = 0;
    *(_QWORD *)&dataDesc_5[175].override_field = 0;
    *(_QWORD *)&dataDesc_5[175].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[175].flatOffset[1] = 0;
    dataDesc_5[176].fieldType = FIELD_STRING;
    dataDesc_5[176].fieldSize = 1;
    dataDesc_5[177].fieldSize = 1;
    *(_QWORD *)&dataDesc_5[176].td = 0;
    *(_QWORD *)&dataDesc_5[176].override_field = 0;
    *(_QWORD *)&dataDesc_5[176].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[176].flatOffset[1] = 0;
    dataDesc_5[177].flags = 8;
    dataDesc_5[176].fieldName = "InputUpdateEnemyMemory";
    dataDesc_5[176].fieldOffset = 0;
    dataDesc_5[176].flags = 8;
    dataDesc_5[176].externalName = "UpdateEnemyMemory";
    dataDesc_5[176].pSaveRestoreOps = nullptr;
    dataDesc_5[176].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputUpdateEnemyMemory;
    dataDesc_5[177].fieldType = FIELD_STRING;
    dataDesc_5[177].fieldName = "InputCreateAddon";
    dataDesc_5[177].fieldOffset = 0;
    dataDesc_5[177].externalName = "CreateAddon";
    dataDesc_5[177].pSaveRestoreOps = nullptr;
    dataDesc_5[177].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::InputCreateAddon;
    *(_QWORD *)&dataDesc_5[177].td = 0;
    *(_QWORD *)&dataDesc_5[177].override_field = 0;
    *(_QWORD *)&dataDesc_5[177].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[177].flatOffset[1] = 0;
    dataDesc_5[178].fieldType = FIELD_VOID;
    dataDesc_5[178].fieldName = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_5, pszIdentifier: "NPCUse");
    dataDesc_5[178].fieldOffset = 0;
    *(_DWORD *)&dataDesc_5[178].fieldSize = 2097153;
    dataDesc_5[178].externalName = nullptr;
    dataDesc_5[178].pSaveRestoreOps = nullptr;
    dataDesc_5[178].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CParticleSystemQuery::TraceAgainstRayTraceEnv;
    *(_QWORD *)&dataDesc_5[178].td = 0;
    *(_QWORD *)&dataDesc_5[178].override_field = 0;
    *(_QWORD *)&dataDesc_5[178].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[178].flatOffset[1] = 0;
    dataDesc_5[179].fieldType = FIELD_VOID;
    dataDesc_5[179].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_5,
                                  pszIdentifier: "CallNPCThink");
    dataDesc_5[179].fieldOffset = 0;
    *(_DWORD *)&dataDesc_5[179].fieldSize = 2097153;
    dataDesc_5[179].externalName = nullptr;
    dataDesc_5[179].pSaveRestoreOps = nullptr;
    dataDesc_5[179].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::CallNPCThink;
    *(_QWORD *)&dataDesc_5[179].td = 0;
    *(_QWORD *)&dataDesc_5[179].override_field = 0;
    *(_QWORD *)&dataDesc_5[179].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[179].flatOffset[1] = 0;
    dataDesc_5[180].fieldType = FIELD_VOID;
    dataDesc_5[180].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_5,
                                  pszIdentifier: "CorpseFallThink");
    dataDesc_5[180].fieldOffset = 0;
    *(_DWORD *)&dataDesc_5[180].fieldSize = 2097153;
    dataDesc_5[180].externalName = nullptr;
    dataDesc_5[180].pSaveRestoreOps = nullptr;
    dataDesc_5[180].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::CorpseFallThink;
    *(_QWORD *)&dataDesc_5[180].td = 0;
    *(_QWORD *)&dataDesc_5[180].override_field = 0;
    *(_QWORD *)&dataDesc_5[180].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[180].flatOffset[1] = 0;
    dataDesc_5[181].fieldType = FIELD_VOID;
    dataDesc_5[181].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_5,
                                  pszIdentifier: "NPCInitThink");
    dataDesc_5[181].fieldOffset = 0;
    *(_DWORD *)&dataDesc_5[181].fieldSize = 2097153;
    dataDesc_5[181].externalName = nullptr;
    dataDesc_5[181].pSaveRestoreOps = nullptr;
    dataDesc_5[181].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::NPCInitThink;
    *(_QWORD *)&dataDesc_5[181].td = 0;
    *(_QWORD *)&dataDesc_5[181].override_field = 0;
    *(_QWORD *)&dataDesc_5[181].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_5[181].flatOffset[1] = 0;
  }
  CAI_BaseNPC::m_DataMap.dataNumFields = 181;
  CAI_BaseNPC::m_DataMap.dataDesc = &dataDesc_5[1];
  return &CAI_BaseNPC::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FB1D0
// Name: _dynamic_initializer_for__g_CAI_BaseNPC_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CAI_BaseNPC_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CAI_BaseNPC_ClassReg,
           pNetworkName: "CAI_BaseNPC",
           pTable: &DT_AI_BaseNPC::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FB260
// Name: _dynamic_initializer_for__sv_test_scripted_sequences__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_test_scripted_sequences__()
{
  ConVar::ConVar(
    this: &sv_test_scripted_sequences,
    pName: "sv_test_scripted_sequences",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Tests for scripted sequences that are embedded in the world. Run through your map with this set to check for NPCs fa"
    "lling through the world.");
  return atexit(func: dynamic_atexit_destructor_for__sv_test_scripted_sequences__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB290
// Name: _dynamic_initializer_for__ai_LOS_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_LOS_mode__()
{
  ConVar::ConVar(this: &ai_LOS_mode, pName: "ai_LOS_mode", pDefaultValue: "0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ai_LOS_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10418B80
// Name: _dynamic_atexit_destructor_for__sv_test_scripted_sequences__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_test_scripted_sequences__()
{
  ConVar::~ConVar(this: &sv_test_scripted_sequences);
}

//------------------------------------------------------------------------------
// Address: 0x10418B90
// Name: _dynamic_atexit_destructor_for__ai_LOS_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_LOS_mode__()
{
  ConVar::~ConVar(this: &ai_LOS_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10418BA0
// Name: _dynamic_atexit_destructor_for__CAI_BaseNPC::gm_SchedulingSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CAI_BaseNPC::gm_SchedulingSymbols__()
{
  CAI_GlobalNamespace::~CAI_GlobalNamespace(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ConditionNamespace);
  CAI_GlobalNamespace::~CAI_GlobalNamespace(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_TaskNamespace);
  CAI_GlobalNamespace::~CAI_GlobalNamespace(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ScheduleNamespace);
}

//------------------------------------------------------------------------------
// Address: 0x10418BC0
// Name: _ServerClassInit_DT_AI_BaseNPC::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_AI_BaseNPC::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S8;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
