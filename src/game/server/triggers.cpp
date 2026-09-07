// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/triggers.cpp
// Functions: 352
// ============================================================

#include "game\server\triggers.h"

//------------------------------------------------------------------------------
// Address: 0x100E3A20
// Name: public: void CTriggerCameraMultiplayer::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCameraMultiplayer::InputDisable(CBaseButton *this, inputdata_t *inputdata)
{
  this->Lock(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D2970
// Name: public: virtual void CBaseVPhysicsTrigger::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVPhysicsTrigger::Activate(CPointEntityFinder *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  void *v4; // eax

  pszValue = this->m_iFilterName.pszValue;
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
    v4 = __RTDynamicCast(
           inptr: EntityByName,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBaseFilter `RTTI Type Descriptor',
           isReference: 0);
    if ( v4 != nullptr )
    {
      this->m_hFilter.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
      CBaseEntity::Activate(this);
      return;
    }
    this->m_hFilter.m_Index = -1;
  }
  CBaseEntity::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023C5C0
// Name: public: class Vector Vector::Normalized(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::Normalized(Vector *this, Vector *result)
{
  *result = *this;
  VectorNormalize(vec: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023C600
// Name: protected: virtual struct datamap_t __near * CBaseTrigger::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseTrigger::GetDataDescMap(CBaseTrigger *this)
{
  return &CBaseTrigger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C610
// Name: public: virtual class ServerClass __near * CBaseTrigger::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseTrigger::GetServerClass(CBaseTrigger *this)
{
  return &g_CBaseTrigger_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1023C620
// Name: public: virtual void CBaseTrigger::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::InputDisable(CBaseButton *this, inputdata_t *inputdata)
{
  this->Unlock(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023C630
// Name: public: virtual void CBaseTrigger::InputStartTouch(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::InputStartTouch(CBaseTrigger *this, inputdata_t *inputdata)
{
  this->StartTouch(this, a2: inputdata->pCaller);
}

//------------------------------------------------------------------------------
// Address: 0x1023C650
// Name: public: virtual void CBaseTrigger::InputEndTouch(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::InputEndTouch(CBaseTrigger *this, inputdata_t *inputdata)
{
  this->EndTouch(this, a2: inputdata->pCaller);
}

//------------------------------------------------------------------------------
// Address: 0x1023C670
// Name: public: virtual void CBaseTrigger::OnStartTouchAll(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::OnStartTouchAll(CBaseTrigger *this, CBaseEntity *pOther)
{
  COutputEvent::FireOutput(this: &this->m_OnStartTouchAll, pActivator: pOther, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1023C690
// Name: public: virtual void CBaseTrigger::OnEndTouchAll(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::OnEndTouchAll(CBaseTrigger *this, CBaseEntity *pOther)
{
  COutputEvent::FireOutput(this: &this->m_OnEndTouchAll, pActivator: pOther, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1023C6B0
// Name: public: virtual struct datamap_t __near * CTriggerRemove::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerRemove::GetDataDescMap(CTriggerRemove *this)
{
  return &CTriggerRemove::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C6C0
// Name: public: virtual void CTriggerRemove::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerRemove::Touch(CTriggerRemove *this, CBaseEntity *pOther)
{
  if ( this->PassesTriggerFilters(this, a2: pOther) )
    UTIL_Remove(oldObj: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x1023C6F0
// Name: public: virtual struct datamap_t __near * CTriggerHurt::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerHurt::GetDataDescMap(CTriggerHurt *this)
{
  return &CTriggerHurt::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C700
// Name: public: virtual struct datamap_t __near * CTriggerMultiple::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerMultiple::GetDataDescMap(CTriggerMultiple *this)
{
  return &CTriggerMultiple::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C710
// Name: public: void CTriggerMultiple::MultiTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerMultiple::MultiTouch(CTriggerMultiple *this, CBaseEntity *pOther)
{
  if ( this->PassesTriggerFilters(this, a2: pOther) )
    this->ActivateMultiTrigger(this, a2: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x1023C740
// Name: public: void CTriggerMultiple::MultiWaitOver(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerMultiple::MultiWaitOver(CAI_FightFromCoverGoal *this)
{
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1023C760
// Name: public: virtual struct datamap_t __near * CTriggerLook::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerLook::GetDataDescMap(CTriggerLook *this)
{
  return &CTriggerLook::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C770
// Name: private: virtual struct datamap_t __near * CChangeLevel::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CChangeLevel::GetDataDescMap(CChangeLevel *this)
{
  return &CChangeLevel::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C780
// Name: public: virtual struct datamap_t __near * CTriggerPush::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerPush::GetDataDescMap(CTriggerPush *this)
{
  return &CTriggerPush::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C790
// Name: private: virtual struct datamap_t __near * CTriggerTeleport::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerTeleport::GetDataDescMap(CTriggerTeleport *this)
{
  return &CTriggerTeleport::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C7A0
// Name: public: virtual struct datamap_t __near * CTriggerToggleSave::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerToggleSave::GetDataDescMap(CTriggerToggleSave *this)
{
  return &CTriggerToggleSave::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C7B0
// Name: public: virtual void CTriggerToggleSave::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerToggleSave::Touch(CTriggerToggleSave *this, CBaseEntity *pOther)
{
  if ( !this->m_bDisabled && pOther->IsPlayer(this: pOther) )
  {
    this->m_bDisabled = true;
    engine->ServerCommand(this: engine, a2: "autosave\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023C800
// Name: public: virtual struct datamap_t __near * CTriggerSave::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerSave::GetDataDescMap(CTriggerSave *this)
{
  return &CTriggerSave::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C810
// Name: public: virtual struct datamap_t __near * CTriggerGravity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerGravity::GetDataDescMap(CTriggerGravity *this)
{
  return &CTriggerGravity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C820
// Name: public: virtual struct datamap_t __near * CAI_ChangeTarget::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_ChangeTarget::GetDataDescMap(CAI_ChangeTarget *this)
{
  return &CAI_ChangeTarget::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C830
// Name: public: virtual struct datamap_t __near * CAI_ChangeHintGroup::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_ChangeHintGroup::GetDataDescMap(CAI_ChangeHintGroup *this)
{
  return &CAI_ChangeHintGroup::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C840
// Name: public: virtual struct datamap_t __near * CTriggerCamera::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerCamera::GetDataDescMap(CTriggerCamera *this)
{
  return &CTriggerCamera::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C850
// Name: public: virtual struct ScriptClassDesc_t __near * CTriggerCamera::GetScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall CTriggerCamera::GetScriptDesc(CTriggerCamera *this)
{
  return GetScriptDesc<CTriggerCamera>();
}

//------------------------------------------------------------------------------
// Address: 0x1023C870
// Name: public: virtual int CTriggerCamera::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTriggerCamera::UpdateTransmitState(CTriggerCamera *this)
{
  if ( this->m_state == 1 )
    return CBaseEntity::SetTransmitState(this, nFlag: 8);
  else
    return CBaseEntity::SetTransmitState(this, nFlag: 16);
}

//------------------------------------------------------------------------------
// Address: 0x1023C890
// Name: public: virtual struct datamap_t __near * CTriggerCameraMultiplayer::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerCameraMultiplayer::GetDataDescMap(CTriggerCameraMultiplayer *this)
{
  return &CTriggerCameraMultiplayer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C8A0
// Name: public: virtual int CTriggerCameraMultiplayer::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTriggerCameraMultiplayer::UpdateTransmitState(CTriggerCameraMultiplayer *this)
{
  if ( this->m_bEnabled )
    return CBaseEntity::SetTransmitState(this, nFlag: 8);
  else
    return CBaseEntity::SetTransmitState(this, nFlag: 16);
}

//------------------------------------------------------------------------------
// Address: 0x1023C8C0
// Name: public: virtual float CTriggerCameraMultiplayer::MoveTime(float)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CTriggerCameraMultiplayer::MoveTime(CTriggerCameraMultiplayer *this, float flTime)
{
  return SmoothCurve(x: flTime);
}

//------------------------------------------------------------------------------
// Address: 0x1023C8E0
// Name: public: virtual struct datamap_t __near * CTriggerViewProxy::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerViewProxy::GetDataDescMap(CTriggerViewProxy *this)
{
  return &CTriggerViewProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C8F0
// Name: public: virtual int CTriggerViewProxy::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTriggerViewProxy::UpdateTransmitState(CTriggerViewProxy *this)
{
  if ( this->m_state == 1 )
    return CBaseEntity::SetTransmitState(this, nFlag: 8);
  else
    return CBaseEntity::SetTransmitState(this, nFlag: 16);
}

//------------------------------------------------------------------------------
// Address: 0x1023C910
// Name: public: virtual bool CTriggerViewProxy::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTriggerViewProxy::KeyValue(CTriggerViewProxy *this, char *szKeyName, const char *szValue)
{
  return CBaseEntity::KeyValue(this, szKeyName, szValue);
}

//------------------------------------------------------------------------------
// Address: 0x1023C920
// Name: PlayCDTrack
// Source: json
//------------------------------------------------------------------------------
void __usercall PlayCDTrack(int iTrack@<eax>)
{
  edict_t *pEdicts; // esi
  int m_fStateFlags; // ecx
  edict_t *v3; // esi
  char string[64]; // [esp+0h] [ebp-40h] BYREF

  if ( gpGlobals->pEdicts != nullptr )
  {
    pEdicts = gpGlobals->pEdicts;
    m_fStateFlags = pEdicts[1].m_fStateFlags;
    v3 = pEdicts + 1;
    if ( (m_fStateFlags & 2) == 0 )
    {
      if ( (unsigned int)(iTrack + 1) > 0x1F )
      {
        _Warning(a1: "TriggerCDAudio - Track %d out of range\n", iTrack);
      }
      else if ( iTrack == -1 )
      {
        engine->ClientCommand(this: engine, a2: v3, a3: "cd pause\n");
      }
      else
      {
        V_snprintf(pDest: string, maxLen: 64, pFormat: "cd play %3d\n", iTrack);
        engine->ClientCommand(this: engine, a2: v3, a3: string);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023C9B0
// Name: protected: virtual struct datamap_t __near * CTriggerProximity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerProximity::GetDataDescMap(CTriggerProximity *this)
{
  return &CTriggerProximity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C9C0
// Name: public: virtual struct datamap_t __near * CTriggerWind::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerWind::GetDataDescMap(CTriggerWind *this)
{
  return &CTriggerWind::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023C9D0
// Name: public: virtual bool CTriggerWind::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTriggerWind::KeyValue(CTriggerWind *this, char *szKeyName, const char *szValue)
{
  if ( szKeyName != "Speed" && _V_stricmp(s1: szKeyName, s2: "Speed") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  this->m_nSpeedBase = atoi(nptr: szValue);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1023CA20
// Name: public: virtual void CTriggerWind::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerWind::OnRestore(CTriggerWind *this)
{
  CBaseEntity::OnRestore(this);
  if ( this->m_pWindController != nullptr )
    this->m_pWindController->SetEventHandler(this: this->m_pWindController, a2: &this->m_WindCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1023CA50
// Name: public: void CTriggerWind::InputSetSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerWind::InputSetSpeed(CTriggerWind *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  if ( inputdata->value.fieldType == FIELD_INTEGER )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    this->m_bSwitch = true;
    this->m_nSpeedBase = (int)pszValue;
  }
  else
  {
    this->m_bSwitch = true;
    this->m_nSpeedBase = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023CA90
// Name: public: virtual int CTriggerWind::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTriggerWind::DrawDebugTextOverlays(CTriggerWind *this)
{
  int result; // eax
  int v3; // edi
  int v4; // edi
  char tempstr[256]; // [esp+1Ch] [ebp-100h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Dir: %i (%i)", this->m_nDirCurrent, this->m_nDirTarget);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Speed: %i (%i)", this->m_nSpeedCurrent, this->m_nSpeedTarget);
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v4 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023CB70
// Name: public: virtual struct datamap_t __near * CTriggerHierarchy::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerHierarchy::GetDataDescMap(CTriggerHierarchy *this)
{
  return &CTriggerHierarchy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023CB80
// Name: public: virtual struct datamap_t __near * CTriggerImpact::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerImpact::GetDataDescMap(CTriggerImpact *this)
{
  return &CTriggerImpact::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023CB90
// Name: public: void CTriggerImpact::InputSetMagnitude(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerImpact::InputSetMagnitude(CTriggerImpact *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_flMagnitude) = inputdata->value.iVal;
  else
    this->m_flMagnitude = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1023CBC0
// Name: public: virtual class ServerClass __near * CTriggerPlayerMovement::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTriggerPlayerMovement::GetServerClass(CTriggerPlayerMovement *this)
{
  return &g_CTriggerPlayerMovement_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1023CBD0
// Name: public: virtual struct datamap_t __near * CTriggerPlayerMovement::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerPlayerMovement::GetDataDescMap(CTriggerPlayerMovement *this)
{
  return &CTriggerPlayerMovement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023CBE0
// Name: public: virtual class ServerClass __near * CBaseVPhysicsTrigger::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseVPhysicsTrigger::GetServerClass(CBaseVPhysicsTrigger *this)
{
  return &g_CBaseVPhysicsTrigger_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1023CBF0
// Name: public: bool CTriggerVPhysicsMotion::HasAngularScale(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTriggerVPhysicsMotion::HasAngularScale(CTriggerVPhysicsMotion *this)
{
  return this->m_angularScale != 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1023CC10
// Name: public: virtual struct datamap_t __near * CTriggerVPhysicsMotion::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerVPhysicsMotion::GetDataDescMap(CTriggerVPhysicsMotion *this)
{
  return &CTriggerVPhysicsMotion::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023CC20
// Name: public: virtual void CTriggerVPhysicsMotion::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerVPhysicsMotion::Precache(CTriggerVPhysicsMotion *this)
{
  if ( this->m_ParticleTrail.m_strMaterialName.pszValue != nullptr )
    PrecacheMaterial(pMaterialName: this->m_ParticleTrail.m_strMaterialName.pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x1023CC40
// Name: public: float CTriggerVPhysicsMotion::LinearLimit(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTriggerVPhysicsMotion::LinearLimit(CTriggerVPhysicsMotion *this)
{
  float m_linearLimitTime; // xmm1_4
  float v2; // xmm0_4

  m_linearLimitTime = this->m_linearLimitTime;
  if ( m_linearLimitTime == 0.0 )
    return this->m_linearLimit;
  v2 = gpGlobals->curtime - this->m_linearLimitStartTime;
  if ( v2 >= m_linearLimitTime )
  {
    this->m_linearLimitTime = 0.0;
    return this->m_linearLimit;
  }
  return (float)((float)((float)(this->m_linearLimit - this->m_linearLimitStart) * (float)(v2 / m_linearLimitTime))
               + this->m_linearLimitStart);
}

//------------------------------------------------------------------------------
// Address: 0x1023CCB0
// Name: public: virtual void CTriggerVPhysicsMotion::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerVPhysicsMotion::OnRestore(CTriggerVPhysicsMotion *this)
{
  CBaseEntity::OnRestore(this);
  if ( this->m_pController != nullptr )
    this->m_pController->SetEventHandler(this: this->m_pController, a2: &this->IMotionEvent);
}

//------------------------------------------------------------------------------
// Address: 0x1023CCE0
// Name: public: void CTriggerVPhysicsMotion::InputSetVelocityLimitTime(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerVPhysicsMotion::InputSetVelocityLimitTime(CTriggerVPhysicsMotion *this, inputdata_t *inputdata)
{
  float m_linearLimitTime; // xmm1_4
  float m_linearLimit; // xmm0_4
  float v5; // xmm0_4
  variant_t *p_value; // ecx
  const char *iVal; // eax
  float args[2]; // [esp+0h] [ebp-8h] BYREF

  m_linearLimitTime = this->m_linearLimitTime;
  if ( m_linearLimitTime == 0.0 )
  {
    m_linearLimit = this->m_linearLimit;
  }
  else
  {
    v5 = gpGlobals->curtime - this->m_linearLimitStartTime;
    if ( v5 < m_linearLimitTime )
    {
      m_linearLimit = (float)((float)(this->m_linearLimit - this->m_linearLimitStart) * (float)(v5 / m_linearLimitTime))
                    + this->m_linearLimitStart;
    }
    else
    {
      m_linearLimit = this->m_linearLimit;
      this->m_linearLimitTime = 0.0;
    }
  }
  this->m_linearLimitStart = m_linearLimit;
  p_value = &inputdata->value;
  this->m_linearLimitStartTime = gpGlobals->curtime;
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
  UTIL_StringToFloatArray(pVector: args, count: 2, pString: iVal);
  this->m_linearLimit = args[0];
  this->m_linearLimitTime = args[1];
}

//------------------------------------------------------------------------------
// Address: 0x1023CDC0
// Name: public: virtual struct datamap_t __near * CTriggerAutoCrouch::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerAutoCrouch::GetDataDescMap(CTriggerAutoCrouch *this)
{
  return &CTriggerAutoCrouch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1023CEA0
// Name: public: virtual void CBaseTrigger::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::UpdateOnRemove(CBaseTrigger *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->RemoveTrigger(this: m_pPhysicsObject);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023CEC0
// Name: public: virtual void CBaseTrigger::PostClientActive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::PostClientActive(CBaseTrigger *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  if ( !this->m_bDisabled.m_Value )
    CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1023CEE0
// Name: public: virtual void CTriggerMultiple::ActivateMultiTrigger(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerMultiple::ActivateMultiTrigger(CTriggerMultiple *this, CBaseEntity *pActivator)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  if ( CBaseEntity::GetNextThink(this, szContext: nullptr) <= gpGlobals->curtime )
  {
    if ( pActivator != nullptr )
      this->m_hActivator.m_Index = pActivator->GetRefEHandle(this: pActivator)->m_Index;
    else
      this->m_hActivator.m_Index = -1;
    m_Index = this->m_hActivator.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    COutputEvent::FireOutput(this: &this->m_OnTrigger, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
    if ( this->m_flWait <= 0.0 )
    {
      this->m_pfnTouch = nullptr;
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
      CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
    }
    else
    {
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CTriggerMultiple::MultiWaitOver,
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + this->m_flWait, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D000
// Name: public: virtual bool CChangeLevel::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChangeLevel::KeyValue(CChangeLevel *this, const char *szKeyName, const char *szValue)
{
  if ( szKeyName != "map" && _V_stricmp(s1: szKeyName, s2: "map") != 0 )
  {
    if ( szKeyName != "landmark" && _V_stricmp(s1: szKeyName, s2: "landmark") != 0 )
    {
      return CBaseToggle::KeyValue(this, szKeyName, szValue);
    }
    else
    {
      if ( strlen(szValue) >= 0x20 )
        _Warning(a1: "Landmark name '%s' too long (32 chars)\n", szValue);
      V_strncpy(pDest: this->m_szLandmarkName, pSrc: szValue, maxLen: 32);
      return true;
    }
  }
  else
  {
    if ( strlen(szValue) >= 0x20 )
      _Warning(a1: "Map name '%s' too long (32 chars)\n", szValue);
    V_strncpy(pDest: this->m_szMapName, pSrc: szValue, maxLen: 32);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D0E0
// Name: private: static class CBaseEntity __near * CChangeLevel::FindLandmark(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl CChangeLevel::FindLandmark(const char *pLandmarkName)
{
  CBaseEntity *EntityByName; // esi

  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pLandmarkName,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
  {
    while ( EntityByName->m_iClassname.pszValue != "info_landmark"
         && CBaseEntity::ClassMatchesComplex(this: EntityByName, pszClassOrWildcard: "info_landmark") == 0 )
    {
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: EntityByName,
                       szName: pLandmarkName,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      if ( EntityByName == nullptr )
        goto LABEL_5;
    }
    return EntityByName;
  }
  else
  {
LABEL_5:
    _Warning(a1: "Can't find landmark %s\n", pLandmarkName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D160
// Name: private: static int CChangeLevel::AddTransitionToList(struct levellist_t __near *,int,char const __near *,char const __near *,struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CChangeLevel::AddTransitionToList(
        levellist_t *pLevelList,
        int listCount,
        const char *pMapName,
        const char *pLandmarkName,
        edict_t *pentLandmark)
{
  edict_t *v5; // edi
  const char *pszValue; // eax
  int v8; // ebx
  levellist_t *v9; // edi
  levellist_t *v10; // esi
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v12; // edi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( pLevelList == nullptr )
    return 0;
  if ( pMapName == nullptr )
    return 0;
  if ( pLandmarkName == nullptr )
    return 0;
  v5 = pentLandmark;
  if ( pentLandmark == nullptr )
    return 0;
  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( _V_stricmp(s1: pMapName, s2: pszValue) == 0 )
    return 0;
  v8 = 0;
  if ( listCount <= 0 )
  {
LABEL_15:
    v10 = &pLevelList[listCount];
    V_strncpy(pDest: v10->mapName, pSrc: pMapName, maxLen: 32);
    V_strncpy(pDest: v10->landmarkName, pSrc: pLandmarkName, maxLen: 32);
    v10->pentLandmark = v5;
    m_pUnk = v5->m_pUnk;
    if ( m_pUnk != nullptr )
      v12 = m_pUnk->GetBaseEntity(this: m_pUnk);
    else
      v12 = nullptr;
    if ( (v12->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v12, a2: (int)&savedregs);
    v10->vecLandmarkOrigin.x = v12->m_vecAbsOrigin.x;
    v10->vecLandmarkOrigin.y = v12->m_vecAbsOrigin.y;
    v10->vecLandmarkOrigin.z = v12->m_vecAbsOrigin.z;
    return 1;
  }
  else
  {
    v9 = pLevelList;
    while ( v9->pentLandmark != pentLandmark || _V_stricmp(s1: v9->mapName, s2: pMapName) != 0 )
    {
      ++v8;
      ++v9;
      if ( v8 >= listCount )
      {
        v5 = pentLandmark;
        goto LABEL_15;
      }
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D260
// Name: private: static int CChangeLevel::ComputeEntitySaveFlags(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CChangeLevel::ComputeEntitySaveFlags(CBaseEntity *pEntity)
{
  const char *pszValue; // edi
  const char *DebugName; // eax
  int v3; // eax
  int v5; // edi

  if ( g_iDebuggingTransition == 2 )
  {
    pszValue = pEntity->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    DebugName = CBaseEntity::GetDebugName(this: pEntity);
    _Msg(a1: "Trying %s (%s): ", pszValue, DebugName);
  }
  v3 = pEntity->ObjectCaps(this: pEntity);
  if ( v3 >= 0 )
  {
    v5 = 0;
    if ( (v3 & 0x80u) != 0 )
      v5 = 0x20000000;
    if ( pEntity->m_iGlobalname.pszValue != nullptr && !CBaseEntity::IsDormant(this: pEntity) )
      v5 |= 0x10000000u;
    if ( g_iDebuggingTransition == 2 && v5 == 0 )
      _Msg(a1: "IGNORED, no across_transition flag & no globalname\n");
    return v5;
  }
  else
  {
    if ( g_iDebuggingTransition == 2 )
      _Msg(a1: "IGNORED due to being marked \"Don't save\".\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D310
// Name: public: void CTriggerPush::InputSetPushDirection(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerPush::InputSetPushDirection(CTriggerPush *this, inputdata_t *inputdata)
{
  _fieldtypes fieldType; // ecx
  Vector *p_m_vecPushDir; // esi
  Vector vecAbsDir; // [esp+8h] [ebp-18h] BYREF
  QAngle angPushDir; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  fieldType = inputdata->value.fieldType;
  p_m_vecPushDir = &this->m_vecPushDir;
  if ( fieldType == FIELD_VECTOR || fieldType == FIELD_POSITION_VECTOR )
  {
    p_m_vecPushDir->x = inputdata->value.flVal;
    this->m_vecPushDir.y = inputdata->value.vecVal[1];
    this->m_vecPushDir.z = inputdata->value.vecVal[2];
  }
  else
  {
    p_m_vecPushDir->x = vec3_origin.x;
    this->m_vecPushDir.y = vec3_origin.y;
    this->m_vecPushDir.z = vec3_origin.z;
  }
  angPushDir.x = p_m_vecPushDir->x;
  angPushDir.y = this->m_vecPushDir.y;
  angPushDir.z = this->m_vecPushDir.z;
  AngleVectors(angles: &angPushDir, forward: &vecAbsDir);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  VectorIRotate(in1: &vecAbsDir.x, in2: &this->m_rgflCoordinateFrame, out: &this->m_vecPushDir.x);
}

//------------------------------------------------------------------------------
// Address: 0x1023D3D0
// Name: public: virtual void CTriggerPush::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerPush::DrawDebugGeometryOverlays(CTriggerPush *this)
{
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  float *v3; // eax
  CTriggerPush_vtbl *v4; // edx
  float v5; // xmm0_4
  const Vector *(__thiscall *v6)(CBaseEntity *); // eax
  const Vector *v7; // eax
  Vector endPos; // [esp+20h] [ebp-24h] BYREF
  Vector vecAbsDir; // [esp+2Ch] [ebp-18h] BYREF
  float v10; // [esp+38h] [ebp-Ch]
  float v11; // [esp+3Ch] [ebp-8h]
  float v12; // [esp+40h] [ebp-4h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  CBaseEntity::DrawDebugGeometryOverlays(this);
  if ( (this->m_debugOverlays & 4) != 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    VectorRotate(in1: &this->m_vecPushDir.x, in2: &this->m_rgflCoordinateFrame, out: &vecAbsDir.x);
    WorldSpaceCenter = this->WorldSpaceCenter;
    v10 = vecAbsDir.x * 100.0;
    v11 = vecAbsDir.y * 100.0;
    v12 = vecAbsDir.z * 100.0;
    v3 = (float *)WorldSpaceCenter(this);
    v4 = this->__vftable;
    endPos.x = *v3 + v10;
    endPos.y = v3[1] + v11;
    v5 = v3[2] + v12;
    v6 = v4->WorldSpaceCenter;
    endPos.z = v5;
    v7 = v6(this);
    NDebugOverlay::VertArrow(
      startPos: v7,
      &endPos,
      width: 10.0,
      r: 255,
      g: 0,
      b: 255,
      a: 0,
      noDepthTest: true,
      flDuration: 0.1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D4D0
// Name: public: void CTriggerTeleport::InputSetTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerTeleport::InputSetTarget(CTriggerTeleport *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  this->m_target.pszValue = iVal;
}

//------------------------------------------------------------------------------
// Address: 0x1023D510
// Name: public: void CTriggerGravity::GravityTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerGravity::GravityTouch(CTriggerGravity *this, CBaseEntity *pOther)
{
  if ( pOther->IsPlayer(this: pOther) )
    pOther->m_flGravity = this->m_flGravity;
}

//------------------------------------------------------------------------------
// Address: 0x1023D540
// Name: public: void CAI_ChangeTarget::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ChangeTarget::InputActivate(CAI_ChangeTarget *this, inputdata_t *inputdata)
{
  CBaseEntity *v3; // esi
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  CBaseEntity_vtbl *v6; // edx
  int v7; // eax

  v3 = nullptr;
  while ( 1 )
  {
    pszValue = this->m_target.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: v3,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: inputdata->pActivator,
                     pCaller: inputdata->pCaller,
                     pFilter: nullptr);
    v3 = EntityByName;
    if ( EntityByName == nullptr )
      break;
    v6 = EntityByName->__vftable;
    EntityByName->m_target.pszValue = this->m_iszNewTarget.pszValue;
    v7 = (int)v6->MyNPCPointer(this: EntityByName);
    if ( v7 != 0 )
      *(_DWORD *)(v7 + 2792) = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D5B0
// Name: public: virtual bool CTriggerCamera::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTriggerCamera::KeyValue(CTriggerCamera *this, char *szKeyName, const char *szValue)
{
  if ( szKeyName != "wait" && _V_stricmp(s1: szKeyName, s2: "wait") != 0 )
  {
    if ( szKeyName != "moveto" && _V_stricmp(s1: szKeyName, s2: "moveto") != 0 )
    {
      if ( szKeyName != "acceleration" && _V_stricmp(s1: szKeyName, s2: "acceleration") != 0 )
      {
        if ( szKeyName != "deceleration" && _V_stricmp(s1: szKeyName, s2: "deceleration") != 0 )
        {
          return CBaseEntity::KeyValue(this, szKeyName, szValue);
        }
        else
        {
          this->m_deceleration = atof(nptr: szValue);
          return true;
        }
      }
      else
      {
        this->m_acceleration = atof(nptr: szValue);
        return true;
      }
    }
    else
    {
      this->m_sPath.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&szValue).pszValue;
      return true;
    }
  }
  else
  {
    this->m_flWait = atof(nptr: szValue);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D6B0
// Name: public: void CTriggerCamera::InputSetTrackSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::InputSetTrackSpeed(CTriggerCamera *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_trackSpeed) = inputdata->value.iVal;
  else
    this->m_trackSpeed = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1023D6E0
// Name: public: int CTriggerCamera::ScriptGetFov(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTriggerCamera::ScriptGetFov(CTriggerCamera *this)
{
  unsigned int m_Index; // ecx
  int v2; // eax
  CEntInfo *v3; // edx
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CBasePlayer **v7; // eax

  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index == -1 )
    return 0;
  v2 = (unsigned __int16)m_Index;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v4 = HIWORD(m_Index);
  if ( v3->m_SerialNumber != v4 || v3->m_pEntity == nullptr )
    return 0;
  v5 = v2;
  v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4;
  v7 = (CBasePlayer **)&g_pEntityList->m_EntPtrArray[v5];
  if ( v6 )
    return CBasePlayer::GetFOV(this: *v7);
  else
    return CBasePlayer::GetFOV(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1023D740
// Name: public: void CTriggerCamera::ScriptSetFov(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::ScriptSetFov(CTriggerCamera *this, int iFOV, float fovSpeed)
{
  unsigned int m_Index; // eax
  unsigned int v4; // eax
  CBasePlayer *m_pEntity; // edx

  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    this->m_fov = (float)iFOV;
    this->m_fovSpeed = fovSpeed;
    v4 = this->m_hPlayer.m_Index;
    if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
    CBasePlayer::SetFOV(this: m_pEntity, pRequester: this, FOV: iFOV, zoomRate: fovSpeed, iZoomStart: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D7E0
// Name: public: void CTriggerCamera::StartCameraShot(char const __near *,class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::StartCameraShot(
        CTriggerCamera *this,
        const char *pszShotType,
        CBaseEntity *pSceneEntity,
        CBaseEntity *pActor1,
        CBaseEntity *pActor2,
        float duration)
{
  HSCRIPT__ *ScriptInstance; // edi
  HSCRIPT__ *v8; // esi
  HSCRIPT__ *v9; // eax
  HSCRIPT__ *pActor2a; // [esp+2Ch] [ebp+14h]

  ScriptInstance = nullptr;
  if ( this->m_iszVScripts.pszValue != nullptr )
  {
    v8 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: "ScriptStartCameraShot", a3: this->m_ScriptScope.m_hScope);
    if ( v8 != nullptr )
    {
      if ( pActor2 != nullptr )
        pActor2a = CBaseEntity::GetScriptInstance(this: pActor2);
      else
        pActor2a = nullptr;
      if ( pActor1 != nullptr )
        ScriptInstance = CBaseEntity::GetScriptInstance(this: pActor1);
      if ( pSceneEntity != nullptr )
        v9 = CBaseEntity::GetScriptInstance(this: pSceneEntity);
      else
        v9 = nullptr;
      IScriptVM::Call<char const *,HSCRIPT__ *,HSCRIPT__ *,HSCRIPT__ *,float>(
        this: g_pScriptVM,
        hFunction: v8,
        hScope: this->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 ? this->m_ScriptScope.m_hScope : nullptr,
        bWait: true,
        pReturn: nullptr,
        arg1: pszShotType,
        arg2: v9,
        arg3: ScriptInstance,
        arg4: pActor2a,
        arg5: duration);
      g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D8A0
// Name: public: virtual void CTriggerWind::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerWind::StartTouch(CTriggerWind *this, CBaseEntity *pOther)
{
  IPhysicsObject *m_pPhysicsObject; // esi

  if ( this->PassesTriggerFilters(this, a2: pOther) && !pOther->IsPlayer(this: pOther) )
  {
    m_pPhysicsObject = pOther->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      this->m_pWindController->AttachObject(this: this->m_pWindController, a2: m_pPhysicsObject, a3: false);
      m_pPhysicsObject->Wake(this: m_pPhysicsObject);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D900
// Name: public: virtual void CTriggerWind::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerWind::EndTouch(CTriggerWind *this, CBaseEntity *pOther)
{
  if ( this->PassesTriggerFilters(this, a2: pOther)
    && !pOther->IsPlayer(this: pOther)
    && pOther->m_pPhysicsObject != nullptr
    && this->m_pWindController != nullptr )
  {
    this->m_pWindController->DetachObject(this: this->m_pWindController, a2: pOther->m_pPhysicsObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D950
// Name: public: void CTriggerWind::WindThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTriggerWind::WindThink(CTriggerWind *this@<ecx>, int a2@<esi>)
{
  int m_nSpeedNoise; // eax
  int m_nSpeedCurrent; // ecx
  int m_nSpeedTarget; // edi
  char v6; // bl
  float v7; // xmm0_4
  __int64 v8; // rax
  int m_nHoldNoise; // eax
  bool v10; // zf
  float value; // [esp+8h] [ebp-14h]

  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CTriggerWind::WindThink,
    thinkTime: gpGlobals->curtime + 0.1,
    szContext: "WindThinkContext");
  if ( this->m_bSwitch )
  {
    m_nSpeedNoise = this->m_nSpeedNoise;
    this->m_bSwitch = false;
    this->m_nSpeedTarget = this->m_nSpeedBase + random->RandomInt(this: random, a2: -m_nSpeedNoise, a3: m_nSpeedNoise);
    this->m_nDirTarget = (int)(float)((float)(unsigned __int16)(int)(float)((float)(this->m_nDirBase
                                                                                  + random->RandomInt(
                                                                                      this: random,
                                                                                      a2: -this->m_nDirNoise,
                                                                                      a3: this->m_nDirNoise))
                                                                          * 182.04445)
                                    * 0.0054931641);
  }
  else
  {
    m_nSpeedCurrent = this->m_nSpeedCurrent;
    m_nSpeedTarget = this->m_nSpeedTarget;
    v6 = 1;
    if ( (float)(int)abs32(m_nSpeedTarget - m_nSpeedCurrent) > 5.0 )
    {
      if ( m_nSpeedTarget <= m_nSpeedCurrent )
        v7 = -5.0;
      else
        v7 = 5.0;
      this->m_nSpeedCurrent = (int)(float)((float)m_nSpeedCurrent + v7);
      v6 = 0;
    }
    v8 = this->m_nDirTarget - this->m_nDirCurrent;
    if ( (float)(int)((HIDWORD(v8) ^ v8) - HIDWORD(v8)) <= 5.0 )
    {
      if ( v6 != 0 )
      {
        m_nHoldNoise = this->m_nHoldNoise;
        this->m_nSpeedCurrent = m_nSpeedTarget;
        value = ((double (__thiscall *)(_DWORD, _DWORD, _DWORD))random->RandomFloat)(
                  a1: random,
                  a2: (float)-m_nHoldNoise,
                  a3: (float)m_nHoldNoise)
              + (double)this->m_nHoldBase;
        CBaseEntity::ThinkSet(
          this,
          func: (void (__thiscall *)(CBaseEntity *))CTriggerWind::WindThink,
          thinkTime: value,
          szContext: "WindThinkContext");
        this->m_bSwitch = true;
      }
    }
    else
    {
      this->m_nDirCurrent = (int)ApproachAngle(
                                   target: (float)this->m_nDirTarget,
                                   value: (float)this->m_nDirCurrent,
                                   speed: 5.0);
    }
  }
  if ( this->m_nSpeedCurrent != 0 )
    ((void (__thiscall *)(IPhysicsMotionController *, int))this->m_pWindController->WakeObjects)(
      a1: this->m_pWindController,
      a2);
  v10 = !this->m_bDisabled.m_Value;
  this->m_WindCallback.m_nWindYaw = this->m_nDirCurrent;
  if ( v10 )
    this->m_WindCallback.m_flWindSpeed = (float)this->m_nSpeedCurrent;
  else
    this->m_WindCallback.m_flWindSpeed = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1023DC70
// Name: public: bool CTriggerVPhysicsMotion::HasLinearLimit(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTriggerVPhysicsMotion::HasLinearLimit(CTriggerVPhysicsMotion *this)
{
  float m_linearLimitTime; // xmm1_4
  float m_linearLimit; // xmm0_4
  float v3; // xmm0_4

  m_linearLimitTime = this->m_linearLimitTime;
  if ( m_linearLimitTime == 0.0 )
  {
    m_linearLimit = this->m_linearLimit;
  }
  else
  {
    v3 = gpGlobals->curtime - this->m_linearLimitStartTime;
    if ( v3 < m_linearLimitTime )
    {
      m_linearLimit = (float)((float)(this->m_linearLimit - this->m_linearLimitStart) * (float)(v3 / m_linearLimitTime))
                    + this->m_linearLimitStart;
    }
    else
    {
      m_linearLimit = this->m_linearLimit;
      this->m_linearLimitTime = 0.0;
    }
  }
  return m_linearLimit != 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1023DCF0
// Name: public: virtual void CTriggerVPhysicsMotion::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerVPhysicsMotion::UpdateOnRemove(CTriggerVPhysicsMotion *this)
{
  IPhysicsMotionController *m_pController; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx

  m_pController = this->m_pController;
  if ( m_pController != nullptr )
  {
    physenv->DestroyMotionController(this: physenv, a2: m_pController);
    this->m_pController = nullptr;
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->RemoveTrigger(this: m_pPhysicsObject);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023DD40
// Name: public: virtual enum IMotionEvent::simresult_e CTriggerVPhysicsMotion::Simulate(class IPhysicsMotionController __near *,class IPhysicsObject __near *,float,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CTriggerVPhysicsMotion::Simulate@<eax>(
        CTriggerVPhysicsMotion *this@<ecx>,
        int a2@<esi>,
        IPhysicsMotionController *pController,
        IPhysicsObject *pObject,
        float deltaTime,
        Vector *linear,
        Vector *angular)
{
  float v10; // xmm1_4
  CTimedEventMgr *m_pEventMgr; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  double v17; // st7
  float v18; // xmm1_4
  float (__thiscall *CalculateAngularDrag)(IPhysicsObject *, const Vector *); // edx
  double v20; // st7
  float v21; // xmm0_4
  float v22; // xmm1_4
  CTriggerVPhysicsMotion *v23; // ecx
  float m_linearLimit; // xmm0_4
  float v25; // xmm0_4
  double v26; // st7
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  ServerClass *m_pServerClass; // xmm0_4
  Vector *v31; // ecx
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float x; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  Vector angVel; // [esp+4h] [ebp-3Ch] BYREF
  Vector unitAngVel; // [esp+10h] [ebp-30h] BYREF
  Vector unitVel; // [esp+1Ch] [ebp-24h] BYREF
  Vector vel; // [esp+28h] [ebp-18h] BYREF
  float angSpeed; // [esp+34h] [ebp-Ch]
  float speedScale; // [esp+38h] [ebp-8h]
  float angDrag; // [esp+3Ch] [ebp-4h]
  float flDeltaVel; // [esp+4Ch] [ebp+Ch]
  float flDeltaVela; // [esp+4Ch] [ebp+Ch]
  float linearDraga; // [esp+54h] [ebp+14h]
  float linearDrag; // [esp+54h] [ebp+14h]

  if ( *((_BYTE *)this - 12) != 0 )
    return 0;
  linear->x = 0.0;
  linear->y = 0.0;
  linear->z = 0.0;
  angular->x = 0.0;
  angular->y = 0.0;
  angular->z = 0.0;
  v10 = *(float *)&this->m_Network.m_PVSInfo.m_nHeadNode;
  if ( v10 != 1.0 )
    linear->z = linear->z - (float)((float)(v10 - 1.0) * sv_gravity.m_pParent->m_Value.m_fValue);
  if ( *(float *)&this->m_Network.m_TimerEvent.m_pEventMgr != 0.0 )
  {
    AngleVectors(angles: (const QAngle *)&this->m_Network.m_TimerEvent.m_flNextEventTime, forward: &angVel);
    m_pEventMgr = this->m_Network.m_TimerEvent.m_pEventMgr;
    linear->x = (float)(angVel.x * *(float *)&m_pEventMgr) + linear->x;
    linear->y = (float)(angVel.y * *(float *)&m_pEventMgr) + linear->y;
    linear->z = (float)(angVel.z * *(float *)&m_pEventMgr) + linear->z;
  }
  if ( *(float *)&this->m_Network.m_PVSInfo.m_pClusters != 0.0
    || CTriggerVPhysicsMotion::HasLinearLimit(this: (CTriggerVPhysicsMotion *)((char *)this - 864))
    || *(float *)&this->m_Network.m_PVSInfo.m_pClustersInline[2] != 1.0
    || *(float *)&this->m_Network.m_pServerClass != 0.0
    || CTriggerVPhysicsMotion::HasAngularScale(this: (CTriggerVPhysicsMotion *)((char *)this - 864)) )
  {
    pObject->GetVelocity(this: pObject, a2: &vel, a3: &angVel);
    y = linear->y;
    z = linear->z;
    vel.x = (float)(linear->x * deltaTime) + vel.x;
    vel.y = vel.y + (float)(y * deltaTime);
    vel.z = vel.z + (float)(z * deltaTime);
    unitVel = vel;
    unitAngVel = angVel;
    flDeltaVel = VectorNormalize(vec: &unitVel);
    angSpeed = VectorNormalize(vec: &unitAngVel);
    v15 = 0.0;
    v16 = 0.0;
    if ( *(float *)&this->m_Network.m_PVSInfo.m_pClusters != 0.0 )
    {
      v17 = ((double (__thiscall *)(IPhysicsObject *, Vector *, int))pObject->CalculateLinearDrag)(
              a1: pObject,
              a2: &unitVel,
              a3: a2)
          * (*(float *)&this->m_Network.m_PVSInfo.m_pClusters
           * -0.5)
          * deltaTime;
      if ( v17 >= -1.0 )
      {
        linearDraga = v17;
        v18 = linearDraga;
      }
      else
      {
        v18 = -1.0;
      }
      CalculateAngularDrag = pObject->CalculateAngularDrag;
      speedScale = (float)(1.0 / deltaTime) * v18;
      v20 = ((double (__thiscall *)(IPhysicsObject *, Vector *))CalculateAngularDrag)(a1: pObject, a2: &unitAngVel)
          * (*(float *)&this->m_Network.m_PVSInfo.m_pClusters
           * -0.5)
          * deltaTime;
      angDrag = v20;
      if ( v20 >= -1.0 )
        v21 = angDrag;
      else
        v21 = -1.0;
      v15 = speedScale;
      v16 = (float)(1.0 / deltaTime) * v21;
    }
    v22 = this->m_Network.m_PVSInfo.m_vCenter[1];
    v23 = (CTriggerVPhysicsMotion *)((char *)this - 864);
    if ( v22 == 0.0 )
    {
      m_linearLimit = v23->m_linearLimit;
    }
    else
    {
      v25 = gpGlobals->curtime - v23->m_linearLimitStartTime;
      if ( v25 < v22 )
      {
        m_linearLimit = (float)((float)(v23->m_linearLimit - v23->m_linearLimitStart) * (float)(v25 / v22))
                      + v23->m_linearLimitStart;
      }
      else
      {
        m_linearLimit = v23->m_linearLimit;
        v23->m_linearLimitTime = 0.0;
      }
    }
    if ( m_linearLimit != 0.0 && flDeltaVel > *(float *)&this->m_Network.m_PVSInfo.m_nAreaNum )
    {
      linearDrag = 1.0 / deltaTime;
      v26 = CTriggerVPhysicsMotion::LinearLimit(this: v23);
      v27 = this->m_Network.m_PVSInfo.m_vCenter[0];
      flDeltaVela = (v26 - flDeltaVel) * linearDrag;
      v28 = flDeltaVela;
      if ( v27 != 0.0 )
      {
        LODWORD(v29) = COERCE_UNSIGNED_INT(v27 * linearDrag) ^ _mask__NegFloat_;
        if ( v29 > flDeltaVela )
          v28 = v29;
      }
      linear->x = (float)(unitVel.x * v28) + linear->x;
      linear->y = (float)(unitVel.y * v28) + linear->y;
      linear->z = (float)(unitVel.z * v28) + linear->z;
    }
    m_pServerClass = this->m_Network.m_pServerClass;
    if ( *(float *)&m_pServerClass == 0.0 || angSpeed <= *(float *)&m_pServerClass )
    {
      v31 = angular;
    }
    else
    {
      v31 = angular;
      v32 = (float)(*(float *)&m_pServerClass - angSpeed) / deltaTime;
      v33 = (float)(unitAngVel.z * v32) + angular->z;
      v34 = unitAngVel.y * v32;
      angular->x = angular->x + (float)(unitAngVel.x * v32);
      angular->y = angular->y + v34;
      angular->z = v33;
    }
    v35 = *(float *)&this->m_Network.m_PVSInfo.m_pClustersInline[2];
    if ( v35 != 1.0 )
      v15 = (float)((float)(v15 + 1.0) * v35) - 1.0;
    v36 = *(float *)&this->m_Network.m_hParent.m_Index;
    if ( v36 != 1.0 )
      v16 = (float)((float)(v16 + 1.0) * v36) - 1.0;
    v37 = vel.z;
    v38 = linear->x + (float)(vel.x * v15);
    x = angVel.x;
    linear->y = linear->y + (float)(vel.y * v15);
    v40 = linear->z;
    linear->x = v38;
    v41 = v40 + (float)(v37 * v15);
    v42 = angVel.y;
    linear->z = v41;
    v43 = v31->x + (float)(x * v16);
    v44 = (float)(angVel.z * v16) + v31->z;
    v45 = v31->y + (float)(v42 * v16);
    v31->x = v43;
    v31->y = v45;
    v31->z = v44;
  }
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1023E270
// Name: public: virtual enum IMotionEvent::simresult_e CPhysicsWind::Simulate(class IPhysicsMotionController __near *,class IPhysicsObject __near *,float,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsWind::Simulate(
        CPhysicsWind *this,
        IPhysicsMotionController *pController,
        IPhysicsObject *pObject,
        float deltaTime,
        Vector *linear,
        Vector *angular)
{
  __m128 curtime_low; // xmm1
  double v9; // xmm0_8
  __m128 v10; // xmm0
  double v11; // xmm0_8
  float v12; // xmm2_4
  float m_flWindSpeed; // xmm3_4
  Vector vWind; // [esp+4h] [ebp-18h] BYREF
  QAngle vWindAngle; // [esp+10h] [ebp-Ch] BYREF
  float pObjecta; // [esp+28h] [ebp+Ch]

  if ( this->m_flWindSpeed == 0.0 )
    return 0;
  vWindAngle = vec3_angle;
  curtime_low = (__m128)LODWORD(gpGlobals->curtime);
  pObjecta = (float)((int)pObject % 15 + 5);
  curtime_low.m128_f32[0] = (float)(curtime_low.m128_f32[0] + 1.0) * pObjecta;
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(curtime_low));
  *(float *)&v9 = v9;
  vWindAngle.y = (float)(*(float *)&v9 * 30.0) + (float)this->m_nWindYaw;
  AngleVectors(angles: &vWindAngle, forward: &vWind);
  v10 = (__m128)LODWORD(gpGlobals->curtime);
  v10.m128_f32[0] = (float)(v10.m128_f32[0] + 1.0) * pObjecta;
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v10));
  *(float *)&v11 = v11;
  curtime_low.m128_f32[0] = *(float *)&v11 + 1.1;
  v12 = vWind.y * 3.0;
  m_flWindSpeed = this->m_flWindSpeed;
  linear->x = (float)(vWind.x * 3.0) * m_flWindSpeed;
  linear->y = m_flWindSpeed * v12;
  linear->z = (float)(curtime_low.m128_f32[0] * 3.0) * m_flWindSpeed;
  *angular = vec3_origin;
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x1023E3E0
// Name: public: static bool CMemberScriptBinding0<class CTriggerCamera __near *,int (CTriggerCamera::*)(void),int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding0<CTriggerCamera *,int (__thiscall CTriggerCamera::*)(void),int>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext == nullptr )
    return 0;
  pReturn->m_int = pFunction();
  pReturn->m_type = 5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023E410
// Name: public: static bool CMemberScriptBinding2<class CTriggerCamera __near *,void (CTriggerCamera::*)(int,float),void,int,float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CTriggerCamera *,void (__thiscall CTriggerCamera::*)(int,float),void,int,float>::Call(
        void (__stdcall *pFunction)(int, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 2 || pReturn != nullptr || pContext == nullptr )
    return 0;
  pFunction(a1: pArguments->m_int, a2: pArguments[1].m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023E510
// Name: public: virtual void CBaseTrigger::InputTouchTest(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::InputTouchTest(CBaseTrigger *this, inputdata_t *inputdata)
{
  if ( !this->m_bDisabled.m_Value )
  {
    if ( this->m_hTouchingEntities.m_Size != 0 )
      COutputEvent::FireOutput(this: &this->m_OnTouching, pActivator: this, pCaller: this, fDelay: 0.0);
    else
      COutputEvent::FireOutput(this: &this->m_OnNotTouching, pActivator: this, pCaller: this, fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023E550
// Name: public: virtual void CBaseTrigger::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::Activate(CBaseTrigger *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  void *v4; // eax

  pszValue = this->m_iFilterName.pszValue;
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
    v4 = __RTDynamicCast(
           inptr: EntityByName,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBaseFilter `RTTI Type Descriptor',
           isReference: 0);
    if ( v4 != nullptr )
    {
      this->m_hFilter.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
      CBaseEntity::Activate(this);
      return;
    }
    this->m_hFilter.m_Index = -1;
  }
  CBaseEntity::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023E5C0
// Name: public: virtual int CBaseTrigger::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseTrigger::DrawDebugTextOverlays(CBaseTrigger *this)
{
  int result; // eax
  int v3; // esi
  char tempstr[256]; // [esp+1Ch] [ebp-100h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    if ( (this->m_Collision.m_usSolidFlags.m_Value & 8) != 0 )
      V_strncpy(pDest: tempstr, pSrc: "State: Enabled", maxLen: 255);
    else
      V_strncpy(pDest: tempstr, pSrc: "State: Disabled", maxLen: 255);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023E650
// Name: public: virtual bool CBaseTrigger::PassesTriggerFilters(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseTrigger::PassesTriggerFilters(CBaseTrigger *this, CBaseEntity *pOther)
{
  int m_Value; // eax
  CAI_BaseNPC *v5; // eax
  CAI_BaseNPC *v6; // edi
  bool v8; // al
  int v9; // eax
  unsigned int m_Index; // ecx
  CBaseFilter *m_pEntity; // eax
  bool bOtherIsPlayer_3; // [esp+17h] [ebp+Bh]

  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x40) != 0 || (m_Value & 1) != 0 && (pOther->m_fFlags.m_Value & 0x100) != 0 )
    goto LABEL_12;
  if ( (m_Value & 2) == 0 || (pOther->m_fFlags.m_Value & 0x4000) == 0 )
  {
    if ( ((m_Value & 4) == 0
       || pOther == nullptr
       || pOther->m_iClassname.pszValue != "func_pushable"
       && CBaseEntity::ClassMatchesComplex(this: pOther, pszClassOrWildcard: "func_pushable") == 0)
      && ((this->m_spawnflags.m_Value & 8) == 0 || pOther->m_MoveType.m_Value != 6) )
    {
      return false;
    }
LABEL_12:
    if ( (pOther->m_fFlags.m_Value & 0x4000) == 0 )
      goto LABEL_20;
  }
  v5 = pOther->MyNPCPointer(this: pOther);
  v6 = v5;
  if ( (this->m_spawnflags.m_Value & 0x10) != 0 && (v5 == nullptr || !v5->IsPlayerAlly(this: v5, a2: nullptr))
    || (this->m_spawnflags.m_Value & 0x800) != 0 && (v6 == nullptr || !v6->IsInAVehicle(this: v6)) )
  {
    return false;
  }
LABEL_20:
  v8 = pOther->IsPlayer(this: pOther);
  bOtherIsPlayer_3 = v8;
  if ( (this->m_spawnflags.m_Value & 0x20) != 0 && v8 )
  {
    if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *))pOther->__vftable[1].ModifyOrAppendCriteria)(a1: pOther) == 0 )
      return false;
    v9 = ((int (__thiscall *)(CBaseEntity *))pOther->__vftable[1].ModifyOrAppendDerivedCriteria)(a1: pOther);
    if ( v9 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 60))(a1: v9) != 0 )
      return false;
    v8 = bOtherIsPlayer_3;
  }
  if ( (this->m_spawnflags.m_Value & 0x200) != 0
    && v8
    && ((unsigned __int8 (__thiscall *)(CBaseEntity *))pOther->__vftable[1].ModifyOrAppendCriteria)(a1: pOther) != 0 )
  {
    return false;
  }
  m_Index = this->m_hFilter.m_Index;
  return m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || (m_pEntity = (CBaseFilter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr
      || CBaseFilter::PassesFilter(this: m_pEntity, pCaller: this, pEntity: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x1023E7F0
// Name: public: virtual void CBaseTrigger::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::InputToggle(CBaseTrigger *this, inputdata_t *inputdata)
{
  char v3; // al
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ecx

  v3 = LOBYTE(this->m_Collision.m_usSolidFlags.m_Value) >> 3;
  p_m_Collision = &this->m_Collision;
  if ( (v3 & 1) != 0 )
    CCollisionProperty::SetSolidFlags(this: p_m_Collision, flags: p_m_Collision->m_usSolidFlags.m_Value & 0xFFF7);
  else
    CCollisionProperty::SetSolidFlags(this: p_m_Collision, flags: p_m_Collision->m_usSolidFlags.m_Value | 8);
  CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1023E840
// Name: public: virtual void CTriggerLook::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerLook::Activate(CTriggerLook *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int m_Index; // eax
  const char *v5; // eax
  const char *DebugName; // eax
  const char *v7; // [esp-4h] [ebp-8h]

  CBaseTrigger::Activate(this);
  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hLookTarget.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hLookTarget.m_Index = -1;
  m_Index = this->m_hLookTarget.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    v5 = this->m_target.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    v7 = v5;
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(a1: "CTriggerLook '%s' has a bad look target (%s)\n", DebugName, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023E8F0
// Name: private: void CTriggerLook::Trigger(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerLook::Trigger(CTriggerLook *this, CBaseEntity *pActivator, bool bTimeout)
{
  if ( bTimeout )
  {
    COutputEvent::FireOutput(this: &this->m_OnTimeout, pActivator, pCaller: this, fDelay: 0.0);
    this->m_bTimeoutFired = true;
  }
  else
  {
    COutputEvent::FireOutput(this: &this->m_OnTrigger, pActivator, pCaller: this, fDelay: 0.0);
    this->m_flLookTimeTotal = -1.0;
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
  if ( (this->m_spawnflags.m_Value & 0x80) != 0 )
  {
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023E9B0
// Name: public: virtual int CTriggerLook::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTriggerLook::DrawDebugTextOverlays(CTriggerLook *this)
{
  int result; // eax
  int v3; // edi
  float m_flLookTimeTotal; // xmm0_4
  char tempstr[256]; // [esp+1Ch] [ebp-100h] BYREF

  result = CBaseTrigger::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    m_flLookTimeTotal = this->m_flLookTimeTotal;
    if ( m_flLookTimeTotal < 0.0 )
      m_flLookTimeTotal = 0.0;
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Time:   %3.2f", (float)(this->m_flLookTime - m_flLookTimeTotal));
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023EA50
// Name: public: virtual void CTriggerVolume::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerVolume::Spawn(CTriggerVolume *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+8h] [ebp-4h] BYREF

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CTriggerVolume *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  if ( showtriggers.m_pParent == nullptr || showtriggers.m_pParent->m_Value.m_nValue == 0 )
    CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x1023EAD0
// Name: public: virtual void CChangeLevel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CChangeLevel::Activate(CChangeLevel *this@<ecx>, int a2@<ebp>)
{
  CBaseEntity *Landmark; // edi

  CBaseTrigger::Activate(this);
  if ( gpGlobals->eLoadType != MapLoad_NewGame || (this->m_spawnflags.m_Value & 4) == 0 )
  {
    Landmark = CChangeLevel::FindLandmark(pLandmarkName: this->m_szLandmarkName);
    if ( Landmark != nullptr )
    {
      if ( (Landmark->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: Landmark, a2);
      if ( engine->GetClusterForOrigin(this: engine, a2: &Landmark->m_vecAbsOrigin) < 0 )
        _Warning(
          a1: "trigger_changelevel to map %s has a landmark embedded in solid!\nThis will break level transitions!\n",
          this->m_szMapName);
      if ( g_debug_transitions.m_pParent != nullptr
        && g_debug_transitions.m_pParent->m_Value.m_nValue != 0
        && CGlobalEntityList::FindEntityByClassname(
             this: &gEntList,
             pStartEntity: nullptr,
             szName: "trigger_transition") == nullptr )
      {
        _Warning(a1: "Map has no trigger_transition volumes for landmark %s\n", this->m_szLandmarkName);
      }
    }
    this->m_bTouched = false;
  }
  else
  {
    CBaseEntity::VPhysicsInitStatic(this, a2);
    CCollisionProperty::SetSolidFlags(
      this: &this->m_Collision,
      flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFF3);
    this->m_pfnTouch = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023EBB0
// Name: private: void CChangeLevel::WarnAboutActiveLead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeLevel::WarnAboutActiveLead(CChangeLevel *this)
{
  int i; // edi
  CAI_BaseNPC *v2; // esi
  CAI_BehaviorBase *m_pPrimaryBehavior; // eax
  const char *pszValue; // esi

  for ( i = 0; i < vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager); ++i )
  {
    v2 = CAI_Manager::AccessAIs(this: &g_AI_Manager)[i];
    m_pPrimaryBehavior = v2->m_pPrimaryBehavior;
    if ( m_pPrimaryBehavior != nullptr
      && __RTDynamicCast(
           inptr: m_pPrimaryBehavior,
           VfDelta: 0,
           SrcType: &CAI_BehaviorBase `RTTI Type Descriptor',
           TargetType: &CAI_LeadBehavior `RTTI Type Descriptor',
           isReference: 0) != nullptr )
    {
      pszValue = v2->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      _Warning(a1: "Entity '%s' is still actively leading\n", pszValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023EC30
// Name: private: static int CChangeLevel::BuildChangeLevelList(struct levellist_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CChangeLevel::BuildChangeLevelList(levellist_t *pLevelList, int maxList)
{
  int v2; // ebx
  CBaseEntity *EntityByClassname; // edi
  const char *v4; // eax
  const char *v5; // esi
  CBaseEntity *Landmark; // eax
  int nCount; // [esp+8h] [ebp-4h]

  v2 = 0;
  nCount = 0;
  EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                        this: &gEntList,
                        pStartEntity: nullptr,
                        szName: "trigger_changelevel");
  if ( EntityByClassname != nullptr )
  {
    while ( 1 )
    {
      v4 = (const char *)__RTDynamicCast(
                           inptr: EntityByClassname,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CChangeLevel `RTTI Type Descriptor',
                           isReference: 0);
      v5 = v4;
      if ( v4 != nullptr )
      {
        Landmark = CChangeLevel::FindLandmark(pLandmarkName: v4 + 1184);
        if ( Landmark != nullptr
          && CChangeLevel::AddTransitionToList(
               pLevelList,
               listCount: nCount,
               pMapName: v5 + 1152,
               pLandmarkName: v5 + 1184,
               pentLandmark: Landmark->m_Network.m_pPev) != 0
          && ++nCount >= maxList )
        {
          return nCount;
        }
        v2 = nCount;
      }
      EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                            this: &gEntList,
                            pStartEntity: EntityByClassname,
                            szName: "trigger_changelevel");
      if ( EntityByClassname == nullptr )
        return v2;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1023ECF0
// Name: public: virtual void CTriggerPush::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerPush::Activate(CTriggerPush *this)
{
  if ( this->m_flAlternateTicksFix == 0.0 || !CBaseEntity::IsSimulatingOnAlternateTicks() )
  {
    this->m_flPushSpeed = this->m_flSpeed;
    CBaseTrigger::Activate(this);
  }
  else
  {
    this->m_flPushSpeed = this->m_flSpeed * this->m_flAlternateTicksFix;
    CBaseTrigger::Activate(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023ED50
// Name: public: virtual void CTriggerTeleport::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTriggerTeleport::Touch(CTriggerTeleport *this@<ecx>, int a2@<edi>, CBaseEntity *pOther)
{
  bool (__thiscall *PassesTriggerFilters)(CBaseTrigger *, CBaseEntity *); // edx
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // edi
  const char *v7; // eax
  const char *v8; // ebx
  const char *v9; // eax
  CBaseEntity *v10; // ebx
  CBaseEntity *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  bool (__thiscall *IsPlayer)(CBaseEntity *); // eax
  unsigned int v15; // edx
  __int64 v16; // xmm0_8
  void (__thiscall *GetVelocity)(CBaseEntity *, Vector *, Vector *); // edx
  float z; // edx
  int m_iEFlags; // ecx
  const Vector *v20; // eax
  float v21; // xmm3_4
  matrix3x4_t pLocalLandmarkMatrix; // [esp+8h] [ebp-F4h] BYREF
  matrix3x4_t pTransformMatrix; // [esp+38h] [ebp-C4h] BYREF
  matrix3x4_t pRemoteLandmarkMatrix; // [esp+68h] [ebp-94h] BYREF
  Vector vecActivatorOrigin; // [esp+98h] [ebp-64h] BYREF
  Vector vecNewActivatorVelocity; // [esp+A4h] [ebp-58h] BYREF
  Vector vecActivatorVelocity; // [esp+B0h] [ebp-4Ch] BYREF
  Vector vecNewActivatorOrigin; // [esp+BCh] [ebp-40h] BYREF
  Vector vecPentTargetOrigin; // [esp+C8h] [ebp-34h] BYREF
  QAngle qActivatorEyeAngles; // [esp+D4h] [ebp-28h] BYREF
  CTriggerTeleport *v32; // [esp+E0h] [ebp-1Ch]
  QAngle qNewActivatorEyeAngles; // [esp+E4h] [ebp-18h] BYREF
  Vector vecLandmarkOffset; // [esp+F0h] [ebp-Ch] BYREF
  int savedregs; // [esp+FCh] [ebp+0h] BYREF

  PassesTriggerFilters = this->PassesTriggerFilters;
  v32 = this;
  if ( ((unsigned __int8 (__stdcall *)(CBaseEntity *))PassesTriggerFilters)(a1: pOther) != 0 )
  {
    pszValue = this->m_target.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: pOther,
                     pCaller: pOther,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
    {
      v9 = v32->m_iLandmark.pszValue;
      v10 = nullptr;
      memset((void *)&vecLandmarkOffset, 0, sizeof(vecLandmarkOffset));
      if ( v9 != nullptr )
      {
        v11 = CGlobalEntityList::FindEntityByName(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: v9,
                pSearchingEntity: nullptr,
                pActivator: pOther,
                pCaller: pOther,
                pFilter: nullptr);
        v10 = v11;
        if ( v11 != nullptr )
        {
          if ( (v11->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
          if ( (pOther->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: pOther, a2: (int)&savedregs);
          v12 = pOther->m_vecAbsOrigin.y - v10->m_vecAbsOrigin.y;
          v13 = pOther->m_vecAbsOrigin.z - v10->m_vecAbsOrigin.z;
          vecLandmarkOffset.x = pOther->m_vecAbsOrigin.x - v10->m_vecAbsOrigin.x;
          vecLandmarkOffset.y = v12;
          vecLandmarkOffset.z = v13;
        }
      }
      CBaseEntity::SetGroundEntity(this: pOther, ground: nullptr);
      if ( (pOther->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pOther, a2: (int)&savedregs);
      IsPlayer = pOther->IsPlayer;
      qActivatorEyeAngles = pOther->m_angAbsRotation;
      if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *, int))IsPlayer)(a1: pOther, a2) != 0 )
        qActivatorEyeAngles = *pOther->EyeAngles(this: pOther);
      v15 = (unsigned int)pOther->m_iEFlags >> 11;
      qNewActivatorEyeAngles = qActivatorEyeAngles;
      if ( (v15 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pOther, a2: (int)&savedregs);
      v16 = *(_QWORD *)&pOther->m_vecAbsOrigin.x;
      GetVelocity = pOther->GetVelocity;
      vecActivatorOrigin.z = pOther->m_vecAbsOrigin.z;
      vecNewActivatorOrigin.z = vecActivatorOrigin.z;
      *(_QWORD *)&vecActivatorOrigin.x = v16;
      *(_QWORD *)&vecNewActivatorOrigin.x = v16;
      GetVelocity(this: pOther, a2: &vecActivatorVelocity, a3: nullptr);
      vecNewActivatorVelocity = vecActivatorVelocity;
      if ( (EntityByName->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
      z = EntityByName->m_vecAbsOrigin.z;
      *(_QWORD *)&vecPentTargetOrigin.x = *(_QWORD *)&EntityByName->m_vecAbsOrigin.x;
      vecPentTargetOrigin.z = z;
      if ( v10 != nullptr )
      {
        if ( (EntityByName->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
        m_iEFlags = v10->m_iEFlags;
        pRemoteLandmarkMatrix = EntityByName->m_rgflCoordinateFrame;
        if ( (m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v10, a2: (int)&savedregs);
        MatrixInvert(in: &v10->m_rgflCoordinateFrame, out: &pLocalLandmarkMatrix);
        ConcatTransforms(in1: &pRemoteLandmarkMatrix, in2: &pLocalLandmarkMatrix, out: &pTransformMatrix);
        qNewActivatorEyeAngles = *TransformAnglesToWorldSpace(
                                    result: (QAngle *)&vecPentTargetOrigin,
                                    angles: &qActivatorEyeAngles,
                                    parentMatrix: &pTransformMatrix);
        VectorTransform(in1: &vecActivatorOrigin.x, in2: &pTransformMatrix, out: &vecNewActivatorOrigin.x);
        VectorRotate(in1: &vecActivatorVelocity.x, in2: &pTransformMatrix, out: &vecNewActivatorVelocity.x);
      }
      else
      {
        if ( pOther->IsPlayer(this: pOther) )
        {
          v20 = pOther->m_Collision.OBBMins(this: &pOther->m_Collision);
          v21 = vecPentTargetOrigin.z - v20->z;
        }
        else
        {
          v21 = vecPentTargetOrigin.z;
        }
        vecNewActivatorOrigin.x = vecPentTargetOrigin.x + vecLandmarkOffset.x;
        vecNewActivatorOrigin.y = vecPentTargetOrigin.y + vecLandmarkOffset.y;
        vecNewActivatorOrigin.z = vecLandmarkOffset.z + v21;
      }
      if ( v32->m_bUseLandmarkAngles )
      {
        if ( (EntityByName->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
        qNewActivatorEyeAngles = EntityByName->m_angAbsRotation;
      }
      ((void (__thiscall *)(CBaseEntity *, Vector *, QAngle *, Vector *))pOther->Teleport)(
        a1: pOther,
        a2: &vecNewActivatorOrigin,
        a3: &qNewActivatorEyeAngles,
        a4: &vecNewActivatorVelocity);
    }
    else
    {
      v7 = this->m_target.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
      v8 = this->m_iName.m_Value.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
      _Warning(a1: "Teleport trigger '%s' cannot find destination named '%s'!\n", v8, v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023F150
// Name: public: virtual void CTriggerSave::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerSave::Touch(CTriggerSave *this, CBaseEntity *pOther)
{
  float m_Value; // xmm0_4
  CBasePlayer *v4; // eax

  if ( pOther->IsPlayer(this: pOther) )
  {
    if ( this->m_fDangerousTimer != 0.0
      && g_ServerGameDLL.m_fAutoSaveDangerousTime != 0.0
      && g_ServerGameDLL.m_fAutoSaveDangerousTime >= gpGlobals->curtime )
    {
      m_Value = UTIL_PlayerByIndex(playerIndex: 1)->m_flDeathTime.m_Value;
      if ( m_Value == 0.0 || m_Value > gpGlobals->curtime )
        engine->ServerCommand(this: engine, a2: "autosavedangerousissafe\n");
    }
    if ( this->m_bForceNewLevelUnit )
      engine->ClearSaveDir(this: engine);
    UTIL_Remove(oldObj: this);
    if ( this->m_fDangerousTimer == 0.0 )
    {
      engine->ServerCommand(this: engine, a2: "autosave\n");
    }
    else
    {
      v4 = UTIL_PlayerByIndex(playerIndex: 1);
      if ( v4 != nullptr && v4->m_iHealth.m_Value >= this->m_minHitPoints )
      {
        engine->ServerCommand(this: engine, a2: "autosavedangerous\n");
        g_ServerGameDLL.m_fAutoSaveDangerousTime = gpGlobals->curtime + this->m_fDangerousTimer;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023F280
// Name: public: void CAI_ChangeHintGroup::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ChangeHintGroup::InputActivate(CAI_ChangeHintGroup *this, inputdata_t *inputdata)
{
  CBaseEntity *v3; // edi
  const char *pszValue; // ecx
  int m_iSearchType; // eax
  int v6; // eax
  float flRadius; // xmm0_4
  CBaseEntity *EntityInSphere; // eax
  int v9; // eax
  CAI_BaseNPC *v10; // ebx
  const char *v11; // eax
  CBaseEntity *pActivator; // [esp+1Ch] [ebp-Ch]
  CBaseEntity *pCaller; // [esp+20h] [ebp-8h]
  char *s2; // [esp+24h] [ebp-4h]

  v3 = nullptr;
LABEL_2:
  pCaller = inputdata->pCaller;
  pActivator = inputdata->pActivator;
  if ( this->m_strSearchName.pszValue != nullptr )
  {
    pszValue = this->m_strSearchName.pszValue;
    s2 = (char *)pszValue;
    goto LABEL_6;
  }
  s2 = (char *)locale;
  while ( 1 )
  {
    pszValue = s2;
LABEL_6:
    m_iSearchType = this->m_iSearchType;
    if ( m_iSearchType != 0 )
    {
      v6 = m_iSearchType - 1;
      if ( v6 != 0 )
      {
        if ( v6 != 1 )
          goto LABEL_15;
        flRadius = this->m_flRadius;
        if ( flRadius == 0.0 )
          flRadius = 3.4028235e38;
        EntityInSphere = CGlobalEntityList::FindEntityInSphere(
                           this: &gEntList,
                           pStartEntity: v3,
                           vecCenter: &this->m_vecOrigin.m_Value,
                           flRadius);
      }
      else
      {
        EntityInSphere = CGlobalEntityList::FindEntityByClassnameWithin(
                           this: &gEntList,
                           pStartEntity: v3,
                           szName: pszValue,
                           vecSrc: &this->m_vecOrigin.m_Value,
                           flRadius: this->m_flRadius);
      }
    }
    else
    {
      EntityInSphere = CGlobalEntityList::FindEntityByNameWithin(
                         this: &gEntList,
                         pStartEntity: v3,
                         szName: pszValue,
                         vecSrc: &this->m_vecOrigin.m_Value,
                         flRadius: this->m_flRadius,
                         pSearchingEntity: nullptr,
                         pActivator,
                         pCaller);
    }
    v3 = EntityInSphere;
LABEL_15:
    if ( v3 == nullptr )
      break;
    v9 = (int)v3->MyNPCPointer(this: v3);
    v10 = (CAI_BaseNPC *)v9;
    if ( v9 != 0 )
    {
      if ( this->m_iSearchType != 2 )
        goto LABEL_22;
      v11 = *(const char **)(v9 + 2992);
      if ( v11 == nullptr )
        v11 = locale;
      if ( v11 == s2 || _V_stricmp(s1: v11, s2) == 0 )
      {
LABEL_22:
        v3 = v10;
        CAI_BaseNPC::SetHintGroup(
          this: v10,
          newGroup: this->m_strNewHintGroup,
          bHintGroupNavLimiting: this->m_bHintGroupNavLimiting);
        goto LABEL_2;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023F3D0
// Name: public: CTriggerCamera::CTriggerCamera(void)
// Source: json
//------------------------------------------------------------------------------
CTriggerCamera *__thiscall CTriggerCamera::CTriggerCamera(CTriggerCamera *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CTriggerCamera_vtbl *)&CTriggerCamera::`vftable';
  this->m_hPlayer.m_Index = -1;
  this->m_hTarget.m_Index = -1;
  this->m_OnEndFollow.m_Value.iVal = 0;
  this->m_OnEndFollow.m_Value.eVal.m_Index = -1;
  this->m_OnEndFollow.m_Value.fieldType = FIELD_VOID;
  this->m_fov = 90.0;
  this->m_fovSpeed = 1.0;
  this->m_trackSpeed = 40.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1023F470
// Name: public: void CTriggerCamera::InputSetPath(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::InputSetPath(CTriggerCamera *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  CBaseEntity *EntityByName; // ecx
  float m_flSpeed; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4

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
  this->m_pPath = EntityByName;
  this->m_flStopTime = gpGlobals->curtime;
  if ( EntityByName != nullptr )
  {
    m_flSpeed = EntityByName->m_flSpeed;
    if ( m_flSpeed != 0.0 )
      this->m_targetSpeed = m_flSpeed;
    v7 = EntityByName->m_vecOrigin.m_Value.y - this->m_vecOrigin.m_Value.y;
    v8 = EntityByName->m_vecOrigin.m_Value.z - this->m_vecOrigin.m_Value.z;
    this->m_vecMoveDir.x = EntityByName->m_vecOrigin.m_Value.x - this->m_vecOrigin.m_Value.x;
    this->m_vecMoveDir.y = v7;
    this->m_vecMoveDir.z = v8;
    this->m_moveDistance = VectorNormalize(vec: &this->m_vecMoveDir);
    this->m_flStopTime = ((double (__thiscall *)(CBaseEntity *))this->m_pPath->GetDelay)(a1: this->m_pPath)
                       + gpGlobals->curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023F560
// Name: public: void CTriggerCamera::FindAttachment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::FindAttachment(CTriggerCamera *this)
{
  unsigned int m_Index; // eax
  bool v3; // zf
  unsigned int v4; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v6; // eax
  IHandleEntity *v7; // ecx
  const char *v8; // eax
  const char *pszValue; // edx
  const char *v10; // ecx
  IHandleEntity *v11; // ecx
  const char *v12; // eax
  CBaseAnimating *v13; // eax
  int v14; // eax
  const char *v15; // edx
  const char *v16; // ecx
  const char *v17; // eax
  const char *v18; // [esp-4h] [ebp-Ch]

  m_Index = this->m_hTarget.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v3 = this->m_iszTargetAttachment.pszValue == nullptr;
    this->m_iAttachmentIndex = 0;
    if ( !v3 )
    {
      v4 = this->m_hTarget.m_Index;
      if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      v3 = m_pEntity->__vftable[17].GetRefEHandle(this: m_pEntity) == nullptr;
      v6 = this->m_hTarget.m_Index;
      if ( v3 )
      {
        if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
          v7 = nullptr;
        else
          v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
        v8 = (const char *)v7[51].__vftable;
        if ( v8 == nullptr )
          v8 = locale;
        pszValue = this->m_iszTargetAttachment.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        v10 = this->m_iClassname.pszValue;
        if ( v10 == nullptr )
          v10 = locale;
        _Warning(a1: "%s tried to target an attachment (%s) on target %s, which has no model.\n", v10, pszValue, v8);
      }
      else
      {
        if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
          v11 = nullptr;
        else
          v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
        v12 = this->m_iszTargetAttachment.pszValue;
        if ( v12 == nullptr )
          v12 = locale;
        v18 = v12;
        v13 = (CBaseAnimating *)v11->__vftable[17].GetRefEHandle(this: v11);
        v14 = CBaseAnimating::LookupAttachment(this: v13, szName: v18);
        this->m_iAttachmentIndex = v14;
        if ( v14 == 0 )
        {
          v15 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget)->m_iName.m_Value.pszValue;
          if ( v15 == nullptr )
            v15 = locale;
          v16 = this->m_iszTargetAttachment.pszValue;
          if ( v16 == nullptr )
            v16 = locale;
          v17 = this->m_iClassname.pszValue;
          if ( v17 == nullptr )
            v17 = locale;
          _Warning(a1: "%s could not find attachment %s on target %s.\n", v17, v16, v15);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023F700
// Name: public: void CTriggerCamera::MoveViewTo(class QAngle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::MoveViewTo(CTriggerCamera *this, QAngle vecGoalView)
{
  unsigned int m_Index; // ecx
  float z; // eax
  float y; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float m_trackSpeed; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  QAngle vecAngVel; // [esp+4h] [ebp-18h] BYREF
  QAngle angles; // [esp+10h] [ebp-Ch] BYREF

  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    z = this->m_angRotation.m_Value.z;
    *(_QWORD *)&angles.x = *(_QWORD *)&this->m_angRotation.m_Value.x;
    y = angles.y;
    angles.z = z;
    if ( angles.y > 360.0 )
    {
      y = angles.y - 360.0;
      angles.y = angles.y - 360.0;
    }
    if ( y < 0.0 )
      angles.y = y + 360.0;
    CBaseEntity::SetLocalAngles(this, &angles);
    v6 = vecGoalView.x - this->m_angRotation.m_Value.x;
    v7 = vecGoalView.y - this->m_angRotation.m_Value.y;
    if ( v6 < -180.0 )
      v6 = v6 + 360.0;
    if ( v6 > 180.0 )
      v6 = v6 - 360.0;
    if ( v7 < -180.0 )
      v7 = v7 + 360.0;
    if ( v7 > 180.0 )
      v7 = v7 - 360.0;
    m_trackSpeed = this->m_trackSpeed;
    v9 = (float)(m_trackSpeed * v6) * gpGlobals->frametime;
    v10 = (float)(m_trackSpeed * v7) * gpGlobals->frametime;
    vecAngVel.x = v9;
    v11 = this->m_vecAngVelocity.z;
    vecAngVel.y = v10;
    vecAngVel.z = v11;
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vecAngVel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023F830
// Name: public: virtual class Vector CMoveableCamera::GetEndPos(class CHandle<class CBaseEntity>)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CMoveableCamera::GetEndPos(CMoveableCamera *this, Vector *result, CHandle<CBaseEntity> hTarget)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // esi
  float v6; // ecx
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( ((int)m_pEntity[49].__vftable & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)m_pEntity, a2: (int)&savedregs);
  v6 = *(float *)&m_pEntity[117].__vftable;
  *(_QWORD *)&result->x = *(_QWORD *)&m_pEntity[115].__vftable;
  result->z = v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023F8A0
// Name: public: void CMoveableCamera::Move(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveableCamera::Move(CMoveableCamera *this)
{
  float v2; // xmm1_4
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  float (__thiscall *MoveTime)(CMoveableCamera *, float); // eax
  float x; // xmm0_4
  unsigned int v7; // ecx
  float y; // xmm1_4
  float z; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  Vector desiredVel; // [esp+10h] [ebp-28h] BYREF
  Vector vEndPos; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector nextPos; // [esp+28h] [ebp-10h]
  float v16; // [esp+34h] [ebp-4h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  ((void (__thiscall *)(CMoveableCamera *, Vector *, unsigned int))this->GetEndPos)(
    a1: this,
    a2: &vEndPos,
    a3: this->m_hTargetEnt.m_Index);
  v2 = (float)(gpGlobals->curtime - this->m_flInterpStartTime) / this->m_flInterpTime;
  if ( v2 < 1.0 )
  {
    MoveTime = this->MoveTime;
    nextPos.x = vEndPos.x - this->m_vStartPos.x;
    nextPos.y = vEndPos.y - this->m_vStartPos.y;
    nextPos.z = vEndPos.z - this->m_vStartPos.z;
    v16 = ((double (__thiscall *)(CMoveableCamera *, _DWORD))MoveTime)(a1: this, a2: LODWORD(v2));
    x = this->m_vStartPos.x + (float)(nextPos.x * v16);
    v7 = (unsigned int)this->m_iEFlags >> 11;
    y = this->m_vStartPos.y + (float)(nextPos.y * v16);
    z = this->m_vStartPos.z + (float)(nextPos.z * v16);
    nextPos.x = x;
    nextPos.y = y;
    nextPos.z = z;
    if ( (v7 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      z = nextPos.z;
      y = nextPos.y;
      x = nextPos.x;
    }
    v10 = 1.0 / gpGlobals->frametime;
    v11 = (float)(y - this->m_vecAbsOrigin.y) * v10;
    v12 = (float)(z - this->m_vecAbsOrigin.z) * v10;
    desiredVel.x = (float)(x - this->m_vecAbsOrigin.x) * v10;
    desiredVel.y = v11;
    desiredVel.z = v12;
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &desiredVel);
  }
  else
  {
    UTIL_SetOrigin(entity: this, vecOrigin: &vEndPos, bFireTriggers: false);
    m_Index = this->m_hTargetEnt.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    CBaseEntity::SetAbsAngles(this, absAngles: (const QAngle *)&m_pEntity[178]);
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    if ( this->m_bDisableOnMoveEnd )
      this->Disable(this);
    this->m_bMovementStarted = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023FA80
// Name: public: void CTriggerCameraMultiplayer::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCameraMultiplayer::InputEnable(CTriggerCameraMultiplayer *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int m_Index; // eax
  CTriggerCameraMultiplayer_vtbl *v6; // edx

  pszValue = this->m_targetEntName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    m_Index = -1;
  v6 = this->__vftable;
  this->m_hTargetEnt.m_Index = m_Index;
  v6->Enable(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023FAE0
// Name: public: class Vector CTriggerViewProxy::GetPlayerOffset(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CTriggerViewProxy::GetPlayerOffset(CTriggerViewProxy *this, Vector *result)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CBaseEntity **v9; // eax
  CBaseEntity *v10; // edi
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm0_4
  CBaseEntity *m_pProxy; // edi
  float v15; // xmm2_4
  float v16; // xmm0_4
  unsigned int v17; // edx
  CBaseAnimating *Parent; // eax
  float v19; // xmm2_4
  float v20; // xmm0_4
  int m_nParentAttachment; // [esp-18h] [ebp-70h]
  VMatrix matRotate; // [esp+0h] [ebp-58h] BYREF
  Vector vOrigin; // [esp+40h] [ebp-18h] BYREF
  QAngle qProxyAngles; // [esp+4Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  m_Index = this->m_hPlayer.m_Index;
  *result = vec3_origin;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr && this->m_pProxy != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        v10 = *v9;
      else
        v10 = nullptr;
      if ( (v10->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v10, a2: (int)&savedregs);
      x = v10->m_vecAbsOrigin.x;
      y = v10->m_vecAbsOrigin.y;
      z = v10->m_vecAbsOrigin.z;
      m_pProxy = this->m_pProxy;
      v15 = y - this->m_vecInitialPosition.y;
      v16 = (float)(z + 64.0) - this->m_vecInitialPosition.z;
      v17 = (unsigned int)m_pProxy->m_iEFlags >> 11;
      result->x = x - this->m_vecInitialPosition.x;
      result->y = v15;
      result->z = v16;
      if ( (v17 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: m_pProxy, a2: (int)&savedregs);
      qProxyAngles = m_pProxy->m_angAbsRotation;
      if ( this->m_nParentAttachment != -1 )
      {
        m_nParentAttachment = this->m_nParentAttachment;
        Parent = (CBaseAnimating *)CBaseEntity::GetParent(this: this->m_pProxy);
        CBaseAnimating::GetAttachment(
          this: Parent,
          iAttachment: m_nParentAttachment,
          absOrigin: &vOrigin,
          absAngles: &qProxyAngles);
      }
      VMatrix::SetupMatrixOrgAngles(this: &matRotate, origin: &vec3_origin, vAngles: &qProxyAngles);
      v19 = (float)((float)((float)(result->x * matRotate.m[1][0]) + (float)(result->y * matRotate.m[1][1]))
                  + (float)(result->z * matRotate.m[1][2]))
          + matRotate.m[1][3];
      v20 = (float)((float)((float)(result->x * matRotate.m[2][0]) + (float)(result->y * matRotate.m[2][1]))
                  + (float)(result->z * matRotate.m[2][2]))
          + matRotate.m[2][3];
      result->x = (float)((float)((float)(result->y * matRotate.m[0][1]) + (float)(result->x * matRotate.m[0][0]))
                        + (float)(result->z * matRotate.m[0][2]))
                + matRotate.m[0][3];
      result->y = v19;
      result->z = v20;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023FCB0
// Name: public: virtual void CTriggerCDAudio::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCDAudio::Touch(CTriggerCDAudio *this, CBaseEntity *pOther)
{
  if ( pOther->IsPlayer(this: pOther) )
  {
    PlayCDTrack(iTrack: this->m_iHealth.m_Value);
    this->m_pfnTouch = nullptr;
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023FCF0
// Name: public: virtual void CTriggerCDAudio::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCDAudio::Use(
        CTriggerCDAudio *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        CBaseEntity *useType,
        float value)
{
  PlayCDTrack(iTrack: this->m_iHealth.m_Value);
  this->m_pfnTouch = nullptr;
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x1023FD20
// Name: public: virtual void CTriggerProximity::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerProximity::Activate(CTriggerProximity *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // eax

  CBaseTrigger::Activate(this);
  pszValue = this->m_iszMeasureTarget.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hMeasureTarget.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hMeasureTarget.m_Index = -1;
  m_Index = this->m_hMeasureTarget.m_Index;
  if ( m_Index == -1
    || (v5 = (unsigned __int16)m_Index,
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v7 = HIWORD(m_Index),
        v6->m_SerialNumber != v7)
    || v6->m_pEntity == nullptr
    || ((v8 = v5,
         v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7,
         v10 = &g_pEntityList->m_EntPtrArray[v8],
         !v9)
      ? (m_pEntity = nullptr)
      : (m_pEntity = v10->m_pEntity),
        m_pEntity[6].__vftable == nullptr) )
  {
    _Warning(a1: "TriggerProximity - Missing measure target or measure target with no origin!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023FDD0
// Name: public: void CTriggerProximity::MeasureThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerProximity::MeasureThink(CTriggerProximity *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *v9; // eax
  touchlink_t *DataObject; // eax
  unsigned int v11; // eax
  CBaseEntity **v12; // ecx
  CBaseEntity *v13; // esi
  unsigned int v14; // eax
  float *m_pEntity; // eax
  float v16; // xmm0_4
  float m_fRadius; // xmm0_4
  float thinkTime; // xmm0_4
  float v19; // [esp+20h] [ebp-2Ch]
  touchlink_t *v20; // [esp+30h] [ebp-1Ch]
  CBaseEntity *v21; // [esp+34h] [ebp-18h]
  float v22; // [esp+38h] [ebp-14h]
  touchlink_t *root; // [esp+3Ch] [ebp-10h]

  m_Index = this->m_hMeasureTarget.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v5 = HIWORD(m_Index),
        v4->m_SerialNumber == v5)
    && v4->m_pEntity != nullptr
    && ((v6 = v3, v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5,
                  v8 = &g_pEntityList->m_EntPtrArray[v6],
                  !v7)
      ? (v9 = nullptr)
      : (v9 = v8->m_pEntity),
        v9[6].__vftable != nullptr) )
  {
    v22 = this->m_fRadius + 100.0;
    v21 = nullptr;
    DataObject = (touchlink_t *)CBaseEntity::GetDataObject(this, type: 1);
    v20 = DataObject;
    if ( DataObject != nullptr )
    {
      root = DataObject->nextLink;
      if ( root != DataObject )
      {
        do
        {
          v11 = root->entityTouched.m_Index;
          if ( root->entityTouched.m_Index != -1 )
          {
            v12 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v11];
            if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber == HIWORD(v11) )
            {
              v13 = *v12;
              if ( *v12 != nullptr && this->PassesTriggerFilters(this, a2: *v12) )
              {
                v14 = this->m_hMeasureTarget.m_Index;
                if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
                  m_pEntity = nullptr;
                else
                  m_pEntity = (float *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
                v16 = v13->m_vecOrigin.m_Value.x - m_pEntity[175];
                v19 = fsqrt(
                        (float)((float)((float)(v13->m_vecOrigin.m_Value.y - m_pEntity[176])
                                      * (float)(v13->m_vecOrigin.m_Value.y - m_pEntity[176]))
                              + (float)((float)(v13->m_vecOrigin.m_Value.z - m_pEntity[177])
                                      * (float)(v13->m_vecOrigin.m_Value.z - m_pEntity[177])))
                      + (float)(v16 * v16));
                if ( v22 > v19 )
                {
                  v22 = v19;
                  v21 = v13;
                }
              }
            }
          }
          root = root->nextLink;
        }
        while ( root != v20 );
      }
    }
    m_fRadius = this->m_fRadius;
    if ( m_fRadius >= v22 && (float)(v22 / m_fRadius) != this->m_NearestEntityDistance.m_Value.flVal )
      CEntityOutputTemplate<float,1>::Set(
        this: &this->m_NearestEntityDistance,
        value: v22 / m_fRadius,
        pActivator: v21,
        pCaller: this);
    thinkTime = gpGlobals->curtime;
  }
  else
  {
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    thinkTime = -1.0;
  }
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10240000
// Name: public: virtual void CTriggerWind::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerWind::UpdateOnRemove(CTriggerWind *this)
{
  IPhysicsMotionController *m_pWindController; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx

  m_pWindController = this->m_pWindController;
  if ( m_pWindController != nullptr )
  {
    physenv->DestroyMotionController(this: physenv, a2: m_pWindController);
    this->m_pWindController = nullptr;
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->RemoveTrigger(this: m_pPhysicsObject);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10240050
// Name: public: virtual void CTriggerHierarchy::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerHierarchy::Activate(CTriggerHierarchy *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  void *v4; // eax

  CBaseTrigger::Activate(this);
  pszValue = this->m_iChildFilterName.pszValue;
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
    v4 = __RTDynamicCast(
           inptr: EntityByName,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBaseFilter `RTTI Type Descriptor',
           isReference: 0);
    if ( v4 != nullptr )
      this->m_hChildFilter.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
    else
      this->m_hChildFilter.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102400C0
// Name: public: bool CTriggerHierarchy::HasChildThatPassesChildFilter(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTriggerHierarchy::HasChildThatPassesChildFilter(CTriggerHierarchy *this, CBaseEntity *pEnt)
{
  unsigned int m_Index; // eax
  CBaseFilter *m_pEntity; // ebx
  unsigned int v5; // eax
  CBaseEntity *v6; // esi
  unsigned int v7; // eax
  IHandleEntity *v8; // eax

  m_Index = this->m_hChildFilter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseFilter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v5 = pEnt->m_hMoveChild.m_Index;
  if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
    v6 = nullptr;
  else
    v6 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  if ( v6 == nullptr )
    return 0;
  while ( m_pEntity != nullptr
       && !CBaseFilter::PassesFilter(this: m_pEntity, pCaller: this, pEntity: v6)
       && !CTriggerHierarchy::HasChildThatPassesChildFilter(this, pEnt: v6) )
  {
    v7 = v6->m_hMovePeer.m_Index;
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      v8 = nullptr;
    else
      v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
    v6 = (CBaseEntity *)v8;
    if ( v8 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10240190
// Name: public: void CTriggerImpact::InputImpact(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerImpact::InputImpact(CTriggerImpact *this, inputdata_t *inputdata)
{
  float m_flMagnitude; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  CBaseEntity *pActivator; // eax
  CBaseEntity *thinkTime; // [esp+0h] [ebp-18h]
  Vector vDir; // [esp+Ch] [ebp-Ch] BYREF

  AngleVectors(angles: &this->m_angRotation.m_Value, forward: &vDir);
  m_flMagnitude = this->m_flMagnitude;
  x = vDir.x;
  y = vDir.y;
  z = vDir.z;
  pActivator = inputdata->pActivator;
  thinkTime = inputdata->pCaller;
  this->m_pOutputForce.m_Value.fieldType = FIELD_VECTOR;
  this->m_pOutputForce.m_Value.flVal = x * m_flMagnitude;
  this->m_pOutputForce.m_Value.vecVal[1] = y * m_flMagnitude;
  this->m_pOutputForce.m_Value.vecVal[2] = z * m_flMagnitude;
  CBaseEntityOutput::FireOutput(
    this: &this->m_pOutputForce,
    Value: this->m_pOutputForce.m_Value,
    pActivator,
    pCaller: thinkTime,
    fDelay: 0.0);
  this->Enable(this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CBaseEntity::ThinkSet(this, func:  __thiscall vgui::Panel::`vcall'{784,{flat}}, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10240280
// Name: public: virtual void CTriggerImpact::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerImpact::StartTouch(CTriggerImpact *this, CBaseEntity *pOther)
{
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream *v5; // ecx
  IUniformRandomStream *v6; // ecx
  float m_flMagnitude; // xmm3_4
  IPhysicsObject *m_pPhysicsObject; // ecx
  void (__thiscall *ApplyForceCenter)(IPhysicsObject *, const Vector *); // edx
  float v10; // xmm0_4
  float m_flNoise; // [esp+4h] [ebp-28h]
  QAngle angleOffset; // [esp+10h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+1Ch] [ebp-10h] BYREF
  float v14; // [esp+28h] [ebp-4h]
  CBaseEntity *pOthera; // [esp+34h] [ebp+8h]

  if ( pOther != nullptr && pOther->m_pPhysicsObject != nullptr )
  {
    AngleVectors(angles: &this->m_angRotation.m_Value, forward: &vDir);
    m_flNoise = this->m_flNoise;
    LODWORD(v14) = LODWORD(m_flNoise) ^ _mask__NegFloat_;
    pOthera = (CBaseEntity *)LODWORD(m_flNoise);
    _RandomFloat(this: v4, a2: COERCE_FLOAT(LODWORD(m_flNoise) ^ _mask__NegFloat_), a3: m_flNoise);
    _RandomFloat(this: v5, a2: v14, a3: *(float *)&pOthera);
    angleOffset.z = _RandomFloat(this: v6, a2: v14, a3: *(float *)&pOthera);
    m_flMagnitude = this->m_flMagnitude;
    m_pPhysicsObject = pOther->m_pPhysicsObject;
    vDir.x = angleOffset.x + vDir.x;
    vDir.y = vDir.y + angleOffset.y;
    vDir.z = vDir.z + angleOffset.z;
    angleOffset.x = vDir.x * m_flMagnitude;
    angleOffset.y = vDir.y * m_flMagnitude;
    angleOffset.z = vDir.z * m_flMagnitude;
    ApplyForceCenter = m_pPhysicsObject->ApplyForceCenter;
    LODWORD(vDir.x) = &angleOffset;
    ((void (__thiscall *)(IPhysicsObject *))ApplyForceCenter)(a1: m_pPhysicsObject);
  }
  if ( pOther->IsPlayer(this: pOther) && COERCE_FLOAT(LODWORD(this->m_flMagnitude) & _mask__AbsFloat_) > 0.0 )
  {
    AngleVectors(angles: &this->m_angRotation.m_Value, forward: &vDir);
    v10 = COERCE_FLOAT(COERCE_UNSIGNED_INT(this->m_flViewkick * this->m_flMagnitude) ^ _mask__NegFloat_) * 0.1;
    CBaseEntity::ViewPunch(this: pOther, angleOffset: COERCE_CONST_QANGLE_(vDir.x * v10));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10240430
// Name: public: virtual int CTriggerImpact::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTriggerImpact::DrawDebugTextOverlays(CTriggerImpact *this)
{
  int result; // eax
  int v3; // edi
  char tempstr[256]; // [esp+1Ch] [ebp-100h] BYREF

  result = CBaseTrigger::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Magnitude: %3.2f", this->m_flMagnitude);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102404B0
// Name: public: virtual void CBaseVPhysicsTrigger::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVPhysicsTrigger::Spawn(CBaseVPhysicsTrigger *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+8h] [ebp-4h] BYREF

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CBaseVPhysicsTrigger *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  if ( showtriggers.m_pParent == nullptr || showtriggers.m_pParent->m_Value.m_nValue == 0 )
    CBaseEntity::AddEffects(this, nEffects: 32);
  this->CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x10240540
// Name: public: virtual bool CBaseVPhysicsTrigger::PassesTriggerFilters(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVPhysicsTrigger::PassesTriggerFilters(CBaseVPhysicsTrigger *this, CBaseEntity *pOther)
{
  int m_Value; // eax
  bool v5; // al
  bool v6; // bl
  CAI_BaseNPC *v7; // eax
  unsigned int m_Index; // ecx
  CBaseFilter *m_pEntity; // eax

  if ( pOther->m_MoveType.m_Value != 6 && !pOther->IsPlayer(this: pOther) )
    return false;
  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x40) == 0
    && ((m_Value & 1) == 0 || (pOther->m_fFlags.m_Value & 0x100) == 0)
    && ((m_Value & 2) == 0 || (pOther->m_fFlags.m_Value & 0x4000) == 0)
    && ((m_Value & 4) == 0
     || pOther->m_iClassname.pszValue != "func_pushable"
     && CBaseEntity::ClassMatchesComplex(this: pOther, pszClassOrWildcard: "func_pushable") == 0)
    && ((this->m_spawnflags.m_Value & 8) == 0 || pOther->m_MoveType.m_Value != 6) )
  {
    return false;
  }
  v5 = pOther->IsPlayer(this: pOther);
  v6 = v5;
  if ( (this->m_spawnflags.m_Value & 0x10) != 0 && !v5 )
  {
    v7 = pOther->MyNPCPointer(this: pOther);
    if ( v7 == nullptr || !v7->IsPlayerAlly(this: v7, a2: nullptr) )
      return false;
  }
  if ( (this->m_spawnflags.m_Value & 0x20) != 0
    && v6
    && ((unsigned __int8 (__thiscall *)(CBaseEntity *))pOther->__vftable[1].ModifyOrAppendCriteria)(a1: pOther) == 0
    || (this->m_spawnflags.m_Value & 0x200) != 0
    && v6
    && ((unsigned __int8 (__thiscall *)(CBaseEntity *))pOther->__vftable[1].ModifyOrAppendCriteria)(a1: pOther) != 0 )
  {
    return false;
  }
  m_Index = this->m_hFilter.m_Index;
  return m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || (m_pEntity = (CBaseFilter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr
      || CBaseFilter::PassesFilter(this: m_pEntity, pCaller: this, pEntity: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x102406C0
// Name: public: virtual void CTriggerVPhysicsMotion::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerVPhysicsMotion::Spawn(CTriggerVPhysicsMotion *this)
{
  this->Precache(this);
  CBaseVPhysicsTrigger::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102406E0
// Name: public: virtual bool CTriggerVPhysicsMotion::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CTriggerVPhysicsMotion::CreateVPhysics@<al>(CTriggerVPhysicsMotion *this@<ecx>, int a2@<ebp>)
{
  IMotionEvent *v3; // eax
  IPhysicsMotionController *v4; // eax
  bool v5; // zf
  IPhysicsObject *inited; // eax

  if ( this != nullptr )
    v3 = &this->IMotionEvent;
  else
    v3 = nullptr;
  v4 = physenv->CreateMotionController(this: physenv, a2: v3);
  v5 = (this->m_spawnflags.m_Value & 0x1000) == 0;
  this->m_pController = v4;
  if ( v5 )
    inited = CBaseEntity::VPhysicsInitStatic(this, a2);
  else
    inited = CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
  inited->BecomeTrigger(this: inited);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10240820
// Name: public: virtual void CBaseTrigger::Enable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::Enable(CBaseTrigger *this)
{
  CNetworkVarBase<bool,CBaseTrigger::NetworkVar_m_bDisabled> *p_m_bDisabled; // edi
  IPhysicsObject *m_pPhysicsObject; // ecx

  p_m_bDisabled = &this->m_bDisabled;
  if ( this->m_bDisabled.m_Value )
  {
    this->NetworkStateChanged_m_bDisabled(this, a2: &this->m_bDisabled);
    p_m_bDisabled->m_Value = false;
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: true);
  if ( (this->m_Collision.m_usSolidFlags.m_Value & 8) == 0 )
  {
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
    CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10240890
// Name: public: virtual void CBaseTrigger::Disable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::Disable(CBaseTrigger *this)
{
  CNetworkVarBase<bool,CBaseTrigger::NetworkVar_m_bDisabled> *p_m_bDisabled; // esi
  IPhysicsObject *m_pPhysicsObject; // ecx

  p_m_bDisabled = &this->m_bDisabled;
  if ( !this->m_bDisabled.m_Value )
  {
    this->NetworkStateChanged_m_bDisabled(this, a2: &this->m_bDisabled);
    p_m_bDisabled->m_Value = true;
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: false);
  if ( (this->m_Collision.m_usSolidFlags.m_Value & 8) != 0 )
  {
    CCollisionProperty::SetSolidFlags(
      this: &this->m_Collision,
      flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFF7);
    CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10240900
// Name: private: void CTriggerLook::TimeoutThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerLook::TimeoutThink(CTriggerLook *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v4; // eax

  m_Index = this->m_hActivator.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  COutputEvent::FireOutput(this: &this->m_OnTimeout, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
  v4 = (unsigned int)this->m_spawnflags.m_Value >> 7;
  this->m_bTimeoutFired = true;
  if ( (v4 & 1) != 0 )
  {
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10240990
// Name: public: virtual void CTriggerLook::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerLook::Touch(CTriggerLook *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  int v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  CBaseEntity *m_pEntity; // edi
  Vector *v10; // eax
  float m_flLookTimeTotal; // xmm0_4
  double curtime; // st7
  float v13; // xmm0_4
  _BYTE v14[12]; // [esp+4h] [ebp-24h] BYREF
  Vector vTargetDir; // [esp+10h] [ebp-18h] BYREF
  Vector vLookDir; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  if ( !this->m_bTimeoutFired )
  {
    m_Index = this->m_hLookTarget.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
      && pOther->IsPlayer(this: pOther) )
    {
      if ( (this->m_spawnflags.m_Value & 0x100) != 0 )
      {
        if ( (pOther->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this: pOther, a2: (int)&savedregs);
        y = pOther->m_vecAbsVelocity.y;
        z = pOther->m_vecAbsVelocity.z;
        vLookDir.x = pOther->m_vecAbsVelocity.x;
        vLookDir.y = y;
        vLookDir.z = z;
        if ( vec3_origin.x == vLookDir.x
          && vec3_origin.y == y
          && vec3_origin.z == z
          && ((unsigned __int8 (__thiscall *)(CBaseEntity *))pOther->__vftable[1].ModifyOrAppendCriteria)(a1: pOther) != 0 )
        {
          v6 = ((int (__thiscall *)(CBaseEntity *))pOther->__vftable[1].ModifyOrAppendDerivedCriteria)(a1: pOther);
          v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 32))(a1: v6);
          vLookDir = *(Vector *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v7 + 540))(a1: v7, a2: v14);
        }
        VectorNormalize(vec: &vLookDir);
      }
      else
      {
        vLookDir = *(Vector *)((int (__thiscall *)(CBaseEntity *, _BYTE *))pOther->__vftable[1].GetAutoAimRadius)(
                                a1: pOther,
                                a2: v14);
      }
      v8 = this->m_hLookTarget.m_Index;
      if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
      if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
      v10 = pOther->EyePosition(this: pOther, result: v14);
      vTargetDir.x = m_pEntity->m_vecAbsOrigin.x - v10->x;
      vTargetDir.y = m_pEntity->m_vecAbsOrigin.y - v10->y;
      vTargetDir.z = m_pEntity->m_vecAbsOrigin.z - v10->z;
      VectorNormalize(vec: &vTargetDir);
      if ( (float)((float)((float)(vTargetDir.y * vLookDir.y) + (float)(vTargetDir.x * vLookDir.x))
                 + (float)(vTargetDir.z * vLookDir.z)) <= this->m_flFieldOfView )
      {
        this->m_flLookTimeTotal = -1.0;
      }
      else
      {
        m_flLookTimeTotal = this->m_flLookTimeTotal;
        if ( m_flLookTimeTotal == -1.0 )
        {
          curtime = gpGlobals->curtime;
          this->m_flLookTimeTotal = 0.0;
        }
        else
        {
          this->m_flLookTimeTotal = (float)(gpGlobals->curtime - this->m_flLookTimeLast) + m_flLookTimeTotal;
          curtime = gpGlobals->curtime;
        }
        v13 = this->m_flLookTimeTotal;
        this->m_flLookTimeLast = curtime;
        if ( v13 >= this->m_flLookTime )
          CTriggerLook::Trigger(this, pActivator: pOther, bTimeout: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10240C60
// Name: public: void CTriggerCamera::InputSetTargetAttachment(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::InputSetTargetAttachment(CTriggerCamera *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  this->m_iszTargetAttachment.pszValue = iVal;
  CTriggerCamera::FindAttachment(this);
}

//------------------------------------------------------------------------------
// Address: 0x10240CA0
// Name: public: void CMoveableCamera::FollowTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveableCamera::FollowTarget(CMoveableCamera *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // edi
  float z; // edx
  float v5; // ecx
  __int64 v6; // xmm0_8
  Quaternion qt; // [esp+10h] [ebp-64h] BYREF
  Quaternion outQuat; // [esp+20h] [ebp-54h] BYREF
  Quaternion q; // [esp+30h] [ebp-44h] BYREF
  QAngle v10; // [esp+40h] [ebp-34h] BYREF
  QAngle nextAngle; // [esp+4Ch] [ebp-28h] BYREF
  QAngle vecGoal; // [esp+58h] [ebp-1Ch] BYREF
  QAngle angles; // [esp+64h] [ebp-10h] BYREF
  float tt; // [esp+70h] [ebp-4h]
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( ((int)m_pEntity[49].__vftable & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)m_pEntity, a2: (int)&savedregs);
  z = this->m_vStartAngles.z;
  *(_QWORD *)&vecGoal.x = *(_QWORD *)&m_pEntity[118].__vftable;
  v5 = *(float *)&m_pEntity[120].__vftable;
  *(_QWORD *)&angles.x = *(_QWORD *)&this->m_vStartAngles.x;
  vecGoal.z = v5;
  angles.z = z;
  tt = (float)(gpGlobals->curtime - this->m_flInterpStartTime) / this->m_flInterpTime;
  if ( vecGoal.x == angles.x && vecGoal.y == angles.y && vecGoal.z == angles.z )
  {
    v6 = *(_QWORD *)&this->m_vStartAngles.x;
    nextAngle.z = z;
  }
  else
  {
    AngleQuaternion(&angles, &outQuat);
    AngleQuaternion(angles: &vecGoal, outQuat: &q);
    QuaternionSlerp(p: &outQuat, &q, t: tt, &qt);
    QuaternionAngles(q: &qt, angles: &v10);
    v6 = *(_QWORD *)&v10.x;
    nextAngle.z = v10.z;
  }
  *(_QWORD *)&nextAngle.x = v6;
  CBaseEntity::SetAbsAngles(this, absAngles: &nextAngle);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  CMoveableCamera::Move(this);
}

//------------------------------------------------------------------------------
// Address: 0x10240E00
// Name: public: virtual void CTriggerWind::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerWind::Spawn(CTriggerWind *this)
{
  int y; // eax
  int m_nDirBase; // edx

  y = (int)this->m_angRotation.m_Value.y;
  this->m_bSwitch = true;
  this->m_nDirBase = y;
  CBaseVPhysicsTrigger::Spawn(this);
  m_nDirBase = this->m_nDirBase;
  this->m_nSpeedCurrent = this->m_nSpeedBase;
  this->m_nDirCurrent = m_nDirBase;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CTriggerWind::WindThink,
    thinkTime: gpGlobals->curtime,
    szContext: "WindThinkContext");
}

//------------------------------------------------------------------------------
// Address: 0x10240E60
// Name: public: virtual bool CTriggerWind::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CTriggerWind::CreateVPhysics@<al>(CTriggerWind *this@<ecx>, int a2@<ebp>)
{
  IPhysicsObject *inited; // eax

  if ( (this->m_spawnflags.m_Value & 0x1000) != 0 )
    inited = CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
  else
    inited = CBaseEntity::VPhysicsInitStatic(this, a2);
  inited->BecomeTrigger(this: inited);
  this->m_pWindController = physenv->CreateMotionController(this: physenv, a2: &this->m_WindCallback);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10240EB0
// Name: public: virtual bool CTriggerHierarchy::PassesTriggerFilters(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTriggerHierarchy::PassesTriggerFilters(CTriggerHierarchy *this, CBaseEntity *pOther)
{
  char result; // al

  result = CBaseTrigger::PassesTriggerFilters(this, pOther);
  if ( result != 0 )
    return CTriggerHierarchy::HasChildThatPassesChildFilter(this, pEnt: pOther);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10240EE0
// Name: public: void CBaseVPhysicsTrigger::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVPhysicsTrigger::InputEnable(CBaseVPhysicsTrigger *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CBaseVPhysicsTrigger::NetworkVar_m_bDisabled> *p_m_bDisabled; // esi
  IPhysicsObject *m_pPhysicsObject; // ecx

  p_m_bDisabled = &this->m_bDisabled;
  if ( this->m_bDisabled.m_Value )
  {
    this->NetworkStateChanged_m_bDisabled(this, a2: &this->m_bDisabled);
    p_m_bDisabled->m_Value = false;
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
      m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10240F30
// Name: public: void CBaseVPhysicsTrigger::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVPhysicsTrigger::InputDisable(CBaseVPhysicsTrigger *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CBaseVPhysicsTrigger::NetworkVar_m_bDisabled> *p_m_bDisabled; // esi
  IPhysicsObject *m_pPhysicsObject; // ecx

  p_m_bDisabled = &this->m_bDisabled;
  if ( !this->m_bDisabled.m_Value )
  {
    if ( !p_m_bDisabled->m_Value )
    {
      this->NetworkStateChanged_m_bDisabled(this, a2: &this->m_bDisabled);
      p_m_bDisabled->m_Value = true;
    }
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
      m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102410E0
// Name: public: void CBaseTrigger::InitTrigger(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::InitTrigger(CBaseTrigger *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // eax
  const char *v4; // eax
  bool v5; // sf
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  m_Index = this->m_pParent.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CCollisionProperty::SetSolid(
    this: &this->m_Collision,
    val: (SolidType_t)(m_pEntity != nullptr ? SOLID_VPHYSICS : SOLID_BSP));
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  if ( this->m_bDisabled.m_Value )
    CCollisionProperty::SetSolidFlags(
      this: &this->m_Collision,
      flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFF7);
  else
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v4 = *(const char **)((int (__thiscall *)(CBaseTrigger *, _BYTE *))this->GetModelName)(a1: this, a2: v6);
  if ( v4 == nullptr )
    v4 = locale;
  this->SetModel(this, a2: v4);
  if ( showtriggers.m_pParent == nullptr || showtriggers.m_pParent->m_Value.m_nValue == 0 )
    CBaseEntity::AddEffects(this, nEffects: 32);
  v5 = this->m_hTouchingEntities.m_Memory.m_nGrowSize < 0;
  this->m_hTouchingEntities.m_Size = 0;
  if ( !v5 )
  {
    if ( this->m_hTouchingEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hTouchingEntities.m_Memory.m_pMemory);
      this->m_hTouchingEntities.m_Memory.m_pMemory = nullptr;
    }
    this->m_hTouchingEntities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_hTouchingEntities.m_pElements = this->m_hTouchingEntities.m_Memory.m_pMemory;
  if ( (this->m_spawnflags.m_Value & 0x400) != 0 )
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x200);
}

//------------------------------------------------------------------------------
// Address: 0x10241230
// Name: public: virtual void CBaseTrigger::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::EndTouch(CBaseTrigger *this, CBaseEntity *pOther)
{
  int v3; // eax
  int v4; // edi
  unsigned int m_Index; // eax
  CHandle<CBaseEntity> hOther; // [esp+10h] [ebp-8h] BYREF
  bool bFoundOtherTouchee; // [esp+17h] [ebp-1h]

  if ( pOther != nullptr )
    hOther.m_Index = pOther->GetRefEHandle(this: pOther)->m_Index;
  else
    hOther.m_Index = -1;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: &this->m_hTouchingEntities,
         src: &hOther) != -1 )
  {
    if ( pOther != nullptr )
      hOther.m_Index = pOther->GetRefEHandle(this: pOther)->m_Index;
    else
      hOther.m_Index = -1;
    v3 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: &this->m_hTouchingEntities,
           src: &hOther);
    if ( v3 != -1 )
    {
      if ( this->m_hTouchingEntities.m_Size - v3 - 1 > 0 )
        _V_memmove(
          dest: &this->m_hTouchingEntities.m_Memory.m_pMemory[v3],
          src: &this->m_hTouchingEntities.m_Memory.m_pMemory[v3 + 1],
          count: 4 * (this->m_hTouchingEntities.m_Size - v3 - 1));
      --this->m_hTouchingEntities.m_Size;
    }
    COutputEvent::FireOutput(this: &this->m_OnEndTouch, pActivator: pOther, pCaller: this, fDelay: 0.0);
    v4 = this->m_hTouchingEntities.m_Size - 1;
    bFoundOtherTouchee = false;
    if ( v4 < 0 )
      goto LABEL_22;
    do
    {
      m_Index = this->m_hTouchingEntities.m_Memory.m_pMemory[v4].m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        bFoundOtherTouchee = true;
      }
      else
      {
        if ( this->m_hTouchingEntities.m_Size - v4 - 1 > 0 )
          _V_memmove(
            dest: &this->m_hTouchingEntities.m_Memory.m_pMemory[v4],
            src: &this->m_hTouchingEntities.m_Memory.m_pMemory[v4 + 1],
            count: 4 * (this->m_hTouchingEntities.m_Size - v4 - 1));
        --this->m_hTouchingEntities.m_Size;
      }
      --v4;
    }
    while ( v4 >= 0 );
    if ( !bFoundOtherTouchee )
LABEL_22:
      this->OnEndTouchAll(this, a2: pOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10241380
// Name: public: virtual void CTriggerLook::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerLook::EndTouch(CTriggerLook *this, CBaseEntity *pOther)
{
  CBaseTrigger::EndTouch(this, pOther);
  if ( pOther->IsPlayer(this: pOther) )
  {
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    this->m_flLookTimeTotal = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102413F0
// Name: public: virtual void CTriggerPush::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerPush::Touch(CTriggerPush *this, CBaseEntity *pOther)
{
  unsigned __int8 m_Value; // al
  const matrix3x4_t *v4; // eax
  int v5; // eax
  float m_flPushSpeed; // xmm0_4
  int v7; // ebx
  int i; // esi
  float v9; // xmm0_4
  int v10; // ecx
  float frametime; // xmm3_4
  double v12; // st7
  int v13; // ecx
  IPhysicsObject *m_pPhysicsObject; // ecx
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  int v18; // eax
  float v19; // xmm3_4
  float v20; // xmm1_4
  const Vector *AbsOrigin; // eax
  _DWORD v22[1024]; // [esp+8h] [ebp-1030h] BYREF
  float v23[3]; // [esp+1008h] [ebp-30h] BYREF
  Vector vecImpulse; // [esp+1014h] [ebp-24h] BYREF
  float out; // [esp+1020h] [ebp-18h] BYREF
  float v26; // [esp+1024h] [ebp-14h]
  float v27; // [esp+1028h] [ebp-10h]
  Vector v; // [esp+102Ch] [ebp-Ch] BYREF
  float v29; // [esp+1040h] [ebp+8h]

  if ( pOther->m_Collision.m_nSolidType.m_Value != 0 && (pOther->m_Collision.m_usSolidFlags.m_Value & 4) == 0 )
  {
    m_Value = pOther->m_MoveType.m_Value;
    if ( m_Value != 7
      && m_Value != 0
      && this->PassesTriggerFilters(this, a2: pOther)
      && CBaseEntity::GetMoveParent(this: pOther) == nullptr )
    {
      v4 = CBaseEntity::EntityToWorldTransform(this);
      VectorRotate(in1: &this->m_vecPushDir.x, in2: v4, &out);
      v5 = this->m_spawnflags.m_Value;
      if ( (v5 & 0x80) != 0 )
      {
        m_flPushSpeed = this->m_flPushSpeed;
        vecImpulse.x = out * m_flPushSpeed;
        vecImpulse.y = v26 * m_flPushSpeed;
        vecImpulse.z = m_flPushSpeed * v27;
        CBaseEntity::ApplyAbsVelocityImpulse(this: pOther, &vecImpulse);
        if ( v27 > 0.0 )
          CBaseEntity::SetGroundEntity(this: pOther, ground: nullptr);
        UTIL_Remove(oldObj: this);
      }
      else
      {
        switch ( pOther->m_MoveType.m_Value )
        {
          case 0u:
          case 7u:
          case 8u:
            return;
          case 6u:
            if ( (v5 & 0x1000) != 0 )
            {
              v7 = pOther->VPhysicsGetObjectList(this: pOther, a2: (IPhysicsObject **)v22, a3: 1024);
              for ( i = 0; i < v7; ++i )
              {
                v9 = this->m_flPushSpeed;
                v10 = v22[i];
                frametime = gpGlobals->frametime;
                v.x = (float)((float)(out * v9) * 100.0) * frametime;
                v.y = (float)((float)(v26 * v9) * 100.0) * frametime;
                v.z = (float)((float)(v9 * v27) * 100.0) * frametime;
                v12 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v10 + 116))(a1: v10);
                v13 = v22[i];
                v29 = v12 * 0.0099999998;
                v.x = v.x * v29;
                v.y = v.y * v29;
                v.z = v.z * v29;
                (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v13 + 240))(a1: v13, a2: &v);
              }
            }
            else
            {
              m_pPhysicsObject = pOther->m_pPhysicsObject;
              if ( m_pPhysicsObject != nullptr )
              {
                v15 = this->m_flPushSpeed;
                v16 = gpGlobals->frametime;
                v23[0] = (float)((float)(out * v15) * 100.0) * v16;
                v23[1] = (float)((float)(v26 * v15) * 100.0) * v16;
                v23[2] = (float)((float)(v15 * v27) * 100.0) * v16;
                m_pPhysicsObject->ApplyForceCenter(this: m_pPhysicsObject, a2: (const Vector *)v23);
              }
            }
            break;
          default:
            v17 = this->m_flPushSpeed;
            v18 = pOther->m_fFlags.m_Value;
            v19 = v17 * v27;
            v.x = v17 * out;
            v.y = v26 * v17;
            v.z = v17 * v27;
            if ( (v18 & 0x1000000) != 0 )
            {
              v19 = v19 + pOther->m_vecBaseVelocity.m_Value.z;
              v20 = pOther->m_vecBaseVelocity.m_Value.y + (float)(v26 * v17);
              v.x = pOther->m_vecBaseVelocity.m_Value.x + (float)(v17 * out);
              v.y = v20;
              v.z = v19;
            }
            if ( v19 > 0.0 && (v18 & 1) != 0 )
            {
              CBaseEntity::SetGroundEntity(this: pOther, ground: nullptr);
              AbsOrigin = CBaseEntity::GetAbsOrigin(this: pOther);
              *(_QWORD *)&vecImpulse.x = *(_QWORD *)&AbsOrigin->x;
              vecImpulse.z = AbsOrigin->z + 1.0;
              CBaseEntity::SetAbsOrigin(this: pOther, absOrigin: &vecImpulse);
            }
            CBaseEntity::SetBaseVelocity(this: pOther, &v);
            CBaseEntity::AddFlag(this: pOther, flags: 0x1000000);
            break;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10241760
// Name: public: virtual void CTriggerToggleSave::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerToggleSave::Spawn(CTriggerSave *this)
{
  if ( g_pGameRules->IsDeathmatch(this: g_pGameRules) )
    UTIL_Remove(oldObj: this);
  else
    CBaseTrigger::InitTrigger(this);
}

//------------------------------------------------------------------------------
// Address: 0x10241790
// Name: public: virtual void CTriggerGravity::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerGravity::EndTouch(CTriggerGravity *this, CBaseEntity *pOther)
{
  CBaseTrigger::EndTouch(this, pOther);
  if ( pOther->IsPlayer(this: pOther) )
    pOther->m_flGravity = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102417D0
// Name: public: void CTriggerCamera::Disable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::Disable(CTriggerCamera *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // esi
  unsigned int v10; // eax
  IHandleEntity *v11; // ecx
  char m_nOldTakeDamage; // bl
  _BYTE *v13; // esi

  m_Index = this->m_hPlayer.m_Index;
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
      if ( m_pEntity->__vftable[22].GetRefEHandle(this: m_pEntity) != nullptr )
      {
        if ( (this->m_spawnflags.m_Value & 0x20) != 0 )
          CCollisionProperty::SetSolidFlags(
            this: (CCollisionProperty *)&m_pEntity[57],
            flags: (int)m_pEntity[65].__vftable & 0xFFFB);
        CBasePlayer::SetViewEntity(this: (CBasePlayer *)m_pEntity, pEntity: nullptr, bShouldDrawPlayer: true);
        CBasePlayer::EnableControl(this: (CBasePlayer *)m_pEntity, fControl: true);
        if ( LOBYTE(m_pEntity[606].__vftable) != 1 )
        {
          ((void (__thiscall *)(IHandleEntity *, IHandleEntity *))m_pEntity[572].dtr_IHandleEntity)(
            a1: &m_pEntity[572],
            a2: &m_pEntity[606]);
          LOBYTE(m_pEntity[606].__vftable) = 1;
        }
      }
      if ( (this->m_spawnflags.m_Value & 0x80) != 0 )
        CBasePlayer::SetFOV(
          this: (CBasePlayer *)m_pEntity,
          pRequester: this,
          FOV: 0,
          zoomRate: this->m_fovSpeed,
          iZoomStart: 0);
      v10 = this->m_hPlayer.m_Index;
      if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
        v11 = nullptr;
      else
        v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
      m_nOldTakeDamage = this->m_nOldTakeDamage;
      v13 = (char *)&v11[138].__vftable + 2;
      if ( BYTE2(v11[138].__vftable) != m_nOldTakeDamage )
      {
        ((void (__thiscall *)(IHandleEntity *, int))v11->__vftable[63].dtr_IHandleEntity)(
          a1: v11,
          a2: (int)&v11[138].__vftable + 2);
        *v13 = m_nOldTakeDamage;
      }
    }
  }
  this->m_state = 0;
  this->m_flReturnTime = gpGlobals->curtime;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  COutputEvent::FireOutput(this: &this->m_OnEndFollow, pActivator: this, pCaller: this, fDelay: 0.0);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10241970
// Name: public: void CTriggerCamera::InputTeleportToView(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTriggerCamera::InputTeleportToView(CTriggerCamera *this@<ecx>, int a2@<esi>, inputdata_t *inputdata)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CBaseEntity **v10; // eax
  CBaseEntity *v11; // esi
  float z; // edx
  float *v13; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float v16; // xmm2_4
  unsigned int v17; // eax
  int m_iEFlags; // ecx
  int v19; // edx
  CGameTrace tr; // [esp+4h] [ebp-84h] BYREF
  QAngle vecPlayerView; // [esp+58h] [ebp-30h] BYREF
  Vector vecAbsEnd; // [esp+64h] [ebp-24h] BYREF
  Vector vecTeleportPosition; // [esp+70h] [ebp-18h] BYREF
  Vector vecEyeOffset; // [esp+7Ch] [ebp-Ch]
  IHandleEntity savedregs; // [esp+88h] [ebp+0h] BYREF

  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index != -1 )
  {
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        v11 = *v10;
      else
        v11 = nullptr;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      z = this->m_angAbsRotation.z;
      *(_QWORD *)&vecPlayerView.x = *(_QWORD *)&this->m_angAbsRotation.x;
      vecPlayerView.z = z;
      if ( (v11->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
      v13 = (float *)((int (__thiscall *)(CBaseEntity *, Vector *, int))v11->EyePosition)(
                       a1: v11,
                       a2: &vecAbsEnd,
                       a3: a2);
      x = *v13 - v11->m_vecAbsOrigin.x;
      y = v13[1] - v11->m_vecAbsOrigin.y;
      v16 = v13[2] - v11->m_vecAbsOrigin.z;
      v17 = (unsigned int)this->m_iEFlags >> 11;
      vecEyeOffset.x = x;
      vecEyeOffset.y = y;
      vecEyeOffset.z = v16;
      if ( (v17 & 1) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v16 = vecEyeOffset.z;
        y = vecEyeOffset.y;
        x = vecEyeOffset.x;
      }
      m_iEFlags = this->m_iEFlags;
      vecTeleportPosition.x = this->m_vecAbsOrigin.x - x;
      vecTeleportPosition.y = this->m_vecAbsOrigin.y - y;
      vecTeleportPosition.z = this->m_vecAbsOrigin.z - v16;
      vecEyeOffset.x = x * 1.02;
      vecEyeOffset.y = y * 1.02;
      vecEyeOffset.z = v16 * 1.02;
      if ( (m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v19 = this->m_iEFlags;
      vecAbsEnd.x = this->m_vecAbsOrigin.x - vecEyeOffset.x;
      vecAbsEnd.y = this->m_vecAbsOrigin.y - vecEyeOffset.y;
      vecAbsEnd.z = this->m_vecAbsOrigin.z - vecEyeOffset.z;
      if ( (v19 & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)v11,
        vecAbsStart: &this->m_vecAbsOrigin,
        &vecAbsEnd,
        mask: 0x200400Bu,
        ignore: v11,
        collisionGroup: 0,
        ptr: &tr);
      if ( tr.fraction != 1.0 )
        vecTeleportPosition = tr.endpos;
      CBaseEntity::SetGroundEntity(this: v11, ground: nullptr);
      ((void (__thiscall *)(CBaseEntity *, Vector *, QAngle *, _DWORD))v11->Teleport)(
        a1: v11,
        a2: &vecTeleportPosition,
        a3: &vecPlayerView,
        a4: 0);
    }
  }
  CTriggerCamera::Disable(this);
}

//------------------------------------------------------------------------------
// Address: 0x10241BA0
// Name: public: void CTriggerCamera::ReturnToEyes(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTriggerCamera::ReturnToEyes(CTriggerCamera *this@<ecx>, float a2@<ebp>)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // edi
  float *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  unsigned int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  unsigned int v19; // xmm1_4
  unsigned int v20; // xmm2_4
  unsigned int v21; // eax
  IHandleEntity *v22; // edi
  IHandleEntity *v23; // ecx
  unsigned int v24; // xmm0_4
  const CBaseHandle *(__thiscall *GetRefEHandle)(IHandleEntity *); // eax
  __int128 v26; // xmm0
  float v27; // xmm0_4
  QAngle v28; // [esp+0h] [ebp-48h]
  _QWORD v29[2]; // [esp+1Ch] [ebp-2Ch] BYREF
  unsigned __int64 v30; // [esp+30h] [ebp-18h]
  float v31; // [esp+38h] [ebp-10h]
  QAngle vecPlayerView; // [esp+3Ch] [ebp-Ch] BYREF
  float retaddr; // [esp+48h] [ebp+0h]

  vecPlayerView.x = a2;
  vecPlayerView.y = retaddr;
  m_Index = this->m_hPlayer.m_Index;
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
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecPlayerView);
      v11 = (float *)((int (__thiscall *)(IHandleEntity *, char *))m_pEntity->__vftable[42].dtr_IHandleEntity)(
                       a1: m_pEntity,
                       a2: (char *)v29 + 4);
      v12 = *v11;
      v13 = v11[1];
      v14 = v11[2];
      v15 = (unsigned int)this->m_iEFlags >> 11;
      v16 = (float)(v12 - this->m_vecAbsOrigin.x) * 0.1;
      v17 = (float)(v13 - this->m_vecAbsOrigin.y) * 0.1;
      v18 = (float)(v14 - this->m_vecAbsOrigin.z) * 0.1;
      v30 = __PAIR64__(LODWORD(v17), LODWORD(v16));
      v31 = v18;
      if ( (v15 & 1) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecPlayerView);
        v18 = v31;
        v17 = *((float *)&v30 + 1);
        LODWORD(v16) = v30;
      }
      *(float *)&v19 = v17 + this->m_vecAbsOrigin.y;
      *(float *)&v20 = v18 + this->m_vecAbsOrigin.z;
      *((float *)v29 + 1) = v16 + this->m_vecAbsOrigin.x;
      v29[1] = __PAIR64__(v20, v19);
      UTIL_SetOrigin(entity: this, vecOrigin: (const Vector *)((char *)v29 + 4), bFireTriggers: false);
      v21 = this->m_hPlayer.m_Index;
      if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
        v22 = nullptr;
      else
        v22 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
      if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
        v23 = nullptr;
      else
        v23 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
      v24 = v23->__vftable[42].GetRefEHandle(this: v23)->m_Index;
      GetRefEHandle = v22->__vftable[42].GetRefEHandle;
      LODWORD(v30) = v24;
      HIDWORD(v30) = GetRefEHandle(this: v22)[1].m_Index;
      v31 = 0.0;
      *(_QWORD *)&v28.x = v30;
      v28.z = 0.0;
      CTriggerCamera::MoveViewTo(this, vecGoalView: v28);
      v26 = 0;
      *(float *)&v26 = fsqrt(
                         (float)((float)((float)(*((float *)&v30 + 1) - this->m_angRotation.m_Value.y)
                                       * (float)(*((float *)&v30 + 1) - this->m_angRotation.m_Value.y))
                               + (float)(0.0 * 0.0))
                       + (float)((float)(*(float *)&v30 - this->m_angRotation.m_Value.x)
                               * (float)(*(float *)&v30 - this->m_angRotation.m_Value.x)));
      *(_OWORD *)v29 = v26;
      v27 = fabs(*(float *)&v26);
      if ( v27 > 180.0 )
        v27 = v27 - 360.0;
      if ( fabs(v27) >= 1.0 )
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
      else
        CTriggerCamera::Disable(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10241E20
// Name: public: void CTriggerCamera::Move(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::Move(CTriggerCamera *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // edi
  int v10; // edi
  float v11; // xmm0_4
  CBaseEntity *NextTarget; // eax
  float m_flSpeed; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float m_targetSpeed; // xmm0_4
  float v22; // xmm3_4
  unsigned int v23; // eax
  float v24; // xmm7_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  variant_t emptyVariant; // [esp+8h] [ebp-18h] BYREF
  float fraction; // [esp+1Ch] [ebp-4h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( (this->m_spawnflags.m_Value & 0x40) != 0 )
  {
    m_Index = this->m_hPlayer.m_Index;
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
        {
          m_pEntity = v8->m_pEntity;
          if ( v8->m_pEntity != nullptr
            && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: m_pEntity) != 0 )
          {
            v10 = (int)m_pEntity[738].__vftable;
            if ( v10 != this->m_nPlayerButtons && v10 != 0 )
            {
              CTriggerCamera::Disable(this);
              return;
            }
            this->m_nPlayerButtons = v10;
          }
        }
      }
    }
  }
  if ( this->m_pPath != nullptr )
  {
    v11 = this->m_moveDistance - (float)(gpGlobals->frametime * this->m_flSpeed);
    this->m_moveDistance = v11;
    if ( v11 <= 0.0 )
    {
      ((void (__thiscall *)(CBaseEntity *, const char *, CTriggerCamera *, CTriggerCamera *, _DWORD))this->m_pPath->AcceptInput)(
        a1: this->m_pPath,
        a2: "InPass",
        a3: this,
        a4: this,
        a5: 0);
      NextTarget = CBaseEntity::GetNextTarget(this: this->m_pPath);
      this->m_pPath = NextTarget;
      if ( NextTarget != nullptr )
      {
        m_flSpeed = NextTarget->m_flSpeed;
        if ( m_flSpeed != 0.0 )
          this->m_targetSpeed = m_flSpeed;
        v14 = NextTarget->m_vecOrigin.m_Value.y - this->m_vecOrigin.m_Value.y;
        v15 = NextTarget->m_vecOrigin.m_Value.z - this->m_vecOrigin.m_Value.z;
        this->m_vecMoveDir.x = NextTarget->m_vecOrigin.m_Value.x - this->m_vecOrigin.m_Value.x;
        this->m_vecMoveDir.y = v14;
        this->m_vecMoveDir.z = v15;
        this->m_moveDistance = VectorNormalize(vec: &this->m_vecMoveDir);
        this->m_flStopTime = ((double (__thiscall *)(CBaseEntity *))this->m_pPath->GetDelay)(a1: this->m_pPath)
                           + gpGlobals->curtime;
      }
      else
      {
        CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
      }
    }
    if ( this->m_flStopTime <= gpGlobals->curtime )
    {
      v18 = this->m_flSpeed;
      v19 = this->m_acceleration * gpGlobals->frametime;
      v20 = this->m_targetSpeed - v18;
      if ( v20 <= v19 )
      {
        if ( COERCE_FLOAT(LODWORD(v19) ^ _mask__NegFloat_) <= v20 )
          m_targetSpeed = this->m_targetSpeed;
        else
          m_targetSpeed = v18 - v19;
      }
      else
      {
        m_targetSpeed = v18 + v19;
      }
      this->m_flSpeed = m_targetSpeed;
    }
    else
    {
      v16 = this->m_flSpeed;
      v17 = this->m_deceleration * gpGlobals->frametime;
      if ( (float)-v16 <= v17 )
      {
        if ( (float)-v17 <= (float)-v16 )
          this->m_flSpeed = 0.0;
        else
          this->m_flSpeed = v16 - v17;
      }
      else
      {
        this->m_flSpeed = v16 + v17;
      }
    }
    v22 = gpGlobals->frametime * 2.0;
    v23 = (unsigned int)this->m_iEFlags >> 12;
    fraction = v22;
    if ( (v23 & 1) != 0 )
    {
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
      v22 = fraction;
    }
    v24 = this->m_flSpeed;
    y = this->m_vecMoveDir.y;
    z = this->m_vecMoveDir.z;
    v27 = this->m_vecAbsVelocity.y * (float)(1.0 - v22);
    v28 = this->m_vecAbsVelocity.z * (float)(1.0 - v22);
    emptyVariant.vecVal[2] = (float)((float)(this->m_vecMoveDir.x * v24) * v22)
                           + (float)((float)(1.0 - v22) * this->m_vecAbsVelocity.x);
    *(float *)&emptyVariant.eVal.m_Index = (float)((float)(y * v24) * v22) + v27;
    *(float *)&emptyVariant.fieldType = (float)((float)(z * v24) * v22) + v28;
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: (const Vector *)(&emptyVariant.rgbaVal + 2));
  }
  else
  {
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242190
// Name: public: void CMoveableCamera::StartMovement(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMoveableCamera::StartMovement(CMoveableCamera *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // eax

  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    this->SetParent(this, a2: nullptr, a3: -1);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NOCLIP, moveCollide: MOVECOLLIDE_DEFAULT);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    this->m_vStartPos.x = this->m_vecAbsOrigin.x;
    this->m_vStartPos.y = this->m_vecAbsOrigin.y;
    this->m_vStartPos.z = this->m_vecAbsOrigin.z;
    this->m_vStartAngles.x = this->m_angRotation.m_Value.x;
    this->m_vStartAngles.y = this->m_angRotation.m_Value.y;
    this->m_vStartAngles.z = this->m_angRotation.m_Value.z;
    this->m_bMovementStarted = true;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CMoveableCamera::FollowTarget,
      thinkTime: 0.0,
      szContext: nullptr);
    this->m_flInterpStartTime = gpGlobals->curtime;
    CMoveableCamera::FollowTarget(this);
  }
  else
  {
    this->Disable(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242280
// Name: public: void CTriggerCameraMultiplayer::InputStartMovement(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __userpurge CTriggerCameraMultiplayer::InputStartMovement(
        CTriggerCameraMultiplayer *this@<ecx>,
        int a2@<ebp>,
        inputdata_t *inputdata)
{
  CMoveableCamera::StartMovement(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10242290
// Name: public: void CTriggerCameraMultiplayer::RemovePlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCameraMultiplayer::RemovePlayer(CTriggerCameraMultiplayer *this, CBasePlayer *player)
{
  CBasePlayer::EnableControl(this: player, fControl: true);
  if ( !player->m_Local.m_bDrawViewmodel.m_Value )
  {
    player->m_Local.NetworkStateChanged(this: &player->m_Local, a2: &player->m_Local.m_bDrawViewmodel);
    player->m_Local.m_bDrawViewmodel.m_Value = true;
  }
  CBasePlayer::SetViewEntity(this: player, pEntity: nullptr, bShouldDrawPlayer: true);
  CBasePlayer::SetFOV(this: player, pRequester: this, FOV: 0, zoomRate: this->m_fovSpeed, iZoomStart: 0);
  CBasePlayer::ClearZoomOwner(this: player);
}

//------------------------------------------------------------------------------
// Address: 0x10242300
// Name: public: virtual void CTriggerCameraMultiplayer::Enable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCameraMultiplayer::Enable(CTriggerCameraMultiplayer *this)
{
  this->m_bEnabled = true;
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  if ( this->m_bMovementStarted )
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CMoveableCamera::FollowTarget,
      thinkTime: 0.0,
      szContext: nullptr);
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10242340
// Name: public: virtual void CTriggerCameraMultiplayer::Disable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCameraMultiplayer::Disable(CTriggerCameraMultiplayer *this)
{
  int v2; // ebx
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // esi
  int i; // [esp+18h] [ebp-4h]

  this->m_bEnabled = false;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  v2 = 0;
  for ( i = 0; v2 < this->m_players.m_Size; i = v2 )
  {
    m_Index = this->m_players.m_Memory.m_pMemory[v2].m_Index;
    if ( m_Index != -1 )
    {
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = v4->m_pEntity;
        if ( v4->m_pEntity != nullptr
          && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: v4->m_pEntity) != 0 )
        {
          CBasePlayer::EnableControl(this: (CBasePlayer *)m_pEntity, fControl: true);
          if ( LOBYTE(m_pEntity[606].__vftable) != 1 )
          {
            ((void (__thiscall *)(IHandleEntity *, IHandleEntity *))m_pEntity[572].dtr_IHandleEntity)(
              a1: &m_pEntity[572],
              a2: &m_pEntity[606]);
            LOBYTE(m_pEntity[606].__vftable) = 1;
          }
          CBasePlayer::SetViewEntity(this: (CBasePlayer *)m_pEntity, pEntity: nullptr, bShouldDrawPlayer: true);
          CBasePlayer::SetFOV(
            this: (CBasePlayer *)m_pEntity,
            pRequester: this,
            FOV: 0,
            zoomRate: this->m_fovSpeed,
            iZoomStart: 0);
          CBasePlayer::ClearZoomOwner(this: (CBasePlayer *)m_pEntity);
          v2 = i;
        }
      }
    }
    ++v2;
  }
  this->m_players.m_Size = 0;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10242450
// Name: public: void CTriggerViewProxy::Disable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerViewProxy::Disable(CTriggerViewProxy *this)
{
  CTriggerViewProxy *v1; // ebx
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  CEntInfo *v6; // eax
  IHandleEntity *m_pEntity; // edi
  unsigned int v8; // eax
  CBaseEntity *v9; // ecx
  unsigned int v10; // eax
  IHandleEntity *v11; // ecx
  char m_nOldTakeDamage; // bl
  _BYTE *v13; // esi
  CTriggerViewProxy *v14; // [esp+14h] [ebp-4h]

  v1 = this;
  m_Index = this->m_hPlayer.m_Index;
  v14 = v1;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = &g_pEntityList->m_EntPtrArray[v3];
      if ( v6->m_SerialNumber == v5 )
        m_pEntity = v6->m_pEntity;
      else
        m_pEntity = nullptr;
      if ( m_pEntity->__vftable[22].GetRefEHandle(this: m_pEntity) != nullptr )
      {
        if ( (v1->m_spawnflags.m_Value & 0x20) != 0 )
          CCollisionProperty::SetSolidFlags(
            this: (CCollisionProperty *)&m_pEntity[57],
            flags: (int)m_pEntity[65].__vftable & 0xFFFB);
        CBasePlayer::SetViewEntity(this: (CBasePlayer *)m_pEntity, pEntity: nullptr, bShouldDrawPlayer: true);
        CBasePlayer::EnableControl(this: (CBasePlayer *)m_pEntity, fControl: true);
        v8 = v1->m_hPlayer.m_Index;
        if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
          v9 = nullptr;
        else
          v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
        CBaseEntity::RemoveFlag(this: v9, flagsToRemove: 128);
        if ( LOBYTE(m_pEntity[606].__vftable) != 1 )
        {
          ((void (__thiscall *)(IHandleEntity *, IHandleEntity *))m_pEntity[572].dtr_IHandleEntity)(
            a1: &m_pEntity[572],
            a2: &m_pEntity[606]);
          LOBYTE(m_pEntity[606].__vftable) = 1;
        }
      }
      v10 = v1->m_hPlayer.m_Index;
      if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
        v11 = nullptr;
      else
        v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
      m_nOldTakeDamage = v1->m_nOldTakeDamage;
      v13 = (char *)&v11[138].__vftable + 2;
      if ( BYTE2(v11[138].__vftable) != m_nOldTakeDamage )
      {
        ((void (__thiscall *)(IHandleEntity *, int))v11->__vftable[63].dtr_IHandleEntity)(
          a1: v11,
          a2: (int)&v11[138].__vftable + 2);
        *v13 = m_nOldTakeDamage;
      }
      v1 = v14;
      BYTE1(m_pEntity[763].__vftable) = 1;
    }
  }
  v1->m_state = 0;
  CBaseEntity::ThinkSet(this: v1, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetLocalAngularVelocity(this: v1, vecAngVelocity: &vec3_angle);
  CBaseEntity::DispatchUpdateTransmitState(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x102425F0
// Name: public: void CTriggerViewProxy::Move(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTriggerViewProxy::Move(CTriggerViewProxy *this@<ecx>, float a2@<ebp>)
{
  unsigned int m_Index; // eax
  float v4; // xmm1_4
  int m_nOffsetType; // eax
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  CBaseEntity *m_pProxy; // edi
  float z; // ecx
  float x; // xmm5_4
  float y; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  const QAngle *AbsAngles; // eax
  Vector *v22; // eax
  float v23; // xmm0_4
  CBaseEntity *v24; // eax
  float v25; // edx
  __int128 v26; // xmm4
  float v27; // xmm6_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float m_flAccelerationScalar; // xmm3_4
  CBaseEntity *v32; // eax
  CBaseEntity *v33; // eax
  __int128 v34; // [esp-20h] [ebp-4Ch] BYREF
  Vector v35; // [esp-Ch] [ebp-38h] BYREF
  Vector vecNewVelocity; // [esp+0h] [ebp-2Ch] BYREF
  Vector vecBase; // [esp+Ch] [ebp-20h] BYREF
  Vector vecAccel; // [esp+18h] [ebp-14h] BYREF
  void *v39; // [esp+24h] [ebp-8h]
  void *retaddr; // [esp+2Ch] [ebp+0h]

  vecAccel.z = a2;
  v39 = retaddr;
  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
    && this->m_pProxy != nullptr )
  {
    v4 = 0.0;
    vecBase.z = vec3_origin.z;
    m_nOffsetType = this->m_nOffsetType;
    *(_QWORD *)&vecBase.x = *(_QWORD *)&vec3_origin.x;
    if ( m_nOffsetType == 1 )
    {
      v6 = gpGlobals->curtime - this->m_flStartTime;
      if ( v6 >= 0.0 )
      {
        if ( v6 <= 1.0 )
          v4 = gpGlobals->curtime - this->m_flStartTime;
        else
          v4 = 1.0;
      }
      v7 = 1.0 - (float)((float)((float)(v4 * v4) * 3.0) - (float)((float)((float)(v4 * v4) * 2.0) * v4));
      v8 = this->m_vecInitialOffset.y * v7;
      v9 = this->m_vecInitialOffset.z * v7;
      vecBase.x = this->m_vecInitialOffset.x * v7;
      vecBase.y = v8;
      vecBase.z = v9;
    }
    else if ( m_nOffsetType == 2 )
    {
      vecBase = *CTriggerViewProxy::GetPlayerOffset(this, result: &v35);
    }
    m_pProxy = this->m_pProxy;
    if ( (m_pProxy->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pProxy, a2: (int)&vecAccel.z);
    z = m_pProxy->m_vecAbsOrigin.z;
    *(_QWORD *)&vecNewVelocity.x = *(_QWORD *)&m_pProxy->m_vecAbsOrigin.x;
    v35.x = vecNewVelocity.x + vecBase.x;
    v35.y = vecNewVelocity.y + vecBase.y;
    vecNewVelocity.z = z;
    v35.z = z + vecBase.z;
    UTIL_SetOrigin(entity: this, vecOrigin: &v35, bFireTriggers: false);
    if ( this->m_bUseFakeAcceleration && gpGlobals->frametime > 0.0 )
    {
      x = vecNewVelocity.x;
      y = vecNewVelocity.y;
      v14 = vecNewVelocity.z;
      v15 = 1.0 / gpGlobals->frametime;
      v16 = (float)(vecNewVelocity.y - this->m_vecLastPosition.y) * v15;
      v17 = (float)(vecNewVelocity.z - this->m_vecLastPosition.z) * v15;
      v18 = v15 * (float)(vecNewVelocity.x - this->m_vecLastPosition.x);
      vecBase.x = v18 - this->m_vecLastVelocity.x;
      vecBase.y = v16 - this->m_vecLastVelocity.y;
      v19 = v17 - this->m_vecLastVelocity.z;
      this->m_vecLastVelocity.x = v18;
      this->m_vecLastVelocity.y = v16;
      this->m_vecLastVelocity.z = v17;
      v35.x = v18;
      v35.y = v16;
      v35.z = v17;
      vecBase.z = v19;
      this->m_vecLastPosition.x = x;
      this->m_vecLastPosition.y = y;
      this->m_vecLastPosition.z = v14;
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &v35);
      vecAccel.y = 1.0 - (float)(gpGlobals->frametime * 0.25);
      if ( vecAccel.y < 0.0 )
        vecAccel.y = 0.0;
      v20 = (float)((float)(vecBase.y * vecBase.y) + (float)(vecBase.x * vecBase.x)) + (float)(vecBase.z * vecBase.z);
      if ( v20 < 20.0 || v20 > 10000.0 )
        vecBase = vec3_origin;
      if ( this->m_bSkewAccelerationForward )
      {
        AbsAngles = CBaseEntity::GetAbsAngles(this: this->m_pProxy);
        AngleVectors(angles: AbsAngles, forward: &vecNewVelocity);
        v22 = Vector::Normalized(this: &vecBase, result: (Vector *)((char *)&v34 + 4));
        v23 = 0.75
            - (float)((float)((float)((float)(vecNewVelocity.y * v22->y) + (float)(vecNewVelocity.x * v22->x))
                            + (float)(vecNewVelocity.z * v22->z))
                    * 0.34999999);
        vecBase.x = vecBase.x * v23;
        vecBase.y = vecBase.y * v23;
        vecBase.z = vecBase.z * v23;
      }
      vecAccel.x = gpGlobals->frametime;
      if ( vecAccel.x > 0.0 )
      {
        v24 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hPlayer);
        v25 = v24->m_vecBaseVelocity.m_Value.z;
        *(_QWORD *)&vecNewVelocity.x = *(_QWORD *)&v24->m_vecBaseVelocity.m_Value.x;
        vecNewVelocity.z = v25;
        v26 = 0;
        *(float *)&v26 = fsqrt(
                           (float)((float)(vecNewVelocity.y * vecNewVelocity.y) + (float)(v25 * v25))
                         + (float)(vecNewVelocity.x * vecNewVelocity.x));
        v34 = v26;
        if ( (float)(vecAccel.x * 100.0) <= *(float *)&v26 )
        {
          v30 = (float)(*(float *)&v34 - (float)(vecAccel.x * 100.0)) / *(float *)&v34;
          v27 = vecNewVelocity.x * v30;
          v28 = vecNewVelocity.y * v30;
          v29 = v25 * v30;
        }
        else
        {
          v27 = vec3_origin.x;
          v28 = vec3_origin.y;
          v29 = vec3_origin.z;
        }
        m_flAccelerationScalar = this->m_flAccelerationScalar;
        vecNewVelocity.x = (float)(v27 * vecAccel.y) - (float)((float)(vecBase.x * 3.0) * m_flAccelerationScalar);
        vecNewVelocity.y = (float)(v28 * vecAccel.y) - (float)((float)(vecBase.y * 3.0) * m_flAccelerationScalar);
        vecNewVelocity.z = (float)(v29 * vecAccel.y) - (float)((float)(vecBase.z * 3.0) * m_flAccelerationScalar);
        v32 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hPlayer);
        CBaseEntity::SetBaseVelocity(this: v32, v: &vecNewVelocity);
        v33 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hPlayer);
        CBaseEntity::AddFlag(this: v33, flags: 0x1000000);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242B20
// Name: public: virtual void CTriggerProximity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerProximity::Spawn(CTriggerProximity *this)
{
  if ( this->m_fRadius == 0.0 )
    this->m_fRadius = 32.0;
  CBaseTrigger::InitTrigger(this);
}

//------------------------------------------------------------------------------
// Address: 0x10242B50
// Name: public: virtual void CTriggerProximity::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerProximity::EndTouch(CTriggerProximity *this, CBaseEntity *pOther)
{
  CBaseTrigger::EndTouch(this, pOther);
  if ( this->PassesTriggerFilters(this, a2: pOther) && this->m_nTouchers-- == 1 )
  {
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242BB0
// Name: public: virtual void CTriggerPlayerMovement::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerPlayerMovement::StartTouch(CTriggerPlayerMovement *this, CBasePlayer *pOther)
{
  if ( this->PassesTriggerFilters(this, a2: pOther) && pOther != nullptr && pOther->IsPlayer(this: pOther) )
  {
    if ( (this->m_spawnflags.m_Value & 0x800) != 0 )
      CBasePlayer::ForceButtons(this: pOther, nButtons: 4);
    if ( (this->m_spawnflags.m_Value & 0x1000) != 0 )
      CBasePlayer::ForceButtons(this: pOther, nButtons: 0x20000);
    if ( (this->m_spawnflags.m_Value & 0x80) != 0 && pOther->m_Local.m_bAllowAutoMovement.m_Value )
    {
      pOther->m_Local.NetworkStateChanged(this: &pOther->m_Local, a2: &pOther->m_Local.m_bAllowAutoMovement);
      pOther->m_Local.m_bAllowAutoMovement.m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242C50
// Name: public: virtual void CTriggerPlayerMovement::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerPlayerMovement::EndTouch(CTriggerPlayerMovement *this, CBasePlayer *pOther)
{
  if ( this->PassesTriggerFilters(this, a2: pOther) && pOther != nullptr && pOther->IsPlayer(this: pOther) )
  {
    if ( (this->m_spawnflags.m_Value & 0x800) != 0 )
      CBasePlayer::UnforceButtons(this: pOther, nButtons: 4);
    if ( (this->m_spawnflags.m_Value & 0x1000) != 0 )
      CBasePlayer::UnforceButtons(this: pOther, nButtons: 0x20000);
    if ( (this->m_spawnflags.m_Value & 0x80) != 0 && !pOther->m_Local.m_bAllowAutoMovement.m_Value )
    {
      pOther->m_Local.NetworkStateChanged(this: &pOther->m_Local, a2: &pOther->m_Local.m_bAllowAutoMovement);
      pOther->m_Local.m_bAllowAutoMovement.m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242CF0
// Name: public: void CBaseVPhysicsTrigger::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVPhysicsTrigger::InputToggle(CBaseVPhysicsTrigger *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CBaseVPhysicsTrigger::NetworkVar_m_bDisabled> *p_m_bDisabled; // esi
  IPhysicsObject *m_pPhysicsObject; // ecx
  IPhysicsObject *v5; // ecx

  p_m_bDisabled = &this->m_bDisabled;
  if ( this->m_bDisabled.m_Value )
  {
    this->NetworkStateChanged_m_bDisabled(this, a2: &this->m_bDisabled);
    p_m_bDisabled->m_Value = false;
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
      m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: true);
  }
  else
  {
    if ( !p_m_bDisabled->m_Value )
    {
      this->NetworkStateChanged_m_bDisabled(this, a2: &this->m_bDisabled);
      p_m_bDisabled->m_Value = true;
    }
    v5 = this->m_pPhysicsObject;
    if ( v5 != nullptr )
      v5->EnableCollisions(this: v5, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242D70
// Name: public: virtual void CTriggerVPhysicsMotion::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerVPhysicsMotion::StartTouch(CTriggerVPhysicsMotion *this, CBasePlayer *pOther)
{
  CBaseAnimating *v3; // eax
  triggerevent_t event; // [esp+8h] [ebp-14h] BYREF

  if ( this->PassesTriggerFilters(this, a2: pOther) )
  {
    if ( pOther != nullptr && pOther->IsPlayer(this: pOther) )
    {
      CBasePlayer::SetPhysicsFlag(this: pOther, nFlag: 16, bSet: true);
      if ( !pOther->m_Local.m_bSlowMovement.m_Value )
      {
        pOther->m_Local.NetworkStateChanged(this: &pOther->m_Local, a2: &pOther->m_Local.m_bSlowMovement);
        pOther->m_Local.m_bSlowMovement.m_Value = true;
      }
    }
    PhysGetTriggerEvent(pEvent: &event, pTriggerEntity: this);
    if ( event.pObject != nullptr )
      this->m_pController->AttachObject(this: this->m_pController, a2: event.pObject, a3: true);
    if ( this->m_ParticleTrail.m_strMaterialName.pszValue != nullptr )
      CEntityParticleTrail::Create(pTarget: pOther, info: &this->m_ParticleTrail, pConstraintEntity: this);
    if ( pOther->GetBaseAnimating(this: pOther) != nullptr )
    {
      v3 = pOther->GetBaseAnimating(this: pOther);
      if ( v3->IsRagdoll(this: v3) )
        CRagdollBoogie::IncrementSuppressionCount(pTarget: pOther);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242E50
// Name: public: virtual void CTriggerVPhysicsMotion::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerVPhysicsMotion::EndTouch(CTriggerVPhysicsMotion *this, CBasePlayer *pOther)
{
  CBaseAnimating *v3; // eax
  triggerevent_t event; // [esp+8h] [ebp-14h] BYREF

  if ( this->PassesTriggerFilters(this, a2: pOther) )
  {
    if ( pOther != nullptr && pOther->IsPlayer(this: pOther) )
    {
      CBasePlayer::SetPhysicsFlag(this: pOther, nFlag: 16, bSet: false);
      if ( pOther->m_Local.m_bSlowMovement.m_Value )
      {
        pOther->m_Local.NetworkStateChanged(this: &pOther->m_Local, a2: &pOther->m_Local.m_bSlowMovement);
        pOther->m_Local.m_bSlowMovement.m_Value = false;
      }
    }
    PhysGetTriggerEvent(pEvent: &event, pTriggerEntity: this);
    if ( event.pObject != nullptr && this->m_pController != nullptr )
      this->m_pController->DetachObject(this: this->m_pController, a2: event.pObject);
    if ( this->m_ParticleTrail.m_strMaterialName.pszValue != nullptr )
      CEntityParticleTrail::Destroy(pTarget: pOther, info: &this->m_ParticleTrail);
    if ( pOther->GetBaseAnimating(this: pOther) != nullptr )
    {
      v3 = pOther->GetBaseAnimating(this: pOther);
      if ( v3->IsRagdoll(this: v3) )
        CRagdollBoogie::DecrementSuppressionCount(pTarget: pOther);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242F40
// Name: public: virtual void CServerRagdollTrigger::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRagdollTrigger::EndTouch(CServerRagdollTrigger *this, CBaseEntity *pOther)
{
  CBaseCombatCharacter *v2; // eax

  CBaseTrigger::EndTouch(this, pOther);
  if ( !pOther->IsPlayer(this: pOther) )
  {
    v2 = pOther->MyCombatCharacterPointer(this: pOther);
    if ( v2 != nullptr )
      v2->m_bForceServerRagdoll = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242F80
// Name: public: virtual void CTriggerAutoCrouch::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerAutoCrouch::EndTouch(CTriggerAutoCrouch *this, CBaseEntity *pOther)
{
  CBaseTrigger::EndTouch(this, pOther);
  if ( pOther != nullptr )
    pOther->IsPlayer(this: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x10242FF0
// Name: void Cmd_ShowtriggersToggle_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_ShowtriggersToggle_f(const CCommand *args)
{
  CBaseEntity *i; // esi
  const char *v2; // eax
  unsigned int v3; // ebx
  CBaseEdict *v4; // ecx

  for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
        i != nullptr;
        i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
  {
    if ( (__RTDynamicCast(
            inptr: i,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CBaseTrigger `RTTI Type Descriptor',
            isReference: 0) != nullptr
       || __RTDynamicCast(
            inptr: i,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CTriggerVPhysicsMotion `RTTI Type Descriptor',
            isReference: 0) != nullptr
       || __RTDynamicCast(
            inptr: i,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CTriggerVolume `RTTI Type Descriptor',
            isReference: 0) != nullptr)
      && (args->m_nArgc <= 1
       || (v2 = CCommand::operator[](this: args, nIndex: 1)) == nullptr
       || *v2 == 0
       || i->m_iClassname.pszValue == v2
       || CBaseEntity::ClassMatchesComplex(this: i, pszClassOrWildcard: v2) != 0) )
    {
      if ( (i->m_fEffects.m_Value & 0x20) != 0 )
      {
        v3 = i->m_fEffects.m_Value & 0xFFFFFFDF;
        if ( i->m_fEffects.m_Value != v3 )
        {
          if ( i->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&i->m_Network + 76) |= 1u;
          }
          else
          {
            v4 = &i->m_Network.m_pPev->CBaseEdict;
            if ( v4 != nullptr )
              CBaseEdict::StateChanged(this: v4, offset: 0xA4u);
          }
          i->m_fEffects.m_Value = v3;
        }
        if ( i->m_Network.m_pPev != nullptr )
          i->m_Network.m_pPev->m_fStateFlags |= 0x80u;
        CBaseEntity::DispatchUpdateTransmitState(this: i);
      }
      else
      {
        CBaseEntity::AddEffects(this: i, nEffects: 32);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10243110
// Name: public: CBaseTrigger::CBaseTrigger(void)
// Source: json
//------------------------------------------------------------------------------
CBaseTrigger *__thiscall CBaseTrigger::CBaseTrigger(CBaseTrigger *this)
{
  CBaseTrigger *result; // eax
  edict_t *m_pPev; // ecx

  CBaseToggle::CBaseToggle(this);
  this->__vftable = (CBaseTrigger_vtbl *)&CBaseTrigger::`vftable';
  this->m_hFilter.m_Index = -1;
  this->m_OnStartTouch.m_Value.iVal = 0;
  this->m_OnStartTouch.m_Value.eVal.m_Index = -1;
  this->m_OnStartTouch.m_Value.fieldType = FIELD_VOID;
  this->m_OnStartTouchAll.m_Value.iVal = 0;
  this->m_OnStartTouchAll.m_Value.eVal.m_Index = -1;
  this->m_OnStartTouchAll.m_Value.fieldType = FIELD_VOID;
  this->m_OnEndTouch.m_Value.iVal = 0;
  this->m_OnEndTouch.m_Value.eVal.m_Index = -1;
  this->m_OnEndTouch.m_Value.fieldType = FIELD_VOID;
  this->m_OnEndTouchAll.m_Value.iVal = 0;
  this->m_OnEndTouchAll.m_Value.eVal.m_Index = -1;
  this->m_OnEndTouchAll.m_Value.fieldType = FIELD_VOID;
  this->m_OnTouching.m_Value.iVal = 0;
  this->m_OnTouching.m_Value.eVal.m_Index = -1;
  this->m_OnTouching.m_Value.fieldType = FIELD_VOID;
  this->m_OnNotTouching.m_Value.iVal = 0;
  this->m_OnNotTouching.m_Value.eVal.m_Index = -1;
  this->m_OnNotTouching.m_Value.fieldType = FIELD_VOID;
  this->m_hTouchingEntities.m_Memory.m_pMemory = nullptr;
  this->m_hTouchingEntities.m_Memory.m_nAllocationCount = 0;
  this->m_hTouchingEntities.m_Memory.m_nGrowSize = 0;
  this->m_hTouchingEntities.m_Size = 0;
  this->m_hTouchingEntities.m_pElements = nullptr;
  this->m_iEFlags |= 0x40000u;
  result = this;
  if ( this->m_bClientSidePredicted.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bClientSidePredicted.m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x47Cu);
      this->m_bClientSidePredicted.m_Value = false;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10243200
// Name: public: virtual void CBaseTrigger::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::Spawn(CBaseTrigger *this)
{
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  int v3; // edi
  edict_t *m_pPev; // ecx
  int v5; // edi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v6; // eax
  CBaseEdict *v7; // ecx
  int v8; // edi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v9; // eax
  CBaseEdict *v10; // ecx

  m_Value = this->m_spawnflags.m_Value;
  p_m_spawnflags = &this->m_spawnflags;
  if ( (m_Value & 0x10) != 0 || (m_Value & 0x800) != 0 )
  {
    v3 = p_m_spawnflags->m_Value | 2;
    if ( p_m_spawnflags->m_Value != v3 )
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
      p_m_spawnflags->m_Value = v3;
    }
  }
  if ( (p_m_spawnflags->m_Value & 0x20) != 0 )
  {
    v5 = p_m_spawnflags->m_Value | 1;
    if ( p_m_spawnflags->m_Value != v5 )
    {
      v6 = p_m_spawnflags - 190;
      if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
      {
        LOBYTE(v6[22].m_Value) |= 1u;
      }
      else
      {
        v7 = (CBaseEdict *)v6[6].m_Value;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: v7, offset: 0x2F8u);
      }
      p_m_spawnflags->m_Value = v5;
    }
  }
  if ( (p_m_spawnflags->m_Value & 0x200) != 0 )
  {
    v8 = p_m_spawnflags->m_Value | 1;
    if ( p_m_spawnflags->m_Value != v8 )
    {
      v9 = p_m_spawnflags - 190;
      if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
      {
        LOBYTE(v9[22].m_Value) |= 1u;
        p_m_spawnflags->m_Value = v8;
        CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
        return;
      }
      v10 = (CBaseEdict *)v9[6].m_Value;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: v10, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v8;
    }
  }
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x102432F0
// Name: public: virtual void CBaseTrigger::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::StartTouch(CBaseTrigger *this, CBaseEntity *pOther)
{
  CBaseTrigger *v2; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_hTouchingEntities; // esi
  char v4; // bl
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v8; // eax
  CHandle<CBaseEntity> *v9; // edi
  CHandle<CBaseEntity> hOther; // [esp+18h] [ebp-4h] BYREF

  v2 = this;
  if ( ((unsigned __int8 (__stdcall *)(CBaseEntity *))this->PassesTriggerFilters)(a1: pOther) != 0 )
  {
    if ( pOther != nullptr )
      hOther.m_Index = pOther->GetRefEHandle(this: pOther)->m_Index;
    else
      hOther.m_Index = -1;
    p_m_hTouchingEntities = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_hTouchingEntities;
    v4 = 0;
    if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: &v2->m_hTouchingEntities,
           src: &hOther) == -1 )
    {
      m_Size = v2->m_hTouchingEntities.m_Size;
      m_nAllocationCount = p_m_hTouchingEntities->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_hTouchingEntities, num: m_Size - m_nAllocationCount + 1);
      ++p_m_hTouchingEntities[1].m_pMemory;
      m_pMemory = p_m_hTouchingEntities->m_pMemory;
      v8 = (int)p_m_hTouchingEntities[1].m_pMemory - m_Size - 1;
      p_m_hTouchingEntities[1].m_nAllocationCount = (int)p_m_hTouchingEntities->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v9 = (CHandle<CBaseEntity> *)&p_m_hTouchingEntities->m_pMemory[m_Size];
      if ( v9 != nullptr )
        v9->m_Index = hOther.m_Index;
      v2 = this;
      v4 = 1;
    }
    COutputEvent::FireOutput(this: &v2->m_OnStartTouch, pActivator: pOther, pCaller: v2, fDelay: 0.0);
    if ( v4 != 0 && v2->m_hTouchingEntities.m_Size == 1 )
      v2->OnStartTouchAll(this: v2, a2: pOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102434A0
// Name: public: bool CTriggerHurt::HurtEntity(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTriggerHurt::HurtEntity(CTriggerHurt *this, CBaseEntity *pOther, float damage)
{
  Vector *v5; // eax
  bool v6; // zf
  bool v7; // al
  COutputEvent *p_m_OnHurtPlayer; // ecx
  const CBaseHandle *v9; // eax
  int m_Size; // edi
  unsigned int m_Index; // ebx
  int m_nAllocationCount; // eax
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int v14; // eax
  CHandle<CBaseEntity> *v15; // edi
  CTakeDamageInfo info; // [esp+20h] [ebp-80h] BYREF
  Vector vecForceDir; // [esp+7Ch] [ebp-24h] BYREF
  Vector vecDamagePos; // [esp+88h] [ebp-18h] BYREF
  Vector vecCenter; // [esp+94h] [ebp-Ch] BYREF
  Vector *pOthera; // [esp+A8h] [ebp+8h]

  if ( pOther->m_takedamage.m_Value == 0 || !this->PassesTriggerFilters(this, a2: pOther) )
    return 0;
  if ( damage >= 0.0 )
  {
    pOthera = AllocTempVector();
    v5 = AllocTempVector();
    v5->x = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x) * 0.5)
          + this->m_Collision.m_vecMins.m_Value.x;
    v5->y = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y) * 0.5)
          + this->m_Collision.m_vecMins.m_Value.y;
    v5->z = (float)((float)(this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z) * 0.5)
          + this->m_Collision.m_vecMins.m_Value.z;
    CCollisionProperty::CollisionToWorldSpace(this: &this->m_Collision, in: v5, pResult: pOthera);
    vecCenter = *pOthera;
    CCollisionProperty::CalcNearestPoint(
      this: &pOther->m_Collision,
      vecWorldPt: &vecCenter,
      pVecNearestWorldPt: &vecDamagePos);
    CTakeDamageInfo::CTakeDamageInfo(
      this: &info,
      pInflictor: this,
      pAttacker: this,
      flDamage: damage,
      bitsDamageType: this->m_bitsDamageInflict,
      iKillType: 0,
      iObjectsPenetrated: 0);
    v6 = !this->m_bNoDmgForce;
    info.m_vecDamagePosition = vecDamagePos;
    if ( v6 )
    {
      vecForceDir.x = vecDamagePos.x - vecCenter.x;
      vecForceDir.y = vecDamagePos.y - vecCenter.y;
      vecForceDir.z = vecDamagePos.z - vecCenter.z;
      GuessDamageForce(&info, &vecForceDir, vecForceOrigin: &vecDamagePos, flScale: 1.0);
    }
    else
    {
      info.m_vecDamageForce = vec3_origin;
    }
    CBaseEntity::TakeDamage(this: pOther, a2: (int)this, inputInfo: &info);
  }
  else
  {
    ((void (__thiscall *)(CBaseEntity *, _DWORD, int))pOther->TakeHealth)(
      a1: pOther,
      a2: LODWORD(damage) ^ _mask__NegFloat_,
      a3: this->m_bitsDamageInflict);
  }
  v7 = pOther->IsPlayer(this: pOther);
  p_m_OnHurtPlayer = &this->m_OnHurtPlayer;
  if ( !v7 )
    p_m_OnHurtPlayer = &this->m_OnHurt;
  COutputEvent::FireOutput(this: p_m_OnHurtPlayer, pActivator: pOther, pCaller: this, fDelay: 0.0);
  v9 = pOther->GetRefEHandle(this: pOther);
  m_Size = this->m_hurtEntities.m_Size;
  m_Index = v9->m_Index;
  m_nAllocationCount = this->m_hurtEntities.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hurtEntities,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_hurtEntities.m_Size;
  m_pMemory = this->m_hurtEntities.m_Memory.m_pMemory;
  v14 = this->m_hurtEntities.m_Size - m_Size - 1;
  this->m_hurtEntities.m_pElements = m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
  v15 = &this->m_hurtEntities.m_Memory.m_pMemory[m_Size];
  if ( v15 != nullptr )
    v15->m_Index = m_Index;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10243720
// Name: public: virtual void CTriggerHurt::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerHurt::EndTouch(CTriggerHurt *this, CHandle<CBaseEntity> pOther)
{
  CBaseEntity *m_Index; // edi

  m_Index = (CBaseEntity *)pOther.m_Index;
  if ( this->PassesTriggerFilters(this, a2: (CBaseEntity *)pOther.m_Index) )
  {
    if ( m_Index != nullptr )
      pOther.m_Index = m_Index->GetRefEHandle(this: m_Index)->m_Index;
    else
      pOther.m_Index = -1;
    if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: &this->m_hurtEntities,
           src: &pOther) < 0 )
      CTriggerHurt::HurtEntity(this, pOther: m_Index, damage: this->m_flDamage * 0.5);
  }
  CBaseTrigger::EndTouch(this, pOther: m_Index);
}

//------------------------------------------------------------------------------
// Address: 0x102437A0
// Name: public: int CTriggerHurt::HurtAllTouchers(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTriggerHurt::HurtAllTouchers(CTriggerHurt *this, float dt)
{
  float damage; // xmm0_4
  int v4; // edi
  unsigned int *DataObject; // eax
  unsigned int *v6; // ebx
  unsigned int *v7; // edi
  unsigned int v8; // eax
  CBaseEntity *m_pEntity; // ecx
  int result; // eax
  float v11; // xmm0_4
  float m_flDamageCap; // xmm1_4
  int hurtCount; // [esp+10h] [ebp-4h]

  damage = dt * this->m_flDamage;
  this->m_flLastDmgTime = gpGlobals->curtime;
  v4 = 0;
  hurtCount = 0;
  this->m_hurtEntities.m_Size = 0;
  DataObject = (unsigned int *)CBaseEntity::GetDataObject(this, type: 1);
  v6 = DataObject;
  if ( DataObject != nullptr )
  {
    v7 = (unsigned int *)DataObject[2];
    if ( v7 != DataObject )
    {
      do
      {
        v8 = *v7;
        if ( *v7 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber == HIWORD(v8) )
        {
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
          if ( m_pEntity != nullptr && CTriggerHurt::HurtEntity(this, pOther: m_pEntity, damage) != 0 )
            ++hurtCount;
        }
        v7 = (unsigned int *)v7[2];
      }
      while ( v7 != v6 );
    }
    v4 = hurtCount;
  }
  if ( this->m_damageModel != 1 )
    return v4;
  if ( v4 != 0 )
  {
    v11 = this->m_flDamage * 2.0;
    m_flDamageCap = this->m_flDamageCap;
    this->m_flDamage = v11;
    if ( v11 > m_flDamageCap )
      this->m_flDamage = m_flDamageCap;
    this->m_flDmgResetTime = gpGlobals->curtime + 3.0;
    return v4;
  }
  result = 0;
  if ( gpGlobals->curtime > this->m_flDmgResetTime )
    this->m_flDamage = this->m_flOriginalDamage;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10243AA0
// Name: public: virtual void CTriggerMultiple::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerMultiple::Spawn(CTriggerMultiple *this)
{
  float m_flWait; // xmm0_4

  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
  m_flWait = this->m_flWait;
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CTriggerMultiple::MultiTouch;
  if ( m_flWait == 0.0 )
    this->m_flWait = 0.2;
}

//------------------------------------------------------------------------------
// Address: 0x10243AE0
// Name: public: virtual void CTriggerOnce::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerOnce::Spawn(CTriggerOnce *this)
{
  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
  if ( this->m_flWait == 0.0 )
    this->m_flWait = 0.2;
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CTriggerMultiple::MultiTouch;
  this->m_flWait = -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10243D40
// Name: public: virtual void CTriggerLook::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerLook::Spawn(CTriggerLook *this)
{
  this->m_hLookTarget.m_Index = -1;
  this->m_flLookTimeTotal = -1.0;
  this->m_bTimeoutFired = false;
  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
  if ( this->m_flWait == 0.0 )
    this->m_flWait = 0.2;
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CTriggerMultiple::MultiTouch;
  this->m_flWait = -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10243DC0
// Name: public: virtual void CTriggerLook::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerLook::StartTouch(CTriggerLook *this, CBaseEntity *pOther)
{
  CBaseTrigger::StartTouch(this, pOther);
  if ( pOther->IsPlayer(this: pOther) && this->m_flTimeoutDuration != 0.0 )
  {
    this->m_bTimeoutFired = false;
    this->m_hActivator.m_Index = pOther->GetRefEHandle(this: pOther)->m_Index;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CTriggerLook::TimeoutThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + this->m_flTimeoutDuration, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10243E50
// Name: TestEntityTriggerIntersection_Accurate
// Source: json
//------------------------------------------------------------------------------
bool __usercall TestEntityTriggerIntersection_Accurate@<al>(
        CBaseEntity *pEntity@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseEntity *a5)
{
  void *v5; // esp
  int v7; // eax
  int v8; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v10; // edx
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  const Vector *v12; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v13; // edx
  const Vector *v14; // edi
  IVModelInfo_vtbl *v15; // edi
  int v16; // eax
  struct CPhysCollide *v17; // ecx
  int (__thiscall *VPhysicsGetObjectList)(CBaseEntity *, IPhysicsObject **, int); // edx
  int v19; // eax
  int v20; // edi
  int v21; // esi
  CBaseEntity *v22; // eax
  int v23; // ecx
  IVModelInfo_vtbl *v24; // edi
  int v25; // eax
  int v26; // eax
  int v27; // edi
  Vector *p_prevAbsOrigin; // esi
  CBaseEntity *v29; // ecx
  _DWORD v31[1024]; // [esp-10E0h] [ebp-10ECh] BYREF
  Ray_t v32; // [esp-E0h] [ebp-ECh] BYREF
  _BYTE v33[88]; // [esp-90h] [ebp-9Ch] BYREF
  TeleportListEntry_t v34; // [esp-38h] [ebp-44h] BYREF
  const Vector *v35; // [esp-1Ch] [ebp-28h]
  CUtlVector<TeleportListEntry_t,CUtlMemory<TeleportListEntry_t,int> > v36; // [esp-18h] [ebp-24h] BYREF
  ICollideable *p_m_Collision; // [esp-4h] [ebp-10h]
  _DWORD v38[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v38[0] = a2;
  v38[1] = retaddr;
  v5 = alloca(4328);
  if ( !CBaseEntity::Intersects(this: a5, pOther: pEntity) )
    return false;
  v7 = ((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int, int))pEntity->m_Collision.GetSolid)(
         a1: &pEntity->m_Collision,
         a2: a3,
         a3: a4)
     - 1;
  if ( v7 != 0 )
  {
    v8 = v7 - 1;
    if ( v8 == 0 )
    {
      v10 = pEntity->m_Collision.__vftable;
      p_m_Collision = &a5->m_Collision;
      OBBMaxs = v10->OBBMaxs;
      v32.m_pWorldAxisTransform = nullptr;
      v12 = OBBMaxs(this: &pEntity->m_Collision);
      v13 = pEntity->m_Collision.__vftable;
      v35 = v12;
      v14 = v13->OBBMins(this: &pEntity->m_Collision);
      if ( (pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)v38);
      if ( (pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)v38);
      Ray_t::Init(this: &v32, start: &pEntity->m_vecAbsOrigin, end: &pEntity->m_vecAbsOrigin, mins: v14, maxs: v35);
      enginetrace->ClipRayToCollideable(this: enginetrace, a2: &v32, a3: -1u, a4: p_m_Collision, a5: (CGameTrace *)v33);
      return v33[55] != 0;
    }
    if ( v8 != 4 )
      return true;
  }
  v15 = modelinfo->__vftable;
  v16 = a5->GetModelIndex(this: a5);
  v17 = *v15->GetVCollide(this: modelinfo, a2: v16)->solids;
  VPhysicsGetObjectList = pEntity->VPhysicsGetObjectList;
  memset(&v36, 0, sizeof(v36));
  p_m_Collision = (ICollideable *)v17;
  v19 = VPhysicsGetObjectList(this: pEntity, a2: (IPhysicsObject **)v31, a3: 1024);
  v20 = v19;
  if ( v19 != 0 )
  {
    v21 = 0;
    if ( v19 > 0 )
    {
      do
      {
        v22 = (CBaseEntity *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)v31[v21] + 296))(a1: v31[v21]);
        if ( v22 != nullptr )
        {
          v23 = v31[v21];
          v34.pEntity = v22;
          (*(void (__thiscall **)(int, Vector *, QAngle *))(*(_DWORD *)v23 + 192))(
            a1: v23,
            a2: &v34.prevAbsOrigin,
            a3: &v34.prevAbsAngles);
          CUtlVector<collidelist_t,CUtlMemory<collidelist_t,int>>::InsertBefore(this: &v36, elem: v36.m_Size, src: &v34);
        }
        ++v21;
      }
      while ( v21 < v20 );
    }
  }
  else
  {
    v24 = modelinfo->__vftable;
    v25 = pEntity->GetModelIndex(this: pEntity);
    v26 = (int)v24->GetVCollide(this: modelinfo, a2: v25);
    if ( v26 != 0 && (*(_WORD *)v26 & 0x7FFF) != 0 )
    {
      v34.pEntity = **(CBaseEntity ***)(v26 + 4);
      v34.prevAbsOrigin = *CBaseEntity::GetAbsOrigin(this: pEntity);
      v34.prevAbsAngles = *CBaseEntity::GetAbsAngles(this: pEntity);
      CUtlVector<collidelist_t,CUtlMemory<collidelist_t,int>>::InsertBefore(this: &v36, elem: 0, src: &v34);
    }
  }
  v27 = v36.m_Size - 1;
  if ( v36.m_Size - 1 < 0 )
  {
LABEL_29:
    if ( v36.m_Memory.m_nGrowSize >= 0 && v36.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v36.m_Memory.m_pMemory);
    return false;
  }
  p_prevAbsOrigin = &v36.m_Memory.m_pMemory[v27].prevAbsOrigin;
  while ( 1 )
  {
    v29 = a5;
    if ( (a5->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: a5, a2: (int)v38);
      v29 = a5;
    }
    if ( (v29->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v29, a2: (int)v38);
      v29 = a5;
    }
    physcollision->TraceCollide(
      this: physcollision,
      a2: p_prevAbsOrigin,
      a3: p_prevAbsOrigin,
      a4: (const struct CPhysCollide *)LODWORD(p_prevAbsOrigin[-1].z),
      a5: (const QAngle *)&p_prevAbsOrigin[1],
      a6: (const struct CPhysCollide *)p_m_Collision,
      a7: &v29->m_vecAbsOrigin,
      a8: &v29->m_angAbsRotation,
      a9: (CGameTrace *)v33);
    if ( v33[55] != 0 )
      break;
    p_prevAbsOrigin = (Vector *)((char *)p_prevAbsOrigin - 28);
    if ( --v27 < 0 )
      goto LABEL_29;
  }
  if ( v36.m_Memory.m_nGrowSize >= 0 && v36.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v36.m_Memory.m_pMemory);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10244190
// Name: private: static int CChangeLevel::InTransitionVolume(class CBaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CChangeLevel::InTransitionVolume(CBaseEntity *pEntity, const char *pVolumeName)
{
  CBaseEntity *RootMoveParent; // ebx
  CBaseEntity *EntityByName; // esi
  int savedregs; // [esp+4h] [ebp+0h] BYREF
  int inVolume; // [esp+Ch] [ebp+8h]

  if ( (pEntity->ObjectCaps(this: pEntity) & 0x100) != 0 )
    return 2;
  RootMoveParent = CBaseEntity::GetRootMoveParent(this: pEntity);
  inVolume = 1;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pVolumeName,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName == nullptr )
    return inVolume;
  while ( 1 )
  {
    if ( EntityByName->m_iClassname.pszValue == "trigger_transition"
      || CBaseEntity::ClassMatchesComplex(this: EntityByName, pszClassOrWildcard: "trigger_transition") != 0 )
    {
      if ( TestEntityTriggerIntersection_Accurate(
             pEntity: RootMoveParent,
             a2: (int)&savedregs,
             a3: (int)pVolumeName,
             a4: (int)EntityByName,
             a5: EntityByName) )
      {
        break;
      }
      inVolume = 0;
    }
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: EntityByName,
                     szName: pVolumeName,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName == nullptr )
      return inVolume;
  }
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10244240
// Name: private: static int CChangeLevel::BuildEntityTransitionList(class CBaseEntity __near *,char const __near *,class CBaseEntity __near * __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CChangeLevel::BuildEntityTransitionList(
        CBaseEntity *pLandmarkEntity,
        const char *pLandmarkName,
        CBaseEntity **ppEntList,
        int *pEntityFlags,
        int nMaxList)
{
  ConVar *m_pParent; // eax
  int v6; // ebx
  CBaseEntity *v7; // esi
  int m_nValue; // eax
  CBaseEntity *v9; // esi
  int v10; // edi
  const char *pszValue; // edi
  const char *DebugName; // eax

  m_pParent = g_debug_transitions.m_pParent;
  v6 = 0;
  if ( g_debug_transitions.m_pParent == nullptr || g_debug_transitions.m_pParent->m_Value.m_nValue == 0 )
  {
    v7 = pLandmarkEntity;
    goto LABEL_10;
  }
  v7 = pLandmarkEntity;
  if ( pLandmarkEntity->m_iName.m_Value.pszValue != st_szNextSpot )
  {
    if ( CBaseEntity::NameMatchesComplex(this: pLandmarkEntity, pszNameOrWildcard: st_szNextSpot) == 0 )
    {
LABEL_10:
      g_iDebuggingTransition = 0;
      goto LABEL_11;
    }
    m_pParent = g_debug_transitions.m_pParent;
  }
  if ( m_pParent != nullptr )
  {
    m_nValue = m_pParent->m_Value.m_nValue;
    pLandmarkEntity->m_debugOverlays |= 0xEu;
    g_iDebuggingTransition = m_nValue;
  }
  else
  {
    pLandmarkEntity->m_debugOverlays |= 0xEu;
    g_iDebuggingTransition = 0;
  }
LABEL_11:
  v9 = UTIL_EntitiesInPVS(pPVSEntity: v7, pStartingEntity: nullptr);
  if ( v9 != nullptr )
  {
    while ( 1 )
    {
      v10 = CChangeLevel::ComputeEntitySaveFlags(pEntity: v9);
      if ( v10 != 0 )
      {
        if ( CChangeLevel::InTransitionVolume(pEntity: v9, pVolumeName: pLandmarkName) != 0 )
        {
          if ( v6 >= nMaxList )
          {
            _Warning(a1: "Too many entities across a transition!\n");
            return v6;
          }
          ppEntList[v6] = v9;
          pEntityFlags[v6] = v10;
          if ( g_iDebuggingTransition != 0 )
          {
            if ( g_iDebuggingTransition == 2 )
            {
              _Msg(a1: "ADDED.\n");
            }
            else
            {
              pszValue = v9->m_iClassname.pszValue;
              if ( pszValue == nullptr )
                pszValue = locale;
              DebugName = CBaseEntity::GetDebugName(this: v9);
              _Msg(a1: "ADDED %s (%s) to transition.\n", pszValue, DebugName);
            }
            v9->m_debugOverlays |= 6u;
          }
          ++v6;
        }
        else if ( g_iDebuggingTransition == 2 )
        {
          _Msg(a1: "IGNORED, outside transition volume.\n");
        }
      }
      v9 = UTIL_EntitiesInPVS(pPVSEntity: pLandmarkEntity, pStartingEntity: v9);
      if ( v9 == nullptr )
        return v6;
    }
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10244390
// Name: public: static int CChangeLevel::ChangeList(struct levellist_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CChangeLevel::ChangeList(levellist_t *pLevelList, int maxList)
{
  int v2; // esi
  bool v3; // zf
  CSaveRestoreData *pSaveData; // eax
  char *landmarkName; // esi
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // eax
  CBaseEntity *v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // ebx
  int j; // edi
  int v13; // eax
  int pEntityFlags[512]; // [esp+8h] [ebp-1034h] BYREF
  CBaseEntity *ppEntList[512]; // [esp+808h] [ebp-834h] BYREF
  CSave v17; // [esp+1008h] [ebp-34h] BYREF
  int v18; // [esp+1030h] [ebp-Ch]
  char *i; // [esp+1034h] [ebp-8h]
  int v20; // [esp+1038h] [ebp-4h]

  v2 = CChangeLevel::BuildChangeLevelList(pLevelList, maxList);
  v3 = gpGlobals->pSaveData == nullptr;
  v18 = v2;
  if ( !v3 )
  {
    pSaveData = gpGlobals->pSaveData;
    if ( pSaveData->tableCount != 0 )
    {
      CSave::CSave(this: &v17, pdata: pSaveData);
      v20 = 0;
      if ( v2 > 0 )
      {
        landmarkName = pLevelList->landmarkName;
        for ( i = pLevelList->landmarkName; ; landmarkName = i )
        {
          if ( ((pEdicts = *((edict_t **)landmarkName + 8)) != nullptr
             || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0)
            && (m_pUnk = pEdicts->m_pUnk) != nullptr )
          {
            v8 = m_pUnk->GetBaseEntity(this: m_pUnk);
          }
          else
          {
            v8 = nullptr;
          }
          v9 = CChangeLevel::BuildEntityTransitionList(
                 pLandmarkEntity: v8,
                 pLandmarkName: landmarkName,
                 ppEntList,
                 pEntityFlags,
                 nMaxList: 512);
          v10 = 0;
          v11 = v9;
          for ( j = __ROL4__(1, v20); v10 < v11; ++v10 )
          {
            v13 = CSave::EntityIndex(this: &v17, pEntity: ppEntList[v10]);
            CSave::EntityFlagsSet(this: &v17, entityIndex: v13, flags: j | pEntityFlags[v10]);
          }
          i += 80;
          if ( ++v20 >= v18 )
            break;
        }
        v2 = v18;
      }
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v17.m_BlockStartStack);
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10244530
// Name: public: virtual void CTriggerPush::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerPush::Spawn(CTriggerPush *this)
{
  Vector *p_m_vecPushDir; // edi
  Vector vecAbsDir; // [esp+4h] [ebp-18h] BYREF
  QAngle angPushDir; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  p_m_vecPushDir = &this->m_vecPushDir;
  angPushDir = (QAngle)this->m_vecPushDir;
  AngleVectors(angles: &angPushDir, forward: &vecAbsDir);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  VectorIRotate(in1: &vecAbsDir.x, in2: &this->m_rgflCoordinateFrame, out: &p_m_vecPushDir->x);
  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
  if ( this->m_flSpeed == 0.0 )
    this->m_flSpeed = 100.0;
}

//------------------------------------------------------------------------------
// Address: 0x10244850
// Name: public: virtual void CTriggerGravity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerGravity::Spawn(CTriggerGravity *this)
{
  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CTriggerGravity::GravityTouch;
}

//------------------------------------------------------------------------------
// Address: 0x10244970
// Name: public: virtual void CTriggerCamera::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::Spawn(CTriggerCamera *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  float m_acceleration; // xmm1_4

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NOCLIP, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( this->m_clrRender.m_Value.a != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = 0;
  }
  if ( this->m_nRenderMode.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = 2;
  }
  m_acceleration = this->m_acceleration;
  this->m_initialSpeed = this->m_flSpeed;
  this->m_state = 0;
  if ( m_acceleration == 0.0 )
    this->m_acceleration = 500.0;
  if ( this->m_deceleration == 0.0 )
    this->m_deceleration = 500.0;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10244A60
// Name: public: void CTriggerCamera::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTriggerCamera::InputDisable(CTriggerCamera *this, inputdata_t *inputdata)
{
  CTriggerCamera::Disable(this);
}

//------------------------------------------------------------------------------
// Address: 0x10244A70
// Name: public: void CTriggerCamera::InputReturnToEyes(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::InputReturnToEyes(CTriggerCamera *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CBasePlayer **v9; // eax
  CBasePlayer *v10; // eax

  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr && (this->m_spawnflags.m_Value & 0x80) != 0 )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = (CBasePlayer **)&g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        v10 = *v9;
      else
        v10 = nullptr;
      CBasePlayer::SetFOV(this: v10, pRequester: this, FOV: 0, zoomRate: this->m_fovSpeed, iZoomStart: 0);
    }
  }
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CTriggerCamera::ReturnToEyes,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10244B20
// Name: public: void CTriggerCamera::FollowTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTriggerCamera::FollowTarget(CTriggerCamera *this@<ecx>, float a2@<ebp>)
{
  unsigned int m_Index; // eax
  unsigned int v4; // eax
  int m_iAttachmentIndex; // edi
  CHandle<CBaseEntity> *p_m_hTarget; // ecx
  CBaseEntity *v7; // eax
  CBaseAnimating *v8; // eax
  const Vector *AbsOrigin; // edi
  CBaseEntity *v10; // eax
  const Vector *v11; // eax
  __int128 v12; // xmm0
  _QWORD v13[2]; // [esp+18h] [ebp-3Ch] BYREF
  Vector v14; // [esp+30h] [ebp-24h] BYREF
  Vector vecOrigin; // [esp+3Ch] [ebp-18h] BYREF
  QAngle vecGoal; // [esp+48h] [ebp-Ch] BYREF
  float retaddr; // [esp+54h] [ebp+0h]

  vecGoal.x = a2;
  vecGoal.y = retaddr;
  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v4 = this->m_hTarget.m_Index;
    if ( v4 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == HIWORD(v4)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity != nullptr
      && ((this->m_spawnflags.m_Value & 8) != 0
       || !CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hTarget)
       && gpGlobals->curtime <= this->m_flReturnTime) )
    {
      m_iAttachmentIndex = this->m_iAttachmentIndex;
      p_m_hTarget = &this->m_hTarget;
      if ( m_iAttachmentIndex != 0 )
      {
        v7 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hTarget);
        v8 = v7->GetBaseAnimating(this: v7);
        CBaseAnimating::GetAttachment(
          this: v8,
          iAttachment: m_iAttachmentIndex,
          absOrigin: &v14,
          forward: nullptr,
          right: nullptr,
          up: nullptr);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecGoal);
        *((float *)v13 + 1) = v14.x - this->m_vecAbsOrigin.x;
        *(float *)&v13[1] = v14.y - this->m_vecAbsOrigin.y;
        *((float *)&v13[1] + 1) = v14.z - this->m_vecAbsOrigin.z;
        VectorAngles(forward: (const Vector *)((char *)v13 + 4), angles: (QAngle *)&vecOrigin);
      }
      else if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hTarget) != nullptr )
      {
        AbsOrigin = CBaseEntity::GetAbsOrigin(this);
        v10 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget);
        v11 = CBaseEntity::GetAbsOrigin(this: v10);
        *((float *)v13 + 1) = v11->x - AbsOrigin->x;
        *(float *)&v13[1] = v11->y - AbsOrigin->y;
        *((float *)&v13[1] + 1) = v11->z - AbsOrigin->z;
        VectorAngles(forward: (const Vector *)((char *)v13 + 4), angles: (QAngle *)&vecOrigin);
      }
      else
      {
        vecOrigin = (Vector)*CBaseEntity::GetAbsAngles(this);
      }
      if ( this->m_bSnapToGoal )
      {
        CBaseEntity::SetAbsAngles(this, absAngles: (const QAngle *)&vecOrigin);
        this->m_bSnapToGoal = false;
      }
      else
      {
        CTriggerCamera::MoveViewTo(this, vecGoalView: (QAngle)vecOrigin);
      }
      if ( (this->m_spawnflags.m_Value & 4) == 0 )
      {
        if ( (this->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&vecGoal);
        *((float *)v13 + 1) = this->m_vecAbsVelocity.x * 0.80000001;
        *(float *)&v13[1] = this->m_vecAbsVelocity.y * 0.80000001;
        *((float *)&v13[1] + 1) = this->m_vecAbsVelocity.z * 0.80000001;
        CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: (const Vector *)((char *)v13 + 4));
        if ( (this->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&vecGoal);
        v12 = 0;
        *(float *)&v12 = fsqrt(
                           (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                                 + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
                         + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z));
        *(_OWORD *)v13 = v12;
        if ( *(float *)&v12 < 10.0 )
          CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
      }
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
      CTriggerCamera::Move(this);
    }
    else
    {
      CTriggerCamera::Disable(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10244E30
// Name: public: virtual void CMoveableCamera::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveableCamera::Spawn(CMoveableCamera *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  bool v4; // al

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NOCLIP, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( this->m_clrRender.m_Value.a != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = 0;
  }
  if ( this->m_nRenderMode.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = 2;
  }
  v4 = this->m_spawnflags.m_Value & 1;
  this->m_bEnabled = false;
  this->m_bMovementStarted = false;
  this->m_bDisableOnMoveEnd = v4;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10244EE0
// Name: public: CTriggerCameraMultiplayer::CTriggerCameraMultiplayer(void)
// Source: json
//------------------------------------------------------------------------------
CTriggerCameraMultiplayer *__thiscall CTriggerCameraMultiplayer::CTriggerCameraMultiplayer(
        CTriggerCameraMultiplayer *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->m_hTargetEnt.m_Index = -1;
  this->m_flInterpTime = 1.0;
  this->__vftable = (CTriggerCameraMultiplayer_vtbl *)&CTriggerCameraMultiplayer::`vftable';
  this->m_players.m_Memory.m_pMemory = nullptr;
  this->m_players.m_Memory.m_nAllocationCount = 0;
  this->m_players.m_Memory.m_nGrowSize = 0;
  this->m_players.m_Size = 0;
  this->m_players.m_pElements = nullptr;
  this->m_nTeamNum = -1;
  this->m_fov = 90.0;
  this->m_fovSpeed = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10244F50
// Name: public: virtual void CTriggerCameraMultiplayer::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCameraMultiplayer::Spawn(CTriggerCameraMultiplayer *this)
{
  CMoveableCamera::Spawn(this);
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10244F60
// Name: public: void CTriggerCameraMultiplayer::InputRemovePlayer(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCameraMultiplayer::InputRemovePlayer(CTriggerCameraMultiplayer *this, inputdata_t *inputdata)
{
  CBasePlayer *pActivator; // esi
  int v4; // eax
  int m_Size; // edx

  pActivator = (CBasePlayer *)inputdata->pActivator;
  if ( inputdata->pActivator != nullptr && pActivator->IsPlayer(this: inputdata->pActivator) )
  {
    CTriggerCameraMultiplayer::RemovePlayer(this, player: pActivator);
    inputdata = (inputdata_t *)pActivator->GetRefEHandle(this: pActivator)->m_Index;
    v4 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: &this->m_players,
           src: (CHandle<CBaseEntity> *)&inputdata);
    if ( v4 != -1 )
    {
      m_Size = this->m_players.m_Size;
      if ( m_Size > 0 )
      {
        if ( v4 != m_Size - 1 )
          this->m_players.m_Memory.m_pMemory[v4].m_Index = this->m_players.m_Memory.m_pMemory[m_Size - 1].m_Index;
        --this->m_players.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10244FE0
// Name: public: void CTriggerCameraMultiplayer::AddPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCameraMultiplayer::AddPlayer(CTriggerCameraMultiplayer *this, unsigned int player)
{
  unsigned int v2; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int v7; // eax
  CHandle<CBaseEntity> *v8; // edi
  unsigned int v9; // eax
  CBaseEntity **v10; // ecx
  CBaseEntity *v11; // esi

  v2 = player;
  if ( player != 0 )
    player = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)player + 8))(a1: player);
  else
    player = -1;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: &this->m_players,
         src: (CHandle<CBaseEntity> *)&player) < 0 )
  {
    if ( v2 != 0 )
      player = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 8))(a1: v2);
    else
      player = -1;
    m_nAllocationCount = this->m_players.m_Memory.m_nAllocationCount;
    m_Size = this->m_players.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_players,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_players.m_Size;
    m_pMemory = this->m_players.m_Memory.m_pMemory;
    v7 = this->m_players.m_Size - m_Size - 1;
    this->m_players.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_players.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      v8->m_Index = player;
    CBasePlayer::EnableControl(this: (CBasePlayer *)v2, fControl: false);
    if ( *(_BYTE *)(v2 + 2424) != 0 )
    {
      (**(void (__thiscall ***)(int, int))(v2 + 2288))(a1: v2 + 2288, a2: v2 + 2424);
      *(_BYTE *)(v2 + 2424) = 0;
    }
    CBasePlayer::SetViewEntity(this: (CBasePlayer *)v2, pEntity: this, bShouldDrawPlayer: true);
    v9 = *(_DWORD *)(v2 + 3176);
    if ( v9 != -1 )
    {
      v10 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v9];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber == HIWORD(v9) )
      {
        v11 = *v10;
        if ( *v10 != nullptr
          && (v11 == (CBaseEntity *)v2
           || v11->m_iClassname.pszValue == "point_viewcontrol_multiplayer"
           || CBaseEntity::ClassMatchesComplex(this: v11, pszClassOrWildcard: "point_viewcontrol_multiplayer") != 0
           || FClassnameIs(pEntity: v11, szClassname: "point_viewcontrol_survivor")) )
        {
          CBasePlayer::ClearZoomOwner(this: (CBasePlayer *)v2);
        }
      }
    }
    CBasePlayer::SetFOV(
      this: (CBasePlayer *)v2,
      pRequester: this,
      FOV: (int)this->m_fov,
      zoomRate: this->m_fovSpeed,
      iZoomStart: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10245170
// Name: public: virtual void CTriggerViewProxy::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTriggerViewProxy::Spawn(CTriggerViewProxy *this@<ecx>, int a2@<ebp>)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  const char *pszValue; // eax
  int v6; // xmm1_4
  float m_flTiltFraction; // xmm0_4
  CBaseEntity *m_pProxy; // edi

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NOCLIP, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( this->m_clrRender.m_Value.a != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = 0;
  }
  if ( this->m_nRenderMode.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = 2;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  this->m_vecInitialPosition.x = this->m_vecAbsOrigin.x;
  this->m_vecInitialPosition.y = this->m_vecAbsOrigin.y;
  this->m_vecInitialPosition.z = this->m_vecAbsOrigin.z;
  pszValue = this->m_sProxy.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v6 = 0;
  this->m_pProxy = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
  this->m_state = 0;
  m_flTiltFraction = this->m_flTiltFraction;
  if ( m_flTiltFraction < 0.0 || (v6 = 1065353216, m_flTiltFraction > 1.0) )
    m_flTiltFraction = *(float *)&v6;
  this->m_flTiltFraction = m_flTiltFraction;
  CBaseEntity::DispatchUpdateTransmitState(this);
  this->m_vecInitialOffset = vec3_origin;
  m_pProxy = this->m_pProxy;
  if ( m_pProxy != nullptr )
  {
    if ( (m_pProxy->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pProxy, a2);
    this->m_vecLastPosition.x = m_pProxy->m_vecAbsOrigin.x;
    this->m_vecLastPosition.y = m_pProxy->m_vecAbsOrigin.y;
    this->m_vecLastPosition.z = m_pProxy->m_vecAbsOrigin.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10245310
// Name: public: void CTriggerViewProxy::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTriggerViewProxy::InputDisable(CTriggerViewProxy *this, inputdata_t *inputdata)
{
  CTriggerViewProxy::Disable(this);
}

//------------------------------------------------------------------------------
// Address: 0x10245320
// Name: public: void CTriggerViewProxy::TranslateViewToProxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerViewProxy::TranslateViewToProxy(CTriggerViewProxy *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pProxy; // esi
  bool v4; // zf
  CBaseEntity *Parent; // eax
  CBaseAnimating *v6; // esi
  Vector vOrigin; // [esp+10h] [ebp-18h] BYREF
  QAngle qProxyAngles; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    m_pProxy = this->m_pProxy;
    if ( m_pProxy != nullptr )
    {
      if ( (m_pProxy->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: this->m_pProxy, a2: (int)&savedregs);
      v4 = this->m_nParentAttachment == -1;
      qProxyAngles = m_pProxy->m_angAbsRotation;
      if ( !v4 )
      {
        Parent = CBaseEntity::GetParent(this: this->m_pProxy);
        v6 = (CBaseAnimating *)Parent;
        if ( Parent != nullptr )
        {
          Parent->__vftable[1].GetRefEHandle(this: Parent);
          v6->InvalidateBoneCache(this: v6);
          CBaseAnimating::GetAttachment(
            this: v6,
            iAttachment: this->m_nParentAttachment,
            absOrigin: &vOrigin,
            absAngles: &qProxyAngles);
        }
      }
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
      CTriggerViewProxy::Move(this, a2: COERCE_FLOAT(&savedregs));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10245740
// Name: public: virtual void CTriggerProximity::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerProximity::StartTouch(CTriggerProximity *this, CBaseEntity *pOther)
{
  CBaseTrigger::StartTouch(this, pOther);
  if ( this->PassesTriggerFilters(this, a2: pOther) )
  {
    ++this->m_nTouchers;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CTriggerProximity::MeasureThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10245BD0
// Name: public: virtual void CTriggerImpact::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerImpact::Spawn(CTriggerImpact *this)
{
  float m_flNoise; // xmm0_4
  float m_flViewkick; // xmm0_4
  CNetworkVarBase<bool,CBaseTrigger::NetworkVar_m_bDisabled> *p_m_bDisabled; // esi
  float m_flWait; // xmm0_4

  m_flNoise = this->m_flNoise;
  if ( m_flNoise >= 0.0 )
  {
    if ( m_flNoise > 1.0 )
      m_flNoise = 1.0;
  }
  else
  {
    m_flNoise = 0.0;
  }
  this->m_flNoise = m_flNoise;
  m_flViewkick = this->m_flViewkick;
  if ( m_flViewkick >= 0.0 )
  {
    if ( m_flViewkick > 1.0 )
      m_flViewkick = 1.0;
  }
  else
  {
    m_flViewkick = 0.0;
  }
  p_m_bDisabled = &this->m_bDisabled;
  this->m_flViewkick = m_flViewkick;
  if ( !this->m_bDisabled.m_Value )
  {
    this->NetworkStateChanged_m_bDisabled(this, a2: &this->m_bDisabled);
    p_m_bDisabled->m_Value = true;
  }
  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
  m_flWait = this->m_flWait;
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CTriggerMultiple::MultiTouch;
  if ( m_flWait == 0.0 )
    this->m_flWait = 0.2;
}

//------------------------------------------------------------------------------
// Address: 0x10245D00
// Name: public: virtual void CTriggerPlayerMovement::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerPlayerMovement::Spawn(CTriggerPlayerMovement *this)
{
  unsigned int v2; // edi
  edict_t *m_pPev; // ecx
  int v4; // edi
  edict_t *v5; // ecx
  int m_Value; // esi
  edict_t *v7; // ecx

  if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
  {
    DevMsg(
      a1: "*** trigger_playermovement using obsolete spawnflag. Remove and reset with new value for \"Disable auto player movement\"\n");
    v2 = this->m_spawnflags.m_Value & 0xFFFFFFEF;
    if ( this->m_spawnflags.m_Value != v2 )
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
      this->m_spawnflags.m_Value = v2;
    }
    v4 = this->m_spawnflags.m_Value | 0x80;
    if ( this->m_spawnflags.m_Value != v4 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v4;
    }
  }
  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x800) != 0 || (m_Value & 0x1000) != 0 )
  {
    if ( !this->m_bClientSidePredicted.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bClientSidePredicted.m_Value = true;
        CBaseEntity::SetTransmitState(this, nFlag: 32);
        return;
      }
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x47Cu);
      this->m_bClientSidePredicted.m_Value = true;
    }
    CBaseEntity::SetTransmitState(this, nFlag: 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10246540
// Name: public: virtual void CTriggerCDAudio::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCDAudio::Spawn(CTriggerAutoCrouch *this)
{
  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
}

//------------------------------------------------------------------------------
// Address: 0x10246550
// Name: public: virtual void CServerRagdollTrigger::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRagdollTrigger::StartTouch(CServerRagdollTrigger *this, CBaseEntity *pOther)
{
  CBaseCombatCharacter *v2; // eax

  CBaseTrigger::StartTouch(this, pOther);
  if ( !pOther->IsPlayer(this: pOther) )
  {
    v2 = pOther->MyCombatCharacterPointer(this: pOther);
    if ( v2 != nullptr )
      v2->m_bForceServerRagdoll = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10246600
// Name: public: virtual void CTriggerAutoCrouch::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerAutoCrouch::StartTouch(CTriggerAutoCrouch *this, unsigned int pOther)
{
  CBaseEntity *v2; // esi

  v2 = (CBaseEntity *)pOther;
  CBaseTrigger::StartTouch(this, (CBaseEntity *)pOther);
  if ( v2 != nullptr )
    pOther = v2->GetRefEHandle(this: v2)->m_Index;
  else
    pOther = -1;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: &this->m_hTouchingEntities,
         src: (CHandle<CBaseEntity> *)&pOther) != -1
    && v2 != nullptr )
  {
    v2->IsPlayer(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10246680
// Name: public: virtual bool CTriggerAutoCrouch::PassesTriggerFilters(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTriggerAutoCrouch::PassesTriggerFilters(CTriggerAutoCrouch *this, CBaseEntity *pOther)
{
  return pOther != nullptr && pOther->IsPlayer(this: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x102466B0
// Name: public: CTriggerHurt::CTriggerHurt(void)
// Source: json
//------------------------------------------------------------------------------
CTriggerHurt *__thiscall CTriggerHurt::CTriggerHurt(CTriggerHurt *this)
{
  CBaseTrigger::CBaseTrigger(this);
  this->__vftable = (CTriggerHurt_vtbl *)&CTriggerHurt::`vftable';
  this->m_OnHurt.m_Value.iVal = 0;
  this->m_OnHurt.m_Value.eVal.m_Index = -1;
  this->m_OnHurt.m_Value.fieldType = FIELD_VOID;
  this->m_OnHurtPlayer.m_Value.iVal = 0;
  this->m_OnHurtPlayer.m_Value.eVal.m_Index = -1;
  this->m_OnHurtPlayer.m_Value.fieldType = FIELD_VOID;
  this->m_hurtEntities.m_Memory.m_pMemory = nullptr;
  this->m_hurtEntities.m_Memory.m_nAllocationCount = 0;
  this->m_hurtEntities.m_Memory.m_nGrowSize = 0;
  this->m_hurtEntities.m_Size = 0;
  this->m_hurtEntities.m_pElements = nullptr;
  this->m_flDamageCap = 20.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10246D20
// Name: public: void CTriggerHurt::NavThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerHurt::NavThink(CTriggerHurt *this)
{
  bool v2; // zf
  float v3; // xmm1_4
  int m_Size; // edx
  int v5; // eax
  CNavArea **m_pMemory; // esi
  CNavArea *v7; // ecx
  NavAreaCollector overlap; // [esp+10h] [ebp-30h] BYREF
  Extent extent; // [esp+28h] [ebp-18h] BYREF

  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CTriggerHurt::NavThink,
    thinkTime: gpGlobals->curtime + 5.0,
    szContext: "NavContext");
  if ( TheNavMesh->m_isLoaded && !this->m_bDisabled.m_Value )
  {
    memset(&overlap.m_area, 0, sizeof(overlap.m_area));
    overlap.m_checkForDuplicates = false;
    CCollisionProperty::CollisionAABBToWorldAABB(
      this: &this->m_Collision,
      entityMins: &this->m_Collision.m_vecMins.m_Value,
      entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
      pWorldMins: &extent.lo,
      pWorldMaxs: &extent.hi);
    v2 = (this->m_bitsDamageInflict & 8) == 0;
    v3 = extent.lo.z - 71.0;
    extent.lo.z = extent.lo.z - 71.0;
    if ( !v2 )
    {
      extent.lo.z = v3;
      extent.lo.x = extent.lo.x - 16.0;
      extent.hi.x = extent.hi.x + 16.0;
      extent.lo.y = extent.lo.y - 16.0;
      extent.hi.y = extent.hi.y + 16.0;
    }
    CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>(this: TheNavMesh, func: &overlap, &extent);
    m_Size = overlap.m_area.m_Size;
    v5 = 0;
    if ( overlap.m_area.m_Size > 0 )
    {
      m_pMemory = overlap.m_area.m_Memory.m_pMemory;
      do
      {
        v7 = m_pMemory[v5++];
        v7->m_damagingTickCount = gpGlobals->tickcount + (int)(float)((float)(6.0 / gpGlobals->interval_per_tick) + 0.5);
      }
      while ( v5 < m_Size );
    }
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&overlap.m_area);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10246E80
// Name: public: void CTriggerHurt::RadiationThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerHurt::RadiationThink(CTriggerHurt *this)
{
  CBasePlayer *ClientInPVS; // ebx
  const Vector *v3; // eax
  float dt; // xmm0_4
  Vector vecSurroundMins; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector vecSurroundMaxs; // [esp+28h] [ebp-10h] BYREF
  float flRange; // [esp+34h] [ebp-4h]

  this->m_Collision.WorldSpaceSurroundingBounds(this: &this->m_Collision, a2: &vecSurroundMins, a3: &vecSurroundMaxs);
  ClientInPVS = (CBasePlayer *)UTIL_FindClientInPVS(vecBoxMins: &vecSurroundMins, vecBoxMaxs: &vecSurroundMaxs);
  if ( ClientInPVS != nullptr )
  {
    v3 = ClientInPVS->WorldSpaceCenter(this: ClientInPVS);
    flRange = CCollisionProperty::CalcDistanceFromPoint(this: &this->m_Collision, vecWorldPt: v3) * 3.0;
    CBasePlayer::NotifyNearbyRadiationSource(this: ClientInPVS, flRange);
  }
  dt = gpGlobals->curtime - this->m_flLastDmgTime;
  if ( dt >= 0.5 )
    CTriggerHurt::HurtAllTouchers(this, dt);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.25, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10246F40
// Name: public: void CTriggerHurt::HurtThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerHurt::HurtThink(CTriggerHurt *this)
{
  if ( CTriggerHurt::HurtAllTouchers(this, dt: 0.5) > 0 )
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
  else
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10246F90
// Name: public: virtual void CTriggerHurt::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerHurt::Touch(CTriggerHurt *this, CBaseEntity *pOther)
{
  if ( this->m_pfnThink == nullptr )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CTriggerHurt::HurtThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10246FD0
// Name: private: bool CChangeLevel::IsEntityInTransition(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChangeLevel::IsEntityInTransition(CChangeLevel *this, CBaseEntity *pEntity)
{
  char *m_szLandmarkName; // esi
  CBaseEntity *Landmark; // esi
  int v5; // eax
  _BYTE v6[8192]; // [esp+8h] [ebp-2018h] BYREF
  _BYTE v7[12]; // [esp+2008h] [ebp-18h] BYREF
  _BYTE v8[12]; // [esp+2014h] [ebp-Ch] BYREF
  int savedregs; // [esp+2020h] [ebp+0h] BYREF

  m_szLandmarkName = this->m_szLandmarkName;
  if ( CChangeLevel::InTransitionVolume(pEntity, pVolumeName: this->m_szLandmarkName) == 0 )
    return false;
  Landmark = CChangeLevel::FindLandmark(pLandmarkName: m_szLandmarkName);
  if ( Landmark == nullptr )
    return false;
  if ( (Landmark->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: Landmark, a2: (int)&savedregs);
  v5 = engine->GetClusterForOrigin(this: engine, a2: &Landmark->m_vecAbsOrigin);
  engine->GetPVSForCluster(this: engine, a2: v5, a3: 0x2000, a4: v6);
  pEntity->m_Collision.WorldSpaceSurroundingBounds(this: &pEntity->m_Collision, a2: (Vector *)v8, a3: (Vector *)v7);
  return engine->CheckBoxInPVS(this: engine, a2: (const Vector *)v8, a3: (const Vector *)v7, a4: v6, a5: 0x2000);
}

//------------------------------------------------------------------------------
// Address: 0x10247090
// Name: private: void CChangeLevel::NotifyEntitiesOutOfTransition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeLevel::NotifyEntitiesOutOfTransition(CChangeLevel *this)
{
  CBaseEntity *i; // esi

  for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
        i != nullptr;
        i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
  {
    if ( (i->ObjectCaps(this: i) & 0x200) != 0 )
    {
      if ( (i->ObjectCaps(this: i) & 0x180) != 0 && CChangeLevel::IsEntityInTransition(this, pEntity: i) )
        ((void (__thiscall *)(CBaseEntity *, const char *, CChangeLevel *, CChangeLevel *, _DWORD))i->AcceptInput)(
          a1: i,
          a2: "InsideTransition",
          a3: this,
          a4: this,
          a5: 0);
      else
        ((void (__thiscall *)(CBaseEntity *, const char *, CChangeLevel *, CChangeLevel *, _DWORD))i->AcceptInput)(
          a1: i,
          a2: "OutsideTransition",
          a3: this,
          a4: this,
          a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10247150
// Name: int BuildChangeList(struct levellist_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BuildChangeList(levellist_t *pLevelList, int maxList)
{
  return CChangeLevel::ChangeList(pLevelList, maxList);
}

//------------------------------------------------------------------------------
// Address: 0x10247160
// Name: public: void CTriggerCamera::InputSetTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::InputSetTarget(CTriggerCamera *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int m_Index; // eax

  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    if ( pszValue == nullptr )
    {
LABEL_7:
      pszValue = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
  }
  if ( pszValue == nullptr || *pszValue == 0 )
    goto LABEL_7;
LABEL_8:
  this->m_target.pszValue = pszValue;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    v4 = inputdata->value.iszVal.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
  }
  else
  {
    v4 = variant_t::ToString(this: &inputdata->value);
  }
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: v4,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hTarget.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hTarget.m_Index = -1;
  this->m_iAttachmentIndex = 0;
  m_Index = this->m_hTarget.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CTriggerCamera::FollowTarget,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10247260
// Name: public: void CTriggerCamera::Enable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::Enable(CTriggerCamera *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax
  CBasePlayer *LocalPlayer; // eax
  unsigned int v11; // ecx
  int v12; // eax
  CEntInfo *v13; // edx
  unsigned int v14; // ecx
  int v15; // eax
  CEntInfo *v16; // eax
  IHandleEntity *v17; // eax
  unsigned int v18; // eax
  CBasePlayer *v19; // ebx
  unsigned int v20; // eax
  IHandleEntity *v21; // ecx
  CTriggerCamera *v22; // eax
  const char *DebugName; // eax
  unsigned int v24; // eax
  IHandleEntity *v25; // ecx
  unsigned int v26; // eax
  IHandleEntity *v27; // ecx
  _BYTE *v28; // edi
  unsigned int v29; // eax
  IHandleEntity *v30; // ecx
  int m_Value; // eax
  float m_initialSpeed; // xmm0_4
  CBaseEntity *FOVOwner; // eax
  CBaseEntity *v34; // eax
  CBaseEntity *NextTarget; // eax
  unsigned int v36; // eax
  CBasePlayer *v37; // ecx
  const char *pszValue; // edx
  unsigned int v39; // eax
  CBaseEntity *v40; // ecx
  CBaseEntity *m_pPath; // ecx
  float m_flSpeed; // xmm0_4
  unsigned int v43; // eax
  IHandleEntity *v44; // ecx
  const Vector *v45; // eax
  unsigned int v46; // eax
  IHandleEntity *v47; // edi
  IHandleEntity *v48; // ecx
  float v49; // xmm0_4
  const CBaseHandle *(__thiscall *GetRefEHandle)(IHandleEntity *); // eax
  unsigned int v51; // eax
  CBaseEntity *v52; // edi
  CBaseCombatWeapon *ActiveWeapon; // eax
  unsigned int v54; // eax
  QAngle angles; // [esp+18h] [ebp-10h] BYREF
  float v56; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  this->m_state = 1;
  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index == -1
    || (v3 = (unsigned __int16)m_Index,
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v5 = HIWORD(m_Index),
        v4->m_SerialNumber != v5)
    || v4->m_pEntity == nullptr
    || ((v6 = v3, v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5,
                  v8 = &g_pEntityList->m_EntPtrArray[v6],
                  !v7)
      ? (m_pEntity = nullptr)
      : (m_pEntity = v8->m_pEntity),
        ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: m_pEntity) == 0) )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer != nullptr )
      this->m_hPlayer.m_Index = LocalPlayer->GetRefEHandle(this: LocalPlayer)->m_Index;
    else
      this->m_hPlayer.m_Index = -1;
  }
  v11 = this->m_hPlayer.m_Index;
  if ( v11 == -1
    || (v12 = (unsigned __int16)v11,
        v13 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v11],
        v14 = HIWORD(v11),
        v13->m_SerialNumber != v14)
    || v13->m_pEntity == nullptr )
  {
    CBaseEntity::DispatchUpdateTransmitState(this);
    return;
  }
  v15 = v12;
  v7 = g_pEntityList->m_EntPtrArray[v15].m_SerialNumber == v14;
  v16 = &g_pEntityList->m_EntPtrArray[v15];
  if ( v7 )
    v17 = v16->m_pEntity;
  else
    v17 = nullptr;
  if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v17->__vftable[28].dtr_IHandleEntity)(a1: v17) != 0 )
  {
    v18 = this->m_hPlayer.m_Index;
    if ( v18 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
      v19 = nullptr;
    else
      v19 = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
    v20 = v19->m_hViewEntity.m_Value.m_Index;
    if ( v20 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber == HIWORD(v20) )
    {
      v21 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
      if ( v21 != nullptr && v21 != v19 )
      {
        v22 = (CTriggerCamera *)__RTDynamicCast(
                                  inptr: v21,
                                  VfDelta: 0,
                                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                                  TargetType: &CTriggerCamera `RTTI Type Descriptor',
                                  isReference: 0);
        if ( v22 != nullptr )
        {
          if ( v22 == this )
          {
            DebugName = CBaseEntity::GetDebugName(this);
            _Warning(a1: "Viewcontrol %s was enabled twice in a row!\n", DebugName);
            return;
          }
          CTriggerCamera::Disable(this: v22);
        }
      }
    }
    this->m_nPlayerButtons = v19->m_nButtons;
    v24 = this->m_hPlayer.m_Index;
    if ( v24 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber != HIWORD(v24) )
      v25 = nullptr;
    else
      v25 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_pEntity;
    this->m_nOldTakeDamage = SBYTE2(v25[138].__vftable);
    v26 = this->m_hPlayer.m_Index;
    if ( v26 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_SerialNumber != HIWORD(v26) )
      v27 = nullptr;
    else
      v27 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_pEntity;
    v28 = (char *)&v27[138].__vftable + 2;
    if ( BYTE2(v27[138].__vftable) != 0 )
    {
      ((void (__thiscall *)(IHandleEntity *, int))v27->__vftable[63].dtr_IHandleEntity)(
        a1: v27,
        a2: (int)&v27[138].__vftable + 2);
      *v28 = 0;
    }
    if ( (this->m_spawnflags.m_Value & 0x20) != 0 )
    {
      v29 = this->m_hPlayer.m_Index;
      if ( v29 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_SerialNumber != HIWORD(v29) )
        v30 = nullptr;
      else
        v30 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_pEntity;
      CCollisionProperty::SetSolidFlags(this: (CCollisionProperty *)&v30[57], flags: LOWORD(v30[65].__vftable) | 4);
    }
    m_Value = this->m_spawnflags.m_Value;
    this->m_flReturnTime = this->m_flWait + gpGlobals->curtime;
    m_initialSpeed = this->m_initialSpeed;
    this->m_flSpeed = m_initialSpeed;
    this->m_targetSpeed = m_initialSpeed;
    if ( (m_Value & 0x10) != 0 )
      this->m_bSnapToGoal = true;
    if ( (m_Value & 0x80) != 0 )
    {
      if ( CBasePlayer::GetFOVOwner(this: v19) != nullptr )
      {
        FOVOwner = CBasePlayer::GetFOVOwner(this: v19);
        if ( FClassnameIs(pEntity: FOVOwner, szClassname: "point_viewcontrol_multiplayer")
          || (v34 = CBasePlayer::GetFOVOwner(this: v19), FClassnameIs(pEntity: v34, szClassname: "point_viewcontrol")) )
        {
          CBasePlayer::ClearZoomOwner(this: v19);
        }
      }
      CBasePlayer::SetFOV(this: v19, pRequester: this, FOV: (int)this->m_fov, zoomRate: this->m_fovSpeed, iZoomStart: 0);
    }
    if ( (this->m_spawnflags.m_Value & 2) != 0 )
    {
      this->m_hTarget.m_Index = this->m_hPlayer.m_Index;
    }
    else
    {
      NextTarget = CBaseEntity::GetNextTarget(this);
      if ( NextTarget != nullptr )
        this->m_hTarget.m_Index = NextTarget->GetRefEHandle(this: NextTarget)->m_Index;
      else
        this->m_hTarget.m_Index = -1;
    }
    CTriggerCamera::FindAttachment(this);
    if ( (this->m_spawnflags.m_Value & 4) != 0 )
    {
      v36 = this->m_hPlayer.m_Index;
      if ( v36 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v36].m_SerialNumber != HIWORD(v36) )
        v37 = nullptr;
      else
        v37 = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v36].m_pEntity;
      CBasePlayer::EnableControl(this: v37, fControl: false);
    }
    pszValue = this->m_sPath.pszValue;
    if ( pszValue != nullptr )
    {
      v39 = this->m_hPlayer.m_Index;
      if ( v39 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v39].m_SerialNumber != HIWORD(v39) )
        v40 = nullptr;
      else
        v40 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v39].m_pEntity;
      this->m_pPath = CGlobalEntityList::FindEntityByName(
                        this: &gEntList,
                        pStartEntity: nullptr,
                        szName: pszValue,
                        pSearchingEntity: nullptr,
                        pActivator: v40,
                        pCaller: nullptr,
                        pFilter: nullptr);
    }
    else
    {
      this->m_pPath = nullptr;
    }
    m_pPath = this->m_pPath;
    this->m_flStopTime = gpGlobals->curtime;
    if ( m_pPath != nullptr )
    {
      m_flSpeed = m_pPath->m_flSpeed;
      if ( m_flSpeed != 0.0 )
        this->m_targetSpeed = m_flSpeed;
      this->m_flStopTime = ((double (__thiscall *)(CBaseEntity *))m_pPath->GetDelay)(a1: m_pPath) + this->m_flStopTime;
    }
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      v43 = this->m_hPlayer.m_Index;
      if ( v43 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v43].m_SerialNumber != HIWORD(v43) )
        v44 = nullptr;
      else
        v44 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v43].m_pEntity;
      v45 = (const Vector *)((int (__thiscall *)(IHandleEntity *, QAngle *))v44->__vftable[42].dtr_IHandleEntity)(
                              a1: v44,
                              a2: &angles);
      UTIL_SetOrigin(entity: this, vecOrigin: v45, bFireTriggers: false);
      v46 = this->m_hPlayer.m_Index;
      if ( v46 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_SerialNumber != HIWORD(v46) )
        v47 = nullptr;
      else
        v47 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_pEntity;
      if ( v46 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_SerialNumber != HIWORD(v46) )
        v48 = nullptr;
      else
        v48 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_pEntity;
      v49 = *(float *)&v48->__vftable[42].GetRefEHandle(this: v48)->m_Index;
      GetRefEHandle = v47->__vftable[42].GetRefEHandle;
      v56 = v49;
      LODWORD(angles.y) = GetRefEHandle(this: v47)[1].m_Index;
      angles.x = v56;
      angles.z = 0.0;
      CBaseEntity::SetLocalAngles(this, &angles);
      v51 = this->m_hPlayer.m_Index;
      if ( v51 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v51].m_SerialNumber != HIWORD(v51) )
        v52 = nullptr;
      else
        v52 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v51].m_pEntity;
      if ( (v52->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this: v52, a2: (int)&savedregs);
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &v52->m_vecAbsVelocity);
    }
    else
    {
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    }
    CBasePlayer::SetViewEntity(this: v19, pEntity: this, bShouldDrawPlayer: false);
    if ( CBaseCombatCharacter::GetActiveWeapon(this: v19) != nullptr )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v19);
      CBaseEntity::AddEffects(this: ActiveWeapon, nEffects: 32);
    }
    v54 = this->m_hTarget.m_Index;
    if ( v54 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v54].m_SerialNumber == HIWORD(v54)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v54].m_pEntity != nullptr )
    {
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CTriggerCamera::FollowTarget,
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
    this->m_moveDistance = 0.0;
    CTriggerCamera::Move(this);
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
  else
  {
    _Warning(a1: "CTriggerCamera could not find a player!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x102478C0
// Name: public: virtual void CTriggerCamera::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::Use(
        CTriggerCamera *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( CBaseEntity::ShouldToggle(this, useType, currentState: this->m_state) != 0 )
  {
    if ( this->m_state != 0 )
    {
      CTriggerCamera::Disable(this);
    }
    else
    {
      if ( pActivator != nullptr )
        this->m_hPlayer.m_Index = pActivator->GetRefEHandle(this: pActivator)->m_Index;
      else
        this->m_hPlayer.m_Index = -1;
      CTriggerCamera::Enable(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10247960
// Name: public: void CTriggerCameraMultiplayer::InputAddPlayer(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCameraMultiplayer::InputAddPlayer(CTriggerCameraMultiplayer *this, inputdata_t *inputdata)
{
  CBaseEntity *pActivator; // esi

  pActivator = inputdata->pActivator;
  if ( inputdata->pActivator != nullptr && pActivator->IsPlayer(this: inputdata->pActivator) )
    CTriggerCameraMultiplayer::AddPlayer(this, player: (unsigned int)pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x10247990
// Name: public: void CTriggerViewProxy::Enable(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTriggerViewProxy::Enable(CTriggerViewProxy *this@<ecx>, float a2@<ebp>)
{
  CBaseEntity *m_pProxy; // ecx
  bool v4; // zf
  unsigned int m_Index; // eax
  CBaseAnimating *Parent; // eax
  const char *pszValue; // edx
  unsigned int v8; // ecx
  int v9; // eax
  CEntInfo *v10; // edx
  unsigned int v11; // ecx
  int v12; // eax
  CEntInfo *v13; // eax
  IHandleEntity *m_pEntity; // eax
  CBasePlayer *LocalPlayer; // eax
  unsigned int v16; // ecx
  int v17; // eax
  CEntInfo *v18; // edx
  unsigned int v19; // ecx
  int v20; // eax
  CEntInfo *v21; // eax
  IHandleEntity *v22; // eax
  unsigned int v23; // eax
  CBasePlayer *v24; // ebx
  unsigned int v25; // eax
  IHandleEntity *v26; // ecx
  unsigned int v27; // eax
  IHandleEntity *v28; // ecx
  _BYTE *v29; // edi
  unsigned int v30; // eax
  IHandleEntity *v31; // ecx
  unsigned int v32; // eax
  CBaseEntity *v33; // ecx
  CBaseCombatWeapon *ActiveWeapon; // eax
  unsigned int v35; // eax

  m_pProxy = this->m_pProxy;
  if ( m_pProxy != nullptr )
  {
    v4 = this->m_sProxyAttachment.pszValue == nullptr;
    this->m_nParentAttachment = -1;
    if ( !v4 )
    {
      m_Index = m_pProxy->m_pParent.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        Parent = (CBaseAnimating *)CBaseEntity::GetParent(this: m_pProxy);
        if ( Parent != nullptr )
        {
          pszValue = this->m_sProxyAttachment.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          this->m_nParentAttachment = CBaseAnimating::LookupAttachment(this: Parent, szName: pszValue);
        }
      }
    }
  }
  this->m_state = 1;
  v8 = this->m_hPlayer.m_Index;
  if ( v8 == -1
    || (v9 = (unsigned __int16)v8,
        v10 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v8],
        v11 = HIWORD(v8),
        v10->m_SerialNumber != v11)
    || v10->m_pEntity == nullptr
    || ((v12 = v9,
         v4 = g_pEntityList->m_EntPtrArray[v12].m_SerialNumber == v11,
         v13 = &g_pEntityList->m_EntPtrArray[v12],
         !v4)
      ? (m_pEntity = nullptr)
      : (m_pEntity = v13->m_pEntity),
        ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: m_pEntity) == 0) )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer != nullptr )
      this->m_hPlayer.m_Index = LocalPlayer->GetRefEHandle(this: LocalPlayer)->m_Index;
    else
      this->m_hPlayer.m_Index = -1;
  }
  v16 = this->m_hPlayer.m_Index;
  if ( v16 != -1
    && (v17 = (unsigned __int16)v16,
        v18 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v16],
        v19 = HIWORD(v16),
        v18->m_SerialNumber == v19)
    && v18->m_pEntity != nullptr )
  {
    v20 = v17;
    v4 = g_pEntityList->m_EntPtrArray[v20].m_SerialNumber == v19;
    v21 = &g_pEntityList->m_EntPtrArray[v20];
    if ( v4 )
      v22 = v21->m_pEntity;
    else
      v22 = nullptr;
    if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v22->__vftable[28].dtr_IHandleEntity)(a1: v22) != 0 )
    {
      v23 = this->m_hPlayer.m_Index;
      if ( v23 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != HIWORD(v23) )
        v24 = nullptr;
      else
        v24 = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
      this->m_nPlayerButtons = v24->m_nButtons;
      v24->m_bDuckEnabled = false;
      v25 = this->m_hPlayer.m_Index;
      if ( v25 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_SerialNumber != HIWORD(v25) )
        v26 = nullptr;
      else
        v26 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_pEntity;
      this->m_nOldTakeDamage = SBYTE2(v26[138].__vftable);
      v27 = this->m_hPlayer.m_Index;
      if ( v27 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_SerialNumber != HIWORD(v27) )
        v28 = nullptr;
      else
        v28 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_pEntity;
      v29 = (char *)&v28[138].__vftable + 2;
      if ( BYTE2(v28[138].__vftable) != 0 )
      {
        ((void (__thiscall *)(IHandleEntity *, int))v28->__vftable[63].dtr_IHandleEntity)(
          a1: v28,
          a2: (int)&v28[138].__vftable + 2);
        *v29 = 0;
      }
      if ( (this->m_spawnflags.m_Value & 0x20) != 0 )
      {
        v30 = this->m_hPlayer.m_Index;
        if ( v30 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v30].m_SerialNumber != HIWORD(v30) )
          v31 = nullptr;
        else
          v31 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v30].m_pEntity;
        CCollisionProperty::SetSolidFlags(this: (CCollisionProperty *)&v31[57], flags: LOWORD(v31[65].__vftable) | 4);
      }
      if ( (this->m_spawnflags.m_Value & 4) != 0 )
      {
        v32 = this->m_hPlayer.m_Index;
        if ( v32 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_SerialNumber != HIWORD(v32) )
          v33 = nullptr;
        else
          v33 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_pEntity;
        CBaseEntity::AddFlag(this: v33, flags: 128);
      }
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
      CBasePlayer::SetViewEntity(this: v24, pEntity: this, bShouldDrawPlayer: false);
      if ( CBaseCombatCharacter::GetActiveWeapon(this: v24) != nullptr )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v24);
        CBaseEntity::AddEffects(this: ActiveWeapon, nEffects: 32);
      }
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CTriggerViewProxy::TranslateViewToProxy,
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
      CTriggerViewProxy::Move(this, a2);
      CTriggerViewProxy::TranslateViewToProxy(this);
      v35 = this->m_hPlayer.m_Index;
      if ( v35 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v35].m_SerialNumber != HIWORD(v35) )
      {
        CBaseEntity::SetBaseVelocity(this: nullptr, v: &vec3_origin);
        CBaseEntity::DispatchUpdateTransmitState(this);
      }
      else
      {
        CBaseEntity::SetBaseVelocity(
          this: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v35].m_pEntity,
          v: &vec3_origin);
        CBaseEntity::DispatchUpdateTransmitState(this);
      }
    }
    else
    {
      _Warning(a1: "CTriggerViewProxy could not find a player!\n");
    }
  }
  else
  {
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102488E0
// Name: public: virtual void CTriggerHurt::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerHurt::Spawn(CTriggerHurt *this)
{
  float thinkTime; // [esp+8h] [ebp-Ch]

  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
  this->m_flOriginalDamage = this->m_flDamage;
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  if ( (this->m_bitsDamageInflict & 0x40000) != 0 )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CTriggerHurt::RadiationThink,
      thinkTime: 0.0,
      szContext: nullptr);
    thinkTime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                  a1: random,
                  a2: 0,
                  a3: 1056964608)
              + gpGlobals->curtime;
    CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  }
  if ( TheNavMesh != nullptr )
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CTriggerHurt::NavThink,
      thinkTime: gpGlobals->curtime,
      szContext: "NavContext");
}

//------------------------------------------------------------------------------
// Address: 0x102489C0
// Name: private: void CChangeLevel::ChangeLevelNow(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeLevel::ChangeLevelNow(CChangeLevel *this, CBaseEntity *pActivator)
{
  CBaseEntity *v3; // edi
  CBaseEntity *Landmark; // eax
  IVEngineServer_vtbl *v5; // edi
  const Vector *AbsOrigin; // eax
  int v7; // eax
  ConVar *m_pParent; // eax
  CSaveRestoreData *v9; // edi
  char *fDelay; // [esp+10h] [ebp-2030h]
  _BYTE v11[8192]; // [esp+20h] [ebp-2020h] BYREF
  _BYTE v12[12]; // [esp+2020h] [ebp-20h] BYREF
  _BYTE v13[12]; // [esp+202Ch] [ebp-14h] BYREF
  int v14; // [esp+2038h] [ebp-8h]
  CBaseEntity *pEntity; // [esp+203Ch] [ebp-4h]

  if ( !g_pGameRules->IsDeathmatch(this: g_pGameRules) && !this->m_bTouched )
  {
    v3 = pActivator;
    this->m_bTouched = true;
    if ( pActivator != nullptr && pActivator->IsPlayer(this: pActivator) )
      pEntity = pActivator;
    else
      pEntity = UTIL_GetLocalPlayer();
    v14 = CChangeLevel::InTransitionVolume(pEntity, pVolumeName: this->m_szLandmarkName);
    fDelay = this->m_szLandmarkName;
    if ( v14 == 0 )
    {
      _DevMsg(a1: 2, a2: "Player isn't in the transition volume %s, aborting\n", fDelay);
      return;
    }
    Landmark = CChangeLevel::FindLandmark(pLandmarkName: fDelay);
    if ( Landmark != nullptr )
    {
      if ( v14 == 1 )
      {
        v5 = engine->__vftable;
        AbsOrigin = CBaseEntity::GetAbsOrigin(this: Landmark);
        v7 = v5->GetClusterForOrigin(this: engine, a2: AbsOrigin);
        engine->GetPVSForCluster(this: engine, a2: v7, a3: 0x2000, a4: v11);
        if ( pEntity != nullptr )
        {
          pEntity->m_Collision.WorldSpaceSurroundingBounds(
            this: &pEntity->m_Collision,
            a2: (Vector *)v12,
            a3: (Vector *)v13);
          if ( !engine->CheckBoxInPVS(
                  this: engine,
                  a2: (const Vector *)v12,
                  a3: (const Vector *)v13,
                  a4: v11,
                  a5: 0x2000) )
          {
            _Warning(a1: "Player isn't in the landmark's (%s) PVS, aborting\n", this->m_szLandmarkName);
            return;
          }
        }
        v3 = pActivator;
      }
      CChangeLevel::WarnAboutActiveLead(this);
      g_iDebuggingTransition = 0;
      st_szNextSpot[0] = 0;
      V_strncpy(pDest: st_szNextSpot, pSrc: this->m_szLandmarkName, maxLen: 32);
      V_strncpy(pDest: st_szNextMap, pSrc: this->m_szMapName, maxLen: 32);
      CHandle<CBaseEntity>::operator=(this: &this->m_hActivator, val: v3);
      COutputEvent::FireOutput(this: &this->m_OnChangeLevel, pActivator: v3, pCaller: this, fDelay: 0.0);
      CChangeLevel::NotifyEntitiesOutOfTransition(this);
      m_pParent = g_debug_transitions.m_pParent;
      if ( g_debug_transitions.m_pParent == nullptr )
        goto LABEL_20;
      if ( g_debug_transitions.m_pParent->m_Value.m_nValue != 0 )
      {
        _Msg(a1: "CHANGE LEVEL: %s %s\n", st_szNextMap, st_szNextSpot);
        m_pParent = g_debug_transitions.m_pParent;
      }
      if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      {
        v9 = SaveInit(size: 0);
        if ( v9 != nullptr )
        {
          g_pGameSaveRestoreBlockSet->PreSave(this: g_pGameSaveRestoreBlockSet, a2: v9);
          v9->levelInfo.connectionCount = CChangeLevel::ChangeList(pLevelList: v9->levelInfo.levelList, maxList: 16);
          g_pGameSaveRestoreBlockSet->PostSave(this: g_pGameSaveRestoreBlockSet);
        }
        this->m_pfnTouch = nullptr;
      }
      else
      {
LABEL_20:
        g_pGameRules->OnBeginChangeLevel(this: g_pGameRules, a2: st_szNextMap, a3: nullptr);
        engine->ChangeLevel(this: engine, a2: st_szNextMap, a3: st_szNextSpot);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248C20
// Name: private: void CChangeLevel::TouchChangeLevel(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeLevel::TouchChangeLevel(CChangeLevel *this, CBaseEntity *pOther)
{
  __int64 v3; // xmm0_8
  float z; // ecx
  Vector vecVelocity; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( pOther != nullptr && pOther->IsPlayer(this: pOther) )
  {
    if ( BYTE2(pOther[4].m_fadeMaxDist.m_Value) == 1 )
    {
      if ( (pOther->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this: pOther, a2: (int)&savedregs);
      v3 = *(_QWORD *)&pOther->m_vecAbsVelocity.x;
      z = pOther->m_vecAbsVelocity.z;
      vecVelocity.x = *(float *)&v3 * 0.5;
      vecVelocity.z = z;
      vecVelocity.y = *((float *)&v3 + 1) * 0.5;
      CBaseEntity::SetAbsVelocity(this: pOther, vecAbsVelocity: &vecVelocity);
      CBaseEntity::AddFlag(this: pOther, flags: 64);
    }
    else if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *))pOther->__vftable[1].ModifyOrAppendCriteria)(a1: pOther) != 0
           || pOther->m_MoveType.m_Value != 8 )
    {
      CChangeLevel::ChangeLevelNow(this, pActivator: pOther);
    }
    else
    {
      DevMsg(a1: "In level transition: %s %s\n", st_szNextMap, st_szNextSpot);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248D10
// Name: public: void CTriggerCamera::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerCamera::InputEnable(CTriggerCamera *this, inputdata_t *inputdata)
{
  if ( inputdata->pActivator != nullptr )
    this->m_hPlayer.m_Index = inputdata->pActivator->GetRefEHandle(this: inputdata->pActivator)->m_Index;
  else
    this->m_hPlayer.m_Index = -1;
  CTriggerCamera::Enable(this);
}

//------------------------------------------------------------------------------
// Address: 0x10248DD0
// Name: public: void CTriggerViewProxy::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerViewProxy::InputEnable(CTriggerViewProxy *this, inputdata_t *inputdata)
{
  CBasePlayer *LocalPlayer; // eax
  CBaseEntity *m_pProxy; // ebx
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *m_pEntity; // edi
  float *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  _BYTE v16[12]; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  LocalPlayer = UTIL_GetLocalPlayer();
  if ( LocalPlayer != nullptr )
    this->m_hPlayer.m_Index = LocalPlayer->GetRefEHandle(this: LocalPlayer)->m_Index;
  else
    this->m_hPlayer.m_Index = -1;
  m_pProxy = this->m_pProxy;
  this->m_flStartTime = gpGlobals->curtime;
  if ( m_pProxy != nullptr )
  {
    m_Index = this->m_hPlayer.m_Index;
    if ( m_Index != -1 )
    {
      v6 = (unsigned __int16)m_Index;
      v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v8 = HIWORD(m_Index);
      if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr && this->m_nOffsetType != 2 )
      {
        v9 = v6;
        v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
        v11 = &g_pEntityList->m_EntPtrArray[v9];
        if ( v10 )
          m_pEntity = v11->m_pEntity;
        else
          m_pEntity = nullptr;
        if ( (m_pProxy->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: m_pProxy, a2: (int)&savedregs);
        v13 = (float *)((int (__thiscall *)(IHandleEntity *, _BYTE *))m_pEntity->__vftable[42].dtr_IHandleEntity)(
                         a1: m_pEntity,
                         a2: v16);
        v14 = v13[1] - m_pProxy->m_vecAbsOrigin.y;
        v15 = v13[2] - m_pProxy->m_vecAbsOrigin.z;
        this->m_vecInitialOffset.x = *v13 - m_pProxy->m_vecAbsOrigin.x;
        this->m_vecInitialOffset.y = v14;
        this->m_vecInitialOffset.z = v15;
      }
    }
  }
  CTriggerViewProxy::Enable(this, a2: COERCE_FLOAT(&savedregs));
}

//------------------------------------------------------------------------------
// Address: 0x102493E0
// Name: public: virtual void CChangeLevel::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeLevel::Spawn(CChangeLevel *this)
{
  char *m_szMapName; // edi

  m_szMapName = this->m_szMapName;
  if ( this->m_szMapName == locale || _V_stricmp(s1: this->m_szMapName, s2: locale) == 0 )
    _Msg(a1: "a trigger_changelevel doesn't have a map");
  if ( this->m_szLandmarkName == locale || _V_stricmp(s1: this->m_szLandmarkName, s2: locale) == 0 )
    _Msg(a1: "trigger_changelevel to %s doesn't have a landmark", m_szMapName);
  CBaseTrigger::InitTrigger(this);
  if ( (this->m_spawnflags.m_Value & 2) == 0 )
    this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CChangeLevel::TouchChangeLevel;
}

//------------------------------------------------------------------------------
// Address: 0x10249460
// Name: private: void CChangeLevel::InputChangeLevel(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeLevel::InputChangeLevel(CChangeLevel *this, inputdata_t *inputdata)
{
  CBasePlayer *LocalPlayer; // eax
  CBasePlayer *v4; // esi

  if ( gpGlobals->maxClients != 1
    || (LocalPlayer = UTIL_GetLocalPlayer(), v4 = LocalPlayer, LocalPlayer == nullptr)
    || LocalPlayer->IsAlive(this: LocalPlayer) && v4->m_iBonusChallenge.m_Value <= 0 )
  {
    CChangeLevel::ChangeLevelNow(this, pActivator: inputdata->pActivator);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249690
// Name: void InitCTriggerCameraScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCTriggerCameraScriptDesc()
{
  ScriptFunctionBinding_t *v0; // eax
  ScriptFunctionBinding_t *v1; // esi

  if ( !bInitialized_6 )
  {
    bInitialized_6 = true;
    g_CTriggerCamera_ScriptDesc.m_pszDescription = "Server-side camera entity";
    g_CTriggerCamera_ScriptDesc.m_pszScriptName = "CTriggerCamera";
    g_CTriggerCamera_ScriptDesc.m_pszClassname = "CTriggerCamera";
    g_CTriggerCamera_ScriptDesc.m_pBaseDesc = GetScriptDesc();
    g_CTriggerCamera_ScriptDesc.pHelper = GetScriptInstanceHelper_CBaseEntity();
    v0 = &g_CTriggerCamera_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                              this: &g_CTriggerCamera_ScriptDesc.m_FunctionBindings,
                                                                              elem: g_CTriggerCamera_ScriptDesc.m_FunctionBindings.m_Size)];
    v0->m_desc.m_pszDescription = "get camera's current fov setting as integer";
    v0->m_desc.m_pszScriptName = "GetFov";
    v0->m_desc.m_pszFunction = "ScriptGetFov";
    v0->m_desc.m_ReturnType = 5;
    v0->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CTriggerCamera *,int (__thiscall CTriggerCamera::*)(void),int>::Call;
    v0->m_pFunction = CTriggerCamera::ScriptGetFov;
    v0->m_flags = 1;
    v1 = &g_CTriggerCamera_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                              this: &g_CTriggerCamera_ScriptDesc.m_FunctionBindings,
                                                                              elem: g_CTriggerCamera_ScriptDesc.m_FunctionBindings.m_Size)];
    v1->m_desc.m_pszDescription = "set camera's current fov in integer degrees and fov change rate as float";
    v1->m_desc.m_pszScriptName = "SetFov";
    v1->m_desc.m_pszFunction = "ScriptSetFov";
    ScriptDeduceFunctionSignature<CTriggerCamera *,CTriggerCamera,void,int,float>(pDesc: &v1->m_desc);
    v1->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CTriggerCamera *,void (__thiscall CTriggerCamera::*)(int,float),void,int,float>::Call;
    v1->m_pFunction = CTriggerCamera::ScriptSetFov;
    v1->m_flags = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402B80
// Name: _dynamic_initializer_for__trigger_tonemap__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_tonemap__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTonemapTrigger> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_tonemap,
           a3: "trigger_tonemap");
}

//------------------------------------------------------------------------------
// Address: 0x104036B0
// Name: _dynamic_initializer_for__trigger_fog__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_fog__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFogTrigger> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_fog,
           a3: "trigger_fog");
}

//------------------------------------------------------------------------------
// Address: 0x10405E80
// Name: _dynamic_initializer_for__trigger_brush__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_brush__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerBrush> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_brush,
           a3: "trigger_brush");
}

//------------------------------------------------------------------------------
// Address: 0x1040A390
// Name: _dynamic_initializer_for__trigger_soundscape__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_soundscape__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerSoundscape> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_soundscape,
           a3: "trigger_soundscape");
}

//------------------------------------------------------------------------------
// Address: 0x1040BA70
// Name: CBaseTrigger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseTrigger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseTrigger>(__formal: nullptr);
  CBaseTrigger_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BA80
// Name: _dynamic_initializer_for__trigger__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBaseTrigger> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger,
           a3: "trigger");
}

//------------------------------------------------------------------------------
// Address: 0x1040BAC0
// Name: DT_BaseTrigger::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTrigger::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseTrigger::g_SendTable);
  return atexit(func: DT_BaseTrigger::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040BAE0
// Name: DT_BaseTrigger::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTrigger::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseTrigger::ignored>();
  DT_BaseTrigger::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BAF0
// Name: CTriggerRemove_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerRemove_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerRemove>(__formal: nullptr);
  CTriggerRemove_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BB00
// Name: _dynamic_initializer_for__trigger_remove__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_remove__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerRemove> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_remove,
           a3: "trigger_remove");
}

//------------------------------------------------------------------------------
// Address: 0x1040BB20
// Name: CTriggerHurt_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerHurt_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerHurt>();
  CTriggerHurt_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BB30
// Name: _dynamic_initializer_for__trigger_hurt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_hurt__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerHurt> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_hurt,
           a3: "trigger_hurt");
}

//------------------------------------------------------------------------------
// Address: 0x1040BB50
// Name: _dynamic_initializer_for__trigger_multiple__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_multiple__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerMultiple> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_multiple,
           a3: "trigger_multiple");
}

//------------------------------------------------------------------------------
// Address: 0x1040BB70
// Name: CTriggerMultiple_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerMultiple_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerMultiple>(__formal: nullptr);
  CTriggerMultiple_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BB80
// Name: _dynamic_initializer_for__trigger_once__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_once__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerOnce> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_once,
           a3: "trigger_once");
}

//------------------------------------------------------------------------------
// Address: 0x1040BBA0
// Name: _dynamic_initializer_for__trigger_look__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_look__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerLook> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_look,
           a3: "trigger_look");
}

//------------------------------------------------------------------------------
// Address: 0x1040BBC0
// Name: CTriggerLook_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerLook_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerLook>(__formal: nullptr);
  CTriggerLook_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BBD0
// Name: _dynamic_initializer_for__trigger_transition__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_transition__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerVolume> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_transition,
           a3: "trigger_transition");
}

//------------------------------------------------------------------------------
// Address: 0x1040BBF0
// Name: _dynamic_initializer_for__trigger_changelevel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_changelevel__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CChangeLevel> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_changelevel,
           a3: "trigger_changelevel");
}

//------------------------------------------------------------------------------
// Address: 0x1040BC10
// Name: CChangeLevel_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CChangeLevel_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CChangeLevel>();
  CChangeLevel_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BC20
// Name: CTriggerPush_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerPush_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerPush>(__formal: nullptr);
  CTriggerPush_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BC30
// Name: _dynamic_initializer_for__trigger_push__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_push__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerPush> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_push,
           a3: "trigger_push");
}

//------------------------------------------------------------------------------
// Address: 0x1040BC50
// Name: _dynamic_initializer_for__trigger_teleport__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_teleport__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerTeleport> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_teleport,
           a3: "trigger_teleport");
}

//------------------------------------------------------------------------------
// Address: 0x1040BC70
// Name: CTriggerTeleport_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerTeleport_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerTeleport>(__formal: nullptr);
  CTriggerTeleport_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BCA0
// Name: CTriggerToggleSave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerToggleSave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerToggleSave>(__formal: nullptr);
  CTriggerToggleSave_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BCB0
// Name: _dynamic_initializer_for__trigger_togglesave__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_togglesave__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerToggleSave> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_togglesave,
           a3: "trigger_togglesave");
}

//------------------------------------------------------------------------------
// Address: 0x1040BCD0
// Name: CTriggerSave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerSave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerSave>(__formal: nullptr);
  CTriggerSave_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BCE0
// Name: _dynamic_initializer_for__trigger_autosave__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_autosave__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerSave> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_autosave,
           a3: "trigger_autosave");
}

//------------------------------------------------------------------------------
// Address: 0x1040BD00
// Name: _dynamic_initializer_for__trigger_gravity__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_gravity__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerGravity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_gravity,
           a3: "trigger_gravity");
}

//------------------------------------------------------------------------------
// Address: 0x1040BD20
// Name: CTriggerGravity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerGravity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerGravity>(__formal: nullptr);
  CTriggerGravity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BD50
// Name: CAI_ChangeTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_ChangeTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_ChangeTarget>(__formal: nullptr);
  CAI_ChangeTarget_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BD80
// Name: CAI_ChangeHintGroup_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_ChangeHintGroup_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_ChangeHintGroup>(__formal: nullptr);
  CAI_ChangeHintGroup_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BDB0
// Name: CTriggerCamera_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerCamera_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerCamera>(__formal: nullptr);
  CTriggerCamera_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BE10
// Name: CTriggerCameraMultiplayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerCameraMultiplayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerCameraMultiplayer>(__formal: nullptr);
  CTriggerCameraMultiplayer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BE40
// Name: CTriggerViewProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerViewProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerViewProxy>(__formal: nullptr);
  CTriggerViewProxy_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BE50
// Name: _dynamic_initializer_for__trigger_cdaudio__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_cdaudio__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerCDAudio> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_cdaudio,
           a3: "trigger_cdaudio");
}

//------------------------------------------------------------------------------
// Address: 0x1040BE70
// Name: CTriggerProximity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerProximity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerProximity>(__formal: nullptr);
  CTriggerProximity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BE80
// Name: _dynamic_initializer_for__trigger_proximity__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_proximity__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerProximity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_proximity,
           a3: "trigger_proximity");
}

//------------------------------------------------------------------------------
// Address: 0x1040BEC0
// Name: CPhysicsWind_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysicsWind_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysicsWind>(__formal: nullptr);
  CPhysicsWind_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BED0
// Name: _dynamic_initializer_for__trigger_wind__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_wind__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerWind> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_wind,
           a3: "trigger_wind");
}

//------------------------------------------------------------------------------
// Address: 0x1040BEF0
// Name: CTriggerWind_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerWind_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerWind>(__formal: nullptr);
  CTriggerWind_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BF00
// Name: _dynamic_initializer_for__trigger_hierarchy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_hierarchy__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerHierarchy> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_hierarchy,
           a3: "trigger_hierarchy");
}

//------------------------------------------------------------------------------
// Address: 0x1040BF20
// Name: CTriggerHierarchy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerHierarchy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerHierarchy>(__formal: nullptr);
  CTriggerHierarchy_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BF30
// Name: _dynamic_initializer_for__trigger_impact__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_impact__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerImpact> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_impact,
           a3: "trigger_impact");
}

//------------------------------------------------------------------------------
// Address: 0x1040BF50
// Name: CTriggerImpact_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerImpact_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerImpact>(__formal: nullptr);
  CTriggerImpact_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BF80
// Name: DT_TriggerPlayerMovement::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TriggerPlayerMovement::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TriggerPlayerMovement::g_SendTable);
  return atexit(func: DT_TriggerPlayerMovement::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040BFA0
// Name: DT_TriggerPlayerMovement::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TriggerPlayerMovement::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TriggerPlayerMovement::ignored>();
  DT_TriggerPlayerMovement::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BFB0
// Name: CTriggerPlayerMovement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerPlayerMovement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerPlayerMovement>(__formal: nullptr);
  CTriggerPlayerMovement_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BFC0
// Name: _dynamic_initializer_for__trigger_playermovement__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_playermovement__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerPlayerMovement> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_playermovement,
           a3: "trigger_playermovement");
}

//------------------------------------------------------------------------------
// Address: 0x1040BFE0
// Name: CBaseVPhysicsTrigger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseVPhysicsTrigger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseVPhysicsTrigger>(__formal: nullptr);
  CBaseVPhysicsTrigger_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C010
// Name: DT_BaseVPhysicsTrigger::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseVPhysicsTrigger::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseVPhysicsTrigger::g_SendTable);
  return atexit(func: DT_BaseVPhysicsTrigger::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C030
// Name: DT_BaseVPhysicsTrigger::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseVPhysicsTrigger::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseVPhysicsTrigger::ignored>();
  DT_BaseVPhysicsTrigger::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C040
// Name: CTriggerVPhysicsMotion_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerVPhysicsMotion_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerVPhysicsMotion>(__formal: nullptr);
  CTriggerVPhysicsMotion_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C050
// Name: _dynamic_initializer_for__trigger_vphysics_motion__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_vphysics_motion__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerVPhysicsMotion> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_vphysics_motion,
           a3: "trigger_vphysics_motion");
}

//------------------------------------------------------------------------------
// Address: 0x1040C070
// Name: _dynamic_initializer_for__trigger_serverragdoll__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_serverragdoll__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CServerRagdollTrigger> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_serverragdoll,
           a3: "trigger_serverragdoll");
}

//------------------------------------------------------------------------------
// Address: 0x1040C090
// Name: CTriggerAutoCrouch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerAutoCrouch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerAutoCrouch>(__formal: nullptr);
  CTriggerAutoCrouch_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C0A0
// Name: _dynamic_initializer_for__trigger_auto_crouch__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trigger_auto_crouch__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerAutoCrouch> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &trigger_auto_crouch,
           a3: "trigger_auto_crouch");
}

//------------------------------------------------------------------------------
// Address: 0x1041EA00
// Name: DT_BaseTrigger::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseTrigger::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseTrigger::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041EA10
// Name: DT_TriggerPlayerMovement::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TriggerPlayerMovement::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TriggerPlayerMovement::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041EA40
// Name: DT_BaseVPhysicsTrigger::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseVPhysicsTrigger::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseVPhysicsTrigger::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x101D2A10
// Name: class CPointEntityFinder __near * _CreateEntityTemplate<class CPointEntityFinder>(class CPointEntityFinder __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPointEntityFinder *__cdecl _CreateEntityTemplate<CPointEntityFinder>(
        CPointEntityFinder *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x384u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CPointEntityFinder::`vftable';
    v3[213] = -1;
    v3[215] = -1;
    v3[217] = -1;
    v3[219] = 0;
    v3[222] = -1;
    v3[223] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPointEntityFinder *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023C5F0
// Name: __CreateCServerGameTagsIServerGameTags_interface_7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_7()
{
  return &_g_CServerGameTags_singleton_7;
}

//------------------------------------------------------------------------------
// Address: 0x102433E0
// Name: struct datamap_t __near * DataMapInit<class CTriggerRemove>(class CTriggerRemove __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerRemove>()
{
  if ( (_S4_63 & 1) == 0 )
  {
    _S4_63 |= 1u;
    nameHolder_426.m_pszBase = "CTriggerRemove";
    nameHolder_426.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_426.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_426.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_426.m_Names.m_Size = 0;
    nameHolder_426.m_Names.m_pElements = nullptr;
    nameHolder_426.m_nLenBase = 14;
    atexit(func: DataMapInit_CTriggerRemove__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerRemove::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S4_63 & 2) == 0 )
  {
    _S4_63 |= 2u;
    dataDesc_404[1].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_404[1].inputFunc = 0;
    *(_QWORD *)&dataDesc_404[1].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_404[1].override_count = 0;
    *(_QWORD *)dataDesc_404[1].flatOffset = 0;
    *(_DWORD *)&dataDesc_404[1].flatGroup = 0;
  }
  CTriggerRemove::m_DataMap.dataNumFields = 1;
  CTriggerRemove::m_DataMap.dataDesc = &dataDesc_404[1];
  return &CTriggerRemove::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102438C0
// Name: struct datamap_t __near * DataMapInit<class CTriggerMultiple>(class CTriggerMultiple __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerMultiple>()
{
  if ( (_S6_25 & 1) == 0 )
  {
    _S6_25 |= 1u;
    nameHolder_427.m_pszBase = "CTriggerMultiple";
    nameHolder_427.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_427.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_427.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_427.m_Names.m_Size = 0;
    nameHolder_427.m_Names.m_pElements = nullptr;
    nameHolder_427.m_nLenBase = 16;
    atexit(func: DataMapInit_CTriggerMultiple__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerMultiple::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S6_25 & 2) == 0 )
  {
    _S6_25 |= 2u;
    dataDesc_489[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_427,
                                  pszIdentifier: "MultiTouch");
    dataDesc_489[1].flags = 32;
    dataDesc_489[1].fieldOffset = 0;
    dataDesc_489[1].fieldSize = 1;
    dataDesc_489[1].externalName = nullptr;
    dataDesc_489[1].pSaveRestoreOps = nullptr;
    dataDesc_489[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerMultiple::MultiTouch;
    *(_QWORD *)&dataDesc_489[1].td = 0;
    *(_QWORD *)&dataDesc_489[1].override_field = 0;
    *(_QWORD *)&dataDesc_489[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_489[1].flatOffset[1] = 0;
    dataDesc_489[2].fieldType = FIELD_VOID;
    dataDesc_489[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_427,
                                  pszIdentifier: "MultiWaitOver");
    dataDesc_489[2].fieldSize = 1;
    *(_QWORD *)&dataDesc_489[2].td = 0;
    *(_QWORD *)&dataDesc_489[2].override_field = 0;
    *(_QWORD *)&dataDesc_489[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_489[2].flatOffset[1] = 0;
    dataDesc_489[2].fieldOffset = 0;
    dataDesc_489[2].flags = 32;
    dataDesc_489[2].externalName = nullptr;
    dataDesc_489[2].pSaveRestoreOps = nullptr;
    dataDesc_489[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerMultiple::MultiWaitOver;
    dataDesc_489[3].fieldType = FIELD_CUSTOM;
    dataDesc_489[3].fieldName = "m_OnTrigger";
    dataDesc_489[3].fieldOffset = 1152;
    *(_DWORD *)&dataDesc_489[3].fieldSize = 1441793;
    dataDesc_489[3].externalName = "OnTrigger";
    dataDesc_489[3].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_489[3].inputFunc = 0;
    *(_QWORD *)&dataDesc_489[3].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_489[3].override_count = 0;
    *(_QWORD *)dataDesc_489[3].flatOffset = 0;
    *(_DWORD *)&dataDesc_489[3].flatGroup = 0;
  }
  CTriggerMultiple::m_DataMap.dataNumFields = 3;
  CTriggerMultiple::m_DataMap.dataDesc = &dataDesc_489[1];
  return &CTriggerMultiple::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10243B30
// Name: struct datamap_t __near * DataMapInit<class CTriggerLook>(class CTriggerLook __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerLook>()
{
  if ( (_S7_17 & 1) == 0 )
  {
    _S7_17 |= 1u;
    nameHolder_428.m_pszBase = "CTriggerLook";
    nameHolder_428.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_428.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_428.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_428.m_Names.m_Size = 0;
    nameHolder_428.m_Names.m_pElements = nullptr;
    nameHolder_428.m_nLenBase = 12;
    atexit(func: DataMapInit_CTriggerLook__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerLook::m_DataMap.baseMap = &CTriggerMultiple::m_DataMap;
  if ( (_S7_17 & 2) == 0 )
  {
    _S7_17 |= 2u;
    dataDesc_405[7].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_405[7].inputFunc = 0;
    *(_QWORD *)&dataDesc_405[7].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_405[7].override_count = 0;
    *(_QWORD *)dataDesc_405[7].flatOffset = 0;
    *(_DWORD *)&dataDesc_405[7].flatGroup = 0;
    dataDesc_405[8].fieldType = FIELD_VOID;
    dataDesc_405[8].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_428,
                                  pszIdentifier: "TimeoutThink");
    *(_QWORD *)&dataDesc_405[8].td = 0;
    *(_QWORD *)&dataDesc_405[8].override_field = 0;
    *(_QWORD *)&dataDesc_405[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_405[8].flatOffset[1] = 0;
    dataDesc_405[8].fieldSize = 1;
    dataDesc_405[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_405[9].override_field = 0;
    *(_QWORD *)&dataDesc_405[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_405[9].flatOffset[1] = 0;
    dataDesc_405[8].fieldOffset = 0;
    dataDesc_405[8].flags = 32;
    dataDesc_405[8].externalName = nullptr;
    dataDesc_405[8].pSaveRestoreOps = nullptr;
    dataDesc_405[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerLook::TimeoutThink;
    dataDesc_405[9].fieldType = FIELD_FLOAT;
    dataDesc_405[9].fieldName = "m_flFieldOfView";
    dataDesc_405[9].fieldOffset = 1180;
    dataDesc_405[9].flags = 14;
    dataDesc_405[9].externalName = "FieldOfView";
    dataDesc_405[9].pSaveRestoreOps = nullptr;
    dataDesc_405[9].inputFunc = nullptr;
    dataDesc_405[9].td = nullptr;
    dataDesc_405[9].fieldSizeInBytes = 4;
    dataDesc_405[10].fieldType = FIELD_FLOAT;
    dataDesc_405[10].fieldName = "m_flLookTime";
    dataDesc_405[10].fieldOffset = 1184;
    *(_DWORD *)&dataDesc_405[10].fieldSize = 917505;
    dataDesc_405[10].externalName = "LookTime";
    dataDesc_405[10].pSaveRestoreOps = nullptr;
    dataDesc_405[10].inputFunc = nullptr;
    dataDesc_405[10].td = nullptr;
    dataDesc_405[10].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_405[10].override_field = 0;
    *(_QWORD *)&dataDesc_405[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_405[10].flatOffset[1] = 0;
  }
  CTriggerLook::m_DataMap.dataNumFields = 10;
  CTriggerLook::m_DataMap.dataDesc = &dataDesc_405[1];
  return &CTriggerLook::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102444B0
// Name: struct datamap_t __near * DataMapInit<class CTriggerPush>(class CTriggerPush __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerPush>()
{
  if ( (_S9_9 & 1) == 0 )
  {
    _S9_9 |= 1u;
    nameHolder_429.m_pszBase = "CTriggerPush";
    nameHolder_429.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_429.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_429.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_429.m_Names.m_Size = 0;
    nameHolder_429.m_Names.m_pElements = nullptr;
    nameHolder_429.m_nLenBase = 12;
    atexit(func: DataMapInit_CTriggerPush__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerPush::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  CTriggerPush::m_DataMap.dataNumFields = 3;
  CTriggerPush::m_DataMap.dataDesc = &dataDesc_406[1];
  return &CTriggerPush::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102445E0
// Name: struct datamap_t __near * DataMapInit<class CTriggerTeleport>(class CTriggerTeleport __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerTeleport>()
{
  if ( (_S10_6 & 1) == 0 )
  {
    _S10_6 |= 1u;
    nameHolder_430.m_pszBase = "CTriggerTeleport";
    nameHolder_430.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_430.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_430.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_430.m_Names.m_Size = 0;
    nameHolder_430.m_Names.m_pElements = nullptr;
    nameHolder_430.m_nLenBase = 16;
    atexit(func: DataMapInit_CTriggerTeleport__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerTeleport::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  CTriggerTeleport::m_DataMap.dataNumFields = 3;
  CTriggerTeleport::m_DataMap.dataDesc = &dataDesc_407[1];
  return &CTriggerTeleport::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10244660
// Name: struct datamap_t __near * DataMapInit<class CTriggerToggleSave>(class CTriggerToggleSave __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerToggleSave>()
{
  if ( (_S11_4 & 1) == 0 )
  {
    _S11_4 |= 1u;
    nameHolder_431.m_pszBase = "CTriggerToggleSave";
    nameHolder_431.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_431.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_431.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_431.m_Names.m_Size = 0;
    nameHolder_431.m_Names.m_pElements = nullptr;
    nameHolder_431.m_nLenBase = 18;
    atexit(func: DataMapInit_CTriggerToggleSave__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerToggleSave::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  CTriggerToggleSave::m_DataMap.dataNumFields = 3;
  CTriggerToggleSave::m_DataMap.dataDesc = &dataDesc_408[1];
  return &CTriggerToggleSave::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102446E0
// Name: struct datamap_t __near * DataMapInit<class CTriggerSave>(class CTriggerSave __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerSave>()
{
  if ( (_S12_3 & 1) == 0 )
  {
    _S12_3 |= 1u;
    nameHolder_432.m_pszBase = "CTriggerSave";
    nameHolder_432.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_432.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_432.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_432.m_Names.m_Size = 0;
    nameHolder_432.m_Names.m_pElements = nullptr;
    nameHolder_432.m_nLenBase = 12;
    atexit(func: DataMapInit_CTriggerSave__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerSave::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  CTriggerSave::m_DataMap.dataNumFields = 3;
  CTriggerSave::m_DataMap.dataDesc = &dataDesc_409[1];
  return &CTriggerSave::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10244760
// Name: struct datamap_t __near * DataMapInit<class CTriggerGravity>(class CTriggerGravity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerGravity>()
{
  if ( (_S13_2 & 1) == 0 )
  {
    _S13_2 |= 1u;
    nameHolder_433.m_pszBase = "CTriggerGravity";
    nameHolder_433.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_433.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_433.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_433.m_Names.m_Size = 0;
    nameHolder_433.m_Names.m_pElements = nullptr;
    nameHolder_433.m_nLenBase = 15;
    atexit(func: DataMapInit_CTriggerGravity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerGravity::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S13_2 & 2) == 0 )
  {
    _S13_2 |= 2u;
    dataDesc_490[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_433,
                                  pszIdentifier: "GravityTouch");
    dataDesc_490[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_490[1].fieldSize = 2097153;
    dataDesc_490[1].externalName = nullptr;
    dataDesc_490[1].pSaveRestoreOps = nullptr;
    dataDesc_490[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerGravity::GravityTouch;
    *(_QWORD *)&dataDesc_490[1].td = 0;
    *(_QWORD *)&dataDesc_490[1].override_field = 0;
    *(_QWORD *)&dataDesc_490[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_490[1].flatOffset[1] = 0;
  }
  CTriggerGravity::m_DataMap.dataNumFields = 1;
  CTriggerGravity::m_DataMap.dataDesc = &dataDesc_490[1];
  return &CTriggerGravity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10244870
// Name: struct datamap_t __near * DataMapInit<class CAI_ChangeTarget>(class CAI_ChangeTarget __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_ChangeTarget>()
{
  if ( (_S14_2 & 1) == 0 )
  {
    _S14_2 |= 1u;
    nameHolder_434.m_pszBase = "CAI_ChangeTarget";
    nameHolder_434.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_434.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_434.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_434.m_Names.m_Size = 0;
    nameHolder_434.m_Names.m_pElements = nullptr;
    nameHolder_434.m_nLenBase = 16;
    atexit(func: DataMapInit_CAI_ChangeTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_ChangeTarget::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CAI_ChangeTarget::m_DataMap.dataNumFields = 2;
  CAI_ChangeTarget::m_DataMap.dataDesc = &dataDesc_410[1];
  return &CAI_ChangeTarget::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102448F0
// Name: struct datamap_t __near * DataMapInit<class CAI_ChangeHintGroup>(class CAI_ChangeHintGroup __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_ChangeHintGroup>()
{
  if ( (_S15_1 & 1) == 0 )
  {
    _S15_1 |= 1u;
    nameHolder_435.m_pszBase = "CAI_ChangeHintGroup";
    nameHolder_435.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_435.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_435.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_435.m_Names.m_Size = 0;
    nameHolder_435.m_Names.m_pElements = nullptr;
    nameHolder_435.m_nLenBase = 19;
    atexit(func: DataMapInit_CAI_ChangeHintGroup__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_ChangeHintGroup::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CAI_ChangeHintGroup::m_DataMap.dataNumFields = 6;
  CAI_ChangeHintGroup::m_DataMap.dataDesc = &dataDesc_411[1];
  return &CAI_ChangeHintGroup::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10245420
// Name: struct datamap_t __near * DataMapInit<class CTriggerProximity>(class CTriggerProximity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerProximity>()
{
  char *Name; // eax

  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    nameHolder_436.m_pszBase = "CTriggerProximity";
    nameHolder_436.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_436.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_436.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_436.m_Names.m_Size = 0;
    nameHolder_436.m_Names.m_pElements = nullptr;
    nameHolder_436.m_nLenBase = 17;
    atexit(func: DataMapInit_CTriggerProximity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerProximity::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S19_1 & 2) == 0 )
  {
    _S19_1 |= 2u;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_436, pszIdentifier: "MeasureThink");
    *(_QWORD *)&dataDesc_491[1].td = 0;
    *(_QWORD *)&dataDesc_491[1].override_field = 0;
    *(_QWORD *)&dataDesc_491[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_491[1].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_491[2].flatOffset = 0;
    dataDesc_491[1].fieldName = Name;
    dataDesc_491[2].fieldTolerance = 0.0;
    dataDesc_491[3].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_491[3].flatOffset = 0;
    dataDesc_491[4].fieldTolerance = 0.0;
    dataDesc_491[5].fieldTolerance = 0.0;
    dataDesc_491[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_491[1].fieldSize = 2097153;
    dataDesc_491[1].externalName = nullptr;
    dataDesc_491[1].pSaveRestoreOps = nullptr;
    dataDesc_491[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerProximity::MeasureThink;
    dataDesc_491[2].fieldType = FIELD_STRING;
    dataDesc_491[2].fieldName = "m_iszMeasureTarget";
    dataDesc_491[2].fieldOffset = 1156;
    *(_DWORD *)&dataDesc_491[2].fieldSize = 393217;
    dataDesc_491[2].externalName = "measuretarget";
    dataDesc_491[2].pSaveRestoreOps = nullptr;
    dataDesc_491[2].inputFunc = nullptr;
    dataDesc_491[2].td = nullptr;
    dataDesc_491[2].fieldSizeInBytes = 4;
    dataDesc_491[2].override_field = nullptr;
    dataDesc_491[2].override_count = 0;
    *(_DWORD *)&dataDesc_491[2].flatGroup = 0;
    dataDesc_491[3].fieldType = FIELD_EHANDLE;
    dataDesc_491[3].fieldName = "m_hMeasureTarget";
    dataDesc_491[3].fieldOffset = 1152;
    dataDesc_491[3].fieldSize = 1;
    dataDesc_491[3].flags = 2;
    dataDesc_491[3].externalName = nullptr;
    dataDesc_491[3].pSaveRestoreOps = nullptr;
    dataDesc_491[3].inputFunc = nullptr;
    dataDesc_491[3].td = nullptr;
    dataDesc_491[3].fieldSizeInBytes = 4;
    dataDesc_491[3].override_field = nullptr;
    dataDesc_491[3].override_count = 0;
    *(_DWORD *)&dataDesc_491[3].flatGroup = 0;
    dataDesc_491[4].fieldType = FIELD_FLOAT;
    dataDesc_491[4].fieldName = "m_fRadius";
    dataDesc_491[4].fieldOffset = 1160;
    *(_DWORD *)&dataDesc_491[4].fieldSize = 393217;
    dataDesc_491[4].externalName = "radius";
    dataDesc_491[4].pSaveRestoreOps = nullptr;
    dataDesc_491[4].inputFunc = nullptr;
    dataDesc_491[4].td = nullptr;
    dataDesc_491[4].fieldSizeInBytes = 4;
    dataDesc_491[4].override_field = nullptr;
    dataDesc_491[4].override_count = 0;
    *(_QWORD *)dataDesc_491[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_491[4].flatGroup = 0;
    dataDesc_491[5].fieldType = FIELD_INTEGER;
    dataDesc_491[5].fieldName = "m_nTouchers";
    dataDesc_491[5].fieldOffset = 1164;
    *(_DWORD *)&dataDesc_491[5].fieldSize = 131073;
    dataDesc_491[5].externalName = nullptr;
    dataDesc_491[5].pSaveRestoreOps = nullptr;
    dataDesc_491[5].inputFunc = nullptr;
    dataDesc_491[5].td = nullptr;
    dataDesc_491[5].fieldSizeInBytes = 4;
    dataDesc_491[5].override_field = nullptr;
    dataDesc_491[5].override_count = 0;
    *(_QWORD *)dataDesc_491[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_491[5].flatGroup = 0;
    dataDesc_491[6].fieldType = FIELD_CUSTOM;
    dataDesc_491[6].fieldName = "m_NearestEntityDistance";
    dataDesc_491[6].fieldOffset = 1168;
    *(_DWORD *)&dataDesc_491[6].fieldSize = 1441793;
    dataDesc_491[6].externalName = "NearestEntityDistance";
    dataDesc_491[6].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_491[6].inputFunc = 0;
    *(_QWORD *)&dataDesc_491[6].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_491[6].override_count = 0;
    *(_QWORD *)dataDesc_491[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_491[6].flatGroup = 0;
  }
  CTriggerProximity::m_DataMap.dataNumFields = 6;
  CTriggerProximity::m_DataMap.dataDesc = &dataDesc_491[1];
  return &CTriggerProximity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102457A0
// Name: struct datamap_t __near * DataMapInit<class CPhysicsWind>(class CPhysicsWind __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysicsWind>()
{
  if ( (_S20_1 & 1) == 0 )
  {
    _S20_1 |= 1u;
    nameHolder_437.m_pszBase = "CPhysicsWind";
    nameHolder_437.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_437.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_437.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_437.m_Names.m_Size = 0;
    nameHolder_437.m_Names.m_pElements = nullptr;
    nameHolder_437.m_nLenBase = 12;
    atexit(func: DataMapInit_CPhysicsWind__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysicsWind::m_DataMap.baseMap = nullptr;
  CPhysicsWind::m_DataMap.dataNumFields = 2;
  CPhysicsWind::m_DataMap.dataDesc = &dataDesc_412[1];
  return &CPhysicsWind::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10245820
// Name: struct datamap_t __near * DataMapInit<class CTriggerWind>(class CTriggerWind __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerWind>()
{
  CPhysObjSaveRestoreOps *PhysObjSaveRestoreOps; // eax
  char *Name; // eax

  if ( (_S21_0 & 1) == 0 )
  {
    _S21_0 |= 1u;
    nameHolder_438.m_pszBase = "CTriggerWind";
    nameHolder_438.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_438.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_438.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_438.m_Names.m_Size = 0;
    nameHolder_438.m_Names.m_pElements = nullptr;
    nameHolder_438.m_nLenBase = 12;
    atexit(func: DataMapInit_CTriggerWind__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerWind::m_DataMap.baseMap = &CBaseVPhysicsTrigger::m_DataMap;
  if ( (_S21_0 & 2) == 0 )
  {
    _S21_0 |= 2u;
    PhysObjSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSMOTIONCONTROLLER);
    *(_QWORD *)&dataDesc_413[12].td = 0;
    *(_QWORD *)&dataDesc_413[12].override_field = 0;
    *(_QWORD *)&dataDesc_413[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_413[12].flatOffset[1] = 0;
    dataDesc_413[13].fieldTolerance = 0.0;
    dataDesc_413[12].pSaveRestoreOps = PhysObjSaveRestoreOps;
    dataDesc_413[12].inputFunc = nullptr;
    dataDesc_413[13].fieldType = FIELD_EMBEDDED;
    dataDesc_413[13].fieldName = "m_WindCallback";
    dataDesc_413[13].fieldOffset = 912;
    *(_DWORD *)&dataDesc_413[13].fieldSize = 131073;
    dataDesc_413[13].externalName = nullptr;
    dataDesc_413[13].pSaveRestoreOps = nullptr;
    dataDesc_413[13].inputFunc = nullptr;
    dataDesc_413[13].td = &CPhysicsWind::m_DataMap;
    dataDesc_413[13].fieldSizeInBytes = 12;
    dataDesc_413[13].override_field = nullptr;
    dataDesc_413[13].override_count = 0;
    *(_QWORD *)dataDesc_413[13].flatOffset = 0;
    *(_DWORD *)&dataDesc_413[13].flatGroup = 0;
    dataDesc_413[14].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_438, pszIdentifier: "WindThink");
    *(_QWORD *)&dataDesc_413[14].td = 0;
    *(_QWORD *)&dataDesc_413[14].override_field = 0;
    *(_QWORD *)&dataDesc_413[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_413[14].flatOffset[1] = 0;
    dataDesc_413[14].fieldName = Name;
    dataDesc_413[14].fieldOffset = 0;
    *(_DWORD *)&dataDesc_413[14].fieldSize = 2097153;
    dataDesc_413[14].externalName = nullptr;
    dataDesc_413[14].pSaveRestoreOps = nullptr;
    dataDesc_413[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerWind::WindThink;
    dataDesc_413[15].fieldType = FIELD_INTEGER;
    dataDesc_413[15].fieldName = "InputSetSpeed";
    dataDesc_413[15].fieldOffset = 0;
    *(_DWORD *)&dataDesc_413[15].fieldSize = 524289;
    dataDesc_413[15].externalName = "SetSpeed";
    dataDesc_413[15].pSaveRestoreOps = nullptr;
    dataDesc_413[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerWind::InputSetSpeed;
    *(_QWORD *)&dataDesc_413[15].td = 0;
    *(_QWORD *)&dataDesc_413[15].override_field = 0;
    *(_QWORD *)&dataDesc_413[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_413[15].flatOffset[1] = 0;
  }
  CTriggerWind::m_DataMap.dataNumFields = 15;
  CTriggerWind::m_DataMap.dataDesc = &dataDesc_413[1];
  return &CTriggerWind::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10245A30
// Name: struct datamap_t __near * DataMapInit<class CTriggerHierarchy>(class CTriggerHierarchy __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerHierarchy>()
{
  if ( (_S22_0 & 1) == 0 )
  {
    _S22_0 |= 1u;
    nameHolder_439.m_pszBase = "CTriggerHierarchy";
    nameHolder_439.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_439.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_439.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_439.m_Names.m_Size = 0;
    nameHolder_439.m_Names.m_pElements = nullptr;
    nameHolder_439.m_nLenBase = 17;
    atexit(func: DataMapInit_CTriggerHierarchy__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerHierarchy::m_DataMap.baseMap = &CTriggerMultiple::m_DataMap;
  CTriggerHierarchy::m_DataMap.dataNumFields = 1;
  CTriggerHierarchy::m_DataMap.dataDesc = &dataDesc_414[1];
  return &CTriggerHierarchy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10245AA0
// Name: struct datamap_t __near * DataMapInit<class CTriggerImpact>(class CTriggerImpact __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerImpact>()
{
  if ( (_S23_0 & 1) == 0 )
  {
    _S23_0 |= 1u;
    nameHolder_440.m_pszBase = "CTriggerImpact";
    nameHolder_440.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_440.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_440.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_440.m_Names.m_Size = 0;
    nameHolder_440.m_Names.m_pElements = nullptr;
    nameHolder_440.m_nLenBase = 14;
    atexit(func: DataMapInit_CTriggerImpact__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerImpact::m_DataMap.baseMap = &CTriggerMultiple::m_DataMap;
  if ( (_S23_0 & 2) == 0 )
  {
    _S23_0 |= 2u;
    dataDesc_415[6].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_415[6].inputFunc = 0;
    *(_QWORD *)&dataDesc_415[6].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_415[6].override_count = 0;
    *(_QWORD *)dataDesc_415[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_415[6].flatGroup = 0;
    dataDesc_415[7].fieldType = FIELD_VOID;
    dataDesc_415[7].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_440,
                                  pszIdentifier: "Disable");
    dataDesc_415[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_415[7].fieldSize = 2097153;
    dataDesc_415[7].externalName = nullptr;
    dataDesc_415[7].pSaveRestoreOps = nullptr;
    dataDesc_415[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall vgui::Panel::`vcall'{784,{flat}};
    *(_QWORD *)&dataDesc_415[7].td = 0;
    *(_QWORD *)&dataDesc_415[7].override_field = 0;
    *(_QWORD *)&dataDesc_415[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_415[7].flatOffset[1] = 0;
  }
  CTriggerImpact::m_DataMap.dataNumFields = 7;
  CTriggerImpact::m_DataMap.dataDesc = &dataDesc_415[1];
  return &CTriggerImpact::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10245C90
// Name: struct datamap_t __near * DataMapInit<class CTriggerPlayerMovement>(class CTriggerPlayerMovement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerPlayerMovement>()
{
  if ( (_S25_0 & 1) == 0 )
  {
    _S25_0 |= 1u;
    nameHolder_441.m_pszBase = "CTriggerPlayerMovement";
    nameHolder_441.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_441.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_441.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_441.m_Names.m_Size = 0;
    nameHolder_441.m_Names.m_pElements = nullptr;
    nameHolder_441.m_nLenBase = 22;
    atexit(func: DataMapInit_CTriggerPlayerMovement__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerPlayerMovement::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  CTriggerPlayerMovement::m_DataMap.dataNumFields = 1;
  CTriggerPlayerMovement::m_DataMap.dataDesc = dataDesc_492;
  return &CTriggerPlayerMovement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10245E10
// Name: struct datamap_t __near * DataMapInit<class CBaseVPhysicsTrigger>(class CBaseVPhysicsTrigger __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseVPhysicsTrigger>()
{
  if ( (_S26_0 & 1) == 0 )
  {
    _S26_0 |= 1u;
    nameHolder_442.m_pszBase = "CBaseVPhysicsTrigger";
    nameHolder_442.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_442.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_442.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_442.m_Names.m_Size = 0;
    nameHolder_442.m_Names.m_pElements = nullptr;
    nameHolder_442.m_nLenBase = 20;
    atexit(func: DataMapInit_CBaseVPhysicsTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseVPhysicsTrigger::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CBaseVPhysicsTrigger::m_DataMap.dataNumFields = 6;
  CBaseVPhysicsTrigger::m_DataMap.dataDesc = &dataDesc_416[1];
  return &CBaseVPhysicsTrigger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10245E90
// Name: struct datamap_t __near * DataMapInit<class CTriggerVPhysicsMotion>(class CTriggerVPhysicsMotion __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerVPhysicsMotion>()
{
  if ( (_S28 & 1) == 0 )
  {
    _S28 |= 1u;
    nameHolder_443.m_pszBase = "CTriggerVPhysicsMotion";
    nameHolder_443.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_443.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_443.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_443.m_Names.m_Size = 0;
    nameHolder_443.m_Names.m_pElements = nullptr;
    nameHolder_443.m_nLenBase = 22;
    atexit(func: DataMapInit_CTriggerVPhysicsMotion__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerVPhysicsMotion::m_DataMap.baseMap = &CBaseVPhysicsTrigger::m_DataMap;
  if ( (_S28 & 2) == 0 )
  {
    _S28 |= 2u;
    dataDesc_417[1].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSMOTIONCONTROLLER);
    *(_QWORD *)dataDesc_417[2].flatOffset = 0;
    dataDesc_417[2].fieldSize = 1;
    *(_QWORD *)&dataDesc_417[3].override_field = 0;
    *(_QWORD *)&dataDesc_417[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[3].flatOffset[1] = 0;
    dataDesc_417[2].flags = 2;
    dataDesc_417[3].fieldSize = 1;
    dataDesc_417[3].flags = 14;
    *(_QWORD *)&dataDesc_417[1].td = 0;
    *(_QWORD *)&dataDesc_417[1].override_field = 0;
    *(_QWORD *)&dataDesc_417[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[1].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_417[4].override_field = 0;
    *(_QWORD *)&dataDesc_417[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[4].flatOffset[1] = 0;
    dataDesc_417[1].inputFunc = nullptr;
    dataDesc_417[2].fieldType = FIELD_EMBEDDED;
    dataDesc_417[2].fieldName = "m_ParticleTrail";
    dataDesc_417[2].fieldOffset = 872;
    dataDesc_417[2].externalName = nullptr;
    dataDesc_417[2].pSaveRestoreOps = nullptr;
    dataDesc_417[2].inputFunc = nullptr;
    dataDesc_417[2].td = &EntityParticleTrailInfo_t::m_DataMap;
    dataDesc_417[2].fieldSizeInBytes = 20;
    dataDesc_417[2].override_field = nullptr;
    dataDesc_417[2].override_count = 0;
    dataDesc_417[2].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_417[2].flatGroup = 0;
    dataDesc_417[3].fieldType = FIELD_FLOAT;
    dataDesc_417[3].fieldName = "m_gravityScale";
    dataDesc_417[3].fieldOffset = 892;
    dataDesc_417[3].externalName = "SetGravityScale";
    dataDesc_417[3].pSaveRestoreOps = nullptr;
    dataDesc_417[3].inputFunc = nullptr;
    dataDesc_417[3].td = nullptr;
    dataDesc_417[3].fieldSizeInBytes = 4;
    dataDesc_417[4].fieldType = FIELD_FLOAT;
    dataDesc_417[4].fieldName = "m_addAirDensity";
    dataDesc_417[4].fieldOffset = 896;
    dataDesc_417[4].fieldSize = 1;
    dataDesc_417[4].flags = 14;
    dataDesc_417[4].externalName = "SetAdditionalAirDensity";
    dataDesc_417[4].pSaveRestoreOps = nullptr;
    dataDesc_417[4].inputFunc = nullptr;
    dataDesc_417[4].td = nullptr;
    dataDesc_417[4].fieldSizeInBytes = 4;
    dataDesc_417[5].fieldType = FIELD_FLOAT;
    dataDesc_417[5].fieldName = "m_linearLimit";
    dataDesc_417[5].fieldOffset = 900;
    dataDesc_417[5].fieldSize = 1;
    dataDesc_417[5].flags = 14;
    dataDesc_417[5].externalName = "SetVelocityLimit";
    dataDesc_417[5].pSaveRestoreOps = nullptr;
    dataDesc_417[5].inputFunc = nullptr;
    dataDesc_417[5].td = nullptr;
    dataDesc_417[5].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_417[5].override_field = 0;
    *(_QWORD *)&dataDesc_417[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[5].flatOffset[1] = 0;
    dataDesc_417[6].fieldType = FIELD_FLOAT;
    dataDesc_417[6].fieldName = "m_linearLimitDelta";
    dataDesc_417[6].fieldOffset = 904;
    dataDesc_417[6].fieldSize = 1;
    dataDesc_417[6].flags = 14;
    dataDesc_417[7].flags = 2;
    dataDesc_417[7].fieldSize = 1;
    dataDesc_417[8].fieldSize = 1;
    *(_QWORD *)&dataDesc_417[6].override_field = 0;
    *(_QWORD *)&dataDesc_417[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[6].flatOffset[1] = 0;
    dataDesc_417[7].fieldTolerance = 0.0;
    dataDesc_417[8].fieldTolerance = 0.0;
    dataDesc_417[9].fieldTolerance = 0.0;
    dataDesc_417[8].fieldType = FIELD_TIME;
    dataDesc_417[8].flags = 2;
    dataDesc_417[9].fieldType = FIELD_TIME;
    dataDesc_417[9].flags = 2;
    *(_QWORD *)dataDesc_417[7].flatOffset = 0;
    *(_QWORD *)dataDesc_417[9].flatOffset = 0;
    dataDesc_417[6].externalName = "SetVelocityLimitDelta";
    dataDesc_417[6].pSaveRestoreOps = nullptr;
    dataDesc_417[6].inputFunc = nullptr;
    dataDesc_417[6].td = nullptr;
    dataDesc_417[6].fieldSizeInBytes = 4;
    dataDesc_417[7].fieldType = FIELD_FLOAT;
    dataDesc_417[7].fieldName = "m_linearLimitTime";
    dataDesc_417[7].fieldOffset = 908;
    dataDesc_417[7].externalName = nullptr;
    dataDesc_417[7].pSaveRestoreOps = nullptr;
    dataDesc_417[7].inputFunc = nullptr;
    dataDesc_417[7].td = nullptr;
    dataDesc_417[7].fieldSizeInBytes = 4;
    dataDesc_417[7].override_field = nullptr;
    dataDesc_417[7].override_count = 0;
    *(_DWORD *)&dataDesc_417[7].flatGroup = 0;
    dataDesc_417[8].fieldName = "m_linearLimitStart";
    dataDesc_417[8].fieldOffset = 912;
    dataDesc_417[8].externalName = nullptr;
    dataDesc_417[8].pSaveRestoreOps = nullptr;
    dataDesc_417[8].inputFunc = nullptr;
    dataDesc_417[8].td = nullptr;
    dataDesc_417[8].fieldSizeInBytes = 4;
    dataDesc_417[8].override_field = nullptr;
    dataDesc_417[8].override_count = 0;
    *(_QWORD *)dataDesc_417[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_417[8].flatGroup = 0;
    dataDesc_417[9].fieldName = "m_linearLimitStartTime";
    dataDesc_417[9].fieldOffset = 916;
    dataDesc_417[9].fieldSize = 1;
    dataDesc_417[9].externalName = nullptr;
    dataDesc_417[9].pSaveRestoreOps = nullptr;
    dataDesc_417[9].inputFunc = nullptr;
    dataDesc_417[9].td = nullptr;
    dataDesc_417[9].fieldSizeInBytes = 4;
    dataDesc_417[9].override_field = nullptr;
    dataDesc_417[9].override_count = 0;
    *(_DWORD *)&dataDesc_417[9].flatGroup = 0;
    dataDesc_417[10].fieldType = FIELD_FLOAT;
    dataDesc_417[10].fieldName = "m_linearScale";
    dataDesc_417[10].fieldOffset = 920;
    dataDesc_417[10].fieldSize = 1;
    dataDesc_417[10].flags = 14;
    dataDesc_417[10].externalName = "SetVelocityScale";
    dataDesc_417[10].pSaveRestoreOps = nullptr;
    dataDesc_417[10].inputFunc = nullptr;
    dataDesc_417[10].td = nullptr;
    dataDesc_417[10].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_417[10].override_field = 0;
    *(_QWORD *)&dataDesc_417[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[10].flatOffset[1] = 0;
    dataDesc_417[11].fieldType = FIELD_FLOAT;
    dataDesc_417[11].fieldName = "m_angularLimit";
    dataDesc_417[11].fieldOffset = 924;
    *(_QWORD *)&dataDesc_417[11].override_field = 0;
    *(_QWORD *)&dataDesc_417[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[11].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_417[12].override_field = 0;
    *(_QWORD *)&dataDesc_417[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[12].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_417[13].override_field = 0;
    *(_QWORD *)&dataDesc_417[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[13].flatOffset[1] = 0;
    dataDesc_417[11].fieldSize = 1;
    dataDesc_417[11].fieldSizeInBytes = 4;
    dataDesc_417[12].fieldSize = 1;
    dataDesc_417[12].fieldSizeInBytes = 4;
    dataDesc_417[13].fieldSize = 1;
    dataDesc_417[13].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_417[14].override_field = 0;
    *(_QWORD *)&dataDesc_417[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[14].flatOffset[1] = 0;
    dataDesc_417[11].flags = 14;
    dataDesc_417[11].externalName = "SetAngVelocityLimit";
    dataDesc_417[11].pSaveRestoreOps = nullptr;
    dataDesc_417[11].inputFunc = nullptr;
    dataDesc_417[11].td = nullptr;
    dataDesc_417[12].fieldType = FIELD_FLOAT;
    dataDesc_417[12].fieldName = "m_angularScale";
    dataDesc_417[12].fieldOffset = 928;
    dataDesc_417[12].flags = 14;
    dataDesc_417[12].externalName = "SetAngVelocityScale";
    dataDesc_417[12].pSaveRestoreOps = nullptr;
    dataDesc_417[12].inputFunc = nullptr;
    dataDesc_417[12].td = nullptr;
    dataDesc_417[13].fieldType = FIELD_FLOAT;
    dataDesc_417[13].fieldName = "m_linearForce";
    dataDesc_417[13].fieldOffset = 932;
    dataDesc_417[13].flags = 14;
    dataDesc_417[13].externalName = "SetLinearForce";
    dataDesc_417[13].pSaveRestoreOps = nullptr;
    dataDesc_417[13].inputFunc = nullptr;
    dataDesc_417[13].td = nullptr;
    dataDesc_417[14].fieldType = FIELD_VECTOR;
    dataDesc_417[14].fieldName = "m_linearForceAngles";
    dataDesc_417[14].fieldOffset = 936;
    *(_DWORD *)&dataDesc_417[14].fieldSize = 917505;
    dataDesc_417[14].externalName = "SetLinearForceAngles";
    dataDesc_417[14].pSaveRestoreOps = nullptr;
    dataDesc_417[14].inputFunc = nullptr;
    dataDesc_417[14].td = nullptr;
    dataDesc_417[14].fieldSizeInBytes = 12;
    dataDesc_417[15].fieldType = FIELD_STRING;
    dataDesc_417[15].fieldName = "InputSetVelocityLimitTime";
    dataDesc_417[15].fieldOffset = 0;
    *(_DWORD *)&dataDesc_417[15].fieldSize = 524289;
    dataDesc_417[15].externalName = "SetVelocityLimitTime";
    dataDesc_417[15].pSaveRestoreOps = nullptr;
    dataDesc_417[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerVPhysicsMotion::InputSetVelocityLimitTime;
    *(_QWORD *)&dataDesc_417[15].td = 0;
    *(_QWORD *)&dataDesc_417[15].override_field = 0;
    *(_QWORD *)&dataDesc_417[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_417[15].flatOffset[1] = 0;
  }
  CTriggerVPhysicsMotion::m_DataMap.dataNumFields = 15;
  CTriggerVPhysicsMotion::m_DataMap.dataDesc = &dataDesc_417[1];
  return &CTriggerVPhysicsMotion::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10246590
// Name: struct datamap_t __near * DataMapInit<class CTriggerAutoCrouch>(class CTriggerAutoCrouch __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerAutoCrouch>()
{
  if ( (_S29 & 1) == 0 )
  {
    _S29 |= 1u;
    nameHolder_444.m_pszBase = "CTriggerAutoCrouch";
    nameHolder_444.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_444.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_444.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_444.m_Names.m_Size = 0;
    nameHolder_444.m_Names.m_pElements = nullptr;
    nameHolder_444.m_nLenBase = 18;
    atexit(func: DataMapInit_CTriggerAutoCrouch__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerAutoCrouch::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  CTriggerAutoCrouch::m_DataMap.dataNumFields = 1;
  CTriggerAutoCrouch::m_DataMap.dataDesc = dataDesc_493;
  return &CTriggerAutoCrouch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10246770
// Name: struct datamap_t __near * DataMapInit<class CBaseTrigger>(class CBaseTrigger __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseTrigger>()
{
  if ( (_S2_228 & 1) == 0 )
  {
    _S2_228 |= 1u;
    nameHolder_445.m_pszBase = "CBaseTrigger";
    nameHolder_445.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_445.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_445.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_445.m_Names.m_Size = 0;
    nameHolder_445.m_Names.m_pElements = nullptr;
    nameHolder_445.m_nLenBase = 12;
    atexit(func: DataMapInit_CBaseTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseTrigger::m_DataMap.baseMap = &CBaseToggle::m_DataMap;
  if ( (_S2_228 & 2) == 0 )
  {
    _S2_228 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    *(_QWORD *)&dataDesc_418[4].td = 0;
    *(_QWORD *)&dataDesc_418[4].override_field = 0;
    *(_QWORD *)&dataDesc_418[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_418[4].flatOffset[1] = 0;
    dataDesc_418[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_418[5].td = 0;
    *(_QWORD *)&dataDesc_418[5].override_field = 0;
    *(_QWORD *)&dataDesc_418[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_418[5].flatOffset[1] = 0;
    dataDesc_418[5].flags = 8;
    dataDesc_418[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_418[6].td = 0;
    *(_QWORD *)&dataDesc_418[6].override_field = 0;
    *(_QWORD *)&dataDesc_418[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_418[6].flatOffset[1] = 0;
    dataDesc_418[6].flags = 8;
    dataDesc_418[7].fieldSize = 1;
    *(_QWORD *)&dataDesc_418[7].td = 0;
    *(_QWORD *)&dataDesc_418[7].override_field = 0;
    *(_QWORD *)&dataDesc_418[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_418[7].flatOffset[1] = 0;
    dataDesc_418[7].flags = 8;
    dataDesc_418[8].fieldSize = 1;
    *(_QWORD *)&dataDesc_418[8].td = 0;
    *(_QWORD *)&dataDesc_418[8].override_field = 0;
    *(_QWORD *)&dataDesc_418[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_418[8].flatOffset[1] = 0;
    dataDesc_418[4].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_418[4].inputFunc = nullptr;
    dataDesc_418[5].fieldType = FIELD_VOID;
    dataDesc_418[5].fieldName = "InputEnable";
    dataDesc_418[5].fieldOffset = 0;
    dataDesc_418[5].externalName = "Enable";
    dataDesc_418[5].pSaveRestoreOps = nullptr;
    dataDesc_418[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall vgui::Panel::`vcall'{788,{flat}};
    dataDesc_418[6].fieldType = FIELD_VOID;
    dataDesc_418[6].fieldName = "InputDisable";
    dataDesc_418[6].fieldOffset = 0;
    dataDesc_418[6].externalName = "Disable";
    dataDesc_418[6].pSaveRestoreOps = nullptr;
    dataDesc_418[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall vgui::Panel::`vcall'{792,{flat}};
    dataDesc_418[7].fieldType = FIELD_VOID;
    dataDesc_418[7].fieldName = "InputToggle";
    dataDesc_418[7].fieldOffset = 0;
    dataDesc_418[7].externalName = "Toggle";
    dataDesc_418[7].pSaveRestoreOps = nullptr;
    dataDesc_418[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall vgui::Panel::`vcall'{796,{flat}};
    dataDesc_418[8].fieldType = FIELD_VOID;
    dataDesc_418[8].fieldName = "InputTouchTest";
    dataDesc_418[8].fieldOffset = 0;
    dataDesc_418[8].flags = 8;
    dataDesc_418[8].externalName = "TouchTest";
    dataDesc_418[8].pSaveRestoreOps = nullptr;
    dataDesc_418[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall vgui::Panel::`vcall'{800,{flat}};
    dataDesc_418[9].fieldType = FIELD_VOID;
    dataDesc_418[9].fieldName = "InputStartTouch";
    dataDesc_418[9].fieldOffset = 0;
    dataDesc_418[9].fieldSize = 1;
    dataDesc_418[9].flags = 8;
    dataDesc_418[9].externalName = "StartTouch";
    dataDesc_418[9].pSaveRestoreOps = nullptr;
    dataDesc_418[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall vgui::Panel::`vcall'{804,{flat}};
    *(_QWORD *)&dataDesc_418[9].td = 0;
    *(_QWORD *)&dataDesc_418[9].override_field = 0;
    *(_QWORD *)&dataDesc_418[9].fieldTolerance = 0;
    dataDesc_418[10].flags = 8;
    dataDesc_418[11].flags = 22;
    dataDesc_418[12].fieldSize = 1;
    dataDesc_418[12].flags = 22;
    *(_QWORD *)&dataDesc_418[9].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_418[10].td = 0;
    *(_QWORD *)&dataDesc_418[10].override_field = 0;
    *(_QWORD *)&dataDesc_418[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_418[10].flatOffset[1] = 0;
    dataDesc_418[13].fieldSize = 1;
    *(_QWORD *)&dataDesc_418[11].inputFunc = 0;
    *(_QWORD *)&dataDesc_418[11].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_418[11].override_count = 0;
    *(_QWORD *)dataDesc_418[11].flatOffset = 0;
    dataDesc_418[13].flags = 22;
    *(_QWORD *)&dataDesc_418[12].inputFunc = 0;
    *(_QWORD *)&dataDesc_418[12].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_418[12].override_count = 0;
    *(_QWORD *)dataDesc_418[12].flatOffset = 0;
    dataDesc_418[10].fieldSize = 1;
    dataDesc_418[11].fieldSize = 1;
    dataDesc_418[14].fieldSize = 1;
    *(_QWORD *)&dataDesc_418[13].inputFunc = 0;
    *(_QWORD *)&dataDesc_418[13].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_418[13].override_count = 0;
    *(_QWORD *)dataDesc_418[13].flatOffset = 0;
    dataDesc_418[10].fieldType = FIELD_VOID;
    dataDesc_418[10].fieldName = "InputEndTouch";
    dataDesc_418[10].fieldOffset = 0;
    dataDesc_418[10].externalName = "EndTouch";
    dataDesc_418[10].pSaveRestoreOps = nullptr;
    dataDesc_418[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall vgui::Panel::`vcall'{808,{flat}};
    dataDesc_418[11].fieldType = FIELD_CUSTOM;
    dataDesc_418[11].fieldName = "m_OnStartTouch";
    dataDesc_418[11].fieldOffset = 984;
    dataDesc_418[11].externalName = "OnStartTouch";
    dataDesc_418[11].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_418[11].flatGroup = 0;
    dataDesc_418[12].fieldType = FIELD_CUSTOM;
    dataDesc_418[12].fieldName = "m_OnStartTouchAll";
    dataDesc_418[12].fieldOffset = 1008;
    dataDesc_418[12].externalName = "OnStartTouchAll";
    dataDesc_418[12].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_418[12].flatGroup = 0;
    dataDesc_418[13].fieldType = FIELD_CUSTOM;
    dataDesc_418[13].fieldName = "m_OnEndTouch";
    dataDesc_418[13].fieldOffset = 1032;
    dataDesc_418[13].externalName = "OnEndTouch";
    dataDesc_418[13].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_418[13].flatGroup = 0;
    dataDesc_418[14].fieldType = FIELD_CUSTOM;
    dataDesc_418[14].fieldName = "m_OnEndTouchAll";
    dataDesc_418[14].fieldOffset = 1056;
    dataDesc_418[14].flags = 22;
    dataDesc_418[14].externalName = "OnEndTouchAll";
    dataDesc_418[14].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_418[14].inputFunc = 0;
    *(_QWORD *)&dataDesc_418[14].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_418[14].override_count = 0;
    *(_QWORD *)dataDesc_418[14].flatOffset = 0;
    *(_DWORD *)&dataDesc_418[14].flatGroup = 0;
    dataDesc_418[15].fieldType = FIELD_CUSTOM;
    dataDesc_418[15].fieldName = "m_OnTouching";
    dataDesc_418[15].fieldOffset = 1080;
    dataDesc_418[15].fieldSize = 1;
    *(_QWORD *)&dataDesc_418[15].inputFunc = 0;
    *(_QWORD *)&dataDesc_418[15].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_418[15].override_count = 0;
    *(_QWORD *)dataDesc_418[15].flatOffset = 0;
    dataDesc_418[15].flags = 22;
    dataDesc_418[15].externalName = "OnTouching";
    dataDesc_418[15].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_418[15].flatGroup = 0;
    dataDesc_418[16].fieldType = FIELD_CUSTOM;
    dataDesc_418[16].fieldName = "m_OnNotTouching";
    dataDesc_418[16].fieldOffset = 1104;
    *(_DWORD *)&dataDesc_418[16].fieldSize = 1441793;
    dataDesc_418[16].externalName = "OnNotTouching";
    dataDesc_418[16].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_418[16].inputFunc = 0;
    *(_QWORD *)&dataDesc_418[16].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_418[16].override_count = 0;
    *(_QWORD *)dataDesc_418[16].flatOffset = 0;
    *(_DWORD *)&dataDesc_418[16].flatGroup = 0;
  }
  CBaseTrigger::m_DataMap.dataNumFields = 16;
  CBaseTrigger::m_DataMap.dataDesc = &dataDesc_418[1];
  return &CBaseTrigger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10248D50
// Name: struct datamap_t __near * DataMapInit<class CTriggerCameraMultiplayer>(class CTriggerCameraMultiplayer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerCameraMultiplayer>()
{
  if ( (_S17_2 & 1) == 0 )
  {
    _S17_2 |= 1u;
    nameHolder_447.m_pszBase = "CTriggerCameraMultiplayer";
    nameHolder_447.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_447.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_447.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_447.m_Names.m_Size = 0;
    nameHolder_447.m_Names.m_pElements = nullptr;
    nameHolder_447.m_nLenBase = 25;
    atexit(func: DataMapInit_CTriggerCameraMultiplayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerCameraMultiplayer::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CTriggerCameraMultiplayer::m_DataMap.dataNumFields = 10;
  CTriggerCameraMultiplayer::m_DataMap.dataDesc = &dataDesc_419[1];
  return &CTriggerCameraMultiplayer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102494B0
// Name: struct datamap_t __near * DataMapInit<class CTriggerCamera>(class CTriggerCamera __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerCamera>()
{
  if ( (_S16_2 & 1) == 0 )
  {
    _S16_2 |= 1u;
    nameHolder_448.m_pszBase = "CTriggerCamera";
    nameHolder_448.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_448.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_448.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_448.m_Names.m_Size = 0;
    nameHolder_448.m_Names.m_pElements = nullptr;
    nameHolder_448.m_nLenBase = 14;
    atexit(func: DataMapInit_CTriggerCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerCamera::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S16_2 & 2) == 0 )
  {
    _S16_2 |= 2u;
    dataDesc_420[31].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_448,
                                   pszIdentifier: "FollowTarget");
    dataDesc_420[31].flags = 32;
    dataDesc_420[31].fieldOffset = 0;
    dataDesc_420[31].fieldSize = 1;
    dataDesc_420[31].externalName = nullptr;
    dataDesc_420[31].pSaveRestoreOps = nullptr;
    dataDesc_420[31].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerCamera::FollowTarget;
    *(_QWORD *)&dataDesc_420[31].td = 0;
    *(_QWORD *)&dataDesc_420[31].override_field = 0;
    *(_QWORD *)&dataDesc_420[31].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_420[31].flatOffset[1] = 0;
    dataDesc_420[32].fieldType = FIELD_VOID;
    dataDesc_420[32].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_448,
                                   pszIdentifier: "ReturnToEyes");
    dataDesc_420[32].fieldSize = 1;
    *(_QWORD *)&dataDesc_420[32].td = 0;
    *(_QWORD *)&dataDesc_420[32].override_field = 0;
    *(_QWORD *)&dataDesc_420[32].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_420[32].flatOffset[1] = 0;
    dataDesc_420[32].fieldOffset = 0;
    dataDesc_420[32].flags = 32;
    dataDesc_420[32].externalName = nullptr;
    dataDesc_420[32].pSaveRestoreOps = nullptr;
    dataDesc_420[32].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerCamera::ReturnToEyes;
    dataDesc_420[33].fieldType = FIELD_CUSTOM;
    dataDesc_420[33].fieldName = "m_OnEndFollow";
    dataDesc_420[33].fieldOffset = 948;
    *(_DWORD *)&dataDesc_420[33].fieldSize = 1441793;
    dataDesc_420[33].externalName = "OnEndFollow";
    dataDesc_420[33].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_420[33].inputFunc = 0;
    *(_QWORD *)&dataDesc_420[33].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_420[33].override_count = 0;
    *(_QWORD *)dataDesc_420[33].flatOffset = 0;
    *(_DWORD *)&dataDesc_420[33].flatGroup = 0;
  }
  CTriggerCamera::m_DataMap.dataNumFields = 33;
  CTriggerCamera::m_DataMap.dataDesc = &dataDesc_420[1];
  return &CTriggerCamera::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10249780
// Name: struct datamap_t __near * DataMapInit<class CTriggerViewProxy>(class CTriggerViewProxy __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerViewProxy>()
{
  if ( (_S18_2 & 1) == 0 )
  {
    _S18_2 |= 1u;
    nameHolder_449.m_pszBase = "CTriggerViewProxy";
    nameHolder_449.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_449.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_449.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_449.m_Names.m_Size = 0;
    nameHolder_449.m_Names.m_pElements = nullptr;
    nameHolder_449.m_nLenBase = 17;
    atexit(func: DataMapInit_CTriggerViewProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerViewProxy::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S18_2 & 2) == 0 )
  {
    _S18_2 |= 2u;
    dataDesc_421[21].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_449,
                                   pszIdentifier: "TranslateViewToProxy");
    dataDesc_421[21].fieldOffset = 0;
    *(_DWORD *)&dataDesc_421[21].fieldSize = 2097153;
    dataDesc_421[21].externalName = nullptr;
    dataDesc_421[21].pSaveRestoreOps = nullptr;
    dataDesc_421[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerViewProxy::TranslateViewToProxy;
    *(_QWORD *)&dataDesc_421[21].td = 0;
    *(_QWORD *)&dataDesc_421[21].override_field = 0;
    *(_QWORD *)&dataDesc_421[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_421[21].flatOffset[1] = 0;
  }
  CTriggerViewProxy::m_DataMap.dataNumFields = 21;
  CTriggerViewProxy::m_DataMap.dataDesc = &dataDesc_421[1];
  return &CTriggerViewProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040BAA0
// Name: _dynamic_initializer_for__g_CBaseTrigger_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseTrigger_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseTrigger_ClassReg,
           pNetworkName: "CBaseTrigger",
           pTable: &DT_BaseTrigger::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040BD30
// Name: _dynamic_initializer_for__ai_changetarget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_changetarget__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_ChangeTarget> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_changetarget,
           a3: "ai_changetarget");
}

//------------------------------------------------------------------------------
// Address: 0x1040BD60
// Name: _dynamic_initializer_for__ai_changehintgroup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_changehintgroup__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_ChangeHintGroup> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_changehintgroup,
           a3: "ai_changehintgroup");
}

//------------------------------------------------------------------------------
// Address: 0x1040BDC0
// Name: _dynamic_initializer_for__g_CTriggerCamera_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CTriggerCamera_ScriptDesc__()
{
  InitCTriggerCameraScriptDesc();
  g_CTriggerCamera_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CTriggerCamera_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CTriggerCamera_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x1040BF60
// Name: _dynamic_initializer_for__g_CTriggerPlayerMovement_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTriggerPlayerMovement_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTriggerPlayerMovement_ClassReg,
           pNetworkName: "CTriggerPlayerMovement",
           pTable: &DT_TriggerPlayerMovement::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040BFF0
// Name: _dynamic_initializer_for__g_CBaseVPhysicsTrigger_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseVPhysicsTrigger_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseVPhysicsTrigger_ClassReg,
           pNetworkName: "CBaseVPhysicsTrigger",
           pTable: &DT_BaseVPhysicsTrigger::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040C0C0
// Name: _dynamic_initializer_for__dumpentityfactories__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dumpentityfactories__()
{
  ConCommand::ConCommand(
    this: &dumpentityfactories,
    pName: "dumpentityfactories",
    callback: DumpEntityFactories_f,
    pHelpString: "Lists all entity factory names.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dumpentityfactories__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C0F0
// Name: _dynamic_initializer_for__dump_entity_sizes_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dump_entity_sizes_command__()
{
  ConCommand::ConCommand(
    this: &dump_entity_sizes_command,
    pName: "dump_entity_sizes",
    callback: (void (__cdecl *)())dump_entity_sizes,
    pHelpString: "Print sizeof(entclass)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dump_entity_sizes_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C120
// Name: _dynamic_initializer_for__g_PrecacheOtherList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PrecacheOtherList__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_PrecacheOtherList, name: "CPrecacheOtherList");
  g_PrecacheOtherList.__vftable = (CPrecacheOtherList_vtbl *)&CPrecacheOtherList::`vftable';
  CUtlSymbolTable::CUtlSymbolTable(this: &g_PrecacheOtherList.m_list, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_PrecacheOtherList__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C160
// Name: _dynamic_initializer_for__g_CheckClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CheckClient__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_CheckClient, name: "CCheckClient");
  g_CheckClient.__vftable = (CCheckClient_vtbl *)&CCheckClient::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_CheckClient__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C190
// Name: _dynamic_initializer_for__sv_strict_notarget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_strict_notarget__()
{
  ConVar::ConVar(
    this: &sv_strict_notarget,
    pName: "sv_strict_notarget",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If set, notarget will cause entities to never think they are in the pvs");
  return atexit(func: dynamic_atexit_destructor_for__sv_strict_notarget__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C1C0
// Name: _dynamic_initializer_for__kdtree_test__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__kdtree_test__()
{
  ConCommand::ConCommand(
    this: &kdtree_test,
    pName: "kdtree_test",
    callback: (void (__cdecl *)())CC_KDTreeTest,
    pHelpString: "Tests spatial partition for entities queries.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__kdtree_test__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C1F0
// Name: _dynamic_initializer_for__voxeltree_view__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__voxeltree_view__()
{
  ConCommand::ConCommand(
    this: &voxeltree_view,
    pName: "voxeltree_view",
    callback: CC_VoxelTreeView,
    pHelpString: "View entities in the voxel-tree.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voxeltree_view__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C220
// Name: _dynamic_initializer_for__voxeltree_playerview__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__voxeltree_playerview__()
{
  ConCommand::ConCommand(
    this: &voxeltree_playerview,
    pName: "voxeltree_playerview",
    callback: CC_VoxelTreePlayerView,
    pHelpString: "View entities in the voxel-tree at the player position.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voxeltree_playerview__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C250
// Name: _dynamic_initializer_for__voxeltree_box__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__voxeltree_box__()
{
  ConCommand::ConCommand(
    this: &voxeltree_box,
    pName: "voxeltree_box",
    callback: (void (__cdecl *)())CC_VoxelTreeBox,
    pHelpString: "View entities in the voxel-tree inside box <Vector(min), Vector(max)>.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voxeltree_box__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C280
// Name: _dynamic_initializer_for__voxeltree_sphere__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__voxeltree_sphere__()
{
  ConCommand::ConCommand(
    this: &voxeltree_sphere,
    pName: "voxeltree_sphere",
    callback: (void (__cdecl *)())CC_VoxelTreeSphere,
    pHelpString: "View entities in the voxel-tree inside sphere <Vector(center), float(radius)>.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voxeltree_sphere__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EA20
// Name: _ServerClassInit_DT_TriggerPlayerMovement::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TriggerPlayerMovement::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S24_0;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041EA50
// Name: _ServerClassInit_DT_BaseVPhysicsTrigger::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseVPhysicsTrigger::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S27_0;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041EA70
// Name: _ServerClassInit_DT_BaseTrigger::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseTrigger::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_135;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041EA90
// Name: _DataMapInit_CTriggerRemove__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerRemove__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_426);
}

//------------------------------------------------------------------------------
// Address: 0x1041EAA0
// Name: _DataMapInit_CTriggerHurt__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerHurt__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_446);
}

//------------------------------------------------------------------------------
// Address: 0x1041EAB0
// Name: _DataMapInit_CTriggerMultiple__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerMultiple__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_427);
}

//------------------------------------------------------------------------------
// Address: 0x1041EAC0
// Name: _DataMapInit_CTriggerLook__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerLook__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_428);
}

//------------------------------------------------------------------------------
// Address: 0x1041EAD0
// Name: _DataMapInit_CChangeLevel__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CChangeLevel__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_450);
}

//------------------------------------------------------------------------------
// Address: 0x1041EAE0
// Name: _DataMapInit_CTriggerPush__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerPush__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_429);
}

//------------------------------------------------------------------------------
// Address: 0x1041EAF0
// Name: _DataMapInit_CTriggerTeleport__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerTeleport__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_430);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB00
// Name: _DataMapInit_CTriggerToggleSave__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerToggleSave__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_431);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB10
// Name: _DataMapInit_CTriggerSave__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerSave__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_432);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB20
// Name: _DataMapInit_CTriggerGravity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerGravity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_433);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB30
// Name: _DataMapInit_CAI_ChangeTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_ChangeTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_434);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB40
// Name: _DataMapInit_CAI_ChangeHintGroup__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_ChangeHintGroup__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_435);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB50
// Name: _DataMapInit_CTriggerCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_448);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB60
// Name: _DataMapInit_CTriggerCameraMultiplayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerCameraMultiplayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_447);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB70
// Name: _DataMapInit_CTriggerViewProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerViewProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_449);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB80
// Name: _DataMapInit_CTriggerProximity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerProximity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_436);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB90
// Name: _DataMapInit_CPhysicsWind__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysicsWind__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_437);
}

//------------------------------------------------------------------------------
// Address: 0x1041EBA0
// Name: _DataMapInit_CTriggerWind__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerWind__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_438);
}

//------------------------------------------------------------------------------
// Address: 0x1041EBB0
// Name: _DataMapInit_CTriggerHierarchy__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerHierarchy__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_439);
}

//------------------------------------------------------------------------------
// Address: 0x1041EBC0
// Name: _DataMapInit_CTriggerImpact__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerImpact__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_440);
}

//------------------------------------------------------------------------------
// Address: 0x1041EBD0
// Name: _DataMapInit_CTriggerPlayerMovement__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerPlayerMovement__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_441);
}

//------------------------------------------------------------------------------
// Address: 0x1041EBE0
// Name: _DataMapInit_CBaseVPhysicsTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseVPhysicsTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_442);
}

//------------------------------------------------------------------------------
// Address: 0x1041EBF0
// Name: _DataMapInit_CTriggerVPhysicsMotion__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerVPhysicsMotion__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_443);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC00
// Name: _DataMapInit_CTriggerAutoCrouch__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerAutoCrouch__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_444);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC10
// Name: _dynamic_atexit_destructor_for__g_hWeaponFireTriggers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_hWeaponFireTriggers__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_hWeaponFireTriggers);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC20
// Name: _DataMapInit_CBaseTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_445);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC30
// Name: _dynamic_atexit_destructor_for__g_CTriggerCamera_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CTriggerCamera_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CTriggerCamera_ScriptDesc.m_FunctionBindings);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC40
// Name: _dynamic_atexit_destructor_for__dumpentityfactories__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dumpentityfactories__()
{
  ConCommand::~ConCommand(this: &dumpentityfactories);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC50
// Name: _dynamic_atexit_destructor_for__dump_entity_sizes_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dump_entity_sizes_command__()
{
  ConCommand::~ConCommand(this: &dump_entity_sizes_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC60
// Name: _dynamic_atexit_destructor_for__sv_strict_notarget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_strict_notarget__()
{
  ConVar::~ConVar(this: &sv_strict_notarget);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC70
// Name: _dynamic_atexit_destructor_for__kdtree_test__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__kdtree_test__()
{
  ConCommand::~ConCommand(this: &kdtree_test);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC80
// Name: _dynamic_atexit_destructor_for__voxeltree_view__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voxeltree_view__()
{
  ConCommand::~ConCommand(this: &voxeltree_view);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC90
// Name: _dynamic_atexit_destructor_for__voxeltree_playerview__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voxeltree_playerview__()
{
  ConCommand::~ConCommand(this: &voxeltree_playerview);
}

//------------------------------------------------------------------------------
// Address: 0x1041ECA0
// Name: _dynamic_atexit_destructor_for__voxeltree_box__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voxeltree_box__()
{
  ConCommand::~ConCommand(this: &voxeltree_box);
}

//------------------------------------------------------------------------------
// Address: 0x1041ECB0
// Name: _dynamic_atexit_destructor_for__voxeltree_sphere__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voxeltree_sphere__()
{
  ConCommand::~ConCommand(this: &voxeltree_sphere);
}
