// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_tonemap_controller.cpp
// Functions: 48
// ============================================================

#include "game\server\env_tonemap_controller.h"

//------------------------------------------------------------------------------
// Address: 0x10118B90
// Name: public: virtual struct datamap_t __near * CEnvTonemapController::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvTonemapController::GetDataDescMap(CEnvTonemapController *this)
{
  return &CEnvTonemapController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10118BA0
// Name: public: virtual class ServerClass __near * CEnvTonemapController::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEnvTonemapController::GetServerClass(CEnvTonemapController *this)
{
  return &g_CEnvTonemapController_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10118BB0
// Name: public: virtual struct datamap_t __near * CTonemapTrigger::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTonemapTrigger::GetDataDescMap(CTonemapTrigger *this)
{
  return &CTonemapTrigger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10118BC0
// Name: class CTonemapSystem __near * TheTonemapSystem(void)
// Source: json
//------------------------------------------------------------------------------
CTonemapSystem *__cdecl TheTonemapSystem()
{
  return &s_TonemapSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10118BD0
// Name: public: void CEnvTonemapController::InputSetTonemapScale(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetTonemapScale(CEnvTonemapController *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    ConVar::SetValue(this: (ConVar *)&mat_hdr_tonemapscale.IConVar, value: inputdata->value.flVal);
  else
    ConVar::SetValue(this: (ConVar *)&mat_hdr_tonemapscale.IConVar, value: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10118C10
// Name: public: void CEnvTonemapController::InputSetTonemapRate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetTonemapRate(CEnvTonemapController *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  ConVarRef mat_hdr_manual_tonemap_rate; // [esp+4h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &mat_hdr_manual_tonemap_rate, pName: "mat_hdr_manual_tonemap_rate");
  if ( ConVarRef::IsValid(this: &mat_hdr_manual_tonemap_rate) )
  {
    if ( inputdata->value.fieldType == FIELD_FLOAT )
      pszValue = inputdata->value.iszVal.pszValue;
    else
      pszValue = nullptr;
    ((void (__stdcall *)(const char *))mat_hdr_manual_tonemap_rate.m_pConVar->SetValue_3)(a1: pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118C60
// Name: public: virtual void CTonemapTrigger::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTonemapTrigger::StartTouch(CTonemapTrigger *this, CBasePlayer *other)
{
  if ( this->PassesTriggerFilters(this, a2: other) )
  {
    CBaseTrigger::StartTouch(this, pOther: other);
    if ( other != nullptr && other->IsPlayer(this: other) )
      CBasePlayer::OnTonemapTriggerStartTouch(this: other, pTonemapTrigger: (unsigned int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118CB0
// Name: public: virtual void CTonemapTrigger::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTonemapTrigger::EndTouch(CTonemapTrigger *this, CBasePlayer *other)
{
  if ( this->PassesTriggerFilters(this, a2: other) )
  {
    CBaseTrigger::EndTouch(this, pOther: other);
    if ( other != nullptr && other->IsPlayer(this: other) )
      CBasePlayer::OnTonemapTriggerEndTouch(this: other, pTonemapTrigger: (unsigned int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118D00
// Name: public: virtual void CTonemapSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTonemapSystem::LevelInitPreEntity(CTonemapSystem *this)
{
  this->m_hMasterController.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10118D20
// Name: float RemapValClamped(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapValClamped(float val, float A, float B, float C, float D)
{
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( A == B )
  {
    if ( (float)(val - B) < 0.0 )
      return C;
    else
      return D;
  }
  else
  {
    v6 = (float)(val - A) / (float)(B - A);
    v7 = 0.0;
    if ( v6 < 0.0 )
      return C + (D - C) * v7;
    v7 = 1.0;
    if ( v6 > 1.0 )
      return C + (D - C) * v7;
    else
      return C + (D - C) * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119120
// Name: public: void CEnvTonemapController::UpdateTonemapScaleBlend(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::UpdateTonemapScaleBlend(CEnvTonemapController *this)
{
  float curtime; // xmm0_4
  float m_flBlendStartTime; // xmm2_4
  float m_flBlendEndTime; // xmm1_4
  float value; // xmm3_4
  float v6; // xmm0_4
  int v7; // xmm1_4
  float v8; // xmm0_4

  curtime = gpGlobals->curtime;
  m_flBlendStartTime = this->m_flBlendStartTime;
  m_flBlendEndTime = this->m_flBlendEndTime;
  value = this->m_flBlendTonemapEnd;
  if ( m_flBlendStartTime == m_flBlendEndTime )
  {
    if ( (float)(curtime - m_flBlendEndTime) < 0.0 )
      value = this->m_flBlendTonemapStart;
  }
  else
  {
    v6 = (float)(curtime - m_flBlendStartTime) / (float)(m_flBlendEndTime - m_flBlendStartTime);
    v7 = 0;
    if ( v6 < 0.0 || (v7 = 1065353216, v6 > 1.0) )
      v6 = *(float *)&v7;
    value = (float)((float)(value - this->m_flBlendTonemapStart) * v6) + this->m_flBlendTonemapStart;
  }
  ConVar::SetValue(this: (ConVar *)&mat_hdr_tonemapscale.IConVar, value);
  v8 = gpGlobals->curtime;
  if ( v8 < this->m_flBlendEndTime )
    CBaseEntity::SetNextThink(this, thinkTime: v8 + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101191E0
// Name: public: virtual void CTonemapSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTonemapSystem::LevelInitPostEntity(CTonemapSystem *this)
{
  CBaseEntity *EntityByClassname; // esi
  unsigned int m_Index; // eax

  EntityByClassname = nullptr;
  while ( 1 )
  {
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: EntityByClassname,
                          szName: "env_tonemap_controller");
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
// Address: 0x10119260
// Name: public: void CEnvTonemapController::InputBlendTonemapScale(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputBlendTonemapScale(CEnvTonemapController *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *pszValue; // edi
  const char *DebugName; // eax
  const char *v9; // edi
  const char *v10; // eax
  float thinkTime; // [esp+0h] [ebp-110h]
  char parseString[256]; // [esp+10h] [ebp-100h] BYREF

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
  V_strncpy(pDest: parseString, pSrc: iVal, maxLen: 255);
  v5 = strtok(string: parseString, control: " ");
  if ( v5 != nullptr && *v5 != 0 )
  {
    this->m_flBlendTonemapEnd = atof(nptr: v5);
    v6 = strtok(string: nullptr, control: " ");
    if ( v6 != nullptr && *v6 != 0 )
    {
      this->m_flBlendEndTime = atof(nptr: v6) + gpGlobals->curtime;
      this->m_flBlendStartTime = gpGlobals->curtime;
      this->m_flBlendTonemapStart = mat_hdr_tonemapscale.m_pParent->m_Value.m_fValue;
      thinkTime = gpGlobals->curtime + 0.1;
      CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CEnvTonemapController::UpdateTonemapScaleBlend,
        thinkTime: 0.0,
        szContext: nullptr);
    }
    else
    {
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      DebugName = CBaseEntity::GetDebugName(this);
      _Warning(
        a1: "%s (%s) received BlendTonemapScale input without a blend time. Syntax: <target tonemap scale> <blend time>\n",
        pszValue,
        DebugName);
    }
  }
  else
  {
    v9 = this->m_iClassname.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
    v10 = CBaseEntity::GetDebugName(this);
    _Warning(
      a1: "%s (%s) received BlendTonemapScale input without a target tonemap scale. Syntax: <target tonemap scale> <blend time>\n",
      v9,
      v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101193D0
// Name: public: CEnvTonemapController::CEnvTonemapController(void)
// Source: json
//------------------------------------------------------------------------------
CEnvTonemapController *__thiscall CEnvTonemapController::CEnvTonemapController(CEnvTonemapController *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  CEnvTonemapController *result; // eax
  edict_t *v7; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CEnvTonemapController_vtbl *)&CEnvTonemapController::`vftable';
  if ( this->m_flBloomExponent.m_Value != 2.5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
    }
    this->m_flBloomExponent.m_Value = 2.5;
  }
  if ( this->m_flBloomSaturation.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flBloomSaturation.m_Value = 1.0;
  }
  if ( this->m_flTonemapPercentTarget.m_Value != 65.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x380u);
    }
    this->m_flTonemapPercentTarget.m_Value = 65.0;
  }
  if ( this->m_flTonemapPercentBrightPixels.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x384u);
    }
    this->m_flTonemapPercentBrightPixels.m_Value = 2.0;
  }
  result = this;
  if ( this->m_flTonemapMinAvgLum.m_Value != 3.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x388u);
    }
    this->m_flTonemapMinAvgLum.m_Value = 3.0;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10119550
// Name: public: void CEnvTonemapController::InputSetBloomScaleRange(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetBloomScaleRange(CEnvTonemapController *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  const char *pszValue; // edi
  const char *DebugName; // eax
  edict_t *m_pPev; // ecx
  edict_t *v8; // ecx

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
  if ( sscanf(string: "%f %f", format: iVal, 0, 1072693248, 0, 1072693248) == 2 )
  {
    if ( this->m_flCustomBloomScale.m_Value != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
      }
      this->m_flCustomBloomScale.m_Value = 1.0;
    }
    if ( this->m_flCustomBloomScale.m_Value != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flCustomBloomScale.m_Value = 1.0;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x370u);
        this->m_flCustomBloomScale.m_Value = 1.0;
      }
    }
  }
  else
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(
      a1: "%s (%s) received SetBloomScaleRange input without 2 arguments. Syntax: <max bloom> <min bloom>\n",
      pszValue,
      DebugName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119670
// Name: public: void CEnvTonemapController::InputSetAutoExposureMin(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetAutoExposureMin(CEnvTonemapController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  if ( this->m_flCustomAutoExposureMin.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x368u);
    }
    this->m_flCustomAutoExposureMin.m_Value = flVal;
  }
  if ( !this->m_bUseCustomAutoExposureMin.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bUseCustomAutoExposureMin.m_Value = true;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x364u);
      this->m_bUseCustomAutoExposureMin.m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119720
// Name: public: void CEnvTonemapController::InputSetAutoExposureMax(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetAutoExposureMax(CEnvTonemapController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  if ( this->m_flCustomAutoExposureMax.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
    }
    this->m_flCustomAutoExposureMax.m_Value = flVal;
  }
  if ( !this->m_bUseCustomAutoExposureMax.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bUseCustomAutoExposureMax.m_Value = true;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x365u);
      this->m_bUseCustomAutoExposureMax.m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101197D0
// Name: public: void CEnvTonemapController::InputUseDefaultAutoExposure(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputUseDefaultAutoExposure(CEnvTonemapController *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx

  if ( this->m_bUseCustomAutoExposureMin.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x364u);
    }
    this->m_bUseCustomAutoExposureMin.m_Value = false;
  }
  if ( this->m_bUseCustomAutoExposureMax.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bUseCustomAutoExposureMax.m_Value = false;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x365u);
      this->m_bUseCustomAutoExposureMax.m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119850
// Name: public: void CEnvTonemapController::InputSetBloomScale(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetBloomScale(CEnvTonemapController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  if ( this->m_flCustomBloomScale.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
    }
    this->m_flCustomBloomScale.m_Value = flVal;
  }
  if ( this->m_flCustomBloomScaleMinimum.m_Value != this->m_flCustomBloomScale.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x374u);
    }
    this->m_flCustomBloomScaleMinimum.m_Value = this->m_flCustomBloomScale.m_Value;
  }
  if ( !this->m_bUseCustomBloomScale.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bUseCustomBloomScale.m_Value = true;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x366u);
      this->m_bUseCustomBloomScale.m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119940
// Name: public: void CEnvTonemapController::InputUseDefaultBloomScale(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputUseDefaultBloomScale(CEnvTonemapController *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CEnvTonemapController::NetworkVar_m_bUseCustomBloomScale> *p_m_bUseCustomBloomScale; // esi
  edict_t *m_pPev; // ecx

  p_m_bUseCustomBloomScale = &this->m_bUseCustomBloomScale;
  if ( this->m_bUseCustomBloomScale.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bUseCustomBloomScale->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x366u);
      p_m_bUseCustomBloomScale->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119990
// Name: public: void CEnvTonemapController::InputSetBloomExponent(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetBloomExponent(CEnvTonemapController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvTonemapController::NetworkVar_m_flBloomExponent> *p_m_flBloomExponent; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flBloomExponent = &this->m_flBloomExponent;
  if ( this->m_flBloomExponent.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flBloomExponent->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
      p_m_flBloomExponent->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119A10
// Name: public: void CEnvTonemapController::InputSetBloomSaturation(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetBloomSaturation(CEnvTonemapController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvTonemapController::NetworkVar_m_flBloomSaturation> *p_m_flBloomSaturation; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flBloomSaturation = &this->m_flBloomSaturation;
  if ( this->m_flBloomSaturation.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flBloomSaturation->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
      p_m_flBloomSaturation->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119A90
// Name: public: void CEnvTonemapController::InputSetTonemapPercentTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetTonemapPercentTarget(
        CEnvTonemapController *this,
        inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvTonemapController::NetworkVar_m_flTonemapPercentTarget> *p_m_flTonemapPercentTarget; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flTonemapPercentTarget = &this->m_flTonemapPercentTarget;
  if ( this->m_flTonemapPercentTarget.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flTonemapPercentTarget->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x380u);
      p_m_flTonemapPercentTarget->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119B10
// Name: public: void CEnvTonemapController::InputSetTonemapPercentBrightPixels(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetTonemapPercentBrightPixels(
        CEnvTonemapController *this,
        inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvTonemapController::NetworkVar_m_flTonemapPercentBrightPixels> *p_m_flTonemapPercentBrightPixels; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flTonemapPercentBrightPixels = &this->m_flTonemapPercentBrightPixels;
  if ( this->m_flTonemapPercentBrightPixels.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flTonemapPercentBrightPixels->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x384u);
      p_m_flTonemapPercentBrightPixels->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119B90
// Name: public: void CEnvTonemapController::InputSetTonemapMinAvgLum(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTonemapController::InputSetTonemapMinAvgLum(CEnvTonemapController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvTonemapController::NetworkVar_m_flTonemapMinAvgLum> *p_m_flTonemapMinAvgLum; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flTonemapMinAvgLum = &this->m_flTonemapMinAvgLum;
  if ( this->m_flTonemapMinAvgLum.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flTonemapMinAvgLum->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x388u);
      p_m_flTonemapMinAvgLum->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119C10
// Name: public: virtual void CTonemapTrigger::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTonemapTrigger::Spawn(CTonemapTrigger *this)
{
  int v2; // esi
  edict_t *m_pPev; // ecx
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax

  v2 = this->m_spawnflags.m_Value | 1;
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
  pszValue = this->m_tonemapControllerName.pszValue;
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
    this->m_hTonemapController.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hTonemapController.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10402B20
// Name: CEnvTonemapController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvTonemapController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvTonemapController>();
  CEnvTonemapController_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402B50
// Name: DT_EnvTonemapController::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvTonemapController::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EnvTonemapController::g_SendTable);
  return atexit(func: DT_EnvTonemapController::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10402B70
// Name: DT_EnvTonemapController::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvTonemapController::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EnvTonemapController::ignored>();
  DT_EnvTonemapController::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402BA0
// Name: CTonemapTrigger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTonemapTrigger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTonemapTrigger>();
  CTonemapTrigger_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041AF90
// Name: DT_EnvTonemapController::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvTonemapController::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EnvTonemapController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10402B30
// Name: _dynamic_initializer_for__g_CEnvTonemapController_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEnvTonemapController_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEnvTonemapController_ClassReg,
           pNetworkName: "CEnvTonemapController",
           pTable: &DT_EnvTonemapController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10402BB0
// Name: _dynamic_initializer_for__s_TonemapSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_TonemapSystem__()
{
  CAutoGameSystem::CAutoGameSystem(this: &s_TonemapSystem, name: "TonemapSystem");
  s_TonemapSystem.__vftable = (CTonemapSystem_vtbl *)&CTonemapSystem::`vftable';
  s_TonemapSystem.m_hMasterController.m_Index = -1;
  return atexit(func: dynamic_atexit_destructor_for__s_TonemapSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10402BE0
// Name: _dynamic_initializer_for__s_windControllers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_windControllers__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_windControllers__);
}

//------------------------------------------------------------------------------
// Address: 0x10402BF0
// Name: _dynamic_initializer_for__env_zoom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_zoom__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvZoom> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_zoom,
           a3: "env_zoom");
}

//------------------------------------------------------------------------------
// Address: 0x1041AFA0
// Name: _ServerClassInit_DT_EnvTonemapController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EnvTonemapController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_53;
  for ( i = 13; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041AFC0
// Name: _dynamic_atexit_destructor_for__s_TonemapSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_TonemapSystem__()
{
  s_TonemapSystem.__vftable = (CTonemapSystem_vtbl *)&CTonemapSystem::`vftable';
  s_TonemapSystem.m_hMasterController.m_Index = -1;
  IGameSystem::~IGameSystem(this: &s_TonemapSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041AFE0
// Name: _DataMapInit_CEnvTonemapController__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvTonemapController__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_170);
}

//------------------------------------------------------------------------------
// Address: 0x1041AFF0
// Name: _DataMapInit_CTonemapTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTonemapTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_171);
}

//------------------------------------------------------------------------------
// Address: 0x1041B000
// Name: _dynamic_atexit_destructor_for__s_windControllers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_windControllers__()
{
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&s_windControllers);
  if ( s_windControllers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_windControllers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_windControllers.m_Memory.m_pMemory);
      s_windControllers.m_Memory.m_pMemory = nullptr;
    }
    s_windControllers.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041B050
// Name: _DataMapInit_CEnvZoom__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvZoom__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_172);
}

//------------------------------------------------------------------------------
// Address: 0x1041B060
// Name: _DataMapInit_CEnvBeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvBeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_173);
}

//------------------------------------------------------------------------------
// Address: 0x1041B070
// Name: _dynamic_atexit_destructor_for__fadeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fadeout__()
{
  ConCommand::~ConCommand(this: &fadeout);
}

//------------------------------------------------------------------------------
// Address: 0x1041B080
// Name: _dynamic_atexit_destructor_for__fadein__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fadein__()
{
  ConCommand::~ConCommand(this: &fadein);
}

//------------------------------------------------------------------------------
// Address: 0x1041B090
// Name: _DataMapInit_CEnvFade__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvFade__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_174);
}

//------------------------------------------------------------------------------
// Address: 0x1041B0A0
// Name: _DataMapInit_CEnvHudHint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvHudHint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_175);
}

//------------------------------------------------------------------------------
// Address: 0x1041B0B0
// Name: _DataMapInit_CEnvLaser__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvLaser__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_176);
}

//------------------------------------------------------------------------------
// Address: 0x1041B0C0
// Name: _dynamic_atexit_destructor_for__creditsdone__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__creditsdone__()
{
  ConCommand::~ConCommand(this: &creditsdone);
}
