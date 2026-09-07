// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/logic_measure_movement.cpp
// Functions: 15
// ============================================================

#include "game\server\logic_measure_movement.h"

//------------------------------------------------------------------------------
// Address: 0x10120FC0
// Name: private: void CLogicMeasureMovement::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::InputDisable(CEnvSpark *this, inputdata_t *inputdata)
{
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10165760
// Name: private: virtual struct datamap_t __near * CLogicMeasureMovement::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicMeasureMovement::GetDataDescMap(CLogicMeasureMovement *this)
{
  return &CLogicMeasureMovement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101657A0
// Name: private: void CLogicMeasureMovement::SetMeasureTarget(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::SetMeasureTarget(CLogicMeasureMovement *this, const char *pName)
{
  CBasePlayer *EntityByName; // eax
  unsigned int m_Index; // eax
  const char *pszValue; // esi

  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pName,
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
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    pszValue = this->m_strMeasureTarget.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( V_strnicmp(s1: pszValue, s2: "!player", n: 8) != 0 )
      _Warning(a1: "logic_measure_movement: Unable to find measure target entity %s\n", pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165850
// Name: private: void CLogicMeasureMovement::SetMeasureReference(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::SetMeasureReference(CLogicMeasureMovement *this, const char *pName)
{
  CBasePlayer *EntityByName; // eax
  unsigned int m_Index; // eax

  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pName,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hMeasureReference.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hMeasureReference.m_Index = -1;
  m_Index = this->m_hMeasureReference.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    _Warning(a1: "logic_measure_movement: Unable to find measure reference entity %s\n", pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101658E0
// Name: private: void CLogicMeasureMovement::SetTarget(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::SetTarget(CLogicMeasureMovement *this, const char *pName)
{
  CBasePlayer *EntityByName; // eax
  unsigned int m_Index; // eax

  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pName,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hTarget.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hTarget.m_Index = -1;
  m_Index = this->m_hTarget.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    _Warning(a1: "logic_measure_movement: Unable to find movement target entity %s\n", pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165970
// Name: private: void CLogicMeasureMovement::SetTargetReference(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::SetTargetReference(CLogicMeasureMovement *this, const char *pName)
{
  CBasePlayer *EntityByName; // eax
  unsigned int m_Index; // eax

  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pName,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hTargetReference.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hTargetReference.m_Index = -1;
  m_Index = this->m_hTargetReference.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    _Warning(a1: "logic_measure_movement: Unable to find movement reference entity %s\n", pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165A00
// Name: private: void CLogicMeasureMovement::MeasureThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::MeasureThink(CLogicMeasureMovement *this)
{
  unsigned int m_Index; // eax
  CBaseEntityList *v3; // edx
  const char *pszValue; // eax
  const char *v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  int m_nMeasureType; // eax
  CBaseEntity *v11; // edi
  CBaseEntity *v12; // ebx
  const QAngle *v13; // eax
  CBaseEntity *v14; // eax
  const matrix3x4_t *v15; // eax
  CBaseEntity *v16; // eax
  CBaseEntity *v17; // edi
  float m_flScale; // xmm0_4
  float v19; // xmm0_4
  CBaseEntity *v20; // eax
  CBaseEntity *v21; // edi
  CBaseEntity *v22; // eax
  CBaseEntity *v23; // eax
  const Vector *v24; // [esp-4h] [ebp-F8h]
  matrix3x4_t matMeasureToRef; // [esp+10h] [ebp-E4h] BYREF
  matrix3x4_t matWorldToMeasure; // [esp+40h] [ebp-B4h] BYREF
  matrix3x4_t matRefToMeasure; // [esp+70h] [ebp-84h] BYREF
  matrix3x4_t matNewTargetToWorld; // [esp+A0h] [ebp-54h] BYREF
  QAngle vecNewAngles; // [esp+D0h] [ebp-24h] BYREF
  Vector vecNewOrigin; // [esp+DCh] [ebp-18h] BYREF
  Vector vecTranslation; // [esp+E8h] [ebp-Ch] BYREF
  int savedregs; // [esp+F4h] [ebp+0h] BYREF

  m_Index = this->m_hMeasureTarget.m_Index;
  if ( m_Index == -1
    || (v3 = g_pEntityList, g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index))
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    pszValue = this->m_strMeasureTarget.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( V_strnicmp(s1: pszValue, s2: "!player", n: 8) == 0 )
    {
      v5 = this->m_strMeasureTarget.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      CLogicMeasureMovement::SetMeasureTarget(this, pName: v5);
    }
    v3 = g_pEntityList;
  }
  v6 = this->m_hMeasureTarget.m_Index;
  if ( v6 != -1
    && v3->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6)
    && v3->m_EntPtrArray[(unsigned __int16)v6].m_pEntity != nullptr )
  {
    v7 = this->m_hMeasureReference.m_Index;
    if ( v7 != -1
      && v3->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7)
      && v3->m_EntPtrArray[(unsigned __int16)v7].m_pEntity != nullptr )
    {
      v8 = this->m_hTarget.m_Index;
      if ( v8 != -1
        && v3->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber == HIWORD(v8)
        && v3->m_EntPtrArray[(unsigned __int16)v8].m_pEntity != nullptr )
      {
        v9 = this->m_hTargetReference.m_Index;
        if ( v9 != -1
          && v3->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber == HIWORD(v9)
          && v3->m_EntPtrArray[(unsigned __int16)v9].m_pEntity != nullptr )
        {
          m_nMeasureType = this->m_nMeasureType;
          if ( m_nMeasureType != 0 )
          {
            if ( m_nMeasureType == 1 )
            {
              v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hMeasureTarget);
              v12 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hMeasureTarget);
              v24 = v11->EyePosition(this: v11, result: &vecTranslation);
              v13 = v12->EyeAngles(this: v12);
              AngleIMatrix(angles: v13, position: v24, mat: &matWorldToMeasure);
            }
          }
          else
          {
            v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hMeasureTarget);
            v15 = CBaseEntity::EntityToWorldTransform(this: v14);
            MatrixInvert(in: v15, out: &matWorldToMeasure);
          }
          v16 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hMeasureReference);
          v17 = v16;
          if ( (v16->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v16, a2: (int)&savedregs);
          ConcatTransforms(in1: &matWorldToMeasure, in2: &v17->m_rgflCoordinateFrame, out: &matRefToMeasure);
          m_flScale = this->m_flScale;
          if ( m_flScale != 0.0 && m_flScale != 1.0 )
          {
            MatrixGetColumn(in: &matRefToMeasure, column: 3, out: &vecTranslation);
            v19 = 1.0 / this->m_flScale;
            vecTranslation.x = vecTranslation.x * v19;
            vecTranslation.y = vecTranslation.y * v19;
            vecTranslation.z = vecTranslation.z * v19;
            MatrixSetColumn(in: &vecTranslation, column: 3, out: &matRefToMeasure);
          }
          MatrixInvert(in: &matRefToMeasure, out: &matMeasureToRef);
          v20 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTargetReference);
          v21 = v20;
          if ( (v20->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v20, a2: (int)&savedregs);
          ConcatTransforms(in1: &v21->m_rgflCoordinateFrame, in2: &matMeasureToRef, out: &matNewTargetToWorld);
          MatrixAngles(a1: (int)this, src: (const VMatrix *)&matNewTargetToWorld, vAngles: &vecNewAngles);
          vecNewOrigin.x = matNewTargetToWorld.m_flMatVal[0][3];
          vecNewOrigin.y = matNewTargetToWorld.m_flMatVal[1][3];
          vecNewOrigin.z = matNewTargetToWorld.m_flMatVal[2][3];
          v22 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget);
          CBaseEntity::SetAbsOrigin(this: v22, absOrigin: &vecNewOrigin);
          v23 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget);
          CBaseEntity::SetAbsAngles(this: v23, absAngles: &vecNewAngles);
        }
      }
    }
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10165D50
// Name: private: void CLogicMeasureMovement::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::InputEnable(CLogicMeasureMovement *this, inputdata_t *inputdata)
{
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CLogicMeasureMovement::MeasureThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10165D90
// Name: private: void CLogicMeasureMovement::InputSetMeasureTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::InputSetMeasureTarget(CLogicMeasureMovement *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax

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
  this->m_strMeasureTarget.pszValue = pszValue;
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
  CLogicMeasureMovement::SetMeasureTarget(this, pName: v4);
  v5 = this->m_target.pszValue;
  if ( v5 == nullptr )
    v5 = locale;
  CLogicMeasureMovement::SetTarget(this, pName: v5);
  v6 = this->m_strTargetReference.pszValue;
  if ( v6 == nullptr )
    v6 = locale;
  CLogicMeasureMovement::SetTargetReference(this, pName: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10165E20
// Name: private: void CLogicMeasureMovement::InputSetMeasureReference(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::InputSetMeasureReference(CLogicMeasureMovement *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // esi
  const char *v5; // eax

  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
LABEL_5:
    if ( pszValue != nullptr && *pszValue != 0 )
      goto LABEL_8;
    goto LABEL_7;
  }
  pszValue = inputdata->value.iszVal.pszValue;
  if ( pszValue != nullptr )
    goto LABEL_5;
LABEL_7:
  pszValue = nullptr;
LABEL_8:
  this->m_strMeasureReference.pszValue = pszValue;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    v4 = inputdata->value.iszVal.pszValue;
    if ( v4 != nullptr )
      CLogicMeasureMovement::SetMeasureReference(this, pName: v4);
    else
      CLogicMeasureMovement::SetMeasureReference(this, pName: locale);
  }
  else
  {
    v5 = variant_t::ToString(this: &inputdata->value);
    CLogicMeasureMovement::SetMeasureReference(this, pName: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165EA0
// Name: private: void CLogicMeasureMovement::InputSetTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::InputSetTarget(CLogicMeasureMovement *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // esi
  const char *v5; // eax

  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
LABEL_5:
    if ( pszValue != nullptr && *pszValue != 0 )
      goto LABEL_8;
    goto LABEL_7;
  }
  pszValue = inputdata->value.iszVal.pszValue;
  if ( pszValue != nullptr )
    goto LABEL_5;
LABEL_7:
  pszValue = nullptr;
LABEL_8:
  this->m_target.pszValue = pszValue;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    v4 = inputdata->value.iszVal.pszValue;
    if ( v4 != nullptr )
      CLogicMeasureMovement::SetTarget(this, pName: v4);
    else
      CLogicMeasureMovement::SetTarget(this, pName: locale);
  }
  else
  {
    v5 = variant_t::ToString(this: &inputdata->value);
    CLogicMeasureMovement::SetTarget(this, pName: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165F20
// Name: private: void CLogicMeasureMovement::InputSetTargetReference(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::InputSetTargetReference(CLogicMeasureMovement *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // esi
  const char *v5; // eax

  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
LABEL_5:
    if ( pszValue != nullptr && *pszValue != 0 )
      goto LABEL_8;
    goto LABEL_7;
  }
  pszValue = inputdata->value.iszVal.pszValue;
  if ( pszValue != nullptr )
    goto LABEL_5;
LABEL_7:
  pszValue = nullptr;
LABEL_8:
  this->m_strTargetReference.pszValue = pszValue;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    v4 = inputdata->value.iszVal.pszValue;
    if ( v4 != nullptr )
      CLogicMeasureMovement::SetTargetReference(this, pName: v4);
    else
      CLogicMeasureMovement::SetTargetReference(this, pName: locale);
  }
  else
  {
    v5 = variant_t::ToString(this: &inputdata->value);
    CLogicMeasureMovement::SetTargetReference(this, pName: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165FA0
// Name: public: virtual void CLogicMeasureMovement::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicMeasureMovement::Activate(CLogicMeasureMovement *this)
{
  const char *pszValue; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax

  CBaseEntity::Activate(this);
  pszValue = this->m_strMeasureTarget.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CLogicMeasureMovement::SetMeasureTarget(this, pName: pszValue);
  v3 = this->m_strMeasureReference.pszValue;
  if ( v3 == nullptr )
    v3 = locale;
  CLogicMeasureMovement::SetMeasureReference(this, pName: v3);
  v4 = this->m_target.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  CLogicMeasureMovement::SetTarget(this, pName: v4);
  v5 = this->m_strTargetReference.pszValue;
  if ( v5 == nullptr )
    v5 = locale;
  CLogicMeasureMovement::SetTargetReference(this, pName: v5);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CLogicMeasureMovement::MeasureThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10405700
// Name: CLogicMeasureMovement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicMeasureMovement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicMeasureMovement>();
  CLogicMeasureMovement_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166040
// Name: class CLogicMeasureMovement __near * _CreateEntityTemplate<class CLogicMeasureMovement>(class CLogicMeasureMovement __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CLogicMeasureMovement *__cdecl _CreateEntityTemplate<CLogicMeasureMovement>(
        CLogicMeasureMovement *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x378u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CLogicMeasureMovement::`vftable';
    v3[216] = -1;
    v3[217] = -1;
    v3[218] = -1;
    v3[219] = -1;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CLogicMeasureMovement *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}
