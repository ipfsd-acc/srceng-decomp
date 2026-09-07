// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/pointanglesensor.cpp
// Functions: 23
// ============================================================

#include "game\server\pointanglesensor.h"

//------------------------------------------------------------------------------
// Address: 0x101D7C90
// Name: protected: virtual struct datamap_t __near * CPointAngleSensor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointAngleSensor::GetDataDescMap(CPointAngleSensor *this)
{
  return &CPointAngleSensor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D7CA0
// Name: private: virtual struct datamap_t __near * CPointProximitySensor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointProximitySensor::GetDataDescMap(CPointProximitySensor *this)
{
  return &CPointProximitySensor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D7CB0
// Name: public: virtual bool CPointAngleSensor::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPointAngleSensor::KeyValue(CPointAngleSensor *this, const char *szKeyName, const char *szValue)
{
  long double v4; // st7

  if ( szKeyName != "tolerance" && _V_stricmp(s1: szKeyName, s2: "tolerance") != 0 )
    return CServerOnlyPointEntity::KeyValue((CLogicalEntity *)this, szKeyName, szValue);
  v4 = atof(nptr: szValue);
  this->m_flDotTolerance = cos(v4 * 0.017453292);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101D7D10
// Name: protected: void CPointAngleSensor::InputSetTargetEntity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngleSensor::InputSetTargetEntity(CPointAngleSensor *this, inputdata_t *inputdata)
{
  inputdata_t *v2; // ebx
  const char *pszValue; // eax
  _fieldtypes fieldType; // ecx
  inputdata_t **p_value; // eax
  const char *v7; // eax
  float thinkTime; // xmm0_4
  const char *v9; // eax
  string_t v10; // eax
  CBasePlayer *EntityByName; // eax

  v2 = inputdata;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    if ( pszValue == nullptr )
      goto LABEL_6;
  }
  else
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
  }
  if ( pszValue == nullptr )
  {
LABEL_12:
    thinkTime = -1.0;
    this->m_target.pszValue = nullptr;
    this->m_hTargetEntity.m_Index = -1;
LABEL_13:
    CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
    return;
  }
LABEL_6:
  fieldType = v2->value.fieldType;
  if ( fieldType == FIELD_STRING )
  {
    p_value = (inputdata_t **)&v2->value;
  }
  else
  {
    inputdata = nullptr;
    p_value = &inputdata;
  }
  if ( *p_value == nullptr )
    goto LABEL_12;
  if ( fieldType == FIELD_STRING )
  {
    v7 = v2->value.iszVal.pszValue;
    if ( v7 == nullptr )
      goto LABEL_12;
  }
  else
  {
    v7 = variant_t::ToString(this: &v2->value);
  }
  if ( *v7 == 0 )
    goto LABEL_12;
  if ( v2->value.fieldType == FIELD_STRING )
  {
    v9 = v2->value.iszVal.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
  }
  else
  {
    v9 = variant_t::ToString(this: &v2->value);
  }
  v10.pszValue = *(const char **)AllocPooledString(pszValue: (char *)&inputdata, pszValuea: v9).pszValue;
  this->m_target = v10;
  if ( v10.pszValue == nullptr )
    v10.pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: v10.pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: v2->pActivator,
                   pCaller: v2->pCaller,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hTargetEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hTargetEntity.m_Index = -1;
  if ( !this->m_bDisabled && CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTargetEntity) != nullptr )
  {
    thinkTime = gpGlobals->curtime;
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7E40
// Name: protected: void CPointProximitySensor::InputSetTargetEntity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointProximitySensor::InputSetTargetEntity(CPointProximitySensor *this, inputdata_t *inputdata)
{
  inputdata_t *v2; // ebx
  const char *pszValue; // eax
  _fieldtypes fieldType; // ecx
  inputdata_t **p_value; // eax
  const char *v7; // eax
  float thinkTime; // xmm0_4
  const char *v9; // eax
  string_t v10; // eax
  CBasePlayer *EntityByName; // eax

  v2 = inputdata;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    if ( pszValue == nullptr )
      goto LABEL_6;
  }
  else
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
  }
  if ( pszValue == nullptr )
  {
LABEL_12:
    thinkTime = -1.0;
    this->m_target.pszValue = nullptr;
    this->m_hTargetEntity.m_Index = -1;
LABEL_13:
    CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
    return;
  }
LABEL_6:
  fieldType = v2->value.fieldType;
  if ( fieldType == FIELD_STRING )
  {
    p_value = (inputdata_t **)&v2->value;
  }
  else
  {
    inputdata = nullptr;
    p_value = &inputdata;
  }
  if ( *p_value == nullptr )
    goto LABEL_12;
  if ( fieldType == FIELD_STRING )
  {
    v7 = v2->value.iszVal.pszValue;
    if ( v7 == nullptr )
      goto LABEL_12;
  }
  else
  {
    v7 = variant_t::ToString(this: &v2->value);
  }
  if ( *v7 == 0 )
    goto LABEL_12;
  if ( v2->value.fieldType == FIELD_STRING )
  {
    v9 = v2->value.iszVal.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
  }
  else
  {
    v9 = variant_t::ToString(this: &v2->value);
  }
  v10.pszValue = *(const char **)AllocPooledString(pszValue: (char *)&inputdata, pszValuea: v9).pszValue;
  this->m_target = v10;
  if ( v10.pszValue == nullptr )
    v10.pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: v10.pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: v2->pActivator,
                   pCaller: v2->pCaller,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hTargetEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hTargetEntity.m_Index = -1;
  if ( !this->m_bDisabled && CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTargetEntity) != nullptr )
  {
    thinkTime = gpGlobals->curtime;
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7F70
// Name: protected: void CPointProximitySensor::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointProximitySensor::InputDisable(CPointProximitySensor *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D7FA0
// Name: public: virtual void CPointAngleSensor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngleSensor::Activate(CPointAngleSensor *this)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  unsigned int v5; // eax
  const char *v6; // eax
  CBasePlayer *v7; // eax
  unsigned int v8; // eax
  const char *v9; // eax
  const char *DebugName; // eax
  unsigned int v11; // eax
  const char *v12; // [esp+4h] [ebp-8h]

  CBaseEntity::Activate(this);
  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
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
      this->m_hTargetEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
    else
      this->m_hTargetEntity.m_Index = -1;
  }
  v5 = this->m_hLookAtEntity.m_Index;
  if ( v5 == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity == nullptr )
  {
    v6 = this->m_nLookAtName.pszValue;
    if ( v6 != nullptr )
    {
      v7 = CGlobalEntityList::FindEntityByName(
             this: &gEntList,
             pStartEntity: nullptr,
             szName: v6,
             pSearchingEntity: nullptr,
             pActivator: nullptr,
             pCaller: nullptr,
             pFilter: nullptr);
      this->m_hLookAtEntity.m_Index = v7 != nullptr ? v7->GetRefEHandle(this: v7)->m_Index : -1;
      v8 = this->m_hLookAtEntity.m_Index;
      if ( v8 == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity == nullptr )
      {
        v9 = this->m_nLookAtName.pszValue;
        if ( v9 == nullptr )
          v9 = locale;
        v12 = v9;
        DebugName = CBaseEntity::GetDebugName(this);
        _DevMsg(a1: 1, a2: "Angle sensor '%s' could not find look at entity '%s'.\n", DebugName, v12);
      }
    }
  }
  if ( !this->m_bDisabled )
  {
    v11 = this->m_hTargetEntity.m_Index;
    if ( v11 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber == HIWORD(v11)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity != nullptr )
    {
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8140
// Name: protected: bool CPointAngleSensor::IsFacingWithinTolerance(class CBaseEntity __near *,class CBaseEntity __near *,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPointAngleSensor::IsFacingWithinTolerance(
        CPointAngleSensor *this,
        CBaseEntity *pEntity,
        CBaseEntity *pTarget,
        float flTolerance,
        float *pflDot)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  Vector forward; // [esp+Ch] [ebp-18h] BYREF
  Vector dir; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( pflDot != nullptr )
    *pflDot = 0.0;
  if ( pEntity == nullptr || pTarget == nullptr )
    return false;
  pEntity->GetVectors(this: pEntity, a2: &forward, a3: nullptr, a4: nullptr);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    pTarget->GetVectors(this: pTarget, a2: &dir, a3: nullptr, a4: nullptr);
  }
  else
  {
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
    if ( (pTarget->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pTarget, a2: (int)&savedregs);
    v6 = pTarget->m_vecAbsOrigin.y - pEntity->m_vecAbsOrigin.y;
    v7 = pTarget->m_vecAbsOrigin.z - pEntity->m_vecAbsOrigin.z;
    dir.x = pTarget->m_vecAbsOrigin.x - pEntity->m_vecAbsOrigin.x;
    dir.y = v6;
    dir.z = v7;
    VectorNormalize(vec: &dir);
  }
  v8 = (float)((float)(forward.y * dir.y) + (float)(forward.x * dir.x)) + (float)(forward.z * dir.z);
  if ( pflDot != nullptr )
    *pflDot = v8;
  return v8 >= this->m_flDotTolerance;
}

//------------------------------------------------------------------------------
// Address: 0x101D8270
// Name: protected: void CPointAngleSensor::InputTest(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngleSensor::InputTest(CPointAngleSensor *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edi
  unsigned int v5; // eax
  CBaseEntity *v6; // ecx

  m_Index = this->m_hLookAtEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v5 = this->m_hTargetEntity.m_Index;
  if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
    v6 = nullptr;
  else
    v6 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  if ( CPointAngleSensor::IsFacingWithinTolerance(
         this,
         pEntity: v6,
         pTarget: m_pEntity,
         flTolerance: this->m_flDotTolerance,
         pflDot: nullptr) )
  {
    COutputEvent::FireOutput(
      this: &this->m_OnFacingLookat,
      pActivator: inputdata->pActivator,
      pCaller: this,
      fDelay: 0.0);
  }
  else
  {
    COutputEvent::FireOutput(
      this: &this->m_OnNotFacingLookat,
      pActivator: inputdata->pActivator,
      pCaller: this,
      fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8330
// Name: protected: void CPointAngleSensor::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngleSensor::InputEnable(CPointAngleSensor *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // eax

  this->m_bDisabled = false;
  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8380
// Name: protected: void CPointAngleSensor::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngleSensor::InputToggle(CPointAngleSensor *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // eax

  if ( this->m_bDisabled )
  {
    this->m_bDisabled = false;
    m_Index = this->m_hTargetEntity.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
  else
  {
    this->m_bDisabled = true;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8400
// Name: public: virtual int CPointAngleSensor::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPointAngleSensor::DrawDebugTextOverlays(CPointAngleSensor *this)
{
  int result; // eax
  int v3; // edi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edx
  unsigned int v6; // eax
  CBaseEntity *v7; // eax
  bool IsFacingWithinTolerance; // bl
  double v9; // xmm0_8
  int v10; // edi
  int v11; // edi
  const char *v12; // eax
  double flTolerance; // [esp+Ch] [ebp-218h]
  double flTolerancea; // [esp+Ch] [ebp-218h]
  char tempstr[512]; // [esp+20h] [ebp-204h] BYREF
  float flDot; // [esp+220h] [ebp-4h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    m_Index = this->m_hLookAtEntity.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v6 = this->m_hTargetEntity.m_Index;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      v7 = nullptr;
    else
      v7 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    IsFacingWithinTolerance = CPointAngleSensor::IsFacingWithinTolerance(
                                this,
                                pEntity: v7,
                                pTarget: m_pEntity,
                                flTolerance: this->m_flDotTolerance,
                                pflDot: &flDot);
    flTolerance = flDot;
    v9 = flDot;
    __libm_sse2_acos();
    *(float *)&v9 = v9;
    V_snprintf(
      pDest: tempstr,
      maxLen: 512,
      pFormat: "delta ang (dot)    : %.2f (%f)",
      (float)(*(float *)&v9 * 57.29578),
      flTolerance);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v10 = v3 + 1;
    flTolerancea = this->m_flDotTolerance;
    __libm_sse2_acos();
    *(float *)&v9 = flTolerancea;
    V_snprintf(
      pDest: tempstr,
      maxLen: 512,
      pFormat: "tolerance ang (dot): %.2f (%f)",
      (float)(*(float *)&v9 * 57.29578),
      flTolerancea);
    CBaseEntity::EntityText(this, text_offset: v10, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v11 = v10 + 1;
    v12 = "yes";
    if ( !IsFacingWithinTolerance )
      v12 = "no";
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "facing: %s", v12);
    CBaseEntity::EntityText(this, text_offset: v11, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v11 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D85F0
// Name: public: virtual void CPointProximitySensor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointProximitySensor::Activate(CPointProximitySensor *this)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  unsigned int v5; // eax

  CBaseEntity::Activate(this);
  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
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
      this->m_hTargetEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
    else
      this->m_hTargetEntity.m_Index = -1;
  }
  if ( !this->m_bDisabled )
  {
    v5 = this->m_hTargetEntity.m_Index;
    if ( v5 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber == HIWORD(v5)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity != nullptr )
    {
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D86C0
// Name: protected: void CPointProximitySensor::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointProximitySensor::InputEnable(CPointProximitySensor *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // eax

  this->m_bDisabled = false;
  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8710
// Name: protected: void CPointProximitySensor::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointProximitySensor::InputToggle(CPointProximitySensor *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // eax

  if ( this->m_bDisabled )
  {
    this->m_bDisabled = false;
    m_Index = this->m_hTargetEntity.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
  else
  {
    this->m_bDisabled = true;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8790
// Name: public: virtual void CPointAngleSensor::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngleSensor::Think(CPointAngleSensor *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v10; // ecx
  int v11; // eax
  CEntInfo *v12; // edx
  unsigned int v13; // ecx
  int v14; // eax
  CBaseEntity **v15; // eax
  CBaseEntity *v16; // edx
  unsigned int v17; // eax
  CBaseEntity *v18; // ecx
  float m_flDotTolerance; // xmm2_4
  float value; // xmm1_4
  float v21; // xmm0_4
  Vector forward; // [esp+20h] [ebp-10h] BYREF
  float flDot; // [esp+2Ch] [ebp-4h] BYREF

  m_Index = this->m_hTargetEntity.m_Index;
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
      ((void (__thiscall *)(IHandleEntity *, Vector *, _DWORD, _DWORD))m_pEntity->__vftable[44].dtr_IHandleEntity)(
        a1: m_pEntity,
        a2: &forward,
        a3: 0,
        a4: 0);
      CEntityOutputTemplate<Vector,3>::Set(
        this: &this->m_TargetDir,
        value: ($3B1CACFA647AB85A7D70EA6016B49717 *)&forward,
        pActivator: this,
        pCaller: this);
      v10 = this->m_hLookAtEntity.m_Index;
      if ( v10 != -1 )
      {
        v11 = (unsigned __int16)v10;
        v12 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v10];
        v13 = HIWORD(v10);
        if ( v12->m_SerialNumber == v13 && v12->m_pEntity != nullptr )
        {
          v14 = v11;
          v7 = g_pEntityList->m_EntPtrArray[v14].m_SerialNumber == v13;
          v15 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v14];
          if ( v7 )
            v16 = *v15;
          else
            v16 = nullptr;
          v17 = this->m_hTargetEntity.m_Index;
          if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
            v18 = nullptr;
          else
            v18 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
          if ( CPointAngleSensor::IsFacingWithinTolerance(
                 this,
                 pEntity: v18,
                 pTarget: v16,
                 flTolerance: this->m_flDotTolerance,
                 pflDot: &flDot) )
          {
            if ( !this->m_bFired )
            {
              if ( this->m_flFacingTime == 0.0 )
                this->m_flFacingTime = gpGlobals->curtime;
              if ( gpGlobals->curtime >= (float)(this->m_flDuration + this->m_flFacingTime) )
              {
                COutputEvent::FireOutput(this: &this->m_OnFacingLookat, pActivator: this, pCaller: this, fDelay: 0.0);
                this->m_bFired = true;
              }
            }
          }
          else
          {
            if ( this->m_bFired )
              this->m_bFired = false;
            this->m_flFacingTime = 0.0;
          }
          m_flDotTolerance = this->m_flDotTolerance;
          value = 1.0;
          if ( m_flDotTolerance == 1.0 )
          {
            if ( (float)(flDot - m_flDotTolerance) >= 0.0 )
              value = 0.0;
          }
          else
          {
            v21 = (float)(flDot - 1.0) / (float)(m_flDotTolerance - 1.0);
            if ( v21 >= 0.0 )
            {
              if ( v21 > 1.0 )
                v21 = 1.0;
            }
            else
            {
              v21 = 0.0;
            }
            value = 1.0 - v21;
          }
          CEntityOutputTemplate<float,1>::Set(this: &this->m_FacingPercentage, value, pActivator: this, pCaller: this);
        }
      }
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D89A0
// Name: protected: virtual void CPointProximitySensor::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointProximitySensor::Think(CPointProximitySensor *this)
{
  unsigned int m_Index; // eax
  unsigned int v3; // eax
  CBaseEntity *m_pEntity; // esi
  float v5; // xmm0_4
  Vector vecDir; // [esp+10h] [ebp-1Ch] BYREF
  Vector vecTestDir; // [esp+1Ch] [ebp-10h] BYREF
  float flDist; // [esp+28h] [ebp-4h] BYREF
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v3 = this->m_hTargetEntity.m_Index;
    if ( v3 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
    vecTestDir.x = m_pEntity->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
    vecTestDir.y = m_pEntity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
    vecTestDir.z = m_pEntity->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
    flDist = VectorNormalize(vec: &vecTestDir);
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      this->GetVectors(this, a2: &vecDir, a3: nullptr, a4: nullptr);
      v5 = COERCE_FLOAT(
             COERCE_UNSIGNED_INT(
               (float)((float)(vecTestDir.x * vecDir.x) + (float)(vecDir.y * vecTestDir.y))
             + (float)(vecDir.z * vecTestDir.z))
           & _mask__AbsFloat_)
         * flDist;
    }
    else
    {
      v5 = flDist;
    }
    flDist = v5;
    variant_t::Set(
      this: &this->m_Distance.m_Value,
      ftype: FIELD_FLOAT,
      data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&flDist);
    CBaseEntityOutput::FireOutput(
      this: &this->m_Distance,
      Value: this->m_Distance.m_Value,
      pActivator: this,
      pCaller: this,
      fDelay: 0.0);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8B80
// Name: public: CPointAngleSensor::CPointAngleSensor(void)
// Source: json
//------------------------------------------------------------------------------
CPointAngleSensor *__thiscall CPointAngleSensor::CPointAngleSensor(CPointAngleSensor *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CPointAngleSensor_vtbl *)&CPointAngleSensor::`vftable';
  this->m_hTargetEntity.m_Index = -1;
  this->m_hLookAtEntity.m_Index = -1;
  this->m_OnFacingLookat.m_Value.iVal = 0;
  this->m_OnFacingLookat.m_Value.eVal.m_Index = -1;
  this->m_OnFacingLookat.m_Value.fieldType = FIELD_VOID;
  this->m_OnNotFacingLookat.m_Value.iVal = 0;
  this->m_OnNotFacingLookat.m_Value.eVal.m_Index = -1;
  this->m_OnNotFacingLookat.m_Value.fieldType = FIELD_VOID;
  this->m_TargetDir.m_Value.iVal = 0;
  this->m_TargetDir.m_Value.eVal.m_Index = -1;
  this->m_TargetDir.m_Value.fieldType = FIELD_VOID;
  this->m_FacingPercentage.m_Value.iVal = 0;
  this->m_FacingPercentage.m_Value.eVal.m_Index = -1;
  this->m_FacingPercentage.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102A5610
// Name: public: virtual void CPointAngleSensor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPointAngleSensor::Spawn(CPointAngleSensor *this)
{
  CPointEntity::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x10408860
// Name: CPointAngleSensor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointAngleSensor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointAngleSensor>();
  CPointAngleSensor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408890
// Name: CPointProximitySensor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointProximitySensor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointProximitySensor>();
  CPointProximitySensor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D8C70
// Name: class CPointProximitySensor __near * _CreateEntityTemplate<class CPointProximitySensor>(class CPointProximitySensor __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPointProximitySensor *__cdecl _CreateEntityTemplate<CPointProximitySensor>(
        CPointProximitySensor *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x374u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CPointProximitySensor::`vftable';
    v3[214] = -1;
    v3[215] = 0;
    v3[218] = -1;
    v3[219] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPointProximitySensor *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104088A0
// Name: _dynamic_initializer_for__g_debug_angularsensor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_angularsensor__()
{
  ConVar::ConVar(this: &g_debug_angularsensor, pName: "g_debug_angularsensor", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_angularsensor__);
}
