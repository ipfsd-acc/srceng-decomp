// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/lights.cpp
// Functions: 16
// ============================================================

#include "game\server\lights.h"

//------------------------------------------------------------------------------
// Address: 0x10164B90
// Name: public: virtual struct datamap_t __near * CLight::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLight::GetDataDescMap(CLight *this)
{
  return &CLight::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10164BA0
// Name: public: virtual bool CLight::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLight::KeyValue(CLight *this, const char *szKeyName, const char *szValue)
{
  float z; // ecx
  QAngle angles; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( szKeyName != "pitch" && _V_stricmp(s1: szKeyName, s2: "pitch") != 0 )
    return CServerOnlyPointEntity::KeyValue((CLogicalEntity *)this, szKeyName, szValue);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_angAbsRotation.z;
  *(_QWORD *)&angles.x = *(_QWORD *)&this->m_angAbsRotation.x;
  angles.z = z;
  angles.x = atof(nptr: szValue);
  CBaseEntity::SetAbsAngles(this, absAngles: &angles);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10164C30
// Name: public: void CLight::FadeThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLight::FadeThink(CLight *this)
{
  char m_iCurrentFade; // al
  char m_iTargetFade; // cl
  char v4; // al
  const char *pszValue; // eax
  int m_iStyle; // edx
  char sCurString[4]; // [esp+14h] [ebp-4h] BYREF

  m_iCurrentFade = this->m_iCurrentFade;
  m_iTargetFade = this->m_iTargetFade;
  if ( m_iCurrentFade >= m_iTargetFade )
  {
    if ( m_iCurrentFade <= m_iTargetFade )
      goto LABEL_6;
    v4 = m_iCurrentFade - 1;
  }
  else
  {
    v4 = m_iCurrentFade + 1;
  }
  this->m_iCurrentFade = v4;
LABEL_6:
  if ( this->m_iCurrentFade == m_iTargetFade )
  {
    pszValue = this->m_iszPattern.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    engine->LightStyle(this: engine, a2: this->m_iStyle, a3: pszValue);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
  else
  {
    sCurString[0] = this->m_iCurrentFade;
    m_iStyle = this->m_iStyle;
    sCurString[1] = 0;
    engine->LightStyle(this: engine, a2: m_iStyle, a3: sCurString);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164CF0
// Name: public: virtual bool CEnvLight::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEnvLight::KeyValue(CEnvLight *this, const char *szKeyName, const char *szValue)
{
  return szKeyName == "_light"
      || _V_stricmp(s1: szKeyName, s2: "_light") == 0
      || CLight::KeyValue(this, szKeyName, szValue);
}

//------------------------------------------------------------------------------
// Address: 0x10164D30
// Name: public: virtual void CLight::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLight::Spawn(CLight *this)
{
  const char *DefaultLightstyleString; // eax
  const char *pszValue; // eax

  if ( this->m_iName.m_Value.pszValue != nullptr )
  {
    if ( this->m_iStyle >= 32 )
    {
      if ( this->m_iszPattern.pszValue == nullptr && this->m_iDefaultStyle > 0 )
      {
        DefaultLightstyleString = GetDefaultLightstyleString(styleIndex: this->m_iDefaultStyle);
        if ( DefaultLightstyleString == nullptr || *DefaultLightstyleString == 0 )
          DefaultLightstyleString = nullptr;
        this->m_iszPattern.pszValue = DefaultLightstyleString;
      }
      if ( (this->m_spawnflags.m_Value & 1) != 0 )
      {
        engine->LightStyle(this: engine, a2: this->m_iStyle, a3: "a");
      }
      else if ( this->m_iszPattern.pszValue != nullptr )
      {
        pszValue = this->m_iszPattern.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        engine->LightStyle(this: engine, a2: this->m_iStyle, a3: pszValue);
      }
      else
      {
        engine->LightStyle(this: engine, a2: this->m_iStyle, a3: "m");
      }
    }
  }
  else
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164DF0
// Name: public: virtual void CEnvLight::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEnvLight::Spawn(CEnvLight *this)
{
  CLight::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x10164E80
// Name: public: void CLight::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLight::TurnOn(CLight *this)
{
  const char *pszValue; // eax
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  pszValue = this->m_iszPattern.pszValue;
  if ( pszValue != nullptr )
    engine->LightStyle(this: engine, a2: this->m_iStyle, a3: pszValue);
  else
    engine->LightStyle(this: engine, a2: this->m_iStyle, a3: "m");
  v3 = this->m_spawnflags.m_Value & 0xFFFFFFFE;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_spawnflags.m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      this->m_spawnflags.m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164F00
// Name: public: void CLight::TurnOff(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLight::TurnOff(CLight *this)
{
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // edi
  int v4; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v5; // eax
  CBaseEdict *v6; // ecx

  engine->LightStyle(this: engine, a2: this->m_iStyle, a3: "a");
  m_Value = this->m_spawnflags.m_Value;
  p_m_spawnflags = &this->m_spawnflags;
  v4 = m_Value | 1;
  if ( m_Value != (m_Value | 1) )
  {
    v5 = p_m_spawnflags - 190;
    if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
    {
      LOBYTE(v5[22].m_Value) |= 1u;
      p_m_spawnflags->m_Value = v4;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164F70
// Name: public: void CLight::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CLight::InputTurnOn(CLight *this, inputdata_t *inputdata)
{
  CLight::TurnOn(this);
}

//------------------------------------------------------------------------------
// Address: 0x10164F80
// Name: public: void CLight::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CLight::InputTurnOff(CLight *this, inputdata_t *inputdata)
{
  CLight::TurnOff(this);
}

//------------------------------------------------------------------------------
// Address: 0x10164F90
// Name: public: void CLight::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLight::InputToggle(CLight *this, inputdata_t *inputdata)
{
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    CLight::TurnOn(this);
  else
    CLight::TurnOff(this);
}

//------------------------------------------------------------------------------
// Address: 0x10164FB0
// Name: public: void CLight::InputSetPattern(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLight::InputSetPattern(CLight *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax
  const char *iVal; // eax
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // edi
  unsigned int v7; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v8; // eax
  CBaseEdict *v9; // ecx

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  iVal = (const char *)p_value->iVal;
  this->m_iszPattern.pszValue = iVal;
  if ( iVal == nullptr )
    iVal = locale;
  engine->LightStyle(this: engine, a2: this->m_iStyle, a3: iVal);
  m_Value = this->m_spawnflags.m_Value;
  p_m_spawnflags = &this->m_spawnflags;
  v7 = m_Value & 0xFFFFFFFE;
  if ( m_Value != (m_Value & 0xFFFFFFFE) )
  {
    v8 = p_m_spawnflags - 190;
    if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
    {
      LOBYTE(v8[22].m_Value) |= 1u;
      p_m_spawnflags->m_Value = v7;
    }
    else
    {
      v9 = (CBaseEdict *)v8[6].m_Value;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: v9, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165040
// Name: public: void CLight::InputFadeToPattern(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLight::InputFadeToPattern(CLight *this, inputdata_t *inputdata)
{
  char *pszValue; // eax
  variant_t *p_value; // edi
  char *iVal; // eax
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // edi
  unsigned int v8; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v9; // eax
  CBaseEdict *v10; // ecx

  pszValue = (char *)this->m_iszPattern.pszValue;
  if ( pszValue == nullptr )
    pszValue = (char *)locale;
  p_value = &inputdata->value;
  this->m_iCurrentFade = *pszValue;
  if ( p_value->fieldType == FIELD_STRING )
  {
    iVal = (char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = (char *)locale;
  }
  else
  {
    iVal = (char *)variant_t::ToString(this: p_value);
  }
  this->m_iTargetFade = *iVal;
  if ( p_value->fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  this->m_iszPattern.pszValue = (const char *)p_value->iVal;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CLight::FadeThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  m_Value = this->m_spawnflags.m_Value;
  p_m_spawnflags = &this->m_spawnflags;
  v8 = m_Value & 0xFFFFFFFE;
  if ( m_Value != (m_Value & 0xFFFFFFFE) )
  {
    v9 = p_m_spawnflags - 190;
    if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
    {
      LOBYTE(v9[22].m_Value) |= 1u;
      p_m_spawnflags->m_Value = v8;
    }
    else
    {
      v10 = (CBaseEdict *)v9[6].m_Value;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: v10, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165120
// Name: public: virtual void CLight::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLight::Use(CLight *this, CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value)
{
  if ( this->m_iStyle >= 32
    && CBaseEntity::ShouldToggle(this, useType, currentState: (this->m_spawnflags.m_Value & 1) == 0) != 0 )
  {
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
      CLight::TurnOn(this);
    else
      CLight::TurnOff(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405620
// Name: CLight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLight>(__formal: nullptr);
  CLight_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10165170
// Name: struct datamap_t __near * DataMapInit<class CLight>(class CLight __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLight>()
{
  char *Name; // eax

  if ( (_S2_141 & 1) == 0 )
  {
    _S2_141 |= 1u;
    nameHolder_244.m_pszBase = "CLight";
    nameHolder_244.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_244.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_244.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_244.m_Names.m_Size = 0;
    nameHolder_244.m_Names.m_pElements = nullptr;
    nameHolder_244.m_nLenBase = 6;
    atexit(func: DataMapInit_CLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLight::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_141 & 2) == 0 )
  {
    _S2_141 |= 2u;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_244, pszIdentifier: "FadeThink");
    *(_QWORD *)&dataDesc_231[6].td = 0;
    *(_QWORD *)&dataDesc_231[6].override_field = 0;
    *(_QWORD *)&dataDesc_231[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_231[6].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_231[7].td = 0;
    *(_QWORD *)&dataDesc_231[7].override_field = 0;
    *(_QWORD *)&dataDesc_231[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_231[7].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_231[8].td = 0;
    *(_QWORD *)&dataDesc_231[8].override_field = 0;
    *(_QWORD *)&dataDesc_231[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_231[8].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_231[9].td = 0;
    *(_QWORD *)&dataDesc_231[9].override_field = 0;
    *(_QWORD *)&dataDesc_231[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_231[9].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_231[10].td = 0;
    *(_QWORD *)&dataDesc_231[10].override_field = 0;
    *(_QWORD *)&dataDesc_231[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_231[10].flatOffset[1] = 0;
    dataDesc_231[6].fieldName = Name;
    dataDesc_231[6].fieldOffset = 0;
    *(_DWORD *)&dataDesc_231[6].fieldSize = 2097153;
    dataDesc_231[6].externalName = nullptr;
    dataDesc_231[6].pSaveRestoreOps = nullptr;
    dataDesc_231[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLight::FadeThink;
    dataDesc_231[7].fieldType = FIELD_STRING;
    dataDesc_231[7].fieldName = "InputSetPattern";
    dataDesc_231[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_231[7].fieldSize = 524289;
    dataDesc_231[7].externalName = "SetPattern";
    dataDesc_231[7].pSaveRestoreOps = nullptr;
    dataDesc_231[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLight::InputSetPattern;
    dataDesc_231[8].fieldType = FIELD_STRING;
    dataDesc_231[8].fieldName = "InputFadeToPattern";
    dataDesc_231[8].fieldOffset = 0;
    *(_DWORD *)&dataDesc_231[8].fieldSize = 524289;
    dataDesc_231[8].externalName = "FadeToPattern";
    dataDesc_231[8].pSaveRestoreOps = nullptr;
    dataDesc_231[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLight::InputFadeToPattern;
    dataDesc_231[9].fieldType = FIELD_VOID;
    dataDesc_231[9].fieldName = "InputToggle";
    dataDesc_231[9].fieldOffset = 0;
    *(_DWORD *)&dataDesc_231[9].fieldSize = 524289;
    dataDesc_231[9].externalName = "Toggle";
    dataDesc_231[9].pSaveRestoreOps = nullptr;
    dataDesc_231[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLight::InputToggle;
    dataDesc_231[10].fieldType = FIELD_VOID;
    dataDesc_231[10].fieldName = "InputTurnOn";
    dataDesc_231[10].fieldOffset = 0;
    *(_DWORD *)&dataDesc_231[10].fieldSize = 524289;
    dataDesc_231[10].externalName = "TurnOn";
    dataDesc_231[10].pSaveRestoreOps = nullptr;
    dataDesc_231[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLight::InputTurnOn;
    dataDesc_231[11].fieldType = FIELD_VOID;
    dataDesc_231[11].fieldName = "InputTurnOff";
    dataDesc_231[11].fieldOffset = 0;
    *(_DWORD *)&dataDesc_231[11].fieldSize = 524289;
    dataDesc_231[11].externalName = "TurnOff";
    dataDesc_231[11].pSaveRestoreOps = nullptr;
    dataDesc_231[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLight::InputTurnOff;
    *(_QWORD *)&dataDesc_231[11].td = 0;
    *(_QWORD *)&dataDesc_231[11].override_field = 0;
    *(_QWORD *)&dataDesc_231[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_231[11].flatOffset[1] = 0;
  }
  CLight::m_DataMap.dataNumFields = 11;
  CLight::m_DataMap.dataDesc = &dataDesc_231[1];
  return &CLight::m_DataMap;
}
