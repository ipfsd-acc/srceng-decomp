// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/fogcontroller.cpp
// Functions: 50
// ============================================================

#include "game\server\fogcontroller.h"

//------------------------------------------------------------------------------
// Address: 0x1012AFB0
// Name: class CFogSystem __near * FogSystem(void)
// Source: json
//------------------------------------------------------------------------------
CFogSystem *__cdecl FogSystem()
{
  return &s_FogSystem;
}

//------------------------------------------------------------------------------
// Address: 0x1012AFC0
// Name: public: virtual struct datamap_t __near * CFogController::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFogController::GetDataDescMap(CFogController *this)
{
  return &CFogController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012AFD0
// Name: public: virtual class ServerClass __near * CFogController::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFogController::GetServerClass(CFogController *this)
{
  return &g_CFogController_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1012AFE0
// Name: public: virtual struct datamap_t __near * CFogTrigger::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFogTrigger::GetDataDescMap(CFogTrigger *this)
{
  return &CFogTrigger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012AFF0
// Name: public: virtual void CFogTrigger::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogTrigger::StartTouch(CFogTrigger *this, CBaseEntity *other)
{
  CBaseCombatCharacter *v3; // eax

  if ( this->PassesTriggerFilters(this, a2: other) )
  {
    CBaseTrigger::StartTouch(this, pOther: other);
    v3 = other->MyCombatCharacterPointer(this: other);
    if ( v3 != nullptr )
      CBaseCombatCharacter::OnFogTriggerStartTouch(this: v3, fogTrigger: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B030
// Name: public: virtual void CFogTrigger::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogTrigger::EndTouch(CFogTrigger *this, CBaseEntity *other)
{
  CBaseCombatCharacter *v3; // eax

  if ( this->PassesTriggerFilters(this, a2: other) )
  {
    CBaseTrigger::EndTouch(this, pOther: other);
    v3 = other->MyCombatCharacterPointer(this: other);
    if ( v3 != nullptr )
      CBaseCombatCharacter::OnFogTriggerEndTouch(this: v3, fogTrigger: (unsigned int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B0A0
// Name: public: virtual int CFogController::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFogController::DrawDebugTextOverlays(CFogController *this)
{
  int result; // eax
  int v3; // esi
  const char *v4; // eax
  int v5; // esi
  unsigned __int8 g; // bh
  unsigned __int8 v7; // bh
  char tempstr[512]; // [esp+20h] [ebp-204h] BYREF
  color32_s color; // [esp+220h] [ebp-4h]

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    v4 = "On";
    if ( !this->m_fog.enable.m_Value )
      v4 = "Off";
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "State: %s", v4);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v5 = v3 + 1;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Start: %3.0f", this->m_fog.start.m_Value);
    CBaseEntity::EntityText(this, text_offset: v5++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "End  : %3.0f", this->m_fog.end.m_Value);
    CBaseEntity::EntityText(this, text_offset: v5++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    color = (color32_s)this->m_fog.colorPrimary;
    g = color.g;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "1) Red  : %i", color.r);
    CBaseEntity::EntityText(this, text_offset: v5++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "1) Green: %i", g);
    CBaseEntity::EntityText(this, text_offset: v5++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "1) Blue : %i", color.b);
    CBaseEntity::EntityText(this, text_offset: v5++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    color = (color32_s)this->m_fog.colorSecondary;
    v7 = color.g;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "2) Red  : %i", color.r);
    CBaseEntity::EntityText(this, text_offset: v5++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "2) Green: %i", v7);
    CBaseEntity::EntityText(this, text_offset: v5++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "2) Blue : %i", color.b);
    CBaseEntity::EntityText(this, text_offset: v5++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "HDR Color Scale: %0.3f", this->m_fog.HDRColorScale.m_Value);
    CBaseEntity::EntityText(this, text_offset: v5, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v5 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012B800
// Name: public: virtual void CFogController::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFogController::Activate(CFogController *this@<ecx>, int a2@<ebp>, int a3@<edi>)
{
  CBaseEntity::Activate(this);
  if ( this->m_bUseAngles )
  {
    ((void (__thiscall *)(CFogController::NetworkVar_m_fog *, CNetworkVectorBase<Vector,fogparams_t::NetworkVar_dirPrimary> *, int))this->m_fog.NetworkStateChanged)(
      a1: &this->m_fog,
      a2: &this->m_fog.dirPrimary,
      a3);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    AngleVectors(angles: &this->m_angAbsRotation, forward: &this->m_fog.dirPrimary.m_Value);
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.dirPrimary);
    this->m_fog.dirPrimary.m_Value.x = this->m_fog.dirPrimary.m_Value.x * -1.0;
    this->m_fog.dirPrimary.m_Value.y = this->m_fog.dirPrimary.m_Value.y * -1.0;
    this->m_fog.dirPrimary.m_Value.z = this->m_fog.dirPrimary.m_Value.z * -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B890
// Name: public: void CFogController::InputSetAngles(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetAngles(CFogController *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  Vector vTemp; // [esp+Ch] [ebp-18h] BYREF
  QAngle angles; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

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
  UTIL_StringToVector(pVector: &angles.x, pString: iVal);
  AngleVectors(&angles, forward: &vTemp);
  CBaseEntity::SetAbsAngles(this, absAngles: &angles);
  this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.dirPrimary);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  AngleVectors(angles: &this->m_angAbsRotation, forward: &this->m_fog.dirPrimary.m_Value);
  this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.dirPrimary);
  this->m_fog.dirPrimary.m_Value.x = this->m_fog.dirPrimary.m_Value.x * -1.0;
  this->m_fog.dirPrimary.m_Value.y = this->m_fog.dirPrimary.m_Value.y * -1.0;
  this->m_fog.dirPrimary.m_Value.z = this->m_fog.dirPrimary.m_Value.z * -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B960
// Name: private: void CFogSystem::InitMasterController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogSystem::InitMasterController(CFogSystem *this)
{
  CBaseEntity *EntityByClassname; // esi
  unsigned int m_Index; // eax

  EntityByClassname = nullptr;
  while ( 1 )
  {
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: EntityByClassname,
                          szName: "env_fog_controller");
    if ( EntityByClassname == nullptr )
      break;
    m_Index = this->m_hMasterController.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
      || (EntityByClassname->m_spawnflags.m_Value & 1) != 0 )
    {
      this->m_hMasterController.m_Index = EntityByClassname->GetRefEHandle(this: EntityByClassname)->m_Index;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B9E0
// Name: public: virtual void CFogSystem::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogSystem::FireGameEvent(CFogSystem *this, IGameEvent *pEvent)
{
  CFogSystem::InitMasterController(this: (CFogSystem *)((char *)this - 12));
}

//------------------------------------------------------------------------------
// Address: 0x1012B9F0
// Name: public: virtual void CFogSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogSystem::LevelInitPostEntity(CFogSystem *this)
{
  CBasePlayer *LocalPlayer; // eax
  unsigned int m_Index; // esi

  CFogSystem::InitMasterController(this);
  if ( gpGlobals->maxClients == 1 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer != nullptr )
    {
      m_Index = LocalPlayer->m_PlayerFog.m_hCtrl.m_Value.m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        CBasePlayer::InitFogController(this: LocalPlayer);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BAD0
// Name: public: virtual void CFogController::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::Spawn(CFogController *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  if ( this->m_fog.colorPrimaryLerpTo.m_Value.r != this->m_fog.colorPrimary.m_Value.r
    || this->m_fog.colorPrimaryLerpTo.m_Value.g != this->m_fog.colorPrimary.m_Value.g
    || this->m_fog.colorPrimaryLerpTo.m_Value.b != this->m_fog.colorPrimary.m_Value.b
    || this->m_fog.colorPrimaryLerpTo.m_Value.a != this->m_fog.colorPrimary.m_Value.a )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.colorPrimaryLerpTo);
    this->m_fog.colorPrimaryLerpTo = (CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorPrimaryLerpTo>)this->m_fog.colorPrimary;
  }
  if ( this->m_fog.colorSecondaryLerpTo.m_Value.r != this->m_fog.colorSecondary.m_Value.r
    || this->m_fog.colorSecondaryLerpTo.m_Value.g != this->m_fog.colorSecondary.m_Value.g
    || this->m_fog.colorSecondaryLerpTo.m_Value.b != this->m_fog.colorSecondary.m_Value.b
    || this->m_fog.colorSecondaryLerpTo.m_Value.a != this->m_fog.colorSecondary.m_Value.a )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.colorSecondaryLerpTo);
    this->m_fog.colorSecondaryLerpTo = (CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorSecondaryLerpTo>)this->m_fog.colorSecondary;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BB70
// Name: public: void CFogController::InputSetColor(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetColor(CFogController *this, inputdata_t *inputdata)
{
  const char *pszValue; // ebx
  CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorPrimary> *p_colorPrimary; // esi

  pszValue = inputdata->value.iszVal.pszValue;
  p_colorPrimary = &this->m_fog.colorPrimary;
  if ( *(_WORD *)&this->m_fog.colorPrimary.m_Value.r != (_WORD)pszValue
    || this->m_fog.colorPrimary.m_Value.b != BYTE2(pszValue)
    || this->m_fog.colorPrimary.m_Value.a != HIBYTE(pszValue) )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.colorPrimary);
    *p_colorPrimary = (CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorPrimary>)pszValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BBC0
// Name: public: void CFogController::InputSetColorSecondary(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetColorSecondary(CFogController *this, inputdata_t *inputdata)
{
  const char *pszValue; // ebx
  CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorSecondary> *p_colorSecondary; // esi

  pszValue = inputdata->value.iszVal.pszValue;
  p_colorSecondary = &this->m_fog.colorSecondary;
  if ( *(_WORD *)&this->m_fog.colorSecondary.m_Value.r != (_WORD)pszValue
    || this->m_fog.colorSecondary.m_Value.b != BYTE2(pszValue)
    || this->m_fog.colorSecondary.m_Value.a != HIBYTE(pszValue) )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.colorSecondary);
    *p_colorSecondary = (CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorSecondary>)pszValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BC10
// Name: public: void CFogController::InputSetColorLerpTo(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetColorLerpTo(CFogController *this, inputdata_t *data)
{
  const char *pszValue; // ebx
  CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorPrimaryLerpTo> *p_colorPrimaryLerpTo; // esi

  this->m_iChangedVariables |= 1u;
  pszValue = data->value.iszVal.pszValue;
  p_colorPrimaryLerpTo = &this->m_fog.colorPrimaryLerpTo;
  if ( *(_WORD *)&this->m_fog.colorPrimaryLerpTo.m_Value.r != (_WORD)pszValue
    || this->m_fog.colorPrimaryLerpTo.m_Value.b != BYTE2(pszValue)
    || this->m_fog.colorPrimaryLerpTo.m_Value.a != HIBYTE(pszValue) )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.colorPrimaryLerpTo);
    *p_colorPrimaryLerpTo = (CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorPrimaryLerpTo>)pszValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BC70
// Name: public: void CFogController::InputSetColorSecondaryLerpTo(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetColorSecondaryLerpTo(CFogController *this, inputdata_t *data)
{
  const char *pszValue; // ebx
  CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorSecondaryLerpTo> *p_colorSecondaryLerpTo; // esi

  this->m_iChangedVariables |= 2u;
  pszValue = data->value.iszVal.pszValue;
  p_colorSecondaryLerpTo = &this->m_fog.colorSecondaryLerpTo;
  if ( *(_WORD *)&this->m_fog.colorSecondaryLerpTo.m_Value.r != (_WORD)pszValue
    || this->m_fog.colorSecondaryLerpTo.m_Value.b != BYTE2(pszValue)
    || this->m_fog.colorSecondaryLerpTo.m_Value.a != HIBYTE(pszValue) )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.colorSecondaryLerpTo);
    *p_colorSecondaryLerpTo = (CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorSecondaryLerpTo>)pszValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BCD0
// Name: public: struct fogparams_t __near & fogparams_t::operator=(struct fogparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
fogparams_t *__thiscall fogparams_t::operator=(fogparams_t *this, const fogparams_t *__that)
{
  CNetworkVectorBase<Vector,fogparams_t::NetworkVar_dirPrimary> *p_dirPrimary; // edi

  p_dirPrimary = &this->dirPrimary;
  if ( __that->dirPrimary.m_Value.x != this->dirPrimary.m_Value.x
    || __that->dirPrimary.m_Value.y != this->dirPrimary.m_Value.y
    || __that->dirPrimary.m_Value.z != this->dirPrimary.m_Value.z )
  {
    this->NetworkStateChanged(this, a2: &this->dirPrimary);
    *p_dirPrimary = __that->dirPrimary;
  }
  if ( this->colorPrimary.m_Value.r != __that->colorPrimary.m_Value.r
    || this->colorPrimary.m_Value.g != __that->colorPrimary.m_Value.g
    || this->colorPrimary.m_Value.b != __that->colorPrimary.m_Value.b
    || this->colorPrimary.m_Value.a != __that->colorPrimary.m_Value.a )
  {
    this->NetworkStateChanged(this, a2: &this->colorPrimary);
    this->colorPrimary = __that->colorPrimary;
  }
  if ( this->colorSecondary.m_Value.r != __that->colorSecondary.m_Value.r
    || this->colorSecondary.m_Value.g != __that->colorSecondary.m_Value.g
    || this->colorSecondary.m_Value.b != __that->colorSecondary.m_Value.b
    || this->colorSecondary.m_Value.a != __that->colorSecondary.m_Value.a )
  {
    this->NetworkStateChanged(this, a2: &this->colorSecondary);
    this->colorSecondary = __that->colorSecondary;
  }
  if ( this->colorPrimaryLerpTo.m_Value.r != __that->colorPrimaryLerpTo.m_Value.r
    || this->colorPrimaryLerpTo.m_Value.g != __that->colorPrimaryLerpTo.m_Value.g
    || this->colorPrimaryLerpTo.m_Value.b != __that->colorPrimaryLerpTo.m_Value.b
    || this->colorPrimaryLerpTo.m_Value.a != __that->colorPrimaryLerpTo.m_Value.a )
  {
    this->NetworkStateChanged(this, a2: &this->colorPrimaryLerpTo);
    this->colorPrimaryLerpTo = __that->colorPrimaryLerpTo;
  }
  if ( this->colorSecondaryLerpTo.m_Value.r != __that->colorSecondaryLerpTo.m_Value.r
    || this->colorSecondaryLerpTo.m_Value.g != __that->colorSecondaryLerpTo.m_Value.g
    || this->colorSecondaryLerpTo.m_Value.b != __that->colorSecondaryLerpTo.m_Value.b
    || this->colorSecondaryLerpTo.m_Value.a != __that->colorSecondaryLerpTo.m_Value.a )
  {
    this->NetworkStateChanged(this, a2: &this->colorSecondaryLerpTo);
    this->colorSecondaryLerpTo = __that->colorSecondaryLerpTo;
  }
  this->start.m_Value = __that->start.m_Value;
  this->end.m_Value = __that->end.m_Value;
  this->farz.m_Value = __that->farz.m_Value;
  this->maxdensity.m_Value = __that->maxdensity.m_Value;
  this->startLerpTo.m_Value = __that->startLerpTo.m_Value;
  this->endLerpTo.m_Value = __that->endLerpTo.m_Value;
  this->maxdensityLerpTo.m_Value = __that->maxdensityLerpTo.m_Value;
  this->lerptime.m_Value = __that->lerptime.m_Value;
  this->duration.m_Value = __that->duration.m_Value;
  this->enable.m_Value = __that->enable.m_Value;
  this->blend.m_Value = __that->blend.m_Value;
  this->HDRColorScale.m_Value = __that->HDRColorScale.m_Value;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012BE50
// Name: public: void CFogController::InputSetStartDist(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetStartDist(CFogController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,fogparams_t::NetworkVar_start> *p_start; // esi

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_start = &this->m_fog.start;
  if ( this->m_fog.start.m_Value != flVal )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: p_start);
    p_start->m_Value = flVal;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BEA0
// Name: public: void CFogController::InputSetEndDist(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetEndDist(CFogController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,fogparams_t::NetworkVar_end> *p_end; // esi

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_end = &this->m_fog.end;
  if ( this->m_fog.end.m_Value != flVal )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: p_end);
    p_end->m_Value = flVal;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BEF0
// Name: public: void CFogController::InputSetMaxDensity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetMaxDensity(CFogController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,fogparams_t::NetworkVar_maxdensity> *p_maxdensity; // esi

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_maxdensity = &this->m_fog.maxdensity;
  if ( this->m_fog.maxdensity.m_Value != flVal )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: p_maxdensity);
    p_maxdensity->m_Value = flVal;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BF40
// Name: public: void CFogController::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputTurnOn(CFogController *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,fogparams_t::NetworkVar_enable> *p_enable; // esi

  p_enable = &this->m_fog.enable;
  if ( !this->m_fog.enable.m_Value )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: p_enable);
    p_enable->m_Value = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BF70
// Name: public: void CFogController::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputTurnOff(CFogController *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,fogparams_t::NetworkVar_enable> *p_enable; // esi

  p_enable = &this->m_fog.enable;
  if ( this->m_fog.enable.m_Value )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: p_enable);
    p_enable->m_Value = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BFA0
// Name: public: void CFogController::InputSetFarZ(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetFarZ(CFogController *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  CNetworkVarBase<float,fogparams_t::NetworkVar_farz> *p_farz; // esi
  float v4; // xmm0_4

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_farz = &this->m_fog.farz;
  v4 = (float)(int)pszValue;
  if ( this->m_fog.farz.m_Value != (float)(int)pszValue )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: p_farz);
    p_farz->m_Value = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BFF0
// Name: public: void CFogController::InputSetStartDistLerpTo(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetStartDistLerpTo(CFogController *this, inputdata_t *data)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,fogparams_t::NetworkVar_startLerpTo> *p_startLerpTo; // esi

  this->m_iChangedVariables |= 4u;
  if ( data->value.fieldType == FIELD_FLOAT )
    flVal = data->value.flVal;
  else
    flVal = 0.0;
  p_startLerpTo = &this->m_fog.startLerpTo;
  if ( this->m_fog.startLerpTo.m_Value != flVal )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: p_startLerpTo);
    p_startLerpTo->m_Value = flVal;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C050
// Name: public: void CFogController::InputSetEndDistLerpTo(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetEndDistLerpTo(CFogController *this, inputdata_t *data)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,fogparams_t::NetworkVar_endLerpTo> *p_endLerpTo; // esi

  this->m_iChangedVariables |= 8u;
  if ( data->value.fieldType == FIELD_FLOAT )
    flVal = data->value.flVal;
  else
    flVal = 0.0;
  p_endLerpTo = &this->m_fog.endLerpTo;
  if ( this->m_fog.endLerpTo.m_Value != flVal )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: p_endLerpTo);
    p_endLerpTo->m_Value = flVal;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C0B0
// Name: public: void CFogController::InputSetMaxDensityLerpTo(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputSetMaxDensityLerpTo(CFogController *this, inputdata_t *data)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,fogparams_t::NetworkVar_maxdensityLerpTo> *p_maxdensityLerpTo; // esi

  this->m_iChangedVariables |= 0x10u;
  if ( data->value.fieldType == FIELD_FLOAT )
    flVal = data->value.flVal;
  else
    flVal = 0.0;
  p_maxdensityLerpTo = &this->m_fog.maxdensityLerpTo;
  if ( this->m_fog.maxdensityLerpTo.m_Value != flVal )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: p_maxdensityLerpTo);
    p_maxdensityLerpTo->m_Value = flVal;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C110
// Name: public: void CFogController::SetLerpValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::SetLerpValues(CFogController *this)
{
  CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorPrimary> *p_colorPrimary; // edi
  CGlobalVars *v3; // edi
  float m_Value; // xmm0_4
  CNetworkVarBase<float,fogparams_t::NetworkVar_lerptime> *p_lerptime; // esi

  if ( (this->m_iChangedVariables & 1) != 0 )
  {
    p_colorPrimary = &this->m_fog.colorPrimary;
    if ( this->m_fog.colorPrimary.m_Value.r != this->m_fog.colorPrimaryLerpTo.m_Value.r
      || this->m_fog.colorPrimary.m_Value.g != this->m_fog.colorPrimaryLerpTo.m_Value.g
      || this->m_fog.colorPrimary.m_Value.b != this->m_fog.colorPrimaryLerpTo.m_Value.b
      || this->m_fog.colorPrimary.m_Value.a != this->m_fog.colorPrimaryLerpTo.m_Value.a )
    {
      this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.colorPrimary);
      *p_colorPrimary = (CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorPrimary>)this->m_fog.colorPrimaryLerpTo;
    }
  }
  if ( (this->m_iChangedVariables & 2) != 0
    && (this->m_fog.colorSecondary.m_Value.r != this->m_fog.colorSecondaryLerpTo.m_Value.r
     || this->m_fog.colorSecondary.m_Value.g != this->m_fog.colorSecondaryLerpTo.m_Value.g
     || this->m_fog.colorSecondary.m_Value.b != this->m_fog.colorSecondaryLerpTo.m_Value.b
     || this->m_fog.colorSecondary.m_Value.a != this->m_fog.colorSecondaryLerpTo.m_Value.a) )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.colorSecondary);
    this->m_fog.colorSecondary = (CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorSecondary>)this->m_fog.colorSecondaryLerpTo;
  }
  if ( (this->m_iChangedVariables & 4) != 0 && this->m_fog.start.m_Value != this->m_fog.startLerpTo.m_Value )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.start);
    this->m_fog.start.m_Value = this->m_fog.startLerpTo.m_Value;
  }
  if ( (this->m_iChangedVariables & 8) != 0 && this->m_fog.end.m_Value != this->m_fog.endLerpTo.m_Value )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.end);
    this->m_fog.end.m_Value = this->m_fog.endLerpTo.m_Value;
  }
  if ( (this->m_iChangedVariables & 0x10) != 0 && this->m_fog.maxdensity.m_Value != this->m_fog.maxdensityLerpTo.m_Value )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.maxdensity);
    this->m_fog.maxdensity.m_Value = this->m_fog.maxdensityLerpTo.m_Value;
  }
  this->m_iChangedVariables = 0;
  v3 = gpGlobals;
  m_Value = this->m_fog.lerptime.m_Value;
  p_lerptime = &this->m_fog.lerptime;
  if ( m_Value != gpGlobals->curtime )
  {
    (*(void (__thiscall **)(int, CNetworkVarBase<float,fogparams_t::NetworkVar_lerptime> *))LODWORD(p_lerptime[-15].m_Value))(
      a1: (int)&p_lerptime[-15],
      a2: p_lerptime);
    p_lerptime->m_Value = v3->curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C2A0
// Name: bool GetWorldFogParams(class CBaseCombatCharacter __near *,struct fogparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetWorldFogParams(CBaseCombatCharacter *character, fogparams_t *fog)
{
  CBaseEntity *FogTrigger; // eax
  char *v3; // eax
  fogparams_t *v4; // esi
  IHandleEntity *m_pEntity; // eax
  float m_Value; // xmm1_4

  if ( character != nullptr
    && CBaseCombatCharacter::GetFogTrigger(this: character) != nullptr
    && (FogTrigger = CBaseCombatCharacter::GetFogTrigger(this: character),
        (v3 = (char *)__RTDynamicCast(
                        inptr: FogTrigger,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CFogTrigger `RTTI Type Descriptor',
                        isReference: 0)) != nullptr)
    && (v4 = (fogparams_t *)(v3 + 1152), v3 != (char *)-1152)
    || s_FogSystem.m_hMasterController.m_Index != -1
    && g_pEntityList->m_EntPtrArray[LOWORD(s_FogSystem.m_hMasterController.m_Index)].m_SerialNumber == HIWORD(s_FogSystem.m_hMasterController.m_Index)
    && g_pEntityList->m_EntPtrArray[LOWORD(s_FogSystem.m_hMasterController.m_Index)].m_pEntity != nullptr
    && (g_pEntityList->m_EntPtrArray[LOWORD(s_FogSystem.m_hMasterController.m_Index)].m_SerialNumber != HIWORD(s_FogSystem.m_hMasterController.m_Index)
      ? (m_pEntity = nullptr)
      : (m_pEntity = g_pEntityList->m_EntPtrArray[LOWORD(s_FogSystem.m_hMasterController.m_Index)].m_pEntity),
        v4 = (fogparams_t *)&m_pEntity[213],
        m_pEntity != (IHandleEntity *)-852) )
  {
    if ( fogparams_t::operator!=(this: v4, other: fog) )
    {
      fogparams_t::operator=(this: fog, __that: v4);
      return 1;
    }
    return 0;
  }
  m_Value = fog->farz.m_Value;
  if ( m_Value == -1.0 && !fog->enable.m_Value )
    return 0;
  if ( m_Value != -1.0 )
  {
    fog->NetworkStateChanged(this: fog, a2: &fog->farz);
    fog->farz.m_Value = -1.0;
  }
  if ( fog->enable.m_Value )
  {
    fog->NetworkStateChanged(this: fog, a2: &fog->enable);
    fog->enable.m_Value = false;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012C3E0
// Name: public: void CFogController::InputStartFogTransition(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogController::InputStartFogTransition(CFogController *this, inputdata_t *data)
{
  float v3; // xmm0_4

  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CFogController::SetLerpValues,
    thinkTime: 0.0,
    szContext: nullptr);
  v3 = (float)(gpGlobals->curtime + this->m_fog.duration.m_Value) + 0.1;
  if ( this->m_fog.lerptime.m_Value != v3 )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.lerptime);
    this->m_fog.lerptime.m_Value = v3;
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + this->m_fog.duration.m_Value, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1012C480
// Name: public: virtual void CFogTrigger::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogTrigger::Spawn(CFogTrigger *this)
{
  int v2; // edi
  edict_t *m_pPev; // ecx

  v2 = this->m_spawnflags.m_Value | 0x40;
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
  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
}

//------------------------------------------------------------------------------
// Address: 0x1012C8E0
// Name: public: CFogController::CFogController(void)
// Source: json
//------------------------------------------------------------------------------
CFogController *__thiscall CFogController::CFogController(CFogController *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CFogController_vtbl *)&CFogController::`vftable';
  this->m_fog.__vftable = (CFogController::NetworkVar_m_fog_vtbl *)&CFogController::NetworkVar_m_fog::`vftable';
  if ( this->m_fog.enable.m_Value )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.enable);
    this->m_fog.enable.m_Value = false;
  }
  if ( this->m_fog.maxdensity.m_Value != 1.0 )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.maxdensity);
    this->m_fog.maxdensity.m_Value = 1.0;
  }
  if ( this->m_fog.HDRColorScale.m_Value != 1.0 )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.HDRColorScale);
    this->m_fog.HDRColorScale.m_Value = 1.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10403650
// Name: CFogController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFogController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFogController>(__formal: nullptr);
  CFogController_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403680
// Name: DT_FogController::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FogController::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FogController::g_SendTable);
  return atexit(func: DT_FogController::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104036A0
// Name: DT_FogController::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FogController::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FogController::ignored>();
  DT_FogController::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104036D0
// Name: CFogTrigger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFogTrigger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFogTrigger>(__formal: nullptr);
  CFogTrigger_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B3F0
// Name: DT_FogController::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FogController::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FogController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1012C4D0
// Name: struct datamap_t __near * DataMapInit<class CFogController>(class CFogController __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFogController>()
{
  if ( (_S2_107 & 1) == 0 )
  {
    _S2_107 |= 1u;
    nameHolder_204.m_pszBase = "CFogController";
    nameHolder_204.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_204.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_204.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_204.m_Names.m_Size = 0;
    nameHolder_204.m_Names.m_pElements = nullptr;
    nameHolder_204.m_nLenBase = 14;
    atexit(func: DataMapInit_CFogController__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFogController::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_107 & 2) == 0 )
  {
    _S2_107 |= 2u;
    dataDesc_194[28].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_204,
                                   pszIdentifier: "SetLerpValues");
    dataDesc_194[28].flags = 32;
    dataDesc_194[29].fieldSize = 1;
    dataDesc_194[28].fieldSize = 1;
    dataDesc_194[30].fieldSize = 1;
    dataDesc_194[30].flags = 2;
    *(_QWORD *)dataDesc_194[29].flatOffset = 0;
    dataDesc_194[29].flags = 2;
    dataDesc_194[31].fieldType = FIELD_COLOR32;
    dataDesc_194[31].fieldSize = 1;
    dataDesc_194[32].fieldType = FIELD_COLOR32;
    *(_QWORD *)&dataDesc_194[28].td = 0;
    *(_QWORD *)&dataDesc_194[28].override_field = 0;
    *(_QWORD *)&dataDesc_194[28].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_194[28].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_194[30].flatOffset = 0;
    dataDesc_194[28].fieldOffset = 0;
    dataDesc_194[28].externalName = nullptr;
    dataDesc_194[28].pSaveRestoreOps = nullptr;
    dataDesc_194[28].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFogController::SetLerpValues;
    dataDesc_194[29].fieldType = FIELD_INTEGER;
    dataDesc_194[29].fieldName = "m_iChangedVariables";
    dataDesc_194[29].fieldOffset = 932;
    dataDesc_194[29].externalName = nullptr;
    dataDesc_194[29].pSaveRestoreOps = nullptr;
    dataDesc_194[29].inputFunc = nullptr;
    dataDesc_194[29].td = nullptr;
    dataDesc_194[29].fieldSizeInBytes = 4;
    dataDesc_194[29].override_field = nullptr;
    dataDesc_194[29].override_count = 0;
    dataDesc_194[29].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_194[29].flatGroup = 0;
    dataDesc_194[30].fieldType = FIELD_TIME;
    dataDesc_194[30].fieldName = "m_fog.lerptime";
    dataDesc_194[30].fieldOffset = 912;
    dataDesc_194[30].externalName = nullptr;
    dataDesc_194[30].pSaveRestoreOps = nullptr;
    dataDesc_194[30].inputFunc = nullptr;
    dataDesc_194[30].td = nullptr;
    dataDesc_194[30].fieldSizeInBytes = 4;
    dataDesc_194[30].override_field = nullptr;
    dataDesc_194[30].override_count = 0;
    dataDesc_194[30].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_194[30].flatGroup = 0;
    dataDesc_194[31].fieldName = "m_fog.colorPrimaryLerpTo";
    dataDesc_194[31].fieldOffset = 876;
    dataDesc_194[31].flags = 2;
    dataDesc_194[31].externalName = nullptr;
    dataDesc_194[31].pSaveRestoreOps = nullptr;
    dataDesc_194[31].inputFunc = nullptr;
    dataDesc_194[31].td = nullptr;
    dataDesc_194[31].fieldSizeInBytes = 4;
    dataDesc_194[31].override_field = nullptr;
    dataDesc_194[31].override_count = 0;
    dataDesc_194[31].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_194[31].flatOffset = 0;
    *(_DWORD *)&dataDesc_194[31].flatGroup = 0;
    dataDesc_194[32].fieldName = "m_fog.colorSecondaryLerpTo";
    dataDesc_194[32].fieldOffset = 880;
    *(_DWORD *)&dataDesc_194[32].fieldSize = 131073;
    *(_QWORD *)dataDesc_194[32].flatOffset = 0;
    dataDesc_194[32].fieldTolerance = 0.0;
    dataDesc_194[33].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_194[33].flatOffset = 0;
    dataDesc_194[34].fieldTolerance = 0.0;
    dataDesc_194[35].fieldTolerance = 0.0;
    dataDesc_194[32].externalName = nullptr;
    dataDesc_194[32].pSaveRestoreOps = nullptr;
    dataDesc_194[32].inputFunc = nullptr;
    dataDesc_194[32].td = nullptr;
    dataDesc_194[32].fieldSizeInBytes = 4;
    dataDesc_194[32].override_field = nullptr;
    dataDesc_194[32].override_count = 0;
    *(_DWORD *)&dataDesc_194[32].flatGroup = 0;
    dataDesc_194[33].fieldType = FIELD_FLOAT;
    dataDesc_194[33].fieldName = "m_fog.startLerpTo";
    dataDesc_194[33].fieldOffset = 900;
    *(_DWORD *)&dataDesc_194[33].fieldSize = 131073;
    dataDesc_194[33].externalName = nullptr;
    dataDesc_194[33].pSaveRestoreOps = nullptr;
    dataDesc_194[33].inputFunc = nullptr;
    dataDesc_194[33].td = nullptr;
    dataDesc_194[33].fieldSizeInBytes = 4;
    dataDesc_194[33].override_field = nullptr;
    dataDesc_194[33].override_count = 0;
    *(_DWORD *)&dataDesc_194[33].flatGroup = 0;
    dataDesc_194[34].fieldType = FIELD_FLOAT;
    dataDesc_194[34].fieldName = "m_fog.endLerpTo";
    dataDesc_194[34].fieldOffset = 904;
    *(_DWORD *)&dataDesc_194[34].fieldSize = 131073;
    dataDesc_194[34].externalName = nullptr;
    dataDesc_194[34].pSaveRestoreOps = nullptr;
    dataDesc_194[34].inputFunc = nullptr;
    dataDesc_194[34].td = nullptr;
    dataDesc_194[34].fieldSizeInBytes = 4;
    dataDesc_194[34].override_field = nullptr;
    dataDesc_194[34].override_count = 0;
    *(_QWORD *)dataDesc_194[34].flatOffset = 0;
    *(_DWORD *)&dataDesc_194[34].flatGroup = 0;
    dataDesc_194[35].fieldType = FIELD_FLOAT;
    dataDesc_194[35].fieldName = "m_fog.maxdensityLerpTo";
    dataDesc_194[35].fieldOffset = 908;
    *(_DWORD *)&dataDesc_194[35].fieldSize = 131073;
    dataDesc_194[35].externalName = nullptr;
    dataDesc_194[35].pSaveRestoreOps = nullptr;
    dataDesc_194[35].inputFunc = nullptr;
    dataDesc_194[35].td = nullptr;
    dataDesc_194[35].fieldSizeInBytes = 4;
    dataDesc_194[35].override_field = nullptr;
    dataDesc_194[35].override_count = 0;
    *(_QWORD *)dataDesc_194[35].flatOffset = 0;
    *(_DWORD *)&dataDesc_194[35].flatGroup = 0;
  }
  CFogController::m_DataMap.dataNumFields = 35;
  CFogController::m_DataMap.dataDesc = &dataDesc_194[1];
  return &CFogController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012C980
// Name: struct datamap_t __near * DataMapInit<class CFogTrigger>(class CFogTrigger __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFogTrigger>()
{
  if ( (_S4_33 & 1) == 0 )
  {
    _S4_33 |= 1u;
    nameHolder_205.m_pszBase = "CFogTrigger";
    nameHolder_205.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_205.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_205.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_205.m_Names.m_Size = 0;
    nameHolder_205.m_Names.m_pElements = nullptr;
    nameHolder_205.m_nLenBase = 11;
    atexit(func: DataMapInit_CFogTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFogTrigger::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  CFogTrigger::m_DataMap.dataNumFields = 8;
  CFogTrigger::m_DataMap.dataDesc = &dataDesc_195[1];
  return &CFogTrigger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10403660
// Name: _dynamic_initializer_for__g_CFogController_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFogController_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFogController_ClassReg,
           pNetworkName: "CFogController",
           pTable: &DT_FogController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104036E0
// Name: _dynamic_initializer_for__TheFogVolumes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__TheFogVolumes__()
{
  return atexit(func: dynamic_atexit_destructor_for__TheFogVolumes__);
}

//------------------------------------------------------------------------------
// Address: 0x104036F0
// Name: _dynamic_initializer_for__fog_volume_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_volume_debug__()
{
  ConVar::ConVar(
    this: &fog_volume_debug,
    pName: "fog_volume_debug",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If enabled, prints diagnostic information about the current fog volume");
  return atexit(func: dynamic_atexit_destructor_for__fog_volume_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10403720
// Name: _dynamic_initializer_for__fog_volume__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_volume__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFogVolume> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &fog_volume,
           a3: "fog_volume");
}

//------------------------------------------------------------------------------
// Address: 0x1041B400
// Name: _ServerClassInit_DT_FogController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FogController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_60;
  for ( i = 17; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B420
// Name: _dynamic_atexit_destructor_for__s_FogSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_FogSystem__()
{
  s_FogSystem.CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CFogSystem_vtbl *)&CFogSystem::`vftable'{for `CAutoGameSystem'};
  s_FogSystem.m_hMasterController.m_Index = -1;
  s_FogSystem.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  s_FogSystem.m_nDebugID = 13;
  if ( s_FogSystem.m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &s_FogSystem.CGameEventListener);
    s_FogSystem.m_bRegisteredForEvents = false;
  }
  s_FogSystem.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  IGameSystem::~IGameSystem(this: &s_FogSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041B490
// Name: _DataMapInit_CFogController__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFogController__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_204);
}

//------------------------------------------------------------------------------
// Address: 0x1041B4A0
// Name: _DataMapInit_CFogTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFogTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_205);
}

//------------------------------------------------------------------------------
// Address: 0x1041B4B0
// Name: _dynamic_atexit_destructor_for__fog_volume_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_volume_debug__()
{
  ConVar::~ConVar(this: &fog_volume_debug);
}

//------------------------------------------------------------------------------
// Address: 0x1041B4C0
// Name: _dynamic_atexit_destructor_for__TheFogVolumes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__TheFogVolumes__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&TheFogVolumes);
}

//------------------------------------------------------------------------------
// Address: 0x1041B4D0
// Name: _DataMapInit_CFogVolume__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFogVolume__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_206);
}
