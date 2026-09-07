// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/baseflex.cpp
// Functions: 146
// ============================================================

#include "game\server\baseflex.h"

//------------------------------------------------------------------------------
// Address: 0x10042100
// Name: public: bool CAI_BaseNPC::GetBehavior<class CAI_AssaultBehavior>(class CAI_AssaultBehavior __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::GetBehavior<CAI_AssaultBehavior>(CAI_BaseNPC *this, CAI_AssaultBehavior **ppBehavior)
{
  CAI_BehaviorBase **v3; // ebx
  int v4; // esi
  CAI_AssaultBehavior *v5; // eax

  v3 = this->AccessBehaviors(this);
  *ppBehavior = nullptr;
  v4 = 0;
  if ( this->NumBehaviors(this) <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = (CAI_AssaultBehavior *)__RTDynamicCast(
                                  inptr: v3[v4],
                                  VfDelta: 0,
                                  SrcType: &CAI_BehaviorBase `RTTI Type Descriptor',
                                  TargetType: &CAI_AssaultBehavior `RTTI Type Descriptor',
                                  isReference: 0);
    *ppBehavior = v5;
    if ( v5 != nullptr )
      break;
    if ( ++v4 >= this->NumBehaviors(this) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10043980
// Name: public: bool CAI_BaseNPC::GetBehavior<class CAI_FightFromCoverBehavior>(class CAI_FightFromCoverBehavior __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::GetBehavior<CAI_FightFromCoverBehavior>(
        CAI_BaseNPC *this,
        CAI_FightFromCoverBehavior **ppBehavior)
{
  CAI_BehaviorBase **v3; // ebx
  int v4; // esi
  CAI_FightFromCoverBehavior *v5; // eax

  v3 = this->AccessBehaviors(this);
  *ppBehavior = nullptr;
  v4 = 0;
  if ( this->NumBehaviors(this) <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = (CAI_FightFromCoverBehavior *)__RTDynamicCast(
                                         inptr: v3[v4],
                                         VfDelta: 0,
                                         SrcType: &CAI_BehaviorBase `RTTI Type Descriptor',
                                         TargetType: &CAI_FightFromCoverBehavior `RTTI Type Descriptor',
                                         isReference: 0);
    *ppBehavior = v5;
    if ( v5 != nullptr )
      break;
    if ( ++v4 >= this->NumBehaviors(this) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10044A80
// Name: public: bool CAI_BaseNPC::GetBehavior<class CAI_FollowBehavior>(class CAI_FollowBehavior __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::GetBehavior<CAI_FollowBehavior>(CAI_BaseNPC *this, CAI_FollowBehavior **ppBehavior)
{
  CAI_BehaviorBase **v3; // ebx
  int v4; // esi
  CAI_FollowBehavior *v5; // eax

  v3 = this->AccessBehaviors(this);
  *ppBehavior = nullptr;
  v4 = 0;
  if ( this->NumBehaviors(this) <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = (CAI_FollowBehavior *)__RTDynamicCast(
                                 inptr: v3[v4],
                                 VfDelta: 0,
                                 SrcType: &CAI_BehaviorBase `RTTI Type Descriptor',
                                 TargetType: &CAI_FollowBehavior `RTTI Type Descriptor',
                                 isReference: 0);
    *ppBehavior = v5;
    if ( v5 != nullptr )
      break;
    if ( ++v4 >= this->NumBehaviors(this) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10047700
// Name: public: bool CAI_BaseNPC::GetBehavior<class CAI_LeadBehavior>(class CAI_LeadBehavior __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::GetBehavior<CAI_LeadBehavior>(CAI_BaseNPC *this, CAI_LeadBehavior **ppBehavior)
{
  CAI_BehaviorBase **v3; // ebx
  int v4; // esi
  CAI_LeadBehavior *v5; // eax

  v3 = this->AccessBehaviors(this);
  *ppBehavior = nullptr;
  v4 = 0;
  if ( this->NumBehaviors(this) <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = (CAI_LeadBehavior *)__RTDynamicCast(
                               inptr: v3[v4],
                               VfDelta: 0,
                               SrcType: &CAI_BehaviorBase `RTTI Type Descriptor',
                               TargetType: &CAI_LeadBehavior `RTTI Type Descriptor',
                               isReference: 0);
    *ppBehavior = v5;
    if ( v5 != nullptr )
      break;
    if ( ++v4 >= this->NumBehaviors(this) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100489B0
// Name: public: bool CAI_BaseNPC::GetBehavior<class CAI_StandoffBehavior>(class CAI_StandoffBehavior __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::GetBehavior<CAI_StandoffBehavior>(CAI_BaseNPC *this, CAI_StandoffBehavior **ppBehavior)
{
  CAI_BehaviorBase **v3; // ebx
  int v4; // esi
  CAI_StandoffBehavior *v5; // eax

  v3 = this->AccessBehaviors(this);
  *ppBehavior = nullptr;
  v4 = 0;
  if ( this->NumBehaviors(this) <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = (CAI_StandoffBehavior *)__RTDynamicCast(
                                   inptr: v3[v4],
                                   VfDelta: 0,
                                   SrcType: &CAI_BehaviorBase `RTTI Type Descriptor',
                                   TargetType: &CAI_StandoffBehavior `RTTI Type Descriptor',
                                   isReference: 0);
    *ppBehavior = v5;
    if ( v5 != nullptr )
      break;
    if ( ++v4 >= this->NumBehaviors(this) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CEF90
// Name: public: void CAI_BaseNPC::AddSceneLock(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::AddSceneLock(CAI_BaseNPC *this, float flDuration)
{
  float v2; // xmm0_4
  float m_flSceneTime; // xmm1_4

  v2 = gpGlobals->curtime + flDuration;
  m_flSceneTime = this->m_flSceneTime;
  if ( v2 <= m_flSceneTime )
    this->m_flSceneTime = m_flSceneTime;
  else
    this->m_flSceneTime = v2;
}

//------------------------------------------------------------------------------
// Address: 0x100CEFD0
// Name: void __near * SendProxy_FlexWeights(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl SendProxy_FlexWeights(const SendProp *pProp, const void *pStruct, const void *pVarData)
{
  return g_bClientFlex ? 0 : (unsigned int)pVarData;
}

//------------------------------------------------------------------------------
// Address: 0x100CEFF0
// Name: public: virtual class ServerClass __near * CBaseFlex::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseFlex::GetServerClass(CBaseFlex *this)
{
  return &g_CBaseFlex_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100CF000
// Name: public: virtual struct datamap_t __near * CBaseFlex::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseFlex::GetDataDescMap(CBaseFlex *this)
{
  return &CBaseFlex::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100CF010
// Name: public: virtual struct ScriptClassDesc_t __near * CBaseFlex::GetScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall CBaseFlex::GetScriptDesc(CBaseFlex *this)
{
  return GetScriptDesc(__formal: this);
}

//------------------------------------------------------------------------------
// Address: 0x100CF030
// Name: public: virtual bool CBaseFlex::ClearSceneEvent(class CSceneEventInfo __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::ClearSceneEvent(CBaseFlex *this, CSceneEventInfo *info, bool fastKill, bool canceled)
{
  CAI_BaseNPC *v6; // ebx
  vgui::Panel *Actor; // eax
  const char *Filename; // eax
  const char *Parameters; // eax
  double DmgModClub; // [esp+0h] [ebp-18h]
  const char *flKillRate; // [esp+8h] [ebp-10h]

  switch ( CChoreoEvent::GetType(this: info->m_pEvent) )
  {
    case EXPRESSION:
    case LOOKAT:
    case FACE:
    case FLEXANIMATION:
    case GENERIC:
    case CAMERA:
    case SCRIPT:
      return 1;
    case MOVETO:
      v6 = this->MyNPCPointer(this);
      if ( v6 != nullptr
        && this->IsMoving(this)
        && (canceled || CChoreoEvent::GetDistanceToTarget(this: info->m_pEvent) > 0.0) )
      {
        if ( !info->m_bHasArrived && info->m_pScene != nullptr )
        {
          Actor = (vgui::Panel *)CChoreoEvent::GetActor(this: info->m_pEvent);
          flKillRate = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: Actor);
          DmgModClub = CBreakableProp::GetDmgModClub(this: info->m_pScene);
          Filename = CChoreoScene::GetFilename(this: info->m_pScene);
          Scene_Printf(
            pFormat: "%s : %8.2f: MOVETO canceled but actor %s not at goal\n",
            Filename,
            DmgModClub,
            flKillRate);
        }
        CAI_Navigator::StopMoving(this: v6->m_pNavigator, bImmediate: false);
      }
      return 1;
    case SPEAK:
      if ( canceled )
      {
        Parameters = CChoreoEvent::GetParameters(this: info->m_pEvent);
        CBaseEntity::StopSound(this, soundname: Parameters);
      }
      return 1;
    case GESTURE:
    case SEQUENCE:
      if ( info->m_iLayer < 0 )
        return 1;
      if ( fastKill )
      {
        CBaseAnimatingOverlay::FastRemoveLayer(this, iLayer: info->m_iLayer);
        return 1;
      }
      else if ( CChoreoEvent::GetType(this: info->m_pEvent) == GESTURE )
      {
        if ( canceled )
          CBaseAnimatingOverlay::RemoveLayer(this, iLayer: info->m_iLayer, flKillRate: 0.5, flKillDelay: 0.0);
        else
          CBaseAnimatingOverlay::RemoveLayer(this, iLayer: info->m_iLayer, flKillRate: 0.1, flKillDelay: 0.0);
        return 1;
      }
      else
      {
        CBaseAnimatingOverlay::RemoveLayer(this, iLayer: info->m_iLayer, flKillRate: 0.30000001, flKillDelay: 0.0);
        return 1;
      }
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF1E0
// Name: private: bool CBaseFlex::StartFacingSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *,class CChoreoActor __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::StartFacingSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event,
        CChoreoActor *actor,
        CBaseEntity *pTarget)
{
  CAI_BaseNPC *v6; // eax

  if ( pTarget == nullptr )
    return 0;
  v6 = this->MyNPCPointer(this);
  if ( v6 != nullptr && v6->IsInAVehicle(this: v6) )
    return 0;
  info->m_bIsMoving = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CF220
// Name: public: virtual bool CBaseFlex::CheckSceneEventCompletion(class CSceneEventInfo __near *,float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::CheckSceneEventCompletion(
        CBaseFlex *this,
        CSceneEventInfo *info,
        float currenttime,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  CAI_BaseNPC *v6; // eax
  CAI_BaseNPC *v7; // esi
  const Task_t *Task; // eax
  int iTask; // eax
  double v10; // st7
  double v11; // st7
  vgui::Panel *Actor; // eax
  const char *Filename; // eax
  double DmgModClub; // [esp+0h] [ebp-14h]
  const char *v16; // [esp+8h] [ebp-Ch]
  float t; // [esp+20h] [ebp+Ch]
  float preload; // [esp+28h] [ebp+14h]

  if ( CChoreoEvent::GetType(this: event) == MOVETO )
  {
    v6 = this->MyNPCPointer(this);
    v7 = v6;
    if ( v6 != nullptr )
    {
      if ( CAI_Navigator::IsGoalActive(this: v6->m_pNavigator) )
      {
        Task = CAI_BaseNPC::GetTask(this: v7);
        if ( Task == nullptr )
          return 0;
        iTask = Task->iTask;
        if ( iTask != 122 && iTask != 130 )
          return 0;
        v10 = CChoreoEvent::GetEndTime(this: event) - currenttime;
        preload = v10;
        if ( v10 < 0.0 )
          return 0;
        v11 = ((double (__thiscall *)(CAI_BaseNPC *))v7->GetTimeToNavGoal)(a1: v7);
        if ( v11 <= 0.0 )
          return 0;
        t = v11;
        if ( preload < t )
          return 0;
      }
      else if ( !info->m_bHasArrived )
      {
        if ( !info->m_bStarted || CAI_BaseNPC::IsCurSchedule(this: v7, schedId: 63, fIdeal: true) )
          return 0;
        Actor = (vgui::Panel *)CChoreoEvent::GetActor(this: event);
        v16 = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: Actor);
        DmgModClub = CBreakableProp::GetDmgModClub(this: scene);
        Filename = CChoreoScene::GetFilename(this: scene);
        _Warning(
          a1: "%s : %8.2f: waiting for actor %s to complete MOVETO but actor not in SCHED_SCENE_GENERIC\n",
          Filename,
          DmgModClub,
          v16);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CF320
// Name: DetermineExpressionMoveActivity
// Source: json
//------------------------------------------------------------------------------
Activity __cdecl DetermineExpressionMoveActivity(CAI_BaseNPC *pNPC)
{
  CChoreoEvent *event; // ecx
  const char *Parameters2; // eax
  char *v3; // esi
  char *v4; // edi
  Activity result; // eax
  char szActName[256]; // [esp+4h] [ebp-104h] BYREF
  char pszValue[4]; // [esp+104h] [ebp-4h] BYREF

  Parameters2 = CChoreoEvent::GetParameters2(this: event);
  v3 = (char *)Parameters2;
  if ( Parameters2 == nullptr || *Parameters2 == 0 )
    return ACT_WALK;
  v4 = _V_strstr(s1: Parameters2, search: " ");
  if ( v4 != nullptr )
  {
    V_strncpy(pDest: szActName, pSrc: v3, maxLen: 256);
    szActName[v4 - v3] = 0;
    v3 = szActName;
  }
  if ( _V_stricmp(s1: v3, s2: "Walk") == 0 )
    return ACT_WALK;
  if ( _V_stricmp(s1: v3, s2: "Run") == 0 )
    return ACT_RUN;
  if ( _V_stricmp(s1: v3, s2: "CrouchWalk") == 0 )
    return ACT_WALK_CROUCH;
  result = ActivityList_IndexForName(pszActivityName: v3);
  if ( result == ACT_INVALID )
  {
    pNPC->m_iszSceneCustomMoveSeq.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
    return ACT_SCRIPT_CUSTOM_MOVE;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CF410
// Name: public: bool CBaseFlex::PermitResponse(float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseFlex::PermitResponse(CBaseFlex *this, float response_length)
{
  float m_flAllowResponsesEndTime; // xmm0_4

  m_flAllowResponsesEndTime = this->m_flAllowResponsesEndTime;
  return m_flAllowResponsesEndTime > 0.0 && m_flAllowResponsesEndTime >= (float)(gpGlobals->curtime + response_length);
}

//------------------------------------------------------------------------------
// Address: 0x100CF450
// Name: public: void CBaseFlex::SetPermitResponse(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::SetPermitResponse(CBaseFlex *this, float endtime)
{
  this->m_flAllowResponsesEndTime = endtime;
}

//------------------------------------------------------------------------------
// Address: 0x100CF470
// Name: public: virtual float CBaseFlex::PlayScene(char const __near *,float,class ResponseRules::CRR_Response __near *,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CBaseFlex::PlayScene(
        CBaseFlex *this,
        const char *pszScene,
        float flDelay,
        ResponseRules::CRR_Response *response,
        IRecipientFilter *filter)
{
  return InstancedScriptedScene(
           pActor: this,
           pszScene,
           phSceneEnt: nullptr,
           flPostDelay: flDelay,
           bIsBackground: false,
           response,
           bMultiplayer: false,
           filter);
}

//------------------------------------------------------------------------------
// Address: 0x100CF4A0
// Name: public: virtual float CBaseFlex::ScriptPlayScene(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CBaseFlex::ScriptPlayScene(CBaseFlex *this, const char *pszScene, float flDelay)
{
  return InstancedScriptedScene(
           pActor: this,
           pszScene,
           phSceneEnt: nullptr,
           flPostDelay: flDelay,
           bIsBackground: false,
           response: nullptr,
           bMultiplayer: false,
           filter: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100CF4D0
// Name: public: virtual float CBaseFlex::PlayAutoGeneratedSoundScene(char const __near *)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CBaseFlex::PlayAutoGeneratedSoundScene(CBaseFlex *this, const char *soundname)
{
  return InstancedAutoGeneratedSoundScene(pActor: this, soundname, phSceneEnt: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100CF4F0
// Name: public: bool CBaseFlex::IsSuppressedFlexAnimation(class CSceneEventInfo __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseFlex::IsSuppressedFlexAnimation(CBaseFlex *this, CSceneEventInfo *info)
{
  CChoreoScene *m_pScene; // ecx
  double m_flLastFlexAnimationTime; // st6
  double curtime; // [esp+Ch] [ebp-8h]

  m_pScene = info->m_pScene;
  if ( m_pScene != nullptr && CChoreoScene::IsBackground(this: m_pScene) )
  {
    curtime = gpGlobals->curtime;
    m_flLastFlexAnimationTime = this->m_flLastFlexAnimationTime;
    return m_flLastFlexAnimationTime > curtime - CBaseAnimating::GetAnimTimeInterval(this) * 1.5;
  }
  else
  {
    this->m_flLastFlexAnimationTime = gpGlobals->curtime;
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF570
// Name: public: virtual void CBaseFlex::Teleport(class Vector const __near *,class QAngle const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::Teleport(
        CBaseFlex *this,
        const Vector *newPosition,
        const QAngle *newAngles,
        const Vector *newVelocity,
        bool bUseSlowHighAccuracyContacts)
{
  CBaseAnimating::Teleport(this, newPosition, newAngles, newVelocity, bUseSlowHighAccuracyContacts);
}

//------------------------------------------------------------------------------
// Address: 0x100CF580
// Name: public: void CSceneEventInfo::InitWeight(class CBaseFlex __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEventInfo::InitWeight(CSceneEventInfo *this, CBaseFlex *pActor)
{
  if ( CBaseFlex::IsSuppressedFlexAnimation(this: pActor, info: this) )
    this->m_flWeight = 0.0;
  else
    this->m_flWeight = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100CF5C0
// Name: public: float CSceneEventInfo::UpdateWeight(class CBaseFlex __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSceneEventInfo::UpdateWeight(CSceneEventInfo *this, CBaseFlex *pActor)
{
  bool IsSuppressedFlexAnimation; // al
  double m_flWeight; // xmm0_8
  double v5; // xmm0_8
  __int64 v6; // xmm1_8
  bool v7; // cc

  IsSuppressedFlexAnimation = CBaseFlex::IsSuppressedFlexAnimation(this: pActor, info: this);
  m_flWeight = this->m_flWeight;
  if ( IsSuppressedFlexAnimation )
  {
    v5 = m_flWeight - 0.2;
    v6 = 0;
    v7 = v5 <= 0.0;
  }
  else
  {
    v5 = m_flWeight + 0.1;
    v6 = 0x3FF0000000000000LL;
    v7 = v5 >= 1.0;
  }
  if ( v7 )
    v5 = *(double *)&v6;
  this->m_flWeight = v5;
  return this->m_flWeight;
}

//------------------------------------------------------------------------------
// Address: 0x100CF620
// Name: public: virtual struct datamap_t __near * CFlexCycler::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFlexCycler::GetDataDescMap(CFlexCycler *this)
{
  return &CFlexCycler::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100CF630
// Name: float clamp<float,int,double>(float const __near &,int const __near &,double const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,int,double>(float *val, const int *minVal, const long double *maxVal)
{
  float v3; // xmm1_4
  float vala; // [esp+10h] [ebp+8h]

  v3 = (float)*minVal;
  vala = *val;
  if ( v3 > vala )
    return v3;
  if ( vala <= *(double *)maxVal )
    return vala;
  return *(double *)maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x100CF680
// Name: public: int mstudioseqdesc_t::anim(int,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mstudioseqdesc_t::anim(mstudioseqdesc_t *this, int x, int y)
{
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // edx

  v3 = this->groupsize[0];
  v4 = x;
  if ( x >= v3 )
    v4 = v3 - 1;
  v5 = this->groupsize[1];
  v6 = y;
  if ( y >= v5 )
    v6 = v5 - 1;
  return *(__int16 *)((char *)&this->baseptr + 2 * v4 + 2 * v6 * v3 + this->animindexindex);
}

//------------------------------------------------------------------------------
// Address: 0x100CF6C0
// Name: public: enum LocalFlexController_t CBaseFlex::FindFlexController(char const __near *)
// Source: json
//------------------------------------------------------------------------------
LocalFlexController_t __thiscall CBaseFlex::FindFlexController(CBaseFlex *this, const char *szName)
{
  LocalFlexController_t v3; // esi
  const char *FlexControllerName; // eax

  v3 = DUMMY_NULL_FLEX_CONTROLLER;
  if ( CBaseAnimating::GetNumFlexControllers(this) <= 0 )
    return DUMMY_NULL_FLEX_CONTROLLER;
  while ( 1 )
  {
    FlexControllerName = CBaseAnimating::GetFlexControllerName(this, iFlexController: v3);
    if ( _V_stricmp(s1: FlexControllerName, s2: szName) == 0 )
      break;
    if ( ++v3 >= CBaseAnimating::GetNumFlexControllers(this) )
      return DUMMY_NULL_FLEX_CONTROLLER;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100CF710
// Name: public: CSceneEventInfo::CSceneEventInfo(class CSceneEventInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
CSceneEventInfo *__thiscall CSceneEventInfo::CSceneEventInfo(CSceneEventInfo *this, const CSceneEventInfo *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CF7A0
// Name: public: void CFlexCycler::SetFlexTarget(enum LocalFlexController_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFlexCycler::SetFlexTarget(CFlexCycler *this@<ecx>, int a2@<edi>, LocalFlexController_t flexnum)
{
  LocalFlexController_t v5; // edi
  const char *FlexControllerType; // eax
  const char *FlexControllerName; // eax
  const char *v8; // eax
  const char *pszType; // [esp+14h] [ebp-4h]
  float *flexnuma; // [esp+20h] [ebp+8h]

  this->m_flextarget[flexnum] = ((double (__thiscall *)(IUniformRandomStream *, int, int, int))random->RandomFloat)(
                                  a1: random,
                                  a2: 1056964608,
                                  a3: 1065353216,
                                  a4: a2);
  pszType = CBaseAnimating::GetFlexControllerType(this, iFlexController: flexnum);
  v5 = DUMMY_NULL_FLEX_CONTROLLER;
  if ( CBaseAnimating::GetNumFlexControllers(this) > 0 )
  {
    flexnuma = this->m_flextarget;
    do
    {
      if ( v5 != flexnum )
      {
        FlexControllerType = CBaseAnimating::GetFlexControllerType(this, iFlexController: v5);
        if ( _V_stricmp(s1: pszType, s2: FlexControllerType) == 0 )
          *flexnuma = 0.0;
      }
      ++flexnuma;
      ++v5;
    }
    while ( v5 < CBaseAnimating::GetNumFlexControllers(this) );
  }
  FlexControllerName = CBaseAnimating::GetFlexControllerName(this, iFlexController: flexnum);
  if ( strncmp(first: "right_", last: FlexControllerName, count: 6u) == 0 )
  {
    this->m_flextarget[flexnum + 1] = this->m_flextarget[flexnum];
  }
  else
  {
    v8 = CBaseAnimating::GetFlexControllerName(this, iFlexController: flexnum);
    if ( strncmp(first: "left_", last: v8, count: 5u) == 0 )
      *((float *)&this->m_flexnum + flexnum) = this->m_flextarget[flexnum];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFA50
// Name: public: void CBaseFlex::NetworkVar_m_flexWeight::Set(int,float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::NetworkVar_m_flexWeight::Set(
        CBaseFlex::NetworkVar_m_flexWeight *this,
        int i,
        const float *val)
{
  char *v4; // eax
  CBaseEdict *v5; // ecx

  if ( LODWORD(this->m_Value[i]) != *(_DWORD *)val )
  {
    v4 = (char *)this - 1184;
    if ( *((_BYTE *)this - 1100) != 0 )
    {
      v4[88] |= 1u;
      this->m_Value[i] = *val;
    }
    else
    {
      v5 = *((CBaseEdict **)v4 + 6);
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: (_WORD)this + 4 * i - (_WORD)v4);
      this->m_Value[i] = *val;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFC00
// Name: public: void CBaseFlex::SetFlexWeight(enum LocalFlexController_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::SetFlexWeight(CBaseFlex *this, LocalFlexController_t index, float value)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  __int32 v6; // ecx
  float v7; // xmm1_4
  float *v8; // ecx
  float v9; // xmm0_4
  int v10; // xmm1_4

  if ( index >= DUMMY_NULL_FLEX_CONTROLLER && index < CBaseAnimating::GetNumFlexControllers(this) )
  {
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      v5 = m_pStudioHdr->m_pStudioHdr;
      v6 = v5->flexcontrollerindex + 20 * index;
      v7 = *(float *)&v5->name[v6 + 4];
      v8 = (float *)((char *)&v5->id + v6);
      if ( v7 != v8[3] )
      {
        v9 = (float)(value - v8[3]) / (float)(v7 - v8[3]);
        v10 = 0;
        if ( v9 < 0.0 || (v10 = 1065353216, v9 > 1.0) )
          v9 = *(float *)&v10;
        value = v9;
      }
      CBaseFlex::NetworkVar_m_flexWeight::Set(this: &this->m_flexWeight, i: index, val: &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFCB0
// Name: public: float CBaseFlex::GetFlexWeight(enum LocalFlexController_t)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseFlex::GetFlexWeight(CBaseFlex *this, LocalFlexController_t index)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  __int32 v5; // ecx
  float v6; // xmm0_4
  float *v7; // ecx

  if ( index < DUMMY_NULL_FLEX_CONTROLLER || index >= CBaseAnimating::GetNumFlexControllers(this) )
    return 0.0;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0.0;
  v4 = m_pStudioHdr->m_pStudioHdr;
  v5 = v4->flexcontrollerindex + 20 * index;
  v6 = *(float *)&v4->name[v5 + 4];
  v7 = (float *)((char *)&v4->id + v5);
  if ( v6 == v7[3] )
    return this->m_flexWeight.m_Value[index];
  else
    return v7[3] + (v6 - v7[3]) * this->m_flexWeight.m_Value[index];
}

//------------------------------------------------------------------------------
// Address: 0x100CFD50
// Name: public: int CBaseFlex::GetScenePriority(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFlex::GetScenePriority(CBaseFlex *this, CChoreoScene *scene)
{
  int m_Size; // ebx
  int result; // eax
  int v5; // esi
  CChoreoScene *v6; // ecx
  int iPriority; // [esp+Ch] [ebp-4h]

  m_Size = this->m_ActiveChoreoScenes.m_Size;
  result = 0;
  v5 = 0;
  for ( iPriority = 0; v5 < m_Size; ++v5 )
  {
    v6 = this->m_ActiveChoreoScenes.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      if ( v6 == scene )
        return result;
      iPriority += CChoreoScene::GetNumChannels(this: v6);
      result = iPriority;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CFDA0
// Name: private: bool CBaseFlex::RequestStartSequenceSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *,class CChoreoActor __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::RequestStartSequenceSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event,
        CChoreoActor *actor,
        CBaseEntity *pTarget)
{
  const char *Parameters; // eax
  int v8; // eax
  const char *pszValue; // esi
  const char *v10; // eax
  const char *v12; // [esp-4h] [ebp-Ch]

  Parameters = CChoreoEvent::GetParameters(this: event);
  v8 = CBaseAnimating::LookupSequence(this, label: Parameters);
  info->m_nSequence = v8;
  if ( v8 >= 0 )
  {
    info->m_pActor = actor;
    info->m_iLayer = -2;
    return 1;
  }
  else
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v12 = CChoreoEvent::GetParameters(this: event);
    v10 = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: (vgui::Panel *)actor);
    _Warning(a1: "CSceneEntity %s :\"%s\" unable to find sequence \"%s\"\n", pszValue, v10, v12);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFE10
// Name: private: bool CBaseFlex::RequestStartGestureSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *,class CChoreoActor __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::RequestStartGestureSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event,
        CChoreoActor *actor,
        CBaseEntity *pTarget)
{
  const char *Parameters; // eax
  int v8; // eax
  const char *pszValue; // esi
  const char *v10; // eax
  const char *v12; // [esp-4h] [ebp-Ch]

  Parameters = CChoreoEvent::GetParameters(this: event);
  v8 = CBaseAnimating::LookupSequence(this, label: Parameters);
  info->m_nSequence = v8;
  if ( v8 >= 0 )
  {
    info->m_pActor = actor;
    info->m_iLayer = -2;
    return 1;
  }
  else
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v12 = CChoreoEvent::GetParameters(this: event);
    v10 = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: (vgui::Panel *)actor);
    _Warning(a1: "CSceneEntity %s :\"%s\" unable to find gesture \"%s\"\n", pszValue, v10, v12);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFE80
// Name: private: bool CBaseFlex::HandleStartGestureSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *,class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::HandleStartGestureSceneEvent(
        CBaseFlex *this,
        float info,
        CChoreoScene *scene,
        float event,
        CChoreoActor *actor)
{
  CChoreoEvent *v5; // edi
  CBaseFlex *v6; // ebx
  const char *Parameters; // eax
  int v8; // eax
  CSceneEventInfo *v9; // esi
  const char *pszValue; // ebx
  const char *v11; // eax
  KeyValues *SequenceKeyValues; // eax
  KeyValues *Key; // eax
  KeyValues *v15; // eax
  const char *String; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  char *v19; // eax
  char *v20; // edx
  char v21; // cl
  const char *v22; // eax
  char *v23; // eax
  char *v24; // edx
  char v25; // cl
  CEventAbsoluteTag *AbsoluteTag; // eax
  CEventAbsoluteTag *v27; // eax
  CEventAbsoluteTag *v28; // eax
  CEventAbsoluteTag *v29; // eax
  CStudioHdr *m_pStudioHdr; // ebx
  CStudioHdr *v31; // esi
  int v32; // eax
  const studiohdr_t *v33; // ecx
  mstudioseqdesc_t *v34; // eax
  int v35; // ecx
  int v36; // edx
  int v37; // edi
  int v38; // ebx
  int v39; // eax
  const studiohdr_t *v40; // esi
  KeyValues *FirstSubKey; // eax
  CChoreoEvent *v42; // ebx
  const char *v43; // eax
  KeyValues *j; // edi
  int v45; // esi
  const char *v46; // eax
  CEventAbsoluteTag *v47; // eax
  CEventAbsoluteTag *v48; // esi
  double v49; // st7
  const char *v50; // eax
  CChoreoEvent *v51; // esi
  const char *v52; // eax
  int v53; // xmm0_4
  CChoreoEvent *v54; // ecx
  CChoreoChannel *Channel; // eax
  int ChannelIndex; // eax
  int m_Size; // edi
  int v58; // esi
  CChoreoScene *v59; // ecx
  int NumChannels; // eax
  CSceneEventInfo *v61; // esi
  int v62; // eax
  CChoreoEvent *v63; // edi
  CStudioHdr *v64; // eax
  const char *v65; // eax
  const char *v66; // eax
  double StartTime; // st7
  const char *v68; // [esp-4h] [ebp-140h]
  double v69; // [esp+0h] [ebp-13Ch]
  double v70; // [esp+8h] [ebp-134h]
  const char *Filename; // [esp+10h] [ebp-12Ch]
  const char *v72; // [esp+10h] [ebp-12Ch]
  const char *v73; // [esp+14h] [ebp-128h]
  const char *v74; // [esp+14h] [ebp-128h]
  const char *flDuration; // [esp+18h] [ebp-124h]
  const char *flDurationa; // [esp+18h] [ebp-124h]
  const char *flDurationb; // [esp+18h] [ebp-124h]
  float flDurationc; // [esp+18h] [ebp-124h]
  const char *flDurationd; // [esp+18h] [ebp-124h]
  char szEndLoop[128]; // [esp+28h] [ebp-114h] BYREF
  char szStartLoop[128]; // [esp+A8h] [ebp-94h] BYREF
  mstudioanimdesc_t *animdesc; // [esp+128h] [ebp-14h]
  KeyValues *seqKeyValues; // [esp+12Ch] [ebp-10h]
  CBaseFlex *v84; // [esp+130h] [ebp-Ch]
  float percentage; // [esp+134h] [ebp-8h]
  KeyValues *pkvFaceposer; // [esp+138h] [ebp-4h]

  v5 = (CChoreoEvent *)LODWORD(event);
  v6 = this;
  v84 = this;
  Parameters = CChoreoEvent::GetParameters(this: (CChoreoEvent *)LODWORD(event));
  v8 = CBaseAnimating::LookupSequence(this: v6, label: Parameters);
  v9 = (CSceneEventInfo *)LODWORD(info);
  *(_DWORD *)(LODWORD(info) + 28) = v8;
  v9->m_iLayer = -1;
  if ( v8 >= 0 )
  {
    v9->m_bIsGesture = false;
    SequenceKeyValues = CBaseAnimating::GetSequenceKeyValues(this: v6, iSequence: v8);
    seqKeyValues = SequenceKeyValues;
    if ( SequenceKeyValues != nullptr )
    {
      Key = KeyValues::FindKey(this: SequenceKeyValues, keyName: "faceposer", bCreate: false);
      pkvFaceposer = Key;
      if ( Key != nullptr )
      {
        v15 = KeyValues::FindKey(this: Key, keyName: "type", bCreate: false);
        if ( v15 != nullptr )
        {
          String = KeyValues::GetString(this: v15, keyName: nullptr, defaultValue: locale);
          v9->m_bIsGesture = _V_stricmp(s1: String, s2: "gesture") == 0;
        }
      }
      strcpy(szStartLoop, "loop");
      memset(dst: (unsigned __int8 *)&szStartLoop[5], value: 0, count: 0x7Bu);
      strcpy(szEndLoop, "end");
      memset(dst: (unsigned __int8 *)&szEndLoop[4], value: 0, count: 0x7Cu);
      for ( i = KeyValues::GetFirstSubKey(this: pkvFaceposer); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: Name, s2: "startloop") != 0 )
        {
          v22 = KeyValues::GetName(this: i);
          if ( _V_stricmp(s1: v22, s2: "endloop") == 0 )
          {
            v23 = (char *)KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
            v24 = (char *)(szEndLoop - v23);
            do
            {
              v25 = *v23;
              v23[(_DWORD)v24] = *v23;
              ++v23;
            }
            while ( v25 != 0 );
          }
        }
        else
        {
          v19 = (char *)KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
          v20 = (char *)(szStartLoop - v19);
          do
          {
            v21 = *v19;
            v19[(_DWORD)v20] = *v19;
            ++v19;
          }
          while ( v21 != 0 );
        }
      }
      AbsoluteTag = CChoreoEvent::FindAbsoluteTag(this: v5, type: ORIGINAL, tagname: szStartLoop);
      if ( AbsoluteTag != nullptr )
        CEventAbsoluteTag::SetLinear(this: AbsoluteTag, bLinear: true);
      v27 = CChoreoEvent::FindAbsoluteTag(this: v5, type: PLAYBACK, tagname: szStartLoop);
      if ( v27 != nullptr )
        CEventAbsoluteTag::SetLinear(this: v27, bLinear: true);
      v28 = CChoreoEvent::FindAbsoluteTag(this: v5, type: ORIGINAL, tagname: szEndLoop);
      if ( v28 != nullptr )
        CEventAbsoluteTag::SetLinear(this: v28, bLinear: true);
      v29 = CChoreoEvent::FindAbsoluteTag(this: v5, type: PLAYBACK, tagname: szEndLoop);
      if ( v29 != nullptr )
        CEventAbsoluteTag::SetLinear(this: v29, bLinear: true);
      if ( pkvFaceposer != nullptr )
      {
        if ( v6->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v6) != nullptr )
          CBaseAnimating::LockStudioHdr(this: v6);
        m_pStudioHdr = v6->m_pStudioHdr;
        if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
          v31 = m_pStudioHdr;
        else
          v31 = nullptr;
        v32 = *(_DWORD *)(LODWORD(info) + 28);
        if ( v31->m_pVModel != nullptr )
        {
          v34 = CStudioHdr::pSeqdesc_Internal(this: v31, i: *(_DWORD *)(LODWORD(info) + 28));
        }
        else
        {
          v33 = v31->m_pStudioHdr;
          if ( v32 < 0 || v32 >= v33->numlocalseq )
            v32 = 0;
          v34 = (mstudioseqdesc_t *)((char *)v33 + 212 * v32 + v33->localseqindex);
        }
        v35 = v34->groupsize[0];
        v36 = 0;
        v37 = 0;
        if ( v35 <= 0 )
          v37 = v35 - 1;
        v38 = v34->groupsize[1];
        if ( v38 <= 0 )
          v36 = v38 - 1;
        v39 = *(__int16 *)((char *)&v34->baseptr + 2 * v37 + 2 * v36 * v35 + v34->animindexindex);
        if ( v31->m_pVModel != nullptr
          && (v39 = CStudioHdr::iRelativeAnim_Internal(
                      this: v31,
                      baseseq: *(_DWORD *)(LODWORD(info) + 28),
                      relanim: v39),
              v31->m_pVModel != nullptr) )
        {
          animdesc = CStudioHdr::pAnimdesc_Internal(this: v31, i: v39);
        }
        else
        {
          v40 = v31->m_pStudioHdr;
          if ( v39 < 0 || v39 >= v40->numlocalanim )
            v39 = 0;
          animdesc = (mstudioanimdesc_t *)((char *)v40 + 100 * v39 + v40->localanimindex);
        }
        FirstSubKey = KeyValues::GetFirstSubKey(this: pkvFaceposer);
        v42 = (CChoreoEvent *)LODWORD(event);
        for ( pkvFaceposer = FirstSubKey; pkvFaceposer != nullptr; pkvFaceposer = KeyValues::GetNextKey(this: pkvFaceposer) )
        {
          v43 = KeyValues::GetName(this: pkvFaceposer);
          if ( _V_stricmp(s1: v43, s2: "tags") == 0 )
          {
            for ( j = KeyValues::GetFirstSubKey(this: pkvFaceposer); j != nullptr; j = KeyValues::GetNextKey(this: j) )
            {
              if ( animdesc->numframes - 2 > 0 )
              {
                v45 = animdesc->numframes - 2;
                percentage = (float)KeyValues::GetInt(this: j, keyName: nullptr, defaultValue: 0) / (float)v45;
                v46 = KeyValues::GetName(this: j);
                v47 = CChoreoEvent::FindAbsoluteTag(this: v42, type: ORIGINAL, tagname: v46);
                v48 = v47;
                if ( v47 != nullptr )
                {
                  v49 = CEventAbsoluteTag::GetPercentage(this: v47);
                  if ( fabs(v49 - percentage) > 0.05 )
                  {
                    flDurationa = CChoreoEvent::GetParameters(this: v42);
                    v73 = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: (vgui::Panel *)actor);
                    Filename = CChoreoScene::GetFilename(this: scene);
                    v70 = percentage;
                    v69 = CEventAbsoluteTag::GetPercentage(this: v48);
                    v68 = KeyValues::GetName(this: j);
                    v50 = CChoreoScene::GetFilename(this: scene);
                    DevWarning(
                      a1: "%s repositioned tag: %s : %.3f -> %.3f (%s:%s:%s)\n",
                      v50,
                      v68,
                      v69,
                      v70,
                      Filename,
                      v73,
                      flDurationa);
                    CEventAbsoluteTag::SetPercentage(this: v48, percentage);
                  }
                }
              }
            }
          }
        }
        if ( !CChoreoEvent::VerifyTagOrder(this: v42) )
        {
          v51 = (CChoreoEvent *)LODWORD(event);
          flDurationb = CChoreoEvent::GetParameters(this: (CChoreoEvent *)LODWORD(event));
          v74 = CChoreoEvent::GetName(this: v51);
          v72 = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: (vgui::Panel *)actor);
          v52 = CChoreoScene::GetFilename(this: scene);
          DevWarning(a1: "out of order tags : %s : (%s:%s:%s)\n", v52, v72, v74, flDurationb);
        }
        v6 = v84;
      }
      KeyValues::deleteThis(this: seqKeyValues);
      v9 = (CSceneEventInfo *)LODWORD(info);
    }
    if ( v9->m_bIsGesture || !v6->IsMoving(this: v6) )
      v53 = 1065353216;
    else
      v53 = 0;
    v54 = (CChoreoEvent *)LODWORD(event);
    LODWORD(v9->m_flWeight) = v53;
    Channel = CChoreoEvent::GetChannel(this: v54);
    ChannelIndex = CChoreoActor::FindChannelIndex(this: actor, channel: Channel);
    *(_DWORD *)(LODWORD(info) + 24) = ChannelIndex;
    m_Size = v6->m_ActiveChoreoScenes.m_Size;
    v58 = 0;
    for ( actor = nullptr; v58 < m_Size; ++v58 )
    {
      v59 = v6->m_ActiveChoreoScenes.m_Memory.m_pMemory[v58];
      if ( v59 != nullptr )
      {
        if ( v59 == scene )
          break;
        NumChannels = CChoreoScene::GetNumChannels(this: v59);
        actor = (CChoreoActor *)((char *)actor + NumChannels);
      }
    }
    v61 = (CSceneEventInfo *)LODWORD(info);
    v62 = CBaseAnimatingOverlay::AddLayeredSequence(
            this: v6,
            sequence: *(_DWORD *)(LODWORD(info) + 28),
            iPriority: (int)&actor->m_szName[*(_DWORD *)(LODWORD(info) + 24)]);
    v61->m_iLayer = v62;
    CBaseAnimatingOverlay::SetLayerNoRestore(this: v6, iLayer: v62, bNoRestore: true);
    v63 = (CChoreoEvent *)LODWORD(event);
    flDurationc = ((double (__thiscall *)(_DWORD))**(_DWORD **)LODWORD(event))(a1: LODWORD(event));
    CBaseAnimatingOverlay::SetLayerDuration(this: v6, iLayer: v61->m_iLayer, flDuration: flDurationc);
    CBaseAnimatingOverlay::SetLayerWeight(this: v6, iLayer: v61->m_iLayer, flWeight: 0.0);
    if ( v6->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v6) != nullptr )
      CBaseAnimating::LockStudioHdr(this: v6);
    v64 = v6->m_pStudioHdr;
    if ( v64 == nullptr || v64->m_pStudioHdr == nullptr )
      v64 = nullptr;
    if ( (GetSequenceFlags(pstudiohdr: v64, sequence: v61->m_nSequence) & 1) != 0 )
    {
      v65 = *(const char **)((int (__thiscall *)(CBaseFlex *, float *))v6->GetModelName)(a1: v6, a2: &info);
      if ( v65 == nullptr )
        v65 = locale;
      flDurationd = v65;
      v66 = CChoreoEvent::GetParameters(this: v63);
      _DevMsg(a1: 1, a2: "vcd error, gesture %s of model %s is marked as STUDIO_LOOPING!\n", v66, flDurationd);
    }
    CBaseAnimatingOverlay::SetLayerLooping(this: v6, iLayer: v61->m_iLayer, bLooping: false);
    event = v63->GetDuration(this: v63);
    info = CBreakableProp::GetDmgModClub(this: scene);
    StartTime = CChoreoEvent::GetStartTime(this: v63);
    info = (info - StartTime) / event;
    info = CChoreoEvent::GetOriginalPercentageFromPlaybackPercentage(this: v63, t: info);
    CBaseAnimatingOverlay::SetLayerCycle(this: v6, iLayer: v61->m_iLayer, flCycle: info, flPrevCycle: 0.0);
    CBaseAnimatingOverlay::SetLayerPlaybackRate(this: v6, iLayer: v61->m_iLayer, flPlaybackRate: 0.0);
    return 1;
  }
  else
  {
    pszValue = v6->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    flDuration = CChoreoEvent::GetParameters(this: v5);
    v11 = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: (vgui::Panel *)actor);
    _Warning(a1: "CSceneEntity %s :\"%s\" unable to find gesture \"%s\"\n", pszValue, v11, flDuration);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D04D0
// Name: public: bool CBaseFlex::CheckSceneEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseFlex::CheckSceneEvent(
        CBaseFlex *this,
        float currenttime,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  int m_Size; // esi
  int v5; // edx
  CSceneEventInfo *i; // eax

  m_Size = this->m_SceneEvents.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    return true;
  for ( i = this->m_SceneEvents.m_Memory.m_pMemory; i->m_pScene != scene || i->m_pEvent != event; ++i )
  {
    if ( ++v5 >= m_Size )
      return true;
  }
  return ((bool (__thiscall *)(CBaseFlex *, CSceneEventInfo *, _DWORD, CChoreoScene *, CChoreoEvent *))this->CheckSceneEventCompletion)(
           a1: this,
           a2: i,
           a3: LODWORD(currenttime),
           a4: scene,
           a5: event);
}

//------------------------------------------------------------------------------
// Address: 0x100D0530
// Name: public: virtual void CBaseFlex::ProcessSceneEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::ProcessSceneEvents(CBaseFlex *this)
{
  LocalFlexController_t j; // edi
  CSceneEventInfo *v3; // edi
  CChoreoScene *m_pScene; // ebx
  CAI_BaseNPC *v5; // eax
  CAI_BaseNPC *v6; // edi
  const Vector *v7; // eax
  int m_iEFlags; // edx
  float value; // [esp+Ch] [ebp-38h]
  Vector p0; // [esp+1Ch] [ebp-28h] BYREF
  Vector p1; // [esp+28h] [ebp-1Ch] BYREF
  CChoreoEvent *event; // [esp+34h] [ebp-10h]
  int i; // [esp+38h] [ebp-Ch]
  unsigned int v14; // [esp+3Ch] [ebp-8h]
  bool bHasForegroundEvents; // [esp+43h] [ebp-1h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  for ( j = DUMMY_NULL_FLEX_CONTROLLER; j < CBaseAnimating::GetNumFlexControllers(this); ++j )
  {
    value = CBaseFlex::GetFlexWeight(this, index: j) * 0.95;
    CBaseFlex::SetFlexWeight(this, index: j, value);
  }
  bHasForegroundEvents = false;
  i = 0;
  if ( this->m_SceneEvents.m_Size <= 0 )
  {
    this->m_bUpdateLayerPriorities = false;
  }
  else
  {
    v14 = 0;
    do
    {
      v3 = &this->m_SceneEvents.m_Memory.m_pMemory[v14 / 0x4C];
      m_pScene = v3->m_pScene;
      event = v3->m_pEvent;
      if ( m_pScene != nullptr && !CChoreoScene::IsBackground(this: m_pScene) )
        bHasForegroundEvents = true;
      if ( this->ProcessSceneEvent(this, a2: v3, a3: m_pScene, a4: event) )
        v3->m_bStarted = true;
      v14 += 76;
      ++i;
    }
    while ( i < this->m_SceneEvents.m_Size );
    if ( bHasForegroundEvents
      && scene_showunlock.m_pParent != nullptr
      && scene_showunlock.m_pParent->m_Value.m_nValue != 0 )
    {
      v5 = this->MyNPCPointer(this);
      v6 = v5;
      if ( v5 != nullptr
        && v5->m_NPCState != NPC_STATE_SCRIPT
        && !CAI_BaseNPC::IsCurSchedule(this: v5, schedId: 63, fIdeal: true) )
      {
        p0 = *NAI_Hull::Mins(id: v6->m_eHull);
        v7 = NAI_Hull::Maxs(id: v6->m_eHull);
        m_iEFlags = v6->m_iEFlags;
        *(_QWORD *)&p1.x = *(_QWORD *)&v7->x;
        p0.z = v7->z + 2.0;
        p1.z = p0.z;
        if ( (m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v6, a2: (int)&savedregs);
        NDebugOverlay::Box(
          origin: &v6->m_vecAbsOrigin,
          mins: &p0,
          maxs: &p1,
          r: 255,
          g: 0,
          b: 0,
          a: 0,
          flDuration: 0.12);
      }
    }
    this->m_bUpdateLayerPriorities = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D06E0
// Name: private: bool CBaseFlex::ProcessLookAtSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::ProcessLookAtSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  CAI_BaseNPC *v4; // edi
  unsigned int m_Index; // eax
  double v7; // st7
  float v8; // xmm1_4
  unsigned int v9; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v11; // ebx
  float *v12; // esi
  float *v13; // eax
  float v14; // xmm0_4
  float scenetime; // [esp+34h] [ebp-44h]
  Vector v17; // [esp+44h] [ebp-34h] BYREF
  Vector endPos; // [esp+50h] [ebp-28h] BYREF
  Vector p0; // [esp+5Ch] [ebp-1Ch] BYREF
  Vector tmp; // [esp+68h] [ebp-10h] BYREF
  CHandle<CBaseEntity> *p_m_hTarget; // [esp+74h] [ebp-4h]
  float flDuration; // [esp+80h] [ebp+8h]
  float flDurationa; // [esp+80h] [ebp+8h]
  float intensity; // [esp+84h] [ebp+Ch]

  v4 = this->MyNPCPointer(this);
  if ( v4 != nullptr )
  {
    p_m_hTarget = &info->m_hTarget;
    m_Index = info->m_hTarget.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      scenetime = CBreakableProp::GetDmgModClub(this: scene);
      intensity = CChoreoEvent::GetIntensity(this: event, scenetime);
      flDuration = CBreakableProp::GetDmgModClub(this: scene);
      v7 = flDuration - CChoreoEvent::GetStartTime(this: event);
      if ( v7 >= 0.30000001 )
      {
        v8 = 1.0;
      }
      else
      {
        flDurationa = v7;
        v8 = (float)((float)((float)(flDurationa * 3.3333333) * (float)(flDurationa * 3.3333333)) * 3.0)
           - (float)((float)((float)((float)(flDurationa * 3.3333333) * (float)(flDurationa * 3.3333333)) * 2.0)
                   * (float)(flDurationa * 3.3333333));
      }
      if ( intensity >= 0.0 )
      {
        if ( intensity <= v8 )
          v8 = intensity;
      }
      else
      {
        v8 = 0.0;
      }
      v9 = p_m_hTarget->m_Index;
      if ( p_m_hTarget->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
      ((void (__thiscall *)(CAI_BaseNPC *, IHandleEntity *, float, int, _DWORD))v4->AddLookTarget)(
        a1: v4,
        a2: m_pEntity,
        a3: COERCE_FLOAT(LODWORD(v8)),
        a4: 1036831949,
        a5: 0);
      if ( developer.m_pParent != nullptr
        && developer.m_pParent->m_Value.m_nValue > 0
        && scene_showlook.m_pParent != nullptr
        && scene_showlook.m_pParent->m_Value.m_nValue != 0
        && CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hTarget) != nullptr )
      {
        v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hTarget);
        v12 = (float *)v4->EyePosition(this: v4, result: &endPos);
        v13 = (float *)v11->EyePosition(this: v11, result: &v17);
        tmp.x = *v13 - *v12;
        tmp.y = v13[1] - v12[1];
        tmp.z = v13[2] - v12[2];
        VectorNormalize(vec: &tmp);
        v4->EyePosition(this: v4, result: &p0);
        v14 = (float)(v8 * 16.0) + 4.0;
        endPos.x = p0.x + (float)(tmp.x * v14);
        endPos.y = p0.y + (float)(v14 * tmp.y);
        endPos.z = p0.z + (float)(tmp.z * v14);
        NDebugOverlay::VertArrow(
          startPos: &p0,
          &endPos,
          width: 4.0,
          r: 255,
          g: 255,
          b: 255,
          a: 0,
          noDepthTest: true,
          flDuration: 0.12);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D0980
// Name: protected: void CBaseFlex::AddFlexAnimation(class CSceneEventInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::AddFlexAnimation(CBaseFlex *this, CSceneEventInfo *info)
{
  CSceneEventInfo *v2; // esi
  CAI_BaseNPC *v4; // eax
  CChoreoEvent *m_pEvent; // edi
  CFlexAnimationTrack *FlexAnimationTrack; // eax
  CFlexAnimationTrack *v7; // esi
  const char *FlexControllerName; // eax
  LocalFlexController_t FlexController; // eax
  const char *v10; // eax
  LocalFlexController_t v11; // eax
  const char *v12; // eax
  LocalFlexController_t v13; // eax
  const char *v14; // eax
  int v15; // esi
  bool IsSuppressedFlexAnimation; // al
  double m_flWeight; // xmm0_8
  double v18; // xmm0_8
  __int64 v19; // xmm1_8
  bool v20; // cc
  float v21; // xmm0_4
  double Intensity; // st7
  CChoreoScene *v23; // ebx
  CFlexAnimationTrack *v24; // eax
  CFlexAnimationTrack *v25; // edi
  int j; // esi
  LocalFlexController_t RawFlexControllerIndex; // ebx
  double FlexWeight; // st7
  LocalFlexController_t v29; // esi
  CBaseFlex *v30; // edi
  double v31; // st7
  char scenetime; // [esp+4h] [ebp-228h]
  float scenetimea; // [esp+4h] [ebp-228h]
  float scenetimeb; // [esp+4h] [ebp-228h]
  char name[512]; // [esp+14h] [ebp-218h] BYREF
  float weight; // [esp+214h] [ebp-18h]
  CChoreoEvent *event; // [esp+218h] [ebp-14h]
  CBaseFlex *v38; // [esp+21Ch] [ebp-10h]
  float flIntensity; // [esp+220h] [ebp-Ch]
  CChoreoScene *scene; // [esp+224h] [ebp-8h]
  int i; // [esp+228h] [ebp-4h]

  v2 = info;
  v38 = this;
  if ( info != nullptr )
  {
    v4 = this->MyNPCPointer(this);
    if ( v4 == nullptr || CAI_BaseNPC::HasCondition(this: v4, iCondition: 1) )
    {
      m_pEvent = info->m_pEvent;
      event = m_pEvent;
      if ( m_pEvent != nullptr )
      {
        scene = info->m_pScene;
        if ( *(float *)&scene != 0.0 )
        {
          if ( !CChoreoEvent::GetTrackLookupSet(this: m_pEvent) )
          {
            *(float *)&i = 0.0;
            if ( CChoreoEvent::GetNumFlexAnimationTracks(this: m_pEvent) > 0 )
            {
              do
              {
                FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: m_pEvent, index: i);
                v7 = FlexAnimationTrack;
                if ( FlexAnimationTrack != nullptr )
                {
                  if ( CFlexAnimationTrack::IsComboType(this: FlexAnimationTrack) )
                  {
                    V_strncpy(pDest: name, pSrc: "right_", maxLen: 512);
                    FlexControllerName = CFlexAnimationTrack::GetFlexControllerName(this: v7);
                    V_strncat(pDest: name, pSrc: FlexControllerName, destBufferSize: 0x200u, max_chars_to_copy: -1);
                    FlexController = CBaseFlex::FindFlexController(this, szName: name);
                    CFlexAnimationTrack::SetFlexControllerIndex(this: v7, raw: FlexController, index: 0, side: 0);
                    if ( CAI_BaseActor::IsServerSideFlexController(szName: name) != 0 )
                      CFlexAnimationTrack::SetServerSide(this: v7, state: true);
                    V_strncpy(pDest: name, pSrc: "left_", maxLen: 512);
                    v10 = CFlexAnimationTrack::GetFlexControllerName(this: v7);
                    V_strncat(pDest: name, pSrc: v10, destBufferSize: 0x200u, max_chars_to_copy: -1);
                    v11 = CBaseFlex::FindFlexController(this, szName: name);
                    CFlexAnimationTrack::SetFlexControllerIndex(this: v7, raw: v11, index: 0, side: 1);
                    if ( CAI_BaseActor::IsServerSideFlexController(szName: name) != 0 )
                      CFlexAnimationTrack::SetServerSide(this: v7, state: true);
                  }
                  else
                  {
                    v12 = CFlexAnimationTrack::GetFlexControllerName(this: v7);
                    v13 = CBaseFlex::FindFlexController(this, szName: v12);
                    CFlexAnimationTrack::SetFlexControllerIndex(this: v7, raw: v13, index: 0, side: 0);
                    v14 = CFlexAnimationTrack::GetFlexControllerName(this: v7);
                    scenetime = CAI_BaseActor::IsServerSideFlexController(szName: v14);
                    CFlexAnimationTrack::SetServerSide(this: v7, state: scenetime);
                  }
                }
                v15 = ++i;
              }
              while ( v15 < CChoreoEvent::GetNumFlexAnimationTracks(this: m_pEvent) );
              v2 = info;
            }
            CChoreoEvent::SetTrackLookupSet(this: m_pEvent, set: true);
          }
          *(float *)&i = CBreakableProp::GetDmgModClub(this: scene);
          IsSuppressedFlexAnimation = CBaseFlex::IsSuppressedFlexAnimation(this, info: v2);
          m_flWeight = v2->m_flWeight;
          if ( IsSuppressedFlexAnimation )
          {
            v18 = m_flWeight - 0.2;
            v19 = 0;
            v20 = v18 <= 0.0;
          }
          else
          {
            v18 = m_flWeight + 0.1;
            v19 = 0x3FF0000000000000LL;
            v20 = v18 >= 1.0;
          }
          if ( v20 )
            v18 = *(double *)&v19;
          v21 = v18;
          v2->m_flWeight = v21;
          scene = (CChoreoScene *)LODWORD(v2->m_flWeight);
          Intensity = CChoreoEvent::GetIntensity(this: m_pEvent, scenetime: *(float *)&i);
          v23 = nullptr;
          weight = Intensity * *(float *)&scene;
          *(float *)&scene = 0.0;
          if ( CChoreoEvent::GetNumFlexAnimationTracks(this: m_pEvent) > 0 )
          {
            while ( 1 )
            {
              v24 = CChoreoEvent::GetFlexAnimationTrack(this: m_pEvent, index: (int)v23);
              v25 = v24;
              if ( v24 != nullptr
                && CFlexAnimationTrack::IsTrackActive(this: v24)
                && (!g_bClientFlex || CFlexAnimationTrack::IsServerSide(this: v25)) )
              {
                if ( CFlexAnimationTrack::IsComboType(this: v25) )
                {
                  for ( j = 0; j < 2; ++j )
                  {
                    RawFlexControllerIndex = CFlexAnimationTrack::GetRawFlexControllerIndex(this: v25, side: j);
                    flIntensity = CFlexAnimationTrack::GetIntensity(this: v25, time: *(float *)&i, side: j);
                    if ( RawFlexControllerIndex >= DUMMY_NULL_FLEX_CONTROLLER )
                    {
                      FlexWeight = CBaseFlex::GetFlexWeight(this: v38, index: RawFlexControllerIndex);
                      scenetimea = FlexWeight * (1.0 - weight) + weight * flIntensity;
                      CBaseFlex::SetFlexWeight(this: v38, index: RawFlexControllerIndex, value: scenetimea);
                    }
                  }
                  v23 = scene;
                }
                else
                {
                  v29 = CFlexAnimationTrack::GetRawFlexControllerIndex(this: v25, side: 0);
                  flIntensity = CFlexAnimationTrack::GetIntensity(this: v25, time: *(float *)&i, side: 0);
                  if ( v29 >= DUMMY_NULL_FLEX_CONTROLLER )
                  {
                    v30 = v38;
                    v31 = CBaseFlex::GetFlexWeight(this: v38, index: v29);
                    scenetimeb = v31 * (1.0 - weight) + weight * flIntensity;
                    CBaseFlex::SetFlexWeight(this: v30, index: v29, value: scenetimeb);
                  }
                }
              }
              v23 = (CChoreoScene *)((char *)v23 + 1);
              scene = v23;
              if ( (int)v23 >= CChoreoEvent::GetNumFlexAnimationTracks(this: event) )
                break;
              m_pEvent = event;
            }
            v2 = info;
          }
          v2->m_bStarted = true;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0CF0
// Name: private: bool CBaseFlex::ProcessGestureSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::ProcessGestureSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  bool v7; // al
  double m_flWeight; // xmm0_8
  double v9; // xmm0_8
  __int64 v10; // xmm1_8
  bool v11; // cc
  int ScenePriority; // eax
  float t; // [esp+0h] [ebp-10h]
  float flWeighta; // [esp+18h] [ebp+8h]
  float flWeightb; // [esp+18h] [ebp+8h]
  float flWeightc; // [esp+18h] [ebp+8h]
  float flWeight; // [esp+18h] [ebp+8h]
  float duration; // [esp+20h] [ebp+10h]

  if ( info == nullptr || event == nullptr || scene == nullptr )
    return 0;
  if ( info->m_iLayer == -2 )
    CBaseFlex::HandleStartGestureSceneEvent(
      this,
      info: *(float *)&info,
      scene,
      event: *(float *)&event,
      actor: info->m_pActor);
  if ( info->m_iLayer >= 0 )
  {
    duration = event->GetDuration(this: event);
    flWeighta = CBreakableProp::GetDmgModClub(this: scene);
    flWeightb = (flWeighta - CChoreoEvent::GetStartTime(this: event)) / duration;
    flWeightc = CChoreoEvent::GetOriginalPercentageFromPlaybackPercentage(this: event, t: flWeightb);
    CBaseAnimatingOverlay::SetLayerCycle(this, iLayer: info->m_iLayer, flCycle: flWeightc);
    t = CBreakableProp::GetDmgModClub(this: scene);
    flWeight = CChoreoEvent::GetIntensity(this: event, scenetime: t);
    if ( !info->m_bIsGesture )
    {
      v7 = this->IsMoving(this);
      m_flWeight = info->m_flWeight;
      if ( v7 )
      {
        v9 = m_flWeight - 0.2;
        v10 = 0;
        v11 = v9 <= 0.0;
      }
      else
      {
        v9 = m_flWeight + 0.2;
        v10 = 0x3FF0000000000000LL;
        v11 = v9 >= 1.0;
      }
      if ( v11 )
        v9 = *(double *)&v10;
      info->m_flWeight = v9;
    }
    CBaseAnimatingOverlay::SetLayerWeight(
      this,
      iLayer: info->m_iLayer,
      flWeight: (float)((float)((float)(info->m_flWeight * 3.0) * info->m_flWeight)
            - (float)((float)((float)(info->m_flWeight * 2.0) * info->m_flWeight) * info->m_flWeight))
    * flWeight);
    if ( this->m_bUpdateLayerPriorities )
    {
      ScenePriority = CBaseFlex::GetScenePriority(this, scene);
      CBaseAnimatingOverlay::SetLayerPriority(
        this,
        iLayer: info->m_iLayer,
        iPriority: info->m_iPriority + ScenePriority);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D0E70
// Name: public: virtual struct HSCRIPT__ __near * CBaseFlex::ScriptGetOldestScene(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CBaseFlex::ScriptGetOldestScene(CBaseFlex *this)
{
  CBaseEntity *m_pEntity; // eax
  CSceneEventInfo curScene; // [esp+0h] [ebp-4Ch] BYREF

  if ( this->m_SceneEvents.m_Size > 0
    && (CSceneEventInfo::CSceneEventInfo(this: &curScene, __that: this->m_SceneEvents.m_Memory.m_pMemory),
        curScene.m_hSceneEntity.m_Index != -1)
    && g_pEntityList->m_EntPtrArray[LOWORD(curScene.m_hSceneEntity.m_Index)].m_SerialNumber == HIWORD(curScene.m_hSceneEntity.m_Index)
    && (m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(curScene.m_hSceneEntity.m_Index)].m_pEntity) != nullptr )
  {
    return CBaseEntity::GetScriptInstance(this: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0ED0
// Name: public: virtual struct HSCRIPT__ __near * CBaseFlex::ScriptGetSceneByIndex(int)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CBaseFlex::ScriptGetSceneByIndex(CBaseFlex *this, int index)
{
  CBaseEntity *m_pEntity; // eax
  CSceneEventInfo curScene; // [esp+0h] [ebp-4Ch] BYREF

  if ( index >= 0
    && index < this->m_SceneEvents.m_Size
    && (CSceneEventInfo::CSceneEventInfo(this: &curScene, __that: &this->m_SceneEvents.m_Memory.m_pMemory[index]),
        curScene.m_hSceneEntity.m_Index != -1)
    && g_pEntityList->m_EntPtrArray[LOWORD(curScene.m_hSceneEntity.m_Index)].m_SerialNumber == HIWORD(curScene.m_hSceneEntity.m_Index)
    && (m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(curScene.m_hSceneEntity.m_Index)].m_pEntity) != nullptr )
  {
    return CBaseEntity::GetScriptInstance(this: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1420
// Name: public: virtual void CBaseFlex::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::SetModel(CBaseFlex *this, const char *szModelName)
{
  IMDLCache *v2; // esi
  int v4; // edi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v6; // eax
  int v7; // ecx
  float v8; // xmm1_4
  char *v9; // ecx
  float v10; // xmm0_4
  int v11; // xmm1_4
  edict_t *m_pPev; // ecx
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h]
  const char *szModelNamea; // [esp+1Ch] [ebp+8h]

  v2 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  CBaseAnimatingOverlay::SetModel(this, szModelName);
  v4 = 0;
  if ( CBaseAnimating::GetNumFlexControllers(this) > 0 )
  {
    v14 = 0;
    do
    {
      szModelNamea = nullptr;
      if ( v4 >= 0 && v4 < CBaseAnimating::GetNumFlexControllers(this) )
      {
        if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
          CBaseAnimating::LockStudioHdr(this);
        m_pStudioHdr = this->m_pStudioHdr;
        if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
        {
          v6 = m_pStudioHdr->m_pStudioHdr;
          v7 = v14 + v6->flexcontrollerindex;
          v8 = *(float *)&v6->name[v7 + 4];
          v9 = (char *)v6 + v7;
          if ( v8 != *((float *)v9 + 3) )
          {
            v10 = COERCE_FLOAT(*((_DWORD *)v9 + 3) ^ _mask__NegFloat_) / (float)(v8 - *((float *)v9 + 3));
            v11 = 0;
            if ( v10 < 0.0 || (v11 = 1065353216, v10 > 1.0) )
              v10 = *(float *)&v11;
            szModelNamea = (const char *)LODWORD(v10);
          }
          if ( (const char *)LODWORD(this->m_flexWeight.m_Value[v4]) != szModelNamea )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
                CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 4 * v4 + 1184);
            }
            LODWORD(this->m_flexWeight.m_Value[v4]) = szModelNamea;
          }
        }
      }
      v14 += 20;
      ++v4;
    }
    while ( v4 < CBaseAnimating::GetNumFlexControllers(this) );
    v2 = cacheCriticalSection;
  }
  v2->EndLock(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100D1580
// Name: public: void CBaseFlex::RemoveChoreoScene(class CChoreoScene __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::RemoveChoreoScene(CBaseFlex *this, CChoreoScene *scene, bool canceled)
{
  bool v4; // zf
  CAI_BaseNPC *v5; // eax

  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ActiveChoreoScenes,
    src: (vgui::TreeNode **)&scene);
  v4 = !canceled;
  this->m_bUpdateLayerPriorities = true;
  if ( !v4 )
  {
    v5 = this->MyNPCPointer(this);
    if ( v5 != nullptr )
      v5->m_flSceneTime = gpGlobals->curtime + 0.2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D15E0
// Name: public: void CBaseFlex::ClearSceneEvents(class CChoreoScene __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::ClearSceneEvents(CBaseFlex *this, CChoreoScene *scene, BOOL canceled)
{
  int v4; // ebx
  int v5; // eax
  CSceneEventInfo *v6; // esi
  int v7; // [esp+4h] [ebp-4h]

  if ( scene != nullptr )
  {
    v4 = this->m_SceneEvents.m_Size - 1;
    if ( v4 >= 0 )
    {
      v5 = 76 * v4;
      v7 = 76 * v4;
      do
      {
        v6 = (CSceneEventInfo *)((char *)this->m_SceneEvents.m_Memory.m_pMemory + v5);
        if ( v6->m_pScene == scene )
        {
          this->ClearSceneEvent(this, a2: v6, a3: false, a4: canceled);
          v6->m_pEvent = nullptr;
          v6->m_pScene = nullptr;
          v6->m_bStarted = false;
          if ( this->m_SceneEvents.m_Size - v4 - 1 > 0 )
            _V_memmove(
              dest: (char *)this->m_SceneEvents.m_Memory.m_pMemory + v7,
              src: (char *)&this->m_SceneEvents.m_Memory.m_pMemory[1] + v7,
              count: 76 * (this->m_SceneEvents.m_Size - v4 - 1));
          --this->m_SceneEvents.m_Size;
          v5 = v7;
        }
        v5 -= 76;
        --v4;
        v7 = v5;
      }
      while ( v4 >= 0 );
    }
  }
  else
  {
    this->m_SceneEvents.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1690
// Name: public: void CBaseFlex::RemoveSceneEvent(class CChoreoScene __near *,class CChoreoEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::RemoveSceneEvent(CBaseFlex *this, CChoreoScene *scene, CChoreoEvent *event, BOOL fastKill)
{
  int v5; // ebx
  CSceneEventInfo *v6; // esi
  int i; // [esp+8h] [ebp-4h]

  v5 = 0;
  if ( this->m_SceneEvents.m_Size > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v6 = &this->m_SceneEvents.m_Memory.m_pMemory[i];
      if ( v6->m_pScene == scene
        && v6->m_pEvent == event
        && this->ClearSceneEvent(this, a2: v6, a3: fastKill, a4: false) )
      {
        break;
      }
      if ( ++v5 >= this->m_SceneEvents.m_Size )
        return;
    }
    v6->m_pEvent = nullptr;
    v6->m_pScene = nullptr;
    v6->m_bStarted = false;
    if ( this->m_SceneEvents.m_Size - v5 - 1 > 0 )
      _V_memmove(
        dest: &this->m_SceneEvents.m_Memory.m_pMemory[v5],
        src: &this->m_SceneEvents.m_Memory.m_pMemory[v5 + 1],
        count: 76 * (this->m_SceneEvents.m_Size - v5 - 1));
    --this->m_SceneEvents.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1740
// Name: private: bool CBaseFlex::ProcessFlexAnimationSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __thiscall CBaseFlex::ProcessFlexAnimationSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  CAI_BaseNPC *v5; // eax
  ConVar *m_pParent; // ecx
  double v7; // st7
  CBasePlayer *LocalPlayer; // eax
  IUniformRandomStream *v9; // ecx
  bool v10; // al

  if ( CChoreoEvent::CurveHasEndTime(this: event) )
  {
    v5 = this->MyNPCPointer(this);
    if ( v5 == nullptr )
    {
LABEL_17:
      CBaseFlex::AddFlexAnimation(this, info);
      return 1;
    }
    if ( CAI_BaseNPC::HasCondition(this: v5, iCondition: 1) )
    {
      if ( ai_expression_optimization.m_pParent == nullptr
        || ai_expression_optimization.m_pParent->m_Value.m_nValue == 0
        || !CChoreoScene::IsBackground(this: scene) )
      {
        goto LABEL_17;
      }
      m_pParent = ai_expression_frametime.m_pParent;
      if ( gpGlobals->frametime <= ai_expression_frametime.m_pParent->m_Value.m_fValue )
      {
        if ( gpGlobals->curtime < info->m_flNext )
          goto LABEL_16;
        LocalPlayer = UTIL_GetLocalPlayer();
        v10 = LocalPlayer != nullptr && !LocalPlayer->FInViewCone(this: LocalPlayer, a2: this);
        info->m_bHasArrived = v10;
        v7 = _RandomFloat(this: v9, a2: 0.69999999, a3: 1.2) + gpGlobals->curtime;
      }
      else
      {
        info->m_bHasArrived = true;
        v7 = _RandomFloat(this: (IUniformRandomStream *)m_pParent, a2: 0.69999999, a3: 1.2) + gpGlobals->curtime;
      }
      info->m_flNext = v7;
LABEL_16:
      if ( !info->m_bHasArrived )
        goto LABEL_17;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D1870
// Name: public: virtual int CFlexCycler::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFlexCycler::OnTakeDamage(CFlexCycler *this, const CTakeDamageInfo *info)
{
  int v3; // esi
  edict_t *m_pPev; // ecx

  v3 = this->m_nSequence.m_Value + 1;
  if ( !CBaseAnimating::IsValidSequence(this, iSequence: v3) )
    v3 = 0;
  CBaseAnimating::ResetSequence(this, nSequence: v3);
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
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D20F0
// Name: public: virtual void CBaseFlex::SetViewtarget(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::SetViewtarget(CBaseFlex *this, const Vector *viewtarget)
{
  CNetworkVectorBase<Vector,CBaseFlex::NetworkVar_m_viewtarget> *p_m_viewtarget; // esi
  edict_t *m_pPev; // ecx

  p_m_viewtarget = &this->m_viewtarget;
  if ( viewtarget->x != this->m_viewtarget.m_Value.x
    || viewtarget->y != this->m_viewtarget.m_Value.y
    || viewtarget->z != this->m_viewtarget.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x620u);
    }
    p_m_viewtarget->m_Value = *viewtarget;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2170
// Name: private: void CFlexSceneFileManager::DeleteSceneFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexSceneFileManager::DeleteSceneFiles(CFlexSceneFileManager *this)
{
  CFlexSceneFile *v2; // edi

  while ( this->m_FileList.m_Size > 0 )
  {
    v2 = *this->m_FileList.m_Memory.m_pMemory;
    if ( this->m_FileList.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_FileList.m_Memory.m_pMemory,
        src: this->m_FileList.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_FileList.m_Size - 1));
    --this->m_FileList.m_Size;
    filesystem->FreeOptimalReadBuffer(this: filesystem, a2: v2->buffer);
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D21E0
// Name: public: virtual void CFlexSceneFileManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFlexSceneFileManager::Shutdown(CFlexSceneFileManager *this)
{
  CFlexSceneFileManager::DeleteSceneFiles(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D21F0
// Name: public: bool CBaseFlex::EnterSceneSequence(class CChoreoScene __near *,class CChoreoEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::EnterSceneSequence(CBaseFlex *this, CChoreoScene *scene, CChoreoEvent *event, bool bRestart)
{
  CAI_BaseNPC *v4; // edi
  double v7; // st7
  double v8; // st7
  float curtime; // xmm0_4
  CAI_Schedule *m_pSchedule; // eax
  bool v11; // zf
  unsigned int v12; // edx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  unsigned int v15; // eax
  float m_flSceneTime; // xmm0_4
  unsigned int testBits_12; // [esp+10h] [ebp-1Ch]
  unsigned int testBits_16; // [esp+14h] [ebp-18h]
  unsigned int testBits_20; // [esp+18h] [ebp-14h]
  double v20; // [esp+24h] [ebp-8h]
  double v21; // [esp+24h] [ebp-8h]
  double v22; // [esp+24h] [ebp-8h]
  float flDuration; // [esp+38h] [ebp+Ch]
  float flDurationa; // [esp+38h] [ebp+Ch]
  float flDurationb; // [esp+38h] [ebp+Ch]
  float flDurationc; // [esp+38h] [ebp+Ch]
  float flDurationd; // [esp+38h] [ebp+Ch]
  float flDuratione; // [esp+38h] [ebp+Ch]
  float flDurationf; // [esp+38h] [ebp+Ch]
  float flDurationg; // [esp+38h] [ebp+Ch]
  float flDurationh; // [esp+38h] [ebp+Ch]

  v4 = this->MyNPCPointer(this);
  if ( v4 == nullptr )
    return 0;
  flDuration = CChoreoEvent::GetEndTime(this: event);
  v20 = flDuration - CBreakableProp::GetDmgModClub(this: scene) + 2.0;
  flDurationa = CChoreoScene::FindStopTime(this: scene);
  if ( flDurationa - CBreakableProp::GetDmgModClub(this: scene) + 0.2 <= v20 )
  {
    flDurationc = CChoreoScene::FindStopTime(this: scene);
    v7 = flDurationc - CBreakableProp::GetDmgModClub(this: scene) + 0.2;
  }
  else
  {
    flDurationb = CChoreoEvent::GetEndTime(this: event);
    v7 = flDurationb - CBreakableProp::GetDmgModClub(this: scene) + 2.0;
  }
  if ( v7 <= 2.0 )
  {
    flDurationd = CChoreoEvent::GetEndTime(this: event);
    v22 = flDurationd - CBreakableProp::GetDmgModClub(this: scene) + 2.0;
    flDuratione = CChoreoScene::FindStopTime(this: scene);
    if ( flDuratione - CBreakableProp::GetDmgModClub(this: scene) + 0.2 <= v22 )
    {
      flDurationg = CChoreoScene::FindStopTime(this: scene);
      v8 = flDurationg - CBreakableProp::GetDmgModClub(this: scene) + 0.2;
    }
    else
    {
      flDurationf = CChoreoEvent::GetEndTime(this: event);
      v8 = flDurationf - CBreakableProp::GetDmgModClub(this: scene) + 2.0;
    }
    v21 = v8;
  }
  else
  {
    v21 = 2.0;
  }
  if ( CAI_BaseNPC::IsCurSchedule(this: v4, schedId: 63, fIdeal: true) )
  {
    curtime = gpGlobals->curtime;
  }
  else
  {
    m_pSchedule = v4->m_pSchedule;
    if ( m_pSchedule != nullptr )
    {
      v11 = (m_pSchedule->m_InterruptMask.m_Ints[0] & 0xFDFFFFFF) == 0;
      v12 = m_pSchedule->m_InterruptMask.m_Ints[1];
      v13 = m_pSchedule->m_InterruptMask.m_Ints[2];
      testBits_12 = m_pSchedule->m_InterruptMask.m_Ints[3];
      testBits_16 = m_pSchedule->m_InterruptMask.m_Ints[4];
      testBits_20 = m_pSchedule->m_InterruptMask.m_Ints[5];
      v14 = m_pSchedule->m_InterruptMask.m_Ints[6];
      v15 = m_pSchedule->m_InterruptMask.m_Ints[7];
      if ( v11
        && v12 == 0
        && v13 == 0
        && testBits_12 == 0
        && testBits_16 == 0
        && testBits_20 == 0
        && v14 == 0
        && v15 == 0 )
      {
        return 0;
      }
    }
    if ( !v4->IsInterruptable(this: v4) )
      return 0;
    if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v4->m_hCine) != nullptr )
      CAI_BaseNPC::ExitScriptedSequence(this: v4);
    v4->OnStartScene(this: v4);
    CAI_BaseNPC::SetSchedule(this: v4, localScheduleID: 63);
    curtime = gpGlobals->curtime;
  }
  flDurationh = v21;
  m_flSceneTime = curtime + flDurationh;
  if ( m_flSceneTime <= v4->m_flSceneTime )
    m_flSceneTime = v4->m_flSceneTime;
  v4->m_flSceneTime = m_flSceneTime;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D2420
// Name: public: virtual void CFlexCycler::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexCycler::Spawn(CFlexCycler *this)
{
  edict_t *m_pPev; // ecx
  double v3; // st7
  edict_t *v4; // ecx
  float v5; // [esp+18h] [ebp-4h]

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
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
  v3 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
         a1: random,
         a2: 0,
         a3: 1065353216);
  v5 = v3;
  if ( this->m_flCycle.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flCycle.m_Value = v5;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x3ACu);
      this->m_flCycle.m_Value = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D25B0
// Name: public: virtual void CFlexCycler::Think(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CFlexCycler::Think(CFlexCycler *this@<ecx>, unsigned int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  float *p_curtime; // edx
  bool v6; // zf
  edict_t *m_pPev; // ecx
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  char *m_pszString; // eax
  char v11; // dl
  int j; // edi
  int k; // edi
  LocalFlexController_t v14; // eax
  __int32 v15; // ecx
  int v16; // edi
  float v17; // eax
  int v18; // edi
  float v19; // xmm1_4
  float *v20; // eax
  char *m; // eax
  float v22; // edi
  char v23; // al
  int v24; // edi
  LocalFlexController_t v25; // eax
  LocalFlexController_t n; // edi
  const char *v27; // eax
  LocalFlexController_t v28; // eax
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  IUniformRandomStream_vtbl *v30; // edi
  int v31; // eax
  LocalFlexController_t v32; // ecx
  const char *FlexControllerType; // eax
  unsigned __int8 *FlexControllerName; // eax
  int v35; // eax
  const char *v36; // eax
  int v37; // edi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v39; // eax
  const char *v40; // ecx
  float v41; // xmm0_4
  const char *v42; // ecx
  float v43; // xmm0_4
  float v44; // xmm1_4
  float (__thiscall *v45)(IUniformRandomStream *, float, float); // edx
  double v46; // st7
  int v47; // xmm1_4
  CStudioHdr *v48; // eax
  const studiohdr_t *v49; // eax
  const char *v50; // ecx
  float v51; // xmm1_4
  const char *v52; // ecx
  float v53; // xmm0_4
  int v54; // xmm1_4
  int v55; // eax
  float v56; // edi
  edict_t *v57; // ecx
  int m_sentence; // eax
  const char *pszValue; // ecx
  int v60; // eax
  int v61; // edi
  char *v62; // eax
  char *v63; // eax
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  Vector *(__thiscall *v65)(CBaseEntity *, Vector *); // edx
  const Vector *v66; // eax
  edict_t *v67; // eax
  float v68; // edx
  edict_t *v69; // ecx
  void (__thiscall *GetVectors)(CBaseEntity *, Vector *, Vector *, Vector *); // edx
  CBasePlayer *LocalPlayer; // edi
  float *v72; // eax
  __int128 v73; // xmm0
  float *v74; // eax
  float *v75; // eax
  int v76; // xmm0_4
  double v77; // st7
  float (__thiscall *v78)(IUniformRandomStream *, float, float); // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v80; // eax
  float v81; // xmm1_4
  float v82; // xmm2_4
  double v83; // st7
  float m_blinktime; // xmm0_4
  float v85; // edx
  edict_t *v86; // ecx
  double v87; // st7
  char v89[128]; // [esp+68h] [ebp-1A4h] BYREF
  char v90[12]; // [esp+E8h] [ebp-124h] BYREF
  char szExpression[128]; // [esp+F4h] [ebp-118h] BYREF
  float v92; // [esp+174h] [ebp-98h]
  Vector up; // [esp+178h] [ebp-94h] BYREF
  Vector right; // [esp+184h] [ebp-88h] BYREF
  float v95; // [esp+190h] [ebp-7Ch]
  Vector forward; // [esp+194h] [ebp-78h] BYREF
  IRecipientFilter v97[3]; // [esp+1A0h] [ebp-6Ch] BYREF
  CPASAttenuationFilter filter; // [esp+1ACh] [ebp-60h] BYREF
  float v99; // [esp+1CCh] [ebp-40h]
  float v100; // [esp+1D0h] [ebp-3Ch]
  int v101; // [esp+1D4h] [ebp-38h]
  float v102; // [esp+1D8h] [ebp-34h]
  float *m_flextarget; // [esp+1DCh] [ebp-30h]
  double i; // [esp+1E0h] [ebp-2Ch] OVERLAPPED
  float v105; // [esp+1E8h] [ebp-24h]
  float v106; // [esp+1F4h] [ebp-18h]
  LocalFlexController_t NumFlexControllers; // [esp+1F8h] [ebp-14h]
  float value; // [esp+1FCh] [ebp-10h]
  long double v109; // [esp+200h] [ebp-Ch] OVERLAPPED BYREF
  unsigned int retaddr; // [esp+20Ch] [ebp+0h]

  *(_QWORD *)&v109 = __PAIR64__(retaddr, a2);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  ((void (__thiscall *)(CFlexCycler *, int, int))this->StudioFrameAdvance)(a1: this, a2: a3, a3: a4);
  if ( this->m_bSequenceFinished && !this->m_bSequenceLoops )
  {
    p_curtime = &gpGlobals->curtime;
    v6 = this->m_flAnimTime.m_Value == gpGlobals->curtime;
    NumFlexControllers = (LocalFlexController_t)&gpGlobals->curtime;
    if ( !v6 )
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
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x64u);
          p_curtime = (float *)NumFlexControllers;
        }
      }
      this->m_flAnimTime.m_Value = *p_curtime;
    }
    if ( this->m_flPlaybackRate.m_Value != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x37Cu);
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
        v9 = this->m_Network.m_pPev;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x3ACu);
      }
      this->m_flCycle.m_Value = 0.0;
    }
  }
  if ( CBaseAnimating::GetNumFlexControllers(this) > 2 )
  {
    if ( (flex_expression.m_nFlags & 0x1000) != 0 )
    {
      value = COERCE_FLOAT("FCVAR_NEVER_AS_STRING");
    }
    else
    {
      m_pszString = flex_expression.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        goto LABEL_69;
      v11 = *m_pszString;
      value = *(float *)&flex_expression.m_pParent->m_Value.m_pszString;
      if ( v11 == 43 && m_pszString[1] != 0 )
      {
        NumFlexControllers = atoi(nptr: m_pszString + 1);
        for ( j = 0; j < CBaseAnimating::GetNumFlexControllers(this); ++j )
          this->m_flextarget[this->m_flexnum] = 0.0;
        for ( k = 0; k < 35; ++k )
        {
          if ( predef_flexcontroller_names[k] == nullptr )
            break;
          v14 = CFlextalkActor::LookupFlex(this, szTarget: predef_flexcontroller_names[k]);
          v15 = k + 30 * NumFlexControllers;
          this->m_flexnum = v14;
          this->m_flextarget[v14] = predef_flexcontroller_values[v15];
        }
        goto LABEL_75;
      }
      if ( v11 == 49 && m_pszString[1] == 0 )
      {
        v16 = 0;
        if ( CBaseAnimating::GetNumFlexControllers(this) > 0 )
        {
          LODWORD(value) = this->m_flextarget;
          do
          {
            v17 = value;
            value = 1.0;
            NumFlexControllers = v16;
            *(_DWORD *)LODWORD(v17) = 1065353216;
            CBaseFlex::SetFlexWeight(this, index: NumFlexControllers, value);
            LODWORD(value) += 4;
            ++v16;
          }
          while ( v16 < CBaseAnimating::GetNumFlexControllers(this) );
        }
        goto LABEL_75;
      }
      if ( v11 == 94 && m_pszString[1] == 0 )
      {
        v18 = 0;
        if ( CBaseAnimating::GetNumFlexControllers(this) > 0 )
        {
          LODWORD(value) = this->m_flextarget;
          do
          {
            v19 = (float)((float)(1.0 / (float)CBaseAnimating::GetNumFlexControllers(this)) * (float)v18)
                + gpGlobals->curtime;
            __libm_sse2_sin(x: v109);
            v20 = (float *)LODWORD(value);
            value = (float)(v19 + 1.0) * 0.5;
            NumFlexControllers = v18;
            *v20 = value;
            CBaseFlex::SetFlexWeight(this, index: NumFlexControllers, value);
            LODWORD(value) += 4;
            ++v18;
          }
          while ( v18 < CBaseAnimating::GetNumFlexControllers(this) );
        }
        goto LABEL_75;
      }
      if ( v11 == 0 )
      {
LABEL_69:
        if ( gpGlobals->curtime > this->m_flextime )
        {
          NumFlexControllers = CBaseAnimating::GetNumFlexControllers(this);
          RandomFloat = random->RandomFloat;
          i = 1.0 / (double)(int)NumFlexControllers * 30.0;
          this->m_flextime = ((double (__thiscall *)(IUniformRandomStream *, int, int))RandomFloat)(
                               a1: random,
                               a2: 1050253722,
                               a3: 1056964608)
                           * i
                           + gpGlobals->curtime;
          v30 = random->__vftable;
          v31 = CBaseAnimating::GetNumFlexControllers(this);
          v32 = v30->RandomInt(this: random, a2: 0, a3: v31 - 1);
          this->m_flexnum = v32;
          if ( this->m_flextarget[v32] == 1.0 )
          {
            this->m_flextarget[v32] = 0.0;
          }
          else
          {
            FlexControllerType = CBaseAnimating::GetFlexControllerType(this, iFlexController: v32);
            if ( _V_stricmp(s1: FlexControllerType, s2: "phoneme") != 0 )
            {
              FlexControllerName = (unsigned __int8 *)CBaseAnimating::GetFlexControllerName(
                                                        this,
                                                        iFlexController: this->m_flexnum);
              strstr(str1: FlexControllerName, str2: "upper_raiser");
              if ( v35 == 0 )
              {
                value = COERCE_FLOAT(CBaseAnimating::GetFlexControllerName(this, iFlexController: this->m_flexnum));
                v36 = CBaseAnimating::GetFlexControllerType(this, iFlexController: this->m_flexnum);
                _Msg(a1: "%s:%s\n", v36, (const char *)LODWORD(value));
                CFlexCycler::SetFlexTarget(this, a2: (int)v30, flexnum: this->m_flexnum);
              }
            }
          }
        }
        goto LABEL_75;
      }
    }
    if ( strcmp((const char *)LODWORD(value), "+") != 0 )
    {
      V_strncpy(pDest: v90, pSrc: (const char *)LODWORD(value), maxLen: 128);
      for ( m = v90; *m != 0; ++m )
      {
        if ( *m == 43 )
          *m = 32;
      }
      v22 = COERCE_FLOAT(v90);
      v106 = COERCE_FLOAT(v90);
      if ( v90[0] != 0 )
      {
        do
        {
          v23 = *(_BYTE *)LODWORD(v22);
          if ( *(_BYTE *)LODWORD(v22) != 32 )
          {
            if ( v23 == 45 )
            {
              v24 = 0;
              if ( CBaseAnimating::GetNumFlexControllers(this) > 0 )
              {
                NumFlexControllers = (LocalFlexController_t)this->m_flextarget;
                do
                {
                  v25 = NumFlexControllers;
                  *(_DWORD *)NumFlexControllers = 0;
                  ++v24;
                  NumFlexControllers = v25 + 4;
                }
                while ( v24 < CBaseAnimating::GetNumFlexControllers(this) );
              }
            }
            else
            {
              if ( v23 != 63 )
              {
                if ( sscanf(string: (const char *)LODWORD(v22), format: "%31s", v97) == 1 )
                {
                  v28 = CFlextalkActor::LookupFlex(this, szTarget: (const char *)v97);
                  this->m_flexnum = v28;
                  if ( v28 != DUMMY_INVALID_FLEX_CONTROLLER && this->m_flextarget[v28] != 1.0 )
                    this->m_flextarget[v28] = 1.0;
                  LODWORD(v22) += (char *)v97 + strlen((const char *)v97) - ((char *)&v97[0].__vftable + 1);
                }
                goto LABEL_58;
              }
              for ( n = DUMMY_NULL_FLEX_CONTROLLER; n < CBaseAnimating::GetNumFlexControllers(this); ++n )
              {
                v27 = CBaseAnimating::GetFlexControllerName(this, iFlexController: n);
                _Msg(a1: "\"%s\" ", v27);
              }
              _Msg(a1: "\n");
              ConVar::SetValue(this: (ConVar *)&flex_expression.IConVar, value: locale);
            }
            v22 = v106;
          }
LABEL_58:
          ++LODWORD(v22);
          v6 = *(_BYTE *)LODWORD(v22) == 0;
          v106 = v22;
        }
        while ( !v6 );
      }
LABEL_75:
      v101 = 0;
      if ( CBaseAnimating::GetNumFlexControllers(this) > 0 )
      {
        v37 = v101;
        value = 0.0;
        m_flextarget = this->m_flextarget;
        LODWORD(v105) = -1672 - (_DWORD)this;
        do
        {
          if ( v37 < 0 || v37 >= CBaseAnimating::GetNumFlexControllers(this) )
            goto LABEL_87;
          if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
            CBaseAnimating::LockStudioHdr(this);
          m_pStudioHdr = this->m_pStudioHdr;
          if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
          {
            v39 = m_pStudioHdr->m_pStudioHdr;
            v40 = (const char *)(LODWORD(value) + v39->flexcontrollerindex);
            v41 = *(float *)&v39->name[(_DWORD)v40 + 4];
            v42 = &v40[(_DWORD)v39];
            if ( v41 == *((float *)v42 + 3) )
              v43 = *(m_flextarget - 122);
            else
              v43 = (float)((float)(v41 - *((float *)v42 + 3)) * *(m_flextarget - 122)) + *((float *)v42 + 3);
          }
          else
          {
LABEL_87:
            v43 = 0.0;
          }
          v44 = *m_flextarget;
          v106 = v43;
          right.x = v44;
          if ( v43 != v44 )
          {
            v45 = random->RandomFloat;
            v102 = right.x - v106;
            v46 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v45)(
                    a1: random,
                    a2: 0x40000000,
                    a3: 1082130432);
            v102 = v102 / v46 + v106;
            v43 = v102;
          }
          *(float *)&v47 = 0.0;
          if ( v43 < 0.0 || (*(float *)&v47 = 1.0, v43 > 1.0) )
            v43 = *(float *)&v47;
          *(float *)&filter.m_Recipients.m_pElements = v43;
          NumFlexControllers = LODWORD(v43);
          if ( v37 >= 0 && v37 < CBaseAnimating::GetNumFlexControllers(this) )
          {
            if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
              CBaseAnimating::LockStudioHdr(this);
            v48 = this->m_pStudioHdr;
            if ( v48 != nullptr && v48->m_pStudioHdr != nullptr )
            {
              v49 = v48->m_pStudioHdr;
              v50 = (const char *)(LODWORD(value) + v49->flexcontrollerindex);
              v51 = *(float *)&v49->name[(_DWORD)v50 + 4];
              v52 = &v50[(_DWORD)v49];
              if ( v51 != *((float *)v52 + 3) )
              {
                v53 = (float)(*(float *)&filter.m_Recipients.m_pElements - *((float *)v52 + 3))
                    / (float)(v51 - *((float *)v52 + 3));
                *(float *)&v54 = 0.0;
                if ( v53 < 0.0 || (*(float *)&v54 = 1.0, v53 > 1.0) )
                  v53 = *(float *)&v54;
                NumFlexControllers = LODWORD(v53);
              }
              v55 = *(_DWORD *)((char *)this->m_flexWeight.m_Value + (_DWORD)m_flextarget + LODWORD(v105));
              LODWORD(v56) = (char *)this->m_flexWeight.m_Value + (_DWORD)m_flextarget + LODWORD(v105);
              v102 = v56;
              if ( v55 != NumFlexControllers )
              {
                if ( this->m_Network.m_TimerEvent.m_bRegistered )
                {
                  *((_BYTE *)&this->m_Network + 76) |= 1u;
                }
                else
                {
                  v57 = this->m_Network.m_pPev;
                  if ( v57 != nullptr )
                  {
                    CBaseEdict::StateChanged(this: &v57->CBaseEdict, offset: 4 * v101 + 1184);
                    v56 = v102;
                  }
                }
                *(_DWORD *)LODWORD(v56) = NumFlexControllers;
              }
            }
          }
          LODWORD(value) += 20;
          ++m_flextarget;
          v37 = ++v101;
        }
        while ( v37 < CBaseAnimating::GetNumFlexControllers(this) );
      }
      if ( flex_talk.m_pParent != nullptr && flex_talk.m_pParent->m_Value.m_nValue == -1 )
      {
        m_sentence = this->m_sentence;
        this->m_istalking = 1;
        this->m_sentence = m_sentence + 1;
        pszValue = this->m_iszSentence.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        V_snprintf(pDest: v89, maxLen: 256, pFormat: "%s%d", pszValue, m_sentence);
        v60 = engine->SentenceIndexFromName(this: engine, a2: v89);
        v61 = v60;
        if ( v60 >= 0 )
        {
          _Msg(a1: "%d : %s\n", v60, v89);
LABEL_130:
          GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
          value = COERCE_FLOAT((CPASAttenuationFilter *)&filter.m_bUsingPredictionRules);
          v105 = COERCE_FLOAT(((int (__thiscall *)(CFlexCycler *))GetSoundEmissionOrigin)(a1: this));
          CRecipientFilter::CRecipientFilter(this: (CRecipientFilter *)v97);
          v97[0].__vftable = (IRecipientFilter_vtbl *)&CPASFilter::`vftable';
          CRecipientFilter::AddRecipientsByPAS(this: (CRecipientFilter *)v97, origin: (const Vector *)LODWORD(v105));
          v65 = this->GetSoundEmissionOrigin;
          v97[0].__vftable = (IRecipientFilter_vtbl *)&CPASAttenuationFilter::`vftable';
          v66 = (const Vector *)((int (__thiscall *)(CFlexCycler *, bool *, int))v65)(
                                  a1: this,
                                  a2: &filter.m_bUsingPredictionRules,
                                  a3: 1061997773);
          CPASAttenuationFilter::Filter(
            this: (CPASAttenuationFilter *)v97,
            a2: (int)&v109,
            origin: v66,
            attenuation: value);
          v67 = this->m_Network.m_pPev;
          if ( v67 != nullptr )
            v67 -= (int)gpGlobals->pEdicts;
          CBaseEntity::EmitSentenceByIndex(
            filter: v97,
            iEntIndex: (int)v67,
            iChannel: 2,
            iSentenceIndex: v61,
            flVolume: 1.0,
            iSoundlevel: SNDLVL_80dB,
            iFlags: 0,
            iPitch: 100,
            pOrigin: nullptr,
            pDirection: nullptr,
            bUpdatePositions: 1,
            soundtime: 0.0);
          CRecipientFilter::~CRecipientFilter(this: (CRecipientFilter *)v97);
          goto LABEL_133;
        }
        this->m_sentence = 0;
      }
      else
      {
        if ( (flex_talk.m_nFlags & 0x1000) != 0 )
        {
          v62 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          v62 = flex_talk.m_pParent->m_Value.m_pszString;
          if ( v62 == nullptr )
            v62 = (char *)locale;
        }
        if ( v62 == "0" || _V_stricmp(s1: v62, s2: "0") == 0 )
          goto LABEL_134;
        if ( (flex_talk.m_nFlags & 0x1000) != 0 )
        {
          v63 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          v63 = flex_talk.m_pParent->m_Value.m_pszString;
          if ( v63 == nullptr )
            v63 = (char *)locale;
        }
        v61 = engine->SentenceIndexFromName(this: engine, a2: v63);
        if ( v61 >= 0 )
          goto LABEL_130;
      }
LABEL_133:
      ConVar::SetValue(this: (ConVar *)&flex_talk.IConVar, value: "0");
LABEL_134:
      if ( gpGlobals->curtime > this->m_blinktime )
      {
        LODWORD(v68) = this->m_blinktoggle.m_Value == 0;
        v105 = v68;
        if ( this->m_blinktoggle.m_Value != LODWORD(v68) )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v69 = this->m_Network.m_pPev;
            if ( v69 != nullptr )
            {
              CBaseEdict::StateChanged(this: &v69->CBaseEdict, offset: 0x62Cu);
              v68 = v105;
            }
          }
          *(float *)&this->m_blinktoggle.m_Value = v68;
        }
        this->m_blinktime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                              a1: random,
                              a2: 1069547520,
                              a3: 1083179008)
                          + gpGlobals->curtime;
      }
      goto LABEL_142;
    }
    goto LABEL_69;
  }
LABEL_142:
  GetVectors = this->GetVectors;
  value = COERCE_FLOAT(&szExpression[120]);
  ((void (__thiscall *)(CFlexCycler *, float *, Vector *))GetVectors)(a1: this, a2: &right.y, a3: &up);
  LocalPlayer = UTIL_GetLocalPlayer();
  if ( LocalPlayer == nullptr )
    return;
  v72 = (float *)((int (__thiscall *)(CBasePlayer *, bool *, float))LocalPlayer->GetSmoothedVelocity)(
                   a1: LocalPlayer,
                   a2: &filter.m_bUsingPredictionRules,
                   a3: COERCE_FLOAT(LODWORD(value)));
  v73 = 0;
  *(float *)&v73 = fsqrt((float)((float)(*v72 * *v72) + (float)(v72[1] * v72[1])) + (float)(v72[2] * v72[2]));
  *(_OWORD *)&filter.m_bReliable = v73;
  if ( *(float *)&v73 != 0.0 )
  {
    v105 = COERCE_FLOAT((int)this->EyePosition(this, result: &filter.m_bUsingPredictionRules));
    v74 = (float *)LocalPlayer->EyePosition(this: LocalPlayer, result: &forward);
    if ( (float)((float)((float)((float)(*v74 - *(float *)LODWORD(v105)) * right.y)
                       + (float)(right.z * (float)(v74[1] - *(float *)(LODWORD(v105) + 4))))
               + (float)(v95 * (float)(v74[2] - *(float *)(LODWORD(v105) + 8)))) > 0.5 )
    {
      v75 = (float *)((int (__thiscall *)(CBasePlayer *, bool *, _DWORD, _DWORD))LocalPlayer->EyePosition)(
                       a1: LocalPlayer,
                       a2: &filter.m_bUsingPredictionRules,
                       a3: LODWORD(v109),
                       a4: HIDWORD(v109));
      HIDWORD(v109) = 1082130432;
      v76 = 0x40000000;
LABEL_157:
      v87 = *v75;
      LODWORD(v109) = v76;
      this->m_lookTarget.x = v87;
      this->m_lookTarget.y = v75[1];
      this->m_lookTarget.z = v75[2];
      this->m_looktime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                           a1: random,
                           a2: LODWORD(v109),
                           a3: HIDWORD(v109))
                       + gpGlobals->curtime;
      goto LABEL_158;
    }
  }
  if ( gpGlobals->curtime > this->m_looktime )
  {
    if ( this->m_istalking == 0 && random->RandomInt(this: random, a2: 0, a3: 1) == 0 )
    {
      v77 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: -1040187392,
              a3: 1107296256);
      v78 = random->RandomFloat;
      *(float *)&filter.m_bUsingPredictionRules = *(float *)&szExpression[120] * v77;
      v99 = *(float *)&szExpression[124] * v77;
      v100 = v77 * v92;
      v105 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v78)(a1: random, a2: -1031798784, a3: 1115684864);
      EyePosition = this->EyePosition;
      forward.x = up.x * v105;
      forward.y = up.y * v105;
      forward.z = up.z * v105;
      *(float *)&i = right.y * 128.0;
      *((float *)&i + 1) = right.z * 128.0;
      v105 = v95 * 128.0;
      v80 = (float *)EyePosition(this, result: (Vector *)&filter.m_Recipients);
      v81 = (float)((float)(v80[1] + *((float *)&i + 1)) + forward.y) + v99;
      v82 = (float)((float)(v80[2] + v105) + forward.z) + v100;
      this->m_lookTarget.x = (float)((float)(*v80 + *(float *)&i) + forward.x)
                           + *(float *)&filter.m_bUsingPredictionRules;
      this->m_lookTarget.y = v81;
      this->m_lookTarget.z = v82;
      v83 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1050253722,
              a3: 1065353216);
      m_blinktime = this->m_blinktime;
      this->m_looktime = v83 + gpGlobals->curtime;
      if ( gpGlobals->curtime > (float)(m_blinktime - 0.5) )
      {
        LODWORD(v85) = this->m_blinktoggle.m_Value == 0;
        v105 = v85;
        if ( this->m_blinktoggle.m_Value != LODWORD(v85) )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
            *(float *)&this->m_blinktoggle.m_Value = v85;
          }
          else
          {
            v86 = this->m_Network.m_pPev;
            if ( v86 != nullptr )
            {
              CBaseEdict::StateChanged(this: &v86->CBaseEdict, offset: 0x62Cu);
              v85 = v105;
            }
            *(float *)&this->m_blinktoggle.m_Value = v85;
          }
        }
      }
      goto LABEL_158;
    }
    v75 = (float *)((int (__thiscall *)(CBasePlayer *, CUtlVector<int,CUtlMemory<int,int> > *, _DWORD, _DWORD))LocalPlayer->EyePosition)(
                     a1: LocalPlayer,
                     a2: &filter.m_Recipients,
                     a3: LODWORD(v109),
                     a4: HIDWORD(v109));
    HIDWORD(v109) = 1082130432;
    v76 = 1065353216;
    goto LABEL_157;
  }
LABEL_158:
  this->SetViewtarget(this, a2: &this->m_lookTarget);
}

//------------------------------------------------------------------------------
// Address: 0x100D3470
// Name: public: virtual CBaseFlex::~CBaseFlex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::~CBaseFlex(CBaseFlex *this)
{
  this->__vftable = (CBaseFlex_vtbl *)&CBaseFlex::`vftable';
  CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_LocalToGlobal);
  this->m_SceneEvents.m_Size = 0;
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ActiveChoreoScenes);
  CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::~CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>(this: &this->m_LocalToGlobal);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SceneEvents);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_AnimOverlay);
  CBaseAnimating::~CBaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D34D0
// Name: public: void CBaseFlex::StartChoreoScene(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::StartChoreoScene(CBaseFlex *this, CChoreoScene *scene)
{
  int m_Size; // ecx
  int v4; // eax
  CChoreoScene **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CChoreoScene **v8; // ecx
  int v9; // eax
  CChoreoScene **v10; // eax

  m_Size = this->m_ActiveChoreoScenes.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = this->m_ActiveChoreoScenes.m_Memory.m_pMemory;
  while ( *m_pMemory != scene )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = this->m_ActiveChoreoScenes.m_Memory.m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ActiveChoreoScenes,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ActiveChoreoScenes.m_Size;
    v8 = this->m_ActiveChoreoScenes.m_Memory.m_pMemory;
    v9 = this->m_ActiveChoreoScenes.m_Size - v7 - 1;
    this->m_ActiveChoreoScenes.m_pElements = v8;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &this->m_ActiveChoreoScenes.m_Memory.m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = scene;
    this->m_bUpdateLayerPriorities = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3580
// Name: public: void CBaseFlex::AddSceneEvent(class CChoreoScene __near *,class CChoreoEvent __near *,class CBaseEntity __near *,class CSceneEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::AddSceneEvent(
        CBaseFlex *this,
        CChoreoActor *scene,
        CChoreoEvent *event,
        CBaseEntity *pTarget,
        CSceneEntity *pSceneEntity)
{
  CSceneEventInfo info; // [esp+8h] [ebp-50h] BYREF
  CBaseFlex *v7; // [esp+54h] [ebp-4h]
  CChoreoActor *actor; // [esp+60h] [ebp+8h]

  v7 = this;
  if ( scene != nullptr && event != nullptr )
  {
    actor = CChoreoEvent::GetActor(this: event);
    if ( actor != nullptr )
    {
      memset(dst: (unsigned __int8 *)&info, value: 0, count: sizeof(info));
      info.m_pEvent = event;
      info.m_pScene = (CChoreoScene *)scene;
      if ( pTarget != nullptr )
        info.m_hTarget.m_Index = pTarget->GetRefEHandle(this: pTarget)->m_Index;
      else
        info.m_hTarget.m_Index = -1;
      info.m_bStarted = false;
      if ( pSceneEntity != nullptr )
        info.m_hSceneEntity.m_Index = pSceneEntity->GetRefEHandle(this: pSceneEntity)->m_Index;
      else
        info.m_hSceneEntity.m_Index = -1;
      if ( v7->StartSceneEvent(this: v7, a2: &info, a3: (CChoreoScene *)scene, a4: event, a5: actor, a6: pTarget) )
        CUtlVector<CSceneEventInfo,CUtlMemory<CSceneEventInfo,int>>::InsertBefore(
          this: &v7->m_SceneEvents,
          elem: v7->m_SceneEvents.m_Size,
          src: &info);
      else
        Scene_Printf(pFormat: "CBaseFlex::AddSceneEvent:  event failed\n");
    }
    else
    {
      _Msg(a1: "CBaseFlex::AddSceneEvent:  event->GetActor() was NULL!!!\n");
    }
  }
  else
  {
    _Msg(a1: "CBaseFlex::AddSceneEvent:  scene or event was NULL!!!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3690
// Name: private: bool CBaseFlex::HandleStartSequenceSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *,class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::HandleStartSequenceSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event,
        CChoreoActor *actor)
{
  const char *Parameters; // eax
  int v7; // eax
  const char *v8; // esi
  const char *v9; // eax
  const char *pszValue; // esi
  const char *v12; // eax
  CChoreoChannel *Channel; // eax
  int ScenePriority; // eax
  int v15; // eax
  CStudioHdr *m_pStudioHdr; // eax
  const char *flWeight; // [esp+4h] [ebp-10h]
  const char *flWeighta; // [esp+4h] [ebp-10h]
  float flCycle; // [esp+28h] [ebp+14h]
  float flCyclea; // [esp+28h] [ebp+14h]
  float flCycleb; // [esp+28h] [ebp+14h]

  Parameters = CChoreoEvent::GetParameters(this: event);
  v7 = CBaseAnimating::LookupSequence(this, label: Parameters);
  info->m_nSequence = v7;
  info->m_iLayer = -1;
  if ( v7 >= 0 )
  {
    if ( CBaseFlex::EnterSceneSequence(this, scene, event, bRestart: false) != 0
      || CChoreoEvent::GetPlayOverScript(this: event) )
    {
      Channel = CChoreoEvent::GetChannel(this: event);
      info->m_iPriority = CChoreoActor::FindChannelIndex(this: actor, channel: Channel);
      ScenePriority = CBaseFlex::GetScenePriority(this, scene);
      v15 = CBaseAnimatingOverlay::AddLayeredSequence(
              this,
              sequence: info->m_nSequence,
              iPriority: info->m_iPriority + ScenePriority);
      info->m_iLayer = v15;
      CBaseAnimatingOverlay::SetLayerNoRestore(this, iLayer: v15, bNoRestore: true);
      CBaseAnimatingOverlay::SetLayerWeight(this, iLayer: info->m_iLayer, flWeight: 0.0);
      if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
        CBaseAnimating::LockStudioHdr(this);
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
        m_pStudioHdr = nullptr;
      if ( (GetSequenceFlags(pstudiohdr: m_pStudioHdr, sequence: info->m_nSequence) & 1) != 0 )
      {
        CBaseAnimatingOverlay::SetLayerPlaybackRate(this, iLayer: info->m_iLayer, flPlaybackRate: 1.0);
      }
      else
      {
        flCycle = CBreakableProp::GetDmgModClub(this: scene);
        flCyclea = flCycle - CChoreoEvent::GetStartTime(this: event);
        flCycleb = flCyclea / CBaseAnimating::SequenceDuration(this, iSequence: info->m_nSequence);
        CBaseAnimatingOverlay::SetLayerCycle(
          this,
          iLayer: info->m_iLayer,
          flCycle: flCycleb - (float)(int)flCycleb,
          flPrevCycle: flCycleb - (float)(int)flCycleb);
        CBaseAnimatingOverlay::SetLayerPlaybackRate(this, iLayer: info->m_iLayer, flPlaybackRate: 0.0);
      }
      if ( this->IsMoving(this) )
        info->m_flWeight = 0.0;
      else
        info->m_flWeight = 1.0;
      return 1;
    }
    else
    {
      pszValue = this->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      flWeighta = CChoreoEvent::GetParameters(this: event);
      v12 = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: (vgui::Panel *)actor);
      _Warning(a1: "CSceneEntity %s :\"%s\" failed to start sequence \"%s\"\n", pszValue, v12, flWeighta);
      return 0;
    }
  }
  else
  {
    v8 = this->m_iName.m_Value.pszValue;
    if ( v8 == nullptr )
      v8 = locale;
    flWeight = CChoreoEvent::GetParameters(this: event);
    v9 = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: (vgui::Panel *)actor);
    _Warning(a1: "CSceneEntity %s :\"%s\" unable to find sequence \"%s\"\n", v8, v9, flWeight);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3890
// Name: private: bool CBaseFlex::StartMoveToSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *,class CChoreoActor __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::StartMoveToSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event,
        CChoreoActor *actor,
        CBaseEntity *pTarget)
{
  CAI_BaseNPC *v7; // esi

  if ( pTarget == nullptr )
    return 0;
  *(_WORD *)&info->m_bIsMoving = 0;
  v7 = this->MyNPCPointer(this);
  if ( v7 == nullptr )
    return 0;
  CBaseFlex::EnterSceneSequence(this, scene, event, bRestart: true);
  if ( v7->IsMoving(this: v7) && (*((_BYTE *)scene + 528) & 0x10) == 0 )
    CAI_Navigator::StopMoving(this: v7->m_pNavigator, bImmediate: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D3910
// Name: public: virtual bool CBaseFlex::StartSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *,class CChoreoActor __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::StartSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event,
        CChoreoActor *actor,
        CBaseEntity *pTarget)
{
  char result; // al

  switch ( CChoreoEvent::GetType(this: event) )
  {
    case EXPRESSION:
    case SPEAK:
      goto $LN2_12;
    case LOOKAT:
      CHandle<CBaseEntity>::operator=(this: &info->m_hTarget, val: pTarget);
$LN2_12:
      result = 1;
      break;
    case MOVETO:
      result = CBaseFlex::StartMoveToSceneEvent(this, info, scene, event, actor, pTarget);
      break;
    case GESTURE:
      result = CBaseFlex::RequestStartGestureSceneEvent(this, info, scene, event, actor, pTarget);
      break;
    case SEQUENCE:
      result = CBaseFlex::RequestStartSequenceSceneEvent(this, info, scene, event, actor, pTarget);
      break;
    case FACE:
      result = CBaseFlex::StartFacingSceneEvent(this, info, scene, event, actor, pTarget);
      break;
    case FLEXANIMATION:
      if ( CBaseFlex::IsSuppressedFlexAnimation(this, info) )
        info->m_flWeight = 0.0;
      else
        info->m_flWeight = 1.0;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D3A30
// Name: private: bool CBaseFlex::ProcessFacingSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::ProcessFacingSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  unsigned int m_Index; // eax
  CHandle<CBaseEntity> *p_m_hTarget; // esi
  unsigned int v8; // eax
  CBaseFlex *m_pEntity; // ecx
  CAI_BaseNPC *v10; // esi
  CAI_BaseNPC_vtbl *v11; // edi
  CBaseEntity *v12; // eax
  CBaseEntity *v14; // eax
  CAI_BaseNPC_vtbl *v15; // edi
  int v16; // eax
  float scenetime; // [esp+Ch] [ebp-1Ch]
  Vector v18; // [esp+1Ch] [ebp-Ch] BYREF
  CHandle<CBaseEntity> *infoa; // [esp+30h] [ebp+8h]
  float intensity; // [esp+34h] [ebp+Ch]
  float goalYaw; // [esp+38h] [ebp+10h]
  float goalYawa; // [esp+38h] [ebp+10h]

  m_Index = info->m_hTarget.m_Index;
  p_m_hTarget = &info->m_hTarget;
  infoa = &info->m_hTarget;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
    && CBaseFlex::EnterSceneSequence(this, scene, event, bRestart: true) != 0 )
  {
    if ( !info->m_bStarted )
      info->m_flInitialYaw = this->m_angRotation.m_Value.y;
    v8 = p_m_hTarget->m_Index;
    if ( p_m_hTarget->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseFlex *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
    if ( m_pEntity == this )
      return 1;
    v10 = this->MyNPCPointer(this);
    if ( v10 != nullptr )
    {
      if ( info->m_bIsMoving != this->IsMoving(this) )
        info->m_flInitialYaw = this->m_angRotation.m_Value.y;
      info->m_bIsMoving = this->IsMoving(this);
      scenetime = CBreakableProp::GetDmgModClub(this: scene);
      intensity = CChoreoEvent::GetIntensity(this: event, scenetime);
      if ( info->m_bIsMoving )
      {
        v11 = v10->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v12 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: infoa);
        ((void (__thiscall *)(CAI_BaseNPC *, CBaseEntity *, float, int, _DWORD))v11->AddFacingTarget)(
          a1: v10,
          a2: v12,
          a3: COERCE_FLOAT(LODWORD(intensity)),
          a4: 1045220557,
          a5: 0);
        return 1;
      }
      v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: infoa);
      v15 = v10->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v16 = (int)v14->EyePosition(this: v14, result: &v18);
      goalYaw = v15->CalcIdealYaw(this: v10, a2: (const Vector *)v16);
      goalYawa = AngleDiff(destAngle: goalYaw, srcAngle: info->m_flInitialYaw);
      CAI_Motor::SetIdealYawAndUpdate(
        this: v10->m_pMotor,
        idealYaw: (float)(unsigned __int16)(int)(float)((float)((float)(goalYawa * intensity) + info->m_flInitialYaw) * 182.04445)
      * 0.0054931641,
        yawSpeed: -1.0);
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D3C20
// Name: private: bool CBaseFlex::ProcessMoveToSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CBaseFlex::ProcessMoveToSceneEvent@<al>(
        CBaseFlex *this@<ecx>,
        int a2@<ebp>,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  unsigned int m_Index; // eax
  CHandle<CBaseEntity> *p_m_hTarget; // edi
  CAI_BaseNPC *v7; // esi
  int v9; // eax
  CBaseEntity *v10; // eax
  double v11; // st7
  bool v12; // zf
  CBaseEntity *v13; // edi
  const Vector *v14; // eax
  Vector *(__thiscall *v15)(CBaseEntity *, Vector *); // edx
  float *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm0_4
  __int128 v19; // xmm1
  double v20; // xmm0_8
  double DistanceToTarget; // st7
  double v22; // xmm0_8
  CAI_BaseNPC_vtbl *v23; // edi
  CBaseEntity *v24; // eax
  CBaseEntity *v25; // eax
  CBaseEntity *v26; // eax
  CAI_MoveProbe *v27; // edi
  const Vector *v28; // eax
  const Vector *v29; // eax
  const Vector *v30; // eax
  CAI_Navigator *v31; // edi
  CBaseEntity *v32; // edi
  const Vector *AbsOrigin; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v35; // eax
  float v36; // xmm1_4
  float v37; // xmm0_4
  __int128 v38; // xmm1
  const Vector *GoalPos; // eax
  unsigned int m_nAITraceMask; // edx
  CAI_MoveProbe *m_pMoveProbe; // ecx
  unsigned int v42; // eax
  CAI_Navigator *m_pNavigator; // ecx
  int v44; // edi
  const Vector *v45; // eax
  const Vector *v46; // eax
  const Vector *v47; // eax
  const Vector *v48; // [esp+18h] [ebp-B4h]
  const Vector *v49; // [esp+18h] [ebp-B4h]
  int v50; // [esp+1Ch] [ebp-B0h]
  unsigned int v51; // [esp+20h] [ebp-ACh]
  int tolerance; // [esp+24h] [ebp-A8h]
  float duration; // [esp+2Ch] [ebp-A0h]
  _BYTE v54[12]; // [esp+40h] [ebp-8Ch] BYREF
  __int128 goal_36; // [esp+70h] [ebp-5Ch] OVERLAPPED BYREF
  Vector v56; // [esp+88h] [ebp-44h] BYREF
  Vector vecStart; // [esp+94h] [ebp-38h] BYREF
  Vector v58; // [esp+A0h] [ebp-2Ch] BYREF
  Vector vTestPoint; // [esp+ACh] [ebp-20h]
  float v60; // [esp+B8h] [ebp-14h]
  Activity moveActivity; // [esp+BCh] [ebp-10h]
  int b; // [esp+C0h] [ebp-Ch]
  int r; // [esp+C4h] [ebp-8h]
  int retaddr; // [esp+CCh] [ebp+0h]

  b = a2;
  r = retaddr;
  m_Index = info->m_hTarget.m_Index;
  p_m_hTarget = &info->m_hTarget;
  moveActivity = (Activity)this;
  LODWORD(vTestPoint.z) = &info->m_hTarget;
  if ( m_Index == -1 )
    return 0;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return 0;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    return 0;
  v7 = this->MyNPCPointer(this);
  if ( v7 == nullptr
    || CBaseFlex::EnterSceneSequence(this: (CBaseFlex *)moveActivity, scene, event, bRestart: true) == 0 )
  {
    return 0;
  }
  if ( CHandle<CBaseEntity>::operator==(this: p_m_hTarget, val: (CBaseEntity *)moveActivity) )
    return 1;
  if ( v7->IsInAVehicle(this: v7) )
  {
    v7->ExitVehicle(this: v7);
    return 0;
  }
  v60 = COERCE_FLOAT(CAI_BaseNPC::GetTask(this: v7));
  if ( info->m_bIsMoving
    || (*(unsigned __int8 (__thiscall **)(Activity))(*(_DWORD *)moveActivity + 312))(a1: moveActivity) != 0
    && *(_DWORD *)LODWORD(v60) != 125 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(Activity))(*(_DWORD *)moveActivity + 312))(a1: moveActivity) == 0 )
    {
      info->m_bIsMoving = false;
      goto LABEL_40;
    }
    v32 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hTarget);
    AbsOrigin = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)moveActivity);
    EyePosition = v32->EyePosition;
    LODWORD(v58.z) = AbsOrigin;
    v35 = (float *)EyePosition(this: v32, result: (Vector *)((char *)&goal_36 + 4));
    v36 = v35[1] - *(float *)(LODWORD(v58.z) + 4);
    v37 = (float)((float)(*v35 - *(float *)LODWORD(v58.z)) * (float)(*v35 - *(float *)LODWORD(v58.z)))
        + (float)(v36 * v36);
    v38 = 0;
    *(float *)&v38 = fsqrt(v37);
    goal_36 = v38;
    if ( CChoreoEvent::GetDistanceToTarget(this: event) >= (double)*(float *)&v38 )
    {
      CAI_Navigator::StopMoving(this: v7->m_pNavigator, bImmediate: false);
LABEL_38:
      info->m_bHasArrived = true;
    }
LABEL_40:
    if ( developer.m_pParent != nullptr
      && developer.m_pParent->m_Value.m_nValue > 0
      && scene_showmoveto.m_pParent != nullptr
      && scene_showmoveto.m_pParent->m_Value.m_nValue != 0
      && (*(unsigned __int8 (__thiscall **)(Activity))(*(_DWORD *)moveActivity + 312))(a1: moveActivity) != 0 )
    {
      GoalPos = CAI_Navigator::GetGoalPos(this: v7->m_pNavigator);
      m_nAITraceMask = v7->m_nAITraceMask;
      v56.x = GoalPos->x;
      v56.y = GoalPos->y;
      m_pMoveProbe = v7->m_pMoveProbe;
      v56.z = GoalPos->z;
      CAI_MoveProbe::FloorPoint(
        this: m_pMoveProbe,
        vecStart: &v56,
        collisionMask: m_nAITraceMask,
        flStartZ: 0.0,
        flEndZ: -64.0,
        pVecResult: &v58);
      v42 = v7->m_nAITraceMask;
      m_pNavigator = v7->m_pNavigator;
      v44 = 0;
      vTestPoint.z = 0.0;
      v60 = 0.0;
      if ( CAI_Navigator::CanFitAtPosition(
             this: m_pNavigator,
             vStartPos: &v58,
             collisionMask: v42,
             bIgnoreTransients: false,
             bAllowPlayerAvoid: true) )
      {
        if ( CAI_MoveProbe::CheckStandPosition(
               this: v7->m_pMoveProbe,
               vecStart: &v58,
               collisionMask: v7->m_nAITraceMask) )
        {
          v44 = 255;
          if ( !CChoreoEvent::IsResumeCondition(this: event) )
            LODWORD(v60) = 255;
        }
        else
        {
          v44 = 255;
          LODWORD(vTestPoint.z) = 255;
        }
      }
      else
      {
        LODWORD(v60) = 255;
      }
      vecStart.x = v58.x;
      vecStart.y = v58.y;
      vecStart.z = v58.z + 1.0;
      v45 = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)moveActivity);
      *(_QWORD *)((char *)&goal_36 + 4) = *(_QWORD *)&v45->x;
      *((float *)&goal_36 + 3) = v45->z + 1.0;
      NDebugOverlay::HorzArrow(
        startPos: (const Vector *)((char *)&goal_36 + 4),
        endPos: &vecStart,
        width: 4.0,
        r: SLODWORD(v60),
        g: v44,
        b: SLODWORD(vTestPoint.z),
        a: 0,
        noDepthTest: false,
        flDuration: 0.12);
      v46 = NAI_Hull::Maxs(id: v7->m_eHull);
      tolerance = LODWORD(vTestPoint.z);
      v50 = LODWORD(v60);
      v49 = v46;
      v47 = NAI_Hull::Mins(id: v7->m_eHull);
      NDebugOverlay::Box(origin: &v58, mins: v47, maxs: v49, r: v50, g: v44, b: tolerance, a: 0, flDuration: 0.12);
    }
    return 1;
  }
  if ( v60 == 0.0 )
    goto LABEL_40;
  v9 = *(_DWORD *)LODWORD(v60);
  if ( *(_DWORD *)LODWORD(v60) != 122 && v9 != 130 && v9 != 125 )
    goto LABEL_40;
  LODWORD(vTestPoint.y) = DetermineExpressionMoveActivity(pNPC: v7);
  v10 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hTarget);
  CAI_BaseNPC::SetTarget(this: v7, pTarget: v10);
  v11 = NAI_Hull::Width(id: v7->m_eHull);
  v12 = (*((_BYTE *)event + 377) & 0x10) == 0;
  v60 = v11 * 0.5;
  if ( !v12 )
    v60 = 0.1;
  AI_NavGoal_t::AI_NavGoal_t(
    this: (AI_NavGoal_t *)v54,
    type: GOALTYPE_TARGETENT,
    activity: SLODWORD(vTestPoint.y),
    tolerance: v60,
    flags: 2u,
    pTarget: AIN_DEF_TARGET_58);
  v13 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hTarget);
  v14 = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)moveActivity);
  v15 = v13->EyePosition;
  LODWORD(v58.z) = v14;
  v16 = (float *)v15(this: v13, result: (Vector *)((char *)&goal_36 + 4));
  v17 = v16[1] - *(float *)(LODWORD(v58.z) + 4);
  v18 = (float)((float)(*v16 - *(float *)LODWORD(v58.z)) * (float)(*v16 - *(float *)LODWORD(v58.z)))
      + (float)(v17 * v17);
  v19 = 0;
  *(float *)&v19 = v18;
  v20 = 0.1;
  *(float *)&v19 = fsqrt(*(float *)&v19);
  goal_36 = v19;
  if ( v60 > 0.1 )
    v20 = v60;
  *(double *)&v58.x = v20;
  DistanceToTarget = CChoreoEvent::GetDistanceToTarget(this: event);
  if ( *(double *)&v58.x <= DistanceToTarget )
  {
    *(double *)&v58.x = CChoreoEvent::GetDistanceToTarget(this: event);
    v22 = *(double *)&v58.x;
  }
  else
  {
    v22 = 0.1;
    if ( v60 > 0.1 )
      v22 = v60;
  }
  if ( *(float *)&goal_36 <= v22 )
    goto LABEL_38;
  v23 = v7->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  v24 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)LODWORD(vTestPoint.z));
  if ( !v23->IsUnreachable(this: v7, a2: v24) )
  {
    if ( v7->m_pNavigator->SetGoal(this: v7->m_pNavigator, a2: (const AI_NavGoal_t *)v54, a3: 2u) )
    {
      CAI_Navigator::SetMovementActivity(this: v7->m_pNavigator, activity: SLODWORD(vTestPoint.y));
      v31 = v7->m_pNavigator;
      duration = CChoreoEvent::GetDistanceToTarget(this: event);
      CAI_Navigator::SetArrivalDistance(this: v31, flDistance: duration);
      info->m_bIsMoving = true;
      goto LABEL_40;
    }
    v25 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)LODWORD(vTestPoint.z));
    CAI_BaseNPC::RememberUnreachable(this: v7, pEntity: v25, duration: 1.5);
  }
  if ( developer.m_pParent != nullptr )
  {
    if ( developer.m_pParent->m_Value.m_nValue > 0
      && scene_showmoveto.m_pParent != nullptr
      && scene_showmoveto.m_pParent->m_Value.m_nValue != 0 )
    {
      v26 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)LODWORD(vTestPoint.z));
      v27 = v7->m_pMoveProbe;
      v51 = v7->m_nAITraceMask;
      v28 = v26->EyePosition(this: v26, result: (Vector *)((char *)&goal_36 + 4));
      CAI_MoveProbe::FloorPoint(
        this: v27,
        vecStart: v28,
        collisionMask: v51,
        flStartZ: 0.0,
        flEndZ: -64.0,
        pVecResult: &v58);
      vecStart.x = v58.x;
      vecStart.y = v58.y;
      vecStart.z = v58.z + 1.0;
      v29 = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)moveActivity);
      v56.x = v29->x;
      v56.y = v29->y;
      v56.z = v29->z + 1.0;
      NDebugOverlay::HorzArrow(
        startPos: &v56,
        endPos: &vecStart,
        width: 4.0,
        r: 255,
        g: 0,
        b: 255,
        a: 0,
        noDepthTest: false,
        flDuration: 0.12);
      v48 = NAI_Hull::Maxs(id: v7->m_eHull);
      v30 = NAI_Hull::Mins(id: v7->m_eHull);
      NDebugOverlay::Box(origin: &v58, mins: v30, maxs: v48, r: 255, g: 0, b: 255, a: 0, flDuration: 0.12);
    }
    goto LABEL_40;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D42B0
// Name: private: bool CBaseFlex::ProcessSequenceSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::ProcessSequenceSceneEvent(CBaseFlex *this, float info, CChoreoScene *scene, float event)
{
  float v4; // edi
  CChoreoScene *v6; // ecx
  char v7; // bl
  char result; // al
  bool v9; // bl
  CAI_BaseNPC *v10; // eax
  Activity m_Activity; // eax
  const char *pszValue; // eax
  __int64 v13; // xmm1_8
  double v14; // xmm0_8
  bool v15; // cc
  float v16; // xmm0_4
  int v17; // ecx
  CStudioHdr *ModelPtr; // eax
  double StartTime; // st7
  double v20; // st7
  int ScenePriority; // eax
  float scenetime; // [esp+0h] [ebp-1Ch]
  float scenetimea; // [esp+0h] [ebp-1Ch]
  int scenetimeb; // [esp+0h] [ebp-1Ch]
  int scenetimec; // [esp+0h] [ebp-1Ch]
  double maxVal; // [esp+10h] [ebp-Ch] BYREF
  CAI_BaseNPC *myNpc; // [esp+18h] [ebp-4h]

  v4 = info;
  if ( info != 0.0 && event != 0.0 )
  {
    v6 = scene;
    if ( scene != nullptr )
    {
      v7 = 0;
      if ( *(_DWORD *)(LODWORD(info) + 20) == -2 )
      {
        result = CBaseFlex::HandleStartSequenceSceneEvent(
                   this,
                   info: (CSceneEventInfo *)LODWORD(info),
                   scene,
                   event: (CChoreoEvent *)LODWORD(event),
                   actor: *(CChoreoActor **)(LODWORD(info) + 8));
        if ( result == 0 )
          return result;
        v6 = scene;
        HIBYTE(info) = 1;
        v7 = 1;
      }
      if ( *(int *)(LODWORD(v4) + 20) < 0 )
        return 1;
      scenetime = CBreakableProp::GetDmgModClub(this: v6);
      info = CChoreoEvent::GetIntensity(this: (CChoreoEvent *)LODWORD(event), scenetime);
      if ( v7 != 0 )
        info = 0.0;
      v9 = this->IsMoving(this);
      v10 = this->MyNPCPointer(this);
      myNpc = v10;
      if ( v10 == nullptr
        || CAI_BaseNPC::IsCurSchedule(this: v10, schedId: 63, fIdeal: true)
        || (m_Activity = myNpc->m_Activity) == ACT_IDLE_ANGRY
        || m_Activity == ACT_IDLE )
      {
        if ( !v9 )
        {
          *(double *)&v13 = 1.0;
          v14 = *(float *)(LODWORD(v4) + 36) + 0.2;
          v15 = v14 >= 1.0;
          goto LABEL_21;
        }
      }
      else if ( *(float *)(LODWORD(v4) + 36) == 1.0 )
      {
        pszValue = this->m_iName.m_Value.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        _Warning(a1: "%s playing CChoreoEvent::SEQUENCE but AI has forced them to do something different\n", pszValue);
      }
      *(double *)&v13 = 0.0;
      v14 = *(float *)(LODWORD(v4) + 36) - 0.2;
      v15 = v14 <= 0.0;
LABEL_21:
      if ( v15 )
        v14 = *(double *)&v13;
      v16 = v14;
      v17 = *(_DWORD *)(LODWORD(v4) + 20);
      scenetimea = (float)((float)((float)(v16 * 3.0) * v16) - (float)((float)((float)(v16 * 2.0) * v16) * v16)) * info;
      *(float *)(LODWORD(v4) + 36) = v16;
      CBaseAnimatingOverlay::SetLayerWeight(this, iLayer: v17, flWeight: scenetimea);
      scenetimeb = *(_DWORD *)(LODWORD(v4) + 28);
      ModelPtr = CBaseAnimating::GetModelPtr(this);
      if ( (GetSequenceFlags(pstudiohdr: ModelPtr, sequence: scenetimeb) & 1) == 0 )
      {
        info = CBreakableProp::GetDmgModClub(this: scene);
        StartTime = CChoreoEvent::GetStartTime(this: (CChoreoEvent *)LODWORD(event));
        scenetimec = *(_DWORD *)(LODWORD(v4) + 28);
        event = info - StartTime;
        v20 = CBaseAnimating::SequenceDuration(this, iSequence: scenetimec);
        maxVal = 1.0;
        info = 0.0;
        event = event / v20;
        event = clamp<float,int,double>(val: &event, minVal: (const int *)&info, &maxVal);
        CBaseAnimatingOverlay::SetLayerCycle(this, iLayer: *(_DWORD *)(LODWORD(v4) + 20), flCycle: event);
      }
      if ( myNpc != nullptr )
        CAI_BaseNPC::AddSceneLock(this: myNpc, flDuration: 0.2);
      if ( this->m_bUpdateLayerPriorities )
      {
        ScenePriority = CBaseFlex::GetScenePriority(this, scene);
        CBaseAnimatingOverlay::SetLayerPriority(
          this,
          iLayer: *(_DWORD *)(LODWORD(v4) + 20),
          iPriority: *(_DWORD *)(LODWORD(v4) + 24) + ScenePriority);
      }
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D4580
// Name: public: void CFlexCycler::GenericCyclerSpawn(char __near *,class Vector,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexCycler::GenericCyclerSpawn(CFlexCycler *this, char *szModel, Vector vecMin, Vector vecMax)
{
  CStudioHdr *m_pStudioHdr; // eax
  Vector vecEyeOffset; // [esp+20h] [ebp-Ch] BYREF
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  if ( szModel != nullptr && *szModel != 0 )
  {
    CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))szModel, name: szModel, bPreload: true);
    this->SetModel(this, a2: szModel);
    CFlexCycler::Spawn(this);
    UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    GetEyePosition(pstudiohdr: m_pStudioHdr, vecEyePosition: &vecEyeOffset);
    this->SetViewOffset(this, a2: &vecEyeOffset);
    this->InitBoneControllers(this);
    if ( CBaseAnimating::GetNumFlexControllers(this) < 5 )
      _Warning(a1: "cycler_flex used on model %s without enough flexes.\n", szModel);
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
// Address: 0x100D48E0
// Name: public: CBaseFlex::CBaseFlex(void)
// Source: json
//------------------------------------------------------------------------------
CBaseFlex *__thiscall CBaseFlex::CBaseFlex(CBaseFlex *this)
{
  UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short> *m_pMemory; // ecx

  CBaseAnimating::CBaseAnimating(this);
  this->m_AnimOverlay.m_Memory.m_pMemory = nullptr;
  this->m_AnimOverlay.m_Memory.m_nAllocationCount = 0;
  this->m_AnimOverlay.m_Memory.m_nGrowSize = 0;
  this->m_AnimOverlay.m_Size = 0;
  this->m_AnimOverlay.m_pElements = nullptr;
  this->__vftable = (CBaseFlex_vtbl *)&CBaseFlex::`vftable';
  this->m_SceneEvents.m_Memory.m_pMemory = nullptr;
  this->m_SceneEvents.m_Memory.m_nAllocationCount = 0;
  this->m_SceneEvents.m_Memory.m_nGrowSize = 0;
  this->m_SceneEvents.m_Size = 0;
  this->m_SceneEvents.m_pElements = nullptr;
  this->m_LocalToGlobal.m_LessFunc = (bool (__cdecl *)(const CBaseFlex::FS_LocalToGlobal_t *, const CBaseFlex::FS_LocalToGlobal_t *))CDefOps<CChoreoActor *>::LessFunc;
  this->m_LocalToGlobal.m_Elements.m_pMemory = nullptr;
  this->m_LocalToGlobal.m_Elements.m_nAllocationCount = 0;
  this->m_LocalToGlobal.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_LocalToGlobal.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_LocalToGlobal.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_LocalToGlobal.m_FirstFree = -1;
  this->m_LocalToGlobal.m_pElements = m_pMemory;
  this->m_ActiveChoreoScenes.m_Memory.m_pMemory = nullptr;
  this->m_ActiveChoreoScenes.m_Memory.m_nAllocationCount = 0;
  this->m_ActiveChoreoScenes.m_Memory.m_nGrowSize = 0;
  this->m_ActiveChoreoScenes.m_Size = 0;
  this->m_ActiveChoreoScenes.m_pElements = nullptr;
  this->m_bUpdateLayerPriorities = true;
  this->m_flLastFlexAnimationTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D4A50
// Name: public: void CBaseFlex::EnsureTranslations(struct flexsettinghdr_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::EnsureTranslations(CBaseFlex *this, int pSettinghdr)
{
  int v2; // esi
  CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl*)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short> > *p_m_LocalToGlobal; // edi
  const char *v4; // ebx
  LocalFlexController_t v5; // edi
  const char *FlexControllerName; // eax
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // dx
  unsigned __int16 v9; // cx
  int v10; // esi
  UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short> *v11; // eax
  int v12; // edx
  UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short> *v14; // ecx
  const flexsettinghdr_t **p_m_Key; // esi
  const flexsettinghdr_t *v16; // eax
  const flexsettinghdr_t *v17; // [esp-4h] [ebp-24h]
  CBaseFlex::FS_LocalToGlobal_t entry; // [esp+Ch] [ebp-14h] BYREF
  CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl*)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short> > *v19; // [esp+18h] [ebp-8h]
  CBaseAnimating *v20; // [esp+1Ch] [ebp-4h] BYREF

  v2 = pSettinghdr;
  p_m_LocalToGlobal = &this->m_LocalToGlobal;
  v20 = this;
  entry.m_Key = (const flexsettinghdr_t *)pSettinghdr;
  entry.m_nCount = 0;
  entry.m_Mapping = nullptr;
  v19 = &this->m_LocalToGlobal;
  if ( CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_LocalToGlobal,
         search: &entry) == 0xFFFF )
  {
    entry.m_nCount = *(_DWORD *)(v2 + 96);
    entry.m_Mapping = (LocalFlexController_t *)operator new(nSize: 4 * entry.m_nCount);
    _V_memset(dest: entry.m_Mapping, fill: 0, count: 4 * entry.m_nCount);
    pSettinghdr = 0;
    if ( *(int *)(v2 + 96) > 0 )
    {
      do
      {
        v4 = (const char *)(v2 + *(_DWORD *)(4 * pSettinghdr + *(_DWORD *)(v2 + 100) + v2));
        v5 = DUMMY_NULL_FLEX_CONTROLLER;
        if ( CBaseAnimating::GetNumFlexControllers(this: v20) <= 0 )
        {
LABEL_6:
          v5 = DUMMY_NULL_FLEX_CONTROLLER;
        }
        else
        {
          while ( 1 )
          {
            FlexControllerName = CBaseAnimating::GetFlexControllerName(this: v20, iFlexController: v5);
            if ( _V_stricmp(s1: FlexControllerName, s2: v4) == 0 )
              break;
            if ( ++v5 >= CBaseAnimating::GetNumFlexControllers(this: v20) )
              goto LABEL_6;
          }
        }
        entry.m_Mapping[pSettinghdr++] = v5;
      }
      while ( pSettinghdr < *(_DWORD *)(v2 + 96) );
      p_m_LocalToGlobal = v19;
    }
    v20 = (CBaseAnimating *)0xFFFF;
    HIBYTE(pSettinghdr) = 0;
    CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: p_m_LocalToGlobal,
      insert: &entry,
      parent: (unsigned __int16 *)&v20,
      leftchild: (bool *)&pSettinghdr + 3);
    v7 = CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::NewNode(
           this: p_m_LocalToGlobal,
           a2: (const char *)p_m_LocalToGlobal);
    v8 = (unsigned __int16)v20;
    v9 = v7;
    v10 = v7;
    v11 = &p_m_LocalToGlobal->m_Elements.m_pMemory[v10];
    v11->m_Right = -1;
    v11->m_Left = -1;
    v11->m_Parent = v8;
    v11->m_Tag = 0;
    if ( v8 == 0xFFFF )
    {
      p_m_LocalToGlobal->m_Root = v9;
    }
    else
    {
      v12 = v8;
      m_pMemory = p_m_LocalToGlobal->m_Elements.m_pMemory;
      if ( HIBYTE(pSettinghdr) != 0 )
        m_pMemory[v12].m_Left = v9;
      else
        m_pMemory[v12].m_Right = v9;
    }
    CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: p_m_LocalToGlobal,
      elem: v9);
    v14 = p_m_LocalToGlobal->m_Elements.m_pMemory;
    ++p_m_LocalToGlobal->m_NumElements;
    p_m_Key = &v14[v10].m_Data.m_Key;
    if ( p_m_Key != nullptr )
    {
      v17 = p_m_Key[2];
      *p_m_Key = entry.m_Key;
      free(pMem: (void *)v17);
      v16 = (const flexsettinghdr_t *)operator new(nSize: 4 * entry.m_nCount);
      p_m_Key[2] = v16;
      _V_memcpy(dest: (void *)v16, src: entry.m_Mapping, count: 4 * entry.m_nCount);
      p_m_Key[1] = (const flexsettinghdr_t *)entry.m_nCount;
    }
  }
  free(pMem: entry.m_Mapping);
}

//------------------------------------------------------------------------------
// Address: 0x100D4C30
// Name: protected: enum LocalFlexController_t CBaseFlex::FlexControllerLocalToGlobal(struct flexsettinghdr_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
LocalFlexController_t __thiscall CBaseFlex::FlexControllerLocalToGlobal(
        CBaseFlex *this,
        const flexsettinghdr_t *pSettinghdr,
        int key)
{
  int v4; // esi
  const char *pszValue; // ecx
  edict_t *m_pPev; // eax
  LocalFlexController_t v7; // esi
  const char *v9; // [esp+0h] [ebp-18h]
  CBaseFlex::FS_LocalToGlobal_t entry; // [esp+Ch] [ebp-Ch] BYREF

  entry.m_nCount = 0;
  entry.m_Mapping = nullptr;
  entry.m_Key = pSettinghdr;
  v4 = CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_LocalToGlobal,
         search: &entry);
  if ( v4 == 0xFFFF )
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    _Warning(
      a1: "Unable to find mapping for flexcontroller %i, settings %p on %i/%s\n",
      key,
      pSettinghdr,
      m_pPev,
      pszValue);
    CBaseFlex::EnsureTranslations(this, (int)pSettinghdr);
    v4 = CUtlRBTree<CBaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(CBaseFlex::FS_LocalToGlobal_t const &,CBaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_LocalToGlobal,
           search: &entry);
    if ( v4 == 0xFFFF )
      _Error(this: (ISceneTokenProcessor *)&stru_1045034C, a2: v9);
  }
  v7 = this->m_LocalToGlobal.m_Elements.m_pMemory[(unsigned __int16)v4].m_Data.m_Mapping[key];
  free(pMem: entry.m_Mapping);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100D4D00
// Name: protected: void CBaseFlex::AddFlexSetting(char const __near *,float,struct flexsettinghdr_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::AddFlexSetting(
        CBaseFlex *this,
        const char *expr,
        float scale,
        const flexsettinghdr_t *pSettinghdr,
        bool newexpression)
{
  int v6; // esi
  const char *v7; // edi
  int v8; // esi
  bool v9; // zf
  float *v10; // esi
  int v11; // edi
  LocalFlexController_t v12; // eax
  float v13; // xmm0_4
  LocalFlexController_t v14; // edi
  float value; // [esp+10h] [ebp-8h]
  const char *expra; // [esp+20h] [ebp+8h]
  int s; // [esp+28h] [ebp+10h]
  float sa; // [esp+28h] [ebp+10h]

  v6 = 0;
  if ( pSettinghdr->numflexsettings > 0 )
  {
    s = 0;
    do
    {
      v7 = (char *)pSettinghdr + s + pSettinghdr->flexsettingindex;
      if ( v7 != nullptr && _V_stricmp(s1: &v7[*(_DWORD *)v7], s2: expr) == 0 )
        break;
      s += 24;
      ++v6;
    }
    while ( v6 < pSettinghdr->numflexsettings );
    if ( v6 < pSettinghdr->numflexsettings )
    {
      v8 = *((_DWORD *)v7 + 5);
      v9 = &v7[v8] == nullptr;
      v10 = (float *)&v7[v8];
      v11 = *((_DWORD *)v7 + 2);
      if ( !v9 && v11 > 0 )
      {
        for ( expra = (const char *)v11; expra != nullptr; --expra )
        {
          v12 = CBaseFlex::FlexControllerLocalToGlobal(this, pSettinghdr, key: *(_DWORD *)v10);
          v13 = v10[2] * scale;
          v14 = v12;
          if ( v13 >= 0.0 )
          {
            if ( v13 <= 1.0 )
              sa = v10[2] * scale;
            else
              sa = 1.0;
          }
          else
          {
            sa = 0.0;
          }
          value = sa * v10[1] + (1.0 - sa) * CBaseFlex::GetFlexWeight(this, index: v12);
          CBaseFlex::SetFlexWeight(this, index: v14, value);
          v10 += 3;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4E40
// Name: public: virtual void CGenericFlexCycler::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGenericFlexCycler::Spawn(CGenericFlexCycler *this@<ecx>, int a2@<esi>)
{
  char *v3; // ecx
  Vector v4; // [esp-18h] [ebp-34h]
  Vector v5; // [esp-Ch] [ebp-28h]
  _BYTE v7[4]; // [esp+18h] [ebp-4h] BYREF

  v3 = *(char **)((int (__thiscall *)(CGenericFlexCycler *, _BYTE *, int))this->GetModelName)(a1: this, a2: v7, a3: a2);
  if ( v3 == nullptr )
    v3 = (char *)locale;
  *(_QWORD *)&v5.x = 0x4180000041800000LL;
  v5.z = 72.0;
  *(_QWORD *)&v4.x = 0xC1800000C1800000uLL;
  v4.z = 0.0;
  CFlexCycler::GenericCyclerSpawn(this, szModel: v3, vecMin: v4, vecMax: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100D4F50
// Name: void InitCBaseFlexScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCBaseFlexScriptDesc()
{
  ScriptFunctionBinding_t *v0; // eax
  ScriptFunctionBinding_t *v1; // esi

  if ( !bInitialized_1 )
  {
    bInitialized_1 = true;
    g_CBaseFlex_ScriptDesc.m_pszDescription = "Animated characters who have vertex flex capability.";
    g_CBaseFlex_ScriptDesc.m_pszScriptName = "CBaseFlex";
    g_CBaseFlex_ScriptDesc.m_pszClassname = "CBaseFlex";
    g_CBaseFlex_ScriptDesc.m_pBaseDesc = GetScriptDesc(__formal: nullptr);
    g_CBaseFlex_ScriptDesc.pHelper = GetScriptInstanceHelper_CBaseAnimating();
    v0 = &g_CBaseFlex_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                         this: &g_CBaseFlex_ScriptDesc.m_FunctionBindings,
                                                                         elem: g_CBaseFlex_ScriptDesc.m_FunctionBindings.m_Size)];
    v0->m_desc.m_pszDescription = "Returns the instance of the oldest active scene entity (if any).";
    v0->m_desc.m_pszScriptName = "GetCurrentScene";
    v0->m_desc.m_pszFunction = "ScriptGetOldestScene";
    v0->m_desc.m_ReturnType = 33;
    v0->m_pfnBinding = CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v0->m_pFunction =  __thiscall CMolotovProjectile::`vcall'{952,{flat}};
    v0->m_flags = 1;
    v1 = &g_CBaseFlex_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                         this: &g_CBaseFlex_ScriptDesc.m_FunctionBindings,
                                                                         elem: g_CBaseFlex_ScriptDesc.m_FunctionBindings.m_Size)];
    v1->m_desc.m_pszDescription = "Returns the instance of the scene entity at the specified index.";
    v1->m_desc.m_pszScriptName = "GetSceneByIndex";
    v1->m_desc.m_pszFunction = "ScriptGetSceneByIndex";
    ScriptDeduceFunctionSignature<CBaseFlex *,CBaseFlex,HSCRIPT__ *,int>(
      pDesc: &v1->m_desc,
      pObject: nullptr,
      pfnProxied:  __thiscall CBaseFlex::`vcall'{956,{flat}});
    v1->m_pfnBinding = CMemberScriptBinding1<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *),HSCRIPT__ *,HSCRIPT__ *>::Call;
    v1->m_pFunction =  __thiscall CBaseFlex::`vcall'{956,{flat}};
    v1->m_flags = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5040
// Name: public: void const __near * CFlexSceneFileManager::FindSceneFile(class CBaseFlex __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFlexSceneFileManager::FindSceneFile(
        CFlexSceneFileManager *this,
        CBaseFlex *instance,
        char *filename,
        bool allowBlockingIO)
{
  int v5; // edi
  CFlexSceneFile *v6; // ebx
  IFileSystem_vtbl *v8; // edi
  char *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CFlexSceneFile **m_pMemory; // ecx
  int v13; // eax
  CFlexSceneFile **v14; // edi
  char szFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  _V_strcpy(dest: szFilename, src: filename);
  V_FixSlashes(pname: szFilename, separator: 92);
  v5 = 0;
  if ( this->m_FileList.m_Size <= 0 )
  {
LABEL_5:
    if ( !allowBlockingIO )
      return nullptr;
    filename = nullptr;
    v8 = filesystem->IAppSystem::__vftable;
    v9 = UTIL_VarArgs(format: "expressions/%s.vfe", szFilename);
    if ( v8->ReadFileEx(
           this: filesystem,
           a2: v9,
           a3: "GAME",
           a4: (void **)&filename,
           a5: false,
           a6: true,
           a7: 0,
           a8: 0,
           a9: nullptr) == 0 )
      return nullptr;
    v6 = (CFlexSceneFile *)operator new(nSize: 0x84u);
    V_strncpy(pDest: v6->filename, pSrc: szFilename, maxLen: 128);
    v6->buffer = filename;
    m_Size = this->m_FileList.m_Size;
    m_nAllocationCount = this->m_FileList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FileList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_FileList.m_Size;
    m_pMemory = this->m_FileList.m_Memory.m_pMemory;
    v13 = this->m_FileList.m_Size - m_Size - 1;
    this->m_FileList.m_pElements = m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
    v14 = &this->m_FileList.m_Memory.m_pMemory[m_Size];
    if ( v14 != nullptr )
      *v14 = v6;
  }
  else
  {
    while ( 1 )
    {
      v6 = this->m_FileList.m_Memory.m_pMemory[v5];
      if ( v6 != nullptr && _V_stricmp(s1: v6->filename, s2: szFilename) == 0 )
        break;
      if ( ++v5 >= this->m_FileList.m_Size )
        goto LABEL_5;
    }
  }
  if ( instance != nullptr )
    CBaseFlex::EnsureTranslations(this: instance, pSettinghdr: (int)v6->buffer);
  return v6->buffer;
}

//------------------------------------------------------------------------------
// Address: 0x100D51A0
// Name: protected: void const __near * CBaseFlex::FindSceneFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseFlex::FindSceneFile(CBaseFlex *this, char *filename)
{
  CBaseFlex *v2; // esi
  string_t (__thiscall *GetModelName)(struct CBaseEntity *); // edx
  const char *v4; // eax
  bool v5; // zf
  string_t (__thiscall *v6)(struct CBaseEntity *); // edx
  const char *v7; // eax
  char *v8; // eax
  char *v9; // edx
  char v10; // cl
  char *v11; // eax
  char *v12; // edx
  char v13; // cl
  int v14; // edi
  CFlexSceneFile *v15; // esi
  void *result; // eax
  char dest[260]; // [esp+Ch] [ebp-10Ch] BYREF
  char v18[4]; // [esp+110h] [ebp-8h] BYREF
  CBaseFlex *v19; // [esp+114h] [ebp-4h]

  v2 = this;
  GetModelName = this->GetModelName;
  v19 = this;
  v4 = *(const char **)((int (__stdcall *)(char *))GetModelName)(a1: v18);
  if ( v4 == nullptr )
    v4 = locale;
  v5 = StringAfterPrefix(str: v4, prefix: "models") == nullptr;
  v6 = v2->GetModelName;
  if ( v5 )
  {
    v11 = *(char **)((int (__thiscall *)(CBaseFlex *, char *))v6)(a1: v2, a2: v18);
    if ( v11 == nullptr )
      v11 = (char *)locale;
    v12 = (char *)(szExtendedPath - v11);
    do
    {
      v13 = *v11;
      v11[(_DWORD)v12] = *v11;
      ++v11;
    }
    while ( v13 != 0 );
  }
  else
  {
    v7 = *(const char **)((int (__thiscall *)(CBaseFlex *, char *))v6)(a1: v2, a2: v18);
    if ( v7 == nullptr )
      v7 = locale;
    v8 = (char *)(StringAfterPrefix(str: v7, prefix: "models") + 1);
    v9 = (char *)(szExtendedPath - v8);
    do
    {
      v10 = *v8;
      v8[(_DWORD)v9] = *v8;
      ++v8;
    }
    while ( v10 != 0 );
  }
  V_StripExtension(in: szExtendedPath, out: szExtendedPath, outSize: 260);
  V_FixupPathName(pOut: szExtendedPath, nOutLen: 0x104u, pPath: szExtendedPath);
  if ( _V_strlen(str: szExtendedPath) > 2 )
  {
    do
    {
      V_ComposeFileName(path: szExtendedPath, filename, dest: szExtendedName, destSize: 260);
      _V_strcpy(dest, src: szExtendedName);
      V_FixSlashes(pname: dest, separator: 92);
      v14 = 0;
      if ( g_FlexSceneFileManager.m_FileList.m_Size > 0 )
      {
        while ( 1 )
        {
          v15 = g_FlexSceneFileManager.m_FileList.m_Memory.m_pMemory[v14];
          if ( v15 != nullptr && _V_stricmp(s1: v15->filename, s2: dest) == 0 )
            break;
          if ( ++v14 >= g_FlexSceneFileManager.m_FileList.m_Size )
            goto LABEL_20;
        }
        CBaseFlex::EnsureTranslations(this: v19, pSettinghdr: (int)v15->buffer);
        result = v15->buffer;
        if ( result != nullptr )
          return result;
LABEL_20:
        v2 = v19;
      }
    }
    while ( V_StripLastDir(dirName: szExtendedPath, maxlen: 260) && _V_strlen(str: szExtendedPath) > 2 );
  }
  return CFlexSceneFileManager::FindSceneFile(
           this: &g_FlexSceneFileManager,
           instance: v2,
           filename,
           allowBlockingIO: false);
}

//------------------------------------------------------------------------------
// Address: 0x100D5350
// Name: private: bool CBaseFlex::ProcessFlexSettingSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::ProcessFlexSettingSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  char *Parameters; // ebx
  const char *Parameters2; // eax
  const flexsettinghdr_t *SceneFile; // eax
  const char *name; // [esp+18h] [ebp-8h]
  float scale; // [esp+30h] [ebp+10h]
  float scalea; // [esp+30h] [ebp+10h]

  if ( CChoreoEvent::CurveHasEndTime(this: event) )
  {
    Parameters = (char *)CChoreoEvent::GetParameters(this: event);
    Parameters2 = CChoreoEvent::GetParameters2(this: event);
    name = Parameters2;
    if ( Parameters != nullptr && Parameters2 != nullptr )
    {
      if ( info->m_pExpHdr != nullptr
        || (SceneFile = (const flexsettinghdr_t *)CBaseFlex::FindSceneFile(this, filename: Parameters),
            info->m_pExpHdr = SceneFile,
            SceneFile != nullptr) )
      {
        scale = CBreakableProp::GetDmgModClub(this: scene);
        scalea = CChoreoEvent::GetIntensity(this: event, scenetime: scale);
        CBaseFlex::AddFlexSetting(
          this,
          expr: name,
          scale: scalea,
          pSettinghdr: info->m_pExpHdr,
          newexpression: !info->m_bStarted);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D53F0
// Name: public: virtual bool CBaseFlex::ProcessSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFlex::ProcessSceneEvent(
        CBaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  char result; // al
  CChoreoEvent::EVENTTYPE Type; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  switch ( CChoreoEvent::GetType(this: event) )
  {
    case EXPRESSION:
      result = CBaseFlex::ProcessFlexSettingSceneEvent(this, info, scene, event);
      break;
    case LOOKAT:
      result = CBaseFlex::ProcessLookAtSceneEvent(this, info, scene, event);
      break;
    case MOVETO:
      result = CBaseFlex::ProcessMoveToSceneEvent(this, a2: (int)&savedregs, info, scene, event);
      break;
    case SPEAK:
      result = 1;
      break;
    case GESTURE:
      result = CBaseFlex::ProcessGestureSceneEvent(this, info, scene, event);
      break;
    case SEQUENCE:
      result = CBaseFlex::ProcessSequenceSceneEvent(this, info: *(float *)&info, scene, event: *(float *)&event);
      break;
    case FACE:
      result = CBaseFlex::ProcessFacingSceneEvent(this, info, scene, event);
      break;
    case FLEXANIMATION:
      result = CBaseFlex::ProcessFlexAnimationSceneEvent(this, info, scene, event);
      break;
    default:
      Type = CChoreoEvent::GetType(this: event);
      _Msg(a1: "unknown type %d in ProcessSceneEvent()\n", Type);
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D5560
// Name: public: virtual bool CFlexSceneFileManager::InitRecursive(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFlexSceneFileManager::InitRecursive(CFlexSceneFileManager *this, const char *pFolder)
{
  const char *v2; // ebx
  const char *i; // esi
  const char *FileExtension; // eax
  int v6; // eax
  char fullFileName[260]; // [esp+Ch] [ebp-410h] BYREF
  char folderpath[260]; // [esp+110h] [ebp-30Ch] BYREF
  char directory[260]; // [esp+214h] [ebp-208h] BYREF
  char vfeName[260]; // [esp+318h] [ebp-104h] BYREF

  v2 = pFolder;
  if ( pFolder == nullptr )
    v2 = "expressions";
  V_snprintf(pDest: directory, maxLen: 260, pFormat: "%s/*.*", v2);
  for ( i = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: directory, a3: &pFolder);
        i != nullptr;
        i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: pFolder) )
  {
    if ( _V_stricmp(s1: i, s2: ".") != 0 && _V_stricmp(s1: i, s2: "..") != 0 )
    {
      if ( g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: (int)pFolder) )
      {
        V_snprintf(pDest: folderpath, maxLen: 260, pFormat: "%s/%s", v2, i);
        this->InitRecursive(this, a2: folderpath);
      }
      else
      {
        FileExtension = V_GetFileExtension(path: i);
        if ( FileExtension == nullptr || _V_stricmp(s1: FileExtension, s2: "vfe") == 0 )
        {
          V_snprintf(pDest: fullFileName, maxLen: 260, pFormat: "%s/%s", v2, i);
          v6 = _V_strlen(str: "expressions/");
          V_StripExtension(in: &fullFileName[v6], out: vfeName, outSize: 260);
          V_FixSlashes(pname: vfeName, separator: 92);
          CFlexSceneFileManager::FindSceneFile(this, instance: nullptr, filename: vfeName, allowBlockingIO: true);
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D56E0
// Name: public: virtual bool CFlexSceneFileManager::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFlexSceneFileManager::Init(CFlexSceneFileManager *this)
{
  CFlexSceneFileManager::FindSceneFile(this, instance: nullptr, filename: "phonemes", allowBlockingIO: true);
  CFlexSceneFileManager::FindSceneFile(this, instance: nullptr, filename: "phonemes_weak", allowBlockingIO: true);
  CFlexSceneFileManager::FindSceneFile(this, instance: nullptr, filename: "phonemes_strong", allowBlockingIO: true);
  this->InitRecursive(this, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015DBF0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: m_pMemory,
                                                                                           a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CBaseFlex::FS_LocalToGlobal_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10400290
// Name: DT_BaseFlex::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseFlex::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseFlex::g_SendTable);
  return atexit(func: DT_BaseFlex::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104002B0
// Name: DT_BaseFlex::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseFlex::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseFlex::ignored>();
  DT_BaseFlex::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104002C0
// Name: CBaseFlex_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseFlex_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseFlex>();
  CBaseFlex_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104003C0
// Name: CFlexCycler_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFlexCycler_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFlexCycler>(__formal: nullptr);
  CFlexCycler_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400450
// Name: flexsettinghdr_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *flexsettinghdr_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<flexsettinghdr_t>();
  flexsettinghdr_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400460
// Name: flexsetting_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *flexsetting_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<flexsetting_t>();
  flexsetting_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400470
// Name: flexweight_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *flexweight_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<flexweight_t>();
  flexweight_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10418BE0
// Name: _CAI_BaseNPC::RebalanceThinks_::_13_::_dynamic_atexit_destructor_for__rebalanceCandidates__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_BaseNPC::RebalanceThinks_::_13_::_dynamic_atexit_destructor_for__rebalanceCandidates__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&rebalanceCandidates);
}

//------------------------------------------------------------------------------
// Address: 0x10418BF0
// Name: _CAI_BaseNPC::TranslateActivity_::_17_::_dynamic_atexit_destructor_for__sUniqueActivities__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_BaseNPC::TranslateActivity_::_17_::_dynamic_atexit_destructor_for__sUniqueActivities__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&sUniqueActivities);
}

//------------------------------------------------------------------------------
// Address: 0x10419DE0
// Name: DT_BaseFlex::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseFlex::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseFlex::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100D4500
// Name: struct datamap_t __near * DataMapInit<class CFlexCycler>(class CFlexCycler __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFlexCycler>()
{
  if ( (_S4_14 & 1) == 0 )
  {
    _S4_14 |= 1u;
    nameHolder_92.m_pszBase = "CFlexCycler";
    nameHolder_92.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_92.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_92.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_92.m_Names.m_Size = 0;
    nameHolder_92.m_Names.m_pElements = nullptr;
    nameHolder_92.m_nLenBase = 11;
    atexit(func: DataMapInit_CFlexCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFlexCycler::m_DataMap.baseMap = &CBaseFlex::m_DataMap;
  CFlexCycler::m_DataMap.dataNumFields = 11;
  CFlexCycler::m_DataMap.dataDesc = &dataDesc_89[1];
  return &CFlexCycler::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100D49A0
// Name: void ScriptDeduceFunctionSignature<class CBaseFlex __near *,class CBaseFlex,struct HSCRIPT__ __near *,int>(struct ScriptFuncDescriptor_t __near *,class CBaseFlex __near *,struct HSCRIPT__ __near * (CBaseFlex::*)(int))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseFlex *,CBaseFlex,HSCRIPT__ *,int>(ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 33;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)5;
}

//------------------------------------------------------------------------------
// Address: 0x100D5500
// Name: class CGenericFlexCycler __near * _CreateEntityTemplate<class CGenericFlexCycler>(class CGenericFlexCycler __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGenericFlexCycler *__cdecl _CreateEntityTemplate<CGenericFlexCycler>(
        CGenericFlexCycler *newEnt,
        const char *className)
{
  CBaseFlex *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseFlex *)CBaseEntity::operator new(stAllocateBlock: 0x7B0u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseFlex::CBaseFlex(this: v2);
    v3[490] = 0;
    v3[491] = 0;
    *v3 = &CGenericFlexCycler::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CGenericFlexCycler *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104002D0
// Name: _dynamic_initializer_for__g_CBaseFlex_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CBaseFlex_ScriptDesc__()
{
  InitCBaseFlexScriptDesc();
  g_CBaseFlex_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CBaseFlex_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CBaseFlex_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x10400300
// Name: _dynamic_initializer_for__funCBaseFlex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__funCBaseFlex__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBaseFlex> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &funCBaseFlex,
           a3: "funCBaseFlex");
}

//------------------------------------------------------------------------------
// Address: 0x10400320
// Name: _dynamic_initializer_for__g_FlexSceneFileManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FlexSceneFileManager__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_FlexSceneFileManager, name: "CFlexSceneFileManager");
  g_FlexSceneFileManager.__vftable = (CFlexSceneFileManager_vtbl *)&CFlexSceneFileManager::`vftable';
  g_FlexSceneFileManager.m_FileList.m_Memory.m_pMemory = nullptr;
  g_FlexSceneFileManager.m_FileList.m_Memory.m_nAllocationCount = 0;
  g_FlexSceneFileManager.m_FileList.m_Memory.m_nGrowSize = 0;
  g_FlexSceneFileManager.m_FileList.m_Size = 0;
  g_FlexSceneFileManager.m_FileList.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_FlexSceneFileManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10400360
// Name: _dynamic_initializer_for__ai_expression_optimization__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_expression_optimization__()
{
  ConVar::ConVar(
    this: &ai_expression_optimization,
    pName: "ai_expression_optimization",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Disable npc background expressions when you can't see them.");
  return atexit(func: dynamic_atexit_destructor_for__ai_expression_optimization__);
}

//------------------------------------------------------------------------------
// Address: 0x10400390
// Name: _dynamic_initializer_for__ai_expression_frametime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_expression_frametime__()
{
  ConVar::ConVar(
    this: &ai_expression_frametime,
    pName: "ai_expression_frametime",
    pDefaultValue: "0.05",
    flags: 0,
    pHelpString: "Maximum frametime to still play background expressions.");
  return atexit(func: dynamic_atexit_destructor_for__ai_expression_frametime__);
}

//------------------------------------------------------------------------------
// Address: 0x10418C00
// Name: _DataMapInit_CAI_BaseNPC__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_BaseNPC__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_5);
}

//------------------------------------------------------------------------------
// Address: 0x10418C10
// Name: _DataMapInit_AIScheduleState_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AIScheduleState_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_6);
}

//------------------------------------------------------------------------------
// Address: 0x10418C20
// Name: _DataMapInit_UnreachableEnt_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_UnreachableEnt_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_7);
}

//------------------------------------------------------------------------------
// Address: 0x10418C30
// Name: _DataMapInit_ScriptedNPCInteraction_Phases_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ScriptedNPCInteraction_Phases_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_8);
}

//------------------------------------------------------------------------------
// Address: 0x10418C40
// Name: _DataMapInit_ScriptedNPCInteraction_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ScriptedNPCInteraction_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_9);
}

//------------------------------------------------------------------------------
// Address: 0x10418C50
// Name: _DataMapInit_AIExtendedSaveHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AIExtendedSaveHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_10);
}

//------------------------------------------------------------------------------
// Address: 0x10418C60
// Name: _dynamic_atexit_destructor_for__g_AI_Manager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AI_Manager__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_AI_Manager);
}

//------------------------------------------------------------------------------
// Address: 0x10418C70
// Name: _dynamic_atexit_destructor_for__g_PostFrameNavigationHook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PostFrameNavigationHook__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PostFrameNavigationHook.m_Functors);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_PostFrameNavigationHook);
}

//------------------------------------------------------------------------------
// Address: 0x10418C90
// Name: _DataMapInit_CAI_BaseFlyingBot__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_BaseFlyingBot__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_11);
}

//------------------------------------------------------------------------------
// Address: 0x10418CA0
// Name: _DataMapInit_CAI_BasePhysicsFlyingBot__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_BasePhysicsFlyingBot__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_12);
}

//------------------------------------------------------------------------------
// Address: 0x10418CB0
// Name: _dynamic_atexit_destructor_for__ai_simulate_task_overtime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_simulate_task_overtime__()
{
  ConVar::~ConVar(this: &ai_simulate_task_overtime);
}

//------------------------------------------------------------------------------
// Address: 0x10418CC0
// Name: _DataMapInit_AIChannelScheduleState_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AIChannelScheduleState_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_13);
}

//------------------------------------------------------------------------------
// Address: 0x10418CD0
// Name: _DataMapInit_CAI_BehaviorBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_BehaviorBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_14);
}

//------------------------------------------------------------------------------
// Address: 0x10418CE0
// Name: _DataMapInit_AIBehaviorChannelSaveHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AIBehaviorChannelSaveHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_15);
}

//------------------------------------------------------------------------------
// Address: 0x10418CF0
// Name: _dynamic_atexit_destructor_for__ai_debug_assault__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_assault__()
{
  ConVar::~ConVar(this: &ai_debug_assault);
}

//------------------------------------------------------------------------------
// Address: 0x10418D00
// Name: _dynamic_atexit_destructor_for__g_AssaultPointString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AssaultPointString__()
{
  if ( g_AssaultPointString.m_bCopy )
    free(pMem: (void *)g_AssaultPointString.m_pszString);
}

//------------------------------------------------------------------------------
// Address: 0x10418D20
// Name: _dynamic_atexit_destructor_for__g_RallyPointString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RallyPointString__()
{
  if ( g_RallyPointString.m_bCopy )
    free(pMem: (void *)g_RallyPointString.m_pszString);
}

//------------------------------------------------------------------------------
// Address: 0x10418D40
// Name: _DataMapInit_CRallyPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRallyPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_16);
}

//------------------------------------------------------------------------------
// Address: 0x10418D50
// Name: _DataMapInit_CAssaultPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAssaultPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_17);
}

//------------------------------------------------------------------------------
// Address: 0x10418D60
// Name: _DataMapInit_CAI_AssaultBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_AssaultBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_18);
}

//------------------------------------------------------------------------------
// Address: 0x10418D70
// Name: _DataMapInit_CAI_AssaultGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_AssaultGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_19);
}

//------------------------------------------------------------------------------
// Address: 0x10418D80
// Name: _dynamic_atexit_destructor_for__ai_enable_fear_behavior__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_enable_fear_behavior__()
{
  ConVar::~ConVar(this: &ai_enable_fear_behavior);
}

//------------------------------------------------------------------------------
// Address: 0x10418D90
// Name: _dynamic_atexit_destructor_for__ai_fear_player_dist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_fear_player_dist__()
{
  ConVar::~ConVar(this: &ai_fear_player_dist);
}

//------------------------------------------------------------------------------
// Address: 0x10418DA0
// Name: _DataMapInit_CAI_FearBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_FearBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_20);
}

//------------------------------------------------------------------------------
// Address: 0x10418DB0
// Name: _DataMapInit_CAI_FightFromCoverBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_FightFromCoverBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_21);
}

//------------------------------------------------------------------------------
// Address: 0x10418DC0
// Name: _DataMapInit_CAI_FightFromCoverGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_FightFromCoverGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_22);
}

//------------------------------------------------------------------------------
// Address: 0x10418DD0
// Name: _dynamic_atexit_destructor_for__ai_debug_follow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_follow__()
{
  ConVar::~ConVar(this: &ai_debug_follow);
}

//------------------------------------------------------------------------------
// Address: 0x10418DE0
// Name: _dynamic_atexit_destructor_for__ai_follow_use_points__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_follow_use_points__()
{
  ConVar::~ConVar(this: &ai_follow_use_points);
}

//------------------------------------------------------------------------------
// Address: 0x10418DF0
// Name: _dynamic_atexit_destructor_for__ai_follow_use_points_when_moving__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_follow_use_points_when_moving__()
{
  ConVar::~ConVar(this: &ai_follow_use_points_when_moving);
}

//------------------------------------------------------------------------------
// Address: 0x10418E00
// Name: _DataMapInit_AI_FollowNavInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AI_FollowNavInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_23);
}

//------------------------------------------------------------------------------
// Address: 0x10418E10
// Name: _DataMapInit_AI_FollowParams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AI_FollowParams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_24);
}

//------------------------------------------------------------------------------
// Address: 0x10418E20
// Name: _DataMapInit_CAI_FollowBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_FollowBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_25);
}

//------------------------------------------------------------------------------
// Address: 0x10418E30
// Name: _DataMapInit_CAI_FollowGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_FollowGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_26);
}

//------------------------------------------------------------------------------
// Address: 0x10418E40
// Name: _dynamic_atexit_destructor_for__g_AIFollowManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AIFollowManager__()
{
  CAI_FollowManager::~CAI_FollowManager(this: &g_AIFollowManager);
}

//------------------------------------------------------------------------------
// Address: 0x10418E50
// Name: _DataMapInit_AI_LeadArgs_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AI_LeadArgs_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_27);
}

//------------------------------------------------------------------------------
// Address: 0x10418E60
// Name: _DataMapInit_CAI_LeadBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_LeadBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_28);
}

//------------------------------------------------------------------------------
// Address: 0x10418E70
// Name: _DataMapInit_CAI_LeadGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_LeadGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_29);
}

//------------------------------------------------------------------------------
// Address: 0x10418E80
// Name: _DataMapInit_CAI_LeadGoal_Weapon__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_LeadGoal_Weapon__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_30);
}

//------------------------------------------------------------------------------
// Address: 0x10418E90
// Name: _DataMapInit_CAI_RappelBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_RappelBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_31);
}

//------------------------------------------------------------------------------
// Address: 0x10418EA0
// Name: _DataMapInit_CRopeAnchor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRopeAnchor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_32);
}

//------------------------------------------------------------------------------
// Address: 0x10418EB0
// Name: _dynamic_atexit_destructor_for__DrawBattleLines__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DrawBattleLines__()
{
  ConVar::~ConVar(this: &DrawBattleLines);
}

//------------------------------------------------------------------------------
// Address: 0x10418EC0
// Name: _DataMapInit_CAI_BattleLine__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_BattleLine__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_33);
}

//------------------------------------------------------------------------------
// Address: 0x10418ED0
// Name: _DataMapInit_AI_StandoffParams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AI_StandoffParams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_34);
}

//------------------------------------------------------------------------------
// Address: 0x10418EE0
// Name: _DataMapInit_CAI_StandoffBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_StandoffBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_35);
}

//------------------------------------------------------------------------------
// Address: 0x10418EF0
// Name: _DataMapInit_CAI_StandoffGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_StandoffGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_36);
}

//------------------------------------------------------------------------------
// Address: 0x10418F00
// Name: _dynamic_atexit_destructor_for__ai_path_insert_pause_at_obstruction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_path_insert_pause_at_obstruction__()
{
  ConVar::~ConVar(this: &ai_path_insert_pause_at_obstruction);
}

//------------------------------------------------------------------------------
// Address: 0x10418F10
// Name: _dynamic_atexit_destructor_for__ai_path_adjust_speed_on_immediate_turns__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_path_adjust_speed_on_immediate_turns__()
{
  ConVar::~ConVar(this: &ai_path_adjust_speed_on_immediate_turns);
}

//------------------------------------------------------------------------------
// Address: 0x10418F20
// Name: _dynamic_atexit_destructor_for__ai_path_insert_pause_at_est_end__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_path_insert_pause_at_est_end__()
{
  ConVar::~ConVar(this: &ai_path_insert_pause_at_est_end);
}

//------------------------------------------------------------------------------
// Address: 0x10419DF0
// Name: _dynamic_atexit_destructor_for__ai_expression_optimization__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_expression_optimization__()
{
  ConVar::~ConVar(this: &ai_expression_optimization);
}

//------------------------------------------------------------------------------
// Address: 0x10419E00
// Name: _dynamic_atexit_destructor_for__ai_expression_frametime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_expression_frametime__()
{
  ConVar::~ConVar(this: &ai_expression_frametime);
}
