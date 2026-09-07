// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_baseactor.cpp
// Functions: 68
// ============================================================

#include "game\server\ai_baseactor.h"

//------------------------------------------------------------------------------
// Address: 0x10011BF0
// Name: float Vector2DNormalize(class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Vector2DNormalize(Vector2D *v)
{
  float v1; // xmm1_4
  double result; // st7
  float v3; // xmm0_4

  v1 = fsqrt((float)(v->x * v->x) + (float)(v->y * v->y));
  result = v1;
  v3 = 0.0;
  if ( v1 == 0.0 )
  {
    v->x = 0.0;
  }
  else
  {
    v3 = (float)(1.0 / v1) * v->y;
    v->x = v->x * (float)(1.0 / v1);
  }
  v->y = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011C80
// Name: public: class matrix3x4a_t __near & matrix3x4a_t::operator=(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
matrix3x4a_t *__thiscall matrix3x4a_t::operator=(matrix3x4a_t *this, matrix3x4a_t *src)
{
  *this = *src;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011CD0
// Name: int VectorCompare(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VectorCompare(const Vector *v1, const Vector *v2)
{
  return v2->x == v1->x && v2->y == v1->y && v2->z == v1->z;
}

//------------------------------------------------------------------------------
// Address: 0x10011D20
// Name: float Approach(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Approach(float target, float value, float speed)
{
  if ( (float)(target - value) > speed )
    return (float)(value + speed);
  if ( COERCE_FLOAT(LODWORD(speed) ^ _mask__NegFloat_) <= (float)(target - value) )
    return target;
  return (float)(value - speed);
}

//------------------------------------------------------------------------------
// Address: 0x10011D80
// Name: public: virtual struct datamap_t __near * CAI_BaseActor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_BaseActor::GetDataDescMap(CAI_BaseActor *this)
{
  return &CAI_BaseActor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10011D90
// Name: public: virtual void CAI_BaseActor::StudioFrameAdvance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::StudioFrameAdvance(CAI_BaseActor *this)
{
  this->m_fLatchedPositions &= 0xFFFFFFFC;
  CBaseAnimatingOverlay::StudioFrameAdvance(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011DA0
// Name: public: static bool CAI_BaseActor::IsServerSideFlexController(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CAI_BaseActor::IsServerSideFlexController(const char *szName)
{
  const char **v1; // esi

  v1 = g_ServerSideFlexControllers;
  while ( _V_stricmp(s1: szName, s2: *v1) != 0 )
  {
    if ( (int)++v1 >= (int)&AIN_DEF_TARGET_1 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011DE0
// Name: public: virtual bool CAI_BaseActor::ClearSceneEvent(class CSceneEventInfo __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseActor::ClearSceneEvent(
        CAI_BaseActor *this,
        CSceneEventInfo *info,
        bool fastKill,
        bool canceled)
{
  CChoreoEvent::GetType(this: info->m_pEvent);
  return CBaseFlex::ClearSceneEvent(this, info, fastKill, canceled);
}

//------------------------------------------------------------------------------
// Address: 0x10011E30
// Name: public: virtual void CAI_BaseActor::SetViewtarget(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::SetViewtarget(CAI_BaseActor *this, const Vector *viewtarget)
{
  this->m_fLatchedPositions &= ~1u;
  CBaseFlex::SetViewtarget(this, viewtarget);
}

//------------------------------------------------------------------------------
// Address: 0x10011E40
// Name: public: virtual void CAI_BaseActor::InvalidateBoneCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::InvalidateBoneCache(CAI_BaseActor *this)
{
  this->m_fLatchedPositions &= 0xFFFFFFFC;
  CBaseAnimating::InvalidateBoneCache(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011E50
// Name: public: virtual bool CAI_BaseActor::ValidEyeTarget(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseActor::ValidEyeTarget(CAI_BaseActor *this, const Vector *lookTargetPos)
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
  return VectorNormalize(vec: &lookTargetDir) >= 1.0
      && (float)((float)((float)(lookTargetDir.x * vHeadDir.x) + (float)(vHeadDir.y * lookTargetDir.y))
               + (float)(vHeadDir.z * lookTargetDir.z)) > 0.259;
}

//------------------------------------------------------------------------------
// Address: 0x10011F00
// Name: public: bool CAI_BaseActor::ValidHeadTarget(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseActor::ValidHeadTarget(CAI_BaseActor *this, const Vector *vLookTargetDir, float flDistance)
{
  bool result; // al
  Vector vFacing; // [esp+0h] [ebp-Ch] BYREF

  result = false;
  if ( flDistance >= 1.0 )
  {
    this->BodyDirection3D(this, result: &vFacing);
    if ( (float)((float)((float)(vLookTargetDir->y * vFacing.y) + (float)(vLookTargetDir->x * vFacing.x))
               + (float)(vLookTargetDir->z * vFacing.z)) > 0.0
      && COERCE_FLOAT(LODWORD(vLookTargetDir->z) & _mask__AbsFloat_) < 0.7 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011F80
// Name: public: virtual float CAI_BaseActor::PickLookTarget(bool,float,float)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CAI_BaseActor::PickLookTarget(CAI_BaseActor *this, int bExcludePlayers, float minTime, float maxTime)
{
  return ((float (__stdcall *)(CAI_InterestTarget *, int, _DWORD, _DWORD))this->PickLookTarget)(
           a1: &this->m_randomLookQueue,
           a2: bExcludePlayers,
           a3: LODWORD(minTime),
           a4: LODWORD(maxTime));
}

//------------------------------------------------------------------------------
// Address: 0x10011FC0
// Name: public: virtual void CAI_BaseActor::MakeRandomLookTarget(struct AILookTargetArgs_t __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::MakeRandomLookTarget(
        CAI_BaseActor *this,
        AILookTargetArgs_t *pArgs,
        float minTime,
        float maxTime)
{
  double v5; // st7
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // edx
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector v11; // [esp+34h] [ebp-58h] BYREF
  Vector forward; // [esp+40h] [ebp-4Ch] BYREF
  Vector right; // [esp+4Ch] [ebp-40h] BYREF
  Vector up; // [esp+58h] [ebp-34h] BYREF
  float v15; // [esp+64h] [ebp-28h]
  float v16; // [esp+68h] [ebp-24h]
  float v17; // [esp+6Ch] [ebp-20h]
  float v18; // [esp+70h] [ebp-1Ch]
  float v19; // [esp+74h] [ebp-18h]
  float v20; // [esp+78h] [ebp-14h]
  float v21; // [esp+7Ch] [ebp-10h]
  float v22; // [esp+80h] [ebp-Ch]
  float v23; // [esp+84h] [ebp-8h]
  float v24; // [esp+88h] [ebp-4h]

  this->GetVectors(this, a2: &forward, a3: &right, a4: &up);
  v5 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: -1048576000,
         a3: 1098907648);
  RandomFloat = random->RandomFloat;
  v15 = up.x * v5;
  v16 = up.y * v5;
  v17 = v5 * up.z;
  v24 = ((double (__thiscall *)(IUniformRandomStream *, int, int))RandomFloat)(
          a1: random,
          a2: -1040187392,
          a3: 1107296256);
  EyePosition = this->EyePosition;
  v18 = right.x * v24;
  v19 = right.y * v24;
  v20 = right.z * v24;
  v21 = forward.x * 128.0;
  v22 = forward.y * 128.0;
  v23 = forward.z * 128.0;
  v8 = (float *)EyePosition(this, result: &v11);
  v9 = (float)((float)(v8[1] + v22) + v19) + v16;
  v10 = (float)((float)(v8[2] + v23) + v20) + v17;
  pArgs->vTarget.x = (float)((float)(*v8 + v21) + v18) + v15;
  pArgs->vTarget.y = v9;
  pArgs->vTarget.z = v10;
  pArgs->flDuration = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                        a1: random,
                        a2: LODWORD(minTime),
                        a3: LODWORD(maxTime));
  pArgs->flInfluence = 0.0099999998;
  pArgs->flRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: 1061997773,
                    a3: 1077097267);
}

//------------------------------------------------------------------------------
// Address: 0x10012180
// Name: public: virtual void CAI_BaseActor::StartTaskRangeAttack1(struct Task_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::StartTaskRangeAttack1(CAI_BaseActor *this, const Task_t *pTask)
{
  CAI_BaseActor_vtbl *v3; // edi
  int v4; // eax

  CAI_BaseHumanoid::StartTaskRangeAttack1(this, pTask);
  if ( this->GetEnemy_2(this) != nullptr )
  {
    v3 = this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v4 = ((int (__thiscall *)(CAI_BaseActor *, int, int, int))this->GetEnemy_2)(
           a1: this,
           a2: 1065353216,
           a3: 1056964608,
           a4: 1045220557);
    ((void (__thiscall *)(CAI_BaseActor *, int))v3->AddLookTarget)(a1: this, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100121F0
// Name: protected: virtual bool CAI_BaseActor::TestRemarkingUpon(class CInfoRemarkable __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseActor::TestRemarkingUpon(CAI_BaseActor *this, CInfoRemarkable *pRemarkable)
{
  return this->IsInFieldOfView(this, a2: pRemarkable)
      && this->IsLineOfSightClear(this, a2: pRemarkable, a3: IGNORE_ACTORS);
}

//------------------------------------------------------------------------------
// Address: 0x10012230
// Name: public: virtual void CAI_BaseActor::AddLookTarget(class CBaseEntity __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::AddLookTarget(
        CAI_BaseActor *this,
        CBaseEntity *pTarget,
        float flImportance,
        float flDuration,
        float flRamp)
{
  CAI_InterestTarget::Add(this: &this->m_lookQueue, pTarget, flImportance, flDuration, flRamp);
}

//------------------------------------------------------------------------------
// Address: 0x10012270
// Name: public: virtual void CAI_BaseActor::AddLookTarget(class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::AddLookTarget(
        CAI_BaseActor *this,
        const Vector *vecPosition,
        float flImportance,
        float flDuration,
        float flRamp)
{
  CAI_InterestTarget::Add(this: &this->m_lookQueue, vecPosition, flImportance, flDuration, flRamp);
}

//------------------------------------------------------------------------------
// Address: 0x100122B0
// Name: public: virtual void CAI_BaseActor::OnStateChange(enum NPC_STATE,enum NPC_STATE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::OnStateChange(CAI_BaseActor *this, NPC_STATE OldState, NPC_STATE NewState)
{
  this->PlayExpressionForState(this, a2: NewState);
}

//------------------------------------------------------------------------------
// Address: 0x100122D0
// Name: public: virtual bool CAI_BaseActor::UseSemaphore(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseActor::UseSemaphore(CAI_BaseActor *this)
{
  return LOBYTE(this->m_iMaxHealth.m_Value) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100122E0
// Name: protected: virtual class CAI_Expresser __near * CAI_BaseActor::CreateExpresser(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Expresser *__thiscall CAI_BaseActor::CreateExpresser(CAI_BaseActor *this)
{
  CAI_Expresser *v2; // eax
  CAI_Expresser *result; // eax

  v2 = (CAI_Expresser *)operator new(nSize: 0x44u);
  if ( v2 != nullptr )
  {
    result = CAI_Expresser::CAI_Expresser(this: v2, pOuter: this);
    this->m_pExpresser = result;
  }
  else
  {
    this->m_pExpresser = nullptr;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012310
// Name: public: virtual class CAI_Expresser __near * CAI_BaseActor::GetExpresser(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Expresser *__thiscall CAI_BaseActor::GetExpresser(CAI_BaseActor *this)
{
  return this->m_pExpresser;
}

//------------------------------------------------------------------------------
// Address: 0x10012320
// Name: protected: virtual bool CAI_BaseActor::CreateComponents(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseActor::CreateComponents(CAI_BaseActor *this)
{
  CAI_Expresser *v3; // eax

  if ( !CAI_BaseNPC::CreateComponents(this) )
    return 0;
  v3 = this->CreateExpresser(this);
  this->m_pExpresser = v3;
  if ( v3 == nullptr )
    return 0;
  v3->m_pSink = &this->CAI_ExpresserSink;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012360
// Name: float UTIL_Approach(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl UTIL_Approach(float target, float value, float speed)
{
  if ( (float)(target - value) > speed )
    return (float)(value + speed);
  if ( COERCE_FLOAT(LODWORD(speed) ^ _mask__NegFloat_) <= (float)(target - value) )
    return target;
  return (float)(value - speed);
}

//------------------------------------------------------------------------------
// Address: 0x100123C0
// Name: public: char const __near * CBaseEntity::GetClassname(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseEntity::GetClassname(CBaseEntity *this)
{
  const char *result; // eax

  result = this->m_iClassname.pszValue;
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100123D0
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x100124B0
// Name: public: void CAI_BaseActor::Init(enum FlexWeight_t __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::Init(CAI_BaseActor *this, FlexWeight_t *index, const char *szName)
{
  const char **v4; // esi

  v4 = g_ServerSideFlexControllers;
  while ( _V_stricmp(s1: szName, s2: *v4) != 0 )
  {
    if ( (int)++v4 >= (int)&AIN_DEF_TARGET_1 )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_1042DAB8, a2: szName);
      break;
    }
  }
  *index = CBaseFlex::FindFlexController(this, szName);
}

//------------------------------------------------------------------------------
// Address: 0x10012500
// Name: private: bool CAI_BaseActor::RandomFaceFlex(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseActor::RandomFaceFlex(
        CAI_BaseActor *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  const char *Parameters2; // eax
  const flexsettinghdr_t *SceneFile; // ebx
  int v7; // eax
  int v8; // esi
  char *v9; // eax
  bool v10; // zf
  char *v11; // esi
  int v12; // eax
  LocalFlexController_t v14; // eax
  double v15; // st7
  LocalFlexController_t v16; // esi
  float *m_flextarget; // ebx
  double FlexWeight; // st7
  float v19; // xmm0_4
  int v20; // xmm1_4
  float scenetime; // [esp+14h] [ebp-14h]
  int intensity; // [esp+24h] [ebp-4h]
  float intensitya; // [esp+24h] [ebp-4h]
  float scenea; // [esp+34h] [ebp+Ch]
  float weighta; // [esp+38h] [ebp+10h]
  float weight; // [esp+38h] [ebp+10h]
  float weightb; // [esp+38h] [ebp+10h]

  if ( gpGlobals->curtime > info->m_flNext )
  {
    Parameters2 = CChoreoEvent::GetParameters2(this: event);
    SceneFile = (const flexsettinghdr_t *)CBaseFlex::FindSceneFile(this, filename: Parameters2);
    if ( SceneFile == nullptr )
    {
      SceneFile = (const flexsettinghdr_t *)CBaseFlex::FindSceneFile(this, filename: "random");
      if ( SceneFile == nullptr )
        return 0;
    }
    info->m_flNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                       a1: random,
                       a2: 1050253722,
                       a3: 1056964608)
                   * (30.0
                    / (double)SceneFile->numflexsettings)
                   + gpGlobals->curtime;
    v7 = SceneFile->flexsettingindex + 24 * random->RandomInt(this: random, a2: 0, a3: SceneFile->numflexsettings - 1);
    v8 = *(_DWORD *)&SceneFile->name[v7 + 12];
    v9 = (char *)SceneFile + v7;
    v10 = &v9[v8] == nullptr;
    v11 = &v9[v8];
    v12 = *((_DWORD *)v9 + 2);
    if ( v10 )
      return 0;
    if ( v12 > 0 )
    {
      for ( intensity = v12; intensity != 0; --intensity )
      {
        v14 = CBaseFlex::FlexControllerLocalToGlobal(this, pSettinghdr: SceneFile, key: *(_DWORD *)v11);
        v15 = *((float *)v11 + 1);
        v11 += 12;
        this->m_flextarget[v14] = v15;
      }
    }
  }
  scenetime = CBreakableProp::GetDmgModClub(this: scene);
  weighta = CChoreoEvent::GetIntensity(this: event, scenetime);
  v16 = DUMMY_NULL_FLEX_CONTROLLER;
  intensitya = CSceneEventInfo::UpdateWeight(this: info, pActor: this) * weighta;
  if ( CBaseAnimating::GetNumFlexControllers(this) > DUMMY_NULL_FLEX_CONTROLLER )
  {
    m_flextarget = this->m_flextarget;
    do
    {
      FlexWeight = CBaseFlex::GetFlexWeight(this, index: v16);
      weight = FlexWeight;
      v19 = weight;
      if ( weight != *m_flextarget )
      {
        scenea = *m_flextarget - FlexWeight;
        weightb = scenea
                / ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: 0x40000000,
                    a3: 1082130432)
                * intensitya
                + weight;
        v19 = weightb;
      }
      v20 = 0;
      if ( v19 < 0.0 || (v20 = 1065353216, v19 > 1.0) )
        v19 = *(float *)&v20;
      CBaseFlex::SetFlexWeight(this, index: v16++, value: v19);
      ++m_flextarget;
    }
    while ( v16 < CBaseAnimating::GetNumFlexControllers(this) );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100126D0
// Name: public: virtual float CAI_BaseActor::HeadTargetValidity(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
double __userpurge CAI_BaseActor::HeadTargetValidity@<st0>(
        CAI_BaseActor *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        const Vector *lookTargetPos)
{
  int v5; // eax
  Vector *v6; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  __int128 v9; // xmm0
  __int64 v11; // xmm1_8
  double v12; // xmm0_8
  float v13; // xmm0_4
  __int128 v15; // [esp-10h] [ebp-3Ch] BYREF
  Vector tmp1; // [esp+0h] [ebp-2Ch] BYREF
  float v17; // [esp+Ch] [ebp-20h]
  Vector vFacing; // [esp+10h] [ebp-1Ch] BYREF
  Vector lookTargetDir; // [esp+1Ch] [ebp-10h]
  float retaddr; // [esp+2Ch] [ebp+0h]

  lookTargetDir.y = a2;
  lookTargetDir.z = retaddr;
  ((void (__thiscall *)(CAI_BaseActor *, float *, int))this->BodyDirection3D)(a1: this, a2: &tmp1.y, a3);
  v5 = CBaseAnimating::LookupAttachment(this, szName: "forward");
  if ( v5 != 0 )
    CBaseAnimating::GetAttachment(
      this,
      iAttachment: v5,
      absOrigin: (Vector *)((char *)&v15 + 4),
      forward: (Vector *)&tmp1.y,
      right: nullptr,
      up: nullptr);
  v6 = this->EyePosition(this, result: (char *)&v15 + 4);
  y = lookTargetPos->y;
  z = lookTargetPos->z;
  vFacing.x = lookTargetPos->x - v6->x;
  vFacing.y = y - v6->y;
  v9 = 0;
  vFacing.z = z - v6->z;
  *(float *)&v9 = fsqrt((float)(vFacing.y * vFacing.y) + (float)(vFacing.x * vFacing.x));
  v15 = v9;
  VectorNormalize(vec: &vFacing);
  if ( *(float *)&v9 <= 1.0 )
    return 0.0;
  *(double *)&v11 = 0.0;
  v12 = (float)((float)((float)((float)(tmp1.z * vFacing.y) + (float)(tmp1.y * vFacing.x)) + (float)(v17 * vFacing.z))
              + 1.0)
      * 3.4142;
  if ( v12 < 0.0 || (*(double *)&v11 = 1.0, v12 > 1.0) )
    v12 = *(double *)&v11;
  v13 = v12;
  lookTargetDir.x = v13;
  if ( *(float *)&v15 < 10.0 )
    lookTargetDir.x = (float)((float)(*(float *)&v15 - 1.0) * v13) * 0.11111111;
  return lookTargetDir.x;
}

//------------------------------------------------------------------------------
// Address: 0x10012830
// Name: public: virtual class Vector CAI_BaseActor::EyeDirection2D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__userpurge CAI_BaseActor::EyeDirection2D@<eax>(CAI_BaseActor *this@<ecx>, int a2@<esi>, Vector *result)
{
  float v3; // xmm1_4
  Vector *v4; // eax
  float v5; // [esp-10h] [ebp-1Ch]

  ((void (__thiscall *)(CAI_BaseActor *, Vector *, int))this->EyeDirection3D)(a1: this, a2: result, a3: a2);
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
// Address: 0x100128E0
// Name: public: virtual class Vector CAI_BaseActor::HeadDirection2D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__userpurge CAI_BaseActor::HeadDirection2D@<eax>(CAI_BaseActor *this@<ecx>, int a2@<esi>, Vector *result)
{
  float v3; // xmm1_4
  Vector *v4; // eax
  float v5; // [esp-10h] [ebp-1Ch]

  ((void (__thiscall *)(CAI_BaseActor *, Vector *, int))this->HeadDirection3D)(a1: this, a2: result, a3: a2);
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
// Address: 0x10012990
// Name: public: virtual bool CAI_BaseActor::HasActiveLookTargets(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseActor::HasActiveLookTargets(CAI_BaseActor *this)
{
  return this->m_lookQueue.m_Size != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100129A0
// Name: public: virtual bool CAI_BaseActor::PickTacticalLookTarget(struct AILookTargetArgs_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CAI_BaseActor::PickTacticalLookTarget@<al>(
        CAI_BaseActor *this@<ecx>,
        int a2@<ebx>,
        AILookTargetArgs_t *pArgs)
{
  CBaseEntity *v4; // edi
  float *v5; // ebx
  float *v6; // eax
  Vector v8; // [esp+30h] [ebp-24h] BYREF
  float v9[3]; // [esp+3Ch] [ebp-18h] BYREF
  Vector vLookTargetDir; // [esp+48h] [ebp-Ch] BYREF

  v4 = this->GetEnemy_2(this);
  if ( v4 != nullptr )
  {
    v5 = (float *)((int (__thiscall *)(CAI_BaseActor *, float *, int))this->EyePosition)(a1: this, a2: v9, a3: a2);
    v6 = (float *)v4->EyePosition(this: v4, result: &v8);
    vLookTargetDir.x = *v6 - *v5;
    vLookTargetDir.y = v6[1] - v5[1];
    vLookTargetDir.z = v6[2] - v5[2];
    if ( VectorNormalize(vec: &vLookTargetDir) >= 1.0 )
    {
      this->BodyDirection3D(this, result: (Vector *)v9);
      if ( (float)((float)((float)(v9[0] * vLookTargetDir.x) + (float)(v9[1] * vLookTargetDir.y))
                 + (float)(v9[2] * vLookTargetDir.z)) > 0.0
        && COERCE_FLOAT(LODWORD(vLookTargetDir.z) & _mask__AbsFloat_) < 0.7
        && (this->FVisible_2(this, a2: v4, a3: 16449, a4: nullptr) || random->RandomInt(this: random, a2: 0, a3: 3) == 0) )
      {
        pArgs->hTarget.m_Index = v4->GetRefEHandle(this: v4)->m_Index;
        pArgs->flInfluence = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                               a1: random,
                               a2: 1060320051,
                               a3: 1065353216);
        pArgs->flRamp = 0.0;
        return 1;
      }
    }
    pArgs->flDuration = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                          a1: random,
                          a2: 1056964608,
                          a3: 1061997773);
    pArgs->flRamp = 0.2;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012BE0
// Name: public: class CBaseEntity __near * CBaseEntity::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::GetParent(CBaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_pParent.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10012C10
// Name: public: class CBaseEntity __near * CBaseEntity::GetOwnerEntity(void)const
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::GetOwnerEntity(CBaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10012CE0
// Name: public: int CAI_InterestTarget::Find(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_InterestTarget::Find(CAI_InterestTarget *this, CBaseEntity *pTarget)
{
  int m_Size; // edi
  int result; // eax
  CHandle<CBaseEntity> *i; // esi
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // edx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = &this->m_Memory.m_pMemory->m_hTarget; ; i += 9 )
  {
    m_Index = i->m_Index;
    if ( i->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( pTarget == m_pEntity )
      break;
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012D40
// Name: public: void CAI_BaseActor::Set(enum PoseParameter_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::Set(CAI_BaseActor *this, PoseParameter_t index, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: m_pStudioHdr, iParameter: index, flValue);
}

//------------------------------------------------------------------------------
// Address: 0x10012D90
// Name: public: virtual void CAI_BaseActor::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::SetModel(CAI_BaseActor *this, const char *szModelName)
{
  CStudioHdr *m_pStudioHdr; // eax
  PoseParameter_t v4; // eax
  bool v5; // zf
  CStudioHdr *v6; // eax
  PoseParameter_t v7; // eax
  CStudioHdr *v8; // eax
  PoseParameter_t v9; // eax
  CStudioHdr *v10; // eax
  PoseParameter_t v11; // eax
  CStudioHdr *v12; // eax
  PoseParameter_t v13; // eax
  CStudioHdr *v14; // eax
  CStudioHdr *v15; // eax
  PoseParameter_t v16; // eax
  CStudioHdr *v17; // eax

  CBaseFlex::SetModel(this, szModelName);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v4 = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: m_pStudioHdr, szName: "body_yaw");
  v5 = this->m_pStudioHdr == nullptr;
  this->m_ParameterBodyYaw = v4;
  if ( v5 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v6 = this->m_pStudioHdr;
  if ( v6 == nullptr || v6->m_pStudioHdr == nullptr )
    v6 = nullptr;
  v7 = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: v6, szName: "spine_yaw");
  v5 = this->m_pStudioHdr == nullptr;
  this->m_ParameterSpineYaw = v7;
  if ( v5 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v8 = this->m_pStudioHdr;
  if ( v8 == nullptr || v8->m_pStudioHdr == nullptr )
    v8 = nullptr;
  v9 = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: v8, szName: "neck_trans");
  v5 = this->m_pStudioHdr == nullptr;
  this->m_ParameterNeckTrans = v9;
  if ( v5 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v10 = this->m_pStudioHdr;
  if ( v10 == nullptr || v10->m_pStudioHdr == nullptr )
    v10 = nullptr;
  v11 = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: v10, szName: "head_yaw");
  v5 = this->m_pStudioHdr == nullptr;
  this->m_ParameterHeadYaw = v11;
  if ( v5 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v12 = this->m_pStudioHdr;
  if ( v12 == nullptr || v12->m_pStudioHdr == nullptr )
    v12 = nullptr;
  v13 = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: v12, szName: "head_pitch");
  v5 = this->m_pStudioHdr == nullptr;
  this->m_ParameterHeadPitch = v13;
  if ( v5 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v14 = this->m_pStudioHdr;
  if ( v14 == nullptr || v14->m_pStudioHdr == nullptr )
    v14 = nullptr;
  this->m_ParameterHeadRoll = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: v14, szName: "head_roll");
  CAI_BaseActor::Init(this, index: &this->m_FlexweightBodyRightLeft, szName: "body_rightleft");
  CAI_BaseActor::Init(this, index: &this->m_FlexweightChestRightLeft, szName: "chest_rightleft");
  CAI_BaseActor::Init(this, index: &this->m_FlexweightHeadForwardBack, szName: "head_forwardback");
  CAI_BaseActor::Init(this, index: &this->m_FlexweightHeadRightLeft, szName: "head_rightleft");
  CAI_BaseActor::Init(this, index: &this->m_FlexweightHeadUpDown, szName: "head_updown");
  CAI_BaseActor::Init(this, index: &this->m_FlexweightHeadTilt, szName: "head_tilt");
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v15 = this->m_pStudioHdr;
  if ( v15 == nullptr || v15->m_pStudioHdr == nullptr )
    v15 = nullptr;
  v16 = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: v15, szName: "gesture_height");
  v5 = this->m_pStudioHdr == nullptr;
  this->m_ParameterGestureHeight = v16;
  if ( v5 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v17 = this->m_pStudioHdr;
  if ( v17 == nullptr || v17->m_pStudioHdr == nullptr )
    v17 = nullptr;
  this->m_ParameterGestureWidth = CBaseAnimating::LookupPoseParameter(this, pStudioHdr: v17, szName: "gesture_width");
  CAI_BaseActor::Init(this, index: &this->m_FlexweightGestureUpDown, szName: "gesture_updown");
  CAI_BaseActor::Init(this, index: &this->m_FlexweightGestureRightLeft, szName: "gesture_rightleft");
}

//------------------------------------------------------------------------------
// Address: 0x10013040
// Name: public: virtual bool CAI_BaseActor::CheckSceneEventCompletion(class CSceneEventInfo __near *,float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseActor::CheckSceneEventCompletion(
        CAI_BaseActor *this,
        CSceneEventInfo *info,
        float currenttime,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  double v7; // st7
  int LayerSequence; // eax
  float currenttimea; // [esp+24h] [ebp+Ch]
  float preload; // [esp+2Ch] [ebp+14h]

  if ( CChoreoEvent::GetType(this: event) != GENERIC || (unsigned int)(info->m_nType - 2) > 1 )
    return CBaseFlex::CheckSceneEventCompletion(this, info, currenttime, scene, event);
  if ( info->m_iLayer == -1 )
    return true;
  v7 = CChoreoEvent::GetEndTime(this: event) - currenttime;
  preload = v7;
  if ( v7 < 0.0 )
    return true;
  LayerSequence = CBaseAnimatingOverlay::GetLayerSequence(this, iLayer: info->m_iLayer);
  currenttimea = CBaseAnimating::SequenceDuration(this, iSequence: LayerSequence);
  return preload >= (1.0 - CBaseAnimatingOverlay::GetLayerCycle(this, iLayer: info->m_iLayer)) * currenttimea;
}

//------------------------------------------------------------------------------
// Address: 0x100130F0
// Name: private: void CAI_BaseActor::ClearHeadAdjustment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::ClearHeadAdjustment(CAI_BaseActor *this)
{
  PoseParameter_t m_ParameterHeadYaw; // edi
  CStudioHdr *m_pStudioHdr; // eax
  PoseParameter_t m_ParameterHeadPitch; // edi
  CStudioHdr *v5; // eax
  PoseParameter_t m_ParameterHeadRoll; // edi
  CStudioHdr *v7; // eax

  this->m_lookQueue.m_Size = 0;
  this->m_syntheticLookQueue.m_Size = 0;
  this->m_randomLookQueue.m_Size = 0;
  m_ParameterHeadYaw = this->m_ParameterHeadYaw;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: m_pStudioHdr, iParameter: m_ParameterHeadYaw, flValue: 0.0);
  m_ParameterHeadPitch = this->m_ParameterHeadPitch;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v5 = this->m_pStudioHdr;
  if ( v5 == nullptr || v5->m_pStudioHdr == nullptr )
    v5 = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: v5, iParameter: m_ParameterHeadPitch, flValue: 0.0);
  m_ParameterHeadRoll = this->m_ParameterHeadRoll;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v7 = this->m_pStudioHdr;
  if ( v7 == nullptr || v7->m_pStudioHdr == nullptr )
    v7 = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: v7, iParameter: m_ParameterHeadRoll, flValue: 0.0);
  this->m_goalHeadDirection.x = 0.0;
  this->m_goalHeadDirection.y = 0.0;
  this->m_goalHeadDirection.z = 0.0;
  this->m_goalHeadInfluence = 0.0;
  this->m_goalSpineYaw = 0.0;
  this->m_goalBodyYaw = 0.0;
  this->m_goalHeadCorrection.x = 0.0;
  this->m_goalHeadCorrection.y = 0.0;
  this->m_goalHeadCorrection.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10013230
// Name: public: virtual void CAI_BaseActor::Teleport(class Vector const __near *,class QAngle const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::Teleport(
        CAI_BaseActor *this,
        const Vector *newPosition,
        const QAngle *newAngles,
        const Vector *newVelocity,
        BOOL bUseSlowHighAccuracyContacts)
{
  CAI_BaseActor::ClearHeadAdjustment(this);
  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->Teleport(
      this: this->m_pPrimaryBehavior,
      a2: newPosition,
      a3: newAngles,
      a4: newVelocity,
      a5: bUseSlowHighAccuracyContacts);
  else
    CAI_BaseNPC::Teleport(this, newPosition, newAngles, newVelocity, bUseSlowHighAccuracyContacts);
}

//------------------------------------------------------------------------------
// Address: 0x10013270
// Name: private: void CAI_BaseActor::UpdateLatchedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::UpdateLatchedValues(CAI_BaseActor *this)
{
  int m_fLatchedPositions; // eax
  int v3; // eax
  CAI_BaseActor_vtbl *v4; // edx
  float v5; // xmm1_4
  float v6; // xmm2_4
  Vector result; // [esp+4h] [ebp-Ch] BYREF

  m_fLatchedPositions = this->m_fLatchedPositions;
  if ( (m_fLatchedPositions & 2) == 0 )
  {
    this->m_fLatchedPositions = m_fLatchedPositions | 2;
    if ( CBaseAnimating::CanSkipAnimation(this)
      || !CBaseAnimating::GetAttachment(
            this,
            szName: "eyes",
            absOrigin: &this->m_latchedEyeOrigin,
            forward: &this->m_latchedHeadDirection,
            right: nullptr,
            up: nullptr) )
    {
      this->m_latchedEyeOrigin = *CAI_BaseNPC::EyePosition(this, &result);
      AngleVectors(angles: &this->m_angRotation.m_Value, forward: &this->m_latchedHeadDirection);
    }
    this->m_fLatchedPositions &= ~1u;
  }
  v3 = this->m_fLatchedPositions;
  if ( (v3 & 1) == 0 )
  {
    v4 = this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    this->m_fLatchedPositions = v3 | 1;
    if ( (v4->CapabilitiesGet(this) & 0x800000) != 0 )
    {
      v5 = this->m_viewtarget.m_Value.y - this->m_latchedEyeOrigin.y;
      v6 = this->m_viewtarget.m_Value.z - this->m_latchedEyeOrigin.z;
      this->m_latchedEyeDirection.x = this->m_viewtarget.m_Value.x - this->m_latchedEyeOrigin.x;
      this->m_latchedEyeDirection.y = v5;
      this->m_latchedEyeDirection.z = v6;
      VectorNormalize(vec: &this->m_latchedEyeDirection);
    }
    else
    {
      this->m_latchedEyeDirection.x = this->m_latchedHeadDirection.x;
      this->m_latchedEyeDirection.y = this->m_latchedHeadDirection.y;
      this->m_latchedEyeDirection.z = this->m_latchedHeadDirection.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100133A0
// Name: public: virtual class Vector CAI_BaseActor::EyePosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseActor::EyePosition(CAI_BaseActor *this, Vector *result)
{
  float z; // ecx

  CAI_BaseActor::UpdateLatchedValues(this);
  z = this->m_latchedEyeOrigin.z;
  *(_QWORD *)&result->x = *(_QWORD *)&this->m_latchedEyeOrigin.x;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100133D0
// Name: public: void CAI_BaseActor::AccumulateIdealYaw(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::AccumulateIdealYaw(CAI_BaseActor *this, float flYaw, float flIntensity)
{
  double v4; // st7

  v4 = AngleDiff(destAngle: flYaw, srcAngle: this->m_angRotation.m_Value.y) * flIntensity + this->m_flAccumYawDelta;
  this->m_flAccumYawScale = flIntensity + this->m_flAccumYawScale;
  this->m_flAccumYawDelta = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10013430
// Name: public: bool CAI_BaseActor::SetAccumulatedYawAndUpdate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseActor::SetAccumulatedYawAndUpdate(CAI_BaseActor *this)
{
  float m_flAccumYawScale; // xmm2_4
  float facing; // [esp+Ch] [ebp-4h]

  m_flAccumYawScale = this->m_flAccumYawScale;
  if ( m_flAccumYawScale <= 0.0 )
    return 0;
  facing = (float)(this->m_flAccumYawDelta / m_flAccumYawScale) + this->m_angRotation.m_Value.y;
  this->m_flAccumYawDelta = 0.0;
  this->m_flAccumYawScale = 0.0;
  if ( !CAI_BaseNPC::IsCurSchedule(this, schedId: 63, fIdeal: true) || this->IsMoving(this) )
    return 0;
  CAI_Motor::SetIdealYawAndUpdate(this: this->m_pMotor, idealYaw: facing, yawSpeed: -1.0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100134D0
// Name: public: void CAI_BaseActor::UpdateBodyControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::UpdateBodyControl(CAI_BaseActor *this)
{
  double FlexWeight; // st7
  PoseParameter_t m_ParameterBodyYaw; // edi
  CStudioHdr *m_pStudioHdr; // eax
  double v5; // st7
  PoseParameter_t m_ParameterSpineYaw; // edi
  CStudioHdr *v7; // eax
  PoseParameter_t m_ParameterNeckTrans; // edi
  CStudioHdr *v9; // eax
  float flValue; // [esp+Ch] [ebp-4h]
  float v11; // [esp+Ch] [ebp-4h]
  float v12; // [esp+Ch] [ebp-4h]

  FlexWeight = CBaseFlex::GetFlexWeight(this, index: (LocalFlexController_t)this->m_FlexweightBodyRightLeft);
  m_ParameterBodyYaw = this->m_ParameterBodyYaw;
  flValue = FlexWeight + this->m_goalBodyYaw;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: m_pStudioHdr, iParameter: m_ParameterBodyYaw, flValue);
  v5 = CBaseFlex::GetFlexWeight(this, index: (LocalFlexController_t)this->m_FlexweightChestRightLeft);
  m_ParameterSpineYaw = this->m_ParameterSpineYaw;
  v11 = v5 + this->m_goalSpineYaw;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v7 = this->m_pStudioHdr;
  if ( v7 == nullptr || v7->m_pStudioHdr == nullptr )
    v7 = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: v7, iParameter: m_ParameterSpineYaw, flValue: v11);
  v12 = CBaseFlex::GetFlexWeight(this, index: (LocalFlexController_t)this->m_FlexweightHeadForwardBack);
  m_ParameterNeckTrans = this->m_ParameterNeckTrans;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v9 = this->m_pStudioHdr;
  if ( v9 == nullptr || v9->m_pStudioHdr == nullptr )
    v9 = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: v9, iParameter: m_ParameterNeckTrans, flValue: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10013600
// Name: public: void CAI_BaseActor::UpdateHeadControl(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_BaseActor::UpdateHeadControl(
        CAI_BaseActor *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vHeadTarget,
        float flHeadInfluence)
{
  int v7; // edi
  int v8; // eax
  double PoseParameter; // st7
  double v10; // st7
  double v11; // st7
  Vector *v12; // eax
  float x; // xmm0_4
  __int64 v14; // xmm1_8
  double v15; // xmm0_8
  double v16; // st7
  float v17; // xmm2_4
  float y; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float z; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // ecx
  _BYTE v33[12]; // [esp+2Ch] [ebp-1CCh] BYREF
  matrix3x4_t headXform; // [esp+38h] [ebp-1C0h] BYREF
  matrix3x4_t chestToWorld; // [esp+68h] [ebp-190h] BYREF
  matrix3x4_t worldToForward; // [esp+98h] [ebp-160h] BYREF
  matrix3x4_t eyesToWorld; // [esp+C8h] [ebp-130h] BYREF
  matrix3x4_t tmpM; // [esp+F8h] [ebp-100h] BYREF
  matrix3x4_t worldToChest; // [esp+128h] [ebp-D0h] BYREF
  matrix3x4a_t targetXform; // [esp+158h] [ebp-A0h] BYREF
  matrix3x4_t forwardToWorld; // [esp+190h] [ebp-68h] BYREF
  QAngle vTargetAngles; // [esp+1C0h] [ebp-38h] BYREF
  Vector vTargetDir; // [esp+1CCh] [ebp-2Ch] BYREF
  Vector vTargetLocal; // [esp+1D8h] [ebp-20h] BYREF
  QAngle angBias; // [esp+1E4h] [ebp-14h]
  int iForward; // [esp+1F0h] [ebp-8h]
  int retaddr; // [esp+1F8h] [ebp+0h]

  angBias.z = a2;
  iForward = retaddr;
  if ( (((int (__thiscall *)(CAI_BaseActor *, int, int))this->CapabilitiesGet)(a1: this, a2: a3, a3: a4) & 0x1000) != 0 )
  {
    v7 = CBaseAnimating::LookupAttachment(this, szName: "eyes");
    LODWORD(angBias.y) = CBaseAnimating::LookupAttachment(this, szName: "chest");
    v8 = CBaseAnimating::LookupAttachment(this, szName: "forward");
    LODWORD(angBias.x) = v8;
    if ( v7 > 0 && v8 > 0 )
    {
      ((void (__thiscall *)(CAI_BaseActor *, int, float *, _DWORD))this->GetAttachment)(
        a1: this,
        a2: v7,
        a3: &worldToForward.m_flMatVal[2][1],
        a4: LODWORD(angBias.y));
      this->GetAttachment(this, a2: LODWORD(angBias.x), a3: (matrix3x4a_t *)&targetXform.m_flMatVal[2][3]);
      MatrixInvert(
        in: (matrix3x4a_t *)&targetXform.m_flMatVal[2][3],
        out: (matrix3x4_t *)&chestToWorld.m_flMatVal[2][1]);
      if ( SLODWORD(angBias.y) <= 0 )
      {
        memset((void *)&vTargetLocal, 0, sizeof(vTargetLocal));
      }
      else
      {
        this->GetAttachment(this, a2: LODWORD(angBias.y), a3: (matrix3x4_t *)&headXform.m_flMatVal[2][1]);
        MatrixInvert(in: (matrix3x4_t *)&headXform.m_flMatVal[2][1], out: (matrix3x4_t *)&tmpM.m_flMatVal[2][1]);
        ConcatTransforms(
          in1: (matrix3x4_t *)&tmpM.m_flMatVal[2][1],
          in2: (matrix3x4_t *)&worldToForward.m_flMatVal[2][1],
          out: (matrix3x4_t *)&eyesToWorld.m_flMatVal[2][1]);
        MatrixAngles(src: (const VMatrix *)&eyesToWorld.m_flMatVal[2][1], vAngles: (QAngle *)&vTargetLocal);
        PoseParameter = CBaseAnimating::GetPoseParameter(this, iParameter: this->m_ParameterHeadYaw);
        LODWORD(angBias.y) = this->m_ParameterHeadPitch;
        vTargetLocal.y = vTargetLocal.y - PoseParameter;
        v10 = CBaseAnimating::GetPoseParameter(this, iParameter: SLODWORD(angBias.y));
        LODWORD(angBias.y) = this->m_ParameterHeadRoll;
        vTargetLocal.x = vTargetLocal.x - v10;
        v11 = CBaseAnimating::GetPoseParameter(this, iParameter: SLODWORD(angBias.y));
        vTargetLocal.z = vTargetLocal.z - v11;
      }
      matrix3x4a_t::operator=(
        this: (matrix3x4a_t *)&worldToChest.m_flMatVal[2][1],
        src: (matrix3x4a_t *)&targetXform.m_flMatVal[2][3]);
      v12 = this->EyePosition(this, result: &vTargetDir);
      vTargetAngles.x = vHeadTarget->x - v12->x;
      vTargetAngles.y = vHeadTarget->y - v12->y;
      vTargetAngles.z = vHeadTarget->z - v12->z;
      if ( scene_clamplookat.m_pParent != nullptr && scene_clamplookat.m_pParent->m_Value.m_nValue != 0 )
      {
        VectorNormalize(vec: (Vector *)&vTargetAngles);
        VectorIRotate(in1: &vTargetAngles.x, in2: (matrix3x4a_t *)&targetXform.m_flMatVal[2][3], out: &vTargetDir.x);
        x = vTargetDir.x;
        if ( vTargetDir.x >= 0.1 )
        {
          if ( vTargetDir.x > 1.0 )
            x = 1.0;
        }
        else
        {
          x = 0.1;
        }
        vTargetDir.z = x * vTargetDir.z;
        VectorNormalize(vec: &vTargetDir);
        VectorRotate(in1: &vTargetDir.x, in2: (matrix3x4a_t *)&targetXform.m_flMatVal[2][3], out: &vTargetAngles.x);
        *(double *)&v14 = 0.0;
        v15 = (float)(vTargetDir.x + 1.0) * 2.0;
        if ( v15 < 0.0 || (*(double *)&v14 = 1.0, v15 > 1.0) )
          v15 = *(double *)&v14;
        flHeadInfluence = flHeadInfluence * v15;
      }
      Studio_AlignIKMatrix(
        mMat: (matrix3x4a_t *)&worldToChest.m_flMatVal[2][1],
        vAlignTo: (const Vector *)&vTargetAngles);
      ConcatTransforms(
        in1: (matrix3x4_t *)&chestToWorld.m_flMatVal[2][1],
        in2: (matrix3x4_t *)&worldToChest.m_flMatVal[2][1],
        out: (matrix3x4_t *)v33);
      MatrixAngles(src: (const VMatrix *)v33, vAngles: (QAngle *)&forwardToWorld.m_flMatVal[2][1]);
      v16 = ((double (__thiscall *)(CAI_BaseActor *))this->GetHeadDebounce)(a1: this);
      v17 = this->m_goalHeadCorrection.x;
      angBias.y = v16 * flHeadInfluence + 1.0 - flHeadInfluence;
      y = angBias.y;
      v19 = 1.0 - angBias.y;
      v20 = (float)(v17 * y) + (float)(forwardToWorld.m_flMatVal[2][1] * (float)(1.0 - y));
      if ( (float)(v20 - v17) <= 10.0 )
      {
        if ( (float)(v20 - v17) >= -10.0 )
          goto LABEL_22;
        v21 = v17 - 10.0;
      }
      else
      {
        v21 = v17 + 10.0;
      }
      v20 = v21;
LABEL_22:
      v22 = this->m_goalHeadCorrection.y;
      v23 = forwardToWorld.m_flMatVal[2][2];
      this->m_goalHeadCorrection.x = v20;
      v24 = (float)(v22 * y) + (float)(v23 * v19);
      if ( (float)(v24 - v22) <= 30.0 )
      {
        if ( (float)(v24 - v22) >= -30.0 )
          goto LABEL_27;
        v25 = v22 - 30.0;
      }
      else
      {
        v25 = v22 + 30.0;
      }
      v24 = v25;
LABEL_27:
      z = this->m_goalHeadCorrection.z;
      v27 = forwardToWorld.m_flMatVal[2][3];
      this->m_goalHeadCorrection.y = v24;
      v28 = (float)(z * y) + (float)(v27 * v19);
      if ( (float)(v28 - z) <= 10.0 )
      {
        if ( (float)(v28 - z) >= -10.0 )
        {
LABEL_32:
          LODWORD(angBias.x) = this->m_FlexweightHeadRightLeft;
          this->m_goalHeadCorrection.z = v28;
          angBias.y = CBaseFlex::GetFlexWeight(this, index: SLODWORD(angBias.x));
          angBias.x = CBaseAnimating::EdgeLimitPoseParameter(
                        this,
                        iParameter: this->m_ParameterHeadYaw,
                        flValue: angBias.y + this->m_goalHeadCorrection.y,
                        flBase: vTargetLocal.y);
          CAI_BaseActor::Set(this, index: this->m_ParameterHeadYaw, flValue: angBias.x);
          angBias.y = CBaseFlex::GetFlexWeight(this, index: (LocalFlexController_t)this->m_FlexweightHeadUpDown);
          angBias.x = CBaseAnimating::EdgeLimitPoseParameter(
                        this,
                        iParameter: this->m_ParameterHeadPitch,
                        flValue: this->m_goalHeadCorrection.x + angBias.y,
                        flBase: vTargetLocal.x);
          v30 = angBias.x;
          angBias.x = v31;
          CAI_BaseActor::Set(this, index: this->m_ParameterHeadPitch, flValue: v30);
          angBias.y = CBaseFlex::GetFlexWeight(this, index: (LocalFlexController_t)this->m_FlexweightHeadTilt);
          angBias.x = CBaseAnimating::EdgeLimitPoseParameter(
                        this,
                        iParameter: this->m_ParameterHeadRoll,
                        flValue: this->m_goalHeadCorrection.z + angBias.y,
                        flBase: vTargetLocal.z);
          CAI_BaseActor::Set(this, index: this->m_ParameterHeadRoll, flValue: angBias.x);
          return;
        }
        v29 = z - 10.0;
      }
      else
      {
        v29 = z + 10.0;
      }
      v28 = v29;
      goto LABEL_32;
    }
    CAI_BaseNPC::CapabilitiesRemove(this, capability: 4096);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013B20
// Name: public: virtual class Vector CAI_BaseActor::EyeDirection3D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseActor::EyeDirection3D(CAI_BaseActor *this, Vector *result)
{
  float z; // ecx

  CAI_BaseActor::UpdateLatchedValues(this);
  z = this->m_latchedEyeDirection.z;
  *(_QWORD *)&result->x = *(_QWORD *)&this->m_latchedEyeDirection.x;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013B50
// Name: public: virtual class Vector CAI_BaseActor::HeadDirection3D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_BaseActor::HeadDirection3D(CAI_BaseActor *this, Vector *result)
{
  float z; // ecx

  CAI_BaseActor::UpdateLatchedValues(this);
  z = this->m_latchedHeadDirection.z;
  *(_QWORD *)&result->x = *(_QWORD *)&this->m_latchedHeadDirection.x;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013B80
// Name: public: virtual float CAI_BaseActor::PickLookTarget(class CAI_InterestTarget __near &,bool,float,float)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CAI_BaseActor::PickLookTarget@<st0>(
        CAI_BaseActor *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CAI_InterestTarget *queue,
        bool bExcludePlayers,
        float minTime,
        float maxTime)
{
  bool (__thiscall *PickTacticalLookTarget)(CAI_BaseActor *, AILookTargetArgs_t *); // edx
  CBaseEntity *m_pEntity; // eax
  AILookTargetArgs_t args; // [esp+44h] [ebp-24h] BYREF

  args.vTarget = vec3_invalid;
  args.hTarget.m_Index = -1;
  args.flDuration = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD, int, int))random->RandomFloat)(
                      a1: random,
                      a2: LODWORD(minTime),
                      a3: LODWORD(maxTime),
                      a4: a2,
                      a5: a3);
  args.flInfluence = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                       a1: random,
                       a2: 1050253722,
                       a3: 1056964608);
  args.flRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1045220557,
                  a3: 1053609165);
  PickTacticalLookTarget = this->PickTacticalLookTarget;
  args.bExcludePlayers = bExcludePlayers;
  args.pQueue = queue;
  if ( !PickTacticalLookTarget(this, a2: &args) && !this->PickRandomLookTarget(this, a2: &args) )
    ((void (__thiscall *)(CAI_BaseActor *, AILookTargetArgs_t *, _DWORD, _DWORD))this->MakeRandomLookTarget)(
      a1: this,
      a2: &args,
      a3: LODWORD(minTime),
      a4: LODWORD(maxTime));
  this->OnSelectedLookTarget(this, a2: &args);
  if ( args.hTarget.m_Index != -1
    && g_pEntityList->m_EntPtrArray[LOWORD(args.hTarget.m_Index)].m_SerialNumber == HIWORD(args.hTarget.m_Index)
    && g_pEntityList->m_EntPtrArray[LOWORD(args.hTarget.m_Index)].m_pEntity != nullptr )
  {
    if ( g_pEntityList->m_EntPtrArray[LOWORD(args.hTarget.m_Index)].m_SerialNumber == HIWORD(args.hTarget.m_Index) )
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(args.hTarget.m_Index)].m_pEntity;
    else
      m_pEntity = nullptr;
    CAI_InterestTarget::Add(
      this: queue,
      pTarget: m_pEntity,
      flImportance: args.flInfluence,
      flDuration: args.flDuration,
      flRamp: args.flRamp);
    return args.flDuration;
  }
  else
  {
    CAI_InterestTarget::Add(
      this: queue,
      vecPosition: &args.vTarget,
      flImportance: args.flInfluence,
      flDuration: args.flDuration,
      flRamp: args.flRamp);
    return args.flDuration;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013D60
// Name: public: virtual bool CAI_BaseActor::PickRandomLookTarget(struct AILookTargetArgs_t __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CAI_BaseActor::PickRandomLookTarget@<al>(
        CAI_BaseActor *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        AILookTargetArgs_t *pArgs)
{
  float x; // edi
  CAI_Navigator *m_pNavigator; // ecx
  __int128 v7; // xmm0
  int v8; // xmm0_4
  int v10; // eax
  CBaseEntity *CurrentEntity; // esi
  unsigned int m_Index; // ecx
  CBaseEntityList *v13; // edi
  int v14; // eax
  CEntInfo *v15; // edx
  unsigned int v16; // ecx
  int v17; // eax
  bool v18; // zf
  CEntInfo *v19; // eax
  IHandleEntity *v20; // eax
  unsigned int v21; // eax
  IHandleEntity *m_pEntity; // edi
  IHandleEntity_vtbl *v23; // eax
  IHandleEntity *v24; // eax
  int (__thiscall *v25)(_DWORD, CBaseEntity **, int, int); // edx
  float *v26; // edi
  float *v27; // eax
  float v28; // edi
  int v29; // edi
  int v30; // eax
  int flDistance; // [esp+2Ch] [ebp-858h]
  _DWORD v33[3]; // [esp+30h] [ebp-854h] BYREF
  CEntitySphereQuery sphere; // [esp+3Ch] [ebp-848h] BYREF
  __int128 v35; // [esp+848h] [ebp-3Ch] BYREF
  float v36; // [esp+858h] [ebp-2Ch]
  int v37; // [esp+85Ch] [ebp-28h]
  CBaseEntity *v38; // [esp+860h] [ebp-24h]
  int flDist; // [esp+864h] [ebp-20h]
  int iHighestImportance; // [esp+868h] [ebp-1Ch] BYREF
  CBaseEntity *pBestEntity; // [esp+86Ch] [ebp-18h]
  int iConsidered; // [esp+870h] [ebp-14h]
  Vector vLookTargetDir; // [esp+874h] [ebp-10h]
  float retaddr; // [esp+884h] [ebp+0h]

  vLookTargetDir.y = a2;
  vLookTargetDir.z = retaddr;
  flDistance = a4;
  x = *(float *)&this;
  m_pNavigator = this->m_pNavigator;
  vLookTargetDir.x = x;
  if ( CAI_Navigator::IsGoalActive(this: m_pNavigator)
    && CAI_Navigator::IsGoalSet(this: *(CAI_Navigator **)(LODWORD(x) + 2772))
    && random->RandomInt(this: random, a2: 1, a3: 10) <= 3
    && CAI_Navigator::GetPointAlongPath(
         this: *(CAI_Navigator **)(LODWORD(x) + 2772),
         pResult: (Vector *)&iHighestImportance,
         distance: 144.0,
         fReducibleOnly: false) )
  {
    if ( (*(_DWORD *)(LODWORD(x) + 196) & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(x));
    v7 = 0;
    *(float *)&v7 = fsqrt(
                      (float)((float)((float)(*(float *)&pBestEntity - *(float *)(LODWORD(x) + 464))
                                    * (float)(*(float *)&pBestEntity - *(float *)(LODWORD(x) + 464)))
                            + (float)((float)(*(float *)&iConsidered - *(float *)(LODWORD(x) + 468))
                                    * (float)(*(float *)&iConsidered - *(float *)(LODWORD(x) + 468))))
                    + (float)((float)(*(float *)&iHighestImportance - *(float *)(LODWORD(x) + 460))
                            * (float)(*(float *)&iHighestImportance - *(float *)(LODWORD(x) + 460))));
    v35 = v7;
    if ( *(float *)&v7 > 96.0 )
    {
      if ( ((int (__thiscall *)(IUniformRandomStream *, int, int, int, int))random->RandomInt)(
             a1: random,
             a2: 1,
             a3: 10,
             a4: a3,
             a5: a4) > 5 )
      {
        CHandle<CBaseEntity>::operator=(this: &pArgs->hTarget, val: (const CBaseEntity *)LODWORD(x));
        vLookTargetDir.x = 2.0;
        v8 = 1065353216;
      }
      else
      {
        pArgs->vTarget.x = *(float *)&iHighestImportance;
        pArgs->vTarget.y = *(float *)&pBestEntity;
        pArgs->vTarget.z = *(float *)&iConsidered;
        vLookTargetDir.x = 0.40000001;
        v8 = 1045220557;
      }
      pArgs->flDuration = ((double (__thiscall *)(IUniformRandomStream *, int))random->RandomFloat)(a1: random, a2: v8);
      pArgs->flRamp = 0.2;
      return 1;
    }
  }
  if ( *(_DWORD *)(LODWORD(x) + 2520) == 3 && random->RandomInt(this: random, a2: 1, a3: 10) <= 8 )
  {
    pArgs->hTarget.m_Index = *(_DWORD *)(*(int (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(x) + 8))(
                                          a1: COERCE_FLOAT(LODWORD(x)),
                                          a2: a3,
                                          a3: a4);
    return 1;
  }
  v10 = *(_DWORD *)(LODWORD(x) + 196) >> 11;
  v38 = nullptr;
  v37 = 0;
  flDist = 0;
  if ( (v10 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(x));
  CEntitySphereQuery::CEntitySphereQuery(
    this: (CEntitySphereQuery *)v33,
    center: (const Vector *)(LODWORD(x) + 460),
    radius: 360.0,
    flagMask: 0);
  CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v33);
  if ( CurrentEntity != nullptr )
  {
    while ( 1 )
    {
      if ( CurrentEntity != (CBaseEntity *)LODWORD(x)
        && (!pArgs->bExcludePlayers || (CurrentEntity->m_fFlags.m_Value & 0x100) == 0)
        && CurrentEntity->IsViewable(this: CurrentEntity) )
      {
        m_Index = CurrentEntity->m_hOwnerEntity.m_Value.m_Index;
        if ( m_Index == -1 )
          break;
        v13 = g_pEntityList;
        v14 = (unsigned __int16)m_Index;
        v15 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v16 = HIWORD(m_Index);
        if ( v15->m_SerialNumber != v16 || v15->m_pEntity == nullptr )
          goto LABEL_30;
        v17 = v14;
        v18 = g_pEntityList->m_EntPtrArray[v17].m_SerialNumber == v16;
        v19 = &g_pEntityList->m_EntPtrArray[v17];
        v20 = v18 ? v19->m_pEntity : nullptr;
        if ( v20->__vftable[30].GetRefEHandle(this: v20) != nullptr )
          break;
LABEL_54:
        x = vLookTargetDir.x;
      }
      ++v33[0];
      CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v33);
      if ( CurrentEntity == nullptr )
        goto LABEL_58;
    }
    v13 = g_pEntityList;
LABEL_30:
    v21 = CurrentEntity->m_pParent.m_Index;
    if ( v21 == -1 || v13->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
      m_pEntity = nullptr;
    else
      m_pEntity = v13->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      while ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: m_pEntity) == 0 )
      {
        v23 = m_pEntity[52].__vftable;
        if ( v23 == (IHandleEntity_vtbl *)-1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != (unsigned int)v23 >> 16 )
        {
          v24 = nullptr;
        }
        else
        {
          v24 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
        }
        m_pEntity = v24;
        if ( v24 == nullptr )
          goto LABEL_41;
      }
    }
    else
    {
LABEL_41:
      if ( CAI_InterestTarget::Find(this: pArgs->pQueue, pTarget: CurrentEntity) == -1 )
      {
        v25 = *(int (__thiscall **)(_DWORD, CBaseEntity **, int, int))(*(_DWORD *)LODWORD(vLookTargetDir.x) + 504);
        ++flDist;
        v26 = (float *)v25(a1: LODWORD(vLookTargetDir.x), a2: &sphere.m_pList[510], a3, a4: flDistance);
        v27 = (float *)CurrentEntity->EyePosition(this: CurrentEntity, result: (Vector *)((char *)&v35 + 4));
        *(float *)&iHighestImportance = *v27 - *v26;
        *(float *)&pBestEntity = v27[1] - v26[1];
        *(float *)&iConsidered = v27[2] - v26[2];
        v36 = VectorNormalize(vec: (Vector *)&iHighestImportance);
        if ( (CurrentEntity->m_fFlags.m_Value & 0x100) != 0
          && (CurrentEntity->IsMoving(this: CurrentEntity) || random->RandomInt(this: random, a2: 0, a3: 2) == 0) )
        {
          v28 = vLookTargetDir.x;
          if ( CAI_BaseActor::ValidHeadTarget(
                 this: (CAI_BaseActor *)LODWORD(vLookTargetDir.x),
                 vLookTargetDir: (const Vector *)&iHighestImportance,
                 flDistance: v36)
            && (*(unsigned __int8 (__thiscall **)(float, CBaseEntity *, int, _DWORD))(*(_DWORD *)LODWORD(v28) + 556))(
                 a1: COERCE_FLOAT(LODWORD(v28)),
                 a2: CurrentEntity,
                 a3: 16449,
                 a4: 0) != 0 )
          {
            pArgs->flDuration = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                  a1: random,
                                  a2: 1065353216,
                                  a3: 1082130432);
            v38 = CurrentEntity;
            goto LABEL_58;
          }
        }
        flDistance = 100;
        a3 = 1;
        v29 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
        if ( CurrentEntity->MyNPCPointer(this: CurrentEntity) != nullptr )
        {
          v29 *= 10;
          if ( CurrentEntity->IsMoving(this: CurrentEntity) )
            v29 *= 10;
        }
        if ( v29 > v37
          && CAI_BaseActor::ValidHeadTarget(
               this: (CAI_BaseActor *)LODWORD(vLookTargetDir.x),
               vLookTargetDir: (const Vector *)&iHighestImportance,
               flDistance: v36)
          && (*(unsigned __int8 (__thiscall **)(_DWORD, CBaseEntity *, int, _DWORD))(*(_DWORD *)LODWORD(vLookTargetDir.x)
                                                                                   + 556))(
               a1: LODWORD(vLookTargetDir.x),
               a2: CurrentEntity,
               a3: 16449,
               a4: 0) != 0 )
        {
          v37 = v29;
          v38 = CurrentEntity;
        }
      }
    }
    goto LABEL_54;
  }
LABEL_58:
  v30 = random->RandomInt(this: random, a2: 0, a3: 5);
  if ( flDist < v30 || v38 == nullptr )
    return 0;
  pArgs->hTarget.m_Index = v38->GetRefEHandle(this: v38)->m_Index;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014290
// Name: public: void CAI_BaseActor::ClearExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::ClearExpression(CAI_BaseActor *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hExpressionSceneEnt.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    StopScriptedScene(pActor: this, hSceneEnt: this->m_hExpressionSceneEnt);
  }
  this->m_iszExpressionScene.pszValue = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10014400
// Name: public: void CAI_InterestTarget::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_InterestTarget::Cleanup(CAI_InterestTarget *this)
{
  int v2; // esi
  int v3; // ebx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      if ( !CAI_InterestTarget_t::IsActive(this: &this->m_Memory.m_pMemory[v3]) )
      {
        if ( this->m_Size - v2 - 1 > 0 )
          _V_memmove(
            dest: &this->m_Memory.m_pMemory[v3],
            src: &this->m_Memory.m_pMemory[v3 + 1],
            count: 36 * (this->m_Size - v2 - 1));
        --this->m_Size;
      }
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014450
// Name: public: virtual void CAI_BaseActor::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::Precache(CAI_BaseActor *this)
{
  int i; // edi
  CAI_BehaviorBase *v3; // ecx
  const char *pszValue; // esi

  CAI_BaseNPC::Precache(this);
  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v3 = this->m_Behaviors.m_Memory.m_pMemory[i];
    v3->Precache(this: v3);
  }
  if ( this->m_iszExpressionOverride.pszValue != nullptr )
    PrecacheInstancedScene(pszScene: this->m_iszExpressionOverride.pszValue);
  if ( this->m_iszIdleExpression.pszValue != nullptr )
    PrecacheInstancedScene(pszScene: this->m_iszIdleExpression.pszValue);
  if ( this->m_iszCombatExpression.pszValue != nullptr )
    PrecacheInstancedScene(pszScene: this->m_iszCombatExpression.pszValue);
  if ( this->m_iszAlertExpression.pszValue != nullptr )
    PrecacheInstancedScene(pszScene: this->m_iszAlertExpression.pszValue);
  pszValue = this->m_iszDeathExpression.pszValue;
  if ( pszValue != nullptr )
    PrecacheInstancedScene(pszScene: pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x100144F0
// Name: public: virtual bool CAI_BaseActor::ProcessSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseActor::ProcessSceneEvent(
        CAI_BaseActor *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  CChoreoEvent::EVENTTYPE Type; // eax
  char result; // al
  float m_flBlinktime; // xmm0_4
  CBaseEntity *v9; // eax
  Vector *v10; // eax
  CAI_InterestTarget *p_m_syntheticLookQueue; // ebx
  int v12; // eax
  float v13; // xmm0_4
  CBaseEntity *v14; // eax
  unsigned int m_Index; // eax
  float y; // xmm0_4
  float v17; // xmm0_4
  unsigned int v18; // eax
  CAI_BaseActor *m_pEntity; // ecx
  double DmgModClub; // st7
  float v21; // xmm0_4
  double v22; // st7
  float v23; // xmm1_4
  double v24; // st7
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  CHandle<CBaseEntity> *v30; // eax
  float v31; // xmm1_4
  unsigned int v32; // eax
  IHandleEntity *v33; // ecx
  CBaseEntity *v34; // eax
  int (__thiscall *BodyTarget)(CBaseEntity *, char *); // edx
  char *v36; // ecx
  CAI_BaseActor_vtbl *v37; // ebx
  int v38; // eax
  const Vector *AbsOrigin; // eax
  double v40; // st7
  float m_flInitialYaw; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  double v44; // xmm1_8
  bool IsLockBodyFacing; // al
  float z; // xmm1_4
  float v47; // xmm1_4
  float v48; // xmm3_4
  float v49; // xmm1_4
  CAI_BaseActor_vtbl *v50; // edi
  CBaseEntity *v51; // eax
  char v52; // [esp+38h] [ebp-54h] BYREF
  char v53; // [esp+44h] [ebp-48h] BYREF
  _BYTE v54[12]; // [esp+50h] [ebp-3Ch] BYREF
  Vector startPos; // [esp+5Ch] [ebp-30h] BYREF
  Vector vecAimTargetLoc; // [esp+68h] [ebp-24h] BYREF
  Vector vec; // [esp+74h] [ebp-18h] BYREF
  float intensity; // [esp+80h] [ebp-Ch]
  CHandle<CBaseEntity> *p_m_hTarget; // [esp+84h] [ebp-8h]
  float goalYaw; // [esp+88h] [ebp-4h]
  bool bInScene_3; // [esp+97h] [ebp+Bh]
  float remaininga; // [esp+98h] [ebp+Ch]
  float remainingb; // [esp+98h] [ebp+Ch]
  float remainingc; // [esp+98h] [ebp+Ch]
  float remainingd; // [esp+98h] [ebp+Ch]
  float remaininge; // [esp+98h] [ebp+Ch]
  float remaining; // [esp+98h] [ebp+Ch]
  float eventa; // [esp+9Ch] [ebp+10h]
  float eventb; // [esp+9Ch] [ebp+10h]
  float eventc; // [esp+9Ch] [ebp+10h]

  Type = CChoreoEvent::GetType(this: info->m_pEvent);
  if ( Type == FACE )
  {
    p_m_hTarget = &info->m_hTarget;
    m_Index = info->m_hTarget.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      bInScene_3 = false;
      if ( !CChoreoEvent::IsLockBodyFacing(this: event) )
        bInScene_3 = CBaseFlex::EnterSceneSequence(this, scene, event, bRestart: true);
      if ( !info->m_bStarted )
      {
        y = this->m_angRotation.m_Value.y;
        info->m_flInitialYaw = y;
        info->m_flFacingYaw = info->m_flInitialYaw;
        info->m_flTargetYaw = y;
        if ( this->IsMoving(this) )
          v17 = 1.0;
        else
          v17 = 0.0;
        info->m_flWeight = v17;
      }
      v18 = p_m_hTarget->m_Index;
      if ( p_m_hTarget->m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CAI_BaseActor *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
      }
      if ( m_pEntity != this )
      {
        if ( !bInScene_3 || info->m_bIsMoving != this->IsMoving(this) )
          info->m_flInitialYaw = this->m_angRotation.m_Value.y;
        info->m_bIsMoving = this->IsMoving(this);
        *(double *)&vec.y = CChoreoEvent::GetEndTime(this: event) - 0.1;
        goalYaw = CChoreoEvent::GetStartTime(this: event);
        DmgModClub = CBreakableProp::GetDmgModClub(this: scene);
        intensity = DmgModClub;
        if ( goalYaw <= DmgModClub )
        {
          v21 = intensity;
          if ( intensity > *(double *)&vec.y )
            v21 = *(double *)&vec.y;
        }
        else
        {
          v21 = goalYaw;
        }
        intensity = CChoreoEvent::GetIntensity(this: event, scenetime: v21);
        remainingd = CBreakableProp::GetDmgModClub(this: scene);
        v22 = remainingd - CChoreoEvent::GetStartTime(this: event);
        if ( v22 >= 0.5 )
        {
          v23 = 1.0;
        }
        else
        {
          remaininge = v22;
          v23 = (float)((float)((float)(remaininge * 2.0) * (float)(remaininge * 2.0)) * 3.0)
              - (float)((float)((float)((float)(remaininge * 2.0) * (float)(remaininge * 2.0)) * 2.0)
                      * (float)(remaininge * 2.0));
        }
        if ( intensity >= 0.0 )
        {
          if ( intensity <= v23 )
            remaining = intensity;
          else
            remaining = v23;
        }
        else
        {
          remaining = 0.0;
        }
        if ( bInScene_3 && info->m_bIsMoving )
          info->m_flInitialYaw = this->m_angRotation.m_Value.y;
        if ( !CChoreoEvent::IsLockBodyFacing(this: event) && !info->m_bIsMoving && bInScene_3 )
          CAI_BaseActor::AccumulateIdealYaw(this, flYaw: info->m_flFacingYaw, flIntensity: remaining);
        v24 = AngleDiff(destAngle: info->m_flTargetYaw, srcAngle: this->m_angRotation.m_Value.y);
        goalYaw = v24;
        v25 = goalYaw;
        if ( v24 >= 0.0 )
        {
          v26 = 1.0;
        }
        else
        {
          LODWORD(v25) = LODWORD(goalYaw) ^ _mask__NegFloat_;
          v26 = -1.0;
        }
        v27 = 30.0;
        if ( v25 >= 30.0 )
          v28 = 30.0;
        else
          v28 = v25;
        v29 = v25 - v28;
        if ( v29 < 30.0 )
          v27 = v29;
        v30 = p_m_hTarget;
        v31 = (float)((float)(remaining * v27) * v26) + (float)(this->m_goalBodyYaw * (float)(1.0 - remaining));
        this->m_goalSpineYaw = (float)((float)(remaining * v28) * v26)
                             + (float)(this->m_goalSpineYaw * (float)(1.0 - remaining));
        this->m_goalBodyYaw = v31;
        v32 = v30->m_Index;
        if ( v32 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_SerialNumber != HIWORD(v32) )
          v33 = nullptr;
        else
          v33 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_pEntity;
        v34 = (CBaseEntity *)v33->__vftable[24].GetRefEHandle(this: v33);
        if ( v34 != nullptr )
        {
          BodyTarget = (int (__thiscall *)(CBaseEntity *, char *))v34->__vftable[2].BodyTarget;
          v36 = &v53;
        }
        else
        {
          v34 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hTarget);
          BodyTarget = (int (__thiscall *)(CBaseEntity *, char *))v34->EyePosition;
          v36 = &v52;
        }
        v37 = this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v38 = BodyTarget(a1: v34, a2: v36);
        goalYaw = v37->CalcIdealYaw(this, a2: (const Vector *)v38);
        if ( developer.m_pParent != nullptr
          && developer.m_pParent->m_Value.m_nValue > 0
          && scene_showfaceto.m_pParent != nullptr
          && scene_showfaceto.m_pParent->m_Value.m_nValue != 0 )
        {
          AbsOrigin = CBaseEntity::GetAbsOrigin(this);
          startPos.x = AbsOrigin->x;
          startPos.y = AbsOrigin->y;
          startPos.z = AbsOrigin->z + 1.0;
          NDebugOverlay::YawArrow(
            &startPos,
            yaw: goalYaw,
            length: (float)(remaining * 32.0) + 8.0,
            width: 8.0,
            r: 255,
            g: 255,
            b: 255,
            a: 0,
            noDepthTest: true,
            flDuration: 0.12);
        }
        v40 = AngleDiff(destAngle: goalYaw, srcAngle: info->m_flInitialYaw) * remaining;
        m_flInitialYaw = info->m_flInitialYaw;
        goalYaw = v40;
        intensity = 1.0;
        v42 = goalYaw;
        info->m_flTargetYaw = (float)(unsigned __int16)(int)(float)((float)(m_flInitialYaw + goalYaw) * 182.04445)
                            * 0.0054931641;
        if ( v40 < 0.0 )
        {
          LODWORD(v42) ^= _mask__NegFloat_;
          goalYaw = v42;
          intensity = -1.0;
        }
        v43 = (float)(remaining - 0.5) * 2.0;
        if ( v43 >= 0.0 )
          v44 = v43;
        else
          v44 = 0.0;
        vec.z = 1.0 - v44;
        if ( bInScene_3
          && (IsLockBodyFacing = CChoreoEvent::IsLockBodyFacing(this: event), v42 = goalYaw, !IsLockBodyFacing) )
        {
          z = vec.z;
        }
        else
        {
          z = 1.0;
        }
        v47 = z * v42;
        if ( v47 >= 30.0 )
          v48 = 30.0;
        else
          v48 = v47;
        v49 = v47 - v48;
        if ( v49 >= 30.0 )
          v49 = 30.0;
        info->m_flFacingYaw = (float)((float)((float)(v42 - v49) - v48) * intensity) + info->m_flInitialYaw;
        if ( !CChoreoEvent::IsLockBodyFacing(this: event) )
        {
          v50 = this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          v51 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hTarget);
          ((void (__thiscall *)(CAI_BaseActor *, CBaseEntity *, float, int, _DWORD))v50->AddFacingTarget)(
            a1: this,
            a2: v51,
            a3: COERCE_FLOAT(LODWORD(remaining)),
            a4: 1045220557,
            a5: 0);
        }
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else if ( Type == GENERIC )
  {
    switch ( info->m_nType )
    {
      case 1:
        eventa = CChoreoEvent::GetEndTime(this: event);
        remaininga = eventa - CBreakableProp::GetDmgModClub(this: scene);
        m_flBlinktime = gpGlobals->curtime + remaininga;
        if ( this->m_flBlinktime > m_flBlinktime )
          m_flBlinktime = this->m_flBlinktime;
        this->m_flBlinktime = m_flBlinktime;
        result = 1;
        break;
      case 2:
      case 3:
      case 7:
        return 1;
      case 4:
        if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &info->m_hTarget) == nullptr )
          return 1;
        v9 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &info->m_hTarget);
        v9->EyePosition(this: v9, result: &vecAimTargetLoc);
        v10 = this->EyePosition(this, result: v54);
        vec.x = vecAimTargetLoc.x - v10->x;
        vec.y = vecAimTargetLoc.y - v10->y;
        vec.z = vecAimTargetLoc.z - v10->z;
        VectorNormalize(&vec);
        this->SetAim(this, a2: &vec);
        result = 1;
        break;
      case 5:
        if ( gpGlobals->curtime <= info->m_flNext )
          return 1;
        p_m_syntheticLookQueue = &this->m_syntheticLookQueue;
        info->m_flNext = ((double (__thiscall *)(CAI_BaseActor *, CAI_InterestTarget *, _DWORD, int, int))this->PickLookTarget)(
                           a1: this,
                           a2: &this->m_syntheticLookQueue,
                           a3: 0,
                           a4: 1069547520,
                           a5: 1075838976)
                       + gpGlobals->curtime
                       - 0.4;
        if ( this->m_syntheticLookQueue.m_Size <= 0 )
          return 1;
        eventb = CChoreoEvent::GetEndTime(this: event);
        remainingb = eventb - CBreakableProp::GetDmgModClub(this: scene);
        v12 = 4 * (9 * this->m_syntheticLookQueue.m_Size - 9);
        v13 = gpGlobals->curtime + remainingb;
        if ( v13 > *(float *)((char *)&p_m_syntheticLookQueue->m_Memory.m_pMemory->m_flEndTime + v12) )
          v13 = *(float *)((char *)&p_m_syntheticLookQueue->m_Memory.m_pMemory->m_flEndTime + v12);
        *(float *)((char *)&p_m_syntheticLookQueue->m_Memory.m_pMemory->m_flEndTime + v12) = v13;
        *(float *)((char *)&p_m_syntheticLookQueue->m_Memory.m_pMemory->m_flInterest + v12) = 0.1;
        result = 1;
        break;
      case 6:
        result = CAI_BaseActor::RandomFaceFlex(this, info, scene, event);
        break;
      case 8:
        if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &info->m_hTarget) == nullptr
          || gpGlobals->curtime <= info->m_flNext )
        {
          return 1;
        }
        eventc = CChoreoEvent::GetEndTime(this: event);
        remainingc = eventc - CBreakableProp::GetDmgModClub(this: scene);
        v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &info->m_hTarget);
        NPCPhysics_CreateSolver(
          pNPC: this,
          pPhysicsObject: v14,
          disableCollisions: true,
          separationDuration: remainingc);
        info->m_flNext = gpGlobals->curtime + remainingc;
        result = 1;
        break;
      case 9:
        if ( this->m_NPCState == NPC_STATE_SCRIPT || CAI_BaseNPC::IsCurSchedule(this, schedId: 63, fIdeal: true) )
          return 1;
        CBaseFlex::EnterSceneSequence(this, scene, event, bRestart: false);
        result = 1;
        break;
      default:
        return 0;
    }
  }
  else
  {
    return CBaseFlex::ProcessSceneEvent(this, info, scene, event);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014D70
// Name: public: virtual void CAI_BaseActor::ClearLookTarget(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::ClearLookTarget(CAI_BaseActor *this, CBaseEntity *pTarget)
{
  int v3; // eax
  int v4; // eax
  float v5; // xmm0_4
  int v6; // eax
  float *p_m_flEndTime; // esi

  v3 = CAI_InterestTarget::Find(this: &this->m_lookQueue, pTarget);
  if ( v3 != -1 )
  {
    if ( this->m_lookQueue.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &this->m_lookQueue.m_Memory.m_pMemory[v3],
        src: &this->m_lookQueue.m_Memory.m_pMemory[v3 + 1],
        count: 36 * (this->m_lookQueue.m_Size - v3 - 1));
    --this->m_lookQueue.m_Size;
  }
  v4 = CAI_InterestTarget::Find(this: &this->m_randomLookQueue, pTarget);
  if ( v4 != -1 )
  {
    if ( this->m_randomLookQueue.m_Size - v4 - 1 > 0 )
      _V_memmove(
        dest: &this->m_randomLookQueue.m_Memory.m_pMemory[v4],
        src: &this->m_randomLookQueue.m_Memory.m_pMemory[v4 + 1],
        count: 36 * (this->m_randomLookQueue.m_Size - v4 - 1));
    --this->m_randomLookQueue.m_Size;
    v5 = gpGlobals->curtime + 1.0;
    v6 = 0;
    this->m_flNextRandomLookTime = v5;
    if ( this->m_randomLookQueue.m_Size > 0 )
    {
      p_m_flEndTime = &this->m_randomLookQueue.m_Memory.m_pMemory->m_flEndTime;
      do
      {
        if ( *p_m_flEndTime > v5 )
        {
          v5 = *p_m_flEndTime + 0.4;
          this->m_flNextRandomLookTime = v5;
        }
        ++v6;
        p_m_flEndTime += 9;
      }
      while ( v6 < this->m_randomLookQueue.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014E70
// Name: public: bool CAI_BaseActor::UpdateRemarkableSpeech(void)restrict
// Source: json
//------------------------------------------------------------------------------
char __usercall CAI_BaseActor::UpdateRemarkableSpeech@<al>(
        CAI_BaseActor *this@<ecx>,
        CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short> > *a2@<ebp>)
{
  float curtime; // xmm0_4
  CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short> > *ListOfAllThatIsRemarkable; // edx
  float v5; // xmm0_4
  unsigned __int16 m_Head; // cx
  float v7; // eax
  UtlLinkedListElem_t<CInfoRemarkable *,unsigned short> *m_pMemory; // edx
  bool v9; // zf
  UtlLinkedListElem_t<CInfoRemarkable *,unsigned short> *v10; // edx
  CInfoRemarkable *m_Element; // edi
  float v12; // xmm0_4
  float v13; // xmm1_4
  const char *pszValue; // eax
  float v15; // xmm0_4
  __int128 v16; // xmm1
  __int128 v17; // xmm0
  CAI_Expresser *v18; // eax
  bool (__thiscall *Speak)(CAI_ExpresserHost<CAI_BaseHumanoid> *, CAI_Concept, const char *, char *, unsigned int, IRecipientFilter *); // eax
  _DWORD v21[2]; // [esp-Ch] [ebp-64h] BYREF
  char *v22; // [esp-4h] [ebp-5Ch]
  __int64 v23; // [esp+0h] [ebp-58h]
  int v24; // [esp+8h] [ebp-50h]
  __int128 v25; // [esp+1Ch] [ebp-3Ch]
  char *v26; // [esp+38h] [ebp-20h]
  float v27; // [esp+3Ch] [ebp-1Ch]
  CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short> > *v28; // [esp+40h] [ebp-18h]
  const char *pModifiers; // [esp+44h] [ebp-14h]
  float maxDistSq; // [esp+48h] [ebp-10h]
  CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short> > *pList; // [esp+4Ch] [ebp-Ch]
  int remarkLimit; // [esp+50h] [ebp-8h]
  int retaddr; // [esp+58h] [ebp+0h]

  pList = a2;
  remarkLimit = retaddr;
  if ( this->m_bRemarkablePolling )
  {
    curtime = gpGlobals->curtime;
    if ( curtime > this->m_fNextRemarkPollTime )
    {
      this->m_fNextRemarkPollTime = curtime + 1.0;
      ListOfAllThatIsRemarkable = CInfoRemarkable::GetListOfAllThatIsRemarkable();
      v5 = rr_remarkable_max_distance.m_pParent->m_Value.m_fValue
         * rr_remarkable_max_distance.m_pParent->m_Value.m_fValue;
      v28 = ListOfAllThatIsRemarkable;
      v27 = v5;
      if ( rr_remarkable_world_entities_replay_limit.m_pParent != nullptr )
        pModifiers = (const char *)rr_remarkable_world_entities_replay_limit.m_pParent->m_Value.m_nValue;
      else
        pModifiers = nullptr;
      m_Head = ListOfAllThatIsRemarkable->m_Head;
      while ( 1 )
      {
        LODWORD(v7) = m_Head;
        LODWORD(maxDistSq) = m_Head;
        if ( m_Head >= ListOfAllThatIsRemarkable->m_Memory.m_nAllocationCount )
          break;
        if ( m_Head > ListOfAllThatIsRemarkable->m_LastAlloc.index )
          break;
        m_pMemory = ListOfAllThatIsRemarkable->m_Memory.m_pMemory;
        v9 = m_pMemory[m_Head].m_Previous == m_Head;
        v10 = &m_pMemory[m_Head];
        if ( v9 && v10->m_Next != m_Head )
          break;
        m_Element = v10->m_Element;
        if ( (v10->m_Element->m_iEFlags & 0x800) != 0 )
        {
          CBaseEntity::CalcAbsolutePosition(this: v10->m_Element);
          v7 = maxDistSq;
        }
        if ( (this->m_iEFlags & 0x800) != 0 )
        {
          CBaseEntity::CalcAbsolutePosition(this);
          v7 = maxDistSq;
        }
        if ( (float)((float)((float)((float)(this->m_vecAbsOrigin.y - m_Element->m_vecAbsOrigin.y)
                                   * (float)(this->m_vecAbsOrigin.y - m_Element->m_vecAbsOrigin.y))
                           + (float)((float)(this->m_vecAbsOrigin.x - m_Element->m_vecAbsOrigin.x)
                                   * (float)(this->m_vecAbsOrigin.x - m_Element->m_vecAbsOrigin.x)))
                   + (float)((float)(this->m_vecAbsOrigin.z - m_Element->m_vecAbsOrigin.z)
                           * (float)(this->m_vecAbsOrigin.z - m_Element->m_vecAbsOrigin.z))) <= v27
          && m_Element->m_iTimesRemarkedUpon < (int)pModifiers )
        {
          if ( this->TestRemarkingUpon(this, a2: m_Element) )
          {
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this);
            if ( (m_Element->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: m_Element);
            v12 = m_Element->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
            v13 = m_Element->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
            pszValue = m_Element->m_szRemarkContext.pszValue;
            v15 = (float)((float)(v12 * v12)
                        + (float)((float)(m_Element->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)
                                * (float)(m_Element->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)))
                + (float)(v13 * v13);
            v16 = 0;
            *(float *)&v16 = v15;
            v17 = v16;
            *(float *)&v17 = fsqrt(*(float *)&v16);
            v25 = v17;
            if ( pszValue == nullptr )
              pszValue = locale;
            v26 = UTIL_VarArgs(format: "Subject:%s,Distance:%f", pszValue, *(float *)&v25);
            v18 = this->GetExpresser(this);
            if ( CAI_Expresser::CanSpeak(this: v18) )
            {
              v24 = 0;
              v23 = 0;
              v22 = v26;
              v26 = (char *)v21;
              ResponseRules::CRR_Concept::CRR_Concept(this: (ResponseRules::CRR_Concept *)v21, fromString: "TLK_REMARK");
              Speak = this->Speak;
              *((_DWORD *)v26 + 1) = -1;
              if ( ((unsigned __int8 (__thiscall *)(CAI_BaseActor *, _DWORD, _DWORD, char *, _DWORD, _DWORD, int))Speak)(
                     a1: this,
                     a2: v21[0],
                     a3: v21[1],
                     a4: v22,
                     a5: v23,
                     a6: HIDWORD(v23),
                     a7: v24) != 0 )
              {
                ++m_Element->m_iTimesRemarkedUpon;
                return 1;
              }
            }
          }
          v7 = maxDistSq;
        }
        m_Head = v28->m_Memory.m_pMemory[LODWORD(v7)].m_Next;
        ListOfAllThatIsRemarkable = v28;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015110
// Name: public: float CAI_BaseActor::SetExpression(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseActor::SetExpression(CAI_BaseActor *this, const char *pszExpressionScene)
{
  const char *v2; // ebx
  const char *v4; // eax
  const char *v5; // ebx
  const char *DebugName; // eax
  unsigned int m_Index; // ecx
  char pszValue[4]; // [esp+20h] [ebp-4h] BYREF
  float flDuration; // [esp+2Ch] [ebp+8h]

  v2 = pszExpressionScene;
  if ( pszExpressionScene == nullptr || *pszExpressionScene == 0 )
  {
    m_Index = this->m_hExpressionSceneEnt.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      StopScriptedScene(pActor: this, hSceneEnt: this->m_hExpressionSceneEnt);
    }
    this->m_iszExpressionScene.pszValue = nullptr;
  }
  else
  {
    if ( this->m_iszExpressionScene.pszValue == nullptr )
      goto LABEL_26;
    v4 = this->m_iszExpressionScene.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    if ( _V_stricmp(s1: v4, s2: pszExpressionScene) != 0 )
    {
LABEL_26:
      if ( CHandle<CBaseEntity>::operator!=(this: &this->m_hExpressionSceneEnt, val: nullptr) )
        StopScriptedScene(pActor: this, hSceneEnt: this->m_hExpressionSceneEnt);
      if ( ai_debug_expressions.m_pParent != nullptr && ai_debug_expressions.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( this->m_iClassname.pszValue != nullptr )
        {
          v5 = this->m_iClassname.pszValue;
        }
        else
        {
          *(_DWORD *)pszValue = locale;
          v5 = locale;
        }
        DebugName = CBaseEntity::GetDebugName(this);
        _Msg(a1: "%s (%s) set expression to: %s\n", v5, DebugName, pszExpressionScene);
        v2 = pszExpressionScene;
      }
      this->m_iszExpressionScene.pszValue = nullptr;
      flDuration = InstancedScriptedScene(
                     pActor: this,
                     pszScene: v2,
                     phSceneEnt: &this->m_hExpressionSceneEnt,
                     flPostDelay: 0.0,
                     bIsBackground: true,
                     response: nullptr,
                     bMultiplayer: false,
                     filter: nullptr);
      if ( CHandle<CBaseEntity>::operator!=(this: &this->m_hExpressionSceneEnt, val: nullptr) )
        this->m_iszExpressionScene.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
      return flDuration;
    }
  }
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10015270
// Name: private: void CAI_BaseActor::InputSetExpressionOverride(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::InputSetExpressionOverride(CAI_BaseActor *this, inputdata_t *inputdata)
{
  bool v2; // dl
  variant_t *p_value; // eax
  const char *iVal; // eax

  v2 = this->m_iszExpressionOverride.pszValue != nullptr;
  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  iVal = (const char *)p_value->iVal;
  this->m_iszExpressionOverride.pszValue = iVal;
  if ( iVal != nullptr )
  {
    CAI_BaseActor::SetExpression(this, pszExpressionScene: iVal);
  }
  else if ( v2 )
  {
    this->PlayExpressionForState(this, a2: this->m_NPCState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100152D0
// Name: public: virtual void CAI_BaseActor::GatherConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BaseActor::GatherConditions(
        CAI_BaseActor *this@<ecx>,
        CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short> > *a2@<ebp>)
{
  CAI_BehaviorHost<CAI_BaseNPC>::GatherConditions(this);
  if ( rr_remarkables_enabled.m_pParent != nullptr && rr_remarkables_enabled.m_pParent->m_Value.m_nValue != 0 )
    CAI_BaseActor::UpdateRemarkableSpeech(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100153A0
// Name: public: void CBaseFlex::Blink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFlex::Blink(CBaseFlex *this)
{
  CNetworkVarBase<int,CBaseFlex::NetworkVar_m_blinktoggle> *p_m_blinktoggle; // esi
  int v2; // edi
  edict_t *m_pPev; // ecx

  p_m_blinktoggle = &this->m_blinktoggle;
  v2 = this->m_blinktoggle.m_Value == 0;
  if ( this->m_blinktoggle.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_blinktoggle->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x62Cu);
      p_m_blinktoggle->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100153F0
// Name: public: virtual bool CAI_BaseActor::StartSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *,class CChoreoActor __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseActor::StartSceneEvent(
        CAI_BaseActor *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event,
        CChoreoActor *actor,
        CBaseEntity *pTarget)
{
  const char *Parameters; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *Parameters2; // eax
  const CBaseEntity *v16; // eax
  const char *Filename; // eax
  const char *v18; // eax
  const char *separationDuration; // [esp+Ch] [ebp-10h]
  float remaining; // [esp+28h] [ebp+Ch]
  float remaininga; // [esp+28h] [ebp+Ch]
  CBaseEntity *actora; // [esp+30h] [ebp+14h]
  float pTargeta; // [esp+34h] [ebp+18h]
  CBaseEntity *pTargetb; // [esp+34h] [ebp+18h]
  float pTargetc; // [esp+34h] [ebp+18h]

  if ( CChoreoEvent::GetType(this: info->m_pEvent) != GENERIC )
    return CBaseFlex::StartSceneEvent(this, info, scene, event, actor, pTarget);
  Parameters = CChoreoEvent::GetParameters(this: event);
  if ( _V_stricmp(s1: Parameters, s2: "AI_BLINK") != 0 )
  {
    v8 = CChoreoEvent::GetParameters(this: event);
    if ( _V_stricmp(s1: v8, s2: "AI_HOLSTER") == 0 )
    {
      info->m_nType = 2;
      info->m_iLayer = this->HolsterWeapon(this);
      return true;
    }
    v9 = CChoreoEvent::GetParameters(this: event);
    if ( _V_stricmp(s1: v9, s2: "AI_UNHOLSTER") == 0 )
    {
      info->m_nType = 3;
      info->m_iLayer = this->UnholsterWeapon(this);
      return true;
    }
    v10 = CChoreoEvent::GetParameters(this: event);
    if ( _V_stricmp(s1: v10, s2: "AI_AIM") == 0 )
    {
      info->m_nType = 4;
      CHandle<CBaseEntity>::operator=(this: &info->m_hTarget, val: pTarget);
      return true;
    }
    v11 = CChoreoEvent::GetParameters(this: event);
    if ( _V_stricmp(s1: v11, s2: "AI_RANDOMLOOK") != 0 )
    {
      v12 = CChoreoEvent::GetParameters(this: event);
      if ( _V_stricmp(s1: v12, s2: "AI_RANDOMFACEFLEX") == 0 )
      {
        info->m_nType = 6;
        info->m_flNext = 0.0;
        CSceneEventInfo::InitWeight(this: info, pActor: this);
        return true;
      }
      v13 = CChoreoEvent::GetParameters(this: event);
      if ( _V_stricmp(s1: v13, s2: "AI_RANDOMHEADFLEX") != 0 )
      {
        v14 = CChoreoEvent::GetParameters(this: event);
        if ( _V_stricmp(s1: v14, s2: "AI_IGNORECOLLISION") != 0 )
        {
          v18 = CChoreoEvent::GetParameters(this: event);
          if ( _V_stricmp(s1: v18, s2: "AI_DISABLEAI") != 0 )
          {
            return CBaseFlex::StartSceneEvent(this, info, scene, event, actor, pTarget);
          }
          else
          {
            info->m_nType = 9;
            return true;
          }
        }
        else
        {
          pTargetb = (CBaseEntity *)this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          Parameters2 = CChoreoEvent::GetParameters2(this: event);
          v16 = (const CBaseEntity *)((int (__thiscall *)(CAI_BaseActor *, const char *, _DWORD))pTargetb[2].m_pfnUse)(
                                       a1: this,
                                       a2: Parameters2,
                                       a3: 0);
          actora = (CBaseEntity *)v16;
          if ( v16 != nullptr )
          {
            info->m_nType = 8;
            CHandle<CBaseEntity>::operator=(this: &info->m_hTarget, val: v16);
            pTargetc = CChoreoEvent::GetEndTime(this: event);
            remaininga = pTargetc - CBreakableProp::GetDmgModClub(this: scene);
            NPCPhysics_CreateSolver(
              pNPC: this,
              pPhysicsObject: actora,
              disableCollisions: true,
              separationDuration: remaininga);
            info->m_flNext = gpGlobals->curtime + remaininga;
            return true;
          }
          else
          {
            separationDuration = CChoreoEvent::GetParameters2(this: event);
            Filename = CChoreoScene::GetFilename(this: scene);
            _Warning(a1: "CSceneEntity %s unable to find actor named \"%s\"\n", Filename, separationDuration);
            return false;
          }
        }
      }
      info->m_nType = 7;
    }
    else
    {
      info->m_nType = 5;
    }
    info->m_flNext = 0.0;
    return true;
  }
  info->m_nType = 1;
  CBaseFlex::Blink(this);
  pTargeta = CChoreoEvent::GetEndTime(this: event);
  remaining = pTargeta - CBreakableProp::GetDmgModClub(this: scene);
  if ( remaining <= ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1069547520,
                      a3: 1083179008) )
    remaining = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1069547520,
                  a3: 1083179008);
  this->m_flBlinktime = gpGlobals->curtime + remaining;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10015760
// Name: public: virtual void CAI_BaseActor::PlayExpressionForState(enum NPC_STATE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::PlayExpressionForState(CAI_BaseActor *this, NPC_STATE state)
{
  CAI_BaseActor *v2; // esi
  const char *pszValue; // eax
  const char *v4; // eax

  v2 = this;
  if ( this->m_iszExpressionOverride.pszValue == nullptr || state == NPC_STATE_DEAD )
  {
    v4 = this->SelectRandomExpressionForState(this, a2: state);
    if ( v4 != nullptr && *v4 != 0 )
    {
      v2->m_flNextRandomExpressionTime = CAI_BaseActor::SetExpression(this: v2, pszExpressionScene: v4)
                                       + gpGlobals->curtime;
    }
    else
    {
      v2->m_flNextRandomExpressionTime = 0.0;
      switch ( state )
      {
        case NPC_STATE_IDLE:
          if ( v2->m_iszIdleExpression.pszValue != nullptr )
          {
            pszValue = v2->m_iszIdleExpression.pszValue;
            goto LABEL_17;
          }
          break;
        case NPC_STATE_ALERT:
          if ( v2->m_iszAlertExpression.pszValue != nullptr )
          {
            pszValue = v2->m_iszAlertExpression.pszValue;
            goto LABEL_17;
          }
          break;
        case NPC_STATE_COMBAT:
          if ( v2->m_iszCombatExpression.pszValue != nullptr )
          {
            pszValue = v2->m_iszCombatExpression.pszValue;
            goto LABEL_17;
          }
          break;
        case NPC_STATE_PLAYDEAD:
        case NPC_STATE_DEAD:
          if ( v2->m_iszDeathExpression.pszValue != nullptr )
          {
            pszValue = v2->m_iszDeathExpression.pszValue;
LABEL_17:
            if ( pszValue == nullptr )
              pszValue = locale;
            this = v2;
            goto LABEL_20;
          }
          break;
        default:
          return;
      }
    }
  }
  else
  {
    pszValue = this->m_iszExpressionOverride.pszValue;
    if ( pszValue != nullptr )
LABEL_20:
      CAI_BaseActor::SetExpression(this, pszExpressionScene: pszValue);
    else
      CAI_BaseActor::SetExpression(this, pszExpressionScene: locale);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015860
// Name: public: virtual void CAI_BaseActor::MaintainLookTargets(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAI_BaseActor::MaintainLookTargets(CAI_BaseActor *this@<ecx>, int a2@<ebx>, float flInterval)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  PoseParameter_t m_ParameterGestureHeight; // edi
  CStudioHdr *m_pStudioHdr; // eax
  PoseParameter_t m_ParameterGestureWidth; // edi
  CStudioHdr *v13; // eax
  CAI_InterestTarget *p_m_randomLookQueue; // edi
  int v15; // edx
  int v16; // ecx
  float curtime; // xmm1_4
  float m_flRamp; // xmm0_4
  float m_flNextRandomExpressionTime; // xmm0_4
  CAI_InterestTarget_t **m_pMemory; // ebx
  int m_Size; // edi
  float v22; // ecx
  float *v23; // eax
  float v24; // ecx
  float *v25; // eax
  float v26; // ecx
  float *v27; // eax
  int v28; // ebx
  int v29; // eax
  Vector *v30; // eax
  float x; // xmm4_4
  float y; // xmm2_4
  float z; // xmm3_4
  const Vector *Position; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  CAI_InterestTarget_t *v37; // ecx
  const Vector *v38; // eax
  double v39; // st7
  float v40; // xmm5_4
  float v41; // xmm1_4
  float v42; // xmm5_4
  float v43; // xmm1_4
  double v44; // xmm0_8
  float v45; // xmm1_4
  float v46; // xmm2_4
  unsigned int v47; // ebx
  int v48; // edi
  CAI_InterestTarget_t **v49; // ebx
  CAI_InterestTarget_t *v50; // ecx
  const Vector *v51; // eax
  IHandleEntity *m_pEntity; // edx
  unsigned int v53; // eax
  IHandleEntity *v54; // ecx
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CBaseEntity *); // eax
  Vector *v56; // eax
  float v57; // xmm0_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  CAI_BaseActor_vtbl *v60; // eax
  CAI_InterestTarget_t *v61; // edi
  CAI_BaseActor_vtbl *v62; // eax
  bool v63; // zf
  unsigned int v64; // ecx
  CAI_BaseActor *v65; // edx
  IHandleEntity *v66; // ecx
  const Vector *v67; // eax
  unsigned int v68; // eax
  CBaseEntity *v69; // ecx
  IHandleEntity *v70; // edx
  const char *v71; // ebx
  const char *DebugName; // eax
  const char *v73; // eax
  const Vector *v74; // eax
  double v75; // st7
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // edx
  Vector *(__thiscall *HeadDirection3D)(CBaseCombatCharacter *, Vector *); // edx
  float *v78; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v80; // eax
  float v81; // xmm1_4
  float v82; // xmm2_4
  void (__thiscall *SetViewtarget)(CBaseFlex *, const Vector *); // edx
  unsigned int v84; // ecx
  int v85; // eax
  CEntInfo *v86; // edx
  unsigned int v87; // ecx
  int v88; // eax
  CEntInfo *v89; // eax
  IHandleEntity *v90; // ebx
  unsigned int v91; // eax
  float v92; // edx
  CBaseEntity *v93; // ecx
  CBaseEntity *GroundEntity; // eax
  float *v95; // ebx
  float v96; // xmm0_4
  float v97; // xmm2_4
  float v98; // xmm1_4
  float v99; // ecx
  void (__thiscall *v100)(CBaseFlex *, const Vector *); // edx
  int v101; // edi
  edict_t *m_pPev; // ecx
  const Vector *v103; // eax
  const Vector *duration; // [esp+44h] [ebp-B4h]
  Vector *v106; // [esp+4Ch] [ebp-ACh]
  Vector v107; // [esp+54h] [ebp-A4h] BYREF
  Vector v108; // [esp+60h] [ebp-98h] BYREF
  Vector up; // [esp+6Ch] [ebp-8Ch] BYREF
  Vector right; // [esp+78h] [ebp-80h] BYREF
  Vector mins; // [esp+84h] [ebp-74h] BYREF
  Vector tmp1; // [esp+90h] [ebp-68h] BYREF
  Vector vEyePosition; // [esp+9Ch] [ebp-5Ch] BYREF
  float flHeadInfluence; // [esp+A8h] [ebp-50h]
  Vector vHead; // [esp+ACh] [ebp-4Ch] BYREF
  CUtlVector<CAI_InterestTarget_t *,CUtlMemory<CAI_InterestTarget_t *,int> > active; // [esp+B8h] [ebp-40h] BYREF
  Vector vHeadTarget; // [esp+CCh] [ebp-2Ch] BYREF
  int v118; // [esp+D8h] [ebp-20h]
  int i; // [esp+DCh] [ebp-1Ch]
  Vector viewTarget; // [esp+E0h] [ebp-18h] BYREF
  float flInterest; // [esp+ECh] [ebp-Ch]
  float FlexWeight; // [esp+F0h] [ebp-8h]
  bool bFoundTarget; // [esp+F7h] [ebp-1h]
  int savedregs; // [esp+F8h] [ebp+0h] BYREF

  if ( this->m_iszExpressionScene.pszValue != nullptr )
  {
    m_Index = this->m_hExpressionSceneEnt.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      pszValue = this->m_iszExpressionScene.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      InstancedScriptedScene(
        pActor: this,
        pszScene: pszValue,
        phSceneEnt: &this->m_hExpressionSceneEnt,
        flPostDelay: 0.0,
        bIsBackground: true,
        response: nullptr,
        bMultiplayer: false,
        filter: nullptr);
    }
  }
  v6 = this->m_goalSpineYaw * 0.8;
  this->m_goalSpineYaw = v6;
  v7 = this->m_goalBodyYaw * 0.8;
  this->m_goalBodyYaw = v7;
  v8 = this->m_goalHeadCorrection.y * 0.80000001;
  v9 = this->m_goalHeadCorrection.z * 0.80000001;
  this->m_goalHeadCorrection.x = this->m_goalHeadCorrection.x * 0.80000001;
  this->m_goalHeadCorrection.y = v8;
  this->m_goalHeadCorrection.z = v9;
  CAI_BaseActor::SetAccumulatedYawAndUpdate(this);
  this->ProcessSceneEvents(this);
  this->MaintainTurnActivity(this);
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CAI_BaseActor::UpdateBodyControl(this);
  this->InvalidateBoneCache(this);
  this->EyePosition(this, result: &vEyePosition);
  FlexWeight = CBaseFlex::GetFlexWeight(this, index: (LocalFlexController_t)this->m_FlexweightGestureUpDown);
  m_ParameterGestureHeight = this->m_ParameterGestureHeight;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  CBaseAnimating::SetPoseParameter(
    this,
    pStudioHdr: m_pStudioHdr,
    iParameter: m_ParameterGestureHeight,
    flValue: FlexWeight);
  FlexWeight = CBaseFlex::GetFlexWeight(this, index: (LocalFlexController_t)this->m_FlexweightGestureRightLeft);
  m_ParameterGestureWidth = this->m_ParameterGestureWidth;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v13 = this->m_pStudioHdr;
  if ( v13 == nullptr || v13->m_pStudioHdr == nullptr )
    v13 = nullptr;
  CBaseAnimating::SetPoseParameter(this, pStudioHdr: v13, iParameter: m_ParameterGestureWidth, flValue: FlexWeight);
  this->HeadDirection3D(this, result: &vHead);
  flHeadInfluence = 0.0;
  CAI_InterestTarget::Cleanup(this: &this->m_lookQueue);
  p_m_randomLookQueue = &this->m_randomLookQueue;
  CAI_InterestTarget::Cleanup(this: &this->m_randomLookQueue);
  CAI_InterestTarget::Cleanup(this: &this->m_syntheticLookQueue);
  if ( this->m_lookQueue.m_Size != 0 || this->m_syntheticLookQueue.m_Size != 0 )
  {
    v15 = 0;
    if ( this->m_randomLookQueue.m_Size > 0 )
    {
      v16 = 0;
      do
      {
        curtime = gpGlobals->curtime;
        m_flRamp = p_m_randomLookQueue->m_Memory.m_pMemory[v16].m_flRamp;
        if ( (float)(p_m_randomLookQueue->m_Memory.m_pMemory[v16].m_flEndTime - m_flRamp) - 0.2 > curtime )
          p_m_randomLookQueue->m_Memory.m_pMemory[v16].m_flEndTime = (float)(m_flRamp + curtime) + 0.2;
        ++v15;
        ++v16;
      }
      while ( v15 < this->m_randomLookQueue.m_Size );
    }
    this->m_flNextRandomLookTime = gpGlobals->curtime + 1.0;
  }
  else if ( gpGlobals->curtime >= this->m_flNextRandomLookTime && this->m_NPCState != NPC_STATE_SCRIPT )
  {
    this->m_flNextRandomLookTime = ((double (__thiscall *)(CAI_BaseActor *, CAI_InterestTarget *, _DWORD, int, int))this->PickLookTarget)(
                                     a1: this,
                                     a2: &this->m_randomLookQueue,
                                     a3: 0,
                                     a4: 1069547520,
                                     a5: 1075838976)
                                 + gpGlobals->curtime
                                 - 0.4;
  }
  if ( CBaseAnimating::CanSkipAnimation(this) )
    return;
  m_flNextRandomExpressionTime = this->m_flNextRandomExpressionTime;
  if ( m_flNextRandomExpressionTime != 0.0 && gpGlobals->curtime > m_flNextRandomExpressionTime )
  {
    CAI_BaseActor::ClearExpression(this);
    this->PlayExpressionForState(this, a2: this->m_NPCState);
  }
  m_pMemory = nullptr;
  *(float *)&m_Size = 0.0;
  memset(&active, 0, sizeof(active));
  i = 0;
  if ( this->m_randomLookQueue.m_Size > 0 )
  {
    flInterest = 0.0;
    do
    {
      LODWORD(v22) = (char *)this->m_randomLookQueue.m_Memory.m_pMemory + LODWORD(flInterest);
      FlexWeight = v22;
      v118 = m_Size;
      if ( m_Size + 1 > active.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&active,
          num: m_Size - active.m_Memory.m_nAllocationCount + 1);
        m_Size = active.m_Size;
        m_pMemory = active.m_Memory.m_pMemory;
        v22 = FlexWeight;
      }
      active.m_Size = ++m_Size;
      active.m_pElements = m_pMemory;
      if ( m_Size - v118 - 1 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v118 + 1], src: &m_pMemory[v118], count: 4 * (m_Size - v118 - 1));
        v22 = FlexWeight;
      }
      v23 = (float *)&m_pMemory[v118];
      if ( v23 != nullptr )
        *v23 = v22;
      LODWORD(flInterest) += 36;
      ++i;
    }
    while ( i < this->m_randomLookQueue.m_Size );
  }
  i = 0;
  if ( this->m_lookQueue.m_Size > 0 )
  {
    v118 = 0;
    do
    {
      LODWORD(v24) = (char *)this->m_lookQueue.m_Memory.m_pMemory + v118;
      FlexWeight = v24;
      flInterest = *(float *)&m_Size;
      if ( m_Size + 1 > active.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&active,
          num: m_Size - active.m_Memory.m_nAllocationCount + 1);
        m_Size = active.m_Size;
        m_pMemory = active.m_Memory.m_pMemory;
        v24 = FlexWeight;
      }
      active.m_Size = ++m_Size;
      active.m_pElements = m_pMemory;
      if ( m_Size - LODWORD(flInterest) - 1 > 0 )
      {
        _V_memmove(
          dest: &m_pMemory[LODWORD(flInterest) + 1],
          src: &m_pMemory[LODWORD(flInterest)],
          count: 4 * (m_Size - LODWORD(flInterest) - 1));
        v24 = FlexWeight;
      }
      v25 = (float *)&m_pMemory[LODWORD(flInterest)];
      if ( v25 != nullptr )
        *v25 = v24;
      v118 += 36;
      ++i;
    }
    while ( i < this->m_lookQueue.m_Size );
  }
  i = 0;
  if ( this->m_syntheticLookQueue.m_Size > 0 )
  {
    v118 = 0;
    do
    {
      LODWORD(v26) = (char *)this->m_syntheticLookQueue.m_Memory.m_pMemory + v118;
      FlexWeight = v26;
      flInterest = *(float *)&m_Size;
      if ( m_Size + 1 > active.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&active,
          num: m_Size - active.m_Memory.m_nAllocationCount + 1);
        m_Size = active.m_Size;
        m_pMemory = active.m_Memory.m_pMemory;
        v26 = FlexWeight;
      }
      active.m_Size = ++m_Size;
      active.m_pElements = m_pMemory;
      if ( m_Size - LODWORD(flInterest) - 1 > 0 )
      {
        _V_memmove(
          dest: &m_pMemory[LODWORD(flInterest) + 1],
          src: &m_pMemory[LODWORD(flInterest)],
          count: 4 * (m_Size - LODWORD(flInterest) - 1));
        v26 = FlexWeight;
      }
      v27 = (float *)&m_pMemory[LODWORD(flInterest)];
      if ( v27 != nullptr )
        *v27 = v26;
      v118 += 36;
      ++i;
    }
    while ( i < this->m_syntheticLookQueue.m_Size );
  }
  v28 = 0;
  bFoundTarget = false;
  i = 0;
  if ( m_Size <= 0 )
  {
    z = vHead.z;
    y = vHead.y;
    x = vHead.x;
    goto LABEL_79;
  }
  do
  {
    flInterest = CAI_InterestTarget_t::Interest(this: active.m_Memory.m_pMemory[v28]);
    if ( CAI_InterestTarget_t::IsThis(this: active.m_Memory.m_pMemory[v28], pThis: this) )
    {
      v29 = CBaseAnimating::LookupAttachment(this, szName: "forward");
      if ( v29 == 0 )
      {
        v30 = this->HeadDirection3D(this, result: &right);
        x = v30->x;
        viewTarget.x = v30->x;
        y = v30->y;
        viewTarget.y = y;
        z = v30->z;
        viewTarget.z = z;
        goto LABEL_69;
      }
      CBaseAnimating::GetAttachment(
        this,
        iAttachment: v29,
        absOrigin: &tmp1,
        forward: &viewTarget,
        right: nullptr,
        up: nullptr);
    }
    else
    {
      Position = CAI_InterestTarget_t::GetPosition(this: active.m_Memory.m_pMemory[v28]);
      v35 = Position->y - vEyePosition.y;
      v36 = Position->z - vEyePosition.z;
      viewTarget.x = Position->x - vEyePosition.x;
      viewTarget.y = v35;
      viewTarget.z = v36;
      VectorNormalize(vec: &viewTarget);
      v37 = active.m_Memory.m_pMemory[v28];
      FlexWeight = *(float *)&this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v38 = CAI_InterestTarget_t::GetPosition(this: v37);
      v39 = ((double (__thiscall *)(CAI_BaseActor *, const Vector *))*(_DWORD *)(LODWORD(FlexWeight) + 2528))(
              a1: this,
              a2: v38);
      v28 = i;
      flInterest = v39 * flInterest;
    }
    x = viewTarget.x;
    y = viewTarget.y;
    z = viewTarget.z;
LABEL_69:
    v40 = flHeadInfluence;
    if ( flInterest <= 0.0 )
    {
      z = vHead.z;
      y = vHead.y;
      x = vHead.x;
    }
    else
    {
      if ( flHeadInfluence == 0.0 )
      {
        v40 = flInterest;
      }
      else
      {
        v40 = (float)(flHeadInfluence * (float)(1.0 - flInterest)) + flInterest;
        v41 = flInterest / v40;
        z = (float)(z * v41) + (float)(vHead.z * (float)(1.0 - v41));
        y = (float)(vHead.y * (float)(1.0 - v41)) + (float)(y * v41);
        x = (float)((float)(1.0 - v41) * vHead.x) + (float)(x * v41);
      }
      vHead.z = z;
      vHead.y = y;
      vHead.x = x;
      flHeadInfluence = v40;
      bFoundTarget = true;
    }
    i = ++v28;
  }
  while ( v28 < m_Size );
  if ( !bFoundTarget )
  {
LABEL_79:
    v42 = this->m_goalHeadDirection.z;
    v43 = (float)(this->m_goalHeadDirection.y * 0.80000001) + (float)(y * 0.2);
    this->m_goalHeadDirection.x = (float)(this->m_goalHeadDirection.x * 0.80000001) + (float)(x * 0.2);
    this->m_goalHeadDirection.y = v43;
    this->m_goalHeadDirection.z = (float)(v42 * 0.80000001) + (float)(z * 0.2);
    v44 = this->m_goalHeadInfluence - 0.2;
    if ( v44 <= 0.0 )
      v44 = 0.0;
    this->m_goalHeadInfluence = v44;
    VectorNormalize(vec: &this->m_goalHeadDirection);
    v45 = this->m_goalHeadDirection.y;
    v46 = this->m_goalHeadDirection.z;
    vHeadTarget.x = (float)(this->m_goalHeadDirection.x * 100.0) + vEyePosition.x;
    vHeadTarget.y = vEyePosition.y + (float)(v45 * 100.0);
    vHeadTarget.z = vEyePosition.z + (float)(v46 * 100.0);
    CAI_BaseActor::UpdateHeadControl(
      this,
      a2: COERCE_FLOAT(&savedregs),
      a3: m_Size,
      a4: (int)this,
      &vHeadTarget,
      flHeadInfluence: this->m_goalHeadInfluence);
    goto LABEL_82;
  }
  vHeadTarget.y = vEyePosition.y + (float)(y * 100.0);
  vHeadTarget.x = (float)(x * 100.0) + vEyePosition.x;
  vHeadTarget.z = vEyePosition.z + (float)(z * 100.0);
  CAI_BaseActor::UpdateHeadControl(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: m_Size,
    a4: (int)this,
    &vHeadTarget,
    flHeadInfluence: v40);
  this->m_goalHeadDirection = vHead;
  this->m_goalHeadInfluence = flHeadInfluence;
LABEL_82:
  v47 = -1;
  v48 = m_Size - 1;
  bFoundTarget = false;
  flInterest = NAN;
  if ( v48 < 0 )
    goto LABEL_87;
  while ( 1 )
  {
    v49 = active.m_Memory.m_pMemory;
    if ( CAI_InterestTarget_t::IsThis(this: active.m_Memory.m_pMemory[v48], pThis: this) )
    {
      GetRefEHandle = this->GetRefEHandle;
      bFoundTarget = true;
      v47 = GetRefEHandle(this)->m_Index;
      v56 = this->HeadDirection3D(this, result: &tmp1);
      v57 = v56->x;
      v58 = v56->y;
      v59 = v56->z;
      v60 = this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      vHeadTarget.x = (float)(v57 * 100.0) + vEyePosition.x;
      vHeadTarget.y = vEyePosition.y + (float)(v58 * 100.0);
      vHeadTarget.z = vEyePosition.z + (float)(v59 * 100.0);
      v60->SetViewtarget(this, a2: &vHeadTarget);
      goto LABEL_93;
    }
    v50 = v49[v48];
    FlexWeight = *(float *)&this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v51 = CAI_InterestTarget_t::GetPosition(this: v50);
    if ( (*(unsigned __int8 (__thiscall **)(CAI_BaseActor *, const Vector *))(LODWORD(FlexWeight) + 2068))(
           a1: this,
           a2: v51) != 0 )
      break;
    if ( --v48 < 0 )
    {
      v47 = LODWORD(flInterest);
      goto LABEL_87;
    }
  }
  v61 = active.m_Memory.m_pMemory[v48];
  v62 = this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  v47 = v61->m_hTarget.m_Index;
  bFoundTarget = true;
  FlexWeight = *(float *)&v62;
  duration = CAI_InterestTarget_t::GetPosition(this: v61);
  (*(void (__thiscall **)(CAI_BaseActor *, const Vector *))(LODWORD(FlexWeight) + 916))(a1: this, a2: duration);
LABEL_93:
  if ( v47 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_SerialNumber != HIWORD(v47) )
LABEL_87:
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_pEntity;
  v53 = this->m_hLookTarget.m_Index;
  if ( v53 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v53].m_SerialNumber != HIWORD(v53) )
    v54 = nullptr;
  else
    v54 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v53].m_pEntity;
  if ( v54 != m_pEntity )
  {
    v63 = (this->m_debugOverlays & 0x1000) == 0;
    this->m_flBlinktime = this->m_flBlinktime - 0.5;
    this->m_hLookTarget.m_Index = v47;
    if ( !v63
      && ai_debug_looktargets.m_pParent != nullptr
      && ai_debug_looktargets.m_pParent->m_Value.m_nValue == 2
      && v47 != -1 )
    {
      v64 = HIWORD(v47);
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_SerialNumber == HIWORD(v47)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_pEntity != nullptr )
      {
        v65 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_SerialNumber == v64
            ? (CAI_BaseActor *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_pEntity
            : nullptr;
        if ( v65 != this )
        {
          if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_SerialNumber == v64 )
            v66 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_pEntity;
          else
            v66 = nullptr;
          ((void (__thiscall *)(IHandleEntity *, Vector *, int))v66->__vftable[42].dtr_IHandleEntity)(
            a1: v66,
            a2: &viewTarget,
            a3: a2);
          vHeadTarget.x = 5.0;
          vHeadTarget.y = 5.0;
          vHeadTarget.z = 5.0;
          mins.x = -5.0;
          mins.y = -5.0;
          mins.z = -5.0;
          NDebugOverlay::Box(
            origin: &viewTarget,
            &mins,
            maxs: &vHeadTarget,
            r: 0,
            g: 255,
            b: 0,
            a: 255,
            flDuration: 20.0);
          a2 = 1101004800;
          v67 = (const Vector *)((int (__thiscall *)(CAI_BaseActor *))this->EyePosition)(a1: this);
          NDebugOverlay::Line(
            origin: v67,
            target: &tmp1,
            r: (int)&viewTarget,
            g: 0,
            b: 255,
            noDepthTest: false,
            duration: COERCE_FLOAT(1));
          v68 = this->m_hLookTarget.m_Index;
          if ( v68 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v68].m_SerialNumber != HIWORD(v68) )
            v69 = nullptr;
          else
            v69 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v68].m_pEntity;
          if ( v68 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v68].m_SerialNumber != HIWORD(v68) )
            v70 = nullptr;
          else
            v70 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v68].m_pEntity;
          v71 = (const char *)v70[23].__vftable;
          if ( v71 == nullptr )
            v71 = locale;
          DebugName = CBaseEntity::GetDebugName(this: v69);
          v73 = UTIL_VarArgs(format: "%s (%s)", v71, DebugName);
          NDebugOverlay::Text(origin: &viewTarget, text: v73, bViewCheck: false, duration: 20.0);
        }
      }
    }
    this->OnNewLookTarget(this);
  }
  if ( !bFoundTarget && !this->ValidEyeTarget(this, a2: (const Vector *)&this->m_viewtarget) )
  {
    v74 = (const Vector *)((int (__thiscall *)(CAI_BaseActor *, Vector *, Vector *, Vector *))this->HeadDirection3D)(
                            a1: this,
                            a2: &tmp1,
                            a3: &right,
                            a4: &up);
    VectorVectors(forward: v74, right: (Vector *)a2, up: v106);
    v75 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: -1048576000,
            a3: 1098907648);
    RandomFloat = random->RandomFloat;
    vHeadTarget.x = up.x * v75;
    vHeadTarget.y = up.y * v75;
    vHeadTarget.z = v75 * up.z;
    FlexWeight = ((double (__thiscall *)(IUniformRandomStream *, int, int))RandomFloat)(
                   a1: random,
                   a2: -1040187392,
                   a3: 1107296256);
    HeadDirection3D = this->HeadDirection3D;
    mins.x = right.x * FlexWeight;
    mins.y = FlexWeight * right.y;
    mins.z = FlexWeight * right.z;
    v78 = (float *)HeadDirection3D(this, result: &v107);
    viewTarget.x = *v78 * 128.0;
    viewTarget.y = v78[1] * 128.0;
    EyePosition = this->EyePosition;
    viewTarget.z = v78[2] * 128.0;
    v80 = (float *)EyePosition(this, result: &v108);
    v81 = v80[1];
    v82 = v80[2];
    tmp1.x = (float)((float)(*v80 + viewTarget.x) + mins.x) + vHeadTarget.x;
    SetViewtarget = this->SetViewtarget;
    tmp1.y = (float)((float)(v81 + viewTarget.y) + mins.y) + vHeadTarget.y;
    tmp1.z = (float)((float)(v82 + viewTarget.z) + mins.z) + vHeadTarget.z;
    SetViewtarget(this, a2: &tmp1);
  }
  v84 = this->m_hLookTarget.m_Index;
  if ( v84 != -1 )
  {
    v85 = (unsigned __int16)v84;
    v86 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v84];
    v87 = HIWORD(v84);
    if ( v86->m_SerialNumber == v87 && v86->m_pEntity != nullptr )
    {
      v88 = v85;
      v63 = g_pEntityList->m_EntPtrArray[v88].m_SerialNumber == v87;
      v89 = &g_pEntityList->m_EntPtrArray[v88];
      if ( v63 )
        v90 = v89->m_pEntity;
      else
        v90 = nullptr;
      if ( ((int)v90[49].__vftable & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this: (CBaseEntity *)v90);
      v91 = this->m_hLookTarget.m_Index;
      v92 = *(float *)&v90[93].__vftable;
      *(_QWORD *)&viewTarget.x = *(_QWORD *)&v90[91].__vftable;
      viewTarget.z = v92;
      if ( v91 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v91].m_SerialNumber != HIWORD(v91) )
        v93 = nullptr;
      else
        v93 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v91].m_pEntity;
      GroundEntity = CBaseEntity::GetGroundEntity(this: v93);
      v95 = (float *)GroundEntity;
      if ( GroundEntity != nullptr && GroundEntity->m_MoveType.m_Value == 7 )
      {
        if ( (GroundEntity->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this: GroundEntity);
        v96 = viewTarget.x + v95[91];
        v97 = v95[92] + viewTarget.y;
        v98 = v95[93] + viewTarget.z;
      }
      else
      {
        v98 = viewTarget.z;
        v97 = viewTarget.y;
        v96 = viewTarget.x;
      }
      if ( vec3_origin.x != v96 || vec3_origin.y != v97 || vec3_origin.z != v98 )
      {
        v99 = this->m_viewtarget.m_Value.z;
        v100 = this->SetViewtarget;
        *(_QWORD *)&viewTarget.x = *(_QWORD *)&this->m_viewtarget.m_Value.x;
        viewTarget.x = (float)(v96 * flInterval) + viewTarget.x;
        viewTarget.y = viewTarget.y + (float)(v97 * flInterval);
        viewTarget.z = v99 + (float)(v98 * flInterval);
        v100(this, a2: &viewTarget);
      }
    }
  }
  if ( gpGlobals->curtime > this->m_flBlinktime )
  {
    v101 = this->m_blinktoggle.m_Value == 0;
    if ( this->m_blinktoggle.m_Value != v101 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x62Cu);
      }
      this->m_blinktoggle.m_Value = v101;
    }
    this->m_flBlinktime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                            a1: random,
                            a2: 1069547520,
                            a3: 1083179008)
                        + gpGlobals->curtime;
  }
  if ( ai_debug_looktargets.m_pParent != nullptr
    && ai_debug_looktargets.m_pParent->m_Value.m_nValue == 1
    && (this->m_debugOverlays & 0x1000) != 0 )
  {
    tmp1.x = 2.0;
    tmp1.y = 2.0;
    tmp1.z = 2.0;
    right.x = -2.0;
    right.y = -2.0;
    right.z = -2.0;
    NDebugOverlay::Box(
      origin: &this->m_viewtarget.m_Value,
      mins: &right,
      maxs: &tmp1,
      r: 0,
      g: 255,
      b: 0,
      a: 0,
      flDuration: 20.0);
    v103 = this->EyePosition(this, result: &v108);
    NDebugOverlay::Line(
      origin: v103,
      target: &this->m_viewtarget.m_Value,
      r: 0,
      g: 255,
      b: 0,
      noDepthTest: false,
      duration: 0.1);
  }
  if ( active.m_Memory.m_nGrowSize >= 0 && active.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: active.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103FA900
// Name: CAI_BaseActor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_BaseActor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_BaseActor>(__formal: nullptr);
  CAI_BaseActor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FA910
// Name: CAI_InterestTarget_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_InterestTarget_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_InterestTarget_t>(__formal: nullptr);
  CAI_InterestTarget_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100168E0
// Name: struct datamap_t __near * DataMapInit<class CAI_BaseActor>(class CAI_BaseActor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_BaseActor>()
{
  int v0; // eax

  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    nameHolder_3.m_pszBase = "CAI_BaseActor";
    nameHolder_3.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_3.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_3.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_3.m_Names.m_Size = 0;
    nameHolder_3.m_Names.m_pElements = nullptr;
    nameHolder_3.m_nLenBase = 13;
    atexit(func: DataMapInit_CAI_BaseActor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_BaseActor::m_DataMap.baseMap = &CAI_BaseNPC::m_DataMap;
  if ( (_S2_1 & 2) == 0 )
  {
    v0 = `CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::`local static guard';
    _S2_1 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::`local static guard' & 1) == 0 )
    {
      v0 = `CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::`local static guard' | 1;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::ops = (int)&CUtlVectorDataOps<CAI_InterestTarget,10>::`vftable';
    }
    dataDesc_3[13].fieldSize = 1;
    dataDesc_3[12].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::ops;
    dataDesc_3[12].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_3[12].td = 0;
    *(_QWORD *)&dataDesc_3[12].override_field = 0;
    *(_QWORD *)&dataDesc_3[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_3[12].flatOffset[1] = 0;
    dataDesc_3[13].fieldType = FIELD_CUSTOM;
    dataDesc_3[13].fieldName = "m_randomLookQueue";
    dataDesc_3[13].fieldOffset = 3856;
    dataDesc_3[13].flags = 2;
    dataDesc_3[13].externalName = nullptr;
    if ( (v0 & 1) == 0 )
    {
      v0 |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::`local static guard' = v0;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::ops = (int)&CUtlVectorDataOps<CAI_InterestTarget,10>::`vftable';
    }
    dataDesc_3[14].fieldSize = 1;
    dataDesc_3[13].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::ops;
    dataDesc_3[13].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_3[13].td = 0;
    *(_QWORD *)&dataDesc_3[13].override_field = 0;
    *(_QWORD *)&dataDesc_3[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_3[13].flatOffset[1] = 0;
    dataDesc_3[14].fieldType = FIELD_CUSTOM;
    dataDesc_3[14].fieldName = "m_syntheticLookQueue";
    dataDesc_3[14].fieldOffset = 3836;
    dataDesc_3[14].flags = 2;
    dataDesc_3[14].externalName = nullptr;
    if ( (v0 & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::`local static guard' = v0 | 1;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::ops = (int)&CUtlVectorDataOps<CAI_InterestTarget,10>::`vftable';
    }
    dataDesc_3[14].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::ops;
    dataDesc_3[16].fieldSize = 1;
    *(_QWORD *)dataDesc_3[15].flatOffset = 0;
    dataDesc_3[15].fieldType = FIELD_TIME;
    dataDesc_3[15].fieldSize = 1;
    dataDesc_3[16].flags = 2;
    dataDesc_3[18].fieldType = FIELD_TIME;
    *(_QWORD *)dataDesc_3[16].flatOffset = 0;
    dataDesc_3[15].flags = 2;
    dataDesc_3[17].fieldSize = 1;
    dataDesc_3[18].fieldSize = 1;
    *(_QWORD *)&dataDesc_3[14].td = 0;
    *(_QWORD *)&dataDesc_3[14].override_field = 0;
    *(_QWORD *)&dataDesc_3[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_3[14].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_3[17].flatOffset = 0;
    dataDesc_3[14].inputFunc = nullptr;
    dataDesc_3[15].fieldName = "m_flNextRandomLookTime";
    dataDesc_3[15].fieldOffset = 3876;
    dataDesc_3[15].externalName = nullptr;
    dataDesc_3[15].pSaveRestoreOps = nullptr;
    dataDesc_3[15].inputFunc = nullptr;
    dataDesc_3[15].td = nullptr;
    dataDesc_3[15].fieldSizeInBytes = 4;
    dataDesc_3[15].override_field = nullptr;
    dataDesc_3[15].override_count = 0;
    dataDesc_3[15].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[15].flatGroup = 0;
    dataDesc_3[16].fieldType = FIELD_STRING;
    dataDesc_3[16].fieldName = "m_iszExpressionScene";
    dataDesc_3[16].fieldOffset = 3880;
    dataDesc_3[16].externalName = nullptr;
    dataDesc_3[16].pSaveRestoreOps = nullptr;
    dataDesc_3[16].inputFunc = nullptr;
    dataDesc_3[16].td = nullptr;
    dataDesc_3[16].fieldSizeInBytes = 4;
    dataDesc_3[16].override_field = nullptr;
    dataDesc_3[16].override_count = 0;
    dataDesc_3[16].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[16].flatGroup = 0;
    dataDesc_3[17].fieldType = FIELD_EHANDLE;
    dataDesc_3[17].fieldName = "m_hExpressionSceneEnt";
    dataDesc_3[17].fieldOffset = 3884;
    dataDesc_3[17].flags = 2;
    dataDesc_3[17].externalName = nullptr;
    dataDesc_3[17].pSaveRestoreOps = nullptr;
    dataDesc_3[17].inputFunc = nullptr;
    dataDesc_3[17].td = nullptr;
    dataDesc_3[17].fieldSizeInBytes = 4;
    dataDesc_3[17].override_field = nullptr;
    dataDesc_3[17].override_count = 0;
    dataDesc_3[17].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[17].flatGroup = 0;
    dataDesc_3[18].fieldName = "m_flNextRandomExpressionTime";
    dataDesc_3[18].fieldOffset = 3888;
    dataDesc_3[18].flags = 2;
    dataDesc_3[18].externalName = nullptr;
    dataDesc_3[18].pSaveRestoreOps = nullptr;
    dataDesc_3[18].inputFunc = nullptr;
    dataDesc_3[18].td = nullptr;
    dataDesc_3[18].fieldSizeInBytes = 4;
    dataDesc_3[18].override_field = nullptr;
    dataDesc_3[18].override_count = 0;
    dataDesc_3[18].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_3[18].flatOffset = 0;
    dataDesc_3[19].fieldSize = 1;
    dataDesc_3[19].flags = 2;
    dataDesc_3[20].fieldSize = 1;
    dataDesc_3[20].flags = 2;
    dataDesc_3[21].fieldSize = 1;
    dataDesc_3[21].flags = 2;
    *(_QWORD *)dataDesc_3[19].flatOffset = 0;
    dataDesc_3[22].fieldSize = 1;
    *(_QWORD *)dataDesc_3[20].flatOffset = 0;
    dataDesc_3[22].flags = 2;
    dataDesc_3[23].fieldSize = 1;
    *(_QWORD *)dataDesc_3[21].flatOffset = 0;
    *(_DWORD *)&dataDesc_3[18].flatGroup = 0;
    dataDesc_3[19].fieldType = FIELD_STRING;
    dataDesc_3[19].fieldName = "m_iszIdleExpression";
    dataDesc_3[19].fieldOffset = 3896;
    dataDesc_3[19].externalName = nullptr;
    dataDesc_3[19].pSaveRestoreOps = nullptr;
    dataDesc_3[19].inputFunc = nullptr;
    dataDesc_3[19].td = nullptr;
    dataDesc_3[19].fieldSizeInBytes = 4;
    dataDesc_3[19].override_field = nullptr;
    dataDesc_3[19].override_count = 0;
    dataDesc_3[19].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[19].flatGroup = 0;
    dataDesc_3[20].fieldType = FIELD_STRING;
    dataDesc_3[20].fieldName = "m_iszAlertExpression";
    dataDesc_3[20].fieldOffset = 3900;
    dataDesc_3[20].externalName = nullptr;
    dataDesc_3[20].pSaveRestoreOps = nullptr;
    dataDesc_3[20].inputFunc = nullptr;
    dataDesc_3[20].td = nullptr;
    dataDesc_3[20].fieldSizeInBytes = 4;
    dataDesc_3[20].override_field = nullptr;
    dataDesc_3[20].override_count = 0;
    dataDesc_3[20].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[20].flatGroup = 0;
    dataDesc_3[21].fieldType = FIELD_STRING;
    dataDesc_3[21].fieldName = "m_iszCombatExpression";
    dataDesc_3[21].fieldOffset = 3904;
    dataDesc_3[21].externalName = nullptr;
    dataDesc_3[21].pSaveRestoreOps = nullptr;
    dataDesc_3[21].inputFunc = nullptr;
    dataDesc_3[21].td = nullptr;
    dataDesc_3[21].fieldSizeInBytes = 4;
    dataDesc_3[21].override_field = nullptr;
    dataDesc_3[21].override_count = 0;
    dataDesc_3[21].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[21].flatGroup = 0;
    dataDesc_3[22].fieldType = FIELD_STRING;
    dataDesc_3[22].fieldName = "m_iszDeathExpression";
    dataDesc_3[22].fieldOffset = 3908;
    dataDesc_3[22].externalName = nullptr;
    dataDesc_3[22].pSaveRestoreOps = nullptr;
    dataDesc_3[22].inputFunc = nullptr;
    dataDesc_3[22].td = nullptr;
    dataDesc_3[22].fieldSizeInBytes = 4;
    dataDesc_3[22].override_field = nullptr;
    dataDesc_3[22].override_count = 0;
    dataDesc_3[22].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_3[22].flatOffset = 0;
    *(_DWORD *)&dataDesc_3[22].flatGroup = 0;
    dataDesc_3[23].fieldType = FIELD_INTEGER;
    dataDesc_3[23].fieldName = "m_ParameterBodyYaw";
    dataDesc_3[23].fieldOffset = 3924;
    dataDesc_3[23].flags = 2;
    dataDesc_3[24].fieldSize = 1;
    dataDesc_3[24].flags = 2;
    dataDesc_3[25].fieldSize = 1;
    dataDesc_3[25].flags = 2;
    dataDesc_3[26].fieldSize = 1;
    *(_QWORD *)dataDesc_3[23].flatOffset = 0;
    *(_QWORD *)dataDesc_3[24].flatOffset = 0;
    dataDesc_3[26].flags = 2;
    *(_QWORD *)dataDesc_3[25].flatOffset = 0;
    dataDesc_3[27].fieldSize = 1;
    *(_QWORD *)dataDesc_3[26].flatOffset = 0;
    dataDesc_3[23].externalName = nullptr;
    dataDesc_3[23].pSaveRestoreOps = nullptr;
    dataDesc_3[23].inputFunc = nullptr;
    dataDesc_3[23].td = nullptr;
    dataDesc_3[23].fieldSizeInBytes = 4;
    dataDesc_3[23].override_field = nullptr;
    dataDesc_3[23].override_count = 0;
    dataDesc_3[23].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[23].flatGroup = 0;
    dataDesc_3[24].fieldType = FIELD_INTEGER;
    dataDesc_3[24].fieldName = "m_ParameterSpineYaw";
    dataDesc_3[24].fieldOffset = 3928;
    dataDesc_3[24].externalName = nullptr;
    dataDesc_3[24].pSaveRestoreOps = nullptr;
    dataDesc_3[24].inputFunc = nullptr;
    dataDesc_3[24].td = nullptr;
    dataDesc_3[24].fieldSizeInBytes = 4;
    dataDesc_3[24].override_field = nullptr;
    dataDesc_3[24].override_count = 0;
    dataDesc_3[24].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[24].flatGroup = 0;
    dataDesc_3[25].fieldType = FIELD_INTEGER;
    dataDesc_3[25].fieldName = "m_ParameterNeckTrans";
    dataDesc_3[25].fieldOffset = 3932;
    dataDesc_3[25].externalName = nullptr;
    dataDesc_3[25].pSaveRestoreOps = nullptr;
    dataDesc_3[25].inputFunc = nullptr;
    dataDesc_3[25].td = nullptr;
    dataDesc_3[25].fieldSizeInBytes = 4;
    dataDesc_3[25].override_field = nullptr;
    dataDesc_3[25].override_count = 0;
    dataDesc_3[25].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[25].flatGroup = 0;
    dataDesc_3[26].fieldType = FIELD_INTEGER;
    dataDesc_3[26].fieldName = "m_ParameterHeadYaw";
    dataDesc_3[26].fieldOffset = 3936;
    dataDesc_3[26].externalName = nullptr;
    dataDesc_3[26].pSaveRestoreOps = nullptr;
    dataDesc_3[26].inputFunc = nullptr;
    dataDesc_3[26].td = nullptr;
    dataDesc_3[26].fieldSizeInBytes = 4;
    dataDesc_3[26].override_field = nullptr;
    dataDesc_3[26].override_count = 0;
    dataDesc_3[26].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[26].flatGroup = 0;
    dataDesc_3[27].fieldType = FIELD_INTEGER;
    dataDesc_3[27].fieldName = "m_ParameterHeadPitch";
    dataDesc_3[27].fieldOffset = 3940;
    dataDesc_3[27].flags = 2;
    dataDesc_3[27].externalName = nullptr;
    dataDesc_3[27].pSaveRestoreOps = nullptr;
    dataDesc_3[27].inputFunc = nullptr;
    dataDesc_3[27].td = nullptr;
    dataDesc_3[27].fieldSizeInBytes = 4;
    dataDesc_3[27].override_field = nullptr;
    dataDesc_3[27].override_count = 0;
    dataDesc_3[27].fieldTolerance = 0.0;
    dataDesc_3[28].fieldSize = 1;
    dataDesc_3[28].flags = 2;
    dataDesc_3[29].fieldSize = 1;
    dataDesc_3[29].flags = 2;
    dataDesc_3[30].fieldSize = 1;
    dataDesc_3[30].flags = 2;
    *(_QWORD *)dataDesc_3[27].flatOffset = 0;
    dataDesc_3[31].fieldSize = 1;
    *(_QWORD *)dataDesc_3[28].flatOffset = 0;
    dataDesc_3[31].flags = 2;
    *(_QWORD *)dataDesc_3[29].flatOffset = 0;
    dataDesc_3[32].fieldSize = 1;
    *(_QWORD *)dataDesc_3[30].flatOffset = 0;
    *(_DWORD *)&dataDesc_3[27].flatGroup = 0;
    dataDesc_3[28].fieldType = FIELD_INTEGER;
    dataDesc_3[28].fieldName = "m_ParameterHeadRoll";
    dataDesc_3[28].fieldOffset = 3944;
    dataDesc_3[28].externalName = nullptr;
    dataDesc_3[28].pSaveRestoreOps = nullptr;
    dataDesc_3[28].inputFunc = nullptr;
    dataDesc_3[28].td = nullptr;
    dataDesc_3[28].fieldSizeInBytes = 4;
    dataDesc_3[28].override_field = nullptr;
    dataDesc_3[28].override_count = 0;
    dataDesc_3[28].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[28].flatGroup = 0;
    dataDesc_3[29].fieldType = FIELD_INTEGER;
    dataDesc_3[29].fieldName = "m_FlexweightBodyRightLeft";
    dataDesc_3[29].fieldOffset = 3948;
    dataDesc_3[29].externalName = nullptr;
    dataDesc_3[29].pSaveRestoreOps = nullptr;
    dataDesc_3[29].inputFunc = nullptr;
    dataDesc_3[29].td = nullptr;
    dataDesc_3[29].fieldSizeInBytes = 4;
    dataDesc_3[29].override_field = nullptr;
    dataDesc_3[29].override_count = 0;
    dataDesc_3[29].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[29].flatGroup = 0;
    dataDesc_3[30].fieldType = FIELD_INTEGER;
    dataDesc_3[30].fieldName = "m_FlexweightChestRightLeft";
    dataDesc_3[30].fieldOffset = 3952;
    dataDesc_3[30].externalName = nullptr;
    dataDesc_3[30].pSaveRestoreOps = nullptr;
    dataDesc_3[30].inputFunc = nullptr;
    dataDesc_3[30].td = nullptr;
    dataDesc_3[30].fieldSizeInBytes = 4;
    dataDesc_3[30].override_field = nullptr;
    dataDesc_3[30].override_count = 0;
    dataDesc_3[30].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[30].flatGroup = 0;
    dataDesc_3[31].fieldType = FIELD_INTEGER;
    dataDesc_3[31].fieldName = "m_FlexweightHeadForwardBack";
    dataDesc_3[31].fieldOffset = 3956;
    dataDesc_3[31].externalName = nullptr;
    dataDesc_3[31].pSaveRestoreOps = nullptr;
    dataDesc_3[31].inputFunc = nullptr;
    dataDesc_3[31].td = nullptr;
    dataDesc_3[31].fieldSizeInBytes = 4;
    dataDesc_3[31].override_field = nullptr;
    dataDesc_3[31].override_count = 0;
    dataDesc_3[31].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_3[31].flatOffset = 0;
    *(_DWORD *)&dataDesc_3[31].flatGroup = 0;
    dataDesc_3[32].fieldType = FIELD_INTEGER;
    dataDesc_3[32].fieldName = "m_FlexweightHeadRightLeft";
    dataDesc_3[32].fieldOffset = 3960;
    dataDesc_3[32].flags = 2;
    dataDesc_3[33].fieldSize = 1;
    dataDesc_3[33].flags = 2;
    dataDesc_3[34].fieldSize = 1;
    dataDesc_3[34].flags = 2;
    dataDesc_3[35].fieldSize = 1;
    *(_QWORD *)dataDesc_3[32].flatOffset = 0;
    *(_QWORD *)dataDesc_3[33].flatOffset = 0;
    dataDesc_3[35].flags = 2;
    *(_QWORD *)dataDesc_3[34].flatOffset = 0;
    dataDesc_3[36].fieldSize = 1;
    *(_QWORD *)dataDesc_3[35].flatOffset = 0;
    dataDesc_3[32].externalName = nullptr;
    dataDesc_3[32].pSaveRestoreOps = nullptr;
    dataDesc_3[32].inputFunc = nullptr;
    dataDesc_3[32].td = nullptr;
    dataDesc_3[32].fieldSizeInBytes = 4;
    dataDesc_3[32].override_field = nullptr;
    dataDesc_3[32].override_count = 0;
    dataDesc_3[32].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[32].flatGroup = 0;
    dataDesc_3[33].fieldType = FIELD_INTEGER;
    dataDesc_3[33].fieldName = "m_FlexweightHeadUpDown";
    dataDesc_3[33].fieldOffset = 3964;
    dataDesc_3[33].externalName = nullptr;
    dataDesc_3[33].pSaveRestoreOps = nullptr;
    dataDesc_3[33].inputFunc = nullptr;
    dataDesc_3[33].td = nullptr;
    dataDesc_3[33].fieldSizeInBytes = 4;
    dataDesc_3[33].override_field = nullptr;
    dataDesc_3[33].override_count = 0;
    dataDesc_3[33].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[33].flatGroup = 0;
    dataDesc_3[34].fieldType = FIELD_INTEGER;
    dataDesc_3[34].fieldName = "m_FlexweightHeadTilt";
    dataDesc_3[34].fieldOffset = 3968;
    dataDesc_3[34].externalName = nullptr;
    dataDesc_3[34].pSaveRestoreOps = nullptr;
    dataDesc_3[34].inputFunc = nullptr;
    dataDesc_3[34].td = nullptr;
    dataDesc_3[34].fieldSizeInBytes = 4;
    dataDesc_3[34].override_field = nullptr;
    dataDesc_3[34].override_count = 0;
    dataDesc_3[34].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[34].flatGroup = 0;
    dataDesc_3[35].fieldType = FIELD_INTEGER;
    dataDesc_3[35].fieldName = "m_ParameterGestureHeight";
    dataDesc_3[35].fieldOffset = 3972;
    dataDesc_3[35].externalName = nullptr;
    dataDesc_3[35].pSaveRestoreOps = nullptr;
    dataDesc_3[35].inputFunc = nullptr;
    dataDesc_3[35].td = nullptr;
    dataDesc_3[35].fieldSizeInBytes = 4;
    dataDesc_3[35].override_field = nullptr;
    dataDesc_3[35].override_count = 0;
    dataDesc_3[35].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[35].flatGroup = 0;
    dataDesc_3[36].fieldType = FIELD_INTEGER;
    dataDesc_3[36].fieldName = "m_ParameterGestureWidth";
    dataDesc_3[36].fieldOffset = 3976;
    dataDesc_3[36].flags = 2;
    dataDesc_3[36].externalName = nullptr;
    dataDesc_3[36].pSaveRestoreOps = nullptr;
    dataDesc_3[36].inputFunc = nullptr;
    dataDesc_3[36].td = nullptr;
    dataDesc_3[36].fieldSizeInBytes = 4;
    dataDesc_3[36].override_field = nullptr;
    dataDesc_3[36].override_count = 0;
    dataDesc_3[36].fieldTolerance = 0.0;
    dataDesc_3[37].fieldType = FIELD_INTEGER;
    dataDesc_3[38].fieldType = FIELD_INTEGER;
    dataDesc_3[38].fieldSize = 1;
    dataDesc_3[38].flags = 2;
    dataDesc_3[39].fieldSize = 1;
    dataDesc_3[39].flags = 2;
    *(_QWORD *)dataDesc_3[36].flatOffset = 0;
    dataDesc_3[40].fieldSize = 1;
    *(_QWORD *)dataDesc_3[37].flatOffset = 0;
    dataDesc_3[40].flags = 2;
    *(_QWORD *)dataDesc_3[38].flatOffset = 0;
    dataDesc_3[37].fieldSize = 1;
    dataDesc_3[41].fieldSize = 64;
    *(_QWORD *)dataDesc_3[39].flatOffset = 0;
    *(_DWORD *)&dataDesc_3[36].flatGroup = 0;
    dataDesc_3[37].fieldName = "m_FlexweightGestureUpDown";
    dataDesc_3[37].fieldOffset = 3980;
    dataDesc_3[37].flags = 2;
    dataDesc_3[37].externalName = nullptr;
    dataDesc_3[37].pSaveRestoreOps = nullptr;
    dataDesc_3[37].inputFunc = nullptr;
    dataDesc_3[37].td = nullptr;
    dataDesc_3[37].fieldSizeInBytes = 4;
    dataDesc_3[37].override_field = nullptr;
    dataDesc_3[37].override_count = 0;
    dataDesc_3[37].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[37].flatGroup = 0;
    dataDesc_3[38].fieldName = "m_FlexweightGestureRightLeft";
    dataDesc_3[38].fieldOffset = 3984;
    dataDesc_3[38].externalName = nullptr;
    dataDesc_3[38].pSaveRestoreOps = nullptr;
    dataDesc_3[38].inputFunc = nullptr;
    dataDesc_3[38].td = nullptr;
    dataDesc_3[38].fieldSizeInBytes = 4;
    dataDesc_3[38].override_field = nullptr;
    dataDesc_3[38].override_count = 0;
    dataDesc_3[38].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[38].flatGroup = 0;
    dataDesc_3[39].fieldType = FIELD_FLOAT;
    dataDesc_3[39].fieldName = "m_flAccumYawDelta";
    dataDesc_3[39].fieldOffset = 3724;
    dataDesc_3[39].externalName = nullptr;
    dataDesc_3[39].pSaveRestoreOps = nullptr;
    dataDesc_3[39].inputFunc = nullptr;
    dataDesc_3[39].td = nullptr;
    dataDesc_3[39].fieldSizeInBytes = 4;
    dataDesc_3[39].override_field = nullptr;
    dataDesc_3[39].override_count = 0;
    dataDesc_3[39].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_3[39].flatGroup = 0;
    dataDesc_3[40].fieldType = FIELD_FLOAT;
    dataDesc_3[40].fieldName = "m_flAccumYawScale";
    dataDesc_3[40].fieldOffset = 3728;
    dataDesc_3[40].externalName = nullptr;
    dataDesc_3[40].pSaveRestoreOps = nullptr;
    dataDesc_3[40].inputFunc = nullptr;
    dataDesc_3[40].td = nullptr;
    dataDesc_3[40].fieldSizeInBytes = 4;
    dataDesc_3[40].override_field = nullptr;
    dataDesc_3[40].override_count = 0;
    dataDesc_3[40].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_3[40].flatOffset = 0;
    *(_DWORD *)&dataDesc_3[40].flatGroup = 0;
    dataDesc_3[41].fieldType = FIELD_FLOAT;
    dataDesc_3[41].fieldName = "m_flextarget";
    dataDesc_3[41].fieldOffset = 3988;
    dataDesc_3[41].flags = 2;
    dataDesc_3[42].fieldSize = 1;
    dataDesc_3[42].flags = 6;
    dataDesc_3[43].fieldSize = 1;
    dataDesc_3[41].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_3[41].flatOffset = 0;
    dataDesc_3[42].fieldTolerance = 0.0;
    dataDesc_3[43].fieldTolerance = 0.0;
    dataDesc_3[44].fieldTolerance = 0.0;
    dataDesc_3[43].flags = 6;
    dataDesc_3[43].fieldSizeInBytes = 4;
    *(_QWORD *)dataDesc_3[42].flatOffset = 0;
    *(_QWORD *)dataDesc_3[44].flatOffset = 0;
    dataDesc_3[41].externalName = nullptr;
    dataDesc_3[41].pSaveRestoreOps = nullptr;
    dataDesc_3[41].inputFunc = nullptr;
    dataDesc_3[41].td = nullptr;
    dataDesc_3[41].fieldSizeInBytes = 256;
    dataDesc_3[41].override_field = nullptr;
    dataDesc_3[41].override_count = 0;
    *(_DWORD *)&dataDesc_3[41].flatGroup = 0;
    dataDesc_3[42].fieldType = FIELD_BOOLEAN;
    dataDesc_3[42].fieldName = "m_bDontUseSemaphore";
    dataDesc_3[42].fieldOffset = 4244;
    dataDesc_3[42].externalName = "DontUseSpeechSemaphore";
    dataDesc_3[42].pSaveRestoreOps = nullptr;
    dataDesc_3[42].inputFunc = nullptr;
    dataDesc_3[42].td = nullptr;
    dataDesc_3[42].fieldSizeInBytes = 1;
    dataDesc_3[42].override_field = nullptr;
    dataDesc_3[42].override_count = 0;
    *(_DWORD *)&dataDesc_3[42].flatGroup = 0;
    dataDesc_3[43].fieldType = FIELD_STRING;
    dataDesc_3[43].fieldName = "m_iszExpressionOverride";
    dataDesc_3[43].fieldOffset = 3892;
    dataDesc_3[43].externalName = "ExpressionOverride";
    dataDesc_3[43].pSaveRestoreOps = nullptr;
    dataDesc_3[43].inputFunc = nullptr;
    dataDesc_3[43].td = nullptr;
    dataDesc_3[43].override_field = nullptr;
    dataDesc_3[43].override_count = 0;
    *(_QWORD *)dataDesc_3[43].flatOffset = 0;
    *(_DWORD *)&dataDesc_3[43].flatGroup = 0;
    dataDesc_3[44].fieldType = FIELD_EMBEDDED;
    dataDesc_3[44].fieldName = "m_pExpresser";
    dataDesc_3[44].fieldOffset = 4248;
    dataDesc_3[44].fieldSize = 1;
    dataDesc_3[44].flags = 66;
    dataDesc_3[44].externalName = nullptr;
    dataDesc_3[44].pSaveRestoreOps = nullptr;
    dataDesc_3[44].inputFunc = nullptr;
    dataDesc_3[44].td = &CAI_Expresser::m_DataMap;
    dataDesc_3[44].fieldSizeInBytes = 68;
    dataDesc_3[44].override_field = nullptr;
    dataDesc_3[44].override_count = 0;
    *(_DWORD *)&dataDesc_3[44].flatGroup = 0;
    dataDesc_3[45].fieldType = FIELD_STRING;
    dataDesc_3[45].fieldName = "InputSetExpressionOverride";
    dataDesc_3[45].fieldOffset = 0;
    *(_DWORD *)&dataDesc_3[45].fieldSize = 524289;
    dataDesc_3[45].externalName = "SetExpressionOverride";
    dataDesc_3[45].pSaveRestoreOps = nullptr;
    dataDesc_3[45].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseActor::InputSetExpressionOverride;
    *(_QWORD *)&dataDesc_3[45].td = 0;
    *(_QWORD *)&dataDesc_3[45].override_field = 0;
    *(_QWORD *)&dataDesc_3[45].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_3[45].flatOffset[1] = 0;
  }
  CAI_BaseActor::m_DataMap.dataNumFields = 45;
  CAI_BaseActor::m_DataMap.dataDesc = &dataDesc_3[1];
  return &CAI_BaseActor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10017860
// Name: struct datamap_t __near * DataMapInit<class CAI_InterestTarget_t>(class CAI_InterestTarget_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_InterestTarget_t>()
{
  if ( (_S3_0 & 1) == 0 )
  {
    _S3_0 |= 1u;
    nameHolder_4.m_pszBase = "CAI_InterestTarget_t";
    nameHolder_4.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_4.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_4.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_4.m_Names.m_Size = 0;
    nameHolder_4.m_Names.m_pElements = nullptr;
    nameHolder_4.m_nLenBase = 20;
    atexit(func: DataMapInit_CAI_InterestTarget_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_InterestTarget_t::m_DataMap.baseMap = nullptr;
  CAI_InterestTarget_t::m_DataMap.dataNumFields = 7;
  CAI_InterestTarget_t::m_DataMap.dataDesc = &dataDesc_4[1];
  return &CAI_InterestTarget_t::m_DataMap;
}
