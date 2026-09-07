// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/props.cpp
// Functions: 343
// ============================================================

#include "game\server\props.h"

//------------------------------------------------------------------------------
// Address: 0x10101E60
// Name: void SendProxy_UnmodifiedQAngles(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_UnmodifiedQAngles(
        const SendProp *pProp,
        const void *pStruct,
        $5FB8512C96CD1B8867E59BA5A9F6C5D6 *pData,
        DVariant *pOut)
{
  pOut->___u0 = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x1018E5A0
// Name: public: void CPhysicsProp::InputWake(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::InputWake(CPhysicsCannister *this, inputdata_t *data)
{
  IPhysicsObject *m_pPhysicsObject; // ecx

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->Wake(this: m_pPhysicsObject);
}

//------------------------------------------------------------------------------
// Address: 0x1019CC00
// Name: public: void CDynamicProp::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::InputTurnOff(CBaseEntity *this, inputdata_t *inputdata)
{
  CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x101DD750
// Name: private: void CBreakableProp::InputEnablePuntSound(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::InputEnablePuntSound(CBreakableProp *this, inputdata_t *inputdata)
{
  this->m_bUsePuntSound = true;
}

//------------------------------------------------------------------------------
// Address: 0x101DD760
// Name: private: void CBreakableProp::InputDisablePuntSound(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::InputDisablePuntSound(CBreakableProp *this, inputdata_t *inputdata)
{
  this->m_bUsePuntSound = false;
}

//------------------------------------------------------------------------------
// Address: 0x101DD770
// Name: public: int CBaseProp::ParsePropData(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseProp::ParsePropData(CBaseProp *this)
{
  IVModelInfo_vtbl *v1; // esi
  model_t *Model; // eax
  KeyValues *v4; // esi
  int v6; // eax
  KeyValues *Key; // eax
  IBreakableWithPropData *v8; // eax
  KeyValues *v9; // [esp-8h] [ebp-10h]

  v1 = modelinfo->__vftable;
  Model = CBaseEntity::GetModel(this);
  v4 = v1->GetModelKeyValues(this: modelinfo, a2: Model);
  if ( v4 == nullptr )
    return 2;
  if ( (_S2_189 & 1) == 0 )
  {
    _S2_189 |= 1u;
    v6 = _KeyValuesSystem();
    keyPropData = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v6 + 12))(a1: v6, a2: "prop_data", a3: 1);
  }
  Key = KeyValues::FindKey(this: v4, keySymbol: keyPropData);
  if ( Key == nullptr )
    return 2;
  v9 = Key;
  v8 = (IBreakableWithPropData *)__RTDynamicCast(
                                   inptr: this,
                                   VfDelta: 0,
                                   SrcType: &CBaseProp `RTTI Type Descriptor',
                                   TargetType: &IBreakableWithPropData `RTTI Type Descriptor',
                                   isReference: 0);
  return CPropData::ParsePropFromKV(
           this: &g_PropDataSystem,
           pProp: this,
           pBreakableInterface: v8,
           pSection: v9,
           pInteractionSection: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101DD810
// Name: public: virtual class ServerClass __near * CBreakableProp::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBreakableProp::GetServerClass(CBreakableProp *this)
{
  return &g_CBreakableProp_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101DD820
// Name: public: virtual struct datamap_t __near * CBreakableProp::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBreakableProp::GetDataDescMap(CBreakableProp *this)
{
  return &CBreakableProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DD830
// Name: public: virtual CBreakableProp::~CBreakableProp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::~CBreakableProp(CBreakableProp *this)
{
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysCannonPullAnimFinished);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysCannonAnimatePostStarted);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysCannonAnimatePullStarted);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysCannonAnimatePreStarted);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysCannonDetach);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTakeDamage);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnHealthChanged);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnBreak);
  CBaseAnimating::~CBaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DD8A0
// Name: private: void CBreakableProp::RampToDefaultFadeScale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::RampToDefaultFadeScale(CBreakableProp *this)
{
  float flFadeScale; // [esp+4h] [ebp-Ch]
  float m_flDefaultFadeScale; // [esp+Ch] [ebp-4h]

  flFadeScale = CBaseEntity::GetGlobalFadeScale(this) + gpGlobals->interval_per_tick * this->m_flDefaultFadeScale * 0.5;
  CBaseEntity::SetGlobalFadeScale(this, flFadeScale);
  m_flDefaultFadeScale = this->m_flDefaultFadeScale;
  if ( CBaseEntity::GetGlobalFadeScale(this) < m_flDefaultFadeScale )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CBreakableProp::RampToDefaultFadeScale,
      thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime,
      szContext: s_pFadeScaleThink);
  }
  else
  {
    CBaseEntity::SetGlobalFadeScale(this, flFadeScale: m_flDefaultFadeScale);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: gpGlobals->curtime, szContext: s_pFadeScaleThink);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD950
// Name: public: virtual void CBreakableProp::PlayPuntSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::PlayPuntSound(CBreakableProp *this)
{
  const char *pszValue; // eax

  if ( this->m_bUsePuntSound )
  {
    pszValue = this->m_iszPuntSound.pszValue;
    if ( pszValue != nullptr )
      CBaseEntity::EmitSound(this, soundname: pszValue, soundtime: 0.0, duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD980
// Name: public: virtual struct datamap_t __near * CDynamicProp::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CDynamicProp::GetDataDescMap(CDynamicProp *this)
{
  return &CDynamicProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DD990
// Name: public: virtual class ServerClass __near * CDynamicProp::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CDynamicProp::GetServerClass(CDynamicProp *this)
{
  return &g_CDynamicProp_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101DD9A0
// Name: public: void CDynamicProp::CreateBoneFollowers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::CreateBoneFollowers(CDynamicProp *this)
{
  CBoneFollowerManager *p_m_BoneFollowerManager; // ebx
  IVModelInfo_vtbl *v3; // esi
  model_t *Model; // eax
  KeyValues *v5; // eax
  KeyValues *Key; // eax
  KeyValues *i; // esi
  const char *String; // eax
  IVModelInfo_vtbl *v9; // esi
  int v10; // eax
  vcollide_t *v11; // eax

  p_m_BoneFollowerManager = &this->m_BoneFollowerManager;
  if ( this->m_BoneFollowerManager.m_iNumBones == 0 )
  {
    v3 = modelinfo->__vftable;
    Model = CBaseEntity::GetModel(this);
    v5 = v3->GetModelKeyValues(this: modelinfo, a2: Model);
    if ( v5 != nullptr )
    {
      Key = KeyValues::FindKey(this: v5, keyName: "bone_followers", bCreate: false);
      if ( Key != nullptr )
      {
        for ( i = KeyValues::GetFirstSubKey(this: Key); i != nullptr; i = KeyValues::GetNextKey(this: i) )
        {
          String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
          CBoneFollowerManager::AddBoneFollower(
            this: p_m_BoneFollowerManager,
            pParentEntity: this,
            pFollowerBoneName: String,
            pSolid: nullptr);
        }
      }
    }
    if ( p_m_BoneFollowerManager->m_iNumBones == 0 )
    {
      v9 = modelinfo->__vftable;
      v10 = this->GetModelIndex(this);
      v11 = v9->GetVCollide(this: modelinfo, a2: v10);
      if ( v11 != nullptr && (*(_WORD *)v11 & 0x7FFFu) > 1 )
        CreateBoneFollowersFromRagdoll(pEntity: this, pManager: p_m_BoneFollowerManager, pCollide: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DDA70
// Name: public: virtual void CDynamicProp::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::UpdateOnRemove(CDynamicProp *this)
{
  CBoneFollowerManager::DestroyBoneFollowers(this: &this->m_BoneFollowerManager);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DDAB0
// Name: public: void CDynamicProp::InputFadeAndKill(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDynamicProp::InputFadeAndKill(CDynamicProp *this, inputdata_t *inputdata)
{
  CBaseEntity::SUB_StartFadeOutInstant(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DDAC0
// Name: public: virtual struct datamap_t __near * COrnamentProp::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall COrnamentProp::GetDataDescMap(COrnamentProp *this)
{
  return &COrnamentProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DDAD0
// Name: public: virtual struct datamap_t __near * CPhysicsProp::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysicsProp::GetDataDescMap(CPhysicsProp *this)
{
  return &CPhysicsProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DDAE0
// Name: public: virtual class ServerClass __near * CPhysicsProp::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPhysicsProp::GetServerClass(CPhysicsProp *this)
{
  return &g_CPhysicsProp_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101DDAF0
// Name: private: void CPhysicsProp::ComputeEnablingImpulse(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::ComputeEnablingImpulse(CPhysicsProp *this, int index, gamevcollisionevent_t *pEvent)
{
  BOOL v4; // edi
  IPhysicsObject *v5; // esi
  float *v6; // eax
  float v7; // xmm2_4
  float z; // ecx
  __int64 v9; // xmm0_8
  float *v10; // edi
  IPhysicsObject *v11; // ecx
  Vector vecForce; // [esp+Ch] [ebp-54h] BYREF
  Vector vecTorque; // [esp+18h] [ebp-48h] BYREF
  Vector vecContactPoint; // [esp+24h] [ebp-3Ch] BYREF
  Vector vecLocalContactVelocity; // [esp+30h] [ebp-30h] BYREF
  Vector vecAngularVelocity; // [esp+3Ch] [ebp-24h] BYREF
  Vector vecLocalContactPoint; // [esp+48h] [ebp-18h] BYREF
  Vector vecContactVelocity; // [esp+54h] [ebp-Ch] BYREF
  float pEventa; // [esp+6Ch] [ebp+Ch]

  pEvent->pInternalData->GetContactPoint(this: pEvent->pInternalData, a2: &vecContactPoint);
  v4 = index == 0;
  v5 = pEvent->pObjects[v4];
  v5->WorldToLocal(this: v5, a2: &vecLocalContactPoint, a3: &vecContactPoint);
  v6 = (float *)v5->GetMassCenterLocalSpace(this: v5, result: &vecAngularVelocity);
  vecLocalContactPoint.x = vecLocalContactPoint.x - *v6;
  vecLocalContactPoint.y = vecLocalContactPoint.y - v6[1];
  v7 = vecLocalContactPoint.z - v6[2];
  z = pEvent->preAngularVelocity[v4].z;
  v9 = *(_QWORD *)&pEvent->preAngularVelocity[v4].x;
  v10 = (float *)((char *)pEvent + 12 * v4);
  *(_QWORD *)&vecAngularVelocity.x = v9;
  *(float *)&v9 = *(float *)&v9 * 0.017453292;
  vecAngularVelocity.z = z;
  vecLocalContactPoint.z = v7;
  vecLocalContactVelocity.x = (float)((float)(vecAngularVelocity.y * 0.017453292) * v7)
                            - (float)((float)(z * 0.017453292) * vecLocalContactPoint.y);
  vecLocalContactVelocity.y = (float)((float)(z * 0.017453292) * vecLocalContactPoint.x) - (float)(v7 * *(float *)&v9);
  vecLocalContactVelocity.z = (float)(*(float *)&v9 * vecLocalContactPoint.y)
                            - (float)((float)(vecAngularVelocity.y * 0.017453292) * vecLocalContactPoint.x);
  v5->LocalToWorldVector(this: v5, a2: &vecContactVelocity, a3: &vecLocalContactVelocity);
  vecContactVelocity.x = v10[8] + vecContactVelocity.x;
  vecContactVelocity.y = v10[9] + vecContactVelocity.y;
  vecContactVelocity.z = v10[10] + vecContactVelocity.z;
  pEventa = v5->GetMass(this: v5);
  v11 = pEvent->pObjects[index];
  vecContactVelocity.x = pEventa * vecContactVelocity.x;
  vecContactVelocity.y = vecContactVelocity.y * pEventa;
  vecContactVelocity.z = vecContactVelocity.z * pEventa;
  v11->CalculateForceOffset(this: v11, a2: &vecContactVelocity, a3: &vecContactPoint, a4: &vecForce, a5: &vecTorque);
  PhysCallbackImpulse(pPhysicsObject: pEvent->pObjects[index], vecCenterForce: &vecForce, vecCenterTorque: &vecTorque);
}

//------------------------------------------------------------------------------
// Address: 0x101DDCA0
// Name: public: static bool CBreakModelsPrecached::BreakLessFunc(struct CBreakModelsPrecached::breakable_precache_t const __near &,struct CBreakModelsPrecached::breakable_precache_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CBreakModelsPrecached::BreakLessFunc(
        const CBreakModelsPrecached::breakable_precache_t *lhs,
        const CBreakModelsPrecached::breakable_precache_t *rhs)
{
  const char *pszValue; // eax
  const char *v3; // ecx

  pszValue = lhs->iszModelName.pszValue;
  if ( lhs->iszModelName.pszValue == nullptr )
    pszValue = locale;
  v3 = rhs->iszModelName.pszValue;
  if ( rhs->iszModelName.pszValue == nullptr )
    v3 = locale;
  return pszValue < v3;
}

//------------------------------------------------------------------------------
// Address: 0x101DDCD0
// Name: public: virtual struct datamap_t __near * locksound_t::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall locksound_t::GetDataDescMap(locksound_t *this)
{
  return &locksound_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DDCE0
// Name: protected: virtual struct datamap_t __near * CBasePropDoor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBasePropDoor::GetDataDescMap(CBasePropDoor *this)
{
  return &CBasePropDoor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DDCF0
// Name: public: virtual class ServerClass __near * CBasePropDoor::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBasePropDoor::GetServerClass(CBasePropDoor *this)
{
  return &g_CBasePropDoor_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101DDD00
// Name: public: bool CBasePropDoor::NPCOpenDoor(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePropDoor::NPCOpenDoor(CBasePropDoor *this, CAI_BaseNPC *pNPC)
{
  if ( this->m_eDoorState == DOOR_STATE_CLOSED )
    ((void (__thiscall *)(CBasePropDoor *, CAI_BaseNPC *, CAI_BaseNPC *, int, _DWORD))this->Use)(
      a1: this,
      a2: pNPC,
      a3: pNPC,
      a4: 1,
      a5: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DDD30
// Name: public: virtual struct datamap_t __near * CPropDoorRotating::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPropDoorRotating::GetDataDescMap(CPropDoorRotating *this)
{
  return &CPropDoorRotating::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DDD40
// Name: public: virtual class ServerClass __near * CPropDoorRotating::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPropDoorRotating::GetServerClass(CPropDoorRotating *this)
{
  return &g_CPropDoorRotating_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101DDD50
// Name: void UTIL_ComputeAABBForBounds(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ComputeAABBForBounds(
        const Vector *mins1,
        const Vector *maxs1,
        const Vector *mins2,
        const Vector *maxs2,
        Vector *destMins,
        Vector *destMaxs)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm1_4

  x = mins1->x;
  if ( mins2->x <= mins1->x )
    x = mins2->x;
  destMins->x = x;
  y = mins1->y;
  if ( mins2->y <= y )
    y = mins2->y;
  destMins->y = y;
  z = mins1->z;
  if ( mins2->z <= z )
    z = mins2->z;
  destMins->z = z;
  v9 = maxs1->x;
  if ( maxs1->x <= maxs2->x )
    v9 = maxs2->x;
  destMaxs->x = v9;
  v10 = maxs1->y;
  if ( v10 <= maxs2->y )
    v10 = maxs2->y;
  destMaxs->y = v10;
  v11 = maxs1->z;
  v12 = maxs2->z;
  if ( v11 <= v12 )
    destMaxs->z = v12;
  else
    destMaxs->z = v11;
}

//------------------------------------------------------------------------------
// Address: 0x101DDDF0
// Name: bool DoorUnlockedFilter(class CBaseEntity __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DoorUnlockedFilter(CBaseEntity *pVisibleEntity)
{
  return pVisibleEntity != nullptr && pVisibleEntity->__vftable[1].GetPlayerName(this: pVisibleEntity) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DDE20
// Name: private: void CPropDoorRotating::CalcOpenAngles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::CalcOpenAngles(CPropDoorRotating *this)
{
  float y; // xmm2_4
  float z; // xmm4_4
  float x; // xmm5_4
  float v4; // xmm0_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm5_4

  y = this->m_vecAxis.y;
  z = this->m_vecAxis.z;
  x = this->m_vecAxis.x;
  if ( this->m_flDistance == 0.0 )
    this->m_flDistance = 90.0;
  LODWORD(v4) = LODWORD(this->m_flDistance) & _mask__AbsFloat_;
  v5 = this->m_angRotationClosed.x;
  v6 = v4 * y;
  this->m_angRotationOpenForward.x = v5 - (float)(v4 * y);
  v7 = v4 * z;
  v8 = this->m_angRotationClosed.y;
  this->m_flDistance = v4;
  v9 = v4 * x;
  v10 = this->m_angRotationClosed.z;
  this->m_angRotationOpenForward.y = v8 - v7;
  this->m_angRotationOpenForward.z = v10 - v9;
  this->m_angRotationOpenBack.x = v6 + v5;
  this->m_angRotationOpenBack.y = v7 + v8;
  this->m_angRotationOpenBack.z = v9 + v10;
}

//------------------------------------------------------------------------------
// Address: 0x101DDEF0
// Name: private: enum doorCheck_e CPropDoorRotating::GetOpenState(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPropDoorRotating::GetOpenState(CPropDoorRotating *this)
{
  return this->m_angRotationOpenForward.x != this->m_angGoal.x
      || this->m_angRotationOpenForward.y != this->m_angGoal.y
      || this->m_angRotationOpenForward.z != this->m_angGoal.z;
}

//------------------------------------------------------------------------------
// Address: 0x101DDF50
// Name: public: virtual void CPropDoorRotating::MoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::MoveDone(CPropDoorRotating *this)
{
  void (__thiscall *m_pfnMoveDone)(CBaseEntity *); // eax

  CBaseEntity::SetLocalAngles(this, angles: &this->m_angGoal);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
  m_pfnMoveDone = this->m_pfnMoveDone;
  if ( m_pfnMoveDone != nullptr )
    m_pfnMoveDone(this);
  COutputEvent::FireOutput(this: &this->m_OnRotationDone, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101DDFB0
// Name: public: virtual void CPropDoorRotating::DoorStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::DoorStop(CPropDoorRotating *this)
{
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x101DDFE0
// Name: public: void CPropDoorRotating::InputSetSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::InputSetSpeed(CPropDoorRotating *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  void (*DoorResume)(void); // edx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  DoorResume = (void (*)(void))this->DoorResume;
  LODWORD(this->m_flSpeed) = pszValue;
  DoorResume();
}

//------------------------------------------------------------------------------
// Address: 0x101DE010
// Name: public: virtual struct datamap_t __near * CPropDoorRotatingBreakable::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPropDoorRotatingBreakable::GetDataDescMap(CPropDoorRotatingBreakable *this)
{
  return &CPropDoorRotatingBreakable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DE020
// Name: class Vector GetVelocityFromDamageForce(class CTakeDamageInfo const __near &,class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl GetVelocityFromDamageForce(Vector *result, const CTakeDamageInfo *info, const CBaseEntity *pEntity)
{
  float m_flNonShadowMass; // xmm1_4
  Vector force; // 0:^0.12

  if ( pEntity != nullptr && (m_flNonShadowMass = pEntity->m_flNonShadowMass) > 0.0 )
  {
    force = info->m_vecDamageForce;
    result->x = info->m_vecDamageForce.x * (float)(1.0 / m_flNonShadowMass);
    result->y = force.y * (float)(1.0 / m_flNonShadowMass);
    result->z = force.z * (float)(1.0 / m_flNonShadowMass);
    return result;
  }
  else
  {
    *result = vec3_origin;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE0B0
// Name: public: void CPropDoorRotatingBreakable::InputSetUnbreakable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotatingBreakable::InputSetUnbreakable(
        CPropDoorRotatingBreakable *this,
        inputdata_t *inputdata)
{
  this->m_bBreakable = false;
}

//------------------------------------------------------------------------------
// Address: 0x101DE0C0
// Name: public: void CPropDoorRotatingBreakable::InputSetBreakable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotatingBreakable::InputSetBreakable(CPropDoorRotatingBreakable *this, inputdata_t *inputdata)
{
  this->m_bBreakable = true;
}

//------------------------------------------------------------------------------
// Address: 0x101DE0D0
// Name: public: virtual bool CPropDoorRotatingBreakable::IsAbleToCloseAreaPortals(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPropDoorRotatingBreakable::IsAbleToCloseAreaPortals(CPropDoorRotatingBreakable *this)
{
  return this->m_isAbleToCloseAreaPortals;
}

//------------------------------------------------------------------------------
// Address: 0x101DE0E0
// Name: public: virtual struct datamap_t __near * CPhysBoxMultiplayer::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysBoxMultiplayer::GetDataDescMap(CPhysBoxMultiplayer *this)
{
  return &CPhysBoxMultiplayer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DE0F0
// Name: public: virtual class ServerClass __near * CPhysBoxMultiplayer::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPhysBoxMultiplayer::GetServerClass(CPhysBoxMultiplayer *this)
{
  return &g_CPhysBoxMultiplayer_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101DE100
// Name: public: virtual struct datamap_t __near * CPhysicsPropMultiplayer::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysicsPropMultiplayer::GetDataDescMap(CPhysicsPropMultiplayer *this)
{
  return &CPhysicsPropMultiplayer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DE110
// Name: public: virtual class ServerClass __near * CPhysicsPropMultiplayer::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPhysicsPropMultiplayer::GetServerClass(CPhysicsPropMultiplayer *this)
{
  return &g_CPhysicsPropMultiplayer_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101DE120
// Name: private: virtual struct datamap_t __near * CPhysicsPropRespawnable::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysicsPropRespawnable::GetDataDescMap(CPhysicsPropRespawnable *this)
{
  return &CPhysicsPropRespawnable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DE130
// Name: public: void Extent::Encompass(struct Extent const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Extent::Encompass(Extent *this, const Extent *extent)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  x = extent->lo.x;
  if ( this->lo.x <= extent->lo.x )
  {
    if ( x > this->hi.x )
      this->hi.x = x;
  }
  else
  {
    this->lo.x = x;
  }
  y = extent->lo.y;
  if ( this->lo.y <= y )
  {
    if ( y > this->hi.y )
      this->hi.y = y;
  }
  else
  {
    this->lo.y = y;
  }
  z = extent->lo.z;
  if ( this->lo.z <= z )
  {
    if ( z > this->hi.z )
      this->hi.z = z;
  }
  else
  {
    this->lo.z = z;
  }
  v5 = extent->hi.x;
  if ( this->lo.x <= v5 )
  {
    if ( v5 > this->hi.x )
      this->hi.x = v5;
  }
  else
  {
    this->lo.x = v5;
  }
  v6 = extent->hi.y;
  if ( this->lo.y <= v6 )
  {
    if ( v6 > this->hi.y )
      this->hi.y = v6;
  }
  else
  {
    this->lo.y = v6;
  }
  v7 = extent->hi.z;
  if ( this->lo.z <= v7 )
  {
    if ( v7 > this->hi.z )
      this->hi.z = v7;
  }
  else
  {
    this->lo.z = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE200
// Name: public: bool CBasePropDoor::IsPlayerOpening(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBasePropDoor::IsPlayerOpening(CBasePropDoor *this)
{
  unsigned int m_Index; // ecx
  int v2; // eax
  CEntInfo *v3; // edx
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax
  IHandleEntity *v8; // eax
  BOOL result; // eax

  m_Index = this->m_hActivator.m_Index;
  result = false;
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
      v8 = v6 ? v7->m_pEntity : nullptr;
      if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v8->__vftable[28].dtr_IHandleEntity)(a1: v8) != 0 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DE260
// Name: float GetBreakableDamage(class CTakeDamageInfo const __near &,class IBreakableWithPropData __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetBreakableDamage(const CTakeDamageInfo *inputInfo, IBreakableWithPropData *pProp)
{
  float m_flDamage; // xmm0_4
  int m_bitsDamageType; // ebx
  double v4; // st7
  float flDamage; // [esp+8h] [ebp+8h]

  m_flDamage = inputInfo->m_flDamage;
  m_bitsDamageType = inputInfo->m_bitsDamageType;
  flDamage = m_flDamage;
  if ( (m_bitsDamageType & 2) != 0 )
  {
    if ( (m_bitsDamageType & 0x20000000) != 0 )
    {
      if ( pProp != nullptr )
      {
        v4 = ((double (__thiscall *)(IBreakableWithPropData *))pProp->GetDmgModBullet)(a1: pProp);
        flDamage = (v4 + v4) * m_flDamage;
        m_flDamage = flDamage;
        goto LABEL_10;
      }
      m_flDamage = m_flDamage * (float)(func_breakdmg_bullet.m_pParent->m_Value.m_fValue * 2.0);
    }
    else
    {
      if ( pProp != nullptr )
      {
        flDamage = ((double (__thiscall *)(IBreakableWithPropData *))pProp->GetDmgModBullet)(a1: pProp) * m_flDamage;
        m_flDamage = flDamage;
        goto LABEL_10;
      }
      m_flDamage = m_flDamage * func_breakdmg_bullet.m_pParent->m_Value.m_fValue;
    }
    flDamage = m_flDamage;
  }
LABEL_10:
  if ( (m_bitsDamageType & 0x80u) != 0 )
  {
    if ( pProp != nullptr )
    {
      flDamage = ((double (__thiscall *)(IBreakableWithPropData *))pProp->GetDmgModClub)(a1: pProp) * flDamage;
      m_flDamage = flDamage;
    }
    else
    {
      m_flDamage = m_flDamage * func_breakdmg_club.m_pParent->m_Value.m_fValue;
      flDamage = m_flDamage;
    }
  }
  if ( (m_bitsDamageType & 0x40) != 0 )
  {
    if ( pProp != nullptr )
    {
      flDamage = ((double (__thiscall *)(IBreakableWithPropData *))pProp->GetDmgModExplosive)(a1: pProp) * flDamage;
      m_flDamage = flDamage;
    }
    else
    {
      m_flDamage = m_flDamage * func_breakdmg_explosive.m_pParent->m_Value.m_fValue;
      flDamage = m_flDamage;
    }
  }
  if ( (m_bitsDamageType & 8) != 0 && pProp != nullptr )
  {
    flDamage = ((double (__thiscall *)(IBreakableWithPropData *))pProp->GetDmgModFire)(a1: pProp) * flDamage;
    m_flDamage = flDamage;
  }
  if ( (m_bitsDamageType & 4) != 0 && (m_bitsDamageType & 1) != 0 )
    flDamage = m_flDamage * 10.0;
  if ( g_pGameRules->Damage_IsTimeBased(this: g_pGameRules, a2: m_bitsDamageType) )
    return 0.0;
  return flDamage;
}

//------------------------------------------------------------------------------
// Address: 0x101DE3A0
// Name: public: virtual void CBaseProp::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseProp::Precache(CBaseProp *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  const char *v4; // eax
  char pszValue[4]; // [esp+20h] [ebp-4h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( *(_DWORD *)((int (__thiscall *)(CBaseProp *, char *))this->GetModelName)(a1: this, a2: pszValue) == 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v3 = this->m_iClassname.pszValue;
    if ( v3 == nullptr )
      v3 = locale;
    _Msg(
      a1: "%s at (%.3f, %.3f, %.3f) has no model name!\n",
      v3,
      this->m_vecAbsOrigin.x,
      this->m_vecAbsOrigin.y,
      this->m_vecAbsOrigin.z);
    this->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
  v4 = *(const char **)((int (__thiscall *)(CBaseProp *, char *))this->GetModelName)(a1: this, a2: pszValue);
  if ( v4 == nullptr )
    v4 = locale;
  CBaseEntity::PrecacheModel(a1: a2, name: v4, bPreload: true);
  CBaseEntity::PrecacheScriptSound(soundname: "Metal.SawbladeStick");
  CBaseEntity::PrecacheScriptSound(soundname: "PropaneTank.Burst");
  CBaseAnimating::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DE4B0
// Name: public: virtual void CBaseProp::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseProp::Activate(CBaseProp *this)
{
  const char *v2; // eax
  const char *pszValue; // esi
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  CBaseAnimating::Activate(this);
  if ( this->m_takedamage.m_Value == 0 && this->m_iHealth.m_Value != 0 )
  {
    v2 = *(const char **)((int (__thiscall *)(CBaseProp *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
    if ( v2 == nullptr )
      v2 = locale;
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "%s has a health specified in model '%s'. Use prop_physics or prop_dynamic instead.\n", pszValue, v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE510
// Name: public: virtual bool CBaseProp::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseProp::KeyValue(CBaseProp *this, char *szKeyName, const char *szValue)
{
  return (szKeyName == "health" || _V_stricmp(s1: szKeyName, s2: "health") == 0)
      && (this == nullptr
       || this->m_iClassname.pszValue != "prop_physics_override"
       && CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "prop_physics_override") == 0
       && this->m_iClassname.pszValue != "prop_dynamic_override"
       && CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "prop_dynamic_override") == 0)
      || CBaseEntity::KeyValue(this, szKeyName, szValue);
}

//------------------------------------------------------------------------------
// Address: 0x101DE5A0
// Name: public: void CBaseProp::CalculateBlockLOS(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseProp::CalculateBlockLOS(CBaseProp *this)
{
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  float *v3; // edi
  const Vector *v4; // eax
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  Vector vecSize; // [esp+Ch] [ebp-10h]
  bool bFoundLarge; // [esp+1Bh] [ebp-1h]

  OBBMins = this->m_Collision.OBBMins;
  bFoundLarge = false;
  v3 = (float *)OBBMins(this: &this->m_Collision);
  v4 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
  vecSize.x = v4->x - *v3;
  vecSize.y = v4->y - v3[1];
  v5 = v4->z - v3[2];
  v6 = 0;
  vecSize.z = v5;
  while ( 1 )
  {
    v7 = *(&vecSize.x + v6);
    if ( v7 > 40.0 )
      bFoundLarge = true;
    if ( v7 <= 30.0 )
      break;
    if ( ++v6 >= 3 )
    {
      if ( bFoundLarge )
        return;
      break;
    }
  }
  CBaseEntity::SetBlocksLOS(this, bBlocksLOS: false);
}

//------------------------------------------------------------------------------
// Address: 0x101DE650
// Name: public: virtual void CBaseProp::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseProp::DrawDebugGeometryOverlays(CBaseProp *this)
{
  char m_Value; // al
  float v3; // xmm0_4

  CBaseEntity::DrawDebugGeometryOverlays(this);
  if ( (this->m_debugOverlays & 0x10000000) != 0 )
  {
    m_Value = this->m_takedamage.m_Value;
    if ( m_Value != 0 )
    {
      if ( m_Value == 1 )
      {
        NDebugOverlay::EntityBounds(pEntity: this, r: 255, g: 255, b: 255, a: 0, flDuration: 0.0);
      }
      else
      {
        v3 = (float)((float)((float)this->m_iHealth.m_Value * 191.0) * 0.0099999998) + 64.0;
        if ( v3 >= 0.0 )
        {
          if ( v3 > 255.0 )
            v3 = 255.0;
        }
        else
        {
          v3 = 0.0;
        }
        NDebugOverlay::EntityBounds(pEntity: this, r: 0, g: (int)v3, b: 0, a: 0, flDuration: 0.0);
      }
    }
    else
    {
      NDebugOverlay::EntityBounds(pEntity: this, r: 255, g: 0, b: 0, a: 0, flDuration: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE720
// Name: void CC_Prop_Debug(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Prop_Debug()
{
  CBaseEntity *i; // esi
  _DWORD *v1; // eax
  int v2; // ecx
  unsigned int v3; // ecx

  for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
        i != nullptr;
        i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
  {
    v1 = __RTDynamicCast(
           inptr: i,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBaseProp `RTTI Type Descriptor',
           isReference: 0);
    if ( v1 != nullptr )
    {
      v2 = v1[201];
      if ( (v2 & 0x10000000) != 0 )
        v3 = v2 & 0xEFFFFFFF;
      else
        v3 = v2 | 0x10000000;
      v1[201] = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE790
// Name: public: void CBreakableProp::CopyFadeFrom(class CBreakableProp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::CopyFadeFrom(CBreakableProp *this, CBreakableProp *pSource)
{
  float thinkTime; // xmm1_4
  float flFadeScale; // [esp+4h] [ebp-Ch]
  float flNextThink; // [esp+18h] [ebp+8h]

  this->m_flDefaultFadeScale = pSource->m_flDefaultFadeScale;
  flFadeScale = CBaseEntity::GetGlobalFadeScale(this: pSource);
  CBaseEntity::SetGlobalFadeScale(this, flFadeScale);
  if ( CBaseEntity::GetGlobalFadeScale(this) != this->m_flDefaultFadeScale )
  {
    flNextThink = CBaseEntity::GetNextThink(this: pSource, szContext: s_pFadeScaleThink);
    thinkTime = flNextThink;
    if ( (float)(gpGlobals->interval_per_tick + gpGlobals->curtime) > flNextThink )
      thinkTime = gpGlobals->interval_per_tick + gpGlobals->curtime;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CBreakableProp::RampToDefaultFadeScale,
      thinkTime,
      szContext: s_pFadeScaleThink);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE820
// Name: private: void CBreakableProp::InputEnablePhyscannonPickup(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::InputEnablePhyscannonPickup(CBreakableProp *this, inputdata_t *inputdata)
{
  this->m_iEFlags &= ~0x40000000u;
}

//------------------------------------------------------------------------------
// Address: 0x101DE830
// Name: private: void CBreakableProp::InputDisablePhyscannonPickup(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::InputDisablePhyscannonPickup(CBreakableProp *this, inputdata_t *inputdata)
{
  this->m_iEFlags |= 0x40000000u;
}

//------------------------------------------------------------------------------
// Address: 0x101DE840
// Name: public: virtual class Vector CBreakableProp::PhysGunLaunchAngularImpulse(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBreakableProp::PhysGunLaunchAngularImpulse(CBreakableProp *this, Vector *result)
{
  if ( (*(unsigned __int8 (__thiscall **)(char *, int))(*((_DWORD *)this - 1) + 96))(a1: (char *)this - 4, a2: 4) != 0
    || (*(unsigned __int8 (__thiscall **)(char *, int))(*((_DWORD *)this - 1) + 96))(a1: (char *)this - 4, a2: 5) != 0 )
  {
    *(_QWORD *)&result->x = 0;
    result->z = 0.0;
    return result;
  }
  else
  {
    CDefaultPlayerPickupVPhysics::PhysGunLaunchAngularImpulse((CDefaultPlayerPickupVPhysics *)this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE8B0
// Name: public: virtual class CBasePlayer __near * CBreakableProp::HasPhysicsAttacker(float)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CBreakableProp::HasPhysicsAttacker(CBreakableProp *this, float dt)
{
  unsigned int m_Index; // ecx

  if ( this->m_flLastPhysicsInfluenceTime < (float)(gpGlobals->curtime - dt) )
    return nullptr;
  m_Index = this->m_hPhysicsAttacker.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101DE910
// Name: public: virtual class IPhysicsObject __near * CBreakableProp::GetRootPhysicsObjectForBreak(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CBreakableProp::GetRootPhysicsObjectForBreak(CBreakableProp *this)
{
  return this->m_pPhysicsObject;
}

//------------------------------------------------------------------------------
// Address: 0x101DE9F0
// Name: public: virtual bool CDynamicProp::OverridePropdata(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDynamicProp::OverridePropdata(CDynamicProp *this)
{
  return this != nullptr
      && (this->m_iClassname.pszValue == "prop_dynamic_override"
       || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "prop_dynamic_override") != 0);
}

//------------------------------------------------------------------------------
// Address: 0x101DEA20
// Name: public: virtual void CDynamicProp::NotifyPositionChanged(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::NotifyPositionChanged(CDynamicProp *this, CBaseEntity *pEntity)
{
  CBoneFollowerManager::UpdateBoneFollowers(
    this: (CBoneFollowerManager *)((char *)&this->m_Network + 76),
    pParentEntity: (CDynamicProp *)((char *)this - 1512));
}

//------------------------------------------------------------------------------
// Address: 0x101DEA40
// Name: public: void CDynamicProp::InputSetDefaultAnimation(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::InputSetDefaultAnimation(CDynamicProp *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_STRING )
    this->m_iszDefaultAnim.pszValue = inputdata->value.iszVal.pszValue;
  else
    this->m_iszDefaultAnim.pszValue = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DEB90
// Name: public: virtual bool CPhysicsProp::OverridePropdata(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPhysicsProp::OverridePropdata(CPhysicsProp *this)
{
  return this != nullptr
      && (this->m_iClassname.pszValue == "prop_physics_override"
       || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "prop_physics_override") != 0);
}

//------------------------------------------------------------------------------
// Address: 0x101DEBC0
// Name: public: void CPhysicsProp::InputSleep(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::InputSleep(CPhysicsProp *this, inputdata_t *inputdata)
{
  IPhysicsObject *m_pPhysicsObject; // ecx

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->Sleep(this: m_pPhysicsObject);
}

//------------------------------------------------------------------------------
// Address: 0x101DEBE0
// Name: public: void CPhysicsProp::ClearFlagsThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::ClearFlagsThink(CPhysicsProp *this)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  unsigned __int16 v3; // ax

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    v3 = m_pPhysicsObject->GetGameFlags(this: this->m_pPhysicsObject);
    m_pPhysicsObject->SetGameFlags(this: m_pPhysicsObject, a2: v3 & 0xFEFF);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: "PROP_CLEARFLAGS");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DED40
// Name: protected: virtual void CBasePropDoor::CalcDoorSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::CalcDoorSounds(CBasePropDoor *this)
{
  IVModelInfo_vtbl *v2; // esi
  model_t *Model; // eax
  KeyValues *v4; // eax
  KeyValues *Key; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  string_t v8; // eax
  bool v9; // zf
  const char *String; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  IPhysicsObject *m_pPhysicsObject; // ecx
  IVModelInfo_vtbl *v16; // esi
  model_t *v17; // eax
  const char *DebugName; // eax
  IPhysicsObject_vtbl *v19; // esi
  string_t *p_m_SoundOpen; // ebx
  string_t *p_m_SoundMoving; // esi
  string_t *p_sUnlockedSound; // edi
  const char *pszValue; // esi
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // [esp+8h] [ebp-C8h]
  int v29; // [esp+8h] [ebp-C8h]
  char szHardware[80]; // [esp+1Ch] [ebp-B4h] BYREF
  char szSkin[80]; // [esp+6Ch] [ebp-64h] BYREF
  string_t strSoundClose; // [esp+BCh] [ebp-14h] BYREF
  string_t strSoundLocked; // [esp+C0h] [ebp-10h] BYREF
  string_t strSoundUnlocked; // [esp+C4h] [ebp-Ch] BYREF
  string_t strSoundOpen; // [esp+C8h] [ebp-8h] BYREF
  string_t strSoundMoving; // [esp+CCh] [ebp-4h] BYREF
  int savedregs; // [esp+D0h] [ebp+0h] BYREF

  if ( CBaseEntity::GetModel(this) == nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    _Error(
      this: (ISceneTokenProcessor *)&stru_104AB360,
      a2: (const char *)COERCE_UNSIGNED_INT64(this->m_vecAbsOrigin.x),
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(this->m_vecAbsOrigin.x)),
      this->m_vecAbsOrigin.y,
      this->m_vecAbsOrigin.z);
  }
  v2 = modelinfo->__vftable;
  strSoundOpen.pszValue = nullptr;
  strSoundClose.pszValue = nullptr;
  strSoundMoving.pszValue = nullptr;
  strSoundLocked.pszValue = nullptr;
  strSoundUnlocked.pszValue = nullptr;
  Model = CBaseEntity::GetModel(this);
  v4 = v2->GetModelKeyValues(this: modelinfo, a2: Model);
  if ( v4 != nullptr )
  {
    Key = KeyValues::FindKey(this: v4, keyName: "door_options", bCreate: false);
    if ( Key != nullptr )
    {
      V_snprintf(pDest: szSkin, maxLen: 80, pFormat: "skin%d", this->m_nSkin.m_Value);
      v6 = KeyValues::FindKey(this: Key, keyName: szSkin, bCreate: false);
      v7 = v6;
      if ( v6 != nullptr )
      {
        KeyValues::GetString(this: v6, keyName: "open", defaultValue: locale);
        strSoundOpen.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&strSoundMoving).pszValue;
        KeyValues::GetString(this: v7, keyName: "close", defaultValue: locale);
        strSoundClose.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&strSoundMoving).pszValue;
        KeyValues::GetString(this: v7, keyName: "move", defaultValue: locale);
        v8.pszValue = AllocPooledString(pszValue: (const char *)&strSoundMoving).pszValue;
        v9 = this->m_nPhysicsMaterial == -1;
        strSoundMoving.pszValue = *(const char **)v8.pszValue;
        if ( v9 )
        {
          String = KeyValues::GetString(this: v7, keyName: "surfaceprop", defaultValue: locale);
          if ( String != nullptr && this->m_pPhysicsObject != nullptr )
            this->m_nPhysicsMaterial = physprops->GetSurfaceIndex(this: physprops, a2: String);
        }
      }
      V_snprintf(pDest: szHardware, maxLen: 80, pFormat: "hardware%d", this->m_nHardwareType);
      v11 = KeyValues::FindKey(this: Key, keyName: szHardware, bCreate: false);
      v12 = v11;
      if ( v11 != nullptr )
      {
        KeyValues::GetString(this: v11, keyName: "locked", defaultValue: locale);
        strSoundLocked.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&strSoundUnlocked).pszValue;
        KeyValues::GetString(this: v12, keyName: "unlocked", defaultValue: locale);
        strSoundUnlocked.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&strSoundUnlocked).pszValue;
      }
      if ( strSoundOpen.pszValue == nullptr
        || strSoundClose.pszValue == nullptr
        || strSoundMoving.pszValue == nullptr
        || strSoundLocked.pszValue == nullptr
        || strSoundUnlocked.pszValue == nullptr )
      {
        v13 = KeyValues::FindKey(this: Key, keyName: "defaults", bCreate: false);
        v14 = v13;
        if ( v13 != nullptr )
        {
          if ( strSoundOpen.pszValue == nullptr )
          {
            KeyValues::GetString(this: v13, keyName: "open", defaultValue: locale);
            strSoundOpen.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&strSoundOpen).pszValue;
          }
          if ( strSoundClose.pszValue == nullptr )
          {
            KeyValues::GetString(this: v14, keyName: "close", defaultValue: locale);
            strSoundClose.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&strSoundClose).pszValue;
          }
          if ( strSoundMoving.pszValue == nullptr )
          {
            KeyValues::GetString(this: v14, keyName: "move", defaultValue: locale);
            strSoundMoving.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&strSoundMoving).pszValue;
          }
          if ( strSoundLocked.pszValue == nullptr )
          {
            KeyValues::GetString(this: v14, keyName: "locked", defaultValue: locale);
            strSoundLocked.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&strSoundLocked).pszValue;
          }
          if ( strSoundUnlocked.pszValue == nullptr )
          {
            KeyValues::GetString(this: v14, keyName: "unlocked", defaultValue: locale);
            strSoundUnlocked.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&strSoundUnlocked).pszValue;
          }
        }
      }
    }
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    if ( this->m_nPhysicsMaterial == -1 )
    {
      v16 = modelinfo->__vftable;
      v17 = CBaseEntity::GetModel(this);
      v28 = v16->GetModelName(this: modelinfo, a2: v17);
      DebugName = CBaseEntity::GetDebugName(this);
      _Warning(
        a1: "%s has Door model (%s) with no door_options or m_nPhysicsMaterial specified! Verify that SKIN is valid, and has "
        "a corresponding options block in the model QC file\n",
        DebugName,
        v28);
      v19 = this->m_pPhysicsObject->CDynamicProp::CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::__vftable;
      v29 = physprops->GetSurfaceIndex(this: physprops, a2: "wood");
      ((void (__stdcall *)(int))v19->SetMaterialIndex)(a1: v29);
    }
    else
    {
      ((void (__stdcall *)(int))m_pPhysicsObject->SetMaterialIndex)(a1: this->m_nPhysicsMaterial);
    }
  }
  p_m_SoundOpen = &this->m_SoundOpen;
  if ( this->m_SoundOpen.pszValue == nullptr )
    p_m_SoundOpen->pszValue = strSoundOpen.pszValue;
  v9 = this->m_SoundClose.pszValue == nullptr;
  strSoundOpen.pszValue = (const char *)&this->m_SoundClose;
  if ( v9 )
    this->m_SoundClose = strSoundClose;
  p_m_SoundMoving = &this->m_SoundMoving;
  if ( this->m_SoundMoving.pszValue == nullptr )
    p_m_SoundMoving->pszValue = strSoundMoving.pszValue;
  v9 = this->m_ls.sLockedSound.pszValue == nullptr;
  strSoundMoving.pszValue = (const char *)&this->m_ls.sLockedSound;
  if ( v9 )
    this->m_ls.sLockedSound = strSoundLocked;
  p_sUnlockedSound = &this->m_ls.sUnlockedSound;
  if ( p_sUnlockedSound->pszValue == nullptr )
    p_sUnlockedSound->pszValue = strSoundUnlocked.pszValue;
  UTIL_ValidateSoundName(name: p_m_SoundMoving, defaultStr: "DoorSound.Null");
  UTIL_ValidateSoundName(name: p_m_SoundOpen, defaultStr: "DoorSound.Null");
  UTIL_ValidateSoundName(name: (string_t *)strSoundOpen.pszValue, defaultStr: "DoorSound.Null");
  UTIL_ValidateSoundName(name: (string_t *)strSoundMoving.pszValue, defaultStr: "DoorSound.Null");
  UTIL_ValidateSoundName(name: p_sUnlockedSound, defaultStr: "DoorSound.Null");
  pszValue = p_m_SoundMoving->pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CBaseEntity::PrecacheScriptSound(soundname: pszValue);
  v24 = p_m_SoundOpen->pszValue;
  if ( p_m_SoundOpen->pszValue == nullptr )
    v24 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v24);
  v25 = *(const char **)strSoundOpen.pszValue;
  if ( *(_DWORD *)strSoundOpen.pszValue == 0 )
    v25 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v25);
  v26 = *(const char **)strSoundMoving.pszValue;
  if ( *(_DWORD *)strSoundMoving.pszValue == 0 )
    v26 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v26);
  v27 = p_sUnlockedSound->pszValue;
  if ( p_sUnlockedSound->pszValue == nullptr )
    v27 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v27);
}

//------------------------------------------------------------------------------
// Address: 0x101DF210
// Name: private: void CBasePropDoor::SetDoorBlocker(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::SetDoorBlocker(CBasePropDoor *this, CBaseEntity *pBlocker)
{
  unsigned int m_Index; // eax

  if ( pBlocker != nullptr )
    this->m_hBlocker.m_Index = pBlocker->GetRefEHandle(this: pBlocker)->m_Index;
  else
    this->m_hBlocker.m_Index = -1;
  m_Index = this->m_hBlocker.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    this->m_bFirstBlocked = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF280
// Name: private: void CBasePropDoor::InputLock(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::InputLock(CBasePropDoor *this, inputdata_t *inputdata)
{
  this->m_bLocked = true;
}

//------------------------------------------------------------------------------
// Address: 0x101DF290
// Name: private: void CBasePropDoor::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePropDoor::Unlock(CBasePropDoor *this@<ecx>, int a2@<ebp>)
{
  const char *DebugName; // eax
  double x; // [esp+0h] [ebp-1Ch]
  double y; // [esp+8h] [ebp-14h]
  double z; // [esp+10h] [ebp-Ch]

  if ( this->m_nHardwareType == 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    z = this->m_vecAbsOrigin.z;
    y = this->m_vecAbsOrigin.y;
    x = this->m_vecAbsOrigin.x;
    DebugName = CBaseEntity::GetDebugName(this);
    _DevWarning(
      a1: 1,
      a2: "Unlocking prop_door '%s' at (%.0f %.0f %.0f) with no hardware. All openable doors must have hardware!\n",
      DebugName,
      x,
      y,
      z);
  }
  this->m_bLocked = false;
}

//------------------------------------------------------------------------------
// Address: 0x101DF340
// Name: public: virtual bool CBasePropDoor::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePropDoor::TestCollision(
        CBasePropDoor *this,
        const Ray_t *ray,
        unsigned int mask,
        CGameTrace *trace)
{
  IMDLCache *v6; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  int v8; // eax
  CStudioHdr *v9; // [esp+4h] [ebp-8h]
  IPhysicsCollision_vtbl *v10; // [esp+8h] [ebp-4h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  IPhysicsObject *maska; // [esp+18h] [ebp+Ch]

  if ( this->m_pPhysicsObject == nullptr )
    return 0;
  v6 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  v9 = m_pStudioHdr;
  if ( m_pStudioHdr == nullptr
    || m_pStudioHdr->m_pStudioHdr == nullptr
    || (mask & m_pStudioHdr->m_pStudioHdr->contents) == 0 )
  {
    goto LABEL_18;
  }
  maska = this->m_pPhysicsObject;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v10 = physcollision->__vftable;
  v8 = ((int (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, CGameTrace *))maska->GetCollide)(
         a1: maska,
         a2: &this->m_vecAbsOrigin,
         a3: &this->m_angAbsRotation,
         a4: trace);
  ((void (__thiscall *)(IPhysicsCollision *, const Ray_t *, int))v10->TraceBox_2)(a1: physcollision, a2: ray, a3: v8);
  if ( trace->fraction < 1.0 || trace->allsolid || trace->startsolid )
  {
    trace->contents = v9->m_pStudioHdr->contents;
    trace->surface.name = "**studio**";
    trace->surface.flags = 0;
    trace->surface.surfaceProps = this->m_pPhysicsObject->GetMaterialIndex(this: this->m_pPhysicsObject);
    v6->EndLock(this: v6);
    return 1;
  }
  else
  {
LABEL_18:
    v6->EndLock(this: v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF530
// Name: private: bool CPropDoorRotating::IsHingeOnLeft(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPropDoorRotating::IsHingeOnLeft(CPropDoorRotating *this)
{
  float x; // xmm3_4
  float y; // xmm2_4
  float v4; // xmm0_4
  unsigned int v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm1_4
  Vector vecRight; // [esp+4h] [ebp-30h] BYREF
  Vector vecPointCheck; // [esp+10h] [ebp-24h]
  Vector vecMaxs; // [esp+1Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+28h] [ebp-Ch] BYREF
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  CCollisionProperty::CollisionAABBToWorldAABB(
    this: &this->m_Collision,
    entityMins: &this->m_Collision.m_vecMins.m_Value,
    entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
    pWorldMins: &vecMins,
    pWorldMaxs: &vecMaxs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  x = vecMins.x - this->m_vecAbsOrigin.x;
  y = vecMins.y - this->m_vecAbsOrigin.y;
  v4 = vecMins.z - this->m_vecAbsOrigin.z;
  v5 = (unsigned int)this->m_iEFlags >> 11;
  vecMins.x = x;
  vecMins.y = y;
  vecMins.z = v4;
  if ( (v5 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    y = vecMins.y;
    x = vecMins.x;
  }
  v6 = vecMaxs.x - this->m_vecAbsOrigin.x;
  v7 = vecMaxs.y - this->m_vecAbsOrigin.y;
  vecMaxs.z = 0.0;
  vecMins.z = 0.0;
  vecMaxs.x = v6;
  vecMaxs.y = v7;
  if ( (float)((float)(x * x) + (float)(y * y)) <= (float)((float)(v7 * v7) + (float)(v6 * v6)) )
  {
    vecPointCheck.x = v6;
    vecPointCheck.y = v7;
  }
  else
  {
    vecPointCheck.x = x;
    vecPointCheck.y = y;
  }
  this->GetVectors(this, a2: nullptr, a3: &vecRight, a4: nullptr);
  return (float)((float)((float)(vecRight.y * vecPointCheck.y) + (float)(vecRight.x * vecPointCheck.x))
               + (float)(vecRight.z * 0.0)) > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101DF690
// Name: public: virtual void CPropDoorRotating::GetNPCOpenData(class CAI_BaseNPC __near *,struct opendata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::GetNPCOpenData(CPropDoorRotating *this, CAI_BaseNPC *pNPC, opendata_t *opendata)
{
  unsigned int v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm0_4
  float v14; // xmm3_4
  bool v15; // cc
  float v16; // xmm5_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  float v20; // xmm6_4
  float v21; // xmm3_4
  float v22; // xmm6_4
  float v23; // xmm3_4
  Vector vecRight; // [esp+Ch] [ebp-24h] BYREF
  float v25; // [esp+18h] [ebp-18h]
  float v26; // [esp+1Ch] [ebp-14h]
  float v27; // [esp+20h] [ebp-10h]
  Vector vecForward; // [esp+24h] [ebp-Ch] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  AngleVectors(angles: &this->m_angAbsRotation, forward: &vecForward, right: &vecRight, up: nullptr);
  v4 = (unsigned int)this->m_iEFlags >> 11;
  v5 = vecRight.x * 24.0;
  v6 = vecRight.y * 24.0;
  v7 = vecRight.z * 24.0;
  v25 = vecRight.x * 24.0;
  v26 = vecRight.y * 24.0;
  v27 = vecRight.z * 24.0;
  if ( (v4 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v7 = v27;
    v6 = v26;
    v5 = v25;
  }
  v8 = this->m_vecAbsOrigin.x - v5;
  v9 = (float)(this->m_vecAbsOrigin.z - v7) - 54.0;
  v10 = this->m_vecAbsOrigin.y - v6;
  opendata->vecStandPos.x = v8;
  opendata->vecStandPos.y = v10;
  opendata->vecStandPos.z = v9;
  if ( (pNPC->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pNPC, a2: (int)&savedregs);
  if ( (pNPC->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pNPC, a2: (int)&savedregs);
  y = vecForward.y;
  x = vecForward.x;
  z = vecForward.z;
  v14 = (float)((float)(pNPC->m_vecAbsOrigin.y * vecForward.y) + (float)(pNPC->m_vecAbsOrigin.x * vecForward.x))
      + (float)(pNPC->m_vecAbsOrigin.z * vecForward.z);
  if ( (this->m_iEFlags & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    z = vecForward.z;
    y = vecForward.y;
    x = vecForward.x;
  }
  v15 = v14 <= (float)((float)((float)(this->m_vecAbsOrigin.y * y) + (float)(this->m_vecAbsOrigin.x * x))
                     + (float)(this->m_vecAbsOrigin.z * z));
  v16 = z * 64.0;
  v17 = x * 64.0;
  v18 = y * 64.0;
  v19 = opendata->vecStandPos.x;
  if ( v15 )
  {
    v22 = v19 - v17;
    opendata->vecStandPos.y = opendata->vecStandPos.y - v18;
    v23 = opendata->vecStandPos.z - v16;
    opendata->vecStandPos.x = v22;
    opendata->vecStandPos.z = v23;
  }
  else
  {
    v20 = v19 + v17;
    opendata->vecStandPos.y = opendata->vecStandPos.y + v18;
    v21 = opendata->vecStandPos.z + v16;
    opendata->vecStandPos.x = v20;
    opendata->vecStandPos.z = v21;
    x = -x;
    y = -y;
    z = -z;
  }
  opendata->vecFaceDir.x = x;
  opendata->vecFaceDir.y = y;
  opendata->vecFaceDir.z = z;
  opendata->eActivity = ACT_OPEN_DOOR;
}

//------------------------------------------------------------------------------
// Address: 0x101DF8C0
// Name: public: virtual int CPropDoorRotating::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropDoorRotating::DrawDebugTextOverlays(CPropDoorRotating *this)
{
  int result; // eax
  int v3; // edi
  int v4; // edi
  CBasePropDoor::DoorState_t m_eDoorState; // eax
  const char *v6; // [esp+10h] [ebp-210h]
  char tempstr[512]; // [esp+20h] [ebp-200h] BYREF

  result = CBaseAnimating::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(
      pDest: tempstr,
      maxLen: 512,
      pFormat: "Avelocity: %.2f %.2f %.2f",
      this->m_vecAngVelocity.x,
      this->m_vecAngVelocity.y,
      this->m_vecAngVelocity.z);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    if ( this->IsDoorLocked(this) )
      CBaseEntity::EntityText(this, text_offset: v4++, text: "LOCKED", duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    m_eDoorState = this->m_eDoorState;
    if ( m_eDoorState == DOOR_STATE_OPEN )
    {
      V_strncpy(pDest: tempstr, pSrc: "DOOR STATE: OPEN", maxLen: 512);
LABEL_15:
      CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      return v4 + 1;
    }
    if ( m_eDoorState != DOOR_STATE_CLOSED )
    {
      if ( m_eDoorState == DOOR_STATE_OPENING )
      {
        V_strncpy(pDest: tempstr, pSrc: "DOOR STATE: OPENING", maxLen: 512);
        goto LABEL_15;
      }
      if ( m_eDoorState == DOOR_STATE_CLOSING )
      {
        V_strncpy(pDest: tempstr, pSrc: "DOOR STATE: CLOSING", maxLen: 512);
        goto LABEL_15;
      }
      if ( m_eDoorState != DOOR_STATE_AJAR )
        goto LABEL_15;
      v6 = "DOOR STATE: AJAR";
    }
    else
    {
      v6 = "DOOR STATE: CLOSED";
    }
    V_strncpy(pDest: tempstr, pSrc: v6, maxLen: 512);
    goto LABEL_15;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DFA50
// Name: public: virtual int CPropDoorRotatingBreakable::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropDoorRotatingBreakable::DrawDebugTextOverlays(CPropDoorRotatingBreakable *this)
{
  int result; // eax
  int v3; // esi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CPropDoorRotating::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    if ( this->m_bBreakable )
      V_strncpy(pDest: tempstr, pSrc: "DOOR IS BREAKABLE", maxLen: 512);
    else
      V_strncpy(pDest: tempstr, pSrc: "DOOR IS NOT BREAKABLE", maxLen: 512);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DFD20
// Name: void CC_Prop_Dynamic_Create(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CC_Prop_Dynamic_Create(int a1@<ebx>, int a2@<esi>, const CCommand *args)
{
  CBasePlayer *CommandClient; // esi
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v5; // eax
  Vector *(__thiscall *v6)(CBaseEntity *, Vector *); // edx
  const Vector *v7; // eax
  IMDLCache *v8; // ebx
  const char *v9; // eax
  unsigned __int16 v10; // ax
  int v11; // esi
  vcollide_t *v12; // eax
  vcollide_t *v13; // edi
  CBaseEntity *EntityByName; // eax
  CBaseEntity *v15; // esi
  const char *v16; // eax
  int v18; // [esp+30h] [ebp-500h]
  char pModelName[512]; // [esp+3Ch] [ebp-4F4h] BYREF
  char buf[512]; // [esp+23Ch] [ebp-2F4h] BYREF
  _BYTE v22[12]; // [esp+43Ch] [ebp-F4h] BYREF
  Vector vecAbsEnd; // [esp+448h] [ebp-E8h] BYREF
  VMatrix entToWorld; // [esp+454h] [ebp-DCh] BYREF
  CGameTrace tr; // [esp+494h] [ebp-9Ch] BYREF
  unsigned int mask[3]; // [esp+4E8h] [ebp-48h] BYREF
  Vector forward; // [esp+4F4h] [ebp-3Ch] BYREF
  QAngle angles; // [esp+500h] [ebp-30h] BYREF
  float v29; // [esp+50Ch] [ebp-24h]
  float v30; // [esp+510h] [ebp-20h]
  float v31; // [esp+514h] [ebp-1Ch]
  Vector xaxis; // [esp+518h] [ebp-18h] BYREF
  Vector yaxis; // [esp+524h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+530h] [ebp+0h] BYREF
  bool bAllowPrecache; // [esp+538h] [ebp+8h]

  if ( args->m_nArgc == 2 )
  {
    CommandClient = UTIL_GetCommandClient();
    CBasePlayer::EyeVectors(this: CommandClient, pForward: &forward, pRight: nullptr, pUp: nullptr);
    EyePosition = CommandClient->EyePosition;
    v29 = forward.x * 56755.84;
    v30 = forward.y * 56755.84;
    v31 = forward.z * 56755.84;
    v5 = (float *)((int (__thiscall *)(CBasePlayer *, _BYTE *, int))EyePosition)(a1: CommandClient, a2: v22, a3: a2);
    v6 = CommandClient->EyePosition;
    *(float *)mask = *v5 + v29;
    *(float *)&mask[1] = v5[1] + v30;
    *(float *)&mask[2] = v5[2] + v31;
    v7 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v6)(a1: CommandClient);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)CommandClient,
      vecAbsStart: v7,
      &vecAbsEnd,
      (unsigned int)mask,
      ignore: (const IHandleEntity *)0x202400B,
      collisionGroup: (int)CommandClient,
      ptr: nullptr);
    if ( tr.fraction != 1.0 )
    {
      v8 = mdlcache;
      ((void (__thiscall *)(IMDLCache *, int))mdlcache->BeginLock)(a1: mdlcache, a2: a1);
      v9 = locale;
      if ( args->m_nArgc > 1 )
        v9 = args->m_ppArgv[1];
      V_snprintf(pDest: pModelName, maxLen: 512, pFormat: "models/%s", v9);
      V_DefaultExtension(path: pModelName, extension: ".mdl", pathStringLength: 512);
      v10 = mdlcache->FindMDL(this: mdlcache, a2: pModelName);
      v11 = v10;
      if ( v10 != 0xFFFF )
      {
        bAllowPrecache = CBaseEntity::IsPrecacheAllowed();
        CBaseEntity::SetAllowPrecache(allow: true);
        v12 = mdlcache->GetVCollide(this: mdlcache, a2: v11);
        xaxis.x = 1.0;
        yaxis.x = (float)(tr.plane.normal.y * 0.0) - (float)(tr.plane.normal.z * 0.0);
        v13 = v12;
        xaxis.y = 0.0;
        xaxis.z = 0.0;
        yaxis.y = tr.plane.normal.z - (float)(tr.plane.normal.x * 0.0);
        yaxis.z = (float)(tr.plane.normal.x * 0.0) - tr.plane.normal.y;
        if ( VectorNormalize(vec: &yaxis) < 0.001 )
        {
          xaxis.z = 1.0;
          yaxis.x = tr.plane.normal.y - (float)(tr.plane.normal.z * 0.0);
          xaxis.x = 0.0;
          xaxis.y = 0.0;
          yaxis.y = (float)(tr.plane.normal.z * 0.0) - tr.plane.normal.x;
          yaxis.z = (float)(tr.plane.normal.x * 0.0) - (float)(tr.plane.normal.y * 0.0);
          VectorNormalize(vec: &yaxis);
        }
        xaxis.x = (float)(tr.plane.normal.z * yaxis.y) - (float)(tr.plane.normal.y * yaxis.z);
        xaxis.y = (float)(tr.plane.normal.x * yaxis.z) - (float)(tr.plane.normal.z * yaxis.x);
        xaxis.z = (float)(tr.plane.normal.y * yaxis.x) - (float)(tr.plane.normal.x * yaxis.y);
        VectorNormalize(vec: &xaxis);
        *(_QWORD *)&entToWorld.m[0][0] = __PAIR64__(LODWORD(yaxis.x), LODWORD(xaxis.x));
        *(_QWORD *)&entToWorld.m[1][0] = __PAIR64__(LODWORD(yaxis.y), LODWORD(xaxis.y));
        *(_QWORD *)&entToWorld.m[2][0] = __PAIR64__(LODWORD(yaxis.z), LODWORD(xaxis.z));
        entToWorld.m[0][2] = tr.plane.normal.x;
        entToWorld.m[1][2] = tr.plane.normal.y;
        entToWorld.m[2][2] = tr.plane.normal.z;
        MatrixAngles(a1: v11, src: &entToWorld, vAngles: &angles);
        EntityByName = CreateEntityByName(className: "dynamic_prop", iForceEdictIndex: -1, bNotify: true);
        v15 = (CBaseEntity *)__RTDynamicCast(
                               inptr: EntityByName,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CDynamicProp `RTTI Type Descriptor',
                               isReference: 0);
        if ( v15 != nullptr )
        {
          V_snprintf(pDest: buf, maxLen: 512, pFormat: "%.10f %.10f %.10f", tr.endpos.x, tr.endpos.y, tr.endpos.z);
          ((void (__thiscall *)(CBaseEntity *, const char *, char *, int, CGameTrace *))v15->KeyValue_4)(
            a1: v15,
            a2: "origin",
            a3: buf,
            a4: v18,
            a5: &tr);
          V_snprintf(pDest: buf, maxLen: 512, pFormat: "%.10f %.10f %.10f", angles.x, angles.y, angles.z);
          v15->KeyValue_4(this: v15, a2: "angles", a3: buf);
          v15->KeyValue_4(this: v15, a2: "model", a3: pModelName);
          v16 = "6";
          if ( v13 == nullptr )
            v16 = "2";
          v15->KeyValue_4(this: v15, a2: "solid", a3: v16);
          v15->KeyValue_4(this: v15, a2: "fademindist", a3: "-1");
          v15->KeyValue_4(this: v15, a2: "fademaxdist", a3: "0");
          v15->KeyValue_4(this: v15, a2: "fadescale", a3: "1");
          v15->KeyValue_4(this: v15, a2: "MinAnimTime", a3: "5");
          v15->KeyValue_4(this: v15, a2: "MaxAnimTime", a3: "10");
          v15->Precache(this: v15);
          DispatchSpawn(pEntity: v15, bRunVScripts: true);
          v15->Activate(this: v15);
        }
        CBaseEntity::SetAllowPrecache(allow: bAllowPrecache);
      }
      v8->EndLock(this: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0230
// Name: class CPhysicsProp __near * CreatePhysicsProp(char const __near *,class Vector const __near &,class Vector const __near &,class IHandleEntity const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
CPhysicsProp *__usercall CreatePhysicsProp@<eax>(
        IHandleEntity_vtbl *a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        const char *pModelName,
        const Vector *vTraceStart,
        const Vector *vTraceEnd,
        const IHandleEntity *pTraceIgnore,
        bool bRequireVCollide,
        const char *pClassName)
{
  IMDLCache *v9; // esi
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  unsigned __int16 v11; // ax
  int v12; // edi
  studiohdr_t *v14; // esi
  float z; // edx
  __int64 v16; // xmm0_8
  __int128 v17; // xmm0
  bool IsPrecacheAllowed; // al
  CBaseEntity *EntityByName; // eax
  CBaseEntity *v20; // esi
  char v22[12]; // [esp+34h] [ebp-294h] BYREF
  char buf[512]; // [esp+40h] [ebp-288h] BYREF
  _BYTE tr[88]; // [esp+240h] [ebp-88h] OVERLAPPED
  float v25; // [esp+298h] [ebp-30h]
  __int128 vecSweepMaxs; // [esp+29Ch] [ebp-2Ch] OVERLAPPED BYREF
  Vector vecSweepMins; // [esp+2ACh] [ebp-1Ch]
  IMDLCache *v28; // [esp+2B8h] [ebp-10h]
  IHandleEntity v29; // [esp+2BCh] [ebp-Ch] BYREF
  void *bAllowPrecache; // [esp+2C0h] [ebp-8h]
  void *retaddr; // [esp+2C8h] [ebp+0h]

  v29.__vftable = a1;
  bAllowPrecache = retaddr;
  v9 = mdlcache;
  BeginLock = mdlcache->BeginLock;
  v28 = mdlcache;
  ((void (__thiscall *)(IMDLCache *, int, int))BeginLock)(a1: mdlcache, a2, a3);
  v11 = mdlcache->FindMDL(this: mdlcache, a2: pModelName);
  v12 = v11;
  if ( v11 == 0xFFFF )
  {
    v9->EndLock(this: v9);
    return nullptr;
  }
  else
  {
    v14 = mdlcache->GetStudioHdr(this: mdlcache, a2: v11);
    if ( v14 == nullptr || bRequireVCollide && mdlcache->GetVCollide(this: mdlcache, a2: v12) == nullptr )
      goto LABEL_4;
    z = v14->hull_max.z;
    v16 = *(_QWORD *)&v14->hull_min.x;
    LODWORD(vecSweepMins.z) = &buf[500];
    vecSweepMins.y = 0.0;
    LODWORD(vecSweepMins.x) = pTraceIgnore;
    HIDWORD(vecSweepMaxs) = 33701899;
    v25 = z;
    *(_QWORD *)((char *)&vecSweepMaxs + 4) = v16;
    *(_QWORD *)&tr[80] = *(_QWORD *)&v14->hull_max.x;
    UTIL_TraceHull(
      a1: &v29,
      a2: (int)vTraceEnd,
      vecAbsStart: vTraceStart,
      vecAbsEnd: vTraceEnd,
      hullMin: (const Vector *)((char *)&vecSweepMaxs + 4),
      hullMax: (const Vector *)HIDWORD(v16),
      mask: 0x202400Bu,
      ignore: pTraceIgnore,
      collisionGroup: 0,
      ptr: (CGameTrace *)&buf[500]);
    if ( *(float *)&tr[32] == 1.0 )
    {
      v17 = 0;
      *(float *)&v17 = fsqrt(
                         (float)((float)((float)(vTraceEnd->y - vTraceStart->y) * (float)(vTraceEnd->y - vTraceStart->y))
                               + (float)((float)(vTraceEnd->z - vTraceStart->z) * (float)(vTraceEnd->z - vTraceStart->z)))
                       + (float)((float)(vTraceEnd->x - vTraceStart->x) * (float)(vTraceEnd->x - vTraceStart->x)));
      vecSweepMaxs = v17;
      if ( *(float *)&v17 > 0.01 )
        goto LABEL_4;
    }
    if ( tr[42] != 0 )
    {
LABEL_4:
      v28->EndLock(this: v28);
      return nullptr;
    }
    else
    {
      *(float *)tr = *(float *)&tr[12] + *(float *)tr;
      *(float *)&tr[4] = *(float *)&tr[16] + *(float *)&tr[4];
      *(float *)&tr[8] = *(float *)&tr[20] + *(float *)&tr[8];
      IsPrecacheAllowed = CBaseEntity::IsPrecacheAllowed();
      CBaseEntity::SetAllowPrecache(allow: IsPrecacheAllowed);
      vecSweepMins.z = 0.0;
      LODWORD(vecSweepMins.y) = &CPhysicsProp `RTTI Type Descriptor';
      LODWORD(vecSweepMins.x) = &CBaseEntity `RTTI Type Descriptor';
      HIDWORD(vecSweepMaxs) = 0;
      EntityByName = CreateEntityByName(className: pClassName, iForceEdictIndex: -1, bNotify: true);
      v20 = (CBaseEntity *)__RTDynamicCast(
                             inptr: EntityByName,
                             VfDelta: SHIDWORD(vecSweepMaxs),
                             SrcType: (void *)LODWORD(vecSweepMins.x),
                             TargetType: (void *)LODWORD(vecSweepMins.y),
                             isReference: SLODWORD(vecSweepMins.z));
      if ( v20 != nullptr )
      {
        V_snprintf(
          pDest: v22,
          maxLen: 512,
          pFormat: "%.10f %.10f %.10f",
          *(float *)tr,
          *(float *)&tr[4],
          *(float *)&tr[8]);
        v20->KeyValue_4(this: v20, a2: "origin", a3: v22);
        V_snprintf(pDest: v22, maxLen: 512, pFormat: "%.10f %.10f %.10f", 0.0, 0.0, 0.0);
        v20->KeyValue_4(this: v20, a2: "angles", a3: v22);
        v20->KeyValue_4(this: v20, a2: "model", a3: pModelName);
        v20->KeyValue_4(this: v20, a2: "fademindist", a3: "-1");
        v20->KeyValue_4(this: v20, a2: "fademaxdist", a3: "0");
        v20->KeyValue_4(this: v20, a2: "fadescale", a3: "1");
        v20->KeyValue_4(this: v20, a2: "inertiaScale", a3: "1.0");
        v20->KeyValue_4(this: v20, a2: "physdamagescale", a3: "0.1");
        v20->Precache(this: v20);
        DispatchSpawn(pEntity: v20, bRunVScripts: true);
        v20->Activate(this: v20);
      }
      CBaseEntity::SetAllowPrecache(allow: SLOBYTE(vecSweepMins.z));
      v28->EndLock(this: v28);
      return (CPhysicsProp *)v20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0570
// Name: void CC_Ent_Rotate(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Rotate(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  int v2; // eax
  CBaseEntity *v3; // esi
  bool v4; // zf
  double v5; // xmm0_8
  VMatrix newEntToWorld; // [esp+8h] [ebp-D4h] BYREF
  VMatrix entToWorld; // [esp+48h] [ebp-94h] BYREF
  VMatrix rot; // [esp+88h] [ebp-54h] BYREF
  long double v9; // [esp+C8h] [ebp-14h]
  QAngle angles; // [esp+D0h] [ebp-Ch] BYREF

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr )
  {
    v2 = (int)CommandClient->FindPickerEntity(this: CommandClient);
    v3 = (CBaseEntity *)v2;
    if ( v2 != 0 )
    {
      v4 = args->m_nArgc == 2;
      angles = *(QAngle *)(v2 + 712);
      if ( v4 )
      {
        v9 = atof(nptr: args->m_ppArgv[1]);
        v5 = v9;
      }
      else
      {
        v5 = 7.5;
      }
      MatrixBuildRotateZ(dst: &rot, angleDegrees: v5);
      MatrixFromAngles(vAngles: &angles, dst: &entToWorld);
      MatrixMultiply(src1: &entToWorld, src2: &rot, dst: &newEntToWorld);
      MatrixAngles(a1: (int)v3, src: &newEntToWorld, vAngles: &angles);
      CBaseEntity::SetLocalAngles(this: v3, &angles);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0670
// Name: public: char const __near * CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(CFmtStrN<80> *this, const char *pszFormat, ...)
{
  CFmtStrN<80> *v2; // esi
  bool v3; // zf
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  this->InitQuietTruncation(this);
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v2->m_szBuf, maxLen: 79, pFormat: pszFormat, params, pbTruncated: (bool *)&this + 3);
  v3 = HIBYTE(this) == 0;
  v2->m_szBuf[79] = 0;
  if ( !v3 && !v2->m_bQuietTruncation && `CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf'::`4'::scAsserted < 5 )
    ++`CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2->m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x101E07B0
// Name: public: virtual void CBreakableProp::Ignite(float,bool,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::Ignite(
        CBreakableProp *this,
        float flFlameLifetime,
        bool bNPCOnly,
        float flSize,
        bool bCalledByLevelDesigner)
{
  CBaseEntity *EffectEntity; // eax
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( (this->m_fFlags.m_Value & 0x10000000) == 0
    && this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_FIRE_FLAMMABLE) )
  {
    CBaseAnimating::Ignite(this, flFlameLifetime, bNPCOnly, flSize, bCalledByLevelDesigner);
    if ( g_pGameRules->ShouldBurningPropsEmitLight(this: g_pGameRules) )
    {
      EffectEntity = CBaseEntity::GetEffectEntity(this);
      CBaseEntity::AddEffects(this: EffectEntity, nEffects: 4);
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    CSoundEnt::InsertSound(
      iType: 8,
      vecOrigin: &this->m_vecAbsOrigin,
      iVolume: 128,
      flDuration: 1.0,
      pOwner: this,
      soundChannelIndex: 2,
      pSoundTarget: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0930
// Name: public: virtual void CBreakableProp::OnPhysGunPickup(class CBasePlayer __near *,enum PhysGunPickup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::OnPhysGunPickup(
        CBreakableProp *this,
        CBasePlayer *pPhysGunUser,
        PhysGunPickup_t reason)
{
  CBaseEntity *v4; // esi
  float reasona; // [esp+20h] [ebp+Ch]

  v4 = (CBreakableProp *)((char *)this - 1168);
  if ( reason != PICKED_UP_BY_CANNON )
  {
    CBaseEntity::ThinkSet(
      this: (CBreakableProp *)((char *)this - 1168),
      func: (void (__thiscall *)(CBaseEntity *))CBreakableProp::RampToDefaultFadeScale,
      thinkTime: gpGlobals->curtime + 2.0,
      szContext: s_pFadeScaleThink);
    if ( reason == PUNTED_BY_CANNON )
      v4->__vftable[1].Activate(this: v4);
  }
  else
  {
    CBaseEntity::SetGlobalFadeScale(this: (CBreakableProp *)((char *)this - 1168), flFadeScale: 0.0);
    CBaseEntity::ThinkSet(this: v4, func: nullptr, thinkTime: gpGlobals->curtime, szContext: s_pFadeScaleThink);
  }
  reasona = gpGlobals->curtime;
  if ( pPhysGunUser != nullptr )
    LODWORD(v4[1].m_vecVelocity.m_Value.y) = pPhysGunUser->GetRefEHandle(this: pPhysGunUser)->m_Index;
  else
    v4[1].m_vecVelocity.m_Value.y = NAN;
  v4[1].m_vecVelocity.m_Value.z = reasona;
  LOBYTE(this->m_nModelIndex.m_Value) = CBaseEntity::BlocksLOS(this: v4);
  CBaseEntity::SetBlocksLOS(this: v4, bBlocksLOS: false);
}

//------------------------------------------------------------------------------
// Address: 0x101E0A10
// Name: public: virtual void CBreakableProp::OnPhysGunDrop(class CBasePlayer __near *,enum PhysGunDrop_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::OnPhysGunDrop(CBreakableProp *this, CBasePlayer *pPhysGunUser, PhysGunDrop_t Reason)
{
  float curtime; // [esp+10h] [ebp-4h]

  CBaseEntity::ThinkSet(
    this: (CBreakableProp *)((char *)this - 1168),
    func: (void (__thiscall *)(CBaseEntity *))CBreakableProp::RampToDefaultFadeScale,
    thinkTime: gpGlobals->curtime + 2.0,
    szContext: s_pFadeScaleThink);
  curtime = gpGlobals->curtime;
  if ( pPhysGunUser != nullptr )
    this->m_pLink = (CBaseEntity *)pPhysGunUser->GetRefEHandle(this: pPhysGunUser)->m_Index;
  else
    this->m_pLink = (CBaseEntity *)-1;
  *(float *)&this->m_target.pszValue = curtime;
  if ( Reason == THROWN_BY_PLAYER )
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 292) + 920))(a1: (char *)this - 1168);
  CBaseEntity::SetBlocksLOS(this: (CBreakableProp *)((char *)this - 1168), bBlocksLOS: this->m_nModelIndex.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x101E0AC0
// Name: public: virtual bool CDynamicProp::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CDynamicProp::CreateVPhysics@<al>(CDynamicProp *this@<ecx>, int a2@<ebp>)
{
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ebx
  CBoneFollowerManager *p_m_BoneFollowerManager; // edi
  int i; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  p_m_Collision = &this->m_Collision;
  if ( this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_NONE
    || (p_m_Collision->GetSolidFlags(this: p_m_Collision) & 4) != 0 && (this->m_spawnflags.m_Value & 0x80) != 0 )
  {
    return 1;
  }
  if ( !this->m_bDisableBoneFollowers )
    CDynamicProp::CreateBoneFollowers(this);
  p_m_BoneFollowerManager = &this->m_BoneFollowerManager;
  if ( this->m_BoneFollowerManager.m_iNumBones == 0 )
  {
    CBaseEntity::VPhysicsInitStatic(this, a2);
    return 1;
  }
  if ( (p_m_Collision->GetSolidFlags(this: p_m_Collision) & 4) != 0 )
  {
    for ( i = 0; i < p_m_BoneFollowerManager->m_iNumBones; ++i )
    {
      m_Index = CBoneFollowerManager::GetBoneFollower(this: p_m_BoneFollowerManager, iFollowerIndex: i)->hFollower.m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr )
          CCollisionProperty::SetSolidFlags(
            this: (CCollisionProperty *)&m_pEntity[57],
            flags: LOWORD(m_pEntity[65].__vftable) | 4);
      }
    }
  }
  CCollisionProperty::SetSolidFlags(this: p_m_Collision, flags: p_m_Collision->m_usSolidFlags.m_Value | 4);
  CCollisionProperty::SetSolidFlags(this: p_m_Collision, flags: p_m_Collision->m_usSolidFlags.m_Value | 3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E0BC0
// Name: public: virtual bool CDynamicProp::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDynamicProp::TestCollision(CDynamicProp *this, const Ray_t *ray, unsigned int mask, CGameTrace *trace)
{
  unsigned __int16 m_Value; // ax
  int v6; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  m_Value = this->m_Collision.m_usSolidFlags.m_Value;
  if ( (m_Value & 4) == 0 )
    return CBaseAnimating::TestCollision(this, ray, fContentsMask: mask, tr: trace);
  if ( (m_Value & 2) == 0 )
    return CBaseAnimating::TestCollision(this, ray, fContentsMask: mask, tr: trace);
  if ( (this->m_Collision.m_usSolidFlags.m_Value & 1) == 0 )
    return CBaseAnimating::TestCollision(this, ray, fContentsMask: mask, tr: trace);
  v6 = 0;
  if ( this->m_BoneFollowerManager.m_iNumBones <= 0 )
    return CBaseAnimating::TestCollision(this, ray, fContentsMask: mask, tr: trace);
  while ( 1 )
  {
    m_Index = CBoneFollowerManager::GetBoneFollower(this: &this->m_BoneFollowerManager, iFollowerIndex: v6)->hFollower.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr
        && ((unsigned __int8 (__thiscall *)(IHandleEntity *, const Ray_t *, unsigned int, CGameTrace *))m_pEntity->__vftable[4].GetRefEHandle)(
             a1: m_pEntity,
             a2: ray,
             a3: mask,
             a4: trace) != 0 )
      {
        break;
      }
    }
    if ( ++v6 >= this->m_BoneFollowerManager.m_iNumBones )
      return CBaseAnimating::TestCollision(this, ray, fContentsMask: mask, tr: trace);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E0C70
// Name: public: virtual class IPhysicsObject __near * CDynamicProp::GetRootPhysicsObjectForBreak(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CDynamicProp::GetRootPhysicsObjectForBreak(CDynamicProp *this)
{
  bool v2; // zf
  CBoneFollowerManager *p_m_BoneFollowerManager; // ecx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  v2 = this->m_BoneFollowerManager.m_iNumBones == 0;
  p_m_BoneFollowerManager = &this->m_BoneFollowerManager;
  if ( v2 )
    return this->m_pPhysicsObject;
  m_Index = CBoneFollowerManager::GetBoneFollower(this: p_m_BoneFollowerManager, iFollowerIndex: 0)->hFollower.m_Index;
  if ( m_Index == -1 )
    return this->m_pPhysicsObject;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return this->m_pPhysicsObject;
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == nullptr )
    return this->m_pPhysicsObject;
  else
    return (IPhysicsObject *)m_pEntity[82].__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x101E0CD0
// Name: public: virtual void CDynamicProp::HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::HandleAnimEvent(CDynamicProp *this, animevent_t *pEvent)
{
  int event_lowword; // eax
  int v4; // eax

  if ( (pEvent->type & 0x400) != 0 )
    event_lowword = pEvent->_event_lowword;
  else
    event_lowword = *(_DWORD *)&pEvent->_event_highword;
  v4 = event_lowword - 1004;
  if ( v4 != 0 )
  {
    if ( v4 == 96 )
    {
      ((void (__thiscall *)(CDynamicProp *, const char *, CDynamicProp *, CDynamicProp *, _DWORD))this->AcceptInput)(
        a1: this,
        a2: pEvent->options,
        a3: this,
        a4: this,
        a5: 0);
      return;
    }
  }
  else
  {
    CBaseEntity::EmitSound(this, soundname: pEvent->options, soundtime: 0.0, duration: nullptr);
  }
  CBaseAnimating::HandleAnimEvent(this, pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x101E0D60
// Name: public: void CDynamicProp::InputDisableCollision(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::InputDisableCollision(CDynamicProp *this, inputdata_t *inputdata)
{
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
}

//------------------------------------------------------------------------------
// Address: 0x101E0D80
// Name: public: void CDynamicProp::InputEnableCollision(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::InputEnableCollision(CDynamicProp *this, inputdata_t *inputdata)
{
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
}

//------------------------------------------------------------------------------
// Address: 0x101E0DA0
// Name: public: void COrnamentProp::InputDetach(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COrnamentProp::InputDetach(COrnamentProp *this, inputdata_t *inputdata)
{
  this->SetOwnerEntity(this, a2: nullptr);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x101E0DE0
// Name: bool PropIsGib(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PropIsGib(CBaseEntity *pEntity)
{
  return pEntity != nullptr
      && (pEntity->m_iClassname.pszValue == "prop_physics"
       || CBaseEntity::ClassMatchesComplex(this: pEntity, pszClassOrWildcard: "prop_physics") != 0)
      && (pEntity->m_spawnflags.m_Value & 0x400000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E0E20
// Name: public: virtual CPhysicsProp::~CPhysicsProp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::~CPhysicsProp(CPhysicsProp *this)
{
  this->CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPhysicsProp_vtbl *)&CPhysicsProp::`vftable'{for `CBaseProp'};
  this->CBreakableProp::IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CPhysicsProp::`vftable'{for `IBreakableWithPropData'};
  this->CBreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPhysicsProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->INavAvoidanceObstacle::__vftable = (INavAvoidanceObstacle_vtbl *)&CPhysicsProp::`vftable';
  CNavMesh::UnregisterAvoidanceObstacle(this: TheNavMesh, obstruction: &this->INavAvoidanceObstacle);
  if ( (this->m_spawnflags.m_Value & 0x400000) != 0 )
    --g_ActiveGibCount;
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnOutOfWorld);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPlayerPickup);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPlayerUse);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysGunDrop);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysGunOnlyPickup);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysGunPunt);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysGunPickup);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnAwakened);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_MotionEnabled);
  CBreakableProp::~CBreakableProp(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E0EE0
// Name: public: virtual int CPhysicsProp::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsProp::ObjectCaps(CPhysicsProp *this)
{
  vgui::ToggleButton *v2; // ecx
  int v3; // esi

  v3 = CBaseEntity::ObjectCaps(this) | 0x40000000;
  if ( (this->m_spawnflags.m_Value & 0x100) != 0 )
  {
    v3 |= 1u;
  }
  else if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: v2) )
  {
    v3 |= 1u;
    if ( hl2_episodic.m_pParent != nullptr
      && hl2_episodic.m_pParent->m_Value.m_nValue != 0
      && this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_CREATE_FLARE) )
    {
      v3 |= 0x20u;
    }
  }
  if ( (this->m_spawnflags.m_Value & 0x4000) != 0 )
    return v3 | 0x20;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101E0F70
// Name: public: virtual void CPhysicsProp::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::Use(
        CPhysicsProp *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( pActivator != nullptr && pActivator->IsPlayer(this: pActivator) )
  {
    if ( (this->m_spawnflags.m_Value & 0x100) != 0 )
      COutputEvent::FireOutput(this: &this->m_OnPlayerUse, pActivator: this, pCaller: this, fDelay: 0.0);
    ((void (__thiscall *)(CBaseEntity *, CPhysicsProp *, int))pActivator->__vftable[2].NetworkStateChanged_m_nNextThinkTick)(
      a1: pActivator,
      a2: this,
      a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0FD0
// Name: public: bool CPhysicsProp::ShouldDisableMotionOnFreeze(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CPhysicsProp::ShouldDisableMotionOnFreeze@<al>(CPhysicsProp *this@<ecx>, int a2@<edi>)
{
  float curtime; // xmm0_4
  IPhysicsObject *m_pPhysicsObject; // edi
  int v5; // esi
  int v6; // eax
  void *v7; // eax
  _BYTE *v8; // eax
  int v10; // [esp-8h] [ebp-8h]

  curtime = gpGlobals->curtime;
  if ( this->m_fNextCheckDisableMotionContactsTime > curtime )
    return 0;
  m_pPhysicsObject = this->m_pPhysicsObject;
  this->m_fNextCheckDisableMotionContactsTime = curtime + 0.5;
  v5 = ((int (__thiscall *)(IPhysicsObject *, int))m_pPhysicsObject->CreateFrictionSnapshot)(a1: m_pPhysicsObject, a2);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5) != 0 )
  {
    while ( 1 )
    {
      v6 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 8))(a1: v5, a2: 1);
      v7 = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 68))(a1: v6);
      v8 = __RTDynamicCast(
             inptr: v7,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CPhysicsProp `RTTI Type Descriptor',
             isReference: 0);
      if ( v8 != nullptr && (v8[762] & 1) == 0 )
        return 0;
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 48))(a1: v5, a2: v10);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5) == 0 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    m_pPhysicsObject->DestroyFrictionSnapshot(this: m_pPhysicsObject, a2: (IPhysicsFrictionSnapshot *)v5);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1090
// Name: public: virtual bool CPhysicsProp::IsPotentiallyAbleToObstructNavAreas(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsProp::IsPotentiallyAbleToObstructNavAreas(CPhysicsProp *this)
{
  CCollisionProperty *v1; // esi
  int v3; // ecx
  Extent extent; // [esp+4h] [ebp-1Ch] BYREF
  float v5; // [esp+1Ch] [ebp-4h]

  v1 = (CCollisionProperty *)((char *)this - 1284);
  if ( *((_BYTE *)this - 1250) == 0 )
    return false;
  if ( (v1->m_usSolidFlags.m_Value & 4) != 0 )
    return false;
  if ( (*((_BYTE *)this - 1252) & 4) != 0 )
    return false;
  v3 = *((_DWORD *)this - 296);
  if ( v3 == 0 )
    return false;
  v5 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v3 + 116))(a1: v3);
  if ( v5 <= 100.0 )
    return false;
  CCollisionProperty::CollisionAABBToWorldAABB(
    this: v1,
    entityMins: &v1->m_vecMins.m_Value,
    entityMaxs: &v1->m_vecMaxs.m_Value,
    pWorldMins: &extent.lo,
    pWorldMaxs: &extent.hi);
  return (float)((float)((float)((float)(extent.hi.x - extent.lo.x) * (float)(extent.hi.x - extent.lo.x))
                       + (float)((float)(extent.hi.y - extent.lo.y) * (float)(extent.hi.y - extent.lo.y)))
               + (float)((float)(extent.hi.z - extent.lo.z) * (float)(extent.hi.z - extent.lo.z))) > 324.0;
}

//------------------------------------------------------------------------------
// Address: 0x101E1150
// Name: public: virtual float CPhysicsProp::GetNavObstructionHeight(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsProp::GetNavObstructionHeight(CPhysicsProp *this)
{
  Extent extent; // [esp+0h] [ebp-18h] BYREF

  CCollisionProperty::CollisionAABBToWorldAABB(
    this: (CCollisionProperty *)((char *)this - 1284),
    entityMins: (const Vector *)&this->m_pfnThink - 107,
    entityMaxs: (const Vector *)&this->m_Network.m_pOuter - 107,
    pWorldMins: &extent.lo,
    pWorldMaxs: &extent.hi);
  return extent.hi.z - extent.lo.z;
}

//------------------------------------------------------------------------------
// Address: 0x101E1180
// Name: public: virtual bool CPhysicsProp::CanObstructNavAreas(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsProp::CanObstructNavAreas(CPhysicsProp *this)
{
  bool result; // al
  int v3; // ecx
  CCollisionProperty *v4; // ecx
  Extent extent; // [esp+4h] [ebp-1Ch] BYREF
  float v6; // [esp+1Ch] [ebp-4h]

  result = false;
  if ( LOBYTE(this->m_Collision.m_usSolidFlags.m_Value) == 0 )
  {
    v3 = *((_DWORD *)this - 296);
    if ( v3 != 0 )
    {
      v6 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v3 + 116))(a1: v3);
      if ( v6 > 100.0 )
      {
        v4 = (CCollisionProperty *)((char *)this - 1284);
        if ( *((_BYTE *)this - 1250) != 0 && (v4->m_usSolidFlags.m_Value & 4) == 0 && (*((_BYTE *)this - 1252) & 4) == 0 )
        {
          CCollisionProperty::CollisionAABBToWorldAABB(
            this: v4,
            entityMins: &v4->m_vecMins.m_Value,
            entityMaxs: &v4->m_vecMaxs.m_Value,
            pWorldMins: &extent.lo,
            pWorldMaxs: &extent.hi);
          if ( (float)(extent.hi.z - extent.lo.z) >= 18.0
            && (*((int *)this - 246) >= 300 || *((_BYTE *)this - 958) != 2) )
          {
            return true;
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E1230
// Name: public: virtual int CPhysicsProp::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsProp::DrawDebugTextOverlays(CPhysicsProp *this)
{
  int result; // eax
  int v3; // edi
  IPhysicsObject *m_pPhysicsObject; // ebx
  const char *MassEquivalent; // eax
  double v6; // st7
  double v7; // st7
  int v8; // edi
  double v9; // st7
  int v10; // edi
  int v11; // eax
  int v12; // edi
  double v13; // [esp+Ch] [ebp-224h]
  float flMass; // [esp+14h] [ebp-21Ch]
  const char *flMassa; // [esp+14h] [ebp-21Ch]
  char tempstr[512]; // [esp+24h] [ebp-20Ch] BYREF
  vphysics_objectstress_t stressOut; // [esp+224h] [ebp-Ch] BYREF

  result = CBaseAnimating::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 && this->m_pPhysicsObject != nullptr )
  {
    m_pPhysicsObject = this->m_pPhysicsObject;
    flMass = m_pPhysicsObject->GetMass(this: m_pPhysicsObject);
    MassEquivalent = GetMassEquivalent(flMass);
    v6 = ((double (__thiscall *)(IPhysicsObject *, const char *))m_pPhysicsObject->GetMass)(
           a1: m_pPhysicsObject,
           a2: MassEquivalent);
    v7 = ((double (__thiscall *)(IPhysicsObject *, _DWORD, _DWORD))m_pPhysicsObject->GetMass)(
           a1: m_pPhysicsObject,
           a2: COERCE_UNSIGNED_INT64(v6 * 2.2),
           a3: HIDWORD(COERCE_UNSIGNED_INT64(v6 * 2.2)));
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Mass: %.2f kg / %.2f lb (%s)", v7, v13, flMassa);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v8 = v3 + 1;
    v9 = CalculateObjectStress(pObject: this->m_pPhysicsObject, pInputOwnerEntity: this, pOutput: &stressOut);
    V_snprintf(
      pDest: tempstr,
      maxLen: 512,
      pFormat: "Stress: %.2f (%.2f / %.2f)",
      v9,
      stressOut.exertedStress,
      stressOut.receivedStress);
    CBaseEntity::EntityText(this, text_offset: v8, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v10 = v8 + 1;
    if ( !this->m_pPhysicsObject->IsMoveable(this: this->m_pPhysicsObject) )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Motion Disabled");
      CBaseEntity::EntityText(this, text_offset: v10++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    if ( this->m_iszBasePropData.pszValue != nullptr )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Base PropData: %s", this->m_iszBasePropData.pszValue);
      CBaseEntity::EntityText(this, text_offset: v10++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    if ( this->m_iNumBreakableChunks != 0 )
    {
      v11 = this->GetMaxBreakableSize(this: &this->IBreakableWithPropData);
      V_snprintf(
        pDest: tempstr,
        maxLen: 512,
        pFormat: "Breakable Chunks: %d (Max Size %d)",
        this->m_iNumBreakableChunks,
        v11);
      CBaseEntity::EntityText(this, text_offset: v10++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Skin: %d", this->m_nSkin.m_Value);
    CBaseEntity::EntityText(this, text_offset: v10, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v12 = v10 + 1;
    V_snprintf(
      pDest: tempstr,
      maxLen: 512,
      pFormat: "Health: %d, collision group %d",
      this->m_iHealth.m_Value,
      this->m_CollisionGroup.m_Value);
    CBaseEntity::EntityText(this, text_offset: v12, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v12 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E1520
// Name: bool PropBreakableCapEdictsOnCreateAll(class CUtlVector<struct breakmodel_t,class CUtlMemory<struct breakmodel_t,int>> __near &,class IPhysicsObject __near *,struct breakablepropparams_t const __near &,class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PropBreakableCapEdictsOnCreateAll(
        CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int> > *list,
        IPhysicsObject *pPhysics,
        const breakablepropparams_t *params,
        CBaseEntity *pEntity,
        int iPrecomputedBreakableCount)
{
  int v5; // edi
  int m_Size; // eax
  int v7; // edi
  int v8; // esi
  void *v9; // eax
  void *v10; // esi
  int nCurrentEntityCount; // [esp+Ch] [ebp-8h]
  int numToCreate; // [esp+10h] [ebp-4h]

  v5 = engine->GetEntityCount(this: engine);
  m_Size = iPrecomputedBreakableCount;
  nCurrentEntityCount = v5;
  numToCreate = 0;
  if ( iPrecomputedBreakableCount != -1 )
    goto LABEL_15;
  m_Size = list->m_Size;
  if ( m_Size == 0 )
  {
    if ( pEntity == nullptr )
      return true;
    v9 = __RTDynamicCast(
           inptr: pEntity,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &IBreakableWithPropData `RTTI Type Descriptor',
           isReference: 0);
    v10 = v9;
    if ( v9 == nullptr
      || *(_DWORD *)(*(int (__thiscall **)(void *, int *))(*(_DWORD *)v9 + 56))(a1: v9, a2: &iPrecomputedBreakableCount) == 0
      || (*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 72))(a1: v10) == 0 )
    {
      return true;
    }
    m_Size = (*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 72))(a1: v10);
    goto LABEL_15;
  }
  if ( 1984 - v5 > m_Size )
  {
LABEL_15:
    numToCreate = m_Size;
    return numToCreate == 0 || numToCreate + v5 + 64 < 2048;
  }
  v7 = 0;
  if ( m_Size <= 0 )
    return true;
  v8 = 0;
  do
  {
    if ( modelinfo->GetModelIndex(this: modelinfo, a2: list->m_Memory.m_pMemory[v8].modelName) > 0 )
      ++numToCreate;
    ++v7;
    ++v8;
  }
  while ( v7 < list->m_Size );
  v5 = nCurrentEntityCount;
  return numToCreate == 0 || numToCreate + v5 + 64 < 2048;
}

//------------------------------------------------------------------------------
// Address: 0x101E1620
// Name: public: virtual int CBasePropDoor::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePropDoor::ObjectCaps(CBasePropDoor *this)
{
  unsigned int v1; // ebx

  v1 = (unsigned int)this->m_spawnflags.m_Value >> 15;
  return ((v1 & 1) != 0 ? 0 : 0x21) | CBaseEntity::ObjectCaps(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E1640
// Name: protected: void CBasePropDoor::UpdateAreaPortals(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::UpdateAreaPortals(CBasePropDoor *this, bool isOpen)
{
  const char *pszValue; // ebx
  CBaseEntity *i; // esi

  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: "AreaPortal");
  if ( !this->IsAbleToCloseAreaPortals(this) )
    isOpen = true;
  pszValue = this->m_iName.m_Value.pszValue;
  if ( pszValue != nullptr )
  {
    for ( i = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: "func_areaportal");
          i != nullptr;
          i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "func_areaportal") )
    {
      if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *, const char *))i->HasTarget)(a1: i, a2: pszValue) != 0 )
        ((void (__thiscall *)(CBaseEntity *, CBasePropDoor *, CBasePropDoor *, bool, _DWORD))i->Use)(
          a1: i,
          a2: this,
          a3: this,
          a4: isOpen,
          a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E16E0
// Name: private: void CBasePropDoor::InputUnlock(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __userpurge CBasePropDoor::InputUnlock(CBasePropDoor *this@<ecx>, int a2@<ebp>, inputdata_t *inputdata)
{
  CBasePropDoor::Unlock(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101E16F0
// Name: private: virtual void CBasePropDoor::Blocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::Blocked(CBasePropDoor *this, CBaseEntity *pOther)
{
  const CTakeDamageInfo *v2; // eax
  CTakeDamageInfo v3; // [esp+14h] [ebp-5Ch] BYREF

  if ( this->m_bForceClosed )
  {
    if ( pOther->m_MoveType.m_Value == 6 && pOther->m_takedamage.m_Value <= 1u )
    {
      EntityPhysics_CreateSolver(
        pMovingEntity: this,
        pPhysicsObject: pOther,
        disableCollisions: true,
        separationDuration: 4.0);
    }
    else if ( pOther->m_MoveType.m_Value == 6 && pOther->m_takedamage.m_Value == 2 )
    {
      v2 = CTakeDamageInfo::CTakeDamageInfo(
             this: &v3,
             pInflictor: this,
             pAttacker: this,
             flDamage: (float)pOther->m_iHealth.m_Value,
             bitsDamageType: 1,
             iKillType: 0,
             iObjectsPenetrated: 0);
      CBaseEntity::TakeDamage(this: pOther, a2: (int)pOther, inputInfo: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1790
// Name: private: virtual void CBasePropDoor::EndBlocked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::EndBlocked(CBasePropDoor *this)
{
  CBaseEntityList *v1; // ebx
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  int m_Size; // edx
  int i; // edi
  unsigned int v12; // eax
  IHandleEntity *m_pEntity; // ecx
  const char *pszValue; // eax
  COutputEvent *p_m_OnUnblockedClosing; // ecx
  int v16; // [esp+10h] [ebp-4h]

  v1 = g_pEntityList;
  m_Index = this->m_hMaster.m_Index;
  if ( m_Index != -1
    && (v4 = (unsigned __int16)m_Index,
        v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v6 = HIWORD(m_Index),
        v5->m_SerialNumber == v6)
    && v5->m_pEntity != nullptr )
  {
    v7 = v4;
    v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
    v9 = &g_pEntityList->m_EntPtrArray[v7];
    if ( v8 )
      v9->m_pEntity->__vftable[35].dtr_IHandleEntity(this: v9->m_pEntity);
    else
      (*(void (__thiscall **)(_DWORD))(MEMORY[0] + 420))(a1: 0);
  }
  else
  {
    m_Size = this->m_hDoorList.m_Size;
    v16 = m_Size;
    if ( m_Size > 0 )
    {
      for ( i = 0; i < m_Size; ++i )
      {
        v12 = this->m_hDoorList.m_Memory.m_pMemory[i].m_Index;
        if ( v12 != -1 && v1->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == HIWORD(v12) )
        {
          m_pEntity = v1->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
          if ( m_pEntity != nullptr && LOBYTE(m_pEntity[427].__vftable) == 0 )
          {
            m_pEntity->__vftable[82].dtr_IHandleEntity(this: m_pEntity);
            v1 = g_pEntityList;
            m_Size = v16;
          }
        }
      }
    }
    if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
    {
      pszValue = this->m_SoundMoving.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      CBaseEntity::EmitSound(this, soundname: pszValue, soundtime: 0.0, duration: nullptr);
    }
    p_m_OnUnblockedClosing = &this->m_OnUnblockedClosing;
    if ( this->m_eDoorState != DOOR_STATE_CLOSING )
      p_m_OnUnblockedClosing = &this->m_OnUnblockedOpening;
    COutputEvent::FireOutput(this: p_m_OnUnblockedClosing, pActivator: this, pCaller: this, fDelay: 0.0);
    if ( !this->m_bFirstBlocked )
      this->DoorResume(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E18D0
// Name: public: virtual void CPropDoorRotating::OnDoorOpened(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPropDoorRotating::OnDoorOpened(CPropDoorRotating *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *v10; // eax
  unsigned int v11; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity *v13; // edi
  IHandleEntity *v14; // ecx
  IHandleEntity *v15; // esi
  const Vector *v16; // eax
  const Vector *v17; // [esp-14h] [ebp-24h]

  m_Index = this->m_hDoorBlocker.m_Index;
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
      v10 = v8 ? v9->m_pEntity : nullptr;
      CCollisionProperty::SetSolidFlags(this: (CCollisionProperty *)&v10[57], flags: LOWORD(v10[65].__vftable) | 4);
      if ( g_debug_doors.m_pParent != nullptr && g_debug_doors.m_pParent->m_Value.m_nValue != 0 )
      {
        v11 = this->m_hDoorBlocker.m_Index;
        if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
        v13 = m_pEntity + 57;
        if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
          v14 = nullptr;
        else
          v14 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
        v15 = v14 + 57;
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2);
        v17 = (const Vector *)v13->GetRefEHandle(this: v13);
        v16 = (const Vector *)((int (__thiscall *)(IHandleEntity *))v15->SetRefEHandle)(a1: v15);
        NDebugOverlay::Box(
          origin: &this->m_vecAbsOrigin,
          mins: v16,
          maxs: v17,
          r: 0,
          g: 255,
          b: 0,
          a: 1,
          flDuration: 1.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1A10
// Name: public: virtual void CPropDoorRotating::OnDoorClosed(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPropDoorRotating::OnDoorClosed(CPropDoorRotating *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  CBaseEntity *v10; // eax
  unsigned int v11; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity *v13; // edi
  IHandleEntity *v14; // ecx
  IHandleEntity *v15; // esi
  const Vector *v16; // eax
  const Vector *v17; // [esp-14h] [ebp-24h]

  m_Index = this->m_hDoorBlocker.m_Index;
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
      v10 = v8 ? (CBaseEntity *)v9->m_pEntity : nullptr;
      UTIL_Remove(oldObj: v10);
      if ( g_debug_doors.m_pParent != nullptr && g_debug_doors.m_pParent->m_Value.m_nValue != 0 )
      {
        v11 = this->m_hDoorBlocker.m_Index;
        if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
        v13 = m_pEntity + 57;
        if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
          v14 = nullptr;
        else
          v14 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
        v15 = v14 + 57;
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2);
        v17 = (const Vector *)v13->GetRefEHandle(this: v13);
        v16 = (const Vector *)((int (__thiscall *)(IHandleEntity *))v15->SetRefEHandle)(a1: v15);
        NDebugOverlay::Box(
          origin: &this->m_vecAbsOrigin,
          mins: v16,
          maxs: v17,
          r: 0,
          g: 255,
          b: 0,
          a: 1,
          flDuration: 1.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1B40
// Name: private: void CPropDoorRotating::CalculateDoorVolume(class QAngle,class QAngle,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::CalculateDoorVolume(
        CPropDoorRotating *this,
        QAngle closedAngles,
        QAngle openAngles,
        Vector *destMins,
        Vector *destMaxs)
{
  float z; // eax
  float x; // xmm0_4
  Vector *v8; // edi
  float y; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  Vector *v15; // ebx
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  QAngle saveAngles; // [esp+8h] [ebp-3Ch] BYREF
  Vector openMaxs; // [esp+14h] [ebp-30h] BYREF
  Vector closedMaxs; // [esp+20h] [ebp-24h] BYREF
  Vector closedMins; // [esp+2Ch] [ebp-18h] BYREF
  Vector openMins; // [esp+38h] [ebp-Ch] BYREF
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  z = this->m_angRotation.m_Value.z;
  *(_QWORD *)&saveAngles.x = *(_QWORD *)&this->m_angRotation.m_Value.x;
  saveAngles.z = z;
  CBaseEntity::SetLocalAngles(this, angles: &closedAngles);
  CCollisionProperty::CollisionAABBToWorldAABB(
    this: &this->m_Collision,
    entityMins: &this->m_Collision.m_vecMins.m_Value,
    entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
    pWorldMins: &closedMins,
    pWorldMaxs: &closedMaxs);
  CBaseEntity::SetLocalAngles(this, angles: &openAngles);
  CCollisionProperty::CollisionAABBToWorldAABB(
    this: &this->m_Collision,
    entityMins: &this->m_Collision.m_vecMins.m_Value,
    entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
    pWorldMins: &openMins,
    pWorldMaxs: &openMaxs);
  CBaseEntity::SetLocalAngles(this, angles: &saveAngles);
  x = openMins.x;
  if ( openMins.x > closedMins.x )
    x = closedMins.x;
  v8 = destMins;
  y = closedMins.y;
  destMins->x = x;
  v10 = openMins.y;
  if ( openMins.y > y )
    v10 = y;
  v11 = closedMins.z;
  v8->y = v10;
  v12 = openMins.z;
  if ( openMins.z > v11 )
    v12 = v11;
  v13 = openMaxs.x;
  v8->z = v12;
  v14 = closedMaxs.x;
  if ( closedMaxs.x <= v13 )
    v14 = v13;
  v15 = destMaxs;
  v16 = openMaxs.y;
  destMaxs->x = v14;
  v17 = closedMaxs.y;
  if ( closedMaxs.y <= v16 )
    v17 = v16;
  v18 = openMaxs.z;
  v15->y = v17;
  v19 = closedMaxs.z;
  if ( closedMaxs.z <= v18 )
    v19 = v18;
  v15->z = v19;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v8->x = v8->x - this->m_vecAbsOrigin.x;
  v8->y = v8->y - this->m_vecAbsOrigin.y;
  v8->z = v8->z - this->m_vecAbsOrigin.z;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v15->x = v15->x - this->m_vecAbsOrigin.x;
  v15->y = v15->y - this->m_vecAbsOrigin.y;
  v15->z = v15->z - this->m_vecAbsOrigin.z;
}

//------------------------------------------------------------------------------
// Address: 0x101E1CF0
// Name: public: virtual void CPropDoorRotating::ComputeDoorExtent(struct Extent __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::ComputeDoorExtent(CPropDoorRotating *this, Extent *extent, char extentType)
{
  Extent openExtent; // [esp+Ch] [ebp-18h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF
  QAngle m_angRotationClosed; // 0:^C.12

  if ( extent != nullptr )
  {
    if ( (extentType & 2) != 0 )
    {
      m_angRotationClosed = this->m_angRotationClosed;
      CPropDoorRotating::CalculateDoorVolume(
        this,
        closedAngles: m_angRotationClosed,
        openAngles: m_angRotationClosed,
        destMins: &extent->lo,
        destMaxs: &extent->hi);
      if ( (extentType & 1) != 0 )
      {
        if ( this->m_vecBackBoundsMin.x <= this->m_vecForwardBoundsMin.x )
          openExtent.lo.x = this->m_vecBackBoundsMin.x;
        else
          openExtent.lo.x = this->m_vecForwardBoundsMin.x;
        if ( this->m_vecBackBoundsMin.y <= this->m_vecForwardBoundsMin.y )
          openExtent.lo.y = this->m_vecBackBoundsMin.y;
        else
          openExtent.lo.y = this->m_vecForwardBoundsMin.y;
        if ( this->m_vecBackBoundsMin.z <= this->m_vecForwardBoundsMin.z )
          openExtent.lo.z = this->m_vecBackBoundsMin.z;
        else
          openExtent.lo.z = this->m_vecForwardBoundsMin.z;
        if ( this->m_vecForwardBoundsMax.x <= this->m_vecBackBoundsMax.x )
          openExtent.hi.x = this->m_vecBackBoundsMax.x;
        else
          openExtent.hi.x = this->m_vecForwardBoundsMax.x;
        if ( this->m_vecForwardBoundsMax.y <= this->m_vecBackBoundsMax.y )
          openExtent.hi.y = this->m_vecBackBoundsMax.y;
        else
          openExtent.hi.y = this->m_vecForwardBoundsMax.y;
        if ( this->m_vecForwardBoundsMax.z <= this->m_vecBackBoundsMax.z )
          openExtent.hi.z = this->m_vecBackBoundsMax.z;
        else
          openExtent.hi.z = this->m_vecForwardBoundsMax.z;
        Extent::Encompass(this: extent, extent: &openExtent);
      }
    }
    else if ( (extentType & 1) != 0 )
    {
      UTIL_ComputeAABBForBounds(
        mins1: &this->m_vecForwardBoundsMin,
        maxs1: &this->m_vecForwardBoundsMax,
        mins2: &this->m_vecBackBoundsMin,
        maxs2: &this->m_vecBackBoundsMax,
        destMins: &extent->lo,
        destMaxs: &extent->hi);
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    extent->lo.x = extent->lo.x + this->m_vecAbsOrigin.x;
    extent->lo.y = extent->lo.y + this->m_vecAbsOrigin.y;
    extent->lo.z = extent->lo.z + this->m_vecAbsOrigin.z;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    extent->hi.x = extent->hi.x + this->m_vecAbsOrigin.x;
    extent->hi.y = this->m_vecAbsOrigin.y + extent->hi.y;
    extent->hi.z = extent->hi.z + this->m_vecAbsOrigin.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1F00
// Name: public: virtual void CPropDoorRotating::DoorTeleportToSpawnPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::DoorTeleportToSpawnPosition(CPropDoorRotating *this)
{
  PropDoorRotatingSpawnPos_t m_eSpawnPosition; // eax
  float z; // xmm0_4
  float v3; // xmm0_4
  QAngle angSpawn; // [esp+0h] [ebp-Ch] BYREF

  if ( (this->m_spawnflags.m_Value & 1) != 0 || (m_eSpawnPosition = this->m_eSpawnPosition) == DOOR_SPAWN_OPEN_FORWARD )
  {
    angSpawn.x = this->m_angRotationOpenForward.x;
    angSpawn.y = this->m_angRotationOpenForward.y;
    z = this->m_angRotationOpenForward.z;
    goto LABEL_10;
  }
  if ( m_eSpawnPosition == DOOR_SPAWN_OPEN_BACK )
  {
    angSpawn.x = this->m_angRotationOpenBack.x;
    angSpawn.y = this->m_angRotationOpenBack.y;
    z = this->m_angRotationOpenBack.z;
LABEL_10:
    this->m_eDoorState = DOOR_STATE_OPEN;
    angSpawn.z = z;
    CBaseEntity::SetLocalAngles(this, angles: &angSpawn);
    return;
  }
  if ( m_eSpawnPosition == DOOR_SPAWN_AJAR )
  {
    angSpawn.x = this->m_angRotationAjar.x;
    angSpawn.y = this->m_angRotationAjar.y;
    v3 = this->m_angRotationAjar.z;
    this->m_eDoorState = DOOR_STATE_AJAR;
  }
  else
  {
    angSpawn.x = this->m_angRotationClosed.x;
    angSpawn.y = this->m_angRotationClosed.y;
    v3 = this->m_angRotationClosed.z;
    this->m_eDoorState = DOOR_STATE_CLOSED;
  }
  angSpawn.z = v3;
  CBaseEntity::SetLocalAngles(this, angles: &angSpawn);
}

//------------------------------------------------------------------------------
// Address: 0x101E2010
// Name: private: void CPropDoorRotating::AngularMove(class QAngle const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPropDoorRotating::AngularMove(
        CPropDoorRotating *this@<ecx>,
        float a2@<ebp>,
        const QAngle *vecDestAngle,
        float flSpeed)
{
  float x; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  QAngle v9; // [esp+18h] [ebp-28h] BYREF
  float v10; // [esp+24h] [ebp-1Ch]
  float v11; // [esp+28h] [ebp-18h]
  float v12; // [esp+2Ch] [ebp-14h]
  QAngle vecDestDelta; // [esp+30h] [ebp-10h]
  float retaddr; // [esp+40h] [ebp+0h]

  vecDestDelta.y = a2;
  vecDestDelta.z = retaddr;
  this->m_angGoal = *vecDestAngle;
  x = this->m_angRotation.m_Value.x;
  if ( x == vecDestAngle->x
    && this->m_angRotation.m_Value.y == vecDestAngle->y
    && this->m_angRotation.m_Value.z == vecDestAngle->z )
  {
    this->MoveDone(this);
  }
  else
  {
    v6 = vecDestAngle->x - x;
    v7 = vecDestAngle->z - this->m_angRotation.m_Value.z;
    v11 = vecDestAngle->y - this->m_angRotation.m_Value.y;
    v12 = v7;
    v10 = v6;
    vecDestDelta.x = fsqrt((float)((float)(v11 * v11) + (float)(v7 * v7)) + (float)(v10 * v10)) / flSpeed;
    CBaseEntity::SetMoveDoneTime(this, flDelay: vecDestDelta.x);
    v8 = 1.0 / vecDestDelta.x;
    v9.x = v8 * v10;
    v9.y = v11 * v8;
    v9.z = v8 * v7;
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2160
// Name: public: virtual void CPropDoorRotating::DoorResume(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPropDoorRotating::DoorResume(CPropDoorRotating *this@<ecx>, float a2@<ebp>)
{
  CPropDoorRotating::AngularMove(this, a2, vecDestAngle: &this->m_angGoal, flSpeed: this->m_flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x101E2180
// Name: public: virtual float CPropDoorRotating::GetOpenInterval(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPropDoorRotating::GetOpenInterval(CPropDoorRotating *this)
{
  float v1; // xmm0_4

  v1 = this->m_angRotationOpenForward.x - this->m_angRotation.m_Value.x;
  return fsqrt(
           (float)((float)((float)(this->m_angRotationOpenForward.y - this->m_angRotation.m_Value.y)
                         * (float)(this->m_angRotationOpenForward.y - this->m_angRotation.m_Value.y))
                 + (float)((float)(this->m_angRotationOpenForward.z - this->m_angRotation.m_Value.z)
                         * (float)(this->m_angRotationOpenForward.z - this->m_angRotation.m_Value.z)))
         + (float)(v1 * v1))
       / this->m_flSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x101E2200
// Name: private: void CPropDoorRotating::InputSetRotationDistance(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::InputSetRotationDistance(CPropDoorRotating *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  LODWORD(this->m_flDistance) = pszValue;
  CPropDoorRotating::CalcOpenAngles(this);
  CPropDoorRotating::CalculateDoorVolume(
    this,
    closedAngles: this->m_angRotation.m_Value,
    openAngles: this->m_angRotationOpenForward,
    destMins: &this->m_vecForwardBoundsMin,
    destMaxs: &this->m_vecForwardBoundsMax);
  CPropDoorRotating::CalculateDoorVolume(
    this,
    closedAngles: this->m_angRotation.m_Value,
    openAngles: this->m_angRotationOpenBack,
    destMins: &this->m_vecBackBoundsMin,
    destMaxs: &this->m_vecBackBoundsMax);
}

//------------------------------------------------------------------------------
// Address: 0x101E22C0
// Name: private: void CPropDoorRotating::InputMoveToRotationDistance(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::InputMoveToRotationDistance(CPropDoorRotating *this, inputdata_t *inputdata)
{
  CPropDoorRotating::InputSetRotationDistance(this, inputdata);
  this->BeginOpening(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101E22F0
// Name: void CC_Prop_Physics_Create(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CC_Prop_Physics_Create(int a1@<edi>, int a2@<esi>, const CCommand *args)
{
  CBasePlayer *CommandClient; // esi
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v5; // eax
  Vector *(__thiscall *v6)(CBaseEntity *, Vector *); // edx
  const Vector *v7; // eax
  char pModelName[512]; // [esp+0h] [ebp-23Ch] BYREF
  Vector vTraceEnd; // [esp+200h] [ebp-3Ch] BYREF
  _BYTE v11[12]; // [esp+20Ch] [ebp-30h] BYREF
  Vector forward; // [esp+218h] [ebp-24h] BYREF
  IHandleEntity pTraceIgnore; // [esp+224h] [ebp-18h] BYREF
  float v14; // [esp+228h] [ebp-14h]
  float v15; // [esp+22Ch] [ebp-10h]
  float v16; // [esp+230h] [ebp-Ch]
  float v17; // [esp+234h] [ebp-8h]
  float v18; // [esp+238h] [ebp-4h]
  int savedregs; // [esp+23Ch] [ebp+0h] BYREF

  if ( args->m_nArgc == 2 )
  {
    V_snprintf(pDest: pModelName, maxLen: 512, pFormat: "models/%s", args->m_ppArgv[1]);
    V_DefaultExtension(path: pModelName, extension: ".mdl", pathStringLength: 512);
    CommandClient = UTIL_GetCommandClient();
    CBasePlayer::EyeVectors(this: CommandClient, pForward: &forward, pRight: nullptr, pUp: nullptr);
    EyePosition = CommandClient->EyePosition;
    v16 = forward.x * 56755.84;
    v17 = forward.y * 56755.84;
    v18 = forward.z * 56755.84;
    v5 = (float *)((int (__thiscall *)(CBasePlayer *, _BYTE *, int))EyePosition)(a1: CommandClient, a2: v11, a3: a2);
    v6 = CommandClient->EyePosition;
    *(float *)&pTraceIgnore.__vftable = *v5 + v16;
    v14 = v5[1] + v17;
    v15 = v5[2] + v18;
    v7 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v6)(a1: CommandClient);
    CreatePhysicsProp(
      a1: (IHandleEntity_vtbl *)&savedregs,
      a2: a1,
      a3: (int)CommandClient,
      pModelName,
      vTraceStart: v7,
      &vTraceEnd,
      &pTraceIgnore,
      bRequireVCollide: (bool)CommandClient,
      pClassName: (const char *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E25F0
// Name: public: virtual void CMemberFunctor3<class CBreakableProp __near *,void (CBreakableProp::*)(class Vector const __near &,class Vector const __near &,class QAngle const __near &),class Vector,class Vector,class QAngle,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CBreakableProp *,void (__thiscall CBreakableProp::*)(Vector const &,Vector const &,QAngle const &),Vector,Vector,QAngle,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CBreakableProp *,void (__thiscall CBreakableProp::*)(Vector const &,Vector const &,QAngle const &),Vector,Vector,QAngle,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, Vector *, Vector *, QAngle *))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + HIDWORD(this->m_Proxy.m_pfnProxied),
    a2: &this->m_arg1,
    a3: &this->m_arg2,
    a4: &this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x101E27F0
// Name: public: CBreakableProp::CBreakableProp(void)
// Source: json
//------------------------------------------------------------------------------
CBreakableProp *__thiscall CBreakableProp::CBreakableProp(CBreakableProp *this)
{
  edict_t *m_pPev; // ecx

  CBaseAnimating::CBaseAnimating(this);
  this->IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&IBreakableWithPropData::`vftable';
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CDefaultPlayerPickupVPhysics::`vftable';
  this->CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBreakableProp_vtbl *)&CBreakableProp::`vftable'{for `CBaseProp'};
  this->IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CBreakableProp::`vftable'{for `IBreakableWithPropData'};
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CBreakableProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->m_OnBreak.m_Value.iVal = 0;
  this->m_OnBreak.m_Value.eVal.m_Index = -1;
  this->m_OnBreak.m_Value.fieldType = FIELD_VOID;
  this->m_OnHealthChanged.m_Value.iVal = 0;
  this->m_OnHealthChanged.m_Value.eVal.m_Index = -1;
  this->m_OnHealthChanged.m_Value.fieldType = FIELD_VOID;
  this->m_OnTakeDamage.m_Value.iVal = 0;
  this->m_OnTakeDamage.m_Value.eVal.m_Index = -1;
  this->m_OnTakeDamage.m_Value.fieldType = FIELD_VOID;
  this->m_hBreaker.m_Index = -1;
  this->m_hPhysicsAttacker.m_Index = -1;
  this->m_OnPhysCannonDetach.m_Value.iVal = 0;
  this->m_OnPhysCannonDetach.m_Value.eVal.m_Index = -1;
  this->m_OnPhysCannonDetach.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysCannonAnimatePreStarted.m_Value.iVal = 0;
  this->m_OnPhysCannonAnimatePreStarted.m_Value.eVal.m_Index = -1;
  this->m_OnPhysCannonAnimatePreStarted.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysCannonAnimatePullStarted.m_Value.iVal = 0;
  this->m_OnPhysCannonAnimatePullStarted.m_Value.eVal.m_Index = -1;
  this->m_OnPhysCannonAnimatePullStarted.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysCannonAnimatePostStarted.m_Value.iVal = 0;
  this->m_OnPhysCannonAnimatePostStarted.m_Value.eVal.m_Index = -1;
  this->m_OnPhysCannonAnimatePostStarted.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysCannonPullAnimFinished.m_Value.iVal = 0;
  this->m_OnPhysCannonPullAnimFinished.m_Value.eVal.m_Index = -1;
  this->m_OnPhysCannonPullAnimFinished.m_Value.fieldType = FIELD_VOID;
  this->m_hLastAttacker.m_Index = -1;
  this->m_hFlareEnt.m_Index = -1;
  CBaseAnimating::SetFadeDistance(this, minFadeDist: -1.0, maxFadeDist: 0.0);
  CBaseEntity::SetGlobalFadeScale(this, flFadeScale: 1.0);
  this->m_flDefaultFadeScale = 1.0;
  this->m_mpBreakMode = MULTIPLAYER_BREAK_DEFAULT;
  this->m_iPhysicsMode = 1;
  this->m_bUsePuntSound = true;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5D8u);
  }
  this->m_qPreferredPlayerCarryAngles.m_Value.x = 3.4028235e38;
  this->m_qPreferredPlayerCarryAngles.m_Value.y = 3.4028235e38;
  this->m_qPreferredPlayerCarryAngles.m_Value.z = 3.4028235e38;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E29B0
// Name: public: virtual int CBreakableProp::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CBreakableProp::OnTakeDamage@<eax>(
        CBreakableProp *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const CTakeDamageInfo *inputInfo)
{
  unsigned int v7; // eax
  IHandleEntity *m_pEntity; // eax
  CBaseEntity *v9; // eax
  CBaseEntity *Attacker; // eax
  CBaseEntity *OwnerEntity; // eax
  const CBaseEntity *v12; // edi
  IBreakableWithPropData *v13; // edi
  double BreakableDamage; // st7
  bool v15; // zf
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // edi
  int v17; // esi
  int m_bitsDamageType; // eax
  char v19; // al
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *v20; // edi
  CBaseEntity *Inflictor; // eax
  float *v22; // edi
  const Vector *v23; // eax
  float v24; // xmm1_4
  __int128 v25; // xmm0
  float v26; // xmm0_4
  double v27; // xmm0_8
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  double v29; // st7
  double v30; // st7
  __m128i v31; // xmm0
  double v32; // xmm0_8
  float v33; // xmm2_4
  float v34; // xmm0_4
  CBreakableProp_vtbl *v35; // edi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // edi
  float v37; // xmm0_4
  int v38; // eax
  float v39; // xmm0_4
  int v40; // edi
  CBaseEntity *v41; // eax
  float value; // [esp+28h] [ebp-A8h]
  CBaseEntity *v43; // [esp+2Ch] [ebp-A4h]
  float fDelay; // [esp+30h] [ebp-A0h]
  _BYTE v47[12]; // [esp+44h] [ebp-8Ch] BYREF
  _BYTE info_28[72]; // [esp+6Ch] [ebp-64h] OVERLAPPED BYREF
  int v49; // [esp+B8h] [ebp-18h] BYREF
  int m_Value; // [esp+BCh] [ebp-14h] BYREF
  bool v51; // [esp+C3h] [ebp-Dh]
  int v52; // [esp+C4h] [ebp-Ch]
  float flBurnTime; // [esp+C8h] [ebp-8h]
  float retaddr; // [esp+D0h] [ebp+0h]

  v52 = a2;
  flBurnTime = retaddr;
  CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)v47, __that: inputInfo);
  if ( (float)this->m_iMinHealthDmg > *(float *)&info_28[8] )
    return 0;
  if ( !this->PassesDamageFilter(this, a2: (const CTakeDamageInfo *)v47) )
    return 1;
  v7 = *(_DWORD *)info_28;
  if ( *(_DWORD *)info_28 == -1 )
    goto LABEL_22;
  if ( g_pEntityList->m_EntPtrArray[*(unsigned __int16 *)info_28].m_SerialNumber != HIWORD(*(_DWORD *)info_28)
    || g_pEntityList->m_EntPtrArray[*(unsigned __int16 *)info_28].m_pEntity == nullptr )
  {
    goto LABEL_16;
  }
  if ( g_pEntityList->m_EntPtrArray[*(unsigned __int16 *)info_28].m_SerialNumber == HIWORD(*(_DWORD *)info_28) )
    m_pEntity = g_pEntityList->m_EntPtrArray[*(unsigned __int16 *)info_28].m_pEntity;
  else
    m_pEntity = nullptr;
  if ( ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity) == 0 )
  {
    v7 = *(_DWORD *)info_28;
LABEL_16:
    if ( v7 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity != nullptr )
    {
      Attacker = CTakeDamageInfo::GetAttacker(this: (CTakeDamageInfo *)v47);
      OwnerEntity = CBaseEntity::GetOwnerEntity(this: Attacker);
      v12 = OwnerEntity;
      if ( OwnerEntity != nullptr && OwnerEntity->MyCombatCharacterPointer(this: OwnerEntity) != nullptr )
        CHandle<CBaseEntity>::Set(this: &this->m_hLastAttacker, pVal: v12);
    }
    goto LABEL_22;
  }
  v9 = CTakeDamageInfo::GetAttacker(this: (CTakeDamageInfo *)v47);
  if ( v9 != nullptr )
    this->m_hLastAttacker.m_Index = v9->GetRefEHandle(this: v9)->m_Index;
  else
    this->m_hLastAttacker.m_Index = -1;
LABEL_22:
  v13 = &this->IBreakableWithPropData;
  BreakableDamage = GetBreakableDamage(inputInfo: (const CTakeDamageInfo *)v47, pProp: &this->IBreakableWithPropData);
  *(float *)&info_28[8] = BreakableDamage;
  if ( (double)this->m_iMinHealthDmg > BreakableDamage )
    return 0;
  if ( this->m_createTick == gpGlobals->tickcount )
  {
    v15 = this->m_takedamage.m_Value == 1;
    p_m_takedamage = &this->m_takedamage;
    m_Value = this->m_takedamage.m_Value;
    if ( !v15 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      p_m_takedamage->m_Value = 1;
    }
    v17 = CBaseEntity::OnTakeDamage(this, info: (const CTakeDamageInfo *)v47);
    if ( p_m_takedamage->m_Value != (_BYTE)m_Value )
    {
      (*(void (__thiscall **)(CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *))(*(_DWORD *)&p_m_takedamage[-554].m_Value + 756))(
        a1: p_m_takedamage - 554,
        a2: p_m_takedamage);
      p_m_takedamage->m_Value = m_Value;
    }
    return v17;
  }
  if ( (this->m_fFlags.m_Value & 0x10000000) != 0 )
  {
    m_bitsDamageType = inputInfo->m_bitsDamageType;
    if ( (m_bitsDamageType & 8) != 0 && (m_bitsDamageType & 0x10000000) == 0 )
      return 0;
  }
  v51 = *(float *)&info_28[8] >= (float)this->m_iHealth.m_Value;
  v19 = info_28[20];
  if ( (info_28[20] & 0x84) == 0 )
  {
LABEL_39:
    if ( v51 )
    {
      if ( (v19 & 0x40) == 0
        || !v13->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_FIRE_EXPLOSIVE_RESIST)
        || CTakeDamageInfo::GetInflictor(this: (CTakeDamageInfo *)v47) == nullptr )
      {
        goto LABEL_67;
      }
      Inflictor = CTakeDamageInfo::GetInflictor(this: (CTakeDamageInfo *)v47);
      v22 = (float *)((int (__thiscall *)(CBaseEntity *, int, int))Inflictor->WorldSpaceCenter)(
                       a1: Inflictor,
                       a2: a3,
                       a3: a4);
      v23 = this->WorldSpaceCenter(this);
      v24 = v23->y - v22[1];
      v25 = 0;
      *(float *)&v25 = fsqrt(
                         (float)((float)(v24 * v24) + (float)((float)(v23->z - v22[2]) * (float)(v23->z - v22[2])))
                       + (float)((float)(v23->x - *v22) * (float)(v23->x - *v22)));
      *(_OWORD *)&info_28[56] = v25;
      if ( *(float *)&v25 < 32.0 )
      {
        v30 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1036831949,
                a3: 1045220557);
      }
      else
      {
        if ( *(float *)&v25 > 256.0 )
          LODWORD(v25) = 1132462080;
        v26 = (float)(*(float *)&v25 * 0.00390625) * 5.0;
        v27 = v26 >= 0.5 ? v26 : 0.5;
        RandomFloat = random->RandomFloat;
        *(double *)&info_28[64] = v27;
        v29 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))RandomFloat)(
                a1: random,
                a2: 0,
                a3: 1056964608);
        v30 = v29 + *(double *)&info_28[64];
      }
      v31 = _mm_cvtsi32_si128(this->m_iHealth.m_Value);
      *(float *)&m_Value = v30;
      v32 = _mm_cvtepi32_pd(v31).m128d_f64[0];
      if ( v32 > (float)(*(float *)&m_Value * 5.0) )
        v32 = (float)(*(float *)&m_Value * 5.0);
      v33 = v32;
      v34 = (float)this->m_iHealth.m_Value;
      *(float *)&info_28[8] = (float)((float)(v34 - v33) / *(float *)&info_28[8]) * *(float *)&info_28[8];
      if ( *(float *)&info_28[8] >= v34 )
        goto LABEL_67;
      v19 = info_28[20];
      v51 = false;
    }
    if ( (v19 & 0x40) == 0 && (v19 & 8) == 0 )
    {
      if ( (v19 & 2) == 0
        || !this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_FIRE_IGNITE_HALFHEALTH) )
      {
        goto LABEL_67;
      }
      p_m_iHealth = &this->m_iHealth;
      v37 = (float)this->m_iHealth.m_Value;
      if ( (float)(this->m_iMaxHealth.m_Value / 2) < (float)(v37 - *(float *)&info_28[8])
        || (this->m_fFlags.m_Value & 0x10000000) != 0 )
      {
        if ( (this->m_fFlags.m_Value & 0x10000000) != 0 )
          *(float *)&info_28[8] = (float)(v37 / *(float *)&info_28[8]) * *(float *)&info_28[8];
        goto LABEL_67;
      }
      if ( p_m_iHealth->m_Value != this->m_iMaxHealth.m_Value )
      {
        this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
        p_m_iHealth->m_Value = this->m_iMaxHealth.m_Value;
      }
    }
    v35 = this->CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    fDelay = ((double (__thiscall *)(IUniformRandomStream *, int, int, _DWORD, _DWORD, _DWORD))random->RandomFloat)(
               a1: random,
               a2: 1092616192,
               a3: 1097859072,
               a4: 0,
               a5: 0,
               a6: 0);
    ((void (__thiscall *)(CBreakableProp *, _DWORD))v35->Ignite)(a1: this, a2: LODWORD(fDelay));
LABEL_67:
    v38 = CBaseEntity::OnTakeDamage(this, info: (const CTakeDamageInfo *)v47);
    v39 = (float)this->m_iHealth.m_Value / (float)this->m_iMaxHealth.m_Value;
    v40 = v38;
    m_Value = 1;
    v49 = 0;
    *(float *)&info_28[68] = v39;
    v43 = CTakeDamageInfo::GetAttacker(this: (CTakeDamageInfo *)v47);
    value = clamp<float,int,int>(val: (float *)&info_28[68], minVal: &v49, maxVal: &m_Value);
    CEntityOutputTemplate<float,1>::Set(this: &this->m_OnHealthChanged, value, pActivator: v43, pCaller: this);
    v41 = CTakeDamageInfo::GetAttacker(this: (CTakeDamageInfo *)v47);
    COutputEvent::FireOutput(this: &this->m_OnTakeDamage, pActivator: v41, pCaller: this, fDelay: 0.0);
    return v40;
  }
  if ( !v13->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_MELEE_IMMUNE) )
  {
    v19 = info_28[20];
    goto LABEL_39;
  }
  v15 = this->m_takedamage.m_Value == 1;
  v20 = &this->m_takedamage;
  m_Value = this->m_takedamage.m_Value;
  if ( !v15 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    v20->m_Value = 1;
  }
  v17 = CBaseEntity::OnTakeDamage(this, info: (const CTakeDamageInfo *)v47);
  if ( v20->m_Value == (_BYTE)m_Value )
    return v17;
  (*(void (__thiscall **)(CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, int, int))(*(_DWORD *)&v20[-554].m_Value + 756))(
    a1: v20 - 554,
    a2: v20,
    a3,
    a4);
  v20->m_Value = m_Value;
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x101E2FF0
// Name: public: void CBreakableProp::Break(class CBaseEntity __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::Break(CBreakableProp *this, CBaseEntity *pBreaker, const CTakeDamageInfo *info)
{
  const char *v4; // eax
  unsigned int m_Index; // eax
  CBaseEntity *v6; // eax
  int v7; // eax
  IGameEvent *v8; // edi
  bool v9; // al
  edict_t *m_pPev; // eax
  IPhysicsObject *v11; // ebx
  int m_iEFlags; // ecx
  int v13; // edx
  unsigned int v14; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v16; // ecx
  int v17; // eax
  CEntInfo *v18; // edx
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  CEntInfo *v21; // edx
  int v22; // eax
  CBaseEntity *v23; // edi
  int m_explodeDamage; // edx
  CBaseEntity *v25; // eax
  int m_explodeRadius; // ecx
  bool v27; // al
  bool v28; // zf
  const Vector *v29; // eax
  const Vector *v30; // eax
  float m_impactEnergyScale; // xmm0_4
  int m_Value; // eax
  const Vector *v33; // edi
  ITempEntsSystem_vtbl *v34; // edi
  const Vector *AbsOrigin; // eax
  int v36; // eax
  PerformanceMode_t m_PerformanceMode; // eax
  int v38; // eax
  ITempEntsSystem_vtbl *v39; // edi
  const Vector *v40; // eax
  int v41; // eax
  PerformanceMode_t v42; // eax
  int v43; // eax
  PerformanceMode_t v44; // eax
  int v45; // eax
  CBaseEntity *i; // edi
  int v47; // eax
  CBaseEntity *v48; // ebx
  CBaseEntity *j; // edi
  void *v50; // eax
  CBaseEntity *v51; // [esp+4Ch] [ebp-8BCh]
  CBaseEntity *v52; // [esp+4Ch] [ebp-8BCh]
  int v53; // [esp+50h] [ebp-8B8h]
  int v54; // [esp+50h] [ebp-8B8h]
  int v55; // [esp+54h] [ebp-8B4h]
  int v56; // [esp+54h] [ebp-8B4h]
  int v57; // [esp+58h] [ebp-8B0h]
  IPhysicsObject *v58; // [esp+58h] [ebp-8B0h]
  const QAngle *flExplosionForce; // [esp+5Ch] [ebp-8ACh]
  const QAngle *flExplosionForcea; // [esp+5Ch] [ebp-8ACh]
  CBreakableProp *v61; // [esp+60h] [ebp-8A8h]
  int soundtime; // [esp+68h] [ebp-8A0h]
  bool soundtimea; // [esp+68h] [ebp-8A0h]
  int soundtimeb; // [esp+68h] [ebp-8A0h]
  bool soundtimec; // [esp+68h] [ebp-8A0h]
  bool soundtimed; // [esp+68h] [ebp-8A0h]
  int fDelay; // [esp+6Ch] [ebp-89Ch]
  unsigned __int16 fDelaya; // [esp+6Ch] [ebp-89Ch]
  int fDelayb; // [esp+6Ch] [ebp-89Ch]
  int fDelayc; // [esp+6Ch] [ebp-89Ch]
  CEntitySphereQuery sphere; // [esp+7Ch] [ebp-88Ch] BYREF
  CPASFilter filter; // [esp+884h] [ebp-84h] BYREF
  breakablepropparams_t params; // [esp+8A4h] [ebp-64h] BYREF
  _DWORD v74[3]; // [esp+8C0h] [ebp-48h] BYREF
  Vector angVelocity; // [esp+8CCh] [ebp-3Ch] BYREF
  Vector velocity; // [esp+8D8h] [ebp-30h] BYREF
  Vector origin; // [esp+8E4h] [ebp-24h] BYREF
  IPhysicsObject *pPhysics; // [esp+8F0h] [ebp-18h] BYREF
  QAngle angles; // [esp+8F4h] [ebp-14h] BYREF
  CBaseEntity *pAttacker; // [esp+900h] [ebp-8h]
  bool bExploded; // [esp+907h] [ebp-1h]
  int savedregs; // [esp+908h] [ebp+0h] BYREF

  v4 = *(const char **)((int (__thiscall *)(CBreakableProp *, IPhysicsObject **))this->GetModelName)(
                         a1: this,
                         a2: &pPhysics);
  if ( v4 == nullptr )
    v4 = locale;
  if ( V_stristr(pStr: v4, pSearch: "crate") != nullptr )
  {
    if ( pBreaker != nullptr && pBreaker->IsPlayer(this: pBreaker)
      || (m_Index = this->m_hPhysicsAttacker.m_Index) != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
      && (v6 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hPhysicsAttacker),
          v6->IsPlayer(this: v6))
      || pBreaker != nullptr
      && __RTDynamicCast(
           inptr: pBreaker,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CPropVehicleDriveable `RTTI Type Descriptor',
           isReference: 0) != nullptr
      && (v7 = (*(int (__thiscall **)(COutputEvent *))pBreaker[1].m_OnKilled.m_Value.iszVal.pszValue)(a1: &pBreaker[1].m_OnKilled)) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 336))(a1: v7) != 0 )
    {
      gamestats->Event_CrateSmashed(this: gamestats);
    }
  }
  v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "break_prop", a3: 0, a4: &g_BreakPropEvent);
  if ( v8 != nullptr )
  {
    if ( pBreaker != nullptr && pBreaker->IsPlayer(this: pBreaker) )
    {
      v9 = pBreaker->IsPlayer(this: pBreaker);
      fDelay = engine->GetPlayerUserId(this: engine, a2: *(v9 ? &pBreaker->m_Network.m_pPev : (edict_t **)24));
      v8->SetInt(this: v8, a2: "userid", a3: fDelay);
    }
    else
    {
      v8->SetInt(this: v8, a2: "userid", a3: 0);
    }
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v8->SetInt(this: v8, a2: "entindex", a3: (int)m_pPev);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
  }
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  COutputEvent::FireOutput(this: &this->m_OnBreak, pActivator: pBreaker, pCaller: this, fDelay: 0.0);
  v11 = this->GetRootPhysicsObjectForBreak(this);
  fDelaya = this->m_Collision.m_usSolidFlags.m_Value | 4;
  pPhysics = v11;
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: fDelaya);
  if ( v11 != nullptr )
  {
    v11->GetVelocity(this: v11, a2: &velocity, a3: &angVelocity);
    v11->GetPosition(this: v11, a2: &origin, a3: &angles);
    v11->RecheckCollisionFilter(this: v11);
  }
  else
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    m_iEFlags = this->m_iEFlags;
    velocity = this->m_vecAbsVelocity;
    angVelocity.x = this->m_vecAngVelocity.z;
    angVelocity.y = this->m_vecAngVelocity.x;
    angVelocity.z = this->m_vecAngVelocity.y;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v13 = this->m_iEFlags;
    origin = this->m_vecAbsOrigin;
    if ( (v13 & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    angles = this->m_angAbsRotation;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  PhysBreakSound(pEntity: this, pPhysObject: this->m_pPhysicsObject, vecOrigin: this->m_vecAbsOrigin);
  v14 = info->m_hAttacker.m_Index;
  bExploded = false;
  if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
  pAttacker = m_pEntity;
  v16 = this->m_hLastAttacker.m_Index;
  if ( v16 != -1
    && (v17 = (unsigned __int16)v16,
        v18 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v16],
        v19 = HIWORD(v16),
        v18->m_SerialNumber == v19)
    && v18->m_pEntity != nullptr
    || (v20 = this->m_hPhysicsAttacker.m_Index) != -1
    && (v17 = (unsigned __int16)v20,
        v21 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v20],
        v19 = HIWORD(v20),
        v21->m_SerialNumber == v19)
    && v21->m_pEntity != nullptr
    && (float)(gpGlobals->curtime - this->m_flLastPhysicsInfluenceTime) <= 2.0 )
  {
    v22 = v17;
    if ( g_pEntityList->m_EntPtrArray[v22].m_SerialNumber == v19 )
      v23 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[v22].m_pEntity;
    else
      v23 = nullptr;
    pAttacker = v23;
  }
  if ( this->m_explodeDamage > 0.0 || this->m_explodeRadius > 0.0 )
  {
    if ( this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_BREAK_EXPLODE) )
    {
      m_explodeDamage = (int)this->m_explodeDamage;
      v25 = pAttacker;
      v61 = this;
      m_explodeRadius = (int)this->m_explodeRadius;
      v57 = 9320;
    }
    else
    {
      v27 = this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_BREAK_EXPLODE_ICE);
      m_explodeDamage = (int)this->m_explodeDamage;
      v61 = this;
      m_explodeRadius = (int)this->m_explodeRadius;
      v28 = !v27;
      v25 = pAttacker;
      if ( v28 )
      {
        v56 = (int)this->m_explodeRadius;
        v54 = (int)this->m_explodeDamage;
        v52 = pAttacker;
        v30 = this->WorldSpaceCenter(this);
        ExplosionCreate(
          center: v30,
          &angles,
          pOwner: v52,
          magnitude: v54,
          radius: v56,
          nSpawnFlags: 9256,
          flExplosionForce: 0.0,
          pInflictor: this,
          iCustomDamageType: -1,
          ignoredEntity: nullptr,
          ignoredClass: CLASS_NONE);
        goto LABEL_59;
      }
      v57 = 42089;
    }
    v55 = m_explodeRadius;
    v53 = m_explodeDamage;
    v51 = v25;
    v29 = this->WorldSpaceCenter(this);
    ExplosionCreate(
      center: v29,
      &angles,
      pOwner: v51,
      magnitude: v53,
      radius: v55,
      nSpawnFlags: v57,
      flExplosionForce: 0.0,
      pInflictor: v61,
      iCustomDamageType: -1,
      ignoredEntity: nullptr,
      ignoredClass: CLASS_NONE);
    CBaseEntity::EmitSound(this, soundname: "PropaneTank.Burst", soundtime: 0.0, duration: nullptr);
LABEL_59:
    bExploded = true;
  }
  this->OnBreak(this, a2: &velocity, a3: &angVelocity, a4: pBreaker);
  m_impactEnergyScale = this->m_impactEnergyScale;
  params.origin = &origin;
  params.angularVelocity = &angVelocity;
  m_Value = this->m_CollisionGroup.m_Value;
  params.angles = &angles;
  params.velocity = &velocity;
  params.impactEnergyScale = m_impactEnergyScale;
  params.defCollisionGroup = m_Value;
  if ( m_Value == 0 )
    params.defCollisionGroup = 4;
  params.defBurstScale = 100.0;
  if ( gpGlobals->maxClients > 1
    && breakable_multiplayer.m_pParent != nullptr
    && breakable_multiplayer.m_pParent->m_Value.m_nValue != 0 )
  {
    v33 = this->WorldSpaceCenter(this);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v33);
    memset(v74, 0, sizeof(v74));
    if ( v11 != nullptr )
      v11->GetVelocity(this: v11, a2: (Vector *)v74, a3: nullptr);
    switch ( this->GetMultiplayerBreakMode(this: &this->IBreakableWithPropData) )
    {
      case MULTIPLAYER_BREAK_DEFAULT:
      case MULTIPLAYER_BREAK_CLIENTSIDE:
        v34 = te->__vftable;
        soundtime = this->m_fEffects.m_Value;
        LOWORD(fDelayb) = *(_WORD *)&this->m_clrRender.m_Value.r;
        HIWORD(fDelayb) = this->m_clrRender.m_Value.b;
        flExplosionForce = CBaseEntity::GetAbsAngles(this);
        AbsOrigin = CBaseEntity::GetAbsOrigin(this);
        v36 = ((int (__thiscall *)(CBreakableProp *, int, const Vector *, const QAngle *, _DWORD *, int, int, int))this->GetModelIndex)(
                a1: this,
                a2: this->m_nSkin.m_Value,
                a3: AbsOrigin,
                a4: flExplosionForce,
                a5: v74,
                a6: 1,
                a7: soundtime,
                a8: fDelayb);
        ((void (__thiscall *)(ITempEntsSystem *, CPASFilter *, int, int))v34->PhysicsProp)(
          a1: te,
          a2: &filter,
          a3: -1082130432,
          a4: v36);
        CRecipientFilter::~CRecipientFilter(this: &filter);
        break;
      case MULTIPLAYER_BREAK_SERVERSIDE:
        m_PerformanceMode = this->m_PerformanceMode;
        if ( m_PerformanceMode != PM_NO_GIBS
          || breakable_disable_gib_limit.m_pParent != nullptr
          && breakable_disable_gib_limit.m_pParent->m_Value.m_nValue != 0 )
        {
          soundtimea = m_PerformanceMode == PM_FULL_GIBS;
          v38 = this->GetModelIndex(this);
          PropBreakableCreateAll(
            modelindex: v38,
            pPhysics: v11,
            &params,
            pEntity: this,
            iPrecomputedBreakableCount: -1,
            bIgnoreGibLimit: soundtimea,
            defaultLocation: false);
        }
        goto LABEL_77;
      case MULTIPLAYER_BREAK_BOTH:
        v39 = te->__vftable;
        soundtimeb = this->m_fEffects.m_Value;
        LOWORD(fDelayc) = *(_WORD *)&this->m_clrRender.m_Value.r;
        HIWORD(fDelayc) = this->m_clrRender.m_Value.b;
        flExplosionForcea = CBaseEntity::GetAbsAngles(this);
        v40 = CBaseEntity::GetAbsOrigin(this);
        v41 = ((int (__thiscall *)(CBreakableProp *, int, const Vector *, const QAngle *, _DWORD *, int, int, int))this->GetModelIndex)(
                a1: this,
                a2: this->m_nSkin.m_Value,
                a3: v40,
                a4: flExplosionForcea,
                a5: v74,
                a6: 1,
                a7: soundtimeb,
                a8: fDelayc);
        ((void (__thiscall *)(ITempEntsSystem *, CPASFilter *, int, int))v39->PhysicsProp)(
          a1: te,
          a2: &filter,
          a3: -1082130432,
          a4: v41);
        v42 = this->m_PerformanceMode;
        if ( v42 != PM_NO_GIBS
          || breakable_disable_gib_limit.m_pParent != nullptr
          && breakable_disable_gib_limit.m_pParent->m_Value.m_nValue != 0 )
        {
          soundtimec = v42 == PM_FULL_GIBS;
          v58 = pPhysics;
          v43 = this->GetModelIndex(this);
          PropBreakableCreateAll(
            modelindex: v43,
            pPhysics: v58,
            &params,
            pEntity: this,
            iPrecomputedBreakableCount: -1,
            bIgnoreGibLimit: soundtimec,
            defaultLocation: false);
        }
        goto LABEL_77;
      default:
LABEL_77:
        CRecipientFilter::~CRecipientFilter(this: &filter);
        break;
    }
  }
  else
  {
    v44 = this->m_PerformanceMode;
    if ( v44 != PM_NO_GIBS
      || breakable_disable_gib_limit.m_pParent != nullptr
      && breakable_disable_gib_limit.m_pParent->m_Value.m_nValue != 0 )
    {
      soundtimed = v44 == PM_FULL_GIBS;
      v45 = this->GetModelIndex(this);
      PropBreakableCreateAll(
        modelindex: v45,
        pPhysics: v11,
        &params,
        pEntity: this,
        iPrecomputedBreakableCount: -1,
        bIgnoreGibLimit: soundtimed,
        defaultLocation: true);
    }
  }
  if ( this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_BREAK_EXPLODE) )
  {
    if ( !bExploded )
      ExplosionCreate(
        center: &origin,
        &angles,
        pOwner: pAttacker,
        magnitude: 1,
        radius: (int)this->m_explodeRadius,
        nSpawnFlags: 1065,
        flExplosionForce: 0.0,
        pInflictor: this,
        iCustomDamageType: -1,
        ignoredEntity: nullptr,
        ignoredClass: CLASS_NONE);
    CEntitySphereQuery::CEntitySphereQuery(this: &sphere, center: &origin, radius: this->m_explodeRadius, flagMask: 0);
    for ( i = CEntitySphereQuery::GetCurrentEntity(this: &sphere);
          i != nullptr;
          i = CEntitySphereQuery::GetCurrentEntity(this: &sphere) )
    {
      if ( i->MyCombatCharacterPointer(this: i) != nullptr && i->PassesDamageFilter(this: i, a2: info) )
      {
        v47 = (int)i->MyCombatCharacterPointer(this: i);
        (*(void (__thiscall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)v47 + 876))(
          a1: v47,
          a2: 1106247680,
          a3: 1,
          a4: 0,
          a5: 0);
      }
      ++sphere.m_listIndex;
    }
  }
  if ( this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_BREAK_EXPLODE_ICE) )
  {
    v48 = pAttacker;
    if ( !bExploded )
      ExplosionCreate(
        center: &origin,
        &angles,
        pOwner: pAttacker,
        magnitude: 1,
        radius: (int)this->m_explodeRadius,
        nSpawnFlags: 33832,
        flExplosionForce: 0.0,
        pInflictor: this,
        iCustomDamageType: -1,
        ignoredEntity: nullptr,
        ignoredClass: CLASS_NONE);
    CEntitySphereQuery::CEntitySphereQuery(this: &sphere, center: &origin, radius: this->m_explodeRadius, flagMask: 0);
    for ( j = CEntitySphereQuery::GetCurrentEntity(this: &sphere);
          j != nullptr;
          j = CEntitySphereQuery::GetCurrentEntity(this: &sphere) )
    {
      if ( j->MyCombatCharacterPointer(this: j) != nullptr && j->PassesDamageFilter(this: j, a2: info) )
      {
        v50 = __RTDynamicCast(
                inptr: j,
                VfDelta: 0,
                SrcType: &CBaseEntity `RTTI Type Descriptor',
                TargetType: &CAI_BaseNPC `RTTI Type Descriptor',
                isReference: 0);
        if ( v50 != nullptr )
          (*(void (__thiscall **)(void *, int, CBaseEntity *, _DWORD))(*(_DWORD *)v50 + 896))(
            a1: v50,
            a2: 1082130432,
            a3: v48,
            a4: 0);
      }
      ++sphere.m_listIndex;
    }
  }
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x101E39E0
// Name: public: CDynamicProp::CDynamicProp(void)
// Source: json
//------------------------------------------------------------------------------
CDynamicProp *__thiscall CDynamicProp::CDynamicProp(CDynamicProp *this)
{
  CBreakableProp::CBreakableProp(this);
  this->IPositionWatcher::IWatcherCallback::__vftable = (IPositionWatcher_vtbl *)&IPositionWatcher::`vftable';
  this->CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CDynamicProp_vtbl *)&CDynamicProp::`vftable'{for `CBaseProp'};
  this->CBreakableProp::IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CDynamicProp::`vftable'{for `IBreakableWithPropData'};
  this->CBreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CDynamicProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->IPositionWatcher::IWatcherCallback::__vftable = (IPositionWatcher_vtbl *)&CDynamicProp::`vftable';
  this->m_pOutputAnimBegun.m_Value.iVal = 0;
  this->m_pOutputAnimBegun.m_Value.eVal.m_Index = -1;
  this->m_pOutputAnimBegun.m_Value.fieldType = FIELD_VOID;
  this->m_pOutputAnimOver.m_Value.iVal = 0;
  this->m_pOutputAnimOver.m_Value.eVal.m_Index = -1;
  this->m_pOutputAnimOver.m_Value.fieldType = FIELD_VOID;
  CBoneFollowerManager::CBoneFollowerManager(this: &this->m_BoneFollowerManager);
  this->m_nPendingSequence = -1;
  if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) )
    CBaseAnimating::UseClientSideAnimation(this);
  this->m_iGoalSequence = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E3AE0
// Name: public: virtual void CDynamicProp::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::OnRestore(CDynamicProp *this)
{
  unsigned int m_Index; // ecx

  CBaseAnimating::OnRestore(this);
  if ( this->m_BoneFollowerManager.m_iNumBones != 0 )
  {
    m_Index = this->m_pParent.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      WatchPositionChanges(pWatcher: this, pMovingEntity: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3B30
// Name: public: virtual void CDynamicProp::SetParent(class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::SetParent(CDynamicProp *this, CBaseEntity *pNewParent, int iAttachment)
{
  unsigned int m_Index; // ecx

  CBaseEntity::SetParent(this, pParentEntity: pNewParent, iAttachment);
  if ( this->m_BoneFollowerManager.m_iNumBones != 0 )
  {
    m_Index = this->m_pParent.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      WatchPositionChanges(pWatcher: this, pMovingEntity: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3B90
// Name: public: CPhysicsProp::CPhysicsProp(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsProp *__thiscall CPhysicsProp::CPhysicsProp(CPhysicsProp *this)
{
  CBreakableProp::CBreakableProp(this);
  this->INavAvoidanceObstacle::__vftable = (INavAvoidanceObstacle_vtbl *)&INavAvoidanceObstacle::`vftable';
  this->CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPhysicsProp_vtbl *)&CPhysicsProp::`vftable'{for `CBaseProp'};
  this->CBreakableProp::IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CPhysicsProp::`vftable'{for `IBreakableWithPropData'};
  this->CBreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPhysicsProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->INavAvoidanceObstacle::__vftable = (INavAvoidanceObstacle_vtbl *)&CPhysicsProp::`vftable';
  this->m_MotionEnabled.m_Value.iVal = 0;
  this->m_MotionEnabled.m_Value.eVal.m_Index = -1;
  this->m_MotionEnabled.m_Value.fieldType = FIELD_VOID;
  this->m_OnAwakened.m_Value.iVal = 0;
  this->m_OnAwakened.m_Value.eVal.m_Index = -1;
  this->m_OnAwakened.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysGunPickup.m_Value.iVal = 0;
  this->m_OnPhysGunPickup.m_Value.eVal.m_Index = -1;
  this->m_OnPhysGunPickup.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysGunPunt.m_Value.iVal = 0;
  this->m_OnPhysGunPunt.m_Value.eVal.m_Index = -1;
  this->m_OnPhysGunPunt.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysGunOnlyPickup.m_Value.iVal = 0;
  this->m_OnPhysGunOnlyPickup.m_Value.eVal.m_Index = -1;
  this->m_OnPhysGunOnlyPickup.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysGunDrop.m_Value.iVal = 0;
  this->m_OnPhysGunDrop.m_Value.eVal.m_Index = -1;
  this->m_OnPhysGunDrop.m_Value.fieldType = FIELD_VOID;
  this->m_OnPlayerUse.m_Value.iVal = 0;
  this->m_OnPlayerUse.m_Value.eVal.m_Index = -1;
  this->m_OnPlayerUse.m_Value.fieldType = FIELD_VOID;
  this->m_OnPlayerPickup.m_Value.iVal = 0;
  this->m_OnPlayerPickup.m_Value.eVal.m_Index = -1;
  this->m_OnPlayerPickup.m_Value.fieldType = FIELD_VOID;
  this->m_OnOutOfWorld.m_Value.iVal = 0;
  this->m_OnOutOfWorld.m_Value.eVal.m_Index = -1;
  this->m_OnOutOfWorld.m_Value.fieldType = FIELD_VOID;
  this->m_bHasBeenAwakened = false;
  this->m_fNextCheckDisableMotionContactsTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E3C90
// Name: protected: void CBasePropDoor::DisableAreaPortalThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::DisableAreaPortalThink(CBasePropDoor *this)
{
  CBasePropDoor::UpdateAreaPortals(this, isOpen: false);
}

//------------------------------------------------------------------------------
// Address: 0x101E3CA0
// Name: private: void CBasePropDoor::DoorCloseMoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::DoorCloseMoveDone(CBasePropDoor *this)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax
  const char *v4; // eax
  unsigned int v5; // eax
  CBaseEntity *m_pEntity; // ecx

  this->m_hBlocker.m_Index = -1;
  m_Index = this->m_hBlocker.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    this->m_bFirstBlocked = false;
  }
  if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
  {
    pszValue = this->m_SoundMoving.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CBaseEntity::StopSound(this, soundname: pszValue);
    v4 = this->m_SoundClose.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    CBaseEntity::EmitSound(this, soundname: v4, soundtime: 0.0, duration: nullptr);
  }
  this->m_eDoorState = DOOR_STATE_CLOSED;
  v5 = this->m_hActivator.m_Index;
  if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  COutputEvent::FireOutput(this: &this->m_OnFullyClosed, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CBasePropDoor::DisableAreaPortalThink,
    thinkTime: gpGlobals->curtime + 0.5,
    szContext: "AreaPortal");
  this->OnDoorClosed(this);
  this->m_hActivator.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x101E3DC0
// Name: public: virtual void CPropDoorRotating::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::OnRestore(CPropDoorRotating *this)
{
  unsigned int m_Index; // ecx

  CBaseAnimating::OnRestore(this);
  if ( this->m_BoneFollowerManager.m_iNumBones != 0 )
  {
    m_Index = this->m_pParent.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      WatchPositionChanges(pWatcher: this, pMovingEntity: this);
    }
  }
  CPropDoorRotating::CalculateDoorVolume(
    this,
    closedAngles: this->m_angRotation.m_Value,
    openAngles: this->m_angRotationOpenForward,
    destMins: &this->m_vecForwardBoundsMin,
    destMaxs: &this->m_vecForwardBoundsMax);
  CPropDoorRotating::CalculateDoorVolume(
    this,
    closedAngles: this->m_angRotation.m_Value,
    openAngles: this->m_angRotationOpenBack,
    destMins: &this->m_vecBackBoundsMin,
    destMaxs: &this->m_vecBackBoundsMax);
}

//------------------------------------------------------------------------------
// Address: 0x101E40D0
// Name: public: virtual bool CPhysSphere::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysSphere::CreateVPhysics(CPhysSphere *this)
{
  int m_iEFlags; // eax
  IPhysicsObject *v3; // eax
  IPhysicsObject *v4; // edi
  objectparams_t params; // [esp+20h] [ebp-44h] BYREF
  Vector mins; // [esp+4Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+58h] [ebp-Ch] BYREF
  int savedregs; // [esp+64h] [ebp+0h] BYREF

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  maxs.x = 12.0;
  maxs.y = 12.0;
  maxs.z = 12.0;
  mins.x = -12.0;
  mins.y = -12.0;
  mins.z = -12.0;
  CBaseEntity::SetCollisionBounds(this, &mins, &maxs);
  m_iEFlags = this->m_iEFlags;
  *(_QWORD *)&params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  params.pName = g_PhysDefaultObjectParams.pName;
  *(_QWORD *)&params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  *(_DWORD *)&params.enableCollisions = 1;
  params.pGameData = this;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v3 = (IPhysicsObject *)((int (__stdcall *)(int, _DWORD, Vector *, QAngle *, objectparams_t *, _DWORD))physenv->CreateSphereObject)(
                           a1: 1094713344,
                           a2: 0,
                           a3: &this->m_vecAbsOrigin,
                           a4: &this->m_angAbsRotation,
                           a5: &params,
                           a6: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CBaseEntity::VPhysicsSetObject(this, pPhysics: v3);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
    v4->Wake(this: v4);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E4870
// Name: public: virtual void CBaseProp::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseProp::Spawn(CBaseProp *this)
{
  bool (__cdecl *v2)(const char *); // edi
  int v3; // ebx
  const char *pszValue; // eax
  const Vector *AbsOrigin; // ebx
  const Vector *v6; // ebx
  CGlobalVars *v7; // ebx
  edict_t *m_pPev; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  const char *v11; // eax
  double y; // [esp+10h] [ebp-28h]
  double v13; // [esp+10h] [ebp-28h]
  double z; // [esp+18h] [ebp-20h]
  double v15; // [esp+18h] [ebp-20h]
  _BYTE v16[4]; // [esp+30h] [ebp-8h] BYREF
  const char *v17; // [esp+34h] [ebp-4h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  v2 = *(bool (__cdecl **)(const char *))((int (__thiscall *)(CBaseProp *, _BYTE *))this->GetModelName)(
                                           a1: this,
                                           a2: v16);
  if ( v2 != nullptr && *(_BYTE *)v2 != 0 )
  {
    CBaseEntity::PrecacheModel(a1: v2, name: (const char *)v2, bPreload: true);
    this->Precache(this);
    this->SetModel(this, a2: (const char *)v2);
    v3 = CBaseProp::ParsePropData(this);
    if ( !this->OverridePropdata(this) )
    {
      if ( v3 == 3 )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        pszValue = this->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        DevWarning(
          a1: "%s at %.0f %.0f %0.f uses model %s, which has an invalid prop_data type. DELETED.\n",
          pszValue,
          this->m_vecAbsOrigin.x,
          this->m_vecAbsOrigin.y,
          this->m_vecAbsOrigin.z,
          v2);
LABEL_14:
        UTIL_Remove(oldObj: this);
        return;
      }
      if ( v3 == 2 )
      {
        if ( FClassnameIs(pEntity: this, szClassname: "prop_physics") )
        {
          v17 = this->m_iClassname.pszValue;
          if ( v17 == nullptr )
            v17 = locale;
          AbsOrigin = CBaseEntity::GetAbsOrigin(this);
          z = CBaseEntity::GetAbsOrigin(this)->z;
          y = CBaseEntity::GetAbsOrigin(this)->y;
          DevWarning(
            a1: "%s at %.0f %.0f %0.f uses model %s, which has no propdata which means it must be used on a prop_static. DELETED.\n",
            v17,
            AbsOrigin->x,
            y,
            z,
            v2);
          goto LABEL_14;
        }
      }
      else if ( v3 == 0
             && __RTDynamicCast(
                  inptr: this,
                  VfDelta: 0,
                  SrcType: &CBaseProp `RTTI Type Descriptor',
                  TargetType: &CPhysicsProp `RTTI Type Descriptor',
                  isReference: 0) == nullptr )
      {
        v17 = this->m_iClassname.pszValue;
        if ( v17 == nullptr )
          v17 = locale;
        v6 = CBaseEntity::GetAbsOrigin(this);
        v15 = CBaseEntity::GetAbsOrigin(this)->z;
        v13 = CBaseEntity::GetAbsOrigin(this)->y;
        DevWarning(
          a1: "%s at %.0f %.0f %0.f uses model %s, which has propdata which means that it be used on a prop_physics. DELETED.\n",
          v17,
          v6->x,
          v13,
          v15,
          v2);
        goto LABEL_14;
      }
    }
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
    if ( this->m_takedamage.m_Value != 0 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      this->m_takedamage.m_Value = 0;
    }
    v7 = gpGlobals;
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
      this->m_flAnimTime.m_Value = v7->curtime;
    }
    if ( this->m_flPlaybackRate.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v9 = this->m_Network.m_pPev;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x37Cu);
      }
      this->m_flPlaybackRate.m_Value = 0.0;
    }
    if ( this->m_flCycle.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flCycle.m_Value = 0.0;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x3ACu);
        this->m_flCycle.m_Value = 0.0;
      }
    }
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v11 = this->m_iClassname.pszValue;
    if ( v11 == nullptr )
      v11 = locale;
    _Warning(
      a1: "prop %s at %.0f %.0f %0.f missing modelname\n",
      v11,
      this->m_vecAbsOrigin.x,
      this->m_vecAbsOrigin.y,
      this->m_vecAbsOrigin.z);
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4C40
// Name: private: class CBaseEntity __near * CBreakableProp::FindEnableMotionFixup(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBreakableProp::FindEnableMotionFixup(CBreakableProp *this)
{
  CBaseEntity **m_pMemory; // eax
  int v2; // esi
  CBaseEntity *v3; // ecx
  bool v4; // zf
  CBaseEntity *v6; // esi
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > list; // [esp+8h] [ebp-14h] BYREF

  memset(&list, 0, sizeof(list));
  GetAllChildren(pParent: this, &list);
  m_pMemory = list.m_Memory.m_pMemory;
  v2 = list.m_Size - 1;
  if ( list.m_Size - 1 < 0 )
  {
LABEL_6:
    list.m_Size = 0;
    if ( list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        list.m_Memory.m_pMemory = nullptr;
      }
      list.m_Memory.m_nAllocationCount = 0;
    }
    list.m_pElements = m_pMemory;
    if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v3 = m_pMemory[v2];
      if ( v3 != nullptr )
      {
        if ( v3->m_iClassname.pszValue == "point_enable_motion_fixup" )
          break;
        v4 = CBaseEntity::ClassMatchesComplex(this: v3, pszClassOrWildcard: "point_enable_motion_fixup") == 0;
        m_pMemory = list.m_Memory.m_pMemory;
        if ( !v4 )
          break;
      }
      if ( --v2 < 0 )
        goto LABEL_6;
    }
    v6 = m_pMemory[v2];
    list.m_Size = 0;
    if ( list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        list.m_Memory.m_pMemory = nullptr;
      }
      list.m_Memory.m_nAllocationCount = 0;
    }
    list.m_pElements = m_pMemory;
    if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4D30
// Name: protected: bool CBreakableProp::GetEnableMotionPosition(class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBreakableProp::GetEnableMotionPosition(CBreakableProp *this, Vector *pPosition, QAngle *pAngles)
{
  CBaseEntity *EnableMotionFixup; // esi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  EnableMotionFixup = CBreakableProp::FindEnableMotionFixup(this);
  if ( EnableMotionFixup == nullptr )
    return 0;
  if ( (EnableMotionFixup->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: EnableMotionFixup, a2: (int)&savedregs);
  *pPosition = EnableMotionFixup->m_vecAbsOrigin;
  if ( (EnableMotionFixup->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: EnableMotionFixup, a2: (int)&savedregs);
  *pAngles = EnableMotionFixup->m_angAbsRotation;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E4DB0
// Name: public: virtual void CBreakableProp::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::Event_Killed(CBreakableProp *this, const CTakeDamageInfo *info)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr && !m_pPhysicsObject->IsMoveable(this: this->m_pPhysicsObject) )
  {
    m_pPhysicsObject->EnableMotion(this: m_pPhysicsObject, a2: true);
    this->VPhysicsTakeDamage(this, a2: info);
  }
  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CBreakableProp::Break(this, pBreaker: m_pEntity, info);
  CBaseEntity::Event_Killed(this, info);
}

//------------------------------------------------------------------------------
// Address: 0x101E4E30
// Name: public: void CBreakableProp::InputBreak(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::InputBreak(CBreakableProp *this, inputdata_t *inputdata)
{
  CTakeDamageInfo info; // [esp+4h] [ebp-5Ch] BYREF

  CTakeDamageInfo::CTakeDamageInfo(this: &info);
  if ( this != nullptr )
    info.m_hAttacker.m_Index = this->GetRefEHandle(this)->m_Index;
  else
    info.m_hAttacker.m_Index = -1;
  CBreakableProp::Break(this, pBreaker: inputdata->pActivator, &info);
}

//------------------------------------------------------------------------------
// Address: 0x101E4E80
// Name: protected: bool CBreakableProp::UpdateHealth(int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBreakableProp::UpdateHealth(CBreakableProp *this, int iNewHealth, CBaseEntity *pActivator)
{
  int v3; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // ebx
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iMaxHealth> *p_m_iMaxHealth; // esi
  float v7; // xmm0_4
  int v8; // xmm1_4
  CTakeDamageInfo info; // [esp+18h] [ebp-5Ch] BYREF

  v3 = iNewHealth;
  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value == iNewHealth )
    return 1;
  this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
  p_m_iHealth->m_Value = v3;
  p_m_iMaxHealth = &this->m_iMaxHealth;
  if ( this->m_iMaxHealth.m_Value == 0 && p_m_iMaxHealth->m_Value != 1 )
  {
    this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
    p_m_iMaxHealth->m_Value = 1;
  }
  v7 = (float)p_m_iHealth->m_Value / (float)p_m_iMaxHealth->m_Value;
  v8 = 0;
  if ( v7 < 0.0 || (v8 = 1065353216, v7 > 1.0) )
    v7 = *(float *)&v8;
  iNewHealth = LODWORD(v7);
  variant_t::Set(
    this: &this->m_OnHealthChanged.m_Value,
    ftype: FIELD_FLOAT,
    data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&iNewHealth);
  CBaseEntityOutput::FireOutput(
    this: &this->m_OnHealthChanged,
    Value: this->m_OnHealthChanged.m_Value,
    pActivator,
    pCaller: this,
    fDelay: 0.0);
  if ( p_m_iHealth->m_Value > 0 )
    return 1;
  CTakeDamageInfo::CTakeDamageInfo(this: &info);
  info.m_hAttacker.m_Index = this->GetRefEHandle(this)->m_Index;
  CBreakableProp::Break(this, pBreaker: pActivator, &info);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E4FD0
// Name: public: void CBreakableProp::AnimateThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::AnimateThink(CBreakableProp *this)
{
  char m_nPhysgunState; // al
  int v3; // eax
  COutputEvent *p_m_OnPhysCannonAnimatePullStarted; // ecx

  m_nPhysgunState = this->m_nPhysgunState;
  if ( m_nPhysgunState == 6 || m_nPhysgunState == 7 )
  {
    CBaseAnimating::StudioFrameAdvanceManual(this, flInterval: 0.1);
    this->DispatchAnimEvents(this, a2: this);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: s_pPropAnimateThink);
    if ( this->IsActivityFinished(this) )
    {
      if ( this->m_nPhysgunState == 6 )
      {
        this->m_nPhysgunState = 4;
        v3 = CBaseAnimating::SelectWeightedSequence(this, activity: ACT_PHYSCANNON_ANIMATE);
        CBaseAnimating::ResetSequence(this, nSequence: v3);
        CBaseAnimating::SetPlaybackRate(this, rate: 1.0);
        CBaseAnimating::ResetClientsideFrame(this);
        p_m_OnPhysCannonAnimatePullStarted = &this->m_OnPhysCannonAnimatePullStarted;
      }
      else
      {
        this->m_nPhysgunState = 5;
        p_m_OnPhysCannonAnimatePullStarted = &this->m_OnPhysCannonPullAnimFinished;
      }
      COutputEvent::FireOutput(
        this: p_m_OnPhysCannonAnimatePullStarted,
        pActivator: nullptr,
        pCaller: this,
        fDelay: 0.0);
      CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: s_pPropAnimateThink);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E50D0
// Name: public: void CBreakableProp::BreakThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::BreakThink(CBreakableProp *this)
{
  unsigned int m_Index; // eax
  CTakeDamageInfo info; // [esp+4h] [ebp-5Ch] BYREF

  CTakeDamageInfo::CTakeDamageInfo(this: &info);
  if ( this != nullptr )
    info.m_hAttacker.m_Index = this->GetRefEHandle(this)->m_Index;
  else
    info.m_hAttacker.m_Index = -1;
  m_Index = this->m_hBreaker.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    CBreakableProp::Break(this, pBreaker: nullptr, &info);
  else
    CBreakableProp::Break(
      this,
      pBreaker: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity,
      &info);
}

//------------------------------------------------------------------------------
// Address: 0x101E5150
// Name: protected: void CDynamicProp::FinishSetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::FinishSetSequence(CDynamicProp *this, int nSequence)
{
  CNetworkVarBase<float,CBaseAnimating::NetworkVar_m_flCycle> *p_m_flCycle; // edx
  edict_t *m_pPev; // ecx
  CGlobalVars *v5; // ebx
  edict_t *v6; // ecx
  float v7; // xmm0_4
  edict_t *v8; // ecx
  float v9; // xmm0_4
  CNetworkVarBase<float,CBaseAnimating::NetworkVar_m_flCycle> *v10; // eax
  CBaseEdict *m_Value_low; // ecx
  CNetworkVarBase<float,CBaseAnimating::NetworkVar_m_flCycle> *v12; // [esp+Ch] [ebp-4h]

  p_m_flCycle = &this->m_flCycle;
  v12 = &this->m_flCycle;
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
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
        p_m_flCycle = v12;
      }
    }
    p_m_flCycle->m_Value = 0.0;
  }
  v5 = gpGlobals;
  if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x64u);
    }
    this->m_flAnimTime.m_Value = v5->curtime;
  }
  CBaseAnimating::ResetSequence(this, nSequence);
  CBaseAnimating::ResetClientsideFrame(this);
  CBaseEntity::RemoveFlag(this, flagsToRemove: 0x80000);
  if ( this->m_iTransitionDirection <= 0 )
    v7 = -1.0;
  else
    v7 = 1.0;
  this->m_bSequenceFinished = false;
  if ( this->m_flPlaybackRate.m_Value != v7 )
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
    this->m_flPlaybackRate.m_Value = v7;
  }
  if ( this->m_iTransitionDirection <= 0 )
    v9 = 0.99900001;
  else
    v9 = 0.0;
  if ( v12->m_Value != v9 )
  {
    v10 = v12 - 235;
    if ( LOBYTE(v12[-214].m_Value) != 0 )
    {
      LOBYTE(v10[22].m_Value) |= 1u;
      v12->m_Value = v9;
    }
    else
    {
      m_Value_low = (CBaseEdict *)LODWORD(v10[6].m_Value);
      if ( m_Value_low != nullptr )
        CBaseEdict::StateChanged(this: m_Value_low, offset: 0x3ACu);
      v12->m_Value = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E52E0
// Name: public: void CDynamicProp::PropSetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::PropSetSequence(CDynamicProp *this, int nSequence)
{
  float v3; // xmm0_4
  float nextCycle; // [esp+1Ch] [ebp-8h] BYREF
  int nNextSequence; // [esp+20h] [ebp-4h] BYREF
  int nSequencea; // [esp+2Ch] [ebp+8h]

  v3 = 1.0 - this->m_flFrozen.m_Value;
  this->m_iGoalSequence = nSequence;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 1.0 )
      v3 = 1.0;
  }
  else
  {
    v3 = 0.0;
  }
  if ( CBaseAnimating::GotoSequence(
         this,
         iCurrentSequence: this->m_nSequence.m_Value,
         flCurrentCycle: this->m_flCycle.m_Value,
         flCurrentRate: this->m_flPlaybackRate.m_Value * v3,
         iGoalSequence: nSequence,
         &nNextSequence,
         flNextCycle: &nextCycle,
         iNextDir: &this->m_iTransitionDirection) )
  {
    CDynamicProp::FinishSetSequence(this, nSequence: nNextSequence);
  }
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CDynamicProp::AnimThink,
    thinkTime: 0.0,
    szContext: nullptr);
  nSequencea = SLODWORD(gpGlobals->curtime);
  if ( *(float *)&nSequencea >= CBaseEntity::GetNextThink(this, szContext: nullptr) )
    CBaseEntity::SetNextThink(this, thinkTime: *(float *)&nSequencea + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101E53D0
// Name: public: virtual bool CPhysicsProp::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CPhysicsProp::CreateVPhysics@<al>(CPhysicsProp *this@<ecx>, int a2@<ebx>)
{
  CPhysicsProp_vtbl *v3; // edx
  int v4; // eax
  float m_massScale; // xmm0_4
  float m_inertiaScale; // xmm0_4
  IVModelInfo_vtbl *v7; // edi
  vcollide_t *v8; // eax
  IPhysicsObject *inited; // edi
  const char *v10; // eax
  unsigned __int16 v12; // ax
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // ax
  unsigned __int16 v15; // ax
  edict_t *m_pPev; // ecx
  solid_t *v17; // [esp-4h] [ebp-650h]
  solid_t tmpSolid; // [esp+8h] [ebp-644h] BYREF
  BOOL asleep; // [esp+648h] [ebp-4h] BYREF

  v3 = this->CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  LOBYTE(asleep) = this->m_spawnflags.m_Value & 1;
  v4 = ((int (*)(void))v3->GetModelIndex)();
  PhysModelParseSolid(solid: &tmpSolid, pEntity: this, modelIndex: v4);
  m_massScale = this->m_massScale;
  if ( m_massScale > 0.0 )
    tmpSolid.params.mass = m_massScale * tmpSolid.params.mass;
  m_inertiaScale = this->m_inertiaScale;
  if ( m_inertiaScale > 0.0 )
  {
    tmpSolid.params.inertia = m_inertiaScale * tmpSolid.params.inertia;
    if ( tmpSolid.params.inertia < 0.5 )
      tmpSolid.params.inertia = 0.5;
  }
  v7 = modelinfo->__vftable;
  v17 = (solid_t *)((int (__thiscall *)(CPhysicsProp *, solid_t *))this->GetModelIndex)(a1: this, a2: &tmpSolid);
  v8 = (vcollide_t *)((int (__thiscall *)(IVModelInfo *))v7->GetVCollide)(a1: modelinfo);
  PhysGetMassCenterOverride(pEntity: this, pCollide: v8, solidOut: v17);
  if ( (this->m_spawnflags.m_Value & 0x200000) != 0 )
    tmpSolid.params.enableCollisions = false;
  PhysSolidOverride(solid: &tmpSolid, overrideScript: this->m_iszOverrideScript);
  inited = CBaseEntity::VPhysicsInitNormal(
             this,
             solidType: SOLID_VPHYSICS,
             nSolidFlags: 0,
             createAsleep: asleep,
             pSolid: &tmpSolid);
  if ( inited != nullptr )
  {
    if ( this->m_damageType == 1 )
    {
      v12 = inited->GetGameFlags(this: inited);
      inited->SetGameFlags(this: inited, a2: v12 | 1);
    }
    if ( (this->m_spawnflags.m_Value & 8) != 0
      || this->m_damageToEnableMotion > 0
      || this->m_flForceToEnableMotion > 0.0 )
    {
      inited->EnableMotion(this: inited, a2: false);
      if ( this->m_damageToEnableMotion <= 0 && this->m_flForceToEnableMotion <= 0.0 )
        CCollisionProperty::SetSolidFlags(
          this: &this->m_Collision,
          flags: this->m_Collision.m_usSolidFlags.m_Value | 0x800);
    }
    if ( ((unsigned __int8 (__thiscall *)(IBreakableWithPropData *, int, int))this->HasInteraction)(
           a1: &this->IBreakableWithPropData,
           a2: 5,
           a3: a2) != 0
      && (((int (__thiscall *)(IPhysicsObject *))this->m_pPhysicsObject->GetGameFlags)(a1: this->m_pPhysicsObject) & 1) == 0 )
    {
      v13 = inited->GetGameFlags(this: inited);
      inited->SetGameFlags(this: inited, a2: v13 | 1);
    }
    if ( this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_DAMAGE_NONE) )
    {
      v14 = inited->GetGameFlags(this: inited);
      inited->SetGameFlags(this: inited, a2: v14 | 0x400);
    }
    if ( (this->m_spawnflags.m_Value & 0x200) != 0 )
    {
      v15 = inited->GetGameFlags(this: inited);
      inited->SetGameFlags(this: inited, a2: v15 | 0x80);
    }
    if ( (!inited->IsMoveable(this: inited)
       || ((double (__thiscall *)(IPhysicsObject *))inited->GetMass)(a1: inited) >= 500.0)
      && !this->m_bClientPhysics.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bClientPhysics.m_Value = true;
        return 1;
      }
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5E4u);
      this->m_bClientPhysics.m_Value = true;
    }
    return 1;
  }
  else
  {
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    v10 = *(const char **)((int (__thiscall *)(CPhysicsProp *, BOOL *))this->GetModelName)(a1: this, a2: &asleep);
    if ( v10 == nullptr )
      v10 = locale;
    _Warning(a1: "ERROR!: Can't create physics object for %s\n", v10);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5690
// Name: public: virtual void CPhysicsProp::OnPhysGunDrop(class CBasePlayer __near *,enum PhysGunDrop_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::OnPhysGunDrop(CPhysicsProp *this, CBasePlayer *pPhysGunUser, PhysGunDrop_t Reason)
{
  int v4; // ecx
  int v5; // ecx
  int v6; // edi
  unsigned __int16 v7; // ax
  IGameEvent *v8; // edi
  int v9; // eax
  signed int v10; // eax
  int i; // esi
  void *v12; // eax
  CBaseEntity **m_pMemory; // eax
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > list; // [esp+10h] [ebp-18h] BYREF
  float angDrag; // [esp+24h] [ebp-4h] BYREF

  CBreakableProp::OnPhysGunDrop(this, pPhysGunUser, Reason);
  if ( Reason == LAUNCHED_BY_CANNON )
  {
    if ( (*(unsigned __int8 (__thiscall **)(char *, int))(*((_DWORD *)this - 1) + 96))(a1: (char *)this - 4, a2: 5) != 0 )
    {
      v4 = *((_DWORD *)this - 210);
      list.m_Memory.m_nGrowSize = 0;
      list.m_Size = 0;
      list.m_pElements = (CBaseEntity **)1167867904;
      (*(void (__thiscall **)(int, _DWORD, int *))(*(_DWORD *)v4 + 212))(a1: v4, a2: 0, a3: &list.m_Memory.m_nGrowSize);
      v5 = *((_DWORD *)this - 210);
      angDrag = 0.0;
      (*(void (__thiscall **)(int, _DWORD, float *))(*(_DWORD *)v5 + 144))(a1: v5, a2: 0, a3: &angDrag);
    }
    v6 = *((_DWORD *)this - 210);
    v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 76))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 72))(a1: v6, a2: v7 | 0x100);
    BYTE1(this->m_OnUser2.m_Value.vecVal[1]) = 1;
  }
  else if ( Reason == THROWN_BY_PLAYER )
  {
    *((_BYTE *)&this->m_OnUser2.m_Value.flVal + 4) = 1;
  }
  COutputEvent::FireOutput(
    this: (COutputEvent *)&this->m_vecAbsOrigin.z,
    pActivator: pPhysGunUser,
    pCaller: (CPhysicsProp *)((char *)this - 1168),
    fDelay: 0.0);
  v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_drop", a3: 0, a4: 0);
  if ( v8 != nullptr )
  {
    if ( pPhysGunUser != nullptr )
      v9 = engine->GetPlayerUserId(this: engine, a2: pPhysGunUser->m_Network.m_pPev);
    else
      v9 = 0;
    v8->SetInt(this: v8, a2: "userid", a3: v9);
    v10 = *((_DWORD *)this - 286);
    if ( v10 != 0 )
      v10 = (signed int)(v10 - (unsigned int)gpGlobals->pEdicts) >> 4;
    v8->SetInt(this: v8, a2: "entity", a3: v10);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
  }
  if ( (*(unsigned __int8 (__thiscall **)(char *, int))(*((_DWORD *)this - 1) + 96))(a1: (char *)this - 4, a2: 15) != 0 )
  {
    memset(&list, 0, sizeof(list));
    GetAllChildren(pParent: (CPhysicsProp *)((char *)this - 1168), &list);
    for ( i = 0; i < list.m_Size; ++i )
    {
      v12 = __RTDynamicCast(
              inptr: list.m_Memory.m_pMemory[i],
              VfDelta: 0,
              SrcType: &CBaseEntity `RTTI Type Descriptor',
              TargetType: &IParentPropInteraction `RTTI Type Descriptor',
              isReference: 0);
      if ( v12 != nullptr )
        (*(void (__thiscall **)(void *, CBasePlayer *, PhysGunDrop_t))(*(_DWORD *)v12 + 4))(
          a1: v12,
          a2: pPhysGunUser,
          a3: Reason);
    }
    m_pMemory = list.m_Memory.m_pMemory;
    list.m_Size = 0;
    if ( list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( list.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        list.m_Memory.m_pMemory = nullptr;
      }
      list.m_Memory.m_nAllocationCount = 0;
    }
    list.m_pElements = m_pMemory;
    if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E58B0
// Name: public: CBasePropDoor::CBasePropDoor(void)
// Source: json
//------------------------------------------------------------------------------
CBasePropDoor *__thiscall CBasePropDoor::CBasePropDoor(CBasePropDoor *this)
{
  CDynamicProp::CDynamicProp(this);
  this->CDynamicProp::CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBasePropDoor_vtbl *)&CBasePropDoor::`vftable'{for `CBaseProp'};
  this->CDynamicProp::CBreakableProp::IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CBasePropDoor::`vftable'{for `IBreakableWithPropData'};
  this->CDynamicProp::CBreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CBasePropDoor::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->CDynamicProp::IPositionWatcher::IWatcherCallback::__vftable = (IPositionWatcher_vtbl *)&CBasePropDoor::`vftable';
  this->m_hDoorList.m_Memory.m_pMemory = nullptr;
  this->m_hDoorList.m_Memory.m_nAllocationCount = 0;
  this->m_hDoorList.m_Memory.m_nGrowSize = 0;
  this->m_hDoorList.m_Size = 0;
  this->m_hDoorList.m_pElements = nullptr;
  this->m_ls.__vftable = (locksound_t_vtbl *)&locksound_t::`vftable';
  this->m_hActivator.m_Index = -1;
  this->m_hBlocker.m_Index = -1;
  this->m_OnBlockedClosing.m_Value.iVal = 0;
  this->m_OnBlockedClosing.m_Value.eVal.m_Index = -1;
  this->m_OnBlockedClosing.m_Value.fieldType = FIELD_VOID;
  this->m_OnBlockedOpening.m_Value.iVal = 0;
  this->m_OnBlockedOpening.m_Value.eVal.m_Index = -1;
  this->m_OnBlockedOpening.m_Value.fieldType = FIELD_VOID;
  this->m_OnUnblockedClosing.m_Value.iVal = 0;
  this->m_OnUnblockedClosing.m_Value.eVal.m_Index = -1;
  this->m_OnUnblockedClosing.m_Value.fieldType = FIELD_VOID;
  this->m_OnUnblockedOpening.m_Value.iVal = 0;
  this->m_OnUnblockedOpening.m_Value.eVal.m_Index = -1;
  this->m_OnUnblockedOpening.m_Value.fieldType = FIELD_VOID;
  this->m_OnFullyClosed.m_Value.iVal = 0;
  this->m_OnFullyClosed.m_Value.eVal.m_Index = -1;
  this->m_OnFullyClosed.m_Value.fieldType = FIELD_VOID;
  this->m_OnFullyOpen.m_Value.iVal = 0;
  this->m_OnFullyOpen.m_Value.eVal.m_Index = -1;
  this->m_OnFullyOpen.m_Value.fieldType = FIELD_VOID;
  this->m_OnClose.m_Value.iVal = 0;
  this->m_OnClose.m_Value.eVal.m_Index = -1;
  this->m_OnClose.m_Value.fieldType = FIELD_VOID;
  this->m_OnOpen.m_Value.iVal = 0;
  this->m_OnOpen.m_Value.eVal.m_Index = -1;
  this->m_OnOpen.m_Value.fieldType = FIELD_VOID;
  this->m_OnLockedUse.m_Value.iVal = 0;
  this->m_OnLockedUse.m_Value.eVal.m_Index = -1;
  this->m_OnLockedUse.m_Value.fieldType = FIELD_VOID;
  this->m_hMaster.m_Index = -1;
  this->m_nPhysicsMaterial = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E59D0
// Name: public: virtual bool CBasePropDoor::IsDoorLocked(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePropDoor::IsDoorLocked(CBasePropDoor *this)
{
  return this->m_bLocked;
}

//------------------------------------------------------------------------------
// Address: 0x101E59F0
// Name: public: virtual CBasePropDoor::~CBasePropDoor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::~CBasePropDoor(CBasePropDoor *this)
{
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnLockedUse);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnOpen);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnClose);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnFullyOpen);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnFullyClosed);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUnblockedOpening);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUnblockedClosing);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnBlockedOpening);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnBlockedClosing);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hDoorList);
  CBoneFollowerManager::~CBoneFollowerManager(this: &this->m_BoneFollowerManager);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_pOutputAnimOver);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_pOutputAnimBegun);
  this->CDynamicProp::IPositionWatcher::IWatcherCallback::__vftable = (IPositionWatcher_vtbl *)&IWatcherCallback::`vftable';
  CBreakableProp::~CBreakableProp(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E5AA0
// Name: protected: void CBasePropDoor::DoorClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::DoorClose(CBasePropDoor *this)
{
  CBasePropDoor::DoorState_t m_eDoorState; // eax
  const char *pszValue; // eax
  unsigned int m_Index; // eax
  CBaseEntity *v5; // eax
  const Vector *AbsOrigin; // eax
  void (__thiscall *BeginClosing)(CBasePropDoor *); // eax
  int m_Size; // ebx
  int i; // edi
  unsigned int v10; // eax
  CBasePropDoor *m_pEntity; // ecx

  m_eDoorState = this->m_eDoorState;
  if ( m_eDoorState != DOOR_STATE_CLOSED && m_eDoorState != DOOR_STATE_CLOSING )
  {
    if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
    {
      pszValue = this->m_SoundMoving.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      CBaseEntity::EmitSound(this, soundname: pszValue, soundtime: 0.0, duration: nullptr);
      m_Index = this->m_hActivator.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        v5 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
        if ( v5->IsPlayer(this: v5) )
        {
          AbsOrigin = CBaseEntity::GetAbsOrigin(this);
          CSoundEnt::InsertSound(
            iType: 4,
            vecOrigin: AbsOrigin,
            iVolume: 512,
            flDuration: 0.5,
            pOwner: this,
            soundChannelIndex: 0,
            pSoundTarget: nullptr);
        }
      }
    }
    BeginClosing = this->BeginClosing;
    this->m_eDoorState = DOOR_STATE_CLOSING;
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CBasePropDoor::DoorCloseMoveDone;
    BeginClosing(this);
    COutputEvent::FireOutput(this: &this->m_OnClose, pActivator: this, pCaller: this, fDelay: 0.0);
    m_Size = this->m_hDoorList.m_Size;
    if ( m_Size > 0 )
    {
      for ( i = 0; i < m_Size; ++i )
      {
        v10 = this->m_hDoorList.m_Memory.m_pMemory[i].m_Index;
        if ( v10 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber == HIWORD(v10) )
        {
          m_pEntity = (CBasePropDoor *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
          if ( m_pEntity != nullptr )
            CBasePropDoor::DoorClose(this: m_pEntity);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5BF0
// Name: public: virtual CPropDoorRotating::~CPropDoorRotating(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::~CPropDoorRotating(CPropDoorRotating *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // eax

  this->CBasePropDoor::CDynamicProp::CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPropDoorRotating_vtbl *)&CPropDoorRotating::`vftable'{for `CBaseProp'};
  this->CBasePropDoor::CDynamicProp::CBreakableProp::IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CPropDoorRotating::`vftable'{for `IBreakableWithPropData'};
  this->CBasePropDoor::CDynamicProp::CBreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPropDoorRotating::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->CBasePropDoor::CDynamicProp::IPositionWatcher::IWatcherCallback::__vftable = (IPositionWatcher_vtbl *)&CPropDoorRotating::`vftable';
  m_Index = this->m_hDoorBlocker.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        v9 = *v8;
      else
        v9 = nullptr;
      UTIL_Remove(oldObj: v9);
    }
  }
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnRotationDone);
  CBasePropDoor::~CBasePropDoor(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E5CC0
// Name: public: virtual void CPropDoorRotatingBreakable::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotatingBreakable::Event_Killed(CPropDoorRotatingBreakable *this, const CTakeDamageInfo *info)
{
  int m_Size; // eax
  int v4; // edi
  const Vector *v5; // ebx
  float z; // eax
  double v7; // st7
  float x; // xmm2_4
  float y; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  unsigned __int8 r; // al
  unsigned __int8 g; // cl
  int m_Value; // edx
  unsigned __int8 b; // bl
  int m_iEFlags; // eax
  unsigned int v17; // ecx
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  ITempEntsSystem_vtbl *v21; // edi
  int v22; // eax
  string_t *v23; // eax
  const char *v24; // eax
  string_t v25; // eax
  int fDelay; // [esp+2Ch] [ebp-C0h]
  CFmtStrN<80> str; // [esp+3Ch] [ebp-B0h] BYREF
  CPASFilter filter; // [esp+98h] [ebp-54h] BYREF
  char pszValue[4]; // [esp+B8h] [ebp-34h] BYREF
  _DWORD v30[3]; // [esp+BCh] [ebp-30h] BYREF
  int targetDamageState; // [esp+C8h] [ebp-24h]
  Vector force; // [esp+CCh] [ebp-20h] BYREF
  float forceLen; // [esp+D8h] [ebp-14h]
  color24 color; // [esp+DCh] [ebp-10h]
  Vector offset; // [esp+E0h] [ebp-Ch] BYREF
  int savedregs; // [esp+ECh] [ebp+0h] BYREF

  m_Size = this->m_damageStates.m_Size;
  if ( m_Size != 0 )
  {
    v4 = m_Size - 1;
    targetDamageState = m_Size - 1;
    if ( m_Size - 1 > this->m_currentDamageState )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      PhysBreakSound(pEntity: this, pPhysObject: this->m_pPhysicsObject, vecOrigin: this->m_vecAbsOrigin);
      v5 = this->WorldSpaceCenter(this);
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
      CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v5);
      if ( v4 > this->m_currentDamageState )
      {
        do
        {
          z = info->m_vecDamageForce.z;
          *(_QWORD *)&offset.x = *(_QWORD *)&info->m_vecDamageForce.x;
          offset.z = z;
          v7 = VectorNormalize(vec: &offset);
          forceLen = v7;
          force = offset;
          x = offset.x * 10.0;
          y = offset.y * 10.0;
          v10 = offset.z * 10.0;
          offset.x = offset.x * 10.0;
          offset.y = offset.y * 10.0;
          offset.z = offset.z * 10.0;
          if ( v7 >= 300.0 )
            v11 = 300.0;
          else
            v11 = forceLen;
          r = this->m_clrRender.m_Value.r;
          g = this->m_clrRender.m_Value.g;
          m_Value = this->m_fEffects.m_Value;
          b = this->m_clrRender.m_Value.b;
          force.x = v11 * force.x;
          color.r = r;
          m_iEFlags = this->m_iEFlags;
          force.y = force.y * v11;
          force.z = force.z * v11;
          color.g = g;
          forceLen = *(float *)&m_Value;
          if ( (m_iEFlags & 0x800) != 0 )
          {
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
            v10 = offset.z;
            y = offset.y;
            x = offset.x;
          }
          v17 = (unsigned int)this->m_iEFlags >> 11;
          if ( (this->m_iEFlags & 0x800) != 0 )
          {
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
            v10 = offset.z;
            y = offset.y;
            x = offset.x;
          }
          HIBYTE(fDelay) = HIBYTE(v17);
          v18 = this->m_vecAbsOrigin.x + x;
          v19 = this->m_vecAbsOrigin.y + y;
          v20 = this->m_vecAbsOrigin.z + v10;
          LOWORD(fDelay) = *(_WORD *)&color.r;
          *(float *)v30 = v18;
          *(float *)&v30[1] = v19;
          *(float *)&v30[2] = v20;
          v21 = te->__vftable;
          BYTE2(fDelay) = b;
          v22 = ((int (__thiscall *)(CPropDoorRotatingBreakable *, int, _DWORD *, QAngle *, Vector *, int, _DWORD, int))this->GetModelIndex)(
                  a1: this,
                  a2: this->m_nSkin.m_Value,
                  a3: v30,
                  a4: &this->m_angAbsRotation,
                  a5: &force,
                  a6: 1,
                  a7: LODWORD(forceLen),
                  a8: fDelay);
          ((void (__thiscall *)(ITempEntsSystem *, CPASFilter *, int, int))v21->PhysicsProp)(
            a1: te,
            a2: &filter,
            a3: -1082130432,
            a4: v22);
          v23 = &this->m_damageStates.m_Memory.m_pMemory[++this->m_currentDamageState];
          str.__vftable = (CFmtStrN<80>_vtbl *)&CFmtStrN<80>::`vftable';
          *(_WORD *)&str.m_bQuietTruncation = 1;
          str.m_nLength = 0;
          v24 = v23->pszValue;
          if ( v24 == nullptr )
            v24 = locale;
          CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "models/%s.mdl", v24);
          V_FixSlashes(pname: str.m_szBuf, separator: 47);
          v25.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
          if ( v25.pszValue == nullptr )
            v25.pszValue = locale;
          this->SetModel(this, a2: v25.pszValue);
        }
        while ( targetDamageState > this->m_currentDamageState );
      }
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
  if ( this->m_eDoorState == DOOR_STATE_CLOSED )
    CBasePropDoor::UpdateAreaPortals(this, isOpen: true);
  COutputEvent::FireOutput(this: &this->m_OnBreak, pActivator: this, pCaller: this, fDelay: 0.0);
  CBreakableProp::Event_Killed(this, info);
}

//------------------------------------------------------------------------------
// Address: 0x101E5FE0
// Name: public: virtual int CPropDoorRotatingBreakable::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropDoorRotatingBreakable::OnTakeDamage(CPropDoorRotatingBreakable *this, const CTakeDamageInfo *info)
{
  int m_Value; // ebx
  int m_bitsDamageType; // eax
  int v6; // eax
  int v7; // edi
  int m_Size; // eax
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // ebx
  bool v14; // zf
  Activity SequenceActivity; // eax
  float v16; // xmm0_4
  IPhysicsObject *m_pPhysicsObject; // edi
  const Vector *v18; // eax
  unsigned __int8 g; // al
  unsigned __int8 b; // bl
  int v21; // edi
  unsigned int v22; // ecx
  int v23; // eax
  string_t *v24; // eax
  const char *v25; // eax
  string_t v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // edi
  IVModelInfo_vtbl *v29; // ebx
  IVModelInfo_vtbl *v30; // ebx
  model_t *v31; // eax
  const char *v32; // eax
  bool v33; // al
  KeyValues *v34; // ecx
  IBreakableWithPropData_vtbl *v35; // ebx
  IBreakableWithPropData_vtbl *v36; // ebx
  IBreakableWithPropData_vtbl *v37; // ebx
  double v38; // st7
  KeyValues *v39; // edi
  bool v40; // al
  int Int; // eax
  int v42; // eax
  int v43; // [esp+30h] [ebp-C8h]
  const char *Model; // [esp+34h] [ebp-C4h]
  int defaultValue; // [esp+40h] [ebp-B8h]
  float defaultValuea; // [esp+40h] [ebp-B8h]
  float defaultValueb; // [esp+40h] [ebp-B8h]
  float defaultValuec; // [esp+40h] [ebp-B8h]
  float defaultValued; // [esp+40h] [ebp-B8h]
  float defaultValuee; // [esp+40h] [ebp-B8h]
  float defaultValuef; // [esp+40h] [ebp-B8h]
  float defaultValueg; // [esp+40h] [ebp-B8h]
  CPASFilter filter; // [esp+50h] [ebp-A8h] BYREF
  CFmtStrN<80> str; // [esp+70h] [ebp-88h] BYREF
  Vector addedVelocity; // [esp+CCh] [ebp-2Ch] BYREF
  char pszValue[4]; // [esp+D8h] [ebp-20h] BYREF
  int ret; // [esp+DCh] [ebp-1Ch]
  Activity mainActivity; // [esp+E0h] [ebp-18h]
  float mainCycle; // [esp+E4h] [ebp-14h]
  color24 color; // [esp+E8h] [ebp-10h]
  int v61; // [esp+ECh] [ebp-Ch]
  KeyValues *pkvPropData; // [esp+F0h] [ebp-8h]
  KeyValues *modelKeyValues; // [esp+F4h] [ebp-4h]
  int savedregs; // [esp+F8h] [ebp+0h] BYREF
  Vector v65; // 0:^38.12

  m_Value = this->m_iHealth.m_Value;
  CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&str, __that: info);
  m_bitsDamageType = info->m_bitsDamageType;
  if ( (m_bitsDamageType & 0x40) != 0 && (info->m_flDamage >= 40.0 || (m_bitsDamageType & 0x8000000) != 0) )
    *(float *)&str.m_szBuf[43] = (float)this->m_iMaxHealth.m_Value;
  if ( !this->m_bBreakable )
    return 0;
  v6 = CBreakableProp::OnTakeDamage(
         this,
         a2: (int)&savedregs,
         a3: (int)info,
         a4: (int)this,
         inputInfo: (const CTakeDamageInfo *)&str);
  v7 = this->m_iHealth.m_Value;
  ret = v6;
  if ( m_Value != v7 && v7 > 0 )
  {
    m_Size = this->m_damageStates.m_Size;
    if ( m_Size > 0 )
    {
      v9 = this->m_iMaxHealth.m_Value / (m_Size + 1);
      v10 = -1;
      if ( v7 < this->m_iMaxHealth.m_Value - v9 )
      {
        v11 = this->m_iMaxHealth.m_Value - v9;
        do
        {
          v11 -= v9;
          ++v10;
        }
        while ( v7 < v11 );
      }
      v12 = this->m_damageStates.m_Size - 1;
      if ( v10 >= -1 )
      {
        v61 = this->m_damageStates.m_Size - 1;
        if ( v10 <= v12 )
          v61 = v10;
      }
      else
      {
        v61 = -1;
      }
      v13 = v61;
      if ( v61 > this->m_currentDamageState )
      {
        v14 = this->m_eDoorState == DOOR_STATE_CLOSED;
        this->m_isAbleToCloseAreaPortals = false;
        if ( v14 )
          CBasePropDoor::UpdateAreaPortals(this, isOpen: true);
        SequenceActivity = CBaseAnimating::GetSequenceActivity(this, iSequence: this->m_nSequence.m_Value);
        v16 = this->m_flCycle.m_Value;
        m_pPhysicsObject = this->m_pPhysicsObject;
        mainActivity = SequenceActivity;
        mainCycle = v16;
        v65 = *CBaseEntity::GetAbsOrigin(this);
        PhysBreakSound(pEntity: this, pPhysObject: m_pPhysicsObject, vecOrigin: v65);
        v18 = this->WorldSpaceCenter(this);
        CPASFilter::CPASFilter(this: &filter, origin: v18);
        if ( v13 > this->m_currentDamageState )
        {
          do
          {
            GetVelocityFromDamageForce(result: &addedVelocity, info, pEntity: this);
            g = this->m_clrRender.m_Value.g;
            b = this->m_clrRender.m_Value.b;
            v21 = this->m_fEffects.m_Value;
            v22 = (unsigned int)this->m_iEFlags >> 11;
            color.r = this->m_clrRender.m_Value.r;
            color.g = g;
            if ( (v22 & 1) != 0 )
              CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
            HIBYTE(defaultValue) = HIBYTE(v22);
            modelKeyValues = (KeyValues *)te->__vftable;
            LOWORD(defaultValue) = *(_WORD *)&color.r;
            BYTE2(defaultValue) = b;
            v23 = ((int (__thiscall *)(CPropDoorRotatingBreakable *, int, Vector *, QAngle *, Vector *, int, int, int))this->GetModelIndex)(
                    a1: this,
                    a2: this->m_nSkin.m_Value,
                    a3: &this->m_vecAbsOrigin,
                    a4: &this->m_angAbsRotation,
                    a5: &addedVelocity,
                    a6: 1,
                    a7: v21,
                    a8: defaultValue);
            ((void (__thiscall *)(ITempEntsSystem *, CPASFilter *, int, int))modelKeyValues[4].m_iValue)(
              a1: te,
              a2: &filter,
              a3: -1082130432,
              a4: v23);
            v24 = &this->m_damageStates.m_Memory.m_pMemory[++this->m_currentDamageState];
            str.__vftable = (CFmtStrN<80>_vtbl *)&CFmtStrN<80>::`vftable';
            *(_WORD *)&str.m_bQuietTruncation = 1;
            str.m_nLength = 0;
            v25 = v24->pszValue;
            if ( v25 == nullptr )
              v25 = locale;
            CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "models/%s.mdl", v25);
            V_FixSlashes(pname: str.m_szBuf, separator: 47);
            v26.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
            if ( v26.pszValue == nullptr )
              v26.pszValue = locale;
            this->SetModel(this, a2: v26.pszValue);
            this->VPhysicsDestroyObject(this);
            CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
            v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v27 != nullptr )
            {
              v28 = KeyValues::KeyValues(this: v27, setName: locale);
              modelKeyValues = v28;
            }
            else
            {
              v28 = nullptr;
              modelKeyValues = nullptr;
            }
            v29 = modelinfo->__vftable;
            Model = (const char *)CBaseEntity::GetModel(this);
            v43 = ((int (__thiscall *)(IVModelInfo *))v29->GetModelKeyValueText)(a1: modelinfo);
            v30 = modelinfo->__vftable;
            v31 = CBaseEntity::GetModel(this);
            v32 = (const char *)((int (__thiscall *)(IVModelInfo *, model_t *, int))v30->GetModelName)(
                                  a1: modelinfo,
                                  a2: v31,
                                  a3: v43);
            v33 = KeyValues::LoadFromBuffer(
                    this: v28,
                    resourceName: v32,
                    pBuffer: Model,
                    pFileSystem: nullptr,
                    pPathID: nullptr,
                    pfnEvaluateSymbolProc: nullptr);
            v34 = v28;
            if ( v33 )
            {
              pkvPropData = KeyValues::FindKey(this: v28, keyName: "prop_data", bCreate: false);
              if ( pkvPropData != nullptr )
              {
                v35 = this->CPropDoorRotating::CBasePropDoor::CDynamicProp::CBreakableProp::IBreakableWithPropData::__vftable;
                defaultValuea = v35->GetDmgModBullet(this: &this->IBreakableWithPropData);
                defaultValueb = KeyValues::GetFloat(
                                  this: pkvPropData,
                                  keyName: "dmg.bullets",
                                  defaultValue: defaultValuea);
                ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v35->SetDmgModBullet)(
                  a1: &this->IBreakableWithPropData,
                  a2: LODWORD(defaultValueb));
                v36 = this->CPropDoorRotating::CBasePropDoor::CDynamicProp::CBreakableProp::IBreakableWithPropData::__vftable;
                defaultValuec = v36->GetDmgModClub(this: &this->IBreakableWithPropData);
                defaultValued = KeyValues::GetFloat(this: pkvPropData, keyName: "dmg.club", defaultValue: defaultValuec);
                ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v36->SetDmgModClub)(
                  a1: &this->IBreakableWithPropData,
                  a2: LODWORD(defaultValued));
                v37 = this->CPropDoorRotating::CBasePropDoor::CDynamicProp::CBreakableProp::IBreakableWithPropData::__vftable;
                defaultValuee = v37->GetDmgModExplosive(this: &this->IBreakableWithPropData);
                defaultValuef = KeyValues::GetFloat(
                                  this: pkvPropData,
                                  keyName: "dmg.explosive",
                                  defaultValue: defaultValuee);
                ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v37->SetDmgModExplosive)(
                  a1: &this->IBreakableWithPropData,
                  a2: LODWORD(defaultValuef));
                v38 = ((double (__thiscall *)(IBreakableWithPropData *))this->GetDmgModFire)(a1: &this->IBreakableWithPropData);
                v39 = pkvPropData;
                defaultValueg = v38;
                this->m_flDmgModFire = KeyValues::GetFloat(
                                         this: pkvPropData,
                                         keyName: "dmg.fire",
                                         defaultValue: defaultValueg);
                v40 = CBaseEntity::BlocksLOS(this);
                Int = KeyValues::GetInt(this: v39, keyName: "blocklos", defaultValue: v40);
                CBaseEntity::SetBlocksLOS(this, bBlocksLOS: Int != 0);
                if ( KeyValues::GetInt(this: v39, keyName: "isdebris", defaultValue: 0) != 0 )
                  CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
                v28 = modelKeyValues;
              }
              v34 = v28;
            }
            KeyValues::deleteThis(this: v34);
          }
          while ( v61 > this->m_currentDamageState );
        }
        v42 = CBaseAnimating::SelectWeightedSequence(this, activity: mainActivity);
        if ( v42 >= 0 )
        {
          CBaseAnimating::SetSequence(this, nSequence: v42);
          CBaseAnimating::SetCycle(this, flCycle: mainCycle);
        }
        COutputEvent::FireOutput(this: &this->m_OnBreak, pActivator: this, pCaller: this, fDelay: 0.0);
        CRecipientFilter::~CRecipientFilter(this: &filter);
      }
    }
  }
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x101E64C0
// Name: public: CPhysicsPropMultiplayer::CPhysicsPropMultiplayer(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsPropMultiplayer *__thiscall CPhysicsPropMultiplayer::CPhysicsPropMultiplayer(CPhysicsPropMultiplayer *this)
{
  CPhysicsPropMultiplayer *result; // eax
  edict_t *m_pPev; // ecx

  CPhysicsProp::CPhysicsProp(this);
  this->IMultiplayerPhysics::__vftable = (IMultiplayerPhysics_vtbl *)&IMultiplayerPhysics::`vftable';
  this->CPhysicsProp::CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPhysicsPropMultiplayer_vtbl *)&CPhysicsPropMultiplayer::`vftable'{for `CBaseProp'};
  this->CPhysicsProp::CBreakableProp::IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CPhysicsPropMultiplayer::`vftable'{for `IBreakableWithPropData'};
  this->CPhysicsProp::CBreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPhysicsPropMultiplayer::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->CPhysicsProp::INavAvoidanceObstacle::__vftable = (INavAvoidanceObstacle_vtbl *)&CPhysicsPropMultiplayer::`vftable'{for `CPhysicsProp'};
  this->IMultiplayerPhysics::__vftable = (IMultiplayerPhysics_vtbl *)&CPhysicsPropMultiplayer::`vftable'{for `IMultiplayerPhysics'};
  result = this;
  if ( this->m_iPhysicsMode.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x6F4u);
    }
    this->m_iPhysicsMode.m_Value = 0;
    result = this;
  }
  this->m_usingCustomCollisionBounds = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E6550
// Name: public: virtual int CPhysicsPropMultiplayer::GetPhysicsMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsPropMultiplayer::GetPhysicsMode(CPhysicsPropMultiplayer *this)
{
  return LODWORD(this->m_OnUser3.m_Value.vecVal[2]);
}

//------------------------------------------------------------------------------
// Address: 0x101E6560
// Name: public: virtual float CPhysicsPropMultiplayer::GetMass(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsPropMultiplayer::GetMass(CHLTVDirector *this)
{
  return *(float *)&this->m_bRegisteredForEvents;
}

//------------------------------------------------------------------------------
// Address: 0x101E6570
// Name: public: virtual bool CPhysicsPropMultiplayer::IsAsleep(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPhysicsPropMultiplayer::IsAsleep(CPhysicsPropMultiplayer *this)
{
  return *((_BYTE *)this - 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E6580
// Name: public: virtual void CPhysicsPropMultiplayer::ComputeWorldSpaceSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPropMultiplayer::ComputeWorldSpaceSurroundingBox(
        CPhysicsPropMultiplayer *this,
        Vector *mins,
        Vector *maxs)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( mins != nullptr && maxs != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    TransformAABB(
      transform: &this->m_rgflCoordinateFrame,
      vecMinsIn: &this->m_collisionMins.m_Value,
      vecMaxsIn: &this->m_collisionMaxs.m_Value,
      vecMinsOut: mins,
      vecMaxsOut: maxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E65D0
// Name: public: virtual void CPhysicsPropMultiplayer::SetPhysicsMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPropMultiplayer::SetPhysicsMode(CPhysicsPropMultiplayer *this, int iMode)
{
  float *v2; // esi
  char *v3; // eax
  CBaseEdict *v4; // ecx

  v2 = &this->m_OnUser3.m_Value.vecVal[2];
  if ( LODWORD(this->m_OnUser3.m_Value.vecVal[2]) != iMode )
  {
    v3 = (char *)this - 1164;
    if ( *((_BYTE *)this - 1080) != 0 )
    {
      v3[88] |= 1u;
      *(_DWORD *)v2 = iMode;
    }
    else
    {
      v4 = *((CBaseEdict **)v3 + 6);
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: v4, offset: 0x6F4u);
      *(_DWORD *)v2 = iMode;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6620
// Name: public: void CPhysicsPropRespawnable::Materialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPropRespawnable::Materialize(CPhysicsPropRespawnable *this)
{
  int m_Value; // eax
  unsigned int v3; // ebx
  edict_t *m_pPev; // ecx
  CGameTrace tr; // [esp+Ch] [ebp-54h] BYREF
  IHandleEntity savedregs; // [esp+60h] [ebp+0h] BYREF

  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &this->m_vOriginalSpawnOrigin,
    vecAbsEnd: &this->m_vOriginalSpawnOrigin,
    hullMin: &this->m_vOriginalMins,
    hullMax: &this->m_vOriginalMaxs,
    mask: 0x200400Bu,
    ignore: this,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.startsolid || tr.allsolid )
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
  }
  else
  {
    m_Value = this->m_fEffects.m_Value;
    v3 = m_Value & 0xFFFFFFDF;
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
      this->m_fEffects.m_Value = v3;
    }
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
    this->Spawn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E68E0
// Name: public: virtual bool CPhysBoxMultiplayer::IsAsleep(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysBoxMultiplayer::IsAsleep(CPhysBoxMultiplayer *this)
{
  return (*(bool (__thiscall **)(_DWORD))(**((_DWORD **)this - 234) + 8))(a1: *((_DWORD *)this - 234));
}

//------------------------------------------------------------------------------
// Address: 0x101E6920
// Name: public: virtual void CPhysBoxMultiplayer::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBoxMultiplayer::Activate(CPhysBoxMultiplayer *this)
{
  double v2; // st7
  edict_t *m_pPev; // ecx
  float v4; // [esp+4h] [ebp-4h]

  CBaseEntity::Activate(this);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 17);
  v2 = ((double (__thiscall *)(IPhysicsObject *))this->m_pPhysicsObject->GetMass)(a1: this->m_pPhysicsObject);
  v4 = v2;
  if ( this->m_fMass.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_fMass.m_Value = v4;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4F8u);
      this->m_fMass.m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6A20
// Name: public: bool NavAreaCollector::operator()(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall NavAreaCollector::operator()(NavAreaCollector *this, CNavArea *area)
{
  int m_Size; // esi
  int v3; // eax
  CNavArea **m_pMemory; // edx
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_area; // esi
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  if ( !this->m_checkForDuplicates )
    goto LABEL_8;
  m_Size = this->m_area.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    goto LABEL_8;
  m_pMemory = this->m_area.m_Memory.m_pMemory;
  while ( *m_pMemory != area )
  {
    ++v3;
    ++m_pMemory;
    if ( v3 >= m_Size )
      goto LABEL_8;
  }
  if ( v3 < 0 )
  {
LABEL_8:
    m_nAllocationCount = this->m_area.m_Memory.m_nAllocationCount;
    p_m_area = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_area;
    v7 = this->m_area.m_Size;
    if ( v7 + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_area, num: v7 - m_nAllocationCount + 1);
    ++p_m_area[1].m_pMemory;
    v8 = p_m_area->m_pMemory;
    v9 = (int)p_m_area[1].m_pMemory - v7 - 1;
    p_m_area[1].m_nAllocationCount = (int)p_m_area->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_area->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)area;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E6AB0
// Name: protected: void CBreakableProp::CheckRemoveRagdolls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::CheckRemoveRagdolls(CBreakableProp *this)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  unsigned int v2; // edi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v3; // eax
  CBaseEdict *m_Value; // ecx

  p_m_spawnflags = &this->m_spawnflags;
  if ( (this->m_spawnflags.m_Value & 0x800) != 0 )
  {
    DetachAttachedRagdollsForEntity(pRagdollParent: this);
    v2 = p_m_spawnflags->m_Value & 0xFFFFF7FF;
    if ( p_m_spawnflags->m_Value != v2 )
    {
      v3 = p_m_spawnflags - 190;
      if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
      {
        LOBYTE(v3[22].m_Value) |= 1u;
        p_m_spawnflags->m_Value = v2;
      }
      else
      {
        m_Value = (CBaseEdict *)v3[6].m_Value;
        if ( m_Value != nullptr )
          CBaseEdict::StateChanged(this: m_Value, offset: 0x2F8u);
        p_m_spawnflags->m_Value = v2;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6B10
// Name: public: void CBreakableProp::StickAtPosition(class Vector const __near &,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBreakableProp::StickAtPosition(
        CBreakableProp *this@<ecx>,
        int a2@<edi>,
        const Vector *stickPosition,
        const Vector *savePosition,
        const QAngle *saveAngles)
{
  CBaseEntity *EnableMotionFixup; // eax
  CBaseEntity *v7; // edi
  CBaseEntity *v8; // eax
  int v9; // edi
  edict_t *m_pPev; // ecx

  if ( this->m_pPhysicsObject->IsMotionEnabled(this: this->m_pPhysicsObject) )
  {
    CBaseEntity::EmitSound(this, soundname: "Metal.SawbladeStick", soundtime: 0.0, duration: nullptr);
    ((void (__thiscall *)(CBreakableProp *, const Vector *, _DWORD, _DWORD, int, int))this->Teleport)(
      a1: this,
      a2: stickPosition,
      a3: 0,
      a4: 0,
      a5: 1,
      a6: a2);
    EnableMotionFixup = CBreakableProp::FindEnableMotionFixup(this);
    v7 = EnableMotionFixup;
    if ( EnableMotionFixup != nullptr )
    {
      UnlinkFromParent(pRemove: EnableMotionFixup);
      UTIL_Remove(oldObj: v7);
    }
    v8 = CBaseEntity::Create(
           szName: "point_enable_motion_fixup",
           vecOrigin: savePosition,
           vecAngles: saveAngles,
           pOwner: this);
    if ( v8 != nullptr )
      v8->SetParent(this: v8, a2: this, a3: -1);
    this->m_pPhysicsObject->EnableMotion(this: this->m_pPhysicsObject, a2: false);
    v9 = this->m_spawnflags.m_Value | 0x40;
    if ( this->m_spawnflags.m_Value != v9 )
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
      this->m_spawnflags.m_Value = v9;
    }
    CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6C00
// Name: public: void CBreakableProp::BreakablePropTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CBreakableProp::BreakablePropTouch(CBreakableProp *this@<ecx>, int a2@<ebp>, CBaseEntity *pOther)
{
  Vector *v4; // eax
  __m128i v5; // xmm1
  __int128 v6; // xmm0
  float v7; // xmm0_4
  CTakeDamageInfo *v8; // eax
  CTakeDamageInfo v9; // [esp+30h] [ebp-E8h] BYREF
  _BYTE v10[12]; // [esp+8Ch] [ebp-8Ch] BYREF
  __int128 info_84; // [esp+ECh] [ebp-2Ch] OVERLAPPED BYREF
  CBreakableProp_vtbl *v12; // [esp+104h] [ebp-14h]
  float v13; // [esp+108h] [ebp-10h]
  _DWORD v14[2]; // [esp+10Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+118h] [ebp+0h]

  v14[0] = a2;
  v14[1] = retaddr;
  if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
  {
    v4 = pOther->GetSmoothedVelocity(this: pOther, result: (char *)&info_84 + 4);
    v5 = _mm_cvtsi32_si128(this->m_iHealth.m_Value);
    v6 = 0;
    *(float *)&v6 = fsqrt((float)((float)(v4->x * v4->x) + (float)(v4->y * v4->y)) + (float)(v4->z * v4->z));
    info_84 = v6;
    v7 = *(float *)&v6 * 0.01;
    v13 = v7;
    if ( v7 >= _mm_cvtepi32_ps(v5).m128_f32[0] )
    {
      if ( this->m_takedamage.m_Value != 2 )
      {
        this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
        v7 = v13;
        this->m_takedamage.m_Value = 2;
      }
      v12 = this->CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v8 = CTakeDamageInfo::CTakeDamageInfo(
             this: &v9,
             pInflictor: pOther,
             pAttacker: pOther,
             flDamage: v7,
             bitsDamageType: 1,
             iKillType: 0,
             iObjectsPenetrated: 0);
      v12->OnTakeDamage(this, a2: v8);
      CTakeDamageInfo::CTakeDamageInfo(
        this: (CTakeDamageInfo *)v10,
        pInflictor: pOther,
        pAttacker: pOther,
        flDamage: v13 * 0.25,
        bitsDamageType: 4,
        iKillType: 0,
        iObjectsPenetrated: 0);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)v14);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)v14);
      if ( (pOther->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pOther, a2: (int)v14);
      *((float *)&info_84 + 1) = pOther->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
      *((float *)&info_84 + 2) = pOther->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
      *((float *)&info_84 + 3) = pOther->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
      CalculateMeleeDamageForce(
        info: (CTakeDamageInfo *)v10,
        vecMeleeDir: (const Vector *)((char *)&info_84 + 4),
        vecForceOrigin: &this->m_vecAbsOrigin,
        flScale: 1.0);
      CBaseEntity::TakeDamage(this: pOther, a2: (int)this, inputInfo: (const CTakeDamageInfo *)v10);
    }
  }
  if ( (this->m_spawnflags.m_Value & 0x20) != 0 && CBaseEntity::GetGroundEntity(this: pOther) == this )
  {
    if ( pOther != nullptr )
      this->m_hBreaker.m_Index = pOther->GetRefEHandle(this: pOther)->m_Index;
    else
      this->m_hBreaker.m_Index = -1;
    if ( (void (__thiscall *)(CBreakableProp *))this->m_pfnThink != CBreakableProp::BreakThink )
    {
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CBreakableProp::BreakThink,
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: this->m_flPressureDelay + gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6E50
// Name: public: void CBreakableProp::InputAddHealth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::InputAddHealth(CBreakableProp *this, inputdata_t *inputdata)
{
  const char *pszValue; // edx

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  CBreakableProp::UpdateHealth(
    this,
    iNewHealth: (int)&pszValue[this->m_iHealth.m_Value],
    pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x101E6E80
// Name: public: void CBreakableProp::InputRemoveHealth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::InputRemoveHealth(CBreakableProp *this, inputdata_t *inputdata)
{
  const char *pszValue; // edx

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  CBreakableProp::UpdateHealth(
    this,
    iNewHealth: this->m_iHealth.m_Value - (_DWORD)pszValue,
    pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x101E6EB0
// Name: public: void CBreakableProp::InputSetHealth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::InputSetHealth(CBreakableProp *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_INTEGER )
    CBreakableProp::UpdateHealth(this, iNewHealth: inputdata->value.iVal, pActivator: inputdata->pActivator);
  else
    CBreakableProp::UpdateHealth(this, iNewHealth: 0, pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x101E6EE0
// Name: public: virtual bool CBreakableProp::OnAttemptPhysGunPickup(class CBasePlayer __near *,enum PhysGunPickup_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBreakableProp::OnAttemptPhysGunPickup(
        CBreakableProp *this,
        CBasePlayer *pPhysGunUser,
        PhysGunPickup_t reason)
{
  char m_Value_high; // al
  int v6; // eax
  int v7; // ebx
  const char *v8; // eax
  COutputEvent *p_m_pOuter; // ecx
  char v10; // al
  CBaseEntity *v11; // edi
  int v12; // ebx
  const char *v13; // eax
  COutputEvent *p_z; // ecx
  float frametime; // xmm0_4
  float thinkTime; // [esp+4h] [ebp-14h]
  float thinkTimea; // [esp+4h] [ebp-14h]

  m_Value_high = HIBYTE(this->m_nModelIndex.m_Value);
  switch ( m_Value_high )
  {
    case 2:
      return 1;
    case 5:
      return 0;
    case 0:
      v6 = CBaseAnimating::SelectWeightedSequence(
             this: (CBreakableProp *)((char *)this - 1168),
             activity: ACT_PHYSCANNON_DETACH);
      CBaseAnimating::ResetSequence(this: (CBreakableProp *)((char *)this - 1168), nSequence: v6);
      CBaseAnimating::SetPlaybackRate(this: (CBreakableProp *)((char *)this - 1168), rate: 0.0);
      CBaseAnimating::ResetClientsideFrame(this: (CBreakableProp *)((char *)this - 1168));
      HIBYTE(this->m_nModelIndex.m_Value) = 1;
      return 0;
    case 3:
      if ( reason == PUNTED_BY_CANNON )
        return 0;
      v7 = CBaseAnimating::SelectWeightedSequence(
             this: (CBreakableProp *)((char *)this - 1168),
             activity: ACT_PHYSCANNON_ANIMATE_PRE);
      if ( v7 == -1 )
      {
        v7 = CBaseAnimating::SelectWeightedSequence(
               this: (CBreakableProp *)((char *)this - 1168),
               activity: ACT_PHYSCANNON_ANIMATE);
        HIBYTE(this->m_nModelIndex.m_Value) = 4;
        p_m_pOuter = (COutputEvent *)&this->m_Collision.m_pOuter;
      }
      else
      {
        v8 = s_pPropAnimateThink;
        HIBYTE(this->m_nModelIndex.m_Value) = 6;
        thinkTime = gpGlobals->curtime + 0.1;
        CBaseEntity::ThinkSet(
          this: (CBreakableProp *)((char *)this - 1168),
          func: (void (__thiscall *)(CBaseEntity *))CBreakableProp::AnimateThink,
          thinkTime,
          szContext: v8);
        p_m_pOuter = (COutputEvent *)&this->m_pParent;
      }
      COutputEvent::FireOutput(
        this: p_m_pOuter,
        pActivator: nullptr,
        pCaller: (CBreakableProp *)((char *)this - 1168),
        fDelay: 0.0);
      CBaseAnimating::ResetSequence(this: (CBreakableProp *)((char *)this - 1168), nSequence: v7);
      CBaseAnimating::SetPlaybackRate(this: (CBreakableProp *)((char *)this - 1168), rate: 1.0);
      CBaseAnimating::ResetClientsideFrame(this: (CBreakableProp *)((char *)this - 1168));
      break;
    default:
      break;
  }
  v10 = HIBYTE(this->m_nModelIndex.m_Value);
  if ( v10 == 6 || v10 == 7 )
    return 0;
  if ( v10 == 4 )
  {
    if ( reason == PUNTED_BY_CANNON )
      return 0;
    v11 = (CBreakableProp *)((char *)this - 1168);
    CBaseAnimating::StudioFrameAdvanceManual(
      this: (CBreakableProp *)((char *)this - 1168),
      flInterval: gpGlobals->frametime);
    (*(void (__thiscall **)(char *, char *))(*((_DWORD *)this - 292) + 836))(
      a1: (char *)this - 1168,
      a2: (char *)this - 1168);
    if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 292) + 796))(a1: (char *)this - 1168) == 0 )
      return 0;
    v12 = CBaseAnimating::SelectWeightedSequence(
            this: (CBreakableProp *)((char *)this - 1168),
            activity: ACT_PHYSCANNON_ANIMATE_POST);
    if ( v12 == -1 )
    {
      HIBYTE(this->m_nModelIndex.m_Value) = 5;
      p_z = (COutputEvent *)&this->m_Collision.m_vecSpecifiedSurroundingMins.m_Value.z;
    }
    else
    {
      v13 = s_pPropAnimateThink;
      HIBYTE(this->m_nModelIndex.m_Value) = 7;
      thinkTimea = gpGlobals->curtime + 0.1;
      CBaseEntity::ThinkSet(
        this: (CBreakableProp *)((char *)this - 1168),
        func: (void (__thiscall *)(CBaseEntity *))CBreakableProp::AnimateThink,
        thinkTime: thinkTimea,
        szContext: v13);
      CBaseAnimating::ResetSequence(this: (CBreakableProp *)((char *)this - 1168), nSequence: v12);
      CBaseAnimating::SetPlaybackRate(this: (CBreakableProp *)((char *)this - 1168), rate: 1.0);
      CBaseAnimating::ResetClientsideFrame(this: (CBreakableProp *)((char *)this - 1168));
      p_z = (COutputEvent *)&this->m_Collision.m_vecMaxs.m_Value.z;
    }
  }
  else
  {
    if ( reason != PICKED_UP_BY_CANNON )
      frametime = 0.5;
    else
      frametime = gpGlobals->frametime;
    v11 = (CBreakableProp *)((char *)this - 1168);
    CBaseAnimating::StudioFrameAdvanceManual(this: (CBreakableProp *)((char *)this - 1168), flInterval: frametime);
    CBaseAnimating::ResetClientsideFrame(this: (CBreakableProp *)((char *)this - 1168));
    (*(void (__thiscall **)(char *, char *))(*((_DWORD *)this - 292) + 836))(
      a1: (char *)this - 1168,
      a2: (char *)this - 1168);
    if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 292) + 796))(a1: (char *)this - 1168) == 0 )
      return 0;
    CBaseAnimating::SetPlaybackRate(this: (CBreakableProp *)((char *)this - 1168), rate: 1.0);
    HIBYTE(this->m_nModelIndex.m_Value) = 2;
    p_z = (COutputEvent *)&this->m_clrRender;
  }
  COutputEvent::FireOutput(this: p_z, pActivator: nullptr, pCaller: v11, fDelay: 0.0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E7190
// Name: protected: void CDynamicProp::PropSetAnim(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::PropSetAnim(CDynamicProp *this, const char *szAnim)
{
  int m_Value; // edi
  const char *SequenceName; // eax
  const char *DebugName; // eax

  if ( szAnim != nullptr )
  {
    m_Value = this->m_nSequence.m_Value;
    SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: m_Value);
    if ( _V_stricmp(s1: szAnim, s2: SequenceName) != 0 )
      m_Value = CBaseAnimating::LookupSequence(this, label: szAnim);
    if ( m_Value <= -1 )
    {
      DebugName = CBaseEntity::GetDebugName(this);
      _Warning(a1: "Dynamic prop %s: no sequence named:%s\n", DebugName, szAnim);
      CBaseAnimating::SetSequence(this, nSequence: 0);
    }
    else
    {
      CDynamicProp::PropSetSequence(this, nSequence: m_Value);
      COutputEvent::FireOutput(this: &this->m_pOutputAnimBegun, pActivator: nullptr, pCaller: this, fDelay: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7220
// Name: public: void CDynamicProp::InputSetAnimation(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::InputSetAnimation(CDynamicProp *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
      CDynamicProp::PropSetAnim(this, szAnim: locale);
      return;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  CDynamicProp::PropSetAnim(this, szAnim: iVal);
}

//------------------------------------------------------------------------------
// Address: 0x101E7260
// Name: public: void CDynamicProp::InputSetAnimationNoReset(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::InputSetAnimationNoReset(CDynamicProp *this, inputdata_t *inputdata)
{
  int m_Value; // ebx
  const char *pszValue; // eax
  const char *v5; // eax

  m_Value = this->m_nSequence.m_Value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
  }
  else
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
  }
  if ( m_Value != CBaseAnimating::LookupSequence(this, label: pszValue) )
  {
    if ( inputdata->value.fieldType == FIELD_STRING )
    {
      v5 = inputdata->value.iszVal.pszValue;
      if ( v5 == nullptr )
      {
        CDynamicProp::PropSetAnim(this, szAnim: locale);
        return;
      }
    }
    else
    {
      v5 = variant_t::ToString(this: &inputdata->value);
    }
    CDynamicProp::PropSetAnim(this, szAnim: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7340
// Name: public: void COrnamentProp::AttachTo(char const __near *,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COrnamentProp::AttachTo(
        COrnamentProp *this,
        const char *pAttachName,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  int m_Value; // eax
  unsigned int v6; // esi
  edict_t *m_pPev; // ecx
  CBaseEntity *pAttach; // [esp+14h] [ebp+10h]

  pAttach = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: nullptr,
              szName: pAttachName,
              pSearchingEntity: nullptr,
              pActivator,
              pCaller,
              pFilter: nullptr);
  if ( pAttach != nullptr )
  {
    m_Value = this->m_fEffects.m_Value;
    v6 = m_Value & 0xFFFFFFDF;
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
      this->m_fEffects.m_Value = v6;
    }
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
    CBaseEntity::FollowEntity(this, pBaseEntity: pAttach, bBoneMerge: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E73D0
// Name: public: void CPhysicsProp::EnableMotion(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::EnableMotion(CPhysicsProp *this)
{
  IPhysicsObject *m_pPhysicsObject; // edi
  CBaseEntity *EnableMotionFixup; // eax
  CBaseEntity *v4; // ebx
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // edi
  unsigned int v6; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v7; // eax
  CBaseEdict *m_Value; // ecx
  Vector pos; // [esp+20h] [ebp-18h] BYREF
  QAngle angles; // [esp+2Ch] [ebp-Ch] BYREF

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    if ( CBreakableProp::GetEnableMotionPosition(this, pPosition: &pos, pAngles: &angles) != 0 )
    {
      EnableMotionFixup = CBreakableProp::FindEnableMotionFixup(this);
      v4 = EnableMotionFixup;
      if ( EnableMotionFixup != nullptr )
      {
        UnlinkFromParent(pRemove: EnableMotionFixup);
        UTIL_Remove(oldObj: v4);
      }
      this->Teleport(this, a2: &pos, a3: &angles, a4: nullptr, a5: true);
    }
    m_pPhysicsObject->EnableMotion(this: m_pPhysicsObject, a2: true);
    m_pPhysicsObject->Wake(this: m_pPhysicsObject);
    COutputEvent::FireOutput(this: &this->m_MotionEnabled, pActivator: this, pCaller: this, fDelay: 0.0);
  }
  p_m_spawnflags = &this->m_spawnflags;
  if ( (this->m_spawnflags.m_Value & 0x800) != 0 )
  {
    DetachAttachedRagdollsForEntity(pRagdollParent: this);
    v6 = p_m_spawnflags->m_Value & 0xFFFFF7FF;
    if ( p_m_spawnflags->m_Value != v6 )
    {
      v7 = p_m_spawnflags - 190;
      if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
      {
        LOBYTE(v7[22].m_Value) |= 1u;
        p_m_spawnflags->m_Value = v6;
      }
      else
      {
        m_Value = (CBaseEdict *)v7[6].m_Value;
        if ( m_Value != nullptr )
          CBaseEdict::StateChanged(this: m_Value, offset: 0x2F8u);
        p_m_spawnflags->m_Value = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E74C0
// Name: public: virtual void CPhysicsProp::OnPhysGunPickup(class CBasePlayer __near *,enum PhysGunPickup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::OnPhysGunPickup(CPhysicsProp *this, CBasePlayer *pPhysGunUser, PhysGunPickup_t reason)
{
  int v4; // ecx
  COutputEvent *p_m_iHammerID; // ecx

  CBreakableProp::OnPhysGunPickup(this, pPhysGunUser, reason);
  v4 = *((_DWORD *)this - 210);
  if ( v4 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 40))(a1: v4) == 0 )
  {
    if ( (*((_DWORD *)this - 102) & 0x40) == 0 )
      return;
    CPhysicsProp::EnableMotion(this: (CPhysicsProp *)((char *)this - 1168));
    if ( (*(unsigned __int8 (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 1) + 96))(a1: (char *)this - 4, a2: 0) != 0 )
      CBaseEntity::SetCollisionGroup(this: (CPhysicsProp *)((char *)this - 1168), collisionGroup: 3);
  }
  COutputEvent::FireOutput(
    this: (COutputEvent *)&this->m_rgflCoordinateFrame.m_flMatVal[0][2],
    pActivator: pPhysGunUser,
    pCaller: (CPhysicsProp *)((char *)this - 1168),
    fDelay: 0.0);
  switch ( reason )
  {
    case PICKED_UP_BY_CANNON:
      COutputEvent::FireOutput(
        this: (COutputEvent *)&this->m_flLocalTime,
        pActivator: pPhysGunUser,
        pCaller: (CPhysicsProp *)((char *)this - 1168),
        fDelay: 0.0);
      goto LABEL_11;
    case PUNTED_BY_CANNON:
      p_m_iHammerID = (COutputEvent *)this->m_rgflCoordinateFrame.m_flMatVal[2];
LABEL_12:
      COutputEvent::FireOutput(
        this: p_m_iHammerID,
        pActivator: pPhysGunUser,
        pCaller: (CPhysicsProp *)((char *)this - 1168),
        fDelay: 0.0);
      break;
    case PICKED_UP_BY_PLAYER:
LABEL_11:
      p_m_iHammerID = (COutputEvent *)&this->m_iHammerID;
      goto LABEL_12;
    default:
      break;
  }
  CBreakableProp::CheckRemoveRagdolls(this: (CPhysicsProp *)((char *)this - 1168));
}

//------------------------------------------------------------------------------
// Address: 0x101E75A0
// Name: public: virtual void CPhysicsProp::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::VPhysicsUpdate(CPhysicsProp *this, IPhysicsObject *pPhysics)
{
  bool v3; // bl
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  unsigned int v6; // edi
  edict_t *v7; // ecx
  int v8; // edi
  int savedregs; // [esp+10h] [ebp+0h] BYREF
  IPhysicsObject *pPhysicsObject; // [esp+18h] [ebp+8h]

  CBaseEntity::VPhysicsUpdate(this, pPhysics);
  v3 = !pPhysics->IsAsleep(this: pPhysics);
  if ( this->m_bAwake.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x6ECu);
    }
    this->m_bAwake.m_Value = v3;
  }
  pPhysicsObject = this->m_pPhysicsObject;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v5 = this->m_Network.m_pPev;
    if ( v5 != nullptr )
    {
      v5->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v5->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  if ( (this->m_spawnflags.m_Value & 1) != 0 && this->m_bAwake.m_Value )
  {
    COutputEvent::FireOutput(this: &this->m_OnAwakened, pActivator: this, pCaller: this, fDelay: 0.0);
    v6 = this->m_spawnflags.m_Value & 0xFFFFFFFE;
    if ( this->m_spawnflags.m_Value != v6 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v6;
    }
    v8 = (int)pPhysicsObject;
    if ( pPhysicsObject != nullptr && pPhysicsObject->IsMoveable(this: pPhysicsObject) )
      this->m_bHasBeenAwakened = true;
  }
  else
  {
    v8 = (int)pPhysicsObject;
  }
  if ( this->m_bThrownByPlayer && !this->m_bAwake.m_Value )
    this->m_bThrownByPlayer = false;
  if ( !CBaseEntity::IsInWorld(this, a2: (int)&savedregs) )
    COutputEvent::FireOutput(this: &this->m_OnOutOfWorld, pActivator: this, pCaller: this, fDelay: 0.0);
  if ( (!this->m_bAwake.m_Value || v8 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 40))(a1: v8) == 0)
    && this->m_bHasBeenAwakened
    && (this->m_spawnflags.m_Value & 0x10000) != 0
    && CPhysicsProp::ShouldDisableMotionOnFreeze(this, a2: v8) != 0 )
  {
    DevMsg(a1: "Disabling motion on phys prop");
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 60))(a1: v8, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7730
// Name: public: virtual int CPhysicsProp::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CPhysicsProp::OnTakeDamage@<eax>(CPhysicsProp *this@<ecx>, float a2@<ebp>, const CTakeDamageInfo *info)
{
  const CTakeDamageInfo *v3; // edi
  float y; // edx
  unsigned int v6; // eax
  int m_bitsDamageType; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  int v9; // edi
  const Vector *v10; // eax
  CPhysicsProp_vtbl *v11; // edx
  float v12; // xmm0_4
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  const Vector *v14; // eax
  float m_flForceToEnableMotion; // xmm1_4
  float z; // eax
  __int128 v17; // xmm0
  int m_damageToEnableMotion; // eax
  bool v19; // zf
  int v21; // [esp+20h] [ebp-94h] BYREF
  _BYTE tr[92]; // [esp+2Ch] [ebp-88h] OVERLAPPED BYREF
  __int64 v23; // [esp+94h] [ebp-20h] BYREF
  float v24; // [esp+9Ch] [ebp-18h]
  Vector vel; // [esp+A0h] [ebp-14h] BYREF
  void *v26; // [esp+ACh] [ebp-8h]
  void *retaddr; // [esp+B4h] [ebp+0h]

  vel.z = a2;
  v26 = retaddr;
  v3 = info;
  y = COERCE_FLOAT(CBreakableProp::OnTakeDamage(this, a2: (int)&vel.z, a3: (int)info, a4: (int)this, inputInfo: info));
  v6 = (unsigned int)this->m_fFlags.m_Value >> 28;
  vel.y = y;
  if ( (v6 & 1) != 0 )
  {
    m_bitsDamageType = info->m_bitsDamageType;
    if ( (m_bitsDamageType & 8) != 0 && (m_bitsDamageType & 0x10000000) != 0 )
    {
      m_pPhysicsObject = this->m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr )
      {
        m_pPhysicsObject->GetVelocity(this: m_pPhysicsObject, a2: (Vector *)&v23, a3: nullptr);
        v9 = 256;
        if ( hl2_episodic.m_pParent != nullptr
          && hl2_episodic.m_pParent->m_Value.m_nValue != 0
          && this->m_iHealth.m_Value < 1 )
        {
          v9 = 120;
        }
        v10 = this->WorldSpaceCenter(this);
        v11 = this->CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        *(float *)&tr[80] = *(float *)&v23 + v10->x;
        *(float *)&tr[84] = v10->y + *((float *)&v23 + 1);
        v12 = v10->z + v24;
        WorldSpaceCenter = v11->WorldSpaceCenter;
        *(float *)&tr[88] = v12;
        v14 = WorldSpaceCenter(this);
        UTIL_TraceLine(
          a1: (const IHandleEntity *)&vel.z,
          a2: (int)this,
          vecAbsStart: v14,
          vecAbsEnd: (const Vector *)&tr[80],
          mask: 0x46004003u,
          ignore: this,
          collisionGroup: 0,
          ptr: (CGameTrace *)&v21);
        CSoundEnt::InsertSound(
          iType: 8,
          vecOrigin: (const Vector *)tr,
          iVolume: v9,
          flDuration: 1.0,
          pOwner: this,
          soundChannelIndex: 2,
          pSoundTarget: nullptr);
        v3 = info;
        y = vel.y;
      }
    }
  }
  m_flForceToEnableMotion = this->m_flForceToEnableMotion;
  if ( m_flForceToEnableMotion != 0.0 )
  {
    z = v3->m_vecDamageForce.z;
    v23 = *(_QWORD *)&v3->m_vecDamageForce.x;
    vel.x = *((float *)&v23 + 1) * *((float *)&v23 + 1);
    v24 = z;
    v17 = 0;
    *(float *)&v17 = fsqrt(
                       (float)((float)(*((float *)&v23 + 1) * *((float *)&v23 + 1)) + (float)(v24 * v24))
                     + (float)(*(float *)&v23 * *(float *)&v23));
    *(_OWORD *)&tr[76] = v17;
    if ( *(float *)&v17 >= m_flForceToEnableMotion )
    {
      CPhysicsProp::EnableMotion(this);
      y = vel.y;
      this->m_flForceToEnableMotion = 0.0;
    }
  }
  m_damageToEnableMotion = this->m_damageToEnableMotion;
  if ( m_damageToEnableMotion <= 0 )
    return LODWORD(y);
  if ( this->m_iHealth.m_Value >= m_damageToEnableMotion )
    return LODWORD(y);
  v19 = this->m_pPhysicsObject == nullptr;
  this->m_damageToEnableMotion = 0;
  if ( v19 )
    return LODWORD(y);
  CPhysicsProp::EnableMotion(this);
  this->VPhysicsTakeDamage(this, a2: v3);
  return LODWORD(vel.y);
}

//------------------------------------------------------------------------------
// Address: 0x101E7920
// Name: BreakModelCreate_Prop
// Source: json
//------------------------------------------------------------------------------
CBreakableProp *__usercall BreakModelCreate_Prop@<eax>(
        const Vector *position@<ecx>,
        const QAngle *angles@<eax>,
        int a3@<edi>,
        CBaseEntity *pOwner,
        breakmodel_t *pModel,
        const breakablepropparams_t *params)
{
  CBaseEntity *v6; // ebx
  CBreakableProp *result; // eax
  CBreakableProp *v8; // esi
  int m_Value; // eax
  int v10; // ebx
  CBaseEdict *v11; // ecx
  unsigned int v12; // ebx
  CBaseEdict *v13; // ecx
  CBreakableProp *v14; // eax
  IBreakableWithPropData *v15; // edi
  float (__thiscall *GetDmgModBullet)(IBreakableWithPropData *); // eax
  float (__thiscall *GetDmgModClub)(IBreakableWithPropData *); // eax
  float (__thiscall *GetDmgModExplosive)(IBreakableWithPropData *); // eax
  const char *v19; // eax
  float minFadeDist; // xmm0_4
  int v21; // ebx
  CBaseEdict *v22; // ecx
  CBaseEntity *v23; // eax
  CBaseEntity *EffectEntity; // eax
  CEntityFlame *v25; // eax
  CBreakableProp_vtbl *v26; // edi
  float RemainingLife; // [esp+1Ch] [ebp-24h]
  float maxFadeDist; // [esp+28h] [ebp-18h]
  float maxFadeDista; // [esp+28h] [ebp-18h]
  float maxFadeDistb; // [esp+28h] [ebp-18h]
  float maxFadeDistc; // [esp+28h] [ebp-18h]
  int v32; // [esp+2Ch] [ebp-14h]
  CBreakableProp *pBreakableOwner; // [esp+38h] [ebp-8h] BYREF
  IBreakableWithPropData_vtbl *v34; // [esp+3Ch] [ebp-4h]

  v6 = pOwner;
  result = (CBreakableProp *)CBaseEntity::CreateNoSpawn(
                               szName: "prop_physics",
                               vecOrigin: position,
                               vecAngles: angles,
                               pOwner);
  v8 = result;
  if ( result != nullptr )
  {
    v32 = a3;
    if ( pOwner != nullptr )
    {
      m_Value = result->m_spawnflags.m_Value;
      v10 = m_Value | pOwner->m_spawnflags.m_Value;
      if ( m_Value != v10 )
      {
        if ( v8->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v8->m_Network + 76) |= 1u;
        }
        else
        {
          v11 = &v8->m_Network.m_pPev->CBaseEdict;
          if ( v11 != nullptr )
            CBaseEdict::StateChanged(this: v11, offset: 0x2F8u);
        }
        v8->m_spawnflags.m_Value = v10;
      }
      v12 = v8->m_spawnflags.m_Value & 0xFFFFFFF7;
      if ( v8->m_spawnflags.m_Value != v12 )
      {
        if ( v8->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v8->m_Network + 76) |= 1u;
        }
        else
        {
          v13 = &v8->m_Network.m_pPev->CBaseEdict;
          if ( v13 != nullptr )
            CBaseEdict::StateChanged(this: v13, offset: 0x2F8u);
        }
        v8->m_spawnflags.m_Value = v12;
      }
      v6 = pOwner;
    }
    v8->m_impactEnergyScale = params->impactEnergyScale;
    v14 = (CBreakableProp *)__RTDynamicCast(
                              inptr: v6,
                              VfDelta: 0,
                              SrcType: &CBaseEntity `RTTI Type Descriptor',
                              TargetType: &CBreakableProp `RTTI Type Descriptor',
                              isReference: 0);
    pBreakableOwner = v14;
    if ( v14 != nullptr )
    {
      v15 = &v14->IBreakableWithPropData;
      GetDmgModBullet = v14->GetDmgModBullet;
      v34 = v8->IBreakableWithPropData::__vftable;
      maxFadeDist = ((double (__thiscall *)(IBreakableWithPropData *, int))GetDmgModBullet)(a1: v15, a2: v32);
      ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v34->SetDmgModBullet)(
        a1: &v8->IBreakableWithPropData,
        a2: LODWORD(maxFadeDist));
      GetDmgModClub = v15->GetDmgModClub;
      v34 = v8->IBreakableWithPropData::__vftable;
      maxFadeDista = GetDmgModClub(this: v15);
      ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v34->SetDmgModClub)(
        a1: &v8->IBreakableWithPropData,
        a2: LODWORD(maxFadeDista));
      GetDmgModExplosive = v15->GetDmgModExplosive;
      v34 = v8->IBreakableWithPropData::__vftable;
      maxFadeDistb = GetDmgModExplosive(this: v15);
      ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v34->SetDmgModExplosive)(
        a1: &v8->IBreakableWithPropData,
        a2: LODWORD(maxFadeDistb));
      v8->m_flDmgModFire = v15->GetDmgModFire(this: v15);
      CBreakableProp::CopyFadeFrom(this: v8, pSource: pBreakableOwner);
      v6 = pOwner;
    }
    v8->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&pBreakableOwner).pszValue;
    CBaseEntity::DispatchUpdateTransmitState(this: v8);
    v19 = *(const char **)((int (__thiscall *)(CBreakableProp *, CBreakableProp **, int))v8->GetModelName)(
                            a1: v8,
                            a2: &pBreakableOwner,
                            a3: v32);
    if ( v19 == nullptr )
      v19 = locale;
    v8->SetModel(this: v8, a2: v19);
    CBaseEntity::SetCollisionGroup(this: v8, collisionGroup: pModel->collisionGroup);
    minFadeDist = pModel->fadeMinDist;
    if ( minFadeDist > 0.0 && pModel->fadeMaxDist >= minFadeDist )
      CBaseAnimating::SetFadeDistance(this: v8, minFadeDist, maxFadeDist: pModel->fadeMaxDist);
    if ( pModel->fadeTime != 0.0 )
    {
      v21 = v8->m_spawnflags.m_Value | 0x400000;
      if ( v8->m_spawnflags.m_Value != v21 )
      {
        if ( v8->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v8->m_Network + 76) |= 1u;
        }
        else
        {
          v22 = &v8->m_Network.m_pPev->CBaseEdict;
          if ( v22 != nullptr )
            CBaseEdict::StateChanged(this: v22, offset: 0x2F8u);
        }
        v8->m_spawnflags.m_Value = v21;
      }
      v6 = pOwner;
    }
    v8->Spawn(this: v8);
    if ( prop_break_disable_float.m_pParent != nullptr && prop_break_disable_float.m_pParent->m_Value.m_nValue != 0 )
      PhysEnableFloating(pObject: v8->m_pPhysicsObject, bEnable: false);
    if ( v6 != nullptr )
    {
      v23 = v6->GetBaseAnimating(this: v6);
      if ( v23 != nullptr && (v23->m_fFlags.m_Value & 0x10000000) != 0 )
      {
        EffectEntity = CBaseEntity::GetEffectEntity(this: v23);
        v25 = (CEntityFlame *)__RTDynamicCast(
                                inptr: EffectEntity,
                                VfDelta: 0,
                                SrcType: &CBaseEntity `RTTI Type Descriptor',
                                TargetType: &CEntityFlame `RTTI Type Descriptor',
                                isReference: 0);
        v26 = v8->CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        if ( v25 != nullptr )
        {
          RemainingLife = CEntityFlame::GetRemainingLife(this: v25);
          ((void (__thiscall *)(CBreakableProp *, _DWORD, _DWORD, _DWORD, _DWORD))v26->Ignite)(
            a1: v8,
            a2: LODWORD(RemainingLife),
            a3: 0,
            a4: 0,
            a5: 0);
          return v8;
        }
        maxFadeDistc = ((double (__thiscall *)(IUniformRandomStream *, int, int, _DWORD, _DWORD, _DWORD))random->RandomFloat)(
                         a1: random,
                         a2: 1084227584,
                         a3: 1092616192,
                         a4: 0,
                         a5: 0,
                         a6: 0);
        ((void (__thiscall *)(CBreakableProp *, _DWORD))v26->Ignite)(a1: v8, a2: LODWORD(maxFadeDistc));
      }
    }
    return v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E7C40
// Name: class CBaseEntity __near * BreakModelCreateSingle(class CBaseEntity __near *,struct breakmodel_t __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,int,struct breakablepropparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CBreakableProp *__cdecl BreakModelCreateSingle(
        CBaseEntity *pOwner,
        breakmodel_t *pModel,
        const Vector *position,
        const QAngle *angles,
        const Vector *velocity,
        const Vector *angVelocity,
        int nSkin,
        const breakablepropparams_t *params)
{
  int m_nValue; // eax
  CBreakableProp *Prop; // ebx
  CBaseAnimating *v11; // eax
  CBaseEdict *v12; // ecx
  int health; // edi
  int v14; // eax
  float fadeTime; // xmm0_4
  float delay; // xmm0_4
  _BYTE *v17; // eax
  _BYTE *v18; // esi
  int v19; // eax
  int v20; // edi
  int v21; // esi
  int collisionGroup; // [esp+Ch] [ebp-1010h]
  _DWORD v23[1024]; // [esp+18h] [ebp-1004h] BYREF
  CBaseAnimating *ServerRagdollSubmodel; // [esp+1018h] [ebp-4h]

  if ( prop_active_gib_limit.m_pParent != nullptr )
    m_nValue = prop_active_gib_limit.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_ActiveGibCount >= m_nValue )
    return nullptr;
  if ( pModel->isRagdoll )
  {
    collisionGroup = pModel->collisionGroup;
    v11 = (CBaseAnimating *)__RTDynamicCast(
                              inptr: pOwner,
                              VfDelta: 0,
                              SrcType: &CBaseEntity `RTTI Type Descriptor',
                              TargetType: &CBaseAnimating `RTTI Type Descriptor',
                              isReference: 0);
    ServerRagdollSubmodel = CreateServerRagdollSubmodel(
                              pOwner: v11,
                              pModelName: pModel->modelName,
                              position,
                              angles,
                              collisionGroup);
    Prop = (CBreakableProp *)ServerRagdollSubmodel;
  }
  else
  {
    Prop = BreakModelCreate_Prop(position, angles, a3: (int)pModel, pOwner, pModel, params);
    ServerRagdollSubmodel = Prop;
  }
  if ( Prop == nullptr )
    return Prop;
  if ( Prop->m_nSkin.m_Value != nSkin )
  {
    if ( Prop->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&Prop->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = &Prop->m_Network.m_pPev->CBaseEdict;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: v12, offset: 0x36Cu);
    }
    Prop->m_nSkin.m_Value = nSkin;
  }
  health = (int)pModel->health;
  if ( Prop->m_iHealth.m_Value != health )
  {
    Prop->NetworkStateChanged_m_iHealth(this: Prop, a2: &Prop->m_iHealth);
    Prop->m_iHealth.m_Value = health;
  }
  if ( prop_active_gib_max_fade_time.m_pParent != nullptr )
    v14 = prop_active_gib_max_fade_time.m_pParent->m_Value.m_nValue;
  else
    v14 = 0;
  if ( g_ActiveGibCount >= v14 )
  {
    fadeTime = pModel->fadeTime;
    if ( fadeTime > 3.0 )
      fadeTime = 3.0;
    pModel->fadeTime = fadeTime;
  }
  delay = pModel->fadeTime;
  if ( delay != 0.0 )
  {
    CBaseEntity::SUB_StartFadeOut(this: Prop, delay, notSolid: false);
    v17 = __RTDynamicCast(
            inptr: Prop,
            VfDelta: 0,
            SrcType: &CBaseAnimating `RTTI Type Descriptor',
            TargetType: &CBreakableProp `RTTI Type Descriptor',
            isReference: 0);
    if ( v17 != nullptr && *((_DWORD *)v17 + 334) == 0 )
    {
      v18 = v17 + 554;
      if ( v17[554] == 2 && *v18 != 1 )
      {
        (*(void (__thiscall **)(_BYTE *, _BYTE *))(*(_DWORD *)v17 + 756))(a1: v17, a2: v17 + 554);
        *v18 = 1;
      }
    }
  }
  v19 = Prop->VPhysicsGetObjectList(this: Prop, a2: (IPhysicsObject **)v23, a3: 1024);
  v20 = v19;
  if ( v19 != 0 )
  {
    v21 = 0;
    if ( v19 > 0 )
    {
      do
      {
        (*(void (__thiscall **)(_DWORD, const Vector *, const Vector *))(*(_DWORD *)v23[v21] + 200))(
          a1: v23[v21],
          a2: velocity,
          a3: angVelocity);
        ++v21;
      }
      while ( v21 < v20 );
      return (CBreakableProp *)ServerRagdollSubmodel;
    }
    return Prop;
  }
  UTIL_Remove(oldObj: Prop);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E7E60
// Name: public: virtual void CBreakModelsPrecached::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakModelsPrecached::LevelShutdownPostEntity(CBreakModelsPrecached *this)
{
  CUtlRBTree<CBreakModelsPrecached::breakable_precache_t,unsigned short,bool (__cdecl *)(CBreakModelsPrecached::breakable_precache_t const &,CBreakModelsPrecached::breakable_precache_t const &),CUtlMemory<UtlRBTreeNode_t<CBreakModelsPrecached::breakable_precache_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_modelList);
}

//------------------------------------------------------------------------------
// Address: 0x101E7F20
// Name: public: virtual void CBasePropDoor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePropDoor::Activate(CBasePropDoor *this@<ecx>, CBasePropDoor *a2@<ebx>)
{
  CBasePropDoor *v2; // esi
  const char *v3; // eax
  const char *pszValue; // ecx
  const char *v5; // edi
  const char *v6; // eax
  const char *v7; // eax
  CBaseEntity *EntityByName; // eax
  int *v9; // eax
  int *v10; // ebx
  unsigned int v11; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<CBasePropDoor> *m_pMemory; // ecx
  int v15; // eax
  CHandle<CBasePropDoor> *v16; // edi
  unsigned int v18; // [esp+4h] [ebp-10h] BYREF
  CBasePropDoor *v19; // [esp+8h] [ebp-Ch]
  string_t iszSearchName; // [esp+Ch] [ebp-8h]
  CBaseEntity *pTarget; // [esp+10h] [ebp-4h]

  v2 = this;
  v19 = this;
  CBaseAnimating::Activate(this);
  if ( v2->m_takedamage.m_Value == 0 && v2->m_iHealth.m_Value != 0 )
  {
    v3 = *(const char **)((int (__thiscall *)(CBasePropDoor *, unsigned int *))v2->GetModelName)(a1: v2, a2: &v18);
    if ( v3 == nullptr )
      v3 = locale;
    pszValue = v2->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "%s has a health specified in model '%s'. Use prop_physics or prop_dynamic instead.\n", pszValue, v3);
  }
  CBasePropDoor::UpdateAreaPortals(this: v2, isOpen: v2->m_eDoorState != DOOR_STATE_CLOSED);
  if ( v2->m_iName.m_Value.pszValue != nullptr )
  {
    v5 = v2->m_iName.m_Value.pszValue;
    v6 = v2->m_SlaveName.pszValue;
    pTarget = nullptr;
    iszSearchName.pszValue = v5;
    if ( v6 != nullptr && *v6 != 0 )
    {
      iszSearchName.pszValue = v6;
      v5 = v6;
    }
    while ( 1 )
    {
      v7 = v5;
      if ( v5 == nullptr )
        v7 = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: pTarget,
                       szName: v7,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      pTarget = EntityByName;
      if ( EntityByName == nullptr )
        break;
      if ( EntityByName != v2 )
      {
        v9 = (int *)__RTDynamicCast(
                      inptr: EntityByName,
                      VfDelta: 0,
                      SrcType: &CBaseEntity `RTTI Type Descriptor',
                      TargetType: &CBasePropDoor `RTTI Type Descriptor',
                      isReference: 0);
        v10 = v9;
        if ( v9 != nullptr && v9[410] <= 0 )
        {
          v11 = *(_DWORD *)(*(int (__thiscall **)(int *, CBasePropDoor *))(*v9 + 8))(a1: v9, a2);
          m_Size = v2->m_hDoorList.m_Size;
          m_nAllocationCount = v2->m_hDoorList.m_Memory.m_nAllocationCount;
          v18 = v11;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_hDoorList,
              num: m_Size - m_nAllocationCount + 1);
          ++v2->m_hDoorList.m_Size;
          m_pMemory = v2->m_hDoorList.m_Memory.m_pMemory;
          v15 = v2->m_hDoorList.m_Size - m_Size - 1;
          v2->m_hDoorList.m_pElements = m_pMemory;
          if ( v15 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
          v16 = &v2->m_hDoorList.m_Memory.m_pMemory[m_Size];
          if ( v16 != nullptr )
            v16->m_Index = v18;
          v2 = v19;
          v10[433] = v19->GetRefEHandle(this: v19)->m_Index;
          a2 = v2;
          (*(void (__thiscall **)(int *))(*v10 + 72))(a1: v10);
          v5 = iszSearchName.pszValue;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E80C0
// Name: private: void CBasePropDoor::InputClose(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::InputClose(CBasePropDoor *this, inputdata_t *inputdata)
{
  if ( this->m_eDoorState != DOOR_STATE_CLOSED )
  {
    COutputEvent::FireOutput(this: &this->m_OnClose, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
    CBasePropDoor::DoorClose(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E8100
// Name: private: void CBasePropDoor::DoorAutoCloseThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::DoorAutoCloseThink(CBasePropDoor *this)
{
  float m_flAutoReturnDelay; // xmm0_4

  if ( this->DoorCanClose(this, a2: true) )
  {
    CBasePropDoor::DoorClose(this);
  }
  else
  {
    m_flAutoReturnDelay = this->m_flAutoReturnDelay;
    if ( m_flAutoReturnDelay == -1.0 )
    {
      CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    }
    else
    {
      CBaseEntity::SetMoveDoneTime(this, flDelay: m_flAutoReturnDelay + 0.1);
      this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CBasePropDoor::DoorAutoCloseThink;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E8170
// Name: public: CTraceFilterDoor::CTraceFilterDoor(class IHandleEntity const __near *,class IHandleEntity const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CTraceFilterDoor *__thiscall CTraceFilterDoor::CTraceFilterDoor(
        CTraceFilterDoor *this,
        const IHandleEntity *pDoor,
        const IHandleEntity *passentity,
        int collisionGroup)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  const IHandleEntity **m_pMemory; // ecx
  int v8; // eax
  const IHandleEntity **v9; // edi
  CTraceFilterDoor *result; // eax

  this->__vftable = (CTraceFilterDoor_vtbl *)&CTraceFilterDoor::`vftable';
  this->m_pPassEnts.m_Memory.m_pMemory = nullptr;
  this->m_pPassEnts.m_Memory.m_nAllocationCount = 0;
  this->m_pPassEnts.m_Memory.m_nGrowSize = 0;
  this->m_pPassEnts.m_Size = 0;
  this->m_pPassEnts.m_pElements = nullptr;
  this->m_pDoor = pDoor;
  this->m_collisionGroup = collisionGroup;
  if ( passentity == nullptr )
    return this;
  m_nAllocationCount = this->m_pPassEnts.m_Memory.m_nAllocationCount;
  m_Size = this->m_pPassEnts.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pPassEnts,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pPassEnts.m_Size;
  m_pMemory = this->m_pPassEnts.m_Memory.m_pMemory;
  v8 = this->m_pPassEnts.m_Size - m_Size - 1;
  this->m_pPassEnts.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_pPassEnts.m_Memory.m_pMemory[m_Size];
  result = this;
  if ( v9 != nullptr )
    *v9 = passentity;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E8210
// Name: public: virtual bool CTraceFilterDoor::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterDoor::ShouldHitEntity(
        CTraceFilterDoor *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  int v5; // edi
  const CBaseHandle *v6; // edi
  unsigned int m_Index; // edi

  if ( !StandardFilterRules(pHandleEntity, fContentsMask: contentsMask)
    || !PassServerEntityFilter(pTouch: pHandleEntity, pPass: this->m_pDoor) )
  {
    return 0;
  }
  v5 = 0;
  if ( this->m_pPassEnts.m_Size > 0 )
  {
    while ( PassServerEntityFilter(pTouch: pHandleEntity, pPass: this->m_pPassEnts.m_Memory.m_pMemory[v5]) )
    {
      if ( ++v5 >= this->m_pPassEnts.m_Size )
        goto LABEL_7;
    }
    return 0;
  }
LABEL_7:
  if ( !staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity) )
  {
    v6 = pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity);
    if ( v6 != nullptr )
    {
      if ( (*(unsigned __int8 (__thiscall **)(const CBaseHandle *, int, int))(v6->m_Index + 68))(
             a1: v6,
             a2: this->m_collisionGroup,
             a3: contentsMask) == 0 )
        return 0;
      if ( !g_pGameRules->ShouldCollide(this: g_pGameRules, a2: this->m_collisionGroup, a3: v6[81].m_Index) )
        return 0;
      if ( BYTE2(v6[53].m_Index) == 6 )
      {
        m_Index = v6[82].m_Index;
        if ( (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)m_Index + 40))(a1: m_Index) != 0
          && ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)m_Index + 116))(a1: m_Index) < 32.0 )
        {
          return 0;
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E83E0
// Name: private: bool CPropDoorRotating::CheckDoorClear(enum doorCheck_e)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CPropDoorRotating::CheckDoorClear@<al>(
        CPropDoorRotating *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        doorCheck_e state)
{
  float z; // xmm0_4
  unsigned int m_Index; // ecx
  int v9; // esi
  int v10; // edi
  int (__thiscall *v11)(int); // eax
  const Vector *v12; // eax
  int v13; // edx
  const Vector *v14; // eax
  Ray_t v16; // [esp+24h] [ebp-FCh] BYREF
  int v17; // [esp+7Ch] [ebp-A4h] BYREF
  CGameTrace tr; // [esp+88h] [ebp-98h] BYREF
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > v19; // [esp+DCh] [ebp-44h] BYREF
  IHandleEntity *m_pEntity; // [esp+F8h] [ebp-28h]
  Vector v21; // [esp+FCh] [ebp-24h] BYREF
  Vector moveMaxs; // [esp+108h] [ebp-18h] BYREF
  Vector moveMins; // [esp+114h] [ebp-Ch] BYREF
  float retaddr; // [esp+120h] [ebp+0h]

  moveMins.x = a2;
  moveMins.y = retaddr;
  if ( state == DOOR_CHECK_FORWARD )
  {
    moveMaxs = this->m_vecForwardBoundsMin;
    v21.x = this->m_vecForwardBoundsMax.x;
    v21.y = this->m_vecForwardBoundsMax.y;
    z = this->m_vecForwardBoundsMax.z;
    goto LABEL_22;
  }
  if ( state == DOOR_CHECK_BACKWARD )
  {
    moveMaxs = this->m_vecBackBoundsMin;
    v21.x = this->m_vecBackBoundsMax.x;
    v21.y = this->m_vecBackBoundsMax.y;
    z = this->m_vecBackBoundsMax.z;
LABEL_22:
    v21.z = z;
    goto LABEL_23;
  }
  if ( this->m_vecBackBoundsMin.x <= this->m_vecForwardBoundsMin.x )
    moveMaxs.x = this->m_vecBackBoundsMin.x;
  else
    moveMaxs.x = this->m_vecForwardBoundsMin.x;
  if ( this->m_vecBackBoundsMin.y <= this->m_vecForwardBoundsMin.y )
    moveMaxs.y = this->m_vecBackBoundsMin.y;
  else
    moveMaxs.y = this->m_vecForwardBoundsMin.y;
  if ( this->m_vecBackBoundsMin.z <= this->m_vecForwardBoundsMin.z )
    moveMaxs.z = this->m_vecBackBoundsMin.z;
  else
    moveMaxs.z = this->m_vecForwardBoundsMin.z;
  if ( this->m_vecForwardBoundsMax.x <= this->m_vecBackBoundsMax.x )
    v21.x = this->m_vecBackBoundsMax.x;
  else
    v21.x = this->m_vecForwardBoundsMax.x;
  if ( this->m_vecForwardBoundsMax.y <= this->m_vecBackBoundsMax.y )
    v21.y = this->m_vecBackBoundsMax.y;
  else
    v21.y = this->m_vecForwardBoundsMax.y;
  z = this->m_vecForwardBoundsMax.z;
  if ( z > this->m_vecBackBoundsMax.z )
    goto LABEL_22;
  v21.z = this->m_vecBackBoundsMax.z;
LABEL_23:
  m_Index = this->m_hActivator.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&moveMins);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&moveMins);
  v16.m_pWorldAxisTransform = nullptr;
  Ray_t::Init(this: &v16, start: &this->m_vecAbsOrigin, end: &this->m_vecAbsOrigin, mins: &moveMaxs, maxs: &v21);
  CTraceFilterDoor::CTraceFilterDoor(
    this: (CTraceFilterDoor *)&tr.hitbox,
    pDoor: this,
    passentity: m_pEntity,
    collisionGroup: 0);
  ((void (__thiscall *)(IEngineTrace *, Ray_t *, int, int *, int *, int, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: &v16,
    a3: 33570827,
    a4: &tr.hitbox,
    a5: &v17,
    a6: a3,
    a7: a4);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: &v19);
  if ( tr.plane.pad[0] != 0 || tr.plane.pad[1] != 0 )
  {
    if ( g_debug_doors.m_pParent != nullptr && g_debug_doors.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&moveMins);
      NDebugOverlay::Box(
        origin: &this->m_vecAbsOrigin,
        mins: &moveMaxs,
        maxs: &v21,
        r: 255,
        g: 0,
        b: 0,
        a: 1,
        flDuration: 10.0);
      if ( *(_DWORD *)&tr.surface.surfaceProps != 0 )
      {
        v9 = *(_DWORD *)&tr.surface.surfaceProps + 228;
        v10 = *(_DWORD *)&tr.surface.surfaceProps;
        if ( (*(_DWORD *)(*(_DWORD *)&tr.surface.surfaceProps + 196) & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: *(CBaseEntity **)&tr.surface.surfaceProps, a2: (int)&moveMins);
        v11 = *(int (__thiscall **)(int))(*(_DWORD *)v9 + 8);
        moveMaxs.y = 10.0;
        LODWORD(moveMaxs.x) = 1;
        v21.z = 0.0;
        LODWORD(v21.y) = 220;
        LODWORD(v21.x) = 220;
        v12 = (const Vector *)v11(a1: v9);
        v13 = *(_DWORD *)v9;
        m_pEntity = (IHandleEntity *)v12;
        v14 = (const Vector *)(*(int (__thiscall **)(int))(v13 + 4))(a1: v9);
        NDebugOverlay::Box(
          origin: (const Vector *)(v10 + 460),
          mins: v14,
          maxs: (const Vector *)m_pEntity,
          r: SLODWORD(v21.x),
          g: SLODWORD(v21.y),
          b: SLODWORD(v21.z),
          a: SLODWORD(moveMaxs.x),
          flDuration: moveMaxs.y);
      }
    }
    return 0;
  }
  else
  {
    if ( g_debug_doors.m_pParent != nullptr && g_debug_doors.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&moveMins);
      NDebugOverlay::Box(
        origin: &this->m_vecAbsOrigin,
        mins: &moveMaxs,
        maxs: &v21,
        r: 0,
        g: 255,
        b: 0,
        a: 1,
        flDuration: 10.0);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E8760
// Name: public: virtual void CPropDoorRotating::BeginOpening(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::BeginOpening(CPropDoorRotating *this, CBaseEntity *pOpenAwayFrom)
{
  PropDoorRotatingOpenDirection_e m_eOpenDirection; // eax
  doorCheck_e v4; // ebx
  float z; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  unsigned int m_Index; // ecx
  int v9; // eax
  CEntInfo *v10; // edx
  unsigned int v11; // ecx
  int v12; // eax
  bool v13; // zf
  CBaseEntity **v14; // eax
  CBaseEntity *v15; // eax
  const Vector *v16; // eax
  char v17; // bl
  CEntityBlocker *v19; // eax
  float v20; // xmm7_4
  float x; // xmm3_4
  float v22; // xmm6_4
  float y; // xmm1_4
  unsigned int v24; // ecx
  CBaseEntityList *v25; // edi
  int v26; // eax
  CEntInfo *v27; // edx
  unsigned int v28; // ecx
  int v29; // eax
  CBaseEntity **v30; // eax
  CBaseEntity *v31; // eax
  unsigned int v32; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v34; // eax
  IHandleEntity *v35; // ecx
  IHandleEntity *v36; // ebx
  IHandleEntity *v37; // ecx
  IHandleEntity *v38; // edi
  const Vector *v39; // eax
  const Vector *v40; // [esp-8h] [ebp-74h]
  Vector volumeCenter; // [esp+1Ch] [ebp-50h] BYREF
  Vector vecToActivator; // [esp+28h] [ebp-44h] BYREF
  Vector vecForwardDoor; // [esp+34h] [ebp-38h] BYREF
  Vector mins; // [esp+40h] [ebp-2Ch] BYREF
  Vector maxs; // [esp+4Ch] [ebp-20h] BYREF
  QAngle angOpen; // [esp+58h] [ebp-14h] BYREF
  doorCheck_e eDirCheck; // [esp+64h] [ebp-8h]
  bool isOpenForwardOnLeft; // [esp+6Ah] [ebp-2h]
  bool isActivatorOnLeft; // [esp+6Bh] [ebp-1h]
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF
  float volumeRadius; // [esp+74h] [ebp+8h]

  angOpen.z = this->m_angRotationOpenForward.z;
  m_eOpenDirection = this->m_eOpenDirection;
  v4 = DOOR_CHECK_FORWARD;
  *(_QWORD *)&angOpen.x = *(_QWORD *)&this->m_angRotationOpenForward.x;
  eDirCheck = DOOR_CHECK_FORWARD;
  if ( m_eOpenDirection == DOOR_ROTATING_OPEN_FORWARD )
  {
    angOpen.x = this->m_angRotationOpenForward.x;
    angOpen.y = this->m_angRotationOpenForward.y;
    z = this->m_angRotationOpenForward.z;
    eDirCheck = DOOR_CHECK_FORWARD;
    angOpen.z = z;
LABEL_31:
    mins = this->m_vecForwardBoundsMin;
    maxs.x = this->m_vecForwardBoundsMax.x;
    maxs.y = this->m_vecForwardBoundsMax.y;
    v7 = this->m_vecForwardBoundsMax.z;
    goto LABEL_6;
  }
  if ( m_eOpenDirection == DOOR_ROTATING_OPEN_BACKWARD )
  {
    angOpen.x = this->m_angRotationOpenBack.x;
    angOpen.y = this->m_angRotationOpenBack.y;
    v6 = this->m_angRotationOpenBack.z;
    eDirCheck = DOOR_CHECK_BACKWARD;
    angOpen.z = v6;
  }
  else
  {
    if ( pOpenAwayFrom != nullptr )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v16 = this->WorldSpaceCenter(this);
      vecForwardDoor.x = v16->x - this->m_vecAbsOrigin.x;
      vecForwardDoor.y = v16->y - this->m_vecAbsOrigin.y;
      vecForwardDoor.z = 0.0;
      VectorNormalize(vec: &vecForwardDoor);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (pOpenAwayFrom->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pOpenAwayFrom, a2: (int)&savedregs);
      vecToActivator.x = pOpenAwayFrom->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
      vecToActivator.y = pOpenAwayFrom->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
      vecToActivator.z = 0.0;
      VectorNormalize(vec: &vecToActivator);
      isActivatorOnLeft = (float)((float)(vecToActivator.y * vecForwardDoor.x)
                                - (float)(vecForwardDoor.y * vecToActivator.x)) >= 0.0;
      v17 = 0;
      if ( AngleNormalize(angle: this->m_angRotationOpenForward.y - this->m_angRotation.m_Value.y) >= 0.0 )
      {
        isOpenForwardOnLeft = true;
        v17 = 1;
      }
      if ( isActivatorOnLeft == v17 )
      {
        angOpen = this->m_angRotationOpenBack;
        eDirCheck = DOOR_CHECK_BACKWARD;
      }
      v4 = eDirCheck;
    }
    if ( CBasePropDoor::IsPlayerOpening(this)
      && pOpenAwayFrom != nullptr
      && pOpenAwayFrom->IsPlayer(this: pOpenAwayFrom)
      && CPropDoorRotating::CheckDoorClear(
           this,
           a2: COERCE_FLOAT(&savedregs),
           a3: (int)pOpenAwayFrom,
           a4: (int)this,
           state: v4) == 0 )
    {
      if ( v4 != DOOR_CHECK_FORWARD )
      {
        angOpen = this->m_angRotationOpenForward;
        eDirCheck = DOOR_CHECK_FORWARD;
        goto LABEL_31;
      }
      angOpen = this->m_angRotationOpenBack;
      eDirCheck = DOOR_CHECK_BACKWARD;
    }
    else if ( v4 == DOOR_CHECK_FORWARD )
    {
      goto LABEL_31;
    }
  }
  mins = this->m_vecBackBoundsMin;
  maxs.x = this->m_vecBackBoundsMax.x;
  maxs.y = this->m_vecBackBoundsMax.y;
  v7 = this->m_vecBackBoundsMax.z;
LABEL_6:
  m_Index = this->m_hDoorBlocker.m_Index;
  maxs.z = v7;
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
      UTIL_Remove(oldObj: v15);
    }
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v19 = CEntityBlocker::Create(origin: &this->m_vecAbsOrigin, &mins, &maxs, pOwner: pOpenAwayFrom, bBlockPhysics: false);
  if ( v19 != nullptr )
    this->m_hDoorBlocker.m_Index = v19->GetRefEHandle(this: v19)->m_Index;
  else
    this->m_hDoorBlocker.m_Index = -1;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v20 = this->m_vecAbsOrigin.x + (float)((float)(maxs.x + mins.x) * 0.5);
  volumeCenter.y = this->m_vecAbsOrigin.y + (float)((float)(maxs.y + mins.y) * 0.5);
  volumeCenter.z = this->m_vecAbsOrigin.z + (float)((float)(maxs.z + mins.z) * 0.5);
  x = fabs(mins.x);
  volumeCenter.x = v20;
  if ( x <= maxs.x )
    x = maxs.x;
  v22 = fabs(mins.y);
  volumeRadius = x;
  if ( v22 <= maxs.y )
    y = maxs.y;
  else
    y = v22;
  if ( x <= y )
  {
    if ( v22 <= maxs.y )
      x = maxs.y;
    else
      x = v22;
    volumeRadius = x;
  }
  if ( g_debug_doors.m_pParent != nullptr && g_debug_doors.m_pParent->m_Value.m_nValue != 0 )
  {
    vecToActivator.x = x;
    vecToActivator.y = x;
    vecToActivator.z = x;
    LODWORD(vecForwardDoor.x) = LODWORD(x) ^ _mask__NegFloat_;
    LODWORD(vecForwardDoor.y) = LODWORD(x) ^ _mask__NegFloat_;
    LODWORD(vecForwardDoor.z) = LODWORD(x) ^ _mask__NegFloat_;
    NDebugOverlay::Cross3D(
      position: &volumeCenter,
      mins: &vecForwardDoor,
      maxs: &vecToActivator,
      r: 255,
      g: 0,
      b: 0,
      noDepthTest: 1,
      fDuration: 1.0);
    x = volumeRadius;
  }
  if ( (this->m_spawnflags.m_Value & 0x4000) == 0 )
    CSoundEnt::InsertSound(
      iType: 4096,
      vecOrigin: &volumeCenter,
      iVolume: (int)x,
      flDuration: 0.5,
      pOwner: pOpenAwayFrom,
      soundChannelIndex: 0,
      pSoundTarget: nullptr);
  v24 = this->m_hDoorBlocker.m_Index;
  if ( v24 != -1 )
  {
    v25 = g_pEntityList;
    v26 = (unsigned __int16)v24;
    v27 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v24];
    v28 = HIWORD(v24);
    if ( v27->m_SerialNumber == v28 && v27->m_pEntity != nullptr )
    {
      v29 = v26;
      v13 = g_pEntityList->m_EntPtrArray[v29].m_SerialNumber == v28;
      v30 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v29];
      if ( v13 )
        v31 = *v30;
      else
        v31 = nullptr;
      CBaseEntity::SetCollisionGroup(this: v31, collisionGroup: 14);
      if ( CPropDoorRotating::CheckDoorClear(
             this,
             a2: COERCE_FLOAT(&savedregs),
             a3: (int)v25,
             a4: (int)this,
             state: eDirCheck) == 0 )
      {
        v32 = this->m_hDoorBlocker.m_Index;
        if ( v32 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_SerialNumber != HIWORD(v32) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_pEntity;
        CCollisionProperty::SetSolidFlags(
          this: (CCollisionProperty *)&m_pEntity[57],
          flags: LOWORD(m_pEntity[65].__vftable) | 4);
      }
      if ( g_debug_doors.m_pParent != nullptr && g_debug_doors.m_pParent->m_Value.m_nValue != 0 )
      {
        v34 = this->m_hDoorBlocker.m_Index;
        if ( v34 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v34].m_SerialNumber != HIWORD(v34) )
          v35 = nullptr;
        else
          v35 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v34].m_pEntity;
        v36 = v35 + 57;
        if ( v34 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v34].m_SerialNumber != HIWORD(v34) )
          v37 = nullptr;
        else
          v37 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v34].m_pEntity;
        v38 = v37 + 57;
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v40 = (const Vector *)v36->GetRefEHandle(this: v36);
        v39 = (const Vector *)((int (__thiscall *)(IHandleEntity *))v38->SetRefEHandle)(a1: v38);
        NDebugOverlay::Box(
          origin: &this->m_vecAbsOrigin,
          mins: v39,
          maxs: v40,
          r: 255,
          g: 0,
          b: 0,
          a: 1,
          flDuration: 1.0);
      }
    }
  }
  CPropDoorRotating::AngularMove(this, a2: COERCE_FLOAT(&savedregs), vecDestAngle: &angOpen, flSpeed: this->m_flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x101E8E30
// Name: public: virtual void CPropDoorRotating::BeginClosing(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPropDoorRotating::BeginClosing(CPropDoorRotating *this@<ecx>, int a2@<edi>)
{
  unsigned int m_Index; // eax
  bool v4; // al
  unsigned int v5; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx
  IHandleEntity *v9; // ebx
  IHandleEntity *v10; // ecx
  IHandleEntity *v11; // edi
  const Vector *v12; // eax
  const Vector *v13; // [esp-14h] [ebp-3Ch]
  Vector vecAbsMins; // [esp+10h] [ebp-18h] BYREF
  Vector vecAbsMaxs; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  m_Index = this->m_hDoorBlocker.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v4 = this->m_angRotationOpenForward.x == this->m_angGoal.x
      && this->m_angRotationOpenForward.y == this->m_angGoal.y
      && this->m_angRotationOpenForward.z == this->m_angGoal.z;
    if ( CPropDoorRotating::CheckDoorClear(
           this,
           a2: COERCE_FLOAT(&savedregs),
           a3: a2,
           a4: (int)this,
           state: (doorCheck_e)!v4) != 0 )
    {
      v5 = this->m_hDoorBlocker.m_Index;
      if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      CCollisionProperty::SetSolidFlags(
        this: (CCollisionProperty *)&m_pEntity[57],
        flags: (int)m_pEntity[65].__vftable & 0xFFFB);
    }
    if ( g_debug_doors.m_pParent != nullptr && g_debug_doors.m_pParent->m_Value.m_nValue != 0 )
    {
      v7 = this->m_hDoorBlocker.m_Index;
      if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
        v8 = nullptr;
      else
        v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      v9 = v8 + 57;
      if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
        v10 = nullptr;
      else
        v10 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      v11 = v10 + 57;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v13 = (const Vector *)v9->GetRefEHandle(this: v9);
      v12 = (const Vector *)((int (__thiscall *)(IHandleEntity *))v11->SetRefEHandle)(a1: v11);
      NDebugOverlay::Box(origin: &this->m_vecAbsOrigin, mins: v12, maxs: v13, r: 255, g: 0, b: 0, a: 1, flDuration: 1.0);
    }
  }
  CCollisionProperty::CollisionAABBToWorldAABB(
    this: &this->m_Collision,
    entityMins: &this->m_Collision.m_vecMins.m_Value,
    entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
    pWorldMins: &vecAbsMins,
    pWorldMaxs: &vecAbsMaxs);
  CPropDoorRotating::AngularMove(
    this,
    a2: COERCE_FLOAT(&savedregs),
    vecDestAngle: &this->m_angRotationClosed,
    flSpeed: this->m_flSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x101E9110
// Name: public: virtual void CPhysicsPropMultiplayer::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPropMultiplayer::VPhysicsUpdate(CPhysicsPropMultiplayer *this, IPhysicsObject *pPhysics)
{
  CPhysicsProp::VPhysicsUpdate(this, pPhysics);
  if ( sv_turbophysics.m_pParent != nullptr
    && sv_turbophysics.m_pParent->m_Value.m_nValue != 0
    && (this->m_spawnflags.m_Value & 4) == 0 )
  {
    if ( this->m_bAwake.m_Value )
    {
      CBaseEntity::SetCollisionGroup(this, collisionGroup: 17);
    }
    else if ( this->m_iPhysicsMode.m_Value == 2 )
    {
      CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
    }
    else
    {
      CBaseEntity::SetCollisionGroup(this, collisionGroup: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E9540
// Name: public: virtual void CPhysicsPropRespawnable::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPropRespawnable::Event_Killed(CPhysicsPropRespawnable *this, const CTakeDamageInfo *info)
{
  IPhysicsObject *m_pPhysicsObject; // edi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v6; // eax
  CBaseEntity *v7; // ecx

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr && !m_pPhysicsObject->IsMoveable(this: this->m_pPhysicsObject) )
  {
    m_pPhysicsObject->EnableMotion(this: m_pPhysicsObject, a2: true);
    this->VPhysicsTakeDamage(this, a2: info);
  }
  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CBreakableProp::Break(this, pBreaker: m_pEntity, info);
  PhysCleanupFrictionSounds(pEntity: this);
  this->VPhysicsDestroyObject(this);
  CBaseEntity::PhysicsRemoveTouchedList(ent: this);
  CBaseEntity::PhysicsRemoveGroundList(ent: this);
  CBaseEntity::DestroyAllDataObjects(this);
  CBaseEntity::AddEffects(this, nEffects: 32);
  if ( (this->m_fFlags.m_Value & 0x10000000) != 0 || (this->m_fFlags.m_Value & 0x20000000) != 0 )
  {
    v6 = this->m_hEffectEntity.m_Value.m_Index;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      v7 = nullptr;
    else
      v7 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    UTIL_Remove(oldObj: v7);
  }
  this->Teleport(this, a2: &this->m_vOriginalSpawnOrigin, a3: &this->m_vOriginalSpawnAngles, a4: nullptr, a5: true);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: "PROP_CLEARFLAGS");
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CPhysicsPropRespawnable::Materialize,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: this->m_flRespawnTime + gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101E9A20
// Name: public: CPropDoorRotatingBreakable::CPropDoorRotatingBreakable(void)
// Source: json
//------------------------------------------------------------------------------
CPropDoorRotatingBreakable *__thiscall CPropDoorRotatingBreakable::CPropDoorRotatingBreakable(
        CPropDoorRotatingBreakable *this)
{
  CBasePropDoor::CBasePropDoor(this);
  this->m_OnRotationDone.m_Value.iVal = 0;
  this->m_OnRotationDone.m_Value.eVal.m_Index = -1;
  this->m_OnRotationDone.m_Value.fieldType = FIELD_VOID;
  this->m_hDoorBlocker.m_Index = -1;
  this->CPropDoorRotating::CBasePropDoor::CDynamicProp::CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPropDoorRotatingBreakable_vtbl *)&CPropDoorRotatingBreakable::`vftable'{for `CBaseProp'};
  this->CPropDoorRotating::CBasePropDoor::CDynamicProp::CBreakableProp::IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CPropDoorRotatingBreakable::`vftable'{for `IBreakableWithPropData'};
  this->CPropDoorRotating::CBasePropDoor::CDynamicProp::CBreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPropDoorRotatingBreakable::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->CPropDoorRotating::CBasePropDoor::CDynamicProp::IPositionWatcher::IWatcherCallback::__vftable = (IPositionWatcher_vtbl *)&CPropDoorRotatingBreakable::`vftable';
  this->m_damageStates.m_Memory.m_pMemory = nullptr;
  this->m_damageStates.m_Memory.m_nAllocationCount = 0;
  this->m_damageStates.m_Memory.m_nGrowSize = 0;
  this->m_damageStates.m_Size = 0;
  this->m_damageStates.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E9AA0
// Name: public: virtual void CPropDoorRotatingBreakable::OnDoorOpened(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CPropDoorRotatingBreakable::OnDoorOpened(CPropDoorRotatingBreakable *this@<ecx>, int a2@<ebp>)
{
  CPropDoorRotating::OnDoorOpened(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101E9AB0
// Name: public: virtual void CPropDoorRotatingBreakable::OnDoorClosed(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CPropDoorRotatingBreakable::OnDoorClosed(CPropDoorRotatingBreakable *this@<ecx>, int a2@<ebp>)
{
  CPropDoorRotating::OnDoorClosed(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101E9AF0
// Name: public: void CBreakableProp::HandleInteractionStick(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::HandleInteractionStick(CBreakableProp *this, int index, gamevcollisionevent_t *pEvent)
{
  __int64 v3; // xmm0_8
  float z; // ecx
  float x; // xmm2_4
  float y; // xmm1_4
  float v7; // xmm0_4
  int material; // eax
  float v9; // ecx
  __int64 v10; // xmm0_8
  float v11; // xmm3_4
  CFunctor *v12; // eax
  QAngle angles; // [esp+8h] [ebp-4Ch] BYREF
  Vector savePosition; // [esp+14h] [ebp-40h] BYREF
  Vector vecDir; // [esp+20h] [ebp-34h] BYREF
  Vector vecEmbed; // [esp+2Ch] [ebp-28h] BYREF
  Vector position; // [esp+38h] [ebp-1Ch] BYREF
  Vector vecNormal; // [esp+44h] [ebp-10h] BYREF
  CBreakableProp *pObject; // [esp+50h] [ebp-4h]

  v3 = *(_QWORD *)&pEvent->preVelocity[index].x;
  pObject = this;
  z = pEvent->preVelocity[index].z;
  *(_QWORD *)&vecDir.x = v3;
  vecDir.z = z;
  if ( VectorNormalize(vec: &vecDir) > 1000.0 )
  {
    pObject->m_pPhysicsObject->GetPosition(this: pObject->m_pPhysicsObject, a2: &position, a3: &angles);
    pEvent->pInternalData->GetSurfaceNormal(this: pEvent->pInternalData, a2: &vecNormal);
    x = vecNormal.x;
    y = vecNormal.y;
    v7 = vecNormal.z;
    if ( index == 1 )
    {
      x = vecNormal.x * -1.0;
      y = vecNormal.y * -1.0;
      v7 = vecNormal.z * -1.0;
      vecNormal.x = vecNormal.x * -1.0;
      vecNormal.y = vecNormal.y * -1.0;
      vecNormal.z = vecNormal.z * -1.0;
    }
    if ( (float)((float)((float)(vecDir.y * y) + (float)(vecDir.x * x)) + (float)(vecDir.z * v7)) > 0.3 )
    {
      material = physprops->GetSurfaceData(this: physprops, a2: pEvent->surfaceProps[index == 0])->game.material;
      if ( material != 77 && material != 71 && material != 88 )
      {
        v9 = pEvent->preVelocity[index].z;
        *(_QWORD *)&savePosition.x = *(_QWORD *)&position.x;
        v10 = *(_QWORD *)&pEvent->preVelocity[index].x;
        savePosition.z = position.z;
        *(_QWORD *)&vecEmbed.x = v10;
        vecEmbed.z = v9;
        VectorNormalize(vec: &vecEmbed);
        v11 = position.x + (float)(vecEmbed.x * 8.0);
        vecEmbed.x = vecEmbed.x * 8.0;
        position.y = position.y + (float)(vecEmbed.y * 8.0);
        *(float *)&v10 = position.z + (float)(vecEmbed.z * 8.0);
        vecEmbed.y = vecEmbed.y * 8.0;
        vecEmbed.z = vecEmbed.z * 8.0;
        position.x = v11;
        LODWORD(position.z) = v10;
        v12 = CreateFunctor<CBreakableProp *,CBreakableProp,void,Vector const &,Vector const &,QAngle const &,Vector,Vector,QAngle>(
                pObject,
                pfnProxied: (void (__thiscall *__ptr64)(CBreakableProp *, const Vector *, const Vector *, const QAngle *))(unsigned int)CBreakableProp::StickAtPosition,
                arg1: &position,
                arg2: &savePosition,
                arg3: &angles);
        CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this: &g_PostSimulationQueue, pFunctor: v12);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EA550
// Name: public: virtual void CBreakableProp::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::Spawn(CBreakableProp *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // ebx
  int m_Value; // ebx
  float m_impactEnergyScale; // xmm1_4
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  this->m_flDefaultFadeScale = CBaseEntity::GetGlobalFadeScale(this);
  this->m_flDmgModBullet = 1.0;
  this->m_flDmgModClub = 1.0;
  this->m_flDmgModExplosive = 1.0;
  this->m_flDmgModFire = 1.0;
  CBaseProp::Spawn(this);
  if ( (this->m_iEFlags & 1) != 0 )
    return;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  if ( (m_pStudioHdr->m_pStudioHdr->flags & 0x800) != 0 )
  {
    CBaseEntity::SetGlobalFadeScale(this, flFadeScale: 0.0);
    this->m_flDefaultFadeScale = 0.0;
  }
  else
  {
    CBaseEntity::SetGlobalFadeScale(this, flFadeScale: this->m_flDefaultFadeScale);
  }
  if ( this->m_iNumBreakableChunks == 0
    && *(_DWORD *)((int (__thiscall *)(IBreakableWithPropData *, _BYTE *))this->GetBreakableModel)(
                    a1: &this->IBreakableWithPropData,
                    a2: v6) != 0
    && this->GetBreakableCount(this: &this->IBreakableWithPropData) != 0 )
  {
    this->m_iNumBreakableChunks = this->GetBreakableCount(this: &this->IBreakableWithPropData);
  }
  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value == 0 )
    goto LABEL_33;
  if ( this->m_iNumBreakableChunks == 0
    && !this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_BREAK_EXPLODE)
    && !this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_BREAK_EXPLODE_ICE)
    && !this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_FIRST_BREAK)
    && !this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_FIRE_FLAMMABLE)
    && !this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_FIRE_IGNITE_HALFHEALTH)
    && !this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_MELEE_IMMUNE)
    && !this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_FIRE_EXPLOSIVE_RESIST) )
  {
    if ( p_m_iHealth->m_Value != 0 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      p_m_iHealth->m_Value = 0;
    }
LABEL_33:
    if ( this->m_takedamage.m_Value != 1 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      this->m_takedamage.m_Value = 1;
    }
    goto LABEL_35;
  }
  if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  if ( g_pGameRules->GetAutoAimMode(this: g_pGameRules) == 2
    && (this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_BREAK_EXPLODE)
     || this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_BREAK_EXPLODE_ICE)
     || this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_FIRE_IGNITE_HALFHEALTH)) )
  {
    CBaseEntity::AddFlag(this, flags: 0x20000);
  }
LABEL_35:
  m_Value = p_m_iHealth->m_Value;
  if ( m_Value <= 0 )
    m_Value = 1;
  if ( this->m_iMaxHealth.m_Value != m_Value )
  {
    this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
    this->m_iMaxHealth.m_Value = m_Value;
  }
  m_impactEnergyScale = this->m_impactEnergyScale;
  this->m_createTick = gpGlobals->tickcount;
  if ( m_impactEnergyScale == 0.0 )
    this->m_impactEnergyScale = 0.1;
  this->m_preferredCarryAngles.x = -5.0;
  this->m_preferredCarryAngles.y = 0.0;
  this->m_preferredCarryAngles.z = 0.0;
  if ( CBaseAnimating::SelectWeightedSequence(this, activity: ACT_PHYSCANNON_ANIMATE) == -1 )
    this->m_nPhysgunState = CBaseAnimating::SelectWeightedSequence(this, activity: ACT_PHYSCANNON_DETACH) != -1 ? 0 : 2;
  else
    this->m_nPhysgunState = 3;
  this->m_hLastAttacker.m_Index = -1;
  this->m_hBreaker.m_Index = -1;
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBreakableProp::BreakablePropTouch;
}

//------------------------------------------------------------------------------
// Address: 0x101EA8E0
// Name: public: void CDynamicProp::AnimThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::AnimThink(CDynamicProp *this)
{
  __int16 m_nPendingSequence; // ax
  int v3; // eax
  float v4; // xmm0_4
  char v5; // bl
  float curtime; // xmm0_4
  float thinkTime; // xmm0_4
  unsigned int m_Index; // esi
  IHandleEntity *m_pEntity; // eax
  const char *pszValue; // eax
  IHandleEntity *v11; // ebx
  CPhysicsPushedEntities *v12; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBaseEntity **m_pMemory; // ecx
  int v16; // eax
  CBaseEntity **v17; // eax
  IHandleEntity_vtbl *v18; // eax
  IHandleEntity *v19; // eax

  m_nPendingSequence = this->m_nPendingSequence;
  if ( m_nPendingSequence != -1 )
  {
    CDynamicProp::FinishSetSequence(this, nSequence: m_nPendingSequence);
    this->m_nPendingSequence = -1;
  }
  if ( this->m_bRandomAnimator && gpGlobals->curtime > this->m_flNextRandAnim )
  {
    v3 = CBaseAnimating::SelectWeightedSequence(this, activity: ACT_IDLE);
    CBaseAnimating::ResetSequence(this, nSequence: v3);
    CBaseAnimating::ResetClientsideFrame(this);
    COutputEvent::FireOutput(this: &this->m_pOutputAnimBegun, pActivator: nullptr, pCaller: this, fDelay: 0.0);
    this->m_flNextRandAnim = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                               a1: random,
                               a2: LODWORD(this->m_flMinRandAnimTime),
                               a3: LODWORD(this->m_flMaxRandAnimTime))
                           + gpGlobals->curtime;
  }
  v4 = 1.0 - this->m_flFrozen.m_Value;
  if ( v4 >= 0.0 )
  {
    if ( v4 > 1.0 )
      v4 = 1.0;
  }
  else
  {
    v4 = 0.0;
  }
  if ( (float)(this->m_flPlaybackRate.m_Value * v4) < 0.0 )
  {
    if ( this->m_flCycle.m_Value > 0.0 )
      goto LABEL_12;
  }
  else if ( this->m_flCycle.m_Value < 0.99900001 )
  {
LABEL_12:
    v5 = 0;
    this->m_bAnimationDone = false;
    curtime = gpGlobals->curtime;
LABEL_13:
    thinkTime = curtime + 0.1;
LABEL_14:
    CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
    goto LABEL_15;
  }
  if ( this->m_bSequenceLoops )
    goto LABEL_12;
  v5 = 1;
  if ( this->m_nSequence.m_Value != this->m_iGoalSequence )
  {
    CDynamicProp::PropSetSequence(this, nSequence: this->m_iGoalSequence);
    v5 = 0;
    goto LABEL_15;
  }
  if ( !this->m_bAnimationDone )
  {
    this->m_bAnimationDone = true;
    COutputEvent::FireOutput(this: &this->m_pOutputAnimOver, pActivator: nullptr, pCaller: this, fDelay: 0.0);
  }
  if ( this->m_bRandomAnimator )
  {
    thinkTime = (float)(this->m_flNextRandAnim + gpGlobals->curtime) + 0.1;
    goto LABEL_14;
  }
  if ( this->m_iszDefaultAnim.pszValue != nullptr )
  {
    if ( this->m_bHoldAnimation )
    {
LABEL_37:
      curtime = gpGlobals->curtime;
      goto LABEL_13;
    }
    pszValue = this->m_iszDefaultAnim.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CDynamicProp::PropSetAnim(this, szAnim: pszValue);
    v5 = 0;
  }
  if ( this->m_bHoldAnimation )
    goto LABEL_37;
LABEL_15:
  if ( this->m_bAnimateEveryFrame )
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  if ( v5 == 0 || this->m_nPendingSequence != -1 || !this->m_bSequenceFinished )
  {
    this->StudioFrameAdvance(this);
    this->DispatchAnimEvents(this, a2: this);
    CBoneFollowerManager::UpdateBoneFollowers(this: &this->m_BoneFollowerManager, pParentEntity: this);
    m_Index = this->m_hMoveChild.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v11 = m_pEntity;
    if ( m_pEntity != nullptr )
    {
      do
      {
        v12 = g_pPushedEntities;
        m_Size = g_pPushedEntities->m_rgUpdatedChildren.m_Size;
        m_nAllocationCount = g_pPushedEntities->m_rgUpdatedChildren.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&g_pPushedEntities->m_rgUpdatedChildren,
            num: m_Size - m_nAllocationCount + 1);
        ++v12->m_rgUpdatedChildren.m_Size;
        m_pMemory = v12->m_rgUpdatedChildren.m_Memory.m_pMemory;
        v16 = v12->m_rgUpdatedChildren.m_Size - m_Size - 1;
        v12->m_rgUpdatedChildren.m_pElements = m_pMemory;
        if ( v16 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
        v17 = &v12->m_rgUpdatedChildren.m_Memory.m_pMemory[m_Size];
        if ( v17 != nullptr )
          *v17 = (CBaseEntity *)v11;
        v18 = v11[56].__vftable;
        if ( v18 == (IHandleEntity_vtbl *)-1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != (unsigned int)v18 >> 16 )
        {
          v19 = nullptr;
        }
        else
        {
          v19 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
        }
        v11 = v19;
      }
      while ( v19 != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EAC20
// Name: public: void CDynamicProp::InputSetPlaybackRate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::InputSetPlaybackRate(CDynamicProp *this, inputdata_t *inputdata)
{
  float flVal; // xmm3_4
  float v4; // xmm0_4
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  v4 = 1.0 - this->m_flFrozen.m_Value;
  if ( v4 >= 0.0 )
  {
    if ( v4 > 1.0 )
      v4 = 1.0;
  }
  else
  {
    v4 = 0.0;
  }
  if ( (float)(this->m_flPlaybackRate.m_Value * v4) != flVal )
  {
    this->m_bSequenceFinished = false;
    if ( this->m_flPlaybackRate.m_Value != flVal )
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
      this->m_flPlaybackRate.m_Value = flVal;
    }
    if ( gpGlobals->curtime >= CBaseEntity::GetNextThink(this, szContext: nullptr) )
    {
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CDynamicProp::AnimThink,
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EAD20
// Name: public: virtual void COrnamentProp::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COrnamentProp::Activate(COrnamentProp *this)
{
  const char *v2; // eax
  const char *pszValue; // ecx
  const char *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  CBaseAnimating::Activate(this);
  if ( this->m_takedamage.m_Value == 0 && this->m_iHealth.m_Value != 0 )
  {
    v2 = *(const char **)((int (__thiscall *)(COrnamentProp *, _BYTE *))this->GetModelName)(a1: this, a2: v5);
    if ( v2 == nullptr )
      v2 = locale;
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "%s has a health specified in model '%s'. Use prop_physics or prop_dynamic instead.\n", pszValue, v2);
  }
  v4 = this->m_initialOwner.pszValue;
  if ( v4 != nullptr )
    COrnamentProp::AttachTo(this, pAttachName: v4, pActivator: nullptr, pCaller: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101EAD90
// Name: public: void COrnamentProp::InputSetAttached(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COrnamentProp::InputSetAttached(COrnamentProp *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

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
  COrnamentProp::AttachTo(this, pAttachName: iVal, pActivator: inputdata->pActivator, pCaller: inputdata->pCaller);
}

//------------------------------------------------------------------------------
// Address: 0x101EADD0
// Name: public: virtual void CPhysicsProp::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::Spawn(CPhysicsProp *this)
{
  bool v2; // zf
  const char *v3; // eax
  IVModelInfo_vtbl *v4; // edi
  model_t *Model; // eax
  KeyValues *v6; // eax
  KeyValues *Key; // eax
  _BYTE *v8; // eax
  IPhysicsObject *m_pPhysicsObject; // ebx
  Vector *v10; // edi
  CResponseRulesToEngineInterface *v11; // ecx
  ICommandLine *v12; // eax
  edict_t *m_pPev; // ecx
  float maxFadeDist; // [esp+10h] [ebp-20h]
  QAngle qPreffered; // [esp+20h] [ebp-10h] BYREF
  char pszValue[4]; // [esp+2Ch] [ebp-4h] BYREF

  CBaseEntity::SetNetworkQuantizeOriginAngAngles(this, bQuantize: true);
  if ( (this->m_spawnflags.m_Value & 0x400000) != 0 )
    ++g_ActiveGibCount;
  if ( this->m_iClassname.pszValue == "physics_prop"
    || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "physics_prop") != 0 )
  {
    CBaseEntity::SetClassname(this, className: "prop_physics");
  }
  CBreakableProp::Spawn(this);
  if ( (this->m_iEFlags & 1) == 0 )
  {
    v2 = this->m_iClassname.pszValue == "prop_physics_override";
    this->m_flFrozenThawRate = 0.1;
    if ( v2 || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "prop_physics_override") != 0 )
      CBaseEntity::SetClassname(this, className: "prop_physics");
    if ( (this->m_spawnflags.m_Value & 4) != 0
      || this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_CREATE_FLARE) )
    {
      CBaseEntity::SetCollisionGroup(this, collisionGroup: ((this->m_spawnflags.m_Value & 0x1000) != 0) + 1);
    }
    if ( (this->m_spawnflags.m_Value & 0x80) != 0 )
      this->m_iEFlags |= 0x200000u;
    this->CreateVPhysics(this);
    if ( !this->m_bBlockLOSSetByPropData )
      CBaseProp::CalculateBlockLOS(this);
    v3 = *(const char **)((int (__thiscall *)(CPhysicsProp *, char *))this->GetModelName)(a1: this, a2: pszValue);
    if ( v3 == nullptr )
      v3 = locale;
    if ( _V_strcmp(s1: v3, s2: "models/props_c17/door01_left.mdl") == 0 )
    {
      CBaseAnimating::SetFadeDistance(this, minFadeDist: -1.0, maxFadeDist: 0.0);
      CBaseEntity::SetGlobalFadeScale(this, flFadeScale: 0.0);
      this->m_flDefaultFadeScale = 0.0;
    }
    v4 = modelinfo->__vftable;
    Model = CBaseEntity::GetModel(this);
    v6 = v4->GetModelKeyValues(this: modelinfo, a2: Model);
    if ( v6 != nullptr )
    {
      Key = KeyValues::FindKey(this: v6, keyName: "ai_addon", bCreate: false);
      if ( Key != nullptr )
      {
        KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: locale);
        this->m_AIAddOn.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
        return;
      }
      v8 = *(_BYTE **)((int (__thiscall *)(CPhysicsProp *, char *))this->GetAIAddOn)(a1: this, a2: pszValue);
      if ( v8 == nullptr || *v8 == 0 )
        this->m_AIAddOn.pszValue = "ai_addon_thrownprojectile";
    }
    if ( this->m_iPhysicsMode == 0 )
    {
      m_pPhysicsObject = this->m_pPhysicsObject;
      if ( m_pPhysicsObject == nullptr )
        goto LABEL_44;
      v10 = AllocTempVector();
      v10->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
      v10->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
      v10->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
      maxFadeDist = m_pPhysicsObject->GetMass(this: m_pPhysicsObject);
      this->m_iPhysicsMode = GetAutoMultiplayerPhysicsMode(size: *v10, mass: maxFadeDist);
    }
    if ( (this->m_spawnflags.m_Value & 0x2000) != 0 )
      this->SetPhysicsMode(this: &this->IBreakableWithPropData, a2: 2);
    if ( this->m_iPhysicsMode != 3 )
      goto LABEL_36;
    if ( engine->IsInEditMode(this: engine) != 0
      || (v12 = _CommandLine(this: v11), v12->FindParm(this: v12, a2: "-makereslists") != 0) )
    {
      this->SetPhysicsMode(this: &this->IBreakableWithPropData, a2: 2);
LABEL_36:
      if ( this->IsPotentiallyAbleToObstructNavAreas(this: &this->INavAvoidanceObstacle) != 0 )
        CNavMesh::RegisterAvoidanceObstacle(this: TheNavMesh, obstruction: &this->INavAvoidanceObstacle);
      if ( CPhysicsProp::GetPropDataAngles(this, pKeyName: "preferred_carryangles", vecAngles: &qPreffered)
        && (qPreffered.x != this->m_qPreferredPlayerCarryAngles.m_Value.x
         || qPreffered.y != this->m_qPreferredPlayerCarryAngles.m_Value.y
         || qPreffered.z != this->m_qPreferredPlayerCarryAngles.m_Value.z) )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5D8u);
        }
        this->m_qPreferredPlayerCarryAngles.m_Value = qPreffered;
      }
      return;
    }
LABEL_44:
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB190
// Name: public: void CPhysicsProp::InputEnableMotion(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPhysicsProp::InputEnableMotion(CPhysicsProp *this, inputdata_t *inputdata)
{
  CPhysicsProp::EnableMotion(this);
}

//------------------------------------------------------------------------------
// Address: 0x101EB1A0
// Name: public: void CPhysicsProp::NavThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::NavThink(CPhysicsProp *this)
{
  CNavArea **m_pMemory; // edi
  int i; // esi
  Extent extent; // [esp+10h] [ebp-34h] BYREF
  NavAreaCollector overlap; // [esp+28h] [ebp-1Ch] BYREF
  float obstructionHeight; // [esp+40h] [ebp-4h]

  if ( this->CanObstructNavAreas(this: &this->INavAvoidanceObstacle) )
  {
    CCollisionProperty::CollisionAABBToWorldAABB(
      this: &this->m_Collision,
      entityMins: &this->m_Collision.m_vecMins.m_Value,
      entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
      pWorldMins: &extent.lo,
      pWorldMaxs: &extent.hi);
    extent.lo.z = extent.lo.z - 71.0;
    memset(&overlap.m_area, 0, sizeof(overlap.m_area));
    overlap.m_checkForDuplicates = false;
    CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>(this: TheNavMesh, func: &overlap, &extent);
    obstructionHeight = this->GetNavObstructionHeight(this: &this->INavAvoidanceObstacle);
    m_pMemory = overlap.m_area.m_Memory.m_pMemory;
    for ( i = 0; i < overlap.m_area.m_Size; ++i )
      CNavArea::MarkObstacleToAvoid(this: m_pMemory[i], obstructionHeight);
    if ( overlap.m_area.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB2C0
// Name: private: void CBasePropDoor::DoorOpenMoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::DoorOpenMoveDone(CBasePropDoor *this)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax
  float m_flAutoReturnDelay; // xmm0_4
  float v5; // xmm1_4
  unsigned int v6; // eax
  IHandleEntity *m_pEntity; // ecx
  CAI_BaseNPC *v8; // eax
  float flDelay; // [esp+4h] [ebp-8h]

  this->m_hBlocker.m_Index = -1;
  m_Index = this->m_hBlocker.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    this->m_bFirstBlocked = false;
  }
  if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
  {
    pszValue = this->m_SoundOpen.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CBaseEntity::EmitSound(this, soundname: pszValue, soundtime: 0.0, duration: nullptr);
  }
  m_flAutoReturnDelay = this->m_flAutoReturnDelay;
  this->m_eDoorState = DOOR_STATE_OPEN;
  if ( m_flAutoReturnDelay != -1.0 )
  {
    flDelay = m_flAutoReturnDelay + 0.1;
    CBaseEntity::SetMoveDoneTime(this, flDelay);
    v5 = this->m_flAutoReturnDelay;
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CBasePropDoor::DoorAutoCloseThink;
    if ( v5 == -1.0 )
      CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
  v6 = this->m_hActivator.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  v8 = (CAI_BaseNPC *)__RTDynamicCast(
                        inptr: m_pEntity,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CAI_BaseNPC `RTTI Type Descriptor',
                        isReference: 0);
  if ( v8 != nullptr )
    CAI_BaseNPC::OnDoorFullyOpen(this: v8, pDoor: this);
  COutputEvent::FireOutput(this: &this->m_OnFullyOpen, pActivator: this, pCaller: this, fDelay: 0.0);
  this->OnDoorOpened(this);
  this->m_hActivator.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x101EB420
// Name: public: virtual bool CPropDoorRotating::DoorCanClose(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPropDoorRotating::DoorCanClose(CPropDoorRotating *this, int bAutoClose)
{
  CBaseEntityList *v2; // esi
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // eax
  int v13; // ebx
  unsigned int v14; // eax
  IHandleEntity *v15; // ecx
  CPropDoorRotating *v16; // eax
  CPropDoorRotating *v17; // edx
  doorCheck_e v18; // eax
  bool v19; // al
  int m_Size; // [esp+8h] [ebp-4h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  v2 = g_pEntityList;
  m_Index = this->m_hMaster.m_Index;
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
      m_pEntity = v10->m_pEntity;
    else
      m_pEntity = nullptr;
    return ((bool (__thiscall *)(IHandleEntity *, int))m_pEntity->__vftable[78].SetRefEHandle)(
             a1: m_pEntity,
             a2: bAutoClose);
  }
  else
  {
    m_Size = this->m_hDoorList.m_Size;
    if ( m_Size <= 0 )
    {
LABEL_10:
      if ( (_BYTE)bAutoClose != 0 )
      {
        return CPropDoorRotating::CheckDoorClear(
                 this,
                 a2: COERCE_FLOAT(&savedregs),
                 a3: (int)this,
                 a4: (int)v2,
                 state: DOOR_CHECK_FULL);
      }
      else
      {
        v19 = this->m_angRotationOpenForward.x == this->m_angGoal.x
           && this->m_angRotationOpenForward.y == this->m_angGoal.y
           && this->m_angRotationOpenForward.z == this->m_angGoal.z;
        return CPropDoorRotating::CheckDoorClear(
                 this,
                 a2: COERCE_FLOAT(&savedregs),
                 a3: (int)this,
                 a4: (int)v2,
                 state: (doorCheck_e)!v19);
      }
    }
    else
    {
      v13 = 0;
      while ( 1 )
      {
        v14 = this->m_hDoorList.m_Memory.m_pMemory[v13].m_Index;
        if ( v14 == -1 || v2->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
          v15 = nullptr;
        else
          v15 = v2->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
        v16 = (CPropDoorRotating *)__RTDynamicCast(
                                     inptr: v15,
                                     VfDelta: 0,
                                     SrcType: &CBasePropDoor `RTTI Type Descriptor',
                                     TargetType: &CPropDoorRotating `RTTI Type Descriptor',
                                     isReference: 0);
        v17 = v16;
        if ( v16 != nullptr )
        {
          v18 = (_BYTE)bAutoClose != 0 ? DOOR_CHECK_FULL : CPropDoorRotating::GetOpenState(this: v16);
          if ( CPropDoorRotating::CheckDoorClear(
                 this: v17,
                 a2: COERCE_FLOAT(&savedregs),
                 a3: (int)this,
                 a4: (int)v2,
                 state: v18) == 0 )
            return 0;
        }
        if ( ++v13 >= m_Size )
          goto LABEL_10;
        v2 = g_pEntityList;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB5B0
// Name: public: virtual void CPhysicsPropMultiplayer::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPropMultiplayer::Spawn(CPhysicsPropMultiplayer *this)
{
  IPhysicsObject *m_pPhysicsObject; // ebx
  Vector *v3; // edi
  int AutoMultiplayerPhysicsMode; // ebx
  edict_t *m_pPev; // ecx
  double v6; // st7
  edict_t *v7; // ecx
  IPhysicsObject *v8; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  IPhysicsCollision_vtbl *v11; // ebx
  int v12; // eax
  float mass; // [esp+0h] [ebp-14h]
  float pPhysicsa; // [esp+10h] [ebp-4h]
  IPhysicsObject *pPhysics; // [esp+10h] [ebp-4h]

  CPhysicsProp::Spawn(this);
  if ( this->m_iPhysicsMode.m_Value == 0 )
  {
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject == nullptr )
      goto LABEL_21;
    v3 = AllocTempVector();
    v3->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
    v3->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
    v3->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
    mass = m_pPhysicsObject->GetMass(this: m_pPhysicsObject);
    AutoMultiplayerPhysicsMode = GetAutoMultiplayerPhysicsMode(size: *v3, mass);
    if ( this->m_iPhysicsMode.m_Value != AutoMultiplayerPhysicsMode )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x6F4u);
      }
      this->m_iPhysicsMode.m_Value = AutoMultiplayerPhysicsMode;
    }
  }
  if ( (this->m_spawnflags.m_Value & 0x2000) != 0 )
    this->SetPhysicsMode(this: &this->IBreakableWithPropData, a2: 2);
  if ( this->m_iPhysicsMode.m_Value == 3 )
  {
    if ( engine->IsInEditMode(this: engine) == 0 )
    {
LABEL_21:
      UTIL_Remove(oldObj: this);
      return;
    }
    this->SetPhysicsMode(this: &this->IBreakableWithPropData, a2: 2);
  }
  if ( this->m_CollisionGroup.m_Value == 0 )
    CBaseEntity::SetCollisionGroup(this, collisionGroup: 17);
  if ( (this->m_spawnflags.m_Value & 4) != 0 )
    CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
  v6 = ((double (__thiscall *)(IPhysicsObject *))this->m_pPhysicsObject->GetMass)(a1: this->m_pPhysicsObject);
  if ( this->m_fMass.m_Value != v6 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x6F8u);
    }
    pPhysicsa = v6;
    this->m_fMass.m_Value = pPhysicsa;
  }
  this->m_usingCustomCollisionBounds = false;
  if ( this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_VPHYSICS && this->m_MoveType.m_Value == 6 )
  {
    v8 = this->m_pPhysicsObject;
    pPhysics = v8;
    if ( v8 != nullptr && v8->GetCollide(this: v8) != nullptr )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v9 = this->m_Network.m_pPev;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x70Cu);
      }
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x700u);
      }
      v11 = physcollision->__vftable;
      v12 = ((int (__thiscall *)(IPhysicsObject *, Vector *, QAngle *))pPhysics->GetCollide)(
              a1: pPhysics,
              a2: &vec3_origin,
              a3: &vec3_angle);
      ((void (__thiscall *)(IPhysicsCollision *, CNetworkVectorBase<Vector,CPhysicsPropMultiplayer::NetworkVar_m_collisionMins> *, CNetworkVectorBase<Vector,CPhysicsPropMultiplayer::NetworkVar_m_collisionMaxs> *, int))v11->CollideGetAABB)(
        a1: physcollision,
        a2: &this->m_collisionMins,
        a3: &this->m_collisionMaxs,
        a4: v12);
      CCollisionProperty::SetSurroundingBoundsType(
        this: &this->m_Collision,
        type: USE_GAME_CODE,
        pMins: nullptr,
        pMaxs: nullptr);
      this->m_usingCustomCollisionBounds = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB840
// Name: public: virtual void CPhysicsPropRespawnable::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysicsPropRespawnable::Spawn(CPhysicsPropRespawnable *this@<ecx>, int a2@<ebp>)
{
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  float *v4; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v5; // edx
  double v6; // st7
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  float *v8; // eax

  CPhysicsProp::Spawn(this);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  this->m_vOriginalSpawnOrigin.x = this->m_vecAbsOrigin.x;
  this->m_vOriginalSpawnOrigin.y = this->m_vecAbsOrigin.y;
  this->m_vOriginalSpawnOrigin.z = this->m_vecAbsOrigin.z;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  OBBMins = this->m_Collision.OBBMins;
  this->m_vOriginalSpawnAngles.x = this->m_angAbsRotation.x;
  this->m_vOriginalSpawnAngles.y = this->m_angAbsRotation.y;
  this->m_vOriginalSpawnAngles.z = this->m_angAbsRotation.z;
  v4 = (float *)OBBMins(this: &this->m_Collision);
  v5 = this->m_Collision.CPhysicsProp::CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::__vftable;
  this->m_vOriginalMins.x = *v4;
  this->m_vOriginalMins.y = v4[1];
  v6 = v4[2];
  OBBMaxs = v5->OBBMaxs;
  this->m_vOriginalMins.z = v6;
  v8 = (float *)OBBMaxs(this: &this->m_Collision);
  this->m_vOriginalMaxs.x = *v8;
  this->m_vOriginalMaxs.y = v8[1];
  this->m_vOriginalMaxs.z = v8[2];
  if ( this->m_flRespawnTime == 0.0 )
    this->m_flRespawnTime = 60.0;
  this->SetOwnerEntity(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101EB9E0
// Name: public: void CBreakableProp::HandleFirstCollisionInteractions(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::HandleFirstCollisionInteractions(
        CBreakableProp *this,
        int index,
        gamevcollisionevent_t *pEvent)
{
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CBaseEntity *); // eax
  unsigned int m_Index; // ecx
  const CBaseHandle *(__thiscall *v6)(struct CBaseEntity *); // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  float z; // eax
  edict_t *m_pPev; // ecx
  int v10; // ecx
  int v11; // ecx
  int i; // esi
  void (__thiscall ***v13)(void *, int, int, gamevcollisionevent_t *); // eax
  CGameTrace tr; // [esp+Ch] [ebp-88h] BYREF
  int v15; // [esp+60h] [ebp-34h]
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > children; // [esp+68h] [ebp-2Ch] BYREF
  Vector vecPos; // [esp+7Ch] [ebp-18h] BYREF
  Vector vecVelocity; // [esp+88h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+94h] [ebp+0h] BYREF

  if ( pEvent->pEntities[index == 0] == g_WorldEntity
    && this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_WORLD_STICK) )
  {
    CBreakableProp::HandleInteractionStick(this, index, pEvent);
  }
  if ( this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_FIRST_BREAK) )
  {
    CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&tr);
    GetRefEHandle = this->GetRefEHandle;
    *(float *)&tr.contents = (float)this->m_iHealth.m_Value;
    m_Index = GetRefEHandle(this)->m_Index;
    v6 = this->GetRefEHandle;
    *(_DWORD *)&tr.plane.type = m_Index;
    LODWORD(tr.plane.dist) = v6(this)->m_Index;
    m_pPhysicsObject = this->m_pPhysicsObject;
    tr.surface.name = nullptr;
    m_pPhysicsObject->GetVelocity(this: m_pPhysicsObject, a2: &vecPos, a3: nullptr);
    this->m_pPhysicsObject->GetPosition(this: this->m_pPhysicsObject, a2: &vecVelocity, a3: nullptr);
    tr.startpos = vecPos;
    tr.endpos = vecVelocity;
    CBaseEntity::TakeDamage(this, a2: (int)this, inputInfo: (const CTakeDamageInfo *)&tr);
  }
  else
  {
    if ( this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_FIRST_PAINT) )
    {
      this->m_pPhysicsObject->GetPosition(this: this->m_pPhysicsObject, a2: &vecPos, a3: nullptr);
      z = pEvent->preVelocity[0].z;
      *(_QWORD *)&vecVelocity.x = *(_QWORD *)&pEvent->preVelocity[0].x;
      vecVelocity.z = z;
      VectorNormalize(vec: &vecVelocity);
      *(float *)&children.m_Size = vecPos.y + (float)(vecVelocity.y * 64.0);
      *(float *)&children.m_Memory.m_nGrowSize = vecPos.x + (float)(vecVelocity.x * 64.0);
      *(float *)&children.m_pElements = vecPos.z + (float)(vecVelocity.z * 64.0);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: &vecPos,
        vecAbsEnd: (const Vector *)&children.m_Memory.m_nGrowSize,
        mask: 0x46004003u,
        ignore: this,
        collisionGroup: 0,
        ptr: (CGameTrace *)&tr.startpos.z);
      if ( v15 != 0 )
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          m_pPev -= (int)gpGlobals->pEdicts;
        v10 = (int)m_pPev % 3;
        if ( v10 != 0 )
        {
          v11 = v10 - 1;
          if ( v11 != 0 )
          {
            if ( v11 == 1 )
              UTIL_DecalTrace(pTrace: (CGameTrace *)&tr.startpos.z, decalName: "PaintSplatPink");
          }
          else
          {
            UTIL_DecalTrace(pTrace: (CGameTrace *)&tr.startpos.z, decalName: "PaintSplatGreen");
          }
        }
        else
        {
          UTIL_DecalTrace(pTrace: (CGameTrace *)&tr.startpos.z, decalName: "PaintSplatBlue");
        }
      }
    }
    if ( this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_NOTIFY_CHILDREN) )
    {
      memset(&children, 0, sizeof(children));
      GetAllChildren(pParent: this, list: &children);
      for ( i = 0; i < children.m_Size; ++i )
      {
        v13 = (void (__thiscall ***)(void *, int, int, gamevcollisionevent_t *))__RTDynamicCast(
                                                                                  inptr: children.m_Memory.m_pMemory[i],
                                                                                  VfDelta: 0,
                                                                                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                                                                                  TargetType: &IParentPropInteraction `RTTI Type Descriptor',
                                                                                  isReference: 0);
        if ( v13 != nullptr )
          (**v13)(a1: v13, a2: 1, a3: index, a4: pEvent);
      }
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&children);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBCA0
// Name: public: void CPhysicsProp::HandleAnyCollisionInteractions(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsProp::HandleAnyCollisionInteractions(
        CPhysicsProp *this@<ecx>,
        int a2@<edi>,
        int index,
        gamevcollisionevent_t *pEvent)
{
  float z; // edx
  Vector *v6; // ebx
  CWorld *v7; // edi
  float v8; // xmm0_4
  int v9; // eax
  IPhysicsObject *m_pPhysicsObject; // edi
  int v11; // eax
  float v12; // xmm2_4
  float v13; // xmm3_4
  double v14; // st7
  CGameTrace tr; // [esp+20h] [ebp-A0h] BYREF
  QAngle vecBoneAngles; // [esp+74h] [ebp-4Ch] BYREF
  QAngle angImpaleForward; // [esp+80h] [ebp-40h] BYREF
  Vector vecPos; // [esp+8Ch] [ebp-34h] BYREF
  Vector forward; // [esp+98h] [ebp-28h] BYREF
  int iBone; // [esp+A4h] [ebp-1Ch]
  Vector vecImpalePos; // [esp+A8h] [ebp-18h] BYREF
  Vector vecVelocity; // [esp+B4h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+C0h] [ebp+0h] BYREF
  CAI_BaseNPC *pNPC; // [esp+C8h] [ebp+8h]

  if ( this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_PHYSGUN_FIRST_IMPALE) )
  {
    z = pEvent->preVelocity[index].z;
    v6 = &pEvent->preVelocity[index];
    *(_QWORD *)&vecImpalePos.x = *(_QWORD *)&v6->x;
    vecImpalePos.z = z;
    if ( CPhysicsProp::GetPropDataAngles(this, pKeyName: "impale_forward", vecAngles: &angImpaleForward) )
    {
      AngleVectors(angles: &angImpaleForward, forward: &vecVelocity);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      VectorRotate(in1: &vecVelocity.x, in2: &this->m_rgflCoordinateFrame, out: &forward.x);
    }
    else
    {
      this->GetVectors(this, a2: &forward, a3: nullptr, a4: nullptr);
    }
    if ( (float)((float)((float)(forward.y * vecImpalePos.y) + (float)(vecImpalePos.x * forward.x))
               + (float)(forward.z * vecImpalePos.z)) >= 1000.0 )
    {
      v7 = (CWorld *)pEvent->pEntities[index == 0];
      if ( v7 == g_WorldEntity )
      {
        if ( index != 0 )
          v8 = -1.0;
        else
          v8 = 1.0;
        pEvent->pInternalData->GetSurfaceNormal(this: pEvent->pInternalData, a2: &vecVelocity);
        if ( (float)((float)((float)((float)(vecVelocity.y * forward.y) + (float)(vecVelocity.x * forward.x))
                           + (float)(vecVelocity.z * forward.z))
                   * v8) >= 0.707106781187 )
          CBreakableProp::HandleInteractionStick(this, index, pEvent);
      }
      else if ( v7->MyNPCPointer(this: v7) != nullptr )
      {
        v9 = (int)v7->MyNPCPointer(this: v7);
        m_pPhysicsObject = this->m_pPhysicsObject;
        pNPC = (CAI_BaseNPC *)v9;
        v11 = ((int (__thiscall *)(CPhysicsProp *, int))this->HasPhysicsAttacker)(a1: this, a2: 1103626240);
        if ( v11 == 0 || pNPC->IRelationType(this: pNPC, a2: (CBaseEntity *)v11) != D_LI )
        {
          ((void (__thiscall *)(IPhysicsObject *, Vector *, _DWORD, int))m_pPhysicsObject->GetPosition)(
            a1: m_pPhysicsObject,
            a2: &vecPos,
            a3: 0,
            a4: a2);
          v12 = v6->z * 1.5;
          v13 = vecPos.x + (float)(v6->x * 1.5);
          vecVelocity.y = vecPos.y + (float)(v6->y * 1.5);
          vecVelocity.x = v13;
          vecVelocity.z = vecPos.z + v12;
          UTIL_TraceLine(
            a1: &savedregs,
            a2: (int)this,
            vecAbsStart: &vecPos,
            vecAbsEnd: &vecVelocity,
            mask: 0x46004003u,
            ignore: this,
            collisionGroup: 0,
            ptr: &tr);
          vecImpalePos = tr.endpos;
          iBone = -1;
          if ( tr.hitbox != 0 )
          {
            iBone = CBaseAnimating::GetHitboxBone(this: pNPC, hitboxIndex: tr.hitbox);
            CBaseAnimating::GetBonePosition(this: pNPC, iBone, origin: &vecVelocity, angles: &vecBoneAngles);
            this->Teleport(this, a2: &vecVelocity, a3: nullptr, a4: nullptr, a5: true);
            vecImpalePos = vecVelocity;
          }
          pEvent->pInternalData->GetContactPoint(this: pEvent->pInternalData, a2: &vecImpalePos);
          if ( CreateServerRagdollAttached(
                 pAnimating: pNPC,
                 vecForce: &vec3_origin,
                 forceBone: -1,
                 collisionGroup: 3,
                 pAttached: m_pPhysicsObject,
                 pParentEntity: this,
                 boneAttach: 0,
                 originAttached: &vecImpalePos,
                 parentBoneAttach: iBone,
                 boneOrigin: &vec3_origin) != nullptr )
          {
            v14 = ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: m_pPhysicsObject);
            vecVelocity.x = v6->x * v14;
            vecVelocity.y = v6->y * v14;
            vecVelocity.z = v14 * v6->z;
            PhysCallbackImpulse(
              pPhysicsObject: m_pPhysicsObject,
              vecCenterForce: &vecVelocity,
              vecCenterTorque: &vec3_origin);
            UTIL_Remove(oldObj: pNPC);
            CBaseEntity::AddSpawnFlags(this, nFlags: 2048);
          }
        }
      }
    }
    else
    {
      CBreakableProp::CheckRemoveRagdolls(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC200
// Name: public: virtual void CDynamicProp::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicProp::Spawn(CDynamicProp *this)
{
  double v2; // st7
  const char *pszValue; // eax
  unsigned int m_Index; // ecx
  bool v5; // bl
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx
  float thinkTime; // [esp+8h] [ebp-14h]

  if ( this != nullptr
    && (this->m_iClassname.pszValue == "dynamic_prop"
     || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "dynamic_prop") != 0) )
  {
    CBaseEntity::SetClassname(this, className: "prop_dynamic");
  }
  if ( this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_NONE
    && (this->m_iClassname.pszValue == "prop_dynamic"
     || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "prop_dynamic") != 0) )
  {
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_OBB);
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  }
  CBreakableProp::Spawn(this);
  if ( (this->m_iEFlags & 1) == 0 )
  {
    if ( this->m_iClassname.pszValue == "dynamic_prop"
      || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "dynamic_prop") != 0
      || this->m_iClassname.pszValue == "prop_dynamic_override"
      || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "prop_dynamic_override") != 0 )
    {
      CBaseEntity::SetClassname(this, className: "prop_dynamic");
    }
    CBaseEntity::AddFlag(this, flags: 0x80000);
    if ( this->m_bRandomAnimator || this->m_iszDefaultAnim.pszValue != nullptr )
    {
      CBaseEntity::RemoveFlag(this, flagsToRemove: 0x80000);
      if ( this->m_bRandomAnimator )
      {
        CBaseEntity::ThinkSet(
          this,
          func: (void (__thiscall *)(CBaseEntity *))CDynamicProp::AnimThink,
          thinkTime: 0.0,
          szContext: nullptr);
        v2 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
               a1: random,
               a2: LODWORD(this->m_flMinRandAnimTime),
               a3: LODWORD(this->m_flMaxRandAnimTime))
           + gpGlobals->curtime;
        this->m_flNextRandAnim = v2;
        thinkTime = v2 + gpGlobals->curtime + 0.1;
        CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
      }
      else
      {
        pszValue = this->m_iszDefaultAnim.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        CDynamicProp::PropSetAnim(this, szAnim: pszValue);
      }
    }
    this->CreateVPhysics(this);
    if ( this->m_BoneFollowerManager.m_iNumBones != 0 )
    {
      m_Index = this->m_pParent.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        WatchPositionChanges(pWatcher: this, pMovingEntity: this);
      }
    }
    if ( this->m_bStartDisabled )
      CBaseEntity::AddEffects(this, nEffects: 32);
    if ( !this->m_bBlockLOSSetByPropData )
      CBaseProp::CalculateBlockLOS(this);
    v5 = (this->m_spawnflags.m_Value & 0x40) != 0;
    if ( this->m_bUseHitboxesForRenderBox.m_Value != v5 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x63Cu);
      }
      this->m_bUseHitboxesForRenderBox.m_Value = v5;
    }
    if ( (this->m_spawnflags.m_Value & 0x100) != 0 )
      CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    if ( this->m_bAnimateEveryFrame && !this->m_bAnimatedEveryTick.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bAnimatedEveryTick.m_Value = true;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x1F6u);
        this->m_bAnimatedEveryTick.m_Value = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC520
// Name: public: virtual void COrnamentProp::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COrnamentProp::Spawn(COrnamentProp *this)
{
  CDynamicProp::Spawn(this);
  this->SetOwnerEntity(this, a2: nullptr);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x101ECB30
// Name: public: virtual void CPhysicsProp::OnNavMeshLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::OnNavMeshLoaded(CPhysicsProp *this)
{
  if ( LOBYTE(this->m_Collision.m_usSolidFlags.m_Value) == 0 )
    CBaseEntity::ThinkSet(
      this: (CPhysicsProp *)((char *)this - 1512),
      func: (void (__thiscall *)(CBaseEntity *))CPhysicsProp::NavThink,
      thinkTime: gpGlobals->curtime,
      szContext: "NavContext");
}

//------------------------------------------------------------------------------
// Address: 0x101ECB60
// Name: public: virtual void CPhysicsProp::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsProp::VPhysicsCollision(CPhysicsProp *this, float index, BOOL pEvent)
{
  int v3; // ebx
  gamevcollisionevent_t *v4; // edi
  float m_flForceToEnableMotion; // xmm0_4
  float v7; // ecx
  int v8; // eax
  string_t (__thiscall *GetPhysicsDamageTable)(IBreakableWithPropData *); // edx
  string_t *v10; // eax
  double v11; // st7
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  double v14; // st7
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  const CTakeDamageInfo *v18; // eax
  CBaseEntity *v19; // edi
  int v20; // ebx
  int v21; // eax
  CTakeDamageInfo v22; // [esp+34h] [ebp-80h] BYREF
  Vector damagePos; // [esp+90h] [ebp-24h] BYREF
  Vector damageForce; // [esp+9Ch] [ebp-18h] BYREF
  float v25; // [esp+A8h] [ebp-Ch]
  int damageType; // [esp+ACh] [ebp-8h] BYREF
  CBaseEntity *pHitEntity; // [esp+B0h] [ebp-4h]

  v3 = LODWORD(index);
  v4 = (gamevcollisionevent_t *)pEvent;
  CBaseEntity::VPhysicsCollision(this, index: (surfacedata_t *)LODWORD(index), (CBaseEntity *)pEvent);
  m_flForceToEnableMotion = this->m_flForceToEnableMotion;
  v7 = *(float *)&v4->pObjects[v3 == 0];
  pEvent = v3 == 0;
  index = v7;
  if ( m_flForceToEnableMotion != 0.0 )
  {
    v8 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v7) + 68))(a1: COERCE_FLOAT(LODWORD(v7)));
    if ( (v8 == 0
       || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 336))(a1: v8) == 0
       || (this->m_spawnflags.m_Value & 0x400) == 0)
      && ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(index) + 116))(a1: LODWORD(index))
       * v4->collisionSpeed >= this->m_flForceToEnableMotion )
    {
      CPhysicsProp::ComputeEnablingImpulse(this, index: v3, pEvent: v4);
      CPhysicsProp::EnableMotion(this);
      this->m_flForceToEnableMotion = 0.0;
    }
  }
  if ( this->m_bFirstCollisionAfterLaunch )
    CBreakableProp::HandleFirstCollisionInteractions(this, index: v3, pEvent: v4);
  if ( ((int (__thiscall *)(CPhysicsProp *, int))this->HasPhysicsAttacker)(a1: this, a2: 0x40000000) != 0 )
    CPhysicsProp::HandleAnyCollisionInteractions(this, a2: (int)v4, index: v3, pEvent: v4);
  if ( (this->m_spawnflags.m_Value & 2) == 0 )
  {
    GetPhysicsDamageTable = this->GetPhysicsDamageTable;
    damageType = 0;
    v10 = (string_t *)((int (__thiscall *)(IBreakableWithPropData *, float *))GetPhysicsDamageTable)(
                        a1: &this->IBreakableWithPropData,
                        a2: &index);
    v11 = CalculateDefaultPhysicsDamage(
            index: v3,
            pEvent: v4,
            energyScale: this->m_impactEnergyScale,
            allowStaticDamage: true,
            &damageType,
            iszDamageTableName: (string_t)v10->pszValue,
            bDamageFromHeldObjects: false);
    index = v11;
    if ( v11 > 0.0 )
    {
      if ( this->m_bFirstCollisionAfterLaunch && !this->m_bThrownByPlayer )
        index = index * 10.0;
      pHitEntity = v4->pEntities[pEvent];
      if ( pHitEntity == nullptr )
      {
        if ( gpGlobals->pEdicts != nullptr
          && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0
          && (m_pUnk = pEdicts->m_pUnk) != nullptr )
        {
          pHitEntity = m_pUnk->GetBaseEntity(this: m_pUnk);
        }
        else
        {
          pHitEntity = nullptr;
        }
      }
      v4->pInternalData->GetContactPoint(this: v4->pInternalData, a2: &damagePos);
      v14 = ((double (__thiscall *)(IPhysicsObject *))v4->pObjects[v3]->GetMass)(a1: v4->pObjects[v3]);
      v25 = v14;
      v15 = v4->postVelocity[v3].x * v25;
      damageForce.y = v4->postVelocity[v3].y * v14;
      damageForce.x = v15;
      damageForce.z = v14 * v4->postVelocity[v3].z;
      if ( vec3_origin.x == v15 && vec3_origin.y == damageForce.y && vec3_origin.z == damageForce.z )
      {
        v25 = v4->pObjects[pEvent]->GetMass(this: v4->pObjects[pEvent]);
        v16 = v4->postVelocity[pEvent].y * v25;
        v17 = v4->postVelocity[pEvent].z * v25;
        damageForce.x = v4->postVelocity[pEvent].x * v25;
        damageForce.y = v16;
        damageForce.z = v17;
      }
      v18 = CTakeDamageInfo::CTakeDamageInfo(
              this: &v22,
              pInflictor: pHitEntity,
              pAttacker: pHitEntity,
              &damageForce,
              damagePosition: &damagePos,
              flDamage: index,
              bitsDamageType: damageType,
              iKillType: 0,
              reportedPosition: nullptr,
              iObjectsPenetrated: 0);
      PhysCallbackDamage(pEntity: this, info: v18, event: v4, hurtIndex: v3);
    }
  }
  if ( this->m_bThrownByPlayer || this->m_bFirstCollisionAfterLaunch )
  {
    v19 = v4->pEntities[pEvent];
    if ( v19 != nullptr && v19->MyNPCPointer(this: v19) != nullptr )
    {
      v20 = g_interactionHitByPlayerThrownPhysObj;
      v21 = (int)v19->MyNPCPointer(this: v19);
      if ( v20 > 0 )
        (*(void (__thiscall **)(int, int, CPhysicsProp *, _DWORD))(*(_DWORD *)v21 + 988))(
          a1: v21,
          a2: v20,
          a3: this,
          a4: 0);
      this->m_bThrownByPlayer = false;
    }
    if ( this->m_bFirstCollisionAfterLaunch )
    {
      this->m_bFirstCollisionAfterLaunch = false;
      CBaseEntity::RegisterThinkContext(this, szContext: "PROP_CLEARFLAGS");
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CPhysicsProp::ClearFlagsThink,
        thinkTime: gpGlobals->curtime,
        szContext: "PROP_CLEARFLAGS");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECEA0
// Name: int PropBreakablePrecacheAll(struct string_t)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PropBreakablePrecacheAll(string_t modelName)
{
  unsigned __int16 v1; // ax
  int v3; // edi
  int m_Size; // esi
  int v5; // ebx
  CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int> > list; // [esp+10h] [ebp-20h] BYREF
  CBreakModelsPrecached::breakable_precache_t search; // [esp+24h] [ebp-Ch] BYREF
  int modelIndex; // [esp+2Ch] [ebp-4h]

  search.iszModelName = modelName;
  v1 = CUtlRBTree<CBreakModelsPrecached::breakable_precache_t,unsigned short,bool (__cdecl *)(CBreakModelsPrecached::breakable_precache_t const &,CBreakModelsPrecached::breakable_precache_t const &),CUtlMemory<UtlRBTreeNode_t<CBreakModelsPrecached::breakable_precache_t,unsigned short>,unsigned short>>::Find(
         this: &g_BreakModelsPrecached.m_modelList,
         &search);
  if ( v1 != 0xFFFF )
    return g_BreakModelsPrecached.m_modelList.m_Elements.m_pMemory[v1].m_Data.iBreakableCount;
  v3 = 0;
  if ( modelName.pszValue != nullptr )
  {
    modelIndex = CBaseEntity::PrecacheModel(a1: nullptr, name: modelName.pszValue, bPreload: true);
    memset(&list, 0, sizeof(list));
    BreakModelList(&list, modelindex: modelIndex, defBurstScale: 0.0, defCollisionGroup: 0);
    m_Size = list.m_Size;
    search.iszModelName = modelName;
    search.iBreakableCount = list.m_Size;
    CUtlRBTree<CBreakModelsPrecached::breakable_precache_t,unsigned short,bool (__cdecl *)(CBreakModelsPrecached::breakable_precache_t const &,CBreakModelsPrecached::breakable_precache_t const &),CUtlMemory<UtlRBTreeNode_t<CBreakModelsPrecached::breakable_precache_t,unsigned short>,unsigned short>>::Insert(
      this: &g_BreakModelsPrecached.m_modelList,
      insert: &search);
    if ( m_Size > 0 )
    {
      v5 = 0;
      do
      {
        AllocPooledString(pszValue: (const char *)&search.iBreakableCount);
        if ( modelIndex > 0 )
          PropBreakablePrecacheAll(modelName: (string_t)search.iBreakableCount);
        else
          --m_Size;
        ++v3;
        v5 += 1068;
      }
      while ( v3 < m_Size );
    }
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
    return m_Size;
  }
  else
  {
    _Msg(a1: "Trying to precache breakable prop, but has no model name\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECFA0
// Name: public: virtual void CBasePropDoor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePropDoor::Spawn(CBasePropDoor *this@<ecx>, int a2@<ebp>)
{
  void (__thiscall *Precache)(CBaseEntity *); // edx
  const char *DebugName; // eax
  unsigned int m_Index; // eax
  double x; // [esp+0h] [ebp-1Ch]
  double y; // [esp+8h] [ebp-14h]
  double z; // [esp+10h] [ebp-Ch]

  CDynamicProp::Spawn(this);
  CBaseEntity::SetGlobalFadeScale(this, flFadeScale: 0.0);
  Precache = this->Precache;
  this->m_flDefaultFadeScale = 0.0;
  Precache(this);
  this->DoorTeleportToSpawnPosition(this);
  if ( (this->m_spawnflags.m_Value & 0x800) != 0 )
    this->m_bLocked = true;
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_flSpeed == 0.0 )
    this->m_flSpeed = 100.0;
  CBaseEntity::RemoveFlag(this, flagsToRemove: 0x80000);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 3);
  CBaseAnimating::SetBodygroup(this, iGroup: 1, iValue: this->m_nHardwareType);
  if ( this->m_nHardwareType == 0 && (this->m_spawnflags.m_Value & 0x800) == 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    z = this->m_vecAbsOrigin.z;
    y = this->m_vecAbsOrigin.y;
    x = this->m_vecAbsOrigin.x;
    DebugName = CBaseEntity::GetDebugName(this);
    _DevWarning(
      a1: 1,
      a2: "Unlocked prop_door '%s' at (%.0f %.0f %.0f) has no hardware. All openable doors must have hardware!\n",
      DebugName,
      x,
      y,
      z);
  }
  if ( !this->m_bBlockLOSSetByPropData )
    CBaseProp::CalculateBlockLOS(this);
  this->m_hBlocker.m_Index = -1;
  m_Index = this->m_hBlocker.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    this->m_bFirstBlocked = false;
  }
  this->CalcDoorSounds(this);
}

//------------------------------------------------------------------------------
// Address: 0x101ED170
// Name: private: void CBasePropDoor::DoorOpen(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::DoorOpen(CBasePropDoor *this, CBaseEntity *pOpenAwayFrom)
{
  CBasePropDoor::DoorState_t m_eDoorState; // eax
  const char *pszValue; // eax
  unsigned int m_Index; // eax
  CBaseEntity *v6; // eax
  const Vector *AbsOrigin; // eax
  void (__thiscall *BeginOpening)(CBasePropDoor *, CBaseEntity *); // edx
  int m_Size; // ebx
  int i; // edi
  unsigned int v11; // eax
  CBasePropDoor *m_pEntity; // ecx

  m_eDoorState = this->m_eDoorState;
  if ( m_eDoorState != DOOR_STATE_OPEN && m_eDoorState != DOOR_STATE_OPENING )
  {
    CBasePropDoor::UpdateAreaPortals(this, isOpen: true);
    if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
    {
      pszValue = this->m_SoundMoving.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      CBaseEntity::EmitSound(this, soundname: pszValue, soundtime: 0.0, duration: nullptr);
      m_Index = this->m_hActivator.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        v6 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
        if ( v6->IsPlayer(this: v6) && (this->m_spawnflags.m_Value & 0x4000) == 0 )
        {
          AbsOrigin = CBaseEntity::GetAbsOrigin(this);
          CSoundEnt::InsertSound(
            iType: 4,
            vecOrigin: AbsOrigin,
            iVolume: 512,
            flDuration: 0.5,
            pOwner: this,
            soundChannelIndex: 0,
            pSoundTarget: nullptr);
        }
      }
    }
    BeginOpening = this->BeginOpening;
    this->m_eDoorState = DOOR_STATE_OPENING;
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CBasePropDoor::DoorOpenMoveDone;
    BeginOpening(this, a2: pOpenAwayFrom);
    COutputEvent::FireOutput(this: &this->m_OnOpen, pActivator: this, pCaller: this, fDelay: 0.0);
    m_Size = this->m_hDoorList.m_Size;
    if ( m_Size > 0 )
    {
      for ( i = 0; i < m_Size; ++i )
      {
        v11 = this->m_hDoorList.m_Memory.m_pMemory[i].m_Index;
        if ( v11 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber == HIWORD(v11) )
        {
          m_pEntity = (CBasePropDoor *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
          if ( m_pEntity != nullptr )
          {
            m_pEntity->m_hActivator.m_Index = this->m_hActivator.m_Index;
            CBasePropDoor::DoorOpen(this: m_pEntity, pOpenAwayFrom);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED2F0
// Name: private: void CBasePropDoor::OnStartBlocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::OnStartBlocked(CBasePropDoor *this, CBaseEntity *pOther)
{
  const char *pszValue; // eax
  CAI_BaseNPC *(__thiscall *MyNPCPointer)(CBaseEntity *); // eax
  COutputEvent *p_m_OnBlockedClosing; // ecx
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  vgui::TreeView *v8; // eax

  if ( !this->m_bFirstBlocked )
    this->DoorStop(this);
  CBasePropDoor::SetDoorBlocker(this, pBlocker: pOther);
  if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
  {
    pszValue = this->m_SoundMoving.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CBaseEntity::StopSound(this, soundname: pszValue);
  }
  MyNPCPointer = pOther->MyNPCPointer;
  if ( this->m_eDoorState == DOOR_STATE_CLOSING )
  {
    if ( (int)MyNPCPointer(this: pOther) != 0 )
      CBasePropDoor::DoorOpen(this, pOpenAwayFrom: pOther);
    p_m_OnBlockedClosing = &this->m_OnBlockedClosing;
  }
  else
  {
    if ( (int)MyNPCPointer(this: pOther) != 0 )
      CBasePropDoor::DoorClose(this);
    m_Index = this->m_hActivator.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v8 = (vgui::TreeView *)__RTDynamicCast(
                             inptr: m_pEntity,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CAI_BaseNPC `RTTI Type Descriptor',
                             isReference: 0);
    if ( v8 != nullptr )
      CNavMesh::SaveCustomData(this: v8, itemIndex: (int)this);
    p_m_OnBlockedClosing = &this->m_OnBlockedOpening;
  }
  COutputEvent::FireOutput(this: p_m_OnBlockedClosing, pActivator: pOther, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101ED3E0
// Name: public: virtual void CPropDoorRotating::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotating::Spawn(CPropDoorRotating *this)
{
  CBasePropDoor *v2; // ecx
  __int64 v3; // xmm0_8
  float z; // eax
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  this->m_angRotationClosed = this->m_angRotation.m_Value;
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 1.0;
  CPropDoorRotating::CalcOpenAngles(this);
  CBasePropDoor::Spawn(this: v2, a2: (int)&savedregs);
  if ( CPropDoorRotating::IsHingeOnLeft(this) )
  {
    v3 = *(_QWORD *)&this->m_angRotationOpenForward.x;
    z = this->m_angRotationOpenForward.z;
    this->m_angRotationOpenForward.x = this->m_angRotationOpenBack.x;
    this->m_angRotationOpenForward.y = this->m_angRotationOpenBack.y;
    this->m_angRotationOpenForward.z = this->m_angRotationOpenBack.z;
    *(_QWORD *)&this->m_angRotationOpenBack.x = v3;
    this->m_angRotationOpenBack.z = z;
  }
  CPropDoorRotating::CalculateDoorVolume(
    this,
    closedAngles: this->m_angRotation.m_Value,
    openAngles: this->m_angRotationOpenForward,
    destMins: &this->m_vecForwardBoundsMin,
    destMaxs: &this->m_vecForwardBoundsMax);
  CPropDoorRotating::CalculateDoorVolume(
    this,
    closedAngles: this->m_angRotation.m_Value,
    openAngles: this->m_angRotationOpenBack,
    destMins: &this->m_vecBackBoundsMin,
    destMaxs: &this->m_vecBackBoundsMax);
  VisibilityMonitor_AddEntity(
    pEntity: this,
    flMinDist: 600.0,
    pfnCallback: nullptr,
    pfnEvaluator: (bool (__cdecl *)(CBaseEntity *, CBasePlayer *))DoorUnlockedFilter);
}

//------------------------------------------------------------------------------
// Address: 0x101ED560
// Name: public: void CPropDoorRotatingBreakable::PrecacheBreakables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotatingBreakable::PrecacheBreakables(CPropDoorRotatingBreakable *this)
{
  KeyValues *v2; // eax
  const struct model_t *Model; // esi
  const char *v4; // edi
  const char *v5; // eax
  KeyValues *Key; // esi
  char *v7; // eax
  KeyValues *v8; // edi
  int v9; // esi
  char *v10; // eax
  const char *i; // eax
  string_t v12; // eax
  char *v13; // eax
  int m_Value; // [esp-8h] [ebp-78h]
  CFmtStrN<80> str; // [esp+Ch] [ebp-64h] BYREF
  char pszValue[4]; // [esp+68h] [ebp-8h] BYREF
  KeyValues *modelKeyValues; // [esp+6Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    modelKeyValues = KeyValues::KeyValues(this: v2, setName: locale);
  else
    modelKeyValues = nullptr;
  Model = CBaseEntity::GetModel(this);
  v4 = modelinfo->GetModelName(this: modelinfo, a2: Model);
  v5 = modelinfo->GetModelKeyValueText(this: modelinfo, a2: Model);
  if ( KeyValues::LoadFromBuffer(
         this: modelKeyValues,
         resourceName: v4,
         pBuffer: v5,
         pFileSystem: nullptr,
         pPathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    Key = KeyValues::FindKey(this: modelKeyValues, keyName: "door_options", bCreate: false);
    if ( Key != nullptr )
    {
      m_Value = this->m_nSkin.m_Value;
      str.__vftable = (CFmtStrN<80>_vtbl *)&CFmtStrN<80>::`vftable';
      *(_WORD *)&str.m_bQuietTruncation = 1;
      str.m_nLength = 0;
      v7 = CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "skin%d", m_Value);
      v8 = KeyValues::FindKey(this: Key, keyName: v7, bCreate: false);
      if ( v8 != nullptr || (v8 = KeyValues::FindKey(this: Key, keyName: "defaults", bCreate: false)) != nullptr )
      {
        v9 = 1;
        v10 = CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "damage%d", 1);
        for ( i = KeyValues::GetString(this: v8, keyName: v10, defaultValue: nullptr);
              i != nullptr;
              i = KeyValues::GetString(this: v8, keyName: v13, defaultValue: nullptr) )
        {
          ++v9;
          CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "models/%s.mdl", i);
          V_FixSlashes(pname: str.m_szBuf, separator: 47);
          v12.pszValue = AllocPooledString(pszValue).pszValue;
          PropBreakablePrecacheAll(modelName: *(string_t *)v12.pszValue);
          v13 = CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "damage%d", v9);
        }
      }
    }
    else
    {
      DevMsg(a1: "Breakable door %s has no door_options\n", v4);
    }
  }
  else
  {
    DevMsg(a1: "Breakable door %s has no KeyValues\n", v4);
  }
  KeyValues::deleteThis(this: modelKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x101ED6F0
// Name: public: virtual void CPropDoorRotatingBreakable::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropDoorRotatingBreakable::Spawn(CPropDoorRotatingBreakable *this)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_damageStates; // esi
  KeyValues *v3; // eax
  IVModelInfo_vtbl *v4; // edi
  IVModelInfo_vtbl *v5; // ebx
  int v6; // eax
  CBaseEntity *v7; // edi
  model_t *v8; // eax
  const char *v9; // eax
  KeyValues *Key; // ebx
  char *v11; // eax
  int v12; // ebx
  char *v13; // eax
  char *i; // edi
  string_t v15; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v18; // ecx
  int v19; // eax
  vgui::TreeNode **v20; // edi
  char *v21; // eax
  int v22; // [esp-14h] [ebp-90h]
  const char *Model; // [esp-10h] [ebp-8Ch]
  edict_t *m_pPev; // [esp-8h] [ebp-84h]
  CFmtStrN<80> str; // [esp+Ch] [ebp-70h] BYREF
  char pszValue[4]; // [esp+68h] [ebp-14h] BYREF
  const char *v27; // [esp+6Ch] [ebp-10h]
  KeyValues *modelKeyValues; // [esp+70h] [ebp-Ch]
  KeyValues *skin; // [esp+74h] [ebp-8h]
  CBaseEntity *v30; // [esp+78h] [ebp-4h]

  v30 = this;
  this->m_isAbleToCloseAreaPortals = true;
  CPropDoorRotating::Spawn(this);
  CPropDoorRotatingBreakable::PrecacheBreakables(this);
  p_m_damageStates = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_damageStates;
  this->m_damageStates.m_Size = 0;
  this->m_currentDamageState = -1;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    modelKeyValues = KeyValues::KeyValues(this: v3, setName: locale);
  else
    modelKeyValues = nullptr;
  v4 = modelinfo->__vftable;
  v5 = modelinfo->__vftable;
  Model = (const char *)CBaseEntity::GetModel(this: v30);
  v6 = ((int (__thiscall *)(IVModelInfo *))v4->GetModelKeyValueText)(a1: modelinfo);
  v7 = v30;
  v22 = v6;
  v8 = CBaseEntity::GetModel(this: v30);
  v9 = (const char *)((int (__thiscall *)(IVModelInfo *, model_t *, int))v5->GetModelName)(
                       a1: modelinfo,
                       a2: v8,
                       a3: v22);
  if ( KeyValues::LoadFromBuffer(
         this: modelKeyValues,
         resourceName: v9,
         pBuffer: Model,
         pFileSystem: nullptr,
         pPathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    Key = KeyValues::FindKey(this: modelKeyValues, keyName: "door_options", bCreate: false);
    if ( Key != nullptr )
    {
      m_pPev = v30[1].m_Network.m_pPev;
      str.__vftable = (CFmtStrN<80>_vtbl *)&CFmtStrN<80>::`vftable';
      *(_WORD *)&str.m_bQuietTruncation = 1;
      str.m_nLength = 0;
      v11 = CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "skin%d", m_pPev);
      skin = KeyValues::FindKey(this: Key, keyName: v11, bCreate: false);
      if ( skin != nullptr || (skin = KeyValues::FindKey(this: Key, keyName: "defaults", bCreate: false)) != nullptr )
      {
        v12 = 1;
        v13 = CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "damage%d", 1);
        for ( i = (char *)KeyValues::GetString(this: skin, keyName: v13, defaultValue: nullptr);
              i != nullptr;
              i = (char *)KeyValues::GetString(this: skin, keyName: v21, defaultValue: nullptr) )
        {
          ++v12;
          CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "models/%s.mdl", i);
          V_FixSlashes(pname: str.m_szBuf, separator: 47);
          CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))i, name: str.m_szBuf, bPreload: true);
          v15.pszValue = AllocPooledString(pszValue).pszValue;
          m_pMemory = p_m_damageStates[1].m_pMemory;
          v27 = v15.pszValue;
          m_nAllocationCount = p_m_damageStates->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(this: p_m_damageStates, num: (int)m_pMemory - m_nAllocationCount + 1);
          ++p_m_damageStates[1].m_pMemory;
          v18 = p_m_damageStates->m_pMemory;
          v19 = (char *)p_m_damageStates[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_damageStates[1].m_nAllocationCount = (int)p_m_damageStates->m_pMemory;
          if ( v19 > 0 )
            _V_memmove(dest: &v18[(_DWORD)m_pMemory + 1], src: &v18[(_DWORD)m_pMemory], count: 4 * v19);
          v20 = &p_m_damageStates->m_pMemory[(_DWORD)m_pMemory];
          if ( v20 != nullptr )
            *v20 = *(vgui::TreeNode **)v27;
          v21 = CFmtStrN<80>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "damage%d", v12);
        }
        v7 = v30;
      }
    }
  }
  KeyValues::deleteThis(this: modelKeyValues);
  LOBYTE(v7[2].m_rgflCoordinateFrame.m_flMatVal[1][2]) = (v7->m_spawnflags.m_Value & 0x80000) != 0;
  v7[2].m_rgflCoordinateFrame.m_flMatVal[1][1] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101ED950
// Name: public: virtual void CBreakableProp::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBreakableProp::Precache(CBreakableProp *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  string_t *v3; // eax
  int v4; // eax
  bool v5; // zf
  const char *pszValue; // eax
  _BYTE v7[4]; // [esp+4h] [ebp-4h] BYREF

  v3 = (string_t *)((int (__thiscall *)(CBreakableProp *, _BYTE *))this->GetModelName)(a1: this, a2: v7);
  v4 = PropBreakablePrecacheAll(modelName: (string_t)v3->pszValue);
  v5 = this->m_iszPuntSound.pszValue == nullptr;
  this->m_iNumBreakableChunks = v4;
  if ( !v5 )
  {
    pszValue = this->m_iszPuntSound.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CBaseEntity::PrecacheScriptSound(soundname: pszValue);
  }
  CBaseProp::Precache(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101ED9B0
// Name: public: virtual void CPhysicsProp::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysicsProp::Precache(CPhysicsProp *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  const char *v4; // eax
  string_t *v5; // eax
  int v6; // eax
  bool v7; // zf
  const char *pszValue; // eax
  _BYTE v9[4]; // [esp+20h] [ebp-4h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( *(_DWORD *)((int (__thiscall *)(CPhysicsProp *, _BYTE *))this->GetModelName)(a1: this, a2: v9) != 0 )
  {
    v4 = *(const char **)((int (__thiscall *)(CPhysicsProp *, _BYTE *))this->GetModelName)(a1: this, a2: v9);
    if ( v4 == nullptr )
      v4 = locale;
    CBaseEntity::PrecacheModel(a1: a2, name: v4, bPreload: true);
    v5 = (string_t *)((int (__thiscall *)(CPhysicsProp *, _BYTE *))this->GetModelName)(a1: this, a2: v9);
    v6 = PropBreakablePrecacheAll(modelName: (string_t)v5->pszValue);
    v7 = this->m_iszPuntSound.pszValue == nullptr;
    this->m_iNumBreakableChunks = v6;
    if ( !v7 )
    {
      pszValue = this->m_iszPuntSound.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      CBaseEntity::PrecacheScriptSound(soundname: pszValue);
    }
    CBaseProp::Precache(this, a2);
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v3 = this->m_iClassname.pszValue;
    if ( v3 == nullptr )
      v3 = locale;
    _Msg(
      a1: "%s at (%.3f, %.3f, %.3f) has no model name!\n",
      v3,
      this->m_vecAbsOrigin.x,
      this->m_vecAbsOrigin.y,
      this->m_vecAbsOrigin.z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDAD0
// Name: public: virtual void CBasePropDoor::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePropDoor::Precache(CBasePropDoor *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  string_t *v3; // eax
  int v4; // eax
  bool v5; // zf
  const char *pszValue; // eax
  _BYTE v7[4]; // [esp+4h] [ebp-4h] BYREF

  v3 = (string_t *)((int (__thiscall *)(CBasePropDoor *, _BYTE *))this->GetModelName)(a1: this, a2: v7);
  v4 = PropBreakablePrecacheAll(modelName: (string_t)v3->pszValue);
  v5 = this->m_iszPuntSound.pszValue == nullptr;
  this->m_iNumBreakableChunks = v4;
  if ( !v5 )
  {
    pszValue = this->m_iszPuntSound.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CBaseEntity::PrecacheScriptSound(soundname: pszValue);
  }
  CBaseProp::Precache(this, a2);
  if ( byte_10633000 == 0 )
  {
    ACT_DOOR_OPEN = ActivityList_RegisterPrivateActivity(pszActivityName: "ACT_DOOR_OPEN");
    ACT_DOOR_LOCKED = ActivityList_RegisterPrivateActivity(pszActivityName: "ACT_DOOR_LOCKED");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDB50
// Name: private: void CBasePropDoor::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::InputToggle(CBasePropDoor *this, inputdata_t *inputdata)
{
  CBasePropDoor::DoorState_t m_eDoorState; // eax

  m_eDoorState = this->m_eDoorState;
  if ( m_eDoorState != DOOR_STATE_CLOSED )
  {
    if ( m_eDoorState == DOOR_STATE_OPEN )
      CBasePropDoor::DoorClose(this);
  }
  else if ( !this->IsDoorLocked(this) )
  {
    CBasePropDoor::DoorOpen(this, pOpenAwayFrom: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDB90
// Name: private: bool CBasePropDoor::DoorActivate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePropDoor::DoorActivate(CBasePropDoor *this)
{
  unsigned int m_Index; // ecx

  if ( this->m_eDoorState == DOOR_STATE_OPEN && this->DoorCanClose(this, a2: false) )
  {
    CBasePropDoor::DoorClose(this);
    return 1;
  }
  else
  {
    m_Index = this->m_hActivator.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      CBasePropDoor::DoorOpen(this, pOpenAwayFrom: nullptr);
      return 1;
    }
    else
    {
      CBasePropDoor::DoorOpen(
        this,
        pOpenAwayFrom: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDC00
// Name: private: void CBasePropDoor::MasterStartBlocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::MasterStartBlocked(CBasePropDoor *this, CBaseEntity *pOther)
{
  int m_Size; // ebx
  int i; // esi
  unsigned int m_Index; // eax
  CBasePropDoor *m_pEntity; // ecx

  m_Size = this->m_hDoorList.m_Size;
  if ( m_Size > 0 )
  {
    for ( i = 0; i < m_Size; ++i )
    {
      m_Index = this->m_hDoorList.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = (CBasePropDoor *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr )
          CBasePropDoor::OnStartBlocked(this: m_pEntity, pOther);
      }
    }
  }
  CBasePropDoor::OnStartBlocked(this, pOther);
}

//------------------------------------------------------------------------------
// Address: 0x101EDC80
// Name: private: virtual void CBasePropDoor::StartBlocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::StartBlocked(CBasePropDoor *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // edx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  bool v7; // zf
  CBasePropDoor **v8; // eax

  this->m_bFirstBlocked = true;
  m_Index = this->m_hMaster.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v5 = HIWORD(m_Index),
        v4->m_SerialNumber == v5)
    && v4->m_pEntity != nullptr )
  {
    v6 = v3;
    v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
    v8 = (CBasePropDoor **)&g_pEntityList->m_EntPtrArray[v6];
    if ( v7 )
      CBasePropDoor::MasterStartBlocked(this: *v8, pOther);
    else
      CBasePropDoor::MasterStartBlocked(this: nullptr, pOther);
  }
  else
  {
    CBasePropDoor::OnStartBlocked(this, pOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDCF0
// Name: public: virtual void CPropDoorRotatingBreakable::Precache(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CPropDoorRotatingBreakable::Precache(
        CPropDoorRotatingBreakable *this@<ecx>,
        bool (__cdecl *a2)(const char *)@<edi>)
{
  CBasePropDoor::Precache(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101EDD00
// Name: public: virtual void CBasePropDoor::HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::HandleAnimEvent(CBasePropDoor *this, animevent_t *pEvent)
{
  int event_lowword; // edx

  if ( (pEvent->type & 0x400) != 0 )
    event_lowword = pEvent->_event_lowword;
  else
    event_lowword = *(_DWORD *)&pEvent->_event_highword;
  if ( event_lowword == 1 )
    CBasePropDoor::DoorActivate(this);
  else
    CDynamicProp::HandleAnimEvent(this, pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x101EDD30
// Name: private: void CBasePropDoor::OnUse(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::OnUse(
        CBasePropDoor *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  unsigned int m_Index; // eax
  unsigned int v7; // eax
  CEntInfo *v8; // ecx
  CBasePropDoor::DoorState_t m_eDoorState; // eax
  unsigned int v10; // eax
  int v11; // eax
  int v12; // edi

  m_Index = this->m_hBlocker.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
    && this->m_eDoorState == DOOR_STATE_CLOSING )
  {
    if ( pActivator != nullptr )
      this->m_hActivator.m_Index = pActivator->GetRefEHandle(this: pActivator)->m_Index;
    else
      this->m_hActivator.m_Index = -1;
    v7 = this->m_hBlocker.m_Index;
    if ( v7 != -1 )
    {
      v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v7];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7) )
      {
LABEL_10:
        CBasePropDoor::DoorOpen(this, pOpenAwayFrom: (CBaseEntity *)v8->m_pEntity);
        return;
      }
    }
    goto LABEL_24;
  }
  m_eDoorState = this->m_eDoorState;
  if ( m_eDoorState == DOOR_STATE_CLOSED
    || m_eDoorState == DOOR_STATE_OPEN && (this->m_spawnflags.m_Value & 0x2000) != 0 )
  {
    if ( this->IsDoorLocked(this) )
    {
      v11 = CBaseAnimating::SelectWeightedSequence(this, activity: ACT_DOOR_LOCKED);
      CDynamicProp::PropSetSequence(this, nSequence: v11);
      PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 1, fbutton: 0);
      COutputEvent::FireOutput(this: &this->m_OnLockedUse, pActivator, pCaller, fDelay: 0.0);
    }
    else
    {
      if ( pActivator != nullptr )
        this->m_hActivator.m_Index = pActivator->GetRefEHandle(this: pActivator)->m_Index;
      else
        this->m_hActivator.m_Index = -1;
      PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 0, fbutton: 0);
      v12 = CBaseAnimating::SelectWeightedSequence(this, activity: ACT_DOOR_OPEN);
      CDynamicProp::PropSetSequence(this, nSequence: v12);
      if ( v12 == -1 || CBaseAnimating::HasAnimEvent(this, nSequence: v12, nEvent: 1) == 0 )
        CBasePropDoor::DoorActivate(this);
    }
  }
  else
  {
    if ( m_eDoorState == DOOR_STATE_OPENING && (this->m_spawnflags.m_Value & 0x2000) != 0 )
    {
      CHandle<CBaseEntity>::operator=(this: &this->m_hActivator, val: pActivator);
      CBasePropDoor::DoorClose(this);
      return;
    }
    if ( m_eDoorState == DOOR_STATE_CLOSING || m_eDoorState == DOOR_STATE_AJAR )
    {
      if ( pActivator != nullptr )
        this->m_hActivator.m_Index = pActivator->GetRefEHandle(this: pActivator)->m_Index;
      else
        this->m_hActivator.m_Index = -1;
      v10 = this->m_hActivator.m_Index;
      if ( v10 != -1 )
      {
        v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v10];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber == HIWORD(v10) )
          goto LABEL_10;
      }
LABEL_24:
      CBasePropDoor::DoorOpen(this, pOpenAwayFrom: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDF70
// Name: private: void CBasePropDoor::InputOpen(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::InputOpen(CBasePropDoor *this, inputdata_t *inputdata)
{
  CBaseEntity *pActivator; // edi
  CBasePropDoor::DoorState_t m_eDoorState; // eax

  pActivator = inputdata->pActivator;
  if ( !this->IsDoorLocked(this) )
  {
    m_eDoorState = this->m_eDoorState;
    if ( m_eDoorState != DOOR_STATE_OPEN && m_eDoorState != DOOR_STATE_OPENING )
    {
      PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 0, fbutton: 0);
      COutputEvent::FireOutput(this: &this->m_OnOpen, pActivator, pCaller: this, fDelay: 0.0);
      CBasePropDoor::DoorOpen(this, pOpenAwayFrom: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDFF0
// Name: private: void CBasePropDoor::InputOpenAwayFrom(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::InputOpenAwayFrom(CBasePropDoor *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // eax
  CBaseEntity *EntityByName; // eax
  CBaseEntity *pActivator; // edi
  CBaseEntity *v8; // ebx
  CBasePropDoor::DoorState_t m_eDoorState; // eax

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
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: v5,
                   pSearchingEntity: nullptr,
                   pActivator: inputdata->pActivator,
                   pCaller: inputdata->pCaller,
                   pFilter: nullptr);
  pActivator = inputdata->pActivator;
  v8 = EntityByName;
  if ( !this->IsDoorLocked(this) )
  {
    m_eDoorState = this->m_eDoorState;
    if ( m_eDoorState != DOOR_STATE_OPEN && m_eDoorState != DOOR_STATE_OPENING )
    {
      PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 0, fbutton: 0);
      COutputEvent::FireOutput(this: &this->m_OnOpen, pActivator, pCaller: this, fDelay: 0.0);
      CBasePropDoor::DoorOpen(this, pOpenAwayFrom: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE6D0
// Name: private: virtual void CBasePropDoor::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePropDoor::Use(
        CBasePropDoor *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  unsigned int m_Index; // edx
  int v6; // eax
  CEntInfo *v7; // esi
  unsigned int v8; // edx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hMaster.m_Index;
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
    ((void (__thiscall *)(IHandleEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, _DWORD))m_pEntity->__vftable[33].dtr_IHandleEntity)(
      a1: m_pEntity,
      a2: pActivator,
      a3: pCaller,
      a4: useType,
      a5: LODWORD(value));
  }
  else
  {
    CBasePropDoor::OnUse(this, pActivator, pCaller, useType, value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104035C0
// Name: _dynamic_initializer_for__prop_talker__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_talker__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFlexExpresser> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_talker,
           a3: "prop_talker");
}

//------------------------------------------------------------------------------
// Address: 0x104076A0
// Name: _dynamic_initializer_for__prop_ragdoll__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_ragdoll__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRagdollProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_ragdoll,
           a3: "prop_ragdoll");
}

//------------------------------------------------------------------------------
// Address: 0x10407720
// Name: _dynamic_initializer_for__prop_ragdoll_attached__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_ragdoll_attached__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRagdollPropAttached> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_ragdoll_attached,
           a3: "prop_ragdoll_attached");
}

//------------------------------------------------------------------------------
// Address: 0x10408B40
// Name: _dynamic_initializer_for__prop_hallucination__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_hallucination__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CProp_Hallucination> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_hallucination,
           a3: "prop_hallucination");
}

//------------------------------------------------------------------------------
// Address: 0x10408BF0
// Name: _dynamic_initializer_for__prop_active_gib_limit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_active_gib_limit__()
{
  ConVar::ConVar(this: &prop_active_gib_limit, pName: "prop_active_gib_limit", pDefaultValue: "64", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__prop_active_gib_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x10408C20
// Name: _dynamic_initializer_for__prop_active_gib_max_fade_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_active_gib_max_fade_time__()
{
  ConVar::ConVar(
    this: &prop_active_gib_max_fade_time,
    pName: "prop_active_gib_max_fade_time",
    pDefaultValue: "12",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__prop_active_gib_max_fade_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10408D10
// Name: _dynamic_initializer_for__prop_break_disable_float__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_break_disable_float__()
{
  ConVar::ConVar(this: &prop_break_disable_float, pName: "prop_break_disable_float", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__prop_break_disable_float__);
}

//------------------------------------------------------------------------------
// Address: 0x10408D60
// Name: _dynamic_initializer_for__prop_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_debug__()
{
  ConCommand::ConCommand(
    this: &prop_debug,
    pName: "prop_debug",
    callback: CC_Prop_Debug,
    pHelpString: "Toggle prop debug mode. If on, props will show colorcoded bounding boxes. Red means ignore all damage. White means r"
    "espond physically to damage but never break. Green maps health in the range of 100 down to 1.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__prop_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10408DB0
// Name: DT_BreakableProp::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BreakableProp::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BreakableProp::g_SendTable);
  return atexit(func: DT_BreakableProp::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10408DD0
// Name: DT_BreakableProp::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BreakableProp::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BreakableProp::ignored>();
  DT_BreakableProp::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408DE0
// Name: CBreakableProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBreakableProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBreakableProp>(__formal: nullptr);
  CBreakableProp_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408E10
// Name: _dynamic_initializer_for__prop_dynamic__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_dynamic__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CDynamicProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_dynamic,
           a3: "prop_dynamic");
}

//------------------------------------------------------------------------------
// Address: 0x10408E30
// Name: _dynamic_initializer_for__prop_dynamic_override__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_dynamic_override__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CDynamicProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_dynamic_override,
           a3: "prop_dynamic_override");
}

//------------------------------------------------------------------------------
// Address: 0x10408E50
// Name: CDynamicProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CDynamicProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CDynamicProp>(__formal: nullptr);
  CDynamicProp_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408E80
// Name: DT_DynamicProp::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DynamicProp::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_DynamicProp::g_SendTable);
  return atexit(func: DT_DynamicProp::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10408EA0
// Name: DT_DynamicProp::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DynamicProp::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_DynamicProp::ignored>();
  DT_DynamicProp::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408EB0
// Name: _dynamic_initializer_for__prop_dynamic_ornament__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_dynamic_ornament__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<COrnamentProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_dynamic_ornament,
           a3: "prop_dynamic_ornament");
}

//------------------------------------------------------------------------------
// Address: 0x10408ED0
// Name: COrnamentProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *COrnamentProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<COrnamentProp>(__formal: nullptr);
  COrnamentProp_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408F00
// Name: _dynamic_initializer_for__prop_physics__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_physics__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysicsProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_physics,
           a3: "prop_physics");
}

//------------------------------------------------------------------------------
// Address: 0x10408F20
// Name: _dynamic_initializer_for__prop_physics_override__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_physics_override__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysicsProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_physics_override,
           a3: "prop_physics_override");
}

//------------------------------------------------------------------------------
// Address: 0x10408F40
// Name: CPhysicsProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysicsProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysicsProp>(__formal: nullptr);
  CPhysicsProp_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408F70
// Name: DT_PhysicsProp::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysicsProp::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PhysicsProp::g_SendTable);
  return atexit(func: DT_PhysicsProp::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10408F90
// Name: DT_PhysicsProp::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysicsProp::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PhysicsProp::ignored>();
  DT_PhysicsProp::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409000
// Name: locksound_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *locksound_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<locksound_t>();
  locksound_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409010
// Name: CBasePropDoor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBasePropDoor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBasePropDoor>(__formal: nullptr);
  CBasePropDoor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409040
// Name: DT_BasePropDoor::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BasePropDoor::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BasePropDoor::g_SendTable);
  return atexit(func: DT_BasePropDoor::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10409060
// Name: DT_BasePropDoor::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BasePropDoor::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BasePropDoor::ignored>();
  DT_BasePropDoor::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409070
// Name: CPropDoorRotating_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPropDoorRotating_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPropDoorRotating>(__formal: nullptr);
  CPropDoorRotating_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104090A0
// Name: DT_PropDoorRotating::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PropDoorRotating::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PropDoorRotating::g_SendTable);
  return atexit(func: DT_PropDoorRotating::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104090C0
// Name: DT_PropDoorRotating::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PropDoorRotating::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PropDoorRotating::ignored>();
  DT_PropDoorRotating::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104090D0
// Name: CPropDoorRotatingBreakable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPropDoorRotatingBreakable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPropDoorRotatingBreakable>(__formal: nullptr);
  CPropDoorRotatingBreakable_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104090E0
// Name: _dynamic_initializer_for__prop_door_rotating__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_door_rotating__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPropDoorRotatingBreakable> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_door_rotating,
           a3: "prop_door_rotating");
}

//------------------------------------------------------------------------------
// Address: 0x10409100
// Name: _dynamic_initializer_for__prop_sphere__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_sphere__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysSphere> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_sphere,
           a3: "prop_sphere");
}

//------------------------------------------------------------------------------
// Address: 0x10409140
// Name: CPhysBoxMultiplayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysBoxMultiplayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysBoxMultiplayer>(__formal: nullptr);
  CPhysBoxMultiplayer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409170
// Name: DT_PhysBoxMultiplayer::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysBoxMultiplayer::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PhysBoxMultiplayer::g_SendTable);
  return atexit(func: DT_PhysBoxMultiplayer::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10409190
// Name: DT_PhysBoxMultiplayer::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysBoxMultiplayer::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PhysBoxMultiplayer::ignored>();
  DT_PhysBoxMultiplayer::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104091A0
// Name: _dynamic_initializer_for__prop_physics_multiplayer__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_physics_multiplayer__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysicsPropMultiplayer> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_physics_multiplayer,
           a3: "prop_physics_multiplayer");
}

//------------------------------------------------------------------------------
// Address: 0x104091C0
// Name: CPhysicsPropMultiplayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysicsPropMultiplayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysicsPropMultiplayer>(__formal: nullptr);
  CPhysicsPropMultiplayer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104091F0
// Name: DT_PhysicsPropMultiplayer::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysicsPropMultiplayer::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PhysicsPropMultiplayer::g_SendTable);
  return atexit(func: DT_PhysicsPropMultiplayer::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10409210
// Name: DT_PhysicsPropMultiplayer::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysicsPropMultiplayer::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PhysicsPropMultiplayer::ignored>();
  DT_PhysicsPropMultiplayer::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409220
// Name: _dynamic_initializer_for__prop_physics_respawnable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_physics_respawnable__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysicsPropRespawnable> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_physics_respawnable,
           a3: "prop_physics_respawnable");
}

//------------------------------------------------------------------------------
// Address: 0x10409240
// Name: CPhysicsPropRespawnable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysicsPropRespawnable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysicsPropRespawnable>(__formal: nullptr);
  CPhysicsPropRespawnable_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409250
// Name: _dynamic_initializer_for__prop_dynamic_create__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_dynamic_create__()
{
  ConCommand::ConCommand(
    this: &prop_dynamic_create,
    pName: "prop_dynamic_create",
    callback: (void (__cdecl *)())CC_Prop_Dynamic_Create,
    pHelpString: "Creates a dynamic prop with a specific .mdl aimed away from where the player is looking.\n\tArguments: {.mdl name}",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__prop_dynamic_create__);
}

//------------------------------------------------------------------------------
// Address: 0x10409280
// Name: _dynamic_initializer_for__prop_physics_create__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_physics_create__()
{
  ConCommand::ConCommand(
    this: &prop_physics_create,
    pName: "prop_physics_create",
    callback: (void (__cdecl *)())CC_Prop_Physics_Create,
    pHelpString: "Creates a physics prop with a specific .mdl aimed away from where the player is looking.\n\tArguments: {.mdl name}",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__prop_physics_create__);
}

//------------------------------------------------------------------------------
// Address: 0x10409330
// Name: _dynamic_initializer_for__props_break_max_pieces__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__props_break_max_pieces__()
{
  ConVar::ConVar(
    this: &props_break_max_pieces,
    pName: "props_break_max_pieces",
    pDefaultValue: "-1",
    flags: 0x2000,
    pHelpString: "Maximum prop breakable piece count (-1 = model default)");
  return atexit(func: dynamic_atexit_destructor_for__props_break_max_pieces__);
}

//------------------------------------------------------------------------------
// Address: 0x10409360
// Name: _dynamic_initializer_for__props_break_max_pieces_perframe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__props_break_max_pieces_perframe__()
{
  ConVar::ConVar(
    this: &props_break_max_pieces_perframe,
    pName: "props_break_max_pieces_perframe",
    pDefaultValue: "-1",
    flags: 0x2000,
    pHelpString: "Maximum prop breakable piece count per frame (-1 = model default)");
  return atexit(func: dynamic_atexit_destructor_for__props_break_max_pieces_perframe__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C500
// Name: _dynamic_initializer_for__prop_vehicle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_vehicle__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPropVehicle> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_vehicle,
           a3: "prop_vehicle");
}

//------------------------------------------------------------------------------
// Address: 0x1040C5B0
// Name: _dynamic_initializer_for__prop_vehicle_driveable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_vehicle_driveable__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPropVehicleDriveable> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &prop_vehicle_driveable,
           a3: "prop_vehicle_driveable");
}

//------------------------------------------------------------------------------
// Address: 0x1041D700
// Name: _dynamic_atexit_destructor_for__prop_active_gib_limit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__prop_active_gib_limit__()
{
  ConVar::~ConVar(this: &prop_active_gib_limit);
}

//------------------------------------------------------------------------------
// Address: 0x1041D710
// Name: _dynamic_atexit_destructor_for__prop_active_gib_max_fade_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__prop_active_gib_max_fade_time__()
{
  ConVar::~ConVar(this: &prop_active_gib_max_fade_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041D760
// Name: _dynamic_atexit_destructor_for__prop_break_disable_float__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__prop_break_disable_float__()
{
  ConVar::~ConVar(this: &prop_break_disable_float);
}

//------------------------------------------------------------------------------
// Address: 0x1041D770
// Name: _dynamic_atexit_destructor_for__prop_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__prop_debug__()
{
  ConCommand::~ConCommand(this: &prop_debug);
}

//------------------------------------------------------------------------------
// Address: 0x1041D780
// Name: DT_BreakableProp::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BreakableProp::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BreakableProp::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D790
// Name: DT_DynamicProp::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DynamicProp::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_DynamicProp::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D7C0
// Name: DT_PhysicsProp::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PhysicsProp::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PhysicsProp::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D7F0
// Name: DT_BasePropDoor::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BasePropDoor::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BasePropDoor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D820
// Name: DT_PropDoorRotating::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PropDoorRotating::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PropDoorRotating::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D850
// Name: DT_PhysBoxMultiplayer::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PhysBoxMultiplayer::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PhysBoxMultiplayer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D880
// Name: DT_PhysicsPropMultiplayer::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PhysicsPropMultiplayer::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PhysicsPropMultiplayer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D8B0
// Name: _dynamic_atexit_destructor_for__prop_dynamic_create__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__prop_dynamic_create__()
{
  ConCommand::~ConCommand(this: &prop_dynamic_create);
}

//------------------------------------------------------------------------------
// Address: 0x1041D8C0
// Name: _dynamic_atexit_destructor_for__prop_physics_create__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__prop_physics_create__()
{
  ConCommand::~ConCommand(this: &prop_physics_create);
}

//------------------------------------------------------------------------------
// Address: 0x1041D9E0
// Name: _dynamic_atexit_destructor_for__props_break_max_pieces__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__props_break_max_pieces__()
{
  ConVar::~ConVar(this: &props_break_max_pieces);
}

//------------------------------------------------------------------------------
// Address: 0x1041D9F0
// Name: _dynamic_atexit_destructor_for__props_break_max_pieces_perframe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__props_break_max_pieces_perframe__()
{
  ConVar::~ConVar(this: &props_break_max_pieces_perframe);
}

//------------------------------------------------------------------------------
// Address: 0x101E4200
// Name: class CFunctor __near * CreateFunctor<class CBreakableProp __near *,class CBreakableProp,void,class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Vector,class Vector,class QAngle>(class CBreakableProp __near *,void (CBreakableProp::*)(class Vector const __near &,class Vector const __near &,class QAngle const __near &),class Vector const __near &,class Vector const __near &,class QAngle const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunctor *__cdecl CreateFunctor<CBreakableProp *,CBreakableProp,void,Vector const &,Vector const &,QAngle const &,Vector,Vector,QAngle>(
        CBreakableProp *pObject,
        void (__thiscall *__ptr64 pfnProxied)(CBreakableProp *this, const Vector *, const Vector *, const QAngle *),
        const Vector *arg1,
        const Vector *arg2,
        const QAngle *arg3)
{
  CFunctor *result; // eax

  result = (CFunctor *)operator new(nSize: 0x48u);
  if ( result == nullptr )
    return nullptr;
  result[1].m_nUserID = 1;
  result->__vftable = (CFunctor_vtbl *)&CMemberFunctor3<CBreakableProp *,void (__thiscall CBreakableProp::*)(Vector const &,Vector const &,QAngle const &),Vector,Vector,QAngle,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  result[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor3<CBreakableProp *,void (__thiscall CBreakableProp::*)(Vector const &,Vector const &,QAngle const &),Vector,Vector,QAngle,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  result[2].__vftable = (CFunctor_vtbl *)pfnProxied;
  result[3].__vftable = (CFunctor_vtbl *)pObject;
  result[2].m_nUserID = HIDWORD(pfnProxied);
  *(Vector *)&result[4].__vftable = *arg1;
  *(Vector *)&result[5].m_nUserID = *arg2;
  *(QAngle *)&result[7].__vftable = *arg3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E8310
// Name: struct datamap_t __near * DataMapInit<class CPropDoorRotating>(class CPropDoorRotating __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPropDoorRotating>()
{
  if ( (_S13_1 & 1) == 0 )
  {
    _S13_1 |= 1u;
    nameHolder_352.m_pszBase = "CPropDoorRotating";
    nameHolder_352.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_352.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_352.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_352.m_Names.m_Size = 0;
    nameHolder_352.m_Names.m_pElements = nullptr;
    nameHolder_352.m_nLenBase = 17;
    atexit(func: DataMapInit_CPropDoorRotating__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPropDoorRotating::m_DataMap.baseMap = &CBasePropDoor::m_DataMap;
  if ( (_S13_1 & 2) == 0 )
  {
    _S13_1 |= 2u;
    dataDesc_337[14].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_337[14].inputFunc = 0;
    *(_QWORD *)&dataDesc_337[14].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_337[14].override_count = 0;
    *(_QWORD *)dataDesc_337[14].flatOffset = 0;
    *(_DWORD *)&dataDesc_337[14].flatGroup = 0;
  }
  CPropDoorRotating::m_DataMap.dataNumFields = 14;
  CPropDoorRotating::m_DataMap.dataDesc = &dataDesc_337[1];
  return &CPropDoorRotating::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101E9020
// Name: struct datamap_t __near * DataMapInit<class CPropDoorRotatingBreakable>(class CPropDoorRotatingBreakable __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPropDoorRotatingBreakable>()
{
  if ( (_S15_0 & 1) == 0 )
  {
    _S15_0 |= 1u;
    nameHolder_353.m_pszBase = "CPropDoorRotatingBreakable";
    nameHolder_353.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_353.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_353.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_353.m_Names.m_Size = 0;
    nameHolder_353.m_Names.m_pElements = nullptr;
    nameHolder_353.m_nLenBase = 26;
    atexit(func: DataMapInit_CPropDoorRotatingBreakable__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPropDoorRotatingBreakable::m_DataMap.baseMap = &CPropDoorRotating::m_DataMap;
  CPropDoorRotatingBreakable::m_DataMap.dataNumFields = 2;
  CPropDoorRotatingBreakable::m_DataMap.dataDesc = &dataDesc_338[1];
  return &CPropDoorRotatingBreakable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101E90A0
// Name: struct datamap_t __near * DataMapInit<class CPhysBoxMultiplayer>(class CPhysBoxMultiplayer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysBoxMultiplayer>()
{
  if ( (_S16_1 & 1) == 0 )
  {
    _S16_1 |= 1u;
    nameHolder_354.m_pszBase = "CPhysBoxMultiplayer";
    nameHolder_354.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_354.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_354.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_354.m_Names.m_Size = 0;
    nameHolder_354.m_Names.m_pElements = nullptr;
    nameHolder_354.m_nLenBase = 19;
    atexit(func: DataMapInit_CPhysBoxMultiplayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysBoxMultiplayer::m_DataMap.baseMap = &CPhysBox::m_DataMap;
  CPhysBoxMultiplayer::m_DataMap.dataNumFields = 1;
  CPhysBoxMultiplayer::m_DataMap.dataDesc = dataDesc_482;
  return &CPhysBoxMultiplayer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101E9180
// Name: struct datamap_t __near * DataMapInit<class CPhysicsPropMultiplayer>(class CPhysicsPropMultiplayer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysicsPropMultiplayer>()
{
  if ( (_S18_1 & 1) == 0 )
  {
    _S18_1 |= 1u;
    nameHolder_355.m_pszBase = "CPhysicsPropMultiplayer";
    nameHolder_355.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_355.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_355.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_355.m_Names.m_Size = 0;
    nameHolder_355.m_Names.m_pElements = nullptr;
    nameHolder_355.m_nLenBase = 23;
    atexit(func: DataMapInit_CPhysicsPropMultiplayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysicsPropMultiplayer::m_DataMap.baseMap = &CPhysicsProp::m_DataMap;
  CPhysicsPropMultiplayer::m_DataMap.dataNumFields = 5;
  CPhysicsPropMultiplayer::m_DataMap.dataDesc = &dataDesc_339[1];
  return &CPhysicsPropMultiplayer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101E9200
// Name: struct datamap_t __near * DataMapInit<class CPhysicsPropRespawnable>(class CPhysicsPropRespawnable __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysicsPropRespawnable>()
{
  char *Name; // eax

  if ( (_S20_0 & 1) == 0 )
  {
    _S20_0 |= 1u;
    nameHolder_356.m_pszBase = "CPhysicsPropRespawnable";
    nameHolder_356.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_356.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_356.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_356.m_Names.m_Size = 0;
    nameHolder_356.m_Names.m_pElements = nullptr;
    nameHolder_356.m_nLenBase = 23;
    atexit(func: DataMapInit_CPhysicsPropRespawnable__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysicsPropRespawnable::m_DataMap.baseMap = &CPhysicsProp::m_DataMap;
  if ( (_S20_0 & 2) == 0 )
  {
    _S20_0 |= 2u;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_356, pszIdentifier: "Materialize");
    dataDesc_483[2].fieldSize = 1;
    dataDesc_483[3].flags = 2;
    dataDesc_483[1].fieldName = Name;
    dataDesc_483[4].fieldSize = 1;
    dataDesc_483[1].fieldSize = 1;
    dataDesc_483[1].flags = 32;
    *(_QWORD *)dataDesc_483[2].flatOffset = 0;
    dataDesc_483[4].flags = 2;
    dataDesc_483[2].flags = 6;
    dataDesc_483[3].fieldSize = 1;
    *(_QWORD *)&dataDesc_483[1].td = 0;
    *(_QWORD *)&dataDesc_483[1].override_field = 0;
    *(_QWORD *)&dataDesc_483[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_483[1].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_483[3].flatOffset = 0;
    dataDesc_483[5].fieldSize = 1;
    dataDesc_483[1].fieldOffset = 0;
    dataDesc_483[1].externalName = nullptr;
    dataDesc_483[1].pSaveRestoreOps = nullptr;
    dataDesc_483[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsPropRespawnable::Materialize;
    dataDesc_483[2].fieldType = FIELD_FLOAT;
    dataDesc_483[2].fieldName = "m_flRespawnTime";
    dataDesc_483[2].fieldOffset = 1824;
    dataDesc_483[2].externalName = "RespawnTime";
    dataDesc_483[2].pSaveRestoreOps = nullptr;
    dataDesc_483[2].inputFunc = nullptr;
    dataDesc_483[2].td = nullptr;
    dataDesc_483[2].fieldSizeInBytes = 4;
    dataDesc_483[2].override_field = nullptr;
    dataDesc_483[2].override_count = 0;
    dataDesc_483[2].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_483[2].flatGroup = 0;
    dataDesc_483[3].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_483[3].fieldName = "m_vOriginalSpawnOrigin";
    dataDesc_483[3].fieldOffset = 1776;
    dataDesc_483[3].externalName = nullptr;
    dataDesc_483[3].pSaveRestoreOps = nullptr;
    dataDesc_483[3].inputFunc = nullptr;
    dataDesc_483[3].td = nullptr;
    dataDesc_483[3].fieldSizeInBytes = 12;
    dataDesc_483[3].override_field = nullptr;
    dataDesc_483[3].override_count = 0;
    dataDesc_483[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_483[3].flatGroup = 0;
    dataDesc_483[4].fieldType = FIELD_VECTOR;
    dataDesc_483[4].fieldName = "m_vOriginalSpawnAngles";
    dataDesc_483[4].fieldOffset = 1788;
    dataDesc_483[4].externalName = nullptr;
    dataDesc_483[4].pSaveRestoreOps = nullptr;
    dataDesc_483[4].inputFunc = nullptr;
    dataDesc_483[4].td = nullptr;
    dataDesc_483[4].fieldSizeInBytes = 12;
    dataDesc_483[4].override_field = nullptr;
    dataDesc_483[4].override_count = 0;
    dataDesc_483[4].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_483[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_483[4].flatGroup = 0;
    dataDesc_483[5].fieldType = FIELD_VECTOR;
    dataDesc_483[5].fieldName = "m_vOriginalMins";
    dataDesc_483[5].fieldOffset = 1800;
    dataDesc_483[5].fieldTolerance = 0.0;
    dataDesc_483[6].fieldTolerance = 0.0;
    dataDesc_483[5].flags = 2;
    dataDesc_483[5].externalName = nullptr;
    dataDesc_483[5].pSaveRestoreOps = nullptr;
    dataDesc_483[5].inputFunc = nullptr;
    dataDesc_483[5].td = nullptr;
    dataDesc_483[5].fieldSizeInBytes = 12;
    dataDesc_483[5].override_field = nullptr;
    dataDesc_483[5].override_count = 0;
    *(_QWORD *)dataDesc_483[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_483[5].flatGroup = 0;
    dataDesc_483[6].fieldType = FIELD_VECTOR;
    dataDesc_483[6].fieldName = "m_vOriginalMaxs";
    dataDesc_483[6].fieldOffset = 1812;
    *(_DWORD *)&dataDesc_483[6].fieldSize = 131073;
    dataDesc_483[6].externalName = nullptr;
    dataDesc_483[6].pSaveRestoreOps = nullptr;
    dataDesc_483[6].inputFunc = nullptr;
    dataDesc_483[6].td = nullptr;
    dataDesc_483[6].fieldSizeInBytes = 12;
    dataDesc_483[6].override_field = nullptr;
    dataDesc_483[6].override_count = 0;
    *(_QWORD *)dataDesc_483[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_483[6].flatGroup = 0;
  }
  CPhysicsPropRespawnable::m_DataMap.dataNumFields = 6;
  CPhysicsPropRespawnable::m_DataMap.dataDesc = &dataDesc_483[1];
  return &CPhysicsPropRespawnable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101E9CD0
// Name: struct datamap_t __near * DataMapInit<class CBreakableProp>(class CBreakableProp __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBreakableProp>()
{
  char *Name; // eax

  if ( (_S4_49 & 1) == 0 )
  {
    _S4_49 |= 1u;
    nameHolder_357.m_pszBase = "CBreakableProp";
    nameHolder_357.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_357.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_357.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_357.m_Names.m_Size = 0;
    nameHolder_357.m_Names.m_pElements = nullptr;
    nameHolder_357.m_nLenBase = 14;
    atexit(func: DataMapInit_CBreakableProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBreakableProp::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S4_49 & 2) == 0 )
  {
    _S4_49 |= 2u;
    dataDesc_340[35].fieldSize = 1;
    dataDesc_340[35].flags = 22;
    dataDesc_340[36].fieldSize = 1;
    dataDesc_340[36].flags = 22;
    dataDesc_340[37].fieldSize = 1;
    dataDesc_340[37].flags = 22;
    *(_QWORD *)&dataDesc_340[34].inputFunc = 0;
    *(_QWORD *)&dataDesc_340[34].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_340[34].override_count = 0;
    *(_QWORD *)dataDesc_340[34].flatOffset = 0;
    dataDesc_340[38].fieldSize = 1;
    *(_QWORD *)&dataDesc_340[35].inputFunc = 0;
    *(_QWORD *)&dataDesc_340[35].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_340[35].override_count = 0;
    *(_QWORD *)dataDesc_340[35].flatOffset = 0;
    *(_QWORD *)&dataDesc_340[36].inputFunc = 0;
    *(_QWORD *)&dataDesc_340[36].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_340[36].override_count = 0;
    *(_QWORD *)dataDesc_340[36].flatOffset = 0;
    dataDesc_340[38].flags = 22;
    *(_QWORD *)&dataDesc_340[37].inputFunc = 0;
    *(_QWORD *)&dataDesc_340[37].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_340[37].override_count = 0;
    *(_QWORD *)dataDesc_340[37].flatOffset = 0;
    dataDesc_340[39].fieldSize = 1;
    *(_QWORD *)&dataDesc_340[38].inputFunc = 0;
    *(_QWORD *)&dataDesc_340[38].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_340[38].override_count = 0;
    *(_QWORD *)dataDesc_340[38].flatOffset = 0;
    dataDesc_340[34].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_340[34].flatGroup = 0;
    dataDesc_340[35].fieldType = FIELD_CUSTOM;
    dataDesc_340[35].fieldName = "m_OnHealthChanged";
    dataDesc_340[35].fieldOffset = 1196;
    dataDesc_340[35].externalName = "OnHealthChanged";
    dataDesc_340[35].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_340[35].flatGroup = 0;
    dataDesc_340[36].fieldType = FIELD_CUSTOM;
    dataDesc_340[36].fieldName = "m_OnTakeDamage";
    dataDesc_340[36].fieldOffset = 1220;
    dataDesc_340[36].externalName = "OnTakeDamage";
    dataDesc_340[36].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_340[36].flatGroup = 0;
    dataDesc_340[37].fieldType = FIELD_CUSTOM;
    dataDesc_340[37].fieldName = "m_OnPhysCannonDetach";
    dataDesc_340[37].fieldOffset = 1352;
    dataDesc_340[37].externalName = "OnPhysCannonDetach";
    dataDesc_340[37].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_340[37].flatGroup = 0;
    dataDesc_340[38].fieldType = FIELD_CUSTOM;
    dataDesc_340[38].fieldName = "m_OnPhysCannonAnimatePreStarted";
    dataDesc_340[38].fieldOffset = 1376;
    dataDesc_340[38].externalName = "OnPhysCannonAnimatePreStarted";
    dataDesc_340[38].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_340[38].flatGroup = 0;
    dataDesc_340[39].fieldType = FIELD_CUSTOM;
    dataDesc_340[39].fieldName = "m_OnPhysCannonAnimatePullStarted";
    dataDesc_340[39].fieldOffset = 1400;
    dataDesc_340[39].flags = 22;
    dataDesc_340[39].externalName = "OnPhysCannonAnimatePullStarted";
    dataDesc_340[39].pSaveRestoreOps = eventFuncs;
    dataDesc_340[40].fieldType = FIELD_CUSTOM;
    dataDesc_340[41].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_340[39].inputFunc = 0;
    *(_QWORD *)&dataDesc_340[39].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_340[39].override_count = 0;
    *(_QWORD *)dataDesc_340[39].flatOffset = 0;
    dataDesc_340[40].fieldSize = 1;
    *(_QWORD *)&dataDesc_340[40].inputFunc = 0;
    *(_QWORD *)&dataDesc_340[40].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_340[40].override_count = 0;
    *(_QWORD *)dataDesc_340[40].flatOffset = 0;
    dataDesc_340[41].fieldSize = 1;
    *(_DWORD *)&dataDesc_340[39].flatGroup = 0;
    dataDesc_340[40].fieldName = "m_OnPhysCannonAnimatePostStarted";
    dataDesc_340[40].fieldOffset = 1424;
    dataDesc_340[40].flags = 22;
    dataDesc_340[40].externalName = "OnPhysCannonAnimatePostStarted";
    dataDesc_340[40].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_340[40].flatGroup = 0;
    dataDesc_340[41].fieldName = "m_OnPhysCannonPullAnimFinished";
    dataDesc_340[41].fieldOffset = 1448;
    dataDesc_340[41].flags = 22;
    dataDesc_340[41].externalName = "OnPhysCannonPullAnimFinished";
    dataDesc_340[41].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_340[41].inputFunc = 0;
    *(_QWORD *)&dataDesc_340[41].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_340[41].override_count = 0;
    *(_QWORD *)dataDesc_340[41].flatOffset = 0;
    *(_DWORD *)&dataDesc_340[41].flatGroup = 0;
    dataDesc_340[42].fieldType = FIELD_VOID;
    dataDesc_340[42].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_357,
                                   pszIdentifier: "BreakThink");
    dataDesc_340[42].flags = 32;
    dataDesc_340[42].fieldOffset = 0;
    dataDesc_340[42].fieldSize = 1;
    dataDesc_340[42].externalName = nullptr;
    dataDesc_340[42].pSaveRestoreOps = nullptr;
    dataDesc_340[42].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBreakableProp::BreakThink;
    *(_QWORD *)&dataDesc_340[42].td = 0;
    *(_QWORD *)&dataDesc_340[42].override_field = 0;
    *(_QWORD *)&dataDesc_340[42].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_340[42].flatOffset[1] = 0;
    dataDesc_340[43].fieldType = FIELD_VOID;
    dataDesc_340[43].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_357,
                                   pszIdentifier: "AnimateThink");
    dataDesc_340[43].fieldOffset = 0;
    dataDesc_340[43].fieldSize = 1;
    dataDesc_340[43].flags = 32;
    dataDesc_340[43].externalName = nullptr;
    dataDesc_340[43].pSaveRestoreOps = nullptr;
    dataDesc_340[43].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBreakableProp::AnimateThink;
    *(_QWORD *)&dataDesc_340[43].td = 0;
    *(_QWORD *)&dataDesc_340[43].override_field = 0;
    *(_QWORD *)&dataDesc_340[43].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_340[43].flatOffset[1] = 0;
    dataDesc_340[44].fieldType = FIELD_VOID;
    dataDesc_340[44].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_357,
                                   pszIdentifier: "RampToDefaultFadeScale");
    dataDesc_340[44].fieldOffset = 0;
    dataDesc_340[44].fieldSize = 1;
    dataDesc_340[44].flags = 32;
    dataDesc_340[44].externalName = nullptr;
    dataDesc_340[44].pSaveRestoreOps = nullptr;
    dataDesc_340[44].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBreakableProp::RampToDefaultFadeScale;
    *(_QWORD *)&dataDesc_340[44].td = 0;
    *(_QWORD *)&dataDesc_340[44].override_field = 0;
    *(_QWORD *)&dataDesc_340[44].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_340[44].flatOffset[1] = 0;
    dataDesc_340[45].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_357, pszIdentifier: "BreakablePropTouch");
    dataDesc_340[45].flags = 32;
    dataDesc_340[46].flags = 2;
    dataDesc_340[45].fieldName = Name;
    dataDesc_340[47].fieldSize = 1;
    *(_QWORD *)dataDesc_340[46].flatOffset = 0;
    dataDesc_340[45].fieldSize = 1;
    dataDesc_340[46].fieldSize = 1;
    dataDesc_340[47].flags = 2;
    dataDesc_340[48].fieldSize = 1;
    *(_QWORD *)&dataDesc_340[45].td = 0;
    *(_QWORD *)&dataDesc_340[45].override_field = 0;
    *(_QWORD *)&dataDesc_340[45].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_340[45].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_340[47].flatOffset = 0;
    dataDesc_340[45].fieldOffset = 0;
    dataDesc_340[45].externalName = nullptr;
    dataDesc_340[45].pSaveRestoreOps = nullptr;
    dataDesc_340[45].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBreakableProp::BreakablePropTouch;
    dataDesc_340[46].fieldType = FIELD_EHANDLE;
    dataDesc_340[46].fieldName = "m_hPhysicsAttacker";
    dataDesc_340[46].fieldOffset = 1340;
    dataDesc_340[46].externalName = nullptr;
    dataDesc_340[46].pSaveRestoreOps = nullptr;
    dataDesc_340[46].inputFunc = nullptr;
    dataDesc_340[46].td = nullptr;
    dataDesc_340[46].fieldSizeInBytes = 4;
    dataDesc_340[46].override_field = nullptr;
    dataDesc_340[46].override_count = 0;
    dataDesc_340[46].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_340[46].flatGroup = 0;
    dataDesc_340[47].fieldType = FIELD_TIME;
    dataDesc_340[47].fieldName = "m_flLastPhysicsInfluenceTime";
    dataDesc_340[47].fieldOffset = 1344;
    dataDesc_340[47].externalName = nullptr;
    dataDesc_340[47].pSaveRestoreOps = nullptr;
    dataDesc_340[47].inputFunc = nullptr;
    dataDesc_340[47].td = nullptr;
    dataDesc_340[47].fieldSizeInBytes = 4;
    dataDesc_340[47].override_field = nullptr;
    dataDesc_340[47].override_count = 0;
    dataDesc_340[47].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_340[47].flatGroup = 0;
    dataDesc_340[48].fieldType = FIELD_BOOLEAN;
    dataDesc_340[48].fieldName = "m_bOriginalBlockLOS";
    dataDesc_340[48].fieldOffset = 1350;
    dataDesc_340[48].flags = 2;
    dataDesc_340[48].externalName = nullptr;
    dataDesc_340[48].pSaveRestoreOps = nullptr;
    dataDesc_340[48].inputFunc = nullptr;
    dataDesc_340[48].td = nullptr;
    dataDesc_340[48].fieldSizeInBytes = 1;
    dataDesc_340[48].override_field = nullptr;
    dataDesc_340[48].override_count = 0;
    dataDesc_340[48].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_340[48].flatOffset = 0;
    dataDesc_340[49].fieldType = FIELD_BOOLEAN;
    dataDesc_340[50].fieldType = FIELD_BOOLEAN;
    dataDesc_340[49].fieldSize = 1;
    dataDesc_340[50].fieldSize = 1;
    dataDesc_340[50].flags = 2;
    *(_QWORD *)dataDesc_340[49].flatOffset = 0;
    dataDesc_340[51].fieldSize = 1;
    dataDesc_340[49].fieldTolerance = 0.0;
    dataDesc_340[50].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_340[50].flatOffset = 0;
    dataDesc_340[51].fieldTolerance = 0.0;
    dataDesc_340[52].fieldTolerance = 0.0;
    dataDesc_340[49].flags = 2;
    *(_DWORD *)&dataDesc_340[48].flatGroup = 0;
    dataDesc_340[49].fieldName = "m_bBlockLOSSetByPropData";
    dataDesc_340[49].fieldOffset = 1348;
    dataDesc_340[49].externalName = nullptr;
    dataDesc_340[49].pSaveRestoreOps = nullptr;
    dataDesc_340[49].inputFunc = nullptr;
    dataDesc_340[49].td = nullptr;
    dataDesc_340[49].fieldSizeInBytes = 1;
    dataDesc_340[49].override_field = nullptr;
    dataDesc_340[49].override_count = 0;
    *(_DWORD *)&dataDesc_340[49].flatGroup = 0;
    dataDesc_340[50].fieldName = "m_bIsWalkableSetByPropData";
    dataDesc_340[50].fieldOffset = 1349;
    dataDesc_340[50].externalName = nullptr;
    dataDesc_340[50].pSaveRestoreOps = nullptr;
    dataDesc_340[50].inputFunc = nullptr;
    dataDesc_340[50].td = nullptr;
    dataDesc_340[50].fieldSizeInBytes = 1;
    dataDesc_340[50].override_field = nullptr;
    dataDesc_340[50].override_count = 0;
    *(_DWORD *)&dataDesc_340[50].flatGroup = 0;
    dataDesc_340[51].fieldType = FIELD_EHANDLE;
    dataDesc_340[51].fieldName = "m_hLastAttacker";
    dataDesc_340[51].fieldOffset = 1480;
    dataDesc_340[51].flags = 2;
    dataDesc_340[51].externalName = nullptr;
    dataDesc_340[51].pSaveRestoreOps = nullptr;
    dataDesc_340[51].inputFunc = nullptr;
    dataDesc_340[51].td = nullptr;
    dataDesc_340[51].fieldSizeInBytes = 4;
    dataDesc_340[51].override_field = nullptr;
    dataDesc_340[51].override_count = 0;
    *(_QWORD *)dataDesc_340[51].flatOffset = 0;
    *(_DWORD *)&dataDesc_340[51].flatGroup = 0;
    dataDesc_340[52].fieldType = FIELD_EHANDLE;
    dataDesc_340[52].fieldName = "m_hFlareEnt";
    dataDesc_340[52].fieldOffset = 1484;
    *(_DWORD *)&dataDesc_340[52].fieldSize = 131073;
    dataDesc_340[52].externalName = nullptr;
    dataDesc_340[52].pSaveRestoreOps = nullptr;
    dataDesc_340[52].inputFunc = nullptr;
    dataDesc_340[52].td = nullptr;
    dataDesc_340[52].fieldSizeInBytes = 4;
    dataDesc_340[52].override_field = nullptr;
    dataDesc_340[52].override_count = 0;
    *(_QWORD *)dataDesc_340[52].flatOffset = 0;
    *(_DWORD *)&dataDesc_340[52].flatGroup = 0;
  }
  CBreakableProp::m_DataMap.dataNumFields = 52;
  CBreakableProp::m_DataMap.dataDesc = &dataDesc_340[1];
  return &CBreakableProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101EC000
// Name: struct datamap_t __near * DataMapInit<class CDynamicProp>(class CDynamicProp __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CDynamicProp>()
{
  char *Name; // eax

  if ( (_S5_27 & 1) == 0 )
  {
    _S5_27 |= 1u;
    nameHolder_358.m_pszBase = "CDynamicProp";
    nameHolder_358.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_358.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_358.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_358.m_Names.m_Size = 0;
    nameHolder_358.m_Names.m_pElements = nullptr;
    nameHolder_358.m_nLenBase = 12;
    atexit(func: DataMapInit_CDynamicProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CDynamicProp::m_DataMap.baseMap = &CBreakableProp::m_DataMap;
  if ( (_S5_27 & 2) == 0 )
  {
    _S5_27 |= 2u;
    *(_QWORD *)&dataDesc_341[27].inputFunc = 0;
    *(_QWORD *)&dataDesc_341[27].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_341[27].override_count = 0;
    *(_QWORD *)dataDesc_341[27].flatOffset = 0;
    dataDesc_341[27].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_341[27].flatGroup = 0;
    dataDesc_341[28].fieldType = FIELD_CUSTOM;
    dataDesc_341[28].fieldName = "m_pOutputAnimOver";
    dataDesc_341[28].fieldOffset = 1540;
    *(_DWORD *)&dataDesc_341[28].fieldSize = 1441793;
    dataDesc_341[28].externalName = "OnAnimationDone";
    dataDesc_341[28].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_341[28].inputFunc = 0;
    *(_QWORD *)&dataDesc_341[28].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_341[28].override_count = 0;
    *(_QWORD *)dataDesc_341[28].flatOffset = 0;
    *(_DWORD *)&dataDesc_341[28].flatGroup = 0;
    dataDesc_341[29].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_358, pszIdentifier: "AnimThink");
    *(_QWORD *)&dataDesc_341[29].td = 0;
    *(_QWORD *)&dataDesc_341[29].override_field = 0;
    *(_QWORD *)&dataDesc_341[29].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_341[29].flatOffset[1] = 0;
    dataDesc_341[30].fieldTolerance = 0.0;
    dataDesc_341[29].fieldName = Name;
    dataDesc_341[29].fieldOffset = 0;
    *(_DWORD *)&dataDesc_341[29].fieldSize = 2097153;
    dataDesc_341[29].externalName = nullptr;
    dataDesc_341[29].pSaveRestoreOps = nullptr;
    dataDesc_341[29].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CDynamicProp::AnimThink;
    dataDesc_341[30].fieldType = FIELD_EMBEDDED;
    dataDesc_341[30].fieldName = "m_BoneFollowerManager";
    dataDesc_341[30].fieldOffset = 1600;
    *(_DWORD *)&dataDesc_341[30].fieldSize = 131073;
    dataDesc_341[30].externalName = nullptr;
    dataDesc_341[30].pSaveRestoreOps = nullptr;
    dataDesc_341[30].inputFunc = nullptr;
    dataDesc_341[30].td = &CBoneFollowerManager::m_DataMap;
    dataDesc_341[30].fieldSizeInBytes = 24;
    dataDesc_341[30].override_field = nullptr;
    dataDesc_341[30].override_count = 0;
    *(_QWORD *)dataDesc_341[30].flatOffset = 0;
    *(_DWORD *)&dataDesc_341[30].flatGroup = 0;
  }
  CDynamicProp::m_DataMap.dataNumFields = 30;
  CDynamicProp::m_DataMap.dataDesc = &dataDesc_341[1];
  return &CDynamicProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101EC4A0
// Name: struct datamap_t __near * DataMapInit<class COrnamentProp>(class COrnamentProp __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<COrnamentProp>()
{
  if ( (_S7_13 & 1) == 0 )
  {
    _S7_13 |= 1u;
    nameHolder_359.m_pszBase = "COrnamentProp";
    nameHolder_359.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_359.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_359.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_359.m_Names.m_Size = 0;
    nameHolder_359.m_Names.m_pElements = nullptr;
    nameHolder_359.m_nLenBase = 13;
    atexit(func: DataMapInit_COrnamentProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  COrnamentProp::m_DataMap.baseMap = &CDynamicProp::m_DataMap;
  COrnamentProp::m_DataMap.dataNumFields = 3;
  COrnamentProp::m_DataMap.dataDesc = &dataDesc_342[1];
  return &COrnamentProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101EC560
// Name: struct datamap_t __near * DataMapInit<class CPhysicsProp>(class CPhysicsProp __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysicsProp>()
{
  if ( (_S8_10 & 1) == 0 )
  {
    _S8_10 |= 1u;
    nameHolder_360.m_pszBase = "CPhysicsProp";
    nameHolder_360.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_360.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_360.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_360.m_Names.m_Size = 0;
    nameHolder_360.m_Names.m_pElements = nullptr;
    nameHolder_360.m_nLenBase = 12;
    atexit(func: DataMapInit_CPhysicsProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysicsProp::m_DataMap.baseMap = &CBreakableProp::m_DataMap;
  if ( (_S8_10 & 2) == 0 )
  {
    _S8_10 |= 2u;
    dataDesc_343[14].fieldSize = 1;
    dataDesc_343[14].flags = 22;
    dataDesc_343[15].fieldSize = 1;
    dataDesc_343[15].flags = 22;
    dataDesc_343[16].fieldSize = 1;
    dataDesc_343[16].flags = 22;
    *(_QWORD *)&dataDesc_343[13].inputFunc = 0;
    *(_QWORD *)&dataDesc_343[13].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_343[13].override_count = 0;
    *(_QWORD *)dataDesc_343[13].flatOffset = 0;
    dataDesc_343[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_343[14].inputFunc = 0;
    *(_QWORD *)&dataDesc_343[14].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_343[14].override_count = 0;
    *(_QWORD *)dataDesc_343[14].flatOffset = 0;
    *(_QWORD *)&dataDesc_343[15].inputFunc = 0;
    *(_QWORD *)&dataDesc_343[15].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_343[15].override_count = 0;
    *(_QWORD *)dataDesc_343[15].flatOffset = 0;
    dataDesc_343[17].flags = 22;
    *(_QWORD *)&dataDesc_343[16].inputFunc = 0;
    *(_QWORD *)&dataDesc_343[16].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_343[16].override_count = 0;
    *(_QWORD *)dataDesc_343[16].flatOffset = 0;
    dataDesc_343[18].fieldSize = 1;
    *(_QWORD *)&dataDesc_343[17].inputFunc = 0;
    *(_QWORD *)&dataDesc_343[17].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_343[17].override_count = 0;
    *(_QWORD *)dataDesc_343[17].flatOffset = 0;
    dataDesc_343[13].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_343[13].flatGroup = 0;
    dataDesc_343[14].fieldType = FIELD_CUSTOM;
    dataDesc_343[14].fieldName = "m_MotionEnabled";
    dataDesc_343[14].fieldOffset = 1516;
    dataDesc_343[14].externalName = "OnMotionEnabled";
    dataDesc_343[14].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_343[14].flatGroup = 0;
    dataDesc_343[15].fieldType = FIELD_CUSTOM;
    dataDesc_343[15].fieldName = "m_OnPhysGunPickup";
    dataDesc_343[15].fieldOffset = 1564;
    dataDesc_343[15].externalName = "OnPhysGunPickup";
    dataDesc_343[15].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_343[15].flatGroup = 0;
    dataDesc_343[16].fieldType = FIELD_CUSTOM;
    dataDesc_343[16].fieldName = "m_OnPhysGunOnlyPickup";
    dataDesc_343[16].fieldOffset = 1612;
    dataDesc_343[16].externalName = "OnPhysGunOnlyPickup";
    dataDesc_343[16].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_343[16].flatGroup = 0;
    dataDesc_343[17].fieldType = FIELD_CUSTOM;
    dataDesc_343[17].fieldName = "m_OnPhysGunPunt";
    dataDesc_343[17].fieldOffset = 1588;
    dataDesc_343[17].externalName = "OnPhysGunPunt";
    dataDesc_343[17].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_343[17].flatGroup = 0;
    dataDesc_343[18].fieldType = FIELD_CUSTOM;
    dataDesc_343[18].fieldName = "m_OnPhysGunDrop";
    dataDesc_343[18].fieldOffset = 1636;
    dataDesc_343[18].flags = 22;
    dataDesc_343[18].externalName = "OnPhysGunDrop";
    dataDesc_343[18].pSaveRestoreOps = eventFuncs;
    dataDesc_343[19].fieldSize = 1;
    dataDesc_343[19].fieldType = FIELD_CUSTOM;
    dataDesc_343[20].fieldType = FIELD_CUSTOM;
    dataDesc_343[21].fieldType = FIELD_CUSTOM;
    dataDesc_343[19].flags = 22;
    dataDesc_343[21].fieldSize = 1;
    dataDesc_343[20].fieldSize = 1;
    *(_QWORD *)&dataDesc_343[18].inputFunc = 0;
    *(_QWORD *)&dataDesc_343[18].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_343[18].override_count = 0;
    *(_QWORD *)dataDesc_343[18].flatOffset = 0;
    dataDesc_343[21].flags = 22;
    *(_QWORD *)&dataDesc_343[19].inputFunc = 0;
    *(_QWORD *)&dataDesc_343[19].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_343[19].override_count = 0;
    *(_QWORD *)dataDesc_343[19].flatOffset = 0;
    dataDesc_343[22].fieldSize = 1;
    *(_QWORD *)&dataDesc_343[20].inputFunc = 0;
    *(_QWORD *)&dataDesc_343[20].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_343[20].override_count = 0;
    *(_QWORD *)dataDesc_343[20].flatOffset = 0;
    dataDesc_343[19].pSaveRestoreOps = eventFuncs;
    dataDesc_343[20].pSaveRestoreOps = eventFuncs;
    dataDesc_343[21].pSaveRestoreOps = eventFuncs;
    dataDesc_343[22].flags = 2;
    *(_QWORD *)&dataDesc_343[21].inputFunc = 0;
    *(_QWORD *)&dataDesc_343[21].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_343[21].override_count = 0;
    *(_QWORD *)dataDesc_343[21].flatOffset = 0;
    *(_DWORD *)&dataDesc_343[18].flatGroup = 0;
    dataDesc_343[19].fieldName = "m_OnPlayerUse";
    dataDesc_343[19].fieldOffset = 1660;
    dataDesc_343[19].externalName = "OnPlayerUse";
    *(_DWORD *)&dataDesc_343[19].flatGroup = 0;
    dataDesc_343[20].fieldName = "m_OnPlayerPickup";
    dataDesc_343[20].fieldOffset = 1684;
    dataDesc_343[20].flags = 22;
    dataDesc_343[20].externalName = "OnPlayerPickup";
    *(_DWORD *)&dataDesc_343[20].flatGroup = 0;
    dataDesc_343[21].fieldName = "m_OnOutOfWorld";
    dataDesc_343[21].fieldOffset = 1708;
    dataDesc_343[21].externalName = "OnOutOfWorld";
    *(_DWORD *)&dataDesc_343[21].flatGroup = 0;
    dataDesc_343[22].fieldType = FIELD_BOOLEAN;
    dataDesc_343[22].fieldName = "m_bThrownByPlayer";
    dataDesc_343[22].fieldOffset = 1756;
    dataDesc_343[22].externalName = nullptr;
    dataDesc_343[22].pSaveRestoreOps = nullptr;
    dataDesc_343[22].inputFunc = nullptr;
    dataDesc_343[22].td = nullptr;
    dataDesc_343[22].fieldSizeInBytes = 1;
    dataDesc_343[22].override_field = nullptr;
    dataDesc_343[22].override_count = 0;
    dataDesc_343[22].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_343[22].flatOffset = 0;
    *(_DWORD *)&dataDesc_343[22].flatGroup = 0;
    dataDesc_343[23].fieldType = FIELD_BOOLEAN;
    dataDesc_343[23].fieldName = "m_bFirstCollisionAfterLaunch";
    dataDesc_343[23].fieldOffset = 1757;
    dataDesc_343[23].fieldSize = 1;
    dataDesc_343[23].flags = 2;
    dataDesc_343[23].externalName = nullptr;
    dataDesc_343[23].pSaveRestoreOps = nullptr;
    dataDesc_343[23].inputFunc = nullptr;
    dataDesc_343[23].td = nullptr;
    dataDesc_343[23].fieldSizeInBytes = 1;
    dataDesc_343[23].fieldTolerance = 0.0;
    dataDesc_343[24].fieldTolerance = 0.0;
    dataDesc_343[23].override_field = nullptr;
    dataDesc_343[23].override_count = 0;
    *(_QWORD *)dataDesc_343[23].flatOffset = 0;
    *(_DWORD *)&dataDesc_343[23].flatGroup = 0;
    dataDesc_343[24].fieldType = FIELD_INTEGER;
    dataDesc_343[24].fieldName = "m_iExploitableByPlayer";
    dataDesc_343[24].fieldOffset = 1760;
    dataDesc_343[24].fieldSize = 1;
    dataDesc_343[24].flags = 6;
    dataDesc_343[24].externalName = "ExploitableByPlayer";
    dataDesc_343[24].pSaveRestoreOps = nullptr;
    dataDesc_343[24].inputFunc = nullptr;
    dataDesc_343[24].td = nullptr;
    dataDesc_343[24].fieldSizeInBytes = 4;
    dataDesc_343[24].override_field = nullptr;
    dataDesc_343[24].override_count = 0;
    *(_QWORD *)dataDesc_343[24].flatOffset = 0;
    *(_DWORD *)&dataDesc_343[24].flatGroup = 0;
    dataDesc_343[25].fieldType = FIELD_VOID;
    dataDesc_343[25].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_360,
                                   pszIdentifier: "ClearFlagsThink");
    dataDesc_343[25].fieldOffset = 0;
    *(_DWORD *)&dataDesc_343[25].fieldSize = 2097153;
    dataDesc_343[25].externalName = nullptr;
    dataDesc_343[25].pSaveRestoreOps = nullptr;
    dataDesc_343[25].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsProp::ClearFlagsThink;
    *(_QWORD *)&dataDesc_343[25].td = 0;
    *(_QWORD *)&dataDesc_343[25].override_field = 0;
    *(_QWORD *)&dataDesc_343[25].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_343[25].flatOffset[1] = 0;
  }
  CPhysicsProp::m_DataMap.dataNumFields = 25;
  CPhysicsProp::m_DataMap.dataDesc = &dataDesc_343[1];
  return &CPhysicsProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101EE090
// Name: struct datamap_t __near * DataMapInit<class CBasePropDoor>(class CBasePropDoor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBasePropDoor>()
{
  if ( (_S11_3 & 1) == 0 )
  {
    _S11_3 |= 1u;
    nameHolder_361.m_pszBase = "CBasePropDoor";
    nameHolder_361.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_361.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_361.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_361.m_Names.m_Size = 0;
    nameHolder_361.m_Names.m_pElements = nullptr;
    nameHolder_361.m_nLenBase = 13;
    atexit(func: DataMapInit_CBasePropDoor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBasePropDoor::m_DataMap.baseMap = &CDynamicProp::m_DataMap;
  if ( (_S11_3 & 2) == 0 )
  {
    _S11_3 |= 2u;
    dataDesc_344[23].fieldSize = 1;
    dataDesc_344[23].flags = 22;
    dataDesc_344[24].fieldSize = 1;
    dataDesc_344[24].flags = 22;
    dataDesc_344[25].fieldSize = 1;
    dataDesc_344[25].flags = 22;
    *(_QWORD *)&dataDesc_344[22].inputFunc = 0;
    *(_QWORD *)&dataDesc_344[22].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_344[22].override_count = 0;
    *(_QWORD *)dataDesc_344[22].flatOffset = 0;
    dataDesc_344[26].fieldSize = 1;
    *(_QWORD *)&dataDesc_344[23].inputFunc = 0;
    *(_QWORD *)&dataDesc_344[23].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_344[23].override_count = 0;
    *(_QWORD *)dataDesc_344[23].flatOffset = 0;
    *(_QWORD *)&dataDesc_344[24].inputFunc = 0;
    *(_QWORD *)&dataDesc_344[24].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_344[24].override_count = 0;
    *(_QWORD *)dataDesc_344[24].flatOffset = 0;
    dataDesc_344[26].flags = 22;
    *(_QWORD *)&dataDesc_344[25].inputFunc = 0;
    *(_QWORD *)&dataDesc_344[25].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_344[25].override_count = 0;
    *(_QWORD *)dataDesc_344[25].flatOffset = 0;
    dataDesc_344[27].fieldSize = 1;
    *(_QWORD *)&dataDesc_344[26].inputFunc = 0;
    *(_QWORD *)&dataDesc_344[26].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_344[26].override_count = 0;
    *(_QWORD *)dataDesc_344[26].flatOffset = 0;
    dataDesc_344[22].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_344[22].flatGroup = 0;
    dataDesc_344[23].fieldType = FIELD_CUSTOM;
    dataDesc_344[23].fieldName = "m_OnBlockedClosing";
    dataDesc_344[23].fieldOffset = 1736;
    dataDesc_344[23].externalName = "OnBlockedClosing";
    dataDesc_344[23].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_344[23].flatGroup = 0;
    dataDesc_344[24].fieldType = FIELD_CUSTOM;
    dataDesc_344[24].fieldName = "m_OnUnblockedOpening";
    dataDesc_344[24].fieldOffset = 1808;
    dataDesc_344[24].externalName = "OnUnblockedOpening";
    dataDesc_344[24].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_344[24].flatGroup = 0;
    dataDesc_344[25].fieldType = FIELD_CUSTOM;
    dataDesc_344[25].fieldName = "m_OnUnblockedClosing";
    dataDesc_344[25].fieldOffset = 1784;
    dataDesc_344[25].externalName = "OnUnblockedClosing";
    dataDesc_344[25].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_344[25].flatGroup = 0;
    dataDesc_344[26].fieldType = FIELD_CUSTOM;
    dataDesc_344[26].fieldName = "m_OnFullyClosed";
    dataDesc_344[26].fieldOffset = 1832;
    dataDesc_344[26].externalName = "OnFullyClosed";
    dataDesc_344[26].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_344[26].flatGroup = 0;
    dataDesc_344[27].fieldType = FIELD_CUSTOM;
    dataDesc_344[27].fieldName = "m_OnFullyOpen";
    dataDesc_344[27].fieldOffset = 1856;
    dataDesc_344[27].flags = 22;
    dataDesc_344[27].externalName = "OnFullyOpen";
    dataDesc_344[27].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_344[27].inputFunc = 0;
    *(_QWORD *)&dataDesc_344[27].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_344[27].override_count = 0;
    *(_QWORD *)dataDesc_344[27].flatOffset = 0;
    *(_QWORD *)&dataDesc_344[28].inputFunc = 0;
    *(_QWORD *)&dataDesc_344[28].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_344[28].override_count = 0;
    *(_QWORD *)dataDesc_344[28].flatOffset = 0;
    dataDesc_344[28].fieldSize = 1;
    *(_QWORD *)&dataDesc_344[29].inputFunc = 0;
    *(_QWORD *)&dataDesc_344[29].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_344[29].override_count = 0;
    *(_QWORD *)dataDesc_344[29].flatOffset = 0;
    dataDesc_344[28].flags = 22;
    dataDesc_344[28].fieldType = FIELD_CUSTOM;
    dataDesc_344[29].fieldType = FIELD_CUSTOM;
    dataDesc_344[30].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_344[30].inputFunc = 0;
    *(_QWORD *)&dataDesc_344[30].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_344[30].override_count = 0;
    *(_QWORD *)dataDesc_344[30].flatOffset = 0;
    dataDesc_344[29].fieldSize = 1;
    dataDesc_344[30].fieldSize = 1;
    dataDesc_344[28].pSaveRestoreOps = eventFuncs;
    dataDesc_344[29].pSaveRestoreOps = eventFuncs;
    dataDesc_344[30].pSaveRestoreOps = eventFuncs;
    dataDesc_344[30].flags = 22;
    dataDesc_344[31].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_344[27].flatGroup = 0;
    dataDesc_344[28].fieldName = "m_OnClose";
    dataDesc_344[28].fieldOffset = 1880;
    dataDesc_344[28].externalName = "OnClose";
    *(_DWORD *)&dataDesc_344[28].flatGroup = 0;
    dataDesc_344[29].fieldName = "m_OnOpen";
    dataDesc_344[29].fieldOffset = 1904;
    dataDesc_344[29].flags = 22;
    dataDesc_344[29].externalName = "OnOpen";
    *(_DWORD *)&dataDesc_344[29].flatGroup = 0;
    dataDesc_344[30].fieldName = "m_OnLockedUse";
    dataDesc_344[30].fieldOffset = 1928;
    dataDesc_344[30].externalName = "OnLockedUse";
    *(_DWORD *)&dataDesc_344[30].flatGroup = 0;
    dataDesc_344[31].fieldType = FIELD_EMBEDDED;
    dataDesc_344[31].fieldName = "m_ls";
    dataDesc_344[31].fieldOffset = 1656;
    dataDesc_344[31].fieldSize = 1;
    dataDesc_344[31].flags = 2;
    dataDesc_344[31].externalName = nullptr;
    dataDesc_344[31].pSaveRestoreOps = nullptr;
    dataDesc_344[31].inputFunc = nullptr;
    dataDesc_344[31].td = &locksound_t::m_DataMap;
    dataDesc_344[31].fieldSizeInBytes = 40;
    dataDesc_344[31].override_field = nullptr;
    dataDesc_344[31].override_count = 0;
    *(_QWORD *)dataDesc_344[31].flatOffset = 0;
    *(_DWORD *)&dataDesc_344[31].flatGroup = 0;
    dataDesc_344[32].fieldType = FIELD_VOID;
    dataDesc_344[32].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_361,
                                   pszIdentifier: "DoorOpenMoveDone");
    dataDesc_344[32].fieldOffset = 0;
    dataDesc_344[32].fieldSize = 1;
    dataDesc_344[32].flags = 32;
    dataDesc_344[32].externalName = nullptr;
    dataDesc_344[32].pSaveRestoreOps = nullptr;
    dataDesc_344[32].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBasePropDoor::DoorOpenMoveDone;
    *(_QWORD *)&dataDesc_344[32].td = 0;
    *(_QWORD *)&dataDesc_344[32].override_field = 0;
    *(_QWORD *)&dataDesc_344[32].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_344[32].flatOffset[1] = 0;
    dataDesc_344[33].fieldType = FIELD_VOID;
    dataDesc_344[33].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_361,
                                   pszIdentifier: "DoorCloseMoveDone");
    dataDesc_344[33].flags = 32;
    dataDesc_344[33].fieldOffset = 0;
    dataDesc_344[33].fieldSize = 1;
    dataDesc_344[33].externalName = nullptr;
    dataDesc_344[33].pSaveRestoreOps = nullptr;
    dataDesc_344[33].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBasePropDoor::DoorCloseMoveDone;
    *(_QWORD *)&dataDesc_344[33].td = 0;
    *(_QWORD *)&dataDesc_344[33].override_field = 0;
    *(_QWORD *)&dataDesc_344[33].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_344[33].flatOffset[1] = 0;
    dataDesc_344[34].fieldType = FIELD_VOID;
    dataDesc_344[34].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_361,
                                   pszIdentifier: "DoorAutoCloseThink");
    dataDesc_344[34].fieldOffset = 0;
    dataDesc_344[34].fieldSize = 1;
    dataDesc_344[34].flags = 32;
    dataDesc_344[34].externalName = nullptr;
    dataDesc_344[34].pSaveRestoreOps = nullptr;
    dataDesc_344[34].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBasePropDoor::DoorAutoCloseThink;
    *(_QWORD *)&dataDesc_344[34].td = 0;
    *(_QWORD *)&dataDesc_344[34].override_field = 0;
    *(_QWORD *)&dataDesc_344[34].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_344[34].flatOffset[1] = 0;
    dataDesc_344[35].fieldType = FIELD_VOID;
    dataDesc_344[35].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_361,
                                   pszIdentifier: "DisableAreaPortalThink");
    dataDesc_344[35].fieldOffset = 0;
    *(_DWORD *)&dataDesc_344[35].fieldSize = 2097153;
    dataDesc_344[35].externalName = nullptr;
    dataDesc_344[35].pSaveRestoreOps = nullptr;
    dataDesc_344[35].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBasePropDoor::DisableAreaPortalThink;
    *(_QWORD *)&dataDesc_344[35].td = 0;
    *(_QWORD *)&dataDesc_344[35].override_field = 0;
    *(_QWORD *)&dataDesc_344[35].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_344[35].flatOffset[1] = 0;
  }
  CBasePropDoor::m_DataMap.dataNumFields = 35;
  CBasePropDoor::m_DataMap.dataDesc = &dataDesc_344[1];
  return &CBasePropDoor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104035E0
// Name: _dynamic_initializer_for__s_FogSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_FogSystem__()
{
  CAutoGameSystem::CAutoGameSystem(this: &s_FogSystem, name: "FogSystem");
  s_FogSystem.m_bRegisteredForEvents = false;
  s_FogSystem.m_nDebugID = 42;
  s_FogSystem.CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CFogSystem_vtbl *)&CFogSystem::`vftable'{for `CAutoGameSystem'};
  s_FogSystem.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CFogSystem::`vftable'{for `CGameEventListener'};
  s_FogSystem.m_hMasterController.m_Index = -1;
  return atexit(func: dynamic_atexit_destructor_for__s_FogSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10403630
// Name: _dynamic_initializer_for__env_fog_controller__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_fog_controller__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFogController> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_fog_controller,
           a3: "env_fog_controller");
}

//------------------------------------------------------------------------------
// Address: 0x104076C0
// Name: _dynamic_initializer_for__g_CRagdollProp_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CRagdollProp_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CRagdollProp_ClassReg,
           pNetworkName: "CRagdollProp",
           pTable: &DT_Ragdoll::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10407740
// Name: _dynamic_initializer_for__g_CRagdollPropAttached_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CRagdollPropAttached_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CRagdollPropAttached_ClassReg,
           pNetworkName: "CRagdollPropAttached",
           pTable: &DT_Ragdoll_Attached::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10408B60
// Name: _dynamic_initializer_for__g_debug_doors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_doors__()
{
  ConVar::ConVar(this: &g_debug_doors, pName: "g_debug_doors", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_doors__);
}

//------------------------------------------------------------------------------
// Address: 0x10408D90
// Name: _dynamic_initializer_for__g_CBreakableProp_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBreakableProp_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBreakableProp_ClassReg,
           pNetworkName: "CBreakableProp",
           pTable: &DT_BreakableProp::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10408E60
// Name: _dynamic_initializer_for__g_CDynamicProp_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CDynamicProp_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CDynamicProp_ClassReg,
           pNetworkName: "CDynamicProp",
           pTable: &DT_DynamicProp::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10408F50
// Name: _dynamic_initializer_for__g_CPhysicsProp_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPhysicsProp_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPhysicsProp_ClassReg,
           pNetworkName: "CPhysicsProp",
           pTable: &DT_PhysicsProp::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10408FA0
// Name: _dynamic_initializer_for__g_BreakModelsPrecached__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BreakModelsPrecached__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_BreakModelsPrecached, name: "CBreakModelsPrecached");
  g_BreakModelsPrecached.__vftable = (CBreakModelsPrecached_vtbl *)&CBreakModelsPrecached::`vftable';
  g_BreakModelsPrecached.m_modelList.m_Elements.m_pMemory = nullptr;
  g_BreakModelsPrecached.m_modelList.m_Elements.m_nAllocationCount = 0;
  g_BreakModelsPrecached.m_modelList.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&g_BreakModelsPrecached.m_modelList.m_Root = 0xFFFF;
  *(_DWORD *)&g_BreakModelsPrecached.m_modelList.m_FirstFree = -1;
  g_BreakModelsPrecached.m_modelList.m_pElements = nullptr;
  g_BreakModelsPrecached.m_modelList.m_LessFunc = (bool (__cdecl *)(const CBreakModelsPrecached::breakable_precache_t *, const CBreakModelsPrecached::breakable_precache_t *))CBreakModelsPrecached::BreakLessFunc;
  return atexit(func: dynamic_atexit_destructor_for__g_BreakModelsPrecached__);
}

//------------------------------------------------------------------------------
// Address: 0x10409020
// Name: _dynamic_initializer_for__g_CBasePropDoor_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBasePropDoor_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBasePropDoor_ClassReg,
           pNetworkName: "CBasePropDoor",
           pTable: &DT_BasePropDoor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10409080
// Name: _dynamic_initializer_for__g_CPropDoorRotating_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPropDoorRotating_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPropDoorRotating_ClassReg,
           pNetworkName: "CPropDoorRotating",
           pTable: &DT_PropDoorRotating::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10409150
// Name: _dynamic_initializer_for__g_CPhysBoxMultiplayer_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPhysBoxMultiplayer_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPhysBoxMultiplayer_ClassReg,
           pNetworkName: "CPhysBoxMultiplayer",
           pTable: &DT_PhysBoxMultiplayer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104091D0
// Name: _dynamic_initializer_for__g_CPhysicsPropMultiplayer_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPhysicsPropMultiplayer_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPhysicsPropMultiplayer_ClassReg,
           pNetworkName: "CPhysicsPropMultiplayer",
           pTable: &DT_PhysicsPropMultiplayer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104092B0
// Name: _dynamic_initializer_for__ent_rotate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_rotate__()
{
  ConCommand::ConCommand(
    this: &ent_rotate,
    pName: "ent_rotate",
    callback: (void (__cdecl *)())CC_Ent_Rotate,
    pHelpString: "Rotates an entity by a specified # of degrees",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_rotate__);
}

//------------------------------------------------------------------------------
// Address: 0x10409390
// Name: _dynamic_initializer_for__g_PropDataSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PropDataSystem__()
{
  CPropData::CPropData(this: &g_PropDataSystem);
  return atexit(func: dynamic_atexit_destructor_for__g_PropDataSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C5D0
// Name: _dynamic_initializer_for__r_JeepFOV__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_JeepFOV__()
{
  ConVar::ConVar(this: &r_JeepFOV, pName: "r_JeepFOV", pDefaultValue: "90", flags: 24576);
  return atexit(func: dynamic_atexit_destructor_for__r_JeepFOV__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C600
// Name: _dynamic_initializer_for__g_debug_vehiclesound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_vehiclesound__()
{
  ConVar::ConVar(this: &g_debug_vehiclesound, pName: "g_debug_vehiclesound", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_vehiclesound__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C630
// Name: _dynamic_initializer_for__g_debug_vehicleexit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_vehicleexit__()
{
  ConVar::ConVar(this: &g_debug_vehicleexit, pName: "g_debug_vehicleexit", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_vehicleexit__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C660
// Name: _dynamic_initializer_for__sv_vehicle_autoaim_scale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_vehicle_autoaim_scale__()
{
  ConVar::ConVar(this: &sv_vehicle_autoaim_scale, pName: "sv_vehicle_autoaim_scale", pDefaultValue: "8", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_vehicle_autoaim_scale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D7A0
// Name: _ServerClassInit_DT_DynamicProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_DynamicProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S6_21;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D7D0
// Name: _ServerClassInit_DT_PhysicsProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PhysicsProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S9_7;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D800
// Name: _ServerClassInit_DT_BasePropDoor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BasePropDoor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S12_2;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D830
// Name: _ServerClassInit_DT_PropDoorRotating::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PropDoorRotating::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S14_1;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D860
// Name: _ServerClassInit_DT_PhysBoxMultiplayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PhysBoxMultiplayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S17_1;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D890
// Name: _ServerClassInit_DT_PhysicsPropMultiplayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PhysicsPropMultiplayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S19_0;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D8D0
// Name: _dynamic_atexit_destructor_for__ent_rotate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_rotate__()
{
  ConCommand::~ConCommand(this: &ent_rotate);
}

//------------------------------------------------------------------------------
// Address: 0x1041D8E0
// Name: _ServerClassInit_DT_BreakableProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BreakableProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_105;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D900
// Name: _DataMapInit_CBreakableProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBreakableProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_357);
}

//------------------------------------------------------------------------------
// Address: 0x1041D910
// Name: _DataMapInit_CDynamicProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CDynamicProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_358);
}

//------------------------------------------------------------------------------
// Address: 0x1041D920
// Name: _DataMapInit_COrnamentProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_COrnamentProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_359);
}

//------------------------------------------------------------------------------
// Address: 0x1041D930
// Name: _DataMapInit_CPhysicsProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysicsProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_360);
}

//------------------------------------------------------------------------------
// Address: 0x1041D940
// Name: _DataMapInit_locksound_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_locksound_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_351);
}

//------------------------------------------------------------------------------
// Address: 0x1041D950
// Name: _DataMapInit_CBasePropDoor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBasePropDoor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_361);
}

//------------------------------------------------------------------------------
// Address: 0x1041D960
// Name: _DataMapInit_CPropDoorRotating__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPropDoorRotating__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_352);
}

//------------------------------------------------------------------------------
// Address: 0x1041D970
// Name: _DataMapInit_CPropDoorRotatingBreakable__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPropDoorRotatingBreakable__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_353);
}

//------------------------------------------------------------------------------
// Address: 0x1041D980
// Name: _DataMapInit_CPhysBoxMultiplayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysBoxMultiplayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_354);
}

//------------------------------------------------------------------------------
// Address: 0x1041D990
// Name: _DataMapInit_CPhysicsPropMultiplayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysicsPropMultiplayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_355);
}

//------------------------------------------------------------------------------
// Address: 0x1041D9A0
// Name: _DataMapInit_CPhysicsPropRespawnable__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysicsPropRespawnable__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_356);
}

//------------------------------------------------------------------------------
// Address: 0x1041D9B0
// Name: _dynamic_atexit_destructor_for__g_BreakModelsPrecached__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BreakModelsPrecached__()
{
  CUtlRBTree<CBreakModelsPrecached::breakable_precache_t,unsigned short,bool (__cdecl *)(CBreakModelsPrecached::breakable_precache_t const &,CBreakModelsPrecached::breakable_precache_t const &),CUtlMemory<UtlRBTreeNode_t<CBreakModelsPrecached::breakable_precache_t,unsigned short>,unsigned short>>::~CUtlRBTree<CBreakModelsPrecached::breakable_precache_t,unsigned short,bool (__cdecl *)(CBreakModelsPrecached::breakable_precache_t const &,CBreakModelsPrecached::breakable_precache_t const &),CUtlMemory<UtlRBTreeNode_t<CBreakModelsPrecached::breakable_precache_t,unsigned short>,unsigned short>>(this: &g_BreakModelsPrecached.m_modelList);
  IGameSystem::~IGameSystem(this: &g_BreakModelsPrecached);
}

//------------------------------------------------------------------------------
// Address: 0x1041D9D0
// Name: _dynamic_atexit_destructor_for__sv_pushaway_clientside_size__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pushaway_clientside_size__()
{
  ConVar::~ConVar(this: &sv_pushaway_clientside_size);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA00
// Name: _DataMapInit_CGameGibManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGameGibManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_362);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA10
// Name: _dynamic_atexit_destructor_for__g_PropDataSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PropDataSystem__()
{
  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::~CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>(this: (CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *)&g_PropDataSystem.m_BreakableChunks);
  IGameSystem::~IGameSystem(this: &g_PropDataSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA30
// Name: _dynamic_atexit_destructor_for__sv_disable_querycache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_disable_querycache__()
{
  ConVar::~ConVar(this: &sv_disable_querycache);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA40
// Name: _dynamic_atexit_destructor_for__sv_querycache_stats_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_querycache_stats_command__()
{
  ConCommand::~ConCommand(this: &sv_querycache_stats_command);
}
