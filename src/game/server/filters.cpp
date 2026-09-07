// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/filters.cpp
// Functions: 48
// ============================================================

#include "game\server\filters.h"

//------------------------------------------------------------------------------
// Address: 0x101236A0
// Name: public: virtual struct datamap_t __near * CBaseFilter::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseFilter::GetDataDescMap(CBaseFilter *this)
{
  return &CBaseFilter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101236B0
// Name: public: bool CBaseFilter::PassesFilter(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFilter::PassesFilter(CBaseFilter *this, CBaseEntity *pCaller, CBaseEntity *pEntity)
{
  int result; // eax

  LOBYTE(result) = this->PassesFilterImpl(this, a2: pCaller, a3: pEntity);
  if ( this->m_bNegated )
    return (_BYTE)result == 0;
  else
    return (unsigned __int8)result;
}

//------------------------------------------------------------------------------
// Address: 0x101236F0
// Name: public: virtual bool CBaseFilter::PassesDamageFilter(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFilter::PassesDamageFilter(CBaseFilter *this, const CTakeDamageInfo *info)
{
  int result; // eax

  LOBYTE(result) = this->PassesDamageFilterImpl(this, a2: info);
  if ( this->m_bNegated )
    return (_BYTE)result == 0;
  else
    return (unsigned __int8)result;
}

//------------------------------------------------------------------------------
// Address: 0x10123730
// Name: public: void CBaseFilter::InputTestActivator(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFilter::InputTestActivator(CBaseFilter *this, inputdata_t *inputdata)
{
  bool v3; // al
  bool v4; // cl

  v3 = this->PassesFilterImpl(this, a2: inputdata->pCaller, a3: inputdata->pActivator);
  if ( this->m_bNegated )
    v4 = !v3;
  else
    v4 = v3;
  if ( v4 )
    COutputEvent::FireOutput(this: &this->m_OnPass, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
  else
    COutputEvent::FireOutput(this: &this->m_OnFail, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101237A0
// Name: private: virtual struct datamap_t __near * CFilterMultiple::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFilterMultiple::GetDataDescMap(CFilterMultiple *this)
{
  return &CFilterMultiple::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101237B0
// Name: private: virtual struct datamap_t __near * CFilterName::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFilterName::GetDataDescMap(CFilterName *this)
{
  return &CFilterName::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101237C0
// Name: private: virtual struct datamap_t __near * CFilterModel::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFilterModel::GetDataDescMap(CFilterModel *this)
{
  return &CFilterModel::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101237D0
// Name: private: virtual struct datamap_t __near * CFilterContext::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFilterContext::GetDataDescMap(CFilterContext *this)
{
  return &CFilterContext::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101237E0
// Name: private: virtual struct datamap_t __near * CFilterClass::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFilterClass::GetDataDescMap(CFilterClass *this)
{
  return &CFilterClass::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101237F0
// Name: private: virtual struct datamap_t __near * FilterTeam::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall FilterTeam::GetDataDescMap(FilterTeam *this)
{
  return &FilterTeam::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10123800
// Name: private: virtual struct datamap_t __near * CFilterMassGreater::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFilterMassGreater::GetDataDescMap(CFilterMassGreater *this)
{
  return &CFilterMassGreater::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10123810
// Name: private: virtual struct datamap_t __near * FilterDamageType::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall FilterDamageType::GetDataDescMap(FilterDamageType *this)
{
  return &FilterDamageType::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10123820
// Name: private: bool CFilterEnemy::PassesMobbedFilter(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFilterEnemy::PassesMobbedFilter(CFilterEnemy *this, CBaseEntity *pCaller, CBaseEntity *pEnemy)
{
  CAI_BaseNPC *v4; // eax
  CAI_BaseNPC *v5; // esi
  CAI_Squad *m_pSquad; // ecx
  int v8; // edi
  CAI_BaseNPC *FirstMember; // eax
  CBaseEntity *v10; // eax

  v4 = pCaller->MyNPCPointer(this: pCaller);
  v5 = v4;
  if ( v4 == nullptr )
    return 1;
  m_pSquad = v4->m_pSquad;
  if ( m_pSquad == nullptr || this->m_nMaxSquadmatesPerEnemy <= 0 )
    return 1;
  v8 = 0;
  FirstMember = CAI_Squad::GetFirstMember(
                  this: m_pSquad,
                  pIter: (AISquadIter_t__ **)&pCaller,
                  bIgnoreSilentMembers: true);
  if ( FirstMember == nullptr )
    return !this->m_bNegated;
  while ( 1 )
  {
    if ( FirstMember != v5 )
    {
      v10 = FirstMember->GetEnemy_2(this: FirstMember);
      if ( v10 == pEnemy && ++v8 >= this->m_nMaxSquadmatesPerEnemy )
        break;
    }
    FirstMember = CAI_Squad::GetNextMember(
                    this: v5->m_pSquad,
                    pIter: (AISquadIter_t__ **)&pCaller,
                    bIgnoreSilentMembers: true);
    if ( FirstMember == nullptr )
      return !this->m_bNegated;
  }
  return this->m_bNegated;
}

//------------------------------------------------------------------------------
// Address: 0x101238C0
// Name: private: virtual struct datamap_t __near * CFilterEnemy::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFilterEnemy::GetDataDescMap(CFilterEnemy *this)
{
  return &CFilterEnemy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101238D0
// Name: private: virtual void CFilterMultiple::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterMultiple::Activate(CFilterMultiple *this)
{
  CHandle<CBaseEntity> *m_hFilter; // edi
  string_t *m_iFilterName; // esi
  int i; // ebx
  CBasePlayer *EntityByName; // eax
  void *v6; // eax
  const char *pszValue; // eax

  CBaseEntity::Activate(this);
  m_hFilter = this->m_hFilter;
  m_iFilterName = this->m_iFilterName;
  for ( i = 10; i != 0; --i )
  {
    if ( m_iFilterName->pszValue != nullptr )
    {
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: m_iFilterName->pszValue,
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
      {
        m_hFilter->m_Index = *(unsigned int *)(*(int (__thiscall **)(void *))(*(_DWORD *)v6 + 8))(a1: v6);
        ++m_hFilter;
      }
      else
      {
        pszValue = m_iFilterName->pszValue;
        if ( m_iFilterName->pszValue == nullptr )
          pszValue = locale;
        _Warning(a1: "filter_multi: Tried to add entity (%s) which is not a filter entity!\n", pszValue);
      }
    }
    ++m_iFilterName;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123960
// Name: private: bool CFilterEnemy::PassesProximityFilter(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFilterEnemy::PassesProximityFilter(CFilterEnemy *this, CBaseEntity *pCaller, CBaseEntity *pEnemy)
{
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float m_flOuterRadius; // xmm0_4
  float v10; // xmm3_4
  float m_flRadius; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  bool m_bNegated; // al
  int savedregs; // [esp+0h] [ebp+0h] BYREF
  bool bAlreadyEnemy_3; // [esp+Bh] [ebp+Bh]

  if ( this->m_flRadius <= 0.0 )
    return 1;
  bAlreadyEnemy_3 = pCaller->GetEnemy_2(this: pCaller) == pEnemy;
  if ( (pEnemy->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEnemy, a2: (int)&savedregs);
  if ( (pCaller->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pCaller, a2: (int)&savedregs);
  v6 = pCaller->m_vecAbsOrigin.x - pEnemy->m_vecAbsOrigin.x;
  v7 = pCaller->m_vecAbsOrigin.z - pEnemy->m_vecAbsOrigin.z;
  v8 = v6 * v6;
  m_flOuterRadius = this->m_flOuterRadius;
  v10 = (float)(v8
              + (float)((float)(pCaller->m_vecAbsOrigin.y - pEnemy->m_vecAbsOrigin.y)
                      * (float)(pCaller->m_vecAbsOrigin.y - pEnemy->m_vecAbsOrigin.y)))
      + (float)(v7 * v7);
  if ( m_flOuterRadius == 0.0 )
  {
    m_flRadius = this->m_flRadius;
    if ( this->m_bNegated )
      m_flOuterRadius = m_flRadius * 0.5;
    else
      m_flOuterRadius = m_flRadius * 2.0;
  }
  v12 = this->m_flRadius;
  if ( v12 > m_flOuterRadius )
  {
    v13 = m_flOuterRadius;
    m_flOuterRadius = this->m_flRadius;
    v12 = v13;
  }
  m_bNegated = this->m_bNegated;
  if ( !bAlreadyEnemy_3 )
  {
    if ( m_bNegated )
      goto LABEL_18;
  }
  else if ( !m_bNegated )
  {
LABEL_18:
    if ( (float)(m_flOuterRadius * m_flOuterRadius) < v10 )
      return m_bNegated;
    else
      return !m_bNegated;
  }
  m_flOuterRadius = v12;
  goto LABEL_18;
}

//------------------------------------------------------------------------------
// Address: 0x10123AA0
// Name: protected: virtual bool CBaseFilter::PassesDamageFilterImpl(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseFilter::PassesDamageFilterImpl(CBaseFilter *this, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax

  m_Index = info->m_hAttacker.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return this->PassesFilterImpl(this, a2: nullptr, a3: nullptr);
  else
    return this->PassesFilterImpl(
             this,
             a2: nullptr,
             a3: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10123B00
// Name: private: virtual bool CFilterMultiple::PassesFilterImpl(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFilterMultiple::PassesFilterImpl(CFilterMultiple *this, CBaseEntity *pCaller, CBaseEntity *pEntity)
{
  CBaseEntityList *v3; // esi
  int v4; // edi
  CHandle<CBaseEntity> *m_hFilter; // ebx
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *m_pEntity; // esi
  char v14; // al
  bool v15; // cl
  unsigned int v17; // ecx
  int v18; // eax
  CEntInfo *v19; // edx
  unsigned int v20; // ecx
  int v21; // eax
  CEntInfo *v22; // eax
  IHandleEntity *v23; // esi
  char v24; // al
  bool v25; // cl

  v3 = g_pEntityList;
  v4 = 0;
  m_hFilter = this->m_hFilter;
  if ( this->m_nFilterType == FILTER_AND )
  {
    while ( 1 )
    {
      m_Index = m_hFilter->m_Index;
      if ( m_hFilter->m_Index != -1 )
      {
        v7 = (unsigned __int16)m_Index;
        v8 = &v3->m_EntPtrArray[(unsigned __int16)m_Index];
        v9 = HIWORD(m_Index);
        if ( v8->m_SerialNumber == v9 && v8->m_pEntity != nullptr )
        {
          v10 = v7;
          v11 = v3->m_EntPtrArray[v10].m_SerialNumber == v9;
          v12 = &v3->m_EntPtrArray[v10];
          if ( v11 )
            m_pEntity = v12->m_pEntity;
          else
            m_pEntity = nullptr;
          v14 = ((int (__thiscall *)(IHandleEntity *, CBaseEntity *, CBaseEntity *))m_pEntity->__vftable[64].GetRefEHandle)(
                  a1: m_pEntity,
                  a2: pCaller,
                  a3: pEntity);
          if ( LOBYTE(m_pEntity[213].__vftable) != 0 )
            v15 = v14 == 0;
          else
            v15 = v14;
          if ( !v15 )
            return 0;
          v3 = g_pEntityList;
        }
      }
      ++v4;
      ++m_hFilter;
      if ( v4 >= 10 )
        return 1;
    }
  }
  do
  {
    v17 = m_hFilter->m_Index;
    if ( m_hFilter->m_Index != -1 )
    {
      v18 = (unsigned __int16)v17;
      v19 = &v3->m_EntPtrArray[(unsigned __int16)v17];
      v20 = HIWORD(v17);
      if ( v19->m_SerialNumber == v20 && v19->m_pEntity != nullptr )
      {
        v21 = v18;
        v11 = v3->m_EntPtrArray[v21].m_SerialNumber == v20;
        v22 = &v3->m_EntPtrArray[v21];
        if ( v11 )
          v23 = v22->m_pEntity;
        else
          v23 = nullptr;
        v24 = ((int (__thiscall *)(IHandleEntity *, CBaseEntity *, CBaseEntity *))v23->__vftable[64].GetRefEHandle)(
                a1: v23,
                a2: pCaller,
                a3: pEntity);
        if ( LOBYTE(v23[213].__vftable) != 0 )
          v25 = v24 == 0;
        else
          v25 = v24;
        if ( v25 )
          return 1;
        v3 = g_pEntityList;
      }
    }
    ++v4;
    ++m_hFilter;
  }
  while ( v4 < 10 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10123C20
// Name: private: virtual bool CFilterMultiple::PassesDamageFilterImpl(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFilterMultiple::PassesDamageFilterImpl(CFilterMultiple *this, const CTakeDamageInfo *info)
{
  CBaseEntityList *v2; // esi
  int v3; // edi
  CHandle<CBaseEntity> *m_hFilter; // ebx
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *m_pEntity; // eax
  unsigned int v14; // ecx
  int v15; // eax
  CEntInfo *v16; // edx
  unsigned int v17; // ecx
  int v18; // eax
  CEntInfo *v19; // eax
  IHandleEntity *v20; // eax

  v2 = g_pEntityList;
  v3 = 0;
  m_hFilter = this->m_hFilter;
  if ( this->m_nFilterType == FILTER_AND )
  {
    while ( 1 )
    {
      m_Index = m_hFilter->m_Index;
      if ( m_hFilter->m_Index != -1 )
      {
        v6 = (unsigned __int16)m_Index;
        v7 = &v2->m_EntPtrArray[(unsigned __int16)m_Index];
        v8 = HIWORD(m_Index);
        if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
        {
          v9 = v6;
          v10 = v2->m_EntPtrArray[v9].m_SerialNumber == v8;
          v11 = &v2->m_EntPtrArray[v9];
          if ( v10 )
            m_pEntity = v11->m_pEntity;
          else
            m_pEntity = nullptr;
          if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *, const CTakeDamageInfo *))m_pEntity->__vftable[21].dtr_IHandleEntity)(
                 a1: m_pEntity,
                 a2: info) == 0 )
            return 0;
          v2 = g_pEntityList;
        }
      }
      ++v3;
      ++m_hFilter;
      if ( v3 >= 10 )
        return 1;
    }
  }
  do
  {
    v14 = m_hFilter->m_Index;
    if ( m_hFilter->m_Index != -1 )
    {
      v15 = (unsigned __int16)v14;
      v16 = &v2->m_EntPtrArray[(unsigned __int16)v14];
      v17 = HIWORD(v14);
      if ( v16->m_SerialNumber == v17 && v16->m_pEntity != nullptr )
      {
        v18 = v15;
        v10 = v2->m_EntPtrArray[v18].m_SerialNumber == v17;
        v19 = &v2->m_EntPtrArray[v18];
        if ( v10 )
          v20 = v19->m_pEntity;
        else
          v20 = nullptr;
        if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *, const CTakeDamageInfo *))v20->__vftable[21].dtr_IHandleEntity)(
               a1: v20,
               a2: info) != 0 )
          return 1;
        v2 = g_pEntityList;
      }
    }
    ++v3;
    ++m_hFilter;
  }
  while ( v3 < 10 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10123D10
// Name: private: bool CFilterEnemy::PassesNameFilter(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFilterEnemy::PassesNameFilter(CFilterEnemy *this, CBaseEntity *pEnemy)
{
  const char *v4; // eax
  bool v5; // al
  char pszValue[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_iszEnemyName.pszValue == nullptr )
    return true;
  if ( this->m_iszPlayerName.pszValue == nullptr )
    this->m_iszPlayerName.pszValue = *(const char **)FindPooledString(pszValue).pszValue;
  if ( this->m_iszEnemyName.pszValue == this->m_iszPlayerName.pszValue && pEnemy->IsPlayer(this: pEnemy) )
    return !this->m_bNegated;
  v4 = this->m_iszEnemyName.pszValue;
  v5 = v4 == pEnemy->m_iName.m_Value.pszValue || v4 == pEnemy->m_iClassname.pszValue;
  if ( this->m_bNegated )
  {
    if ( v5 )
      return false;
  }
  else if ( !v5 )
  {
    return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10123DC0
// Name: public: virtual bool CFilterEnemy::PassesFilterImpl(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFilterEnemy::PassesFilterImpl(CFilterEnemy *this, CBaseEntity *pCaller, CBaseEntity *pEntity)
{
  if ( pCaller == nullptr || pEntity == nullptr )
    return false;
  if ( (this->m_spawnflags.m_Value & 1) != 0 && pEntity == pCaller->GetEnemy_2(this: pCaller)
    || !CFilterEnemy::PassesNameFilter(this, pEnemy: pEntity) )
  {
    return true;
  }
  return CFilterEnemy::PassesProximityFilter(this, pCaller, pEnemy: pEntity) != 0
      && CFilterEnemy::PassesMobbedFilter(this, pCaller, pEnemy: pEntity) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10123E30
// Name: public: CFilterMultiple::CFilterMultiple(void)
// Source: json
//------------------------------------------------------------------------------
CFilterMultiple *__thiscall CFilterMultiple::CFilterMultiple(CFilterMultiple *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->m_OnPass.m_Value.iVal = 0;
  this->m_OnPass.m_Value.eVal.m_Index = -1;
  this->m_OnPass.m_Value.fieldType = FIELD_VOID;
  this->m_OnFail.m_Value.iVal = 0;
  this->m_OnFail.m_Value.eVal.m_Index = -1;
  this->m_OnFail.m_Value.fieldType = FIELD_VOID;
  this->__vftable = (CFilterMultiple_vtbl *)&CFilterMultiple::`vftable';
  this->m_hFilter[0].m_Index = -1;
  this->m_hFilter[1].m_Index = -1;
  this->m_hFilter[2].m_Index = -1;
  this->m_hFilter[3].m_Index = -1;
  this->m_hFilter[4].m_Index = -1;
  this->m_hFilter[5].m_Index = -1;
  this->m_hFilter[6].m_Index = -1;
  this->m_hFilter[7].m_Index = -1;
  this->m_hFilter[8].m_Index = -1;
  this->m_hFilter[9].m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10123EF0
// Name: public: virtual bool CFilterName::PassesFilterImpl(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFilterName::PassesFilterImpl(CFilterName *this, CBaseEntity *pCaller, CBaseEntity *pEntity)
{
  const char *pszValue; // eax
  const char *v6; // eax

  pszValue = this->m_iFilterName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( pszValue == "!player" || _V_stricmp(s1: pszValue, s2: "!player") == 0 )
    return pEntity->IsPlayer(this: pEntity);
  v6 = this->m_iFilterName.pszValue;
  if ( v6 == nullptr )
    v6 = locale;
  if ( pEntity->m_iName.m_Value.pszValue == v6 )
    return 1;
  else
    return CBaseEntity::NameMatchesComplex(this: pEntity, pszNameOrWildcard: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10123F60
// Name: public: virtual bool CFilterModel::PassesFilterImpl(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFilterModel::PassesFilterImpl(CFilterModel *this, CBaseEntity *pCaller, CBaseEntity *pEntity)
{
  const char *v4; // eax
  const char *pszValue; // ecx

  v4 = *(const char **)((int (__thiscall *)(CBaseEntity *, CBaseEntity **))pEntity->GetModelName)(
                         a1: pEntity,
                         a2: &pEntity);
  if ( v4 == nullptr )
    v4 = locale;
  pszValue = this->m_iFilterModel.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  return pszValue == v4 || _V_stricmp(s1: pszValue, s2: v4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10123FB0
// Name: public: virtual bool CFilterContext::PassesFilterImpl(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFilterContext::PassesFilterImpl(CFilterContext *this, CBaseEntity *pCaller, CBaseEntity *pEntity)
{
  const char *pszValue; // eax
  int ContextByName; // eax
  const char *ContextValue; // eax
  BOOL result; // eax

  pszValue = this->m_iFilterContext.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  ContextByName = CBaseEntity::FindContextByName(this: pEntity, name: pszValue);
  result = false;
  if ( ContextByName != -1 )
  {
    ContextValue = CBaseEntity::GetContextValue(this: pEntity, index: ContextByName);
    if ( atoi(nptr: ContextValue) > 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10124000
// Name: public: virtual bool CFilterClass::PassesFilterImpl(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFilterClass::PassesFilterImpl(CFilterClass *this, CBaseEntity *pCaller, CBaseEntity *pEntity)
{
  const char *pszValue; // eax

  pszValue = this->m_iFilterClass.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( pEntity->m_iClassname.pszValue == pszValue )
    return 1;
  else
    return CBaseEntity::ClassMatchesComplex(this: pEntity, pszClassOrWildcard: pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x10124030
// Name: public: virtual bool FilterTeam::PassesFilterImpl(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall FilterTeam::PassesFilterImpl(FilterTeam *this, CBaseEntity *pCaller, CBaseEntity *pEntity)
{
  return pEntity != nullptr && CBaseEntity::GetTeamNumber(this: pEntity) == this->m_iFilterTeam;
}

//------------------------------------------------------------------------------
// Address: 0x10124060
// Name: public: virtual bool CFilterMassGreater::PassesFilterImpl(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFilterMassGreater::PassesFilterImpl(
        CFilterMassGreater *this,
        CBaseEntity *pCaller,
        CBaseEntity *pEntity)
{
  IPhysicsObject *m_pPhysicsObject; // ecx

  m_pPhysicsObject = pEntity->m_pPhysicsObject;
  return m_pPhysicsObject != nullptr
      && ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: m_pPhysicsObject) > this->m_fFilterMass;
}

//------------------------------------------------------------------------------
// Address: 0x101240A0
// Name: protected: virtual bool FilterDamageType::PassesDamageFilterImpl(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall FilterDamageType::PassesDamageFilterImpl(FilterDamageType *this, const CTakeDamageInfo *info)
{
  return (info->m_bitsDamageType & 0xEFFFFFFF) == this->m_iDamageType;
}

//------------------------------------------------------------------------------
// Address: 0x10403010
// Name: CBaseFilter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseFilter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseFilter>();
  CBaseFilter_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403040
// Name: CFilterMultiple_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFilterMultiple_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFilterMultiple>();
  CFilterMultiple_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403070
// Name: CFilterName_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFilterName_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFilterName>();
  CFilterName_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104030A0
// Name: CFilterModel_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFilterModel_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFilterModel>();
  CFilterModel_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104030D0
// Name: CFilterContext_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFilterContext_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFilterContext>();
  CFilterContext_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403100
// Name: CFilterClass_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFilterClass_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFilterClass>();
  CFilterClass_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403130
// Name: FilterTeam_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *FilterTeam_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<FilterTeam>();
  FilterTeam_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403160
// Name: CFilterMassGreater_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFilterMassGreater_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFilterMassGreater>();
  CFilterMassGreater_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403190
// Name: FilterDamageType_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *FilterDamageType_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<FilterDamageType>();
  FilterDamageType_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104031C0
// Name: CFilterEnemy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFilterEnemy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFilterEnemy>();
  CFilterEnemy_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101240C0
// Name: class CBaseFilter __near * _CreateEntityTemplate<class CBaseFilter>(class CBaseFilter __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseFilter *__cdecl _CreateEntityTemplate<CBaseFilter>(CBaseFilter *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x388u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CBaseFilter::`vftable';
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    v3[220] = 0;
    v3[223] = -1;
    v3[224] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CBaseFilter *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124140
// Name: class CFilterName __near * _CreateEntityTemplate<class CFilterName>(class CFilterName __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFilterName *__cdecl _CreateEntityTemplate<CFilterName>(CFilterName *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    v3[220] = 0;
    v3[223] = -1;
    v3[224] = 0;
    *v3 = &CFilterName::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFilterName *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101241C0
// Name: class CFilterModel __near * _CreateEntityTemplate<class CFilterModel>(class CFilterModel __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFilterModel *__cdecl _CreateEntityTemplate<CFilterModel>(CFilterModel *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    v3[220] = 0;
    v3[223] = -1;
    v3[224] = 0;
    *v3 = &CFilterModel::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFilterModel *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124240
// Name: class CFilterContext __near * _CreateEntityTemplate<class CFilterContext>(class CFilterContext __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFilterContext *__cdecl _CreateEntityTemplate<CFilterContext>(CFilterContext *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    v3[220] = 0;
    v3[223] = -1;
    v3[224] = 0;
    *v3 = &CFilterContext::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFilterContext *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101242C0
// Name: class CFilterClass __near * _CreateEntityTemplate<class CFilterClass>(class CFilterClass __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFilterClass *__cdecl _CreateEntityTemplate<CFilterClass>(CFilterClass *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    v3[220] = 0;
    v3[223] = -1;
    v3[224] = 0;
    *v3 = &CFilterClass::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFilterClass *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124340
// Name: class FilterTeam __near * _CreateEntityTemplate<class FilterTeam>(class FilterTeam __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
FilterTeam *__cdecl _CreateEntityTemplate<FilterTeam>(FilterTeam *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    v3[220] = 0;
    v3[223] = -1;
    v3[224] = 0;
    *v3 = &FilterTeam::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (FilterTeam *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101243C0
// Name: class CFilterMassGreater __near * _CreateEntityTemplate<class CFilterMassGreater>(class CFilterMassGreater __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFilterMassGreater *__cdecl _CreateEntityTemplate<CFilterMassGreater>(
        CFilterMassGreater *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    v3[220] = 0;
    v3[223] = -1;
    v3[224] = 0;
    *v3 = &CFilterMassGreater::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFilterMassGreater *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124440
// Name: class FilterDamageType __near * _CreateEntityTemplate<class FilterDamageType>(class FilterDamageType __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
FilterDamageType *__cdecl _CreateEntityTemplate<FilterDamageType>(FilterDamageType *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    v3[220] = 0;
    v3[223] = -1;
    v3[224] = 0;
    *v3 = &FilterDamageType::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (FilterDamageType *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101244C0
// Name: class CFilterEnemy __near * _CreateEntityTemplate<class CFilterEnemy>(class CFilterEnemy __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFilterEnemy *__cdecl _CreateEntityTemplate<CFilterEnemy>(CFilterEnemy *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x39Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    v3[220] = 0;
    v3[223] = -1;
    v3[224] = 0;
    *v3 = &CFilterEnemy::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFilterEnemy *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}
